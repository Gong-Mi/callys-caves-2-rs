"""GML usage audit for the original audio domain: play sites, gates,
stop/gain calls per sound name, from the 1,354 recovered GML units."""
import json, os, re, collections

GML_DIR = os.environ.get(
    "CALLY_GML_DIR",
    "/data/data/com.termux/files/home/cally-recovered-gml-0ca243a/restored-source/gml",
)

plays = collections.Counter()
looping = collections.Counter()
gates = collections.Counter()
stops = collections.Counter()
gains = collections.Counter()

play_re = re.compile(
    r"audio_play_sound\(\s*([a-zA-Z_][a-zA-Z_0-9]*)\s*,\s*([a-zA-Z_0-9.]+)\s*,\s*(true|false)\s*\)"
)
gate_re = re.compile(r"audio_is_playing\(\s*([a-zA-Z_][a-zA-Z_0-9]*)\s*\)")
stop_re = re.compile(r"audio_stop_sound\(\s*([a-zA-Z_][a-zA-Z_0-9]*)\s*\)")
gain_re = re.compile(r"audio_sound_gain\(\s*([a-zA-Z_][a-zA-Z_0-9]*)\s*,")

total_files = 0
for fname in os.listdir(GML_DIR):
    if not fname.endswith(".gml"):
        continue
    total_files += 1
    text = open(os.path.join(GML_DIR, fname), encoding="utf-8", errors="replace").read()
    for m in play_re.finditer(text):
        plays[m.group(1)] += 1
        if m.group(3) == "true":
            looping[m.group(1)] += 1
    for m in gate_re.finditer(text):
        gates[m.group(1)] += 1
    for m in stop_re.finditer(text):
        stops[m.group(1)] += 1
    for m in gain_re.finditer(text):
        gains[m.group(1)] += 1

out = {
    "gml_files_scanned": total_files,
    "total_play_sites": sum(plays.values()),
    "total_gate_sites": sum(gates.values()),
    "total_stop_sites": sum(stops.values()),
    "total_gain_sites": sum(gains.values()),
    "plays_by_name": dict(plays.most_common()),
    "looping_plays_by_name": dict(looping.most_common()),
    "gates_by_name": dict(gates.most_common()),
    "stops_by_name": dict(stops.most_common()),
    "gains_by_name": dict(gains.most_common()),
}
json.dump(out, open("reconstruction/contracts/audio-usage.json", "w"), indent=1)
print("files:", total_files)
print("play sites:", sum(plays.values()), "| gates:", sum(gates.values()),
      "| stops:", sum(stops.values()), "| gains:", sum(gains.values()))
print("top plays:", plays.most_common(6))
print("looping:", dict(looping.most_common()))
print("top gates:", gates.most_common(4))
print("top stops:", stops.most_common(4))
print("gain names:", len(gains))
