#!/usr/bin/env python3
"""Build the internal call graph of libyoyo.so and rank what to reverse next.

Coverage of ".text" is not the same as understanding it: what matters is which
functions the ones we have already carded depend on. This script resolves every
`bl`/`blx <imm>` target to its owning function and ranks callees of the carded
set that still have no card.

    python3 scripts/call_graph.py --root reconstruction/reverse-v1
"""
from __future__ import annotations

import argparse
import collections
import json
import lzma
import re
import sys
from pathlib import Path

BL = re.compile(r"^(?:0x([0-9a-f]+)|([0-9a-f]+))\s*<")


def open_insns(asm: Path):
    plain = asm / "instructions.jsonl"
    if plain.exists():
        return open(plain, encoding="utf-8")
    return lzma.open(asm / "instructions.jsonl.xz", "rt", encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="reconstruction/reverse-v1")
    ap.add_argument("--top", type=int, default=30)
    a = ap.parse_args()

    root = Path(a.root)
    asm = root / "asm"

    spans: list[tuple[int, int, str]] = []
    for line in (asm / "functions.tsv").read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        addr, size, dem, mangled, _first, _last, _n = line.split("\t")
        spans.append((int(addr, 16), int(size), dem.split("(")[0]))
    spans.sort()

    starts = {addr for addr, _s, _n in spans}

    def owner(addr: int) -> str | None:
        for start, size, name in spans:
            if start <= addr < start + size:
                return name
            if start > addr:
                break
        return None

    edges: collections.Counter[tuple[str, str]] = collections.Counter()
    with open_insns(asm) as fh:
        for line in fh:
            row = json.loads(line)
            if row["m"] not in ("bl", "blx"):
                continue
            m = BL.match(row["o"])
            if not m:
                continue
            target = int(m.group(1) or m.group(2), 16)
            src = owner(row["a"])
            dst = owner(target)
            if src and dst and src != dst:
                edges[(src, dst)] += 1

    carded = {p.stem for p in (root / "cards").glob("*.c")}
    callees = collections.Counter()
    for (src, dst), n in edges.items():
        if src in carded and dst not in carded:
            callees[dst] += n

    print(f"边 {len(edges)} 条；已出卡函数 {len(carded)} 个")
    print(f"\n已出卡函数调用、但尚未出卡的最大 {a.top} 个目标：")
    for dst, n in callees.most_common(a.top):
        size = next((s for st, s, nm in spans if nm == dst and st in starts), 0)
        print(f"  {n:4d} 次  {size:6d} B  {dst}")
    print(f"\n合计未覆盖被调方 {len(callees)} 个，调用次数 {sum(callees.values())}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
