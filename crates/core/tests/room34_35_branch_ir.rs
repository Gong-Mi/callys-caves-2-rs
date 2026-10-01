//! room34-35 (asset rooms 31-32) post-Boss2 branch chain, second segment.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const ENEMY: i32 = 14;
const KNIFEBANDIT: i32 = 15;
const SKELETON: i32 = 17;
const ZOMBIE: i32 = 19;
const BAT: i32 = 31;
const FIRESLIME: i32 = 33;
const BOULDER: i32 = 6;
const PLATFORM: i32 = 7;
const COIN: i32 = 58;
const GEM: i32 = 59;
const WATERSURFACE: i32 = 9;
const WATERFILL: i32 = 10;
const TREASURE_CHEST: i32 = 100;
const BOULDERBLOCK: i32 = 156;
const WOODBLOCK: i32 = 158;
const WEAPONSWAP: i32 = 126;
const TRIGGERINTRO: i32 = 186;

fn load_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).expect("parse game.droid");
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();
    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sp.width as f64, height: sp.height as f64,
            origin_x: sp.origin_x as f64, origin_y: sp.origin_y as f64,
            frames: sp.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load town");
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("town -> level1");
    s.view_positions.insert(0, (0.0, 0.0));
    let player = s.instances.iter().find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id).expect("persistent player");
    (bundle, s, player, asset)
}

fn walk_portal(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, want_room: f64) {
    let portal = s.instances.iter().filter(|(_, i)| i.object == WARP && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(want_room))
        .map(|(id, _)| *id).expect("portal with requested target room");
    let (x, y) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, x).unwrap();
    s.write(player, -1, "y", None, y).unwrap();
    for _ in 0..3 { s.tick(bundle).unwrap(); if s.target_room_warp.is_some() { break; } }
    let target = s.target_room_warp.take().expect("CODE 13 warp target");
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("room transition");
}

fn cast(s: &Scene, object: i32) -> usize {
    s.instances.iter().filter(|(_, i)| i.object == object && i.alive).count()
}

fn doors(s: &Scene) -> Vec<(f64, f64, f64)> {
    s.instances.iter().filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"])).collect()
}

/// Walk the whole pre-Boss2 chain, then the room31-33 segment from 27 up to 30.
fn reach_room30() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn room34_cast_matches_asset_and_doors_are_unlocked() {
    let (bundle, mut s, player, asset) = reach_room30();
    walk_portal(&bundle, &mut s, &asset, player, 31.0);
    assert_eq!(s.current_room, 31.0, "room34");
    // CODE 864 landing (128,204).
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 204.0));

    assert_eq!(cast(&s, ENEMY), 3);
    assert_eq!(cast(&s, KNIFEBANDIT), 2);
    assert_eq!(cast(&s, ZOMBIE), 2);
    assert_eq!(cast(&s, FIRESLIME), 4);
    assert_eq!(cast(&s, BOULDER), 181);
    assert_eq!(cast(&s, PLATFORM), 3);
    assert_eq!(cast(&s, COIN), 15);
    assert_eq!(cast(&s, TREASURE_CHEST), 13);
    assert_eq!(cast(&s, BOULDERBLOCK), 3);
    assert_eq!(cast(&s, WOODBLOCK), 4);
    assert_eq!(cast(&s, WEAPONSWAP), 1, "room34 has the weapon swap pad");

    assert!(doors(&s).contains(&(32.0, 128.0, 268.0)), "CODE 865 opens room35");
    assert!(doors(&s).contains(&(30.0, 896.0, 140.0)), "CODE 867 returns to room33");
}

#[test]
fn room34_to_room35_forward_chain_is_asset_exact() {
    let (bundle, mut s, player, asset) = reach_room30();
    walk_portal(&bundle, &mut s, &asset, player, 31.0);
    // CODE 865 -> room35, landing (128,268).
    walk_portal(&bundle, &mut s, &asset, player, 32.0);
    assert_eq!(s.current_room, 32.0, "room35");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 268.0));

    assert_eq!(cast(&s, SKELETON), 2);
    assert_eq!(cast(&s, BAT), 1);
    assert_eq!(cast(&s, FIRESLIME), 2);
    assert_eq!(cast(&s, BOULDER), 119);
    assert_eq!(cast(&s, PLATFORM), 23);
    assert_eq!(cast(&s, WATERSURFACE), 62);
    assert_eq!(cast(&s, WATERFILL), 3);
    assert_eq!(cast(&s, COIN), 19);
    assert_eq!(cast(&s, GEM), 1, "room35 holds a gem");
    assert_eq!(cast(&s, TREASURE_CHEST), 1);
    assert_eq!(cast(&s, WEAPONSWAP), 1);
    assert_eq!(cast(&s, TRIGGERINTRO), 2);

    assert!(doors(&s).contains(&(31.0, 1440.0, 172.0)), "CODE 868 returns to room34");
    assert!(doors(&s).contains(&(33.0, 160.0, 204.0)), "CODE 869 opens room36");
}

#[test]
fn room35_to_room36_door_chain_continues() {
    let (bundle, mut s, player, asset) = reach_room30();
    walk_portal(&bundle, &mut s, &asset, player, 31.0);
    walk_portal(&bundle, &mut s, &asset, player, 32.0);
    // CODE 869 -> room36, landing (160,204).
    walk_portal(&bundle, &mut s, &asset, player, 33.0);
    assert_eq!(s.current_room, 33.0, "room36");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (160.0, 204.0));

    assert!(doors(&s).contains(&(34.0, 128.0, 1932.0)), "CODE 870 opens room37");
    assert!(doors(&s).contains(&(32.0, 1888.0, 236.0)), "CODE 871 returns to room35");
}
