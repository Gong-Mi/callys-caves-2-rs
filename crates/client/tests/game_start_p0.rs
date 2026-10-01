//! P0 startup-chain contract: the production boot must run the original
//! Game Start (obj_player Other_2, CODE 17) on a live player, with the three
//! original savefile INIs reachable through the real file boundary, and the
//! prologue riding the full scene exactly like the original single-scene boot.
//!
//! Evidence: reconstruction/contracts/startup.json (CODE 17 GML + bytecode
//! sha), CODE 548/549 disassembly in crates/core/src/generated/full_ir.json,
//! and the roomstart writer census (CODE 0/5/16/675 + lloydtutorial Destroy).
use callys_client::{write_save_atomic, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::save::{SaveData, CURRENT_SAVE_VERSION};
use std::path::PathBuf;
use std::sync::Arc;

fn manifest() -> &'static str {
    env!("CARGO_MANIFEST_DIR")
}

fn full_bundle() -> Arc<callys_core::code_vm::Bundle> {
    let path = PathBuf::from(manifest()).join("../../crates/core/src/generated/full_ir.json");
    Arc::new(load_bundle_from_file(&path).expect("load full_ir.json"))
}

fn intro_alive(state: &GameState) -> bool {
    state
        .scene
        .as_ref()
        .map(|s| s.instances.values().any(|i| i.object == 137 && i.alive))
        .unwrap_or(false)
}

/// Cold start (no INI files anywhere): CODE 17's no-save branch must derive
/// level=1, maxhp=4, xptolevelup=30, health1=4; the weapon ladder runs on the
/// fresh pistollevel=1. The intro spawned by CODE 17 deactivates the room, so
/// the player carries no alarm[6] and roomstart stays 0 (CODE 16's
/// roomstart=1+alarm[6]=10 block guards room==110, rm_ending).
#[test]
fn game_start_cold_boot_derives_original_baseline_and_spawns_intro() {
    let asset_path = PathBuf::from(manifest()).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState::new");
    state.enable_ir_gameplay(full_bundle()).expect("enable_ir_gameplay");

    let scene = state.scene.as_ref().expect("full scene");
    assert!(scene.instances.values().any(|i| i.object == 137 && i.alive),
        "CODE 17 spawns obj_introduction into the full scene");
    assert_eq!(scene.globals.get("level").copied(), Some(1.0), "cold start level");
    assert_eq!(scene.globals.get("maxhp").copied(), Some(4.0), "cold start maxhp");
    assert_eq!(scene.globals.get("xptolevelup").copied(), Some(30.0), "cold start xp gate");
    assert_eq!(scene.globals.get("health1").copied(), Some(4.0), "cold start health");
    assert_eq!(scene.globals.get("pistoldamage").copied(), Some(1.0),
        "pistol ladder level 1 damage");
    assert_eq!(scene.globals.get("roomstart").copied(), Some(0.0),
        "roomstart stays 0 outside rm_ending");

    let player = scene.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, i)| (id, i))
        .expect("live player");
    assert_eq!(player.1.alarms[6], -1, "town boot never arms alarm[6]");
}

/// The real INI boundary: with a savefile.ini on disk, CODE 17 must read it
/// through ini_open/ini_read_real (file_exists takes the disk path), overwrite
/// the fresh baseline with the file's values, and Room End (CODE 15) must
/// flush the INI back to disk through ini_close.
#[test]
fn game_start_reads_ini_and_room_end_flushes_it_back() {
    let dir = std::env::temp_dir().join(format!("callys-p0-ini-{}", std::process::id()));
    let _ = std::fs::remove_dir_all(&dir);
    std::fs::create_dir_all(&dir).expect("temp dir");
    std::fs::write(dir.join("savefile.ini"), "current_maxhp=7\ncurrent_level=3\n")
        .expect("seed savefile.ini");

    let asset_path = PathBuf::from(manifest()).join("../../assets/game.droid");
    let mut state =
        GameState::new_with_save_path(&asset_path, Some(dir.join("save.json"))).expect("state");
    state.enable_ir_gameplay(full_bundle()).expect("enable_ir_gameplay");

    {
        let scene = state.scene.as_ref().expect("full scene");
        assert_eq!(scene.globals.get("maxhp").copied(), Some(7.0),
            "CODE 17 read current_maxhp from the real savefile.ini");
        assert_eq!(scene.globals.get("level").copied(), Some(3.0),
            "CODE 17 read current_level from the real savefile.ini");
        assert_eq!(
            scene.ini_data.get(&("savefile.ini".into(), "Save".into(), "current_maxhp".into())),
            Some(&7.0),
            "ini_open loaded the disk file into the scene cache"
        );
    }

    // Room End (7/5, CODE 15) runs the original full INI write-back and
    // ini_close; the file must land on disk through the same boundary.
    let bundle = full_bundle();
    let pid = state.scene.as_ref().unwrap().instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(&id, _)| id)
        .expect("player");
    state.scene.as_mut().unwrap()
        .dispatch(bundle.as_ref(), pid, 7, 5)
        .expect("player Room End (CODE 15)");
    let written = std::fs::read_to_string(dir.join("savefile.ini")).expect("flushed ini");
    assert!(written.contains("current_maxhp=7"), "Room End flushed the INI: {written}");
    let _ = std::fs::remove_dir_all(&dir);
}

/// A boot-time IR snapshot must survive the prologue handover: the original
/// boot plays the prologue over rm_town (CODE 17 spawns the intro there), and
/// the saved room loads only once the intro is gone — with no second
/// enable_ir_gameplay rebuilding the room over the restored scene.
#[test]
fn boot_save_restores_after_prologue_handover_without_rebuild() {
    let dir = std::env::temp_dir().join(format!("callys-p0-restore-{}", std::process::id()));
    let _ = std::fs::remove_dir_all(&dir);
    std::fs::create_dir_all(&dir).expect("temp dir");
    let save_path = dir.join("save.json");
    let save = SaveData {
        format_version: CURRENT_SAVE_VERSION,
        current_room: 1,
        checkpoint: callys_core::Checkpoint { room_index: 1, x: 0.0, y: 0.0 },
        max_health: 4,
        gems: 0,
        coins: 0,
        current_weapon: callys_core::WeaponType::Pistol,
        unlocked_weapons: vec![callys_core::WeaponType::Pistol],
        collected_instance_ids: Vec::new(),
        scene_globals: [
            ("maxhp".to_string(), 7.0),
            ("level".to_string(), 3.0),
        ]
        .into_iter()
        .collect(),
        score: 120.0,
    };
    write_save_atomic(&save_path, &save).expect("seed IR save");

    let asset_path = PathBuf::from(manifest()).join("../../assets/game.droid");
    let mut state =
        GameState::new_with_save_path(&asset_path, Some(save_path)).expect("state");
    assert!(state.queue_boot_ir_restore(), "the v2 scene save must queue for handover");
    state.enable_ir_gameplay(full_bundle()).expect("enable_ir_gameplay");
    assert!(intro_alive(&state), "the prologue rides the boot scene");

    // Original tap gate: alarm[0] = 120 frames, then a real tap kills the intro.
    for _ in 0..125 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    }
    assert!(intro_alive(&state), "intro outlives 120 frames");
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;

    // Handover frame: the intro died in the SAME scene, the queued restore
    // landed on the live scene, and no enable_ir_gameplay rebuild happened.
    assert!(!intro_alive(&state), "the tap retired the intro");
    {
        let scene = state.scene.as_ref().expect("scene after handover");
        assert_eq!(scene.current_room, 1.0,
            "the saved room must be live after handover, not the rebuilt town");
        assert_eq!(scene.globals.get("maxhp").copied(), Some(7.0),
            "restored globals survive the handover intact");
        assert_eq!(scene.score, 120.0, "restored score survives the handover");
        assert!(
            scene.instances.values().any(|i| i.object == 0 && i.alive),
            "the player persists across the restore"
        );
    }

    // The very next frame runs the original upgrade reconciliation ladder
    // (player Step, CODE 12): level==3 finds the unapplied hpupgrade3 and
    // enforces maxhp=6, health1=6, hpupgrade3=1. The INI's maxhp only rules
    // the instant before the first Step; the ladder is the original
    // authority. A cold boot with this same savefile.ini reconciles
    // identically, so this is fidelity, not a restore defect.
    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    {
        let scene = state.scene.as_ref().expect("scene");
        assert_eq!(scene.globals.get("maxhp").copied(), Some(6.0),
            "the level-3 ladder reconciles INI maxhp=7 down to 6 on the first Step");
        assert_eq!(scene.globals.get("health1").copied(), Some(6.0),
            "health1 follows the reconciled maxhp (original CODE 12 behavior)");
        let pid = scene.instances.iter()
            .find(|(_, i)| i.object == 0 && i.alive)
            .map(|(&id, _)| id)
            .expect("player");
        assert_eq!(scene.instances[&pid].fields.get("hpupgrade3").copied(), Some(1.0),
            "the ladder marks hpupgrade3 applied (original CODE 12 behavior)");
    }
    let _ = std::fs::remove_dir_all(&dir);
}
