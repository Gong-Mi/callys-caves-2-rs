#!/usr/bin/env python3
"""Mass-card the uncovered reachable functions at skeleton level.

Scope is the documented denominator: `scripts/reachability.py --dump` gives the
1,439 functions reachable from the game's own entry points. This generator takes the
largest ones that no card has anchored yet and emits one card of structure-grade
sections: gate bytes (GOT slot -> global), call sequence (resolved symbols), field-offset
histogram, VFP usage, plus every instruction as an anchor.

It never claims semantics for these functions — the level line says 骨架 and the section
footer lists what is open. A function is skipped if *any* of its addresses is already
claimed, so `verify_reverse_v1.py` keeps `addresses_claimed_by_two_cards=0`.

    python3 scripts/reachability.py --dump /tmp/reach.tsv
    python3 scripts/gen_func_cards.py /tmp/reach.tsv --name Reach_01 --budget 7000
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
ANCHOR = re.compile(r"(?:/\*|\*)\s+@0x([0-9a-f]+) ")
sys.path.insert(0, str(Path(__file__).resolve().parent))
import init_table_extract as X   # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("reach_tsv")
    ap.add_argument("--name", required=True)
    ap.add_argument("--budget", type=int, default=7000)
    ap.add_argument("--min-size", type=int, default=256)
    ap.add_argument("--out-dir", default=str(RV / "cards"))
    a = ap.parse_args()

    ins = {}
    for line in open(ASM / "instructions.jsonl", encoding="utf-8"):
        r = json.loads(line)
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

    owner = {}
    for card in (RV / "cards").glob("*.c"):
        for m in ANCHOR.finditer(card.read_text(encoding="utf-8")):
            owner.setdefault(int(m.group(1), 16), card.stem)

    img = X.Image(next(p for p in X.SO_CANDIDATES if p.exists()))
    rows = []
    for line in Path(a.reach_tsv).read_text(encoding="utf-8").splitlines()[1:]:
        c = line.split("\t")
        if len(c) < 3:
            continue
        rows.append((int(c[0], 16), int(c[1]), c[2]))
    rows.sort(key=lambda r: -r[1])

    def facts(lo: int, hi: int):
        base = None
        for x in range(lo, min(lo + 0x40, hi), 4):
            if x in ins and ins[x][0] == "ldr" and "[pc," in ins[x][1]:
                dst = ins[x][1].split(",")[0].strip()
                for b in range(x + 4, min(x + 0x14, hi), 4):
                    if b in ins and ins[b][0] == "add" and ins[b][1].startswith(dst + ", pc"):
                        off = X.num(ins[x][1].split("[pc,")[1].rstrip("]").strip().lstrip("#"))
                        if off is not None:
                            cand = (b + 8 + (img.u32((x + 8 + off) & ~3) or 0)) & 0xFFFFFFFF
                            if 0x3D0000 < cand < 0x3F3000:
                                base = cand
                        break
                if base:
                    break
        gates, calls, offs, vfp = [], [], collections.Counter(), 0
        for x in range(lo, min(hi, lo + hi - lo), 4):
            if x not in ins:
                continue
            m, o = ins[x]
            if m.startswith("bl"):
                try:
                    calls.append(int(o.split()[0], 16))
                except (ValueError, IndexError):
                    pass
            if m.startswith("ldr") and "[pc," in o and base:
                off = X.num(o.split("[pc,")[1].rstrip("]").strip().lstrip("#"))
                if off is not None:
                    slot = (base + (img.u32((x + 8 + off) & ~3) or 0)) & 0xFFFFFFFF
                    tg = img.relocs.get(slot)
                    if tg and tg >= 0x3A0000:
                        gates.append((x, tg))
            if m in ("ldr", "str", "ldrb", "strb", "ldrh", "strh", "ldrsb"):
                p = o.split("#")
                if len(p) == 2:
                    try:
                        offs[int(p[1].split("]")[0].split(",")[0], 0)] += 1
                    except ValueError:
                        pass
            if m.startswith("v"):
                vfp += 1
        return base, gates, calls, offs, vfp

    picked, anchors = [], 0
    for lo, size, name in rows:
        if size < a.min_size:
            continue
        hi = lo + size
        full = [x for x in range(lo, hi, 4) if x in ins]
        addrs = [x for x in full if x not in owner]
        if not addrs or anchors + len(addrs) > a.budget:
            continue
        picked.append((lo, hi, size, name, addrs, len(full) - len(addrs)))
        anchors += len(addrs)

    if not picked:
        print("no uncovered function fits the budget", file=sys.stderr)
        return 1

    lines = [
        f"/* cally 逆向卡：{a.name} —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）",
        f" * 节: {len(picked)} 个函数｜锚点 {anchors} 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）",
        " * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；",
        " *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。",
        " * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。",
        " * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn",
    ]
    for n, (lo, hi, size, name, addrs, taken) in enumerate(picked, 1):
        base, gates, calls, offs, vfp = facts(lo, hi)
        gates_txt = ", ".join(f"0x{x:x}→0x{t:x}" for x, t in gates[:8]) or "无"
        cal = collections.Counter(resolve(t) for t in calls)
        cal_txt = " / ".join(f"{k}×{v}" if v > 1 else k for k, v in cal.most_common(8)) or "无"
        off_txt = " / ".join(f"0x{k:x}×{v}" for k, v in offs.most_common(8)) or "无"
        lines += [
            " *",
            f" * ══ §{n}/{len(picked)} {name}  0x{lo:x}  size {size}  {len(addrs)} 条（0x{lo:x}..0x{hi:x}）"
            + (f"｜其中 {taken} 条已由别的卡落锚，本节不再重复" if taken else ""),
            f" * @func 0x{lo:x} 0x{hi:x}  size {size}  {len(addrs)} 条",
            " * 级别: 骨架（结构 + 锚点；语义未展开）",
            f" * GOT 基址: {hex(base) if base else '无标准序言'}",
            f" * 门字节（加载点→目标全局）: {gates_txt}",
            f" * 调用序列: {cal_txt}",
            f" * 字段偏移 top8: {off_txt}",
            f" * VFP 指令 {vfp} 条",
            " * 未主张: 形参/返回值、分支语义、字段含义 —— open",
            " * ────────────────────────────────────────────────────────────────────────────",
        ]
        for x in addrs:
            m, o = ins[x]
            lines.append(f" *   @0x{x:x} {m} {o}".rstrip())

    path = Path(a.out_dir) / f"{a.name}.c"
    path.write_text("\n".join(lines) + "\n */\n", encoding="utf-8")
    print(f"{path}: {len(picked)} functions, {anchors} anchors, "
          f"{sum(p[2] for p in picked):,} B covered")
    for lo, hi, size, name, addrs, taken in picked:
        print(f"   §{name[:48]:48} 0x{lo:x} {size:6d} B {len(addrs):5d} 条" + (f" (+{taken} 已属别卡)" if taken else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
