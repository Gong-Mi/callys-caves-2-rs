use callys_core::save::{SaveData, SaveError, CURRENT_SAVE_VERSION};
use callys_core::{Checkpoint, WeaponType};

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
    }
}

#[test]
fn save_json_round_trip_preserves_all_fields() {
    let original = complete_save();

    let json = original.to_json().expect("save should serialize");
    let restored = SaveData::from_json(&json).expect("current save version should load");

    assert_eq!(restored, original);
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
            "unlocked_weapons": ["Pistol", "Shotgun", "Sword"]
        }}"#
    );

    let error = SaveData::from_json(&json).expect_err("future save version must be rejected");

    assert!(matches!(
        error,
        SaveError::UnsupportedVersion { found, supported }
            if found == future_version && supported == CURRENT_SAVE_VERSION
    ));
}
