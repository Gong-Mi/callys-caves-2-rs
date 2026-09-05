#!/usr/bin/env python3
"""Verify a real upstream GML export against the pinned original CODE table."""
import argparse
import hashlib
import json
from pathlib import Path
import re
from reverse_code import Reader, SHA256


def verify(asset, directory):
    raw = asset.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA256, 'wrong input'
    codes = Reader(raw).codes()
    entries = [json.loads(line) for line in (directory / 'entries.jsonl').read_text().splitlines()]
    assert len(entries) == len(codes) == 1354
    assert sorted(e['id'] for e in entries) == list(range(len(codes))), 'missing/duplicate IDs'
    summary = json.loads((directory / 'summary.json').read_text())
    assert summary['input_sha256'] == SHA256
    exported, failures, warned = [], [], []
    for entry in entries:
        assert entry['name'] == codes[entry['id']]['name'], 'CODE identity mismatch'
        if entry['status'] == 'failed':
            assert entry['error']
            failures.append(entry['id'])
            continue
        assert entry['status'] == 'exported'
        expected_file = f"code/{entry['id']:04d}.gml"
        assert entry['file'] == expected_file
        data = (directory / expected_file).read_bytes()
        assert len(data) == entry['bytes']
        assert hashlib.sha256(data).hexdigest() == entry['sha256']
        assert entry['semantics_verified'] is False and entry['runtime_verified'] is False
        exported.append(entry['id'])
        if entry['warnings']:
            warned.append(entry['id'])
    actual = sorted(p.name for p in (directory / 'code').iterdir())
    assert actual == sorted(f'{idx:04d}.gml' for idx in exported), 'stale or missing GML files'
    assert summary['exported'] == len(exported)
    assert summary['failed'] == len(failures)
    assert summary['warned'] == len(warned)
    # Small bytecode-proven anchors, not proof of all emitted GML semantics.
    anchors = {3: ['invulnerable', 'invulnerable2'], 7: ['sliding1', 'sliding2', 'hsp']}
    for idx, variables in anchors.items():
        assert idx in exported, f'anchor CODE {idx} failed'
        text = (directory / f'code/{idx:04d}.gml').read_text()
        for var in variables:
            assert re.search(rf'\b{var}\s*=\s*0\s*;', text), f'missing original anchor {idx}:{var}'
    report = dict(code_count=len(codes), exported=len(exported), failed_ids=failures,
                  warned_ids=warned, checked_constant_anchor_code_ids=sorted(anchors),
                  full_semantics_verified=0, runtime_verified=0)
    (directory / 'verification.json').write_text(json.dumps(report, indent=2) + '\n')
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('asset', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(args.asset, args.output), indent=2))
