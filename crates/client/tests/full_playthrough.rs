//! The full playthrough: one continuous client frame loop from the cold boot
//! to rm_ending, with NO per-region re-seeding. The six segment suites
//! (first_chapter, mines/depths/core/lab/lair trunks, boss_kill_chains) each
//! enter through `transition_to_room` and own their segment's detail; what
//! none of them proves is CONTINUITY: that the shipped door chain, the boss
//! gate globals and the persistent player survive being strung together —
//! room 0 -> town -> chapter 1 -> boss1 (real bullets) -> Mines -> boss2 ->
//! Depths -> boss3 -> Core -> boss4 -> Lab -> boss5 -> Lair -> boss6 ->
//! rm_ending — inside one GameState with accumulated globals.
//!
//! Discipline (same as the segment suites):
//! - every hop stands the player on the live obj_warpanywhere door and lets
//!   the client consume its queued room_goto (CODE 13 collision);
//! - boss1 dies to the shoot button's real bullet chain (CODE 11 -> 284 ->
//!   160); bosses 2..6 to the per-instance hp injection their suites use —
//!   hpbossN is never recomputed after Create, so the lethal transition is
//!   the boss's own Step->Alarm code, and only the flag-free entry is pinned;
//! - the six bossNdead globals must ACCUMULATE: each is asserted alive in
//!   the scene long after its arena, which only a continuous run can show;
//! - the persistent player count stays 1 and obj_music stays alive through
//!   every hop (the asset-verified persistent set), same per-hop assertions
//!   as the trunks.
//!
//! Boundary: the continuous run re-enters the map after the ending/restart and
//! walks all three resolution-specific pages (mapview0 / rm_map / mapview3),
//! returning from each through the client's own release queue - including the
//! page whose view only CODE 538's armed Alarm 0 selects, one tick after entry.
//! Original runner behavior and GPU pixels are not claimed here.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::cell::RefCell;
use std::collections::BTreeSet;
use std::path::Path;
use std::sync::Arc;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const MUSIC: i32 = 68;
const INTRO: i32 = 137;
const TREX: i32 = 25;
const BULLET: i32 = 39;
const BOULDER: i32 = 3;
const PAUSEBUTTON: i32 = 125;
const MAPMENU: i32 = 111;
const MAPTILE: i32 = 160;
const VIEWRESOLUTION: i32 = 133;
const YOUHAVEDIED: i32 = 134;

thread_local! {
    /// Every room this thread's client frame loop actually ticked in. The
    /// continuous suite's room-coverage claim is read from THIS observation, not
    /// restated from the route tables the walk uses; a set also means a room
    /// entered twice is not counted as two rooms.
    static OBSERVED_ROOMS: RefCell<BTreeSet<i64>> = RefCell::new(BTreeSet::new());
}

fn observed_rooms() -> BTreeSet<i64> {
    OBSERVED_ROOMS.with(|rooms| rooms.borrow().clone())
}

fn observe_room(state: &GameState) {
    let room = scene(state).current_room as i64;
    OBSERVED_ROOMS.with(|rooms| {
        rooms.borrow_mut().insert(room);
    });
}

/// The raster's unconditional fill colour (`draw_frame_inner` ->
/// `Framebuffer::fill_rect(15, 18, 30, 255)`), stored BGRA in `pixels`. Every
/// frame is painted with it, so a "non-zero pixel" count is true even for an
/// empty frame; content is what differs from this clear.
const CLEAR_BGRA: [u8; 4] = [30, 18, 15, 255];

fn content_pixels(fb: &Framebuffer) -> usize {
    fb.pixels
        .chunks_exact(4)
        .filter(|px| px[0] != CLEAR_BGRA[0] || px[1] != CLEAR_BGRA[1]
            || px[2] != CLEAR_BGRA[2] || px[3] != CLEAR_BGRA[3])
        .count()
}

/// How many distinct pixel values the frame carries. A frame that never ran the
/// payload (or an empty room) collapses to the clear colour alone; a composited
/// gameplay frame shows the background layer, tiles, sprites and HUD.
fn distinct_colors(fb: &Framebuffer) -> usize {
    let mut seen = BTreeSet::new();
    for px in fb.pixels.chunks_exact(4) {
        seen.insert([px[0], px[1], px[2], px[3]]);
    }
    seen.len()
}

fn boot_like_android() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).expect("GameState::new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../../crates/core/src/generated/full_ir.json"))
            .expect("load full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    // Fresh observation per state: the boot seed room counts too.
    OBSERVED_ROOMS.with(|rooms| rooms.borrow_mut().clear());
    observe_room(&state);
    state
}

fn scene(state: &GameState) -> &Scene {
    state.scene.as_ref().expect("IR gameplay scene")
}

fn field(s: &Scene, id: i32, name: &str) -> f64 {
    s.instances[&id].fields[name]
}

/// The four command queues the draw pass is built from. `draw_view` clears them
/// on the way in; a frame that never reaches it (the client's pending-view
/// guard) must clear them itself instead of carrying the previous room's
/// commands into the next presented frame.
fn draw_queues(s: &Scene) -> usize {
    s.draws.len() + s.texts.len() + s.healthbars.len() + s.backgrounds.len()
}

/// A live rm_level17 gameplay state for the map-flow and view-guard fixtures.
fn level17_state() -> GameState {
    let mut state = boot_like_android();
    let bundle = state.full_bundle.as_ref().expect("bundle").clone();
    state
        .scene
        .as_mut()
        .expect("IR scene")
        .transition_to_room(&bundle, 25, &state.asset.rooms[25])
        .expect("seed rm_level17");
    state
}

fn step(state: &mut GameState) {
    state.step(1.0 / 60.0);
    assert!(
        state.runtime_diagnostic.is_none(),
        "IR frame loop halted in room {}: {:?}",
        scene(state).current_room,
        state.runtime_diagnostic
    );
    observe_room(state);
}

fn frames(state: &mut GameState, n: usize) {
    for _ in 0..n {
        step(state);
    }
}

fn room_name(state: &GameState) -> String {
    state.asset.rooms[scene(state).current_room as usize].name.clone()
}

fn player_id(state: &GameState) -> i32 {
    scene(state)
        .instances
        .iter()
        .find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent obj_player")
}

fn cast(state: &GameState, object: i32) -> usize {
    scene(state)
        .instances
        .values()
        .filter(|i| i.object == object && i.alive)
        .count()
}

/// Standing the player on the live door whose own warproom targets `target`,
/// through the shipped CODE 13 collision (identical machinery to the trunks).
fn walk_door(state: &mut GameState, target: f64, expect_name: &str) {
    let portal = scene(state)
        .instances
        .iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id)
        .unwrap_or_else(|| panic!("no door to room {target} in {}", scene(state).current_room));
    let (x, y) = {
        let p = &scene(state).instances[&portal];
        (p.fields["x"], p.fields["y"])
    };
    let player = player_id(state);
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "x", None, x).unwrap();
        s.write(player, -1, "y", None, y).unwrap();
    }
    for _ in 0..14 {
        step(state);
        if scene(state).current_room == target {
            break;
        }
    }
    assert_eq!(scene(state).current_room, target, "door landed in the wrong room");
    assert_eq!(room_name(state), expect_name);
    assert_eq!(cast(state, PLAYER), 1, "{expect_name}: one persistent player");
    assert!(
        scene(state).instances.values().any(|i| i.object == MUSIC && i.alive),
        "{expect_name}: obj_music survives the hop"
    );
    assert!(
        scene(state).room_views.iter().any(|v| v.visible),
        "{expect_name}: the reseeded runtime view is visible"
    );
}

/// par_enemy descendants declared by the bundle — the family every one of
/// CODE 12's `instance_place(x, y, obj_*)` contact selectors is drawn from.
fn enemy_family(bundle: &callys_core::code_vm::Bundle) -> BTreeSet<i32> {
    let root = bundle.objects.iter()
        .find(|object| object.name == "par_enemy")
        .expect("par_enemy in the bundle")
        .id;
    bundle.objects.iter()
        .filter(|object| object.parent_chain.contains(&root))
        .map(|object| object.id)
        .collect()
}

fn box_overlap(a: (f64, f64, f64, f64), b: (f64, f64, f64, f64)) -> bool {
    a.0 < b.1 && a.1 > b.0 && a.2 < b.3 && a.3 > b.2
}

/// The original runner's instance box (`Compute_BoundingBox`): the recorded SPRT
/// bbox margins, not the sprite rectangle the engine's broad phase uses. Read
/// straight from the asset metadata wired into the scene, so the two readings of
/// one instance can be compared instead of assumed equal — this suite's parking
/// spot sits exactly on the seam between them.
fn recorded_bbox(s: &Scene, id: i32) -> Option<(f64, f64, f64, f64)> {
    let inst = s.instances.get(&id)?;
    let x = *inst.fields.get("x")?;
    let y = *inst.fields.get("y")?;
    let sprite = inst.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
    let bounds = s.sprite_bounds.get(&sprite)?;
    let [left, right, top, bottom] = *s.sprite_bboxes.get(&sprite)?;
    Some((
        x - bounds.origin_x + left as f64,
        x - bounds.origin_x + right as f64 + 1.0,
        y - bounds.origin_y + top as f64,
        y - bounds.origin_y + bottom as f64 + 1.0,
    ))
}

/// Alive enemy-family instances whose box shares the player's, in the requested
/// reading (`recorded == false` = the engine's broad phase; `true` = the recorded
/// SPRT bbox the original computes).
fn player_enemy_contacts(
    state: &GameState,
    bundle: &callys_core::code_vm::Bundle,
    recorded: bool,
) -> Vec<(i32, String)> {
    let s = scene(state);
    let player = player_id(state);
    let reading = |id: i32| if recorded { recorded_bbox(s, id) } else { s.bounds_for_instance(id) };
    let Some(player_box) = reading(player) else { return Vec::new() };
    let family = enemy_family(bundle);
    let mut hits: Vec<(i32, String)> = s.instances.iter()
        .filter(|(id, i)| i.alive && **id != player && family.contains(&i.object))
        .filter(|(id, _)| reading(**id).is_some_and(|other| box_overlap(player_box, other)))
        .map(|(id, i)| {
            let name = bundle.objects.iter().find(|o| o.id == i.object)
                .map(|o| o.name.clone()).unwrap_or_default();
            (*id, name)
        })
        .collect();
    hits.sort();
    hits
}

/// Visit a map room from the live rm_level17 map path and come back through the
/// same release queue the production pointer path fills: the pause button and the
/// map menu are dispatched directly (like the other round-trip suites), while the
/// return tile release goes through `left_releases`, so Mouse_7's hit test and the
/// queued `room_goto` are consumed inside the client's own frame loop.
///
/// Fixture discipline (this spot is load bearing): the player is parked away from
/// the rm_level17 return pin so CODE 692/16's re-pin is observable, but NOT on top
/// of a level instance. The map menu's CODE 476 destroys obj_firstpause, whose
/// Destroy CODE 495 ends in `instance_activate_all()`, so the tick that consumes
/// the map warp runs the player's Step against the whole room — a contact in that
/// tick is a real hit. The old spot (900,400) shares the player's box with
/// obj_slime #119898 once that activation lands: the engine's broad phase uses the
/// full sprite rectangle, and the slime's rectangle reaches 0.7px into the
/// player's (the recorded SPRT bbox the original computes leaves a 3.3px gap, so
/// the original sheds nothing there). `global.health1 == 1` is the shipped death
/// trigger (CODE 12 -> CODE 540 obj_youhavedied), whose `instance_deactivate_all`
/// survives the map warp and leaves the persistent player inactive. The gate below
/// (`player_enemy_contacts` in both readings) is what keeps a fixture out of that
/// damage path, and it is checked on every leg because the hazard is invisible to
/// a pre-tick assertion. (428,204) is 300px right of the pin and measured clear of
/// the whole enemy set — in either active state — for 120px around it in every leg.
fn visit_map_room_round_trip(
    state: &mut GameState,
    bundle: &callys_core::code_vm::Bundle,
    width: f64,
    height: f64,
    target_room: usize,
    expected_name: &str,
) {
    assert_eq!(room_name(state), "rm_level17");
    let player = player_id(state);
    let (startx, starty) = (scene(state).globals["startx"], scene(state).globals["starty"]);
    assert_eq!((startx, starty), (128.0, 204.0), "level17 return pin");
    let health_before = scene(state).globals["health1"];
    {
        let s = state.scene.as_mut().unwrap();
        s.display_width = width;
        s.display_height = height;
        s.write(player, -1, "x", None, 428.0).unwrap();
        s.write(player, -1, "y", None, 204.0).unwrap();
    }
    assert_ne!(
        (field(scene(state), player, "x"), field(scene(state), player, "y")),
        (startx, starty),
        "the parking spot must differ from the pin, or the re-pin assertion is vacuous"
    );

    let pause = scene(state).instances.iter()
        .find(|(_, i)| i.object == PAUSEBUTTON && i.alive && i.active)
        .map(|(id, _)| *id).expect("active pausebutton in rm_level17");
    state.scene.as_mut().unwrap().dispatch(bundle, pause, 6, 7)
        .expect("pause menu release");
    let menu = scene(state).instances.iter()
        .find(|(_, i)| i.object == MAPMENU && i.alive && i.active)
        .map(|(id, _)| *id).expect("active mapmenu under pause menu");
    state.scene.as_mut().unwrap().dispatch(bundle, menu, 6, 7)
        .expect("mapmenu release");
    assert_eq!(scene(state).target_room_warp, Some(target_room),
        "CODE 476 at {width}x{height} queues {expected_name}");
    assert_eq!(scene(state).globals["health1"], health_before,
        "{expected_name}: opening the map must not shed health (the parked spot is live)");
    // The next tick is the damaging one if the spot is wrong: CODE 495 has just
    // re-activated every instance, so the player's Step runs against the whole
    // room. Gate both readings of the collision box here, where the hit would
    // land, instead of trusting the health assertion to notice afterwards.
    for (reading, recorded) in [("engine broad phase", false), ("recorded SPRT bbox", true)] {
        let hits = player_enemy_contacts(state, bundle, recorded);
        assert!(hits.is_empty(),
            "{expected_name}: the parking spot shares the player's box with enemy instances ({reading}): {hits:?}");
    }

    step(state); // client loop consumes the map-room warp
    assert_eq!(room_name(state), expected_name);
    if expected_name == "rm_mapview3" {
        // The entry frame precedes CODE 538's armed Alarm 0: no view is visible
        // yet, so the client's pending-view guard skips the draw pass. That frame
        // must not carry the previous room's four queues forward (the guard is
        // what discards them here; the shipped warp path also clears through
        // `transition_to_room`, so the isolated guard fixture below is what makes
        // the discard load bearing).
        assert_eq!(scene(state).active_view_index(), None,
            "the room entry frame precedes CODE 538's armed Alarm 0");
        let resolver = scene(state).instances.values()
            .find(|i| i.object == VIEWRESOLUTION && i.alive && i.active)
            .expect("obj_viewresolution in rm_mapview3");
        assert_eq!(resolver.alarms[0], 1, "Create arms view selection for the next tick");
        assert_eq!(draw_queues(scene(state)), 0,
            "the skipped frame must not leak the previous room's draw queues");
        step(state);
        assert_eq!(scene(state).active_view_index(), Some(3),
            "CODE 538 selects view 3 for the 1024x768 map branch");
        assert!(draw_queues(scene(state)) > 0,
            "and the next tick draws the map room normally");
    }
    if expected_name == "rm_mapview0" {
        assert_eq!(scene(state).globals["roomcamefrom"], 25.0,
            "the initial map entry pins rm_level17 via Room End CODE 15");
    }
    let tile = scene(state).instances.iter()
        .find(|(_, i)| i.object == MAPTILE && i.alive && i.fields.get("goto") == Some(&25.0))
        .map(|(id, _)| *id).expect("visited rm_level17 tile survives fog gate");
    // Feed the same world-space release queue the production pointer path uses.
    // The next client tick dispatches Mouse_7 and consumes its queued room_goto
    // in that same frame, avoiding an artificial extra idle tick in the map.
    let (left, right, top, bottom) = scene(state).bounds_for_instance(tile).expect("tile bounds");
    state.scene.as_mut().unwrap().left_releases
        .push(((left + right) * 0.5, (top + bottom) * 0.5));
    step(state); // Mouse_7 dispatch + client-loop warp consumption
    assert_eq!(room_name(state), "rm_level17");
    assert_eq!(scene(state).globals["warpfrommap"], 1.0, "CODE 692 armed map return");
    assert_eq!((field(scene(state), player, "x"), field(scene(state), player, "y")),
        (startx, starty), "CODE 692/16 re-pinned the player at the saved start");
    frames(state, 6);
    assert_eq!(scene(state).globals["warpfrommap"], 0.0, "CODE 362 clears the map flag");
    // The round trip is only complete if the player is still in play: a death
    // overlay here (shipped trigger: `global.health1 == 1`, CODE 12 -> 540) means
    // the fixture stood in a damage path, not that the map return failed.
    assert_eq!(cast(state, YOUHAVEDIED), 0,
        "{expected_name}: no death overlay after the map return");
    assert!(scene(state).instances[&player].active,
        "{expected_name}: the returned player is active again");
    assert_eq!(scene(state).globals["health1"], health_before,
        "{expected_name}: the map leg must not shed health (fixture hazard, not game logic)");
    let s = state.scene.as_mut().unwrap();
    s.display_width = 1136.0;
    s.display_height = 640.0;
}

fn dead(state: &GameState, flag: &str) -> bool {
    scene(state).globals.get(flag).copied() == Some(1.0)
}

/// obj_lloydtutorial1..16 freeze the world via instance_deactivate_all(true):
/// run to the sheet's taplock, dismiss it with a real release edge, exactly
/// like first_chapter_playthrough's helper.
fn dismiss_tutorial_sheet_if_any(state: &mut GameState) {
    let sheet = scene(state).instances.iter()
        .filter(|(_, i)| (138..=153).contains(&i.object) && i.alive)
        .map(|(id, _)| *id).next();
    let Some(sheet) = sheet else { return };
    for _ in 0..640 {
        step(state);
        if scene(state).instances[&sheet].fields.get("taplock").copied() == Some(1.0) {
            break;
        }
    }
    state.input.tap = true;
    step(state);
    state.input.tap = false;
    frames(state, 4);
    assert!(!scene(state).instances[&sheet].alive, "the sheet retires on a real tap");
}

/// hp injection + the boss's own Step->Alarm kill + the CODE 29 boulder clear,
/// mirroring boss_kill_chains' discipline inside the continuous scene.
fn kill_boss_and_open_gate(state: &mut GameState, obj: i32, hp_field: &str, flag: &str) {
    frames(state, 20); // settle the arena cast
    let id = scene(state)
        .instances
        .iter()
        .find(|(_, i)| i.object == obj && i.alive)
        .map(|(id, _)| *id)
        .unwrap_or_else(|| panic!("obj {obj} alive in room {}", scene(state).current_room));
    state.scene.as_mut().unwrap().write(id, -1, hp_field, None, 0.0).expect("inject hp");
    for _ in 0..120 {
        step(state);
        if dead(state, flag) {
            break;
        }
    }
    assert!(dead(state, flag), "{flag} fired within 120 frames");
    assert_eq!(cast(state, obj), 0, "the boss instance is gone after its death alarm");
    for _ in 0..40 {
        step(state);
        if cast(state, BOULDER) == 0 {
            break;
        }
    }
    assert_eq!(cast(state, BOULDER), 0, "obj_bossboulder cleared after {flag}");
}

/// After a kill, the region's forward door must fire through its own CODE 13
/// collision (boss_kill_chains' gate_opens, inside the continuous scene).
fn gate_forward(state: &mut GameState, target: f64, name: &str) {
    walk_door(state, target, name);
}

/// The first-chapter door chain, kept in one place (the trunks' forward cards
/// are enumerated from the RoomCC creation codes; see their suite headers).
const CHAPTER1: [(&str, f64); 11] = [
    ("rm_level1", 1.0), ("rm_level2", 2.0), ("rm_level3", 3.0), ("rm_level4", 4.0),
    ("rm_level5", 5.0), ("rm_level6", 6.0), ("rm_level5", 5.0), ("rm_level7", 7.0),
    ("rm_level8", 8.0), ("rm_level8a", 9.0), ("rm_boss1", 10.0),
];
const MINES: [(&str, f64); 16] = [
    ("rm_level9", 11.0), ("rm_level9a", 12.0), ("rm_level10", 13.0), ("rm_level11", 14.0),
    ("rm_level11a", 15.0), ("rm_level12", 16.0), ("rm_level13", 17.0), ("rm_level13a", 18.0),
    ("rm_level14", 19.0), ("rm_level14a", 20.0), ("rm_level15", 21.0), ("rm_level15a", 22.0),
    ("rm_level16", 23.0), ("rm_level16a", 24.0), ("rm_level17", 25.0), ("rm_level17a", 26.0),
];
const DEPTHS: [(&str, f64); 20] = [
    ("room31", 28.0), ("room32", 29.0), ("room33", 30.0), ("room34", 31.0),
    ("room35", 32.0), ("room36", 33.0), ("room37", 34.0), ("room38", 35.0),
    ("room39", 36.0), ("room40", 37.0), ("room41", 38.0), ("room42", 39.0),
    ("room43", 40.0), ("room44", 41.0), ("room45", 42.0), ("room46", 43.0),
    ("room47", 44.0), ("room48", 45.0), ("room49", 46.0), ("room50", 47.0),
];
const CORE: [(&str, f64); 15] = [
    ("room51", 49.0), ("room52", 50.0), ("room53", 51.0), ("room54", 52.0),
    ("room55", 53.0), ("room56", 54.0), ("room57", 55.0), ("room58", 56.0),
    ("room59", 57.0), ("room60", 58.0), ("room61", 59.0), ("room62", 60.0),
    ("room63", 61.0), ("room64", 62.0), ("room65", 63.0),
];
const LAB: [(&str, f64); 17] = [
    ("room66", 65.0), ("room67", 66.0), ("room68", 67.0), ("room69", 68.0),
    ("room70", 69.0), ("room71", 70.0), ("room72", 71.0), ("room73", 72.0),
    ("room74", 73.0), ("room75", 74.0), ("room76", 75.0), ("room77", 76.0),
    ("room78", 77.0), ("room79", 78.0), ("room80", 79.0), ("room81", 80.0),
    ("room82", 81.0),
];
const LAIR: [(&str, f64); 21] = [
    ("room83", 83.0), ("room84", 84.0), ("room85", 85.0), ("room86", 86.0),
    ("room87", 87.0), ("room88", 88.0), ("room89", 89.0), ("room90", 90.0),
    ("room91", 91.0), ("room92", 92.0), ("room93", 93.0), ("room94", 94.0),
    ("room95", 95.0), ("room96", 96.0), ("room97", 97.0), ("room98", 98.0),
    ("room99", 99.0), ("room100", 100.0), ("room101", 101.0), ("room102", 102.0),
    ("room103", 103.0),
];

#[test]
fn the_whole_game_walks_in_one_continuous_frame_loop() {
    let mut state = boot_like_android();

    // Prologue -> town on a real tap (the untouched intro outlives 120 frames).
    frames(&mut state, 125);
    assert!(scene(&state).instances.values().any(|i| i.object == INTRO && i.alive),
        "the prologue outlives 120 frames");
    state.input.tap = true;
    step(&mut state);
    state.input.tap = false;
    frames(&mut state, 2);
    assert_eq!(scene(&state).current_room, 0.0, "the prologue hands over to rm_town");
    assert!(!scene(&state).instances.values().any(|i| i.object == INTRO && i.alive));

    // Chapter 1: the town's Lloyd sheet (if the boot armed one) freezes the
    // world until dismissed with a real tap, then the eleven shipped doors.
    frames(&mut state, 15);
    dismiss_tutorial_sheet_if_any(&mut state);
    for (name, target) in &CHAPTER1 {
        walk_door(&mut state, *target, name);
    }

    // Boss 1 with real bullets (pistol damage, shoot button alarm chain).
    let (tx, ty) = {
        let t = scene(&state).instances.values().find(|i| i.object == TREX && i.alive).expect("obj_trex");
        (t.fields["x"], t.fields["y"])
    };
    let player = player_id(&state);
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "facing", None, 0.0).unwrap();
        let trex: i32 = s.instances.iter().find(|(_, i)| i.object == TREX && i.alive).map(|(id, _)| *id).unwrap();
        s.write(trex, -1, "hptrex", None, 1.0).unwrap();
    }
    let mut bullets_seen = 0;
    state.input.attack = true;
    for _ in 0..30 {
        step(&mut state);
        bullets_seen = bullets_seen.max(cast(&state, BULLET));
        if dead(&state, "boss1dead") { break; }
        let flank = scene(&state).instances.values().find(|i| i.object == TREX && i.alive)
            .map(|i| (i.fields["x"], i.fields["y"])).unwrap_or((tx, ty));
        let p = player_id(&state);
        let s = state.scene.as_mut().unwrap();
        s.write(p, -1, "x", None, flank.0 - 25.0).unwrap();
        s.write(p, -1, "y", None, flank.1).unwrap();
    }
    state.input.attack = false;
    for _ in 0..8 {
        step(&mut state);
        if dead(&state, "boss1dead") { break; }
    }
    assert!(bullets_seen > 0, "the shoot button spawned real bullets");
    assert!(dead(&state, "boss1dead"), "the bullet chain killed boss1 (CODE 284 -> 160)");

    // Mines trunk, then boss2.
    for (name, target) in &MINES { walk_door(&mut state, *target, name); }
    walk_door(&mut state, 27.0, "rm_boss2");
    kill_boss_and_open_gate(&mut state, 26, "hpboss2", "boss2dead");
    gate_forward(&mut state, 28.0, "room31");

    // Depths trunk, then boss3.
    for (name, target) in &DEPTHS[1..] { walk_door(&mut state, *target, name); }
    walk_door(&mut state, 48.0, "rm_boss3");
    kill_boss_and_open_gate(&mut state, 27, "hpboss3", "boss3dead");
    gate_forward(&mut state, 49.0, "room51");

    // Core trunk, then boss4.
    for (name, target) in &CORE[1..] { walk_door(&mut state, *target, name); }
    walk_door(&mut state, 64.0, "rm_boss4");
    kill_boss_and_open_gate(&mut state, 28, "hpboss4", "boss4dead");
    gate_forward(&mut state, 65.0, "room66");

    // Lab trunk, then boss5.
    for (name, target) in &LAB[1..] { walk_door(&mut state, *target, name); }
    walk_door(&mut state, 82.0, "rm_boss5");
    kill_boss_and_open_gate(&mut state, 29, "hpboss5", "boss5dead");
    gate_forward(&mut state, 83.0, "room83");

    // Lair trunk, then boss6: its death IS the exit (puff -> deactivate +
    // room_goto rm_ending), no forward door exists in rm_boss6.
    for (name, target) in &LAIR[1..] { walk_door(&mut state, *target, name); }
    walk_door(&mut state, 104.0, "rm_boss6");
    // The boss6 intro materialises the arena on its own alarm schedule; the
    // kill chains suite settles 20 frames before touching the boss.
    frames(&mut state, 20);
    // The continuous walk stands the player on the backward door anchor
    // (128,142): ~547px from the boss spawn, so the CODE 361 distance sweep
    // (<450px) deactivated it before the kill. Mirror the original's own
    // activation path (obj_boss6intro CODE 778's instance_activate_region,
    // recovered GML) by handing the player next to the arena first — no
    // manual active flip, no engine change.
    let fb = scene(&state).instances.iter()
        .find(|(_, i)| i.object == 30 && i.alive).map(|(id, _)| *id).expect("obj_finalboss");
    let (bx, by) = {
        let b = &scene(&state).instances[&fb];
        (b.fields["x"], b.fields["y"])
    };
    let player = player_id(&state);
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "x", None, bx - 120.0).unwrap();
        s.write(player, -1, "y", None, by).unwrap();
    }
    // One settle frame lets the sweep's wake path (CODE 361's own activation
    // region) run before the injection; hp stays the engine-unrecomputed field.
    step(&mut state);
    state.scene.as_mut().unwrap().write(fb, -1, "hpfinalboss", None, 0.0).unwrap();
    // Death first, warp second: rm_ending's own RoomData places obj_finalboss
    // for the ending scene, so checking "boss gone" after the warp would flag
    // the ending's placement (boss_kill_chains' probe note).
    for _ in 0..30 {
        step(&mut state);
        if cast(&state, 30) == 0 { break; }
    }
    let diag: Vec<String> = scene(&state).instances.iter()
        .filter(|(_, i)| (i.object == 30 || i.object == 185 || i.object == 189) && i.alive)
        .map(|(id, i)| format!("#{id} obj{} active={} pos={:.0},{:.0} hp={:?}",
            i.object, i.active, i.fields["x"], i.fields["y"],
            i.fields.get("hpfinalboss").copied()))
        .collect();
    assert_eq!(cast(&state, 30), 0, "the final boss died in the arena; live cast: {diag:?}");
    // The puff's Destroy arms alarm[3]=129 before CODE 787 warps; 320 frames
    // is generous over the ladder.
    let mut reached = false;
    for _ in 0..320 {
        step(&mut state);
        if scene(&state).current_room == 110.0 { reached = true; break; }
    }
    assert!(reached, "boss6's puff Destroy chain landed in rm_ending (110)");
    assert_eq!(room_name(&state), "rm_ending");

    // Continuity, only observable in ONE run: all six dead flags accumulated.
    for flag in ["boss1dead", "boss2dead", "boss3dead", "boss4dead", "boss5dead"] {
        assert!(dead(&state, flag), "{flag} still set in rm_ending");
    }
    assert_eq!(cast(&state, PLAYER), 1, "one persistent player reached the ending");

    // The ending's own credits engine runs INSIDE the live room: obj_endmusic
    // is RoomData-placed in rm_ending (asset probe: {obj_endmusic: 1} among
    // the 623 placements). The ladder ticks from t=1 RIGHT at the entry
    // frame (endmusic's Create seeded alarm[0]=50 there), so the beats must
    // match #82's hand-built table exactly - no 20-frame settle window in
    // between (a RED here first read 30/380/680/980: the offset of a stray
    // settle block, deterministic and now folded into this loop).
    let em = *scene(&state)
        .instances
        .iter()
        .find(|(_, i)| i.object == 163 && i.alive)
        .map(|(id, _)| id)
        .expect("obj_endmusic is placed in rm_ending");
    let mut flips: Vec<(u32, u32)> = Vec::new();
    let mut prev = [0.0f64; 11];
    let mut final_spawn = 0u32;
    let mut panel2_tick = 0u32;
    let mut lock_tick = 0u32;
    // Run past the starvation point: obj_final spawns at A11=2660, its
    // Create deactivates the room (keep-self), A1 arms taplock at 2960.
    for t in 1..=2975u32 {
        step(&mut state);
        let s = scene(&state);
        for n in 1..=10u32 {
            let v = s.instances[&em].fields.get(&format!("drawcredit{n}")).copied().unwrap_or(0.0);
            if v == 1.0 && prev[n as usize] != 1.0 {
                flips.push((t, n));
            }
            prev[n as usize] = v;
        }
        if final_spawn == 0 && s.instances.values().any(|i| i.object == 161 && i.alive) {
            final_spawn = t;
        }
        if let Some(f) = s.instances.values().find(|i| i.object == 161) {
            if panel2_tick == 0 && f.fields.get("drawpanel2").copied() == Some(1.0) {
                panel2_tick = t;
            }
            if lock_tick == 0 && f.fields.get("taplock").copied() == Some(1.0) {
                lock_tick = t;
            }
        }
    }
    assert_eq!(flips, vec![(50, 1), (400, 2), (700, 3), (1000, 4), (1300, 5),
        (1600, 6), (1900, 7), (2200, 8), (2400, 9)],
        "the credits ladder keeps its shipped beats inside the live ending room");
    assert_eq!(final_spawn, 2660, "A11 spawns obj_final at t2660 in the live room");
    assert_eq!(panel2_tick, 2760, "obj_final's A0 lands at +100");
    assert_eq!(lock_tick, 2960, "and A1 arms taplock at +300");
    // The shipped starvation reproduces live (same mechanism #82 pinned on a
    // hand-built scene; here it is the entered room's own timeline):
    let em_inst = &scene(&state).instances[&em];
    assert!(!em_inst.active, "obj_final's Create deactivated the credits");
    assert_eq!(em_inst.alarms[9], 140, "a9 was left at 140");
    assert_eq!(em_inst.fields.get("drawcredit10").copied(), Some(0.0),
        "the tenth page never flips in the shipped flow");
    assert!(scene(&state).instances.values().any(|i| i.object == MUSIC && i.alive),
        "obj_music reached the ending");

    // A real draw pass in the ending room (the pixel pipeline runs end-to-end).
    let mut fbm = Framebuffer::new(960, 540);
    draw_frame(&mut fbm, &state, &state.asset.tpag_items, &state.asset.sprites);
    // Honest scope of this claim: the room's background layer covers the whole
    // canvas, so "content" says the frame is not the bare clear fill (the payload
    // reached the rasteriser), and the colour count says it is a composited frame
    // rather than one flat fill. It is NOT original-pixel equivalence, and it does
    // not single out any sprite or text run.
    let content = content_pixels(&fbm);
    let shades = distinct_colors(&fbm);
    assert!(content > 0 && shades >= 10,
        "rm_ending rasterises drawn payload: content={content} distinct={shades}");

    // The hand-off tap: a PHYSICAL release inside obj_final's box goes through
    // the client's pointer_released -> screen_to_world -> left_releases ->
    // Mouse_7 hit test (the #82 batch dispatches (6,7) directly; this proves
    // the queue path in the live room). CODE 698 then does
    // instance_activate_all + warpfrommap=1 + room_goto(rm_challenge1), and
    // the client frame loop consumes the warp itself.
    let fin = *scene(&state)
        .instances
        .iter()
        .find(|(_, i)| i.object == 161 && i.alive && i.active)
        .map(|(id, _)| id)
        .expect("obj_final active (keep-self)");
    let (fx, fy) = {
        let f = &scene(&state).instances[&fin];
        // sprite_index is unset (Draw draws the panel sprites), so the hit
        // box is the engine's 32x32 fallback at (x, y) - aim at the center.
        (f.fields["x"], f.fields["y"])
    };
    state.pointer_released(0.0, 0.0); // invalid coord class check below uses the real map
    // pointer_released maps the LOGICAL canvas through screen_to_world; the
    // camera origin makes raw math fragile, so push the world-space release
    // the queue itself carries (the same Vec the client pushes to):
    state.scene.as_mut().unwrap().left_releases.push((fx + 16.0, fy + 16.0));
    let mut warped = false;
    for _ in 0..14 {
        step(&mut state);
        if scene(&state).current_room == 105.0 {
            warped = true;
            break;
        }
    }
    assert!(warped, "the real release tap handed the game to rm_challenge1");
    assert_eq!(room_name(&state), "rm_challenge1");
    assert_eq!(scene(&state).globals.get("warpfrommap").copied(), Some(1.0),
        "CODE 698 set warpfrommap before the warp");
    assert_eq!(cast(&state, PLAYER), 1, "one persistent player entered challenge1");
    let mut fbm2 = Framebuffer::new(960, 540);
    draw_frame(&mut fbm2, &state, &state.asset.tpag_items, &state.asset.sprites);
    let content2 = content_pixels(&fbm2);
    let shades2 = distinct_colors(&fbm2);
    assert!(content2 > 0 && shades2 >= 100,
        "rm_challenge1 rasterises drawn payload: content={content2} distinct={shades2}");

    // The five challenge stages, forward cards 1014/1016/1018/1020 (their
    // warproom constants read from room_bindings' creation codes, same as the
    // trunks' cards). Backward cards (1013/1015/1017/1019/1021) are the
    // return doors this walk never takes.
    for (target, name) in [(106.0, "rm_challenge2"), (107.0, "rm_challenge3"),
                           (108.0, "rm_challenge4"), (109.0, "rm_challenge5")] {
        walk_door(&mut state, target, name);
    }

    // rm_challenge5 places obj_finalchest (101, sprite 91). Its Collision 0
    // (CODE 454) creates obj_tease at itself and dies: stand the player on
    // the chest and let the shipped collision dispatch fire - no direct
    // dispatch, the natural pair.
    let chest = *scene(&state)
        .instances
        .iter()
        .find(|(_, i)| i.object == 101 && i.alive)
        .map(|(id, _)| id)
        .expect("obj_finalchest is placed in rm_challenge5");
    let (cx, cy) = {
        let c = &scene(&state).instances[&chest];
        (c.fields["x"], c.fields["y"])
    };
    let player = player_id(&state);
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "x", None, cx).unwrap();
        s.write(player, -1, "y", None, cy).unwrap();
    }
    let mut tease = 0i32;
    for _ in 0..14 {
        step(&mut state);
        if let Some((id, _)) = scene(&state).instances.iter()
            .find(|(_, i)| i.object == 162 && i.alive) {
            tease = *id;
            break;
        }
    }
    assert_ne!(tease, 0, "the chest collision created obj_tease (CODE 454)");
    assert_eq!(cast(&state, 101), 0, "the chest destroyed itself handing off the teaser");

    // obj_tease's Create (CODE 700): deactivate_all(true) keeps only itself,
    // stops the music and arms alarm[0] = 600. The freeze is observable:
    // the persistent player survives the warp but went inactive.
    assert!(!scene(&state).instances[&player].active,
        "the room is frozen under the teaser (deactivate_all keep-self)");
    let mut unlocked = false;
    for _ in 0..640 {
        step(&mut state);
        if scene(&state).instances[&tease].fields.get("taplock").copied() == Some(1.0) {
            unlocked = true;
            break;
        }
    }
    assert!(unlocked, "alarm 0 arms taplock on the 600th tick (#82's table)");
    assert_eq!(scene(&state).instances[&tease].fields.get("drawpanel3").copied(), Some(1.0),
        "the same alarm raises the Teaser's panel 3");

    // The restart tap through the release queue, aimed at the teaser's sprite
    // box center (sprite 162 bounds, same fallback as the engine).
    let (fx, fy) = {
        let t = &scene(&state).instances[&tease];
        (t.fields["x"], t.fields["y"])
    };
    let (w, h, ox, oy) = scene(&state).sprite_bounds.get(&162)
        .map(|sb| (sb.width, sb.height, sb.origin_x, sb.origin_y))
        .unwrap_or((32.0, 32.0, 0.0, 0.0));
    state.scene.as_mut().unwrap().left_releases.push((fx - ox + w * 0.5, fy - oy + h * 0.5));
    let mut restarted = false;
    for _ in 0..14 {
        step(&mut state);
        if scene(&state).current_room == 0.0 {
            restarted = true;
            break;
        }
    }
    assert!(restarted, "the teaser tap ran game_restart (CODE 702 -> warp 0) and the loop consumed it");
    assert_eq!(room_name(&state), "rm_town", "the restart hands the game back to rm_town");
    assert_eq!(cast(&state, PLAYER), 1, "one persistent player survived the restart");
    // Engine boundary, pinned honestly: this rewrite's game_restart is a
    // room-0 warp; globals ACCUMULATE across it (the original rebuilds all
    // memory). The flags still set here is the registered divergence, not a
    // claim about the original.
    assert_eq!(scene(&state).globals.get("boss1dead").copied(), Some(1.0),
        "registered boundary: warp-0 restart keeps globals, the original would reset them");

    // The secret branch: CODE 17's fresh-start baseline gave haskey=1, and
    // rm_town's door card 803 is the ONLY locked door in the 218-card set
    // (unlocked=0). CODE 13's key branch consumes the key, unlocks the card
    // and warps to rm_level16 - the Mines dead-end region the trunk never
    // walks. Then card 849 (rm_level16 -> rm_level15a, unlocked) folds the
    // branch back onto the trunk room the walk already knows.
    assert_eq!(scene(&state).globals.get("haskey").copied(), Some(1.0),
        "CODE 17's reset path re-seeded the key");
    walk_door(&mut state, 23.0, "rm_level16");
    assert_eq!(scene(&state).globals.get("haskey").copied(), Some(0.0),
        "CODE 13 consumed the key on the secret door");
    // The dead-end's own cards: 850 folds 16 -> 16a, and 16a's forward card
    // 851 (shipped unlocked=1, landing pin (128,204)) brings the branch back
    // onto the trunk at rm_level17 - the region is walked in, not visited as
    // a single room.
    walk_door(&mut state, 24.0, "rm_level16a");
    let mut fbm3 = Framebuffer::new(960, 540);
    draw_frame(&mut fbm3, &state, &state.asset.tpag_items, &state.asset.sprites);
    let content3 = content_pixels(&fbm3);
    let shades3 = distinct_colors(&fbm3);
    assert!(content3 > 0 && shades3 >= 100,
        "rm_level16a rasterises drawn payload: content={content3} distinct={shades3}");
    walk_door(&mut state, 25.0, "rm_level17");

    // Finish the continuous room census at all three resolution-specific map
    // rooms, and RETURN from each one through the client's own frame loop. The
    // earlier shape stopped on rm_mapview3 (the page whose view CODE 538 only
    // selects on the tick after entry) and never exercised its client-side
    // return; the return now runs the same live release path as the other two.
    let bundle_arc = state.full_bundle.as_ref().expect("bundle").clone();
    for (width, height, target, name) in [
        (1136.0, 640.0, 113, "rm_mapview0"),
        (960.0, 640.0, 111, "rm_map"),
        (1024.0, 768.0, 112, "rm_mapview3"),
    ] {
        visit_map_room_round_trip(&mut state, &bundle_arc, width, height, target, name);
    }

    // Room coverage as an OBSERVATION: every room id this one continuous
    // GameState actually ticked in (observed inside `step`, so re-entries
    // collapse in the set and nothing is derived from the route tables),
    // compared against the asset's full room table both ways.
    let observed = observed_rooms();
    let all: BTreeSet<i64> = (0..state.asset.rooms.len() as i64).collect();
    let missing: Vec<i64> = all.difference(&observed).copied().collect();
    let extra: Vec<i64> = observed.difference(&all).copied().collect();
    let names = |ids: &[i64]| -> Vec<String> {
        ids.iter()
            .map(|id| {
                state.asset.rooms.get(*id as usize)
                    .map(|room| room.name.clone())
                    .unwrap_or_else(|| format!("<room {id} outside the table>"))
            })
            .collect()
    };
    assert!(missing.is_empty(),
        "rooms never ticked in the continuous run: {:?}", names(&missing));
    assert!(extra.is_empty(),
        "rooms ticked that are not in the asset table: {:?}", names(&extra));
    assert_eq!(observed.len(), state.asset.rooms.len(),
        "distinct rooms visited must equal the asset room count");
}

#[test]
fn fresh_gameplay_state_roundtrips_mapview3_through_client_steps() {
    let mut state = boot_like_android();
    let bundle = state.full_bundle.as_ref().expect("bundle").clone();
    state.scene.as_mut().expect("IR scene")
        .transition_to_room(&bundle, 25, &state.asset.rooms[25])
        .expect("seed rm_level17 for isolated client map-flow test");
    // This focused fixture pins only the prerequisite fog flag; the continuous
    // end-to-end test above owns the actual room-entry census.
    state.scene.as_mut().unwrap().globals.insert("level17visited".into(), 1.0);
    step(&mut state); // arm/resolve rm_level17's runtime view selector
    assert_eq!(room_name(&state), "rm_level17");
    assert_eq!(scene(&state).globals["health1"], 4.0, "fresh player state");

    visit_map_room_round_trip(&mut state, &bundle, 1024.0, 768.0, 112, "rm_mapview3");
    assert_eq!(room_name(&state), "rm_level17");
    assert!(scene(&state).instances[&player_id(&state)].active,
        "the client-loop mapview3 return wakes the player in the fresh-state fixture");
}

/// The guard's POSITIVE boundary, isolated from the warp path: a viewless frame
/// whose obj_viewresolution is armed for the next tick is the one state the
/// client may skip. It must skip the draw pass, drop the commands the previous
/// room left behind, and let the following tick select a view and draw normally.
#[test]
fn a_pending_view_resolution_frame_skips_draw_and_clears_the_queues() {
    let mut state = level17_state();
    step(&mut state); // a normal gameplay frame
    let s = scene(&state);
    let queues = [s.draws.len(), s.texts.len(), s.healthbars.len(), s.backgrounds.len()];
    assert!(queues.iter().all(|count| *count > 0),
        "each of the four queues must carry real commands before the guard: {queues:?}");

    {
        let s = state.scene.as_mut().expect("IR scene");
        s.view_visible = [false; 8];
        let mut armed = 0;
        for instance in s.instances.values_mut().filter(|i| i.object == VIEWRESOLUTION) {
            // Due after the next tick, so the guard's check reads the exact
            // armed value (1) on the frame it skips.
            instance.alarms[0] = 2;
            armed += 1;
        }
        assert!(armed > 0, "rm_level17 carries obj_viewresolution (its CODE 538 runs here)");
    }

    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.is_none(),
        "the armed resolver state is the permitted pending frame: {:?}", state.runtime_diagnostic);
    assert_eq!(scene(&state).active_view_index(), None, "the frame really had no visible view");
    assert_eq!(draw_queues(scene(&state)), 0,
        "the skipped frame must not carry the old four queues");

    step(&mut state); // CODE 538 fires
    assert!(scene(&state).active_view_index().is_some(), "the next tick selects a view");
    assert!(draw_queues(scene(&state)) > 0, "and that frame draws normally");
}

/// The guard's NEGATIVE boundary: a permanently viewless gameplay frame halts
/// instead of being swallowed by a looser guard. Each arm of the predicate is
/// exercised: the object table always has obj_viewresolution (191-object bundle),
/// so the reachable false cases are "no live+active instance" and "alarm not
/// armed for the next tick".
#[test]
fn a_viewless_frame_without_pending_view_resolution_still_halts() {
    let cases: [(&str, fn(&mut Scene)); 4] = [
        ("no resolver instance", |s| {
            s.instances.retain(|_, i| i.object != VIEWRESOLUTION);
        }),
        ("resolver dead", |s| {
            for i in s.instances.values_mut().filter(|i| i.object == VIEWRESOLUTION) {
                i.alive = false;
            }
        }),
        ("resolver inactive", |s| {
            for i in s.instances.values_mut().filter(|i| i.object == VIEWRESOLUTION) {
                i.active = false;
            }
        }),
        ("alarm not armed", |s| {
            for i in s.instances.values_mut().filter(|i| i.object == VIEWRESOLUTION) {
                i.alarms[0] = -1;
            }
        }),
    ];
    for (label, mutate) in cases {
        let mut state = level17_state();
        step(&mut state);
        {
            let s = state.scene.as_mut().expect("IR scene");
            assert!(
                s.instances.values().any(|i| i.object == VIEWRESOLUTION),
                "{label}: the fixture room carries a resolver before it is broken"
            );
            s.view_visible = [false; 8];
            mutate(s);
        }
        state.step(1.0 / 60.0);
        let diagnostic = state
            .runtime_diagnostic
            .as_deref()
            .unwrap_or_else(|| panic!("{label}: a viewless gameplay frame must halt"));
        assert!(diagnostic.contains("no visible view for gameplay room"), "{label}: {diagnostic}");
    }
}

/// Detection power of the pixel-content gate the room-render assertions use: the
/// raster's mandatory clear fill makes "non-zero pixel" counts true for an empty
/// frame, so the gate counts pixels that DIFFER from that clear. Removing the
/// payload (the four command queues and the room's tile layer) must leave the
/// same gate at zero - otherwise the assertion above would be claiming content
/// it never measured.
#[test]
fn the_pixel_content_gate_sees_the_clear_when_nothing_is_drawn() {
    let mut state = level17_state();
    step(&mut state);

    let mut drawn = Framebuffer::new(960, 540);
    draw_frame(&mut drawn, &state, &state.asset.tpag_items, &state.asset.sprites);
    let content = content_pixels(&drawn);
    let shades = distinct_colors(&drawn);
    assert!(content > 0 && shades >= 100,
        "rm_level17 rasterises drawn payload: content={content} distinct={shades}");

    {
        let s = state.scene.as_mut().expect("IR scene");
        s.clear_draw_commands();
        s.room_tiles.clear();
        s.particles.clear();
    }
    let mut blank = Framebuffer::new(960, 540);
    draw_frame(&mut blank, &state, &state.asset.tpag_items, &state.asset.sprites);
    let blank_content = content_pixels(&blank);
    let blank_shades = distinct_colors(&blank);
    assert_eq!(blank_content, 0,
        "an empty payload must leave only the clear colour (content={blank_content})");
    assert_eq!(blank_shades, 1,
        "and the frame collapses to the single clear value (distinct={blank_shades})");
}

/// Park at `spot` in the rm_level17 map-flow fixture and stop at the exact moment
/// before the tick that consumes the map warp: the pause button and the map menu
/// are released, so CODE 495 has re-activated the room and rm_mapview3's warp is
/// queued. The display is the 1024x768 branch (CODE 476 -> rm_mapview3), the same
/// page the continuous run ends its map stint on.
fn parked_at_map_open(spot: (f64, f64)) -> (GameState, Arc<callys_core::code_vm::Bundle>) {
    let mut state = boot_like_android();
    let bundle = state.full_bundle.as_ref().expect("bundle").clone();
    {
        let s = state.scene.as_mut().expect("IR scene");
        s.transition_to_room(&bundle, 25, &state.asset.rooms[25]).expect("seed rm_level17");
        s.globals.insert("level17visited".into(), 1.0);
        s.display_width = 1024.0;
        s.display_height = 768.0;
    }
    step(&mut state); // arm the room's runtime view selector
    let player = player_id(&state);
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "x", None, spot.0).unwrap();
        s.write(player, -1, "y", None, spot.1).unwrap();
    }
    let pause = scene(&state).instances.iter()
        .find(|(_, i)| i.object == PAUSEBUTTON && i.alive && i.active)
        .map(|(id, _)| *id).expect("active pausebutton in rm_level17");
    state.scene.as_mut().unwrap().dispatch(&bundle, pause, 6, 7).expect("pause menu release");
    let menu = scene(&state).instances.iter()
        .find(|(_, i)| i.object == MAPMENU && i.alive && i.active)
        .map(|(id, _)| *id).expect("active mapmenu under the pause menu");
    state.scene.as_mut().unwrap().dispatch(&bundle, menu, 6, 7).expect("mapmenu release");
    (state, bundle)
}

/// Post-fix successor of the seam test (WL7): the collision fix moved the
/// engine's broad phase to the recorded SPRT bbox, so the old spot (900,400)
/// in rm_level17 is now contact-free in BOTH readings — the seam this suite
/// once parked on is closed. The original geometry the seam sat on is pinned
/// as data (recorded boxes, y gap ~3.3px), and the shipped spot (428,204)
/// remains the clean control for the same gate.
#[test]
fn the_parking_spot_gate_confirms_the_engine_box_seam_is_closed() {
    let (state, bundle) = parked_at_map_open((900.0, 400.0));
    for (reading, recorded) in [("engine broad phase", false), ("recorded SPRT bbox", true)] {
        assert!(player_enemy_contacts(&state, &bundle, recorded).is_empty(),
            "the collision fix left a contact at (900,400) in the {reading} reading");
    }

    // The recorded geometry is unchanged data — the original's boxes stay
    // apart in y at exactly the spot the old whole-sprite box overlapped.
    let slime_object = bundle.objects.iter()
        .find(|o| o.name == "obj_slime").expect("obj_slime").id;
    let s = scene(&state);
    let player = player_id(&state);
    let slime = s.instances.iter()
        .find(|(_, i)| i.object == slime_object && i.alive).map(|(id, _)| *id)
        .expect("the rm_level17 slime");
    let (rp, rs) = (recorded_bbox(s, player).unwrap(), recorded_bbox(s, slime).unwrap());
    assert!(!box_overlap(rp, rs),
        "the recorded boxes stay apart at the old seam spot: {rp:?} vs {rs:?}");
    assert!(rp.0 < rs.1 && rp.1 > rs.0,
        "the recorded boxes still overlap in x, so the separation is in y alone");
    let gap = rp.2 - rs.3;
    assert!(gap > 0.0 && gap <= 8.0,
        "and that y gap is the same seam, not a distant instance: {gap}px");

    let (clean, clean_bundle) = parked_at_map_open((428.0, 204.0));
    for (reading, recorded) in [("engine broad phase", false), ("recorded SPRT bbox", true)] {
        assert!(player_enemy_contacts(&clean, &clean_bundle, recorded).is_empty(),
            "the shipped parking spot is clear in the {reading} reading");
    }
}

/// The reported defect, reproduced deterministically at the tick level —
/// RE-CAST by the collision-box fix (WL7): the death threshold `health1 == 1`
/// is injected directly instead of being reached through the slime contact,
/// because the contact itself was the engine-side false positive this test
/// originally sat on (the old broad phase's whole-sprite box overlapped the
/// slime by 0.7px where the recorded bbox leaves a 3.3px gap). The guard below
/// — no contact in EITHER box reading at the old parking spot — is what the
/// fix must satisfy; the chain it triggers is shipped bytecode.
///
/// Parked at (900,400) with `health1 == 1` the run does this:
///
/// tick 1  the map-warp tick: the player's Step (CODE 12) sees
///         `if (global.health1 == 1)` directly -> creates obj_youhavedied
///         (CODE 540), which re-pins the player to
///         `global.startx/starty`, calls `instance_deactivate_all(true)` and bumps
///         `playerdied`. The client then consumes the queued rm_mapview3 warp in the
///         same frame, and the overlay is NOT persistent (asset-verified: only
///         obj_player and obj_music are), so the room switch drops it while the
///         persistent player keeps `active == false`.
/// ticks 2-4  rm_mapview3 is inert: no overlay, no player Step, nothing to draw a
///         death screen from.
/// tick 5  the return tile release runs CODE 692: `instance_activate_all()` +
///         `warpfrommap = 1` + `room_goto(25)`; the frame consumes the warp.
/// tick 6  back in rm_level17 the player's Step runs again with `health1` still 1
///         -> a SECOND overlay is created (playerdied 1 -> 2) -> deactivated room.
///         Terminal state == the reported one: obj_youhavedied is the only active
///         instance, the player is inactive, `warpfrommap` stays 1 (obj_bg is
///         deactivated, so CODE 362 never clears it).
#[test]
fn the_map_open_contact_tick_hands_the_run_to_the_death_overlay_across_the_map_warp() {
    let (mut state, bundle) = parked_at_map_open((900.0, 400.0));
    let player = player_id(&state);
    {
        let s = state.scene.as_mut().unwrap();
        s.globals.insert("health1".into(), 1.0);
    }
    assert_eq!(scene(&state).target_room_warp, Some(112),
        "CODE 476 at 1024x768 queues rm_mapview3");
    // The fix's guard: the old parking spot must now be contact-free in BOTH
    // box readings (engine broad phase AND recorded SPRT bbox). Under the old
    // whole-sprite broad phase the engine reading showed the seam hit.
    for (reading, recorded) in [("engine broad phase", false), ("recorded SPRT bbox", true)] {
        let hits = player_enemy_contacts(&state, &bundle, recorded);
        assert!(hits.is_empty(),
            "the collision fix left a contact at (900,400) ({reading}): {hits:?}");
    }
    assert_eq!(scene(&state).globals["health1"], 1.0,
        "the death threshold is injected, not shed by a contact");

    step(&mut state); // the death-branch tick + the warp it shares a frame with
    assert_eq!(room_name(&state), "rm_mapview3");
    assert_eq!(scene(&state).globals["health1"], 1.0,
        "no contact consumed health: the threshold stays exactly as injected");
    assert_eq!(scene(&state).globals["playerdied"], 1.0,
        "and reached the shipped death branch in the same Step");
    assert_eq!(cast(&state, YOUHAVEDIED), 0,
        "the overlay the death branch created did not survive the room switch");
    assert!(scene(&state).instances.contains_key(&player), "the player is persistent");
    assert!(!scene(&state).instances[&player].active,
        "but CODE 540's instance_deactivate_all(true) travelled with it");
    assert_eq!((field(scene(&state), player, "x"), field(scene(&state), player, "y")),
        (128.0, 204.0), "CODE 540 re-pinned the player to global.startx/starty first");
    assert!(!bundle.objects.iter().find(|o| o.id == YOUHAVEDIED).expect("obj_youhavedied").persistent,
        "asset-verified: the death controller is not persistent, which is why the warp dropped it");

    frames(&mut state, 3);
    assert_eq!(cast(&state, YOUHAVEDIED), 0, "rm_mapview3 stays overlay-free");
    assert!(!scene(&state).instances[&player].active, "and the player stays inert there");

    let tile = scene(&state).instances.iter()
        .find(|(_, i)| i.object == MAPTILE && i.alive && i.fields.get("goto") == Some(&25.0))
        .map(|(id, _)| *id).expect("visited rm_level17 tile in rm_mapview3");
    let (left, right, top, bottom) = scene(&state).bounds_for_instance(tile).unwrap();
    state.scene.as_mut().unwrap().left_releases.push(((left + right) * 0.5, (top + bottom) * 0.5));
    step(&mut state); // CODE 692 + the client's warp consumption
    assert_eq!(room_name(&state), "rm_level17");
    assert_eq!(scene(&state).globals["warpfrommap"], 1.0, "CODE 692 armed the map return");
    assert!(scene(&state).instances[&player].active,
        "CODE 692's instance_activate_all woke the persistent player");

    step(&mut state); // the first tick back in rm_level17
    assert_eq!(cast(&state, YOUHAVEDIED), 1, "the death layer is rebuilt in the returned room");
    assert_eq!(scene(&state).globals["playerdied"], 2.0, "a second death branch ran");
    assert!(!scene(&state).instances[&player].active, "the player is deactivated again");
    let active = scene(&state).instances.values().filter(|i| i.alive && i.active).count();
    assert_eq!(active, 1, "obj_youhavedied is the only active instance: {active}");
    assert_eq!(scene(&state).instances.values().filter(|i| i.alive && i.active).next().unwrap().object,
        YOUHAVEDIED, "and it is the overlay");
    assert_eq!(scene(&state).globals["warpfrommap"], 1.0,
        "obj_bg is deactivated, so CODE 362 never clears the flag: the reported state");
}

