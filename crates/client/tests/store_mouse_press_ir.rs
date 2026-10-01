use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

fn logical_screen_point_for_world(
    state: &GameState,
    world_x: f64,
    world_y: f64,
) -> (f64, f64) {
    let scene = state.scene.as_ref().expect("IR scene");
    let view_index = scene.active_view_index().expect("active room view");
    let view = &scene.room_views[view_index];
    let (camera_x, camera_y) = scene
        .view_positions
        .get(&(view_index as i32))
        .copied()
        .unwrap_or((view.xview as f64, view.yview as f64));
    (
        (world_x - camera_x) * scene.display_width / view.wview as f64,
        (world_y - camera_y) * scene.display_height / view.hview as f64,
    )
}

fn pointer_press_instance_center(state: &mut GameState, instance_id: i32) {
    let (world_x, world_y) = {
        let scene = state.scene.as_ref().expect("IR scene");
        let (left, right, top, bottom) = scene
            .bounds_for_instance(instance_id)
            .expect("button bounds");
        ((left + right) / 2.0, (top + bottom) / 2.0)
    };
    let (screen_x, screen_y) = logical_screen_point_for_world(state, world_x, world_y);
    let (round_trip_x, round_trip_y) = state.screen_to_world(screen_x, screen_y);
    assert!(
        (round_trip_x - world_x).abs() < 1e-6 && (round_trip_y - world_y).abs() < 1e-6,
        "screen/world mapping must round-trip the button center"
    );
    state.pointer_pressed(screen_x, screen_y);
}

#[test]
fn pointer_press_drives_mouse_0_store_purchases_and_stat_upgrades() {
    let manifest_dir = Path::new(env!("CARGO_MANIFEST_DIR"));
    let bundle = Arc::new(load_bundle_from_file(&manifest_dir.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&manifest_dir.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();
    // Establish the camera origin that the first presented frame exposes to GML.
    state.step(1.0 / 60.0);

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

    // 3. Click (Mouse_0 / LeftPressed) on obj_powerupgrade
    pointer_press_instance_center(&mut state, pwr_btn_id);
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.score, 5000.0, "score deducted 5000 for power upgrade (10000 -> 5000)");
    assert_eq!(scene.globals.get("powerupgradebought").copied(), Some(1.0), "powerupgradebought set to 1");
    assert_eq!(scene.globals.get("pwr").copied(), Some(2.0), "global.pwr upgraded to 2");

    // 4. Duplicate press on already-bought power upgrade must NOT deduct score again
    pointer_press_instance_center(&mut state, pwr_btn_id);
    state.step(1.0 / 60.0);
    assert_eq!(state.scene.as_ref().unwrap().score, 5000.0, "no duplicate deduction on bought power upgrade");

    // 5. Click on obj_strengthupgrade (costs 3000)
    pointer_press_instance_center(&mut state, str_btn_id);
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.score, 2000.0, "score deducted 3000 for strength upgrade (5000 -> 2000)");
    assert_eq!(scene.globals.get("strengthupgradebought").copied(), Some(1.0), "strengthupgradebought set to 1");

    // 6. Click on sword upgrade 2 (costs 10000) with insufficient score (only 2000 available)
    let swd2_btn_id = *scene.instances.iter()
        .find(|(_, i)| i.object == 89 && i.alive && i.active)
        .map(|(id, _)| id)
        .expect("obj_swordupgrade2 materialized in store");
    pointer_press_instance_center(&mut state, swd2_btn_id);
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().unwrap();
    assert_eq!(scene.score, 2000.0, "insufficient score rejects purchase, score unchanged");
    assert_eq!(scene.globals.get("swordupgrade2bought").copied(), Some(0.0), "swordupgrade2bought remains 0");
}
