//! Render batch 4 — Store upgrades, page switches, and weapon found overlays.
//!
//! Covers:
//! 1. `obj_foundweapon` (82, Draw CODE 408, 3429 instrs): weapon pickup celebration overlay.
//!    Draws `spr_pause` (123) backdrop, "Tap to Continue" (string 743) when `taplock == 1`,
//!    and weapon-specific magnified 7x gun sprite + "You have found the <Weapon>!" banner.
//! 2. Upgrade pedestals (16 objects, CODE 415..448):
//!    Each draws pedestal `spr_storepedestal` (154), weapon/power icon, upgrade name and price;
//!    and overlays `spr_soldout` (148) when bought.
//!    Special case `obj_healthrefill` (CODE 448): swaps "$250" for "HEALTH FULL!" when `drawhealthfull == 1`.
//! 3. Store navigation:
//!    `obj_store` (CODE 475): "Store" button (spr 153).
//!    `obj_storepageswitch` (CODE 490): "Next Page" button (spr 153).
//!    `obj_storepageswitch2` (CODE 493): "Last Page" button (spr 153).
//! 4. Store page generators:
//!    `obj_pause` (CODE 507 Create) spawns page 1 items (healthrefill, coinmultiplier2, triplejump,
//!    powerupgrade, swordupgrade, strengthupgrade, swordupgrade2, healthregen, storepageswitch).
//!    `obj_pause2` (CODE 512 Create) spawns page 2 items (maxhpupgrade, maxhpupgrade2, coinmultiplier5,
//!    powerupgrade2, powerupgrade3, swordupgrade3, energywaveupgrade, strengthupgrade2, storepageswitch2).

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds, TextCommand};
use std::path::Path;

const FOUNDWEAPON: i32 = 82;
const POWERUPGRADE: i32 = 84;
const TRIPLEJUMP: i32 = 87;
const MAXHPUPGRADE: i32 = 97;
const HEALTHREFILL: i32 = 99;
const STORE: i32 = 110;
const STOREPAGESWITCH: i32 = 116;
const STOREPAGESWITCH2: i32 = 117;
const PAUSE: i32 = 122;
const PAUSE2: i32 = 123;

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
fn foundweapon_overlay_draws_backdrop_tap_prompt_and_weapon_showcase() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // 1. Unlocked taplock=1 and found shotgun (global.shotgun = 1)
    s.globals.insert("shotgun".into(), 1.0);
    let fw = s.create(&bundle, FOUNDWEAPON, 0.0, 0.0).unwrap();
    s.instances.get_mut(&fw).unwrap().fields.insert("taplock".into(), 1.0);

    s.draw_view(&bundle, 0).expect("draw view 0");

    let draws = draws_from(&s, 408);
    // Backdrop: sprite 123 (spr_pause) scale (0.96, 0.8)
    let backdrop = draws.iter().find(|d| d.sprite == 123).expect("backdrop sprite 123");
    assert_eq!((backdrop.scale_x, backdrop.scale_y), (0.96, 0.8));

    // Magnified weapon sprite: sprite 127 (spr_gunshotgun) scale (7.0, 7.0) at (220, 120)
    let gun = draws.iter().find(|d| d.sprite == 127).expect("shotgun sprite 127");
    assert_eq!((gun.scale_x, gun.scale_y), (7.0, 7.0));
    assert_eq!((gun.x, gun.y), (220.0, 120.0));

    let texts = texts_from(&s, 408);
    // Tap to continue prompt
    assert!(texts.iter().any(|t| t.text == "Tap to Continue" && (t.x, t.y) == (150.0, 200.0)));
    // Weapon celebration text
    assert!(texts.iter().any(|t| t.text == "You have found the Shotgun!" && (t.x, t.y) == (80.0, 30.0)));

    // 2. Negative test: taplock=0 hides "Tap to Continue"
    s.instances.get_mut(&fw).unwrap().fields.insert("taplock".into(), 0.0);
    s.draw_view(&bundle, 0).expect("redraw");
    let texts_locked = texts_from(&s, 408);
    assert!(!texts_locked.iter().any(|t| t.text == "Tap to Continue"), "no tap prompt while taplock is 0");
    // But weapon celebration title and gun sprite remain visible
    assert!(texts_locked.iter().any(|t| t.text == "You have found the Shotgun!"));
}

#[test]
fn upgrade_pedestals_draw_prices_and_overlay_soldout_when_bought() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // Create power upgrade at (100, 100) unbought
    s.globals.insert("powerupgradebought".into(), 0.0);
    let _pwr = s.create(&bundle, POWERUPGRADE, 100.0, 100.0).unwrap();

    // Create triple jump at (300, 100) bought
    s.globals.insert("triplejumpbought".into(), 1.0);
    let _tj = s.create(&bundle, TRIPLEJUMP, 300.0, 100.0).unwrap();

    // Create maxhp upgrade at (500, 100) unbought
    s.globals.insert("maxhpupgradebought".into(), 0.0);
    let _hp = s.create(&bundle, MAXHPUPGRADE, 500.0, 100.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw view 0");

    // Power upgrade: CODE 415
    let pwr_draws = draws_from(&s, 415);
    assert!(pwr_draws.iter().any(|d| d.sprite == 154 && (d.x, d.y) == (100.0, 100.0)), "pedestal drawn");
    assert!(!pwr_draws.iter().any(|d| d.sprite == 148), "unbought pedestal has no spr_soldout");
    let pwr_texts = texts_from(&s, 415);
    assert!(pwr_texts.iter().any(|t| t.text == "Reduce Enemy HP 1:"));
    assert!(pwr_texts.iter().any(|t| t.text == "$5,000"));

    // Triple jump: CODE 422 (bought = 1)
    let tj_draws = draws_from(&s, 422);
    let soldout = tj_draws.iter().find(|d| d.sprite == 148).expect("spr_soldout must be drawn when bought=1");
    assert_eq!((soldout.scale_x, soldout.scale_y), (0.6, 0.55), "spr_soldout scaled 0.6x0.55");
    assert_eq!((soldout.x, soldout.y), (300.0, 100.0));

    // Buy power upgrade and redraw: soldout appears
    s.globals.insert("powerupgradebought".into(), 1.0);
    s.draw_view(&bundle, 0).expect("redraw");
    let pwr_draws_bought = draws_from(&s, 415);
    assert!(pwr_draws_bought.iter().any(|d| d.sprite == 148 && (d.x, d.y) == (100.0, 100.0)));
}

#[test]
fn health_refill_swaps_price_for_health_full_banner() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    let hr = s.create(&bundle, HEALTHREFILL, 200.0, 150.0).unwrap();

    // 1. Normal: drawhealthfull == 0
    s.globals.insert("drawhealthfull".into(), 0.0);
    s.draw_view(&bundle, 0).expect("draw view 0");
    let texts_normal = texts_from(&s, 448);
    assert!(texts_normal.iter().any(|t| t.text == "Health Refill" && (t.x, t.y) == (205.0, 150.0)));
    assert!(texts_normal.iter().any(|t| t.text == "$250" && (t.x, t.y) == (205.0, 165.0)));
    assert!(!texts_normal.iter().any(|t| t.text == "HEALTH FULL!"));

    // 2. Full health: drawhealthfull == 1 on instance overlays "HEALTH FULL!" at x+40
    s.instances.get_mut(&hr).unwrap().fields.insert("drawhealthfull".into(), 1.0);
    s.draw_view(&bundle, 0).expect("redraw");
    let texts_full = texts_from(&s, 448);
    assert!(texts_full.iter().any(|t| t.text == "Health Refill"));
    assert!(texts_full.iter().any(|t| t.text == "$250" && (t.x, t.y) == (205.0, 165.0)));
    assert!(texts_full.iter().any(|t| t.text == "HEALTH FULL!" && (t.x, t.y) == (240.0, 165.0)),
        "HEALTH FULL! overlays at (x+40, y+15) when drawhealthfull == 1");
}

#[test]
fn store_navigation_buttons_draw_labels_and_box_sprites() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    let _btn_store = s.create(&bundle, STORE, 50.0, 50.0).unwrap();
    let _btn_next = s.create(&bundle, STOREPAGESWITCH, 150.0, 190.0).unwrap();
    let _btn_last = s.create(&bundle, STOREPAGESWITCH2, 20.0, 190.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw view 0");

    // obj_store (CODE 475)
    let store_draws = draws_from(&s, 475);
    assert!(store_draws.iter().any(|d| d.sprite == 153), "button box sprite 153");
    let store_texts = texts_from(&s, 475);
    assert!(store_texts.iter().any(|t| t.text == "Store" && (t.x, t.y) == (50.0 + 37.0, 50.0)));

    // obj_storepageswitch (CODE 490)
    let next_texts = texts_from(&s, 490);
    assert!(next_texts.iter().any(|t| t.text == "Next Page" && (t.x, t.y) == (150.0 + 12.0, 190.0)));

    // obj_storepageswitch2 (CODE 493)
    let last_texts = texts_from(&s, 493);
    assert!(last_texts.iter().any(|t| t.text == "Last Page" && (t.x, t.y) == (20.0 + 14.0, 190.0)));
}

#[test]
fn pause_store_generators_spawn_complete_page1_and_page2_catalogs() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset);

    // Page 1: obj_pause (CODE 507 Create)
    let _p1 = s.create(&bundle, PAUSE, 0.0, 0.0).unwrap();
    // Spawns 9 items: 8 pedestals (healthrefill, coinmultiplier2, triplejump, powerupgrade,
    // swordupgrade, strengthupgrade, swordupgrade2, healthregen) + 1 storepageswitch
    let page1_objs = [99, 96, 87, 84, 88, 93, 89, 92, 116];
    for &expected_obj in &page1_objs {
        let count = s.instances.values().filter(|i| i.object == expected_obj && i.alive).count();
        assert!(count >= 1, "page 1 must contain object {expected_obj}");
    }

    // Page 2: obj_pause2 (CODE 512 Create)
    let mut s2 = fresh(&bundle, &asset);
    let _p2 = s2.create(&bundle, PAUSE2, 0.0, 0.0).unwrap();
    // Spawns 9 items: 8 pedestals (maxhpupgrade, maxhpupgrade2, coinmultiplier5, powerupgrade2,
    // powerupgrade3, swordupgrade3, energywaveupgrade, strengthupgrade2) + 1 storepageswitch2
    let page2_objs = [97, 98, 95, 85, 86, 90, 91, 94, 117];
    for &expected_obj in &page2_objs {
        let count = s2.instances.values().filter(|i| i.object == expected_obj && i.alive).count();
        assert!(count >= 1, "page 2 must contain object {expected_obj}");
    }
}
