#!/usr/bin/env python3
"""Check a reverse-engineering card's anchors against the binary-derived index.

Every `/* @0xADDR mnem operands */` (or `* @0x…` in a block comment) must match the index from the .so
(ignoring whitespace and equivalent decimal/hex integer immediates), and
every instruction in that nonempty index must be anchored by the card.

    python3 scripts/check_card_anchors.py \
        --card reconstruction/reverse-v1/cards/Code_Execute.c \
        --index reconstruction/reverse-v1/asm/index-Code_Execute.tsv

Exit: 0 = exact, 1 = missing/extra/mismatch, 2 = invalid input.
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

# Address mentions in prose are references, not instruction assertions.
ANCHOR = re.compile(r"(?:/\*|\*)[ \t]+@0x([0-9a-fA-F]+)[ \t]+([A-Za-z.][A-Za-z0-9_.]*)"
                    r"(?=[ \t]|\*/|$)[ \t]*(.*?)(?=\*/|(?:/\*|\*)[ \t]+@0x[0-9a-fA-F]+[ \t]+[A-Za-z.]|$)")
IMMEDIATE = re.compile(r"#([+-]?)(0[xX][0-9a-fA-F]+|[0-9]+)(?![\w.])")


def load_index(path: Path) -> dict[int, tuple[str, str]]:
    rows: dict[int, tuple[str, str]] = {}
    for lineno, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        if not line.strip():
            continue
        try:
            value, _word, mnem, ops = line.split("\t")
            addr = int(value, 16)
        except ValueError as exc:
            raise ValueError(f"{path}:{lineno}: malformed index row") from exc
        if addr in rows:
            raise ValueError(f"{path}:{lineno}: duplicate index address {addr:#x}")
        rows[addr] = (mnem, ops.strip())
    if not rows:
        raise ValueError(f"{path}: empty instruction index")
    return rows


def load_card(path: Path) -> dict[int, tuple[str, str]]:
    rows: dict[int, tuple[str, str]] = {}
    for lineno, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        for m in ANCHOR.finditer(line):
            addr = int(m.group(1), 16)
            mnem = m.group(2)
            ops = m.group(3)
            # Explicit commentary delimiters in historical card annotations.
            ops = re.split(r"\s*(?:——|→|[\u4e00-\u9fff])", ops, maxsplit=1)[0].strip()
            prev = rows.get(addr)
            if prev is not None and (prev[0] != mnem or norm_ops(prev[1]) != norm_ops(ops)):
                raise ValueError(f"{path}:{lineno}: conflicting anchors at {addr:#x}")
            rows[addr] = (mnem, ops)
    return rows


def norm_ops(ops: str) -> str:
    def integer(match: re.Match[str]) -> str:
        sign, digits = match.groups()
        base = 16 if digits[:2].lower() == "0x" else 10
        return f"#{int(sign + digits, base)}"

    return IMMEDIATE.sub(integer, re.sub(r"\s+", "", ops))


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", required=True)
    ap.add_argument("--index", required=True)
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()

    try:
        index = load_index(Path(a.index))
        card = load_card(Path(a.card))
    except (OSError, ValueError) as exc:
        print(f"RESULT INVALID: {exc}", file=sys.stderr)
        return 2

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
