//! H-line slice: drive the real rm_level1 for 30 frames and require the
//! original obj_knifebandit Step (CODE 56) to execute end-to-end — every
//! tick must return Ok (the Android client currently swallows tick errors
//! with `let _ =`), and the enemy must show observable AI behavior
//! (movement, wall-turn, or alarm writes), not just sit inert.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;

fn fixture() -> (callys_core::code_vm::Bundle, Scene, i32) {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();

    // Enter rm_level1 through rm_town so the persistent obj_player carries
    // over exactly like the original warp flow (CODE 13 room_goto keeps
    // persistent instances across transition_to_room).
    let town = &asset.rooms[0];
    assert_eq!(town.name, "rm_town");
    s.load_room_from_data(&bundle, 0, town)
        .expect("load rm_town");
    assert!(
        s.instances.values().any(|i| i.object == 0 && i.alive),
        "rm_town must materialize the player"
    );
    let level1 = &asset.rooms[1];
    assert_eq!(level1.name, "rm_level1");
    s.transition_to_room(&bundle, 1, level1)
        .expect("warp town -> rm_level1");

    let bandit = s.instances.iter()
        .find(|(_, i)| i.object == 15 && i.alive)
        .map(|(id, _)| *id)
        .expect("obj_knifebandit materialized in rm_level1");
    (bundle, s, bandit)
}

#[test]
fn knifebandit_step_executes_cleanly_for_30_frames() {
    let (bundle, mut s, bandit) = fixture();

    let x0 = s.instances[&bandit].fields.get("x").copied().unwrap_or(0.0);
    let facing0 = s.instances[&bandit].fields.get("facing").copied().unwrap_or(0.0);
    let alarms0 = s.instances[&bandit].alarms;

    let mut positions = vec![x0];
    for frame in 0..30 {
        s.tick(&bundle)
            .unwrap_or_else(|e| panic!("tick {frame} must not error (client swallows these today): {e}"));
        positions.push(s.instances[&bandit].fields.get("x").copied().unwrap_or(0.0));
    }

    let facing1 = s.instances[&bandit].fields.get("facing").copied().unwrap_or(0.0);
    let alarms1 = s.instances[&bandit].alarms;
    let moved = positions.iter().any(|&x| (x - x0).abs() > 0.01);
    let turned = facing1 != facing0;
    let alarm_touched = alarms0 != alarms1;
    assert!(
        moved || turned || alarm_touched,
        "knifebandit must show observable AI behavior: moved={moved} turned={turned} alarm_touched={alarm_touched}"
    );
}

#[test]
fn level1_full_cast_steps_without_dispatch_errors() {
    let (bundle, mut s, _) = fixture();
    for frame in 0..60 {
        s.tick(&bundle)
            .unwrap_or_else(|e| panic!("tick {frame}: {e}"));
    }
}
