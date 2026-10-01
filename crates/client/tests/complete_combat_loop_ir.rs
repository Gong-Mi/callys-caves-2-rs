use callys_asset::GameDroidAsset;
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn complete_combat_loop_shoot_kill_loot_and_weapon_upgrade() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&manifest_dir.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();

    // 1. Enter rm_level1
    scene.target_room_warp = Some(1);
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();

    let player_id = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;
    let bandit_id = *scene.instances.iter().find(|(_, i)| i.object == 15 && i.alive).unwrap().0;

    // Set bandit close to death (hpknife = 1.0) and pistolxp close to levelup (45.0 out of 46.0)
    scene.instances.get_mut(&bandit_id).unwrap().fields.insert("hpknife".into(), 1.0);
    scene.globals.insert("pistolxp".into(), 45.0);
    let score_initial = scene.score;

    // Position player facing knifebandit
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), 1500.0);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), 584.0);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("facing".into(), 0.0);

    // 2. Fire pistol shot (player Alarm 0)
    scene.dispatch(&bundle, player_id, 2, 0).unwrap();

    let bullet_id = *scene
        .instances
        .iter()
        .find(|(&id, i)| id >= 200000 && i.object == 39 && i.alive)
        .map(|(id, _)| id)
        .expect("bullet spawned");

    // 3. Tick 4 frames: bullet travels 100px and deals fatal hit to bandit
    for _ in 0..4 {
        scene.tick(&bundle).unwrap();
    }

    assert!(!scene.instances[&bullet_id].alive, "bullet consumed on hit");
    assert_eq!(
        scene.instances[&bandit_id].fields.get("hpknife").copied(),
        Some(0.0),
        "bandit reduced to 0 hp"
    );
    assert_eq!(scene.globals["pistolxp"], 46.0, "pistolxp incremented to 46.0 (meets level-up threshold)");

    // 4. Tick 1 frame: bandit Step detects hpknife <= 0 and sets alarm[0] = 1
    scene.tick(&bundle).unwrap();

    // 5. Tick 1 frame: bandit Alarm 0 fires, spawning drops and destroying bandit
    scene.tick(&bundle).unwrap();
    assert!(!scene.instances[&bandit_id].alive, "bandit destroyed");

    // Find dropped gem
    let dropped_gem_id = *scene
        .instances
        .iter()
        .find(|(&id, i)| id >= 200000 && i.object == 59 && i.alive)
        .map(|(id, _)| id)
        .expect("dropped gem");
    let gx = scene.instances[&dropped_gem_id].fields["x"];
    let gy = scene.instances[&dropped_gem_id].fields["y"];

    // 6. Move player to dropped loot position and collect
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), gx);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), gy);
    scene.tick(&bundle).unwrap();

    assert!(!scene.instances[&dropped_gem_id].alive, "gem collected");
    let coinmult = scene.globals["coinmultiply"];
    assert!(scene.score >= score_initial + 100.0 * coinmult, "score increased from collected loot");

    // 7. Step 30 frames for obj_UI Alarm 0 to evaluate weapon level-up
    for _ in 0..30 {
        state.step(1.0 / 60.0);
    }

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.globals.get("pistollevel").copied(), Some(2.0), "pistol leveled up to level 2!");
    assert_eq!(scene.globals.get("pistolxp").copied(), Some(1.0), "pistolxp reset to 1");
    assert_eq!(scene.globals.get("pistolxptolevelup").copied(), Some(69.0), "pistolxptolevelup scaled to 69.0");
}
