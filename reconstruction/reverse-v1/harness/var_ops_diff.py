#!/usr/bin/env python3
"""Variable-instruction side of libyoyo — original-binary differential (3 fns).

Functions under judgement, all from the pinned image
(3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):

  F1  _Z23Code_Variable_Find_NamePKcii              @0x000d25fc
      7 instructions, 28 B, no literal pool, no frame; both exits are `b`
      tail jumps, so its return value is its callee's.
  F2  _Z19DoConvIntToVariablejPhPKhP6VMExec          @0x000d773c
      9 instructions, 36 B, no literal pool, no frame, no call: a leaf that
      rewrites the value-stack top into a 16-byte RValue at top-12.
  F3  _Z18DoPopLocalVariablejPhPKhP6VMExec           @0x000e1f5c
      46 instructions, 184 B, no literal pool, one six-register frame, five
      callees, two ways into the shared epilogue.

Two arms, same inputs, same staged memory:
  arm A (judge)  the original bytes, executed in Unicorn over one staged arena
  arm B (claim)  reconstruction/reverse-v1/c/variable_ops/, cross-compiled for
                 armv7a-none-eabi (freestanding) and run under qemu-arm

Why arm B must not be host-compiled: F3's `lsl #4` has to mean 16 bytes, the
tag has to land at +0xc of a 16-byte slot, and F2 has to write 12 bytes below a
4-byte stack word.  A 64-bit host build moves all of those and the records would
stop describing the original.

Scope, stated up front — no callee of these three bodies was recovered when this
arm was written, and this arm links no callee at all: both arms run IDENTICAL
stubs for every one of them, so the comparison is always like-for-like:
  0x001f3b38  Variable_BuiltIn_Find_Name(int)
  0x000d2228  Variable_GetName_Scope(char const*, int, int)
  0x000d3968  PushContextStack(YYObjectBase*)
  0x000d3a34  PopContextStack()
  0x000c0a7c  FREE_RValue__Pre(RValue*)
  0x000d0b24  SET_RValue(RValue*, RValue*, int)
  0x00196a70  YYObjectBase::InternalGetYYVar(int)
A green run therefore proves these three bodies' dispatch, field offsets, slot
arithmetic, tag/constant words, stack effect and return plumbing — not those
callees, and not device equivalence.  (A parallel workstream has since added
c/variable_misc/, which holds a translation of Variable_GetName_Scope @0xd2228,
one of F1's two callees.  It is deliberately not linked here: see
scope.not_covered.)  SET_RValue is the one that performs the
actual store, so what F3's arm proves is the destination address, the source
slot and the instance id it is handed.

Gates:
  * binding    image sha256; each body's byte range, instruction count and
               pool-freedom (no pc-relative load); the exact set of callee
               addresses AND symbol names its branches name; the arena layout
               used by both arms, parsed out of the translation's header
  * census     every instruction of the original appears in the translation as
               an `@0xADDR <verbatim llvm-objdump text>` comment, each address
               exactly once, text equal after whitespace collapse
  * census-self  the census is re-run on deliberately corrupted copies of the
               translation (one operand, one deleted annotation, one constant
               word) and must go red on the mutated address — a gate that
               cannot fail is not a gate
  * identity   every case identical on both arms (return value, ordered call
               log, the three memory windows, the stack delta)
  * coverage   every decision of the ORIGINAL body is taken, proven by its own
               instruction trace (COVER)
  * repeat     both arms rerun in a second process reproduce their records
  * teeth      every source-level mutant of the translations is caught by at
               least one named case; a green mutant means the case set does not
               exercise that decision

Usage:
  python3 var_ops_diff.py            # build, run both arms, write receipt
  python3 var_ops_diff.py --no-run   # replay the gates on the last receipt
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
MOD = RV1 / 'c' / 'variable_ops'
BUILD = HERE / 'build' / 'var_ops'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
import handler_oracle  # noqa: E402
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_PC, UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

# ── F1 Code_Variable_Find_Name ──────────────────────────────────────────────
F1 = 0xd25fc
F1_END = 0xd2618
BUILTIN = 0x1f3b38
SCOPE = 0xd2228

# ── F2 DoConvIntToVariable ──────────────────────────────────────────────────
F2 = 0xd773c
F2_END = 0xd7760

# ── F3 DoPopLocalVariable ───────────────────────────────────────────────────
F3 = 0xe1f5c
F3_END = 0xe2014
PUSH_CTX = 0xd3968
POP_CTX = 0xd3a34
FREE_RV = 0xc0a7c
SET_RV = 0xd0b24
IGV = 0x196a70

# name each branch target must be labelled with, in the pinned image
CALLEE_NAMES = {
    BUILTIN: '_Z26Variable_BuiltIn_Find_Namei',
    SCOPE: '_Z22Variable_GetName_ScopePKcii',
    PUSH_CTX: '_Z16PushContextStackP12YYObjectBase',
    POP_CTX: '_Z15PopContextStackv',
    FREE_RV: '_Z16FREE_RValue__PreP6RValue',
    SET_RV: '_Z10SET_RValueP6RValueS0_i',
    IGV: '_ZN12YYObjectBase16InternalGetYYVarEi',
}

# ── the arena: mirrored from c/variable_ops/src/variable_ops.h, and checked ──
AO_NAME = 0x000
AO_RETSTR = 0x040
AO_VSTACK = 0x080
AO_SP = 0x0a0
AO_CODE = 0x0c0
AO_EXEC = 0x100
AO_SELF = 0x140
AO_TABLE = 0x180
AO_DYN = 0x200
ARENA_SIZE = 0x280
AO_W1, AO_W1LEN = 0x090, 0x030
AO_W2, AO_W2LEN = 0x180, 0x020
AO_W3, AO_W3LEN = 0x200, 0x010

EXEC_SELF = 0x010
YYB_VAR_TABLE = 0x004
YYB_CTX_GATE = 0x024
CODE_ONE_WORD = 0x20000000
INSTANCE_SELF = 0x80000000

MARK = 0xcc
TAGM = 0xa5
NAME_MAX = 32
RET_A = b'builtin-answer'
RET_B = b'scope-answer'

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
    label: str

    def args(self):
        return (self.fn, self.p0, self.p1, self.p2, self.p3, self.p4, self.p5,
                self.p6)

    def as_dict(self):
        return {k: getattr(self, k) for k in
                ('fn', 'p0', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'label')}


NAMES = {0: b'alpha', 1: b'', 2: None, 3: b'beta'}


def cases():
    """Deterministic; the same list, in the same order, on every rerun.

    F1 fields: id type name_tag ret_mode _ _ _
    F2 fields: value arg _ _ _ _ _
    F3 fields: raw self_mode tag instance_id arg _ _
    """
    return [
        # ── F1: the two tail jumps and the boundary ─────────────────────────
        Case(1, 100000, -7, 0, 0, 0, 0, 0,
             'F1 id 100000 (one past 99999) -> scope, name+type+id live'),
        Case(1, 99999, -7, 0, 0, 0, 0, 0,
             'F1 id 99999 (boundary, bgt not taken) -> built-in'),
        Case(1, 99999, -7, 3, 0, 0, 0, 0,
             'F1 id 99999, name "beta" -> built-in, same record as "alpha"'),
        Case(1, 99999, -7, 2, 0, 0, 0, 0,
             'F1 id 99999, name NULL -> built-in, same record again'),
        Case(1, 100001, -5, 0, 0, 0, 0, 0,
             'F1 id 100001 -> scope'),
        Case(1, 0, 1, 0, 0, 0, 0, 0,
             'F1 id 0 -> built-in, type 1 dropped'),
        Case(1, -1, -12, 0, 0, 0, 0, 0,
             'F1 id -1 (signed bgt) -> built-in, not scope'),
        Case(1, -100000, -12, 0, 0, 0, 0, 0,
             'F1 id -100000 -> built-in'),
        Case(1, INT_MIN, 1, 0, 0, 0, 0, 0,
             'F1 id INT_MIN -> built-in (an unsigned test would say scope)'),
        Case(1, INT_MAX, 1, 0, 0, 0, 0, 0,
             'F1 id INT_MAX -> scope'),

        # ── F1: what the scope branch forwards ─────────────────────────────
        Case(1, 100000, -7, 1, 1, 0, 0, 0,
             'F1 scope forwards an EMPTY name'),
        Case(1, 100000, -7, 2, 1, 0, 0, 0,
             'F1 scope forwards a NULL name'),
        Case(1, 100000, INT_MIN, 3, 0, 0, 0, 0,
             'F1 scope forwards type INT_MIN and name "beta"'),

        # ── F1: the return value is the callee's, verbatim ─────────────────
        Case(1, 100000, -7, 0, 2, 0, 0, 0,
             'F1 scope answers NULL -> NULL is returned verbatim'),
        Case(1, 99999, -7, 0, 2, 0, 0, 0,
             'F1 built-in answers NULL -> NULL is returned verbatim'),
        Case(1, 100000, -7, 0, 3, 0, 0, 0,
             'F1 scope answers with the NAME pointer itself (offset 0)'),
        Case(1, 99999, 1, 2, 3, 0, 0, 0,
             'F1 built-in answers with the NAME pointer, NULL name this time'),
        Case(1, 100000, 1, 0, 0, 0, 0, 0,
             'F1 same id as the built-in cases, different name: scope again'),

        # ── F2: int32 -> double -> 12 bytes below the stack top ────────────
        Case(2, 42, 0, 0, 0, 0, 0, 0, 'F2 value 42'),
        Case(2, 0, 0, 0, 0, 0, 0, 0, 'F2 value 0'),
        Case(2, -1, 0, 0, 0, 0, 0, 0, 'F2 value -1 (sign extension of s32)'),
        Case(2, 1, 0, 0, 0, 0, 0, 0, 'F2 value 1'),
        Case(2, INT_MAX, 0, 0, 0, 0, 0, 0, 'F2 value INT_MAX'),
        Case(2, INT_MIN, 0, 0, 0, 0, 0, 0, 'F2 value INT_MIN'),
        Case(2, 65537, 0, 0, 0, 0, 0, 0, 'F2 value 65537'),
        Case(2, -16777216, 0, 0, 0, 0, 0, 0, 'F2 value 0xFF000000 as signed'),
        Case(2, 16777217, 0, 0, 0, 0, 0, 0,
             'F2 value 2^24+1: exact as a double, rounded as a float'),
        Case(2, 1234567890, 0, 0, 0, 0, 0, 0,
             'F2 value 1234567890: float rounding would show'),
        Case(2, -2147483647, 0, 0, 0, 0, 0, 0, 'F2 value -INT_MAX'),
        Case(2, 42, 12345, 0, 0, 0, 0, 0,
             'F2 dead first argument 12345: same record as value 42'),
        Case(2, 100000, INT_MIN, 0, 0, 0, 0, 0,
             'F2 dead first argument INT_MIN'),

        # ── F3: the full path (self, table, store) ─────────────────────────
        Case(3, 0x000186a0, 2, 1, 77, 3, 0, 0,
             'F3 varid 0, live instance id 77, tag 1 -> FREE + SET + tag5'),
        Case(3, 0x000186a0, 2, 0, 77, 3, 0, 0,
             'F3 tag 0 -> NO FREE, still SET + tag5'),
        Case(3, 0x000186a0, 2, 4, 77, 3, 0, 0,
             'F3 tag 4 (upper end of 1..4) -> FREE'),
        Case(3, 0x000186a0, 2, 5, 77, 3, 0, 0,
             'F3 tag 5 -> NO FREE (one past the gate)'),
        Case(3, 0x000186a0, 2, 0x105, 77, 3, 0, 0,
             'F3 tag 0x105 (bit 2 set) -> NO FREE'),
        Case(3, 0x000186a0, 2, 0x40000001, 77, 3, 0, 0,
             'F3 tag 0x40000001: bits 24..31 are masked off -> FREE'),
        Case(3, 0x000186a0, 2, INT_MIN + 1, 77, 3, 0, 0,
             'F3 tag 0x80000001 -> FREE (bit 31 masked off too)'),
        Case(3, 0x000186a0, 2, -1, 77, 3, 0, 0,
             'F3 tag 0xFFFFFFFF -> NO FREE (low bits survive the mask)'),

        # ── F3: the two operand flags ──────────────────────────────────────
        Case(3, 0x200186a0, 2, 1, 77, 3, 0, 0,
             'F3 bit29 set: one word only, sp delta 20'),
        Case(3, 0x800186a0, 2, 1, 77, 3, 0, 0,
             'F3 bit31 set: instance id = INT_MIN sentinel, sp delta 20'),
        Case(3, 0xa00186a0, 2, 1, 77, 3, 0, 0,
             'F3 bit31+bit29: nothing popped, sp delta 16'),
        Case(3, 0, 2, 1, 5, 3, 0, 0,
             'F3 raw 0: id word read (0 >= 0), variable id -100000'),

        # ── F3: self == 0, the gate, and the two destinations ──────────────
        Case(3, 0x000186a0, 0, 1, 77, 3, 0, 0,
             'F3 self NULL: no Push/Pop, no store, epilogue still runs'),
        Case(3, 0x000186a0, 1, 1, 77, 3, 0, 0,
             'F3 self->[0x24] == 0: Push + Pop, no store'),
        Case(3, 0x000186a0, 3, 1, 77, 3, 0, 0,
             'F3 self->[4] == 0: InternalGetYYVar supplies the destination'),
        Case(3, 0x800186a5, 3, 5, 77, 3, 0, 0,
             'F3 dynamic destination, variable id 5, sentinel instance, no FREE'),

        # ── F3: the slot arithmetic ────────────────────────────────────────
        Case(3, 0x000186a5, 2, 1, 77, 3, 0, 0,
             'F3 variable id 5 -> table slot 5'),
        Case(3, 0x000186b0, 2, 1, 77, 3, 0, 0,
             'F3 variable id 16 -> past the 8 staged slots, still arithmetic'),
        Case(3, 0x0fffffff, 2, 1, 77, 3, 0, 0,
             'F3 operand 0x0fffffff: mask then subtract, destination far out'),
        Case(3, 0x000186a0, 2, 1, 0, 3, 0, 0,
             'F3 instance id 0 is a legal id, not "absent"'),
        Case(3, 0x000186a0, 2, 1, -1, 3, 0, 0,
             'F3 instance id -1 passes through untouched'),
        Case(3, 0x000186a0, 2, 1, 77, INT_MIN, 0, 0,
             'F3 dead first argument INT_MIN: same record as arg 3'),
    ]


# ── record helpers ──────────────────────────────────────────────────────────
def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


def _tk(tr, a, b):
    for i in range(len(tr) - 1):
        if tr[i] == a and tr[i + 1] == b:
            return True
    return False


def _ex(tr, a):
    return a in tr


def _calls(rec, k):
    return [c for c in rec['calls'] if c[0] == k]


# The MEM blob is the three evidence windows concatenated, not the whole arena,
# so an absolute arena offset has to be mapped into it.
WINDOWS = ((AO_W1, AO_W1LEN, 0),
           (AO_W2, AO_W2LEN, AO_W1LEN),
           (AO_W3, AO_W3LEN, AO_W1LEN + AO_W2LEN))


def _mem_at(rec, off, n=4):
    """The n bytes at an arena offset, out of the MEM blob (-1 if outside)."""
    mem = rec['mem']
    if not mem or off < 0:
        return -1
    for start, ln, idx in WINDOWS:
        if start <= off and off + n <= start + ln:
            s = 2 * (idx + off - start)
            w = mem[s:s + 2 * n]
            if len(w) != 2 * n:
                return -1
            # MEM prints bytes in memory order; a word here is little-endian,
            # the way the original reads it with ldr.
            return int.from_bytes(bytes.fromhex(w), 'little')
    return -1


def _memword(rec, off, n=4):
    return _mem_at(rec, off, n)


def _membyte(rec, off):
    if not rec['mem']:
        return -1
    b = rec['mem'][2 * off:2 * off + 2]
    return int(b, 16) if len(b) == 2 else -1


def _slot_off(c):
    """The value slot the body will consume, from the case's operand word.

    The fixture uses this to stage the source RValue; a translation that pops
    one word too many or too few then reads a different slot, which is exactly
    what the FREE decision and the SET_RValue source expose.
    """
    raw = c.p0 & 0xffffffff
    return AO_SP + (4 if to_i32(raw) >= 0 else 0) + (0 if raw & CODE_ONE_WORD else 4)


def _f1_scope_forwarded(tr, r, c):
    if c.fn != 1 or not _calls(r, 'S'):
        return False
    s = _calls(r, 'S')[0]
    want = NAMES[c.p2]
    got = -1 if want is None else len(want)
    return s[1] == got and s[2] == ('-' if not want else want.hex())


def _f2_double_ok(tr, r, c):
    """The two words at sp-12 must be the IEEE-754 double of the int32."""
    want = struct.pack('<d', float(to_i32(c.p0 & 0xffffffff)))
    lo = int.from_bytes(want[0:4], 'little')
    hi = int.from_bytes(want[4:8], 'little')
    return (_memword(r, AO_SP - 12) == lo and _memword(r, AO_SP - 8) == hi
            and _memword(r, AO_SP) == 0)


def _f1_builtin_ignores_name(rows):
    """Same id, different name tags, built-in branch: identical records."""
    by = {}
    for c, a in rows:
        if c.fn != 1 or c.p0 > 99999:
            continue
        key = (c.p0, c.p1, c.p3)
        by.setdefault(key, []).append((json.dumps(a['ret']),
                                       json.dumps(a['calls'])))
    return any(len(set(v)) == 1 and len(v) > 1 for v in by.values())


def _f2_dead_arg(rows):
    """Pairs that differ only in the dead first argument."""
    by = {}
    for c, a in rows:
        if c.fn != 2:
            continue
        by.setdefault(c.p0, []).append((json.dumps(a['ret']),
                                        json.dumps(a['calls']), a['mem']))
    return any(len(set(v)) == 1 and len(v) > 1 for v in by.values())


def _f3_dead_arg(rows):
    by = {}
    for c, a in rows:
        if c.fn != 3:
            continue
        key = (c.p0, c.p1, c.p2, c.p3)
        by.setdefault(key, []).append((json.dumps(a['ret']),
                                       json.dumps(a['calls']), a['mem'],
                                       a['spdlt']))
    return any(len(set(v)) == 1 and len(v) > 1 for v in by.values())


COVER = [
    # ── F1 ──────────────────────────────────────────────────────────────────
    ('f1_scope_branch', lambda tr, r, c: _tk(tr, F1 + 0x0c, F1 + 0x18)),
    ('f1_builtin_branch', lambda tr, r, c: _tk(tr, F1 + 0x0c, F1 + 0x10)),
    ('f1_boundary_99999', lambda tr, r, c: c.fn == 1 and c.p0 == 99999
     and _tk(tr, F1 + 0x0c, F1 + 0x10)),
    ('f1_boundary_100000', lambda tr, r, c: c.fn == 1 and c.p0 == 100000
     and _tk(tr, F1 + 0x0c, F1 + 0x18)),
    ('f1_negative_id', lambda tr, r, c: c.fn == 1 and c.p0 < 0
     and _tk(tr, F1 + 0x0c, F1 + 0x10)),
    ('f1_scope_name_forwarded', _f1_scope_forwarded),
    ('f1_scope_empty_name', lambda tr, r, c: c.fn == 1 and c.p2 == 1
     and _calls(r, 'S') and _calls(r, 'S')[0][1] == 0),
    ('f1_scope_null_name', lambda tr, r, c: c.fn == 1 and c.p2 == 2
     and _calls(r, 'S') and _calls(r, 'S')[0][1] == -1),
    ('f1_scope_type_forwarded', lambda tr, r, c: c.fn == 1 and c.p0 == 100000
     and _calls(r, 'S') and _calls(r, 'S')[0][3] == c.p1),
    ('f1_builtin_id_is_r2', lambda tr, r, c: c.fn == 1 and c.p0 <= 99999
     and _calls(r, 'B') and _calls(r, 'B')[0][1] == c.p0),
    ('f1_ret_is_callee_answer', lambda tr, r, c: c.fn == 1 and c.p3 in (0, 1)
     and r['ret'][0] == str(AO_RETSTR + 16 * c.p3)),
    ('f1_ret_null_passthrough', lambda tr, r, c: c.fn == 1 and c.p3 == 2
     and r['ret'][0] == 'NULL'),
    ('f1_ret_name_pointer', lambda tr, r, c: c.fn == 1 and c.p3 == 3
     and r['ret'][0] == str(AO_NAME)),

    # ── F2 ──────────────────────────────────────────────────────────────────
    ('f2_all_nine_instructions', lambda tr, r, c: c.fn == 2
     and sum(1 for a in range(F2, F2_END, 4) if a in tr) == 9),
    ('f2_double_exact', _f2_double_ok),
    ('f2_tag_word_zero', lambda tr, r, c: c.fn == 2 and _memword(r, AO_SP) == 0),
    ('f2_hole_at_plus8_untouched', lambda tr, r, c: c.fn == 2
     and _memword(r, AO_SP - 4) == 0xcccccccc),
    ('f2_above_top_untouched', lambda tr, r, c: c.fn == 2
     and _memword(r, AO_SP + 4) == 0xcccccccc),
    ('f2_ret_is_sp_minus_12', lambda tr, r, c: c.fn == 2
     and r['ret'][0] == str(AO_SP - 12)),
    ('f2_negative_value', lambda tr, r, c: c.fn == 2 and c.p0 < 0
     and _f2_double_ok(tr, r, c)),

    # ── F3 ──────────────────────────────────────────────────────────────────
    ('f3_self_null_skips_context', lambda tr, r, c: _tk(tr, F3 + 0x28, F3 + 0x44)),
    ('f3_gate_zero_no_store', lambda tr, r, c: _tk(tr, F3 + 0x3c, F3 + 0x40)),
    ('f3_writeback_branch', lambda tr, r, c: _tk(tr, F3 + 0x3c, F3 + 0x80)),
    ('f3_table_destination', lambda tr, r, c: _tk(tr, F3 + 0x94, F3 + 0x98)),
    ('f3_dynamic_destination', lambda tr, r, c: _tk(tr, F3 + 0x94, F3 + 0xac)),
    ('f3_free_taken', lambda tr, r, c: _tk(tr, F3 + 0x58, F3 + 0x5c)),
    ('f3_free_skipped', lambda tr, r, c: _tk(tr, F3 + 0x58, F3 + 0x64)),
    # 0xe1f70 ldrge and 0xe1f74 movlt are CONDITIONAL single instructions: a code
    # hook fires on both whatever the flags say, so their trace cannot tell the
    # two apart.  The decision is read off the record instead - the stack delta
    # says whether the id word was popped, and SET_RValue's instance argument
    # says which id reached the store.
    ('f3_instance_id_popped', lambda tr, r, c: c.fn == 3
     and (c.p0 & 0x80000000) == 0 and r['spdlt'] in (20, 24)),
    ('f3_instance_sentinel', lambda tr, r, c: c.fn == 3
     and (c.p0 & 0x80000000) != 0
     and any(x[0] == 'R' and x[3] == INT_MIN for x in r['calls'])),
    ('f3_branch_back_to_pop', lambda tr, r, c: _tk(tr, F3 + 0xa8, F3 + 0x40)),
    ('f3_spdlt_24', lambda tr, r, c: r['spdlt'] == 24),
    ('f3_spdlt_20', lambda tr, r, c: r['spdlt'] == 20),
    ('f3_spdlt_16', lambda tr, r, c: r['spdlt'] == 16),
    ('f3_tag5_write', lambda tr, r, c: c.fn == 3
     and _memword(r, _slot_off(c) + 12) == 5),
    ('f3_plus4_untouched', lambda tr, r, c: c.fn == 3
     and _memword(r, _slot_off(c) + 4) == 0x33333333),
    ('f3_ret_is_slot_plus_16', lambda tr, r, c: c.fn == 3
     and r['ret'][0] == str(_slot_off(c) + 16)),
    ('f3_push_pop_paired', lambda tr, r, c: c.fn == 3 and c.p1 != 0
     and bool(_calls(r, 'P')) and bool(_calls(r, 'Q'))),
    ('f3_dynamic_idx_forwarded', lambda tr, r, c: c.fn == 3
     and _calls(r, 'G') and _calls(r, 'G')[0][2]
     == to_i32(((c.p0 & 0x0fffffff) - 100000) & 0xffffffff)),
]


# ── original arm ─────────────────────────────────────────────────────────────
class Stage:
    """One staged arena, hooks installed exactly once.

    Per case only the arena is rewritten and the logs cleared: adding hooks per
    case would leave the previous case's hooks live on the same Unicorn
    instance.
    """

    def __init__(self, o):
        self.o = o
        self.arena = o.alloc(ARENA_SIZE)
        self.log = []
        self.tr = []
        self.traces = {}
        for addr, fn in ((BUILTIN, self.h_builtin), (SCOPE, self.h_scope),
                         (PUSH_CTX, self.h_push), (POP_CTX, self.h_pop),
                         (FREE_RV, self.h_free), (SET_RV, self.h_set),
                         (IGV, self.h_igv)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        for entry, end in ((F1, F1_END), (F2, F2_END), (F3, F3_END)):
            o.uc.hook_add(UC_HOOK_CODE, self.h_trace, begin=entry, end=end - 4)

    # -- plumbing -----------------------------------------------------------
    def h_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def _w(self, off, w):
        """Write a word at an ARENA OFFSET (never an absolute address: the two
        arms live at different bases and every staged byte is addressed the way
        the fixture addresses it)."""
        self.o.write(self.arena + off, struct.pack('<I', w & 0xffffffff))

    def _r(self, off):
        return struct.unpack('<I', bytes(self.o.read(self.arena + off, 4)))[0]

    def _fill(self, off, n, b):
        self.o.write(self.arena + off, bytes([b]) * n)

    def off(self, p):
        if p == 0:
            return 'NULL'
        d = (p - self.arena) & 0xffffffff
        return str(d) if d < ARENA_SIZE else '-1'

    def _cstr(self, addr, cap=NAME_MAX):
        if addr == 0:
            return -1, '-'
        out = bytearray()
        for i in range(cap):
            try:
                b = self.o.read(addr + i, 1)[0]
            except Exception:
                break
            if b == 0:
                break
            out.append(b)
        return len(out), (out.hex() if out else '-')

    def answer(self, mode):
        if mode == 0:
            return self.arena + AO_RETSTR
        if mode == 1:
            return self.arena + AO_RETSTR + 16
        if mode == 2:
            return 0
        return self.arena + AO_NAME

    # -- callee hooks -------------------------------------------------------
    def h_builtin(self, uc_, _a, _s, _d):
        self.log.append(['B', to_i32(uc_.reg_read(UC_ARM_REG_R0))])
        uc_.reg_write(UC_ARM_REG_R0, self.answer(self.ret_mode))
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def h_scope(self, uc_, _a, _s, _d):
        n, hx = self._cstr(uc_.reg_read(UC_ARM_REG_R0))
        self.log.append(['S', n, hx, to_i32(uc_.reg_read(UC_ARM_REG_R1)),
                         to_i32(uc_.reg_read(UC_ARM_REG_R2))])
        uc_.reg_write(UC_ARM_REG_R0, self.answer(self.ret_mode))
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def h_push(self, uc_, _a, _s, _d):
        self.log.append(['P', self.off(uc_.reg_read(UC_ARM_REG_R0))])
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def h_pop(self, uc_, _a, _s, _d):
        self.log.append(['Q'])
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def h_free(self, uc_, _a, _s, _d):
        self.log.append(['F', self.off(uc_.reg_read(UC_ARM_REG_R0))])
        uc_.reg_write(UC_ARM_REG_R0, 0)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def h_set(self, uc_, _a, _s, _d):
        self.log.append(['R', self.off(uc_.reg_read(UC_ARM_REG_R0)),
                         self.off(uc_.reg_read(UC_ARM_REG_R1)),
                         to_i32(uc_.reg_read(UC_ARM_REG_R2))])
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def h_igv(self, uc_, _a, _s, _d):
        self.log.append(['G', self.off(self.arena + AO_DYN),
                         to_i32(uc_.reg_read(UC_ARM_REG_R1))])
        uc_.reg_write(UC_ARM_REG_R0, self.arena + AO_DYN)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    # -- staging ------------------------------------------------------------
    def _stage_retstrings(self):
        self._fill(AO_RETSTR, 64, 0)
        self.o.write(self.arena + AO_RETSTR, RET_A + b'\0')
        self.o.write(self.arena + AO_RETSTR + 16, RET_B + b'\0')

    def dump_mem(self):
        blob = (bytes(self.o.read(self.arena + AO_W1, AO_W1LEN))
                + bytes(self.o.read(self.arena + AO_W2, AO_W2LEN))
                + bytes(self.o.read(self.arena + AO_W3, AO_W3LEN)))
        return blob.hex()

    def _record(self, ret, spdlt=None, mem=True, text=True):
        n, hx = self._cstr(ret)
        if not text:
            hx = '-'                      # fn 2/3: the offset is the record
        return {'ret': [self.off(ret), hx], 'calls': list(self.log),
                'mem': self.dump_mem() if mem else '', 'spdlt': spdlt}

    def run(self, case):
        _, p0, p1, p2, p3, p4, _p5, _p6 = case.args()
        self.o.write(self.arena, bytes([MARK]) * ARENA_SIZE)
        self.log.clear()
        self.tr.clear()
        if case.fn == 1:
            self._stage_retstrings()
            self._fill(AO_NAME, 48, 0)
            name = NAMES.get(p2)
            if name:
                self.o.write(self.arena + AO_NAME, name + b'\0')
            self.ret_mode = p3
            sel = 0 if name is None else self.arena + AO_NAME
            ret = self.o.call(F1, r0=sel, r1=p1 & 0xffffffff,
                              r2=p0 & 0xffffffff)
            rec = self._record(ret, mem=False)
        elif case.fn == 2:
            self._w(AO_SP, p0)
            ret = self.o.call(F2, r0=p1 & 0xffffffff, r1=self.arena + AO_SP,
                              r2=self.arena + AO_CODE,
                              r3=self.arena + AO_EXEC)
            rec = self._record(ret, text=False)
        else:
            raw = p0 & 0xffffffff
            slot = _slot_off(case)
            self._fill(AO_VSTACK, 0x40, TAGM)
            self._w(AO_VSTACK, 0)
            self._w(AO_SP, p3)
            self._w(slot, 0x11111111)
            self._w(slot + 4, 0x33333333)
            self._w(slot + 8, 0x22222222)
            self._w(slot + 12, p2)
            self._fill(AO_TABLE, 0x80, MARK)
            self._fill(AO_DYN, 0x30, TAGM)
            self._w(AO_CODE, raw)
            self._fill(AO_SELF, 0x40, 0)
            if p1 != 0:
                if p1 >= 2:
                    self._w(AO_SELF + YYB_CTX_GATE, 1)
                    if p1 == 2:
                        self._w(AO_SELF + YYB_VAR_TABLE, self.arena + AO_TABLE)
                self._w(AO_EXEC + EXEC_SELF, self.arena + AO_SELF)
            else:
                self._w(AO_EXEC + EXEC_SELF, 0)
            ret = self.o.call(F3, r0=p4 & 0xffffffff, r1=self.arena + AO_SP,
                              r2=self.arena + AO_CODE,
                              r3=self.arena + AO_EXEC)
            rec = self._record(ret, spdlt=to_i32((ret - (self.arena + AO_SP))),
                               text=False)
        self.traces.setdefault(case.fn, []).append(list(self.tr))
        self.trace = list(self.tr)
        return rec


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

SRCS = ['find_name.c', 'conv_int.c', 'pop_local.c']


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
        tag = parts[0]
        if tag == 'CASE':
            cur = {'ret': ['', ''], 'calls': [], 'mem': '', 'spdlt': None}
            recs.append(cur)
        elif cur is None:
            raise RuntimeError('record line before CASE: %r' % line[:80])
        elif tag == 'RET':
            cur['ret'] = [parts[1], parts[2]]
        elif tag == 'CALLS':
            cur['ncalls'] = int(parts[1])
        elif tag == 'MEM':
            cur['mem'] = parts[1]
        elif tag == 'SPDLT':
            cur['spdlt'] = int(parts[1])
        elif tag == 'B':
            cur['calls'].append(['B', int(parts[1])])
        elif tag == 'S':
            cur['calls'].append(['S', int(parts[1]), parts[2],
                                 int(parts[3]), int(parts[4])])
        elif tag == 'P':
            cur['calls'].append(['P', parts[1]])
        elif tag == 'Q':
            cur['calls'].append(['Q'])
        elif tag == 'F':
            cur['calls'].append(['F', parts[1]])
        elif tag == 'R':
            cur['calls'].append(['R', parts[1], parts[2], int(parts[3])])
        elif tag == 'G':
            cur['calls'].append(['G', parts[1], int(parts[2])])
    if len(recs) != len(case_list):
        raise RuntimeError('driver returned %d records for %d cases'
                           % (len(recs), len(case_list)))
    for r in recs:
        if 'ncalls' in r and r['ncalls'] != len(r['calls']):
            raise RuntimeError('CALLS %d but %d call records'
                               % (r['ncalls'], len(r['calls'])))
    return recs


def same(a, b):
    """The only equality this file accepts: return value, the ordered call log,
    the three memory windows and the stack delta.  'Not comparable' is never a
    pass."""
    return (a['ret'] == b['ret'] and a['calls'] == b['calls']
            and a['mem'] == b['mem'] and a['spdlt'] == b['spdlt'])


def _digest(recs):
    return hashlib.sha256(json.dumps(
        [{'ret': r['ret'], 'calls': r['calls'], 'mem': r['mem'],
          'spdlt': r['spdlt']} for r in recs], sort_keys=True).encode()
    ).hexdigest()


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    # ── F1: the dispatch, the boundary, the signedness, the forwarding ─────
    {'name': 'f1_dispatch_flipped', 'file': 'find_name.c',
     'edits': [('if (id > VARID_BUILTIN_MAX)', 'if (id < VARID_BUILTIN_MAX)')]},
    {'name': 'f1_boundary_constant', 'file': 'find_name.c',
     'edits': [('if (id > VARID_BUILTIN_MAX)',
                'if (id > VARID_BUILTIN_MAX + 1)')]},
    {'name': 'f1_dispatch_unsigned', 'file': 'find_name.c',
     'edits': [('if (id > VARID_BUILTIN_MAX)',
                'if ((uint32_t)id > (uint32_t)VARID_BUILTIN_MAX)')]},
    {'name': 'f1_builtin_gets_type', 'file': 'find_name.c',
     'edits': [('return Variable_BuiltIn_Find_Name(id);',
                'return Variable_BuiltIn_Find_Name(type);')]},
    {'name': 'f1_scope_name_shifted', 'file': 'find_name.c',
     'edits': [('return Variable_GetName_Scope(name, type, id);',
                'return Variable_GetName_Scope(name ? name + 1 : name, type, id);')]},
    {'name': 'f1_scope_type_zeroed', 'file': 'find_name.c',
     'edits': [('return Variable_GetName_Scope(name, type, id);',
                'return Variable_GetName_Scope(name, 0, id);')]},
    {'name': 'f1_scope_return_normalised', 'file': 'find_name.c',
     'edits': [('return Variable_GetName_Scope(name, type, id);',
                '{ Variable_GetName_Scope(name, type, id); return (const char *)0; }')]},

    # ── F2: the double, its two words, the hole, the tag, the return ───────
    {'name': 'f2_words_swapped', 'file': 'conv_int.c',
     'edits': [('wr32(sp - 12, bits.w[0]);', 'wr32(sp - 12, bits.w[1]);')]},
    {'name': 'f2_high_word_offset', 'file': 'conv_int.c',
     'edits': [('wr32(sp - 8, bits.w[1]);', 'wr32(sp - 4, bits.w[1]);')]},
    {'name': 'f2_return_unshifted', 'file': 'conv_int.c',
     'edits': [('return p - 12;', 'return p;')]},
    {'name': 'f2_tag_nonzero', 'file': 'conv_int.c',
     'edits': [('wr32(p, zero);', 'wr32(p, zero + 1u);')]},
    {'name': 'f2_float_instead_of_double', 'file': 'conv_int.c',
     'edits': [('bits.d = (double)v;', 'bits.d = (double)(float)v;')]},
    {'name': 'f2_low_word_dropped', 'file': 'conv_int.c',
     'edits': [('wr32(sp - 12, bits.w[0]);', '(void)0;')]},
    {'name': 'f2_unsigned_widening', 'file': 'conv_int.c',
     'edits': [('bits.d = (double)v;', 'bits.d = (double)(uint32_t)v;')]},

    # ── F3: flags, gate, slot arithmetic, tag gate, stack effect ───────────
    {'name': 'f3_bit29_inverted', 'file': 'pop_local.c',
     'edits': [('if ((r6 & CODE_ONE_WORD) == 0)', 'if ((r6 & CODE_ONE_WORD) != 0)')]},
    {'name': 'f3_sign_test_strict', 'file': 'pop_local.c',
     'edits': [('if ((int32_t)r6 >= 0) {', 'if ((int32_t)r6 > 0) {')]},
    {'name': 'f3_gate_offset', 'file': 'pop_local.c',
     'edits': [('self + YYB_CTX_GATE', 'self + YYB_CTX_GATE + 4')]},
    {'name': 'f3_slot_base', 'file': 'pop_local.c',
     'edits': [('r6 -= 672;', 'r6 -= 668;')]},
    {'name': 'f3_slot_stride', 'file': 'pop_local.c',
     'edits': [('dst = tbl + (r6 << 4);', 'dst = tbl + (r6 << 2);')]},
    {'name': 'f3_tag_mask_high_bits', 'file': 'pop_local.c',
     'edits': [('tag &= 0x00ffffffu;', 'tag &= 0xffffffffu;')]},
    {'name': 'f3_tag_mask_low_bits', 'file': 'pop_local.c',
     'edits': [('tag &= ~3u;', 'tag &= ~7u;')]},
    {'name': 'f3_free_dropped', 'file': 'pop_local.c',
     'edits': [('FREE_RValue__Pre(r4);', '(void)r4;')]},
    {'name': 'f3_tag5_becomes_zero', 'file': 'pop_local.c',
     'edits': [('wr32(r4 + 12, 5);', 'wr32(r4 + 12, 0);')]},
    {'name': 'f3_plus4_clobbered', 'file': 'pop_local.c',
     'edits': [('wr32(r4 + 8, 0);', 'wr32(r4 + 4, 0);')]},
    {'name': 'f3_return_step', 'file': 'pop_local.c',
     'edits': [('return r4 + 16;', 'return r4 + 12;')]},
    {'name': 'f3_set_args_swapped', 'file': 'pop_local.c',
     'edits': [('SET_RValue(dst, r4, (int32_t)r7);',
                'SET_RValue(r4, dst, (int32_t)r7);')]},
    {'name': 'f3_instance_sentinel_lost', 'file': 'pop_local.c',
     'edits': [('r7 = INSTANCE_SELF;', 'r7 = 0;')]},
    {'name': 'f3_dyn_index_zeroed', 'file': 'pop_local.c',
     'edits': [('InternalGetYYVar(self, (int32_t)r6)',
                'InternalGetYYVar(self, 0)')]},
    # 0xe1fe0 bic r6,r6,#-268435456 clears bits 28..31, and a 4-bit left shift
    # discards exactly those bits — so dropping the mask is INVISIBLE in the
    # table destination and only shows up in the InternalGetYYVar argument.
    # That is a property of the body, not a gap in the case set; the tooth is
    # pinned by the dynamic-variable case with variable id 5.
    {'name': 'f3_varid_mask_dropped', 'file': 'pop_local.c',
     'edits': [('r6 &= CODE_VARID_MASK;', '(void)0;')]},
]

MUTANT_NOTES = {}


def _sample(case, a, r):
    return {'case': case.label,
            'ret': {'original': a['ret'], 'mutant': r['ret']},
            'calls': {'original': a['calls'], 'mutant': r['calls']},
            'mem': {'original': a['mem'][:96], 'mutant': r['mem'][:96]},
            'spdlt': {'original': a['spdlt'], 'mutant': r['spdlt']}}


def teeth_one(m, case_list, a_recs):
    """Judge one mutant.  A batch that aborts is re-diagnosed one case per
    process: the crash belongs to the cases that crash, and every surviving
    case is still compared on all four facets."""
    try:
        b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
    except RuntimeError as exc:
        # A mutant that does not compile proves nothing, so it is a FAILED
        # tooth, not a crash: the receipt must name it, not bury it.
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
ROW = re.compile(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$')
CALLEE_SYM = re.compile(r'<([^>]+)>')
BRANCH = re.compile(r'^(b|bl|bx|beq|bne|bgt|blt|bge|ble|bhi|bls|bcs|bcc)$')


def dis_body(entry, stop):
    """(instructions {addr: text}, rows [(addr, mnemonic, operand, sym)])."""
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                        '--stop-address=%#x' % stop, '-M', 'reg-names-std', SO],
                       capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('llvm-objdump failed: %s' % p.stderr[-800:])
    dis, rows = {}, []
    for ln in p.stdout.splitlines():
        m = ROW.match(ln)
        if not m:
            continue
        addr, rest = int(m.group(1), 16), m.group(3)
        text = ' '.join(x for x in rest.split('\t') if x.strip())
        text = re.sub(r'\s*@.*$', '', text)
        text = re.sub(r'\s*<[^>]*>', '', text)
        text = _norm(text)
        dis[addr] = text
        raw = _norm(' '.join(rest.split('\t')))
        fields = raw.split()
        sym = CALLEE_SYM.search(raw)
        rows.append((addr, fields[0] if fields else '',
                     fields[1] if len(fields) > 1 else '',
                     sym.group(1) if sym else None))
    return dis, rows


def census_scan(dis, text):
    """The census for one body, against arbitrary source text (so the gate can
    be fed a corrupted copy and must still reject it)."""
    cands = {}
    for ln in text.splitlines():
        m = ANCHOR.search(ln)
        if m:
            cands.setdefault(int(m.group(1), 16), []).append(_norm(m.group(2)))
    wrong = [{'addr': hex(a), 'objdump': dis[a], 'source': cands.get(a, [])}
             for a in sorted(dis)
             if a not in cands or dis[a] not in cands[a]]
    dupes = [{'addr': hex(a), 'texts': cands[a]}
             for a in sorted(cands) if len(cands[a]) > 1]
    extra = [{'addr': hex(a), 'texts': cands[a]}
             for a in sorted(cands) if a not in dis]
    return {'wrong': wrong, 'duplicate_addresses': dupes,
            'unknown_addresses': extra,
            'ok': not wrong and not dupes and not extra}


BODIES = [('Code_Variable_Find_Name', F1, F1_END, 'find_name.c'),
          ('DoConvIntToVariable', F2, F2_END, 'conv_int.c'),
          ('DoPopLocalVariable', F3, F3_END, 'pop_local.c')]

# Each entry: (body, mutation description, old, new, an address that must go red)
# Every `old` is an ANNOTATION LINE (or a fragment of one) and must occur exactly
# once — the prose of these files quotes the same mnemonics, and a mutation that
# lands in the prose instead of the annotation would test nothing.
CENSUS_SELFTEST = [
    ('Code_Variable_Find_Name', 'operand: the 99999 low half 0x869f -> 0x869e',
     '/* @0xd25fc movw r3, #0x869f */', '/* @0xd25fc movw r3, #0x869e */', F1),
    ('Code_Variable_Find_Name', 'constant word: movt high half 0x1 -> 0x2',
     '/* @0xd2600 movt r3, #0x1 */', '/* @0xd2600 movt r3, #0x2 */', F1 + 4),
    ('DoConvIntToVariable', 'operand: the tag register move #0 -> #1',
     '/* @0xd7748 mov r12, #0 */', '/* @0xd7748 mov r12, #1 */', F2 + 0x0c),
    ('DoPopLocalVariable', 'annotations: the 0xe1f78 tst row deleted',
     '/* @0xe1f78 tst r6, #536870912 */\n', '', F3 + 0x1c),
    ('DoPopLocalVariable', 'constant word: the 99328 half of the id base',
     '/* @0xe1fe4 sub r6, r6, #99328 */',
     '/* @0xe1fe4 sub r6, r6, #99392 */', F3 + 0x88),
]


def instruction_census():
    report, ok = {}, True
    for label, entry, stop, srcname in BODIES:
        dis, _rows = dis_body(entry, stop)
        part = census_scan(dis, (MOD / 'src' / srcname).read_text())
        expect = (stop - entry) // 4
        part.update({'function': label, 'instructions': len(dis),
                     'documented': len(dis) - len(part['wrong']),
                     'words_in_range': expect,
                     'covers_every_word': len(dis) == expect,
                     'ok': part['ok'] and len(dis) == expect})
        report[label] = part
        ok = ok and part['ok']
    report['ok'] = ok
    report['instructions'] = sum(v['instructions'] for v in report.values()
                                 if isinstance(v, dict) and 'instructions' in v)
    report['documented'] = sum(v['documented'] for v in report.values()
                               if isinstance(v, dict) and 'documented' in v)
    return report


def census_selftest():
    """Feed the census a corrupted copy of the annotation block and require it
    to reject exactly the address that was corrupted."""
    out, ok = [], True
    texts = {f: (MOD / 'src' / f).read_text() for _, _, _, f in BODIES}
    for label, what, old, new, addr in CENSUS_SELFTEST:
        f = dict((b[0], b[3]) for b in BODIES)[label]
        entry, stop = dict((b[0], (b[1], b[2])) for b in BODIES)[label]
        dis, _rows = dis_body(entry, stop)
        text = texts[f]
        if text.count(old) != 1:
            out.append({'body': label, 'mutation': what, 'applied': False,
                        'expected_red': True, 'observed_red': None,
                        'ok': False})
            ok = False
            continue
        res = census_scan(dis, text.replace(old, new, 1))
        red_at = [w['addr'] for w in res['wrong']]
        good = (not res['ok']) and hex(addr) in red_at
        out.append({'body': label, 'mutation': what, 'applied': True,
                    'expected_red_at': hex(addr), 'red_at': red_at[:6],
                    'expected_red': True, 'observed_red': not res['ok'],
                    'ok': good})
        ok = ok and good
    return {'mutations': out, 'ok': ok,
            'note': 'the same census_scan() runs on the real sources; three of '
                    'these five corrupt an operand/constant word, two delete or '
                    'blank an annotation line'}


# ── binding ──────────────────────────────────────────────────────────────────
def sha(p):
    return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()


def header_layout():
    """The AO_* layout the C arm uses, read out of its own header."""
    text = (MOD / 'src' / 'variable_ops.h').read_text()
    got = {}
    for m in re.finditer(r'^#define\s+(AO_[A-Z0-9]+|ARENA_SIZE)\s+(0x[0-9a-fA-F]+)u?',
                         text, re.M):
        got[m.group(1)] = int(m.group(2), 16)
    return got


def binding():
    got = header_layout()
    mine = {'AO_NAME': AO_NAME, 'AO_RETSTR': AO_RETSTR, 'AO_VSTACK': AO_VSTACK,
            'AO_SP': AO_SP, 'AO_CODE': AO_CODE, 'AO_EXEC': AO_EXEC,
            'AO_SELF': AO_SELF, 'AO_TABLE': AO_TABLE, 'AO_DYN': AO_DYN,
            'ARENA_SIZE': ARENA_SIZE, 'AO_W1': AO_W1, 'AO_W1LEN': AO_W1LEN,
            'AO_W2': AO_W2, 'AO_W2LEN': AO_W2LEN, 'AO_W3': AO_W3,
            'AO_W3LEN': AO_W3LEN}
    layout_bad = {k: {'header': got.get(k), 'harness': v}
                  for k, v in mine.items() if got.get(k) != v}

    bodies, ok = {}, not layout_bad
    for label, entry, stop, srcname in BODIES:
        dis, rows = dis_body(entry, stop)
        callees, internal = {}, []
        for addr, mnem, operand, sym in rows:
            if not BRANCH.match(mnem) or not operand.startswith('0x'):
                continue
            tgt = int(operand, 16)
            if entry <= tgt < stop:
                internal.append(hex(tgt))
            else:
                callees[hex(tgt)] = sym
        pcrel = [hex(a) for a, _m, _o, _s in rows if '[pc' in dis[a]]
        want = {hex(a): n for a, n in CALLEE_NAMES.items()
                if entry <= a < stop or a in
                ({BUILTIN, SCOPE} if label == 'Code_Variable_Find_Name' else
                 {PUSH_CTX, POP_CTX, FREE_RV, SET_RV, IGV}
                 if label == 'DoPopLocalVariable' else set())}
        part_ok = (callees == want and not pcrel
                   and len(dis) == (stop - entry) // 4)
        bodies[label] = {'entry': hex(entry), 'end': hex(stop),
                         'bytes': stop - entry,
                         'instructions': len(dis), 'pool_free': not pcrel,
                         'pc_relative_loads': pcrel,
                         'callees': callees, 'internal_branches': internal,
                         'expected_callees': want, 'ok': part_ok,
                         'body_sha256': sha(MOD / 'src' / srcname)}
        ok = ok and part_ok

    return {'original_sha256': sha(SO), 'sha_matches_pin': sha(SO) == PIN,
            'bodies': bodies, 'arena_layout': got,
            'arena_layout_matches_harness': not layout_bad,
            'arena_layout_mismatch': layout_bad,
            'ok': ok and sha(SO) == PIN}


# ── card re-check ────────────────────────────────────────────────────────────
CARD_DELTAS = [
    {'card': 'cards/Code_Variable_Find_Name.c',
     'claim': '@func 0xd25fc 0xd2618 size 28, 7 instructions, no frame, both '
              'exits are tail jumps, 99999 = movw 0x869f + movt 0x1',
     'bytes': '7 instructions 0xd25fc..0xd2614, 0x1c = 28 B, no pc-relative '
              'load anywhere in the body, 0xd2610 and 0xd2614 are both `b`',
     'verdict': 'consistent'},
    {'card': 'cards/Code_Variable_Find_Name.c',
     'claim': 'the built-in branch throws away name and type (0xd260c mov r0, '
              'r2) and both targets only take the id',
     'bytes': '0xd260c is mov r0, r2 and 0xd2610 branches to 0x1f3b38; the case '
              'set proves it by handing the same id three different names',
     'verdict': 'consistent'},
    {'card': 'cards/DoConvIntToVariable.c',
     'claim': 'prose block: "vldr s15,[sp]", "vstr s14,[sp,#-12]", '
              '"str #0,[sp]", "写 12 字节对象的前 4 字节", open: "s14 的来源"',
     'bytes': 'the bytes are [r1]-based, not [sp]-based: 0xd773c vldr s15,[r1], '
              '0xd7750 vstr s14,[r1,#-12], 0xd7758 str r12,[r0],#-12. And s14 is '
              'not residual: 0xd7740 vcvt.f64.s32 d7,s15 defines d7, whose low '
              'half IS s14 — the stored low word is the double\'s, and a wire '
              'probe with s14 preloaded to 0x3f800000 shows it overwritten',
     'verdict': 'card prose is stale; its own annotated instruction list (the '
                'second block) is right. No byte disagreement, one prose fix.'},
    {'card': 'cards/DoConvIntToVariable.c',
     'claim': 'open: "12 字节里 tag 字段的位置" / "写 12 字节对象"',
     'bytes': 'object is 16 B at r1-12: +0 low word, +4 high word, +8 NEVER '
              'written (no instruction stores to r1-4), +0xc tag word 0. The '
              '"12 bytes" is the store footprint, not the object size',
     'verdict': 'corrected: 16-byte RValue with a hole at +8, tag at +0xc'},
    {'card': 'cards/DoPopLocalVariable.c',
     'claim': '@func 0xe1f5c 0xe2014 size 184, 46 instructions; idx = (raw & '
              '0x0fffffff) - 99328 - 672; stride 16; self->[4] table; '
              'self->[0x24] gate; result {+0=0,+8=0,+0xc=5}, +4 untouched',
     'bytes': '46 instructions, 0xb8 = 184 B, every one of those claims is '
              'reproduced by the arm: the SET_RValue destination offset is '
              'table + idx*16, the gate at 0xf90 gates the store, and the MEM '
              'window keeps the staged 0x33333333 at slot+4',
     'verdict': 'consistent'},
    {'card': 'cards/DoPopLocalVariable.c',
     'claim': 'stack effect: "sp 净下移 0：16 B 出去、16 B 回来"',
     'bytes': 'the body never touches the CPU sp beyond its own frame. The r1 '
              'pointer it returns moves by 16 + 4*[bit31 clear] + 4*[bit29 '
              'clear], i.e. 16 / 20 / 24 — the arm records all three',
     'verdict': 'corrected wording: the delta is the returned sp minus the '
                'incoming sp, and it is never 0'},
]
CARD_NOTE = ('Two prose-level deltas, both in cards/DoConvIntToVariable.c (its '
             '[sp]-based description contradicts its own [r1]-based annotation '
             'list, and it calls the result a 12-byte object when the tag sits '
             'at +0xc of a 16-byte slot with a hole at +8); one wording delta in '
             'cards/DoPopLocalVariable.c about the stack effect. No instruction '
             'address, opcode, offset or constant in any of the three cards '
             'disagrees with the bytes.')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('var_ops_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    bind = binding()
    census = instruction_census()
    cself = census_selftest()

    base_bin = build_c(BUILD / 'var_ops.arm')
    c_recs = run_c_arm(base_bin, case_list)

    # the Oracle's blanket FREE_RValue__Pre stub would answer the same address a
    # second time; this arm answers it itself so there is exactly one F record
    # per call.
    handler_oracle.STUBS.pop(FREE_RV, None)
    stage = Stage(Oracle())
    a_recs = [stage.run(c) for c in case_list]
    traces = list(stage.traces.get(1, [])), list(stage.traces.get(2, [])), \
        list(stage.traces.get(3, []))

    def trace_of(i):
        fn = case_list[i].fn
        return traces[fn - 1][sum(1 for j in range(i) if case_list[j].fn == fn)]

    rows, mismatches = [], []
    for i, (case, a, c) in enumerate(zip(case_list, a_recs, c_recs)):
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
    coverage['f1_builtin_identical_across_names'] = _f1_builtin_ignores_name(
        list(zip(case_list, a_recs)))
    coverage['f2_dead_arg_identical_records'] = _f2_dead_arg(
        list(zip(case_list, a_recs)))
    coverage['f3_dead_arg_identical_records'] = _f3_dead_arg(
        list(zip(case_list, a_recs)))

    teeth = [teeth_one(m, case_list, a_recs) for m in MUTANTS]
    teeth_by_fn = {'Code_Variable_Find_Name': 0, 'DoConvIntToVariable': 0,
                   'DoPopLocalVariable': 0}
    for t in teeth:
        for body, srcname in (('Code_Variable_Find_Name', 'find_name.c'),
                              ('DoConvIntToVariable', 'conv_int.c'),
                              ('DoPopLocalVariable', 'pop_local.c')):
            if t['file'] == srcname:
                teeth_by_fn[body] += 1

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    status = 'PASS' if (identity and cov_ok and rep_ok and teeth_ok
                        and census['ok'] and cself['ok'] and bind['ok']) else 'FAIL'

    per_fn = {k: [r for r in rows if r['case']['fn'] == k] for k in (1, 2, 3)}

    receipt = {
        'schema': 'cally-var-ops-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0xd25fc / 0xd773c / 0xe1f5c executed over one staged '
                           'arena, with identical stubs on both arms; NOT device '
                           'execution'),
        'BINDING': {
            'original_sha256': PIN,
            'functions': bind['bodies'],
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'header_sha256': sha(MOD / 'src' / 'variable_ops.h'),
            'arena_layout': bind['arena_layout'],
            'arena_layout_matches_harness':
                bind['arena_layout_matches_harness'],
            'binding_checks': {
                'sha_matches_pin': bind['sha_matches_pin'],
                'stub_callees': [
                    'Variable_BuiltIn_Find_Name@0x1f3b38',
                    'Variable_GetName_Scope@0xd2228',
                    'PushContextStack@0xd3968',
                    'PopContextStack@0xd3a34',
                    'FREE_RValue__Pre@0xc0a7c',
                    'SET_RValue@0xd0b24',
                    'InternalGetYYVar@0x196a70'],
                'ok': bind['ok'],
            },
        },
        'scope': {
            'covered': [
                'F1: id > 99999 signed -> Variable_GetName_Scope, all three '
                'arguments live (boundary 99999 vs 100000, INT_MAX, negative '
                'ids incl. INT_MIN, id 0)',
                'F1: id <= 99999 -> Variable_BuiltIn_Find_Name(id) with name '
                'and type unreachable (three different names, same id)',
                'F1: the return value is the callee answer verbatim - two '
                'distinct canned strings, NULL, and the name pointer itself',
                'F1: name forwarded byte-exactly on the scope branch - "alpha", '
                '"beta", "" and NULL; type forwarded incl. INT_MIN',
                'F2: int32 -> double is exact for 42, 0, +-1, 65537, 2^24+1, '
                '0xFF000000, INT_MAX, INT_MIN, 1234567890',
                'F2: the 12-byte store footprint below the stack top - low word '
                'at +0, high word at +4, tag word 0 at +0xc, the +8 hole and '
                'everything above the top left holding the sentinel',
                'F2: return value is r1-12 (post-index writeback), and the dead '
                'first argument changes nothing',
                'F3: both operand flags - instance id popped / INT_MIN sentinel, '
                'and one-word vs two-word value stack (sp delta 24 / 20 / 16)',
                'F3: self == 0 (no context stack), self->[0x24] == 0 (Push/Pop, '
                'no store), self->[0x24] != 0 with self->[4] (direct table '
                'destination) and with self->[4] == 0 (InternalGetYYVar)',
                'F3: slot arithmetic - (raw & 0x0fffffff) - 100000, stride 16, '
                'ids 0, 5, 16 and 0x0fffffff',
                'F3: the FREE gate is tag in 1..4 after masking bits 24..31 and '
                'bits 0..1 - tags 0, 1, 4, 5, 0x105, 0x40000001, 0x80000001, '
                '0xffffffff',
                'F3: the consumed slot is rewritten to {+0=0, +8=0, +0xc=5} with '
                '+4 untouched, and the return is slot+16',
                'second-run reproducibility of both arms'],
            'not_covered': [
                'Variable_BuiltIn_Find_Name semantics (stubbed): the 16-byte '
                'strided built-in table and its "<unknown built-in variable>" '
                'fallback at 0x3527c8',
                'Variable_GetName_Scope semantics (stubbed): the linear strcmp '
                'scan, the [id-100000] index and the Script_Find_Parent branch',
                'PushContextStack / PopContextStack semantics (stubbed): this '
                'arm proves they are called once each, in that order, with the '
                'right object - not what they push',
                'FREE_RValue__Pre semantics (stubbed): which tag classes release '
                'which payload is that callee\'s business, and the stub has no '
                'memory effect',
                'SET_RValue semantics (stubbed): the actual RValue copy and the '
                'instance-id refcount handling.  F3 proves the destination '
                'address, the source slot and the instance id it is handed',
                'InternalGetYYVar semantics (stubbed): it always answers the '
                'staged AO_DYN block',
                'Variable_GetName_Scope as written by the parallel workstream in '
                'c/variable_misc/ is NOT linked here, on purpose.  It is another '
                'workstream\'s in-flight body (684 B, its own tables, snprintf '
                'and Script_Find_Parent); linking it would fold its claims into '
                'F1\'s verdict, and the stub is also what makes the two arms '
                'comparable in the first place.  A later batch that wants the '
                'composed F1+callee behaviour should link it explicitly and say '
                'so.',
                'device behaviour'],
            'not_applicable': [
                'No body here reads a global or a rodata string: all three are '
                'pool-free and GOT-free, so there is no .bss to stage and no '
                'error text to compare.  The error-message contract of this '
                'chain lives in the VMError callers (DoPushLocal 0xd4b1c, '
                'DoPop 0xe6788), which are outside this batch.',
                'DoConvIntToVariable has no callee and no branch: its 9 '
                'instructions are straight-line, so its coverage is the nine '
                'addresses themselves plus the record fields.'],
        },
        'findings': [
            'DoConvIntToVariable does not touch the CPU stack pointer at all: '
            'r1 is a value-stack pointer argument, and the returned pointer is '
            'r1-12 from the post-index writeback at 0xd7758.  The stack top word '
            'is still there, at the returned +12, now holding the tag.',
            'The card\'s open question about s14 is answered by the bytes: '
            '0xd7740 vcvt.f64.s32 d7, s15 writes d7 = {s14, s15}, so 0xd7750 '
            'vstr s14 stores the double\'s low word.  A probe that preloads s14 '
            'with 0x3f800000 and then reads r1-12 shows it overwritten by the '
            'converted low word, and the 8 bytes at r1-12 equal struct '
            'pack("<d", value) for every case.',
            'The RValue that F2 builds is 16 bytes with a HOLE at +8: +0 low, '
            '+4 high, +8 never written, +0xc tag 0.  Only three of four words '
            'are stored, and the arm keeps the sentinel at +8 to prove it.',
            'F3\'s FREE gate is not "tag != 0".  It is (tag-1) & 0x00fffffc == '
            '0, so tag 0x40000001 and 0x80000001 both release (their high bits '
            'are masked off) while tag 5 and 0x105 do not.  The case set pins '
            'all four classes.',
            'F3 returns slot+16 with the slot rewritten to tag 5, so the net '
            'stack effect is 16/20/24 depending on the two operand flags - the '
            'card\'s "sp 净下移 0" describes the CPU frame, not this pointer.',
            'F1\'s comparison is signed: bgt sends every negative id, including '
            'INT_MIN, down the built-in branch that discards the name — the '
            'branch where the name cannot even be reached.',
            'card/byte agreement: every address, opcode, offset and constant in '
            'the three cards was re-checked against llvm-objdump; see '
            'card_deltas.  The deltas are prose-level, in '
            'cards/DoConvIntToVariable.c.'],
        'card_deltas': CARD_DELTAS,
        'card_note': CARD_NOTE,
        'instruction_census': census,
        'census_selftest': cself,
        'repeat': repeat,
        'cases': len(case_list),
        'cases_f1': len(per_fn[1]),
        'cases_f2': len(per_fn[2]),
        'cases_f3': len(per_fn[3]),
        'rows': rows,
        'coverage': coverage,
        'covered_by': covered_by,
        'teeth': teeth,
        'teeth_total': len(teeth),
        'teeth_by_function': teeth_by_fn,
        'teeth_modes': {m: sum(1 for t in teeth if t['mode'] == m)
                        for m in sorted({t['mode'] for t in teeth})},
        'status': status,
    }
    out = args.out or (RECEIPTS / ('var_ops_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d (F1 %d, F2 %d, F3 %d) identical=%d '
          'binding=%s census=%d/%d census-self=%s'
          % (status, len(case_list), len(per_fn[1]), len(per_fn[2]),
             len(per_fn[3]), sum(1 for r in rows if r['equal']),
             'ok' if bind['ok'] else 'BAD',
             census['documented'], census['instructions'],
             'ok' if cself['ok'] else 'BAD'))
    print('  REPEAT second-run identical  original=%s rebuild=%s' % (
        'yes' if repeat['original_identical'] else 'NO',
        'yes' if repeat['rebuild_identical'] else 'NO'))
    for k, v in coverage.items():
        print('  COVER %-38s %s  %s' % (k, 'yes' if v else 'NO',
                                        (covered_by.get(k) or [''])[0][:52]))
    for t in teeth:
        print('  TEETH %-30s %s caught_by=%d mode=%s aborted=%d' % (
            t['mutant'], 'PASS' if t['passed'] else 'FAIL',
            len(t['caught_by']), t['mode'], len(t['aborted_cases'])))
    for m in mismatches[:6]:
        print('  DIFF case=%r' % (m['case']['label'],))
        print('    original', m['original'])
        print('    rebuild ', m['rebuild'])
    for body in census:
        if not isinstance(census[body], dict) or 'wrong' not in census[body]:
            continue
        for w in census[body]['wrong'][:6]:
            print('  CENSUS %s %s objdump=%r source=%r'
                  % (body, w['addr'], w['objdump'], w['source']))
        for w in census[body]['duplicate_addresses'][:6]:
            print('  CENSUS dup %s %s' % (body, w['addr']))
        for w in census[body]['unknown_addresses'][:6]:
            print('  CENSUS extra %s %s' % (body, w['addr']))
    for m in cself['mutations']:
        if not m['ok']:
            print('  CENSUS-SELF %r applied=%s red=%s at=%s'
                  % (m['mutation'], m['applied'], m['observed_red'],
                     m.get('red_at')))
    for label, part in bind['bodies'].items():
        if not part['ok']:
            print('  BINDING %s callees=%r want=%r pcrel=%r'
                  % (label, part['callees'], part['expected_callees'],
                     part['pc_relative_loads']))
    if bind['arena_layout_mismatch']:
        print('  BINDING layout mismatch %r' % (bind['arena_layout_mismatch'],))
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
