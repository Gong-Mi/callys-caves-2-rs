#!/usr/bin/env python3
"""Audit the 118-body Draw differential census without hiding empty outcomes.

Recalculate with:
    python3 scripts/batch_diff.py --c-bin <state_dump> --sequence --all-objects \
        --code-file <draw-code-ids> --work <work>
    python3 scripts/draw_corpus_summary.py --work <work>

The constants are a regression baseline for the current generic fixtures, not
original-runner equivalence. SAME_ABORT and an empty command stream stay separate
from a body that emitted commands. No report is written into a scanned input.
"""
from __future__ import annotations

import argparse
import json
import re
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
EXPECTED = {
    "bodies": 118,
    "with_commands": 113,
    "no_commands": 4,
    "same_abort": 1,
    "no_command_ids": {374, 539, 555, 716},
    "abort_ids": {370},
    "commands": Counter({"SPRITE": 142, "TEXT": 110, "BACKGROUND": 1, "HEALTHBAR": 0}),
}


def validate(summary: dict) -> list[str]:
    errors = []
    for key in ("bodies", "with_commands", "no_commands", "same_abort"):
        if summary.get(key) != EXPECTED[key]:
            errors.append(f"{key}={summary.get(key)!r}, want {EXPECTED[key]!r}")
    for key in ("no_command_ids", "abort_ids"):
        if summary.get(key) != EXPECTED[key]:
            errors.append(f"{key}={sorted(summary.get(key, ()))}, want {sorted(EXPECTED[key])}")
    commands = summary.get("commands", Counter())
    for kind in ("SPRITE", "TEXT", "BACKGROUND", "HEALTHBAR"):
        if commands.get(kind, 0) != EXPECTED["commands"][kind]:
            errors.append(f"{kind}={commands.get(kind, 0)}, want {EXPECTED['commands'][kind]}")
    if summary.get("unequal"):
        errors.append(f"unequal files={summary['unequal']}")
    if summary.get("unexpected_files"):
        errors.append(f"unexpected_files={summary['unexpected_files']}")
    return errors


def abort_reason(text: str) -> str:
    value = text.strip()
    if value.startswith("ERROR"):
        value = value[5:].lstrip()
    value = re.sub(r"^CODE \d+\s*(?:@0x[0-9a-f]+)?:?\s*", "", value)
    return re.sub(r"\s*(?:@0x[0-9a-f]+|offset=\d+)", "", value).strip()


def summarize(work: Path) -> dict:
    bundle = json.loads((ROOT / "crates/core/src/generated/full_ir.json").read_text())
    ids = sorted({code for obj in bundle["objects"] for event in obj["events"]
                  if event["event_type"] == 8 for code in event["codes"]})
    expected_files = {f"{code}.v0.txt" for code in ids}
    summary = {
        "bodies": len(ids), "with_commands": 0, "no_commands": 0, "same_abort": 0,
        "no_command_ids": set(), "abort_ids": set(), "commands": Counter(),
        "unequal": [], "unexpected_files": [],
    }
    for side in ("rust", "c"):
        actual = {p.name for p in (work / side).glob("*.txt")}
        summary["unexpected_files"] += [f"{side}/{name}" for name in sorted(actual - expected_files)]
    for code in ids:
        name = f"{code}.v0.txt"
        rp, cp = work / "rust" / name, work / "c" / name
        if not rp.is_file() or not cp.is_file():
            summary["unequal"].append(f"missing:{name}")
            continue
        rt, ct = rp.read_text(), cp.read_text()
        same_abort = (rt.startswith("ERROR") and ct.startswith("ERROR")
                      and abort_reason(rt) == abort_reason(ct))
        if rt != ct and not same_abort:
            summary["unequal"].append(name)
            continue
        lines = [line for line in rt.splitlines() if line.startswith("DRAW ")]
        if same_abort:
            summary["same_abort"] += 1
            summary["abort_ids"].add(code)
        elif lines:
            summary["with_commands"] += 1
            for line in lines:
                fields = line.split()
                if len(fields) < 3:
                    summary["unequal"].append(f"malformed:{name}")
                else:
                    summary["commands"][fields[2]] += 1
        else:
            summary["no_commands"] += 1
            summary["no_command_ids"].add(code)
    return summary


def self_test() -> None:
    clean = {key: (Counter(value) if isinstance(value, Counter) else
                   set(value) if isinstance(value, set) else value)
             for key, value in EXPECTED.items()}
    clean["unequal"] = []
    clean["unexpected_files"] = []
    assert not validate(clean), validate(clean)
    mutations = []
    for key in ("bodies", "with_commands", "no_commands", "same_abort"):
        bad = dict(clean)
        bad[key] = clean[key] + 1
        mutations.append(bad)
    for key in ("no_command_ids", "abort_ids"):
        bad = dict(clean)
        bad[key] = set()
        mutations.append(bad)
    bad = dict(clean)
    bad["commands"] = Counter(clean["commands"])
    bad["commands"]["SPRITE"] -= 1
    mutations.append(bad)
    bad = dict(clean)
    bad["unequal"] = ["18.v0.txt"]
    mutations.append(bad)
    for index, bad in enumerate(mutations):
        assert validate(bad), f"negative control {index} stayed green"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--work", type=Path, required=True)
    args = ap.parse_args()
    self_test()
    summary = summarize(args.work)
    errors = validate(summary)
    counts = ", ".join(f"{kind}={summary['commands'][kind]}"
                       for kind in ("SPRITE", "TEXT", "BACKGROUND", "HEALTHBAR"))
    print(f"[draw] bodies={summary['bodies']} with_commands={summary['with_commands']} "
          f"no_commands={summary['no_commands']} same_abort={summary['same_abort']} "
          f"commands={sum(summary['commands'].values())} ({counts})")
    print(f"[draw] no_command_ids={sorted(summary['no_command_ids'])} "
          f"abort_ids={sorted(summary['abort_ids'])}; C==VM command-stream census, "
          "not original-runner equivalence")
    print("[draw] negative controls: PASS")
    for error in errors:
        print(f"[draw] FAIL {error}")
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
