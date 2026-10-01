//! Mines trunk progression: rm_level9 -> ... -> rm_boss2 through the shipped
//! obj_warpanywhere door instances only. Every hop stands the player on the
//! live door whose `warproom` field targets the next room and lets the client
//! consume the queued room_goto — no room_goto injection, no name guessing:
//! the chain 11..27 and both door directions per room were enumerated from
//! the recovered RoomCC creation codes (826/827, 830/829, ... 856/857).
//!
//! This is the H-line continuation of first_chapter_playthrough (which ends
//! entering rm_level9). Each visited room must load, keep exactly one live
//! persistent player, keep obj_music alive (the asset-verified persistent set),
//! and reseed the runtime view from its own ROOM table.
use callys_client::GameState;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const INTRO: i32 = 137;
const PLAYER: i32 = 0;
const WARP: i32 = 69;
const MUSIC: i32 = 68;

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

fn player_id(state: &GameState) -> i32 {
    *scene(state).instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| id).unwrap()
}

/// Stands the player on the live obj_warpanywhere whose own `warproom` field
/// targets `target` and lets the client consume the queued room_goto (the
/// door fires through its original CODE 13 collision, same as
/// first_chapter_playthrough).
fn walk_door(state: &mut GameState, target: f64) {
    let portal = scene(state).instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id)
        .unwrap_or_else(|| {
            let doors: Vec<_> = scene(state).instances.iter()
                .filter(|(_, i)| i.object == WARP && i.alive)
                .map(|(_, i)| (i.fields.get("warproom").copied(), i.active))
                .collect();
            panic!("no door to room {target} in room {}: doors {doors:?}", scene(state).current_room);
        });
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
        if scene(state).current_room == target { return; }
    }
    panic!("door to room {target} never fired: still in room {}", scene(state).current_room);
}

/// The Mines trunk, room ids 11..27, enumerated from the shipped door cards:
/// 9a/11a/… side branches lie one hop off each trunk room; this test takes
/// the forward door (the odd cards) all the way to rm_boss2.
const TRUNK: [(f64, &str); 16] = [
    (11.0, "rm_level9"), (12.0, "rm_level9a"), (13.0, "rm_level10"), (14.0, "rm_level11"),
    (15.0, "rm_level11a"), (16.0, "rm_level12"), (17.0, "rm_level13"), (18.0, "rm_level13a"),
    (19.0, "rm_level14"), (20.0, "rm_level14a"), (21.0, "rm_level15"), (22.0, "rm_level15a"),
    (23.0, "rm_level16"), (24.0, "rm_level16a"), (25.0, "rm_level17"), (26.0, "rm_level17a"),
];
const BOSS2: f64 = 27.0;

#[test]
fn the_mines_trunk_walks_from_level9_to_boss2_through_real_doors() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    // Seed at the trunk entry through the client's own room transition
    // (challenge_rooms_playthrough's machinery): rm_level9 is gated in-game by
    // boss1's freed door, whose kill chain belongs to first_chapter_playthrough
    // and draw_stream_sensitivities. This suite owns the 16-hop Mines trunk
    // from that entry onward.
    {
        let bundle = state.full_bundle.as_ref().expect("bundle").clone();
        let room_data = state.asset.rooms[11].clone();
        let s = state.scene.as_mut().unwrap();
        s.transition_to_room(&bundle, 11, &room_data).expect("enter rm_level9");
    }
    assert_eq!(scene(&state).current_room, 11.0);

    for (id, name) in &TRUNK[1..] {
        walk_door(&mut state, *id);
        assert_eq!(scene(&state).current_room, *id, "door landed in {name}");
        assert_eq!(state.asset.rooms[scene(&state).current_room as usize].name, *name);
        assert_eq!(
            scene(&state).instances.values().filter(|i| i.object == PLAYER && i.alive).count(),
            1, "{name}: exactly one persistent player after the hop"
        );
        assert!(
            scene(&state).instances.values().any(|i| i.object == MUSIC && i.alive),
            "{name}: obj_music survives the hop (asset persistent set)"
        );
        assert!(
            scene(&state).room_views.iter().any(|v| v.visible),
            "{name}: the reseeded runtime view is visible"
        );
    }

    // The arena door: rm_level17a's forward card (856) targets rm_boss2.
    walk_door(&mut state, BOSS2);
    assert_eq!(state.asset.rooms[scene(&state).current_room as usize].name, "rm_boss2");
    assert_eq!(
        scene(&state).instances.values().filter(|i| i.object == PLAYER && i.alive).count(),
        1, "the player walks into the boss2 arena");
}
