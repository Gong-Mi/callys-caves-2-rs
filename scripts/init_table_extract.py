#!/usr/bin/env python3
"""Extract a GML builtin registration table (Function_Add calls) from an Init*Functions body.

Why: `Init*Functions` in libyoyo.so is a straight-line list of
`Function_Add(name, fn, argc, flag)` calls. Recovering that list is what pins the
registration point of every GML builtin — and the four arguments are recoverable
from the instruction stream alone (no guessing, no symbol-name heuristics).

Method (all from the shipped binary, nothing hand-transcribed):
  * instruction stream  = reconstruction/reverse-v1/asm/instructions.jsonl (census output)
  * literal-pool words   = read from the .so at `Align(PC,4) + imm`
  * GOT slot values      = .rel.dyn / .rel.plt addends (R_ARM_RELATIVE / ABS32 / GLOB_DAT)
  * name strings         = read as C strings at the resolved pointer
  * fn pointers          = resolved to `asm/functions.tsv` symbols (nearest containing range)

Control flow is walked as a CFG with per-register merge; on a merge conflict the
register becomes unknown rather than silently keeping one arm's value. A `bl` to
anything is assumed to clobber r0-r3/r12 and preserve r4-r11.

    python3 scripts/init_table_extract.py --func InitDataStructuresFunctions
    python3 scripts/init_table_extract.py --all --out-dir reconstruction/reverse-v1/asm

Output rows (TSV): idx  call_addr  name  fn_addr  fn_symbol  argc  flag
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ASM = ROOT / "reconstruction/reverse-v1/asm"
SO_CANDIDATES = [
    Path.home() / "callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so",
    ROOT / "reconstruction/live-mem/libyoyo_armv7.so",
]
FUNCTION_ADD = 0xCDF84          # _Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib
IND = "int32"                    # symbolic register value: python int, or None (unknown)


class Image:
    def __init__(self, path: Path) -> None:
        from elftools.elf.elffile import ELFFile

        self.fh = open(path, "rb")
        self.elf = ELFFile(self.fh)
        self.segments = []
        for seg in self.elf.iter_segments():
            if seg["p_type"] != "PT_LOAD":
                continue
            self.segments.append((seg["p_vaddr"], seg["p_vaddr"] + seg["p_filesz"], seg["p_offset"]))
        self.relocs: dict[int, int] = {}
        self.symtab: list[tuple[int, str]] = []
        dynsym = self.elf.get_section_by_name(".dynsym")
        if dynsym is not None:
            for s in dynsym.iter_symbols():
                self.symtab.append((s["st_value"] & ~1, s.name))
        for name in (".rel.dyn", ".rel.plt"):
            sec = self.elf.get_section_by_name(name)
            if sec is None:
                continue
            for rel in sec.iter_relocations():
                rtype = rel["r_info_type"]
                slot = rel["r_offset"]
                if rtype in (21, 22):            # GLOB_DAT / JUMP_SLOT: target is the symbol
                    target = 0
                    if dynsym is not None and rel["r_info_sym"] < dynsym.num_symbols():
                        target = dynsym.get_symbol(rel["r_info_sym"])["st_value"] & ~1
                    self.relocs[slot] = target
                elif rtype == 2:                 # ABS32
                    self.relocs[slot] = rel["r_addend"] if rel.is_RELA() else (self.u32(slot) or 0)
                elif rtype == 23:                # RELATIVE
                    self.relocs[slot] = rel["r_addend"] if rel.is_RELA() else (self.u32(slot) or 0)
        self.symbols = []
        sym = self.elf.get_section_by_name(".dynsym")
        if sym is not None:
            for s in sym.iter_symbols():
                if s["st_info"]["type"] == "STT_FUNC" and s["st_value"]:
                    self.symbols.append((s["st_value"] & ~1, s.name))
        self.symbols.sort()

    def read(self, va: int, n: int) -> bytes | None:
        for lo, hi, off in self.segments:
            if lo <= va and va + n <= hi:
                self.fh.seek(off + (va - lo))
                return self.fh.read(n)
        return None

    def u32(self, va: int) -> int | None:
        b = self.read(va, 4)
        return int.from_bytes(b, "little") if b and len(b) == 4 else None

    def cstr(self, va: int, limit: int = 128) -> str | None:
        out = b""
        while len(out) < limit:
            b = self.read(va + len(out), 1)
            if not b:
                return None
            if b == b"\x00":
                try:
                    return out.decode("utf-8")
                except UnicodeDecodeError:
                    return None
            out += b
        return None

    def sym_at(self, va: int) -> str | None:
        for addr, name in self.symbols:
            if addr == va:
                return name
        return None


def load_instructions() -> dict[int, tuple[str, str]]:
    rows: dict[int, tuple[str, str]] = {}
    with open(ASM / "instructions.jsonl", encoding="utf-8") as fh:
        for line in fh:
            r = json.loads(line)
            rows[r["a"]] = (r["m"], r.get("o", ""))
    return rows


def parse_ops(ops: str) -> list[str]:
    out, depth, cur = [], 0, ""
    for ch in ops:
        if ch in "[{":
            depth += 1
        elif ch in "]}":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
            continue
        cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def num(tok: str) -> int | None:
    tok = tok.strip().lstrip("#").rstrip("!")
    try:
        if tok.startswith("-"):
            return -int(tok[1:], 0)
        return int(tok, 0)
    except ValueError:
        return None


MEM = re.compile(r"^\[([^,\]]+)(?:,\s*([^\]]+?))?(?:,\s*lsl\s*#?(\d+))?\]$")

CONDS = {"eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "al"}
BASES = (
    "movw", "movt", "mov", "mvn", "addw", "add", "subw", "sub", "rsb", "and", "orr", "eor", "bic",
    "lsl", "lsr", "asr", "ror", "cmp", "cmn", "tst", "teq", "ldrsb", "ldrsh", "ldrd", "ldrb", "ldrh",
    "ldr", "strd", "strb", "strh", "str", "push", "pop", "stmdb", "stm", "ldmia", "ldm", "blx", "bl",
    "bx", "b", "mul", "mla", "umull", "smull", "sdiv", "udiv", "nop", "it", "adr",
)


def split_mnem(m: str) -> tuple[str, str]:
    """`popeq` -> ('pop','eq'); `movs` -> ('mov','s'); `bne` -> ('b','ne')."""
    for base in BASES:
        if m == base:
            return base, ""
        if m.startswith(base):
            rest = m[len(base):]
            if rest in CONDS:
                return base, rest
            if rest == "s" or (rest.startswith("s") and rest[1:] in CONDS):
                return base, rest
    return m, ""


class Walker:
    def __init__(self, img: Image, ins: dict[int, tuple[str, str]], lo: int, hi: int) -> None:
        self.img, self.ins, self.lo, self.hi = img, ins, lo, hi
        self.calls: list[tuple[int, dict[str, int | None]]] = []
        self.saves: list[dict[str, int | None]] = []
        self.observations: list[tuple[int, str]] = []   # (addr, note) for card prose
        self.unknown_reads = 0
        self.conflicts = 0

    # -- value helpers -------------------------------------------------
    def slot(self, va: int | None) -> int | None:
        if va is None:
            return None
        if va in self.img.relocs:
            return self.img.relocs[va]
        return self.img.u32(va)

    def merge(self, old: dict[str, int | None] | None, new: dict[str, int | None]) -> tuple[dict[str, int | None], bool]:
        """Join two incoming states.

        `None` means "not recovered", not a value: an unknown never contradicts a known
        one, so a concrete value wins over None. Two *concrete* values that disagree are
        a real conflict and the register is forgotten rather than picking one arm.
        """
        if old is None:
            return dict(new), True
        changed = False
        out = dict(old)
        for k, v in new.items():
            cur = out.get(k, "absent")
            if cur == "absent":
                out[k] = v
                changed = True
            elif cur == v:
                continue
            elif cur is None:
                out[k] = v
                changed = True
            elif v is None:
                continue
            else:
                out[k] = None      # two different concrete values: forget, do not pick one
                self.conflicts += 1
                changed = True
        return out, changed

    def step(self, addr: int, regs: dict[str, int | None]) -> tuple[dict[str, int | None], str | None]:
        """Apply one instruction. Returns (new_regs, next_kind) where next_kind in
        {None (fallthrough), 'ret'} — branch targets are handled by the caller.

        Conditional mnemonics are normalized (`popeq` -> base `pop` + cond `eq`) and
        tracked optimistically: a conditionally executed instruction is applied as if
        it ran. The alternative (clobbering its first operand because the suffix was
        not recognized) is what produced the first batch of unresolved rows.
        """
        raw, ops = self.ins[addr]
        m, cond = split_mnem(raw)
        a = parse_ops(ops) if ops else []
        r = dict(regs)
        if m in ("mov", "movw", "movt", "mvn") and len(a) == 2:
            dst = a[0]
            if m == "mvn":
                v = num(a[1])
                r[dst] = None if v is None else (~v) & 0xFFFFFFFF
            elif m == "movw":
                v = num(a[1])
                r[dst] = None if v is None else (v & 0xFFFF) | ((r.get(dst) or 0) & 0xFFFF0000)
            elif m == "movt":
                v = num(a[1])
                r[dst] = None if v is None else ((v & 0xFFFF) << 16) | ((r.get(dst) or 0) & 0xFFFF)
            else:
                v = num(a[1])
                if v is not None:
                    r[dst] = v
                elif a[1] in r:
                    r[dst] = r[a[1]]
                elif a[1] == "pc":
                    r[dst] = addr + 8
                else:
                    r[dst] = None
            return r, None
        if m in ("add", "addw", "sub", "subw", "rsb") and len(a) >= 3:
            dst, s1, s2 = a[0], a[1], a[2]
            base = addr + 8 if s1 == "pc" else (r.get(s1) if s1 in r else num(s1))
            v2 = num(s2)
            if v2 is None:
                v2 = r.get(s2)
            if base is None or v2 is None:
                r[dst] = None
            else:
                r[dst] = ((base + v2) if m.startswith("add") else (base - v2)) & 0xFFFFFFFF
            return r, None
        if m.startswith("ldr") and len(a) >= 2:
            dst, mem = a[0], a[1]
            mm = MEM.match(mem)
            if not mm:
                r[dst] = None
                return r, None
            base_tok, idx_tok, shift = mm.group(1).strip(), (mm.group(2) or "").strip(), mm.group(3)
            if base_tok == "sp":
                off = num(idx_tok) if idx_tok else 0
                r[dst] = regs.get(f"sp+{off}")
                return r, None
            if base_tok == "pc":
                off = num(idx_tok) if idx_tok else 0
                va = (addr + 8 + (off or 0)) & ~3
            else:
                base = r.get(base_tok)
                if base is None:
                    r[dst] = None
                    return r, None
                if not idx_tok:
                    va = base
                elif num(idx_tok) is not None:
                    va = base + num(idx_tok)
                else:
                    idx = r.get(idx_tok)
                    if idx is None:
                        r[dst] = None
                        return r, None
                    if shift:
                        idx <<= int(shift)
                    va = (base + idx) & 0xFFFFFFFF
            v = self.slot(va)
            if v is None:
                self.unknown_reads += 1
            elif m in ("ldrb", "ldrh") and va >= 0x3A0000:
                self.observations.append((addr, f"读全局字节 @0x{va:x}"))
            r[dst] = v
            return r, None
        if m.startswith("str") and len(a) >= 2:
            mm = MEM.match(a[1])
            if mm and mm.group(1).strip() == "sp":
                off = num(mm.group(2)) if mm.group(2) else 0
                r[f"sp+{off}"] = r.get(a[0])
            return r, None
        if m in ("push", "stmdb", "stm"):
            self.saves.append({k: r.get(k) for k in re.findall(r"r\d+|lr", ops)})
            return r, None
        if m in ("pop", "ldmia", "ldm"):
            if "pc" in ops:
                # `pop {... pc}` returns; a *conditional* one only returns on the taken
                # path, so the fallthrough must keep its registers (restoring here is
                # what wiped r4 and made half of Init3D's fn pointers unresolvable).
                return r, ("ret" if not cond else None)
            saved = self.saves.pop() if self.saves else {}
            for k in re.findall(r"r\d+", ops):
                r[k] = saved.get(k)
            return r, None
        if m == "blx":
            for k in ("r0", "r1", "r2", "r3", "r12"):
                r[k] = None
            return r, None
        if m in ("cmp", "cmn", "tst", "teq", "it", "nop"):
            return r, None
        if m == "bl":
            target = num(a[0].split()[0]) if a else None
            if target == FUNCTION_ADD:
                self.calls.append((addr, {k: r.get(k) for k in ("r0", "r1", "r2", "r3")}))
            for k in ("r0", "r1", "r2", "r3", "r12"):
                r[k] = None
            return r, None
        if m == "b" and a and num(a[0].split()[0]) == FUNCTION_ADD:
            # tail call after the epilogue: Function_Add returns straight to our caller
            self.calls.append((addr, {k: r.get(k) for k in ("r0", "r1", "r2", "r3")}))
            return r, "ret"
        if m in ("bx", "b"):
            if m == "bx":
                return r, "ret"
            return r, None
        if m.startswith("v") or m in ("mul", "mla", "umull", "smull", "sdiv", "udiv", "and", "orr", "eor", "bic",
                                      "lsl", "lsr", "asr", "ror"):
            if a and re.fullmatch(r"r\d+", a[0]):
                r[a[0]] = None
            return r, None
        if a and re.fullmatch(r"r\d+", a[0]):
            r[a[0]] = None
        return r, None

    def run(self) -> None:
        state: dict[int, dict[str, int | None]] = {}
        work = [(self.lo, {f"r{i}": None for i in range(13)})]
        visits = 0
        self.visited: set[int] = set()
        while work:
            addr, regs = work.pop()
            while True:
                if not (self.lo <= addr < self.hi):
                    break
                if addr in self.ins is False:
                    break
                old = state.get(addr)
                merged, changed = self.merge(old, regs)
                state[addr] = merged
                if old is not None and not changed:
                    break
                visits += 1
                self.visited.add(addr)
                if visits > 200000:
                    raise RuntimeError("CFG walk did not converge")
                m, ops = self.ins[addr]
                base, cond = split_mnem(m)
                a = parse_ops(ops) if ops else []
                newregs, kind = self.step(addr, merged)
                state[addr] = newregs
                if kind == "ret":
                    break
                if base == "b" and a:
                    lit = num(a[0].split()[0])
                    if not cond:                      # unconditional: follow in-function only
                        if lit is None or not (self.lo <= lit < self.hi):
                            break
                        addr = lit
                        regs = newregs
                        continue
                    work.append((addr + 4, newregs))   # conditional: both successors
                    if lit is not None and self.lo <= lit < self.hi:
                        work.append((lit, newregs))
                    break
                addr += 4
                regs = newregs


def load_functions() -> list[tuple[int, int, str]]:
    rows = []
    for line in (ASM / "functions.tsv").read_text(encoding="utf-8").splitlines():
        c = line.split("\t")
        if len(c) >= 3:
            rows.append((int(c[0], 16), int(c[1]), c[2]))
    rows.sort()
    return rows


def resolve(fns: list[tuple[int, int, str]], va: int | None) -> str:
    if va is None:
        return "?"
    for start, size, name in fns:
        if start == va:
            return name
        if start <= va < start + size:
            return f"{name}+{va - start:#x}"
    return f"0x{va:x}"


def extract(img, ins, fns, start: int, size: int) -> tuple[list[dict], Walker]:
    w = Walker(img, ins, start, start + size)
    w.run()
    # One registration per call site is the normal shape; a shared tail entered with
    # different arguments yields several. Visits through arms whose registers we could
    # not recover are not extra registrations — they are the same site seen blind, so
    # resolved snapshots win and an unresolved one is kept only if nothing resolved.
    by_addr: dict[int, list[dict]] = {}
    for addr, args in w.calls:
        by_addr.setdefault(addr, []).append(args)
    ordered = []
    for addr in sorted(by_addr):
        uniq: dict[tuple, dict] = {}
        for args in by_addr[addr]:
            key = (args.get("r0"), args.get("r1"), args.get("r2"), args.get("r3"))
            uniq.setdefault(key, args)
        resolved = {k: v for k, v in uniq.items() if None not in k}
        kept = list(resolved.values()) if resolved else list(uniq.values())
        for args in kept:
            ordered.append((addr, args))
    rows = []
    for idx, (addr, args) in enumerate(ordered):
        name_ptr = args.get("r0")
        name = img.cstr(name_ptr) if name_ptr else None
        rows.append({
            "idx": idx,
            "call_addr": addr,
            "name": name,
            "fn_addr": args.get("r1"),
            "argc": args.get("r2"),
            "flag": args.get("r3"),
            "unknown": w.unknown_reads,
        })
    for r in rows:
        r["fn_symbol"] = resolve(fns, r["fn_addr"])
    return rows, w


def sg(v):
    if isinstance(v, int) and v > 0x7FFFFFFF:
        return v - (1 << 32)
    return v


def summarise(rows: list[dict]) -> str:
    from collections import Counter

    names = [r["name"] for r in rows]
    argc = Counter(sg(r["argc"]) for r in rows)
    flag = Counter(sg(r["flag"]) for r in rows)
    fns = {r["fn_addr"] for r in rows}
    got = sum(1 for n in names if not n)
    unk = sum(1 for r in rows if None in (r["name"], r["fn_addr"], r["argc"], r["flag"]))
    parts = [
        f"registrations={len(rows)}",
        f"distinct_names={len(set(names))}",
        f"distinct_fns={len(fns)}",
        f"unresolved_names={got}",
        f"rows_with_unknown_arg={unk}",
        "argc=" + ",".join(f"{k}:{v}" for k, v in sorted(argc.items(), key=lambda kv: (kv[0] is None, kv[0]))),
        "flag=" + ",".join(f"{k}:{v}" for k, v in sorted(flag.items(), key=lambda kv: (kv[0] is None, kv[0]))),
    ]
    return " ".join(parts)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--func", action="append", default=[], help="Init*Functions symbol name (repeatable)")
    ap.add_argument("--all", action="store_true", help="every Init*Functions symbol in functions.tsv")
    ap.add_argument("--so", default=None)
    ap.add_argument("--out-dir", default=None, help="write <func>.tsv here")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()

    so = Path(a.so) if a.so else next((p for p in SO_CANDIDATES if p.exists()), None)
    if so is None:
        print("libyoyo not found; set --so", file=sys.stderr)
        return 2

    fns = load_functions()
    ins = load_instructions()
    img = Image(so)

    if a.all:
        targets = [(n, s, z) for s, z, n in fns if re.match(r"^(?:_Z\d+)?Init[A-Za-z0-9_]*Functions", n) and "Mv" not in n]
    else:
        targets = []
        for want in a.func:
            hit = [(s, z, n) for s, z, n in fns if n == want or n.startswith(f"_{len(want)+1}{want}") or want in n]
            if not hit:
                print(f"function not found: {want}", file=sys.stderr)
                return 2
            s, z, n = hit[0]
            targets.append((n, s, z))

    out_dir = Path(a.out_dir) if a.out_dir else None
    if out_dir:
        out_dir.mkdir(parents=True, exist_ok=True)

    addrs = sorted(ins)
    import bisect

    total = 0
    summary_rows = []
    for name, start, size in sorted(targets, key=lambda t: t[1]):
        rows, w = extract(img, ins, fns, start, size)
        total += len(rows)
        lo_i = bisect.bisect_left(addrs, start)
        hi_i = bisect.bisect_left(addrs, start + size)
        instr_total = hi_i - lo_i
        reached = sum(1 for ad in addrs[lo_i:hi_i] if ad in w.visited)
        # unreached == literal-pool words (data the census decodes as instructions)?
        pools = set()
        for ad in w.visited:
            mnem, ops = ins.get(ad, ("", ""))
            if mnem in ("ldr", "ldrd") and "[pc," in ops:
                try:
                    off = int(ops.split("[pc,")[1].split("]")[0].strip().lstrip("#"), 0)
                except ValueError:
                    continue
                pools.add((ad + 8 + off) & ~3)
        unreached = [ad for ad in addrs[lo_i:hi_i] if ad not in w.visited]
        dead = [ad for ad in unreached if ad not in pools]
        unknown_rows = sum(1 for r in rows if None in (r["name"], r["fn_addr"], r["argc"], r["flag"]))
        cov = (f"instr={instr_total} reached={reached} unreached={len(unreached)}"
               f" pool_words={len(unreached) - len(dead)} dead={len(dead)}")
        print(f"== {name} 0x{start:x} size={size}  {cov}  {summarise(rows)}")
        for r in rows[:4]:
            print(f"   #{r['idx']:3} {r['name']} -> {r['fn_symbol']} argc={sg(r['argc'])} flag={sg(r['flag'])}")
        if not rows:
            print("   (no Function_Add calls recovered)")
        summary_rows.append({
            "func": name, "start": f"0x{start:x}", "size": size,
            "instr": instr_total, "reached": reached, "registrations": len(rows),
            "pool_words": len(unreached) - len(dead), "dead": len(dead),
            "unknown_rows": unknown_rows, "conflicts": w.conflicts,
            "dead_addrs": [f"0x{ad:x}" for ad in dead[:20]],
        })
        if out_dir:
            p = out_dir / f"init-{name.replace('(', '').replace(')', '')}.tsv"
            with open(p, "w", encoding="utf-8") as fh:
                fh.write("idx\tcall_addr\tname\tfn_addr\tfn_symbol\targc\tflag\n")
                for r in rows:
                    fh.write("\t".join([
                        str(r["idx"]), f"0x{r['call_addr']:x}", r["name"] or "?",
                        f"0x{r['fn_addr']:x}" if r["fn_addr"] else "?", r["fn_symbol"],
                        str(sg(r["argc"])), str(sg(r["flag"])),
                    ]) + "\n")
    print(f"TOTAL registrations={total} functions={len(targets)}")
    if a.json:
        print(json.dumps(summary_rows, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())
