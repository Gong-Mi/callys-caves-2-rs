#!/usr/bin/env python3
"""Full guard evaluation over audio-call-table.json against live state.

Resolves:
  global.X op N        (YYObjectBase hash layout, globals)
  room op <roomname>   (live Current_Room + room-index-map.json)
  audio_is_playing(..) -> AUDIO-STATE (shell: audio subsystem disabled)
  <obj>.<var> op N     (find a live instance of <obj>, read <var>)  [NEW]
  <refvar>.<var> op N  -> REF-UNRESOLVED (prints the ref value for decoding)
Chain note: guards whose text starts with 'else if' are part of a chain; a call
is marked CHAIN-SKIPPED if an earlier sibling branch in the same chain was TRUE.

Usage: guard_eval2.py <pid> <rw_base_hex> [--all | object [event]]
"""
import json, os, pathlib, re, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16)
rest = sys.argv[3:]
ALL = '--all' in rest
OBJ = None if ALL or not rest else rest[0]
EVE = None if ALL or len(rest) < 2 else rest[1]
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
    if t in (5, 7):
        return struct.unpack("<d", struct.pack("<II", v0, v1))[0]
    if t == 0:
        return struct.unpack("<i", struct.pack("<I", v0))[0]
    return ('REF', v0, t)

def name_table(va):
    cnt, f1, esz, ptr = struct.unpack("<4I", rd(A(va), 16))
    out = {}
    raw = rd(ptr, 4*cnt)
    for i in range(cnt):
        p = struct.unpack_from('<I', raw, 4*i)[0]
        if p:
            s = cstr(p)
            if s: out[s] = i
    return out

gnames = name_table(0x47A19C)
inames = name_table(0x47A18C)
room_by_name = {v: int(k) for k, v in json.load(open(BASE/'room-index-map.json')).items()}

_gcache = {}
def gval(name):
    if name not in _gcache:
        idx = gnames.get(name)
        p = lookup(gmap, gmask, gdata, idx) if idx is not None else None
        _gcache[name] = rval(p) if p else None
    return _gcache[name]

# instance index: object name -> instance ptr (from the room draw list)
_inst_cache = {}
def find_inst(objname):
    if objname in _inst_cache: return _inst_cache[objname]
    room = u32(0x54298C)
    n = h32(room + 0x84); res = None
    while n and n != 0xFFFFFFFF:
        gm = h32(n + 0x80)
        if cstr(h32(gm + 0x14)) == objname:
            res = n; break
        n = h32(n + 0x17C)
    _inst_cache[objname] = res
    return res

def ival(objname, var):
    inst = find_inst(objname)
    if not inst: return None
    m = h32(inst + 0x60)
    if not m: return None
    mask = h32(m + 8); data = h32(m + 16)
    idx = inames.get(var)
    if idx is None: return None
    p = lookup(m, mask, data, idx)
    return rval(p) if p else None

COND = re.compile(r'^\s*(?:else\s+)?if\s*\(\s*([\w.]+)\s*(==|!=|<=|>=|<|>)\s*([-\w.]+)\s*\)')

def eval_guard(text, objname):
    if 'audio_is_playing' in text:
        return ('AUDIO-STATE', 'audio disabled (shell)')
    m = COND.match(text)
    if not m:
        return ('UNRESOLVED', text.strip()[:60])
    lhs, op, rhs = m.groups()
    chain = text.strip().startswith('else if')
    def cmpv(v, n):
        try:
            n = float(n)
        except ValueError:
            return None
        return {'==': v == n, '!=': v != n, '<': v < n, '>': v > n,
                '<=': v <= n, '>=': v >= n}[op]
    if lhs.startswith('global.'):
        v = gval(lhs.split('.', 1)[1])
        if v is None: return ('UNRESOLVED', f'{lhs} unreadable')
        r = cmpv(v, rhs)
        return (('CHAIN-ELSE ' if chain else '') + ('TRUE' if r else 'FALSE'),
                f'{lhs}={v:g} {op} {rhs}') if r is not None else ('UNRESOLVED', f'{lhs} vs {rhs}')
    if lhs == 'room':
        v = float(struct.unpack('<I', rd(A(0x542958), 4))[0])
        n = room_by_name.get(rhs, None)
        if n is None:
            try: n = float(rhs)
            except ValueError: return ('UNRESOLVED', f'room vs {rhs}')
        return (('TRUE' if v == n else 'FALSE'), f'room={v:g} {op} {rhs}({n})')
    if '.' in lhs:
        oname, var = lhs.split('.', 1)
        if oname in inames:      # instance-var reference -> needs 2-step
            return ('REF-UNRESOLVED', f'{lhs} (ref var)')
        v = ival(oname, var)
        if v is None: return ('UNRESOLVED', f'{lhs} unreadable')
        if isinstance(v, tuple): return ('REF-UNRESOLVED', f'{lhs}={v}')
        r = cmpv(v, rhs)
        return (('TRUE' if r else 'FALSE'), f'{lhs}={v:g} {op} {rhs}') if r is not None else ('UNRESOLVED', f'{lhs} vs {rhs}')
    # bare instance var of the event owner
    v = ival(objname, lhs) if objname else None
    if v is None: return ('UNRESOLVED', f'{lhs} (owner var?)')
    if isinstance(v, tuple): return ('REF-UNRESOLVED', f'{lhs}={v}')
    r = cmpv(v, rhs)
    return (('TRUE' if r else 'FALSE'), f'{lhs}={v:g} {op} {rhs}') if r is not None else ('UNRESOLVED', f'{lhs} vs {rhs}')

table = json.load(open(BASE/'audio-call-table.json'))
rows = [r for r in table if (OBJ is None or r['object'] == OBJ)
        and (EVE is None or r['event'].startswith(EVE))]
stats = {'TRUE': 0, 'FALSE': 0, 'UNRESOLVED': 0, 'AUDIO-STATE': 0, 'REF-UNRESOLVED': 0}
likely = []
for r in rows:
    for c in r['calls']:
        if not c['guards']:
            verdicts = [('TRUE', 'no guard')]
        else:
            verdicts = [eval_guard(g[1], r['object']) for g in c['guards']]
        tags = [v[0].replace('CHAIN-ELSE ', '') for v in verdicts]
        if any(t == 'FALSE' for t in tags): stat = 'FALSE'
        elif any(t == 'AUDIO-STATE' for t in tags): stat = 'AUDIO-STATE'
        elif any(t == 'REF-UNRESOLVED' for t in tags): stat = 'REF-UNRESOLVED'
        elif any(t == 'UNRESOLVED' for t in tags): stat = 'UNRESOLVED'
        else: stat = 'TRUE'
        stats[stat] += 1
        if stat == 'TRUE':
            likely.append((r['object'], r['event'], r['sub'], c['line'], c['sound']))
if not ALL:
    for r in rows:
        print(f"\n{r['object']}.{r['event']}({r['sub']}) c{r['code_id']}")
        last = None
        for c in r['calls']:
            v = [eval_guard(g[1], r['object']) for g in c['guards']] or [('TRUE', 'no guard')]
            if c['sound'] != last:
                last = c['sound']
                print(f"   L{c['line']:5d} {c['sound']:20s} " +
                      ' | '.join(f'{a}:{b}' for a, b in v[-2:])[:110])
print("\n== summary ==", stats)
if likely:
    print(f"likely plays (all guards TRUE): {len(likely)}")
    for o, e, s, ln, snd in likely[:20]:
        print(f"   {o}.{e}({s}) L{ln} -> {snd}")
