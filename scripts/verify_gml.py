#!/usr/bin/env python3
"""Verify a real upstream GML export against the pinned original CODE table."""
import argparse
import hashlib
import json
from pathlib import Path
import re
from reverse_code import Reader, SHA256


def verify(asset, directory, require_roundtrip=False):
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
    contract_path = Path(__file__).resolve().parents[1] / 'reconstruction/contracts/player-alarms.json'
    contract = json.loads(contract_path.read_text())
    assert contract['asset_sha256'] == SHA256
    for binding in contract['bindings']:
        assert (directory / f"code/{binding['code_id']:04d}.gml").read_text() == binding['gml']
        assert codes[binding['code_id']]['sha256'] == binding['bytecode_sha256']
    report = dict(code_count=len(codes), exported=len(exported), failed_ids=failures,
                  warned_ids=warned, checked_constant_anchor_code_ids=sorted(anchors),
                  full_semantics_verified=0, runtime_verified=0)
    if require_roundtrip:
        trips = [json.loads(line) for line in (directory / 'roundtrip.jsonl').read_text().splitlines()]
        assert sorted(t['id'] for t in trips) == list(range(len(codes)))
        rt = json.loads((directory / 'roundtrip-summary.json').read_text())
        good = [t for t in trips if t['status'] == 'compiled']
        bad = [t for t in trips if t['status'] == 'failed']
        assert len(good) + len(bad) == len(codes)
        assert rt['compiled'] == len(good) and rt['failed'] == len(bad)
        assert rt['same_symbolic_disassembly'] == sum(t['assembly_equal'] for t in good)
        assert rt['same_redecompiled_text'] == sum(t['redecompiled_text_equal'] for t in good)
        assert rt['raw_binary_equality_verified'] is False and rt['runtime_verified'] is False
        expected_diffs = []
        for t in trips:
            assert t['name'] == codes[t['id']]['name']
            if t['status'] == 'failed':
                assert t['error']
                continue
            if not t['assembly_equal'] or not t['redecompiled_text_equal']:
                stem = f"{t['id']:04d}"
                before = (directory / 'roundtrip-differences' / (stem + '.before.asm')).read_text()
                after = (directory / 'roundtrip-differences' / (stem + '.after.asm')).read_text()
                again = (directory / 'roundtrip-differences' / (stem + '.after.gml')).read_text()
                original = (directory / 'code' / (stem + '.gml')).read_text()
                assert (before == after) == t['assembly_equal']
                assert (again == original) == t['redecompiled_text_equal']
                expected_diffs.extend(stem + suffix for suffix in ['.before.asm', '.after.asm', '.after.gml'])
        assert sorted(p.name for p in (directory / 'roundtrip-differences').iterdir()) == sorted(expected_diffs)
        report['roundtrip'] = rt
        report['roundtrip_failed_ids'] = [t['id'] for t in bad]
        report['assembly_difference_ids'] = [t['id'] for t in good if not t['assembly_equal']]
        report['redecompilation_difference_ids'] = [t['id'] for t in good if not t['redecompiled_text_equal']]
    (directory / 'verification.json').write_text(json.dumps(report, indent=2) + '\n')
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('asset', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--require-roundtrip', action='store_true')
    args = parser.parse_args()
    print(json.dumps(verify(args.asset, args.output, args.require_roundtrip), indent=2))
