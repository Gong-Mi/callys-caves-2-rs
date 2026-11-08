# Level A first diff report — 2026-11-08

Receipt: `reconstruction/reverse-v1/harness/receipts/level_a_diff-20261108T154757.json`
(schema `cally-level-a-diff/1`, tier `test_anchored`).
Field table: `build/level_a_field_report_20261108T154757.json`.

## Verdict

`合成内存 oracle 层已测，差异 0（输入域：本合同输入集）`

Not full-input-domain equivalence. Not device equivalence.

| run | tree nodes | fields compared | diffs | tree sha (both arms) |
|---|---:|---:|---:|---|
| main, scale 2.0 | 150 | 267 | **0** | `1f543bca…` |
| main, scale 1.0 | 150 | 267 | **0** | `1f543bca…` |
| err_parent, scale 2.0 | 150 | 2 (error) | **0** | `4091a08b…` |
| perturb, scale 2.0 | 146 | 245 | **0** | `f7ccada8…` |

Error tree: both arms return NULL with `Parent bone not found: forearm`.

## Field groups (main, scale 2.0)

| group | fields | diffs |
|---|---:|---:|
| meta | 22 | 0 |
| bones | 39 | 0 |
| slots | 8 | 0 |
| ik | 7 | 0 |
| transform | 14 | 0 |
| path | 12 | 0 |
| skins (skin/entries/region/mesh payload) | 71 | 0 |
| events | 4 | 0 |
| animations (timelines/frames/curves/events) | 88 | 0 |
| error | 2 | 0 |

Every row in the field table carries the original value, rebuild value,
`equal` flag and segment attribution.

## BINDING v1

* original image sha256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`
* per-node sha256 list (150 nodes per main tree), canonical tree sha256 equal on
  both arms for all four runs
* rebuild binary sha256 recorded for each run
* fixture/model/oracle/dump/driver sha256 recorded

## Negative controls

| control | result |
|---|---|
| broken segment: slots blend 1→3 | diff=1 `slots[0].blend`, attribution hits `spine_read_slots` |
| broken segment: bones scaleX slot 0x1c→0x20 | diff=1 `bones[0].scaleX`, hits `spine_read_bones` |
| broken segment: rotate `"angle"`→`"angel"` | diff=3 rotate `frames[1,3,5]`, hits `spine_read_tl_bones` |
| input perturbation (delete translate frame, rename animation) | both arms change on the same 25 fields |
| oracle single-run archive replay | identical 3879-byte archive, sha256 `583b168d…` |
