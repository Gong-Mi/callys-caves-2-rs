#!/usr/bin/env python3
"""What "reverse the whole .so" actually means: the reachable set from the game's
own entry points.

9,623 functions is the wrong denominator: most of .text is GL / audio / Box2D /
ads, which the game never calls. The honest target is the transitive closure of
direct calls from the runner's entry points plus the opcode table.

    python3 scripts/reachability.py --root reconstruction/reverse-v1
"""
from __future__ import annotations

import argparse
import collections
import json
import lzma
import re
import sys
from pathlib import Path

BL = re.compile(r"^(?:0x([0-9a-f]+)|([0-9a-f]+))\s*<")

ROOTS = [
    "_Z10DoTheWorkv",
    "_Z9VM::Exec",              # prefix match, resolved below
    "_Z9ExecuteItP9CInstanceS0_P5CCodeP6RValuei",
    "_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei",
    "_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_",
    "_Z20Perform_Event_ObjectP9CInstanceS0_iii",
    "_Z13Perform_EventP9CInstanceS0_ii",
    "_Z15Command_DestroyP9CInstance",
    "_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_",
]


def open_insns(asm: Path):
    plain = asm / "instructions.jsonl"
    if plain.exists():
        return open(plain, encoding="utf-8")
    return lzma.open(asm / "instructions.jsonl.xz", "rt", encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="reconstruction/reverse-v1")
    ap.add_argument("--top", type=int, default=25)
    a = ap.parse_args()

    root = Path(a.root)
    asm = root / "asm"

    spans: list[tuple[int, int, str, str]] = []
    for line in (asm / "functions.tsv").read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        addr, size, dem, mangled, *_ = line.split("\t")
        spans.append((int(addr, 16), int(size), dem.split("(")[0], mangled))
    spans.sort()
    by_start = {s[0]: s for s in spans}

    def owner(addr: int):
        for start, size, dem, mangled in spans:
            if start <= addr < start + size:
                return start
            if start > addr:
                break
        return None

    # direct-call edges
    succ: dict[int, set[int]] = collections.defaultdict(set)
    with open_insns(asm) as fh:
        for line in fh:
            row = json.loads(line)
            if row["m"] not in ("bl", "blx"):
                continue
            m = BL.match(row["o"])
            if not m:
                continue
            target = int(m.group(1) or m.group(2), 16)
            src, dst = owner(row["a"]), owner(target)
            if src is not None and dst is not None and src != dst:
                succ[src].add(dst)

    # roots: mangled exact match or prefix (VM::Exec has a long signature)
    roots = set()
    for start, size, dem, mangled in spans:
        for r in ROOTS:
            if mangled == r or mangled.startswith(r):
                roots.add(start)
    # every Do* handler is reachable through the opcode table (indirect), so root them
    for start, size, dem, mangled in spans:
        if re.match(r"^Do[A-Z]", dem) or dem in ("ExecuteIt", "VM::Exec", "VM::ExecRelease", "VM::ExecDebug"):
            roots.add(start)

    seen, queue = set(roots), collections.deque(roots)
    while queue:
        cur = queue.popleft()
        for nxt in succ.get(cur, ()):
            if nxt not in seen:
                seen.add(nxt)
                queue.append(nxt)

    carded = {p.stem.lower() for p in (root / "cards").glob("*.c")}

    def norm(x: str) -> str:
        return re.sub(r"[^A-Za-z0-9]+", "_", x).strip("_").lower()

    carded |= {norm(c) for c in carded}

    def is_carded(name: str) -> bool:
        t = norm(name)
        last = t.split("_")[-1]
        return any(t == c or t.endswith(c) or c.endswith(t) or c.endswith("_" + last) for c in carded)

    reach = [by_start[s] for s in seen if s in by_start]
    todo = [f for f in reach if not is_carded(f[2])]
    todo.sort(key=lambda f: -f[1])

    insn_total = sum(1 for _ in open_insns(asm))
    reach_bytes = sum(f[1] for f in reach)
    todo_bytes = sum(f[1] for f in todo)

    print(f"全库函数 {len(spans)}  指令 {insn_total}")
    print(f"从入口可达 {len(reach)} 个函数（{reach_bytes} B ≈ {reach_bytes // 4} 条指令）")
    print(f"其中已出卡 {len(reach) - len(todo)}，未出卡 {len(todo)}（{todo_bytes} B ≈ {todo_bytes // 4} 条指令）")
    print(f"\n未出卡里最大的 {a.top} 个：")
    for _start, size, dem, _mangled in todo[:a.top]:
        print(f"  {size:7d} B  0x{_start:x}  {dem}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
