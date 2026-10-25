//! UI progression: the two directly-dependent `obj_UI` Alarm bodies, enumerated.
//!
//!   * CODE 367 = `gml_Object_obj_UI_Alarm_1` - the 12-weapon x 10-level damage
//!     table plus each weapon's own "level > 10 -> level = 10" ceiling.
//!   * CODE 368 = `gml_Object_obj_UI_Alarm_0` - the 30-tick re-arming XP
//!     dispatcher: per-weapon XP thresholds, the player level ceiling of 20,
//!     the `drawlevelup` / `drawweaponlevelup` overlay latches, the 36
//!     "weapon reached tier 4/7/10" banner arms, the `drawweaponchange`
//!     consumer and the two `choose()` sound ids.
//!
//! Both bodies are bytecode-shaped flat tables of INDEPENDENT `if` statements
//! (no `switch`), so unlike a chain every comparison executes on every call:
//!
//!     load <weapon>level; constant L; cmp(3 = eq); bf next; constant V; store <weapon>damage
//!     ...
//!     load <weapon>level; constant 10; cmp(6 = gt); bf next; constant 10; store <weapon>level
//!     constant 30; constant -1; constant 1; store alarm[array]        <- re-arms slot 1 / 0
//!
//! and CODE 368's `&&` arms (`level == tier && drawchange<w><tier> == 1`) compile
//! with an UNCONDITIONAL `b` that jumps over a `constant 0` false value:
//!
//!     load <weapon>level; constant T; cmp(3); bf next
//!     load <weapon>drawchange...; constant 1; cmp(3); b next+1   <- short-circuit
//!     constant 0                                                  <- the false value
//!     bf next; constant 1; store drawweaponchange; constant 0; store <flag>
//!
//! Provenance of the expected tables
//! ---------------------------------
//! The `DAMAGE`, `XP` and `BANNER` tables below were extracted from the
//! authoritative bytecode in `crates/core/src/generated/full_ir.json` (keys
//! `codes[].id`, never `code_id`; CODE 367 start 4219172, CODE 368 start
//! 4224184) by a scratch probe (`wl59-ui-alarms_gen.py`, not checked in) that
//! walks the instruction stream and prints these rows; nothing here was hand
//! transcribed from the recovered GML. The recovered GML (`0367`/`0368`) was
//! used only as navigation; every constant, store name, jump and spawn
//! parameter in this file is cross-derived from the live Bundle at run time by
//! `validate_alarm1` / `validate_alarm0`, which fail if the embedded table and
//! the shipped bytecode disagree. `perturbing_the_tables_is_rejected` proves
//! those validators are not self-satisfying: it mutates a CLONE of the Bundle
//! (one arm's write value, one arm's jump target, one store name, one spawn
//! object id, one spawn offset, one banner short-circuit) and requires every
//! mutation to be rejected.
//!
//! Census (asserted, not asserted-by-comment):
//!   * CODE 367: 796 instructions, 132 `bf`, 0 `bt`, 0 `b`; 12 families x 10
//!     `==` arms = 120 damage stores, plus 12 `gt` ceiling arms.
//!   * CODE 368: 834 instructions, 103 `bf`, 0 `bt`, 36 `b` (the `&&`
//!     short-circuits of the 36 banner arms), 12 XP blocks, 36 banner arms.
//!
//! Shipped semantics that a "clean" rewrite would get wrong (all pinned below):
//!   1. `pistol` is the one XP block whose `level += 1`, `xptolevelup *= 1.5`
//!      and `drawweaponlevelup = 1` sit OUTSIDE the `level < 10` guard: only
//!      `pistolxp = 1` is guarded. At level 10 the pistol therefore still
//!      levels up (to 11), still multiplies its threshold and still raises the
//!      banner latch - and only the NEXT CODE 367 call clamps it back to 10.
//!   2. `bladegun` multiplies into `bladegunxpxptolevelup` (an extra `xp`), a
//!      typo in the shipped body: `bladegunxptolevelup` never grows, so the
//!      bladegun re-levels on every subsequent call.
//!   3. The `drawweaponlevelup` latch is consumed at the TOP of CODE 368, i.e.
//!      BEFORE this call's own level-ups arm it again: a banner raised by this
//!      call is spawned by the NEXT call (one-dispatch delay).
//!   4. `drawlevelup` is cleared unconditionally in its own block, but the
//!      `obj_levelup` overlay only spawns while `level <= 20` AT THAT POINT -
//!      so a level-up that pushes the player to 21 (level 20 -> 21) shows no
//!      overlay, and the following `level >= 20` clamp lands on 20.
//!   5. CODE 367 stores damage only when the level EQUALS a table row: a level
//!      above 10 clamps the level in the same call without recomputing damage,
//!      so the fresh damage arrives one dispatch later.
//!
//! Fixture discipline
//! ------------------
//! The `dispatch`-level tests create their instances directly and never `tick`,
//! so no engine-side Step can recompute the globals under test - CODE 12
//! (`obj_player` Step) and CODE 369 (`obj_UI` Step) contain no store to any
//! `*damage` / `*level` / `*xp` name in the shipped bytecode (verified over
//! their full store-name sets), and `dispatch` alone does not run Steps. The
//! natural-scheduling test uses untouched `init_fresh_start_globals` state and
//! `Scene::tick`, i.e. the real alarm slots armed by CODE 365.
//!
//! Scope: re-written-end IR regression semantics. Nothing here claims parity
//! with the original runner, a rendered frame, or a real device.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Code, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::collections::BTreeSet;
use std::path::Path;

// ---- object ids (from the bundle's object table) ---------------------------

/// obj_player (persistent, sprite 29) - `obj_levelup`'s Create reads its x/y.
const PLAYER: i32 = 0;
/// obj_levelup (sprite 35, Create CODE 352).
const LEVELUP: i32 = 63;
/// obj_weaponlevelup (sprite 34, Create CODE 357).
const WEAPONLEVELUP: i32 = 64;
/// obj_UI (sprite 84, Create CODE 365, Alarm 0 CODE 368, Alarm 1 CODE 367).
const UI: i32 = 66;
/// obj_weaponchange (no sprite, Create CODE 409).
const WEAPONCHANGE: i32 = 83;
/// obj_weaponswap (sprite 151) - `obj_weaponlevelup`'s spawn anchor.
const WEAPONSWAP: i32 = 126;

const CODE_ALARM1: usize = 367;
const CODE_ALARM0: usize = 368;
const ALARM1_START: usize = 4_219_172;
const ALARM0_START: usize = 4_224_184;

/// Distinctive value pre-seeded into every damage global: an arm that does not
/// run must leave it in place, which is how "no store" is told apart from
/// "stored the same number twice".
const SENTINEL: f64 = -999.0;

/// `init_fresh_start_globals` seeds `drawchange<weapon><tier> = 1` for all 36
/// tiers; the isolated XP tests zero them so a level-up crossing 4/7/10 cannot
/// also open the weaponchange overlay (covered by its own test).
const BANNER_FLAGS: [&str; 36] = [
    "drawchangepistol4", "drawchangeshotgun4", "drawchangeassaultrifle4", "drawchangerocket4",
    "drawchangelaser4", "drawchangeicegun4", "drawchangebow4", "drawchangebladegun4",
    "drawchangeflamethrower4", "drawchangeboomerang4", "drawchangespikegun4", "drawchangebombgun4",
    "drawchangepistol7", "drawchangeshotgun7", "drawchangeassaultrifle7", "drawchangerocket7",
    "drawchangelaser7", "drawchangeicegun7", "drawchangebow7", "drawchangebladegun7",
    "drawchangeflamethrower7", "drawchangeboomerang7", "drawchangespikegun7", "drawchangebombgun7",
    "drawchangepistol10", "drawchangeshotgun10", "drawchangeassaultrifle10", "drawchangerocket10",
    "drawchangelaser10", "drawchangeicegun10", "drawchangebow10", "drawchangebladegun10",
    "drawchangeflamethrower10", "drawchangeboomerang10", "drawchangespikegun10",
    "drawchangebombgun10",
];

// ---- embedded tables (machine-extracted from full_ir.json, see module doc) --

/// (level global, damage global, 10 damage values, the 10 damage-store
/// code_offsets in arm order, the ceiling-store offset, the ceiling-branch
/// offset) - CODE 367 in bytecode order.
#[rustfmt::skip]
const DAMAGE: [(&str, &str, [f64; 10], [usize; 10], usize, usize); 12] = [
    ("pistollevel", "pistoldamage",
     [1.0, 1.3, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4.0, 5.0],
     [24, 64, 104, 136, 176, 216, 256, 296, 328, 360], 392, 384),
    ("shotgunlevel", "shotgundamage",
     [0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.5],
     [432, 472, 512, 552, 592, 624, 664, 704, 744, 784], 816, 808),
    ("assaultriflelevel", "assaultrifledamage",
     [0.6, 0.7, 0.8, 1.0, 1.1, 1.2, 1.4, 1.5, 1.7, 2.0],
     [856, 896, 936, 968, 1008, 1048, 1088, 1128, 1168, 1200], 1232, 1224),
    ("icegunlevel", "icegundamage",
     [1.0, 1.2, 1.4, 1.7, 1.9, 2.1, 2.4, 2.6, 2.8, 3.0],
     [1264, 1304, 1344, 1384, 1424, 1464, 1504, 1544, 1584, 1616], 1648, 1640),
    ("laserlevel", "laserdamage",
     [1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.5],
     [1688, 1728, 1768, 1808, 1848, 1880, 1920, 1960, 2000, 2040], 2072, 2064),
    ("rocketlevel", "rocketdamage",
     [2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.2, 3.4, 3.6, 4.0],
     [2112, 2152, 2192, 2232, 2272, 2304, 2344, 2384, 2424, 2456], 2488, 2480),
    ("bowlevel", "bowdamage",
     [2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 4.0],
     [2520, 2560, 2600, 2640, 2680, 2712, 2752, 2792, 2832, 2864], 2896, 2888),
    ("flamethrowerlevel", "flamethrowerdamage",
     [0.3, 0.5, 0.7, 0.9, 1.0, 1.1, 1.2, 1.4, 1.5, 2.0],
     [2936, 2976, 3016, 3056, 3088, 3128, 3168, 3208, 3248, 3280], 3312, 3304),
    ("bladegunlevel", "bladegundamage",
     [1.0, 1.2, 1.3, 1.5, 1.6, 1.7, 2.0, 2.1, 2.2, 2.5],
     [3344, 3384, 3424, 3464, 3504, 3544, 3576, 3616, 3656, 3696], 3728, 3720),
    ("spikegunlevel", "spikegundamage",
     [1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.2, 2.4, 2.6, 3.0],
     [3768, 3808, 3848, 3888, 3928, 3960, 4000, 4040, 4080, 4112], 4144, 4136),
    ("boomeranglevel", "boomerangdamage",
     [0.1, 0.15, 0.2, 0.3, 0.35, 0.4, 0.5, 0.6, 0.7, 1.0],
     [4184, 4224, 4264, 4304, 4344, 4384, 4424, 4464, 4504, 4536], 4568, 4560),
    ("bombgunlevel", "bombgundamage",
     [3.5, 3.7, 3.9, 4.0, 4.1, 4.2, 4.4, 4.5, 4.6, 5.0],
     [4608, 4648, 4688, 4720, 4760, 4800, 4840, 4880, 4920, 4952], 4984, 4976),
];

/// (xp global, level global, the stores INSIDE the `level < 10` guard, their
/// code_offsets) - CODE 368's 12 XP blocks in bytecode order.
#[rustfmt::skip]
const XP: [(&str, &str, &[&str], &[usize]); 12] = [
    // The pistol block guards ONLY the xp reset - see exception (1) in the module doc.
    ("pistolxp", "pistollevel", &["pistolxp"], &[476]),
    ("shotgunxp", "shotgunlevel",
     &["shotgunxp", "shotgunlevel", "shotgunxptolevelup", "drawweaponlevelup"],
     &[600, 624, 656, 668]),
    ("assaultriflexp", "assaultriflelevel",
     &["assaultriflexp", "assaultriflelevel", "assaultriflexptolevelup", "drawweaponlevelup"],
     &[724, 748, 780, 792]),
    ("rocketxp", "rocketlevel",
     &["rocketxp", "rocketlevel", "rocketxptolevelup", "drawweaponlevelup"],
     &[848, 872, 904, 916]),
    ("laserxp", "laserlevel",
     &["laserxp", "laserlevel", "laserxptolevelup", "drawweaponlevelup"],
     &[972, 996, 1028, 1040]),
    ("icegunxp", "icegunlevel",
     &["icegunxp", "icegunlevel", "icegunxptolevelup", "drawweaponlevelup"],
     &[1096, 1120, 1152, 1164]),
    ("bowxp", "bowlevel",
     &["bowxp", "bowlevel", "bowxptolevelup", "drawweaponlevelup"],
     &[1220, 1244, 1276, 1288]),
    // Exception (2): the shipped store name carries a doubled `xp`.
    ("bladegunxp", "bladegunlevel",
     &["bladegunxp", "bladegunlevel", "bladegunxpxptolevelup", "drawweaponlevelup"],
     &[1344, 1368, 1400, 1412]),
    ("flamethrowerxp", "flamethrowerlevel",
     &["flamethrowerxp", "flamethrowerlevel", "flamethrowerxptolevelup", "drawweaponlevelup"],
     &[1468, 1492, 1524, 1536]),
    ("boomerangxp", "boomeranglevel",
     &["boomerangxp", "boomeranglevel", "boomerangxptolevelup", "drawweaponlevelup"],
     &[1592, 1616, 1648, 1660]),
    ("spikegunxp", "spikegunlevel",
     &["spikegunxp", "spikegunlevel", "spikegunxptolevelup", "drawweaponlevelup"],
     &[1716, 1740, 1772, 1784]),
    ("bombgunxp", "bombgunlevel",
     &["bombgunxp", "bombgunlevel", "bombgunxptolevelup", "drawweaponlevelup"],
     &[1840, 1864, 1896, 1908]),
];

/// (level global, tier, banner latch global, `drawweaponchange` store offset,
/// latch-clear store offset) - CODE 368's 36 banner arms, tier-major order.
#[rustfmt::skip]
const BANNER: [(&str, f64, &str, usize, usize); 36] = [
    ("pistollevel", 4.0, "drawchangepistol4", 1968, 1980),
    ("shotgunlevel", 4.0, "drawchangeshotgun4", 2040, 2052),
    ("assaultriflelevel", 4.0, "drawchangeassaultrifle4", 2112, 2124),
    ("rocketlevel", 4.0, "drawchangerocket4", 2184, 2196),
    ("laserlevel", 4.0, "drawchangelaser4", 2256, 2268),
    ("icegunlevel", 4.0, "drawchangeicegun4", 2328, 2340),
    ("bowlevel", 4.0, "drawchangebow4", 2400, 2412),
    ("bladegunlevel", 4.0, "drawchangebladegun4", 2472, 2484),
    ("flamethrowerlevel", 4.0, "drawchangeflamethrower4", 2544, 2556),
    ("boomeranglevel", 4.0, "drawchangeboomerang4", 2616, 2628),
    ("spikegunlevel", 4.0, "drawchangespikegun4", 2688, 2700),
    ("bombgunlevel", 4.0, "drawchangebombgun4", 2760, 2772),
    ("pistollevel", 7.0, "drawchangepistol7", 2832, 2844),
    ("shotgunlevel", 7.0, "drawchangeshotgun7", 2904, 2916),
    ("assaultriflelevel", 7.0, "drawchangeassaultrifle7", 2976, 2988),
    ("rocketlevel", 7.0, "drawchangerocket7", 3048, 3060),
    ("laserlevel", 7.0, "drawchangelaser7", 3120, 3132),
    ("icegunlevel", 7.0, "drawchangeicegun7", 3192, 3204),
    ("bowlevel", 7.0, "drawchangebow7", 3264, 3276),
    ("bladegunlevel", 7.0, "drawchangebladegun7", 3336, 3348),
    ("flamethrowerlevel", 7.0, "drawchangeflamethrower7", 3408, 3420),
    ("boomeranglevel", 7.0, "drawchangeboomerang7", 3480, 3492),
    ("spikegunlevel", 7.0, "drawchangespikegun7", 3552, 3564),
    ("bombgunlevel", 7.0, "drawchangebombgun7", 3624, 3636),
    ("pistollevel", 10.0, "drawchangepistol10", 3696, 3708),
    ("shotgunlevel", 10.0, "drawchangeshotgun10", 3768, 3780),
    ("assaultriflelevel", 10.0, "drawchangeassaultrifle10", 3840, 3852),
    ("rocketlevel", 10.0, "drawchangerocket10", 3912, 3924),
    ("laserlevel", 10.0, "drawchangelaser10", 3984, 3996),
    ("icegunlevel", 10.0, "drawchangeicegun10", 4056, 4068),
    ("bowlevel", 10.0, "drawchangebow10", 4128, 4140),
    ("bladegunlevel", 10.0, "drawchangebladegun10", 4200, 4212),
    ("flamethrowerlevel", 10.0, "drawchangeflamethrower10", 4272, 4284),
    ("boomeranglevel", 10.0, "drawchangeboomerang10", 4344, 4356),
    ("spikegunlevel", 10.0, "drawchangespikegun10", 4416, 4428),
    ("bombgunlevel", 10.0, "drawchangebombgun10", 4488, 4500),
];

/// The `obj_weaponlevelup` spawn at the top of CODE 368: (object, dx, dy,
/// x/y source selector). `drawweaponlevelup` is consumed before this call, so
/// the latch read here belongs to the previous dispatch.
const HEAD_SPAWN: (f64, f64, f64, i32) = (64.0, -32.0, 132.0, WEAPONSWAP);
/// The `obj_levelup` spawn inside the `drawlevelup` block: (obj, dx, dy,
/// selector) - selector 0 is obj_player.
const LEVELUP_SPAWN: (f64, f64, f64, i32) = (63.0, -45.0, -32.0, 0);
/// The `obj_weaponchange` spawn at the tail: (obj, dx, dy, selector) - self.
const CHANGE_SPAWN: (f64, f64, f64, i32) = (83.0, 0.0, 0.0, -1);
/// Both bodies re-arm their own slot with this value; CODE 368 also arms it
/// mid-body, before its XP blocks.
const REARM: f64 = 30.0;

// ---- fixture ---------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// A scene with the three instances the alarm bodies can reach: the UI itself
/// (whose Create arms the real alarms), obj_weaponswap (spawn anchor) and,
/// optionally, obj_player (the `obj_levelup` spawn reads its x/y).
struct Fx {
    b: Bundle,
    s: Scene,
    ui: i32,
    swap: i32,
    player: Option<i32>,
}

const PLAYER_XY: (f64, f64) = (100.0, 200.0);
const SWAP_XY: (f64, f64) = (300.0, 400.0);
const UI_XY: (f64, f64) = (10.0, 20.0);

fn fx(with_player: bool) -> Fx {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.init_fresh_start_globals();
    let swap = s.create(&b, WEAPONSWAP, SWAP_XY.0, SWAP_XY.1).expect("create obj_weaponswap");
    let player = if with_player {
        Some(s.create(&b, PLAYER, PLAYER_XY.0, PLAYER_XY.1).expect("create obj_player"))
    } else {
        None
    };
    let ui = s.create(&b, UI, UI_XY.0, UI_XY.1).expect("create obj_UI");
    Fx { b, s, ui, swap, player }
}

fn g(s: &Scene, name: &str) -> f64 {
    *s.globals.get(name).unwrap_or_else(|| panic!("global {name} is not set"))
}

fn set_g(s: &mut Scene, name: &str, v: f64) {
    s.globals.insert(name.to_string(), v);
}

fn field(s: &Scene, id: i32, name: &str) -> f64 {
    *s.instances[&id].fields.get(name).unwrap_or_else(|| panic!("instance {id} has no {name}"))
}

// ---- live-IR derivation ----------------------------------------------------

fn code<'a>(b: &'a Bundle, id: usize) -> &'a Code {
    b.codes.iter().find(|c| c.id == id).unwrap_or_else(|| panic!("CODE {id} missing from the bundle"))
}

fn body<'a>(b: &'a Bundle, id: usize) -> &'a [Instruction] {
    &code(b, id).instructions
}

fn cst(x: &Instruction) -> Option<f64> {
    match x.op { Op::Constant { value } => Some(value), _ => None }
}

fn gload(x: &Instruction) -> Option<&str> {
    match &x.op { Op::Load { name, selector: -5, .. } => Some(name.as_str()), _ => None }
}

fn gstore(x: &Instruction) -> Option<&str> {
    match &x.op { Op::Store { name, selector: -5, array: false, .. } => Some(name.as_str()), _ => None }
}

fn store_parts(x: &Instruction) -> Option<(&str, i32, bool)> {
    match &x.op { Op::Store { name, selector, array, .. } => Some((name.as_str(), *selector, *array)), _ => None }
}

fn load_parts(x: &Instruction) -> Option<(&str, i32)> {
    match &x.op { Op::Load { name, selector, .. } => Some((name.as_str(), *selector)), _ => None }
}

fn cpof(x: &Instruction) -> Option<u8> {
    match x.op { Op::Cmp { comparison } => Some(comparison), _ => None }
}

fn bfof(x: &Instruction) -> Option<usize> {
    match x.op { Op::Bf { target } => Some(target), _ => None }
}

fn bof(x: &Instruction) -> Option<usize> {
    match x.op { Op::B { target } => Some(target), _ => None }
}

fn callof(x: &Instruction) -> Option<(&str, usize)> {
    match &x.op { Op::Call { name, argc } => Some((name.as_str(), *argc)), _ => None }
}

fn nxt(body: &[Instruction], i: usize) -> Option<usize> {
    body.get(i).map(|x| x.offset)
}

fn branch_census(b: &Bundle, id: usize) -> (usize, usize, usize) {
    let mut bf = 0;
    let mut bt = 0;
    let mut bj = 0;
    for x in body(b, id) {
        match x.op {
            Op::Bf { .. } => bf += 1,
            Op::Bt { .. } => bt += 1,
            Op::B { .. } => bj += 1,
            _ => {}
        }
    }
    (bf, bt, bj)
}

fn all_stores(b: &Bundle, id: usize) -> BTreeSet<usize> {
    body(b, id).iter().filter(|x| matches!(x.op, Op::Store { .. })).map(|x| x.code_offset).collect()
}

/// Every store code_offset the VM actually executed for one CODE, in order.
fn ran_stores(s: &Scene, id: usize, start: usize, stores: &BTreeSet<usize>) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(c, _)| *c == id)
        .map(|(_, o)| o - start)
        .filter(|o| stores.contains(o))
        .collect()
}

/// The complete execution ledger of one CODE, as code_offsets in order.
fn ran_all(s: &Scene, id: usize, start: usize) -> Vec<usize> {
    s.executed.iter().filter(|(c, _)| *c == id).map(|(_, o)| o - start).collect()
}

// ---- CODE 367 derivation ---------------------------------------------------

#[derive(Debug, Clone, PartialEq)]
struct Fam {
    level: String,
    damage: String,
    /// (level constant, damage constant, damage-store code_offset) in order.
    arms: Vec<(f64, f64, usize)>,
    cap_store: usize,
    cap_bf: usize,
}

struct A1 {
    fams: Vec<Fam>,
    /// The trailing `alarm[1] = 30`, as (store code_offset, slot, value).
    rearm: (usize, f64, f64),
}

fn derive_alarm1(b: &Bundle) -> Result<A1, String> {
    let body = body(b, CODE_ALARM1);
    let mut fams: Vec<Fam> = Vec::new();
    let mut i = 0usize;
    let mut rearm: Option<(usize, f64, f64)> = None;
    while i < body.len() {
        if i + 4 <= body.len() {
            let addr_tail = cst(&body[i]) == Some(REARM)
                && cst(&body[i + 1]) == Some(-1.0)
                && body.get(i + 3).and_then(store_parts).is_some_and(|(n, _, arr)| n == "alarm" && arr);
            if addr_tail {
                let slot = cst(&body[i + 2]).ok_or("CODE 367 alarm slot is not a constant")?;
                rearm = Some((body[i + 3].code_offset, slot, REARM));
                i += 4;
                continue;
            }
        }
        if i + 6 > body.len() {
            return Err(format!("CODE 367 [{i}]: truncated block"));
        }
        let level = gload(&body[i])
            .ok_or_else(|| format!("CODE 367 [{i}]: expected a global load, got {:?}", body[i].op))?
            .to_string();
        let tier = cst(&body[i + 1]).ok_or_else(|| format!("CODE 367 [{i}]: tier is not a constant"))?;
        let cmp = cpof(&body[i + 2]).ok_or_else(|| format!("CODE 367 [{i}]: expected cmp"))?;
        let target = bfof(&body[i + 3]).ok_or_else(|| format!("CODE 367 [{i}]: expected bf"))?;
        if nxt(body, i + 6) != Some(target) {
            return Err(format!(
                "CODE 367 [{i}] {} cmp {tier}: bf target {target} is not the block's fall-through {:?}",
                level,
                nxt(body, i + 6)
            ));
        }
        match cmp {
            3 => {
                let value = cst(&body[i + 4]).ok_or_else(|| format!("CODE 367 [{i}]: arm value not a constant"))?;
                let damage = gstore(&body[i + 5])
                    .ok_or_else(|| format!("CODE 367 [{i}]: arm does not store a global"))?
                    .to_string();
                if fams.last().map_or(true, |f: &Fam| f.level != level) {
                    if fams.iter().any(|f| f.level == level) {
                        return Err(format!("CODE 367: family {level} appears twice"));
                    }
                    fams.push(Fam {
                        level: level.clone(),
                        damage: damage.clone(),
                        arms: Vec::new(),
                        cap_store: 0,
                        cap_bf: 0,
                    });
                }
                let f = fams.last_mut().unwrap();
                if f.damage != damage {
                    return Err(format!("CODE 367 {level}: arm stores {damage}, family started with {}", f.damage));
                }
                if !f.arms.is_empty() && f.arms.last().unwrap().0 >= tier {
                    return Err(format!("CODE 367 {level}: arm tiers are not strictly ascending at {tier}"));
                }
                f.arms.push((tier, value, body[i + 5].code_offset));
            }
            6 => {
                let value = cst(&body[i + 4]).ok_or_else(|| format!("CODE 367 [{i}]: ceiling value not a constant"))?;
                let name = gstore(&body[i + 5])
                    .ok_or_else(|| format!("CODE 367 [{i}]: ceiling does not store a global"))?;
                let f = fams.last_mut().ok_or("CODE 367: ceiling arm before any family")?;
                if name != f.level {
                    return Err(format!("CODE 367 {level}: ceiling stores {name} instead of the level"));
                }
                if value != 10.0 || tier != 10.0 {
                    return Err(format!("CODE 367 {level}: ceiling is not `> 10 -> 10` (cmp {tier}, store {value})"));
                }
                if f.cap_store != 0 {
                    return Err(format!("CODE 367 {level}: two ceiling arms"));
                }
                f.cap_store = body[i + 5].code_offset;
                f.cap_bf = body[i + 3].code_offset;
            }
            other => return Err(format!("CODE 367 [{i}]: unsupported comparison {other}")),
        }
        i += 6;
    }
    if i != body.len() {
        return Err(format!("CODE 367: {} trailing instructions after the table", body.len() - i));
    }
    let rearm = rearm.ok_or("CODE 367: no trailing alarm re-arm")?;
    if rearm.1 != 1.0 {
        return Err(format!("CODE 367: re-arms alarm slot {} instead of slot 1", rearm.1));
    }
    Ok(A1 { fams, rearm })
}

/// Derive CODE 367 from the live bundle and require it to reproduce the
/// embedded table exactly (families, values, store offsets, ceilings).
fn validate_alarm1(b: &Bundle) -> Result<A1, String> {
    let a1 = derive_alarm1(b)?;
    if a1.fams.len() != DAMAGE.len() {
        return Err(format!("CODE 367 ships {} families, the table says {}", a1.fams.len(), DAMAGE.len()));
    }
    for (k, f) in a1.fams.iter().enumerate() {
        let (level, damage, values, stores, cap_store, cap_bf) = &DAMAGE[k];
        if f.level != *level || f.damage != *damage {
            return Err(format!(
                "CODE 367 family {k}: bytecode {}/{} but the table says {level}/{damage}",
                f.level, f.damage
            ));
        }
        if f.damage != f.level.replace("level", "damage") {
            return Err(format!("CODE 367 {}: damage global {} is not the level's damage name", f.level, f.damage));
        }
        if f.arms.len() != values.len() {
            return Err(format!("CODE 367 {level}: {} arms, the table has {}", f.arms.len(), values.len()));
        }
        for (n, (tier, value, off)) in f.arms.iter().enumerate() {
            let want_tier = (n + 1) as f64;
            if *tier != want_tier {
                return Err(format!("CODE 367 {level}: arm {n} tests {tier}, expected {want_tier}"));
            }
            if *value != values[n] {
                return Err(format!(
                    "CODE 367 {level} arm {n}: bytecode stores {value}, the table says {}",
                    values[n]
                ));
            }
            if *off != stores[n] {
                return Err(format!(
                    "CODE 367 {level} arm {n}: store at code_offset {off}, the table says {}",
                    stores[n]
                ));
            }
        }
        if f.cap_store != *cap_store || f.cap_bf != *cap_bf {
            return Err(format!(
                "CODE 367 {level}: ceiling at {} (bf {}) but the table says {cap_store} (bf {cap_bf})",
                f.cap_store, f.cap_bf
            ));
        }
    }
    let (bf, bt, bj) = branch_census(b, CODE_ALARM1);
    let want_bf = a1.fams.iter().map(|f| f.arms.len() + 1).sum::<usize>();
    if bf != want_bf || bt != 0 || bj != 0 {
        return Err(format!("CODE 367 branch census: {bf} bf / {bt} bt / {bj} b, expected {want_bf} / 0 / 0"));
    }
    let stores = all_stores(b, CODE_ALARM1);
    let want_stores = a1.fams.iter().map(|f| f.arms.len() + 1).sum::<usize>() + 1;
    if stores.len() != want_stores {
        return Err(format!("CODE 367 has {} store sites, expected {want_stores}", stores.len()));
    }
    Ok(a1)
}

// ---- CODE 368 derivation ---------------------------------------------------

#[derive(Debug, Clone, PartialEq)]
struct XpBlock {
    xp: String,
    level: String,
    /// First instruction (the xp load) and the exclusive end of this block.
    start: usize,
    end: usize,
    /// Stores skipped by the `level < 10` guard.
    guarded: Vec<(String, usize)>,
}

#[derive(Debug, Clone, PartialEq)]
struct BannerArm {
    level: String,
    tier: f64,
    flag: String,
    set_store: usize,
    clear_store: usize,
}

#[derive(Debug, Clone, PartialEq)]
struct Spawn {
    obj: f64,
    /// x = source.x + dx (dx may be negative), y = source.y + dy.
    dx: f64,
    dy: f64,
    /// Instance selector the x/y are read from (-1 = self, 0 = obj_player).
    source: i32,
    /// code_offset of the `instance_create` call.
    call: usize,
}

struct A0 {
    xp: Vec<XpBlock>,
    banner: Vec<BannerArm>,
    head_flag: String,
    head_spawn: Spawn,
    levelup_spawn: Spawn,
    change_spawn: Spawn,
    /// `level >= 20 -> level = 20` constant, read from the tail clamp.
    level_cap: f64,
    /// `xptolevelup * 1.12` multiplier.
    xp_growth: f64,
    /// `experience = 1` reset value.
    xp_reset: f64,
    final_reset_store: usize,
    rearm: (usize, f64, f64),
    choose: Vec<(Vec<f64>, String)>,
    /// Stores of the banner region, i.e. everything from the first banner arm
    /// to the tail consumer.
    banner_start: usize,
}

fn derive_spawn(body: &[Instruction], i: usize, want_obj: f64) -> Result<Spawn, String> {
    // constant obj; cast 5; [load y[sel]; [constant dy; add]]; [load x[sel]; [constant dx; sub]]; call
    // The zero-offset form (`instance_create(x, y, obj)`) omits the add/sub pair.
    let obj = cst(&body[i]).ok_or_else(|| format!("spawn [{i}]: object is not a constant"))?;
    if obj != want_obj {
        return Err(format!("spawn [{i}]: creates object {obj}, expected {want_obj}"));
    }
    if !matches!(body[i + 1].op, Op::Cast { to: 5 }) {
        return Err(format!("spawn [{i}]: expected cast-to-instance after the object id"));
    }
    let mut k = i + 2;
    let (y_name, y_sel) = load_parts(&body[k]).ok_or_else(|| format!("spawn [{i}]: y is not a load"))?;
    if y_name != "y" {
        return Err(format!("spawn [{i}]: expected the y load, found {y_name}"));
    }
    let mut dy = 0.0;
    if let Some(v) = cst(&body[k + 1]) {
        // `y + K` and `y - K` both occur in this body (the weapon banner adds,
        // the levelup overlay subtracts), so the offset is signed.
        dy = match body[k + 2].op {
            Op::Add => v,
            Op::Sub => -v,
            _ => return Err(format!("spawn [{i}]: `y +/- dy` has no add/sub")),
        };
        k += 2;
    }
    k += 1;
    let (x_name, x_sel) = load_parts(&body[k]).ok_or_else(|| format!("spawn [{i}]: x is not a load"))?;
    if x_name != "x" {
        return Err(format!("spawn [{i}]: expected the x load, found {x_name}"));
    }
    let mut dx = 0.0;
    if let Some(v) = cst(&body[k + 1]) {
        dx = match body[k + 2].op {
            Op::Add => v,
            Op::Sub => -v,
            _ => return Err(format!("spawn [{i}]: `x +/- dx` has no add/sub")),
        };
        k += 2;
    }
    k += 1;
    if x_sel != y_sel {
        return Err(format!("spawn [{i}]: x selector {x_sel} != y selector {y_sel}"));
    }
    let (name, argc) = callof(&body[k]).ok_or_else(|| format!("spawn [{i}]: no instance_create"))?;
    if name != "instance_create" || argc != 3 {
        return Err(format!("spawn [{i}]: expected instance_create/3, got {name}/{argc}"));
    }
    Ok(Spawn { obj, dx, dy, source: x_sel, call: body[k].code_offset })
}

fn derive_alarm0(b: &Bundle) -> Result<A0, String> {
    let body = body(b, CODE_ALARM0);
    if body.len() < 70 {
        return Err("CODE 368 is shorter than its fixed prologue".into());
    }

    // --- head: consume drawweaponlevelup, spawn the weapon banner -----------
    let head_flag = gload(&body[0]).ok_or("CODE 368 [0]: expected the drawweaponlevelup load")?.to_string();
    if cst(&body[1]) != Some(1.0) || cpof(&body[2]) != Some(3) {
        return Err("CODE 368 [1..2]: expected `flag == 1`".into());
    }
    // The guard encloses BOTH the latch clear and the spawn: the bf jumps past
    // the spawn call's popz, not to the spawn's first instruction. (The WIP
    // file asserted the latter; the bytecode at code_offset 16 targets 84.)
    let head_end = (4..body.len())
        .find(|&j| matches!(body[j].op, Op::Popz))
        .ok_or("CODE 368: the head block has no closing popz")?;
    let head_next = body.get(head_end + 1).ok_or("CODE 368: the head block ends the body")?;
    if bfof(&body[3]) != Some(head_next.offset) {
        return Err(format!(
            "CODE 368 [3]: the flag guard jumps to {:?}, expected {} (after the head popz)",
            bfof(&body[3]),
            head_next.offset
        ));
    }
    if cst(&body[4]) != Some(0.0) || gstore(&body[5]) != Some(head_flag.as_str()) {
        return Err("CODE 368 [4..5]: expected the flag to be cleared before the spawn".into());
    }
    let head_spawn = derive_spawn(body, 6, HEAD_SPAWN.0)?;

    // --- player level block -------------------------------------------------
    if !matches!(body[15].op, Op::Popz) {
        return Err("CODE 368 [15]: expected the popz that closes the head block".into());
    }
    let exp = gload(&body[16]).ok_or("CODE 368 [16]: expected the experience load")?.to_string();
    let thr = gload(&body[17]).ok_or("CODE 368 [17]: expected the xptolevelup load")?.to_string();
    if cpof(&body[18]) != Some(5) || bfof(&body[19]).is_none() {
        return Err("CODE 368 [18..19]: expected `experience >= xptolevelup`".into());
    }
    if gload(&body[20]) != Some("level") || cpof(&body[22]) != Some(2) {
        return Err("CODE 368 [20..22]: expected `level <= 20`".into());
    }
    let level_cap = cst(&body[21]).ok_or("CODE 368 [21]: level ceiling is not a constant")?;
    let xp_reset = cst(&body[24]).ok_or("CODE 368 [24]: experience reset is not a constant")?;
    if gstore(&body[25]) != Some(exp.as_str()) || !matches!(body[28].op, Op::Add) {
        return Err("CODE 368 [25..28]: expected the experience reset and the level increment".into());
    }
    let xp_growth = cst(&body[31]).ok_or("CODE 368 [31]: xp growth is not a constant")?;
    if !matches!(body[32].op, Op::Mul) || gstore(&body[33]) != Some(thr.as_str()) {
        return Err("CODE 368 [32..33]: expected the threshold multiplication".into());
    }
    if gstore(&body[35]) != Some("drawlevelup") || cst(&body[34]) != Some(1.0) {
        return Err("CODE 368 [34..35]: expected the drawlevelup latch to be raised".into());
    }
    if gload(&body[36]) != Some("drawlevelup") || cpof(&body[38]) != Some(3) {
        return Err("CODE 368 [36..38]: expected the drawlevelup branch".into());
    }
    if gload(&body[40]) != Some("level") || cpof(&body[42]) != Some(2) || cst(&body[41]) != Some(level_cap) {
        return Err("CODE 368 [40..42]: the overlay's inner `level <= 20` does not match the ceiling".into());
    }
    let levelup_spawn = derive_spawn(body, 44, LEVELUP_SPAWN.0)?;
    if !matches!(body[53].op, Op::Popz) || cst(&body[54]) != Some(0.0) || gstore(&body[55]) != Some("drawlevelup")
    {
        return Err("CODE 368 [53..55]: expected the unconditional drawlevelup clear".into());
    }
    if gload(&body[56]) != Some("level") || cpof(&body[58]) != Some(5) || cst(&body[57]) != Some(level_cap)
    {
        return Err("CODE 368 [56..58]: expected the trailing `level >= 20` clamp test".into());
    }
    if cst(&body[60]) != Some(level_cap) || gstore(&body[61]) != Some("level") {
        return Err("CODE 368 [60..61]: expected the clamp store".into());
    }

    // --- the two choose() sites --------------------------------------------
    let mut choose: Vec<(Vec<f64>, String)> = Vec::new();
    for (i, ins) in body.iter().enumerate() {
        if callof(ins) == Some(("choose", 2)) {
            let a = cst(&body[i - 4]).ok_or("choose: first candidate is not a constant")?;
            let c = cst(&body[i - 2]).ok_or("choose: second candidate is not a constant")?;
            if !matches!(body[i - 1].op, Op::Cast { to: 5 }) || !matches!(body[i - 3].op, Op::Cast { to: 5 }) {
                return Err("choose: candidates are not cast to integers".into());
            }
            let dst = gstore(&body[i + 1]).ok_or("choose: result is not stored to a global")?.to_string();
            let mut pair = vec![a, c];
            pair.sort_by(|x, y| x.partial_cmp(y).unwrap());
            choose.push((pair, dst));
        }
    }

    // --- the 12 XP blocks ---------------------------------------------------
    let mut xp: Vec<XpBlock> = Vec::new();
    // Start at the first `load <weapon>xp; load <weapon>xptolevelup` pair. The
    // head, the player block, the two choose() sites and the mid-body re-arm all
    // sit in front of it; the WIP file hardcoded 62, which is the `constant 20`
    // feeding the coinsound cast, so it derived zero XP blocks.
    let mut i = (0..body.len().saturating_sub(1))
        .find(|&k| match gload(&body[k]) {
            Some(n) if n.ends_with("xp") => {
                let want = format!("{n}tolevelup");
                gload(&body[k + 1]) == Some(want.as_str())
            }
            _ => false,
        })
        .ok_or("CODE 368: no `xp` / `xptolevelup` pair")?;
    while i < body.len() {
        let Some(name) = gload(&body[i]) else { break };
        if !name.ends_with("xp") || !matches!(body.get(i + 1).and_then(gload), Some(t) if t == format!("{name}tolevelup"))
        {
            break;
        }
        if cpof(&body[i + 2]) != Some(5) {
            return Err(format!("CODE 368 [{i}] {name}: expected `xp >= xptolevelup`"));
        }
        let block_end = bfof(&body[i + 3]).ok_or_else(|| format!("CODE 368 [{i}] {name}: expected bf"))?;
        let level = gload(&body[i + 4]).ok_or_else(|| format!("CODE 368 [{i}] {name}: expected the level load"))?.to_string();
        if cst(&body[i + 5]) != Some(10.0) || cpof(&body[i + 6]) != Some(1) {
            return Err(format!("CODE 368 [{i}] {name}: expected `{level} < 10`"));
        }
        // The `level < 10` guard closes before the level increment, so the
        // guarded stores run only up to the SECOND bf. The pistol is the one
        // block where the two differ (1 guarded store vs 4), which is exactly
        // the shipped quirk this table pins.
        let guard_end = bfof(&body[i + 7]).ok_or_else(|| format!("CODE 368 [{i}] {name}: the guard has no bf"))?;
        let mut guarded = Vec::new();
        let mut j = i + 8;
        while nxt(body, j) != Some(guard_end) {
            if let Some((n, _, _)) = store_parts(&body[j]) {
                guarded.push((n.to_string(), body[j].code_offset));
            }
            j += 1;
            if j >= body.len() {
                return Err(format!("CODE 368 [{i}] {name}: the guard target is not in this body"));
            }
        }
        // Advance to the end of the whole block so the next iteration lands on
        // the following XP block.
        while nxt(body, j) != Some(block_end) {
            j += 1;
            if j >= body.len() {
                return Err(format!("CODE 368 [{i}] {name}: the block target is not in this body"));
            }
        }
        xp.push(XpBlock { xp: name.to_string(), level, start: body[i].code_offset, end: 0, guarded });
        i = j;
    }

    // --- the 36 banner arms -------------------------------------------------
    let mut banner: Vec<BannerArm> = Vec::new();
    let banner_start = body.get(i).map(|x| x.code_offset).ok_or("CODE 368: no banner region")?;
    while i < body.len() {
        let Some(level) = gload(&body[i]) else { break };
        if !level.ends_with("level") {
            break;
        }
        let tier = match cst(&body[i + 1]) {
            Some(t) => t,
            None => break,
        };
        if cpof(&body[i + 2]) != Some(3) || bfof(&body[i + 3]).is_none() {
            return Err(format!("CODE 368 [{i}] {level} == {tier}: expected an equality guard"));
        }
        let flag = gload(&body[i + 4]).ok_or_else(|| format!("CODE 368 [{i}]: the banner arm has no latch load"))?.to_string();
        if !flag.starts_with("drawchange") || cst(&body[i + 5]) != Some(1.0) || cpof(&body[i + 6]) != Some(3) {
            return Err(format!("CODE 368 [{i}] {flag}: expected `drawchange... == 1`"));
        }
        // The `&&` short-circuit: an unconditional b jumps over the `constant 0`.
        let short = bof(&body[i + 7]).ok_or_else(|| format!("CODE 368 [{i}] {flag}: expected the && short-circuit b"))?;
        if cst(&body[i + 8]) != Some(0.0) || short != body[i + 9].offset {
            return Err(format!("CODE 368 [{i}] {flag}: the short-circuit target is not the value test"));
        }
        if bfof(&body[i + 9]).is_none() {
            return Err(format!("CODE 368 [{i}] {flag}: the && result has no bf"));
        }
        if gstore(&body[i + 11]) != Some("drawweaponchange") || cst(&body[i + 10]) != Some(1.0) {
            return Err(format!("CODE 368 [{i}] {flag}: expected `drawweaponchange = 1`"));
        }
        if gstore(&body[i + 13]) != Some(flag.as_str()) || cst(&body[i + 12]) != Some(0.0) {
            return Err(format!("CODE 368 [{i}] {flag}: expected the latch to be cleared"));
        }
        let want_flag = format!("drawchange{}{}", level.strip_suffix("level").unwrap(), tier as i64);
        if flag != want_flag {
            return Err(format!("CODE 368 [{i}]: {level} tier {tier} toggles {flag}, expected {want_flag}"));
        }
        banner.push(BannerArm {
            level: level.to_string(),
            tier,
            flag,
            set_store: body[i + 11].code_offset,
            clear_store: body[i + 13].code_offset,
        });
        i += 14;
    }
    for k in 0..xp.len() {
        let next = if k + 1 < xp.len() {
            xp[k + 1].start
        } else {
            banner_start
        };
        xp[k].end = next;
    }

    // --- tail: the drawweaponchange consumer --------------------------------
    let n = body.len();
    if !matches!(body[n - 1].op, Op::Popz) {
        return Err("CODE 368: the body does not end on popz".into());
    }
    if gload(&body[n - 12]) != Some("drawweaponchange") || cpof(&body[n - 10]) != Some(3) || bfof(&body[n - 9]).is_none()
    {
        return Err("CODE 368 tail: expected the `drawweaponchange == 1` consumer".into());
    }
    if cst(&body[n - 8]) != Some(0.0) || gstore(&body[n - 7]) != Some("drawweaponchange") {
        return Err("CODE 368 tail: expected the latch to be cleared before the spawn".into());
    }
    let change_spawn = derive_spawn(body, n - 6, CHANGE_SPAWN.0)?;

    // --- the mid-body alarm re-arm -----------------------------------------
    let mut rearm: Option<(usize, f64, f64)> = None;
    for (k, ins) in body.iter().enumerate() {
        if k + 3 >= body.len() {
            break;
        }
        if cst(ins) == Some(REARM) && cst(&body[k + 1]) == Some(-1.0)
            && body.get(k + 3).and_then(store_parts).is_some_and(|(n2, _, arr)| n2 == "alarm" && arr)
        {
            let slot = cst(&body[k + 2]).ok_or("CODE 368: alarm slot is not a constant")?;
            rearm = Some((body[k + 3].code_offset, slot, REARM));
            break;
        }
    }
    let rearm = rearm.ok_or("CODE 368: no alarm[0] re-arm")?;
    if rearm.1 != 0.0 {
        return Err(format!("CODE 368: re-arms alarm slot {} instead of slot 0", rearm.1));
    }

    Ok(A0 {
        xp,
        banner,
        head_flag,
        head_spawn,
        levelup_spawn,
        change_spawn,
        level_cap,
        xp_growth,
        xp_reset,
        final_reset_store: body[n - 3].code_offset,
        rearm,
        choose,
        banner_start,
    })
}

/// Derive CODE 368 from the live bundle and require it to reproduce the
/// embedded XP and banner tables exactly.
fn validate_alarm0(b: &Bundle) -> Result<A0, String> {
    let a0 = derive_alarm0(b)?;
    if a0.xp.len() != XP.len() {
        return Err(format!("CODE 368 ships {} XP blocks, the table says {}", a0.xp.len(), XP.len()));
    }
    for (k, blk) in a0.xp.iter().enumerate() {
        let (xp_name, level_name, guarded_names, guarded_offsets) = &XP[k];
        if blk.xp != *xp_name || blk.level != *level_name {
            return Err(format!(
                "CODE 368 XP block {k}: bytecode {}/{} but the table says {xp_name}/{level_name}",
                blk.xp, blk.level
            ));
        }
        let got: Vec<&str> = blk.guarded.iter().map(|(n, _)| n.as_str()).collect();
        if got != *guarded_names {
            return Err(format!("CODE 368 {xp_name}: guarded stores {got:?}, the table says {guarded_names:?}"));
        }
        let offs: Vec<usize> = blk.guarded.iter().map(|(_, o)| *o).collect();
        if offs != *guarded_offsets {
            return Err(format!("CODE 368 {xp_name}: guarded offsets {offs:?}, the table says {guarded_offsets:?}"));
        }
    }
    if a0.banner.len() != BANNER.len() {
        return Err(format!("CODE 368 ships {} banner arms, the table says {}", a0.banner.len(), BANNER.len()));
    }
    for (k, arm) in a0.banner.iter().enumerate() {
        let (level, tier, flag, set_store, clear_store) = &BANNER[k];
        if arm.level != *level || arm.tier != *tier || arm.flag != *flag {
            return Err(format!(
                "CODE 368 banner {k}: bytecode {}/{}/{} but the table says {level}/{tier}/{flag}",
                arm.level, arm.tier, arm.flag
            ));
        }
        if arm.set_store != *set_store || arm.clear_store != *clear_store {
            return Err(format!(
                "CODE 368 banner {k} {flag}: stores at {}/{} but the table says {set_store}/{clear_store}",
                arm.set_store, arm.clear_store
            ));
        }
    }
    if a0.head_flag != "drawweaponlevelup" {
        return Err(format!("CODE 368 consumes {} at the top, expected drawweaponlevelup", a0.head_flag));
    }
    let want = |s: &Spawn, e: (f64, f64, f64, i32), what: &str| -> Result<(), String> {
        if (s.obj, s.dx, s.dy, s.source) != e {
            return Err(format!(
                "{what} spawn is {:?} but the table says {e:?}",
                (s.obj, s.dx, s.dy, s.source)
            ));
        }
        Ok(())
    };
    want(&a0.head_spawn, HEAD_SPAWN, "obj_weaponlevelup")?;
    want(&a0.levelup_spawn, LEVELUP_SPAWN, "obj_levelup")?;
    want(&a0.change_spawn, CHANGE_SPAWN, "obj_weaponchange")?;
    if a0.level_cap != 20.0 || a0.xp_growth != 1.12 || a0.xp_reset != 1.0 {
        return Err(format!(
            "CODE 368 player block: cap {} growth {} reset {}, expected 20 / 1.12 / 1",
            a0.level_cap, a0.xp_growth, a0.xp_reset
        ));
    }
    let want_choose: [(Vec<f64>, &str); 2] = [(vec![19.0, 20.0], "coinsound"), (vec![13.0, 14.0], "swordsound")];
    if a0.choose.len() != 2 {
        return Err(format!("CODE 368 has {} choose() sites, expected 2", a0.choose.len()));
    }
    for (k, (pair, dst)) in a0.choose.iter().enumerate() {
        if *pair != want_choose[k].0 || dst != want_choose[k].1 {
            return Err(format!(
                "CODE 368 choose {k}: {pair:?} -> {dst}, expected {:?} -> {}",
                want_choose[k].0, want_choose[k].1
            ));
        }
    }
    let (bf, bt, bj) = branch_census(b, CODE_ALARM0);
    let want_bf = 1 + 2 + 2 + 1 + 2 + 11 * 2 + BANNER.len() * 2 + 1;
    let want_b = BANNER.len();
    if bf != want_bf || bt != 0 || bj != want_b {
        return Err(format!("CODE 368 branch census: {bf} bf / {bt} bt / {bj} b, expected {want_bf} / 0 / {want_b}"));
    }
    Ok(a0)
}

// ---- perturbation helpers (negative controls) ------------------------------

fn ins_index(b: &Bundle, id: usize, code_offset: usize) -> usize {
    body(b, id)
        .iter()
        .position(|x| x.code_offset == code_offset)
        .unwrap_or_else(|| panic!("CODE {id} has no instruction at code_offset {code_offset}"))
}

fn code_mut<'a>(b: &'a mut Bundle, id: usize) -> &'a mut Code {
    b.codes.iter_mut().find(|c| c.id == id).unwrap_or_else(|| panic!("CODE {id} missing"))
}

/// Rewrite the constant a given store consumes (the instruction right before
/// the store, or - for the three-constant alarm template - the value slot).
fn set_stored_value(b: &mut Bundle, id: usize, store_off: usize, value: f64) {
    let idx = ins_index(b, id, store_off);
    let code = code_mut(b, id);
    let back = if store_parts(&code.instructions[idx]).is_some_and(|(n, _, arr)| n == "alarm" && arr) { 3 } else { 1 };
    code.instructions[idx - back].op = Op::Constant { value };
}

fn set_store_name(b: &mut Bundle, id: usize, store_off: usize, name: &str) {
    let idx = ins_index(b, id, store_off);
    let code = code_mut(b, id);
    match &mut code.instructions[idx].op {
        Op::Store { name: n, .. } => *n = name.to_string(),
        other => panic!("CODE {id} @{store_off} is not a store: {other:?}"),
    }
}

fn set_bf_target(b: &mut Bundle, id: usize, code_offset: usize, target: usize) {
    let idx = ins_index(b, id, code_offset);
    let code = code_mut(b, id);
    match &mut code.instructions[idx].op {
        Op::Bf { target: t } => *t = target,
        other => panic!("CODE {id} @{code_offset} is not a bf: {other:?}"),
    }
}

fn set_b_target(b: &mut Bundle, id: usize, code_offset: usize, target: usize) {
    let idx = ins_index(b, id, code_offset);
    let code = code_mut(b, id);
    match &mut code.instructions[idx].op {
        Op::B { target: t } => *t = target,
        other => panic!("CODE {id} @{code_offset} is not a b: {other:?}"),
    }
}

fn set_constant(b: &mut Bundle, id: usize, code_offset: usize, value: f64) {
    let idx = ins_index(b, id, code_offset);
    let code = code_mut(b, id);
    code.instructions[idx].op = Op::Constant { value };
}

// ---- tests -----------------------------------------------------------------

fn count(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|i| i.object == object).count()
}

/// The multiplier CODE 368 applies to `thr` (`thr *= K`), read off the live
/// bytecode: the pistol block uses a different constant than the other 11.
fn growth(b: &Bundle, thr: &str) -> f64 {
    let body = body(b, CODE_ALARM0);
    let at = body
        .iter()
        .position(|x| gstore(x) == Some(thr))
        .unwrap_or_else(|| panic!("CODE 368 never stores {thr}"));
    for j in (0..at).rev().take(6) {
        if matches!(body[j].op, Op::Mul) {
            for k in (0..j).rev().take(4) {
                if let Some(c) = cst(&body[k]) {
                    return c;
                }
            }
        }
    }
    panic!("CODE 368 has no growth constant before the {thr} store");
}

#[test]
fn the_alarm1_body_is_the_shipped_damage_table() {
    let b = bundle();
    let a1 = validate_alarm1(&b).expect("CODE 367 must reproduce its damage table");
    assert_eq!(a1.fams.len(), 12, "one family per weapon");
    assert_eq!(a1.fams.iter().map(|f| f.arms.len()).sum::<usize>(), 120, "12 weapons x 10 tiers");
    assert!(a1.fams.iter().all(|f| f.arms.len() == 10), "every family covers tiers 1..=10");
    assert_eq!(a1.rearm.1, 1.0, "CODE 367 re-arms its own slot");
    assert_eq!(a1.rearm.2, REARM);
    assert_eq!(body(&b, CODE_ALARM1).len(), 796);
    assert_eq!(branch_census(&b, CODE_ALARM1), (132, 0, 0), "132 bf = 120 arms + 12 ceilings");
    assert_eq!(all_stores(&b, CODE_ALARM1).len(), 133, "120 damage + 12 ceiling + 1 alarm");
}

#[test]
fn the_alarm0_body_is_the_shipped_progression_table() {
    let b = bundle();
    let a0 = validate_alarm0(&b).expect("CODE 368 must reproduce its XP and banner tables");
    assert_eq!(a0.xp.len(), 12, "one XP block per weapon");
    assert_eq!(a0.banner.len(), 36, "12 weapons x tiers 4/7/10");
    assert_eq!(a0.choose.len(), 2, "coinsound and swordsound");
    assert_eq!(body(&b, CODE_ALARM0).len(), 834);
    assert_eq!(branch_census(&b, CODE_ALARM0), (103, 0, 36), "36 b = the && short-circuits");
    let tiers: Vec<f64> = a0.banner.iter().map(|arm| arm.tier).collect();
    assert!(tiers[..12].iter().all(|t| *t == 4.0), "the tier-4 block comes first");
    assert!(tiers[12..24].iter().all(|t| *t == 7.0), "then tier 7");
    assert!(tiers[24..].iter().all(|t| *t == 10.0), "then tier 10");
}

/// The validators must not be self-satisfying: every perturbation of a clone
/// has to be rejected, or the embedded tables prove nothing.
#[test]
fn perturbing_the_tables_is_rejected() {
    let base = bundle();

    let mut b = base.clone();
    set_stored_value(&mut b, CODE_ALARM1, DAMAGE[0].3[0], 42.0);
    assert!(validate_alarm1(&b).is_err(), "a rewritten damage value must be caught");

    let mut b = base.clone();
    set_stored_value(&mut b, CODE_ALARM1, DAMAGE[0].4, 9.0);
    assert!(validate_alarm1(&b).is_err(), "a ceiling that is not `> 10 -> 10` must be caught");

    let mut b = base.clone();
    set_bf_target(&mut b, CODE_ALARM1, DAMAGE[0].5, 0);
    assert!(validate_alarm1(&b).is_err(), "an arm that stops falling through must be caught");

    let mut b = base.clone();
    set_store_name(&mut b, CODE_ALARM1, DAMAGE[1].3[0], DAMAGE[1].0);
    assert!(validate_alarm1(&b).is_err(), "a family storing into its level global must be caught");

    let mut b = base.clone();
    set_store_name(&mut b, CODE_ALARM0, XP[0].3[0], XP[0].1);
    assert!(validate_alarm0(&b).is_err(), "a renamed guarded store must be caught");

    let mut b = base.clone();
    let short = body(&b, CODE_ALARM0)
        .iter()
        .find(|x| matches!(x.op, Op::B { .. }))
        .expect("CODE 368 has the && short-circuits")
        .code_offset;
    set_b_target(&mut b, CODE_ALARM0, short, 0);
    assert!(validate_alarm0(&b).is_err(), "a broken && short-circuit must be caught");

    let mut b = base.clone();
    let cap_off = body(&b, CODE_ALARM0)[21].code_offset;
    set_constant(&mut b, CODE_ALARM0, cap_off, 25.0);
    assert!(validate_alarm0(&b).is_err(), "a raised player level cap must be caught");
}

#[test]
fn code_367_tiers_each_family_and_clamps_above_ten() {
    let mut f = fx(false);
    for fam in DAMAGE.iter() {
        let (level, damage, values) = (fam.0, fam.1, &fam.2);
        for (n, want) in values.iter().enumerate() {
            let lvl = (n + 1) as f64;
            set_g(&mut f.s, level, lvl);
            set_g(&mut f.s, damage, SENTINEL);
            f.s.dispatch(&f.b, f.ui, 2, 1).expect("CODE 367");
            assert_eq!(g(&f.s, damage), *want, "{level} == {lvl}");
            assert_eq!(g(&f.s, level), lvl, "{level} stays put inside the table");
        }
        // Above the table no arm runs: the level clamps and the damage keeps
        // whatever the previous dispatch stored (shipped quirk 5).
        set_g(&mut f.s, level, 11.0);
        set_g(&mut f.s, damage, SENTINEL);
        f.s.dispatch(&f.b, f.ui, 2, 1).expect("CODE 367 clamp");
        assert_eq!(g(&f.s, level), 10.0, "{level} > 10 clamps to 10");
        assert_eq!(g(&f.s, damage), SENTINEL, "{damage}: no arm matches 11");
    }
    assert_eq!(f.s.instances[&f.ui].alarms[1], REARM as i32, "the body re-armed alarm[1]");
}

#[test]
fn code_368_levels_the_player_and_spawns_the_levelup_overlay() {
    let mut f = fx(true);
    let thr0 = 80.0;
    set_g(&mut f.s, "level", 5.0);
    set_g(&mut f.s, "experience", 100.0);
    set_g(&mut f.s, "xptolevelup", thr0);
    set_g(&mut f.s, "drawlevelup", 0.0);
    let before = count(&f.s, LEVELUP);
    f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
    assert_eq!(g(&f.s, "level"), 6.0);
    assert_eq!(g(&f.s, "experience"), 1.0, "the xp reset is a constant 1");
    assert_eq!(g(&f.s, "xptolevelup"), thr0 * growth(&f.b, "xptolevelup"));
    assert_eq!(g(&f.s, "drawlevelup"), 0.0, "the latch is consumed in the same dispatch");
    assert_eq!(count(&f.s, LEVELUP), before + 1, "obj_levelup spawned at the player");

    // Below the threshold nothing happens at all.
    set_g(&mut f.s, "level", 7.0);
    set_g(&mut f.s, "experience", 10.0);
    set_g(&mut f.s, "xptolevelup", 50.0);
    f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
    assert_eq!(g(&f.s, "level"), 7.0, "experience < xptolevelup leaves the level alone");
    assert_eq!(g(&f.s, "experience"), 10.0);

    // 20 -> 21 -> clamped back to 20, and no overlay: the inner `level <= 20`
    // is read when the level is already 21 (shipped quirk 4).
    set_g(&mut f.s, "level", 20.0);
    set_g(&mut f.s, "experience", 999.0);
    set_g(&mut f.s, "xptolevelup", 1.0);
    set_g(&mut f.s, "drawlevelup", 0.0);
    let before = count(&f.s, LEVELUP);
    f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
    assert_eq!(g(&f.s, "level"), 20.0, "the trailing clamp lands on 20");
    assert_eq!(count(&f.s, LEVELUP), before, "no overlay at the ceiling");
}

#[test]
fn code_368_levels_weapons_under_the_ceiling_and_the_pistol_escapes_it() {
    let mut f = fx(true);
    for flag in BANNER_FLAGS {
        set_g(&mut f.s, flag, 0.0);
    }
    set_g(&mut f.s, "drawweaponlevelup", 0.0);

    // A normal weapon: level 3 -> 4, xp reset, threshold grows.
    set_g(&mut f.s, "shotgunlevel", 3.0);
    set_g(&mut f.s, "shotgunxp", 100.0);
    set_g(&mut f.s, "shotgunxptolevelup", 50.0);
    f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
    assert_eq!(g(&f.s, "shotgunlevel"), 4.0);
    assert_eq!(g(&f.s, "shotgunxp"), 1.0);
    assert_eq!(g(&f.s, "shotgunxptolevelup"), 50.0 * growth(&f.b, "shotgunxptolevelup"));

    // At the ceiling the whole guarded arm is skipped.
    set_g(&mut f.s, "shotgunlevel", 10.0);
    set_g(&mut f.s, "shotgunxp", 100.0);
    set_g(&mut f.s, "shotgunxptolevelup", 50.0);
    f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
    assert_eq!(g(&f.s, "shotgunlevel"), 10.0, "`level < 10` is the arm's own guard");
    assert_eq!(g(&f.s, "shotgunxp"), 100.0);
    assert_eq!(g(&f.s, "shotgunxptolevelup"), 50.0);

    // The pistol guards ONLY its xp reset (shipped quirk 1).
    set_g(&mut f.s, "pistollevel", 10.0);
    set_g(&mut f.s, "pistolxp", 100.0);
    set_g(&mut f.s, "pistolxptolevelup", 50.0);
    f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
    assert_eq!(g(&f.s, "pistollevel"), 11.0, "the pistol escapes the `level < 10` guard");
    assert_eq!(g(&f.s, "pistolxp"), 100.0, "only the reset sits inside the guard");
    assert_eq!(g(&f.s, "pistolxptolevelup"), 50.0 * growth(&f.b, "pistolxptolevelup"));

    // ...and the next CODE 367 clamps it back.
    f.s.dispatch(&f.b, f.ui, 2, 1).expect("CODE 367");
    assert_eq!(g(&f.s, "pistollevel"), 10.0, "CODE 367 owns the clamp");
}

#[test]
fn code_368_banner_arms_latch_the_weaponchange_overlay_and_clear_themselves() {
    let mut f = fx(true);
    for arm in BANNER.iter() {
        let (level, tier, flag) = (arm.0, arm.1, arm.2);
        for clear in BANNER_FLAGS {
            set_g(&mut f.s, clear, 0.0);
        }
        set_g(&mut f.s, level, tier);
        set_g(&mut f.s, flag, 1.0);
        set_g(&mut f.s, "drawweaponchange", 0.0);
        let before = count(&f.s, WEAPONCHANGE);
        f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
        assert_eq!(count(&f.s, WEAPONCHANGE), before + 1, "{flag}: the tail spawns the overlay");
        assert_eq!(g(&f.s, flag), 0.0, "{flag} is a one-shot latch");
        assert_eq!(g(&f.s, "drawweaponchange"), 0.0, "the tail consumes the overlay latch");

        // Negative: the latch flag is required.
        set_g(&mut f.s, flag, 0.0);
        set_g(&mut f.s, "drawweaponchange", 0.0);
        let before = count(&f.s, WEAPONCHANGE);
        f.s.dispatch(&f.b, f.ui, 2, 0).expect("CODE 368");
        assert_eq!(count(&f.s, WEAPONCHANGE), before, "{flag} == 0 draws nothing");
        assert_eq!(g(&f.s, "drawweaponchange"), 0.0);
    }
}

/// The slots CODE 365 armed are the ones the scheduler decrements: this drives
/// the real `Scene::tick` instead of dispatching the bodies directly.
#[test]
fn the_real_alarm_slots_reach_both_bodies_on_a_tick() {
    let mut f = fx(true);
    let armed: Vec<i32> = f.s.instances[&f.ui].alarms.to_vec();
    assert!(armed[0] > 0 && armed[1] > 0, "obj_UI Create armed alarm[0]/[1]: {armed:?}");
    for _ in 0..45 {
        f.s.tick(&f.b).expect("tick");
    }
    assert!(
        f.s.executed.iter().any(|(c, _)| *c == CODE_ALARM0),
        "alarm[0] dispatched CODE 368"
    );
    assert!(
        f.s.executed.iter().any(|(c, _)| *c == CODE_ALARM1),
        "alarm[1] dispatched CODE 367"
    );
}
