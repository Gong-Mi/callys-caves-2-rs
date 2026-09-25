//! rm_level17 (room 25) and rm_level17a (room 26) branch verification.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const ENEMY: i32 = 14;
const KNIFEBANDIT: i32 = 15;
const SHOOTER1: i32 = 16;
const SHOOTER2: i32 = 20;
const SLIME: i32 = 32;
const WOLF: i32 = 23;
const BAT: i32 = 31;
const BOULDER: i32 = 6;
const COIN: i32 = 58;
const PLATFORM: i32 = 7;
const TREASURE_CHEST: i32 = 100;
const WOODBLOCK: i32 = 158;

fn load_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset_path = root.join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
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

fn level17() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn level17_room_and_forward_branch_are_asset_exact() {
    let (bundle, mut s, player, asset) = level17();
    assert_eq!(s.current_room, 25.0, "rm_level17");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&s, ENEMY), 3);
    assert_eq!(cast(&s, KNIFEBANDIT), 3);
    assert_eq!(cast(&s, SHOOTER1), 2);
    assert_eq!(cast(&s, SHOOTER2), 1);
    assert_eq!(cast(&s, SLIME), 4);
    assert_eq!(cast(&s, WOLF), 2);
    assert_eq!(cast(&s, BOULDER), 343);
    assert_eq!(cast(&s, COIN), 18);
    assert_eq!(cast(&s, TREASURE_CHEST), 4);
    assert_eq!(cast(&s, WOODBLOCK), 5);
    assert!(doors(&s).contains(&(24.0, 672.0, 1484.0)), "CODE 853 returns to rm_level16a");
    assert!(doors(&s).contains(&(26.0, 128.0, 204.0)), "CODE 854 opens rm_level17a");

    walk_portal(&bundle, &mut s, &asset, player, 26.0);
    assert_eq!(s.current_room, 26.0, "rm_level17a");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&s, BAT), 5);
    assert_eq!(cast(&s, KNIFEBANDIT), 1);
    assert_eq!(cast(&s, BOULDER), 184);
    assert_eq!(cast(&s, COIN), 27);
    assert_eq!(cast(&s, PLATFORM), 1);
    assert!(doors(&s).contains(&(25.0, 1920.0, 1164.0)), "CODE 855 returns to rm_level17");
    assert!(doors(&s).contains(&(27.0, 128.0, 140.0)), "CODE 856 opens rm_boss2");
}

#[test]
fn reverse_branch_returns_to_level17_spawn() {
    let (bundle, mut s, player, asset) = level17();
    walk_portal(&bundle, &mut s, &asset, player, 26.0);
    walk_portal(&bundle, &mut s, &asset, player, 25.0);
    assert_eq!(s.current_room, 25.0);
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (1920.0, 1164.0));
    assert_eq!(cast(&s, ENEMY), 3);
    assert_eq!(cast(&s, BOULDER), 343);
}
