#!/usr/bin/env python3
"""Static audio-call table from the recovered GML snapshot.

Scans restored-source/gml/NNNN__gml_Object_<obj>_<Event>_<sub>.gml for
audio_* calls and emits {object, event, code_id, calls:[{line, text}]}.

Usage: audio_static_table.py [snapshot_dir] [-o out.json]
"""
import json, re, sys, pathlib

SNAP = pathlib.Path(sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith('-')
                    else pathlib.Path.home() / 'cally-recovered-gml-fd6fc01')
OUT = pathlib.Path(sys.argv[sys.argv.index('-o')+1] if '-o' in sys.argv else
                   pathlib.Path(__file__).parent.parent / 'audio-call-table.json')

CALLS = ('audio_play_sound', 'audio_play_music', 'audio_stop_sound',
         'audio_stop_all', 'audio_stop_music', 'audio_pause_sound',
         'audio_resume_sound', 'audio_sound_set_volume', 'audio_master_gain',
         'audio_sound_gain', 'audio_sound_pitch', 'audio_falloff_set_model')
pat = re.compile(r'\b(' + '|'.join(CALLS) + r')\s*\(')

rows = []
gdir = SNAP / 'restored-source' / 'gml'
files = sorted(gdir.glob('*.gml'))
for f in files:
    m = re.match(r'^(\d+)__gml_Object_(.+?)_(Create|Destroy|Step|Draw|Alarm|Other|KeyPress|KeyRelease|Mouse|Collision|RoomStart|RoomEnd|GameStart)_(\d+)\.gml$', f.name)
    if not m:
        continue
    code_id, obj, event, sub = m.groups()
    try:
        text = f.read_text(errors='replace')
    except Exception:
        continue
    calls = []
    for ln, line in enumerate(text.splitlines(), 1):
        mm = pat.search(line)
        if mm:
            calls.append({'line': ln, 'call': mm.group(1), 'text': line.strip()[:200]})
    if calls:
        rows.append({'code_id': int(code_id), 'object': obj, 'event': event,
                     'sub': int(sub), 'file': f.name, 'calls': calls})

json.dump(rows, open(OUT, 'w'), indent=1)
total = sum(len(r['calls']) for r in rows)
objs = sorted({r['object'] for r in rows})
print(f'{len(files)} gml files scanned; {len(rows)} events with audio; {total} calls; '
      f'{len(objs)} objects')
print('objects:', ', '.join(objs[:25]) + (' ...' if len(objs) > 25 else ''))
print(f'table -> {OUT}')
