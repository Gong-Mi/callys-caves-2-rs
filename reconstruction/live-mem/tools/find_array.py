#!/usr/bin/env python3
"""Locate a GML array's backing data by searching memory for its value sequence.

Strategy: read `global.playlist` live, take that playlist's theme[0..16] ints
from the recovered GML, then stream the process's writable mappings looking for
that sequence as int32 and as double — the hit pinpoints the array layout
(header fields + element stride + element encoding).

Usage: find_array.py <pid> <rw_base_hex> <playlist>
"""
import os, struct, sys

pid = int(sys.argv[1]); RW = int(sys.argv[2], 16); PLAYLIST = int(sys.argv[3])
GML = '/data/data/com.termux/files/home/cally-recovered-gml-fd6fc01/restored-source/gml/0375__gml_Object_obj_music_Create_0.gml'

# --- parse the playlist table out of the recovered GML
theme = {}
cur = None
for line in open(GML, errors='replace'):
    s = line.strip()
    if s.startswith('if (global.playlist =='):
        cur = int(s.split('==')[1].strip().rstrip(')'))
    elif s.startswith('theme[') and cur is not None:
        idx = int(s.split('[')[1].split(']')[0])
        val = int(s.split('=')[1].strip().rstrip(';'))
        theme.setdefault(cur, {})[idx] = val
table = theme.get(PLAYLIST)
print(f'playlist {PLAYLIST}: {len(table)} theme entries')
seq = [table[i] for i in range(17) if i in table]
print('theme[0..16] =', seq)

# --- mappings
maps = []
for line in open(f'/proc/{pid}/maps'):
    parts = line.split()
    if len(parts) < 2 or 'w' not in parts[1]:
        continue
    lo, hi = [int(x, 16) for x in parts[0].split('-')]
    if hi - lo > 300*1024*1024:
        continue
    maps.append((lo, hi, parts[-1] if len(parts) > 5 else 'anon'))
print(f'writable mappings: {len(maps)}, total '
      f'{sum(h-l for l,h,_ in maps)/1e6:.0f} MB')

def scan(needle_bytes, label, stride_align=4):
    pat = needle_bytes
    for lo, hi, name in maps:
        try:
            with open(f'/proc/{pid}/mem', 'rb', buffering=0) as f:
                pos = lo
                while pos < hi:
                    chunk = min(8*1024*1024, hi - pos)
                    try:
                        os.lseek(f.fileno(), pos, os.SEEK_SET)
                        buf = os.read(f.fileno(), chunk)
                    except Exception:
                        break
                    if not buf: break
                    i = buf.find(pat)
                    while i >= 0:
                        addr = pos + i
                        if addr % stride_align == 0:
                            print(f'  {label} hit @{addr:#x} in {name}')
                            return addr
                        i = buf.find(pat, i + 1)
                    pos += len(buf)
        except Exception:
            continue
    return None

def scan_all(pat, label):
    hits = []
    for lo, hi, name in maps:
        try:
            with open(f'/proc/{pid}/mem', 'rb', buffering=0) as f:
                pos = lo
                while pos < hi:
                    chunk = min(8*1024*1024, hi - pos)
                    try:
                        os.lseek(f.fileno(), pos, os.SEEK_SET)
                        buf = os.read(f.fileno(), chunk)
                    except Exception:
                        break
                    if not buf: break
                    i = buf.find(pat)
                    while i >= 0:
                        hits.append((pos + i, name))
                        i = buf.find(pat, i + 1)
                    pos += len(buf)
        except Exception:
            continue
    print(f'{label}: {len(hits)} hits {[(hex(a), n) for a, n in hits[:6]]}')
    return hits

n4 = seq[:4]
print('prefix ints :', n4)
print('prefix reals:', [float(v) for v in n4])
hit_i = scan_all(struct.pack('<4i', *n4), 'int32[0:4]')
hit_d = scan_all(struct.pack('<4d', *n4), 'double[0:4]')
# also try {index,value} pairs (double) for first two entries
pair = struct.pack('<4d', 0.0, float(seq[0]), 1.0, float(seq[1]))
scan_all(pair, 'pair(0,v0,1,v1) double')
if hit_i: hit_i = hit_i[0][0]
else: hit_i = None
if hit_d: hit_d = hit_d[0][0]
else: hit_d = None
if hit_i:
    print(f'--- int32 sequence at {hit_i:#x}; dumping 0x100 bytes around ---')
    with open(f'/proc/{pid}/mem', 'rb', buffering=0) as fh:
        os.lseek(fh.fileno(), hit_i - 0x40, os.SEEK_SET)
        raw = os.read(fh.fileno(), 0x100)
    w = struct.unpack('<64I', raw)
    for i in range(0, 64, 4):
        print(f'  +{(i-16)*4:+#06x}: ' + ' '.join(f'{v:#010x}' for v in w[i:i+4]))
if hit_d:
    print(f'--- double sequence at {hit_d:#x} ---')
