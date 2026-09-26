//! Map system batch: obj_maptile (160, CODE 690-693) — the fog-of-war map
//! tiles bound in rm_map/rm_mapview0/rm_mapview3 (CODE 1024-1352), obj_mapmenu
//! (111, CODE 476/477) — the resolution-based map view selector, and the map
//! warp flow: tile tap -> room_goto(goto), warpfrommap=1, player at startx/y.
//! Every asserted value comes from the static decode of the full_ir.json
//! bytecode plus live probes on this host; scratch probes are deleted.
//!
//! Static decode pinned first (contract reconstruction/contracts/map-system.md):
//! - all 109 distinct map tiles share the SAME code shape: 'if {room}visited == 0
//!   -> instance_destroy; goto = N' — the visited global is the fog gate;
//! - rm_map(111) / rm_mapview0(113) / rm_mapview3(112) tiles are the same 109
//!   goto values x3 (three zoom levels of the same map);
//! - mapmenu Mouse_7 (CODE 476) selects the view room by WINDOW RESOLUTION
//!   (16 branches: 960x640/1280x800/2560x1600/854x480 -> rm_map; 1024x768/
//!   2048x1536 -> mapview3; the rest -> mapview0) — the host's display size
//!   drives which room opens;
//! - maptile Mouse_7 (CODE 692): sweep 15 UI objects, activate_all,
//!   warpfrommap=1, room_goto(goto), then the PLAYER (selector 0) is re-pinned
//!   to global startx/starty — the map remembers where you were standing;
//! - maptile Step (CODE 691): sprite variants 171/172/173 by neighbor adjacency
//!   (road drawing), image_blend 255 highlight when goto == roomcamefrom;
//! - player Create (CODE 0) seeds roomcamefrom; Other_5 (Room End, CODE 15)
//!   re-stamps it — the "you are here" pin follows the real room.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const MAPTILE: i32 = 160;
const MAPMENU: i32 = 111;

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

fn live_tiles(scene: &Scene) -> Vec<(f64, f64)> {
    // (goto, blend) of every live maptile
    scene.instances.values()
        .filter(|i| i.object == MAPTILE && i.alive)
        .map(|i| (
            i.fields.get("goto").copied().unwrap_or(-1.0),
            i.fields.get("image_blend").copied().unwrap_or(-1.0),
        ))
        .collect()
}

#[test]
fn rm_map_fog_of_war_gates_every_tile_on_its_visited_global() {
    let (bundle, mut scene, asset) = setup();
    // Load rm_map with NO visited globals set: every tile must destroy itself.
    scene.transition_to_room(&bundle, 111, &asset.rooms[111]).unwrap();
    assert_eq!(scene.instances.values().filter(|i| i.object == MAPTILE && i.alive).count(), 0,
        "with no visited flags every CODE 1024-1352 tile destroys itself (fog of war)");

    // Load rm_map after "visiting" three representative rooms: the Mines entry
    // (level9 -> goto 11), a numbered room (room42 -> goto 39) and boss6 (goto 104).
    let (bundle, mut scene, asset) = setup();
    scene.globals.insert("level9visited".into(), 1.0);
    scene.globals.insert("room42visited".into(), 1.0);
    scene.globals.insert("boss6visited".into(), 1.0);
    scene.transition_to_room(&bundle, 111, &asset.rooms[111]).unwrap();
    let tiles = live_tiles(&scene);
    let gots: Vec<f64> = tiles.iter().map(|(g, _)| *g).collect();
    for want in [11.0, 39.0, 104.0] {
        assert!(gots.contains(&want), "visiting the room keeps its tile (goto {want}) on the map");
    }
    assert_eq!(gots.len(), 3, "exactly the three visited rooms survive the fog gate");

    // The three zoom levels carry the same 109-tile table: rm_mapview0/3 fog identically.
    let (_, mut scene2, asset2) = setup();
    let mut bundle2 = bundle.clone();
    bundle2.string_table = asset2.string_table.clone();
    scene2.init_bundle(&bundle2);
    scene2.globals.insert("room42visited".into(), 1.0);
    scene2.transition_to_room(&bundle2, 112, &asset2.rooms[112]).unwrap();
    assert_eq!(live_tiles(&scene2).len(), 1, "rm_mapview3 fog-gates the same table");
    let (_, mut scene3, asset3) = setup();
    let mut bundle3 = bundle.clone();
    bundle3.string_table = asset3.string_table.clone();
    scene3.init_bundle(&bundle3);
    scene3.globals.insert("room42visited".into(), 1.0);
    scene3.transition_to_room(&bundle3, 113, &asset3.rooms[113]).unwrap();
    assert_eq!(live_tiles(&scene3).len(), 1, "rm_mapview0 fog-gates the same table");
}

#[test]
fn tapping_a_tile_warps_to_the_room_and_pins_the_player_at_the_saved_start() {
    let (bundle, mut scene, asset) = setup();
    // Two visited rooms with distinct gotos; roomcamefrom highlights one.
    scene.globals.insert("level9visited".into(), 1.0);
    scene.globals.insert("room42visited".into(), 1.0);
    scene.transition_to_room(&bundle, 111, &asset.rooms[111]).unwrap();
    // roomcamefrom == 39: the room42 tile blends 255 (the "you are here" pin).
    scene.globals.insert("roomcamefrom".into(), 39.0);
    for (_, i) in scene.instances.iter().filter(|(_, i)| i.object == MAPTILE && i.alive) {
        let _ = i; // tiles are re-derived below after the Step
    }
    // Dispatch one maptile Step (CODE 691) to apply the highlight + adjacency sprite.
    let tile39 = scene.instances.iter()
        .find(|(_, i)| i.object == MAPTILE && i.alive && i.fields.get("goto") == Some(&39.0))
        .map(|(id, _)| *id).unwrap();
    scene.dispatch(&bundle, tile39, 3, 0).expect("maptile Step");
    assert_eq!(scene.instances[&tile39].fields["image_blend"], 255.0,
        "CODE 691: goto == roomcamefrom highlights the current room's tile");
    assert_eq!(scene.instances[&tile39].fields["sprite_index"], 171.0,
        "an isolated tile (no neighbors in either direction) keeps the plain 171 sprite");

    // The player's saved start position is where the map warp re-lands them.
    // The real game's obj_player is persistent — it survives into rm_map even
    // though the room's own bindings only list obj_maptile; the tile's tap
    // writes player.x/y (selector 0). Mirror that with a live player instance.
    let _player = scene.create(&bundle, PLAYER, 0.0, 0.0).unwrap();
    scene.globals.insert("startx".into(), 4242.0);
    scene.globals.insert("starty".into(), 1717.0);
    // Dispatch the tile's Mouse_7 (tap) event: sweep, activate, warpfrommap, room_goto(goto).
    scene.dispatch(&bundle, tile39, 6, 7).expect("maptile tap");
    assert_eq!(scene.globals["warpfrommap"], 1.0,
        "CODE 692 stamps warpfrommap=1 before the warp");
    assert_eq!(scene.target_room_warp, Some(39),
        "the tap warps to the tile's goto room");
    assert_eq!((scene.instances.values().find(|i| i.object == PLAYER).unwrap().fields.get("x").copied(),
                scene.instances.values().find(|i| i.object == PLAYER).unwrap().fields.get("y").copied()),
        (Some(4242.0), Some(1717.0)),
        "the player (selector 0) is re-pinned to global startx/starty — the map restores your standing spot");
}

#[test]
fn the_map_menu_picks_the_view_room_by_window_resolution() {
    let (bundle, mut scene, _asset) = {
        let (b, s, a) = setup();
        (b, s, a)
    };
    // CODE 476: 16 resolution branches. The host's display_width/height drive the pick.
    // 960x640 -> rm_map(111); 1024x768 -> mapview3(112); 1136x640 -> mapview0(113).
    scene.display_width = 960.0;
    scene.display_height = 640.0;
    let menu = scene.create(&bundle, MAPMENU, 100.0, 100.0).unwrap();
    scene.dispatch(&bundle, menu, 6, 7).expect("mapmenu release");
    assert_eq!(scene.target_room_warp, Some(111),
        "960x640 opens rm_map");
    scene.target_room_warp = None;

    scene.display_width = 1024.0;
    scene.display_height = 768.0;
    scene.dispatch(&bundle, menu, 6, 7).expect("mapmenu release 2");
    assert_eq!(scene.target_room_warp, Some(112),
        "1024x768 opens rm_mapview3");
    scene.target_room_warp = None;

    scene.display_width = 1136.0;
    scene.display_height = 640.0;
    scene.dispatch(&bundle, menu, 6, 7).expect("mapmenu release 3");
    assert_eq!(scene.target_room_warp, Some(113),
        "1136x640 opens rm_mapview0");
    scene.target_room_warp = None;

    // 1280x720 -> 113 per the static table (the modern 16:9 default).
    scene.display_width = 1280.0;
    scene.display_height = 720.0;
    scene.dispatch(&bundle, menu, 6, 7).expect("mapmenu release 4");
    assert_eq!(scene.target_room_warp, Some(113),
        "1280x720 opens rm_mapview0");
}
