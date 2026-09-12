//! rm_level2's lone obj_enemy2 (id 22, sprite spr_enemy2 12 frames): the
//! spider-jumper AI driven purely by original bytecode — Create (CODE 123)
//! 40 HP at pwr1 with a 15-tick alarm[2] rhythm, the jump cycle (CODE 130
//! within 192 px arms jumping; CODE 131 launch: move_towards_point speed 4,
//! vspeed -8, spr_spiderattack, alarm[7]=60; CODE 125 reset back to
//! spr_enemy2), the CODE 12 hitenemy2 contact branch, and the CODE 284 hit2
//! bullet branch into the CODE 132 death cascade. The 1-frame attack sprite
//! also exercises the animation engine's single-frame clamp.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level2_scene() -> (callys_core::code_vm::Bundle, Scene, i32, i32) {
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
    let e2 = s.instances.iter()
        .find(|(_, i)| i.object == 22 && i.alive)
        .map(|(id, _)| *id)
        .expect("obj_enemy2 casts exactly once in rm_level2");
    (bundle, s, player, e2)
}

#[test]
fn enemy2_jump_cycle_arms_launches_and_resets_attack_sprite() {
    let (bundle, mut s, player, e2) = level2_scene();

    // CODE 123: pwr-1 tier at level <= 5 -> 40 HP; the 15-tick rhythm starts
    // at Create.
    assert_eq!(s.instances[&e2].fields["hptwo"], 40.0);
    assert_eq!(s.instances[&e2].alarms[2], 15, "CODE 123 alarm[2] rhythm");

    // Park the player 100 px to the left (inside CODE 130's 192 px trigger
    // window), invulnerable so a landed jump cannot spend HP mid-observation.
    let ex = s.instances[&e2].fields["x"];
    let ey = s.instances[&e2].fields["y"];
    s.write(player, -1, "x", None, ex - 100.0).unwrap();
    s.write(player, -1, "y", None, ey).unwrap();
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
    s.instances.get_mut(&e2).unwrap().active = true;

    // Evidence from the live trace: alarm[1] launch (CODE 131) lands on the
    // same tick the alarm loop already advanced alarm[7] once (set 60 -> 59),
    // motion integration eats 0.6 of the -8 launch vertical, and the aim at
    // (player -100, -15) over the jump arc gives hspeed ~ -3.96 while airborne,
    // zeroed once CODE 133's x+hspeed wall probe pins the spider in place.
    // A full cycle is: walk sprite -> attack-sprite launch with a fresh
    // upward impulse -> walk sprite again -> re-launch.
    let mut launches = 0;
    let mut walk_gap = false;
    let mut launch_alarm_ok = false;
    let mut rhythm_rearmed = false;
    let mut was_attack = false;
    let mut prev_vs = 0.0;
    for _ in 0..90 {
        s.tick(&bundle).unwrap();
        let i = &s.instances[&e2];
        let active_now = i.active;
        let spr = i.fields.get("sprite_index").copied().unwrap_or(-1.0);
        let vs = i.fields.get("vspeed").copied().unwrap_or(0.0);
        if !active_now {
            s.instances.get_mut(&e2).unwrap().active = true;
            continue;
        }
        if spr == 61.0 && vs < prev_vs - 6.5 {
            // fresh launch: upward impulse applied this tick
            launches += 1;
            if i.alarms[7] < 60 && i.alarms[7] > 20 { launch_alarm_ok = true; }
        }
        if spr == 61.0 { was_attack = true; }
        else if was_attack { walk_gap = true; }
        if i.alarms[2] == 15 { rhythm_rearmed = true; }
        prev_vs = vs;
        let frame = i.fields["image_index"];
        let frames = s.read(e2, -1, "image_number", None).unwrap();
        assert!(frame >= 0.0 && frame < frames.max(1.0), "frame {frame} escaped {spr}");
        if launches >= 2 && walk_gap { break; }
    }
    assert!(launches >= 2, "CODE 130/131 launched the jump cycle {launches} times");
    assert!(walk_gap, "CODE 133 returned the spider to the walk sprite between launches");
    assert!(launch_alarm_ok, "CODE 131 armed the 60-tick alarm[7] reset window");
    assert!(rhythm_rearmed, "CODE 130 re-armed the 15-tick alarm[2] rhythm");
    // The 1-frame attack sprite pinned image_index at 0 during its window
    // (animation single-frame clamp); the 12-frame walk sprite stays bounded.
    let frame = s.instances[&e2].fields["image_index"];
    let frames = s.read(e2, -1, "image_number", None).unwrap();
    assert!(frame >= 0.0 && frame < frames.max(1.0), "walk frame {frame} bounded");
}

#[test]
fn player_enemy2_contact_costs_health_with_the_hitenemy2_branch() {
    let (bundle, mut s, player, e2) = level2_scene();

    // CODE 12's hitenemy2 branch mirrors hitenemy: park the spider just to
    // the player's right so invulnerable + sliding1 arms.
    let px = s.instances[&player].fields["x"];
    let py = s.instances[&player].fields["y"];
    s.write(e2, -1, "x", None, px + 2.0).unwrap();
    s.write(e2, -1, "y", None, py + 1.0).unwrap();
    s.instances.get_mut(&e2).unwrap().active = true;
    s.write(player, -1, "facing", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 0.0).unwrap();
    let hp0 = s.globals["health1"];

    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["health1"], hp0 - 1.0, "hitenemy2 spends one health1");
    let p = &s.instances[&player];
    assert_eq!(p.fields["flashing"], 1.0);
    assert_eq!(p.fields["invulnerable"], 1.0, "spider on the right arms invulnerable");
    assert_eq!(p.fields.get("sliding1").copied().unwrap_or(0.0), 1.0);
    assert_eq!(p.alarms[4], 10);
    assert_eq!(p.alarms[7], 20);
    assert_eq!(p.alarms[8], 23);
    assert!(s.audio.iter().any(|c| c.sound == 24 && !c.looping),
        "snd_impactsound5 queued on spider contact");
}

#[test]
fn bullet_enemy2_kill_runs_the_code132_cascade() {
    let (bundle, mut s, player, e2) = level2_scene();

    // Duel at 40 px with the player carrying the original invulnerable state;
    // last HP, one real 1.0 pistoldamage bullet from CODE 11 finishes it.
    s.write(player, -1, "x", None, 500.0).unwrap();
    s.write(player, -1, "y", None, 584.0).unwrap();
    s.write(player, -1, "facing", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(e2, -1, "hptwo", None, 1.0).unwrap();
    s.write(e2, -1, "x", None, 540.0).unwrap();
    s.write(e2, -1, "y", None, 584.0).unwrap();
    s.instances.get_mut(&e2).unwrap().active = true;

    s.dispatch(&bundle, player, 2, 0).unwrap();
    let bullet = s.instances.iter()
        .find(|(_, i)| i.object == 39 && i.alive)
        .map(|(id, _)| *id)
        .expect("bullet from CODE 11");

    let hp0 = s.globals["health1"];
    for _ in 0..4 {
        if !s.instances[&bullet].alive { break; }
        s.tick(&bundle).unwrap();
    }
    assert!(!s.instances[&bullet].alive, "CODE 284 hit2 branch consumed the bullet");
    assert_eq!(s.instances[&e2].fields["hptwo"], 0.0, "hptwo 1 -> 0 through CODE 284");
    assert_eq!(s.globals["pistolxp"], 1.0, "hit2 refunds weapon xp");

    let mut died = false;
    for _ in 0..6 {
        if !s.instances[&e2].alive { died = true; break; }
        s.tick(&bundle).unwrap();
    }
    assert!(died, "CODE 133 armed alarm[0], CODE 132 killed the spider");
    assert_eq!(s.globals["health1"], hp0, "the duel spent no player health");
    assert!(s.audio.iter().any(|c| c.sound == 7 && !c.looping), "snd_explode queued");
    assert!(s.instances.values().any(|i| i.alive && i.object == 61),
        "obj_XPorb drop (xpdrop=1, CODE 132)");
    // gemdropenabled defaults to 1 from the fresh-start globals, CODE 132's
    // first drop branch: gem must be on the field.
    assert!(s.instances.values().any(|i| i.alive && i.object == 59),
        "obj_gem drop under gemdropenabled=1");
    let loot = s.instances.values().filter(|i| i.alive && matches!(i.object, 58 | 60 | 62)).count();
    assert!(loot >= 1, "hpdrop/coindrop tier landed ({loot})");
}
