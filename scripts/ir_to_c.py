#!/usr/bin/env python3
"""Lower the numeric IR to C, one function per CODE body.

Design (M0):

* This is NOT a C re-implementation of the stack VM. Inside a basic block the
  bytecode stack is tracked symbolically, so `load x; constant 1; add; store x`
  becomes one C assignment and a call keeps its original name and argc.
* Values live across a branch are carried in named phi variables (`p<target>_<k>`),
  assigned on every incoming edge. Two edges must agree on the stack depth; a
  disagreement is refused, never guessed. This is what makes the GML idiom
  `A && B` (bf to the pushed `0`, `b` over it) emit as readable C instead of
  forcing a stack machine.
* Values are GML reals (`Val` = double) with the VM's string-reference
  encoding (pool refs are >= STRING_REF_BASE); the C host implements the same
  rule.
* Branch targets become labels, so the generated function's control flow is
  the shipped control flow.

Usage:
    python3 scripts/ir_to_c.py --ir <full_ir.json> --code 12 --out gen/gml_0012.c
    python3 scripts/ir_to_c.py --ir <full_ir.json> --all --outdir gen
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


class Refuse(Exception):
    pass


class Emitter:
    def __init__(self, code: dict):
        self.code = code
        self.lines: list[str] = []
        self.decls: list[str] = []
        self.stack: list[tuple[str, bool]] = []  # (expr, pure)
        self.phi: dict[int, list[str]] = {}       # target -> phi var names
        self.depth: dict[int, int] = {}           # target -> stack depth
        self.n = 0
        self.offset = 0
        self.dead = False

    # -- small helpers ---------------------------------------------------
    def emit(self, s: str, ind: int = 4) -> None:
        self.lines.append(" " * ind + s)

    def fresh(self, prefix: str = "v") -> str:
        self.n += 1
        return f"{prefix}{self.n}"

    def push(self, expr: str, pure: bool = True) -> None:
        self.stack.append((expr, pure))

    def pop(self, where: str) -> tuple[str, bool]:
        if not self.stack:
            raise Refuse(f"{where}: stack underflow")
        return self.stack.pop()

    def label(self, off: int) -> str:
        return f"L_{off}"

    def materialise(self, v: tuple[str, bool], where: str) -> str:
        """Make an impure expression safe to duplicate: bind it to a temporary."""
        expr, pure = v
        if pure:
            return expr
        tmp = self.fresh()
        self.decls.append(f"Val {tmp};")
        self.emit(f"{tmp} = {expr};")
        return tmp

    def bind_phi(self, target: int, where: str) -> None:
        """Assign every live stack slot into the target's phi variables."""
        depth = len(self.stack)
        if target in self.depth and self.depth[target] != depth:
            raise Refuse(
                f"{where}: edges into {target} disagree on stack depth "
                f"({self.depth[target]} vs {depth})"
            )
        self.depth.setdefault(target, depth)
        names = self.phi.get(target)
        if names is None:
            names = [f"p{target}_{k}" for k in range(depth)]
            self.phi[target] = names
            self.decls.extend(f"Val {n};" for n in names)
        for k, slot in enumerate(self.stack):
            expr = self.materialise(slot, where)
            self.emit(f"{names[k]} = {expr};")

    def land(self, target: int, where: str) -> None:
        """Enter a label: adopt its phi values, binding the live stack into them.

        A label can be reached by jumps (already recorded in `depth`) and by the
        linear fall-through (only when the previous instruction did not jump
        away). Both edges write the same phi variables, so the label body reads
        one set of names regardless of how control arrived.
        """
        if target in self.depth:
            names = self.phi[target]
            if not self.dead:
                if len(self.stack) != len(names):
                    raise Refuse(
                        f"{where}: fall-through depth {len(self.stack)} != "
                        f"incoming depth {len(names)}"
                    )
                for k, slot in enumerate(self.stack):
                    expr = self.materialise(slot, where)
                    self.emit(f"{names[k]} = {expr};")
            self.stack = [(n, True) for n in names]
        else:
            self.depth[target] = len(self.stack)
            names = [f"p{target}_{k}" for k in range(len(self.stack))]
            self.phi[target] = names
            self.decls.extend(f"Val {n};" for n in names)
            for k, slot in enumerate(self.stack):
                expr = self.materialise(slot, where)
                self.emit(f"{names[k]} = {expr};")
            self.stack = [(n, True) for n in names]
        self.emit(f"{self.label(target)}: ;")
        self.dead = False

    # -- lowering --------------------------------------------------------
    def run(self) -> str:
        ins = self.code["instructions"]
        targets = {i["target"] for i in ins if i.get("target") is not None}
        for i in ins:
            self.offset = i["offset"]
            if i["offset"] in targets:
                self.land(i["offset"], f"CODE {self.code['id']}@{i['offset']}")
            elif self.dead:
                # unreachable without a label: the shipped body cannot arrive
                # here, so emitting it would only add noise
                continue
            self.instruction(i)
        # A `bf`/`b` may target the body end (skip to the function exit): give
        # that offset a real label instead of leaving a dangling goto.
        self.emit(f"{self.label(self.code['end'])}: ;")
        self.emit("return;")
        head = [
            f"/* generated from CODE {self.code['id']} ({self.code['name']}), "
            f"source start {self.code['start']}, end {self.code['end']}. */",
            "/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */",
            '#include "gml.h"',
            "",
            f"void gml_{self.code['id']:04d}(GmVM* vm) {{",
        ]
        body = [" " * 4 + d for d in self.decls] + self.lines
        return "\n".join(head + body + ["}", ""])

    def instruction(self, i: dict) -> None:
        op = i["op"]
        where = f"CODE {self.code['id']}@{i['offset']}"
        if op == "constant":
            self.push(f"VAL({i['value']!r})")
        elif op == "string":
            self.push(f"STR_REF({i['string_id']})")
        elif op == "load":
            name, sel = i["name"], i["selector"]
            if not NAME_RE.match(name):
                raise Refuse(f"{where}: field name {name!r}")
            if i["array"]:
                idx = self.pop(where)
                inst = self.pop(where)
                self.push(f"GM_READ_ARR(vm, {inst[0]}, \"{name}\", {idx[0]})")
            elif i.get("other"):
                inst = self.pop(where)
                self.push(f"GM_READ(vm, {inst[0]}, \"{name}\")", inst[1])
            else:
                self.push(f"GM_READ(vm, {sel}, \"{name}\")")
        elif op == "store":
            name, sel = i["name"], i["selector"]
            if not NAME_RE.match(name):
                raise Refuse(f"{where}: field name {name!r}")
            if i["array"]:
                idx = self.pop(where)
                inst = self.pop(where)
                val = self.pop(where)
                self.emit(f"GM_WRITE_ARR(vm, {inst[0]}, \"{name}\", {idx[0]}, {val[0]});")
            elif i.get("other"):
                # Two GMS pop variants discriminated by the value-type nibble in
                # the original wordcode (same rule as the VM): type1==2 keeps the
                # destination under the computed value, otherwise it is on top.
                nib = ((i["words_raw"][0] >> 16) & 0xFF) & 0x0F
                if nib == 2:
                    val = self.pop(where)
                    dst = self.pop(where)
                else:
                    dst = self.pop(where)
                    val = self.pop(where)
                expr = self.materialise(val, where) if not val[1] else val[0]
                self.emit(f"GM_WRITE(vm, {dst[0]}, \"{name}\", {expr});")
            else:
                val = self.pop(where)
                expr = self.materialise(val, where) if not val[1] else val[0]
                self.emit(f"GM_WRITE(vm, {sel}, \"{name}\", {expr});")
        elif op == "load_local":
            self.push(f"loc_{i['name']}")
        elif op == "store_local":
            v = self.pop(where)
            self.decls.append(f"Val loc_{i['name']};")
            self.emit(f"loc_{i['name']} = {v[0]};")
        elif op == "cast":
            v = self.pop(where)
            to = i["to"]
            if to in (0, 5):
                self.push(v[0], v[1])
            elif to == 4:
                self.push(f"BOOL({v[0]})", v[1])
            elif to == 2:
                self.push(f"TO_INT({v[0]})", v[1])
            else:
                raise Refuse(f"{where}: cast {to}")
        elif op in ("add", "sub", "mul", "div"):
            b = self.pop(where)
            a = self.pop(where)
            if op == "div":
                expr, pure = f"GM_DIV({a[0]}, {b[0]})", True
            elif op == "add":
                expr, pure = f"GM_ADD({a[0]}, {b[0]})", True
            else:
                sym = {"sub": "-", "mul": "*"}[op]
                expr, pure = f"({a[0]} {sym} {b[0]})", a[1] and b[1]
            self.push(expr, pure)
        elif op == "cmp":
            b = self.pop(where)
            a = self.pop(where)
            sym = {1: "<", 2: "<=", 3: "==", 4: "!=", 5: ">=", 6: ">"}[i["comparison"]]
            self.push(f"NUMBOOL({a[0]} {sym} {b[0]})", a[1] and b[1])
        elif op == "not":
            v = self.pop(where)
            self.push(f"NOT({v[0]})", v[1])
        elif op == "and":
            b = self.pop(where)
            a = self.pop(where)
            self.push(f"BAND({a[0]}, {b[0]})", a[1] and b[1])
        elif op == "dup":
            if not self.stack:
                raise Refuse(f"{where}: dup on empty stack")
            top = self.stack[-1]
            self.push(top[0], top[1])
        elif op in ("bf", "bt"):
            cond = self.pop(where)
            cond_expr = self.materialise(cond, where)
            self.bind_phi(i["target"], where)
            test = "!TRUTH" if op == "bf" else "TRUTH"
            self.emit(f"if ({test}({cond_expr})) goto {self.label(i['target'])};")
        elif op == "b":
            self.bind_phi(i["target"], where)
            self.emit(f"goto {self.label(i['target'])};")
            self.dead = True
        elif op == "call":
            argc = i["argc"]
            args = [self.pop(where) for _ in range(argc)]  # pops = reverse push order
            for k, a in enumerate(args):
                if not a[1]:
                    args[k] = (self.materialise(a, where), True)
            names = ", ".join(a[0] for a in args)
            self.push(f"GM_CALL(vm, \"{i['name']}\", {argc}{', ' if argc else ''}{names})")
        elif op == "popz":
            v = self.pop(where)
            if not v[1]:
                self.emit(f"(void)({v[0]});")
        elif op == "pushenv":
            sel = self.pop(where)
            sel_expr = self.materialise(sel, where)
            self.emit(f"if (!GM_PUSHENV(vm, {sel_expr})) goto {self.label(i['target'])};")
        elif op == "popenv":
            self.emit(f"if (GM_POPENV_NEXT(vm)) goto {self.label(i['target'])};")
        elif op == "exit":
            self.emit("return;")
        else:
            raise Refuse(f"{where}: unsupported op {op}")


def render(code: dict) -> str:
    return Emitter(code).run()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--ir", required=True, type=Path)
    ap.add_argument("--code", type=int, action="append", default=[])
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--out", type=Path)
    ap.add_argument("--outdir", type=Path)
    a = ap.parse_args()
    bundle = json.loads(a.ir.read_text())
    codes = {c["id"]: c for c in bundle["codes"]}
    if a.all:
        if a.outdir is None:
            raise SystemExit("--all needs --outdir")
        a.outdir.mkdir(parents=True, exist_ok=True)
        ok = 0
        refused = []
        for cid, c in sorted(codes.items()):
            try:
                text = render(c)
            except Refuse as e:
                refused.append(str(e))
                continue
            (a.outdir / f"gml_{cid:04d}.c").write_text(text)
            ok += 1
        print(f"generated {ok}/{len(codes)}; refused {len(refused)}")
        for r in refused[:20]:
            print("  REFUSED " + r)
        return 0 if not refused else 2
    if not a.code:
        raise SystemExit("need --code or --all")
    rc = 0
    for cid in a.code:
        if cid not in codes:
            raise SystemExit(f"CODE {cid} not in bundle")
        try:
            text = render(codes[cid])
        except Refuse as e:
            print(f"REFUSED {e}", file=sys.stderr)
            rc = 2
            continue
        if a.out:
            a.out.parent.mkdir(parents=True, exist_ok=True)
            a.out.write_text(text)
            print(f"{a.out}: {len(text.splitlines())} lines")
        else:
            print(text)
    return rc


if __name__ == "__main__":
    sys.exit(main())
