//! Acceptance test for the 5 challenge stages (rm_challenge1..5).
//! Verifies room transition, player persistence, tile loading, and real rendering.

use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const PLAYER: i32 = 0;
const INTRO: i32 = 137;

fn boot_like_android() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset_path = root.join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState::new");

    let full_ir_path = root.join("../../crates/core/src/generated/full_ir.json");
    let full_bundle = Arc::new(load_bundle_from_file(&full_ir_path).expect("load full_ir"));
    state.enable_ir_gameplay(full_bundle).expect("enable_ir_gameplay");
    state
}

fn scene(state: &GameState) -> &Scene {
    state.scene.as_ref().expect("IR gameplay scene")
}

fn room(state: &GameState) -> f64 {
    scene(state).current_room
}

fn room_name(state: &GameState, room: f64) -> String {
    state.asset.rooms[room as usize].name.clone()
}

fn cast(state: &GameState, object: i32) -> usize {
    scene(state).instances.values().filter(|i| i.object == object && i.alive).count()
}

fn transition_room(state: &mut GameState, target: usize) {
    let bundle = state.full_bundle.as_ref().expect("bundle").clone();
    let room_data = state.asset.rooms[target].clone();
    let scene = state.scene.as_mut().expect("scene");
    scene
        .transition_to_room(&bundle, target, &room_data)
        .expect("transition_to_room");
}

fn frames(state: &mut GameState, count: usize) {
    for _ in 0..count {
        state.step(1.0 / 60.0);
        assert!(
            state.runtime_diagnostic.is_none(),
            "the IR frame loop must not halt: {:?}",
            state.runtime_diagnostic
        );
    }
}

fn skip_prologue_into_town(state: &mut GameState) {
    for _ in 0..125 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    }
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    frames(state, 2);
    let intro_alive = state
        .scene
        .as_ref()
        .map(|s| s.instances.values().any(|i| i.object == INTRO && i.alive))
        .unwrap_or(false);
    assert!(!intro_alive, "a real tap retires the prologue intro");
    assert_eq!(room(state), 0.0, "the prologue hands over to rm_town");
}

fn rendered_pixels(state: &GameState) -> usize {
    let mut framebuffer = Framebuffer::new(960, 540);
    draw_frame(&mut framebuffer, state, &state.asset.tpag_items, &state.asset.sprites);
    framebuffer.pixels.iter().filter(|&&pixel| pixel != 0).count()
}

#[test]
fn all_five_challenge_rooms_load_step_and_render_with_player() {
    let mut state = boot_like_android();
    skip_prologue_into_town(&mut state);
    frames(&mut state, 15);

    let challenge_rooms: [(usize, &str); 5] = [
        (105, "rm_challenge1"),
        (106, "rm_challenge2"),
        (107, "rm_challenge3"),
        (108, "rm_challenge4"),
        (109, "rm_challenge5"),
    ];

    for (target, expected_name) in challenge_rooms {
        transition_room(&mut state, target);
        assert_eq!(room(&state) as usize, target, "must land in challenge room {target}");
        assert_eq!(room_name(&state, room(&state)), expected_name);
        assert_eq!(
            cast(&state, PLAYER), 1,
            "{expected_name}: exactly one live player after transition"
        );

        // Step 10 frames to ensure alarms and step events run without panic
        frames(&mut state, 10);

        // Verify stage objects populated from game.droid (Challenge rooms
        // are built out of 600~900 dynamic objects rather than static tiles)
        assert!(
            scene(&state).instances.len() > 100,
            "{expected_name} must contain hundreds of challenge objects, got {}",
            scene(&state).instances.len()
        );

        // Verify rendering draws real stage pixels
        let drawn = rendered_pixels(&state);
        assert!(
            drawn > 1000,
            "{expected_name} must visibly render objects/player, got {drawn} non-clear pixels"
        );
    }
}
