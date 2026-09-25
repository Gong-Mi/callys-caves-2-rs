use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

/// The prologue produces three command queues from the live bytecode: sprite
/// draws (draw_self / draw_sprite_ext from obj_phone + obj_logo), the room
/// background (obj_bg CODE 364), and HUD text (obj_UI CODE 370, pause button
/// CODE 520). Each of these carries visible information in the original
/// runner's boot frame; historically our draw_frame's prologue branch
/// consumed only `scene.draws` and dropped the other two.
///
/// Probe evidence for layers present on every tick during the natural
/// prologue run: draws=147..176, backgrounds=1 (obj_bg CODE 364), texts=3
/// (CODE 370×2 + CODE 520). The original runner's boot frame shows the
/// backdrop, the scrolling film sprite, and the HUD text simultaneously.
///
/// This test renders the prologue with and without each supplementary
/// queue and asserts the difference actually lands on the framebuffer — an
/// A/B pixel-difference harness mirroring the `draw_field_consumption` /
/// `particle_render_consumption` patterns.
fn boot_state() -> GameState {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let full_ir_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&full_ir_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state.step(1.0 / 60.0);
    state
}

fn render(state: &GameState) -> Framebuffer {
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, state, &state.asset.tpag_items, &state.asset.sprites);
    fb
}

fn diff_count(a: &Framebuffer, b: &Framebuffer) -> usize {
    a.pixels.iter().zip(b.pixels.iter()).filter(|(x, y)| x != y).count()
}

#[test]
fn prologue_background_layer_lands_on_framebuffer() {
    let mut state = boot_state();
    let full = render(&state);
    let full_bgs = state.scene.as_ref().unwrap().backgrounds.len();
    assert!(full_bgs > 0, "probe: backgrounds queue has obj_bg draws, got {full_bgs}");

    state.scene.as_mut().unwrap().backgrounds.clear();
    let no_bg = render(&state);

    let diff = diff_count(&full, &no_bg);
    // obj_bg CODE 364 draws either background_town or another backdrop at
    // view_yview-48; consuming it must change tens of thousands of pixels.
    assert!(diff > 10_000, "backgrounds clear must change the framebuffer; diff={diff} bytes");
}

#[test]
fn prologue_text_layer_lands_on_framebuffer() {
    let mut state = boot_state();
    let full = render(&state);
    let full_texts = state.scene.as_ref().unwrap().texts.len();
    assert!(full_texts > 0, "probe: HUD texts present, got {full_texts}");

    state.scene.as_mut().unwrap().texts.clear();
    let no_text = render(&state);

    let diff = diff_count(&full, &no_text);
    assert!(diff > 50, "texts clear must change the framebuffer; diff={diff}");
}
