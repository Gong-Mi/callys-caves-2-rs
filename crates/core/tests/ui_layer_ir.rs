use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

#[test]
fn ui_buttons_touch_and_player_motion_integration() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");

    let mut s = Scene::default();
    s.init_bundle(&bundle);

    // Register button sprite bounds (from sprites.json metadata)
    s.sprite_bounds.insert(158, SpriteBounds { width: 96.0, height: 64.0, origin_x: 0.0, origin_y: 0.0 }); // spr_leftbutton
    s.sprite_bounds.insert(159, SpriteBounds { width: 96.0, height: 64.0, origin_x: 0.0, origin_y: 0.0 }); // spr_rightbutton
    s.sprite_bounds.insert(155, SpriteBounds { width: 64.0, height: 64.0, origin_x: 0.0, origin_y: 0.0 }); // spr_jumpbutton
    s.sprite_bounds.insert(156, SpriteBounds { width: 64.0, height: 64.0, origin_x: 0.0, origin_y: 0.0 }); // spr_shootbutton
    s.sprite_bounds.insert(84, SpriteBounds { width: 512.0, height: 88.0, origin_x: 0.0, origin_y: 0.0 });  // spr_UI

    s.view_positions.insert(0, (0.0, 0.0));

    // Create external obj_player (object id 0)
    let player_id = s.insert_external(0);
    {
        let pi = s.instances.get_mut(&player_id).unwrap();
        pi.fields.insert("x".into(), 100.0);
        pi.fields.insert("y".into(), 100.0);
        pi.fields.insert("hsp".into(), 0.0);
        pi.fields.insert("vsp".into(), 0.0);
        pi.fields.insert("grounded".into(), 1.0);
        pi.fields.insert("sliding1".into(), 0.0);
        pi.fields.insert("sliding2".into(), 0.0);
        pi.fields.insert("djump".into(), 1.0);
        pi.fields.insert("tjump".into(), 0.0);
        pi.fields.insert("sprite_index".into(), 29.0);
    }

    // Provide player progression globals (normally set by obj_player_Other_2)
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("health1".into(), 4.0);
    s.globals.insert("experience".into(), 0.0);
    s.globals.insert("xptolevelup".into(), 30.0);
    s.globals.insert("roomstart".into(), 0.0);
    s.globals.insert("assaultrifle".into(), 0.0);
    s.globals.insert("shotgun".into(), 0.0);
    s.globals.insert("pistol".into(), 1.0);
    s.globals.insert("tjumpactive".into(), 0.0);
    s.globals.insert("soundmute".into(), 0.0);
    s.globals.insert("drawlevelup".into(), 0.0);
    s.globals.insert("drawweaponchange".into(), 0.0);
    s.globals.insert("drawweaponlevelup".into(), 0.0);
    s.globals.insert("strengthupgradebought".into(), 0.0);
    s.globals.insert("strengthupgrade2bought".into(), 0.0);
    for w in [
        "assaultriflelevel", "bladegunlevel", "bombgunlevel", "boomeranglevel", "bowlevel",
        "flamethrowerlevel", "icegunlevel", "laserlevel", "pistollevel", "rocketlevel",
        "shotgunlevel", "spikegunlevel",
    ] {
        s.globals.insert(w.into(), 1.0);
    }

    // Create obj_UI (object id 66)
    let ui_id = s.create(&bundle, 66, 0.0, 0.0).expect("create obj_UI");
    s.instances.get_mut(&ui_id).unwrap().fields.insert("score".into(), 100.0);
    assert!(s.instances.contains_key(&ui_id));

    // Verify globals created by obj_UI Create (CODE 365)
    assert!(s.globals.contains_key("coinsound"));
    assert!(s.globals.contains_key("swordsound"));
    assert!(s.globals.contains_key("playlist"));
    assert_eq!(s.globals["firing"], 0.0);

    // Verify spawned button objects
    let spawned_objects: Vec<i32> = s.instances.values().map(|i| i.object).collect();
    // obj_viewresolution (133), obj_shootbutton (128), obj_jumpbutton (127),
    // obj_swordbutton (129), obj_leftbutton (130), obj_rightbutton (131), obj_pausebutton (125)
    for expected_obj in [133, 128, 127, 129, 130, 131, 125] {
        assert!(
            spawned_objects.contains(&expected_obj),
            "UI must spawn object id {expected_obj}"
        );
    }

    // Run draw_view(0) so buttons position themselves
    s.draw_view(&bundle, 0).expect("draw view 0");

    // Find obj_leftbutton (130)
    let left_btn_id = *s.instances.iter().find(|(_, i)| i.object == 130).map(|(id, _)| id).unwrap();
    let btn_x = s.instances[&left_btn_id].fields["x"];
    let btn_y = s.instances[&left_btn_id].fields["y"];
    // In GML: x = view_xview[0] - 10 = -10, y = view_yview[0] + 190 = 190
    assert_eq!(btn_x, -10.0);
    assert_eq!(btn_y, 190.0);

    // Simulate touch on the left button (inside -10..86 and 190..254)
    s.touch_devices[0].x = 20.0;
    s.touch_devices[0].y = 210.0;
    s.touch_devices[0].down = true;
    s.touch_devices[0].pressed = true;

    // Redraw: leftbutton detects collision, sets alarm[1] = 1
    s.draw_view(&bundle, 0).expect("draw view 0 with touch");
    assert_eq!(s.instances[&left_btn_id].alarms[1], 1, "alarm[1] must be primed to 1");

    // Tick: alarm[1] expires and executes CODE 529 (Alarm 1)
    s.tick(&bundle).expect("tick alarm");

    // CODE 529 sets obj_player.hsp = -7.0
    let player_hsp = s.instances[&player_id].fields["hsp"];
    assert_eq!(player_hsp, -7.0, "player.hsp must be set to -7.0 by real CODE 529");

    // Clear left touch, simulate touch on obj_rightbutton (x=88, y=190)
    s.touch_devices[0].x = 100.0;
    s.touch_devices[0].y = 210.0;
    s.touch_devices[0].down = true;
    s.touch_devices[0].pressed = true;
    s.draw_view(&bundle, 0).expect("draw view 0 with right touch");
    let right_btn_id = *s.instances.iter().find(|(_, i)| i.object == 131).map(|(id, _)| id).unwrap();
    assert_eq!(s.instances[&right_btn_id].alarms[1], 1, "right button alarm[1] must be 1");
    s.tick(&bundle).expect("tick right alarm");
    assert_eq!(s.instances[&player_id].fields["hsp"], 7.0, "player.hsp must be set to 7.0 by real CODE 532");

    // Simulate touch on obj_jumpbutton (x=380, y=190)
    s.touch_devices[0].x = 400.0;
    s.touch_devices[0].y = 210.0;
    s.touch_devices[0].down = true;
    s.touch_devices[0].pressed = true;
    s.draw_view(&bundle, 0).expect("draw view 0 with jump touch");
    let jump_btn_id = *s.instances.iter().find(|(_, i)| i.object == 127).map(|(id, _)| id).unwrap();
    assert_eq!(s.instances[&jump_btn_id].alarms[1], 1, "jump button alarm[1] must be 1");
    s.tick(&bundle).expect("tick jump alarm");
    assert_eq!(s.instances[&player_id].fields["vsp"], -12.0, "player.vsp must be set to -12.0 by real CODE 521");
}
