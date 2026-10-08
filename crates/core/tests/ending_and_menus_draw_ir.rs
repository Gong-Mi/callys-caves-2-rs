//! Render batch 6 — Ending credits sequence, The End finale panels,
//! teaser card, first pause tutorial tip screen, and IAP store overlays.
//!
//! Closes the final remaining Draw CODEs of Cally's Caves 2:
//! 1. `obj_endmusic` (163, Draw CODE 716, 1929 instrs):
//!    Plays credits theme (sound 42), runs an 11-stage alarm timeline,
//!    and renders staff credits (Art by 0HK0, Jordan Pearson, David Stanich, etc.).
//!    Alarm 11 spawns `obj_final`.
//! 2. `obj_final` (161, Draw CODE 699, 446 instrs):
//!    Draws `spr_theend` (176) and "Tap to Continue" (743) when taplock==1.
//! 3. `obj_tease` (162, Draw CODE 703, 228 instrs):
//!    Draws teaser card `spr_tease` (162).
//! 4. `obj_firstpause` (118, Draw CODE 497, 648 instrs):
//!    Draws pause backdrop (123), Lloyd portrait (152), and "Lloyd's Tip:" (970).
//!    Suppresses tip text when confirmation dialog `obj_areyousure` (114) exists.
//! 5. IAP overlays:
//!    `obj_iapmenu` (119, Draw CODE 500): backdrop (123).
//!    `obj_IAPstore` (124, Draw CODE 516): button (121).
//!    `obj_poisoniap` (120, Draw CODE 503): title "Poison Bullets, Gems & Remove Ads:" (992) and "$0.99" (993).
//!    `obj_restoreiap` (121, Draw CODE 506): "Restore Purchases:" (996) and "Purchases Restored!" (997).

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds, TextCommand};
use std::path::Path;

const FIRSTPAUSE: i32 = 118;
const IAPMENU: i32 = 119;
const POISONIAP: i32 = 120;
const RESTOREIAP: i32 = 121;
const IAPSTORE: i32 = 124;
const FINAL: i32 = 161;
const TEASE: i32 = 162;
const ENDMUSIC: i32 = 163;
const AREYOUSURE: i32 = 114;

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
fn firstpause_draws_lloyd_tip_and_suppresses_under_confirmation() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    let fp = s.create(&bundle, FIRSTPAUSE, 0.0, 0.0).unwrap();

    // Store custom pooled string references for tips
    s.instances.get_mut(&fp).unwrap().fields.insert("tips1".into(), 100.0);
    s.instances.get_mut(&fp).unwrap().fields.insert("tips2".into(), 101.0);

    // 1. Normal state: no obj_areyousure exists
    s.draw_view(&bundle, 0).expect("draw view 0");

    let fp_draws = draws_from(&s, 497);
    assert!(fp_draws.iter().any(|d| d.sprite == 123), "spr_pause backdrop");

    let fp_texts = texts_from(&s, 497);
    assert!(fp_texts.iter().any(|t| t.text == "Lloyd's Tip:"), "STRG 970 'Lloyd's Tip:'");

    // 2. Erase confirmation dialog active: obj_areyousure (114) exists
    let sure = s.create(&bundle, AREYOUSURE, 200.0, 100.0).unwrap();
    s.draw_view(&bundle, 0).expect("redraw with confirmation");

    let fp_texts_suppressed = texts_from(&s, 497);
    assert!(!fp_texts_suppressed.iter().any(|t| t.text == "Lloyd's Tip:"),
        "Lloyd's tip text is suppressed when obj_areyousure dialog is open");

    // Clean up confirmation
    s.instances.get_mut(&sure).unwrap().alive = false;
    s.draw_view(&bundle, 0).expect("redraw after confirmation closed");
    assert!(texts_from(&s, 497).iter().any(|t| t.text == "Lloyd's Tip:"));
}

#[test]
fn iap_store_and_restore_purchases_overlays() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    let _menu = s.create(&bundle, IAPMENU, 0.0, 0.0).unwrap();
    let store_btn = s.create(&bundle, IAPSTORE, 315.0, 1.0).unwrap();
    // Mouse 7 on the store icon (CODE 515) is an empty body: dispatching it
    // must be a clean no-op with no side effects.
    s.dispatch(&bundle, store_btn, 6, 7).expect("Mouse 7 dispatch on the store icon");
    assert!(s.instances[&store_btn].alive, "the empty handler changes nothing");
    let _poison = s.create(&bundle, POISONIAP, 100.0, 100.0).unwrap();
    let restore = s.create(&bundle, RESTOREIAP, 100.0, 200.0).unwrap();

    // 1. Normal state: drawpurchase == 0
    s.instances.get_mut(&restore).unwrap().fields.insert("drawpurchase".into(), 0.0);
    s.draw_view(&bundle, 0).expect("draw view 0");

    // IAP menu backdrop (CODE 500)
    let menu_draws = draws_from(&s, 500);
    assert!(menu_draws.iter().any(|d| d.sprite == 123), "IAP menu spr_pause backdrop");

    // IAP store icon button (CODE 516)
    let store_draws = draws_from(&s, 516);
    assert!(store_draws.iter().any(|d| d.sprite == 121), "IAP store button sprite 121");

    // Poison IAP pedestal (CODE 503)
    let poison_texts = texts_from(&s, 503);
    assert!(poison_texts.iter().any(|t| t.text == "Poison Bullets, Gems & Remove Ads:"));
    assert!(poison_texts.iter().any(|t| t.text == "$0.99"));

    // Restore IAP button (CODE 506)
    let restore_texts = texts_from(&s, 506);
    assert!(restore_texts.iter().any(|t| t.text == "Restore Purchases:"));
    assert!(!restore_texts.iter().any(|t| t.text == "Purchases Restored!"));

    // 2. Purchased state: drawpurchase == 1
    s.instances.get_mut(&restore).unwrap().fields.insert("drawpurchase".into(), 1.0);
    s.draw_view(&bundle, 0).expect("redraw with purchases restored");

    let restore_texts_bought = texts_from(&s, 506);
    assert!(restore_texts_bought.iter().any(|t| t.text == "Purchases Restored!"));
}

#[test]
fn ending_credits_sequence_plays_music_and_rolls_staff_pages() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // Create obj_endmusic (CODE 704 Create)
    s.audio.clear();
    let em = s.create(&bundle, ENDMUSIC, 0.0, 0.0).unwrap();

    // Plays ending credits theme (sound 42)
    assert!(s.audio.iter().any(|a| a.sound == 42), "sound 42 (mus_credits) played on create");

    // Initial alarms: alarm[0]=50, alarm[1]=400, alarm[2]=700, ..., alarm[11]=2660
    assert_eq!(s.instances[&em].alarms[0], 50);
    assert_eq!(s.instances[&em].alarms[1], 400);
    assert_eq!(s.instances[&em].alarms[11], 2660);

    // Initial draw: all drawcredit flags are 0, no credit text
    s.draw_view(&bundle, 0).expect("draw initial credits");
    assert!(texts_from(&s, 716).is_empty(), "no credits drawn before alarm[0]");

    // Step 50 ticks to trigger Alarm 0 (CODE 715: drawcredit1 = 1)
    for _ in 0..50 {
        s.tick(&bundle).expect("tick");
    }
    assert_eq!(s.instances[&em].fields.get("drawcredit1").copied(), Some(1.0));

    s.draw_view(&bundle, 0).expect("draw credit page 1");
    let c1_texts = texts_from(&s, 716);
    assert!(c1_texts.iter().any(|t| t.text == "Art by 0HK0"), "STRG 1179 'Art by 0HK0'");

    // Trigger Alarm 1 (CODE 714: drawcredit2 = 1) -> "And Yal"
    s.instances.get_mut(&em).unwrap().fields.insert("drawcredit2".into(), 1.0);
    s.draw_view(&bundle, 0).expect("draw credit page 2");
    let c2_texts = texts_from(&s, 716);
    assert!(c2_texts.iter().any(|t| t.text == "And Yal"), "STRG 1180 'And Yal'");

    // Trigger Alarm 2 (CODE 713: drawcredit3 = 1) -> "Code and Music", "by Jordan Pearson"
    s.instances.get_mut(&em).unwrap().fields.insert("drawcredit3".into(), 1.0);
    s.draw_view(&bundle, 0).expect("draw credit page 3");
    let c3_texts = texts_from(&s, 716);
    assert!(c3_texts.iter().any(|t| t.text.contains("Jordan Pearson")), "STRG 1183 'by Jordan Pearson'");

    // Trigger Alarm 3 (CODE 712: drawcredit4 = 1) -> "Additional Design", "& Music", "by Dave Stanich"
    s.instances.get_mut(&em).unwrap().fields.insert("drawcredit4".into(), 1.0);
    s.draw_view(&bundle, 0).expect("draw credit page 4");
    let c4_texts = texts_from(&s, 716);
    assert!(c4_texts.iter().any(|t| t.text.contains("Dave Stanich")), "STRG 1190 'by Dave Stanich'");

    // Alarm 11 (CODE 705) spawns obj_final (161)
    s.dispatch(&bundle, em, 2, 11).expect("dispatch alarm 11");
    let has_final = s.instances.values().any(|i| i.object == FINAL && i.alive);
    assert!(has_final, "obj_endmusic Alarm 11 spawns obj_final");
}

#[test]
fn finale_the_end_panels_and_teaser_card() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // 1. obj_final (161, CODE 694 Create sets drawpanel1 = 1)
    let fin = s.create(&bundle, FINAL, 0.0, 0.0).unwrap();
    assert_eq!(s.instances[&fin].fields.get("drawpanel1").copied(), Some(1.0));

    s.draw_view(&bundle, 0).expect("draw final panel 1");

    let fin_draws = draws_from(&s, 699);
    assert!(fin_draws.iter().any(|d| d.sprite == 176), "spr_theend is sprite 176");

    // Panel 3 + taplock == 1 reveals "Tap to Continue"
    s.instances.get_mut(&fin).unwrap().fields.insert("drawpanel1".into(), 0.0);
    s.instances.get_mut(&fin).unwrap().fields.insert("drawpanel3".into(), 1.0);
    s.instances.get_mut(&fin).unwrap().fields.insert("taplock".into(), 1.0);

    s.draw_view(&bundle, 0).expect("draw final panel 3 with taplock");

    let fin_texts = texts_from(&s, 699);
    assert!(fin_texts.iter().any(|t| t.text == "Tap to Continue" && (t.x, t.y) == (140.0, 220.0)));

    // 2. obj_tease (162, Draw CODE 703)
    let _tease = s.create(&bundle, TEASE, 0.0, 0.0).unwrap();
    s.draw_view(&bundle, 0).expect("draw tease card");

    let tease_draws = draws_from(&s, 703);
    assert!(tease_draws.iter().any(|d| d.sprite == 162), "spr_tease is sprite 162");
}

// ---- the credits ladder and the endgame taps -------------------------------------
// The old credits test proved the DRAW layer by setting the drawcredit flags by
// hand and dispatching Alarm 11; the ladder itself (A1..A9 flipping one page
// every ~300 ticks) never ran. Here it drives live off the Create seeds. The
// run also exposes the ending's own starvation: obj_final spawns at t2660 and
// its Create calls instance_deactivate_all(true) (keep-self), which freezes the
// credits instance — a9 is left at 140 and the tenth page flip never fires in
// the shipped flow. The body is then driven directly so it still executes, and
// the starvation itself is pinned as a assertion.

#[test]
fn ending_credits_ladder_flips_pages_and_starves_on_obj_final() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);
    let em = s.create(&bundle, ENDMUSIC, 0.0, 0.0).unwrap();
    let mut flips: Vec<(i32, u32)> = Vec::new();
    let mut prev = [0.0f64; 11];
    let mut final_spawn = 0;
    let mut panel2_tick = 0;
    let mut lock_tick = 0;
    for t in 1..=2965 {
        s.tick(&bundle).expect("tick");
        for n in 1..=10u32 {
            let v = s.instances[&em].fields.get(&format!("drawcredit{n}")).copied().unwrap_or(0.0);
            if v == 1.0 && prev[n as usize] != 1.0 {
                flips.push((t, n));
            }
            prev[n as usize] = v;
        }
        if final_spawn == 0 && s.instances.values().any(|i| i.object == FINAL && i.alive) {
            final_spawn = t;
        }
        if let Some(f) = s.instances.values().find(|i| i.object == FINAL) {
            if panel2_tick == 0 && f.fields.get("drawpanel2").copied() == Some(1.0) {
                panel2_tick = t;
            }
            if lock_tick == 0 && f.fields.get("taplock").copied() == Some(1.0) {
                lock_tick = t;
            }
        }
    }
    assert_eq!(flips, vec![(50, 1), (400, 2), (700, 3), (1000, 4), (1300, 5),
        (1600, 6), (1900, 7), (2200, 8), (2400, 9)],
        "A1..A8 flip one page per beat off the own tick counter");
    assert_eq!(final_spawn, 2660, "A11 (2660 in Create) spawns obj_final at t2660");
    assert_eq!(panel2_tick, 2760, "obj_final's own A0 lands at +100");
    assert_eq!(lock_tick, 2960, "and its A1/A3 beats at +300");
    // The starvation, pinned: the room got deactivated under the credits.
    assert!(!s.instances[&em].active, "obj_final's Create deactivates the credits");
    assert_eq!(s.instances[&em].alarms[9], 140,
        "a9 was left at 140 the moment the credits went inactive");
    assert_eq!(s.instances[&em].fields.get("drawcredit9").copied(), Some(1.0));
    assert_eq!(s.instances[&em].fields.get("drawcredit10").copied(), Some(0.0),
        "the tenth page flip never fires in the shipped flow");
    // Drive the starved body directly: its raw effect still holds.
    s.dispatch(&bundle, em, 2, 9).expect("A9 direct");
    assert_eq!(s.instances[&em].fields.get("drawcredit10").copied(), Some(1.0));
}

#[test]
fn endgame_taps_warp_to_challenges_and_restart_the_game() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);
    let marker = s.create(&bundle, ENDMUSIC, 400.0, 0.0).unwrap();
    let fin = s.create(&bundle, FINAL, 0.0, 0.0).unwrap();
    assert!(!s.instances[&marker].active, "Create deactivates the room (keep-self)");
    s.dispatch(&bundle, fin, 6, 7).expect("tap before the lock");
    assert_eq!(s.target_room_warp, None, "taplock gates the warp");
    s.dispatch(&bundle, fin, 2, 1).expect("alarm 1 sets taplock");
    assert_eq!(s.instances[&fin].fields.get("taplock").copied(), Some(1.0));
    s.dispatch(&bundle, fin, 6, 7).expect("tap after the lock");
    assert_eq!(s.target_room_warp, Some(105), "rm_challenge1");
    assert_eq!(s.globals.get("warpfrommap").copied(), Some(1.0));
    assert!(s.instances[&marker].active, "activate_all revived the room");

    // obj_tease: alarm 0 unlocks at t600; the tap stops the music and restarts.
    let mut s = fresh(&bundle, &asset);
    let tease = s.create(&bundle, TEASE, 0.0, 0.0).unwrap();
    let cally3 = s.audio.last().map(|a| a.sound as f64).expect("mus_cally3 played on create");
    assert!(s.audio_is_playing_sound(cally3));
    s.dispatch(&bundle, tease, 6, 7).expect("tap before the unlock");
    assert_eq!(s.target_room_warp, None, "taplock gates the restart");
    for _ in 0..599 {
        s.tick(&bundle).expect("tick");
    }
    assert_eq!(s.instances[&tease].fields.get("taplock").copied(), Some(0.0));
    s.tick(&bundle).expect("tick");
    assert_eq!(s.instances[&tease].fields.get("drawpanel3").copied(), Some(1.0));
    assert_eq!(s.instances[&tease].fields.get("taplock").copied(), Some(1.0),
        "alarm 0 unlocks on the 600th tick");
    s.dispatch(&bundle, tease, 6, 7).expect("restart tap");
    assert_eq!(s.target_room_warp, Some(0), "game_restart requests room 0");
    assert!(!s.audio_is_playing_sound(cally3), "and stops the teaser music");
}
