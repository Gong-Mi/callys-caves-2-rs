//! Enemy family ladders III: firehulk (18), fireslime (33), knifebandit (15),
//! shooter1 (16), slime (32) and trex (25) - the rest of the beast cast. The
//! missing bodies are the same status template as II, with three local twists:
//! firehulk's slot-6 body is a pure pose reset (no poison tick), knifebandit's
//! A4 drops the sprite back with the stun, and trex's A3/A2 are the charge
//! pair (walk sprite + hspeed +-3, each re-arming its own 90-tick beat under
//! the room != 110 gate). Drives follow the mines_slime_ir convention.

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const TREX: i32 = 25;
const FIREHULK: i32 = 18;
const FIRESLIME: i32 = 33;
const KNIFEBANDIT: i32 = 15;
const SHOOTER1: i32 = 16;
const SLIME: i32 = 32;
const MUTING: i32 = 67;
const DAMAGE: i32 = 104;

struct Spec {
    object: i32,
    hp: &'static str,
    frozen: &'static str,
    poison: Option<usize>,
    pose6: bool, // A6 is a pure default-pose reset (firehulk)
    sprite5: bool,
    sprite4: bool,
    thaw: bool, // trex's A3 is the charge, not a thaw
    a4: bool,   // trex has no A4 body at all
}

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.globals.insert("pwr".into(), 1.0);
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

fn status_run(b: &Bundle, spec: &Spec) {
    let mut s = scene(b);
    let p = s.create(b, P, 100.0, 100.0).unwrap();
    let e = s.create(b, spec.object, 300.0, 200.0).unwrap();
    let base_sprite = s.instances[&e].fields["sprite_index"];
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("stunned".into(), 1.0);
        i.fields.insert(spec.frozen.into(), 1.0);
        i.fields.insert("image_blend".into(), 16777215.0);
        i.fields.insert("sprite_index".into(), -999.0);
    }
    s.dispatch(b, e, 2, 5).expect("A5");
    assert_eq!(s.instances[&e].fields["swordstunned"], 0.0);
    if spec.sprite5 {
        assert_eq!(s.instances[&e].fields["sprite_index"], base_sprite,
            "A5 drops back into the default pose");
    }
    s.instances.get_mut(&e).unwrap().fields.insert("sprite_index".into(), -999.0);
    if spec.a4 {
        s.dispatch(b, e, 2, 4).expect("A4");
        assert_eq!(s.instances[&e].fields["stunned"], 0.0);
        if spec.sprite4 {
            assert_eq!(s.instances[&e].fields["sprite_index"], base_sprite,
                "A4 drops back into the default pose");
        }
    }
    if spec.thaw {
        s.dispatch(b, e, 2, 3).expect("A3");
        assert_eq!(s.instances[&e].fields[spec.frozen], 0.0);
        assert_eq!(s.instances[&e].fields["image_blend"], 0.0, "the white wash comes off");
    }
    if spec.pose6 {
        s.instances.get_mut(&e).unwrap().fields.insert("sprite_index".into(), -999.0);
        s.dispatch(b, e, 2, 6).expect("A6");
        assert_eq!(s.instances[&e].fields["sprite_index"], base_sprite,
            "A6 is a pure pose reset for this one");
    }
    if let Some(slot) = spec.poison {
        let hp0 = s.instances[&e].fields[spec.hp];
        s.dispatch(b, e, 2, slot as i32).expect("poison");
        assert_eq!(s.instances[&e].fields["poisoned"], 1.0);
        assert_eq!(hp0 - s.instances[&e].fields[spec.hp], 0.25);
        assert_eq!(count(&s, DAMAGE), 1, "one 0.25 damage number");
        assert_eq!(s.instances[&e].alarms[slot], 30, "self-armed");
        for _ in 0..30 {
            pin(&mut s, p, 100.0, 100.0);
            s.tick(b).unwrap();
        }
        assert_eq!(hp0 - s.instances[&e].fields[spec.hp], 0.5,
            "the poison ticked itself again on its own timer");
        assert_eq!(s.instances[&e].alarms[slot], 30);
    }
}

fn spec(object: i32, hp: &'static str, frozen: &'static str, poison: Option<usize>,
        pose6: bool, sprite5: bool, sprite4: bool) -> Spec {
    Spec { object, hp, frozen, poison, pose6, sprite5, sprite4, thaw: true, a4: true }
}

#[test]
fn firehulk_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(FIREHULK, "hpfirehulk", "hpfirehulkfrozen", None, true, false, false));
}

#[test]
fn fireslime_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(FIRESLIME, "hpfireslime", "hpfireslimefrozen", Some(6), false, false, false));
}

#[test]
fn knifebandit_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(KNIFEBANDIT, "hpknife", "hpfrozen", Some(6), false, false, true));
}

#[test]
fn shooter1_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(SHOOTER1, "hpshooter1", "hpshooter1frozen", Some(6), false, false, false));
}

#[test]
fn slime_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(SLIME, "hpslime", "hpslimefrozen", Some(6), false, false, false));
}

#[test]
fn trex_ladders_and_the_charge_pair() {
    let b = bundle();
    let mut ts = spec(TREX, "hptrex", "hptrex", Some(6), false, false, false);
    ts.thaw = false; // trex's A3 is the rightward charge, not a thaw
    ts.a4 = false; // and it has no A4 body at all
    status_run(&b, &ts);
    // A3 / A2: the charge pair under the room != 110 gate. Each sets the walk
    // sprite and hspeed, and re-arms its own 90-tick beat.
    let mut s = scene(&b);
    let p = s.create(&b, P, 100.0, 100.0).unwrap();
    let e = s.create(&b, TREX, 300.0, 200.0).unwrap();
    s.dispatch(&b, e, 2, 3).expect("A3 charge right");
    assert_eq!(s.instances[&e].fields["sprite_index"], 56.0, "the walk pose");
    assert_eq!(s.instances[&e].fields["hspeed"], 3.0);
    assert_eq!(s.instances[&e].alarms[3], 90, "the beat re-arms itself");
    for _ in 0..90 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(s.instances[&e].alarms[3], 90, "and fires again 90 ticks later");
    s.dispatch(&b, e, 2, 2).expect("A2 charge left");
    assert_eq!(s.instances[&e].fields["sprite_index"], 54.0, "the leftward walk pose");
    assert_eq!(s.instances[&e].fields["hspeed"], -3.0);
    assert_eq!(s.instances[&e].alarms[2], 90);
}
