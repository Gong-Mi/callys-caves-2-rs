#!/usr/bin/env python3
"""For a saved mismatch, find which side's mask mapping disagrees with the
runner, pixel by pixel: probe A and B separately with a 1x1 sprite."""
import json
import math
import struct
import sys

import precise_oracle as O

def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]

def mask_px(m, x, y):
    return m[y][x] if 0 <= y < len(m) and 0 <= x < len(m[0]) else 0

case = json.load(open(sys.argv[1] if len(sys.argv) > 1 else 'mismatch_1.json'))
am, bm, w, h = case['am'], case['bm'], case['w'], case['h']
ax, ay, bx, by = case['ax'], case['ay'], case['bx'], case['by']
sxa, sya, sxb, syb = case['sxa'], case['sya'], case['sxb'], case['syb']
anga = case['anga']
ba, bb = case['ba'], case['bb']

def our_pixel(mask, x, y, sx, sy, ang, wx, wy):
    cx, cy = int(x), int(y)
    rad = f32(f32(ang) * f32(math.pi) / 180.0)
    c, s = f32(math.cos(rad)), f32(math.sin(rad))
    dx, dy = f32(wx - cx), f32(wy - cy)
    rx = f32(f32(dx * c) - f32(dy * s))
    ry = f32(f32(dx * s) + f32(dy * c))
    return mask_px(mask, int(f32(rx / f32(sx))), int(f32(ry / f32(sy))))

left, right = max(ba[0], bb[0]), min(ba[2], bb[2])
top, bottom = max(ba[1], bb[1]), min(ba[3], bb[3])
print('intersection', (left, top, right, bottom))

o = O.Oracle()
sa = o.sprite(w, h, am)
sb = o.sprite(w, h, bm)
probe = o.sprite(1, 1, [[1]])

for wy in range(int(top), int(bottom) + 1):
    for wx in range(int(left), int(right) + 1):
        ours_a = our_pixel(am, ax, ay, sxa, sya, anga, wx, wy)
        ours_b = our_pixel(bm, bx, by, sxb, syb, 0.0, wx, wy)
        if not (ours_a and ours_b):
            continue
        oa = o.precise(sa, 0, o.rect(*[int(v) for v in ba]), ax, ay, sxa, sya, anga,
                       probe, 0, o.rect(wx, wy, wx, wy), wx, wy, 1.0, 1.0, 0.0)
        ob = o.precise(probe, 0, o.rect(wx, wy, wx, wy), wx, wy, 1.0, 1.0, 0.0,
                       sb, 0, o.rect(*[int(v) for v in bb]), bx, by, sxb, syb, 0.0)
        print('pixel (%d,%d) ours(A=%d,B=%d) oracle(A=%d,B=%d)' % (wx, wy, ours_a, ours_b, oa, ob))
