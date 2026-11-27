# Weapon ballistics (spawn, speed, gravity, lifetime)

Status: **static from the IR** (2026-10-25). Completes the reachability model in
`boss-reachability.md`: the geometry says *where* a hit can happen, this says
whether the weapon gets there.

## Spawn offsets (relative to the player's `x, y`)

Every weapon is created from `obj_player_Alarm_0` (code 11) except the sword and
the energy wave, which come from `obj_player_Alarm_1` (code 10). Offsets are
literal in the `instance_create` argument expressions:

| weapon | spawn offset | speed | vertical | gravity |
|---|---|---|---|---|
| flame (35) | `(x ± 10, y + 7)` | 15 | `vspeed = -1` | — |
| blade (36) | `(x ± 3, y + 6)` | 20 | — | — |
| bomb (37) | `(x ± 20, y + 5)` | 8 | — | 0.3 |
| arrow (38) | `(x, y + 3)` / `(x - 3, y + 3)` | 15 | `vspeed = -1` | 0.3 |
| bullet (39) | `(x ± 10, y + 6)`, `(x ± 10, y + 5)`, fan `(x ± 8, y + 1..+7)`, rifle `(x ± 8, y + 8)` and `(x ± 16, y + 10)` | 25 | — | — |
| laserbeam (41) | `(x ± 8, y + 6)` | 20 | — | — |
| spikegunspike (42) | `(x ± 24, y - 3)` | 14 | — | — |
| boomerangthrow (43) | `(x ± 10, y + 7)` | 5 | — | — |
| rocket (44) | `(x ± 30, y + 3)` | 16 | — | — |
| energywave (45) | `(x ± 15, y - 5)` | 20 | — | — |
| sword (46) | `(x ± 15, y - 15)` | — | — | — |

## Direction

`Create` sets the sign from the player's `facing`:

```
if (facing == 1) hspeed = -V else hspeed = +V
```

with `V` from the table (bullet 25, laser/energywave 20, rocket 16, blade 20,
arrow/flame 15, spike 14, bomb 8, boomerang 5). Three global weapon upgrades
modify the shot, all inside the bullet's Create:

- `shotgun == 1`: `motion_set(±32°)` with `image_angle = direction + random(±15°)` — a spread shot.
- `assaultrifle == 1`: `motion_set(±32°)` with `random(±3°)`.
- neither: plain `hspeed`, no angle change.

## Lifetime

No weapon checks `room_width` / `room_height`, so nothing is destroyed by
leaving the screen from its own Step. `instance_destroy` appears only inside hit
branches (bullet has one per target family; rocket has one at instruction 21).
The practical lifetime is therefore "until it overlaps something that kills it",
i.e. the first target it touches — which is exactly the collision chain the
`boss-damage-matrix.md` describes. Whether the engine also despawns off-screen
instances elsewhere (a global sweep, not a per-body check) was **not** verified.

## What this means for reach

With `V` between 5 and 25 px/frame and no gravity except bomb/arrow (0.3), every
weapon crosses the boss windows from `boss-reachability.md` within a handful of
frames: a bullet covers the 110 px trex window in ~5 frames, the spike's 126 px
in ~9, the boomerang's 110 px in ~22. The binding constraints are therefore:

1. the boss must be inside the weapon's *spawn* band (the ±spawn offset and the
   facing sign decide which side),
2. the first instance the weapon overlaps is the one it damages (it dies there),
3. for bomb/arrow the 0.3 gravity adds ~0.15 px/frame² of drop, so a 30-frame
   flight lands ~67 px low — enough to miss a boss that sits high.

## In-room flight is blocked by scenery (measured)

A bullet launched 200 px to the left of the trex at 25 px/frame dies after three
ticks, roughly 150 px short of the target: the boss room's scenery is the first
thing it overlaps. A 100 px lane fares no better. So "the window exists" and
"the weapon flies at 25 px/frame" still do not add up to a hit — the lane has to
be clear, and in rm_boss1 it usually is not. Flight fixtures for this reason
belong in a hand-built empty room, not in the boss arena.

## Measured: frames to first contact in a clear lane

Empty room (every instance except the player and the trex removed), weapon
spawned 200 px left of the trex at its documented `dy`, `hspeed = +V`, trex
parked 80 px up. Frames counted until the trex's HP first changes:

| weapon | frames | damage | note |
|---|---|---|---|
| bullet | 7 | 1.00 | |
| flame | 8 | 0.30 | |
| blade | 8 | 3.00 | |
| spike | 8 | 3.00 | |
| energywave | 8 | 3.00 | |
| arrow | 9 | 2.00 | 0.3 gravity, still connects |
| laserbeam | 9 | 0.25 | |
| rocket | 9 | 6.00 | |
| bomb | never | — | **no boss HP write in the body at all** (see below) |
| boomerang | never | — | **no boss HP write in the body at all** |
| sword | 1 (touch range) | 1.00 | not a projectile: repositions on the player |

The first explanation I wrote for bomb/boomerang was wrong on both counts — I
blamed the bomb's gravity and guessed the boomerang turns back. Measuring the
bodies settles it: each writes 14 `hp*` fields, all regular enemies
(`hpknife`, `hp`, `hpwolf`, `hptwo`, `hpfour`, `hpslime`, `hpghost`,
`hpshooter1/2`, `hpfireslime`, `hphulkingbandit`, `hpzombie`, `hpfirehulk`,
`hpskeleton`) and **none** of `hptrex` / `hpboss2..5` / `hpfinalboss`. The bomb
does check `obj_trex` and then damage... `hpfour` (the bat) in the branch that
follows, but it never touches a boss's HP. No amount of aim fixes that: these
two weapons are not boss weapons.

The sword is spawned at `(x ± 15, y - 15)` and its Step repositions itself from
the player each tick (`x ± 5`, `y + 6`, `image_angle ± 25`), so it only connects
when the player is at touch range — then it lands 1.00 on the very next tick.

These eight numbers plus the two negatives are pinned by
`weapon_flight_frames_to_the_trex_in_a_clear_lane` (9/9 with the rest of the
boss1 suite).

## Not covered

- The engine's despawn sweep (if any) and the room-bound clipping.
- What `facing` means in world space (the sprite's `image_xscale` convention)
  beyond the sign of `hspeed`.
- Trajectory of the sword and energy wave: they are spawned per swing and their
  own Step controls motion (not modelled here).
