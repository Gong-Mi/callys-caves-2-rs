use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn player_picks_gem_with_100_score_multiplier_and_sound() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();
    // In rm_town, gem 100045 is at (480, 64) and gem 100044 is at (544, 64)
    let gem_id = 100045;
    let other_gem_id = 100044;
    assert!(scene.instances.contains_key(&gem_id), "gem 100045 exists in rm_town");
    assert!(scene.instances.contains_key(&other_gem_id), "gem 100044 exists in rm_town");

    let gem = &scene.instances[&gem_id];
    assert_eq!(gem.object, 59, "gem is object 59");
    assert_eq!(gem.fields.get("type").copied(), Some(2.0), "gem type is 2");

    let gem_x = gem.fields["x"];
    let gem_y = gem.fields["y"];
    let player_id = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;

    // Park player on gem 100045
    scene.instances.get_mut(&player_id).unwrap().fields.insert("x".into(), gem_x);
    scene.instances.get_mut(&player_id).unwrap().fields.insert("y".into(), gem_y);

    let score_before = scene.score;
    let pickup_before = scene.globals["coinpickup"];
    let coinmult = scene.globals["coinmultiply"];

    // Run 1 tick of real player Step CODE 12
    scene.tick(bundle.as_ref()).unwrap();

    let scene = state.scene.as_ref().unwrap();
    assert!(!scene.instances[&gem_id].alive, "gem must be destroyed on pickup");
    assert!(scene.instances[&other_gem_id].alive, "distant gem must remain alive");
    assert_eq!(scene.score, score_before + 100.0 * coinmult, "gem adds 100 * coinmultiply to score");
    assert_eq!(scene.globals["coinpickup"], pickup_before + 100.0 * coinmult, "gem adds 100 * coinmultiply to coinpickup");
    assert!(scene.audio.iter().any(|c| c.sound == scene.globals["coinsound"] as i32 && !c.looping), "Destroy plays coinsound");
}

#[test]
fn gem_physics_integrates_gravity_and_settles_on_par_wall() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();
    // In rm_town, player is at x=416, y=494. Floor wall is at y=512.
    // Spawn gem at x=550, y=400 (distance to player = 134 < 400, so obj_bg does not cull;
    // dx = 134 > 32 so player does not pick it up prematurely).
    let spawned_id = scene.create(&bundle, 59, 550.0, 400.0).expect("create gem");
    let gem = &scene.instances[&spawned_id];
    assert_eq!(gem.fields.get("yorigin").copied(), Some(400.0), "yorigin initialized to spawn y");
    assert_eq!(gem.fields.get("friction").copied(), Some(0.3), "gem friction initialized to 0.3");

    // Tick 5 frames: gravity (0.6) accelerates vspeed downward
    let mut prev_y = 400.0;
    for _ in 0..5 {
        scene.tick(bundle.as_ref()).unwrap();
        let curr_y = scene.instances[&spawned_id].fields["y"];
        assert!(curr_y > prev_y, "gem must fall downward: {prev_y} -> {curr_y}");
        prev_y = curr_y;
    }

    // Step until the gem falls and settles on par_wall at y=497.5 (takes ~25 frames total)
    for _ in 0..30 {
        scene.tick(bundle.as_ref()).unwrap();
    }

    let settled = &scene.instances[&spawned_id];
    assert_eq!(settled.fields.get("gravity").copied(), Some(0.0), "gravity must zero out when resting on wall");
    assert_eq!(settled.fields.get("vspeed").copied(), Some(0.0), "vspeed must zero out when resting on wall");
    assert!(settled.fields["y"] > 450.0, "gem settled below initial yorigin");

    // Once settled, further ticks keep it stationary
    let settled_y = settled.fields["y"];
    for _ in 0..10 {
        scene.tick(bundle.as_ref()).unwrap();
    }
    assert_eq!(scene.instances[&spawned_id].fields["y"], settled_y, "gem remains stationary once settled");
}

#[test]
fn falling_gem_into_standing_player_is_picked_up_dynamically() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();
    let score_before = scene.score;
    let coinmult = scene.globals["coinmultiply"];

    // Spawn gem at x=416, y=450 directly above standing player at (416, 494)
    let spawned_id = scene.create(&bundle, 59, 416.0, 450.0).expect("create falling gem");

    // As it falls, on frame 10 it intersects the player's bounding box and is picked up
    for _ in 0..15 {
        scene.tick(bundle.as_ref()).unwrap();
    }

    assert!(!scene.instances[&spawned_id].alive, "falling gem destroyed upon intersecting player");
    assert_eq!(scene.score, score_before + 100.0 * coinmult, "score increased by 100*coinmultiply from falling gem");
}
