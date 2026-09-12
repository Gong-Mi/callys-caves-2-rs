//! rm_level3: the deep portal leg (rm_level2 -> CODE 807 -> rm_level3) plus
//! the airborne obj_bat (id 31) lifecycle from original bytecode only —
//! CODE 234 wake probe (player within 150 px AND below -> awake), CODE 242
//! Step handoff (awake arms alarm[1]; moving flies spr_batfly at speed 3),
//! CODE 240/239 phase sprites spr_batawake -> moving, the CODE 12
//! hitenemybat contact branch, and CODE 284 hit4 -> CODE 241 death. rm_level3
//! also proves the room carries the 59-cell water hazard field.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level2_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
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
    s.transition_to_room(&bundle, 2, &asset.rooms[2]).expect("warp town -> rm_level2");
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, s, player, asset)
}

/// Walk the player onto the level2 portal pinned to `want_room` (CODE 13)
/// and pump the client-equivalent transition.
fn walk_portal(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, want_room: f64) {
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == 69 && i.alive && i.active)
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

fn bats(s: &Scene) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == 31 && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

#[test]
fn portal_level2_to_level3_delivers_the_bat_and_water_cast() {
    let (bundle, mut s, player, asset) = level2_scene();
    walk_portal(&bundle, &mut s, &asset, player, 3.0);
    assert_eq!(s.current_room, 3.0, "CODE 807 pinned warproom 3");
    // CODE 807 reposition: warpx = 128, warpy = 140 (the deep-rm_level3 entry).
    let p = &s.instances[&player];
    assert_eq!(p.fields["x"], 128.0);
    assert_eq!(p.fields["y"], 140.0);
    // rm_level3's distinct cast survived the data-driven load.
    assert_eq!(bats(&s).len(), 2, "rm_level3 casts 2 bats");
    let water = s.instances.values().filter(|i| i.object == 9 && i.alive).count();
    assert_eq!(water, 59, "rm_level3 carries the 59-cell water field");
    let chests = s.instances.values().filter(|i| i.object == 100 && i.alive).count();
    assert_eq!(chests, 6, "rm_level3 casts 6 treasure chests");
    // A few clean frames in the new room: no stray dispatch errors.
    for _ in 0..20 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], 4.0, "standing clear costs nothing");
}

#[test]
fn bat_sleep_wake_fly_phase_machine_runs_from_alarm7_probe() {
    let (bundle, mut s, player, asset) = level2_scene();
    walk_portal(&bundle, &mut s, &asset, player, 3.0);
    let bat = *bats(&s).iter()
        .max_by_key(|id| s.instances[*id].fields["y"] as i64)
        .expect("bat present");
    // CODE 232 Create starts asleep on spr_bat (66) with the 30-tick probe.
    assert_eq!(s.instances[&bat].fields["sprite_index"], 66.0, "bat sleeps as spr_bat");
    assert_eq!(s.instances[&bat].fields["awake"], 0.0);

    // CODE 234 probe needs: within 150 px AND the player BELOW the bat.
    let bx = s.instances[&bat].fields["x"];
    let by = s.instances[&bat].fields["y"];
    s.write(player, -1, "x", None, bx).unwrap();
    s.write(player, -1, "y", None, by + 100.0).unwrap();
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();

    let mut saw_awake = false;
    let mut saw_reprobe = false;
    let mut saw_flying = false;
    let mut closing = 0;
    let mut prev_dist = f64::MAX;
    for _ in 0..80 {
        s.tick(&bundle).unwrap();
        if !s.instances[&bat].active { s.instances.get_mut(&bat).unwrap().active = true; }
        let i = &s.instances[&bat];
        let spr = i.fields.get("sprite_index").copied().unwrap_or(-1.0);
        let awake = i.fields.get("awake").copied().unwrap_or(-1.0);
        let moving = i.fields.get("moving").copied().unwrap_or(-1.0);
        if awake == 1.0 {
            saw_awake = true;
            // Trace t29: the waking tick also re-arms CODE 234's own probe
            // (alarm[7] = 30 at tick end).
            if i.alarms[7] == 30 { saw_reprobe = true; }
        }
        if spr == 67.0 && moving == 1.0 {
            // The alarm sweep decrements indices ascending, so CODE 240's
            // alarm[2]=1 fires CODE 239 inside the SAME sweep (moving=1) and
            // CODE 242's fly branch overwrites spr_batawake before the tick
            // ends: 66 -> 67 with awake latching for one tick is the
            // tick-end-observable phase chain.

            saw_flying = true;
            let px = s.instances[&player].fields["x"];
            let py = s.instances[&player].fields["y"];
            let d = ((px - i.fields["x"]).powi(2) + (py - i.fields["y"]).powi(2)).sqrt();
            if prev_dist - d > 2.5 { closing += 1; }
            prev_dist = d;
        }
        if saw_flying && closing >= 5 { break; }
    }
    assert!(saw_awake, "CODE 234 armed awake under the player-below probe");
    assert!(saw_reprobe, "CODE 234 re-arms its own 30-tick probe after firing");
    assert!(saw_flying, "CODE 239/242 switched to spr_batfly with moving=1");
    assert!(closing >= 5, "move_towards_point(3) closes distance each fly tick ({closing})");
    // The 42-frame fly sprite animates under the engine cycle.
    let frame = s.instances[&bat].fields["image_index"];
    let frames = s.read(bat, -1, "image_number", None).unwrap();
    assert!(frame >= 0.0 && frame < frames.max(1.0), "fly frame {frame} bounded");
}

#[test]
fn bat_contact_spends_health_then_the_bullet_finishes_it() {
    let (bundle, mut s, player, asset) = level2_scene();
    walk_portal(&bundle, &mut s, &asset, player, 3.0);
    let bat = *bats(&s).iter()
        .max_by_key(|id| s.instances[*id].fields["y"] as i64)
        .expect("bat present");

    // CODE 12 hitenemybat contact: park the sleeping bat 2 px to the right.
    let px = s.instances[&player].fields["x"];
    let py = s.instances[&player].fields["y"];
    s.write(bat, -1, "x", None, px + 2.0).unwrap();
    s.write(bat, -1, "y", None, py + 1.0).unwrap();
    s.write(player, -1, "facing", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 0.0).unwrap();
    let hp0 = s.globals["health1"];
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["health1"], hp0 - 1.0, "hitenemybat spends one health1");
    let p = &s.instances[&player];
    assert_eq!(p.fields["invulnerable"], 1.0, "right-side bat arms invulnerable");
    assert_eq!(p.fields.get("sliding1").copied().unwrap_or(0.0), 1.0);
    assert_eq!(p.alarms[4], 10);
    assert_eq!(p.alarms[7], 20);
    assert_eq!(p.alarms[8], 23);

    // Aerial duel: last HP, real bullet from CODE 11, CODE 242 arms
    // alarm[0] once hpfour <= 0, CODE 241 destroys and cascades. The bat
    // moves 40 px downrange from the player (trace-proven geometry); the
    // player keeps the CODE 12 knockback's invulnerable state, so no extra
    // health spend while the shot travels.
    let px2 = s.instances[&player].fields["x"];
    let py2 = s.instances[&player].fields["y"];
    s.write(bat, -1, "hpfour", None, 1.0).unwrap();
    s.write(bat, -1, "x", None, px2 + 40.0).unwrap();
    s.write(bat, -1, "y", None, py2).unwrap();
    s.write(player, -1, "facing", None, 0.0).unwrap();
    s.dispatch(&bundle, player, 2, 0).unwrap(); // CODE 11 shot
    let bullets: Vec<_> = s.instances.iter()
        .filter(|(_, i)| i.object == 39 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    assert!(!bullets.is_empty(), "bullet queued for the aerial duel");

    // Trace evidence: CODE 284 consumed the bullet (hpfour 1 -> 0, pistolxp 1)
    // and CODE 242 armed alarm[0] = 1, but CODE 361's dormancy sweep then hit
    // the far roost bat (>= 450 px) with instance_deactivate_object(id), which
    // GMS applies to ALL obj_bat instances - the duel bat sleeps with the
    // death alarm pending. Walking the player back over the roost mirrors
    // CODE 361's instance_activate_region(player +/- 400) reactivation, and
    // the live alarm[0] then dispatches CODE 241.
    let mut killed = false;
    for _ in 0..8 {
        if !s.instances[&bat].active {
            let bxx = s.instances[&bat].fields["x"];
            let byy = s.instances[&bat].fields["y"];
            s.write(player, -1, "x", None, bxx).unwrap();
            s.write(player, -1, "y", None, byy).unwrap();
            s.instances.get_mut(&bat).unwrap().active = true;
        }
        s.tick(&bundle).unwrap();
        if !s.instances[&bat].alive { killed = true; break; }
    }
    assert!(killed, "CODE 242 armed alarm[0]; CODE 241 destroyed the bat");
    assert_eq!(s.instances[&bat].fields["hpfour"], 0.0, "CODE 284 applied the damage pre-death");
    assert!(s.globals["pistolxp"] >= 1.0, "hit4 branch refunded weapon xp");
    assert!(s.audio.iter().any(|c| c.sound == 7 && !c.looping), "snd_explode queued");
}
