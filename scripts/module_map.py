#!/usr/bin/env python3
"""WIP — 未完成，输出不可信，别拿来当依据。

现状：只能解 `ldr rX,[pc,#imm]` → 字面量池 → .rodata 这一条直路（971 个函数里只命中 36 个，
且解出来的都是串的碎片）。原因是多数访问走 GOT：字面量池里的值往往是 **GOT 槽偏移**，
需要再过 .got 一次才能拿到真正的 .rodata 地址；这一层没实现。

Group functions by the source-file string they reference.

Almost every GameMaker runner function touches a literal like
`jni/../jni/yoyo/../../../Files/Room/Room_Layers.h` for its allocation site, so
the .rodata path is a reliable subsystem label — better than guessing from names.

    python3 scripts/module_map.py --so libyoyo.so --root reconstruction/reverse-v1
"""
from __future__ import annotations

import argparse
import collections
import json
import lzma
import re
import struct
import subprocess
import sys
from pathlib import Path

LOAD = re.compile(r"\[pc, #(0x[0-9a-f]+)\]")
ADD = re.compile(r"^r(\d+), pc, #(0x[0-9a-f]+)$")
SEC = re.compile(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\S+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)")


def open_insns(asm: Path):
    plain = asm / "instructions.jsonl"
    if plain.exists():
        return open(plain, encoding="utf-8")
    return lzma.open(asm / "instructions.jsonl.xz", "rt", encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--so", required=True)
    ap.add_argument("--root", default="reconstruction/reverse-v1")
    ap.add_argument("--out", default="asm/modules.tsv")
    a = ap.parse_args()

    root = Path(a.root)
    asm = root / "asm"
    blob = open(a.so, "rb").read()

    sections: dict[str, tuple[int, int, int]] = {}
    for line in subprocess.run(["/bin/readelf", "-SW", a.so], capture_output=True, text=True).stdout.splitlines():
        m = SEC.match(line)
        if m and m.group(2) != "NOBITS":
            sections[m.group(1)] = (int(m.group(3), 16), int(m.group(4), 16), int(m.group(5), 16))
    ro = sections.get(".rodata")
    if not ro:
        print("no .rodata", file=sys.stderr)
        return 1
    ro_lo, ro_off, ro_size = ro

    text_sections = {name: v for name, v in sections.items() if name in (".text", ".rodata", ".data", ".data.rel.ro")}

    def read_word(va: int):
        for name, (lo, off, size) in text_sections.items():
            if lo <= va < lo + size - 3:
                return struct.unpack_from("<I", blob, off + (va - lo))[0]
        return None

    def string_at(va: int) -> str | None:
        # ARM loads a literal-pool word first: follow one indirection if needed
        if not (ro_lo <= va < ro_lo + ro_size):
            word = read_word(va)
            if word is None or not (ro_lo <= word < ro_lo + ro_size):
                return None
            va = word
        off = ro_off + (va - ro_lo)
        end = blob.find(b"\0", off, min(len(blob), off + 200))
        if end < 0 or end - off < 6:
            return None
        raw = blob[off:end]
        try:
            text = raw.decode("utf-8")
        except UnicodeDecodeError:
            return None
        return text if all(32 <= ord(c) < 127 for c in text) else None

    # instruction address -> owning function start
    owner_of = {}
    for line in (asm / "functions.tsv").read_text(encoding="utf-8").splitlines():
        cols = line.split("\t")
        if len(cols) < 7:
            continue
        start = int(cols[0], 16)
        for ins in (int(cols[4], 16), int(cols[5], 16)):
            pass
    funcs = [(int(c[0], 16), int(c[1]), c[2]) for c in
             (l.split("\t") for l in (asm / "functions.tsv").read_text(encoding="utf-8").splitlines()) if len(c) >= 7]
    funcs.sort()

    def owner(addr: int):
        lo, hi = 0, len(funcs) - 1
        best = None
        while lo <= hi:
            mid = (lo + hi) // 2
            if funcs[mid][0] <= addr:
                best = funcs[mid]
                lo = mid + 1
            else:
                hi = mid - 1
        if best and best[0] <= addr < best[0] + best[1]:
            return best
        return None

    hits: dict[int, collections.Counter] = collections.defaultdict(collections.Counter)
    with open_insns(asm) as fh:
        for line in fh:
            row = json.loads(line)
            f = owner(row["a"])
            if not f:
                continue
            m = LOAD.search(row["o"])
            if m:
                imm = int(m.group(1), 16)
                for pc_off in (8, 4):        # ARM reads pc+8, Thumb reads pc+4
                    s = string_at(row["a"] + pc_off + imm)
                    if s:
                        hits[f[0]][s] += 1
                        break

    def module_of(s: str) -> str:
        for sep in ("/", "\\"):
            if sep in s:
                parts = [p for p in re.split(r"[/\\]", s) if p and p != ".."]
                if parts:
                    return "/".join(parts[-2:]) if len(parts) >= 2 else parts[-1]
        return s

    rows = []
    for start, size, name in funcs:
        mod = ""
        if hits.get(start):
            mod = module_of(hits[start].most_common(1)[0][0])
        rows.append((start, size, name, mod))

    out = root / a.out
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("start\tsize\tname\tmodule\n")
        for start, size, name, mod in rows:
            fh.write(f"{start:x}\t{size}\t{name}\t{mod}\n")

    by_mod = collections.Counter()
    bytes_by_mod = collections.Counter()
    for _s, size, _n, mod in rows:
        by_mod[mod or "(no path string)"] += 1
        bytes_by_mod[mod or "(no path string)"] += size
    print(f"函数 {len(rows)}，带源码路径的 {sum(1 for r in rows if r[3])}")
    for mod, n in by_mod.most_common(18):
        print(f"  {mod:34s} {n:5d} 个  {bytes_by_mod[mod]/1024:8.1f} KB")
    print(f"\n写入 {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
