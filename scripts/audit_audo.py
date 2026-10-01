import struct, json
data = open('assets/game.droid','rb').read()
i = data.find(b'AUDO')
p = i + 8
count = struct.unpack('<I', data[p:p+4])[0]
ptrs = [struct.unpack('<I', data[p+4+4*k:p+8+4*k])[0] for k in range(count)]
rows = []
for k, ptr in enumerate(ptrs):
    slen = struct.unpack('<I', data[ptr:ptr+4])[0]
    wav = data[ptr+4:ptr+4+slen]
    assert wav[:4] == b'RIFF', (k, wav[:4])
    pos = 12; rate = ch = bits = 0; dsz = 0
    while pos < len(wav) - 8:
        cid = wav[pos:pos+4]; sz = struct.unpack('<I', wav[pos+4:pos+8])[0]
        if cid == b'fmt ':
            fmt, ch, rate, br, align, bits = struct.unpack('<HHIIHH', wav[pos+8:pos+24])
        if cid == b'data':
            dsz = sz
        pos += 8 + sz + (sz & 1)
    dur = dsz / (rate * ch * bits / 8)
    rows.append(dict(audo_id=k, bytes=slen, fmt=fmt, channels=ch, rate=rate, bits=bits, duration_s=round(dur, 3)))
json.dump(rows, open('reconstruction/contracts/audio-audo.json', 'w'), indent=1)
print('written', len(rows))
specs = {(r['fmt'], r['channels'], r['rate'], r['bits']) for r in rows}
print('distinct specs:', specs)
