#!/usr/bin/env python3
"""Dynamic event trace + object index->name calibration for the live shell.

- Builds object map from the room draw list: CObjectGM ptr -> name (+0x14).
- Discovers the object-index field inside CObjectGM by correlating with
  Current_Object (VA 0x54290C) observed while a KNOWN object's event runs
  (obj_player is in the town cast; index values are small ints).
- Polls (Current_Object, Current_Event_Type, Current_Event_Number) at POLL ms
  and prints transitions, joined with object names once calibrated, plus the
  audio calls that this (object,event) fires per audio-call-table.json.

Usage: event_trace.py <pid> <rw_base_hex> <seconds> [poll_ms]
"""
import json, os, pathlib, struct, sys, time

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
SECS = float(sys.argv[3]); POLL = float(sys.argv[4]) if len(sys.argv) > 4 else 5
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]
def h32(addr): return struct.unpack("<I", rd(addr, 4))[0]
def cstr(a):
    try: return rd(a, 40).split(b"\x00")[0].decode("ascii", "replace")
    except Exception: return None

CUR_OBJ, CUR_ET, CUR_EN = 0x54290C, 0x542908, 0x542904
RUN_ROOM = 0x54298C

# --- object map from the live cast
room = u32(RUN_ROOM)
n = h32(room + 0x84); seen = {}
while n and n != 0xFFFFFFFF and len(seen) < 400:
    gm = h32(n + 0x80)
    if gm not in seen:
        nm = cstr(h32(gm + 0x14)) or '?'
        seen[gm] = nm
    n = h32(n + 0x17C)
print(f"live objects in current room: {len(seen)}")

# --- index-field discovery: dump each CObjectGM's first 0x40 bytes once
cand_offsets = list(range(0, 0x40, 4))
gm_words = {}
for gm in seen:
    try:
        gm_words[gm] = struct.unpack("<16I", rd(gm, 0x40))
    except Exception:
        pass
print(f"CObjectGM dumps: {len(gm_words)}")

# --- trace
table = json.load(open(pathlib.Path(__file__).parent.parent / 'audio-call-table.json'))
by_obj_ev = {}
for r in table:
    by_obj_ev.setdefault(r['object'], []).append(r)

idx2name = {}
observed = []
off_hits = {}
trace = []
prev = None
t0 = time.time()
while time.time() - t0 < SECS:
    now = round(time.time() - t0, 3)
    try:
        o, et, en = u32(CUR_OBJ), u32(CUR_ET), u32(CUR_EN)
        gt = rd(A(0x5428C0), 0x28)
    except Exception as ex:
        print(f"[{now}] ERR {ex}"); break
    key = (o, et, en)
    if key != prev:
        gm_hit = None
        if (o, et, en) not in observed and len(observed) < 40:
            observed.append((o, et, en))
        for off in cand_offsets:
            hits = {}
            for gm, words in gm_words.items():
                if words[off//4] == o:
                    hits[gm] = seen[gm]
            if len(hits) == 1:
                gm_hit = list(hits.values())[0]
                off_hits[off] = off_hits.get(off, 0) + 1
                idx2name[o] = gm_hit
                break
        name = gm_hit or idx2name.get(o, f"obj#{o}")
        evs = by_obj_ev.get(name, [])
        hint = ''
        for r in evs:
            hint += f" [{r['event']}({r['sub']}) c{r['code_id']}]"
        print(f"[{now:7.3f}] obj={o} ({name}) event_type={et} num={en} audio_events:{hint or ' -'}")
        trace.append({'t': now, 'obj': o, 'name': name, 'et': et, 'en': en})
        prev = key
    time.sleep(POLL/1000.0)

out = pathlib.Path(__file__).parent / 'event_trace.json'
json.dump(trace, open(out, 'w'), indent=1)
print(f"transitions={len(trace)} -> {out}")
print("index-field hit offsets:", {hex(k): v for k, v in sorted(off_hits.items())})
print("index->name map:", {k: v for k, v in sorted(idx2name.items())})
