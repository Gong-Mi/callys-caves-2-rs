#!/usr/bin/env python3
"""Decode ms_ID2InstanceE (id->instance container) in a live callyscaves2-shell.

v1 observed the header as {ptr,511,180} = {table, capacity-1, count}.
This probe:
  1. reads the container header + the full table,
  2. sanity-checks entry count vs header count,
  3. hunts the town player instance (x ~ 649 per v1 town evidence) to anchor
     CInstance layout (x/y at +0xb4/+0xb8 per skill),
  4. dumps the player's leading words so the instance-id field can be pinned.

Usage: decode_id2inst.py <pid> <rw_base_hex>
"""
import os, struct, sys

pid = int(sys.argv[1])
RW = int(sys.argv[2], 16)
SEG_OFF = 0x3F2000  # read_views.py formula

def live(va):
    return RW + (va - SEG_OFF)

def rd(addr, n):
    with open(f"/proc/{pid}/mem", "rb", buffering=0) as f:
        os.lseek(f.fileno(), addr, os.SEEK_SET)
        b = os.read(f.fileno(), n)
        if len(b) < n:
            raise RuntimeError(f"short read @{addr:#x}: {len(b)}/{n}")
        return b

def u32(addr): return struct.unpack("<I", rd(addr, 4))[0]
def f32(addr): return struct.unpack("<f", rd(addr, 4))[0]

MS_ID2INST_VA   = 0x536F28
MS_CREATE_VA    = 0x536F20
RUN_ROOM_VA     = 0x54298C
CUR_ROOM_VA     = 0x542958

hdr     = u32(live(MS_ID2INST_VA))
capm1   = u32(live(MS_ID2INST_VA) + 4)
count   = u32(live(MS_ID2INST_VA) + 8)
create  = u32(live(MS_CREATE_VA))
curroom = u32(live(CUR_ROOM_VA))
runroom = u32(live(RUN_ROOM_VA))

print(f"container hdr: table={hdr:#x} cap-1={capm1} count={count} "
      f"createCounter={create} room={curroom} runroom={runroom:#x}")

# dump the table: capm1+1 u32 slots
cap = capm1 + 1
tbl = rd(hdr, cap * 4)
slots = struct.unpack(f"<{cap}I", tbl)
nonnull = [(i, p) for i, p in enumerate(slots) if p not in (0, 0xFFFFFFFF)]
print(f"table slots={cap} nonnull={len(nonnull)} (header says {count})")

# classify: dense prefix or sparse
idxs = [i for i, _ in nonnull]
print(f"first indices: {idxs[:8]} ... last: {idxs[-4:]}")

# try to find the player: scan instances for x in [640..660]
hits = []
for i, p in nonnull[:256]:
    try:
        x = f32(p + 0xB4)
        y = f32(p + 0xB8)
    except Exception:
        continue
    if 640.0 <= x <= 660.0 and -1000.0 < y < 10000.0:
        hits.append((i, p, x, y))
print(f"player-x candidates: {[(i, hex(p), x, y) for i, p, x, y in hits]}")

# dump leading words of the first hit (or first entry) to pin the id field
if hits:
    i, p, x, y = hits[0]
else:
    i, p = nonnull[0]
words = struct.unpack("<32I", rd(p, 0x80))
print(f"instance @{p:#x} (slot {i}) leading 0x80 bytes:")
for w in range(0, 32, 4):
    print(f"  +{w*4:#04x}: " + " ".join(f"{v:#010x}" for v in words[w:w+4]))
print(f"  +0xb4 x={f32(p+0xB4)}  +0xb8 y={f32(p+0xB8)}")

# id hypothesis: GM ids look like 100000+n (v1 draw list had 200002/200001)
# scan the leading words for values in [100000..300000]
cand = [(off*4, v) for off, v in enumerate(words) if 100000 <= v <= 300000]
print(f"id-looking words (100000..300000): {[(hex(o), v) for o, v in cand]}")
