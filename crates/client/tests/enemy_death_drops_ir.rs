use callys_asset::GameDroidAsset;
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn knifebandit_death_spawns_drops_and_player_collects_gem_coins_and_xp() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&manifest_dir.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();

    // 1. Warp town -> rm_level1 (room 1)
    scene.target_room_warp = Some(1);
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();

    // 2. Find knifebandit (object 15) in rm_level1
    let bandit_id = *scene
        .instances
        .iter()
        .find(|(_, i)| i.object == 15 && i.alive)
        .map(|(id, _)| id)
        .expect("knifebandit in rm_level1");

    let _bx = scene.instances[&bandit_id].fields["x"];
    let _by = scene.instances[&bandit_id].fields["y"];
    assert!(scene.instances[&bandit_id].fields.get("hpknife").copied().unwrap_or(0.0) > 0.0);

    // 3. Apply lethal damage: hpknife = 0
    scene.instances.get_mut(&bandit_id).unwrap().fields.insert("hpknife".into(), 0.0);

    // Frame 1: Step CODE 56 detects hpknife <= 0 and sets alarm[0] = 1
    scene.tick(&bundle).unwrap();
    assert_eq!(scene.instances[&bandit_id].alarms[0], 1, "alarm[0] primed to 1 on fatal hpknife");

    // Frame 2: Alarm 0 (CODE 55) fires: spawns drops and kills bandit
    scene.tick(&bundle).unwrap();
    assert!(!scene.instances[&bandit_id].alive, "bandit destroyed by action_kill_object");

    // Verify explosion sound emitted (snd_explode = sound ID 7)
    let snd_explode_id = 7;
    assert!(
        scene.audio.iter().any(|c| c.sound == snd_explode_id && !c.looping),
        "snd_explode emitted upon bandit death"
    );

    // 4. Verify spawned drops from CODE 55
    let spawned_gems: Vec<i32> = scene
        .instances
        .iter()
        .filter(|(&id, i)| id >= 200000 && i.object == 59 && i.alive)
        .map(|(&id, _)| id)
        .collect();
    let spawned_xporbs: Vec<i32> = scene
        .instances
        .iter()
        .filter(|(&id, i)| id >= 200000 && i.object == 61 && i.alive)
        .map(|(&id, _)| id)
        .collect();
    let spawned_silvercoins: Vec<i32> = scene
        .instances
        .iter()
        .filter(|(&id, i)| id >= 200000 && i.object == 60 && i.alive)
        .map(|(&id, _)| id)
        .collect();

    assert_eq!(spawned_gems.len(), 1, "global.gemdropenabled == 1 spawns exactly 1 gem");
    assert_eq!(spawned_xporbs.len(), 1, "xpdrop == 1 spawns exactly 1 XPorb");
    assert!(!spawned_silvercoins.is_empty(), "coindrop spawns silver coins");

    let dropped_gem_id = spawned_gems[0];
    let dropped_xp_id = spawned_xporbs[0];
    let gem_x = scene.instances[&dropped_gem_id].fields["x"];
    let gem_y = scene.instances[&dropped_gem_id].fields["y"];
    let xp_x = scene.instances[&dropped_xp_id].fields["x"];
    let xp_y = scene.instances[&dropped_xp_id].fields["y"];

    // 5. Player collects the dropped gem and silver coins
    let player_id = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), gem_x);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), gem_y);

    let score_before = scene.score;
    let coinmult = scene.globals["coinmultiply"];

    // Tick: player Step CODE 12 and Collision 60 collect gem and coins
    scene.tick(&bundle).unwrap();

    assert!(!scene.instances[&dropped_gem_id].alive, "dropped gem collected and destroyed");
    assert!(
        scene.score >= score_before + 100.0 * coinmult,
        "score increased by at least 100*coinmultiply from gem: before={score_before}, after={}",
        scene.score
    );

    // 6. Player collects the dropped XPorb
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), xp_x);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), xp_y);

    let xp_before = scene.globals["experience"];
    scene.tick(&bundle).unwrap();

    assert!(!scene.instances[&dropped_xp_id].alive, "XPorb collected and destroyed");
    assert_eq!(scene.globals["experience"], xp_before + 1.0, "global.experience incremented by 1");
}
