#!/usr/bin/env python3
"""pread u32 from live process memory. Usage: read_mem.py <pid> <addr> [count]"""
import sys, os

pid = int(sys.argv[1])
addr = int(sys.argv[2], 16)
count = int(sys.argv[3]) if len(sys.argv) > 3 else 1

with open(f"/proc/{pid}/mem", "rb", buffering=0) as f:
    for i in range(count):
        os.lseek(f.fileno(), addr + 4 * i, os.SEEK_SET)
        b = os.read(f.fileno(), 4)
        if len(b) < 4:
            print(f"{addr+4*i:#010x}: <short read>")
            break
        v = int.from_bytes(b, "little")
        print(f"{addr+4*i:#010x}: 0x{v:08x} ({v})")
