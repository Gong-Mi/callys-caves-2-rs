#!/usr/bin/env python3
"""Pin the mask base ([sprite+0x24]/+0x28) behaviour of PreciseCollisionPoint.

The collision probe computes

    local = floor((q - centre) / scale + base)

where `base` is read from the sprite at +0x24/+0x28. This script drives the
real function (0x1e4a30) with a synthetic 8x8 mask whose only solid pixel is
(2,0) and asks for the point (0,0) at scale 1:

    base_x = 0  -> the pixel at column 0 is empty      -> 0 (miss)
    base_x = 2  -> the base shifts the sample two cols -> 1 (hit)

That proves the base is an additive offset applied after the un-scale and
before the floor. What it does NOT prove is which asset field the loader
stores at +0x24; see reconstruction/contracts/collision-broad-phase.md §7.1.

Usage:  CALLY_LIBYOYO=/path/to/libyoyo.so python3 base_probe.py
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
os.environ.setdefault(
    "CALLY_LIBYOYO",
    os.path.expanduser("~/cally/oracle/libyoyo.so"),
)

import point_oracle as P  # noqa: E402


def main() -> int:
    o = P.PointOracle()
    w = h = 8
    rows = [[1 if x == 2 and y == 0 else 0 for x in range(w)] for y in range(h)]
    rect = o.rect(-16, -16, 24, 24)
    got = {}
    for base_x in (0, 2):
        spr = o.sprite(w, h, rows, base_x=base_x, base_y=0)
        got[base_x] = o.point(spr, 0, rect, 0, 0, 1.0, 1.0, 0.0, 0, 0)
    print(f"base_x=0 -> {got[0]} (want 0)")
    print(f"base_x=2 -> {got[2]} (want 1)")
    ok = got[0] == 0 and got[2] == 1
    print("base probe:", "PASS" if ok else "FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
