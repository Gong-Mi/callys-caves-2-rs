//! room36-37 (asset rooms 33-34) post-Boss2 branch chain, third segment.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const SPIKES: i32 = 8;
const KNIFEBANDIT: i32 = 15;
const SHOOTER1: i32 = 16;
const SKELETON: i32 = 17;
const ZOMBIE: i32 = 19;
const ENEMY2: i32 = 22;
const SHOOTER2: i32 = 20;
const WOLF: i32 = 23;
const BAT: i32 = 31;
const SLIME: i32 = 32;
const FIRESLIME: i32 = 33;
const BOULDER: i32 = 6;
const PLATFORM: i32 = 7;
const WATERSURFACE: i32 = 9;
const WATERFILL: i32 = 10;
const COIN: i32 = 58;
const TREASURE_CHEST: i32 = 100;
const BOULDERBLOCK: i32 = 156;
const WOODBLOCK: i32 = 158;
const WEAPONSWAP: i32 = 126;

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

/// Walk the pre-Boss2 chain plus the 27..32 back-branch to enter room36.
fn reach_room36() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    walk_portal(&bundle, &mut s, &asset, player, 33.0);
    (bundle, s, player, asset)
}

#[test]
fn room36_cast_matches_asset_and_doors_are_unlocked() {
    let (bundle, mut s, player, asset) = reach_room36();
    assert_eq!(s.current_room, 33.0, "room36");
    // CODE 869 landing (160,204).
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (160.0, 204.0));

    assert_eq!(cast(&s, SHOOTER1), 1);
    assert_eq!(cast(&s, SKELETON), 1);
    assert_eq!(cast(&s, ZOMBIE), 5);
    assert_eq!(cast(&s, ENEMY2), 1);
    assert_eq!(cast(&s, BAT), 2);
    assert_eq!(cast(&s, SLIME), 1);
    assert_eq!(cast(&s, FIRESLIME), 2);
    assert_eq!(cast(&s, BOULDER), 296);
    assert_eq!(cast(&s, PLATFORM), 3);
    assert_eq!(cast(&s, WATERSURFACE), 17);
    assert_eq!(cast(&s, WATERFILL), 4);
    assert_eq!(cast(&s, COIN), 22);
    assert_eq!(cast(&s, TREASURE_CHEST), 7);
    assert_eq!(cast(&s, BOULDERBLOCK), 5);
    assert_eq!(cast(&s, WOODBLOCK), 5);
    assert_eq!(cast(&s, WEAPONSWAP), 1);

    assert!(doors(&s).contains(&(34.0, 128.0, 1932.0)), "CODE 870 opens room37");
    assert!(doors(&s).contains(&(32.0, 1888.0, 236.0)), "CODE 871 returns to room35");
}

#[test]
fn room36_to_room37_forward_chain_is_asset_exact() {
    let (bundle, mut s, player, asset) = reach_room36();
    // CODE 870 -> room37, landing (128,1932).
    walk_portal(&bundle, &mut s, &asset, player, 34.0);
    assert_eq!(s.current_room, 34.0, "room37");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 1932.0));

    assert_eq!(cast(&s, KNIFEBANDIT), 1);
    assert_eq!(cast(&s, SHOOTER1), 2);
    assert_eq!(cast(&s, SKELETON), 1);
    assert_eq!(cast(&s, SHOOTER2), 3);
    assert_eq!(cast(&s, WOLF), 1);
    assert_eq!(cast(&s, BAT), 1);
    assert_eq!(cast(&s, BOULDER), 294);
    assert_eq!(cast(&s, SPIKES), 6);
    assert_eq!(cast(&s, WATERSURFACE), 9);
    assert_eq!(cast(&s, WATERFILL), 3);
    assert_eq!(cast(&s, COIN), 24);

    assert!(doors(&s).contains(&(35.0, 128.0, 428.0)), "CODE 872 opens room38");
    assert!(doors(&s).contains(&(33.0, 1888.0, 684.0)), "CODE 873 returns to room36");
}

#[test]
fn room37_to_room38_door_chain_continues() {
    let (bundle, mut s, player, asset) = reach_room36();
    walk_portal(&bundle, &mut s, &asset, player, 34.0);
    // CODE 872 -> room38, landing (128,428).
    walk_portal(&bundle, &mut s, &asset, player, 35.0);
    assert_eq!(s.current_room, 35.0, "room38");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 428.0));

    assert!(doors(&s).contains(&(36.0, 160.0, 204.0)), "CODE 874 opens next segment");
    assert!(doors(&s).contains(&(34.0, 512.0, 172.0)), "CODE 875 returns to room37");
}
