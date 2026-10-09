//! The store round trip inside the pause menu: firstpause's view-0 branch
//! activates obj_store (the #90 suite pinned the sibling branches), the store
//! button opens obj_pause, pause's Create deactivates the world (keep-self)
//! and builds the nine-item shop page, a real purchase fires through the
//! item's own Mouse_0, and backtogame's ELSE branch (CODE 470, map rooms
//! tested by map_exit_ending_ir) sweeps the whole menu and re-activates the
//! frozen player. One continuous scene, all shipped dispatch — the middle
//! seam (pause -> store page) was never chained before.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const UI: i32 = 66;
const PAUSEBUTTON: i32 = 125;
const FIRSTPAUSE: i32 = 118;
const STORE: i32 = 110;
const PAUSE: i32 = 122;
const BACKTOGAME: i32 = 108;
const SWORDUPGRADE: i32 = 88;
const LEVEL5: usize = 5;

fn setup() -> (Bundle, Scene, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();
    for (sid, sprite) in &asset.sprites {
        scene.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sprite.width as f64,
            height: sprite.height as f64,
            origin_x: sprite.origin_x as f64,
            origin_y: sprite.origin_y as f64,
            frames: sprite.tpag_indices.len().max(1) as f64,
        });
    }
    scene.load_room_from_data(&bundle, 0, &asset.rooms[0]).unwrap();
    scene.view_positions.insert(0, (0.0, 0.0));
    (bundle, scene, asset)
}

fn count(scene: &Scene, object: i32) -> usize {
    scene.instances.values().filter(|i| i.object == object && i.alive).count()
}
fn active_count(scene: &Scene, object: i32) -> usize {
    scene.instances.values().filter(|i| i.object == object && i.alive && i.active).count()
}
fn id_of(scene: &Scene, object: i32) -> i32 {
    scene.instances.iter().find(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id).expect("instance")
}

#[test]
fn the_pause_menu_opens_the_shop_a_purchase_lands_and_back_home_sweeps() {
    let (bundle, mut scene, asset) = setup();
    scene.transition_to_room(&bundle, LEVEL5, &asset.rooms[LEVEL5]).expect("enter rm_level5");
    scene.globals.insert("timespaused".into(), 0.0);
    scene.score = 3000.0;

    // Pause: firstpause's view-0 branch builds the menu and activates the
    // store button under the freeze.
    let btn = id_of(&scene, PAUSEBUTTON);
    scene.dispatch(&bundle, btn, 6, 7).expect("pause tap");
    assert_eq!(count(&scene, FIRSTPAUSE), 1);
    assert_eq!(active_count(&scene, STORE), 1, "firstpause activated obj_store");
    assert!(active_count(&scene, BACKTOGAME) >= 1, "the exit button is reachable");
    let player = id_of(&scene, PLAYER);
    assert!(!scene.instances[&player].active, "the world is frozen under the menu");

    // Open the shop: CODE 474 creates obj_pause at backtogame's spot; pause's
    // Create sets storemenu, freezes again (keep-self), and builds the page.
    let store = id_of(&scene, STORE);
    scene.dispatch(&bundle, store, 6, 7).expect("store tap");
    assert_eq!(count(&scene, PAUSE), 1, "CODE 474 created obj_pause");
    assert_eq!(scene.globals.get("storemenu").copied(), Some(1.0), "pause's Create opened the shop menu");
    assert_eq!(active_count(&scene, SWORDUPGRADE), 1, "the shop page carries swordupgrade");
    assert_eq!(count(&scene, FIRSTPAUSE), 1, "firstpause is still alive (deactivated) under the shop");

    // The real purchase through the item's own Mouse_0 (price 3000, gates
    // pinned by store_sweep_ir - here it must fire in this live page):
    let sword = id_of(&scene, SWORDUPGRADE);
    assert!(scene.instances[&sword].active, "the shop item is clickable");
    scene.dispatch(&bundle, sword, 6, 0).expect("purchase click");
    assert_eq!(scene.score, 0.0, "the price was deducted from the live score");
    assert_eq!(scene.globals["sword"], 1.0, "the upgrade applied");
    assert_eq!(scene.globals["swordupgradebought"], 1.0);

    // Back home: CODE 470's ELSE branch sweeps the whole menu (store items,
    // the store button, firstpause, pause itself) and re-activates the world.
    let exit = id_of(&scene, BACKTOGAME);
    scene.dispatch(&bundle, exit, 6, 7).expect("backtogame outside the map");
    for obj in [PAUSE, STORE, FIRSTPAUSE, SWORDUPGRADE, 84, 87, 89, 92, 93, 96, 99, 116] {
        assert_eq!(count(&scene, obj), 0, "menu object {obj} swept by CODE 470");
    }
    assert!(scene.instances[&player].active, "instance_activate_all woke the persistent player");
    assert_eq!(scene.globals.get("storemenu").copied(), Some(0.0),
        "pause's Destroy closed the shop menu");
    assert_eq!(count(&scene, PAUSEBUTTON), 1, "the HUD pausebutton survived the sweep (it is not on the teardown list)");
}
