//! Room-editor VIEW projection consumption.
//!
//! Device evidence (2026-09-26, original APK sha256 d608f455… vs our build,
//! same-phone captures): the original renders rm_town's world sprites at
//! ~2.54x our flat 960x540 projection. Direct ROOM-chunk probe of game.droid
//! pinned the cause: rm_town view[0] is visible with wview=448, hview=252,
//! wport=1136, hport=640, hborder=vborder=512, no auto-scroll, following
//! obj_player — GM8.1 zooms the view rect into the port.
//!
//! These tests pin the client's consumption of that table:
//!   - the projection scale becomes fb/port × (port/view),
//!   - the camera follows obj_player inside the border dead-zone and clamps
//!     to the room bounds,
//!   - the prologue keeps the flat projection (the intro pins view 0 to the
//!     room origin).

use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

fn state() -> GameState {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    state.retire_prologue();
    state
}

#[test]
fn rm_town_camera_clamps_to_the_view_rect_inside_the_room() {
    let state = state();
    let scene = state.scene.as_ref().unwrap();
    // rm_town is 1024x576; the view is 448x252, so the clamp range is
    // [0, 1024-448] x [0, 576-252].
    let (cx, cy) = GameState::camera_position_for_scene(scene);
    assert!(cx >= 0.0 && cx <= 1024.0 - 448.0, "cam_x {cx} inside [0, 576]");
    assert!(cy >= 0.0 && cy <= 576.0 - 252.0, "cam_y {cy} inside [0, 324]");
    // The player spawns near the room start; the border dead-zone (512 ≥ half
    // the view) means the camera only leaves 0 once the player crosses
    // xview+half+… — with hborder=512 > half_w=224 the dead-zone pin holds
    // the camera at the initial rect for the spawn area.
    let player = scene.instances.values().find(|i| i.object == 0 && i.alive).unwrap();
    let px = player.fields["x"];
    let center_x = 0.0 + 448.0 / 2.0;
    // Dead-zone semantics: |px - center| > hb(=min(512, 224)=224) never at spawn.
    if (px - center_x).abs() <= 224.0 {
        assert!((cx - 0.0).abs() < 1e-9, "camera stays at the view start inside the dead zone, got {cx}");
    }
}

#[test]
fn view_projection_zooms_world_sprites_by_the_port_view_ratio() {
    let mut state = state();
    // A 32x32 world sprite (spr_set1wall) at a fixed camera-relative offset:
    // the view projection must scale its on-screen extent by
    // fb/port * port/view = fb/view = 960/448 ≈ 2.143 on both axes.
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    {
        let scene = state.scene.as_mut().unwrap();
        scene.draws.clear();
        scene.backgrounds.clear();
        scene.room_tiles.clear();
        scene.texts.clear();
        scene.healthbars.clear();
        scene.particles.clear();
        scene.draws.push(callys_core::ir_scene::DrawCommand {
            code: 0, offset: 0, instance: -1, view: 0,
            sprite: 6, frame: 0.0, x: cam_x + 60.0, y: cam_y + 40.0,
            scale_x: 1.0, scale_y: 1.0, rotation: 0.0, color: -1, alpha: 1.0, fog: false,
        });
    }
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    let mut x0 = i64::MAX; let mut x1 = i64::MIN;
    let mut y0 = i64::MAX; let mut y1 = i64::MIN;
    for y in 0..fb.height as i32 {
        for x in 0..fb.width as i32 {
            let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
            let (b, g, r) = (fb.pixels[i], fb.pixels[i+1], fb.pixels[i+2]);
            if (r, g, b) != (15, 18, 30) && (r as u16 + g as u16 + b as u16) > 60 {
                x0 = x0.min(x as i64); x1 = x1.max(x as i64);
                y0 = y0.min(y as i64); y1 = y1.max(y as i64);
            }
        }
    }
    assert!(x0 < x1 && y0 < y1, "the sprite must land on the framebuffer");
    let w = (x1 - x0 + 1) as f64;
    let h = (y1 - y0 + 1) as f64;
    let zoom = 960.0 / 448.0;
    assert!(
        (w - 32.0 * zoom).abs() < 32.0 * zoom * 0.1,
        "view zoom must scale the 32px-wide sprite to ~{:.0}px, got {w:.0}px", 32.0 * zoom
    );
    assert!(
        (h - 32.0 * zoom).abs() < 32.0 * zoom * 0.1,
        "view zoom must scale the 32px-tall sprite to ~{:.0}px, got {h:.0}px", 32.0 * zoom
    );
}

#[test]
fn prologue_keeps_the_flat_projection() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    // The intro is alive: the room view must NOT zoom the prologue.
    let intro_alive = state.scene.as_ref().unwrap()
        .instances.values().any(|i| i.object == 137 && i.alive);
    assert!(intro_alive, "cold boot holds the prologue");
    let (_cam_x, _cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    let scene = state.scene.as_mut().unwrap();
    scene.draws.clear();
    scene.backgrounds.clear();
    scene.room_tiles.clear();
    scene.texts.clear();
    scene.healthbars.clear();
    scene.particles.clear();
    scene.draws.push(callys_core::ir_scene::DrawCommand {
        code: 0, offset: 0, instance: -1, view: 0,
        sprite: 161, frame: 0.0, x: 100.0, y: 100.0,
        scale_x: 1.0, scale_y: 1.0, rotation: 0.0, color: -1, alpha: 1.0, fog: false,
    });
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    let mut x0 = i64::MAX; let mut x1 = i64::MIN;
    let mut y0 = i64::MAX; let mut y1 = i64::MIN;
    for y in 0..fb.height as i32 {
        for x in 0..fb.width as i32 {
            let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
            let (b, g, r) = (fb.pixels[i], fb.pixels[i+1], fb.pixels[i+2]);
            if (r, g, b) != (0, 0, 0) && (r as u16 + g as u16 + b as u16) > 60 {
                x0 = x0.min(x as i64); x1 = x1.max(x as i64);
                y0 = y0.min(y as i64); y1 = y1.max(y as i64);
            }
        }
    }
    assert!(x0 < x1 && y0 < y1, "the sprite must land");
    let w = (x1 - x0 + 1) as f64;
    // Flat projection: the 208px sprite stays ~208px wide (within rounding).
    assert!((w - 208.0).abs() < 12.0,
        "the prologue keeps the flat 1:1 projection: 208px sprite must stay ~208px, got {w:.0}px");
}

#[test]
fn touch_screen_to_world_unprojects_through_active_view_zoom() {
    let mut state = state();
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    let scene = state.scene.as_ref().unwrap();
    let v = scene.room_views.iter().find(|v| v.visible).expect("visible view");
    assert_eq!((v.wview, v.hview), (448, 252));

    // Outside the prologue, 960x540 screen center (480, 270) must unproject to the
    // center of the 448x252 view rect: (cam_x + 224, cam_y + 126).
    let (wx, wy) = state.screen_to_world(480.0, 270.0);
    assert!(
        (wx - (cam_x + 224.0)).abs() < 1e-4,
        "screen_to_world X must scale into view rect: expected {}, got {}",
        cam_x + 224.0,
        wx
    );
    assert!(
        (wy - (cam_y + 126.0)).abs() < 1e-4,
        "screen_to_world Y must scale into view rect: expected {}, got {}",
        cam_y + 126.0,
        wy
    );

    // Negative control: flat mapping would have emitted cam_x + 480.0, drifting
    // by 256 world units (landing outside the view rect entirely).
    let flat_x = cam_x + 480.0;
    assert!(
        (wx - flat_x).abs() > 200.0,
        "unprojected world X must diverge from unscaled screen offset by >200 units"
    );

    // pointer_pressed and pointer_released must queue the unprojected coordinates
    state.pointer_pressed(480.0, 270.0);
    let queued_press = state.scene.as_ref().unwrap().left_presses.last().copied();
    assert_eq!(queued_press, Some((wx, wy)));

    state.pointer_released(480.0, 270.0);
    let queued_release = state.scene.as_ref().unwrap().left_releases.last().copied();
    assert_eq!(queued_release, Some((wx, wy)));
}
