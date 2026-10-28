#!/usr/bin/env python3
"""Build an address-anchored asm index for a stripped ARM32 .so (Shamiko-style).

Every card line carries `@0xVA mnem operands`; this index is the authority those
anchors are checked against, so it has to come from the binary, never from a
human transcription.

    python3 scripts/asm_index.py --so libyoyo.so --start 0xcfc60 --end 0xcfcb4 \
        --out reconstruction/reverse-v1/asm/index-Code_Execute.tsv

Output columns (tab separated, no header, address without 0x):
    addr  word_hex  mnemonic  operands
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

LINE = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--so", required=True)
    ap.add_argument("--start", required=True)
    ap.add_argument("--end", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--triple", default="armv7-linux-androideabi")
    a = ap.parse_args()

    start, end = int(a.start, 16), int(a.end, 16)
    cmd = [
        "llvm-objdump", "-d", f"--triple={a.triple}",
        f"--start-address={start:#x}", f"--stop-address={end:#x}",
        a.so,
    ]
    out = subprocess.run(cmd, text=True, capture_output=True)
    if out.returncode != 0:
        print(out.stderr, file=sys.stderr)
        return 2

    rows = []
    for line in out.stdout.splitlines():
        m = LINE.match(line)
        if not m:
            continue
        addr, word, mnem, ops = m.groups()
        # objdump appends its own resolved-target comment ("@ imm = ...",
        # "@ 0xcfcac <sym+0x4c>"); the anchor must be the instruction only.
        ops = re.split(r"\s+@\s", ops)[0].strip()
        if mnem.startswith("<"):  # literal-pool word: objdump has no opcode name for it
            mnem, ops = ".word", f"0x{word}"
        rows.append((int(addr, 16), word, mnem, ops))

    if not rows:
        print("no instructions decoded in that range", file=sys.stderr)
        return 1
    rows.sort()
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    with open(a.out, "w", encoding="utf-8") as fh:
        for addr, word, mnem, ops in rows:
            fh.write(f"{addr:x}\t{word}\t{mnem}\t{ops}\n")
    print(f"{a.out}: {len(rows)} instructions, {rows[0][0]:#x}..{rows[-1][0]:#x}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
