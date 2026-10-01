//! obj_woodblock (158, parent par_wall) shattering contract, built from the
//! room72-75 cast note (woodblock quartet, first of the branch). Create
//! CODE 684 pins type=1 — a write-only field: no GML ever reads
//! obj_woodblock.type (grep over the full recovered corpus hits only the
//! blade Step and the two push-reject Alarm 1 files, none touching .type).
//! Collision 36 (obj_blade) CODE 686 is a bare instance_destroy; the blade
//! kills BOTH itself and the block through its Step scan (CODE 274's first
//! branch), not through a collision event — obj_blade has no Collision 158.
//! The Destroy (CODE 685) sprays six obj_logparts at fixed offsets and, if
//! soundmute==0, plays snd_explode (sond 7). Logparts (CODE 676/677/678)
//! draw sprite/scales/direction from choose(), fly at speed 7, and die at
//! alarm[0] — measured 31 live ticks.
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;

const BLADE: i32 = 36;
const WOOD: i32 = 158;
const LOGPARTS: i32 = 155;
const INIT: i32 = 103;
const P: i32 = 0;
const SND_EXPLODE: i32 = 7;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).unwrap()
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    let i = s.create(b, INIT, -1000., -1000.).unwrap();
    s.instances.get_mut(&i).unwrap().alive = false;
    s
}

fn field(s: &Scene, id: i32, name: &str) -> f64 {
    s.instances.get(&id).unwrap().fields[name]
}
fn alive(s: &Scene, id: i32) -> bool {
    s.instances.get(&id).map(|i| i.alive).unwrap_or(false)
}
fn logs(s: &Scene) -> Vec<i32> {
    s.instances.iter().filter(|(_, i)| i.object == LOGPARTS && i.alive).map(|(id, _)| *id).collect()
}

/// Player pinned to `facing`, blade created at (bx,by); the player must stay
/// active until the blade exists because CODE 271 reads obj_player.facing
/// through the object selector (alive+active filter).
fn throw_blade(b: &Bundle, s: &mut Scene, facing: f64, bx: f64, by: f64) -> i32 {
    let p = s.create(b, P, bx + 200., by).unwrap();
    s.write(p, -1, "facing", None, facing).unwrap();
    let blade = s.create(b, BLADE, bx, by).unwrap();
    s.instances.get_mut(&p).unwrap().active = false;
    blade
}

#[test]
fn create_pins_type_one_and_the_block_survives_without_a_blade() {
    let b = bundle();
    let mut s = scene(&b);
    let blk = s.create(&b, WOOD, 300., 200.).unwrap();
    assert_eq!(field(&s, blk, "type"), 1., "CODE 684 type=1 (write-only field)");
    for _ in 1..=5 { s.tick(&b).unwrap(); }
    assert!(alive(&s, blk), "no blade, no shatter over 5 ticks");
    assert_eq!(logs(&s).len(), 0, "logparts only exist after a shatter");
}

#[test]
fn blade_step_destroys_both_and_sprays_six_offset_logparts() {
    let b = bundle();
    let mut s = scene(&b);
    let blade = throw_blade(&b, &mut s, 1., 300., 200.);
    assert_eq!(field(&s, blade, "hspeed"), -20., "facing==1 -> hspeed -20 (CODE 271)");
    assert_eq!(s.instances[&blade].alarms[1], 40, "CODE 271 alarm[1]=40");
    let blk = s.create(&b, WOOD, 300., 200.).unwrap();
    assert_eq!(field(&s, blk, "type"), 1.);
    s.tick(&b).unwrap();
    assert!(!alive(&s, blk), "woodblock destroyed via blade Step CODE 274");
    assert!(!alive(&s, blade), "blade consumes itself in the same branch");
    let ls = logs(&s);
    assert_eq!(ls.len(), 6, "CODE 685 sprays exactly six logparts");
    let mut offs: Vec<(f64, f64)> = ls.iter()
        .map(|l| (field(&s, *l, "x") - 300., field(&s, *l, "y") - 200.))
        .collect();
    offs.sort_by(|a, b2| a.partial_cmp(b2).unwrap());
    let mut want: Vec<(f64, f64)> =
        vec![(0., -8.), (8., 0.), (-8., 0.), (0., 8.), (-8., 8.), (8., 8.)];
    want.sort_by(|a, b2| a.partial_cmp(b2).unwrap());
    assert_eq!(offs, want, "the six spawn offsets from CODE 685 verbatim");
    for l in &ls {
        assert_eq!(field(&s, *l, "speed"), 7., "CODE 676 speed=7");
        assert!([70., 110.].contains(&field(&s, *l, "direction")), "choose(70,110)");
        assert!([167., 168.].contains(&field(&s, *l, "sprite_index")), "spr_logstop/spr_logsbottom");
        assert!([1., -1.].contains(&field(&s, *l, "image_xscale")), "choose(1,-1)");
        assert!([1., -1.].contains(&field(&s, *l, "image_yscale")), "choose(1,-1)");
        assert_eq!(s.instances[l].alarms[0], 30, "CODE 676 alarm[0]=30 at spawn");
    }
    let sounds: Vec<i32> = s.audio.iter().map(|a| a.sound).collect();
    assert_eq!(sounds, vec![SND_EXPLODE], "CODE 685 plays snd_explode once, unmutated");
}

#[test]
fn facing_zero_mirrors_the_throw() {
    let b = bundle();
    let mut s = scene(&b);
    let blade = throw_blade(&b, &mut s, 0., 300., 200.);
    assert_eq!(field(&s, blade, "hspeed"), 20., "facing==0 -> hspeed +20");
}

#[test]
fn logparts_die_at_alarm_thirty_one_ticks_after_the_shatter() {
    let b = bundle();
    let mut s = scene(&b);
    let _blade = throw_blade(&b, &mut s, 1., 300., 200.);
    let blk = s.create(&b, WOOD, 300., 200.).unwrap();
    s.tick(&b).unwrap(); // shatter at tick 1; alarms read 30 after this tick
    assert_eq!(logs(&s).len(), 6);
    for t in 2..=30 {
        s.tick(&b).unwrap();
        assert_eq!(logs(&s).len(), 6, "six logs still alive at tick {t}");
        let want = 31 - t;
        for l in logs(&s) {
            assert_eq!(s.instances[&l].alarms[0], want, "alarm counts down every tick at {t}");
        }
    }
    s.tick(&b).unwrap(); // tick 31: alarm hits 0 -> CODE 677
    assert_eq!(logs(&s).len(), 0, "CODE 677 destroys the logs at tick 31");
}

#[test]
fn blade_times_out_at_alarm_40_in_the_open() {
    let b = bundle();
    let mut s = scene(&b);
    let blade = throw_blade(&b, &mut s, 0., 300., 200.);
    for t in 1..=39 {
        s.tick(&b).unwrap();
        assert!(alive(&s, blade), "blade alive at tick {t}");
    }
    s.tick(&b).unwrap(); // tick 40: alarm[1] reaches 0 -> CODE 272
    assert!(!alive(&s, blade), "CODE 272 destroys the blade at tick 40");
    assert_eq!(logs(&s).len(), 0, "no shatter without a woodblock");
}

#[test]
fn soundmute_suppresses_the_shatter_sound() {
    let b = bundle();
    let mut s = scene(&b);
    let _blade = throw_blade(&b, &mut s, 1., 300., 200.);
    let blk = s.create(&b, WOOD, 300., 200.).unwrap();
    // obj_player Create (CODE 0) writes global.soundmute=0, so the mute must
    // be applied AFTER every player creation in the fixture.
    s.globals.insert("soundmute".into(), 1.);
    s.tick(&b).unwrap();
    assert!(!alive(&s, blk), "the shatter still happens while muted");
    let sounds: Vec<i32> = s.audio.iter().map(|a| a.sound).collect();
    assert!(sounds.is_empty(), "CODE 685 takes the mute branch, no audio");
    assert_eq!(logs(&s).len(), 6, "debris unaffected by mute");
}
