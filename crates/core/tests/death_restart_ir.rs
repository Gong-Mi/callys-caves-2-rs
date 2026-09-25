use callys_asset::GameDroidAsset;
use callys_core::{code_vm::load_bundle_from_file, ir_scene::Scene};
use std::path::Path;

#[test]
fn original_death_events_lock_then_request_same_room_restart() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    let death_object = bundle.objects.iter().find(|o| o.name == "obj_youhavedied").unwrap().id;
    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();
    scene.load_room_from_data(&bundle, 0, &asset.rooms[0]).unwrap();
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();
    let player = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;
    let died_before = scene.globals.get("playerdied").copied().unwrap_or(0.0);
    scene.globals.insert("health1".into(), 1.0);
    scene.tick(&bundle).unwrap();
    let death = *scene.instances.iter().find(|(_, i)| i.object == death_object && i.alive).expect("player Step creates death controller").0;
    assert_eq!(scene.globals["playerdied"], died_before + 1.0);
    assert!(!scene.instances[&player].active);
    assert_eq!(scene.instances[&death].fields["taplock"], 0.0);
    assert_eq!(scene.instances[&death].alarms[0], 70);
    assert_eq!(scene.instances[&player].fields["x"], scene.globals["startx"]);
    assert_eq!(scene.instances[&player].fields["y"], scene.globals["starty"]);
    // This core contract explicitly invokes the original local LeftReleased
    // callback; platform release routing is a separate consumer gate.
    scene.dispatch(&bundle, death, 6, 7).unwrap();
    assert!(scene.instances[&death].alive, "early release must be locked");
    for _ in 0..69 { scene.tick(&bundle).unwrap(); }
    assert_eq!(scene.instances[&death].fields["taplock"], 0.0);
    scene.tick(&bundle).unwrap();
    assert_eq!(scene.instances[&death].fields["taplock"], 1.0);
    let deduction = scene.instances[&death].fields["coindeduct"];
    assert!((30.0..=99.0).contains(&deduction));
    scene.dispatch(&bundle, death, 6, 7).unwrap();
    assert!(!scene.instances[&death].alive);
    assert!(scene.instances[&player].active);
    assert_eq!(scene.globals["health1"], 4.0);
    assert_eq!(scene.globals["warpfrommap"], 1.0);
    assert_eq!(scene.target_room_warp, Some(1), "room_restart must request current room");
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();
    assert!(scene.instances[&player].alive && scene.instances[&player].active);
    assert_eq!(scene.current_room, 1.0);
    assert!(!scene.instances.values().any(|i| i.alive && i.object == death_object));
    for frame in 0..15 {
        scene.tick(&bundle).unwrap_or_else(|e| panic!("respawn frame {frame}: {e}"));
    }
}
