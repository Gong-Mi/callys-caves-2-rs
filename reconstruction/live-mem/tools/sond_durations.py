#!/usr/bin/env python3
"""Emit reconstruction/contracts/audio-durations.json for ALL sond entries.

Two sources:
  * music  (sond kind 5199697, ext *.ogg)  -> APK assets/mus_<ext>: OGG granule
    position / sample rate from the Vorbis identification header.
  * sfx    (sond kind 5198594, embedded)   -> game.droid AUDO chunk: RIFF/WAVE
    fmt byte-rate and data size.

Usage: sond_durations.py [--apk P] [--droid P] [-o out.json]
"""
import json, pathlib, struct, sys, zipfile

HOME = pathlib.Path.home()
REPO = HOME/'callys-caves-2-rs'
apk = HOME/'cally-work/shell32/apk/base.apk'
droid = REPO/'assets/game.droid'
sond_p = REPO/'reconstruction/contracts/audio-sond.json'
out = REPO/'reconstruction/contracts/audio-durations.json'
for flag, setter in (('--apk', 'apk'), ('--droid', 'droid'), ('-o', 'out')):
    if flag in sys.argv:
        val = pathlib.Path(sys.argv[sys.argv.index(flag)+1])
        if flag == '--apk': apk = val
        elif flag == '--droid': droid = val
        else: out = val

sond = json.load(open(sond_p))
rows = []

# ---- music: OGG from the APK
def ogg_duration(data):
    if data[:4] != b'OggS': return None
    off, rate, last = 0, None, 0
    while True:
        i = data.find(b'OggS', off)
        if i < 0 or i + 27 > len(data): break
        nseg = data[i+26]
        seg = data[i+27:i+27+nseg]
        body = i + 27 + nseg
        size = sum(seg)
        granule = struct.unpack_from('<q', data, i+6)[0]
        payload = data[body:body+size]
        if rate is None and payload[:7] == b'\x01vorbis':
            rate = struct.unpack_from('<I', payload, 12)[0]
        if granule > 0: last = granule
        off = body + size
        if off >= len(data): break
    return (last/float(rate)) if rate else None

z = zipfile.ZipFile(apk)
assets = {n.rsplit('/', 1)[-1]: n for n in z.namelist() if n.startswith('assets/')}
for e in sond:
    ext = e.get('ext') or ''
    if ext.endswith('.ogg'):
        cand = 'mus_' + ext
        if cand in assets:
            secs = ogg_duration(z.read(assets[cand]))
            if secs:
                rows.append({'sond_id': e['sond_id'], 'name': e['name'], 'source': 'ogg',
                             'asset': assets[cand], 'seconds': round(secs, 3),
                             'ticks_at_30hz': int(round(secs*30))})

# ---- sfx: WAV from game.droid's AUDO chunk
d = open(droid, 'rb').read()
form_len = struct.unpack_from('<I', d, 4)[0]
off, chunks = 8, {}
while off < min(form_len+8, len(d)):
    name = d[off:off+4]; size = struct.unpack_from('<I', d, off+4)[0]
    chunks[name] = (off+8, size); off += 8 + ((size+3) & ~3)
audo_dur = {}
if b'AUDO' in chunks:
    apos = chunks[b'AUDO'][0]
    count = struct.unpack_from('<I', d, apos)[0]
    offs = struct.unpack_from(f'<{count}I', d, apos+4)
    for i, ro in enumerate(offs):
        wlen = struct.unpack_from('<I', d, ro)[0]
        buf = d[ro+4:ro+4+wlen]
        if buf[:4] != b'RIFF' or buf[8:12] != b'WAVE': continue
        o, rate, dlen = 12, None, None
        while o + 8 <= len(buf):
            cid = buf[o:o+4]; csz = struct.unpack_from('<I', buf, o+4)[0]; body = o+8
            if cid == b'fmt ' and len(buf) >= body+16:
                rate = struct.unpack_from('<I', buf, body+8)[0]
            elif cid == b'data':
                dlen = csz
            o = body + csz + (csz & 1)
        if rate and dlen: audo_dur[i] = dlen/float(rate)
for e in sond:
    if e.get('kind') == 5198594:
        secs = audo_dur.get(e['audio_id'])
        if secs:
            rows.append({'sond_id': e['sond_id'], 'name': e['name'], 'source': 'wav',
                         'asset': f"game.droid:AUDO[{e['audio_id']}]",
                         'seconds': round(secs, 3), 'ticks_at_30hz': int(round(secs*30))})

rows.sort(key=lambda r: r['sond_id'])
json.dump(rows, open(out, 'w'), indent=1)
oggs = sum(1 for r in rows if r['source'] == 'ogg')
wavs = sum(1 for r in rows if r['source'] == 'wav')
print(f'{len(rows)} durations ({oggs} ogg / {wavs} wav) -> {out}')
print('missing sond ids:', [e['sond_id'] for e in sond
                            if e['sond_id'] not in {r['sond_id'] for r in rows}])
