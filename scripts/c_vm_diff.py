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
import hashlib
import json
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


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def binding_line(code: int, fixture_text: str) -> str:
    """Identity of everything this result depends on (see AGENTS.md §3).

    A passing diff without this line only says "it matched once". With it, the
    result is void the moment the body, the fixture or the lowered C changes.
    """
    ir = json.loads(IR.read_text())
    body = next((c for c in ir["codes"] if c["id"] == code), None)
    body_sha = body["sha256"] if body else "absent"
    src = ROOT / f"c-recon/gen/gml_{code:04d}.c"
    impl_sha = sha256_bytes(src.read_bytes()) if src.exists() else "absent"
    impl = str(src.relative_to(ROOT)) if src.exists() else "absent"
    return (
        f"BINDING v1 code={code} body_sha256={body_sha} "
        f"fixture_sha256={sha256_bytes(fixture_text.encode())} "
        f"impl={impl} impl_sha256={impl_sha}"
    )


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
    print(binding_line(a.code, text))

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
