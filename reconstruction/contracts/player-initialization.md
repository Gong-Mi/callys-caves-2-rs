# Player initialization and unified immediate event entry

Baseline: 2a4eb2460d23d677f54e6016b92d66f3e44c4b76. This batch does not change
legacy GameWorld::update, saves, Android or the device foreground.

## Implemented entry points

- `original_player_create::create`: the full original CODE0, not final-state
  coalescing. Keeps the ending-room hspeed=1 write followed later by hspeed=0,
  both shotgun=0 writes, all hpupgrade2..20 fields, self/global playerdied,
  alarm 10/11 and device_mouse_dbclick_enable(false).
- `original_events::dispatch_player_create`: calls CODE0 through one host.
- `original_events::dispatch_player_alarm`: all direct player alarms 0..8,10,11;
  Alarm9 returns NoDirectEvent and invalid indices return OutOfRange before any
  host call. The numeric legacy API is retained for compatibility; it is not the
  unified entry. The new entry does not return NotRestored for 0/1.
- `original_events::dispatch_projectile_create`: connects all twelve direct
  object Create methods through the same host and resource bindings.
- Adapters exhaustively map every combat/projectile field, global, slot, sound
  and object name. A single host instance sees immediate reads/writes, not three
  copied state structs or an event-entry snapshot. Instance IDs stay typed.
- The nine small alarms use only their own required fields. Alarm11 short
  circuits before healthregenbought when health1==maxhp; callbacks that only
  write do not demand preinitialized unrelated fields.

The shared-map test host actually registers child identities and synchronously
calls the real Create method with a self stack, then restores the caller. Its
registry exists in the TEST, not a production world. A complete fixture runs
player Create -> fire/melee -> release firing/swing -> heal -> elapsed time.
It explicitly supplies builtin values and seven progression globals. Missing
reads panic in this fixture instead of silently becoming zero. The production
host's error propagation, destruction, selector and visibility policies remain
unimplemented; the trait's numeric return type is not a completed error model.

Existing numerical callbacks and unified callbacks also receive the same finite
flag/counter matrices and compare the full resulting state, including unrelated
sentinels and all alarms. This is a Rust preservation oracle, not an independent
GameMaker differential execution or proof of arbitrary GML value semantics.

## Static initialization-source census

`player_initialization.py` scans every one of the pinned 1,354 CODE bodies.
The cohort is CODE0, eleven player Alarm bodies and twelve projectile Creates:
24 methods. It finds 22 directly read global names and 1,290 direct write sites
for those names across the whole CODE universe. Counts are static instruction
sites, not initialization count or executed events.

`player-initialization.json` retains per-name/per-CODE read/write offsets, full
CODE hashes and original object/event/room ownership. Every normal -5 global
VARI read in the cohort participates; every matching pop in the full universe
is classified. Other-scope/indirect same-name writes are retained separately
(the current input has zero in that category). This does NOT prove dynamic
selectors, CFG dominance, branch feasibility or event initialization order.

All source records are reproduced from the original asset in reverse CI. CODE0
GML is separately matched to freshly recovered source in recovery CI; the whole
census/contract is regenerated and byte-compared there as well.

### Seven read globals absent from player Create

| Global | Direct writer CODEs | Important source path (not guaranteed startup order) |
|---|---|---|
| assaultriflelevel | 17,367,368,478 | Player Other_2: Save/assaultriflelevel read, no-save assignment 1; later caps/upgrades/reset. |
| boomeranglevel | 17,367,368,478 | Player Other_2: Save/boomeranglevel read, no-save assignment 1; later caps/upgrades/reset. |
| energywavebought | 17,429,478 | Player Other_2: INI read or 0; purchase and reset writers separate. |
| healthregenbought | 17,431,478 | Player Other_2: INI read or 0; purchase and reset writers separate. |
| maxhp | 12,17,478 | Player Other_2: Save/current_maxhp read or 4; player Step growth and reset also write. |
| swordsound | 365,368 | UI Create and UI Alarm0: choose(13,14), not a fixed sword sound or a fabricated zero. |
| timeplayed | 2,17,478 | Player Other_2: Save/timeplayed read or 0; Alarm10 increments, reset also writes. |

The exact `file_exists("savefile.ini")` and `ini_read_real` branches reside in
CODE17 (`gml_Object_obj_player_Other_2`). That whole method and UI Create are
still NOT ported by this batch. The literal save keys must be retained, even
where spellings look inconsistent. Do not take selected seven assignment lines
out of the method and call original save/startup restoration complete.

## Next dependency batch

1. Recover CODE17's complete startup/save decision method and its direct
   dependencies, plus UI Create CODE365. Separate platform services such as its
   initial AdColony call from state restoration with explicit unsupported policy,
   not silent suppression or replacement of source strings.
2. Establish production instance lifecycle/selector semantics and builtin
   coupling; then define event order and timers against original evidence.
3. Bind the unified entry to that production host, and replace one coherent
   legacy player/weapon lifecycle including Step/collision/destruction.
4. Keep ROOM object coverage, rendering/collision masks, save compatibility and
   all-level/Android acceptance as separate lanes. No new host test closes them.
