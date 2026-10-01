//! The Mines' second ranged mould: obj_shooter2 (20), the "trap" gunner of
//! rm_level10 (room 13) and later Mines rooms. It is not a reskin of
//! obj_shooter1: CODE 100 rolls a different HP ladder (50/45/40/35 …
//! 70/65/60/55), CODE 100 arms a slower first shot (alarm[1] = 60), CODE 110
//! turns to face the player every step, and CODE 108 only fires when
//! `collision_line(x, y, obj_player.x, obj_player.y, par_wall, true, true)`
//! reports a clear line of sight - otherwise the volley is skipped and the
//! cadence still re-arms with choose(30, 45, 60, 75). Its projectile is
//! obj_enemybullet2 (48) with the same impact contract as bullet one, and its
//! CODE 101 counts global.trapskilled.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WALL: i32 = 4;
const WARP: i32 = 69;
const SHOOTER2: i32 = 20;
const BULLET2: i32 = 48;
const GEM: i32 = 59;
const COIN: i32 = 60;
const XPORB: i32 = 61;
const HEALTH: i32 = 62;
const SMALLPUFF: i32 = 187;
/// SOND ids from reconstruction/contracts/audio-sond.json.
const SND_EXPLODE: i32 = 7;
const SND_FIRE: i32 = 10;
const SND_IMPACTSOUND2: i32 = 23;
/// Every enemy species present in the Mines rooms under test.
const ENEMIES: [i32; 6] = [14, 15, 16, 20, 23, 31];

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

fn one(s: &Scene, object: i32) -> i32 {
    *cast(s, object).first().unwrap_or_else(|| panic!("no live object {object}"))
}

fn doors(s: &Scene) -> Vec<(f64, f64, f64)> {
    s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect()
}

/// rm_town -> rm_level1 -> rm_level4 -> rm_level5 -> rm_level7 -> rm_level8 ->
/// rm_level8a (9) -> rm_boss1 (10) -> rm_level9 (11) -> rm_level9a (12) ->
/// rm_level10 (13) -> rm_level11 (14).
fn mines_scene(through: f64) -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0] {
        if s.current_room == through { break; }
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

/// Quarantine every enemy except `keep` and pin the pair at fixed coordinates:
/// CODE 361's dormancy sweep and contact damage would otherwise pollute the
/// firing window.
fn duel(s: &mut Scene, player: i32, keep: i32, px: f64, py: f64, sx: f64, sy: f64, invulnerable: bool) {
    let others: Vec<i32> = s.instances.iter()
        .filter(|(id, i)| i.alive && i.active && **id != keep && ENEMIES.contains(&i.object))
        .map(|(id, _)| *id)
        .collect();
    for id in others {
        s.write(id, -1, "x", None, 6000.0).unwrap();
        s.write(id, -1, "y", None, 6000.0).unwrap();
        s.write(id, -1, "hspeed", None, 0.0).unwrap();
        s.write(id, -1, "vspeed", None, 0.0).unwrap();
        s.write(id, -1, "gravity", None, 0.0).unwrap();
    }
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    s.write(player, -1, "hspeed", None, 0.0).unwrap();
    s.write(player, -1, "vspeed", None, 0.0).unwrap();
    if invulnerable {
        s.write(player, -1, "invulnerable", None, 1.0).unwrap();
        s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
    }
    s.write(keep, -1, "x", None, sx).unwrap();
    s.write(keep, -1, "y", None, sy).unwrap();
    s.write(keep, -1, "hspeed", None, 0.0).unwrap();
    s.write(keep, -1, "vspeed", None, 0.0).unwrap();
    s.write(keep, -1, "gravity", None, 0.0).unwrap();
    if let Some(i) = s.instances.get_mut(&keep) { i.active = true; }
}


/// Ids of the par_wall family (obj_wall 4, obj_wall_2 5, obj_boulder 6) plus the
/// parent itself, so a fixture can guarantee a genuinely clear line.
const WALL_OBJECTS: [i32; 4] = [4, 5, 6, 34];

fn segment_hits_box(x1: f64, y1: f64, x2: f64, y2: f64, min_x: f64, max_x: f64, min_y: f64, max_y: f64) -> bool {
    // Liang-Barsky clipping: true when the segment enters the box at all.
    let dx = x2 - x1;
    let dy = y2 - y1;
    let mut t0 = 0.0f64;
    let mut t1 = 1.0f64;
    let checks = [(-dx, x1 - min_x), (dx, max_x - x1), (-dy, y1 - min_y), (dy, max_y - y1)];
    for (p, q) in checks {
        if p == 0.0 {
            if q < 0.0 { return false; }
        } else {
            let r = q / p;
            if p < 0.0 {
                if r > t1 { return false; }
                if r > t0 { t0 = r; }
            } else {
                if r < t0 { return false; }
                if r < t1 { t1 = r; }
            }
        }
    }
    true
}

/// Destroy every wall/boulder on the segment so the LOS fixture measures the
/// mechanic instead of the room's own geometry. Returns how many were cleared.
fn clear_segment(s: &mut Scene, bundle: &callys_core::code_vm::Bundle, x1: f64, y1: f64, x2: f64, y2: f64) -> usize {
    let blockers: Vec<i32> = s.instances.iter()
        .filter(|(_, i)| i.alive && WALL_OBJECTS.contains(&i.object))
        .filter(|(id, _)| match s.bounds_for_instance(**id) {
            Some((min_x, max_x, min_y, max_y)) => segment_hits_box(x1, y1, x2, y2, min_x, max_x, min_y, max_y),
            None => false,
        })
        .map(|(id, _)| *id)
        .collect();
    let n = blockers.len();
    for id in blockers { let _ = s.destroy(bundle, id); }
    n
}

fn new_ids(s: &Scene, before: &[i32]) -> Vec<i32> {
    let mut created: Vec<i32> = s.instances.keys().copied().filter(|k| !before.contains(k)).collect();
    created.sort();
    created
}

#[test]
fn the_mines_chain_opens_from_level9_through_level11() {
    let (bundle, mut s, player, asset) = mines_scene(11.0);
    assert_eq!(s.current_room, 11.0, "rm_level9");
    assert_eq!(cast(&s, 74).len(), 1, "the assault rifle still waits in rm_level9");
    walk_portal(&bundle, &mut s, &asset, player, 12.0);

    // room 12 = rm_level9a, the second chest room of the run.
    assert_eq!(s.current_room, 12.0, "CODE 826 leads to rm_level9a");
    assert_eq!(cast(&s, 14).len(), 2, "two obj_enemy");
    assert_eq!(cast(&s, 15).len(), 4, "four obj_knifebandit");
    assert_eq!(cast(&s, 23).len(), 2, "two obj_wolf");
    assert_eq!(cast(&s, 100).len(), 1, "one treasure chest");
    assert!(doors(&s).contains(&(13.0, 1888.0, 172.0)), "CODE 827 opens rm_level10");
    assert!(doors(&s).contains(&(11.0, 1920.0, 204.0)), "CODE 828 returns to rm_level9");
    walk_portal(&bundle, &mut s, &asset, player, 13.0);

    // room 13 = rm_level10: the first room whose cast is built around trap gunners.
    assert_eq!(s.current_room, 13.0, "rm_level10");
    assert_eq!(cast(&s, SHOOTER2).len(), 4, "four obj_shooter2");
    assert_eq!(cast(&s, 23).len(), 4, "four obj_wolf");
    assert_eq!(cast(&s, 15).len(), 2, "two obj_knifebandit");
    assert_eq!(cast(&s, 31).len(), 1, "one obj_bat");
    assert!(cast(&s, 16).is_empty(), "no obj_shooter1 in rm_level10");
    assert!(doors(&s).contains(&(12.0, 128.0, 1164.0)), "CODE 829 returns to rm_level9a");
    assert!(doors(&s).contains(&(14.0, 160.0, 1164.0)), "CODE 830 opens rm_level11");
    walk_portal(&bundle, &mut s, &asset, player, 14.0);

    assert_eq!(s.current_room, 14.0, "rm_level11");
    assert_eq!(cast(&s, 16).len(), 1, "one obj_shooter1 returns here");
    assert!(cast(&s, SHOOTER2).is_empty(), "no trap gunner in rm_level11");
    assert!(doors(&s).contains(&(13.0, 1888.0, 492.0)), "CODE 831 returns to rm_level10");
    assert!(doors(&s).contains(&(15.0, 128.0, 172.0)), "CODE 832 opens rm_level11a, the slime room");
}

#[test]
fn shooter2_hp_ladder_is_its_own_table() {
    let (bundle, mut s, _player, _asset) = mines_scene(13.0);
    let ladder: [(f64, f64, f64); 8] = [
        (1.0, 1.0, 50.0), (5.0, 2.0, 45.0), (5.0, 3.0, 40.0), (5.0, 4.0, 35.0),
        (10.0, 1.0, 54.0), (15.0, 4.0, 53.0), (20.0, 1.0, 70.0), (20.0, 4.0, 55.0),
    ];
    for (level, pwr, want) in ladder {
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let id = s.create(&bundle, SHOOTER2, 64.0, 64.0).expect("create obj_shooter2");
        assert_eq!(s.instances[&id].fields["hpshooter2"], want,
            "level {level} / pwr {pwr} must set hpshooter2 = {want}");
        let _ = s.destroy(&bundle, id);
    }
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("pwr".into(), 1.0);
    let room_shooter = one(&s, SHOOTER2);
    assert_eq!(s.instances[&room_shooter].fields["hpshooter2"], 50.0,
        "the room's own trap gunner spawns with the level-1 HP");
    assert_eq!(s.instances[&room_shooter].alarms[1], 60, "CODE 100 arms a slower 60-tick first shot");
}

#[test]
fn shooter2_fires_only_with_line_of_sight() {
    let (bundle, mut s, player, _asset) = mines_scene(13.0);
    let shooter = one(&s, SHOOTER2);
    duel(&mut s, player, shooter, 400.0, 400.0, 800.0, 400.0, true);
    s.write(shooter, -1, "hpshooter2", None, 50.0).unwrap();
    // The room's own walls would silently cancel the volley, so the fixture
    // clears the segment first and asserts how much it had to remove.
    let cleared = clear_segment(&mut s, &bundle, 800.0, 400.0, 400.0, 400.0);
    assert!(cleared > 0, "rm_level10's geometry really does cross the firing lane");

    // Clear line: CODE 108 fires bullet two from (x + 5, y + 11).
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    let first = new_ids(&s, &before);
    let bullet = *first.iter().find(|id| s.instances[id].object == BULLET2).expect("bullet two spawned");
    assert_eq!((s.instances[&bullet].fields["x"], s.instances[&bullet].fields["y"]), (805.0, 411.0),
        "CODE 108 spawns at (x + 5, y + 11) when facing 0");
    assert_eq!(s.instances[&bullet].fields["hspeed"], 10.0, "bullet two flies right");
    assert_eq!(s.instances[&shooter].alarms[2], 1, "CODE 108 arms the fire pose");
    assert_eq!(s.instances[&shooter].alarms[6], 8, "CODE 108 arms its muzzle-flash timer");
    assert!([30, 45, 60, 75].contains(&s.instances[&shooter].alarms[1]),
        "the cadence re-arms with choose(30, 45, 60, 75), got {}", s.instances[&shooter].alarms[1]);
    assert!(s.audio.iter().any(|c| c.sound == SND_FIRE && !c.looping), "snd_fire queues for the volley");
    // The bullet's own lifetime alarm is never armed anywhere in the original:
    // both bullet moulds are destroyed by contact only.
    assert_eq!(s.instances[&bullet].alarms[3], -1, "obj_enemybullet2's alarm[3] stays unarmed");
    let _ = s.destroy(&bundle, bullet);

    // Blocked line: the same alarm must skip the volley entirely. The pose
    // alarm is zeroed first - alarms only tick down in `tick`, and this test
    // dispatches events directly, so a leftover 1 from the volley above would
    // otherwise be indistinguishable from a newly armed pose.
    s.instances.get_mut(&shooter).unwrap().alarms[2] = 0;
    let before: Vec<i32> = s.instances.keys().copied().collect();
    let wall = s.create(&bundle, WALL, 600.0, 400.0).expect("blocking wall");
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    assert!(new_ids(&s, &before).iter().all(|id| s.instances[id].object != BULLET2),
        "collision_line against par_wall cancels the volley");
    assert_eq!(s.instances[&shooter].alarms[2], 0, "no fire pose without a shot");
    assert!(s.instances[&shooter].alarms[1] > 0,
        "the cadence still re-arms while the shot is cancelled");

    // Clear the wall again: the volley resumes.
    let _ = s.destroy(&bundle, wall);
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    assert!(new_ids(&s, &before).iter().any(|id| s.instances[id].object == BULLET2),
        "removing the wall restores line of sight");
    assert_eq!(s.instances[&shooter].alarms[2], 1, "the volley re-arms the fire pose");

    // Facing 1 mirrors the muzzle, exactly like the first gunner.
    for b in cast(&s, BULLET2) { let _ = s.destroy(&bundle, b); }
    s.write(shooter, -1, "image_xscale", None, -1.0).unwrap();
    s.write(shooter, -1, "facing", None, 1.0).unwrap();
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    let mirrored = new_ids(&s, &before).iter()
        .find(|id| s.instances[id].object == BULLET2).copied().expect("mirrored bullet");
    assert_eq!((s.instances[&mirrored].fields["x"], s.instances[&mirrored].fields["hspeed"]), (795.0, -10.0),
        "facing 1 spawns at (x - 5, y + 11) with hspeed -10");
}

#[test]
fn bullet_two_costs_a_heart_like_bullet_one() {
    let (bundle, mut s, player, _asset) = mines_scene(13.0);
    let shooter = one(&s, SHOOTER2);
    duel(&mut s, player, shooter, 400.0, 400.0, 800.0, 400.0, false);
    s.write(player, -1, "invulnerable", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 0.0).unwrap();

    // A stationary bullet two pinned on the player's right: CODE 315 checks the
    // projected position, so a zeroed velocity makes the overlap exact.
    let live = s.create(&bundle, BULLET2, 404.0, 400.0).expect("bullet two fixture");
    s.write(live, -1, "hspeed", None, 0.0).unwrap();
    s.write(live, -1, "vspeed", None, 0.0).unwrap();
    assert_eq!(s.globals["health1"], 4.0, "no damage before the fixture tick");
    s.tick(&bundle).unwrap();
    assert!(!s.instances[&live].alive, "CODE 315 spends the bullet on the player");
    assert_eq!(s.globals["health1"], 3.0, "one heart, same as obj_enemybullet");
    assert_eq!(s.instances[&player].fields["invulnerable"], 1.0, "impact from the right");
    assert_eq!(s.instances[&player].fields["sliding1"], 1.0, "sliding1 mirrors the impact side");
    assert_eq!(s.instances[&player].alarms[7], 22, "player alarm[7] = 22");
    assert_eq!(s.instances[&player].alarms[4], 10, "player alarm[4] = 10");
    assert_eq!(s.instances[&player].alarms[8], 25, "player alarm[8] = 25");
    assert!(s.audio.iter().any(|c| c.sound == SND_IMPACTSOUND2 && !c.looping),
        "snd_impactsound2 queues for the trap gunner's hit too");
}

#[test]
fn shooter2_death_spray_has_xp_tiers_and_counts_traps() {
    let (bundle, mut s, player, _asset) = mines_scene(13.0);
    let shooter = one(&s, SHOOTER2);
    duel(&mut s, player, shooter, 400.0, 400.0, 800.0, 400.0, true);
    s.write(shooter, -1, "hpdrop", None, 1.0).unwrap();
    s.write(shooter, -1, "xpdrop", None, 2.0).unwrap(); // the two-orb tier
    s.write(shooter, -1, "coindrop", None, 2.0).unwrap(); // the 5-coin tier
    let sy = s.instances[&shooter].fields["y"];

    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 0).unwrap(); // CODE 109
    let spawned = new_ids(&s, &before);
    let count = |o: i32| spawned.iter().filter(|id| s.instances[id].object == o).count();

    assert_eq!(count(XPORB), 2, "xpdrop == 2 hands out two experience orbs");
    assert_eq!(count(HEALTH), 1, "hpdrop == 1 drops one obj_health");
    assert_eq!(count(GEM), 1, "gemdropenabled == 1 drops one obj_gem");
    // obj_shooter2 rolls its own coin table in CODE 109 - 5 / 10 / 8 / 11 / 13
    // for coindrop 1..5, richer than obj_shooter1's 3 / 5 / 9 / 8 / 12.
    assert_eq!(count(COIN), 10, "coindrop == 2 is the trap gunner's ten-coin tier");
    assert_eq!(count(SMALLPUFF), 1, "CODE 101 leaves one obj_smallpuff");
    let orbs: Vec<i32> = spawned.iter().filter(|id| s.instances[*id].object == XPORB).copied().collect();
    assert_eq!(s.instances[&orbs[0]].fields["direction"], s.globals["xpspread"],
        "the first orb rides global.xpspread");
    assert_eq!(s.instances[&orbs[1]].fields["direction"], s.globals["xpspread2"],
        "the second orb rides global.xpspread2");
    assert!(s.instances[&orbs[0]].fields["y"] == sy - 35.0, "orbs spawn at y - 35");
    assert!(spawned.iter().filter(|id| s.instances[*id].object == COIN)
        .all(|id| s.instances[id].fields["y"] == sy - 35.0), "coins spawn at y - 35");
    assert!(s.audio.iter().any(|c| c.sound == SND_EXPLODE && !c.looping), "snd_explode queues");
    assert!(!s.instances[&shooter].alive, "CODE 109 ends in action_kill_object()");
    // CODE 101's counters: the trap gunner has its own ledger.
    assert_eq!(s.globals.get("trapskilled").copied().unwrap_or(0.0), 1.0,
        "global.trapskilled counts the trap gunner");
    assert_eq!(s.globals.get("enemieskilled").copied().unwrap_or(0.0), 1.0,
        "global.enemieskilled counts it too");
}
