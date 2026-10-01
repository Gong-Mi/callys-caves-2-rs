//! Boss kill chains 2..6 at the client layer — the H-line capstone after the
//! trunk playthroughs. Mechanism (all recovered-GML facts, core suites pin
//! the same dispatch paths):
//!
//! - boss2 (obj 26, room 27): Step sees hpboss2<=0 -> alarm[0]=1 -> Alarm 0
//!   writes global.boss2dead = 1;
//! - boss3 (obj 27, room 48): Step at hpboss3<=0 -> Alarm 0 (CODE 184) writes
//!   global.boss3dead = 1;
//! - boss4 (obj 28, room 64) / boss5 (obj 29, room 82): same Step->Alarm
//!   shape (core bosses_3_5_ir dispatches these at hp 0);
//! - boss6 (obj_finalboss 30, room 104): Step at hpfinalboss<=0 spawns
//!   obj_finalbosspuff (189); the puff's Destroy (CODE 787) does
//!   instance_deactivate_object(obj_player); room_goto(rm_ending=110).
//!   The original chain NEVER writes global.boss6dead — that name is only
//!   read (player save/load, bossboulder gate, map/restore buttons) across
//!   all 1,354 recovered GML units; asserting it would fabricate a flag.
//!
//! Injection discipline: hpbossN / hpfinalboss are per-instance fields the
//! engine NEVER recomputes after Create (only bullet Collision decrements
//! them); setting them to 0 hands the lethal transition to the boss's own
//! original code — same evidence class as the boss1 bullet chain in
//! draw_stream_sensitivities, without needing per-boss damage immunity rules.
//!
//! Boulder gate: obj_bossboulder (3) CODE 29 re-scans global.bossNdead every
//! 30 ticks and self-destructs; all six arenas share it. After the kill the
//! region's forward door (boss2->28, boss3->49, boss4->65, boss5->83) must
//! fire; boss6 has no forward door — the puff Destroy IS the exit.
use callys_client::GameState;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const INTRO: i32 = 137;
const PLAYER: i32 = 0;
const WARP: i32 = 69;
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
    assert!(state.runtime_diagnostic.is_none(), "IR frame loop halted: {:?}", state.runtime_diagnostic);
}

fn skip_prologue(state: &mut GameState) {
    for _ in 0..125 { step(state); }
    state.input.tap = true;
    step(state);
    state.input.tap = false;
    for _ in 0..2 { step(state); }
    assert!(!scene(state).instances.values().any(|i| i.object == INTRO && i.alive));
}

fn enter_room(state: &mut GameState, room: usize) {
    let bundle = state.full_bundle.as_ref().expect("bundle").clone();
    let room_data = state.asset.rooms[room].clone();
    let s = state.scene.as_mut().unwrap();
    s.transition_to_room(&bundle, room, &room_data).expect("transition");
}

fn boss_alive(state: &GameState, obj: i32) -> bool {
    scene(state).instances.values().any(|i| i.object == obj && i.alive)
}

fn boss_draws(state: &GameState, obj: i32) -> usize {
    let s = scene(state);
    let ids: Vec<i32> = s.instances.iter().filter(|(_, i)| i.object == obj && i.alive).map(|(id, _)| *id).collect();
    s.draws.iter().filter(|d| ids.contains(&d.instance)).count()
}

fn inject_hp(state: &mut GameState, obj: i32, field: &str) {
    let id = scene(state).instances.iter().find(|(_, i)| i.object == obj && i.alive).map(|(id, _)| *id)
        .unwrap_or_else(|| panic!("obj {obj} alive in room {}", scene(state).current_room));
    state.scene.as_mut().unwrap().write(id, -1, field, None, 0.0).expect("write hp");
}

/// Kill bossN: step (bounded) until global.bossNdead == 1, asserting the
/// boss's own Step->Alarm chain did it (not a fabricated flag write).
fn kill_boss(state: &mut GameState, obj: i32, hp_field: &str, dead_flag: &str) {
    // Settle the arena first: the draws queue only reflects the last stepped
    // view pass, and right after transition_to_room it still holds the
    // previous room's pass (probe: the queue stabilises within ~15 frames).
    for _ in 0..20 { step(state); }
    inject_hp(state, obj, hp_field);
    for _ in 0..120 {
        step(state);
        if scene(state).globals.get(dead_flag).copied() == Some(1.0) { break; }
    }
    assert_eq!(scene(state).globals.get(dead_flag).copied(), Some(1.0),
        "boss{dead_flag} chain fired within 120 frames");
    assert!(!boss_alive(state, obj), "the boss instance is gone after its death alarm");
}

/// After the kill: boulders clear within the CODE 29 window, then the
/// region's forward door fires through its own CODE 13 collision.
fn gate_opens(state: &mut GameState, forward: f64) {
    for _ in 0..40 { step(state); }
    assert_eq!(scene(state).instances.values().filter(|i| i.object == BOULDER && i.alive).count(), 0,
        "obj_bossboulder (CODE 29) cleared after the kill");
    let portal = scene(state).instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(forward))
        .map(|(id, _)| *id)
        .expect("forward door present after the gate opened");
    let (x, y) = {
        let p = &scene(state).instances[&portal];
        (p.fields["x"], p.fields["y"])
    };
    let player = *scene(state).instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| id).unwrap();
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "x", None, x).unwrap();
        s.write(player, -1, "y", None, y).unwrap();
    }
    for _ in 0..14 {
        step(state);
        if scene(state).current_room == forward { return; }
    }
    panic!("forward door to {forward} never fired after the kill");
}

macro_rules! boss_kill_suite {
    ($name:ident, $obj:expr, $room:expr, $hp:expr, $flag:expr, $forward:expr, $label:literal) => {
        #[test]
        fn $name() {
            let mut state = boot_like_android();
            skip_prologue(&mut state);
            enter_room(&mut state, $room);
            for _ in 0..20 { step(&mut state); } // settle: queue holds the previous room's pass otherwise
            assert!(boss_alive(&state, $obj), $label);
            let draws_before = boss_draws(&state, $obj);
            assert!(draws_before >= 1, "{} draws while alive", $label);
            kill_boss(&mut state, $obj, $hp, $flag);
            assert_eq!(boss_draws(&state, $obj), 0, "{} no longer draws after death", $label);
            gate_opens(&mut state, $forward);
        }
    };
}

boss_kill_suite!(boss2_kill_opens_the_depths, 26, 27, "hpboss2", "boss2dead", 28.0, "boss2");
boss_kill_suite!(boss3_kill_opens_the_core, 27, 48, "hpboss3", "boss3dead", 49.0, "boss3");
boss_kill_suite!(boss4_kill_opens_the_lab, 28, 64, "hpboss4", "boss4dead", 65.0, "boss4");
boss_kill_suite!(boss5_kill_opens_the_lair, 29, 82, "hpboss5", "boss5dead", 83.0, "boss5");

#[test]
fn boss6_kill_is_the_ending_itself() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    enter_room(&mut state, 104);
    // Settle before touching the boss: obj_boss6intro's alarm (0778/0779)
    // materialises the arena on its own schedule — injecting before the
    // intro fires would zero a stale instance while the intro later
    // re-creates a fresh full-HP boss that survives into the ending room
    // (probe: 20 settle frames make the cast stable).
    for _ in 0..20 { step(&mut state); }
    assert!(boss_alive(&state, 30), "obj_finalboss in rm_boss6");
    inject_hp(&mut state, 30, "hpfinalboss");
    // The boss's Step at hp 0 destroys itself and spawns obj_finalbosspuff
    // (probe: fb gone by t=5). Assert the death BEFORE the warp — rm_ending's
    // own RoomData places obj_finalboss for the ending scene, so checking
    // "boss gone" after the warp would flag the ending's own placement.
    for _ in 0..30 {
        step(&mut state);
        if !boss_alive(&state, 30) { break; }
    }
    assert!(!boss_alive(&state, 30), "the final boss died in the arena");
    // The puff's Destroy (CODE 787, armed alarm[3]=129 at Create) does
    // instance_deactivate_object(obj_player); room_goto(rm_ending). Bounded
    // window: 300 frames is generous over the 129-tick ladder.
    let mut reached = false;
    for _ in 0..300 {
        step(&mut state);
        if scene(&state).current_room == 110.0 { reached = true; break; }
    }
    assert!(reached, "the finalbosspuff Destroy chain landed in rm_ending (110)");
    assert_eq!(state.asset.rooms[110].name, "rm_ending", "room 110 is rm_ending");
    // The original chain NEVER writes global.boss6dead (grep of all 1,354
    // recovered GML units: only reads in player save/load, bossboulder and
    // map/restore buttons) — do not assert a flag the game itself never sets.
    // CODE 787's documented side effect is the player deactivation:
    let player_active = scene(&state)
        .instances.values().any(|i| i.object == PLAYER && i.alive && i.active);
    assert!(!player_active, "CODE 787 deactivated obj_player before the ending warp");
}
