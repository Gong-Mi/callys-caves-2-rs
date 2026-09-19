//! rm_level13 (room 17) and rm_level13a (room 18) branch verification.
//!
//! This batch verifies the real room-to-room warp chain and asset-derived casts
//! after rm_level12. Enemy behavior is covered by the existing obj_slime and
//! obj_bat contracts; this file only establishes the next topology slice.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const BAT: i32 = 31;
const SLIME: i32 = 32;
const KNIFEBANDIT: i32 = 15;
const SPIKES: i32 = 8;
const CHEST: i32 = 100;
const PLATFORM: i32 = 7;
const WATERSURFACE: i32 = 9;
const WATERFILL: i32 = 10;
const COIN: i32 = 58;

fn load_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sp.width as f64,
            height: sp.height as f64,
            origin_x: sp.origin_x as f64,
            origin_y: sp.origin_y as f64,
            frames: sp.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load town");
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("town -> level1");
    s.view_positions.insert(0, (0.0, 0.0));
    let player = s.instances.iter()
        .find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, s, player, asset)
}

fn walk_portal(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, want_room: f64) {
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(want_room))
        .map(|(id, _)| *id)
        .expect("portal with requested target room");
    let (x, y) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, x).unwrap();
    s.write(player, -1, "y", None, y).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    let target = s.target_room_warp.take().expect("CODE 13 warp target");
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("room transition");
}

fn cast(s: &Scene, object: i32) -> usize {
    s.instances.iter().filter(|(_, i)| i.object == object && i.alive).count()
}

fn doors(s: &Scene) -> Vec<(f64, f64, f64)> {
    s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect()
}

fn level13() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn level13_room_and_forward_branch_are_asset_exact() {
    let (bundle, mut s, player, asset) = level13();
    assert_eq!(s.current_room, 17.0, "rm_level13");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 268.0));
    assert_eq!(cast(&s, BAT), 2);
    assert_eq!(cast(&s, SLIME), 2);
    assert_eq!(cast(&s, KNIFEBANDIT), 3);
    assert_eq!(cast(&s, SPIKES), 5);
    assert_eq!(cast(&s, CHEST), 0);
    assert_eq!(cast(&s, PLATFORM), 3);
    assert_eq!(cast(&s, WATERSURFACE), 12);
    assert_eq!(cast(&s, WATERFILL), 3);
    assert_eq!(cast(&s, COIN), 20);
    assert!(doors(&s).contains(&(16.0, 1888.0, 524.0)), "CODE 837 returns to rm_level12");
    assert!(doors(&s).contains(&(18.0, 128.0, 236.0)), "CODE 838 opens rm_level13a");

    walk_portal(&bundle, &mut s, &asset, player, 18.0);
    assert_eq!(s.current_room, 18.0, "rm_level13a");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 236.0));
    assert_eq!(cast(&s, KNIFEBANDIT), 5);
    assert_eq!(cast(&s, CHEST), 5);
    assert_eq!(cast(&s, PLATFORM), 10);
    assert_eq!(cast(&s, WATERSURFACE), 56);
    assert_eq!(cast(&s, WATERFILL), 1);
    assert_eq!(cast(&s, COIN), 22);
    assert!(doors(&s).contains(&(19.0, 128.0, 236.0)), "CODE 839 opens rm_level14");
    assert!(doors(&s).contains(&(17.0, 864.0, 1164.0)), "CODE 840 returns to rm_level13");
}

#[test]
fn reverse_branch_returns_to_level13_spawn() {
    let (bundle, mut s, player, asset) = level13();
    walk_portal(&bundle, &mut s, &asset, player, 18.0);
    walk_portal(&bundle, &mut s, &asset, player, 17.0);
    assert_eq!(s.current_room, 17.0);
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (864.0, 1164.0));
    assert_eq!(cast(&s, BAT), 2);
    assert_eq!(cast(&s, SLIME), 2);
}
