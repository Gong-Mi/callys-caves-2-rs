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
//!   - the prologue executes CODE 538's 960x540 choice of view 6 for Draw,
//!     projection and touch unprojection (not a special flat view-0 path).

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
    // Materialize an actual command frame and its captured view before the
    // rasterizer-only fixtures replace queues. Calculating a fresh follow
    // origin without presenting it is not the renderer's coordinate space.
    state.step(1.0 / 30.0);
    assert!(state.runtime_diagnostic.is_none());
    state
}

#[test]
fn rm_town_camera_centers_the_player_then_clamps_to_the_room() {
    let state = state();
    let scene = state.scene.as_ref().unwrap();
    // The runner's follow rule (CCamera::CameraUpdate, disasm @0x170b30):
    // with hborder=vborder=512, 2*512 >= the 448x252 view extent, so the
    // camera CENTERS the player and then clamps to rm_town's 1024x576 bounds.
    let (cx, cy) = GameState::camera_position_for_scene(scene);
    let player = scene.instances.values().find(|i| i.object == 0 && i.alive).unwrap();
    let px = player.fields["x"];
    let py = player.fields["y"];
    let expect_x = (px - 448.0 / 2.0).clamp(0.0, 1024.0 - 448.0);
    let expect_y = (py - 252.0 / 2.0).clamp(0.0, 576.0 - 252.0);
    assert!((cx - expect_x).abs() < 1e-9, "camera centers the player horizontally: {cx} vs {expect_x}");
    assert!((cy - expect_y).abs() < 1e-9, "camera centers the player vertically: {cy} vs {expect_y}");
    assert!(cx >= 0.0 && cx <= 1024.0 - 448.0, "cam_x {cx} inside [0, 576]");
    assert!(cy >= 0.0 && cy <= 576.0 - 252.0, "cam_y {cy} inside [0, 324]");
    // The spawn (416,494) centers to (192,368) with y clamped to 324: the
    // player sits mid-screen horizontally and near the bottom edge — the
    // original's town composition.
    assert!((cx - 192.0).abs() < 1e-9, "spawn cam_x = 416-224 = 192, got {cx}");
    assert!((cy - 324.0).abs() < 1e-9, "spawn cam_y clamps to 576-252 = 324, got {cy}");
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
fn prologue_draw_dispatch_uses_runtime_selected_view_and_projection() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    assert!(state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive));

    // CODE 538 runs on the first frame at this 1136x640 display size — the
    // original's real-device branch: it disables view 6 and enables view 0
    // (448x252 into 1136x640). Draw must use that live choice, not the ROOM
    // record's original visible bit or a prologue-specific flat projection.
    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.is_none(), "first prologue frame must run");
    let scene = state.scene.as_ref().unwrap();
    assert!(scene.view_visible[0] && !scene.view_visible[6], "original resolution GML selects view 0");
    assert_eq!(scene.view, 0, "Draw dispatch must set view_current to the live view");
    assert!(!scene.draws.is_empty(), "the selected view must produce Draw commands");
    assert!(scene.draws.iter().all(|cmd| cmd.view == 0), "commands must carry view 0");

    let (cam_x, cam_y) = GameState::camera_position_for_scene(scene);
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
    let (w, h) = ((x1 - x0 + 1) as f64, (y1 - y0 + 1) as f64);
    // ROOM view[0] is 448x252 and fills the 1136x640 canvas: on the 960-wide
    // framebuffer the 32px sprite scales by 960/448 ≈ 2.143 → ~68.6px.
    let zoom = 960.0 / 448.0;
    assert!((w - 32.0 * zoom).abs() < 3.0, "view 0 should scale sprite width 32→{:.1}, got {w:.0}", 32.0 * zoom);
    assert!((h - 32.0 * zoom).abs() < 3.0, "view 0 should scale sprite height 32→{:.1}, got {h:.0}", 32.0 * zoom);
}

#[test]
fn entering_a_room_reseeds_runtime_view_state_from_its_room_table() {
    let mut state = state();
    let mut target = state.asset.rooms[1].clone();
    target.objects.clear();
    target.tiles.clear();
    let expected_visible: [bool; 8] = std::array::from_fn(|index| {
        target.views.get(index).is_some_and(|view| view.visible)
    });
    let expected_positions: Vec<_> = target.views.iter().take(8).enumerate().map(|(index, view)| {
        (index as i32, (view.xview as f64, view.yview as f64))
    }).collect();
    let expected_ports: Vec<_> = target.views.iter().take(8).enumerate().map(|(index, view)| {
        (index as i32, (view.wport as f64, view.hport as f64))
    }).collect();
    let bundle = state.full_bundle.clone().expect("full IR bundle");
    {
        let scene = state.scene.as_mut().unwrap();
        scene.view_visible = [false; 8];
        scene.view_visible[6] = true;
        scene.view_positions.insert(6, (123.0, 456.0));
        scene.view_ports.insert(6, (12.0, 34.0));
        scene.load_room_from_data(&bundle, 1, &target).expect("load target room");
        assert_eq!(scene.view_visible, expected_visible, "room's static visible bits seed the runtime array");
        assert_eq!(scene.view_positions.iter().map(|(i, p)| (*i, *p)).collect::<Vec<_>>(), expected_positions);
        assert_eq!(scene.view_ports.iter().map(|(i, p)| (*i, *p)).collect::<Vec<_>>(), expected_ports);
    }
}

#[test]
fn prologue_touch_unprojects_through_runtime_selected_view() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    let active = &scene.room_views[0];
    let (cam_x, cam_y) = GameState::camera_position_for_scene(scene);
    let expected = (cam_x + active.wview as f64 / 2.0, cam_y + active.hview as f64 / 2.0);
    let actual = state.screen_to_world(568.0, 320.0);
    assert!((actual.0 - expected.0).abs() < 1e-6, "center X should unproject through view 0: {actual:?} vs {expected:?}");
    assert!((actual.1 - expected.1).abs() < 1e-6, "center Y should unproject through view 0: {actual:?} vs {expected:?}");
}

#[test]
fn touch_screen_to_world_unprojects_through_active_view_zoom() {
    let mut state = state();
    state.step(1.0 / 60.0);
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    let scene = state.scene.as_ref().unwrap();
    let active_index = scene.active_view_index().expect("active view");
    let v = &scene.room_views[active_index];
    assert_eq!(active_index, 0, "1136x640 runtime resolution selects room view 0");
    assert_eq!((v.wview, v.hview), (448, 252));

    // After the first frame, view 0 maps the 1136x640 screen center to the
    // center of its 448x252 room rectangle: (cam_x + 224, cam_y + 126).
    let (wx, wy) = state.screen_to_world(568.0, 320.0);
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

    // Negative control: flat mapping would emit cam_x + 568, i.e. 344 world
    // units away from the view-scaled 224.
    let flat_x = cam_x + 568.0;
    assert!(
        (wx - flat_x).abs() > 200.0,
        "unprojected world X must diverge from unscaled screen offset by >200 units"
    );

    // pointer_pressed and pointer_released must queue the unprojected coordinates
    state.pointer_pressed(568.0, 320.0);
    let queued_press = state.scene.as_ref().unwrap().left_presses.last().copied();
    assert_eq!(queued_press, Some((wx, wy)));

    state.pointer_released(568.0, 320.0);
    let queued_release = state.scene.as_ref().unwrap().left_releases.last().copied();
    assert_eq!(queued_release, Some((wx, wy)));
}

#[test]
fn pointer_uses_last_presented_view_origin_when_follow_camera_moves() {
    let mut state = state();
    let (view_index, view_width, view_height) = {
        let scene = state.scene.as_ref().unwrap();
        let view_index = scene.active_view_index().expect("active view");
        let view = &scene.room_views[view_index];
        (view_index, view.wview as f64, view.hview as f64)
    };
    let presented_origin = (64.0, 32.0);
    {
        let scene = state.scene.as_mut().unwrap();
        scene.view_positions.insert(view_index as i32, presented_origin);
        let player = scene
            .instances
            .values_mut()
            .find(|instance| instance.object == 0 && instance.alive)
            .expect("live player");
        player.fields.insert("x".into(), 900.0);
        player.fields.insert("y".into(), 500.0);
    }

    let scene = state.scene.as_ref().unwrap();
    let current_camera = GameState::camera_position_for_scene(scene);
    assert_ne!(current_camera, presented_origin, "fixture moves the follow camera after presentation");

    let actual = state.screen_to_world(568.0, 320.0);
    let expected = (
        presented_origin.0 + view_width / 2.0,
        presented_origin.1 + view_height / 2.0,
    );
    assert_eq!(actual, expected, "pointer input must use the camera origin of the last presented frame");
}
