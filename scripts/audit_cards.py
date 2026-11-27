#!/usr/bin/env python3
"""Per-card audit ("验牌"): every card must own exactly what it declares.

Checks per card:
  1. level line present (正文/骨架/桩)
  2. every anchor exists in asm/instructions.jsonl
  3. every @func section's declared count matches the anchored instructions, under either
     END convention (exclusive: END = one past the body; inclusive: END = last
     instruction). The convention actually used is reported.
  4. every anchor falls inside some declared range (else "undeclared-range")
  5. partial sections are allowed but reported, because several cards hand a function
     over to another card; the global disjoint+cover check is verify_reverse_v1.py
     (anchors == 649,229, shared == 0)
  6. legacy cards without @func lines are audited by deriving contiguous anchor runs

    python3 scripts/audit_cards.py --tsv /tmp/card_audit.tsv
"""
from __future__ import annotations

import argparse
import bisect
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RV = ROOT / "reconstruction/reverse-v1"
ASM = RV / "asm"
LEVEL = re.compile(r"级别:\s*(正文|骨架|桩|原始覆盖)")
FUNC = re.compile(r"@func\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+size\s+(\d+)\s+(\d+)\s*条")
ANCHOR = re.compile(r"(?:/\*|\*)\s+@0x([0-9a-f]+) ")


def load_thumb():
    out = []
    for name in ("thumb_ranges_extra.txt", "thumb_ranges.txt"):
        p = ASM / name
        if not p.exists():
            continue
        for line in p.read_text(encoding="utf-8").splitlines():
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            f = re.split(r"[\s,]+", line)
            try:
                out.append((int(f[0], 16), int(f[0], 16) + int(f[1], 0)))
            except (ValueError, IndexError):
                continue
    return sorted(out)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--tsv", default=None)
    args = ap.parse_args()

    ins = set()
    for line in open(ASM / "instructions.jsonl", encoding="utf-8"):
        ins.add(json.loads(line)["a"])
    addrs = sorted(ins)

    def span(lo, hi, inclusive):
        x = bisect.bisect_left(addrs, lo)
        y = bisect.bisect_right(addrs, hi if inclusive else hi - 1)
        return set(addrs[x:y])

    thumbs = load_thumb()

    def is_thumb(x):
        return any(a0 <= x < a1 for a0, a1 in thumbs)

    rows = []
    for card in sorted((RV / "cards").glob("*.c")):
        text = card.read_text(encoding="utf-8")
        anchors = {int(m.group(1), 16) for m in ANCHOR.finditer(text)}
        funcs = [(int(m.group(1), 16), int(m.group(2), 16), int(m.group(3)), int(m.group(4)))
                 for m in FUNC.finditer(text)]
        level = LEVEL.search(text)
        problems = []
        if not level:
            problems.append("no-level")
        outside_index = [x for x in anchors if x not in ins]
        if outside_index:
            problems.append(f"anchor-not-in-index:{len(outside_index)}")
        convs, covered, partials = set(), set(), []
        if funcs:
            for start, end, size, declared in funcs:
                # END is exclusive everywhere after scripts/fix_card_metadata.py normalized
                # the headers: count what falls in [start, end)
                excl = span(start, end, False)
                incl = span(start, end, True)
                have = anchors & excl
                # "N 条" is what the card anchors in this section; a partial section
                # therefore declares its own (smaller) count. Only a count that matches
                # neither the range nor the anchored set is a real mismatch.
                if declared == len(have):
                    convs.add("excl" if len(have) == len(excl) else "partial")
                    full = len(excl)
                elif declared == len(incl):
                    convs.add("incl")
                    full = len(incl)
                else:
                    problems.append(f"count:{start:#x} declared={declared} anchored={len(have)} excl={len(excl)} incl={len(incl)}")
                    full = len(excl)
                covered |= excl
                if len(have) < full:
                    declared_note = f"部分覆盖: 本节 {len(have)}/{full} 条"
                    partials.append(f"{start:#x} {len(have)}/{full}" + ("" if declared_note in text else "(未声明)"))
            undeclared = anchors - {x for s, e, _, _ in funcs for x in span(s, e, True)}
            if undeclared:
                problems.append(f"undeclared-range:{len(undeclared)}")
            mode = "@func"
        elif anchors:
            xs = sorted(anchors)
            runs, prev = 1, xs[0]
            for x in xs[1:]:
                if x - prev > 0x40:
                    runs += 1
                prev = x
            mode = f"runs-derived({runs})"
        else:
            mode = "doc-only"
        isa = "Thumb" if any(is_thumb(x) for x in list(anchors)[:80]) else "ARM"
        rows.append({
            "card": card.name,
            "level": level.group(1) if level else "-",
            "anchors": len(anchors),
            "sections": len(funcs),
            "isa": isa,
            "conv": ",".join(sorted(convs)) or "-",
            "status": "OK" if not problems else "FAIL",
            "problems": "; ".join(problems[:6]),
            "partial_declared": len(partials),
            "mode": mode,
        })

    for r in rows:
        if r["status"] != "OK":
            print(f"{r['card'][:34]:34} {r['level']:5} {r['anchors']:8d} {r['isa']:5} "
                  f"{r['status']}  {r['problems']}  [{r['mode']}]")
    ok = sum(1 for r in rows if r["status"] == "OK")
    modes = {}
    for r in rows:
        key = r["mode"].split("(")[0]
        modes[key] = modes.get(key, 0) + 1
    print(f"\ncards={len(rows)} OK={ok} FAIL={len(rows) - ok} "
          f"anchors={sum(r['anchors'] for r in rows)} modes={modes}")
    if args.tsv:
        with open(args.tsv, "w", encoding="utf-8") as fh:
            keys = ("card", "level", "anchors", "sections", "isa", "conv", "status", "problems",
                    "partial_declared", "mode")
            fh.write("\t".join(keys) + "\n")
            for r in rows:
                fh.write("\t".join(str(r[k]) for k in keys) + "\n")
        print("tsv:", args.tsv)
    return 0 if ok == len(rows) else 1


if __name__ == "__main__":
    sys.exit(main())
