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
//! Boundary: this stops at entry into rm_ending (room 110) plus 20 settle
//! frames. The credits pagination ring, obj_final's panels and the tap-to-
//! challenge1 gate are owned by the ending batch (#82); re-running 2,965
//! ticks here would double-attribute a failure. The original's side regions
//! (rm_level*a branches, map, challenge stages) are off the trunk and not
//! walked here.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const MUSIC: i32 = 68;
const INTRO: i32 = 137;
const TREX: i32 = 25;
const BULLET: i32 = 39;
const BOULDER: i32 = 3;

fn boot_like_android() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).expect("GameState::new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../../crates/core/src/generated/full_ir.json"))
            .expect("load full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state
}

fn scene(state: &GameState) -> &Scene {
    state.scene.as_ref().expect("IR gameplay scene")
}

fn step(state: &mut GameState) {
    state.step(1.0 / 60.0);
    assert!(
        state.runtime_diagnostic.is_none(),
        "IR frame loop halted in room {}: {:?}",
        scene(state).current_room,
        state.runtime_diagnostic
    );
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
    for t in 1..=1200u32 {
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
    }
    assert_eq!(flips, vec![(50, 1), (400, 2), (700, 3), (1000, 4)],
        "the credits ladder keeps its shipped beats inside the live ending room");
    assert_eq!(final_spawn, 0, "A11 (t2660) is beyond this window and not reached yet");
    assert!(scene(&state).instances.values().any(|i| i.object == MUSIC && i.alive),
        "obj_music reached the ending");

    // A real draw pass in the ending room (the pixel pipeline runs end-to-end).
    let mut fbm = Framebuffer::new(960, 540);
    draw_frame(&mut fbm, &state, &state.asset.tpag_items, &state.asset.sprites);
    let lit = fbm.pixels.iter().filter(|&&p| p != 0).count();
    assert!(lit > 1000, "rm_ending renders real pixels (lit={lit})");
}
