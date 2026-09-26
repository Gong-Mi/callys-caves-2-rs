#!/usr/bin/env python3
"""Audit original FUNC names against the Scene VM builtin dispatch table.

This is an evidence inventory, not a completion claim: a name appearing in the
Rust match table may still be an explicit no-op and must be reviewed separately.
"""
import re
import sys
from pathlib import Path

from reverse_code import Reader


def original_funcs(data):
    r = Reader(data)
    lo, hi = r.chunks["FUNC"]
    count = r.u32(lo)
    out = set()
    for idx in range(count):
        pos = lo + 4 + idx * 12
        out.add(r.string(r.u32(pos)))
    return out


def rust_dispatch(path):
    text = Path(path).read_text()
    # All names in the Host::call expected-argc match are dispatch candidates.
    start = text.index("let expected_argc = match n")
    end = text.index("if let Some(exp)", start)
    return set(re.findall(r'"([A-Za-z_][A-Za-z0-9_]*)"', text[start:end]))


def main():
    root = Path(__file__).resolve().parents[1]
    asset = root / "assets/game.droid"
    source = root / "crates/core/src/ir_scene.rs"
    names = original_funcs(asset.read_bytes())
    supported = rust_dispatch(source)
    unsupported = sorted(names - supported)
    print(f"original FUNC names: {len(names)}")
    print(f"dispatch-listed names: {len(names & supported)}")
    print(f"not dispatch-listed: {len(unsupported)}")
    for name in unsupported:
        print(name)
    return 1 if unsupported else 0


if __name__ == "__main__":
    sys.exit(main())
