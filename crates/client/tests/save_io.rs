use std::fs;
use std::path::Path;

use callys_client::{load_save, save_path_for_asset, write_save_atomic, GameState};
use callys_core::save::{SaveData, CURRENT_SAVE_VERSION};
use callys_core::{Checkpoint, Rect, WeaponPickup, WeaponType};

fn save_data() -> SaveData {
    SaveData {
        format_version: CURRENT_SAVE_VERSION,
        current_room: 1,
        checkpoint: Checkpoint {
            room_index: 1,
            x: 128.0,
            y: 492.0,
        },
        max_health: 175,
        gems: 23,
        coins: 41,
        current_weapon: WeaponType::Shotgun,
        unlocked_weapons: vec![WeaponType::Pistol, WeaponType::Shotgun],
    }
}

#[test]
fn save_path_is_next_to_private_game_asset() {
    assert_eq!(
        save_path_for_asset(Path::new("/data/user/0/com.example/files/game.droid")),
        Path::new("/data/user/0/com.example/files/save-v1.json")
    );
}

#[test]
fn atomic_write_round_trips_without_leaving_temporary_file() {
    let temp = tempfile::tempdir().unwrap();
    let path = temp.path().join("save-v1.json");

    write_save_atomic(&path, &save_data()).unwrap();

    assert_eq!(load_save(&path).unwrap(), Some(save_data()));
    assert!(!temp.path().join("save-v1.json.tmp").exists());
}

#[test]
fn missing_save_is_a_normal_new_game() {
    let temp = tempfile::tempdir().unwrap();
    assert_eq!(load_save(&temp.path().join("missing.json")).unwrap(), None);
}

#[test]
fn corrupt_and_future_saves_fail_safely_and_remain_diagnosable() {
    let temp = tempfile::tempdir().unwrap();
    let corrupt = temp.path().join("corrupt.json");
    fs::write(&corrupt, b"not-json").unwrap();
    let corrupt_error = load_save(&corrupt).unwrap_err().to_string();
    assert!(corrupt_error.contains("invalid save data"));

    let future = temp.path().join("future.json");
    let future_json = save_data().to_json().unwrap().replace(
        &format!("\"format_version\":{}", CURRENT_SAVE_VERSION),
        &format!("\"format_version\":{}", CURRENT_SAVE_VERSION + 1),
    );
    fs::write(&future, future_json).unwrap();
    let future_error = load_save(&future).unwrap_err().to_string();
    assert!(future_error.contains("unsupported save format version"));
}

#[test]
fn initialization_loads_room_before_restoring_checkpoint_coordinates() {
    let temp = tempfile::tempdir().unwrap();
    let save_path = temp.path().join("save-v1.json");
    write_save_atomic(&save_path, &save_data()).unwrap();
    let droid = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid");

    let state = GameState::new_with_save_path(&droid, Some(save_path)).unwrap();

    assert_eq!(state.world.current_room_index, 1);
    assert_eq!(state.world.current_room_name, "rm_level1");
    assert_eq!((state.world.player.x, state.world.player.y), (128.0, 492.0));
    assert_eq!(state.world.checkpoint, save_data().checkpoint);
    assert_eq!(state.world.player.max_health, 175);
    assert_eq!(state.world.player.current_weapon, WeaponType::Shotgun);
}

#[test]
fn stable_progress_events_write_but_idle_frames_do_not() {
    let temp = tempfile::tempdir().unwrap();
    let save_path = temp.path().join("save-v1.json");
    let droid = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid");
    let mut state = GameState::new_with_save_path(&droid, Some(save_path.clone())).unwrap();
    state.world.player.x = -1000.0;
    state.world.player.y = -1000.0;

    state.step(0.0);
    assert!(!save_path.exists(), "idle frame must not write a save");

    state.world.weapon_pickups.push(WeaponPickup {
        rect: Rect::new(-1000.0, -1000.0, 32.0, 32.0),
        weapon: WeaponType::Shotgun,
        sprite_id: -1,
        collected: false,
    });
    state.step(0.0);

    let saved = load_save(&save_path).unwrap().unwrap();
    assert_eq!(saved.current_weapon, WeaponType::Shotgun);
    assert!(saved.unlocked_weapons.contains(&WeaponType::Shotgun));
}

#[test]
fn room_transition_persists_post_load_checkpoint() {
    let temp = tempfile::tempdir().unwrap();
    let save_path = temp.path().join("save-v1.json");
    let droid = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid");
    let mut state = GameState::new_with_save_path(&droid, Some(save_path.clone())).unwrap();
    let town_exit = state
        .world
        .warps
        .iter()
        .find(|warp| warp.creation_code == 804)
        .cloned()
        .unwrap();
    state.world.player.x = town_exit.rect.x;
    state.world.player.y = town_exit.rect.y;

    state.step(0.0);

    let saved = load_save(&save_path).unwrap().unwrap();
    assert_eq!(saved.current_room, 1);
    assert_eq!(saved.checkpoint.room_index, 1);
    assert_eq!((saved.checkpoint.x, saved.checkpoint.y), (128.0, 492.0));
}

#[test]
fn corrupt_save_does_not_abort_initialization() {
    let temp = tempfile::tempdir().unwrap();
    let save_path = temp.path().join("save-v1.json");
    fs::write(&save_path, b"not-json").unwrap();
    let droid = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid");

    let state = GameState::new_with_save_path(&droid, Some(save_path)).unwrap();

    assert_eq!(state.world.current_room_index, 0);
    assert!(state
        .save_diagnostic
        .as_deref()
        .unwrap()
        .contains("invalid save data"));
}
