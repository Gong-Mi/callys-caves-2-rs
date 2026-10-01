# Draw-stream frame fingerprint (render batch: visual verification without pixels)

Suite: `crates/client/tests/draw_stream_frame_fingerprint.rs` (callys-client)

## Contract

The IR Scene's per-view-pass command queues (`draws`, `texts`, `backgrounds`,
`healthbars`, in emission order) are the complete visual output the original
bytecode commits each tick. This batch pins them with an FNV-1a 64 digest over
every identifying field, quantised `floor(x*8)` / `floor(x*1000)` (no float
noise, no std-hasher dependency, cross-toolchain stable). The framebuffer is
their deterministic consumption, covered separately by the per-field
rasterisation suites (`draw_field_consumption`, `prologue_layers_consumption`,
`font_consumption`, `particle_render_consumption`).

Pinned facts (probe-recorded on this head, view-6 town / full-cast level1):

* Determinism: two cold boots replay identical 30-tick digest sequences
  (town idle, level1 through the door chain + sleep sweep).
* Golden anchor: town idle tick-0 digest = `0x68c1b6be4897c703`
  (180 draws / 3 texts / 1 bg / 2 healthbars per tick).
* Content sensitivity: 4 ticks of `move_right` move the digest away from the
  idle stream; the walk's world x lands in the player's own DrawCommand.
* Room discrimination: the same tick indices in rm_town vs rm_level1 produce
  different sequences.
* Original behaviour visible in the stream: rm_level1 arrival draws the whole
  cast (1354 draws), obj_bg Alarm 2 (CODE 361) sleep sweep reduces it (716)
  within a few ticks — the reduction is the sweep, not a missing door chain.

## Boundaries (not this suite's claim)

* The digest verifies bytecode-emitted command fields, not GPU/raster output;
  device pixels remain the separate registered layer (real-device captures).
* No-periodicity beyond tick-0 is pinned for the town: the view-6 camera
  follows the player, so the stream is deterministic but not constant; the
  period probe prints what it finds rather than pinning a guessed cycle.
* `end_frame` retirement timing is inherited from the client frame loop this
  suite drives through `GameState::step` (same entry point as nativeStep).
