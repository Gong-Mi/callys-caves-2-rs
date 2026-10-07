#!/usr/bin/env python3
"""Audio state probe for the live shell (alc-patched libopenal).

Usage: audio_state_probe.py <pid> <rw_base_hex> [--flip]
  pre-flip read of every audio-relevant slot; with --flip the four
  F_/manager gate bytes are written 0 first (the two Audio_PlaySound
  internal gates are only READ: gate1 must already be 0, gate2 nonzero).
Then, when --poll is given, watch obj_music soundplay + the CNoise bump
pointer for 10 x 2s samples.
"""
import os, struct, sys, time

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
FLIP = "--flip" in sys.argv; POLL = "--poll" in sys.argv
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
def byte_at(slot):
    p = u32(slot)
    try: return p, rd(p, 1)[0]
    except Exception: return p, None

GATES = [("F_AudioPlaySound", 0x3EF0D4), ("flag1", 0x3EF2EC),
         ("flag2", 0x3EEFD0), ("startnoise", 0x3EF070),
         ("PS_gate1(must=0)", 0x3EF054), ("PS_gate2(must!=0)", 0x3EED38)]

print("== boot/pre-flip state ==")
for name, slot in GATES:
    p, v = byte_at(slot)
    print(f"  {name:20s} slot={slot:#x} ptr={p:#x} byte={v}")
print("  device state 0x755470 =", u32(0x755470), " ctx 0x755474 =", u32(0x755474))
print("  S mgr 0x7553AC =", hex(u32(0x7553AC)))
# sound table is an INLINE struct at data VA 0x75529C (GetSoundSourceToPlay
# reads [0x75529C+0x20] directly — do NOT deref the slot first; see §24).
print("  sound tbl inline @0x75529C:")
print("    cap+0x18 =", u32(0x7552B4), " count+0x20 =", u32(0x7552BC),
      " arr+0x24 =", hex(u32(0x7552C0)), " +0x28 =", u32(0x7552C4))
cnt = u32(0x7552BC); arr = u32(0x7552C0)
if arr and cnt:
    nn = sum(1 for i in range(cnt) if struct.unpack('<I', rd(arr+i*4, 4))[0])
    print(f"    CSound array: {nn}/{cnt} non-null")
bump = u32(0x3F1690)
print("  CNoise bump slot", hex(bump), "top", hex(struct.unpack('<I', rd(bump,4))[0]))

if FLIP:
    print("== flipping F_/mgr gates ==")
    for name, slot in GATES[:4]:
        p, old = byte_at(slot)
        if old is not None:
            wr8(p, 0); print(f"  {name}: {old} -> {rd(p,1)[0]} @{p:#x}")

if POLL:
    def obj_find(nm_want):
        rr = u32(0x54298C)
        n = struct.unpack('<I', rd(rr+0x84, 4))[0]; c = 0
        while n and c < 250:
            og = struct.unpack('<I', rd(n+0x80, 4))[0]
            p = struct.unpack('<I', rd(og+0x14, 4))[0]
            nm = rd(p, 40).split(b'\x00')[0].decode('ascii', 'replace')
            if nm == nm_want: return n
            n = struct.unpack('<I', rd(n+0x17c, 4))[0]; c += 1
        return None
    mus = obj_find("obj_music")
    print("obj_music inst:", hex(mus) if mus else None)
    if mus:
        mp = struct.unpack('<I', rd(mus+0x60, 4))[0]
        mask = struct.unpack('<I', rd(mp+8, 4))[0]
        data = struct.unpack('<I', rd(mp+16, 4))[0]
        def inst_var(idx):
            h = idx + 1; slot = h & mask
            for _ in range(mask + 1):
                e = data + slot*12
                stored = struct.unpack('<I', rd(e+8, 4))[0]
                if stored == 0: return None
                if stored == h: return struct.unpack('<I', rd(e+4, 4))[0]
                slot = (slot+1) & mask
            return None
        sp = inst_var(636)
        bump = u32(0x3F1690)
        top0 = struct.unpack('<I', rd(bump,4))[0]
        for i in range(10):
            v = struct.unpack('<d', rd(sp, 8))[0] if sp else None
            top = struct.unpack('<I', rd(u32(0x3F1690),4))[0]
            print(f"  t{i}: soundplay={v} bump_top={top:#x}" + (f" delta={top-top0:#x}" if top!=top0 else ""))
            time.sleep(2)
