//! Boss battle batch on the IR scene host: obj_boss3 (27, CODE 171-186),
//! obj_boss4 (28, CODE 187-198) and obj_boss5 (29, CODE 199-214) — the three
//! arena bosses the room-branch contracts registered as behavior debts — plus
//! their projectiles obj_boss3projectile (55, CODE 335/336) and
//! obj_fireprojectile (54, CODE 333/334). boss1 (trex) and boss2 already have
//! contracts; this closes the boss roster through boss5 (finalboss excluded).
//! Every asserted value was observed from the real bytecode through scratch
//! probes on this host before being frozen; the static decode (including the
//! comparison-enum resolution: (words_raw & 0xFF00) >> 8 = 1..6 for
//! <,<=,==,!=,>=,>) is in reconstruction/contracts/bosses-3-5.md.
//!
//! Fixture discipline: the ranged/chase fixtures keep the player alive+active
//! (a parked player is invisible to distance_to_object — enemies-batch-2
//! lesson) and ground the actors with a wall whose sprite box covers y+1.
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const INIT: i32 = 103;
const BOSS3: i32 = 27;
const BOSS4: i32 = 28;
const BOSS5: i32 = 29;
const BOSS3PROJ: i32 = 55;
const FIREPROJ: i32 = 54;
const GHOST: i32 = 24;
const SWORD: i32 = 46;
const BOSSPUFF: i32 = 190;
const WALL: i32 = 4;
const GEM: i32 = 59;
const COIN: i32 = 60;
const XPORB: i32 = 61;

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
    freeze(s, p);
    p
}

fn freeze(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
    i.fields.insert("gravity".into(), 0.0);
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

// ---- obj_boss3 ----------------------------------------------------------------

#[test]
fn boss3_ladder_and_ring_schedule() {
    let b = bundle();
    // Create 171: pwr ladder, a9=400 (summon), a1=90 (ring seed), a11=60 (drift),
    // all inside the room != 110 gate; the ending room keeps the boss inert.
    for (pwr, want) in [(1.0, 850.0), (2.0, 800.0), (3.0, 725.0), (4.0, 600.0)] {
        let mut s = scene(&b);
        s.globals.insert("pwr".into(), pwr);
        let p = player(&mut s, &b, 500.0, 200.0);
        let bs = s.create(&b, BOSS3, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&bs].fields["hpboss3"], want,
            "CODE 171 pwr ladder: pwr {pwr} -> {want}");
        assert_eq!(s.instances[&bs].fields["boss3maxhp"], want,
            "the max-hp mirror field is written alongside");
        assert_eq!(s.instances[&bs].alarms[9], 400, "summon beat");
        assert_eq!(s.instances[&bs].alarms[1], 90, "ring seed beat");
        assert_eq!(s.instances[&bs].alarms[11], 60, "drift beat");
        assert_eq!(s.instances[&bs].fields["image_xscale"], -1.0,
            "boss3 starts flipped");
        park(&mut s, p);
    }
    // The ring through the REAL scheduler: first projectile at the 90-tick a1 beat.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let _g = s.create(&b, WALL, 300.0, 216.0).unwrap();
    let bs = s.create(&b, BOSS3, 300.0, 200.0).unwrap();
    let mut first = 0;
    for t in 1..=100 {
        let i = s.instances.get_mut(&p).unwrap();
        i.fields.insert("x".into(), 500.0);
        i.fields.insert("y".into(), 200.0);
        s.tick(&b).unwrap();
        if first == 0 && count(&s, BOSS3PROJ) > 0 { first = t; }
    }
    assert_eq!(first, 90, "CODE 183 fires the first ring projectile at the a1=90 beat");
    let dir = s.instances.values()
        .find(|x| x.object == BOSS3PROJ && x.alive)
        .map(|x| x.fields.get("direction").copied()).unwrap_or(None);
    assert!(dir.unwrap_or(-99.0).abs() <= 60.0,
        "boss3projectile Create picks one of 7 directions (60..-30)");
}

#[test]
fn boss3_summons_ghost_adds_under_the_cap_guards() {
    let b = bundle();
    // CODE 175 (A9): instance_number(obj_ghost) < 2 && instance_number(obj_slime) < 2
    // -> summon obj_ghost at (x-70, y) and (x+70, y); re-arm a9=200.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS3, 300.0, 200.0).unwrap();
    park(&mut s, p);
    assert_eq!(count(&s, GHOST), 0);
    s.dispatch(&b, bs, 2, 9).expect("summon");
    assert_eq!(count(&s, GHOST), 2, "the summon adds two ghosts at x∓70");
    assert_eq!(s.instances[&bs].alarms[9], 200, "the summon re-arms its own 200");
    // With 2 ghosts alive the strict < 2 guard blocks a second summon.
    s.dispatch(&b, bs, 2, 9).expect("summon blocked");
    assert_eq!(count(&s, GHOST), 2, "the cap guard keeps the add count at 2");
}

#[test]
fn boss3_death_clears_the_room_and_sprays() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS3, 300.0, 200.0).unwrap();
    // The Destroy event also kills any surviving projectiles (55).
    let stray = s.create(&b, BOSS3PROJ, 400.0, 150.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&bs).unwrap().fields.insert("hpboss3".into(), 0.0);
    s.dispatch(&b, bs, 3, 0).expect("step at hp 0");
    assert_eq!(s.instances[&bs].alarms[0], 1, "the Step arms the death beat");
    s.tick(&b).unwrap();
    assert!(!s.instances[&bs].alive);
    assert!(!s.instances[&stray].alive,
        "CODE 172's Destroy kills every obj_boss3projectile in the room");
    assert_eq!(s.globals["boss3dead"], 1.0);
    assert_eq!(count(&s, BOSSPUFF), 1);
    assert_eq!(count(&s, XPORB), 10, "the death drop sprays 10 XP orbs");
    assert_eq!(count(&s, COIN), 20, "and 20 coins");
    assert!(s.audio.iter().any(|a| a.sound == 50), "the death fanfare plays snd 50");
}

#[test]
fn boss3_projectiles_hit_parried_and_scatter() {
    let b = bundle();
    // Create 335: speed -5?? no — speed = -5 is the pre-choose default; direction =
    // choose(60,45,30,15,0,-15,-30). Step 336: player contact -> knock side by x
    // comparison, health1 -= 1, player a4/a7/a8 armed 10/22/25, projectile dies.
    // The knock-side chain is strict: x > player.x -> invulnerable/sliding1;
    // else x < player.x -> invulnerable2/sliding2; EXACT x overlap arms neither
    // flag (probe-proven at equal coordinates). Place the player off-axis.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 310.0, 200.0);
    let pr = s.create(&b, BOSS3PROJ, 300.0, 200.0).unwrap();
    let h0 = s.globals["health1"];
    s.dispatch(&b, pr, 3, 0).expect("hit step");
    assert_eq!(h0 - s.globals["health1"], 1.0, "the projectile costs one heart");
    assert!(!s.instances[&pr].alive, "and is consumed");
    let pi = &s.instances[&p];
    assert_eq!(pi.alarms[4], 10, "hit-invulnerability alarm");
    assert_eq!(pi.alarms[7], 22);
    assert_eq!(pi.alarms[8], 25);
    assert_eq!(pi.fields["invulnerable2"], 1.0,
        "proj.x < player.x takes the second knock side");
    assert_eq!(pi.fields["sliding2"], 1.0);
    assert!(s.audio.iter().any(|a| a.sound == 23), "impact sound");
    // Parry: the player's sword (46) intercepts -> obj_parry spark (12), both survive.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let sw = s.create(&b, SWORD, 300.0, 200.0).unwrap();
    let pr = s.create(&b, BOSS3PROJ, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, pr, 3, 0).expect("parry step");
    assert!(!s.instances[&pr].alive, "the projectile dies on the sword");
    assert_eq!(count(&s, 12), 1, "one obj_parry spark spawns");
    assert!(s.instances[&sw].alive, "the sword survives the parry");
}

// ---- obj_boss4 ------------------------------------------------------------------

#[test]
fn boss4_ladder_chase_and_the_swing_cycle() {
    let b = bundle();
    // Create 187: pwr ladder, chasing=1, a4=60 (chase resync), a3=30 (movelock),
    // a1=90 (pose cycle seed).
    for (pwr, want) in [(1.0, 950.0), (2.0, 900.0), (3.0, 825.0), (4.0, 700.0)] {
        let mut s = scene(&b);
        s.globals.insert("pwr".into(), pwr);
        let p = player(&mut s, &b, 500.0, 200.0);
        let bs = s.create(&b, BOSS4, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&bs].fields["hpboss4"], want, "pwr {pwr} -> {want}");
        assert_eq!(s.instances[&bs].fields["chasing"], 1.0, "boss4 starts chasing");
        assert_eq!(s.instances[&bs].alarms[4], 60);
        assert_eq!(s.instances[&bs].alarms[3], 30);
        assert_eq!(s.instances[&bs].alarms[1], 90);
        park(&mut s, p);
    }
    // Step 197: player within distance <= 100 -> swinging=1; the boss faces the
    // player (xscale by x comparison) and walks hspeed ∓2.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 380.0, 200.0); // 80 px away
    let _g = s.create(&b, WALL, 300.0, 216.0).unwrap();
    let bs = s.create(&b, BOSS4, 300.0, 200.0).unwrap();
    s.dispatch(&b, bs, 3, 0).expect("chase step");
    assert_eq!(s.instances[&bs].fields["swinging"], 1.0,
        "within 100 px the boss raises its guard (CODE 197 distance <= 100)");
    assert_eq!(s.instances[&bs].fields["hspeed"], -2.0,
        "the boss walks toward the player at 2 px/tick");
    assert_eq!(s.instances[&bs].fields["image_xscale"], -1.0, "facing the player");
    // A1 (195): swinging pose sprite 77 + a2=10; A2 (194): swing END spawns two
    // obj_fireprojectile (54) at (x±30, y-10), swinging back to 0.
    s.dispatch(&b, bs, 2, 1).expect("pose");
    assert_eq!(s.instances[&bs].fields["sprite_index"], 77.0);
    assert_eq!(s.instances[&bs].alarms[2], 10);
    s.dispatch(&b, bs, 2, 2).expect("swing end");
    assert_eq!(count(&s, FIREPROJ), 2, "the swing releases two fire projectiles");
    assert_eq!(s.instances[&bs].fields["swinging"], 0.0);
}

#[test]
fn boss4_death_fanfare_and_drop() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS4, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&bs).unwrap().fields.insert("hpboss4".into(), 0.0);
    s.dispatch(&b, bs, 3, 0).expect("step at hp 0");
    s.tick(&b).unwrap();
    assert!(!s.instances[&bs].alive);
    assert_eq!(s.globals["boss4dead"], 1.0);
    assert_eq!(count(&s, BOSSPUFF), 1);
    assert!(s.audio.iter().any(|a| a.sound == 49), "boss4's death fanfare is snd 49");
    assert_eq!(count(&s, GEM), 1);
    assert!(count(&s, COIN) >= 1);
}

// ---- obj_boss5 --------------------------------------------------------------------

#[test]
fn boss5_ladder_pursuit_and_facing_gated_burst() {
    let b = bundle();
    // Create 199: pwr ladder, a1=90 (burst chain seed), a11=70 (flank beat).
    for (pwr, want) in [(1.0, 1000.0), (2.0, 900.0), (3.0, 800.0), (4.0, 700.0)] {
        let mut s = scene(&b);
        s.globals.insert("pwr".into(), pwr);
        let p = player(&mut s, &b, 500.0, 200.0);
        let bs = s.create(&b, BOSS5, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&bs].fields["hpboss5"], want, "pwr {pwr} -> {want}");
        assert_eq!(s.instances[&bs].fields["boss5maxhp"], want);
        assert_eq!(s.instances[&bs].alarms[1], 90);
        assert_eq!(s.instances[&bs].alarms[11], 70);
        park(&mut s, p);
    }
    // Step 213: face the player (xscale), walk hspeed ±1 unless a wall stands
    // within 100 px on that side; facing follows the walk direction.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS5, 300.0, 200.0).unwrap();
    s.dispatch(&b, bs, 3, 0).expect("pursuit step");
    assert_eq!(s.instances[&bs].fields["hspeed"], 1.0,
        "boss5 advances at 1 px/tick when the lane is clear");
    assert_eq!(s.instances[&bs].fields["facing"], 1.0);
    assert_eq!(s.instances[&bs].fields["image_xscale"], 1.0);
    // A1 (211): facing-gated burst — one obj_fireprojectile at (x+50, y-5)
    // aimed at the player (CODE 333 point_direction + speed 8), snd 12, a2=10.
    s.dispatch(&b, bs, 2, 1).expect("burst");
    assert_eq!(count(&s, FIREPROJ), 1);
    let proj = s.instances.values().find(|x| x.object == FIREPROJ && x.alive).unwrap();
    assert_eq!(proj.fields["speed"], 8.0, "CODE 333 sets speed 8");
    assert!(proj.fields["direction"] > 300.0 && proj.fields["direction"] < 400.0,
        "the fire projectile aims at the player (right side ≈ 358°)");
    assert_eq!(s.instances[&bs].alarms[2], 10, "the burst chains to the next slot");
    assert!(s.audio.iter().any(|a| a.sound == 12));
}

#[test]
fn boss5_death_sets_the_flag_and_puffs() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS5, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&bs).unwrap().fields.insert("hpboss5".into(), 0.0);
    s.dispatch(&b, bs, 3, 0).expect("step at hp 0");
    s.tick(&b).unwrap();
    assert!(!s.instances[&bs].alive);
    assert_eq!(s.globals["boss5dead"], 1.0);
    assert_eq!(count(&s, BOSSPUFF), 1);
    assert_eq!(count(&s, XPORB), 10, "boss5's drop matches boss3's ten-orb spray");
}
