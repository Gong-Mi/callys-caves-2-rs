#!/usr/bin/env python3
"""One-time font cut proof; pass the pre-cut revision, not a permanent freeze.

Compare complete expanded bytes, then replay symbol-anchored source windows.
This measures returned source characters, not tokens or model behavior.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
SOURCE = 'crates/client/src/lib.rs'
FRAGMENT = 'crates/client/src/parts/font.rs'
MARKER = b'include!("parts/font.rs");\n'
FONT = re.compile(rb'^const FONT_5X7: \[\[u8; 5\]; 95\] = \[\n.*?^\];\n', re.M | re.S)


def excerpt(source, before_lines):
    lines = source.decode('utf-8').splitlines()
    start = next(i for i, line in enumerate(lines) if line.startswith('fn draw_sprite('))
    end = next(i for i, line in enumerate(lines) if line.startswith('pub fn draw_frame(')) + 8
    assert start >= before_lines
    return '\n'.join(lines[start - before_lines:end]) + '\n'


def verify(before, current, font):
    match = FONT.search(before)
    assert match is not None, 'pre-cut font item not found'
    assert current.count(MARKER) == 1, 'expected one same-scope font include'
    assert font == match[0], 'font fragment differs from complete pre-cut item'
    expanded = current.replace(MARKER, font)
    assert expanded == before, 'expanded client source differs from pre-cut revision'
    # Explicit negative control: this proof must reject a changed glyph.
    changed = font.replace(b'0x00', b'0x01', 1)
    assert changed != font and current.replace(MARKER, changed) != before
    exact_before, exact_after = excerpt(before, 0), excerpt(current, 0)
    assert exact_before == exact_after, 'required draw helpers/entry changed'
    wide_before, wide_after = excerpt(before, 32), excerpt(current, 32)
    assert len(re.findall(r'\[0x', wide_before)) == 30
    assert not re.search(r'\[0x', wide_after), 'font rows still leak into draw window'
    return dict(
        expanded_byte_identical=True,
        expanded_sha256=hashlib.sha256(expanded).hexdigest(),
        font_sha256=hashlib.sha256(font).hexdigest(),
        font_bytes=len(font), font_lines=len(font.splitlines()),
        before_root_lines=len(before.splitlines()), after_root_lines=len(current.splitlines()),
        exact_symbol=dict(before_chars=len(exact_before), after_chars=len(exact_after), identical=True),
        same_75_line_neighborhood=dict(before_chars=len(wide_before), after_chars=len(wide_after),
            before_lines=len(wide_before.splitlines()), after_lines=len(wide_after.splitlines()),
            before_glyph_rows=30, after_glyph_rows=0),
        limits='Synthetic source-window replay; not token savings or a live model A/B test.',
    )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('baseline', help='pre-cut git revision')
    args = parser.parse_args()
    baseline = subprocess.check_output(['git', '-C', str(ROOT), 'rev-parse', '--verify',
                                        args.baseline + '^{commit}'], text=True).strip()
    before = subprocess.check_output(['git', '-C', str(ROOT), 'show', f'{baseline}:{SOURCE}'])
    path = ROOT / FRAGMENT
    assert path.is_file(), 'font fragment missing: physical cut not applied'
    report = verify(before, (ROOT / SOURCE).read_bytes(), path.read_bytes())
    report['baseline'] = baseline
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
