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
# ARM prints an 8-hex word; Thumb-2 prints 4 hex or two 4-hex halves ("e92d 4ff0")
INSN = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{4}(?:\s?[0-9a-f]{4})?)\s+(\S+)\s*(.*)$")


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
    thumb_ranges: list[tuple[int, int]] = []
    for line in run([tool("readelf"), "-sW", str(so)]).splitlines():
        m = SYM.match(line.strip())
        if not m:
            continue
        addr, size, name = int(m.group(1), 16), int(m.group(2)), m.group(3)
        thumb = addr % 2 == 1
        if thumb:            # bit0 = ISA select: the real address is even
            addr -= 1
        if size == 0 or not (text_lo <= addr < text_hi):
            continue
        funcs.append((addr, size, name))
        if thumb:
            thumb_ranges.append((addr, addr + size))
    funcs.sort()

    # 3) instructions
    dis = run([tool("llvm-objdump"), "-d", f"--triple={a.triple}",
               f"--start-address={text_lo:#x}", f"--stop-address={text_hi:#x}", str(so)])
    def parse(text: str) -> dict[int, tuple[str, str, str]]:
        out: dict[int, tuple[str, str, str]] = {}
        for line in text.splitlines():
            m = INSN.match(line)
            if not m:
                continue
            addr = int(m.group(1), 16)
            mnem = m.group(3)
            ops = re.split(r"\s+@\s", m.group(4))[0].strip()
            if mnem.startswith("<"):
                mnem, ops = ".word", f"0x{m.group(2)}"
            out[addr] = (m.group(2).replace(" ", ""), mnem, ops)
        return out

    insnsThumb: dict[int, tuple[str, str, str]] = {}
    for lo, hi in thumb_ranges:
        t = run([tool("llvm-objdump"), "-d", "--triple=thumbv7-linux-androideabi",
                 f"--start-address={lo:#x}", f"--stop-address={hi:#x}", str(so)])
        for k, v in parse(t).items():
            insnsThumb[k] = v
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

    # 3b) unnamed Thumb-2: a stripped static function carries no symbol, so the only hint is
    #     that the ARM decode is nonsense (svc / undefined / .word runs). Retry those ranges
    #     with the Thumb triple and keep whichever decode is cleaner.
    SUSPECT = ("svc", "undefined", ".word", "andeq", "eorseq")
    def bad_ratio(rng_lo, rng_hi, table) -> float:
        tot = bad = 0
        for a, (_w, m, _o) in table.items():
            if rng_lo <= a < rng_hi:
                tot += 1
                if m.startswith(SUSPECT):
                    bad += 1
        return bad / tot if tot else 0.0

    # anonymous ranges from the previous census pass (functions.tsv is written by it);
    # on the very first run there is nothing to retry, and the ranges get built below anyway.
    prev_anon: list[tuple[int, int]] = []
    prev_tsv = out_dir / "functions.tsv"
    if prev_tsv.exists():
        for line in prev_tsv.read_text(encoding="utf-8").splitlines():
            cols = line.split("\t")
            if len(cols) >= 7 and cols[2].startswith("anon_"):
                a = int(cols[0], 16)
                prev_anon.append((a, a + int(cols[1])))

    thumb_fixed = 0
    import os as _os
    _retry = _os.environ.get("CENSUS_UNNAMED_THUMB") == "1"
    for lo, hi in (prev_anon if _retry else []):
        if bad_ratio(lo, hi, insns) < 0.10:
            continue
        t = run([tool("llvm-objdump"), "-d", "--triple=thumbv7-linux-androideabi",
                 f"--start-address={lo:#x}", f"--stop-address={hi:#x}", str(so)])
        cand = parse(t)
        if not cand:
            continue
        if bad_ratio(lo, hi, cand) < bad_ratio(lo, hi, insns):
            for a in [x for x in insns if lo <= x < hi]:
                del insns[a]
            insns.update(cand)
            thumb_fixed += 1
    print(f"unnamed Thumb-2 regions re-decoded: {thumb_fixed} "
          f"(opt-in via CENSUS_UNNAMED_THUMB=1; off by default: the heuristic doubled the "
          f"anon segment count and is not evidence enough to ship)", file=sys.stderr)

    insns.update(insnsThumb)
    for lo, hi in thumb_ranges:
        for a in [x for x in insns if lo <= x < hi and x not in insnsThumb]:
            pass

    # 4) attribute: smallest enclosing symbol wins, so nested symbols are not swallowed.
    #    NOTE: cannot step by 4 — Thumb-2 instructions are 2 or 4 bytes, so the walk has to
    #    come from the decoded instruction addresses themselves.
    import bisect

    addrs = sorted(insns)
    owner: dict[int, int] = {}
    for addr, size, _ in sorted(funcs, key=lambda f: (f[1], f[0])):
        lo = bisect.bisect_left(addrs, addr)
        hi = bisect.bisect_left(addrs, addr + size)
        for ins_addr in addrs[lo:hi]:
            if ins_addr not in owner:
                owner[ins_addr] = addr

    # 4b) everything still unowned is an anonymous region (stripped statics, literal pools,
    #     jump tables). Contiguity is judged on the decoded instruction stream, not on a +4 step,
    #     because Thumb-2 mixes 2- and 4-byte instructions.
    unowned = [a for a in addrs if a not in owner]
    order = {a: i for i, a in enumerate(addrs)}
    anon_ranges: list[tuple[int, int]] = []
    run_start = prev = None
    for ins_addr in unowned:
        if prev is not None and order[ins_addr] == order[prev] + 1:
            prev = ins_addr
            continue
        if run_start is not None:
            anon_ranges.append((run_start, prev))
        run_start = prev = ins_addr
    if run_start is not None:
        anon_ranges.append((run_start, prev))

    for lo, hi in anon_ranges:
        a = bisect.bisect_left(addrs, lo)
        b = bisect.bisect_right(addrs, hi)
        funcs.append((lo, addrs[b - 1] - lo, f"anon_{lo:x}"))
        for ins_addr in addrs[a:b]:
            if ins_addr not in owner:
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
