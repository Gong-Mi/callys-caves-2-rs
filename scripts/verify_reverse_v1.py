#!/usr/bin/env python3
"""Verify every reverse-engineering card against the whole-binary instruction index.

Per-card checks (`check_card_anchors.py`) trust a per-card index file, which the
card author also generated — a single source of truth is better. This script
checks all cards at once against asm/instructions.jsonl(.xz), the census output,
and also reports:

    · per card: anchors / level / EXACT vs the global index
    · cross-card: any address claimed by two cards (aliasing bug)
    · claims: merged status counts from claims*.jsonl

Use --strict to require that every census address has one card owner, all
recognized anchors agree on the mnemonic, and a card declaring functions is
not entirely anchorless. Operand checking is per-card via
check_card_anchors.py; this is not a native C++ or behavior verification.

    python3 scripts/verify_reverse_v1.py --strict
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
ANCHOR = re.compile(r"(?:/\*|\*)[ \t]+@0x([0-9a-fA-F]+)[ \t]+([A-Za-z.][A-Za-z0-9_.]*)(?=[ \t\r\n]|\*/|$)")
LEVEL = re.compile(r"级别:\s*(正文|骨架|桩|原始覆盖)")
FUNC = re.compile(r"@func\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)")


def load_index(asm: Path) -> dict[int, str]:
    path = asm / "instructions.jsonl"
    if not path.exists():
        path = asm / "instructions.jsonl.xz"
    opener = lzma.open if path.suffix == ".xz" else open
    index: dict[int, str] = {}
    with opener(path, "rt", encoding="utf-8") as fh:
        for lineno, line in enumerate(fh, 1):
            try:
                row = json.loads(line)
                addr, mnemonic = row["a"], row["m"]
            except (ValueError, KeyError, TypeError) as exc:
                raise ValueError(f"{path}:{lineno}: malformed census row") from exc
            if type(addr) is not int or addr < 0 or not isinstance(mnemonic, str) or not mnemonic:
                raise ValueError(f"{path}:{lineno}: invalid census address or mnemonic")
            if addr in index:
                raise ValueError(f"{path}:{lineno}: duplicate census address {addr:#x}")
            index[addr] = mnemonic
    if not index:
        raise ValueError(f"{path}: empty instruction index")
    return index


def load_claims(root: Path) -> tuple[dict[str, str], set[str]]:
    ids: dict[str, str] = {}
    with_card: set[str] = set()
    for path in sorted(root.glob("claims*.jsonl")):
        with path.open(encoding="utf-8") as fh:
            for lineno, line in enumerate(fh, 1):
                if not line.strip():
                    continue
                try:
                    row = json.loads(line)
                except json.JSONDecodeError as exc:
                    raise ValueError(f"{path}:{lineno}: {exc.msg}") from exc
                if not isinstance(row, dict) or not isinstance(row.get("id"), str) or not row["id"]:
                    raise ValueError(f"{path}:{lineno}: expected a claim with a string id")
                name, status = row["id"], row.get("status", "?")
                if not isinstance(status, str):
                    raise ValueError(f"{path}:{lineno}: expected a string claim status")
                ids[name] = status
                if row.get("card"):
                    with_card.add(name)
    return ids, with_card


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="reconstruction/reverse-v1")
    ap.add_argument("--strict", action="store_true",
                    help="exit 1 for wrong or missing anchors, multiple card owners, or anchorless function cards")
    a = ap.parse_args()

    root = Path(a.root)
    asm, cards = root / "asm", root / "cards"
    try:
        index = load_index(asm)
    except (OSError, EOFError, ValueError, lzma.LZMAError) as exc:
        print(f"invalid instruction index: {exc}", file=sys.stderr)
        return 2
    try:
        ids, with_card = load_claims(root)
    except (OSError, ValueError) as exc:
        print(f"invalid claim ledger: {exc}", file=sys.stderr)
        return 2

    owners: dict[int, list[str]] = collections.defaultdict(list)
    rows = []
    for card in sorted(cards.glob("*.c")):
        text = card.read_text(encoding="utf-8")
        found = {(int(m.group(1), 16), m.group(2)) for m in ANCHOR.finditer(text)}
        level = LEVEL.search(text)
        span = FUNC.search(text)
        bad = [addr for addr, mnem in found if index.get(addr) != mnem]
        for addr in {addr for addr, _ in found}:
            owners[addr].append(card.stem)
        rows.append({
            "card": card.stem,
            "level": level.group(1) if level else "-",
            "anchors": len(found),
            "span": f"{span.group(1)}..{span.group(2)}" if span else "-",
            "wrong": len(bad),
            "empty_function": span is not None and not found,
        })

    shared = {addr: names for addr, names in owners.items() if len(names) > 1}
    missing = [addr for addr in index if addr not in owners]
    empty_functions = sum(r["empty_function"] for r in rows)

    print(f"{'card':22} {'level':6} {'anchors':>7}  {'range':>19}  status")
    for r in sorted(rows, key=lambda r: r["card"]):
        status = ("EMPTY_FUNCTION_CARD" if r["empty_function"] else
                  f"{r['wrong']} WRONG" if r["wrong"] else
                  "EXACT" if r["anchors"] else "NO_ANCHORS")
        print(f"{r['card']:22} {r['level']:6} {r['anchors']:7d}  {r['span']:>19}  {status}")
    print(f"\ncards={len(rows)} anchors={sum(r['anchors'] for r in rows)} "
          f"addresses_claimed_by_two_cards={len(shared)}")
    print(f"census_addresses={len(index)} missing_in_cards={len(missing)} "
          f"empty_function_cards={empty_functions}")
    for addr in sorted(shared)[:5]:
        print(f"  shared {addr:#x}: {', '.join(shared[addr])}")
    for addr in sorted(missing)[:5]:
        print(f"  missing {addr:#x} ({index[addr]})")

    claims = collections.Counter(ids.values())
    print(f"claims={len(ids)} " + " ".join(f"{k}={v}" for k, v in sorted(claims.items())))
    missing_card = [i for i, s in ids.items() if s != "open" and i not in with_card]
    if missing_card:
        print(f"claims without a card reference: {missing_card[:5]}")

    return 1 if a.strict and (missing or shared or empty_functions or any(r["wrong"] for r in rows)) else 0


if __name__ == "__main__":
    sys.exit(main())
