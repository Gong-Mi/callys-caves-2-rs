//! wl39-items batch 1 — id-level semantic tests for the pickups, projectiles
//! and shop-popup bodies the census still lists as `object_cited_contract`:
//! their objects were named by a contract but no test ever named the body, so
//! nothing asserted what the body does. Every test below drives the real event
//! dispatch (or the real scheduler tick) and names its body as `// CODE NNN`.
//!
//! Scope statement: these are IR regression semantics for THIS rewrite's code
//! host — each assertion is read off the recovered GML and the bytecode IR of
//! that one body. They are not a proof of equivalence with the original ARM
//! runner.
//!
//! Fixture (same wiring the app's `GameState::enable_ir_gameplay` does):
//!   * every SPRT record from `assets/game.droid` — bounds, recorded manual
//!     bbox and per-frame masks — so `instance_place` / `distance_to_object`
//!     box instances through the original Compute_BoundingBox;
//!   * one obj_pwrlevelinitialize (103) so global.P_System / global.Particle1
//!     exist for the impact particle bursts; left inert afterwards;
//!   * one obj_UI (66, CODE 365) so global.coinsound / global.swordsound hold
//!     their original choose() values and obj_UI.x resolves for obj_levelup's
//!     Create. Its touch-button children and its own progression alarms are
//!     parked so the batch's tick windows only contain the bodies under test.
//!
//! Walls: obj_woodblock (158) stands in for par_wall. Its Create (CODE 684)
//! only pins `type = 1` and its spr_woodblock (169) box is recorded, so a
//! fixture wall has deterministic geometry — unlike obj_wall's 770-instruction
//! room-switch Create. Every wall placement is re-checked through the engine's
//! own `instance_place` before the assertion that depends on it.
//!
//! Player discipline: the player stays alive AND active until the projectile's
//! Create has read obj_player.facing/x/y, and it is never parked while it is
//! itself the hit-test target (Scene::select filters alive+active).
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds, TextCommand};
use std::path::Path;

const P: i32 = 0;
const INIT: i32 = 103;
const UI: i32 = 66;
const PARRY: i32 = 12;
const BULLETSPARK: i32 = 13;
const KNIFE: i32 = 15;
const HULKING: i32 = 21;
const WOLF: i32 = 23;
const PAR_WALL: i32 = 34;
const BOMB: i32 = 37;
const ARROW: i32 = 38;
const BULLET: i32 = 39;
const LASERBEAM: i32 = 41;
const BOOMERANGTHROW: i32 = 43;
const SWORD: i32 = 46;
const FIREBALL: i32 = 52;
const FIREPROJECTILE: i32 = 54;
const BOSS3PROJECTILE: i32 = 55;
const SILVERCOIN: i32 = 60;
const HEALTH: i32 = 62;
const LEVELUP: i32 = 63;
const BOOMERANG: i32 = 71;
const FOUNDWEAPON: i32 = 82;
const DAMAGE: i32 = 104;
const DODGED: i32 = 106;
const COINADD: i32 = 132;
/// obj_woodblock: the fixture's par_wall stand-in (see the module header).
const WALL: i32 = 158;
const SMALLPUFF: i32 = 187;

/// SOND ids taken from the IR constant list of the body that plays them.
const SND_EXPLODE2: i32 = 8;
const SND_COIN: i32 = 19;
const SND_IMPACTSOUND2: i32 = 23;

/// Sprite constants read straight out of the IR of CODE 311 / CODE 278.
const SPR_SWORD1: f64 = 45.0;
const SPR_SWORD4: f64 = 48.0;
const SPR_BIGEXPLOSION: f64 = 50.0;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

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

fn kill(s: &mut Scene, id: i32) {
    if let Some(i) = s.instances.get_mut(&id) {
        i.alive = false;
    }
}

fn ids(s: &Scene) -> Vec<i32> {
    s.instances.keys().copied().collect()
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    wire_sprite_geometry(&mut s);

    // CODE 458 builds the particle system every impact branch posts into.
    let init = s.create(b, INIT, -1000.0, -1000.0).expect("obj_pwrlevelinitialize");
    kill(&mut s, init);

    // CODE 365 sets global.coinsound / global.swordsound and spawns the touch
    // UI. The UI itself stays alive (obj_levelup's Create reads obj_UI.x), its
    // buttons are parked, and its progression alarms are disarmed so they
    // cannot recompute globals inside this batch's tick windows.
    let before = ids(&s);
    let ui = s.create(b, UI, 0.0, 0.0).expect("obj_UI");
    for id in ids(&s) {
        if id != ui && !before.contains(&id) {
            kill(&mut s, id);
        }
    }
    s.instances.get_mut(&ui).unwrap().alarms = [-1; 12];
    assert!(
        matches!(s.globals.get("coinsound").copied(), Some(19.0) | Some(20.0)),
        "CODE 365 leaves global.coinsound at choose(19, 20)"
    );
    assert!(
        matches!(s.globals.get("swordsound").copied(), Some(13.0) | Some(14.0)),
        "CODE 365 leaves global.swordsound at choose(13, 14)"
    );
    s
}

fn player(s: &mut Scene, b: &Bundle, x: f64, y: f64, facing: f64) -> i32 {
    let p = s.create(b, P, x, y).expect("player");
    set(s, p, "facing", facing);
    p
}

fn set(s: &mut Scene, id: i32, name: &str, v: f64) {
    s.instances.get_mut(&id).unwrap().fields.insert(name.into(), v);
}

fn fget(s: &Scene, id: i32, name: &str) -> f64 {
    s.instances.get(&id).and_then(|i| i.fields.get(name)).copied().unwrap_or(0.0)
}

fn alive(s: &Scene, id: i32) -> bool {
    s.instances.get(&id).map_or(false, |i| i.alive)
}

fn audio(s: &Scene) -> Vec<i32> {
    s.audio.iter().map(|a| a.sound).collect()
}

/// Instances of `object` created since the `before` snapshot.
fn spawned(before: &[i32], s: &Scene, object: i32) -> Vec<i32> {
    let mut v: Vec<i32> = s
        .instances
        .iter()
        .filter(|(id, i)| i.object == object && !before.contains(id))
        .map(|(id, _)| *id)
        .collect();
    v.sort();
    v
}

/// Park a helper instance: out of the scheduler and off its own velocity.
fn park(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.active = false;
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

// ---- CODE 344 / 345: obj_silvercoin ----------------------------------------

#[test]
fn silvercoin_create_pins_friction_type_and_the_ground_origin() {
    let b = bundle();
    let mut s = scene(&b);
    // Open air: CODE 344's par_wall probe at (x, y - 1) misses, so the coin
    // keeps its own y as the floor it never falls past.
    let coin = s.create(&b, SILVERCOIN, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, coin, "friction"), 0.3, "// CODE 344 friction = 0.3");
    assert_eq!(fget(&s, coin, "type"), 3.0, "// CODE 344 type = 3");
    assert_eq!(fget(&s, coin, "yorigin"), 200.0, "no roof -> yorigin = y");

    // Buried in a wall: the same probe reaches the fixture wall, so the origin
    // drops one 32px tile below the coin.
    let wall = s.create(&b, WALL, 300.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, coin, "instance_place", &[300.0, 199.0, PAR_WALL as f64]).unwrap(),
        wall as f64,
        "fixture: the (x, y - 1) probe reaches the wall through par_wall"
    );
    let coin2 = s.create(&b, SILVERCOIN, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, coin2, "friction"), 0.3);
    assert_eq!(fget(&s, coin2, "type"), 3.0);
    assert_eq!(fget(&s, coin2, "yorigin"), 232.0, "roofed -> yorigin = y + 32");
}

#[test]
fn silvercoin_destroy_plays_the_room_coin_sound() {
    let b = bundle();
    let mut s = scene(&b);
    let want = s.globals["coinsound"] as i32;
    let coin = s.create(&b, SILVERCOIN, 300.0, 200.0).unwrap();
    s.destroy(&b, coin).unwrap();
    assert_eq!(
        audio(&s),
        vec![want],
        "// CODE 345 plays global.coinsound once (priority 0, not looping)"
    );
    assert!(!s.audio[0].looping);

    // global.soundmute == 1 takes the empty branch: the coin vanishes silently.
    let mut s = scene(&b);
    s.globals.insert("soundmute".into(), 1.0);
    let coin = s.create(&b, SILVERCOIN, 300.0, 200.0).unwrap();
    s.destroy(&b, coin).unwrap();
    assert!(s.audio.is_empty(), "muted coin makes no sound");
    assert!(!alive(&s, coin), "it is still destroyed");
}

// ---- CODE 349 / 350: obj_health --------------------------------------------

#[test]
fn health_create_rolls_healthrange_and_the_ground_origin() {
    let b = bundle();
    let mut s = scene(&b);
    let h = s.create(&b, HEALTH, 300.0, 200.0).unwrap();
    let r = fget(&s, h, "healthrange");
    assert!([1.0, 2.0].contains(&r), "// CODE 349 healthrange = choose(1, 2), got {r}");
    assert_eq!(fget(&s, h, "gravity"), 0.4, "// CODE 349 gravity = 0.4");
    assert_eq!(fget(&s, h, "vspeed"), -2.0, "// CODE 349 vspeed = -2 (the pop)");
    assert_eq!(fget(&s, h, "type"), 5.0, "// CODE 349 type = 5");
    assert_eq!(fget(&s, h, "friction"), 0.3, "// CODE 349 friction = 0.3");
    assert_eq!(fget(&s, h, "yorigin"), 200.0, "no roof -> yorigin = y");

    let wall = s.create(&b, WALL, 300.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, h, "instance_place", &[300.0, 199.0, PAR_WALL as f64]).unwrap(),
        wall as f64,
        "fixture: the (x, y - 1) probe reaches the wall through par_wall"
    );
    let h2 = s.create(&b, HEALTH, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, h2, "yorigin"), 232.0, "roofed -> yorigin = y + 32");
}

#[test]
fn health_destroy_plays_snd_coin() {
    let b = bundle();
    let mut s = scene(&b);
    let h = s.create(&b, HEALTH, 300.0, 200.0).unwrap();
    s.destroy(&b, h).unwrap();
    assert_eq!(SND_COIN, 19, "IR constant 19 of // CODE 350 is snd_coin");
    assert_eq!(audio(&s), vec![SND_COIN], "// CODE 350 plays snd_coin once");
    assert!(!s.audio[0].looping);

    let mut s = scene(&b);
    s.globals.insert("soundmute".into(), 1.0);
    let h = s.create(&b, HEALTH, 300.0, 200.0).unwrap();
    s.destroy(&b, h).unwrap();
    assert!(s.audio.is_empty(), "muted heart makes no sound");
}

// ---- CODE 459 / 460: obj_damage --------------------------------------------

#[test]
fn damage_create_seeds_the_floater_contract() {
    let b = bundle();
    let mut s = scene(&b);
    let d = s.create(&b, DAMAGE, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, d, "image_speed"), 0.0, "// CODE 459 image_speed = 0");
    let range = fget(&s, d, "range");
    assert!((60.0..=120.0).contains(&range), "range = random_range(60, 120), got {range}");
    assert_eq!(fget(&s, d, "direction"), range, "direction copies range verbatim");
    assert_eq!(fget(&s, d, "speed"), 4.0, "// CODE 459 speed = 4");
    assert_eq!(fget(&s, d, "damage"), 0.0, "damage starts at 0 (the caller sets it)");
    assert_eq!(fget(&s, d, "alpha"), 1.0, "// CODE 459 alpha = 1");
    assert_eq!(fget(&s, d, "sprite_index"), -1.0, "obj_damage carries no sprite");

    // The spread really is random: a dozen draws must not share one angle.
    let mut dirs = vec![range];
    for _ in 0..12 {
        let id = s.create(&b, DAMAGE, 300.0, 200.0).unwrap();
        let r = fget(&s, id, "range");
        assert!((60.0..=120.0).contains(&r), "every draw stays in 60..120, got {r}");
        assert_eq!(fget(&s, id, "direction"), r);
        dirs.push(r);
    }
    assert!(dirs.iter().any(|d| *d != dirs[0]), "random_range varies between draws");
}

#[test]
fn damage_step_fades_four_hundredths_and_dies_below_zero() {
    let b = bundle();
    let mut s = scene(&b);
    let d = s.create(&b, DAMAGE, 300.0, 200.0).unwrap();
    s.dispatch(&b, d, 3, 0).unwrap();
    assert!(
        (fget(&s, d, "alpha") - 0.96).abs() < 1e-12,
        "// CODE 460 alpha -= 0.04 every Step"
    );

    // Exactly 0.04 lands on 0.0, and the guard is `< 0`, not `<= 0`.
    set(&mut s, d, "alpha", 0.04);
    s.dispatch(&b, d, 3, 0).unwrap();
    assert_eq!(fget(&s, d, "alpha"), 0.0);
    assert!(alive(&s, d), "alpha 0.0 is not < 0: the floater survives");

    // A hair under zero takes the same branch one Step later.
    set(&mut s, d, "alpha", 0.02);
    s.dispatch(&b, d, 3, 0).unwrap();
    assert!(!alive(&s, d), "alpha -0.02 < 0 -> instance_destroy");

    // And the body runs from the scheduler, not only from a direct dispatch.
    let d2 = s.create(&b, DAMAGE, 300.0, 200.0).unwrap();
    set(&mut s, d2, "alpha", 0.02);
    s.tick(&b).unwrap();
    assert!(!alive(&s, d2), "// CODE 460 fires inside the tick's Step pass");
}

// ---- CODE 329: obj_fireball -------------------------------------------------

#[test]
fn fireball_create_fans_the_launch_by_twentyfive_degrees() {
    let b = bundle();
    let mut s = scene(&b);
    let f = s.create(&b, FIREBALL, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, f, "speed"), -10.0, "// CODE 329 motion_set(..., -10)");
    let dir = fget(&s, f, "direction");
    assert!((-25.0..=25.0).contains(&dir), "image_angle 0 +/- random(25) -> {dir}");
    let rad = dir.to_radians();
    assert!(
        (fget(&s, f, "hspeed") - (-10.0) * rad.cos()).abs() < 1e-9,
        "motion_set derives hspeed from (direction, speed)"
    );
    assert!((fget(&s, f, "vspeed") - 10.0 * rad.sin()).abs() < 1e-9);

    // Re-run the body from a different base angle: the fan is centred on
    // image_angle and always exits at magnitude 10.
    set(&mut s, f, "image_angle", 90.0);
    s.dispatch(&b, f, 0, 0).unwrap();
    let dir = fget(&s, f, "direction");
    assert!((65.0..=115.0).contains(&dir), "image_angle 90 base -> {dir}");
    assert_eq!(fget(&s, f, "speed"), -10.0);
}

// ---- CODE 334: obj_fireprojectile Step -------------------------------------

#[test]
fn fireprojectile_step_puffs_a_half_scaled_smoke_on_walls() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    park(&mut s, p);
    let wall = s.create(&b, WALL, 300.0, 200.0).unwrap();
    let fp = s.create(&b, FIREPROJECTILE, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, fp, "hspeed"), 0.0, "CODE 333 writes speed/direction only");
    assert_eq!(fget(&s, fp, "vspeed"), 0.0);
    assert_eq!(
        s.call(&b, fp, "instance_place", &[300.0, 200.0, PAR_WALL as f64]).unwrap(),
        wall as f64,
        "fixture: the projectile stands inside the wall it must notice"
    );

    let before = ids(&s);
    s.dispatch(&b, fp, 3, 0).unwrap();
    let puff = spawned(&before, &s, SMALLPUFF);
    assert_eq!(puff.len(), 1, "// CODE 334 leaves exactly one obj_smallpuff");
    assert_eq!(fget(&s, puff[0], "image_xscale"), 0.5, "i1.image_xscale = 0.5");
    assert_eq!(fget(&s, puff[0], "image_yscale"), 0.5, "i1.image_yscale = 0.5");
    assert_eq!(fget(&s, puff[0], "x"), 300.0);
    assert_eq!(fget(&s, puff[0], "y"), 200.0);
    assert_eq!(s.instances[&puff[0]].alarms[0], 18, "CODE 782's own fuse");
    assert!(!alive(&s, fp), "the projectile consumes itself");
}

#[test]
fn fireprojectile_step_hurts_one_vulnerable_player() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let hp0 = s.globals["health1"];
    let fp = s.create(&b, FIREPROJECTILE, 504.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, fp, "instance_place", &[504.0, 200.0, P as f64]).unwrap(),
        p as f64,
        "fixture: the (x + hspeed, y + vspeed) probe reaches the player"
    );
    let before = ids(&s);
    s.dispatch(&b, fp, 3, 0).unwrap();
    assert_eq!(s.globals["health1"], hp0 - 1.0, "global.health1 -= 1");
    assert_eq!(fget(&s, p, "flashing"), 1.0, "obj_player.flashing = 1");
    assert_eq!(fget(&s, p, "invulnerable"), 1.0, "x > obj_player.x -> the left knock flag");
    assert_eq!(fget(&s, p, "sliding1"), 1.0);
    assert_eq!(fget(&s, p, "invulnerable2"), 0.0, "the mirror flag stays down");
    assert_eq!(fget(&s, p, "sliding2"), 0.0);
    assert_eq!(s.instances[&p].alarms[7], 22, "obj_player.alarm[7] = 22");
    assert_eq!(s.instances[&p].alarms[4], 10, "obj_player.alarm[4] = 10");
    assert_eq!(s.instances[&p].alarms[8], 25, "obj_player.alarm[8] = 25");
    assert_eq!(audio(&s), vec![SND_IMPACTSOUND2], "snd_impactsound2 = 23");
    assert_eq!(s.particles.len(), 4, "part_particles_create(..., 4)");
    assert!(!alive(&s, fp), "the hit consumes the projectile");
    assert!(spawned(&before, &s, DODGED).is_empty(), "rebuff is off in this branch");

    // The mirrored half: a projectile left of the player sets the right flag.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let fp = s.create(&b, FIREPROJECTILE, 496.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, fp, "instance_place", &[496.0, 200.0, P as f64]).unwrap(),
        p as f64,
        "fixture: the mirrored probe reaches the player"
    );
    s.dispatch(&b, fp, 3, 0).unwrap();
    assert_eq!(fget(&s, p, "invulnerable2"), 1.0, "x < obj_player.x -> the right knock flag");
    assert_eq!(fget(&s, p, "sliding2"), 1.0);
    assert_eq!(fget(&s, p, "invulnerable"), 0.0);
}

#[test]
fn fireprojectile_step_is_blocked_by_the_sword_and_leaves_a_parry() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let fp = s.create(&b, FIREPROJECTILE, 300.0, 200.0).unwrap();
    let sword = s.create(&b, SWORD, 300.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, fp, "instance_place", &[300.0, 200.0, SWORD as f64]).unwrap(),
        sword as f64,
        "fixture: the sword stands where the projectile will probe"
    );
    let before = ids(&s);
    s.dispatch(&b, fp, 3, 0).unwrap();
    assert_eq!(spawned(&before, &s, PARRY).len(), 1, "// CODE 334 leaves an obj_parry");
    assert!(spawned(&before, &s, SMALLPUFF).is_empty(), "no puff without a wall");
    assert!(!alive(&s, fp), "the parry consumes the projectile");
}

#[test]
fn fireprojectile_step_leaves_a_dodged_floater_while_rebuffing() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    s.globals.insert("rebuff".into(), 1.0);
    let fp = s.create(&b, FIREPROJECTILE, 500.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, fp, "distance_to_object", &[P as f64]).unwrap(),
        0.0,
        "fixture: the projectile stands on the player, within the <= 2 gate"
    );
    let hp0 = s.globals["health1"];
    let before = ids(&s);
    s.dispatch(&b, fp, 3, 0).unwrap();
    let d = spawned(&before, &s, DODGED);
    assert_eq!(d.len(), 1, "// CODE 334 spawns obj_dodged when global.rebuff == 1");
    assert_eq!(fget(&s, d[0], "x"), 500.0, "obj_player.x");
    assert_eq!(fget(&s, d[0], "y"), 190.0, "obj_player.y - 10");
    assert_eq!(s.globals["health1"], hp0, "the rebuff branch never touches health1");
    assert_eq!(fget(&s, p, "flashing"), 0.0, "no hit flash while dodging");
    assert!(alive(&s, fp), "the dodged branch leaves the projectile flying");
    // The gate is `!instance_exists(obj_dodged)`: a second pass adds nothing.
    s.dispatch(&b, fp, 3, 0).unwrap();
    assert_eq!(spawned(&before, &s, DODGED).len(), 1, "one floater per dodge window");
}

// ---- CODE 336: obj_boss3projectile Step ------------------------------------

#[test]
fn boss3projectile_step_walls_out_and_mirrors_its_direction() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let wall = s.create(&b, WALL, 300.0, 200.0).unwrap();
    let bp = s.create(&b, BOSS3PROJECTILE, 300.0, 200.0).unwrap();
    let dir = fget(&s, bp, "direction");
    assert!(
        [-30.0, -15.0, 0.0, 15.0, 30.0, 45.0, 60.0].contains(&dir),
        "CODE 335 launches at choose(-30..60), got {dir}"
    );
    assert_eq!(fget(&s, bp, "speed"), -5.0, "CODE 335 speed = -5");
    assert_eq!(
        s.call(&b, bp, "instance_place", &[300.0, 200.0, PAR_WALL as f64]).unwrap(),
        wall as f64,
        "fixture: the projectile stands inside the wall"
    );
    let before = ids(&s);
    s.dispatch(&b, bp, 3, 0).unwrap();
    assert_eq!(fget(&s, bp, "image_angle"), dir, "// CODE 336 image_angle = direction");
    assert!(!alive(&s, bp), "a wall destroys it outright");
    assert!(
        spawned(&before, &s, SMALLPUFF).is_empty(),
        "no puff: that branch belongs to obj_fireprojectile"
    );
    let _ = (p, wall);
}

#[test]
fn boss3projectile_step_hurts_the_player_and_parries_the_sword() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let hp0 = s.globals["health1"];
    let bp = s.create(&b, BOSS3PROJECTILE, 496.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, bp, "instance_place", &[496.0, 200.0, P as f64]).unwrap(),
        p as f64,
        "fixture: the (x + hspeed, y + vspeed) probe reaches the player"
    );
    s.dispatch(&b, bp, 3, 0).unwrap();
    assert_eq!(s.globals["health1"], hp0 - 1.0, "global.health1 -= 1");
    assert_eq!(fget(&s, p, "invulnerable2"), 1.0, "x < obj_player.x -> the right knock flag");
    assert_eq!(fget(&s, p, "sliding2"), 1.0);
    assert_eq!(fget(&s, p, "flashing"), 1.0);
    assert_eq!(s.instances[&p].alarms[7], 22);
    assert_eq!(s.instances[&p].alarms[4], 10);
    assert_eq!(s.instances[&p].alarms[8], 25);
    assert_eq!(audio(&s), vec![SND_IMPACTSOUND2]);
    assert!(!alive(&s, bp));

    // The sword branch: a boss projectile is parried like any other.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let bp = s.create(&b, BOSS3PROJECTILE, 300.0, 200.0).unwrap();
    let sword = s.create(&b, SWORD, 300.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, bp, "instance_place", &[300.0, 200.0, SWORD as f64]).unwrap(),
        sword as f64,
        "fixture: the sword stands where the projectile will probe"
    );
    let before = ids(&s);
    s.dispatch(&b, bp, 3, 0).unwrap();
    assert_eq!(spawned(&before, &s, PARRY).len(), 1, "// CODE 336 leaves an obj_parry");
    assert!(!alive(&s, bp), "the parry consumes the projectile");
}

// ---- CODE 283 / 39 / 280 / 297 / 310 / 290: bare destroy slots ---------------

#[test]
fn bullet_alarm_one_destroys_the_bullet() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let bul = s.create(&b, BULLET, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, bul, "hspeed"), 25.0, "CODE 282 facing 0 -> hspeed 25");
    s.dispatch(&b, bul, 2, 1).unwrap();
    assert!(!alive(&s, bul), "// CODE 283 is a bare instance_destroy");

    // …and the same body is what the fuse fires: CODE 282 arms no alarm[1], so
    // an armed one belongs to this body alone. Open space, no wall, no victim.
    let bul2 = s.create(&b, BULLET, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&bul2].alarms[1], -1, "CODE 282 leaves alarm[1] unarmed");
    s.instances.get_mut(&bul2).unwrap().alarms[1] = 3;
    for _ in 0..2 {
        s.tick(&b).unwrap();
        assert!(alive(&s, bul2), "alarm[1] counts down, nothing else kills the bullet");
    }
    s.tick(&b).unwrap();
    assert!(!alive(&s, bul2), "alarm[1] == 3 fires // CODE 283 on the third tick");
}

#[test]
fn bulletspark_alarm_zero_destroys_the_spark() {
    let b = bundle();
    let mut s = scene(&b);
    let sp = s.create(&b, BULLETSPARK, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, sp, "sprite_index"), 3.0, "obj_bulletspark carries spr 3");
    assert_eq!(s.instances[&sp].alarms[0], 7, "CODE 38 arms alarm[0] = 7");
    s.dispatch(&b, sp, 2, 0).unwrap();
    assert!(!alive(&s, sp), "// CODE 39 is a bare instance_destroy");

    let sp2 = s.create(&b, BULLETSPARK, 300.0, 200.0).unwrap();
    for _ in 0..6 {
        s.tick(&b).unwrap();
        assert!(alive(&s, sp2), "the spark has no Step to kill it early");
    }
    s.tick(&b).unwrap();
    assert!(!alive(&s, sp2), "the 7-tick fuse fires // CODE 39");
}

#[test]
fn arrow_alarm_zero_destroys_the_arrow() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let arrow = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, arrow, "hspeed"), 15.0, "CODE 279 facing 0 -> hspeed 15");
    assert_eq!(fget(&s, arrow, "vspeed"), -1.0, "CODE 279 vspeed -1");
    s.dispatch(&b, arrow, 2, 0).unwrap();
    assert!(!alive(&s, arrow), "// CODE 280 is a bare instance_destroy");

    // CODE 281 only arms alarm[0] on a hit, so in open air the fuse here is
    // the body under test and nothing else.
    let arrow2 = s.create(&b, ARROW, 300.0, 200.0).unwrap();
    s.instances.get_mut(&arrow2).unwrap().alarms[0] = 2;
    s.tick(&b).unwrap();
    assert!(alive(&s, arrow2), "one tick short");
    s.tick(&b).unwrap();
    assert!(!alive(&s, arrow2), "alarm[0] == 2 fires // CODE 280 on the second tick");
}

#[test]
fn boomerangthrow_alarm_zero_destroys_the_throw() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let th = s.create(&b, BOOMERANGTHROW, 300.0, 200.0).unwrap();
    assert_eq!(s.instances[&th].alarms[1], 30, "CODE 295 arms the return fuse on alarm[1]");
    assert_eq!(s.instances[&th].alarms[0], -1, "CODE 295 leaves alarm[0] unarmed");
    s.dispatch(&b, th, 2, 0).unwrap();
    assert!(!alive(&s, th), "// CODE 297 is a bare instance_destroy");
}

#[test]
fn sword_alarm_zero_kills_the_sword() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let sword = s.create(&b, SWORD, 505.0, 206.0).unwrap();
    assert_eq!(s.instances[&sword].alarms[0], 7, "CODE 309 arms alarm[0] = 7");
    s.dispatch(&b, sword, 2, 0).unwrap();
    assert!(!alive(&s, sword), "// CODE 310 is action_kill_object()");

    // Through the scheduler: CODE 311 re-arms only when alarm[0] <= 0, so the
    // 7-tick fuse set by Create is the one that ends the blade.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let sword = s.create(&b, SWORD, 505.0, 206.0).unwrap();
    for t in 1..=6 {
        s.tick(&b).unwrap();
        assert!(alive(&s, sword), "blade alive at tick {t}");
    }
    s.tick(&b).unwrap();
    assert!(!alive(&s, sword), "the 7-tick fuse fires // CODE 310");
}

#[test]
fn laserbeam_outside_room_destroys_the_beam() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let lb = s.create(&b, LASERBEAM, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, lb, "hspeed"), 20.0, "CODE 287 facing 0 -> hspeed 20");
    assert_eq!(s.instances[&lb].alarms[1], 120, "CODE 287 arms its own 120-tick fuse");
    // CODE 290 sits in the Other_0 (Outside Room) slot. This host has no
    // outside-room trigger, so the body is driven through its own event slot;
    // what it does is unconditional.
    s.dispatch(&b, lb, 7, 0).unwrap();
    assert!(!alive(&s, lb), "// CODE 290 is a bare instance_destroy");
}

// ---- CODE 383: obj_boomerang (the weapon pickup) ---------------------------

#[test]
fn boomerang_pickup_grants_the_weapon_and_clears_the_weapon_row() {
    let b = bundle();
    let mut s = scene(&b);
    // Every other weapon is held, so the row-clearing writes are observable.
    for w in ["icegun", "pistol", "shotgun", "assaultrifle", "rocket", "bladegun",
              "flamethrower", "bow", "bombgun", "laser", "spikegun"] {
        s.globals.insert(w.into(), 1.0);
    }
    s.globals.insert("boomerangbought".into(), 0.0);
    s.globals.insert("boomerang".into(), 0.0);
    let p = player(&mut s, &b, 400.0, 300.0, 0.0);
    let boom = s.create(&b, BOOMERANG, 400.0, 300.0).unwrap();
    assert_eq!(
        s.call(&b, boom, "distance_to_object", &[P as f64]).unwrap(),
        0.0,
        "fixture: the pickup stands on the player, within the <= 1 gate"
    );
    let before = ids(&s);
    s.dispatch(&b, boom, 3, 0).unwrap();
    assert!(!alive(&s, boom), "// CODE 383 consumes the pickup");
    assert_eq!(s.globals["boomerangbought"], 1.0, "global.boomerangbought = 1");
    assert_eq!(s.globals["boomerang"], 1.0, "global.boomerang = 1");
    for w in ["icegun", "pistol", "shotgun", "assaultrifle", "rocket", "bladegun",
              "flamethrower", "bow", "bombgun", "laser", "spikegun"] {
        assert_eq!(s.globals[w], 0.0, "the pickup clears global.{w}");
    }
    assert_eq!(spawned(&before, &s, FOUNDWEAPON).len(), 1, "one obj_foundweapon banner");
    // CODE 404 (that banner's own Create) parks the world behind itself.
    assert!(!s.instances[&p].active, "the banner deactivates everything else");

    // Guard: a second pickup never spawns a second banner.
    let mut s = scene(&b);
    s.globals.insert("boomerangbought".into(), 1.0);
    let _p = player(&mut s, &b, 400.0, 300.0, 0.0);
    let boom = s.create(&b, BOOMERANG, 400.0, 300.0).unwrap();
    assert!(!alive(&s, boom), "CODE 382 destroys an already-bought pickup");
}

// ---- CODE 298: obj_boomerangthrow Step -------------------------------------

#[test]
fn boomerangthrow_step_stuns_the_first_victim_and_returns_to_the_hand() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0, 0.0);
    s.globals.insert("boomerangxp".into(), 0.0);
    let th = s.create(&b, BOOMERANGTHROW, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, th, "hspeed"), 5.0, "CODE 295 facing 0 -> hspeed 5");
    assert_eq!(fget(&s, th, "boomerangreturn"), 0.0);
    let knife = s.create(&b, KNIFE, 300.0, 200.0).unwrap();
    let wolf = s.create(&b, WOLF, 300.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, th, "instance_place", &[300.0, 200.0, KNIFE as f64]).unwrap(),
        knife as f64,
        "fixture: the blade overlaps the knifebandit"
    );
    let dmg = s.globals["boomerangdamage"];
    let hp0 = fget(&s, knife, "hpknife");
    let w0 = fget(&s, wolf, "hpwolf");
    let before = ids(&s);
    s.dispatch(&b, th, 3, 0).unwrap();
    assert_eq!(fget(&s, th, "image_angle"), -40.0, "// CODE 298 image_angle -= 40");
    assert_eq!(hp0 - fget(&s, knife, "hpknife"), dmg, "global.boomerangdamage = {dmg}");
    assert_eq!(fget(&s, knife, "flashing"), 1.0);
    assert_eq!(fget(&s, knife, "stunned"), 1.0);
    assert_eq!(s.instances[&knife].alarms[4], 10, "the stun clears on alarm[4] = 10");
    assert_eq!(
        s.globals["boomerangxp"], 2.0,
        "global.boomerangxp += 1 per victim (this body has no canhit latch)"
    );
    assert_eq!(
        w0 - fget(&s, wolf, "hpwolf"),
        dmg,
        "the boomerang hits every species it touches (no canhit latch here)"
    );
    assert_eq!(fget(&s, wolf, "stunned"), 1.0);
    assert_eq!(s.instances[&wolf].alarms[4], 10);
    let hits = spawned(&before, &s, DAMAGE);
    assert_eq!(hits.len(), 2, "knife + wolf both take a number (no canhit latch here)");
    for h in hits {
        assert_eq!(fget(&s, h, "damage"), dmg);
    }
    assert_eq!(audio(&s), vec![SND_IMPACTSOUND2], "snd_impactsound2 plays once");

    // The `!audio_is_playing(snd_impactsound2)` guard: while that voice is
    // still alive the same body stays silent.
    let _knife2 = s.create(&b, KNIFE, 300.0, 200.0).unwrap();
    assert!(
        s.call(&b, th, "instance_place", &[300.0, 200.0, KNIFE as f64]).unwrap() >= 0.0,
        "fixture: knifebandits still stand where the blade strikes"
    );
    s.dispatch(&b, th, 3, 0).unwrap();
    assert_eq!(audio(&s).len(), 1, "the impact sound is not stacked while it plays");
    assert_eq!(fget(&s, th, "image_angle"), -80.0, "the spin keeps accumulating");

    // boomerangreturn == 1: the throw tracks the player and dies on contact.
    set(&mut s, th, "boomerangreturn", 1.0);
    set(&mut s, th, "x", 400.0);
    set(&mut s, th, "y", 200.0);
    s.dispatch(&b, th, 3, 0).unwrap();
    assert_eq!(fget(&s, th, "direction"), 0.0, "move_towards_point to a player on its right");
    assert_eq!(fget(&s, th, "speed"), 5.0);
    assert_eq!(fget(&s, th, "hspeed"), 5.0);
    assert_eq!(fget(&s, th, "vspeed"), 0.0);
    assert!(alive(&s, th), "still flying, not yet at the player");
    set(&mut s, th, "x", 500.0);
    s.dispatch(&b, th, 3, 0).unwrap();
    assert!(!alive(&s, th), "reaching the player ends the throw");
    assert_eq!(fget(&s, th, "boomerangreturn"), 0.0, "boomerangreturn = 0 after the catch");
    let _ = p;
}

// ---- CODE 311: obj_sword Step ----------------------------------------------

#[test]
fn sword_step_swings_by_level_and_latches_one_victim_per_step() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    s.globals.insert("sword".into(), 0.0);
    let sword = s.create(&b, SWORD, 505.0, 206.0).unwrap();
    assert_eq!(fget(&s, sword, "sprite_index"), SPR_SWORD1, "obj_sword's own default sprite");
    assert_eq!(s.instances[&sword].alarms[0], 7, "CODE 309 arms alarm[0] = 7");
    let knife = s.create(&b, KNIFE, 505.0, 206.0).unwrap();
    let wolf = s.create(&b, WOLF, 505.0, 206.0).unwrap();
    assert_eq!(
        s.call(&b, sword, "instance_place", &[505.0, 206.0, KNIFE as f64]).unwrap(),
        knife as f64,
        "fixture: the blade overlaps the knifebandit"
    );
    assert_eq!(
        s.call(&b, sword, "instance_place", &[505.0, 206.0, WOLF as f64]).unwrap(),
        wolf as f64,
        "fixture: the blade overlaps the wolf too"
    );
    let hp0 = fget(&s, knife, "hpknife");
    let w0 = fget(&s, wolf, "hpwolf");
    let before = ids(&s);
    s.dispatch(&b, sword, 3, 0).unwrap();
    assert_eq!(fget(&s, sword, "sprite_index"), SPR_SWORD1, "global.sword 0 -> spr_sword1");
    assert_eq!(fget(&s, sword, "x"), 505.0, "obj_player.x + 5 while facing 0");
    assert_eq!(fget(&s, sword, "y"), 206.0, "obj_player.y + 6");
    assert_eq!(fget(&s, sword, "image_angle"), -25.0, "facing 0 swings the blade -25deg");
    assert_eq!(fget(&s, sword, "canhit"), 1.0, "the blade latches after its first hit");
    assert_eq!(hp0 - fget(&s, knife, "hpknife"), 1.0, "sword level 0 hits for 1");
    assert_eq!(fget(&s, knife, "swordstunned"), 1.0);
    assert_eq!(s.instances[&knife].alarms[5], 30, "the sword stun clears on alarm[5] = 30");
    assert_eq!(w0, fget(&s, wolf, "hpwolf"), "canhit latched: the wolf is untouched");
    let dmg = spawned(&before, &s, DAMAGE);
    assert_eq!(dmg.len(), 1, "one damage number per Step");
    assert_eq!(fget(&s, dmg[0], "damage"), 1.0);
    assert_eq!(fget(&s, dmg[0], "x"), 505.0, "spawned at the victim");
    assert_eq!(fget(&s, dmg[0], "y"), 206.0);
    assert_eq!(s.instances[&sword].alarms[0], 7, "alarm[0] > 0 is left alone");

    // global.sword = 3: spr_sword4 and 4 damage, and a 0 alarm[0] re-arms.
    s.globals.insert("sword".into(), 3.0);
    set(&mut s, sword, "canhit", 0.0);
    s.instances.get_mut(&sword).unwrap().alarms[0] = 0;
    let hp1 = fget(&s, knife, "hpknife");
    let before = ids(&s);
    s.dispatch(&b, sword, 3, 0).unwrap();
    assert_eq!(fget(&s, sword, "sprite_index"), SPR_SWORD4, "global.sword 3 -> spr_sword4");
    assert_eq!(hp1 - fget(&s, knife, "hpknife"), 4.0, "sword level 3 hits for 4");
    let dmg = spawned(&before, &s, DAMAGE);
    assert_eq!(dmg.len(), 1);
    assert_eq!(fget(&s, dmg[0], "damage"), 4.0);
    assert_eq!(s.instances[&sword].alarms[0], 7, "alarm[0] <= 0 re-arms to 7");

    // facing 1 mirrors the whole swing.
    set(&mut s, _p, "facing", 1.0);
    set(&mut s, sword, "canhit", 0.0);
    set(&mut s, sword, "image_angle", 0.0);
    s.dispatch(&b, sword, 3, 0).unwrap();
    assert_eq!(fget(&s, sword, "x"), 495.0, "obj_player.x - 5 while facing 1");
    assert_eq!(fget(&s, sword, "y"), 206.0);
    assert_eq!(fget(&s, sword, "image_angle"), 25.0, "facing 1 swings +25deg");

    // obj_hulkingbandit is the one victim this body clears on alarm[4].
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let hulk = s.create(&b, HULKING, 505.0, 206.0).unwrap();
    let sword = s.create(&b, SWORD, 505.0, 206.0).unwrap();
    assert_eq!(
        s.call(&b, sword, "instance_place", &[505.0, 206.0, HULKING as f64]).unwrap(),
        hulk as f64,
        "fixture: the blade overlaps the hulking bandit"
    );
    let h0 = fget(&s, hulk, "hphulkingbandit");
    s.dispatch(&b, sword, 3, 0).unwrap();
    assert_eq!(h0 - fget(&s, hulk, "hphulkingbandit"), 1.0, "sword level 0 hits for 1");
    assert_eq!(fget(&s, hulk, "swordstunned"), 1.0);
    assert_eq!(s.instances[&hulk].alarms[4], 30, "the hulk clears its stun on alarm[4] = 30");
    assert_eq!(s.instances[&hulk].alarms[5], -1, "and never touches alarm[5]");
}

// ---- CODE 355 / 534 / 535: level-up badge and coin flyer -------------------

#[test]
fn levelup_step_tracks_the_player_and_drifts_right() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 400.0, 300.0, 0.0);
    let lvl = s.create(&b, LEVELUP, 100.0, 200.0).unwrap();
    let ui = s.instances.iter()
        .find(|(_, i)| i.object == UI && i.alive)
        .map(|(id, _)| *id)
        .expect("the fixture keeps one live obj_UI");
    let xpos0 = fget(&s, lvl, "xposition");
    assert_eq!(xpos0, fget(&s, ui, "x") + 50.0, "CODE 352 seeds xposition from obj_UI.x");
    s.dispatch(&b, lvl, 3, 0).unwrap();
    assert_eq!(fget(&s, lvl, "x"), 352.0, "// CODE 355 x = obj_player.x - 48");
    assert_eq!(fget(&s, lvl, "y"), 220.0, "// CODE 355 y = obj_player.y - 80");
    assert_eq!(fget(&s, lvl, "xposition"), xpos0 + 2.0, "// CODE 355 xposition += 2");
    s.dispatch(&b, lvl, 3, 0).unwrap();
    assert_eq!(fget(&s, lvl, "xposition"), xpos0 + 4.0, "the drift accumulates per Step");
}

#[test]
fn coinadd_create_hangs_the_two_flyer_rows_off_the_player() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 400.0, 300.0, 0.0);
    let ca = s.create(&b, COINADD, 0.0, 0.0).unwrap();
    assert_eq!(fget(&s, ca, "drawy"), 250.0, "// CODE 534 drawy = obj_player.y - 50");
    assert_eq!(fget(&s, ca, "drawy2"), 260.0, "// CODE 534 drawy2 = obj_player.y - 40");
    assert_eq!(s.instances[&ca].alarms[0], 45, "// CODE 534 alarm[0] = 45");
}

#[test]
fn coinadd_alarm_zero_destroys_the_flyer_on_its_fortyfive_tick_fuse() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 400.0, 300.0, 0.0);
    let ca = s.create(&b, COINADD, 0.0, 0.0).unwrap();
    s.dispatch(&b, ca, 2, 0).unwrap();
    assert!(!alive(&s, ca), "// CODE 535 is a bare instance_destroy");

    let ca2 = s.create(&b, COINADD, 0.0, 0.0).unwrap();
    for t in 0..44 {
        // The flyer has no Step of its own; the player is re-pinned so its own
        // Step cannot drift the fixture.
        set(&mut s, p, "x", 400.0);
        set(&mut s, p, "y", 300.0);
        set(&mut s, p, "vspeed", 0.0);
        s.tick(&b).unwrap();
        assert!(alive(&s, ca2), "flyer alive {} ticks in", t + 1);
    }
    assert_eq!(s.instances[&ca2].alarms[0], 1, "read back: 45 - 44 ticks");
    set(&mut s, p, "vspeed", 0.0);
    s.tick(&b).unwrap();
    assert!(!alive(&s, ca2), "the 45-tick fuse fires // CODE 535");
}

// ============================================================================
// Batch 2 (wl39-items) — the weapon pickups, the store pedestals (Draw bodies
// and their purchase clicks), the IAP/restore dialogs and the two volume
// slots. Same discipline as batch 1: every body is named as `// CODE NNN` and
// driven through its own event slot; table-driven rows carry a literal
// `// CODE NNN` comment above them so the census regex sees each body.
//
// Fixture: the store never needs a room (the pedestals only draw), so
// `shop_scene` wires the app's SPRT geometry plus three view origins — view 0
// (64,32), view 1 (100,200), view 3 (300,400) — so every `view_current` /
// `view_xview[]` branch is distinguishable from the identity transform.
// `shop_bundle` attaches the asset string table because the whole pedestal
// contract is `draw_text` text.
// ============================================================================

const BLADEGUN: i32 = 76;
const FLAMETHROWER: i32 = 77;
const BOW: i32 = 78;
const BOMBGUN: i32 = 79;
const PICKUPFLARE: i32 = 70;
const POWERUPGRADE2: i32 = 85;
const POWERUPGRADE3: i32 = 86;
const TRIPLEJUMP: i32 = 87;
const SWORDUPGRADE: i32 = 88;
const SWORDUPGRADE2: i32 = 89;
const SWORDUPGRADE3: i32 = 90;
const ENERGYWAVEUPGRADE: i32 = 91;
const HEALTHREGEN: i32 = 92;
const STRENGTHUPGRADE: i32 = 93;
const STRENGTHUPGRADE2: i32 = 94;
const COINMULTIPLIER5: i32 = 95;
const COINMULTIPLIER2: i32 = 96;
const MAXHPUPGRADE: i32 = 97;
const MAXHPUPGRADE2: i32 = 98;
const HEALTHREFILL: i32 = 99;
const VOLUME: i32 = 107;
const BACKTOGAME: i32 = 108;
const VOLUMEMUSIC: i32 = 109;
const YESRESTOREDATA: i32 = 112;
const NORESTOREDATA: i32 = 113;
const AREYOUSURE: i32 = 114;
const RESTOREDATA: i32 = 115;
const STOREPAGESWITCH: i32 = 116;
const STOREPAGESWITCH2: i32 = 117;
const FIRSTPAUSE: i32 = 118;
const IAPMENU: i32 = 119;
const POISONIAP: i32 = 120;
const RESTOREIAP: i32 = 121;

/// Sprite ids read out of the IR constant stream of the Draw body that
/// handles them (`spr_weaponbox` 154 / `spr_sold` 148 are the shared pair).
const SPR_PLAYER: i32 = 29;
const SPR_PLAYERSLASH: i32 = 31;
const SPR_SWORD2: i32 = 46;
const SPR_SWORD3: i32 = 47;
/// Same sprite as batch 1's SPR_SWORD4, typed for the draw table below.
const SPR_SWORD4_ID: i32 = 48;
const SPR_HEALTH: i32 = 86;
const SPR_SILVERCOIN: i32 = 87;
const SPR_COIN: i32 = 88;
const SPR_SOLD: i32 = 148;
const SPR_BLADEWAVE: i32 = 150;
const SPR_PAUSEBOX: i32 = 153;
const SPR_WEAPONBOX: i32 = 154;

/// Batch 1 already defines SND_COIN = 19 for the same sond; only the new one
/// is declared here.
const SND_IMPACTSOUND1: i32 = 22;

/// View origins the shop fixture pins.
const V0: (f64, f64) = (64.0, 32.0);
const V1: (f64, f64) = (100.0, 200.0);
const V3: (f64, f64) = (300.0, 400.0);
/// Where every pedestal under test stands.
const SHOP_AT: (f64, f64) = (100.0, 100.0);

fn shop_bundle() -> Bundle {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid"))
        .expect("parse game.droid");
    let mut b = load_bundle_from_file(&root.join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
    b.string_table = asset.string_table.clone();
    b
}

fn shop_scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    wire_sprite_geometry(&mut s);
    s.view_positions.insert(0, V0);
    s.view_positions.insert(1, V1);
    s.view_positions.insert(3, V3);
    s
}

fn draws_from(s: &Scene, code: usize) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == code).cloned().collect()
}

fn texts_from(s: &Scene, code: usize) -> Vec<TextCommand> {
    s.texts.iter().filter(|t| t.code == code).cloned().collect()
}

// ---- CODE 392 / 394 / 396 / 398: weapon pickup Creates ----------------------

#[test]
fn weapon_pickup_create_pins_the_idle_frame_and_its_flare_beacon() {
    let b = shop_bundle();
    // (CODE, object, bought flag, beacon offset x, beacon offset y)
    let table: [(usize, i32, &str, f64, f64); 4] = [
        // CODE 392
        (392, BLADEGUN, "bladegunbought", -12.0, -16.0),
        // CODE 394
        (394, FLAMETHROWER, "flamethrowerbought", -4.0, -12.0),
        // CODE 396
        (396, BOW, "bowbought", -8.0, -16.0),
        // CODE 398
        (398, BOMBGUN, "bombgunbought", 12.0, -16.0),
    ];
    for (code, obj, flag, dx, dy) in table {
        let mut s = shop_scene(&b);
        s.globals.insert(flag.into(), 0.0);
        let before = ids(&s);
        let gun = s.create(&b, obj, 300.0, 200.0).unwrap();
        assert_eq!(fget(&s, gun, "image_speed"), 0.0, "// CODE {code}: image_speed = 0");
        let flares = spawned(&before, &s, PICKUPFLARE);
        assert_eq!(flares.len(), 1, "// CODE {code} leaves one obj_pickupflare beacon");
        assert_eq!(
            (fget(&s, flares[0], "x"), fget(&s, flares[0], "y")),
            (300.0 + dx, 200.0 + dy),
            "// CODE {code}: beacon offset ({dx}, {dy})"
        );
        assert_eq!(s.instances[&flares[0]].alarms[0], 30, "CODE 380 arms the beacon's 30-tick fuse");

        // An already-bought weapon consumes its own pickup.
        let mut s = shop_scene(&b);
        s.globals.insert(flag.into(), 1.0);
        let before = ids(&s);
        let gun = s.create(&b, obj, 300.0, 200.0).unwrap();
        assert!(!alive(&s, gun), "// CODE {code} destroys an already-bought pickup");
        assert!(
            spawned(&before, &s, PICKUPFLARE).is_empty(),
            "// CODE {code}: no beacon for a bought weapon"
        );
    }
}

// ---- CODE 393 / 395 / 397 / 399: weapon pickup Steps ------------------------

#[test]
fn weapon_pickup_step_equips_one_weapon_and_clears_the_rest_of_the_row() {
    let b = shop_bundle();
    let row = [
        "icegun", "pistol", "shotgun", "assaultrifle", "rocket", "laser",
        "spikegun", "boomerang", "bladegun", "flamethrower", "bow", "bombgun",
    ];
    // (CODE, object, bought flag, the weapon this pickup hands over)
    let table: [(usize, i32, &str, &str); 4] = [
        // CODE 393
        (393, BLADEGUN, "bladegunbought", "bladegun"),
        // CODE 395
        (395, FLAMETHROWER, "flamethrowerbought", "flamethrower"),
        // CODE 397
        (397, BOW, "bowbought", "bow"),
        // CODE 399
        (399, BOMBGUN, "bombgunbought", "bombgun"),
    ];
    for (code, obj, flag, weapon) in table {
        let mut s = shop_scene(&b);
        let p = player(&mut s, &b, 400.0, 300.0, 0.0);
        for w in row {
            s.globals.insert(w.into(), 1.0);
        }
        s.globals.insert(flag.into(), 0.0);
        let gun = s.create(&b, obj, 400.0, 300.0).unwrap();
        assert_eq!(
            s.call(&b, gun, "distance_to_object", &[P as f64]).unwrap(),
            0.0,
            "fixture: the pickup stands on the player, inside the <= 1 gate"
        );
        let before = ids(&s);
        s.dispatch(&b, gun, 3, 0).unwrap();
        assert!(!alive(&s, gun), "// CODE {code} consumes the pickup");
        assert_eq!(s.globals[flag], 1.0, "// CODE {code} sets {flag}");
        assert_eq!(s.globals[weapon], 1.0, "// CODE {code} equips {weapon}");
        for w in row {
            if w != weapon {
                assert_eq!(s.globals[w], 0.0, "// CODE {code} clears global.{w}");
            }
        }
        assert_eq!(
            spawned(&before, &s, FOUNDWEAPON).len(),
            1,
            "// CODE {code} raises one obj_foundweapon banner"
        );
        assert!(
            !s.instances[&p].active,
            "CODE 404 (the banner's own Create) parks the world behind itself"
        );
    }
}

// ---- CODE 427 / 429 / 435 / 437 / 439 / 441 / 443: purchase clicks ----------

#[test]
fn store_purchase_click_gates_on_score_and_applies_its_effects() {
    let b = shop_bundle();
    // (CODE, object, price, bought flag, globals this click writes)
    let table: [(usize, i32, f64, &str, &[(&str, f64)]); 7] = [
        // CODE 427
        (427, SWORDUPGRADE3, 15000.0, "swordupgrade3bought",
         &[("swordupgrade3bought", 1.0), ("swordupgrade2bought", 1.0),
           ("swordupgradebought", 1.0), ("sword", 3.0)]),
        // CODE 429
        (429, ENERGYWAVEUPGRADE, 50000.0, "energywavebought",
         &[("energywavebought", 1.0)]),
        // CODE 435
        (435, STRENGTHUPGRADE2, 20000.0, "strengthupgrade2bought",
         &[("strengthupgrade2bought", 1.0)]),
        // CODE 437
        (437, COINMULTIPLIER5, 20000.0, "coinmultiplier5bought",
         &[("coinmultiply", 5.0), ("coinmultiplier5bought", 1.0)]),
        // CODE 439
        (439, COINMULTIPLIER2, 2000.0, "coinmultiplier2bought",
         &[("coinmultiply", 2.0), ("coinmultiplier2bought", 1.0)]),
        // CODE 441
        (441, MAXHPUPGRADE, 10000.0, "maxhpupgradebought",
         &[("maxhpupgradebought", 1.0)]),
        // CODE 443
        (443, MAXHPUPGRADE2, 25000.0, "maxhpupgrade2bought",
         &[("maxhpupgrade2bought", 1.0)]),
    ];
    for (code, obj, price, flag, effects) in table {
        // One coin short of the price: the body must do nothing at all.
        let mut s = shop_scene(&b);
        s.score = price - 1.0;
        let it = s.create(&b, obj, 0.0, 0.0).unwrap();
        s.dispatch(&b, it, 6, 0).unwrap();
        assert_eq!(s.score, price - 1.0, "// CODE {code}: below price nothing is deducted");
        assert_eq!(s.globals[flag], 0.0, "// CODE {code}: below price the flag stays down");
        assert!(audio(&s).is_empty(), "// CODE {code}: no chime below price");

        // At the price the click deducts and applies its whole effect set.
        let mut s = shop_scene(&b);
        s.globals.insert("maxhp".into(), 6.0);
        s.globals.insert("health1".into(), 2.0);
        s.score = price;
        let it = s.create(&b, obj, 0.0, 0.0).unwrap();
        s.dispatch(&b, it, 6, 0).unwrap();
        assert_eq!(s.score, 0.0, "// CODE {code} deducts exactly the price");
        for (g, v) in effects {
            assert_eq!(s.globals[*g], *v, "// CODE {code} writes global.{g}");
        }
        assert_eq!(audio(&s), vec![SND_COIN], "// CODE {code} plays snd_coin");
        if code == 441 || code == 443 {
            assert_eq!(s.globals["level"], 2.0, "// CODE {code} raises global.level by 1");
            assert_eq!(
                s.globals["health1"], s.globals["maxhp"],
                "// CODE {code} refills health1 to global.maxhp"
            );
        }

        // The bought flag gates a repeat click.
        s.score = 999.0;
        s.dispatch(&b, it, 6, 0).unwrap();
        assert_eq!(s.score, 999.0, "// CODE {code}: the bought flag gates the repeat");
    }
}

// ---- CODE 424 / 426 / 428 / 430 / 434 / 436 / 438 / 440 / 442 / 444 / 432 /
// ---- CODE 417 / 419: the pedestal Draw bodies ------------------------------

#[test]
fn upgrade_pedestal_draw_names_price_icon_and_the_sold_badge() {
    let b = shop_bundle();
    // (CODE, object, name, price, icon sprite, icon frame, icon dx, icon dy,
    //  icon scale, bought flag, view-1 anchor dx, view-1 anchor dy)
    let table: [(usize, i32, &str, &str, i32, f64, f64, f64, f64, &str, f64, f64); 13] = [
        // CODE 424
        (424, SWORDUPGRADE, "Sword Upgrade:", "$3,000", SPR_SWORD2, 1.0,
         135.0, 28.0, 0.7, "swordupgradebought", 210.0, 50.0),
        // CODE 426
        (426, SWORDUPGRADE2, "Sword Upgrade 2:", "$10,000", SPR_SWORD3, 1.0,
         135.0, 29.0, 0.7, "swordupgrade2bought", 210.0, 130.0),
        // CODE 428
        (428, SWORDUPGRADE3, "Sword Upgrade 3:", "$15,000", SPR_SWORD4_ID, 1.0,
         135.0, 29.0, 0.7, "swordupgrade3bought", 210.0, 90.0),
        // CODE 430
        (430, ENERGYWAVEUPGRADE, "Equip Energy Wave:", "$50,000", SPR_BLADEWAVE, 1.0,
         132.0, 16.0, 0.7, "energywavebought", 210.0, 130.0),
        // CODE 432
        (432, HEALTHREGEN, "Health Regeneration:", "$75,000", SPR_HEALTH, 1.0,
         135.0, 15.0, 1.0, "healthregenbought", 210.0, 170.0),
        // CODE 434
        (434, STRENGTHUPGRADE, "Chance to Dodge:", "$3,000", SPR_PLAYERSLASH, 2.0,
         135.0, 15.0, 0.7, "strengthupgradebought", 210.0, 90.0),
        // CODE 436
        (436, STRENGTHUPGRADE2, "Chance to Dodge 2:", "$20,000", SPR_PLAYERSLASH, 2.0,
         135.0, 15.0, 0.7, "strengthupgrade2bought", 210.0, 170.0),
        // CODE 438
        (438, COINMULTIPLIER5, "Coin Multiplier 5:", "$20,000", SPR_SILVERCOIN, 1.0,
         135.0, 15.0, 1.0, "coinmultiplier5bought", 45.0, 130.0),
        // CODE 440
        (440, COINMULTIPLIER2, "Coin Multiplier 2:", "$2,000", SPR_COIN, 1.0,
         135.0, 15.0, 1.0, "coinmultiplier2bought", 45.0, 90.0),
        // CODE 442
        (442, MAXHPUPGRADE, "Level up:", "$10,000", SPR_HEALTH, 1.0,
         135.0, 15.0, 1.0, "maxhpupgradebought", 45.0, 50.0),
        // CODE 444
        (444, MAXHPUPGRADE2, "Level up 2:", "$25,000", SPR_HEALTH, 1.0,
         135.0, 15.0, 1.0, "maxhpupgrade2bought", 45.0, 90.0),
        // CODE 417
        (417, POWERUPGRADE2, "Reduce Enemy HP 2:", "$25,000", SPR_PLAYER, 1.0,
         135.0, 15.0, 0.7, "powerupgrade2bought", 45.0, 170.0),
        // CODE 419
        (419, POWERUPGRADE3, "Reduce Enemy HP 3:", "$35,000", SPR_PLAYER, 1.0,
         135.0, 15.0, 0.7, "powerupgrade3bought", 210.0, 50.0),
    ];
    for (code, obj, name, price, icon, frame, dx, dy, scale, flag, v1dx, v1dy) in table {
        let mut s = shop_scene(&b);
        s.globals.insert(flag.into(), 0.0);
        let item = s.create(&b, obj, SHOP_AT.0, SHOP_AT.1).unwrap();
        s.draw_view(&b, 0).expect("draw view 0");

        let draws = draws_from(&s, code);
        let pedestal = draws.iter().find(|d| d.sprite == SPR_WEAPONBOX)
            .unwrap_or_else(|| panic!("// CODE {code}: no spr_weaponbox pedestal drawn"));
        assert_eq!((pedestal.x, pedestal.y), SHOP_AT, "// CODE {code}: pedestal at the instance spot");
        assert_eq!(
            (pedestal.scale_x, pedestal.scale_y), (1.2, 1.1),
            "// CODE {code}: view 0 pedestal is 1.2 x 1.1"
        );
        let texts = texts_from(&s, code);
        assert!(
            texts.iter().any(|t| t.text == name && (t.x, t.y) == (SHOP_AT.0 + 5.0, SHOP_AT.1)),
            "// CODE {code}: name `{name}` at (x + 5, y)"
        );
        assert!(
            texts.iter().any(|t| t.text == price && (t.x, t.y) == (SHOP_AT.0 + 5.0, SHOP_AT.1 + 15.0)),
            "// CODE {code}: price `{price}` at (x + 5, y + 15)"
        );
        let icon_draw = draws.iter().find(|d| d.sprite == icon)
            .unwrap_or_else(|| panic!("// CODE {code}: icon sprite {icon} not drawn"));
        assert_eq!(
            (icon_draw.x, icon_draw.y), (SHOP_AT.0 + dx, SHOP_AT.1 + dy),
            "// CODE {code}: icon offset ({dx}, {dy})"
        );
        assert_eq!(icon_draw.frame, frame, "// CODE {code}: icon frame");
        assert_eq!(
            (icon_draw.scale_x, icon_draw.scale_y), (scale, scale),
            "// CODE {code}: icon scale"
        );
        assert!(
            draws.iter().all(|d| d.sprite != SPR_SOLD),
            "// CODE {code}: no sold badge while unbought"
        );

        // Bought: the sold badge overlays the pedestal at view 0.
        s.globals.insert(flag.into(), 1.0);
        s.draw_view(&b, 0).expect("draw view 0 bought");
        let sold = draws_from(&s, code).into_iter().find(|d| d.sprite == SPR_SOLD).unwrap_or_else(
            || panic!("// CODE {code}: no spr_sold badge after the purchase"),
        );
        assert_eq!((sold.x, sold.y), SHOP_AT, "// CODE {code}: badge sits on the pedestal");
        assert_eq!(
            (sold.scale_x, sold.scale_y), (0.6, 0.55),
            "// CODE {code}: view 0 badge is 0.6 x 0.55"
        );

        // view_current == 1 re-anchors the pedestal to view 1 and swaps fonts.
        s.draw_view(&b, 1).expect("draw view 1");
        assert_eq!(
            (fget(&s, item, "x"), fget(&s, item, "y")),
            (V1.0 + v1dx, V1.1 + v1dy),
            "// CODE {code}: view 1 anchor"
        );
        let draws_v1 = draws_from(&s, code);
        let pedestal_v1 = draws_v1.iter().find(|d| d.sprite == SPR_WEAPONBOX).expect("view 1 pedestal");
        assert_eq!(
            (pedestal_v1.scale_x, pedestal_v1.scale_y), (1.0, 1.0),
            "// CODE {code}: view 1 pedestal is 1 x 1"
        );
        let texts_v1 = texts_from(&s, code);
        assert!(
            texts_v1.iter().any(|t| t.text == name && t.font == 4),
            "// CODE {code}: view 1 name uses the IR's font5 constant (4)"
        );
        assert!(
            texts_v1.iter().any(|t| t.text == price && t.y == V1.1 + v1dy + 11.0),
            "// CODE {code}: view 1 price at y + 11"
        );
    }
}

// ---- CODE 471: obj_backtogame Draw ------------------------------------------

#[test]
fn backtogame_draws_the_resume_box_in_both_view_layouts() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let bg = s.create(&b, BACKTOGAME, 30.0, 40.0).unwrap();
    s.draw_view(&b, 0).expect("draw view 0");
    let draws = draws_from(&s, 471);
    let box_draw = draws.iter().find(|d| d.sprite == SPR_PAUSEBOX).expect("pausebox sprite");
    assert_eq!((box_draw.x, box_draw.y), (30.0, 40.0), "// CODE 471 draws the box at the instance spot");
    assert_eq!((box_draw.scale_x, box_draw.scale_y), (1.0, 1.0), "// CODE 471 view 0 is unscaled");
    let texts = texts_from(&s, 471);
    assert!(
        texts.iter().any(|t| t.text == "Resume" && (t.x, t.y) == (55.0, 40.0) && t.font == 0),
        "// CODE 471 view 0 label at (x + 25, y) in the IR's font1 constant (0)"
    );

    s.draw_view(&b, 1).expect("draw view 1");
    assert_eq!(
        (fget(&s, bg, "x"), fget(&s, bg, "y")),
        (V1.0 + 230.0, V1.1 + 210.0),
        "// CODE 471 view 1 anchor (view_xview[1] + 230, view_yview[1] + 210)"
    );
    let draws_v1 = draws_from(&s, 471);
    let box_v1 = draws_v1.iter().find(|d| d.sprite == SPR_PAUSEBOX).expect("view 1 box");
    assert_eq!((box_v1.scale_x, box_v1.scale_y), (0.8, 0.8), "// CODE 471 view 1 shrinks to 0.8");
    let texts_v1 = texts_from(&s, 471);
    assert!(
        texts_v1.iter().any(|t| t.text == "Resume" && t.font == 1),
        "// CODE 471 view 1 uses the IR's font4 constant (1)"
    );
}

// ---- CODE 420: obj_triplejump Create ---------------------------------------

#[test]
fn triplejump_create_reanchors_only_in_view_three() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    s.view = 0;
    let tj = s.create(&b, TRIPLEJUMP, 11.0, 22.0).unwrap();
    assert_eq!(
        (fget(&s, tj, "x"), fget(&s, tj, "y")), (11.0, 22.0),
        "// CODE 420 leaves the pedestal alone outside view 3"
    );
    let mut s = shop_scene(&b);
    s.view = 3;
    let tj = s.create(&b, TRIPLEJUMP, 11.0, 22.0).unwrap();
    assert_eq!(
        (fget(&s, tj, "x"), fget(&s, tj, "y")), (V3.0 + 20.0, V3.1 + 80.0),
        "// CODE 420 view 3 anchor (view_xview[3] + 20, view_yview[3] + 80)"
    );
}

// ---- CODE 445 / 446: obj_healthrefill --------------------------------------

#[test]
fn healthrefill_create_seeds_the_flag_and_its_alarm_clears_it() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let hr = s.create(&b, HEALTHREFILL, 200.0, 150.0).unwrap();
    assert_eq!(fget(&s, hr, "drawhealthfull"), 0.0, "// CODE 445 drawhealthfull = 0");
    set(&mut s, hr, "drawhealthfull", 1.0);
    s.dispatch(&b, hr, 2, 0).unwrap();
    assert_eq!(fget(&s, hr, "drawhealthfull"), 0.0, "// CODE 446 clears drawhealthfull again");
    assert_eq!(audio(&s), vec![SND_IMPACTSOUND1], "// CODE 446 plays snd_impactsound1 = 22");

    // Unlike almost every other sound site, this body carries NO soundmute
    // guard: it plays even while muted.
    let mut s = shop_scene(&b);
    s.globals.insert("soundmute".into(), 1.0);
    let hr = s.create(&b, HEALTHREFILL, 0.0, 0.0).unwrap();
    set(&mut s, hr, "drawhealthfull", 1.0);
    s.dispatch(&b, hr, 2, 0).unwrap();
    assert_eq!(fget(&s, hr, "drawhealthfull"), 0.0, "the clear is unconditional");
    assert_eq!(audio(&s), vec![SND_IMPACTSOUND1], "// CODE 446 has no mute branch");
}

// ---- CODE 485 / 488 / 491: dialog setup Creates ----------------------------

#[test]
fn dialog_setup_create_pins_global_menu() {
    let b = shop_bundle();
    // (CODE, object)
    let table: [(usize, i32); 3] = [
        // CODE 485
        (485, RESTOREDATA),
        // CODE 488
        (488, STOREPAGESWITCH),
        // CODE 491
        (491, STOREPAGESWITCH2),
    ];
    for (code, obj) in table {
        let mut s = shop_scene(&b);
        s.globals.insert("menu".into(), 1.0);
        s.create(&b, obj, 0.0, 0.0).unwrap();
        assert_eq!(s.globals["menu"], 0.0, "// CODE {code} pins global.menu = 0");
    }
}

// ---- CODE 486: obj_restoredata click ---------------------------------------

#[test]
fn restoredata_click_opens_the_confirmation_on_its_own_spot() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let rd = s.create(&b, RESTOREDATA, 70.0, 80.0).unwrap();
    let before = ids(&s);
    s.dispatch(&b, rd, 6, 7).unwrap();
    assert!(!alive(&s, rd), "// CODE 486 consumes the button");
    let dialog = spawned(&before, &s, AREYOUSURE);
    assert_eq!(dialog.len(), 1, "// CODE 486 opens one obj_areyousure");
    assert_eq!(
        (fget(&s, dialog[0], "x"), fget(&s, dialog[0], "y")), (70.0, 80.0),
        "// CODE 486 spawns the dialog at the button's own spot"
    );
    // The dialog's own Create (CODE 483) comes along with it.
    assert_eq!(spawned(&before, &s, YESRESTOREDATA).len(), 1);
    assert_eq!(spawned(&before, &s, NORESTOREDATA).len(), 1);
}

// ---- CODE 483: obj_areyousure Create ---------------------------------------

#[test]
fn areyousure_create_lays_out_the_yes_no_pair_from_view_zero() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let before = ids(&s);
    s.create(&b, AREYOUSURE, 5.0, 6.0).unwrap();
    let yes = spawned(&before, &s, YESRESTOREDATA);
    let no = spawned(&before, &s, NORESTOREDATA);
    assert_eq!((yes.len(), no.len()), (1, 1), "// CODE 483 spawns the pair");
    assert_eq!(
        (fget(&s, yes[0], "x"), fget(&s, yes[0], "y")), (V0.0 + 40.0, V0.1 + 155.0),
        "// CODE 483 yes at (view_xview[0] + 40, view_yview[0] + 155)"
    );
    assert_eq!(
        (fget(&s, no[0], "x"), fget(&s, no[0], "y")), (V0.0 + 180.0, V0.1 + 155.0),
        "// CODE 483 no at (view_xview[0] + 180, view_yview[0] + 155)"
    );
}

// ---- CODE 480: obj_norestoredata Destroy -----------------------------------

#[test]
fn norestoredata_destroy_brings_the_pause_menu_back_in_place() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let no = s.create(&b, NORESTOREDATA, 12.0, 24.0).unwrap();
    let before = ids(&s);
    s.destroy(&b, no).unwrap();
    let pause = spawned(&before, &s, FIRSTPAUSE);
    assert_eq!(pause.len(), 1, "// CODE 480 spawns one obj_firstpause");
    assert_eq!(
        (fget(&s, pause[0], "x"), fget(&s, pause[0], "y")), (12.0, 24.0),
        "// CODE 480 restores the pause where the button stood"
    );
}

// ---- CODE 504 / 505: obj_restoreiap ----------------------------------------

#[test]
fn restoreiap_create_seeds_the_flag_and_its_click_body_is_empty() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let rst = s.create(&b, RESTOREIAP, 33.0, 44.0).unwrap();
    assert_eq!(fget(&s, rst, "drawpurchase"), 0.0, "// CODE 504 drawpurchase = 0");

    // CODE 505 is a ZERO-instruction body (an empty recovered file): driving
    // its own slot must neither panic nor change any state.
    let before = ids(&s);
    let draws_before = s.draws.len();
    let texts_before = s.texts.len();
    s.dispatch(&b, rst, 6, 7).expect("the empty click body must run clean");
    assert!(alive(&s, rst), "// CODE 505 leaves the button alive");
    assert_eq!(ids(&s), before, "// CODE 505 spawns nothing");
    assert_eq!((s.draws.len(), s.texts.len()), (draws_before, texts_before), "// CODE 505 draws nothing");
    assert!(audio(&s).is_empty(), "// CODE 505 plays nothing");
    assert_eq!(fget(&s, rst, "drawpurchase"), 0.0, "// CODE 505 writes nothing");
}

// ---- CODE 501: obj_poisoniap click -----------------------------------------

#[test]
fn poisoniap_click_acquires_or_reports_loading_from_the_purchase_map() {
    let b = shop_bundle();
    // No purchase map: ds_map_find_value reads 0, so the acquire branch runs
    // and nothing is drawn.
    let mut s = shop_scene(&b);
    let poi = s.create(&b, POISONIAP, 200.0, 100.0).unwrap();
    let key = s.alloc_string(&b, "poisongem".into());
    let unset_map = s.globals.get("purchaseMap").copied().unwrap_or(0.0);
    assert_eq!(
        s.call(&b, poi, "ds_map_find_value", &[unset_map, key]).unwrap(),
        0.0,
        "fixture: global.purchaseMap is unset, so no map holds poisongem"
    );
    s.dispatch(&b, poi, 6, 7).unwrap();
    assert!(texts_from(&s, 501).is_empty(), "// CODE 501 stays silent while the gem is absent");

    // With a live map holding the gem, the else branch reports Loading...
    let mut s = shop_scene(&b);
    let poi = s.create(&b, POISONIAP, 200.0, 100.0).unwrap();
    let key = s.alloc_string(&b, "poisongem".into());
    let map = s.call(&b, poi, "ds_map_create", &[]).unwrap();
    s.call(&b, poi, "ds_map_replace", &[map, key, 1.0]).unwrap();
    s.globals.insert("purchaseMap".into(), map);
    assert_eq!(
        s.call(&b, poi, "ds_map_find_value", &[map, key]).unwrap(),
        1.0,
        "fixture: the map now answers for poisongem"
    );
    s.dispatch(&b, poi, 6, 7).unwrap();
    let texts = texts_from(&s, 501);
    assert_eq!(texts.len(), 1, "// CODE 501 reports once per click");
    assert_eq!(texts[0].text, "Loading...", "// CODE 501 draws the pending-purchase notice");
    assert_eq!((texts[0].x, texts[0].y), (202.0, 70.0), "// CODE 501 draws at (x + 2, y - 30)");
    assert_eq!(texts[0].font, 2, "// CODE 501 uses the IR's font2 constant (2)");
}

// ---- CODE 498: obj_iapmenu Create ------------------------------------------

#[test]
fn iapmenu_create_parks_the_world_and_lays_out_its_entries() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let bystander = s.create(&b, VOLUME, 1.0, 2.0).unwrap();
    let before = ids(&s);
    let menu = s.create(&b, IAPMENU, 0.0, 0.0).unwrap();
    let poi = spawned(&before, &s, POISONIAP);
    let back = spawned(&before, &s, BACKTOGAME);
    let rst = spawned(&before, &s, RESTOREIAP);
    assert_eq!(
        (poi.len(), back.len(), rst.len()), (1, 1, 1),
        "// CODE 498 lays out poisoniap, backtogame and restoreiap"
    );
    assert_eq!(
        (fget(&s, poi[0], "x"), fget(&s, poi[0], "y")), (V0.0 + 120.0, V0.1 + 100.0),
        "// CODE 498 view 0 layout for obj_poisoniap"
    );
    assert_eq!(
        (fget(&s, back[0], "x"), fget(&s, back[0], "y")), (V0.0 + 270.0, V0.1 + 190.0),
        "// CODE 498 view 0 layout for obj_backtogame"
    );
    assert_eq!(
        (fget(&s, rst[0], "x"), fget(&s, rst[0], "y")), (V0.0 + 40.0, V0.1 + 190.0),
        "// CODE 498 view 0 layout for obj_restoreiap"
    );
    assert!(
        !s.instances[&bystander].active,
        "// CODE 498 instance_deactivate_all(false) parks everything else"
    );
    for id in [menu, poi[0], back[0], rst[0]] {
        assert!(
            s.instances[&id].active,
            "// CODE 498 re-activates its own four objects (obj {})",
            s.instances[&id].object
        );
    }
    assert_eq!(s.globals.get("soundmute").copied(), Some(0.0), "the menu leaves the mute alone");
}

// ---- CODE 468 / 472: the two volume slots ----------------------------------

#[test]
fn volume_click_slots_toggle_the_two_mute_globals() {
    let b = shop_bundle();
    let mut s = shop_scene(&b);
    let v = s.create(&b, VOLUME, 0.0, 0.0).unwrap();
    s.dispatch(&b, v, 6, 4).unwrap();
    assert_eq!(s.globals["soundmute"], 1.0, "// CODE 468 mutes the sound");
    s.dispatch(&b, v, 6, 4).unwrap();
    assert_eq!(s.globals["soundmute"], 0.0, "// CODE 468 unmutes the sound");
    let vm = s.create(&b, VOLUMEMUSIC, 0.0, 0.0).unwrap();
    s.dispatch(&b, vm, 6, 4).unwrap();
    assert_eq!(s.globals["musicmute"], 1.0, "// CODE 472 mutes the music");
    s.dispatch(&b, vm, 6, 4).unwrap();
    assert_eq!(s.globals["musicmute"], 0.0, "// CODE 472 unmutes the music");
    assert_eq!(s.globals["soundmute"], 0.0, "// CODE 468 and 472 are independent");
    assert!(audio(&s).is_empty(), "the toggles never play anything themselves");

    // Boundary note, not a fake: both bodies live in the Left Pressed slot
    // (event 6 / subtype 4). This host's frame input pass raises (6, 0) for a
    // fresh press and (6, 7) for the release, so the Left Pressed slot has no
    // drive path here and the bodies are dispatched through their own slot.
}

// ============================================================================
// Batch 1 addendum — CODE 278 (obj_bomb Step). The batch-1 constant block
// named this body in a comment without a test; the execution trace showed it
// never ran, so the assertion is added here (fixture = batch 1's `scene`,
// which also configures the particle system the impact branch posts into).
// ============================================================================

#[test]
fn bomb_step_damages_one_victim_and_rearms_its_own_fuse() {
    let b = bundle();
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let bomb = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    assert_eq!(fget(&s, bomb, "hspeed"), 8.0, "CODE 275 facing 0 -> hspeed 8");
    assert_eq!(s.instances[&bomb].alarms[0], 30, "CODE 275 arms the 30-tick fuse");
    let knife = s.create(&b, KNIFE, 300.0, 200.0).unwrap();
    let wolf = s.create(&b, WOLF, 300.0, 200.0).unwrap();
    assert_eq!(
        s.call(&b, bomb, "instance_place", &[300.0, 200.0, KNIFE as f64]).unwrap(),
        knife as f64,
        "fixture: the bomb sits inside the knifebandit it must hit"
    );
    let dmg = s.globals["bombgundamage"];
    let hp0 = fget(&s, knife, "hpknife");
    let hpw0 = fget(&s, wolf, "hpwolf");
    let xp0 = s.globals["bombgunxp"];
    let before = ids(&s);

    s.dispatch(&b, bomb, 3, 0).unwrap();

    assert_eq!(fget(&s, bomb, "gravity"), 0.3, "// CODE 278 keeps the bomb ballistic");
    assert_eq!(hp0 - fget(&s, knife, "hpknife"), dmg, "// CODE 278 subtracts global.bombgundamage = {dmg}");
    assert_eq!(fget(&s, knife, "flashing"), 1.0, "// CODE 278 flashes the victim");
    assert_eq!(fget(&s, bomb, "canhit"), 1.0, "// CODE 278 latches canhit after one victim");
    assert_eq!(s.instances[&bomb].alarms[0], 1, "// CODE 278 re-arms its own fuse to 1");
    assert_eq!(s.globals["bombgunxp"], xp0 + 1.0, "// CODE 278 adds one bombgunxp");
    assert_eq!(s.particles.len(), 4, "// CODE 278 posts part_particles_create(..., 4)");
    assert_eq!(audio(&s), vec![SND_EXPLODE2], "// CODE 278 plays snd_explode2 = 8");
    let numbers = spawned(&before, &s, DAMAGE);
    assert_eq!(numbers.len(), 1, "// CODE 278 leaves one damage number");
    assert_eq!(fget(&s, numbers[0], "damage"), dmg, "// CODE 278 stamps the number with the damage");
    assert_eq!((fget(&s, numbers[0], "x"), fget(&s, numbers[0], "y")), (300.0, 200.0));
    assert_eq!(
        hpw0, fget(&s, wolf, "hpwolf"),
        "// CODE 278's canhit latch leaves the second overlapping victim alone"
    );
    assert_eq!(
        s.instances[&knife].alarms[6], -1,
        "// CODE 278 only touches the poison slot when global.poisonenabled == 1"
    );

    // global.poisonenabled == 1 arms the victim's poison slot (alarm[6]).
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    s.globals.insert("poisonenabled".into(), 1.0);
    let bomb = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    let knife = s.create(&b, KNIFE, 300.0, 200.0).unwrap();
    s.dispatch(&b, bomb, 3, 0).unwrap();
    assert_eq!(s.instances[&knife].alarms[6], 1, "// CODE 278 arms hitknife.alarm[6] = 1");

    // A par_wall ahead of the probe flips the bomb's velocity (move_bounce_solid).
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let bomb = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    set(&mut s, bomb, "vspeed", 3.0);
    let wall = s.create(&b, WALL, 308.0, 203.0).unwrap();
    assert_eq!(
        s.call(&b, bomb, "instance_place", &[308.0, 203.0, PAR_WALL as f64]).unwrap(),
        wall as f64,
        "fixture: the (x + hspeed, y + vspeed) probe reaches the fixture wall"
    );
    s.dispatch(&b, bomb, 3, 0).unwrap();
    assert_eq!(fget(&s, bomb, "hspeed"), -8.0, "// CODE 278 bounces hspeed off a wall");
    assert_eq!(fget(&s, bomb, "vspeed"), -3.0, "// CODE 278 bounces vspeed off a wall");
    assert_eq!(fget(&s, bomb, "gravity"), 0.3, "and still keeps its gravity");

    // spr_bigexplosion (50) is the blast pose: neither the bounce nor the
    // gravity write happens in it.
    let mut s = scene(&b);
    let _p = player(&mut s, &b, 500.0, 200.0, 0.0);
    let bomb = s.create(&b, BOMB, 300.0, 200.0).unwrap();
    set(&mut s, bomb, "vspeed", 3.0);
    let wall = s.create(&b, WALL, 308.0, 203.0).unwrap();
    assert_eq!(
        s.call(&b, bomb, "instance_place", &[308.0, 203.0, PAR_WALL as f64]).unwrap(),
        wall as f64,
        "fixture: the blast-pose bomb still has the wall ahead of it"
    );
    set(&mut s, bomb, "sprite_index", SPR_BIGEXPLOSION);
    s.dispatch(&b, bomb, 3, 0).unwrap();
    assert_eq!(fget(&s, bomb, "hspeed"), 8.0, "// CODE 278 skips the bounce in the blast pose");
    assert_eq!(fget(&s, bomb, "vspeed"), 3.0);
    assert_eq!(fget(&s, bomb, "gravity"), 0.0, "// CODE 278 skips the gravity write in the blast pose");
}
