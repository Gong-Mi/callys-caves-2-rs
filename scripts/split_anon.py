#!/usr/bin/env python3
"""Split the anonymous regions into real function boundaries.

The census merged every stripped stretch into `anon_<addr>`, so 21 of them hide an
unknown number of functions. Two independent signals give the boundaries:

    1  every `bl`/`blx <imm>` target that lands inside an anon region is a function entry
    2  an ARM prologue right after a literal pool (`push {..., lr}` / `str lr,[sp,#-4]!`)

    python3 scripts/split_anon.py --root reconstruction/reverse-v1 --out asm/anon_splits.tsv
"""
from __future__ import annotations

import argparse
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
    ap.add_argument("--out", default=None)
    a = ap.parse_args()

    asm = Path(a.root) / "asm"
    anon = []
    for line in (asm / "functions.tsv").read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        addr, size, dem, mangled, *_ = line.split("\t")
        if dem.startswith("anon_"):
            anon.append((int(addr, 16), int(size)))
    anon.sort()

    def in_anon(addr: int):
        for lo, size in anon:
            if lo <= addr < lo + size:
                return lo
        return None

    entries: dict[int, set[str]] = {}
    calls: dict[int, int] = {}
    with open_insns(asm) as fh:
        for line in fh:
            row = json.loads(line)
            if row["m"] not in ("bl", "blx"):
                continue
            m = BL.match(row["o"])
            if not m:
                continue
            t = int(m.group(1) or m.group(2), 16)
            if in_anon(t):
                entries.setdefault(t, set()).add("bl")
                calls[t] = calls.get(t, 0) + 1

    # prologue heuristic: push {..., lr} or `str lr,[sp,#-4]!`
    prologue = {}
    with open_insns(asm) as fh:
        prev_word = None
        for line in fh:
            row = json.loads(line)
            if in_anon(row["a"]) is None:
                prev_word = None
                continue
            mnem, ops = row["m"], row["o"]
            is_pro = (mnem == "push" and "lr" in ops) or (mnem == "str" and ops.startswith("lr, [sp, #-4]!"))
            # only count it when the previous slot was a literal word or a return/pool gap
            if is_pro and (prev_word is None or prev_word in ("bx", "pop", "b") or row["m"] == "push"):
                prologue.setdefault(row["a"], set()).add("prologue")
            prev_word = mnem

    # 3rd signal: 4-byte data words in .data/.rodata that point into an anon region.
    # Method tables (`str rX,[base,#imm]` entries) never show up as a `bl`, so this is the only
    # way to see them. Produced by the inline scan in the session log; file is optional.
    data_entries = asm / "anon_data_entries.txt"
    if data_entries.exists():
        for line in data_entries.read_text(encoding="utf-8").split():
            entries.setdefault(int(line, 16), set()).add("data-ptr")

    merged: dict[int, set[str]] = {}
    for d in (entries, prologue):
        for k, v in d.items():
            merged.setdefault(k, set()).update(v)

    rows = []
    for lo, size in anon:
        inside = sorted(x for x in merged if lo <= x < lo + size)
        bounds = [lo] + [x for x in inside if x != lo] + [lo + size]
        bounds = sorted(set(bounds))
        for i in range(len(bounds) - 1):
            start, end = bounds[i], bounds[i + 1]
            ev = ",".join(sorted(merged.get(start, {"region-start"})))
            rows.append((start, end - start, lo, ev))

    total = sum(r[1] for r in rows)
    print(f"anon 区 {len(anon)} 块 / {sum(s for _, s in anon)} B → 切出 {len(rows)} 段 / {total} B")
    multi = [r for r in rows if "," in r[3] or r[3] != "region-start"]
    print(f"其中入口有证据（bl 或 prologue）的 {len(multi)} 段")

    if a.out:
        with open(Path(a.root) / "asm" / "anon_splits.tsv", "w", encoding="utf-8") as fh:
            fh.write("start\tsize\tparent_anon\tevidence\n")
            for start, size, lo, ev in rows:
                fh.write(f"{start:x}\t{size}\t{lo:x}\t{ev}\n")
        print(f"写入 {Path(a.root) / 'asm' / 'anon_splits.tsv'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
