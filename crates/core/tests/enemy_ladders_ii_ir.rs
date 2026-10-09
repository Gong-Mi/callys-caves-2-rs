//! Enemy family ladders II: enemy (14), enemy2 (22), wolf (23), bat (31) and
//! shooter2 (20). What was left unexecuted were the status/pose slots: the A3
//! thaw, the A4/A5 stun clears (with their sprite resets where the bodies carry
//! one), the A7 landing reset (wolf/enemy2), the two trap-pose bodies of
//! shooter2 (A6 back to spr_trap1 = 79 = its own default, A2 to spr_trap1fire =
//! 80), and the poison tick - slot 6 for the four beasts, slot 7 for the trap
//! gunner (whose body re-arms alarm[7] itself). Drives follow the mines_slime_ir
//! convention: raw values, self-firing timers run for real.

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const ENEMY: i32 = 14;
const ENEMY2: i32 = 22;
const WOLF: i32 = 23;
const BAT: i32 = 31;
const SHOOTER2: i32 = 20;
const MUTING: i32 = 67;
const DAMAGE: i32 = 104;

struct Spec {
    object: i32,
    hp: &'static str,
    frozen: &'static str,
    poison_slot: usize,
    landing: bool,
    resets: (bool, bool), // A5 / A4 write the default sprite back
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
    if spec.resets.0 {
        assert_eq!(s.instances[&e].fields["sprite_index"], base_sprite,
            "A5 drops back into the default pose");
    }
    s.instances.get_mut(&e).unwrap().fields.insert("sprite_index".into(), -999.0);
    s.dispatch(b, e, 2, 4).expect("A4");
    assert_eq!(s.instances[&e].fields["stunned"], 0.0);
    if spec.resets.1 {
        assert_eq!(s.instances[&e].fields["sprite_index"], base_sprite,
            "A4 drops back into the default pose");
    }
    s.dispatch(b, e, 2, 3).expect("A3");
    assert_eq!(s.instances[&e].fields[spec.frozen], 0.0);
    assert_eq!(s.instances[&e].fields["image_blend"], 0.0, "the white wash comes off");
    if spec.landing {
        {
            let i = s.instances.get_mut(&e).unwrap();
            i.fields.insert("jumping".into(), 1.0);
            i.fields.insert("sprite_index".into(), -999.0);
        }
        s.dispatch(b, e, 2, 7).expect("A7");
        assert_eq!(s.instances[&e].fields["jumping"], 0.0);
        assert_eq!(s.instances[&e].fields["sprite_index"], base_sprite,
            "A7 lands back into the default pose");
    }
    // The poison tick, on its own slot, self-arming through its timer.
    let hp0 = s.instances[&e].fields[spec.hp];
    s.dispatch(b, e, 2, spec.poison_slot as i32).expect("poison");
    assert_eq!(s.instances[&e].fields["poisoned"], 1.0);
    assert_eq!(hp0 - s.instances[&e].fields[spec.hp], 0.25);
    assert_eq!(count(&s, DAMAGE), 1, "one 0.25 damage number");
    assert_eq!(s.instances[&e].alarms[spec.poison_slot], 30, "self-armed");
    for _ in 0..30 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&e].fields[spec.hp], 0.5,
        "the poison ticked itself again on its own timer");
    assert_eq!(s.instances[&e].alarms[spec.poison_slot], 30);
}

fn spec(object: i32, hp: &'static str, frozen: &'static str, poison_slot: usize,
        landing: bool, resets: (bool, bool)) -> Spec {
    Spec { object, hp, frozen, poison_slot, landing, resets }
}

#[test]
fn enemy_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(ENEMY, "hp", "hpfrozen", 6, false, (true, true)));
}

#[test]
fn enemy2_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(ENEMY2, "hptwo", "hptwofrozen", 6, true, (false, false)));
}

#[test]
fn wolf_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(WOLF, "hpwolf", "hpwolffrozen", 6, true, (true, true)));
}

#[test]
fn bat_ladder_completes() {
    let b = bundle();
    status_run(&b, &spec(BAT, "hpfour", "hpfourfrozen", 6, false, (false, false)));
}

#[test]
fn shooter2_status_ladder_and_trap_poses() {
    let b = bundle();
    status_run(&b, &spec(SHOOTER2, "hpshooter2", "hpshooter2frozen", 7, false, (false, false)));
    // The two trap-pose bodies: A6 back to the deployed pose (spr_trap1 = 79 =
    // the object's own default), A2 to the firing pose (spr_trap1fire = 80).
    let mut s = scene(&b);
    let _p = s.create(&b, P, 100.0, 100.0).unwrap();
    let e = s.create(&b, SHOOTER2, 300.0, 200.0).unwrap();
    s.instances.get_mut(&e).unwrap().fields.insert("sprite_index".into(), 80.0);
    s.dispatch(&b, e, 2, 6).expect("A6");
    assert_eq!(s.instances[&e].fields["sprite_index"], 79.0, "back to spr_trap1");
    s.dispatch(&b, e, 2, 2).expect("A2");
    assert_eq!(s.instances[&e].fields["sprite_index"], 80.0, "up to spr_trap1fire");
}
