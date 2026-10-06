#!/usr/bin/env python3
"""Read instance variables of a live instance (same YYObjectBase hash layout).

  CInstance derives from YYObjectBase: map = [instance + 0x60]
  mask = [map+8], data = [map+16], hash(i) = i+1, entry = data + slot*12,
  entry {?, RValue* @+4, hash @+8}, RValue 16B (type byte in +12 high 8 bits)

Name tables (same {count, f1, elem_size, ptr} shape as g_VarNamesGlobal):
  g_VarNamesInstance 0x47A18C   g_VarNamesLocal 0x47A17C

Usage: instance_get.py <pid> <rw_base_hex> <object_name> [var ...]
       instance_get.py <pid> <rw_base_hex> --names <substr>
"""
import json, os, pathlib, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OBJ = sys.argv[3]
WANT = sys.argv[4:]
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
    return cnt, out

icnt, inames = name_table(0x47A18C)
lcnt, lnames = name_table(0x47A17C)
print(f"g_VarNamesInstance: {icnt} entries, {len(inames)} named")
print(f"g_VarNamesLocal:    {lcnt} entries, {len(lnames)} named")

if OBJ == '--names':
    for s, i in sorted(inames.items(), key=lambda kv: kv[1]):
        if not WANT or any(w in s for w in WANT):
            print(f"  i[{i:4d}] {s}")
    sys.exit(0)

# find instance by object name from the room draw list
scope_va = u32(0x54298C)
room = scope_va
n = h32(room + 0x84)
target = None
while n and n != 0xFFFFFFFF:
    gm = h32(n + 0x80)
    nm = cstr(h32(gm + 0x14))
    if nm == OBJ:
        target = n; break
    n = h32(n + 0x17C)
if not target:
    print(f"instance of {OBJ} not found in current room"); sys.exit(1)
print(f"{OBJ} instance @{target:#x}")

map_ = h32(target + 0x60)
mask = h32(map_ + 8); data = h32(map_ + 16)
print(f"map={map_:#x} mask={mask:#x} data={data:#x}")

def lookup(idx):
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

def dump_var(name, mapping):
    idx = mapping.get(name)
    if idx is None:
        print(f"  {name:20s} <not in name table>"); return
    p = lookup(idx)
    if not p:
        print(f"  {name:20s} idx={idx:4d} <no slot>"); return
    v0, v1, v2, tag = struct.unpack("<4I", rd(p, 16))
    t = (tag >> 24) & 0xFF
    dbl = struct.unpack("<d", struct.pack("<II", v0, v1))[0]
    as_int = struct.unpack("<i", struct.pack("<I", v0))[0]
    print(f"  {name:20s} idx={idx:4d} ptr={p:#x} type={t:#04x} "
          f"int={as_int:>12} dbl={dbl!r}")

for w in WANT or ['invulnerable', 'facing', 'hsp', 'vspeed', 'hitpickup', 'type']:
    if w in inames:
        dump_var(w, inames)
    elif w in lnames:
        dump_var(w, lnames)
    else:
        print(f"  {w:20s} <unknown>")
