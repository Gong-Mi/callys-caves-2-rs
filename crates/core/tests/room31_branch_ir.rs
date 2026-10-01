//! room31-33 (rooms 28-30) post-Boss2 branch chain verification.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const ENEMY: i32 = 14;
const KNIFEBANDIT: i32 = 15;
const SHOOTER1: i32 = 16;
const ZOMBIE: i32 = 19;
const SHOOTER2: i32 = 20;
const BAT: i32 = 31;
const SLIME: i32 = 32;
const FIRESLIME: i32 = 33;
const BOULDER: i32 = 6;
const COIN: i32 = 58;
const PLATFORM: i32 = 7;
const SPIKES: i32 = 8;
const TREASURE_CHEST: i32 = 100;
const WOODBLOCK: i32 = 158;
const PICKUP_FLARE: i32 = 70;
const BOOMERANG: i32 = 71;

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

fn boss2_room() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn room31_through_room33_forward_chain_is_asset_exact() {
    let (bundle, mut s, player, asset) = boss2_room();
    assert_eq!(s.current_room, 27.0, "rm_boss2");

    // CODE 858 (own 1216,352) -> room31, landing (128,204).
    walk_portal(&bundle, &mut s, &asset, player, 28.0);
    assert_eq!(s.current_room, 28.0, "room31");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&s, SHOOTER1), 2);
    assert_eq!(cast(&s, ZOMBIE), 8);
    assert_eq!(cast(&s, SLIME), 3);
    assert_eq!(cast(&s, BOULDER), 154);
    assert_eq!(cast(&s, COIN), 13);
    assert_eq!(cast(&s, PLATFORM), 6);
    assert_eq!(cast(&s, SPIKES), 3);
    assert_eq!(cast(&s, TREASURE_CHEST), 9);
    assert_eq!(cast(&s, WOODBLOCK), 6);
    assert!(doors(&s).contains(&(27.0, 1152.0, 364.0)), "CODE 859 returns to rm_boss2");
    assert!(doors(&s).contains(&(29.0, 128.0, 236.0)), "CODE 860 opens room32");

    // CODE 860 -> room32, landing (128,236).
    walk_portal(&bundle, &mut s, &asset, player, 29.0);
    assert_eq!(s.current_room, 29.0, "room32");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 236.0));
    assert_eq!(cast(&s, KNIFEBANDIT), 1);
    assert_eq!(cast(&s, SHOOTER1), 1);
    assert_eq!(cast(&s, ZOMBIE), 2);
    assert_eq!(cast(&s, SHOOTER2), 1);
    assert_eq!(cast(&s, BAT), 3);
    assert_eq!(cast(&s, SLIME), 1);
    assert_eq!(cast(&s, BOULDER), 75);
    assert_eq!(cast(&s, COIN), 24);
    assert!(doors(&s).contains(&(30.0, 128.0, 1164.0)), "CODE 861 opens room33");
    assert!(doors(&s).contains(&(28.0, 1888.0, 684.0)), "CODE 862 returns to room31");

    // CODE 861 -> room33, landing (128,1164).
    walk_portal(&bundle, &mut s, &asset, player, 30.0);
    assert_eq!(s.current_room, 30.0, "room33");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 1164.0));
    assert_eq!(cast(&s, ENEMY), 2);
    assert_eq!(cast(&s, KNIFEBANDIT), 3);
    assert_eq!(cast(&s, SHOOTER1), 3);
    assert_eq!(cast(&s, FIRESLIME), 1);
    assert_eq!(cast(&s, BOULDER), 222);
    assert_eq!(cast(&s, COIN), 18);
    assert_eq!(cast(&s, PLATFORM), 7);
    assert_eq!(cast(&s, SPIKES), 4);
    assert_eq!(cast(&s, TREASURE_CHEST), 6);
    assert_eq!(cast(&s, WOODBLOCK), 6);
    assert_eq!(cast(&s, PICKUP_FLARE), 1);
    assert_eq!(cast(&s, BOOMERANG), 1);
    assert!(doors(&s).contains(&(29.0, 1888.0, 236.0)), "CODE 863 returns to room32");
    assert!(doors(&s).contains(&(31.0, 128.0, 204.0)), "CODE 864 opens room34");
}

#[test]
fn reverse_branch_returns_to_boss2_spawn_with_cast_respawn() {
    let (bundle, mut s, player, asset) = boss2_room();
    walk_portal(&bundle, &mut s, &asset, player, 28.0);
    walk_portal(&bundle, &mut s, &asset, player, 29.0);
    walk_portal(&bundle, &mut s, &asset, player, 30.0);
    // CODE 863 -> back to room32 (1888,236).
    walk_portal(&bundle, &mut s, &asset, player, 29.0);
    assert_eq!(s.current_room, 29.0);
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (1888.0, 236.0));
    assert_eq!(cast(&s, ZOMBIE), 2);
    assert_eq!(cast(&s, BAT), 3);
    // CODE 862 -> back to room31 (1888,684).
    walk_portal(&bundle, &mut s, &asset, player, 28.0);
    assert_eq!(s.current_room, 28.0);
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (1888.0, 684.0));
    assert_eq!(cast(&s, ZOMBIE), 8);
    assert_eq!(cast(&s, TREASURE_CHEST), 9);
    // CODE 859 -> back to rm_boss2 (1152,364), Boss2 cast re-materializes.
    walk_portal(&bundle, &mut s, &asset, player, 27.0);
    assert_eq!(s.current_room, 27.0);
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (1152.0, 364.0));
    assert_eq!(cast(&s, 26), 1, "obj_boss2 respawns");
    assert_eq!(cast(&s, 3), 8, "obj_bossboulder respawns");
}
