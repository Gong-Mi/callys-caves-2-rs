#!/usr/bin/env python3
"""Read GML global variables from the live shell (YYObjectBase hash layout).

RE anchors (libyoyo 3bbedd09):
  scope   = *(g_pGlobal VA 0x544BE0)
  map     = [scope + 0x60]
  mask    = [map + 8]        data = [map + 16]
  hash(i) = i + 1            (CHashMapCalculateHash@0x1b6e44 = add r0,r0,#1)
  entry   = data + slot*12   { ?, RValue* @+4, hash @+8 }   slot = hash & mask,
          linear probe on mismatch, miss when stored hash == 0
  RValue  = 16 bytes (type byte in +12 high 8 bits; payload +0..+11)

Usage: global_get.py <pid> <rw_base_hex> [name ...]   (names from globals-name-map.json)
"""
import json, os, pathlib, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
WANT = sys.argv[3:]
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

scope = u32(0x544BE0)
map_ = h32(scope + 0x60)
mask = h32(map_ + 8); data = h32(map_ + 16)
print(f"scope={scope:#x} map={map_:#x} mask={mask:#x} data={data:#x}")

def lookup(idx):
    h = (idx + 1) & 0x7FFFFFFF
    slot = h & mask
    for _ in range(mask + 2):
        e = data + slot * 12
        stored = h32(e + 8)
        if stored == 0:
            return None
        if stored == h:
            p = h32(e + 4)
            if p == 0 or p == 0xFFFFFFFC or p == 0xFFFFFFFF:
                return None
            return p
        slot = (slot + 1) & mask
    return None

def rvalue(p):
    v0, v1, v2, tag = struct.unpack("<4I", rd(p, 16))
    t = (tag >> 24) & 0xFF
    as_int = struct.unpack("<i", struct.pack("<I", v0))[0]
    as_dbl = struct.unpack("<d", struct.pack("<II", v0, v1))[0]
    return t, v0, v1, v2, as_int, as_dbl

names = {int(k): v for k, v in json.load(
    open(pathlib.Path(__file__).parent.parent / 'globals-name-map.json')).items()}
targets = WANT or [n for i, n in sorted(names.items())][:0]
if WANT:
    sel = [(i, n) for i, n in names.items() if n in WANT]
else:
    sel = sorted(names.items())[:40]
for i, n in sel:
    p = lookup(i)
    if not p:
        print(f"  {n:16s} idx={i:3d}  <no slot>")
        continue
    t, v0, v1, v2, as_int, as_dbl = rvalue(p)
    kind = 'real' if abs(as_dbl) < 1e30 and as_dbl == as_dbl else 'int/other'
    print(f"  {n:16s} idx={i:3d} ptr={p:#x} type={t:#04x} int={as_int:>12} "
          f"dbl={as_dbl!r} words={v0:#010x},{v1:#010x},{v2:#010x}")
