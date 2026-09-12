# Water surface hazard death and loot dissolution loop

Scope: test-driven verification of `obj_watersurface` (object 9) interaction with
dropped loot items and the player entity.

Original chain (all from recovered GML and bytecode IR evidence):
- Loot dissolution:
  - `obj_gem` Step (CODE 343), `obj_silvercoin` Step (CODE 346), `obj_health` Step (CODE 351),
    `obj_XPorb` Step (CODE 348) all contain:
    `if (instance_place(x, y, obj_watersurface)) { instance_destroy(); }`
  - Any dropped items touching water dissolve instantly and are eliminated.
- Player water hazard death:
  - Player Step (CODE 12):
    - `if (distance_to_object(obj_watersurface) <= 1) { global.health1 = 1; obj_player.playerhp = 1; }`
    - When `global.health1 == 1`:
      - Instantiates `obj_youhavedied` (134) death modal controller.
      - Plays `snd_youhavedied` (sound ID 26).
      - Increments `global.playerdied += 1`.
      - Clears `invulnerable = 0`.
  - The instantiated `obj_youhavedied` controller manages the 70-tick lockout,
    coin penalty deduction (30..99 coins), and tap-to-restart loop (proven in `death_release_ir.rs`).

Verification in `crates/client/tests/water_hazard_and_dissolution_ir.rs`:
1. Loot dissolution:
   - `obj_gem` (59) and `obj_silvercoin` (60) spawned at water surface in `rm_level1` (1600, 704).
   - In 1 tick, Step CODE 343 & 346 detect water contact and destroy both instances.
2. Player hazard collision:
   - Player moved to water surface at (1600, 704).
   - Tick 1: Step CODE 12 detects water proximity and drops `health1` to 1.0.
   - Tick 2: Step CODE 12 detects fatal health (1.0), instantiates `obj_youhavedied` (134),
     advances `global.playerdied` from 0 to 1, and emits `snd_youhavedied` (26).

Test suite count:
- Workspace tests: 196 passed / 0 failed (195 baseline + 1 new integration test).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Water fill background tile visual shader/blending tested under render pipeline suites.
- Spikes hazard (`obj_spikes` 8) follows the identical `distance_to_object <= 1` path in level 2.
