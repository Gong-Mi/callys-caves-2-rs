//! ID-level body semantics for the remaining Lloyd/store/pause/intro CODEs.
//!
//! The census tiers left 24 bodies with no *id-level* test citation: they were
//! either classified only as `env_classified` (their `with()` sites are covered
//! by reconstruction/contracts/env-semantics.md at the VM layer, but nothing
//! named the body itself), or cited only by object name. This module names each
//! one and pins what that body alone observes on a live scene.
//!
//! Three families:
//!
//!   * Lloyd tutorial sheets 3..15 Destroy (obj_lloydtutorial3..15). One shape,
//!     thirteen codes: raise `global.talkedtolloydN`, land it in savefile.ini
//!     `[Save]`, gate mus_townmusic (`audio_stop_sound` on 11 of them, none on
//!     sheet 5, resume-only on sheet 9 - this is where 585 and 615 differ from
//!     the other eleven), `instance_activate_all`, `with (obj_lloyd) {
//!     instance_destroy }`, re-create both virtual buttons at the body's own
//!     (x, y), lower `global.roomstart`. Sheets 9..15 order the button creation
//!     *before* the lloyd with-block; sheets 3..8 after. Both lloyd's Destroy
//!     (CODE 671) and the buttons' Create (CODE 528) are a bare
//!     `mouse_clear(mb_any)`, so the two orderings are observationally
//!     equivalent - which is asserted here rather than assumed.
//!
//!   * The store dialogs and the two pause menus: the `Mouse_7` bodies that
//!     cancel/switch the menus (478, 481, 489, 492) and the Destroy cleanups
//!     that sweep a named furniture list (499, 508, 513). These are the bodies
//!     whose whole content is `if (instance_exists(o)) { with (o) {...} }`.
//!
//!   * The three intro banners' retirement: obj_boss1intro's Create (739) and
//!     its Alarm_0 (740), plus the identical Alarm_0 bodies of obj_bearcubintro
//!     (722) and obj_boss6intro (779), driven through the timer the Create
//!     itself armed rather than by poking the alarm slot.
//!
//! Every body here is dispatched as the original event (`s.dispatch(&b, id,
//! type, subtype)`), so the assertions read the body's own effect on the scene.
//! This is IR-regression semantics against the recovered GML/IR - not a proof
//! of runtime equivalence with the original runner (see the repo's evidence
//! tiers).

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{Instance, Scene};
use std::collections::BTreeMap;
use std::path::Path;

// Object ids as they stand in the IR object table - the same numbers the CODE
// bodies themselves push as constants.
const PLAYER: i32 = 0;
const MUSIC: i32 = 68;
const POWERUPGRADE: i32 = 84;
const POWERUPGRADE2: i32 = 85;
const POWERUPGRADE3: i32 = 86;
const TRIPLEJUMP: i32 = 87;
const SWORDUPGRADE: i32 = 88;
const SWORDUPGRADE2: i32 = 89;
const SWORDUPGRADE3: i32 = 90;
const ENERGYWAVEUPGRADE: i32 = 91;
const HEALTHREGEN: i32 = 92;
const STRENGTHUPGRADE: i32 = 93;
const STRENGTHUPGRADE2: i32 = 94;
const COINMULTIPLIER5: i32 = 95;
const COINMULTIPLIER2: i32 = 96;
const MAXHPUPGRADE: i32 = 97;
const MAXHPUPGRADE2: i32 = 98;
const HEALTHREFILL: i32 = 99;
const VOLUME: i32 = 107;
const BACKTOGAME: i32 = 108;
const VOLUMEMUSIC: i32 = 109;
const STORE: i32 = 110;
const YESRESTOREDATA: i32 = 112;
const NORESTOREDATA: i32 = 113;
const AREYOUSURE: i32 = 114;
const RESTOREDATA: i32 = 115;
const STOREPAGESWITCH: i32 = 116;
const STOREPAGESWITCH2: i32 = 117;
const FIRSTPAUSE: i32 = 118;
const IAPMENU: i32 = 119;
const POISONIAP: i32 = 120;
const RESTOREIAP: i32 = 121;
const PAUSE: i32 = 122;
const PAUSE2: i32 = 123;
const PAUSEBUTTON: i32 = 125;
const SHOOTBUTTON: i32 = 128;
const LEFT_BUTTON: i32 = 130;
const RIGHT_BUTTON: i32 = 131;
const LLOYD: i32 = 154;
const LINELEFT: i32 = 164;
const LINERIGHT: i32 = 165;
const BEARCUBINTRO: i32 = 166;
const BOSS1INTRO: i32 = 172;
const BOSS6INTRO: i32 = 185;

/// mus_townmusic, from reconstruction/contracts/audio-sond.json.
const MUS_TOWNMUSIC: f64 = 32.0;
/// snd_meetnewenemy's SOND id, read straight out of the intro Create bodies.
const SND_MEETNEWENEMY: i32 = 4;
/// rm_town, the room CODE 478 warps back to.
const RM_TOWN: usize = 0;

fn bundle() -> Bundle {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut b = load_bundle_from_file(&root.join("src/generated/full_ir.json")).expect("load full_ir.json");
    // These bodies pass file names, ini sections/keys and window titles through
    // `string` references, which the host resolves against the bundle's string
    // table (`arg_text` -> `pool_text`). full_ir.json carries no string table,
    // so the asset's is the one the bodies must resolve against - otherwise
    // every `ini_open`/`file_delete` name degrades to a number.
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).expect("parse game.droid");
    b.string_table = asset.string_table.clone();
    b
}

/// Bundle + the verified fresh-start global table (`init_fresh_start_globals`).
/// No room is loaded: the bodies below only read globals, and loading a room
/// would bury the targets of the `with`-loops in a thousand unrelated instances.
fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s
}

/// A live, active, non-external instance placed by hand: the furniture these
/// bodies sweep must not run its own Create (that is a different CODE, and its
/// Create is what spawns the store's paired furniture).
fn raw(s: &mut Scene, id: i32, object: i32, x: f64, y: f64) -> i32 {
    let mut fields = BTreeMap::new();
    fields.insert("id".to_string(), id as f64);
    fields.insert("x".to_string(), x);
    fields.insert("y".to_string(), y);
    s.instances.insert(id, Instance {
        object, alive: true, active: true, external: false, spawn_seq: 0,
        fields, arrays: BTreeMap::new(), alarms: [-1; 12],
    });
    id
}

fn alive(s: &Scene, id: i32) -> bool {
    s.instances.get(&id).map(|i| i.alive).unwrap_or(false)
}

fn count(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|i| i.object == object && i.alive).count()
}

/// The live instances of one object, oldest id first.
fn live_ids(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter().filter(|(_, i)| i.object == object && i.alive).map(|(k, _)| *k).collect()
}

// ---------------------------------------------------------------------------
// Lloyd tutorial sheets 3..15 - Destroy_0
// ---------------------------------------------------------------------------

/// (CODE id, sheet object, `global.talkedtolloydN` it raises, stops
///  mus_townmusic, resumes the audio, spawns the buttons before the lloyd
///  with-block)
#[allow(non_snake_case)]
const LLOYD_TUTORIAL_DESTROY: [(usize, i32, &str, bool, bool, bool); 13] = [
    // CODE 572 — obj_lloydtutorial3
    (572, 140, "talkedtolloyd3", true, true, false),
    // CODE 577 — obj_lloydtutorial4
    (577, 141, "talkedtolloyd4", true, true, false),
    // CODE 585 — obj_lloydtutorial5: no music gate at all in Destroy
    (585, 142, "talkedtolloyd5", false, false, false),
    // CODE 593 — obj_lloydtutorial6
    (593, 143, "talkedtolloyd6", true, true, false),
    // CODE 601 — obj_lloydtutorial7
    (601, 144, "talkedtolloyd7", true, true, false),
    // CODE 607 — obj_lloydtutorial8
    (607, 145, "talkedtolloyd8", true, true, false),
    // CODE 615 — obj_lloydtutorial9: resumes but never stops the town music
    (615, 146, "talkedtolloyd9", false, true, true),
    // CODE 620 — obj_lloydtutorial10
    (620, 147, "talkedtolloyd10", true, true, true),
    // CODE 625 — obj_lloydtutorial11
    (625, 148, "talkedtolloyd11", true, true, true),
    // CODE 634 — obj_lloydtutorial12
    (634, 149, "talkedtolloyd12", true, true, true),
    // CODE 643 — obj_lloydtutorial13
    (643, 150, "talkedtolloyd13", true, true, true),
    // CODE 651 — obj_lloydtutorial14
    (651, 151, "talkedtolloyd14", true, true, true),
    // CODE 655 — obj_lloydtutorial15
    (655, 152, "talkedtolloyd15", true, true, true),
];

/// Drive one sheet's Destroy body through the real dispatch and check the
/// effects the body itself owns.
///
/// `lloyds` is how many obj_lloyd instances the scene holds: the GML puts the
/// destroy in `with (obj_lloyd)`, so one dispatch must retire every one of
/// them (and, with none, must still leave the environment stack balanced).
fn sheet_destroy_run(b: &Bundle, code: usize, object: i32, flag: &str,
                     stops_music: bool, resumes: bool, lloyds: usize) {
    let mut s = scene(b);
    // A voice that predates the cutscene: audio_resume_all's reach is only
    // observable on a voice that was already playing.
    let voice = s.call_audio_play(7.0, 0.0, false);
    s.call_audio_pause_all();
    assert!(s.audio_voices.iter().any(|v| v.voice == voice && v.paused),
        "CODE {code}: the harness parks a paused voice first");

    let mut lloyd_ids = Vec::new();
    for n in 0..lloyds {
        lloyd_ids.push(raw(&mut s, 900_000 + n as i32, LLOYD, 100.0 + n as f64, 100.0));
    }

    let sheet = s.create(b, object, 200.0, 200.0).expect("sheet Create");
    let (sx, sy) = (s.instances[&sheet].fields["x"], s.instances[&sheet].fields["y"]);
    // Create's instance_deactivate_all(true) freezes the world, lloyds included:
    // the Destroy body can only reach them because it calls instance_activate_all.
    for id in &lloyd_ids {
        assert!(alive(&s, *id) && !s.instances[id].active,
            "CODE {code}: the sheet's Create parked the pre-existing obj_lloyd");
    }
    s.globals.insert("roomstart".into(), 1.0);
    // Before/after control: the flag this body raises is flat beforehand.
    assert_eq!(s.globals.get(flag).copied().unwrap_or(0.0), 0.0,
        "CODE {code}: {flag} is flat before the body runs");
    for d in s.touch_devices.iter_mut() { d.down = true; d.pressed = true; }

    s.dispatch(b, sheet, 1, 0).unwrap_or_else(|e| panic!("CODE {code} Destroy: {e}"));

    // The save flag, in the global and in the ini row the body writes.
    assert_eq!(s.globals.get(flag).copied(), Some(1.0),
        "CODE {code}: raises global.{flag}");
    assert_eq!(
        s.ini_data.get(&("savefile.ini".to_string(), "Save".to_string(), flag.to_string())).copied(),
        Some(1.0),
        "CODE {code}: writes [Save] {flag} into savefile.ini");

    // Music gate: stop iff the body carries the audio_stop_sound block, resume
    // iff it carries audio_resume_all.
    let stops = s.take_stop_commands();
    assert_eq!(stops.contains(&MUS_TOWNMUSIC), stops_music,
        "CODE {code}: audio_stop_sound(mus_townmusic) is present iff the body has the gate");
    if stops_music {
        assert!(s.audio_voices.iter().any(|v| v.sound == MUS_TOWNMUSIC && v.stopped),
            "CODE {code}: the town-music voice is the one that got stopped");
    }
    assert_eq!(s.audio_voices.iter().all(|v| !v.paused), resumes,
        "CODE {code}: audio_resume_all is present iff the body carries it");

    // The with (obj_lloyd) body.
    assert_eq!(lloyd_ids.iter().filter(|id| alive(&s, **id)).count(), 0,
        "CODE {code}: with (obj_lloyd) ran once per selected instance ({lloyds} of them)");
    assert_eq!(count(&s, LLOYD), 0, "CODE {code}: no live obj_lloyd survives the block");

    // The re-created virtual buttons, at the body's own (x, y).
    assert_eq!(count(&s, LEFT_BUTTON), 1, "CODE {code}: obj_leftbutton re-created");
    assert_eq!(count(&s, RIGHT_BUTTON), 1, "CODE {code}: obj_rightbutton re-created");
    for object in [LEFT_BUTTON, RIGHT_BUTTON] {
        let id = live_ids(&s, object)[0];
        assert_eq!((s.instances[&id].fields["x"], s.instances[&id].fields["y"]), (sx, sy),
            "CODE {code}: obj {object} sits on the body's own spot");
    }

    assert_eq!(s.globals["roomstart"], 0.0, "CODE {code}: lowers global.roomstart");
    // Both orderings of (lloyd Destroy CODE 671, button Create CODE 528) end in
    // the same place: each of the two is a bare mouse_clear(mb_any).
    assert!(s.touch_devices.iter().all(|d| !d.down && !d.pressed && !d.released),
        "CODE {code}: the held pointer is cleared either way");
}

#[test]
fn lloyd_sheet_destroy_bodies_land_their_own_save_flag_and_furniture() {
    let b = bundle();
    for (code, object, flag, stops, resumes, _buttons_first) in LLOYD_TUTORIAL_DESTROY {
        // Two lloyds: the with-body is a per-instance loop, not a single pick.
        sheet_destroy_run(&b, code, object, flag, stops, resumes, 2);
        // …and the same body with an empty selection still balances its
        // environment stack (dispatch returns Ok) and lands everything else.
        sheet_destroy_run(&b, code, object, flag, stops, resumes, 0);
    }
}

// ---------------------------------------------------------------------------
// The intro banners
// ---------------------------------------------------------------------------

/// obj_boss1intro's Create and the three retirement alarms. The Create of the
/// two driving sheets (obj_bearcubintro CODE 721, obj_boss6intro CODE 778) is
/// byte-identical to CODE 739's shape, so it is only used as the driver here.
const INTROS: [(usize, usize, i32); 3] = [
    // CODE 739 Create + CODE 740 Alarm_0 — obj_boss1intro
    (739, 740, BOSS1INTRO),
    // CODE 722 Alarm_0 — obj_bearcubintro (driver Create: CODE 721)
    (721, 722, BEARCUBINTRO),
    // CODE 779 Alarm_0 — obj_boss6intro (driver Create: CODE 778)
    (778, 779, BOSS6INTRO),
];

#[test]
fn intro_banner_alarm_bodies_retire_their_own_banner_on_the_armed_timer() {
    let b = bundle();
    for (create, alarm_code, object) in INTROS {
        let mut s = scene(&b);
        s.globals.insert("soundmute".into(), 0.0);
        s.audio.clear();
        let banner = s.create(&b, object, 500.0, 300.0).expect("banner Create");

        // CODE 739: the fanfare goes through the soundmute gate with priority 0
        // and looping off.
        let fanfare = s.audio.iter().find(|c| c.sound == SND_MEETNEWENEMY);
        if create == 739 {
            let fanfare = fanfare.expect("CODE 739: snd_meetnewenemy plays when soundmute == 0");
            assert_eq!((fanfare.priority, fanfare.looping), (0.0, false),
                "// CODE 739: audio_play_sound(snd_meetnewenemy, 0, false)");
            assert_eq!(s.instances[&banner].alarms[0], 60, "// CODE 739: alarm[0] = 60");
            // The two flanking lines at the body's own offsets.
            let left = live_ids(&s, LINELEFT);
            let right = live_ids(&s, LINERIGHT);
            assert_eq!(left.len(), 1, "// CODE 739: one obj_lineleft");
            assert_eq!(right.len(), 1, "// CODE 739: one obj_lineright");
            assert_eq!((s.instances[&left[0]].fields["x"], s.instances[&left[0]].fields["y"]),
                (820.0, 270.0), "// CODE 739: obj_lineleft at (x + 320, y - 30)");
            assert_eq!((s.instances[&right[0]].fields["x"], s.instances[&right[0]].fields["y"]),
                (180.0, 295.0), "// CODE 739: obj_lineright at (x - 320, y - 5)");
            // Nothing else was created by this body.
            assert_eq!(s.instances.values().filter(|i| i.alive).count(), 3,
                "// CODE 739: Create spawns the banner plus exactly two lines");
        } else {
            assert!(fanfare.is_some(), "CODE {create}: the driving Create cues the fanfare too");
            assert_eq!(s.instances[&banner].alarms[0], 60,
                "CODE {create}: the driving Create arms the same 60-tick retirement");
        }

        // The alarm path: no poking. 60 ticks down, the 60th tick fires Alarm_0.
        for _ in 0..59 {
            s.tick(&b).expect("tick");
        }
        assert!(alive(&s, banner), "// CODE {alarm_code}: still on screen at tick 59");
        assert!(live_ids(&s, LINELEFT).len() == 1 && live_ids(&s, LINERIGHT).len() == 1,
            "// CODE {alarm_code}: the 89-tick lines outlive the banner");
        s.tick(&b).expect("tick");
        assert!(!alive(&s, banner),
            "// CODE {alarm_code}: instance_destroy() on the tick the Create armed (60)");
    }
}

#[test]
fn intro_create_respects_soundmute() {
    let b = bundle();
    // CODE 739's `if (soundmute == 1) {} else if (soundmute == 0) { play }`.
    let mut s = scene(&b);
    s.globals.insert("soundmute".into(), 1.0);
    s.audio.clear();
    let banner = s.create(&b, BOSS1INTRO, 500.0, 300.0).expect("muted banner Create");
    assert!(s.audio.iter().all(|c| c.sound != SND_MEETNEWENEMY),
        "// CODE 739: soundmute == 1 suppresses the fanfare");
    // The rest of the body runs regardless of the gate.
    assert_eq!(s.instances[&banner].alarms[0], 60, "// CODE 739: the alarm is armed anyway");
    assert_eq!(live_ids(&s, LINELEFT).len(), 1, "// CODE 739: the lines spawn anyway");
    assert_eq!(live_ids(&s, LINERIGHT).len(), 1, "// CODE 739: the lines spawn anyway");
}

// ---------------------------------------------------------------------------
// Store dialogs and page switches
// ---------------------------------------------------------------------------

#[test]
fn store_page_switch_bodies_swap_the_pause_menu_at_their_own_spot() {
    let b = bundle();

    // CODE 489 (obj_storepageswitch Mouse_7): with (obj_pause) kills the live
    // page-1 menu and puts a page-2 menu on this button's own spot. A second
    // page-2 menu already on screen belongs to nobody and stays.
    let mut s = scene(&b);
    let p1 = raw(&mut s, 900_500, PAUSE, 10.0, 10.0);
    let p2 = raw(&mut s, 900_501, PAUSE, 20.0, 20.0);
    let parked = raw(&mut s, 900_502, PAUSE, 30.0, 30.0);
    s.instances.get_mut(&parked).unwrap().active = false;
    let page2 = raw(&mut s, 900_503, PAUSE2, 40.0, 40.0);
    let sw = raw(&mut s, 900_504, STOREPAGESWITCH, 50.0, 60.0);
    s.dispatch(&b, sw, 6, 7).expect("// CODE 489 page switch");
    assert!(!alive(&s, p1) && !alive(&s, p2),
        "// CODE 489: with (obj_pause) retires every live page-1 menu");
    assert!(alive(&s, parked),
        "// CODE 489: a deactivated obj_pause is not in the with-selection");
    assert!(alive(&s, page2), "// CODE 489: the page-2 menu already up is untouched");
    assert_eq!(live_ids(&s, PAUSE), vec![parked],
        "// CODE 489: the only obj_pause left is the deactivated one the with-selection skipped");
    let new_page2: Vec<i32> = live_ids(&s, PAUSE2).into_iter().filter(|id| *id != page2).collect();
    assert_eq!(new_page2.len(), 1, "// CODE 489: one obj_pause2 replaces it");
    assert_eq!((s.instances[&new_page2[0]].fields["x"], s.instances[&new_page2[0]].fields["y"]),
        (50.0, 60.0), "// CODE 489: instance_create(x, y, obj_pause2) on the button's spot");

    // …and with no page-1 menu at all the with-selection is empty: the body
    // still creates the page-2 menu and the environment stack still balances.
    let mut s = scene(&b);
    let sw = raw(&mut s, 900_505, STOREPAGESWITCH, 70.0, 80.0);
    s.dispatch(&b, sw, 6, 7).expect("// CODE 489 empty with-selection");
    assert_eq!(count(&s, PAUSE2), 1, "// CODE 489: the button still creates its page-2 menu");
    assert_eq!(s.instances[&live_ids(&s, PAUSE2)[0]].fields["x"], 70.0,
        "// CODE 489: at the switch's own x");

    // CODE 492 (obj_storepageswitch2 Mouse_7): the mirror image.
    let mut s = scene(&b);
    let q1 = raw(&mut s, 900_510, PAUSE2, 10.0, 10.0);
    let q2 = raw(&mut s, 900_511, PAUSE2, 20.0, 20.0);
    let page1 = raw(&mut s, 900_512, PAUSE, 30.0, 30.0);
    let sw2 = raw(&mut s, 900_513, STOREPAGESWITCH2, 70.0, 80.0);
    s.dispatch(&b, sw2, 6, 7).expect("// CODE 492 page switch");
    assert!(!alive(&s, q1) && !alive(&s, q2),
        "// CODE 492: with (obj_pause2) retires every live page-2 menu");
    assert!(alive(&s, page1), "// CODE 492: the page-1 menu already up is untouched");
    assert_eq!(count(&s, PAUSE2), 0, "// CODE 492: no live obj_pause2 is left");
    let new_page1: Vec<i32> = live_ids(&s, PAUSE).into_iter().filter(|id| *id != page1).collect();
    assert_eq!(new_page1.len(), 1, "// CODE 492: one obj_pause replaces it");
    assert_eq!((s.instances[&new_page1[0]].fields["x"], s.instances[&new_page1[0]].fields["y"]),
        (70.0, 80.0), "// CODE 492: instance_create(x, y, obj_pause) on the button's spot");
}

#[test]
fn norestoredata_click_guards_every_with_and_consumes_itself() {
    let b = bundle();

    // CODE 481 (obj_norestoredata Mouse_7): cancel the erase-data dialog. Each
    // with-block sits behind an instance_exists guard, and the body then
    // destroys itself (its own Destroy, CODE 480, restores the pause menu).
    let mut s = scene(&b);
    let ays = raw(&mut s, 900_400, AREYOUSURE, 0.0, 0.0);
    let yes = raw(&mut s, 900_401, YESRESTOREDATA, 0.0, 0.0);
    let no = raw(&mut s, 900_402, NORESTOREDATA, 7.0, 8.0);
    let keep = raw(&mut s, 900_403, RESTOREIAP, 0.0, 0.0);
    s.dispatch(&b, no, 6, 7).expect("// CODE 481 cancel click");
    assert!(!alive(&s, ays), "// CODE 481: the Erase-Data? dialog is destroyed");
    assert!(!alive(&s, yes), "// CODE 481: the Yes button is destroyed");
    assert!(!alive(&s, no), "// CODE 481: the body destroys itself");
    assert_eq!(count(&s, NORESTOREDATA), 0, "// CODE 481: no no-button is left");
    assert!(alive(&s, keep), "// CODE 481: an object the body does not name is untouched");
    // The self-destroy ran CODE 480 at the instance's own spot.
    assert_eq!(count(&s, FIRSTPAUSE), 1, "// CODE 481: the self-destroy restores a pause menu");
    assert_eq!((s.instances[&live_ids(&s, FIRSTPAUSE)[0]].fields["x"],
                s.instances[&live_ids(&s, FIRSTPAUSE)[0]].fields["y"]), (7.0, 8.0),
        "// CODE 481: at its own (x, y)");

    // The guards' false branch: no dialog at all. Nothing is touched, no error,
    // and the object it does not name survives.
    let mut s = scene(&b);
    let keep = raw(&mut s, 900_404, RESTOREIAP, 0.0, 0.0);
    let no = raw(&mut s, 900_405, NORESTOREDATA, 1.0, 2.0);
    s.dispatch(&b, no, 6, 7).expect("// CODE 481 with every dialog absent");
    assert!(!alive(&s, no), "// CODE 481: the no-button still consumes itself");
    assert!(alive(&s, keep), "// CODE 481: the unrelated object survives");
    assert_eq!(count(&s, AREYOUSURE) + count(&s, YESRESTOREDATA), 0,
        "// CODE 481: nothing else was created");
}

#[test]
fn iapmenu_destroy_clears_the_iap_triad() {
    let b = bundle();

    // CODE 499 (obj_iapmenu Destroy_0): three guarded with-blocks - its own
    // object, obj_poisoniap and obj_restoreiap.
    let mut s = scene(&b);
    let m1 = raw(&mut s, 900_600, IAPMENU, 1.0, 1.0);
    let m2 = raw(&mut s, 900_601, IAPMENU, 2.0, 2.0);
    let poi = raw(&mut s, 900_602, POISONIAP, 3.0, 3.0);
    let rst = raw(&mut s, 900_603, RESTOREIAP, 4.0, 4.0);
    let parked = raw(&mut s, 900_604, RESTOREIAP, 5.0, 5.0);
    s.instances.get_mut(&parked).unwrap().active = false;
    let keep = raw(&mut s, 900_605, YESRESTOREDATA, 6.0, 6.0);
    s.dispatch(&b, m1, 1, 0).expect("// CODE 499 iapmenu Destroy");
    assert!(!alive(&s, m1) && !alive(&s, m2),
        "// CODE 499: with (obj_iapmenu) retires every one, this instance included");
    assert!(!alive(&s, poi), "// CODE 499: with (obj_poisoniap) retires the poison entry");
    assert!(!alive(&s, rst), "// CODE 499: with (obj_restoreiap) retires the restore entry");
    assert!(alive(&s, parked),
        "// CODE 499: a deactivated obj_restoreiap is not in the with-selection");
    assert!(alive(&s, keep), "// CODE 499: the erase-data dialog is not in any of the lists");
    assert_eq!(count(&s, IAPMENU), 0, "// CODE 499: no live obj_iapmenu is left");
    assert_eq!(count(&s, POISONIAP), 0, "// CODE 499: no live obj_poisoniap is left");
    assert_eq!(live_ids(&s, RESTOREIAP), vec![parked],
        "// CODE 499: the only obj_restoreiap left is the deactivated one the guard skipped");

    // The two other guards' false branch: a lone iapmenu dies, nothing else.
    let mut s = scene(&b);
    let solo = raw(&mut s, 900_606, IAPMENU, 9.0, 9.0);
    let keep = raw(&mut s, 900_607, YESRESTOREDATA, 0.0, 0.0);
    s.dispatch(&b, solo, 1, 0).expect("// CODE 499 with the other two absent");
    assert!(!alive(&s, solo), "// CODE 499: the lone iapmenu still goes");
    assert!(alive(&s, keep), "// CODE 499: unrelated objects are untouched");
}

/// The furniture list each pause Destroy sweeps, transcribed from the recovered
/// GML (0508/0513). CODE 508 names obj_healthrefill twice - two separate blocks
/// - so the list keeps both entries.
const PAUSE_PAGE1: [i32; 13] = [
    HEALTHREFILL, COINMULTIPLIER2, TRIPLEJUMP, POWERUPGRADE, SWORDUPGRADE,
    STRENGTHUPGRADE, SWORDUPGRADE2, HEALTHREGEN, HEALTHREFILL, VOLUME,
    VOLUMEMUSIC, STORE, FIRSTPAUSE,
];
const PAUSE_PAGE2: [i32; 13] = [
    MAXHPUPGRADE, MAXHPUPGRADE2, COINMULTIPLIER5, POWERUPGRADE2,
    ENERGYWAVEUPGRADE, POWERUPGRADE3, SWORDUPGRADE3, STRENGTHUPGRADE2, VOLUME,
    VOLUMEMUSIC, STORE, FIRSTPAUSE, STOREPAGESWITCH2,
];

fn pause_destroy_run(b: &Bundle, code: usize, object: i32, list: &[i32], others: &[i32]) {
    let mut s = scene(b);
    s.globals.insert("storemenu".into(), 1.0);
    let mut seeds = Vec::new();
    for (n, obj) in list.iter().enumerate() {
        seeds.push(raw(&mut s, 900_700 + n as i32, *obj, n as f64, n as f64));
    }
    let mut controls = Vec::new();
    for (n, obj) in others.iter().enumerate() {
        controls.push(raw(&mut s, 900_800 + n as i32, *obj, n as f64, n as f64));
    }
    let menu = raw(&mut s, 900_799, object, 0.0, 0.0);
    s.dispatch(b, menu, 1, 0).unwrap_or_else(|e| panic!("CODE {code} Destroy: {e}"));
    assert_eq!(s.globals["storemenu"], 0.0, "CODE {code}: lowers global.storemenu");
    for (n, obj) in list.iter().enumerate() {
        assert!(!alive(&s, seeds[n]), "CODE {code}: obj {obj} at slot {n} is swept");
    }
    for (n, obj) in others.iter().enumerate() {
        assert!(alive(&s, controls[n]),
            "CODE {code}: obj {obj} is not in this body's list and survives");
    }
}

#[test]
fn pause_destroy_bodies_clear_exactly_their_own_page() {
    let b = bundle();
    // CODE 508 (obj_pause Destroy): page 1's furniture. The page-2 upgrades are
    // not in its list.
    pause_destroy_run(&b, 508, PAUSE, &PAUSE_PAGE1, &[MAXHPUPGRADE, MAXHPUPGRADE2, COINMULTIPLIER5, STOREPAGESWITCH2, IAPMENU]);
    // CODE 513 (obj_pause2 Destroy): page 2's furniture - a different list. The
    // page-1 entries are not in it.
    pause_destroy_run(&b, 513, PAUSE2, &PAUSE_PAGE2, &[HEALTHREFILL, HEALTHREGEN, COINMULTIPLIER2, IAPMENU]);
}

// ---------------------------------------------------------------------------
// The erase-data wipe
// ---------------------------------------------------------------------------

/// Every `global.<name> = <value>;` line of the recovered GML for CODE 478 -
/// 288 distinct names, last write wins - transcribed mechanically from
/// `0478__gml_Object_obj_yesrestoredata_Mouse_7.gml`.
const WIPE_GLOBALS: [(&str, f64); 288] = [
    ("talkedtolloyd1", 0.0), ("talkedtolloyd2", 0.0), ("talkedtolloyd3", 0.0), ("talkedtolloyd4", 0.0), ("talkedtolloyd5", 0.0), ("talkedtolloyd6", 0.0),
    ("talkedtolloyd7", 0.0), ("talkedtolloyd8", 0.0), ("talkedtolloyd9", 0.0), ("talkedtolloyd10", 0.0), ("talkedtolloyd11", 0.0), ("talkedtolloyd12", 0.0),
    ("talkedtolloyd13", 0.0), ("talkedtolloyd14", 0.0), ("talkedtolloyd15", 0.0), ("coinmultiply", 1.0), ("timeplayed", 0.0), ("gemdropenabled", 1.0),
    ("poisonenabled", 0.0), ("weaponswapped", 0.0), ("haskey", 1.0), ("level", 1.0), ("maxhp", 4.0), ("xptolevelup", 30.0),
    ("health1", 4.0), ("boss1dead", 0.0), ("boss2dead", 0.0), ("boss3dead", 0.0), ("boss4dead", 0.0), ("boss5dead", 0.0),
    ("boss6dead", 0.0), ("strengthupgradebought", 0.0), ("strengthupgrade2bought", 0.0), ("energywavebought", 0.0), ("healthregenbought", 0.0), ("swordupgradebought", 0.0),
    ("swordupgrade2bought", 0.0), ("swordupgrade3bought", 0.0), ("pistolbought", 1.0), ("spikegunbought", 0.0), ("boomerangbought", 0.0), ("shotgunbought", 0.0),
    ("powerupgradebought", 0.0), ("powerupgrade2bought", 0.0), ("powerupgrade3bought", 0.0), ("bladegunbought", 0.0), ("flamethrowerbought", 0.0), ("bowbought", 0.0),
    ("assaultriflebought", 0.0), ("rocketbought", 0.0), ("laserbought", 0.0), ("icegunbought", 0.0), ("bombgunbought", 0.0), ("bombgunxp", 0.0),
    ("bombgunxptolevelup", 50.0), ("bombgunlevel", 1.0), ("sword", 0.0), ("triplejumpbought", 0.0), ("tjumpactive", 0.0), ("coinmultiplier2bought", 0.0),
    ("coinmultiplier5bought", 0.0), ("maxhpupgradebought", 0.0), ("maxhpupgrade2bought", 0.0), ("experience", 1.0), ("drawchange", 0.0), ("drawlevelup", 0.0),
    ("drawweaponlevelup", 0.0), ("drawweaponchange", 0.0), ("drawchangepistol4", 1.0), ("drawchangeshotgun4", 1.0), ("drawchangeassaultrifle4", 1.0), ("drawchangerocket4", 1.0),
    ("drawchangelaser4", 1.0), ("drawchangeicegun4", 1.0), ("drawchangebow4", 1.0), ("drawchangebladegun4", 1.0), ("drawchangeflamethrower4", 1.0), ("drawchangeboomerang4", 1.0),
    ("drawchangespikegun4", 1.0), ("drawchangebombgun4", 1.0), ("drawchangepistol7", 1.0), ("drawchangeshotgun7", 1.0), ("drawchangeassaultrifle7", 1.0), ("drawchangerocket7", 1.0),
    ("drawchangelaser7", 1.0), ("drawchangeicegun7", 1.0), ("drawchangebow7", 1.0), ("drawchangebladegun7", 1.0), ("drawchangeflamethrower7", 1.0), ("drawchangeboomerang7", 1.0),
    ("drawchangespikegun7", 1.0), ("drawchangebombgun7", 1.0), ("drawchangepistol10", 1.0), ("drawchangeshotgun10", 1.0), ("drawchangeassaultrifle10", 1.0), ("drawchangerocket10", 1.0),
    ("drawchangelaser10", 1.0), ("drawchangeicegun10", 1.0), ("drawchangebow10", 1.0), ("drawchangebladegun10", 1.0), ("drawchangeflamethrower10", 1.0), ("drawchangeboomerang10", 1.0),
    ("drawchangespikegun10", 1.0), ("drawchangebombgun10", 1.0), ("bearskilled", 0.0), ("knifebanditskilled", 0.0), ("pistolthugskilled", 0.0), ("wolfkilled", 0.0),
    ("chomperbotkilled", 0.0), ("greenslimeskilled", 0.0), ("fireslimeskilled", 0.0), ("hulkingbanditskilled", 0.0), ("ghostskilled", 0.0), ("skeletonskilled", 0.0),
    ("zombieskilled", 0.0), ("firehulkskilled", 0.0), ("batskilled", 0.0), ("trapskilled", 0.0), ("enemieskilled", 0.0), ("boughtallguns", 0.0),
    ("triplejumpachievement", 0.0), ("boughtallupgrades", 0.0), ("boughteverything", 0.0), ("achievemaxhp", 0.0), ("getmoney", 0.0), ("hitmaxlevel", 0.0),
    ("bladegunxp", 0.0), ("bladegunxptolevelup", 175.0), ("flamethrowerxp", 0.0), ("flamethrowerxptolevelup", 200.0), ("bowxp", 0.0), ("bowxptolevelup", 125.0),
    ("pistolxp", 0.0), ("pistolxptolevelup", 50.0), ("shotgunxp", 0.0), ("shotgunxptolevelup", 125.0), ("assaultriflexp", 0.0), ("assaultriflexptolevelup", 175.0),
    ("rocketxp", 0.0), ("rocketxptolevelup", 200.0), ("laserxp", 0.0), ("laserxptolevelup", 100.0), ("icegunxp", 0.0), ("icegunxptolevelup", 75.0),
    ("pistollevel", 1.0), ("shotgunlevel", 1.0), ("assaultriflelevel", 1.0), ("grenadelevel", 1.0), ("rocketlevel", 1.0), ("laserlevel", 1.0),
    ("icegunlevel", 1.0), ("scattergunlevel", 1.0), ("bowlevel", 1.0), ("bladegunlevel", 1.0), ("flamethrowerlevel", 1.0), ("boomerangxp", 0.0),
    ("boomeranglevel", 1.0), ("boomerangxptolevelup", 150.0), ("spikegunxp", 0.0), ("spikegunlevel", 1.0), ("spikegunxptolevelup", 100.0), ("roomtownvisited", 1.0),
    ("level1visited", 0.0), ("level2visited", 0.0), ("level3visited", 0.0), ("level4visited", 0.0), ("level5visited", 0.0), ("level6visited", 0.0),
    ("level7visited", 0.0), ("level8visited", 0.0), ("level8avisited", 0.0), ("boss1visited", 0.0), ("level9visited", 0.0), ("level9avisited", 0.0),
    ("level10visited", 0.0), ("level11visited", 0.0), ("level11avisited", 0.0), ("level12visited", 0.0), ("level13visited", 0.0), ("level13avisited", 0.0),
    ("level14visited", 0.0), ("level14avisited", 0.0), ("level15visited", 0.0), ("level15avisited", 0.0), ("level16visited", 0.0), ("level16avisited", 0.0),
    ("level17visited", 0.0), ("level17avisited", 0.0), ("boss2visited", 0.0), ("room31visited", 0.0), ("room32visited", 0.0), ("room33visited", 0.0),
    ("room34visited", 0.0), ("room35visited", 0.0), ("room36visited", 0.0), ("room37visited", 0.0), ("room38visited", 0.0), ("room39visited", 0.0),
    ("room40visited", 0.0), ("room41visited", 0.0), ("room42visited", 0.0), ("room43visited", 0.0), ("room44visited", 0.0), ("room45visited", 0.0),
    ("room46visited", 0.0), ("room47visited", 0.0), ("room48visited", 0.0), ("room49visited", 0.0), ("room50visited", 0.0), ("boss3visited", 0.0),
    ("room51visited", 0.0), ("room52visited", 0.0), ("room53visited", 0.0), ("room54visited", 0.0), ("room55visited", 0.0), ("room56visited", 0.0),
    ("room57visited", 0.0), ("room58visited", 0.0), ("room59visited", 0.0), ("room60visited", 0.0), ("room61visited", 0.0), ("room62visited", 0.0),
    ("room63visited", 0.0), ("room64visited", 0.0), ("room65visited", 0.0), ("boss4visited", 0.0), ("room66visited", 0.0), ("room67visited", 0.0),
    ("room68visited", 0.0), ("room69visited", 0.0), ("room70visited", 0.0), ("room71visited", 0.0), ("room72visited", 0.0), ("room73visited", 0.0),
    ("room74visited", 0.0), ("room75visited", 0.0), ("room76visited", 0.0), ("room77visited", 0.0), ("room78visited", 0.0), ("room79visited", 0.0),
    ("room80visited", 0.0), ("room81visited", 0.0), ("room82visited", 0.0), ("boss5visited", 0.0), ("room83visited", 0.0), ("room84visited", 0.0),
    ("room85visited", 0.0), ("room86visited", 0.0), ("room87visited", 0.0), ("room88visited", 0.0), ("room89visited", 0.0), ("room90visited", 0.0),
    ("room91visited", 0.0), ("room92visited", 0.0), ("room93visited", 0.0), ("room94visited", 0.0), ("room95visited", 0.0), ("room96visited", 0.0),
    ("room97visited", 0.0), ("room98visited", 0.0), ("room99visited", 0.0), ("room100visited", 0.0), ("room101visited", 0.0), ("room102visited", 0.0),
    ("room103visited", 0.0), ("boss6visited", 0.0), ("soundmute", 0.0), ("musicmute", 0.0), ("beartouched", 0.0), ("knifetouched", 0.0),
    ("spidertouched", 0.0), ("battouched", 0.0), ("wolftouched", 0.0), ("pistolbandittouched", 0.0), ("boss1touched", 0.0), ("turrettouched", 0.0),
    ("slimetouched", 0.0), ("boss2touched", 0.0), ("zombietouched", 0.0), ("redslimetouched", 0.0), ("skeletontouched", 0.0), ("hulkingbandittouched", 0.0),
    ("beetouched", 0.0), ("boss3touched", 0.0), ("firehulktouched", 0.0), ("boss4touched", 0.0), ("boss5touched", 0.0), ("boss6touched", 0.0),
];

/// A spot-checked subset of the ini rows CODE 478 rewrites after the wipe
/// (`ini_write_real("Save", k, v)`), covering the versioned names, the level
/// header and the mute flags.
const WIPE_INI_KEYS: [(&str, f64); 6] = [
    ("talkedtolloyd1", 0.0), ("talkedtolloyd15", 0.0), ("current_level", 1.0),
    ("current_maxhp", 4.0), ("boss6dead", 0.0), ("musicmute", 0.0),
];

#[test]
fn yesrestoredata_wipe_lands_the_full_global_reset() {
    let b = bundle();

    // CODE 478 (obj_yesrestoredata Mouse_7): the erase-everything confirmation.
    // Only the dispatcher and the persistent player exist, so the body's 15
    // guarded with-blocks all take their "absent" branch: the globals below are
    // this body's own writes, not a second-order Destroy body's.
    let mut s = scene(&b);
    let player = raw(&mut s, 900_100, PLAYER, 100.0, 100.0);
    let yes = raw(&mut s, 900_101, YESRESTOREDATA, 300.0, 400.0);
    s.ini_data.insert(("filesave.ini".into(), "Save".into(), "stale".into()), 7.0);
    s.ini_data.insert(("savefile.ini".into(), "Save".into(), "old".into()), 9.0);
    s.score = 4242.0;
    s.dispatch(&b, yes, 6, 7).expect("// CODE 478 erase-data wipe");

    for (name, value) in WIPE_GLOBALS {
        assert_eq!(s.globals.get(name).copied(), Some(value),
            "// CODE 478: global.{name} = {value}");
    }
    assert_eq!(s.score, 100.0, "// CODE 478: score = 100");

    // ini: the wipe deletes filesave.ini (its own rows included) and rewrites
    // savefile.ini's [Save] block.
    assert!(!s.ini_data.keys().any(|(f, _, _)| f == "filesave.ini"),
        "// CODE 478: file_delete(\"filesave.ini\") drops its rows");
    assert_eq!(s.ini_data.get(&("savefile.ini".into(), "Save".into(), "old".into())).copied(),
        Some(9.0), "// CODE 478: savefile.ini rows the body does not write are kept");
    for (key, value) in WIPE_INI_KEYS {
        assert_eq!(
            s.ini_data.get(&("savefile.ini".to_string(), "Save".to_string(), key.to_string())).copied(),
            Some(value),
            "// CODE 478: [Save] {key} = {value} in savefile.ini");
    }

    // room_goto(rm_town), instance_activate_all and the player parked at spawn.
    assert_eq!(s.target_room_warp, Some(RM_TOWN), "// CODE 478: room_goto(rm_town)");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (416.0, 352.0),
        "// CODE 478: obj_player.x = 416; obj_player.y = 352");
    assert!(s.instances.values().filter(|i| i.alive && !i.active).count() == 0,
        "// CODE 478: instance_activate_all leaves nothing frozen");

    // The dispatcher names its own object in the with-list, so it retires itself.
    assert!(!alive(&s, yes), "// CODE 478: with (obj_yesrestoredata) destroys the button itself");
    assert_eq!(count(&s, YESRESTOREDATA), 0, "// CODE 478: no dialog instance is left");

    // obj_music was absent: the body re-creates it at its own spot.
    assert_eq!(count(&s, MUSIC), 1, "// CODE 478: instance_create(x, y, obj_music)");
    let music = live_ids(&s, MUSIC)[0];
    assert_eq!((s.instances[&music].fields["x"], s.instances[&music].fields["y"]), (300.0, 400.0),
        "// CODE 478: the music object lands on the body's own (x, y)");

    // A second run over a scene that already has obj_music: the guard holds and
    // no second music object appears.
    let mut s = scene(&b);
    raw(&mut s, 900_102, PLAYER, 0.0, 0.0);
    let existing = raw(&mut s, 900_103, MUSIC, 1.0, 2.0);
    let yes = raw(&mut s, 900_104, YESRESTOREDATA, 0.0, 0.0);
    s.dispatch(&b, yes, 6, 7).expect("// CODE 478 wipe with obj_music already present");
    assert_eq!(count(&s, MUSIC), 1, "// CODE 478: the music guard skips a second create");
    assert_eq!(s.instances[&existing].fields["x"], 1.0,
        "// CODE 478: the existing obj_music is not moved");
}

/// The 15 objects CODE 478's guarded with-blocks name, in the order the GML
/// lists them, plus two instances no list in the reachable destroy chain names.
const WIPE_TARGETS: [i32; 15] = [
    HEALTHREFILL, RESTOREDATA, PAUSE, STORE, VOLUME, VOLUMEMUSIC, FIRSTPAUSE,
    BACKTOGAME, STOREPAGESWITCH, PAUSE2, IAPMENU, POISONIAP, AREYOUSURE,
    YESRESTOREDATA, NORESTOREDATA,
];

#[test]
fn yesrestoredata_wipe_clears_every_named_dialog_and_spares_the_rest() {
    let b = bundle();
    let mut s = scene(&b);
    let player = raw(&mut s, 900_150, PLAYER, 0.0, 0.0);
    let mut seeded = Vec::new();
    for (n, obj) in WIPE_TARGETS.iter().enumerate() {
        seeded.push(raw(&mut s, 900_200 + n as i32, *obj, n as f64, 0.0));
    }
    // Controls: objects that neither CODE 478 nor the Destroy bodies it wakes
    // (obj_norestoredata 480, obj_firstpause 495, obj_pause 508, obj_pause2 513,
    // obj_iapmenu 499) ever name.
    let button = raw(&mut s, 900_300, PAUSEBUTTON, 0.0, 0.0);
    let shoot = raw(&mut s, 900_301, SHOOTBUTTON, 0.0, 0.0);

    let yes = seeded[WIPE_TARGETS.iter().position(|o| *o == YESRESTOREDATA).unwrap()];
    s.dispatch(&b, yes, 6, 7).expect("// CODE 478 wipe over the full dialog set");

    for (n, obj) in WIPE_TARGETS.iter().enumerate() {
        assert!(!alive(&s, seeded[n]),
            "// CODE 478: the with (obj {obj}) block retires the instance it selected");
    }
    // Objects the body names that nothing in the reachable chain re-creates:
    // no live instance of any of them may survive the sweep.
    for (obj, name) in [
        (HEALTHREFILL, "obj_healthrefill"), (PAUSE, "obj_pause"), (PAUSE2, "obj_pause2"),
        (STOREPAGESWITCH, "obj_storepageswitch"), (AREYOUSURE, "obj_areyousure"),
        (IAPMENU, "obj_iapmenu"), (POISONIAP, "obj_poisoniap"),
        (NORESTOREDATA, "obj_norestoredata"), (YESRESTOREDATA, "obj_yesrestoredata"),
    ] {
        assert_eq!(count(&s, obj), 0, "// CODE 478: no live {name} is left");
    }
    // The sweep is not the end of the chain: destroying obj_norestoredata runs
    // its own Destroy (CODE 480), which re-creates obj_firstpause, whose Create
    // (CODE 494, view_current == 0) in turn re-creates the store furniture and
    // the erase entry. Those second-order instances are the reason the counts
    // below are not zero.
    for (obj, name) in [
        (FIRSTPAUSE, "obj_firstpause"), (RESTOREDATA, "obj_restoredata"),
        (STORE, "obj_store"), (VOLUME, "obj_volume"),
        (VOLUMEMUSIC, "obj_volumemusic"), (BACKTOGAME, "obj_backtogame"),
    ] {
        assert_eq!(count(&s, obj), 1,
            "// CODE 478: CODE 480/494 re-create exactly one {name} after the sweep");
    }
    assert!(alive(&s, player), "// CODE 478: the player is not in any list");
    assert!(alive(&s, button) && alive(&s, shoot),
        "// CODE 478: instances outside the named lists are untouched");
}
