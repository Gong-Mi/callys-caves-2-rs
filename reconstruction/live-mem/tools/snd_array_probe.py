#!/usr/bin/env python3
"""Faithful replay of Audio_GetSoundSourceToPlay(0x21632c) against the live
shell: dump the 54-entry CSound array + per-entry state, then read what the
sequencer gate (audio_is_playing) would see.

Usage: snd_array_probe.py <pid> <rw_base_hex>
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
def d32(va): return struct.unpack("<I", rd(A(va), 4))[0]

# inline table at 0x75529C: +0x0 self/vtable?, +0x18 cap(128), +0x20 count(54),
# +0x24 arr, +0x28/+0x2c secondary ranges (0x2163b4/0x21641c branches)
arr = d32(0x7552C0)
count = d32(0x7552BC)
print(f"inline tbl: cap+0x18={d32(0x7552B4)} count+0x20={count} arr+0x24={arr:#x}")
nonnull = nulls = 0
for idx in range(count):
    p = struct.unpack("<I", rd(arr + idx*4, 4))[0]
    if p: nonnull += 1
    else: nulls += 1
print(f"CSound array: {nonnull} non-null / {nulls} null of {count}")

for idx in (0, 1, 2, 29, 32, 52):
    p = struct.unpack("<I", rd(arr + idx*4, 4))[0]
    if not p:
        print(f"  sond[{idx}] = NULL")
        continue
    flag27 = rd(p + 0x27, 1)[0]
    w0 = struct.unpack("<I", rd(p, 4))[0]
    name = ""
    try:
        name = rd(w0, 48).split(b"\x00")[0].decode("ascii", "replace")
        if not all(32 <= ord(c) < 127 for c in name): name = f"(not-str {w0:#x})"
    except Exception:
        name = f"(bad {w0:#x})"
    f4c = struct.unpack("<I", rd(p + 0x4c, 4))[0]
    print(f"  sond[{idx}] CSound={p:#x} flag+0x27={flag27} +0x4c={f4c:#x} name={name!r}")
