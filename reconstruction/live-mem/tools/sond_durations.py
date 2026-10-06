#!/usr/bin/env python3
"""Compute music durations from the APK's assets/mus_*.ogg (+ sond mapping).

OGG/Vorbis: the identification header gives sample rate; the last page's
granule position is the total sample count. duration = granule / rate.
Music files are packaged as assets/mus_<ext>; sond ids >= 29 are the music
entries in audio-sond.json (their ext is '<name>.ogg').

Usage: sond_durations.py [apk] [sond.json] [-o out.json]
"""
import json, pathlib, struct, sys, zipfile

apk = sys.argv[1] if len(sys.argv) > 1 else \
    '/data/data/com.termux/files/home/cally-work/shell32/apk/base.apk'
sond_p = sys.argv[2] if len(sys.argv) > 2 else \
    str(pathlib.Path.home()/'callys-caves-2-rs/reconstruction/contracts/audio-sond.json')
out = pathlib.Path(sys.argv[sys.argv.index('-o')+1]) if '-o' in sys.argv else \
    pathlib.Path.home()/'callys-caves-2-rs/reconstruction/contracts/audio-durations.json'

sond = json.load(open(sond_p))
z = zipfile.ZipFile(apk)
assets = {n.rsplit('/', 1)[-1]: n for n in z.namelist() if n.startswith('assets/')}

def ogg_info(name):
    data = z.read(assets[name])
    if data[:4] != b'OggS':
        return None
    off = 0; rate = None; last_granule = 0
    while True:
        i = data.find(b'OggS', off)
        if i < 0 or i + 27 > len(data):
            break
        nseg = data[i + 26]
        seg = data[i + 27:i + 27 + nseg]
        body = i + 27 + nseg
        size = sum(seg)
        granule = struct.unpack_from('<q', data, i + 6)[0]
        payload = data[body:body + size]
        if rate is None and payload[:7] == b'\x01vorbis':
            rate = struct.unpack_from('<I', payload, 12)[0]
        if granule > 0:
            last_granule = granule
        off = body + size
        # stop when the next page is not found
        if off >= len(data):
            break
    if rate:
        return last_granule / float(rate), rate, last_granule
    return None

rows = []
for e in sond:
    ext = e.get('ext') or ''
    if not ext.endswith('.ogg'):
        continue
    cand = 'mus_' + ext
    if cand not in assets:
        print(f"  sond {e['sond_id']:3d} {e['name']:16s} ext={ext} -> asset {cand} NOT FOUND")
        continue
    info = ogg_info(cand)
    if not info:
        print(f"  sond {e['sond_id']:3d} {cand}: not a parseable ogg")
        continue
    secs, rate, gran = info
    rows.append({'sond_id': e['sond_id'], 'name': e['name'], 'asset': assets[cand],
                 'seconds': round(secs, 3), 'sample_rate': rate,
                 'ticks_at_30hz': int(round(secs * 30))})
    print(f"  sond {e['sond_id']:3d} {e['name']:16s} {cand:26s} {secs:8.2f}s  "
          f"({int(round(secs*30))} ticks @30Hz)")

json.dump(rows, open(out, 'w'), indent=1)
print(f"{len(rows)} music durations -> {out}")
