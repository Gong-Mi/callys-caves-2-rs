use callys_core::save::{SaveData, SaveError, CURRENT_SAVE_VERSION};
use callys_core::{Checkpoint, GameWorld, WeaponType};

fn complete_save() -> SaveData {
    SaveData {
        format_version: CURRENT_SAVE_VERSION,
        current_room: 7,
        checkpoint: Checkpoint {
            room_index: 6,
            x: 128.0,
            y: 492.0,
        },
        max_health: 175,
        gems: 23,
        coins: 41,
        current_weapon: WeaponType::Shotgun,
        unlocked_weapons: vec![
            WeaponType::Pistol,
            WeaponType::Shotgun,
            WeaponType::Sword,
        ],
        collected_instance_ids: vec![4242, 5001, 5002],
    }
}

#[test]
fn game_world_save_round_trip_restores_persistent_progress() {
    let mut original = GameWorld::new();
    original.current_room_index = 7;
    original.checkpoint = Checkpoint {
        room_index: 7,
        x: 128.0,
        y: 492.0,
    };
    original.player.max_health = 175;
    original.player.gems = 23;
    original.player.coins = 41;
    original.player.current_weapon = WeaponType::Shotgun;
    original.player.unlocked_weapons = vec![WeaponType::Pistol, WeaponType::Shotgun];
    original.collected_instance_ids.extend([5002, 4242, 5001]);

    let save = SaveData::from_world(&original);
    let mut restored = GameWorld::new();
    restored.restore_from_save(&save);

    assert_eq!(restored.current_room_index, 7);
    assert_eq!(restored.checkpoint, original.checkpoint);
    assert_eq!((restored.player.x, restored.player.y), (128.0, 492.0));
    assert_eq!(restored.player.max_health, 175);
    assert_eq!(restored.player.health, 175);
    assert_eq!(restored.player.gems, 23);
    assert_eq!(restored.player.coins, 41);
    assert_eq!(restored.player.current_weapon, WeaponType::Shotgun);
    assert_eq!(
        restored.player.unlocked_weapons,
        vec![WeaponType::Pistol, WeaponType::Shotgun]
    );
    assert_eq!(restored.collected_instance_ids, original.collected_instance_ids);
}

#[test]
fn save_json_round_trip_preserves_all_fields() {
    let original = complete_save();

    let json = original.to_json().expect("save should serialize");
    let restored = SaveData::from_json(&json).expect("current save version should load");

    assert_eq!(restored, original);
}

#[test]
fn save_json_serializes_collected_instance_ids_sorted_and_deduplicated() {
    let mut original = complete_save();
    original.collected_instance_ids = vec![5002, 4242, 5002, 5001];

    let json = original.to_json().expect("save should serialize");
    let value: serde_json::Value = serde_json::from_str(&json).unwrap();

    assert_eq!(value["format_version"], CURRENT_SAVE_VERSION);
    assert_eq!(value["collected_instance_ids"], serde_json::json!([4242, 5001, 5002]));
    assert_eq!(SaveData::from_json(&json).unwrap().collected_instance_ids, vec![4242, 5001, 5002]);
}

#[test]
fn version_one_save_migrates_all_progress_and_defaults_collected_instances_empty() {
    let json = r#"{
        "format_version": 1,
        "current_room": 1,
        "checkpoint": {"room_index": 1, "x": 128.0, "y": 492.0},
        "max_health": 100,
        "gems": 0,
        "coins": 0,
        "current_weapon": "Pistol",
        "unlocked_weapons": ["Pistol"]
    }"#;

    let migrated = SaveData::from_json(json).expect("v1 should migrate to v2");

    assert_eq!(migrated.format_version, CURRENT_SAVE_VERSION);
    assert_eq!(migrated.current_room, 1);
    assert_eq!(
        migrated.checkpoint,
        Checkpoint {
            room_index: 1,
            x: 128.0,
            y: 492.0,
        }
    );
    assert_eq!(migrated.max_health, 100);
    assert_eq!(migrated.gems, 0);
    assert_eq!(migrated.coins, 0);
    assert_eq!(migrated.current_weapon, WeaponType::Pistol);
    assert_eq!(migrated.unlocked_weapons, vec![WeaponType::Pistol]);
    assert!(migrated.collected_instance_ids.is_empty());
}

#[test]
fn future_save_version_is_rejected() {
    let future_version = CURRENT_SAVE_VERSION + 1;
    let json = format!(
        r#"{{
            "format_version": {future_version},
            "current_room": 7,
            "checkpoint": {{"room_index": 6, "x": 128.0, "y": 492.0}},
            "max_health": 175,
            "gems": 23,
            "coins": 41,
            "current_weapon": "Shotgun",
            "unlocked_weapons": ["Pistol", "Shotgun", "Sword"],
            "collected_instance_ids": []
        }}"#
    );

    let error = SaveData::from_json(&json).expect_err("future save version must be rejected");

    assert!(matches!(
        error,
        SaveError::UnsupportedVersion { found, supported }
            if found == future_version && supported == CURRENT_SAVE_VERSION
    ));
}
