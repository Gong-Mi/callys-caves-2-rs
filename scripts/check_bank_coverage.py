#!/usr/bin/env python3
"""Assert that the generated bank cards cover every instruction of libyoyo.so.

The claim "we reversed the whole .so" reduces to two equalities:

    anchors in cards/auto/bank_*.c   ==  instructions in asm/instructions.jsonl
    instructions.jsonl               ==  every instruction in .text (asm/census.json)

and one inequality: no anchor address appears in two banks.

    python3 scripts/check_bank_coverage.py --asm .../asm --cards .../cards/auto
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

def open_instructions(asm_dir: Path):
    plain = asm_dir / "instructions.jsonl"
    if plain.exists():
        return open(plain, encoding="utf-8")
    import lzma
    return lzma.open(asm_dir / "instructions.jsonl.xz", "rt", encoding="utf-8")


ANCHOR = re.compile(r"/\* @0x([0-9a-f]+) ([A-Za-z.][A-Za-z0-9_.]*)")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--asm", required=True)
    ap.add_argument("--cards", required=True)
    a = ap.parse_args()

    asm, cards = Path(a.asm), Path(a.cards)
    census = json.loads((asm / "census.json").read_text(encoding="utf-8"))

    index: dict[int, str] = {}
    with open_instructions(asm) as fh:
        for line in fh:
            row = json.loads(line)
            index[row["a"]] = row["m"]

    seen: dict[int, str] = {}
    duplicates = []
    mismatched = []
    for card in sorted(cards.glob("bank_*.c")):
        for m in ANCHOR.finditer(card.read_text(encoding="utf-8")):
            addr, mnem = int(m.group(1), 16), m.group(2)
            if addr in seen:
                duplicates.append((addr, seen[addr], card.name))
                continue
            seen[addr] = card.name
            if addr in index and index[addr] != mnem:
                mismatched.append((addr, index[addr], mnem))

    missing = sorted(set(index) - set(seen))
    orphan = sorted(set(seen) - set(index))

    print(f"census: instructions={census['instructions']} attributed={census['attributed']} "
          f"coverage={census['coverage_pct']}%")
    print(f"cards: anchors={len(seen)} duplicates={len(duplicates)} "
          f"missing={len(missing)} orphan={len(orphan)} mnemonic_mismatch={len(mismatched)}")
    for addr, a1, a2 in duplicates[:5]:
        print(f"  dup {addr:#x} in {a1} and {a2}")
    for addr, want, got in mismatched[:5]:
        print(f"  mismatch {addr:#x}: index={want} card={got}")
    for addr in missing[:5]:
        print(f"  missing {addr:#x} ({index[addr]})")

    ok = not (duplicates or missing or orphan or mismatched)
    print("RESULT", "TOTAL" if ok else "INCOMPLETE")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
