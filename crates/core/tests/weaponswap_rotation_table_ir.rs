//! Full else-if arm enumeration of CODE 519 (gml_Object_obj_weaponswap_Alarm_0):
//! the weapon-swap rotation ladder.
//!
//! The body is one flat ladder, bytecode-shaped
//!
//!     if (!audio_is_playing(snd_weaponswap)) audio_play_sound(snd_weaponswap, 0, false);
//!     global.weaponswapped += 1; global.weaponswapped += 1;
//!     [ arm 0 gate ] body: 12..13 constant/store pairs; b tail
//!     [ arm 1 gate ] ...
//!     [ arm 77 gate ] body: ... falls straight into the tail
//!     tail: instance_create(obj_weaponname, obj_player.x - 16, obj_player.y)
//!
//! Every arm is `vessel == 1 && <bought chain>`, where the bought chain reads
//! "every bought flag before the target is 0, the target's own is 1". Each vessel
//! group ends with an all-bought-0 arm that wraps back to pistol, and
//! `bombgun == 1` is the bare tail arm. The ladder is therefore a triangular
//! matrix: 12 + 11 + ... + 1 = 78 arms.
//!
//! This suite is the incremental step over `weaponswap_rotation_ir.rs` (which
//! samples 2 of the 12 rotations): it enumerates ALL 78 arms, each driven by the
//! one minimal purchase state that reaches it, and asserts per arm
//!   * the full 12-dimensional active vector after dispatch (exactly one 1),
//!   * the double `weaponswapped` increment and the sound gate in BOTH states,
//!   * the tail's label spawn, its position, and the weapon name CODE 462 gives it,
//!   * instruction-level proof from `Scene::executed` that only that arm's body
//!     ran, and that every earlier arm short-circuited at its first false test.
//!
//! The expected table below was extracted straight from the authoritative
//! bytecode in `crates/core/src/generated/full_ir.json` - per-arm condition
//! triples, selected weapon, store count, code_offsets - never hand transcribed
//! and never guessed from the recovered GML. Extraction (scratch, not checked
//! in): `wl54-weaponswap_gen.py`, which walks CODE 519's `bf` gates, decodes each
//! arm's `load <global>; constant v; cmp 3` chain and its constant/store body,
//! and refuses to emit when the arm/body spans do not tile the whole ladder.
//! `arm_table_matches_the_live_instruction_stream` re-checks every row against
//! the live bundle at run time, so the embedded table cannot drift from the IR.
//!
//! Fixture: obj_weaponswap (126) ships only Alarm 0 (CODE 519) and Draw 0 (CODE
//! 520) - no Create at all - so the alarm body is driven directly with
//! `dispatch(2, 0)` on a hand-placed instance, with obj_player (0) placed for the
//! tail's `obj_player.x` read. Nothing ticks, so no motion pass or alarm
//! scheduler contaminates the values read back.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Op, STRING_REF_BASE};
use callys_core::ir_scene::Scene;
use std::collections::BTreeMap;
use std::path::Path;

const SWAP: i32 = 126;
const PLAYER: i32 = 0;
const LABEL: i32 = 105;
const WEAPONS_WAP_CODE: usize = 519;
const WEAPONNAME_CODE: usize = 462;
const CODE_START: usize = 4_715_676;
const CODE_END: usize = 4_737_360;
/// First instruction of the ladder (arm 0's first condition load). Everything
/// before it is the audio gate plus the double `weaponswapped` increment.
const LADDER_START: usize = 112;
/// `call audio_play_sound` inside the prologue gate.
const AUDIO_CALL: usize = 52;
/// Post-ladder tail: `instance_create(105, obj_player.x - 16, obj_player.y)`.
const TAIL: usize = 21_640;
const TAIL_POPZ: usize = 21_680;
const SND_WEAPONS_WAP: i32 = 5;
const SENTINEL_SWAPS: f64 = 10.0;

const WEAPONS: [&str; 12] = [
    "pistol", "shotgun", "assaultrifle", "rocket", "icegun", "laser",
    "bow", "bladegun", "flamethrower", "boomerang", "spikegun", "bombgun",
];
const BOUGHT: [&str; 11] = [
    "shotgunbought", "assaultriflebought", "rocketbought", "icegunbought",
    "laserbought", "bowbought", "bladegunbought", "flamethrowerbought",
    "boomerangbought", "spikegunbought", "bombgunbought",
];

/// The weapon-name string ids obj_weaponname's Create (CODE 462) assigns, in its
/// `if`-chain order. Re-read from the live IR by
/// `weaponname_label_map_matches_code_462`.
const LABEL_STR: [(&str, usize); 12] = [
    ("pistol", 843),
    ("shotgun", 844),
    ("boomerang", 845),
    ("spikegun", 846),
    ("assaultrifle", 847),
    ("rocket", 848),
    ("bladegun", 849),
    ("flamethrower", 850),
    ("bow", 851),
    ("bombgun", 852),
    ("laser", 853),
    ("icegun", 854),
];

struct Arm {
    /// Ordered `load <global>; constant v; cmp 3 (==)` test chain.
    cond: &'static [(&'static str, i32)],
    /// The one weapon the body leaves at 1.
    sel: &'static str,
    /// Number of store instructions in the body: 12 in the pistol group, 13 in
    /// every other group (those arms store `shotgun` twice).
    stores: u8,
    /// code_offset of the arm's first condition load.
    chain: usize,
    /// code_offset of the shared true/false gate `bf`.
    gate: usize,
    /// code_offset of the arm's first body instruction.
    body: usize,
    /// Instruction count of the body, terminator (`b tail`) included.
    len: usize,
}

/// The 78-arm else-if ladder of CODE 519, extracted verbatim from
/// `crates/core/src/generated/full_ir.json` (never hand transcribed): one row per
/// `bf` gate whose fallthrough body writes the rotated vector. `cond` is the
/// ordered `load <global>; constant v; cmp 3 (==)` test chain, `sel` the weapon the
/// body leaves at 1, `stores` the number of store instructions in the body (12 for
/// the pistol group, 13 for every other group - those re-store `shotgun` twice),
/// `chain`/`gate`/`body` code_offsets and `len` the body's instruction count.
#[rustfmt::skip]
const ARMS: [Arm; 78] = [
    // ---- ladder group: pistol active (arms 0..=11) ----
    Arm { cond: &[("pistol", 1), ("shotgunbought", 1)], sel: "shotgun", stores: 12, chain: 112, gate: 156, body: 160, len: 25 }, // arm 0
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 1)], sel: "assaultrifle", stores: 12, chain: 308, gate: 372, body: 376, len: 25 }, // arm 1
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 1)], sel: "rocket", stores: 12, chain: 524, gate: 608, body: 612, len: 25 }, // arm 2
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 1)], sel: "icegun", stores: 12, chain: 760, gate: 864, body: 868, len: 25 }, // arm 3
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 1)], sel: "laser", stores: 12, chain: 1016, gate: 1140, body: 1144, len: 25 }, // arm 4
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 1)], sel: "bow", stores: 12, chain: 1292, gate: 1436, body: 1440, len: 25 }, // arm 5
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 1)], sel: "bladegun", stores: 12, chain: 1588, gate: 1752, body: 1756, len: 25 }, // arm 6
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 12, chain: 1904, gate: 2088, body: 2092, len: 25 }, // arm 7
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 12, chain: 2240, gate: 2444, body: 2448, len: 25 }, // arm 8
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 12, chain: 2596, gate: 2820, body: 2824, len: 25 }, // arm 9
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 12, chain: 2972, gate: 3216, body: 3220, len: 25 }, // arm 10
    Arm { cond: &[("pistol", 1), ("shotgunbought", 0), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 12, chain: 3368, gate: 3612, body: 3616, len: 25 }, // arm 11

    // ---- ladder group: shotgun active (arms 12..=22) ----
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 1)], sel: "assaultrifle", stores: 13, chain: 3764, gate: 3808, body: 3812, len: 27 }, // arm 12
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 1)], sel: "rocket", stores: 13, chain: 3972, gate: 4036, body: 4040, len: 27 }, // arm 13
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 1)], sel: "icegun", stores: 13, chain: 4200, gate: 4284, body: 4288, len: 27 }, // arm 14
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 1)], sel: "laser", stores: 13, chain: 4448, gate: 4552, body: 4556, len: 27 }, // arm 15
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 1)], sel: "bow", stores: 13, chain: 4716, gate: 4840, body: 4844, len: 27 }, // arm 16
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 1)], sel: "bladegun", stores: 13, chain: 5004, gate: 5148, body: 5152, len: 27 }, // arm 17
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 5312, gate: 5476, body: 5480, len: 27 }, // arm 18
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 5640, gate: 5824, body: 5828, len: 27 }, // arm 19
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 5988, gate: 6192, body: 6196, len: 27 }, // arm 20
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 6356, gate: 6580, body: 6584, len: 27 }, // arm 21
    Arm { cond: &[("shotgun", 1), ("assaultriflebought", 0), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 6744, gate: 6968, body: 6972, len: 27 }, // arm 22

    // ---- ladder group: assaultrifle active (arms 23..=32) ----
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 1)], sel: "rocket", stores: 13, chain: 7132, gate: 7176, body: 7180, len: 27 }, // arm 23
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 1)], sel: "icegun", stores: 13, chain: 7340, gate: 7404, body: 7408, len: 27 }, // arm 24
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 1)], sel: "laser", stores: 13, chain: 7568, gate: 7652, body: 7656, len: 27 }, // arm 25
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 1)], sel: "bow", stores: 13, chain: 7816, gate: 7920, body: 7924, len: 27 }, // arm 26
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 1)], sel: "bladegun", stores: 13, chain: 8084, gate: 8208, body: 8212, len: 27 }, // arm 27
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 8372, gate: 8516, body: 8520, len: 27 }, // arm 28
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 8680, gate: 8844, body: 8848, len: 27 }, // arm 29
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 9008, gate: 9192, body: 9196, len: 27 }, // arm 30
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 9356, gate: 9560, body: 9564, len: 27 }, // arm 31
    Arm { cond: &[("assaultrifle", 1), ("rocketbought", 0), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0)], sel: "pistol", stores: 13, chain: 9724, gate: 9908, body: 9912, len: 27 }, // arm 32

    // ---- ladder group: rocket active (arms 33..=41) ----
    Arm { cond: &[("rocket", 1), ("icegunbought", 1)], sel: "icegun", stores: 13, chain: 10072, gate: 10116, body: 10120, len: 27 }, // arm 33
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 1)], sel: "laser", stores: 13, chain: 10280, gate: 10344, body: 10348, len: 27 }, // arm 34
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 1)], sel: "bow", stores: 13, chain: 10508, gate: 10592, body: 10596, len: 27 }, // arm 35
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 1)], sel: "bladegun", stores: 13, chain: 10756, gate: 10860, body: 10864, len: 27 }, // arm 36
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 11024, gate: 11148, body: 11152, len: 27 }, // arm 37
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 11312, gate: 11456, body: 11460, len: 27 }, // arm 38
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 11620, gate: 11784, body: 11788, len: 27 }, // arm 39
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 11948, gate: 12132, body: 12136, len: 27 }, // arm 40
    Arm { cond: &[("rocket", 1), ("icegunbought", 0), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 12296, gate: 12480, body: 12484, len: 27 }, // arm 41

    // ---- ladder group: icegun active (arms 42..=49) ----
    Arm { cond: &[("icegun", 1), ("laserbought", 1)], sel: "laser", stores: 13, chain: 12644, gate: 12688, body: 12692, len: 27 }, // arm 42
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 1)], sel: "bow", stores: 13, chain: 12852, gate: 12916, body: 12920, len: 27 }, // arm 43
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 1)], sel: "bladegun", stores: 13, chain: 13080, gate: 13164, body: 13168, len: 27 }, // arm 44
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 13328, gate: 13432, body: 13436, len: 27 }, // arm 45
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 13596, gate: 13720, body: 13724, len: 27 }, // arm 46
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 13884, gate: 14028, body: 14032, len: 27 }, // arm 47
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 14192, gate: 14356, body: 14360, len: 27 }, // arm 48
    Arm { cond: &[("icegun", 1), ("laserbought", 0), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 14520, gate: 14684, body: 14688, len: 27 }, // arm 49

    // ---- ladder group: laser active (arms 50..=56) ----
    Arm { cond: &[("laser", 1), ("bowbought", 1)], sel: "bow", stores: 13, chain: 14848, gate: 14892, body: 14896, len: 27 }, // arm 50
    Arm { cond: &[("laser", 1), ("bowbought", 0), ("bladegunbought", 1)], sel: "bladegun", stores: 13, chain: 15056, gate: 15120, body: 15124, len: 27 }, // arm 51
    Arm { cond: &[("laser", 1), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 15284, gate: 15368, body: 15372, len: 27 }, // arm 52
    Arm { cond: &[("laser", 1), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 15532, gate: 15636, body: 15640, len: 27 }, // arm 53
    Arm { cond: &[("laser", 1), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 15800, gate: 15924, body: 15928, len: 27 }, // arm 54
    Arm { cond: &[("laser", 1), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 16088, gate: 16232, body: 16236, len: 27 }, // arm 55
    Arm { cond: &[("laser", 1), ("bowbought", 0), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 16396, gate: 16540, body: 16544, len: 27 }, // arm 56

    // ---- ladder group: bow active (arms 57..=62) ----
    Arm { cond: &[("bow", 1), ("bladegunbought", 1)], sel: "bladegun", stores: 13, chain: 16704, gate: 16748, body: 16752, len: 27 }, // arm 57
    Arm { cond: &[("bow", 1), ("bladegunbought", 0), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 16912, gate: 16976, body: 16980, len: 27 }, // arm 58
    Arm { cond: &[("bow", 1), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 17140, gate: 17224, body: 17228, len: 27 }, // arm 59
    Arm { cond: &[("bow", 1), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 17388, gate: 17492, body: 17496, len: 27 }, // arm 60
    Arm { cond: &[("bow", 1), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 17656, gate: 17780, body: 17784, len: 27 }, // arm 61
    Arm { cond: &[("bow", 1), ("bladegunbought", 0), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 17944, gate: 18068, body: 18072, len: 27 }, // arm 62

    // ---- ladder group: bladegun active (arms 63..=67) ----
    Arm { cond: &[("bladegun", 1), ("flamethrowerbought", 1)], sel: "flamethrower", stores: 13, chain: 18232, gate: 18276, body: 18280, len: 27 }, // arm 63
    Arm { cond: &[("bladegun", 1), ("flamethrowerbought", 0), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 18440, gate: 18504, body: 18508, len: 27 }, // arm 64
    Arm { cond: &[("bladegun", 1), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 18668, gate: 18752, body: 18756, len: 27 }, // arm 65
    Arm { cond: &[("bladegun", 1), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 18916, gate: 19020, body: 19024, len: 27 }, // arm 66
    Arm { cond: &[("bladegun", 1), ("flamethrowerbought", 0), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 19184, gate: 19288, body: 19292, len: 27 }, // arm 67

    // ---- ladder group: flamethrower active (arms 68..=71) ----
    Arm { cond: &[("flamethrower", 1), ("boomerangbought", 1)], sel: "boomerang", stores: 13, chain: 19452, gate: 19496, body: 19500, len: 27 }, // arm 68
    Arm { cond: &[("flamethrower", 1), ("boomerangbought", 0), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 19660, gate: 19724, body: 19728, len: 27 }, // arm 69
    Arm { cond: &[("flamethrower", 1), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 19888, gate: 19972, body: 19976, len: 27 }, // arm 70
    Arm { cond: &[("flamethrower", 1), ("boomerangbought", 0), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 20136, gate: 20220, body: 20224, len: 27 }, // arm 71

    // ---- ladder group: boomerang active (arms 72..=74) ----
    Arm { cond: &[("boomerang", 1), ("spikegunbought", 1)], sel: "spikegun", stores: 13, chain: 20384, gate: 20428, body: 20432, len: 27 }, // arm 72
    Arm { cond: &[("boomerang", 1), ("spikegunbought", 0), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 20592, gate: 20656, body: 20660, len: 27 }, // arm 73
    Arm { cond: &[("boomerang", 1), ("spikegunbought", 0), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 20820, gate: 20884, body: 20888, len: 27 }, // arm 74

    // ---- ladder group: spikegun active (arms 75..=76) ----
    Arm { cond: &[("spikegun", 1), ("bombgunbought", 1)], sel: "bombgun", stores: 13, chain: 21048, gate: 21092, body: 21096, len: 27 }, // arm 75
    Arm { cond: &[("spikegun", 1), ("bombgunbought", 0)], sel: "pistol", stores: 13, chain: 21256, gate: 21300, body: 21304, len: 27 }, // arm 76

    // ---- ladder group: bombgun active (arms 77..=77) ----
    Arm { cond: &[("bombgun", 1)], sel: "pistol", stores: 13, chain: 21464, gate: 21480, body: 21484, len: 26 }, // arm 77
];

// ---- fixture ---------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn code(b: &Bundle, id: usize) -> &callys_core::code_vm::Code {
    b.codes.iter().find(|c| c.id == id).unwrap_or_else(|| panic!("CODE {id} is compiled"))
}

/// The body's instruction stream, code_offset -> op, cloned once per test so
/// decoding never depends on instruction widths.
fn ops(b: &Bundle, id: usize) -> BTreeMap<usize, Op> {
    code(b, id).instructions.iter().map(|i| (i.code_offset, i.op.clone())).collect()
}

fn op_at<'a>(m: &'a BTreeMap<usize, Op>, off: usize) -> &'a Op {
    m.get(&off).unwrap_or_else(|| panic!("no instruction @{off}"))
}

/// code_offsets of the instructions in `[from, to)`, in body order.
fn span_offsets(b: &Bundle, id: usize, from: usize, to: usize) -> Vec<usize> {
    code(b, id).instructions.iter().map(|i| i.code_offset).filter(|o| (from..to).contains(o)).collect()
}

fn g(s: &Scene, name: &str) -> f64 {
    s.globals.get(name).copied().unwrap_or(0.0)
}

fn labels(s: &Scene) -> Vec<i32> {
    s.instances.iter().filter(|(_, i)| i.object == LABEL && i.alive).map(|(id, _)| *id).collect()
}

fn fresh(b: &Bundle) -> (Scene, i32, i32) {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    let player = s.create(b, PLAYER, 300.0, 200.0).expect("obj_player places");
    let swap = s.create(b, SWAP, 40.0, 60.0).expect("obj_weaponswap places");
    (s, player, swap)
}

/// Zero every global the ladder can read, then park weaponswapped on a sentinel
/// so the double increment is proved to be `+=`, not `= 2`.
fn reset(s: &mut Scene) {
    for w in WEAPONS {
        s.globals.insert(w.into(), 0.0);
    }
    for w in BOUGHT {
        s.globals.insert(w.into(), 0.0);
    }
    s.globals.insert("weaponswapped".into(), SENTINEL_SWAPS);
}

fn seed(s: &mut Scene, cond: &[(&str, i32)]) {
    for (k, v) in cond {
        s.globals.insert((*k).into(), f64::from(*v));
    }
}

fn label_string_id(sel: &str) -> usize {
    LABEL_STR.iter().find(|(w, _)| *w == sel).map(|(_, s)| *s).expect("weapon has a label string")
}

/// The value arm `n`'s input writes for `name` (its own cond pairs, else 0).
fn input_value(winner: &[(&str, i32)], name: &str) -> f64 {
    winner.iter().find(|(k, _)| *k == name).map_or(0.0, |(_, v)| f64::from(*v))
}

/// Index of the first condition test that fails for arm `j` when arm `n`'s input
/// is seeded - the short-circuit point the ledger must show.
fn first_mismatch(j: usize, n: usize) -> usize {
    ARMS[j]
        .cond
        .iter()
        .position(|(k, v)| input_value(ARMS[n].cond, k) != f64::from(*v))
        .unwrap_or_else(|| panic!("arm {j} cannot match arm {n}'s input - the ladder is not exclusive"))
}

fn body_end(n: usize) -> usize {
    if n + 1 < ARMS.len() { ARMS[n + 1].chain } else { TAIL }
}

/// Offset of the false materializer (`constant 0`) shared by an arm's test chain,
/// when the arm has more than one test.
fn false_materializer(b: &Bundle, n: usize) -> Option<usize> {
    if ARMS[n].cond.len() == 1 {
        return None;
    }
    let span = span_offsets(b, WEAPONS_WAP_CODE, ARMS[n].chain, ARMS[n].body);
    let pos = span.iter().position(|o| *o == ARMS[n].gate).expect("gate is inside the chain");
    Some(span[pos - 1])
}

fn ledger(s: &Scene) -> Vec<usize> {
    s.executed.iter().filter(|(c, _)| *c == WEAPONS_WAP_CODE).map(|(_, o)| *o - CODE_START).collect()
}

/// Instruction-level proof that exactly arm `n`'s body ran, in full, in order.
fn assert_only_this_body(b: &Bundle, s: &Scene, n: usize) {
    let led = ledger(s);
    for (j, arm) in ARMS.iter().enumerate() {
        let end = body_end(j);
        let hits: Vec<usize> = led.iter().copied().filter(|o| (arm.body..end).contains(o)).collect();
        if j == n {
            let span = span_offsets(b, WEAPONS_WAP_CODE, arm.body, end);
            assert_eq!(hits, span,
                "arm {n}: its own body at {}..{end} must run instruction for instruction", arm.body);
        } else {
            assert!(hits.is_empty(),
                "arm {n}: arm {j}'s body at {}..{end} must not run, got {hits:?}", arm.body);
        }
    }
}

/// Instruction-level proof of the ladder's control flow for arm `n`: the winner
/// evaluates its whole condition and never takes the false materializer; every
/// earlier arm evaluates its tests up to the first false one and stops there; no
/// later arm is even tested.
fn assert_short_circuit(b: &Bundle, s: &Scene, n: usize) {
    let led = ledger(s);
    let map = ops(b, WEAPONS_WAP_CODE);
    let cmps = |hits: &[usize]| {
        hits.iter().filter(|o| matches!(op_at(&map, **o), Op::Cmp { .. })).count()
    };
    for (j, arm) in ARMS.iter().enumerate() {
        let hits: Vec<usize> =
            led.iter().copied().filter(|o| (arm.chain..arm.body).contains(o)).collect();
        if j < n {
            let fail = first_mismatch(j, n);
            assert_eq!(cmps(&hits), fail + 1,
                "arm {n}: arm {j} must stop at its first false comparison (#{fail}), executed {hits:?}");
            assert!(hits.contains(&arm.gate),
                "arm {n}: arm {j}'s gate bf @{} must be reached on the false path", arm.gate);
            if let Some(glue) = false_materializer(b, j) {
                // The failed comparison's own 0 is on the stack, so only a
                // failure of the FIRST test needs the shared `constant 0`.
                assert_eq!(hits.contains(&glue), fail == 0,
                    "arm {n}: arm {j} runs the false materializer @{glue} only when test #0 fails");
            }
        } else if j == n {
            assert_eq!(cmps(&hits), arm.cond.len(),
                "arm {n}: the winning arm evaluates all {} tests, executed {hits:?}", arm.cond.len());
            assert!(hits.contains(&arm.gate), "arm {n}: gate bf @{} must run", arm.gate);
            if let Some(glue) = false_materializer(b, n) {
                assert!(!hits.contains(&glue),
                    "arm {n}: the winning arm must not run its false materializer @{glue}");
            }
        } else {
            assert!(hits.is_empty(),
                "arm {n}: the ladder stops at its own gate - arm {j} never tested, got {hits:?}");
        }
    }
}

// ---- the embedded table against the live bytecode --------------------------

#[test]
// CODE 519
fn arm_table_matches_the_live_instruction_stream() {
    let b = bundle();
    let c = code(&b, WEAPONS_WAP_CODE);
    assert_eq!((c.start, c.end), (CODE_START, CODE_END), "CODE 519 span moved");
    assert_eq!(c.instructions.len(), 3981, "CODE 519 instruction count moved");
    let map = ops(&b, WEAPONS_WAP_CODE);

    // obj_weaponswap ships Alarm 0 alone: the body can only arrive there.
    let obj = b.objects.iter().find(|o| o.id == SWAP).expect("obj_weaponswap exists");
    assert!(obj.events.iter().all(|e| e.event_type != 0),
        "obj_weaponswap must carry no Create, got {:?}", obj.events);
    let alarm: Vec<_> = obj.events.iter().filter(|e| e.event_type == 2 && e.subtype == 0).collect();
    assert_eq!(alarm.len(), 1, "one Alarm 0");
    assert_eq!(alarm[0].codes, vec![WEAPONS_WAP_CODE], "Alarm 0 is CODE 519 and nothing else");

    assert_eq!(ARMS.len(), 78, "the ladder is the shipped triangular matrix");
    assert_eq!(ARMS[0].chain, LADDER_START, "arm 0 starts right after the prologue");
    assert_eq!(ARMS[77].gate, 21_480, "the bare bombgun arm is the last gate");
    assert_eq!(body_end(77), TAIL, "the last body falls straight into the tail");

    for (n, arm) in ARMS.iter().enumerate() {
        let end = body_end(n);

        // Gate: a bf whose fallthrough is the body.
        match op_at(&map, arm.gate) {
            Op::Bf { target } => assert_eq!(*target, CODE_START + end,
                "arm {n}: gate bf must target the next arm's chain (or the tail)"),
            other => panic!("arm {n}: gate @{} is {other:?}, not a bf", arm.gate),
        }
        let body_span = span_offsets(&b, WEAPONS_WAP_CODE, arm.body, end);
        assert_eq!(body_span.len(), arm.len, "arm {n}: embedded body length");
        assert_eq!(body_span[0], arm.gate + 4, "arm {n}: the body is the gate's fallthrough");

        // Condition: ordered (load global, constant v, cmp ==) triples.
        let chain_span = span_offsets(&b, WEAPONS_WAP_CODE, arm.chain, arm.body);
        let mut cond: Vec<(&str, i32)> = Vec::new();
        let mut glue: Vec<usize> = Vec::new();
        let mut k = 0;
        while k < chain_span.len() {
            let triple = if k + 2 < chain_span.len() {
                match (op_at(&map, chain_span[k]), op_at(&map, chain_span[k + 1]),
                       op_at(&map, chain_span[k + 2])) {
                    (Op::Load { name, selector: -5, array: false, .. },
                     Op::Constant { value },
                     Op::Cmp { comparison: 3 }) => Some((name.as_str(), *value as i32)),
                    _ => None,
                }
            } else {
                None
            };
            match triple {
                Some((name, value)) => {
                    cond.push((name, value));
                    k += 3;
                }
                None => {
                    glue.push(chain_span[k]);
                    k += 1;
                }
            }
        }
        assert_eq!(cond, arm.cond, "arm {n}: extracted condition anchors");
        // Only control flow, plus the shared false materializer, sits between tests.
        for off in &glue {
            match op_at(&map, *off) {
                Op::B { .. } | Op::Bf { .. } => {}
                Op::Constant { value } => {
                    assert_eq!(*value, 0.0, "arm {n}: the only literal in the chain is 0");
                    assert_eq!(Some(*off), false_materializer(&b, n),
                        "arm {n}: the false materializer sits right before the gate");
                }
                other => panic!("arm {n}: unexpected {other:?} in the test chain @{off}"),
            }
        }
        assert_eq!(false_materializer(&b, n).is_some(), arm.cond.len() > 1,
            "arm {n}: only multi-test chains need a false materializer");

        // Body: constant/store pairs, exactly one 1, the rest 0, all twelve globals.
        let mut names: Vec<String> = Vec::new();
        let mut ones: Vec<String> = Vec::new();
        let mut pos = 0;
        while pos < body_span.len() {
            match op_at(&map, body_span[pos]) {
                Op::Constant { value } => {
                    match op_at(&map, body_span[pos + 1]) {
                        Op::Store { name, selector: -5, .. } => {
                            assert!(*value == 0.0 || *value == 1.0,
                                "arm {n}: body writes {value}, not a flag");
                            if *value == 1.0 {
                                ones.push(name.clone());
                            }
                            names.push(name.clone());
                        }
                        other => panic!("arm {n}: constant @{} feeds {other:?}", body_span[pos]),
                    }
                    pos += 2;
                }
                Op::B { target } => {
                    assert_eq!(*target, CODE_START + TAIL,
                        "arm {n}: the body terminator jumps to the tail");
                    assert_eq!(pos, body_span.len() - 1, "arm {n}: the body ends with it");
                    pos += 1;
                }
                other => panic!("arm {n}: unexpected {other:?} in the body @{}", body_span[pos]),
            }
        }
        assert_eq!(names.len(), usize::from(arm.stores), "arm {n}: store count");
        assert_eq!(ones, vec![arm.sel.to_string()], "arm {n}: exactly one weapon is selected");
        let mut distinct = names.clone();
        distinct.sort();
        distinct.dedup();
        assert_eq!(distinct.len(), 12, "arm {n}: the body covers all twelve weapon globals");
        for w in WEAPONS {
            assert!(distinct.iter().any(|n| n == w), "arm {n}: {w} missing from the body");
        }
        let dup: Vec<&String> =
            distinct.iter().filter(|d| names.iter().filter(|n| *n == *d).count() > 1).collect();
        if arm.stores == 13 {
            assert_eq!(dup.len(), 1, "arm {n}: one repeated name in the 13-store layout");
            assert_eq!(dup[0].as_str(), "shotgun",
                "arm {n}: the extra store is shotgun, written twice");
            let hits = names.iter().filter(|n| *n == "shotgun").count();
            assert_eq!(hits, 2, "arm {n}: shotgun stored twice");
        } else {
            assert!(dup.is_empty(), "arm {n}: the 12-store layout writes each weapon once");
        }
    }

    // The tail: instance_create(105, obj_player.x - 16, obj_player.y).
    let tail: Vec<usize> = span_offsets(&b, WEAPONS_WAP_CODE, TAIL, CODE_END);
    assert_eq!(tail.len(), 8, "tail instruction count");
    assert!(matches!(op_at(&map, tail[0]), Op::Constant { value } if *value == 105.0),
        "the tail creates obj_weaponname (105)");
    assert!(matches!(op_at(&map, tail[1]), Op::Cast { to: 5 }), "the object id is a real");
    assert!(matches!(op_at(&map, tail[2]), Op::Load { name, selector: 0, .. } if name == "y"),
        "the tail reads obj_player.y");
    assert!(matches!(op_at(&map, tail[3]), Op::Load { name, selector: 0, .. } if name == "x"),
        "the tail reads obj_player.x");
    assert!(matches!(op_at(&map, tail[4]), Op::Constant { value } if *value == 16.0));
    assert!(matches!(op_at(&map, tail[5]), Op::Sub));
    assert!(matches!(op_at(&map, tail[6]), Op::Call { name, argc: 3 } if name == "instance_create"));
    assert!(matches!(op_at(&map, tail[7]), Op::Popz), "the body ends on a popped call result");
    assert_eq!(tail[7], TAIL_POPZ);
}

#[test]
// CODE 462
fn weaponname_label_map_matches_code_462() {
    let b = bundle();
    let map = ops(&b, WEAPONNAME_CODE);
    let c = code(&b, WEAPONNAME_CODE);
    let obj = b.objects.iter().find(|o| o.id == LABEL).expect("obj_weaponname exists");
    let create: Vec<_> = obj.events.iter().filter(|e| e.event_type == 0 && e.subtype == 0).collect();
    assert_eq!(create.len(), 1);
    assert_eq!(create[0].codes, vec![WEAPONNAME_CODE], "obj_weaponname's Create is CODE 462");

    let span = span_offsets(&b, WEAPONNAME_CODE, 0, c.end - c.start);
    // Prologue: constant/store pairs for vspeed = -6; image_speed = 0; alpha = 1.
    let prologue = [("vspeed", -6.0), ("image_speed", 0.0), ("alpha", 1.0)];
    for (i, (name, value)) in prologue.iter().enumerate() {
        match (op_at(&map, span[i * 2]), op_at(&map, span[i * 2 + 1])) {
            (Op::Constant { value: v }, Op::Store { name: n, selector: -1, .. }) => {
                assert_eq!((n.as_str(), *v), (*name, *value), "CODE 462 prologue row {i}");
            }
            other => panic!("CODE 462 prologue row {i}: {other:?}"),
        }
    }
    // Then six-instruction name arms:
    // load <weapon>; constant 1; cmp ==; bf; string <id>; store damage.
    let mut seen: Vec<(String, usize)> = Vec::new();
    let mut pos = 6;
    while pos + 5 < span.len() {
        match (op_at(&map, span[pos]), op_at(&map, span[pos + 1]), op_at(&map, span[pos + 2]),
               op_at(&map, span[pos + 3]), op_at(&map, span[pos + 4]), op_at(&map, span[pos + 5])) {
            (Op::Load { name, selector: -5, .. }, Op::Constant { value: 1.0 },
             Op::Cmp { comparison: 3 }, Op::Bf { .. }, Op::String { string_id },
             Op::Store { name: field, selector: -1, .. }) => {
                assert_eq!(field, "damage", "the label writes `damage`");
                seen.push((name.clone(), *string_id));
            }
            other => panic!("CODE 462 name arm at span slot {pos}: {other:?}"),
        }
        pos += 6;
    }
    assert_eq!(seen.len(), 12, "CODE 462 names all twelve weapons");
    let want: Vec<(String, usize)> = LABEL_STR.iter().map(|(w, s)| ((*w).to_string(), *s)).collect();
    assert_eq!(seen, want, "the label string ids the sweep asserts");
}

// ---- the sweep -------------------------------------------------------------

#[test]
// CODE 519
fn every_arm_rotates_the_full_twelve_weapon_vector() {
    let b = bundle();
    let mut covered = 0usize;
    for (n, arm) in ARMS.iter().enumerate() {
        let (mut s, player, swap) = fresh(&b);
        reset(&mut s);
        seed(&mut s, arm.cond);
        s.executed.clear();
        s.audio.clear();
        let before = labels(&s);
        let px = s.instances[&player].fields["x"];
        let py = s.instances[&player].fields["y"];

        s.dispatch(&b, swap, 2, 0).unwrap_or_else(|e| panic!("arm {n}: CODE 519 failed: {e}"));

        // CODE 519 - the arm body: the whole 12-dimensional active vector.
        for w in WEAPONS {
            let want = if w == arm.sel { 1.0 } else { 0.0 };
            assert_eq!(g(&s, w), want,
                "arm {n} ({} active): {w} must be {want} after the rotation", arm.cond[0].0);
        }
        let active = WEAPONS.iter().filter(|w| g(&s, w) == 1.0).count();
        assert_eq!(active, 1, "arm {n}: exactly one weapon active, got {active}");

        // The double increment, on top of the sentinel.
        assert_eq!(g(&s, "weaponswapped"), SENTINEL_SWAPS + 2.0,
            "arm {n}: the shipped body increments weaponswapped twice");

        // CODE 519 carries no alarm re-arm line.
        assert_eq!(s.instances[&swap].alarms[0], -1, "arm {n}: alarm[0] is not re-armed");

        // CODE 519 - the prologue's sound gate (gate shut -> plays).
        assert_eq!(s.audio.len(), 1, "arm {n}: one sound queued, got {:?}", s.audio);
        let a = &s.audio[0];
        assert_eq!(a.sound, SND_WEAPONS_WAP, "arm {n}: snd_weaponswap (SOND 5)");
        assert_eq!(a.priority, 0.0, "arm {n}: priority 0");
        assert!(!a.looping, "arm {n}: one-shot");
        assert_eq!((a.code, a.offset), (WEAPONS_WAP_CODE, CODE_START + AUDIO_CALL),
            "arm {n}: the command comes from CODE 519's own gate call");

        // CODE 519 - the tail's label (its name comes from CODE 462).
        let after = labels(&s);
        let new: Vec<i32> = after.iter().copied().filter(|id| !before.contains(id)).collect();
        assert_eq!(new.len(), 1, "arm {n}: one obj_weaponname spawned, got {new:?}");
        let l = &s.instances[&new[0]];
        assert_eq!(l.fields["x"], px - 16.0, "arm {n}: spawn x = obj_player.x - 16");
        assert_eq!(l.fields["y"], py, "arm {n}: spawn y = obj_player.y (no motion pass ran)");
        assert_eq!(l.fields["vspeed"], -6.0, "arm {n}: CODE 462 launches the label");
        assert_eq!(l.fields["image_speed"], 0.0, "arm {n}: CODE 462 pins the label sprite");
        assert_eq!(l.fields["alpha"], 1.0);
        let want_name = STRING_REF_BASE + label_string_id(arm.sel) as f64;
        assert_eq!(l.fields["damage"], want_name,
            "arm {n}: the label names {} (CODE 462 runs after the rotation)", arm.sel);

        // CODE 519 - instruction level: only this arm's body, ladder stopped here.
        assert_only_this_body(&b, &s, n);
        assert_short_circuit(&b, &s, n);
        covered += 1;
    }
    assert_eq!(covered, 78, "all 78 arms driven");
}

#[test]
// CODE 519
fn every_arm_stays_silent_while_snd_weaponswap_is_playing() {
    let b = bundle();
    for (n, arm) in ARMS.iter().enumerate() {
        let (mut s, _player, swap) = fresh(&b);
        reset(&mut s);
        seed(&mut s, arm.cond);
        // Open the gate: a live voice of SOND 5 exists, so audio_is_playing is
        // true and the body has to skip the play call entirely.
        s.call_audio_play(f64::from(SND_WEAPONS_WAP), 0.0, false);
        s.audio.clear();
        s.executed.clear();

        s.dispatch(&b, swap, 2, 0).unwrap_or_else(|e| panic!("arm {n}: CODE 519 failed: {e}"));

        // CODE 519 - the prologue's sound gate (gate open -> silent).
        assert!(s.audio.is_empty(), "arm {n}: the is_playing gate stays shut, got {:?}", s.audio);
        assert!(!ledger(&s).contains(&AUDIO_CALL),
            "arm {n}: the audio_play_sound instruction must not execute behind an open gate");
        for w in WEAPONS {
            let want = if w == arm.sel { 1.0 } else { 0.0 };
            assert_eq!(g(&s, w), want, "arm {n}: the rotation is independent of the gate ({w})");
        }
        assert_eq!(g(&s, "weaponswapped"), SENTINEL_SWAPS + 2.0, "arm {n}: still counted");
        assert_only_this_body(&b, &s, n);
    }
}

// ---- negatives -------------------------------------------------------------

#[test]
// CODE 519
fn no_active_weapon_falls_through_every_arm_without_writing() {
    let b = bundle();
    let (mut s, _player, swap) = fresh(&b);
    reset(&mut s);
    // Every weapon flag on a distinct non-1 sentinel: no arm's vessel test can
    // pass, so the ladder has to fall through to the tail untouched.
    for (i, w) in WEAPONS.iter().enumerate() {
        s.globals.insert((*w).into(), 2.0 + i as f64);
    }
    s.executed.clear();
    s.audio.clear();
    let before = labels(&s);

    s.dispatch(&b, swap, 2, 0).expect("CODE 519 fall-through");

    for (i, w) in WEAPONS.iter().enumerate() {
        assert_eq!(g(&s, w), 2.0 + i as f64, "no arm matched, so nothing may write {w}");
    }
    assert_eq!(g(&s, "weaponswapped"), SENTINEL_SWAPS + 2.0,
        "the prologue is outside the ladder: it still counts the swap");
    assert_eq!(s.audio.len(), 1, "the prologue still plays the swap sound");

    let after = labels(&s);
    let new: Vec<i32> = after.iter().copied().filter(|id| !before.contains(id)).collect();
    assert_eq!(new.len(), 1, "the tail runs on every fall-through");
    assert!(s.instances[&new[0]].fields.get("damage").is_none(),
        "no weapon active, so CODE 462's name chain writes nothing");

    // CODE 519 - no arm body ran; every arm's vessel test did.
    let led = ledger(&s);
    let map = ops(&b, WEAPONS_WAP_CODE);
    for (j, arm) in ARMS.iter().enumerate() {
        let hits: Vec<usize> =
            led.iter().copied().filter(|o| (arm.body..body_end(j)).contains(o)).collect();
        assert!(hits.is_empty(), "fall-through must not enter arm {j}'s body, got {hits:?}");
        let chain: Vec<usize> =
            led.iter().copied().filter(|o| (arm.chain..arm.body).contains(o)).collect();
        let cmps = chain.iter().filter(|o| matches!(op_at(&map, **o), Op::Cmp { .. })).count();
        assert_eq!(cmps, 1, "fall-through evaluates exactly the vessel test of arm {j}");
        assert!(chain.contains(&arm.gate), "arm {j}'s gate bf must be reached");
    }
    assert_eq!(led.last(), Some(&TAIL_POPZ), "execution ends on the tail's popped call");
}

#[test]
// CODE 519
fn the_ladder_keys_on_the_bought_flags_not_the_active_flags() {
    let b = bundle();

    // (a) Two active flags, no purchases: arm 11 is the pistol group's
    //     all-bought-0 wrap and it matches before the bare bombgun arm is tested.
    let (mut s, _p, swap) = fresh(&b);
    reset(&mut s);
    s.globals.insert("pistol".into(), 1.0);
    s.globals.insert("bombgun".into(), 1.0);
    s.dispatch(&b, swap, 2, 0).expect("CODE 519 dirty vector");
    for w in WEAPONS {
        assert_eq!(g(&s, w), if w == "pistol" { 1.0 } else { 0.0 },
            "(a) the first matching arm wins and re-normalizes the vector ({w})");
    }
    assert_only_this_body(&b, &s, 11);

    // (b) An active flag that was never bought does not steer the ladder: the
    //     shotgun group reads assaultriflebought, not assaultrifle.
    let (mut s, _p, swap) = fresh(&b);
    reset(&mut s);
    s.globals.insert("shotgun".into(), 1.0);
    s.globals.insert("assaultrifle".into(), 1.0);
    s.globals.insert("rocketbought".into(), 1.0);
    s.dispatch(&b, swap, 2, 0).expect("CODE 519 active/bought split");
    assert_eq!(g(&s, "rocket"), 1.0, "(b) shotgun + rocketbought rotates to rocket");
    assert_eq!(g(&s, "assaultrifle"), 0.0,
        "(b) an active-but-unbought assaultrifle is zeroed, not rotated into");
    assert_only_this_body(&b, &s, 13);

    // (c) The bare `bombgun == 1` arm at the very end is pre-empted while a
    //     vessel arm still matches: spikegun + unbought bombgun wraps to pistol.
    let (mut s, _p, swap) = fresh(&b);
    reset(&mut s);
    s.globals.insert("spikegun".into(), 1.0);
    s.globals.insert("bombgun".into(), 1.0);
    s.dispatch(&b, swap, 2, 0).expect("CODE 519 tail arm precedence");
    assert_eq!(g(&s, "pistol"), 1.0, "(c) the spikegun wrap arm pre-empts the bare bombgun arm");
    assert_eq!(ARMS[76].cond, &[("spikegun", 1), ("bombgunbought", 0)][..],
        "arm 76 is the spikegun wrap that matches first");
    assert_only_this_body(&b, &s, 76);
}

// ---- the table's own census ------------------------------------------------

#[test]
// CODE 519
fn the_arm_census_is_the_shipped_triangular_matrix() {
    assert_eq!(ARMS.len(), 78);

    // 12 + 11 + ... + 1 groups, one per active weapon, in ladder order.
    let mut groups: Vec<(&str, Vec<&str>)> = Vec::new();
    for arm in ARMS.iter() {
        let vessel = arm.cond[0].0;
        match groups.last_mut() {
            Some((v, sels)) if *v == vessel => sels.push(arm.sel),
            _ => groups.push((vessel, vec![arm.sel])),
        }
    }
    let vessels: Vec<&str> = groups.iter().map(|(v, _)| *v).collect();
    assert_eq!(vessels, WEAPONS.to_vec(), "one group per weapon, in the shipped order");
    let sizes: Vec<usize> = groups.iter().map(|(_, sels)| sels.len()).collect();
    assert_eq!(sizes, (1..=12).rev().collect::<Vec<usize>>(), "group sizes are the triangular 12..1");
    assert_eq!(sizes.iter().sum::<usize>(), 78);

    for (i, (vessel, sels)) in groups.iter().enumerate() {
        // Each group reaches every later weapon, in order, then wraps to pistol.
        let mut want: Vec<&str> = WEAPONS[i + 1..].to_vec();
        want.push("pistol");
        assert_eq!(*sels, want, "group {vessel} rotation order");
        for arm in ARMS.iter().filter(|a| a.cond[0].0 == *vessel) {
            assert_eq!(arm.cond[0], (*vessel, 1), "the group's vessel test opens every arm");
            // The bought chain is the purchase-flag prefix, all 0 but the last.
            // The bare `bombgun == 1` arm (the ladder's last) tests no purchase
            // flag at all, so its chain is empty.
            let chain: Vec<(&str, i32)> = arm.cond[1..].to_vec();
            let want_chain: Vec<&str> = BOUGHT[i..i + chain.len()].to_vec();
            assert_eq!(chain.iter().map(|(k, _)| *k).collect::<Vec<_>>(), want_chain,
                "group {vessel}: the tested purchase flags are the shipped prefix");
            if chain.is_empty() {
                assert_eq!(*vessel, "bombgun", "only the bare bombgun arm tests no purchase flag");
                assert_eq!(arm.sel, "pistol", "the bare bombgun arm wraps to pistol");
                continue;
            }
            for (k, v) in &chain[..chain.len() - 1] {
                assert_eq!(*v, 0, "group {vessel}: only the last test selects ({k})");
            }
            let last = *chain.last().unwrap();
            if arm.sel == "pistol" {
                assert_eq!(last.1, 0, "the wrap arm needs the last purchase flag absent");
            } else {
                assert_eq!(last.1, 1, "the arm's last test selects {}", arm.sel);
                assert_eq!(last.0, format!("{}bought", arm.sel).as_str(),
                    "the selecting purchase flag belongs to {}", arm.sel);
            }
        }
    }

    // Every arm is a distinct predicate and a distinct purchase state.
    let mut conds: Vec<Vec<(&str, i32)>> = ARMS.iter().map(|a| a.cond.to_vec()).collect();
    conds.sort();
    conds.dedup();
    assert_eq!(conds.len(), 78, "78 distinct predicates, no duplicate arm");
    let mut inputs: Vec<Vec<(&str, i32)>> = Vec::new();
    for arm in ARMS.iter() {
        let mut row: Vec<(&str, i32)> =
            WEAPONS.iter().map(|w| (*w, input_value(arm.cond, w) as i32)).collect();
        row.extend(BOUGHT.iter().map(|w| (*w, input_value(arm.cond, w) as i32)));
        assert_eq!(row[..WEAPONS.len()].iter().filter(|(_, v)| *v == 1).count(), 1,
            "every input activates exactly one weapon (the purchase flags sit in the row's tail)");
        inputs.push(row);
    }
    let mut sorted = inputs.clone();
    sorted.sort();
    sorted.dedup();
    assert_eq!(sorted.len(), 78, "78 distinct purchase states, one per arm");

    // Store layout: 12 rows of 12 stores, 66 rows of 13 (shotgun twice).
    assert_eq!(ARMS.iter().filter(|a| a.stores == 12).count(), 12,
        "only the pistol group has the 12-store layout");
    assert_eq!(ARMS.iter().filter(|a| a.stores == 13).count(), 66);
    assert!(ARMS[..12].iter().all(|a| a.stores == 12));
    assert!(ARMS[12..].iter().all(|a| a.stores == 13),
        "every other group re-stores shotgun");

    // The name universe is exactly the twelve weapons plus the eleven bought flags.
    let mut names: Vec<&str> = ARMS.iter().flat_map(|a| a.cond.iter().map(|(k, _)| *k)).collect();
    names.sort();
    names.dedup();
    let mut want: Vec<&str> = WEAPONS.iter().copied().chain(BOUGHT.iter().copied()).collect();
    want.sort();
    assert_eq!(names, want, "the ladder reads no global outside these 23");

    // Body spans tile the ladder exactly: no gap, no overlap, no dead arm.
    assert_eq!(ARMS[0].chain, LADDER_START);
    for n in 1..ARMS.len() {
        assert_eq!(ARMS[n].chain, body_end(n - 1),
            "arm {n} starts where arm {}'s body ends - no dead code between gates", n - 1);
    }
    assert_eq!(body_end(ARMS.len() - 1), TAIL, "the last body runs into the tail");
}
