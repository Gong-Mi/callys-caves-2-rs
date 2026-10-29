#!/usr/bin/env python3
"""Scan every ALU path in a VM handler body (all integer mnemonics, not just v*/helpers).

Why this exists: an earlier pass concluded "DoAdd/DoSub have no integer path" because it
only looked at `v*` and `__aeabi*` mnemonics and missed the inline `adds`/`adc` and
`subs`/`sbc` pairs. This tool histograms the whole body and flags the shapes that matter,
so the same mistake cannot be repeated:

  * inline 64-bit add  (adds + adc in adjacent slots)
  * inline 64-bit sub  (subs + sbc)
  * integer mul/div    (mul/mla/umull/smulal/__aeabi_lmul/__divsi3/__aeabi_ldivmod)
  * shifts/logic       (lsl/lsr/asr/and/orr/eor/bic, both inline and via helpers)
  * VFP float ops      (vadd/vsub/vmul/vdiv/vcvt/vmov/vldr/vstr)
  * result tag constants (mov r12,#imm near strd)

    python3 scripts/alu_path_scan.py --f 0xdc524 DoAdd [--all]
"""
from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ASM = ROOT / "reconstruction/reverse-v1/asm"

INT_ADD = {"add", "adds", "adc", "addw"}
INT_SUB = {"sub", "subs", "sbc", "subw", "rsb"}
INT_MUL = {"mul", "muls", "mla", "mls", "umull", "smull", "umlal", "smlal", "smulbb", "smulwb"}
INT_DIV = {"sdiv", "udiv"}
LOGIC = {"and", "ands", "orr", "orrs", "eor", "eors", "bic", "bics", "orn"}
SHIFT = {"lsl", "lsls", "lsr", "lsrs", "asr", "asrs", "ror", "rors"}
HELPERS = ("__aeabi_ldivmod", "__aeabi_lmul", "__divsi3", "__udivsi3", "__fixdfdi",
           "__floatdidf", "__aeabi_dmul", "__aeabi_ddiv", "fmod")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--f", required=True, help="census function start (hex)")
    ap.add_argument("names", nargs="*")
    args = ap.parse_args()
    start = int(args.f, 16)

    ins = {}
    for line in open(ASM / "instructions.jsonl", encoding="utf-8"):
        r = json.loads(line)
        if r.get("f") == start:
            ins[r["a"]] = (r["m"], r.get("o", ""))
    if not ins:
        print("no instructions for that census function start", file=sys.stderr)
        return 2
    order = sorted(ins)
    hist = collections.Counter(m for m, _ in ins.values())
    title = " ".join(args.names) or f"0x{start:x}"

    def near(a, mnems, window=3):
        i = order.index(a)
        return [order[j] for j in range(i + 1, min(i + 1 + window, len(order)))
                if order[j] in ins and ins[order[j]][0] in mnems]

    wide_add, wide_sub, tag10 = [], [], []
    for a in order:
        m, o = ins[a]
        if m in ("adds", "add") and near(a, {"adc", "adcs"}):
            wide_add.append(a)
        if m in ("subs", "sub") and near(a, {"sbc", "sbcs"}):
            wide_sub.append(a)
        if m == "mov" and re.match(r"r12,\s*#10$", o.strip()):
            tag10.append(a)

    helpers = collections.Counter()
    for a in order:
        m, o = ins[a]
        if m.startswith("bl") and o:
            sym = o.split("<")[1].rstrip(">") if "<" in o else ""
            for h in HELPERS:
                if h in sym:
                    helpers[h] += 1

    print(f"== {title} 0x{start:x}  {len(order)} 条")
    print("   整数加(add/adds/adc): " + ", ".join(f"{k}×{v}" for k, v in hist.items() if k in INT_ADD))
    print("   整数减(sub/subs/sbc): " + ", ".join(f"{k}×{v}" for k, v in hist.items() if k in INT_SUB))
    print("   整数乘: " + (", ".join(f"{k}×{v}" for k, v in hist.items() if k in INT_MUL) or "无"))
    print("   整数除: " + (", ".join(f"{k}×{v}" for k, v in hist.items() if k in INT_DIV) or "无"))
    print("   逻辑: " + (", ".join(f"{k}×{v}" for k, v in hist.items() if k in LOGIC) or "无"))
    print("   移位: " + (", ".join(f"{k}×{v}" for k, v in hist.items() if k in SHIFT) or "无"))
    print("   VFP: " + (", ".join(f"{k}×{v}" for k, v in hist.items() if k.startswith("v")) or "无"))
    print("   助手: " + (", ".join(f"{k}×{v}" for k, v in helpers.items()) or "无"))
    print(f"   形状: 64位加(adds+adc) {len(wide_add)} 处 {[hex(x) for x in wide_add[:6]]}")
    print(f"         64位减(subs+sbc) {len(wide_sub)} 处 {[hex(x) for x in wide_sub[:6]]}")
    print(f"         结果 tag=10 站点 {len(tag10)} 处 {[hex(x) for x in tag10[:6]]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
