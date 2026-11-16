#!/usr/bin/env python3
"""The per-frame activation machinery of libyoyo ARMv7 — original-binary differential.

Three bodies from the pinned image
(3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a), all three
recovered here and all three running for real on BOTH arms:

  F1  _ZN5CRoom12UpdateActiveEv                  @0x001abd9c
      116 instructions, 0 literal-pool words, 464 B      void (CRoom* in r0)
  F2  _Z17UpdateActiveListsv                     @0x001d30a4
      42 instructions + 6 literal-pool words, 192 B      void ()
  F3  _Z27ProcessActivateDeactveListsv           @0x001d3074
      10 instructions + 2 literal-pool words, 48 B       void ()

  arm A (judge)  the original bytes, executed in Unicorn over the real .bss the
                 three bodies reach through their .got (0x542a4c / 0x542a58 /
                 0x542a64 the three queue cells, 0x757e7c the profile switch,
                 0x757e80 the CProfiler, 0x54298c the Run_Room pointer cell).
                 F2's `bl 0x1d3074` lands in F3's original bytes and F3's
                 `bl 0x1abd9c` in F1's: the cross-body link is executed as the
                 binary lays it out, not faked.
  arm B (claim)  reconstruction/reverse-v1/c/room_update/src/*.c, built for
                 armv7a-none-eabi (freestanding) and run under qemu-arm.

Why arm B must not be host-compiled: the whole point of these three bodies is
their offsets -- +0x69/+0x80/+0x178/+0x17c/+0x180/+0x184 on a CInstance,
+0x80/+0x84/+0x88/+0x8c/+0x90/+0x94 on a CRoom, a 12 B queue cell with the count
at +8.  A 64-bit host build moves every one of them.

Gates
  binding    image sha256, the six GOT slots re-derived from the bytes (one .got
             anchor 0x3f1c58 plus five negative pool words for F2, two positive
             pc-relative words for F3), and the .bss extent holding them
  census     every instruction of every body appears in its translation as
             `@0xADDR <verbatim llvm-objdump text>`, each address exactly once,
             every literal-pool word documented; the gate is itself tested by
             three source mutations that must turn it red
  identity   every case identical on both arms: the returned word, every staged
             region word-for-word (pointers normalised), every alloc block, and
             the ordered callee log
  coverage   every decision of the ORIGINAL bodies is taken, proven by their own
             instruction trace (COVER)
  repeat     both arms rerun in a second process and reproduce their records
  teeth      every source-level mutant of the translations is caught by at
             least one named case

Scope, stated up front
  * all three bodies are recovered: the claim arm links all three translations
    and the judge arm runs all three original bodies.  A green run says the
    chain's dispatch, the two chain rewrites, the three queue tests, the profile
    pairing and all four branch pairs agree; it does NOT say anything about what
    the stubbed callees do.
  * UNRECOVERED and stubbed identically on both arms: CObjectGM::AddInstance
    @0x19e02c, CObjectGM::RemoveInstance @0x19e0fc, ChangeInstanceTypes
    @0x1d2ea0, ChangeInstanceDepths @0x1d2ee8, CProfiler::Push @0x2a0738,
    CProfiler::Pop @0x2a08ac, and the harness's own bump allocator.  A green run
    proves nothing about those callees and is not device equivalence.
  * the two handler stubs CLEAR their queue count and honour an AUX knob; both
    are MODEL.  The clear matches what the cards' cross-evidence says the real
    bodies do (each handler's body re-derives its own list and stores 0 at +8);
    the knob exists only so that "the exit re-reads the profile byte" can be
    observed at all.
  * neither body allocates.  The bump arena is exercised only through the
    handler stubs' GROW model, so that "if a container grows it grows through
    the same allocator with the same fill" is a graded fact, not a comment.

Heap model, identical on both arms
  * a bump arena, 16-byte alignment, reset per case, every block prefilled with
    0xA5 over the WHOLE aligned block (FILL_BYTE, printed in the receipt).  Two
    arms filling with different bytes has cost this line a day before.

Usage
  python3 room_update_diff.py            # build, run both arms, write receipt
  python3 room_update_diff.py --no-run   # replay the gates on the last receipt
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
MOD = RV1 / 'c' / 'room_update'
BUILD = HERE / 'build' / 'room_update'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2,
    UC_ARM_REG_PC, UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

# ── the three bodies ─────────────────────────────────────────────────────────
F1, F1_END, F1_POOL = 0x1abd9c, 0x1abf6c, 0x1abf6c
F2, F2_END, F2_POOL = 0x1d30a4, 0x1d3164, 0x1d314c
F3, F3_END, F3_POOL = 0x1d3074, 0x1d30a4, 0x1d309c

FUNCS = {
    1: {'name': 'CRoom_UpdateActive', 'entry': F1, 'end': F1_END, 'pool': F1_POOL,
        'src': 'CRoom_UpdateActive.c', 'npool': 0, 'ninstr': 116},
    2: {'name': 'UpdateActiveLists', 'entry': F2, 'end': F2_END, 'pool': F2_POOL,
        'src': 'UpdateActiveLists.c', 'npool': 6, 'ninstr': 42},
    3: {'name': 'ProcessActivateDeactveLists', 'entry': F3, 'end': F3_END,
        'pool': F3_POOL, 'src': 'ProcessActivateDeactveLists.c', 'npool': 2,
        'ninstr': 10},
}

# ── callees ──────────────────────────────────────────────────────────────────
CG_ADD = 0x19e02c
CG_REM = 0x19e0fc
CH_TYP = 0x1d2ea0
CH_DEP = 0x1d2ee8
CP_PUSH = 0x2a0738
CP_POP = 0x2a08ac

MAGIC_ADD = 0x0B1EC7A1
MAGIC_REM = 0x0B1EC7B2
MAGIC_TYP = 0x0C7A0001
MAGIC_DEP = 0x0CDE0002
MAGIC_PSH = 0x0C9F0003
MAGIC_POP = 0x0C9F0004

AUX_FLIP = 0x5017          # "a handler switches profiling off" knob (model)
GROW_MAX = 8
SEED = 0x5a5a5a5a          # r0 for the two argument-less entries

# ── GOT slots -> .bss cells (read out of the pinned image, re-checked at run) ─
GOT_SLOTS = {
    0x3edb70: 0x757e7c,   # profile switch byte      F2
    0x3edb74: 0x757e80,   # the CProfiler object     F2
    0x3edc50: 0x542a4c,   # list A, activation       F2 (and F3 clears +8)
    0x3edc48: 0x542a64,   # list B, object type      F2
    0x3ee0ac: 0x542a58,   # list C, depth            F2
    0x3ed930: 0x54298c,   # Run_Room, a POINTER cell F3
}

# Re-derived from the bytes at run time, because a card once had a slot off by
# one: F2 reaches its five cells through ONE .got anchor, materialised as
# `ldr r4,[pc,#0x9c]` + `add r4,pc,r4` (pc = instruction + 8), then
# `ldr r3,[pc,#imm]` (a NEGATIVE pool word) + `ldr r3,[r4,r3]`.  F3 uses the
# simpler positive `ldr r3,[pc,r3]` form twice.
# `add r4, pc, r4` at 0x1d30b0, so pc there is 0x1d30b8 (the card's arithmetic)
ANCHOR_ADD, ANCHOR_POOL = 0x1d30b0, 0x1d314c
ANCHOR_WANT = 0x3f1c58
# (name, kind, the `ldr rX,[pc,rX]`/`add r4,pc,r4` instruction, pool word
#  address, the slot it must land on)
GOT_DERIVATION = [
    ('UpdateActiveLists/switch', 'anchor', 0x1d30b4, 0x1d3150, 0x3edb70),
    ('UpdateActiveLists/profiler', 'anchor', 0x1d30b4, 0x1d3160, 0x3edb74),
    ('UpdateActiveLists/listA', 'anchor', 0x1d30b4, 0x1d3154, 0x3edc50),
    ('UpdateActiveLists/listB', 'anchor', 0x1d30b4, 0x1d3158, 0x3edc48),
    ('UpdateActiveLists/listC', 'anchor', 0x1d30b4, 0x1d315c, 0x3ee0ac),
    ('ProcessActivateDeactveLists/room', 'pc', 0x1d307c, 0x1d309c, 0x3ed930),
    ('ProcessActivateDeactveLists/listA', 'pc', 0x1d3090, 0x1d30a0, 0x3edc50),
]
BSS_SWITCH = 0x757e7c
BSS_PROFILER = 0x757e80
BSS_LIST_A = 0x542a4c
BSS_LIST_B = 0x542a64
BSS_LIST_C = 0x542a58
BSS_RUN_ROOM = 0x54298c

FILL_BYTE = 0xA5
ALIGN = 16

# ── the staged object graph ─────────────────────────────────────────────────
# (id, count, stride) — the driver's REGIONS array is the same list.
REGIONS = [
    ('R', 1, 0x120),      # CRoom
    ('I', 8, 0x188),      # CInstance
    ('O', 8, 0x10),       # one CObjectGM cell per instance
    ('A', 8, 4),          # list A's item array
    ('T', 8, 4),          # list B's item array
    ('D', 8, 4),          # list C's item array
    ('Q', 1, 12),         # 0x542a4c  list A cell
    ('C', 1, 12),         # 0x542a58  list C cell
    ('B', 1, 12),         # 0x542a64  list B cell
    ('W', 1, 4),          # 0x757e7c  profile switch (low byte read)
    ('F', 1, 4),          # 0x757e80  the CProfiler object
    ('S', 1, 4),          # 0x54298c  Run_Room (a POINTER cell)
]
REG = {r: (c, s) for r, c, s in REGIONS}
FIXED_REGION = {'Q': BSS_LIST_A, 'C': BSS_LIST_C, 'B': BSS_LIST_B,
                'W': BSS_SWITCH, 'F': BSS_PROFILER, 'S': BSS_RUN_ROOM}
LISTOF = {'Q': 'A', 'C': 'D', 'B': 'T'}   # queue cell -> its item array

# field offsets, mirrored from room_update.h
ROOM_A_TAIL, ROOM_A_HEAD, ROOM_A_COUNT = 0x80, 0x84, 0x88
ROOM_B_TAIL, ROOM_B_HEAD, ROOM_B_COUNT = 0x8c, 0x90, 0x94
INST_DEACT, INST_GM = 0x69, 0x80
INST_PREV, INST_NEXT, INST_DEPTH, INST_SNAP = 0x178, 0x17c, 0x180, 0x184
LIST_ITEMS, LIST_AUX, LIST_COUNT = 0x0, 0x4, 0x8


def fb(x):
    """float -> its 32-bit pattern."""
    return struct.unpack('<I', struct.pack('<f', x))[0]


# ── case description ─────────────────────────────────────────────────────────
class Case:
    """One input plus the staging program both arms interpret.

    The program is a list of writes `(region, index, offset, kind, a, b)`:
    kind 0 stores `a`, kind 1 stores base(a) + b*stride(a).  The two arms supply
    their own region bases, so the same program stages the same graph at
    different addresses - and no case can self-certify: the gates are judged on
    the ORIGINAL arm's instruction trace and on the compared facets.
    """

    def __init__(self, fn, label=''):
        self.fn = fn
        self.label = label
        self.w = []
        self._base()

    # -- writers ------------------------------------------------------------
    def lit(self, reg, idx, off, v):
        self._check(reg, idx, off)
        self.w.append((reg, idx, off, 0, v & 0xffffffff, 0))
        return self

    def ptr(self, reg, idx, off, src, sidx):
        self._check(reg, idx, off)
        self._check(src, sidx, 0)
        self.w.append((reg, idx, off, 1, ord(src), sidx))
        return self

    def byte(self, reg, idx, off, v):
        """A byte field inside a word: store the value at its own byte lane.

        The bodies read +0x69 with `ldrb` and the two cells either side of it
        are unrelated words, so the staging program writes the containing word
        with the byte placed where the ldrb will find it."""
        return self.lit(reg, idx, off & ~3, (v & 0xff) << ((off & 3) * 8))

    @staticmethod
    def _check(reg, idx, off):
        """A write outside its region corrupts the next one on the claim arm
        (static arrays) and lands in unrelated heap on the judge arm: refuse."""
        count, stride = REG[reg]
        if not (0 <= idx < count) or not (0 <= off <= stride - 4):
            raise IndexError('write outside region %s: idx=%d off=%#x'
                             % (reg, idx, off))

    # -- structure helpers --------------------------------------------------
    def _base(self):
        self.lit('R', 0, ROOM_A_HEAD, 0).lit('R', 0, ROOM_A_TAIL, 0)
        self.lit('R', 0, ROOM_A_COUNT, 0)
        self.lit('R', 0, ROOM_B_HEAD, 0).lit('R', 0, ROOM_B_TAIL, 0)
        self.lit('R', 0, ROOM_B_COUNT, 0)
        self.ptr('S', 0, 0, 'R', 0)          # Run_Room -> the staged room
        for i in range(REG['I'][0]):
            self.ptr('I', i, INST_GM, 'O', i)  # every instance owns a cell
        for q in ('Q', 'C', 'B'):
            self.lit(q, 0, LIST_ITEMS, 0).lit(q, 0, LIST_AUX, 0)
            self.lit(q, 0, LIST_COUNT, 0)
        return self

    def room(self, a_head=None, a_tail=None, a_count=None, b_head=None,
             b_tail=None, b_count=None):
        if a_head is not None:
            self.ptr('R', 0, ROOM_A_HEAD, 'I', a_head)
        if a_tail is not None:
            self.ptr('R', 0, ROOM_A_TAIL, 'I', a_tail)
        if a_count is not None:
            self.lit('R', 0, ROOM_A_COUNT, a_count)
        if b_head is not None:
            self.ptr('R', 0, ROOM_B_HEAD, 'I', b_head)
        if b_tail is not None:
            self.ptr('R', 0, ROOM_B_TAIL, 'I', b_tail)
        if b_count is not None:
            self.lit('R', 0, ROOM_B_COUNT, b_count)
        return self

    def inst(self, i, deact=0, depth=0.0, snap=None, depth_bits=None,
             snap_bits=None):
        self.byte('I', i, INST_DEACT, 1 if deact else 0)
        self.lit('I', i, INST_DEPTH,
                 depth_bits if depth_bits is not None else fb(depth))
        self.lit('I', i, INST_SNAP,
                 snap_bits if snap_bits is not None else fb(depth if snap is None
                                                          else snap))
        return self

    def chain(self, which, ids, count=None, count_raw=None):
        """Wire a chain: room head/tail and every instance's prev/next."""
        if which == 'A':
            head, tail, cnt = ROOM_A_HEAD, ROOM_A_TAIL, ROOM_A_COUNT
        else:
            head, tail, cnt = ROOM_B_HEAD, ROOM_B_TAIL, ROOM_B_COUNT
        for k, i in enumerate(ids):
            if k:
                self.ptr('I', i, INST_PREV, 'I', ids[k - 1])
            else:
                self.lit('I', i, INST_PREV, 0)
            if k + 1 < len(ids):
                self.ptr('I', i, INST_NEXT, 'I', ids[k + 1])
            else:
                self.lit('I', i, INST_NEXT, 0)
        self.ptr('R', 0, head, 'I', ids[0])
        self.ptr('R', 0, tail, 'I', ids[-1])
        if count_raw is not None:
            self.lit('R', 0, cnt, count_raw & 0xffffffff)
        else:
            self.lit('R', 0, cnt, len(ids) if count is None else count)
        return self

    def queue(self, which, arr=None, aux=0, count=None):
        """Stage one queue cell; `arr` stages that many instance pointers.

        `which` is the .bss cell's region letter: 'Q' activation, 'C' depth,
        'B' object type.  'T' is accepted as an alias for the type queue so a
        case can name the queue rather than the cell.
        """
        which = 'B' if which == 'T' else which
        if arr:
            for k, i in enumerate(arr):
                self.ptr(LISTOF[which], k, 0, 'I', i)
            self.ptr(which, 0, LIST_ITEMS, LISTOF[which], 0)
        else:
            self.lit(which, 0, LIST_ITEMS, 0)
        self.lit(which, 0, LIST_AUX, aux & 0xffffffff)
        n = count if count is not None else (len(arr) if arr else 0)
        self.lit(which, 0, LIST_COUNT, n & 0xffffffff)
        return self

    def switch(self, v):
        return self.lit('W', 0, 0, v & 0xff)

    def args(self):
        return (self.fn, 0, 0, 0)

    def line(self):
        out = ['%d 0 0 0 %d' % (self.fn, len(self.w))]
        for (reg, idx, off, kind, a, b) in self.w:
            out.append('%s %d %d %d %d %d' % (reg, idx, off, kind, a, b))
        return '\n'.join(out) + '\n'


def cases():
    """Deterministic; same list, same order, on every run."""
    C = []
    add = C.append

    # ══ F1 · CRoom::UpdateActive: the two chains ═══════════════════════════
    add(Case(1, 'F1-a both chains empty: no walk, no call, r0 residue = room'))
    add(Case(1, 'F1-b one ACTIVE instance in the dormant chain: moved into an '
                'empty active chain')
        .inst(0, depth=5.5).chain('B', [0]))
    add(Case(1, 'F1-c the same node INACTIVE: branch 2, nothing moves, no call')
        .inst(0, deact=1, depth=5.5).chain('B', [0]))
    add(Case(1, 'F1-d two active nodes from the dormant TAIL: the first fills '
                'the empty chain, the second walks past it (tail append)')
        .inst(1, depth=3.0).inst(0, depth=5.0).chain('B', [1, 0]))
    add(Case(1, 'F1-e one ACTIVE node in the active chain: branch 4, nothing '
                'moves')
        .inst(0, depth=5.5).chain('A', [0]))
    add(Case(1, 'F1-f two INACTIVE nodes in the active chain: dormant chain '
                'empty first, then a head insert')
        .inst(0, deact=1, depth=9.0).inst(1, deact=1, depth=1.0)
        .chain('A', [0, 1]))
    add(Case(1, 'F1-g mixed active chain: tail-first walk, branch 4, branch 3, '
                'branch 3')
        .inst(0, depth=9.0).inst(1, deact=1, depth=5.0)
        .inst(2, deact=1, depth=1.0).chain('A', [0, 1, 2]))
    add(Case(1, 'F1-h both phases in one call: the node phase 1 inserted is '
                'walked again by phase 2 and left alone')
        .inst(0, deact=1, depth=9.0).inst(1, depth=5.0).inst(2, depth=7.0)
        .chain('A', [0, 1]).chain('B', [2]))
    add(Case(1, 'F1-i insert in the MIDDLE of the active chain (splice in front '
                'of a non-head node)')
        .inst(0, depth=9.0).inst(1, depth=4.0).inst(2, depth=2.0)
        .inst(3, depth=5.0).chain('A', [0, 1, 2]).chain('B', [3]))
    add(Case(1, 'F1-j insert at the HEAD: deeper than every node, so room+0x84 '
                'moves')
        .inst(0, depth=9.0).inst(1, depth=4.0).inst(3, depth=99.0)
        .chain('A', [0, 1]).chain('B', [3]))
    add(Case(1, 'F1-k EQUAL depth: bls puts the new node in FRONT of the equal '
                'one')
        .inst(0, depth=5.0).inst(1, depth=5.0)
        .chain('A', [0]).chain('B', [1]))
    add(Case(1, 'F1-l sort key is the SNAPSHOT +0x184, not the live depth')
        .inst(0, depth=1.0, snap=9.0).inst(1, depth=5.0)
        .chain('A', [0]).chain('B', [1]))
    add(Case(1, 'F1-m NaN as the NEW depth: VCMP unordered -> bls not taken -> '
                'walk past -> the node lands at the TAIL')
        .inst(0, depth=5.0).inst(1, depth_bits=0x7fc00000)
        .chain('A', [0]).chain('B', [1]))
    add(Case(1, 'F1-n NaN as the CURSOR snapshot: unordered -> bls not taken, '
                'the walk steps over it and the node lands at the TAIL')
        .inst(0, depth=5.0, snap_bits=0x7fc00000).inst(1, depth=1.0)
        .chain('A', [0]).chain('B', [1]))
    add(Case(1, 'F1-o eight instances, four in each chain, mixed flags')
        .inst(0, depth=8.0).inst(1, deact=1, depth=6.0)
        .inst(2, depth=4.0).inst(3, deact=1, depth=2.0)
        .inst(4, depth=7.0).inst(5, deact=1, depth=3.0)
        .inst(6, depth=1.0)
        .chain('A', [0, 1, 2, 3]).chain('B', [6, 5, 4]))
    add(Case(1, 'F1-p dormant count staged 0: the unconditional `sub` takes it '
                'to 0xffffffff (no clamp, no sign test)')
        .inst(0, depth=5.0).chain('B', [0], count_raw=0))
    add(Case(1, 'F1-q single inactive node is the whole active chain: both the '
                'head and the tail must go to 0')
        .inst(0, deact=1, depth=5.0).chain('A', [0]))
    add(Case(1, 'F1-r active chain all active, dormant chain all inactive: '
                'neither phase moves anything')
        .inst(0, depth=3.0).inst(1, depth=2.0)
        .inst(2, deact=1, depth=2.0).inst(3, deact=1, depth=1.0)
        .chain('A', [0, 1]).chain('B', [2, 3]))
    add(Case(1, 'F1-s the CObjectGM argument is READ OUT OF inst+0x80 (two '
                'instances, two different cells)')
        .inst(0, depth=5.0).inst(1, depth=4.0)
        .chain('B', [1, 0]))
    add(Case(1, 'F1-t active count staged 0xffffffff and one node moved in: '
                '`add #1` wraps it to 0')
        .inst(0, depth=2.0).chain('B', [0]).room(a_count=0xffffffff))

    # ══ F2 · UpdateActiveLists: the three queue tests ══════════════════════
    add(Case(2, 'F2-a profile off, all three counts 0: no handler, no profiler'))
    add(Case(2, 'F2-b only the ACTIVATION queue is non-empty: handler A runs '
                'and clears its own count')
        .queue('Q', arr=[0], count=1).inst(0, depth=5.0).chain('B', [0]))
    add(Case(2, 'F2-c a whole frame: all three queues non-empty, a mixed room, '
                'handlers run A (which rewrites the chains) then B then C')
        .queue('Q', arr=[0, 1], count=2).queue('T', arr=[2, 3], count=2)
        .queue('C', arr=[4], count=1)
        .inst(0, deact=1, depth=9.0).inst(1, depth=5.0)
        .inst(2, depth=6.0).inst(3, depth=2.0).inst(4, depth=7.0)
        .inst(5, deact=1, depth=3.0)
        .chain('A', [0, 1]).chain('B', [5, 2]))
    add(Case(2, 'F2-d only the TYPE queue: handler B alone')
        .queue('T', arr=[1], count=1).inst(1, depth=4.0))
    add(Case(2, 'F2-e only the DEPTH queue: handler C runs last and returns to '
                'the exit')
        .queue('C', arr=[2], count=1).inst(2, depth=3.0))
    add(Case(2, 'F2-f profile ON with empty queues: Push(6,7) then Pop, same '
                'object')
        .switch(1))
    add(Case(2, 'F2-g count -1 on the TYPE queue: `cmp/bne` is a NON-ZERO test, '
                'so the handler still runs')
        .queue('T', arr=[1], count=0xffffffff).inst(1, depth=4.0))
    add(Case(2, 'F2-h count 0x80000000 on the DEPTH queue: still non-zero')
        .queue('C', arr=[2], count=0x80000000).inst(2, depth=3.0))
    add(Case(2, 'F2-i count 5 with a NULL item array: the flusher never '
                'dereferences the array, only the count')
        .queue('T', count=5))
    add(Case(2, 'F2-j profile ON and the type handler clears the switch '
                'mid-frame: Push without Pop (the byte is re-read at the exit)')
        .switch(1).queue('T', arr=[1], aux=AUX_FLIP, count=2)
        .inst(1, depth=4.0))
    add(Case(2, 'F2-k profile off, the activation queue holds three entries and '
                'the room really flushes')
        .queue('Q', arr=[0, 1, 2], count=3)
        .inst(0, deact=1, depth=9.0).inst(1, depth=5.0).inst(2, depth=7.0)
        .chain('A', [0, 1]).chain('B', [2]))
    add(Case(2, 'F2-l profile ON over an empty room: Push, handler A on an '
                'empty chain, Pop')
        .switch(1).queue('Q', count=1))
    add(Case(2, 'F2-m A and C non-empty, B empty: the order is A -> (B) -> C')
        .queue('Q', arr=[0], count=1).queue('C', arr=[2], count=1)
        .inst(0, depth=5.0).inst(2, depth=3.0).chain('B', [0]))
    add(Case(2, 'F2-n only the TYPE cell is non-empty: the other two cells are '
                'at +8 of their own addresses, not of this one')
        .queue('B', arr=[1], count=1).queue('Q', count=0).queue('C', count=0)
        .inst(1, depth=4.0))
    add(Case(2, 'F2-o count -1 on the ACTIVATION queue: handler A runs too')
        .queue('Q', arr=[0], count=0xffffffff).inst(0, depth=5.0)
        .chain('B', [0]))

    # ══ F3 · ProcessActivateDeactveLists: the singleton hop ════════════════
    add(Case(3, 'F3-a reads the room out of *0x54298c, runs UpdateActive, '
                'clears the count')
        .queue('Q', arr=[0], count=7).inst(0, depth=5.0).chain('B', [0]))
    add(Case(3, 'F3-b empty room: the count is still cleared, r0 is '
                "UpdateActive's residue (== room)")
        .queue('Q', count=0))
    add(Case(3, "F3-c the Run_Room cell is what is used, not the caller's r0")
        .queue('Q', arr=[0], count=2).inst(0, deact=1, depth=5.0)
        .chain('A', [0]))
    return C


# ── coverage ────────────────────────────────────────────────────────────────
# Two kinds of proof, and the receipt says which is which:
#   * tk() - CONTROL FLOW, from the original arm's instruction trace.  A branch
#     is a real decision: the next trace entry is the target.
#   * state/log predicates - the PREDICATED store runs (F1's 0x1abddc..0x1abdfc,
#     0x1abee4..0x1abf04, 0x1abf24..0x1abf44) and the calls.  A predicated-off
#     instruction still fires Unicorn's code hook, so the trace cannot tell the
#     two halves apart; what CAN is the memory the half wrote.
def tk(tr, a, b):
    """a is immediately followed by b in the trace."""
    for i in range(len(tr) - 1):
        if tr[i] == a and tr[i + 1] == b:
            return True
    return False


def logtoks(r):
    """Every logged call, split into tokens."""
    return [c.split() for c in r['calls']]


def calls(r, name):
    """The logged calls with this name, each split into its tokens."""
    return [p for p in logtoks(r) if p and p[0] == name]


def W(st, reg, off):
    return st[reg][off // 4]


def Iw(st, i, off):
    return st['I'][(i * 0x188 + off) // 4]


def iid(tok):
    """'I3' or 'I3+8' -> 3."""
    return int(tok[1:].split('+')[0])


def moved(r):
    """The instances an AddInstance was logged for, as region tokens."""
    return [c[2] for c in calls(r, 'CGAI')]


def dropped(r):
    return [c[2] for c in calls(r, 'CGRI')]


def staged(c, reg, off, idx=0):
    """The last word the case's staging program wrote at (reg, idx, off)."""
    v = 0
    for (r, i, o, kind, a, b) in c.w:
        if r == reg and i == idx and o == off:
            v = a
    return v


def staged_deact(c, i):
    """The inst+0x69 byte the case staged (the containing word is at +0x68)."""
    return (staged(c, 'I', INST_DEACT & ~3, idx=i) >> ((INST_DEACT & 3) * 8)) & 0xff


def order(r, names):
    got = [p[0] for p in logtoks(r) if p[0] in names]
    return got == names


COVER = [
    # ── F1 · phase 1 control flow ─────────────────────────────────────────
    ('f1_p1_empty_chain', lambda tr, r, c: tk(tr, 0x1abdac, 0x1abdb0)
     and tk(tr, 0x1abdb0, 0x1abe64)),
    ('f1_p1_first_node', lambda tr, r, c: tk(tr, 0x1abdac, 0x1abdc0)),
    ('f1_p1_skip_inactive', lambda tr, r, c: tk(tr, 0x1abdcc, 0x1abdb4)),
    ('f1_p1_cursor_step', lambda tr, r, c: tk(tr, 0x1abe60, 0x1abdbc)),
    ('f1_p1_loop_end', lambda tr, r, c: tk(tr, 0x1abe60, 0x1abe64)),
    ('f1_p1_prev_zero_exit', lambda tr, r, c: tk(tr, 0x1abdb8, 0x1abe64)),
    ('f1_a_walk_steps', lambda tr, r, c: tk(tr, 0x1abe38, 0x1abe20)),
    ('f1_move_b_to_a', lambda tr, r, c: bool(calls(r, 'CGAI'))),
    ('f1_reactivate_moves_in', lambda tr, r, c: any(
        staged_deact(c, iid(m)) == 0 for m in moved(r))),
    ('f1_deactivate_moves_out', lambda tr, r, c: any(
        staged_deact(c, iid(m)) != 0 for m in dropped(r))),
    ('f1_p2_walk_steps', lambda tr, r, c: tk(tr, 0x1abe80, 0x1abe84)),
    # ── F1 · the active-chain insert, three flavours ──────────────────────
    ('f1_a_insert_empty', lambda tr, r, c: any(
        W(r['state'], 'R', ROOM_A_HEAD) == m
        and W(r['state'], 'R', ROOM_A_TAIL) == m
        and Iw(r['state'], iid(m), INST_PREV) == '00000000'
        and Iw(r['state'], iid(m), INST_NEXT) == '00000000' for m in moved(r))),
    ('f1_a_walk_off_the_end', lambda tr, r, c: tk(tr, 0x1abe38, 0x1abe3c)),
    ('f1_a_tail_append', lambda tr, r, c: tk(tr, 0x1abe38, 0x1abe3c) and any(
        W(r['state'], 'R', ROOM_A_TAIL) == m
        and Iw(r['state'], iid(m), INST_NEXT) == '00000000'
        for m in moved(r))),
    ('f1_a_stop_at_node', lambda tr, r, c: tk(tr, 0x1abe2c, 0x1abf1c)),
    ('f1_a_insert_head', lambda tr, r, c: any(
        W(r['state'], 'R', ROOM_A_HEAD) == m
        and Iw(r['state'], iid(m), INST_PREV) == '00000000'
        and Iw(r['state'], iid(m), INST_NEXT).startswith('I') for m in moved(r))),
    ('f1_a_insert_middle', lambda tr, r, c: any(
        Iw(r['state'], iid(m), INST_PREV).startswith('I')
        and Iw(r['state'], iid(m), INST_NEXT).startswith('I')
        for m in moved(r))),
    ('f1_nan_sinks_to_the_tail', lambda tr, r, c: (
        any(reg == 'I' and off in (INST_DEPTH, INST_SNAP) and val == 0x7fc00000
            for (reg, _i, off, _k, val, _b) in c.w)
        and tk(tr, 0x1abe38, 0x1abe3c)
        and any(W(r['state'], 'R', ROOM_A_TAIL) == m for m in moved(r)))),
    ('f1_snapshot_refreshed', lambda tr, r, c: any(
        Iw(r['state'], iid(m), INST_SNAP) == Iw(r['state'], iid(m), INST_DEPTH)
        for m in moved(r))),
    # ── F1 · phase 2 control flow ─────────────────────────────────────────
    ('f1_p2_empty_return', lambda tr, r, c: tk(tr, 0x1abe68, 0x1abe6c)),
    ('f1_p2_enter', lambda tr, r, c: tk(tr, 0x1abe6c, 0x1abe70)),
    ('f1_p2_skip_active', lambda tr, r, c: tk(tr, 0x1abe90, 0x1abe78)),
    ('f1_p2_prev_zero_exit', lambda tr, r, c: tk(tr, 0x1abe78, 0x1abe7c)
     or tk(tr, 0x1abf14, 0x1abf18)),
    ('f1_p2_loop_edge', lambda tr, r, c: tk(tr, 0x1abf14, 0x1abe80)),
    ('f1_move_a_to_b', lambda tr, r, c: bool(calls(r, 'CGRI'))),
    ('f1_b_insert_empty', lambda tr, r, c: any(
        W(r['state'], 'R', ROOM_B_HEAD) == m
        and W(r['state'], 'R', ROOM_B_TAIL) == m
        and Iw(r['state'], iid(m), INST_PREV) == '00000000'
        for m in dropped(r))),
    ('f1_b_head_insert', lambda tr, r, c: any(
        W(r['state'], 'R', ROOM_B_HEAD) == m
        and Iw(r['state'], iid(m), INST_NEXT).startswith('I')
        and W(r['state'], 'R', ROOM_B_TAIL) != m for m in dropped(r))),
    # ── F1 · the bookkeeping and the arguments ────────────────────────────
    ('f1_counts_move_together', lambda tr, r, c: (
        bool(calls(r, 'CGAI') or calls(r, 'CGRI'))
        and (int(W(r['state'], 'R', ROOM_A_COUNT), 16)
             + int(W(r['state'], 'R', ROOM_B_COUNT), 16)) & 0xffffffff
        == (staged(c, 'R', ROOM_A_COUNT) + staged(c, 'R', ROOM_B_COUNT))
        & 0xffffffff)),
    ('f1_active_count_wraps_to_zero', lambda tr, r, c: (
        staged(c, 'R', ROOM_A_COUNT) == 0xffffffff
        and W(r['state'], 'R', ROOM_A_COUNT) == '00000000')),
    ('f1_dormant_count_wraps', lambda tr, r, c: (
        W(r['state'], 'R', ROOM_B_COUNT) == 'ffffffff')),
    ('f1_hook_first_arg_is_inst_plus_0x80', lambda tr, r, c: any(
        x[1].startswith('O') for x in calls(r, 'CGAI') + calls(r, 'CGRI'))),
    ('f1_hook_second_arg_is_the_instance', lambda tr, r, c: any(
        x[2].startswith('I') for x in calls(r, 'CGAI') + calls(r, 'CGRI'))),
    ('f1_hook_args_differ_per_instance', lambda tr, r, c: len(
        {x[1] for x in calls(r, 'CGAI') + calls(r, 'CGRI')}) > 1),
    # ── F2 · the three tests and the order ────────────────────────────────
    ('f2_check_a_taken', lambda tr, r, c: tk(tr, 0x1d30d4, 0x1d312c)),
    ('f2_check_a_not_taken', lambda tr, r, c: tk(tr, 0x1d30d4, 0x1d30d8)),
    ('f2_check_b_taken', lambda tr, r, c: tk(tr, 0x1d30e8, 0x1d3124)),
    ('f2_check_b_not_taken', lambda tr, r, c: tk(tr, 0x1d30e8, 0x1d30ec)),
    ('f2_check_c_taken', lambda tr, r, c: tk(tr, 0x1d30fc, 0x1d311c)),
    ('f2_check_c_not_taken', lambda tr, r, c: tk(tr, 0x1d30fc, 0x1d3100)),
    ('f2_after_a_goes_to_b', lambda tr, r, c: tk(tr, 0x1d3130, 0x1d30d8)),
    ('f2_after_b_goes_to_c', lambda tr, r, c: tk(tr, 0x1d3128, 0x1d30ec)),
    ('f2_after_c_goes_to_exit', lambda tr, r, c: tk(tr, 0x1d3120, 0x1d3100)),
    ('f2_nonzero_count_negative_type', lambda tr, r, c: (
        bool(calls(r, 'CTYP'))
        and staged(c, 'B', LIST_COUNT) == 0xffffffff)),
    ('f2_nonzero_count_int_min_depth', lambda tr, r, c: (
        bool(calls(r, 'CDEP'))
        and staged(c, 'C', LIST_COUNT) == 0x80000000)),
    ('f2_nonzero_count_negative_activation', lambda tr, r, c: (
        bool(calls(r, 'CGAI'))
        and staged(c, 'Q', LIST_COUNT) == 0xffffffff)),
    ('f2_count_cleared_by_handler', lambda tr, r, c: (
        bool(calls(r, 'CTYP')) and W(r['state'], 'B', LIST_COUNT) == '00000000')),
    ('f2_all_three_in_order', lambda tr, r, c: order(
        r, ['CGAI', 'CTYP', 'CDEP'])),
    ('f2_middle_handler_skipped', lambda tr, r, c: (
        bool(calls(r, 'CGAI')) and bool(calls(r, 'CDEP'))
        and not calls(r, 'CTYP'))),
    # ── F2 · the profile pair ─────────────────────────────────────────────
    ('f2_profile_push', lambda tr, r, c: tk(tr, 0x1d30c0, 0x1d3134)
     and any(x[2] == '00000006' and x[3] == '00000007'
             for x in calls(r, 'CPUSH'))),
    ('f2_profile_pop', lambda tr, r, c: bool(calls(r, 'CPOP'))),
    ('f2_profile_off_no_pop', lambda tr, r, c: not calls(r, 'CPOP')),
    ('f2_profile_switch_reread', lambda tr, r, c: bool(calls(r, 'CPUSH'))
     and not calls(r, 'CPOP') and bool(calls(r, 'SWOFF'))),
    ('f2_push_pop_same_object', lambda tr, r, c: any(
        p[1] == q[1] for p in calls(r, 'CPUSH') for q in calls(r, 'CPOP'))),
    # ── F2/F3 · the grow model and the singleton hop ──────────────────────
    ('f2_grow_allocates', lambda tr, r, c: any(
        x[3] != '00000000' and x[4] != '00000000' for x in calls(r, 'GROW'))),
    ('f2_grow_skipped', lambda tr, r, c: any(
        x[4] == '00000000' for x in calls(r, 'GROW'))),
    ('f2_type_queue_names_its_entries', lambda tr, r, c: bool(calls(r, 'CTYP'))
     and any(x[1] != '00000000' and x[3] != '00000000'
             for x in calls(r, 'GROW'))),
    ('f3_reads_the_run_room_cell', lambda tr, r, c: tk(tr, 0x1d3080, 0x1d3084)),
    ('f3_clears_the_queue', lambda tr, r, c: tk(tr, 0x1d3094, 0x1d3098)
     and W(r['state'], 'Q', LIST_COUNT) == '00000000'),
    ('f3_returns_update_active_r0', lambda tr, r, c: bool(calls(r, 'CGAI'))
     and r['ret'] == '%08x' % MAGIC_ADD),
    ('f3_residue_is_room', lambda tr, r, c: not calls(r, 'CGAI')
     and not calls(r, 'CGRI') and r['ret'].startswith('R')),
]


# ── original arm ────────────────────────────────────────────────────────────
class Stage:
    """One staged environment; hooks installed once.

    Per case only the region contents are rewritten and the log cleared.  Adding
    hooks per case would leave the previous case's hooks live on the same
    Unicorn instance, and they would keep appending to their own logs.
    """

    def __init__(self, o):
        self.o = o
        self.log = []
        self.tr = []
        self.base = {}
        for reg, count, stride in REGIONS:
            if reg in FIXED_REGION:
                self.base[reg] = FIXED_REGION[reg]
            else:
                self.base[reg] = o.alloc(count * stride)
        self.heap_start = o.heap
        self.allocs = []
        for addr, fn in ((CG_ADD, self.hook_add), (CG_REM, self.hook_rem),
                         (CH_TYP, self.hook_typ), (CH_DEP, self.hook_dep),
                         (CP_PUSH, self.hook_push), (CP_POP, self.hook_pop)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        for lo, hi in ((F1, F1_END - 4), (F2, F2_END - 4), (F3, F3_END - 4)):
            o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=lo, end=hi)

    # -- hooks --------------------------------------------------------------
    def hook_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def _ret(self, uc_, v):
        uc_.reg_write(UC_ARM_REG_R0, v & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_add(self, uc_, _a, _s, _d):
        self.log.append(['CGAI', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff])
        self._ret(uc_, MAGIC_ADD)

    def hook_rem(self, uc_, _a, _s, _d):
        self.log.append(['CGRI', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff])
        self._ret(uc_, MAGIC_REM)

    def hook_push(self, uc_, _a, _s, _d):
        self.log.append(['CPUSH', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff])
        self._ret(uc_, MAGIC_PSH)

    def hook_pop(self, uc_, _a, _s, _d):
        self.log.append(['CPOP', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff])
        self._ret(uc_, MAGIC_POP)

    def hook_typ(self, uc_, _a, _s, _d):
        self._ret(uc_, self.handler('CTYP', BSS_LIST_B, MAGIC_TYP))

    def hook_dep(self, uc_, _a, _s, _d):
        self._ret(uc_, self.handler('CDEP', BSS_LIST_C, MAGIC_DEP))

    def handler(self, name, cell, magic):
        """The stub model, mirrored cell for cell by driver.c.

        Log the list, GROW the queue through the same bump arena, honour the AUX
        flip knob, clear the count, return a distinctive word.
        """
        self.log.append([name, cell])
        items = self.rd32(cell + LIST_ITEMS)
        aux = self.rd32(cell + LIST_AUX)
        count = self.rd32(cell + LIST_COUNT)
        n = count if 1 <= count <= GROW_MAX else 0
        p = 0
        if n and items:
            size = (n * 4 + ALIGN - 1) // ALIGN * ALIGN
            p = self.o.alloc(size, ALIGN)
            self.o.write(p, bytes([FILL_BYTE]) * size)
            for k in range(n):
                self.o.write(p + k * 4, bytes(self.o.read(items + k * 4, 4)))
            self.allocs.append((p, size))
        self.log.append(['GROW', items, count, n, p])
        if aux == AUX_FLIP:
            self.log.append(['SWOFF'])
            self.o.write(BSS_SWITCH, b'\0')
        self.o.write(cell + LIST_COUNT, struct.pack('<I', 0))
        return magic

    # -- staging ------------------------------------------------------------
    def rd32(self, addr):
        return struct.unpack('<I', self.o.read(addr, 4))[0]

    def apply(self, writes):
        for (reg, idx, off, kind, a, b) in writes:
            addr = (self.base[reg] + idx * REG[reg][1] + off) & 0xffffffff
            if kind:
                val = self.base[chr(a)] + b * REG[chr(a)][1]
            else:
                val = a
            self.o.write(addr, struct.pack('<I', val & 0xffffffff))

    def reset(self):
        for reg, count, stride in REGIONS:
            self.o.write(self.base[reg], b'\0' * (count * stride))
        self.o.heap = self.heap_start
        self.allocs = []

    def run(self, case):
        self.reset()
        self.apply(case.w)
        self.log.clear()
        self.tr.clear()
        if case.fn == 1:
            ret = self.o.call(F1, r0=self.base['R'])
        elif case.fn == 2:
            ret = self.o.call(F2, r0=SEED)
        else:
            ret = self.o.call(F3, r0=SEED)
        return {'ret': ret & 0xffffffff,
                'regions': {reg: bytes(self.o.read(self.base[reg], cnt * st))
                            for reg, cnt, st in REGIONS},
                'allocs': [(ad, sz, bytes(self.o.read(ad, sz)))
                           for ad, sz in self.allocs],
                'calls': [list(x) for x in self.log],
                'tr': list(self.tr)}


# ── pointer normalisation, shared by both arms ──────────────────────────────
def ranges_for(bases, allocs):
    out = []
    for reg, count, stride in REGIONS:
        for i in range(count):
            lo = bases[reg] + i * stride
            out.append((lo, lo + stride, '%s%d' % (reg, i)))
    for i, (addr, size) in enumerate(allocs):
        out.append((addr, addr + max(size, 1), 'A%d' % i))
    return out


def token(v, ranges):
    for lo, hi, name in ranges:
        if lo <= v < hi:
            return name if v == lo else '%s+%x' % (name, v - lo)
    return '%08x' % v


def words(blob):
    return [struct.unpack_from('<I', blob, o)[0] for o in range(0, len(blob) - 3, 4)]


def norm_state(rec, bases):
    ranges = ranges_for(bases, [(a, s) for a, s, _ in rec['allocs']])
    state = {}
    for reg, count, stride in REGIONS:
        state[reg] = [token(w, ranges) for w in words(rec['regions'][reg])]
    allocs = [[token(a, ranges), s] + [token(w, ranges) for w in words(b)]
              for a, s, b in rec['allocs']]
    return state, allocs, ranges


def fmt_calls(rec, ranges):
    out = []
    for c in rec['calls']:
        parts = [c[0]]
        for x in c[1:]:
            parts.append(x if isinstance(x, str) else token(x, ranges))
        out.append(' '.join(parts))
    return out


def same(a, b):
    return (a['ret'] == b['ret'] and a['state'] == b['state']
            and a['allocs'] == b['allocs'] and a['calls'] == b['calls'])


# ── claim arm ───────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

SRCS = ['CRoom_UpdateActive.c', 'UpdateActiveLists.c',
        'ProcessActivateDeactveLists.c']


def build_c(out_bin, mutant=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    srcs = []
    for name in SRCS:
        src = MOD / 'src' / name
        text = src.read_text()
        if mutant and mutant['file'] == name:
            for old, new in mutant['edits']:
                if text.count(old) != 1:
                    raise RuntimeError('mutation site not unique (%d hits) in %s: %r'
                                       % (text.count(old), name, old[:60]))
                text = text.replace(old, new)
            src = BUILD / ('mut_%s_%s' % (mutant['name'], name))
            src.write_text(text)
        srcs.append(str(src))
    cmd = (['clang'] + ARM_FLAGS + ['-O1', '-I', str(MOD / 'src')] + srcs +
           [str(MOD / 'fixture' / 'driver.c'), '-o', str(out_bin)])
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-3000:])
    return out_bin


def parse_c(txt):
    """Parse the driver's record stream into records + its own region bases."""
    if not txt.rstrip().endswith('END'):
        raise RuntimeError('driver stream not terminated')
    bases, recs = {}, []
    cur, allocs = None, []
    for line in txt.splitlines():
        parts = line.split()
        if not parts:
            continue
        tag = parts[0]
        if tag == 'BASE':
            bases[parts[1]] = int(parts[2], 16)
        elif tag == 'CASE':
            cur = {'ret': 0, 'regions': {}, 'allocs': [], 'calls': []}
            recs.append(cur)
            allocs = []
        elif tag == 'RAW':
            cur['regions'][parts[1]] = bytes.fromhex(parts[2])
        elif tag == 'ALLOC':
            allocs.append([int(parts[2], 16), int(parts[3]), b''])
        elif tag == 'RAWA':
            allocs[int(parts[1])][2] = bytes.fromhex(parts[2])
        elif tag == 'C':
            name, a = parts[1], parts[2:]
            cur['calls'].append([name] + [int(x, 16) for x in a])
        elif tag == 'RET':
            cur['ret'] = int(parts[1], 16)
            cur['allocs'] = [tuple(x) for x in allocs]
    if len(bases) != len(REGIONS):
        raise RuntimeError('driver printed %d region bases, expected %d'
                           % (len(bases), len(REGIONS)))
    return {'bases': bases, 'recs': recs}


def run_c_arm(binary, case_list):
    blob = ''.join(c.line() for c in case_list).encode()
    p = subprocess.run(['qemu-arm', str(binary)], input=blob, capture_output=True)
    if p.returncode:
        raise RuntimeError('driver exit %d: %s'
                           % (p.returncode, p.stderr.decode()[-2000:]))
    out = parse_c(p.stdout.decode())
    if len(out['recs']) != len(case_list):
        raise RuntimeError('driver produced %d records for %d cases'
                           % (len(out['recs']), len(case_list)))
    return out


def norm_c(rec, bases):
    state, allocs, ranges = norm_state(rec, bases)
    return {'ret': token(rec['ret'], ranges), 'state': state, 'allocs': allocs,
            'calls': fmt_calls(rec, ranges), 'tr': rec.get('tr', [])}


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
        text = re.sub(r'\s*<[^>]*>', '', text)     # <sym+0x28>
        text = re.sub(r'\s*@.*$', '', text)        # @ imm = #0x20
        out.append((addr, word, _norm(text)))
    return out


def instruction_census(overrides=None, fns=None):
    """Every instruction of the original appears in its translation as
    `@0xADDR <verbatim operand text>`, each address exactly once, and every
    literal-pool word is documented with its value.

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
    """The census gate must be able to say no: an operand digit, a deleted
    comment line and a changed pool word each have to turn it red."""
    f1 = (MOD / 'src' / FUNCS[1]['src']).read_text()
    f2 = (MOD / 'src' / FUNCS[2]['src']).read_text()
    m = re.search(r'^.*@0x1abe58 bl 0x19e02c.*$', f1, re.M)
    drop = f1 if not m else f1[:m.start()] + f1[m.end():]
    trials = {
        'operand_digit_changed': (
            {FUNCS[1]['src']: f1.replace('bl 0x19e02c', 'bl 0x19e02d', 1)}, {1}),
        'comment_line_deleted': ({FUNCS[1]['src']: drop}, {1}),
        'pool_word_changed': (
            {FUNCS[2]['src']: f2.replace('.word 0xffffbf18',
                                         '.word 0xffffbf19', 1)}, {2}),
    }
    res, ok = {}, True
    for name, (ov, fns) in trials.items():
        rep = instruction_census(overrides=ov, fns=fns)
        fn = list(fns)[0]
        red = not rep['ok']
        res[name] = {'turned_red': red,
                     'wrong': len(rep[FUNCS[fn]['name']]['wrong']),
                     'pool_missing': len(rep[FUNCS[fn]['name']]['pool_missing'])}
        ok = ok and red
    res['ok'] = ok
    res['note'] = ('a mutation that leaves the gate green means the census does '
                   'not actually bind the translation to the bytes')
    return res


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    # ── F1 · the two phase predicates ─────────────────────────────────────
    {'name': 'uav_p1_predicate_inverted', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (deact != 0) goto P1_SKIP;',
                'if (deact == 0) goto P1_SKIP;')]},
    {'name': 'uav_p2_predicate_inverted', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (deact == 0) goto P2_SKIP;',
                'if (deact != 0) goto P2_SKIP;')]},
    # ── F1 · the walk start and the sort key ──────────────────────────────
    {'name': 'uav_p1_starts_at_head', 'file': 'CRoom_UpdateActive.c',
     'edits': [('cur = (u8 *)(uintptr_t)rd32(rm + ROOM_B_TAIL);',
                'cur = (u8 *)(uintptr_t)rd32(rm + ROOM_B_HEAD);')]},
    {'name': 'uav_sort_key_live_depth', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (f32(rd32(r3p + INST_SNAP)) <= f32(s14)) goto A_FRONT;',
                'if (f32(rd32(r3p + INST_DEPTH)) <= f32(s14)) goto A_FRONT;')]},
    {'name': 'uav_unordered_treated_as_less', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (f32(rd32(r3p + INST_SNAP)) <= f32(s14)) goto A_FRONT;',
                'if (!(f32(rd32(r3p + INST_SNAP)) > f32(s14))) goto A_FRONT;')]},
    # ── F1 · the two counters ─────────────────────────────────────────────
    {'name': 'uav_a_count_not_incremented', 'file': 'CRoom_UpdateActive.c',
     'edits': [('/* @0x1abe10 add r2, r2, #1 */\n    r2v += 1;',
                '/* @0x1abe10 add r2, r2, #1 */\n    r2v += 0;')]},
    {'name': 'uav_b_count_not_decremented', 'file': 'CRoom_UpdateActive.c',
     'edits': [('/* @0x1abde4 sub r0, r0, #1 */\n    r0v -= 1;',
                '/* @0x1abde4 sub r0, r0, #1 */\n    r0v -= 0;')]},
    # ── F1 · the snapshot and the unlink fields ───────────────────────────
    {'name': 'uav_snapshot_written_to_depth', 'file': 'CRoom_UpdateActive.c',
     'edits': [('/* @0x1abe40 vstr s14, [r1, #388] */\n'
                '    wr32(cur + INST_SNAP, s14);',
                '/* @0x1abe40 vstr s14, [r1, #388] */\n'
                '    wr32(cur + INST_DEPTH, s14);')]},
    {'name': 'uav_b_unlink_tail_writes_head', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (r3p == 0) wr32(rm + ROOM_B_TAIL, (u32)(uintptr_t)prev);',
                'if (r3p == 0) wr32(rm + ROOM_B_HEAD, (u32)(uintptr_t)prev);')]},
    # ── F1 · the two bls ──────────────────────────────────────────────────
    {'name': 'uav_add_first_arg_is_instance', 'file': 'CRoom_UpdateActive.c',
     'edits': [('r0v = CObjectGM_AddInstance((void *)(uintptr_t)r0v, cur);',
                'r0v = CObjectGM_AddInstance((void *)(uintptr_t)cur, cur);')]},
    {'name': 'uav_phase2_calls_add', 'file': 'CRoom_UpdateActive.c',
     'edits': [('r0v = CObjectGM_RemoveInstance((void *)(uintptr_t)r0v, cur);',
                'r0v = CObjectGM_AddInstance((void *)(uintptr_t)r0v, cur);')]},
    # ── F1 · the insert flavours ──────────────────────────────────────────
    {'name': 'uav_empty_insert_tail_not_set', 'file': 'CRoom_UpdateActive.c',
     'edits': [('/* @0x1abf58 str r1, [r4, #0x80] */\n'
                '    wr32(rm + ROOM_A_TAIL, (u32)(uintptr_t)cur);',
                '/* @0x1abf58 str r1, [r4, #0x80] */\n'
                '    wr32(rm + ROOM_A_HEAD, (u32)(uintptr_t)cur);')]},
    {'name': 'uav_front_head_not_republished', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (peq) wr32(rm + ROOM_A_HEAD, (u32)(uintptr_t)cur);',
                'if (peq) wr32(rm + ROOM_A_TAIL, (u32)(uintptr_t)cur);')]},
    {'name': 'uav_dormant_head_not_moved', 'file': 'CRoom_UpdateActive.c',
     'edits': [('if (!pz) wr32(rm + ROOM_B_HEAD, (u32)(uintptr_t)cur);',
                'if (0) wr32(rm + ROOM_B_HEAD, (u32)(uintptr_t)cur);')]},
    # ── F2 · the queue tests ──────────────────────────────────────────────
    {'name': 'ual_count_positive_only_activation', 'file': 'UpdateActiveLists.c',
     'edits': [('if (rd32(g_list_activate + LIST_COUNT) != 0) goto HANDLER_A;',
                'if ((s32)rd32(g_list_activate + LIST_COUNT) > 0) goto HANDLER_A;')]},
    {'name': 'ual_count_positive_only_type', 'file': 'UpdateActiveLists.c',
     'edits': [('if (rd32(g_list_type + LIST_COUNT) != 0) goto HANDLER_B;',
                'if ((s32)rd32(g_list_type + LIST_COUNT) > 0) goto HANDLER_B;')]},
    {'name': 'ual_check_a_reads_the_type_cell', 'file': 'UpdateActiveLists.c',
     'edits': [('if (rd32(g_list_activate + LIST_COUNT) != 0) goto HANDLER_A;',
                'if (rd32(g_list_type + LIST_COUNT) != 0) goto HANDLER_A;')]},
    {'name': 'ual_skip_c_check', 'file': 'UpdateActiveLists.c',
     'edits': [('if (rd32(g_list_depth + LIST_COUNT) != 0) goto HANDLER_C;',
                'if (0) goto HANDLER_C;')]},
    # ── F2 · the profiler pair ────────────────────────────────────────────
    {'name': 'ual_pop_unconditional', 'file': 'UpdateActiveLists.c',
     'edits': [('if (rd8(r5p) == 0) return r0;', 'if (0) return r0;')]},
    {'name': 'ual_push_args_swapped', 'file': 'UpdateActiveLists.c',
     'edits': [('r0 = CProfiler_Push(&g_profiler[0], 6, 7);',
                'r0 = CProfiler_Push(&g_profiler[0], 7, 6);')]},
    # ── F3 · the singleton hop ────────────────────────────────────────────
    {'name': 'pa_queue_not_cleared', 'file': 'ProcessActivateDeactveLists.c',
     'edits': [('wr32(g_list_activate + LIST_COUNT, 0);',
                'wr32(g_list_activate + LIST_COUNT, 1);')]},
]


def rowview(rec):
    """The receipt's per-case view: every compared facet, with each region
    reduced to a digest of its token list.  The full state is kept only for
    rows that differ, so a green run stays inspectable without a 2 MB receipt."""
    return {'ret': rec['ret'], 'calls': rec['calls'], 'allocs': rec['allocs'],
            'state_sha': {r: hashlib.sha256('|'.join(rec['state'][r])
                                            .encode()).hexdigest()[:16]
                          for r in rec['state']}}


def _digest(recs):
    return hashlib.sha256(json.dumps(
        [{k: r[k] for k in ('ret', 'state', 'allocs', 'calls')} for r in recs],
        sort_keys=True).encode()).hexdigest()


def _sample(case, a, r):
    d = {}
    for k in ('ret', 'state', 'allocs', 'calls'):
        if a[k] != r[k]:
            d[k] = {'original': a[k], 'mutant': r[k]}
    return {'case': case.label, 'differing_facets': d}


def teeth_one(m, case_list, a_recs):
    b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
    batch_detail = None
    try:
        out = run_c_arm(b, case_list)
        recs = [norm_c(r, out['bases']) for r in out['recs']]
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
            out = run_c_arm(b, [c])
            r = norm_c(out['recs'][0], out['bases'])
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
                       'weaker than a mismatch tooth')
    return rec


# ── binding ──────────────────────────────────────────────────────────────────
def sha(p):
    return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()


def got_slot(o, addr):
    return struct.unpack('<I', o.read(addr, 4))[0]


def derive_got_slots(o):
    """Re-derive every slot from the bytes: F2's five cells are `anchor + pool
    word` (both negative words), the anchor itself is `pc + word`; F3's two are
    the plain `pc + word` form, pc being instruction + 8."""
    word_anchor = struct.unpack('<I', o.read(ANCHOR_POOL, 4))[0]
    anchor = (ANCHOR_ADD + 8 + word_anchor) & 0xffffffff
    out = [{'body': 'anchor', 'add': hex(ANCHOR_ADD),
            'pool_word': '%08x' % word_anchor, 'slot': hex(anchor),
            'want': hex(ANCHOR_WANT), 'ok': anchor == ANCHOR_WANT}]
    for name, kind, insn, pool_addr, want in GOT_DERIVATION:
        w = struct.unpack('<I', o.read(pool_addr, 4))[0]
        if kind == 'anchor':
            slot = (anchor + w) & 0xffffffff      # ldr rX,[r4,rX]
        else:
            slot = (insn + 8 + w) & 0xffffffff    # ldr rX,[pc,rX]
        out.append({'body': name, 'kind': kind, 'insn': hex(insn),
                    'pool_at': hex(pool_addr), 'pool_word': '%08x' % w,
                    'slot': hex(slot), 'want': hex(want), 'ok': slot == want})
    return out


# ── the VFP premise, measured rather than assumed ──────────────────────────
# The active-chain walk's ordering decision is `vcmpe.f32` + `vmrs APSR_nzcv` +
# `bls`.  Whether `bls` is taken for an UNORDERED compare decides whether a NaN
# sinks to the tail or jumps to the head, and that is exactly the difference
# between `a <= b` and `!(a > b)` in C.  So the harness runs the pinned
# instruction pair itself and records the answer:
#
#     vldr s15,[r0] / vldr s14,[r1] / vcmpe.f32 s15,s14 / vmrs APSR_nzcv,fpscr
#     mov r2,#0 / bls #0 / mov r2,#1 / bx lr
#
# r2 == 0 means bls was taken (insert in front), r2 == 1 means the walk moves on.
VFP_SNIPPET = [0xEDD07A00, 0xED917A00, 0xEEF47AC7, 0xEEF1FA10,
               0xE3A02000, 0x9A000000, 0xE3A02001, 0xE12FFF1E]
VFP_CODE, VFP_DATA, VFP_RET = 0x10000, 0x20000, 0x30000


def fb_of(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def vfp_flag_probe():
    """Run the pinned vcmpe/bls pair seven times and report what it decided."""
    from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
    from unicorn.arm_const import (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2,
                                   UC_ARM_REG_LR, UC_ARM_REG_C1_C0_2,
                                   UC_ARM_REG_FPEXC)
    rows = [('equal', fb_of(5.0), fb_of(5.0), True),
            ('greater', fb_of(5.0), fb_of(3.0), False),
            ('less', fb_of(3.0), fb_of(5.0), True),
            ('new_is_nan', fb_of(5.0), 0x7fc00000, False),
            ('cursor_is_nan', 0x7fc00000, fb_of(5.0), False),
            ('negative_less', fb_of(-3.0), fb_of(0.0), True),
            ('negative_zero', fb_of(5.0), 0x80000000, False)]
    out, ok = [], True
    for name, a, b, want_taken in rows:
        uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        for base in (VFP_CODE, VFP_DATA, VFP_RET):
            uc.mem_map(base, 0x1000)
        uc.mem_write(VFP_CODE, b''.join(struct.pack('<I', w)
                                        for w in VFP_SNIPPET))
        uc.reg_write(UC_ARM_REG_C1_C0_2, 0x00F00000)
        uc.reg_write(UC_ARM_REG_FPEXC, 0x40000000)
        uc.mem_write(VFP_DATA, struct.pack('<II', a, b))
        uc.reg_write(UC_ARM_REG_R0, VFP_DATA)
        uc.reg_write(UC_ARM_REG_R1, VFP_DATA + 4)
        uc.reg_write(UC_ARM_REG_LR, VFP_RET)
        uc.emu_start(VFP_CODE, VFP_RET, 0, 100)
        taken = uc.reg_read(UC_ARM_REG_R2) == 0
        out.append({'compare': name, 'bls_taken': taken,
                    'expected': want_taken, 'ok': taken == want_taken})
        ok = ok and taken == want_taken
    return {'snippet': ['vldr s15,[r0]', 'vldr s14,[r1]', 'vcmpe.f32 s15,s14',
                        'vmrs APSR_nzcv,fpscr', 'mov r2,#0', 'bls #0',
                        'mov r2,#1', 'bx lr'],
            'rows': out, 'ok': ok,
            'reading': ('bls is taken only for an ORDERED cur <= new; an '
                        'unordered compare walks on like "greater" does, so a '
                        'NaN depth sinks to the TAIL and the C model is '
                        '`a <= b`, not `!(a > b)`')}


def bss_extent(so):
    from elftools.elf.elffile import ELFFile
    with open(so, 'rb') as f:
        elf = ELFFile(f)
        for s in elf.iter_sections():
            if s.name == '.bss':
                return s['sh_addr'], s['sh_size']
    raise RuntimeError('no .bss in %s' % so)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('room_update_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    # binding: the pinned image, the six GOT cells, the .bss extent
    img_sha = sha(SO)
    o = Oracle()
    got = {hex(a): got_slot(o, a) for a in GOT_SLOTS}
    got_ok = all(got[hex(a)] == v for a, v in GOT_SLOTS.items())
    deriv = derive_got_slots(o)
    deriv_ok = all(d['ok'] for d in deriv)
    blo, blen = bss_extent(SO)
    bss_ok = all(blo <= a < blo + blen for a in
                 (BSS_SWITCH, BSS_PROFILER, BSS_LIST_A, BSS_LIST_B, BSS_LIST_C,
                  BSS_RUN_ROOM))
    census = instruction_census()
    stest = census_selftest()
    vfp = vfp_flag_probe()

    # claim arm
    base_bin = build_c(BUILD / 'room_update.arm')
    c_out = run_c_arm(base_bin, case_list)
    c_recs = [norm_c(r, c_out['bases']) for r in c_out['recs']]

    # judge arm
    stage = Stage(o)
    A = {reg: stage.base[reg] for reg, _c, _s in REGIONS}
    a_raw = [stage.run(c) for c in case_list]
    a_recs = [norm_c(r, A) for r in a_raw]

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_recs, c_recs):
        eq = same(a, c)
        row = {'case': case.fn, 'label': case.label,
               'original': rowview(a), 'rebuild': rowview(c), 'equal': eq}
        if not eq:
            row['original_full'] = a
            row['rebuild_full'] = c
            mismatches.append(row)
        rows.append(row)

    # repeat: a second Unicorn instance and a second qemu process
    stage2 = Stage(Oracle())
    A2 = {reg: stage2.base[reg] for reg, _c, _s in REGIONS}
    a_rep = [norm_c(stage2.run(c), A2) for c in case_list]
    c_out2 = run_c_arm(base_bin, case_list)
    c_rep = [norm_c(r, c_out2['bases']) for r in c_out2['recs']]
    repeat = {'original': all(same(x, y) for x, y in zip(a_recs, a_rep)),
              'rebuild': all(same(x, y) for x, y in zip(c_recs, c_rep)),
              'original_sha256': [_digest(a_recs), _digest(a_rep)],
              'rebuild_sha256': [_digest(c_recs), _digest(c_rep)],
              'original_bases_differ': A['R'] != A2['R'],
              'rebuild_bases_same': (c_out['bases'] == c_out2['bases'])}

    coverage, covered_by = {}, {}
    for name, fn in COVER:
        hits = [c.label for c, a in zip(case_list, a_recs)
                if fn(a['tr'], a, c)]
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]

    teeth = [teeth_one(m, case_list, a_recs) for m in MUTANTS]

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    rep_ok = repeat['original'] and repeat['rebuild']
    binding_ok = (img_sha == PIN and got_ok and deriv_ok and bss_ok
                  and vfp['ok'])
    status = ('PASS' if (identity and cov_ok and teeth_ok and binding_ok
                         and rep_ok and census['ok'] and stest['ok']) else 'FAIL')

    receipt = {
        'schema': 'cally-room-update-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': (
            'synthetic memory oracle: the original ARM bytes of THREE bodies '
            '(0x1abd9c CRoom::UpdateActive, 0x1d30a4 UpdateActiveLists, '
            '0x1d3074 ProcessActivateDeactveLists) executed over the image\'s '
            'own .bss cells, with the bl chain landing in the next body\'s '
            'original bytes and every unrecovered callee stubbed identically on '
            'both arms; NOT device execution'),
        'BINDING': {
            'original_sha256': img_sha,
            'original_sha256_pinned': PIN,
            'functions': {v['name']: {'entry': hex(v['entry']),
                                      'end': hex(v['end']),
                                      'instructions': v['ninstr'],
                                      'pool_words': v['npool'],
                                      'src': v['src']}
                          for v in FUNCS.values()},
            'src_sha256': {n: sha(MOD / 'src' / n) for n in SRCS},
            'header_sha256': sha(MOD / 'src' / 'room_update.h'),
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'got_slots': got,
            'got_slots_expected': {hex(a): hex(v) for a, v in GOT_SLOTS.items()},
            'got_match': got_ok,
            'got_slot_derivation': deriv,
            'got_slot_derivation_ok': deriv_ok,
            'bss_extent': [hex(blo), hex(blen)],
            'bss_cells_inside': bss_ok,
            'vfp_compare_semantics': vfp,
            'real_link': {
                'UpdateActiveLists@0x1d30a4': 'entry, both arms',
                'ProcessActivateDeactveLists@0x1d3074':
                    'both arms: the judge arm runs its bytes because F2 bls to '
                    'it, the claim arm runs the C translation',
                'CRoom::UpdateActive@0x1abd9c':
                    'both arms: reached through F3, so the queue-count -> '
                    'chain-rewrite link is real on both sides',
            },
            'stub_callees': ['CObjectGM::AddInstance@0x19e02c',
                             'CObjectGM::RemoveInstance@0x19e0fc',
                             'ChangeInstanceTypes@0x1d2ea0',
                             'ChangeInstanceDepths@0x1d2ee8',
                             'CProfiler::Push@0x2a0738',
                             'CProfiler::Pop@0x2a08ac',
                             'the bump allocator'],
            'build': 'clang --target=armv7a-none-eabi (freestanding) + qemu-arm',
            'heap_model': {'allocator': 'bump', 'align': ALIGN,
                           'fill_byte': '0x%02x' % FILL_BYTE,
                           'reset': 'per case, both arms',
                           'note': 'the fill byte is asserted, not incidental: '
                                   'bytes no body writes must still compare '
                                   'equal across the two arms'},
        },
        'scope': {
            'covered': [
                'F1: both walk directions (dormant TAIL via +0x178, active TAIL '
                'via +0x178); all four branch pairs; the two unlink field sets '
                '(0x8c/0x90 and 0x80/0x84); the three active-chain insert '
                'flavours (empty / in-front-of-a-node / tail-append) including '
                'the head republish at 0x1abf38; the two dormant-chain inserts '
                '(empty and head); the depth-descending order with `bls` == '
                '<= OR unordered (equal depth, NaN on either side); the '
                'SNAPSHOT +0x184 as the sort key and its refresh at insert '
                'time; the word copy of +0x180 into +0x184 on the empty-chain '
                'path; both counters including their wrap behaviour; both bls '
                'with the CObjectGM* read out of inst+0x80 and the instance in '
                'r1',
                'F2: the three queue tests in machine order, `cmp/bne` as a '
                'NON-ZERO (not positive) test -- counts -1 and 0x80000000 both '
                'flush; the three fall-through edges; handler A cleared count '
                'and the stub-cleared B/C counts; the profile Push(6,7)/Pop '
                'pair on the same object and the exit RE-READING the switch '
                'byte (a handler that clears it yields Push without Pop); the '
                'GROW model through the shared bump arena',
                'F3: the Run_Room singleton hop (not the caller\'s r0), the '
                'queue count clear, and the r0 pass-through of '
                'UpdateActive\'s result',
            ],
            'not_covered': [
                'the semantics of every stubbed callee: a green run says the '
                'chain passes the right ARGUMENTS to them and passes their r0 '
                'through, nothing more',
                'what the two real handlers do with their queue: the stub '
                'clears the count and honours the AUX knob, and that is a '
                'MODEL.  The array growth of a queue container therefore is not '
                'graded as the original\'s behaviour -- only the harness\'s GROW '
                'model is, and only for the case shapes staged here',
                'inst+0x69 has no write point in F1: WHICH body sets or clears '
                'the deactivated flag (and when) is not in this arm, so '
                '"deactivate then reactivate across frames" is staged as input, '
                'never produced',
                'the class identity of the CProfiler object and what (6,7) '
                'mean beyond being Push\'s two arguments',
                'device behaviour: this is a synthetic-memory oracle over the '
                'original bytes, not execution on a phone',
            ],
            'observability': [
                'every case compares the returned word (r0 residue included), '
                'every word of every staged region (12 regions, pointers '
                'normalised to region tokens) and every allocated block, so a '
                'store the translation forgot and a store it invented both show '
                'up',
                'the call log records each stub call in order with the '
                'arguments the body passed: the CObjectGM* (read out of '
                'inst+0x80 by the body, not by the harness) and the instance '
                'pointer (which the body never materialises explicitly -- it '
                'relies on r1 still holding it)',
                'the stubs return magic constants, so "does this body return '
                'its callee\'s r0" is graded, not assumed',
            ],
            'staging_geometry': {
                'shared': 'one write program interpreted by both arms; only the '
                          'region bases differ (the judge arm uses the image\'s '
                          'own .bss cells for Q/C/B/W/F/S, the claim arm its own '
                          'globals)',
                'regions': {r: {'count': c, 'stride': hex(s)}
                            for r, c, s in REGIONS},
            },
        },
        'findings': [
            'CRoom::UpdateActive sorts the ACTIVE chain by the SNAPSHOT at '
            'inst+0x184, never by the live depth at +0x180, and it refreshes '
            'that snapshot on every insert (0x1abe40 / 0x1abf48 / 0x1abf5c).  '
            'A depth change therefore does NOT reorder the chain: the instance '
            'has to leave (deactivate) and come back for the order to follow '
            'its new depth.  Case F1-l is the one that separates the two keys.',
            "CARD DRIFT, measured: the walk's `vcmpe.f32` + `bls` is an "
            'ORDERED <= only.  VCMP leaves FPSCR = 0110 (equal), 0010 '
            '(greater), 1000 (less) and 0011 on UNORDERED -- C=1, Z=0 -- so '
            '`ls` (C == 0 || Z == 1) is FALSE for a NaN on either side and the '
            'walk steps past it like it steps past a greater node.  A NaN '
            'depth therefore sinks to the TAIL, it does not jump to the head '
            '(cases F1-m, F1-n).  The C model is `a <= b`, NOT `!(a > b)`: '
            'the latter is true for NaN and is exactly the "bls == <= or '
            'unordered" gloss this line carried before the differential '
            'disagreed with it.  Note the same idiom sits at CRoom::AddInstance '
            '0x1ab680 in c/room_add, whose translation uses `!(a > b)` and '
            'whose case set has no NaN depth, so that arm cannot see this.',
            'both counters are read-modify-write with NO clamp and NO sign '
            'test: a dormant count of 0 minus one move becomes 0xffffffff '
            '(F1-p), and an active count of 0xffffffff plus one wraps to 0 '
            '(F1-t).  The counts are therefore only trustworthy if the chains '
            'and the counters were consistent to begin with, which nothing in '
            'these 116 instructions checks.',
            'the two bls take the CObjectGM* out of inst+0x80 in r0 and rely on '
            'r1 STILL holding the instance -- no instruction between 0x1abe00 '
            'and 0x1abe54 writes r1.  The C++ signature '
            '(CObjectGM::AddInstance(CInstance*)) agrees, so the body is '
            'passing (this = *(inst+0x80), inst) and nothing else.',
            'UpdateActiveLists tests `cmp/bne`, i.e. NON-ZERO, not positive: a '
            'queue count of -1 or 0x80000000 flushes the queue exactly like +1 '
            '(F2-g, F2-h, F2-o).  `if (count > 0)` would silently skip a queue '
            'whose count underflowed.',
            'the profile switch byte 0x757e7c is read TWICE -- at entry '
            '(0x1d30b8) and again at the exit (0x1d3100) -- and the SECOND read '
            'decides Pop.  A handler that turns profiling off mid-frame gives a '
            'Push with no Pop (F2-j).  That is not an accident of code '
            'generation: the exit does not reuse the r3 the entry loaded.',
            'F2 checks all three queues every frame and each handler returning '
            'goes to the NEXT check, not to the head: the order A -> B -> C is '
            'fixed and a frame runs each handler at most once (no loop edge '
            'anywhere in the 42 instructions).',
            'the three queue cells are 12 B apart in one .bss cluster '
            '(0x542a4c / 0x542a58 / 0x542a64) but they are NOT the same object '
            'as the room: F3 clears list A\'s count behind '
            'UpdateActiveLists\'s back, so a frame that ran handler A leaves '
            'count A at 0 without F2 ever storing to it.',
        ],
        'instruction_census': census,
        'census_selftest': stest,
        'cases': len(case_list),
        'repeat': repeat,
        'rows': rows,
        'coverage': coverage,
        'coverage_witness': covered_by,
        'teeth': teeth,
        'status': status,
    }
    out = args.out or (RECEIPTS / ('room_update_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d identical=%d binding=%s repeat=%s census=%d/%d '
          'selftest=%s'
          % (status, len(case_list), sum(1 for r in rows if r['equal']),
             'ok' if binding_ok else 'MISMATCH',
             'ok' if rep_ok else 'DRIFT',
             census['documented'], census['instructions'],
             'ok' if stest['ok'] else 'NO'))
    if not binding_ok:
        print('  BINDING img=%s got=%s deriv=%s bss=%s'
              % (img_sha == PIN, got_ok, deriv_ok, bss_ok))
        for d in deriv:
            if not d['ok']:
                print('    slot %s -> %s want %s' % (d['body'], d['slot'],
                                                     d['want']))
        for a, v in GOT_SLOTS.items():
            if got[hex(a)] != v:
                print('    cell %#x holds %#x want %#x'
                      % (a, got[hex(a)], v))
    if not census['ok']:
        for v in census.values():
            if not isinstance(v, dict) or 'wrong' not in v:
                continue
            for w in v['wrong'][:8]:
                print('  CENSUS %s objdump=%r source=%r'
                      % (w['addr'], w['objdump'], w['source']))
            for w in v['pool_missing'][:8]:
                print('  CENSUS pool %s word=%s undocumented'
                      % (w['addr'], w['word']))
    for k, v in coverage.items():
        print('  COVER %-40s %s' % (k, 'yes' if v else 'NO'))
    for t in teeth:
        print('  TEETH %-38s %s mode=%-20s caught_by=%d'
              % (t['mutant'], 'PASS' if t['passed'] else 'FAIL', t['mode'],
                 len(t['caught_by'])))
    for m in mismatches[:6]:
        print('  DIFF case=%r' % (m['label'],))
        for k in ('ret', 'calls', 'allocs', 'state_sha'):
            if m['original'][k] != m['rebuild'][k]:
                print(('    %s original=%r' % (k, m['original'][k]))[:400])
                print(('    %s rebuild =%r' % (k, m['rebuild'][k]))[:400])
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
