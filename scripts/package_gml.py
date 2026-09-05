#!/usr/bin/env python3
"""Organize recovered GML with original, pointer-derived ownership metadata."""
import argparse
import hashlib
import json
from pathlib import Path
import re
from reverse_code import Reader, SHA256
from verify_gml import verify


def package(asset, export):
    verification = verify(asset, export, require_roundtrip=True)
    assert verification['exported'] == 1354 and not verification['failed_ids']
    target = export / 'restored-source'
    assert not target.exists(), 'refuse stale source tree'
    (target / 'gml').mkdir(parents=True)
    data = asset.read_bytes()
    assert hashlib.sha256(data).hexdigest() == SHA256
    reader = Reader(data)
    codes = reader.codes()
    objects = reader.objects(codes)
    rooms = reader.rooms(codes)
    entries = {r['id']: r for r in map(json.loads, (export / 'entries.jsonl').read_text().splitlines())}
    trips = {r['id']: r for r in map(json.loads, (export / 'roundtrip.jsonl').read_text().splitlines())}
    index = []
    for c in codes:
        name = re.sub(r'[^A-Za-z0-9_.-]', '_', c['name'])
        filename = f"gml/{c['id']:04d}__{name}.gml"
        original = export / entries[c['id']]['file']
        text = original.read_bytes()
        (target / filename).write_bytes(text)
        assert hashlib.sha256(text).hexdigest() == entries[c['id']]['sha256']
        index.append(dict(id=c['id'], name=c['name'], file=filename,
                          original_bytecode_offset=c['start'], original_bytecode_bytes=c['length'],
                          gml_sha256=entries[c['id']]['sha256'], owners=c['owners'],
                          roundtrip=trips[c['id']], runtime_verified=False))
    assert len(index) == len(list((target / 'gml').iterdir())) == 1354
    assert all(c['owners'] for c in index)
    for name, value in [('index.json', index), ('objects.json', objects), ('rooms.json', rooms)]:
        (target / name).write_text(json.dumps(value, indent=2) + '\n')
    (target / 'README.txt').write_text(
        'Callys Caves 2: recovered GML source, NOT the original GameMaker project.\n'
        'gml/: every original CODE entry as a named GML unit.\n'
        'index.json: original CODE id/address, source hash, pointer-derived owners and roundtrip status.\n'
        'objects.json: direct OBJT events/actions and parent ids; no invented inherited events.\n'
        'rooms.json: ROOM/instance creation-code associations.\n'
        'Compilation uses the pinned Underanalyzer via UndertaleModLib in GitHub CI.\n'
        'Assets, runner, project/editor metadata, original comments and runtime parity are NOT supplied by this tree.\n'
        'See ../verification.json and ../roundtrip-differences/ for exact mismatches.\n'
        'Original game data SHA256: ' + SHA256 + '\n'
    )
    report = dict(source_units=len(index), objects=len(objects), rooms=len(rooms),
                  source_hashes_verified=True, pointer_owners_complete=True,
                  asm_difference_ids=verification['assembly_difference_ids'],
                  game_project_reconstructed=False, runtime_verified=False)
    (target / 'package-summary.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('asset', type=Path)
    p.add_argument('export', type=Path)
    args = p.parse_args()
    package(args.asset, args.export)
