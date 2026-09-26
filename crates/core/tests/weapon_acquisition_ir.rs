//! The weapon-acquisition chain: obj_shotgun (73) in rm_level1/2 and
//! obj_assaultrifle (74) in the Mines. Each pickup is a two-event object -
//! CODE 386/388 Create (destroy when the weapon was already bought, otherwise
//! leave an obj_pickupflare beacon) and CODE 387/389 Step (`distance <= 1`
//! hands over obj_foundweapon, raises the bought flag, and flips the whole
//! exclusive weapon row so exactly one weapon stays active). The banner
//! obj_foundweapon (82) is the second freeze-frame system in the game: CODE
//! 404 pauses audio and deactivates the world, CODE 406 unlocks the tap after
//! 70 ticks, CODE 407 waits for a left press, CODE 408 composes the pause
//! backdrop plus the active weapon's sprite and title per viewport, and CODE
//! 405 resumes and reactivates.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const PICKUPFLARE: i32 = 70;
const SHOTGUN: i32 = 73;
const ASSAULTRIFLE: i32 = 74;
const FOUNDWEAPON: i32 = 82;
const SPR_PAUSE: i32 = 123;
const SPR_GUNSHOTGUN: i32 = 127;
/// SOND id from reconstruction/contracts/audio-sond.json.
const SND_PICKUPSTINGER: i32 = 27;

const WEAPON_GLOBALS: [&str; 12] = [
    "pistol", "shotgun", "assaultrifle", "rocket", "laser", "icegun",
    "bladegun", "flamethrower", "bow", "bombgun", "boomerang", "spikegun",
];

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

fn active_weapons(s: &Scene) -> Vec<String> {
    WEAPON_GLOBALS.iter()
        .filter(|w| s.globals.get(**w).copied() == Some(1.0))
        .map(|w| (*w).to_string())
        .collect()
}

/// Place the player on the pickup and tick until the Step hands over.
fn collect(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, player: i32, pickup: i32) {
    let (px, py) = (s.instances[&pickup].fields["x"], s.instances[&pickup].fields["y"]);
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..4 {
        s.tick(bundle).unwrap();
        if !s.instances[&pickup].alive { break; }
    }
    assert!(!s.instances[&pickup].alive, "CODE 387/389 destroys the pickup on contact");
}

#[test]
fn the_shotgun_pickup_flips_the_whole_weapon_row() {
    let (bundle, mut s, player, _asset) = load_scene();
    let shotgun = one(&s, SHOTGUN);
    // CODE 386 Create: an un-bought weapon leaves a beacon 16 px above.
    let flare = cast(&s, PICKUPFLARE);
    assert_eq!(flare.len(), 1, "CODE 386 spawns exactly one obj_pickupflare");
    assert_eq!(s.instances[&flare[0]].fields["x"], s.instances[&shotgun].fields["x"],
        "the beacon shares the pickup x");
    assert_eq!(s.instances[&flare[0]].fields["y"], s.instances[&shotgun].fields["y"] - 16.0,
        "the beacon sits 16 px above the shotgun");
    assert_eq!(s.instances[&flare[0]].alarms[0], 30, "CODE 380 arms a 30-tick beacon check");

    assert_eq!(active_weapons(&s), vec!["pistol".to_string()], "the pistol is the only live weapon");
    assert_eq!(s.globals["shotgunbought"], 0.0, "fresh start has not bought the shotgun");
    let (sx, sy) = (s.instances[&shotgun].fields["x"], s.instances[&shotgun].fields["y"]);

    collect(&bundle, &mut s, player, shotgun);

    // CODE 387 Step: the hand-over and the exclusivity flip.
    assert_eq!(s.globals["shotgunbought"], 1.0, "CODE 387 raises shotgunbought");
    assert_eq!(active_weapons(&s), vec!["shotgun".to_string()],
        "every other weapon - pistol included - is switched off");
    let banner = one(&s, FOUNDWEAPON);
    assert_eq!((s.instances[&banner].fields["x"], s.instances[&banner].fields["y"]), (sx, sy),
        "CODE 387 spawns the banner on the pickup's own coordinates");

}

#[test]
fn the_pickup_beacon_retires_only_next_to_the_player() {
    // CODE 380/381: the beacon re-arms itself every 30 ticks and only retires
    // when the player is within 30 px - so it keeps blinking from far away.
    let (bundle, mut s, player, _asset) = load_scene();
    let far = s.create(&bundle, PICKUPFLARE, 64.0, 64.0).expect("far beacon");
    for _ in 0..30 {
        // Re-pin the player every tick: its own Step applies gravity, so an
        // unpinned player drifts off the fixture coordinates.
        s.write(player, -1, "x", None, 2000.0).unwrap();
        s.write(player, -1, "y", None, 2000.0).unwrap();
        s.tick(&bundle).unwrap();
    }
    assert!(s.instances[&far].alive, "a beacon far from the player keeps blinking");
    assert_eq!(s.instances[&far].alarms[0], 30, "CODE 381 re-arms the 30-tick check");

    let near = s.create(&bundle, PICKUPFLARE, 2000.0, 2000.0).expect("near beacon");
    for _ in 0..31 {
        s.write(player, -1, "x", None, 2000.0).unwrap();
        s.write(player, -1, "y", None, 2000.0).unwrap();
        s.tick(&bundle).unwrap();
    }
    assert!(!s.instances[&near].alive, "CODE 381 retires the beacon within 30 px");
}

#[test]
fn the_found_weapon_banner_freezes_the_world_and_unlocks_on_a_tap() {
    let (bundle, mut s, player, _asset) = load_scene();
    let shotgun = one(&s, SHOTGUN);
    collect(&bundle, &mut s, player, shotgun);
    let banner = one(&s, FOUNDWEAPON);

    // CODE 404 Create.
    let active: Vec<i32> = s.instances.iter()
        .filter(|(_, i)| i.alive && i.active)
        .map(|(id, _)| *id)
        .collect();
    assert_eq!(active, vec![banner], "instance_deactivate_all(true) freezes the world");
    assert_eq!(s.instances[&banner].fields["taplock"], 0.0, "CODE 404 taplock");
    assert_eq!(s.instances[&banner].alarms[0], 70, "CODE 404 alarm[0] = 70");
    assert!(s.audio.iter().any(|c| c.sound == SND_PICKUPSTINGER && !c.looping),
        "CODE 404 cues snd_pickupstinger through the mute gate");

    // CODE 406 unlocks after 70 ticks; CODE 408 then composes the banner.
    for _ in 0..70 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&banner].fields["taplock"], 1.0, "CODE 406 unlocks the tap at 70");
    s.draw_view(&bundle, 0).unwrap();
    let lines: Vec<(f64, f64, String)> = s.texts.iter().map(|t| (t.x, t.y, t.text.clone())).collect();
    assert!(lines.contains(&(80.0, 30.0, "You have found the Shotgun!".to_string())),
        "CODE 408 titles the banner from the active weapon, got {lines:?}");
    assert!(lines.contains(&(150.0, 200.0, "Tap to Continue".to_string())),
        "the banner carries the tap prompt at view_xview[0] + 150 / + 200");
    assert!(s.draws.iter().any(|d| d.sprite == SPR_GUNSHOTGUN && d.frame == 0.0
        && d.x == 220.0 && d.y == 120.0 && d.scale_x == 7.0 && d.scale_y == 7.0),
        "the shotgun sprite is composited at (+220, +120) at 7x");
    assert!(s.draws.iter().any(|d| d.sprite == SPR_PAUSE && (d.scale_x - 0.96).abs() < 1e-9),
        "the pause backdrop is reused from CODE 408's first branch");

    // CODE 407: a left press dismisses; CODE 405 resumes and reactivates.
    s.mouse_pressed = true;
    s.tick(&bundle).unwrap();
    assert!(!s.instances[&banner].alive, "CODE 407 destroys the banner on a left press");
    assert!(s.instances.values().filter(|i| i.alive && i.active).count() > 1,
        "CODE 405 reactivates the world");
    assert!(s.audio_voices.iter().all(|v| !v.paused), "CODE 405 resumes audio");
}

#[test]
fn an_already_bought_weapon_leaves_no_pickup_in_the_room() {
    let (bundle, mut asset_scene, _player, asset) = load_scene();
    let _ = &mut asset_scene;
    // Re-enter rm_level1 with the shotgun already in hand: CODE 386's Create
    // destroys the pickup, and therefore no beacon is spawned either.
    asset_scene.globals.insert("shotgunbought".into(), 1.0);
    asset_scene.globals.insert("shotgun".into(), 1.0);
    asset_scene.globals.insert("pistol".into(), 0.0);
    asset_scene.transition_to_room(&bundle, 2, &asset.rooms[2]).expect("level1 -> level2");
    asset_scene.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("level2 -> level1");
    assert!(cast(&asset_scene, SHOTGUN).is_empty(),
        "CODE 386 destroys an already-bought pickup as the room loads");
    assert!(cast(&asset_scene, PICKUPFLARE).is_empty(), "no beacon without a pickup");
    assert_eq!(active_weapons(&asset_scene), vec!["shotgun".to_string()],
        "the bought weapon survives the room round trip");
}

#[test]
fn level8_swarm_hands_over_to_the_mines_door() {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    walk_portal(&bundle, &mut s, &asset, player, 5.0);
    walk_portal(&bundle, &mut s, &asset, player, 7.0);
    walk_portal(&bundle, &mut s, &asset, player, 8.0);
    assert_eq!(s.current_room, 8.0, "CODE 818 lands in rm_level8");
    assert_eq!(s.instances[&player].fields["x"], 160.0, "CODE 818 landing x");
    assert_eq!(cast(&s, 14).len(), 3, "three obj_enemy");
    assert_eq!(cast(&s, 15).len(), 8, "eight obj_knifebandit - the densest swarm so far");
    assert_eq!(cast(&s, 23).len(), 1, "one obj_wolf");
    let doors: Vec<(f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert!(doors.contains(&(7.0, 1888.0, 140.0)), "CODE 819 returns to rm_level7");
    // Room-id truth: 9 is rm_level8a (the area's side room), 10 is rm_boss1 and
    // 11 is rm_level9 - the Mines entry is boss1's CODE 824, not this door.
    assert!(doors.contains(&(9.0, 128.0, 1132.0)), "CODE 820 opens rm_level8a");
    for _ in 0..20 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.globals["health1"], 4.0, "the CODE 818 landing is safe");
}

/// rm_town -> rm_level1 -> rm_level4 -> rm_level5 -> rm_level7 -> rm_level8 ->
/// rm_level8a (room 9) -> rm_boss1 (room 10) -> rm_level9 (room 11).
fn mines_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

#[test]
fn the_cave_area_hands_over_through_level8a_and_the_boss_arena() {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    for want in [5.0, 7.0, 8.0, 9.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    // room 9 = rm_level8a, the densest side room of the Caves.
    assert_eq!(s.current_room, 9.0, "CODE 820 lands in rm_level8a");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 1132.0),
        "CODE 820 landing");
    assert_eq!(cast(&s, 14).len(), 5, "five obj_enemy in rm_level8a");
    assert_eq!(cast(&s, 15).len(), 3, "three obj_knifebandit");
    assert_eq!(cast(&s, 16).len(), 2, "two obj_shooter1");
    assert_eq!(cast(&s, 23).len(), 3, "three obj_wolf");
    let doors: Vec<(f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert!(doors.contains(&(10.0, 160.0, 140.0)), "CODE 821 opens rm_boss1");
    assert!(doors.contains(&(8.0, 1888.0, 236.0)), "CODE 822 returns to rm_level8");

    walk_portal(&bundle, &mut s, &asset, player, 10.0);
    assert_eq!(s.current_room, 10.0, "rm_boss1");
    assert_eq!(cast(&s, 3).len(), 2, "both obj_bossboulder gates");
    assert_eq!(cast(&s, 25).len(), 1, "obj_trex (25) waits in the arena");
    let doors: Vec<(f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert!(doors.contains(&(9.0, 1888.0, 1164.0)), "CODE 823 returns to rm_level8a");
    assert!(doors.contains(&(11.0, 128.0, 524.0)), "CODE 824 is the real Mines door");

    walk_portal(&bundle, &mut s, &asset, player, 11.0);
    assert_eq!(s.current_room, 11.0, "rm_level9, the first Mines room");
    assert_eq!(s.instances[&player].fields["x"], 128.0, "CODE 824 landing x");
    assert_eq!(cast(&s, 14).len(), 5, "rm_level9's own cast");
    let doors: Vec<(f64, f64, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect();
    assert!(doors.contains(&(10.0, 1120.0, 364.0)), "CODE 825 returns to rm_boss1");
    assert!(doors.contains(&(12.0, 224.0, 140.0)), "CODE 826 opens rm_level9a");
}

#[test]
fn the_mines_assault_rifle_mirrors_the_shotgun_path() {
    let (bundle, mut s, player, _asset) = mines_scene();
    assert_eq!(s.current_room, 11.0, "the door chain lands in rm_level9");

    let rifle = one(&s, ASSAULTRIFLE);
    let flares = cast(&s, PICKUPFLARE);
    assert!(flares.iter().any(|f| s.instances[f].fields["x"] == s.instances[&rifle].fields["x"] + 8.0
        && s.instances[f].fields["y"] == s.instances[&rifle].fields["y"] - 14.0),
        "CODE 388 offsets the Mines beacon to (x + 8, y - 14), unlike the shotgun's (x, y - 16)");
    assert_eq!(s.globals["assaultriflebought"], 0.0, "fresh start has not bought the rifle");

    collect(&bundle, &mut s, player, rifle);
    assert_eq!(s.globals["assaultriflebought"], 1.0, "CODE 389 raises assaultriflebought");
    assert_eq!(active_weapons(&s), vec!["assaultrifle".to_string()],
        "the rifle takes the only active weapon slot");
    let banner = one(&s, FOUNDWEAPON);
    assert_eq!(s.instances[&banner].alarms[0], 70, "the same 70-tick banner timeline");
}
