#!/usr/bin/env python3
"""Full census of libyoyo.so: every function, every instruction, attributed.

This is the "coverage" half of the reverse-engineering claim: before any function
card claims semantics, the whole .text has to be enumerated and every instruction
has to belong to exactly one function — otherwise "we reversed it" is a mood.

    python3 scripts/libyoyo_census.py --so libyoyo.so --out reconstruction/reverse-v1/asm

Writes:
    functions.tsv      addr  size  name(demangled)  mangled  first_insn  last_insn  n_insn
    instructions.jsonl one row per instruction: {"a":addr,"w":word,"m":mnem,"o":ops,"f":func_addr}
    census.json        totals: text span, attributed/unattributed instructions and bytes
"""
from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

PREFIX_FALLBACK = "/data/data/com.termux/files/usr/bin"


ALIASES = {"c++filt": ("llvm-cxxfilt", "c++filt")}


def tool(name: str) -> str:
    """A subprocess-launched tool: PATH first, then the Termux prefix."""
    for cand_name in ALIASES.get(name, (name,)):
        found = shutil.which(cand_name)
        if found:
            return found
        cand = os.path.join(PREFIX_FALLBACK, cand_name)
        if os.path.exists(cand):
            return cand
    raise SystemExit(f"cannot find {name}")

SYM = re.compile(r"^[0-9a-f]+:\s+([0-9a-f]{8})\s+(\d+)\s+FUNC\s+\S+\s+\S+\s+\d+\s+(\S+)$")
INSN = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$")


def run(cmd: list[str]) -> str:
    out = subprocess.run(cmd, capture_output=True, text=True)
    if out.returncode != 0:
        print(out.stderr, file=sys.stderr)
        raise SystemExit(2)
    return out.stdout


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--so", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--triple", default="armv7-linux-androideabi")
    a = ap.parse_args()

    so = Path(a.so)
    out_dir = Path(a.out)
    out_dir.mkdir(parents=True, exist_ok=True)

    # 1) .text span
    sections = run([tool("readelf"), "-SW", str(so)])
    text_lo = text_hi = None
    # "[ 8] .text  PROGBITS  000b6fd0 0b6fd0 264bac 00 AX 0 0 8"
    sec = re.compile(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\S+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)")
    for line in sections.splitlines():
        m = sec.match(line)
        if m and m.group(1) == ".text":
            base, size = int(m.group(3), 16), int(m.group(5), 16)
            text_lo, text_hi = base, base + size
    if text_lo is None:
        print("no .text section", file=sys.stderr)
        return 2

    # 2) functions
    funcs = []
    for line in run([tool("readelf"), "-sW", str(so)]).splitlines():
        m = SYM.match(line.strip())
        if not m:
            continue
        addr, size, name = int(m.group(1), 16), int(m.group(2)), m.group(3)
        if size == 0 or not (text_lo <= addr < text_hi):
            continue
        funcs.append((addr, size, name))
    funcs.sort()

    # 3) instructions
    dis = run([tool("llvm-objdump"), "-d", f"--triple={a.triple}",
               f"--start-address={text_lo:#x}", f"--stop-address={text_hi:#x}", str(so)])
    insns: dict[int, tuple[str, str, str]] = {}
    for line in dis.splitlines():
        m = INSN.match(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        mnem = m.group(3)
        ops = re.split(r"\s+@\s", m.group(4))[0].strip()
        if mnem.startswith("<"):
            mnem, ops = ".word", f"0x{m.group(2)}"
        insns[addr] = (m.group(2), mnem, ops)

    # 4) attribute: smallest enclosing symbol wins, so nested symbols are not swallowed
    owner: dict[int, int] = {}
    for addr, size, _ in sorted(funcs, key=lambda f: (f[1], f[0])):
        for ins_addr in range(addr, addr + size, 4):
            if ins_addr in insns and ins_addr not in owner:
                owner[ins_addr] = addr

    # 4b) everything still unowned is an anonymous region (stripped statics, literal pools,
    #     jump tables). Give each contiguous run a synthetic function so coverage is total
    #     and the anonymity is explicit rather than hidden.
    anon_ranges = []
    run_start = prev = None
    for ins_addr in sorted(set(insns) - set(owner)):
        if prev is None or ins_addr != prev + 4:
            if run_start is not None:
                anon_ranges.append((run_start, prev + 4))
            run_start = ins_addr
        prev = ins_addr
    if run_start is not None:
        anon_ranges.append((run_start, prev + 4))
    for lo, hi in anon_ranges:
        funcs.append((lo, hi - lo, f"anon_{lo:x}"))
        for ins_addr in range(lo, hi, 4):
            if ins_addr in insns:
                owner[ins_addr] = lo
    funcs.sort()

    n_ins = len(insns)
    n_owned = len(owner)
    unowned = sorted(set(insns) - set(owner))
    text_bytes = text_hi - text_lo

    by_func: dict[int, list[int]] = {}
    for ins_addr, faddr in owner.items():
        by_func.setdefault(faddr, []).append(ins_addr)

    mangled = [n for _, _, n in funcs if n.startswith("_Z")]
    demap: dict[str, str] = {}
    if mangled:
        out = subprocess.run([tool("c++filt")], input="\n".join(mangled), text=True,
                             capture_output=True)
        for src, dst in zip(mangled, out.stdout.splitlines()):
            demap[src] = dst.strip()

    with open(out_dir / "functions.tsv", "w", encoding="utf-8") as fh:
        for addr, size, name in funcs:
            members = sorted(by_func.get(addr, []))
            dem = demap.get(name, name)
            fh.write("\t".join([
                f"{addr:x}", str(size), dem, name,
                f"{members[0]:x}" if members else "",
                f"{members[-1]:x}" if members else "",
                str(len(members)),
            ]) + "\n")

    with open(out_dir / "instructions.jsonl", "w", encoding="utf-8") as fh:
        for addr in sorted(insns):
            word, mnem, ops = insns[addr]
            fh.write(json.dumps({"a": addr, "w": word, "m": mnem, "o": ops,
                                 "f": owner.get(addr, 0)}, separators=(",", ":")) + "\n")

    import lzma
    with open(out_dir / "instructions.jsonl", "rb") as src, \
            lzma.open(out_dir / "instructions.jsonl.xz", "wb", preset=6) as dst:
        dst.write(src.read())

    census = {
        "so": str(so),
        "text": [hex(text_lo), hex(text_hi)],
        "text_bytes": text_bytes,
        "functions_in_text": len(funcs),
        "anonymous_regions": len(anon_ranges),
        "instructions": n_ins,
        "attributed": n_owned,
        "unattributed": len(unowned),
        "unattributed_first": [hex(x) for x in unowned[:8]],
        "coverage_pct": round(100.0 * n_owned / max(n_ins, 1), 2),
        "funcs_with_instructions": len(by_func),
    }
    (out_dir / "census.json").write_text(json.dumps(census, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(census, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
