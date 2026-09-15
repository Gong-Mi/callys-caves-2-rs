//! rm_boss2 room topology and boss initialization verification.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const BOSS2: i32 = 26;
const BOSS_BOULDER: i32 = 3;
const BOULDER: i32 = 6;
const PLATFORM: i32 = 7;

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

fn boss2_room() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

fn cast(s: &Scene, object: i32) -> usize {
    s.instances.iter().filter(|(_, i)| i.object == object && i.alive).count()
}

fn doors(s: &Scene) -> Vec<(f64, f64, f64)> {
    s.instances.iter().filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"])).collect()
}

#[test]
fn boss2_room_and_doors_are_asset_exact() {
    let (_bundle, s, player, _asset) = boss2_room();
    assert_eq!(s.current_room, 27.0, "rm_boss2");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 140.0));
    assert_eq!(cast(&s, BOSS2), 1);
    assert_eq!(cast(&s, BOSS_BOULDER), 8);
    assert_eq!(cast(&s, BOULDER), 111);
    assert_eq!(cast(&s, PLATFORM), 9);
    assert!(doors(&s).contains(&(26.0, 352.0, 1484.0)), "CODE 857 returns to rm_level17a");
    assert!(doors(&s).contains(&(28.0, 128.0, 204.0)), "CODE 858 opens room31");
}

#[test]
fn boss2_alarm1_emits_three_original_attack_entities_when_room_gate_matches() {
    let (bundle, mut s, _player, _asset) = boss2_room();
    // CODE 167 skips its volley when the original room resource id is 110;
    // the actual asset room index for rm_boss2 is 27, so keep the real room
    // identity here and verify the remaining slime-count gates.
    s.current_room = 27.0;
    let boss = s.instances.iter().find(|(_, i)| i.object == BOSS2 && i.alive)
        .map(|(id, _)| *id).expect("obj_boss2 instance");
    s.dispatch(&bundle, boss, 2, 1).expect("Boss2 Alarm 1");
    let created: Vec<_> = s.instances.iter()
        .filter(|(_, i)| i.object == 32 && i.alive)
        .map(|(id, _)| *id).filter(|id| *id != boss).collect();
    assert_eq!(created.len(), 3, "CODE 167 creates three obj_slime attack entities");
    for id in created {
        assert_eq!(s.instances[&id].alarms[0], 30);
    }
}

#[test]
fn boss2_create_initializes_original_state_for_power_one() {
    let (_bundle, s, _player, _asset) = boss2_room();
    let boss = s.instances.iter().find(|(_, i)| i.object == BOSS2 && i.alive)
        .map(|(id, _)| *id).expect("obj_boss2 instance");
    let i = &s.instances[&boss];
    assert_eq!(i.fields["flashing"], 0.0);
    assert_eq!(i.fields["poisoned"], 0.0);
    assert_eq!(i.fields["swordstunned"], 0.0);
    assert_eq!(i.fields["xpdrop"], 1.0);
    assert_eq!(i.fields["hpdrop"], 1.0);
    assert_eq!(i.fields["hpboss2"], 750.0);
    assert_eq!(i.fields["boss2maxhp"], 750.0);
}
