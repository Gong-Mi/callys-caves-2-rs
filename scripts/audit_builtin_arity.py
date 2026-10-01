#!/usr/bin/env python3
"""Audit every original builtin call against the VM's dispatch signature.

The VM dispatches builtins by name through an `expected_argc` table. A name can
be present with the wrong arity and still pass a name-only coverage audit - which
is how `collision_line` (called with 7 args by obj_shooter2's CODE 108, but
registered as 5) reached a release branch and made rm_level10's gunner raise at
runtime.

This audit closes that class of hole: it reads the argc recorded on every `call`
instruction of the recovered bytecode and fails when the VM table disagrees.
"""
import argparse
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
DEFAULT_IR = ROOT / 'crates/core/src/generated/full_ir.json'
DEFAULT_ENGINE = ROOT / 'crates/core/src/ir_scene.rs'

NAME_RE = re.compile(r'"([A-Za-z0-9_]+)"')


def parse_expected_argc(source: str) -> dict:
    """Extract the expected_argc table from the VM's dispatch match block."""
    start = source.index('let expected_argc = match n {')
    end = source.index('\n        };', start)
    block = source[start:end]
    table = {}
    pending = []
    for raw in block.splitlines():
        line = raw.split('//')[0]
        if '=>' in line:
            head, tail = line.split('=>', 1)
            pending.extend(NAME_RE.findall(head))
            kind = re.search(r'(Some\((\d+)\)|None)', tail)
            if kind is not None:
                value = int(kind.group(2)) if kind.group(1).startswith('Some') else None
                for name in pending:
                    table[name] = value
            pending = []
        else:
            pending.extend(NAME_RE.findall(line))
    return table


def observed_argc(ir_path: pathlib.Path) -> dict:
    bundle = json.loads(ir_path.read_text())
    observed = {}
    for code in bundle['codes']:
        for ins in code['instructions']:
            if ins.get('op') != 'call':
                continue
            name = ins.get('name')
            argc = ins.get('argc')
            if name is None or argc is None:
                continue
            observed.setdefault(name, set()).add(int(argc))
    return observed


def audit(table: dict, observed: dict):
    unknown = sorted(n for n in observed if n not in table)
    mismatched = []
    for name, argcs in sorted(observed.items()):
        if name not in table or table[name] is None:
            continue
        bad = sorted(a for a in argcs if a != table[name])
        if bad:
            mismatched.append((name, table[name], bad))
    return unknown, mismatched


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument('--ir', type=pathlib.Path, default=DEFAULT_IR)
    parser.add_argument('--engine', type=pathlib.Path, default=DEFAULT_ENGINE)
    parser.add_argument('--expect-mismatch', action='store_true',
                        help='invert the exit code: proves the audit catches a known gap')
    args = parser.parse_args()

    table = parse_expected_argc(args.engine.read_text())
    observed = observed_argc(args.ir)
    unknown, mismatched = audit(table, observed)

    print(f'original call sites: {len(observed)} distinct builtins')
    print(f'dispatch table entries: {len(table)}')
    for name, expected, bad in mismatched:
        print(f'MISMATCH {name}: VM expects {expected}, original calls with {bad}')
    for name in unknown:
        print(f'UNSUPPORTED {name}: called by the original but absent from the dispatch table')

    ok = not mismatched and not unknown
    if args.expect_mismatch:
        return 0 if not ok else 1
    if ok:
        print('OK: every original builtin call matches the VM dispatch signature')
        return 0
    return 1


if __name__ == '__main__':
    sys.exit(main())
