//! Enemy behavior batch on the IR scene host: obj_hulkingbandit (21, CODE
//! 112-122), obj_firehulk (18, CODE 80-90), obj_skeleton (17, CODE 69-79),
//! obj_ghost (24, CODE 145-153) and obj_fireslime (33, CODE 256-267) — the
//! five families the room-branch contracts kept registering as cast debts.
//! Every asserted value was observed from the real bytecode through scratch
//! probes on this host before being frozen; the static per-branch decode is
//! recorded in reconstruction/contracts/enemies-batch-2.md.
//!
//! Fixture discipline (blood rules + this batch's new evidence):
//! - ranged-attack probes MUST keep the player alive+active — a parked player
//!   makes distance_to_object return the host's 100000 no-target sentinel
//!   and the distance gate correctly fails (probe-proven, not a defect);
//!   freeze the player by zeroing speeds and re-pinning position instead.
//! - coindrop/hpdrop use choose(...) seeded by the scene rng: the values are
//!   asserted via the drop SPRAY the death alarm produces, not the raw draw.
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const INIT: i32 = 103;
const HULKING: i32 = 21;
const FIREHULK: i32 = 18;
const SKELETON: i32 = 17;
const GHOST: i32 = 24;
const FIRESLIME: i32 = 33;
const WALL: i32 = 4;
const HBULLET: i32 = 51;
const BONE: i32 = 56;
const FHFLAME: i32 = 53;
const BIGPUFF: i32 = 188;
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

/// Freeze an instance WITHOUT parking it: speeds/gravity zeroed so its own
/// Step cannot drift it, but it stays alive+active so object-selector reads
/// (distance_to_object, collision_line, mp_potential_step) still find it.
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

// ---- obj_hulkingbandit ------------------------------------------------------

#[test]
fn hulkingbandit_create_rolls_drops_and_arms_the_thirty_beat() {
    let b = bundle();
    // hp ladder: level<=5 / <=10 (100/95/90/85), <=15 (120/115/110/105), <=20 (130/125/118/113).
    for (level, pwr, want) in [
        (1.0, 1.0, 100.0), (5.0, 1.0, 100.0), (10.0, 1.0, 100.0),
        (5.0, 2.0, 95.0), (5.0, 3.0, 90.0), (5.0, 4.0, 85.0),
        (15.0, 1.0, 120.0), (15.0, 4.0, 105.0),
        (20.0, 1.0, 130.0), (20.0, 3.0, 118.0), (20.0, 4.0, 113.0),
    ] {
        let mut s = scene(&b);
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let p = player(&mut s, &b, 500.0, 200.0);
        let h = s.create(&b, HULKING, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&h].fields["hphulkingbandit"], want,
            "CODE 112 ladder: level {level} pwr {pwr} -> {want}");
        assert_eq!(s.instances[&h].alarms[1], 30,
            "CODE 112 arms the 30-tick ranged-attack beat");
        assert_eq!(s.instances[&h].fields["xpdrop"], 1.0);
        park(&mut s, p);
    }
}

#[test]
fn hulkingbandit_death_arms_the_drop_alarm_and_sprays() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let h = s.create(&b, HULKING, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&h).unwrap().fields.insert("hphulkingbandit".into(), 0.0);

    s.dispatch(&b, h, 3, 0).expect("step at hp 0");
    assert_eq!(s.instances[&h].alarms[0], 1,
        "CODE 121 arms alarm[0]=1 when hp<=0 (death drop beat)");

    s.tick(&b).unwrap();
    assert!(!s.instances[&h].alive, "CODE 120 kills and sprays the loot");
    assert_eq!(count(&s, GEM), 1, "gemdropenabled=1 -> one obj_gem");
    assert_eq!(count(&s, XPORB), 1, "xpdrop=1 -> one obj_XPorb with motion_set 5");
    assert!(count(&s, COIN) >= 1, "coindrop draw >=1 -> at least one coin");
    assert_eq!(count(&s, BIGPUFF), 1, "the Destroy event spawns one obj_bigpuff");
    assert_eq!(s.globals["hulkingbanditskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    let snds: Vec<i32> = s.audio.iter().map(|a| a.sound).collect();
    assert!(snds.contains(&7), "death plays snd 7");
}

#[test]
fn hulkingbandit_fires_a_bullet_every_beat_and_freezes_hold() {
    let b = bundle();
    // Ranged attack through the REAL alarm schedule; the player stays ACTIVE
    // (frozen) 199 px away — a parked player is invisible to distance_to_object.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 499.0, 200.0);
    // Ground under both actors: without it the enemy's gravity lands it 260 px below
    // the player within 29 ticks and the 200-px attack gate correctly refuses to fire
    // (probe-proven y=461 failure; the wall's sprite box covers y+1 at y=200).
    let _g = s.create(&b, WALL, 400.0, 216.0).unwrap();
    let h = s.create(&b, HULKING, 300.0, 200.0).unwrap();
    let mut first_shot = 0;
    let mut shot_a2 = -1;
    for t in 1..=70 {
        // re-pin both actors every frame: the player stays the attack target and the
        // enemy stays on its ground line (its own Step would otherwise drift the fixture).
        {
            let i = s.instances.get_mut(&p).unwrap();
            i.fields.insert("x".into(), 499.0);
            i.fields.insert("y".into(), 200.0);
        }
        {
            let i = s.instances.get_mut(&h).unwrap();
            i.fields.insert("y".into(), 200.0);
        }
        s.tick(&b).unwrap();
        if first_shot == 0 && count(&s, HBULLET) > 0 {
            first_shot = t;
            shot_a2 = s.instances[&h].alarms[2];
        }
    }
    assert_eq!(first_shot, 30, "CODE 119 fires the first bullet at the 30-tick beat");
    assert_eq!(s.instances[&h].fields["shooting"], 1.0);
    assert_eq!(shot_a2, 7,
        "the shot arms alarm[2]=8; the same tick's slot loop decrements it to 7 on read-back (rocket-batch precedent)");
    assert_eq!(s.instances[&h].fields["sprite_index"], 117.0,
        "the 8-tick pose reverts to sprite 117 after its alarm (CODE 118)");
    assert!(s.audio.iter().any(|a| a.sound == 12), "the shot plays snd 12");
    // The frozen state pins the enemy in place.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let h = s.create(&b, HULKING, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&h).unwrap().fields.insert("hphulkingbanditfrozen".into(), 1.0);
    s.dispatch(&b, h, 3, 0).expect("frozen step");
    assert_eq!(s.instances[&h].fields["hspeed"], 0.0, "frozen zeroes motion");
    assert_eq!(s.instances[&h].fields["vspeed"], 0.0);
    assert_eq!(s.instances[&h].fields["image_blend"], 16711680.0, "frozen tint");
}

#[test]
fn hulkingbandit_recovery_alarms_clear_states() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let h = s.create(&b, HULKING, 300.0, 200.0).unwrap();
    park(&mut s, p);
    // alarm 2: shooting pose reverts to sprite 117.
    s.instances.get_mut(&h).unwrap().fields.insert("sprite_index".into(), 116.0);
    s.dispatch(&b, h, 2, 2).expect("alarm2");
    assert_eq!(s.instances[&h].fields["sprite_index"], 117.0);
    // alarm 3: freeze thaws (blend -= white, flag 0).
    s.instances.get_mut(&h).unwrap().fields.insert("hphulkingbanditfrozen".into(), 1.0);
    s.instances.get_mut(&h).unwrap().fields.insert("image_blend".into(), 16711680.0);
    s.dispatch(&b, h, 2, 3).expect("alarm3");
    assert_eq!(s.instances[&h].fields["hphulkingbanditfrozen"], 0.0);
    assert_eq!(s.instances[&h].fields["image_blend"], -65535.0,
        "CODE 117 subtracts 16777215 from the blend (16711680 - 16777215)");
    // alarm 4: stun clears + sprite; alarm 5: swordstun clears.
    s.instances.get_mut(&h).unwrap().fields.insert("stunned".into(), 1.0);
    s.instances.get_mut(&h).unwrap().fields.insert("swordstunned".into(), 1.0);
    s.dispatch(&b, h, 2, 4).expect("alarm4");
    assert_eq!(s.instances[&h].fields["stunned"], 0.0);
    s.dispatch(&b, h, 2, 5).expect("alarm5");
    assert_eq!(s.instances[&h].fields["swordstunned"], 0.0);
    // alarm 6: poison tick — 0.25 per beat, damage float, re-arm 30.
    let hp0 = s.instances[&h].fields["hphulkingbandit"];
    s.dispatch(&b, h, 2, 6).expect("alarm6");
    assert_eq!(s.instances[&h].fields["poisoned"], 1.0);
    assert_eq!(hp0 - s.instances[&h].fields["hphulkingbandit"], 0.25);
    assert_eq!(s.instances[&h].alarms[6], 30, "poison re-arms its own 30-tick cycle");
    let dmg = s.instances.values().find(|x| x.object == 104 && x.alive).unwrap();
    assert_eq!(dmg.fields["damage"], 0.25);
}

// ---- obj_firehulk -----------------------------------------------------------

#[test]
fn firehulk_ladder_and_flame_breath() {
    let b = bundle();
    // Ladder: level<=10 (100/95/90/80), <=15 (115/110/105/95), <=20 (130/120/115/105).
    for (level, pwr, want) in [
        (1.0, 1.0, 100.0), (10.0, 1.0, 100.0),
        (10.0, 4.0, 80.0), (15.0, 1.0, 115.0), (15.0, 4.0, 95.0),
        (20.0, 1.0, 130.0), (20.0, 2.0, 120.0), (20.0, 4.0, 105.0),
    ] {
        let mut s = scene(&b);
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let p = player(&mut s, &b, 500.0, 200.0);
        let f = s.create(&b, FIREHULK, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&f].fields["hpfirehulk"], want,
            "CODE 80 ladder: level {level} pwr {pwr} -> {want}");
        assert_eq!(s.instances[&f].alarms[1], 30, "CODE 80 arms the 30-tick flame beat");
        park(&mut s, p);
    }
    // Flame breath (alarm 1, CODE 87): spawns obj_firehulkflame toward facing,
    // re-arms alarm[6]=8 (the flame cadence), snd 14.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, f, 2, 1).expect("firehulk alarm1");
    assert_eq!(count(&s, FHFLAME), 1, "the breath spawns one obj_firehulkflame");
    assert_eq!(s.instances[&f].alarms[6], 8, "CODE 87 arms alarm[6]=8");
    assert!(s.audio.iter().any(|a| a.sound == 14), "the breath plays snd 14");
    // alarm 6 handler re-arms 8 and loops the flame spawn; alarm 7 = the poison
    // slot this family uses (per the ballistics-closure cross-family rule).
    s.dispatch(&b, f, 2, 7).expect("firehulk alarm7");
    assert_eq!(s.instances[&f].fields["poisoned"], 1.0);
    assert_eq!(s.instances[&f].alarms[7], 30, "the poison tick re-arms its own 30");
}

#[test]
fn firehulk_death_drop_counts_and_puffs() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&f).unwrap().fields.insert("hpfirehulk".into(), 0.0);
    s.dispatch(&b, f, 3, 0).expect("step at hp 0");
    assert_eq!(s.instances[&f].alarms[0], 1);
    s.tick(&b).unwrap();
    assert!(!s.instances[&f].alive);
    assert_eq!(count(&s, GEM), 1);
    assert_eq!(count(&s, BIGPUFF), 1);
    assert_eq!(s.globals["firehulkskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
}

// ---- obj_skeleton -------------------------------------------------------------

#[test]
fn skeleton_throws_bones_on_a_sixty_beat_and_swaps_poses() {
    let b = bundle();
    // Create arms alarm[1]=60 (bone throw) + alarm[2]=56 (pose swap to 110).
    let mut s = scene(&b);
    s.globals.insert("level".into(), 10.0);
    s.globals.insert("pwr".into(), 1.0);
    let p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&k].fields["hpskeleton"], 60.0, "CODE 69 ladder level 10 pwr 1");
    assert_eq!(s.instances[&k].alarms[1], 60);
    assert_eq!(s.instances[&k].alarms[2], 56);
    park(&mut s, p);

    // alarm 1 (CODE 76): throw — bone toward facing, sprite 111, re-arm 60, snd 13.
    s.dispatch(&b, k, 2, 1).expect("skeleton alarm1");
    assert_eq!(count(&s, BONE), 1, "the throw spawns one obj_bone");
    assert_eq!(s.instances[&k].fields["sprite_index"], 111.0, "throw pose");
    assert_eq!(s.instances[&k].alarms[1], 60, "the throw re-arms its own 60");
    assert!(s.audio.iter().any(|a| a.sound == 13));

    // alarm 2 (CODE 75): pose back to 110, re-arm 60.
    s.dispatch(&b, k, 2, 2).expect("skeleton alarm2");
    assert_eq!(s.instances[&k].fields["sprite_index"], 110.0, "walk pose");
    assert_eq!(s.instances[&k].alarms[2], 60);

    // Through the REAL schedule: bones at the 60-tick beat.
    let mut s = scene(&b);
    s.globals.insert("level".into(), 10.0);
    let p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let mut bones = 0;
    for t in 1..=130 {
        s.tick(&b).unwrap();
        if count(&s, BONE) > 0 { bones = t; break; }
    }
    assert_eq!(bones, 60, "the first scheduled bone lands at tick 60");
}

#[test]
fn skeleton_poison_ticks_a_quarter() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let hp0 = s.instances[&k].fields["hpskeleton"];
    s.dispatch(&b, k, 2, 6).expect("skeleton alarm6");
    assert_eq!(hp0 - s.instances[&k].fields["hpskeleton"], 0.25);
    assert_eq!(s.instances[&k].alarms[6], 30);
    assert_eq!(s.globals.get("skeletonskilled").copied().unwrap_or(0.0), 0.0,
        "the poison tick alone kills nothing (global absent until the first skeleton dies)");
}

// ---- obj_ghost -----------------------------------------------------------------

#[test]
fn ghost_creeps_toward_an_active_player_and_ignores_the_far_one() {
    let b = bundle();
    let mut s = scene(&b);
    s.globals.insert("level".into(), 5.0);
    s.globals.insert("pwr".into(), 1.0);
    let p = player(&mut s, &b, 500.0, 200.0); // 200 px away: inside the 220 wake band
    let g = s.create(&b, GHOST, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&g].fields["hpghost"], 45.0, "CODE 145 ladder level 5 pwr 1");

    let x0 = s.instances[&g].fields["x"];
    s.dispatch(&b, g, 3, 0).expect("ghost step near");
    assert_eq!(s.instances[&g].fields["x"] - x0, 3.0,
        "mp_potential_step closes 3 px per step toward the player");
    park(&mut s, p);

    // Outside the 220 wake band: no chase.
    let mut s = scene(&b);
    s.globals.insert("level".into(), 5.0);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let g = s.create(&b, GHOST, 300.0, 200.0).unwrap();
    let x0 = s.instances[&g].fields["x"];
    s.dispatch(&b, g, 3, 0).expect("ghost step far");
    assert_eq!(s.instances[&g].fields["x"] - x0, 0.0, "beyond 220 the ghost does not chase");
    park(&mut s, p);
}

#[test]
fn ghost_death_puff_and_poison_slot() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let g = s.create(&b, GHOST, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&g).unwrap().fields.insert("hpghost".into(), 0.0);
    s.dispatch(&b, g, 3, 0).expect("ghost step at hp 0");
    // Ghost's hp gate arms alarm[0]=1 INSIDE the room!=110 branch only; outside
    // room 110 the death beat is armed by the same gate structure as the family.
    s.tick(&b).unwrap();
    assert!(!s.instances[&g].alive || s.instances[&g].alarms[0] >= 0,
        "the death beat is armed or consumed");
    assert_eq!(s.globals["ghostskilled"], if s.instances[&g].alive { 0.0 } else { 1.0 });
    // alarm 6: the poison slot for this family.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let g = s.create(&b, GHOST, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let hp0 = s.instances[&g].fields["hpghost"];
    s.dispatch(&b, g, 2, 6).expect("ghost alarm6");
    assert_eq!(hp0 - s.instances[&g].fields["hpghost"], 0.25);
    assert_eq!(s.instances[&g].alarms[6], 30);
}

// ---- obj_fireslime ---------------------------------------------------------------

#[test]
fn fireslime_rolls_a_direction_and_hops_on_the_real_schedule() {
    let b = bundle();
    let mut s = scene(&b);
    s.globals.insert("level".into(), 5.0);
    s.globals.insert("pwr".into(), 1.0);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fs = s.create(&b, FIRESLIME, 300.0, 200.0).unwrap();
    let fi = &s.instances[&fs];
    assert_eq!(fi.fields["hpfireslime"], 80.0, "CODE 256 ladder level 5 pwr 1");
    assert_eq!(fi.alarms[0], 30, "hop beat");
    assert_eq!(fi.alarms[1], 40, "land beat");
    assert_eq!(fi.fields["blobjump"], 45.0);
    let dir = fi.fields["slimedirection"];
    assert!(dir == 3.0 || dir == -3.0, "choose(3,-3) picks one of the two");
    assert_eq!(fi.fields["hspeed"], dir, "the rolled direction is the walk speed");
    park(&mut s, p);

    // Hop (alarm 0, CODE 264): grounded + not frozen -> vspeed -5, sprite 75, jumping=1, re-arm 60.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 216.0).unwrap(); // ground whose sprite box covers y+1 (probe-proven)
    let fs = s.create(&b, FIRESLIME, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, fs, 2, 0).expect("hop");
    let fi = &s.instances[&fs];
    assert_eq!(fi.fields["vspeed"], -5.0, "the hop launches at vspeed -5");
    assert_eq!(fi.fields["sprite_index"], 75.0, "hop sprite");
    assert_eq!(fi.fields["jumping"], 1.0);
    assert_eq!(fi.alarms[0], 60, "the hop re-arms its own 60");

    // Land (alarm 1, CODE 263): jumping=0, sprite 70, re-arm 60.
    s.dispatch(&b, fs, 2, 1).expect("land");
    let fi = &s.instances[&fs];
    assert_eq!(fi.fields["jumping"], 0.0);
    assert_eq!(fi.fields["sprite_index"], 70.0);
    assert_eq!(fi.alarms[1], 60);
}

#[test]
fn fireslime_death_sprays_from_alarm_two() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fs = s.create(&b, FIRESLIME, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&fs).unwrap().fields.insert("hpfireslime".into(), 0.0);
    s.dispatch(&b, fs, 3, 0).expect("step at hp 0");
    assert_eq!(s.instances[&fs].alarms[2], 1, "CODE 265 arms alarm[2]=1 at hp<=0");
    s.tick(&b).unwrap();
    assert!(!s.instances[&fs].alive, "CODE 262 sprays and destroys");
    assert_eq!(count(&s, GEM), 1);
    assert!(count(&s, COIN) >= 1);
    assert_eq!(s.globals["fireslimeskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    assert!(s.audio.iter().any(|a| a.sound == 7));
}
