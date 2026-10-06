#!/usr/bin/env python3
"""Audio timeline poller for the live callyscaves2-shell (no binary patch).

Reads (all RE-verified, see live-findings-v2.md sec.8):
  play counter   VA 0x3F1690  (RW + va-0x3F1000)  — increments per Audio_PlaySound
  audio manager  VA 0x7553AC  (RW + va-0x3F2000)  — {sounds array, count, ...}
  g_GameTimer    VA 0x5428C0  (RW + va-0x3F2000)  — 0x28-byte timer struct
Per-sound playing flag offset is auto-derived: dump candidate bytes for the
sound whose index matches the most recent counter event, and report all
CSound slots with any nonzero activity bytes (offsets 0x24..0x60).

Usage: audio_poll.py <pid> <rw_base_hex> <seconds> [poll_ms]
"""
import os, struct, sys, time, json

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
SECS = float(sys.argv[3]); POLL = float(sys.argv[4]) if len(sys.argv) > 4 else 50

def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def data_u32(va): return struct.unpack("<I", rd(RW + (va - 0x3F1000), 4))[0]
def bss_u32(va):  return struct.unpack("<I", rd(RW + (va - 0x3F2000), 4))[0]
def bss_bytes(va, n): return rd(RW + (va - 0x3F2000), n)

COUNTER = 0x3F1690
MGR     = 0x7553AC
TIMER   = 0x5428C0

t0 = time.time()
samples = []
prev_counter = None
prev_timer = None
print(f"poll every {POLL}ms for {SECS}s")
while time.time() - t0 < SECS:
    now = time.time() - t0
    try:
        c = data_u32(COUNTER)
        gt = bss_bytes(TIMER, 0x28)
        mgr = bss_bytes(MGR, 0x40)
    except Exception as ex:
        print(f"[{now:6.2f}] read error: {ex}")
        break
    # timer word diffs (first 40 samples establish tick field)
    if prev_timer is not None:
        diffs = [i for i in range(0x28//4)
                 if struct.unpack_from('<I', gt, 4*i)[0] != struct.unpack_from('<I', prev_timer, 4*i)[0]]
    else:
        diffs = []
    if prev_counter is not None and c != prev_counter:
        print(f"[{now:6.2f}] PLAY counter {prev_counter} -> {c} (+{c-prev_counter})")
    if diffs and now < 5:
        print(f"[{now:6.2f}] timer words changed: "
              f"{[(hex(4*i), struct.unpack_from('<I',gt,4*i)[0]) for i in diffs]}")
    samples.append((now, c, gt, mgr))
    prev_counter = c; prev_timer = gt
    time.sleep(POLL / 1000.0)

# dump manager struct + sounds array activity snapshot
now, c, gt, mgr = samples[-1]
words = struct.unpack('<16I', mgr)
print('manager S words:', [hex(w) for w in words])
# guess sounds array = first ptr-like word with a plausible count nearby
for i, w in enumerate(words):
    if 0x8000000 <= w <= 0xf0000000:
        try:
            head = rd(w, 0x40)
            print(f"S[{i:#x}] -> {w:#x}: {head.hex()}")
        except Exception as ex:
            print(f"S[{i:#x}] -> {w:#x}: unreadable ({ex})")

import pathlib
out = pathlib.Path(__file__).parent / 'audio_poll_raw.json'
json.dump([{'t': t, 'counter': c, 'timer': gt.hex(), 'mgr': m.hex()}
           for t, c, gt, m in samples], open(out, 'w'))
print(f"raw samples -> {out} ({len(samples)} samples)")
