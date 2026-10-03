#!/usr/bin/env python3
"""Full instance census of the original runner via ms_ID2InstanceE.

Registry layout (from CInstance statics + the camera's bucket walk):
  ms_ID2InstanceE slot (VA 0x536F28) -> container {table_ptr, mask=0x1ff, count}
  table = array of 512 bucket slots (8 bytes each); each non-null slot points
  to a chain of nodes: node = {next(+0, ptr), ?, obj_id(+8, i32), inst(+12, ptr)}
  instance x/y = floats at +0xb4/+0xb8 (read by CCamera::CameraUpdate).
"""
import struct, sys, os

PID = int(sys.argv[1])
RW_BASE = 0x803c7000
RW_VA = 0x3f2000

def live(va):
    return RW_BASE + (va - RW_VA)

fd = os.open(f"/proc/{PID}/mem", os.O_RDONLY)

def rd(addr, n):
    try:
        d = os.pread(fd, n, addr)
        return d if d and len(d) == n else None
    except OSError:
        return None

def u32(a):
    d = rd(a, 4)
    return struct.unpack("<I", d)[0] if d else None

def i32(a):
    d = rd(a, 4)
    return struct.unpack("<i", d)[0] if d else None

def f32(a):
    d = rd(a, 4)
    return struct.unpack("<f", d)[0] if d else None

slot = live(0x536F28)
table = u32(slot)
mask = 0x1ff
count = u32(0xeadc07f0 + 0x80 + 8)
print(f"ms_ID2InstanceE slot -> table={table:#x} mask={mask} count={count}")

seen = set()
census = []
for b in range((mask or 511) + 1):
    node = u32(table + b * 8)
    guard = 0
    while node and guard < 64:
        if node in seen:
            break
        seen.add(node)
        nxt = u32(node + 0)
        obj = i32(node + 8)
        inst = u32(node + 12)
        if inst and inst not in [c[0] for c in census]:
            x = f32(inst + 0xB4)
            y = f32(inst + 0xB8)
            if x is not None and y is not None:
                census.append((inst, obj, x, y))
        node = nxt
        guard += 1

print(f"census: {len(census)} instances")
from collections import Counter
cnt = Counter(obj for (_, obj, _, _) in census)
print("object histogram (id xN):", dict(sorted(cnt.items())))

print("\ninstances inside the town bounds (0..1024, 0..576):")
for (inst, obj, x, y) in census:
    if 0.0 <= x <= 1024.0 and 0.0 <= y <= 576.0:
        tag = ""
        if obj == 100000:
            tag = "  <=== PLAYER (rm_town placement 100000)"
        if abs(x - 649.0) < 3.0 and abs(y - 494.0) < 3.0:
            tag = "  <=== matches centering prediction (view 425+224=649)"
        print(f"  inst {inst:#x} id {obj:6d} x={x:8.2f} y={y:8.2f}{tag}")
os.close(fd)
