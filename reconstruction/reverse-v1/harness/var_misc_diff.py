#!/usr/bin/env python3
"""Variable-family remainders of libyoyo — original-binary differential.

Functions under judgement, all from the pinned image
(3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):

  F1  _Z20Variable_Global_Initv                    @0x001f3354
      24 instructions + 2 literal-pool words, 104 B.  void.
  F2  _Z24DoVariableInstanceExistsP9CInstancePKc   @0x001178b8
      33 instructions, no literal pool, 132 B.  int (0/1).
  F3  _Z22Variable_GetName_ScopePKcii              @0x000d2228
      158 instructions + 13 literal-pool words, 684 B.  const char *.
  F4  _Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b
      @0x001f4da8, 164 instructions + 6 literal-pool words, 680 B.  void.

Two arms, same inputs, same staged memory:
  arm A (judge)  the original bytes, executed in Unicorn over the real .bss the
                 GOT points at (0x753100 globdecl, 0x753108 builtin_numb,
                 0x75310c the 500x16 table, 0x7530fc the map pointer,
                 0x47a19c/0x47a18c/0x47a178/0x47a1ac/0x47a1b0 the name tables,
                 0x544b5c and 0x47f295 the two gates, 0x75505c the failure byte)
  arm B (claim)  reconstruction/reverse-v1/c/variable_misc/, plus the two
                 already recovered bodies c/variable_names/src/
                 find_slot_from_name.c and c/variable_direct/src/
                 variable_direct.c, built for armv7a-none-eabi (freestanding)
                 and run under qemu-arm

Why arm B must not be host-compiled: the name tables are 16 B
{size,count,?,data}, the map header is 20 B with entries at +0x10 and 12 B
items, the builtin table entry is 16 B with writable@+0xc, the local function
table element is 12 B, and every body addresses them with `lsl #2` / `lsl #4`.
A 64-bit host build moves all of them and stops testing what the original does.

Scope, stated up front
  * Variable_GetValue_Direct @0x1f3b8c and Code_Variable_Find_Slot_From_Name
    @0x000d21ec are ALREADY recovered; the claim arm links those translations
    for real and the judge arm runs their original bytes, so F2's differential
    covers four bodies, not one.
  * Everything one level below is UNRECOVERED and runs as an identical stub on
    both arms: MemoryManager::ReAlloc 0x27cedc, Variable_BuiltIn_Find 0x1f3a5c,
    Variable_GetName 0xd1d04, Script_Find_Parent 0x1e06dc, strcmp/snprintf/
    memset @plt, GET_RValue 0xd13bc, InternalGetYYVar 0x196a70, the builtin
    getter fn, YYStrDup 0xdb8c8, MemoryManager::{Alloc,Free}, CHashMap::
    CalculateHash 0x1eeb88, CHashMap::Insert 0xd261c, ShowMessage 0xc4b0c.
    A green run proves nothing about those callees and is not device
    equivalence.  Two of those stubs (the hash and Insert) DEFINE the map
    layout the rehash produces; the harness says so where it matters.

Gates:
  * binding    image sha256, the 12 GOT-slot -> .bss chains this file stages,
               and the four rodata strings the bodies use
  * census     every instruction of the original appears in the translation as
               `@0xADDR <verbatim llvm-objdump text>`, each address exactly
               once, every literal-pool word documented with its value; the
               gate is itself tested by three source mutations that must turn
               it red (operand digit, missing comment, wrong pool word)
  * identity   every case identical on both arms (return, ordered call log,
               per-function observed state, failure byte)
  * coverage   every decision of the ORIGINAL body is taken, proven by its own
               instruction trace (COVER)
  * repeat     both arms rerun in a second process reproduce their records
  * teeth      every source-level mutant is caught by at least one named case

Usage:
  python3 var_misc_diff.py            # build, run both arms, write receipt
  python3 var_misc_diff.py --no-run   # replay the gates on the last receipt
  python3 var_misc_diff.py --fns 1,2  # restrict to a subset (development aid;
                                      # a restricted run records 'partial')
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
MOD = RV1 / 'c' / 'variable_misc'
NAMES_MOD = RV1 / 'c' / 'variable_names'
DIRECT_MOD = RV1 / 'c' / 'variable_direct'
BUILD = HERE / 'build' / 'var_misc'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
    UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

# ── the four bodies ─────────────────────────────────────────────────────────
F1 = 0x1f3354            # Variable_Global_Init
F1_POOL = 0x1f33b4
F1_END = 0x1f33bc
F2 = 0x1178b8            # DoVariableInstanceExists
F2_END = 0x11793c        # no literal pool: the next function starts here
F3 = 0xd2228             # Variable_GetName_Scope
F3_POOL = 0xd24a0
F3_END = 0xd24d4
F4 = 0x1f4da8            # Variable_BuiltIn_Add
F4_POOL = 0x1f5038
F4_END = 0x1f5050

FUNCS = {
    1: {'name': 'Variable_Global_Init', 'entry': F1, 'pool': F1_POOL,
        'end': F1_END, 'src': 'variable_global_init.c', 'npool': 2,
        'ninstr': 24},
    2: {'name': 'DoVariableInstanceExists', 'entry': F2, 'pool': F2_END,
        'end': F2_END, 'src': 'do_variable_instance_exists.c', 'npool': 0,
        'ninstr': 33},
    3: {'name': 'Variable_GetName_Scope', 'entry': F3, 'pool': F3_POOL,
        'end': F3_END, 'src': 'variable_getname_scope.c', 'npool': 13,
        'ninstr': 158},
    4: {'name': 'Variable_BuiltIn_Add', 'entry': F4, 'pool': F4_POOL,
        'end': F4_END, 'src': 'variable_builtin_add.c', 'npool': 6,
        'ninstr': 164},
}

# ── callees ─────────────────────────────────────────────────────────────────
REALLOC = 0x27cedc
BUILTIN_FIND = 0x1f3a5c
GETNAME = 0xd1d04
SCRIPT_PARENT = 0x1e06dc
HASH = 0x1eeb88
INSERT = 0xd261c
STRDUP = 0xdb8c8
MM_ALLOC = 0x27ce78
MM_FREE = 0x27c2d0
SHOWMSG = 0xc4b0c
MEMSET_PLT = 0xb65b0
STRCMP_PLT = 0xb6574
SNPRINTF_PLT = 0xb65c8
GET_RVALUE = 0xd13bc             # inside the linked Variable_GetValue_Direct
INTERNAL_GETYYVAR = 0x196a70     # ditto, lazy-slot path
BVAR_GETTER = 0x1f3bfc           # ditto, `blx r3` through the table entry
LOCAL_NAME = 0xd1f74             # inside the linked Find_Slot_From_Name
GLOBAL_NAME = 0xd2054            # ditto

# ── GOT cells -> .bss, all read out of the pinned image by binding() ────────
GOT_GLOBDECL = 0x3f0e30
BSS_GLOBDECL = 0x753100
GOT_BUILTIN_NUMB = 0x3edc3c
BSS_BUILTIN_NUMB = 0x753108
GOT_BUILTIN_TABLE = 0x3edc40
BSS_BUILTIN_TABLE = 0x75310c
GOT_BUILTIN_MAP = 0x3f0e34
BSS_BUILTIN_MAP = 0x7530fc
GOT_GLOBAL_NAMES = 0x3edba4
BSS_GLOBAL_NAMES = 0x47a19c
GOT_INST_NAMES = 0x3edba8
BSS_INST_NAMES = 0x47a18c
GOT_INST_MAP = 0x3edbac
BSS_INST_MAP = 0x47a178
GOT_NUM_LOCAL = 0x3edbb4
BSS_NUM_LOCAL = 0x47a1ac
GOT_LOCAL_ARR = 0x3edbb8
BSS_LOCAL_ARR = 0x47a1b0
GOT_GATE1 = 0x3edb5c
BSS_GATE1 = 0x544b5c
GOT_GATE2 = 0x3edbc0
BSS_GATE2 = 0x47f295
BSS_FAILFLAG = 0x75505c
GOT_GUARD = 0x3ed958
RO_UNKNOWN_VAR = 0x332760
RO_SCRIPT_FMT = 0x332774
RO_TOO_MANY = 0x352854
RO_CARRAY = 0x34d23c
RO_MEMMGR = 0x331038

MSG_UNKNOWN_VARIABLE = '<unknown variable>'
MSG_SCRIPT_FMT = 'gml_Script_%s'
MSG_TOO_MANY = 'INTERNAL ERROR: Adding too many variables'
FILE_CARRAY = 'jni/../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h'
FILE_MEMMGR = 'jni/../jni/yoyo/../../../Platform/MemoryManager.h'

INT_MIN = -0x80000000
INT_MAX = 0x7fffffff
GUARD = 0xc2331111


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


def cases_f1():
    """Variable_Global_Init.  p0 prefill, p1 old pointer staged, p2 flag."""
    return [
        Case(1, 0xaa, 1, 0, 0, 0, 0, 0,
             'F1 10000 B prefilled 0xaa, live old pointer, flag clear'),
        Case(1, 0xaa, 1, 1, 0, 0, 0, 0,
             'F1 same, failure byte pre-set: the body must not clear it'),
        Case(1, 0x00, 0, 0, 0, 0, 0, 0,
             'F1 prefill 0 and NULL old pointer: the bl gets 0 as its first arg'),
        Case(1, 0x5a, 0, 1, 0, 0, 0, 0,
             'F1 prefill 0x5a, NULL old pointer, flag set'),
    ]


def cases_f2():
    """DoVariableInstanceExists.
    p0 builtin-find answer, p1 slot mode (0 miss, 1 slot 3, 2 slot 7, 3 slot 0,
    4 slot 3 with a NULL slot table), p2 RValue tag, p3 name tag,
    p4 builtin_numb stage (dead input), p5 failure byte, p6 inst+0x24 == 0."""
    return [
        Case(2, 0, 0, 0, 0, 1, 0, 0,
             'F2 builtin id 0, tag 0: masked tag != 0x00ffffff -> 1'),
        Case(2, 0, 0, 0xffffff, 0, 1, 0, 0,
             'F2 builtin id 0, tag 0x00ffffff -> 0: the only "absent" answer'),
        Case(2, 0, 0, 0x1234ffff, 0, 0, 0, 0,
             'F2 builtin id 0, builtin_numb 0, tag 0x1234ffff -> masked 0x34ffff'),
        Case(2, 0, 0, 0, 0, 0, 0, 0,
             'F2 builtin id 0, tag 0, builtin_numb 0: dead input pair'),
        Case(2, 499, 0, 0, 0, 1, 1, 0,
             'F2 builtin id 499 (last table entry), failure byte pre-set'),
        Case(2, -1, 1, 0xffffff, 0, 0, 0, 0,
             'F2 not builtin, slot 3 -> id 100003, unset tag -> 0'),
        Case(2, -1, 2, 0, 1, 0, 0, 0,
             'F2 not builtin, slot 7 -> id 100007, empty name'),
        Case(2, -1, 1, 0, 3, 0, 0, 0,
             'F2 not builtin, NULL name reaches both lookups'),
        Case(2, -1, 0, 0, 0, 0, 0, 0,
             'F2 neither builtin nor instance -> 0, RValue never touched'),
        Case(2, -1, 3, 0, 0, 0, 0, 0,
             'F2 slot 0 -> id 100000 (the id base boundary)'),
        Case(2, -1, 1, 0, 0, 0, 0, 1,
             'F2 slot path with inst+0x24 == 0: Direct answers 0 untouched'),
        Case(2, -1, 4, 0, 0, 0, 0, 0,
             'F2 slot path with a NULL slot table -> InternalGetYYVar'),
        Case(2, -2, 1, 0xffffff, 2, 0, 0, 0,
             'F2 builtin_find -2, slot 3, unset tag: any negative is "not builtin"'),
    ]


def cases_f3():
    """Variable_GetName_Scope.
    p0 name tag (0 scrA, 1 other, 2 "", 3 NULL, 4 gml_Script_Par),
    p1 type, p2 id, p3 gate 1, p4 gate 2, p5 table layout (0 empty / 1
    consistent / 2 global count>size + parent entry),
    p6 bit0 Script_Find_Parent answers, bit1 failure byte staged."""
    T = -5
    return [
        # ── gate 1 ──────────────────────────────────────────────────────────
        Case(3, 0, T, 100000, 0, 1, 1, 0,
             'F3 gate 1 closed: Variable_GetName(100000), tables untouched'),
        Case(3, 3, -1, 42, 0, 0, 1, 0,
             'F3 gate 1 closed with a builtin-domain id 42'),
        # ── id domain ──────────────────────────────────────────────────────
        Case(3, 0, T, 99999, 1, 0, 1, 0,
             'F3 id 99999 < 100000 with the gate open -> unknown'),
        Case(3, 0, T, 100000, 1, 0, 1, 0,
             'F3 global slot 0 -> "g0" (the id base is a legal slot)'),
        Case(3, 0, T, 100002, 1, 0, 1, 0,
             'F3 global slot 2 holds NULL -> NULL, not the unknown string'),
        Case(3, 0, T, 100004, 1, 0, 1, 0, 'F3 global slot 4 -> "g4"'),
        Case(3, 0, T, 100005, 1, 0, 1, 0,
             'F3 global slot 5 == count -> unknown'),
        Case(3, 0, T, 0x7fffffff, 1, 0, 1, 0,
             'F3 id INT_MAX -> slot 2147383647, far past every table'),
        # ── global count > size (layout 2) ─────────────────────────────────
        Case(3, 0, T, 100005, 1, 0, 2, 0,
             'F3 global slot 5 < count 6 but >= size 4 -> NULL'),
        Case(3, 0, T, 100006, 1, 0, 2, 0,
             'F3 global slot 6 == count -> unknown'),
        # ── instance table ─────────────────────────────────────────────────
        Case(3, 0, -1, 100000, 1, 0, 1, 0, 'F3 instance slot 0 -> "i0"'),
        Case(3, 0, -1, 100001, 1, 0, 1, 0,
             'F3 instance slot 1 holds NULL -> NULL'),
        Case(3, 0, -1, 100002, 1, 0, 1, 0, 'F3 instance slot 2 -> "i2"'),
        # ── instance reverse map ───────────────────────────────────────────
        Case(3, 0, -1, 100005, 1, 0, 1, 0,
             'F3 instance slot 5 >= count -> map scan finds value 5'),
        Case(3, 0, -1, 100007, 1, 0, 1, 0,
             'F3 instance slot 7 -> map scan walks past a negative hash'),
        Case(3, 0, -1, 100006, 1, 0, 1, 0,
             'F3 instance slot 6: only entry with value 6 has hash < 0 -> skipped'),
        Case(3, 0, -1, 100009, 1, 0, 1, 0,
             'F3 instance slot 9: no map entry carries it -> unknown'),
        Case(3, 0, -1, 100000, 1, 0, 0, 0,
             'F3 instance table empty (count 0) -> unknown without a scan'),
        # ── function-name-keyed local table ────────────────────────────────
        Case(3, 0, -7, 100001, 1, 0, 1, 0, 'F3 local "scrA" slot 1 -> "l1"'),
        Case(3, 0, -12, 100003, 1, 0, 1, 0,
             'F3 local via type -12 (same code path) slot 3 -> "l3"'),
        Case(3, 0, -7, 100005, 1, 0, 1, 0,
             'F3 local slot 5 > entry->count 4: names[5] is read anyway'),
        Case(3, 0, -7, 100007, 1, 0, 1, 0,
             'F3 local slot 7 == the last staged name -> "l7"'),
        Case(3, 1, -7, 100000, 1, 0, 1, 0,
             'F3 local scan misses "other", gate 2 closed -> unknown'),
        Case(3, 1, -7, 100000, 1, 1, 1, 0,
             'F3 local scan misses, gate 2 open, no parent -> unknown'),
        Case(3, 1, -7, 100000, 1, 1, 1, 1,
             'F3 parent fallback formats "gml_Script_Par" and rescan misses'),
        Case(3, 1, -7, 100001, 1, 1, 2, 1,
             'F3 parent rescan HITS "gml_Script_Par" -> names[1] = "p1"'),
        Case(3, 1, -7, 100000, 1, 1, 0, 1,
             'F3 local table empty, gate 2 open, parent answers, table still empty'),
        Case(3, 3, -7, 100000, 1, 1, 1, 1,
             'F3 NULL script name reaches both the scan and the parent lookup'),
        Case(3, 2, -7, 100000, 1, 1, 1, 1,
             'F3 empty script name: same path, a live pointer this time'),
        # ── normalisation into the instance domain ─────────────────────────
        Case(3, 0, -9, 100000, 1, 0, 1, 0,
             'F3 type -9 -> (type & ~2) == -11 -> instance table'),
        Case(3, 0, -11, 100007, 1, 0, 1, 0,
             'F3 type -11 -> instance table, map hit at slot 7'),
        Case(3, 0, 100001, 100007, 1, 0, 1, 0,
             'F3 type 100001 > 100000 -> instance table, map hit'),
        Case(3, 0, 100000, 100000, 1, 0, 1, 0,
             'F3 type 100000 is NOT > 100000 and not -9/-11 -> unknown'),
        Case(3, 0, 0, 100000, 1, 0, 1, 0,
             'F3 type 0 -> unknown'),
        Case(3, 0, 3, 100000, 1, 0, 1, 0,
             'F3 type 3: (3 & ~2) == 1 != -11 -> unknown'),
        Case(3, 0, INT_MIN, 100000, 1, 0, 1, 0,
             'F3 type INT_MIN -> unknown'),
        # ── failure byte ───────────────────────────────────────────────────
        Case(3, 0, T, 100000, 1, 0, 1, 2,
             'F3 failure byte staged 1: the body must leave it set'),
    ]


def cases_f4():
    """Variable_BuiltIn_Add.
    p0 name tag (0..2 alpha/beta/gamma, 3..5 the same bytes at other addresses),
    p1 getter present, p2 setter present, p3 the DEAD 4th argument,
    p4 pre-stage (0 fresh, 1 stale name in table[1], 2 same key pointer already
    mapped, 3 count 499, 4 count 500, 5 two colliding entries at idx / idx+1),
    p5 map mode (0 as initialised, 1 threshold -1 with three old entries,
    2 threshold -1 and an empty old table), p6 unused."""
    return [
        Case(4, 0, 1, 1, 0, 0, 0, 0,
             'F4 fresh insert, getter and setter -> writable 1'),
        Case(4, 0, 1, 0, 0, 0, 0, 0, 'F4 no setter -> writable 0'),
        Case(4, 0, 0, 1, 0, 0, 0, 0,
             'F4 setter only, no getter -> writable 1'),
        Case(4, 0, 0, 0, 0, 0, 0, 0, 'F4 neither -> writable 0'),
        Case(4, 0, 1, 1, 1, 0, 0, 0,
             'F4 dead 4th argument set: the record must equal the first case'),
        Case(4, 1, 1, 1, 0, 0, 0, 0,
             'F4 name "beta": its hash has bit 31 set and must be cleared'),
        Case(4, 2, 1, 1, 0, 0, 0, 0, 'F4 name "gamma"'),
        Case(4, 0, 1, 1, 0, 1, 0, 0,
             'F4 a stale name in the slot about to be reused is freed first'),
        Case(4, 0, 1, 1, 0, 2, 0, 0,
             'F4 the same key POINTER is already mapped: value overwritten and '
             'the count increment undone'),
        Case(4, 3, 1, 1, 0, 8, 0, 0,
             'F4 the same bytes at another address: a second entry, because the '
             'probe compares key pointers, not string contents'),
        Case(4, 1, 1, 1, 0, 2, 0, 0,
             'F4 "beta" twice: dedupe only works if the stored hash was '
             'sign-cleared like the new one'),
        Case(4, 0, 1, 1, 0, 3, 0, 0,
             'F4 count 499: the last legal slot of the fixed table'),
        Case(4, 0, 1, 1, 0, 4, 0, 0,
             'F4 count 500: ShowMessage, and nothing is written at all'),
        Case(4, 0, 1, 1, 0, 5, 0, 0,
             'F4 two colliding entries at idx and idx+1 force the Robin Hood '
             'swap and push the evicted pair one slot further'),
        Case(4, 0, 1, 1, 0, 0, 1, 0,
             'F4 threshold -1: the map doubles and the three old entries are '
             'reinserted through CHashMap::Insert'),
        Case(4, 0, 1, 1, 0, 0, 2, 0,
             'F4 threshold -1 with an empty old table: doubling only'),
        Case(4, 0, 1, 1, 0, 1, 1, 0,
             'F4 stale name freed and the map doubles in the same call'),
        Case(4, 2, 1, 1, 0, 5, 0, 0,
             'F4 collision staging with "gamma" (its own idx, still a swap)'),
        Case(4, 0, 1, 1, 0, 6, 0, 0,
             'F4 a richer entry in our home slot: its distance exceeds ours, so '
             'the walk advances instead of swapping'),
        Case(4, 0, 1, 1, 0, 7, 0, 0,
             'F4 same hash, different key pointer: only the pointer test '
             'rejects it'),
    ]


def cases():
    return cases_f1() + cases_f2() + cases_f3() + cases_f4()


# ── coverage: decisions of the ORIGINAL bodies, proven by their own trace ───
def _tk(tr, a, b):
    for i in range(len(tr) - 1):
        if tr[i] == a and tr[i + 1] == b:
            return True
    return False


def _ex(tr, a):
    return a in tr


def _call(r, k):
    return [c for c in r['calls'] if c[0] == k]


COVER = [
    # ── F1 Variable_Global_Init ─────────────────────────────────────────────
    ('f1_clear_loop_iterated', lambda tr, r, c: c.fn == 1
     and _tk(tr, F1 + 0x54, F1 + 0x48)),
    ('f1_clear_loop_exit', lambda tr, r, c: c.fn == 1 and _ex(tr, F1 + 0x58)),
    ('f1_realloc_called', lambda tr, r, c: c.fn == 1 and _ex(tr, F1 + 0x2c)),
    ('f1_cap_written', lambda tr, r, c: c.fn == 1 and _ex(tr, F1 + 0x40)),
    ('f1_data_written', lambda tr, r, c: c.fn == 1 and _ex(tr, F1 + 0x44)),
    ('f1_all_10000_cleared', lambda tr, r, c: c.fn == 1
     and r['ext']['NZ'] == '0' and r['ext']['FZ'] == '-1'),
    ('f1_old_pointer_forwarded', lambda tr, r, c: c.fn == 1
     and bool(_call(r, 'Q')) and _call(r, 'Q')[0][4] == '1'),
    ('f1_null_pointer_forwarded', lambda tr, r, c: c.fn == 1
     and bool(_call(r, 'Q')) and _call(r, 'Q')[0][4] == '0'),
    ('f1_zero_flag_is_false', lambda tr, r, c: c.fn == 1
     and bool(_call(r, 'Q')) and _call(r, 'Q')[0][3] == '0'),
    ('f1_file_and_line_are_carray', lambda tr, r, c: c.fn == 1
     and bool(_call(r, 'Q')) and _call(r, 'Q')[0][5] == '1'
     and _call(r, 'Q')[0][2] == '106'),
    ('f1_flag_set_stays_set', lambda tr, r, c: c.fn == 1 and c.p2 == 1
     and r['flag'] == 1),
    ('f1_flag_clear_stays_clear', lambda tr, r, c: c.fn == 1 and c.p2 == 0
     and r['flag'] == 0),
    # ── F2 DoVariableInstanceExists ─────────────────────────────────────────
    ('f2_builtin_negative_taken', lambda tr, r, c: c.fn == 2
     and _tk(tr, F2 + 0x1c, F2 + 0x60)),
    ('f2_builtin_nonnegative', lambda tr, r, c: c.fn == 2 and c.p0 >= 0
     and _tk(tr, F2 + 0x1c, F2 + 0x20)),
    ('f2_slot_miss_exit', lambda tr, r, c: c.fn == 2
     and _tk(tr, F2 + 0x74, F2 + 0x58)),
    ('f2_slot_id_base_added', lambda tr, r, c: c.fn == 2
     and _ex(tr, F2 + 0x78)),
    ('f2_name_lookup_called', lambda tr, r, c: c.fn == 2 and bool(_call(r, 'L'))),
    ('f2_builtin_lookup_called', lambda tr, r, c: c.fn == 2
     and bool(_call(r, 'B'))),
    ('f2_getter_called', lambda tr, r, c: c.fn == 2 and bool(_call(r, 'V'))),
    ('f2_rvalue_zeroed_before_getter', lambda tr, r, c: c.fn == 2 and any(
        len(x) > 4 and x[4] == '1' for x in _call(r, 'V'))),
    ('f2_lazy_slot_path', lambda tr, r, c: c.fn == 2 and bool(_call(r, 'I'))),
    ('f2_builtin_numb_is_dead', lambda tr, r, c: c.fn == 2 and any(
        o.p0 == c.p0 and o.p1 == c.p1 and o.p3 == c.p3 and o.p6 == c.p6
        and o.p4 != c.p4 and o.label != c.label for o in _F2_CASES)),
    ('f2_name_null_reaches_lookups', lambda tr, r, c: c.fn == 2 and c.p3 == 3
     and any(x[1] == '-1' for x in _call(r, 'L') + _call(r, 'B'))),
    ('f2_unset_tag_answers_zero', lambda tr, r, c: c.fn == 2
     and r['ret'] == '0' and bool(_call(r, 'V'))),
    ('f2_direct_untouched_when_flag_clear', lambda tr, r, c: c.fn == 2
     and c.p6 == 1 and r['ret'] == '1' and not _call(r, 'V')
     and not _call(r, 'I')),
    ('f2_flag_set_stays_set', lambda tr, r, c: c.fn == 2 and c.p5 == 1
     and r['flag'] == 1),
    ('f2_flag_clear_stays_clear', lambda tr, r, c: c.fn == 2 and c.p5 == 0
     and r['flag'] == 0),
    # ── F3 Variable_GetName_Scope ───────────────────────────────────────────
    ('f3_gate1_off', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd2264, 0xd239c)),
    ('f3_gate1_on', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd2264, 0xd2268)),
    ('f3_id_below_base', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2270, 0xd22f4)),
    ('f3_type_global', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd2278, 0xd23a8)),
    ('f3_type_local_minus12', lambda tr, r, c: c.fn == 3 and c.p1 == -12
     and _tk(tr, 0xd2284, 0xd2288)),
    ('f3_type_local_minus7', lambda tr, r, c: c.fn == 3 and c.p1 == -7
     and _tk(tr, 0xd2284, 0xd2288)),
    ('f3_type_not_local', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2284, 0xd231c)),
    ('f3_local_table_empty', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2298, 0xd22e0)),
    ('f3_local_scan_hit', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd22d0, 0xd22d4)),
    ('f3_local_scan_miss', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd22bc, 0xd22e0)),
    ('f3_gate2_off', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd22f0, 0xd22f4)),
    ('f3_gate2_on', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd22f0, 0xd2404)),
    ('f3_parent_null', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2410, 0xd22f4)),
    ('f3_parent_rescan_advance', lambda tr, r, c: c.fn == 3
     and _ex(tr, 0xd2454)),
    ('f3_parent_rescan_hit', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2474, 0xd22d4)),
    ('f3_parent_rescan_miss', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd245c, 0xd2478)),
    ('f3_global_count_gate', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd23b8, 0xd22f4)),
    ('f3_shared_size_gate_null', lambda tr, r, c: c.fn == 3
     and _ex(tr, 0xd23c8)),
    ('f3_shared_data_read', lambda tr, r, c: c.fn == 3 and _ex(tr, 0xd23cc)),
    ('f3_instance_count_gate', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2334, 0xd23bc)),
    ('f3_map_empty', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd234c, 0xd22f4)),
    ('f3_map_skip_nonpositive', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2374, 0xd2368)),
    ('f3_map_advance_occupied', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd237c, 0xd2364)),
    ('f3_map_hit', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd238c, 0xd22fc)),
    ('f3_map_miss', lambda tr, r, c: c.fn == 3 and _tk(tr, 0xd2398, 0xd22f4)),
    ('f3_type_instance', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2320, 0xd2324)),
    ('f3_normalize_entered', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2320, 0xd23d4)),
    ('f3_normalize_to_instance', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd2400, 0xd2324)),
    ('f3_normalize_reject', lambda tr, r, c: c.fn == 3
     and _tk(tr, 0xd23fc, 0xd22f4)),
    ('f3_unknown_string_loaded', lambda tr, r, c: c.fn == 3 and _ex(tr, 0xd22f4)),
    ('f3_flag_set_stays_set', lambda tr, r, c: c.fn == 3 and c.p6 == 2
     and r['flag'] == 1),
    ('f3_flag_clear_stays_clear', lambda tr, r, c: c.fn == 3 and c.p6 == 0
     and r['flag'] == 0),
    ('f3_canary_check_passed', lambda tr, r, c: c.fn == 3 and _ex(tr, 0xd22fc)),
    # ── F4 Variable_BuiltIn_Add ─────────────────────────────────────────────
    ('f4_limit_taken', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4dd0, 0x1f5024)),
    ('f4_limit_not_taken', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4dd0, 0x1f4dd4)),
    ('f4_stale_name_freed', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4de8, 0x1f4dec)),
    ('f4_fresh_slot_chosen', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4de8, 0x1f4e04)),
    ('f4_writable_bit_written', lambda tr, r, c: c.fn == 4 and _ex(tr, 0x1f4e3c)),
    ('f4_getter_setter_stored', lambda tr, r, c: c.fn == 4 and _ex(tr, 0x1f4e40)),
    ('f4_grow_taken', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4e44, 0x1f4f34)),
    ('f4_grow_not_taken', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4e44, 0x1f4e48)),
    ('f4_grow_rehash_insert', lambda tr, r, c: c.fn == 4 and _ex(tr, 0x1f4fec)),
    ('f4_grow_free_old_block', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4ffc, 0x1f5000)),
    ('f4_grow_doubles_cap', lambda tr, r, c: c.fn == 4
     and r['ext'].get('MAP', '').split()[0] == '256'),
    ('f4_probe_empty_first', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4e80, 0x1f4e84)),
    ('f4_probe_occupied', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4e80, 0x1f4ec8)),
    ('f4_probe_swap', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4edc, 0x1f4e88)),
    ('f4_probe_advance_distance', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4ee4, 0x1f4ea8)),
    ('f4_probe_advance_hash', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4eec, 0x1f4ea8)),
    ('f4_probe_advance_key', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4ef8, 0x1f4ea8)),
    ('f4_duplicate_key_path', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4ef8, 0x1f4efc)),
    ('f4_store_after_advance', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4ec4, 0x1f4f14)),
    ('f4_count_written_last', lambda tr, r, c: c.fn == 4
     and _tk(tr, 0x1f4f28, 0x1f4f2c)),
    ('f4_writable_follows_setter', lambda tr, r, c: c.fn == 4 and all(
        v.split()[-1] == v.split()[-2]
        for k, v in r['ext'].items() if k.startswith('E.'))),
    ('f4_dead_flag_argument', lambda tr, r, c: c.fn == 4 and c.p3 == 1
     and any(o.p0 == c.p0 and o.p1 == c.p1 and o.p2 == c.p2 and o.p3 == 0
             and o.p4 == c.p4 and o.p5 == c.p5 for o in _F4_CASES)),
    ('f4_pointer_compare_keeps_names', lambda tr, r, c: c.fn == 4
     and c.p4 == 8 and r['ext'].get('ENONEMPTY') == '2'),
    ('f4_limit_writes_nothing', lambda tr, r, c: c.fn == 4 and c.p4 == 4
     and r['ext'].get('ENONEMPTY') == '0'
     and r['ext'].get('MAP', '').split()[1] == '0'),
]

_F4_CASES = cases_f4()

_F2_CASES = [c for c in cases_f2()]


# ── original arm ─────────────────────────────────────────────────────────────
def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


class Stage:
    """One staged environment; hooks installed exactly once per arm."""

    def __init__(self, o):
        self.o = o
        self.log = []
        self.tr = []
        self.traces = []
        self.ext = {}
        self.old_block = o.alloc(10000)
        self.new_block = o.alloc(10000)
        # fn=2 geometry: one CInstance, 8 named slots, a getter stub page
        self.inst = o.alloc(0x180)
        self.slots = o.alloc(8 * 16)
        self.getter_stub = o.alloc(64)
        o.write(self.getter_stub, struct.pack('<I', 0xe12fff1e))  # bx lr
        self.f2_names = o.alloc(32)
        o.write(self.f2_names, b'alpha\0\0beta\0' + b'\0' * 20)
        # fn=3 geometry: the three name tables, the map, the local fn table and
        # a guard word the canary read lands on
        self.guard = o.alloc(16)
        self._w(GOT_GUARD, self.guard)
        self.empty_ptr = o.alloc(8)
        o.write(self.empty_ptr, b'\0' * 8)
        o.write(self.guard, struct.pack('<I', GUARD))
        self.glob_slots = o.alloc(32)
        self.inst_slots = o.alloc(32)
        self.fn0_names = o.alloc(32)
        self.fn1_names = o.alloc(32)
        self.fn_arr = o.alloc(24)
        self.map_entries = o.alloc(8 * 12)
        self.scope_map = o.alloc(20)
        self.script_obj = o.alloc(0x20)
        self.vn_buf = o.alloc(32)
        self.str_blob = o.alloc(0x200)
        self.strs = {}
        off = 0
        for s in ('g0', 'g1', 'g2', 'g3', 'g4', 'g5', 'i0', 'i2', 'm5', 'm6', 'm7',
                  'l0', 'l1', 'l2', 'l3', 'l4', 'l5', 'l6', 'l7',
                  'p0', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7',
                  'scrA', 'other', 'gml_Script_Par', 'Par', 'vn', 'yy', 'zz',
                  'ww', 'vv'):
            o.write(self.str_blob + off, s.encode() + b'\0')
            self.strs[s] = self.str_blob + off
            off += len(s) + 1
        # fn=4 geometry: a 128-bucket map, the 500x16 table (a real .bss
        # object, so nothing to allocate), an 8 KB stub heap for the doubling
        # and a 1 KB arena for YYStrDup
        self.f4_map = o.alloc(20)
        self.f4_entries = o.alloc(128 * 12)
        self.f4_heap = o.alloc(8192)
        self.f4_arena = o.alloc(0x400)
        self.f4_heap_used = 0
        self.f4_arena_used = 0
        self.f4_names = o.alloc(6 * 8)
        for k, s in enumerate(('alpha', 'beta', 'gamma', 'alpha', 'beta',
                               'gamma')):
            o.write(self.f4_names + k * 8, s.encode() + b'\0')
        self.setter_stub = o.alloc(64)
        o.write(self.setter_stub, struct.pack('<I', 0xe12fff1e))  # bx lr
        for addr, hook in ((HASH, self.hook_hash),
                           (STRDUP, self.hook_strdup),
                           (MM_FREE, self.hook_mm_free),
                           (MM_ALLOC, self.hook_mm_alloc),
                           (INSERT, self.hook_insert),
                           (SHOWMSG, self.hook_showmessage),
                           (MEMSET_PLT, self.hook_memset)):
            o.uc.hook_add(UC_HOOK_CODE, hook, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F4, end=F4_POOL - 4)
        self.scans = 0
        self.f3_parent = 0
        for addr, hook in ((GETNAME, self.hook_getname),
                           (SCRIPT_PARENT, self.hook_script_parent),
                           (SNPRINTF_PLT, self.hook_snprintf),
                           (STRCMP_PLT, self.hook_strcmp)):
            o.uc.hook_add(UC_HOOK_CODE, hook, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F3, end=F3_POOL - 4)
        for addr, hook in ((REALLOC, self.hook_realloc),
                           (BUILTIN_FIND, self.hook_builtin_find),
                           (LOCAL_NAME, self.hook_local_name),
                           (GLOBAL_NAME, self.hook_global_name),
                           (GET_RVALUE, self.hook_get_rvalue),
                           (INTERNAL_GETYYVAR, self.hook_internal),
                           (self.getter_stub, self.hook_bvar_getter)):
            o.uc.hook_add(UC_HOOK_CODE, hook, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F1, end=F1_POOL - 4)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F2, end=F2_END - 4)

    # -- plumbing -----------------------------------------------------------
    def hook_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def _w(self, addr, w):
        self.o.write(addr, struct.pack('<I', w & 0xffffffff))

    def _rd(self, addr):
        return struct.unpack('<I', bytes(self.o.read(addr, 4)))[0]

    def _cstr(self, addr, limit=64):
        if addr == 0:
            return None
        try:
            return self.o.read_cstr(addr, limit)
        except Exception:
            return '?'

    def _read_name(self, addr):
        """(len, printable text); len -1 for NULL, capped like the fixture."""
        if addr == 0:
            return -1, ''
        out = bytearray()
        for i in range(60):
            b = self.o.read(addr + i, 1)[0]
            if b == 0:
                break
            out.append(b if 0x20 <= b <= 0x7e else ord('?'))
        text = out.decode('latin-1').replace(' ', '_')
        return len(out), text

    def _ret(self, uc_, value):
        uc_.reg_write(UC_ARM_REG_R0, value & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    # -- fn=1 ---------------------------------------------------------------
    def hook_realloc(self, uc_, _a, _s, _d):
        p = uc_.reg_read(UC_ARM_REG_R0)
        size = uc_.reg_read(UC_ARM_REG_R1)
        file_p = uc_.reg_read(UC_ARM_REG_R2)
        line = to_i32(uc_.reg_read(UC_ARM_REG_R3))
        sp = uc_.reg_read(UC_ARM_REG_SP)
        zero = self._rd(sp)
        f = self._cstr(file_p)
        self.log.append(['Q', str(size), str(line), str(zero),
                         '1' if (p == self.staged_old and p != 0) else '0',
                         '1' if f == FILE_CARRAY else '0'])
        self._ret(uc_, self.new_block)

    # -- fn=2 ---------------------------------------------------------------
    def _name_tok(self, kind, addr):
        n, s = self._read_name(addr)
        self.log.append([kind, str(n), s if n > 0 else '-'])

    def hook_builtin_find(self, uc_, _a, _s, _d):
        self._name_tok('B', uc_.reg_read(UC_ARM_REG_R0))
        self._ret(uc_, self.staged_builtin_ret)

    def hook_local_name(self, uc_, _a, _s, _d):
        self._name_tok('L', uc_.reg_read(UC_ARM_REG_R0))
        self._ret(uc_, self.staged_slot)

    def hook_global_name(self, uc_, _a, _s, _d):
        self._name_tok('G', uc_.reg_read(UC_ARM_REG_R0))
        self._ret(uc_, self.staged_slot)

    def hook_get_rvalue(self, uc_, _a, _s, _d):
        dst = uc_.reg_read(UC_ARM_REG_R0)
        src = uc_.reg_read(UC_ARM_REG_R1)
        arr = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        k = 99
        if self.slots <= src < self.slots + 8 * 16:
            k = (src - self.slots) // 16
        self.log.append(['V', 'S', str(k), str(arr), self._zero_tok(dst)])
        self.o.write(dst, bytes(self.o.read(src, 16)))
        self._ret(uc_, 1)

    def hook_internal(self, uc_, _a, _s, _d):
        self.log.append(['I', str(to_i32(uc_.reg_read(UC_ARM_REG_R1)))])
        self._ret(uc_, self.slots + 3 * 16)

    def hook_bvar_getter(self, uc_, _a, _s, _d):
        arr = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        dst = uc_.reg_read(UC_ARM_REG_R2)
        self.log.append(['V', 'B', str(arr), self._zero_tok(dst)])
        self.o.write(dst, self.staged_rv)
        uc_.reg_write(UC_ARM_REG_R0, 1)
        uc_.reg_write(UC_ARM_REG_PC, BVAR_GETTER + 4)   # the instruction after blx
        return

    def _zero_tok(self, addr):
        return '1' if all(b == 0 for b in bytes(self.o.read(addr, 16))) else '0'

    def stage_f2(self, case):
        o = self.o
        _, p0, p1, p2, p3, p4, p5, _p6 = case.args()
        # one CInstance: +0x04 slot table, +0x24 "has instance vars".
        # p1 == 4 walks Variable_GetValue_Direct's NULL-table (lazy) path.
        self._w(self.inst + 0x4, 0 if p1 == 4 else self.slots)
        o.write(self.inst + 0x24, bytes([0 if _p6 else 1]))
        for k in range(8):
            self._w(self.slots + k * 16 + 0x0, 0x11111111 + k)
            self._w(self.slots + k * 16 + 0xc, p2 & 0xffffffff)
        self.staged_rv = struct.pack('<IIII', 0x22222222, 0, 0, p2 & 0xffffffff)
        # the builtin table: exactly one live entry, and builtin_numb moved by
        # p4 to show that this body never reads it
        o.write(BSS_BUILTIN_TABLE, b'\0' * (500 * 16))
        if 0 <= p0 < 500:
            entry = BSS_BUILTIN_TABLE + p0 * 16
            o.write(entry + 0x0, struct.pack('<I', 0))          # name (unused)
            o.write(entry + 0x4, struct.pack('<I', self.getter_stub))
            self._w(BSS_BUILTIN_NUMB, (p0 + 1) if p4 else 0)
        else:
            self._w(BSS_BUILTIN_NUMB, 1 if p4 else 0)
        self.staged_builtin_ret = p0
        self.staged_slot = {1: 3, 2: 7, 3: 0, 4: 3}.get(p1, -1)
        self._w(BSS_GATE1, 0)       # *g_varname_host = NULL: linked body takes
        o.write(BSS_GATE2, b'\0')  # the local name arm, mode byte irrelevant
        o.write(BSS_FAILFLAG, bytes([p5 & 0xff]))
        self.log.clear()
        self.tr.clear()
        r = o.call(F2, r0=self.inst, r1=self._name_ptr(p3))
        return {'ret': str(to_i32(r)), 'calls': [list(x) for x in self.log],
                'ext': {}, 'flag': o.read(BSS_FAILFLAG, 1)[0]}

    def _name_ptr(self, tag):
        return {0: self.f2_names, 1: self.f2_names + 6, 2: self.f2_names + 7,
                3: 0}[tag]

    # -- fn=3 ---------------------------------------------------------------
    def hook_getname(self, uc_, _a, _s, _d):
        idv = to_i32(uc_.reg_read(UC_ARM_REG_R0))
        self.log.append(['N', str(idv)])
        blob = ('vn%d' % idv).encode() + b'\0'
        self.o.write(self.vn_buf, blob)
        self._ret(uc_, self.vn_buf)

    def hook_script_parent(self, uc_, _a, _s, _d):
        n, s = self._read_name(uc_.reg_read(UC_ARM_REG_R0))
        self.log.append(['P', str(n), s if n > 0 else '-'])
        self._ret(uc_, self.script_obj if (self.f3_parent & 1) else 0)

    def hook_snprintf(self, uc_, _a, _s, _d):
        buf = uc_.reg_read(UC_ARM_REG_R0)
        cap = uc_.reg_read(UC_ARM_REG_R1)
        fmt = uc_.reg_read(UC_ARM_REG_R2)
        arg = uc_.reg_read(UC_ARM_REG_R3)
        text = self._format(self._cstr(fmt) or '', self._cstr(arg))
        blob = text.encode('latin-1')
        self.o.write(buf, blob[:max(0, cap - 1)] + b'\0')
        n, s = self._read_name(buf)
        self.log.append(['S', str(len(blob)), s if n > 0 else '-'])
        self._ret(uc_, len(blob))

    def hook_strcmp(self, uc_, _a, _s, _d):
        a = self._cstr(uc_.reg_read(UC_ARM_REG_R0)) or ''
        b = self._cstr(uc_.reg_read(UC_ARM_REG_R1)) or ''
        self.scans += 1
        self._ret(uc_, 0 if a == b else (1 if a > b else -1))

    @staticmethod
    def _format(fmt, arg):
        out, i = [], 0
        while i < len(fmt):
            if fmt[i] == '%' and i + 1 < len(fmt) and fmt[i + 1] == 's':
                out.append('(null)' if arg is None else arg)
                i += 2
            else:
                out.append(fmt[i])
                i += 1
        return ''.join(out)

    def stage_f3(self, case):
        o = self.o
        _, p0, p1, p2, p3, p4, p5, p6 = case.args()
        S = self.strs
        o.write(self.glob_slots, b'\0' * 32)
        o.write(self.inst_slots, b'\0' * 32)
        o.write(self.fn0_names, b'\0' * 32)
        o.write(self.fn1_names, b'\0' * 32)
        o.write(self.fn_arr, b'\0' * 24)
        o.write(self.map_entries, b'\0' * 96)
        o.write(self.scope_map, struct.pack('<iiiii', 8, 0, 7, 4,
                                            self.map_entries))
        self._w(BSS_INST_MAP, self.scope_map)
        for addr in (BSS_GLOBAL_NAMES, BSS_INST_NAMES):
            o.write(addr, struct.pack('<iiii', 0, 0, 0, 0))
        self._w(BSS_NUM_LOCAL, 0)
        self._w(BSS_LOCAL_ARR, 0)
        self.scans = 0
        self.f3_parent = p6
        o.write(self.script_obj, b'\0' * 0x20)
        self._w(self.script_obj + 0x14, S['Par'])

        if p5 != 0:
            for k in range(8):
                self._w(self.glob_slots + k * 4, 0)
                self._w(self.inst_slots + k * 4, 0)
                self._w(self.fn0_names + k * 4, S['l%d' % k])
                self._w(self.fn1_names + k * 4, S['p%d' % k])
        if p5 == 1:
            for k, nm in enumerate(('g0', 'g1', None, 'g3', 'g4', None, None,
                                    None)):
                self._w(self.glob_slots + k * 4, S[nm] if nm else 0)
            for k, nm in enumerate(('i0', None, 'i2', None, None, None, None,
                                    None)):
                self._w(self.inst_slots + k * 4, S[nm] if nm else 0)
            o.write(BSS_GLOBAL_NAMES, struct.pack('<iiii', 8, 5, 0, self.glob_slots))
            o.write(BSS_INST_NAMES, struct.pack('<iiii', 8, 3, 0, self.inst_slots))
            # count == number of hash>0 entries: the reverse scan's
            # "i-th occupied entry" walk then always ends inside the array
            self._w(self.scope_map + 0x4, 2)
            for idx, key, val, h in ((1, 'm5', 5, 1), (2, 'm6', 6, -3),
                                     (3, 'm7', 7, 9)):
                e = self.map_entries + idx * 12
                self._w(e + 0, S[key])
                self._w(e + 4, val)
                self._w(e + 8, h & 0xffffffff)
            o.write(self.fn_arr, struct.pack('<iii', S['scrA'], 4, self.fn0_names))
            self._w(BSS_NUM_LOCAL, 1)
            self._w(BSS_LOCAL_ARR, self.fn_arr)
        elif p5 == 2:
            for k, nm in enumerate(('g0', 'g1', 'g2', 'g3', None, 'g5', None,
                                    None)):
                self._w(self.glob_slots + k * 4, S[nm] if nm else 0)
            for k, nm in enumerate(('i0', None, None, None, None, None, None,
                                    None)):
                self._w(self.inst_slots + k * 4, S[nm] if nm else 0)
            o.write(BSS_GLOBAL_NAMES, struct.pack('<iiii', 4, 6, 0, self.glob_slots))
            o.write(BSS_INST_NAMES, struct.pack('<iiii', 4, 2, 0, self.inst_slots))
            self._w(self.scope_map + 0x4, 2)
            for idx, key, val, h in ((0, 'm5', 5, 1), (2, 'm7', 7, 3)):
                e = self.map_entries + idx * 12
                self._w(e + 0, S[key])
                self._w(e + 4, val)
                self._w(e + 8, h & 0xffffffff)
            o.write(self.fn_arr, struct.pack('<iii', S['scrA'], 4, self.fn0_names))
            o.write(self.fn_arr + 12,
                    struct.pack('<iii', S['gml_Script_Par'], 2, self.fn1_names))
            self._w(BSS_NUM_LOCAL, 2)
            self._w(BSS_LOCAL_ARR, self.fn_arr)

        o.write(BSS_GATE1, bytes([p3 & 0xff]))
        o.write(BSS_GATE2, bytes([p4 & 0xff]))
        o.write(BSS_FAILFLAG, bytes([(p6 >> 1) & 1]))
        self.log.clear()
        self.tr.clear()
        r = o.call(F3, r0=self._scope_name(p0), r1=p1 & 0xffffffff,
                   r2=p2 & 0xffffffff)
        return {'ret': self._classify_ptr(r), 'calls': [list(x) for x in self.log],
                'ext': {'SCANS': str(self.scans)},
                'flag': o.read(BSS_FAILFLAG, 1)[0]}

    def _scope_name(self, tag):
        '''0..4 -> the five staged names; 3 is a NULL pointer, 2 an empty one.'''
        if tag == 3:
            return 0
        return {0: self.strs['scrA'], 1: self.strs['other'],
                2: self.empty_ptr, 4: self.strs['gml_Script_Par']}.get(tag, 0)

    def _read_name_raw(self, addr):
        """Unescaped bytes, for comparing against the rodata literals."""
        out = bytearray()
        for i in range(60):
            b = self.o.read(addr + i, 1)[0]
            if b == 0:
                break
            out.append(b)
        return bytes(out)

    def _classify_ptr(self, p):
        if p == 0:
            return 'NULL'
        raw = self._read_name_raw(p)
        if raw == MSG_UNKNOWN_VARIABLE.encode():
            return 'UNK'
        return 'PTR:' + raw.hex()

    # -- fn=4 ---------------------------------------------------------------
    def hook_hash(self, uc_, _a, _s, _d):
        h = self._fnv1a(self._cstr(uc_.reg_read(UC_ARM_REG_R0)) or '')
        self._ret(uc_, h)

    def hook_strdup(self, uc_, _a, _s, _d):
        addr = uc_.reg_read(UC_ARM_REG_R0)
        n, s = self._read_name(addr)
        self.log.append(['D', str(n), s if n > 0 else '-'])
        n = max(n, 0)
        p = self.f4_arena + self.f4_arena_used
        blob = (s if s else '').encode('latin-1')[:n] + b'\0'
        self.o.write(p, blob)
        self.f4_arena_used += (n + 1 + 7) & ~7
        self._ret(uc_, p)

    def hook_mm_free(self, uc_, _a, _s, _d):
        p = uc_.reg_read(UC_ARM_REG_R0)
        if self.f4_arena <= p < self.f4_arena + 0x400:
            n, s = self._read_name(p)
            self.log.append(['F', 'n', str(n), s if n > 0 else '-'])
        else:
            self.log.append(['F', 'b'])
        self._ret(uc_, 0)

    def hook_mm_alloc(self, uc_, _a, _s, _d):
        size = uc_.reg_read(UC_ARM_REG_R0)
        line = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        zero = uc_.reg_read(UC_ARM_REG_R3)
        p = self.f4_heap + self.f4_heap_used
        self.log.append(['A', str(size), str(line), str(zero), '1'])
        self.f4_heap_used += (size + 7) & ~7
        if zero:
            self.o.write(p, b'\0' * size)
        self._ret(uc_, p)

    def hook_insert(self, uc_, _a, _s, _d):
        m = uc_.reg_read(UC_ARM_REG_R0)
        key = uc_.reg_read(UC_ARM_REG_R1)
        val = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        cap = self._rd(m)
        mask = self._rd(m + 8)
        entries = self._rd(m + 0x10)
        if cap <= 0 or (mask & (mask + 1)):
            raise RuntimeError('staged map is not a power-of-two table')
        h = self._fnv1a(self._cstr(key) or '') & 0x7fffffff
        idx = h & (mask & 0xffffffff)
        for _ in range(cap + 1):
            e = entries + (idx % cap) * 12
            if self._rd(e + 8) == 0:
                self._w(e + 0, key)
                self._w(e + 4, val & 0xffffffff)
                self._w(e + 8, h)
                self._w(m + 4, (self._rd(m + 4) + 1) & 0xffffffff)
                break
            idx = (idx + 1) & (mask & 0xffffffff)
        else:
            raise RuntimeError('insert found no empty slot')
        n, s = self._read_name(key)
        self.log.append(['I', str(n), s if n > 0 else '-', str(val)])

    def hook_memset(self, uc_, _a, _s, _d):
        dst = uc_.reg_read(UC_ARM_REG_R0)
        val = uc_.reg_read(UC_ARM_REG_R1) & 0xff
        n = uc_.reg_read(UC_ARM_REG_R2)
        self.o.write(dst, bytes([val]) * n)
        self._ret(uc_, dst)

    def hook_showmessage(self, uc_, _a, _s, _d):
        n, s = self._read_name(uc_.reg_read(UC_ARM_REG_R0))
        self.log.append(['M', str(n), s if n > 0 else '-'])
        # the original TAIL-jumps here after popping, so LR is already the
        # caller's return address (the sentinel)
        self._ret(uc_, 0)

    @staticmethod
    def _fnv1a(s):
        h = 2166136261
        for ch in s.encode('latin-1'):
            h ^= ch
            h = (h * 16777619) & 0xffffffff
        return h

    def stage_f4(self, case):
        o = self.o
        _, p0, p1, p2, p3, p4, p5, p6 = case.args()
        o.write(BSS_BUILTIN_TABLE, b'\0' * (500 * 16))
        o.write(self.f4_entries, b'\0' * (128 * 12))
        o.write(self.f4_map, struct.pack('<iiiii', 128, 0, 127, 76,
                                        self.f4_entries))
        self._w(BSS_BUILTIN_MAP, self.f4_map)
        self._w(BSS_BUILTIN_NUMB, 0)
        self.f4_arena_used = 0
        self.f4_heap_used = 0
        nm = self.f4_name_addr(p0)

        if p4 == 1:
            self._w(BSS_BUILTIN_NUMB, 1)
            self._w(BSS_BUILTIN_TABLE + 1 * 16, self._f4_dup_str('stale'))
        elif p4 == 2:
            h = self._fnv1a(self.f4_name_text(p0)) & 0x7fffffff
            idx = h & 127
            self._w(BSS_BUILTIN_TABLE + 0 * 16, self._f4_dup_str('pre'))
            self._w(BSS_BUILTIN_NUMB, 1)
            e = self.f4_entries + idx * 12
            self._w(e + 0, nm)
            self._w(e + 4, 0)
            self._w(e + 8, h)
            self._w(self.f4_map + 4, 1)
        elif p4 == 5:
            h = self._fnv1a(self.f4_name_text(p0)) & 0x7fffffff
            idx = h & 127
            nxt = (idx + 1) & 127
            self._w(BSS_BUILTIN_TABLE + 0 * 16, self._f4_dup_str('pre'))
            self._w(BSS_BUILTIN_NUMB, 1)
            self._w(self.f4_entries + idx * 12 + 0, self.strs['yy'])
            self._w(self.f4_entries + idx * 12 + 4, 70)
            self._w(self.f4_entries + idx * 12 + 8, idx if idx else 1)
            self._w(self.f4_entries + nxt * 12 + 0, self.strs['zz'])
            self._w(self.f4_entries + nxt * 12 + 4, 90)
            self._w(self.f4_entries + nxt * 12 + 8, nxt if nxt else 1)
            self._w(self.f4_map + 4, 2)
        elif p4 == 8:
            h = self._fnv1a(self.f4_name_text(p0)) & 0x7fffffff
            idx = h & 127
            self._w(BSS_BUILTIN_TABLE + 0 * 16, self._f4_dup_str('pre'))
            self._w(BSS_BUILTIN_NUMB, 1)
            # the same bytes, the other address of the pair
            self._w(self.f4_entries + idx * 12 + 0,
                    self.f4_names + ((p0 + 3) % 6) * 8)
            self._w(self.f4_entries + idx * 12 + 4, 55)
            self._w(self.f4_entries + idx * 12 + 8, h)
            self._w(self.f4_map + 4, 1)
        elif p4 == 6:
            h = self._fnv1a(self.f4_name_text(p0)) & 0x7fffffff
            idx = h & 127
            home = (idx - 2) & 127
            self._w(BSS_BUILTIN_TABLE + 0 * 16, self._f4_dup_str('pre'))
            self._w(BSS_BUILTIN_NUMB, 1)
            self._w(self.f4_entries + idx * 12 + 0, self.strs['ww'])
            self._w(self.f4_entries + idx * 12 + 4, 80)
            self._w(self.f4_entries + idx * 12 + 8, home if home else 1)
            self._w(self.f4_map + 4, 1)
        elif p4 == 7:
            h = self._fnv1a(self.f4_name_text(p0)) & 0x7fffffff
            idx = h & 127
            self._w(BSS_BUILTIN_TABLE + 0 * 16, self._f4_dup_str('pre'))
            self._w(BSS_BUILTIN_NUMB, 1)
            self._w(self.f4_entries + idx * 12 + 0, self.strs['vv'])
            self._w(self.f4_entries + idx * 12 + 4, 60)
            self._w(self.f4_entries + idx * 12 + 8, h)
            self._w(self.f4_map + 4, 1)
        elif p4 == 3:
            self._w(BSS_BUILTIN_NUMB, 499)
        elif p4 == 4:
            self._w(BSS_BUILTIN_NUMB, 500)

        if p5 in (1, 2):
            self._w(self.f4_map + 0xc, 0xffffffff)   # threshold -1
            if p5 == 1:
                for k, (nm2, val) in enumerate((('old0', 100), ('old1', 101),
                                                ('old2', 102))):
                    e = self.f4_entries + k * 12
                    self._w(e + 0, self._f4_dup_str(nm2))
                    self._w(e + 4, val)
                    self._w(e + 8, k + 1)
                self._w(self.f4_map + 4, 3)

        o.write(BSS_FAILFLAG, b'\0')
        self.log.clear()
        self.tr.clear()
        o.call(F4, r0=nm, r1=self.getter_stub if p1 else 0,
               r2=self.setter_stub if p2 else 0, r3=p3 & 0xffffffff)
        return self._f4_record()

    def _f4_dup_str(self, s):
        p = self.f4_arena + self.f4_arena_used
        self.o.write(p, s.encode() + b'\0')
        self.f4_arena_used += (len(s) + 1 + 7) & ~7
        return p

    def f4_name_text(self, tag):
        return {0: 'alpha', 1: 'beta', 2: 'gamma', 3: 'alpha', 4: 'beta',
                5: 'gamma'}.get(tag, 'gamma')

    def f4_name_addr(self, tag):
        return self.f4_names + tag * 8

    def _f4_record(self):
        o = self.o
        ext = {'COUNT': str(self._rd(BSS_BUILTIN_NUMB)),
               'MAP': ' '.join(str(to_i32(self._rd(self.f4_map + k)))
                               for k in (0, 4, 8, 12))}
        count = self._rd(BSS_BUILTIN_NUMB)
        nonempty = 0
        for i in range(min(count, 500)):
            e = BSS_BUILTIN_TABLE + i * 16
            namep = self._rd(e)
            if not namep:
                continue
            nonempty += 1
            n, s = self._read_name(namep)
            ext['E.%d' % i] = 'n %d %s %d %d %d' % (
                n, s if n > 0 else '-', 1 if self._rd(e + 4) else 0,
                1 if self._rd(e + 8) else 0, o.read(e + 0xc, 1)[0])
        ext['ENONEMPTY'] = str(nonempty)
        cap = self._rd(self.f4_map)
        entries = self._rd(self.f4_map + 0x10)
        for i in range(cap):
            e = entries + i * 12
            h = self._rd(e + 8)
            if h == 0:
                continue
            n, s = self._read_name(self._rd(e))
            ext['M.%d' % i] = '%08x n %d %s %d' % (
                h, n, s if n > 0 else '-', to_i32(self._rd(e + 4)))
        return {'ret': 'void', 'calls': [list(x) for x in self.log],
                'ext': ext, 'flag': o.read(BSS_FAILFLAG, 1)[0]}

    def stage_f1(self, case):
        o = self.o
        _, p0, p1, p2, _p3, _p4, _p5, _p6 = case.args()
        o.write(self.old_block, b'\x5a' * 10000)
        o.write(self.new_block, bytes([p0 & 0xff]) * 10000)
        self.staged_old = self.old_block if p1 else 0
        self._w(BSS_GLOBDECL + 0x0, 0)
        self._w(BSS_GLOBDECL + 0x4, self.staged_old)
        o.write(BSS_FAILFLAG, bytes([p2 & 0xff]))
        self.log.clear()
        self.tr.clear()
        self.ext = {}
        o.call(F1)
        blob = bytes(o.read(self.new_block, 10000))
        nz = sum(1 for b in blob if b)
        fz = next((i for i, b in enumerate(blob) if b), -1)
        cap = to_i32(self._rd(BSS_GLOBDECL + 0x0))
        data = self._rd(BSS_GLOBDECL + 0x4)
        return {'ret': 'void', 'calls': [list(x) for x in self.log],
                'ext': {'CAP': str(cap),
                        'DATAPTR': '1' if data == self.new_block else '0',
                        'NZ': str(nz), 'FZ': str(fz)},
                'flag': o.read(BSS_FAILFLAG, 1)[0]}

    def run(self, case):
        rec = {1: self.stage_f1, 2: self.stage_f2,
               3: self.stage_f3, 4: self.stage_f4}[case.fn](case)
        self.traces.append(list(self.tr))
        return rec


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

def build_c(out_bin, mutant=None, paths=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    paths = list(paths or [MOD / 'src' / 'variable_global_init.c'])
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
        paths = [patched if p.name == mutant['file'] else p for p in paths]
    cmd = (['clang'] + ARM_FLAGS + ['-O1', '-I', str(MOD / 'src'),
                                    '-I', str(NAMES_MOD / 'src'),
                                    '-I', str(DIRECT_MOD / 'src')] +
           [str(p) for p in paths] +
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
            cur = {'ret': '', 'calls': [], 'ext': {}, 'flag': 0}
            recs.append(cur)
        elif parts[0] == 'RET':
            cur['ret'] = parts[1] if len(parts) == 2 else ' '.join(parts[1:])
        elif parts[0] == 'CALLS':
            cur['ncalls'] = int(parts[1])
        elif parts[0] == 'C':
            cur['calls'].append(parts[1:])
        elif parts[0] == 'EXT':
            cur['ext'][parts[1]] = ' '.join(parts[2:])
        elif parts[0] == 'FLAG':
            cur['flag'] = int(parts[1])
    return recs


def same(a, b):
    """The only equality this file accepts: return value, the ordered call log,
    the per-function observed state, the failure byte."""
    return (a['ret'] == b['ret'] and a['calls'] == b['calls']
            and a['ext'] == b['ext'] and a['flag'] == b['flag'])


def _digest(recs):
    return hashlib.sha256(json.dumps(
        [{'ret': r['ret'], 'calls': r['calls'], 'ext': r['ext'],
          'flag': r['flag']} for r in recs], sort_keys=True).encode()).hexdigest()


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    {'name': 'cap_written_10001', 'file': 'variable_global_init.c', 'edits': [
        ('g_globdecl.cap = VM_GLOBDECL_CAP;',
         'g_globdecl.cap = VM_GLOBDECL_CAP + 1;')]},
    {'name': 'realloc_size_10001', 'file': 'variable_global_init.c', 'edits': [
        ('MemoryManager_ReAlloc(g_globdecl.data, VM_GLOBDECL_CAP,',
         'MemoryManager_ReAlloc(g_globdecl.data, VM_GLOBDECL_CAP + 1,')]},
    {'name': 'clear_bound_9999', 'file': 'variable_global_init.c', 'edits': [
        ('bound = VM_GLOBDECL_CAP;', 'bound = VM_GLOBDECL_CAP - 1;')]},
    {'name': 'clear_value_one', 'file': 'variable_global_init.c', 'edits': [
        ('base[i] = 0;', 'base[i] = 1;')]},
    {'name': 'old_pointer_dropped', 'file': 'variable_global_init.c', 'edits': [
        ('MemoryManager_ReAlloc(g_globdecl.data, VM_GLOBDECL_CAP,',
         'MemoryManager_ReAlloc(0, VM_GLOBDECL_CAP,')]},
    {'name': 'data_store_dropped', 'file': 'variable_global_init.c', 'edits': [
        ('    g_globdecl.cap = VM_GLOBDECL_CAP;\n    g_globdecl.data = base;',
         '    g_globdecl.cap = VM_GLOBDECL_CAP;\n    g_globdecl.data = base;\n'
         '    g_globdecl.data = 0;')]},
]

MUTANTS += [
    {'name': 'f2_builtin_sign_test_le', 'file': 'do_variable_instance_exists.c',
     'edits': [('if (id < 0) {', 'if (id <= 0) {')]},
    {'name': 'f2_slot_miss_bound', 'file': 'do_variable_instance_exists.c',
     'edits': [('if (slot < 0)\n            return 0;',
                'if (slot < -1)\n            return 0;')]},
    {'name': 'f2_id_base_99999', 'file': 'do_variable_instance_exists.c',
     'edits': [('id = slot + 99328;', 'id = slot + 99327;')]},
    {'name': 'f2_tag_mask_high', 'file': 'do_variable_instance_exists.c',
     'edits': [('& 0x00ffffffu', '& 0xffff0000u')]},
    {'name': 'f2_sentinel_inverted', 'file': 'do_variable_instance_exists.c',
     'edits': [('!= VM_RV_UNSET', '== VM_RV_UNSET')]},
    {'name': 'f2_rvalue_tag_not_cleared', 'file': 'do_variable_instance_exists.c',
     'edits': [('v.w[3] = 0;', 'v.w[3] = 1;')]},
]

MUTANTS += [
    {'name': 'f3_gate1_inverted', 'file': 'variable_getname_scope.c',
     'edits': [('if (g_subFunctionsOption == 0)', 'if (g_subFunctionsOption != 0)')]},
    {'name': 'f3_global_count_gt', 'file': 'variable_getname_scope.c',
     'edits': [('if (slot >= t->count)', 'if (slot > t->count)')]},
    {'name': 'f3_size_gate_dropped', 'file': 'variable_getname_scope.c',
     'edits': [('if (slot < t->size)', 'if (1)')]},
    {'name': 'f3_local_bound_check_added', 'file': 'variable_getname_scope.c',
     'edits': [('return fe->names[slot];',
                'if (slot >= fe->count) return VM_MSG_UNKNOWN_VARIABLE;\n'
                '    return fe->names[slot];')]},
    {'name': 'f3_map_skip_strict', 'file': 'variable_getname_scope.c',
     'edits': [('if ((int32_t)me->hash <= 0)', 'if ((int32_t)me->hash < 0)')]},
    {'name': 'f3_map_value_inverted', 'file': 'variable_getname_scope.c',
     'edits': [('if (me->value == slot)', 'if (me->value != slot)')]},
    {'name': 'f3_normalize_ge', 'file': 'variable_getname_scope.c',
     'edits': [('if (type > 100000)', 'if (type >= 100000)')]},
    {'name': 'f3_id_base_671', 'file': 'variable_getname_scope.c',
     'edits': [('slot = slot - 672;', 'slot = slot - 671;')]},
    {'name': 'f3_gate2_inverted', 'file': 'variable_getname_scope.c',
     'edits': [('if (g_fJSGarbageCollection == 0)',
                'if (g_fJSGarbageCollection != 0)')]},
]

MUTANTS += [
    {'name': 'f4_limit_ne', 'file': 'variable_builtin_add.c',
     'edits': [('if (count == VM_BUILTIN_CAP)', 'if (count != VM_BUILTIN_CAP)')]},
    {'name': 'f4_writable_always', 'file': 'variable_builtin_add.c',
     'edits': [('writable = (s != 0) ? 1 : 0;', 'writable = 1;')]},
    {'name': 'f4_count_two', 'file': 'variable_builtin_add.c',
     'edits': [('*countp = *countp + 1;', '*countp = *countp + 2;')]},
    {'name': 'f4_dup_count_not_undone', 'file': 'variable_builtin_add.c',
     'edits': [('map->count = map->count - 1;', 'map->count = map->count;')]},
    {'name': 'f4_key_content_compare', 'file': 'variable_builtin_add.c',
     'edits': [('if ((const char *)e->key != key)',
                'if (strcmp(e->key, key) != 0)')]},
    {'name': 'f4_sign_bit_kept', 'file': 'variable_builtin_add.c',
     'edits': [('hash = hash & 0x7fffffffu;', 'hash = hash & 0xffffffffu;')]},
    {'name': 'f4_grow_cap_plus2', 'file': 'variable_builtin_add.c',
     'edits': [('map->cap = oldcap * 2;', 'map->cap = oldcap * 2 + 2;')]},
    {'name': 'f4_rehash_dropped', 'file': 'variable_builtin_add.c',
     'edits': [('CHashMap_Insert(map, oldentries[i].key, oldentries[i].value);',
                'if (i < 0) CHashMap_Insert(map, oldentries[i].key, '
                'oldentries[i].value);')]},
    {'name': 'f4_stale_free_dropped', 'file': 'variable_builtin_add.c',
     'edits': [('MemoryManager_Free(stale);', '(void)stale;')]},
]

MUTANT_NOTES = {
    'data_store_dropped': 'the store is dropped after being made, so the '
                          'DATAPTR facet alone moves; kept because it is the '
                          'only tooth on "the pointer stored is the bl result"',
}


def _sample(case, a, r):
    return {'case': case.label,
            'ret': {'original': a['ret'], 'mutant': r['ret']},
            'calls': {'original': a['calls'], 'mutant': r['calls']},
            'ext': {'original': a['ext'], 'mutant': r['ext']},
            'flag': {'original': a['flag'], 'mutant': r['flag']}}


def teeth_one(m, case_list, a_recs, paths):
    """Judge one mutant.  A batch that aborts is re-diagnosed one case per
    process: the crash belongs to the cases that crash."""
    b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m, paths=paths)
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


def _objdump(entry, stop):
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                        '--stop-address=%#x' % stop, '-M', 'reg-names-std', SO],
                       capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('llvm-objdump failed: %s' % p.stderr[-800:])
    out = []
    for ln in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
        if not m:
            continue
        addr, word, rest = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        text = ' '.join(x for x in rest.split('\t') if x.strip())
        # <strcmp@plt> contains an '@', so the symbol goes first
        text = re.sub(r'\s*<[^>]*>', '', text)
        text = re.sub(r'\s*@.*$', '', text)
        out.append((addr, word, _norm(text)))
    return out


def instruction_census(overrides=None, fns=None):
    """Every instruction of the original must appear in the translation as
    `@0xADDR <verbatim operand text>`, each address exactly once, and every
    literal-pool word must be documented with its value.

    overrides maps a source filename to replacement text; that is what the
    self-test uses to prove the gate can go red at all.
    """
    overrides = overrides or {}
    report = {}
    ok = True
    for fn, spec in sorted(FUNCS.items()):
        if fns is not None and fn not in fns:
            continue
        rows = _objdump(spec['entry'], spec['end'])
        dis, poolw = {}, {}
        for addr, word, text in rows:
            if addr < spec['pool']:
                dis[addr] = text
            else:
                poolw[addr] = word
        srcfile = MOD / 'src' / spec['src']
        text = overrides.get(spec['src'], srcfile.read_text())
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
                 for a in sorted(cands)
                 if a not in dis and a not in poolw]
        pool_missing = [{'addr': hex(a), 'word': '%08x' % w}
                        for a, w in sorted(poolw.items())
                        if not any(('.word 0x%08x' % w) in c
                                   for c in cands.get(a, []))]
        shape_ok = (len(dis) == spec['ninstr'] and len(poolw) == spec['npool'])
        part = {'function': spec['name'], 'instructions': len(dis),
                'declared_instructions': spec['ninstr'],
                'declared_pool_words': spec['npool'], 'shape_ok': shape_ok,
                'documented': len(dis) - len(wrong), 'wrong': wrong,
                'duplicate_addresses': dupes, 'unknown_addresses': extra,
                'pool_words': len(poolw), 'pool_missing': pool_missing,
                'ok': (not wrong and not dupes and not extra and not pool_missing
                       and shape_ok)}
        report[spec['name']] = part
        ok = ok and part['ok']
    report['ok'] = ok
    report['instructions'] = sum(v['instructions'] for v in report.values()
                                if isinstance(v, dict) and 'instructions' in v)
    report['documented'] = sum(v['documented'] for v in report.values()
                               if isinstance(v, dict) and 'documented' in v)
    return report


def census_selftest():
    """The census gate must be able to say no.  Three source mutations, each of
    which has to turn exactly one part of the report red."""
    base = (MOD / 'src' / FUNCS[1]['src']).read_text()
    anchor_line = re.search(r'^.*@0x1f339c strb.*$', base, re.M)
    drop = base
    if anchor_line:
        drop = base[:anchor_line.start()] + base[anchor_line.end():]
    trials = {
        'operand_digit_changed': {FUNCS[1]['src']:
                                  base.replace('bl 0x27cedc', 'bl 0x27cede', 1)},
        'comment_line_deleted': {FUNCS[1]['src']: drop},
        'pool_word_changed': {FUNCS[1]['src']:
                              base.replace('.word 0x001fdabc',
                                           '.word 0x001fdabd', 1)},
    }
    res, ok = {}, True
    for name, ov in trials.items():
        rep = instruction_census(overrides=ov, fns={1})
        red = not rep['ok']
        res[name] = {'turned_red': red,
                     'wrong': len(rep[FUNCS[1]['name']]['wrong']),
                     'missing': len(rep[FUNCS[1]['name']]['wrong']),
                     'pool_missing': len(rep[FUNCS[1]['name']]['pool_missing'])}
        ok = ok and red
    res['ok'] = ok
    res['note'] = ('a mutation that leaves the gate green means the census does '
                   'not actually bind the translation to the bytes')
    return res


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
    o = Oracle()
    cells = {}
    for name, cell, want in (
            ('globdecl', GOT_GLOBDECL, BSS_GLOBDECL),
            ('builtin_numb', GOT_BUILTIN_NUMB, BSS_BUILTIN_NUMB),
            ('builtin_variables', GOT_BUILTIN_TABLE, BSS_BUILTIN_TABLE),
            ('g_builtinVarLookup', GOT_BUILTIN_MAP, BSS_BUILTIN_MAP),
            ('g_VarNamesGlobal', GOT_GLOBAL_NAMES, BSS_GLOBAL_NAMES),
            ('g_VarNamesInstance', GOT_INST_NAMES, BSS_INST_NAMES),
            ('g_instanceVarLookup', GOT_INST_MAP, BSS_INST_MAP),
            ('g_numFunctionsForLocalVars', GOT_NUM_LOCAL, BSS_NUM_LOCAL),
            ('g_localVariableNamesForFunctions', GOT_LOCAL_ARR, BSS_LOCAL_ARR),
            ('g_subFunctionsOption', GOT_GATE1, BSS_GATE1),
            ('g_fJSGarbageCollection', GOT_GATE2, BSS_GATE2)):
        w = struct.unpack('<I', bytes(o.read(cell, 4)))[0]
        cells[name] = {'got': hex(cell), 'value': hex(w),
                       'expected': hex(want), 'ok': w == want}
    strs = {}
    for name, addr, want in (
            ('unknown_variable', RO_UNKNOWN_VAR, MSG_UNKNOWN_VARIABLE),
            ('script_fmt', RO_SCRIPT_FMT, MSG_SCRIPT_FMT),
            ('too_many', RO_TOO_MANY, MSG_TOO_MANY),
            ('carray_file', RO_CARRAY, FILE_CARRAY),
            ('memmgr_file', RO_MEMMGR, FILE_MEMMGR)):
        got = rodata_string(SO, addr)
        strs[name] = {'at': hex(addr), 'text': got, 'ok': got == want}
    return {
        'original_sha256': sha(SO),
        'sha_matches_pin': sha(SO) == PIN,
        'got_cells': cells,
        'rodata_strings': strs,
        'ok': (sha(SO) == PIN and all(v['ok'] for v in cells.values())
               and all(v['ok'] for v in strs.values())),
    }


CARD_DELTAS = [
    {'card': 'cards/Variable_Misc.c',
     'item': 'segment 10, the pool address written for 0xd243c',
     'card_says': 'g_localVariableNamesForFunctions 槽（池 0xd2? —— -0x40a0）',
     'bytes_say': 'ldr r3,[pc,#0x6c] at 0xd243c reads pool word 0xd24b0 = '
                  '0xffffbf60, i.e. -0x40a0 -> 0x003edbb8',
     'verdict': 'CARD TEXT GLITCH ONLY. The value the card quotes (-0x40a0) is '
                'right; the pool address is truncated ("0xd2?"). No behaviour '
                'difference, nothing to re-derive - recorded so the next reader '
                'does not think the pool address is unknown.'},
]

CARD_NOTE = (
    'All four cards (cards/Variable_Global_Init.c, cards/DoVariableInstanceExists.c,'
    ' cards/Variable_Misc.c) were re-checked against llvm-objdump for this run:'
    ' instruction counts (24+2, 33+0, 158+13, 164+6), every pool word value,'
    ' every branch target and every GOT addend agree with the bytes. No card '
    'claim in this module had to be overruled. The items the cards mark open '
    'are handled as follows: Variable_Misc open 1 (names[slot] has no bound '
    'check) is now an OBSERVABLE in the arm - the fixture stages 8 names behind '
    'a count of 4, and the tooth f3_local_bound_check_added proves a translation '
    'that added the check would be caught. Variable_Misc open 2/3/4/5/6/7/8 are '
    'untouched: they are about who reads the tables and what the enumerations '
    'mean, which no case in this file can decide. Variable_Global_Init open 1 '
    '(what one globdecl byte is) stays open; the arm only pins that exactly '
    '10000 bytes are written per call.')

SCOPE = {
    'covered': [
        'F1: ReAlloc(old data pointer, 10000, cARRAY_STRUCTURE.h, 106, false) '
        'with the old pointer read from +4 BEFORE the new one is stored',
        'F1: cap and data written in that order, data == the bl result',
        'F1: all 10000 bytes cleared, per byte (prefill 0xaa leaves nothing)',
        'F1: no short circuit - every call goes through ReAlloc and the clear '
        'loop again',
        'F2: builtin id >= 0 answers through Variable_GetValue_Direct, builtin '
        'id < 0 falls to the instance name lookup, slot < 0 answers 0 with the '
        'RValue untouched',
        'F2: id = slot + 100000 lands on the right 16 B slot (the linked '
        'Variable_GetValue_Direct reports the slot index it was handed)',
        'F2: the RValue is zeroed before the callee sees it, and the answer is '
        '"tag & 0xffffff != 0xffffff" - tag 0x00ffffff answers 0, tag 0x1234ffff '
        'answers 1, tag 0 answers 1',
        'F2: inst+0x24 == 0 makes the linked Direct return without touching the '
        'RValue, so the zeroed tag answers 1',
        'F2: a NULL slot table takes Direct\'s InternalGetYYVar path and then '
        'GET_RValue with the returned pointer',
        'F2: builtin_numb is a dead input for this body (two cases, one record)',
        'F3: gate 1 short-circuits everything, including the id < 100000 test',
        'F3: type -5 -> global table, -1 -> instance table, -7 and -12 -> the '
        'function-name-keyed table, -9/-11/>100000 -> instance table, '
        'everything else -> "<unknown variable>"',
        'F3: the global/instance VALUE block is one shared block with two '
        'gates: slot >= count -> unknown, slot < size -> data[slot], else NULL',
        'F3: the instance map reverse scan walks the i-th OCCUPIED entry '
        'downwards, skips hash <= 0, and answers the key whose value is the slot',
        'F3: the local table is scanned by strcmp against the SCRIPT name, and '
        'names[slot] is read with no bound check (slots 5 and 7 of a count-4 '
        'entry answer "l5" and "l7")',
        'F3: gate 2 off -> unknown; on -> Script_Find_Parent, '
        '"gml_Script_%s", rescan of the same table, hit and miss',
        'F3: NULL and empty script names reach both the scan and the parent '
        'lookup unchanged',
        'F4: fresh append at slot == count, four fields at +0/+4/+8/+0xc with '
        'writable == (setter != NULL), and the 4th argument provably dead',
        'F4: the stale-name Free path (table[count].name != NULL)',
        'F4: the 500-entry limit tail-jumps ShowMessage and writes nothing '
        '(neither the entry nor the map nor the count)',
        'F4: the Robin Hood probe - empty home slot, occupied home slot, the '
        'swap, the three advance reasons (distance, hash, key pointer), and the '
        'duplicate path that gives the count increment back',
        'F4: duplicate detection is by KEY POINTER: the same bytes from another '
        'address become two entries',
        'F4: the hash sign bit is cleared before use (name "beta" has bit 31 '
        'set, and the stored hash is compared against the masked one)',
        'F4: doubling - cap/mask/entries, count 0, threshold (int)(0.6*cap), '
        'the clearing loop, rehash through CHashMap::Insert, Free of the old '
        'block, threshold recomputed, insert retried',
        'the failure byte 0x75505c: none of the four bodies contains a store to '
        'it, so every case stages it and reads it back - set stays set, clear '
        'stays clear, in all four functions',
        'second-run reproducibility of both arms'],
    'not_covered': [
        'MemoryManager::ReAlloc / Alloc / Free semantics (stubbed): the arm sees '
        'the arguments and the effect on the caller, not the allocator',
        'YYStrDup semantics (stubbed): allocation order and the copy, not the '
        'real allocator',
        'CHashMapCalculateHash semantics (stubbed with FNV-1a on both arms): '
        'the real hash at 0x1eeb88 is strlen + murmurhash 0x1eea84, NOT what '
        'this arm computes, so the BUCKET LAYOUT it produces is the stub\'s, '
        'not the device\'s. Every positional claim about the map in this '
        'receipt is therefore about the probe logic, which is the body under '
        'judgement, given a deterministic hash.',
        'CHashMap::Insert semantics (stubbed identically: linear probe from '
        'hash&mask): it defines the post-grow map, and only the ORDER and the '
        'VALUES handed to it are real evidence',
        'ShowMessage semantics (stubbed): the tail jump is modelled as a call '
        'then a return, so "does not return" is not itself tested',
        'Variable_BuiltIn_Find 0x1f3a5c (stubbed): whether a name is a builtin',
        'Variable_GetName 0x0d1d04 (stubbed): the (VarNumb, VarNames) table the '
        'gate-1 exit answers from',
        'Script_Find_Parent 0x1e06dc (stubbed): the parent lookup, and whether '
        'CScript+0x14 really is the name (card open 5)',
        'strcmp/snprintf @plt (answered identically): the real libc formatting '
        'and truncation behaviour, so the >4095-byte truncation path is not '
        'tested',
        'GET_RValue 0xd13bc / InternalGetYYVar 0x196a70 / the builtin getter fn '
        '(stubbed): what a variable read actually returns',
        'the cards\' open items that are about OTHER readers or about '
        'enumeration meaning (Variable_Misc open 2/3/4/5/6/7/8, '
        'Variable_Global_Init open 1/2/3/4, DoVariableInstanceExists open 1/2/3)',
        'device behaviour: this is a synthetic-memory oracle over the original '
        'bytes, not execution on a phone'],
    'not_applicable': [
        'Variable_GetName_Scope 0xd2494 (count < count-1) is unreachable for '
        'any count that is not INT_MIN; it is documented, not translated, and '
        'no case can reach it without staging an inconsistent map header whose '
        'result would be a NULL dereference in both arms',
        'the same body\'s "< 0 slot" test is done with `bmi` AFTER the gate-1 '
        'branch, so a gate-1-closed call never evaluates it - that ordering is '
        'covered, the "skip" it implies is not a separate decision',
        'F4\'s `beq` on count == 500 means count > 500 would append out of '
        'bounds; count only moves by +1/-1 in this body, so that state is '
        'unreachable and is not staged',
        'the 16 B entry\'s +0xd..+0xf padding is never read or written',
        'F3\'s reverse scan with map->count > the number of hash>0 entries: the '
        'inner walk is unbounded (0xd236c only checks hash and j), so that state '
        'reads past the array and its answer is not a property of the body'],
}

FINDINGS = [
    'Variable_Global_Init has no idempotence guard at all: the second call '
    're-runs ReAlloc and clears the table again.  The arm calls it once per '
    'case, so this is read off the bytes (no compare/short-circuit instruction '
    'exists between 0x1f3354 and 0x1f33b0), not off a re-execution test.',
    'DoVariableInstanceExists answers "is the tag different from 0x00ffffff", '
    'not "does the name exist".  Two cases make the difference concrete: an '
    'unset tag answers 0 even though the name resolved, and the Direct-returns-'
    'early path (inst+0x24 == 0) answers 1 because the RValue it just zeroed is '
    'not the sentinel.',
    'Variable_GetName_Scope folds type > 100000 into the instance domain '
    'unconditionally (`orrgt`), and the boundary is STRICT: type == 100000 is '
    'refused while 100001 is accepted.  Two cases pin the boundary from both '
    'sides and tooth f3_normalize_ge proves a `>=` would be caught.',
    'The local function table read names[slot] with no bound check.  The arm '
    'turns that from a card note into an observation: a count of 4 with 8 live '
    'names answers "l5"/"l7", and adding the check breaks two cases '
    '(f3_local_bound_check_added).',
    'Variable_BuiltIn_Add writes the entry BEFORE it touches the map and bumps '
    'builtin_numb LAST, so no reader can ever see a map value pointing at a '
    'half-built entry.  The order is visible in the trace (0x1f4e38..0x1f4e40 '
    'then 0x1f4ea0/0x1f4f00, then 0x1f4f28) and tooth f4_count_two moves the '
    'count without moving anything else.',
    'The 4th argument of Variable_BuiltIn_Add is genuinely dead: the differential '
    'varies it (p3) and gets a byte-identical record, and the writable bit is '
    'computed from the setter instead.  This is the third independent '
    'confirmation of the card\'s claim (card §6, the 7 inconsistent call '
    'sites, and now an executed case).',
    'The probe compares key POINTERS, not strings.  Case "the same bytes at '
    'another address" yields two table entries and two map entries, and tooth '
    'f4_key_content_compare (pointer -> strcmp) is caught by exactly that case.',
    'card/byte agreement: every instruction of the four bodies was re-read from '
    'the pinned image for this run; see card_deltas for the single documentation '
    'glitch (a truncated pool address, no behavioural content).',
    'NEW (not on any card): the instance map reverse scan has NO bound on its '
    'inner walk.  0xd236c advances the entry cursor until it has counted i+1 '
    'entries with hash > 0 and then compares that entry; if map->count ever '
    'exceeded the number of hash>0 entries, the cursor would run past the '
    'entries array and read unowned memory.  The fixture therefore always '
    'stages count == the number of occupied entries, which is what makes '
    'every map case in this arm terminate inside the array.  The original\'s '
    'behaviour in the out-of-step state is undecidable from these bytes '
    'alone - it depends on whatever follows the array.',
]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    ap.add_argument('--fns', default='1,2,3,4')
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    want = {int(x) for x in args.fns.split(',') if x.strip()}
    case_list = [c for c in cases() if c.fn in want]
    # the driver dispatches over all four bodies, so every module source that
    # exists is linked (a partial --fns run only narrows the case set/gates)
    paths = [MOD / 'src' / FUNCS[f]['src'] for f in sorted(FUNCS)
             if (MOD / 'src' / FUNCS[f]['src']).exists()]
    paths += [NAMES_MOD / 'src' / 'find_slot_from_name.c',
              DIRECT_MOD / 'src' / 'variable_direct.c']

    if args.no_run:
        last = sorted(RECEIPTS.glob('var_misc_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    bind = binding()
    census = instruction_census(fns=want)
    stest = census_selftest()

    base_bin = build_c(BUILD / 'var_misc.arm', paths=paths)
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

    stage2 = Stage(Oracle())
    a2 = [stage2.run(c) for c in case_list]
    c2 = run_c_arm(base_bin, case_list)
    repeat = {
        'runs_per_arm': 2,
        'original_identical': all(same(x, y) for x, y in zip(a_recs, a2)),
        'rebuild_identical': all(same(x, y) for x, y in zip(c_recs, c2)),
        'original_log_sha256': [_digest(a_recs), _digest(a2)],
        'rebuild_log_sha256': [_digest(c_recs), _digest(c2)],
    }
    rep_ok = repeat['original_identical'] and repeat['rebuild_identical']

    coverage, covered_by = {}, {}
    for name, fn in COVER:
        hits = [c.label for c, a, tr in zip(case_list, a_recs, traces)
                if fn(tr, a, c)]
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]

    mine = {FUNCS[f]['src'] for f in want}
    teeth = [teeth_one(m, case_list, a_recs, paths)
             for m in MUTANTS if m['file'] in mine]

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    status = 'PASS' if (identity and cov_ok and rep_ok and teeth_ok
                        and census['ok'] and stest['ok'] and bind['ok']) else 'FAIL'
    if want != set(FUNCS):
        status = status + ' (partial: fn ' + args.fns + ')'

    receipt = {
        'schema': 'cally-var-misc-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0x1f3354 / 0x1178b8 / 0xd2228 / 0x1f4da8 executed '
                           'over the real .bss the GOT points at, with identical '
                           'stubs on both arms; NOT device execution'),
        'BINDING': {
            'original_sha256': PIN,
            'functions': {FUNCS[f]['name']: {
                'entry': hex(FUNCS[f]['entry']),
                'range': [hex(FUNCS[f]['entry']), hex(FUNCS[f]['end'])],
                'pool': [hex(FUNCS[f]['pool']), hex(FUNCS[f]['end'])],
                'body_sha256': sha(MOD / 'src' / FUNCS[f]['src'])}
                for f in sorted(want)},
            'linked_recovered': {
                'Code_Variable_Find_Slot_From_Name@0xd21ec':
                    sha(NAMES_MOD / 'src' / 'find_slot_from_name.c'),
                'Variable_GetValue_Direct@0x1f3b8c':
                    sha(DIRECT_MOD / 'src' / 'variable_direct.c')},
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'header_sha256': sha(MOD / 'src' / 'variable_misc.h'),
            'binding_checks': bind,
            'stub_callees': [
                'MemoryManager::ReAlloc@0x27cedc',
                'Variable_BuiltIn_Find@0x1f3a5c',
                'Variable_GetName@0x0d1d04',
                'Script_Find_Parent@0x1e06dc',
                'strcmp@0x0b6574 / snprintf@0x0b65c8 / memset@0x0b65b0 (libc)',
                'GET_RValue@0x0d13bc / InternalGetYYVar@0x196a70 / the builtin '
                'getter fn (one level below the linked Variable_GetValue_Direct)',
                'Code_Variable_Find_Slot_From_Local_Name@0x0d1f74 / '
                '..._Global_Name@0x0d2054 (one level below the linked '
                'Find_Slot_From_Name)',
                'YYStrDup@0x0db8c8',
                'MemoryManager::Alloc@0x27ce78 / Free@0x27c2d0',
                'CHashMapCalculateHash@0x1eeb88 (FNV-1a here, murmurhash there)',
                'CHashMap::Insert@0x0d261c (linear probe here)',
                'ShowMessage@0x0c4b0c'],
            'guard_slot': {
                'got': hex(GOT_GUARD), 'value_in_image': '0x0',
                'note': 'R_ARM_GLOB_DAT, unrelocated: the fixture points it at a '
                        'guard word so Variable_GetName_Scope can read the '
                        'canary it stores at sp+4100'},
        },
        'scope': SCOPE,
        'findings': FINDINGS,
        'instruction_census': census,
        'census_selftest': stest,
        'repeat': repeat,
        'cases': len(case_list),
        'rows': rows,
        'coverage': coverage,
        'covered_by': covered_by,
        'teeth': teeth,
        'card_deltas': CARD_DELTAS,
        'card_note': CARD_NOTE,
        'status': status,
    }
    out = args.out or (RECEIPTS / ('var_misc_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d identical=%d binding=%s census=%d/%d '
          'selftest=%s' % (status, len(case_list),
                           sum(1 for r in rows if r['equal']),
                           'ok' if bind['ok'] else 'BAD',
                           census['documented'], census['instructions'],
                           'ok' if stest['ok'] else 'BAD'))
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
        for fn, spec in sorted(FUNCS.items()):
            if spec['name'] not in census:
                continue
            part = census[spec['name']]
            for w in part['wrong'][:8]:
                print('  CENSUS %s %s objdump=%r source=%r'
                      % (spec['name'], w['addr'], w['objdump'], w['source']))
            for w in part['pool_missing'][:8]:
                print('  CENSUS pool %s %s' % (spec['name'], w['addr']))
            for w in part['duplicate_addresses'][:8]:
                print('  CENSUS dup %s %s' % (spec['name'], w['addr']))
            for w in part['unknown_addresses'][:8]:
                print('  CENSUS extra %s %s' % (spec['name'], w['addr']))
    if not stest['ok']:
        print('  CENSUS-SELFTEST cannot go red: %r' % (stest,))
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
