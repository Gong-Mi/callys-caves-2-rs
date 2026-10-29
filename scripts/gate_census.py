#!/usr/bin/env python3
"""Census the consumers of a data address that is reached through a GOT slot.

Why: some engine behaviour is gated by a byte/word living at a fixed global. Reading
"who touches 0x5428e8" statically is how a gate stops being a rumour: every site below
is a concrete instruction that loads the GOT slot holding that address.

Method (no guessing):
  1. per function, recover the GOT base from its prologue (`ldr rX,[pc,#imm]` + `add rX,pc,rX`)
  2. a `ldr rD,[pc,#imm]` in the body gives an offset; `base + offset` is a slot address
  3. the slot's target comes from .rel.dyn (RELATIVE/GLOB_DAT), not from pattern-matching
  4. classify the use: a following `ldrb/ldr rD,[rD]` is a read, `strb/str rS,[rD]` a write

    python3 scripts/gate_census.py 0x5428e8 0x755363
"""
from __future__ import annotations

import argparse
import bisect
import collections
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RV = ROOT / "reconstruction/reverse-v1"
ASM = RV / "asm"
sys.path.insert(0, str(ROOT / "scripts"))
import init_table_extract as X   # noqa: E402


def load_index():
    rows = {}
    with open(ASM / "instructions.jsonl", encoding="utf-8") as fh:
        for line in fh:
            r = json.loads(line)
            rows[r["a"]] = (r["m"], r.get("o", ""))
    return rows


def load_functions():
    out = []
    for line in (ASM / "functions.tsv").read_text(encoding="utf-8").splitlines():
        c = line.split("\t")
        if len(c) >= 3:
            out.append((int(c[0], 16), int(c[1]), c[2]))
    out.sort()
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("targets", nargs="+", help="data addresses, e.g. 0x5428e8")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()
    targets = {int(t, 16) for t in a.targets}

    ins = load_index()
    fns = load_functions()
    starts = [f[0] for f in fns]
    img = X.Image(next(p for p in X.SO_CANDIDATES if p.exists()))
    slots = {slot: tgt for slot, tgt in img.relocs.items() if tgt in targets}

    hits = []
    for start, size, name in fns:
        # prologue GOT base
        base = None
        for a2 in range(start, min(start + 0x40, start + size), 4):
            if a2 not in ins:
                continue
            m, ops = ins[a2]
            if m != "ldr" or "[pc," not in ops:
                continue
            dst = ops.split(",")[0].strip()
            for b in range(a2 + 4, min(a2 + 0x14, start + size), 4):
                if b in ins and ins[b][0] == "add" and ins[b][1].startswith(dst + ", pc"):
                    off = X.num(ops.split("[pc,")[1].rstrip("]").strip().lstrip("#"))
                    if off is not None:
                        base = (b + 8 + (img.u32((a2 + 8 + off) & ~3) or 0)) & 0xFFFFFFFF
                    break
            if base:
                break
        if base is None:
            continue
        for a2 in range(start, min(start + size, start + size), 4):
            if a2 not in ins:
                continue
            m, ops = ins[a2]
            if m != "ldr" or "[pc," not in ops:
                continue
            off = X.num(ops.split("[pc,")[1].rstrip("]").strip().lstrip("#"))
            if off is None:
                continue
            word = img.u32((a2 + 8 + off) & ~3)
            if word is None:
                continue
            slot = (base + word) & 0xFFFFFFFF
            if slot not in slots:
                continue
            dst = ops.split(",")[0].strip()
            kind = "?"
            for b in range(a2 + 4, min(a2 + 0x20, start + size), 4):
                if b not in ins:
                    continue
                m2, o2 = ins[b]
                if m2 in ("ldrb", "ldr", "ldrh", "ldrsb") and o2.split(",")[0].strip() == dst and "[" + dst in o2.replace(" ", ""):
                    kind = "read"
                    break
                if m2 in ("strb", "str", "strh") and ("[" + dst in o2.replace(" ", "")):
                    kind = "write"
                    break
            hits.append({"func": name, "site": a2, "slot": slot, "target": slots[slot], "kind": kind, "base": base})

    by = collections.Counter((h["target"], h["kind"]) for h in hits)
    for t in sorted(targets):
        print(f"== 0x{t:x}")
        for (tt, k), n in sorted(by.items()):
            if tt == t:
                print(f"   {k:6} {n}")
        for h in hits:
            if h["target"] == t:
                print(f"   {h['kind']:6} 0x{h['site']:x} in {h['func']} (slot 0x{h['slot']:x})")
    if a.json:
        print(json.dumps(hits, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())
