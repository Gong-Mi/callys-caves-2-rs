# Store upgrades and Mouse_0 pointer press dispatch

Scope: implementation of physical pointer press queue (`Scene.left_presses` / `GameState.pointer_pressed`),
dispatch of GameMaker Event Type 6 Subtype 0 (Left Pressed), and verification of the store upgrade purchase system.

Original chain (all from recovered GML and bytecode IR evidence):
- Event Type 6 Subtype 0 (Left Pressed) is bound to 15 store upgrade buttons:
  - `obj_powerupgrade` (84, CODE 414): costs 5000, sets `global.pwr = 2`, `powerupgradebought = 1`.
  - `obj_powerupgrade2` (85, CODE 416): costs 10000, sets `global.pwr = 3`, `powerupgrade2bought = 1`.
  - `obj_powerupgrade3` (86, CODE 418): costs 20000, sets `global.pwr = 4`, `powerupgrade3bought = 1`.
  - `obj_triplejump` (87, CODE 421): costs 5000, sets `triplejumpbought = 1`.
  - `obj_swordupgrade` (88, CODE 423): costs 5000, sets `sword = 1`, `swordupgradebought = 1`.
  - `obj_strengthupgrade` (93, CODE 433): costs 3000, sets `strengthupgradebought = 1`.
  - `obj_swordupgrade2` (89, CODE 425): costs 10000, sets `sword = 2`, `swordupgrade2bought = 1`.
  - `obj_healthregen` (92, CODE 431): costs 8000, sets `healthregenbought = 1`.
  - Other upgrade buttons: maxhpupgrades, coinmultiplier2/5, etc.
- Store lifecycle:
  - `obj_pause` (122) Create (CODE 507) sets `global.storemenu = 1`, executes
    `instance_deactivate_all(true)`, and materializes Page 1 store upgrade buttons at view 0 offsets.
  - When pressed, each button checks `score >= cost && !already_bought`, deducts score,
    updates player power/stat globals, and plays `snd_coin`.
  - Duplicate presses on already-purchased upgrades are rejected without score loss.
  - Purchases with insufficient score are rejected without score loss.

Implementation:
1. `Scene.left_presses`: separate physical pointer press queue in room coordinates, parallel to `left_releases`.
2. `Scene::tick`: consumes `left_presses`, computes bounding box intersection against active instances,
   and dispatches Event Type 6, Subtype 0 (`CODE 414` etc.).
3. `GameState::pointer_pressed`: accepts viewport coordinates (0..960, 0..540), offsets by active camera
   视口 (`view_xview`, `view_yview`), and enqueues to `scene.left_presses`.

Verification in `crates/client/tests/store_mouse_press_ir.rs`:
- Materialize store menu via `obj_pause` (122).
- Press `obj_powerupgrade`: score deducted 5000 (10000 -> 5000), `global.pwr` upgraded to 2.
- Duplicate press: rejected, score unchanged.
- Press `obj_strengthupgrade`: score deducted 3000 (5000 -> 2000), `strengthupgradebought` set to 1.
- Press `obj_swordupgrade2` (cost 10000 with 2000 balance): rejected, score remains 2000.

Test suite count:
- Workspace tests: 191 passed / 0 failed (190 baseline + 1 new integration test).
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- Multi-touch store navigation and store page switching (`obj_storepageswitch`) are left for dedicated menu test suites.
- Audio playback verified enqueued in audio command buffer, not physically output on Android speaker.
