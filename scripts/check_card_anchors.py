#!/usr/bin/env python3
"""Check a reverse-engineering card's anchors against the binary-derived index.

Shamiko-style rule: every `@0xADDR mnem operands` in a card must appear verbatim
in the index produced from the .so, and every instruction in the function range
must be anchored by the card. Anything else fails.

    python3 scripts/check_card_anchors.py \
        --card reconstruction/reverse-v1/cards/Code_Execute.c \
        --index reconstruction/reverse-v1/asm/index-Code_Execute.tsv

Exit: 0 = exact, 1 = missing/extra/mismatch.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ANCHOR = re.compile(r"@0x([0-9a-fA-F]+)\s+([A-Za-z.][A-Za-z0-9_.]*)\s*(.*)")


def load_index(path: Path) -> dict[int, tuple[str, str]]:
    rows: dict[int, tuple[str, str]] = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        addr, _word, mnem, ops = line.split("\t")
        rows[int(addr, 16)] = (mnem, ops.strip())
    return rows


def load_card(path: Path) -> dict[int, tuple[str, str]]:
    rows: dict[int, tuple[str, str]] = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        for m in ANCHOR.finditer(line):
            addr = int(m.group(1), 16)
            mnem = m.group(2)
            ops = m.group(3)
            # the text after the operands is prose introduced by an em dash or CJK
            ops = re.split(r"\s*——|\s*[\u4e00-\u9fff]", ops)[0].strip()
            ops = re.sub(r"\s*\*/\s*$", "", ops).strip()
            rows[addr] = (mnem, ops)
    return rows


def norm_ops(ops: str) -> str:
    return re.sub(r"\s+", "", ops.replace("0x", ""))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", required=True)
    ap.add_argument("--index", required=True)
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()

    index = load_index(Path(a.index))
    card = load_card(Path(a.card))

    missing = sorted(set(index) - set(card))
    extra = sorted(set(card) - set(index))
    mismatch = []
    for addr in sorted(set(index) & set(card)):
        i_mnem, i_ops = index[addr]
        c_mnem, c_ops = card[addr]
        if i_mnem != c_mnem or norm_ops(i_ops) != norm_ops(c_ops):
            mismatch.append((addr, i_mnem, i_ops, c_mnem, c_ops))

    print(f"index={len(index)} card={len(card)} missing={len(missing)} extra={len(extra)} mismatch={len(mismatch)}")
    if missing:
        print("  missing anchors:", ", ".join(f"{x:#x}({index[x][0]})" for x in missing[:12]))
    if extra:
        print("  anchors not in index:", ", ".join(f"{x:#x}" for x in extra[:12]))
    for addr, i_mnem, i_ops, c_mnem, c_ops in mismatch[:8]:
        print(f"  {addr:#x}: index '{i_mnem} {i_ops}' vs card '{c_mnem} {c_ops}'")
    ok = not missing and not extra and not mismatch
    print("RESULT", "EXACT" if ok else "FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
