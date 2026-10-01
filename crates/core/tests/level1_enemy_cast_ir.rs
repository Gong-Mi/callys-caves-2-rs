//! rm_level1 enemy cast beyond the knifebandit: obj_enemy (id 14, 5 instances)
//! patrol physics from CODE 47, the player's contact-damage branch (CODE 12
//! hitenemy: flashing, global.health1 -= 1, direction-based invulnerability +
//! knockback alarms 4/7/8, snd_impactsound5 id 24), and the bullet's obj_enemy
//! hit branch (CODE 284) ending in the CODE 46 death cascade. Everything is
//! driven by real bytecode in the real room; no hand-written enemy logic.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level1_scene() -> (callys_core::code_vm::Bundle, Scene, i32) {
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
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("warp town -> rm_level1");
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player")
    ;
    (bundle, s, player)
}

/// CODE 361 (obj_bg Alarm 2) deactivates enemies >= 450 px from the player;
/// pick the nearest obj_enemy so the patrol window stays observable.
fn nearest_enemy(s: &Scene, player: i32) -> i32 {
    let px = s.instances[&player].fields["x"];
    let py = s.instances[&player].fields["y"];
    s.instances.iter()
        .filter(|(_, i)| i.object == 14 && i.alive)
        .map(|(id, i)| (*id, (i.fields["x"] - px).hypot(i.fields["y"] - py)))
        .min_by(|a, b| a.1.total_cmp(&b.1))
        .map(|(id, _)| id)
        .expect("obj_enemy cast in rm_level1")
}

#[test]
fn obj_enemy_patrols_with_step_gravity_and_animation() {
    let (bundle, mut s, player) = level1_scene();
    let cast: Vec<_> = s.instances.iter()
        .filter(|(_, i)| i.object == 14 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    assert_eq!(cast.len(), 5, "rm_level1 casts 5 obj_enemy instances");
    let e = nearest_enemy(&s, player);

    // CODE 40 Create: pwr-1 HP tier gives hp = 10 at global.level <= 5.
    assert_eq!(s.instances[&e].fields["hp"], 10.0);

    let mut patrol_moves = 0;
    let mut active_ticks = 0;
    for _ in 0..40 {
        let before = s.instances[&e].fields["x"];
        s.tick(&bundle).unwrap();
        let i = &s.instances[&e];
        if !i.alive { break; }
        if !i.active { continue; }
        active_ticks += 1;
        let h = i.fields.get("hspeed").copied().unwrap_or(0.0);
        assert!(h == 4.0 || h == -4.0 || h == 0.0,
            "CODE 47 patrol hspeed set, got {h}");
        if i.fields["x"] != before { patrol_moves += 1; }
        let frame = i.fields["image_index"];
        let frames = s.read(e, -1, "image_number", None).unwrap();
        assert!(frame >= 0.0 && frame < frames.max(1.0), "enemy frame {frame} escaped");
    }
    assert!(active_ticks >= 30, "the near enemy stayed active {active_ticks}/40");
    assert!(patrol_moves >= 20, "enemy visibly patrols ({patrol_moves} moving ticks)");
}

#[test]
fn player_enemy_contact_costs_health_and_arms_knockback_chain() {
    let (bundle, mut s, player) = level1_scene();
    let e = nearest_enemy(&s, player);

    // Park the enemy just to the player's right: CODE 12's hitenemy branch
    // arms invulnerable + sliding1 on hitenemy.x > x (exact-equal x is the
    // original's own boundary case and arms neither).
    let px = s.instances[&player].fields["x"];
    let py = s.instances[&player].fields["y"];
    s.write(e, -1, "x", None, px + 2.0);
    s.write(e, -1, "y", None, py + 1.0);
    s.instances.get_mut(&e).unwrap().active = true;
    s.write(player, -1, "facing", None, 0.0);
    s.write(player, -1, "invulnerable", None, 0.0);
    s.write(player, -1, "invulnerable2", None, 0.0);
    s.write(player, -1, "sliding1", None, 0.0);
    s.write(player, -1, "sliding2", None, 0.0);
    let hp0 = s.globals["health1"];
    assert!(hp0 >= 2.0, "fresh start carries real HP");

    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["health1"], hp0 - 1.0, "contact costs exactly one global.health1");
    let p = &s.instances[&player];
    assert_eq!(p.fields["flashing"], 1.0, "CODE 12 flashing");
    assert_eq!(p.fields["invulnerable"], 1.0, "enemy on the right arms invulnerable");
    assert_eq!(p.fields.get("sliding1").copied().unwrap_or(0.0), 1.0, "sliding1 knockback armed");
    assert_eq!(p.alarms[4], 10, "knockback timer alarm[4]=10");
    assert_eq!(p.alarms[7], 20, "sprite restore alarm[7]=20");
    assert_eq!(p.alarms[8], 23, "invulnerability window alarm[8]=23");
    assert!(s.audio.iter().any(|c| c.sound == 24 && !c.looping),
        "snd_impactsound5 (SOND 24) queued on enemy contact");

    // Invulnerability prevents a second immediate hit while the alarms run.
    for _ in 0..8 {
        s.write(e, -1, "x", None, s.instances[&player].fields["x"] + 2.0);
        s.instances.get_mut(&e).unwrap().active = true;
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], hp0 - 1.0, "no double-dip while invulnerable/alarm[4] runs");
}

#[test]
fn bullet_enemy_hit_branch_leads_to_death_cascade() {
    let (bundle, mut s, player) = level1_scene();
    let e = nearest_enemy(&s, player);

    // Duel at 40 px: player carries the original post-hit invulnerability so
    // CODE 12's contact branch cannot spend HP while the bullet does its job.
    s.write(player, -1, "x", None, 500.0);
    s.write(player, -1, "y", None, 584.0);
    s.write(player, -1, "facing", None, 0.0); // CODE 282: hspeed +25 right
    s.write(player, -1, "invulnerable", None, 1.0);
    s.write(e, -1, "hp", None, 1.0);
    s.write(e, -1, "x", None, 540.0);
    s.write(e, -1, "y", None, 584.0);
    s.instances.get_mut(&e).unwrap().active = true;

    s.dispatch(&bundle, player, 2, 0).unwrap(); // CODE 11 fires obj_bullet
    let bullet = s.instances.iter()
        .find(|(_, i)| i.object == 39 && i.alive)
        .map(|(id, _)| *id)
        .expect("bullet from CODE 11");
    assert_eq!(s.instances[&bullet].fields["hspeed"], 25.0);

    let hp0 = s.globals["health1"];
    s.tick(&bundle).unwrap();
    assert!(!s.instances[&bullet].alive, "bullet consumed on the enemy (CODE 284)");
    assert_eq!(s.instances[&e].fields["hp"], 0.0, "pistoldamage 1.0 applied through the trex-cast branch set");
    assert_eq!(s.globals["pistolxp"], 1.0, "weapon xp refunded by the obj_enemy branch");

    // hp <= 0 arms CODE 47's alarm[0] = 1; the alarm dispatches CODE 46:
    // snd_explode + drops + destroy. Poll up to 5 ticks for the death.
    let mut died = false;
    for _ in 0..5 {
        if !s.instances[&e].alive { died = true; break; }
        s.tick(&bundle).unwrap();
    }
    assert!(died, "CODE 46 death cascade removed the enemy");
    assert_eq!(s.globals["health1"], hp0, "the duel costs no player health");
    assert!(s.audio.iter().any(|c| c.sound == 7 && !c.looping), "snd_explode queued");

    // Death drops from CODE 46: xpdrop=1 fixed in CODE 40 -> obj_XPorb; the
    // choose()-seeded hpdrop/gemdrop/coin tier lands at least one pickup.
    assert!(s.instances.values().any(|i| i.alive && i.object == 61), "obj_XPorb drop (xpdrop=1)");
    let loot = s.instances.values().filter(|i| i.alive && matches!(i.object, 58 | 59 | 60 | 62)).count();
    assert!(loot >= 1, "gem/coin/health drop tier present ({loot})");
}
