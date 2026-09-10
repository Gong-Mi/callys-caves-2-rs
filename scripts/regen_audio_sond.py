"""Regenerate reconstruction/contracts/audio-sond.json with the correct
SOND field layout: name_ptr(+0) flags(+4) type(+8) file_ptr(+12)
effects(+16) volume_f32(+20) pitch_f32(+24) ?(+28) audio_id(+32).
Matches crates/asset/src/lib.rs: name word then 7 skipped words, audio_id
at +32 (RECORD_SIZE=36). The previous revision misread +24 (pitch) as
audio_id, emitting zeros."""
import struct, json

data = open("assets/game.droid", "rb").read()
i = data.find(b"SOND")
p = i + 8
count = struct.unpack("<I", data[p:p + 4])[0]
ptrs = [struct.unpack("<I", data[p + 4 + 4 * k:p + 8 + 4 * k])[0] for k in range(count)]

rows = []
for k, q in enumerate(ptrs):
    name_ptr = struct.unpack("<I", data[q:q + 4])[0]
    slen = struct.unpack("<I", data[name_ptr:name_ptr + 4])[0]
    name = data[name_ptr + 4:name_ptr + 4 + slen].split(b"\x00")[0].decode()
    flags = struct.unpack("<I", data[q + 4:q + 8])[0]
    kind = struct.unpack("<I", data[q + 8:q + 12])[0]
    ext_ptr = struct.unpack("<I", data[q + 12:q + 16])[0]
    elen = struct.unpack("<I", data[ext_ptr:ext_ptr + 4])[0]
    ext = data[ext_ptr + 4:ext_ptr + 4 + elen].split(b"\x00")[0].decode()
    effects = struct.unpack("<I", data[q + 16:q + 20])[0]
    volume = struct.unpack("<f", data[q + 20:q + 24])[0]
    pitch = struct.unpack("<f", data[q + 24:q + 28])[0]
    audio_id = struct.unpack("<I", data[q + 32:q + 36])[0]
    rows.append(dict(sond_id=k, name=name, flags=flags, kind=kind, ext=ext,
                     effects=effects, volume=round(volume, 4),
                     pitch=round(pitch, 4), audio_id=audio_id))

json.dump(rows, open("reconstruction/contracts/audio-sond.json", "w"), indent=1)

# Structural invariants, fail closed:
ids = [r["audio_id"] for r in rows]
wav_rows = [r for r in rows if r["ext"].endswith(".wav")]
ogg_rows = [r for r in rows if r["ext"].endswith(".ogg")]
assert len(rows) == 54, len(rows)
assert all(r["pitch"] == 0.0 for r in rows), "unexpected nonzero pitch"
# embedded wav SONDs must map 1:1 onto the 29 AUDO entries, order preserved
assert len(wav_rows) == 29, len(wav_rows)
assert [r["audio_id"] for r in wav_rows] == list(range(29)), \
    "wav SOND audio_ids must be the identity permutation of AUDO 0..28"
# external music SONDs carry audio_id 28 (the last AUDO entry) as a
# placeholder — GMS 1.4 marks streamed music this way; the asset crate's
# audio_id < audio_count check passes because 28 < 29.
assert all(r["audio_id"] == 28 for r in ogg_rows), \
    "external music SONDs must carry the audio_id=28 placeholder"
print("entries:", len(rows), "| wav:", len(wav_rows), "| ogg:", len(ogg_rows))
print("wav audio_id sequence OK (identity 0..28)")
print("sample:", rows[3], rows[32])
