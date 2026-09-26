//! rm_level12 (room 16) enemy phase verification.
//!
//! This batch stays at the original bytecode/IR boundary: it verifies the
//! room's bat and shooter initial state, the shooter2 line-of-sight firing
//! contract, and the bat sleep/wake phase transition. It does not claim
//! Android/GPU animation parity.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WALL: i32 = 4;
const PAR_WALL: i32 = 34;
const WARP: i32 = 69;
const BAT: i32 = 31;
const SHOOTER1: i32 = 16;
const SHOOTER2: i32 = 20;
const BULLET2: i32 = 48;

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
        .expect("portal");
    let (x, y) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, x).unwrap();
    s.write(player, -1, "y", None, y).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    let target = s.target_room_warp.take().expect("warp target");
    s.transition_to_room(bundle, target, &asset.rooms[target]).unwrap();
}

fn level12() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

fn ids(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter().filter(|(_, i)| i.object == object && i.alive).map(|(id, _)| *id).collect()
}

fn clear_enemies(s: &mut Scene, player: i32, keep: i32) {
    let other_ids: Vec<i32> = s.instances.iter()
        .filter(|(id, i)| i.alive && i.active && **id != keep && [14, 15, 16, 20, 23, 31].contains(&i.object))
        .map(|(id, _)| *id).collect();
    for id in other_ids {
        s.write(id, -1, "x", None, 6000.0).unwrap();
        s.write(id, -1, "y", None, 6000.0).unwrap();
        s.write(id, -1, "hspeed", None, 0.0).unwrap();
        s.write(id, -1, "vspeed", None, 0.0).unwrap();
        s.write(id, -1, "gravity", None, 0.0).unwrap();
    }
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
}

#[test]
fn level12_bat_and_gunners_load_with_original_initial_phases() {
    let (_bundle, s, _player, _asset) = level12();
    assert_eq!(ids(&s, BAT).len(), 7);
    assert_eq!(ids(&s, SHOOTER1).len(), 1);
    assert_eq!(ids(&s, SHOOTER2).len(), 1);
    for id in ids(&s, BAT) {
        let i = &s.instances[&id];
        assert_eq!(i.fields["awake"], 0.0, "bat starts asleep");
        assert_eq!(i.fields["moving"], 0.0, "bat starts stationary");
        assert_eq!(i.fields["sprite_index"], 66.0, "bat starts with sleep sprite");
        assert_eq!(i.alarms[7], 30, "bat wake probe cadence");
    }
    let shooter1 = ids(&s, SHOOTER1)[0];
    assert!(s.instances[&shooter1].fields["facing"] == 0.0 || s.instances[&shooter1].fields["facing"] == 1.0,
        "shooter1 initial facing remains a valid binary direction");
    assert_eq!(s.instances[&shooter1].alarms[0], -1);
    let shooter2 = ids(&s, SHOOTER2)[0];
    assert!(s.instances[&shooter2].fields["facing"] == 0.0 || s.instances[&shooter2].fields["facing"] == 1.0,
        "shooter2 initial facing remains a valid binary direction");
    assert_eq!(s.instances[&shooter2].alarms[1], 60, "shooter2 first shot cadence");
}

#[test]
fn level12_bat_wakes_after_the_original_distance_and_height_probe() {
    let (bundle, mut s, player, _asset) = level12();
    let bat = ids(&s, BAT)[0];
    clear_enemies(&mut s, player, bat);
    let bx = s.instances[&bat].fields["x"];
    let by = s.instances[&bat].fields["y"];
    s.write(player, -1, "x", None, bx).unwrap();
    s.write(player, -1, "y", None, by + 100.0).unwrap();
    s.write(bat, -1, "alarm", Some(7), 1.0).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&bat].fields["awake"], 1.0, "player is within 150px and below bat");
    assert_eq!(s.instances[&bat].alarms[7], 30, "wake probe rearms itself");
    assert_eq!(s.instances[&bat].fields["moving"], 0.0, "wake probe alone does not start flight");
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&bat].fields["moving"], 1.0, "next Step arms the bat flight phase");
    assert_eq!(s.instances[&bat].fields["sprite_index"], 67.0, "flight sprite");
}

#[test]
fn level12_shooter2_uses_clear_los_before_spawning_bullet_two() {
    let (bundle, mut s, player, _asset) = level12();
    let shooter = ids(&s, SHOOTER2)[0];
    clear_enemies(&mut s, player, shooter);
    let sx = 800.0;
    let sy = 400.0;
    s.write(shooter, -1, "x", None, sx).unwrap();
    s.write(shooter, -1, "y", None, sy).unwrap();
    s.write(player, -1, "x", None, sx - 400.0).unwrap();
    s.write(player, -1, "y", None, sy).unwrap();
    s.write(shooter, -1, "hpshooter2", None, 50.0).unwrap();
    let blocker = s.create(&bundle, WALL, sx - 200.0, sy).unwrap();
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    assert!(s.instances.keys().filter(|id| !before.contains(id)).all(|id| s.instances[id].object != BULLET2),
        "blocked collision_line suppresses the volley");
    assert_eq!(s.instances[&shooter].alarms[1], 30, "blocked volley still rearms choose cadence");
    let _ = s.destroy(&bundle, blocker);
    let remaining_blockers: Vec<i32> = s.instances.iter()
        .filter(|(_, i)| i.alive && [4, 5, 6].contains(&i.object))
        .map(|(id, _)| *id).collect();
    for id in remaining_blockers {
        let _ = s.destroy(&bundle, id);
    }
    let clear = s.call(&bundle, shooter, "collision_line", &[sx, sy, sx - 400.0, sy, PAR_WALL as f64, 1.0, 1.0]).unwrap();
    assert_eq!(clear, -4.0, "the fixture has restored a genuinely clear line");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    let bullet = s.instances.keys().filter(|id| !before.contains(id) && s.instances[id].object == BULLET2).copied().next().expect("clear LOS fires bullet2");
    assert!(s.instances[&bullet].fields["x"] == sx - 5.0 || s.instances[&bullet].fields["x"] == sx + 5.0,
        "clear LOS fires from one of the two original muzzle positions");
    assert_eq!(s.instances[&bullet].fields["y"], sy + 11.0);
    let bullet_speed = s.instances[&bullet].fields["hspeed"];
    assert!(bullet_speed == -10.0 || bullet_speed == 10.0,
        "clear LOS fires with one of the two original horizontal speeds");
    assert_eq!(bullet_speed, if s.instances[&bullet].fields["x"] == sx - 5.0 { -10.0 } else { 10.0 },
        "muzzle side and projectile speed remain paired");
}
