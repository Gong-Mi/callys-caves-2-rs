//! wl44-pickups-misc — id-level body semantics for the 34 enemy-projectile,
//! drop, upgrade-pickup and UI-misc bodies the census still carried without a
//! test that ever names the body.
//!
//! Scope statement: these are IR regression semantics for THIS rewrite's code
//! host. Every value asserted below was read out of the recovered GML body
//! (`cally-recovered-gml-*/restored-source/gml/NNNN__*.gml`) and cross-checked
//! against the bytecode constants of that same body in
//! `crates/core/src/generated/full_ir.json` on this host. They are NOT a proof
//! of equivalence with the original GameMaker runner.
//!
//! Every test first pins the binding it is about (`codes(&b, OBJECT, ev, sub)`)
//! so a body cannot silently move to another event slot, then drives the real
//! dispatch and asserts that body's own observable effect.
//!
//! Fixture (the same wiring the app's gameplay entry point installs):
//!   * SPRT geometry (bounds + recorded manual bbox + per-frame masks) so
//!     `instance_place` / the collision broad phase box instances through the
//!     original Compute_BoundingBox;
//!   * one obj_pwrlevelinitialize — its Create is what builds global.P_System /
//!     global.Particle1 — parked immediately;
//!   * one obj_muting — its Create is the game-start spread table: global.coinspread
//!     ..coinspread25 and global.xpspread..xpspread5 are its random_range(0,180)
//!     draws, so the drop-fan tests compare against the *real* draws instead of
//!     inventing them. Parked immediately after Create, globals retained;
//!   * no room is loaded: every instance in a scene is one this file created, so
//!     nothing else can move, shoot or overwrite a value mid-assertion.
//!
//! Direction of every drive:
//!   * direct `dispatch` for the raw value the body writes (no same-tick Step,
//!     no physics integration in the way);
//!   * the scheduler (`tick`) separately, to prove the body really is wired to
//!     the timer / mouse / collision pass it belongs to. Alarm arithmetic is
//!     measured, never assumed: arming N takes N ticks to fire.
//!
//! Citation hygiene: `CODE NNN` is written here only for the bodies this file
//! owns. Bodies the fixture merely builds or runs alongside (obj_UI Create,
//! obj_ghost Create/Destroy, obj_slime Step, obj_muting Create, the pickup
//! Creates, obj_viewresolution Alarm_0, ...) are named by object/event instead,
//! so this suite cannot claim id-level evidence for work it does not assert.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host, Op};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::collections::BTreeMap;
use std::path::Path;

// ---- object ids, read from full_ir.json's object table ----------------------
const PLAYER: i32 = 0;
const WALL: i32 = 4;
const WATER: i32 = 9;
const SHOOTER1: i32 = 16;
const ENEMY2: i32 = 22;
const WOLF: i32 = 23;
const GHOST: i32 = 24;
const BAT: i32 = 31;
const SLIME: i32 = 32;
const PAR_WALL: i32 = 34;
const BLADE: i32 = 36;
const ENEMYBULLET: i32 = 47;
const ENEMYBULLET2: i32 = 48;
const COIN: i32 = 58;
const GEM: i32 = 59;
const SILVERCOIN: i32 = 60;
const XPORB: i32 = 61;
const HEALTH: i32 = 62;
const LEVELUP: i32 = 63;
const WEAPONLEVELUP: i32 = 64;
const UI: i32 = 66;
const MUTING: i32 = 67;
const WARPANYWHERE: i32 = 69;
const POWERUPGRADE: i32 = 84;
const POWERUPGRADE2: i32 = 85;
const POWERUPGRADE3: i32 = 86;
const TRIPLEJUMP: i32 = 87;
const SWORDUPGRADE: i32 = 88;
const SWORDUPGRADE2: i32 = 89;
const HEALTHREGEN: i32 = 92;
const STRENGTHUPGRADE: i32 = 93;
const INIT: i32 = 103;
const DAMAGE: i32 = 104;
const DODGED: i32 = 106;
const COINADD: i32 = 132;
const VIEWRESOLUTION: i32 = 133;
const PHONE: i32 = 136;
const LOGPARTS: i32 = 155;
const SMALLPUFF: i32 = 187;

/// Sprite constant of CODE 137, read off that body's IR (spr_wolf).
const SPR_WOLF: f64 = 106.0;
/// c_white as the packed value the engine's image_blend uses (CODE 129's
/// constant). obj_create leaves every instance at this blend.
const C_WHITE: f64 = 16_777_215.0;
/// SOND ids from reconstruction/contracts/audio-sond.json, matching the IR
/// constant of the body that plays them: sond 0 = bee (CODE 151), sond 19 =
/// coin (CODE 342 and the eight shop bodies).
const SND_BEE: i32 = 0;
const SND_COIN: i32 = 19;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// The app's SPRT wiring: recorded bbox + bounds + masks, so every box the
/// bodies probe is the original manual one.
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
    let init = spawn(b, &mut s, INIT, -1000.0, -1000.0);
    kill(&mut s, init);
    let m = spawn(b, &mut s, MUTING, -1000.0, -1000.0);
    kill(&mut s, m);
    // global.pwr is the level-configuration global the room initializer writes,
    // not an engine-recomputed field: the fixture seeds it like the other suites.
    s.globals.insert("pwr".into(), 1.0);
    s
}

/// A scene with obj_UI alive: obj_levelup's Create reads obj_UI.x, and obj_UI's
/// own Create is the only place global.coinsound / global.swordsound are set.
/// Its touch buttons are parked and its own alarms disarmed so a tick window
/// contains only the body under test.
fn ui_scene(b: &Bundle) -> (Scene, i32) {
    let mut s = scene(b);
    let before = ids(&s);
    let ui = spawn(b, &mut s, UI, 0.0, 0.0);
    for id in ids(&s) {
        if id != ui && !before.contains(&id) {
            kill(&mut s, id);
        }
    }
    s.instances.get_mut(&ui).unwrap().alarms = [-1; 12];
    assert!(
        matches!(s.globals.get("coinsound").copied(), Some(19.0) | Some(20.0)),
        "obj_UI's Create leaves global.coinsound at choose(19, 20)"
    );
    (s, ui)
}

/// The CODE ids the asset binds to one event slot of one object.
fn codes(b: &Bundle, object: i32, event_type: i32, subtype: i32) -> Vec<usize> {
    b.objects
        .iter()
        .find(|o| o.id == object)
        .and_then(|o| {
            o.events
                .iter()
                .find(|e| e.event_type == event_type && e.subtype == subtype)
        })
        .map(|e| e.codes.clone())
        .unwrap_or_default()
}

fn spawn(b: &Bundle, s: &mut Scene, object: i32, x: f64, y: f64) -> i32 {
    s.create(b, object, x, y)
        .unwrap_or_else(|e| panic!("create object {object} at ({x}, {y}): {e}"))
}

fn ids(s: &Scene) -> Vec<i32> {
    s.instances.keys().copied().collect()
}

/// Instances created since the `before` snapshot (the storage keeps destroyed
/// instances, so this is the creation tally).
fn spawned(s: &Scene, before: &[i32]) -> Vec<i32> {
    let mut v: Vec<i32> = s
        .instances
        .keys()
        .copied()
        .filter(|k| !before.contains(k))
        .collect();
    v.sort();
    v
}

fn of(s: &Scene, object: i32, list: &[i32]) -> Vec<i32> {
    let mut v: Vec<i32> = list
        .iter()
        .copied()
        .filter(|id| s.instances[id].object == object)
        .collect();
    v.sort();
    v
}

/// Living instances of an object.
fn count(s: &Scene, object: i32) -> usize {
    s.instances
        .values()
        .filter(|i| i.object == object && i.alive)
        .count()
}

/// Instances of an object ever created in this scene, dead or alive.
fn made(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|i| i.object == object).count()
}

fn alive(s: &Scene, id: i32) -> bool {
    s.instances.get(&id).map_or(false, |i| i.alive)
}

fn set(s: &mut Scene, id: i32, name: &str, v: f64) {
    s.instances
        .get_mut(&id)
        .unwrap()
        .fields
        .insert(name.into(), v);
}

fn fget(s: &Scene, id: i32, name: &str) -> f64 {
    s.instances
        .get(&id)
        .and_then(|i| i.fields.get(name))
        .copied()
        .unwrap_or(0.0)
}

fn pin(s: &mut Scene, id: i32, x: f64, y: f64) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("x".into(), x);
    i.fields.insert("y".into(), y);
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

fn kill(s: &mut Scene, id: i32) {
    if let Some(i) = s.instances.get_mut(&id) {
        i.alive = false;
    }
}

fn audio(s: &Scene) -> Vec<i32> {
    s.audio.iter().map(|a| a.sound).collect()
}

/// The shared legacy score (GML `score` resolves to one value across every
/// instance context, as CODE 414's own `load score` shows).
fn score(s: &mut Scene, id: i32) -> f64 {
    s.read(id, -1, "score", None).unwrap()
}

/// The client's `pointer_pressed` path: a real press in room coordinates,
/// delivered by the scheduler's Mouse_0 pass to every instance whose box
/// contains it. The point is asserted to sit inside the 1136x640 logical
/// viewport the renderer reports.
fn click(b: &Bundle, s: &mut Scene, id: i32) {
    let (l, r, t, bt) = s.bounds_for_instance(id).expect("instance bounds");
    let (x, y) = ((l + r) / 2.0, (t + bt) / 2.0);
    assert!(
        (0.0..1136.0).contains(&x) && (0.0..640.0).contains(&y),
        "click point ({x}, {y}) must be inside the logical viewport"
    );
    s.left_presses.push((x, y));
    s.tick(b).unwrap();
}

// ---------------------------------------------------------------------------
// obj_coin / obj_gem — the two coin-family Creates
// ---------------------------------------------------------------------------

#[test]
fn coin_create_pins_type_and_friction_without_a_roof_probe() {
    let b = bundle();
    assert_eq!(
        codes(&b, COIN, 0, 0),
        vec![339],
        "// CODE 339 is obj_coin Create_0"
    );
    let mut s = scene(&b);
    let c = spawn(&b, &mut s, COIN, 300.0, 200.0);
    assert_eq!(fget(&s, c, "type"), 1.0, "// CODE 339 type = 1");
    assert_eq!(fget(&s, c, "friction"), 0.3, "// CODE 339 friction = 0.3");
    // The coin carries no yorigin: unlike obj_gem / obj_silvercoin its Create
    // never probes for a roof, so nothing about a floor is pinned here.
    assert!(
        !s.instances[&c].fields.contains_key("yorigin"),
        "// CODE 339 writes exactly two fields"
    );
    assert_eq!(
        fget(&s, c, "sprite_index"),
        88.0,
        "the object's own sprite stays in place"
    );

    // Re-running the body on a dirty instance restores both fields.
    set(&mut s, c, "type", 0.0);
    set(&mut s, c, "friction", 9.0);
    s.dispatch(&b, c, 0, 0).unwrap();
    assert_eq!((fget(&s, c, "type"), fget(&s, c, "friction")), (1.0, 0.3));
}

#[test]
fn gem_create_probes_the_roof_for_its_floor_origin() {
    let b = bundle();
    assert_eq!(
        codes(&b, GEM, 0, 0),
        vec![341],
        "// CODE 341 is obj_gem Create_0"
    );
    let mut s = scene(&b);
    // Open air: the (x, y - 1) probe misses, so the gem keeps its own y.
    let g = spawn(&b, &mut s, GEM, 300.0, 200.0);
    assert_eq!(fget(&s, g, "type"), 2.0, "// CODE 341 type = 2");
    assert_eq!(fget(&s, g, "friction"), 0.3, "// CODE 341 friction = 0.3");
    assert_eq!(
        fget(&s, g, "yorigin"),
        200.0,
        "// CODE 341 no roof -> yorigin = y"
    );

    // A par_wall child one pixel above: the same probe reaches it, so the floor
    // origin drops one 32px tile.
    let wall = spawn(&b, &mut s, WALL, 300.0, 200.0);
    assert_eq!(
        s.call(&b, g, "instance_place", &[300.0, 199.0, PAR_WALL as f64])
            .unwrap(),
        wall as f64,
        "fixture: the (x, y - 1) probe reaches the wall through par_wall"
    );
    let g2 = spawn(&b, &mut s, GEM, 300.0, 200.0);
    assert_eq!(
        fget(&s, g2, "yorigin"),
        232.0,
        "// CODE 341 roofed -> yorigin = y + 32"
    );
    assert_eq!(fget(&s, g2, "type"), 2.0);
    assert_eq!(fget(&s, g2, "friction"), 0.3);
}

#[test]
fn gem_destroy_chimes_only_on_the_zero_and_one_soundmute_branches() {
    let b = bundle();
    assert_eq!(
        codes(&b, GEM, 1, 0),
        vec![342],
        "// CODE 342 is obj_gem Destroy_0"
    );
    let (mut s, _ui) = ui_scene(&b);
    let want = s.globals["coinsound"] as i32;
    assert!(
        want == 19 || want == 20,
        "obj_UI's Create rolled coinsound to {want}"
    );
    let gem = spawn(&b, &mut s, GEM, 300.0, 200.0);
    s.destroy(&b, gem).unwrap();
    assert_eq!(
        audio(&s),
        vec![want],
        "// CODE 342 plays global.coinsound once"
    );
    assert!(!s.audio[0].looping, "// CODE 342 passes loop = false");
    assert!(!alive(&s, gem), "the gem is gone either way");

    // soundmute == 1 takes the empty stub branch: silence.
    let (mut s, _ui) = ui_scene(&b);
    s.globals.insert("soundmute".into(), 1.0);
    let gem = spawn(&b, &mut s, GEM, 300.0, 200.0);
    s.destroy(&b, gem).unwrap();
    assert!(s.audio.is_empty(), "// CODE 342 is silent while muted");

    // Any other value matches neither branch: the body is a `==1 / ==0` pair,
    // not a truthiness test, so soundmute = 5 is silent too.
    let (mut s, _ui) = ui_scene(&b);
    s.globals.insert("soundmute".into(), 5.0);
    let gem = spawn(&b, &mut s, GEM, 300.0, 200.0);
    s.destroy(&b, gem).unwrap();
    assert!(
        s.audio.is_empty(),
        "// CODE 342's else-if is `== 0`, so soundmute = 5 makes no sound"
    );
}

// ---------------------------------------------------------------------------
// obj_silvercoin / obj_XPorb / obj_health — the three identical ground Steps
// ---------------------------------------------------------------------------

#[derive(Clone, Copy)]
enum Ground {
    /// No wall anywhere below: the else branch, gravity 0.6.
    OpenAir,
    /// Wall at y + 1, instance at or below its own yorigin: park on the floor.
    RoofBelow,
    /// Wall at y - 1 when Create runs (so yorigin = y + 32) and still at y + 1:
    /// below the floor origin -> gravity 0.6 with vspeed untouched.
    RoofAbove,
    /// Wall one probe-step ahead: the horizontal walk stops.
    BlockedAhead,
    /// obj_watersurface on the instance: it dies.
    OverWater,
}

/// Drives one ground-rule case of a `par_coin` Step body and reports
/// (gravity, vspeed, hspeed, alive).
fn ground_case(b: &Bundle, object: i32, case: Ground) -> (f64, f64, f64, bool) {
    let mut s = scene(b);
    let (x, y) = (300.0, 200.0);
    let roofed_first = matches!(case, Ground::RoofAbove);
    if roofed_first {
        spawn(b, &mut s, WALL, x, y - 1.0);
    }
    let id = spawn(b, &mut s, object, x, y);
    match case {
        Ground::OpenAir => {}
        Ground::RoofBelow => {
            spawn(b, &mut s, WALL, x, y + 1.0);
        }
        Ground::RoofAbove => {
            spawn(b, &mut s, WALL, x, y + 1.0);
        }
        Ground::BlockedAhead => {
            spawn(b, &mut s, WALL, x + 5.0, y);
            set(&mut s, id, "hspeed", 5.0);
        }
        Ground::OverWater => {
            spawn(b, &mut s, WATER, x, y);
        }
    }
    if matches!(case, Ground::RoofBelow | Ground::RoofAbove) {
        // A visible free-fall value, so "vspeed = 0" is observable.
        set(&mut s, id, "vspeed", 7.0);
    }
    s.dispatch(b, id, 3, 0).unwrap();
    (
        fget(&s, id, "gravity"),
        fget(&s, id, "vspeed"),
        fget(&s, id, "hspeed"),
        alive(&s, id),
    )
}

#[test]
fn silvercoin_step_ground_probe_lateral_stop_and_water_death() {
    let b = bundle();
    assert_eq!(
        codes(&b, SILVERCOIN, 3, 0),
        vec![346],
        "// CODE 346 is obj_silvercoin Step_0"
    );
    let (g, v, _, live) = ground_case(&b, SILVERCOIN, Ground::OpenAir);
    assert_eq!(
        (g, v, live),
        (0.6, 0.0, true),
        "// CODE 346 open air -> gravity = 0.6"
    );
    let (g, v, _, live) = ground_case(&b, SILVERCOIN, Ground::RoofBelow);
    assert_eq!(
        (g, v, live),
        (0.0, 0.0, true),
        "// CODE 346 at yorigin -> vspeed = 0, gravity = 0"
    );
    let (g, v, _, live) = ground_case(&b, SILVERCOIN, Ground::RoofAbove);
    assert_eq!(
        (g, v, live),
        (0.6, 7.0, true),
        "// CODE 346 above yorigin -> only gravity = 0.6"
    );
    let (_, _, hsp, live) = ground_case(&b, SILVERCOIN, Ground::BlockedAhead);
    assert_eq!(
        (hsp, live),
        (0.0, true),
        "// CODE 346 wall at x + hspeed -> hspeed = 0"
    );
    let (_, _, _, live) = ground_case(&b, SILVERCOIN, Ground::OverWater);
    assert!(
        !live,
        "// CODE 346 sitting on obj_watersurface -> instance_destroy"
    );

    // And the same body really runs in the scheduler's Step pass.
    let mut s = scene(&b);
    let c = spawn(&b, &mut s, SILVERCOIN, 300.0, 200.0);
    set(&mut s, c, "gravity", 0.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, c, "gravity"),
        0.6,
        "// CODE 346 fires inside the tick's Step pass"
    );
    assert!(alive(&s, c));
}

#[test]
fn xporb_step_shares_the_ground_rules() {
    let b = bundle();
    assert_eq!(
        codes(&b, XPORB, 3, 0),
        vec![348],
        "// CODE 348 is obj_XPorb Step_0"
    );
    let (g, v, _, live) = ground_case(&b, XPORB, Ground::OpenAir);
    assert_eq!(g, 0.6, "// CODE 348 open air -> gravity = 0.6");
    assert_eq!(v, 0.0, "obj_XPorb's Create leaves vspeed at 0");
    assert!(live);
    let (g, v, _, live) = ground_case(&b, XPORB, Ground::RoofBelow);
    assert_eq!(
        (g, v, live),
        (0.0, 0.0, true),
        "// CODE 348 at yorigin -> vspeed = 0, gravity = 0"
    );
    let (g, v, _, live) = ground_case(&b, XPORB, Ground::RoofAbove);
    assert_eq!(
        (g, v, live),
        (0.6, 7.0, true),
        "// CODE 348 above yorigin -> only gravity = 0.6"
    );
    let (_, _, hsp, live) = ground_case(&b, XPORB, Ground::BlockedAhead);
    assert_eq!(
        (hsp, live),
        (0.0, true),
        "// CODE 348 wall at x + hspeed -> hspeed = 0"
    );
    let (_, _, _, live) = ground_case(&b, XPORB, Ground::OverWater);
    assert!(!live, "// CODE 348 on water -> instance_destroy");
}

#[test]
fn health_step_shares_the_ground_rules() {
    let b = bundle();
    assert_eq!(
        codes(&b, HEALTH, 3, 0),
        vec![351],
        "// CODE 351 is obj_health Step_0"
    );
    let (g, v, _, live) = ground_case(&b, HEALTH, Ground::OpenAir);
    assert_eq!(g, 0.6, "// CODE 351 open air -> gravity = 0.6");
    assert_eq!(
        v, -2.0,
        "obj_health's Create (vspeed = -2) is left alone by // CODE 351"
    );
    assert!(live);
    let (g, v, _, live) = ground_case(&b, HEALTH, Ground::RoofBelow);
    assert_eq!(
        (g, v, live),
        (0.0, 0.0, true),
        "// CODE 351 at yorigin -> vspeed = 0, gravity = 0"
    );
    let (g, v, _, live) = ground_case(&b, HEALTH, Ground::RoofAbove);
    assert_eq!(
        (g, v, live),
        (0.6, 7.0, true),
        "// CODE 351 above yorigin -> only gravity = 0.6"
    );
    let (_, _, hsp, live) = ground_case(&b, HEALTH, Ground::BlockedAhead);
    assert_eq!(
        (hsp, live),
        (0.0, true),
        "// CODE 351 wall at x + hspeed -> hspeed = 0"
    );
    let (_, _, _, live) = ground_case(&b, HEALTH, Ground::OverWater);
    assert!(!live, "// CODE 351 on water -> instance_destroy");
}

// ---------------------------------------------------------------------------
// obj_levelup / obj_weaponlevelup — the two pickup banners
// ---------------------------------------------------------------------------

#[test]
fn levelup_alarm_1_destroys_and_alarm_0_clears_showpart() {
    let b = bundle();
    assert_eq!(
        codes(&b, LEVELUP, 2, 1),
        vec![353],
        "// CODE 353 is obj_levelup Alarm_1"
    );
    assert_eq!(
        codes(&b, LEVELUP, 2, 0),
        vec![354],
        "// CODE 354 is obj_levelup Alarm_0"
    );
    let (mut s, _ui) = ui_scene(&b);

    // obj_levelup's Create arms the pair: alarm[1] = 94 (the hard lifetime) and alarm[0] = 40.
    let lv = spawn(&b, &mut s, LEVELUP, 10.0, 10.0);
    assert_eq!(
        fget(&s, lv, "showpart"),
        1.0,
        "obj_levelup's Create raises the part count"
    );
    assert_eq!(
        s.instances[&lv].alarms[1], 94,
        "obj_levelup's Create arms the lifetime"
    );
    assert_eq!(
        s.instances[&lv].alarms[0], 40,
        "obj_levelup's Create arms the part switch"
    );

    let sounds_before = s.audio.len();
    s.dispatch(&b, lv, 2, 0).unwrap();
    assert_eq!(fget(&s, lv, "showpart"), 0.0, "// CODE 354 clears showpart");
    assert!(alive(&s, lv), "// CODE 354 destroys nothing");
    assert_eq!(
        s.audio.len(),
        sounds_before,
        "// CODE 354 adds no sound of its own (obj_levelup Create's pickup stinger is the only voice)"
    );

    // The real timer: arming the lifetime to 2 must take exactly two ticks.
    let (mut s, _ui) = ui_scene(&b);
    let lv = spawn(&b, &mut s, LEVELUP, 10.0, 10.0);
    let p = spawn(&b, &mut s, PLAYER, 100.0, 100.0);
    s.instances.get_mut(&lv).unwrap().alarms[1] = 2;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(
        alive(&s, lv),
        "// CODE 353: one tick only counts the alarm down"
    );
    assert_eq!(s.instances[&lv].alarms[1], 1);
    s.tick(&b).unwrap();
    assert!(
        !alive(&s, lv),
        "// CODE 353 fires on its own timer at the armed tick"
    );
}

#[test]
fn weaponlevelup_alarm_1_destroys_on_its_own_timer() {
    let b = bundle();
    assert_eq!(
        codes(&b, WEAPONLEVELUP, 2, 1),
        vec![358],
        "// CODE 358 is obj_weaponlevelup Alarm_1"
    );
    let mut s = scene(&b);
    let wl = spawn(&b, &mut s, WEAPONLEVELUP, 10.0, 10.0);
    assert_eq!(
        s.instances[&wl].alarms[1], 90,
        "obj_weaponlevelup's Create arms the 90-tick lifetime"
    );
    s.dispatch(&b, wl, 2, 1).unwrap();
    assert!(!alive(&s, wl), "// CODE 358 is instance_destroy()");

    // Self-firing: arm slot 1 to 2 and let the scheduler deliver it.
    let wl2 = spawn(&b, &mut s, WEAPONLEVELUP, 10.0, 10.0);
    s.instances.get_mut(&wl2).unwrap().alarms[1] = 2;
    s.tick(&b).unwrap();
    assert!(
        alive(&s, wl2),
        "armed at 2: the first tick only counts down"
    );
    assert_eq!(s.instances[&wl2].alarms[1], 1);
    s.tick(&b).unwrap();
    assert!(!alive(&s, wl2), "// CODE 358 fires on the second tick");
}

// ---------------------------------------------------------------------------
// obj_UI / obj_warpanywhere — the shared HUD global and the warp record
// ---------------------------------------------------------------------------

#[test]
fn ui_step_clears_coinpickup_only_while_no_coinadd_exists() {
    let b = bundle();
    assert_eq!(
        codes(&b, UI, 3, 0),
        vec![369],
        "// CODE 369 is obj_UI Step_0"
    );
    let (mut s, ui) = ui_scene(&b);
    // obj_coinadd's Create reads obj_player.y for its two anchors, so
    // the counter needs a real player to spawn against.
    parked_player(&b, &mut s, 100.0, 100.0);
    let add = spawn(&b, &mut s, COINADD, 40.0, 40.0);

    s.globals.insert("coinpickup".into(), 1.0);
    s.dispatch(&b, ui, 3, 0).unwrap();
    assert_eq!(
        s.globals["coinpickup"], 1.0,
        "// CODE 369 leaves the counter alone while obj_coinadd exists"
    );

    // The counter's owner disappears: the branch `!instance_exists` is taken.
    kill(&mut s, add);
    s.dispatch(&b, ui, 3, 0).unwrap();
    assert_eq!(
        s.globals["coinpickup"], 0.0,
        "// CODE 369 zeroes the counter"
    );

    // Same answer through the scheduler's Step pass.
    s.globals.insert("coinpickup".into(), 3.0);
    s.tick(&b).unwrap();
    assert_eq!(
        s.globals["coinpickup"], 0.0,
        "// CODE 369 fires inside the tick"
    );

    // An inactive (not dead) obj_coinadd is not an instance_exists either.
    let add = spawn(&b, &mut s, COINADD, 40.0, 40.0);
    s.instances.get_mut(&add).unwrap().active = false;
    s.globals.insert("coinpickup".into(), 2.0);
    s.dispatch(&b, ui, 3, 0).unwrap();
    assert_eq!(
        s.globals["coinpickup"], 0.0,
        "instance_exists ignores inactive instances"
    );
}

#[test]
fn warpanywhere_create_zeroes_the_unlock_state_and_the_warp_globals() {
    let b = bundle();
    assert_eq!(
        codes(&b, WARPANYWHERE, 0, 0),
        vec![379],
        "// CODE 379 is obj_warpanywhere Create_0"
    );
    let mut s = scene(&b);
    let w = spawn(&b, &mut s, WARPANYWHERE, 300.0, 200.0);
    assert_eq!(fget(&s, w, "unlocked"), 0.0, "// CODE 379 unlocked = 0");
    assert_eq!(
        fget(&s, w, "treasuredoor"),
        0.0,
        "// CODE 379 treasuredoor = 0"
    );
    assert_eq!(
        s.globals.get("warpx").copied(),
        Some(0.0),
        "// CODE 379 global.warpx = 0"
    );
    assert_eq!(
        s.globals.get("warpy").copied(),
        Some(0.0),
        "// CODE 379 global.warpy = 0"
    );

    // Dirty both scopes and re-run the body: all four writes are unconditional.
    set(&mut s, w, "unlocked", 7.0);
    set(&mut s, w, "treasuredoor", 5.0);
    s.globals.insert("warpx".into(), 640.0);
    s.globals.insert("warpy".into(), 480.0);
    s.dispatch(&b, w, 0, 0).unwrap();
    assert_eq!(
        (fget(&s, w, "unlocked"), fget(&s, w, "treasuredoor")),
        (0.0, 0.0)
    );
    assert_eq!((s.globals["warpx"], s.globals["warpy"]), (0.0, 0.0));
    assert_eq!(
        fget(&s, w, "sprite_index"),
        85.0,
        "no other field is touched"
    );
}

// ---------------------------------------------------------------------------
// the eight shop bodies (Mouse_0)
// ---------------------------------------------------------------------------

/// One shop probe: seed globals, create the shopper, charge it a score, then
/// either click it through the scheduler or dispatch Mouse_0 straight.
fn shop_probe(
    b: &Bundle,
    object: i32,
    score_in: f64,
    globals: &[(&str, f64)],
    via_click: bool,
) -> (Scene, i32) {
    let mut s = scene(b);
    for (k, v) in globals {
        s.globals.insert((*k).into(), *v);
    }
    let id = spawn(b, &mut s, object, 300.0, 200.0);
    s.write(id, -1, "score", None, score_in).unwrap();
    if via_click {
        click(b, &mut s, id);
    } else {
        s.dispatch(b, id, 6, 0).unwrap();
    }
    (s, id)
}

#[test]
fn powerupgrade_mouse_buys_pwr_two_for_five_thousand() {
    let b = bundle();
    assert_eq!(
        codes(&b, POWERUPGRADE, 6, 0),
        vec![414],
        "// CODE 414 is obj_powerupgrade Mouse_0"
    );
    // The click path: a press inside the box, delivered by the scheduler's
    // Mouse_0 pass.
    let (mut s, id) = shop_probe(&b, POWERUPGRADE, 5000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 414 spends the whole 5000");
    assert_eq!(s.globals["pwr"], 2.0, "// CODE 414 sets global.pwr = 2");
    assert_eq!(
        s.globals["powerupgradebought"], 1.0,
        "// CODE 414 sets the bought flag"
    );
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 414 plays snd_coin once");
    assert!(!s.audio[0].looping);

    // One point short: the guard is `score >= 5000`.
    let (mut s, id) = shop_probe(&b, POWERUPGRADE, 4999.0, &[], false);
    assert_eq!(score(&mut s, id), 4999.0, "// CODE 414 needs the full 5000");
    assert_eq!(s.globals["pwr"], 1.0, "no power level is granted");
    assert_eq!(s.globals["powerupgradebought"], 0.0);
    assert!(s.audio.is_empty());

    // Already bought: the flag shuts the whole body, score or not.
    let (mut s, id) = shop_probe(
        &b,
        POWERUPGRADE,
        90_000.0,
        &[("powerupgradebought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 414 is a one-shot purchase"
    );
    assert_eq!(s.globals["pwr"], 1.0);
    assert!(s.audio.is_empty());

    // Muted: the purchase still happens, silently (the empty soundmute==1 stub).
    let (mut s, id) = shop_probe(&b, POWERUPGRADE, 5000.0, &[("soundmute", 1.0)], false);
    assert_eq!(score(&mut s, id), 0.0, "the spend is not gated on sound");
    assert_eq!(s.globals["pwr"], 2.0);
    assert!(s.audio.is_empty(), "// CODE 414 is silent while muted");
}

#[test]
fn powerupgrade2_mouse_buys_pwr_three_for_twenty_five_thousand() {
    let b = bundle();
    assert_eq!(
        codes(&b, POWERUPGRADE2, 6, 0),
        vec![416],
        "// CODE 416 is obj_powerupgrade2 Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, POWERUPGRADE2, 25_000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 416 spends 25000");
    assert_eq!(s.globals["pwr"], 3.0, "// CODE 416 sets global.pwr = 3");
    assert_eq!(s.globals["powerupgrade2bought"], 1.0);
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 416 plays snd_coin");

    let (mut s, id) = shop_probe(&b, POWERUPGRADE2, 24_999.0, &[], false);
    assert_eq!(
        score(&mut s, id),
        24_999.0,
        "// CODE 416 needs the full 25000"
    );
    assert_eq!(s.globals["pwr"], 1.0);
    assert_eq!(s.globals["powerupgrade2bought"], 0.0);

    let (mut s, id) = shop_probe(
        &b,
        POWERUPGRADE2,
        90_000.0,
        &[("powerupgrade2bought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 416 is a one-shot purchase"
    );
    assert_eq!(s.globals["pwr"], 1.0);
    assert!(s.audio.is_empty());

    let (s, _id) = shop_probe(&b, POWERUPGRADE2, 25_000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["pwr"], 3.0);
    assert!(s.audio.is_empty(), "// CODE 416 is silent while muted");
}

#[test]
fn powerupgrade3_mouse_buys_pwr_four_for_thirty_five_thousand() {
    let b = bundle();
    assert_eq!(
        codes(&b, POWERUPGRADE3, 6, 0),
        vec![418],
        "// CODE 418 is obj_powerupgrade3 Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, POWERUPGRADE3, 35_000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 418 spends 35000");
    assert_eq!(s.globals["pwr"], 4.0, "// CODE 418 sets global.pwr = 4");
    assert_eq!(s.globals["powerupgrade3bought"], 1.0);
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 418 plays snd_coin");

    let (mut s, id) = shop_probe(&b, POWERUPGRADE3, 34_999.0, &[], false);
    assert_eq!(
        score(&mut s, id),
        34_999.0,
        "// CODE 418 needs the full 35000"
    );
    assert_eq!(s.globals["pwr"], 1.0);
    assert_eq!(s.globals["powerupgrade3bought"], 0.0);

    let (mut s, id) = shop_probe(
        &b,
        POWERUPGRADE3,
        90_000.0,
        &[("powerupgrade3bought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 418 is a one-shot purchase"
    );
    assert_eq!(s.globals["pwr"], 1.0);
    assert!(s.audio.is_empty());

    let (s, _id) = shop_probe(&b, POWERUPGRADE3, 35_000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["pwr"], 4.0);
    assert!(s.audio.is_empty(), "// CODE 418 is silent while muted");
}

#[test]
fn triplejump_mouse_arms_the_triple_jump_for_three_thousand() {
    let b = bundle();
    assert_eq!(
        codes(&b, TRIPLEJUMP, 6, 0),
        vec![421],
        "// CODE 421 is obj_triplejump Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, TRIPLEJUMP, 3000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 421 spends 3000");
    assert_eq!(
        s.globals["tjumpactive"], 1.0,
        "// CODE 421 sets global.tjumpactive = 1"
    );
    assert_eq!(s.globals["triplejumpbought"], 1.0);
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 421 plays snd_coin");

    let (mut s, id) = shop_probe(&b, TRIPLEJUMP, 2999.0, &[], false);
    assert_eq!(score(&mut s, id), 2999.0, "// CODE 421 needs the full 3000");
    assert_eq!(s.globals["tjumpactive"], 0.0);
    assert_eq!(s.globals["triplejumpbought"], 0.0);

    let (mut s, id) = shop_probe(&b, TRIPLEJUMP, 9000.0, &[("triplejumpbought", 1.0)], false);
    assert_eq!(
        score(&mut s, id),
        9000.0,
        "// CODE 421 is a one-shot purchase"
    );
    assert_eq!(s.globals["tjumpactive"], 0.0);
    assert!(s.audio.is_empty());

    let (s, _id) = shop_probe(&b, TRIPLEJUMP, 3000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["tjumpactive"], 1.0);
    assert!(s.audio.is_empty(), "// CODE 421 is silent while muted");
}

#[test]
fn swordupgrade_mouse_is_gated_behind_the_two_later_tiers() {
    let b = bundle();
    assert_eq!(
        codes(&b, SWORDUPGRADE, 6, 0),
        vec![423],
        "// CODE 423 is obj_swordupgrade Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, SWORDUPGRADE, 3000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 423 spends 3000");
    assert_eq!(
        s.globals["swordupgradebought"], 1.0,
        "// CODE 423 sets the bought flag"
    );
    assert_eq!(s.globals["sword"], 1.0, "// CODE 423 sets global.sword = 1");
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 423 plays snd_coin");

    let (mut s, id) = shop_probe(&b, SWORDUPGRADE, 2999.0, &[], false);
    assert_eq!(score(&mut s, id), 2999.0, "// CODE 423 needs the full 3000");
    assert_eq!(s.globals["sword"], 0.0);
    assert_eq!(s.globals["swordupgradebought"], 0.0);

    // The outer guard: owning tier 2 or tier 3 closes this shop body entirely.
    for owned in ["swordupgrade2bought", "swordupgrade3bought"] {
        let (mut s, id) = shop_probe(&b, SWORDUPGRADE, 90_000.0, &[(owned, 1.0)], false);
        assert_eq!(
            score(&mut s, id),
            90_000.0,
            "// CODE 423's outer guard blocks {owned}"
        );
        assert_eq!(s.globals["sword"], 0.0, "no downgrade to sword = 1");
        assert!(s.audio.is_empty());
    }

    let (mut s, id) = shop_probe(
        &b,
        SWORDUPGRADE,
        90_000.0,
        &[("swordupgradebought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 423 is a one-shot purchase"
    );

    let (s, _id) = shop_probe(&b, SWORDUPGRADE, 3000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["sword"], 1.0);
    assert!(s.audio.is_empty(), "// CODE 423 is silent while muted");
}

#[test]
fn swordupgrade2_mouse_is_gated_behind_tier_three_only() {
    let b = bundle();
    assert_eq!(
        codes(&b, SWORDUPGRADE2, 6, 0),
        vec![425],
        "// CODE 425 is obj_swordupgrade2 Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, SWORDUPGRADE2, 10_000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 425 spends 10000");
    assert_eq!(s.globals["swordupgrade2bought"], 1.0);
    assert_eq!(s.globals["sword"], 2.0, "// CODE 425 sets global.sword = 2");
    // Tier 2 also marks tier 1 as owned, or the tier-1 shop would sell 1 later.
    assert_eq!(
        s.globals["swordupgradebought"], 1.0,
        "// CODE 425 sets swordupgradebought too"
    );
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 425 plays snd_coin");

    let (mut s, id) = shop_probe(&b, SWORDUPGRADE2, 9999.0, &[], false);
    assert_eq!(
        score(&mut s, id),
        9999.0,
        "// CODE 425 needs the full 10000"
    );
    assert_eq!(s.globals["sword"], 0.0);

    // The outer guard for tier 2 is tier 3 only: owning tier 1 does not block it.
    let (mut s, id) = shop_probe(
        &b,
        SWORDUPGRADE2,
        10_000.0,
        &[("swordupgradebought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        0.0,
        "// CODE 425 still sells while only tier 1 is owned"
    );
    assert_eq!(s.globals["sword"], 2.0);

    let (mut s, id) = shop_probe(
        &b,
        SWORDUPGRADE2,
        90_000.0,
        &[("swordupgrade3bought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 425's outer guard blocks tier 3 owners"
    );
    assert_eq!(s.globals["sword"], 0.0);
    assert!(s.audio.is_empty());

    let (mut s, id) = shop_probe(
        &b,
        SWORDUPGRADE2,
        90_000.0,
        &[("swordupgrade2bought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 425 is a one-shot purchase"
    );
    assert_eq!(s.globals["sword"], 0.0);

    let (s, _id) = shop_probe(&b, SWORDUPGRADE2, 10_000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["sword"], 2.0);
    assert!(s.audio.is_empty(), "// CODE 425 is silent while muted");
}

#[test]
fn healthregen_mouse_costs_seventy_five_thousand() {
    let b = bundle();
    assert_eq!(
        codes(&b, HEALTHREGEN, 6, 0),
        vec![431],
        "// CODE 431 is obj_healthregen Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, HEALTHREGEN, 75_000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 431 spends 75000");
    assert_eq!(
        s.globals["healthregenbought"], 1.0,
        "// CODE 431 sets the bought flag"
    );
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 431 plays snd_coin");
    // The body writes that flag and the score, nothing else.
    assert_eq!(
        s.globals["maxhp"], 4.0,
        "// CODE 431 grants no max hp itself"
    );
    assert_eq!(s.globals["health1"], 4.0);

    let (mut s, id) = shop_probe(&b, HEALTHREGEN, 74_999.0, &[], false);
    assert_eq!(
        score(&mut s, id),
        74_999.0,
        "// CODE 431 needs the full 75000"
    );
    assert_eq!(s.globals["healthregenbought"], 0.0);

    let (mut s, id) = shop_probe(
        &b,
        HEALTHREGEN,
        90_000.0,
        &[("healthregenbought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 431 is a one-shot purchase"
    );
    assert!(s.audio.is_empty());

    let (s, _id) = shop_probe(&b, HEALTHREGEN, 75_000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["healthregenbought"], 1.0);
    assert!(s.audio.is_empty(), "// CODE 431 is silent while muted");
}

#[test]
fn strengthupgrade_mouse_costs_three_thousand() {
    let b = bundle();
    assert_eq!(
        codes(&b, STRENGTHUPGRADE, 6, 0),
        vec![433],
        "// CODE 433 is obj_strengthupgrade Mouse_0"
    );
    let (mut s, id) = shop_probe(&b, STRENGTHUPGRADE, 3000.0, &[], true);
    assert_eq!(score(&mut s, id), 0.0, "// CODE 433 spends 3000");
    assert_eq!(
        s.globals["strengthupgradebought"], 1.0,
        "// CODE 433 sets the bought flag"
    );
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 433 plays snd_coin");

    let (mut s, id) = shop_probe(&b, STRENGTHUPGRADE, 2999.0, &[], false);
    assert_eq!(score(&mut s, id), 2999.0, "// CODE 433 needs the full 3000");
    assert_eq!(s.globals["strengthupgradebought"], 0.0);

    let (mut s, id) = shop_probe(
        &b,
        STRENGTHUPGRADE,
        90_000.0,
        &[("strengthupgradebought", 1.0)],
        false,
    );
    assert_eq!(
        score(&mut s, id),
        90_000.0,
        "// CODE 433 is a one-shot purchase"
    );
    assert!(s.audio.is_empty());

    let (s, _id) = shop_probe(&b, STRENGTHUPGRADE, 3000.0, &[("soundmute", 1.0)], false);
    assert_eq!(s.globals["strengthupgradebought"], 1.0);
    assert!(s.audio.is_empty(), "// CODE 433 is silent while muted");
}

// ---------------------------------------------------------------------------
// obj_dodged / obj_viewresolution / obj_phone / obj_logparts
// ---------------------------------------------------------------------------

#[test]
fn dodged_step_fades_four_hundredths_and_dies_below_zero() {
    let b = bundle();
    assert_eq!(
        codes(&b, DODGED, 3, 0),
        vec![466],
        "// CODE 466 is obj_dodged Step_0"
    );
    let mut s = scene(&b);
    let d = spawn(&b, &mut s, DODGED, 300.0, 200.0);
    assert_eq!(
        fget(&s, d, "alpha"),
        1.0,
        "obj_dodged's Create starts the floater fully opaque"
    );
    s.dispatch(&b, d, 3, 0).unwrap();
    assert!(
        (fget(&s, d, "alpha") - 0.96).abs() < 1e-12,
        "// CODE 466 alpha -= 0.04 per Step"
    );

    // The guard is `< 0`, so landing exactly on 0 keeps the instance alive.
    set(&mut s, d, "alpha", 0.04);
    s.dispatch(&b, d, 3, 0).unwrap();
    assert_eq!(fget(&s, d, "alpha"), 0.0);
    assert!(alive(&s, d), "// CODE 466: alpha 0.0 is not < 0");

    set(&mut s, d, "alpha", 0.02);
    s.dispatch(&b, d, 3, 0).unwrap();
    assert!(
        !alive(&s, d),
        "// CODE 466: alpha -0.02 < 0 -> instance_destroy"
    );

    // And the same body runs from the scheduler's Step pass.
    let d2 = spawn(&b, &mut s, DODGED, 300.0, 200.0);
    set(&mut s, d2, "alpha", 0.02);
    s.tick(&b).unwrap();
    assert!(!alive(&s, d2), "// CODE 466 fires inside the tick");
}

#[test]
fn viewresolution_create_kills_the_surface_and_arms_slot_zero() {
    let b = bundle();
    assert_eq!(
        codes(&b, VIEWRESOLUTION, 0, 0),
        vec![537],
        "// CODE 537 is obj_viewresolution Create_0"
    );
    assert_eq!(
        codes(&b, VIEWRESOLUTION, 2, 0),
        vec![538],
        "the armed alarm is obj_viewresolution's Alarm_0"
    );
    let mut s = scene(&b);
    let v = spawn(&b, &mut s, VIEWRESOLUTION, 300.0, 200.0);
    // application_surface_enable(false) is a stubbed no-op in this host; the
    // observable effect of the body is the armed timer.
    assert_eq!(s.instances[&v].alarms[0], 1, "// CODE 537 alarm[0] = 1");
    assert_eq!(
        &s.instances[&v].alarms[1..],
        &[-1; 11],
        "// CODE 537 touches no other timer"
    );

    // Re-running it on a dirty instance rewrites slot 0 only.
    s.instances.get_mut(&v).unwrap().alarms = [7; 12];
    s.dispatch(&b, v, 0, 0).unwrap();
    assert_eq!(s.instances[&v].alarms[0], 1);
    assert_eq!(
        &s.instances[&v].alarms[1..],
        &[7; 11],
        "// CODE 537 writes one slot"
    );

    // Self-firing: armed at 1, the very next tick must deliver it. obj_viewresolution's Alarm_0 reads
    // display_get_width/height (the scene defaults to the original's 1136x640),
    // so its own effect is the view table being rewritten.
    let mut s = scene(&b);
    let v = spawn(&b, &mut s, VIEWRESOLUTION, 300.0, 200.0);
    s.view_visible = [true; 8];
    s.tick(&b).unwrap();
    assert_eq!(
        s.instances[&v].alarms[0], -1,
        "// CODE 537's one-shot timer is spent"
    );
    assert!(
        s.view_visible[0],
        "obj_viewresolution's Alarm_0 leaves view 0 visible at 1136x640"
    );
    assert!(
        !s.view_visible[1],
        "obj_viewresolution's Alarm_0 turns the other views off"
    );
    assert!(!s.view_visible[6]);

    // obj_UI's Create spawns exactly one obj_viewresolution, so every
    // UI build runs this body once — the way the original reaches it in game.
    let (s_ui, _ui) = ui_scene(&b);
    assert_eq!(
        made(&s_ui, VIEWRESOLUTION),
        1,
        "obj_UI's Create spawns one obj_viewresolution, whose own Create is // CODE 537"
    );
}

#[test]
fn phone_draw_scales_by_the_current_view() {
    let b = bundle();
    assert_eq!(
        codes(&b, PHONE, 8, 0),
        vec![547],
        "// CODE 547 is obj_phone Draw_0"
    );
    let mut s = scene(&b);
    let phone = spawn(&b, &mut s, PHONE, 300.0, 200.0);
    for view in 0..7 {
        s.view_positions.insert(view, (0.0, 0.0));
    }
    // A sentinel the body never writes: a view it has no branch for must leave
    // both scales exactly as they were.
    let mut expect = BTreeMap::new();
    expect.insert(0, (0.8, 0.8));
    expect.insert(1, (0.8, 0.8));
    expect.insert(2, (5.0, 5.0));
    expect.insert(3, (1.0, 1.0));
    expect.insert(4, (1.0, 1.0));
    expect.insert(5, (0.8, 0.8));
    expect.insert(6, (0.8, 0.8));
    for (view, want) in expect {
        set(&mut s, phone, "image_xscale", 5.0);
        set(&mut s, phone, "image_yscale", 5.0);
        s.draw_view(&b, view).unwrap();
        assert_eq!(
            (
                fget(&s, phone, "image_xscale"),
                fget(&s, phone, "image_yscale")
            ),
            (want.0, want.1),
            "// CODE 547 branches on view_current == {view}"
        );
    }
    // draw_self() is the first statement, so the draw it records still carries
    // the sentinel the instance had before the branch ran: the scale the body
    // writes lands on the NEXT frame's draw, not on this one.
    let self_draw = s
        .draws
        .iter()
        .find(|d| d.instance == phone)
        .expect("// CODE 547 calls draw_self()");
    assert_eq!(
        self_draw.code, 547,
        "the self-draw is attributed to // CODE 547, not to a neighbouring body"
    );
    assert_eq!(self_draw.sprite, 161, "it draws the phone's own sprite");
    assert_eq!(
        (self_draw.scale_x, self_draw.scale_y),
        (5.0, 5.0),
        "the recorded self-draw carries the pre-branch scale"
    );
}

#[test]
fn logparts_step_pins_gravity() {
    let b = bundle();
    assert_eq!(
        codes(&b, LOGPARTS, 3, 0),
        vec![678],
        "// CODE 678 is obj_logparts Step_0"
    );
    let mut s = scene(&b);
    let l = spawn(&b, &mut s, LOGPARTS, 300.0, 200.0);
    assert_eq!(
        s.instances[&l].alarms[0], 30,
        "obj_logparts' Create arms the 30-tick cleanup"
    );
    set(&mut s, l, "gravity", 0.0);
    s.dispatch(&b, l, 3, 0).unwrap();
    assert_eq!(fget(&s, l, "gravity"), 1.0, "// CODE 678 gravity = 1");

    // Through the scheduler the same write lands before the physics pass, so the
    // piece starts falling this very frame.
    set(&mut s, l, "gravity", 0.0);
    set(&mut s, l, "vspeed", 0.0);
    let y0 = fget(&s, l, "y");
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, l, "gravity"),
        1.0,
        "// CODE 678 fires inside the tick"
    );
    assert!(
        fget(&s, l, "y") > y0,
        "the new gravity moved the piece down this frame"
    );
}

// ---------------------------------------------------------------------------
// the three "lifetime" alarms: obj_blade / obj_enemybullet / obj_enemybullet2
// ---------------------------------------------------------------------------

/// A parked player, so bodies that read obj_player.facing / obj_player.x have a
/// real instance to read. Created through the object's own Create.
fn parked_player(b: &Bundle, s: &mut Scene, x: f64, y: f64) -> i32 {
    let p = spawn(b, s, PLAYER, x, y);
    pin(s, p, x, y);
    p
}

#[test]
fn blade_alarm_0_destroys_the_blade() {
    let b = bundle();
    assert_eq!(
        codes(&b, BLADE, 2, 0),
        vec![273],
        "// CODE 273 is obj_blade Alarm_0"
    );
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);
    let blade = spawn(&b, &mut s, BLADE, 600.0, 300.0);
    assert_eq!(
        s.instances[&blade].alarms[1], 40,
        "obj_blade's Create arms the 40-tick throw timer"
    );
    s.dispatch(&b, blade, 2, 0).unwrap();
    assert!(!alive(&s, blade), "// CODE 273 is instance_destroy()");
    assert!(s.audio.is_empty(), "// CODE 273 makes no sound");

    // Self-firing on slot 0, with slot 1's own 40-tick throw timer still pending.
    let blade2 = spawn(&b, &mut s, BLADE, 600.0, 300.0);
    s.instances.get_mut(&blade2).unwrap().alarms[0] = 2;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(
        alive(&s, blade2),
        "armed at 2: the first tick only counts down"
    );
    assert_eq!(s.instances[&blade2].alarms[0], 1);
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(!alive(&s, blade2), "// CODE 273 fires on its own timer");
}

#[test]
fn enemybullet_alarm_0_destroys_the_bullet() {
    let b = bundle();
    assert_eq!(
        codes(&b, ENEMYBULLET, 2, 0),
        vec![312],
        "// CODE 312 is obj_enemybullet Alarm_0"
    );
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);
    let bullet = spawn(&b, &mut s, ENEMYBULLET, 600.0, 300.0);
    s.dispatch(&b, bullet, 2, 0).unwrap();
    assert!(!alive(&s, bullet), "// CODE 312 is instance_destroy()");
    assert!(s.audio.is_empty());
    assert_eq!(count(&s, DAMAGE), 0, "no stray floater");

    let bullet2 = spawn(&b, &mut s, ENEMYBULLET, 600.0, 300.0);
    s.instances.get_mut(&bullet2).unwrap().alarms[0] = 2;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(
        alive(&s, bullet2),
        "armed at 2: // CODE 312 has not fired yet"
    );
    assert_eq!(s.instances[&bullet2].alarms[0], 1);
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(
        !alive(&s, bullet2),
        "// CODE 312 fires on slot 0 of its own timer"
    );
}

#[test]
fn enemybullet2_alarm_3_destroys_the_bullet() {
    let b = bundle();
    assert_eq!(
        codes(&b, ENEMYBULLET2, 2, 3),
        vec![314],
        "// CODE 314 is obj_enemybullet2 Alarm_3"
    );
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);
    let bullet = spawn(&b, &mut s, ENEMYBULLET2, 600.0, 300.0);
    s.dispatch(&b, bullet, 2, 3).unwrap();
    assert!(!alive(&s, bullet), "// CODE 314 is instance_destroy()");
    assert!(s.audio.is_empty());

    // Slot 3, not slot 0: arming the wrong slot must leave it alive.
    let bullet2 = spawn(&b, &mut s, ENEMYBULLET2, 600.0, 300.0);
    s.instances.get_mut(&bullet2).unwrap().alarms[3] = 1;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(
        !alive(&s, bullet2),
        "// CODE 314 fires on slot 3 after one tick"
    );
    let bullet3 = spawn(&b, &mut s, ENEMYBULLET2, 600.0, 300.0);
    s.instances.get_mut(&bullet3).unwrap().alarms[0] = 1;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(alive(&s, bullet3), "slot 0 is not // CODE 314's slot");
}

// ---------------------------------------------------------------------------
// enemy status alarms: stun clears, the frost thaw, the wolf landing, poison
// ---------------------------------------------------------------------------

#[test]
fn enemy2_and_shooter1_alarm_5_clear_the_sword_stun() {
    let b = bundle();
    assert_eq!(
        codes(&b, ENEMY2, 2, 5),
        vec![127],
        "// CODE 127 is obj_enemy2 Alarm_5"
    );
    assert_eq!(
        codes(&b, SHOOTER1, 2, 5),
        vec![61],
        "// CODE 61 is obj_shooter1 Alarm_5"
    );
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);

    let e = spawn(&b, &mut s, ENEMY2, 300.0, 200.0);
    set(&mut s, e, "swordstunned", 1.0);
    s.instances.get_mut(&e).unwrap().alarms = [5; 12];
    s.dispatch(&b, e, 2, 5).unwrap();
    assert_eq!(
        fget(&s, e, "swordstunned"),
        0.0,
        "// CODE 127 clears swordstunned"
    );
    assert_eq!(
        s.instances[&e].alarms, [5; 12],
        "// CODE 127 writes no timer"
    );

    let sh = spawn(&b, &mut s, SHOOTER1, 400.0, 200.0);
    set(&mut s, sh, "swordstunned", 1.0);
    s.dispatch(&b, sh, 2, 5).unwrap();
    assert_eq!(
        fget(&s, sh, "swordstunned"),
        0.0,
        "// CODE 61 clears swordstunned"
    );
    assert!(alive(&s, sh), "// CODE 61 does not kill the gunner");

    // Self-firing on slot 5 (the slot the stun arms elsewhere in the family).
    let e2 = spawn(&b, &mut s, ENEMY2, 500.0, 200.0);
    set(&mut s, e2, "swordstunned", 1.0);
    s.instances.get_mut(&e2).unwrap().alarms[5] = 2;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, e2, "swordstunned"),
        1.0,
        "armed at 2: the first tick only counts down"
    );
    assert_eq!(s.instances[&e2].alarms[5], 1);
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, e2, "swordstunned"),
        0.0,
        "// CODE 127 fires on the second tick"
    );
}

#[test]
fn enemy2_alarm_3_thaws_the_frost_and_the_white_wash() {
    let b = bundle();
    assert_eq!(
        codes(&b, ENEMY2, 2, 3),
        vec![129],
        "// CODE 129 is obj_enemy2 Alarm_3"
    );
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);
    let e = spawn(&b, &mut s, ENEMY2, 300.0, 200.0);
    assert_eq!(
        fget(&s, e, "image_blend"),
        C_WHITE,
        "a fresh instance is white"
    );

    set(&mut s, e, "hptwofrozen", 1.0);
    s.dispatch(&b, e, 2, 3).unwrap();
    assert_eq!(
        fget(&s, e, "image_blend"),
        0.0,
        "// CODE 129 image_blend -= c_white"
    );
    assert_eq!(
        fget(&s, e, "hptwofrozen"),
        0.0,
        "// CODE 129 clears the frozen flag"
    );
    assert!(alive(&s, e), "// CODE 129 destroys nothing");

    // It is a subtraction, not an assignment: a tinted instance keeps the rest.
    set(&mut s, e, "image_blend", C_WHITE + 255.0);
    s.dispatch(&b, e, 2, 3).unwrap();
    assert_eq!(
        fget(&s, e, "image_blend"),
        255.0,
        "// CODE 129 subtracts, never clamps"
    );

    // Self-firing on slot 3.
    let e2 = spawn(&b, &mut s, ENEMY2, 500.0, 200.0);
    set(&mut s, e2, "hptwofrozen", 1.0);
    s.instances.get_mut(&e2).unwrap().alarms[3] = 2;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, e2, "hptwofrozen"),
        1.0,
        "armed at 2: the first tick only counts down"
    );
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, e2, "hptwofrozen"),
        0.0,
        "// CODE 129 fires on the second tick"
    );
    // image_blend is not asserted on this path: obj_enemy2's Step owns
    // the blend every frame and re-whitewashes it inside the same tick, after the
    // alarm has already thawed it. The direct dispatch above is where the body's
    // own subtraction is observable.
}

#[test]
fn wolf_alarm_7_lands_and_restores_the_default_pose() {
    let b = bundle();
    assert_eq!(
        codes(&b, WOLF, 2, 7),
        vec![137],
        "// CODE 137 is obj_wolf Alarm_7"
    );
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);
    let w = spawn(&b, &mut s, WOLF, 300.0, 200.0);
    assert_eq!(
        fget(&s, w, "sprite_index"),
        SPR_WOLF,
        "the object's own sprite is spr_wolf"
    );
    set(&mut s, w, "jumping", 1.0);
    set(&mut s, w, "sprite_index", 999.0);
    s.dispatch(&b, w, 2, 7).unwrap();
    assert_eq!(
        fget(&s, w, "jumping"),
        0.0,
        "// CODE 137 clears the jump flag"
    );
    assert_eq!(
        fget(&s, w, "sprite_index"),
        SPR_WOLF,
        "// CODE 137 sprite_index = spr_wolf"
    );
    assert!(alive(&s, w), "// CODE 137 destroys nothing");

    // Self-firing on slot 7.
    let w2 = spawn(&b, &mut s, WOLF, 500.0, 200.0);
    set(&mut s, w2, "jumping", 1.0);
    set(&mut s, w2, "sprite_index", 999.0);
    s.instances.get_mut(&w2).unwrap().alarms[7] = 2;
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, w2, "jumping"),
        1.0,
        "armed at 2: the first tick only counts down"
    );
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert_eq!(
        fget(&s, w2, "jumping"),
        0.0,
        "// CODE 137 fires on the second tick"
    );
    assert_eq!(fget(&s, w2, "sprite_index"), SPR_WOLF);
}

/// One poison tick of a beast whose hp field is `hp`: asserts the flag, the hp
/// delta, the damage number and the self-re-armed timer, then lets the timer
/// run for real.
fn poison_tick(b: &Bundle, object: i32, hp: &'static str) -> (f64, f64, i32) {
    let mut s = scene(b);
    let p = parked_player(b, &mut s, 100.0, 100.0);
    let e = spawn(b, &mut s, object, 300.0, 200.0);
    let hp0 = fget(&s, e, hp);
    assert!(
        hp0 > 3.0,
        "fixture: the {hp} field really is populated ({hp0})"
    );
    let before = ids(&s);
    s.dispatch(b, e, 2, 6).unwrap();
    assert_eq!(fget(&s, e, "poisoned"), 1.0, "the tick flags the beast");
    assert_eq!(
        hp0 - fget(&s, e, hp),
        0.25,
        "the tick takes a quarter point of hp"
    );
    let floaters = of(&s, DAMAGE, &spawned(&s, &before));
    assert_eq!(floaters.len(), 1, "one damage number per poison tick");
    assert_eq!(
        (fget(&s, floaters[0], "x"), fget(&s, floaters[0], "y")),
        (300.0, 200.0),
        "the number spawns on the beast"
    );
    assert_eq!(
        fget(&s, floaters[0], "damage"),
        0.25,
        "the body sets the floater's damage to its own 0.25"
    );
    assert_eq!(
        s.instances[&e].alarms[6], 30,
        "the tick re-arms slot 6 to 30 for the next one"
    );
    let hp_after_one = fget(&s, e, hp);
    // Measured, not assumed: 30 more ticks must deliver exactly one more tick.
    for _ in 0..29 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(b).unwrap();
    }
    assert_eq!(
        hp_after_one - fget(&s, e, hp),
        0.0,
        "29 ticks are not enough for the 30-tick poison clock"
    );
    pin(&mut s, p, 100.0, 100.0);
    s.tick(b).unwrap();
    assert_eq!(
        hp_after_one - fget(&s, e, hp),
        0.25,
        "the 30th tick delivers the next poison tick"
    );
    assert_eq!(s.instances[&e].alarms[6], 30, "and re-arms itself again");
    (hp0, fget(&s, e, hp), s.instances[&e].alarms[6])
}

#[test]
fn enemy2_alarm_6_is_the_self_arming_poison_tick() {
    let b = bundle();
    assert_eq!(
        codes(&b, ENEMY2, 2, 6),
        vec![126],
        "// CODE 126 is obj_enemy2 Alarm_6"
    );
    let (hp0, hp, slot) = poison_tick(&b, ENEMY2, "hptwo");
    assert_eq!(hp0 - hp, 0.5, "// CODE 126 ticked twice over 30 ticks");
    assert_eq!(slot, 30);
}

#[test]
fn bat_alarm_6_is_the_self_arming_poison_tick() {
    let b = bundle();
    assert_eq!(
        codes(&b, BAT, 2, 6),
        vec![235],
        "// CODE 235 is obj_bat Alarm_6"
    );
    let (hp0, hp, slot) = poison_tick(&b, BAT, "hpfour");
    assert_eq!(hp0 - hp, 0.5, "// CODE 235 ticked twice over 30 ticks");
    assert_eq!(slot, 30);
    // The bat's own hp field is hpfour: the same body shape, a different field.
    assert_ne!(hp0, 0.0);
}

// ---------------------------------------------------------------------------
// obj_slime Collision 34
// ---------------------------------------------------------------------------

#[test]
fn slime_collision_34_bounces_the_blob() {
    let b = bundle();
    assert_eq!(
        codes(&b, SLIME, 4, 34),
        vec![254],
        "// CODE 254 is obj_slime Collision_34"
    );
    let mut s = scene(&b);
    let blob = spawn(&b, &mut s, SLIME, 300.0, 200.0);
    set(&mut s, blob, "hspeed", 3.0);
    set(&mut s, blob, "vspeed", -5.0);
    // action_bounce(0, 0) is self-only: it needs no other instance in the pair.
    s.dispatch(&b, blob, 4, 34).unwrap();
    assert_eq!(fget(&s, blob, "hspeed"), -3.0, "// CODE 254 flips hspeed");
    assert_eq!(fget(&s, blob, "vspeed"), 5.0, "// CODE 254 flips vspeed");
    assert!(alive(&s, blob), "// CODE 254 destroys nothing");

    // Through the real collision pass: par_wall child overlapping the blob. The
    // probes are re-checked first, so the prediction below is a measurement of
    // the fixture, not a guess.
    let mut s = scene(&b);
    let p = parked_player(&b, &mut s, 100.0, 100.0);
    let blob = spawn(&b, &mut s, SLIME, 300.0, 200.0);
    let wall = spawn(&b, &mut s, WALL, 302.0, 200.0);
    set(&mut s, blob, "hspeed", 3.0);
    set(&mut s, blob, "vspeed", 0.0);
    assert!(
        s.call(&b, blob, "place_meeting", &[302.0, 200.0, PAR_WALL as f64])
            .unwrap()
            > 0.0,
        "fixture: the wall overlaps the blob"
    );
    assert_eq!(
        s.call(&b, blob, "instance_place", &[305.0, 198.0, PAR_WALL as f64])
            .unwrap(),
        wall as f64,
        "fixture: the forward probe (x + 5, y - 2) also reaches the wall"
    );
    assert_eq!(
        s.call(&b, blob, "instance_place", &[295.0, 198.0, PAR_WALL as f64])
            .unwrap(),
        wall as f64,
        "fixture: the backward probe (x - 5, y - 2) reaches it too"
    );
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    // obj_slime's Step probes leave hspeed at +2 (right probe -2, then the left
    // probe +2 again), and the clear sight line to the parked player lets its
    // pounce fire in the same Step (vspeed = -8). The collision pass then runs
    // // CODE 254 on top of both and reverses them.
    assert_eq!(
        fget(&s, blob, "hspeed"),
        -2.0,
        "// CODE 254 reverses the hspeed obj_slime's Step left"
    );
    assert_eq!(
        fget(&s, blob, "vspeed"),
        8.0,
        "// CODE 254 reverses the pounce (the Step left -8)"
    );
    assert_eq!(
        fget(&s, blob, "gravity"),
        0.0,
        "obj_slime's Step parked the blob on the wall"
    );
    assert!(alive(&s, blob));
}

// ---------------------------------------------------------------------------
// obj_ghost Alarm_0 — the drop fan and its 44 `with` sites
// ---------------------------------------------------------------------------

/// The coin tier table exactly as CODE 151 encodes it: (tier, x offsets from the
/// ghost, spread slot per coin).
const GHOST_COIN_FAN: [(f64, &[f64], &[&str]); 5] = [
    (
        1.0,
        &[0.0, 2.0, -2.0, 4.0, -4.0],
        &[
            "coinspread",
            "coinspread2",
            "coinspread3",
            "coinspread4",
            "coinspread5",
        ],
    ),
    (
        2.0,
        &[0.0, 2.0, -2.0, 4.0, -4.0, -10.0, 6.0, -6.0, 8.0],
        &[
            "coinspread",
            "coinspread2",
            "coinspread3",
            "coinspread4",
            "coinspread5",
            "coinspread6",
            "coinspread7",
            "coinspread8",
            "coinspread9",
        ],
    ),
    (
        3.0,
        &[0.0, 2.0, -2.0, 4.0, -4.0, -10.0, 6.0, -6.0],
        &[
            "coinspread",
            "coinspread2",
            "coinspread3",
            "coinspread4",
            "coinspread5",
            "coinspread6",
            "coinspread7",
            "coinspread8",
        ],
    ),
    (
        4.0,
        &[0.0, 2.0, -2.0, 4.0, -4.0, 11.0, 6.0, -6.0, 8.0, -8.0, -11.0],
        &[
            "coinspread",
            "coinspread2",
            "coinspread3",
            "coinspread4",
            "coinspread5",
            "coinspread6",
            "coinspread7",
            "coinspread8",
            "coinspread9",
            "coinspread10",
            "coinspread11",
        ],
    ),
    (
        5.0,
        &[0.0, 2.0, -2.0, 4.0, -4.0, 11.0, 6.0, -6.0, 8.0, -8.0],
        &[
            "coinspread",
            "coinspread2",
            "coinspread3",
            "coinspread4",
            "coinspread5",
            "coinspread6",
            "coinspread7",
            "coinspread8",
            "coinspread9",
            "coinspread10",
        ],
    ),
];

#[test]
fn ghost_alarm_0_sprays_the_configured_loot_fan() {
    let b = bundle();
    assert_eq!(
        codes(&b, GHOST, 2, 0),
        vec![151],
        "// CODE 151 is obj_ghost Alarm_0"
    );
    let mut s = scene(&b);
    let g = spawn(&b, &mut s, GHOST, 300.0, 200.0);
    // obj_ghost's Create rolls coindrop/hpdrop with choose(); pin them so the fan is exact.
    set(&mut s, g, "coindrop", 4.0);
    set(&mut s, g, "hpdrop", 1.0);
    set(&mut s, g, "xpdrop", 1.0);
    assert_eq!(
        s.globals["gemdropenabled"], 1.0,
        "a fresh start enables gem drops"
    );
    let before = ids(&s);

    s.dispatch(&b, g, 2, 0).unwrap();

    // global.soundmute == 0 -> one snd_bee (sond 0), not looping.
    assert_eq!(audio(&s), vec![SND_BEE], "// CODE 151 plays snd_bee once");
    assert!(!s.audio[0].looping);

    let new = spawned(&s, &before);
    // gemdropenabled == 1: one gem, 35px above the ghost.
    let gems = of(&s, GEM, &new);
    assert_eq!(gems.len(), 1, "// CODE 151 drops one gem");
    assert_eq!(
        (fget(&s, gems[0], "x"), fget(&s, gems[0], "y")),
        (300.0, 165.0)
    );

    // hpdrop == 1: one heart.
    let hearts = of(&s, HEALTH, &new);
    assert_eq!(
        hearts.len(),
        1,
        "// CODE 151 drops one heart for hpdrop == 1"
    );
    assert_eq!(
        (fget(&s, hearts[0], "x"), fget(&s, hearts[0], "y")),
        (300.0, 165.0)
    );

    // xpdrop == 1: one orb, aimed by `with (ID) motion_set(global.xpspread, 5)`.
    let orbs = of(&s, XPORB, &new);
    assert_eq!(orbs.len(), 1, "// CODE 151 drops one XP orb");
    assert_eq!(
        (fget(&s, orbs[0], "x"), fget(&s, orbs[0], "y")),
        (300.0, 165.0)
    );
    assert_eq!(
        fget(&s, orbs[0], "direction"),
        s.globals["xpspread"],
        "// CODE 151's with (ID) sets the orb's direction from global.xpspread"
    );
    assert_eq!(
        fget(&s, orbs[0], "speed"),
        5.0,
        "motion_set's speed argument is 5"
    );

    // coindrop == 4: the eleven-coin tier, each through its own with (ID<n>).
    let coins = of(&s, SILVERCOIN, &new);
    let (_, offsets, slots) = GHOST_COIN_FAN[3];
    assert_eq!(
        coins.len(),
        offsets.len(),
        "// CODE 151 tier 4 sprays eleven coins"
    );
    let mut by_offset: BTreeMap<i64, i32> = BTreeMap::new();
    for id in &coins {
        assert_eq!(fget(&s, *id, "y"), 165.0, "every coin drops at y - 35");
        let key = (fget(&s, *id, "x") - 300.0) as i64;
        assert!(
            by_offset.insert(key, *id).is_none(),
            "one coin per offset ({key})"
        );
    }
    for (slot, offset) in slots.iter().zip(offsets.iter()) {
        let id = by_offset[&(*offset as i64)];
        assert_eq!(
            fget(&s, id, "direction"),
            s.globals[*slot],
            "// CODE 151's with (ID) on the x {offset:+} coin reads global.{slot}"
        );
        assert_eq!(fget(&s, id, "speed"), 5.0, "every coin leaves at speed 5");
    }
    // And no coin was aimed by a slot the body did not name.
    let used: Vec<f64> = coins.iter().map(|id| fget(&s, *id, "direction")).collect();
    let named: Vec<f64> = slots.iter().map(|k| s.globals[*k]).collect();
    for d in &named {
        assert!(
            used.contains(d),
            "every spread slot the body names was applied"
        );
    }

    // The body ends in action_kill_object(), and obj_ghost's Destroy counts the kill.
    assert!(!alive(&s, g), "// CODE 151 ends in action_kill_object()");
    assert_eq!(
        s.globals["ghostskilled"], 1.0,
        "obj_ghost's Destroy counts the ghost"
    );
    assert_eq!(
        s.globals["enemieskilled"], 1.0,
        "obj_ghost's Destroy counts the kill"
    );
    assert_eq!(
        count(&s, SMALLPUFF),
        1,
        "obj_ghost's Destroy leaves one obj_smallpuff"
    );
}

#[test]
fn ghost_alarm_0_coin_tiers_and_the_drop_gates() {
    let b = bundle();
    assert_eq!(
        codes(&b, GHOST, 2, 0),
        vec![151],
        "// CODE 151 is obj_ghost Alarm_0"
    );

    // Every coin tier, plus the hpdrop / xpdrop gates, in one sweep: hpdrop and
    // xpdrop are pinned to 0, so the absence of hearts and orbs is that gate.
    for (tier, offsets, slots) in GHOST_COIN_FAN {
        let mut s = scene(&b);
        let g = spawn(&b, &mut s, GHOST, 300.0, 200.0);
        set(&mut s, g, "coindrop", tier);
        set(&mut s, g, "hpdrop", 0.0);
        set(&mut s, g, "xpdrop", 0.0);
        let before = ids(&s);
        s.dispatch(&b, g, 2, 0).unwrap();
        let new = spawned(&s, &before);

        assert_eq!(
            of(&s, SILVERCOIN, &new).len(),
            offsets.len(),
            "// CODE 151 coindrop == {tier} sprays {} coins",
            offsets.len()
        );
        assert_eq!(
            of(&s, HEALTH, &new).len(),
            0,
            "// CODE 151 hpdrop == 0 drops no heart"
        );
        assert_eq!(
            of(&s, XPORB, &new).len(),
            0,
            "// CODE 151 xpdrop == 0 drops no orb"
        );
        assert_eq!(
            of(&s, GEM, &new).len(),
            1,
            "the gem gate is independent of coindrop"
        );
        assert!(!alive(&s, g), "// CODE 151 still kills the ghost");

        let mut got: Vec<i64> = of(&s, SILVERCOIN, &new)
            .iter()
            .map(|id| (fget(&s, *id, "x") - 300.0) as i64)
            .collect();
        got.sort();
        let mut want: Vec<i64> = offsets.iter().map(|o| *o as i64).collect();
        want.sort();
        assert_eq!(got, want, "// CODE 151 tier {tier} offsets");
        for slot in slots {
            assert!(
                s.globals.contains_key(*slot),
                "// CODE 151 tier {tier} names global.{slot} (set by obj_muting's Create)"
            );
        }
    }

    // gemdropenabled == 0 drops no gem; the coin fan is untouched by that gate.
    let mut s = scene(&b);
    let g = spawn(&b, &mut s, GHOST, 300.0, 200.0);
    set(&mut s, g, "coindrop", 1.0);
    set(&mut s, g, "hpdrop", 0.0);
    set(&mut s, g, "xpdrop", 0.0);
    s.globals.insert("gemdropenabled".into(), 0.0);
    let before = ids(&s);
    s.dispatch(&b, g, 2, 0).unwrap();
    let new = spawned(&s, &before);
    assert_eq!(
        of(&s, GEM, &new).len(),
        0,
        "// CODE 151 gemdropenabled == 0 drops no gem"
    );
    assert_eq!(
        of(&s, SILVERCOIN, &new).len(),
        5,
        "the coin tier still fires"
    );
    assert!(!alive(&s, g));

    // instance_number(obj_silvercoin) >= 20 closes the whole else-if: the gem
    // still drops, every other drop is suppressed.
    let mut s = scene(&b);
    for _ in 0..20 {
        spawn(&b, &mut s, SILVERCOIN, -500.0, -500.0);
    }
    assert_eq!(
        count(&s, SILVERCOIN),
        20,
        "fixture: the twenty coins are what the >= 20 gate counts"
    );
    assert_eq!(
        s.call(&b, 0, "instance_number", &[SILVERCOIN as f64])
            .unwrap(),
        20.0,
        "fixture: instance_number agrees with the live-instance count"
    );
    let g = spawn(&b, &mut s, GHOST, 300.0, 200.0);
    set(&mut s, g, "coindrop", 5.0);
    set(&mut s, g, "hpdrop", 1.0);
    set(&mut s, g, "xpdrop", 1.0);
    let before = ids(&s);
    s.dispatch(&b, g, 2, 0).unwrap();
    let new = spawned(&s, &before);
    assert_eq!(
        of(&s, GEM, &new).len(),
        1,
        "// CODE 151's gem gate precedes the coin count"
    );
    assert_eq!(
        of(&s, SILVERCOIN, &new).len(),
        0,
        "// CODE 151 >= 20 coins: no fan at all"
    );
    assert_eq!(of(&s, HEALTH, &new).len(), 0);
    assert_eq!(of(&s, XPORB, &new).len(), 0);
    assert!(!alive(&s, g), "the kill is outside the gate");
}

#[test]
fn ghost_with_sites_pair_their_environment_frames() {
    // `// CODE 151` carries 44 `with (ID<n>)` blocks and every pushenv/popenv is
    // paired here. The kernel's empty-selection path jumps to the *pairing*
    // popenv, which then pops the frame it was just handed - so balance for an
    // empty selection set is exactly this pairing: pushenv's target is its own
    // popenv, and that popenv's loop target is the block body right after the
    // pushenv. The runtime half of the evidence is the drop-fan tests above: the
    // VM refuses to return from a body that leaves a frame or a stack slot
    // behind ("unbalanced stack/environment at CODE exit").
    let b = bundle();
    let code = b.codes.iter().find(|c| c.id == 151).expect("// CODE 151");
    let at: BTreeMap<usize, usize> = code
        .instructions
        .iter()
        .enumerate()
        .map(|(k, i)| (i.offset, k))
        .collect();
    let mut pairs = 0usize;
    let mut receivers = 0usize;
    for (k, i) in code.instructions.iter().enumerate() {
        let target = match i.op {
            Op::Pushenv { target } => target,
            _ => continue,
        };
        let pk = *at
            .get(&target)
            .expect("// CODE 151: pushenv target is an instruction");
        match &code.instructions[pk].op {
            Op::Popenv { target: back } => assert_eq!(
                *back,
                code.instructions[k + 1].offset,
                "// CODE 151: the popenv loops back to the block body"
            ),
            other => panic!("// CODE 151: pushenv targets {other:?}, not its own popenv"),
        }
        // The receiver is the instance id the block just created: `load ID<n>`
        // (or ID) then `cast to=2`, never an object constant.
        assert!(
            matches!(code.instructions[k - 1].op, Op::Cast { to: 2 }),
            "// CODE 151: the with receiver is a cast-to-instance"
        );
        match &code.instructions[k - 2].op {
            Op::Load { name, .. } if name.starts_with("ID") => receivers += 1,
            other => panic!("// CODE 151: with receiver is not an ID<n> variable: {other:?}"),
        }
        pairs += 1;
    }
    assert_eq!(pairs, 44, "// CODE 151 has 44 with-blocks");
    assert_eq!(receivers, 44, "all 44 receivers are ID variables");
    assert_eq!(
        code.instructions
            .iter()
            .filter(|i| matches!(i.op, Op::Popenv { .. }))
            .count(),
        44,
        "// CODE 151 has 44 environment frames"
    );
}
