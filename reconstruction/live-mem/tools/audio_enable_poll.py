#!/usr/bin/env python3
"""Enable + observe the runner's audio state machine in the live shell.

- writes 0 to the two GML-level audio gates (F_AudioPlaySound gate + the
  Audio_PlaySound flag1) so audio_play_sound calls actually reach
  Audio_PlaySound (libopenal's AL calls are no-op patched separately).
- then polls, every POLL ms: the CNoise pool bump slot (0x3F1690 -> ptr ->
  value), the audio manager slot (0x7553AC -> ptr), g_GameTimer, and dumps the
  0x80 bytes below the bump top looking for a sound-index word at +0x18
  (source struct offset +24) so each play can be attributed.

Usage: audio_enable_poll.py <pid> <rw_base_hex> <seconds> [poll_ms]
"""
import os, struct, sys, time, json, pathlib

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
SECS = float(sys.argv[3]); POLL = float(sys.argv[4]) if len(sys.argv) > 4 else 50
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def wr8(a, val):
    f = open(f"/proc/{pid}/mem", "rb+", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    f.write(bytes([val])); f.close()
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]

GATE_SLOTS = {'F_AudioPlaySound_gate': 0x3EF0D4, 'audio_flag1': 0x3EF2EC,
              'audio_flag2': 0x3EEFD0, 'startnoise_gate': 0x3EF070}
BUMP_SLOT = 0x3F1690
MGR_SLOT  = 0x7553AC
TIMER     = 0x5428C0

print("== pre-flip gates ==")
bump_ptr = None
for name, slot in GATE_SLOTS.items():
    p = u32(slot)
    try:
        byte = rd(p, 1)[0]
    except Exception as ex:
        byte = f"ERR {ex}"
    print(f"  {name:22s} slot={slot:#x} ptr={p:#x} byte={byte}")

# flip the two hard gates to 0
for name in ('F_AudioPlaySound_gate', 'audio_flag1'):
    p = u32(GATE_SLOTS[name])
    try:
        wr8(p, 0)
        print(f"  wrote 0 -> {name} @{p:#x} (now {rd(p,1)[0]})")
    except Exception as ex:
        print(f"  WRITE FAILED {name}: {ex}")

bump_slot_val = u32(BUMP_SLOT)
bump_ptr = bump_slot_val
print(f"== poll start: bump top ptr={bump_ptr:#x} ==")

t0 = time.time(); prev_bump = None; events = []
while time.time() - t0 < SECS:
    now = time.time() - t0
    try:
        top_ptr = u32(BUMP_SLOT)
        top = struct.unpack("<I", rd(top_ptr, 4))[0] if top_ptr else 0
    except Exception as ex:
        print(f"[{now:6.2f}] ERR {ex}"); break
    if prev_bump is not None and top != prev_bump:
        # dump the freshly allocated window below the bump top
        try:
            win = rd(top - 0x80, 0x80)
            cand = struct.unpack('<32I', win)
            ev = {'t': round(now, 3), 'bump': hex(top), 'delta': top - prev_bump,
                  'words': [hex(w) for w in cand]}
            events.append(ev)
            # find a plausible sound index (small int) in the +0x18..+0x2c area
            idxs = [w for w in cand if w < 4096]
            print(f"[{now:6.2f}] ALLOC +{top-prev_bump:#x} top={top:#x} "
                  f"small_words={[hex(w) for w in idxs][:8]}")
        except Exception as ex:
            print(f"[{now:6.2f}] ALLOC +{top-prev_bump:#x} (dump failed: {ex})")
    prev_bump = top
    time.sleep(POLL/1000.0)

out = pathlib.Path(__file__).parent / 'audio_events.json'
json.dump(events, open(out, 'w'))
print(f"events={len(events)} -> {out}")
