#!/usr/bin/env python3
"""Dump an instance/global variable's raw RValue + chase its array payload.

Goal: pin the GMS array layout (YYArray) so `theme[]`-style arrays can be read.

Usage: array_probe.py <pid> <rw_base_hex> <obj_name> <var_name>
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OBJ, VAR = sys.argv[3], sys.argv[4]
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]
def h32(a): return struct.unpack("<I", rd(a, 4))[0]
def cstr(a, n=64):
    try: return rd(a, n).split(b"\x00")[0].decode("ascii", "replace")
    except Exception: return None

def name_table(va):
    cnt, f1, esz, ptr = struct.unpack("<4I", rd(A(va), 16))
    out = {}
    raw = rd(ptr, 4*cnt)
    for i in range(cnt):
        p = struct.unpack_from('<I', raw, 4*i)[0]
        if p:
            s = cstr(p)
            if s: out[s] = i
    return out

inames = name_table(0x47A18C)
gnames = name_table(0x47A19C)

def lookup(m, mask, data, idx):
    h = (idx + 1) & 0x7FFFFFFF; slot = h & mask
    for _ in range(mask + 2):
        e = data + slot*12
        stored = h32(e + 8)
        if stored == 0: return None
        if stored == h:
            p = h32(e + 4)
            return None if p in (0, 0xFFFFFFFC, 0xFFFFFFFF) else p
        slot = (slot + 1) & mask
    return None

# find instance
room = u32(0x54298C); n = h32(room + 0x84); inst = None
while n and n != 0xFFFFFFFF:
    gm = h32(n + 0x80)
    if cstr(h32(gm + 0x14)) == OBJ:
        inst = n; break
    n = h32(n + 0x17C)
if not inst:
    print(f"{OBJ} not found"); sys.exit(1)
m = h32(inst + 0x60)
idx = inames.get(VAR)
print(f"{OBJ}@{inst:#x} var {VAR} idx={idx}")
p = lookup(m, h32(m+8), h32(m+16), idx)
if not p:
    print("no slot"); sys.exit(1)
words = struct.unpack("<4I", rd(p, 16))
print(f"RValue @{p:#x}: {[hex(w) for w in words]} type={(words[3]>>24)&0xFF:#04x}")
payload = words[0]
if not (0x8000000 <= payload <= 0xf0000000):
    print("payload is not a pointer; scalar value:", struct.unpack('<d', struct.pack('<II', words[0], words[1]))[0])
    sys.exit(0)
print(f"payload -> {payload:#x}; dumping 0x80 bytes:")
raw = rd(payload, 0x80)
w = struct.unpack("<32I", raw)
for i in range(0, 32, 4):
    print(f"  +{i*4:#04x}: " + " ".join(f"{v:#010x}" for v in w[i:i+4]))
# heuristic: look for a small count (like 17) followed by pointer(s)
for i, v in enumerate(w):
    if v in (17, 16):
        print(f"  candidate length {v} at +{i*4:#x}; words after: "
              f"{[hex(x) for x in w[i+1:i+5]]}")
