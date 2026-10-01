//! Every Lloyd tutorial sheet (obj_lloydtutorial1..16) against its GML
//! (ledger T2: the 13-untouched-sheet gap, all 16 covered table-driven).
//!
//! Shared template (recovered GML CODE 556..670, dumped 2026-09-28):
//!   * Create arms one alarm per panel step at 100-tick spacing and the
//!     unlock at alarm[5]; every Alarm_k (k<5) is exactly
//!     `drawpanel_k = 0; drawpanel_(k+1) = 1`; Alarm_5 is `taplock = 1`.
//!     Sheet-specific arms: 1/11/12 = 6 panels (A5=600), 4/5/6/8/13/15/16
//!     = 5 (A5=500), 2/7 = 3 (A5=300/350), 3/9/10 = 2 (A5=200),
//!     14 = single panel (A0=100 AND A5=100).
//!   * Music gate: all sheets except 5 and 9 do audio_pause_all + loop
//!     mus_townmusic in Create and stop+resume in Destroy; sheet 9 resumes
//!     but never stops, sheet 5 does neither.
//!   * Sheet 1 alone calls mouse_clear(mb_any) in Create (CODE 556).
//!   * Destroy: raise global.talkedtolloyd{N} + ini [Save] write,
//!     instance_activate_all, destroy obj_lloyd, recreate both virtual
//!     buttons, lower global.roomstart.
//!   * Draw_0: first panel-1 line at view + (100, 50) with its own text.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const LLOYD: i32 = 154;
const LEFT_BUTTON: i32 = 130;
const RIGHT_BUTTON: i32 = 131;

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

fn fresh(asset: &GameDroidAsset, bundle: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(bundle);
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
    s.load_room_from_data(bundle, 1, &asset.rooms[1]).unwrap();
    s.view_positions.insert(0, (0.0, 0.0));
    s
}

/// Spawn one sheet standalone (Create event through the real dispatch).
fn sheet(s: &mut Scene, bundle: &Bundle, id: i32) -> i32 {
    s.create(bundle, id, 200.0, 200.0).expect("sheet create")
}

/// (sheet object id, alarm[5] unlock tick, last panel index reached)
const TIMELINES: [(i32, usize, usize); 16] = [
    (138, 600, 6), (139, 300, 3), (140, 200, 2), (141, 500, 5),
    (142, 500, 5), (143, 500, 5), (144, 350, 3), (145, 500, 5),
    (146, 200, 2), (147, 200, 2), (148, 600, 6), (149, 600, 6),
    (150, 500, 5), (151, 100, 1), (152, 500, 5), (153, 500, 5),
];

/// Panel cadence per GML: sheet k's Create arms alarm[j] = 100*(j+1) for
/// every panel transition j (0-based, j < panels-1), plus alarm[5] = unlock.
/// Sheet 14 arms alarm[0] (dangling, no handler) and alarm[5] = 100.
/// (Ticks counted here are the raw GML values; the scheduler's same-tick
/// decrement is pinned by `the_panel_chain_walks_every_sheet_to_its_unlock`.)
/// Host convention: a never-armed slot keeps -1 (insert_external inits
/// alarms to [-1;12]); Create only writes the slots its ladder arms.
fn expected_arms(panels: usize, unlock: usize) -> [i32; 6] {
    let mut a = [-1i32; 6];
    for j in 0..panels.saturating_sub(1) {
        a[j] = (100 * (j + 1)) as i32;
    }
    if panels == 1 {
        a[0] = 100; // sheet 14 arms alarm[0] although no Alarm_0 handler exists
    }
    a[5] = unlock as i32;
    a
}

#[test]
fn every_sheet_arms_its_alarm_ladder_and_opens_on_panel_one() {
    let (asset, bundle) = game();
    for (id, unlock, panels) in TIMELINES {
        let mut s = fresh(&asset, &bundle);
        let sheet_id = sheet(&mut s, &bundle, id);
        let inst = &s.instances[&sheet_id];
        let expect = expected_arms(panels, unlock);
        assert_eq!(&inst.alarms[..6], &expect[..], "sheet {id} alarm ladder");
        assert_eq!(inst.fields["taplock"], 0.0, "sheet {id} starts tap-locked");
        let flags: Vec<f64> = (1..=6).map(|p| inst.fields[&format!("drawpanel{p}")]).collect();
        assert_eq!(flags, vec![1.0, 0.0, 0.0, 0.0, 0.0, 0.0], "sheet {id} opens on panel 1");
    }
}

#[test]
fn the_panel_chain_walks_every_sheet_to_its_unlock() {
    let (asset, bundle) = game();
    for (id, unlock, panels) in TIMELINES {
        let mut s = fresh(&asset, &bundle);
        let sheet_id = sheet(&mut s, &bundle, id);
        // World must be frozen to just the sheet.
        let active: Vec<i32> = s.instances.iter()
            .filter(|(_, i)| i.alive && i.active)
            .map(|(k, _)| *k).collect();
        assert!(active.len() == 1 && active[0] == sheet_id,
            "sheet {id}: deactivate_all must leave only itself active");

        let mut elapsed = 0usize;
        for step in 1..panels {
            while elapsed < step * 100 {
                s.tick(&bundle).unwrap();
                elapsed += 1;
            }
            let f = &s.instances[&sheet_id].fields;
            let get = |p: usize| f[&format!("drawpanel{p}")];
            assert_eq!((get(step), get(step + 1)), (0.0, 1.0),
                "sheet {id}: panel {step} -> {} at tick {}", step + 1, step * 100);
        }
        while elapsed < unlock {
            s.tick(&bundle).unwrap();
            elapsed += 1;
        }
        let f = &s.instances[&sheet_id].fields;
        assert_eq!(f["taplock"], 1.0, "sheet {id} unlocks the tap at tick {unlock}");
        assert_eq!(f[&format!("drawpanel{panels}")], 1.0, "sheet {id} ends on panel {panels}");
    }
}

#[test]
fn sheet_one_clears_the_mouse_and_the_others_do_not() {
    let (asset, bundle) = game();
    let mut s = fresh(&asset, &bundle);
    // Seed a held/pressed mouse before each create.
    s.touch_devices[0].down = true;
    s.touch_devices[0].pressed = true;
    let one = sheet(&mut s, &bundle, 138);
    assert!(s.touch_devices.iter().all(|d| !d.down && !d.pressed),
        "CODE 556 mouse_clear(mb_any) drops the held mouse (sheet 1)");
    let _ = one;

    let mut s2 = fresh(&asset, &bundle);
    s2.touch_devices[0].down = true;
    s2.touch_devices[0].pressed = true;
    sheet(&mut s2, &bundle, 139);
    assert!(s2.touch_devices[0].down && s2.touch_devices[0].pressed,
        "sheet 2's Create has no mouse_clear — the held mouse survives");
}

#[test]
fn music_gate_sheets_pause_and_resume_townmusic_and_the_two_exceptions_do_not() {
    let (asset, bundle) = game();
    // (sheet, does its Create cue townmusic?, does its Destroy stop it?, resume?)
    for (id, cue, stop, resume) in [(138usize, true, true, true), (142, false, false, false), (146, false, false, true)] {
        let mut s = fresh(&asset, &bundle);
        let music = s.call_audio_play(7.0, 0.0, false);
        let sheet_id = s.create(&bundle, id as i32, 200.0, 200.0).unwrap();
        assert_eq!(s.audio_voices.iter().any(|v| v.voice == music && v.paused), cue,
            "sheet {id}: audio_pause_all iff the CODE has the music gate");
        assert_eq!(s.audio.iter().any(|c| c.sound == 32 && c.looping), cue,
            "sheet {id}: Create cues mus_townmusic iff the CODE does");
        // For the no-gate sheets, park the voice paused ourselves so the
        // presence/absence of audio_resume_all in Destroy is observable.
        if !cue {
            s.audio_voices.iter_mut()
                .find(|v| v.voice == music)
                .expect("music voice").paused = true;
        }
        // Dismiss through the tap gate.
        s.write(sheet_id, -1, "taplock", None, 1.0).unwrap();
        s.touch_devices[0].released = true;
        s.draw_view(&bundle, 0).unwrap();
        assert!(!s.instances[&sheet_id].alive, "sheet {id} tap-destroys");
        if stop {
            assert!(s.take_stop_commands().contains(&32.0),
                "sheet {id}: Destroy stops mus_townmusic");
        } else {
            assert!(!s.take_stop_commands().iter().any(|x| *x == 32.0),
                "sheet {id}: Destroy stops nothing");
        }
        assert_eq!(
            s.audio_voices.iter().any(|v| v.voice == music && v.paused),
            !resume,
            "sheet {id}: the voice is unpaused iff CODE has audio_resume_all");
    }
}

#[test]
fn every_sheet_destroy_lands_its_flag_ini_row_lloyd_retire_and_buttons() {
    let (asset, bundle) = game();
    for (n, (id, _unlock, _panels)) in TIMELINES.iter().enumerate() {
        let mut s = fresh(&asset, &bundle);
        let lloyd_before = s.instances.iter()
            .filter(|(_, i)| i.object == LLOYD && i.alive)
            .map(|(k, _)| *k).collect::<Vec<_>>();
        let buttons_before = s.instances.iter()
            .filter(|(_, i)| i.alive && (i.object == LEFT_BUTTON || i.object == RIGHT_BUTTON))
            .count();
        let sheet_id = sheet(&mut s, &bundle, *id);
        s.write(sheet_id, -1, "taplock", None, 1.0).unwrap();
        s.touch_devices[0].released = true;
        s.draw_view(&bundle, 0).unwrap();

        let flag = format!("talkedtolloyd{}", n + 1);
        assert_eq!(s.globals[&flag], 1.0, "sheet {id} raises global.{flag}");
        // CODE 663 (sheet 16) is the only one that opens savefile2.ini.
        let file = if n + 1 == 16 { "savefile2.ini" } else { "savefile.ini" };
        assert_eq!(
            s.ini_data.get(&(file.to_string(), String::from("Save"), flag.clone())).copied(),
            Some(1.0),
            "sheet {id} writes [Save] {flag} into {file}",
        );
        for lloyd in &lloyd_before {
            assert!(!s.instances[lloyd].alive, "sheet {id} destroys obj_lloyd {lloyd}");
        }
        assert_eq!(s.globals["roomstart"], 0.0, "sheet {id} lowers global.roomstart");
        let buttons_after = s.instances.iter()
            .filter(|(_, i)| i.alive && (i.object == LEFT_BUTTON || i.object == RIGHT_BUTTON))
            .count();
        assert_eq!(buttons_after, buttons_before + 2,
            "sheet {id} recreates both virtual buttons on dismiss");
    }
}

#[test]
fn each_sheet_panel_one_draws_its_own_first_line_from_the_gml() {
    // First panel-1 line per Draw CODE, transcribed from the recovered GML
    // (view + 100 / view + 50 for every sheet).
    const FIRST_LINES: [(i32, &str); 16] = [
        (138, "Hey Cally! It's me, Lloyd."),
        (139, "Hey! Looks like you"),
        (140, "Since your parents didn't sign"),
        (141, "Hey Cally!"),
        (142, "You beat your first boss!"),
        (143, "Hey there... As you may have noticed,"),
        (144, "Things are getting pretty tough, eh?"),
        (145, "4, 8, 15, 16..."),
        (146, "Another Boss defeated!"),
        (147, "Long time, no see Cally..."),
        (148, "I'm BACK!"),
        (149, "Well Cally,"),
        (150, "Gosh, these shootin' guys"),
        (151, "Pick a Box. Its contents"),
        (152, "You may have noticed you are"),
        (153, "Hey Cally!"),
    ];
    let (asset, bundle) = game();
    for (id, line) in FIRST_LINES {
        let mut s = fresh(&asset, &bundle);
        sheet(&mut s, &bundle, id);
        s.draws.clear();
        s.texts.clear();
        s.draw_view(&bundle, 0).unwrap();
        assert!(
            s.texts.iter().any(|t| t.text == line && t.x == 100.0 && t.y == 50.0),
            "sheet {id} must draw '{line}' at view + (100,50), got {:?}",
            s.texts.iter().map(|t| (&t.text, t.x, t.y)).collect::<Vec<_>>(),
        );
    }
}
