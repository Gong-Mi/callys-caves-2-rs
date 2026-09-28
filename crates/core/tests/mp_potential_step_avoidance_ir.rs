use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const PLAYER: i32 = 0;
const GHOST: i32 = 24;
const WALL: i32 = 4;

#[test]
fn mp_potential_step_avoids_solid_wall_obstacle() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir.json"));

    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();
    scene.globals.insert("level".into(), 5.0);
    scene.globals.insert("pwr".into(), 1.0);

    // Player at (500, 200)
    let _player = scene.create(&bundle, PLAYER, 500.0, 200.0).expect("create player");
    // Ghost at (300, 200)
    let ghost = scene.create(&bundle, GHOST, 300.0, 200.0).expect("create ghost");

    // Place a solid wall at (333, 200).
    // Ghost is at (300, 200) with 32x32 bounding box [300..332, 200..232].
    // At x=333, initial distance is 1px (no initial overlap):
    // A forward step (+3px) puts ghost at [303..335, 200..232],
    // colliding with the wall [333..365, 200..232].
    // Obstacle avoidance must steer the ghost away from 0 degrees (e.g. 90 or 270 deg).
    let _wall = scene.create(&bundle, WALL, 333.0, 200.0).expect("create wall");

    let initial_gy = scene.instances[&ghost].fields["y"];

    // Step the ghost (CODE 152 calls mp_potential_step(player.x, player.y, 3, 0))
    scene.dispatch(&bundle, ghost, 3, 0).expect("ghost step");

    let cur_gy = scene.instances[&ghost].fields["y"];
    let dir = scene.instances[&ghost].fields["direction"];

    // In direct horizontal line (no obstacle), dir would be 0.0 and gy would remain 200.0.
    // With obstacle avoidance, the ghost must steer at an angle around the wall:
    assert!(
        (cur_gy - initial_gy).abs() > 0.01,
        "ghost must steer vertically around the blocking wall, got y={cur_gy} vs initial={initial_gy}"
    );
    assert_ne!(
        dir, 0.0,
        "ghost direction must not be a direct straight line into the wall, got dir={dir}"
    );
}
