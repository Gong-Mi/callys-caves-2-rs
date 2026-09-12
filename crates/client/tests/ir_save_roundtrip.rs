//! Bidirectional IR-path save regression: snapshot -> cold GameState -> same
//! room/progress -> continue playing. Also proves v1/v2 upgrade paths and
//! future-version rejection stay intact after the scene_globals/score fields.
use callys_asset::GameDroidAsset;
use callys_client::{load_save, save_path_for_asset, write_save_atomic, GameState};
use callys_core::save::{SaveData, CURRENT_SAVE_VERSION};
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn ir_progress_survives_snapshot_cold_restart_and_continues() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());

    // Session 1: town -> level1, collect a coin, buy nothing, then snapshot.
    let mut first = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    first.enable_ir_gameplay(bundle.clone()).unwrap();
    let level1 = &asset.rooms[1];
    {
        let scene = first.scene.as_mut().unwrap();
        scene.target_room_warp = Some(1);
        scene.transition_to_room(bundle.as_ref(), 1, level1).unwrap();
        let coin = *scene.instances.iter().find(|(_, i)| i.object == 58 && i.alive).unwrap().0;
        let (x, y) = {
            let i = &scene.instances[&coin];
            (i.fields["x"], i.fields["y"])
        };
        let player = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;
        scene.instances.get_mut(&player).unwrap().fields.insert("x".into(), x);
        scene.instances.get_mut(&player).unwrap().fields.insert("y".into(), y);
        scene.globals.insert("coinmultiply".into(), 2.0);
        scene.tick(bundle.as_ref()).unwrap();
        assert!(!scene.instances[&coin].alive);
    }
    let (room, globals, score, collected) = first.scene.as_ref().unwrap().save_snapshot();
    assert_eq!(room, 1);
    assert_eq!(globals["coinmultiply"], 2.0);
    assert!(score > 0.0);
    assert!(!collected.is_empty(), "destroyed transient coin must be captured by identity");

    // JSON round-trip must keep the new fields byte-stable and filtered.
    let save = SaveData {
        format_version: CURRENT_SAVE_VERSION,
        current_room: room,
        checkpoint: callys_core::Checkpoint { room_index: room, x: 0.0, y: 0.0 },
        max_health: 4,
        gems: 0,
        coins: 0,
        current_weapon: callys_core::WeaponType::Pistol,
        unlocked_weapons: vec![callys_core::WeaponType::Pistol],
        collected_instance_ids: collected.clone(),
        scene_globals: globals.clone(),
        score,
    };
    let path = std::env::temp_dir().join(format!("cally-ir-save-test-{}.json", std::process::id()));
    write_save_atomic(&path, &save).unwrap();
    let reloaded = load_save(&path).unwrap().expect("saved file must load");
    assert_eq!(reloaded, save, "snapshot must survive JSON round-trip identically");
    assert!(reloaded.scene_globals.contains_key("coinmultiply"));
    assert!(!reloaded.scene_globals.contains_key("roomstart"), "transient globals must be filtered");
    std::fs::remove_file(&path).ok();

    // Session 2: cold GameState restores room, coin stays dead, multiplier live.
    let mut second = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    second.enable_ir_gameplay(bundle.clone()).unwrap();
    {
        let scene = second.scene.as_mut().unwrap();
        scene.restore_snapshot(bundle.as_ref(), room, level1, &globals, score, &collected).unwrap();
        assert_eq!(scene.current_room, 1.0);
        assert_eq!(scene.score, score);
        assert_eq!(scene.globals["coinmultiply"], 2.0);
        let dead = collected.iter().filter(|id| !scene.instances.get(id).is_some_and(|i| i.alive)).count();
        assert!(dead > 0, "collected identities must be removed on restore");
    }
    for _ in 0..15 {
        second.step(1.0 / 60.0);
        assert_eq!(second.runtime_diagnostic, None);
    }
}

#[test]
fn persistent_state_autosaves_and_reloads_through_file() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let dir = std::env::temp_dir().join(format!("cally-ir-autosave-{}", std::process::id()));
    std::fs::create_dir_all(&dir).unwrap();
    let droid = dir.join("game.droid");
    std::fs::copy(root.join("../../assets/game.droid"), &droid).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());
    let asset = GameDroidAsset::parse(&root.join("../../assets/game.droid")).unwrap();
    let level1 = &asset.rooms[1];

    let mut live = GameState::new_persistent(&droid).unwrap();
    live.enable_ir_gameplay(bundle.clone()).unwrap();
    {
        let scene = live.scene.as_mut().unwrap();
        scene.target_room_warp = Some(1);
        scene.transition_to_room(bundle.as_ref(), 1, level1).unwrap();
        scene.score = 123.0;
        scene.globals.insert("haskey".into(), 1.0);
    }
    live.step(1.0 / 60.0);
    assert!(live.runtime_diagnostic.is_none());
    let path = save_path_for_asset(&droid);
    let saved = load_save(&path).unwrap().expect("autosave must have written the file");
    assert_eq!(saved.current_room, 1);
    assert_eq!(saved.score, 123.0);
    assert_eq!(saved.scene_globals["haskey"], 1.0, "progression global must persist (coinpickup is transient by original UI Step zeroing)");

    // Cold restart: same file path, fresh GameState restores through nativeInit's code path.
    let mut cold = GameState::new_persistent(&droid).unwrap();
    cold.enable_ir_gameplay(bundle.clone()).unwrap();
    let save = load_save(&path).unwrap().unwrap();
    cold.restore_ir_snapshot(&save).unwrap();
    let scene = cold.scene.as_ref().unwrap();
    assert_eq!(scene.current_room, 1.0);
    assert_eq!(scene.score, 123.0);
    for _ in 0..10 {
        cold.step(1.0 / 60.0);
        assert_eq!(cold.runtime_diagnostic, None);
    }
    std::fs::remove_dir_all(&dir).ok();
}

#[test]
fn v1_v2_files_still_load_and_future_version_is_rejected() {
    let v2_minimal = r#"{"format_version":2,"current_room":3,
        "checkpoint":{"room_index":3,"x":1.0,"y":2.0},"max_health":4,"gems":0,"coins":7,
        "current_weapon":"Pistol","unlocked_weapons":["Pistol"],"collected_instance_ids":[5]}"#;
    let save = SaveData::from_json(v2_minimal).unwrap();
    assert_eq!(save.coins, 7);
    assert!(save.scene_globals.is_empty() && save.score == 0.0, "v2 without new fields defaults cleanly");

    let v1 = r#"{"format_version":1,"current_room":0,
        "checkpoint":{"room_index":0,"x":0.0,"y":0.0},"max_health":4,"gems":0,"coins":1,
        "current_weapon":"Pistol","unlocked_weapons":["Pistol"]}"#;
    assert_eq!(SaveData::from_json(v1).unwrap().collected_instance_ids, Vec::<i32>::new());

    let v99 = r#"{"format_version":99,"current_room":0,
        "checkpoint":{"room_index":0,"x":0.0,"y":0.0},"max_health":4,"gems":0,"coins":1,
        "current_weapon":"Pistol","unlocked_weapons":["Pistol"]}"#;
    assert!(SaveData::from_json(v99).is_err(), "future versions must stay rejected");

    let mutated = r#"{"format_version":2,"current_room":3,
        "checkpoint":{"room_index":3,"x":1.0,"y":2.0},"max_health":4,"gems":0,"coins":7,
        "current_weapon":"Pistol","unlocked_weapons":["Pistol"],"collected_instance_ids":[5],
        "score":1000.0,"scene_globals":{"health1":9.0,"roomstart":1.0}}"#;
    let parsed = SaveData::from_json(mutated).unwrap();
    assert_eq!(parsed.score, 1000.0);
    assert_eq!(parsed.scene_globals["health1"], 9.0);
    let filtered = SaveData { scene_globals: parsed.scene_globals.clone(), ..parsed };
    assert!(!filtered.to_json().unwrap().contains("roomstart"), "to_json must drop non-progression globals");
}
