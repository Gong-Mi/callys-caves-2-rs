//! rm_level15 (room 21) and rm_level15a (room 22) branch verification.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const KNIFEBANDIT: i32 = 15;
const SHOOTER1: i32 = 16;
const SHOOTER2: i32 = 20;
const SLIME: i32 = 32;
const BAT: i32 = 31;
const BOULDER: i32 = 6;
const COIN: i32 = 58;
const PLATFORM: i32 = 7;
const WATERSURFACE: i32 = 9;
const WATERFILL: i32 = 10;
const TREASURE_CHEST: i32 = 100;
const WOODBLOCK: i32 = 158;

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

fn level15() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn level15_room_and_forward_branch_are_asset_exact() {
    let (bundle, mut s, player, asset) = level15();
    assert_eq!(s.current_room, 21.0, "rm_level15");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (160.0, 684.0));
    assert_eq!(cast(&s, KNIFEBANDIT), 6);
    assert_eq!(cast(&s, SHOOTER2), 2);
    assert_eq!(cast(&s, SLIME), 1);
    assert_eq!(cast(&s, BOULDER), 250);
    assert_eq!(cast(&s, COIN), 23);
    assert_eq!(cast(&s, PLATFORM), 9);
    assert_eq!(cast(&s, WATERFILL), 1);
    assert_eq!(cast(&s, WATERSURFACE), 6);
    assert_eq!(cast(&s, TREASURE_CHEST), 6);
    assert_eq!(cast(&s, WOODBLOCK), 9);
    assert!(doors(&s).contains(&(20.0, 1856.0, 364.0)), "CODE 845 returns to rm_level14a");
    assert!(doors(&s).contains(&(22.0, 128.0, 204.0)), "CODE 846 opens rm_level15a");

    walk_portal(&bundle, &mut s, &asset, player, 22.0);
    assert_eq!(s.current_room, 22.0, "rm_level15a");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&s, BAT), 5);
    assert_eq!(cast(&s, SHOOTER1), 1);
    assert_eq!(cast(&s, SLIME), 4);
    assert_eq!(cast(&s, BOULDER), 129);
    assert_eq!(cast(&s, COIN), 10);
    assert_eq!(cast(&s, PLATFORM), 2);
    assert_eq!(cast(&s, WATERFILL), 0);
    assert_eq!(cast(&s, WATERSURFACE), 0);
    assert_eq!(cast(&s, TREASURE_CHEST), 3);
    assert_eq!(cast(&s, WOODBLOCK), 3);
    assert!(doors(&s).contains(&(23.0, 128.0, 204.0)), "CODE 847 opens rm_level16");
    assert!(doors(&s).contains(&(21.0, 1888.0, 684.0)), "CODE 848 returns to rm_level15");
}

#[test]
fn reverse_branch_returns_to_level15_spawn() {
    let (bundle, mut s, player, asset) = level15();
    walk_portal(&bundle, &mut s, &asset, player, 22.0);
    walk_portal(&bundle, &mut s, &asset, player, 21.0);
    assert_eq!(s.current_room, 21.0);
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (1888.0, 684.0));
    assert_eq!(cast(&s, KNIFEBANDIT), 6);
    assert_eq!(cast(&s, BOULDER), 250);
}
