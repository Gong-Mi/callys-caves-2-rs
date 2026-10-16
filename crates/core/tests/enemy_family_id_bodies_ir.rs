//! WL38 enemy-family id-level bodies, batch 1: the undead pair (obj_zombie 19
//! CODE 91-99, obj_skeleton 17 CODE 70-79), the fire family (obj_firehulk 18
//! CODE 81-90, obj_fireslime 33 CODE 257-267) and its two parry-able tail
//! projectiles (obj_firehulkflame 53 CODE 331/332, obj_bone 56 CODE 337/338).
//!
//! These 33 bodies were already EXECUTED by the earlier suites (zombie_skeleton_ir,
//! enemies2_batch_ir, projectile_tail_ir, entity_flashing_ir, room*_branch_ir);
//! the increment here is an id-level naming plus an explicit per-body behaviour
//! assertion, so each body leaves the census `object_cited_contract` tier with a
//! named test. Constants are taken from the bytecode IR (`full_ir.json`), never
//! from a guess at the recovered GML text: e.g. the thaw's `image_blend -=
//! c_white` is the raw 16777215 subtraction, and the frozen tint is the packed
//! GMS BGR constant 16711680 (c_blue).
//!
//! Fixture discipline (the blood rules + this batch's evidence):
//! - `scene()` wires the app's SPRT geometry (bounds + recorded bbox/masks) and
//!   runs the real room-start initializer obj_pwrlevelinitialize (obj 103) so
//!   `global.P_System`/`Particle1` exist for the two tail projectiles.
//! - The player is created and FROZEN (speeds zeroed, still active) whenever a
//!   body reads obj_player/`distance_to_object`: a parked (active=false) player
//!   reads as the host's 1e6 no-target sentinel.
//! - Step bodies are driven by direct `dispatch` so the asserted values are the
//!   body's own writes with no same-frame gravity/motion contamination; timers
//!   that re-arm themselves are additionally driven through the real `tick`
//!   schedule.
//! - obj_firehulkflame / obj_bone Create write `direction` + `speed` (the IR
//!   store), so the probe tests set hspeed/vspeed explicitly, exactly as
//!   projectile_tail_ir does.
//!
//! Scope: these are rewrite-side IR regression semantics (the IR scene host),
//! not an equivalence proof against the original runner.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const P: i32 = 0;
const WALL: i32 = 4;
const BOULDER: i32 = 6;
const PARRY: i32 = 12;
const SPARK: i32 = 13;
const SKELETON: i32 = 17;
const FIREHULK: i32 = 18;
const ZOMBIE: i32 = 19;
const FIRESLIME: i32 = 33;
const PAR_WALL: i32 = 34;
const SWORD: i32 = 46;
const FHFLAME: i32 = 53;
const BONE: i32 = 56;
const INIT: i32 = 103;
const DAMAGE: i32 = 104;
const DODGED: i32 = 106;
const SMALLPUFF: i32 = 187;
const BIGPUFF: i32 = 188;
const RM_ENDING: f64 = 110.0;
/// GMS packed BGR colours, straight from the IR constants.
const C_WHITE: f64 = 16777215.0;
const C_BLUE: f64 = 16711680.0;
const C_RED: f64 = 255.0;
const C_GREEN: f64 = 32768.0;
/// IR constants of the zombie/skeleton pose swaps.
const SPR_ZOMBIE_A: f64 = 107.0;
const SPR_ZOMBIE_B: f64 = 109.0;
const SPR_ZOMBIE_HURT: f64 = 108.0;
const SPR_SKELETON: f64 = 111.0;
const SPR_SKELETON_HURT: f64 = 112.0;
const SPR_FIREHULK: f64 = 119.0;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// The app's SPRT wiring: width/origin as sprite bounds, the recorded manual
/// bbox and the per-frame masks alongside. Without it every instance boxes as
/// its integer point and no collision probe below could be trusted.
fn wire_sprite_geometry(s: &mut Scene) {
    let asset = GameDroidAsset::parse(
        &Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid"),
    )
    .expect("parse game.droid");
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
        if let Some(bbox) = sp.bbox {
            s.sprite_bboxes.insert(*sid as i32, bbox);
        }
        if !sp.masks.is_empty() {
            s.sprite_masks.insert(*sid as i32, sp.masks.clone());
        }
    }
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    wire_sprite_geometry(&mut s);
    // Room-start initializer: seeds global.pwr and the particle handles.
    let init = s.create(b, INIT, -1000.0, -1000.0).expect("obj_pwrlevelinitialize");
    s.instances.get_mut(&init).unwrap().alive = false;
    s
}

/// Freeze WITHOUT parking: speeds/gravity zeroed so the instance cannot drift,
/// but alive+active so object selectors (obj_player reads, distance_to_object)
/// still find it.
fn player(s: &mut Scene, b: &Bundle, x: f64, y: f64) -> i32 {
    let p = s.create(b, P, x, y).expect("obj_player");
    freeze(s, p);
    p
}

fn freeze(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
    i.fields.insert("gravity".into(), 0.0);
}

fn set(s: &mut Scene, id: i32, name: &str, value: f64) {
    s.instances.get_mut(&id).unwrap().fields.insert(name.into(), value);
}

fn get(s: &Scene, id: i32, name: &str) -> f64 {
    s.instances[&id].fields.get(name).copied().unwrap_or(0.0)
}

fn pin(s: &mut Scene, id: i32, x: f64, y: f64) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("x".into(), x);
    i.fields.insert("y".into(), y);
}

fn count(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|x| x.object == object && x.alive).count()
}

/// Instances created by the body just dispatched.
fn spawned(s: &Scene, before: &[i32]) -> Vec<i32> {
    let mut v: Vec<i32> = s.instances.keys().copied().filter(|k| !before.contains(k)).collect();
    v.sort();
    v
}

/// The same `instance_place` the bodies use, boxed at the caller's own position
/// plus an offset — lets a fixture prove its own geometry instead of guessing.
fn probe(s: &mut Scene, b: &Bundle, id: i32, dx: f64, dy: f64, object: i32) -> bool {
    let (x, y) = (get(s, id, "x"), get(s, id, "y"));
    s.call(b, id, "instance_place", &[x + dx, y + dy, object as f64])
        .expect("instance_place") >= 0.0
}

// ---- obj_zombie (19) --------------------------------------------------------

// CODE 91 — obj_zombie Create_0
#[test]
fn zombie_create_ladder_and_default_state() {
    let b = bundle();
    // IR branch chain: level<=10 -> 60/56/52/45, <=15 -> 70/65/60/54,
    // <=20 -> 80/70/65/60 (pwr 1..4).
    for (level, pwr, want) in [
        (1.0, 1.0, 60.0), (10.0, 1.0, 60.0), (10.0, 4.0, 45.0),
        (15.0, 1.0, 70.0), (15.0, 4.0, 54.0), (20.0, 1.0, 80.0),
        (20.0, 3.0, 65.0), (20.0, 4.0, 60.0),
    ] {
        let mut s = scene(&b);
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let _p = player(&mut s, &b, 500.0, 200.0);
        let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
        assert_eq!(get(&s, z, "hpzombie"), want,
            "CODE 91 ladder: level {level} pwr {pwr} -> {want}");
    }
    let mut s = scene(&b);
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("pwr".into(), 1.0);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    let spr = get(&s, z, "zombiesprite");
    assert!(spr == SPR_ZOMBIE_A || spr == SPR_ZOMBIE_B,
        "CODE 91 chooses the sprite from {{107, 109}}, got {spr}");
    assert_eq!(get(&s, z, "sprite_index"), spr, "and latches it as sprite_index");
    assert_eq!(get(&s, z, "flashing"), 0.0);
    assert_eq!(get(&s, z, "poisoned"), 0.0);
    assert_eq!(get(&s, z, "swordstunned"), 0.0);
    assert_eq!(get(&s, z, "stunned"), 0.0);
    assert_eq!(get(&s, z, "chasing"), 0.0);
    assert_eq!(get(&s, z, "enemy1hsp"), 0.0);
    assert_eq!(get(&s, z, "falling"), 0.0);
    assert_eq!(get(&s, z, "facing"), 0.0);
    assert_eq!(get(&s, z, "xpdrop"), 1.0, "CODE 91 always drops experience");
    assert_eq!(get(&s, z, "hpzombiefrozen"), 0.0);
    let coin = get(&s, z, "coindrop");
    assert!((1.0..=5.0).contains(&coin) && coin.fract() == 0.0,
        "CODE 91 rolls coindrop from 1..5, got {coin}");
    let hp = get(&s, z, "hpdrop");
    assert!((0.0..=5.0).contains(&hp) && hp.fract() == 0.0,
        "CODE 91 rolls hpdrop from 0..5, got {hp}");
}

// CODE 92 — obj_zombie Destroy_0
#[test]
fn zombie_destroy_counts_and_sprays_the_puff_offset() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, z, 1, 0).expect("CODE 92 Destroy_0");
    assert_eq!(s.globals["zombieskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    let made = spawned(&s, &before);
    assert_eq!(made.len(), 1, "CODE 92 spawns exactly one puff");
    let puff = made[0];
    assert_eq!(s.instances[&puff].object, SMALLPUFF);
    assert_eq!((get(&s, puff, "x"), get(&s, puff, "y")), (300.0, 212.0),
        "CODE 92 spawns the puff at (x, y + 12) — the zombie's own offset");

    // The real death path reaches the same body: destroy() dispatches (1,0).
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    s.destroy(&b, z).expect("real destroy path");
    assert!(!s.instances[&z].alive);
    assert_eq!(s.globals["zombieskilled"], 1.0);
    assert_eq!(count(&s, SMALLPUFF), 1);
}

// CODE 93 — obj_zombie Alarm_6 (poison tick)
#[test]
fn zombie_alarm6_poison_tick_self_arms_thirty() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    let hp0 = get(&s, z, "hpzombie");
    s.dispatch(&b, z, 2, 6).expect("CODE 93 Alarm_6");
    assert_eq!(get(&s, z, "poisoned"), 1.0);
    assert_eq!(hp0 - get(&s, z, "hpzombie"), 0.25, "CODE 93 takes a quarter");
    assert_eq!(s.instances[&z].alarms[6], 30, "CODE 93 re-arms its own slot at 30");
    assert_eq!(count(&s, DAMAGE), 1, "CODE 93 spawns one obj_damage");
    let d = s.instances.values().find(|i| i.object == DAMAGE && i.alive).unwrap();
    assert_eq!(d.fields["damage"], 0.25, "and labels it 0.25");
    assert_eq!((d.fields["x"], d.fields["y"]), (300.0, 200.0));

    // The armed timer fires itself on the real schedule.
    s.instances.get_mut(&z).unwrap().alarms[6] = 1;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).expect("tick");
    assert_eq!(hp0 - get(&s, z, "hpzombie"), 0.5,
        "the poison ticked itself again on its own 30-tick timer");
    assert_eq!(s.instances[&z].alarms[6], 30, "and re-armed again");
}

// CODE 94 — obj_zombie Alarm_5
#[test]
fn zombie_alarm5_clears_swordstun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "swordstunned", 1.0);
    s.dispatch(&b, z, 2, 5).expect("CODE 94 Alarm_5");
    assert_eq!(get(&s, z, "swordstunned"), 0.0);
    assert_eq!(get(&s, z, "stunned"), 0.0, "CODE 94 touches nothing else");
}

// CODE 95 — obj_zombie Alarm_4
#[test]
fn zombie_alarm4_clears_stun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "stunned", 1.0);
    s.dispatch(&b, z, 2, 4).expect("CODE 95 Alarm_4");
    assert_eq!(get(&s, z, "stunned"), 0.0);
    assert_eq!(get(&s, z, "swordstunned"), 0.0);
}

// CODE 96 — obj_zombie Alarm_3 (thaw)
#[test]
fn zombie_alarm3_thaw_subtracts_white_and_clears_frozen() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "hpzombiefrozen", 1.0);
    set(&mut s, z, "image_blend", C_BLUE);
    s.dispatch(&b, z, 2, 3).expect("CODE 96 Alarm_3");
    assert_eq!(get(&s, z, "hpzombiefrozen"), 0.0);
    assert_eq!(get(&s, z, "image_blend"), C_BLUE - C_WHITE,
        "CODE 96 subtracts the raw c_white constant 16777215 from the blend");
    assert_eq!(C_BLUE - C_WHITE, -65535.0);
}

// CODE 98 — obj_zombie Step_0 (the chase / walk / facing head)
#[test]
fn zombie_step_chases_and_walks_by_facing() {
    let b = bundle();
    // Far player on the right: chasing latches, facing 0, walk +1.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    assert!(!probe(&mut s, &b, z, 5.0, -4.0, PAR_WALL), "fixture: no wall ahead");
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0");
    assert_eq!(get(&s, z, "chasing"), 1.0, "distance >= 50 wakes the chase");
    assert_eq!(get(&s, z, "facing"), 0.0);
    assert_eq!(get(&s, z, "image_xscale"), 1.0);
    assert_eq!(get(&s, z, "hspeed"), 1.0, "CODE 98 chases at +1");
    assert_eq!(get(&s, z, "gravity"), 0.6, "no par_wall under it: it falls");
    assert_eq!(get(&s, z, "falling"), 1.0);
    freeze(&mut s, p);

    // Far player on the left: facing 1, walk -1.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 100.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0");
    assert_eq!(get(&s, z, "chasing"), 1.0);
    assert_eq!(get(&s, z, "facing"), 1.0);
    assert_eq!(get(&s, z, "image_xscale"), -1.0);
    assert_eq!(get(&s, z, "hspeed"), -1.0, "CODE 98 chases at -1");

    // Player right on top of it: no chase, so the plain walk (3) stands.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 300.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0");
    assert_eq!(get(&s, z, "chasing"), 0.0, "inside 50 px the chase stays off");
    assert_eq!(get(&s, z, "facing"), 0.0, "facing is untouched by the near player");
    assert_eq!(get(&s, z, "hspeed"), 3.0, "CODE 98 walks at +3 when not chasing");
    assert_eq!(get(&s, z, "image_xscale"), 1.0);
}

// CODE 98 — obj_zombie Step_0 (hp gate, ground probe, state paints)
#[test]
fn zombie_step_hp_gate_ground_and_state_paints() {
    let b = bundle();
    // hp >= 0 clears the death beat, hp <= 0 arms it at 1.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    s.instances.get_mut(&z).unwrap().alarms[0] = 7;
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0");
    assert_eq!(s.instances[&z].alarms[0], 0, "CODE 98 clears alarm[0] while alive");
    set(&mut s, z, "hpzombie", 0.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 at hp 0");
    assert_eq!(s.instances[&z].alarms[0], 1, "CODE 98 arms the death beat at hp<=0");

    // A par_wall sharing the zombie's box zeroes gravity/vspeed; without one it falls.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 216.0).expect("floor wall");
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "vspeed", 4.0);
    assert!(probe(&mut s, &b, z, 0.0, 4.0, PAR_WALL), "fixture: the wall roofs (x, y+vspeed)");
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 grounded");
    assert_eq!(get(&s, z, "gravity"), 0.0);
    assert_eq!(get(&s, z, "vspeed"), 0.0, "CODE 98 zeroes the fall speed on contact");
    assert_eq!(get(&s, z, "falling"), 0.0);

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "vspeed", 4.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 airborne");
    assert_eq!(get(&s, z, "gravity"), 0.6);
    assert_eq!(get(&s, z, "vspeed"), 4.0, "the free-fall branch leaves vspeed alone");
    assert_eq!(get(&s, z, "falling"), 1.0);

    // A frozen zombie is pinned and tinted c_blue; otherwise c_white.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "hpzombiefrozen", 1.0);
    set(&mut s, z, "hspeed", 5.0);
    set(&mut s, z, "vspeed", 5.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 frozen");
    assert_eq!(get(&s, z, "image_blend"), C_BLUE);
    assert_eq!(get(&s, z, "hspeed"), 0.0);
    assert_eq!(get(&s, z, "vspeed"), 0.0);
    set(&mut s, z, "hpzombiefrozen", 0.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 thawed");
    assert_eq!(get(&s, z, "image_blend"), C_WHITE, "the else branch is c_white");

    // stun / sword-stun paint the hurt sprite; sword-stun also stops it dead.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    let spr = get(&s, z, "zombiesprite");
    set(&mut s, z, "stunned", 1.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 stunned");
    assert_eq!(get(&s, z, "sprite_index"), SPR_ZOMBIE_HURT);
    set(&mut s, z, "stunned", 0.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 recovered");
    assert_eq!(get(&s, z, "sprite_index"), spr, "the else restores zombiesprite");
    set(&mut s, z, "swordstunned", 1.0);
    set(&mut s, z, "hspeed", 5.0);
    set(&mut s, z, "vspeed", 5.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 sword-stunned");
    assert_eq!(get(&s, z, "sprite_index"), SPR_ZOMBIE_HURT);
    assert_eq!(get(&s, z, "hspeed"), 0.0);
    assert_eq!(get(&s, z, "vspeed"), 0.0);

    // Poison overrides the blend last; rm_ending freezes the walk.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    set(&mut s, z, "poisoned", 1.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 poisoned");
    assert_eq!(get(&s, z, "image_blend"), C_GREEN);
    s.current_room = RM_ENDING;
    set(&mut s, z, "hspeed", 3.0);
    s.dispatch(&b, z, 3, 0).expect("CODE 98 Step_0 in rm_ending");
    assert_eq!(get(&s, z, "hspeed"), 0.0, "room == 110 pins the walk");
    assert_eq!(get(&s, z, "vspeed"), 0.0);
}

// CODE 99 — obj_zombie Draw_0 (hit-flash fog pipeline)
#[test]
fn zombie_draw_flashes_white_fog_and_clears_flashing() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let z = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    let spr = get(&s, z, "sprite_index");
    set(&mut s, z, "flashing", 1.0);
    s.dispatch(&b, z, 8, 0).expect("CODE 99 Draw_0");
    let draws: Vec<_> = s.draws.iter().filter(|d| d.instance == z).cloned().collect();
    assert_eq!(draws.len(), 1, "CODE 99 draws the zombie exactly once");
    assert_eq!(draws[0].code, 99, "the recorded draw comes from CODE 99");
    assert!(draws[0].fog, "flashing draws through the d3d_set_fog(true, ...) wrapper");
    assert_eq!(draws[0].color, C_WHITE as i32, "with the c_white fog colour");
    assert_eq!(draws[0].sprite, spr as i32, "and its own sprite_index");
    assert_eq!(get(&s, z, "flashing"), 0.0, "CODE 99 clears flashing on the way out");
    assert!(!s.fog_enabled, "the wrapper restores the fog state");

    let n = s.draws.len();
    s.dispatch(&b, z, 8, 0).expect("CODE 99 Draw_0 calm");
    let draws: Vec<_> = s.draws[n..].iter().filter(|d| d.instance == z).cloned().collect();
    assert_eq!(draws.len(), 1, "the flashing==0 branch also draws exactly once");
    assert!(!draws[0].fog, "no fog wrapper when not flashing");
    assert_eq!(draws[0].color, C_WHITE as i32, "the plain draw carries image_blend");
    assert_eq!(draws[0].code, 99);
}

// ---- obj_skeleton (17) ------------------------------------------------------

// CODE 70 — obj_skeleton Destroy_0
#[test]
fn skeleton_destroy_counts_and_puff_at_origin() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, k, 1, 0).expect("CODE 70 Destroy_0");
    assert_eq!(s.globals["skeletonskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    let made = spawned(&s, &before);
    assert_eq!(made.len(), 1);
    assert_eq!(s.instances[&made[0]].object, SMALLPUFF);
    assert_eq!((get(&s, made[0], "x"), get(&s, made[0], "y")), (300.0, 200.0),
        "CODE 70 has no y offset — one puff exactly on the bones");
}

// CODE 71 — obj_skeleton Alarm_6 (poison tick)
#[test]
fn skeleton_alarm6_poison_tick_self_arms_thirty() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    let hp0 = get(&s, k, "hpskeleton");
    s.dispatch(&b, k, 2, 6).expect("CODE 71 Alarm_6");
    assert_eq!(get(&s, k, "poisoned"), 1.0);
    assert_eq!(hp0 - get(&s, k, "hpskeleton"), 0.25);
    assert_eq!(s.instances[&k].alarms[6], 30);
    let d = s.instances.values().find(|i| i.object == DAMAGE && i.alive).unwrap();
    assert_eq!(d.fields["damage"], 0.25);
    s.instances.get_mut(&k).unwrap().alarms[6] = 1;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).expect("tick");
    assert_eq!(hp0 - get(&s, k, "hpskeleton"), 0.5,
        "CODE 71's own 30-tick timer fires again through the scheduler");
    assert_eq!(s.instances[&k].alarms[6], 30);
}

// CODE 72 — obj_skeleton Alarm_5
#[test]
fn skeleton_alarm5_clears_swordstun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    set(&mut s, k, "swordstunned", 1.0);
    s.dispatch(&b, k, 2, 5).expect("CODE 72 Alarm_5");
    assert_eq!(get(&s, k, "swordstunned"), 0.0);
}

// CODE 73 — obj_skeleton Alarm_4
#[test]
fn skeleton_alarm4_clears_stun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    set(&mut s, k, "stunned", 1.0);
    s.dispatch(&b, k, 2, 4).expect("CODE 73 Alarm_4");
    assert_eq!(get(&s, k, "stunned"), 0.0);
}

// CODE 74 — obj_skeleton Alarm_3 (thaw)
#[test]
fn skeleton_alarm3_thaw_subtracts_white_and_clears_frozen() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    set(&mut s, k, "hpskeletonfrozen", 1.0);
    set(&mut s, k, "image_blend", C_BLUE);
    s.dispatch(&b, k, 2, 3).expect("CODE 74 Alarm_3");
    assert_eq!(get(&s, k, "hpskeletonfrozen"), 0.0);
    assert_eq!(get(&s, k, "image_blend"), C_BLUE - C_WHITE);
}

// CODE 78 — obj_skeleton Step_0 (hp gate, walk, invulnerability gate, mask)
#[test]
fn skeleton_step_hp_gate_walk_and_invulnerable_stop() {
    let b = bundle();
    // hp gate arms/clears the death beat.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    s.instances.get_mut(&k).unwrap().alarms[0] = 7;
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0");
    assert_eq!(s.instances[&k].alarms[0], 0);
    set(&mut s, k, "hpskeleton", 0.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 at hp 0");
    assert_eq!(s.instances[&k].alarms[0], 1);

    // facing drives the walk; mask_index is pinned unconditionally.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 facing 0");
    assert_eq!(get(&s, k, "hspeed"), 3.0, "facing 0 walks +3");
    assert_eq!(get(&s, k, "image_xscale"), 1.0);
    assert_eq!(get(&s, k, "mask_index"), SPR_SKELETON, "CODE 78 pins the mask");
    set(&mut s, k, "facing", 1.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 facing 1");
    assert_eq!(get(&s, k, "hspeed"), -3.0, "facing 1 walks -3");
    assert_eq!(get(&s, k, "image_xscale"), -1.0);

    // A player inside 50 px that is invulnerable stops the walk dead.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 vs plain player");
    assert_eq!(get(&s, k, "hspeed"), 3.0, "a vulnerable player does not stop it");
    set(&mut s, p, "invulnerable", 1.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 vs invulnerable player");
    assert_eq!(get(&s, k, "hspeed"), 0.0,
        "CODE 78 stops the walk at the invulnerable player inside 50 px");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 1.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 vs sliding player");
    assert_eq!(get(&s, k, "hspeed"), 0.0, "invulnerable2 gates it too");

    // Poison, rm_ending and the ground probe.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    set(&mut s, k, "poisoned", 1.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 poisoned");
    assert_eq!(get(&s, k, "image_blend"), C_GREEN);
    set(&mut s, k, "hspeed", 3.0);
    s.current_room = RM_ENDING;
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 rm_ending");
    assert_eq!(get(&s, k, "hspeed"), 0.0, "rm_ending stops the bones");
    assert_eq!(get(&s, k, "vspeed"), 0.0);
    assert_eq!(get(&s, k, "sprite_index"), SPR_SKELETON, "rm_ending restores the pose");

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 216.0).expect("floor wall");
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    assert!(probe(&mut s, &b, k, 0.0, 1.0, PAR_WALL), "fixture: par_wall under the feet");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 grounded");
    assert_eq!(get(&s, k, "gravity"), 0.0, "CODE 78 grounds on par_wall at (x, y+1)");
    assert_eq!(get(&s, k, "vspeed"), 0.0);
    assert_eq!(get(&s, k, "falling"), 0.0);

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    set(&mut s, k, "vspeed", 4.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 airborne");
    assert_eq!(get(&s, k, "gravity"), 0.6);
    assert_eq!(get(&s, k, "falling"), 1.0);
    assert_eq!(get(&s, k, "vspeed"), 4.0);
}

// CODE 78 — obj_skeleton Step_0 (wall/boulder probes, ledge walk, hurt poses)
#[test]
fn skeleton_step_wall_probes_ledges_and_hurt_poses() {
    let b = bundle();
    // Wall 10 px right and 4 px up flips the facing to 1.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    // Half-width wall at (x+4, y-24): the (x+10, y-4) probe box (301..322 x
    // 179..220) reaches its 304..320 x 176..208 body, while the mirrored
    // (x-10, y-4) box (281..302) and the (x, y+27) ledge box (210..251) miss it.
    let w = s.create(&b, WALL, 304.0, 176.0).expect("wall ahead (right)");
    set(&mut s, w, "image_xscale", 0.5);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    assert!(probe(&mut s, &b, k, 10.0, -4.0, WALL), "fixture: wall reachable at (x+10, y-4)");
    assert!(!probe(&mut s, &b, k, -10.0, -4.0, WALL), "fixture: the mirrored probe is clear");
    assert!(!probe(&mut s, &b, k, 0.0, 27.0, WALL), "fixture: the ledge probe is clear too");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0");
    assert_eq!(get(&s, k, "facing"), 1.0,
        "CODE 78 turns right when obj_wall/obj_boulder sits at (x+10, y-4) but not at (x-10, y-4)");

    // Boulder 10 px left and 4 px up flips it back to 0.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let w = s.create(&b, BOULDER, 278.0, 176.0).expect("boulder ahead (left)");
    set(&mut s, w, "image_xscale", 0.5);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    assert!(probe(&mut s, &b, k, -10.0, -4.0, BOULDER), "fixture: boulder reachable at (x-10, y-4)");
    assert!(!probe(&mut s, &b, k, 10.0, -4.0, BOULDER), "fixture: the mirrored probe is clear");
    assert!(!probe(&mut s, &b, k, 0.0, 27.0, BOULDER), "fixture: the ledge probe is clear too");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0");
    assert_eq!(get(&s, k, "facing"), 0.0,
        "CODE 78 turns left on obj_boulder too — both classes feed the probe");

    // Ledge rule: with nothing at (x+27, y+27) and a floor at (x, y+27) it
    // steps right. The floor is scaled to half width (the original scales
    // instances the same way) so the (x+27) probe provably clears it.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    // One full-width block at (x-30, y+35) covers 270..302 x 235..267: the
    // (x, y+27) ledge box (210..251) and the mirrored (x-26, y+27) box
    // (265..286) both reach it, the (x+27, y+27) box (318..339) does not, and
    // its y band sits below the (x+/-10, y-4) walk boxes (179..220).
    let _w = s.create(&b, WALL, 270.0, 235.0).expect("narrow ledge + left-rule blocker");
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    assert!(!probe(&mut s, &b, k, 27.0, 27.0, WALL), "fixture: nothing at (x+27, y+27)");
    assert!(probe(&mut s, &b, k, 0.0, 27.0, WALL), "fixture: floor reachable at (x, y+27)");
    assert!(probe(&mut s, &b, k, -26.0, 27.0, WALL), "fixture: the left ledge branch is blocked");
    assert!(!probe(&mut s, &b, k, 10.0, -4.0, WALL), "fixture: the walk probe is clear");
    assert!(!probe(&mut s, &b, k, -10.0, -4.0, WALL), "fixture: the mirrored walk probe too");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 ledge right");
    assert_eq!(get(&s, k, "facing"), 1.0,
        "CODE 78 steps onto the ledge in front instead of walking off it");

    // Mirrored: the floor sits under the left probe's shadow -> facing 0.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 298.0, 235.0).expect("narrow ledge + right-rule blocker");
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    assert!(!probe(&mut s, &b, k, -26.0, 27.0, WALL), "fixture: nothing at (x-26, y+27)");
    assert!(probe(&mut s, &b, k, 0.0, 27.0, WALL), "fixture: floor reachable at (x, y+27)");
    assert!(probe(&mut s, &b, k, 27.0, 27.0, WALL), "fixture: the right ledge branch is blocked");
    assert!(!probe(&mut s, &b, k, -10.0, -4.0, WALL), "fixture: the walk probe is clear");
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 ledge left");
    assert_eq!(get(&s, k, "facing"), 0.0);

    // Hurt poses: stun (no else - the pose simply stays) and sword-stun.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    set(&mut s, k, "stunned", 1.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 stunned");
    assert_eq!(get(&s, k, "sprite_index"), SPR_SKELETON_HURT);
    set(&mut s, k, "stunned", 0.0);
    set(&mut s, k, "swordstunned", 1.0);
    set(&mut s, k, "hspeed", 5.0);
    set(&mut s, k, "vspeed", 5.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 78 Step_0 sword-stunned");
    assert_eq!(get(&s, k, "sprite_index"), SPR_SKELETON_HURT);
    assert_eq!(get(&s, k, "hspeed"), 0.0);
    assert_eq!(get(&s, k, "vspeed"), 0.0);
}

// CODE 79 — obj_skeleton Draw_0
#[test]
fn skeleton_draw_flashes_white_fog_and_clears_flashing() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    let spr = get(&s, k, "sprite_index");
    set(&mut s, k, "flashing", 1.0);
    s.dispatch(&b, k, 8, 0).expect("CODE 79 Draw_0");
    let draws: Vec<_> = s.draws.iter().filter(|d| d.instance == k).cloned().collect();
    assert_eq!(draws.len(), 1);
    assert_eq!(draws[0].code, 79);
    assert!(draws[0].fog);
    assert_eq!(draws[0].color, C_WHITE as i32);
    assert_eq!(draws[0].sprite, spr as i32);
    assert_eq!(get(&s, k, "flashing"), 0.0);
    assert!(!s.fog_enabled);
    let n = s.draws.len();
    s.dispatch(&b, k, 8, 0).expect("CODE 79 Draw_0 calm");
    let draws: Vec<_> = s.draws[n..].iter().filter(|d| d.instance == k).cloned().collect();
    assert_eq!(draws.len(), 1);
    assert!(!draws[0].fog, "the flashing==0 branch draws without the fog wrapper");
}

// ---- obj_firehulk (18) ------------------------------------------------------

// CODE 81 — obj_firehulk Destroy_0
#[test]
fn firehulk_destroy_counts_and_sprays_bigpuff() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, f, 1, 0).expect("CODE 81 Destroy_0");
    assert_eq!(s.globals["firehulkskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    let made = spawned(&s, &before);
    assert_eq!(made.len(), 1);
    assert_eq!(s.instances[&made[0]].object, BIGPUFF,
        "CODE 81 is the big-puff family (188), unlike the undead pair");
    assert_eq!((get(&s, made[0], "x"), get(&s, made[0], "y")), (300.0, 200.0));
}

// CODE 83 — obj_firehulk Alarm_6
#[test]
fn firehulk_alarm6_restores_its_own_sprite() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "sprite_index", 0.0);
    s.dispatch(&b, f, 2, 6).expect("CODE 83 Alarm_6");
    assert_eq!(get(&s, f, "sprite_index"), SPR_FIREHULK,
        "CODE 83 pins sprite_index back to spr_firehulk (119)");
}

// CODE 84 — obj_firehulk Alarm_5
#[test]
fn firehulk_alarm5_clears_swordstun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "swordstunned", 1.0);
    s.dispatch(&b, f, 2, 5).expect("CODE 84 Alarm_5");
    assert_eq!(get(&s, f, "swordstunned"), 0.0);
}

// CODE 85 — obj_firehulk Alarm_4
#[test]
fn firehulk_alarm4_clears_stun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "stunned", 1.0);
    s.dispatch(&b, f, 2, 4).expect("CODE 85 Alarm_4");
    assert_eq!(get(&s, f, "stunned"), 0.0);
}

// CODE 86 — obj_firehulk Alarm_3 (thaw)
#[test]
fn firehulk_alarm3_thaw_subtracts_white_and_clears_frozen() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "hpfirehulkfrozen", 1.0);
    set(&mut s, f, "image_blend", C_BLUE);
    s.dispatch(&b, f, 2, 3).expect("CODE 86 Alarm_3");
    assert_eq!(get(&s, f, "hpfirehulkfrozen"), 0.0);
    assert_eq!(get(&s, f, "image_blend"), C_BLUE - C_WHITE);
}

// CODE 89 — obj_firehulk Step_0 (hp gate, ground, walk, tint ladder)
#[test]
fn firehulk_step_gates_walk_and_tint_ladder() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    s.instances.get_mut(&f).unwrap().alarms[0] = 7;
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0");
    assert_eq!(s.instances[&f].alarms[0], 0, "CODE 89 clears the death beat while alive");
    set(&mut s, f, "hpfirehulk", 0.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 at hp 0");
    assert_eq!(s.instances[&f].alarms[0], 1, "CODE 89 arms it at hp<=0");

    // Facing drives a slower walk than the skeleton's (+/-2).
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 facing 0");
    assert_eq!(get(&s, f, "hspeed"), 2.0);
    set(&mut s, f, "facing", 1.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 facing 1");
    assert_eq!(get(&s, f, "hspeed"), -2.0);
    // image_xscale is not asserted here: CODE 89's tail re-mirrors to the
    // player's side after the walk branches, so only the player-side rule is
    // observable (see firehulk_step_wall_probes_ledges_and_player_side).

    // The ground probe sits at (x, y+2) for this family.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 217.0).expect("floor wall");
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    assert!(probe(&mut s, &b, f, 0.0, 2.0, PAR_WALL), "fixture: par_wall at (x, y+2)");
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 grounded");
    assert_eq!(get(&s, f, "gravity"), 0.0);
    assert_eq!(get(&s, f, "falling"), 0.0);

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    let fz = s.instances[&f].fields["sprite_index"];
    let _ = fz;
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 airborne");
    assert_eq!(get(&s, f, "gravity"), 0.6);
    assert_eq!(get(&s, f, "falling"), 1.0);

    // Tint ladder: frozen c_blue, stun/sword-stun c_red, poison c_green last.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "hpfirehulkfrozen", 1.0);
    set(&mut s, f, "hspeed", 5.0);
    set(&mut s, f, "vspeed", 5.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 frozen");
    assert_eq!(get(&s, f, "image_blend"), C_BLUE);
    assert_eq!(get(&s, f, "hspeed"), 0.0);
    assert_eq!(get(&s, f, "vspeed"), 0.0);
    set(&mut s, f, "hpfirehulkfrozen", 0.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 thawed");
    assert_eq!(get(&s, f, "image_blend"), C_WHITE);

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "stunned", 1.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 stunned");
    assert_eq!(get(&s, f, "image_blend"), C_RED,
        "the firehulk stun tint is c_red (255), not the undead pair's sprite swap");
    set(&mut s, f, "stunned", 0.0);
    set(&mut s, f, "swordstunned", 1.0);
    set(&mut s, f, "hspeed", 5.0);
    set(&mut s, f, "vspeed", 5.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 sword-stunned");
    assert_eq!(get(&s, f, "image_blend"), C_RED);
    assert_eq!(get(&s, f, "hspeed"), 0.0);
    assert_eq!(get(&s, f, "vspeed"), 0.0);

    // Poison is painted last, so it wins over every other tint.
    set(&mut s, f, "swordstunned", 0.0);
    set(&mut s, f, "hpfirehulkfrozen", 1.0);
    set(&mut s, f, "poisoned", 1.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 poisoned");
    assert_eq!(get(&s, f, "image_blend"), C_GREEN);

    // rm_ending pins it.
    s.current_room = RM_ENDING;
    set(&mut s, f, "hspeed", 2.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 rm_ending");
    assert_eq!(get(&s, f, "hspeed"), 0.0);
    assert_eq!(get(&s, f, "vspeed"), 0.0);
}

// CODE 89 — obj_firehulk Step_0 (wall probes, 50 px ledges, player-side mirror)
#[test]
fn firehulk_step_wall_probes_ledges_and_player_side() {
    let b = bundle();
    // obj_wall at (x+5, y) turns it right.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    // The firehulk boxes 261..339 x 175..251, so the (x+5, y) and (x-5, y)
    // probe boxes differ only at the edges: a quarter-width sliver at (x+34, y)
    // covers 334..342 and is reachable only by the right-hand probe. The low
    // blocker kills the (x-50, y+27) ledge branch without touching the walk.
    let w = s.create(&b, WALL, 334.0, 200.0).expect("wall right");
    set(&mut s, w, "image_xscale", 0.25);
    let _blk = s.create(&b, BOULDER, 250.0, 252.0).expect("blocks the left ledge branch");
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    assert!(probe(&mut s, &b, f, 5.0, 0.0, WALL), "fixture: wall reachable at (x+5, y)");
    assert!(!probe(&mut s, &b, f, -5.0, 0.0, WALL), "fixture: the mirrored probe is clear");
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0");
    assert_eq!(get(&s, f, "facing"), 1.0, "CODE 89 turns right on a wall at (x+5, y)");

    // obj_boulder at (x-5, y) turns it left.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let w = s.create(&b, BOULDER, 258.0, 200.0).expect("boulder left");
    set(&mut s, w, "image_xscale", 0.25);
    let _blk = s.create(&b, WALL, 300.0, 252.0).expect("blocks the right ledge branch");
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    assert!(probe(&mut s, &b, f, -5.0, 0.0, BOULDER), "fixture: boulder reachable at (x-5, y)");
    assert!(!probe(&mut s, &b, f, 5.0, 0.0, BOULDER), "fixture: the mirrored probe is clear");
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0");
    assert_eq!(get(&s, f, "facing"), 0.0, "CODE 89 turns left on an obj_boulder");

    // The 50 px ledge rule. A narrow floor under its own feet with nothing at
    // (x+50, y+27) makes it step right; the mirror makes it step left.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    // One full-width block at (x-30, y+52) covers 270..302 x 252..284: the
    // (x, y+27) and (x-50, y+27) ledge boxes (202..278) reach it, the
    // (x+50, y+27) box (311..389) does not, and its y band sits below the
    // (x+/-5, y) walk boxes (175..251).
    let _w = s.create(&b, WALL, 270.0, 252.0).expect("floor + left-rule blocker");
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    assert!(!probe(&mut s, &b, f, 50.0, 27.0, WALL), "fixture: nothing at (x+50, y+27)");
    assert!(probe(&mut s, &b, f, 0.0, 27.0, WALL), "fixture: floor reachable at (x, y+27)");
    assert!(probe(&mut s, &b, f, -50.0, 27.0, WALL), "fixture: the left ledge branch is blocked");
    assert!(!probe(&mut s, &b, f, 5.0, 0.0, WALL), "fixture: the walk probe is clear");
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 ledge right");
    assert_eq!(get(&s, f, "facing"), 1.0,
        "CODE 89 walks onto a 50 px ledge instead of off it");

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 298.0, 252.0).expect("floor + right-rule blocker");
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    assert!(!probe(&mut s, &b, f, -50.0, 27.0, WALL), "fixture: nothing at (x-50, y+27)");
    assert!(probe(&mut s, &b, f, 0.0, 27.0, WALL), "fixture: floor reachable at (x, y+27)");
    assert!(probe(&mut s, &b, f, 50.0, 27.0, WALL), "fixture: the right ledge branch is blocked");
    assert!(!probe(&mut s, &b, f, -5.0, 0.0, WALL), "fixture: the walk probe is clear");
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 ledge left");
    assert_eq!(get(&s, f, "facing"), 0.0);

    // The last word on image_xscale is the player's side, not `facing`.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "image_xscale", 1.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 player right");
    assert_eq!(get(&s, f, "image_xscale"), 1.0, "player to the right mirrors right");
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 100.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    set(&mut s, f, "image_xscale", 1.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 89 Step_0 player left");
    assert_eq!(get(&s, f, "image_xscale"), -1.0,
        "CODE 89 always faces the player regardless of its walk facing");
}

// CODE 90 — obj_firehulk Draw_0
#[test]
fn firehulk_draw_flashes_white_fog_and_clears_flashing() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    let spr = get(&s, f, "sprite_index");
    set(&mut s, f, "flashing", 1.0);
    s.dispatch(&b, f, 8, 0).expect("CODE 90 Draw_0");
    let draws: Vec<_> = s.draws.iter().filter(|d| d.instance == f).cloned().collect();
    assert_eq!(draws.len(), 1);
    assert_eq!(draws[0].code, 90);
    assert!(draws[0].fog);
    assert_eq!(draws[0].color, C_WHITE as i32);
    assert_eq!(draws[0].sprite, spr as i32);
    assert_eq!(get(&s, f, "flashing"), 0.0);
    assert!(!s.fog_enabled);
}

// ---- obj_fireslime (33) -----------------------------------------------------

// CODE 257 — obj_fireslime Destroy_0
#[test]
fn fireslime_destroy_counts_and_sprays_the_puff() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, r, 1, 0).expect("CODE 257 Destroy_0");
    assert_eq!(s.globals["fireslimeskilled"], 1.0);
    assert_eq!(s.globals["enemieskilled"], 1.0);
    let made = spawned(&s, &before);
    assert_eq!(made.len(), 1);
    assert_eq!(s.instances[&made[0]].object, SMALLPUFF,
        "the burning blob uses the small puff, like the plain one");
    assert_eq!((get(&s, made[0], "x"), get(&s, made[0], "y")), (300.0, 200.0));
}

// CODE 258 — obj_fireslime Alarm_6 (poison tick)
#[test]
fn fireslime_alarm6_poison_tick_self_arms_thirty() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    let hp0 = get(&s, r, "hpfireslime");
    s.dispatch(&b, r, 2, 6).expect("CODE 258 Alarm_6");
    assert_eq!(get(&s, r, "poisoned"), 1.0);
    assert_eq!(hp0 - get(&s, r, "hpfireslime"), 0.25);
    assert_eq!(s.instances[&r].alarms[6], 30);
    let d = s.instances.values().find(|i| i.object == DAMAGE && i.alive).unwrap();
    assert_eq!(d.fields["damage"], 0.25);
    s.instances.get_mut(&r).unwrap().alarms[6] = 1;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).expect("tick");
    assert_eq!(hp0 - get(&s, r, "hpfireslime"), 0.5,
        "CODE 258's own 30-tick timer fires again through the scheduler");
    assert_eq!(s.instances[&r].alarms[6], 30);
}

// CODE 259 — obj_fireslime Alarm_5
#[test]
fn fireslime_alarm5_clears_swordstun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    set(&mut s, r, "swordstunned", 1.0);
    s.dispatch(&b, r, 2, 5).expect("CODE 259 Alarm_5");
    assert_eq!(get(&s, r, "swordstunned"), 0.0);
}

// CODE 260 — obj_fireslime Alarm_4
#[test]
fn fireslime_alarm4_clears_stun() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    set(&mut s, r, "stunned", 1.0);
    s.dispatch(&b, r, 2, 4).expect("CODE 260 Alarm_4");
    assert_eq!(get(&s, r, "stunned"), 0.0);
}

// CODE 261 — obj_fireslime Alarm_3 (thaw)
#[test]
fn fireslime_alarm3_thaw_subtracts_white_and_clears_frozen() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    set(&mut s, r, "hpfireslimefrozen", 1.0);
    set(&mut s, r, "image_blend", C_BLUE);
    s.dispatch(&b, r, 2, 3).expect("CODE 261 Alarm_3");
    assert_eq!(get(&s, r, "hpfireslimefrozen"), 0.0);
    assert_eq!(get(&s, r, "image_blend"), C_BLUE - C_WHITE);
}

// CODE 266 — obj_fireslime Collision_34
#[test]
fn fireslime_collision34_bounces_both_axes() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 200.0).expect("overlapping par_wall");
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    set(&mut s, r, "hspeed", 3.0);
    set(&mut s, r, "vspeed", -5.0);
    s.dispatch(&b, r, 4, 34).expect("CODE 266 Collision_34");
    assert_eq!(get(&s, r, "hspeed"), -3.0, "CODE 266's action_bounce(0, 0) flips hspeed");
    assert_eq!(get(&s, r, "vspeed"), 5.0, "and vspeed");
    assert!(s.instances[&r].alive, "a bounce is not a destroy");

    // Through the real event pass on a tick, with the fireslime's own Step body
    // held off the walk: a quarter-width wall on the LEFT cannot be
    // reached by the (x+5, y-2) probe, so the Step leaves hspeed = +1 and the
    // only body that can flip it is CODE 266 in the collision pass.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    // The blob boxes 281..317 x 207..232: a quarter-width sliver at (278, 210)
    // covers 278..286 x 210..242, which the (x+5, y-2) probe box (286..322) just
    // misses at its left edge while the blob's own box overlaps it.
    let w = s.create(&b, WALL, 278.0, 210.0).expect("sliver par_wall");
    set(&mut s, w, "image_xscale", 0.25);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    set(&mut s, r, "hspeed", 1.0);
    set(&mut s, r, "gravity", 0.0);
    assert!(!probe(&mut s, &b, r, 5.0, -2.0, PAR_WALL), "fixture: the +5 walk probe is clear");
    assert!(probe(&mut s, &b, r, 0.0, 0.0, PAR_WALL), "fixture: the boxes still overlap");
    s.tick(&b).expect("tick");
    assert_eq!(get(&s, r, "hspeed"), -1.0,
        "the event pass really reaches CODE 266 for a par_wall overlap");
}

// CODE 267 — obj_fireslime Draw_0
#[test]
fn fireslime_draw_flashes_white_fog_and_clears_flashing() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let r = s.create(&b, FIRESLIME, 300.0, 200.0).expect("obj_fireslime");
    let spr = get(&s, r, "sprite_index");
    set(&mut s, r, "flashing", 1.0);
    s.dispatch(&b, r, 8, 0).expect("CODE 267 Draw_0");
    let draws: Vec<_> = s.draws.iter().filter(|d| d.instance == r).cloned().collect();
    assert_eq!(draws.len(), 1);
    assert_eq!(draws[0].code, 267);
    assert!(draws[0].fog);
    assert_eq!(draws[0].color, C_WHITE as i32);
    assert_eq!(draws[0].sprite, spr as i32);
    assert_eq!(get(&s, r, "flashing"), 0.0);
    assert!(!s.fog_enabled);
}

// ---- obj_firehulkflame (53) -------------------------------------------------

// CODE 331 — obj_firehulkflame Create_0
#[test]
fn firehulkflame_create_aims_at_the_player() {
    let b = bundle();
    // Player straight to the right: direction 0 (GMS counter-clockwise).
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 400.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    assert_eq!(get(&s, f, "direction"), 0.0, "CODE 331 aims through point_direction");
    assert_eq!(get(&s, f, "speed"), 6.0, "CODE 331 sets speed 6");

    // Player below: direction 270.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 300.0, 300.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    assert_eq!(get(&s, f, "direction"), 270.0);

    // Player above-left: 135.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 200.0, 100.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    assert_eq!(get(&s, f, "direction"), 135.0);
}

// CODE 332 — obj_firehulkflame Step_0
#[test]
fn firehulkflame_step_sword_wall_and_player_branches() {
    let b = bundle();
    // Sword at the next position: half-scale puff + obj_parry, flame consumed.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    set(&mut s, f, "hspeed", 1.0);
    set(&mut s, f, "vspeed", 0.0);
    let _sw = s.create(&b, SWORD, 301.0, 200.0).expect("obj_sword");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 parried");
    assert!(!s.instances[&f].alive, "the sword consumes the flame");
    let made = spawned(&s, &before);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == SMALLPUFF).count(), 1);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == PARRY).count(), 1);
    let puff = made.iter().find(|i| s.instances[i].object == SMALLPUFF).unwrap();
    assert_eq!(get(&s, *puff, "image_xscale"), 0.5, "CODE 332 halves the puff");
    assert_eq!(get(&s, *puff, "image_yscale"), 0.5);

    // par_wall at its own position: half-scale puff, no parry, consumed.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 200.0).expect("par_wall");
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 wall");
    assert!(!s.instances[&f].alive);
    let made = spawned(&s, &before);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == SMALLPUFF).count(), 1);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == PARRY).count(), 0,
        "the wall branch leaves no parry spark");

    // Player hit: lives -2, flash, three player alarms, particles, consumed.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    let _ = f;
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    let hp0 = s.globals["health1"];
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 player hit");
    assert!(!s.instances[&f].alive, "the flame dies on contact");
    assert_eq!(get(&s, p, "flashing"), 1.0);
    assert_eq!(s.globals["health1"], hp0 - 2.0, "CODE 332 takes two lives");
    assert_eq!(s.instances[&p].alarms[7], 22);
    assert_eq!(s.instances[&p].alarms[4], 10);
    assert_eq!(s.instances[&p].alarms[8], 25);
    assert!(s.audio.iter().any(|a| a.sound == 23 && !a.looping),
        "CODE 332 plays snd_impactsound2 (23) when soundmute is off");
    assert_eq!(s.particles.len(), 4, "CODE 332 sprays four particles at the player");
    assert!(s.globals.get("P_System").is_some(), "fixture: the initializer ran");

    // The side of the contact picks the knockback slot.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 299.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 hit from the right");
    assert_eq!(get(&s, p, "invulnerable"), 1.0, "x > player.x knocks it left");
    assert_eq!(get(&s, p, "sliding1"), 1.0);
    assert_eq!(get(&s, p, "invulnerable2"), 0.0);

    let mut s = scene(&b);
    let p = player(&mut s, &b, 301.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 hit from the left");
    assert_eq!(get(&s, p, "invulnerable2"), 1.0, "x < player.x knocks it right");
    assert_eq!(get(&s, p, "sliding2"), 1.0);
    assert_eq!(get(&s, p, "invulnerable"), 0.0);

    // Invulnerable player: the damage branch is gated off entirely.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    set(&mut s, p, "invulnerable", 1.0);
    let hp0 = s.globals["health1"];
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 vs invulnerable player");
    assert!(s.instances[&f].alive, "no contact branch fires");
    assert_eq!(s.globals["health1"], hp0);
    assert_eq!(get(&s, p, "flashing"), 0.0);
}

// CODE 332 — obj_firehulkflame Step_0 (the rebuff dodge branch)
#[test]
fn firehulkflame_step_rebuff_dodge_spawns_obj_dodged() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let f = s.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    s.globals.insert("rebuff".into(), 1.0);
    s.dispatch(&b, f, 3, 0).expect("CODE 332 Step_0 rebuff");
    assert!(s.instances[&f].alive, "the rebuff branch does not consume the flame");
    assert_eq!(count(&s, DODGED), 1, "CODE 332 spawns obj_dodged on the dodge");
    let d = s.instances.values().find(|i| i.object == DODGED && i.alive).unwrap();
    assert_eq!((d.fields["x"], d.fields["y"]), (300.0, 190.0),
        "the dodge marker sits 10 px above the player");
    // A second contact while one already exists spawns nothing more.
    let mut s2 = scene(&b);
    let _p2 = player(&mut s2, &b, 300.0, 200.0);
    let f2 = s2.create(&b, FHFLAME, 300.0, 200.0).expect("obj_firehulkflame");
    s2.globals.insert("rebuff".into(), 1.0);
    let _existing = s2.create(&b, DODGED, 0.0, 0.0).expect("obj_dodged");
    s2.dispatch(&b, f2, 3, 0).expect("CODE 332 Step_0 rebuff again");
    assert_eq!(count(&s2, DODGED), 1, "instance_exists gates the second spawn");
    let _ = (p, f);
}

// ---- obj_bone (56) ----------------------------------------------------------

// CODE 337 — obj_bone Create_0
#[test]
fn bone_create_aims_at_the_player() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 400.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    assert_eq!(get(&s, k, "direction"), 0.0, "CODE 337 aims through point_direction");
    assert_eq!(get(&s, k, "speed"), 6.0, "CODE 337 sets speed 6");

    let mut s = scene(&b);
    let _p = player(&mut s, &b, 200.0, 300.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    assert_eq!(get(&s, k, "direction"), 225.0);
}

// CODE 338 — obj_bone Step_0 (sword / wall / spin)
#[test]
fn bone_step_sword_wall_and_spin() {
    let b = bundle();
    // Sword ahead: obj_parry, no puff, consumed.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    set(&mut s, k, "hspeed", 1.0);
    set(&mut s, k, "vspeed", 0.0);
    let _sw = s.create(&b, SWORD, 301.0, 200.0).expect("obj_sword");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 parried");
    assert!(!s.instances[&k].alive);
    let made = spawned(&s, &before);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == PARRY).count(), 1);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == SMALLPUFF).count(), 0,
        "the bone's parry leaves no puff (the flame's does)");

    // par_wall at its own position: obj_bulletspark, consumed.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 200.0).expect("par_wall");
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 wall");
    assert!(!s.instances[&k].alive);
    assert_eq!(spawned(&s, &before).iter()
        .filter(|i| s.instances[i].object == SPARK).count(), 1,
        "CODE 338 leaves obj_bulletspark (13) on the wall, not a puff");

    // The spin: image_angle -= 40 every step (no collision in the way).
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 spin 1");
    assert_eq!(get(&s, k, "image_angle"), -40.0, "CODE 338 spins 40 degrees per step");
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 spin 2");
    assert_eq!(get(&s, k, "image_angle"), -80.0);

    // The tail rule: within 1 px of a par_wall it dies -- but not before.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    let far = s.call(&b, k, "distance_to_object", &[PAR_WALL as f64]).unwrap();
    assert!(far > 1.0, "fixture: no par_wall near yet (distance {far})");
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 clear");
    assert!(s.instances[&k].alive, "a clear bone keeps flying");
}

// CODE 338 — obj_bone Step_0 (player contact and the rebuff dodge)
#[test]
fn bone_step_player_contact_and_rebuff() {
    let b = bundle();
    // Contact with an undefended player: one life, flash, alarms, particles.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    let hp0 = s.globals["health1"];
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 player hit");
    assert!(!s.instances[&k].alive, "the bone breaks on the player");
    assert_eq!(get(&s, p, "flashing"), 1.0);
    assert_eq!(s.globals["health1"], hp0 - 1.0,
        "CODE 338 takes one life (the flame takes two)");
    assert_eq!(s.instances[&p].alarms[7], 22);
    assert_eq!(s.instances[&p].alarms[4], 10);
    assert_eq!(s.instances[&p].alarms[8], 25);
    assert!(s.audio.iter().any(|a| a.sound == 23 && !a.looping));
    assert_eq!(s.particles.len(), 4);

    // Contact from the right knocks the player left, and vice versa.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 299.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 hit from the right");
    assert_eq!(get(&s, p, "invulnerable"), 1.0);
    assert_eq!(get(&s, p, "sliding1"), 1.0);

    // An invulnerable player takes nothing.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    set(&mut s, p, "invulnerable", 1.0);
    let hp0 = s.globals["health1"];
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 vs invulnerable player");
    assert!(s.instances[&k].alive);
    assert_eq!(s.globals["health1"], hp0);

    // Rebuff: it drops an obj_dodged marker instead of hurting the player.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let k = s.create(&b, BONE, 300.0, 200.0).expect("obj_bone");
    s.globals.insert("rebuff".into(), 1.0);
    s.dispatch(&b, k, 3, 0).expect("CODE 338 Step_0 rebuff");
    assert!(s.instances[&k].alive, "the parry-rebuff leaves the bone whole");
    assert_eq!(count(&s, DODGED), 1);
    let d = s.instances.values().find(|i| i.object == DODGED && i.alive).unwrap();
    assert_eq!((d.fields["x"], d.fields["y"]), (300.0, 190.0));
    let _ = (p, k);
}

// ==== batch 2 ================================================================
// obj_shooter2 (20), obj_knifebandit (15), obj_wolf (23), obj_ghost (24),
// obj_hulkingbandit (21) + its bullet (51), obj_bat (31), obj_slime (32),
// obj_enemy (14), obj_shooter1 (16), obj_enemy2 (22). Same discipline as batch
// 1; the shared per-body helpers below keep one named assertion site per CODE.

const SHOOTER2: i32 = 20;
const KNIFEBANDIT: i32 = 15;
const WOLF: i32 = 23;
const GHOST: i32 = 24;
const HULKING: i32 = 21;
const HBULLET: i32 = 51;
const BAT: i32 = 31;
const SLIME: i32 = 32;
const ENEMY: i32 = 14;
const SHOOTER1: i32 = 16;
const ENEMY2: i32 = 22;
/// IR constants of the pose-restoring alarms.
const SPR_TRAP1: f64 = 79.0;
const SPR_TRAP1FIRE: f64 = 80.0;
const SPR_KNIFEBANDIT: f64 = 59.0;
const SPR_WOLF: f64 = 106.0;
const SPR_HULKING: f64 = 117.0;
const SPR_ENEMY: f64 = 52.0;
const SPR_BIGEXPLOSION: f64 = 50.0;
const SND_EXPLODE: i32 = 7;
const SND_IMPACT2: i32 = 23;

/// The poison tick shared by every family: flag, a quarter of hp, one 0.25
/// obj_damage, and a 30-tick slot that re-arms itself through the scheduler.
fn poison_check(b: &Bundle, object: i32, hp: &str, slot: usize, code: i32) {
    let mut s = scene(b);
    let p = player(&mut s, b, 100.0, 100.0);
    let e = s.create(b, object, 300.0, 200.0).expect("victim");
    let hp0 = get(&s, e, hp);
    s.dispatch(b, e, 2, slot as i32).expect("poison alarm");
    assert_eq!(get(&s, e, "poisoned"), 1.0, "CODE {code} raises the poison flag");
    assert_eq!(hp0 - get(&s, e, hp), 0.25, "CODE {code} takes a quarter");
    assert_eq!(s.instances[&e].alarms[slot], 30, "CODE {code} re-arms its own slot at 30");
    assert_eq!(count(&s, DAMAGE), 1, "CODE {code} spawns one obj_damage");
    let d = s.instances.values().find(|i| i.object == DAMAGE && i.alive).unwrap();
    assert_eq!(d.fields["damage"], 0.25);
    assert_eq!((d.fields["x"], d.fields["y"]), (300.0, 200.0));
    s.instances.get_mut(&e).unwrap().alarms[slot] = 1;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(b).expect("tick");
    assert_eq!(hp0 - get(&s, e, hp), 0.5,
        "CODE {code}'s own 30-tick timer fires again through the scheduler");
    assert_eq!(s.instances[&e].alarms[slot], 30);
}

/// The stun-clearing alarms. `sprite` is Some when the body also restores the
/// family's walk pose (the 4-instruction variants).
fn stun_clear_check(b: &Bundle, object: i32, code: i32, clears: &str, slot: i32, sprite: Option<f64>) {
    let mut s = scene(b);
    let _p = player(&mut s, b, 500.0, 200.0);
    let e = s.create(b, object, 300.0, 200.0).expect("victim");
    set(&mut s, e, clears, 1.0);
    set(&mut s, e, "sprite_index", 0.0);
    s.dispatch(b, e, 2, slot).expect("clear alarm");
    assert_eq!(get(&s, e, clears), 0.0, "CODE {code} clears {clears}");
    if let Some(spr) = sprite {
        assert_eq!(get(&s, e, "sprite_index"), spr,
            "CODE {code} also restores the family's walk sprite");
    } else {
        assert_eq!(get(&s, e, "sprite_index"), 0.0,
            "CODE {code} touches nothing else");
    }
}

/// The thaw alarm: subtract the raw c_white constant and drop the frozen flag.
fn thaw_check(b: &Bundle, object: i32, code: i32, frozen: &str) {
    let mut s = scene(b);
    let _p = player(&mut s, b, 500.0, 200.0);
    let e = s.create(b, object, 300.0, 200.0).expect("victim");
    set(&mut s, e, frozen, 1.0);
    set(&mut s, e, "image_blend", C_BLUE);
    s.dispatch(b, e, 2, 3).expect("thaw alarm");
    assert_eq!(get(&s, e, frozen), 0.0, "CODE {code} clears {frozen}");
    assert_eq!(get(&s, e, "image_blend"), C_BLUE - C_WHITE,
        "CODE {code} subtracts the raw c_white constant 16777215 from the blend");
}

/// The Destroy body: two counters and one puff of the family's size, at the
/// family's own offset.
fn destroy_check(b: &Bundle, object: i32, counter: &str, puff: i32, dy: f64) {
    let mut s = scene(b);
    let _p = player(&mut s, b, 500.0, 200.0);
    let e = s.create(b, object, 300.0, 200.0).expect("victim");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(b, e, 1, 0).expect("Destroy_0");
    assert_eq!(s.globals[counter], 1.0, "the family counter is bumped");
    assert_eq!(s.globals["enemieskilled"], 1.0);
    let made = spawned(&s, &before);
    assert_eq!(made.len(), 1, "exactly one puff");
    assert_eq!(s.instances[&made[0]].object, puff);
    assert_eq!((get(&s, made[0], "x"), get(&s, made[0], "y")), (300.0, 200.0 + dy));
}

/// The hit-flash Draw body: white fog while flashing, a plain draw afterwards,
/// and the flashing latch cleared on the way out.
fn draw_flash_check(b: &Bundle, object: i32, code: usize) {
    let mut s = scene(b);
    let _p = player(&mut s, b, 700.0, 200.0);
    let e = s.create(b, object, 300.0, 200.0).expect("victim");
    let spr = get(&s, e, "sprite_index");
    set(&mut s, e, "flashing", 1.0);
    s.dispatch(b, e, 8, 0).expect("Draw_0");
    let draws: Vec<_> = s.draws.iter().filter(|d| d.instance == e).cloned().collect();
    assert_eq!(draws.len(), 1, "CODE {code} draws the instance exactly once");
    assert_eq!(draws[0].code, code, "the recorded draw comes from CODE {code}");
    assert!(draws[0].fog, "flashing draws through the d3d_set_fog(true, ...) wrapper");
    assert_eq!(draws[0].color, C_WHITE as i32, "with the c_white fog colour");
    assert_eq!(draws[0].sprite, spr as i32, "and its own sprite_index");
    assert_eq!(get(&s, e, "flashing"), 0.0, "CODE {code} clears flashing on the way out");
    assert!(!s.fog_enabled, "the wrapper restores the fog state");
    let n = s.draws.len();
    s.dispatch(b, e, 8, 0).expect("Draw_0 calm");
    let draws: Vec<_> = s.draws[n..].iter().filter(|d| d.instance == e).cloned().collect();
    assert_eq!(draws.len(), 1, "the flashing==0 branch also draws exactly once");
    assert!(!draws[0].fog, "no fog wrapper when not flashing");
    assert_eq!(draws[0].color, get(&s, e, "image_blend") as i32,
        "the plain draw carries image_blend");
    assert_eq!(draws[0].code, code);
}

// ---- obj_shooter2 (20) ------------------------------------------------------

// CODE 102 — obj_shooter2 Alarm_7 (this family poisons on slot 7, not 6)
#[test]
fn shooter2_alarm7_poison_ticks_on_slot_seven() {
    poison_check(&bundle(), SHOOTER2, "hpshooter2", 7, 102);
}

// CODE 103 — obj_shooter2 Alarm_6
#[test]
fn shooter2_alarm6_restores_the_trap_pose() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let e = s.create(&b, SHOOTER2, 300.0, 200.0).expect("obj_shooter2");
    set(&mut s, e, "sprite_index", SPR_TRAP1FIRE);
    s.dispatch(&b, e, 2, 6).expect("CODE 103 Alarm_6");
    assert_eq!(get(&s, e, "sprite_index"), SPR_TRAP1,
        "CODE 103 pins sprite_index back to spr_trap1 (79)");
}

// CODE 104 — obj_shooter2 Alarm_5
#[test]
fn shooter2_alarm5_clears_swordstun() {
    stun_clear_check(&bundle(), SHOOTER2, 104, "swordstunned", 5, None);
}

// CODE 105 — obj_shooter2 Alarm_4
#[test]
fn shooter2_alarm4_clears_stun() {
    stun_clear_check(&bundle(), SHOOTER2, 105, "stunned", 4, None);
}

// CODE 106 — obj_shooter2 Alarm_3 (thaw)
#[test]
fn shooter2_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), SHOOTER2, 106, "hpshooter2frozen");
}

// CODE 107 — obj_shooter2 Alarm_2
#[test]
fn shooter2_alarm2_restores_the_firing_pose() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let e = s.create(&b, SHOOTER2, 300.0, 200.0).expect("obj_shooter2");
    set(&mut s, e, "sprite_index", SPR_TRAP1);
    s.dispatch(&b, e, 2, 2).expect("CODE 107 Alarm_2");
    assert_eq!(get(&s, e, "sprite_index"), SPR_TRAP1FIRE,
        "CODE 107 pins sprite_index to spr_trap1fire (80)");
}

// CODE 111 — obj_shooter2 Draw_0
#[test]
fn shooter2_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), SHOOTER2, 111);
}

// ---- obj_knifebandit (15) ---------------------------------------------------

// CODE 49 — obj_knifebandit Create_0
#[test]
fn knifebandit_create_ladder_and_drop_rolls() {
    let b = bundle();
    // IR branch chain: level<=5 -> 15/14/12/11, <=10 -> 20/17/15/12,
    // <=15 -> 30/23/20/17, <=20 -> 35/30/25/20 (pwr 1..4).
    for (level, pwr, want) in [
        (1.0, 1.0, 15.0), (5.0, 4.0, 11.0), (10.0, 1.0, 20.0), (10.0, 3.0, 15.0),
        (15.0, 1.0, 30.0), (15.0, 4.0, 17.0), (20.0, 1.0, 35.0), (20.0, 4.0, 20.0),
    ] {
        let mut s = scene(&b);
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let _p = player(&mut s, &b, 500.0, 200.0);
        let k = s.create(&b, KNIFEBANDIT, 300.0, 200.0).expect("obj_knifebandit");
        assert_eq!(get(&s, k, "hpknife"), want,
            "CODE 49 ladder: level {level} pwr {pwr} -> {want}");
    }
    let mut s = scene(&b);
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("pwr".into(), 1.0);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let k = s.create(&b, KNIFEBANDIT, 300.0, 200.0).expect("obj_knifebandit");
    assert_eq!(get(&s, k, "flashing"), 0.0);
    assert_eq!(get(&s, k, "poisoned"), 0.0);
    assert_eq!(get(&s, k, "swordstunned"), 0.0);
    assert_eq!(get(&s, k, "stunned"), 0.0);
    assert_eq!(get(&s, k, "knifehsp"), 0.0);
    assert_eq!(get(&s, k, "falling"), 0.0);
    assert_eq!(get(&s, k, "facing"), 0.0);
    assert_eq!(get(&s, k, "xpdrop"), 1.0);
    assert_eq!(get(&s, k, "hpfrozen"), 0.0);
    let coin = get(&s, k, "coindrop");
    assert!((1.0..=5.0).contains(&coin) && coin.fract() == 0.0,
        "CODE 49 rolls coindrop from 1..5, got {coin}");
    let hp = get(&s, k, "hpdrop");
    assert!((1.0..=5.0).contains(&hp) && hp.fract() == 0.0,
        "CODE 49 rolls hpdrop from 1..5 with no zero option, got {hp}");
}

// CODE 50 — obj_knifebandit Destroy_0
#[test]
fn knifebandit_destroy_counts_and_puff_four_px_low() {
    destroy_check(&bundle(), KNIFEBANDIT, "knifebanditskilled", SMALLPUFF, 4.0);
}

// CODE 51 — obj_knifebandit Alarm_6 (poison)
#[test]
fn knifebandit_alarm6_poison_ticks() {
    poison_check(&bundle(), KNIFEBANDIT, "hpknife", 6, 51);
}

// CODE 52 — obj_knifebandit Alarm_5
#[test]
fn knifebandit_alarm5_clears_swordstun() {
    stun_clear_check(&bundle(), KNIFEBANDIT, 52, "swordstunned", 5, None);
}

// CODE 53 — obj_knifebandit Alarm_4
#[test]
fn knifebandit_alarm4_clears_stun_and_restores_the_pose() {
    stun_clear_check(&bundle(), KNIFEBANDIT, 53, "stunned", 4, Some(SPR_KNIFEBANDIT));
}

// CODE 54 — obj_knifebandit Alarm_3 (thaw)
#[test]
fn knifebandit_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), KNIFEBANDIT, 54, "hpfrozen");
}

// ---- obj_wolf (23) ----------------------------------------------------------

// CODE 136 — obj_wolf Destroy_0
#[test]
fn wolf_destroy_counts_and_puffs_at_the_body() {
    destroy_check(&bundle(), WOLF, "wolfkilled", SMALLPUFF, 0.0);
}

// CODE 138 — obj_wolf Alarm_6 (poison)
#[test]
fn wolf_alarm6_poison_ticks() {
    poison_check(&bundle(), WOLF, "hpwolf", 6, 138);
}

// CODE 139 — obj_wolf Alarm_5
#[test]
fn wolf_alarm5_clears_swordstun_and_restores_the_pose() {
    stun_clear_check(&bundle(), WOLF, 139, "swordstunned", 5, Some(SPR_WOLF));
}

// CODE 140 — obj_wolf Alarm_4
#[test]
fn wolf_alarm4_clears_stun_and_restores_the_pose() {
    stun_clear_check(&bundle(), WOLF, 140, "stunned", 4, Some(SPR_WOLF));
}

// CODE 141 — obj_wolf Alarm_3 (thaw)
#[test]
fn wolf_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), WOLF, 141, "hpwolffrozen");
}

// CODE 144 — obj_wolf Draw_0
#[test]
fn wolf_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), WOLF, 144);
}

// ---- obj_ghost (24) ---------------------------------------------------------

// CODE 146 — obj_ghost Destroy_0
#[test]
fn ghost_destroy_counts_and_puffs_at_the_body() {
    destroy_check(&bundle(), GHOST, "ghostskilled", SMALLPUFF, 0.0);
}

// CODE 147 — obj_ghost Alarm_6 (poison)
#[test]
fn ghost_alarm6_poison_ticks() {
    poison_check(&bundle(), GHOST, "hpghost", 6, 147);
}

// CODE 148 — obj_ghost Alarm_5
#[test]
fn ghost_alarm5_clears_swordstun() {
    stun_clear_check(&bundle(), GHOST, 148, "swordstunned", 5, None);
}

// CODE 149 — obj_ghost Alarm_4
#[test]
fn ghost_alarm4_clears_stun() {
    stun_clear_check(&bundle(), GHOST, 149, "stunned", 4, None);
}

// CODE 150 — obj_ghost Alarm_3 (thaw)
#[test]
fn ghost_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), GHOST, 150, "hpghostfrozen");
}

// CODE 153 — obj_ghost Draw_0
#[test]
fn ghost_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), GHOST, 153);
}

// ---- obj_hulkingbandit (21) -------------------------------------------------

// CODE 113 — obj_hulkingbandit Destroy_0
#[test]
fn hulkingbandit_destroy_counts_and_sprays_the_big_puff() {
    destroy_check(&bundle(), HULKING, "hulkingbanditskilled", BIGPUFF, 0.0);
}

// CODE 114 — obj_hulkingbandit Alarm_6 (poison)
#[test]
fn hulkingbandit_alarm6_poison_ticks() {
    poison_check(&bundle(), HULKING, "hphulkingbandit", 6, 114);
}

// CODE 115 — obj_hulkingbandit Alarm_5
#[test]
fn hulkingbandit_alarm5_clears_swordstun_and_restores_the_pose() {
    stun_clear_check(&bundle(), HULKING, 115, "swordstunned", 5, Some(SPR_HULKING));
}

// CODE 116 — obj_hulkingbandit Alarm_4
#[test]
fn hulkingbandit_alarm4_clears_stun_and_restores_the_pose() {
    stun_clear_check(&bundle(), HULKING, 116, "stunned", 4, Some(SPR_HULKING));
}

// CODE 122 — obj_hulkingbandit Draw_0
#[test]
fn hulkingbandit_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), HULKING, 122);
}

// ---- obj_hulkingbanditbullet (51) -------------------------------------------

// CODE 325 — obj_hulkingbanditbullet Create_0
#[test]
fn hulkingbanditbullet_create_seeds_its_two_latches() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    assert_eq!(get(&s, m, "hurtplayer"), 0.0, "CODE 325 starts undamaged");
    assert_eq!(get(&s, m, "checkwall"), 0.0, "CODE 325 starts wall-unchecked");
}

// CODE 326 — obj_hulkingbanditbullet Alarm_2
#[test]
fn hulkingbanditbullet_alarm2_expires_the_shot() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    assert!(s.instances[&m].alive, "fixture: it is alive to begin with");
    s.dispatch(&b, m, 2, 2).expect("CODE 326 Alarm_2");
    assert!(!s.instances[&m].alive, "CODE 326's whole body is instance_destroy()");
}

// CODE 327 — obj_hulkingbanditbullet Alarm_1
#[test]
fn hulkingbanditbullet_alarm1_swaps_to_the_blast_and_rearms() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, m, "sprite_index", 0.0);
    set(&mut s, m, "image_index", 5.0);
    s.dispatch(&b, m, 2, 1).expect("CODE 327 Alarm_1");
    assert_eq!(get(&s, m, "sprite_index"), SPR_BIGEXPLOSION,
        "CODE 327 swaps to spr_bigexplosion (50)");
    assert_eq!(get(&s, m, "image_index"), 0.0, "and restarts the animation");
    assert_eq!(s.instances[&m].alarms[2], 18, "CODE 327 arms the 18-tick expiry");
    assert!(s.audio.iter().any(|a| a.sound == SND_EXPLODE && !a.looping),
        "CODE 327 plays snd_explode (7) when soundmute is off");

    // The swap is gated on the sprite not already being the blast.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, m, "sprite_index", SPR_BIGEXPLOSION);
    set(&mut s, m, "image_index", 3.0);
    s.dispatch(&b, m, 2, 1).expect("CODE 327 Alarm_1 again");
    assert_eq!(get(&s, m, "image_index"), 3.0,
        "already blasting: CODE 327 leaves the animation running");

    // soundmute == 1 mutes it, and the expiry alarm is still armed.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    s.globals.insert("soundmute".into(), 1.0);
    s.dispatch(&b, m, 2, 1).expect("CODE 327 Alarm_1 muted");
    assert!(!s.audio.iter().any(|a| a.sound == SND_EXPLODE),
        "CODE 327's sound is behind the soundmute gate");
    assert_eq!(s.instances[&m].alarms[2], 18);
}

// CODE 328 — obj_hulkingbanditbullet Step_0 (sword / wall / aim)
#[test]
fn hulkingbanditbullet_step_parries_walls_and_stops() {
    let b = bundle();
    // Sword at the next position: one obj_parry, the shot is consumed.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, m, "hspeed", 1.0);
    set(&mut s, m, "vspeed", 0.0);
    let _sw = s.create(&b, SWORD, 301.0, 200.0).expect("obj_sword");
    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 parried");
    assert!(!s.instances[&m].alive, "the sword consumes the shot");
    let made = spawned(&s, &before);
    assert_eq!(made.iter().filter(|i| s.instances[i].object == PARRY).count(), 1,
        "CODE 328 leaves obj_parry at the impact");

    // par_wall: the shot stops dead, latches checkwall and arms its expiry.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let _w = s.create(&b, WALL, 300.0, 200.0).expect("par_wall");
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, m, "hspeed", 3.0);
    set(&mut s, m, "vspeed", 2.0);
    assert!(probe(&mut s, &b, m, 0.0, 0.0, PAR_WALL), "fixture: the shot is on the wall");
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 wall");
    assert_eq!(get(&s, m, "hspeed"), 0.0, "CODE 328 stops the shot on the wall");
    assert_eq!(get(&s, m, "vspeed"), 0.0);
    assert_eq!(s.instances[&m].alarms[1], 1, "CODE 328 hands over to alarm[1]");
    assert_eq!(get(&s, m, "checkwall"), 1.0, "and latches checkwall");
    assert!(s.instances[&m].alive, "the wall branch destroys nothing by itself");

    // The latch is one-shot: a second step on the same wall does not re-arm.
    s.instances.get_mut(&m).unwrap().alarms[1] = -1;
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 wall again");
    assert_eq!(s.instances[&m].alarms[1], -1,
        "CODE 328's checkwall latch blocks the second stop");

    // image_angle tracks direction every step.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 700.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, m, "direction", 135.0);
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 aim");
    assert_eq!(get(&s, m, "image_angle"), 135.0, "CODE 328 pins image_angle to direction");
}

// CODE 328 — obj_hulkingbanditbullet Step_0 (player contact)
#[test]
fn hulkingbanditbullet_step_hurts_the_player_once() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    let hp0 = s.globals["health1"];
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 hit");
    assert_eq!(get(&s, p, "flashing"), 1.0, "CODE 328 flashes the player");
    assert_eq!(s.globals["health1"], hp0 - 1.0, "and takes one life");
    assert_eq!(s.instances[&p].alarms[7], 22);
    assert_eq!(s.instances[&p].alarms[4], 10);
    assert_eq!(s.instances[&p].alarms[8], 25);
    assert_eq!(get(&s, m, "hurtplayer"), 1.0, "and latches hurtplayer");
    assert_eq!(get(&s, m, "hspeed"), 0.0, "the shot stops on the player");
    assert_eq!(get(&s, m, "vspeed"), 0.0);
    assert_eq!(s.instances[&m].alarms[1], 1, "and hands over to alarm[1]");
    assert_eq!(s.particles.len(), 4, "CODE 328 sprays four particles");
    assert!(s.audio.iter().any(|a| a.sound == SND_IMPACT2 && !a.looping),
        "CODE 328 plays snd_impactsound2 (23) when soundmute is off");
    assert!(s.instances[&m].alive, "the shot survives to explode");

    // The latch makes it a one-shot: the same step again costs nothing.
    let hp1 = s.globals["health1"];
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 hit again");
    assert_eq!(s.globals["health1"], hp1, "hurtplayer gates the second bite");
    assert_eq!(get(&s, p, "flashing"), 1.0);

    // Side of contact picks the knockback slot.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 299.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, p, "invulnerable", 0.0);
    set(&mut s, p, "invulnerable2", 0.0);
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 hit from the right");
    assert_eq!(get(&s, p, "invulnerable"), 1.0);
    assert_eq!(get(&s, p, "sliding1"), 1.0);
    assert_eq!(get(&s, p, "invulnerable2"), 0.0);

    // An invulnerable player is not touched at all.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    set(&mut s, p, "invulnerable", 1.0);
    let hp0 = s.globals["health1"];
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 vs invulnerable player");
    assert_eq!(s.globals["health1"], hp0);
    assert_eq!(get(&s, m, "hurtplayer"), 0.0, "the contact branch never ran");

    // Rebuff: the shot drops an obj_dodged marker instead of hurting.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let m = s.create(&b, HBULLET, 300.0, 200.0).expect("obj_hulkingbanditbullet");
    s.globals.insert("rebuff".into(), 1.0);
    s.dispatch(&b, m, 3, 0).expect("CODE 328 Step_0 rebuff");
    assert_eq!(count(&s, DODGED), 1, "CODE 328 spawns obj_dodged on the dodge");
    assert_eq!(get(&s, m, "hurtplayer"), 0.0);
    assert_eq!(get(&s, p, "flashing"), 0.0);
}

// ---- obj_bat (31) -----------------------------------------------------------

// CODE 233 — obj_bat Destroy_0
#[test]
fn bat_destroy_counts_and_puffs_at_the_body() {
    destroy_check(&bundle(), BAT, "batskilled", SMALLPUFF, 0.0);
}

// CODE 236 — obj_bat Alarm_5
#[test]
fn bat_alarm5_clears_swordstun() {
    stun_clear_check(&bundle(), BAT, 236, "swordstunned", 5, None);
}

// CODE 237 — obj_bat Alarm_4
#[test]
fn bat_alarm4_clears_stun() {
    stun_clear_check(&bundle(), BAT, 237, "stunned", 4, None);
}

// CODE 238 — obj_bat Alarm_3 (thaw)
#[test]
fn bat_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), BAT, 238, "hpfourfrozen");
}

// CODE 243 — obj_bat Draw_0
#[test]
fn bat_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), BAT, 243);
}

// ---- obj_slime (32) ---------------------------------------------------------

// CODE 246 — obj_slime Alarm_6 (poison)
#[test]
fn slime_alarm6_poison_ticks() {
    poison_check(&bundle(), SLIME, "hpslime", 6, 246);
}

// CODE 247 — obj_slime Alarm_5
#[test]
fn slime_alarm5_clears_swordstun() {
    stun_clear_check(&bundle(), SLIME, 247, "swordstunned", 5, None);
}

// CODE 248 — obj_slime Alarm_4
#[test]
fn slime_alarm4_clears_stun() {
    stun_clear_check(&bundle(), SLIME, 248, "stunned", 4, None);
}

// CODE 249 — obj_slime Alarm_3 (thaw)
#[test]
fn slime_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), SLIME, 249, "hpslimefrozen");
}

// CODE 255 — obj_slime Draw_0
#[test]
fn slime_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), SLIME, 255);
}

// ---- obj_enemy (14) ---------------------------------------------------------

// CODE 41 — obj_enemy Destroy_0
#[test]
fn enemy_destroy_counts_and_puffs_at_the_body() {
    destroy_check(&bundle(), ENEMY, "bearskilled", SMALLPUFF, 0.0);
}

// CODE 43 — obj_enemy Alarm_5
#[test]
fn enemy_alarm5_clears_swordstun_and_restores_the_pose() {
    stun_clear_check(&bundle(), ENEMY, 43, "swordstunned", 5, Some(SPR_ENEMY));
}

// CODE 44 — obj_enemy Alarm_4
#[test]
fn enemy_alarm4_clears_stun_and_restores_the_pose() {
    stun_clear_check(&bundle(), ENEMY, 44, "stunned", 4, Some(SPR_ENEMY));
}

// CODE 45 — obj_enemy Alarm_3 (thaw)
#[test]
fn enemy_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), ENEMY, 45, "hpfrozen");
}

// ---- obj_shooter1 (16) ------------------------------------------------------

// CODE 60 — obj_shooter1 Alarm_6 (poison)
#[test]
fn shooter1_alarm6_poison_ticks() {
    poison_check(&bundle(), SHOOTER1, "hpshooter1", 6, 60);
}

// CODE 62 — obj_shooter1 Alarm_4
#[test]
fn shooter1_alarm4_clears_stun() {
    stun_clear_check(&bundle(), SHOOTER1, 62, "stunned", 4, None);
}

// CODE 63 — obj_shooter1 Alarm_3 (thaw)
#[test]
fn shooter1_alarm3_thaw_clears_the_frozen_flag() {
    thaw_check(&bundle(), SHOOTER1, 63, "hpshooter1frozen");
}

// CODE 68 — obj_shooter1 Draw_0
#[test]
fn shooter1_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), SHOOTER1, 68);
}

// ---- obj_enemy2 (22) --------------------------------------------------------

// CODE 124 — obj_enemy2 Destroy_0
#[test]
fn enemy2_destroy_counts_and_puffs_at_the_body() {
    destroy_check(&bundle(), ENEMY2, "chomperbotkilled", SMALLPUFF, 0.0);
}

// CODE 128 — obj_enemy2 Alarm_4
#[test]
fn enemy2_alarm4_clears_stun() {
    stun_clear_check(&bundle(), ENEMY2, 128, "stunned", 4, None);
}

// CODE 134 — obj_enemy2 Draw_0
#[test]
fn enemy2_draw_flashes_white_fog() {
    draw_flash_check(&bundle(), ENEMY2, 134);
}
