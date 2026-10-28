#!/usr/bin/env python3
"""Thumb-2 symbols: find them, and find which cards were decoded with the wrong ISA.

`readelf` marks Thumb functions by an odd st_value (bit 0 = ISA select). Our
census copied those odd addresses verbatim and disassembled everything with
`--triple=armv7-...`, which decodes Thumb-2 bytes as ARM — mechanically stable
anchors, semantically wrong mnemonics.

    python3 scripts/thumb_map.py --so libyoyo.so --root reconstruction/reverse-v1
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

SYM = re.compile(r"^[0-9a-f]+:\s+([0-9a-f]{8})\s+(\d+)\s+FUNC\s+\S+\s+\S+\s+\d+\s+(\S+)$")
FUNC = re.compile(r"@func\s+0x([0-9a-f]+)(?:\s+0x([0-9a-f]+))?")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--so", required=True)
    ap.add_argument("--root", default="reconstruction/reverse-v1")
    a = ap.parse_args()

    thumb = []
    for line in subprocess.run(["readelf", "-sW", a.so], capture_output=True, text=True).stdout.splitlines():
        m = SYM.match(line.strip())
        if not m:
            continue
        addr, size, name = int(m.group(1), 16), int(m.group(2)), m.group(3)
        if addr % 2 == 1:
            thumb.append((addr - 1, size, name))

    root = Path(a.root)
    out = root / "asm" / "thumb_symbols.tsv"
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("addr\tsize\tmangled\n")
        for addr, size, name in sorted(thumb):
            fh.write(f"{addr:x}\t{size}\t{name}\n")
    total = sum(s for _, s, _ in thumb)
    print(f"Thumb-2 符号 {len(thumb)} 个 / {total} B（{100 * total / 2509740:.1f}% of .text）→ {out}")

    # which cards cover a Thumb range?
    spans = sorted(thumb)
    affected = []
    for card in sorted((root / "cards").glob("*.c")):
        text = card.read_text(encoding="utf-8")
        for m in FUNC.finditer(text):
            start = int(m.group(1), 16)
            for taddr, tsize, tname in spans:
                if taddr <= start < taddr + tsize:
                    affected.append((card.stem, hex(start), tname, tsize))
                    break
    if affected:
        print(f"\n受影响的卡 {len({c for c, *_ in affected})} 张：")
        for card, start, name, size in affected[:20]:
            print(f"  {card:28s} @func {start:>10s} 落在 Thumb 符号 {name[:44]} ({size} B)")
    else:
        print("\n没有已出卡落在 Thumb 区间")
    return 0


if __name__ == "__main__":
    sys.exit(main())
