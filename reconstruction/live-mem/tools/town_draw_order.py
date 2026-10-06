#!/usr/bin/env python3
"""Find the town CRoom via Run_Room_List and dump its live draw order.

Run_Room_List (VA 0x542990) header first word = room count (114).
Container assumed {count, data}; each CRoom: +0x94 instance count,
+0x80/+0x84 draw-list head/tail, entries: +0x78 id, +0x180 depth,
+0x17c next link, +0x65 visible, +0x68 skip, +0x69 deactivated,
+0xb4/+0xb8 x/y.

Usage: town_draw_order.py <pid> <rw_base_hex> [room_idx]
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
ONLY = int(sys.argv[3]) if len(sys.argv) > 3 else None
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

cnt = u32(live(0x542990))
data = u32(live(0x542990) + 4)
print(f"Run_Room_List count={cnt} data={data:#x}")

rooms = []
for i in range(min(cnt, 120)):
    try:
        r = u32(data + i * 4)
        n = u32(r + 0x94) if r else 0
        rooms.append((i, r, n))
    except Exception:
        rooms.append((i, 0, -1))

top = sorted(rooms, key=lambda t: -t[2])[:6]
print("rooms by instance count:", [(i, hex(r), n) for i, r, n in top])

targets = [ONLY] if ONLY is not None else [i for i, _, n in top[:2]]
for ri in targets:
    r = dict((i, rr) for i, rr, _ in rooms)[ri]
    head = u32(r + 0x80); tail = u32(r + 0x84)
    print(f"\n=== room {ri} @{r:#x} head={head:#x} tail={tail:#x} ===")
    seq = []
    n = tail; guard = 0
    while n and n != 0xFFFFFFFF and guard < 400:
        seq.append((f32(n + 0x180), u32(n + 0x78), f32(n + 0xB4), f32(n + 0xB8),
                    u8(n + 0x65), u8(n + 0x68), u8(n + 0x69)))
        n = u32(n + 0x17C); guard += 1
    print(f"walked {len(seq)}")
    viol = sum(1 for i in range(len(seq)-1) if seq[i+1][0] - seq[i][0] > 1e-6)
    print(f"ordering violations: {viol}")
    pl = [e for e in seq if 640 <= e[2] <= 660]
    print(f"player-x candidates: {[(e[1], round(e[2],1), round(e[3],1)) for e in pl]}")
    deact = sum(1 for e in seq if e[6])
    print(f"deactivated in list: {deact}")
    print("first 12 (draw order):")
    for e in seq[:12]:
        print(f"  d={e[0]:7.2f} id={e[1]:7d} x={e[2]:8.2f} y={e[3]:8.2f} "
              f"v={e[4]} s={e[5]} de={e[6]}")
    print("last 4:")
    for e in seq[-4:]:
        print(f"  d={e[0]:7.2f} id={e[1]:7d} x={e[2]:8.2f} y={e[3]:8.2f} "
              f"v={e[4]} s={e[5]} de={e[6]}")
