#!/usr/bin/env python3
"""Scan full_ir.json for point-writes (assignments to another instance).

The IR encodes a write to an instance held in a local as:

    <value>            # any expression, ending with a value on the stack
    load  <var>        # the target instance id
    cast  to=2         # instance-id cast
    constant <index>   # ONLY for array stores
    store name=<field> [array=1]

so the target is the *variable*, not the `other` bool and not `selector`
(with blocks write through selector=-1 inside pushenv/popenv). Scanning by
`selector == 0` or by `other == true` silently misses writes; this script
exists so that scan never has to be hand-written again.

Usage:
  python3 scripts/scan_point_writes.py --var hittrex
  python3 scripts/scan_point_writes.py --field alarm --index 6
  python3 scripts/scan_point_writes.py --gate poisonenabled
  python3 scripts/scan_point_writes.py --var hittrex --field alarm --index 6 --gate poisonenabled

Columns: code, name, instr, var, field, index, gate
"""
import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_IR = ROOT / "crates/core/src/generated/full_ir.json"


def point_writes(ir_path):
    data = json.loads(Path(ir_path).read_text())
    for c in data["codes"]:
        ins = c["instructions"]
        for i, x in enumerate(ins):
            if x.get("op") != "store":
                continue
            j = i - 1
            idx = None
            if x.get("array"):
                if j < 0 or ins[j].get("op") != "constant":
                    continue
                idx = ins[j].get("value")
                j -= 1
            # Exactly two shapes reach the store:
            #   plain    : load var; cast to=2; store
            #   compound : load var; cast to=2; dup; <value expr>; store
            #              (dest under the value, e.g. `hp -= dmg`)
            var = None
            if j >= 1 and ins[j].get("op") == "cast" and ins[j].get("to") == 2 \
                    and ins[j - 1].get("op") == "load":
                var = ins[j - 1].get("name")
            else:
                k = i - 1
                while k >= 0 and (i - k) <= 6 and ins[k].get("op") != "dup":
                    k -= 1
                if k >= 2 and ins[k].get("op") == "dup" \
                        and ins[k - 1].get("op") == "cast" and ins[k - 1].get("to") == 2 \
                        and ins[k - 2].get("op") == "load":
                    var = ins[k - 2].get("name")
            if var is None:
                continue
            yield c, i, var, x.get("name"), idx, ins


def gate_of(ins, i, gate_name, window=20):
    """Nearest load of `gate_name` before the store.

    The guard shape is `load gate; constant N; cmp; bf skip; ... store`, so the
    load sits *past* the branch from the store's point of view: allow exactly
    one branch crossing and return "distance/branch" instead of giving up.
    """
    branches = 0
    for k in range(i - 1, max(-1, i - window), -1):
        x = ins[k]
        if x.get("op") == "load" and x.get("name") == gate_name:
            return f"{i - k}/{'bf' if branches else 'plain'}"
        if x.get("op") in ("bf", "b", "bt"):
            branches += 1
            if branches > 1:
                return None
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--ir", default=str(DEFAULT_IR))
    ap.add_argument("--var", default="", help="only writes whose target variable matches")
    ap.add_argument("--field", default="", help="only this field name")
    ap.add_argument("--index", type=int, default=None, help="array index (needs --field)")
    ap.add_argument("--gate", default="", help="report the distance to this global load")
    ap.add_argument("--summary", action="store_true", help="print counts only")
    args = ap.parse_args()

    rows = []
    for c, i, var, field, idx, ins in point_writes(args.ir):
        if args.var and var != args.var:
            continue
        if args.field and field != args.field:
            continue
        if args.index is not None and idx != args.index:
            continue
        gate = gate_of(ins, i, args.gate) if args.gate else ""
        rows.append((c["id"], c["name"], i, var, field, "" if idx is None else idx, gate))

    if args.summary:
        print(f"{len(rows)} point-writes match")
        by_field = {}
        for r in rows:
            by_field.setdefault((r[4], r[5]), 0)
            by_field[(r[4], r[5])] += 1
        for (f, idx), n in sorted(by_field.items()):
            print(f"  {f}{f'[{idx}]' if idx != '' else ''}: {n}")
        return 0

    print("code\tname\tinstr\tvar\tfield\tindex\tgate")
    for r in rows:
        print("\t".join(str(x) for x in r))
    return 0


if __name__ == "__main__":
    sys.exit(main())
