# Boss reachability (static geometry)

Status: **static model, one axis validated against the engine** (2026-10-25).
Question: with a weapon instance at `(x, y)` and a boss at `(bx, by)`, where can
a hit happen at all?

## First correction: the hit box is the full sprite extent, not the SPRT bbox

`reconstruction/contracts/collision-broad-phase.md` records the manual SPRT box
(`has_bbox`, `l/r/t/b`). Collision **does not use it**. Measured on the engine
with bullet (sprite 40, 16×16, origin 9,9) against trex (sprite 56, 96×64,
origin 64,64):

| relative offset | manual SPRT box model | full sprite extent model | engine |
|---|---|---|---|
| `by - y = 70` | 54 max → miss | 70 max → hit | **hit** |
| `by - y = 72` | miss | miss | **miss** |
| `bx - x = 70` | 61 max → miss | 70 max → hit | **hit** |
| `bx - x = 72` | miss | miss | **miss** |
| `by - y = -8` | -7 min → miss | -8 min → hit | **hit** |
| `by - y = -10` | miss | miss | **miss** |

All six boundaries match the full-extent model exactly and falsify the manual
box. Pinned by `bullet_window_matches_the_measured_thresholds` (8 cases).

So the box of an instance at `(x, y)` with sprite `w × h` and origin
`(ox, oy)` is:

```
x ∈ [x - ox, x + w - 1 - ox]      y ∈ [y - oy, y + h - 1 - oy]
```

and a hit needs strict overlap of the two boxes.

## Query form

Every weapon tests bosses with `instance_place(<point>, <obj>)`:

| weapon | boss checks | query point |
|---|---|---|
| flame, blade, bomb, arrow, bullet, laserbeam, rocket, energywave, sword | 6 (all bosses) | self `(x, y)` |
| spikegunspike | 6 | `(x ± 20, y)` for the knife pair, `(x ± 30, y)` for the rest — both signs |
| boomerangthrow | 0 | checks `obj_hulkingbandit` (21) and normal enemies, never a boss |

## Boxes (full sprite extent, relative to the instance origin)

| weapon | l | r | t | b |
|---|---|---|---|---|
| flame (64×64, 32,32) | -32 | 31 | -32 | 31 |
| blade (16×16, 0,8) | 0 | 15 | -8 | 7 |
| bomb (16×16, 8,8) | -8 | 7 | -8 | 7 |
| arrow (32×16, 0,8) | 0 | 31 | -8 | 7 |
| bullet (16×16, 9,9) | -9 | 6 | -9 | 6 |
| laserbeam (16×20, 0,10) | 0 | 15 | -10 | 9 |
| spikegunspike (32×16, 0,0) | 0 | 31 | 0 | 15 |
| boomerangthrow (16×32, 2,16) | -2 | 13 | -16 | 15 |
| rocket (48×24, 24,12) | -24 | 23 | -12 | 11 |
| energywave (48×48, 24,24) | -24 | 23 | -24 | 23 |
| sword (15×36, 7,36) | -7 | 7 | -36 | -1 |

| boss | l | r | t | b |
|---|---|---|---|---|
| trex (96×64, 64,64) | -64 | 31 | -64 | -1 |
| boss2 (160×96, 80,48) | -80 | 79 | -48 | 47 |
| boss3 (102×94, 51,47) | -51 | 50 | -47 | 46 |
| boss4 (128×128, 48,64) | -48 | 79 | -64 | 63 |
| boss5 (192×96, 100,49) | -100 | 91 | -49 | 46 |
| finalboss (176×144, 88,72) | -88 | 87 | -72 | 71 |

## Window spans (`dx × dy`, pixels; bigger = connects over a wider offset)

| weapon | trex | boss2 | boss3 | boss4 | boss5 | finalboss |
|---|---|---|---|---|---|---|
| flame | 158×126 | 222×158 | 164×156 | 190×190 | 254×158 | 238×206 |
| blade | 110×78 | 174×110 | 116×108 | 142×142 | 206×110 | 190×158 |
| bomb | 110×78 | 174×110 | 116×108 | 142×142 | 206×110 | 190×158 |
| arrow | 126×78 | 190×110 | 132×108 | 158×142 | 222×110 | 206×158 |
| bullet | 110×78 | 174×110 | 116×108 | 142×142 | 206×110 | 190×158 |
| laserbeam | 110×82 | 174×114 | 116×112 | 142×146 | 206×114 | 190×162 |
| spikegunspike | 126×78 | 190×110 | 132×108 | 158×142 | 222×110 | 206×158 |
| boomerangthrow | 110×94 | 174×126 | 116×124 | 142×158 | 206×126 | 190×174 |
| rocket | 142×86 | 206×118 | 148×116 | 174×150 | 238×118 | 222×166 |
| energywave | 142×110 | 206×142 | 148×140 | 174×174 | 238×142 | 222×190 |
| sword | 109×98 | 173×130 | 115×128 | 141×162 | 205×130 | 189×178 |

Because the boxes are large relative to the sprites' own motion, every weapon
overlaps every boss at `(0, 0)`; reachability in play is therefore decided by
trajectory and AI, not by box size. The boomerang row is informational only —
that body never tests a boss object.

## What this does not say

- Masks: libyoyo uses the SPRT mask when present; whether the shipped build
  takes the mask path for these sprites is unverified, and a mask can only
  shrink the windows above (the bullet/trex boundaries prove the *box* is the
  full extent, not that no mask applies).
- Trajectory: weapon speed, gravity, lifetime and the spawn offset are not
  modelled, so "window exists" ≠ "reaches the boss".
- Boss movement: AI and patrol change `(bx, by)` every step.
- Spike's ±20/±30 query offsets shift its effective window.
