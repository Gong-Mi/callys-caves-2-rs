#!/usr/bin/env python3
"""Oracle table for a REAL sprite (spr_player, id 29) used by the C parity test.

The C unit test cannot synthesise sprites (its table is generated), so this
script lifts the generated frame-0 mask of sprite 29 out of
`c-recon/gen/sprites.c`, feeds exactly that mask and origin to the real
`CSprite::PreciseCollision` @0x1e4298, and prints the runner's answers for a
small angle table. `group_instance_rotation` in collision_test.c pins the same
numbers on the C side.

Two instances of the same sprite sit at (0,0); the second one is rotated. The
rects are deliberately generous: pixels outside a mask's extent always miss, so
any rect that covers the solid area gives the same verdict.
"""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
os.environ.setdefault("CALLY_LIBYOYO", os.path.expanduser("~/cally/oracle/libyoyo.so"))

import precise_oracle as P  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
SPRITES_C = os.path.join(ROOT, "c-recon", "gen", "sprites.c")
SPRITE_ID = 29  # spr_player, 32x34, origin (15,16), 18 frames


def load_sprite(path, sid):
    src = open(path, encoding="utf-8").read()
    m = re.search(r"\{ %d, (\d+), (\d+), (\d+), (\d+), (\d+), -?\d+, -?\d+, -?\d+, -?\d+, (\d+) \}" % sid, src)
    if not m:
        raise SystemExit(f"sprite {sid} not found in {path}")
    w, h, ox, oy = (int(m.group(i)) for i in range(1, 5))
    frames = int(m.group(6))
    arr_name = f"M{sid}__0"
    arr = re.search(r"static const unsigned char %s\[\] = \{(.*?)\};" % arr_name, src, re.S)
    if not arr:
        raise SystemExit(f"mask array {arr_name} not found")
    data = [int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]{2})", arr.group(1))]
    row_bytes = (w + 7) // 8
    if len(data) < row_bytes * h:
        raise SystemExit(f"mask {arr_name}: {len(data)} bytes < {row_bytes*h} expected")
    rows = []
    for y in range(h):
        row = []
        for x in range(w):
            byte = data[y * row_bytes + x // 8]
            row.append(1 if byte & (0x80 >> (x % 8)) else 0)
        rows.append(row)
    return w, h, ox, oy, frames, rows


def main() -> int:
    w, h, ox, oy, frames, rows = load_sprite(SPRITES_C, SPRITE_ID)
    print(f"sprite {SPRITE_ID}: {w}x{h} origin=({ox},{oy}) frames={frames}")
    o = P.Oracle()
    spr = o.sprite(w, h, rows, base_x=ox, base_y=oy)
    rect = o.rect(-64, -64, 64, 64)
    print("angleB -> runner")
    for ang in (0.0, 45.0, 90.0, 180.0):
        got = o.precise(spr, 0, rect, 0, 0, 1.0, 1.0, 0.0,
                        spr, 0, rect, 0, 0, 1.0, 1.0, ang)
        print(f"{ang:>6.0f} -> {got}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
