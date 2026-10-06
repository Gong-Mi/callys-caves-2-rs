#!/usr/bin/env python3
"""Read GML array elements from an instance (YYArray layout, binary-verified).

ARRAY_RVAL_RValue@0xcede4 decode:
  array RValue: [rv+0] = YYArray*, type slot (+12 & 0xFF000000) == 2
  YYArray:      [+0x04] = row-descriptor array (stride 8), [+0x10] = row count
  row desc:     [+0] = inner length, [+4] = row data pointer
  element:      row_data + inner_index*16   (RValue, 16 B)
  index pack:   outer = i / 32000, inner = i % 32000

Usage: array_get.py <pid> <rw_base_hex> <obj> <var> [first_n]
"""
import json, os, pathlib, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OBJ, VAR = sys.argv[3], sys.argv[4]
N = int(sys.argv[5]) if len(sys.argv) > 5 else 20
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    with open(f"/proc/{pid}/mem", "rb", buffering=0) as f:
        os.lseek(f.fileno(), a, os.SEEK_SET)
        b = os.read(f.fileno(), n)
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

room = u32(0x54298C); n = h32(room + 0x84); inst = None
while n and n != 0xFFFFFFFF:
    gm = h32(n + 0x80)
    if cstr(h32(gm + 0x14)) == OBJ:
        inst = n; break
    n = h32(n + 0x17C)
if not inst:
    print(f"{OBJ} not found"); sys.exit(1)
m = h32(inst + 0x60)
rv = lookup(m, h32(m+8), h32(m+16), inames.get(VAR))
print(f"{OBJ}@{inst:#x} {VAR} rvalue@{rv:#x}")
words = struct.unpack("<4I", rd(rv, 16))
print(f"  rvalue words: {[hex(w) for w in words]} type_slot={(words[3] & 0xFF000000):#x}")
arr = words[0]
if (words[3] & 0xFF000000) != 0x02000000 and (words[3] & 0xFF000000) != 0x0:
    print("  not marked as array (type slot != 2); trying anyway")
rows = h32(arr + 4); nrows = h32(arr + 0x10)
print(f"  YYArray@{arr:#x} rows_desc={rows:#x} row_count={nrows}")
vals = []
for i in range(min(nrows, 4)):
    desc = rows + i * 8
    length = h32(desc); data = h32(desc + 4)
    print(f"  row[{i}] len={length} data={data:#x}")
    for j in range(min(length, N)):
        er = data + j * 16
        v0, v1, v2, tag = struct.unpack("<4I", rd(er, 16))
        t = (tag >> 24) & 0xFF
        dbl = struct.unpack("<d", struct.pack("<II", v0, v1))[0]
        i32 = struct.unpack("<i", struct.pack("<I", v0))[0]
        # Verified live: array elements keep tag 0 while their payload IS a
        # double at +0..+7 (theme[0..3] read 37/46/52/35 for playlist 1).
        # Report the double when it is finite and integral-ish, else the int.
        if t in (5, 7) or (v1 != 0 and abs(dbl) < 1e15 and dbl == int(dbl)):
            vals.append(int(dbl) if dbl == int(dbl) else dbl)
        elif t == 0 and v1 == 0:
            vals.append(i32)
        else:
            vals.append(f"?t={t:#x},v0={v0:#x},v1={v1:#x}")
        
print("  values:", vals)
