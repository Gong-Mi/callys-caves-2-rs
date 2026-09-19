//! rm_level4's ground pack: obj_wolf (id 23) through the same bytecode mold
//! as obj_enemy2 but with wolf-specific geometry — CODE 135 Create (40 HP at
//! pwr1, 15-tick alarm[2] rhythm), CODE 143 Step patrol (hspeed ±4 forced,
//! deeper 20 px forward probes and 40 px cliff guards, stunned choose() onto
//! spr_wolfhurt 105), CODE 12's hitwolf contact branch and CODE 284's hitwolf
//! bullet branch into CODE 142's death cascade. The 12-frame spr_wolf sprite
//! cycles under the engine animation contract the whole time.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level4_scene() -> (callys_core::code_vm::Bundle, Scene, i32, Vec<i32>) {
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
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("warp town -> rm_level4");
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    let wolves: Vec<_> = s.instances.iter()
        .filter(|(_, i)| i.object == 23 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    (bundle, s, player, wolves)
}

/// Nearest wolf to the player (CODE 361 dormancy keeps far packs asleep).
fn nearest_wolf(s: &Scene, player: i32, wolves: &[i32]) -> i32 {
    let px = s.instances[&player].fields["x"];
    let py = s.instances[&player].fields["y"];
    wolves.iter()
        .map(|id| (*id, (s.instances[id].fields["x"] - px).hypot(s.instances[id].fields["y"] - py)))
        .min_by(|a, b| a.1.total_cmp(&b.1))
        .map(|(id, _)| id)
        .expect("wolf cast in rm_level4")
}

#[test]
fn wolf_patrol_and_stunned_choice_follow_the_original_mold() {
    let (bundle, mut s, player, wolves) = level4_scene();
    assert_eq!(wolves.len(), 2, "rm_level4 casts 2 wolves");
    let w = nearest_wolf(&s, player, &wolves);

    // CODE 135: pwr1 tier -> 40 HP; 15-tick alarm[2] jump-bait rhythm; walk
    // sprite 106 with 12 frames.
    let i = &s.instances[&w];
    assert_eq!(i.fields["hpwolf"], 40.0);
    assert_eq!(i.alarms[2], 15, "CODE 135 alarm[2] rhythm");
    assert_eq!(i.fields["sprite_index"], 106.0);
    assert_eq!(s.read(w, -1, "image_number", None).unwrap(), 12.0);

    let mut moves = 0;
    let mut active_ticks = 0;
    let mut frames_bounded = true;
    for _ in 0..40 {
        if !s.instances[&w].active { s.instances.get_mut(&w).unwrap().active = true; }
        let before = s.instances[&w].fields["x"];
        s.tick(&bundle).unwrap();
        let i = &s.instances[&w];
        if !i.alive { break; }
        active_ticks += 1;
        let h = i.fields.get("hspeed").copied().unwrap_or(0.0);
        assert!(h == 4.0 || h == -4.0 || h == 0.0, "CODE 143 hspeed set, got {h}");
        if i.fields["x"] != before { moves += 1; }
        let f = i.fields["image_index"];
        if !(f >= 0.0 && f < 12.0) { frames_bounded = false; }
    }
    assert!(active_ticks >= 30, "near wolf stayed active {active_ticks}/40");
    assert!(moves >= 20, "wolf patrols ({moves} moving ticks)");
    assert!(frames_bounded, "12-frame walk cycle bounded");

    // CODE 143 stunned branch: choose(spr_wolfhurt, spr_wolf) is random but
    // only ever between 105 and 106, and vspeed is zeroed.
    s.write(w, -1, "stunned", None, 1.0).unwrap();
    for _ in 0..6 {
        if !s.instances[&w].active { s.instances.get_mut(&w).unwrap().active = true; }
        s.tick(&bundle).unwrap();
        let spr = s.instances[&w].fields["sprite_index"];
        assert!(spr == 105.0 || spr == 106.0, "stunned choose domain 105/106, got {spr}");
    }
}

#[test]
fn wolf_contact_costs_health_and_the_bullet_finishes_the_pack() {
    let (bundle, mut s, player, wolves) = level4_scene();
    let w = nearest_wolf(&s, player, &wolves);

    // CODE 12 hitwolf branch: wolf 2 px to the player's right arms
    // invulnerable + sliding1 exactly like hitenemy/hitenemy2.
    let px = s.instances[&player].fields["x"];
    let py = s.instances[&player].fields["y"];
    s.write(w, -1, "x", None, px + 2.0).unwrap();
    s.write(w, -1, "y", None, py + 1.0).unwrap();
    s.instances.get_mut(&w).unwrap().active = true;
    s.write(player, -1, "facing", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 0.0).unwrap();
    let hp0 = s.globals["health1"];
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["health1"], hp0 - 1.0, "hitenemy wolf branch spends 1");
    let p = &s.instances[&player];
    assert_eq!(p.fields["invulnerable"], 1.0);
    assert_eq!(p.fields.get("sliding1").copied().unwrap_or(0.0), 1.0);
    assert_eq!(p.alarms[4], 10);
    assert_eq!(p.alarms[7], 20);
    assert_eq!(p.alarms[8], 23);
    assert!(s.audio.iter().any(|c| c.sound == 24 && !c.looping), "impactsound5");

    // Duel: last HP wolf 40 px downrange, invulnerable player, real bullet
    // through CODE 284's hitwolf branch -> CODE 143 alarm[0] -> CODE 142.
    let px2 = s.instances[&player].fields["x"];
    let py2 = s.instances[&player].fields["y"];
    s.write(w, -1, "hpwolf", None, 1.0).unwrap();
    s.write(w, -1, "x", None, px2 + 40.0).unwrap();
    s.write(w, -1, "y", None, py2).unwrap();
    s.instances.get_mut(&w).unwrap().active = true;
    s.drain_audio();
    s.dispatch(&bundle, player, 2, 0).unwrap();
    let bullet = s.instances.iter()
        .filter(|(_, i)| i.object == 39 && i.alive)
        .map(|(id, _)| *id)
        .last()
        .expect("bullet from CODE 11");

    let mut killed = false;
    for _ in 0..8 {
        if !s.instances[&bullet].alive && !s.instances[&w].alive { killed = true; break; }
        if !s.instances[&w].active { s.instances.get_mut(&w).unwrap().active = true; }
        s.tick(&bundle).unwrap();
    }
    assert!(killed, "CODE 284 hitwolf -> CODE 142 removed the wolf");
    assert!(s.globals["pistolxp"] >= 1.0, "hitwolf refunded weapon xp");
    assert_eq!(s.globals["health1"], hp0 - 1.0, "only the pre-duel contact spent health");
    assert!(s.audio.iter().any(|c| c.sound == 7 && !c.looping), "snd_explode queued");
    assert!(s.instances.values().any(|i| i.alive && i.object == 61),
        "obj_XPorb drop (xpdrop=1, CODE 142)");
    let loot = s.instances.values().filter(|i| i.alive && matches!(i.object, 58 | 59 | 60 | 62)).count();
    assert!(loot >= 1, "gemdrop/hpdrop/coin tier landed ({loot})");
}
