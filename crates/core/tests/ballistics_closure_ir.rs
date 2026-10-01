//! Weapon ballistics closure batch on the IR scene host: the five remaining
//! projectile families — obj_laserbeam (41, CODE 287/288/289/290), obj_flame
//! (35, CODE 268/269/270), obj_blade (36, CODE 271-274), obj_bomb (37, CODE
//! 275-278), obj_arrow (38, CODE 279-281), obj_boomerangthrow (43, CODE
//! 295-298) and obj_energywave (45, CODE 304-308). Every asserted value was
//! observed from the real bytecode through this host (scratch probes) before
//! being frozen here; the static disassembly of each branch family is
//! recorded in reconstruction/contracts/ballistics-closure.md.
//!
//! Fixture discipline (project hard rules): the player stays alive+active
//! until the projectile's Create has read obj_player.facing, then is parked;
//! victims are never parked while a hit test runs against them (Scene::select
//! filters alive+active); direct Step dispatches assert raw values without
//! the tick's gravity/friction integration; full-tick runs re-pin the player
//! each frame because its own Step gravity would drift the fixture.
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const INIT: i32 = 103;
const KNIFE: i32 = 15;
const WALL: i32 = 4;
const WOODBLOCK: i32 = 158;
const SPARK: i32 = 13;
const DAMAGE: i32 = 104;
const LASERBEAM: i32 = 41;
const FLAME: i32 = 35;
const BLADE: i32 = 36;
const BOMB: i32 = 37;
const ARROW: i32 = 38;
const BOOMERANGTHROW: i32 = 43;
const ENERGYWAVE: i32 = 45;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    let init = s.create(b, INIT, -1000.0, -1000.0).expect("initializer");
    s.instances.get_mut(&init).unwrap().alive = false; // ran once, keep inert
    s
}

fn player(s: &mut Scene, b: &Bundle, facing: f64) -> i32 {
    let p = s.create(b, P, 500.0, 200.0).expect("player");
    s.instances.get_mut(&p).unwrap().fields.insert("facing".into(), facing);
    p
}

fn park(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.active = false;
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

fn knife(s: &mut Scene, b: &Bundle, x: f64, y: f64) -> i32 {
    s.create(b, KNIFE, x, y).expect("knifebandit")
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

fn audio(s: &Scene) -> Vec<i32> {
    s.audio.iter().map(|a| a.sound).collect()
}

// ---- obj_laserbeam ---------------------------------------------------------

#[test]
fn laserbeam_create_flips_on_facing_and_arms_the_fuse() {
    let b = bundle();
    for (facing, want) in [(1.0, -20.0), (0.0, 20.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let lb = s.create(&b, LASERBEAM, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&lb].fields["hspeed"], want,
            "CODE 287: facing {facing} -> hspeed {want}");
        assert_eq!(s.instances[&lb].alarms[1], 120, "CODE 287 alarm[1]=120 fuse");
        assert_eq!(s.instances[&lb].fields["sprite_index"], 42.0);
        park(&mut s, p);
    }
}

#[test]
fn laserbeam_stuns_and_dies_but_only_lasers_damage() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let lb = s.create(&b, LASERBEAM, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, lb, 3, 0).expect("laserbeam Step CODE 289");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], 0.0,
        "global.laser==0 keeps the damage gate closed (CODE 289)");
    assert_eq!(vi.fields["flashing"], 1.0, "flashing happens regardless");
    assert_eq!(vi.fields["stunned"], 1.0, "stunned=1 via the in-branch with-statement");
    assert_eq!(vi.alarms[4], 5, "CODE 289 knife-family stun alarm is 5, not 10");
    assert!(!s.instances[&lb].alive, "the beam consumes itself on any hit");
    assert_eq!(s.globals["laserxp"], 0.0, "xp only flows through the damage gate");
    assert_eq!(s.particles.len(), 2);
    assert_eq!(cast(&s, DAMAGE).len(), 0, "obj_damage only spawns inside the gate");
    assert_eq!(audio(&s), vec![23], "snd_impactsound2 plays outside the gate");

    // The same step with global.laser==1 (weapon actually equipped) opens the gate.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    // obj_player Create (CODE 0) unconditionally stores global.laser=0, so the
    // gate must be armed AFTER the player exists (fixture order matters).
    s.globals.insert("laser".into(), 1.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let lb = s.create(&b, LASERBEAM, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, lb, 3, 0).expect("gated step");
    assert_eq!(hp0 - s.instances[&v].fields["hpknife"], s.globals["laserdamage"],
        "global.laser==1 opens the hpknife damage path");
    assert_eq!(s.globals["laserxp"], 1.0);
    assert_eq!(cast(&s, DAMAGE).len(), 1);
}

#[test]
fn laserbeam_arms_the_poison_alarm_only_when_enabled() {
    let b = bundle();
    let mut s = scene(&b);
    s.globals.insert("poisonenabled".into(), 1.0);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let lb = s.create(&b, LASERBEAM, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, lb, 3, 0).expect("poison step");
    assert_eq!(s.instances[&v].alarms[6], 1, "poisonenabled==1 arms alarm[6]=1");
}

#[test]
fn laserbeam_dies_on_its_fuse_with_no_wall_branch() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    let _wall = s.create(&b, WALL, 280.0, 200.0).unwrap(); // in flight path
    let lb = s.create(&b, LASERBEAM, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let mut death = 0;
    for t in 1..=121 {
        s.tick(&b).unwrap();
        if !s.instances[&lb].alive { death = t; break; }
    }
    assert_eq!(death, 120,
        "CODE 288 kills the beam at alarm[1]=120 (1-based scheduler tick)");
    assert_eq!(cast(&s, SPARK).len(), 0,
        "the beam has NO wall branch — obj_bulletspark never spawns (CODE 289 starts at the knife family)");
}

// ---- obj_flame ------------------------------------------------------------

#[test]
fn flame_flies_diagonally_and_grows_until_alarm_nine_kills_it() {
    let b = bundle();
    for (facing, hsp) in [(1.0, -15.0), (0.0, 15.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let f = s.create(&b, FLAME, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&f].fields["hspeed"], hsp,
            "CODE 268: facing {facing} -> hspeed {hsp}");
        assert_eq!(s.instances[&f].fields["vspeed"], -1.0, "both branches rise at vspeed -1");
        assert_eq!(s.instances[&f].alarms[0], 9, "CODE 268 alarm[0]=9 lifetime");
        park(&mut s, p);
    }
    // Growth per Step (0.1 both axes) and the 9-tick lifetime via the real scheduler.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let f = s.create(&b, FLAME, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, f, 3, 0).expect("flame Step");
    assert_eq!(s.instances[&f].fields["image_xscale"], 1.1,
        "CODE 270 grows xscale by 0.1 every Step");
    assert_eq!(s.instances[&f].fields["image_yscale"], 1.1);
    let mut death = 0;
    for t in 1..=12 {
        s.tick(&b).unwrap();
        if !s.instances[&f].alive { death = t; break; }
    }
    assert_eq!(death, 9, "CODE 269 destroys the flame at alarm[0]=9");
}

#[test]
fn flame_freezes_in_the_ending_room_but_keeps_growing() {
    let b = bundle();
    let mut s = scene(&b);
    s.current_room = 110.0; // rm_ending
    let p = player(&mut s, &b, 0.0);
    let f = s.create(&b, FLAME, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, f, 3, 0).expect("flame Step in room 110");
    let fi = &s.instances[&f];
    assert_eq!(fi.fields["hspeed"], 0.0, "CODE 270 zeroes hspeed in room 110");
    assert_eq!(fi.fields["vspeed"], 0.0, "and vspeed");
    assert_eq!(fi.fields["image_xscale"], 1.1,
        "the growth still runs — the branch only freezes motion");
}

#[test]
fn flame_burns_per_step_without_stun_and_dedups_the_impact_sound() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let f = s.create(&b, FLAME, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, f, 3, 0).expect("burn 1");
    let hp1 = s.instances[&v].fields["hpknife"];
    assert!((15.0 - hp1 - s.globals["flamethrowerdamage"]).abs() < 1e-9,
        "CODE 270 subtracts flamethrowerdamage per Step (no weapon gate; victim hp is a float chain)");
    assert!(!s.instances[&f].alive == false, "flame pierces — no self-destroy on hit");
    assert_eq!(s.instances[&v].fields["flashing"], 1.0);
    assert!(!s.instances[&v].fields.contains_key("stunned") || s.instances[&v].fields["stunned"] == 0.0,
        "flame never stuns: CODE 270 has zero stunned stores (a pre-existing 0 is inert)");
    assert_eq!(s.instances[&v].alarms[6], -1, "poison off: alarm[6] untouched");
    assert_eq!(s.globals["flamethrowerxp"], 1.0);

    s.dispatch(&b, f, 3, 0).expect("burn 2");
    let hp2 = s.instances[&v].fields["hpknife"];
    assert!((hp1 - hp2 - s.globals["flamethrowerdamage"]).abs() < 1e-9,
        "the second Step burns again — a sustained hit is damage-per-step");
    assert_eq!(s.globals["flamethrowerxp"], 2.0);
    assert_eq!(audio(&s).len(), 1,
        "the audio_is_playing gate suppresses a second snd 23 while the first voice is live");
}

// ---- obj_blade ------------------------------------------------------------

#[test]
fn blade_cuts_woodblocks_down_with_both_parties() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let w = s.create(&b, WOODBLOCK, 320.0, 200.0).unwrap();
    let bl = s.create(&b, BLADE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, bl, 3, 0).expect("blade Step at woodblock");
    assert!(!s.instances[&w].alive, "CODE 274 destroys the woodblock (with-env)");
    assert!(!s.instances[&bl].alive, "and the blade dies in the same branch (double kill)");
}

#[test]
fn blade_sparks_and_dies_on_plain_walls() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let _w = s.create(&b, WALL, 320.0, 200.0).unwrap();
    let bl = s.create(&b, BLADE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, bl, 3, 0).expect("blade Step at par_wall");
    assert!(!s.instances[&bl].alive, "the par_wall branch destroys the blade");
    assert_eq!(cast(&s, SPARK).len(), 1, "and leaves one obj_bulletspark");
}

#[test]
fn blade_hits_stun_latch_free_and_survive_to_the_timeout() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let bl = s.create(&b, BLADE, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, bl, 3, 0).expect("blade Step at victim");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], s.globals["bladegundamage"],
        "no canhit gate on the blade — damage is unconditional");
    assert_eq!(vi.fields["stunned"], 1.0);
    assert_eq!(vi.alarms[4], 10, "blade stun alarm is the standard 10");
    assert!(s.instances[&bl].alive, "the blade pierces and keeps flying");
    assert_eq!(s.globals["bladegunxp"], 1.0);
    assert_eq!(s.particles.len(), 3, "blade particle count is 3");

    // 40-tick timeout (alarm[1], CODE 272) owns the blade's death.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let bl = s.create(&b, BLADE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let mut death = 0;
    for t in 1..=41 {
        s.tick(&b).unwrap();
        if !s.instances[&bl].alive { death = t; break; }
    }
    assert_eq!(death, 40, "CODE 272 destroys the blade at alarm[1]=40 (1-based scheduler tick)");
}

// ---- obj_bomb -------------------------------------------------------------

#[test]
fn bomb_creates_with_a_single_hit_latch_and_a_thirty_frame_fuse() {
    let b = bundle();
    for (facing, hsp) in [(1.0, -8.0), (0.0, 8.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let bo = s.create(&b, BOMB, 300.0, 200.0).unwrap();
        let bi = &s.instances[&bo];
        assert_eq!(bi.fields["hspeed"], hsp, "CODE 275: facing {facing} -> {hsp}");
        assert_eq!(bi.fields["canhit"], 0.0);
        assert_eq!(bi.fields["hitwall"], 0.0);
        assert_eq!(bi.alarms[0], 30, "CODE 275 arms the 30-frame fuse");
        park(&mut s, p);
    }
}

#[test]
fn bomb_bounces_off_walls_and_lands_with_gravity() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let _w = s.create(&b, WALL, 308.0, 200.0).unwrap(); // at x+hspeed
    let bo = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, bo, 3, 0).expect("bomb Step at wall");
    let bi = &s.instances[&bo];
    assert_eq!(bi.fields["hspeed"], -8.0,
        "move_bounce_solid flips hspeed while the bomb is still sprite 44");
    assert_eq!(bi.fields["gravity"], 0.3,
        "the Step sets gravity 0.3 — the bomb falls after the first contact");
    assert!(bi.alive);
}

#[test]
fn bomb_hits_once_per_life_and_the_impact_arms_the_fuse() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let bo = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, bo, 3, 0).expect("bomb Step 1");
    assert_eq!(hp0 - s.instances[&v].fields["hpknife"], s.globals["bombgundamage"]);
    assert_eq!(s.instances[&v].fields["flashing"], 1.0);
    assert_eq!(audio(&s), vec![8], "the impact plays snd_explode2 immediately");
    assert_eq!(cast(&s, DAMAGE).len(), 1);
    assert_eq!(s.globals["bombgunxp"], 1.0, "bomb xp flows on the hit");
    // The latch closes family damage for the REST of the bomb's life.
    let hp1 = s.instances[&v].fields["hpknife"];
    s.dispatch(&b, bo, 3, 0).expect("bomb Step 2");
    assert_eq!(s.instances[&v].fields["hpknife"], hp1,
        "canhit=1 blocks a second damage application");
}

#[test]
fn bomb_explodes_on_the_fuse_and_the_blast_is_its_death() {
    let b = bundle();
    // Un-hit fuse: explode at tick 30, blast sprite 50 for 18 frames, dead at 47.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let bo = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let mut expl = 0; let mut death = 0;
    for t in 1..=60 {
        s.tick(&b).unwrap();
        if s.instances[&bo].fields.get("sprite_index") != Some(&50.0) {
            // isolation: re-pin so the flight never meets the parked player
            let i = s.instances.get_mut(&bo).unwrap();
            i.fields.insert("x".into(), 300.0);
            i.fields.insert("y".into(), 200.0);
            i.fields.insert("hspeed".into(), 8.0);
            i.fields.insert("vspeed".into(), 0.0);
        }
        if expl == 0 && s.instances[&bo].fields.get("sprite_index") == Some(&50.0) {
            expl = t;
            assert_eq!(s.instances[&bo].alarms[1], 17,
                "CODE 277 arms alarm[1]=18 (reads 17 in-tick), zeroes motion, plays snd 23");
        }
        if !s.instances[&bo].alive { death = t; break; }
    }
    assert_eq!(expl, 30, "CODE 275's fuse explodes at tick 30");
    assert_eq!(death, 47, "CODE 276 destroys the blast 18 frames later");

    // Hit path: the impact arms alarm[0]=1 so the explosion is immediate.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let bo = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, bo, 3, 0).expect("hit");
    park(&mut s, v);
    s.tick(&b).unwrap();
    assert_eq!(s.instances[&bo].fields["sprite_index"], 50.0,
        "alarm[0]=1 from the hit detonates the bomb on the next tick");
}

// ---- obj_arrow ------------------------------------------------------------

#[test]
fn arrow_flies_a_rising_arc_and_falls_under_gravity_after_the_first_step() {
    let b = bundle();
    for (facing, hsp) in [(1.0, -15.0), (0.0, 15.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let ar = s.create(&b, ARROW, 300.0, 200.0).unwrap();
        let ai = &s.instances[&ar];
        assert_eq!(ai.fields["hspeed"], hsp, "CODE 279: facing {facing} -> {hsp}");
        assert_eq!(ai.fields["vspeed"], -1.0, "both branches launch rising");
        park(&mut s, p);
    }
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let ar = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, ar, 3, 0).expect("arrow Step");
    assert_eq!(s.instances[&ar].fields["gravity"], 0.3,
        "CODE 281 gives the arrow gravity 0.3 — it arcs");
    assert_eq!(s.instances[&ar].fields["image_angle"], 0.0,
        "image_angle follows direction while it is 0");
}

#[test]
fn arrow_sticks_when_it_misses_but_stays_close_to_the_player() {
    let b = bundle();
    // Near an ACTIVE player (<16 px) with a wall at the arrow position: survives.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    s.instances.get_mut(&p).unwrap().fields.insert("x".into(), 305.0); // 5 px gap, active
    let _w = s.create(&b, WALL, 300.0, 200.0).unwrap();
    let ar = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    s.dispatch(&b, ar, 3, 0).expect("near step");
    assert!(s.instances[&ar].alive,
        "distance_to_object(obj_player) < 16 keeps the arrow alive (recoverable arrow)");
    assert_eq!(cast(&s, SPARK).len(), 0);

    // Far player (>=16): spark + destroy.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0); // active at (500,200)
    let _w = s.create(&b, WALL, 300.0, 200.0).unwrap();
    let ar = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    let _ = &p;
    s.dispatch(&b, ar, 3, 0).expect("far step");
    assert!(!s.instances[&ar].alive);
    assert_eq!(cast(&s, SPARK).len(), 1);

    // The boundary is strict: gap exactly 16 dies, 15.9 survives.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    s.instances.get_mut(&p).unwrap().fields.insert("x".into(), 316.0);
    let _w = s.create(&b, WALL, 300.0, 200.0).unwrap();
    let ar = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    s.dispatch(&b, ar, 3, 0).expect("gap 16");
    assert!(!s.instances[&ar].alive, "CODE 281's keep condition is distance < 16");
}

#[test]
fn arrow_hits_stun_and_pierce() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let ar = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, ar, 3, 0).expect("arrow hit step");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], s.globals["bowdamage"]);
    assert_eq!(vi.fields["stunned"], 1.0);
    assert_eq!(vi.alarms[4], 10, "arrow stun alarm 4 at 10");
    assert!(s.instances[&ar].alive, "the arrow pierces enemies — only walls/player range kill it");
    assert_eq!(s.globals["bowxp"], 1.0);
    assert_eq!(s.particles.len(), 3, "arrow particle count is 3");
}

// ---- obj_boomerangthrow ---------------------------------------------------

#[test]
fn boomerang_create_speeds_level_frames_and_arms_the_return() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    let bt = s.create(&b, BOOMERANGTHROW, 300.0, 200.0).unwrap();
    let ti = &s.instances[&bt];
    assert_eq!(ti.fields["hspeed"], -5.0, "CODE 295: facing 1 -> -5 (slow throw)");
    assert_eq!(ti.alarms[1], 30, "CODE 295 arms alarm[1]=30 return timer");
    assert_eq!(ti.fields["boomerangreturn"], 0.0);
    assert_eq!(ti.fields["image_speed"], 0.0, "the throw freezes sprite animation");
    assert_eq!(ti.fields["sprite_index"], 144.0);
    park(&mut s, p);

    // The sprite frame follows the weapon level ladder: <=3 -> 0, 4-6 -> 1, 7-9 -> 2, >=10 -> 3.
    for (lvl, want) in [(2.0, 0.0), (3.0, 0.0), (4.0, 1.0), (6.0, 1.0),
                        (8.0, 2.0), (9.0, 2.0), (10.0, 3.0), (12.0, 3.0)] {
        let mut s = scene(&b);
        s.globals.insert("boomeranglevel".into(), lvl);
        let p = player(&mut s, &b, 0.0);
        let bt = s.create(&b, BOOMERANGTHROW, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&bt].fields["image_index"], want,
            "boomeranglevel {lvl} -> image_index {want}");
        park(&mut s, p);
    }
}

#[test]
fn boomerang_spins_back_to_the_player_after_thirty_frames() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0); // stays ACTIVE at (500,200)
    let bt = s.create(&b, BOOMERANGTHROW, 300.0, 200.0).unwrap();
    let mut returned = 0; let mut death = 0;
    for t in 1..=60 {
        s.tick(&b).unwrap();
        // per-frame re-pin: the player's own Step would drift the fixture
        {
            let i = s.instances.get_mut(&p).unwrap();
            i.fields.insert("x".into(), 500.0);
            i.fields.insert("y".into(), 200.0);
            i.fields.insert("hspeed".into(), 0.0);
            i.fields.insert("vspeed".into(), 0.0);
        }
        if returned == 0 && s.instances[&bt].fields.get("boomerangreturn") == Some(&1.0) {
            returned = t;
            assert_eq!(s.instances[&bt].fields["image_angle"], -1200.0,
                "image_angle spun -40/frame to -1200 at the turn");
        }
        if !s.instances[&bt].alive { death = t; break; }
    }
    assert_eq!(returned, 30, "CODE 296 fires at alarm[1]=30 and flags the return");
    assert!(death > 30, "the return flight continues until it reaches the player");
    assert!(death <= 40, "a straight chase at speed 5 catches the player quickly");
    // CODE 296: point_direction(player <- self) points the chase at the player;
    // pinned by the death tick above (the wave catches an active player).
}

#[test]
fn boomerang_hits_stun_and_pierce_until_caught() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let bt = s.create(&b, BOOMERANGTHROW, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, bt, 3, 0).expect("boomerang hit step");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], s.globals["boomerangdamage"]);
    assert_eq!(vi.fields["stunned"], 1.0);
    assert_eq!(vi.alarms[4], 10);
    assert!(s.instances[&bt].alive, "the boomerang pierces enemies");
    assert_eq!(s.globals["boomerangxp"], 1.0);
    assert_eq!(s.particles.len(), 2, "boomerang particle count is 2");
}

// ---- obj_energywave ---------------------------------------------------------

#[test]
fn energywave_is_a_piercing_constant_three_damage_wave() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    let ew = s.create(&b, ENERGYWAVE, 300.0, 200.0).unwrap();
    let ei = &s.instances[&ew];
    assert_eq!(ei.fields["hspeed"], -20.0, "CODE 304: facing 1 -> -20");
    assert_eq!(ei.alarms[1], 12, "CODE 304 alarm[1]=12 lifetime");
    assert_eq!(ei.fields["canhit"], 0.0);
    assert_eq!(audio(&s), vec![6], "CODE 304 plays snd 6 on create");
    park(&mut s, p);

    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let ew = s.create(&b, ENERGYWAVE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    // facing 0 -> +20
    assert_eq!(s.instances[&ew].fields["hspeed"], 20.0);
}

#[test]
fn energywave_hits_once_per_target_and_marks_every_hit_with_the_blast_sprite() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let ew = s.create(&b, ENERGYWAVE, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, ew, 3, 0).expect("ew hit");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], 3.0,
        "CODE 308 subtracts the CONSTANT 3 — not a global damage ladder");
    assert_eq!(vi.fields["stunned"], 1.0);
    assert_eq!(vi.alarms[4], 10);
    assert_eq!(s.instances[&ew].fields["canhit"], 1.0, "the latch closes after the first hit");
    assert_eq!(s.instances[&ew].alarms[0], 1,
        "every hit arms the wave's own alarm[0]=1 -> spr 50 swap next tick");
    let dmg = cast(&s, DAMAGE);
    assert_eq!(dmg.len(), 1);
    assert_eq!(s.instances[&dmg[0]].fields["damage"], 3.0,
        "the obj_damage float text carries the constant 3");

    // The latch survives into the next Step: same target, no second burn.
    s.dispatch(&b, ew, 3, 0).expect("ew second step");
    assert_eq!(s.instances[&v].fields["hpknife"], hp0 - 3.0,
        "canhit=1 blocks re-damage on the same wave");
}

#[test]
fn energywave_dies_after_twelve_frames_with_the_destroy_sound() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let ew = s.create(&b, ENERGYWAVE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let mut death = 0;
    for t in 1..=14 {
        s.tick(&b).unwrap();
        if !s.instances[&ew].alive { death = t; break; }
    }
    assert_eq!(death, 12, "CODE 306 kills the wave at alarm[1]=12");
    assert_eq!(audio(&s), vec![6, 18],
        "create plays snd 6; the Destroy event (CODE 305) plays snd 18");
}

#[test]
fn energywave_walls_only_swap_the_sprite_not_the_life() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let _w = s.create(&b, WALL, 320.0, 200.0).unwrap();
    let ew = s.create(&b, ENERGYWAVE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, ew, 3, 0).expect("ew wall step");
    assert_eq!(s.instances[&ew].alarms[0], 1, "the wall branch arms alarm[0]=1");
    s.tick(&b).unwrap();
    assert_eq!(s.instances[&ew].fields["sprite_index"], 50.0,
        "CODE 307 swaps to spr_bigexplosion on alarm[0]");
    assert!(s.instances[&ew].alive,
        "the wave is NOT destroyed by walls — the 12-frame timer owns its death");
}
