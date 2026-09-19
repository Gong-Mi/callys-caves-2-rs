//! The weapon-swap HUD chain in rm_level1: obj_weaponswap (id 126, sprite
//! 151) carries NO Create event — it is positioned by its own Draw (CODE 520)
//! at view_xview[0] + 360 and watches device_mouse_check_button_released for
//! devices 0..4 through collision_point. A release over the icon arms
//! alarm[0] = 1; the next tick dispatches CODE 519: the 60+ branch purchase
//! ladder rotates global.{pistol,shotgun,assaultrifle,...} = {0,...,1}, the
//! original double-increments global.weaponswapped, queues snd_weaponswap
//! (SOND 5) through the audio_is_playing gate, and spawns obj_weaponname
//! (105) at the player. Everything below is bytecode-driven; the only test
//! touch is a synthetic device release.
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
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    let swap = s.instances.iter()
        .find(|(_, i)| i.object == 126 && i.alive)
        .map(|(id, _)| *id)
        .expect("obj_weaponswap casts in rm_level1");
    s.view_positions.insert(0, (0.0, 0.0));
    (bundle, s, player, swap)
}

/// Draw once to let CODE 520 pin the icon to the view (360, 0), then release
/// device 0 exactly on its collision box center — the same HUD geometry the
/// Android renderer presents.
fn tap_the_swap_icon(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, swap: i32) {
    let _ = s.draw_view(bundle, 0).unwrap();
    let i = &s.instances[&swap];
    let x = i.fields["x"];
    let y = i.fields["y"];
    let b = s.sprite_bounds.get(&151).cloned().unwrap_or_default();
    let cx = x - b.origin_x * i.fields["image_xscale"] + b.width * i.fields["image_xscale"] / 2.0;
    let cy = y - b.origin_y * i.fields["image_yscale"] + b.height * i.fields["image_yscale"] / 2.0;
    s.touch_devices[0].x = cx;
    s.touch_devices[0].y = cy;
    s.touch_devices[0].down = true;
    s.touch_devices[0].released = true;
    let _ = s.draw_view(bundle, 0).unwrap();
    assert_eq!(s.instances[&swap].alarms[0], 1,
        "CODE 520's release+collision probe must arm alarm[0] = 1");
}

#[test]
fn hud_release_arms_ladder_and_rotates_pistol_to_shotgun() {
    let (bundle, mut s, player, swap) = level1_scene();

    // Fresh start: pistol only, nothing else bought — the ladder's final
    // "pistol && nobody bought" branch must keep pistol selected.
    assert_eq!(s.globals["pistol"], 1.0);
    assert_eq!(s.globals["shotgunbought"], 0.0);
    tap_the_swap_icon(&bundle, &mut s, swap);
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["pistol"], 1.0, "no alternate owned: rotation stays on pistol");
    assert_eq!(s.globals["weaponswapped"], 2.0, "CODE 519's double += 1 is authentic");
    assert_eq!(s.instances[&swap].alarms[0], -1, "alarm consumed");

    // Buy the shotgun behind the scenes (shop loop is separately verified),
    // then rotate: pistol==1 && shotgunbought==1 -> shotgun branch.
    s.globals.insert("shotgunbought".into(), 1.0);
    s.drain_audio();
    // Record the player's exact position right before the second tap; CODE
    // 519 spawns the label relative to obj_player at that instant, and CODE
    // 12 keeps the player drifting between our observations.
    let px2 = s.instances[&player].fields["x"];
    let py2 = s.instances[&player].fields["y"];
    tap_the_swap_icon(&bundle, &mut s, swap);
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["shotgun"], 1.0, "ladder rotates pistol -> shotgun");
    assert_eq!(s.globals["pistol"], 0.0, "old weapon deselected");
    assert_eq!(s.globals["weaponswapped"], 4.0, "second rotation, double increment again");
    assert!(s.audio.iter().any(|c| c.sound == 5 && !c.looping),
        "snd_weaponswap (SOND 5) queued through the is_playing gate");

    // CODE 519's tail spawns obj_weaponname at player.x - 16, player.y on
    // EVERY swap; CODE 462 labels it with the weapon selected at that moment.
    // Swap #1 (no alternates owned) labeled Pistol; swap #2 must have labeled
    // Shotgun — check the newest float, and keep the historic one honest.
    let pistol_id = bundle.string_table.iter().position(|st| st == "Pistol").unwrap() as f64;
    let shotgun_id = bundle.string_table.iter().position(|st| st == "Shotgun").unwrap() as f64;
    let labels: Vec<(i32, f64)> = s.instances.iter()
        .filter(|(_, i)| i.object == 105 && i.alive)
        .map(|(id, i)| (*id, i.fields["damage"]))
        .collect();
    assert!(labels.len() >= 2, "each swap floats its own label ({labels:?})");
    let newest = labels.iter().max_by_key(|(id, _)| *id).unwrap().1;
    assert_eq!(newest, shotgun_id, "the post-rotation label reads Shotgun");
    assert!(labels.iter().any(|(_, d)| *d == pistol_id), "the earlier no-op swap labeled Pistol");
    let (_, _) = (pistol_id, 0.0);
    let n = &s.instances[&labels.iter().max_by_key(|(id, _)| *id).unwrap().0];
    assert_eq!(n.fields["vspeed"], -6.0, "CODE 462 launches the label upward");
    assert_eq!(n.fields["image_speed"], 0.0, "CODE 462 pins the label sprite");
    assert_eq!(n.fields["x"], px2 - 16.0, "spawn x = player.x - 16 at dispatch time");
    // CODE 519 spawns at player.y; the label's own vspeed = -6 is integrated
    // by the SAME tick's motion pass (trace: 494 -> 488 at tick end).
    assert_eq!(n.fields["y"], py2 - 6.0, "spawn at player.y, minus one frame of -6 rise");

    // Rotation must not fire without a release: draw-only ticks stay armed-free.
    let _ = s.draw_view(&bundle, 0).unwrap();
    assert_eq!(s.instances[&swap].alarms[0], -1, "no release, no re-arm");
}

#[test]
fn ladder_follows_purchase_order_from_shotgun_to_assaultrifle() {
    let (bundle, mut s, _player, swap) = level1_scene();

    // Start from a shotgun loadout (pistol deselected), assaultrifle bought.
    s.globals.insert("pistol".into(), 0.0);
    s.globals.insert("shotgun".into(), 1.0);
    s.globals.insert("shotgunbought".into(), 1.0);
    s.globals.insert("assaultriflebought".into(), 1.0);
    s.drain_audio();

    tap_the_swap_icon(&bundle, &mut s, swap);
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["assaultrifle"], 1.0, "shotgun + assaultriflebought -> assaultrifle");
    assert_eq!(s.globals["shotgun"], 0.0);
    assert_eq!(s.globals["pistol"], 0.0);
    assert_eq!(s.globals["weaponswapped"], 2.0);

    // Wrap-around: assaultrifle selected, no rocket bought -> pistol returns.
    s.globals.insert("rocketbought".into(), 0.0);
    s.drain_audio();
    tap_the_swap_icon(&bundle, &mut s, swap);
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["pistol"], 1.0, "assaultrifle with no next buy wraps to pistol");
    assert_eq!(s.globals["assaultrifle"], 0.0);
    assert_eq!(s.globals["weaponswapped"], 4.0);

    // The rotating label re-spawns per swap with the current selection.
    let names: Vec<_> = s.instances.iter()
        .filter(|(_, i)| i.object == 105 && i.alive)
        .map(|(_, i)| i.fields["damage"])
        .collect();
    let pistol_id = bundle.string_table.iter().position(|st| st == "Pistol").unwrap() as f64;
    assert!(names.contains(&pistol_id), "latest label reads Pistol ({names:?})");
}
