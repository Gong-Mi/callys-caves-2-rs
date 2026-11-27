#!/usr/bin/env python3
"""Generate a skeleton card for anonymous (stripped) code segments.

Rules this file obeys (see reconstruction/reverse-v1/METHOD.md §4):
  * an anonymous segment may only be called `anon_<addr>`;
  * its level is at most 骨架 — address + structure, never semantics;
  * what is claimed is stated, and what is not claimed is stated (no invented names).

Facts emitted per segment (all mechanically derived):
    size / instruction count / ARM or Thumb (asm/thumb_ranges*)
    in-degree + caller symbols (branch/call targets landing inside the segment)
    out-calls (bl targets leaving the segment, resolved where a symbol exists)
    whether any existing card already claims addresses inside it (must be 0)

    python3 scripts/gen_anon_skeleton.py --min-size 2048 --budget 6000 --out cards/anon_batch6.c
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


def thumb_ranges():
    rng = []
    for name in ("thumb_ranges_extra.txt", "thumb_ranges.txt"):
        p = ASM / name
        if not p.exists():
            continue
        for line in p.read_text(encoding="utf-8").splitlines():
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = re.split(r"[\s,]+", line)
            try:
                a, s = int(parts[0], 16), int(parts[1], 0)
            except (ValueError, IndexError):
                continue
            rng.append((a, a + s))
    return sorted(rng)


def resolve(fns, va):
    starts = [f[0] for f in fns]
    i = bisect.bisect_right(starts, va) - 1
    if i < 0:
        return f"0x{va:x}"
    s, size, name = fns[i]
    if s <= va < s + size:
        return name if va == s else f"{name}+{va - s:#x}"
    return f"0x{va:x}"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-size", type=int, default=2048)
    ap.add_argument("--budget", type=int, default=6000, help="max anchors in the card")
    ap.add_argument("--order", choices=("size", "indeg"), default="indeg")
    ap.add_argument("--out", default="reconstruction/reverse-v1/cards/anon_batch6.c")
    a = ap.parse_args()

    ins = load_index()
    fns = load_functions()
    thumbs = thumb_ranges()
    addrs = sorted(ins)

    claimed = set()
    for card in (RV / "cards").glob("*.c"):
        for m in ANCHOR.finditer(card.read_text(encoding="utf-8")):
            claimed.add(int(m.group(1), 16))

    rows = []
    for line in (ASM / "anon_splits.tsv").read_text(encoding="utf-8").splitlines()[1:]:
        c = line.split("\t")
        if len(c) < 4:
            continue
        start, size, parent, evidence = int(c[0], 16), int(c[1]), c[2], c[3]
        rows.append({"start": start, "size": size, "parent": parent, "evidence": evidence})
    rows.sort(key=lambda r: -r["size"])

    # in-degree from the whole index, once
    ind = collections.Counter()
    callers = collections.defaultdict(set)
    targets = [(r["start"], r["start"] + r["size"], i) for i, r in enumerate(rows)]
    for addr in addrs:
        m, ops = ins[addr]
        base, cond = re.match(r"([a-z]+)([a-z]*)", m).groups() if re.match(r"[a-z]+", m) else (m, "")
        if base not in ("bl", "b", "blx"):
            continue
        tok = (ops.split()[0] if ops else "")
        try:
            tgt = int(tok, 16)
        except ValueError:
            continue
        for s, e, i in targets:
            if s <= tgt < e and not (s <= addr < e):
                ind[i] += 1
                callers[i].add(addr)

    order = sorted(range(len(rows)),
                   key=(lambda i: -ind[i]) if a.order == "indeg" else (lambda i: -rows[i]["size"]))
    # parent extent: a segment of a huge merged block may be mid-state-machine, not a function
    parent_span = {}
    for r in rows:
        lo, hi = parent_span.get(r["parent"], (r["start"], r["start"] + r["size"]))
        parent_span[r["parent"]] = (min(lo, r["start"]), max(hi, r["start"] + r["size"]))

    picked, anchors = [], 0
    for i in order:
        r = rows[i]
        if r["size"] < a.min_size or not r["evidence"]:
            continue
        seg = [x for x in addrs if r["start"] <= x < r["start"] + r["size"]]
        if not seg:
            continue
        if any(x in claimed for x in seg):
            continue
        if anchors + len(seg) > a.budget:
            continue
        picked.append((r, seg, ind[i], sorted(callers[i])))
        anchors += len(seg)
    picked.sort(key=lambda p: p[0]["start"])

    if not picked:
        print("no candidate segments", file=sys.stderr)
        return 1

    out = []
    out.append("/* cally 逆向卡：匿名代码段骨架（asm/anon_splits.tsv 切分产物，原版 libyoyo.so，armv7）")
    out.append(f" * 节: {len(picked)} 段｜锚点 {anchors} 条｜入选条件: size≥{a.min_size} B、有入口证据、未被既有卡主张")
    out.append(" * 级别: 骨架 —— 只有地址、尺寸、ISA、入度/调用者与出调用；**没有任何语义主张**。")
    out.append(" *       这些段被 strip 掉了符号，METHOD §4 规定只能叫 anon_<addr>、不许编名字；")
    out.append(" *       段内语义要等从调用点反推或出正文卡时才升格，本卡不越过这条线。")
    out.append(" * 切分依据: asm/anon_splits.tsv（bl 直接目标 / ARM prologue / .data·.rodata 数据指针三信号）")
    out.append(" * 索引: asm/instructions.jsonl（census，Thumb 双遍解码）")
    for n, (r, seg, indeg, cs) in enumerate(picked, 1):
        is_thumb = any(lo <= r["start"] < hi for lo, hi in thumbs)
        outcalls = []
        for x in seg:
            m, ops = ins[x]
            if m.startswith("bl"):
                tok = (ops.split()[0] if ops else "")
                try:
                    t = int(tok, 16)
                except ValueError:
                    continue
                if not (r["start"] <= t < r["start"] + r["size"]):
                    outcalls.append((x, t, resolve(fns, t)))
        out.append(" *")
        out.append(f" * ══ §{n}/{len(picked)} anon_{r['start']:x}  0x{r['start']:x}..0x{r['start']+r['size']:x}  "
                   f"size {r['size']}  {len(seg)} 条｜ISA {'Thumb-2' if is_thumb else 'ARM'}｜"
                   f"入口证据 {r['evidence']}｜父块 anon_{r['parent']}")
        out.append(f" * @func 0x{r['start']:x} 0x{r['start']+r['size']:x}  size {r['size']}  {len(seg)} 条")
        plo, phi = parent_span[r["parent"]]
        if phi - plo > 16384:
            out.append(f" * ⚠ 父块 anon_{r['parent']} 是 {phi - plo:,} B 的未闭合大状态机（METHOD §4）："
                       f"段长不一定等于函数长，本段可能只是其中的一段")
        out.append(f" * 入度 {indeg}" + (
            "｜调用者: " + ", ".join(f"0x{c:x}({resolve(fns, c)})" for c in cs[:8]) + ("…" if len(cs) > 8 else "")
            if cs else "｜无外部直接调用（仅方法表/间接调用可达，未静态证明）"))
        if outcalls:
            heads = collections.Counter(sym for _, _, sym in outcalls)
            out.append(f" * 出调用 {len(outcalls)} 处 → " +
                       ", ".join(f"{k}×{v}" for k, v in heads.most_common(6)))
        else:
            out.append(" * 出调用: 无（段内无 bl 离开本段）")
        out.append(" * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open")
        out.append(" * ────────────────────────────────────────────────────────────────────────────")
        for x in seg:
            m, ops = ins[x]
            out.append(f" *   @0x{x:x} {m} {ops}".rstrip())

    path = ROOT / a.out
    path.write_text("\n".join(out) + "\n */\n", encoding="utf-8")
    print(f"{path}: {len('\n'.join(out))//1024} KB, {len(picked)} segments, {anchors} anchors")
    print("segments:", ", ".join(f"anon_{r['start']:x}({r['size']}B,indeg {i})" for r, _, i, _ in picked))
    return 0


if __name__ == "__main__":
    sys.exit(main())
