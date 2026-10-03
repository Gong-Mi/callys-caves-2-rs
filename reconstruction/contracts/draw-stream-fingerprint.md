# Draw-stream frame fingerprint (render batch: visual verification without pixels)

Suites: `crates/client/tests/draw_stream_frame_fingerprint.rs` and
`crates/client/tests/draw_stream_sensitivities.rs` (callys-client; identical
FNV algorithm, digests mutually comparable).

## Contract

The four public queues are projections of the bytecode/engine command stream,
not its complete cross-category render order. Their historical FNV-1a encoding
uses truncation of `x*8` / `x*1000` and omits room tiles/particles. It is a remake
regression baseline, not an original-runtime equivalence oracle. Actual rendering
consumes `ordered_draw_commands` with numeric depth, emit order and GUI phase;
`draw_order_ir` and `draw_order_consumption` independently assert that contract.

Pinned regression facts (1136x640/view-0 town and full-cast level1):

* Determinism: two cold boots replay identical 30-tick digest sequences
  (town idle, level1 through the door chain + sleep sweep).
* Historical town content anchor remains `0x1500da8c98db82f5`
  (180 draws / 3 texts / 1 bg / 2 healthbars). A test-only legacy encoder
  reconstructs its former default-first grouping and stale default CODE377
  provenance. No production renderer uses this adapter, and no new hash is
  recorded merely to accept the repaired order. Current order is separately
  required to walk descending room depth, followed by GUI; engine defaults
  explicitly carry `(code=usize::MAX, offset=0)` rather than an unrelated CODE.
  Old/new probes confirmed identical visual payload multisets and identical
  text/background/healthbar queues before this encoding separation.
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
* No-periodicity beyond tick-0 is pinned for the town: the runtime camera
  follows the player, so the stream is deterministic but not constant; the
  period probe prints what it finds rather than pinning a guessed cycle.
* `end_frame` retirement timing is inherited from the client frame loop this
  suite drives through `GameState::step` (same entry point as nativeStep).

## Sensitivity suite (draw_stream_sensitivities.rs) — pinned transitions

* Lloyd sheet freeze: after the proximity hand-over the room collapses to
  (almost) the sheet's own drawers — the 180-draw town idle cannot recur —
  while the sheet's panel alarm ladder keeps changing the digest with the
  world frozen. Both halves are emission facts, not screenshot inference.
* Boss-1 kill chain: obj_trex contributes draws while alive; after the real
  shoot-button kill (CODE 11 bullet -> CODE 284 -> CODE 160) its instance id
  is gone from the stream and the boulder gate (CODE 29) clears within 35
  ticks; alive-vs-dead arena digests differ.
* Three-room discrimination: town, level1 and the post-boss Mines (room 11,
  only reachable through the killed gate) produce three distinct idle
  digests — no cross-room stream confusion.
* Reproducibility: run 3x green locally (104s / 73s / 94s), the RNG-driven
  kill chain included (hptrex=1 injection is the registered
  engine-recomputes-globals discipline, not a fabricated kill).
