use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::prologue_bundle;
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

/// Regression: the Android prologue must actually fill `intro_scene.draws`
/// each step. Draw events (event_type 8) are dispatched only by an explicit
/// `draw_view` pass — `tick` alone leaves `draws` empty and the prologue
/// renders as a pure black screen on device.
#[test]
fn prologue_step_emits_draw_commands_and_renders_pixels() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");

    // Mirror android_jni nativeInit: prologue bundle + view 0 at origin.
    let bundle = Arc::new(prologue_bundle());
    let mut scene = Scene::default();
    scene.view_positions.insert(0, (0.0, 0.0));
    scene
        .create(&bundle, 137, 0.0, 0.0)
        .expect("prologue obj_introduction Create failed");
    state.intro_bundle = Some(bundle);
    state.intro_scene = Some(scene);

    state.step(1.0 / 60.0);

    let draws = state.intro_scene.as_ref().unwrap().draws.len();
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
    state.full_bundle = Some(full_bundle);

    let bundle = Arc::new(prologue_bundle());
    let mut scene = Scene::default();
    scene.view_positions.insert(0, (0.0, 0.0));
    scene
        .create(&bundle, 137, 0.0, 0.0)
        .expect("prologue obj_introduction Create failed");
    state.intro_bundle = Some(bundle);
    state.intro_scene = Some(scene);

    // 1. Step 5 frames during prologue: taplock is still 0 (alarm[0] = 120)
    for _ in 0..5 {
        state.step(1.0 / 60.0);
    }
    assert!(state.intro_scene.is_some(), "intro_scene is active");

    // Tap while taplock == 0 does NOT skip
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    assert!(state.intro_scene.is_some(), "taplock == 0 prevents premature tap skip");

    // Step remaining 120 frames to trigger alarm[0] (taplock = 1)
    for _ in 0..120 {
        state.step(1.0 / 60.0);
    }

    // Tap now skips prologue (alarm[0] fired, taplock == 1)
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;

    // Must transition to gameplay scene in rm_town
    assert!(state.intro_scene.is_none(), "intro_scene must be cleared after tap");
    assert!(state.scene.is_some(), "gameplay scene must be active");
    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.current_room, 0.0, "current_room must be rm_town (0)");
    assert_eq!(scene.globals.get("roomstart").copied(), Some(1.0), "Room Start set roomstart=1");

    // Step 15 frames to clear roomstart lock (alarm[6] = 10)
    for _ in 0..15 {
        state.step(1.0 / 60.0);
    }
    assert_eq!(state.scene.as_ref().unwrap().globals.get("roomstart").copied(), Some(0.0), "roomstart cleared");

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
