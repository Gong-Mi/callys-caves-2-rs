# Player and weapon level-up progression scaling

Scope: verification of the player character and weapon level-up evaluation loop
driven by `obj_UI` Alarm 0 (CODE 368).

Original chain (all from recovered GML and bytecode IR evidence):
- `obj_UI` (66) runs a periodic 30-tick timer (`alarm[0] = 30`).
- Character level-up evaluation:
  - When `global.experience >= global.xptolevelup` and `global.level <= 20`:
    - `global.experience = 1`
    - `global.level += 1`
    - Next threshold scales by 12%: `global.xptolevelup = global.xptolevelup * 1.12`
    - Triggers `global.drawlevelup = 1` to spawn `obj_levelup` above player.
    - Caps level at 20: `if (global.level >= 20) global.level = 20`.
- Weapon level-up evaluation (Pistol, Shotgun, etc.):
  - When `global.pistolxp >= global.pistolxptolevelup`:
    - If `global.pistollevel < 10`, resets `global.pistolxp = 1`.
    - `global.pistollevel += 1`
    - Next threshold scales by 50%: `global.pistolxptolevelup = global.pistolxptolevelup * 1.5`
    - Triggers `global.drawweaponlevelup = 1` to spawn `obj_weaponlevelup`.

Verification in `crates/client/tests/player_and_weapon_levelup_ir.rs`:
1. Baseline: level 1 (threshold 30.0), pistol level 1 (threshold 46.0).
2. Level 2 advance:
   - Player level advances 1 -> 2, experience resets to 1, threshold becomes 33.6 (30.0 * 1.12).
   - Pistol level advances 1 -> 2, pistolxp resets to 1, threshold becomes 69.0 (46.0 * 1.5).
3. Level 3 advance:
   - Evaluates consecutive level up, scaling threshold to 37.632 (33.6 * 1.12).
4. Level 20 ceiling:
   - Confirms player level caps firmly at 20 without unbounded overflow.

Test suite count:
- Workspace tests: 192 passed / 0 failed (191 baseline + 1 new integration test).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Weapon firing bullet damage and weapon experience accumulation from enemy hits
  are exercised in weapon combat suites; this slice characterizes the progression state machine.
- Level-up floating text / particle animation is verified via instance creation, not pixel readback.
