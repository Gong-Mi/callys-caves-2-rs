use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn player_and_weapon_experience_triggers_level_up_and_progression_scaling() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();

    // 1. Verify initial level 1 baseline from GMS Game Start / fresh globals
    assert_eq!(scene.globals.get("level").copied(), Some(1.0));
    assert_eq!(scene.globals.get("xptolevelup").copied(), Some(30.0));
    assert_eq!(scene.globals.get("pistollevel").copied(), Some(1.0));
    assert_eq!(scene.globals.get("pistolxptolevelup").copied(), Some(46.0));

    // 2. Grant sufficient experience to meet thresholds
    scene.globals.insert("experience".into(), 30.0);
    scene.globals.insert("pistolxp".into(), 46.0);

    // 3. Step 30 frames for obj_UI Alarm 0 (CODE 368) to evaluate progression
    for _ in 0..30 {
        state.step(1.0 / 60.0);
    }

    let scene = state.scene.as_ref().unwrap();
    // Character level up: level 1 -> 2, xp resets to 1, threshold scales by 1.12
    assert_eq!(scene.globals.get("level").copied(), Some(2.0), "player level advances to 2");
    assert_eq!(scene.globals.get("experience").copied(), Some(1.0), "player experience resets to 1");
    let next_xp = scene.globals.get("xptolevelup").copied().unwrap();
    assert!((next_xp - 33.6).abs() < 1e-4, "xptolevelup scales by 1.12: 30.0 -> 33.6, got {next_xp}");

    // Weapon level up: pistol level 1 -> 2, xp resets to 1, threshold scales by 1.5
    assert_eq!(scene.globals.get("pistollevel").copied(), Some(2.0), "pistol level advances to 2");
    assert_eq!(scene.globals.get("pistolxp").copied(), Some(1.0), "pistol xp resets to 1");
    let next_pistol_xp = scene.globals.get("pistolxptolevelup").copied().unwrap();
    assert!((next_pistol_xp - 69.0).abs() < 1e-4, "pistolxptolevelup scales by 1.5: 46.0 -> 69.0, got {next_pistol_xp}");

    // 4. Consecutive level up to level 3
    let scene = state.scene.as_mut().unwrap();
    scene.globals.insert("experience".into(), next_xp);
    for _ in 0..30 {
        state.step(1.0 / 60.0);
    }

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.globals.get("level").copied(), Some(3.0), "player level advances to 3");
    let next_xp_3 = scene.globals.get("xptolevelup").copied().unwrap();
    assert!((next_xp_3 - (33.6 * 1.12)).abs() < 1e-4, "xptolevelup scales again by 1.12");

    // 5. Max level ceiling: level 20 cap check
    let scene = state.scene.as_mut().unwrap();
    scene.globals.insert("level".into(), 20.0);
    scene.globals.insert("experience".into(), 99999.0);
    for _ in 0..30 {
        state.step(1.0 / 60.0);
    }

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.globals.get("level").copied(), Some(20.0), "player level capped at 20");
}
