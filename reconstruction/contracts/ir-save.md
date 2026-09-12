# IR-path save/restore

User directive context: original savefile.ini compatibility remains out of
scope; this slice gives the IR scene its own persistence for bidirectional
(cross-session) testing.

## Snapshot contents

`Scene::save_snapshot` returns (room, globals subset, shared score, collected
transient instance ids). Persisted globals are exactly `SCENE_SAVE_GLOBALS`:
progression counters (level/maxhp/health1/experience/xptolevelup), audio mutes,
haskey/coinmultiply, death count, ending flags, all weapon-shop bought flags,
boss/levelchallenge flags. Room-start/UI transient globals never persist.
Collected ids exclude player(0)/UI(66)/persistent objects, matching
`transition_to_room`'s retention policy exactly; external/test instances are
never captured. `restore_snapshot` applies globals over fresh defaults, sets
score, loads the saved room, then removes collected identities.

## Wiring

`SaveData` (v2) gains `scene_globals` + `score` with `#[serde(default)]`;
v1/v2 files load unchanged with empty/zero defaults, future versions still
rejected. `to_json` drops non-progression globals defensively. The IR client
path autosaves after every successful frame when the snapshot changed (same
atomic temp+rename file `save-v2.json` as the legacy path; write errors surface
via save_diagnostic). `nativeInit` restores any v2 file that carries scene
progress after the full-IR bundle loads; files without scene progress fall
back to the legacy world restore, untouched. Failed frames never autosave.

## Tests

`ir_save_roundtrip.rs`: session1 collects a real CODE12 coin with
coinmultiply=2 -> snapshot; JSON byte-stable round-trip; transient `roomstart`
filtered; cold session2 restores room/score/multiplier, collected coin absent,
15 real client frames error-free. `persistent_state_autosaves_and_reloads`:
new_persistent writes the file on frame, cold new_persistent reloads it.
`save.rs`/`save_io.rs` extended for the new fields; all five legacy save tests
still green.

RED evidence: first full-suite run failed `ir_progress_survives...` because
the snapshot captured the persistent player (identical policy mismatch, fixed
by matching transition retention); a draft assertion expected coinpickup to
persist, but original obj_UI Step CODE369 zeroes it when no coinadd exists —
the test now uses haskey and documents that coinpickup is transient by
original design.

## Boundaries

Not original savefile.ini compatibility; schema is the rewritten v2 JSON with
two added optional fields. Autosave is per-frame post-tick (progression fields
only), not the original's save-point behavior; no save menus. Cold restore
re-loads the saved room; non-persistent coins respawn per original data, only
identities in the collected list stay dead. No device/ART acceptance; host
tests only. checkpoint/max_health fields in IR-path saves are placeholders
(legacy schema values), not IR scene state.
