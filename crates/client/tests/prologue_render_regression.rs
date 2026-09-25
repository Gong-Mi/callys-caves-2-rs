use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

/// Regression: the Android prologue must actually fill `scene.draws`
/// each step. Draw events (event_type 8) are dispatched only by an explicit
/// `draw_view` pass — `tick` alone leaves `draws` empty and the prologue
/// renders as a pure black screen on device.
///
/// The prologue now rides the FULL scene exactly like the original boot:
/// enable_ir_gameplay runs Game Start (CODE 17) on a live player, and CODE 17
/// itself spawns obj_introduction (137). While 137 is alive its Create has
/// deactivated the room behind it and draw_frame renders the intro film.
#[test]
fn prologue_step_emits_draw_commands_and_renders_pixels() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");

    let full_ir_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let full_bundle = Arc::new(load_bundle_from_file(&full_ir_path).expect("load full_ir"));
    state
        .enable_ir_gameplay(full_bundle)
        .expect("enable_ir_gameplay with real Game Start");

    // The intro was spawned by CODE 17 itself, inside the full scene.
    assert!(
        state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive),
        "Game Start must spawn obj_introduction into the full scene"
    );

    state.step(1.0 / 60.0);

    let draws = state.scene.as_ref().unwrap().draws.len();
    assert!(draws > 0, "prologue step must emit draw commands via draw_view, got {draws}");

    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    let non_zero = fb.pixels.iter().filter(|&&p| p != 0).count();
    assert!(
        non_zero > 1000,
        "prologue framebuffer must not be a black screen, got {non_zero} non-zero bytes"
    );
}

#[test]
fn prologue_tap_transitions_to_town_gameplay() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");

    let full_ir_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let full_bundle = Arc::new(callys_core::code_vm::load_bundle_from_file(&full_ir_path).expect("load full_ir"));
    state
        .enable_ir_gameplay(full_bundle)
        .expect("enable_ir_gameplay");

    fn intro_alive(state: &GameState) -> bool {
        state
            .scene
            .as_ref()
            .unwrap()
            .instances
            .values()
            .any(|i| i.object == 137 && i.alive)
    }

    // 1. Step 5 frames during prologue: taplock is still 0 (alarm[0] = 120)
    for _ in 0..5 {
        state.step(1.0 / 60.0);
    }
    assert!(intro_alive(&state), "the prologue intro is alive");

    // Tap while taplock == 0 does NOT skip
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    assert!(intro_alive(&state), "taplock == 0 prevents premature tap skip");

    // Step remaining 120 frames to trigger alarm[0] (taplock = 1)
    for _ in 0..120 {
        state.step(1.0 / 60.0);
    }

    // Tap now skips prologue (alarm[0] fired, taplock == 1)
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;

    // The intro dies inside the SAME scene: no separate intro scene ever
    // existed, and the handover must not rebuild the room.
    assert!(!intro_alive(&state), "the tap retires obj_introduction");
    assert!(state.intro_scene.is_none(), "no separate intro scene exists");
    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.current_room, 0.0, "the full scene has been in rm_town since boot");
    // Game Start ran CODE 17: the cold start derives the damage ladder.
    assert_eq!(
        scene.globals.get("maxhp").copied(),
        Some(4.0),
        "CODE 17 cold start must set global.maxhp=4"
    );

    // Original town contract: obj_lloyd's proximity sets roomstart=1 and the
    // tutorial dismissal chain clears it; CODE 16 sets it only in rm_ending
    // (room 110). The player starts far from Lloyd, so it is still 0 here.
    assert_eq!(
        scene.globals.get("roomstart").copied(),
        Some(0.0),
        "town roomstart stays 0 until the original Lloyd proximity gate"
    );

    // Player motion integration in town
    let initial_x = state.scene.as_ref().unwrap().instances.values()
        .find(|i| i.object == 0 && i.alive)
        .unwrap().fields["x"];
    state.input.move_right = true;
    for _ in 0..15 {
        state.step(1.0 / 60.0);
    }
    state.input.move_right = false;
    let moved_x = state.scene.as_ref().unwrap().instances.values()
        .find(|i| i.object == 0 && i.alive)
        .unwrap().fields["x"];
    assert!(moved_x > initial_x, "player moved right in rm_town: {initial_x} -> {moved_x}");

    // Render town frame
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    let non_zero = fb.pixels.iter().filter(|&&p| p != 0).count();
    assert!(non_zero > 1000, "town frame rendered pixels, got {non_zero}");
}
