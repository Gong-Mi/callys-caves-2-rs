//! obj_iceblock (159) melting contract: Create CODE 687 pins melting=0 and
//! type=1 (a write-only field — no GML ever reads obj_iceblock.type), Step
//! CODE 688 decays both scales by 0.1/frame only once melting is set, and
//! Collision 35 (obj_flame) CODE 689 is the sole trigger, verified through
//! the live tick path, not a direct dispatch.
//!
//! The decay is a double chain, but CODE 688 compares `image_xscale` to zero
//! through DoSet K=3, whose recovered real comparison uses a ±1e-5 tolerance.
//! At tick 11 the tenth decrement leaves ~1.4e-16 (not exact zero), which
//! compares equal to zero and destroys the block. The previous strict-equality
//! / survival interpretation missed the shared DoSet tolerance. The flame that
//! started the melt dies via alarm[0]=9 (gone at tick 9) while melting persists.
//!
//! Fixture discipline: the player stays active until the flame exists
//! (CODE 268 reads obj_player.facing through the object selector, which
//! filters alive+active), then is parked; both are parked so nothing else
//! drifts mid-tick. Values are probe-measured, engine approximation is
//! bounding-box collision (same caveat as every batch).
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

const FLAME: i32 = 35;
const ICEBLOCK: i32 = 159;
const INIT: i32 = 103;
const P: i32 = 0;

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

#[test]
fn create_pins_melting_zero_and_dead_type_field() {
    let b = bundle();
    let mut s = scene(&b);
    let blk = s.create(&b, ICEBLOCK, 300., 200.).unwrap();
    assert_eq!(field(&s, blk, "melting"), 0., "CODE 687 melting=0");
    assert_eq!(field(&s, blk, "type"), 1., "CODE 687 type=1 (write-only field)");
    assert_eq!(field(&s, blk, "image_xscale"), 1.);
    assert_eq!(field(&s, blk, "image_yscale"), 1.);
    // Step without melting leaves both scales untouched (CODE 688 guard).
    s.dispatch(&b, blk, 3, 0).unwrap();
    assert_eq!(field(&s, blk, "image_xscale"), 1., "no melt, no decay");
    assert_eq!(field(&s, blk, "image_yscale"), 1.);
}

#[test]
fn flame_collision_over_live_tick_starts_the_melt() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 500., 200.).unwrap();
    let blk = s.create(&b, ICEBLOCK, 300., 200.).unwrap();
    let f = s.create(&b, FLAME, 300., 200.).unwrap();
    s.instances.get_mut(&p).unwrap().active = false;
    assert_eq!(field(&s, blk, "melting"), 0., "no melt before contact");
    s.tick(&b).unwrap();
    assert_eq!(field(&s, blk, "melting"), 1., "CODE 689 fired on live Collision 35");
    assert_eq!(field(&s, blk, "image_xscale"), 1., "tick-1 decay blocked by Step-before-Collision order");
    assert_eq!(field(&s, f, "image_xscale"), 1.1, "flame CODE 270 grows +0.1/frame");
    let _ = alive(&s, blk);
}

#[test]
fn melt_decays_then_do_set_equality_tolerance_destroys_block() {
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 500., 200.).unwrap();
    let blk = s.create(&b, ICEBLOCK, 300., 200.).unwrap();
    let f = s.create(&b, FLAME, 300., 200.).unwrap();
    s.instances.get_mut(&p).unwrap().active = false;
    // Step-before-Collision: tick 1 latches melting after Step. Ticks 2..10
    // apply nine subtractions and remain alive; the flame's alarm destroys it
    // at tick 9 while the melt continues.
    let expected: [f64; 10] = [
        1.0, 0.9, 0.8, 0.7000000000000001, 0.6000000000000001, 0.5000000000000001,
        0.40000000000000013, 0.30000000000000016, 0.20000000000000015, 0.10000000000000014,
    ];
    for t in 1..=10 {
        s.tick(&b).unwrap();
        assert_eq!(field(&s, blk, "melting"), 1., "melt latches at tick {t}");
        assert_eq!(field(&s, blk, "image_xscale"), expected[t - 1], "scale chain at tick {t}");
        assert_eq!(field(&s, blk, "image_yscale"), expected[t - 1], "yscale tracks xscale at tick {t}");
        assert!(alive(&s, blk), "block remains alive before near-zero comparison at tick {t}");
        assert_eq!(!alive(&s, f), t >= 9, "flame CODE 268 alarm[0]=9 -> CODE 269 destroy, counted live (t={t})");
    }

    // Tick 11 applies the tenth subtraction: xscale is positive, but within
    // DoSet K=3's recovered ±1e-5 equality tolerance, so CODE 688 destroys it.
    s.tick(&b).unwrap();
    let near_zero = field(&s, blk, "image_xscale");
    assert_eq!(near_zero, 1.3877787807814457e-16);
    assert_eq!(field(&s, blk, "image_yscale"), near_zero);
    assert!(near_zero.abs() <= 1e-5, "the value falls within DoSet's equality tolerance");
    assert!(!alive(&s, blk), "DoSet K=3 treats near-zero scale as equal to zero");
    assert!(!alive(&s, f), "the flame has already expired at tick 9");
}

#[test]
fn un_melted_block_outlives_every_scenario() {
    // Negative control: no flame, no melting — Step alone cannot shrink or
    // destroy the block over a long run.
    let b = bundle();
    let mut s = scene(&b);
    let p = s.create(&b, P, 500., 200.).unwrap();
    let blk = s.create(&b, ICEBLOCK, 300., 200.).unwrap();
    s.instances.get_mut(&p).unwrap().active = false;
    for _ in 1..=30 {
        s.tick(&b).unwrap();
    }
    assert_eq!(field(&s, blk, "melting"), 0.);
    assert_eq!(field(&s, blk, "image_xscale"), 1.);
    assert!(alive(&s, blk));
}
