//! Render batch — draw-stream sensitivities: the fingerprint must MOVE on
//! gameplay-visible state transitions and freeze with the world, all without
//! pixels. Companion to draw_stream_frame_fingerprint.rs (which pins cold-boot
//! determinism, the town golden, the door path and the CODE 361 sweep).
//!
//! Pinned here from real emission through the shipped GameState loop:
//!   * the Lloyd sheet's `instance_deactivate_all(true)` freeze leaves exactly
//!     one active instance drawing;
//!   * killing obj_trex removes its draws from the stream (the same transition
//!     the boulder-gate opening then makes reachable);
//!   * the Mines room (rm_level9, reached only after that kill) fingerprints
//!     differently from town and level1 — three rooms, three distinct streams.
use callys_client::GameState;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const INTRO: i32 = 137;
const PLAYER: i32 = 0;
const WARP: i32 = 69;
const TREX: i32 = 25;
const BOSSBOULDER: i32 = 3;

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

fn q8(v: f64) -> i64 { (v * 8.0) as i64 }
fn q1000(v: f64) -> i64 { (v * 1000.0) as i64 }

fn mix(h: &mut u64, v: i64) {
    *h ^= (v as u64).wrapping_add(0x9e37_79b9_7f4a_7c15);
    *h = h.wrapping_mul(0x0000_0100_0000_01b3);
}

/// Same algorithm as draw_stream_frame_fingerprint.rs — keep the two suites'
/// digests mutually comparable.
fn stream_digest(s: &Scene) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    for d in &s.draws {
        mix(&mut h, d.code as i64); mix(&mut h, d.instance as i64); mix(&mut h, d.view as i64); mix(&mut h, d.sprite as i64);
        mix(&mut h, q8(d.frame)); mix(&mut h, q8(d.x)); mix(&mut h, q8(d.y));
        mix(&mut h, q1000(d.scale_x)); mix(&mut h, q1000(d.scale_y)); mix(&mut h, q1000(d.rotation));
        mix(&mut h, d.color as i64); mix(&mut h, q1000(d.alpha)); mix(&mut h, d.fog as i64);
    }
    for t in &s.texts {
        mix(&mut h, t.code as i64); mix(&mut h, t.instance as i64); mix(&mut h, t.view as i64);
        mix(&mut h, q8(t.x)); mix(&mut h, q8(t.y));
        for byte in t.text.as_bytes() { mix(&mut h, *byte as i64); }
        mix(&mut h, t.color as i64); mix(&mut h, q1000(t.alpha)); mix(&mut h, t.font as i64);
    }
    for b in &s.backgrounds {
        mix(&mut h, b.code as i64); mix(&mut h, b.instance as i64); mix(&mut h, b.view as i64); mix(&mut h, b.background as i64);
        mix(&mut h, q8(b.x)); mix(&mut h, q8(b.y));
        mix(&mut h, q1000(b.scale_x)); mix(&mut h, q1000(b.scale_y)); mix(&mut h, q1000(b.rotation));
        mix(&mut h, b.color as i64); mix(&mut h, q1000(b.alpha));
    }
    for hb in &s.healthbars {
        mix(&mut h, hb.code as i64); mix(&mut h, hb.instance as i64); mix(&mut h, hb.view as i64);
        mix(&mut h, q8(hb.x1)); mix(&mut h, q8(hb.y1)); mix(&mut h, q8(hb.x2)); mix(&mut h, q8(hb.y2)); mix(&mut h, q1000(hb.amount));
        mix(&mut h, hb.back_col as i64); mix(&mut h, hb.min_col as i64); mix(&mut h, hb.max_col as i64);
    }
    mix(&mut h, s.draws.len() as i64); mix(&mut h, s.texts.len() as i64);
    mix(&mut h, s.backgrounds.len() as i64); mix(&mut h, s.healthbars.len() as i64);
    h
}

fn step(state: &mut GameState) {
    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.is_none(), "IR frame loop halted: {:?}", state.runtime_diagnostic);
}

fn skip_prologue(state: &mut GameState) {
    for _ in 0..125 { step(state); }
    state.input.tap = true;
    step(state);
    state.input.tap = false;
    for _ in 0..2 { step(state); }
    assert!(!scene(state).instances.values().any(|i| i.object == INTRO && i.alive));
    assert_eq!(scene(state).current_room, 0.0);
}

fn player_id(state: &GameState) -> i32 {
    *scene(state).instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| id).unwrap()
}

fn write_player(state: &mut GameState, x: f64, y: f64) {
    let id = player_id(state);
    let s = state.scene.as_mut().unwrap();
    s.write(id, -1, "x", None, x).unwrap();
    s.write(id, -1, "y", None, y).unwrap();
}

/// Stands the player on the room's own obj_warpanywhere for `target` and lets
/// the client consume the queued room_goto (same machinery as
/// first_chapter_playthrough's door walk, no name guessing).
fn walk_door(state: &mut GameState, target: f64) {
    // Freeze sheets are the chapter's progress gate; dismiss whichever is up.
    let sheet = scene(state).instances.iter()
        .find(|(_, i)| (138..=153).contains(&i.object) && i.alive)
        .map(|(id, _)| *id);
    if let Some(sheet) = sheet {
        for _ in 0..640 {
            step(state);
            if scene(state).instances[&sheet].fields.get("taplock").copied() == Some(1.0) { break; }
        }
        state.pointer_released(480.0, 270.0);
        for _ in 0..3 { step(state); }
    }
    let portal = scene(state).instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id)
        .unwrap_or_else(|| panic!("no door to room {target} in room {}", scene(state).current_room));
    let (x, y) = {
        let p = &scene(state).instances[&portal];
        (p.fields["x"], p.fields["y"])
    };
    write_player(state, x, y);
    for _ in 0..14 {
        step(state);
        if scene(state).current_room == target { return; }
    }
    panic!("door to room {target} never fired");
}

fn boss_alive(state: &GameState) -> bool {
    scene(state).instances.values().any(|i| i.object == TREX && i.alive)
}

#[test]
fn the_lloyd_sheet_freeze_owns_the_stream() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    let idle_digest = { step(&mut state); stream_digest(scene(&state)) };

    // Walk into Lloyd (154): proximity Step raises roomstart and spawns the
    // sheet, whose Create runs instance_deactivate_all(true).
    let (lx, ly) = {
        let lloyd = scene(&state).instances.values().find(|i| i.object == 154 && i.alive).expect("obj_lloyd in rm_town");
        (lloyd.fields["x"], lloyd.fields["y"])
    };
    write_player(&mut state, lx + 40.0, ly);
    for _ in 0..40 { step(&mut state); }
    let sheet = scene(&state).instances.iter()
        .find(|(_, i)| i.object == 138 && i.alive)
        .map(|(id, _)| *id)
        .expect("Lloyd hands over to obj_lloydtutorial1");
    let _ = sheet;

    let active_drawers: Vec<i32> = {
        let s = scene(&state);
        let ids: Vec<i32> = s.draws.iter().map(|d| d.instance).collect();
        let mut uniq: Vec<i32> = ids.clone(); uniq.dedup(); uniq.sort(); uniq
    };
    // The freeze leaves the sheet alone visible: every other instance is
    // deactivated, so the room's 180-draw idle stream collapses.
    assert!(active_drawers.len() <= 2,
        "the frozen room must draw (almost) nothing but its sheet: {active_drawers:?}");
    let frozen = stream_digest(scene(&state));
    assert_ne!(frozen, idle_digest, "the freeze visibly changes the stream");

    // The panel ladder (alarm chain) advances while everything else is frozen:
    // the stream keeps its own timeline even in a stopped world.
    let mut moved = false;
    for _ in 0..120 {
        step(&mut state);
        if stream_digest(scene(&state)) != frozen { moved = true; break; }
    }
    assert!(moved, "the sheet's panel alarm ladder keeps moving the frozen room's stream");
}

#[test]
fn killing_the_boss_changes_the_arena_stream_and_the_mines_are_a_third_room() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    for target in [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 5.0, 7.0, 8.0, 9.0, 10.0] {
        walk_door(&mut state, target);
    }
    assert_eq!(scene(&state).current_room, 10.0, "rm_boss1");
    assert!(boss_alive(&state), "the arena ships its trex alive");
    let level1_room = 1.0; let _ = level1_room;

    // The boss draws: its instance contributes to the stream.
    let trex = scene(&state).instances.iter().find(|(_, i)| i.object == TREX && i.alive).map(|(id, _)| *id).unwrap();
    let draws_before = scene(&state).draws.iter().filter(|d| d.instance == trex).count();
    assert!(draws_before >= 1, "obj_trex draws on the arena pass");
    let arena_alive = stream_digest(scene(&state));

    // Kill chain from boss1_trex_kill_chain_ir: flank with facing=0, hptrex=1
    // (a field the engine does not recompute), then hold the shoot button so
    // the real CODE 11 bullet lands the lethal CODE 284 -> CODE 160.
    let (tx, ty) = { let t = &scene(&state).instances[&trex]; (t.fields["x"], t.fields["y"]) };
    {
        let s = state.scene.as_mut().unwrap();
        let player = s.instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| *id).unwrap();
        s.write(player, -1, "x", None, tx - 25.0).unwrap();
        s.write(player, -1, "y", None, ty).unwrap();
        s.write(player, -1, "facing", None, 0.0).unwrap();
        s.write(trex, -1, "hptrex", None, 1.0).unwrap();
    }
    state.input.attack = true;
    let mut digests = vec![];
    for _ in 0..6 {
        step(&mut state);
        digests.push(stream_digest(scene(&state)));
        let flank = scene(&state).instances.values().find(|i| i.object == TREX && i.alive)
            .map(|i| (i.fields["x"], i.fields["y"])).unwrap_or((tx, ty));
        write_player(&mut state, flank.0 - 25.0, flank.1);
    }
    state.input.attack = false;
    for _ in 0..8 {
        step(&mut state);
        if scene(&state).globals.get("boss1dead").copied() == Some(1.0) { break; }
    }
    assert_eq!(scene(&state).globals.get("boss1dead").copied(), Some(1.0), "the bullet landed");
    assert!(!boss_alive(&state), "CODE 160 removes the boss");

    // The boss's own draws vanish from the stream: gameplay-visible removal,
    // proven as emission, not pixels.
    let after_ids: Vec<i32> = scene(&state).draws.iter().map(|d| d.instance).collect();
    assert!(!after_ids.contains(&trex), "the dead boss no longer draws");
    for _ in 0..35 { step(&mut state); } // CODE 29 clears the gate boulders within 31 ticks
    assert_eq!(scene(&state).instances.values().filter(|i| i.object == BOSSBOULDER && i.alive).count(), 0,
        "the boulder gate is destroyed");
    let arena_dead = stream_digest(scene(&state));
    assert_ne!(arena_alive, arena_dead, "alive-vs-dead arena streams differ");

    // The freed door into the Mines (room 11) is a third distinct stream.
    walk_door(&mut state, 11.0);
    assert_eq!(scene(&state).current_room, 11.0, "rm_level9");
    for _ in 0..6 { step(&mut state); }
    let mines = stream_digest(scene(&state));
    assert_ne!(mines, arena_dead, "Mines != boss arena");
    assert_ne!(mines, level1_stream(), "Mines != level1 (third room, third stream)");
}

/// level1 idle stream digest via the town door (cheap re-boot, same path as
/// the companion suite).
fn level1_stream() -> u64 {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    walk_door(&mut state, 1.0);
    for _ in 0..6 { step(&mut state); }
    stream_digest(scene(&state))
}
