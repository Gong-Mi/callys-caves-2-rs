#!/usr/bin/env python3
"""Raw scan libyoyo for `ldr rB,[pc,#imm]` + `add rB,pc,rB` pairs and report the
data VA each computes. No capstone (its per-chunk disasm stops at embedded
thumb/data words and silently skips pairs).

Encodings:
  ldr rB,[pc,#imm]  : 1110 0101 1 001 1111 imm12          -> (w & 0x0FFF0FFF) == 0x051F0000
  add rB,pc,rB      : 1110 00 0 0 0 0 1 111 B 0000 00 00 B -> (w & 0x0FFF0FF0) == 0x008F0000 and Rd==Rm
"""
import struct, sys

LIB = "/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so"
f = open(LIB, "rb").read()
lo, hi = 0x2000, 0x3F0000

W = lambda o: struct.unpack("<I", f[o:o + 4])[0]

def literal_addr(i_w, va):
    # EMPIRICAL for this ELF (verified x2 against live: Audio_Initialize base
    # 0x755470=1; PlaySound gates 0x3EF054/0x3EED38 byte 0/1):
    # the pc-relative literal sits at (addr+8) + imm12 field, unshifted.
    imm = i_w & 0xFFF
    return ((va + 8) & ~3) + imm

pairs = {}   # data_va -> list of ldr_va
for va in range(lo, hi, 4):
    w1 = W(va)
    if (w1 & 0xFFFF0000) != 0xE59F0000:  # LDR literal, Rn=PC; Rt+imm12 wildcard
        continue
    reg = (w1 >> 12) & 0xF
    w2 = W(va + 4)
    if (w2 & 0xFFFF0FE0) != 0xE08F0000 or ((w2 >> 12) & 0xF) != reg or (w2 & 0xF) != reg:
        continue
    lit = literal_addr(w1, va)
    if lit + 4 > len(f):
        continue
    val = W(lit)
    dva = (val + ((va + 4 + 8) & ~3)) & 0xFFFFFFFF
    pairs.setdefault(dva, []).append(va)

for want in [int(x, 16) for x in sys.argv[1:]]:
    # exact or +-0x40 neighborhood (functions often anchor a few slots before)
    near = {d: v for d, v in pairs.items() if abs(d - want) <= 0x40}
    print(f"target {want:#x}:")
    for d, v in sorted(near.items()):
        print(f"  base {d:#x}: {len(v)} sites {[hex(x) for x in v[:14]]}")
    if not near:
        print("  (none)")

# anchor self-test: Audio_Initialize base 0x75546c from ldr@0x221a38/add@0x221a3c
print("anchor 0x75546c sites:", [hex(x) for x in pairs.get(0x75546C, [])][:20])
