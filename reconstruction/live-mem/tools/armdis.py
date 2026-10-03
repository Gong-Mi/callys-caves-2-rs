#!/usr/bin/env python3
"""Disassemble a VA range of a (32-bit ARM) ELF with capstone.

For libyoyo LOAD#1: vaddr == file offset (zero-based), so file[va:va+n] is the
code. Tries the requested mode; caller can run both arm/thumb and compare.

Usage: dis.py <file> <va_hex> <n_insns> [arm|thumb]
"""
import sys

from capstone import CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, Cs

path = sys.argv[1]
va = int(sys.argv[2], 16)
n = int(sys.argv[3])
mode = sys.argv[4] if len(sys.argv) > 4 else "arm"

data = open(path, "rb").read()
step = 4 if mode == "arm" else 2
code = data[va : va + n * step]
md = Cs(CS_ARCH_ARM, CS_MODE_ARM if mode == "arm" else CS_MODE_THUMB)
count = 0
for insn in md.disasm(code, va):
    print(f"{insn.address:08x}: {insn.mnemonic}\t{insn.op_str}")
    count += 1
print(f"# {count} instructions ({mode})", file=sys.stderr)
