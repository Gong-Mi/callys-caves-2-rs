# C reconstruction (M0)

The shipped behaviour is GameMaker bytecode. This directory lowers that bytecode
to C so the mechanism is readable and auditable line by line, instead of being
hidden behind our own IR + VM.

**What this is not:** a second interpreter. Inside a basic block the stack is
tracked symbolically, so `load x; constant 1; add; store x` becomes one C
assignment and a builtin call keeps its original name and arity. Values live
across a branch are carried in named phi variables assigned on every incoming
edge; two edges that disagree on stack depth make the generator **refuse** the
body rather than guess.

## Status (M0)

| item | state |
| --- | --- |
| generator (`scripts/ir_to_c.py`) | 1354/1354 bodies, 0 refused, 52,411 lines of C |
| C host (`c-recon/src/host.c`) | instances, fields, arrays (`alarm` is a 12-slot array), globals, selector resolution, `with` frames, 7 builtins |
| differential harness | state-file protocol shared with `crates/core/examples/ir_state_dump.rs` |
| CODE 792 (`obj_bosspuff_Create_0`) | **C == VM, identical state** |
| CODE 12 (`obj_player_Step_0`) | compiles (2301 lines); needs collision builtins before it can run |

Generated bodies are not yet in the repository (regenerate with the command
below); only the two bodies used by the harness are checked in.

## Usage

```sh
# regenerate C for every body (writes outside the tree by default)
python3 scripts/ir_to_c.py --ir crates/core/src/generated/full_ir.json \
    --all --outdir c-recon/gen

# build the driver for the bodies present in c-recon/gen
clang -std=c11 -O2 -Wall -Ic-recon/include \
    c-recon/src/main.c c-recon/src/host.c c-recon/gen/gml_*.c \
    -o c-recon/build/state_dump

# differential: same fixture through both implementations
python3 scripts/c_vm_diff.py --fixture fixtures/code792.txt --code 792
```

A fixture is the state-file protocol documented in `c-recon/src/main.c`
(`CODE`/`CURRENT`/`INST`/`FIELD`/`ARRAY`/`GLOBAL`). The Rust side
(`ir_state_dump`) inserts instances directly, so both sides start from identical
bytes with no Create events in between.

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

## Next (M1)

1. Collision builtins (`instance_place`, `place_meeting`, `distance_to_object`)
   with the recorded SPRT box, so CODE 12 can run and be diffed.
2. `instance_create` + object Create dispatch, then bodies that spawn.
3. Run the differential across all bodies that the current host can execute;
   each difference is a generator bug or a host bug — never a test to relax.
