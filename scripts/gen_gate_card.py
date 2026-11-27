#!/usr/bin/env python3
"""Build cards/GateBytes.c from the gate-census output.

Input: the JSON line printed by `scripts/gate_census.py <addr> ... --json`.

Rule kept from METHOD: one address is claimed by exactly one card. Sites that another
card already anchors are listed by address + owner instead of being anchored again, so
`verify_reverse_v1.py` keeps reporting `addresses_claimed_by_two_cards=0`.

    python3 scripts/gate_census.py 0x5428e8 0x755363 --json > /tmp/gate.json
    python3 scripts/gen_gate_card.py <gate.json> [--out reconstruction/reverse-v1/cards/GateBytes.c]
"""
from __future__ import annotations

import bisect
import collections
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RV = ROOT / "reconstruction/reverse-v1"
ANCHOR = re.compile(r"(?:/\*|\*)\s+@0x([0-9a-f]+) ")
TARGET_NAMES = {0x5428E8: "0x5428e8", 0x755363: "0x755363"}


def main() -> int:
    src = Path(sys.argv[1] if len(sys.argv) > 1 else "/dev/null")
    out = Path(sys.argv[3]) if len(sys.argv) > 3 else RV / "cards/GateBytes.c"
    if not src.is_file():
        print("usage: gen_gate_card.py <gate.json> [--out PATH]", file=sys.stderr)
        return 2
    txt = src.read_text(encoding="utf-8")
    hits = json.loads([l for l in txt.splitlines() if l.startswith("[")][-1])

    ins = {}
    for line in open(RV / "asm/instructions.jsonl", encoding="utf-8"):
        r = json.loads(line)
        ins[r["a"]] = (r["m"], r.get("o", ""))
    fns = sorted((int(c[0], 16), int(c[1]), c[2])
                 for c in (l.split("\t") for l in (RV / "asm/functions.tsv").read_text(encoding="utf-8").splitlines())
                 if len(c) >= 3)
    starts = [f[0] for f in fns]

    def resolve(va: int) -> str:
        i = bisect.bisect_right(starts, va) - 1
        if i < 0:
            return f"0x{va:x}"
        s, z, n = fns[i]
        return n if va == s else (f"{n}+{va-s:#x}" if s <= va < s + z else f"0x{va:x}")

    owner: dict[int, str] = {}
    for card in (RV / "cards").glob("*.c"):
        if card.name == out.name:
            continue
        for m in ANCHOR.finditer(card.read_text(encoding="utf-8")):
            owner.setdefault(int(m.group(1), 16), card.stem)

    by = collections.defaultdict(list)
    for h in hits:
        by[h["target"]].append(h)

    lines = [
        "/* cally 逆向卡：两个门字节的消费面（0x5428e8 / 0x755363）—— 原版 libyoyo.so，armv7",
        " * 方法: scripts/gate_census.py —— 按每个函数序言的 GOT 基址把 `ldr rX,[pc,#imm]` 的池字还原成槽地址，",
        " *       再用 .rel.dyn 的 RELATIVE/GLOB_DAT 目标判定「这个槽指向哪个全局」，最后按加载后紧跟的",
        " *       ldr/str 形式分读写。不按变量名或用途猜。本文件由 scripts/gen_gate_card.py 生成。",
        " * 级别: 正文（每个消费点落在具体指令上）；变量语义仍 open —— 本卡只说「谁碰它、怎么碰」，不给它编名字。",
        " * 锚点: 一个地址只由一张卡主张；已由别的卡落锚的站点这里只给地址与归属。",
        f" * 合计 {len(hits)} 个消费点。",
    ]
    for n, (t, v) in enumerate(sorted(by.items()), 1):
        kinds = collections.Counter(h["kind"] for h in v)
        wr = [h for h in v if h["kind"] == "write"]
        names = sorted({resolve(h["site"]) for h in v})
        lines += [
            " *",
            f" * ══ §{n} 0x{t:x}  消费点 {len(v)} 个（read {kinds.get('read', 0)} / write {kinds.get('write', 0)}"
            f" / 未分类 {kinds.get('?', 0)}）══",
            f" * 涉及函数 {len(names)} 个；槽 {sorted({hex(h['slot']) for h in v})}",
            " * 写点: " + (", ".join(f"0x{h['site']:x} in {resolve(h['site'])}" for h in wr)
                            if wr else "**本普查未发现写点**（可能经非 GOT 路径写入，open）"),
            " * 读点函数: " + "、".join(names[:14]) + ("…" if len(names) > 14 else ""),
        ]
        unk = [h for h in v if h["kind"] == "?"]
        if unk:
            lines.append(" * 未分类（加载后 0x20 字节内未见解引用/写回，可能只作指针传递）: "
                         + ", ".join(f"0x{h['site']:x}" for h in unk))
        lines += [" * 未主张: 变量取值域、语义、写入时机 —— open",
                  " * ────────────────────────────────────────────────────────────────────────────"]
        seen, already = set(), []
        for h in sorted(v, key=lambda x: x["site"]):
            if h["site"] in owner:
                already.append(f"0x{h['site']:x}({h['kind']},{owner[h['site']]})")
                continue
            for a in range(max(h["site"] - 8, 0), h["site"] + 0x14, 4):
                if a in ins and a not in seen and a not in owner:
                    seen.add(a)
                    m, o = ins[a]
                    note = (f"{h['kind']} 0x{t:x}（槽 0x{h['slot']:x}，在 {resolve(h['site'])}）"
                            if a == h["site"] else None)
                    lines.append(f" *   @0x{a:x} {m} {o}".rstrip() + (f"   —— {note}" if note else ""))
        if already:
            lines.append(" * 已有卡主张的站点（本卡不重复落锚）: " + ", ".join(already))

    out.write_text("\n".join(lines) + "\n */\n", encoding="utf-8")
    print(f"{out}: {sum(1 for l in lines if '@0x' in l)} anchors, "
          f"{sum(1 for v in by.values() for h in v if h['site'] in owner)} sites deferred to other cards")
    return 0


if __name__ == "__main__":
    sys.exit(main())
