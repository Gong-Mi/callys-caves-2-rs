use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

#[test]
fn original_bytecode_drives_warp_key_and_boss_boulder_lifecycle() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");

    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");

    let mut s = Scene::default();
    s.init_bundle(&bundle);

    // Populate sprite bounds from original asset
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
            },
        );
    }

    // Initialize gameplay globals via verified fresh start baseline
    s.init_fresh_start_globals();

    // 1. Test rm_town locked warp semantics (CODE 13 + CODE 803)
    let town_room = &asset.rooms[0];
    assert_eq!(town_room.name, "rm_town");
    s.load_room_from_data(&bundle, 0, town_room)
        .expect("load rm_town");

    // Find player and warp door 100005
    let player_id = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("player instance in rm_town");

    let warp_door = s.instances.get(&100005).expect("warp 100005 exists");
    let door_x = *warp_door.fields.get("x").unwrap();
    let door_y = *warp_door.fields.get("y").unwrap();
    assert_eq!(warp_door.fields.get("warproom"), Some(&23.0));
    assert_eq!(warp_door.fields.get("unlocked"), Some(&0.0), "Town warp initially locked");

    // Override haskey to 0 to test locked door behavior
    s.globals.insert("haskey".into(), 0.0);

    // Move player onto warp door with haskey == 0
    s.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), door_x);
    s.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), door_y);

    // Tick: collision event (CODE 13) runs
    s.tick(&bundle).expect("tick collision");

    // Without key, warplock is set, warp does not trigger
    assert_eq!(s.globals.get("warplock"), Some(&1.0), "CODE 13 sets warplock when key == 0");
    assert_eq!(s.target_room_warp, None, "Locked door must not warp");

    // Now give key: haskey = 1
    s.globals.insert("haskey".into(), 1.0);
    s.tick(&bundle).expect("tick collision with key");

    // Key consumed, unlocked set to 1, warp triggered to room 23!
    assert_eq!(s.globals.get("haskey"), Some(&0.0), "CODE 13 decrements haskey");
    let warp_after = s.instances.get(&100005).unwrap();
    assert_eq!(warp_after.fields.get("unlocked"), Some(&1.0), "CODE 13 unlocks door");
    assert_eq!(s.target_room_warp, Some(23), "CODE 13 calls room_goto(23)");

    let player_after = s.instances.get(&player_id).unwrap();
    assert_eq!(player_after.fields.get("x"), Some(&64.0), "CODE 13 sets warpx");
    assert_eq!(player_after.fields.get("y"), Some(&384.0), "CODE 13 sets warpy");

    println!("Verified: Town locked door correctly consumes key, sets warplock, and warps to room 23 via CODE 13!");

    // 2. Test transition_to_room and level1 unlocked warp (CODE 13 + CODE 805)
    let level1_room = &asset.rooms[1];
    assert_eq!(level1_room.name, "rm_level1");
    s.transition_to_room(&bundle, 1, level1_room)
        .expect("transition to rm_level1");

    // Player instance preserved
    let player_l1 = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("player preserved in rm_level1");
    assert_eq!(player_l1, player_id, "Player identity preserved across transition");

    // Find forward warp 100171 (CODE 805 -> warproom = 2)
    let warp_l1 = s.instances.get(&100171).expect("level1 forward warp 100171");
    let l1_door_x = *warp_l1.fields.get("x").unwrap();
    let l1_door_y = *warp_l1.fields.get("y").unwrap();
    assert_eq!(warp_l1.fields.get("warproom"), Some(&2.0));
    assert_eq!(warp_l1.fields.get("unlocked"), Some(&1.0), "Level 1 warp is pre-unlocked by CODE 805");

    // Move player onto level 1 warp door
    s.instances.get_mut(&player_l1).unwrap().fields.insert("x".into(), l1_door_x);
    s.instances.get_mut(&player_l1).unwrap().fields.insert("y".into(), l1_door_y);

    s.tick(&bundle).expect("tick level 1 warp collision");
    assert_eq!(s.target_room_warp, Some(2), "CODE 13 triggers warp to rm_level2 (room 2)");

    println!("Verified: Level 1 pre-unlocked door triggers warp to rm_level2 via CODE 13!");

    // 3. Test rm_boss1: bossboulder Alarm 0 (CODE 28 + CODE 29)
    let boss1_room = &asset.rooms[10];
    assert_eq!(boss1_room.name, "rm_boss1");
    s.transition_to_room(&bundle, 10, boss1_room)
        .expect("transition to rm_boss1");

    // Find obj_bossboulder (object 3)
    let boulder_ids: Vec<i32> = s.instances.iter()
        .filter(|(_, i)| i.object == 3 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    assert!(!boulder_ids.is_empty(), "rm_boss1 must contain obj_bossboulder instances");

    // Verify initial alarm[0] was set by CODE 28 Create
    for &bid in &boulder_ids {
        assert_eq!(s.instances[&bid].alarms[0], 30, "CODE 28 sets alarm[0] = 30");
    }

    // With boss1dead == 0, advance 30 ticks
    s.globals.insert("boss1dead".into(), 0.0);
    for _ in 0..30 {
        s.tick(&bundle).expect("tick boss1 arena");
    }
    // Boulder is still alive and alarm was re-scheduled to 30
    for &bid in &boulder_ids {
        let b = s.instances.get(&bid).expect("boulder still exists");
        assert!(b.alive, "boulder must stay alive while boss1dead == 0");
        assert_eq!(b.alarms[0], 30, "CODE 29 re-arms alarm[0] = 30");
    }

    // Now set boss1dead = 1 (simulating Boss defeat)
    s.globals.insert("boss1dead".into(), 1.0);
    for _ in 0..30 {
        s.tick(&bundle).expect("tick boss1 arena post-defeat");
    }

    // All bossboulders destroyed by CODE 29 calling instance_destroy()!
    for &bid in &boulder_ids {
        let b = s.instances.get(&bid).unwrap();
        assert!(!b.alive, "CODE 29 must destroy obj_bossboulder when boss1dead == 1");
    }

    println!("Verified: rm_boss1 obj_bossboulder lifecycle driven by CODE 28/29 alarms and destroyed on boss defeat!");
}
