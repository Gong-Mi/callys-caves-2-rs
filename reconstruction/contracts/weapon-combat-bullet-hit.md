# Weapon firing, bullet projectile travel, and enemy damage settlement loop

Scope: test-driven verification of player pistol firing (CODE 11), in-flight bullet
projectile physics (CODE 282/284), enemy damage, flashing, and weapon XP gain.

Original chain (all from recovered GML and bytecode IR evidence):
- Weapon firing:
  - When shooting (e.g. `obj_player` Alarm 0 / CODE 11):
    - When `global.pistol == 1`:
      - Spawns `obj_bullet` (39) at `(x + 10, y + 6)` (facing right) or `(x - 10, y + 5)` (facing left).
      - Plays `snd_fire` (sound ID 10) when `global.soundmute == 0`.
      - Sets `global.firing = 1` and `alarm[3] = 5`.
- Bullet projectile physics (CODE 282 / 284):
  - Create (CODE 282): sets `hspeed = 25` (facing right) or `-25` (facing left).
  - Step (CODE 284):
    - Advances 25 px per frame along `hspeed`.
    - Wall collision: `instance_place(x, y, par_wall)` creates `obj_bulletspark` (13) and calls `instance_destroy()`.
    - Enemy collision: `hitknife = instance_place(x, y, obj_knifebandit)`:
      - `hitknife.flashing = 1`
      - `part_particles_create(global.P_System, x, y, global.Particle1, 2)`
      - `hitknife.hpknife -= global.pistoldamage`
      - Creates `obj_damage` indicator
      - Increments weapon experience: `global.pistolxp += 1`
      - Plays `snd_impactsound2` (sound ID 23)
      - Calls `instance_destroy()` to consume the bullet
      - Stuns enemy: `hitknife.stunned = 1; hitknife.alarm[4] = 10;`
- Global weapon damage initialization:
  - Base weapon damages initialized in Game Start (`init_fresh_start_globals`):
    `pistoldamage` (1.0), `shotgundamage` (0.5), `assaultrifledamage` (0.6), `rocketdamage` (6.0),
    `laserdamage` (3.0), `icegundamage` (1.0), `bowdamage` (2.0), `flamethrowerdamage` (0.3),
    `bladegundamage` (3.0), `boomerangdamage` (2.0), `spikegundamage` (3.0), `bombgundamage` (4.0).

Verification in `crates/client/tests/bullet_combat_hit_ir.rs`:
1. Player pistol shot in `rm_level1`:
   - Bullet 39 spawned at (1510, 590), `hspeed = 25.0`, `snd_fire` (sound 10) emitted.
2. In-flight motion:
   - Ticks 1..3: advances exactly 25 px/frame (`x = 1510 -> 1535 -> 1560 -> 1585`).
3. Impact settlement:
   - Frame 4: hits knifebandit at x=1600.
   - Bullet destroyed upon impact.
   - Bandit `hpknife` reduced from 15.0 to 14.0 (- `global.pistoldamage`).
   - Bandit `flashing = 1`, `stunned = 1`, `alarm[4] = 10`.
   - Weapon experience `global.pistolxp` increments 0 -> 1.
   - `snd_impactsound2` (sound 23) emitted.
4. Wall collision:
   - Bullet fired into `par_wall` is immediately destroyed and materializes `obj_bulletspark` (13).

Test suite count:
- Workspace tests: 193 passed / 0 failed (192 baseline + 1 new integration test).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Multi-bullet spread weapons (Shotgun / Assault Rifle) tested under dedicated weapon suites.
- Floating damage number (`obj_damage`) font/rasterization tested under client render suites.
