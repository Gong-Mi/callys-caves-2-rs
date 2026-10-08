#!/usr/bin/env python3
"""Regenerate the semantic-coverage census with the FULL-SUITE execution ledger.

Why a dedup ledger: code_vm::coverage appends one line per VM entry, so the raw
run is 3.45M entries / 11 MB / 1187 distinct ids. The census only consumes the
SET of executed ids (`executed` flag per body), so the repo keeps the deduped
list and the raw counts live in the regeneration command below.

Full rebuild pipeline (from a compiled tree):
    python3 scripts/run_exec_ledger.py                       # all test binaries, one shared ledger
    python3 scripts/regen_coverage_with_exec_ledger.py       # dedup + census --md

Run this to refresh both artifacts in one go:
    python3 scripts/regen_coverage_with_exec_ledger.py
"""
import os, json, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW = os.path.join(ROOT, "reconstruction/live-mem/trace/cally-code-trace-full-ledger.txt")
DEDUP = os.path.join(ROOT, "reconstruction/live-mem/trace/cally-code-trace-full-dedup.txt")
LEDGER = os.path.expanduser("~/cally-cfg-evidence-ci-44a33c0/progress.tsv")

def main() -> int:
    if not os.path.exists(RAW):
        raise SystemExit(f"{RAW} missing: run scripts/run_exec_ledger.py first")
    ids = set()
    entries = 0
    with open(RAW, encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if line.isdigit():
                entries += 1
                ids.add(int(line))
    # Guard: the ledger must hold shipped CODE bodies only. Fixture-only suites
    # are isolated by run_exec_ledger.py; anything outside the bundle's code set
    # is still reported and kept out of the dedup rather than counted as an
    # execution of some body.
    with open(os.path.join(ROOT, "crates/core/src/generated/full_ir.json"),
              encoding="utf-8") as fh:
        bundle_ids = {int(c["id"]) for c in json.load(fh)["codes"]}
    strays = sorted(i for i in ids if i not in bundle_ids)
    if strays:
        ids -= set(strays)
        print(f"WARNING: excluded {len(strays)} non-bundle ids from the dedup: {strays}")
    tmp = DEDUP + ".tmp"
    with open(tmp, "w", encoding="utf-8") as fh:
        fh.write("\n".join(str(i) for i in sorted(ids)) + "\n")
    os.replace(tmp, DEDUP)
    print(f"raw entries {entries}, distinct {len(ids)} -> {DEDUP}")
    cmd = [sys.executable, os.path.join(ROOT, "scripts/audit_semantic_coverage.py"),
           "--ledger", LEDGER, "--exec-trace", DEDUP,
           "--md", os.path.join(ROOT, "reconstruction/contracts/semantic-coverage.md")]
    r = subprocess.run(cmd, cwd=ROOT)
    return r.returncode

if __name__ == "__main__":
    sys.exit(main())
