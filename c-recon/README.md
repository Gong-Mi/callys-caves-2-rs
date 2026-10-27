# C reconstruction (M2)

The shipped behaviour is GameMaker bytecode. This directory lowers that bytecode
to C so the mechanism is readable and auditable line by line, instead of being
hidden behind our own IR + VM.

**What this is not:** a second interpreter. Inside a basic block the stack is
tracked symbolically, so `load x; constant 1; add; store x` becomes one C
assignment and a builtin call keeps its original name and arity. Values live
across a branch are carried in named phi variables assigned on every incoming
edge; two edges that disagree on stack depth make the generator **refuse** the
body rather than guess.

## Status (M2)

| item | state |
| --- | --- |
| generator (`scripts/ir_to_c.py`) | 1354/1354 bodies, 0 refused, 52,411 lines of C |
| C host (`c-recon/src/host.c`) | instances, fields, arrays (`alarm` is a 12-slot array), globals, selector resolution, `with` frames, `room_width`/`score` pseudo-fields |
| collision (`c-recon/src/collision.c`) | `instance_place` / `place_meeting` (box + mask pixels), `distance_to_object`, mask line/point probes; 109 assertions |
| objects (`c-recon/src/objects.c`) | `instance_create` + Create dispatch through `registry.c`, audio voice table; 140 assertions |
| with / destroy (`c-recon/tests/env_test.c`) | 142 assertions; six shipped-body C↔VM scenarios with 101 expectations (`scripts/env_fanout_diff.py`) |
| rooms (`c-recon/src/rooms.c`, `c-recon/gen/rooms_data.c`) | all 114 rooms / 71,014 placements / 551 RoomCC bindings; 29 assertions; nine warp scenarios with 79 expectations |
| Draw (`c-recon/src/draw.c`, `c-recon/src/builtins2.c`) | sprite/text/healthbar/background queues, default sprites, depth order and Draw GUI phase; 15 scenarios / 60 expectations; town 179 and tile-bearing level1 1352 commands |
| Draw corpus (`scripts/draw_corpus_summary.py`) | **118/118 bodies C == VM** under the generic Create→body fixtures: 113 emit 253 commands, four emit none, one same-reason abort; negative controls included |
| strings | all 3210 STRG entries read directly from `game.droid`; static and dynamically allocated pooled text is dumped as actual UTF-8 bytes |
| geometry | 178 SPRT records emitted from `game.droid` (`c-recon/gen/sprites.c`) |
| masks | 227 SPRT collision masks (341 KB of bits) emitted into the same file; `collision_line(prec=1)` walks them |
| CODE 792 (`obj_bosspuff_Create_0`) | **C == VM, identical state** |
| CODE 12 (`obj_player_Step_0`, 6163 instructions) | **C == VM, identical state** |
| batch differential (`scripts/batch_diff.py`) | **1354/1354 identical (Create→body); 24,372/24,372 with 18 worlds each** |

The batch run is a generator/host self-consistency check, not original-runner
parity: the fixtures are generic (owning object, room 0, x=y=100), so a body
that needs a different receiver aborts on both sides (`SAME_ABORT` = same
reason, not same behaviour), and alarm/step timing is not exercised. What it
does buy is the whole 1354-body loop in one pass: one bundle load per side
instead of one per body (~0.5 s each on the Rust side).

Draw equality is at the GML command-stream layer, including payload, provenance,
phase and depth order. It is not rasterizer, framebuffer, original-runner or GPU
parity. ROOM tile and particle queues are separate inputs and are not included
in the Draw census. A valid live-particle path such as CODE 356 after CODE 458
still aborts in the C host and is **not** counted as a successful particle proof;
the generic no-system same-abort result must not be confused with that path.
The sole Draw GUI body (CODE 539) is empty, so it does not supply a non-empty
original GUI command stream.

CODE 12 exercises collision (`instance_place` against `obj_knifebandit`), damage,
alarms, item drop, `instance_create`, audio and the LCG. That it matches means
the ported engine primitives and the generated body agree, not that any game
behaviour is "done".

Generated bodies are not all in the repository (regenerate with the command
below); only the bodies the harness uses are checked in.

## Usage

```sh
# regenerate C for every body
python3 scripts/ir_to_c.py --ir crates/core/src/generated/full_ir.json \
    --all --outdir c-recon/gen

# regenerate the object table and the dispatch switch
python3 scripts/gen_object_table.py --ir crates/core/src/generated/full_ir.json \
    --out c-recon/gen/objects_data.c
python3 scripts/gen_registry.py --gen c-recon/gen --out c-recon/gen/registry.c

# regenerate every ROOM placement, RoomCC binding and view default
cargo run -q -p callys-asset --example dump_rooms_c -- \
    assets/game.droid crates/core/src/generated/full_ir.json c-recon/gen/rooms_data.c

# build the driver
SRC="c-recon/src/main.c c-recon/src/host.c c-recon/src/collision.c \
     c-recon/src/objects.c c-recon/src/builtins2.c c-recon/src/rooms.c \
     c-recon/src/draw.c c-recon/gen/objects_data.c c-recon/gen/rooms_data.c c-recon/gen/registry.c \
     c-recon/gen/gml_*.c c-recon/gen/sprites.c"
clang -std=c11 -O2 -ffp-contract=off -Wall -Ic-recon/include $SRC \
    -o c-recon/build/state_dump -lm

# differential: the same fixture through both implementations
python3 scripts/c_vm_diff.py --fixture c-recon/fixtures/code12_contact.txt --code 12

# whole-corpus differential: one process per side for all 1354 bodies
# (--build-c regenerates + compiles every body into --work, ~25 s)
python3 scripts/batch_diff.py --build-c --work .hermes-batch
python3 scripts/batch_diff.py --build-c --matrix --work .hermes-batch   # 18 worlds per body
# richer receiver set: one instance of every object, so a body that reads
# another object's fields runs its real path instead of aborting
python3 scripts/batch_diff.py --build-c --sequence --all-objects --work .hermes-batch

# targeted with/destroy scenarios; default rebuilds checked-in C and current Rust
python3 scripts/env_fanout_diff.py --work "$TMPDIR/env"

# full-corpus room warp scenarios (Create/RoomCC dependencies included)
python3 scripts/env_fanout_diff.py --fixtures c-recon/fixtures/rooms \
    --build-c --work "$TMPDIR/rooms"

# checked-in Draw scenarios and real-room/full-body Draw scenarios
python3 scripts/env_fanout_diff.py --fixtures c-recon/fixtures/draw \
    --work "$TMPDIR/draw"
python3 scripts/env_fanout_diff.py --fixtures c-recon/fixtures/draw_full \
    --build-c --work "$TMPDIR/draw-full"

# independently audit the 118-body Draw output census after batch_diff
python3 scripts/draw_corpus_summary.py --work "$TMPDIR/draw-corpus"
```

Two build flags are not cosmetic:

* `-lm` — bionic keeps `libm` out of the default link, and the rotated-box path
  needs `sinf`/`cosf`.
* `-ffp-contract=off` — clang contracts `a + b*c` into an FMA, Rust does not.
  Leaving it on moved `0.35695191991025244` by one ULP, which the harness
  correctly reported as drift.

A fixture is the state-file protocol in `c-recon/src/main.c`
(`CODE`/`CURRENT`/`OTHER`/`ROOM`/`ROOMW`/`ROOMH`/`INST`/`ACTIVE`/`FIELD`/`ARRAY`/`GLOBAL`).
`WARP <id>` seeds a pending transition; a bare `WARP` consumes it at the client
boundary. `COLLIDE <code> <self> <other>` sets `other` only for that body and
restores it before the next operation. `DRAW <view>` clears the GML queues and
runs the normal Draw + Draw GUI scheduler. `VIEW <i> <visible> <x> <y> <w> <h>`
seeds effective view state for that operation and is also printed in dumps;
unset ports fall back to the display size. Output `DRAW` lines carry queue kind,
phase, CODE/offset, instance/view, depth and payload; text bytes are hex encoded.
`INST` accepts `<id> <object> [alive [active]]`; both flags default to 1. Dumps
print `ACTIVE <id> 0` only for deactivated instances, leaving ordinary dumps
byte-for-byte unchanged. `ACTIVE` is dump-only metadata, not a second fixture
input directive; input uses the fourth `INST` token. The Rust
side (`ir_state_dump`) inserts instances directly and loads SPRT geometry from
`--asset assets/game.droid`; without that geometry every instance degenerates to
an integer point and a body testing `instance_place` takes the miss branch.

Instance ids in a fixture must be **≥ 100000**: that is the absolute-id space
(`ir_scene.rs:1474`). A fixture using 1000/1001 makes a stored collision result
scan the object table instead of the instance table.

## Design rules

1. **Never silently skip.** An unsupported op, a merge with inconsistent stack
   depth, or an unknown field name stops generation for that body. The count of
   refusals is part of the result.
2. **Keep the original names.** Builtin calls, field names and branch targets
   survive into the C text, so it can be diffed against the recovered GML and
   the `libyoyo` disassembly.
3. **Every primitive needs a source.** A host function without an original
   anchor (GML line, `libyoyo` address, or asset field) is marked unrecovered in
   the mechanism ledger; it is not silently "close enough".
4. **A call is never pure.** `popz` drops pure expressions; marking a builtin
   call pure deleted 11,201 statement-position calls (every `audio_play_sound`
   among them) before this was caught.
5. **A difference is a bug, not a formatting detail.** The dump prints sorted
   fields and shortest round-trip numbers precisely so that a line diff means
   behaviour, not printer dialect.

## Next (M3)

1. Merge ROOM tile and particle inputs into the ordered C command stream; they
   are not GML `draw_*` calls and are deliberately absent from the M2 census.
   First close the valid CODE 458→356 live-particle path with a success fixture.
2. Add a C raster consumer and an independent original command/frame oracle.
   Matching C and VM queues proves host/generator consistency, not pixel parity.
