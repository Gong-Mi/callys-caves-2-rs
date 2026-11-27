#!/usr/bin/env python3
"""Merge overlapping @func sections inside a card so its counts can reconcile.

Why: a card that keeps several @func ranges for the same function (or whose sections
overlap each other) cannot declare a per-section count that survives an audit — the same
address falls in two of its own sections. Merging those sections into one @func per
function makes "declared条数 == 本卡在该范围里锚的条数" true by construction.

Coarser, not stronger: one merged section says "this card owns these addresses in this
span", and the note records how much of the span belongs to other cards. No anchor is
added or removed.

    python3 scripts/merge_overlapping_sections.py --cards Residue_Attributed_01.c ... [--apply]
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


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--cards", nargs="+", required=True)
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args()

    ins = set()
    for line in open(ASM / "instructions.jsonl", encoding="utf-8"):
        ins.add(json.loads(line)["a"])
    addrs = sorted(ins)
    fns = []
    for line in (ASM / "functions.tsv").read_text(encoding="utf-8").splitlines():
        c = line.split("\t")
        if len(c) >= 3:
            fns.append((int(c[0], 16), int(c[1]), c[2]))
    fns.sort()

    def owner_fn(x):
        i = bisect.bisect_right([f[0] for f in fns], x) - 1
        if i < 0:
            return None
        s, size, name = fns[i]
        return (s, name) if s <= x < s + size else None

    def span(lo, hi):
        x = bisect.bisect_left(addrs, lo)
        y = bisect.bisect_right(addrs, hi)
        return set(addrs[x:y])

    for name in a.cards:
        p = RV / "cards" / name
        if not p.exists():
            print("missing", name)
            continue
        text = p.read_text(encoding="utf-8")
        ms = list(FUNC.finditer(text))
        if len(ms) < 2:
            print("skip (single section)", name)
            continue
        sections = [(int(m.group(1), 16), int(m.group(2), 16), m) for m in ms]
        sections.sort()
        # merge only sections that belong to the SAME function (touching addresses in a
        # bulk card are usually two different functions laid out next to each other)
        clusters, cur = [], [sections[0]]
        for s in sections[1:]:
            if owner_fn(s[0]) == owner_fn(cur[0][0]) and s[0] <= cur[-1][1]:
                cur.append(s)
            else:
                clusters.append(cur)
                cur = [s]
        clusters.append(cur)
        if len(clusters) == len(sections):
            print("skip (no overlap)", name)
            continue
        anchors = {int(m.group(1), 16) for m in ANCHOR.finditer(text)}
        new_text = text
        notes = []
        for cl in clusters:
            if len(cl) == 1:
                continue
            lo, hi = min(s[0] for s in cl), max(s[1] for s in cl)
            owned = set().union(*[span(s0, s1) for s0, s1, _ in cl])
            n = len(anchors & owned)
            first_old = cl[0][2].group(0)
            new_line = f"@func 0x{lo:x} 0x{hi:x}  size {hi - lo}  {n} 条"
            # drop the other section headers of this cluster
            for s0, s1, m in cl[1:]:
                new_text = new_text.replace(m.group(0) + "\n", "", 1)
            new_text = new_text.replace(first_old, new_line, 1)
            notes.append((new_line, n, len(span(lo, hi))))
        for line, n, full in notes:
            note = f" * 合并节: 本节 {n}/{full} 条（同一函数的多个 @func 已并成一段，范围内其余地址归其它卡）"
            if note.split(":")[0] not in new_text:
                new_text = new_text.replace(line + "\n", line + "\n" + note + "\n", 1)
        print(f"{'MERGED' if a.apply else 'WOULD MERGE'} {name}: {len(sections)} sections -> {len(clusters)} clusters")
        if a.apply:
            p.write_text(new_text, encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
