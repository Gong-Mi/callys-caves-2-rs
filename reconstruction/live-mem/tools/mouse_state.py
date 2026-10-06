#!/usr/bin/env python3
"""Read the runner's mouse/touch state (RE: dynsym anchors in libyoyo 3bbedd09).

  g_MouseX 0x5346B8 (u32)   g_MouseY 0x5346B4 (u32)
  g_MousePosX 0x53468C (10 x u32)  g_MousePosY 0x534664 (10 x u32)
  g_DoMouseButton 0x535700 (10 x u32)  g_DoMouseButton_Last 0x5356D8 (10 x u32)
  g_objectstouched 0x47A21C (u32)  g_TouchActions 0x544A90 (3 x u32)

Usage: mouse_state.py <pid> <rw_base_hex>
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

print(f"g_MouseX={u32(0x5346B8)} g_MouseY={u32(0x5346B4)} "
      f"g_objectstouched={u32(0x47A21C)}")
print("g_MousePosX[0..4] (float bits):",
      [f"{struct.unpack('<f', struct.pack('<I', u32(0x53468C + 4*i)))[0]:.1f}" for i in range(4)])
print("g_MousePosY[0..4]:",
      [f"{struct.unpack('<f', struct.pack('<I', u32(0x534664 + 4*i)))[0]:.1f}" for i in range(4)])
print("g_DoMouseButton[0..4]:", [u32(0x535700 + 4*i) for i in range(4)])
print("g_DoMouseButton_Last[0..4]:", [u32(0x5356D8 + 4*i) for i in range(4)])
print("g_TouchActions:", struct.unpack("<3I", rd(A(0x544A90), 12)))
