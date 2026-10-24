#!/usr/bin/env python3
"""Oracle for CSprite::PreciseCollisionPoint @0x1e4a30.

Signature recovered from CInstance::Collision_Point @0x1946e8 (softfp):

    PreciseCollisionPoint(frame, rect*, x:int, y:int, sx, sy, angle, px:int, py:int)

The GML builtin collision_point -> F_CollisionPoint -> Command_CollisionPoint
-> CInstance::Collision_Point -> this function.

The differential below compares the runner with our mask_hit mapping:
    local = (c*dx - s*dy, s*dx + c*dy) / scale + origin, truncated.
"""
import math
import random
import struct
import sys

import precise_oracle as O
from unicorn.arm_const import *

random.seed(11)


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def mask_px(m, x, y):
    return m[y][x] if 0 <= y < len(m) and 0 <= x < len(m[0]) else 0


def our_point(mask, x, y, sx, sy, ang, px, py):
    rad = f32(f32(ang) * f32(math.pi) / 180.0)
    c, s = f32(math.cos(rad)), f32(math.sin(rad))
    dx, dy = f32(px - int(x)), f32(py - int(y))
    rx = f32(f32(dx * c) - f32(dy * s))
    ry = f32(f32(dx * s) + f32(dy * c))
    # collision_point floors (the runner calls floorf), unlike instance_place.
    return mask_px(mask, math.floor(f32(rx / f32(sx))), math.floor(f32(ry / f32(sy))))


class PointOracle(O.Oracle):
    def point(self, spr, frame, rect, x, y, sx, sy, ang, px, py):
        u = self.uc
        u.reg_write(UC_ARM_REG_SP, O.STACK + O.STACK_SIZE - 0x100)
        u.reg_write(UC_ARM_REG_LR, O.SENTINEL)
        u.reg_write(UC_ARM_REG_R0, spr)
        u.reg_write(UC_ARM_REG_R1, frame & 0xffffffff)
        u.reg_write(UC_ARM_REG_R2, rect)
        u.reg_write(UC_ARM_REG_R3, x & 0xffffffff)
        sp = O.STACK + O.STACK_SIZE - 0x100
        stack = [y & 0xffffffff, self._f32(sx), self._f32(sy), self._f32(ang),
                 px & 0xffffffff, py & 0xffffffff]
        u.mem_write(sp, b''.join(struct.pack('<I', v) for v in stack))
        u.emu_start(0x1e4a30, O.SENTINEL, timeout=5_000_000)
        if u.reg_read(UC_ARM_REG_PC) != O.SENTINEL:
            raise RuntimeError('point: did not return')
        return u.reg_read(UC_ARM_REG_R0)


def main():
    o = PointOracle()
    bad = 0
    for t in range(120):
        w = h = 8
        m = [[1 if random.random() < 0.5 else 0 for _ in range(w)] for _ in range(h)]
        for x in range(w):
            m[0][x] = m[h - 1][x] = 1
        x, y = random.randint(-4, 4), random.randint(-4, 4)
        ang = random.choice([0.0, 0.0, 90.0, -90.0, 45.0])
        sx = random.choice([1.0, 2.0, 0.5])
        sy = random.choice([1.0, 2.0, 0.5])
        px, py = random.randint(-8, 12), random.randint(-8, 12)
        spr = o.sprite(w, h, m)
        rect = o.rect(-16, -16, 24, 24)
        got = 1 if o.point(spr, 0, rect, x, y, sx, sy, ang, px, py) else 0
        want = our_point(m, x, y, sx, sy, ang, px, py)
        if got != want:
            bad += 1
            if bad <= 6:
                print('MISMATCH oracle=%d ours=%d x=%d y=%d sx=%.1f sy=%.1f ang=%.0f p=(%d,%d)'
                      % (got, want, x, y, sx, sy, ang, px, py))
    print('point cases=120 mismatches=%d' % bad)


if __name__ == '__main__':
    main()
