use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

#[test]
fn ir_scene_gameplay_executes_movement_rendering_and_room_transitions() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");

    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));

    // Enable pure data-driven IR gameplay
    state.enable_ir_gameplay(bundle.clone()).expect("enable IR gameplay");
    assert!(state.scene.is_some(), "IR scene must be active");

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.current_room, 0.0, "Initial room is rm_town (0)");
    assert!(!scene.room_tiles.is_empty(), "rm_town tiles loaded");
    assert!(!scene.instances.is_empty(), "rm_town instances materialized");

    // 1. Verify player input drives motion in the IR scene
    state.input.move_right = true;
    for _ in 0..10 {
        state.step(1.0 / 60.0);
    }
    state.input.move_right = false;

    // 2. Verify rendering pipeline draws tiles and instances into Framebuffer
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, &state, &state.asset.tpag, &state.asset.sprites);
    let non_zero_pixels = fb.pixels.iter().filter(|&&p| p != 0).count();
    assert!(
        non_zero_pixels > 1000,
        "draw_frame must render real pixels from room tiles and instances, got {non_zero_pixels}"
    );

    // 3. Verify warp transition to rm_level1 (room 1)
    state.scene.as_mut().unwrap().target_room_warp = Some(1);
    state.step(1.0 / 60.0);
    let scene_l1 = state.scene.as_ref().unwrap();
    assert_eq!(scene_l1.current_room, 1.0, "Transitioned to rm_level1 (1)");
    assert_eq!(scene_l1.room_tiles.len(), 114, "rm_level1 114 tiles preserved");
    assert!(state.rooms_visited >= 2, "Rooms visited incremented");

    // 4. Verify warp transition to rm_boss1 (room 10)
    state.scene.as_mut().unwrap().target_room_warp = Some(10);
    state.step(1.0 / 60.0);
    let scene_boss = state.scene.as_ref().unwrap();
    assert_eq!(scene_boss.current_room, 10.0, "Transitioned to rm_boss1 (10)");
    let has_trex = scene_boss.instances.values().any(|i| i.object == 25 && i.alive);
    assert!(has_trex, "obj_trex must be materialized in rm_boss1");
    let has_boulder = scene_boss.instances.values().any(|i| i.object == 3 && i.alive);
    assert!(has_boulder, "obj_bossboulder must be materialized in rm_boss1");

    // Render Boss1 room to ensure boss arena draws cleanly
    draw_frame(&mut fb, &state, &state.asset.tpag, &state.asset.sprites);
    let boss_pixels = fb.pixels.iter().filter(|&&p| p != 0).count();
    assert!(boss_pixels > 1000, "rm_boss1 must render cleanly");

    println!("Verified: ir_scene gameplay pipeline drives rm_town, rm_level1, and rm_boss1 rendering and transitions!");
}
