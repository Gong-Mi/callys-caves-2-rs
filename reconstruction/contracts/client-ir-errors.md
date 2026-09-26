# Client IR error boundary (H regression line)

Scope: `crates/client/src/lib.rs`; no original bytecode/builtin semantics changed.

## Execution contract

`GameState::step_inner` propagates the first error from the existing sequential
execution path. `GameState::step` records it once in `runtime_diagnostic`, with
completed-frame counter, phase, room (or transition endpoints), and the original
VM CODE/offset/message. Later calls do not retry a partially executed scene or
fall back to the legacy world. `nativeStep` emits one Android log entry on the
transition into the halted state; desktop/host execution writes one stderr entry.

Successful execution order is unchanged: intro tick -> intro Draw -> intro audio
-> gameplay initialization; gameplay input -> tick -> audio -> room transition
-> Draw -> frame count. The legacy world path is unchanged on success.

| Boundary in `step_inner` | Failure behavior | Regression oracle |
| --- | --- | --- |
| Intro `tick` | Return error instead of `expect` panic | `failed_intro_tick_does_not_panic_across_native_boundary` |
| Intro `draw_view` | Stop before draining audio or handing off | `first_error_is_retained_and_failed_scene_is_not_retried` (intro Draw case) |
| `enable_ir_gameplay` handoff | No legacy fallback after init error | `failed_intro_handoff_does_not_fall_back_to_legacy_world` |
| Gameplay `tick` | No subsequent audio drain/warp/Draw/frame count | `failed_gameplay_tick_does_not_commit_frame_or_transition` |
| Target room lookup | Invalid target is an error, not silent discard | `invalid_warp_is_diagnosed_without_counting_a_visit` |
| `transition_to_room` | No successful-visit count after failed Create | `failed_room_create_is_diagnosed_without_counting_a_visit` |
| Gameplay `draw_view` | No completed-frame count | `failed_gameplay_draw_does_not_commit_frame` |
| Subsequent `step` calls | First diagnostic and failed scene stay unchanged | `first_error_is_retained_and_failed_scene_is_not_retried` (all four tick/Draw cases) |
| Real success path | Town 15 frames, transition + level1 60 frames; every frame has no diagnostic | `real_town_to_level1_frames_remain_error_free` |

All named tests are in `crates/client/tests/ir_error_propagation.rs`. Error
fixtures use deliberately missing CODE bodies through the real Scene scheduler,
not mocked Result values. The first three regression tests were run against the
old implementation and failed for the expected panic/frame-count reasons.

## Evidence limits

This is stop-on-error, not transactional rollback: mutation, audio already queued
or playing, and Draw buffers produced before the failure are not undone. Rendering
may still present that partial state. Recovery requires a fresh GameState; no
in-game error dialog or retry mechanism is implemented here. Public initialization
still returns its own Result to its caller.

Host tests prove the Rust execution boundary, not ART panic behavior, Android log
visibility, actual sound playback, or full-game playability. Android-feature
compilation is a separate gate; no device launch/input is authorized by this slice.
75 error-free client frames are not combat/death/pickup/completion acceptance.

## Follow-up: room lifecycle host boundary

`Scene::transition_to_room` previously discarded Event7/5 (Room End) and
Event7/4 (Room Start) errors internally, defeating the client boundary above.
Both dispatch calls now return their error with phase and instance id. Room End
failure stops before target geometry is loaded; Room Start failure leaves the
already-loaded target state and stops, without claiming rollback. Successful
ordering and instance retention are unchanged.

`crates/core/tests/room_lifecycle_errors.rs`: two failing-event regressions
(RED on swallowed errors), plus a valid-callback preservation test.
`crates/client/tests/room_lifecycle_error_boundary.rs`: actual town -> level1
transition with separately fault-injected player RoomEnd/RoomStart bindings;
both regressions were RED before the fix and now reach runtime_diagnostic without
incrementing completed frames or successful visits. This is error transport
coverage, not new gameplay behavior or full lifecycle semantic parity.
