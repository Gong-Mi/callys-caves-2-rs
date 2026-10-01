//! Final boss batch on the IR scene host: obj_finalboss (30, CODE 215-231),
//! obj_finalbosslaser (49, CODE 316-318) and obj_finalbossgrenade (50, CODE
//! 319-324) — closing the boss roster started by boss1/boss2 and the
//! bosses-3-5 batch. Every asserted value was observed from the real bytecode
//! through scratch probes on this host before being frozen; the static decode
//! is in reconstruction/contracts/final-boss.md.
//!
//! Probe-proven fixture facts baked into the tests:
//! - the A2 laser spread must be dispatched DIRECTLY in a wall-free scene:
//!   through the real schedule the a2=270 seed fires beyond a short probe
//!   window, and any wall near the boss kills the spawned lasers within the
//!   same tick (spawn offsets overlap the ground wall's sprite box);
//! - the laser hit does NOT consume the laser (unlike boss3projectile) — it
//!   arms the laser's own alarm[0]=1 and dies on the NEXT tick via CODE 317.
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const INIT: i32 = 103;
const FINALBOSS: i32 = 30;
const LASER: i32 = 49;
const GRENADE: i32 = 50;
const WALL: i32 = 4;
const SWORD: i32 = 46;
const PARRY: i32 = 12;
const SPARK13: i32 = 13;
const FINALPUFF: i32 = 189;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    let init = s.create(b, INIT, -1000.0, -1000.0).expect("initializer");
    s.instances.get_mut(&init).unwrap().alive = false;
    s
}

fn player(s: &mut Scene, b: &Bundle, x: f64, y: f64) -> i32 {
    let p = s.create(b, P, x, y).expect("player");
    let i = s.instances.get_mut(&p).unwrap();
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
    i.fields.insert("gravity".into(), 0.0);
    p
}

fn park(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.active = false;
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

fn count(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|x| x.object == object && x.alive).count()
}

// ---- obj_finalboss -----------------------------------------------------------

#[test]
fn finalboss_ladder_and_phase_seeds() {
    let b = bundle();
    // Create 215: pwr ladder 1750/1650/1550/1350 (the game's highest), hspeed=-1
    // opening drift, a1=180 (empty handler), a2=270 (6-laser spread), a3=120
    // (grenade volley), a4=100 (movement phase).
    for (pwr, want) in [(1.0, 1750.0), (2.0, 1650.0), (3.0, 1550.0), (4.0, 1350.0)] {
        let mut s = scene(&b);
        s.globals.insert("pwr".into(), pwr);
        let p = player(&mut s, &b, 500.0, 200.0);
        let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&fb].fields["hpfinalboss"], want, "pwr {pwr} -> {want}");
        assert_eq!(s.instances[&fb].fields["finalbossmaxhp"], want);
        assert_eq!(s.instances[&fb].fields["hspeed"], -1.0, "opening drift");
        assert_eq!(s.instances[&fb].alarms[4], 100, "movement phase seed");
        assert_eq!(s.instances[&fb].alarms[2], 270, "laser spread seed");
        assert_eq!(s.instances[&fb].alarms[3], 120, "grenade volley seed");
        assert_eq!(s.instances[&fb].alarms[1], 180, "the empty handler slot still cycles");
        park(&mut s, p);
    }
    // The Step re-seeds each cadence slot the moment it reads <= 0: a1->180,
    // a2->180, a3->120 (probe: a3 fired at 120 and read 40 after 200 ticks).
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let i = s.instances.get_mut(&fb).unwrap();
    i.alarms[1] = 0;
    i.alarms[2] = 0;
    i.alarms[3] = 0;
    s.dispatch(&b, fb, 3, 0).expect("reseed step");
    let i = &s.instances[&fb];
    assert_eq!(i.alarms[1], 180, "CODE 229 re-seeds the laser cadence");
    assert_eq!(i.alarms[2], 180);
    assert_eq!(i.alarms[3], 120, "the grenade volley re-seeds at its own 120");
}

#[test]
fn finalboss_six_laser_spread_and_four_grenade_volley() {
    let b = bundle();
    // A2 (226): six lasers at (x-100..x+80, y±20) aimed 45/90/135/180/225/270.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0); // far away: no interference
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, fb, 2, 2).expect("A2 spread");
    let mut dirs: Vec<f64> = s.instances.values().filter(|x| x.object == LASER && x.alive)
        .map(|x| x.fields["direction"]).collect();
    dirs.sort_by(|a, c| a.partial_cmp(c).unwrap());
    assert_eq!(dirs, vec![45.0, 90.0, 135.0, 180.0, 225.0, 270.0],
        "the A2 spread fires all six compass directions");
    // A3 (225): four grenades aimed 180/135/225/90 — gravity bombs, not lasers.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, fb, 2, 3).expect("A3 volley");
    let mut gdirs: Vec<f64> = s.instances.values().filter(|x| x.object == GRENADE && x.alive)
        .map(|x| x.fields["direction"]).collect();
    gdirs.sort_by(|a, c| a.partial_cmp(c).unwrap());
    assert_eq!(gdirs, vec![90.0, 135.0, 180.0, 225.0],
        "the A3 volley throws four grenades");
    let g = s.instances.values().find(|x| x.object == GRENADE && x.alive).unwrap();
    assert_eq!(g.fields["gravity"], 0.6, "grenades arc under gravity");
    assert_eq!(g.fields["speed"], 3.0);
    assert_eq!(g.alarms[0], 45, "the grenade's fuse");
    assert_eq!(g.alarms[1], 63, "and its hard lifetime");
}

#[test]
fn finalboss_movement_phases_relay_through_the_alarms() {
    let b = bundle();
    // The movement phases (A4/A7/A8/A9/A10/A11) form a relay: A4 arms a7=100,
    // A7 arms a8=50, A8 arms a9=20, A9 arms a10=100, A10 arms a11=100,
    // A11 arms a4=100 — a closed movement loop, all gated room != 110.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, fb, 2, 4).expect("A4");
    let i = &s.instances[&fb];
    assert_eq!(i.fields["vspeed"], 2.0, "A4: diagonal dive");
    assert_eq!(i.fields["hspeed"], -2.0);
    assert_eq!(i.alarms[7], 100, "A4 hands over to A7 at 100");
    s.dispatch(&b, fb, 2, 7).expect("A7");
    let i = &s.instances[&fb];
    assert_eq!(i.fields["vspeed"], 3.0, "A7: fast descent with a slow slide");
    assert_eq!(i.fields["hspeed"], 0.5);
    assert_eq!(i.alarms[8], 50, "A7 hands over to A8 at 50");
    s.dispatch(&b, fb, 2, 8).expect("A8");
    assert_eq!(s.instances[&fb].fields["vspeed"], 10.0, "A8: the slam");
    assert_eq!(s.instances[&fb].alarms[9], 20, "A8 hands over to A9 at 20");
    s.dispatch(&b, fb, 2, 9).expect("A9");
    assert_eq!(s.instances[&fb].fields["vspeed"], -0.5, "A9: the slow float back up");
    assert_eq!(s.instances[&fb].alarms[10], 100);
    s.dispatch(&b, fb, 2, 10).expect("A10");
    let i = &s.instances[&fb];
    assert_eq!(i.fields["hspeed"], 2.0, "A10: the horizontal sweep");
    assert_eq!(i.fields["vspeed"], 3.0);
    assert_eq!(i.alarms[11], 100);
    s.dispatch(&b, fb, 2, 11).expect("A11");
    let i = &s.instances[&fb];
    assert_eq!(i.fields["vspeed"], 1.0, "A11: the recovery diagonal");
    assert_eq!(i.fields["hspeed"], -2.0);
    assert_eq!(i.alarms[4], 100, "A11 closes the loop back to A4");
}

#[test]
fn finalboss_death_fanfare_and_puff() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&fb).unwrap().fields.insert("hpfinalboss".into(), 0.0);
    s.dispatch(&b, fb, 3, 0).expect("step at hp 0");
    assert_eq!(s.instances[&fb].alarms[0], 1, "the death beat is armed");
    s.tick(&b).unwrap();
    assert!(!s.instances[&fb].alive);
    assert_eq!(count(&s, FINALPUFF), 1, "obj_finalbosspuff (189) marks the kill");
    assert!(s.audio.iter().any(|a| a.sound == 49), "the death fanfare is snd 49");
    assert!(s.audio.iter().any(|a| a.sound == 7), "the drop beat plays snd 7 first");
}

// ---- obj_finalbosslaser ---------------------------------------------------------

#[test]
fn laser_hits_once_survives_the_impact_and_dies_next_tick() {
    let b = bundle();
    // Create 316: speed=10 fixed, canhit=0, snd 15.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 310.0, 200.0); // off-axis: the knock chain needs x != player.x
    let lz = s.create(&b, LASER, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&lz].fields["speed"], 10.0);
    assert_eq!(s.instances[&lz].fields["canhit"], 0.0);
    assert!(s.audio.iter().any(|a| a.sound == 15), "the laser hums snd 15 on creation");

    let h0 = s.globals["health1"];
    s.dispatch(&b, lz, 3, 0).expect("hit");
    assert_eq!(h0 - s.globals["health1"], 1.0, "the beam costs one heart");
    assert_eq!(s.instances[&lz].fields["canhit"], 1.0, "the single-hit latch closes");
    assert!(s.instances[&lz].alive,
        "the laser SURVIVES its hit (unlike boss3projectile) — it only arms its own death");
    assert_eq!(s.instances[&lz].alarms[0], 1, "the hit arms the laser's alarm[0]=1");
    let pi = &s.instances[&p];
    assert_eq!(pi.fields["invulnerable2"], 1.0, "laser.x < player.x takes the second knock side");
    assert_eq!(pi.fields["sliding2"], 1.0);
    assert_eq!(pi.alarms[4], 10);
    assert_eq!(pi.alarms[7], 22);
    assert_eq!(pi.alarms[8], 25);
    // The latch blocks a second hit on the same step; the armed alarm kills it next tick.
    s.dispatch(&b, lz, 3, 0).expect("second step: latch blocks");
    assert_eq!(s.globals["health1"], h0 - 1.0);
    s.tick(&b).unwrap();
    assert!(!s.instances[&lz].alive, "CODE 317 destroys the laser on its armed alarm");
}

#[test]
fn laser_parry_and_wall_deaths() {
    let b = bundle();
    // Parry: the sword intercepts -> obj_parry(12) spark, laser dies, sword survives.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let sw = s.create(&b, SWORD, 300.0, 200.0).unwrap();
    let lz = s.create(&b, LASER, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, lz, 3, 0).expect("parry");
    assert!(!s.instances[&lz].alive);
    assert_eq!(count(&s, PARRY), 1);
    assert!(s.instances[&sw].alive);
    // Wall: dies with a spark(13).
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let _w = s.create(&b, WALL, 320.0, 200.0).unwrap();
    let lz = s.create(&b, LASER, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, lz, 3, 0).expect("wall");
    assert!(!s.instances[&lz].alive);
    assert_eq!(count(&s, SPARK13), 1, "the wall death leaves one obj_bulletspark");
}

// ---- obj_finalbossgrenade ---------------------------------------------------------

#[test]
fn grenade_bounces_arcs_and_explodes_on_its_fuse() {
    let b = bundle();
    // Create 319: gravity 0.6, speed 3, a0=45 fuse, a1=63 hard lifetime; canhit=0.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 310.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&g].fields["gravity"], 0.6);
    assert_eq!(s.instances[&g].fields["speed"], 3.0);
    assert_eq!(s.instances[&g].alarms[0], 45);
    assert_eq!(s.instances[&g].alarms[1], 63);
    // Bomb-like latch: the first player hit costs a heart, the grenade survives,
    // canhit=1 blocks the second.
    let h0 = s.globals["health1"];
    s.dispatch(&b, g, 3, 0).expect("hit1");
    assert_eq!(h0 - s.globals["health1"], 1.0);
    assert!(s.instances[&g].alive, "the grenade is a contact hazard, not a kamikaze");
    assert_eq!(s.instances[&g].fields["canhit"], 1.0);
    s.dispatch(&b, g, 3, 0).expect("hit2");
    assert_eq!(s.globals["health1"], h0 - 1.0, "the latch blocks re-damage");
    // Collision 34: bounces off walls (action_bounce) — same as the fireslime blob.
    // Fuse A0 (322): stops motion, swaps to sprite 50 (the explosion art), plays snd 8.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, g, 2, 0).expect("fuse");
    let gi = &s.instances[&g];
    assert_eq!(gi.fields["sprite_index"], 50.0, "the fuse swaps to the explosion sprite");
    assert_eq!(gi.fields["image_index"], 0.0);
    assert_eq!(gi.fields["hspeed"], 0.0, "the grenade stops dead at the blast");
    assert_eq!(gi.fields["vspeed"], 0.0);
    assert!(s.audio.iter().any(|a| a.sound == 8), "the blast plays snd 8 (snd_explode2)");
    assert!(gi.alive, "the blast sprite plays out");
    // A1 (321): the hard kill.
    s.dispatch(&b, g, 2, 1).expect("kill");
    assert!(!s.instances[&g].alive);
}
