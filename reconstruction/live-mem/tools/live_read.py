#!/usr/bin/env python3
"""Live probe for the RUNNING original Cally's Caves 2 (libyoyo globals).

Symbol VAs are link-time 32-bit VAs from `llvm-nm -D libyoyo_armv7.so`.
Runtime mapping (from /proc/<pid>/maps):
  r-xp @ 0x7ffd5000 file-off 0x0      -> live = rx_base + va
  r--p @ 0x8037c000 file-off 0x3a6000 -> live = ro_base + (va - 0x3a6000)
  rw-p @ 0x803c7000 file-off 0x3f1000 -> live = rw_base + (va - 0x3f1000)
We print BOTH candidate formulas for the rw segment so the right one is
self-evident from sane values (Current_View 0..8, small ints).

Usage: live_read.py <pid> <rw_base_hex> [name...]
"""
import os
import sys

RW_OFF = 0x3F1000

SYMS = {
    # small state globals (BSS) — sanity anchors
    "Current_View": 0x542920,
    "Current_Room": 0x542958,
    "New_Room": 0x542954,
    "Current_Object": 0x54290C,
    "Current_Event_Type": 0x542908,
    "Current_Event_Number": 0x542904,
    "Current_Action_Index": 0x542900,
    "Cursor_Sprite": 0x542918,
    "Cursor_Subimage": 0x542914,
    "Draw_Automatic": 0x542910,
    "Run_Room": 0x54298C,
    "Run_Room_List": 0x542990,
    "Draw_Color": 0x3F23D0,
    "Draw_Alpha": 0x3F23CC,
    "GR_Depth": 0x4859AC,
    "SurfaceStack": 0x48F7AC,
    "Argument": 0x47A170,
    "Argument_Relative": 0x47A174,
    "g_PrevViewAreaX": 0x3F23FC,
    "g_PrevViewAreaY": 0x3F23F8,
    "g_PrevViewAreaW": 0x3F23F4,
    "g_PrevViewAreaH": 0x3F23F0,
    "g_PrevViewPortH": 0x3F2400,
    "g_InitialScreenSizeX": 0x3F5228,
    "g_InitialScreenSizeY": 0x3F5224,
    "g_ApplicationSurface": 0x3F5110,
    "g_Application_Surface_Autodraw": 0x3F50FC,
    "g_CurrViewSurfaceTexture": 0x5428EC,
    "_views_count": 0x498CD4,
    "_views": 0x498CD8,
    "g_InstanceChangeDepth": 0x542A58,
    "g_InstanceChangeArray": 0x542A64,
    "g_InstanceActivateDeactive": 0x542A4C,
    # CInstance static members / instance tables
    "ms_ID2InstanceE": 0x536F28, "ms_markedCount": 0x536D7C,
    "ms_CurrentCreateCounter": 0x536F20, "s_instancePtr": 0x5428B8,
    "persinst": 0x542A0C, "g_ppDebugInstNames": 0x544C0C,
    "g_DebugInstNameCount": 0x544C08, "g_nInstanceVariables": 0x544B48,
    # last-frame draw / vertex stats
    "g_CurrentVertexCount": 0x4A2FA8, "g_TrianglesDrawn": 0x4A2FB8,
    "g_numVertexBatches": 0x4A20FC, "g_LastVertexFormat": 0x4A2FAC,
    "g_LastVertexSize": 0x4A2FB0, "g_LastBatchStart": 0x4A2FA4,
    "g_LastPrimType": 0x3F2928, "g_NumPrims": 0x4899B0, "g_PrimType": 0x4899AC,
    "g_LastColour": 0x4A22B4, "g_CullMode": 0x4A23F0, "g_DestBlend": 0x4A23FC,
    "g_AlphaTestEnable": 0x4A23A8, "g_ProjIsOrtho": 0x3F237C,
    "g_ViewAreaX": 0x3F23A0, "g_ViewAreaY": 0x3F239C,
    "g_ViewAreaW": 0x3F2398, "g_ViewAreaH": 0x3F2394,
    "g_ViewPortX": 0x3F23B0, "g_ViewPortY": 0x3F23AC,
    "g_ViewPortW": 0x3F23A8, "g_ViewPortH": 0x3F23A4,
    "g_PrevViewPortX": 0x3F240C, "g_PrevViewPortY": 0x3F2408,
    "g_PrevViewPortW": 0x3F2404, "g_PrevViewPortH": 0x3F2400,
    "g_OutsideViewColour": 0x3F2438, "g_DefaultCameraID": 0x3F50B8,
    "g_Display_x2": 0x3F2440, "g_Display_y2": 0x3F2444,
    "region_width": 0x3F238C, "region_height": 0x3F2388,
    "g_CoordFixScaleX": 0x3F23D8, "g_CoordFixScaleY": 0x3F23D4,
    "g_WindowMaxWidth": 0x3F2430, "g_WindowMaxHeight": 0x3F2428,
    "g_WindowMinWidth": 0x3F2434, "g_WindowMinHeight": 0x3F242C,
}


def read_u32(fd, addr):
    try:
        os.lseek(fd, addr, os.SEEK_SET)
        b = os.read(fd, 4)
    except OSError:
        return None
    if len(b) < 4:
        return None
    return int.from_bytes(b, "little")


def main():
    pid = int(sys.argv[1])
    rw_base = int(sys.argv[2], 16)
    names = sys.argv[3:] or list(SYMS)
    fd = os.open(f"/proc/{pid}/mem", os.O_RDONLY)
    print(f"# pid={pid} rw_base={rw_base:#x}  live = base + (va - 0x3f2000)")
    for n in names:
        va = SYMS[n]
        a = rw_base + (va - 0x3F2000)
        u = read_u32(fd, a)
        if u is None:
            print(f"{n:28s} va={va:#08x} @{a:#010x} <unmapped>")
            continue
        s = int.from_bytes(u.to_bytes(4, "little"), "little", signed=True)
        print(f"{n:28s} va={va:#08x} @{a:#010x} u32={u:#010x} ({u}) s={s}")
    os.close(fd)


main()

