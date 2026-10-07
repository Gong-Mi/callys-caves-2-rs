#!/usr/bin/env python3
"""Read the mute/playlist globals via the contract §2 layout, then decide which
branch of CODE 377 Step explains a frozen soundplay.

Usage: mute_check.py <pid> <rw_base_hex>
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET); b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

sc = struct.unpack("<I", rd(A(0x544BE0), 4))[0]
mp = struct.unpack("<I", rd(sc + 0x60, 4))[0]
mask = struct.unpack("<I", rd(mp + 8, 4))[0]
data = struct.unpack("<I", rd(mp + 16, 4))[0]
def gvar(idx):
    h = idx + 1
    slot = h & mask
    for _ in range(mask + 1):
        e = data + slot * 12
        s = struct.unpack("<I", rd(e + 8, 4))[0]
        if s == 0:
            return None
        if s == h:
            rp = struct.unpack("<I", rd(e + 4, 4))[0]
            w = rd(rp, 16)
            tag = w[12]
            return struct.unpack("<d", w[:8])[0], tag
        slot = (slot + 1) & mask
    return None

for idx, name in [(18, "musicmute"), (19, "soundmute"), (10, "roomstart")]:
    r = gvar(idx)
    print(f"global.{name}[{idx}] = {r}")
