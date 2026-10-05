#!/usr/bin/env python3
"""Differential: the Java pointer adapters vs the Rust input semantics.

Both sides print the same table (fraction, mapped x, mapped y, release x,
release y) for the same surfaces; this script runs the real JVM adapters
(InputViewport + PointerReleaseQueue + PointerMappingBridge) and the Rust
example, then compares them line by line. A negative control mutates one value
and must be reported, so a comparator that always passes cannot hide a drift.

Usage: python3 scripts/test_pointer_mapping_parity.py [--tolerance 1e-3]
"""
import argparse
import pathlib
import re
import subprocess
import sys
import tempfile

root = pathlib.Path(__file__).resolve().parents[1]
source = root / 'android-build/src/com/gongmi/callyscaves2'
tests = root / 'android-build/tests'


def parse(out):
    rows = []
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 5:
            try:
                rows.append([float(p) for p in parts])
            except ValueError:
                pass
    return rows


def java_table():
    with tempfile.TemporaryDirectory(prefix='cally-parity-') as out:
        subprocess.run(['javac', '--release', '17', '-d', out,
                        str(source / 'InputViewport.java'),
                        str(source / 'PointerReleaseQueue.java'),
                        str(tests / 'PointerMappingBridge.java')], check=True)
        result = subprocess.run(['java', '-cp', out,
                                 'com.gongmi.callyscaves2.PointerMappingBridge'],
                                check=True, capture_output=True, text=True)
        return parse(result.stdout)


def rust_table():
    result = subprocess.run(['cargo', 'run', '--quiet', '-p', 'callys-client',
                             '--example', 'pointer_mapping_table'],
                            cwd=root, check=True, capture_output=True, text=True)
    return parse(result.stdout)


def compare(java, rust, tolerance):
    if len(java) != len(rust):
        raise AssertionError(f'row count differs: java={len(java)} rust={len(rust)}')
    worst = 0.0
    for i, (a, b) in enumerate(zip(java, rust)):
        for j, (x, y) in enumerate(zip(a, b)):
            diff = abs(x - y)
            worst = max(worst, diff)
            if diff > tolerance:
                raise AssertionError(f'row {i} field {j}: java={x} rust={y} diff={diff}')
    return worst, len(java)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--tolerance', type=float, default=1e-3)
    args = parser.parse_args()

    java, rust = java_table(), rust_table()
    if not java:
        print('FAIL: the JVM bridge produced no rows', file=sys.stderr)
        return 1
    worst, rows = compare(java, rust, args.tolerance)
    print(f'OK: {rows} shared vectors agree, max |java-rust| = {worst:.3e}')

    # Negative control: the comparator must not be a rubber stamp.
    mutated = [row[:] for row in java]
    mutated[0][3] += 0.5
    try:
        compare(mutated, rust, args.tolerance)
    except AssertionError as exc:
        print(f'OK: negative control detected as intended ({exc})')
        return 0
    print('FAIL: a 0.5px mutation went undetected', file=sys.stderr)
    return 1


if __name__ == '__main__':
    sys.exit(main())
