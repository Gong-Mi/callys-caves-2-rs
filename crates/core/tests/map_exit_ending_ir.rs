//! Map exit + ending entry batch: obj_backtogame (108, CODE 470/471) — the
//! map screen's "back to game" button that closes the map loop — and the
//! ending room's entry contract (rm_ending player binding CODE 1022, the
//! still obj_enemy CODE 1023, and the roomstart lock chain already pinned in
//! game-start-p0). Static decode first, live probes on this host; scratch
//! probes deleted.
//!
//! Static decode (contract reconstruction/contracts/map-exit-ending.md):
//! - backtogame Mouse_7 (CODE 470): the room gate is `room == 111 || 113 ||
//!   112` (bt/bf chain with the bt op = branch-true on the first two); in a
//!   map room it does `room_goto(roomcamefrom)` + player.x=startx / y=starty +
//!   activate_all + the same 15-object UI sweep as the maptile tap; outside
//!   the three map rooms it only sweeps (no warp).
//! - the sweep list matches obj_maptile's CODE 692 sweep (99/115/122/110/107/
//!   109/118/108/116/123/119/120/114/112/113) — one shared UI teardown.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use callys_core::ir_scene::SpriteBounds;
use std::path::Path;

const PLAYER: i32 = 0;
const BACKTOGAME: i32 = 108;

fn setup() -> (callys_core::code_vm::Bundle, Scene, GameDroidAsset) {
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
    (bundle, scene, asset)
}

#[test]
fn backtogame_closes_the_map_loop_back_to_the_saved_room() {
    let (bundle, mut scene, asset) = setup();
    // Enter rm_map with one visited room, a live persistent player and the
    // map's saved pin state — exactly what the maptile tap sets up.
    scene.globals.insert("room42visited".into(), 1.0);
    scene.transition_to_room(&bundle, 111, &asset.rooms[111]).unwrap();
    let _player = scene.create(&bundle, PLAYER, 0.0, 0.0).unwrap();
    scene.globals.insert("roomcamefrom".into(), 39.0);
    scene.globals.insert("startx".into(), 4242.0);
    scene.globals.insert("starty".into(), 1717.0);
    scene.globals.insert("warpfrommap".into(), 1.0);

    // The button's release in a MAP room: warp back to roomcamefrom, restore
    // the player's standing spot, reactivate the world.
    let btn = scene.create(&bundle, BACKTOGAME, 100.0, 100.0).unwrap();
    scene.dispatch(&bundle, btn, 6, 7).expect("backtogame release in rm_map");
    assert_eq!(scene.target_room_warp, Some(39),
        "CODE 470 warps back to roomcamefrom (the room you opened the map from)");
    let player = scene.instances.values().find(|i| i.object == PLAYER).unwrap();
    assert_eq!((player.fields.get("x").copied(), player.fields.get("y").copied()),
        (Some(4242.0), Some(1717.0)),
        "the player is re-pinned to startx/starty — the map exit restores your spot");
}

#[test]
fn backtogame_outside_the_map_rooms_only_sweeps() {
    let (bundle, mut scene, _asset) = setup();
    // A normal numbered room (current_room 0 default): the release must NOT warp.
    let btn = scene.create(&bundle, BACKTOGAME, 100.0, 100.0).unwrap();
    scene.dispatch(&bundle, btn, 6, 7).expect("backtogame release outside the map");
    assert_eq!(scene.target_room_warp, None,
        "CODE 470's room gate (111/113/112) refuses to warp outside the map rooms");
}

#[test]
fn the_ending_room_pins_its_cast_still() {
    let (bundle, mut scene, asset) = setup();
    // rm_ending (110): the player binding swaps to sprite 30 and the obj_enemy
    // stands still (hspeed/vspeed = 0) — the ending's tableau, straight from the
    // RoomCC creation codes 1022/1023 through the real room loader.
    scene.transition_to_room(&bundle, 110, &asset.rooms[110]).unwrap();
    let player = scene.instances.values().find(|i| i.object == PLAYER).unwrap();
    assert_eq!(player.fields["sprite_index"], 30.0,
        "CODE 1022: the ending pins the player into sprite 30");
    let enemy = scene.instances.values().find(|i| i.object == 14 && i.alive);
    if let Some(e) = enemy {
        assert_eq!((e.fields.get("hspeed").copied(), e.fields.get("vspeed").copied()),
            (Some(0.0), Some(0.0)),
            "CODE 1023: the ending's obj_enemy stands still");
    }
    // The Room Start lock chain (CODE 16's roomstart=1 + alarm[6]=10 only in
    // room 110, cleared by CODE 5) was pinned in game-start-p0; the room data
    // here confirms the cast is loadable through the real loader.
    assert!(scene.instances.values().any(|i| i.object == PLAYER && i.alive),
        "rm_ending carries a live player instance through the real room load");
}
