#!/usr/bin/env python3
"""What the test suites actually EXECUTE, per CODE body.

`code_vm::coverage` appends one CODE id per VM entry when `CALLY_CODE_TRACE` is
set, so a body a suite drives end to end stops reading as "no evidence" in the
citation census. This reads that ledger and cross-tabs it against the census:

    CALLY_CODE_TRACE=/tmp/trace.txt cargo test -p callys-client --test <suite>
    python3 scripts/code_trace_report.py /tmp/trace.txt

The output separates three different things that are easy to conflate:
  * executed at all (this run),
  * inside the 62 `with`-pending CODEs,
  * in the census's `structural` tier (never cited anywhere).
An execution is evidence that the body ran under a test; it is NOT a claim that
its behaviour matches the original.
"""
import collections
import json
import os
import sys

LEDGER = os.path.expanduser("~/cally-cfg-evidence-ci-44a33c0/progress.tsv")
CENSUS = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                      "reconstruction", "contracts", "semantic-coverage.md")


def read_trace(path):
    if not os.path.exists(path):
        raise SystemExit(f"trace file {path} does not exist")
    ids = []
    with open(path, encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if line.isdigit():
                ids.append(int(line))
    return ids


def pending_codes():
    if not os.path.exists(LEDGER):
        return {}
    with open(LEDGER, encoding="utf-8") as fh:
        rows = [l.rstrip("\n").split("\t") for l in fh if l.strip()]
    header, body = rows[0], rows[1:]
    i = {c: k for k, c in enumerate(header)}
    return {int(r[i["code_id"]]): int(r[i["environment_ops_pending"]])
            for r in body if int(r[i["environment_ops_pending"]]) > 0}


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    ids = read_trace(sys.argv[1])
    distinct = sorted(set(ids))
    print(f"trace: {len(ids)} entries, {len(distinct)} distinct CODE bodies executed")
    counts = collections.Counter(ids)
    hottest = counts.most_common(5)
    print("hottest bodies: " + ", ".join(f"CODE {c} x{n}" for c, n in hottest))

    pend = pending_codes()
    if pend:
        ran = [c for c in distinct if c in pend]
        print(f"of the {len(pend)} with-pending CODEs, {len(ran)} executed: {sorted(ran)[:12]}"
              + (" ..." if len(ran) > 12 else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
