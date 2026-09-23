# Source lookup

Confirm the worktree/branch first. Search the symbol below, then read the complete
relevant function and its direct dependencies; do not read every listed file.
Line numbers drift. Builtins are string match arms in `Host::call`, not standalone
functions (e.g. search `"choose"`, not `fn choose`).

| Task | Source / entry | Related tests |
| --- | --- | --- |
| Font bitmaps | `crates/client/src/parts/font.rs`: `FONT_5X7` | existing client render tests |
| Pixel blending / text drawing | `crates/client/src/lib.rs`: `impl Framebuffer` | `crates/client/tests/ir_scene_gameplay.rs` |
| Scene command consumption / camera | same client file: `draw_frame`, `draw_sprite_alpha`, `draw_tile`, `camera_position_for_scene` | `prologue_render_regression.rs`, `particle_render_consumption.rs` in client tests |
| Frame errors / lifecycle | same client file: `GameState`, `step_inner`, `nativeStep` | `ir_error_propagation.rs`, `room_lifecycle_error_boundary.rs` in client tests |
| Physical release input | `android-build/src/com/gongmi/callyscaves2/PointerReleaseQueue.java`, adjacent `MainActivity.java` → client `pointer_released` → `crates/core/src/ir_scene.rs`: `tick` | `crates/client/tests/death_release_ir.rs`; `scripts/test_pointer_release_java.py` |
| Frame input boundary | core `ir_scene.rs`: `Scene::end_frame` (retires `mouse_pressed` / device `pressed`+`released` **after** the draw pass; `tick` no longer clears them) → client `lib.rs`: `step_inner` touch publication + `pointer_released` | `crates/client/tests/first_chapter_playthrough.rs` |
| Chapter 1 playable flow (client) | client `lib.rs`: `step_inner`, `enable_ir_gameplay`, `pointer_released` → core `ir_scene.rs`: `load_room_from_data`, `transition_to_room`, `obj_bg` Alarm 2 sleep sweep | `crates/client/tests/first_chapter_playthrough.rs`; `crates/core/tests/first_chapter_flow_ir.rs` |
| Save / cold restore | client `write_save_atomic`, `autosave_ir`, `restore_ir_snapshot` → core `ir_scene.rs`: `save_snapshot`, `restore_snapshot`, `restore_snapshot_cross_room` | `crates/client/tests/ir_save_roundtrip.rs`, `save_io.rs` |
| Boot / Game Start chain | client `lib.rs`: `enable_ir_gameplay` (player → CODE 17 dispatch → room load → active-only Room Start), `queue_boot_ir_restore`, `step_inner` prologue phase; core `ir_scene.rs`: `ini_disk_dir` INI boundary, `select_for_access` | `crates/client/tests/game_start_p0.rs`, `prologue_render_regression.rs`; `reconstruction/contracts/game-start-p0.md` |
| VM selectors / builtins | `crates/core/src/code_vm.rs`: `Host`, `Op::Store` → `crates/core/src/ir_scene.rs`: `impl Host for Scene`, `expected_argc`, string match arm | `crates/core/tests/physics_and_motion_ir.rs` and feature-specific core tests |

Only the font constant has moved. It is a same-scope `include!` fragment, not a
new public module. GameState, framebuffer, frame composition and JNI still live
in client `lib.rs`; Scene and its Host impl remain in core `ir_scene.rs`.

One-time cut proof (not a permanent code freeze):

    python3 scripts/verify_font_cut.py 3e151c2539abe671fa263f6376d0c74d23a308e6

The proof compares expanded source bytes and replays a source-reading window.
A precise symbol window is unchanged; no fixed token-saving ratio is claimed.
