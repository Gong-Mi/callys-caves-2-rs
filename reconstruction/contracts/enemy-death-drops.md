# Enemy death drop generation and player collection loop

Scope: test-driven verification of enemy lethal damage, drop generation (CODE 55/56),
and end-to-end player collection of dropped items.

Original chain (all from recovered GML and bytecode IR evidence):
- `obj_knifebandit` (15) Step (CODE 56):
  - When `hpknife <= 0`, sets `alarm[0] = 1`.
- Alarm 0 (CODE 55):
  - Emits explosion sound: `audio_play_sound(snd_explode, 0, false)` (sound ID 7).
  - Checks drop flags and spawns items at `(x, y - 35)`:
    - `if (global.gemdropenabled == 1) instance_create(x, y - 35, obj_gem)`
    - `if (xpdrop == 1) { ID = instance_create(x, y - 35, obj_XPorb); with (ID) motion_set(global.xpspread, 5); }`
    - `if (coindrop == 1) { ... instance_create(..., obj_silvercoin); ... }`
  - Destroys the enemy instance: `action_kill_object()`.
- Unified pickup contract in player Step (CODE 12) & Collision 60 (CODE 14):
  - `hitpickup = instance_place(x, y, par_coin)`:
    - `hitpickup.type == 2` (`obj_gem`): `score += 100 * global.coinmultiply`, `coinpickup += 100 * global.coinmultiply`, spawns `obj_coinadd`, destroys gem.
    - `hitpickup.type == 3` (`obj_silvercoin`): `score += 4 * global.coinmultiply`, `coinpickup += 4 * global.coinmultiply`, spawns `obj_coinadd`, destroys coin. Also triggered by Collision Event 4 with object 60 (`CODE 14`).
    - `hitpickup.type == 4` (`obj_XPorb`): `global.experience += 1`, plays `snd_coin`, destroys orb.
    - `hitpickup.type == 5` (`obj_health`): `if (global.health1 < global.maxhp) global.health1 += 1`, destroys health pickup.

Verification in `crates/client/tests/enemy_death_drops_ir.rs`:
1. Warp into `rm_level1` where `obj_knifebandit` is materialized and active.
2. Lethal damage (`hpknife = 0`):
   - Tick 1: Step CODE 56 detects `hpknife <= 0` and primes `alarm[0] = 1`.
   - Tick 2: Alarm 0 (CODE 55) fires, emits `snd_explode` (sound 7), spawns exactly 1 `obj_gem`, 1 `obj_XPorb`, and multiple `obj_silvercoin`, then destroys the bandit via `action_kill_object()`.
3. Player collection:
   - Player moves to drop position `(x, y - 35)`:
   - Gem is picked up: `score` increases by at least 100 * coinmultiply, gem destroyed.
   - Silver coins are picked up: `score` increases by 4 * coinmultiply per coin.
   - XPorb is picked up: `global.experience` increases by 1, orb destroyed.

Test suite count:
- Workspace tests: 190 passed / 0 failed (189 baseline + 1 new integration test).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Weapon bullet collision with enemy is bypassed in this slice by direct lethal damage
  assignment to isolate the drop-spawn and collection state machine.
- XP level-up threshold trigger (`experience >= xptolevelup`) is verified in subsequent slices.
