#!/usr/bin/env python3
"""Audit per-instruction anchor coverage of the C lowering.

Every lowered statement carries `/* @<offset> <op> */`. This script answers the
only question that matters for that claim: does every shipped instruction have
exactly one anchor, in every body?

    python3 scripts/audit_anchor_coverage.py \
        --ir crates/core/src/generated/full_ir.json --gen c-recon/gen

Exit codes: 0 = coverage is exactly 100% for every body, 1 = mismatch.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from pathlib import Path

ANCHOR = re.compile(r"/\* @(\d+) ")


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--ir", default="crates/core/src/generated/full_ir.json")
    ap.add_argument("--gen", default="c-recon/gen")
    ap.add_argument("--verbose", action="store_true", help="list every body that differs")
    a = ap.parse_args()

    ir_path = Path(a.ir)
    bundle = json.loads(ir_path.read_text())
    gen = Path(a.gen)

    total_ins = total_anchor = 0
    missing_file: list[int] = []
    per_body: list[tuple[int, int, int]] = []  # code, instructions, anchors
    duplicate_offsets: list[tuple[int, int]] = []

    for code in bundle["codes"]:
        cid = code["id"]
        n_ins = len(code["instructions"])
        src = gen / f"gml_{cid:04d}.c"
        if not src.is_file():
            missing_file.append(cid)
            continue
        offsets = [int(m) for m in ANCHOR.findall(src.read_text(encoding="utf-8", errors="ignore"))]
        total_ins += n_ins
        total_anchor += len(offsets)
        if len(offsets) != len(set(offsets)):
            duplicate_offsets.append((cid, len(offsets) - len(set(offsets))))
        per_body.append((cid, n_ins, len(offsets)))

    bad = [row for row in per_body if row[1] != row[2]]
    print(
        "BINDING v1 ir_sha256=%s gen_digest=%s bodies=%d"
        % (
            sha256(ir_path),
            hashlib.sha256(
                b"".join(str(c).encode() + sha256(gen / f"gml_{c:04d}.c").encode()
                         for c, _, _ in per_body)
            ).hexdigest(),
            len(per_body),
        )
    )
    print("instructions=%d anchors=%d coverage=%.2f%%" % (
        total_ins, total_anchor, 100.0 * total_anchor / max(total_ins, 1)))
    print("bodies with a mismatch: %d | missing files: %d | duplicate-offset bodies: %d"
          % (len(bad), len(missing_file), len(duplicate_offsets)))
    if a.verbose:
        for cid, n_ins, n_anchor in bad:
            print("  CODE %d: instructions=%d anchors=%d" % (cid, n_ins, n_anchor))
        for cid in missing_file:
            print("  CODE %d: no generated file" % cid)

    ok = not bad and not missing_file and total_ins == total_anchor
    print("RESULT %s" % ("EXACT" if ok else "MISMATCH"))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
