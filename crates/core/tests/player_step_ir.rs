use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

#[test]
fn player_step_real_code_12_gravity_motion_and_wall_collision() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.current_room = 0.0; // rm_town

    // Register bounds for player (spr_player: 32x34, origin 15,16) and wall (32x32)
    s.sprite_bounds.insert(29, SpriteBounds { width: 32.0, height: 34.0, origin_x: 15.0, origin_y: 16.0 });
    s.sprite_bounds.insert(5, SpriteBounds { width: 32.0, height: 32.0, origin_x: 0.0, origin_y: 0.0 });

    // Populate ground walls (obj_wall: id 4, parent 34 / par_wall) at y=200
    for i in 0..10 {
        let wall_id = s.create(&bundle, 4, (i * 32) as f64, 200.0).expect("create obj_wall");
        // obj_wall Create sets type = 1
        s.instances.get_mut(&wall_id).unwrap().fields.insert("type".into(), 1.0);
    }

    // Create player (obj_player: id 0)
    let player_id = s.create(&bundle, 0, 96.0, 100.0).expect("create obj_player");
    assert_eq!(s.instances[&player_id].fields["y"], 100.0);

    // Set player progression globals
    s.globals.insert("maxhp".into(), 4.0);
    s.globals.insert("health1".into(), 4.0);
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("experience".into(), 0.0);
    s.globals.insert("coinmultiply".into(), 1.0);
    s.globals.insert("coinpickup".into(), 0.0);
    s.globals.insert("playerdied".into(), 0.0);
    s.globals.insert("rebuff".into(), 0.0);
    s.globals.insert("roomstart".into(), 0.0);
    s.globals.insert("soundmute".into(), 0.0);
    s.globals.insert("swing".into(), 1.0);
    s.globals.insert("swordupgradebought".into(), 0.0);
    s.globals.insert("swordupgrade2bought".into(), 0.0);
    s.globals.insert("swordupgrade3bought".into(), 0.0);

    // Initial state before Step
    s.instances.get_mut(&player_id).unwrap().fields.insert("grav".into(), 1.0);
    s.instances.get_mut(&player_id).unwrap().fields.insert("grounded".into(), 0.0);
    s.instances.get_mut(&player_id).unwrap().fields.insert("hsp".into(), 0.0);
    s.instances.get_mut(&player_id).unwrap().fields.insert("vsp".into(), 0.0);

    // Dispatch Step (event_type=3, subtype=0) -> executes real CODE 12
    s.dispatch(&bundle, player_id, 3, 0).expect("dispatch player Step");

    // Gravity applied: vsp becomes 1.0, y moves to 101.0
    let vsp = s.instances[&player_id].fields["vsp"];
    let y = s.instances[&player_id].fields["y"];
    assert_eq!(vsp, 1.0, "gravity must increase vsp by 1");
    assert_eq!(y, 101.0, "y must advance by vsp");

    // Give horizontal speed hsp = 7.0 and step again
    s.instances.get_mut(&player_id).unwrap().fields.insert("hsp".into(), 7.0);
    s.dispatch(&bundle, player_id, 3, 0).expect("dispatch player Step with hsp");
    let x = s.instances[&player_id].fields["x"];
    assert_eq!(x, 103.0, "x must advance by hsp (96 + 7)");

    // Step repeatedly until landing on ground wall (y=200, player height=34, origin=16 -> land y around 183)
    for _ in 0..20 {
        s.dispatch(&bundle, player_id, 3, 0).expect("dispatch player Step falling");
        if s.instances[&player_id].fields["grounded"] == 1.0 {
            break;
        }
    }
    assert_eq!(s.instances[&player_id].fields["grounded"], 1.0, "player must land on par_wall");
    assert_eq!(s.instances[&player_id].fields["vsp"], 0.0, "vertical speed must reset to 0 upon landing");
}
