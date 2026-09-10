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
