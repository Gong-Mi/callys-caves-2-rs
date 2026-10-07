#!/usr/bin/env python3
"""Flip the gate that short-circuits every audio_is_playing query, watch whether
the obj_music sequencer starts advancing + CNoise allocations happen.

libyoyo 3bbedd09: F_AudioPlaying handler @0x134be8 reads gate byte via literal
0x134c10 -> slot VA 0x3EF050; byte != 0 -> return FALSE *immediately* (popne at
0x134c00). The sound-table object has +0x24/+0x28/+0x34 = 0, so even past the
gate the type-lookup default branch would fail — this probe watches soundplay
(clamp experiment §25 proved Step dispatches) and the CNoise bump top.

Usage: isplaying_gate_flip.py <pid> <rw_base_hex> [seconds]
"""
import os, struct, sys, time

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
SECS = float(sys.argv[3]) if len(sys.argv) > 3 else 15
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET); b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short @{a:#x}")
    return b
def wr8(a, v):
    f = open(f"/proc/{pid}/mem", "rb+", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET); f.write(bytes([v])); f.close()
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

def obj_find(want):
    rr = u32(0x54298C)
    n = struct.unpack("<I", rd(rr + 0x84, 4))[0]; c = 0
    while n and c < 250:
        og = struct.unpack("<I", rd(n + 0x80, 4))[0]
        p = struct.unpack("<I", rd(og + 0x14, 4))[0]
        if rd(p, 40).split(b"\x00")[0].decode("ascii", "replace") == want:
            return n
        n = struct.unpack("<I", rd(n + 0x17c, 4))[0]; c += 1
    return None

def inst_var(inst, idx):
    mp = struct.unpack("<I", rd(inst + 0x60, 4))[0]
    mask = struct.unpack("<I", rd(mp + 8, 4))[0]
    data = struct.unpack("<I", rd(mp + 16, 4))[0]
    h = idx + 1; slot = h & mask
    for _ in range(mask + 1):
        e = data + slot * 12
        s = struct.unpack("<I", rd(e + 8, 4))[0]
        if s == 0: return None
        if s == h: return struct.unpack("<I", rd(e + 4, 4))[0]
        slot = (slot + 1) & mask
    return None

gates = [("isplaying_gate(0x3EF050)", 0x3EF050),
         ("F_AudioPlaySound(0x3EF0D4)", 0x3EF0D4),
         ("flag1(0x3EF2EC)", 0x3EF2EC),
         ("flag2(0x3EEFD0)", 0x3EEFD0),
         ("startnoise(0x3EF070)", 0x3EF070),
         ("PS_gate1(0x3EF054)", 0x3EF054),
         ("PS_gate2(0x3EED38)", 0x3EED38)]
print("== before ==")
for name, slot in gates:
    p = u32(slot)
    try: print(f"  {name:28s} ptr={p:#x} byte={rd(p,1)[0]}")
    except Exception: print(f"  {name:28s} ptr={p:#x} UNMAPPED")

# flip the isplaying gate (0/1 only; keep PS_gate2 nonzero — it's a required
# enable byte per Audio_PlaySound 0x21b60c beq-skip)
must_zero = [s for _, s in gates[:6]]
for slot in must_zero:
    p = u32(slot)
    old = rd(p, 1)[0]
    wr8(p, 0)
    print(f"  flipped {slot:#x} ({p:#x}): {old} -> {rd(p,1)[0]}")

mus = obj_find("obj_music")
sp = inst_var(mus, 636) if mus else None
bump = u32(0x3F1690)
top0 = struct.unpack("<I", rd(bump, 4))[0]
print(f"obj_music={mus and hex(mus)} soundplay rv={sp and hex(sp)} bump={bump:#x} top={top0:#x}")

t0 = time.time(); seen = {}
while time.time() - t0 < SECS:
    v = struct.unpack("<d", rd(sp, 8))[0] if sp else None
    top = struct.unpack("<I", rd(u32(0x3F1690), 4))[0]
    seen[v] = seen.get(v, 0) + 1
    time.sleep(0.5)
print(f"soundplay values over {SECS}s: {seen}")
print(f"bump top: {top0:#x} -> {top:#x} (delta {top-top0:#x})")

# dump played sound ids from the freshly bump-allocated window
if top != top0:
    lo = max(top0 - 0x400, top - 0x1000)
    win = rd(lo, min(0x800, top - lo))
    words = struct.unpack(f"<{len(win)//4}I", win)
    small = [hex(w) for w in words if w < 60]
    print(f"small ints (candidate sond ids) in window: {small[:24]}")
