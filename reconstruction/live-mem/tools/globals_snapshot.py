#!/usr/bin/env python3
"""Snapshot the globals storage region; diff two snapshots to identify slots.

Usage:
  globals_snapshot.py <pid> <rw_base_hex> save <out.bin>
  globals_snapshot.py <pid> <rw_base_hex> diff <a.bin> <b.bin>
"""
import os, struct, sys, json, pathlib

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16); mode = sys.argv[3]
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

N = u32(0x544B4C)                      # g_nGlobalVariables
pglob = u32(0x544BE0)
names = json.load(open(pathlib.Path(__file__).parent.parent / 'globals-name-map.json'))
name_by_idx = {int(k): v for k, v in names.items()}

if mode == 'save':
    size = N * 8
    blob = rd(pglob, size)
    pathlib.Path(sys.argv[4]).write_bytes(blob)
    print(f"saved {size} bytes from {pglob:#x} -> {sys.argv[4]}")

elif mode == 'diff':
    a = pathlib.Path(sys.argv[4]).read_bytes()
    b = pathlib.Path(sys.argv[5]).read_bytes()
    words_a = struct.unpack(f"<{len(a)//4}I", a[:len(a)//4*4])
    words_b = struct.unpack(f"<{len(b)//4}I", b[:len(b)//4*4])
    print("changed 4-byte words (idx = word//2 for 8B elements):")
    shown = 0
    for i, (x, y) in enumerate(zip(words_a, words_b)):
        if x != y:
            slot8 = i // 2
            nm = name_by_idx.get(slot8, '?')
            print(f"  word[{i:4d}] slot8[{slot8:3d}] {nm:16s} {x:#010x} -> {y:#010x}")
            shown += 1
            if shown > 60: print('  ...'); break
    if shown == 0:
        print("  no changes")
else:
    print("mode must be save|diff")
