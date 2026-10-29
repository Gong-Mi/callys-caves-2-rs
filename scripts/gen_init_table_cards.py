#!/usr/bin/env python3
"""Generate reverse-v1 cards for the `Init*Functions` registration tables.

Every line of a generated card is derived from the shipped binary:
  * instructions  <- asm/instructions.jsonl (census)
  * tables        <- scripts/init_table_extract.py (CFG walk + pool/GOT resolution)
  * annotations   <- the same walk (registration calls, gate byte reads, other calls)

The generator refuses to run if the three control tables stop matching the values that
were established independently (InitYoYoFunctions card, OPS-NOTES for InitDataStructures
and InitMath) — a silently-broken extractor must not be able to mint cards.

    python3 scripts/gen_init_table_cards.py [--write]
"""
from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import init_table_extract as X   # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
CARDS = ROOT / "reconstruction/reverse-v1/cards"
ASM = ROOT / "reconstruction/reverse-v1/asm"
IR = ROOT / "crates/core/src/generated/full_ir.json"

GROUPS = {
    "InitTables_Core.c": [
        "InitGMLFunctions", "InitDataStructuresFunctions", "InitMathFunctions", "InitMiscFunctions",
    ],
    "InitTables_Draw3D.c": [
        "InitGraphicFunctions", "Init3DFunctions", "InitBufferFunctions",
        "InitBufferVertexFunctions", "InitShaderFunctions",
    ],
    "InitTables_Resource.c": [
        "InitResourceFunctions", "InitParticlesFunctions", "InitFileFunctions",
    ],
    "InitTables_InputAction.c": [
        "InitInteractionFunctions", "InitActionFunctions", "InitGamepadFunctions",
        "InitMetroFunctions", "InitPushFunctions", "InitIAPFunctions",
    ],
    "InitTables_System.c": [
        "InitSoundFunctions", "InitSteamFunctions", "InitNetworkingFunctions",
        "InitJavaScriptFunctions", "InitPhysicsFunctions", "InitGameFunctions",
    ],
}

# controls: values that were established before this batch, independently of this generator
CONTROLS = {
    "InitYoYoFunctions": {"registrations": 385, "distinct_fns": 152, "flag": {0: 183, 1: 202}},
    "InitDataStructuresFunctions": {"registrations": 130,
                                    "argc": {-1: 3, 0: 5, 1: 45, 2: 30, 3: 19, 4: 9, 5: 10, 6: 6, 8: 3},
                                    "flag": {1: 130}},
    "InitMathFunctions": {"registrations": 117,
                          "argc": {-1: 6, 0: 4, 1: 62, 2: 18, 3: 17, 4: 5, 5: 1, 6: 4}},
}


def game_builtin_names() -> set[str]:
    d = json.load(open(IR))
    names = set()
    for code in d["codes"]:
        for ins in code.get("instructions", []):
            if ins.get("op") == "call" and ins.get("name"):
                names.add(ins["name"])
    return names


def fam(name: str) -> str:
    return name.split("_")[0] if "_" in name else name


def hist_line(rows, key) -> str:
    c = collections.Counter(X.sg(r[key]) for r in rows)
    return " ".join(f"{'?' if k is None else k}:{v}" for k, v in
                    sorted(c.items(), key=lambda kv: (kv[0] is None, kv[0])))


def analyse(name: str, start: int, size: int, ins, fns, game: set[str]) -> dict:
    rows, w = X.extract(XIMG, ins, fns, start, size)
    names = [r["name"] for r in rows if r["name"]]
    in_range = [a for a in sorted(ins) if start <= a < start + size]
    unreached = [a for a in in_range if a not in w.visited]
    notes: dict[int, str] = {}
    for r in rows:
        tag = "?" if None in (r["name"], r["fn_addr"], r["argc"], r["flag"]) else ""
        notes[r["call_addr"]] = (
            f"注册 #{r['idx']} {r['name'] or '?'} → {r['fn_symbol']} "
            f"argc={X.sg(r['argc'])} flag={X.sg(r['flag'])}{(' ⚠ ' + tag) if tag else ''}"
        )
    for addr, note in w.observations:
        notes.setdefault(addr, note)
    for addr in in_range:
        mnem, ops = ins[addr]
        m, cond = X.split_mnem(mnem)
        if m == "b" and cond and addr not in notes:
            notes[addr] = f"条件跳转 → {ops.split()[0]}"
        elif m == "bl" and addr not in notes:
            tgt = X.num(ops.split()[0]) if ops else None
            notes[addr] = f"调用 {X.resolve(fns, tgt)}"
    branches = [(a, ins[a][0], ins[a][1]) for a in in_range
                if X.split_mnem(ins[a][0])[0] == "b" and X.split_mnem(ins[a][0])[1]]
    unknown = [r for r in rows if None in (r["name"], r["fn_addr"], r["argc"], r["flag"])]
    return {
        "name": name, "start": start, "end": start + size, "size": size,
        "rows": rows, "w": w, "notes": notes, "branches": branches, "unknown": unknown,
        "addrs": in_range,
        "instr": len(in_range), "reached": len(in_range) - len(unreached),
        "pool": len(unreached),
        "distinct_names": len(set(names)), "distinct_fns": len({r["fn_addr"] for r in rows}),
        "argc": hist_line(rows, "argc"), "flag": hist_line(rows, "flag"),
        "game": sorted(n for n in names if n in game),
        "families": collections.Counter(fam(n) for n in names),
    }


def section(a: dict, idx: int, total: int) -> str:
    out = []
    out.append(" *")
    out.append(f" * ══ §{idx}/{total} {a['name']}  0x{a['start']:x}..0x{a['end']:x}  "
               f"size {a['size']}  {a['instr']} 条（{a['reached']} 条指令 + {a['pool']} 个池字）══")
    out.append(f" * @func 0x{a['start']:x} 0x{a['end']:x}  size {a['size']}  {a['instr']} 条")
    if a["rows"]:
        out.append(f" * 注册 {len(a['rows'])} 条｜唯一名 {a['distinct_names']}｜唯一函数指针 {a['distinct_fns']}"
                   f"｜argc {a['argc']}｜flag {a['flag']}")
        first, last = a["rows"][0], a["rows"][-1]
        out.append(f" * 首条 #{first['idx']} {first['name']}（0x{first['call_addr']:x}）→ 末条 #{last['idx']} "
                   f"{last['name']}（0x{last['call_addr']:x}）")
        fams = " ".join(f"{k}×{v}" for k, v in a["families"].most_common(8))
        out.append(f" * 名字族（前 8）: {fams}")
        out.append(f" * 游戏实际调用的 99 个内建里落在本表: {len(a['game'])} 个"
                   + ("（" + ", ".join(a["game"]) + "）" if a["game"] else ""))
    else:
        out.append(" * 本函数不注册任何内建函数：它是 init 派发器（逐条 bl 下面列出的 Init*），"
                   "注册全部由被调方完成。")
    if a["branches"]:
        out.append(f" * 条件跳转 {len(a['branches'])} 处: "
                   + ", ".join(f"0x{x[0]:x}({x[1]})" for x in a["branches"][:10])
                   + ("…" if len(a["branches"]) > 10 else ""))
    out.append(f" * 表: asm/init-tables/init-{a['name']}.tsv（idx/调用地址/name/fn/argc/flag 逐条）")
    if a["unknown"]:
        out.append(" * 未定（open）: " + ", ".join(
            f"#{r['idx']}@0x{r['call_addr']:x}({r['name'] or '?'})" for r in a["unknown"][:12])
            + (f" 等 {len(a['unknown'])} 条" if len(a["unknown"]) > 12 else "")
            + " —— 实参来自运行期全局值或共享尾未解，本卡不猜")
    else:
        out.append(" * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）")
    out.append(" * ────────────────────────────────────────────────────────────────────────────")
    for addr in a["addrs"]:
        mnem, ops = XINS[addr]
        note = a["notes"].get(addr)
        out.append(f" *   @0x{addr:x} {mnem} {ops}".rstrip() + (f"   —— {note}" if note else ""))
    return "\n".join(out)


def main() -> int:
    global XIMG, XINS
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()

    so = next((p for p in X.SO_CANDIDATES if p.exists()), None)
    if so is None:
        print("libyoyo not found", file=sys.stderr)
        return 2
    XIMG = X.Image(so)
    XINS = X.load_instructions()
    fns = X.load_functions()
    game = game_builtin_names()

    by_name = {}
    for start, size, name in fns:
        by_name.setdefault(name.rstrip("()"), (start, size))

    # controls first: the generator must reproduce them before it may write anything
    ok = True
    for cname, want in CONTROLS.items():
        start, size = by_name[cname]
        rows, _ = X.extract(XIMG, XINS, fns, start, size)
        got = {"registrations": len(rows), "distinct_fns": len({r["fn_addr"] for r in rows}),
               "argc": {k: v for k, v in collections.Counter(X.sg(r["argc"]) for r in rows).items()},
               "flag": {k: v for k, v in collections.Counter(X.sg(r["flag"]) for r in rows).items()}}
        for k, v in want.items():
            if got[k] != v:
                ok = False
                print(f"CONTROL FAIL {cname}.{k}: got {got[k]} want {v}", file=sys.stderr)
    if not ok:
        print("refusing to generate: extractor no longer reproduces the control tables", file=sys.stderr)
        return 1
    print("controls OK (InitYoYo 385/152/202:183, InitDataStructures 130, InitMath 117)")

    total_rows = 0
    written = []
    for card, members in GROUPS.items():
        analyses = [analyse(n, *by_name[n], XINS, fns, game) for n in members]
        total_rows += sum(len(x["rows"]) for x in analyses)
        head = [
            f"/* cally 逆向卡：{card[:-2]} —— Init*Functions 的 GML 内建注册表（原版 libyoyo.so，armv7）",
            f" * 本卡 {len(analyses)} 节，逐节一个 @func；锚点来自 asm/instructions.jsonl（census），",
            " * 注册表来自 scripts/init_table_extract.py：CFG 走指令流，池字按 Align(PC,4)+imm 读，",
            " * GOT 槽按 .rel.dyn 的 RELATIVE/GLOB_DAT 解析，名字串按 r0 指针读，函数指针查 asm/functions.tsv。",
            " * 级别: 正文（每个函数的注册条数、名字、函数指针、argc、flag 与控制流分支逐条落锚；",
            " *        个别实参来自运行期全局字节的行在本节 open 里点名，不填猜值）",
            " * 表: reconstruction/reverse-v1/asm/init-tables/init-<Func>.tsv",
            " *",
            " * ── 控件（生成器每次重跑都先验这三条，不合即拒绝出卡）──",
            " *   InitYoYoFunctions       385 条 / 152 个函数指针 / flag 1:202 0:183  ← cards/InitYoYoFunctions.c",
            " *   InitDataStructures      130 条 / argc 1:45 2:30 3:19 5:10 4:9 6:6 0:5 8:3 -1:3 / flag 全 1 ← OPS-NOTES.md",
            " *   InitMath                117 条 / argc 1:62 2:18 3:17 -1:6 4:5 6:4 0:4 5:1 ← OPS-NOTES.md",
            " *",
            f" * 本卡节: " + "｜".join(f"§{i+1} {x['name']} 0x{x['start']:x}→{len(x['rows'])} 条"
                                    for i, x in enumerate(analyses)),
        ]
        body = "\n".join(section(x, i + 1, len(analyses)) for i, x in enumerate(analyses))
        text = "\n".join(head) + "\n" + body + "\n */\n"
        path = CARDS / card
        if a.write:
            path.write_text(text, encoding="utf-8")
            written.append((card, len(text), sum(len(x["rows"]) for x in analyses)))
        print(f"{card}: {len(text)//1024} KB, {sum(len(x['rows']) for x in analyses)} registrations")
    print(f"TOTAL registrations in cards={total_rows}")
    for w in written:
        print("wrote", w)
    return 0


if __name__ == "__main__":
    sys.exit(main())
