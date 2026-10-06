#!/usr/bin/env python3
"""Global-variable reader for the live shell (guard evaluation base).

RE anchors (libyoyo 3bbedd09):
  g_pGlobal         VA 0x544BE0 (bss)  -> globals storage
  g_nGlobalVariables VA 0x544B4C        -> count
  g_VarNamesGlobal  VA 0x47A19C (16 B)  -> {ptr?, count?} name table (probe)
  Variable_Global_GetVari(int, RValue*) @0x1f3984

Prints: storage pointer, count, name-table words, then tries to resolve a set
of requested names (default: the guard-relevant ones) and dumps their values.

Usage: global_read.py <pid> <rw_base_hex> [name ...]
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
NAMES = sys.argv[3:] or ['soundmute','musicmute','rebuff','health1','score','level',
                         'coins','lives','weapon','health2','health3','health4']
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
def cstr(a, n=48):
    try: return rd(a, n).split(b"\x00")[0].decode("ascii", "replace")
    except Exception: return None

pglob = u32(0x544BE0)
ncount = u32(0x544B4C)
print(f"g_pGlobal={pglob:#x} g_nGlobalVariables={ncount}")
names_words = struct.unpack("<4I", rd(A(0x47A19C), 16))
print("g_VarNamesGlobal words:", [hex(w) for w in names_words])
pnames = u32(0x47A19C)
if pnames:
    print(f"names table @{pnames:#x}:")
    try:
        head = struct.unpack("<8I", rd(pnames, 32))
        print("  head words:", [hex(w) for w in head])
        # try {count, ptr} or {ptr, count}
        for cand_off in (0, 4):
            cnt = head[cand_off//4]
            ptr = head[1 - cand_off//4]
            if 0 < cnt < 20000 and 0x8000000 <= ptr <= 0xf0000000:
                print(f"  layout guess: count@{cand_off:#x}={cnt}, data={ptr:#x}")
                # dump first strings
                for i in range(0, min(cnt, 24)):
                    try:
                        sp = h32(ptr + i*4)
                        s = cstr(sp) if sp else None
                        print(f"    [{i}] {sp:#x} {s!r}")
                    except Exception as ex:
                        print(f"    [{i}] ERR {ex}"); break
                break
    except Exception as ex:
        print("  names read failed:", ex)

# value read: RValue is 8 bytes {int/int64 or type-tagged}; try raw words
print(f"\nvalues (index: raw u32 pair) from storage {pglob:#x}:")
for i in range(0, min(ncount, 24)):
    try:
        v0, v1 = struct.unpack("<II", rd(pglob + i*8, 8))
        print(f"  [{i}] {v0:#010x} {v1:#010x}")
    except Exception as ex:
        print(f"  [{i}] ERR {ex}"); break
