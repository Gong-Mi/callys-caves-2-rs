//! Weapon ballistics batch on the IR scene host: obj_iceball (40, CODE 285
//! fly / 286 hit), obj_spikegunspike (42, CODE 291 stick / 292+293 timeouts /
//! 294 hit-and-stop) and obj_rocket (44, CODE 299 launch / 300 boom sound /
//! 301 self-destruct / 302 explode swap / 303 single-hit flight). Every
//! asserted value was observed from the real bytecode through this host before
//! being frozen here.
//!
//! Fixture discipline (per the project hard rules): the player stays active
//! until the projectile exists (CODE 285/291/299 read obj_player.facing via
//! the object selector, which filters alive+active), then gets parked so its
//! own Step gravity/friction cannot drift the scene mid-tick; victims are
//! parked the same way so the tests exercise the bullet, not enemy AI.
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const P: i32 = 0;
const SPARK: i32 = 13;
const KNIFE: i32 = 15;
const WALL: i32 = 4;
const BOULDERBLOCK: i32 = 156;
const ICEBALL: i32 = 40;
const SPIKE: i32 = 42;
const ROCKET: i32 = 44;
const DAMAGE: i32 = 104;
const INIT: i32 = 103;
const SND_IMPACT2: i32 = 23; // snd_impactsound2
const SND_EXPLODE2: i32 = 8; // snd_explode2
const SPR_BIGEXPLOSION: i32 = 50;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    // Original initialization order: obj_pwrlevelinitialize seeds global.pwr
    // (which enemy Creates read for their hp ladder) and the particle types.
    let init = s.create(b, INIT, -1000.0, -1000.0).expect("initializer");
    s.instances.get_mut(&init).unwrap().alive = false; // ran once, keep inert
    s
}

fn player(s: &mut Scene, b: &Bundle, facing: f64) -> i32 {
    let p = s.create(b, P, 500.0, 200.0).expect("player");
    s.instances.get_mut(&p).unwrap().fields.insert("facing".into(), facing);
    p
}
/// Drop an instance from the tick set. Only for helpers that NO hit-testing
/// selector will ever look up again: `Scene::select` filters alive+active, so
/// parking a bullet's victim makes every `instance_place` miss it.
fn park(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.active = false;
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

fn knife(s: &mut Scene, b: &Bundle, x: f64, y: f64) -> i32 {
    let v = s.create(b, KNIFE, x, y).expect("knifebandit");
    v
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

// ---- obj_iceball -----------------------------------------------------------

#[test]
fn iceball_create_flips_speed_on_the_players_facing() {
    let b = bundle();
    for (facing, want) in [(1.0, -15.0), (0.0, 15.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let ball = s.create(&b, ICEBALL, 300.0, 200.0).unwrap();
        assert_eq!(s.instances[&ball].fields["hspeed"], want,
            "CODE 285: facing {facing} -> hspeed {want}");
        park(&mut s, p);
    }
}

#[test]
fn iceball_hit_freezes_one_enemy_then_dies() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let ball = s.create(&b, ICEBALL, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, ball, 3, 0).expect("iceball Step CODE 286");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], s.globals["icegundamage"],
        "hit applies exactly global.icegundamage once");
    assert_eq!(vi.fields["flashing"], 1.0);
    assert_eq!(vi.fields["hpfrozen"], 1.0, "the ice domain sets hpfrozen");
    assert_eq!(vi.alarms[3], 45, "CODE 286 arms the freeze alarm at 45");
    assert_eq!(vi.alarms[6], -1, "poisonenabled==0 must not arm alarm 6");
    assert!(!s.instances[&ball].alive, "the ball consumes itself on hit");
    assert_eq!(s.globals["icegunxp"], 1.0);
    assert_eq!(s.particles.len(), 2, "part_particles_create count is 2");
    assert_eq!(cast(&s, DAMAGE).len(), 1, "one obj_damage float text spawns");
    let sounds: Vec<i32> = s.audio.iter().map(|a| a.sound).collect();
    assert_eq!(sounds, vec![SND_IMPACT2], "soundmute==0 plays impactsound2 once");
}

#[test]
fn the_spike_arms_the_poison_alarm_when_enabled() {
    // CODE 286 (iceball) has NO poison branch at all (32 poison sites only
    // exist in CODE 294); the ice domain freezes via hpfrozen/alarm[3]
    // instead. Poison coverage therefore belongs to the spike family.
    let b = bundle();
    let mut s = scene(&b);
    s.globals.insert("poisonenabled".into(), 1.0);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 320.0, 200.0);
    let sp = s.create(&b, SPIKE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, sp, 3, 0).expect("spike Step CODE 294");
    assert_eq!(s.instances[&v].alarms[6], 1, "CODE 294 poison branch arms alarm 6 at 1");
    assert_eq!(s.instances[&v].fields.get("hpfrozen").copied().unwrap_or(0.0), 0.0,
        "spikes stun but never freeze");
}

#[test]
fn iceball_wall_branch_spawns_the_seven_frame_spark() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 1.0);
    let _wall = s.create(&b, WALL, 300.0, 200.0).unwrap();
    let ball = s.create(&b, ICEBALL, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, ball, 3, 0).expect("iceball Step CODE 286 wall branch");
    assert!(!s.instances[&ball].alive, "wall kills the ball before any enemy branch");
    let sparks = cast(&s, SPARK);
    assert_eq!(sparks.len(), 1);
    assert_eq!(s.instances[&sparks[0]].alarms[0], 7,
        "obj_bulletspark Create (CODE 38) arms alarm[0]=7");
}

// ---- obj_spikegunspike -----------------------------------------------------

#[test]
fn spike_create_mirrows_flips_and_arms_the_four_minute_timeout() {
    let b = bundle();
    for (facing, hsp, xs) in [(1.0, -14.0, -1.0), (0.0, 14.0, 1.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let sp = s.create(&b, SPIKE, 300.0, 200.0).unwrap();
        let si = &s.instances[&sp];
        assert_eq!(si.fields["hspeed"], hsp, "CODE 291: facing {facing} -> hspeed {hsp}");
        assert_eq!(si.fields["image_xscale"], xs, "CODE 291 mirrors the sprite");
        assert_eq!(si.fields["type"], 2.0, "a stuck spike is par_wall type 2");
        assert_eq!(si.alarms[1], 240, "CODE 291 alarm[1]=240");
        park(&mut s, p);
    }
}

#[test]
fn spike_timeout_alarm_self_destructs() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let sp = s.create(&b, SPIKE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    for _ in 0..239 { s.tick(&b).unwrap(); }
    assert!(s.instances[&sp].alive, "still stuck at frame 239");
    s.tick(&b).unwrap();
    assert!(!s.instances[&sp].alive, "CODE 292 destroys the spike at alarm 240");
}

#[test]
fn spike_hit_stuns_the_victim_and_the_impact_alarm_sticks_it() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 320.0, 200.0); // exactly x+hspeed(14) range probe +20
    let hp0 = s.instances[&v].fields["hpknife"];
    let sp = s.create(&b, SPIKE, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, sp, 3, 0).expect("spike Step CODE 294");
    let vi = &s.instances[&v];
    assert_eq!(hp0 - vi.fields["hpknife"], s.globals["spikegundamage"]);
    assert_eq!(vi.fields["stunned"], 1.0, "the spike stuns on hit");
    assert_eq!(vi.alarms[4], 10, "stun alarm 4 at 10");
    assert_eq!(s.instances[&sp].alarms[0], 1, "CODE 294 alarm[0]=1 after a hit");
    assert_eq!(s.globals["spikegunxp"], 1.0);
    assert_eq!(s.particles.len(), 3, "part count is 3 for the spike family");
    assert_eq!(cast(&s, DAMAGE).len(), 1);
    // The hit stops forward motion via the (x+hspeed) probes on later frames:
    // alarm[0] fires next tick and CODE 293 deletes the spike.
    s.tick(&b).unwrap();
    assert!(!s.instances[&sp].alive, "alarm[0]=1 -> CODE 293 instance_destroy");
}

#[test]
fn spike_stops_on_regular_wall_tiles_but_keeps_sticking() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    // wall sits at the next probe point x+hspeed=14
    let _wall = s.create(&b, WALL, 314.0, 200.0).unwrap();
    let sp = s.create(&b, SPIKE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, sp, 3, 0).expect("spike Step CODE 294 wall stop branch");
    let si = &s.instances[&sp];
    assert_eq!(si.fields["hspeed"], 0.0, "par_wall type != 3 zeroes hspeed");
    assert_eq!(si.fields["vspeed"], 0.0);
    assert!(si.alive, "wall stop is not destruction; the 240 timeout owns that");
    // With hspeed zeroed, a second probe finds no further wall: the spike stays.
    s.dispatch(&b, sp, 3, 0).expect("second Step");
    assert_eq!(s.instances[&sp].fields["hspeed"], 0.0);
}

// ---- obj_rocket ------------------------------------------------------------

#[test]
fn rocket_create_launches_and_arms_the_ten_frame_fuse() {
    let b = bundle();
    for (facing, want) in [(1.0, -16.0), (0.0, 16.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, facing);
        let r = s.create(&b, ROCKET, 300.0, 200.0).unwrap();
        let ri = &s.instances[&r];
        assert_eq!(ri.fields["hspeed"], want, "CODE 299: facing {facing} -> hspeed {want}");
        assert_eq!(ri.alarms[0], 10, "CODE 299 alarm[0]=10 fuse");
        assert_eq!(ri.fields["hitblock"], 0.0);
        assert_eq!(ri.fields["hitwall"], 0.0);
        assert_eq!(ri.fields["canhit"], 0.0);
        assert_eq!(ri.fields["hitboulder"], 0.0);
        park(&mut s, p);
    }
}

#[test]
fn rocket_hits_once_and_awards_xp_and_stun() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let v = knife(&mut s, &b, 300.0, 200.0);
    let hp0 = s.instances[&v].fields["hpknife"];
    let r = s.create(&b, ROCKET, 300.0, 200.0).unwrap();
    park(&mut s, p);

    s.dispatch(&b, r, 3, 0).expect("rocket Step CODE 303");
    assert_eq!(hp0 - s.instances[&v].fields["hpknife"], s.globals["rocketdamage"]);
    assert_eq!(s.instances[&v].fields["stunned"], 1.0);
    assert_eq!(s.instances[&v].alarms[4], 10);
    assert_eq!(s.instances[&r].fields["canhit"], 1.0, "the canhit latch closes");
    assert_eq!(s.instances[&r].fields["hitboulder"], 0.0, "boulder latch stays open");
    assert_eq!(s.instances[&r].alarms[0], 1, "impact arms the fuse for the explosion");
    assert_eq!(s.globals["rocketxp"], 1.0);
    assert_eq!(s.particles.len(), 2);
}

#[test]
fn rocket_blast_clears_boulderblocks_once() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let blk = s.create(&b, BOULDERBLOCK, 316.0, 200.0).unwrap(); // at x+hspeed=16
    let r = s.create(&b, ROCKET, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, r, 3, 0).expect("rocket Step CODE 303 boulder branch");
    assert!(!s.instances[&blk].alive, "with(hitblock) instance_destroy clears the block");
    assert_eq!(s.instances[&r].fields["hitboulder"], 1.0, "boulder latch consumes the blast");
    assert_eq!(s.instances[&r].alarms[0], 1, "hit arms the immediate fuse");
    // A second Step with the latch set must not re-trigger the destroy path.
    s.dispatch(&b, r, 3, 0).expect("second Step");
    assert_eq!(s.instances[&r].fields["hitboulder"], 1.0);
}

#[test]
fn rocket_full_lifecycle_explodes_then_destructs_with_boom() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 0.0);
    let r = s.create(&b, ROCKET, 300.0, 200.0).unwrap();
    park(&mut s, p);
    // Flight: 16 px/frame for 9 ticks, no explosion before the fuse expires.
    for t in 1..=9 {
        s.tick(&b).unwrap();
        let ri = &s.instances[&r];
        assert!(ri.alive, "still flying at {t}");
        assert_eq!(ri.fields["x"], 300.0 + 16.0 * t as f64, "flight at {t}");
        assert_eq!(ri.fields["sprite_index"], 43.0, "rocket sprite until the blast at {t}");
    }
    // Tick 10: alarm[0] hits zero -> CODE 302 swaps to the big explosion.
    s.tick(&b).unwrap();
    {
        let ri = &s.instances[&r];
        assert_eq!(ri.fields["hspeed"], 0.0, "CODE 302 stops the rocket");
        assert_eq!(ri.fields["vspeed"], 0.0);
        assert_eq!(ri.fields["sprite_index"], SPR_BIGEXPLOSION as f64, "swap to spr_bigexplosion");
        assert_eq!(ri.fields["image_index"], 1.0, "CODE 302 forces image_index=1");
        assert_eq!(ri.alarms[1], 17, "alarm[1]=18 was armed then decremented in-tick");
        assert!(ri.alive, "the blast sprite must play out");
    }
    // alarm[1] carries 17 into the next tick; 16 more ticks keep the blast
    // alive, tick 27 decrements it to zero -> CODE 301 destroys, CODE 300
    // plays snd_explode2 from the Destroy event.
    for t in 11..=26 {
        s.tick(&b).unwrap();
        assert!(s.instances[&r].alive, "blast still on screen at {t}");
    }
    assert_eq!(s.instances[&r].alarms[1], 1, "one frame of blast left");
    s.tick(&b).unwrap();
    assert!(!s.instances[&r].alive, "CODE 301 destroys at the end of the blast");
    let sounds: Vec<i32> = s.audio.iter().map(|a| a.sound).collect();
    assert_eq!(sounds, vec![SND_EXPLODE2], "Destroy (CODE 300) plays snd_explode2 once");
}
