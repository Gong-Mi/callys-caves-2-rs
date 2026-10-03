use callys_client::*;
use callys_core::code_vm::load_bundle_from_file;
use std::sync::Arc;
use std::path::Path;

#[test]
fn test_town_rendered_and_player_controls_work() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let droid = Path::new(manifest_dir).join("../../assets/game.droid");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    
    let mut state = GameState::new_persistent(&droid).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).unwrap());
    state.enable_ir_gameplay(bundle.clone()).unwrap();
    
    // Step 125 frames to let prologue alarm[0] = 120 unlock taplock
    for _ in 0..125 {
        state.step(1.0 / 60.0);
    }
    // Tap to dismiss prologue
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    
    // Step 5 frames in rm_town
    for _ in 0..5 {
        state.step(1.0 / 60.0);
    }
    
    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.current_room, 0.0, "must be in rm_town");
    assert_eq!(scene.active_view_index(), Some(0), "1136x640 uses view 0");
    assert!(!scene.draws.is_empty(), "rm_town must emit draw commands");
    assert!(!scene.backgrounds.is_empty(), "rm_town must emit background commands");
    
    // Check player movement via input.move_right + input.jump
    let initial_px = scene.instances.values().find(|i| i.object == 0).unwrap().fields["x"];
    let initial_py = scene.instances.values().find(|i| i.object == 0).unwrap().fields["y"];
    
    state.input.move_right = true;
    state.input.jump = true;
    for _ in 0..10 {
        state.step(1.0 / 60.0);
    }
    state.input.move_right = false;
    state.input.jump = false;
    
    let cur_px = state.scene.as_ref().unwrap().instances.values().find(|i| i.object == 0).unwrap().fields["x"];
    let cur_py = state.scene.as_ref().unwrap().instances.values().find(|i| i.object == 0).unwrap().fields["y"];
    assert!(cur_px > initial_px + 50.0, "player must advance horizontally with move_right");
    assert!(cur_py < initial_py, "player must rise with jump");
    
    // Test sword button press via input.sword
    state.input.sword = true;
    state.step(1.0 / 60.0);
    state.input.sword = false;
    state.step(1.0 / 60.0);
    state.step(1.0 / 60.0);
    
    let player = state.scene.as_ref().unwrap().instances.values().find(|i| i.object == 0).unwrap();
    assert_eq!(player.fields.get("sprite_index").copied(), Some(31.0), "player must switch to spr_playerslash");
    let sword_exists = state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 46 && i.alive);
    assert!(sword_exists, "input.sword must spawn obj_sword (object 46)");
    
    // Test weapon swap via a pointer release inside obj_weaponswap's hit box,
    // unprojected through the view-0 zoom (1136/448 x, 640/252 y) so the tap
    // lands where the button actually sits on the 1136x640 canvas.
    state.scene.as_mut().unwrap().globals.insert("shotgunbought".into(), 1.0);
    assert_eq!(state.scene.as_ref().unwrap().globals.get("shotgun").copied(), Some(0.0));
    assert_eq!(state.scene.as_ref().unwrap().globals.get("pistol").copied(), Some(1.0));
    
    let (swap_x, swap_y) = {
        let swap_inst = state.scene.as_ref().unwrap().instances.iter().find(|(_, i)| i.object == 126).unwrap();
        (swap_inst.1.fields["x"], swap_inst.1.fields["y"])
    };
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    // +40, +14 into the button's sprite box (same nudge as the old flat-canvas
    // tap at 880,30), scaled through the view-0 zoom.
    let tap_x = (swap_x + 40.0 - cam_x) * 1136.0 / 448.0;
    let tap_y = (swap_y + 14.0 - cam_y) * 640.0 / 252.0;
    eprintln!("BEFORE walking, obj_weaponswap: x={swap_x}, y={swap_y}");
    eprintln!("Camera pos: ({cam_x}, {cam_y}); tap canvas ({tap_x:.1}, {tap_y:.1})");
    state.pointer_released(tap_x, tap_y);
    
    // Frame 1: step
    state.step(1.0 / 60.0);
    
    // Check obj_weaponswap alarms after frame 1
    let swap_inst = state.scene.as_ref().unwrap().instances.iter().find(|(_, i)| i.object == 126).unwrap();
    eprintln!("After frame 1 step: obj_weaponswap active = {}, alarms = {:?}", swap_inst.1.active, swap_inst.1.alarms);
    eprintln!("touch_devices[0]: {:?}", state.scene.as_ref().unwrap().touch_devices[0]);
    // Frame 2: obj_weaponswap.alarm[0] fires (CODE 519) -> swaps weapon!
    state.step(1.0 / 60.0);
    
    let shotgun_active = state.scene.as_ref().unwrap().globals.get("shotgun").copied();
    let pistol_active = state.scene.as_ref().unwrap().globals.get("pistol").copied();
    eprintln!("After pointer_released(800, 30): shotgun = {:?}, pistol = {:?}", shotgun_active, pistol_active);
    assert_eq!(shotgun_active, Some(1.0), "shotgun must be active after swap");
    assert_eq!(pistol_active, Some(0.0), "pistol must be inactive after swap");
}
