#!/usr/bin/env python3
"""Emit the CODE-id -> generated-function dispatch used by the C driver.

The registry is generated, not hand-maintained, so adding bodies never leaves a
silently missing case: a code id with no generated file is reported and the
registry refuses to claim it.

    python3 scripts/gen_registry.py --gen c-recon/gen --out c-recon/gen/registry.c
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

PAT = re.compile(r"^gml_(\d{4})\.c$")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--gen", required=True, type=Path)
    ap.add_argument("--out", required=True, type=Path)
    a = ap.parse_args()
    ids = sorted(int(m.group(1)) for p in a.gen.iterdir() if (m := PAT.match(p.name)))
    lines = ['#include "gml.h"', "", "int gml_dispatch(GmVM* vm, long code) {"]
    for cid in ids:
        lines.append(f"    void gml_{cid:04d}(GmVM* vm);")
    lines.append("    switch (code) {")
    for cid in ids:
        lines.append(f"        case {cid}: gml_{cid:04d}(vm); return 1;")
    lines.append("        default: return 0;")
    lines.append("    }")
    lines.append("}")
    a.out.write_text("\n".join(lines) + "\n")
    print(f"registry: {len(ids)} code ids -> {a.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
