#!/usr/bin/env python3
"""Resolve all global-variable names + values; determine element stride.

Layout (verified live): g_VarNamesGlobal = {count, ?, elem_size, ptr};
ptr -> array of 691 name-string pointers (stride 4).
Storage g_pGlobal: element size = the 'elem_size' field (probe both 4 and 8).

Usage: globals_dump.py <pid> <rw_base_hex> [name ...]
"""
import os, struct, sys, json, pathlib

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
def cstr(a, n=64):
    try: return rd(a, n).split(b"\x00")[0].decode("ascii", "replace")
    except Exception: return None

pglob = u32(0x544BE0); ncount = u32(0x544B4C)
cnt, f1, esize, pnames = struct.unpack("<4I", rd(A(0x47A19C), 16))
print(f"names header: count={cnt} f1={f1} elem_size={esize} ptr={pnames:#x}")
print(f"g_pGlobal={pglob:#x} g_nGlobalVariables={ncount}")

name_by_idx = {}
raw = rd(pnames, 4*cnt)
for i in range(cnt):
    p = struct.unpack_from('<I', raw, 4*i)[0]
    if p:
        name_by_idx[i] = cstr(p)
print(f"named globals: {len(name_by_idx)}/{cnt}")

def rvalue(idx):
    # RValue = 16 bytes: payload +0..+11, type tag word at +12 (top byte = type)
    b = rd(pglob + idx*16, 16)
    v0, v1, v2, tag = struct.unpack('<IIII', b)
    t = (tag >> 24) & 0xFF
    return v0, v1, v2, t, b

targets = WANT or ['soundmute','musicmute','rebuff','health1','health2','health3','health4',
                   'score','playerdied','roomstart','roomcamefrom','level','coins','gems',
                   'warplock','keydrop','weapon','curweapon','bosshp','area']
found = {}
for idx, nm in sorted(name_by_idx.items()):
    if nm in targets:
        found[nm] = (idx, rvalue(idx))
for nm in targets:
    if nm in found:
        idx, (v0, v1, v2, t, b) = found[nm]
        as_int = struct.unpack('<i', struct.pack('<I', v0))[0]
        as_dbl = struct.unpack('<d', b[:8])[0]
        print(f"  {nm:14s} idx={idx:3d} type={t:#04x} v0={v0:#010x}({as_int}) "
              f"v1={v1:#010x} v2={v2:#010x} as_double={as_dbl!r}")
    else:
        print(f"  {nm:14s} NOT FOUND")
# dump full name list to a file for later joins
out = pathlib.Path(__file__).parent.parent / 'globals-name-map.json'
json.dump({str(k): v for k, v in sorted(name_by_idx.items())}, open(out, 'w'), indent=0)
print(f"name map -> {out} ({len(name_by_idx)} entries)")
