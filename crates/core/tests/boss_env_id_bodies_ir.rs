//! WL42 batch — id-level body assertions for the last 14 boss-family and
//! `with`-environment CODE bodies the semantic census still carried without an
//! id-level test citation.
//!
//! obj_boss2 (26): CODE 163 Create_0, CODE 164 Destroy_0, CODE 168 Alarm_0.
//! obj_boss3 (27): CODE 182 Alarm_2.
//! obj_boss4 (28): CODE 188 Destroy_0, CODE 196 Alarm_0.
//! obj_boss5 (29): CODE 200 Destroy_0, CODE 212 Alarm_0.
//! obj_finalboss (30): CODE 217 Alarm_11.
//! obj_firehulk (18): CODE 82 Alarm_7, CODE 88 Alarm_0.
//! obj_house (2): CODE 21 Alarm_6.
//! obj_skeleton (17): CODE 77 Alarm_0.
//! obj_zombie (19): CODE 97 Alarm_0.
//!
//! These are REWRITE-SIDE IR regression semantics: every asserted value was read
//! out of the recovered GML body
//! (`~/cally-recovered-gml-0ca243a/restored-source/gml/`) and cross-checked
//! against the bytecode constants and instruction shapes in
//! `crates/core/src/generated/full_ir.json` on this host. They are NOT a proof
//! of equivalence with the original GameMaker runner. The shared suites
//! (`boss_family_id_bodies_ir`, `bosses_3_5_ir`, `enemy_family_id_bodies_ir`,
//! `env_with_sites_ir`) already execute these bodies end to end; this file adds
//! the per-body id naming and the explicit assertion of each body's own
//! observable effects.
//!
//! Fixture discipline (same shape as `boss_family_id_bodies_ir`,
//! `enemy_ladders_ii_ir`, `env_with_sites_ir`):
//!  * alarm bodies are driven with a DIRECT `dispatch` first, so no same-tick
//!    Step or physics pass can overwrite the value under assertion, and each
//!    body that hands a timer on is then re-verified through the real scheduler
//!    (`Scene::tick`) with the actors pinned every frame;
//!  * the two random draws of the shipped bodies are fixture-controlled, never
//!    guessed: `coindrop`/`hpdrop` are stored instance fields the engine writes
//!    once in Create and never recomputes, so the branch under test is selected
//!    by writing the field (the same latitude the existing suites take with
//!    `hptrex`);
//!  * `global.coinspread*`/`global.xpspread*` are NOT forged: `obj_muting`'s own
//!    Create (CODE 371) is the original producer, so the fixture creates that
//!    object and asserts the 30 spread globals exist. Because those draws are
//!    random, every fan assertion is a MULTISET equality against the specific
//!    global the GML names for that offset - a wrong slot only passes when the
//!    two random draws happen to collide;
//!  * `hpdrop` on the three shared enemies is a `choose()` in their Create, so
//!    those tests pin it to 1 instead of accepting a coin-flip;
//!  * `global.pwr` is a level-configuration global (obj_pwrlevelinitialize
//!    Create, CODE 458, in the original), never an engine-recomputed field, so
//!    the CODE 163 ladder test sets it per case.
//!
//! hp field lineage: boss2 `hpboss2`/`boss2maxhp`, firehulk `hpfirehulk`.
//!
//! The `with` bodies here (164/168/196/212/88/77/97 and the gem fans of 21) are
//! the census `env_classified` rows: `crates/core/tests/env_with_sites_ir.rs`
//! reconciles the instruction-level population (1,247 `pushenv` + 1,247
//! `popenv`) and `reconstruction/contracts/env-semantics.md` pins the four
//! receiver behaviours. This file asserts what each of those sites DOES on its
//! own target instances, and the VM's own "unbalanced stack/environment at CODE
//! exit" check makes every one of these tests a `popenv` balance test too,
//! including the empty-selection branch exercised in CODE 164/168.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const P: i32 = 0;
const HOUSE: i32 = 2;
const SKELETON: i32 = 17;
const FIREHULK: i32 = 18;
const ZOMBIE: i32 = 19;
const BOSS2: i32 = 26;
const BOSS3: i32 = 27;
const BOSS4: i32 = 28;
const BOSS5: i32 = 29;
const FINALBOSS: i32 = 30;
const SLIME: i32 = 32;
const FIRESLIME: i32 = 33;
const BOSS3PROJ: i32 = 55;
const GEM: i32 = 59;
const SILVERCOIN: i32 = 60;
const XPORB: i32 = 61;
const HEALTH: i32 = 62;
/// obj_muting (CODE 371) is the original producer of the coin/xp spread globals.
const MUTING: i32 = 67;
const DAMAGE: i32 = 104;
const LLOYD: i32 = 154;
const BOSSPUFF: i32 = 190;
/// Sound ids straight from the bodies' own constants.
const SND_EXPLODE: i32 = 7;
const SND_WEAPONLEVELUP: i32 = 28;
const SND_TECHNOENDING: i32 = 49;
const SND_BOSSSONGENDING: i32 = 50;
/// rm_ending: CODE 217's movement gate.
const RM_ENDING: f64 = 110.0;
/// The live voice CODE 164/188/200 must tear down (an arbitrary music sound).
const LIVE_MUSIC: f64 = 60.0;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// WL7: the app's SPRT wiring (recorded bbox + bounds + masks) so the shared box
/// source reads real geometry instead of integer points. CODE 21 probes with
/// `instance_place`.
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

/// Fresh globals + sprite geometry + the real `obj_muting` Create, which is what
/// fills `global.coinspread*`/`global.xpspread*` in the shipped game (CODE 371).
fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    wire_sprite_geometry(&mut s);
    // global.pwr is a per-level configuration global (obj_pwrlevelinitialize
    // Create, CODE 458); every boss's Create keys its HP ladder on it, and a
    // boss whose HP never got set reads 0 and dies on its own Step. Same value
    // the shared boss fixtures use.
    s.globals.insert("pwr".into(), 1.0);
    let m = s.create(b, MUTING, -1000.0, -1000.0).expect("obj_muting");
    park(&mut s, m);
    let spreads = s
        .globals
        .keys()
        .filter(|k| k.starts_with("coinspread") || k.starts_with("xpspread"))
        .count();
    assert_eq!(spreads, 30, "fixture: obj_muting seeded 25 coinspread + 5 xpspread");
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

fn pin(s: &mut Scene, id: i32, x: f64, y: f64) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("x".into(), x);
    i.fields.insert("y".into(), y);
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

/// Living instances of an object, in id order.
fn lives(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter().filter(|(_, x)| x.object == object && x.alive).map(|(id, _)| *id).collect()
}

fn count(s: &Scene, object: i32) -> usize {
    lives(s, object).len()
}

/// Every instance of an object ever created in this scene, dead or alive:
/// Destroy keeps the storage, so this is the creation tally.
fn created(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|x| x.object == object).count()
}

fn snapshot(s: &Scene, id: i32) -> [i32; 12] {
    s.instances[&id].alarms
}

/// The body wrote its own slot to `want` and touched no other timer.
fn assert_only_slot(s: &Scene, id: i32, before: &[i32; 12], slot: usize, want: i32, label: &str) {
    let after = snapshot(s, id);
    for i in 0..12 {
        if i == slot {
            assert_eq!(after[i], want, "{label}: alarm[{i}] must be re-armed to {want}");
        } else {
            assert_eq!(after[i], before[i], "{label}: alarm[{i}] must not be touched");
        }
    }
}

/// (x offset from the drop origin, the global the GML reads for that instance).
/// `None` is a coin the GML creates WITHOUT a `with` block (no `motion_set`).
type Fan = Vec<(f64, Option<&'static str>)>;

/// One entry per created instance of `object`: (dx, y, direction, speed), sorted
/// by offset then raw bits so the comparison is order independent. `to_bits` is
/// monotonic for the non-negative finite values here.
fn fan_observed(s: &Scene, object: i32, ox: f64) -> Vec<(i64, f64, f64, f64)> {
    let mut got: Vec<(i64, f64, f64, f64)> = s
        .instances
        .values()
        .filter(|i| i.object == object)
        .map(|i| {
            let x = i.fields["x"];
            (
                (x - ox).round() as i64,
                i.fields["y"],
                i.fields.get("direction").copied().unwrap_or(0.0),
                i.fields.get("speed").copied().unwrap_or(0.0),
            )
        })
        .collect();
    got.sort_by_key(|t| (t.0, t.1.to_bits(), t.2.to_bits(), t.3.to_bits()));
    got
}

/// The multiset of (dx, y, direction, speed) the table predicts, sorted the same
/// way. Named entries move at `speed` along `global[name]`; `None` entries are
/// the GML's bare creates (no `with`), which keep the Create's own zero motion.
fn fan_expected(s: &Scene, table: &[(f64, Option<&str>)], oy: f64, dy: f64, speed: f64) -> Vec<(i64, f64, f64, f64)> {
    let mut want: Vec<(i64, f64, f64, f64)> = table
        .iter()
        .map(|(off, name)| match name {
            Some(n) => {
                let dir = *s.globals.get(*n).unwrap_or_else(|| panic!("fixture: global {n}"));
                (off.round() as i64, oy + dy, dir, speed)
            }
            None => (off.round() as i64, oy + dy, 0.0, 0.0),
        })
        .collect();
    want.sort_by_key(|t| (t.0, t.1.to_bits(), t.2.to_bits(), t.3.to_bits()));
    want
}

/// `created` instances of `object` must be exactly the dropped fan the table
/// names, each at `oy + dy`, each riding the global the GML reads for its offset.
fn assert_fan(s: &Scene, object: i32, ox: f64, oy: f64, dy: f64, table: &[(f64, Option<&str>)], speed: f64, label: &str) {
    let got = fan_observed(s, object, ox);
    let want = fan_expected(s, table, oy, dy, speed);
    assert_eq!(got, want, "{label}: dropped fan of {object} (dx, y, direction, speed)");
}

/// The 25-slot XP-orb fan the five boss/enemy death beats share: ten orbs, two
/// per spread slot, all at y-35 and speed 5. Byte-identical blocks - the env
/// ledger counts 85 sites in CODE 168/196/212 and the same 10-orb shape in the
/// 43/45/39-site enemy variants.
fn xp_fan_boss() -> Fan {
    vec![
        (0.0, Some("coinspread")), (7.0, Some("coinspread2")), (-7.0, Some("coinspread3")),
        (12.0, Some("coinspread4")), (-12.0, Some("coinspread5")),
        (0.0, Some("coinspread")), (16.0, Some("coinspread2")), (-17.0, Some("coinspread3")),
        (20.0, Some("coinspread4")), (-21.0, Some("coinspread5")),
    ]
}

/// The coindrop tier table of obj_boss2/obj_boss4/obj_boss5 Alarm_0: 5, 10, 15,
/// 20, 25 silver coins, each tier the previous one plus five new offsets. Branch
/// 1..5 -> index 0..4.
fn boss_coin_fan(branch: usize) -> Fan {
    let base: Fan = vec![
        (0.0, Some("coinspread")), (2.0, Some("coinspread2")), (-2.0, Some("coinspread3")),
        (4.0, Some("coinspread4")), (-4.0, Some("coinspread5")),
    ];
    let second: Fan = vec![
        (-10.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
        (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")),
    ];
    let third: Fan = vec![
        (10.0, Some("coinspread11")), (10.0, Some("coinspread12")), (-10.0, Some("coinspread13")),
        (12.0, Some("coinspread14")), (-12.0, Some("coinspread15")),
    ];
    // Tier 4 re-shuffles slots 6..20 (`+11` replaces `-10`, `-11` appears twice).
    let fourth_tier4: Fan = vec![
        (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
        (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")),
        (-11.0, Some("coinspread11")), (10.0, Some("coinspread12")), (-10.0, Some("coinspread13")),
        (12.0, Some("coinspread14")), (-12.0, Some("coinspread15")),
        (-11.0, Some("coinspread16")), (14.0, Some("coinspread17")), (-14.0, Some("coinspread18")),
        (16.0, Some("coinspread19")), (-16.0, Some("coinspread20")),
    ];
    let fourth_tier5: Fan = vec![
        (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
        (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")),
        (-11.0, Some("coinspread11")), (10.0, Some("coinspread12")), (-10.0, Some("coinspread13")),
        (12.0, Some("coinspread14")), (-12.0, Some("coinspread15")),
        (15.0, Some("coinspread16")), (14.0, Some("coinspread17")), (-14.0, Some("coinspread18")),
        (16.0, Some("coinspread19")), (-16.0, Some("coinspread20")),
    ];
    let fifth_tier5: Fan = vec![
        (-15.0, Some("coinspread21")), (18.0, Some("coinspread22")), (-18.0, Some("coinspread23")),
        (20.0, Some("coinspread24")), (-20.0, Some("coinspread25")),
    ];
    let mut out = base;
    if branch >= 2 {
        out.extend(second);
    }
    if branch >= 3 {
        out.extend(third);
    }
    if branch == 4 {
        out.truncate(5);
        out.extend(fourth_tier4);
    }
    if branch == 5 {
        out.truncate(5);
        out.extend(fourth_tier5);
        out.extend(fifth_tier5);
    }
    out
}

/// What each of the three shared enemy death beats drops: one obj_XPorb riding
/// `global.xpspread`, then the coindrop tier (gated on < 20 live coins).
fn enemy_coin_fan(object: i32, branch: usize) -> Fan {
    let base: Fan = vec![
        (0.0, Some("coinspread")), (2.0, Some("coinspread2")), (-2.0, Some("coinspread3")),
        (4.0, Some("coinspread4")), (-4.0, Some("coinspread5")),
    ];
    let mut out = base;
    match (object, branch) {
        // obj_firehulk (CODE 88): 5, 7, 9, 9, 12.
        (FIREHULK, 1) => {}
        (FIREHULK, 2) => out.extend([
            (-10.0, Some("coinspread6")), (6.0, Some("coinspread7")),
        ]),
        (FIREHULK, 3) => out.extend([
            (-10.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")),
        ]),
        (FIREHULK, 4) => out.extend([
            (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")),
        ]),
        (FIREHULK, 5) => out.extend([
            (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")), (-11.0, Some("coinspread11")),
            (10.0, Some("coinspread12")),
        ]),
        // obj_skeleton (CODE 77): 5, 7, 8, 11, 13.
        (SKELETON, 1) => {}
        (SKELETON, 2) => out.extend([
            (-10.0, Some("coinspread6")), (6.0, Some("coinspread7")),
        ]),
        (SKELETON, 3) => out.extend([
            (-10.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
        ]),
        (SKELETON, 4) => out.extend([
            (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")), (-11.0, Some("coinspread11")),
        ]),
        (SKELETON, 5) => out.extend([
            (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")), (-11.0, Some("coinspread11")),
            (10.0, Some("coinspread12")), (-10.0, Some("coinspread13")),
        ]),
        // obj_zombie (CODE 97): 5, 7, 7, 11, 11 - and its tiers 2/3 end on a coin
        // the shipped body creates with NO `with` block (no motion_set at all),
        // tier 4 the same. The dropped tails are visible in the IR: 39 `pushenv`
        // against 41 created coins.
        (ZOMBIE, 1) => {}
        (ZOMBIE, 2) | (ZOMBIE, 3) => out.extend([
            (-10.0, Some("coinspread6")), (6.0, None),
        ]),
        (ZOMBIE, 4) => out.extend([
            (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")), (-11.0, None),
        ]),
        (ZOMBIE, 5) => out.extend([
            (11.0, Some("coinspread6")), (6.0, Some("coinspread7")), (-6.0, Some("coinspread8")),
            (8.0, Some("coinspread9")), (-8.0, Some("coinspread10")), (-11.0, Some("coinspread11")),
        ]),
        (o, b) => panic!("no coin fan for object {o} tier {b}"),
    }
    out
}

// ---- obj_boss2 (26) ---------------------------------------------------------

// CODE 163 — obj_boss2 Create_0
#[test]
fn boss2_create_scales_its_hp_ladder_by_pwr_and_arms_the_timer() {
    let b = bundle();
    // CODE 163: the four `global.pwr` rungs 750/700/625/525, panic-clear flags,
    // xpdrop/hpdrop 1, facing 0, alarm[1] = 100, coindrop = choose(1..5).
    for (pwr, want) in [(1.0, 750.0), (2.0, 700.0), (3.0, 625.0), (4.0, 525.0)] {
        let mut s = scene(&b);
        let p = player(&mut s, &b, 500.0, 200.0);
        park(&mut s, p);
        s.globals.insert("pwr".into(), pwr);
        let boss = s.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");
        let i = &s.instances[&boss];
        assert_eq!(i.fields["hpboss2"], want, "// CODE 163: pwr {pwr} -> hpboss2");
        assert_eq!(i.fields["boss2maxhp"], want, "// CODE 163: pwr {pwr} -> boss2maxhp");
        assert_eq!(i.fields["flashing"], 0.0, "// CODE 163: flashing 0");
        assert_eq!(i.fields["poisoned"], 0.0, "// CODE 163: poisoned 0");
        assert_eq!(i.fields["swordstunned"], 0.0, "// CODE 163: swordstunned 0");
        assert_eq!(i.fields["facing"], 0.0, "// CODE 163: facing 0");
        assert_eq!(i.fields["xpdrop"], 1.0, "// CODE 163: xpdrop 1");
        assert_eq!(i.fields["hpdrop"], 1.0, "// CODE 163: hpdrop 1");
        let cd = i.fields["coindrop"];
        assert!(
            cd.fract() == 0.0 && (1.0..=5.0).contains(&cd),
            "// CODE 163: coindrop is choose(1,2,3,4,5), got {cd}"
        );
        assert_only_slot(&s, boss, &[-1; 12], 1, 100, "// CODE 163");
    }

    // pwr outside 1..=4 (a level with no power pickup): the body writes no HP at
    // all, so neither field is even created on the instance.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    s.globals.insert("pwr".into(), 0.0);
    let boss = s.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");
    assert!(
        !s.instances[&boss].fields.contains_key("hpboss2"),
        "// CODE 163: pwr 0 writes no hpboss2"
    );
    assert!(
        !s.instances[&boss].fields.contains_key("boss2maxhp"),
        "// CODE 163: pwr 0 writes no boss2maxhp"
    );
}

// CODE 164 — obj_boss2 Destroy_0 (env_classified, 4 environment sites)
#[test]
fn boss2_destroy_sweeps_the_slime_pool_and_leaves_lloyd_and_a_puff() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let slime_a = s.create(&b, SLIME, 100.0, 200.0).expect("obj_slime");
    let slime_b = s.create(&b, SLIME, 120.0, 200.0).expect("obj_slime");
    let fire = s.create(&b, FIRESLIME, 140.0, 200.0).expect("obj_fireslime");
    let boss = s.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");

    // A looping music voice is live before the Destroy body runs.
    s.call_audio_play(LIVE_MUSIC, 0.0, true);
    assert!(
        s.audio_voices.iter().any(|v| v.sound == LIVE_MUSIC && v.looping),
        "fixture: a looping music voice is live"
    );
    s.audio.clear();
    let _ = s.take_stop_commands();

    // CODE 164: instance_activate_all(); with(obj_slime) instance_destroy();
    // with(obj_fireslime) instance_destroy(); instance_create(1024,256,obj_lloyd);
    // audio_stop_all(); audio_play_sound(mus_technoending, 0, false);
    // instance_create(x, y, obj_bosspuff);
    s.destroy(&b, boss).expect("// CODE 164 Destroy_0 runs");
    assert!(!s.instances[&boss].alive, "// CODE 164: the boss ends dead");
    assert!(
        s.instances[&p].active,
        "// CODE 164: instance_activate_all() re-activates the parked player"
    );
    for (id, label) in [(slime_a, "obj_slime"), (slime_b, "obj_slime"), (fire, "obj_fireslime")] {
        assert!(!s.instances[&id].alive, "// CODE 164: with({label}) instance_destroy()");
    }
    // Each swept slime ran its own Destroy (CODE 245/257 bump the kill counters).
    assert_eq!(s.globals["greenslimeskilled"], 2.0, "// CODE 164: both slimes died through their Destroy");
    assert_eq!(s.globals["fireslimeskilled"], 1.0, "// CODE 164: so did the fireslime");
    assert_eq!(s.globals["enemieskilled"], 3.0, "// CODE 164: 2 slimes + 1 fireslime counted");

    let lloyd = lives(&s, LLOYD);
    assert_eq!(lloyd.len(), 1, "// CODE 164: instance_create(1024, 256, obj_lloyd)");
    assert_eq!(
        (s.instances[&lloyd[0]].fields["x"], s.instances[&lloyd[0]].fields["y"]),
        (1024.0, 256.0),
        "// CODE 164: Lloyd lands on the fixed (1024, 256)"
    );
    assert!(
        s.audio_voices.iter().any(|v| v.sound == LIVE_MUSIC && v.stopped),
        "// CODE 164: audio_stop_all() stops the live music voice"
    );
    assert!(
        s.take_stop_commands().contains(&LIVE_MUSIC),
        "// CODE 164: and queues the host-side stop for it"
    );
    let theme: Vec<&callys_core::ir_scene::AudioCommand> = s.audio.iter().filter(|c| c.code == 164).collect();
    assert_eq!(theme.len(), 1, "// CODE 164: exactly one sound, attributed to CODE 164");
    assert_eq!(theme[0].sound, SND_TECHNOENDING, "// CODE 164: mus_technoending is SOND 49");
    assert!(!theme[0].looping, "// CODE 164: loop = false");
    assert_eq!(theme[0].priority, 0.0, "// CODE 164: priority 0");
    let puff = lives(&s, BOSSPUFF);
    assert_eq!(puff.len(), 1, "// CODE 164: one obj_bosspuff");
    assert_eq!(
        (s.instances[&puff[0]].fields["x"], s.instances[&puff[0]].fields["y"]),
        (300.0, 200.0),
        "// CODE 164: instance_create(x, y, obj_bosspuff) at the boss's own coordinates"
    );
}

// CODE 164 — the empty-selection branch of both `with` sites.
#[test]
fn boss2_destroy_with_no_slimes_in_the_room_still_balances_both_environments() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let boss = s.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");
    assert_eq!(count(&s, SLIME), 0, "fixture: no obj_slime exists");
    assert_eq!(count(&s, FIRESLIME), 0, "fixture: no obj_fireslime exists");
    s.audio.clear();
    // object_exists(obj_slime) is true (the object is compiled), so the `with`
    // body IS entered - with an empty receiver set. The VM rejects an unbalanced
    // environment stack at CODE exit, so a clean return is the balance proof.
    s.destroy(&b, boss).expect("// CODE 164: empty `with` selection must pop its environment");
    assert_eq!(lives(&s, LLOYD).len(), 1, "// CODE 164: Lloyd is created either way");
    assert_eq!(count(&s, BOSSPUFF), 1, "// CODE 164: the puff is created either way");
    assert_eq!(
        s.globals.get("enemieskilled").copied().unwrap_or(0.0),
        0.0,
        "// CODE 164: nothing was swept, so no kill counter was touched"
    );
}

/// Directly dispatch a boss's death beat with the Create's random draws pinned
/// to `branch`/hpdrop 1. The player is parked far away so the drops are the only
/// new instances.
fn boss_death_beat(b: &Bundle, object: i32, branch: f64) -> (Scene, i32, i32) {
    let mut s = scene(b);
    let p = player(&mut s, b, 2000.0, 2000.0);
    park(&mut s, p);
    let boss = s.create(b, object, 300.0, 200.0).expect("boss");
    {
        let i = s.instances.get_mut(&boss).unwrap();
        i.fields.insert("coindrop".into(), branch);
        i.fields.insert("hpdrop".into(), 1.0);
    }
    s.audio.clear();
    s.dispatch(b, boss, 2, 0).expect("// death beat");
    (s, boss, p)
}

/// The two gem/health drops a boss death beat leaves at (x, y - 35).
fn assert_gem_and_health(s: &Scene, label: &str) {
    let gem = lives(s, GEM);
    assert_eq!(gem.len(), 1, "{label}: one obj_gem (gemdropenabled 1)");
    assert_eq!(
        (s.instances[&gem[0]].fields["x"], s.instances[&gem[0]].fields["y"]),
        (300.0, 165.0),
        "{label}: gem at (x, y - 35)"
    );
    let health = lives(s, HEALTH);
    assert_eq!(health.len(), 1, "{label}: one obj_health (hpdrop 1)");
    assert_eq!(
        (s.instances[&health[0]].fields["x"], s.instances[&health[0]].fields["y"]),
        (300.0, 165.0),
        "{label}: health at (x, y - 35)"
    );
}

// CODE 168 — obj_boss2 Alarm_0
#[test]
fn boss2_death_beat_drops_the_configured_fan_and_kills_the_boss() {
    let b = bundle();
    for branch in 1..=5usize {
        let (s, boss, _p) = boss_death_beat(&b, BOSS2, branch as f64);
        let label = format!("// CODE 168 coindrop {branch}");
        assert!(!s.instances[&boss].alive, "{label}: action_kill_object()");
        assert_eq!(s.globals["boss2dead"], 1.0, "{label}: global.boss2dead latched");
        assert_eq!(
            s.audio.iter().filter(|c| c.sound == SND_EXPLODE && c.code == 168).count(),
            1,
            "{label}: snd_explode attributed to CODE 168 (soundmute 0)"
        );
        assert_gem_and_health(&s, &label);
        assert_fan(&s, XPORB, 300.0, 200.0, -35.0, &xp_fan_boss(), 5.0, &format!("{label} XP fan"));
        assert_fan(
            &s,
            SILVERCOIN,
            300.0,
            200.0,
            -35.0,
            &boss_coin_fan(branch),
            5.0,
            &format!("{label} coin fan"),
        );
    }

    // global.soundmute == 1 takes the empty branch: no snd_explode from the body.
    let mut s2 = scene(&b);
    let p = player(&mut s2, &b, 2000.0, 2000.0);
    park(&mut s2, p);
    s2.globals.insert("soundmute".into(), 1.0);
    let boss2 = s2.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");
    s2.instances.get_mut(&boss2).unwrap().fields.insert("coindrop".into(), 1.0);
    s2.audio.clear();
    s2.dispatch(&b, boss2, 2, 0).expect("// CODE 168 muted");
    assert!(
        s2.audio.iter().all(|c| c.sound != SND_EXPLODE),
        "// CODE 168: soundmute 1 silences the body's own explosion"
    );
    assert_eq!(s2.audio.iter().filter(|c| c.code == 164).count(), 1,
        "// CODE 168: the kill's own Destroy fanfare still plays");
    assert_eq!(s2.globals["boss2dead"], 1.0, "// CODE 168: the flag is outside the sound gate");
    assert_eq!(lives(&s2, SILVERCOIN).len(), 5, "// CODE 168: the drops are outside the sound gate");

    // global.gemdropenabled == 0 removes only the gem.
    let mut s3 = scene(&b);
    let p = player(&mut s3, &b, 2000.0, 2000.0);
    park(&mut s3, p);
    s3.globals.insert("gemdropenabled".into(), 0.0);
    let boss3 = s3.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");
    s3.instances.get_mut(&boss3).unwrap().fields.insert("coindrop".into(), 1.0);
    s3.dispatch(&b, boss3, 2, 0).expect("// CODE 168 no gem");
    assert_eq!(count(&s3, GEM), 0, "// CODE 168: gemdropenabled 0 -> no obj_gem");
    assert_eq!(count(&s3, HEALTH), 1, "// CODE 168: hpdrop is still 1");
}

// CODE 168 — the real trigger path: Step arms alarm[0] = 1 at hp <= 0.
#[test]
fn boss2_death_beat_fires_from_its_own_alarm_slot_on_the_real_scheduler() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 2000.0);
    park(&mut s, p);
    let boss = s.create(&b, BOSS2, 300.0, 200.0).expect("obj_boss2");
    // hpboss2 is written by the damage path only; the engine never recomputes it.
    s.instances.get_mut(&boss).unwrap().fields.insert("hpboss2".into(), 0.0);
    s.instances.get_mut(&boss).unwrap().fields.insert("coindrop".into(), 5.0);
    s.audio.clear();

    s.dispatch(&b, boss, 3, 0).expect("// CODE 169 Step_0");
    assert_eq!(s.instances[&boss].alarms[0], 1, "// CODE 169: hp <= 0 loads alarm[0] = 1");
    pin(&mut s, p, 2000.0, 2000.0);
    pin(&mut s, boss, 300.0, 200.0);
    s.tick(&b).expect("// the 1-tick alarm fires CODE 168");

    assert!(!s.instances[&boss].alive, "// CODE 168 ran through its own slot and killed the boss");
    assert_eq!(s.globals["boss2dead"], 1.0, "// CODE 168: flag latched through the scheduler");
    assert_eq!(created(&s, XPORB), 10, "// CODE 168: the 10-orb fan materialized");
    assert_eq!(created(&s, SILVERCOIN), 25, "// CODE 168: coindrop 5 -> 25 coins");
    assert_eq!(count(&s, GEM), 1, "// CODE 168: the gem drop materialized");
    assert_eq!(s.instances[&boss].alarms[0], -1, "// CODE 168: the slot retired after firing");
}

// ---- obj_boss3 (27) ---------------------------------------------------------

// CODE 182 — obj_boss3 Alarm_2
#[test]
fn boss3_alarm_2_fires_one_projectile_and_hands_over_to_alarm_3() {
    let b = bundle();
    let mut s = scene(&b);
    // Active on purpose: obj_boss3projectile's own Create (CODE 335) aims.
    let _p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS3, 300.0, 200.0).expect("obj_boss3");
    let before = snapshot(&s, bs);

    // CODE 182: bullet1 = instance_create(x - 50, y, obj_boss3projectile);
    // alarm[3] = 10;
    s.dispatch(&b, bs, 2, 2).expect("// CODE 182 Alarm_2");
    let shots = lives(&s, BOSS3PROJ);
    assert_eq!(shots.len(), 1, "// CODE 182: exactly one obj_boss3projectile");
    let sh = &s.instances[&shots[0]];
    assert_eq!((sh.fields["x"], sh.fields["y"]), (250.0, 200.0), "// CODE 182: spawned at (x - 50, y)");
    assert_eq!(
        s.instances[&bs].fields["bullet1"], shots[0] as f64,
        "// CODE 182: the created id is stored in bullet1"
    );
    assert_only_slot(&s, bs, &before, 3, 10, "// CODE 182");
    // The projectile's own Create (CODE 335) owns its motion: speed -5 and a
    // direction drawn from choose(-30, -15, 0, 15, 30, 45, 60).
    assert_eq!(sh.fields["speed"], -5.0, "fixture observation: CODE 335 pins speed -5");
    let dir = sh.fields["direction"];
    assert!(
        [-30.0, -15.0, 0.0, 15.0, 30.0, 45.0, 60.0].contains(&dir),
        "fixture observation: CODE 335's choose direction, got {dir}"
    );

    // A second beat adds a second projectile, not a replacement.
    s.dispatch(&b, bs, 2, 2).expect("// CODE 182 second beat");
    assert_eq!(lives(&s, BOSS3PROJ).len(), 2, "// CODE 182: one projectile per beat");
}

// CODE 182 — the real scheduler path: CODE 183 (Alarm_1) loads alarm[2] = 10.
#[test]
fn boss3_alarm_2_is_dispatched_by_its_own_alarm_slot() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let bs = s.create(&b, BOSS3, 300.0, 200.0).expect("obj_boss3");
    s.dispatch(&b, bs, 2, 1).expect("// CODE 183 Alarm_1 loads the next beat");
    assert_eq!(s.instances[&bs].alarms[2], 10, "// CODE 183: alarm[2] = 10");
    assert_eq!(lives(&s, BOSS3PROJ).len(), 1, "// CODE 183: and fires its own projectile");

    for n in 1..=9 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, bs, 300.0, 200.0);
        s.tick(&b).expect("tick");
        assert_eq!(s.instances[&bs].alarms[2], 10 - n, "// CODE 182's slot counts down, tick {n}");
    }
    pin(&mut s, p, 500.0, 200.0);
    pin(&mut s, bs, 300.0, 200.0);
    s.tick(&b).expect("// the 10th tick dispatches CODE 182");
    assert_eq!(lives(&s, BOSS3PROJ).len(), 2, "// CODE 182 ran through the real alarm slot");
    // CODE 182 loads alarm[3] = 10 during the alarm[2] event, and the same alarm
    // pass then walks slot 3 - so the freshly loaded 10 is already down to 9.
    assert_eq!(s.instances[&bs].alarms[3], 9, "// CODE 182: alarm[3] loaded then decremented in the same pass");
}

// ---- obj_boss4 (28) ---------------------------------------------------------

// CODE 188 — obj_boss4 Destroy_0
#[test]
fn boss4_destroy_stops_the_audio_and_leaves_the_ending_theme_and_a_puff() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let boss = s.create(&b, BOSS4, 300.0, 200.0).expect("obj_boss4");
    s.call_audio_play(LIVE_MUSIC, 0.0, true);
    s.audio.clear();
    let _ = s.take_stop_commands();

    // CODE 188: audio_stop_all(); audio_play_sound(mus_technoending, 0, false);
    // instance_create(x, y, obj_bosspuff);
    s.destroy(&b, boss).expect("// CODE 188 Destroy_0 runs");
    assert!(!s.instances[&boss].alive, "// CODE 188: the boss ends dead");
    assert!(
        s.audio_voices.iter().any(|v| v.sound == LIVE_MUSIC && v.stopped),
        "// CODE 188: audio_stop_all() stops the live voice"
    );
    assert!(s.take_stop_commands().contains(&LIVE_MUSIC), "// CODE 188: host stop queued");
    let theme: Vec<&callys_core::ir_scene::AudioCommand> = s.audio.iter().filter(|c| c.code == 188).collect();
    assert_eq!(theme.len(), 1, "// CODE 188: exactly one sound");
    assert_eq!(theme[0].sound, SND_TECHNOENDING, "// CODE 188: mus_technoending (49)");
    assert!(!theme[0].looping, "// CODE 188: loop = false");
    assert_eq!(lives(&s, BOSSPUFF).len(), 1, "// CODE 188: one obj_bosspuff");
    assert_eq!(
        (s.instances[&lives(&s, BOSSPUFF)[0]].fields["x"], s.instances[&lives(&s, BOSSPUFF)[0]].fields["y"]),
        (300.0, 200.0),
        "// CODE 188: the puff sits on the boss"
    );
    // CODE 188 is Destroy-only: no slime sweep, no Lloyd.
    assert_eq!(count(&s, LLOYD), 0, "// CODE 188: unlike CODE 164 it creates no Lloyd");
}

// CODE 196 — obj_boss4 Alarm_0
#[test]
fn boss4_death_beat_drops_the_configured_fan_and_kills_the_boss() {
    let b = bundle();
    for branch in 1..=5usize {
        let (s, boss, _p) = boss_death_beat(&b, BOSS4, branch as f64);
        let label = format!("// CODE 196 coindrop {branch}");
        assert!(!s.instances[&boss].alive, "{label}: action_kill_object()");
        assert_eq!(s.globals["boss4dead"], 1.0, "{label}: global.boss4dead latched");
        assert_eq!(
            s.audio.iter().filter(|c| c.sound == SND_EXPLODE && c.code == 196).count(),
            1,
            "{label}: snd_explode attributed to CODE 196"
        );
        assert_gem_and_health(&s, &label);
        assert_fan(&s, XPORB, 300.0, 200.0, -35.0, &xp_fan_boss(), 5.0, &format!("{label} XP fan"));
        assert_fan(
            &s,
            SILVERCOIN,
            300.0,
            200.0,
            -35.0,
            &boss_coin_fan(branch),
            5.0,
            &format!("{label} coin fan"),
        );
    }
    // The muted branch of CODE 196's own probe.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 2000.0);
    park(&mut s, p);
    s.globals.insert("soundmute".into(), 1.0);
    let boss = s.create(&b, BOSS4, 300.0, 200.0).expect("obj_boss4");
    s.instances.get_mut(&boss).unwrap().fields.insert("coindrop".into(), 2.0);
    s.audio.clear();
    s.dispatch(&b, boss, 2, 0).expect("// CODE 196 muted");
    assert!(
        s.audio.iter().all(|c| c.sound != SND_EXPLODE),
        "// CODE 196: soundmute 1 silences the body's explosion"
    );
    assert_eq!(lives(&s, SILVERCOIN).len(), 10, "// CODE 196: coindrop 2 -> 10 coins");
    assert_eq!(s.globals["boss4dead"], 1.0, "// CODE 196: the flag is outside the gate");
}

// ---- obj_boss5 (29) ---------------------------------------------------------

// CODE 200 — obj_boss5 Destroy_0
#[test]
fn boss5_destroy_plays_the_boss_ending_theme_and_leaves_a_puff() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let boss = s.create(&b, BOSS5, 300.0, 200.0).expect("obj_boss5");
    s.call_audio_play(LIVE_MUSIC, 0.0, true);
    s.audio.clear();
    let _ = s.take_stop_commands();

    // CODE 200: audio_stop_all(); audio_play_sound(mus_bosssongending, 0, false);
    // instance_create(x, y, obj_bosspuff);
    s.destroy(&b, boss).expect("// CODE 200 Destroy_0 runs");
    assert!(!s.instances[&boss].alive, "// CODE 200: the boss ends dead");
    assert!(
        s.audio_voices.iter().any(|v| v.sound == LIVE_MUSIC && v.stopped),
        "// CODE 200: audio_stop_all() stops the live voice"
    );
    assert!(s.take_stop_commands().contains(&LIVE_MUSIC), "// CODE 200: host stop queued");
    let theme: Vec<&callys_core::ir_scene::AudioCommand> = s.audio.iter().filter(|c| c.code == 200).collect();
    assert_eq!(theme.len(), 1, "// CODE 200: exactly one sound");
    // boss5 is the one boss whose Destroy body plays mus_bosssongending, not
    // mus_technoending: its constant is 50 where 164/188/216 use 49.
    assert_eq!(theme[0].sound, SND_BOSSSONGENDING, "// CODE 200: mus_bosssongending (50)");
    assert!(!theme[0].looping, "// CODE 200: loop = false");
    assert_eq!(theme[0].priority, 0.0, "// CODE 200: priority 0");
    assert_eq!(lives(&s, BOSSPUFF).len(), 1, "// CODE 200: one obj_bosspuff");
    assert_eq!(count(&s, LLOYD), 0, "// CODE 200: no Lloyd in this body");
}

// CODE 212 — obj_boss5 Alarm_0
#[test]
fn boss5_death_beat_drops_the_configured_fan_and_kills_the_boss() {
    let b = bundle();
    for branch in 1..=5usize {
        let (s, boss, _p) = boss_death_beat(&b, BOSS5, branch as f64);
        let label = format!("// CODE 212 coindrop {branch}");
        assert!(!s.instances[&boss].alive, "{label}: action_kill_object()");
        assert_eq!(s.globals["boss5dead"], 1.0, "{label}: global.boss5dead latched");
        assert_eq!(
            s.audio.iter().filter(|c| c.sound == SND_EXPLODE && c.code == 212).count(),
            1,
            "{label}: snd_explode attributed to CODE 212"
        );
        assert_gem_and_health(&s, &label);
        assert_fan(&s, XPORB, 300.0, 200.0, -35.0, &xp_fan_boss(), 5.0, &format!("{label} XP fan"));
        assert_fan(
            &s,
            SILVERCOIN,
            300.0,
            200.0,
            -35.0,
            &boss_coin_fan(branch),
            5.0,
            &format!("{label} coin fan"),
        );
    }
}

// ---- obj_finalboss (30) -----------------------------------------------------

// CODE 217 — obj_finalboss Alarm_11
#[test]
fn finalboss_alarm_11_swoops_only_outside_the_ending_room() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).expect("obj_finalboss");
    let before = snapshot(&s, fb);
    // CODE 217: if (room != rm_ending) { vspeed = 1; hspeed = -2; alarm[4] = 100; }
    s.dispatch(&b, fb, 2, 11).expect("// CODE 217 Alarm_11");
    assert_eq!(s.instances[&fb].fields["vspeed"], 1.0, "// CODE 217: vspeed 1");
    assert_eq!(s.instances[&fb].fields["hspeed"], -2.0, "// CODE 217: hspeed -2");
    assert_only_slot(&s, fb, &before, 4, 100, "// CODE 217");

    // In rm_ending the whole body is inert: no velocity write, no timer.
    let mut s2 = scene(&b);
    let p2 = player(&mut s2, &b, 500.0, 200.0);
    park(&mut s2, p2);
    let fb2 = s2.create(&b, FINALBOSS, 300.0, 200.0).expect("obj_finalboss");
    s2.current_room = RM_ENDING;
    {
        let i = s2.instances.get_mut(&fb2).unwrap();
        i.fields.insert("hspeed".into(), 7.0);
        i.fields.insert("vspeed".into(), -7.0);
    }
    let before2 = snapshot(&s2, fb2);
    s2.dispatch(&b, fb2, 2, 11).expect("// CODE 217 in rm_ending");
    assert_eq!(s2.instances[&fb2].fields["hspeed"], 7.0, "// CODE 217: gated on room != rm_ending");
    assert_eq!(s2.instances[&fb2].fields["vspeed"], -7.0, "// CODE 217: gated on room != rm_ending");
    assert_eq!(snapshot(&s2, fb2), before2, "// CODE 217: no timer is loaded in rm_ending");
}

// CODE 217 — the real hand-off: CODE 218 (Alarm_10) loads alarm[11] = 100.
#[test]
fn finalboss_alarm_11_is_dispatched_by_its_own_alarm_slot() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).expect("obj_finalboss");
    s.dispatch(&b, fb, 2, 10).expect("// CODE 218 Alarm_10");
    assert_eq!(s.instances[&fb].alarms[11], 100, "// CODE 218: alarm[11] = 100");
    for _ in 0..100 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, fb, 300.0, 200.0);
        s.tick(&b).expect("tick");
    }
    // CODE 217's own hand-offs. alarm[4] and alarm[7] have exactly one loader
    // each after Create: CODE 217 loads alarm[4] = 100, and CODE 224 (Alarm_4,
    // fired by this very tick at slot 4) loads alarm[7] = 100. Both values
    // survive (alarm[4]) or are decremented once (alarm[7], a later slot in the
    // same pass) - the pair pins the frame order: 224 at slot 4, then 217 at
    // slot 11. The velocities CODE 217 writes are asserted raw in the
    // direct-dispatch test above, because the Step body (CODE 229) rewrites
    // hspeed/vspeed later in the same frame.
    assert_eq!(
        s.instances[&fb].alarms[4], 100,
        "// CODE 217 ran through the real alarm[11] slot and loaded alarm[4] = 100"
    );
    assert_eq!(
        s.instances[&fb].alarms[7], 99,
        "// CODE 224 fired first in the same alarm pass (its 100 was already decremented)"
    );
}

// ---- obj_firehulk (18) ------------------------------------------------------

// CODE 82 — obj_firehulk Alarm_7
#[test]
fn firehulk_alarm_7_poison_tick_bites_and_re_arms_itself() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    // obj_firehulk's Create (CODE 80) keys hpfirehulk on global.level: the rungs
    // are level <= 10 -> 100, <= 15 -> 115, <= 20 -> 130 for pwr 1 (and 95/80,
    // 110/105, 120/115 for pwr 2..4). Level 16 is the shipped rung the firehulk
    // rooms use, so the fixture mounts the same configuration the room does.
    s.globals.insert("level".into(), 16.0);
    let fh = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    let hp0 = s.instances[&fh].fields["hpfirehulk"];
    assert_eq!(hp0, 130.0, "fixture: CODE 80 at level 16 / pwr 1 gives 130 hp");
    assert_eq!(s.instances[&fh].fields["poisoned"], 0.0, "fixture: unpoisoned before the tick");
    let before = snapshot(&s, fh);

    // CODE 82: poisoned = 1; hpfirehulk -= 0.25; i = instance_create(x, y,
    // obj_damage); i.damage = 0.25; alarm[7] = 30;
    s.dispatch(&b, fh, 2, 7).expect("// CODE 82 Alarm_7");
    assert_eq!(s.instances[&fh].fields["poisoned"], 1.0, "// CODE 82: poison flag raised");
    assert_eq!(hp0 - s.instances[&fh].fields["hpfirehulk"], 0.25, "// CODE 82: a quarter heart of poison");
    assert_only_slot(&s, fh, &before, 7, 30, "// CODE 82");
    let dmg = lives(&s, DAMAGE);
    assert_eq!(dmg.len(), 1, "// CODE 82: one obj_damage number");
    assert_eq!(s.instances[&dmg[0]].fields["damage"], 0.25, "// CODE 82: the number carries damage 0.25");
    assert_eq!(
        (s.instances[&dmg[0]].fields["x"], s.instances[&dmg[0]].fields["y"]),
        (300.0, 200.0),
        "// CODE 82: created at the firehulk's own coordinates"
    );

    // Through the real scheduler: this body is its own clock (nothing else loads
    // alarm[7]), so the 30-tick timer fires it again and re-arms.
    for _ in 0..30 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, fh, 300.0, 200.0);
        s.tick(&b).expect("tick");
    }
    assert_eq!(hp0 - s.instances[&fh].fields["hpfirehulk"], 0.5, "// CODE 82 self-fired on its 30-tick alarm");
    assert_eq!(s.instances[&fh].alarms[7], 30, "// CODE 82: and re-armed its own slot");
    assert_eq!(created(&s, DAMAGE), 2, "// CODE 82: two damage numbers in total");
}

/// Direct-dispatch one of the three shared enemy death beats (CODE 88/77/97)
/// with the Create's `choose()` draws pinned.
fn enemy_death_beat(b: &Bundle, object: i32, branch: f64) -> (Scene, i32) {
    let mut s = scene(b);
    let p = player(&mut s, b, 2000.0, 2000.0);
    park(&mut s, p);
    let e = s.create(b, object, 300.0, 200.0).expect("enemy");
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("coindrop".into(), branch);
        i.fields.insert("hpdrop".into(), 1.0);
    }
    s.audio.clear();
    s.dispatch(b, e, 2, 0).expect("// death beat");
    (s, e)
}

/// The one-orb XP drop plus the branch's coin fan of a shared enemy death beat.
fn assert_enemy_beat_drops(s: &Scene, object: i32, branch: usize, label: &str) {
    assert_fan(s, XPORB, 300.0, 200.0, -35.0, &vec![(0.0, Some("xpspread"))], 5.0, &format!("{label} XP orb"));
    assert_eq!(
        s.instances[&lives(s, XPORB)[0]].fields["y"],
        165.0,
        "{label}: the single orb drops at y - 35"
    );
    let gem = lives(s, GEM);
    assert_eq!(gem.len(), 1, "{label}: one obj_gem (gemdropenabled 1)");
    let health = lives(s, HEALTH);
    assert_eq!(health.len(), 1, "{label}: one obj_health (hpdrop 1)");
    assert_fan(
        s,
        SILVERCOIN,
        300.0,
        200.0,
        -35.0,
        &enemy_coin_fan(object, branch),
        5.0,
        &format!("{label} coin fan"),
    );
}

// CODE 88 — obj_firehulk Alarm_0
#[test]
fn firehulk_death_beat_drops_its_fan_and_kills_the_enemy() {
    let b = bundle();
    for branch in 1..=5usize {
        let (s, fh) = enemy_death_beat(&b, FIREHULK, branch as f64);
        let label = format!("// CODE 88 coindrop {branch}");
        assert!(!s.instances[&fh].alive, "{label}: action_kill_object()");
        assert_eq!(
            s.audio.iter().filter(|c| c.sound == SND_EXPLODE && c.code == 88).count(),
            1,
            "{label}: snd_explode attributed to CODE 88"
        );
        assert_enemy_beat_drops(&s, FIREHULK, branch, &label);
    }
    // audible-in-total check: the body's own explosion is the only snd 7.
    let (s, _e) = enemy_death_beat(&b, FIREHULK, 1.0);
    assert_eq!(s.audio.iter().filter(|c| c.sound == SND_EXPLODE).count(), 1,
        "// CODE 88: one explosion for the beat");
}

// CODE 88 — the `instance_number(obj_silvercoin) >= 20` gate.
#[test]
fn firehulk_death_beat_stops_coining_once_twenty_coins_are_in_the_room() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 2000.0);
    park(&mut s, p);
    for n in 0..20 {
        s.create(&b, SILVERCOIN, 100.0 + n as f64, 400.0).expect("fixture coin");
    }
    let fh = s.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    {
        let i = s.instances.get_mut(&fh).unwrap();
        i.fields.insert("coindrop".into(), 5.0);
        i.fields.insert("hpdrop".into(), 1.0);
    }
    s.dispatch(&b, fh, 2, 0).expect("// CODE 88 with a full coin room");
    assert_eq!(created(&s, SILVERCOIN), 20, "// CODE 88: the >= 20 gate suppresses the whole coin tier");
    assert_eq!(created(&s, XPORB), 1, "// CODE 88: the XP orb is outside the gate");
    assert_eq!(count(&s, GEM), 1, "// CODE 88: the gem is outside the gate");
    assert!(!s.instances[&fh].alive, "// CODE 88: the kill is outside the gate");

    // One coin short: the tier runs again (19 existing + 12 new).
    let mut s2 = scene(&b);
    let p2 = player(&mut s2, &b, 2000.0, 2000.0);
    park(&mut s2, p2);
    for n in 0..19 {
        s2.create(&b, SILVERCOIN, 100.0 + n as f64, 400.0).expect("fixture coin");
    }
    let fh2 = s2.create(&b, FIREHULK, 300.0, 200.0).expect("obj_firehulk");
    {
        let i = s2.instances.get_mut(&fh2).unwrap();
        i.fields.insert("coindrop".into(), 5.0);
        i.fields.insert("hpdrop".into(), 1.0);
    }
    s2.dispatch(&b, fh2, 2, 0).expect("// CODE 88 with 19 coins");
    assert_eq!(created(&s2, SILVERCOIN), 31, "// CODE 88: 19 + the 12-coin tier");
}

// ---- obj_house (2) ----------------------------------------------------------

// CODE 21 — obj_house Alarm_6
/// The ten gems of CODE 21, all at y + 100 and speed 8 (not 5).
fn house_gem_fan() -> Fan {
    vec![
        (350.0, Some("coinspread")), (352.0, Some("coinspread2")), (355.0, Some("coinspread3")),
        (345.0, Some("coinspread4")), (360.0, Some("coinspread5")), (340.0, Some("coinspread6")),
        (335.0, Some("coinspread7")), (365.0, Some("coinspread8")), (370.0, Some("coinspread9")),
        (330.0, Some("coinspread10")),
    ]
}

#[test]
fn house_alarm_6_gifts_ten_gems_once_when_the_player_stands_on_it() {
    let b = bundle();
    let mut s = scene(&b);
    let h = s.create(&b, HOUSE, 300.0, 200.0).expect("obj_house");
    // The probe is `instance_place(x, y, obj_player)` from the house's own box,
    // so the player must be active AND overlapping.
    let p = player(&mut s, &b, 300.0, 200.0);
    assert!(s.instances[&p].active, "fixture: the player is visible to instance_place");
    let gems_before = s.globals["gemsfromhouse"];
    assert_eq!(gems_before, 0.0, "fixture: the house has not paid out yet");
    s.audio.clear();

    // CODE 21: if (instance_place(x, y, obj_player) && global.gemsfromhouse == 0)
    //   { ten obj_gem at (x + 350..330, y + 100) with motion_set(coinspreadN, 8);
    //     global.gemsfromhouse = 1; audio_play_sound(snd_weaponlevelup, 0, false); }
    s.dispatch(&b, h, 2, 6).expect("// CODE 21 Alarm_6");
    assert_eq!(s.globals["gemsfromhouse"], 1.0, "// CODE 21: the payout latches");
    assert_fan(&s, GEM, 300.0, 200.0, 100.0, &house_gem_fan(), 8.0, "// CODE 21 gem fan");
    let snd: Vec<&callys_core::ir_scene::AudioCommand> = s.audio.iter().filter(|c| c.code == 21).collect();
    assert_eq!(snd.len(), 1, "// CODE 21: one sound");
    assert_eq!(snd[0].sound, SND_WEAPONLEVELUP, "// CODE 21: snd_weaponlevelup is SOND 28");
    assert!(!snd[0].looping, "// CODE 21: loop = false");

    // The latch is checked by the body itself: a second beat pays nothing.
    let audio_len = s.audio.len();
    s.dispatch(&b, h, 2, 6).expect("// CODE 21 second beat");
    assert_eq!(created(&s, GEM), 10, "// CODE 21: gemsfromhouse 1 blocks the second payout");
    assert_eq!(s.audio.len(), audio_len, "// CODE 21: and the sound is inside the same gate");

    // Player away: the `instance_place` probe fails, so nothing is paid.
    let mut s2 = scene(&b);
    let h2 = s2.create(&b, HOUSE, 300.0, 200.0).expect("obj_house");
    let p2 = player(&mut s2, &b, 3000.0, 2000.0);
    assert!(s2.instances[&p2].active, "fixture: an active but distant player");
    s2.audio.clear();
    s2.dispatch(&b, h2, 2, 6).expect("// CODE 21 with nobody home");
    assert_eq!(count(&s2, GEM), 0, "// CODE 21: no overlap -> no gems");
    assert_eq!(s2.globals["gemsfromhouse"], 0.0, "// CODE 21: and no latch");
    assert!(s2.audio.is_empty(), "// CODE 21: and no sound");

    // soundmute 1 keeps the gems and drops only the sound (the gate is the inner
    // `global.soundmute == 0` probe).
    let mut s3 = scene(&b);
    let h3 = s3.create(&b, HOUSE, 300.0, 200.0).expect("obj_house");
    let p3 = player(&mut s3, &b, 300.0, 200.0);
    let _ = p3;
    s3.globals.insert("soundmute".into(), 1.0);
    s3.audio.clear();
    s3.dispatch(&b, h3, 2, 6).expect("// CODE 21 muted");
    assert_eq!(count(&s3, GEM), 10, "// CODE 21: the gems are outside the sound gate");
    assert_eq!(s3.globals["gemsfromhouse"], 1.0, "// CODE 21: the latch is outside it too");
    assert!(s3.audio.is_empty(), "// CODE 21: soundmute 1 silences snd_weaponlevelup");
}

// CODE 21 — the real scheduler path: CODE 22 (Alarm_5) loads alarm[6] = 600.
#[test]
fn house_alarm_6_is_dispatched_by_its_own_alarm_slot() {
    let b = bundle();
    let mut s = scene(&b);
    let h = s.create(&b, HOUSE, 300.0, 200.0).expect("obj_house");
    let p = player(&mut s, &b, 300.0, 200.0);
    s.audio.clear();
    s.dispatch(&b, h, 2, 5).expect("// CODE 22 Alarm_5 loads the gem beat");
    assert_eq!(s.instances[&h].alarms[6], 600, "// CODE 22: alarm[6] = 600");
    for n in 0..600 {
        pin(&mut s, p, 300.0, 200.0);
        pin(&mut s, h, 300.0, 200.0);
        s.tick(&b).expect("tick");
        if n < 3 {
            assert_eq!(s.instances[&h].alarms[6], 600 - 1 - n, "// CODE 21's slot counts down, tick {}", n + 1);
        }
    }
    assert_eq!(s.globals["gemsfromhouse"], 1.0, "// CODE 21 ran on the 600th tick");
    assert_eq!(created(&s, GEM), 10, "// CODE 21: the ten gems came out of the real slot");
}

// ---- obj_skeleton (17) ------------------------------------------------------

// CODE 77 — obj_skeleton Alarm_0
#[test]
fn skeleton_death_beat_drops_its_fan_and_kills_the_enemy() {
    let b = bundle();
    for branch in 1..=5usize {
        let (s, e) = enemy_death_beat(&b, SKELETON, branch as f64);
        let label = format!("// CODE 77 coindrop {branch}");
        assert!(!s.instances[&e].alive, "{label}: action_kill_object()");
        assert_eq!(
            s.audio.iter().filter(|c| c.sound == SND_EXPLODE && c.code == 77).count(),
            1,
            "{label}: snd_explode attributed to CODE 77"
        );
        assert_enemy_beat_drops(&s, SKELETON, branch, &label);
    }
    // The >= 20 coin gate lives in this body too.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 2000.0);
    park(&mut s, p);
    for n in 0..20 {
        s.create(&b, SILVERCOIN, 100.0 + n as f64, 400.0).expect("fixture coin");
    }
    let e = s.create(&b, SKELETON, 300.0, 200.0).expect("obj_skeleton");
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("coindrop".into(), 5.0);
        i.fields.insert("hpdrop".into(), 1.0);
    }
    s.dispatch(&b, e, 2, 0).expect("// CODE 77 with a full coin room");
    assert_eq!(created(&s, SILVERCOIN), 20, "// CODE 77: instance_number >= 20 suppresses the tier");
    assert_eq!(created(&s, XPORB), 1, "// CODE 77: the orb still drops");
}

// ---- obj_zombie (19) --------------------------------------------------------

// CODE 97 — obj_zombie Alarm_0
#[test]
fn zombie_death_beat_drops_its_fan_and_kills_the_enemy() {
    let b = bundle();
    for branch in 1..=5usize {
        let (s, e) = enemy_death_beat(&b, ZOMBIE, branch as f64);
        let label = format!("// CODE 97 coindrop {branch}");
        assert!(!s.instances[&e].alive, "{label}: action_kill_object()");
        assert_eq!(
            s.audio.iter().filter(|c| c.sound == SND_EXPLODE && c.code == 97).count(),
            1,
            "{label}: snd_explode attributed to CODE 97"
        );
        assert_enemy_beat_drops(&s, ZOMBIE, branch, &label);
    }
    // The shipped zombie body loads its slot differently from the skeleton: tiers
    // 2 and 3 create seven coins but only six `with` blocks, tier 4 eleven coins
    // and ten blocks. The bare coin keeps the Create's own zero motion, which the
    // fan table above asserts as (direction 0, speed 0) - 39 environment sites
    // against 41 created coins in the IR.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 2000.0);
    park(&mut s, p);
    for n in 0..20 {
        s.create(&b, SILVERCOIN, 100.0 + n as f64, 400.0).expect("fixture coin");
    }
    let e = s.create(&b, ZOMBIE, 300.0, 200.0).expect("obj_zombie");
    {
        let i = s.instances.get_mut(&e).unwrap();
        i.fields.insert("coindrop".into(), 3.0);
        i.fields.insert("hpdrop".into(), 1.0);
    }
    s.dispatch(&b, e, 2, 0).expect("// CODE 97 with a full coin room");
    assert_eq!(created(&s, SILVERCOIN), 20, "// CODE 97: instance_number >= 20 suppresses the tier");
    assert_eq!(created(&s, XPORB), 1, "// CODE 97: the orb still drops");
    assert_eq!(count(&s, GEM), 1, "// CODE 97: the gem still drops");
    assert_eq!(count(&s, HEALTH), 1, "// CODE 97: the health still drops");
}
