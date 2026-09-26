//! Render batch 5 — Combat floaters, level-up badges, audio toggles, and data erase dialog.
//!
//! Covers:
//! 1. Level-up badges:
//!    `obj_levelup` (63, Draw CODE 356): draws `spr_levelup` (35) and triggers particle burst.
//!    `obj_weaponlevelup` (64, Draw CODE 359): draws `spr_weaponlevelup` (34).
//! 2. Combat floaters:
//!    `obj_weaponname` (105, Draw CODE 464): floating damage/weapon text with alpha fade.
//!    `obj_dodged` (106, Draw CODE 467): floating "Dodged!" text (STRG 856) with alpha fade.
//! 3. Audio settings toggles:
//!    `obj_volume` (107, Draw CODE 469): swaps "Sounds: ON" (857) vs "Sounds: OFF" (858).
//!    `obj_volumemusic` (109, Draw CODE 473): swaps "Music: ON" (860) vs "Music: OFF" (861).
//! 4. Erase data dialog:
//!    `obj_restoredata` (115, Draw CODE 487): "Erase Data" (873).
//!    `obj_areyousure` (114, Draw CODE 484): "Erase Data?" (871).
//!    `obj_yesrestoredata` (112, Draw CODE 479): "Yes" (869).
//!    `obj_norestoredata` (113, Draw CODE 482): "No" (870).
//! 5. Pause HUD button & pause backdrop:
//!    `obj_pausebutton` (125, Draw CODE 518): pause icon button at (vx+320, vy).
//!    `obj_pause` (122, Draw CODE 510): full-screen pause backdrop (spr 123) + coin score display.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds, TextCommand};
use std::path::Path;

const LEVELUP: i32 = 63;
const WEAPONLEVELUP: i32 = 64;
const WEAPONNAME: i32 = 105;
const DODGED: i32 = 106;
const VOLUME: i32 = 107;
const VOLUMEMUSIC: i32 = 109;
const YESRESTORE: i32 = 112;
const NORESTORE: i32 = 113;
const AREYOUSURE: i32 = 114;
const RESTOREDATA: i32 = 115;
const PAUSE: i32 = 122;
const PAUSEBUTTON: i32 = 125;

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

fn fresh(bundle: &Bundle, asset: &GameDroidAsset) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(bundle);
    s.init_fresh_start_globals();
    for (sid, sprite) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sprite.width as f64,
            height: sprite.height as f64,
            origin_x: sprite.origin_x as f64,
            origin_y: sprite.origin_y as f64,
            frames: sprite.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(bundle, 0, &asset.rooms[0]).unwrap();
    s.view_positions.insert(0, (0.0, 0.0));
    s
}

fn draws_from(s: &Scene, code: usize) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == code).cloned().collect()
}

fn texts_from(s: &Scene, code: usize) -> Vec<TextCommand> {
    s.texts.iter().filter(|t| t.code == code).cloned().collect()
}

#[test]
fn levelup_and_weapon_levelup_draw_badges_and_particles() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // Initialize particle systems via obj_pwrlevelinitialize (103)
    let init = s.create(&bundle, 103, -1000.0, -1000.0).unwrap();
    s.instances.get_mut(&init).unwrap().alive = false;

    // Set level = 2 so CODE 356 particle branch evaluates true
    s.globals.insert("level".into(), 2.0);

    // 1. Create obj_levelup (CODE 352 Create: vspeed = -1, showpart = 1, alarm[0]=5, alarm[1]=70)
    let lvl = s.create(&bundle, LEVELUP, 100.0, 200.0).unwrap();
    // 2. Create obj_weaponlevelup (CODE 357 Create: alarm[1]=60)
    let wlvl = s.create(&bundle, WEAPONLEVELUP, 200.0, 200.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw view 0");

    // obj_levelup Draw CODE 356: draws spr_levelup (sprite 35)
    let lvl_draws = draws_from(&s, 356);
    assert_eq!(lvl_draws.len(), 1);
    assert_eq!(lvl_draws[0].sprite, 35, "spr_levelup is sprite 35");
    assert_eq!((lvl_draws[0].x, lvl_draws[0].y), (100.0, 200.0));

    // showpart == 1 triggers particle emission
    assert!(!s.particles.is_empty(), "obj_levelup emits particles while showpart == 1");

    // obj_weaponlevelup Draw CODE 359: draws spr_weaponlevelup (sprite 34)
    let wlvl_draws = draws_from(&s, 359);
    assert_eq!(wlvl_draws.len(), 1);
    assert_eq!(wlvl_draws[0].sprite, 34, "spr_weaponlevelup is sprite 34");

    // Alarm 0 of obj_levelup clears showpart after 40 ticks
    for _ in 0..40 {
        s.tick(&bundle).expect("tick");
    }
    assert_eq!(s.instances[&lvl].fields.get("showpart").copied(), Some(0.0), "showpart cleared at alarm[0]");

    // Alarm 1 of obj_weaponlevelup destroys it after 90 ticks (50 more ticks from tick 40)
    for _ in 0..50 {
        s.tick(&bundle).expect("tick");
    }
    assert!(!s.instances[&wlvl].alive, "weaponlevelup destroyed after 90 ticks");
    assert!(s.instances[&lvl].alive, "levelup still alive at tick 90");

    // Alarm 1 of obj_levelup destroys it after 94 ticks (4 more ticks)
    for _ in 0..4 {
        s.tick(&bundle).expect("tick");
    }
    assert!(!s.instances[&lvl].alive, "levelup destroyed after 94 ticks");
}

#[test]
fn combat_floaters_draw_damage_and_dodged_with_alpha_fade() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // 1. obj_weaponname (CODE 462 Create: vspeed = -2, alpha = 1)
    let wn = s.create(&bundle, WEAPONNAME, 300.0, 200.0).unwrap();
    // 2. obj_dodged (CODE 465 Create: speed = 2, alpha = 1)
    let dd = s.create(&bundle, DODGED, 400.0, 200.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw view 0");

    // obj_weaponname Draw CODE 464: draw_text_color at y - 20 = 180
    let wn_texts = texts_from(&s, 464);
    assert_eq!(wn_texts.len(), 1);
    assert_eq!((wn_texts[0].x, wn_texts[0].y), (300.0, 180.0));
    assert_eq!(wn_texts[0].alpha, 1.0);

    // obj_dodged Draw CODE 467: draw_text "Dodged!" at y - 20 = 180
    let dd_texts = texts_from(&s, 467);
    assert_eq!(dd_texts.len(), 1);
    assert_eq!(dd_texts[0].text, "Dodged!", "resolves string 856 'Dodged!'");
    assert_eq!((dd_texts[0].x, dd_texts[0].y), (400.0, 180.0));
    assert_eq!(dd_texts[0].alpha, 1.0);

    // Step decrements alpha by 0.04 per tick (CODE 463 & 466)
    s.tick(&bundle).expect("tick");
    assert!((s.instances[&wn].fields["alpha"] - 0.96).abs() < 1e-6);
    assert!((s.instances[&dd].fields["alpha"] - 0.96).abs() < 1e-6);

    // Both self-destruct when alpha <= 0 (25 ticks from 1.0 at 0.04/tick)
    for _ in 0..24 {
        s.tick(&bundle).expect("tick");
    }
    assert!(!s.instances[&wn].alive, "weaponname destroyed when alpha fades to 0");
    assert!(!s.instances[&dd].alive, "dodged destroyed when alpha fades to 0");
}

#[test]
fn audio_toggles_render_on_and_off_labels() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    let _vol = s.create(&bundle, VOLUME, 100.0, 50.0).unwrap();
    let _mus = s.create(&bundle, VOLUMEMUSIC, 100.0, 100.0).unwrap();

    // 1. soundmute = 0, musicmute = 0
    s.globals.insert("soundmute".into(), 0.0);
    s.globals.insert("musicmute".into(), 0.0);
    s.draw_view(&bundle, 0).expect("draw view 0");

    let vol_texts = texts_from(&s, 469);
    assert!(vol_texts.iter().any(|t| t.text == "Sounds: ON"), "STRG 857 'Sounds: ON'");

    let mus_texts = texts_from(&s, 473);
    assert!(mus_texts.iter().any(|t| t.text == "Music: ON"), "STRG 860 'Music: ON'");

    // 2. soundmute = 1, musicmute = 1
    s.globals.insert("soundmute".into(), 1.0);
    s.globals.insert("musicmute".into(), 1.0);
    s.draw_view(&bundle, 0).expect("redraw");

    let vol_texts_off = texts_from(&s, 469);
    assert!(vol_texts_off.iter().any(|t| t.text == "Sounds: OFF"), "STRG 858 'Sounds: OFF'");
    assert!(!vol_texts_off.iter().any(|t| t.text == "Sounds: ON"));

    let mus_texts_off = texts_from(&s, 473);
    assert!(mus_texts_off.iter().any(|t| t.text == "Music: OFF"), "STRG 861 'Music: OFF'");
    assert!(!mus_texts_off.iter().any(|t| t.text == "Music: ON"));
}

#[test]
fn erase_data_dialog_renders_confirmation_prompts() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    let _btn_restore = s.create(&bundle, RESTOREDATA, 100.0, 100.0).unwrap();
    let _prompt = s.create(&bundle, AREYOUSURE, 200.0, 100.0).unwrap();
    let _btn_yes = s.create(&bundle, YESRESTORE, 200.0, 150.0).unwrap();
    let _btn_no = s.create(&bundle, NORESTORE, 300.0, 150.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw view 0");

    // obj_restoredata (CODE 487): "Erase Data" (873)
    let r_texts = texts_from(&s, 487);
    assert!(r_texts.iter().any(|t| t.text == "Erase Data"));

    // obj_areyousure (CODE 484): "Erase Data?" (871)
    let sure_texts = texts_from(&s, 484);
    assert!(sure_texts.iter().any(|t| t.text == "Erase Data?"));

    // obj_yesrestoredata (CODE 479): "Yes" (869)
    let yes_texts = texts_from(&s, 479);
    assert!(yes_texts.iter().any(|t| t.text == "Yes"));

    // obj_norestoredata (CODE 482): "No" (870)
    let no_texts = texts_from(&s, 482);
    assert!(no_texts.iter().any(|t| t.text == "No"));
}

#[test]
fn pause_backdrop_and_hud_button() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // 1. In gameplay (unpaused): obj_pausebutton (CODE 518) draws sprite 122 at (vx+320, vy+0)
    let _btn_pause = s.create(&bundle, PAUSEBUTTON, 320.0, 0.0).unwrap();
    s.draw_view(&bundle, 0).expect("draw view 0");

    let pb_draws = draws_from(&s, 518);
    assert!(pb_draws.iter().any(|d| d.sprite == 122 && (d.x, d.y) == (320.0, 0.0)), "pause button draws in gameplay");

    // 2. In pause state: obj_pause (CODE 510) deactivates the world and draws backdrop spr_pause (123) + score
    s.score = 4250.0;
    let _p = s.create(&bundle, PAUSE, 0.0, 0.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw pause view");

    let pause_draws = draws_from(&s, 510);
    assert!(pause_draws.iter().any(|d| d.sprite == 123), "spr_pause backdrop");

    let pause_texts = texts_from(&s, 510);
    assert!(pause_texts.iter().any(|t| t.text == "4250"), "current coin balance displayed");
}
