//! Verification of rm_level12 (room 16) in the Mines:
//! 1. Portal link: rm_level11a's CODE 834 lands in rm_level12 at (128, 204).
//! 2. Room cast: 7 bats, 1 shooter1, 1 shooter2, 2 treasure chests, 2 platforms,
//!    18 watersurfaces, 3 waterfills, 28 coins, 2 warp doors (CODE 835 -> rm_level11a, CODE 836 -> rm_level13).
//! 3. Platform theming: obj_platform (7) Create (CODE 33) dynamically selects
//!    sprite 24 (spr_platform2 / Mines style) for room 16.
//! 4. Forward portal link: CODE 836 opens rm_level13 (room 17) at spawn (128, 268).
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const BAT: i32 = 31;
const SHOOTER1: i32 = 16;
const SHOOTER2: i32 = 20;
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
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
    }
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load rm_town");
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
        .expect("portal instance with pinned warproom");
    let (px, py) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    let target = s.target_room_warp.take().expect("CODE 13 warp");
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("portal transition");
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

fn doors(s: &Scene) -> Vec<(f64, f64, f64)> {
    s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect()
}

/// Navigate rm_town -> ... -> rm_level11a (15) -> rm_level12 (16).
fn level12_room() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn the_level12_room_opens_from_level11a() {
    let (_bundle, s, player, _asset) = level12_room();
    assert_eq!(s.current_room, 16.0, "CODE 834 lands in rm_level12 (room 16)");
    assert_eq!(
        (s.instances[&player].fields["x"], s.instances[&player].fields["y"]),
        (128.0, 204.0),
        "CODE 834 pinned spawn coordinate"
    );

    // Verify cast counts matching asset extraction
    assert_eq!(cast(&s, BAT).len(), 7, "seven obj_bat in rm_level12");
    assert_eq!(cast(&s, SHOOTER1).len(), 1, "one obj_shooter1");
    assert_eq!(cast(&s, SHOOTER2).len(), 1, "one obj_shooter2");
    assert_eq!(cast(&s, CHEST).len(), 2, "two obj_treasurechest");
    assert_eq!(cast(&s, PLATFORM).len(), 2, "two obj_platform");
    assert_eq!(cast(&s, WATERSURFACE).len(), 18, "eighteen obj_watersurface");
    assert_eq!(cast(&s, WATERFILL).len(), 3, "three obj_waterfill");
    assert_eq!(cast(&s, COIN).len(), 28, "twenty-eight obj_coin");

    // Check doors
    let room_doors = doors(&s);
    assert!(room_doors.contains(&(15.0, 1856.0, 1164.0)), "CODE 835 returns to rm_level11a");
    assert!(room_doors.contains(&(17.0, 128.0, 268.0)), "CODE 836 leads to rm_level13");
}

#[test]
fn platform_create_selects_mines_sprite_theme() {
    let (_bundle, s, _player, _asset) = level12_room();
    let platforms = cast(&s, PLATFORM);
    assert_eq!(platforms.len(), 2, "two platforms in level 12");
    for plat_id in platforms {
        let sprite = s.instances[&plat_id].fields.get("sprite_index").copied().unwrap_or(0.0);
        assert_eq!(sprite, 24.0, "CODE 33 assigns sprite 24 (spr_platform2) in Mines (room 16)");
        let ptype = s.instances[&plat_id].fields.get("type").copied().unwrap_or(0.0);
        assert_eq!(ptype, 2.0, "CODE 33 assigns type = 2");
    }
}

#[test]
fn forward_portal_leads_to_level13() {
    let (bundle, mut s, player, asset) = level12_room();
    // Take CODE 836 portal to rm_level13 (room 17)
    walk_portal(&bundle, &mut s, &asset, player, 17.0);
    assert_eq!(s.current_room, 17.0, "portal leads to rm_level13");
    assert_eq!(
        (s.instances[&player].fields["x"], s.instances[&player].fields["y"]),
        (128.0, 268.0),
        "CODE 836 pinned spawn coordinate in rm_level13"
    );
    // Assert rm_level13 key objects
    assert_eq!(cast(&s, BAT).len(), 2, "two obj_bat in rm_level13");
    assert_eq!(cast(&s, 32).len(), 2, "two obj_slime in rm_level13");
    assert_eq!(cast(&s, 15).len(), 3, "three obj_knifebandit in rm_level13");
    assert_eq!(cast(&s, 8).len(), 5, "five obj_spikes in rm_level13");
}
