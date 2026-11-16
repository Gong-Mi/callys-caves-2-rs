#!/usr/bin/env python3
"""The instance-registration chain of libyoyo ARMv7 — original-binary differential.

Three bodies from the pinned image
(3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a), all three
recovered here and all three running for real on BOTH arms:

  F1  _ZN5CRoom11AddInstanceEP9CInstance                     @0x001ab654
      79 instructions + 2 literal-pool words, 324 B   u32 (declared CInstance*)
  F2  _ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance      @0x001c5d18
      40 instructions + 1 literal-pool word, 164 B    void
  F3  _ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance
      @0x001c5a38, 179 instructions + 5 pool words, 736 B   void

  arm A (judge)  the original bytes, executed in Unicorn over the real .bss the
                 three bodies reach through their .got (0x536f28 ms_ID2InstanceE,
                 0x5428e8 the Zeus byte, 0x542678 the 36 B element pool,
                 0x5425f0 the element uid, 0x3eb70c the error host *cell*).
                 F1's `bl 0x1c5d18` lands in F2's original bytes, F2's
                 `b 0x1c5a38` in F3's, F3's `b 0x1c451c` in a stub -- the chain
                 is executed as the binary lays it out.
  arm B (claim)  reconstruction/reverse-v1/c/room_add/src/*.c, built for
                 armv7a-none-eabi (freestanding) and run under qemu-arm.

Why arm B must not be host-compiled: the whole point of these three bodies is
their offsets -- +0x78/+0x69/+0x170/+0x174/+0x178/+0x17c/+0x180/+0x184 on a
CInstance, +0x80/+0x84/+0x88/+0x110..+0x120 on a CRoom, 12 B table-3 buckets,
16 B id-hash nodes, a 36 B element whose free-list links share +0x14/+0x18 with
the live chain.  A 64-bit host build moves every one of them.

Gates
  binding    image sha256, the five GOT slot -> .bss chains, and the three
             rodata strings the bodies pass to Alloc and to the error vtable
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

Two card drifts this harness found (both are in the receipt)
  * the F3 error host: the card says GOT slot 0x3ed718 -> 0x479a94.  pc in
    `ldr rX,[pc,rX]` is instruction+8, so 0x1c5ca4 + pool word 0x00227a78 is
    0x3ed71c, and 0x3ed71c holds 0x3eb70c -- one slot earlier, a different .bss
    cell.  binding() now re-derives all five slots from the bytes instead of
    trusting the card.
  * the F3 message string: the card quotes " ERROR: Adding too many variables"
    at 0x35285c.  0x1c5cac + pool word 0x0018abb8 is 0x350864, and what is
    there is "Attempting to add instance %d multiple times to a layer".  The
    0x35285c string is the tail of a different ("INTERNAL ERROR: ...") message.
    The identity gate caught this as the one remaining diff before the fix.

Scope, stated up front
  * all three bodies are recovered: the claim arm links all three translations
    and the judge arm runs all three original bodies.  A green run says the
    chain's dispatch, field writes, chain/table/pool bookkeeping and both tail
    jumps agree; it does NOT say anything about what the callees do.
  * UNRECOVERED and stubbed identically on both arms: CHashMapCalculateHash
    @0x1b6e44, GetLayerFromID @0x1b8868, GetLayerWithDepth @0x1b87f4,
    AddDynamicLayer @0x1c33e4, AddElementToLayer @0x1c451c,
    UpdateInstanceActivation @0x1b8a28, CollisionInsert @0x1cc494,
    MemoryManager::Alloc @0x27ce78, and the host object's vtable slot.
    A green run proves nothing about those callees and is not device
    equivalence.
  * the hash stub is a MODEL (key * 2654435761), so table 3 is exercised with a
    hash whose bucket placement the harness computes; the original's real hash
    is not being tested.
  * the stubs RETURN staged values, which is deliberate: the arguments are the
    observable (the layer id, the truncated depth, the bool, the deactivated
    byte, the element pointer), and the returned value is a distinctive
    constant so that "does this body pass its tail callee's r0 through" is
    graded, not assumed.

Heap model, identical on both arms
  * a bump arena, 16-byte alignment, reset per case, every block prefilled with
    0xA5 over the WHOLE aligned block.  An earlier batch lost a day to two arms
    filling with different bytes, so the fill value is asserted here
    (FILL_BYTE) and printed in the receipt.

Usage
  python3 room_add_diff.py            # build, run both arms, write receipt
                                      # 48 cases, 61 coverage items, 23 teeth
  python3 room_add_diff.py --no-run   # replay the gates on the last receipt
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
MOD = RV1 / 'c' / 'room_add'
BUILD = HERE / 'build' / 'room_add'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle, SO  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
    UC_ARM_REG_PC, UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

# ── the three bodies ─────────────────────────────────────────────────────────
F1, F1_END, F1_POOL = 0x1ab654, 0x1ab798, 0x1ab790
F2, F2_END, F2_POOL = 0x1c5d18, 0x1c5dbc, 0x1c5db8
F3, F3_END, F3_POOL = 0x1c5a38, 0x1c5d18, 0x1c5d04

FUNCS = {
    1: {'name': 'CRoom_AddInstance', 'entry': F1, 'end': F1_END, 'pool': F1_POOL,
        'src': 'CRoom_AddInstance.c', 'npool': 2, 'ninstr': 79},
    2: {'name': 'CLayerManager_AddInstance', 'entry': F2, 'end': F2_END,
        'pool': F2_POOL, 'src': 'CLayerManager_AddInstance.c', 'npool': 1,
        'ninstr': 40},
    3: {'name': 'CLayerManager_AddInstanceToLayer', 'entry': F3, 'end': F3_END,
        'pool': F3_POOL, 'src': 'CLayerManager_AddInstanceToLayer.c',
        'npool': 5, 'ninstr': 179},
}

# ── callees ──────────────────────────────────────────────────────────────────
HASH = 0x1b6e44
GLID = 0x1b8868
GLWD = 0x1b87f4
ADDL = 0x1c33e4
AEL = 0x1c451c
UIA = 0x1b8a28
COLL = 0x1cc494
MM_ALLOC = 0x27ce78

MAGIC_AEL = 0xAE1AE1AE
MAGIC_UIA = 0x0A1A0A1A
MAGIC_COLL = 0xC0111DE5
MAGIC_ERR = 0xE44E44E4

# ── GOT slots -> .bss cells (read out of the pinned image, re-checked at run) ─
GOT_SLOTS = {
    0x3edc4c: 0x536f28,   # ms_ID2InstanceE      F1
    0x3ed92c: 0x5428e8,   # the Zeus byte        F2
    0x3f086c: 0x542678,   # the 36 B pool        F3
    0x3f0ae8: 0x5425f0,   # the element uid      F3
    0x3ed71c: 0x3eb70c,   # *cell = error host   F3
}

# The slot each body's `ldr rX,[pc,#imm]` + `ldr rX,[pc,rX]` pair really reaches,
# as (the second ldr, its pool word, the slot it must land on).  binding()
# re-derives every one of them from the bytes at run time, because the card for
# F3 said 0x3ed718 (== 0x479a94) and the arithmetic says 0x3ed71c (== 0x3eb70c):
# pc in `ldr rX,[pc,rX]` is the instruction address + 8, and 0x1c5ca4 +
# 0x00227a78 is 0x3ed71c.  One GOT slot is 4 bytes, so this is not cosmetic.
GOT_DERIVATION = [
    ('CRoom_AddInstance', 0x1ab6c0, 0x1ab790, 0x3edc4c),
    ('CLayerManager_AddInstance', 0x1c5d28, 0x1c5db8, 0x3ed92c),
    ('AddInstanceToLayer/pool', 0x1c5ac8, 0x1c5d04, 0x3f086c),
    ('AddInstanceToLayer/uid', 0x1c5ba4, 0x1c5d0c, 0x3f0ae8),
    ('AddInstanceToLayer/host', 0x1c5c9c, 0x1c5d10, 0x3ed71c),
]
BSS_ID_TABLE = 0x536f28
BSS_ZEUS = 0x5428e8
BSS_POOL = 0x542678
BSS_UID = 0x5425f0
BSS_ERR_HOST = 0x3eb70c

# The three rodata strings the bodies use.  The address is NOT hardcoded: each
# is the pc-relative `add rX, pc, rX` that materialises it, so binding() can
# re-derive it.  (This is the second card drift this harness found: the F3 error
# string is at 0x350864 - "Attempting to add instance %d multiple times to a
# layer" - not the " ERROR: Adding too many variables" at 0x35285c the card
# quotes, which is the tail of a different, INTERNAL ERROR message.)
STR_DERIVATION = [
    ('CRoom_AddInstance / Hash.h', 0x1ab6c8, 0x1ab794,
     'jni/../jni/yoyo/../../../Platform/Hash.h'),
    ('AddInstanceToLayer / Room_Layers.h', 0x1c5af0, 0x1c5d08,
     'jni/../jni/yoyo/../../../Files/Room/Room_Layers.h'),
    ('AddInstanceToLayer / error message', 0x1c5ca4, 0x1c5d14,
     'Attempting to add instance %d multiple times to a layer'),
]

FILL_BYTE = 0xA5
ALIGN = 16

# ── the staged object graph ─────────────────────────────────────────────────
# (id, count, stride) — the driver's REGIONS array is the same list.
REGIONS = [
    ('R', 1, 0x130),      # CRoom
    ('I', 6, 0x188),      # CInstance
    ('L', 4, 0x28),       # CLayer
    ('T', 16, 12),        # table 3 buckets
    ('K', 16, 8),         # ms_ID2InstanceE buckets
    ('E', 8, 36),         # pre-staged 36 B elements / 16 B hash nodes
    ('H', 1, 0xc),        # the id-table header cell (0x536f28)
    ('Z', 1, 4),          # the Zeus byte cell (0x5428e8)
    ('G', 1, 4),          # the uid counter cell (0x5425f0)
    ('P', 1, 0x14),       # the pool header (0x542678)
    ('X', 1, 0xc),        # the three stub answer cells
]
REG = {r: (c, s) for r, c, s in REGIONS}
FIXED_REGION = {'H': BSS_ID_TABLE, 'Z': BSS_ZEUS, 'G': BSS_UID, 'P': BSS_POOL}

# field offsets, mirrored from room_add.h
ROOM_TAIL, ROOM_HEAD, ROOM_COUNT = 0x80, 0x84, 0x88
ROOM_T3CAP, ROOM_T3MASK, ROOM_T3BUCKETS = 0x110, 0x118, 0x120
LAYER_ID, LAYER_DEPTH = 0x00, 0x04
INST_DEACT, INST_ID = 0x69, 0x78
INST_LID, INST_INL = 0x170, 0x174
INST_PREV, INST_NEXT = 0x178, 0x17c
INST_DEPTH, INST_SNAP = 0x180, 0x184
POOL_HEAD, POOL_TAIL, POOL_AVAIL, POOL_CAP = 0x0, 0x4, 0x8, 0x10
E_NEXT, E_PREV, E_TYPE, E_UID, E_FLAG, E_IID, E_INST = (
    0x14, 0x18, 0x00, 0x04, 0x08, 0x1c, 0x20)


def fb(x):
    """float -> its 32-bit pattern."""
    return struct.unpack('<I', struct.pack('<f', x))[0]


def i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


def stub_hash(key):
    """The hash model both arms share: CHashMapCalculateHash is stubbed."""
    return (key * 2654435761) & 0xffffffff


# ── case description ─────────────────────────────────────────────────────────
class Case:
    """One input plus the staging program both arms interpret.

    The program is a list of writes `(region, index, offset, kind, a, b)`:
    kind 0 stores `a`, kind 1 stores base(a) + b*stride(a).  The two arms supply
    their own region bases, so the same program stages the same graph at
    different addresses - and no case can self-certify: the gates are judged on
    the ORIGINAL arm's instruction trace and on the compared facets.
    """

    def __init__(self, fn, a=0, b=0, c=0, label=''):
        self.fn, self.a, self.b, self.c = fn, a, b, c
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
        # room: table 3 at T, capacity 16, mask 15
        self.ptr('R', 0, ROOM_T3BUCKETS, 'T', 0)
        self.lit('R', 0, ROOM_T3MASK, 15)
        self.lit('R', 0, ROOM_T3CAP, 16)
        # ms_ID2InstanceE header: buckets at K, mask 15, count 0
        self.ptr('H', 0, 0x0, 'K', 0)
        self.lit('H', 0, 0x4, 15)
        self.lit('H', 0, 0x8, 0)
        # the pool: empty, capacity 1
        self.lit('P', 0, POOL_HEAD, 0)
        self.lit('P', 0, POOL_TAIL, 0)
        self.lit('P', 0, POOL_AVAIL, 0)
        self.lit('P', 0, POOL_CAP, 1)
        # both gates open, uid 0, all three stub answers NULL
        self.lit('Z', 0, 0, 1)
        self.lit('G', 0, 0, 0)
        self.lit('X', 0, 0, 0)
        self.lit('X', 0, 4, 0)
        self.lit('X', 0, 8, 0)
        return self

    def room(self, head=None, tail=None, count=None, t3mask=None, t3cap=None,
             t3buckets=None):
        if head is not None:
            self.ptr('R', 0, ROOM_HEAD, 'I', head)
        if tail is not None:
            self.ptr('R', 0, ROOM_TAIL, 'I', tail)
        if count is not None:
            self.lit('R', 0, ROOM_COUNT, count)
        if t3mask is not None:
            self.lit('R', 0, ROOM_T3MASK, t3mask)
        if t3cap is not None:
            self.lit('R', 0, ROOM_T3CAP, t3cap)
        if t3buckets is not None:
            self.ptr('R', 0, ROOM_T3BUCKETS, t3buckets, 0)
        return self

    def inst(self, i, id=0, depth=0.0, snap=None, snap_bits=None, nxt=None,
             prev=None, in_layer=0, layer_id=-1, deact=0):
        self.lit('I', i, INST_ID, id)
        self.lit('I', i, INST_DEPTH, fb(depth))
        if snap_bits is not None:
            self.lit('I', i, INST_SNAP, snap_bits)
        else:
            self.lit('I', i, INST_SNAP, fb(depth if snap is None else snap))
        if nxt is not None:
            self.ptr('I', i, INST_NEXT, 'I', nxt)
        if prev is not None:
            self.ptr('I', i, INST_PREV, 'I', prev)
        self.lit('I', i, INST_INL, 1 if in_layer else 0)
        self.lit('I', i, INST_LID, layer_id & 0xffffffff)
        self.lit('I', i, INST_DEACT, 1 if deact else 0)
        return self

    def layer(self, i, id_, depth):
        self.lit('L', i, LAYER_ID, id_ & 0xffffffff)
        self.lit('L', i, LAYER_DEPTH, depth & 0xffffffff)
        return self

    def t3(self, bucket, hash_, key=0, value=None):
        """A table-3 bucket: {key@0, value@4, hash@8}; value is an E index."""
        self.lit('T', bucket, 0x0, key & 0xffffffff)
        if value is None:
            self.lit('T', bucket, 0x4, 0)
        else:
            self.ptr('T', bucket, 0x4, 'E', value)
        self.lit('T', bucket, 0x8, hash_ & 0xffffffff)
        return self

    def kslot(self, bucket, head=None, tail=None):
        if head is not None:
            self.ptr('K', bucket, 0x0, 'E', head)
        if tail is not None:
            self.ptr('K', bucket, 0x4, 'E', tail)
        return self

    def elem(self, i, typ=2, uid=0xffffffff, flag=0, nxt=None, prev=None,
             iid=0xffffffff, inst=None):
        self.lit('E', i, E_TYPE, typ)
        self.lit('E', i, E_UID, uid & 0xffffffff)
        self.lit('E', i, E_FLAG, flag & 0xff)
        if nxt is not None:
            self.ptr('E', i, E_NEXT, 'E', nxt)
        if prev is not None:
            self.ptr('E', i, E_PREV, 'E', prev)
        self.lit('E', i, E_IID, iid & 0xffffffff)
        if inst is None:
            self.lit('E', i, E_INST, 0)
        else:
            self.ptr('E', i, E_INST, 'I', inst)
        return self

    def pool(self, head=None, tail=None, avail=None, cap=None):
        if head is not None:
            self.ptr('P', 0, POOL_HEAD, 'E', head)
        if tail is not None:
            self.ptr('P', 0, POOL_TAIL, 'E', tail)
        if avail is not None:
            self.lit('P', 0, POOL_AVAIL, avail)
        if cap is not None:
            self.lit('P', 0, POOL_CAP, cap)
        return self

    def zeus(self, v):
        return self.lit('Z', 0, 0, v)

    def uid(self, v):
        return self.lit('G', 0, 0, v)

    def answer(self, which, layer=None):
        """which: 0 = GetLayerFromID, 1 = GetLayerWithDepth, 2 = AddDynamicLayer."""
        off = which * 4
        if layer is None:
            self.lit('X', 0, off, 0)
        else:
            self.ptr('X', 0, off, 'L', layer)
        return self

    def args(self):
        return (self.fn, self.a, self.b, self.c)

    def line(self):
        out = ['%d %d %d %d %d' % (self.fn, self.a, self.b, self.c, len(self.w))]
        for (reg, idx, off, kind, a, b) in self.w:
            out.append('%s %d %d %d %d %d' % (reg, idx, off, kind, a, b))
        return '\n'.join(out) + '\n'


H100 = stub_hash(100) & 0x7fffffff      # the table-3 hash of id 100


def tb(id_, mask=15):
    """Table-3 bucket index for an instance id: (hash & 0x7fffffff) & mask.

    The hash is the harness's documented stub, so the cases can stage buckets
    that agree with what CHashMapCalculateHash (stubbed on both arms) returns.
    """
    return (stub_hash(id_) & 0x7fffffff) & mask


def cases():
    """Deterministic; same list, same order, on every run."""
    C = []
    add = C.append

    # ══ F1 · CRoom::AddInstance: the depth-descending instance chain ═══════
    # Zeus off for this group so the trace is the chain insert + hash only.
    add(Case(1, 0, 0, 0, 'F1-a empty chain: head=tail=inst, snap from +0x180')
        .zeus(0).inst(0, id=100, depth=5.5))
    add(Case(1, 0, 0, 0, 'F1-b walk to the end: tail append')
        .zeus(0).inst(1, id=101, depth=7.0).inst(0, id=100, depth=3.0)
        .room(head=1, tail=1, count=1))
    add(Case(1, 0, 0, 0, 'F1-c stop at the head: insert in front (prev == 0)')
        .zeus(0).inst(1, id=101, depth=1.0).inst(0, id=100, depth=9.0)
        .room(head=1, tail=1, count=1))
    add(Case(1, 0, 0, 0, 'F1-d stop in the middle: splice before cur')
        .zeus(0).inst(1, id=101, depth=9.0, nxt=2).inst(2, id=102, depth=5.0, prev=1, nxt=3)
        .inst(3, id=103, depth=1.0, prev=2)
        .inst(0, id=100, depth=6.0)
        .room(head=1, tail=3, count=3))
    add(Case(1, 0, 0, 0, 'F1-e equal depth: bls puts the new node FIRST')
        .zeus(0).inst(1, id=101, depth=5.0).inst(0, id=100, depth=5.0)
        .room(head=1, tail=1, count=1))
    add(Case(1, 0, 0, 0, 'F1-f sort key is the SNAPSHOT +0x184, not the live depth')
        .zeus(0).inst(1, id=101, depth=1.0, snap=9.0, nxt=2)
        .inst(2, id=102, depth=3.0, prev=1)
        .inst(0, id=100, depth=5.0)
        .room(head=1, tail=2, count=2))
    add(Case(1, 0, 0, 0, 'F1-g id bucket occupied: append at the bucket TAIL')
        .zeus(0).inst(0, id=100, depth=1.0)
        .elem(5, typ=0, uid=0x77, iid=0x55).elem(6, typ=0, uid=0x88)
        .kslot(100 & 15, head=5, tail=6))
    add(Case(1, 1, 0, 0, 'F1-h same, second node of the bucket')
        .zeus(0).inst(1, id=116, depth=2.0)
        .elem(4, typ=0, uid=1).elem(5, typ=0, uid=2)
        .elem(6, typ=0, uid=3, prev=5).elem(5, typ=0, uid=2, nxt=6)
        .kslot(116 & 15, head=4, tail=6))
    add(Case(1, 0, 0, 0, 'F1-i re-register an instance already at the chain head '
             '(no duplicate check: it points at itself)')
        .zeus(0).inst(0, id=100, depth=4.0, in_layer=1)
        .room(head=0, tail=0, count=1))
    add(Case(1, 2, 0, 0, 'F1-j mid-chain node re-registered')
        .zeus(0).inst(2, id=102, depth=5.0, prev=1, nxt=3, in_layer=1)
        .inst(1, id=101, depth=9.0, nxt=2).inst(3, id=103, depth=1.0, prev=2)
        .room(head=1, tail=3, count=3))
    add(Case(1, 0, 0, 0, 'F1-k chain insert + the FULL layer registration '
             '(Zeus live, no layer at the depth -> dynamic layer)')
        .inst(0, id=100, depth=3.0, layer_id=-1)
        .layer(1, id_=77, depth=3).answer(1, layer=1))
    # NOTE: there is no "F1 with room == NULL" case on purpose.  F1 does not
    # check r0: 0x1ab65c dereferences it, so such a case aborts inside the first
    # body on both arms and grades nothing.  See scope.not_covered.

    # ══ F2 · CLayerManager::AddInstance: the four gates and three levels ═══
    add(Case(2, 0, 0, 0, 'F2-a Zeus byte 0: return, nothing registered')
        .zeus(0).inst(0, id=100, depth=1.0))
    add(Case(2, 0, 0, 1, 'F2-b room == NULL: return').inst(0, id=100, depth=1.0))
    add(Case(2, 0x7f, 0, 0, 'F2-c instance == NULL: return'))
    add(Case(2, 0, 0, 0, 'F2-d instance+0x174 already set: return')
        .inst(0, id=100, depth=1.0, in_layer=1))
    add(Case(2, 0, 0, 0, 'F2-e layer id 0 (NOT the -1 sentinel) + GetLayerFromID hit')
        .inst(0, id=100, depth=1.0, layer_id=0).layer(1, 7, 1).answer(0, layer=1))
    add(Case(2, 0, 0, 0, 'F2-f layer id 5 + GetLayerFromID miss -> level 2')
        .inst(0, id=100, depth=1.0, layer_id=5).answer(1, layer=2)
        .layer(2, 9, 1))
    add(Case(2, 0, 0, 0, 'F2-g layer id -1 -> level 2 hit, level 3 must not run')
        .inst(0, id=100, depth=1.0, layer_id=-1).answer(1, layer=2).layer(2, 9, 1))
    add(Case(2, 0, 0, 0, 'F2-h level 2 miss -> level 3 AddDynamicLayer')
        .inst(0, id=100, depth=1.0, layer_id=-1).layer(3, 88, 1))
    add(Case(2, 0, 0, 0, 'F2-i depth 2.9f truncates to 2')
        .inst(0, id=100, depth=2.9).answer(1, layer=1).layer(1, 7, 1))
    add(Case(2, 0, 0, 0, 'F2-j depth -2.9f truncates to -2')
        .inst(0, id=100, depth=-2.9).answer(1, layer=1).layer(1, 7, 1))
    add(Case(2, 0, 0, 0, 'F2-k depth 1e10f saturates to INT_MAX')
        .inst(0, id=100, depth=1e10).answer(1, layer=1).layer(1, 7, 1))
    add(Case(2, 0, 0, 0, 'F2-l depth -1e10f saturates to INT_MIN')
        .inst(0, id=100, depth=-1e10).answer(1, layer=1).layer(1, 7, 1))
    add(Case(2, 0, 0, 0, 'F2-m depth NaN -> 0').inst(0, id=100, depth=1.0)
        .lit('I', 0, INST_DEPTH, 0x7fc00000).answer(1, layer=1).layer(1, 7, 1))
    add(Case(2, 0, 0, 0, 'F2-n depth -0.9f -> 0 (truncation, not floor)')
        .inst(0, id=100, depth=-0.9).answer(1, layer=1).layer(1, 7, 1))

    # ══ F3 · CLayerManager::AddInstanceToLayer ═════════════════════════════
    add(Case(3, 0x7f, 0, 0, 'F3-a layer == NULL: return').inst(0, id=100, depth=1.0))
    add(Case(3, 0, 0, 1, 'F3-b room == NULL: return').inst(0, id=100, depth=1.0))
    add(Case(3, 0, 0x7f, 0, 'F3-c instance == NULL: return').layer(0, 7, 1))
    add(Case(3, 0, 0, 0, 'F3-d instance+0x174 set: return')
        .layer(0, 7, 1).inst(0, id=100, depth=1.0, in_layer=1))
    add(Case(3, 0, 0, 0, 'F3-e empty table, empty pool: grow 1, double to 2, pop, '
             'tail-call AddElementToLayer')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0))
    add(Case(3, 0, 0, 0, 'F3-f uid counter 41 -> the element gets 41')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0).uid(41))
    add(Case(3, 1, 0, 0, 'F3-g deactivated instance: the tail call gets flag 1')
        .layer(1, 12, -3).inst(0, id=100, depth=1.0, deact=1))
    add(Case(3, 0, 0, 0, 'F3-h pool has 3 free elements: pop the head (prev 0, '
             'next 1) and republish the pool head')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .elem(0, nxt=1).elem(1, prev=0, nxt=2).elem(2, prev=1)
        .pool(head=0, tail=2, avail=3, cap=4))
    add(Case(3, 0, 0, 0, 'F3-i pool with a single free element: head and tail '
             'both cleared')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .pool(head=3, tail=3, avail=1, cap=4))
    add(Case(3, 0, 0, 0, 'F3-j free-list head with prev != 0 (inconsistent but '
             'reachable state): prev->next = next, pool head NOT republished')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .elem(0, prev=1, nxt=2).elem(1, nxt=0).elem(2, prev=0)
        .pool(head=0, tail=2, avail=1, cap=4))
    add(Case(3, 0, 0, 0, 'F3-k capacity 0 with a staged head: double only, no Alloc')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .pool(head=5, tail=5, avail=0, cap=0))
    add(Case(3, 0, 0, 0, 'F3-l capacity 2: two Allocs, double to 4, pop the last')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0).pool(avail=0, cap=2))
    add(Case(3, 0, 0, 0, 'F3-m hash hit in the first bucket, value NULL: '
             'still a new element')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0).t3(tb(100), H100))
    add(Case(3, 0, 0, 0, 'F3-n hash hit, element unowned (+0x20 == 0): REUSE, no '
             'AddElementToLayer')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .elem(2, typ=2, uid=9, iid=100)
        .t3(tb(100), H100, value=2))
    add(Case(3, 3, 3, 0, 'F3-o REUSE of a deactivated instance: tail-call '
             'UpdateInstanceActivation')
        .layer(3, 21, 6).inst(3, id=100, depth=1.0, deact=1)
        .elem(2, typ=2, uid=9, iid=100)
        .t3(tb(100), H100, value=2))
    add(Case(3, 2, 2, 0, 'F3-p hash hit, element owned (+0x20 != 0): the error '
             'vtable call, nothing written')
        .layer(2, 7, 4).inst(2, id=100, depth=1.0)
        .elem(4, typ=2, uid=9, iid=100, inst=1)
        .t3(tb(100), H100, value=4))
    add(Case(3, 0, 0, 0, 'F3-q probe: occupant at its ideal slot -> insert here')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .t3(tb(100), 0x0bad0bad)
        .t3((tb(100) + 1) & 15, ((tb(100) + 1) & 15) | 0x100))
    add(Case(3, 0, 0, 0, 'F3-r probe: our hash one slot on -> take the value')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .t3(tb(100), 0x0bad0bad)
        .t3((tb(100) + 1) & 15, H100))
    add(Case(3, 0, 0, 0, 'F3-s probe: walk into an empty bucket')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .t3(tb(100), 0x0bad0bad))
    add(Case(3, 0, 0, 0, 'F3-w probe: occupant 3 slots from ideal, our hash two '
             'on -> the walk must continue, not insert here')
        .layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .t3(tb(100), 0x0bad0bad)
        .t3((tb(100) + 1) & 15, ((tb(100) - 2) & 15) | 0x40)
        .t3((tb(100) + 2) & 15, H100, value=2)
        .elem(2, typ=2, uid=9, iid=100))
    add(Case(3, 0, 0, 0, 'F3-t mask 3: the bucket index really comes from the room')
        .room(t3mask=3).layer(0, 7, 4).inst(0, id=100, depth=1.0)
        .t3(tb(100, 3), H100, value=1)
        .elem(1, typ=2, uid=9, iid=100))
    add(Case(3, 1, 5, 0, 'F3-u instance id 0: bucket 0, layer depth 0')
        .layer(1, 1, 0).inst(5, id=0, depth=0.0))
    add(Case(3, 3, 4, 0, 'F3-v negative layer depth -> the float store is negative')
        .layer(3, 3, -7).inst(4, id=1000, depth=1.0))
    return C


# ── coverage ────────────────────────────────────────────────────────────────
# Two kinds of proof, and the receipt says which is which:
#   * tk()/seq() - CONTROL FLOW, from the original arm's instruction trace.  A
#     branch is a real decision: the next trace entry is the target.
#   * state/log predicates - the PREDICATED store runs (F1 0x1ab6f8..0x1ab720
#     and 0x1ab748..0x1ab768, F3 0x1c5bb4..0x1c5bd0) and the tail calls.  A
#     predicated-off instruction still fires Unicorn's code hook, so the trace
#     cannot tell the two halves apart; what CAN is the memory the half wrote.
def ex(tr, a):
    return a in tr


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


def Ew(st, i, off):
    return st['E'][(i * 36 + off) // 4]


def Iw(st, i, off):
    return st['I'][(i * 0x188 + off) // 4]


def carrying(st):
    """The E index whose +0x20 names an instance (the element handed out)."""
    return [i for i in range(8) if Ew(st, i, E_INST).startswith('I')]


COVER = [
    # ── F1 · control flow ─────────────────────────────────────────────────
    ('f1_empty_chain_branch', lambda tr, r, c: tk(tr, 0x1ab678, 0x1ab774)),
    ('f1_walk_next', lambda tr, r, c: tk(tr, 0x1ab694, 0x1ab67c)),
    ('f1_walk_stop', lambda tr, r, c: tk(tr, 0x1ab688, 0x1ab740)),
    ('f1_walk_off_the_end', lambda tr, r, c: tk(tr, 0x1ab694, 0x1ab698)),
    ('f1_layer_call', lambda tr, r, c: tk(tr, 0x1ab730, 0x1c5d18)),
    ('f1_collision_tail', lambda tr, r, c: bool(calls(r, 'COLL'))),
    ('f1_returns_callee_r0', lambda tr, r, c: r['ret'] == '%08x' % MAGIC_COLL),
    # ── F1 · the predicated hash insert ───────────────────────────────────
    ('f1_hash_empty_bucket_halves', lambda tr, r, c: any(
        a[0] == 'A0' and a[2] == '00000000' and a[3] == '00000000'
        for a in r['allocs'])),
    ('f1_hash_bucket_tail_halves', lambda tr, r, c: any(
        a[0] == 'A0' and a[2].startswith('E') and a[3] == '00000000'
        for a in r['allocs'])),
    ('f1_count_on_empty_chain', lambda tr, r, c: (
        W(r['state'], 'R', ROOM_COUNT) == '00000001'
        and W(r['state'], 'R', ROOM_HEAD) == 'I0'
        and W(r['state'], 'R', ROOM_TAIL) == 'I0')),
    # ── F1 · the predicated splice ────────────────────────────────────────
    ('f1_splice_at_head', lambda tr, r, c: (
        W(r['state'], 'R', ROOM_HEAD).startswith('I')
        and Iw(r['state'], 0, INST_PREV) == '00000000'
        and Iw(r['state'], 0, INST_NEXT) != '00000000')),
    ('f1_splice_in_middle', lambda tr, r, c: (
        Iw(r['state'], 0, INST_PREV).startswith('I')
        and Iw(r['state'], 0, INST_NEXT).startswith('I'))),
    ('f1_tail_append_state', lambda tr, r, c: (
        W(r['state'], 'R', ROOM_TAIL).startswith('I')
        and Iw(r['state'], 0, INST_PREV).startswith('I')
        and Iw(r['state'], 0, INST_NEXT) == '00000000')),
    # ── F2 · gates (each proof includes "control never came back") ─────────
    ('f2_zeus_gate', lambda tr, r, c: tk(tr, 0x1c5d30, 0x1c5d34)
     and not ex(tr, 0x1c5d38)),
    ('f2_room_gate', lambda tr, r, c: tk(tr, 0x1c5d38, 0x1c5d3c)
     and not ex(tr, 0x1c5d40)),
    ('f2_inst_gate', lambda tr, r, c: tk(tr, 0x1c5d40, 0x1c5d44)
     and not ex(tr, 0x1c5d48)),
    ('f2_in_layer_gate', lambda tr, r, c: tk(tr, 0x1c5d4c, 0x1c5d50)
     and not ex(tr, 0x1c5d54)),
    ('f2_sentinel_skips_l1', lambda tr, r, c: tk(tr, 0x1c5d58, 0x1c5d5c)
     and not ex(tr, 0x1c5d60)),
    ('f2_getlayerfromid_call', lambda tr, r, c: tk(tr, 0x1c5d60, 0x1c5d64)
     and bool(calls(r, 'GLID'))),
    ('f2_level1_hit', lambda tr, r, c: tk(tr, 0x1c5d68, 0x1c5d6c)),
    ('f2_level1_miss', lambda tr, r, c: tk(tr, 0x1c5d68, 0x1c5d7c)),
    ('f2_getlayerwithdepth_call', lambda tr, r, c: tk(tr, 0x1c5d90, 0x1c5d94)
     and bool(calls(r, 'GLWD'))),
    ('f2_level2_hit', lambda tr, r, c: tk(tr, 0x1c5d98, 0x1c5d6c)),
    ('f2_level2_miss', lambda tr, r, c: tk(tr, 0x1c5d98, 0x1c5d9c)),
    ('f2_adddynamiclayer_call', lambda tr, r, c: tk(tr, 0x1c5dac, 0x1c5db0)
     and bool(calls(r, 'ADDL'))),
    ('f2_level3_merge', lambda tr, r, c: tk(tr, 0x1c5db4, 0x1c5d6c)),
    ('f2_tail_jump_f3', lambda tr, r, c: tk(tr, 0x1c5d78, 0x1c5a38)),
    ('f2_bool_arg_is_true', lambda tr, r, c: any(
        x[0] == 'GLWD' and x[3] == '00000001' for x in logtoks(r))),
    # ── F2 · the vcvt.s32.f32 model, graded on the argument it produced ────
    ('f2_trunc_2_9_to_2', lambda tr, r, c: any(
        x[0] == 'GLWD' and x[2] == '00000002' for x in logtoks(r))),
    ('f2_trunc_m2_9_to_m2', lambda tr, r, c: any(
        x[0] == 'GLWD' and x[2] == 'fffffffe' for x in logtoks(r))),
    ('f2_saturate_int_max', lambda tr, r, c: any(
        x[0] == 'GLWD' and x[2] == '7fffffff' for x in logtoks(r))),
    ('f2_saturate_int_min', lambda tr, r, c: any(
        x[0] == 'GLWD' and x[2] == '80000000' for x in logtoks(r))),
    ('f2_nan_to_zero', lambda tr, r, c: any(
        x[0] == 'GLWD' and x[2] == '00000000' and x[1].startswith('R0')
        for x in logtoks(r))),
    # ── F3 · gates ────────────────────────────────────────────────────────
    ('f3_gate_layer_or_room', lambda tr, r, c: tk(tr, 0x1c5a54, 0x1c5a6c)
     or tk(tr, 0x1c5a38, 0x1c5a6c)),
    ('f3_gate_inst_null', lambda tr, r, c: tk(tr, 0x1c5a5c, 0x1c5a6c)),
    ('f3_gate_in_layer', lambda tr, r, c: tk(tr, 0x1c5a68, 0x1c5a6c)),
    # ── F3 · the table-3 lookup ───────────────────────────────────────────
    ('f3_hash_call', lambda tr, r, c: tk(tr, 0x1c5a78, 0x1c5a7c)
     and bool(calls(r, 'HASH'))),
    ('f3_bucket_empty', lambda tr, r, c: tk(tr, 0x1c5aa0, 0x1c5ac4)),
    ('f3_bucket_hash_match', lambda tr, r, c: tk(tr, 0x1c5aa8, 0x1c5c6c)),
    ('f3_probe_advance', lambda tr, r, c: tk(tr, 0x1c5ac0, 0x1c5c2c)),
    ('f3_probe_hash_match', lambda tr, r, c: tk(tr, 0x1c5c20, 0x1c5c64)),
    ('f3_probe_insert_here', lambda tr, r, c: tk(tr, 0x1c5c28, 0x1c5ac4)),
    ('f3_probe_empty_bucket', lambda tr, r, c: tk(tr, 0x1c5c60, 0x1c5ac4)),
    ('f3_take_value_null', lambda tr, r, c: tk(tr, 0x1c5c84, 0x1c5ac4)),
    # ── F3 · the pool ─────────────────────────────────────────────────────
    ('f3_pool_needs_grow', lambda tr, r, c: tk(tr, 0x1c5ae0, 0x1c5ae4)),
    ('f3_pool_grow_loop', lambda tr, r, c: tk(tr, 0x1c5b78, 0x1c5af4)),
    ('f3_pool_double_only', lambda tr, r, c: tk(tr, 0x1c5ae0, 0x1c5b80)),
    ('f3_pool_pop_entry', lambda tr, r, c: tk(tr, 0x1c5ad4, 0x1c5b88)),
    ('f3_pool_pop_head_republished', lambda tr, r, c: any(
        W(r['state'], 'P', POOL_HEAD) != '00000000'
        and W(r['state'], 'P', POOL_HEAD) == Ew(r['state'], i, E_NEXT)
        and W(r['state'], 'P', POOL_HEAD) != 'E%d' % i
        and Ew(r['state'], i, E_PREV) == '00000000'
        for i in carrying(r['state']))),
    ('f3_pool_pop_middle_relinked', lambda tr, r, c: any(
        Ew(r['state'], i, E_PREV) != '00000000'
        and Ew(r['state'], j, E_PREV) == Ew(r['state'], i, E_PREV)
        and W(r['state'], 'P', POOL_HEAD) == 'E%d' % i
        for i in carrying(r['state']) for j in range(8)
        if Ew(r['state'], i, E_NEXT) == 'E%d' % j)),
    ('f3_pool_pop_tail_cleared', lambda tr, r, c: any(
        Ew(r['state'], i, E_NEXT) == '00000000'
        and Ew(r['state'], i, E_INST).startswith('I')
        and W(r['state'], 'P', POOL_TAIL) == '00000000'
        for i in carrying(r['state']))),
    # ── F3 · deliver / reuse / error ──────────────────────────────────────
    ('f3_new_element_fields', lambda tr, r, c: tk(tr, 0x1c5b34, 0x1c5b38)),
    ('f3_new_tail_call_ael', lambda tr, r, c: ex(tr, 0x1c5c18)
     and bool(calls(r, 'AEL')) and r['ret'] == '%08x' % MAGIC_AEL),
    ('f3_reuse', lambda tr, r, c: tk(tr, 0x1c5c90, 0x1c5cc0)),
    ('f3_reuse_plain_exit', lambda tr, r, c: tk(tr, 0x1c5cec, 0x1c5a6c)),
    ('f3_reuse_uia_tail', lambda tr, r, c: bool(calls(r, 'UIA'))
     and r['ret'] == '%08x' % MAGIC_UIA),
    ('f3_error_vtable_call', lambda tr, r, c: tk(tr, 0x1c5cb4, 0x1c5cb8)
     and bool(calls(r, 'ERR'))),
    ('f3_error_writes_nothing', lambda tr, r, c: any(
        x[0] == 'ERR' for x in logtoks(r))
        and Iw(r['state'], 2, INST_LID) == 'ffffffff'
        and Iw(r['state'], 2, INST_INL) == '00000000'
        and r['ret'] == '%08x' % MAGIC_ERR),
    ('f3_deact_arg_1', lambda tr, r, c: any(
        x[0] == 'AEL' and x[4] == '00000001' for x in logtoks(r))),
    ('f3_deact_arg_0', lambda tr, r, c: any(
        x[0] == 'AEL' and x[4] == '00000000' for x in logtoks(r))),
    ('f3_uid_read_then_increment', lambda tr, r, c: any(
        a[0] == 'A0' and a[3] == '00000029'
        for a in r['allocs']) and W(r['state'], 'G', 0) == '0000002a'),
]


# ── original arm ────────────────────────────────────────────────────────────
class Stage:
    """One staged environment; hooks installed once.

    Per case only the region contents are rewritten and the log cleared.
    Adding hooks per case would leave the previous case's hooks live on the same
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
        self.heap_base = o.heap
        # the error-host fixture: *0x3eb70c = host, host[0] = vtable,
        # vtable[3] = the stub page (bx lr is not enough: the hook returns a value)
        self.host = o.alloc(4, 4)
        self.vtable = o.alloc(16, 4)
        self.errfn = o.alloc(4, 4)
        o.write(self.errfn, struct.pack('<I', 0xe12fff1e))
        o.write(self.vtable, struct.pack('<4I', 0, 0, 0, self.errfn))
        o.write(self.host, struct.pack('<I', self.vtable))
        self.heap_base = o.heap          # reset to HERE, not to HEAP
        self.heap_start = self.heap_base
        self.allocs = []
        o.write(BSS_ERR_HOST, struct.pack('<I', self.host))
        for addr, fn in ((MM_ALLOC, self.hook_alloc), (HASH, self.hook_hash),
                         (GLID, self.hook_glid), (GLWD, self.hook_glwd),
                         (ADDL, self.hook_addl), (AEL, self.hook_ael),
                         (UIA, self.hook_uia), (COLL, self.hook_coll),
                         (self.errfn, self.hook_err)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F1, end=F1_END - 4)
        o.uc.hook_add(UC_HOOK_CODE, self.hook_trace, begin=F3, end=F2_END - 4)

    # -- hooks --------------------------------------------------------------
    def hook_trace(self, uc_, addr, _s, _d):
        self.tr.append(addr)

    def _ret(self, uc_, v):
        uc_.reg_write(UC_ARM_REG_R0, v & 0xffffffff)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_alloc(self, uc_, _a, _s, _d):
        size = uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff
        path = uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff
        line = uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff
        flag = uc_.reg_read(UC_ARM_REG_R3) & 0xffffffff
        al = (size + ALIGN - 1) // ALIGN * ALIGN
        addr = self.o.alloc(max(al, 1))
        self.o.write(addr, bytes([FILL_BYTE]) * al)
        self.allocs.append((addr, al))
        self.log.append(['ALLOC', len(self.allocs) - 1, size, line, flag,
                         self.o.read_cstr(path, 128)])
        self._ret(uc_, addr)

    def hook_hash(self, uc_, _a, _s, _d):
        key = uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff
        self.log.append(['HASH', key])
        self._ret(uc_, stub_hash(i32(key)))

    def hook_glid(self, uc_, _a, _s, _d):
        self.log.append(['GLID', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff])
        self._ret(uc_, self.rd32(self.base['X'] + 0))

    def hook_glwd(self, uc_, _a, _s, _d):
        self.log.append(['GLWD', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff])
        self._ret(uc_, self.rd32(self.base['X'] + 4))

    def hook_addl(self, uc_, _a, _s, _d):
        self.log.append(['ADDL', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff])
        self._ret(uc_, self.rd32(self.base['X'] + 8))

    def hook_ael(self, uc_, _a, _s, _d):
        self.log.append(['AEL', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R3) & 0xffffffff])
        self._ret(uc_, MAGIC_AEL)

    def hook_uia(self, uc_, _a, _s, _d):
        self.log.append(['UIA', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff,
                         uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff])
        self._ret(uc_, MAGIC_UIA)

    def hook_coll(self, uc_, _a, _s, _d):
        self.log.append(['COLL', uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff])
        self._ret(uc_, MAGIC_COLL)

    def hook_err(self, uc_, _a, _s, _d):
        host = uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff
        msg = uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff
        iid = uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff
        self.log.append(['ERR', host, self.o.read_cstr(msg, 128), iid])
        self._ret(uc_, MAGIC_ERR)

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
        fn, a, b, c = case.args()
        room = 0 if c else self.base['R']
        if fn == 1:
            inst = 0 if a == 0x7f else self.base['I'] + a * REG['I'][1]
            ret = self.o.call(F1, r0=room, r1=inst)
        elif fn == 2:
            inst = 0 if a == 0x7f else self.base['I'] + a * REG['I'][1]
            ret = self.o.call(F2, r0=room, r1=inst)
        else:
            layer = 0 if a == 0x7f else self.base['L'] + a * REG['L'][1]
            inst = 0 if b == 0x7f else self.base['I'] + b * REG['I'][1]
            ret = self.o.call(F3, r0=room, r1=layer, r2=inst)
        return {'ret': ret & 0xffffffff,
                'regions': {reg: bytes(self.o.read(self.base[reg], cnt * st))
                            for reg, cnt, st in REGIONS},
                'allocs': [(ad, sz, bytes(self.o.read(ad, sz)))
                           for ad, sz in self.allocs],
                'calls': [list(x) for x in self.log],
                'tr': list(self.tr)}


# ── pointer normalisation, shared by both arms ──────────────────────────────
def ranges_for(bases, allocs, fixtures):
    out = []
    for reg, count, stride in REGIONS:
        for i in range(count):
            lo = bases[reg] + i * stride
            out.append((lo, lo + stride, '%s%d' % (reg, i)))
    for i, (addr, size) in enumerate(allocs):
        out.append((addr, addr + max(size, 1), 'A%d' % i))
    for name, addr, size in fixtures:
        out.append((addr, addr + size, name))
    return out


def token(v, ranges):
    for lo, hi, name in ranges:
        if lo <= v < hi:
            return name if v == lo else '%s+%x' % (name, v - lo)
    return '%08x' % v


def words(blob):
    return [struct.unpack_from('<I', blob, o)[0] for o in range(0, len(blob) - 3, 4)]


def norm_state(rec, bases, fixtures):
    ranges = ranges_for(bases, [(a, s) for a, s, _ in rec['allocs']], fixtures)
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

SRCS = ['CRoom_AddInstance.c', 'CLayerManager_AddInstance.c',
        'CLayerManager_AddInstanceToLayer.c']


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
    bases, fix, recs = {}, [], []
    cur, allocs = None, []
    for line in txt.splitlines():
        parts = line.split()
        if not parts:
            continue
        tag = parts[0]
        if tag == 'BASE':
            bases[parts[1]] = int(parts[2], 16)
        elif tag == 'FIX':
            fix = [('HOST', int(parts[2], 16), 4),
                   ('VT', int(parts[4], 16), 16),
                   ('ERRFN', int(parts[6], 16), 4)]
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
            if name == 'ALLOC':
                cur['calls'].append(['ALLOC', int(a[0]), int(a[1]), int(a[2]),
                                     int(a[3]), ' '.join(a[4:])])
            elif name == 'ERR':
                cur['calls'].append(['ERR', int(a[0], 16),
                                     ' '.join(a[1:-1]).replace('_', ' '),
                                     int(a[-1], 16)])
            elif name == 'GLWD':
                cur['calls'].append([name, int(a[0], 16), int(a[1], 16),
                                     int(a[2])])
            else:
                cur['calls'].append([name] + [int(x, 16) for x in a])
        elif tag == 'RET':
            cur['ret'] = int(parts[1], 16)
            cur['allocs'] = [tuple(x) for x in allocs]
    if len(bases) != len(REGIONS):
        raise RuntimeError('driver printed %d region bases, expected %d'
                           % (len(bases), len(REGIONS)))
    return {'bases': bases, 'fix': fix, 'recs': recs}


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


def norm_c(rec, bases, fix):
    state, allocs, ranges = norm_state(rec, bases, fix)
    return {'ret': token(rec['ret'], ranges), 'state': state, 'allocs': allocs,
            'calls': fmt_calls(rec, ranges), 'tr': rec.get('tr', [])}


# ── instruction census ───────────────────────────────────────────────────────
import re  # noqa: E402  (kept next to its only user)


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
    base = (MOD / 'src' / FUNCS[3]['src']).read_text()
    m = re.search(r'^.*@0x1c5c18 b 0x1c451c.*$', base, re.M)
    drop = base if not m else base[:m.start()] + base[m.end():]
    trials = {
        'operand_digit_changed':
            {FUNCS[3]['src']: base.replace('bl 0x1b6e44', 'bl 0x1b6e45', 1)},
        'comment_line_deleted': {FUNCS[3]['src']: drop},
        'pool_word_changed':
            {FUNCS[3]['src']: base.replace('.word 0x0022ad9c',
                                           '.word 0x0022ad9d', 1)},
    }
    res, ok = {}, True
    for name, ov in trials.items():
        rep = instruction_census(overrides=ov, fns={3})
        red = not rep['ok']
        res[name] = {'turned_red': red,
                     'wrong': len(rep[FUNCS[3]['name']]['wrong']),
                     'pool_missing': len(rep[FUNCS[3]['name']]['pool_missing'])}
        ok = ok and red
    res['ok'] = ok
    res['note'] = ('a mutation that leaves the gate green means the census does '
                   'not actually bind the translation to the bytes')
    return res


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    # ── F1 ────────────────────────────────────────────────────────────────
    {'name': 'f1_depth_compare_bls_to_bcc', 'file': 'CRoom_AddInstance.c',
     'edits': [("if (!(f32(rd32(cur + INST_DEPTH_SNAP)) > f32(s14))) goto BEFORE;",
                "if (!(f32(rd32(cur + INST_DEPTH_SNAP)) >= f32(s14))) goto BEFORE;")]},
    {'name': 'f1_sort_key_live_depth', 'file': 'CRoom_AddInstance.c',
     'edits': [("if (!(f32(rd32(cur + INST_DEPTH_SNAP)) > f32(s14))) goto BEFORE;",
                "if (!(f32(rd32(cur + INST_DEPTH)) > f32(s14))) goto BEFORE;")]},
    {'name': 'f1_count_increment_dropped', 'file': 'CRoom_AddInstance.c',
     'edits': [('/* @0x1ab670 add r2, r2, #1 */\n    cnt += 1;',
                '/* @0x1ab670 add r2, r2, #1 */\n    cnt += 0;')]},
    {'name': 'f1_tail_append_updates_head', 'file': 'CRoom_AddInstance.c',
     'edits': [('    wr32(r6 + ROOM_INST_TAIL, (u32)(uintptr_t)r4);\n'
                '    /* @0x1ab6ac str r3, [r4, #0x17c] */',
                '    wr32(r6 + ROOM_INST_HEAD, (u32)(uintptr_t)r4);\n'
                '    /* @0x1ab6ac str r3, [r4, #0x17c] */')]},
    {'name': 'f1_head_insert_keeps_old_head', 'file': 'CRoom_AddInstance.c',
     'edits': [('        if (peq) wr32(r6 + ROOM_INST_HEAD, (u32)(uintptr_t)r4);',
                '        if (peq) wr32(r6 + ROOM_INST_TAIL, (u32)(uintptr_t)r4);')]},
    {'name': 'f1_hash_bucket_prev_not_tail', 'file': 'CRoom_AddInstance.c',
     'edits': [('    if (!empty) wr32(node + HNODE_PREV, (u32)(uintptr_t)head);',
                '    if (!empty) wr32(node + HNODE_PREV, 0);')]},
    {'name': 'f1_hash_key_from_snapshot', 'file': 'CRoom_AddInstance.c',
     'edits': [('    id = rd32(r4 + INST_ID);',
                '    id = rd32(r4 + INST_DEPTH_SNAP);')]},
    # ── F2 ────────────────────────────────────────────────────────────────
    {'name': 'f2_zeus_polarity_inverted', 'file': 'CLayerManager_AddInstance.c',
     'edits': [('    if (r3 == 0) return r0;              /* byte 0 -> not registered */',
                '    if (r3 != 0) return r0;              /* inverted */')]},
    {'name': 'f2_sentinel_zero_not_m1', 'file': 'CLayerManager_AddInstance.c',
     'edits': [('    if (r1 == 0xffffffffu) goto LEVEL2;  /* -1 == "use the depth instead" */',
                '    if (r1 == 0) goto LEVEL2;            /* wrong sentinel */')]},
    {'name': 'f2_bool_arg_cleared', 'file': 'CLayerManager_AddInstance.c',
     'edits': [('    layer = CLayerManager_GetLayerWithDepth(room, (int)r1, 1);',
                '    layer = CLayerManager_GetLayerWithDepth(room, (int)r1, 0);')]},
    {'name': 'f2_depth_rounds_half_up', 'file': 'CLayerManager_AddInstance.c',
     'edits': [('    depth = vfp_f2i_trunc(r3);            /* truncate toward zero */',
                '    depth = (s32)(f32(r3) + (f32(r3) >= 0 ? 0.5f : -0.5f));')]},
    {'name': 'f2_level2_hit_ignored', 'file': 'CLayerManager_AddInstance.c',
     'edits': [('    if (layer != 0) goto MERGE;\n', '    if (0) goto MERGE;\n')]},
    # ── F3 ────────────────────────────────────────────────────────────────
    {'name': 'f3_in_layer_gate_inverted',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    if (probe == 0) goto LOOKUP;    /* 0x1c5a68 is beq: 0 -> keep going */',
                '    if (probe != 0) goto LOOKUP;    /* inverted */')]},
    {'name': 'f3_hash_reads_bucket_value',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [("    r2 = rd32((u8 *)(uintptr_t)(buckets + (twice + r3) * 4) + T3_HASH);\n"
                "    /* @0x1c5a9c cmp r2, #0 */",
                "    r2 = rd32((u8 *)(uintptr_t)(buckets + (twice + r3) * 4) + T3_VALUE);\n"
                "    /* @0x1c5a9c cmp r2, #0 */")]},
    {'name': 'f3_probe_distance_flipped',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    if ((s32)dist < (s32)probe) goto NEW;   /* occupant is closer: insert here */',
                '    if ((s32)dist > (s32)probe) goto NEW;   /* flipped */')]},
    {'name': 'f3_pool_double_halves', 'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    r3 <<= 1;\n', '    r3 >>= 1;\n')]},
    {'name': 'f3_pop_head_writes_tail',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    if (r3 == 0) wr32(pool + POOL_HEAD, r2);      /* flags: 0x1c5bac */',
                '    if (r3 == 0) wr32(pool + POOL_TAIL, r2);      /* swapped */')]},
    {'name': 'f3_uid_read_after_increment',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    r3 = rd32(&g_element_uid);          /* the OLD uid */',
                '    r3 = rd32(&g_element_uid) + 1;      /* wrong: +1 first */')]},
    {'name': 'f3_instance_depth_from_layer_id',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    s15 = rd32(ly + LAYER_DEPTH);       /* the layer depth, as an int */',
                '    s15 = rd32(ly + LAYER_ID);          /* wrong field */')]},
    {'name': 'f3_elem_flag_not_set', 'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    wr8((u8 *)(uintptr_t)occ + ELEM_FLAG, (u8)one);',
                '    wr8((u8 *)(uintptr_t)occ + ELEM_FLAG, 0);')]},
    {'name': 'f3_owned_element_reuses',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    if (r2 == 0) goto REUSE;            /* element is in the table, unowned */',
                '    if (r2 != 0) goto REUSE;            /* inverted */')]},
    {'name': 'f3_deact_arg_reads_other_byte',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    r3 = rd8(in + INST_DEACTIVATED);    /* the 4th argument of the tail call */',
                '    r3 = rd8(in + INST_IN_LAYER);       /* wrong byte */')]},
    {'name': 'f3_chain_attr_from_layer_not_room',
     'file': 'CLayerManager_AddInstanceToLayer.c',
     'edits': [('    mask = rd32(rm + ROOM_T3_MASK);',
                '    mask = rd32(rm + ROOM_T3_CAPACITY);')]},
]


def rowview(rec, ):
    """The receipt's per-case view: every compared facet, with each region
    reduced to a digest of its token list.  The full state is kept for rows that
    differ, so a green run stays inspectable without a 2 MB receipt."""
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
        recs = [norm_c(r, out['bases'], out['fix']) for r in out['recs']]
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
            r = norm_c(out['recs'][0], out['bases'], out['fix'])
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
    """Re-derive each body's GOT slot from the bytes: `ldr rX,[pc,#imm]` loads
    the pool word, `ldr rX,[pc,rX]` adds it to (instruction address + 8).

    This is what caught the card's off-by-one-slot for the error host: the
    arithmetic lands on 0x3ed71c, not on the 0x3ed718 the card names, and the
    two cells point at different .bss.
    """
    out = []
    for name, insn, pool_addr, want in GOT_DERIVATION:
        word = struct.unpack('<I', o.read(pool_addr, 4))[0]
        slot = (insn + 8 + word) & 0xffffffff
        out.append({'body': name, 'ldr': hex(insn), 'pool_word': '%08x' % word,
                    'slot': hex(slot), 'want': hex(want), 'ok': slot == want})
    return out


def rodata_string(so, vaddr, n=128):
    from elftools.elf.elffile import ELFFile
    with open(so, 'rb') as f:
        elf = ELFFile(f)
        for seg in elf.iter_segments():
            if (seg['p_type'] == 'PT_LOAD'
                    and seg['p_vaddr'] <= vaddr < seg['p_vaddr'] + seg['p_filesz']):
                f.seek(seg['p_offset'] + (vaddr - seg['p_vaddr']))
                return f.read(n).split(b'\0')[0].decode('latin-1')
    raise RuntimeError('vaddr %#x not in any PT_LOAD' % vaddr)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('room_add_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    # binding: the pinned image, the five GOT cells, the three strings
    img_sha = sha(SO)
    o = Oracle()
    got = {hex(a): got_slot(o, a) for a in GOT_SLOTS}
    got_ok = all(got[hex(a)] == v for a, v in GOT_SLOTS.items())
    deriv = derive_got_slots(o)
    deriv_ok = all(d['ok'] for d in deriv)
    strings = {}
    for name, insn, pool_addr, want in STR_DERIVATION:
        word = struct.unpack('<I', o.read(pool_addr, 4))[0]
        addr = (insn + 8 + word) & 0xffffffff
        got_s = rodata_string(SO, addr)
        strings[name] = {'add_at': hex(insn), 'pool_word': '%08x' % word,
                         'addr': hex(addr), 'want': want, 'got': got_s,
                         'ok': got_s == want}
    strings_ok = all(v['ok'] for v in strings.values())
    census = instruction_census()
    stest = census_selftest()

    # claim arm
    base_bin = build_c(BUILD / 'room_add.arm')
    c_out = run_c_arm(base_bin, case_list)
    c_recs = [norm_c(r, c_out['bases'], c_out['fix']) for r in c_out['recs']]

    # judge arm
    stage = Stage(o)
    A = {reg: stage.base[reg] for reg, _c, _s in REGIONS}
    fixA = [('HOST', stage.host, 4), ('VT', stage.vtable, 16),
            ('ERRFN', stage.errfn, 4)]
    a_raw = [stage.run(c) for c in case_list]
    a_recs = [norm_c(r, A, fixA) for r in a_raw]

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_recs, c_recs):
        eq = same(a, c)
        row = {'case': case.args(), 'label': case.label,
               'original': rowview(a), 'rebuild': rowview(c), 'equal': eq}
        if not eq:
            # only a failing case carries the full state: see rowview()
            row['original_full'] = a
            row['rebuild_full'] = c
            mismatches.append(row)
        rows.append(row)

    # repeat: a second Unicorn instance and a second qemu process
    stage2 = Stage(Oracle())
    A2 = {reg: stage2.base[reg] for reg, _c, _s in REGIONS}
    fix2 = [('HOST', stage2.host, 4), ('VT', stage2.vtable, 16),
            ('ERRFN', stage2.errfn, 4)]
    a_rep = [norm_c(stage2.run(c), A2, fix2) for c in case_list]
    c_out2 = run_c_arm(base_bin, case_list)
    c_rep = [norm_c(r, c_out2['bases'], c_out2['fix']) for r in c_out2['recs']]
    repeat = {'original': all(same(x, y) for x, y in zip(a_recs, a_rep)),
              'rebuild': all(same(x, y) for x, y in zip(c_recs, c_rep)),
              'original_sha256': [_digest(a_recs), _digest(a_rep)],
              'rebuild_sha256': [_digest(c_recs), _digest(c_rep)],
              'original_bases_differ': A['R'] != A2['R'],
              'rebuild_bases_same': (c_out['bases'] == c_out2['bases'])}

    coverage, covered_by = {}, {}
    for name, fn in COVER:
        hits = [c.label for c, a in zip(case_list, a_recs) if fn(a['tr'], a, c)]
        coverage[name] = bool(hits)
        covered_by[name] = hits[:2]

    teeth = [teeth_one(m, case_list, a_recs) for m in MUTANTS]

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    rep_ok = repeat['original'] and repeat['rebuild']
    binding_ok = img_sha == PIN and got_ok and strings_ok and deriv_ok
    status = ('PASS' if (identity and cov_ok and teeth_ok and binding_ok
                         and rep_ok and census['ok'] and stest['ok']) else 'FAIL')

    receipt = {
        'schema': 'cally-room-add-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': (
            'synthetic memory oracle: the original ARM bytes of THREE bodies '
            '(0x1ab654 CRoom::AddInstance, 0x1c5d18 CLayerManager::AddInstance, '
            '0x1c5a38 CLayerManager::AddInstanceToLayer) executed over the '
            "image's own .bss cells, with F1's bl landing in F2/F3's original "
            'bytes and every unrecovered callee stubbed identically on both '
            'arms; NOT device execution'),
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
            'header_sha256': sha(MOD / 'src' / 'room_add.h'),
            'driver_sha256': sha(MOD / 'fixture' / 'driver.c'),
            'got_slots': got,
            'got_slots_expected': {hex(a): hex(v) for a, v in GOT_SLOTS.items()},
            'got_match': got_ok,
            'got_slot_derivation': deriv,
            'got_slot_derivation_ok': deriv_ok,
            'rodata_strings': strings,
            'rodata_strings_ok': strings_ok,
            'stub_callees': ['CHashMapCalculateHash@0x1b6e44',
                             'GetLayerFromID@0x1b8868',
                             'GetLayerWithDepth@0x1b87f4',
                             'AddDynamicLayer@0x1c33e4',
                             'AddElementToLayer@0x1c451c',
                             'UpdateInstanceActivation@0x1b8a28',
                             'CollisionInsert@0x1cc494',
                             'MemoryManager::Alloc@0x27ce78',
                             'the error host vtable+0xc'],
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
                'F1: count increment before the empty-chain branch; walk on the '
                'SNAPSHOT +0x184; bls (<=, unordered) stop; tail append via '
                'room+0x80; head/middle splice; id-hash append at the bucket '
                'TAIL with no duplicate check; the bl into F2; the b into '
                'CollisionInsert and the resulting return value',
                'F2: all four gates in machine order (Zeus byte polarity, '
                'room, instance, +0x174); the cmn #1 layer-id sentinel vs a '
                'real id 0; GetLayerFromID hit/miss; the vcvt.s32.f32 '
                'truncation on 2.9 / -2.9 / 1e10 / -1e10 / NaN / -0.9; the '
                'hard-coded TRUE third argument; level 2 hit suppresses level '
                '3; AddDynamicLayer; the tail jump into F3',
                'F3: the three gates; hash + 31-bit clear + mask from the room; '
                'the 12 B bucket stride; empty bucket, first-bucket hash match, '
                'probe advance, probe hash match, probe insert-here, probe into '
                'an empty bucket; value NULL; the owned/unowned split; the '
                'error vtable call and its "writes nothing" contract; the pool '
                'grow loop (one and two elements), the capacity doubling, the '
                'capacity <= 0 double-only path, the free-list pop with prev 0 '
                '/ prev != 0 / next 0; the uid counter read-then-increment; the '
                'three instance field writes; both tails (AddElementToLayer '
                'with the deactivated byte, UpdateInstanceActivation)',
            ],
            'not_covered': [
                'the semantics of every stubbed callee: a green run says the '
                'chain passes the right ARGUMENTS to them and passes their r0 '
                'through, nothing more',
                'the real CHashMapCalculateHash: the harness uses a documented '
                'model (key*2654435761), so only the probe STATE MACHINE is '
                'graded, not the original hash',
                "F3's 0x1c5ac0 `tst r2,r4 ; bpl` early-out: it can only fall "
                'through when the table mask has bit 31 set, which needs a '
                '0x80000000-entry table.  The instruction is translated and '
                'documented, but no case takes that edge.  Same for the dead '
                'guards at 0x1c5c64 (idx == -1) and 0x1c5c74 (bucket == -4)',
                "F3's 0x1c5b10 branch on Alloc returning NULL: taken only when "
                'the allocator fails, and the fall-through writes through a '
                'NULL pointer, so staging it measures a fault, not behaviour. '
                'The Alloc stub never returns NULL',
                "F1 does not check room == NULL (it dereferences r0 at "
                '0x1ab65c); a NULL-room case would abort both arms inside the '
                'first body and prove nothing, so it is not staged',
                'the class identity of the host object whose vtable+0xc is '
                'called on the error path (card open) and what the real '
                'CollisionInsert returns (the body reads its r0)',
                'device behaviour: this is a synthetic-memory oracle over the '
                'original bytes, not execution on a phone',
            ],
            'observability': [
                'every case compares the returned word, every word of every '
                'staged region (11 regions, pointers normalised to region / '
                'alloc tokens) and every allocated block, so a store the '
                'translation forgot and a store it invented both show up',
                'the call log records each stub call in order with the '
                'arguments the body passed: the layer id, the truncated depth, '
                'the bool, the deactivated byte and the element pointer are '
                'read out of the log, not out of the input',
                'the three tails return magic constants, so "does this body '
                'return its tail callee\'s r0" is graded, not assumed',
            ],
            'staging_geometry': {
                'shared': 'one write program interpreted by both arms; only the '
                          'region bases differ (the judge arm uses the image\'s '
                          'own .bss cells for H/Z/G/P, the claim arm its own '
                          'globals)',
                'regions': {r: {'count': c, 'stride': hex(s)}
                            for r, c, s in REGIONS},
            },
        },
        'findings': [
            'CARD DRIFT: the F3 error host is GOT slot 0x3ed71c -> 0x3eb70c, '
            'not the 0x3ed718 -> 0x479a94 the card names.  The harness staging '
            'the card\'s cell made the original run `blx` into garbage '
            '(UC_ERR_INSN_INVALID at 0x1c5cb4); the pc-relative arithmetic '
            '(0x1c5ca4 + 0x00227a78) is the authority, and binding() now '
            're-derives all five slots from the pool words.',
            'CARD DRIFT: the F3 message string is at 0x350864 and reads '
            '"Attempting to add instance %d multiple times to a layer", not '
            '" ERROR: Adding too many variables" at 0x35285c.  Everything else '
            'matched case for case; this was the single identity diff left '
            'before the string was corrected.',
            'the 0x1c5abc/0x1c5ac0 probe early-out (`tst r2,r4 ; bpl`) can only '
            'fall through when the table mask carries bit 31, i.e. for a '
            '0x80000000-entry table: with any sane mask the probe ALWAYS '
            'advances and the ordering decision is made at 0x1c5c24 '
            '(`cmp r7,r5 ; blt`).  Case F3-w is the one that makes that '
            'comparison observable at all, because the probe only chooses '
            'new-vs-reuse: flipping the comparison is invisible unless the walk '
            'would have found our hash further on.',
            'CRoom::AddInstance returns CollisionInsert\'s r0, not `inst`: '
            '0x1ab734 seeds r0 and 0x1ab73c is a `b` after the frame is popped. '
            'With a void callee that is inst in practice, but the body gives no '
            'such guarantee and the differential proves the pass-through with '
            'a distinctive stub return (f1_returns_callee_r0).',
            'F1 has NO duplicate check and does not look at +0x174: '
            're-registering an instance that is already the chain head makes it '
            'point at ITSELF (case F1-i: inst->next == inst), bumps room+0x88 '
            'from 1 to 2, and appends a second id-hash node for the same key.  '
            'The idempotence the cards describe lives in F2/F3\'s +0x174 gate, '
            'not here -- so a second call on an already-registered instance is '
            'safe only because F2/F3 do nothing, while the chain and the count '
            'are already corrupted.',
            'the chain sort key is the SNAPSHOT at +0x184 (case F1-f): a node '
            'whose live depth was changed after insertion still sorts by the '
            'value captured when it was inserted, and the empty-chain branch '
            'copies +0x180 into +0x184 with `ldr`/`str`, not through a float '
            'operation.',
            'F2 raises the same r0-residue question on its four gate exits: the '
            'function is void and never writes r0, so each exit returns the '
            'first argument.  The translation reproduces it and says so.',
            'F3\'s error path returns the vtable callee\'s r0 as well, and '
            'writes no field: an instance that already owns a live element is '
            'left exactly as it was (fail-soft, not an assert).',
            'the 36 B pool grows by `capacity` elements and then DOUBLES the '
            'capacity unconditionally -- including on the capacity <= 0 path, '
            'which allocates nothing (case F3-k).  A pool with capacity 0 and '
            'a non-empty free list therefore still hands out an element and '
            'keeps capacity 0.',
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
    out = args.out or (RECEIPTS / ('room_add_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d identical=%d binding=%s repeat=%s census=%d/%d '
          'selftest=%s'
          % (status, len(case_list), sum(1 for r in rows if r['equal']),
             'ok' if binding_ok else 'MISMATCH',
             'ok' if rep_ok else 'DRIFT',
             census['documented'], census['instructions'],
             'ok' if stest['ok'] else 'NO'))
    if not census['ok']:
        for w in census['wrong'][:8]:
            print('  CENSUS %s objdump=%r source=%r'
                  % (w['addr'], w['objdump'], w['source']))
        for w in census['pool_missing'][:8]:
            print('  CENSUS pool %s word=%s undocumented' % (w['addr'], w['word']))
    for k, v in coverage.items():
        print('  COVER %-30s %s' % (k, 'yes' if v else 'NO'))
    for t in teeth:
        print('  TEETH %-34s %s mode=%-20s caught_by=%d'
              % (t['mutant'], 'PASS' if t['passed'] else 'FAIL', t['mode'],
                 len(t['caught_by'])))
    for m in mismatches[:6]:
        print('  DIFF case=%r' % (m['label'],))
        for k in ('ret', 'state', 'allocs', 'calls'):
            if m['original'][k] != m['rebuild'][k]:
                print('    %s original=%r' % (k, m['original'][k])[:400])
                print('    %s rebuild =%r' % (k, m['rebuild'][k])[:400])
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
