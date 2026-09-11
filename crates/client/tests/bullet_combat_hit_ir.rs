use callys_asset::GameDroidAsset;
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn player_bullet_spawn_travel_and_enemy_damage_and_xp_gain() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&manifest_dir.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();

    // 1. Enter rm_level1 (room 1)
    scene.target_room_warp = Some(1);
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();

    let player_id = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;
    let bandit_id = *scene.instances.iter().find(|(_, i)| i.object == 15 && i.alive).unwrap().0;

    let initial_hp = scene.instances[&bandit_id].fields.get("hpknife").copied().unwrap_or(0.0);
    assert_eq!(initial_hp, 15.0, "bandit initial hpknife is 15.0");
    assert_eq!(scene.globals["pistolxp"], 0.0, "initial pistolxp is 0");
    assert_eq!(scene.globals["pistoldamage"], 1.0, "initial pistoldamage is 1.0");

    // 2. Park player facing right toward knifebandit at x=1600
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), 1500.0);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), 584.0);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("facing".into(), 0.0);

    // 3. Trigger player firing: Alarm 0 (CODE 11)
    scene.dispatch(&bundle, player_id, 2, 0).unwrap();

    // Verify bullet (object 39) materialized
    let bullet_id = *scene
        .instances
        .iter()
        .find(|(&id, i)| id >= 200000 && i.object == 39 && i.alive)
        .map(|(id, _)| id)
        .expect("bullet 39 spawned on player Alarm 0");

    let bullet = &scene.instances[&bullet_id];
    assert_eq!(bullet.fields.get("hspeed").copied(), Some(25.0), "bullet hspeed is 25 px/frame");
    assert_eq!(bullet.fields["x"], 1510.0, "bullet spawned at player x + 10");

    // Verify firing sound emitted (snd_fire = 10)
    assert!(
        scene.audio.iter().any(|c| c.sound == 10 && !c.looping),
        "snd_fire emitted on shot"
    );

    // 4. Tick frames to advance bullet motion across space
    let mut prev_bx = 1510.0;
    for _ in 0..3 {
        scene.tick(&bundle).unwrap();
        let curr_bx = scene.instances[&bullet_id].fields["x"];
        assert_eq!(curr_bx, prev_bx + 25.0, "bullet advances 25 px per frame");
        prev_bx = curr_bx;
    }

    // Frame 4: bullet reaches bandit at x=1600 and hits
    scene.tick(&bundle).unwrap();

    // Verify bullet destroyed on impact
    assert!(!scene.instances[&bullet_id].alive, "bullet destroyed upon hitting enemy");

    // Verify enemy received damage, flashing, and stun
    let bandit = &scene.instances[&bandit_id];
    assert_eq!(
        bandit.fields.get("hpknife").copied(),
        Some(14.0),
        "bandit hpknife reduced by pistoldamage (15.0 -> 14.0)"
    );
    assert_eq!(bandit.fields.get("flashing").copied(), Some(1.0), "bandit flashing set to 1");
    assert_eq!(bandit.fields.get("stunned").copied(), Some(1.0), "bandit stunned set to 1");
    assert_eq!(bandit.alarms[4], 10, "bandit stun alarm[4] set to 10 ticks");

    // Verify weapon experience incremented
    assert_eq!(scene.globals["pistolxp"], 1.0, "pistolxp incremented to 1 upon hit");

    // Verify impact sound emitted (snd_impactsound2 = 23)
    assert!(
        scene.audio.iter().any(|c| c.sound == 23 && !c.looping),
        "snd_impactsound2 emitted on bullet hit"
    );
}

#[test]
fn bullet_colliding_with_par_wall_is_destroyed_and_spawns_spark() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&manifest_dir.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();
    scene.target_room_warp = Some(1);
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();

    let player_id = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;

    // Park player directly facing a wall at x=100 (facing 1 = left)
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), 40.0);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), 584.0);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("facing".into(), 1.0);

    // Fire bullet to the left (hspeed = -25)
    scene.dispatch(&bundle, player_id, 2, 0).unwrap();

    let bullet_id = *scene
        .instances
        .iter()
        .find(|(&id, i)| id >= 200000 && i.object == 39 && i.alive)
        .map(|(id, _)| id)
        .expect("bullet spawned facing left");

    assert_eq!(scene.instances[&bullet_id].fields.get("hspeed").copied(), Some(-25.0));

    // Tick: bullet travels left directly into wall at x=0..32
    scene.tick(&bundle).unwrap();

    assert!(!scene.instances[&bullet_id].alive, "bullet destroyed upon hitting par_wall");

    // Verify obj_bulletspark (object 13) spawned
    assert!(
        scene.instances.values().any(|i| i.object == 13 && i.alive),
        "obj_bulletspark spawned on wall impact"
    );
}
