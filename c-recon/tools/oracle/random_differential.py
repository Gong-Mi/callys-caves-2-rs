#!/usr/bin/env python3
"""Differential: our precise-collision model vs libyoyo's PreciseCollision.

Both sides get the SAME rectangles, computed with the runner's
Compute_BoundingBox port (f32 corners, round-ties-even, inclusive edges), so a
mismatch is the pixel mapping, not the box.
"""
import math
import random
import struct

import precise_oracle as O

random.seed(7)


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def bbox(x, y, w, h, sx, sy, ang):
    left, right, top, bottom = 0, w - 1, 0, h - 1
    x, y = f32(x), f32(y)
    if ang == 0.0:
        l = f32(x + f32(left) * f32(sx))
        r = f32(l + f32(right - left + 1) * f32(sx))
        t = f32(y + f32(top) * f32(sy))
        b = f32(t + f32(bottom - top + 1) * f32(sy))
        return (min(l, r), max(l, r) - 1, min(t, b), max(t, b) - 1)
    rad = f32(f32(ang) * f32(math.pi) / 180.0)
    s, c = f32(math.sin(rad)), f32(math.cos(rad))
    xs, ys = [], []
    for cx in (f32(left), f32(right + 1)):
        for cy in (f32(top), f32(bottom + 1)):
            cx2, cy2 = f32(cx * f32(sx)), f32(cy * f32(sy))
            xs.append(f32(x + cx2 * c + cy2 * s))
            ys.append(f32(y + cy2 * c - cx2 * s))
    return (round(min(xs)), round(max(xs)) - 1, round(min(ys)), round(max(ys)) - 1)


def mask_px(m, x, y):
    if y < 0 or x < 0 or y >= len(m) or x >= len(m[0]):
        return 0
    return m[y][x]


def our_hit(ax, ay, sxa, sya, anga, amask, bx, by, sxb, syb, angb, bmask, wx, wy):
    res = []
    for (x, y, sx, sy, ang, m) in ((ax, ay, sxa, sya, anga, amask), (bx, by, sxb, syb, angb, bmask)):
        cx, cy = int(x), int(y)          # vcvt.s32 = trunc toward zero
        rad = f32(f32(ang) * f32(math.pi) / 180.0)
        c, s = f32(math.cos(rad)), f32(math.sin(rad))
        dx, dy = f32(wx - cx), f32(wy - cy)
        rx = f32(f32(dx * c) - f32(dy * s))
        ry = f32(f32(dx * s) + f32(dy * c))
        res.append(mask_px(m, int(f32(rx / f32(sx))), int(f32(ry / f32(sy)))))
    return 1 if res[0] and res[1] else 0


def edges_mask(w, h, p=0.5):
    m = [[1 if random.random() < p else 0 for _ in range(w)] for _ in range(h)]
    for x in range(w):
        m[0][x] = 1
        m[h - 1][x] = 1
    for y in range(h):
        m[y][0] = 1
        m[y][w - 1] = 1
    return m


def main():
    o = O.Oracle()
    bad = 0
    cases = 0
    for t in range(200):
        w, h = random.choice([(8, 8), (16, 8), (8, 16), (16, 16)])
        am, bm = edges_mask(w, h, 0.35), edges_mask(w, h, 0.35)
        ax, ay = random.randint(-10, 10), random.randint(-10, 10)
        bx, by = random.randint(-10, 10), random.randint(-10, 10)
        sxa = random.choice([1.0, 2.0, 0.5])
        sya = random.choice([1.0, 2.0, 0.5])
        sxb = random.choice([1.0, 2.0, 0.5])
        syb = random.choice([1.0, 2.0, 0.5])
        anga = random.choice([0.0, 0.0, 90.0, -90.0, 45.0])
        ba = bbox(ax, ay, w, h, sxa, sya, anga)
        bb = bbox(bx, by, w, h, sxb, syb, 0.0)
        sa = o.sprite(w, h, am)
        sb = o.sprite(w, h, bm)
        got = 1 if o.precise(sa, 0, o.rect(*[int(v) for v in ba]), ax, ay, sxa, sya, anga,
                             sb, 0, o.rect(*[int(v) for v in bb]), bx, by, sxb, syb, 0.0) else 0
        left, right = max(ba[0], bb[0]), min(ba[2], bb[2])
        top, bottom = max(ba[1], bb[1]), min(ba[3], bb[3])
        want = 0
        if left <= right and top <= bottom:
            for wy in range(int(top), int(bottom) + 1):
                for wx in range(int(left), int(right) + 1):
                    if our_hit(ax, ay, sxa, sya, anga, am, bx, by, sxb, syb, 0.0, bm, wx, wy):
                        want = 1
                        break
                if want:
                    break
        cases += 1
        if got != want:
            bad += 1
            if bad <= 8:
                print('MISMATCH oracle=%d ours=%d A(%d,%d,%.2f,%.2f,%.0f) B(%d,%d,%.2f,%.2f) boxA=%s boxB=%s'
                      % (got, want, ax, ay, sxa, sya, anga, bx, by, sxb, syb, ba, bb))
    print('cases=%d mismatches=%d' % (cases, bad))


if __name__ == '__main__':
    main()
