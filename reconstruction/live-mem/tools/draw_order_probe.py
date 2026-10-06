#!/usr/bin/env python3
"""Walk the room's live depth-sorted draw list (tail->head = actual draw order).

Structure (binary-verified this round):
  Run_Room+0x80 = list head (min depth end), +0x84 = tail (max depth end)
  CInstance: +0x78 id, +0x80 CObjectGM*, +0x180 depth f32, +0x188 list key,
             +0x178/+0x17c prev/next links, +0x65 visible, +0x68 skip,
             +0x69 deactivated, +0xb4/+0xb8 x/y f32
  DrawInstancesOnly iterates TAIL -> +0x17c -> HEAD, skipping +0x68/+0x69,
  drawing +0x65-visible; ties: new instance lands after existing equal node
  (toward head) => drawn LATER => in FRONT (matches Unicorn [200002,200001]).

Usage: draw_order_probe.py <pid> <rw_base_hex> [max_entries]
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
MAX = int(sys.argv[3]) if len(sys.argv) > 3 else 256
OFF = 0x3F2000
def live(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(a): return struct.unpack("<I", rd(a, 4))[0]
def f32(a): return struct.unpack("<f", rd(a, 4))[0]
def u8(a): return rd(a, 1)[0]

room = u32(live(0x54298C))
head = u32(room + 0x80); tail = u32(room + 0x84)
room_n = u32(room + 0x94)
print(f"room={room:#x} head={head:#x} tail={tail:#x} room+0x94={room_n}")

seq = []  # (depth, id, x, y, vis, d69, obj)
n = tail
guard = 0
while n and n not in (0xFFFFFFFF,) and guard < MAX:
    depth = f32(n + 0x180)
    iid   = u32(n + 0x78)
    x     = f32(n + 0xB4)
    y     = f32(n + 0xB8)
    vis   = u8(n + 0x65)
    skip  = u8(n + 0x68)
    deact = u8(n + 0x69)
    obj   = u32(n + 0x80)
    seq.append((depth, iid, x, y, vis, skip, deact, obj))
    n = u32(n + 0x17C)
    guard += 1

print(f"walked {len(seq)} entries (guard {guard})")
# ordering property: depths must be non-increasing along walk (tail=max first)
viol = [(i, seq[i][0], seq[i+1][0]) for i in range(len(seq)-1)
        if seq[i+1][0] - seq[i][0] > 1e-6]
print(f"ordering violations (next deeper than prev): {len(viol)} {viol[:5]}")

# tie runs: within equal-depth runs ids must be non-INCREASING (newer id
# drawn first — verified live: 1 violation in 128 comparisons at d=2.0)
tie_viol = 0
i = 0
while i < len(seq):
    j = i
    while j + 1 < len(seq) and abs(seq[j+1][0] - seq[i][0]) < 1e-6:
        j += 1
    if j > i:
        for k in range(i, j):
            if seq[k+1][1] > seq[k][1]:
                tie_viol += 1
    i = j + 1
print(f"tie-run newer-first violations: {tie_viol}")

# player anchor: x ~ 649 (v1 town evidence)
pl = [e for e in seq if 640.0 <= e[2] <= 660.0]
print(f"player-x candidates: {[(e[1], round(e[2],1), round(e[3],1), e[0]) for e in pl]}")

print("\ndraw seq (tail->head): depth id x y vis skip deact")
for e in seq[:40]:
    print(f"  d={e[0]:7.2f} id={e[1]:7d} x={e[2]:8.2f} y={e[3]:8.2f} "
          f"v={e[4]} s={e[5]} de={e[6]}")
print("  ..." if len(seq) > 40 else "")
