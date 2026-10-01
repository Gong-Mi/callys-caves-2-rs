//! Render batch 1 — the HUD Draw pass on the IR scene host, through the REAL
//! draw_view dispatch: obj_UI (CODE 370, 41164 instrs), obj_maptile (693),
//! obj_coinadd (536), obj_youhavedied (544) and obj_damage (461). Every pinned
//! number comes from the shipped bodies (recovered GML cross-checked), not from
//! a hand-written guess: the boss bar geometry is CODE 370's own
//! `obj_boss3.x - 20, y - 50 .. x, y - 40` for a boss at (300, 200).
//!
//! The string facts this batch pins:
//!   * `string(global.level)` — a number formats, it is NOT a table index.
//!     (Without the pooled string model the score draw resolved table[1370]
//!     = 'spr_set3wall' and printed a sprite name on the HUD.)
//!   * `string_format(coindeduct, 2, 0)` — the death screen's deduction text.
//!   * `string_digits(string(other.goto))` — the maptile room number.
//!   * `"+" + string(global.coinpickup)` — the coin popup concatenation.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds};
use std::path::Path;

const BOSS3: i32 = 27;
const PLAYER: i32 = 0;
const COINADD: i32 = 132;
const DAMAGE: i32 = 104;
const YOUHAVEDIED: i32 = 134;

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

fn fresh(bundle: &Bundle, asset: &GameDroidAsset, room: usize) -> Scene {
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
    s.load_room_from_data(bundle, room, &asset.rooms[room]).unwrap();
    s
}

fn sprite_id(asset: &GameDroidAsset, name: &str) -> i32 {
    asset.sprites.iter().find(|(_, s)| s.name == name).map(|(id, _)| *id as i32)
        .unwrap_or_else(|| panic!("missing sprite {name}"))
}

/// Draw commands emitted by one CODE body, in emission order.
fn draws_from(s: &Scene, code: usize) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == code).cloned().collect()
}

fn text_at(s: &Scene, x: f64, y: f64) -> Option<String> {
    s.texts.iter().find(|t| t.x == x && t.y == y).map(|t| t.text.clone())
}

#[test]
fn the_ui_draw_pass_emits_the_boss_healthbar_from_the_real_bytecode() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97); // rm_boss3
    let boss = s.create(&bundle, BOSS3, 300.0, 200.0).unwrap();
    s.instances.get_mut(&boss).unwrap().fields.insert("hpboss3".into(), 425.0);
    s.instances.get_mut(&boss).unwrap().fields.insert("boss3maxhp".into(), 850.0);
    s.view_positions.insert(0, (0.0, 0.0));

    s.draw_view(&bundle, 0).expect("the 41164-instruction UI Draw runs");
    // CODE 370: draw_healthbar(boss.x - 20, boss.y - 50, boss.x, boss.y - 40,
    // hpboss3 / boss3maxhp * 100, ...) — (280, 150)-(300, 160) for (300, 200).
    let boss_bar = s.healthbars.iter()
        .find(|hb| hb.x1 == 280.0 && hb.y1 == 150.0)
        .expect("the boss healthbar is emitted");
    assert_eq!((boss_bar.x2, boss_bar.y2), (300.0, 160.0), "probe-pinned geometry");
    assert_eq!(boss_bar.amount, 50.0, "425/850 hp -> 50% bar");

    // Halve the hp: the same pass emits 25.
    s.instances.get_mut(&boss).unwrap().fields.insert("hpboss3".into(), 212.5);
    s.draw_view(&bundle, 0).expect("redraw");
    let boss_bar = s.healthbars.iter()
        .find(|hb| hb.x1 == 280.0 && hb.y1 == 150.0)
        .expect("the boss bar redraws");
    assert_eq!(boss_bar.amount, 25.0, "212.5/850 -> 25%");

    // The full HUD pass: boss bar + XP bar + sprite layers in the boss room.
    assert!(s.healthbars.len() >= 2, "the HUD carries the boss bar and the XP bar");
    assert!(!s.texts.is_empty(), "the UI emits its text layer");
    assert!(!draws_from(&s, 370).is_empty(), "the UI emits its sprite layer");
}

#[test]
fn the_ui_draw_pass_prints_the_level_number_and_the_score() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97);
    s.globals.insert("level".into(), 12.0);
    s.score = 1370.0; // table[1370] is the literal 'spr_set3wall'
    s.view_positions.insert(0, (0.0, 0.0));

    s.draw_view(&bundle, 0).expect("the UI Draw runs");

    // CODE 370: global.level >= 10 -> draw_text(view + 2, view + 8, string(level)).
    assert_eq!(text_at(&s, 2.0, 8.0).as_deref(), Some("12"),
        "the level prints as a number, not a string-table lookup");
    // CODE 370: draw_text(view + 170, view + 1, score).
    assert_eq!(text_at(&s, 170.0, 1.0).as_deref(), Some("1370"),
        "the score is a real number; a table lookup would render 'spr_set3wall'");

    // A level below 10 takes the other x offset.
    s.globals.insert("level".into(), 9.0);
    s.draw_view(&bundle, 0).expect("redraw");
    assert_eq!(text_at(&s, 10.0, 8.0).as_deref(), Some("9"));
    assert!(text_at(&s, 2.0, 8.0).is_none(), "only the < 10 branch draws");
}

#[test]
fn the_ui_draw_pass_tracks_experience_on_the_xp_bar() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97);
    s.globals.insert("level".into(), 5.0);
    s.globals.insert("experience".into(), 30.0);
    s.globals.insert("xptolevelup".into(), 120.0);
    s.view_positions.insert(0, (0.0, 0.0));

    s.draw_view(&bundle, 0).expect("the UI Draw runs");
    // CODE 370: draw_healthbar(view + 46, view + 4, view + 140, view + 11,
    // (global.experience / global.xptolevelup) * 100, ...).
    let xp = s.healthbars.iter()
        .find(|hb| hb.x1 == 46.0 && hb.y1 == 4.0)
        .expect("the XP bar is emitted");
    assert_eq!((xp.x2, xp.y2), (140.0, 11.0), "probe-pinned geometry");
    assert_eq!(xp.amount, 25.0, "30/120 -> 25%");

    // The level >= 20 branch shows a full bar.
    s.globals.insert("level".into(), 20.0);
    s.draw_view(&bundle, 0).expect("redraw");
    let xp = s.healthbars.iter().find(|hb| hb.x1 == 46.0 && hb.y1 == 4.0).unwrap();
    assert_eq!(xp.amount, 100.0, "level >= 20 pins the bar full");
}

#[test]
fn the_maptile_draw_pass_prints_the_room_number_on_the_tile() {
    let (asset, bundle) = game();
    let mut s = Scene::default();
    s.init_bundle(&bundle);
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
    // The fog gate runs inside the room creation code: room42's tile survives
    // only when the room was visited.
    s.globals.insert("room42visited".into(), 1.0);
    s.load_room_from_data(&bundle, 111, &asset.rooms[111]).unwrap(); // rm_map

    let tile = s.instances.iter()
        .find(|(_, i)| i.object == 160 && i.alive && i.fields.get("goto") == Some(&39.0))
        .map(|(id, _)| *id)
        .expect("the room42 maptile survives the fog gate");
    s.view_positions.insert(0, (0.0, 0.0));
    s.draw_view(&bundle, 0).expect("maptile Draw");
    // CODE 693: draw_self + font 2 + white + draw_text(string_digits(string(goto)))
    // at (x + 6, y + 8).
    let (tx, ty) = (s.instances[&tile].fields["x"] + 6.0, s.instances[&tile].fields["y"] + 8.0);
    assert_eq!(text_at(&s, tx, ty).as_deref(), Some("39"),
        "string_digits(string(39)) prints the room number");

    // A fresh load without the visited flag drops the tile entirely.
    let mut gate = Scene::default();
    gate.init_bundle(&bundle);
    gate.init_fresh_start_globals();
    gate.load_room_from_data(&bundle, 111, &asset.rooms[111]).unwrap();
    assert!(!gate.instances.values().any(|i| i.fields.get("goto") == Some(&39.0) && i.alive),
        "the fog gate still destroys the untouched tile");
}

#[test]
fn the_coin_popup_concatenates_the_plus_and_the_pickup_value() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97);
    s.create(&bundle, PLAYER, 400.0, 300.0).unwrap();
    s.globals.insert("coinpickup".into(), 100.0);
    s.create(&bundle, COINADD, 400.0, 300.0).unwrap();
    s.view_positions.insert(0, (0.0, 0.0));

    s.draw_view(&bundle, 0).expect("obj_coinadd Draw runs");
    // CODE 536: draw_text(obj_player.x, obj_player.y - 70, "+" + string(coinpickup)).
    assert_eq!(text_at(&s, 400.0, 230.0).as_deref(), Some("+100"),
        "\"+\" concatenated with string(100)");

    // Every coin pickup shows its own value: 7 -> "+7" (one digit, no decimals).
    s.globals.insert("coinpickup".into(), 7.0);
    s.draw_view(&bundle, 0).expect("redraw");
    assert_eq!(text_at(&s, 400.0, 230.0).as_deref(), Some("+7"));

    // The popup draws its coin icon too (spr_coin) next to the text.
    let coin = sprite_id(&asset, "spr_coin") as f64;
    assert!(draws_from(&s, 536).iter().any(|d| d.sprite as f64 == coin && d.x == 390.0),
        "the popup carries its own coin sprite at x - 10");
}

#[test]
fn the_death_screen_formats_the_coin_deduction_and_prints_it() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97);
    s.create(&bundle, PLAYER, 400.0, 300.0).unwrap();
    s.globals.insert("startx".into(), 400.0);
    s.globals.insert("starty".into(), 300.0);

    let screen = s.create(&bundle, YOUHAVEDIED, 0.0, 0.0).unwrap();
    // CODE 540: coindeduct = irandom_range(30, 99); str1 = string_format(coindeduct, 2, 0).
    let coindeduct = s.instances[&screen].fields["coindeduct"];
    assert!((30.0..=99.0).contains(&coindeduct), "the deduction stays in range: {coindeduct}");
    s.view_positions.insert(0, (0.0, 0.0));

    s.draw_view(&bundle, 0).expect("obj_youhavedied Draw runs");
    // CODE 544 view 0: "-" at (view + 5, view + 8), the formatted deduction at
    // (view + 15, view + 10), spr_coin at (view + 45, view + 27).
    assert_eq!(text_at(&s, 5.0, 8.0).as_deref(), Some("-"));
    assert_eq!(text_at(&s, 15.0, 10.0).as_deref(), Some(format!("{}", coindeduct as i64).as_str()),
        "string_format(coindeduct, 2, 0) renders the integer deduction");
    let coin = sprite_id(&asset, "spr_coin") as f64;
    assert!(draws_from(&s, 544).iter().any(|d| d.sprite as f64 == coin && d.x == 45.0 && d.y == 27.0));

    // taplock == 0 hides the continue prompt; CODE 542's alarm[0] sets it.
    assert!(text_at(&s, 140.0, 220.0).is_none(), "the prompt is hidden while taplock == 0");
    s.instances.get_mut(&screen).unwrap().fields.insert("taplock".into(), 1.0);
    s.draw_view(&bundle, 0).expect("redraw with taplock");
    assert_eq!(text_at(&s, 140.0, 220.0).as_deref(), Some("Tap to Continue"));
}

#[test]
fn the_damage_popup_prints_the_number_not_a_table_literal() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97);
    let popup = s.create(&bundle, DAMAGE, 100.0, 200.0).unwrap();
    s.instances.get_mut(&popup).unwrap().fields.insert("damage".into(), 3.0); // table[3] = 'flashing'
    s.view_positions.insert(0, (0.0, 0.0));

    s.draw_view(&bundle, 0).expect("obj_damage Draw runs");
    // CODE 461: draw_text(x, y - 20, damage).
    assert_eq!(text_at(&s, 100.0, 180.0).as_deref(), Some("3"),
        "the damage popup is a number, not table[3]");
}
