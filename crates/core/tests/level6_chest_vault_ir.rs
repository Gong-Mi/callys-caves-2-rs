//! rm_level6's chest vault: the CODE 814 door out of rm_level5 (warproom 6,
//! landing 1856,1164) leads to an enemy-free side room holding 14
//! obj_treasurechest instances and one return door (CODE 816 -> warproom 5,
//! landing 128,1164). The chest rules are two objects: obj_treasurechest
//! (CODE 449 Create roll 1..4, CODE 450 velocity clamp, CODE 451 collision ->
//! spawn opener + destroy) and obj_treasurechestopen (CODE 455 rolls
//! `chestcontents = choose(1..7)` and arms alarm[0] = 20, CODE 456 sprays the
//! matching loot table with `motion_set(global.coinspreadN, 5|8)`).
//!
//! Evidence base: recovered GML (Underanalyzer round-trip, all 1,354 CODE),
//! assets/game.droid SHA256 9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6,
//! full_ir.json object/room/CODE ids.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const CHEST: i32 = 100;
const CHEST_SPRITE: f64 = 91.0;
const OPEN: i32 = 102;
const OPEN_SPRITE: f64 = 90.0;
const GEM: i32 = 59;
const COIN: i32 = 60;
const HEALTH: i32 = 62;
const WATERSURFACE: i32 = 9;
const WATERFILL: i32 = 10;
const WARP: i32 = 69;
const ENEMY_OBJECTS: [i32; 4] = [14, 15, 16, 23];

/// Loot histograms of CODE 456's seven tables, verbatim from the recovered GML.
/// Tables 1/3/4/5/6 emit (coin, gem, health); table 2 is the only one using
/// coinspread23/25 with speed 8, and table 7 the only double-health table.
fn table_histogram(table: i32) -> (usize, usize, usize) {
    match table {
        1 => (9, 2, 0),
        2 => (1, 1, 1),
        3 => (7, 2, 0),
        4 => (3, 1, 1),
        5 => (5, 2, 1),
        6 => (6, 1, 1),
        7 => (2, 1, 2),
        other => panic!("no such chest table {other}"),
    }
}

fn level6_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
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

/// Walk the CODE-pinned portal toward `want_room` and pump the transition.
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

fn level6_vault() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = level6_scene();
    walk_portal(&bundle, &mut s, &asset, player, 5.0);
    walk_portal(&bundle, &mut s, &asset, player, 6.0);
    (bundle, s, player, asset)
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

/// Chests sorted by distance to the nearest water tile: the vault has 53
/// watersurface instances, and CODE 343/346/351 dissolve loot that spawns in
/// water, so the far end of this ordering is the reproducible firing range.
fn chests_by_water_distance(s: &Scene) -> Vec<i32> {
    let water: Vec<(f64, f64)> = cast(s, WATERSURFACE).iter()
        .map(|id| (s.instances[id].fields["x"], s.instances[id].fields["y"]))
        .collect();
    let mut chests = cast(s, CHEST);
    chests.sort_by(|a, b| {
        let d = |c: &i32| -> f64 {
            let (cx, cy) = (s.instances[c].fields["x"], s.instances[c].fields["y"]);
            water.iter()
                .map(|(wx, wy)| ((wx - cx).powi(2) + (wy - cy).powi(2)).sqrt())
                .fold(f64::INFINITY, f64::min)
        };
        d(b).partial_cmp(&d(a)).unwrap()
    });
    chests
}

/// Crack one chest open with the player and return the spawned opener.
fn crack_chest(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, player: i32, chest: i32) -> i32 {
    let cx = s.instances[&chest].fields["x"];
    let cy = s.instances[&chest].fields["y"];
    s.write(player, -1, "x", None, cx).unwrap();
    s.write(player, -1, "y", None, cy).unwrap();
    for _ in 0..4 {
        s.tick(bundle).unwrap();
        if !s.instances[&chest].alive { break; }
    }
    assert!(!s.instances[&chest].alive, "CODE 451 destroys the lid on player contact");
    let opener = s.instances.iter()
        .filter(|(_, i)| i.object == OPEN && i.alive)
        .map(|(id, _)| *id)
        .last()
        .expect("CODE 451 spawns obj_treasurechestopen at the chest position");
    assert_eq!(s.instances[&opener].fields["x"], cx, "opener keeps the chest x");
    assert_eq!(s.instances[&opener].fields["y"], cy, "opener keeps the chest y");
    opener
}

#[test]
fn portal_level5_to_level6_lands_in_the_chest_vault() {
    let (bundle, mut s, player, _asset) = level6_vault();

    assert_eq!(s.current_room, 6.0, "CODE 814 pins warproom 6");
    let p = &s.instances[&player];
    assert_eq!(p.fields["x"], 1856.0, "CODE 814 landing x");
    assert_eq!(p.fields["y"], 1164.0, "CODE 814 landing y");

    // The vault is a pure collectible room: 14 chests, no enemy cast at all.
    let chests = cast(&s, CHEST);
    assert_eq!(chests.len(), 14, "rm_level6 places 14 obj_treasurechest");
    for c in &chests {
        let i = &s.instances[c];
        assert_eq!(i.fields["sprite_index"], CHEST_SPRITE, "spr_treasurechest geometry");
        let roll = i.fields["chestcontents"];
        assert!((1.0..=4.0).contains(&roll) && roll.fract() == 0.0,
            "CODE 449 choose(1,2,3,4) rolled {roll} on chest {c}");
    }
    for o in ENEMY_OBJECTS {
        assert!(cast(&s, o).is_empty(), "object {o} must not be in the chest vault");
    }
    // Chests are standalone objects: no par_enemy membership (unlike the
    // level 1-5 cast that resolves through the parent chain).
    assert!(s.object_parents[&CHEST].is_empty(), "obj_treasurechest has no parent");

    // The only door is the CODE 816 return door back into rm_level5.
    let doors: Vec<(i32, f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(id, i)| (*id, i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert_eq!(doors.len(), 1, "rm_level6 has a single warpanywhere");
    assert_eq!(doors[0].1, 5.0, "CODE 816 warproom");
    assert_eq!((doors[0].2, doors[0].3), (128.0, 1164.0), "CODE 816 landing");

    // Water is present but the landing zone itself is dry.
    assert_eq!(cast(&s, WATERSURFACE).len(), 53, "vault water tiles");
    assert_eq!(cast(&s, WATERFILL).len(), 1, "vault waterfill sprite selector");
    for _ in 0..20 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], 4.0, "the vault landing is safe");
}

#[test]
fn chest_lid_pops_into_the_opener_and_arms_its_timer() {
    let (bundle, mut s, player, _asset) = level6_vault();
    let chest = chests_by_water_distance(&s)[0];
    let lid_roll = s.instances[&chest].fields["chestcontents"];
    assert!((1.0..=4.0).contains(&lid_roll), "the lid object carried its own 1..4 roll");

    let opener = crack_chest(&bundle, &mut s, player, chest);

    assert_eq!(s.instances[&opener].fields["sprite_index"], OPEN_SPRITE, "spr_treasurechestopen");
    let roll = s.instances[&opener].fields["chestcontents"];
    assert!((1.0..=7.0).contains(&roll) && roll.fract() == 0.0,
        "CODE 455 choose(1..7) rolled {roll}");
    // Original quirk, preserved: the opener re-rolls and never reads the lid's
    // own chestcontents, so CODE 449's 1..4 roll is dead data (the tables in
    // CODE 456 cover 1..7, three of which the lid can never have produced).
    assert_eq!(s.instances[&opener].alarms[0], 20, "CODE 455 arms alarm[0] = 20");

    // CODE 457 clamps the opener's velocity every step before the timer fires.
    s.write(opener, -1, "hspeed", None, 12.0).unwrap();
    s.write(opener, -1, "vspeed", None, -7.0).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&opener].fields["hspeed"], 0.0, "CODE 457 zeroes hspeed");
    assert_eq!(s.instances[&opener].fields["vspeed"], 0.0, "CODE 457 zeroes vspeed");

    // The 20-tick timer (not a manual dispatch) must be what fires the table.
    let before: Vec<i32> = s.instances.keys().copied().collect();
    let mut fired = false;
    for _ in 0..25 {
        s.tick(&bundle).unwrap();
        if !s.instances[&opener].alive { fired = true; break; }
    }
    assert!(fired, "alarm[0] = 20 fires CODE 456 and destroys the opener");
    let spawned: Vec<i32> = s.instances.keys().copied().filter(|k| !before.contains(k)).collect();
    assert!(!spawned.is_empty(), "the timer path spawned real loot, not just a dispatched body");
}

#[test]
fn every_one_of_the_seven_tables_sprays_its_original_payload() {
    let (bundle, mut s, player, _asset) = level6_vault();
    let lanes = chests_by_water_distance(&s);
    assert!(lanes.len() >= 7, "the vault has 14 chests: seven tables fit in dry ground");

    for table in 1..=7i32 {
        let chest = lanes[(table - 1) as usize];
        let opener = crack_chest(&bundle, &mut s, player, chest);
        let (cx, cy) = (s.instances[&opener].fields["x"], s.instances[&opener].fields["y"]);
        s.write(opener, -1, "chestcontents", None, table as f64).unwrap();

        let before: Vec<i32> = s.instances.keys().copied().collect();
        s.dispatch(&bundle, opener, 2, 0).unwrap(); // CODE 456
        let mut spawned: Vec<i32> = s.instances.keys().copied()
            .filter(|k| !before.contains(k))
            .collect();
        spawned.sort();
        assert!(!s.instances[&opener].alive, "CODE 456 ends with instance_destroy()");

        let (coins, gems, healths) = table_histogram(table);
        let got = |o: i32| spawned.iter().filter(|id| s.instances[id].object == o).count();
        assert_eq!(got(COIN), coins, "table {table} silvercoin count");
        assert_eq!(got(GEM), gems, "table {table} gem count");
        assert_eq!(got(HEALTH), healths, "table {table} health count");
        assert_eq!(spawned.len(), coins + gems + healths,
            "table {table} must not spawn anything else (no XP orb in chest tables)");

        // Every spawn sits within CODE 456's own x window (+20/-20) and one of
        // its two y offsets; every velocity comes from a real
        // global.coinspreadN with speed 5 or 8 (CODE 456's two constants).
        // Directions must be exact: the dispatch path has not run friction or
        // gravity yet. Table 3's ninth spawn is the original's only literal
        // direction — motion_set(90, 5) with no coinspread slot at all.
        for id in &spawned {
            let i = &s.instances[id];
            assert!(i.fields["x"] >= cx - 20.0 && i.fields["x"] <= cx + 20.0,
                "table {table} loot x offset {}", i.fields["x"]);
            let dy = cy - i.fields["y"];
            assert!(dy == 64.0 || dy == 35.0,
                "table {table} loot y offset {dy} is one of CODE 456's two rows");
            let dir = i.fields["direction"];
            let literal_90 = table == 3 && dir == 90.0;
            assert!(
                literal_90
                    || s.globals.iter().any(|(k, v)| k.starts_with("coinspread") && (*v - dir).abs() < 1e-9),
                "table {table} direction {dir} is a global.coinspreadN value");
            let spd = i.fields["speed"];
            assert!(spd == 5.0 || spd == 8.0, "table {table} motion_set speed {spd}");
            let rad = dir * std::f64::consts::PI / 180.0;
            assert!((i.fields["hspeed"] - spd * rad.cos()).abs() < 1e-9,
                "table {table} hspeed derives from motion_set");
            assert!((i.fields["vspeed"] + spd * rad.sin()).abs() < 1e-9,
                "table {table} vspeed derives from motion_set (GMS y-down)");
        }

        if table == 2 {
            // Table 2 is the only one whose three spawns bind distinct
            // coinspread slots with two different speeds: assert the exact
            // (x offset, direction global, speed) tuples in creation order.
            let coin = *spawned.iter().find(|id| s.instances[id].object == COIN).unwrap();
            let health = *spawned.iter().find(|id| s.instances[id].object == HEALTH).unwrap();
            let gem = *spawned.iter().find(|id| s.instances[id].object == GEM).unwrap();
            let dir_of = |id: &i32| s.instances[id].fields["direction"];
            let spd_of = |id: &i32| s.instances[id].fields["speed"];
            assert_eq!(s.instances[&coin].fields["x"], cx - 18.0, "table 2 coin offset");
            assert_eq!(dir_of(&coin), s.globals["coinspread23"], "table 2 coin uses coinspread23");
            assert_eq!(spd_of(&coin), 8.0, "table 2 coin speed");
            assert_eq!(s.instances[&health].fields["x"], cx + 20.0, "table 2 health offset");
            assert_eq!(dir_of(&health), s.globals["coinspread2"], "table 2 health uses coinspread2");
            assert_eq!(spd_of(&health), 5.0, "table 2 health speed");
            assert_eq!(s.instances[&gem].fields["x"], cx - 20.0, "table 2 gem offset");
            assert_eq!(dir_of(&gem), s.globals["coinspread25"], "table 2 gem uses coinspread25");
            assert_eq!(spd_of(&gem), 8.0, "table 2 gem speed");
        }

        for id in spawned {
            let _ = s.destroy(&bundle, id);
        }
    }
}

#[test]
fn muting_create_seeds_the_thirty_spread_globals_the_tables_use() {
    let (_bundle, s, _player, _asset) = level6_vault();
    // obj_muting Create (CODE 371) randomises the spray directions once per
    // room load; every lobby/level room carries one obj_muting instance.
    let spread: Vec<(&String, &f64)> = s.globals.iter()
        .filter(|(k, _)| k.starts_with("coinspread") || k.starts_with("xpspread"))
        .collect();
    assert_eq!(spread.len(), 30, "25 coinspread + 5 xpspread globals");
    for (k, v) in spread {
        assert!((0.0..180.0).contains(v), "global.{k} random_range(0,180) gave {v}");
    }
    for k in ["coinspread", "coinspread2", "coinspread25"] {
        assert!(s.globals.contains_key(k), "global.{k} seeded by CODE 371");
    }
    for k in ["xpspread", "xpspread5"] {
        assert!(s.globals.contains_key(k), "global.{k} seeded by CODE 371");
    }
}

#[test]
fn vault_loot_is_real_currency_the_player_collects() {
    let (bundle, mut s, player, _asset) = level6_vault();
    let chest = chests_by_water_distance(&s)[0];
    let opener = crack_chest(&bundle, &mut s, player, chest);
    s.write(opener, -1, "chestcontents", None, 3.0).unwrap();
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, opener, 2, 0).unwrap();
    let coins: Vec<i32> = s.instances.keys().copied()
        .filter(|k| !before.contains(k))
        .filter(|k| s.instances[k].object == COIN)
        .collect();
    assert_eq!(coins.len(), 7, "table 3 sprays 7 silvercoins");

    let score_before = s.score;
    // Spray the whole table onto the player: the coins land within ±11 px of
    // each other, so one pickup scan consumes the overlapping set (the
    // original's Step 12 sweep is per-instance, not one-per-tick).
    let coin = coins[0];
    s.write(player, -1, "x", None, s.instances[&coin].fields["x"]).unwrap();
    s.write(player, -1, "y", None, s.instances[&coin].fields["y"]).unwrap();
    for _ in 0..4 {
        s.tick(&bundle).unwrap();
        if coins.iter().all(|c| !s.instances[c].alive) { break; }
    }
    let collected = coins.iter().filter(|c| !s.instances[c].alive).count();
    assert!(collected > 0, "the player's pickup scan consumed at least the struck coin");
    assert_eq!(s.score, score_before + 4.0 * collected as f64,
        "each silvercoin (type 3) pays 4 * coinmultiply = {collected} coins");
}

#[test]
fn waterfill_picks_its_sprite_from_the_room_switch_with_the_original_fallthrough() {
    // CODE 35 is `switch (room)`, compiled to 110 numeric case labels (room
    // indices, not names). The original source has no `break` after
    // `case rm_town`, so the bytecode falls through: case 0 stores spr_lavafill
    // (100) and immediately runs case 1's body, which stores spr_waterfill
    // (103) and breaks. rm_town therefore ends on the WATER sprite.
    let (bundle, mut s, _player, _asset) = level6_vault();
    let waterfill_sprite = |s: &mut Scene, room: f64| -> f64 {
        s.current_room = room;
        let id = s.create(&bundle, WATERFILL, 32.0, 32.0).expect("obj_waterfill Create");
        s.instances[&id].fields["sprite_index"]
    };
    assert_eq!(waterfill_sprite(&mut s, 0.0), 103.0,
        "rm_town falls through case 0 into case 1's spr_waterfill");
    assert_eq!(waterfill_sprite(&mut s, 6.0), 103.0, "rm_level6 is a water room");
    assert_eq!(waterfill_sprite(&mut s, 28.0), 100.0,
        "room31 is a lava room: case room31 stores spr_lavafill and breaks");
}

#[test]
fn the_single_return_door_walks_back_into_level5() {
    let (bundle, mut s, player, asset) = level6_vault();
    walk_portal(&bundle, &mut s, &asset, player, 5.0);
    assert_eq!(s.current_room, 5.0, "CODE 816 sends rm_level6 back to rm_level5");
    let p = &s.instances[&player];
    assert_eq!((p.fields["x"], p.fields["y"]), (128.0, 1164.0), "CODE 816 landing");
    // rm_level5's own cast is intact again after the round trip.
    assert_eq!(cast(&s, 14).len(), 2, "two obj_enemy back in rm_level5");
    assert_eq!(cast(&s, 23).len(), 2, "two obj_wolf back in rm_level5");
    for _ in 0..10 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], 4.0, "the landing corner of rm_level5 is safe");
}
