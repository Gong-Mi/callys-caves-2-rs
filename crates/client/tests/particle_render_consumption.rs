//! Client rasterization acceptance for the original particle domain: real
//! CODE 458 config + CODE 281 (obj_arrow Step) hit spawning, then draw_frame
//! must emit the particles as pixels. A/B pixel diff against the same scene
//! without particles isolates the particle contribution from tiles/UI.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

#[test]
fn hit_particles_rasterize_into_framebuffer() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle.clone()).expect("enable IR gameplay");

    let s = state.scene.as_mut().unwrap();

    // Reuse the materialized rm_town player; place it within 16 px of the
    // impact so CODE 281's wall+distance branch stays false.
    let player = s.instances.iter_mut().find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id).expect("rm_town player");
    s.instances.get_mut(&player).unwrap().fields.insert("x".into(), 210.0);
    s.instances.get_mut(&player).unwrap().fields.insert("y".into(), 40.0);
    s.instances.get_mut(&player).unwrap().fields.insert("facing".into(), 1.0);

    // Original initialization order: pwr initializer first, then actors, in
    // clear sky at y=40 to minimize tile/UI occlusion.
    let init = s.create(&bundle, 103, -1000.0, -1000.0).expect("create pwr init");
    s.instances.get_mut(&init).unwrap().alive = false;
    let victim = s.create(&bundle, 15, 200.0, 40.0).expect("create knifebandit");
    let arrow = s.create(&bundle, 38, 200.0, 40.0).expect("create arrow");

    s.dispatch(&bundle, arrow, 3, 0).expect("dispatch obj_arrow Step");
    assert_eq!(s.particles.len(), 3, "hit must spawn 3 particles");

    // Draw A: with particles. Impact at world (200,40); camera clamps to
    // (0,0) here, so the spawn square is centered at screen (200,40).
    let mut fb_a = Framebuffer::new(960, 540);
    draw_frame(&mut fb_a, &state, &state.asset.tpag_items, &state.asset.sprites);

    // Draw B: identical scene minus particles.
    let saved = std::mem::take(&mut state.scene.as_mut().unwrap().particles);
    let mut fb_b = Framebuffer::new(960, 540);
    draw_frame(&mut fb_b, &state, &state.asset.tpag_items, &state.asset.sprites);
    state.scene.as_mut().unwrap().particles = saved;

    // Pixel decode: ABGR8888 row-major.
    let px = |fb: &Framebuffer, x: i32, y: i32| -> (u8, u8, u8, u8) {
        let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
        (fb.pixels[i + 2], fb.pixels[i + 1], fb.pixels[i], fb.pixels[i + 3])
    };

    // 1. Spawn color is original color1 = white (16777215) at the center.
    let (r, g, b, _) = px(&fb_a, 200, 40);
    assert!(r >= 250 && g >= 250 && b >= 250,
        "spawn particle pixel must be original color1 white, got ({r},{g},{b})");

    // 2. A/B diff inside the impact region must show a real particle patch
    // (3 overlapping 4x4 squares, tolerate partial occlusion).
    let mut diff = 0;
    for y in 24..56 {
        for x in 180..220 {
            if px(&fb_a, x, y) != px(&fb_b, x, y) {
                diff += 1;
            }
        }
    }
    assert!(diff >= 8, "particles must visibly rasterize, diff pixels = {diff}");
}
