#!/usr/bin/env python3
"""One-time parts cut proof; compares complete expanded bytes against pre-cut revision."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
SOURCE = 'crates/client/src/lib.rs'
PARTS = [
    ('crates/client/src/parts/save.rs', 'include!("parts/save.rs");\n'),
    ('crates/client/src/parts/audio.rs', 'include!("parts/audio.rs");\n'),
    ('crates/client/src/parts/jni.rs', 'include!("parts/jni.rs");\n'),
]

def verify(baseline):
    before = subprocess.check_output(
        ['git', '-C', str(ROOT), 'show', f'{baseline}:{SOURCE}'],
        text=True
    )
    current = (ROOT / SOURCE).read_text(encoding='utf-8')
    expanded = current
    for part_rel, marker in PARTS:
        part_content = (ROOT / part_rel).read_text(encoding='utf-8')
        assert marker in expanded, f'marker {marker} not found in source'
        expanded = expanded.replace(marker, part_content)

    assert expanded == before, 'expanded source differs from pre-cut baseline'
    return {
        'expanded_byte_identical': True,
        'baseline': baseline,
        'expanded_sha256': hashlib.sha256(expanded.encode('utf-8')).hexdigest(),
        'before_lines': len(before.splitlines()),
        'current_lines': len(current.splitlines()),
        'parts': [p[0] for p in PARTS]
    }

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('baseline', help='pre-cut git revision (e.g. HEAD)')
    args = parser.parse_args()
    report = verify(args.baseline)
    print(json.dumps(report, indent=2))
