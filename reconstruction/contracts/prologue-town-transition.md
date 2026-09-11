# Prologue skip and first room Room Start lifecycle

Scope: client lifecycle and end-to-end prologue-to-town transition.

Original chain (all from recovered GML and bytecode IR evidence):
- obj_introduction (137) Create (CODE 548) initializes `taplock = 0` and sets
  `alarm[0] = 120`. Alarm 0 (CODE 553) sets `taplock = 1`.
- Step (CODE 554) only checks `mouse_check_button_pressed(mb_left)` when
  `taplock == 1`. Premature taps within the first 120 frames (2.0s) are ignored
  by design to display the opening sequence.
- When tapped after frame 120, Step invokes `instance_destroy()`. Destroy
  (CODE 549) calls `instance_activate_all()` and tears down obj_phone and obj_logo.
- GameState::step_inner detects `intro_alive == false`, clears `intro_scene`,
  and invokes `enable_ir_gameplay` to enter rm_town.

Room Start lifecycle gap and resolution:
- Previously, `enable_ir_gameplay` only called `load_room_from_data` to instantiate
  objects and execute creation code, but omitted GameMaker Event 7, Subtype 4
  (Room Start) dispatch on the newly instantiated objects.
- `enable_ir_gameplay` now dispatches Event 7 Subtype 4 to all active non-external
  instances, matching `transition_to_room`'s specification.
- In rm_town, obj_player (0) executes CODE 16 (Other_4):
  - Sets `global.roomstart = 1`, `alarm[6] = 10`, and `global.roomtownvisited = 1`.
  - Player Step CODE 12 gates movement under `if (global.roomstart == 0)`.
  - After 10 ticks, obj_player Alarm 6 clears `global.roomstart = 0`, unlocking
    normal player input and motion.

Verification in `prologue_render_regression.rs`:
- Step 5 frames during prologue: `taplock == 0`, tap does not skip.
- Step 120 frames: Alarm 0 fires, `taplock = 1`.
- Tap skips prologue: `intro_scene` is cleared, `scene` activates in rm_town (room 0).
- Room Start sets `global.roomstart = 1`.
- Step 15 frames: Alarm 6 fires, `global.roomstart` cleared to 0.
- `move_right` input drives real player position advancement (`moved_x > initial_x`).
- Framebuffer renders rm_town with >1000 non-zero pixels.

Test suite count:
- Workspace tests: 186 passed / 0 failed.
- Builtin coverage audit: 99/99 names registered.
- Java pointer release contract: passed.
- Android release cdylib build: passed.

Boundaries:
- SoundPool playback remains mock-queued, not tested on physical audio device.
- Full prologue animation sequence (camera pan / logo slide) is stepped, not
  individually pixel-matched to original runner frames.
