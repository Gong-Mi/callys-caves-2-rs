#!/usr/bin/env python3
"""Read the running original's room views (Cally's Caves 2, libyoyo).

live = RW_BASE + (va - 0x3f2000);  RW_BASE from /proc/<pid>/maps (rw-p of libyoyo).

View struct (from GV_View* accessors): +0 byte visible, +4/8/c/10 float
xview/yview/wview/hview, +14/18/1c/20 int xport/yport/wport/hport, +0x40 int
camera id (-1 none). Room object at Run_Room (VA 0x54298c), views at room+0x48+4i.

Usage: read_views.py <pid> <rw_base_hex>
"""
import os
import struct
import sys

pid = int(sys.argv[1])
RW = int(sys.argv[2], 16)

RUN_ROOM_VA = 0x54298C


def rd(fd, addr, n):
    try:
        os.lseek(fd, addr, os.SEEK_SET)
        b = os.read(fd, n)
    except OSError:
        return None
    return b if len(b) == n else None


def u32(fd, addr):
    b = rd(fd, addr, 4)
    return None if b is None else struct.unpack("<I", b)[0]


def i32(fd, addr):
    b = rd(fd, addr, 4)
    return None if b is None else struct.unpack("<i", b)[0]


def f32(fd, addr):
    b = rd(fd, addr, 4)
    return None if b is None else struct.unpack("<f", b)[0]


def main():
    fd = os.open(f"/proc/{pid}/mem", os.O_RDONLY)
    room = u32(fd, RW + (RUN_ROOM_VA - 0x3F2000))
    print(f"Run_Room object = {room:#x}" if room else "Run_Room = None")
    if room:
        flag = rd(fd, room + 0x44, 1)
        print(f"room+0x44 flag  = {flag.hex() if flag else None}")
        for i in range(8):
            vp = u32(fd, room + 0x48 + 4 * i)
            if not vp:
                print(f"view[{i}] null")
                continue
            vis = rd(fd, vp, 1)
            xv, yv, wv, hv = (f32(fd, vp + 4), f32(fd, vp + 8),
                              f32(fd, vp + 0xC), f32(fd, vp + 0x10))
            xp, yp, wp, hp = (i32(fd, vp + 0x14), i32(fd, vp + 0x18),
                              i32(fd, vp + 0x1C), i32(fd, vp + 0x20))
            cam = i32(fd, vp + 0x40)
            ang = f32(fd, vp + 0x24)
            print(f"view[{i}] @{vp:#x} vis=0x{vis.hex() if vis else '??'} "
                  f"view=({xv},{yv},{wv},{hv}) port=({xp},{yp},{wp},{hp}) "
                  f"angle={ang} cam={cam}")
    fd.close()


main()
