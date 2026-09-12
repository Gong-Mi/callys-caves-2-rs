# Complete combat loop: shoot, kill, loot, and weapon upgrade

Scope: integration of all proven combat subsystems into a single end-to-end verification
of the core game loop in `rm_level1`.

Original chain (all from recovered GML and bytecode IR evidence):
1. Weapon firing: player Alarm 0 (CODE 11) spawns `obj_bullet` (39), emits `snd_fire` (10).
2. Ballistic trajectory: `obj_bullet` Create (CODE 282) initializes `hspeed = 25.0`.
3. Damage & hit settlement: `obj_bullet` Step (CODE 284) detects `instance_place(x, y, obj_knifebandit)`:
   - Deducts `global.pistoldamage` from `hitknife.hpknife`.
   - Advances `global.pistolxp += 1`.
   - Emits `snd_impactsound2` (23) and consumes the bullet.
4. Fatal state transition: `obj_knifebandit` Step (CODE 56) detects `hpknife <= 0` and primes `alarm[0] = 1`.
5. Death & drop generation: `obj_knifebandit` Alarm 0 (CODE 55) emits `snd_explode` (7), spawns
   `obj_gem` (59), `obj_XPorb` (61), `obj_silvercoin` (60), and destroys the bandit.
6. Loot collection: player Step (CODE 12) & Collision 60 (CODE 14) absorb the gem (+100*coinmult)
   and silver coins (+12*coinmult), and destroy the collected instances.
7. Weapon progression scaling: `obj_UI` Alarm 0 (CODE 368) periodically evaluates `pistolxp >= pistolxptolevelup`:
   - Advances `global.pistollevel` 1 -> 2.
   - Resets `global.pistolxp` to 1.
   - Scales next threshold by 50% (`global.pistolxptolevelup = 46.0 -> 69.0`).

Verification in `crates/client/tests/complete_combat_loop_ir.rs`:
- End-to-end execution of steps 1 through 7 in `rm_level1` with real room geometry,
  instantiation, physical motion integration, collision dispatch, and progression scaling.
- All state changes confirmed with exact zero-tolerance numeric assertions.

Test suite count:
- Workspace tests: 195 passed / 0 failed (194 baseline + 1 new integration test).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Weapon firing triggered via player Alarm 0 dispatch; touch-button virtual screen press
  integration is covered in `ui_layer_ir.rs`.
- Enemy movement during combat is held static by test setup to isolate hit trajectory.
