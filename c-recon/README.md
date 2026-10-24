# C reconstruction (M1)

The shipped behaviour is GameMaker bytecode. This directory lowers that bytecode
to C so the mechanism is readable and auditable line by line, instead of being
hidden behind our own IR + VM.

**What this is not:** a second interpreter. Inside a basic block the stack is
tracked symbolically, so `load x; constant 1; add; store x` becomes one C
assignment and a builtin call keeps its original name and arity. Values live
across a branch are carried in named phi variables assigned on every incoming
edge; two edges that disagree on stack depth make the generator **refuse** the
body rather than guess.

## Status (M1)

| item | state |
| --- | --- |
| generator (`scripts/ir_to_c.py`) | 1354/1354 bodies, 0 refused, 52,411 lines of C |
| C host (`c-recon/src/host.c`) | instances, fields, arrays (`alarm` is a 12-slot array), globals, selector resolution, `with` frames, `room_width`/`score` pseudo-fields |
| collision (`c-recon/src/collision.c`) | `instance_place`, `place_meeting`, `distance_to_object`; 89 assertions |
| objects (`c-recon/src/objects.c`) | `instance_create` + Create dispatch through `registry.c`, audio voice table; 132 assertions |
| geometry | 178 SPRT records emitted from `game.droid` (`c-recon/gen/sprites.c`) |
| CODE 792 (`obj_bosspuff_Create_0`) | **C == VM, identical state** |
| CODE 12 (`obj_player_Step_0`, 6163 instructions) | **C == VM, identical state** |

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

# build the driver
SRC="c-recon/src/main.c c-recon/src/host.c c-recon/src/collision.c \
     c-recon/src/objects.c c-recon/gen/objects_data.c c-recon/gen/registry.c \
     c-recon/gen/gml_0012.c c-recon/gen/gml_0792.c c-recon/gen/sprites.c"
clang -std=c11 -O2 -ffp-contract=off -Wall -Ic-recon/include $SRC \
    -o c-recon/build/state_dump -lm

# differential: the same fixture through both implementations
python3 scripts/c_vm_diff.py --fixture c-recon/fixtures/code12_contact.txt --code 12
```

Two build flags are not cosmetic:

* `-lm` — bionic keeps `libm` out of the default link, and the rotated-box path
  needs `sinf`/`cosf`.
* `-ffp-contract=off` — clang contracts `a + b*c` into an FMA, Rust does not.
  Leaving it on moved `0.35695191991025244` by one ULP, which the harness
  correctly reported as drift.

A fixture is the state-file protocol in `c-recon/src/main.c`
(`CODE`/`CURRENT`/`ROOMW`/`ROOMH`/`INST`/`FIELD`/`ARRAY`/`GLOBAL`). The Rust
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

## Next (M2)

1. Run the differential across every body the host can execute today; each
   difference is a generator bug or a host bug.
2. `instance_destroy` + `with` fan-out over destroyed instances, then bodies
   that iterate rooms.
3. `draw_*` — 2796 `draw_sprite_ext` calls are currently recorded as calls into
   an unimplemented builtin, so a drawn frame still has no C-side oracle.
