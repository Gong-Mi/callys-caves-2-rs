#!/usr/bin/env python3
"""Annotated listing of a VM handler body, for writing semantic cards.

Prints only the instructions that carry semantics — the ones that load a constant,
compare a tag, call a helper, or write the caller's RValue — and resolves:
  * `ldr rX,[pc,#imm]`  -> in-text value / .rodata string / GOT-slot target
  * `bl <target>`       -> symbol from asm/functions.tsv
  * `cmp rX,#imm`       -> immediate (tag constants, K values, offsets)

    python3 scripts/vm_handler_scan.py --start 0xe2014 --end 0xe3d28
"""
from __future__ import annotations

import argparse
import bisect
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RV = ROOT / "reconstruction/reverse-v1"
ASM = RV / "asm"
sys.path.insert(0, str(ROOT / "scripts"))
import init_table_extract as X   # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--start", required=True)
    ap.add_argument("--end", required=True)
    ap.add_argument("--all", action="store_true", help="print every instruction, not just semantic ones")
    a = ap.parse_args()
    lo, hi = int(a.start, 16), int(a.end, 16)

    ins = {}
    for line in open(ASM / "instructions.jsonl", encoding="utf-8"):
        r = json.loads(line)
        if lo <= r["a"] < hi:
            ins[r["a"]] = (r["m"], r.get("o", ""))
    fns = sorted((int(c[0], 16), int(c[1]), c[2])
                 for c in (l.split("\t") for l in (ASM / "functions.tsv").read_text(encoding="utf-8").splitlines())
                 if len(c) >= 3)
    starts = [f[0] for f in fns]

    def resolve(va: int) -> str:
        i = bisect.bisect_right(starts, va) - 1
        if i < 0:
            return f"0x{va:x}"
        s, z, n = fns[i]
        return n if va == s else (f"{n}+{va-s:#x}" if s <= va < s + z else f"0x{va:x}")

    img = X.Image(next(p for p in X.SO_CANDIDATES if p.exists()))

    def pool(addr: int, imm: int):
        va = (addr + 8 + imm) & ~3
        val = img.u32(va)
        if val is None:
            return None, None
        s = img.cstr(val)
        if s and all(32 <= ord(ch) < 127 for ch in s) and len(s) >= 2:
            return "str", s
        tgt = img.relocs.get(val)
        if tgt:
            return "slot", tgt
        return "val", val

    for addr in sorted(ins):
        m, o = ins[addr]
        note = ""
        if m == "ldr" and "[pc," in o:
            try:
                imm = X.num(o.split("[pc,")[1].rstrip("]").strip().lstrip("#"))
            except Exception:
                imm = None
            if imm is not None:
                kind, val = pool(addr, imm)
                if kind == "str":
                    note = f'= "{val}"'
                elif kind == "slot":
                    note = f"→ 槽→ 0x{val:x}"
                elif kind == "val":
                    note = f"= 0x{val:x}"
        elif m.startswith("bl"):
            try:
                note = "→ " + resolve(int(o.split()[0], 16))
            except Exception:
                pass
        elif m in ("cmp", "cmn", "tst", "mov", "movs", "mvn") and "#" in o:
            note = ""
        interesting = (a.all or note or m.startswith(("b", "pop", "push", "bx", "v"))
                       or m in ("cmp", "cmn", "tst") or (m.startswith(("str", "strb")) and "#" in o))
        if not interesting:
            continue
        print(f"{addr:#08x}  {m:8} {o:44} {note}".rstrip())
    return 0


if __name__ == "__main__":
    sys.exit(main())
