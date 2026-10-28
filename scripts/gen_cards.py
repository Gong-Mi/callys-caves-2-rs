#!/usr/bin/env python3
"""Generate bank cards covering every function of libyoyo.so.

One card per function would mean 9k files; instead functions are packed 32 to a
bank, address-ordered, so `git`, grep and the anchor checker stay usable.

    python3 scripts/gen_cards.py --asm reconstruction/reverse-v1/asm \
        --out reconstruction/reverse-v1/cards/auto --per-bank 32

Every instruction becomes one anchor line; nothing is summarised or skipped, so
`check_bank_coverage.py` can assert totality: anchors == instructions.
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

def open_instructions(asm_dir: Path):
    plain = asm_dir / "instructions.jsonl"
    if plain.exists():
        return open(plain, encoding="utf-8")
    import lzma
    return lzma.open(asm_dir / "instructions.jsonl.xz", "rt", encoding="utf-8")



def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--asm", required=True, help="dir with functions.tsv + instructions.jsonl")
    ap.add_argument("--out", required=True)
    ap.add_argument("--per-bank", type=int, default=32)
    a = ap.parse_args()

    asm = Path(a.asm)
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)

    funcs = []
    for line in (asm / "functions.tsv").read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        addr, size, dem, mangled, first, last, n = line.split("\t")
        funcs.append({"addr": int(addr, 16), "size": int(size), "dem": dem,
                      "mangled": mangled, "n": int(n)})
    funcs.sort(key=lambda f: f["addr"])

    insns: dict[int, list[tuple[int, str, str]]] = {}
    with open_instructions(asm) as fh:
        for line in fh:
            row = json.loads(line)
            insns.setdefault(row["f"], []).append((row["a"], row["m"], row["o"]))
    for v in insns.values():
        v.sort()

    manifest = []
    emitted: set[int] = set()
    for bank_idx in range(0, len(funcs), a.per_bank):
        bank = funcs[bank_idx:bank_idx + a.per_bank]
        name = f"bank_{bank_idx // a.per_bank:04d}.c"
        total = 0
        lines = [
            f"/* libyoyo.so 覆盖卡组 {bank_idx // a.per_bank:04d}",
            f" * 函数 {bank[0]['addr']:#x}..{bank[-1]['addr']:#x}，共 {len(bank)} 个；",
            " * 级别: 原始覆盖（锚点全挂，语义未钉）",
            " * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl",
            " */",
            "",
        ]
        for f in bank:
            rows = insns.get(f["addr"], [])
            # 337 addresses are shared by alias symbols; the instructions belong to
            # the address once, so the second symbol is recorded as an alias and emits
            # no anchors (otherwise the anchor total exceeds the instruction total).
            if f["addr"] in emitted:
                lines.append(f"/* ── FUNC {f['addr']:#x} · {f['dem']} · alias of the symbol above · insn=0 */")
                lines.append("")
                continue
            emitted.add(f["addr"])
            total += len(rows)
            lines.append(f"/* ── FUNC {f['addr']:#x} · {f['dem']} · size={f['size']} · insn={len(rows)} */")
            for addr, mnem, ops in rows:
                lines.append(f"/* @0x{addr:x} {mnem} {ops} */" if ops else f"/* @0x{addr:x} {mnem} */")
            lines.append("")
        (out / name).write_text("\n".join(lines), encoding="utf-8")
        manifest.append((name, len(bank), total))

    with open(out / "manifest.tsv", "w", encoding="utf-8") as fh:
        for name, nfunc, ninsn in manifest:
            fh.write(f"{name}\t{nfunc}\t{ninsn}\n")
    print(f"banks={len(manifest)} functions={len(funcs)} anchors={sum(m[2] for m in manifest)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
