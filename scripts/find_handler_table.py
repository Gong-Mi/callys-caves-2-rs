#!/usr/bin/env python3
"""Locate the VM handler table: which opcode index maps to which Do* handler.

`VM::ExecRelease` dispatches with `r6 = [VMExec+0x58][pc]`, so the table has to
exist somewhere in .data/.rodata as a run of pointers to Do* functions. This
script finds every maximal run of such pointers and prints opcode -> handler,
which is the missing link between GML bytecode numbers and the cards in cards/.

    python3 scripts/find_handler_table.py --so libyoyo.so --dump asm/handler_table.tsv
"""
from __future__ import annotations

import argparse
import re
import struct
import subprocess
import sys

SEC = re.compile(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\S+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)")
SYM = re.compile(r"^[0-9a-f]+:\s+([0-9a-f]{8})\s+(\d+)\s+FUNC\s+\S+\s+\S+\s+\d+\s+(\S+)$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--so", required=True)
    ap.add_argument("--min-run", type=int, default=8)
    ap.add_argument("--dump", help="write index<TAB>slot_va<TAB>handler to this file")
    a = ap.parse_args()

    blob = open(a.so, "rb").read()
    sections: dict[str, tuple[int, int, int]] = {}
    for line in subprocess.run(["readelf", "-SW", a.so], capture_output=True, text=True).stdout.splitlines():
        m = SEC.match(line)
        if m and m.group(2) != "NOBITS":
            sections[m.group(1)] = (int(m.group(3), 16), int(m.group(4), 16), int(m.group(5), 16))

    funcs: dict[int, str] = {}
    for line in subprocess.run(["readelf", "-sW", a.so], capture_output=True, text=True).stdout.splitlines():
        m = SYM.match(line.strip())
        if m and re.match(r"_Z\d+(Do[A-Z]|PerformReturn)", m.group(3)):
            funcs[int(m.group(1), 16)] = m.group(3)

    print(f"Do*/PerformReturn 函数 {len(funcs)} 个", file=sys.stderr)

    runs = []
    for sec_name in (".data.rel.ro", ".data", ".rodata"):
        if sec_name not in sections:
            continue
        base, off, size = sections[sec_name]
        hits: dict[int, int] = {}
        end = min(size, len(blob) - off)
        for i in range(0, end - 3, 4):
            val = struct.unpack_from("<I", blob, off + i)[0]
            if val in funcs:
                hits[i] = val
        # maximal runs of consecutive 4-byte slots that all hit
        for i in sorted(hits):
            if (i - 4) in hits:
                continue  # not a run start
            run, cur = [], i
            while cur in hits:
                run.append((cur, hits[cur]))
                cur += 4
            if len(run) >= a.min_run:
                runs.append((len(run), sec_name, base + i, run))

    if not runs:
        print("no handler table found", file=sys.stderr)
        return 1
    runs.sort(key=lambda r: -r[0])
    for n, sec, va, run in runs[:3]:
        print(f"\n候选表: {sec} VA 0x{va:x}  条目 {n}")
        for idx, (off, val) in enumerate(run[:10]):
            print(f"  [{idx:3d}] {funcs[val]}")
        if n > 10:
            print(f"  … 共 {n} 项（末项 {funcs[run[-1][1]]}）")

    if a.dump:
        n, sec, va, run = runs[0]
        with open(a.dump, "w", encoding="utf-8") as fh:
            for idx, (off, val) in enumerate(run):
                fh.write(f"{idx}\t0x{va + (off - run[0][0]):x}\t{funcs[val]}\n")
        print(f"\n写入 {a.dump}: {n} 项（取最大候选，{sec}）")
    return 0


if __name__ == "__main__":
    sys.exit(main())
