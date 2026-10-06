#!/usr/bin/env python3
"""Full room census on a live callyscaves2-shell: draw order + names + camera
+ tie-break anomaly localization + storage-container cross-checks.

Reads (all binary-verified, see live-findings-v2.md sec.5/6):
  Run_Room VA 0x54298C; views at room+0x48+4i (view0 camera at +4/+8)
  draw list: room+0x84 tail -> +0x17c links; CInstance +0x78 id, +0x80
  CObjectGM* (+0x14 name), +0x180 depth, +0x65/68/69 flags, +0xb4/b8 x/y
  sec container: room+0xc8 -> {count, 40B records: +0 depth, +4 y, +8 inst,
  +12 spawn_seq}
  id map: VA 0x536F28 {table, 511, count}

Usage: room_census.py <pid> <rw_base_hex>
"""
import os, struct, sys
from collections import Counter

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
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
def cstr(a):
    try: return rd(a, 40).split(b"\x00")[0].decode("ascii", "replace")
    except Exception: return None

room = u32(live(0x54298C))
v0 = u32(room + 0x48)
print(f"room={room:#x}  room+0x94={u32(room+0x94)}")
print(f"view0: xy=({f32(v0+4):.1f},{f32(v0+8):.1f}) wh=({f32(v0+12):.1f}x{f32(v0+16):.1f})")

# --- draw list walk
tail = u32(room + 0x84)
seq = []
n = tail
while n and n != 0xFFFFFFFF and len(seq) < 600:
    obj = u32(n + 0x80)
    seq.append(dict(p=n, d=f32(n + 0x180), id=u32(n + 0x78),
                    x=f32(n + 0xB4), y=f32(n + 0xB8),
                    v=u8(n + 0x65), s=u8(n + 0x68), de=u8(n + 0x69),
                    name=cstr(u32(obj + 0x14)) or "?"))
    n = u32(n + 0x17C)
print(f"draw list: {len(seq)} entries, deactivated={sum(1 for e in seq if e['de'])}, "
      f"invisible={sum(1 for e in seq if not e['v'])}, skipflag={sum(1 for e in seq if e['s'])}")

dv = sum(1 for i in range(len(seq)-1) if seq[i+1]["d"] - seq[i]["d"] > 1e-6)
print(f"depth-order violations: {dv}")

# --- tie runs + anomaly localization
i = 0; anomalies = []; runs = 0
while i < len(seq):
    j = i
    while j + 1 < len(seq) and abs(seq[j+1]["d"] - seq[i]["d"]) < 1e-6:
        j += 1
    if j > i:
        runs += 1
        for k in range(i, j):
            if seq[k+1]["id"] > seq[k]["id"]:
                anomalies.append((seq[k], seq[k+1]))
    i = j + 1
print(f"tie runs: {runs}; newer-first violations: {len(anomalies)}")
for a, b in anomalies:
    print(f"  ANOMALY drawn: ... id={a['id']}({a['name']}) THEN id={b['id']}({b['name']}) d={a['d']}")
    print(f"    a: ptr={a['p']:#x} x={a['x']} y={a['y']}  b: ptr={b['p']:#x} x={b['x']} y={b['y']}")

# --- storage container at room+0xc8 (boot-time staging; freed after room
# load, so reads may fault — guard everything)
try:
    stor = u32(room + 0xC8)
    scount = u32(stor)
except Exception as ex:
    stor = 0; scount = -1
    print(f"storage(+0xc8): unreadable ({ex}) — likely freed after room load")
recs = []
base = stor + 4
for k in range(min(max(scount,0), 400)):
    recs.append((f32(base + k*40), f32(base + k*40 + 4),
                 u32(base + k*40 + 8), u32(base + k*40 + 12)))
print(f"storage(+0xc8): count={scount}")
if recs:
    ids_in_list = {e["p"] for e in seq}
    inst_ptrs = {r[2] for r in recs}
    overlap = sum(1 for e in seq if e["p"] in inst_ptrs)
    print(f"  storage inst ptrs overlapping draw-list ptrs: {overlap}/{len(recs)}")
    seqs = [r[3] for r in recs]
    print(f"  spawn_seq monotonic non-decreasing: {all(seqs[k+1] >= seqs[k] for k in range(len(seqs)-1))}")
    print(f"  first3 records (depth,y,inst,seq): {[(r[0], r[1], hex(r[2]), r[3]) for r in recs[:3]]}")

# --- id map quick state
tab = u32(live(0x536F28)); mcount = u32(live(0x536F28) + 8)
raw = rd(tab, 512*8)
pop = 0
for k in range(512):
    a, b = struct.unpack_from("<II", raw, k*8)
    if a not in (0, 0xFFFFFFFF): pop += 1
print(f"id map: populated={pop} header_count={mcount}")

print("\ndraw order (all):")
for e in seq:
    print(f"  d={e['d']:6.2f} id={e['id']:7d} {e['name']:24s} x={e['x']:8.1f} y={e['y']:8.1f} "
          f"v={e['v']} s={e['s']} de={e['de']}")
