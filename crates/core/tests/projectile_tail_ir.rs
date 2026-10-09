//! The projectile/specials tail: the destroy alarms of the weapon and enemy
//! projectiles, the two parry-able tail projectiles (bone, firehulkflame),
//! the grenade bounce, the final chest's teaser hand-off, boss4's slot-10
//! poison and two small odds (healthrefill's banner, muting's charge zero).

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const SPARK: i32 = 13; // obj_bulletspark
const PARRY: i32 = 12;
const SMALLPUFF: i32 = 187;
const DAMAGE: i32 = 104;
const ARROW: i32 = 38;
const BLADE: i32 = 36;
const BOOMERANGTHROW: i32 = 43;
const BULLET: i32 = 39;
const COINADD: i32 = 132;
const ENEMYBULLET: i32 = 47;
const ENEMYBULLET2: i32 = 48;
const LASERBEAM: i32 = 41;
const SWORD: i32 = 46;
const BONE: i32 = 56;
const FIREHULKFLAME: i32 = 53;
const FINALBOSSGRENADE: i32 = 50;
const FINALCHEST: i32 = 101;
const TEASE: i32 = 162;
const BOSS4: i32 = 28;
const HEALTHREFILL: i32 = 99;
const MUTING: i32 = 67;
const FIRSTPAUSE: i32 = 118;
const WALL: i32 = 4;
const LEFT: i32 = 130;
const RIGHT: i32 = 131;
const SND_IMPACT1: i32 = 22;

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
fn projectile_destroy_alarms_clear() {
    let b = bundle();
    let table: [(i32, i32, i32); 11] = [
        (ARROW, 2, 0), (BLADE, 2, 0), (BOOMERANGTHROW, 2, 0), (BULLET, 2, 1),
        (COINADD, 2, 0), (ENEMYBULLET, 2, 0), (ENEMYBULLET2, 2, 3), (LASERBEAM, 7, 0),
        (PARRY, 2, 0), (SWORD, 2, 0), (FIRSTPAUSE, 2, 0),
    ];
    for (obj, ev, sub) in table {
        let mut s = scene(&b);
        let _p = s.create(&b, P, 100.0, 100.0).unwrap();
        let it = s.create(&b, obj, 300.0, 200.0).unwrap();
        assert!(s.instances[&it].alive, "obj {obj} created");
        s.dispatch(&b, it, ev, sub).expect("cleanup body");
        assert!(!s.instances[&it].alive, "obj {obj}: the body clears the instance");
    }
}

#[test]
fn bone_and_firehulkflame_parry_and_wall_branches() {
    let b = bundle();
    for obj in [BONE, FIREHULKFLAME] {
        // Parry: the sword at the next position -> obj_parry (+ puff for the flame).
        let mut s = scene(&b);
        let _p = s.create(&b, P, 100.0, 100.0).unwrap();
        let it = s.create(&b, obj, 300.0, 200.0).unwrap();
        {
            let i = s.instances.get_mut(&it).unwrap();
            i.fields.insert("hspeed".into(), 1.0);
            i.fields.insert("vspeed".into(), 0.0);
        }
        let _sw = s.create(&b, SWORD, 301.0, 200.0).unwrap();
        s.dispatch(&b, it, 3, 0).expect("parry step");
        assert!(!s.instances[&it].alive, "obj {obj}: dies on the sword");
        assert_eq!(count(&s, PARRY), 1, "obj {obj}: one parry spark");
        if obj == FIREHULKFLAME {
            assert_eq!(count(&s, SMALLPUFF), 1, "the half-scale puff too");
        }
        // Wall: overlaps par_wall at its own position.
        let mut s = scene(&b);
        let _p = s.create(&b, P, 100.0, 100.0).unwrap();
        let _w = s.create(&b, WALL, 300.0, 200.0).unwrap();
        let it = s.create(&b, obj, 300.0, 200.0).unwrap();
        s.dispatch(&b, it, 3, 0).expect("wall step");
        assert!(!s.instances[&it].alive, "obj {obj}: dies on the wall");
        if obj == BONE {
            assert_eq!(count(&s, SPARK), 1, "the bone leaves a bullet spark");
        } else {
            assert_eq!(count(&s, SMALLPUFF), 1, "the flame leaves the puff");
        }
    }
}

#[test]
fn grenade_bounces_and_the_chest_hands_over_the_teaser() {
    let b = bundle();
    let mut s = scene(&b);
    let g = s.create(&b, FINALBOSSGRENADE, 300.0, 200.0).unwrap();
    s.instances.get_mut(&g).unwrap().fields.insert("hspeed".into(), 3.0);
    s.dispatch(&b, g, 4, 34).expect("wall collision");
    assert_eq!(s.instances[&g].fields["hspeed"], -3.0, "action_bounce flips it");

    let mut s = scene(&b);
    let chest = s.create(&b, FINALCHEST, 300.0, 200.0).unwrap();
    s.dispatch(&b, chest, 4, 0).expect("chest collision");
    assert!(!s.instances[&chest].alive, "the chest is consumed");
    assert_eq!(count(&s, TEASE), 1, "obj_tease takes over");
}

#[test]
fn boss4_poison_slot_is_ten() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 100.0, 100.0).unwrap();
    let e = s.create(&b, BOSS4, 300.0, 200.0).unwrap();
    let hp0 = s.instances[&e].fields["hpboss4"];
    s.dispatch(&b, e, 2, 10).expect("boss4 poison");
    assert_eq!(s.instances[&e].fields["poisoned"], 1.0);
    assert_eq!(hp0 - s.instances[&e].fields["hpboss4"], 0.25);
    assert_eq!(count(&s, DAMAGE), 1);
    assert_eq!(s.instances[&e].alarms[10], 30, "self-armed on slot 10");
    for _ in 0..30 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&e].fields["hpboss4"], 0.5,
        "the poison ticked itself again");
}

#[test]
fn healthrefill_banner_and_muting_charge_zero() {
    let b = bundle();
    let mut s = scene(&b);
    let h = s.create(&b, HEALTHREFILL, 0.0, 0.0).unwrap();
    s.instances.get_mut(&h).unwrap().fields.insert("drawhealthfull".into(), 1.0);
    s.dispatch(&b, h, 2, 0).expect("healthrefill alarm");
    assert_eq!(s.instances[&h].fields["drawhealthfull"], 0.0);
    assert!(s.audio.iter().any(|a| a.sound == SND_IMPACT1));

    let mut s = scene(&b);
    let p = s.create(&b, P, 100.0, 100.0).unwrap();
    let lb = s.create(&b, LEFT, 0.0, 0.0).unwrap();
    let rb = s.create(&b, RIGHT, 0.0, 0.0).unwrap();
    let mu = s.create(&b, MUTING, 0.0, 0.0).unwrap();
    {
        let i = s.instances.get_mut(&p).unwrap();
        i.fields.insert("hspeed".into(), 5.0);
        i.fields.insert("vspeed".into(), 5.0);
        i.fields.insert("hsp".into(), 5.0);
    }
    s.instances.get_mut(&lb).unwrap().alarms[1] = 7;
    s.instances.get_mut(&rb).unwrap().alarms[1] = 9;
    s.dispatch(&b, mu, 2, 5).expect("muting alarm 5");
    let pi = &s.instances[&p];
    assert_eq!(pi.fields["hspeed"], 0.0);
    assert_eq!(pi.fields["vspeed"], 0.0);
    assert_eq!(pi.fields["hsp"], 0.0);
    assert_eq!(s.instances[&lb].alarms[1], 0);
    assert_eq!(s.instances[&rb].alarms[1], 0);
}
