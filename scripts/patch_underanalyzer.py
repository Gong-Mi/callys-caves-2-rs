#!/usr/bin/env python3
"""Hash-guarded upstream source adaptation; never normalize output assembly."""
import argparse
import hashlib
import json
from pathlib import Path

BEFORE_SHA256 = '3bbe2eccf841b80f3e99859a0ccabe9c930964f52ee551b18908847340a5bc0b'
RELATIVE = 'Underanalyzer/Decompiler/AST/Nodes/AssignNode.cs'
OLD = b'if (cleaner.Context.OlderThanBytecode15 || binVariable.RegularPush || binVariable.Variable.InstanceType == InstanceType.Self)'
NEW = (b'if (cleaner.Context.OlderThanBytecode15 || binVariable.RegularPush ||\n'
       b'                    (cleaner.Context.GMLv2 && binVariable.Variable.InstanceType == InstanceType.Self))')


def apply(root, report):
    target = root / RELATIVE
    original = target.read_bytes()
    assert hashlib.sha256(original).hexdigest() == BEFORE_SHA256, 'unexpected upstream source; refuse patch'
    assert original.count(OLD) == 1, 'patch context must be unique'
    changed = original.replace(OLD, NEW)
    target.write_bytes(changed)
    assert target.read_bytes() == changed
    result = dict(adaptation='legacy-specialized-assignment-v1',
                  upstream_commit='4ff50a866b4c1a7acee8cebe6a56d6a48709b453', file=RELATIVE,
                  before_sha256=BEFORE_SHA256, after_sha256=hashlib.sha256(changed).hexdigest(),
                  scope='GML1 bytecode15+ specialized Self reads must not be folded to compound assignment; preserve bytecode14 and GML2 exceptions')
    report.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('upstream', type=Path)
    p.add_argument('report', type=Path)
    args = p.parse_args()
    apply(args.upstream, args.report)
