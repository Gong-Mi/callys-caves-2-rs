//! The map round trip in ONE continuous scene: the pause menu's map button
//! opens the resolution-correct view room, the fog gate keeps exactly the
//! visited room's tile, and tapping that tile warps home and re-pins the
//! player at startx/starty — the pieces map_system_ir and map_exit_ending_ir
//! prove separately, here chained the way obj_player Other_4 (CODE 16) sets
//! level5visited on Room Start and obj_bg's Create seeds startx.
//!
//! Chain (all shipped bytecode, dispatch discipline from the map suites):
//! 1. town -> rm_level5 through transition_to_room: Room Start CODE 16 sets
//!    level5visited=1 (no hand-written global), obj_UI Create builds the
//!    pausebutton;
//! 2. pausebutton Mouse_7 (CODE 517): timespaused += 1, obj_firstpause
//!    created — its Create view_current==0 branch deactivates the room
//!    (keep-self) and re-activates only the 7 menu objects; the frozen-world
//!    assertion here is the persistent player sitting inactive;
//! 3. mapmenu Mouse_7 (CODE 476) at the host's 1136x640 -> the mapview0
//!    (113) resolution branch, the real-device view from CODE 538;
//! 4. consuming the warp: Room End CODE 15, the transient purge (mapmenu and
//!    firstpause were never persistent), then the tile RoomCC fog gate: with
//!    only level5visited set, exactly one tile out of mapview0's 112 survives;
//! 5. tile Mouse_7 (CODE 692): warpfrommap=1 + room_goto(5) + the player
//!    re-pinned at global.startx/starty (the selector reaches the deactivated
//!    persistent player, GM's variable-access semantics);
//! 6. consuming the return: obj_bg's Create re-seeds startx/starty for the
//!    room, CODE 16's warpfrommap branch re-pins the player — assert the
//!    landing matches the start pin captured at step 1 and that the world
//!    is awake again (player active, the input-lock alarm[6]=10 armed).
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const UI: i32 = 66;
const PAUSEBUTTON: i32 = 125;
const FIRSTPAUSE: i32 = 118;
const MAPMENU: i32 = 111;
const MAPTILE: i32 = 160;
const LEVEL5: usize = 5;
const MAPVIEW0: usize = 113;

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
fn player_id(scene: &Scene) -> i32 {
    scene.instances.iter().find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id).expect("persistent obj_player")
}
fn field(scene: &Scene, id: i32, name: &str) -> f64 {
    scene.instances[&id].fields[name]
}

#[test]
fn the_pause_menu_opens_the_map_and_a_visited_tile_warps_home_re_pinned() {
    let (bundle, mut scene, asset) = setup();
    let player = player_id(&scene);

    // 1. Town -> rm_level5. CODE 16's Room Start sets the visited flag by
    // ITSELF (nothing hand-written); obj_ui Create builds the pause button.
    scene.transition_to_room(&bundle, LEVEL5, &asset.rooms[LEVEL5]).expect("enter rm_level5");
    assert_eq!(scene.globals.get("level5visited").copied(), Some(1.0),
        "CODE 16 marked rm_level5 visited on Room Start");
    assert_eq!(count(&scene, UI), 1, "rm_level5 places obj_UI");
    assert_eq!(active_count(&scene, PAUSEBUTTON), 1, "obj_UI's Create created the pausebutton");
    // obj_bg's Create seeds this room's start pin (CODE 360's switch).
    let startx = scene.globals["startx"];
    let starty = scene.globals["starty"];
    // Walk the player away from the pin so the re-pin is observable.
    scene.write(player, -1, "x", None, 2000.0).unwrap();
    scene.write(player, -1, "y", None, 700.0).unwrap();

    // 2. Pause. CODE 517 arms firstpause, whose Create (view_current==0)
    // freezes the world under the menu.
    scene.globals.insert("timespaused".into(), 0.0);
    let btn = scene.instances.iter().find(|(_, i)| i.object == PAUSEBUTTON && i.alive)
        .map(|(id, _)| *id).unwrap();
    scene.dispatch(&bundle, btn, 6, 7).expect("pause tap");
    assert_eq!(scene.globals["timespaused"], 1.0);
    assert_eq!(count(&scene, FIRSTPAUSE), 1, "the tap created obj_firstpause");
    assert_eq!(active_count(&scene, MAPMENU), 1, "firstpause's Create built an ACTIVE mapmenu");
    assert!(!scene.instances[&player].active,
        "deactivate_all(true) froze the player under the menu (keep-self = firstpause)");
    assert!(!scene.instances[&btn].active, "the pausebutton itself is frozen too");

    // 3. The map button: the host's 1136x640 picks rm_mapview0 (113).
    let menu = scene.instances.iter().find(|(_, i)| i.object == MAPMENU && i.alive && i.active)
        .map(|(id, _)| *id).unwrap();
    scene.dispatch(&bundle, menu, 6, 7).expect("mapmenu tap");
    assert_eq!(scene.target_room_warp.take(), Some(MAPVIEW0),
        "CODE 476's 1136x640 branch opens rm_mapview0 (the real-device resolution)");

    // 4. Consume the warp. Transient purge (nothing map-side is persistent
    // except the player/music set), then the tile fog gate: exactly the
    // room5 tile survives the room's 112 tiles.
    scene.transition_to_room(&bundle, MAPVIEW0, &asset.rooms[MAPVIEW0]).expect("enter rm_mapview0");
    assert_eq!(count(&scene, MAPMENU), 0, "mapmenu was transient and purged by the switch");
    assert_eq!(count(&scene, FIRSTPAUSE), 0, "firstpause too");
    assert_eq!(count(&scene, MAPTILE), 1,
        "the fog gate kept exactly one visited-room tile out of 112");
    let tile = scene.instances.iter()
        .find(|(_, i)| i.object == MAPTILE && i.alive)
        .map(|(id, _)| *id).unwrap();
    assert_eq!(scene.instances[&tile].fields["goto"], LEVEL5 as f64,
        "the survivor is the rm_level5 tile");

    // 5. The tile tap: CODE 692 arms the warp and re-pins the (deactivated,
    // still reachable per GM variable access) persistent player.
    scene.dispatch(&bundle, tile, 6, 7).expect("maptile tap");
    assert_eq!(scene.globals["warpfrommap"], 1.0);
    assert_eq!(scene.target_room_warp.take(), Some(LEVEL5 as usize),
        "CODE 692 warps to the tile's goto");
    assert_eq!(field(&scene, player, "x"), startx, "the player was pinned at global.startx");
    assert_eq!(field(&scene, player, "y"), starty, "and global.starty");

    // 6. Consume the return. obj_bg re-seeds the same pin on materialize,
    // CODE 16's warpfrommap branch re-pins the player, and the world wakes
    // (the menu teardown was the sweep + activate_all inside CODE 692).
    scene.transition_to_room(&bundle, LEVEL5, &asset.rooms[LEVEL5]).expect("back to rm_level5");
    assert_eq!(scene.globals["startx"], startx, "obj_bg re-seeded the same room pin");
    assert_eq!(field(&scene, player, "x"), startx, "CODE 16 re-pinned the player on the way home");
    assert_eq!(field(&scene, player, "y"), starty);
    assert!(scene.instances[&player].active, "the player runs again in the room");
    assert_eq!(scene.instances[&player].alarms[6], 10, "CODE 16's input-lock alarm armed");
    assert_eq!(count(&scene, PAUSEBUTTON), 1, "a fresh pausebutton via obj_UI");
}
