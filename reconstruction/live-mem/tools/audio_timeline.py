#!/usr/bin/env python3
"""Live audio timeline: event stream x guard-evaluated audio calls.

Polls (Current_Object, Event_Type, Event_Number) at POLL ms; on every change
evaluates that event's audio calls from audio-call-table.json against live
globals/instances (guard_eval2 logic) and prints the calls that resolve to
play. Output JSON: [{t, obj, name, et, en, plays:[{sound, line, why}]}].

Usage: audio_timeline.py <pid> <rw_base_hex> <seconds> [poll_ms]
"""
import json, os, pathlib, re, struct, sys, time

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
SECS = float(sys.argv[3]); POLL = float(sys.argv[4]) if len(sys.argv) > 4 else 20
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
def cstr(a, n=64):
    try: return rd(a, n).split(b"\x00")[0].decode("ascii", "replace")
    except Exception: return None

BASE = pathlib.Path(__file__).parent.parent
sys.path.insert(0, str(pathlib.Path(__file__).parent))
import importlib.util
spec = importlib.util.spec_from_file_location("ge", pathlib.Path(__file__).parent/'guard_eval2.py')
# reuse by subprocess-free import is awkward (script-style); re-implement core inline:
gnames = json.load(open(BASE/'globals-name-map.json'))
gnames = {v: int(k) for k, v in gnames.items()}
room_by_name = {v: int(k) for k, v in json.load(open(BASE/'room-index-map.json')).items()}
table = json.load(open(BASE/'audio-call-table.json'))
by_obj = {}
for r in table:
    by_obj.setdefault(r['object'], []).append(r)

scope = u32(0x544BE0); gmap = h32(scope+0x60)
gmask = h32(gmap+8); gdata = h32(gmap+16)
def lookup(map_, mask, data, idx):
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
    if t in (5, 7): return struct.unpack("<d", struct.pack("<II", v0, v1))[0]
    if t == 0: return struct.unpack("<i", struct.pack("<I", v0))[0]
    return ('REF', v0, t)
def gval(n):
    i = gnames.get(n)
    p = lookup(gmap, gmask, gdata, i) if i is not None else None
    return rval(p) if p else None
_ic = {}
def find_inst(o):
    if o in _ic: return _ic[o]
    room = u32(0x54298C); n = h32(room+0x84); res = None
    while n and n != 0xFFFFFFFF:
        gm = h32(n+0x80)
        if cstr(h32(gm+0x14)) == o: res = n; break
        n = h32(n+0x17C)
    _ic[o] = res; return res
def ival(o, v):
    inst = find_inst(o)
    if not inst: return None
    m = h32(inst+0x60)
    if not m: return None
    i = gnames.get('__never__')
    # instance name table
    global _inames
    idx = _inames.get(v)
    if idx is None: return None
    p = lookup(m, h32(m+8), h32(m+16), idx)
    return rval(p) if p else None

# instance name table
cnt, f1, esz, ptr = struct.unpack("<4I", rd(A(0x47A18C), 16))
_inames = {}
raw = rd(ptr, 4*cnt)
for i in range(cnt):
    q = struct.unpack_from('<I', raw, 4*i)[0]
    if q:
        s = cstr(q)
        if s: _inames[s] = i

COND = re.compile(r'^\s*(?:else\s+)?if\s*\(\s*([\w.]+)\s*(==|!=|<=|>=|<|>)\s*([-\w.]+)\s*\)')
def eval_guard(text, objname):
    if 'audio_is_playing' in text: return ('AUDIO-STATE', 'audio disabled')
    m = COND.match(text)
    if not m: return ('UNRESOLVED', text.strip()[:50])
    lhs, op, rhs = m.groups()
    def cmpv(v, n):
        try: n = float(n)
        except ValueError: return None
        return {'==': v == n, '!=': v != n, '<': v < n, '>': v > n,
                '<=': v <= n, '>=': v >= n}[op]
    if lhs.startswith('global.'):
        v = gval(lhs.split('.', 1)[1])
        if v is None: return ('UNRESOLVED', lhs)
        r = cmpv(v, rhs); return (('TRUE' if r else 'FALSE'), f'{lhs}={v:g}{op}{rhs}')
    if lhs == 'room':
        v = float(u32(0x542958)); n = room_by_name.get(rhs)
        if n is None:
            try: n = float(rhs)
            except ValueError: return ('UNRESOLVED', f'room{op}{rhs}')
        return (('TRUE' if v == n else 'FALSE'), f'room={v:g}{op}{rhs}({n})')
    if '.' in lhs:
        oname, var = lhs.split('.', 1)
        if oname in _inames: return ('REF-UNRESOLVED', lhs)
        v = ival(oname, var)
        if v is None: return ('UNRESOLVED', lhs)
        if isinstance(v, tuple): return ('REF-UNRESOLVED', lhs)
        r = cmpv(v, rhs); return (('TRUE' if r else 'FALSE'), f'{lhs}={v:g}{op}{rhs}')
    v = ival(objname, lhs)
    if v is None: return ('UNRESOLVED', f'{lhs}(owner?)')
    if isinstance(v, tuple): return ('REF-UNRESOLVED', lhs)
    r = cmpv(v, rhs); return (('TRUE' if r else 'FALSE'), f'{lhs}={v:g}{op}{rhs}')

EV = {0:'Create',1:'Destroy',2:'Alarm',3:'Step',4:'Collision',5:'Keyboard',6:'Mouse',
      7:'Other',8:'Draw',9:'KeyPress',10:'KeyRelease'}
WANT = {'Create':0,'Destroy':1,'Alarm':2,'Step':3,'Collision':4,'Draw':8,'Mouse':6,
        'Other':7,'KeyPress':9,'KeyRelease':10}
CUR = (0x54290C, 0x542908, 0x542904)
t0 = time.time(); prev = None; out = []
while time.time() - t0 < SECS:
    now = round(time.time() - t0, 3)
    try:
        o, et, en = (u32(CUR[0]), u32(CUR[1]), u32(CUR[2]))
        gt = struct.unpack('<II', rd(A(0x5428C0), 8))
    except Exception as ex:
        print(f'[{now}] ERR {ex}'); break
    if (o, et, en) != prev:
        prev = (o, et, en)
        name = None
        for gm_i in range(0):  # placeholder
            pass
        # resolve name from any instance of that index in the room
        room = u32(0x54298C); n = h32(room+0x84); nm = None
        while n and n != 0xFFFFFFFF:
            gm = h32(n+0x80)
            if h32(gm+0x04) == o:   # CObjectGM+0x4 = object index (verified)
                nm = cstr(h32(gm+0x14)); break
            n = h32(n+0x17C)
        if nm is None:
            continue
        plays = []
        for r in by_obj.get(nm, []):
            if WANT.get(r['event']) != et:
                continue
            for c in r['calls']:
                vs = [eval_guard(g[1], nm) for g in c['guards']] or [('TRUE', 'no guard')]
                tags = [v[0] for v in vs]
                if any(t == 'FALSE' for t in tags): continue
                stat = 'AUDIO-STATE' if any(t == 'AUDIO-STATE' for t in tags) else \
                       ('UNRESOLVED' if any(t.startswith('UNRESOLVED') or t.startswith('REF') for t in tags) else 'PLAY')
                plays.append({'sound': c['sound'], 'line': c['line'], 'status': stat,
                              'why': ' | '.join(f'{a}:{b}' for a, b in vs)[:120]})
        if plays:
            print(f"[{now:7.3f}] {nm}.{EV.get(et,et)}({en}) -> " +
                  ', '.join(f"{p['sound'] or '<stop>'}[{p['status']}]" for p in plays[:4]))
        out.append({'t': now, 'obj': o, 'name': nm, 'et': et, 'en': en, 'plays': plays})
    time.sleep(POLL/1000.0)
json.dump(out, open(pathlib.Path(__file__).parent/'audio_timeline.json', 'w'), indent=1)
print(f"events={len(out)} -> tools/audio_timeline.json")
