//! obj_house (2): the town's gem house. Standing on it walks a six-beat hold -
//! the first check at +30 ticks, then one beat every 600 - and the sixth pay
//! out sprays ten gems once per save (`gemsfromhouse`) with snd_weaponlevelup.
//! Leaving mid-hold resets the poll to the 30-tick recheck; with no contact the
//! ladder never advances.

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const HOUSE: i32 = 2;
const MUTING: i32 = 67; // Create (CODE 371) seeds the 30 spray globals
const GEM: i32 = 59;
const SND_WEAPONLEVELUP: i32 = 28;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.globals.insert("gemsfromhouse".into(), 0.0); // fresh save: not yet paid
    let m = s.create(b, MUTING, -1000.0, -1000.0).expect("muting");
    s.instances.get_mut(&m).unwrap().alive = false;
    s
}

fn count(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|x| x.object == object && x.alive).count()
}

fn pin(s: &mut Scene, id: i32, x: f64, y: f64) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("x".into(), x);
    i.fields.insert("y".into(), y);
}

#[test]
fn house_pays_ten_gems_after_the_six_beat_hold() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 300.0, 200.0).unwrap();
    let h = s.create(&b, HOUSE, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&h].fields["type"], 1.0);
    assert_eq!(s.instances[&h].alarms[0], 30, "the first check is +30");
    let mut payout = 0;
    let mut got: Vec<f64> = Vec::new();
    let mut speed_ok = false;
    for t in 1..=3640 {
        pin(&mut s, p, 300.0, 200.0);
        s.tick(&b).unwrap();
        if payout == 0 && count(&s, GEM) > 0 {
            payout = t;
            // Read the spawn state at the payout tick; friction (0.3) is
            // integrated in the same tick, so the launch reads 8 - 0.3.
            let gems: Vec<_> = s.instances.values()
                .filter(|x| x.object == GEM && x.alive).collect();
            speed_ok = gems.iter().all(|g| (g.fields["speed"] - 7.7).abs() < 1e-6);
            got = gems.iter().map(|g| g.fields["direction"]).collect();
        }
    }
    assert_eq!(payout, 3624, "the +30 check, then six beats of 599 ticks each \
        (a 600 seed loses one to the same-tick decrement)");
    assert_eq!(count(&s, GEM), 10);
    assert_eq!(s.globals["gemsfromhouse"], 1.0);
    assert!(s.audio.iter().any(|a| a.sound == SND_WEAPONLEVELUP));
    assert_eq!(got.len(), 10);
    assert!(speed_ok, "the spray leaves at speed 8");
    got.sort_by(|a, b| a.total_cmp(b));
    let mut want: Vec<f64> = (1..=10).map(|n| {
        if n == 1 { s.globals["coinspread"] } else { s.globals[&format!("coinspread{n}")] }
    }).collect();
    want.sort_by(|a, b| a.total_cmp(b));
    for (g, w) in got.iter().zip(want.iter()) {
        assert!((g - w).abs() < 1e-9,
            "one gem per seeded spread direction (derived direction is rounding-close)");
    }
    // The payment is once per save: standing on it again pays nothing.
    s.dispatch(&b, h, 2, 6).expect("A6 re-dispatch");
    assert_eq!(count(&s, GEM), 10, "gemsfromhouse gates the repeat");
}

#[test]
fn house_resets_its_hold_when_the_player_leaves() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 100.0, 100.0).unwrap();
    let h = s.create(&b, HOUSE, 300.0, 200.0).unwrap();
    // No contact: the poll re-arms every 30 ticks and the ladder never starts.
    for _ in 0..200 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(count(&s, GEM), 0);
    assert_eq!(s.globals["gemsfromhouse"], 0.0);
    assert!(s.instances[&h].alarms[0] > 0 && s.instances[&h].alarms[0] <= 30,
        "the poll keeps re-arming");
    assert!(s.instances[&h].alarms[1] <= 0, "the first beat was never armed");
    // Contact through the first beat, then leave before the second: the second
    // beat's check finds nobody and resets the poll.
    for _ in 0..630 {
        pin(&mut s, p, 300.0, 200.0);
        s.tick(&b).unwrap();
    }
    for _ in 0..610 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(count(&s, GEM), 0);
    assert_eq!(s.globals["gemsfromhouse"], 0.0);
    assert!(s.instances[&h].alarms[0] > 0, "the beat reset the poll");
    assert!(s.instances[&h].alarms[3] <= 0, "the third beat was never armed");
}
