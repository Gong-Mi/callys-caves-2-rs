//! The weaponchange overlay: when a weapon crosses level 4/7/10, obj_UI
//! Alarm 0 (CODE 368) flips drawweaponchange and spawns obj_weaponchange
//! (id 83). Create (CODE 409) pauses ALL audio and deactivates everything
//! but itself, arming a 70-tick taplock timer; Draw (CODE 413) composites
//! the pause sheet plus the per-tier banner; CODE 411 opens the "Tap to
//! Continue" gate and CODE 412's left-press destroys the overlay, whose
//! Destroy (CODE 410) resumes audio and reactivates the world mid-patrol.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level1_scene() -> (callys_core::code_vm::Bundle, Scene, i32, i32) {
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
    s.view_positions.insert(0, (0.0, 0.0));
    let ui = s.instances.iter()
        .find(|(_, i)| i.object == 66 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent obj_UI in rm_level1");
    let bandit = s.instances.iter()
        .filter(|(_, i)| i.object == 15 && i.alive)
        .map(|(id, _)| *id)
        .max_by_key(|id| s.instances[id].fields["x"] as i64)
        .expect("knifebandit cast");
    (bundle, s, ui, bandit)
}

#[test]
fn weaponchange_overlay_freezes_the_world_then_tap_restores_it() {
    let (bundle, mut s, ui, bandit) = level1_scene();

    // Real trigger: pistol hits level 4, the fresh-start drawchange flag is
    // still armed; obj_UI Alarm 0 (CODE 368) spends it and spawns the sheet.
    assert_eq!(s.globals["drawchangepistol4"], 1.0);
    s.globals.insert("pistollevel".into(), 4.0);
    s.dispatch(&bundle, ui, 2, 0).unwrap();
    let overlay = s.instances.iter()
        .find(|(_, i)| i.object == 83 && i.alive)
        .map(|(id, _)| *id)
        .expect("CODE 368 spawns obj_weaponchange at level 4");
    assert_eq!(s.globals["drawchangepistol4"], 0.0, "banner flag consumed");
    assert_eq!(s.globals["drawweaponchange"], 0.0, "latch cleared at spawn");

    // CODE 409 Create ran inline: snd_weaponlevelup queued through the mute
    // gate, world deactivated except the overlay, 70-tick taplock timer armed.
    assert!(s.audio.iter().any(|c| c.sound == 28 && !c.looping),
        "snd_weaponlevelup (SOND 28) queued on Create");
    assert_eq!(s.instances[&overlay].alarms[0], 70);
    assert!(s.instances[&overlay].active, "overlay keeps itself active");
    assert!(!s.instances[&bandit].active, "instance_deactivate_all froze the bandit");
    assert!(s.instances.values().any(|i| i.object == 0 && i.alive && !i.active), "player frozen too");

    // 70 frozen ticks: the bandit's Step never runs, so the world is truly
    // parked - not just invisible, not stepping.
    let bx0 = s.instances[&bandit].fields["x"];
    for _ in 0..70 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.instances[&bandit].fields["x"], bx0, "no patrol while deactivated");
    assert_eq!(s.instances[&overlay].fields["taplock"], 1.0,
        "CODE 411 released the tap gate after 70 ticks");

    // CODE 413 Draw: pause sheet + tier banner + continue prompt, view 0 only.
    s.draw_view(&bundle, 0).unwrap();
    assert!(s.draws.iter().any(|d| d.sprite == 123), "spr_pause sheet drawn");
    let texts: Vec<&str> = s.texts.iter().map(|t| t.text.as_str()).collect();
    assert!(texts.contains(&"Tap to Continue"), "tap prompt after unlock: {texts:?}");
    assert!(texts.iter().any(|t| t.starts_with("Your Pistol is now level 4")),
        "pistol tier-4 banner: {texts:?}");
    // Deactivated neighbours draw nothing: the bandit's CODE 57 draw event
    // never lands while instance_deactivate_all holds it.
    assert!(s.draws.iter().all(|d| d.instance != bandit),
        "frozen bandit contributes no draws");

    // CODE 412: a real left-press destroys the sheet...
    s.mouse_pressed = true;
    s.tick(&bundle).unwrap();
    assert!(!s.instances[&overlay].alive, "tap consumed the overlay");

    // ...and CODE 410's Destroy resumes audio and reactivates the world.
    assert!(s.instances[&bandit].active, "instance_activate_all revived the cast");
    assert!(s.instances.values()
        .filter(|i| i.alive)
        .all(|i| i.active), "every live instance active again");
    assert!(s.audio_voices.iter().all(|v| !v.paused), "audio_resume_all cleared pauses");

    // Patrol physics genuinely resume: the bandit moves again.
    let mut moved = false;
    for _ in 0..20 {
        s.tick(&bundle).unwrap();
        if s.instances[&bandit].fields["x"] != bx0 { moved = true; break; }
    }
    assert!(moved, "bandit patrol resumed after the overlay closed");
}
