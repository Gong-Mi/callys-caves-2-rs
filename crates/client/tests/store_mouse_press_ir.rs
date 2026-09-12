use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn pointer_press_drives_mouse_0_store_purchases_and_stat_upgrades() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    let scene = state.scene.as_mut().unwrap();

    // 1. Initial baseline: give player sufficient score for upgrades
    scene.score = 10000.0;
    assert_eq!(scene.globals.get("powerupgradebought").copied(), Some(0.0));
    assert_eq!(scene.globals.get("strengthupgradebought").copied(), Some(0.0));
    assert_eq!(scene.globals.get("pwr").copied(), Some(1.0));

    // 2. Open store menu by creating obj_pause (object 122 in GMS, CODE 507)
    // obj_pause Create_0 instantiates store buttons at view 0 offsets
    let pause_id = scene.create(&bundle, 122, 0.0, 0.0).expect("create obj_pause");
    assert!(scene.instances.contains_key(&pause_id));

    // Find obj_powerupgrade (84) and obj_strengthupgrade (93)
    let pwr_btn_id = *scene.instances.iter()
        .find(|(_, i)| i.object == 84 && i.alive && i.active)
        .map(|(id, _)| id)
        .expect("obj_powerupgrade materialized and active in store");

    let str_btn_id = *scene.instances.iter()
        .find(|(_, i)| i.object == 93 && i.alive && i.active)
        .map(|(id, _)| id)
        .expect("obj_strengthupgrade materialized and active in store");

    let (pwr_left, pwr_right, pwr_top, pwr_bottom) = scene.bounds_for_instance(pwr_btn_id).expect("pwr button bounds");
    let pwr_click_x = (pwr_left + pwr_right) / 2.0;
    let pwr_click_y = (pwr_top + pwr_bottom) / 2.0;

    let (str_left, str_right, str_top, str_bottom) = scene.bounds_for_instance(str_btn_id).expect("str button bounds");
    let str_click_x = (str_left + str_right) / 2.0;
    let str_click_y = (str_top + str_bottom) / 2.0;

    // 3. Click (Mouse_0 / LeftPressed) on obj_powerupgrade
    let (vx, vy) = state.scene.as_ref().unwrap().view_positions.get(&0).copied().unwrap_or((0.0, 0.0));
    state.pointer_pressed(pwr_click_x - vx, pwr_click_y - vy);
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.score, 5000.0, "score deducted 5000 for power upgrade (10000 -> 5000)");
    assert_eq!(scene.globals.get("powerupgradebought").copied(), Some(1.0), "powerupgradebought set to 1");
    assert_eq!(scene.globals.get("pwr").copied(), Some(2.0), "global.pwr upgraded to 2");

    // 4. Duplicate press on already-bought power upgrade must NOT deduct score again
    let (vx, vy) = state.scene.as_ref().unwrap().view_positions.get(&0).copied().unwrap_or((0.0, 0.0));
    state.pointer_pressed(pwr_click_x - vx, pwr_click_y - vy);
    state.step(1.0 / 60.0);
    assert_eq!(state.scene.as_ref().unwrap().score, 5000.0, "no duplicate deduction on bought power upgrade");

    // 5. Click on obj_strengthupgrade (costs 3000)
    let (vx, vy) = state.scene.as_ref().unwrap().view_positions.get(&0).copied().unwrap_or((0.0, 0.0));
    state.pointer_pressed(str_click_x - vx, str_click_y - vy);
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.score, 2000.0, "score deducted 3000 for strength upgrade (5000 -> 2000)");
    assert_eq!(scene.globals.get("strengthupgradebought").copied(), Some(1.0), "strengthupgradebought set to 1");

    // 6. Click on sword upgrade 2 (costs 10000) with insufficient score (only 2000 available)
    let swd2_btn_id = *scene.instances.iter()
        .find(|(_, i)| i.object == 89 && i.alive && i.active)
        .map(|(id, _)| id)
        .expect("obj_swordupgrade2 materialized in store");
    let (s2_l, s2_r, s2_t, s2_b) = scene.bounds_for_instance(swd2_btn_id).expect("swd2 bounds");
    let (vx, vy) = state.scene.as_ref().unwrap().view_positions.get(&0).copied().unwrap_or((0.0, 0.0));
    state.pointer_pressed((s2_l + s2_r) / 2.0 - vx, (s2_t + s2_b) / 2.0 - vy);
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.score, 2000.0, "insufficient score rejects purchase, score unchanged");
    assert_eq!(scene.globals.get("swordupgrade2bought").copied(), Some(0.0), "swordupgrade2bought remains 0");
}
