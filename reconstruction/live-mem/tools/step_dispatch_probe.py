#!/usr/bin/env python3
"""DECISIVE test: does obj_music's Step event run in the live shell?

CODE 377 head: `if (soundplay >= 16) soundplay = 0;` — an unconditional clamp at
the top of Step. Inject 17.0 into the soundplay RValue; if Step dispatches, the
value drops to 0 within a few frames. If it stays 17.0 forever, Step never runs.

Usage: step_dispatch_probe.py <pid> <rw_base_hex>
"""
import os, struct, sys, time

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET); b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

def obj_find(want):
    rr = u32(0x54298C)
    n = struct.unpack("<I", rd(rr + 0x84, 4))[0]; c = 0
    while n and c < 250:
        og = struct.unpack("<I", rd(n + 0x80, 4))[0]
        p = struct.unpack("<I", rd(og + 0x14, 4))[0]
        nm = rd(p, 40).split(b"\x00")[0].decode("ascii", "replace")
        if nm == want:
            return n
        n = struct.unpack("<I", rd(n + 0x17c, 4))[0]; c += 1
    return None

def inst_var(inst, idx):
    mp = struct.unpack("<I", rd(inst + 0x60, 4))[0]
    mask = struct.unpack("<I", rd(mp + 8, 4))[0]
    data = struct.unpack("<I", rd(mp + 16, 4))[0]
    h = idx + 1; slot = h & mask
    for _ in range(mask + 1):
        e = data + slot * 12
        s = struct.unpack("<I", rd(e + 8, 4))[0]
        if s == 0: return None
        if s == h: return struct.unpack("<I", rd(e + 4, 4))[0]
        slot = (slot + 1) & mask
    return None

mus = obj_find("obj_music")
if not mus:
    sys.exit("obj_music not in draw list")
x = struct.unpack("<f", rd(mus + 0xb4, 4))[0]
y = struct.unpack("<f", rd(mus + 0xb8, 4))[0]
vis, skip, deact = rd(mus+0x65,1)[0], rd(mus+0x68,1)[0], rd(mus+0x69,1)[0]
print(f"obj_music inst={mus:#x} pos=({x},{y}) visible={vis} skip={skip} deactivated={deact}")
sp = inst_var(mus, 636)
print("soundplay rvalue @", hex(sp))

v = struct.unpack("<d", rd(sp, 8))[0]
print(f"before inject: {v}")
f = open(f"/proc/{pid}/mem", "rb+", buffering=0)
os.lseek(f.fileno(), sp, os.SEEK_SET); f.write(struct.pack("<d", 17.0)); f.close()
print("injected 17.0 (Step head must clamp >=16 -> 0)")
for i in range(10):
    v = struct.unpack("<d", rd(sp, 8))[0]
    print(f"  t{i}: soundplay={v}")
    if v == 0.0:
        print("  => STEP RUNS (clamp executed)")
        break
    time.sleep(1.0)
else:
    print("  => STEP NEVER RAN for obj_music (17.0 untouched after 10s)")
