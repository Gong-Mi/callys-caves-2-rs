//! Render batch 3 (part 2) — Enemy Intro Banners & Trigger System.
//!
//! Across the game, when the player encounters a new enemy or boss for the first time,
//! an `obj_triggerintro` (186, CODE 781 Step_0) checks:
//!   `distance_to_object(obj_player) <= 32 && room == R && <enemy>touched == 0`
//! When tripped:
//!   1. It creates the corresponding `obj_<enemy>intro` banner (objects 166..185).
//!   2. Sets `global.<enemy>touched = 1` so the intro never repeats.
//!
//! The banner object `obj_<enemy>intro` (CODE 721..780):
//!   * Create: plays fanfare `snd_fanfare` (sound 4) if `soundmute == 0`; sets `alarm[0] = 60`;
//!     spawns flanking flight lines `obj_lineleft` (164) at (x+320, y-30) and
//!     `obj_lineright` (165) at (x-320, y-5).
//!   * Draw 0: calls `draw_set_color(c_white)` (16777215), `draw_set_font(0)`, and
//!     `draw_text(fixed_x, fixed_y, name)` pulling the original enemy name
//!     from the STRG table (indices 1214..1233: "Bear Cub", "Mama Bear", ..., "Herbert").
//!   * Alarm 0: calls `instance_destroy()` after 60 ticks.
//!
//! Flanking lines `obj_lineleft` / `obj_lineright` (CODE 717..720):
//!   * Create: sets `hspeed = -12` (left) / `+12` (right); sets `alarm[0] = 89`.
//!   * Alarm 0: calls `instance_destroy()` after 89 ticks.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{Scene, SpriteBounds, TextCommand};
use std::path::Path;

const PLAYER: i32 = 0;
const LINELEFT: i32 = 164;
const LINERIGHT: i32 = 165;
const BEARCUB_INTRO: i32 = 166;
const KNIFEBANDIT_INTRO: i32 = 167;
const BOSS1_INTRO: i32 = 172;
const BOSS6_INTRO: i32 = 185;
const TRIGGERINTRO: i32 = 186;

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
    s.view_positions.insert(0, (0.0, 0.0));
    s
}

fn texts_from(s: &Scene, code: usize) -> Vec<TextCommand> {
    s.texts.iter().filter(|t| t.code == code).cloned().collect()
}

#[test]
fn triggerintro_trips_banner_and_sets_touched_latch() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1); // room 1 = rm_level1

    // Ensure player is at (500, 300)
    let _p = s.create(&bundle, PLAYER, 500.0, 300.0).unwrap();

    // Place triggerintro within 32px of player (x < 1000 -> Bear Cub trigger)
    let _trig = s.create(&bundle, TRIGGERINTRO, 510.0, 300.0).unwrap();
    assert_eq!(s.globals.get("beartouched").copied().unwrap_or(0.0), 0.0);

    // Tick once to dispatch Step (CODE 781)
    s.tick(&bundle).expect("tick");

    // Latch is set to 1
    assert_eq!(s.globals.get("beartouched").copied(), Some(1.0), "beartouched latched to 1");

    // obj_bearcubintro (166) is instantiated
    let intro_count = s.instances.values().filter(|i| i.object == BEARCUB_INTRO && i.alive).count();
    assert_eq!(intro_count, 1, "exactly one obj_bearcubintro spawned");

    // Second tick: beartouched is 1, no duplicate banner is spawned
    s.tick(&bundle).expect("tick 2");
    let intro_count_2 = s.instances.values().filter(|i| i.object == BEARCUB_INTRO && i.alive).count();
    assert_eq!(intro_count_2, 1, "no duplicate intro spawned when beartouched == 1");
}

#[test]
fn intro_banner_draw_renders_enemy_name_from_string_table() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1);
    s.create(&bundle, PLAYER, 400.0, 300.0).unwrap();

    // Directly spawn three representative banners:
    // 1. Bear Cub (166, Draw CODE 723)
    // 2. Boss 1 (Mama Bear, 172, Draw CODE 741)
    // 3. Boss 6 (Herbert, 185, Draw CODE 780)
    let _b_bear = s.create(&bundle, BEARCUB_INTRO, 700.0, 100.0).unwrap();
    let _b_boss1 = s.create(&bundle, BOSS1_INTRO, 400.0, 200.0).unwrap();
    let _b_boss6 = s.create(&bundle, BOSS6_INTRO, 400.0, 200.0).unwrap();

    s.draw_view(&bundle, 0).expect("draw view 0");

    // Verify Bear Cub (CODE 723: draw_text(736, 96, "Bear Cub"))
    let bear_texts = texts_from(&s, 723);
    assert_eq!(bear_texts.len(), 1, "one TextCommand for Bear Cub");
    assert_eq!(bear_texts[0].text, "Bear Cub", "name resolves from string table index 1214");
    assert_eq!((bear_texts[0].x, bear_texts[0].y), (736.0, 96.0), "Bear Cub fixed layout coordinates");
    assert_eq!(bear_texts[0].color, 16777215, "c_white text color");

    // Verify Boss 1 (CODE 741: draw_text(416, 256, "Mama Bear"))
    let boss1_texts = texts_from(&s, 741);
    assert_eq!(boss1_texts.len(), 1, "one TextCommand for Boss 1");
    assert_eq!(boss1_texts[0].text, "Mama Bear", "name resolves from string table index 1220");
    assert_eq!((boss1_texts[0].x, boss1_texts[0].y), (416.0, 256.0), "Boss 1 fixed layout coordinates");
    assert_eq!(boss1_texts[0].color, 16777215);

    // Verify Boss 6 (CODE 780: draw_text(384, 192, "Herbert"))
    let boss6_texts = texts_from(&s, 780);
    assert_eq!(boss6_texts.len(), 1, "one TextCommand for Boss 6");
    assert_eq!(boss6_texts[0].text, "Herbert", "name resolves from string table index 1233");
    assert_eq!((boss6_texts[0].x, boss6_texts[0].y), (384.0, 192.0), "Boss 6 fixed layout coordinates");
    assert_eq!(boss6_texts[0].color, 16777215);
}

#[test]
fn banner_plays_fanfare_and_respects_soundmute() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1);
    s.create(&bundle, PLAYER, 400.0, 300.0).unwrap();

    // soundmute = 0: fanfare queued
    s.globals.insert("soundmute".into(), 0.0);
    s.audio.clear();
    let _b1 = s.create(&bundle, BEARCUB_INTRO, 500.0, 300.0).unwrap();
    assert!(s.audio.iter().any(|a| a.sound == 4), "sound 4 (snd_fanfare) played when soundmute == 0");

    // soundmute = 1: fanfare muted
    s.globals.insert("soundmute".into(), 1.0);
    s.audio.clear();
    let _b2 = s.create(&bundle, KNIFEBANDIT_INTRO, 500.0, 300.0).unwrap();
    assert!(!s.audio.iter().any(|a| a.sound == 4), "no fanfare when soundmute == 1");
}

#[test]
fn flanking_lines_spawn_fly_outward_and_destroy_on_alarm() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1);
    s.create(&bundle, PLAYER, 400.0, 300.0).unwrap();

    // Create banner at (500, 300)
    let banner = s.create(&bundle, BEARCUB_INTRO, 500.0, 300.0).unwrap();

    // Flanking lines were spawned by Create CODE 721:
    // lineleft (164) at (x + 320, y - 30) = (820, 270)
    // lineright (165) at (x - 320, y - 5) = (180, 295)
    let l_id = s.instances.iter().find(|(_, i)| i.object == LINELEFT && i.alive).map(|(id, _)| *id).unwrap();
    let r_id = s.instances.iter().find(|(_, i)| i.object == LINERIGHT && i.alive).map(|(id, _)| *id).unwrap();

    assert_eq!((s.instances[&l_id].fields["x"], s.instances[&l_id].fields["y"]), (820.0, 270.0));
    assert_eq!((s.instances[&r_id].fields["x"], s.instances[&r_id].fields["y"]), (180.0, 295.0));

    // Initial speeds: hspeed = -12 (left) and +12 (right)
    assert_eq!(s.instances[&l_id].fields["hspeed"], -12.0);
    assert_eq!(s.instances[&r_id].fields["hspeed"], 12.0);

    // Initial alarms: alarm[0] = 89 for lines, alarm[0] = 60 for banner
    let banner_alarm = s.instances[&banner].alarms[0];
    let l_alarm = s.instances[&l_id].alarms[0];
    let r_alarm = s.instances[&r_id].alarms[0];
    assert_eq!(banner_alarm, 60, "banner alarm[0] = 60");
    assert_eq!(l_alarm, 89, "lineleft alarm[0] = 89");
    assert_eq!(r_alarm, 89, "lineright alarm[0] = 89");

    // Tick 10 steps: lines fly outward by 120px
    for _ in 0..10 {
        s.tick(&bundle).expect("tick");
    }

    assert_eq!(s.instances[&l_id].fields["x"], 820.0 - 120.0, "lineleft moved -120px");
    assert_eq!(s.instances[&r_id].fields["x"], 180.0 + 120.0, "lineright moved +120px");

    // Tick to step 60: banner destroys itself
    for _ in 0..50 {
        s.tick(&bundle).expect("tick");
    }
    assert!(!s.instances[&banner].alive, "banner destroyed at tick 60");
    assert!(s.instances[&l_id].alive, "lines still alive at tick 60 (89-tick life)");

    // Tick remaining 29 steps: lines destroy themselves
    for _ in 0..29 {
        s.tick(&bundle).expect("tick");
    }
    assert!(!s.instances[&l_id].alive, "lineleft destroyed at tick 89");
    assert!(!s.instances[&r_id].alive, "lineright destroyed at tick 89");
}
