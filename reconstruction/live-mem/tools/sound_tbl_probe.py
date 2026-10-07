#!/usr/bin/env python3
"""Dump the live sound-table object at data slot 0x75529C and check the RUNTIME
dispatch-record table entries that carry the loader VA 0x219048.

Usage: sound_tbl_probe.py <pid> <rw_base_hex>
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OFF = 0x3F2000
LIB = "/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so"

def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET); b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

# INLINE struct: fields live at the data VAs themselves (no slot deref).
print("sound table inline struct @0x75529C:")
for off in (0x00, 0x18, 0x20, 0x24, 0x28, 0x30, 0x34, 0x48, 0x4c):
    print(f"  +{off:#05x} = {u32(0x75529C + off):#x}")

fdata = open(LIB, "rb").read()
print("dispatch records near 0x1c88c (file==vaddr in LOAD#1):")
for s in (0x1c860, 0x1c874, 0x1c888, 0x1c89c, 0x1c8b0):
    words = struct.unpack("<IIII", fdata[s:s+16])
    print(f"  @{s:#07x}: " + " ".join(hex(w) for w in words))
    # 16B record shape guess: {type, name_ptr, fn_ptr, size}
    typ, namep, fnp, size = words
    if 0x2000 <= namep < 0x3F0000 and typ == 0x80012:
        name = fdata[namep:namep+64].split(b"\x00")[0]
        print(f"      name={name!r} fn={fnp:#x} size={size:#x}")
        if fnp:
            print(f"      fn first words: " + " ".join(
                hex(struct.unpack('<I', fdata[fnp+4*i:fnp+4*i+4])[0]) for i in range(4)))
