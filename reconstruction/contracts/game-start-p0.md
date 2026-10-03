# Game Start (CODE 17) production boot chain — P0

Status: runtime_verified in the Rust scene host (this repo's `Scene`), exact-head CI.
Device evidence (real Android launch/save/visual): NOT RUN in this batch.

## What changed

The production boot no longer fakes Game Start with `init_fresh_start_globals()`
defaults and no longer keeps the prologue in a separate hand-built scene. The
boot is now the original single-scene chain, driven by the real compiled
bytecode:

1. `enable_ir_gameplay` materializes the first room's instances first (their
   Create events run as placed), then dispatches Event 7/2 (Game Start,
   CODE 17) on the live player — GM's first-room order. (An earlier revision
   dispatched Game Start *before* the room load; CODE 548's
   `instance_deactivate_all(true)` then only saw the player, and the whole
   room — plus its touch buttons — stayed ACTIVE through the prologue: the
   live town kept stepping and drawing behind the film while the follow
   camera dragged view 6 away from the intro film's composition rect.)
2. CODE 17 runs as bytecode: AdColony_Init (host no-op), the three INI reads
   (`savefile.ini` / `savefile2.ini` / `savefile3.ini`) through the real file
   boundary (`Scene::ini_disk_dir`: `file_exists` checks the directory,
   `ini_open` loads the disk file into the scene cache, `ini_close` flushes the
   open file back to disk), the weapon damage ladders, and the final
   `instance_create(x, y, obj_introduction)`.
3. The prologue therefore rides the full scene: CODE 548 (intro Create) runs
   `instance_deactivate_all(true)` with the whole room already materialized,
   so ONLY the intro film set (obj_introduction / obj_phone / the
   viewresolution pair) stays active; the town sits frozen behind it (touch
   buttons dark, background not drawn, players frozen) and the follow camera
   stays parked at the room's view rect — the film's phone (y≈-2, sliding
   xx1 110→10) is composed against that rect.
   The old second `enable_ir_gameplay` at intro death is deleted — it silently
   discarded a restored save scene (double-init defect).
4. Room Start (7/4) dispatch reaches ACTIVE instances only, matching the
   original engine's event scheduler.
5. Intro death (CODE 549: `instance_activate_all`, `global.health1=4`, phone/
   logo cleanup) hands the SAME scene to gameplay; the handover clears the
   input edges and applies any boot-time IR restore
   (`queue_boot_ir_restore` + `pending_ir_restore`).

## Bytecode facts this batch pinned (all from full_ir.json disassembly)

- CODE 17's INI defaults are UNCONDITIONAL stores: a savefile.ini always
  overwrites the fresh-start baseline (`current_maxhp` default 0 → maxhp=0
  before its cold-start branch runs).
- CODE 17 cold-start branch (no savefile.ini): level=1, maxhp=4,
  xptolevelup=30, health1=4. INI-present branch: level=maxhp=health1=4+
  score=100 block runs after the INI block.
- `global.roomstart` writers census: CODE 0 (Create, =0), CODE 5 (Alarm 6, =0),
  CODE 16 (Room Start, =1 **only when room==110 = rm_ending**, with
  alarm[6]=10), obj_lloyd Step CODE 675 (=1 at distance<100), the sixteen
  obj_lloydtutorialN Destroy codes (=0). Town roomstart comes from the Lloyd
  gate, NOT Room Start — the old regression asserted a value the original
  never produces in town.
- CODE 548's real alarms are alarm[0]=120, alarm[1]=30 only; the handwritten
  `original_startup.rs` trace (alarm[2]/[3]=70) drifts from the shipped
  bytecode. CODE 549 additionally clears obj_logo (135), not just the phone.
- Upgrade reconciliation ladder (player Step, CODE 12): for N in 2..=20,
  `level==N && hpupgradeN==0 → maxhp=N+3, health1=maxhp, hpupgradeN=1`
  (hpupgrade2 → 5, level 23 cap block earlier in the ladder). The INI's
  `current_maxhp` therefore only rules the instant before the first player
  Step; the ladder is the original authority and reconciles a restored
  maxhp=7 @ level 3 down to 6 immediately. This is original fidelity, not a
  restore defect.

## GM semantics correction

Variable reads/writes through object selectors reach DEACTIVATED instances
(a deactivated obj_player still answers `obj_player.x` from CODE 361's sleep
sweep); only the event scheduler (tick/collision/Room Start/Draw) ignores
inactive instances — deactivated instances are neither stepped NOR drawn.
Binary-verified against the shipped `libyoyo.so` (32-bit ARM, dynsym):
`CInstance::SetDeactivated` writes the flag byte at instance +0x69, and
`DrawInstancesOnly(tagYYRECT*)` walks the room's draw list skipping every
entry whose +0x69 is set (checked before both the draw-event dispatch and the
default-sprite branch), so an instance deactivated by CODE 548 disappears
from the frame as well as from the scheduler. `Scene::select_for_access`
implements the reach-through rule for reads/writes, and `ir_scene`'s
`draw_view` gates both the world pass and the GUI pass on `active`. The view
follow in `GameState::camera_position_for_scene` likewise only sees ACTIVE
instances: a deactivated follow target leaves the view parked at the room's
view rect (this is what keeps the intro film composed at (0,0) while the
player is frozen behind it).

Room LAYERS are the other half of the boot frame: the runner's per-frame room
draw (`DrawTheRoom`) clears the surface, runs Draw-Begin, then calls
`DrawRoomLayers` over the room's layer set (backgrounds/tiles) whenever the
room has layers — outside the instance pass — and only then draws instances
per visible view slot. Room layers therefore render on every frame regardless
of instance state, and the prologue frame is the room's tile layers + the
film (matching the original capture annotation "sea/cliff backdrop +
scrolling poster"), never the frozen town's instances. The client's prologue
branch mirrors that ordering: bg tiles (depth >= 0) → film draws → fg tiles
(depth < 0); its instance queues (backgrounds/texts) are empty by
construction while the film runs.

## Tests

- `game_start_p0.rs` (4): cold-start baseline + intro spawn; INI disk read +
  Room End (CODE 15) INI flush round-trip; boot save survives the prologue
  handover without rebuild (maxhp=7 intact at handover, ladder-reconciled to
  6 on the next frame); first boot leaves only the intro film active over a
  frozen room (boot order: Game Start after the room load; player/obj_bg
  inactive, camera parked at (0,0), film draws only and no instance layers on
  the film frame, retirement wakes the room in the same scene).
- `prologue_layers_consumption.rs` (3): the instance-layer consumption proof
  runs on the first gameplay frame (boot, retire the film with the original
  tap gate, then A/B clear each queue and pixel-diff); the single-image
  draw_background no-tiling check runs on the film frame with a hand-built
  command (the film frame's own instance queues are empty — deactivated
  instances are not drawn).
- `prologue_render_regression.rs`: prologue rides the full scene (CODE 17
  spawns the intro; draw_view fills draws; tap retires the intro in-scene).
- `first_chapter_playthrough.rs`: `boot_like_android` mirrors the new
  nativeInit (one `enable_ir_gameplay`, no separate intro scene).
- `prologue_natural_end.rs`: the prologue's full natural run — fast scroll
  -2/frame (moving=1) → alarm[1] (~f29) slow scroll -1/frame (moving2=1) →
  alarm[3] (~f68) parks the film → alarm[2] (~f69) spawns obj_logo →
  alarm[0] (~f119) unlocks taplock → no timer death exists; only a real tap
  retires the intro.

## Prologue visual pipeline (asset truth)

The "film" is obj_phone (136, sprite 161 — a SINGLE 208x320 frame per the
SPRT record, not a 96-frame strip): CODE 555 pins its x to the scrolling
xx1 per active view and CODE 547 draw_self renders it, so the intro motion
is the xx scroll, not sprite animation. obj_logo (135, sprite 160) fades in
via CODE 546 (logoalpha += 0.02 per Draw, drawn at x1). CODE 548's
image_speed = 0.3 on obj_introduction is inert: sprite 161 has one frame
and the engine never advances a 1-frame sprite (matches GMS). The old
"96-frame film sprite" comment was wrong and is gone.
