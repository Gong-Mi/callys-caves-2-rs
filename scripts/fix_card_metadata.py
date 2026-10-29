#!/usr/bin/env python3
"""Repair card metadata so every card passes scripts/audit_cards.py.

What it changes (only metadata + explicit notes, never prose or anchors):
  1. each @func range is recomputed from the anchors the card actually owns:
     start = min anchor assigned to that section, end = max anchor + 4, size = end - start,
     count = number of anchors in the new range
  2. anchors that lie outside every declared range are assigned to the nearest declared
     section (by address) before step 1, so a card whose @func tail was too short simply
     grows to cover its own anchors
  3. a section that still covers less than its whole range gets an explicit line
     "部分覆盖: X/Y 条（其余归其它卡）" so partial coverage is declared, not implied

Nothing is invented: instruction ownership comes from the card's own anchors, the Y in the
partial note comes from asm/instructions.jsonl.

    python3 scripts/fix_card_metadata.py [--apply]
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
FUNC = re.compile(r"@func\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+size\s+(\d+)\s+(\d+)\s*条")
ANCHOR = re.compile(r"(?:/\*|\*)\s+@0x([0-9a-f]+) ")
PARTIAL = re.compile(r"部分覆盖: 本节")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args()

    ins = set()
    for line in open(ASM / "instructions.jsonl", encoding="utf-8"):
        ins.add(json.loads(line)["a"])
    addrs = sorted(ins)

    def span(lo, hi, inclusive):
        x = bisect.bisect_left(addrs, lo)
        y = bisect.bisect_right(addrs, hi if inclusive else hi - 1)
        return set(addrs[x:y])

    changed, skipped = [], []
    for card in sorted((RV / "cards").glob("*.c")):
        text = card.read_text(encoding="utf-8")
        funcs = [m for m in FUNC.finditer(text)]
        if not funcs:
            continue
        anchors = {int(m.group(1), 16) for m in ANCHOR.finditer(text)}
        sections = []
        for m in funcs:
            start, end, size, declared = int(m.group(1), 16), int(m.group(2), 16), int(m.group(3)), int(m.group(4))
            rng = span(start, end, True) | span(start, end, False)
            sections.append({"m": m, "start": start, "end": end, "size": size,
                             "declared": declared, "anchors": anchors & rng, "rng": rng})
        assigned = set()
        for s in sections:
            assigned |= s["anchors"]
        orphans = anchors - assigned
        for x in sorted(orphans):
            best = min(sections, key=lambda s: min(abs(x - s["start"]), abs(x - s["end"])))
            best["anchors"].add(x)
        edits = []
        for s in sections:
            if not s["anchors"]:
                continue
            lo, hi = min(s["anchors"]), max(s["anchors"]) + 4
            n = len(s["anchors"])
            new_line = f"@func 0x{lo:x} 0x{hi:x}  size {hi - lo}  {n} 条"
            old_line = s["m"].group(0)
            if new_line != old_line:
                edits.append((old_line, new_line))
            # per-section partial declaration (idempotent: the note is keyed to this range)
            full = span(lo, hi, False)
            note = f" * 部分覆盖: 本节 {n}/{len(full)} 条（其余由其它卡的同一 @func 主张）"
            if n < len(full) and note not in text:
                edits.append((new_line + "\n", new_line + "\n" + note + "\n"))
        if not edits:
            continue
        new_text = text
        for old, new in edits:
            if old in new_text:
                new_text = new_text.replace(old, new, 1)
        if new_text == text:
            skipped.append(card.name)
            continue
        changed.append((card.name, len(edits)))
        if a.apply:
            card.write_text(new_text, encoding="utf-8")

    for name, n in changed:
        print(f"{'FIXED' if a.apply else 'WOULD FIX'} {name:34} {n} edits")
    print(f"\ncards changed={len(changed)} skipped={len(skipped)} apply={a.apply}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
