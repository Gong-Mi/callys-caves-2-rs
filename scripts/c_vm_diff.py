#!/usr/bin/env python3
"""Differential harness: lowered C vs the Rust interpreter, same fixture.

Both sides speak the state-file protocol documented in c-recon/src/main.c. This
script runs one CODE body through both and diffs the resulting state, so a
generator bug shows up as a concrete state difference instead of a passing
suite.

    python3 scripts/c_vm_diff.py --fixture fx.txt --code 792 [--keep]

Exit codes: 0 identical, 1 different, 2 harness failure.
"""
from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
C_BIN = ROOT / "c-recon/build/state_dump"
IR = ROOT / "crates/core/src/generated/full_ir.json"


def run(cmd: list[str], cwd: Path) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, cwd=cwd, text=True,
                          stdout=subprocess.PIPE, stderr=subprocess.STDOUT)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--fixture", required=True, type=Path)
    ap.add_argument("--code", required=True, type=int)
    ap.add_argument("--keep", action="store_true", help="keep the temp files")
    a = ap.parse_args()

    if not C_BIN.exists():
        print(f"missing {C_BIN}; build it first (see c-recon/README.md)", file=sys.stderr)
        return 2
    fixture = a.fixture.resolve()
    text = fixture.read_text()
    if not text.startswith("CODE "):
        text = f"CODE {a.code}\n" + text
    fixture = Path(tempfile.mkstemp(suffix=".fx")[1])
    fixture.write_text(text)

    c_out = fixture.with_suffix(".c.out")
    r_out = fixture.with_suffix(".r.out")

    p = run([str(C_BIN), str(fixture), str(c_out)], ROOT)
    if p.returncode != 0:
        print("C side failed:\n" + p.stdout, file=sys.stderr)
        return 2
    p = run(["cargo", "run", "-q", "--profile", "ci-test", "-p", "callys-core",
             "--example", "ir_state_dump", "--",
             "--ir", str(IR), "--state", str(fixture), "--out", str(r_out)], ROOT)
    if p.returncode != 0:
        print("Rust side failed:\n" + p.stdout, file=sys.stderr)
        return 2

    d = run(["diff", "-u", str(r_out), str(c_out)], ROOT)
    if d.returncode == 0:
        print(f"CODE {a.code}: IDENTICAL ({len(c_out.read_text().splitlines())} state lines)")
        rc = 0
    else:
        print(d.stdout)
        rc = 1
    if not a.keep:
        for f in (fixture, c_out, r_out):
            f.unlink(missing_ok=True)
    return rc


if __name__ == "__main__":
    sys.exit(main())
