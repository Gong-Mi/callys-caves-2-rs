//! The undead pair's alarm ladders: obj_zombie (19) and obj_skeleton (17) hang
//! under par_enemy; the earlier suites stepped them but never ran the death
//! chain, the stun clears, the thaw or the poison tick. The template is the
//! five families': A0 sprays the drops and ends with action_kill_object (which
//! fires Destroy: counters + puff), A3 thaws, A4/A5 clear stuns, A6 is the
//! poison tick (self-arming 30). Assertions follow the mines_slime_ir
//! convention: raw values, with the self-sustaining timer driven for real.

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const ZOMBIE: i32 = 19;
const SKELETON: i32 = 17;
const MUTING: i32 = 67; // Create (CODE 371) seeds the 30 spray globals
const DAMAGE: i32 = 104;
const SMALLPUFF: i32 = 187;
const XPORB: i32 = 61;
const GEM: i32 = 59;
const HEALTH: i32 = 62;
const SILVERCOIN: i32 = 60;
const SND_EXPLODE: i32 = 7;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.globals.insert("pwr".into(), 1.0); // hp ladder tier: level 1 / pwr 1
    let m = s.create(b, MUTING, -1000.0, -1000.0).expect("muting");
    s.instances.get_mut(&m).unwrap().alive = false; // seeded the sprays, stays inert
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

fn death_ladder(b: &Bundle, object: i32, hp_field: &str, killed: &str) {
    let mut s = scene(b);
    let _p = s.create(b, P, 100.0, 100.0).unwrap();
    let e = s.create(b, object, 300.0, 200.0).unwrap();
    // Deterministic drops: coindrop=1 -> the five-coin spray; hpdrop forced on.
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("coindrop".into(), 1.0);
        i.fields.insert("hpdrop".into(), 1.0);
        i.fields.insert(hp_field.into(), 0.0);
    }
    s.dispatch(b, e, 3, 0).expect("step at hp 0");
    assert_eq!(s.instances[&e].alarms[0], 1, "the death beat is armed");
    s.tick(b).unwrap();
    assert!(!s.instances[&e].alive, "A0 ends with action_kill_object");
    assert_eq!(s.globals[killed], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    assert_eq!(count(&s, SMALLPUFF), 1, "the Destroy puff");
    assert_eq!(count(&s, XPORB), 1, "xpdrop=1 always sprays one orb");
    assert_eq!(count(&s, GEM), 1, "gemdropenabled is the fresh-start default");
    assert_eq!(count(&s, HEALTH), 1);
    assert_eq!(count(&s, SILVERCOIN), 5, "coindrop==1 sprays five");
    let coin = s.instances.values()
        .filter(|x| x.object == SILVERCOIN && x.alive)
        .min_by_key(|x| x.spawn_seq).unwrap();
    assert_eq!(coin.fields["speed"], 4.7,
        "motion_set(..., 5) minus one friction tick (0.3)");
    assert_eq!(coin.fields["direction"], s.globals["coinspread"],
        "the first coin rides the muting-seeded spread");
    assert!(s.audio.iter().any(|a| a.sound == SND_EXPLODE), "snd_explode");
}

fn status_ladder(b: &Bundle, object: i32, hp_field: &str) {
    let mut s = scene(b);
    let p = s.create(b, P, 100.0, 100.0).unwrap();
    let e = s.create(b, object, 300.0, 200.0).unwrap();
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("stunned".into(), 1.0);
        i.fields.insert(format!("{hp_field}frozen").into(), 1.0);
        i.fields.insert("image_blend".into(), 16777215.0); // c_white
    }
    s.dispatch(b, e, 2, 5).expect("A5 sword-stun clear");
    s.dispatch(b, e, 2, 4).expect("A4 stun clear");
    s.dispatch(b, e, 2, 3).expect("A3 thaw");
    assert_eq!(s.instances[&e].fields["swordstunned"], 0.0);
    assert_eq!(s.instances[&e].fields["stunned"], 0.0);
    assert_eq!(s.instances[&e].fields[&format!("{hp_field}frozen")], 0.0);
    assert_eq!(s.instances[&e].fields["image_blend"], 0.0, "the white wash comes off");
    // A6: the poison tick self-arms its own 30-tick timer.
    let hp0 = s.instances[&e].fields[hp_field];
    s.dispatch(b, e, 2, 6).expect("A6 poison");
    assert_eq!(s.instances[&e].fields["poisoned"], 1.0);
    assert_eq!(hp0 - s.instances[&e].fields[hp_field], 0.25);
    assert_eq!(count(&s, DAMAGE), 1, "one 0.25 damage number");
    assert_eq!(s.instances[&e].alarms[6], 30, "the poison slot self-armed");
    for _ in 0..30 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&e].fields[hp_field], 0.5,
        "the poison ticked itself again on its own timer");
    assert_eq!(s.instances[&e].alarms[6], 30, "and re-armed again");
}

#[test]
fn zombie_ladder_completes() {
    let b = bundle();
    death_ladder(&b, ZOMBIE, "hpzombie", "zombieskilled");
    status_ladder(&b, ZOMBIE, "hpzombie");
}

#[test]
fn skeleton_ladder_completes() {
    let b = bundle();
    death_ladder(&b, SKELETON, "hpskeleton", "skeletonskilled");
    status_ladder(&b, SKELETON, "hpskeleton");
}
