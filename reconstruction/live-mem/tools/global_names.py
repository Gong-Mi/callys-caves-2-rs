#!/usr/bin/env python3
"""Resolve global-variable name table + values (guard evaluation base).

RE anchors (libyoyo 3bbedd09):
  g_pGlobal          VA 0x544BE0 (bss) -> globals storage
  g_nGlobalVariables VA 0x544B4C
  g_VarNamesGlobal   VA 0x47A19C -> {count, ?, elem_stride?, ptr}
Usage: global_names.py <pid> <rw_base_hex> [n_dump]
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
ND = int(sys.argv[3]) if len(sys.argv) > 3 else 20
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
hw = struct.unpack("<4I", rd(A(0x47A19C), 16))
print(f"g_pGlobal={pglob:#x} g_nGlobalVariables={ncount}")
print("g_VarNamesGlobal:", [hex(x) for x in hw])
pnames = hw[3]
print(f"name table @{pnames:#x}")
head = struct.unpack("<16I", rd(pnames, 64))
print("  head:", [hex(x) for x in head])
# try both interpretations
for stride, label in ((4, 'ptr array stride4'), (8, 'pair {ptr,idx} stride8')):
    print(f"-- {label} --")
    for i in range(min(ND, 16)):
        try:
            p = h32(pnames + i*stride)
            print(f"   [{i}] {p:#x} {cstr(p)!r}")
        except Exception as ex:
            print(f"   [{i}] ERR {ex}"); break

print(f"\nglobals storage {pglob:#x} (8-byte elements):")
raw = rd(pglob, 8*min(ND,24))
v = struct.unpack(f"<{2*min(ND,24)}I", raw)
for i in range(min(ND, 24)):
    print(f"  [{i}] {v[2*i]:#010x} {v[2*i+1]:#010x}")
