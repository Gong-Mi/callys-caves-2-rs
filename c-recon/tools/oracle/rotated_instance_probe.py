#!/usr/bin/env python3
"""Ground-truth probe for the ROTATED instance-vs-instance precise collision.

`CSprite::PreciseCollision` @0x1e4298 computes sin/cos per call for BOTH
sprites (degrees -> radians via the constants at 0x1e4a1c/0x1e4a20) and then
branches per pixel, so rotation is handled inside the same function — there is
no separate rotated entry point. Our hosts still fall back to the bounding box
for rotated instances (see contract 7.0), so this script records what the
runner answers instead of asserting a port result.

Case: two 8x8 sprites whose only solid pixel is (4,0), both at (0,0), boxes
covering the sprite. Unrotated they share that pixel -> hit; rotating B by 90
degrees moves the sampled pixel off the solid one -> miss. The printed table is
the answer the port must reproduce once it implements the rotated branch.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
os.environ.setdefault("CALLY_LIBYOYO", os.path.expanduser("~/cally/oracle/libyoyo.so"))

import precise_oracle as P  # noqa: E402


def main() -> int:
    o = P.Oracle()
    w = h = 8
    # Solid only at (4,0): a pixel away from the rotation centre (0,0), so a
    # 90-degree rotation moves where it lands instead of mapping to itself.
    col = [[1 if x == 4 and y == 0 else 0 for x in range(w)] for y in range(h)]
    a = o.sprite(w, h, col)
    b = o.sprite(w, h, col)
    rect = o.rect(-8, -8, 16, 16)

    rows = []
    for ang in (0.0, 45.0, 90.0, 180.0):
        got = o.precise(a, 0, rect, 0, 0, 1.0, 1.0, 0.0,
                        b, 0, rect, 0, 0, 1.0, 1.0, ang)
        rows.append((ang, got))
        print(f"angleB={ang:>5.0f} -> {got}")
    ok = rows[0][1] == 1 and any(g != rows[0][1] for _, g in rows[1:])
    print("rotated instance probe:", "PASS" if ok else "FAIL")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
