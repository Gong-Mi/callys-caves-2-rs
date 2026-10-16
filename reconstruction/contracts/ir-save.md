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

## Original semantics: the original saves no player coordinates (WL10)

Judgement, from the recovered GML only (canonical `0017__gml_Object_obj_player_Other_2.gml`,
SHA-256 `dc640893db3b07c6fe5ce278157d039c7223acea70e4d40133aaf8b83569a23b`, identical in
every recovered tree). Exhaustive inventory of every `ini_write_real`/`ini_read_real` in the
recovered corpus — 4 files touch the save (`0015` obj_player Other_5 = Room End,
`0017` Other_2 = Game Start, `0478` data reset, 16 lloydtutorial Destroy codes):

- `savefile.ini`: 320 distinct keys, all in the `[Save]` section — `talkedtolloyd1..16`,
  `current_level`/`current_maxhp`/`current_score`/`current_XP`, `boss1..6dead`,
  bought/xp/xptolevelup/level per weapon, `drawchange*{4,7,10}`, `*killed`/`*touched`
  counters, achievements, `haskey`, `timeplayed`, `gemdropenabled`, `poisonenabled`,
  `musicmute`, `soundmute`, and the room progression flags `roomtownvisited`,
  `room31..103visited`, `level1..17visited` (+`level8a/9a/11a/13a/14a/15a/16a/17avisited`),
  `boss1..6visited` (CODE17 reads 6-289, writes 585-866; CODE15 writes 3-286).
- `savefile2.ini`: `levelchallenge1..5visited` + `talkedtolloyd16` (CODE17 870-895, CODE15 287-293).
- `savefile3.ini`: the `twentyfive*`/`onehundred*`/`fivehundredenemies`/`onethousandenemies`
  achievement counters (CODE17 896-978, CODE15 294-331).
- **No key holds a player x/y, a current-room id, a door or a checkpoint of any kind.**
  `global.roomcamefrom = room` (0015:2, Room End) is runtime state only, never written.
  `filesave.ini` occurs exactly once, in the reset handler's `file_delete` (0478:1), and has
  no producer.

Room progress is therefore recorded at **two granularities, both non-positional**: a boolean
"visited" flag per room/level/boss (which the map menu reads to unlock warps), plus
`current_level` (a progression index, not a location). There is no resume pointer.

Every original path that puts the player back into a room repositions onto a per-room
constant, never onto a stored position:

- Room entry: `global.startx/starty` are per-room constants set by the room's obj_bg Create
  (0360, one case per room); obj_player Room Start (0016:15-20) applies them only when
  `global.warpfrommap == 1`, otherwise the player keeps the room record's placement.
- Map warp (0692:114-117): `warpfrommap = 1`, `room_goto(id.goto)`, then `x/y = startx/starty`.
- "Back to game" (0470:3,11-12): `room_goto(global.roomcamefrom)` **and** explicitly
  `obj_player.x = global.startx; y = global.starty` — the original throws the live position
  away on its own pause/map return.
- Death (0540:2-3): the same `startx/starty`.
- `persistent` appears nowhere in the corpus (0 hits), so no instance, the player included,
  carries a position across rooms.

Conclusion (branch (a) of the WL10 directive): **not writing player coordinates is the
original semantic, and "room start on resume" is what the original itself does.** The
rewrite matches: the IR autosave writes `Checkpoint { room_index: room, x: 0.0, y: 0.0 }`
(crates/client/src/lib.rs 319-331) and `restore_ir_snapshot` (292-308) hands the scene only
room/globals/score/collected, so player placement comes from the room record
(`ir_scene::load_room_from_data` materializes obj_player at its recorded x/y, skipped when the
persistent instance is already alive). The legacy path does store a `checkpoint` (save.rs
13/85) and does apply it (crates/core/src/lib.rs 410-412), but its value is the room placement
(lib.rs 465-469) or a warp arrival point (lib.rs 847-851) — an entry point either way, never a
live mid-room position.

So WL4's registered item "往返不续帧" is a fidelity property, not a defect: no coordinate
field is to be added. The room pin (`current_room`) stays as the rewritten schema's own
addition, with no original counterpart to reconcile. Pinned by
`crates/client/tests/ir_save_roundtrip.rs::ir_autosave_persists_no_player_coordinates_and_restore_lands_at_room_start`
(file keeps the placeholder checkpoint while the live player stands elsewhere; a cold restore
leaves the player on rm_town's recorded obj_player placement, 416/492).

## Boundaries

Not original savefile.ini compatibility; schema is the rewritten v2 JSON with
two added optional fields. Autosave is per-frame post-tick (progression fields
only), not the original's save-point behavior; no save menus. Cold restore
re-loads the saved room; non-persistent coins respawn per original data, only
identities in the collected list stay dead. No device/ART acceptance; host
tests only. checkpoint/max_health fields in IR-path saves are placeholders
(legacy schema values), not IR scene state.
