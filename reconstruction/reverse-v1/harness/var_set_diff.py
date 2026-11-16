#!/usr/bin/env python3
"""Variable_SetValue — original-binary differential (Level A, one function).

Two arms, same inputs, same staged memory:
  arm A (judge)  the original bytes at 0x1f4348, executed in Unicorn over a
                 staged object table, instance table, CObjectGM chain, the two
                 fallback containers and the active-instance list
  arm B (claim)  reconstruction/reverse-v1/c/variable_set/, cross-compiled for
                 armv7a-none-eabi (freestanding) and run under qemu-arm

Why arm B must not be host-compiled: every offset in this body is a literal
(0x4 next / 0x8 key / 0xc value / 0x68 / 0x69 / 0x80 / 0xd0 / 0x178) and the
bucket array is addressed with `lsl #3`, the container item array with `lsl #2`.
A 64-bit host build moves pointers to 8 bytes and every one of those offsets
stops testing what the original does.

Compared per case: the return value and the ordered call log
    D <instance index> <var> <index> <value offset>
    E <NAME|INDEX|OTHER> <first vararg> <second vararg>
with the instance index and the value offset resolved through each arm's own
registry, never as raw pointers (the two arms have different addresses).

Scope, stated up front: the callees of this body are
  * Variable_SetValue_Direct @0x1f3c28  (4 bl + 1 tail b) - NOT recovered
  * YYError @0xd547c                    (3 bl)             - NOT recovered
and GET_RValue @0xd13bc / YYObjectBase::InternalGetYYVar @0x196a70 are two
levels further down (they are Direct's callees), so this differential never
reaches them at all.  Both arms run IDENTICAL stubs for Direct and YYError; the
stubs are part of the evidence (they log every call and answer deterministically)
and are also the reason a green run proves only this body's dispatch, ordering,
field offsets and return plumbing - not those callees, and not device
equivalence.

Gates:
  * identity   every case identical on both arms (return value + call log)
  * coverage   every branch decision of the ORIGINAL body is actually taken,
               proven by the instruction trace of the original arm (COVER)
  * teeth      every source-level mutant of the translation is caught by at
               least one named case; a green mutant means the case set does not
               exercise that decision, so identity above would be worthless

Usage:
  python3 var_set_diff.py             # build, run both arms, write receipt
  python3 var_set_diff.py --no-run    # replay the gates on the last receipt
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

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
MOD = RV1 / 'c' / 'variable_set'
BUILD = HERE / 'build' / 'var_set'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3, UC_ARM_REG_PC,
    UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
ENTRY = 0x1f4348
POOL = 0x1f4744
DIRECT = 0x1f3c28
YYERROR = 0xd547c

# the five .bss objects the body reaches through the GOT
BSS_OBJTABLE = 0x542374      # GOT 0x3edc44 : cell HOLDS a pointer
BSS_CONTAINER_C1 = 0x542a64  # GOT 0x3edc48 : cell IS the container
BSS_INSTTABLE = 0x536f28     # GOT 0x3edc4c : cell IS the table
BSS_CONTAINER_C2 = 0x542a4c  # GOT 0x3edc50 : cell IS the container
BSS_RUNTIME = 0x54298c       # GOT 0x3ed930 : cell HOLDS a pointer

# rodata strings this body passes to YYError
RO_MSG_NAME = 0x334928
RO_MSG_PLAIN = 0x352800
RO_MSG_NULL = 0x3527f8
MSG_NAME = "Unable to find any instance for object index '%d' name '%s'"
MSG_PLAIN = "Unable to find any instance for object index '%d'"
MSG_NULL = "(null)"

NINST = 8
INST_SIZE = 0x180
NBUCK = 8
NCH = 4
MARK_WORD = 0x5A1E0001
INT_MIN = -0x80000000


# ── cases ────────────────────────────────────────────────────────────────────
def cases():
    """(sel, var, index, f_s2, f_c1, f_c2, f_s5, f_s1, label).  Deterministic.

    f_* knobs select the staging (see Stage.stage); every knob is applied on
    every case, so a wrong path still finds readable memory.
    """
    return [
        (0, 100, INT_MIN, 0, 0, 0, 0, 0, 'S2 empty bucket -> E5 "(null)"'),
        (9999, 0, 5, 5, 0, 0, 0, 0, 'S2 hit, 3 chain nodes: ok/dead/off'),
        (10000, 7, 9, 6, 0, 0, 0, 0, 'S2 hit, dead node then node without inst'),
        (10007, 3, 3, 1, 0, 0, 0, 0, 'S2 chain, key never matches'),
        (10050, 4, 4, 2, 0, 0, 0, 0, 'S2 key hit, value NULL'),
        (10001, 5, 5, 3, 0, 0, 0, 0, 'S2 key hit, CObjectGM without chain'),
        (10002, 6, 6, 4, 0, 0, 0, 0, 'S2 chain head without an instance'),
        (10003, 8, 8, 0, 2, 0, 0, 0, 'C1 hit only'),
        (10004, 9, 9, 0, 1, 0, 0, 0, 'C1 element without chain, then a miss'),
        (10005, 10, 10, 0, 3, 0, 0, 0, 'C1 match but destroyed'),
        (10006, 11, 11, 0, 4, 0, 0, 0, 'C1 match but deactivated'),
        (10008, 12, 12, 0, 5, 0, 0, 0, 'C1 two elements, first gated'),
        (10009, 13, 13, 0, 6, 0, 0, 0, 'C1 two-node key chain: miss then hit'),
        (10010, 14, 14, 0, 7, 0, 0, 0, 'C1 signed count <= 0'),
        (10011, 15, 15, 0, 0, 2, 0, 0, 'C2 hit only'),
        (10012, 16, 16, 0, 0, 1, 0, 0, 'C2 element without chain, then a miss'),
        (10013, 17, 17, 0, 0, 3, 0, 0, 'C2 match but destroyed'),
        (10014, 18, 18, 0, 0, 4, 0, 0, 'C2 match but deactivated'),
        (10015, 19, 19, 0, 0, 5, 0, 0, 'C2 two elements, first gated'),
        (10016, 20, 20, 0, 0, 6, 0, 0, 'C2 two-node key chain: miss then hit'),
        (10017, 21, 21, 0, 0, 7, 0, 0, 'C2 signed count <= 0'),
        (10018, 22, 22, 5, 2, 2, 0, 0, 'S2 + C1 + C2 all hit: 3 Directs'),
        (99999, 23, 23, 5, 0, 0, 0, 0, 'boundary 99999 stays on S2'),
        (100001, 24, 24, 0, 0, 0, 0, 0, 'S5 empty bucket'),
        (100002, 25, 25, 0, 0, 0, 1, 0, 'S5 chain, key never matches'),
        (100003, 26, 26, 0, 0, 0, 2, 0, 'S5 key hit, value NULL'),
        (100004, 27, 27, 0, 0, 0, 3, 0, 'S5 key hit, instance destroyed'),
        (100005, 28, 28, 0, 0, 0, 4, 0, 'S5 tail call'),
        (100006, 29, 29, 0, 0, 0, 5, 0, 'S5 miss then hit'),
        (100007, 30, 30, 0, 0, 0, 6, 0, 'S5 ignores +0x69 (still dispatches)'),
        (-3, 32, 32, 0, 0, 0, 0, 0, 'S1 empty active list'),
        (-3, 33, 33, 0, 0, 0, 0, 1, 'S1 every instance gated'),
        (-3, 34, 34, 0, 0, 0, 0, 2, 'S1 ok / dead / ok'),
        (-3, 35, 35, 0, 0, 0, 0, 3, 'S1 single instance'),
        (-1, 36, 36, 0, 0, 0, 0, 0, 'sel < 0 -> return 0, silent'),
        (-2, 0, 0, 0, 2, 2, 4, 2, 'sel < 0 but every structure is live'),
        (0, -7, -8, 0, 2, 2, 0, 0, 'negative var/index passthrough'),
        (10019, 39, 2147483647, 5, 0, 0, 0, 0, 'INT_MAX index passthrough'),
        (10020, 40, -1, 0, 6, 6, 0, 0, 'both containers, index -1'),
        (10021, 41, 41, 0, 2, 1, 0, 0,
         'C1 hits, C2 has a count but no match: return survives C2'),
    ]


# ── coverage: decisions of the ORIGINAL body, proven by its own trace ────────
def _ex(tr, a):
    return a in tr


def _tk(tr, a, b):
    for i in range(len(tr) - 1):
        if tr[i] == a and tr[i + 1] == b:
            return True
    return False


def _direct_return_last(tr, rec, case):
    d = [c for c in rec['calls'] if c[0] == 'D']
    if not d:
        return False
    idx = d[-1][1]
    want = 0x1000 + len(d) * 0x100 + (0 if idx == 0xFF else idx)
    return rec['ret'] == want


COVER = [
    ('entry_sel_m3', lambda tr, rec, c: _tk(tr, 0x1f436c, 0x1f4600)),
    ('entry_sel_negative', lambda tr, rec, c: _tk(tr, 0x1f4374, 0x1f4684)),
    ('entry_sel_gt_99999', lambda tr, rec, c: _tk(tr, 0x1f4384, 0x1f46a0)),
    ('s2_bucket_empty', lambda tr, rec, c: _tk(tr, 0x1f43a8, 0x1f43ac)
     and _tk(tr, 0x1f43ac, 0x1f4690)),
    ('s2_chain_exhausted', lambda tr, rec, c: _tk(tr, 0x1f43b8, 0x1f4690)),
    ('s2_key_mismatch_next', lambda tr, rec, c: _tk(tr, 0x1f43c4, 0x1f43b0)),
    ('s2_value_null', lambda tr, rec, c: _tk(tr, 0x1f43d4, 0x1f4694)),
    ('s2_no_instance_chain', lambda tr, rec, c: _tk(tr, 0x1f43e4, 0x1f4738)),
    ('s2_first_inst_null', lambda tr, rec, c: _tk(tr, 0x1f43f4, 0x1f4450)),
    ('s2_skip_destroyed', lambda tr, rec, c: _tk(tr, 0x1f4420, 0x1f4448)),
    ('s2_skip_deactivated', lambda tr, rec, c: _tk(tr, 0x1f4438, 0x1f4448)),
    ('s2_direct', lambda tr, rec, c: _ex(tr, 0x1f443c)),
    ('s2_loop_resume', lambda tr, rec, c: _tk(tr, 0x1f444c, 0x1f4404)),
    ('s2_loop_exit_inst_null', lambda tr, rec, c: _tk(tr, 0x1f440c, 0x1f4450)),
    ('c1_skipped_count', lambda tr, rec, c: _tk(tr, 0x1f4460, 0x1f4514)),
    ('c1_element_no_chain', lambda tr, rec, c: _tk(tr, 0x1f4494, 0x1f44f0)),
    ('c1_key_chain_walk', lambda tr, rec, c: _tk(tr, 0x1f44b4, 0x1f4498)),
    ('c1_key_miss', lambda tr, rec, c: _tk(tr, 0x1f44bc, 0x1f44f0)),
    ('c1_skip_destroyed', lambda tr, rec, c: _tk(tr, 0x1f44c8, 0x1f44f0)),
    ('c1_skip_deactivated', lambda tr, rec, c: _tk(tr, 0x1f44d4, 0x1f44f0)),
    ('c1_direct', lambda tr, rec, c: _ex(tr, 0x1f44e8)),
    ('c1_loop_next_element', lambda tr, rec, c: _tk(tr, 0x1f44fc, 0x1f4484)),
    ('c2_skipped_count', lambda tr, rec, c: _tk(tr, 0x1f4524, 0x1f45cc)),
    ('c2_element_no_chain', lambda tr, rec, c: _tk(tr, 0x1f4558, 0x1f45b4)),
    ('c2_key_chain_walk', lambda tr, rec, c: _tk(tr, 0x1f4578, 0x1f455c)),
    ('c2_key_miss', lambda tr, rec, c: _tk(tr, 0x1f4580, 0x1f45b4)),
    ('c2_skip_destroyed', lambda tr, rec, c: _tk(tr, 0x1f458c, 0x1f45b4)),
    ('c2_skip_deactivated', lambda tr, rec, c: _tk(tr, 0x1f4598, 0x1f45b4)),
    ('c2_direct', lambda tr, rec, c: _ex(tr, 0x1f45ac)),
    ('c2_loop_next_element', lambda tr, rec, c: _tk(tr, 0x1f45c0, 0x1f4548)),
    ('hit_suppresses_error', lambda tr, rec, c: _tk(tr, 0x1f45d0, 0x1f4668)),
    ('error_name_arg', lambda tr, rec, c: _ex(tr, 0x1f45e0)
     and _ex(tr, 0x1f45f0)),
    ('error_null_name', lambda tr, rec, c: _tk(tr, 0x1f45dc, 0x1f472c)),
    ('s1_head_null', lambda tr, rec, c: _tk(tr, 0x1f4614, 0x1f470c)),
    ('s1_skip_destroyed', lambda tr, rec, c: _tk(tr, 0x1f462c, 0x1f4654)),
    ('s1_skip_deactivated', lambda tr, rec, c: _tk(tr, 0x1f4644, 0x1f4654)),
    ('s1_direct', lambda tr, rec, c: _ex(tr, 0x1f4648)),
    ('s1_loop_next', lambda tr, rec, c: _tk(tr, 0x1f465c, 0x1f4620)),
    ('s1_no_hit_error', lambda tr, rec, c: _tk(tr, 0x1f4664, 0x1f4710)),
    ('s1_return_accumulator', lambda tr, rec, c: _tk(tr, 0x1f4664, 0x1f4668)),
    ('s5_bucket_empty', lambda tr, rec, c: _tk(tr, 0x1f46bc, 0x1f46c0)),
    ('s5_chain_end', lambda tr, rec, c: _tk(tr, 0x1f46cc, 0x1f4674)),
    ('s5_key_mismatch_next', lambda tr, rec, c: _tk(tr, 0x1f46d8, 0x1f46c4)),
    ('s5_value_null', lambda tr, rec, c: _tk(tr, 0x1f46e4, 0x1f4674)),
    ('s5_skip_destroyed', lambda tr, rec, c: _tk(tr, 0x1f46f0, 0x1f4674)),
    ('s5_tail_direct', lambda tr, rec, c: _ex(tr, 0x1f4708)),
    ('e3_message', lambda tr, rec, c: _ex(tr, 0x1f4680)),
    ('e4_message', lambda tr, rec, c: _ex(tr, 0x1f471c)),
    ('e5_message', lambda tr, rec, c: _ex(tr, 0x1f45f0)),
    ('ret_zero_exit', lambda tr, rec, c: _ex(tr, 0x1f4684)),
    ('return_is_last_direct', _direct_return_last),
    ('s5_ignores_0x69', lambda tr, rec, c: c[6] == 6
     and any(r[0] == 'D' for r in rec['calls'])),
    ('index_passthrough', lambda tr, rec, c: any(
        r[0] == 'D' and r[3] == c[2] for r in rec['calls'])),
    ('negative_var_passthrough', lambda tr, rec, c: any(
        r[0] == 'D' and r[2] < 0 for r in rec['calls'])),
]


# ── original arm ─────────────────────────────────────────────────────────────
def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


class Stage:
    """One staged environment; hooks installed once.

    Per case only the staged words are rewritten and the logs cleared: adding
    hooks per case would leave the previous case's hooks live on the same
    Unicorn instance.
    """

    def __init__(self, o):
        self.o = o
        self.log = []
        self.tr = []
        self.ncall = 0
        self.inst = o.alloc(NINST * INST_SIZE)
        self.reg = {self.inst + i * INST_SIZE: i for i in range(NINST)}
        self.objgm = o.alloc(0x100)   # must span +0xd0
        self.runtime = o.alloc(0x88)
        self.value = o.alloc(16)
        self.bucket_obj = o.alloc(NBUCK * 8)
        self.bucket_inst = o.alloc(NBUCK * 8)
        self.objnodes = o.alloc(3 * 16)
        self.instnodes = o.alloc(3 * 16)
        self.s2chain = o.alloc(4 * 12)
        self.ch1 = o.alloc(NCH * 0x50)
        self.ch2 = o.alloc(NCH * 0x50)
        self.name = o.alloc(16)
        o.write(self.name, b'OBJNAME\0')
        self.c1items = o.alloc(8)
        self.c2items = o.alloc(8)
        self.tbl_obj = o.alloc(8)
        o.write(self.c1items, struct.pack('<II', self.inst + 3 * INST_SIZE,
                                          self.inst + 4 * INST_SIZE))
        o.write(self.c2items, struct.pack('<II', self.inst + 5 * INST_SIZE,
                                          self.inst + 6 * INST_SIZE))
        for fn, addr in ((self.hook_direct, DIRECT), (self.hook_yyerror, YYERROR)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=ENTRY, end=POOL - 4)

    # -- hooks --------------------------------------------------------------
    def hook_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def hook_direct(self, uc_, _a, _s, _d):
        obj = uc_.reg_read(UC_ARM_REG_R0)
        var = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        axi = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        val = uc_.reg_read(UC_ARM_REG_R3)
        self.ncall += 1
        idx = self.reg.get(obj & 0xffffffff, 0xFF)
        self.log.append(['D', idx, var, axi, to_i32(val - self.value)])
        ret = 0x1000 + self.ncall * 0x100 + (0 if idx == 0xFF else idx)
        uc_.reg_write(UC_ARM_REG_R0, ret & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_yyerror(self, uc_, _a, _s, _d):
        fmt = self.o.read_cstr(uc_.reg_read(UC_ARM_REG_R0))
        a1 = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        if fmt == MSG_NAME:
            kind, a2 = 'NAME', self.o.read_cstr(uc_.reg_read(UC_ARM_REG_R2))
        elif fmt == MSG_PLAIN:
            kind, a2 = 'INDEX', '-'
        else:
            kind, a2 = 'OTHER', fmt[:24]
        self.ncall += 1
        self.log.append(['E', kind, a1, a2])
        uc_.reg_write(UC_ARM_REG_R0, 0xEEEE)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    # -- staging ------------------------------------------------------------
    def _w(self, addr, w):
        self.o.write(addr, struct.pack('<I', w & 0xffffffff))

    def _inst(self, i):
        return self.inst + i * INST_SIZE

    def _node(self, base, i, next_, key, value):
        self._w(base + i * 16 + 0x0, 0)
        self._w(base + i * 16 + 0x4, next_)
        self._w(base + i * 16 + 0x8, key & 0xffffffff)
        self._w(base + i * 16 + 0xc, value)

    def _instnode(self, i, next_, inst):
        self._w(self.s2chain + i * 12 + 0x0, next_)
        self._w(self.s2chain + i * 12 + 0x4, 0)
        self._w(self.s2chain + i * 12 + 0x8, inst)

    def _chnode(self, base, i, key, next_):
        self._w(base + i * 0x50 + 0x18, key & 0xffffffff)
        self._w(base + i * 0x50 + 0x48, next_)

    def stage(self, sel, f_s2, f_c1, f_c2, f_s5, f_s1):
        o = self.o
        b = (sel & 0xffffffff) & (NBUCK - 1)
        alt = (sel ^ 0x4000) & 0xffffffff

        o.write(self.inst, b'\0' * (NINST * INST_SIZE))
        o.write(self.objgm, b'\0' * 0x100)
        o.write(self.runtime, b'\0' * 0x88)
        o.write(self.value, b'\0' * 16)
        o.write(self.bucket_obj, b'\0' * (NBUCK * 8))
        o.write(self.bucket_inst, b'\0' * (NBUCK * 8))
        o.write(self.objnodes, b'\0' * 48)
        o.write(self.instnodes, b'\0' * 48)
        o.write(self.s2chain, b'\0' * 48)
        o.write(self.ch1, b'\0' * (NCH * 0x50))
        o.write(self.ch2, b'\0' * (NCH * 0x50))

        self._w(self.value, MARK_WORD)
        self._w(self.objgm + 0x14, self.name)

        # the five .bss cells, with the indirection depth the code has
        self._w(self.tbl_obj + 0, self.bucket_obj)
        self._w(self.tbl_obj + 4, NBUCK - 1)
        self._w(BSS_OBJTABLE, self.tbl_obj)
        self._w(BSS_INSTTABLE + 0, self.bucket_inst)
        self._w(BSS_INSTTABLE + 4, NBUCK - 1)
        self._w(BSS_RUNTIME, self.runtime)

        # containers: items always staged, count/gates per knob
        self._w(BSS_CONTAINER_C1 + 0, self.c1items)
        self._w(BSS_CONTAINER_C1 + 4, 0)
        self._w(BSS_CONTAINER_C2 + 0, self.c2items)
        self._w(BSS_CONTAINER_C2 + 4, 0)

        # default element chains
        self._w(self._inst(3) + 0x80, self.ch1 + 0 * 0x50)
        self._w(self._inst(4) + 0x80, self.ch1 + 1 * 0x50)
        self._w(self._inst(5) + 0x80, self.ch2 + 0 * 0x50)
        self._w(self._inst(6) + 0x80, self.ch2 + 1 * 0x50)
        self._chnode(self.ch1, 0, sel, 0)
        self._chnode(self.ch1, 1, alt, 0)
        self._chnode(self.ch2, 0, sel, 0)
        self._chnode(self.ch2, 1, alt, 0)
        self._chnode(self.ch1, 2, alt, self.ch1 + 3 * 0x50)
        self._chnode(self.ch1, 3, sel, 0)
        self._chnode(self.ch2, 2, alt, self.ch2 + 3 * 0x50)
        self._chnode(self.ch2, 3, sel, 0)

        # ── S2 knob
        if f_s2 == 1:
            self._node(self.objnodes, 0, 0, alt, self.objgm)
            self._w(self.bucket_obj + b * 8, self.objnodes)
        elif f_s2 == 2:
            self._node(self.objnodes, 0, self.objnodes + 16, alt, self.objgm)
            self._node(self.objnodes, 1, 0, sel, 0)
            self._w(self.bucket_obj + b * 8, self.objnodes)
        elif f_s2 == 3:
            self._node(self.objnodes, 0, 0, sel, self.objgm)
            self._w(self.bucket_obj + b * 8, self.objnodes)
        elif f_s2 == 4:
            self._node(self.objnodes, 0, 0, sel, self.objgm)
            self._w(self.objgm + 0xd0, self.s2chain)
            self._instnode(0, 0, 0)
            self._w(self.bucket_obj + b * 8, self.objnodes)
        elif f_s2 == 5:
            self._node(self.objnodes, 0, 0, sel, self.objgm)
            self._w(self.objgm + 0xd0, self.s2chain)
            self._instnode(0, self.s2chain + 12, self._inst(0))
            self._instnode(1, self.s2chain + 24, self._inst(1))
            self._instnode(2, 0, self._inst(2))
            o.write(self._inst(1) + 0x68, b'\x01')
            o.write(self._inst(2) + 0x69, b'\x01')
            self._w(self.bucket_obj + b * 8, self.objnodes)
        elif f_s2 == 6:
            self._node(self.objnodes, 0, 0, sel, self.objgm)
            self._w(self.objgm + 0xd0, self.s2chain)
            self._instnode(0, self.s2chain + 12, self._inst(1))
            self._instnode(1, 0, 0)
            o.write(self._inst(1) + 0x68, b'\x01')
            self._w(self.bucket_obj + b * 8, self.objnodes)

        # ── C1 / C2 knobs
        self._w(BSS_CONTAINER_C1 + 8, self._count(f_c1))
        self._w(BSS_CONTAINER_C2 + 8, self._count(f_c2))
        self._gates(f_c1, 3, self.ch1, o)
        self._gates(f_c2, 5, self.ch2, o)

        # ── S5 knob
        if f_s5 == 1:
            self._node(self.instnodes, 0, 0, alt, self._inst(7))
            self._w(self.bucket_inst + b * 8, self.instnodes)
        elif f_s5 == 2:
            self._node(self.instnodes, 0, 0, sel, 0)
            self._w(self.bucket_inst + b * 8, self.instnodes)
        elif f_s5 == 3:
            self._node(self.instnodes, 0, 0, sel, self._inst(7))
            o.write(self._inst(7) + 0x68, b'\x01')
            self._w(self.bucket_inst + b * 8, self.instnodes)
        elif f_s5 == 4:
            self._node(self.instnodes, 0, 0, sel, self._inst(7))
            self._w(self.bucket_inst + b * 8, self.instnodes)
        elif f_s5 == 5:
            self._node(self.instnodes, 0, self.instnodes + 16, alt, self._inst(7))
            self._node(self.instnodes, 1, 0, sel, self._inst(7))
            self._w(self.bucket_inst + b * 8, self.instnodes)
        elif f_s5 == 6:
            self._node(self.instnodes, 0, 0, sel, self._inst(7))
            o.write(self._inst(7) + 0x69, b'\x01')
            self._w(self.bucket_inst + b * 8, self.instnodes)

        # ── S1 knob
        if f_s1 == 1:
            o.write(self._inst(0) + 0x68, b'\x01')
            o.write(self._inst(1) + 0x69, b'\x01')
            self._w(self._inst(0) + 0x178, self._inst(1))
            self._w(self._inst(1) + 0x178, 0)
            self._w(self.runtime + 0x80, self._inst(0))
        elif f_s1 == 2:
            o.write(self._inst(1) + 0x68, b'\x01')
            self._w(self._inst(0) + 0x178, self._inst(1))
            self._w(self._inst(1) + 0x178, self._inst(2))
            self._w(self._inst(2) + 0x178, 0)
            self._w(self.runtime + 0x80, self._inst(0))
        elif f_s1 == 3:
            self._w(self._inst(0) + 0x178, 0)
            self._w(self.runtime + 0x80, self._inst(0))

    @staticmethod
    def _count(f):
        if f in (0,):
            return 0
        if f == 7:
            return -1
        if f in (1, 5):
            return 2
        return 1

    def _gates(self, f, first, chbase, o):
        """Mirror of the driver's C1/C2 switch body."""
        base = self._inst(first)
        if f == 1:
            self._w(base + 0x80, 0)
        elif f == 3:
            o.write(base + 0x68, b'\x01')
        elif f == 4:
            o.write(base + 0x69, b'\x01')
        elif f == 5:
            # first element gated, second one must be the one that hits
            o.write(base + 0x68, b'\x01')
            self._w(self._inst(first + 1) + 0x80, chbase)
        elif f == 6:
            self._w(base + 0x80, chbase + 2 * 0x50)

    # -- run ----------------------------------------------------------------
    def run(self, case):
        sel, var, index, f_s2, f_c1, f_c2, f_s5, f_s1 = case[:8]
        self.stage(sel, f_s2, f_c1, f_c2, f_s5, f_s1)
        self.log = []
        self.tr = []
        self.ncall = 0
        ret = self.o.call(ENTRY, r0=sel & 0xffffffff, r1=var & 0xffffffff,
                          r2=index & 0xffffffff, r3=self.value)
        return {'ret': to_i32(ret), 'calls': list(self.log), 'tr': list(self.tr)}


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']


def build_c(out_bin, mutant=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    src = MOD / 'src' / 'variable_set.c'
    if mutant:
        text = src.read_text()
        for old, new in mutant['edits']:
            if text.count(old) != 1:
                raise RuntimeError('mutation site not unique (%d hits): %r'
                                   % (text.count(old), old))
            text = text.replace(old, new)
        src = BUILD / ('mut_%s.c' % mutant['name'])
        src.write_text(text)
    cmd = (['clang'] + ARM_FLAGS +
           ['-O1', '-I', str(MOD / 'src'), str(src),
            str(MOD / 'fixture' / 'driver.c'), '-o', str(out_bin)])
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed [%s]: %s'
                           % (' '.join(cmd[:3]), p.stderr[-3000:]))
    return out_bin


def run_c_arm(binary, case_list):
    blob = ''.join('%d %d %d %d %d %d %d %d\n' % c[:8] for c in case_list).encode()
    p = subprocess.run(['qemu-arm', str(binary)], input=blob, capture_output=True)
    if p.returncode:
        raise RuntimeError('driver exit %d: %s' % (p.returncode,
                                                   p.stderr.decode()[-2000:]))
    recs, cur = [], None
    for line in p.stdout.decode().splitlines():
        parts = line.split()
        if not parts:
            continue
        if parts[0] == 'CASE':
            cur = {'ret': 0, 'calls': []}
            recs.append(cur)
        elif parts[0] == 'D':
            cur['calls'].append(['D', int(parts[1]), int(parts[2]),
                                 int(parts[3]), int(parts[4])])
        elif parts[0] == 'E':
            cur['calls'].append(['E', parts[1], int(parts[2]),
                                 parts[3] if len(parts) > 3 else ''])
        elif parts[0] == 'RET':
            cur['ret'] = int(parts[1])
        elif parts[0] == 'CALLS':
            cur['ncalls'] = int(parts[1])
    return recs


def same(a, c):
    return a['ret'] == c['ret'] and a['calls'] == c['calls']


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    {'name': 'sel_boundary_ge', 'edits': [
        ('if (sel > SEL_INSTANCE_MAX)', 'if (sel >= SEL_INSTANCE_MAX)')]},
    {'name': 'sel_m3_wrong_constant', 'edits': [
        ('if (sel == SEL_ALL_ACTIVE)', 'if (sel == -4)')]},
    {'name': 'negative_gate_dropped', 'edits': [
        ('if (sel < 0)\n        goto RET_ZERO;', 'if (0)\n        goto RET_ZERO;')]},
    {'name': 's2_bucket_stride_4', 'edits': [
        ('((u32)sel & tbl->mask) * BUCKET_STRIDE',
         '((u32)sel & tbl->mask) * 4')]},
    {'name': 's5_bucket_stride_4', 'edits': [
        ('g_setvalue_inst_table.mask) *\n'
         '                                       BUCKET_STRIDE',
         'g_setvalue_inst_table.mask) *\n'
         '                                       4')]},
    {'name': 's5_key_compare_uses_var', 'edits': [
        ('/* 0x1f46d0 ldr  r2, [r3, #0x8] */\n'
         '            /* 0x1f46d4 cmp  r4, r2 */\n'
         '            /* 0x1f46d8 bne  0x1f46c4 */\n'
         '            if (n->key == sel)',
         '/* 0x1f46d0 ldr  r2, [r3, #0x8] */\n'
         '            /* 0x1f46d4 cmp  r4, r2 */\n'
         '            /* 0x1f46d8 bne  0x1f46c4 */\n'
         '            if (n->key == var)')]},
    {'name': 's5_destroyed_gate_dropped', 'edits': [
        ('if (rd8(cur + YYB_DESTROYED) != 0)\n                goto ERR_S5;',
         'if (0)\n                goto ERR_S5;')]},
    {'name': 's5_gate_0x69_added', 'edits': [
        ('if (rd8(cur + YYB_DESTROYED) != 0)\n                goto ERR_S5;',
         'if (rd8(cur + YYB_DESTROYED) != 0 || rd8(cur + YYB_DEACT) != 0)\n'
         '                goto ERR_S5;')]},
    {'name': 's2_gate_0x69_dropped', 'edits': [
        ('if (rd8(cur + YYB_DEACT) == 0) {', 'if (1) {')]},
    {'name': 's2_gate_0x68_dropped', 'edits': [
        ('if (rd8(cur + YYB_DESTROYED) == 0) {', 'if (1) {')]},
    {'name': 'c1_extra_indirection', 'edits': [
        ('var_container *c1 = &g_setvalue_container_c1;',
         'var_container *c1 = *(var_container **)&g_setvalue_container_c1;')]},
    {'name': 's2_hit_flag_not_set', 'edits': [
        ('/* 0x1f4440 mov  r12, #1 */\n                        hit = 1;',
         '/* 0x1f4440 mov  r12, #1 */\n                        hit = 0;')]},
    {'name': 'c1_item_stride_8', 'edits': [
        ('(items + (u32)i * ITEM_STRIDE)', '(items + (u32)i * 8)')]},
    {'name': 'c1_direct_args_swapped', 'edits': [
        ('/* 0x1f44e8 bl   0x1f3c28 */\n'
         '                                acc = Variable_SetValue_Direct(x, var, index, value);',
         '/* 0x1f44e8 bl   0x1f3c28 */\n'
         '                                acc = Variable_SetValue_Direct(x, index, var, value);')]},
    {'name': 'c1_count_ge_zero', 'edits': [
        ('if (c1->count > 0) {', 'if (c1->count >= 0) {')]},
    {'name': 'c1_count_offset_plus4', 'edits': [
        ('if (c1->count > 0) {', 'if ((int32_t)c1->pad > 0) {')]},
    {'name': 'c2_accumulator_reset', 'edits': [
        ('/* 0x1f452c mov  r0, r10 */\n            int acc = ret;',
         '/* 0x1f452c mov  r0, r10 */\n            int acc = 0;')]},
    {'name': 'error_name_offset', 'edits': [
        ('name = *(const char **)(void *)(obj + YYB_NAME);',
         'name = *(const char **)(void *)(obj + 0x18);')]},
    {'name': 's1_next_offset', 'edits': [
        ('*(unsigned char **)(void *)(cur + YYB_NEXT)',
         '*(unsigned char **)(void *)(cur + 0x174)')]},
]


# ── instruction census ──────────────────────────────────────────────────────
def _norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def instruction_census():
    """Every reachable instruction of the original must appear in the
    translation as `0xADDR <verbatim operand text>`, and each of the ten
    literal-pool words must be documented with its value.

    This is the machine check behind 'one comment line per machine
    instruction': a translation that dropped a gate, a store or an exit cannot
    pass it, and a resurrected typo in an offset shows up as a mismatch against
    llvm-objdump rather than as prose.
    """
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % ENTRY,
                        '--stop-address=%#x' % (POOL + 0x28),
                        '-M', 'reg-names-std', SO],
                       capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('llvm-objdump failed: %s' % p.stderr[-800:])
    dis, pool = {}, {}
    for ln in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
        if not m:
            continue
        addr, word, rest = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        if addr < POOL:
            text = ' '.join(x for x in rest.split('\t') if x.strip())
            text = re.sub(r'\s*@.*$', '', text)
            text = re.sub(r'\s*<[^>]*>', '', text)
            dis[addr] = _norm(text)
        else:
            pool[addr] = word
    src = (MOD / 'src' / 'variable_set.c').read_text()
    cands = {}
    for ln in src.splitlines():
        for m in re.finditer(r'0x([0-9a-f]{6,8})\s+(.*?)(?:\*/|$)', ln):
            txt = re.split(r'\s+--|objdump:|;\s*0x', m.group(2))[0]
            cands.setdefault(int(m.group(1), 16), []).append(_norm(txt))
    wrong = [{'addr': hex(a), 'objdump': dis[a], 'source': cands.get(a, [])[:2]}
             for a in sorted(dis)
             if a not in cands or dis[a] not in cands[a]]
    pool_missing = [{'addr': hex(a), 'word': '%08x' % w}
                    for a, w in sorted(pool.items())
                    if not any(('.word 0x%08x' % w) in c
                               for c in cands.get(a, []))]
    return {'instructions': len(dis),
            'documented': len(dis) - len(wrong),
            'wrong': wrong,
            'pool_words': len(pool),
            'pool_missing': pool_missing,
            'ok': not wrong and not pool_missing}


# ── binding checks ───────────────────────────────────────────────────────────
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


def sha(p):
    return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('var_set_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    # binding: the pinned image and the three rodata strings this body passes
    img_sha = sha(SO)
    strs = {'0x334928': rodata_string(SO, RO_MSG_NAME),
            '0x352800': rodata_string(SO, RO_MSG_PLAIN),
            '0x3527f8': rodata_string(SO, RO_MSG_NULL)}
    binding_ok = (img_sha == PIN and strs['0x334928'] == MSG_NAME
                  and strs['0x352800'] == MSG_PLAIN
                  and strs['0x3527f8'] == MSG_NULL)
    census = instruction_census()

    # claim arm
    base_bin = build_c(BUILD / 'var_set.arm')
    c_recs = run_c_arm(base_bin, case_list)

    # judge arm
    stage = Stage(Oracle())
    a_recs = [stage.run(c) for c in case_list]

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_recs, c_recs):
        eq = same(a, c)
        rows.append({'case': case[:8], 'label': case[8],
                     'original': {'ret': a['ret'], 'calls': a['calls']},
                     'rebuild': {'ret': c['ret'], 'calls': c['calls']},
                     'equal': eq})
        if not eq:
            mismatches.append(rows[-1])

    # repeat gate: a second, freshly built Oracle for arm A and a second driver
    # process for arm B must reproduce both record streams exactly.  This is
    # what rules out staged state leaking from one case (or one process) into
    # the next.
    stage2 = Stage(Oracle())
    a_rep = [stage2.run(c) for c in case_list]
    c_rep = run_c_arm(base_bin, case_list)
    repeat = {'original': all(same(x, y) for x, y in zip(a_recs, a_rep)),
              'rebuild': all(same(x, y) for x, y in zip(c_recs, c_rep))}

    coverage = {}
    covered_by = {}
    for name, fn in COVER:
        hits = [c[8] for c, a in zip(case_list, a_recs) if fn(a['tr'], a, c)]
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]

    teeth = []
    for m in MUTANTS:
        b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
        try:
            recs = run_c_arm(b, case_list)
        except RuntimeError as exc:
            # A mutant that makes the arm crash is discriminated, but by abort
            # rather than by a field mismatch - weaker, and recorded as such.
            teeth.append({'mutant': m['name'], 'caught_by': [], 'passed': True,
                          'mode': 'driver-abort', 'detail': str(exc)[:200],
                          'note': ('discrimination is by abort, not by a field '
                                   'mismatch; the case set cannot say WHICH '
                                   'field moved')})
            continue
        caught = [c[8] for c, a, r in zip(case_list, a_recs, recs) if not same(a, r)]
        teeth.append({'mutant': m['name'], 'caught_by': caught,
                      'mode': 'mismatch', 'passed': bool(caught)})

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    rep_ok = all(repeat.values())
    status = ('PASS' if (identity and cov_ok and teeth_ok and binding_ok
                         and rep_ok and census['ok']) else 'FAIL')

    receipt = {
        'schema': 'cally-var-set-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0x1f4348 executed over staged .bss cells, hash '
                           'tables, containers and instance chains, with '
                           'identical Direct/YYError stubs on both arms; NOT '
                           'device execution'),
        'BINDING': {
            'original_sha256': img_sha,
            'original_sha256_pinned': PIN,
            'entry': hex(ENTRY),
            'function': '_Z17Variable_SetValueiiiP6RValue',
            'body_sha256': sha(MOD / 'src' / 'variable_set.c'),
            'header_sha256': sha(MOD / 'src' / 'variable_set.h'),
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'rodata_strings': strs,
            'rodata_match': binding_ok,
            'stub_callees': ['Variable_SetValue_Direct@0x1f3c28',
                             'YYError@0xd547c'],
            'build': 'clang --target=armv7a-none-eabi (freestanding) + qemu-arm',
        },
        'scope': {
            'covered': [
                'entry dispatch: sel == -3 / sel < 0 / sel > 99999 / else',
                'S2 object table: bucket index = sel & mask, 8-byte buckets, '
                'node {+4 next, +8 key, +0xc CObjectGM}',
                'S2: CObjectGM+0xd0 instance chain, +0x68/+0x69 gates, '
                'loop advance-before-callback',
                'S3/S4 containers (%#x / %#x): {+0 items, +8 signed count}, '
                'element +0x80 chain {+0x18 key, +0x48 next}, gates, '
                'item stride 4' % (BSS_CONTAINER_C1, BSS_CONTAINER_C2),
                'S5 (%#x): table IS the cell, {+0 buckets, +4 mask}, only '
                '+0x68 is checked, tail call' % BSS_INSTTABLE,
                'S1: active list *(*(0x54298c)+0x80), next at +0x178, both '
                'gates',
                'return contract: last Direct return, 0 on the error exits',
                'error messages: name variant, plain variant, "(null)" name',
                'var/index/value passthrough (incl. negative and INT_MAX)',
            ],
            'not_covered': [
                'Variable_SetValue_Direct semantics (stubbed identically on '
                'both arms) - not recovered',
                'YYError semantics (stubbed identically; the real one may exit '
                'the process) - not recovered',
                'GET_RValue@0xd13bc and InternalGetYYVar@0x196a70: two levels '
                'below Direct, never reached by this differential',
                'the identity of the two fallback containers C1/C2 and what '
                'their elements are',
                'whether one instance can be written twice (S2 + C1/C2)',
                'device behaviour: this is a synthetic-memory oracle over the '
                'original bytes, not execution on a phone',
            ],
        },
        'instruction_census': census,
        'cases': len(case_list),
        'repeat': repeat,
        'rows': rows,
        'coverage': coverage,
        'coverage_witness': covered_by,
        'teeth': teeth,
        'status': status,
    }
    out = args.out or (RECEIPTS / ('var_set_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d identical=%d binding=%s repeat=%s census=%d/%d'
          % (status, len(case_list), sum(1 for r in rows if r['equal']),
             'ok' if binding_ok else 'MISMATCH',
             'ok' if rep_ok else 'DRIFT',
             census['documented'], census['instructions']))
    if not census['ok']:
        for w in census['wrong'][:6]:
            print('  CENSUS %s objdump=%r source=%r'
                  % (w['addr'], w['objdump'], w['source']))
        for w in census['pool_missing'][:6]:
            print('  CENSUS pool %s word=%s undocumented' % (w['addr'], w['word']))
    for k, v in coverage.items():
        print('  COVER %-26s %s' % (k, 'yes' if v else 'NO'))
    for t in teeth:
        print('  TEETH %-28s %s mode=%-12s caught_by=%d'
              % (t['mutant'], 'PASS' if t['passed'] else 'FAIL', t['mode'],
                 len(t['caught_by'])))
    for m in mismatches[:8]:
        print('  DIFF case=%r' % (m['label'],))
        print('    original', m['original'])
        print('    rebuild ', m['rebuild'])
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
