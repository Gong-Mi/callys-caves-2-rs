//! obj_lloyd and the sixteen obj_lloydtutorialN dialogue sheets - the game's
//! only cutscene/tutorial system. obj_lloyd (154) watches its Step for the
//! player closing to 100 px (CODE 675): it sets global.roomstart = 1, destroys
//! the virtual buttons, freezes the player and raises startlloyd. Its 30-tick
//! heartbeat (CODE 672) then arms alarm[1], and CODE 673 maps the current room
//! to that room's tutorial sheet (16 mappings, rm_level1 -> obj_lloydtutorial2,
//! rm_level7 -> obj_lloydtutorial13). The sheet's Create freezes the whole
//! world, pauses the playlist, cues mus_townmusic and arms a panel timeline;
//! its Draw composes the pause backdrop, the two portraits and the panel's two
//! text lines per active viewport; a tap destroys it (CODE 570 last block) and
//! CODE 566 lands the save flag through savefile.ini, restores the world and
//! re-creates the buttons. CODE 674 retires a Lloyd whose room is already done.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const LLOYD: i32 = 154;
const TUT2: i32 = 139;
const TUT13: i32 = 150;
const LEFT_BUTTON: i32 = 130;
const RIGHT_BUTTON: i32 = 131;
/// SOND id from reconstruction/contracts/audio-sond.json.
const MUS_TOWNMUSIC: i32 = 32;
const C_WHITE: i32 = 16777215;

fn load_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
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
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("town -> level1");
    // The host configures the camera; every Draw path here reads view_xview[0].
    s.view_positions.insert(0, (0.0, 0.0));
    let player = s.instances.iter()
        .find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, s, player, asset)
}

fn walk_portal(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, want_room: f64) {
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(want_room))
        .map(|(id, _)| *id)
        .expect("portal instance with pinned warproom");
    let (px, py) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    let target = s.target_room_warp.take().expect("CODE 13 warp");
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("portal transition");
}

/// rm_town -> rm_level1 -> rm_level4 -> rm_level5 -> rm_level7.
fn level7_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    walk_portal(&bundle, &mut s, &asset, player, 5.0);
    walk_portal(&bundle, &mut s, &asset, player, 7.0);
    (bundle, s, player, asset)
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

fn one(s: &Scene, object: i32) -> i32 {
    *cast(s, object).first().unwrap_or_else(|| panic!("no live object {object}"))
}

/// Put the player inside Lloyd's 100 px trigger and pump one frame.
fn walk_up_to_lloyd(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, player: i32, lloyd: i32) {
    let (lx, ly) = (s.instances[&lloyd].fields["x"], s.instances[&lloyd].fields["y"]);
    s.write(player, -1, "x", None, lx).unwrap();
    s.write(player, -1, "y", None, ly).unwrap();
    s.tick(bundle).unwrap();
}

/// Drive Lloyd's own heartbeat so the room's tutorial sheet really spawns.
fn lloyd_hands_over(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, player: i32, lloyd: i32, sheet: i32) -> i32 {
    walk_up_to_lloyd(bundle, s, player, lloyd);
    for _ in 0..32 {
        if s.instances[&lloyd].alive {
            // The heartbeat arms alarm[1] on its own 30-tick cadence.
            if s.instances[&lloyd].alarms[1] == 1 {
                s.tick(bundle).unwrap();
                if !cast(s, sheet).is_empty() { break; }
            }
            s.tick(bundle).unwrap();
        }
        if !cast(s, sheet).is_empty() { break; }
    }
    one(s, sheet)
}

#[test]
fn lloyd_stops_the_player_and_hands_over_to_the_room_tutorial() {
    let (bundle, mut s, player, _asset) = load_scene();
    let lloyd = one(&s, LLOYD);
    // CODE 670 Create: idle NPC with a 30-tick heartbeat and a 1-tick retire check.
    assert_eq!(s.instances[&lloyd].fields["startlloyd"], 0.0, "CODE 670 startlloyd");
    assert_eq!(s.instances[&lloyd].alarms[2], 30, "CODE 670 alarm[2] = 30 heartbeat");
    assert_eq!(s.instances[&lloyd].alarms[0], 1, "CODE 670 alarms the retire check");
    assert_eq!(s.instances[&lloyd].fields["hspeed"], 0.0, "Lloyd stands still");
    assert!(cast(&s, LEFT_BUTTON).len() == 1 && cast(&s, RIGHT_BUTTON).len() == 1,
        "obj_UI Create (CODE 365) placed the virtual buttons");

    walk_up_to_lloyd(&bundle, &mut s, player, lloyd);
    // CODE 675's proximity block.
    assert_eq!(s.globals["roomstart"], 1.0, "CODE 675 raises global.roomstart");
    assert_eq!(s.instances[&lloyd].fields["startlloyd"], 1.0, "CODE 675 raises startlloyd");
    assert!(cast(&s, LEFT_BUTTON).is_empty() && cast(&s, RIGHT_BUTTON).is_empty(),
        "CODE 675 drops both virtual buttons");
    let p = &s.instances[&player];
    assert_eq!((p.fields["hspeed"], p.fields["vspeed"], p.fields["hsp"]), (0.0, 0.0, 0.0),
        "CODE 675 freezes the player in place");

    let sheet = lloyd_hands_over(&bundle, &mut s, player, lloyd, TUT2);
    assert_eq!(s.instances[&sheet].fields["x"], s.instances[&lloyd].fields["x"],
        "CODE 673 spawns the sheet on Lloyd");
    assert_eq!(s.instances[&sheet].fields["y"], s.instances[&lloyd].fields["y"],
        "CODE 673 spawns the sheet on Lloyd");
}

#[test]
fn the_sheet_freezes_the_world_and_runs_its_panel_timeline() {
    let (bundle, mut s, player, _asset) = load_scene();
    // A voice that predates the cutscene proves audio_pause_all really fires.
    let music = s.call_audio_play(7.0, 0.0, false);
    assert!(s.audio_is_playing_sound(7.0), "the pre-cutscene voice is audible");
    let lloyd = one(&s, LLOYD);
    let sheet = lloyd_hands_over(&bundle, &mut s, player, lloyd, TUT2);

    // CODE 565 Create.
    let active: Vec<i32> = s.instances.iter()
        .filter(|(_, i)| i.alive && i.active)
        .map(|(id, _)| *id)
        .collect();
    assert_eq!(active, vec![sheet],
        "instance_deactivate_all(true) freezes everything except the sheet");
    assert_eq!(s.instances[&sheet].fields["taplock"], 0.0, "CODE 565 taplock");
    let panels: Vec<f64> = (1..=6).map(|n| s.instances[&sheet].fields[&format!("drawpanel{n}")]).collect();
    assert_eq!(panels, vec![1.0, 0.0, 0.0, 0.0, 0.0, 0.0], "CODE 565 opens on panel 1");
    assert_eq!(s.instances[&sheet].alarms[0], 100, "CODE 565 alarm[0] = 100");
    assert_eq!(s.instances[&sheet].alarms[1], 200, "CODE 565 alarm[1] = 200");
    assert_eq!(s.instances[&sheet].alarms[5], 300, "CODE 565 alarm[5] = 300");
    assert!(s.audio_voices.iter().any(|v| v.voice == music && v.paused),
        "audio_pause_all paused the running playlist");
    assert!(s.audio.iter().any(|c| c.sound == MUS_TOWNMUSIC && c.looping),
        "CODE 565 cues mus_townmusic as a loop through the mute gate");
    let town = s.audio_voices.iter().find(|v| v.sound == MUS_TOWNMUSIC as f64)
        .expect("the townmusic voice exists");
    assert!(!town.paused, "the cutscene track plays after the pause");

    // The timeline: 100 -> panel 2, 200 -> panel 3, 300 -> taplock.
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["drawpanel1"], 0.0, "alarm[0] closes panel 1");
    assert_eq!(s.instances[&sheet].fields["drawpanel2"], 1.0, "alarm[0] opens panel 2");
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["drawpanel2"], 0.0, "alarm[1] closes panel 2");
    assert_eq!(s.instances[&sheet].fields["drawpanel3"], 1.0, "alarm[1] opens panel 3");
    assert_eq!(s.instances[&sheet].fields["taplock"], 0.0, "still locked before 300");
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["taplock"], 1.0, "alarm[5] unlocks the tap at 300");
    assert_eq!(s.instances[&sheet].fields["drawpanel3"], 1.0, "panel 3 stays open");
}

#[test]
fn the_panels_draw_their_lines_and_unlock_the_tap_prompt() {
    let (bundle, mut s, player, _asset) = load_scene();
    let lloyd = one(&s, LLOYD);
    let sheet = lloyd_hands_over(&bundle, &mut s, player, lloyd, TUT2);

    // Panel 1 (view 0): the two lines of CODE 570's drawpanel1 block.
    s.draw_view(&bundle, 0).unwrap();
    let lines: Vec<(f64, f64, String)> = s.texts.iter()
        .map(|t| (t.x, t.y, t.text.clone())).collect();
    assert!(lines.contains(&(100.0, 50.0, "Hey! Looks like you".to_string())),
        "panel 1 draws its first line at view_xview[0] + 100 / + 50, got {lines:?}");
    assert!(lines.contains(&(100.0, 70.0, "Found your first gun!".to_string())),
        "panel 1 draws its second line 20 px lower");
    assert!(s.texts.iter().all(|t| t.color == C_WHITE), "draw_set_color(c_white) applies");
    assert!(lines.iter().all(|(_, _, t)| !t.contains("Tap to Continue")),
        "no tap prompt while taplock == 0");
    assert!(lines.iter().all(|(_, _, t)| !t.contains("These guns come equipped with")),
        "panel 2 stays hidden while panel 1 is open");

    // Panel 3 + taplock (view 0): different line pair, plus the prompt.
    s.write(sheet, -1, "drawpanel1", None, 0.0).unwrap();
    s.write(sheet, -1, "drawpanel3", None, 1.0).unwrap();
    s.write(sheet, -1, "taplock", None, 1.0).unwrap();
    s.draw_view(&bundle, 0).unwrap();
    let lines: Vec<(f64, f64, String)> = s.texts.iter()
        .map(|t| (t.x, t.y, t.text.clone())).collect();
    assert!(lines.contains(&(100.0, 50.0, "Look for the red numbers to see".to_string())),
        "panel 3 draws its own first line, got {lines:?}");
    assert!(lines.contains(&(100.0, 70.0, "how much damage you are doing!".to_string())),
        "panel 3 draws its own second line");
    assert!(lines.contains(&(150.0, 200.0, "Tap to Continue".to_string())),
        "taplock == 1 adds the prompt at view_xview[0] + 150 / + 200");
    // CODE 570's view-0 composition, verbatim: backdrop at view_xview[0] - 1
    // with scale (0.96, 0.8), Lloyd's portrait at (+50, +50) scale (2, 2) with
    // the -3 frame passed straight through to the client, and the mirrored
    // player portrait at (+380, +180) with rotation 1.
    assert!(s.draws.iter().any(|d| d.x == -1.0 && d.y == 0.0 && d.frame == 1.0
        && (d.scale_x - 0.96).abs() < 1e-9 && (d.scale_y - 0.8).abs() < 1e-9),
        "the pause backdrop is composited at view_xview[0] - 1 with the CODE 570 scale");
    assert!(s.draws.iter().any(|d| d.x == 50.0 && d.y == 50.0 && d.frame == -3.0
        && d.scale_x == 2.0 && d.scale_y == 2.0),
        "Lloyd's portrait sits at (+50, +50) at double scale with frame -3 passed through");
    assert!(s.draws.iter().any(|d| d.x == 380.0 && d.y == 180.0 && d.scale_x == -2.0
        && d.scale_y == 2.0 && d.rotation == 1.0),
        "the player portrait is mirrored at (+380, +180) with rotation 1");
}

#[test]
fn tapping_the_sheet_dismisses_it_and_lands_the_save_flag() {
    let (bundle, mut s, player, _asset) = load_scene();
    let music = s.call_audio_play(7.0, 0.0, false);
    let lloyd = one(&s, LLOYD);
    let sheet = lloyd_hands_over(&bundle, &mut s, player, lloyd, TUT2);
    assert!(s.audio_voices.iter().any(|v| v.voice == music && v.paused),
        "the playlist is paused by the sheet");

    s.write(sheet, -1, "taplock", None, 1.0).unwrap();
    assert!(cast(&s, LEFT_BUTTON).is_empty(), "the buttons are still gone before the tap");

    // CODE 570's last block: a released primary device destroys the sheet.
    s.touch_devices[0].x = 200.0;
    s.touch_devices[0].y = 200.0;
    s.touch_devices[0].released = true;
    s.draw_view(&bundle, 0).unwrap();
    assert!(!s.instances[&sheet].alive, "the tap destroys the sheet");

    // CODE 566 Destroy.
    assert_eq!(s.globals["talkedtolloyd2"], 1.0, "CODE 566 raises the room's talked flag");
    assert_eq!(s.ini_data.get(&("savefile.ini".to_string(), "Save".to_string(), "talkedtolloyd2".to_string())).copied(),
        Some(1.0), "CODE 566 writes talkedtolloyd2 into savefile.ini [Save]");
    assert!(s.audio_voices.iter().any(|v| v.voice == music && !v.paused),
        "audio_resume_all released the earlier playlist voice");
    assert!(s.take_stop_commands().contains(&(MUS_TOWNMUSIC as f64)),
        "CODE 566 stops mus_townmusic through the host stop queue");
    assert!(s.audio_voices.iter().all(|v| !v.paused),
        "audio_resume_all releases the paused playlist");
    assert!(s.instances.values().filter(|i| i.alive && i.active).count() > 1,
        "instance_activate_all unfreezes the world");
    assert!(cast(&s, LLOYD).is_empty(), "CODE 566 destroys obj_lloyd");
    assert!(cast(&s, LEFT_BUTTON).len() == 1 && cast(&s, RIGHT_BUTTON).len() == 1,
        "CODE 566 re-creates both virtual buttons");
    assert_eq!(s.globals["roomstart"], 0.0, "CODE 566 lowers global.roomstart again");
}

#[test]
fn lloyd_retires_once_its_room_is_done_or_the_gun_is_bought() {
    // CODE 674: rm_level1 retires Lloyd on talkedtolloyd2, and separately on
    // shotgunbought - two independent self-destruct gates.
    let (bundle, mut s, _player, _asset) = load_scene();
    let lloyd = one(&s, LLOYD);
    for _ in 0..5 { s.tick(&bundle).unwrap(); }
    assert!(s.instances[&lloyd].alive, "an untouched rm_level1 keeps its Lloyd");
    s.globals.insert("talkedtolloyd2".into(), 1.0);
    s.instances.get_mut(&lloyd).unwrap().alarms[0] = 1;
    for _ in 0..2 { s.tick(&bundle).unwrap(); }
    assert!(!s.instances[&lloyd].alive, "talkedtolloyd2 == 1 retires Lloyd");

    let (bundle, mut s, _player, _asset) = load_scene();
    let lloyd = one(&s, LLOYD);
    s.globals.insert("shotgunbought".into(), 1.0);
    s.instances.get_mut(&lloyd).unwrap().alarms[0] = 1;
    for _ in 0..2 { s.tick(&bundle).unwrap(); }
    assert!(!s.instances[&lloyd].alive, "shotgunbought == 1 retires rm_level1's Lloyd too");
}

#[test]
fn level7_lloyd_maps_onto_the_thirteenth_sheet_with_its_own_timeline() {
    let (bundle, mut s, player, _asset) = level7_scene();
    assert_eq!(s.current_room, 7.0, "the CODE 815 door chain lands in rm_level7");
    let lloyd = one(&s, LLOYD);
    let sheet = lloyd_hands_over(&bundle, &mut s, player, lloyd, TUT13);

    // CODE 673's room table sends rm_level7 to the thirteenth sheet.
    assert!(cast(&s, TUT2).is_empty(), "rm_level7 must not use the level-1 sheet");
    // CODE 642 Create: five panel beats instead of three.
    assert_eq!(s.instances[&sheet].alarms[0], 100, "CODE 642 alarm[0] = 100");
    assert_eq!(s.instances[&sheet].alarms[1], 200, "CODE 642 alarm[1] = 200");
    assert_eq!(s.instances[&sheet].alarms[2], 300, "CODE 642 alarm[2] = 300");
    assert_eq!(s.instances[&sheet].alarms[3], 400, "CODE 642 alarm[3] = 400");
    assert_eq!(s.instances[&sheet].alarms[5], 500, "CODE 642 alarm[5] = 500");
    assert_eq!(s.instances[&sheet].fields["drawpanel1"], 1.0, "opens on panel 1");
    assert_eq!(s.instances[&sheet].fields["drawpanel4"], 0.0, "panel 4 is still closed");
    assert!(s.audio.iter().any(|c| c.sound == MUS_TOWNMUSIC && c.looping),
        "the sheet re-cues mus_townmusic in rm_level7 as well");

    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["drawpanel2"], 1.0, "alarm[0] -> panel 2");
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["drawpanel3"], 1.0, "alarm[1] -> panel 3");
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["drawpanel4"], 1.0, "alarm[2] -> panel 4");
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["drawpanel5"], 1.0, "alarm[3] -> panel 5");
    assert_eq!(s.instances[&sheet].fields["taplock"], 0.0, "still locked before 500");
    for _ in 0..100 { s.tick(&bundle).unwrap(); }
    assert_eq!(s.instances[&sheet].fields["taplock"], 1.0, "alarm[5] unlocks at 500");
}
