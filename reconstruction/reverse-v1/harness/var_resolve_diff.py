#!/usr/bin/env python3
"""Variable_GetValue — original-binary differential (Level A, one function).

Two arms, same inputs, same staged memory:
  arm A (judge)  the original bytes at 0x1f3ce0, executed in Unicorn over the
                 six .bss globals the body reaches through its own .got, staged
                 hash tables, CObjectGM chains, the two fallback scan lists and
                 the room instance chain.  Its tail jump lands in the ORIGINAL
                 Variable_GetValue_Direct @0x1f3b8c, which runs for real.
  arm B (claim)  reconstruction/reverse-v1/c/variable_resolve/ plus the already
                 recovered reconstruction/reverse-v1/c/variable_direct/, built
                 for armv7a-none-eabi (freestanding) and run under qemu-arm.

Why arm B must not be host-compiled: every offset in this body is a literal
(0x4 next / 0x8 key / 0xc value / 0x18 index / 0x48 parent / 0x68 / 0x69 / 0x80
/ 0xd0 / 0x178), the bucket array is addressed with `lsl #3` and the fallback
list items with `lsl #2`.  A 64-bit host build moves pointers to 8 bytes and
every one of those offsets stops testing what the original does.

What is compared per case: the return value, all 16 destination bytes, the
1-byte failure flag at 0x75505c, and the ordered callee log
    G <arrindex> <slot delta>     GET_RValue
    B <instance index> <arrindex> builtin-variable getter
    I <slot>                      InternalGetYYVar
with addresses resolved through each arm's own registry, never printed raw.

Scope, stated up front:
  * Variable_GetValue_Direct @0x1f3b8c is ALREADY recovered (c/variable_direct)
    and the claim arm links that translation for real; the judge arm runs its
    original bytes.  So this differential covers two bodies, not one, and a
    green run says both dispatch correctly.
  * GET_RValue @0xd13bc, YYObjectBase::InternalGetYYVar @0x196a70 and the
    builtin-variable table entry's fn are NOT recovered: both arms run
    IDENTICAL stubs for them.  A green run proves nothing about those callees
    and is not device equivalence.
  * the two fallback scan lists are modelled from their layout (12 B
    {items, ?, count}, CInstance* elements) - their class names are unknown
    (see cards/Variable_GetValue.c open 1).

Gates:
  * identity   every case identical on both arms on all four facets
  * census     every instruction of the original appears in the translation
               with verbatim llvm-objdump operand text, and every literal-pool
               word is documented (machine check, not prose)
  * coverage   every decision of the ORIGINAL body is taken, judged by that
               arm's own instruction trace (COVER), never by the case inputs
  * repeat     both arms rerun in a second process reproduce their records
  * teeth      every source-level mutant of the translation is caught by at
               least one named case; a green mutant means the case set does not
               exercise that decision

Usage:
  python3 var_resolve_diff.py            # build, run both arms, write receipt
  python3 var_resolve_diff.py --no-run   # replay the gates on the last receipt
"""
import argparse
import hashlib
import json
import pathlib
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
MOD = RV1 / 'c' / 'variable_resolve'
DIRECT_MOD = RV1 / 'c' / 'variable_direct'
BUILD = HERE / 'build' / 'var_resolve'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3, UC_ARM_REG_PC,
    UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
ENTRY = 0x1f3ce0
LAST_INSN = 0x1f3f6c
POOL = 0x1f3f70
GET_RVALUE = 0xd13bc
INT_GET_YYVAR = 0x196a70
GOT_BVAR = 0x3edc40

# The six .bss globals this body reaches through .got (base 0x3f1c58).  All six
# GOT slots carry their R_ARM_RELATIVE addend in the file, so these addresses
# are read off the image, not guessed - and the harness re-checks them below.
GOT_SLOTS = {
    0x3edd68: 0x75505c,   # g_var_resolve_failed   1 B
    0x3edc4c: 0x536f28,   # g_inst_table           cell IS the table
    0x3edc44: 0x542374,   # g_object_hash          cell HOLDS a pointer
    0x3edc48: 0x542a64,   # g_scan_list1
    0x3edc50: 0x542a4c,   # g_scan_list2
    0x3ed930: 0x54298c,   # g_run_room_holder      cell HOLDS a pointer
}
BSS_FLAG = 0x75505c
BSS_INST_TABLE = 0x536f28
BSS_OBJ_HASH = 0x542374
BSS_SCAN1 = 0x542a64
BSS_SCAN2 = 0x542a4c
BSS_RUN_ROOM = 0x54298c

NBUCK = 512
OUT_PRESET = 0x00FFFFFF
INT_MIN = -0x80000000
INT_MAX = 0x7fffffff

# region id -> (count, stride).  Identical to the fixture's REG table; the bases
# differ per arm (that is the point), the geometry must not.
REGIONS = {
    'I': (8, 0x180),    # instances
    'O': (4, 0x100),    # CObjectGM blocks  (+0x18 index, +0x48 parent, +0xd0 chain)
    'B': (8, 0x10),     # hash nodes        (+4 next, +8 key, +0xc value)
    'C': (6, 0x0c),     # instance chain    (+0 next, +4 prev, +8 inst)
    'L': (8, 0x04),     # fallback list item arrays
    'S': (8, 0x40),     # per-instance variable slot table (16 B slots)
    'T': (1, 0x0c),     # ms_ID2InstanceE body
    'U': (1, 0x0c),     # g_ObjectHash table body
    'K': (NBUCK, 0x08),  # instance-table buckets
    'V': (NBUCK, 0x08),  # object-table buckets
    'R': (1, 0x88),     # CRoom, +0x80 instance head
    'Q': (1, 0x0c),     # scan list 1 body
    'W': (1, 0x0c),     # scan list 2 body
    'G': (1, 0x04),     # *(0x542374), the object-hash pointer variable
    'Y': (1, 0x04),     # *(0x54298c), the room pointer variable
    'X': (1, 0x10),     # the destination RValue
}


# ── case description ─────────────────────────────────────────────────────────
class Case:
    """One input plus the staging program both arms interpret.

    The program is a list of writes `(region, index, offset, kind, a, b)`:
    kind 0 stores `a`, kind 1 stores base(a) + b*stride(a).  Because the two
    arms supply their own region bases, the same program stages the same object
    graph at different addresses - and no case can "self-certify": the gates are
    judged on the original arm's instruction trace and on the four compared
    facets, not on these knobs.
    """

    def __init__(self, p1, p2, p3, label, mask_obj=0x1ff, mask_inst=0x1ff):
        self.p1, self.p2, self.p3 = p1, p2, p3
        self.label = label
        self.mask_obj, self.mask_inst = mask_obj, mask_inst
        self.w = []
        self._base()

    # -- writers ------------------------------------------------------------
    def lit(self, reg, idx, off, v):
        self.w.append((reg, idx, off, 0, v & 0xffffffff, 0))
        return self

    def ptr(self, reg, idx, off, src, sidx):
        self.w.append((reg, idx, off, 1, src, sidx))
        return self

    # -- the sub-graph helpers ---------------------------------------------
    def inst(self, i, obj=None, room_next=None, dead=False, deact=False):
        self.ptr('I', i, 0x04, 'S', i)         # variable table of instance i
        self.lit('I', i, 0x24, 1)              # "has instance variables" flag
        if obj is not None:
            self.ptr('I', i, 0x80, 'O', obj)
        if room_next is not None:
            self.ptr('I', i, 0x178, 'I', room_next)
        if dead:
            self.lit('I', i, 0x68, 1)          # byte +0x68 (word write, low byte)
        if deact:
            self.lit('I', i, 0x69, 1)          # byte +0x69
        return self

    def ogm(self, n, index, parent=None, chain=None):
        self.lit('O', n, 0x18, index)
        if parent is not None:
            self.ptr('O', n, 0x48, 'O', parent)
        if chain is not None:
            self.ptr('O', n, 0xd0, 'C', chain)
        return self

    def hnode(self, n, key, value_inst=None, value=0, nxt=None):
        if nxt is not None:
            self.ptr('B', n, 0x04, 'B', nxt)
        self.lit('B', n, 0x08, key)
        if value_inst is not None:
            self.ptr('B', n, 0x0c, 'I', value_inst)
        else:
            self.lit('B', n, 0x0c, value)
        return self

    def chain(self, n, inst=None, nxt=None):
        if nxt is not None:
            self.ptr('C', n, 0x00, 'C', nxt)
        if inst is not None:
            self.ptr('C', n, 0x08, 'I', inst)
        return self

    def bucket(self, table, b, node):
        self.ptr('K' if table == 'inst' else 'V', b, 0, 'B', node)
        return self

    def scan(self, which, items, count=None):
        reg = 'Q' if which == 1 else 'W'
        self.lit(reg, 0, 0x08, len(items) if count is None else count)
        for k, it in enumerate(items):
            if it is not None:
                self.ptr('L', (0 if which == 1 else 4) + k, 0, 'I', it)
        return self

    def room(self, head=None):
        if head is not None:
            self.ptr('R', 0, 0x80, 'I', head)
        return self

    # -- the staging every case starts from ---------------------------------
    def _base(self):
        # The two hash tables, at their two indirection depths.
        self.ptr('T', 0, 0x00, 'K', 0).lit('T', 0, 0x04, self.mask_inst)
        self.ptr('U', 0, 0x00, 'V', 0).lit('U', 0, 0x04, self.mask_obj)
        # *(0x542374) -> the object table; *(0x54298c) -> holder -> CRoom.
        self.ptr('G', 0, 0x00, 'U', 0)     # g_ObjectHash: pointer variable
        self.ptr('Y', 0, 0x00, 'R', 0)     # Run_Room:    pointer variable
        # Both fallback lists exist and are empty; the room chain is empty.
        self.ptr('Q', 0, 0x00, 'L', 0).lit('Q', 0, 0x08, 0)
        self.ptr('W', 0, 0x00, 'L', 4).lit('W', 0, 0x08, 0)
        self.lit('R', 0, 0x80, 0)
        # Every instance: its own variable table, the "has vars" flag, no
        # object, no room successor, both liveness bytes clear.
        for i in range(REGIONS['I'][0]):
            self.inst(i)
        return self

    def args(self):
        return (self.p1, self.p2, self.p3)

    def line(self):
        """The input record the C driver reads (identical token syntax)."""
        out = ['%d %d %d %d' % (self.p1, self.p2, self.p3, len(self.w))]
        for (reg, idx, off, kind, a, b) in self.w:
            # `a` is a literal for kind 0 and a region id for kind 1; the driver
            # reads every field as an integer, so a region travels as its code.
            a_out = ord(a) if kind else a
            out.append('%s %d %d %d %d %d' % (reg, idx, off, kind, a_out, b))
        return '\n'.join(out) + '\n'


def cases():
    """Deterministic; same list, same order, on every run.

    p2 = 100000 + k resolves to slot k of the instance's own table window
    (region S index i, 16 B slots), so a G line's slot delta names both the
    instance and the slot.
    """
    C = []
    add = C.append
    S = 100000

    # ── A · sel == -3: the room instance chain ─────────────────────────────
    add(Case(-3, S, INT_MIN, 'A1 room chain empty -> fail'))
    add(Case(-3, S, INT_MIN, 'A2 room head live -> hit inst0').room(0))
    add(Case(-3, S, INT_MIN,
             'A3 head destroyed, successor live -> hit inst1')
        .room(0).inst(0, room_next=1, dead=True).inst(1, room_next=None))
    add(Case(-3, S, INT_MIN,
             'A4 head deactivated, successor live -> hit inst1')
        .room(0).inst(0, room_next=1, deact=True))
    add(Case(-3, S, INT_MIN,
             'A5 all gated: dead -> deactivated -> dead -> fail')
        .room(0).inst(0, room_next=1, dead=True)
        .inst(1, room_next=2, deact=True).inst(2, dead=True))
    add(Case(-3, S, INT_MIN, 'A6 head destroyed, no successor -> fail')
        .room(0).inst(0, dead=True))
    add(Case(-3, S + 2, INT_MAX, 'A7 room hit, slot 2, arrindex INT_MAX')
        .room(3).inst(3))

    # ── B · sel < 0 and != -3: immediate failure ───────────────────────────
    # Every structure that could resolve something is live and would match the
    # negative id itself (room head, scan-list element, its object index), so a
    # dropped sign gate cannot hide behind an empty stage.
    for k, neg in enumerate((-1, -2, -4), 1):
        add(Case(neg, S, INT_MIN,
                 'B%d sel %d -> fail even though room and scan1 would match'
                 % (k, neg))
            .room(0).inst(0, obj=0).scan(1, [0]).ogm(0, neg))

    # ── C · sel > 99999: ms_ID2InstanceE ───────────────────────────────────
    add(Case(100000, S, INT_MIN, 'C1 id bucket empty -> fail'))
    add(Case(100000, S, INT_MIN,
             'C2 same-bucket collision then hit -> inst0')
        .hnode(0, 99999, value_inst=1, nxt=1)
        .hnode(1, 100000, value_inst=0)
        .bucket('inst', 100000 & 0x1ff, 0))
    add(Case(100000, S, INT_MIN, 'C3 key hit, value NULL -> fail')
        .hnode(0, 100000, value=0).bucket('inst', 100000 & 0x1ff, 0))
    add(Case(100000, S, INT_MIN, 'C4 key hit, instance destroyed -> fail')
        .hnode(0, 100000, value_inst=0).bucket('inst', 100000 & 0x1ff, 0)
        .inst(0, dead=True))
    add(Case(100000, S, INT_MIN,
             'C5 key hit, instance DEACTIVATED -> still hit (only +0x68 is read)')
        .hnode(0, 100000, value_inst=0).bucket('inst', 100000 & 0x1ff, 0)
        .inst(0, deact=True))
    add(Case(100001, S + 1, INT_MIN, 'C6 key hit, live -> hit inst2')
        .hnode(0, 100001, value_inst=2).bucket('inst', 100001 & 0x1ff, 0))
    add(Case(100002, S, INT_MIN, 'C7 chain walks to the tail without a hit -> fail')
        .hnode(0, 99999, value_inst=0, nxt=1)
        .hnode(1, 99998, value_inst=1)
        .bucket('inst', 100002 & 0x1ff, 0))
    # mask is read from the table, not hardcoded: mask 7 moves the bucket.
    add(Case(100003, S, INT_MIN, 'C8 mask 7: bucket 3 holds the hit',
             mask_inst=7)
        .hnode(0, 100003, value_inst=1).bucket('inst', 100003 & 7, 0))
    add(Case(INT_MAX, S, INT_MIN, 'C9 INT_MAX id, empty bucket -> fail'))
    add(Case(100500, S + 3, -1, 'C10 id hit, slot 3, arrindex -1')
        .hnode(0, 100500, value_inst=4).bucket('inst', 100500 & 0x1ff, 0))
    # bucket 0: the table-extra-indirection mutant turns the bucket head into a
    # fake "buckets" pointer, and bucket 0 is where that pointer is read back.
    add(Case(100352, S, INT_MIN, 'C11 id hit in bucket 0')
        .hnode(0, 100352, value_inst=3).bucket('inst', 100352 & 0x1ff, 0))

    # ── D · 0 <= sel <= 99999: g_ObjectHash -> CObjectGM -> chain ──────────
    add(Case(0, S, INT_MIN, 'D1 object bucket empty, both scans empty -> fail'))
    add(Case(1, S, INT_MIN, 'D2 object chain, key never matches -> fail')
        .hnode(0, 2, value_inst=0).bucket('obj', 1 & 0x1ff, 0))
    add(Case(1, S, INT_MIN, 'D3 key hit, CObjectGM NULL -> fail')
        .hnode(0, 1, value=0).bucket('obj', 1 & 0x1ff, 0))
    add(Case(1, S, INT_MIN, 'D4 key hit, CObjectGM without a chain -> fail')
        .hnode(0, 1, value=0).ptr('B', 0, 0x0c, 'O', 0)
        .bucket('obj', 1 & 0x1ff, 0))
    add(Case(1, S, INT_MIN, 'D5 chain head without an instance -> fail')
        .hnode(0, 1, value=0).ptr('B', 0, 0x0c, 'O', 0)
        .bucket('obj', 1 & 0x1ff, 0)
        .ptr('O', 0, 0xd0, 'C', 0).chain(0, inst=None))
    add(Case(2, S, INT_MIN,
             'D6 chain: first node destroyed, second live -> hit inst1')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0)
        .chain(0, inst=0, nxt=1).chain(1, inst=1)
        .inst(0, dead=True))
    add(Case(2, S, INT_MIN, 'D7 chain: only node dead -> fail')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0)
        .chain(0, inst=0).inst(0, dead=True))
    add(Case(2, S, INT_MIN, 'D8 chain: first node live -> hit inst0')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0)
        .chain(0, inst=0))
    add(Case(2, S, INT_MIN,
             'D11 chain: node 0 deactivated, node 1 live -> hit inst1')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0)
        .chain(0, inst=0, nxt=1).chain(1, inst=1)
        .inst(0, deact=True))
    add(Case(8, S, INT_MIN, 'D9 object mask 7: bucket 0 holds the hit',
             mask_obj=7)
        .hnode(0, 8, value=0).bucket('obj', 8 & 7, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0)
        .chain(0, inst=5))
    add(Case(99999, S, INT_MIN, 'D10 boundary 99999 stays on the object path')
        .hnode(0, 99999, value=0).bucket('obj', 99999 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0)
        .chain(0, inst=6))

    # ── E · the two fallback scan lists ────────────────────────────────────
    add(Case(5, S, INT_MIN, 'E1 scan1 direct object match -> hit inst0')
        .scan(1, [0]).inst(0, obj=0).ogm(0, 5))
    add(Case(5, S, INT_MIN, 'E2 scan1 ancestor match (parent chain) -> hit inst0')
        .scan(1, [0]).inst(0, obj=0)
        .ogm(0, 77, parent=1).ogm(1, 5))
    add(Case(5, S, INT_MIN, 'E3 scan1 ancestor chain without a match -> fail')
        .scan(1, [0]).inst(0, obj=0)
        .ogm(0, 77, parent=1).ogm(1, 78))
    add(Case(5, S, INT_MIN, 'E4 scan1 element without an object -> fail')
        .scan(1, [0]))
    # L[2] is staged as a third, non-counted element so an element-stride
    # mutant reads it instead of L[1] and lands on a different instance.
    add(Case(5, S, INT_MIN,
             'E5 scan1 two matches, first destroyed -> hit inst1')
        .scan(1, [0, 1]).inst(0, obj=0, dead=True).inst(1, obj=1)
        .inst(2, obj=1).ptr('L', 2, 0, 'I', 2)
        .ogm(0, 5).ogm(1, 5))
    add(Case(5, S, INT_MIN, 'E6 scan1 match but deactivated -> fail')
        .scan(1, [0]).inst(0, obj=0, deact=True).ogm(0, 5))
    add(Case(5, S, INT_MIN, 'E7 scan1 match but destroyed -> fail')
        .scan(1, [0]).inst(0, obj=0, dead=True).ogm(0, 5))
    add(Case(5, S, INT_MIN, 'E8 scan1 empty, scan2 match -> hit inst5')
        .scan(2, [5]).inst(5, obj=0).ogm(0, 5))
    add(Case(5, S, INT_MIN,
             'E9 both lists would hit; scan1 wins -> hit inst2')
        .scan(1, [2]).scan(2, [5])
        .inst(2, obj=0).inst(5, obj=1).ogm(0, 5).ogm(1, 5))
    add(Case(5, S, INT_MIN, 'E10 scan2 skips a objectless element -> hit inst6')
        .scan(2, [4, 6]).inst(6, obj=0).ogm(0, 5))
    add(Case(5, S, INT_MIN, 'E11 scan2 ancestor match -> hit inst6')
        .scan(2, [6]).inst(6, obj=0)
        .ogm(0, 88, parent=1).ogm(1, 5))
    add(Case(5, S, INT_MIN,
             'E12 scan2: destroyed match, then a live one -> hit inst7')
        .scan(2, [4, 7]).inst(4, obj=0, dead=True).inst(7, obj=1)
        .ogm(0, 5).ogm(1, 5))
    add(Case(5, S, INT_MIN, 'E13 scan2 match but deactivated -> fail')
        .scan(2, [6]).inst(6, obj=0, deact=True).ogm(0, 5))
    add(Case(5, S, INT_MIN, 'E14 scan1 count -1 is skipped, scan2 hits')
        .scan(2, [5]).inst(5, obj=0).ogm(0, 5).lit('Q', 0, 0x08, -1))
    add(Case(5, S, INT_MIN, 'E15 scan2 destroyed match then chain end -> fail')
        .scan(2, [4]).inst(4, obj=0, dead=True).ogm(0, 5))
    add(Case(5, S, INT_MIN, 'E16 scan2 ancestor chain without a match -> fail')
        .scan(2, [6]).inst(6, obj=0)
        .ogm(0, 88, parent=1).ogm(1, 78))

    # ── F · varid / arrindex passthrough ───────────────────────────────────
    add(Case(2, S + 1, INT_MAX, 'F1 slot 1, arrindex INT_MAX')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0).chain(0, inst=3))
    add(Case(2, 100003, -1, 'F2 slot 3, arrindex -1')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0).chain(0, inst=3))
    add(Case(2, 5000, 7, 'F3 builtin variable number -> fn(obj, 7, out)')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0).chain(0, inst=4))
    add(Case(2, 50000, INT_MIN, 'F4 varid in the unguarded gap -> negative slot')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0).chain(0, inst=4))
    add(Case(2, -7, INT_MIN, 'F5 negative varid -> slot path, negative delta')
        .hnode(0, 2, value=0).bucket('obj', 2 & 0x1ff, 0)
        .ptr('B', 0, 0x0c, 'O', 0).ptr('O', 0, 0xd0, 'C', 0).chain(0, inst=1))
    add(Case(-3, S, INT_MIN, 'F6 room hit with the scalar arrindex sentinel')
        .room(4))
    return C


# ── coverage: decisions of the ORIGINAL body, proven by its own trace ────────
def ex(tr, a):
    return a in tr


def tk(tr, a, b):
    for i in range(len(tr) - 1):
        if tr[i] == a and tr[i + 1] == b:
            return True
    return False


COVER = [
    ('entry_clears_flag', lambda tr, r, c: tk(tr, 0x1f3cf8, 0x1f3cfc)),
    ('dispatch_all_m3', lambda tr, r, c: tk(tr, 0x1f3d00, 0x1f3f0c)),
    ('dispatch_negative', lambda tr, r, c: tk(tr, 0x1f3d08, 0x1f3e68)),
    ('dispatch_instance_id', lambda tr, r, c: tk(tr, 0x1f3d18, 0x1f3d1c)),
    ('dispatch_object_index', lambda tr, r, c: tk(tr, 0x1f3d18, 0x1f3e7c)),
    ('id_bucket_empty', lambda tr, r, c: tk(tr, 0x1f3d3c, 0x1f3e68)),
    ('id_chain_walk', lambda tr, r, c: tk(tr, 0x1f3d54, 0x1f3d40)),
    ('id_chain_end', lambda tr, r, c: tk(tr, 0x1f3d48, 0x1f3e68)),
    ('id_value_null', lambda tr, r, c: tk(tr, 0x1f3d60, 0x1f3e68)),
    ('id_destroyed', lambda tr, r, c: tk(tr, 0x1f3d6c, 0x1f3e68)),
    ('id_hit', lambda tr, r, c: tk(tr, 0x1f3d70, 0x1f3d74)),
    ('id_gate_passes_0x68_clear', lambda tr, r, c: tk(tr, 0x1f3d6c, 0x1f3d70)),
    ('obj_bucket_empty', lambda tr, r, c: tk(tr, 0x1f3ea0, 0x1f3d78)),
    ('obj_chain_walk', lambda tr, r, c: tk(tr, 0x1f3eb8, 0x1f3ea4)),
    ('obj_chain_end', lambda tr, r, c: tk(tr, 0x1f3eac, 0x1f3d78)),
    ('obj_value_null', lambda tr, r, c: tk(tr, 0x1f3ec8, 0x1f3d78)),
    ('obj_no_instance_chain', lambda tr, r, c: tk(tr, 0x1f3ed0, 0x1f3d78)),
    ('obj_node_inst_null', lambda tr, r, c: tk(tr, 0x1f3edc, 0x1f3d78)),
    ('obj_skip_destroyed', lambda tr, r, c: tk(tr, 0x1f3ef0, 0x1f3ecc)),
    ('obj_skip_deactivated', lambda tr, r, c: tk(tr, 0x1f3efc, 0x1f3ecc)),
    ('obj_chain_hit', lambda tr, r, c: tk(tr, 0x1f3f04, 0x1f3f08)),
    ('scan1_count_zero', lambda tr, r, c: tk(tr, 0x1f3d88, 0x1f3df0)),
    ('scan1_element_no_object', lambda tr, r, c: tk(tr, 0x1f3da0, 0x1f3de4)),
    ('scan1_ancestor_walk', lambda tr, r, c: tk(tr, 0x1f3dc0, 0x1f3da4)),
    ('scan1_no_match', lambda tr, r, c: tk(tr, 0x1f3dc8, 0x1f3de4)),
    ('scan1_skip_destroyed', lambda tr, r, c: tk(tr, 0x1f3dd4, 0x1f3de4)),
    ('scan1_skip_deactivated', lambda tr, r, c: tk(tr, 0x1f3de0, 0x1f3de4)),
    ('scan1_hit', lambda tr, r, c: tk(tr, 0x1f3de0, 0x1f3f58)),
    ('scan1_loop_next', lambda tr, r, c: tk(tr, 0x1f3dec, 0x1f3d90)),
    ('scan2_count_zero', lambda tr, r, c: tk(tr, 0x1f3e00, 0x1f3e68)),
    ('scan2_element_no_object', lambda tr, r, c: tk(tr, 0x1f3e18, 0x1f3e5c)),
    ('scan2_ancestor_walk', lambda tr, r, c: tk(tr, 0x1f3e38, 0x1f3e1c)),
    ('scan2_no_match', lambda tr, r, c: tk(tr, 0x1f3e40, 0x1f3e5c)),
    ('scan2_skip_destroyed', lambda tr, r, c: tk(tr, 0x1f3e4c, 0x1f3e5c)),
    ('scan2_skip_deactivated', lambda tr, r, c: tk(tr, 0x1f3e58, 0x1f3e5c)),
    ('scan2_hit', lambda tr, r, c: tk(tr, 0x1f3e58, 0x1f3f64)),
    ('scan2_loop_next', lambda tr, r, c: tk(tr, 0x1f3e64, 0x1f3e08)),
    ('fail_flag_store', lambda tr, r, c: tk(tr, 0x1f3e6c, 0x1f3e70)),
    ('fail_return_bx_lr', lambda tr, r, c: tk(tr, 0x1f3e74, 0x1f3e78)),
    ('room_chain_empty', lambda tr, r, c: tk(tr, 0x1f3f20, 0x1f3f24)),
    ('room_chain_end', lambda tr, r, c: tk(tr, 0x1f3f30, 0x1f3e68)),
    ('room_skip_destroyed', lambda tr, r, c: tk(tr, 0x1f3f40, 0x1f3f28)),
    ('room_skip_deactivated', lambda tr, r, c: tk(tr, 0x1f3f4c, 0x1f3f28)),
    ('room_hit', lambda tr, r, c: tk(tr, 0x1f3f50, 0x1f3f54)),
    ('scan1_hit_exit', lambda tr, r, c: tk(tr, 0x1f3f5c, 0x1f3f60)),
    ('scan2_hit_exit', lambda tr, r, c: tk(tr, 0x1f3f68, 0x1f3f6c)),
    # record-level, not trace-level: the failure contract the caller relies on.
    ('out_untouched_on_failure', lambda tr, r, c: r['ret'] == 0 and r['flag'] == 1
     and r['out'] == preset_out()),
    ('flag_clear_on_success', lambda tr, r, c: r['ret'] != 0 and r['flag'] == 0),
]


def preset_out():
    return (struct.pack('<I', OUT_PRESET) + b'\xee' * 12).hex()


# ── original arm ─────────────────────────────────────────────────────────────
def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


def marker(base):
    return bytes((base + i) & 0xff for i in range(16))


class Stage:
    """One staged environment; hooks installed once.

    Per case only the region contents are rewritten and the logs cleared.
    Adding hooks per case would leave the previous case's hooks live on the
    same Unicorn instance, and they would keep appending to their own logs.
    """

    def __init__(self, o):
        self.o = o
        self.log = []
        self.tr = []
        # region bases.  Six of them are the mapped image's own .bss cells, so
        # the original body's GOT-relative addressing is used unchanged; the
        # rest are oracle heap.
        self.base = {
            'I': o.alloc(REGIONS['I'][0] * REGIONS['I'][1]),
            'O': o.alloc(REGIONS['O'][0] * REGIONS['O'][1]),
            'B': o.alloc(REGIONS['B'][0] * REGIONS['B'][1]),
            'C': o.alloc(REGIONS['C'][0] * REGIONS['C'][1]),
            'L': o.alloc(REGIONS['L'][0] * REGIONS['L'][1]),
            'S': o.alloc(REGIONS['S'][0] * REGIONS['S'][1]),
            'T': BSS_INST_TABLE,
            'U': o.alloc(12),
            'K': o.alloc(NBUCK * 8),
            'V': o.alloc(NBUCK * 8),
            'R': o.alloc(0x88),
            'Q': BSS_SCAN1,
            'W': BSS_SCAN2,
            'G': BSS_OBJ_HASH,
            'Y': BSS_RUN_ROOM,
            'X': o.alloc(0x10),
        }
        self.stride = {k: v[1] for k, v in REGIONS.items()}
        self.count = {k: v[0] for k, v in REGIONS.items()}
        # the builtin-variable table: 16 B entries, getter at +4, one stub page
        self.stub = o.alloc(16, 4)
        o.write(self.stub, struct.pack('<I', 0xe12fff1e))   # bx lr
        self.bvar = o.alloc(10000 * 16)
        blob = bytearray(10000 * 16)
        for i in range(10000):
            struct.pack_into('<I', blob, i * 16 + 4, self.stub)
        o.write(self.bvar, bytes(blob))
        # The one GOT slot the harness rewrites: the builtin table has to live
        # in the oracle heap (10000 entries do not fit the image's .bss).  The
        # other six are asserted below to hold their own addends.
        o.write(GOT_BVAR, struct.pack('<I', self.bvar))
        for addr, fn in ((GET_RVALUE, self.hook_get),
                         (INT_GET_YYVAR, self.hook_int),
                         (self.stub, self.hook_bvar)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=ENTRY, end=LAST_INSN)

    # -- hooks --------------------------------------------------------------
    def hook_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def hook_get(self, uc_, _a, _s, _d):
        dst = uc_.reg_read(UC_ARM_REG_R0)
        src = uc_.reg_read(UC_ARM_REG_R1)
        axi = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        off = src - self.base['S']       # signed: a slot below S is real
        self.log.append(['G', axi, to_i32(off)])
        self.o.write(dst, marker(0x30))
        uc_.reg_write(UC_ARM_REG_R0, 0x2222)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_int(self, uc_, _a, _s, _d):
        slot = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        self.log.append(['I', slot])
        uc_.reg_write(UC_ARM_REG_R0, self.base['S'] + 7 * 0x40)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_bvar(self, uc_, _a, _s, _d):
        obj = uc_.reg_read(UC_ARM_REG_R0)
        axi = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        dst = uc_.reg_read(UC_ARM_REG_R2)
        self.log.append(['B', self.inst_index(obj), axi])
        self.o.write(dst, marker(0x50 + self.inst_index(obj)
                                 if self.inst_index(obj) >= 0 else 0x30))
        uc_.reg_write(UC_ARM_REG_R0, 0x1111)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    # -- staging ------------------------------------------------------------
    def inst_index(self, p):
        for i in range(self.count['I']):
            if self.base['I'] + i * self.stride['I'] == p:
                return i
        return -1

    def apply(self, writes):
        for (reg, idx, off, kind, a, b) in writes:
            addr = (self.base[reg] + idx * self.stride[reg] + off) & 0xffffffff
            if kind:
                val = self.base[a] + b * self.stride[a]
            else:
                val = a
            self.o.write(addr, struct.pack('<I', val & 0xffffffff))

    def reset(self):
        for k in self.base:
            self.o.write(self.base[k], b'\0' * (self.count[k] * self.stride[k]))
        self.o.write(self.base['X'],
                     struct.pack('<I', OUT_PRESET) + b'\xee' * 12)

    def run(self, case):
        self.reset()
        self.apply(case.w)
        self.log.clear()
        self.tr.clear()
        ret = self.o.call(ENTRY, r0=case.p1 & 0xffffffff, r1=case.p2 & 0xffffffff,
                          r2=case.p3 & 0xffffffff, r3=self.base['X'])
        return {'ret': to_i32(ret),
                'out': bytes(self.o.read(self.base['X'], 16)).hex(),
                'flag': self.o.read(BSS_FLAG, 1)[0],
                'calls': [list(x) for x in self.log],
                'tr': list(self.tr)}


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']


def build_c(out_bin, mutant=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    src = MOD / 'src' / 'variable_resolve.c'
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
           ['-O1', '-I', str(MOD / 'src'), '-I', str(DIRECT_MOD / 'src'),
            str(src), str(DIRECT_MOD / 'src' / 'variable_direct.c'),
            str(MOD / 'fixture' / 'driver.c'), '-o', str(out_bin)])
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-3000:])
    return out_bin


def run_c_arm(binary, case_list):
    blob = ''.join(c.line() for c in case_list).encode()
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
            cur = {'ret': 0, 'out': '', 'flag': -1, 'calls': []}
            recs.append(cur)
        elif parts[0] == 'RET':
            cur['ret'] = int(parts[1])
        elif parts[0] == 'OUT':
            cur['out'] = parts[1]
        elif parts[0] == 'FLAG':
            cur['flag'] = int(parts[1])
        elif parts[0] == 'CALLS':
            cur['ncalls'] = int(parts[1])
        elif parts[0] == 'G':
            cur['calls'].append(['G', int(parts[1]), int(parts[2])])
        elif parts[0] == 'B':
            cur['calls'].append(['B', int(parts[1]), int(parts[2])])
        elif parts[0] == 'I':
            cur['calls'].append(['I', int(parts[1])])
    if len(recs) != len(case_list):
        raise RuntimeError('driver produced %d records for %d cases (truncated '
                           'input?)' % (len(recs), len(case_list)))
    return recs


def norm_c(rec):
    return {'ret': rec['ret'], 'out': rec['out'], 'flag': rec['flag'],
            'calls': rec['calls']}


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    {'name': 'boundary_99999_off_by_one', 'edits': [
        ('if (sel <= SEL_INSTANCE_MAX)', 'if (sel <= SEL_INSTANCE_MAX - 1)')]},
    {'name': 'negative_gate_dropped', 'edits': [
        ('if (sel < 0)\n        goto FAIL;', 'if (0)\n        goto FAIL;')]},
    {'name': 'all_branch_constant_m4', 'edits': [
        ('if (sel == SEL_ALL_INSTANCES)', 'if (sel == -4)')]},
    {'name': 'inst_table_extra_indirection', 'edits': [
        ('const var_hash_table *t = &g_inst_table;',
         'const var_hash_table *t = *(var_hash_table **)&g_inst_table;')]},
    {'name': 'inst_mask_hardcoded_511', 'edits': [
        ('((u32)sel & mask) * BUCKET_STRIDE);\n\n        /* 0x1f3d34',
         '((u32)sel & 511u) * BUCKET_STRIDE);\n\n        /* 0x1f3d34')]},
    {'name': 'obj_mask_hardcoded_511', 'edits': [
        ('((u32)sel & mask) * BUCKET_STRIDE);\n\n        /* 0x1f3e98',
         '((u32)sel & 511u) * BUCKET_STRIDE);\n\n        /* 0x1f3e98')]},
    {'name': 'id_key_offset_0x8_to_0xc', 'edits': [
        ('/* 0x1f3d54 bne  0x1f3d40         -- collision -> next node */\n'
         '            if ((u32)rd32(node + HNODE_KEY) == (u32)sel)',
         '/* 0x1f3d54 bne  0x1f3d40         -- collision -> next node */\n'
         '            if ((u32)rd32(node + HNODE_VALUE) == (u32)sel)')]},
    {'name': 'id_path_checks_0x69_too', 'edits': [
        ('if (rd8(inst + INST_DESTROYED) != 0)\n            goto FAIL;\n        /* 0x1f3d70',
         'if (rd8(inst + INST_DESTROYED) != 0 ||\n'
         '            rd8(inst + INST_DEACTIVATED) != 0)\n            goto FAIL;\n'
         '        /* 0x1f3d70')]},
    {'name': 'scan1_drops_0x69_gate', 'edits': [
        ('if (rd8(inst + INST_DESTROYED) == 0 &&\n'
         '                    rd8(inst + INST_DEACTIVATED) == 0)\n'
         '                    goto HIT1;',
         'if (rd8(inst + INST_DESTROYED) == 0 &&\n'
         '                    1)\n'
         '                    goto HIT1;')]},
    {'name': 'scan2_drops_0x68_gate', 'edits': [
        ('if (rd8(inst + INST_DESTROYED) == 0 &&\n'
         '                    rd8(inst + INST_DEACTIVATED) == 0)\n'
         '                    goto HIT2;',
         'if (1 &&\n'
         '                    rd8(inst + INST_DEACTIVATED) == 0)\n'
         '                    goto HIT2;')]},
    {'name': 'scan1_ancestor_no_walk', 'edits': [
        ("hit = ((u32)sel == idx) ? 1u : 0u;\n"
         "                if ((u32)sel == idx || nexto == 0)",
         "hit = ((u32)sel == idx) ? 1u : 0u;\n"
         "                if (1)")]},
    {'name': 'scan1_reads_list2_items', 'edits': [
        ('items = (const unsigned char *)(uintptr_t)g_scan_list1.items;',
         'items = (const unsigned char *)(uintptr_t)g_scan_list2.items;')]},
    {'name': 'scan1_count_offset_plus4', 'edits': [
        ('count = (u32)g_scan_list1.count;', 'count = (u32)g_scan_list1.pad;')]},
    {'name': 'scan_item_stride_8', 'edits': [
        ('inst = (const unsigned char *)(uintptr_t)rd32(items + i * LIST_ITEM_STRIDE);\n'
         '        /* 0x1f3d98',
         'inst = (const unsigned char *)(uintptr_t)rd32(items + i * 8);\n'
         '        /* 0x1f3d98')]},
    {'name': 'chain_next_offset_0_to_4', 'edits': [
        ('node = (const unsigned char *)(uintptr_t)rd32(node + CHAIN_NEXT);',
         'node = (const unsigned char *)(uintptr_t)rd32(node + CHAIN_NEXT + 4);')]},
    {'name': 'ogm_chain_head_0xd0_to_0xd4', 'edits': [
        ('node = (const unsigned char *)(uintptr_t)rd32(obj + OGM_INST_CHAIN);',
         'node = (const unsigned char *)(uintptr_t)rd32(obj + OGM_INST_CHAIN + 4);')]},
    {'name': 'room_next_offset_0x178_to_0x17c', 'edits': [
        ('nexto = rd32(inst + INST_ROOM_NEXT);',
         'nexto = rd32(inst + INST_ROOM_NEXT + 4);')]},
    {'name': 'room_head_offset_0x80_to_0x84', 'edits': [
        ('(const unsigned char *)(uintptr_t)g_run_room + ROOM_INST_HEAD);',
         '(const unsigned char *)(uintptr_t)g_run_room + ROOM_INST_HEAD + 4);')]},
    {'name': 'failure_flag_not_set', 'edits': [
        ('g_var_resolve_failed = 1;', 'g_var_resolve_failed = 0;')]},
    {'name': 'entry_flag_not_cleared', 'edits': [
        ('g_var_resolve_failed = 0;', 'g_var_resolve_failed = 1;')]},
    {'name': 'hit1_zeroes_arrindex', 'edits': [
        ('HIT1:\n    /* 0x1f3f58 mov  r0, r9                 -- the list-1 instance */\n'
         '    /* 0x1f3f5c pop  {r4, r5, r6, r7, r8, r9, r10, r11} */\n'
         '    /* 0x1f3f60 b    0x1f3b8c */\n'
         '    return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid, arrindex,\n'
         '                                    out);',
         'HIT1:\n    /* 0x1f3f58 mov  r0, r9                 -- the list-1 instance */\n'
         '    /* 0x1f3f5c pop  {r4, r5, r6, r7, r8, r9, r10, r11} */\n'
         '    /* 0x1f3f60 b    0x1f3b8c */\n'
         '    return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid, 0,\n'
         '                                    out);')]},
]


# ── instruction census ───────────────────────────────────────────────────────
import re  # noqa: E402  (kept next to its only user)


def _norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def instruction_census():
    """Every instruction of the original must appear in the translation as
    `0xADDR <verbatim operand text>`, and each of the seven literal-pool words
    must be documented with its value.

    This is the machine check behind "one comment line per machine
    instruction": a translation that dropped a gate, a store or an exit cannot
    pass it, and a typo in an offset shows up as a mismatch against
    llvm-objdump rather than as prose.
    """
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % ENTRY,
                        '--stop-address=%#x' % (POOL + 0x1c),
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
    src = (MOD / 'src' / 'variable_resolve.c').read_text()
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


# ── binding ──────────────────────────────────────────────────────────────────
def sha(p):
    return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()


def got_slot(o, addr):
    return struct.unpack('<I', o.read(addr, 4))[0]


def same(a, c):
    return (a['ret'] == c['ret'] and a['out'] == c['out']
            and a['flag'] == c['flag'] and a['calls'] == c['calls'])


def _digest(recs):
    return hashlib.sha256(json.dumps(
        [{k: r[k] for k in ('ret', 'out', 'flag', 'calls')} for r in recs],
        sort_keys=True).encode()).hexdigest()


def _sample(case, a, r):
    return {'case': case.label,
            'ret': {'original': a['ret'], 'mutant': r['ret']},
            'flag': {'original': a['flag'], 'mutant': r['flag']},
            'out': {'original': a['out'], 'mutant': r['out']},
            'calls': {'original': a['calls'], 'mutant': r['calls']}}


def teeth_one(m, case_list, a_recs):
    b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
    batch_detail = None
    try:
        recs = [norm_c(r) for r in run_c_arm(b, case_list)]
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
        return {'mutant': m['name'], 'caught_by': caught, 'aborted_cases': [],
                'mode': 'mismatch', 'field_level': True, 'passed': bool(caught),
                'sample_mismatch': sample}

    caught, aborted, detail, sample = [], [], {}, None
    for c, a in zip(case_list, a_recs):
        try:
            r = norm_c(run_c_arm(b, [c])[0])
        except RuntimeError as exc:
            aborted.append(c.label)
            detail[c.label] = str(exc).splitlines()[0][:120]
            continue
        if not same(a, r):
            caught.append(c.label)
            if sample is None:
                sample = _sample(c, a, r)
    rec = {'mutant': m['name'], 'caught_by': caught, 'aborted_cases': aborted,
           'mode': 'mismatch+driver-abort' if caught else 'driver-abort',
           'field_level': bool(caught), 'passed': bool(caught or aborted),
           'batch_detail': batch_detail, 'abort_detail': detail,
           'sample_mismatch': sample}
    if not caught:
        rec['note'] = ('discrimination is by abort, not by a field mismatch - '
                       'weaker than a mismatch tooth; the case set cannot say '
                       'WHICH field moved')
    return rec


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('var_resolve_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    # binding: the pinned image, and the six GOT slots this body reads
    img_sha = sha(SO)
    o = Oracle()
    got = {hex(a): got_slot(o, a) for a in GOT_SLOTS}
    got_ok = all(got[hex(a)] == v for a, v in GOT_SLOTS.items())
    census = instruction_census()

    # claim arm
    base_bin = build_c(BUILD / 'var_resolve.arm')
    c_recs = [norm_c(r) for r in run_c_arm(base_bin, case_list)]

    # judge arm
    stage = Stage(o)
    a_recs = [stage.run(c) for c in case_list]
    a_cmp = [{k: r[k] for k in ('ret', 'out', 'flag', 'calls')} for r in a_recs]

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_cmp, c_recs):
        eq = same(a, c)
        rows.append({'case': case.args(), 'label': case.label,
                     'original': a, 'rebuild': c, 'equal': eq})
        if not eq:
            mismatches.append(rows[-1])

    # repeat: a second Unicorn instance and a second qemu process must
    # reproduce both record streams.
    stage2 = Stage(Oracle())
    a_rep = [{k: r[k] for k in ('ret', 'out', 'flag', 'calls')}
             for r in (stage2.run(c) for c in case_list)]
    c_rep = [norm_c(r) for r in run_c_arm(base_bin, case_list)]
    repeat = {'original': all(same(x, y) for x, y in zip(a_cmp, a_rep)),
              'rebuild': all(same(x, y) for x, y in zip(c_recs, c_rep)),
              'original_log_sha256': [_digest(a_cmp), _digest(a_rep)],
              'rebuild_log_sha256': [_digest(c_recs), _digest(c_rep)]}

    coverage, covered_by = {}, {}
    for name, fn in COVER:
        hits = [c.label for c, a in zip(case_list, a_recs) if fn(a['tr'], a, c)]
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]

    teeth = [teeth_one(m, case_list, a_cmp) for m in MUTANTS]

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    rep_ok = all(repeat.values())
    binding_ok = img_sha == PIN and got_ok
    status = ('PASS' if (identity and cov_ok and teeth_ok and binding_ok
                         and rep_ok and census['ok']) else 'FAIL')

    receipt = {
        'schema': 'cally-var-resolve-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0x1f3ce0 executed over staged .bss cells, hash '
                           'tables, CObjectGM chains, scan lists and the room '
                           'instance chain; its tail jump lands in the ORIGINAL '
                           'Variable_GetValue_Direct @0x1f3b8c, with identical '
                           'GET_RValue / InternalGetYYVar / builtin-getter '
                           'stubs on both arms; NOT device execution'),
        'BINDING': {
            'original_sha256': img_sha,
            'original_sha256_pinned': PIN,
            'entry': hex(ENTRY),
            'function': '_Z17Variable_GetValueiiiP6RValue',
            'body_sha256': sha(MOD / 'src' / 'variable_resolve.c'),
            'header_sha256': sha(MOD / 'src' / 'variable_resolve.h'),
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'linked_callee': {
                'function': '_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue',
                'entry': hex(0x1f3b8c),
                'recovered_at': str(DIRECT_MOD / 'src' / 'variable_direct.c'),
                'body_sha256': sha(DIRECT_MOD / 'src' / 'variable_direct.c'),
                'arm': 'real link on the claim arm; original bytes on the '
                       'judge arm (not a stub)',
            },
            'got_slots': got,
            'got_slots_expected': {hex(a): hex(v) for a, v in GOT_SLOTS.items()},
            'got_match': got_ok,
            'got_rewritten': {'0x3edc40': 'builtin-variable table base -> the '
                              'oracle heap table (10000 entries do not fit the '
                              'image .bss)'},
            'stub_callees': ['GET_RValue@0xd13bc',
                             'YYObjectBase::InternalGetYYVar@0x196a70',
                             'builtin-variable table entry fn'],
            'build': 'clang --target=armv7a-none-eabi (freestanding) + qemu-arm',
        },
        'scope': {
            'covered': [
                'dispatch: sel == -3 / sel < 0 / sel > 99999 / 0..99999, '
                'decided by the original\'s own three compares',
                'room path: *(*(0x54298c))+0x80 head, next at +0x178 loaded '
                'before the gates, both liveness bytes',
                'id path: ms_ID2InstanceE bucket = id & table mask, 8 B '
                'buckets, node {+4 next, +8 id, +0xc inst}, full 32-bit key, '
                'only +0x68 gated (+0x69 deliberately not read)',
                'object path: g_ObjectHash is a POINTER VARIABLE (the extra '
                'deref at 0x1f3e84), CObjectGM +0xd0 chain {+0 next, +8 inst}, '
                'both liveness bytes',
                'both fallback lists (0x542a64 / 0x542a4c): 12 B {items, pad, '
                'count}, count <= 0 skipped, 4 B elements, ancestor walk via '
                '+0x48 comparing +0x18, both liveness bytes, scan order',
                'return contract: Direct\'s return passed through (tail jump), '
                '0 on every failure exit',
                'failure semantics: return 0 + flag 0x75505c = 1 + out byte-'
                'identical to the caller\'s preset (0x00FFFFFF tag kept)',
                'varid / arrindex passthrough: slot deltas, builtin dispatch, '
                'the [10000,99999] gap, negative varid, INT_MIN/INT_MAX '
                'arrindex',
                'Variable_GetValue_Direct runs for real on both arms',
            ],
            'not_covered': [
                'GET_RValue@0xd13bc semantics - stubbed identically on both '
                'arms, NOT recovered; a green run does not prove it',
                'YYObjectBase::InternalGetYYVar@0x196a70 - stubbed; every '
                'staged instance has a non-NULL variable table so the lazy '
                'path is never entered',
                'builtin-variable getter semantics - stubbed identical page',
                'the class identity of the two fallback lists and their +4 '
                'field (never read by this body) - cards/Variable_GetValue.c '
                'open 1',
                'varid in [10000,99999] reaching Direct with a negative slot '
                'index: the arithmetic is pinned, whether the name table can '
                'emit such an id is not (card open 2)',
                'other callers passing -1/-2 (card open 3)',
                'device behaviour: this is a synthetic-memory oracle over the '
                'original bytes, not execution on a phone',
            ],
            'observability': [
                'every staged instance has +0x24 = 1 (a non-empty variable '
                'table), so a successful resolve always reaches GET_RValue or '
                'the builtin getter - that is what makes the resolved instance '
                'observable on BOTH arms without reading a register the '
                'translation could fake',
                'every instance has its own 16 B-slot window of region S, so a '
                'G line slot delta encodes (instance, slot) even when the slot '
                'index is negative',
                'a failure case cannot say WHICH instance the original had '
                'picked before it gave up - there is nothing to observe',
            ],
            'staging_geometry': {
                'shared': 'the write program is one description interpreted by '
                          'both arms; only the region bases differ (the judge '
                          'arm uses the image\'s own .bss cells for the six '
                          'globals, the claim arm its own symbols)',
                'regions': {k: {'count': v[0], 'stride': v[1]}
                            for k, v in REGIONS.items()},
            },
        },
        'findings': [
            'the body has TWO indirection levels on the object hash and on the '
            'room, not three: 0x1f3e84 / 0x1f3f14 are the single extra load that '
            'turns the pointer variable into the structure.  The first '
            'translation added a third level on the room path (a "holder" whose '
            'word 0 is the CRoom*) and the differential caught it as five room '
            'cases where the original returned 0/flag 1 while the claim arm '
            'resolved an instance - the staging was symmetric, the C body was '
            'not.',
            'the two fallback lists are gated by a SIGNED count compare '
            '(ble on +8), so a negative count skips the list exactly like a '
            'zero one (case E14).',
            'the id path really reads only +0x68: case C5 resolves a deactivated '
            'instance by id, while C4 fails on a destroyed one; the mutant that '
            'adds the +0x69 test to the id path is caught by exactly that pair.',
            'the arithmetical "equal" bit of scan list 2 (subs/rsbs/adcs) '
            'collapses to (sel == index) - the translation keeps the flag chain '
            'and the collapse is stated at the adcs line.',
        ],
        'instruction_census': census,
        'cases': len(case_list),
        'repeat': repeat,
        'rows': rows,
        'coverage': coverage,
        'coverage_witness': covered_by,
        'teeth': teeth,
        'status': status,
    }
    out = args.out or (RECEIPTS / ('var_resolve_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d identical=%d binding=%s repeat=%s census=%d/%d'
          % (status, len(case_list), sum(1 for r in rows if r['equal']),
             'ok' if binding_ok else 'MISMATCH',
             'ok' if rep_ok else 'DRIFT',
             census['documented'], census['instructions']))
    if not census['ok']:
        for w in census['wrong'][:8]:
            print('  CENSUS %s objdump=%r source=%r'
                  % (w['addr'], w['objdump'], w['source']))
        for w in census['pool_missing'][:8]:
            print('  CENSUS pool %s word=%s undocumented' % (w['addr'], w['word']))
    for k, v in coverage.items():
        print('  COVER %-26s %s' % (k, 'yes' if v else 'NO'))
    for t in teeth:
        print('  TEETH %-32s %s mode=%-22s caught_by=%d'
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
