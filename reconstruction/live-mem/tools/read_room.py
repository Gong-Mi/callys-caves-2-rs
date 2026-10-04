#!/usr/bin/env python3
"""Dump the current Run_Room object (Cally's Caves 2 live) + sniff strings.

Usage: read_room.py <pid> <rw_base_hex>
"""
import os
import struct
import sys

pid = int(sys.argv[1])
RW = int(sys.argv[2], 16)


def rd(fd, addr, n):
    try:
        os.lseek(fd, addr, os.SEEK_SET)
        b = os.read(fd, n)
    except OSError:
        return None
    return b if len(b) == n else None


def u32(fd, a):
    b = rd(fd, a, 4)
    return None if b is None else struct.unpack("<I", b)[0]


def main():
    fd = os.open(f"/proc/{pid}/mem", os.O_RDONLY)
    room = u32(fd, RW + (0x54298C - 0x3F2000))
    print(f"room = {room:#x}" if room else "room = None")
    if not room:
        return
    for off in range(0, 0x100, 16):
        b = rd(fd, room + off, 16)
        if not b:
            print(f"{room + off:#010x}: <unmapped>")
            break
        hx = " ".join(f"{x:02x}" for x in b)
        print(f"{room + off:#010x}: {hx}")
    print("\n-- pointers in [0,0x120) -> printable runs at target --")
    seen = set()
    for off in range(0, 0x120, 4):
        v = u32(fd, room + off)
        if not v or v in seen:
            continue
        if 0x10000 < v < 0xF0000000:
            seen.add(v)
            b = rd(fd, v, 96)
            if not b:
                continue
            runs = []
            cur = b""
            for byte in b:
                if 32 <= byte < 127:
                    cur += bytes([byte])
                else:
                    if len(cur) >= 4:
                        runs.append(cur.decode())
                    cur = b""
            if len(cur) >= 4:
                runs.append(cur.decode())
            if runs:
                print(f"  [{off:#04x}] -> {v:#010x}: {runs}")
    fd.close()


main()
