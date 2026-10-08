//! The store sweep: the nine purchase clicks (Mouse_0) with their gates, the
//! dialog/page UI (Mouse_7/4/3), the eight store Draw bodies and the three
//! Destroy cleanups. Purchases: below-price and already-bought must change
//! nothing; at price they deduct and apply their globals. The data wipe
//! (yesrestoredata) resets the whole fresh-start baseline; file_delete is a
//! no-op without a disk directory.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const COINMULTIPLIER5: i32 = 95;
const ENERGYWAVEUPGRADE: i32 = 91;
const MAXHPUPGRADE2: i32 = 98;
const POWERUPGRADE3: i32 = 86;
const STRENGTHUPGRADE2: i32 = 94;
const SWORDUPGRADE3: i32 = 90;
const COINMULTIPLIER2: i32 = 96;
const HEALTHREGEN: i32 = 92;
const POWERUPGRADE2: i32 = 85;
const SWORDUPGRADE: i32 = 88;
const PAUSE: i32 = 122;
const PAUSE2: i32 = 123;
const FIRSTPAUSE: i32 = 118;
const NORESTOREDATA: i32 = 113;
const IAPMENU: i32 = 119;
const STOREPAGESWITCH: i32 = 116;
const STOREPAGESWITCH2: i32 = 117;
const POISONIAP: i32 = 120;
const RESTOREDATA: i32 = 115;
const YESRESTOREDATA: i32 = 112;
const RESTOREIAP: i32 = 121;
const VOLUME: i32 = 107;
const VOLUMEMUSIC: i32 = 109;
const SHOOTBUTTON: i32 = 128;
const PAUSEBUTTON: i32 = 125;
const STORE: i32 = 110;
const BACKTOGAME: i32 = 108;
const AREYOUSURE: i32 = 114;
const SND_COIN: i32 = 19;
const SND_ASSAULTRIFLE: i32 = 9;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.globals.insert("timespaused".into(), 0.0);
    s
}

fn count(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|x| x.object == object && x.alive).count()
}

#[test]
fn store_purchases_gate_and_apply() {
    let b = bundle();
    let table: [(i32, f64, &[(&str, f64)]); 8] = [
        (COINMULTIPLIER5, 20000.0, &[("coinmultiply", 5.0), ("coinmultiplier5bought", 1.0)]),
        (ENERGYWAVEUPGRADE, 50000.0, &[("energywavebought", 1.0)]),
        (MAXHPUPGRADE2, 25000.0, &[("maxhpupgrade2bought", 1.0), ("level", 2.0)]),
        (POWERUPGRADE3, 35000.0, &[("pwr", 4.0), ("powerupgrade3bought", 1.0)]),
        (STRENGTHUPGRADE2, 20000.0, &[("strengthupgrade2bought", 1.0)]),
        (SWORDUPGRADE3, 15000.0, &[("swordupgrade3bought", 1.0), ("swordupgrade2bought", 1.0), ("swordupgradebought", 1.0), ("sword", 3.0)]),
        (COINMULTIPLIER2, 2000.0, &[("coinmultiply", 2.0), ("coinmultiplier2bought", 1.0)]),
        (HEALTHREGEN, 75000.0, &[("healthregenbought", 1.0)]),
    ];
    for (obj, price, effects) in table {
        // One coin short: nothing happens at all.
        let mut s = scene(&b);
        s.score = price - 1.0;
        let it = s.create(&b, obj, 0.0, 0.0).unwrap();
        s.dispatch(&b, it, 6, 0).expect("under-price click");
        assert_eq!(s.score, price - 1.0, "obj {obj}: score untouched");
        assert!(!s.audio.iter().any(|a| a.sound == SND_COIN), "obj {obj}: no chime");
        // At price: deduct + apply.
        let mut s = scene(&b);
        s.score = price;
        let it = s.create(&b, obj, 0.0, 0.0).unwrap();
        s.dispatch(&b, it, 6, 0).expect("purchase click");
        assert_eq!(s.score, 0.0, "obj {obj}: price deducted");
        for (g, v) in effects {
            assert_eq!(s.globals.get(*g).copied(), Some(*v), "obj {obj}: {g}");
        }
        if obj == MAXHPUPGRADE2 {
            assert_eq!(s.globals["health1"], s.globals["maxhp"], "hp refilled to the cap");
        }
        assert!(s.audio.iter().any(|a| a.sound == SND_COIN), "obj {obj}: chime");
        // The bought flag gates the repeat.
        s.score = 999999.0;
        s.dispatch(&b, it, 6, 0).expect("repeat click");
        assert_eq!(s.score, 999999.0, "obj {obj}: bought gates the repeat");
    }
}

#[test]
fn swordupgrade_guards_the_lower_tiers() {
    let b = bundle();
    for g in ["swordupgrade3bought", "swordupgrade2bought"] {
        let mut s = scene(&b);
        s.score = 3000.0;
        s.globals.insert(g.into(), 1.0);
        let it = s.create(&b, SWORDUPGRADE, 0.0, 0.0).unwrap();
        s.dispatch(&b, it, 6, 0).expect("guarded click");
        assert_eq!(s.score, 3000.0, "{g}: refuses the lower tier");
        assert_eq!(s.globals.get("swordupgradebought").copied(), Some(0.0));
    }
    let mut s = scene(&b);
    s.score = 3000.0;
    let it = s.create(&b, SWORDUPGRADE, 0.0, 0.0).unwrap();
    s.dispatch(&b, it, 6, 0).expect("clean purchase");
    assert_eq!(s.score, 0.0);
    assert_eq!(s.globals["sword"], 1.0);
}

#[test]
fn store_dialog_ui_reacts() {
    let b = bundle();
    let mut s = scene(&b);
    let pb = s.create(&b, PAUSEBUTTON, 0.0, 0.0).unwrap();
    s.dispatch(&b, pb, 6, 7).expect("pause tap");
    assert_eq!(s.globals["timespaused"], 1.0);
    assert_eq!(count(&s, FIRSTPAUSE), 1);
    // store: spawns obj_pause at obj_backtogame's (self-positioned) spot. The
    // object spawns a twin; park the extra so the GML selector reads ours.
    let bg = s.create(&b, BACKTOGAME, 30.0, 40.0).unwrap();
    for (id, i) in s.instances.iter_mut() {
        if i.object == BACKTOGAME && *id != bg {
            i.active = false;
        }
    }
    let bx = s.instances[&bg].fields["x"];
    let by = s.instances[&bg].fields["y"];
    let st = s.create(&b, STORE, 0.0, 0.0).unwrap();
    s.dispatch(&b, st, 6, 7).expect("store tap");
    let pz = s.instances.values().find(|i| i.object == PAUSE && i.alive).unwrap();
    assert_eq!(pz.fields["x"], bx);
    assert_eq!(pz.fields["y"], by);
    // page switches: pause <-> pause2.
    let p1 = s.create(&b, STOREPAGESWITCH, 0.0, 0.0).unwrap();
    s.dispatch(&b, p1, 6, 7).expect("switch to page2");
    assert!(s.instances.values().all(|i| i.object != PAUSE || !i.alive));
    assert_eq!(count(&s, PAUSE2), 1);
    let p2 = s.create(&b, STOREPAGESWITCH2, 0.0, 0.0).unwrap();
    s.dispatch(&b, p2, 6, 7).expect("switch back");
    assert!(s.instances.values().all(|i| i.object != PAUSE2 || !i.alive));
    assert_eq!(count(&s, PAUSE), 1);
    // restoredata -> areyousure + self consumed.
    let rd = s.create(&b, RESTOREDATA, 0.0, 0.0).unwrap();
    s.dispatch(&b, rd, 6, 7).expect("restore tap");
    assert_eq!(count(&s, AREYOUSURE), 1);
    assert!(!s.instances[&rd].alive);

    // yesrestoredata: the wipe resets the fresh-start baseline.
    let mut s = scene(&b);
    for (k, v) in [("level", 5.0), ("maxhp", 9.0), ("health1", 2.0), ("boss1dead", 1.0),
                   ("talkedtolloyd1", 5.0), ("gemdropenabled", 0.0)] {
        s.globals.insert(k.into(), v);
    }
    s.score = 9999.0;
    let pl = s.create(&b, P, 100.0, 100.0).unwrap();
    let yes = s.create(&b, YESRESTOREDATA, 0.0, 0.0).unwrap();
    s.dispatch(&b, yes, 6, 7).expect("wipe confirmed");
    assert_eq!(s.instances[&pl].fields["x"], 416.0, "the wipe parks the player at spawn");
    assert_eq!(s.instances[&pl].fields["y"], 352.0);
    assert_eq!(s.globals["level"], 1.0);
    assert_eq!(s.globals["maxhp"], 4.0);
    assert_eq!(s.globals["health1"], 4.0);
    assert_eq!(s.globals["boss1dead"], 0.0);
    assert_eq!(s.globals["talkedtolloyd1"], 0.0);
    assert_eq!(s.globals["gemdropenabled"], 1.0);
    assert_eq!(s.score, 100.0, "the wipe resets the score to 100");

    // norestoredata: cancels the dialogs; its Destroy brings the pause back.
    let mut s = scene(&b);
    let _ays = s.create(&b, AREYOUSURE, 0.0, 0.0).unwrap();
    let _yes = s.create(&b, YESRESTOREDATA, 0.0, 0.0).unwrap();
    let no = s.create(&b, NORESTOREDATA, 0.0, 0.0).unwrap();
    s.dispatch(&b, no, 6, 7).expect("cancel tap");
    assert_eq!(count(&s, AREYOUSURE), 0);
    assert_eq!(count(&s, YESRESTOREDATA), 0);
    assert_eq!(count(&s, NORESTOREDATA), 0);
    // The dialogs spawn in pairs; each no-copy's Destroy restores a pause.
    assert_eq!(count(&s, FIRSTPAUSE), 2, "the no-dialog restores the pause");
    // restoreiap: an empty click body.
    let rst = s.create(&b, RESTOREIAP, 0.0, 0.0).unwrap();
    s.dispatch(&b, rst, 6, 7).expect("empty restore tap");
    // poisoniap: with a purchase map wired in, the acquire branch runs.
    let map_id = s.call(&b, rst, "ds_map_create", &[]).unwrap();
    s.globals.insert("purchaseMap".into(), map_id);
    let poi = s.create(&b, POISONIAP, 0.0, 0.0).unwrap();
    s.dispatch(&b, poi, 6, 7).expect("iap tap");
    // volume / music toggles both ways.
    let v = s.create(&b, VOLUME, 0.0, 0.0).unwrap();
    s.dispatch(&b, v, 6, 4).expect("mute");
    assert_eq!(s.globals["soundmute"], 1.0);
    s.dispatch(&b, v, 6, 4).expect("unmute");
    assert_eq!(s.globals["soundmute"], 0.0);
    let vm = s.create(&b, VOLUMEMUSIC, 0.0, 0.0).unwrap();
    s.dispatch(&b, vm, 6, 4).expect("music mute");
    assert_eq!(s.globals["musicmute"], 1.0);
    s.dispatch(&b, vm, 6, 4).expect("music unmute");
    assert_eq!(s.globals["musicmute"], 0.0);
}

#[test]
fn shootbutton_stops_the_rifle_loop() {
    let b = bundle();
    let mut s = scene(&b);
    let sb = s.create(&b, SHOOTBUTTON, 0.0, 0.0).unwrap();
    s.call_audio_play(SND_ASSAULTRIFLE as f64, 0.0, true);
    assert!(s.audio_is_playing_sound(SND_ASSAULTRIFLE as f64));
    s.dispatch(&b, sb, 6, 3).expect("mouse-off tap");
    assert!(!s.audio_is_playing_sound(SND_ASSAULTRIFLE as f64));
}

#[test]
fn store_draws_execute() {
    let b = bundle();
    let mut s = scene(&b);
    for obj in [COINMULTIPLIER5, ENERGYWAVEUPGRADE, MAXHPUPGRADE2, POWERUPGRADE3,
                STRENGTHUPGRADE2, SWORDUPGRADE3, POWERUPGRADE2, PAUSE2] {
        s.create(&b, obj, 0.0, 0.0).unwrap();
    }
    s.view_positions.insert(0, (0.0, 0.0));
    s.draw_view(&b, 0).expect("draw the store page");
}

#[test]
fn store_cleanups_execute() {
    let b = bundle();
    // firstpause's Destroy clears the store furniture.
    let mut s = scene(&b);
    let fp = s.create(&b, FIRSTPAUSE, 0.0, 0.0).unwrap();
    let _g1 = s.create(&b, BACKTOGAME, 0.0, 0.0).unwrap();
    let _g2 = s.create(&b, STORE, 0.0, 0.0).unwrap();
    let _g3 = s.create(&b, VOLUME, 0.0, 0.0).unwrap();
    let _g4 = s.create(&b, VOLUMEMUSIC, 0.0, 0.0).unwrap();
    let _g5 = s.create(&b, PAUSE, 0.0, 0.0).unwrap();
    // The menu furniture ships inactive until opened (and the objects spawn in
    // pairs); the cleanup's with-loops only walk active instances - GMS
    // semantics - so wake the live ones first.
    for i in s.instances.values_mut() {
        if [BACKTOGAME, STORE, VOLUME, VOLUMEMUSIC, PAUSE].contains(&i.object) {
            i.active = true;
        }
    }
    s.destroy(&b, fp).expect("close first pause");
    assert_eq!(count(&s, BACKTOGAME), 0);
    assert_eq!(count(&s, STORE), 0);
    assert_eq!(count(&s, VOLUME), 0);
    assert_eq!(count(&s, VOLUMEMUSIC), 0);
    assert_eq!(count(&s, PAUSE), 0);
    // iapmenu's Destroy clears its two entries.
    let mut s = scene(&b);
    let m = s.create(&b, IAPMENU, 0.0, 0.0).unwrap();
    let _p1 = s.create(&b, POISONIAP, 0.0, 0.0).unwrap();
    let _p2 = s.create(&b, RESTOREIAP, 0.0, 0.0).unwrap();
    s.destroy(&b, m).expect("close iap menu");
    assert_eq!(count(&s, POISONIAP), 0);
    assert_eq!(count(&s, RESTOREIAP), 0);
    // pause2's Destroy also clears storemenu.
    let mut s = scene(&b);
    s.globals.insert("storemenu".into(), 1.0);
    let p2 = s.create(&b, PAUSE2, 0.0, 0.0).unwrap();
    let _g = s.create(&b, STORE, 0.0, 0.0).unwrap();
    s.destroy(&b, p2).expect("close page2");
    assert_eq!(s.globals["storemenu"], 0.0);
    assert_eq!(count(&s, STORE), 0);
}
