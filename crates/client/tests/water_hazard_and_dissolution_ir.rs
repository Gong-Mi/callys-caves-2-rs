use callys_asset::GameDroidAsset;
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn water_hazard_dissolves_loot_and_triggers_player_death_controller() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&manifest_dir.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();

    // 1. Enter rm_level1 (has 21 obj_watersurface records)
    scene.target_room_warp = Some(1);
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();

    // Verify water surface at (1600, 704)
    let water_inst = scene
        .instances
        .values()
        .find(|i| i.object == 9 && i.alive && (i.fields.get("x").copied().unwrap_or(0.0) - 1600.0).abs() < 32.0)
        .expect("water surface near 1600, 704");
    let wx = water_inst.fields["x"];
    let wy = water_inst.fields["y"];

    // 2. Test loot dissolution: obj_gem (59) and obj_silvercoin (60)
    let gem_id = scene.create(&bundle, 59, wx, wy).expect("create gem at water");
    let coin_id = scene.create(&bundle, 60, wx, wy).expect("create silvercoin at water");

    assert!(scene.instances[&gem_id].alive);
    assert!(scene.instances[&coin_id].alive);

    // 1 tick: Step CODE 343 & 346 detect instance_place(x, y, obj_watersurface) and destroy
    scene.tick(&bundle).unwrap();

    assert!(!scene.instances[&gem_id].alive, "gem destroyed upon contacting water surface");
    assert!(!scene.instances[&coin_id].alive, "silver coin destroyed upon contacting water surface");

    // 3. Test player water hazard death: place player on water surface
    let player_id = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), wx);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), wy);

    assert_eq!(scene.globals.get("health1").copied(), Some(4.0), "initial health is 4.0");
    assert_eq!(scene.globals.get("playerdied").copied(), Some(0.0), "initial playerdied is 0.0");

    // Tick 1: Step CODE 12 detects distance_to_object(obj_watersurface) <= 1 and sets health1 = 1
    scene.tick(&bundle).unwrap();
    assert_eq!(scene.globals.get("health1").copied(), Some(1.0), "water contact sets health1 = 1");

    // Tick 2: Step CODE 12 detects health1 == 1, spawns obj_youhavedied, plays sound, increments playerdied
    scene.tick(&bundle).unwrap();
    assert_eq!(scene.globals.get("playerdied").copied(), Some(1.0), "global.playerdied incremented to 1");

    // Verify obj_youhavedied (134) materialized
    assert!(
        scene.instances.values().any(|i| i.object == 134 && i.alive),
        "obj_youhavedied controller instantiated on water death"
    );

    // Verify death sound emitted (snd_youhavedied = audio ID 26)
    let snd_youhavedied_id = 26;
    assert!(
        scene.audio.iter().any(|c| c.sound == snd_youhavedied_id && !c.looping),
        "snd_youhavedied emitted upon water hazard death"
    );
}
