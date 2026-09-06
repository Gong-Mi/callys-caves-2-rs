use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

#[test]
fn data_driven_room_loader_town_and_level1_from_original_asset() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");

    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");

    let mut s = Scene::default();
    s.init_bundle(&bundle);

    // Populate sprite bounds for objects in rm_town from asset.sprites
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

    // Set progression globals required by objects in town
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("maxhp".into(), 4.0);
    s.globals.insert("health1".into(), 4.0);
    s.globals.insert("experience".into(), 0.0);
    s.globals.insert("xptolevelup".into(), 30.0);
    s.globals.insert("roomstart".into(), 0.0);
    s.globals.insert("soundmute".into(), 0.0);
    s.globals.insert("musicmute".into(), 0.0);
    s.globals.insert("haskey".into(), 0.0);
    s.globals.insert("warplock".into(), 0.0);
    s.globals.insert("pistol".into(), 1.0);
    s.globals.insert("assaultrifle".into(), 0.0);
    s.globals.insert("shotgun".into(), 0.0);
    s.globals.insert("tjumpactive".into(), 0.0);
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
    for wb in [
        "shotgunbought", "assaultriflebought", "rocketbought", "laserbought", "icegunbought",
        "bladegunbought", "flamethrowerbought", "bowbought", "bombgunbought", "boomerangbought",
        "spikegunbought", "triplejumpbought", "coinmultiplier2bought", "coinmultiplier5bought",
        "maxhpupgradebought", "maxhpupgrade2bought",
    ] {
        s.globals.insert(wb.into(), 0.0);
    }

    // 1. Data-driven load of room 0 (rm_town)
    let town_room = &asset.rooms[0];
    assert_eq!(town_room.name, "rm_town");
    s.load_room_from_data(&bundle, 0, town_room)
        .expect("load rm_town from data");

    // Verify room dimensions and tiles loaded directly from data
    assert_eq!(s.room_width, town_room.width as f64);
    assert_eq!(s.room_height, town_room.height as f64);
    assert_eq!(s.room_tiles.len(), town_room.tiles.len());

    // Verify all 170 instances in rm_town were created via their real Create events,
    // plus exactly 7 dynamic button instances created by obj_UI Create (CODE 365).
    assert_eq!(s.instances.len(), town_room.objects.len() + 7);

    // Verify creation code binding ran: obj_warpanywhere (object 69, instance 100005)
    // runs CODE 803 which sets warproom = 23 (rm_level1), warpx = 64, warpy = 384
    let warp_inst = s.instances.get(&100005).expect("warp instance 100005 exists");
    assert_eq!(warp_inst.fields.get("warproom"), Some(&23.0), "Creation code 803 set warproom");
    assert_eq!(warp_inst.fields.get("warpx"), Some(&64.0), "Creation code 803 set warpx");
    assert_eq!(warp_inst.fields.get("warpy"), Some(&384.0), "Creation code 803 set warpy");

    println!("Data-driven rm_town loaded successfully with {} instances and {} tiles!", s.instances.len(), s.room_tiles.len());

    // 2. Data-driven load of room 1 (rm_level1: 1341 instances, 114 tiles)
    let level1_room = &asset.rooms[1];
    assert_eq!(level1_room.name, "rm_level1");
    let mut s1 = Scene::default();
    s1.init_bundle(&bundle);
    s1.sprite_bounds = s.sprite_bounds.clone();
    s1.globals = s.globals.clone();
    s1.load_room_from_data(&bundle, 1, level1_room)
        .expect("load rm_level1 from data");

    assert_eq!(s1.room_width, level1_room.width as f64);
    assert_eq!(s1.room_height, level1_room.height as f64);
    assert_eq!(s1.room_tiles.len(), 114, "rm_level1 must have 114 tiles preserved from data");
    assert!(s1.instances.len() >= level1_room.objects.len(), "rm_level1 instances materialized");

    // Verify level1 warps:
    // CODE 805 links forward to rm_level2 (room 2)
    // CODE 806 links back to rm_town (room 0)
    let warp_fwd = s1.instances.get(&100171).expect("forward warp instance 100171");
    assert_eq!(warp_fwd.fields.get("warproom"), Some(&2.0), "CODE 805 links rm_level1 to rm_level2");
    assert_eq!(warp_fwd.fields.get("warpx"), Some(&128.0));
    assert_eq!(warp_fwd.fields.get("warpy"), Some(&492.0));

    let warp_back = s1.instances.get(&100172).expect("backward warp instance 100172");
    assert_eq!(warp_back.fields.get("warproom"), Some(&0.0), "CODE 806 links rm_level1 back to rm_town");

    println!("Data-driven rm_level1 loaded successfully with {} instances and {} tiles!", s1.instances.len(), s1.room_tiles.len());

    // 3. Data-driven load of room 10 (rm_boss1: 454 instances, boss1 arena)
    let boss1_room = &asset.rooms[10];
    assert_eq!(boss1_room.name, "rm_boss1");
    let mut s_boss = Scene::default();
    s_boss.init_bundle(&bundle);
    s_boss.sprite_bounds = s.sprite_bounds.clone();
    s_boss.globals = s.globals.clone();
    s_boss.load_room_from_data(&bundle, 10, boss1_room)
        .expect("load rm_boss1 from data");

    // Verify rm_boss1 dimensions, tiles, and instances
    assert_eq!(s_boss.room_width, boss1_room.width as f64);
    assert_eq!(s_boss.room_height, boss1_room.height as f64);
    assert_eq!(s_boss.room_tiles.len(), boss1_room.tiles.len());
    assert!(s_boss.instances.len() >= boss1_room.objects.len());

    // Verify obj_trex (object 25) exists in rm_boss1
    let has_trex = s_boss.instances.values().any(|i| i.object == 25);
    assert!(has_trex, "obj_trex must be materialized in rm_boss1 directly from room data");

    // Verify obj_bossboulder (object 3) exists in rm_boss1
    let has_boulder = s_boss.instances.values().any(|i| i.object == 3);
    assert!(has_boulder, "obj_bossboulder must be materialized in rm_boss1 directly from room data");

    println!("Data-driven rm_boss1 loaded successfully with {} instances, obj_trex and obj_bossboulder verified!", s_boss.instances.len());
}
