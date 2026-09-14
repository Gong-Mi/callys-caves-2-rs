# Mines rm_level12 crossroad contract

Input asset: `assets/game.droid`, SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`.

## Room and links

`rm_level12` is room 16, reached from `rm_level11a` through creation code 834:
`warproom=16`, spawn `(128,204)`.

Its two doors are creation codes 835 and 836:

- CODE 835: return to `rm_level11a` (room 15), spawn `(1856,1164)`.
- CODE 836: continue to `rm_level13` (room 17), spawn `(128,268)`.

The exact Rust test walks the real room collision/warp dispatch path; it does not set `target_room_warp` directly.

## Room cast

The parsed room contains:

- `obj_bat` ×7
- `obj_shooter1` ×1
- `obj_shooter2` ×1
- `obj_treasurechest` ×2
- `obj_platform` ×2
- `obj_watersurface` ×18
- `obj_waterfill` ×3
- `obj_coin` ×28

`rm_level13` is checked after the forward transition for `obj_bat` ×2, `obj_slime` ×2, `obj_knifebandit` ×3 and `obj_spikes` ×5.

## Platform Create

`obj_platform` (object 7), CODE 33, writes `type=2` and selects the platform sprite by room number. For room 16 the selected sprite is resource 24 (`spr_platform2`, Mines theme). Both room instances are verified.

## Enemy phase batch

The companion test `level12_mines_enemy_phases_ir.rs` verifies the loaded bat and gunner phases and the actual IR event paths:

- all seven `obj_bat` instances start asleep (`awake=0`, `moving=0`, sleep sprite 66, Alarm 7 = 30);
- the single `obj_shooter1` and `obj_shooter2` retain binary initial facing; shooter2 starts with its 60-tick firing alarm;
- placing the player within 150 px below a bat triggers CODE 234, rearms Alarm 7, and the next Step enters the moving/flight phase;
- shooter2 CODE 108 honors its 7-argument `collision_line` LOS gate: a wall suppresses bullet2 but still rearms cadence, clearing the actual room blockers permits one of the paired `(x±5, y+11)` / `hspeed ±10` muzzle paths.

The tests use real room transitions, Scene dispatch, builtin collision checks, and object creation. They do not claim Android/GPU animation parity or complete rm_level12 combat coverage.

## Evidence boundary

This batch verifies asset-derived room composition, Creation Code values, platform initialization, bat phase entry, and shooter2 LOS firing. It does not yet verify full rm_level12 enemy damage/death chains, chest drops, or Android/GPU pixels.
