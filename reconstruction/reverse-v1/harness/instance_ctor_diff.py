#!/usr/bin/env python3
"""CInstance identity/handle allocation — original-binary differential.

Functions under judgement, both from the pinned image
(3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):

  F1  _ZN9CInstance14SetObjectIndexEib           @0x0019324c
      70 instructions + 1 pool word, 284 B, four-register frame, four callees.
      Writes the object index, unlinks the old CObjectGM, looks the new index up
      in g_ObjectHash, copies six fields and tail-branches to CollisionMarkDirty.

  F2  _ZN9CInstanceC2Effiib                       @0x001994dc
      249 instructions + 8 pool words, 1028 B, nine-register frame, seven
      callees (one of them F1).  Initialises all of a 0x1b0-byte instance,
      resolves its object, plants it in the global instance table and registers
      the builtin properties.

Two arms, same inputs, same staged memory:
  arm A (judge)  the original bytes, executed in Unicorn over one staged arena
  arm B (claim)  reconstruction/reverse-v1/c/instance_ctor/, cross-compiled for
                 armv7a-none-eabi (freestanding) and run under qemu-arm

Why arm B must not be host-compiled: +0x1b0 is 432 bytes only if a pointer is
4, the hash bucket stride is 8 only if `lsl #3` is 8, the instance-table slots
are 4-byte words, and `ldrd/strd` are 8 bytes.  A 64-bit host build moves every
one of those and the records would stop describing the original.

Scope, stated up front.  SetObjectIndex IS recovered and is linked for real:
arm A runs the original bytes at 0x19324c (inside the constructor too), arm B
runs c/instance_ctor/src/set_object_index.c.  Nothing about the object-index
path is stubbed.  Every OTHER callee is unrecovered, and both arms run the SAME
stub for it:

  0x0019e0fc  CObjectGM::RemoveInstance(CInstance*)
  0x0019e02c  CObjectGM::AddInstance(CInstance*)
  0x001931c0  CInstance::SetSpriteIndex(int)
  0x001cc1d0  CollisionMarkDirty(CInstance*)
  0x0019188c  YYObjectBase::YYObjectBase(int,int)
  0x0023f8f0  isGlobalBuiltinVar(char const*)
  0x0023ffac  JS_SetupBuiltinProperty(PFbP9CInstanceiP6RValueES4_)
  0x0019946c  YYObjectBase::Add(char const*, PS, int)
  0x000cef64  YYRealloc(void*, int)
  0x000b65b0  memset@plt

A green run therefore proves these two bodies' dispatch, field offsets,
constants, request order, the hash walk, the table scan/grow, the builtin loop
and the argument plumbing — not one byte of the stubs, and not device
behaviour.  Three stubs are deliberately instrumented, and both arms do it
identically, because that is what makes three ordering facts observable:

  * RemoveInstance writes inst+0x7c = 0xbeef while it runs (probe modes 2 and 4)
    -> F1's re-read of +0x7c after the call (0x193278) is visible.
  * AddInstance re-points inst+0x80 at OBJ3 (probe modes 3 and 4) -> F1's
    re-read of +0x80 after the call (0x19335c) is visible.
  * the base constructor writes +0x10/+0x14 only when the case's gate bit is
    set, so F2's final clear of both words is proven, not tautological.

Heap model, identical on both arms and stated because an earlier arm in this
line was bitten by it: a bump allocator over IC_HEAP inside the arena, 16-byte
alignment, every byte of a block pre-filled with IC_HEAP_FILL = 0x5b, and a
0xdeadbeef guard word written at block+size.  The fill byte is invisible in a
correct run by construction (the grown table zeroes its whole tail), and it
becomes visible exactly when a translation mis-sizes that memset — which is
what mutant ctor_memset_len shows.

Gates:
  * binding    image sha256; each body's byte range, instruction count and
               pool-word count; the exact callee address+symbol set its
               branches name; the arena layout parsed out of the translation's
               own header
  * census     every instruction of the original appears in the translation as
               an `@0xADDR <verbatim llvm-objdump text>` comment, each address
               exactly once, and every literal-pool word as its value
  * census-self  the census is re-run on deliberately corrupted copies of the
               translations and must go red on the mutated address
  * identity   every case identical on both arms (return token, ordered call
               log, the EXT table state, the four memory windows)
  * coverage   every decision of the ORIGINAL body is taken, proven by its own
               instruction trace
  * repeat     both arms rerun in a second process reproduce their records
  * teeth      every source-level mutant of the translations is caught by at
               least one named case; a mutant whose batch aborts the C arm is
               re-diagnosed one case per process, and the receipt says which
               cases were field-level mismatches and which crashed
  * tail       CollisionMarkDirty is entered with the lr SetObjectIndex itself
               was called with, never with an address inside SetObjectIndex -
               the evidence for 0x19334c being a `b` and not a `bl`

Usage:
  python3 instance_ctor_diff.py            # build, run both arms, write receipt
  python3 instance_ctor_diff.py --no-run   # replay the gates on the last receipt
"""
import argparse
import hashlib
import json
import pathlib
import re
import struct
import subprocess
import sys
import time
from typing import NamedTuple

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
MOD = RV1 / 'c' / 'instance_ctor'
BUILD = HERE / 'build' / 'instance_ctor'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO, SENTINEL  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
    UC_ARM_REG_R4, UC_ARM_REG_LR, UC_ARM_REG_PC)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

# ── the two bodies ──────────────────────────────────────────────────────────
SOI, SOI_POOL, SOI_END = 0x19324c, 0x193364, 0x193368
CTOR, CTOR_POOL, CTOR_END = 0x1994dc, 0x1998c0, 0x1998e0
BODIES = {
    1: {'name': 'SetObjectIndex', 'entry': SOI, 'pool': SOI_POOL,
        'end': SOI_END, 'src': 'set_object_index.c', 'ninstr': 70, 'npool': 1},
    2: {'name': 'CInstance_ctor', 'entry': CTOR, 'pool': CTOR_POOL,
        'end': CTOR_END, 'src': 'instance_ctor.c', 'ninstr': 249, 'npool': 8},
}

# ── callees ─────────────────────────────────────────────────────────────────
RM = 0x19e0fc       # CObjectGM::RemoveInstance(CInstance*)
AI = 0x19e02c       # CObjectGM::AddInstance(CInstance*)
SI = 0x1931c0       # CInstance::SetSpriteIndex(int)
CM = 0x1cc1d0       # CollisionMarkDirty(CInstance*)
YB = 0x19188c       # YYObjectBase::YYObjectBase(int,int)
GB = 0x23f8f0       # isGlobalBuiltinVar(char const*)
JS = 0x23ffac       # JS_SetupBuiltinProperty(...)
ADD = 0x19946c      # YYObjectBase::Add(char const*, PS, int)
RA = 0xcef64        # YYRealloc(void*, int)
MS = 0xb65b0        # memset@plt

CALLEE_NAMES = {
    RM: '_ZN9CObjectGM14RemoveInstanceEP9CInstance',
    AI: '_ZN9CObjectGM11AddInstanceEP9CInstance',
    SI: '_ZN9CInstance14SetSpriteIndexEi',
    CM: '_Z18CollisionMarkDirtyP9CInstance',
    YB: '_ZN12YYObjectBaseC2Eii',
    GB: '_Z18isGlobalBuiltinVarPKc',
    JS: '_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_',
    ADD: '_ZN12YYObjectBase3AddEPKcPS_i',
    RA: '_Z9YYReallocPvi',
    MS: 'memset@plt',
    SOI: '_ZN9CInstance14SetObjectIndexEib',   # linked for real, not a stub
}

# which callee belongs to which body
BODY_CALLEES = {
    'SetObjectIndex': (RM, AI, SI, CM),
    'CInstance_ctor': (YB, SOI, GB, JS, ADD, RA, MS),
}

# ── the arena: mirrored from c/instance_ctor/src/instance_ctor.h, and checked ─
IC_INST = 0x000
IC_OBJ1 = 0x200
IC_OBJ2 = 0x280
IC_OBJ3 = 0x300
IC_HASH = 0x380
IC_BUCKETS = 0x3c0
IC_NODES = 0x400
IC_TABLE = 0x480
IC_TBLARR = 0x4a0
IC_BPROPS = 0x4c0
IC_NAMES = 0x500
IC_PS = 0x540
IC_GT1 = 0x560
IC_GT2 = 0x564
IC_HEAP = 0x600
IC_ARENA_SIZE = 0x1000
IC_INST_SIZE = 0x1b0
IC_NBUCKET = 8
IC_NNODE = 8
IC_TBLCAP_MAX = 8
IC_BPROPS_MAX = 4
IC_HEAP_SIZE = 0x400
IC_HEAP_FILL = 0x5b
IC_HEAP_GUARD = 0xdeadbeef
IC_HASH_MASK = 7
IC_BUCKET_STRIDE = 8
IC_NODE_STRIDE = 16
IC_ALARM_BASE = 0xf8
IC_ALARM_COUNT = 12
IC_ALARM_STRIDE = 4
IC_VTABLE_OFF = 8
IC_BASE_ARG2 = 0x00ffffff
IC_F_270 = 0x43870000
IC_F_ONE = 0x3f800000

WINDOWS = ((IC_INST, IC_INST_SIZE),
           (IC_OBJ1, 0x100),
           (IC_TABLE, 0x40),
           (IC_HEAP, 0x100))

# ── the image's own globals (addresses, all read out of the pinned ELF) ─────
G_HASH_PTR = 0x542374       # pointer variable, through GOT 0x3edc44
G_INSTANCE_TABLE = 0x536f0c
G_CREATE_COUNTER = 0x536f20
G_BUILTIN_GATE = 0x47f295
G_BUILTIN_NUMB = 0x753108
G_BUILTIN_TABLE = 0x75310c
G_BASE_ARG1 = 0x544b48
G_VTABLE_HEAD = 0x3ebaf0
VT_VALUE = G_VTABLE_HEAD + IC_VTABLE_OFF      # 0x3ebaf8

MARK = 0xcc
INST_FILL = 0xa5
OBJ1_FIXED = (0x7, 11, -12345, 0x5)
OBJ2_FIXED = (0x0d, 21, -777, 0x33)
OBJ3_FIXED = (0x02, 31, 9, 0x44)
BASE_ARG1_DEFAULT = 0x00012345
BASE_ARG1_MIN = -0x80000000
CREATE_COUNTER = 0x5566778899aabbcc
BNAME = ('hp', 'mp', 'score', 'speed')

INT_MIN = -0x80000000
INT_MAX = 0x7fffffff


# ── cases ────────────────────────────────────────────────────────────────────
class Case(NamedTuple):
    fn: int
    p0: int
    p1: int
    p2: int
    p3: int
    p4: int
    p5: int
    p6: int
    p7: int
    label: str

    def args(self):
        return (self.fn, self.p0, self.p1, self.p2, self.p3, self.p4,
                self.p5, self.p6, self.p7)

    def as_dict(self):
        return {k: getattr(self, k) for k in
                ('fn', 'p0', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7',
                 'label')}


def cases_f1():
    """SetObjectIndex.  p0 objindex, p1 addToObject, p2 old/probe mode,
    p3 hash scenario, p4..p7 OBJ1 flags/sprite/depth/mask."""
    return [
        Case(1, 0, 1, 0, 0, *OBJ1_FIXED,
             'F1 objindex 0, empty hash: miss, +0x7c stored, nothing else'),
        Case(1, 5, 1, 0, 1, *OBJ1_FIXED,
             'F1 hit, addToObject: AddInstance then the six-field copy'),
        Case(1, 5, 0, 0, 1, *OBJ1_FIXED,
             'F1 hit, no AddInstance: the copy still runs'),
        Case(1, 5, 0, 1, 1, *OBJ1_FIXED,
             'F1 old object live: RemoveInstance first'),
        Case(1, -1, 0, 0, 0, *OBJ1_FIXED,
             'F1 objindex -1, empty hash: stored 0, looked up -1, miss'),
        Case(1, -1, 0, 0, 5, *OBJ1_FIXED,
             'F1 objindex -1 with a node keyed -1: HIT, stored 0'),
        Case(1, 0, 0, 0, 6, *OBJ1_FIXED,
             'F1 objindex 0 with a node keyed 0: HIT, stored 0'),
        Case(1, 5, 0, 2, 1, *OBJ1_FIXED,
             'F1 old object scribbles +0x7c: the reload feeds the -1 test'),
        Case(1, -1, 0, 2, 5, *OBJ1_FIXED,
             'F1 scribble beats the -1 normalisation: +0x7c = 0xbeef'),
        Case(1, 5, 1, 3, 1, *OBJ1_FIXED,
             'F1 AddInstance re-points +0x80: the copy uses OBJ3'),
        Case(1, 5, 0, 0, 2, *OBJ1_FIXED,
             'F1 two-node chain, match on the second node'),
        Case(1, 5, 0, 0, 3, *OBJ1_FIXED,
             'F1 two-node chain, no matching key: miss by exhaustion'),
        Case(1, 5, 0, 0, 4, *OBJ1_FIXED,
             'F1 node value NULL: +0x80 = 0, the six fields keep 0xa5'),
        Case(1, 5, 0, 0, 7, *OBJ1_FIXED,
             'F1 two matching nodes: the first wins (OBJ2)'),
        Case(1, 8, 1, 4, 1, *(0x0d, 21, -777, 0x33),
             'F1 both probes at once, other object fields'),
        Case(1, INT_MAX, 1, 0, 1, *(0xffffffff, INT_MAX, INT_MAX, INT_MIN),
             'F1 flags all ones, depth INT_MAX, mask INT_MIN'),
        Case(1, INT_MIN, 1, 0, 1, *(1, -1, 16777217, -1),
             'F1 INT_MIN index, depth 2^24+1 (float rounding), sprite -1'),
        Case(1, 5, 2, 0, 1, *OBJ1_FIXED,
             'F1 addToObject = 2 is still true (cmp, not tst)'),
    ]


def cases_f2():
    """The constructor.  p0 prefill, p1 x bits, p2 y bits, p3 id, p4 objindex,
    p5 addToObject, p6 table/builtin scenario, p7 option bits."""
    one = IC_F_ONE
    two = 0x40000000
    return [
        Case(2, 0, one, two, 7, 5, 1, 0, 2,
             'F2 fresh block, cap 0: slot -1, object resolved'),
        Case(2, 0, one, two, 7, 5, 1, 1, 2,
             'F2 slot 1 of a part-full table'),
        Case(2, 0, one, two, 7, 5, 1, 2, 2,
             'F2 slots 1 and 2 busy: the scan reaches 3'),
        Case(2, 0, one, two, 7, 5, 1, 3, 2,
             'F2 next_free == cap: the clamp sends the scan to slot 0'),
        Case(2, 0, one, two, 7, 5, 1, 4, 2,
             'F2 full table: grow 4 -> 6, slot 4'),
        Case(2, 0, one, two, 7, 5, 1, 5, 0,
             'F2 full table cap 2: grow to 3, slot 2, and a hash miss'),
        Case(2, 0, one, two, 7, 5, 1, 6, 2,
             'F2 two builtin properties registered'),
        Case(2, 0, one, two, 7, 5, 1, 7, 2,
             'F2 first builtin skipped by isGlobalBuiltinVar'),
        Case(2, 0, one, two, 7, 5, 1, 8, 2,
             'F2 both builtins skipped: no Add at all'),
        Case(2, 0, one, two, 7, 5, 1, 9, 2,
             'F2 gate on but count 0: loop never entered'),
        Case(2, 0, one, two, 7, 5, 1, 10, 2,
             'F2 gate off with two entries staged: the gate decides'),
        Case(2, 2, one, two, 7, 5, 1, 1, 2,
             'F2 stale live instance: +0x80 pre-cleared, no RemoveInstance'),
        Case(2, 1, one, two, 7, 5, 1, 1, 0,
             'F2 block prefilled 0xa5 and a hash miss: every slot rewritten'),
        Case(2, 0, one, two, 7, 5, 1, 1, 1,
             'F2 base ctor gate on: +0x10/+0x14 written then cleared'),
        Case(2, 0, one, two, 7, 5, 1, 1, 6,
             'F2 base ctor arg1 = INT_MIN and a hash hit'),
        Case(2, 2, one, two, 7, 5, 1, 0, 2,
             'F2 stale slot 3 overwritten by -1 (cap 0)'),
        Case(2, 0, 0x7fc00001, 0x80000000, INT_MIN, -1, 1, 1, 2,
             'F2 NaN x, -0.0 y, id INT_MIN, objindex -1 (stored 0)'),
        Case(2, 0, one, two, 7, 5, 0, 1, 2,
             'F2 addToObject false: no AddInstance'),
        Case(2, 0, one, two, 7, 5, 2, 1, 2,
             'F2 addToObject 2: AddInstance runs'),
        Case(2, 1, one, two, 0, INT_MAX, 1, 3, 0,
             'F2 prefilled, clamp, objindex INT_MAX, hash miss'),
    ]


def cases():
    return cases_f1() + cases_f2()


# ── record helpers ──────────────────────────────────────────────────────────
def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


def _tk(tr, a, b):
    for i in range(len(tr) - 1):
        if tr[i][0] == a and tr[i + 1][0] == b:
            return True
    return False


def _at(tr, a):
    for row in tr:
        if row[0] == a:
            return row
    return None


def _n(tr, a):
    return sum(1 for r in tr if r[0] == a)


def _memword(rec, off):
    """The word at an ARENA offset, out of the MEM blob, as its 8-char token."""
    base_words = 0
    for start, ln in WINDOWS:
        if start <= off and off + 4 <= start + ln:
            i = base_words + (off - start) // 4
            return rec['mem'][8 * i:8 * i + 8]
        base_words += ln // 4
    return None


def _memb(rec, off):
    """One byte of an arena word, out of its 8-char token."""
    t = _memword(rec, off & ~3)
    if t is None or t[0] in 'AS':
        return None
    return (int(t, 16) >> (8 * (off & 3))) & 0xff


def _memval(rec, off):
    t = _memword(rec, off)
    if t is None:
        return None
    if t.startswith('A'):
        return ('arena', int(t[1:], 16))
    return ('hex', int(t, 16))


COVER = [
    # ── F1 ──────────────────────────────────────────────────────────────────
    ('f1_old_null_skips_unlink', lambda tr, r, c: _tk(tr, 0x19326c, 0x193284)),
    ('f1_old_live_unlinks', lambda tr, r, c: _tk(tr, 0x193270, 0x193274)),
    ('f1_index_minus1_stored_zero', lambda tr, r, c: _tk(tr, 0x193288,
                                                         0x19328c)),
    # 0x19328c is `streq`: a predicated store is still fetched, so its trace
    # presence says nothing.  The stored word does.
    ('f1_index_kept', lambda tr, r, c: c.fn == 1 and c.p0 != -1
     and _memval(r, 0x7c) == ('hex', c.p0 & 0xffffffff)),
    ('f1_bucket_empty', lambda tr, r, c: _tk(tr, 0x1932b0, 0x1932dc)),
    ('f1_head_match', lambda tr, r, c: _tk(tr, 0x1932c0, 0x1932e8)),
    ('f1_chain_match', lambda tr, r, c: _tk(tr, 0x1932cc, 0x1932e8)),
    ('f1_chain_exhausted', lambda tr, r, c: _tk(tr, 0x1932d8, 0x1932dc)),
    # 0x1932f4 is `popeq` - same argument.  A node whose value is 0 must leave
    # +0x80 zero and call nothing.
    ('f1_value_null_returns', lambda tr, r, c: c.fn == 1 and c.p3 == 4
     and _memval(r, 0x80) == ('hex', 0) and not r['calls']),
    ('f1_add_true_path', lambda tr, r, c: _tk(tr, 0x1932fc, 0x193350)),
    ('f1_add_false_path', lambda tr, r, c: _tk(tr, 0x1932fc, 0x193300)),
    ('f1_index_reloaded_after_unlink',
     lambda tr, r, c: _tk(tr, 0x193274, 0x193278)),
    ('f1_object_reread_after_add',
     lambda tr, r, c: _tk(tr, 0x193358, 0x19335c)),
    ('f1_copy_block', lambda tr, r, c: _at(tr, 0x193300) is not None
     and _at(tr, 0x193304) is not None),
    ('f1_tail_branch', lambda tr, r, c: _at(tr, 0x19334c) is not None),
    ('f1_lookup_key_is_raw_argument',
     lambda tr, r, c: c.fn == 1 and c.p0 not in (0, -1)
     and _at(tr, 0x1932a4) is not None
     and to_i32(_at(tr, 0x1932a4)[5]) == c.p0),
    ('f1_index_beyond_mask_hits',
     lambda tr, r, c: c.fn == 1 and (c.p0 & IC_HASH_MASK) != c.p0
     and _at(tr, 0x1932a4) is not None and bool(r['calls'])),
    ('f1_minus1_looks_up_minus1',
     lambda tr, r, c: c.fn == 1 and c.p0 == -1 and c.p3 == 5
     and bool(r['calls']) and _memval(r, 0x7c) == ('hex', 0)),
    ('f1_zero_looks_up_zero',
     lambda tr, r, c: c.fn == 1 and c.p0 == 0 and c.p3 == 6
     and bool(r['calls']) and _memval(r, 0x7c) == ('hex', 0)),
    ('f1_bbox_dirty_on_hit',
     lambda tr, r, c: c.fn == 1 and r['calls'] and _memb(r, 0x64) == 1),
    ('f1_miss_leaves_bbox', lambda tr, r, c: c.fn == 1 and not r['calls']
     and _memb(r, 0x64) == 0xa5),
    # ── F2 ──────────────────────────────────────────────────────────────────
    ('f2_base_ctor_called', lambda tr, r, c: c.fn == 2
     and _at(tr, 0x199520) is not None),
    ('f2_vtable_stored', lambda tr, r, c: c.fn == 2
     and _memword(r, 0x0) == 'S0000001'),
    ('f2_self_rings', lambda tr, r, c: c.fn == 2
     and _at(tr, 0x199540) is not None and _at(tr, 0x199574) is not None),
    ('f2_alarm_pass1_twelve', lambda tr, r, c: c.fn == 2
     and _n(tr, 0x1995f4) == 12),
    ('f2_alarm_pass2_twelve', lambda tr, r, c: c.fn == 2
     and _n(tr, 0x1996d4) == 12),
    ('f2_object_pointer_precleared', lambda tr, r, c: c.fn == 2
     and _at(tr, 0x19964c) is not None),
    ('f2_setobjectindex_called', lambda tr, r, c: c.fn == 2
     and _at(tr, 0x199660) is not None),
    ('f2_table_slot_stored', lambda tr, r, c: c.fn == 2
     and _at(tr, 0x1997cc) is not None),
    ('f2_table_no_slot', lambda tr, r, c: _tk(tr, 0x199778, 0x1997c0)),
    ('f2_table_clamped', lambda tr, r, c: _tk(tr, 0x19979c, 0x1997a0)),
    ('f2_table_grown', lambda tr, r, c: _at(tr, 0x19987c) is not None
     and _at(tr, 0x1998bc) is not None),
    ('f2_builtin_gate_off', lambda tr, r, c: _tk(tr, 0x1997e0, 0x19985c)),
    ('f2_builtin_count_zero', lambda tr, r, c: _tk(tr, 0x1997f4, 0x19985c)),
    ('f2_builtin_skipped', lambda tr, r, c: _tk(tr, 0x19982c, 0x19980c)),
    ('f2_builtin_registered', lambda tr, r, c: _at(tr, 0x19984c) is not None),
    ('f2_epilogue', lambda tr, r, c: _at(tr, 0x199878) is not None),
    # the per-slot proof is the identity gate over the whole 0x1b0 window; this
    # item names the defaults that are not zero and are not the vtable.
    ('f2_defaults_written',
     lambda tr, r, c: c.fn == 2 and c.p0 == 0
     and _memval(r, 0x16c) == ('hex', 2)
     and _memval(r, 0xd8) == ('hex', IC_F_270)
     and _memval(r, 0xa8) == ('hex', IC_BASE_ARG2)
     and _memval(r, 0x188) == ('hex', 0xffffffff)
     and _memval(r, 0x170) == ('hex', 0xffffffff)
     and _memval(r, 0x128) == ('hex', 0xffffffff)
     and _memval(r, 0x14c) == ('hex', 0xffffffff)
     and _memb(r, 0x174) == 0),
    # the child-order contract: base ctor first, instance-table work before the
    # builtin registration, and the memset strictly inside the grow path.
    ('f2_child_object_order',
     lambda tr, r, c: c.fn == 2 and r['calls']
     and r['calls'][0].startswith('YB ')
     and (not any(x.startswith('GB ') for x in r['calls'])
          or r['calls'].index([x for x in r['calls']
                               if x.startswith('GB ')][0])
          > max(i for i, x in enumerate(r['calls'])
                if x.startswith(('SI ', 'CM ', 'RA '))))
     and all(r['calls'].index(x) < r['calls'].index(y)
             for x in r['calls'] if x.startswith('RA ')
             for y in r['calls'] if y.startswith('MS '))),
    ('f2_48_is_one', lambda tr, r, c: _memval(r, 0x48) == ('hex', 1)),
    ('f2_stacktrace_words_cleared',
     lambda tr, r, c: _memval(r, 0x10) == ('hex', 0)
     and _memval(r, 0x14) == ('hex', 0)),
    ('f2_stale_slot_overwritten',
     lambda tr, r, c: c.fn == 2 and c.p0 == 2 and c.p6 == 0
     and _memval(r, 0x44) == ('hex', 0xffffffff)),
    ('f2_stale_object_overwritten',
     lambda tr, r, c: c.fn == 2 and c.p0 == 2 and (c.p7 & 2)
     and _memval(r, 0x80) == ('arena', IC_OBJ1)),
    ('f2_untouched_slots_kept',
     lambda tr, r, c: c.fn == 2 and c.p0 == 1
     and _memval(r, 0x144) == ('hex', 0xa5a5a5a5)
     and _memval(r, 0x148) == ('hex', 0xa5a5a5a5)),
]


# ── original arm ─────────────────────────────────────────────────────────────
class Stage:
    """One staged arena, hooks installed exactly once.

    Per case only the arena and the image .bss are rewritten and the logs are
    cleared: hooks installed per case would accumulate.
    """

    def __init__(self, o):
        self.o = o
        self.arena = o.alloc(IC_ARENA_SIZE)
        self.tr = []
        self.log = []
        self.traces = {1: [], 2: []}
        self.bump = 0
        self.cm_lr = []
        self.cm_traces = []
        self.base_gate = 0
        self.p_rm = 0
        self.p_ai = 0
        self.gb_answer = [0] * IC_BPROPS_MAX
        for addr, fn in ((RM, self.h_rm), (AI, self.h_ai), (SI, self.h_si),
                         (CM, self.h_cm), (YB, self.h_yb), (GB, self.h_gb),
                         (JS, self.h_js), (ADD, self.h_add), (RA, self.h_ra),
                         (MS, self.h_ms)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        for fn, spec in BODIES.items():
            o.uc.hook_add(UC_HOOK_CODE, self.h_trace, begin=spec['entry'],
                          end=spec['end'] - 4)

    # -- plumbing -----------------------------------------------------------
    def h_trace(self, uc_, addr, _s, _d):
        self.tr.append((addr, uc_.reg_read(UC_ARM_REG_R0),
                        uc_.reg_read(UC_ARM_REG_R1),
                        uc_.reg_read(UC_ARM_REG_R2),
                        uc_.reg_read(UC_ARM_REG_R3),
                        uc_.reg_read(UC_ARM_REG_R4),
                        uc_.reg_read(UC_ARM_REG_LR)))

    def rd(self, addr, n=4):
        return bytes(self.o.read(addr, n))

    def wr(self, addr, blob):
        self.o.write(addr, blob)

    def w32(self, addr, w):
        self.wr(addr, struct.pack('<I', w & 0xffffffff))

    def r32(self, addr):
        return struct.unpack('<I', self.rd(addr, 4))[0]

    def put32(self, off, w):
        self.w32(self.arena + off, w)

    def tok(self, w):
        if w == 0:
            return '00000000'
        d = (w - self.arena) & 0xffffffff
        if d < IC_ARENA_SIZE:
            return 'A%07x' % d
        if w == VT_VALUE:
            return 'S0000001'
        return '%08x' % w

    def logf(self, s):
        self.log.append(s)

    def cstr(self, addr, cap=8):
        if addr == 0:
            return None
        out = bytearray()
        for i in range(cap):
            b = self.rd(addr + i, 1)[0]
            if b == 0:
                break
            out.append(b)
        return bytes(out).decode('latin-1')

    def ret(self, uc_, value):
        if value is not None:
            uc_.reg_write(UC_ARM_REG_R0, value & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    # -- callee hooks -------------------------------------------------------
    def h_rm(self, uc_, _a, _s, _d):
        obj = uc_.reg_read(UC_ARM_REG_R0)
        inst = uc_.reg_read(UC_ARM_REG_R1)
        self.logf('RM %s %s' % (self.tok(obj), self.tok(inst)))
        if self.p_rm:
            self.w32(inst + 0x7c, 0xbeef)
        self.ret(uc_, None)

    def h_ai(self, uc_, _a, _s, _d):
        obj = uc_.reg_read(UC_ARM_REG_R0)
        inst = uc_.reg_read(UC_ARM_REG_R1)
        self.logf('AI %s %s' % (self.tok(obj), self.tok(inst)))
        if self.p_ai:
            self.w32(inst + 0x80, self.arena + IC_OBJ3)
        self.ret(uc_, None)

    def h_si(self, uc_, _a, _s, _d):
        self_ = uc_.reg_read(UC_ARM_REG_R0)
        sprite = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        self.logf('SI %d' % sprite)
        self.w32(self_ + 0x8c, sprite & 0xffffffff)
        self.ret(uc_, None)

    def h_cm(self, uc_, _a, _s, _d):
        self.logf('CM %s' % self.tok(uc_.reg_read(UC_ARM_REG_R0)))
        # The return address CollisionMarkDirty is entered with: if 0x19334c
        # really is `b` and not `bl`, this is still the CALLER's lr.
        self.cm_lr.append(uc_.reg_read(UC_ARM_REG_LR))
        self.ret(uc_, None)

    def h_yb(self, uc_, _a, _s, _d):
        self_ = uc_.reg_read(UC_ARM_REG_R0)
        a1 = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        a2 = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        self.logf('YB %d %d' % (a1, a2))
        for off, val in ((0x00, 0x10000000), (0x04, 0), (0x18, 0), (0x1c, 0),
                         (0x20, 0), (0x24, a1), (0x28, 1), (0x2c, a1),
                         (0x30, 0), (0x34, self.arena + IC_GT1), (0x38, 0),
                         (0x3c, self.arena + IC_GT1), (0x44, -1), (0x48, 0),
                         (0x4c, 0), (0x58, a2), (0x60, 0)):
            self.w32(self_ + off, val)
        if self.base_gate:
            self.w32(self_ + 0x10, self.arena + IC_GT2)
            self.w32(self_ + 0x14, self.arena + IC_GT2 + 4)
        self.ret(uc_, None)

    def h_gb(self, uc_, _a, _s, _d):
        name = self.cstr(uc_.reg_read(UC_ARM_REG_R0))
        ans = 0
        for i in range(IC_BPROPS_MAX):
            if name is not None and name == BNAME[i]:
                ans = self.gb_answer[i]
                break
        self.logf('GB %s %d' % ('-(null)' if name is None else name, ans))
        self.ret(uc_, ans)

    def h_js(self, uc_, _a, _s, _d):
        self.logf('JS %s %s' % (self.tok(uc_.reg_read(UC_ARM_REG_R0)),
                                self.tok(uc_.reg_read(UC_ARM_REG_R1))))
        self.ret(uc_, self.arena + IC_PS)

    def h_add(self, uc_, _a, _s, _d):
        self_ = uc_.reg_read(UC_ARM_REG_R0)
        name = self.cstr(uc_.reg_read(UC_ARM_REG_R1))
        ps = uc_.reg_read(UC_ARM_REG_R2)
        flag = to_i32(uc_.reg_read(UC_ARM_REG_R3))
        self.logf('BA %s %s %d %s' % ('-(null)' if name is None else name,
                                      self.tok(ps), flag, self.tok(self_)))
        self.ret(uc_, None)

    def h_ra(self, uc_, _a, _s, _d):
        p = uc_.reg_read(UC_ARM_REG_R0)
        n = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        self.logf('RA %s %d' % (self.tok(p), n))
        size = (n + 15) & ~15
        blk = self.arena + IC_HEAP + self.bump
        self.wr(blk, bytes([IC_HEAP_FILL]) * size)
        if p and n:
            self.wr(blk, self.rd(p, min(n, size)))
        self.w32(blk + size, IC_HEAP_GUARD)
        self.bump += size + 16
        self.ret(uc_, blk)

    def h_ms(self, uc_, _a, _s, _d):
        dst = uc_.reg_read(UC_ARM_REG_R0)
        val = uc_.reg_read(UC_ARM_REG_R1)
        n = uc_.reg_read(UC_ARM_REG_R2)
        self.logf('MS %s %d %d' % (self.tok(dst), to_i32(val), n))
        if n:
            self.wr(dst, bytes([val & 0xff]) * n)
        self.ret(uc_, dst)

    # -- staging ------------------------------------------------------------
    def _obj(self, off, flags, sprite, depth, mask):
        self.put32(off + 0x00, flags)
        self.put32(off + 0x04, sprite)
        self.put32(off + 0x08, depth)
        self.put32(off + 0x10, mask)
        self.put32(off + 0x20, 0)
        self.put32(off + 0x24, 0x5a5a5a5a)

    def _hash(self, scenario, objindex):
        self.put32(IC_HASH, self.arena + IC_BUCKETS)
        self.put32(IC_HASH + 4, IC_HASH_MASK)
        self.wr(self.arena + IC_BUCKETS, b'\0' * (IC_NBUCKET * IC_BUCKET_STRIDE))
        for i in range(IC_NNODE):
            base = self.arena + IC_NODES + i * IC_NODE_STRIDE
            self.w32(base, 0x11110000 + i)
            self.w32(base + 4, 0)
            self.w32(base + 8, 0x7f7f0000 + i)
            self.w32(base + 12, 0)
        nd = self.arena + IC_NODES
        node = lambda i: nd + i * IC_NODE_STRIDE
        idx = (objindex & 0xffffffff) & IC_HASH_MASK
        bslot = self.arena + IC_BUCKETS + idx * IC_BUCKET_STRIDE

        def head(v):
            self.w32(bslot, v)

        def node_at(i, key, value, nxt=None):
            self.w32(node(i) + 4, 0 if nxt is None else nxt)
            self.w32(node(i) + 8, key & 0xffffffff)
            self.w32(node(i) + 12, value)

        if scenario == 1:
            head(node(0))
            node_at(0, objindex, self.arena + IC_OBJ1)
        elif scenario == 2:
            head(node(0))
            node_at(0, objindex ^ 0x11110000, 0, node(1))
            node_at(1, objindex, self.arena + IC_OBJ1)
        elif scenario == 3:
            head(node(0))
            node_at(0, objindex ^ 1, 0, node(1))
            node_at(1, objindex ^ 2, self.arena + IC_OBJ1)
        elif scenario == 4:
            head(node(0))
            node_at(0, objindex, 0)
        elif scenario == 5:
            self.w32(self.arena + IC_BUCKETS + 7 * IC_BUCKET_STRIDE, node(0))
            node_at(0, -1, self.arena + IC_OBJ1)
        elif scenario == 6:
            self.w32(self.arena + IC_BUCKETS, node(0))
            node_at(0, 0, self.arena + IC_OBJ1)
        elif scenario == 7:
            head(node(0))
            node_at(0, objindex, self.arena + IC_OBJ2, node(1))
            node_at(1, objindex, self.arena + IC_OBJ1)

    def _table(self, scenario):
        slots = self.arena + IC_TBLARR
        dummy = self.arena + IC_OBJ2
        caps = {0: (0, 0, 0, []),
                1: (4, 1, 1, [dummy]),
                2: (4, 2, 2, [0, dummy, dummy]),
                3: (4, 0, 4, []),
                4: (4, 4, 0, [dummy, dummy, dummy, dummy]),
                5: (2, 2, 1, [dummy, dummy])}
        cap, count, nf, arr = caps.get(scenario, (4, 0, 0, []))
        self.wr(slots, b'\0' * (IC_TBLCAP_MAX * 4))
        for i, v in enumerate(arr):
            self.w32(slots + 4 * i, v)
        self.w32(G_INSTANCE_TABLE, slots)
        self.w32(G_INSTANCE_TABLE + 4, cap)
        self.w32(G_INSTANCE_TABLE + 8, count)
        self.w32(G_INSTANCE_TABLE + 12, nf)

    def _builtins(self, scenario):
        # 0x0075310c is the table itself: entries are staged there, and only
        # their name pointers point into the arena.
        self.wr(self.arena + IC_NAMES, b'\0' * 32)
        for i in range(IC_BPROPS_MAX):
            nm = self.arena + IC_NAMES + 8 * i
            self.wr(nm, BNAME[i].encode() + b'\0')
            e = G_BUILTIN_TABLE + i * 16
            self.w32(e, nm)
            self.w32(e + 4, 0xa0000000 + i)
            self.w32(e + 8, 0xb0000000 + i)
            self.w32(e + 12, 0xcccccccc)
            self.gb_answer[i] = 0
        gate, numb = 0, 0
        if scenario >= 6:
            gate, numb = 1, 2
            if scenario == 7:
                self.gb_answer[0] = 1
            elif scenario == 8:
                self.gb_answer[0] = 1
                self.gb_answer[1] = 1
            elif scenario == 9:
                numb = 0
            elif scenario == 10:
                gate, numb = 0, 2      # staged, but the gate byte decides
        self.wr(G_BUILTIN_GATE, bytes([gate]))
        self.w32(G_BUILTIN_NUMB, numb)

    def run(self, case):
        _, p0, p1, p2, p3, p4, p5, p6, p7 = case.args()
        self.wr(self.arena, bytes([MARK]) * IC_ARENA_SIZE)
        self.log.clear()
        self.tr.clear()
        self.cm_lr.clear()
        self.bump = 0
        self.p_rm = self.p_ai = 0
        self.base_gate = 0
        self.w32(G_HASH_PTR, self.arena + IC_HASH)
        self.w32(G_CREATE_COUNTER, CREATE_COUNTER & 0xffffffff)
        self.w32(G_CREATE_COUNTER + 4, CREATE_COUNTER >> 32)
        self.w32(G_BASE_ARG1, BASE_ARG1_DEFAULT)

        if case.fn == 1:
            self._obj(IC_OBJ1, p4, p5, p6, p7)
        else:
            self._obj(IC_OBJ1, *OBJ1_FIXED)
        self._obj(IC_OBJ2, *OBJ2_FIXED)
        self._obj(IC_OBJ3, *OBJ3_FIXED)

        if case.fn == 1:
            self.wr(self.arena + IC_INST, bytes([INST_FILL]) * IC_INST_SIZE)
            self.put32(0x80, 0)
            self._hash(p3, p0)
            if p2 in (1, 2, 4):
                self.put32(0x80, self.arena + IC_OBJ2)
            self.p_rm = 1 if p2 in (2, 4) else 0
            self.p_ai = 1 if p2 in (3, 4) else 0
            self._table(1)
            self._builtins(0)
            ret = self.o.call(SOI, r0=self.arena + IC_INST, r1=p0 & 0xffffffff,
                              r2=p1 & 0xffffffff)
            self.traces[1].append(list(self.tr))
            return self._record('void')

        inst = self.arena + IC_INST
        if p0 == 0:
            self.wr(inst, b'\0' * IC_INST_SIZE)
        elif p0 == 1:
            self.wr(inst, bytes([INST_FILL]) * IC_INST_SIZE)
        else:
            self.wr(inst, bytes([INST_FILL]) * IC_INST_SIZE)
            self.put32(0x80, self.arena + IC_OBJ3)
            self.put32(0x44, 3)
            self.put32(0x10, 0x0000c0de)
            self.put32(0x14, 0x0000c0df)
            self.put32(0x18c, 0)
            self.put32(0x190, 0)
            self.put32(0x198, 0)
            self.put32(0x64, 1)
            self.put32(0x7c, 0x77)
            self.put32(0x8c, 0x99)
            self.put32(0xac, 0x66)
            self.put32(0x180, 0x55)
        self._hash(1 if (p7 & 2) else 0, p4)
        self._table(p6)
        self._builtins(p6)
        self.base_gate = p7 & 1
        if p7 & 4:
            self.w32(G_BASE_ARG1, BASE_ARG1_MIN & 0xffffffff)
        ret = self.o.call(CTOR, r0=inst, r1=p1 & 0xffffffff,
                          r2=p2 & 0xffffffff, r3=p3 & 0xffffffff,
                          stack_words=(p4 & 0xffffffff, p5 & 0xffffffff))
        self.traces[2].append(list(self.tr))
        return self._record(self.tok(ret))

    def _ext(self):
        return [('tbl_base', self.tok(self.r32(G_INSTANCE_TABLE))),
                ('tbl_cap', str(to_i32(self.r32(G_INSTANCE_TABLE + 4)))),
                ('tbl_count', str(to_i32(self.r32(G_INSTANCE_TABLE + 8)))),
                ('tbl_nextfree', str(to_i32(self.r32(G_INSTANCE_TABLE + 12)))),
                ('heap_off', str(self.bump))]

    def dump(self):
        out = []
        for off, ln in WINDOWS:
            for o in range(0, ln, 4):
                out.append(self.tok(self.r32(self.arena + off + o)))
        return ''.join(out)

    def _record(self, ret):
        self.cm_traces.append(list(self.cm_lr))
        return {'ret': ret, 'calls': list(self.log), 'ext': self._ext(),
                'mem': self.dump()}


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-O1', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

SRCS = ['set_object_index.c', 'instance_ctor.c']


def build_c(out_bin, mutant=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    srcs = [MOD / 'src' / s for s in SRCS]
    if mutant:
        target = MOD / 'src' / mutant['file']
        text = target.read_text()
        for old, new in mutant['edits']:
            if text.count(old) != 1:
                raise RuntimeError('mutation site not unique in %s: %r'
                                   % (mutant['file'], old[:60]))
            text = text.replace(old, new)
        patched = BUILD / ('mut_%s_%s' % (mutant['name'], mutant['file']))
        patched.write_text(text)
        srcs = [patched if p.name == mutant['file'] else p for p in srcs]
    cmd = (['clang'] + ARM_FLAGS + ['-I', str(MOD / 'src')] +
           [str(p) for p in srcs] +
           [str(MOD / 'fixture' / 'driver.c'), '-o', str(out_bin)])
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-3000:])
    return out_bin


def run_c_arm(binary, case_list):
    blob = ''.join('%d %d %d %d %d %d %d %d %d\n' % c.args()
                   for c in case_list).encode()
    p = subprocess.run(['qemu-arm', str(binary)], input=blob, capture_output=True)
    if p.returncode:
        raise RuntimeError('driver exit %d: %s' % (p.returncode,
                                                   p.stderr.decode()[-500:]))
    recs, cur = [], None
    for line in p.stdout.decode('latin-1').splitlines():
        parts = line.split()
        if not parts:
            continue
        tag = parts[0]
        if tag == 'CASE':
            cur = {'ret': '', 'calls': [], 'ext': [], 'mem': ''}
            recs.append(cur)
        elif cur is None:
            raise RuntimeError('record line before CASE: %r' % line[:80])
        elif tag == 'RET':
            cur['ret'] = parts[1]
        elif tag == 'CALLS':
            cur['ncalls'] = int(parts[1])
        elif tag == 'MEM':
            cur['mem'] = parts[1]
        elif tag == 'EXT':
            cur['ext'].append((parts[1], parts[2]))
        else:
            cur['calls'].append(line.strip())
    if len(recs) != len(case_list):
        raise RuntimeError('driver returned %d records for %d cases'
                           % (len(recs), len(case_list)))
    for r in recs:
        if 'ncalls' in r and r['ncalls'] != len(r['calls']):
            raise RuntimeError('CALLS %d but %d call records'
                               % (r['ncalls'], len(r['calls'])))
        r.pop('ncalls', None)
    return recs


def same(a, b):
    return (a['ret'] == b['ret'] and a['calls'] == b['calls']
            and a['ext'] == b['ext'] and a['mem'] == b['mem'])


def _digest(recs):
    return hashlib.sha256(json.dumps(recs, sort_keys=True).encode()).hexdigest()


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    {'name': 'soi_add_gate_inverted', 'file': 'set_object_index.c',
     'edits': [('if (add_to_object != 0) {', 'if (add_to_object == 0) {')]},
    {'name': 'soi_unlink_dropped', 'file': 'set_object_index.c',
     'edits': [('CObjectGM_RemoveInstance(old, self);', '(void)old;')]},
    {'name': 'soi_lookup_uses_stored_index', 'file': 'set_object_index.c',
     'edits': [('n = buckets[objindex & mask].head;',
                'n = buckets[(uint32_t)idx & mask].head;')]},
    {'name': 'soi_chain_stops_at_head', 'file': 'set_object_index.c',
     'edits': [('    while (n != 0 && n->key != objindex)\n        n = n->next;',
                '    if (n != 0 && n->key != objindex)\n        n = 0;')]},
    {'name': 'soi_value_from_key_slot', 'file': 'set_object_index.c',
     'edits': [('obj = n->value;',
                'obj = *(struct ic_objectgm *const *)(const void *)'
                '((const uint8_t *)n + 0x08);')]},
    {'name': 'soi_mask_shifted', 'file': 'set_object_index.c',
     'edits': [('mask = t->mask;', 'mask = t->mask + 1u;')]},
    {'name': 'soi_visible_from_bit0', 'file': 'set_object_index.c',
     'edits': [('ic_st_u8(self, 0x65, (flags >> 1) & 1u);',
                'ic_st_u8(self, 0x65, flags & 1u);')]},
    {'name': 'soi_solid_from_bit1', 'file': 'set_object_index.c',
     'edits': [('ic_st_u8(self, 0x66, flags & 1u);',
                'ic_st_u8(self, 0x66, (flags >> 1) & 1u);')]},
    {'name': 'soi_persistent_from_bit3', 'file': 'set_object_index.c',
     'edits': [('ic_st_u8(self, 0x67, (flags >> 2) & 1u);',
                'ic_st_u8(self, 0x67, (flags >> 3) & 1u);')]},
    {'name': 'soi_depth_unsigned', 'file': 'set_object_index.c',
     'edits': [('depth = (float)*(const int32_t *)',
                'depth = (float)*(const uint32_t *)')]},
    {'name': 'soi_bbox_dirty_dropped', 'file': 'set_object_index.c',
     'edits': [('    ic_st_u8(self, 0x64, 1);',
                '    (void)0;')]},
    {'name': 'soi_collision_tail_dropped', 'file': 'set_object_index.c',
     'edits': [('    CollisionMarkDirty(self);\n}', '}')]},
    {'name': 'soi_sprite_from_depth', 'file': 'set_object_index.c',
     'edits': [('self, *(const int32_t *)((const uint8_t *)obj + 0x04));',
                'self, *(const int32_t *)((const uint8_t *)obj + 0x08));')]},
    {'name': 'soi_index_store_dropped', 'file': 'set_object_index.c',
     'edits': [('    ic_st_i32(self, 0x7c, objindex);', '    (void)0;')]},
    {'name': 'soi_minus1_not_normalised', 'file': 'set_object_index.c',
     'edits': [('    if (idx == -1)\n        ic_st_i32(self, 0x7c, 0);',
                '    if (idx == -2)\n        ic_st_i32(self, 0x7c, 0);')]},
    {'name': 'soi_miss_sets_dirty', 'file': 'set_object_index.c',
     'edits': [('        ic_st_ptr(self, 0x80, 0);\n        return;',
                '        ic_st_ptr(self, 0x80, 0);\n'
                '        ic_st_u8(self, 0x64, 1);\n        return;')]},

    {'name': 'ctor_vtable_offset', 'file': 'instance_ctor.c',
     'edits': [('+ IC_VTABLE_OFF);', '+ 0u);')]},
    {'name': 'ctor_alarm_sentinel_zero', 'file': 'instance_ctor.c',
     'edits': [('        alarm[i] = -1;', '        alarm[i] = 0;')]},
    # the two alarm loops are textually identical up to their annotations, so
    # the anchor has to reach through the annotation line of the store.
    {'name': 'ctor_alarm_count_eleven', 'file': 'instance_ctor.c',
     'edits': [('for (int32_t i = 0; i < IC_ALARM_COUNT; i++)\n'
                '/* @0x1996d4 str r1, [r3, #0xf8] */',
                'for (int32_t i = 0; i < IC_ALARM_COUNT - 1; i++)\n'
                '/* @0x1996d4 str r1, [r3, #0xf8] */')]},
    {'name': 'ctor_gravity_direction_zero', 'file': 'instance_ctor.c',
     'edits': [('ic_st_u32(self, 0xd8, IC_F_270);',
                'ic_st_u32(self, 0xd8, 0);')]},
    {'name': 'ctor_object_pointer_not_precleared', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_i32(self, 0x80, 0);', '    (void)0;')]},
    {'name': 'ctor_table_slot_dropped', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_i32(self, 0x44, slot);', '    (void)0;')]},
    {'name': 'ctor_table_count_dropped', 'file': 'instance_ctor.c',
     'edits': [('    tp->count = count;', '    (void)0;')]},
    {'name': 'ctor_growth_factor', 'file': 'instance_ctor.c',
     'edits': [('uint32_t x = (uint32_t)cap * 3u;',
                'uint32_t x = (uint32_t)cap * 2u;')]},
    {'name': 'ctor_memset_len', 'file': 'instance_ctor.c',
     'edits': [('               (uint32_t)(newcap - oldcap) << 2);',
                '               ((uint32_t)(newcap - oldcap) + 1u) << 2);')]},
    {'name': 'ctor_stacktrace_clear_dropped', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_i32(self, 0x14, 0);\n    return self;',
                '    return self;')]},
    {'name': 'ctor_ring_not_self', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_ptr(self, 0x18c, (uint8_t *)self + 0x18c);',
                '    ic_st_ptr(self, 0x18c, 0);')]},
    # swapping in `id` would leave objindex unused and fail the -Werror build;
    # +1 keeps the build green and still moves what SetObjectIndex looks up.
    {'name': 'ctor_objectindex_argument', 'file': 'instance_ctor.c',
     'edits': [('CInstance_SetObjectIndex(self, objindex, add_to_object);',
                'CInstance_SetObjectIndex(self, objindex + 1, add_to_object);')]},
    {'name': 'ctor_id_offset', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_i32(self, 0x78, id);',
                '    ic_st_i32(self, 0x74, id);')]},
    {'name': 'ctor_xstart_from_y', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_u32(self, 0xbc, x_bits);',
                '    ic_st_u32(self, 0xbc, y_bits);')]},
    {'name': 'ctor_builtin_gate_ignored', 'file': 'instance_ctor.c',
     'edits': [('    if (g_builtin_gate != 0) {', '    if (1) {')]},
    {'name': 'ctor_clamp_to_last_slot', 'file': 'instance_ctor.c',
     'edits': [('        if (cap <= slot)\n            slot = 0;',
                '        if (cap <= slot)\n            slot = cap - 1;')]},
    {'name': 'ctor_48_flag_zero', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_i32(self, 0x48, 1);',
                '    ic_st_i32(self, 0x48, 0);')]},
    {'name': 'ctor_create_counter_dropped', 'file': 'instance_ctor.c',
     'edits': [('    ic_st_u64(self, 0x70, cc);', '    (void)cc;')]},
]

MUTANT_NOTES = {}


def _sample(case, a, r):
    return {'case': case.label,
            'ret': {'original': a['ret'], 'mutant': r['ret']},
            'calls': {'original': a['calls'][:6], 'mutant': r['calls'][:6]},
            'ext': {'original': a['ext'], 'mutant': r['ext']},
            'mem': {'original': a['mem'][:96], 'mutant': r['mem'][:96]}}


def teeth_one(m, case_list, a_recs):
    """Judge one mutant.  A batch that aborts is re-diagnosed one case per
    process: the crash belongs to the cases that crash, and every surviving
    case is still compared on all four facets."""
    try:
        b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
    except RuntimeError as exc:
        return {'mutant': m['name'], 'file': m['file'], 'caught_by': [],
                'aborted_cases': [], 'mode': 'build-failed',
                'field_level': False, 'passed': False,
                'build_error': str(exc).splitlines()[-1][:300]}
    batch_detail = None
    try:
        recs = run_c_arm(b, case_list)
    except RuntimeError as exc:
        recs = None
        batch_detail = str(exc).splitlines()[0][:200]

    if recs is not None:
        caught, sample = [], None
        for c, a, r in zip(case_list, a_recs, recs):
            if not same(a, r):
                caught.append(c.label)
                if sample is None:
                    sample = _sample(c, a, r)
        return {'mutant': m['name'], 'file': m['file'], 'caught_by': caught,
                'aborted_cases': [], 'mode': 'mismatch',
                'field_level': True, 'passed': bool(caught),
                'sample_mismatch': sample}

    caught, aborted, detail, sample = [], [], {}, None
    for c, a in zip(case_list, a_recs):
        try:
            r = run_c_arm(b, [c])[0]
        except RuntimeError as exc:
            aborted.append(c.label)
            detail[c.label] = str(exc).splitlines()[0][:120]
            continue
        if not same(a, r):
            caught.append(c.label)
            if sample is None:
                sample = _sample(c, a, r)
    rec = {'mutant': m['name'], 'file': m['file'], 'caught_by': caught,
           'aborted_cases': aborted,
           'mode': 'mismatch+driver-abort' if caught else 'driver-abort',
           'field_level': bool(caught), 'passed': bool(caught or aborted),
           'batch_detail': batch_detail, 'abort_detail': detail,
           'sample_mismatch': sample}
    if not caught:
        rec['note'] = ('discrimination is by abort, not by a field mismatch - '
                       'weaker than a mismatch tooth; the case set cannot say '
                       'WHICH field moved')
        if m['name'] in MUTANT_NOTES:
            rec['why_not_field_level'] = MUTANT_NOTES[m['name']]
    return rec


# ── instruction census ───────────────────────────────────────────────────────
def _norm(s):
    return re.sub(r'\s+', ' ', s).strip()


ANCHOR = re.compile(r'/\*\s*@(0x[0-9a-f]{5,8})\s+(.*?)\s*\*/')


def _objdump(entry, pool, stop):
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                        '--stop-address=%#x' % stop, '-M', 'reg-names-std', SO],
                       capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('llvm-objdump failed: %s' % p.stderr[-800:])
    dis, words = {}, {}
    for ln in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
        if not m:
            continue
        addr, word, rest = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        text = ' '.join(x for x in rest.split('\t') if x.strip())
        text = re.sub(r'\s*<[^>]*>', '', text)
        text = re.sub(r'\s*@.*$', '', text)
        if addr < pool:
            dis[addr] = _norm(text)
        else:
            words[addr] = word
    return dis, words


def census_scan(dis, words, text):
    cands = {}
    for ln in text.splitlines():
        m = ANCHOR.search(ln)
        if m:
            cands.setdefault(int(m.group(1), 16), []).append(_norm(m.group(2)))
    wrong = [{'addr': hex(a), 'objdump': dis[a], 'source': cands.get(a, [])}
             for a in sorted(dis) if a not in cands or dis[a] not in cands[a]]
    dupes = [{'addr': hex(a), 'texts': cands[a]}
             for a in sorted(cands) if len(cands[a]) > 1]
    extra = [{'addr': hex(a), 'texts': cands[a]}
             for a in sorted(cands) if a not in dis and a not in words]
    pool_missing = [{'addr': hex(a), 'word': '%08x' % w}
                    for a, w in sorted(words.items())
                    if not any(('.word 0x%08x' % w) in c
                               for c in cands.get(a, []))]
    return {'wrong': wrong, 'duplicate_addresses': dupes,
            'unknown_addresses': extra, 'pool_missing': pool_missing,
            'ok': not wrong and not dupes and not extra and not pool_missing}


def instruction_census(overrides=None, fns=None):
    overrides = overrides or {}
    report, ok = {}, True
    for fn, spec in sorted(BODIES.items()):
        if fns is not None and fn not in fns:
            continue
        dis, words = _objdump(spec['entry'], spec['pool'], spec['end'])
        srcfile = MOD / 'src' / spec['src']
        text = overrides.get(spec['src'], srcfile.read_text())
        part = census_scan(dis, words, text)
        shape_ok = (len(dis) == spec['ninstr'] and len(words) == spec['npool']
                    and (spec['end'] - spec['entry']) // 4
                    == spec['ninstr'] + spec['npool'])
        part.update({'function': spec['name'], 'instructions': len(dis),
                     'declared_instructions': spec['ninstr'],
                     'pool_words': len(words),
                     'declared_pool_words': spec['npool'], 'shape_ok': shape_ok,
                     'documented': len(dis) - len(part['wrong']),
                     'ok': part['ok'] and shape_ok})
        report[spec['name']] = part
        ok = ok and part['ok']
    report['ok'] = ok
    report['instructions'] = sum(v['instructions'] for v in report.values()
                                 if isinstance(v, dict) and 'instructions' in v)
    report['documented'] = sum(v['documented'] for v in report.values()
                               if isinstance(v, dict) and 'documented' in v)
    return report


CENSUS_SELFTEST = [
    ('SetObjectIndex', 'operand: the -1 compare immediate',
     '/* @0x193284 cmn r3, #1 */', '/* @0x193284 cmn r3, #2 */', 0x193284),
    ('SetObjectIndex', 'deleted annotation: the 0x1932e0 store',
     '/* @0x1932e0 str r3, [r5, #0x80] */\n', '', 0x1932e0),
    ('SetObjectIndex', 'pool word: the GOT displacement',
     '/* @0x193364 .word 0x0025a9a8 */',
     '/* @0x193364 .word 0x0025a9a9 */', 0x193364),
    ('CInstance_ctor', 'operand: the alarm base immediate',
     '/* @0x1995f4 str r0, [r2, #0xf8] */',
     '/* @0x1995f4 str r0, [r2, #0xf4] */', 0x1995f4),
    ('CInstance_ctor', 'constant: the growth factor add',
     '/* @0x19987c add r12, r12, r12, lsl #1 */',
     '/* @0x19987c add r12, r12, r12, lsl #2 */', 0x19987c),
    ('CInstance_ctor', 'deleted annotation: the 0x19984c Add call',
     '/* @0x19984c bl 0x19946c */\n', '', 0x19984c),
]


def census_selftest():
    out, ok = [], True
    texts = {b['src']: (MOD / 'src' / b['src']).read_text()
             for b in BODIES.values()}
    byname = {b['name']: b for b in BODIES.values()}
    for label, what, old, new, addr in CENSUS_SELFTEST:
        spec = byname[label]
        dis, words = _objdump(spec['entry'], spec['pool'], spec['end'])
        text = texts[spec['src']]
        if text.count(old) != 1:
            out.append({'body': label, 'mutation': what, 'applied': False,
                        'ok': False})
            ok = False
            continue
        res = census_scan(dis, words, text.replace(old, new, 1))
        red_at = [w['addr'] for w in res['wrong']]
        red_at += [w['addr'] for w in res['pool_missing']]
        good = (not res['ok']) and hex(addr) in red_at
        out.append({'body': label, 'mutation': what, 'applied': True,
                    'expected_red_at': hex(addr), 'red_at': red_at[:6],
                    'ok': good})
        ok = ok and good
    return {'mutations': out, 'ok': ok,
            'note': 'the same census_scan() runs on the real sources; four of '
                    'these corrupt an operand or a constant word, two delete an '
                    'annotation line'}


# ── binding ──────────────────────────────────────────────────────────────────
def sha(p):
    return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()


def header_layout():
    text = (MOD / 'src' / 'instance_ctor.h').read_text()
    got = {}
    for m in re.finditer(r'^#define\s+(IC_[A-Z0-9_]+|ARENA_[A-Z0-9_]+)\s+'
                         r'(0x[0-9a-fA-F]+|\d+)u?', text, re.M):
        got[m.group(1)] = int(m.group(2), 0)
    return got


def binding():
    got = header_layout()
    mine = {'IC_INST': IC_INST, 'IC_OBJ1': IC_OBJ1, 'IC_OBJ2': IC_OBJ2,
            'IC_OBJ3': IC_OBJ3, 'IC_HASH': IC_HASH, 'IC_BUCKETS': IC_BUCKETS,
            'IC_NODES': IC_NODES, 'IC_TABLE': IC_TABLE, 'IC_TBLARR': IC_TBLARR,
            'IC_BPROPS': IC_BPROPS, 'IC_NAMES': IC_NAMES, 'IC_PS': IC_PS,
            'IC_GT1': IC_GT1, 'IC_GT2': IC_GT2, 'IC_HEAP': IC_HEAP,
            'IC_ARENA_SIZE': IC_ARENA_SIZE, 'IC_INST_SIZE': IC_INST_SIZE,
            'IC_NBUCKET': IC_NBUCKET, 'IC_NNODE': IC_NNODE,
            'IC_TBLCAP_MAX': IC_TBLCAP_MAX,
            'IC_BPROPS_MAX': IC_BPROPS_MAX, 'IC_HEAP_SIZE': IC_HEAP_SIZE,
            'IC_HEAP_FILL': IC_HEAP_FILL, 'IC_HEAP_GUARD': IC_HEAP_GUARD,
            'IC_HASH_MASK': IC_HASH_MASK,
            'IC_BUCKET_STRIDE': IC_BUCKET_STRIDE,
            'IC_ALARM_BASE': IC_ALARM_BASE, 'IC_ALARM_COUNT': IC_ALARM_COUNT,
            'IC_ALARM_STRIDE': IC_ALARM_STRIDE,
            'IC_VTABLE_OFF': IC_VTABLE_OFF}
    layout_bad = {k: {'header': got.get(k), 'harness': v}
                  for k, v in mine.items() if got.get(k) != v}

    bodies, ok = {}, not layout_bad
    for fn, spec in sorted(BODIES.items()):
        dis, words = _objdump(spec['entry'], spec['pool'], spec['end'])
        rows = subprocess.run(
            ['llvm-objdump', '-d', '--start-address=%#x' % spec['entry'],
             '--stop-address=%#x' % spec['end'], '-M', 'reg-names-std', SO],
            capture_output=True, text=True).stdout
        callees, internal, blx = {}, [], []
        for ln in rows.splitlines():
            m = re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(.*)$', ln)
            if not m:
                continue
            addr, rest = int(m.group(1), 16), m.group(2)
            if addr >= spec['pool']:
                continue
            fields = re.sub(r'\s+', ' ', rest.replace('\t', ' ')).split()
            if not fields:
                continue
            mnem, operand = fields[0], (fields[1] if len(fields) > 1 else '')
            sym = re.search(r'<([^>]+)>', rest)
            if mnem == 'blx' or (mnem == 'bx' and operand.startswith('r')
                                 and operand != 'lr'):
                blx.append(hex(addr))
            if mnem not in ('b', 'bl', 'bx', 'beq', 'bne', 'bgt', 'blt',
                            'bge', 'ble', 'bhi', 'bls', 'bcs', 'bcc',
                            'bmi', 'bpl', 'bvs', 'bvc'):
                continue
            if not operand.startswith('0x'):
                continue
            tgt = int(operand, 16)
            if spec['entry'] <= tgt < spec['end']:
                internal.append(hex(tgt))
            else:
                callees[hex(tgt)] = sym.group(1) if sym else None
        want = {hex(a): CALLEE_NAMES.get(a) for a in BODY_CALLEES[spec['name']]}
        part_ok = (callees == want and not blx
                   and len(dis) == spec['ninstr'] and len(words) == spec['npool'])
        bodies[spec['name']] = {
            'entry': hex(spec['entry']), 'end': hex(spec['end']),
            'bytes': spec['end'] - spec['entry'],
            'instructions': len(dis), 'pool_words': len(words),
            'callees': callees, 'expected_callees': want,
            'internal_branches': internal, 'indirect_calls': blx,
            'body_sha256': sha(MOD / 'src' / spec['src']),
            'ok': part_ok}
        ok = ok and part_ok

    return {'original_sha256': sha(SO), 'sha_matches_pin': sha(SO) == PIN,
            'bodies': bodies, 'arena_layout': got,
            'arena_layout_matches_harness': not layout_bad,
            'arena_layout_mismatch': layout_bad,
            'globals': {'g_ObjectHash': hex(G_HASH_PTR),
                        'instance_table': hex(G_INSTANCE_TABLE),
                        'create_counter': hex(G_CREATE_COUNTER),
                        'builtin_gate': hex(G_BUILTIN_GATE),
                        'builtin_numb': hex(G_BUILTIN_NUMB),
                        'builtin_table': hex(G_BUILTIN_TABLE),
                        'base_arg1': hex(G_BASE_ARG1),
                        'vtable_head': hex(G_VTABLE_HEAD),
                        'vtable_value': hex(VT_VALUE)},
            'ok': ok and sha(SO) == PIN}


def globals_check():
    """The GOT cells the two bodies read must still hold the addresses this
    fixture stages.  Read out of the pinned image, not assumed."""
    from elftools.elf.elffile import ELFFile
    want = {0x3edc44: G_HASH_PTR, 0x3edd1c: G_BASE_ARG1,
            0x3efb0c: G_CREATE_COUNTER, 0x3f0694: G_VTABLE_HEAD,
            0x3edc6c: G_INSTANCE_TABLE, 0x3edbc0: G_BUILTIN_GATE,
            0x3edc3c: G_BUILTIN_NUMB, 0x3edc40: G_BUILTIN_TABLE}
    out = {}
    with open(SO, 'rb') as f:
        elf = ELFFile(f)
        segs = [(s['p_vaddr'], s['p_memsz'], s['p_offset'], s['p_filesz'])
                for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
        f.seek(0)
        blob = f.read()
    for cell, target in want.items():
        val = None
        for va, ms, off, fs in segs:
            if va <= cell < va + ms and cell - va < fs:
                val = struct.unpack_from('<I', blob, off + (cell - va))[0]
        out[hex(cell)] = {'got_value': None if val is None else hex(val),
                          'expected': hex(target), 'ok': val == target}
    ok = all(v['ok'] for v in out.values())
    return {'cells': out, 'ok': ok}


# ── card re-check ────────────────────────────────────────────────────────────
CARD_DELTAS = [
    {'card': 'cards/CInstance_SetObjectIndex.c',
     'claim': '71 条 = 70 条指令 + 末 1 字池字 0x193364；+0x7c 先写后归一；'
              '查表键用原始 objindex；命中才置 +0x64 并尾调 CollisionMarkDirty',
     'bytes': '70 instructions 0x19324c..0x193360 + 1 pool word 0x193364 = 284 B; '
              'the arm reproduces every one of those claims, including the -1 / 0 '
              'asymmetry (cases 5..9) and the tail branch (0x19334c is a b, and '
              'CollisionMarkDirty runs with LR still the caller of '
              'SetObjectIndex)',
     'verdict': 'consistent'},
    {'card': 'cards/CInstance_SetObjectIndex.c',
     'claim': '字段来源：mask ← obj+0x10，visible ← bit1，solid ← bit0，'
              'persistent ← bit2，depth ← (float)(int)obj+0x08，sprite ← '
              'SetSpriteIndex(obj+0x04)',
     'bytes': 'every one reproduced; the flag/bit assignment is pinned by cases '
              '15 and 16 (flags 0x0d / 0xffffffff / 0x00000001) and the int '
              'reading of obj+0x08 by the 2^24+1 depth case',
     'verdict': 'consistent'},
    {'card': 'cards/CInstance_ctor.c',
     'claim': '257 条 = 249 条指令 + 8 池字；107 条直接存储 + 2 条循环（各 12 次）= '
              '131 次写；sizeof = 0x1b0；+0x144/+0x148/+0x178/+0x17c 谁都不写',
     'bytes': '249 instructions + 8 pool words = 1028 B, and the annotation '
              'census covers all of them; the arm writes 0xa5 into those four '
              'slots before the call and they still hold 0xa5 afterwards '
              '(coverage f2_untouched_slots_kept)',
     'verdict': 'consistent'},
    {'card': 'cards/CInstance_ctor.c',
     'claim': '基类第 1 实参来自 *(int*)0x544b48；实例表 0x536f0c {base,cap,count,'
              'next_free}；count>=cap 时 newcap = cap*3/2，YYRealloc + memset 新段',
     'bytes': 'GOT cells 0x003edd1c -> 0x00544b48, 0x003edc6c -> 0x00536f0c, and '
              'the growth arithmetic (3*cap + (3*cap >>u 31)) >>a 1 is reproduced '
              'byte for byte; both grow scenarios are exercised (4->6 and 2->3)',
     'verdict': 'consistent'},
    {'card': 'cards/CInstance_ctor.c',
     'claim': '内建属性表基址 0x75310c，16B 项；count 0x753108',
     'bytes': 'exactly right, and the distinction matters: the GOT cell '
              '0x003edc40 holds 0x0075310c, and `ldr r4,[r8,r3]` at 0x199800 IS '
              'the single dereference that reaches it - the table starts AT '
              '0x0075310c, it is not a pointer stored there. The first draft of '
              'this fixture modelled it as a pointer variable and arm A then '
              'read the .bss zeros; the trace of 0x19981c settled it (r4 = '
              '0x00753114 on the first iteration, i.e. table+8). count at '
              '0x00753108 is the mirror case: `ldr r7,[r8,r3]` gives the '
              'address and `ldr r3,[r7]` reads the integer',
     'verdict': 'consistent (the card\'s reading is the one the bytes support)'},
    {'card': 'cards/CInstance_ctor.c',
     'claim': 'open: cap<=0 时槽号 -1 仍是唯一"入表失败"分支',
     'bytes': 'true, but the negative-capacity edge is worse than "slot -1": '
              'with cap < 0 the count>=cap test at 0x19976c is true, the grow '
              'path computes newcap = (3*cap + carry) >> 1 which is <= cap for '
              'every negative cap, and the `b 0x199770` at 0x1998bc skips the '
              'test - so the body oscillates between grow and scan for ever. '
              'Not exercised as a case (both arms would hang); recorded as a '
              'finding instead',
     'verdict': 'open, sharpened: cap < 0 does not fail, it loops'},
]
CARD_NOTE = ('No instruction address, opcode, offset or constant in the two '
             'cards disagrees with the bytes. One prose-level delta in '
             'cards/CInstance_ctor.c about 0x0075310c being the address of the '
             'builtin-table pointer variable rather than the table base, and one '
             'open question sharpened: a negative instance-table capacity makes '
             'the constructor loop for ever.')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('instance_ctor_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    bind = binding()
    gchk = globals_check()
    census = instruction_census()
    cself = census_selftest()

    base_bin = build_c(BUILD / 'instance_ctor.arm')
    c_recs = run_c_arm(base_bin, case_list)

    stage = Stage(Oracle())
    a_recs = [stage.run(c) for c in case_list]
    traces = {1: list(stage.traces[1]), 2: list(stage.traces[2])}

    def trace_of(i):
        fn = case_list[i].fn
        return traces[fn][sum(1 for j in range(i) if case_list[j].fn == fn)]

    rows, mismatches = [], []
    for i, (case, a, c) in enumerate(zip(case_list, a_recs, c_recs)):
        eq = same(a, c)
        rows.append({'case': case.as_dict(), 'original': a, 'rebuild': c,
                     'equal': eq})
        if not eq:
            mismatches.append(rows[-1])

    cm_lrs = [lr for per_case in stage.cm_traces for lr in per_case]
    # 0x193348 pops {r4,r5,r6,lr} and 0x19334c is a `b`, so the callee is
    # entered with the lr SetObjectIndex itself was called with - never with a
    # return address inside SetObjectIndex.  Two such lrs exist in this case
    # set: the oracle sentinel (direct calls) and 0x199664 (the bl inside the
    # constructor).
    tail_ev = {'entries': len(cm_lrs),
               'distinct_lr': sorted({hex(x) for x in cm_lrs}),
               'oracle_sentinel_lr': hex(SENTINEL),
               'ctor_resume_lr': hex(CTOR + 0x188),
               'none_inside_setobjectindex': all(
                   not (SOI <= x < SOI_END) for x in cm_lrs),
               'ok': bool(cm_lrs) and all(not (SOI <= x < SOI_END)
                                          for x in cm_lrs)
               and set(cm_lrs) <= {SENTINEL, CTOR + 0x188},
               'note': 'CollisionMarkDirty is entered with the lr its caller '
                       'was called with, so 0x19334c is a `b` and the callee\'s '
                       'return value is SetObjectIndex\'s own. The C arm cannot '
                       'observe lr; its side of the same contract is that '
                       'CollisionMarkDirty is the last call and the function '
                       'then returns'}

    stage2 = Stage(Oracle())
    a2 = [stage2.run(c) for c in case_list]
    c2 = run_c_arm(base_bin, case_list)
    repeat = {
        'runs_per_arm': 2,
        'rerun_kind': {'original': 'second Unicorn instance, same case order',
                       'rebuild': 'second qemu-arm process, same stdin blob'},
        'original_identical': all(same(x, y) for x, y in zip(a_recs, a2)),
        'rebuild_identical': all(same(x, y) for x, y in zip(c_recs, c2)),
        'original_log_sha256': [_digest(a_recs), _digest(a2)],
        'rebuild_log_sha256': [_digest(c_recs), _digest(c2)],
        'note': 'identical digests inside an arm are the repeatability '
                'evidence; the two arms agreeing with each other is the '
                'identity gate',
    }
    rep_ok = repeat['original_identical'] and repeat['rebuild_identical']

    coverage, covered_by = {}, {}
    for name, fn in COVER:
        hits = []
        for i, (c, a) in enumerate(zip(case_list, a_recs)):
            if fn(trace_of(i), a, c):
                hits.append(c.label)
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]

    teeth = [teeth_one(m, case_list, a_recs) for m in MUTANTS]
    teeth_by_fn = {'SetObjectIndex': 0, 'CInstance_ctor': 0}
    for t in teeth:
        body = 'SetObjectIndex' if t['file'] == 'set_object_index.c' \
            else 'CInstance_ctor'
        teeth_by_fn[body] += 1

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    status = 'PASS' if (identity and cov_ok and rep_ok and teeth_ok
                        and census['ok'] and cself['ok'] and bind['ok']
                        and gchk['ok'] and tail_ev['ok']) else 'FAIL'

    per_fn = {k: [r for r in rows if r['case']['fn'] == k] for k in (1, 2)}

    receipt = {
        'schema': 'cally-instance-ctor-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0x19324c / 0x1994dc executed over one staged arena, '
                           'with identical stubs on both arms; NOT device '
                           'execution'),
        'BINDING': {
            'original_sha256': PIN,
            'functions': bind['bodies'],
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'header_sha256': sha(MOD / 'src' / 'instance_ctor.h'),
            'arena_layout': bind['arena_layout'],
            'arena_layout_matches_harness':
                bind['arena_layout_matches_harness'],
            'globals': bind['globals'],
            'got_cells': gchk,
            'binding_checks': {
                'sha_matches_pin': bind['sha_matches_pin'],
                'linked_for_real': [
                    'CInstance::SetObjectIndex@0x19324c - arm A runs the '
                    'original bytes (also inside the constructor), arm B runs '
                    'src/set_object_index.c'],
                'stub_callees': ['%s@%#x' % (CALLEE_NAMES[a].split('@')[0], a)
                                 for a in (RM, AI, SI, CM, YB, GB, JS, ADD,
                                           RA, MS)],
                'ok': bind['ok'] and gchk['ok'],
            },
        },
        'scope': {
            'covered': [
                'F1: no old object (0x19326c) and a live old object (0x193274 '
                'RemoveInstance) - and the index is re-read from +0x7c after '
                'the call, which an instrumented stub makes observable',
                'F1: objindex -1 is stored as 0 but LOOKED UP as -1; a hash '
                'node keyed -1 hits while the field says 0, and objindex 0 '
                'with a node keyed 0 hits independently (cases 5..7)',
                'F1: empty bucket, head match, second-node match, chain '
                'exhaustion, and a matched node whose value is 0 (cases 1, '
                '10..14)',
                'F1: addToObject true / false / 2 - AddInstance strictly '
                'before the field copy, and +0x80 re-read after it (an '
                'instrumented AddInstance re-points it, so the copy visibly '
                'uses OBJ3)',
                'F1: the six copied fields incl. all three flag bits, bits 3+ '
                'ignored, depth as (float)(int) for INT_MAX / 2^24+1 / INT_MIN '
                'and sprite handed to SetSpriteIndex',
                'F1: a hit sets +0x64 and tail-calls CollisionMarkDirty; a '
                'miss leaves +0x64 alone and calls nothing',
                'F2: every documented field store of the 0x1b0-byte object, '
                'alarm[0..11] twice (0 then -1, twelve times each), the three '
                'self rings, the create-counter snapshot, the two image 1.0f '
                'groups, gravity_direction 270.0f, +0x16c = 2, +0x48 = 1',
                'F2: +0x80 cleared before SetObjectIndex, proven on a stale '
                'block that already held an object pointer (case 12)',
                'F2: the instance table - slot -1 with cap 0, a part-full '
                'scan, the next_free==cap clamp, two grow paths (4->6 and 2->3 '
                'with realloc + zeroed tail) and the slot landing in +0x44',
                'F2: the builtin loop - gate off, count 0, two registrations, '
                'the isGlobalBuiltinVar skip (first entry, and both entries)',
                'F2: the base ctor gate writes +0x10/+0x14 and the ctor clears '
                'both; the base argument is forwarded verbatim incl. INT_MIN',
                'F2: prefilled 0xa5 blocks and the four slots nobody writes '
                '(0x144/0x148/0x178/0x17c) survive',
                'second-run reproducibility of both arms'],
            'not_covered': [
                'CObjectGM::RemoveInstance / AddInstance semantics (stubbed): '
                'these arms prove they are called once, in that order, with the '
                'right object and instance; the stubs also scribble +0x7c and '
                're-point +0x80 on purpose, which is a probe, not a claim',
                'CInstance::SetSpriteIndex semantics (stubbed): the stub writes '
                '+0x8c and nothing else. The real body also resets +0x90 when '
                'the sprite does not exist, frees a CSkeletonInstance at +0x88, '
                'sets +0x64 and tail-calls CollisionMarkDirty',
                'CollisionMarkDirty semantics (stubbed): log only, so the '
                '0x198/0x19c/0x1a0 dirty list is not exercised here',
                'YYObjectBase::YYObjectBase semantics (stubbed): the write set '
                'is the one cards/CInstance_ctor.c documents, and it is a '
                'fixture assumption. The ctor overwrites +0x00, +0x44 and '
                '+0x48; the leftovers are compared but not attributed',
                'isGlobalBuiltinVar / JS_SetupBuiltinProperty / '
                'YYObjectBase::Add semantics (stubbed): the loop shape, the '
                'entry stride, the skip decision and the three call arguments '
                'are proven, the property machinery is not',
                'YYRealloc semantics (stubbed): the bump allocator and its '
                '0x5b fill / 0xdeadbeef guard are a fixture model, identical on '
                'both arms',
                'the negative-capacity table edge (cap < 0) - the original '
                'loops for ever there, so it is not a case; see card_deltas',
                'device behaviour'],
            'not_applicable': [
                'Neither body reads a rodata string or calls a PLT entry except '
                'memset in the table-grow path, so there is no error-message '
                'contract to compare.',
                'SetObjectIndex has no stack argument and no floating-point '
                'input: its whole input domain is (int32 objindex, int32 bool).'],
        },
        'findings': [
            'F1 re-reads +0x7c from memory after RemoveInstance returns '
            '(0x193278) instead of keeping the argument in a register, and it '
            're-reads +0x80 after AddInstance returns (0x19335c) instead of '
            'keeping the node value. Both are observable only because the '
            'stubs are instrumented, and both are reproduced by the C.',
            'The -1 / 0 asymmetry is real and testable: +0x7c is normalised to '
            '0, the hash key is not. A node keyed -1 is reachable only through '
            'objindex == -1 (bucket 7), and objindex 0 reaches a node keyed 0 '
            '(bucket 0) - the two requests differ.',
            'A matched node with a NULL value is not a hit: +0x80 becomes 0 and '
            'the function returns at 0x1932f4 without touching +0x64 or calling '
            'CollisionMarkDirty. The instance keeps its previous sprite, mask, '
            'flags and depth.',
            '+0x64, +0x65, +0x66 and +0x67 are four bytes of ONE word: the bbox '
            'dirty bit, visible, solid and persistent. Any dump or comparison '
            'that reads +0x64 as a word is reading all four at once, which is '
            'why the coverage checks use the byte.',
            'The alarm array is written twice: zero first (a loop over +0xf8 + '
            '4*i, 12 times) and then -1 (a second loop over the same range). '
            'The first pass is redundant against a fresh block but not against '
            'a reused one, which is why the prefilled cases matter.',
            'The constructor clears +0x80 at 0x19964c before calling '
            'SetObjectIndex, so the RemoveInstance branch is unreachable from '
            'the constructor even on a recycled instance - mutant '
            'ctor_object_pointer_not_precleared shows exactly that: with a '
            'stale +0x80 the mutant calls RemoveInstance and the original does '
            'not.',
            'A table with cap 0 is not "no work": count >= cap holds (0 >= 0), '
            'so the grow path runs once with newcap = 0, i.e. YYRealloc(base, 0) '
            'and memset(ptr, 0, 0) are both called, cap stays 0, and only then '
            'does the scan report slot -1. The call log of that case is the '
            'evidence (RA ... 0 / MS ... 0).',
            'Instance-table growth is (3*cap + ((3*cap) >>u 31)) >>a 1, i.e. '
            'floor(1.5*cap) for positive cap, and the scan restarts at 0x199770 '
            'so the count>=cap test is not repeated for the grown table.',
            'The builtin count is re-read from 0x753108 on every iteration '
            '(0x19980c and 0x199850) while the table base is cached in r4 at '
            '0x199800 - a callee that changed the base would not be seen, a '
            'callee that changed the count would.',
            'card/byte agreement: every address, opcode, offset and constant in '
            'the two cards was re-checked against llvm-objdump; see '
            'card_deltas. One prose fix, one open question sharpened.'],
        'card_deltas': CARD_DELTAS,
        'card_note': CARD_NOTE,
        'instruction_census': census,
        'census_selftest': cself,
        'repeat': repeat,
        'tail_call_evidence': tail_ev,
        'cases': len(case_list),
        'cases_f1': len(per_fn[1]),
        'cases_f2': len(per_fn[2]),
        'heap_model': {'fill_byte': '0x%02x' % IC_HEAP_FILL,
                       'guard_word': '0x%08x' % IC_HEAP_GUARD,
                       'align': 16,
                       'note': 'bump allocator over IC_HEAP inside the arena; '
                               'identical on both arms; the fill is invisible '
                               'in a correct run by construction and becomes '
                               'visible when a translation mis-sizes the '
                               'memset (mutant ctor_memset_len)'},
        'rows': rows,
        'coverage': coverage,
        'covered_by': covered_by,
        'teeth': teeth,
        'teeth_total': len(teeth),
        'teeth_by_function': teeth_by_fn,
        'teeth_modes': {m: sum(1 for t in teeth if t['mode'] == m)
                        for m in sorted({t['mode'] for t in teeth})},
        'teeth_note': 'a mutant whose batch aborts is re-diagnosed one case per '
                      'process: the cases named in caught_by are field-level '
                      'mismatches, the ones in aborted_cases crashed the C arm. '
                      'No tooth relies on the abort alone.' if all(
                          t['field_level'] for t in teeth if t['passed'])
                      else 'WARNING: at least one tooth is caught by an abort '
                           'only - see the mode field',
        'status': status,
    }
    out = args.out or (RECEIPTS / ('instance_ctor_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d (F1 %d, F2 %d) identical=%d '
          'binding=%s census=%d/%d census-self=%s got=%s tail=%s'
          % (status, len(case_list), len(per_fn[1]), len(per_fn[2]),
             sum(1 for r in rows if r['equal']),
             'ok' if bind['ok'] and gchk['ok'] else 'BAD',
             census['documented'], census['instructions'],
             'ok' if cself['ok'] else 'BAD',
             'ok' if gchk['ok'] else 'BAD',
             'ok' if tail_ev['ok'] else 'BAD'))
    print('  REPEAT second-run identical  original=%s rebuild=%s' % (
        'yes' if repeat['original_identical'] else 'NO',
        'yes' if repeat['rebuild_identical'] else 'NO'))
    for k, v in coverage.items():
        print('  COVER %-40s %s  %s' % (k, 'yes' if v else 'NO',
                                        (covered_by.get(k) or [''])[0][:48]))
    for t in teeth:
        print('  TEETH %-38s %s caught_by=%d mode=%s aborted=%d' % (
            t['mutant'], 'PASS' if t['passed'] else 'FAIL',
            len(t['caught_by']), t['mode'], len(t['aborted_cases'])))
    for m in mismatches[:6]:
        print('  DIFF case=%r' % (m['case']['label'],))
        print('    original %r' % (m['original'],))
        print('    rebuild  %r' % (m['rebuild'],))
    for body in census:
        if not isinstance(census[body], dict) or 'wrong' not in census[body]:
            continue
        for w in census[body]['wrong'][:6]:
            print('  CENSUS %s %s objdump=%r source=%r'
                  % (body, w['addr'], w['objdump'], w['source']))
        for w in census[body]['pool_missing'][:6]:
            print('  CENSUS pool %s %s' % (body, w['addr']))
        for w in census[body]['duplicate_addresses'][:6]:
            print('  CENSUS dup %s %s' % (body, w['addr']))
        for w in census[body]['unknown_addresses'][:6]:
            print('  CENSUS extra %s %s' % (body, w['addr']))
    for m in cself['mutations']:
        if not m['ok']:
            print('  CENSUS-SELF %r applied=%s red_at=%s expected=%s'
                  % (m['mutation'], m['applied'], m.get('red_at'),
                     m.get('expected_red_at')))
    for label, part in bind['bodies'].items():
        if not part['ok']:
            print('  BINDING %s callees=%r want=%r indirect=%r'
                  % (label, part['callees'], part['expected_callees'],
                     part['indirect_calls']))
    if bind['arena_layout_mismatch']:
        print('  BINDING layout mismatch %r' % (bind['arena_layout_mismatch'],))
    for cell, v in gchk['cells'].items():
        if not v['ok']:
            print('  BINDING got cell %s = %r want %r'
                  % (cell, v['got_value'], v['expected']))
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
