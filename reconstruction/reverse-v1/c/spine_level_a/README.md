# c/spine_level_a — Level A function-level differential (④轴 首次实测)

Contract: `reconstruction/contracts/native-equivalence-gate.md`, Level A.
Subject: `spSkeletonJson_readSkeletonData @0x28b84c` (13044 B) of
`libyoyo_armv7.so` SHA256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`.

## What it does

Two arms consume **the same synthetic 32-byte-node Json tree**:

* **original arm** (`tools/level_a_oracle.py`): Unicorn memory oracle. The
  original bytes at `0x28b84c` execute over a full PT_LOAD/BSS image, a bump
  heap, Python answers for the libc/math imports, a planted attachment-loader
  vtable, and a `Json_create` hook that returns the staged tree. `cos`/`sin`
  are prescribed to `1.0`/`0.0`.
* **rebuild arm** (`fixture/level_a_dump.c`, qemu-arm): the assembled
  `c/spine_read_skeleton/` chain plus every segment/glue module and the nine
  timeline families, with the same synthetic creators the chain checker uses
  (plus exact-curve writers whose arithmetic is transcribed from
  `spCurveTimeline_setCurve`).

Both arms dump the terminal state into one record grammar
(`tools/level_a_dump.py`): all 21 `spSkeletonData` words, then per-element
records for bones/slots/ik/transform/path/skins+attachments/events/animations
(types, counts, names, float **bit patterns**, frame bits, curve bits, event
payloads). `tools/level_a_diff.py` flattens both sides to 267 fields and reports
every field with its value and segment attribution.

The tree is written once (`tools/level_a_model.py`) and emitted twice: into
Unicorn memory and as generated C (`build/level_a_tree.inc`). Both arms also
serialise their tree with the same byte grammar; the two sha256 values must
match (BINDING v1).

## Run

```sh
cd reconstruction/reverse-v1/c/spine_level_a
python3 tools/level_a_diff.py --run
```

Output: `build/level_a_report-<stamp>.json` and the receipt
`reconstruction/reverse-v1/harness/receipts/level_a_diff-<YYYYmmddTHHMMSS>.json`
(schema `cally-level-a-diff/1`).

First run (2026-11-08): **PASS** (receipt
`level_a_diff-20261108T154757.json`)

```
main_s2p0        diff=0 tree_match=True
main_s1p0        diff=0 tree_match=True
err_parent_s2p0  diff=0 tree_match=True (both NULL, "Parent bone not found: forearm")
perturb_s2p0     diff=0 tree_match=True
NC1 broken_segment passed=True
NC2 input_perturbation passed=True (25 changed fields each arm, sets equal)
NC3 oracle_archive passed=True (identical sha256)
```

## Input set

| tree | content |
|---|---|
| `main` | skeleton meta; 3 bones (root←arm←hand); slot (additive, color ff000080, attachment reg); ik; transform; path; skin default with region + mesh; event step; animation walk with rotate (3 frames: array curve, stepped, plain), translate (2 frames), event frame |
| `err_parent` | main with `arm.parent = forearm` → `Parent bone not found: forearm` |
| `perturb` | main without the last translate frame, animation renamed `walk2` |

Scales 2.0 and 1.0 both run on `main`; the error and perturbation trees run at
2.0.

## Negative controls

1. **broken segment** — three mutants, each rebuilt from a mutated segment
   source and diffed against the original baseline:
   `spine_read_slots` blend 1→3 → `slots[0].blend`;
   `spine_read_bones` `BD_SCALEX_OFF` 0x1c→0x20 → `bones[0].scaleX`;
   `spine_read_tl_bones` `"angle"`→`"angel"` → rotate `frames[1,3,5]`.
   Every diff group hits the mutated segment.
2. **input perturbation** — the changed-field set is recomputed on both arms
   against their own baselines; both sets are equal and non-empty (25 fields).
3. **oracle archive replay** — the original arm runs once per subprocess,
   archives its dump, and a second subprocess must reproduce the bytes
   (`583b168d…`, 3879 B).

## Scope wording (contract)

`合成内存 oracle 层已测，差异 0（输入域：本合同输入集）`

**不是全输入域等价，不是设备等价。** The original arm is a synthetic-memory
Unicorn execution; the rebuild arm is reconstructed C under qemu-arm. The
attachment loader (atlas dims/UVs) and all timeline creators are declared
synthetic boundaries, aligned on both arms by construction.

## Harness pitfalls fixed here (useful for the next oracle)

* The live-mem dump's `.data` ABS32 slots `0x3f7790/0x3f7794` are **zero**;
  `_malloc/_free` must be given stub addresses or they `blx 0`. The loader also
  calls `free@plt` directly (`0x28b8c4`), so hook both the slots and the PLT.
* PLT0 is 20 bytes and entries are 12 bytes; use `handler_oracle.plt_symbols()`
  (derived, not assumed). In this dump every GOT slot points at PLT0, so an
  unhooked import jumps to nonsense; the oracle guards every remaining PLT entry
  and names it instead of dying at `pc=0`.
* VFP: `C1_C0_2=0x00F00000`, `FPEXC=0x40000000` or every `vpush` traps.
* `spEventTimeline_setFrame` is **3-argument** `(timeline, frameIndex, event)`;
  the time is `event+0x04`. A 4-argument signature silently stores the event
  pointer as a float.
* Event timeline `+0x14` is outside the 20-byte record; do not compare it.
* `spCurveTimeline_setCurve` writes 19 floats per interval (`2.0` marker plus
  18 samples); the exact VFP sequence is required for bit-equal curves. The
  stepped marker is at `curves[frameIndex*19]`, so the tree uses 3 rotate frames
  to keep index 19 in bounds.
* The mesh fixture's `free()` roster is limited to 256 entries; the chain's
  dispose path frees more. The Level A fixture renames that provider and supplies
  a no-op `free`.
* `spSkeletonData` bones dump: 8 scalar words, not 9 (the first decoder draft
  read one word too many and desynced).
* Frame counts for bone timelines are `frameFloatCount / step`
  (rotate 2, translate/scale/shear 3, ik 3, transform 5, color 5, path 2,
  path-mix 3).

## Files

```
tools/level_a_model.py    single-source trees, canonical bytes, C emitter
tools/level_a_oracle.py   Unicorn original arm
tools/level_a_dump.py     shared binary/record decoder (both arms)
tools/level_a_diff.py     driver: build, run, diff, attribution, negative controls, receipt
fixture/level_a_dump.c    rebuild-arm fixture (synthetic creators + binary dump)
functions.json            module manifest
build/                    generated tree include, ARM binaries, logs, reports
```
