#!/usr/bin/env python3
"""Variable-name side of libyoyo — original-binary differential (Level A, 2 functions).

Functions under judgement, both from the pinned image
(3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):

  F1  _Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc  @0xd21ec
      13 instructions + 2 literal-pool words, 60 B.  No frame; both exits are
      `b` tail jumps, so its return value is its callee's.
  F2  _Z22Variable_GetObjectNameii                              @0x1f3f8c
      71 instructions + 9 literal-pool words, 320 B.  Seven exits.

Two arms, same inputs, same staged memory:
  arm A (judge)  the original bytes, executed in Unicorn over the real .bss the
                 GOT points at (0x544be0 host pointer, 0x47f295 mode byte,
                 0x536f28 instance table, 0x54298c Run_Room, 0x75505c flag)
  arm B (claim)  reconstruction/reverse-v1/c/variable_names/, cross-compiled for
                 armv7a-none-eabi (freestanding) and run under qemu-arm

Why arm B must not be host-compiled: vn_node's key has to land at +8 and its
instance at +0xc, the bucket has to be 8 B, and the two GOT globals have to be
one word each.  A 64-bit host build moves every one of them by 4 and the test
stops testing the offsets the original actually uses.

Scope, stated up front — every callee of both bodies is unrecovered, so both
arms run IDENTICAL stubs for them:
  0x000d1f74  Code_Variable_Find_Slot_From_Local_Name   (CHashMap<char const*,int>)
  0x000d2054  Code_Variable_Find_Slot_From_Global_Name  (linear strcmp scan)
  0x0019ed54  Object_Name(int)
A green run therefore proves these two bodies' dispatch, field offsets, pointer
normalisation and return plumbing — not those callees, and not device
equivalence.  It also does not cover Object_Name's own "<undefined>" fallback
(0x330ac8), which is one level down.

Gates:
  * binding    image sha256, the five GOT-slot -> .bss chains this file stages,
               and the rodata string every failure exit returns
  * census     every reachable instruction of the original appears in the
               translation as an `@0xADDR <verbatim llvm-objdump text>` comment,
               each address exactly once, and each literal-pool word is
               documented with its value
  * identity   every case identical on both arms (return value, ordered call
               log, failure byte)
  * coverage   every decision of the ORIGINAL body is taken, proven by its own
               instruction trace (COVER)
  * repeat     both arms rerun in a second process reproduce their records
  * teeth      every source-level mutant of the translations is caught by at
               least one named case; a green mutant means the case set does not
               exercise that decision

Usage:
  python3 var_names_diff.py            # build, run both arms, write receipt
  python3 var_names_diff.py --no-run   # replay the gates on the last receipt
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
MOD = RV1 / 'c' / 'variable_names'
BUILD = HERE / 'build' / 'var_names'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_PC, UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

# ── F1 Code_Variable_Find_Slot_From_Name ────────────────────────────────────
F1 = 0xd21ec
F1_POOL = 0xd2220
F1_END = 0xd2228
LOCAL_NAME = 0xd1f74
GLOBAL_NAME = 0xd2054

# ── F2 Variable_GetObjectName ───────────────────────────────────────────────
F2 = 0x1f3f8c
F2_POOL = 0x1f40a8
F2_END = 0x1f40cc
OBJECT_NAME = 0x19ed54

# ── the .bss objects, reached through the GOT cells the disassembly names ───
GOT_HOST = 0x3edbbc        # -> 0x544be0, cell HOLDS a pointer  (one extra ldr)
BSS_HOST = 0x544be0
GOT_MODE = 0x3edbc0        # -> 0x47f295, cell IS the address of the byte
BSS_MODE = 0x47f295
GOT_ID2INST = 0x3edc4c     # -> 0x536f28, cell IS the table struct
BSS_ID2INST = 0x536f28
GOT_RUNROOM = 0x3ed930     # -> 0x54298c, cell HOLDS a pointer
BSS_RUNROOM = 0x54298c
GOT_FAILFLAG = 0x3edd68    # -> 0x75505c, cell IS the address of the byte
BSS_FAILFLAG = 0x75505c

RO_PLACEHOLDER = 0x3527e4
MSG_PLACEHOLDER = '<unknown_object>'

NINST = 4
INST_SIZE = 0x180
NBUCK = 8
NNODE = 4
INT_MIN = -0x80000000
INT_MAX = 0x7fffffff
NAME_MAX = 40


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
    label: str

    def args(self):
        return (self.fn, self.p0, self.p1, self.p2, self.p3, self.p4, self.p5,
                self.p6)

    def as_dict(self):
        return {k: getattr(self, k) for k in
                ('fn', 'p0', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'label')}


def cases():
    """Deterministic; the same list, in the same order, on every rerun.

    F1 fields: self_kind mode host_kind local_ret global_ret name_tag (unused)
    F2 fields: id varid bucket_mode room_mode objindex mask_override (unused)
    """
    return [
        # ── F1: the dispatch and the two tail jumps ──────────────────────────
        Case(1, 1, 0, 0, 5, -1, 0, 0,
             'F1 self != host -> local table, hit slot 5'),
        Case(1, 1, 0, 0, -1, 7, 0, 0,
             'F1 self != host -> local table, miss (-1)'),
        Case(1, 0, 0, 0, -1, 3, 0, 0,
             'F1 self == host, mode 0 -> GLOBAL table, hit slot 3'),
        Case(1, 0, 0, 0, 3, -1, 0, 0,
             'F1 self == host, mode 0 -> GLOBAL table, miss (-1)'),
        Case(1, 0, 1, 0, 4, 9, 0, 0,
             'F1 self == host, mode 1 -> local fallback (mode != 0)'),
        Case(1, 0, 255, 0, 4, 9, 0, 0,
             'F1 self == host, mode 255 -> local fallback'),
        Case(1, 1, 0, 0, 0, 9, 0, 0,
             'F1 local returns slot 0: 0 is a legal slot, not "absent"'),
        Case(1, 1, 0, 0, INT_MIN, 9, 0, 0,
             'F1 INT_MIN passes through untouched (no normalisation)'),
        Case(1, 1, 0, 0, 100, 200, 1, 0,
             'F1 empty name "" forwarded as-is to the local table'),
        Case(1, 1, 0, 0, 5, -1, 3, 0,
             'F1 NULL name forwarded as-is to the local table'),
        Case(1, 0, 0, 0, 5, -1, 3, 0,
             'F1 NULL name on the GLOBAL path (mode 0)'),
        Case(1, 1, 0, 0, 100, 200, 2, 0,
             'F1 distinct local/global answers: which table ran is visible'),
        Case(1, 0, 0, 1, 2, -1, 2, 0,
             'F1 host pointer NULL and self NULL -> equal, GLOBAL branch'),
        Case(1, 1, 0, 1, 2, -1, 2, 0,
             'F1 host pointer NULL and self non-NULL -> local branch'),
        Case(1, 0, 1, 1, 2, -1, 2, 0,
             'F1 host pointer NULL, self NULL, mode 1 -> local branch'),
        Case(1, 2, 0, 0, 7, 8, 0, 0,
             'F1 self NULL vs a live host pointer -> local branch'),

        # ── F2: id == -3, the room instance chain ───────────────────────────
        Case(2, -3, 0, 0, 0, 100, 0, 0,
             'F2 id -3, empty room -> flag=1 + placeholder'),
        Case(2, -3, 0, 0, 1, 100, 0, 0,
             'F2 id -3, single live instance -> Object_Name(100)'),
        Case(2, -3, 0, 0, 2, 100, 0, 0,
             'F2 id -3, destroyed then live -> Object_Name(101)'),
        Case(2, -3, 0, 0, 3, 100, 0, 0,
             'F2 id -3, deactivated then live -> Object_Name(101)'),
        Case(2, -3, 0, 0, 4, 100, 0, 0,
             'F2 id -3, destroyed + deactivated, then live -> Object_Name(102)'),
        Case(2, -3, 0, 0, 5, 100, 0, 0,
             'F2 id -3, every instance dead -> flag=1 + placeholder'),
        Case(2, -3, 0, 0, 6, 100, 0, 0,
             'F2 id -3, live head with a live next -> stops at the head (100)'),

        # ── F2: the two negative exits ──────────────────────────────────────
        Case(2, -1, 0, 0, 1, 100, 0, 0,
             'F2 id -1 -> placeholder, flag NOT set'),
        Case(2, -10, 0, 0, 1, 100, 0, 0,
             'F2 id -10 (what DoPop passes) -> placeholder, no flag'),
        Case(2, INT_MIN, 0, 0, 1, 100, 0, 0,
             'F2 id INT_MIN -> placeholder, no flag'),
        Case(2, -4, 0, 0, 1, 100, 0, 0,
             'F2 id -4 (one below -3) -> placeholder, not the room branch'),

        # ── F2: 0..99999 is an object index, no table at all ───────────────
        Case(2, 0, 0, 0, 1, 100, 0, 0,
             'F2 id 0 -> Object_Name(0) straight through'),
        Case(2, 99999, 0, 0, 1, 100, 0, 0,
             'F2 id 99999 (upper boundary, ble) -> Object_Name(99999)'),
        Case(2, 100000, 0, 0, 1, 100, 0, 0,
             'F2 id 100000 (one past the boundary) -> hash path, empty bucket'),

        # ── F2: id > 99999, ms_ID2InstanceE ─────────────────────────────────
        Case(2, 100000, 0, 1, 1, 100, 0, 0,
             'F2 id 100000 -> hash hit, live -> Object_Name(103)'),
        Case(2, 100001, 0, 2, 1, 100, 0, 0,
             'F2 id 100001 -> node staged in the NEIGHBOUR bucket, so empty'),
        Case(2, 100002, 0, 3, 1, 100, 0, 0,
             'F2 id 100002 -> chain of one, key mismatch -> chain end'),
        Case(2, 100003, 0, 4, 1, 100, 0, 0,
             'F2 id 100003 -> walk the chain (key+1 first) then hit (103)'),
        Case(2, 100004, 0, 5, 1, 100, 0, 0,
             'F2 id 100004 -> key match but node value NULL -> placeholder'),
        Case(2, 100005, 0, 6, 1, 100, 0, 0,
             'F2 id 100005 -> hash hit, instance +0x68 != 0 -> placeholder'),
        Case(2, 100006, 0, 7, 1, 100, 0, 0,
             'F2 id 100006 -> hash hit, +0x69 ONLY: still names it (103)'),
        Case(2, INT_MAX, 0, 1, 1, 100, 0, 0,
             'F2 id 0x7fffffff -> hash path, bucket = id & mask -> 103'),

        # ── F2: the mask is used, and 8 B per bucket ────────────────────────
        Case(2, 100012, 0, 1, 1, 100, 3, 0,
             'F2 id 100012, mask 3 -> bucket 0 (id&7 would be 4) -> 103'),
        Case(2, 100013, 0, 1, 1, 100, 3, 0,
             'F2 id 100013, mask 3 -> bucket 1 (id&7 would be 5) -> 103'),

        # ── F2: varid is a dead parameter ───────────────────────────────────
        Case(2, 100006, 4242, 7, 1, 100, 0, 0,
             'F2 dead varid 4242: same id as the +0x69 case, same record'),
        Case(2, 100006, INT_MIN, 7, 1, 100, 0, 0,
             'F2 dead varid INT_MIN: same id again, same record'),
    ]


# ── coverage: decisions of the ORIGINAL bodies, proven by their own trace ───
def _tk(tr, a, b):
    for i in range(len(tr) - 1):
        if tr[i] == a and tr[i + 1] == b:
            return True
    return False


def _ex(tr, a):
    return a in tr


def _stub(rec, k):
    return [c for c in rec['calls'] if c[0] == k]


def _name_len(rec, k):
    hits = _stub(rec, k)
    return hits[0][1] if hits else None


def _retstr(r):
    return r['ret'] if isinstance(r['ret'], str) else ''


def _f1_name_forwarded(tr, r, c):
    """The callee received the case's name bytes, not a shifted or NULL one."""
    if c.fn != 1 or not r['calls'] or r['calls'][0][0] not in ('L', 'G'):
        return False
    entry = r['calls'][0]
    return entry[1] > 0 and len(entry) > 2 and entry[2] == NAMES[c.p5]


COVER = [
    # F1
    ('f1_local_beq_not_taken', lambda tr, r, c: _tk(tr, F1 + 0x14, F1 + 0x18)),
    ('f1_host_branch_taken', lambda tr, r, c: _tk(tr, F1 + 0x14, F1 + 0x1c)),
    ('f1_global_tail', lambda tr, r, c: _tk(tr, F1 + 0x2c, F1 + 0x30)),
    ('f1_mode_nonzero_local', lambda tr, r, c: _tk(tr, F1 + 0x2c, F1 + 0x18)),
    ('f1_name_forwarded', _f1_name_forwarded),
    ('f1_empty_name', lambda tr, r, c: c.p5 == 1
     and any(x == 0 for x in (_name_len(r, 'L'), _name_len(r, 'G')))),
    ('f1_null_name', lambda tr, r, c: c.p5 == 3
     and -1 in (_name_len(r, 'L'), _name_len(r, 'G'))),
    ('f1_slot_zero', lambda tr, r, c: r['ret'] == 0 and bool(r['calls'])),
    ('f1_minus_one', lambda tr, r, c: r['ret'] == -1 and bool(r['calls'])),
    ('f1_int_min_passthrough', lambda tr, r, c: r['ret'] == INT_MIN),
    ('f1_host_pointer_null', lambda tr, r, c: c.p2 == 1
     and _tk(tr, F1 + 0x14, F1 + 0x1c)),
    # F2
    ('f2_all_branch', lambda tr, r, c: _tk(tr, F2 + 0x08, F2 + 0x84)),
    ('f2_negative_exit', lambda tr, r, c: _tk(tr, F2 + 0x10, F2 + 0xf8)),
    ('f2_objindex_exit', lambda tr, r, c: _tk(tr, F2 + 0x20, F2 + 0xcc)),
    ('f2_hash_empty_bucket', lambda tr, r, c: _tk(tr, F2 + 0x40, F2 + 0x44)),
    ('f2_hash_chain_end', lambda tr, r, c: _tk(tr, F2 + 0x50, F2 + 0xd0)),
    ('f2_hash_walk', lambda tr, r, c: _tk(tr, F2 + 0x5c, F2 + 0x48)),
    ('f2_hash_value_null', lambda tr, r, c: _tk(tr, F2 + 0x68, F2 + 0x110)),
    ('f2_hash_destroyed', lambda tr, r, c: _tk(tr, F2 + 0x74, F2 + 0x78)),
    ('f2_hash_live', lambda tr, r, c: _tk(tr, F2 + 0x74, F2 + 0xc8)),
    ('f2_all_room_empty', lambda tr, r, c: _tk(tr, F2 + 0x98, F2 + 0x9c)),
    ('f2_all_advance_destroyed', lambda tr, r, c: _tk(tr, F2 + 0xb8, F2 + 0xa0)),
    ('f2_all_advance_deactivated', lambda tr, r, c: _tk(tr, F2 + 0xc4, F2 + 0xa0)),
    ('f2_all_chain_end', lambda tr, r, c: _tk(tr, F2 + 0xa8, F2 + 0xdc)),
    ('f2_all_live', lambda tr, r, c: _tk(tr, F2 + 0xc4, F2 + 0xc8)),
    ('f2_flag_set', lambda tr, r, c: r['flag'] == 1),
    ('f2_flag_untouched_on_other_exits', lambda tr, r, c: (
        c.fn == 2 and r['flag'] == 0 and _retstr(r).startswith('UNK'))),
    ('f2_room_chain_loaded', lambda tr, r, c: _ex(tr, F2 + 0x90)),
    ('f2_mask_honoured', lambda tr, r, c: c.p5 == 3 and _retstr(r).startswith('NAME')),
    ('f2_dead_varid_ignored', lambda tr, r, c: c.p1 not in (0,) and c.p0 == 100006
     and _retstr(r).startswith('NAME')),
]

# The three names a name_tag can select; the fixture stages them and the
# harness passes the same bytes to both arms.
NAMES = ['alpha', '', 'beta', None]


def _dead_varid_same(rows):
    """Two cases that differ only in varid must produce identical records."""
    by_id = {}
    for c, a in rows:
        if c.fn != 2 or c.p0 != 100006:
            continue
        key = (c.p2, c.p3, c.p4, c.p5, c.p6)
        rec = (a['ret'], json.dumps(a['calls']), a['flag'])
        by_id.setdefault(key, []).append(rec)
    return any(len(set(v)) == 1 and len(v) > 1 for v in by_id.values())


# ── original arm ─────────────────────────────────────────────────────────────
def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


class Stage:
    """One staged environment, hooks installed exactly once.

    Per case only the staged words are rewritten and the logs cleared: adding
    hooks per case would leave the previous case's hooks live on the same
    Unicorn instance and they would keep appending to their own logs.
    """

    def __init__(self, o):
        self.o = o
        self.log = []
        self.tr = []
        self.traces = []
        # name strings, laid out once: "alpha\0" "beta\0" (empty = the second)
        self.names = o.alloc(32)
        o.write(self.names, b'alpha\0\0beta\0' + b'\0' * 20)
        self.name_ptr = {0: self.names, 1: self.names + 6, 2: self.names + 7}
        self.objname = o.alloc(64)
        self.host_obj = o.alloc(0x40)
        self.other_obj = o.alloc(0x40)
        self.buckets = o.alloc(NBUCK * 8)
        self.nodes = o.alloc(NNODE * 16)
        self.insts = o.alloc(NINST * INST_SIZE)
        self.room = o.alloc(0x88)
        for addr, fn in ((LOCAL_NAME, self.hook_local),
                         (GLOBAL_NAME, self.hook_global),
                         (OBJECT_NAME, self.hook_objname)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F1, end=F1_POOL - 4)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F2, end=F2_POOL - 4)

    # -- hooks --------------------------------------------------------------
    def hook_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def _read_name(self, addr):
        """len == -1 for NULL, else the byte count (capped), printable only."""
        if addr == 0:
            return -1, ''
        out = bytearray()
        for i in range(NAME_MAX):
            b = self.o.read(addr + i, 1)[0]
            if b == 0:
                break
            out.append(b if 0x20 <= b <= 0x7e else ord('?'))
        return len(out), out.decode('latin-1')

    def _ret_name(self, kind, addr):
        n, s = self._read_name(addr)
        self.log.append([kind, n, s])

    def hook_local(self, uc_, _a, _s, _d):
        self._ret_name('L', uc_.reg_read(UC_ARM_REG_R0))
        uc_.reg_write(UC_ARM_REG_R0, self.local_ret & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_global(self, uc_, _a, _s, _d):
        self._ret_name('G', uc_.reg_read(UC_ARM_REG_R0))
        uc_.reg_write(UC_ARM_REG_R0, self.global_ret & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_objname(self, uc_, _a, _s, _d):
        idx = to_i32(uc_.reg_read(UC_ARM_REG_R0))
        self.log.append(['O', idx])
        blob = ('OBJ%d' % idx).encode()
        self.o.write(self.objname, blob + b'\0')
        uc_.reg_write(UC_ARM_REG_R0, self.objname)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    # -- staging ------------------------------------------------------------
    def _w(self, addr, w):
        self.o.write(addr, struct.pack('<I', w & 0xffffffff))

    def _inst(self, i):
        return self.insts + i * INST_SIZE

    def stage_f1(self, case):
        _, self_kind, mode, host_kind, self.local_ret, self.global_ret, tag, _u = case.args()
        o = self.o
        host = 0 if host_kind else self.host_obj
        o.write(BSS_HOST, struct.pack('<I', host))
        o.write(BSS_MODE, struct.pack('<B', mode & 0xff))
        # the body never touches 0x75505c; staging it to 0 keeps this record
        # comparable with the C arm, which zeroes it per case, and still lets a
        # write by the body show up in the post-call read
        o.write(BSS_FAILFLAG, b'\0')
        if self_kind == 0:
            sel = host
        elif self_kind == 1:
            sel = self.other_obj
        else:
            sel = 0
        self.log.clear()
        self.tr.clear()
        ret = o.call(F1, r0=sel, r1=0 if tag == 3 else self.name_ptr[tag])
        return {'ret': to_i32(ret), 'calls': list(self.log),
                'flag': o.read(BSS_FAILFLAG, 1)[0]}

    def stage_instances(self, objindex):
        o = self.o
        o.write(self.insts, b'\0' * (NINST * INST_SIZE))
        for i in range(NINST):
            base = self._inst(i)
            self._w(base + 0x7c, objindex + i)
            self._w(base + 0x178, 0)

    def stage_room(self, room_mode):
        o = self.o
        o.write(self.room, b'\0' * 0x88)
        if room_mode == 0:
            return
        self._w(self.room + 0x80, self._inst(0))
        if room_mode == 2:
            o.write(self._inst(0) + 0x68, b'\x01')
            self._w(self._inst(0) + 0x178, self._inst(1))
        elif room_mode == 3:
            o.write(self._inst(0) + 0x69, b'\x01')
            self._w(self._inst(0) + 0x178, self._inst(1))
        elif room_mode == 4:
            o.write(self._inst(0) + 0x68, b'\x01')
            self._w(self._inst(0) + 0x178, self._inst(1))
            o.write(self._inst(1) + 0x69, b'\x01')
            self._w(self._inst(1) + 0x178, self._inst(2))
        elif room_mode == 5:
            o.write(self._inst(0) + 0x68, b'\x01')
            self._w(self._inst(0) + 0x178, self._inst(1))
            o.write(self._inst(1) + 0x68, b'\x01')
        elif room_mode == 6:
            self._w(self._inst(0) + 0x178, self._inst(1))

    def stage_buckets(self, bucket_mode, idv, mask):
        """The hash path gets its OWN instance (the last one), so a bucket case
        can never perturb the room chain a room case is staging - they are two
        independent segments of the body and the fixture must not couple them."""
        o = self.o
        o.write(self.buckets, b'\0' * (NBUCK * 8))
        o.write(self.nodes, b'\0' * (NNODE * 16))
        if bucket_mode == 0:
            return
        hi = self._inst(NINST - 1)
        b = (idv & 0xffffffff) & mask
        if bucket_mode == 2:
            b ^= 1
        n0, n1 = self.nodes, self.nodes + 16
        if bucket_mode == 1:
            self._w(n0 + 0x8, idv)
            self._w(n0 + 0xc, hi)
        elif bucket_mode == 2:
            self._w(n0 + 0x8, idv)
            self._w(n0 + 0xc, hi)
        elif bucket_mode == 3:
            self._w(n0 + 0x8, idv + 1)
        elif bucket_mode == 4:
            self._w(n0 + 0x8, idv + 1)
            self._w(n0 + 0x4, n1)
            self._w(n1 + 0x8, idv)
            self._w(n1 + 0xc, hi)
        elif bucket_mode == 5:
            self._w(n0 + 0x8, idv)
        elif bucket_mode == 6:
            o.write(hi + 0x68, b'\x01')
            self._w(n0 + 0x8, idv)
            self._w(n0 + 0xc, hi)
        elif bucket_mode == 7:
            o.write(hi + 0x69, b'\x01')
            self._w(n0 + 0x8, idv)
            self._w(n0 + 0xc, hi)
        self._w(self.buckets + (b % NBUCK) * 8, n0)

    def stage_f2(self, case):
        _, idv, varid, bucket_mode, room_mode, objindex, mask, _u = case.args()
        o = self.o
        use_mask = mask if mask else NBUCK - 1
        self._w(BSS_ID2INST + 0x0, self.buckets)
        self._w(BSS_ID2INST + 0x4, use_mask)
        self.stage_instances(objindex)
        self.stage_room(room_mode)
        self.stage_buckets(bucket_mode, idv, use_mask)
        self._w(BSS_RUNROOM, self.room)
        o.write(BSS_FAILFLAG, b'\0')
        self.log.clear()
        self.tr.clear()
        ret = o.call(F2, r0=idv & 0xffffffff, r1=varid & 0xffffffff)
        return {'ret': self._classify(ret), 'calls': list(self.log),
                'flag': o.read(BSS_FAILFLAG, 1)[0]}

    def _classify(self, p):
        """(class, hexbytes) of the returned pointer, by content only: the two
        arms have different addresses, so an address is never compared."""
        n, s = self._read_name(p)
        if n < 0:
            return 'NULL:'
        if s == MSG_PLACEHOLDER:
            return 'UNK:' + s.encode().hex()
        if s.startswith('OBJ'):
            return 'NAME:' + s.encode().hex()
        return 'RAW:' + s.encode().hex()

    def run(self, case):
        rec = self.stage_f1(case) if case.fn == 1 else self.stage_f2(case)
        self.traces.append(list(self.tr))
        return rec


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

SRCS = ['find_slot_from_name.c', 'get_object_name.c']


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
    cmd = (['clang'] + ARM_FLAGS + ['-O1', '-I', str(MOD / 'src')] +
           [str(p) for p in srcs] +
           [str(MOD / 'fixture' / 'driver.c'), '-o', str(out_bin)])
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-3000:])
    return out_bin


def run_c_arm(binary, case_list):
    blob = ''.join('%d %d %d %d %d %d %d %d\n' % tuple(c.args())
                   for c in case_list).encode()
    p = subprocess.run(['qemu-arm', str(binary)], input=blob, capture_output=True)
    if p.returncode:
        raise RuntimeError('driver exit %d: %s' % (p.returncode,
                                                   p.stderr.decode()[-2000:]))
    recs, cur = [], None
    for line in p.stdout.decode('latin-1').splitlines():
        parts = line.split()
        if not parts:
            continue
        if parts[0] == 'CASE':
            cur = {'ret': None, 'calls': [], 'flag': 0}
            recs.append(cur)
        elif parts[0] == 'RET':
            cur['ret'] = int(parts[1]) if len(parts) == 2 else (parts[1] + ':' + parts[2])
        elif parts[0] == 'CALLS':
            cur['ncalls'] = int(parts[1])
        elif parts[0] == 'FLAG':
            cur['flag'] = int(parts[1])
        elif parts[0] in ('L', 'G'):
            cur['calls'].append([parts[0], int(parts[1]),
                                 parts[2] if len(parts) > 2 else ''])
        elif parts[0] == 'O':
            cur['calls'].append(['O', int(parts[1])])
    return recs


def same(a, b):
    """The only equality this file accepts: return value, the ordered call log,
    the failure byte.  'Not comparable' is never a pass."""
    return a['ret'] == b['ret'] and a['calls'] == b['calls'] and a['flag'] == b['flag']


def _digest(recs):
    return hashlib.sha256(json.dumps(
        [{k: r[k] for k in ('ret', 'calls', 'flag')} for r in recs],
        sort_keys=True).encode()).hexdigest()


# ── teeth ────────────────────────────────────────────────────────────────────
F1_LOCAL_A = ('    if (host != self) {\n'
              '        /* 0xd21fc is where self dies: from here the only argument is the name,\n'
              '         * which is exactly what both tail-jump targets take. */\n'
              '        /* @0xd21fc mov r0, r1 */\n'
              '        /* @0xd2204 b 0xd1f74 */\n'
              '        return Code_Variable_Find_Slot_From_Local_Name(name);')
F1_GLOBAL = '    return Code_Variable_Find_Slot_From_Global_Name(name);'

MUTANTS = [
    # ── F1: the dispatch ────────────────────────────────────────────────────
    {'name': 'f1_dispatch_inverted', 'file': 'find_slot_from_name.c', 'edits': [
        ('if (host != self) {', 'if (host == self) {')]},
    {'name': 'f1_mode_test_flipped', 'file': 'find_slot_from_name.c', 'edits': [
        ('if (g_varname_mode != 0)', 'if (g_varname_mode == 0)')]},
    {'name': 'f1_host_deref_dropped', 'file': 'find_slot_from_name.c', 'edits': [
        ('    host = g_varname_host;', '    host = (void *)&g_varname_host;')]},
    {'name': 'f1_name_pointer_shifted', 'file': 'find_slot_from_name.c', 'edits': [
        (F1_GLOBAL,
         '    return Code_Variable_Find_Slot_From_Global_Name(name + 1);')]},
    {'name': 'f1_local_return_normalised', 'file': 'find_slot_from_name.c', 'edits': [
        (F1_LOCAL_A, F1_LOCAL_A.replace(
            'return Code_Variable_Find_Slot_From_Local_Name(name);',
            'return -1;'))]},
    {'name': 'f1_global_return_normalised', 'file': 'find_slot_from_name.c', 'edits': [
        (F1_GLOBAL, '    return 7;')]},
    # ── F2: the field offsets and the branches ──────────────────────────────
    {'name': 'f2_destroyed_offset_68_to_6c', 'file': 'get_object_name.c', 'edits': [
        ('if (rdb(inst, YYB_DESTROYED) != 0) {',
         'if (rdb(inst, 0x6cu) != 0) {')]},
    {'name': 'f2_room_destroyed_offset_68_to_6a',
     'file': 'get_object_name.c', 'edits': [
        ('destroyed = rdb(cur, YYB_DESTROYED);',
         'destroyed = rdb(cur, 0x6au);')]},
    {'name': 'f2_deact_offset_69_to_6b', 'file': 'get_object_name.c', 'edits': [
        ('deact = rdb(cur, YYB_DEACT);', 'deact = rdb(cur, 0x6bu);')]},
    {'name': 'f2_deact_gate_added_in_hash', 'file': 'get_object_name.c', 'edits': [
        ('if (rdb(inst, YYB_DESTROYED) != 0) {',
         'if (rdb(inst, YYB_DESTROYED) != 0 || rdb(inst, YYB_DEACT) != 0) {')]},
    {'name': 'f2_node_key_is_value', 'file': 'get_object_name.c', 'edits': [
        ('if (idcopy != n->key) {',
         'if (idcopy != (int32_t)(uintptr_t)n->value) {')]},
    {'name': 'f2_bucket_stride_8_to_4', 'file': 'get_object_name.c', 'edits': [
        ('(u32)bucket * VN_BUCKET_STRIDE', '(u32)bucket * 4u')]},
    {'name': 'f2_objindex_boundary_lt', 'file': 'get_object_name.c', 'edits': [
        ('if (id <= VN_OBJINDEX_MAX)', 'if (id < VN_OBJINDEX_MAX)')]},
    {'name': 'f2_all_test_minus4', 'file': 'get_object_name.c', 'edits': [
        ('if (id == VN_ID_ALL)', 'if (id == -4)')]},
    {'name': 'f2_objectname_arg_is_id', 'file': 'get_object_name.c', 'edits': [
        ('return Object_Name((int32_t)rd32(inst, YYB_OBJINDEX));',
         'return Object_Name(idcopy);')]},
    {'name': 'f2_flag_write_dropped', 'file': 'get_object_name.c', 'edits': [
        ('    g_objname_fail = 1;\n', '')]},
    {'name': 'f2_mask_ignored', 'file': 'get_object_name.c', 'edits': [
        ('bucket = (u32)id & t->mask;', 'bucket = (u32)id & 7u;')]},
]


# ── card re-check ────────────────────────────────────────────────────────────
# Both cards were re-read against llvm-objdump before this arm was written, and
# again by the census gate on every run.  What was checked, and the answer:
CARD_DELTAS = [
    {'card': 'cards/Code_Variable_Find_Slot_From_Name.c',
     'claim': '@func 0xd21ec 0xd2228 size 60, 15 rows (13 instructions + 2 pool words)',
     'bytes': '13 instructions 0xd21ec..0xd2204, pool 0xd2220/0xd2224, 0x3c = 60 B',
     'verdict': 'consistent'},
    {'card': 'cards/Code_Variable_Find_Slot_From_Name.c',
     'claim': 'GOT 0x3edbbc -> .bss 0x544be0 (pointer, one extra ldr) and '
              'GOT 0x3edbc0 -> .bss 0x47f295 (byte, ldrb straight off the cell)',
     'bytes': 'the image\'s GOT cells hold exactly 0x544be0 and 0x47f295, and '
              '0xd21f4 is a third ldr while 0xd2210 is ldrb',
     'verdict': 'consistent'},
    {'card': 'cards/Code_Variable_Find_Slot_From_Name.c',
     'claim': 'only self == *g_host AND mode == 0 uses the global table',
     'bytes': '0xd2200 beq + 0xd2218 bne both fall back to 0xd2204; the global '
              'jump at 0xd221c is reachable only when both hold',
     'verdict': 'consistent'},
    {'card': 'cards/Variable_GetObjectName.c',
     'claim': '@func 0x1f3f8c 0x1f40cc size 320, 80 rows (71 instructions + 9 '
              'pool words)',
     'bytes': '71 instructions 0x1f3f8c..0x1f40a4, pool 0x1f40a8..0x1f40c8 (9), '
              '0x140 = 320 B',
     'verdict': 'consistent'},
    {'card': 'cards/Variable_GetObjectName.c',
     'claim': 'the second parameter (r1) is never read; 0x1f3fb8 overwrites it '
              'with the hash mask',
     'bytes': 'no instruction in 0x1f3f8c..0x1f3fb4 names r1; 0x1f3fb8 is '
              'ldr r1, [r3, #0x4]',
     'verdict': 'consistent'},
    {'card': 'cards/Variable_GetObjectName.c',
     'claim': 'six failure exits share one rodata string 0x3527e4, and only '
              '0x1f407c sets 0x75505c',
     'bytes': 'all six ldr/add pairs resolve to 0x3527e4, which holds exactly '
              '"<unknown_object>"; 0x1f407c is the only strb in the body',
     'verdict': 'consistent'},
    {'card': 'cards/Variable_GetObjectName.c',
     'claim': 'the id > 99999 hash path checks +0x68 only, while the room chain '
              'checks +0x68 and +0x69',
     'bytes': '0x1f3ff8 is the only ldrb on the hash path; 0x1f4038 and 0x1f4048 '
              'are the two on the room path',
     'verdict': 'consistent'},
    {'card': 'cards/Variable_GetObjectName.c',
     'claim': 'node layout {next@+4, id@+8, inst@+0xc} and 8 B buckets',
     'bytes': '0x1f3fc4 ldr r3,[r3,r1,lsl #3]; 0x1f3fd4 +4; 0x1f3fe0 +8; '
              '0x1f3fec +0xc',
     'verdict': 'consistent'},
]
CARD_NOTE = ('No card/byte delta.  Both cards\' addresses, instruction counts, '
             'pool sizes, field offsets, GOT->.bss chains and return conventions '
             'match the pinned bytes; nothing had to be corrected on the byte '
             'side, and the cases here pin every one of those claims.')

MUTANT_NOTES = {}


def _sample(case, a, r):
    return {'case': case.label,
            'ret': {'original': a['ret'], 'mutant': r['ret']},
            'calls': {'original': a['calls'], 'mutant': r['calls']},
            'flag': {'original': a['flag'], 'mutant': r['flag']}}


def teeth_one(m, case_list, a_recs):
    """Judge one mutant.  A batch that aborts is re-diagnosed one case per
    process: the crash belongs to the cases that crash, and every surviving
    case is still compared on all three facets."""
    b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
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


def instruction_census():
    """Every reachable instruction of the original must appear in the
    translation as `@0xADDR <verbatim operand text>`, each address exactly once,
    and every literal-pool word must be documented with its value.

    Stricter than the sibling census on one point: the text must match
    llvm-objdump *exactly* after whitespace collapse, not as a substring, so a
    typo'd offset (#0x2c0 for #0x2c) cannot hide inside a longer comment.
    """
    report = {}
    ok = True
    for label, entry, stop, pool, srcname in (
            ('Code_Variable_Find_Slot_From_Name', F1, F1_END, F1_POOL,
             'find_slot_from_name.c'),
            ('Variable_GetObjectName', F2, F2_END, F2_POOL,
             'get_object_name.c')):
        p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                            '--stop-address=%#x' % stop, '-M', 'reg-names-std', SO],
                           capture_output=True, text=True)
        if p.returncode:
            raise RuntimeError('llvm-objdump failed: %s' % p.stderr[-800:])
        dis, poolw = {}, {}
        for ln in p.stdout.splitlines():
            m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
            if not m:
                continue
            addr, word, rest = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
            if addr < pool:
                text = ' '.join(x for x in rest.split('\t') if x.strip())
                text = re.sub(r'\s*@.*$', '', text)
                text = re.sub(r'\s*<[^>]*>', '', text)
                dis[addr] = _norm(text)
            else:
                poolw[addr] = word
        cands = {}
        for ln in (MOD / 'src' / srcname).read_text().splitlines():
            m = ANCHOR.search(ln)
            if m:
                cands.setdefault(int(m.group(1), 16), []).append(_norm(m.group(2)))
        wrong = [{'addr': hex(a), 'objdump': dis[a], 'source': cands.get(a, [])}
                 for a in sorted(dis)
                 if a not in cands or dis[a] not in cands[a]]
        dupes = [{'addr': hex(a), 'texts': cands[a]}
                 for a in sorted(cands) if len(cands[a]) > 1]
        extra = [{'addr': hex(a), 'texts': cands[a]}
                 for a in sorted(cands)
                 if a not in dis and a not in poolw]
        pool_missing = [{'addr': hex(a), 'word': '%08x' % w}
                        for a, w in sorted(poolw.items())
                        if not any(('.word 0x%08x' % w) in c
                                   for c in cands.get(a, []))]
        part = {'function': label, 'instructions': len(dis),
                'documented': len(dis) - len(wrong), 'wrong': wrong,
                'duplicate_addresses': dupes, 'unknown_addresses': extra,
                'pool_words': len(poolw), 'pool_missing': pool_missing,
                'ok': not wrong and not dupes and not extra and not pool_missing}
        report[label] = part
        ok = ok and part['ok']
    report['ok'] = ok
    report['instructions'] = sum(v['instructions'] for k, v in report.items()
                                if isinstance(v, dict) and 'instructions' in v)
    report['documented'] = sum(v['documented'] for k, v in report.items()
                               if isinstance(v, dict) and 'documented' in v)
    return report


# ── binding ──────────────────────────────────────────────────────────────────
def sha(p):
    return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()


def rodata_string(so, vaddr):
    from elftools.elf.elffile import ELFFile
    with open(so, 'rb') as f:
        elf = ELFFile(f)
        for seg in elf.iter_segments():
            if (seg['p_type'] == 'PT_LOAD'
                    and seg['p_vaddr'] <= vaddr < seg['p_vaddr'] + seg['p_filesz']):
                off = seg['p_offset'] + (vaddr - seg['p_vaddr'])
                with open(so, 'rb') as g:
                    g.seek(off)
                    blob = g.read(128)
                return blob.split(b'\0')[0].decode('latin-1')
    raise RuntimeError('vaddr %#x not in any PT_LOAD' % vaddr)


def binding():
    """The five GOT cells this differential stages, read out of the image, plus
    the rodata string every failure exit returns."""
    o = Oracle()
    got = {}
    for name, cell, want in (('host', GOT_HOST, BSS_HOST),
                             ('mode', GOT_MODE, BSS_MODE),
                             ('id2inst', GOT_ID2INST, BSS_ID2INST),
                             ('runroom', GOT_RUNROOM, BSS_RUNROOM),
                             ('failflag', GOT_FAILFLAG, BSS_FAILFLAG)):
        w = struct.unpack('<I', bytes(o.read(cell, 4)))[0]
        got[name] = {'got': hex(cell), 'value': hex(w), 'expected': hex(want),
                     'ok': w == want}
    ph = rodata_string(SO, RO_PLACEHOLDER)
    return {
        'original_sha256': sha(SO),
        'sha_matches_pin': sha(SO) == PIN,
        'got_cells': got,
        'rodata_placeholder': {'at': hex(RO_PLACEHOLDER), 'text': ph,
                               'matches_translation': ph == MSG_PLACEHOLDER},
        'ok': (sha(SO) == PIN and all(v['ok'] for v in got.values())
               and ph == MSG_PLACEHOLDER),
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('var_names_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    bind = binding()
    census = instruction_census()

    base_bin = build_c(BUILD / 'var_names.arm')
    c_recs = run_c_arm(base_bin, case_list)

    stage = Stage(Oracle())
    a_recs = [stage.run(c) for c in case_list]
    traces = stage.traces

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_recs, c_recs):
        eq = same(a, c)
        rows.append({'case': case.as_dict(), 'original': a, 'rebuild': c,
                     'equal': eq})
        if not eq:
            mismatches.append(rows[-1])

    # repeat: second Unicorn instance + second qemu-arm process
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
        'note': 'identical digests inside an arm are the repeatability evidence; '
                'the two arms agreeing with each other is the identity gate',
    }
    rep_ok = repeat['original_identical'] and repeat['rebuild_identical']

    coverage, covered_by = {}, {}
    for name, fn in COVER:
        hits = [c.label for c, a, tr in zip(case_list, a_recs, traces)
                if fn(tr, a, c)]
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]
    coverage['f2_dead_varid_identical_records'] = _dead_varid_same(
        list(zip(case_list, a_recs)))

    teeth = [teeth_one(m, case_list, a_recs) for m in MUTANTS]

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    status = 'PASS' if (identity and cov_ok and rep_ok and teeth_ok
                        and census['ok'] and bind['ok']) else 'FAIL'

    f1_ok = [r for r in rows if r['case']['fn'] == 1]
    f2_ok = [r for r in rows if r['case']['fn'] == 2]

    receipt = {
        'schema': 'cally-var-names-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0xd21ec and 0x1f3f8c executed over staged .bss the '
                           'GOT actually points at, with identical stubs on both '
                           'arms; NOT device execution'),
        'BINDING': {
            'original_sha256': PIN,
            'functions': {
                'Code_Variable_Find_Slot_From_Name': {
                    'entry': hex(F1), 'range': [hex(F1), hex(F1_END)],
                    'instructions': 13, 'pool': [hex(F1_POOL), hex(F1_POOL + 4)],
                    'body_sha256': sha(MOD / 'src' / 'find_slot_from_name.c')},
                'Variable_GetObjectName': {
                    'entry': hex(F2), 'range': [hex(F2), hex(F2_END)],
                    'instructions': 71, 'pool': [hex(F2_POOL), hex(F2_END)],
                    'body_sha256': sha(MOD / 'src' / 'get_object_name.c')},
            },
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'header_sha256': sha(MOD / 'src' / 'variable_names.h'),
            'binding_checks': bind,
            'stub_callees': [
                'Code_Variable_Find_Slot_From_Local_Name@0xd1f74',
                'Code_Variable_Find_Slot_From_Global_Name@0xd2054',
                'Object_Name@0x19ed54'],
        },
        'scope': {
            'covered': [
                'F1: self == *g_host and mode byte 0 -> global name table',
                'F1: self != host -> local name table (hit, miss, -1)',
                'F1: mode byte != 0 falls back to the local table (1 and 255)',
                'F1: name pointer forwarded verbatim - non-empty, empty, NULL',
                'F1: return value is the callee answer: slot 0 legal, -1 absent, '
                'INT_MIN untouched',
                'F1: host pointer NULL + self NULL still takes the host branch',
                'F2: id == -3 room chain - empty room, live head, destroyed, '
                'deactivated, both, all-dead, live head with a live next',
                'F2: id < 0 exits - -1, -10, INT_MIN, -4 (neighbour of -3)',
                'F2: 0..99999 pass-through incl. both boundaries 0 and 99999',
                'F2: id > 99999 hash - hit, neighbour bucket, chain end, '
                'walk-then-hit, NULL instance, destroyed, +0x69-only, INT_MAX',
                'F2: bucket mask honoured (mask 3 vs 7) and 8 B bucket stride',
                'F2: the failure byte 0x75505c is set on exactly one exit',
                'F2: varid is dead - three cases with the same id and different '
                'varids produce identical records',
                'second-run reproducibility of both arms'],
            'not_covered': [
                'Code_Variable_Find_Slot_From_Local_Name semantics (stubbed): '
                'the CHashMap hash/compare and its -1 miss',
                'Code_Variable_Find_Slot_From_Global_Name semantics (stubbed): '
                'the linear strcmp scan and "id = declaration order"',
                'Object_Name semantics (stubbed), including its own '
                '"<undefined>" fallback at 0x330ac8',
                'who writes 0x544be0 and 0x47f295 (no writer exists in .text)',
                'device behaviour'],
            'not_applicable': [
                'F1 has no "lazy slot creation" arm: it is a dispatcher over two '
                'name tables and never touches the object\'s slot table.  The '
                'table==0 -> InternalGetYYVar path lives in '
                'Variable_GetValue_Direct and is covered by c/variable_direct/.',
                'F2 does not consult g_ObjectHash at all; the only object-index '
                'consumer is Object_Name, which is stubbed.',
                'g_run_room == NULL is undefined on the original bytes '
                '(0x1f4018 ldr r3,[r3] then 0x1f401c ldr r3,[r3,#0x80] would '
                'fault), so it is not a case: room_mode 0 stages a live CRoom '
                'with a NULL instance chain instead.'],
        },
        'findings': [
            'F1 compares self against *one* global pointer and nothing else: no '
            'object field is read, so a pointer-equality test is the whole '
            'host test.  The fixture pins the degenerate case where the cell is '
            'NULL and self is NULL - it takes the host branch.',
            'F1 forwards the name pointer with 0xd21fc mov r0,r1 and never '
            'inspects the string; empty and NULL names reach the callee '
            'unchanged.  Whether that is a hit or a miss is not this body\'s '
            'answer.',
            'F2 never reads its second argument.  Three cases with id 100006 and '
            'varid 0 / 4242 / INT_MIN produce identical records.',
            'F2 sets 0x75505c on exactly one of its five failure exits '
            '(0x1f407c, id == -3 with no live instance).  The other four leave '
            'it untouched - verified by reading the byte after every call, not '
            'by reading the card.',
            'F2 is asymmetric on purpose: the id > 99999 hash path tests +0x68 '
            'only, so a deactivated instance (+0x69 != 0, +0x68 == 0) still '
            'yields its object name, while the room chain skips it.',
            'card/byte agreement: both cards were re-checked against llvm-objdump '
            'instruction by instruction; see card_deltas.'],
        'card_deltas': CARD_DELTAS,
        'card_note': CARD_NOTE,
        'instruction_census': census,
        'repeat': repeat,
        'cases': len(case_list),
        'cases_f1': len(f1_ok),
        'cases_f2': len(f2_ok),
        'rows': rows,
        'coverage': coverage,
        'covered_by': covered_by,
        'teeth': teeth,
        'status': status,
    }
    out = args.out or (RECEIPTS / ('var_names_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d (F1 %d, F2 %d) identical=%d binding=%s census=%d/%d'
          % (status, len(case_list), len(f1_ok), len(f2_ok),
             sum(1 for r in rows if r['equal']),
             'ok' if bind['ok'] else 'BAD',
             census['documented'], census['instructions']))
    print('  REPEAT second-run identical  original=%s rebuild=%s' % (
        'yes' if repeat['original_identical'] else 'NO',
        'yes' if repeat['rebuild_identical'] else 'NO'))
    for k, v in coverage.items():
        print('  COVER %-38s %s  %s' % (k, 'yes' if v else 'NO',
                                        (covered_by.get(k) or [''])[0][:52]))
    for t in teeth:
        print('  TEETH %-34s %s caught_by=%d mode=%s aborted=%d' % (
            t['mutant'], 'PASS' if t['passed'] else 'FAIL',
            len(t['caught_by']), t['mode'], len(t['aborted_cases'])))
    for m in mismatches[:8]:
        print('  DIFF case=%r' % (m['case']['label'],))
        print('    original', m['original'])
        print('    rebuild ', m['rebuild'])
    if not census['ok']:
        for part in ('Code_Variable_Find_Slot_From_Name', 'Variable_GetObjectName'):
            for w in census[part]['wrong'][:8]:
                print('  CENSUS %s %s objdump=%r source=%r'
                      % (part, w['addr'], w['objdump'], w['source']))
            for w in census[part]['pool_missing'][:8]:
                print('  CENSUS pool %s %s' % (part, w['addr']))
            for w in census[part]['duplicate_addresses'][:8]:
                print('  CENSUS dup %s %s' % (part, w['addr']))
            for w in census[part]['unknown_addresses'][:8]:
                print('  CENSUS extra %s %s' % (part, w['addr']))
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
