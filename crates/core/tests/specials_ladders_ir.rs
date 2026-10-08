//! The specials sweep: the mixed tail of the object matrix's unexecuted list -
//! ghost's status slots (148/149/150), boss2's poison + sword-stun clears
//! (165/166), finalboss' poison + clear + one genuinely EMPTY body (222/223/227),
//! obj_pause's Esc chain (508/509/511) and the player's three odds (6/9/19).
//! The keyboard events are the only two in the whole bundle (KeyPress 9/27 on
//! pause, KeyRelease 10/38 on the player - the latter walks to rm_ending).

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const GHOST: i32 = 24;
const BOSS2: i32 = 26;
const FINALBOSS: i32 = 30;
const PAUSE: i32 = 122;
const STORE: i32 = 110;
const POWERUPGRADE: i32 = 84;
const DAMAGE: i32 = 104;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.globals.insert("pwr".into(), 1.0);
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
fn ghost_status_ladder_completes() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = s.create(&b, P, 100.0, 100.0).unwrap();
    let e = s.create(&b, GHOST, 300.0, 200.0).unwrap();
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("stunned".into(), 1.0);
        i.fields.insert("hpghostfrozen".into(), 1.0);
        i.fields.insert("image_blend".into(), 16777215.0);
    }
    s.dispatch(&b, e, 2, 5).expect("A5");
    s.dispatch(&b, e, 2, 4).expect("A4");
    s.dispatch(&b, e, 2, 3).expect("A3");
    assert_eq!(s.instances[&e].fields["swordstunned"], 0.0);
    assert_eq!(s.instances[&e].fields["stunned"], 0.0);
    assert_eq!(s.instances[&e].fields["hpghostfrozen"], 0.0);
    assert_eq!(s.instances[&e].fields["image_blend"], 0.0, "the white wash comes off");
}

#[test]
fn boss2_poison_and_clear_slots() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 100.0, 100.0).unwrap();
    let e = s.create(&b, BOSS2, 300.0, 200.0).unwrap();
    s.instances.get_mut(&e).unwrap().fields.insert("swordstunned".into(), 1.0);
    s.dispatch(&b, e, 2, 5).expect("A5");
    assert_eq!(s.instances[&e].fields["swordstunned"], 0.0);
    let hp0 = s.instances[&e].fields["hpboss2"];
    s.dispatch(&b, e, 2, 6).expect("A6 poison");
    assert_eq!(s.instances[&e].fields["poisoned"], 1.0);
    assert_eq!(hp0 - s.instances[&e].fields["hpboss2"], 0.25);
    assert_eq!(count(&s, DAMAGE), 1);
    assert_eq!(s.instances[&e].alarms[6], 30, "self-armed");
    for _ in 0..30 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&e].fields["hpboss2"], 0.5,
        "the poison ticked itself again");
    assert_eq!(s.instances[&e].alarms[6], 30);
}

#[test]
fn finalboss_poison_clear_and_the_empty_body() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 100.0, 100.0).unwrap();
    let e = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    s.instances.get_mut(&e).unwrap().fields.insert("swordstunned".into(), 1.0);
    s.dispatch(&b, e, 2, 5).expect("A5");
    assert_eq!(s.instances[&e].fields["swordstunned"], 0.0);
    let hp0 = s.instances[&e].fields["hpfinalboss"];
    s.dispatch(&b, e, 2, 6).expect("A6 poison");
    assert_eq!(hp0 - s.instances[&e].fields["hpfinalboss"], 0.25);
    assert_eq!(s.instances[&e].alarms[6], 30);
    // A1 is a genuinely empty body: it executes (the ledger records the entry)
    // and changes nothing.
    let alive = s.instances[&e].alive;
    s.dispatch(&b, e, 2, 1).expect("A1 empty");
    assert_eq!(s.instances[&e].alive, alive);
    assert_eq!(s.instances[&e].fields["hpfinalboss"], hp0 - 0.25);
    for _ in 0..30 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&e].fields["hpfinalboss"], 0.5,
        "the poison ticked itself again");
}

#[test]
fn pause_esc_chain_cleans_the_store() {
    let b = bundle();
    let mut s = scene(&b);
    let pause = s.create(&b, PAUSE, 0.0, 0.0).unwrap();
    let store = s.create(&b, STORE, 0.0, 0.0).unwrap();
    let pwr = s.create(&b, POWERUPGRADE, 0.0, 0.0).unwrap();
    s.globals.insert("storemenu".into(), 1.0);
    // Esc press: KeyPress 27 arms the close beat.
    s.dispatch(&b, pause, 9, 27).expect("Esc");
    assert_eq!(s.instances[&pause].alarms[0], 1);
    s.tick(&b).unwrap();
    // A0 destroys the menu; Destroy clears the flag and every store button.
    assert!(!s.instances[&pause].alive, "A0 closes the pause");
    assert_eq!(s.globals["storemenu"], 0.0);
    assert!(!s.instances[&store].alive, "the store button is cleaned");
    assert!(!s.instances[&pwr].alive, "so is the power-upgrade button");
}

#[test]
fn player_odds_swing_death_flag_and_the_ending_key() {
    let b = bundle();
    let mut s = scene(&b);
    let pl = s.create(&b, P, 300.0, 200.0).unwrap();
    // A5: clears the playerdied flag.
    s.instances.get_mut(&pl).unwrap().fields.insert("playerdied".into(), 1.0);
    s.dispatch(&b, pl, 2, 5).expect("A5");
    assert_eq!(s.instances[&pl].fields["playerdied"], 0.0);
    // A2: resets the swing latch and the running pose (spr_player = 29).
    {
        let i = s.instances.get_mut(&pl).unwrap();
        i.fields.insert("sprite_index".into(), -999.0);
    }
    s.globals.insert("swing".into(), 0.0);
    s.dispatch(&b, pl, 2, 2).expect("A2");
    assert_eq!(s.globals["swing"], 1.0);
    assert_eq!(s.instances[&pl].fields["sprite_index"], 29.0, "spr_player");
    // KeyRelease 38 (the only key-release body in the bundle) walks to the ending.
    s.dispatch(&b, pl, 10, 38).expect("key release");
    assert_eq!(s.target_room_warp, Some(110), "rm_ending");
}
