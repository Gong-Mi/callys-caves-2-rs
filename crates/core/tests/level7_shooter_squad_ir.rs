//! rm_level7's four-species squad and obj_shooter1's complete ranged mould.
//! Reached through the real door chain: CODE 812 out of rm_level4 into
//! rm_level5, then rm_level5's CODE 815 (warproom 7, landing 128,364).
//! Cast: obj_knifebandit 15 x1, obj_shooter1 16 x1, obj_wolf 23 x1,
//! obj_bat 31 x2 - the first room that mixes ground, air and projectile
//! enemies. obj_shooter1 is the pistol thug: CODE 58 scales hpshooter1 by
//! global.level/global.pwr, CODE 67 patrols and re-arms, CODE 65 fires
//! obj_enemybullet on alarm[1] = choose(45,50,55,60), CODE 66 sprays the
//! hpdrop/gem/xp/coindrop tables, CODE 59 counts the kill.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const SHOOTER1: i32 = 16;
const BULLET: i32 = 47;
const GEM: i32 = 59;
const COIN: i32 = 60;
const XPORB: i32 = 61;
const HEALTH: i32 = 62;
const WATERSURFACE: i32 = 9;
const WARP: i32 = 69;
const SMALLPUFF: i32 = 187;
/// Every enemy species in rm_level7 (the quarantine set).
const ENEMIES: [i32; 4] = [15, SHOOTER1, 23, 31];
/// CODE 67 / CODE 65 / CODE 64 sprite constants.
const SPR_PISTOLBANDIT: f64 = 114.0;
const SPR_PISTOLBANDITFIRE: f64 = 115.0;
/// SOND ids from reconstruction/contracts/audio-sond.json.
const SND_EXPLODE: i32 = 7;
const SND_IMPACTSOUND2: i32 = 23;
const SND_IMPACTSOUND5: i32 = 24;

fn scene_to_level7() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
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
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
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
    let px = s.instances[&portal].fields["x"];
    let py = s.instances[&portal].fields["y"];
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    assert!(s.target_room_warp.is_some(), "CODE 13 must queue room_goto on portal overlap");
    let target = s.target_room_warp.take().unwrap();
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("portal transition");
}

fn level7_squad() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = scene_to_level7();
    walk_portal(&bundle, &mut s, &asset, player, 5.0);
    walk_portal(&bundle, &mut s, &asset, player, 7.0);
    (bundle, s, player, asset)
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

/// Alive-instance ledger diff: returns the ids created since `before`.
fn new_ids(s: &Scene, before: &[i32]) -> Vec<i32> {
    let mut created: Vec<i32> = s.instances.keys().copied().filter(|k| !before.contains(k)).collect();
    created.sort();
    created
}

/// Duel arena: park every non-player, non-target instance far away so no
/// contact damage or CODE 361 sweep can interfere, then keep the player and
/// the pistol thug pinned at fixed coordinates. The pinning is load-bearing:
/// CODE 67 walks (hspeed +/-3) and CODE 361 deactivates anything further than
/// 450 px from the player, so an unpinned pair drifts out of the test window.
struct Duel {
    player_x: f64,
    player_y: f64,
    shooter_x: f64,
    shooter_y: f64,
}

impl Duel {
    fn setup(s: &mut Scene, player: i32, shooter: i32, invulnerable: bool) -> Duel {
        // Only the other species are quarantined: moving every instance would
        // drag the room's water tiles and walls out from under the fixtures.
        let others: Vec<i32> = s.instances.iter()
            .filter(|(id, i)| i.alive && i.active && **id != shooter && ENEMIES.contains(&i.object))
            .map(|(id, _)| *id)
            .collect();
        for id in others {
            s.write(id, -1, "x", None, 6000.0).unwrap();
            s.write(id, -1, "y", None, 6000.0).unwrap();
            s.write(id, -1, "hspeed", None, 0.0).unwrap();
            s.write(id, -1, "vspeed", None, 0.0).unwrap();
            s.write(id, -1, "gravity", None, 0.0).unwrap();
        }
        let d = Duel { player_x: 128.0, player_y: 364.0, shooter_x: 300.0, shooter_y: 364.0 };
        d.pin(s, player, shooter, invulnerable);
        d
    }

    fn pin(&self, s: &mut Scene, player: i32, shooter: i32, invulnerable: bool) {
        s.write(player, -1, "x", None, self.player_x).unwrap();
        s.write(player, -1, "y", None, self.player_y).unwrap();
        s.write(player, -1, "hspeed", None, 0.0).unwrap();
        s.write(player, -1, "vspeed", None, 0.0).unwrap();
        if invulnerable {
            s.write(player, -1, "invulnerable", None, 1.0).unwrap();
            s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
        }
        s.write(shooter, -1, "x", None, self.shooter_x).unwrap();
        s.write(shooter, -1, "y", None, self.shooter_y).unwrap();
        s.write(shooter, -1, "hspeed", None, 0.0).unwrap();
        s.write(shooter, -1, "vspeed", None, 0.0).unwrap();
        s.write(shooter, -1, "gravity", None, 0.0).unwrap();
        if let Some(i) = s.instances.get_mut(&shooter) {
            i.active = true;
        }
    }
}

#[test]
fn portal_level5_to_level7_delivers_the_four_species_squad() {
    let (bundle, mut s, player, _asset) = level7_squad();

    assert_eq!(s.current_room, 7.0, "CODE 815 pins warproom 7");
    let p = &s.instances[&player];
    assert_eq!((p.fields["x"], p.fields["y"]), (128.0, 364.0), "CODE 815 landing");

    assert_eq!(cast(&s, 15).len(), 1, "one obj_knifebandit");
    assert_eq!(cast(&s, SHOOTER1).len(), 1, "one obj_shooter1");
    assert_eq!(cast(&s, 23).len(), 1, "one obj_wolf");
    assert_eq!(cast(&s, 31).len(), 2, "two obj_bat");
    for o in [15, SHOOTER1, 23, 31] {
        assert!(s.object_parents[&o].contains(&11), "object {o} chains through par_enemy");
    }

    // CODE 58's HP ladder: the town's obj_pwrlevelinitialize (CODE 458) already
    // ran when rm_town loaded, so level 1 / pwr 1 gives 35.
    assert_eq!(s.globals["level"], 1.0, "fresh start level");
    assert_eq!(s.globals["pwr"], 1.0, "CODE 458 global.pwr = 1 in rm_town");
    let shooter = cast(&s, SHOOTER1)[0];
    assert_eq!(s.instances[&shooter].fields["hpshooter1"], 35.0, "pwr 1, level <= 5");

    let doors: Vec<(f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert_eq!(doors.len(), 2, "rm_level7 has two doors");
    assert!(doors.contains(&(5.0, 1888.0, 1164.0)), "CODE 817 back to rm_level5");
    assert!(doors.contains(&(8.0, 160.0, 428.0)), "CODE 818 on to rm_level8");

    // The landing corner is safe for 20 frames with all four species live.
    s.write(player, -1, "x", None, 128.0).unwrap();
    s.write(player, -1, "y", None, 364.0).unwrap();
    for _ in 0..20 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], 4.0, "the CODE 815 landing zone is safe");
}

#[test]
fn shooter1_hp_ladder_reads_level_and_pwr() {
    let (bundle, mut s, _player, _asset) = level7_squad();
    // CODE 58: global.level <= 5 / <= 10 / <= 15 / <= 20 pick the HP band,
    // global.pwr 1..4 picks the row inside it.
    let ladder: [(f64, f64, f64); 8] = [
        (1.0, 1.0, 35.0), (5.0, 2.0, 33.0), (5.0, 3.0, 31.0), (5.0, 4.0, 28.0),
        (10.0, 1.0, 40.0), (15.0, 4.0, 38.0), (20.0, 1.0, 60.0), (20.0, 4.0, 45.0),
    ];
    for (level, pwr, want) in ladder {
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let id = s.create(&bundle, SHOOTER1, 64.0, 64.0).expect("create obj_shooter1");
        assert_eq!(s.instances[&id].fields["hpshooter1"], want,
            "level {level} / pwr {pwr} must set hpshooter1 = {want}");
        let _ = s.destroy(&bundle, id);
    }

    // Without the town's CODE 458 the ladder never runs: every pwr guard is
    // false, hpshooter1 stays undefined, and CODE 67 reads it as 0 - which
    // arms BOTH guards, so the `hpshooter1 <= 0` branch leaves alarm[0] = 1
    // and the mould self-destructs on the next tick.
    s.globals.remove("pwr");
    let orphan = s.create(&bundle, SHOOTER1, 64.0, 64.0).expect("create orphan shooter");
    assert!(!s.instances[&orphan].fields.contains_key("hpshooter1"),
        "no pwr means no HP assignment: rm_town's CODE 458 is load-bearing");
    s.globals.insert("pwr".into(), 1.0);
    s.globals.insert("level".into(), 1.0);
    let id = s.create(&bundle, SHOOTER1, 64.0, 64.0).expect("create shooter with pwr");
    assert_eq!(s.instances[&id].fields["hpshooter1"], 35.0, "pwr 1 / level 1 restores 35");
}

#[test]
fn shooter1_fires_on_its_thirty_tick_rhythm_and_the_bullet_costs_a_heart() {
    let (bundle, mut s, player, _asset) = level7_squad();
    let shooter = cast(&s, SHOOTER1)[0];
    assert_eq!(s.instances[&shooter].alarms[1], 30, "CODE 58 arms alarm[1] = 30");
    let duel = Duel::setup(&mut s, player, shooter, true);

    // (a) The timer path: 30 ticks of CODE 67, then CODE 65 fires.
    let mut fired_at = None;
    for n in 0..32 {
        duel.pin(&mut s, player, shooter, true);
        s.write(shooter, -1, "facing", None, 0.0).unwrap();
        s.write(shooter, -1, "image_xscale", None, 1.0).unwrap();
        s.tick(&bundle).unwrap();
        if cast(&s, BULLET).len() == 1 { fired_at = Some(n + 1); break; }
    }
    assert_eq!(fired_at, Some(30), "CODE 58's 30-tick rhythm fires on tick 30");
    let timer_bullet = cast(&s, BULLET)[0];
    assert_eq!(s.instances[&timer_bullet].fields["hspeed"], 10.0, "facing 0 fires to the right");
    // By the time the timer's bullet is observable the tick has already run
    // CODE 67, whose first line is `sprite_index = spr_pistolbandit` - so the
    // fire pose is only ever live inside the alarm phase (see the dispatch
    // assertions below).
    assert_eq!(s.instances[&shooter].fields["sprite_index"], SPR_PISTOLBANDIT,
        "CODE 67 restores the idle pose in the same tick");
    let _ = s.destroy(&bundle, timer_bullet);

    // (b) Exact spawn geometry through CODE 65 itself.
    duel.pin(&mut s, player, shooter, true);
    s.write(shooter, -1, "image_xscale", None, 1.0).unwrap();
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap(); // CODE 65
    let spawned = new_ids(&s, &before);
    let bullet = *spawned.iter().find(|id| s.instances[id].object == BULLET).expect("bullet spawned");
    assert_eq!((s.instances[&bullet].fields["x"], s.instances[&bullet].fields["y"]),
        (duel.shooter_x + 8.0, duel.shooter_y + 6.0),
        "CODE 65 spawns at (x + 8, y + 6) when image_xscale == 1");
    assert_eq!(s.instances[&bullet].fields["hspeed"], 10.0, "bullet hspeed");
    assert_eq!(s.instances[&shooter].fields["sprite_index"], SPR_PISTOLBANDITFIRE,
        "inside the alarm phase CODE 65 has switched to spr_pistolbanditfire");
    assert_eq!(s.instances[&shooter].alarms[2], 10, "CODE 65 arms alarm[2] = 10");
    assert!([45, 50, 55, 60].contains(&s.instances[&shooter].alarms[1]),
        "adds chooses the next shot gap, got {}", s.instances[&shooter].alarms[1]);
    assert!(s.audio.iter().any(|c| c.sound == SND_IMPACTSOUND5 && !c.looping),
        "snd_impactsound5 queues on every shot");
    let _ = s.destroy(&bundle, bullet);
    for b in cast(&s, BULLET) { let _ = s.destroy(&bundle, b); }

    // Facing 1 mirrors the muzzle.
    s.write(shooter, -1, "image_xscale", None, -1.0).unwrap();
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 1).unwrap();
    let mirrored = new_ids(&s, &before).iter()
        .find(|id| s.instances[id].object == BULLET).copied().expect("second bullet");
    assert_eq!((s.instances[&mirrored].fields["x"], s.instances[&mirrored].fields["hspeed"]),
        (duel.shooter_x - 8.0, -10.0), "image_xscale == -1 fires from x - 8 with hspeed -10");
    for b in cast(&s, BULLET) { let _ = s.destroy(&bundle, b); }

    // (c) CODE 64's alarm[2] = 10 "restore" is redundant in practice: CODE 67
    // already rewrote sprite_index in the firing tick, so the field stays on
    // spr_pistolbandit across the whole window (original dead visual code).
    s.instances.get_mut(&shooter).unwrap().alarms[2] = 10;
    for _ in 0..10 {
        duel.pin(&mut s, player, shooter, true);
        s.tick(&bundle).unwrap();
        assert_eq!(s.instances[&shooter].fields["sprite_index"], SPR_PISTOLBANDIT,
            "the idle pose never leaves spr_pistolbandit");
    }

    // (d) CODE 313: the bullet takes a heart off the player, armours and
    // slides him away from the impact side. Code 66's own spray is over and no
    // other bullet is airborne, so a single tick is the whole event; the
    // fixture bullet is pinned stationary just right of the player, which is
    // the exact geometry the original checks (bullet.x > obj_player.x).
    for b in cast(&s, BULLET) { let _ = s.destroy(&bundle, b); }
    let spot = (duel.player_x, duel.player_y);
    let live = s.create(&bundle, BULLET, spot.0 + 4.0, spot.1).expect("bullet fixture");
    s.write(live, -1, "hspeed", None, 0.0).unwrap();
    s.write(live, -1, "vspeed", None, 0.0).unwrap();
    duel.pin(&mut s, player, shooter, false);
    s.write(player, -1, "invulnerable", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 0.0).unwrap();
    assert_eq!(s.globals["health1"], 4.0, "no damage before the fixture tick");
    s.tick(&bundle).unwrap();
    assert!(!s.instances[&live].alive, "the bullet spends itself on the player");
    assert_eq!(s.globals["health1"], 3.0, "CODE 313 takes exactly one heart");
    assert_eq!(s.instances[&player].fields["invulnerable"], 1.0, "impact from the right");
    assert_eq!(s.instances[&player].fields["sliding1"], 1.0, "sliding1 mirrors the impact side");
    assert_eq!(s.instances[&player].alarms[7], 22, "player alarm[7] = 22");
    assert_eq!(s.instances[&player].alarms[4], 10, "player alarm[4] = 10");
    assert_eq!(s.instances[&player].alarms[8], 25, "player alarm[8] = 25");
    assert!(s.audio.iter().any(|c| c.sound == SND_IMPACTSOUND2 && !c.looping),
        "snd_impactsound2 queues for the hit");
}

#[test]
fn shooter1_sprays_its_death_loot_and_counts_the_kill() {
    let (bundle, mut s, player, _asset) = level7_squad();
    let shooter = cast(&s, SHOOTER1)[0];
    let duel = Duel::setup(&mut s, player, shooter, true);
    s.write(shooter, -1, "hpdrop", None, 1.0).unwrap();
    s.write(shooter, -1, "xpdrop", None, 1.0).unwrap();
    s.write(shooter, -1, "coindrop", None, 3.0).unwrap(); // the 9-coin tier
    assert!(cast(&s, COIN).len() < 20, "the room starts below the coin cap");
    assert_eq!(s.globals["gemdropenabled"], 1.0, "fresh start has gem drops enabled");

    // CODE 66 is dispatched directly: the alarm tamer is verified in
    // water_kills_the_shooter_through_its_own_alarm_zero, and a direct dispatch
    // keeps the sprayed velocities at their raw motion_set values (a tick would
    // already have applied friction 0.3 from the loot's own Create).
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, shooter, 2, 0).unwrap(); // CODE 66
    assert!(!s.instances[&shooter].alive, "CODE 66 ends in action_kill_object()");
    let spawned = new_ids(&s, &before);
    let count = |o: i32| spawned.iter().filter(|id| s.instances[id].object == o).count();

    assert_eq!(count(HEALTH), 1, "hpdrop == 1 drops one obj_health");
    assert_eq!(count(GEM), 1, "gemdropenabled == 1 drops one obj_gem");
    assert_eq!(count(XPORB), 1, "xpdrop == 1 drops one obj_XPorb");
    assert_eq!(count(COIN), 9, "coindrop == 3 drops the 9-coin tier");
    assert_eq!(count(SMALLPUFF), 1, "CODE 59 leaves one obj_smallpuff");
    for id in &spawned {
        match s.instances[id].object {
            XPORB => {
                let dir = s.instances[id].fields["direction"];
                // The velocity integrator re-derives direction from hspeed/vspeed
                // after motion_set, so the identity holds to float tolerance.
                assert!((dir - s.globals["xpspread"]).abs() < 1e-9,
                    "the XP orb sprays along global.xpspread, got {dir}");
                assert_eq!(s.instances[id].fields["speed"], 5.0, "XP orb speed");
            }
            COIN => {
                let dir = s.instances[id].fields["direction"];
                assert!(s.globals.iter().any(|(k, v)| k.starts_with("coinspread") && (*v - dir).abs() < 1e-9),
                    "every coin rides a real coinspread slot, got {dir}");
                assert_eq!(s.instances[id].fields["speed"], 5.0, "coin speed");
                assert_eq!(s.instances[id].fields["y"], duel.shooter_y - 35.0, "coins spawn at y - 35");
                let dx = s.instances[id].fields["x"] - duel.shooter_x;
                assert!((-10.0..=8.0).contains(&dx), "coindrop 3 uses the -10..+8 offsets, got {dx}");
            }
            _ => {}
        }
    }
    assert!(s.audio.iter().any(|c| c.sound == SND_EXPLODE && !c.looping), "snd_explode queues");
    // CODE 59's counters: neither global is pre-seeded, so both read 0 -> 1.
    assert_eq!(s.globals.get("pistolthugskilled").copied().unwrap_or(0.0), 1.0,
        "global.pistolthugskilled counts the pistol thug");
    assert_eq!(s.globals.get("enemieskilled").copied().unwrap_or(0.0), 1.0,
        "global.enemieskilled counts the kill");
}

#[test]
fn the_twenty_silvercoin_cap_suppresses_the_coin_tier() {
    let (bundle, mut s, player, _asset) = level7_squad();
    let shooter = cast(&s, SHOOTER1)[0];
    let duel = Duel::setup(&mut s, player, shooter, true);
    for _ in 0..20 {
        s.create(&bundle, COIN, 100.0, 100.0).expect("seed a silvercoin");
    }
    assert_eq!(cast(&s, COIN).len(), 20, "the cap is exactly 20 live silvercoins");
    s.write(shooter, -1, "coindrop", None, 5.0).unwrap();
    s.write(shooter, -1, "hpdrop", None, 0.0).unwrap();
    s.write(shooter, -1, "xpdrop", None, 0.0).unwrap();
    let before: Vec<i32> = s.instances.keys().copied().collect();
    for _ in 0..4 {
        duel.pin(&mut s, player, shooter, true);
        s.write(shooter, -1, "hpshooter1", None, 0.0).unwrap();
        s.tick(&bundle).unwrap();
        if !s.instances[&shooter].alive { break; }
    }
    assert!(!s.instances[&shooter].alive, "the thug still dies at the cap");
    let spawned = new_ids(&s, &before);
    assert!(spawned.iter().all(|id| s.instances[id].object != COIN),
        "instance_number(obj_silvercoin) >= 20 suppresses the whole coin tier");
}

#[test]
fn water_kills_the_shooter_through_its_own_alarm_zero() {
    let (bundle, mut s, player, _asset) = level7_squad();
    let shooter = cast(&s, SHOOTER1)[0];
    // Pick the water tile nearest the landing and park the player 300 px above
    // it: still inside CODE 361's 450 px anti-dormancy radius (so the thug is
    // never swept out of the tick) but far above the water, which would
    // otherwise kill the player himself.
    let (px0, py0) = (s.instances[&player].fields["x"], s.instances[&player].fields["y"]);
    let water = cast(&s, WATERSURFACE);
    assert!(!water.is_empty(), "rm_level7 has water");
    let near = water.iter()
        .min_by(|a, b| {
            let d = |id: &&i32| {
                let (wx, wy) = (s.instances[*id].fields["x"], s.instances[*id].fields["y"]);
                ((wx - px0).powi(2) + (wy - py0).powi(2)).sqrt()
            };
            d(a).partial_cmp(&d(b)).unwrap()
        })
        .copied().expect("nearest water tile");
    let (wx, wy) = (s.instances[&near].fields["x"], s.instances[&near].fields["y"]);
    let (px, py) = (wx, wy - 300.0);

    let others: Vec<i32> = s.instances.iter()
        .filter(|(id, i)| i.alive && i.active && **id != shooter && ENEMIES.contains(&i.object))
        .map(|(id, _)| *id)
        .collect();
    for id in others {
        s.write(id, -1, "x", None, 6000.0).unwrap();
        s.write(id, -1, "y", None, 6000.0).unwrap();
    }
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
    s.write(shooter, -1, "hpshooter1", None, 35.0).unwrap();
    for _ in 0..5 {
        s.write(player, -1, "x", None, px).unwrap();
        s.write(player, -1, "y", None, py).unwrap();
        s.write(player, -1, "invulnerable", None, 1.0).unwrap();
        s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
        s.write(shooter, -1, "x", None, wx).unwrap();
        s.write(shooter, -1, "y", None, wy).unwrap();
        s.write(shooter, -1, "gravity", None, 0.0).unwrap();
        s.write(shooter, -1, "vspeed", None, 0.0).unwrap();
        if let Some(i) = s.instances.get_mut(&shooter) { i.active = true; }
        s.tick(&bundle).unwrap();
        if !s.instances[&shooter].alive { break; }
    }
    assert!(!s.instances[&shooter].alive,
        "CODE 67's water probe arms alarm[0] and the mould dies intact");
    assert_eq!(s.globals.get("pistolthugskilled").copied().unwrap_or(0.0), 1.0,
        "the water death still counts through CODE 59");
}

#[test]
fn the_second_door_hands_over_to_level8() {
    let (bundle, mut s, player, asset) = level7_squad();
    walk_portal(&bundle, &mut s, &asset, player, 8.0);
    assert_eq!(s.current_room, 8.0, "CODE 818 sends rm_level7 on to rm_level8");
    let p = &s.instances[&player];
    assert_eq!((p.fields["x"], p.fields["y"]), (160.0, 428.0), "CODE 818 landing");
    // rm_level8's own cast (the next batch's material) is materialised intact.
    assert_eq!(cast(&s, 14).len(), 3, "three obj_enemy");
    assert_eq!(cast(&s, 15).len(), 8, "eight obj_knifebandit");
    assert_eq!(cast(&s, 23).len(), 1, "one obj_wolf");
    assert!(cast(&s, SHOOTER1).is_empty(), "rm_level8 has no pistol thug");
    let doors: Vec<(f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert!(doors.contains(&(7.0, 1888.0, 140.0)), "CODE 819 returns to rm_level7");
    assert!(doors.contains(&(9.0, 128.0, 1132.0)), "CODE 820 opens the Mines door to rm_level9");
}
