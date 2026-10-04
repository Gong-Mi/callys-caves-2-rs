#!/usr/bin/env python3
"""Hexdump [start, start+len) of /proc/<pid>/mem.

Usage: hexdump_range.py <pid> <start_hex> <len_hex>
"""
import os
import sys

pid = int(sys.argv[1])
start = int(sys.argv[2], 16)
length = int(sys.argv[3], 16)
fd = os.open(f"/proc/{pid}/mem", os.O_RDONLY)
for off in range(0, length, 16):
    try:
        os.lseek(fd, start + off, os.SEEK_SET)
        b = os.read(fd, 16)
    except OSError:
        print(f"{start + off:#010x}: <unmapped>")
        break
    if not b:
        break
    hx = " ".join(f"{x:02x}" for x in b)
    asc = "".join(chr(x) if 32 <= x < 127 else "." for x in b)
    print(f"{start + off:#010x}: {hx:<48s} {asc}")
os.close(fd)
