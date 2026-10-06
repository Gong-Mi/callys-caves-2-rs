#!/usr/bin/env python3
"""Guard evaluator for the audio-call table, using live globals.

Reads globals via the verified YYObjectBase hash layout (see global_get.py),
then evaluates each call's enclosing guard chain as far as it depends on
global.* only. Instance-variable guards are reported as UNRESOLVED (they need
per-instance state).

Usage: guard_eval.py <pid> <rw_base_hex> [object] [event]
"""
import json, os, pathlib, re, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
OBJ = sys.argv[3] if len(sys.argv) > 3 else None
EV = sys.argv[4] if len(sys.argv) > 4 else None
OFF = 0x3F2000
def A(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n); f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(va): return struct.unpack("<I", rd(A(va), 4))[0]
def h32(a): return struct.unpack("<I", rd(a, 4))[0]

scope = u32(0x544BE0); map_ = h32(scope+0x60)
mask = h32(map_+8); data = h32(map_+16)

def lookup(idx):
    h = (idx + 1) & 0x7FFFFFFF; slot = h & mask
    for _ in range(mask + 2):
        e = data + slot*12
        stored = h32(e + 8)
        if stored == 0: return None
        if stored == h:
            p = h32(e + 4)
            return None if p in (0, 0xFFFFFFFC, 0xFFFFFFFF) else p
        slot = (slot + 1) & mask
    return None

def rval(p):
    v0, v1, v2, tag = struct.unpack("<4I", rd(p, 16))
    t = (tag >> 24) & 0xFF
    if t in (5, 7):      # real/double
        return struct.unpack("<d", struct.pack("<II", v0, v1))[0]
    if t == 0:
        return struct.unpack("<i", struct.pack("<I", v0))[0]
    return None          # string/ptr/other → not comparable numerically here

names = {int(k): v for k, v in json.load(
    open(pathlib.Path(__file__).parent.parent / 'globals-name-map.json')).items()}
name2idx = {v: k for k, v in names.items()}

globals_cache = {}
def gval(name):
    if name not in globals_cache:
        idx = name2idx.get(name)
        p = lookup(idx) if idx is not None else None
        globals_cache[name] = rval(p) if p else None
    return globals_cache[name]

COND = re.compile(r'^\s*(?:else\s+)?if\s*\(\s*(global\.)?(\w+)\s*(==|!=|<=|>=|<|>)\s*([-\d.A-Za-z_]+)\s*\)')
room_by_idx = {int(k): v for k, v in json.load(
    open(pathlib.Path(__file__).parent.parent / 'room-index-map.json')).items()}
room_by_name = {v: k for k, v in room_by_idx.items()}
def cur_room():
    idx = struct.unpack('<I', rd(A(0x542958), 4))[0]
    return idx
def eval_cond(text):
    if 'audio_is_playing' in text:
        return ('AUDIO-STATE', 'audio subsystem disabled in shell -> predicate false')
    m = COND.match(text)
    if not m:
        if 'global.' in text:
            return ('UNRESOLVED', 'complex global expr')
        return ('UNRESOLVED', 'instance/other')
    isglobal, nm, op, rhs = m.groups()
    if not isglobal and nm == 'room':
        v = float(cur_room())
        if rhs in room_by_name:
            n = float(room_by_name[rhs])
        else:
            try: n = float(rhs)
            except ValueError: return ('UNRESOLVED', f'unknown room name {rhs}')
    elif not isglobal:
        return ('UNRESOLVED', f'builtin {nm}')
    else:
        v = gval(nm)
        if v is None:
            return ('UNRESOLVED', f'global.{nm} unreadable')
        try: n = float(rhs)
        except ValueError: return ('UNRESOLVED', f'global.{nm} vs {rhs}')
    ok = {'==': v == n, '!=': v != n, '<': v < n, '>': v > n, '<=': v <= n, '>=': v >= n}[op]
    label = f'global.{nm}' if isglobal else 'room'
    return ('TRUE' if ok else 'FALSE', f'{label}={v:g} {op} {n:g}')
    nm, op, num = m.groups()
    v = gval(nm)
    if v is None:
        return ('UNRESOLVED', f'global.{nm} unreadable')
    n = float(num)
    ok = {'==': v == n, '!=': v != n, '<': v < n, '>': v > n,
          '<=': v <= n, '>=': v >= n}[op]
    return ('TRUE' if ok else 'FALSE', f'global.{nm}={v} {op} {num}')

table = json.load(open(pathlib.Path(__file__).parent.parent / 'audio-call-table.json'))
rows = [r for r in table if (OBJ is None or r['object'] == OBJ)
        and (EV is None or r['event'].startswith(EV))]
print(f"globals: soundmute={gval('soundmute')} musicmute={gval('musicmute')} "
      f"health1={gval('health1')} roomstart={gval('roomstart')}")
tot_t = tot_f = tot_u = 0
for r in rows:
    print(f"\n{r['object']}.{r['event']}({r['sub']}) c{r['code_id']}")
    last_sound = None
    for c in r['calls']:
        verdicts = [eval_cond(g[1]) for g in c['guards']]
        stat = 'TRUE' if all(v[0] == 'TRUE' for v in verdicts) and verdicts else \
               ('FALSE' if any(v[0] == 'FALSE' for v in verdicts) else None)
        if stat == 'TRUE': tot_t += 1
        elif stat == 'FALSE': tot_f += 1
        else: tot_u += 1
        if c['sound'] != last_sound:
            last_sound = c['sound']
            gd = ' | '.join(f'{v[0]}:{v[1]}' for v in verdicts[-2:])[:110]
            print(f"   L{c['line']:4d} {c['sound']:18s} -> {stat or 'UNRESOLVED':11s} {gd}")
print(f"\ntotals: TRUE={tot_t} FALSE={tot_f} UNRESOLVED={tot_u}")
