#!/usr/bin/env python3
"""Oracle for CSprite::PreciseCollisionLine @0x1e52bc.

Signature from the call site at CInstance::Collision_Line @0x195288 (softfp):

    PreciseCollisionLine(frame, rect*, x:int, y:int, sx, sy, angle,
                         x1:int, y1:int, x2:int, y2:int)

Differential against our mask line walk (half-pixel steps, floor mapping).
"""
import math
import random
import struct

import precise_oracle as O
from unicorn.arm_const import *

random.seed(23)


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def mask_px(m, x, y):
    return m[y][x] if 0 <= y < len(m) and 0 <= x < len(m[0]) else 0


def our_line(mask, x, y, sx, sy, ang, x1, y1, x2, y2):
    rad = f32(f32(ang) * f32(math.pi) / 180.0)
    c, s = f32(math.cos(rad)), f32(math.sin(rad))
    length = math.hypot(x2 - x1, y2 - y1)
    steps = max(1, min(4000, math.ceil(length * 2.0)))
    for i in range(steps + 1):
        t = i / steps
        wx = x1 + (x2 - x1) * t
        wy = y1 + (y2 - y1) * t
        dx, dy = f32(wx - int(x)), f32(wy - int(y))
        rx = f32(f32(dx * c) - f32(dy * s))
        ry = f32(f32(dx * s) + f32(dy * c))
        if mask_px(mask, math.floor(f32(rx / f32(sx))), math.floor(f32(ry / f32(sy)))):
            return 1
    return 0


class LineOracle(O.Oracle):
    def line(self, spr, frame, rect, x, y, sx, sy, ang, x1, y1, x2, y2):
        u = self.uc
        u.reg_write(UC_ARM_REG_SP, O.STACK + O.STACK_SIZE - 0x100)
        u.reg_write(UC_ARM_REG_LR, O.SENTINEL)
        u.reg_write(UC_ARM_REG_R0, spr)
        u.reg_write(UC_ARM_REG_R1, frame & 0xffffffff)
        u.reg_write(UC_ARM_REG_R2, rect)
        u.reg_write(UC_ARM_REG_R3, x & 0xffffffff)
        sp = O.STACK + O.STACK_SIZE - 0x100
        stack = [y & 0xffffffff, self._f32(sx), self._f32(sy), self._f32(ang),
                 x1 & 0xffffffff, y1 & 0xffffffff, x2 & 0xffffffff, y2 & 0xffffffff]
        u.mem_write(sp, b''.join(struct.pack('<I', v) for v in stack))
        u.emu_start(0x1e52bc, O.SENTINEL, timeout=5_000_000)
        if u.reg_read(UC_ARM_REG_PC) != O.SENTINEL:
            raise RuntimeError('line: did not return')
        return u.reg_read(UC_ARM_REG_R0)


def main():
    o = LineOracle()
    bad = 0
    for t in range(80):
        w = h = 8
        m = [[1 if random.random() < 0.5 else 0 for _ in range(w)] for _ in range(h)]
        for x in range(w):
            m[0][x] = m[h - 1][x] = 1
        x, y = random.randint(-4, 4), random.randint(-4, 4)
        ang = random.choice([0.0, 0.0, 90.0, -90.0, 45.0])
        sx = random.choice([1.0, 2.0, 0.5])
        sy = random.choice([1.0, 2.0, 0.5])
        x1, y1 = random.randint(-8, 12), random.randint(-8, 12)
        x2, y2 = random.randint(-8, 12), random.randint(-8, 12)
        spr = o.sprite(w, h, m)
        rect = o.rect(-16, -16, 24, 24)
        got = 1 if o.line(spr, 0, rect, x, y, sx, sy, ang, x1, y1, x2, y2) else 0
        want = our_line(m, x, y, sx, sy, ang, x1, y1, x2, y2)
        if got != want:
            bad += 1
            if bad <= 6:
                print('MISMATCH oracle=%d ours=%d x=%d y=%d s=(%.1f,%.1f) ang=%.0f line=(%d,%d)-(%d,%d)'
                      % (got, want, x, y, sx, sy, ang, x1, y1, x2, y2))
    print('line cases=80 mismatches=%d' % bad)


if __name__ == '__main__':
    main()
