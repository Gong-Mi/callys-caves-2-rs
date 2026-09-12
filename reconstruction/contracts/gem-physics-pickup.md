# Gem physics and pickup through real player Step

Scope: test-driven characterization and verification of `obj_gem` (59, parent `par_coin` 57).
Closes the remaining item from `coin-pickup-step.md`:
"gem (type=2) and gem physics (yorigin) are not exercised".

Original chain (all from recovered GML and bytecode IR evidence):
- `obj_gem` (59) is parented to `par_coin` (57).
- Create (CODE 341):
  - Sets `type = 2`, `friction = 0.3`.
  - Sets `yorigin = y` if `!instance_place(x, y - 1, par_wall)`, else `y + 32`.
- Step (CODE 343):
  - Checks floor wall contact: `instance_place(x, y + 1, par_wall)`.
  - When resting on `par_wall` and `y >= yorigin`, sets `vspeed = 0` and `gravity = 0`.
  - Otherwise accelerates with `gravity = 0.6`.
  - Blocks horizontal movement when `instance_place(x + hspeed, y, par_wall)` is true.
  - Destroys instance upon touching `obj_watersurface`.
- Destroy (CODE 342):
  - Plays `global.coinsound` when `global.soundmute == 0`.
- Player Step (CODE 12):
  - Scans `hitpickup = instance_place(x, y, par_coin)`.
  - When `hitpickup.type == 2`:
    - `score += 100 * global.coinmultiply`
    - `global.coinpickup += 100 * global.coinmultiply`
    - Creates `obj_coinadd` at view HUD coordinates `(view_xview[0] + 225, view_yview[0] + 4)`.
    - Destroys the gem instance via `with (hitpickup) { instance_destroy(); }`.

Original culling interaction:
- `obj_bg` Alarm 2 (CODE 361) runs optimization culling every 15 frames:
  `with (obj_gem) { if (distance_to_object(obj_player) >= 400) instance_deactivate_object(id); }`
- Gems further than 400 pixels from the player are deactivated by `obj_bg`, while
  gems within 400 pixels remain active and simulate full physics.

Verification in `crates/client/tests/gem_pickup_ir.rs`:
1. Static placement pickup:
   - Real `rm_town` gem 100045 (at 480, 64) is overlapped by player.
   - One real Step CODE 12 tick destroys the gem, awards 100 * coinmultiply to `score`
     and `coinpickup`, enqueues `coinsound` audio, and leaves distant gems untouched.
2. Dynamic in-flight pickup:
   - Gem created above standing player falls downward via gravity; upon intersecting
     the player at frame 10, is dynamically picked up and destroyed, advancing score.
3. Physical fall and settling:
   - Gem spawned at (550, 400) falls under `gravity = 0.6` with `friction = 0.3`.
   - Hits floor `par_wall` at y=497.5, zeroing `gravity` and `vspeed`.
   - Subsequent ticks verify the gem remains permanently stationary on the floor.

Test suite count:
- Workspace tests: 189 passed / 0 failed (186 baseline + 3 new gem tests).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Water surface destruction not exercised in this slice.
- `obj_coinadd` visual counter animation is verified created, not pixel-matched.
