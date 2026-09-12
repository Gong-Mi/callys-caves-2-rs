//! Boss 1 end-to-end: real rm_boss1 room data + original bytecode drives the
//! complete arena — obj_trex Create (CODE 154) with pwr-scaled HP, Step
//! (CODE 161) patrol/gravity/facing, bullet hits (CODE 284 trex branch),
//! lethal blow -> Alarm 0 (CODE 160) death drop cascade + global.boss1dead,
//! boulder Alarm (CODE 28/29) opening the gate, and the sprite-advance cycle
//! on the boss's multi-frame sprites. No hand-written boss logic is involved.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn boss_scene() -> (callys_core::code_vm::Bundle, Scene, i32) {
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
    let town = &asset.rooms[0];
    s.load_room_from_data(&bundle, 0, town).expect("load rm_town");
    let boss1 = &asset.rooms[10];
    assert_eq!(boss1.name, "rm_boss1");
    s.transition_to_room(&bundle, 10, boss1).expect("warp town -> rm_boss1");

    let trex = s.instances.iter()
        .find(|(_, i)| i.object == 25 && i.alive)
        .map(|(id, _)| *id)
        .expect("obj_trex materializes in rm_boss1");
    (bundle, s, trex)
}

#[test]
fn trex_create_alarms_and_patrol_run_from_real_bytecode() {
    let (bundle, mut s, trex) = boss_scene();
    let t = &s.instances[&trex];
    // CODE 154: pwr 1 -> 275 HP, alarm 2/3 patrol timers, facing 0.
    assert_eq!(t.fields["hptrex"], 275.0);
    assert_eq!(t.fields["boss1maxhp"], 275.0);
    assert_eq!(t.alarms[2], 80, "Alarm 2 patrol timer from Create");
    assert_eq!(t.alarms[3], 100, "Alarm 3 patrol timer from Create");
    let x0 = t.fields["x"];

    // CODE 161 forces facing/hpeed every step: facing 0 -> hspeed = -3 patrol.
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&trex].fields["hspeed"], -3.0, "CODE 161 left patrol");
    s.tick(&bundle).unwrap();
    let x2 = s.instances[&trex].fields["x"];
    assert!(x2 < x0, "trex patrols left ({x0} -> {x2})");

    // The boss walk sprite animates under the new engine cycle: image_index
    // moves while the sprite (56 = spr_bear) is in play and stays bounded.
    let mut moves = 0;
    for _ in 0..40 {
        let before = s.instances[&trex].fields["image_index"];
        let sprite_before = s.instances[&trex].fields["sprite_index"];
        s.tick(&bundle).unwrap();
        let after = s.instances[&trex].fields["image_index"];
        let frames = s.read(trex, -1, "image_number", None).unwrap();
        assert!(after >= 0.0 && after < frames.max(1.0), "frame {after} escaped {sprite_before}");
        if s.instances[&trex].fields["sprite_index"] == sprite_before && after != before {
            moves += 1;
        }
    }
    assert!(moves >= 20, "boss sprite cycled across the patrol ({moves} moves)");
}

#[test]
fn bullets_kill_trex_and_death_cascade_opens_the_gate() {
    let (bundle, mut s, trex) = boss_scene();
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player survived the warp");

    // Teleport the player beside the boss, facing the boss (CODE 282 uses
    // facing 0 -> hspeed +25 when the player sits to the left of trex x).
    let tx = s.instances[&trex].fields["x"];
    let ty = s.instances[&trex].fields["y"];
    s.write(player, -1, "x", None, tx - 25.0).unwrap();
    s.write(player, -1, "y", None, ty).unwrap();
    s.write(player, -1, "facing", None, 0.0).unwrap();
    // CODE 12 recomputes global.pistoldamage from weapon level every step, so
    // a pre-seeded value is not stable. Bring the boss to its last HP and let
    // the real one-damage bullet land the lethal blow.
    s.write(trex, -1, "hptrex", None, 1.0);

    // Fire through the player's original Alarm 0 (CODE 11).
    s.dispatch(&bundle, player, 2, 0).unwrap();
    let bullet = s.instances.iter()
        .find(|(_, i)| i.object == 39 && i.alive)
        .map(|(id, _)| *id)
        .expect("bullet spawned by CODE 11");
    assert_eq!(s.instances[&bullet].fields["hspeed"], 25.0);

    // CODE 284 is the bullet's own Step (running before motion integration in
    // the same tick); the shot overlaps the boss's bounds and the trex branch
    // applies exactly one global.pistoldamage.
    s.tick(&bundle).unwrap();
    assert!(!s.instances[&bullet].alive, "bullet consumed on trex hit (CODE 284)");
    let t = &s.instances[&trex];
    assert_eq!(t.fields["hptrex"], 0.0, "1.0 pistoldamage took the last HP through the real hit");
    assert_eq!(t.fields["flashing"], 1.0, "trex flash on hit");
    assert_eq!(s.globals["pistolxp"], 1.0, "weapon xp refunded by the trex branch");

    // CODE 161: hptrex <= 0 -> alarm[0] = 1 (next trex Step); the alarm then
    // dispatches CODE 160's death cascade: snd_explode, boss1dead, drops,
    // kill_object. Step and alarm phases are ordered per tick, so poll.
    let alive_before = s.instances.values().filter(|i| i.alive && i.active).count();
    for _ in 0..5 {
        s.tick(&bundle).unwrap();
        if !s.instances[&trex].alive { break; }
    }
    let t = &s.instances[&trex];
    assert!(!t.alive, "CODE 160 action_kill_object removes the boss");
    assert_eq!(s.globals["boss1dead"], 1.0, "global.boss1dead latched by CODE 160");
    assert!(s.audio.iter().any(|c| c.sound == 7 && !c.looping), "snd_explode queued on death");

    // CODE 160 drop cascade with the Create's own drop config
    // (xpdrop 1, hpdrop 1, gemdropenabled 1; coindrop is seeded choose()).
    let spawned: Vec<_> = s.instances.values()
        .filter(|i| i.alive && matches!(i.object, 59 | 60 | 61 | 62))
        .map(|i| i.object)
        .collect();
    assert!(spawned.contains(&59), "obj_gem drop");
    assert!(spawned.contains(&62), "obj_health drop");
    assert!(spawned.iter().filter(|o| **o == 61).count() >= 10, "obj_XPorb x10 drop");
    let coins = spawned.iter().filter(|o| **o == 60).count();
    assert!((5..=30).contains(&coins), "silvercoin cascade per coindrop tier ({coins})");
    assert!(s.instances.values().filter(|i| i.alive && i.active).count() > alive_before,
        "the death cascade materialized the loot field");

    // Boulder gate: CODE 29 destroys obj_bossboulder once boss1dead == 1.
    let boulders: Vec<_> = s.instances.iter()
        .filter(|(_, i)| i.object == 3 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    assert!(!boulders.is_empty(), "rm_boss1 spawns boulders");
    for _ in 0..31 {
        s.tick(&bundle).unwrap();
    }
    for b in &boulders {
        assert!(!s.instances[b].alive, "CODE 29 boulder opens after boss death");
    }
}
