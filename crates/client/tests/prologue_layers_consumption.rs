use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::BackgroundCommand;
use std::path::Path;
use std::sync::Arc;

/// The gameplay frame produces three command queues from the live bytecode:
/// sprite draws (draw_self / draw_sprite_ext), the room background (obj_bg
/// CODE 364), and HUD text (obj_UI CODE 370, pause button CODE 520). Each of
/// these carries visible information; historically our draw_frame's frame
/// branch consumed only `scene.draws` and dropped the other two.
///
/// The prologue film frame itself carries NO instance layers: CODE 548
/// deactivates every instance but the film set, and deactivated instances are
/// neither stepped nor drawn (binary-verified: CInstance::SetDeactivated
/// writes +0x69; DrawInstancesOnly skips +0x69 != 0). The boot frame shows
/// the room's own tile layers plus the film — room layers render every frame
/// in the original (DrawTheRoom -> DrawRoomLayers runs over the room's layer
/// set regardless of instance state). The instance queues below belong to the
/// first gameplay frame, so the harness retires the film with the original tap
/// gate first.
fn boot_common() -> GameState {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let full_ir_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&full_ir_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state
}

/// Retire the prologue film with the original tap gate (125 ticks, then tap).
fn retire_prologue(state: &mut GameState) {
    for _ in 0..125 {
        state.step(1.0 / 60.0);
    }
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    state.step(1.0 / 60.0);
}

/// First gameplay frame (film retired): instance queues are live here.
fn boot_state() -> GameState {
    let mut state = boot_common();
    retire_prologue(&mut state);
    state
}

/// Film frame (obj_introduction still alive): renders through the prologue
/// branch, where only room layers + the film are drawn. One step runs the
/// runtime view selector (CODE 538) so the frame already uses view 0.
fn film_state() -> GameState {
    let mut state = boot_common();
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

#[test]
fn draw_background_renders_once_in_the_selected_view_without_tiling() {
    // Runs on the film frame (prologue branch with its black baseline); the
    // film frame's own instance queues are empty by construction (all but the
    // film set are deactivated and not drawn), so the single draw_background
    // command is hand-built from the real resource data.
    let mut state = film_state();
    let scene = state.scene.as_ref().unwrap();
    let view_index = scene.active_view_index().expect("visible runtime view");
    let view = scene.room_views[view_index].clone();
    assert_eq!(view_index, 0, "CODE 538 selects view 0 at 1136x640");
    let (cam_x, cam_y) = GameState::camera_position_for_scene(scene);
    let (&bg_id, bg) = state
        .asset
        .backgrounds
        .iter()
        .min_by_key(|(k, _)| **k)
        .expect("background resource");
    let page = state.asset.tpag_items.get(&bg.tpag_ptr).expect("background texture page");
    assert!(page.w > 0 && page.h > 0);

    // Scale the real background draw to an 80x60-pixel rectangle at the current
    // view origin. This makes an accidental second tile directly observable.
    let mut command = BackgroundCommand {
        code: 0,
        offset: 0,
        instance: 0,
        view: view_index as i32,
        background: bg_id as i32,
        x: cam_x,
        y: cam_y,
        scale_x: 80.0 / (page.w as f64 * 960.0 / view.wview as f64),
        scale_y: 60.0 / (page.h as f64 * 540.0 / view.hview as f64),
        rotation: 0.0,
        color: 0xFFFFFF,
        alpha: 1.0,
    };
    command.x = cam_x;
    command.y = cam_y;
    {
        let scene = state.scene.as_mut().unwrap();
        scene.draws.clear();
        scene.backgrounds.clear();
        scene.backgrounds.push(command);
        scene.room_tiles.clear();
        scene.texts.clear();
        scene.healthbars.clear();
        scene.particles.clear();
    }

    let fb = render(&state);
    let mut first_rect_changes = 0;
    let mut outside_changes = 0;
    for y in 0..fb.height {
        for x in 0..fb.width {
            let i = ((y * fb.width + x) * 4) as usize;
            let pixel = &fb.pixels[i..i + 4];
            if x < 80 && y < 60 {
                if pixel[0..3] != [0, 0, 0] { first_rect_changes += 1; }
            } else if pixel[0..3] != [0, 0, 0] {
                outside_changes += 1;
            }
        }
    }
    assert!(first_rect_changes > 0, "single background image must rasterize in its destination rect");
    assert_eq!(outside_changes, 0, "draw_background must not tile beyond its single destination rect");
}
