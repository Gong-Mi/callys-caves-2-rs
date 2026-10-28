#!/usr/bin/env python3
"""Verify every reverse-engineering card against the whole-binary instruction index.

Per-card checks (`check_card_anchors.py`) trust a per-card index file, which the
card author also generated — a single source of truth is better. This script
checks all cards at once against asm/instructions.jsonl(.xz), the census output,
and also reports:

    · per card: anchors / level / EXACT vs the global index
    · cross-card: any address claimed by two cards (aliasing bug)
    · claims: merged status counts from claims*.jsonl

    python3 scripts/verify_reverse_v1.py
"""
from __future__ import annotations

import argparse
import collections
import json
import lzma
import re
import sys
from pathlib import Path

# cards write anchors either as "/* @0x... mnem" or, inside a block comment, "* @0x... mnem"
ANCHOR = re.compile(r"(?:/\*|\*)\s+@0x([0-9a-f]+) ([A-Za-z.][A-Za-z0-9_.]*)")
LEVEL = re.compile(r"级别:\s*(正文|骨架|桩|原始覆盖)")
FUNC = re.compile(r"@func\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)")


def load_index(asm: Path) -> dict[int, str]:
    plain = asm / "instructions.jsonl"
    if plain.exists():
        fh = open(plain, encoding="utf-8")
        closer = fh.close
    else:
        fh = lzma.open(asm / "instructions.jsonl.xz", "rt", encoding="utf-8")
        closer = fh.close
    try:
        return {json.loads(line)["a"]: json.loads(line)["m"] for line in fh}
    finally:
        closer()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="reconstruction/reverse-v1")
    ap.add_argument("--strict", action="store_true", help="exit 1 if any card is not EXACT")
    a = ap.parse_args()

    root = Path(a.root)
    asm, cards = root / "asm", root / "cards"
    index = load_index(asm)

    owners: dict[int, list[str]] = collections.defaultdict(list)
    rows = []
    for card in sorted(cards.glob("*.c")):
        text = card.read_text(encoding="utf-8")
        found = {(int(m.group(1), 16), m.group(2)) for m in ANCHOR.finditer(text)}
        level = LEVEL.search(text)
        span = FUNC.search(text)
        bad = [addr for addr, mnem in found if index.get(addr) != mnem]
        for addr, _ in found:
            owners[addr].append(card.stem)
        rows.append({
            "card": card.stem,
            "level": level.group(1) if level else "-",
            "anchors": len(found),
            "span": f"{span.group(1)}..{span.group(2)}" if span else "-",
            "wrong": len(bad),
        })

    shared = {addr: names for addr, names in owners.items() if len(names) > 1}

    print(f"{'card':22} {'level':6} {'anchors':>7}  {'range':>19}  status")
    for r in sorted(rows, key=lambda r: r["card"]):
        status = "EXACT" if r["wrong"] == 0 else f"{r['wrong']} WRONG"
        print(f"{r['card']:22} {r['level']:6} {r['anchors']:7d}  {r['span']:>19}  {status}")
    print(f"\ncards={len(rows)} anchors={sum(r['anchors'] for r in rows)} "
          f"addresses_claimed_by_two_cards={len(shared)}")
    for addr, names in list(shared.items())[:5]:
        print(f"  shared {addr:#x}: {', '.join(names)}")

    claims = collections.Counter()
    ids: dict[str, str] = {}
    for f in sorted(root.glob("claims*.jsonl")):
        for line in f.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            row = json.loads(line)
            ids[row["id"]] = row.get("status", "?")
    for status in ids.values():
        claims[status] += 1
    print(f"claims={len(ids)} " + " ".join(f"{k}={v}" for k, v in sorted(claims.items())))
    missing_card = [i for i, s in ids.items() if s != "open" and not any(
        json.loads(l).get("id") == i and json.loads(l).get("card") for f in root.glob("claims*.jsonl")
        for l in f.read_text(encoding="utf-8").splitlines() if l.strip())]
    if missing_card:
        print(f"claims without a card reference: {missing_card[:5]}")

    incomplete = [r for r in rows if r["wrong"]]
    return 1 if (a.strict and incomplete) else 0


if __name__ == "__main__":
    sys.exit(main())
