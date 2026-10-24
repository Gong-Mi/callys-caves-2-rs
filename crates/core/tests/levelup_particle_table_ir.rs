//! `obj_levelup` Draw (CODE 356) — the whole 114-cell `view_current x level`
//! particle table, plus the unconditional `draw_self()` and the `showpart` gate.
//!
//! Why this suite exists: `pause_and_floaters_draw_ir.rs` only probes ONE
//! level-up instance at view 0 / `global.level = 2` and asserts "particles is
//! not empty". CODE 356 is a pure table of **114** `part_particles_create`
//! calls (6 view blocks x 19 levels), each with its own x/y offset from the
//! `obj_UI` instance and its own call site, so "count > 0" says nothing about
//! 113 of them. This suite pins every cell.
//!
//! Navigation: the recovered GML
//! `0356__gml_Object_obj_levelup_Draw_0.gml` (same directory as the other
//! recovered events) is only a reading aid. Every bytecode-shaped claim below
//! (offsets, operands, jump targets, block membership, which arm wins) comes
//! from `crates/core/src/generated/full_ir.json` CODE 356, `codes[].id == 356`,
//! and the extraction was done by walking that body, not by transcribing the
//! GML. GML and bytecode agree on all 114 (dx, dy) pairs here; the bytecode
//! adds what the GML cannot show: the exact call sites, the short-circuit
//! layout of `view_current && showpart`, and the else-if `b` to the exit.
//!
//! Bytecode shape (authoritative):
//!
//!     draw_self(); popz                                  <- runs on EVERY call
//!     for each of 6 view blocks (guard g):
//!       g+0  load view_current(-1); g+8 constant V; g+12 cmp eq; g+16 bf g+40
//!       g+20 load showpart(-1);     g+28 constant 1; g+32 cmp eq; g+36 b g+44
//!       g+40 constant 0;            g+44 bf <next guard | end>
//!       then 19 arms, 88 bytes each, check at g+48+88*i:
//!         c+0 load level(-5); c+8 constant L; c+12 cmp eq; c+16 bf <next check>
//!         c+20 constant 3; cast; load Particle2(-5);
//!              load y(66); +DY; load x(66); +DX; load P_System2(-5);
//!              call part_particles_create(5); popz
//!       <b end>                                          <- else-if exit
//!
//! Two consequences that the GML text hides and that this suite asserts:
//!   * a `view_current` that is not one of {0,1,3,4,5,6} never even loads
//!     `showpart` (the `bf` at g+16 short-circuits to the `constant 0` at g+40),
//!   * `showpart == 1` is an equality test: 0, 2, -1 all take the same path
//!     (the `b` at g+36 jumps straight to the `bf` at g+44, skipping g+40).
//!
//! Fixture / evidence discipline:
//!   * the particle system and particle type come from the shipped initializer
//!     `obj_pwrlevelinitialize` (103) Create (CODE 458), not from a hand-made
//!     `part_system_create`; the globals `P_System2` / `Particle2` are read
//!     back and asserted to differ from the P_System/Particle1/Particle3 set,
//!   * `obj_UI` (66) is a real instance at a non-zero position, and
//!     `obj_levelup`'s own Create (CODE 352) stores `xposition = obj_UI.x + 50`
//!     — asserted, so the fixture proves the selector-66 receiver is the
//!     instance we pinned,
//!   * the particle API only exposes expanded `Particle` records (no call
//!     record), so each cell is proven twice: the particle instances
//!     (x, y, type_id, exactly 3 of them) AND the engine's instruction ledger
//!     (`Scene::executed`, one entry per VM instruction) compared to the exact
//!     instruction sequence CODE 356 must run for that cell — that is what
//!     makes "this one call site, not a neighbouring arm" observable,
//!   * the reusable checker is `validate_cell`, used for the positive matrix
//!     and for four perturbed `Bundle` copies (a written constant, the
//!     particle count, a gate jump target and the object's draw sprite), each
//!     of which it must reject.
//!
//! Scope: re-written-end IR regression semantics. This is not an equivalence
//! proof against the original runner, and particle emission is not pixel
//! consumption: nothing here renders, screenshots or claims GPU/device parity.
//!
//! Table provenance: extracted from `full_ir.json` CODE 356
//! (start 4199244, end 4209596, 1891 instructions) with a scratch walker
//! (`wl60-levelup-particles_table.py`, not checked in, in the worker scratch
//! dir) that decoded the guard chain and every arm body; the same walker is
//! re-implemented at run time by `derive()` below and cross-checked against
//! the embedded table on every run, so a regenerated IR that disagrees with
//! this file fails loudly instead of silently re-baselining.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::path::Path;

const LEVELUP: i32 = 63;
const UI: i32 = 66;
/// Shipped `obj_levelup` sprite (object table of `full_ir.json`); `draw_self()`
/// reads `sprite_index`, which `create` seeds from this value.
const LEVELUP_SPRITE: i32 = 35;
const PWRINIT: i32 = 103;
const CODE: usize = 356;

/// CODE 356's view blocks in bytecode order. There is **no view 2**: the
/// pause/levelup overlay never draws in view 2, and that hole is asserted.
const VIEWS: [i32; 6] = [0, 1, 3, 4, 5, 6];

/// (view, view guard `load view_current`, `load showpart`, the short-circuit
/// `constant 0`, the gate `bf`, that `bf`'s target) — the six guard blocks in
/// bytecode order. `skip_to` of the last block is the end of the body.
#[rustfmt::skip]
const GATES: [(i32, usize, usize, usize, usize, usize); 6] = [
    (0,    12,   32,   52,   56, 1736), // CODE 356 view 0 guard
    (1,  1736, 1756, 1776, 1780, 3460), // CODE 356 view 1 guard
    (3,  3460, 3480, 3500, 3504, 5184), // CODE 356 view 3 guard
    (4,  5184, 5204, 5224, 5228, 6908), // CODE 356 view 4 guard
    (5,  6908, 6928, 6948, 6952, 8632), // CODE 356 view 5 guard
    (6,  8632, 8652, 8672, 8676, 10352), // CODE 356 view 6 guard -> end
];

/// (view, level, dx, dy, arm body code_offset, `part_particles_create` call
/// code_offset) — CODE 356's 114 calls in bytecode order, 19 per view block.
/// Every arm pushes count 3 and the globals `Particle2` / `P_System2`; only
/// (dx, dy) vary. Extracted from `full_ir.json` CODE 356, never hand written.
#[rustfmt::skip]
const ARMS: [(i32, i32, i32, i32, usize, usize); 114] = [
    (0, 2, 104, 30, 80, 136), // CODE 356 view 0 level 2
    (0, 3, 119, 30, 168, 224), // CODE 356 view 0 level 3
    (0, 4, 134, 30, 256, 312), // CODE 356 view 0 level 4
    (0, 5, 149, 30, 344, 400), // CODE 356 view 0 level 5
    (0, 6, 164, 30, 432, 488), // CODE 356 view 0 level 6
    (0, 7, 179, 30, 520, 576), // CODE 356 view 0 level 7
    (0, 8, 194, 30, 608, 664), // CODE 356 view 0 level 8
    (0, 9, 58, 30, 696, 752), // CODE 356 view 0 level 9
    (0, 10, 66, 30, 784, 840), // CODE 356 view 0 level 10
    (0, 11, 74, 30, 872, 928), // CODE 356 view 0 level 11
    (0, 12, 82, 30, 960, 1016), // CODE 356 view 0 level 12
    (0, 13, 90, 30, 1048, 1104), // CODE 356 view 0 level 13
    (0, 14, 98, 30, 1136, 1192), // CODE 356 view 0 level 14
    (0, 15, 106, 30, 1224, 1280), // CODE 356 view 0 level 15
    (0, 16, 114, 30, 1312, 1368), // CODE 356 view 0 level 16
    (0, 17, 122, 30, 1400, 1456), // CODE 356 view 0 level 17
    (0, 18, 130, 30, 1488, 1544), // CODE 356 view 0 level 18
    (0, 19, 138, 20, 1576, 1632), // CODE 356 view 0 level 19
    (0, 20, 138, 30, 1664, 1720), // CODE 356 view 0 level 20
    (1, 2, 85, 25, 1804, 1860), // CODE 356 view 1 level 2
    (1, 3, 100, 25, 1892, 1948), // CODE 356 view 1 level 3
    (1, 4, 115, 25, 1980, 2036), // CODE 356 view 1 level 4
    (1, 5, 130, 25, 2068, 2124), // CODE 356 view 1 level 5
    (1, 6, 145, 25, 2156, 2212), // CODE 356 view 1 level 6
    (1, 7, 160, 25, 2244, 2300), // CODE 356 view 1 level 7
    (1, 8, 175, 25, 2332, 2388), // CODE 356 view 1 level 8
    (1, 9, 40, 25, 2420, 2476), // CODE 356 view 1 level 9
    (1, 10, 48, 25, 2508, 2564), // CODE 356 view 1 level 10
    (1, 11, 56, 25, 2596, 2652), // CODE 356 view 1 level 11
    (1, 12, 64, 25, 2684, 2740), // CODE 356 view 1 level 12
    (1, 13, 72, 25, 2772, 2828), // CODE 356 view 1 level 13
    (1, 14, 80, 25, 2860, 2916), // CODE 356 view 1 level 14
    (1, 15, 88, 25, 2948, 3004), // CODE 356 view 1 level 15
    (1, 16, 96, 25, 3036, 3092), // CODE 356 view 1 level 16
    (1, 17, 104, 25, 3124, 3180), // CODE 356 view 1 level 17
    (1, 18, 112, 25, 3212, 3268), // CODE 356 view 1 level 18
    (1, 19, 120, 20, 3300, 3356), // CODE 356 view 1 level 19
    (1, 20, 120, 25, 3388, 3444), // CODE 356 view 1 level 20
    (3, 2, 103, 38, 3528, 3584), // CODE 356 view 3 level 2
    (3, 3, 118, 38, 3616, 3672), // CODE 356 view 3 level 3
    (3, 4, 133, 38, 3704, 3760), // CODE 356 view 3 level 4
    (3, 5, 148, 38, 3792, 3848), // CODE 356 view 3 level 5
    (3, 6, 163, 38, 3880, 3936), // CODE 356 view 3 level 6
    (3, 7, 178, 38, 3968, 4024), // CODE 356 view 3 level 7
    (3, 8, 193, 38, 4056, 4112), // CODE 356 view 3 level 8
    (3, 9, 58, 33, 4144, 4200), // CODE 356 view 3 level 9
    (3, 10, 66, 33, 4232, 4288), // CODE 356 view 3 level 10
    (3, 11, 74, 33, 4320, 4376), // CODE 356 view 3 level 11
    (3, 12, 82, 33, 4408, 4464), // CODE 356 view 3 level 12
    (3, 13, 90, 33, 4496, 4552), // CODE 356 view 3 level 13
    (3, 14, 98, 33, 4584, 4640), // CODE 356 view 3 level 14
    (3, 15, 106, 33, 4672, 4728), // CODE 356 view 3 level 15
    (3, 16, 114, 33, 4760, 4816), // CODE 356 view 3 level 16
    (3, 17, 122, 33, 4848, 4904), // CODE 356 view 3 level 17
    (3, 18, 130, 33, 4936, 4992), // CODE 356 view 3 level 18
    (3, 19, 138, 23, 5024, 5080), // CODE 356 view 3 level 19
    (3, 20, 138, 33, 5112, 5168), // CODE 356 view 3 level 20
    (4, 2, 103, 38, 5252, 5308), // CODE 356 view 4 level 2
    (4, 3, 118, 38, 5340, 5396), // CODE 356 view 4 level 3
    (4, 4, 133, 38, 5428, 5484), // CODE 356 view 4 level 4
    (4, 5, 148, 38, 5516, 5572), // CODE 356 view 4 level 5
    (4, 6, 163, 38, 5604, 5660), // CODE 356 view 4 level 6
    (4, 7, 178, 38, 5692, 5748), // CODE 356 view 4 level 7
    (4, 8, 193, 38, 5780, 5836), // CODE 356 view 4 level 8
    (4, 9, 58, 33, 5868, 5924), // CODE 356 view 4 level 9
    (4, 10, 66, 33, 5956, 6012), // CODE 356 view 4 level 10
    (4, 11, 74, 33, 6044, 6100), // CODE 356 view 4 level 11
    (4, 12, 82, 33, 6132, 6188), // CODE 356 view 4 level 12
    (4, 13, 90, 33, 6220, 6276), // CODE 356 view 4 level 13
    (4, 14, 98, 33, 6308, 6364), // CODE 356 view 4 level 14
    (4, 15, 106, 33, 6396, 6452), // CODE 356 view 4 level 15
    (4, 16, 114, 33, 6484, 6540), // CODE 356 view 4 level 16
    (4, 17, 122, 33, 6572, 6628), // CODE 356 view 4 level 17
    (4, 18, 130, 33, 6660, 6716), // CODE 356 view 4 level 18
    (4, 19, 138, 23, 6748, 6804), // CODE 356 view 4 level 19
    (4, 20, 138, 33, 6836, 6892), // CODE 356 view 4 level 20
    (5, 2, 104, 30, 6976, 7032), // CODE 356 view 5 level 2
    (5, 3, 119, 30, 7064, 7120), // CODE 356 view 5 level 3
    (5, 4, 134, 30, 7152, 7208), // CODE 356 view 5 level 4
    (5, 5, 149, 30, 7240, 7296), // CODE 356 view 5 level 5
    (5, 6, 164, 30, 7328, 7384), // CODE 356 view 5 level 6
    (5, 7, 179, 30, 7416, 7472), // CODE 356 view 5 level 7
    (5, 8, 194, 30, 7504, 7560), // CODE 356 view 5 level 8
    (5, 9, 58, 30, 7592, 7648), // CODE 356 view 5 level 9
    (5, 10, 66, 30, 7680, 7736), // CODE 356 view 5 level 10
    (5, 11, 74, 30, 7768, 7824), // CODE 356 view 5 level 11
    (5, 12, 82, 30, 7856, 7912), // CODE 356 view 5 level 12
    (5, 13, 90, 30, 7944, 8000), // CODE 356 view 5 level 13
    (5, 14, 98, 30, 8032, 8088), // CODE 356 view 5 level 14
    (5, 15, 106, 30, 8120, 8176), // CODE 356 view 5 level 15
    (5, 16, 114, 30, 8208, 8264), // CODE 356 view 5 level 16
    (5, 17, 122, 30, 8296, 8352), // CODE 356 view 5 level 17
    (5, 18, 130, 30, 8384, 8440), // CODE 356 view 5 level 18
    (5, 19, 138, 20, 8472, 8528), // CODE 356 view 5 level 19
    (5, 20, 138, 30, 8560, 8616), // CODE 356 view 5 level 20
    (6, 2, 104, 30, 8700, 8756), // CODE 356 view 6 level 2
    (6, 3, 119, 30, 8788, 8844), // CODE 356 view 6 level 3
    (6, 4, 134, 30, 8876, 8932), // CODE 356 view 6 level 4
    (6, 5, 149, 30, 8964, 9020), // CODE 356 view 6 level 5
    (6, 6, 164, 30, 9052, 9108), // CODE 356 view 6 level 6
    (6, 7, 179, 30, 9140, 9196), // CODE 356 view 6 level 7
    (6, 8, 194, 30, 9228, 9284), // CODE 356 view 6 level 8
    (6, 9, 58, 30, 9316, 9372), // CODE 356 view 6 level 9
    (6, 10, 66, 30, 9404, 9460), // CODE 356 view 6 level 10
    (6, 11, 74, 30, 9492, 9548), // CODE 356 view 6 level 11
    (6, 12, 82, 30, 9580, 9636), // CODE 356 view 6 level 12
    (6, 13, 90, 30, 9668, 9724), // CODE 356 view 6 level 13
    (6, 14, 98, 30, 9756, 9812), // CODE 356 view 6 level 14
    (6, 15, 106, 30, 9844, 9900), // CODE 356 view 6 level 15
    (6, 16, 114, 30, 9932, 9988), // CODE 356 view 6 level 16
    (6, 17, 122, 30, 10020, 10076), // CODE 356 view 6 level 17
    (6, 18, 130, 30, 10108, 10164), // CODE 356 view 6 level 18
    (6, 19, 138, 20, 10196, 10252), // CODE 356 view 6 level 19
    (6, 20, 138, 30, 10284, 10340), // CODE 356 view 6 level 20
];

// ---- live instruction-stream derivation ------------------------------------

/// One arm as decoded from the bundle's live instruction stream.
#[derive(Debug, Clone)]
struct LiveArm {
    view: i32,
    level: i32,
    dx: i32,
    dy: i32,
    count: i32,
    type_global: String,
    system_global: String,
    /// Object whose `x`/`y` the arm offsets from (selector of the two loads).
    xy_object: i32,
    /// The 4 instructions of the `level == L` test, in execution order.
    check: Vec<usize>,
    /// The 12 instructions of the arm body (`constant 3` .. `popz`).
    body: Vec<usize>,
    body_off: usize,
    call_off: usize,
}

/// One `view_current`/`showpart` guard block as decoded from live IR.
#[derive(Debug, Clone)]
struct LiveGate {
    view: i32,
    view_load: usize,
    view_const: usize,
    view_cmp: usize,
    view_bf: usize,
    showpart_load: usize,
    one_const: usize,
    showpart_cmp: usize,
    b_off: usize,
    false_const: usize,
    gate_bf: usize,
    /// Where the gate `bf` jumps when the block is skipped.
    skip_to: usize,
    /// The else-if `b` that leaves the whole chain after this block ran.
    tail_b: Option<usize>,
}

impl LiveGate {
    /// Instructions executed when `view_current` does not match this block.
    fn mismatch(&self) -> Vec<usize> {
        vec![
            self.view_load,
            self.view_const,
            self.view_cmp,
            self.view_bf,
            self.false_const,
            self.gate_bf,
        ]
    }
    /// Instructions executed when `view_current` matches, up to (and including)
    /// the gate `bf`. Identical for `showpart == 1` and `showpart != 1`: the
    /// difference is only whether the `b` at `b_off` jumps over the arms.
    fn matched(&self) -> Vec<usize> {
        vec![
            self.view_load,
            self.view_const,
            self.view_cmp,
            self.view_bf,
            self.showpart_load,
            self.one_const,
            self.showpart_cmp,
            self.b_off,
            self.gate_bf,
        ]
    }
}

#[derive(Debug, Clone)]
struct Live {
    gates: Vec<LiveGate>,
    arms: Vec<LiveArm>,
    draw_self_off: usize,
    draw_self_popz_off: usize,
    /// Every `part_particles_create` call site in the body.
    call_sites: Vec<usize>,
    /// End of the body, relative to the CODE start.
    end_rel: usize,
}

fn in_at(ins: &[Instruction], k: usize) -> Result<&Instruction, String> {
    ins.get(k)
        .ok_or_else(|| format!("CODE {CODE}: body ends before expected instruction #{k}"))
}

fn is_load(op: &Op, name: &str, sel: i32) -> bool {
    matches!(op, Op::Load { name: n, selector: s, .. } if n == name && *s == sel)
}

fn need_load(i: &Instruction, name: &str, sel: i32, what: &str) -> Result<(), String> {
    if is_load(&i.op, name, sel) {
        Ok(())
    } else {
        Err(format!(
            "CODE {CODE} @{}: expected `load {name}` (selector {sel}) for {what}, got {:?}",
            i.code_offset, i.op
        ))
    }
}

fn need_call(i: &Instruction, name: &str, argc: usize, what: &str) -> Result<(), String> {
    match &i.op {
        Op::Call { name: n, argc: a } if n == name && *a == argc => Ok(()),
        other => Err(format!(
            "CODE {CODE} @{}: expected `call {name}/{argc}` for {what}, got {other:?}",
            i.code_offset
        )),
    }
}

fn need_cmp_eq(i: &Instruction, what: &str) -> Result<(), String> {
    match &i.op {
        Op::Cmp { comparison } if *comparison == 3 => Ok(()),
        other => Err(format!(
            "CODE {CODE} @{}: expected `cmp eq` for {what}, got {other:?}",
            i.code_offset
        )),
    }
}

fn int_const(op: &Op, what: &str) -> Result<i32, String> {
    match op {
        Op::Constant { value } if value.fract() == 0.0 => Ok(*value as i32),
        other => Err(format!(
            "expected an integer constant for {what}, got {other:?}"
        )),
    }
}

fn f64_const(op: &Op, what: &str) -> Result<f64, String> {
    match op {
        Op::Constant { value } => Ok(*value),
        other => Err(format!("expected a constant for {what}, got {other:?}")),
    }
}

fn jump_target(i: &Instruction, what: &str, start: usize) -> Result<usize, String> {
    match &i.op {
        Op::B { target } | Op::Bt { target } | Op::Bf { target } => Ok(*target - start),
        other => Err(format!(
            "CODE {CODE} @{}: expected a jump for {what}, got {other:?}",
            i.code_offset
        )),
    }
}

/// Re-derive the whole table from the bundle's own instruction stream. This is
/// deliberately a second, independent implementation of the extraction
/// (the first one is the embedded `ARMS`/`GATES` tables): a bundle whose
/// bytecode drifted is rejected by the cross-checks below rather than re-baselined.
fn derive(b: &Bundle) -> Result<Live, String> {
    let code = b
        .codes
        .iter()
        .find(|c| c.id == CODE)
        .ok_or_else(|| format!("bundle has no CODE {CODE}"))?;
    let ins = &code.instructions;
    let start = code.start;
    let end_rel = code
        .end
        .checked_sub(code.start)
        .ok_or_else(|| format!("CODE {CODE}: start beyond end"))?;
    let rel = |k: usize| ins[k].code_offset;

    // `draw_self();` runs above the gate: it is not inside any branch.
    need_call(
        in_at(ins, 0)?,
        "draw_self",
        0,
        "the unconditional self draw",
    )?;
    let draw_self_off = rel(0);
    if !matches!(in_at(ins, 1)?.op, Op::Popz) {
        return Err(format!("CODE {CODE}: draw_self() is not followed by popz"));
    }
    let draw_self_popz_off = rel(1);

    let call_sites: Vec<usize> = ins
        .iter()
        .filter(|i| matches!(&i.op, Op::Call { name, argc } if name == "part_particles_create" && *argc == 5))
        .map(|i| i.code_offset)
        .collect();

    let mut gates: Vec<LiveGate> = Vec::new();
    let mut arms: Vec<LiveArm> = Vec::new();
    let mut k = 2usize;

    while k < ins.len() {
        need_load(in_at(ins, k)?, "view_current", -1, "a view guard")?;
        let view = int_const(&in_at(ins, k + 1)?.op, "the guard's view constant")?;
        need_cmp_eq(in_at(ins, k + 2)?, "the view guard")?;
        let view_bf = rel(k + 3);
        jump_target(in_at(ins, k + 3)?, "the failed view guard", start)?;
        need_load(in_at(ins, k + 4)?, "showpart", -1, "the showpart gate")?;
        if int_const(&in_at(ins, k + 5)?.op, "the showpart literal")? != 1 {
            return Err(format!(
                "CODE {CODE} @{}: showpart is not compared with 1",
                rel(k + 5)
            ));
        }
        need_cmp_eq(in_at(ins, k + 6)?, "the showpart gate")?;
        let b_off = rel(k + 7);
        jump_target(in_at(ins, k + 7)?, "the showpart short-circuit", start)?;
        if int_const(&in_at(ins, k + 8)?.op, "the view-mismatch constant")? != 0 {
            return Err(format!(
                "CODE {CODE} @{}: the view-mismatch path does not push 0",
                rel(k + 8)
            ));
        }
        let gate_bf = rel(k + 9);
        let skip_to = jump_target(in_at(ins, k + 9)?, "the gate bf", start)?;
        gates.push(LiveGate {
            view,
            view_load: rel(k),
            view_const: rel(k + 1),
            view_cmp: rel(k + 2),
            view_bf,
            showpart_load: rel(k + 4),
            one_const: rel(k + 5),
            showpart_cmp: rel(k + 6),
            b_off,
            false_const: rel(k + 8),
            gate_bf,
            skip_to,
            tail_b: None,
        });
        k += 10;

        // 19 arms, each 88 bytes: `load level; constant L; cmp eq; bf` then the
        // body `constant 3; cast; load Particle2; ...; call; popz`.
        while k < ins.len() && is_load(&ins[k].op, "level", -5) && rel(k) < skip_to {
            let mut check = Vec::with_capacity(4);
            need_load(in_at(ins, k)?, "level", -5, "an arm")?;
            check.push(rel(k));
            k += 1;
            let level = int_const(&in_at(ins, k)?.op, "the arm's level constant")?;
            check.push(rel(k));
            k += 1;
            need_cmp_eq(in_at(ins, k)?, "the arm's level test")?;
            check.push(rel(k));
            k += 1;
            jump_target(in_at(ins, k)?, "the failed arm test", start)?;
            check.push(rel(k));
            k += 1;

            let mut body = Vec::with_capacity(12);
            let body_off = rel(k);
            let mut take = |body: &mut Vec<usize>, k: &mut usize| -> usize {
                let off = rel(*k);
                body.push(off);
                *k += 1;
                off
            };
            // constant 3
            let count = int_const(&in_at(ins, k)?.op, "the particle count")?;
            take(&mut body, &mut k);
            // cast (the count leaves the VM's int stack as a real)
            match &in_at(ins, k)?.op {
                Op::Cast { .. } => {}
                other => {
                    return Err(format!(
                        "CODE {CODE} @{}: expected cast after the count, got {other:?}",
                        rel(k)
                    ))
                }
            }
            take(&mut body, &mut k);
            // load Particle2 (global type handle)
            need_load(
                in_at(ins, k)?,
                "Particle2",
                -5,
                "the particle type argument",
            )?;
            let type_global = match &in_at(ins, k)?.op {
                Op::Load { name, .. } => name.clone(),
                _ => unreachable!(),
            };
            take(&mut body, &mut k);
            // load y (obj_UI) + dy
            let y_obj = match &in_at(ins, k)?.op {
                Op::Load { name, selector, .. } if name == "y" => *selector,
                other => {
                    return Err(format!(
                        "CODE {CODE} @{}: expected `load y`, got {other:?}",
                        rel(k)
                    ))
                }
            };
            take(&mut body, &mut k);
            let dy = f64_const(&in_at(ins, k)?.op, "the y offset")?;
            take(&mut body, &mut k);
            if !matches!(in_at(ins, k)?.op, Op::Add) {
                return Err(format!(
                    "CODE {CODE} @{}: expected `add` for the y offset",
                    rel(k)
                ));
            }
            take(&mut body, &mut k);
            // load x (same object) + dx
            let x_obj = match &in_at(ins, k)?.op {
                Op::Load { name, selector, .. } if name == "x" => *selector,
                other => {
                    return Err(format!(
                        "CODE {CODE} @{}: expected `load x`, got {other:?}",
                        rel(k)
                    ))
                }
            };
            if x_obj != y_obj {
                return Err(format!(
                    "CODE {CODE} @{}: x comes from object {x_obj} but y from {y_obj}",
                    rel(k)
                ));
            }
            take(&mut body, &mut k);
            let dx = f64_const(&in_at(ins, k)?.op, "the x offset")?;
            take(&mut body, &mut k);
            if !matches!(in_at(ins, k)?.op, Op::Add) {
                return Err(format!(
                    "CODE {CODE} @{}: expected `add` for the x offset",
                    rel(k)
                ));
            }
            take(&mut body, &mut k);
            // load P_System2 (the particle system the call targets)
            need_load(
                in_at(ins, k)?,
                "P_System2",
                -5,
                "the particle system argument",
            )?;
            let system_global = match &in_at(ins, k)?.op {
                Op::Load { name, .. } => name.clone(),
                _ => unreachable!(),
            };
            take(&mut body, &mut k);
            let call_off = rel(k);
            need_call(
                in_at(ins, k)?,
                "part_particles_create",
                5,
                "the arm's particle burst",
            )?;
            take(&mut body, &mut k);
            if !matches!(in_at(ins, k)?.op, Op::Popz) {
                return Err(format!(
                    "CODE {CODE} @{}: the arm body does not end in popz",
                    rel(k)
                ));
            }
            take(&mut body, &mut k);

            arms.push(LiveArm {
                view,
                level,
                dx: dx as i32,
                dy: dy as i32,
                count,
                type_global,
                system_global,
                xy_object: x_obj,
                check,
                body,
                body_off,
                call_off,
            });
        }

        // The else-if exit: a `b` to the end of the body, present on every
        // block except the last one (whose gate `bf` already targets the end).
        if k < ins.len() {
            if let Op::B { .. } = in_at(ins, k)?.op {
                let target = jump_target(in_at(ins, k)?, "the else-if exit", start)?;
                if target != end_rel {
                    return Err(format!("CODE {CODE} @{}: the block exit jumps to {target}, not to the body end {end_rel}", rel(k)));
                }
                let off = rel(k);
                k += 1;
                gates.last_mut().expect("gate pushed above").tail_b = Some(off);
            } else if is_load(&in_at(ins, k)?.op, "view_current", -1) {
                // next guard follows directly (last block had no exit `b`)
            } else {
                return Err(format!("CODE {CODE} @{}: unexpected instruction between a view block and the next guard: {:?}", rel(k), in_at(ins, k)?.op));
            }
        }
    }

    let live = Live {
        gates,
        arms,
        draw_self_off,
        draw_self_popz_off,
        call_sites,
        end_rel,
    };

    // Structural invariants of this body, independent of the embedded tables.
    if live.gates.len() != 6 {
        return Err(format!(
            "CODE {CODE} decodes {} view guards, expected 6",
            live.gates.len()
        ));
    }
    if live.arms.len() != 114 {
        return Err(format!(
            "CODE {CODE} decodes {} arms, expected 114",
            live.arms.len()
        ));
    }
    if live.call_sites.len() != 114 {
        return Err(format!(
            "CODE {CODE} has {} part_particles_create sites, expected 114",
            live.call_sites.len()
        ));
    }
    Ok(live)
}

// ---- expected execution path ----------------------------------------------

/// Exact instruction sequence CODE 356 must execute for one cell, built from
/// the live-derived block/arm groupings. Used to compare against
/// `Scene::executed`, which is why an observed run can be pinned to one arm
/// body and one call site instead of "some particles appeared".
fn expected_ledger(live: &Live, cell: &Cell) -> Vec<usize> {
    let mut out = vec![live.draw_self_off, live.draw_self_popz_off];
    let matched = live.gates.iter().position(|g| g.view == cell.view);
    let Some(mi) = matched else {
        // No block for this view: every guard runs its mismatch path.
        for g in &live.gates {
            out.extend(g.mismatch());
        }
        return out;
    };
    for g in &live.gates[..mi] {
        out.extend(g.mismatch());
    }
    out.extend(live.gates[mi].matched());

    let view_arms: Vec<&LiveArm> = live.arms.iter().filter(|a| a.view == cell.view).collect();
    let hit = view_arms.iter().position(|a| a.level == cell.level);
    if cell.showpart == 1.0 {
        // The 19 arms are INDEPENDENT `if (global.level == N)` statements, not
        // a switch: after the matching body, the remaining tests still run (and
        // fail). The bytecode shows it - the popz at the end of an arm body is
        // followed directly by the next arm's `load level`, and each arm's `bf`
        // targets the next test, not the exit. Only the body is gated.
        let first_after = match hit {
            Some(hi) => {
                for a in &view_arms[..hi] {
                    out.extend(a.check.iter().copied());
                }
                let arm = view_arms[hi];
                out.extend(arm.check.iter().copied());
                out.extend(arm.body.iter().copied());
                hi + 1
            }
            // level outside 2..=20: all 19 tests run and fail.
            None => 0,
        };
        for a in &view_arms[first_after..] {
            out.extend(a.check.iter().copied());
        }
        if let Some(tail) = live.gates[mi].tail_b {
            out.push(tail);
        }
    } else {
        // showpart != 1: the `b` at b_off jumps over the arms straight to the
        // gate `bf`, which skips to the next guard; the remaining guards all
        // mismatch (view_current is unchanged).
        for g in &live.gates[mi + 1..] {
            out.extend(g.mismatch());
        }
    }
    out
}

// ---- fixture ---------------------------------------------------------------

fn bundle_and_asset() -> (Bundle, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset =
        GameDroidAsset::parse(root.join("../../assets/game.droid")).expect("parse game.droid");
    let mut b =
        load_bundle_from_file(&root.join("src/generated/full_ir.json")).expect("load full_ir.json");
    b.string_table = asset.string_table.clone();
    (b, asset)
}

fn bundle() -> Bundle {
    bundle_and_asset().0
}

struct Fixture {
    scene: Scene,
    ui: i32,
    levelup: i32,
}

/// Real materialiser path: `obj_pwrlevelinitialize` Create (CODE 458) builds the
/// three particle systems and three particle types; `obj_UI` Create (CODE 365)
/// spawns the HUD widgets and `obj_levelup` Create (CODE 352) reads obj_UI.
fn setup(b: &Bundle) -> Result<Fixture, String> {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    for v in 0..=6 {
        s.view_positions.insert(v, (0.0, 0.0));
    }

    let pwr = s.create(b, PWRINIT, -1000.0, -1000.0)?;
    // The initializer's only job is the globals; park it so it cannot draw.
    s.instances
        .get_mut(&pwr)
        .expect("initializer instance")
        .alive = false;

    let ui = s.create(b, UI, 400.0, 300.0)?;
    let levelup = s.create(b, LEVELUP, 100.0, 200.0)?;

    // Keep the cell under test isolated: obj_UI's Create spawns the touch
    // buttons and the view-resolution object, all of which own Draw events.
    for (id, i) in s.instances.iter_mut() {
        if *id != ui && *id != levelup {
            i.alive = false;
        }
    }
    Ok(Fixture {
        scene: s,
        ui,
        levelup,
    })
}

#[derive(Clone, Copy, Debug)]
struct Cell {
    view: i32,
    level: i32,
    showpart: f64,
    /// obj_UI's pinned position; the arms offset from it.
    ui: (f64, f64),
    /// obj_levelup's pinned position; `draw_self` must use it verbatim.
    levelup: (f64, f64),
}

#[derive(Debug)]
struct Obs {
    /// (x, y, type_id) of each particle spawned by this draw, in emission order.
    particles: Vec<(f64, f64, f64)>,
    /// (sprite, x, y) of every DrawCommand attributed to CODE 356 this draw.
    draws: Vec<(i32, f64, f64)>,
    /// CODE 356 code_offsets the VM executed during this draw, in order.
    ledger: Vec<usize>,
    /// `global.Particle2` at emission time: the type the arms load.
    particle2_global: f64,
    /// `global.P_System2` at emission time: the system the arms load.
    p_system2_global: f64,
}

fn observe(b: &Bundle, f: &mut Fixture, cell: &Cell) -> Result<Obs, String> {
    f.scene.globals.insert("level".into(), cell.level as f64);
    let lvl = f
        .scene
        .instances
        .get_mut(&f.levelup)
        .ok_or("levelup instance vanished")?;
    lvl.fields.insert("showpart".into(), cell.showpart);
    let ui = f
        .scene
        .instances
        .get_mut(&f.ui)
        .ok_or("obj_UI instance vanished")?;
    ui.fields.insert("x".into(), cell.ui.0);
    ui.fields.insert("y".into(), cell.ui.1);

    let particle2_global = f
        .scene
        .globals
        .get("Particle2")
        .copied()
        .unwrap_or(f64::NAN);
    let p_system2_global = f
        .scene
        .globals
        .get("P_System2")
        .copied()
        .unwrap_or(f64::NAN);

    f.scene.executed.clear();
    let before = f.scene.particles.len();
    f.scene.draw_view(b, cell.view)?;

    let particles = f.scene.particles[before..]
        .iter()
        .map(|p| (p.x, p.y, p.type_id))
        .collect();
    let draws = f
        .scene
        .draws
        .iter()
        .filter(|d| d.code == CODE)
        .map(|d| (d.sprite, d.x, d.y))
        .collect();
    let code = b
        .codes
        .iter()
        .find(|c| c.id == CODE)
        .ok_or("missing CODE 356")?;
    let start = code.start;
    let ledger = f
        .scene
        .executed
        .iter()
        .filter(|(c, _)| *c == CODE)
        .map(|(_, o)| o - start)
        .collect();
    Ok(Obs {
        particles,
        draws,
        ledger,
        particle2_global,
        p_system2_global,
    })
}

/// The reusable oracle. Used unchanged for the positive matrix and for the
/// perturbed-bundle negative controls: it (1) cross-checks the live instruction
/// stream against the embedded bytecode table for this cell, (2) checks the
/// observed particles, the self draw and the executed instruction path.
fn validate_cell(live: &Live, cell: &Cell, obs: &Obs) -> Result<(), String> {
    let where_ = format!(
        "CODE {CODE} view {} level {} showpart {}",
        cell.view, cell.level, cell.showpart
    );

    // (1) guard block: live IR must still match the embedded bytecode.
    match GATES.iter().find(|g| g.0 == cell.view) {
        Some(emb) => {
            let g = live
                .gates
                .iter()
                .find(|g| g.view == cell.view)
                .ok_or_else(|| {
                    format!(
                        "{where_}: live IR has no guard block for view {}",
                        cell.view
                    )
                })?;
            if (
                g.view_load,
                g.showpart_load,
                g.false_const,
                g.gate_bf,
                g.skip_to,
            ) != (emb.1, emb.2, emb.3, emb.4, emb.5)
            {
                return Err(format!(
                    "{where_}: live guard (load {}, showpart {}, false {}, bf {}, skip {}) != embedded ({}, {}, {}, {}, {})",
                    g.view_load, g.showpart_load, g.false_const, g.gate_bf, g.skip_to,
                    emb.1, emb.2, emb.3, emb.4, emb.5));
            }
        }
        None => {
            if live.gates.iter().any(|g| g.view == cell.view) {
                return Err(format!("{where_}: live IR grew a guard block for a view the shipped table does not handle"));
            }
        }
    }

    let row = ARMS.iter().find(|a| a.0 == cell.view && a.1 == cell.level);
    let emit = cell.showpart == 1.0 && row.is_some();

    // (2) arm: live IR must still match the embedded bytecode for this cell.
    if let Some(row) = row {
        let a = live
            .arms
            .iter()
            .find(|a| a.view == cell.view && a.level == cell.level)
            .ok_or_else(|| format!("{where_}: live IR has no arm for this cell"))?;
        if (a.view, a.level, a.dx, a.dy, a.body_off, a.call_off)
            != (row.0, row.1, row.2, row.3, row.4, row.5)
        {
            return Err(format!(
                "{where_}: live arm (view {}, level {}, dx {}, dy {}, body {}, call {}) != embedded (view {}, level {}, dx {}, dy {}, body {}, call {})",
                a.view, a.level, a.dx, a.dy, a.body_off, a.call_off, row.0, row.1, row.2, row.3, row.4, row.5));
        }
        if a.count != 3 {
            return Err(format!(
                "{where_}: live IR emits {} particles, the shipped table says 3",
                a.count
            ));
        }
        if a.type_global != "Particle2" || a.system_global != "P_System2" || a.xy_object != UI {
            return Err(format!(
                "{where_}: live arm loads type `{}` / system `{}` / offsets from object {}, expected Particle2 / P_System2 / {UI}",
                a.type_global, a.system_global, a.xy_object));
        }
    }

    // (3) particle instances: count, position and the resolved type handle.
    if emit {
        let row = row.expect("emit implies a table row");
        let (dx, dy) = (row.2 as f64, row.3 as f64);
        let want = (cell.ui.0 + dx, cell.ui.1 + dy);
        if obs.particles.len() != 3 {
            return Err(format!(
                "{where_}: expected 3 particles at {want:?}, got {} ({:?})",
                obs.particles.len(),
                obs.particles
            ));
        }
        for (i, p) in obs.particles.iter().enumerate() {
            if (p.0, p.1) != want {
                return Err(format!(
                    "{where_}: particle {i} spawned at ({}, {}), expected obj_UI ({}, {}) + ({dx}, {dy}) = {want:?}",
                    p.0, p.1, cell.ui.0, cell.ui.1));
            }
            if p.2 != obs.particle2_global {
                return Err(format!(
                    "{where_}: particle {i} has type {}, expected the global Particle2 = {}",
                    p.2, obs.particle2_global
                ));
            }
        }
    } else if !obs.particles.is_empty() {
        return Err(format!(
            "{where_}: expected no particles, got {:?}",
            obs.particles
        ));
    }

    // (4) the unconditional `draw_self()`: present in every case, at the
    // instance's own position, with the shipped sprite.
    if obs.draws.len() != 1 {
        return Err(format!(
            "{where_}: expected exactly one CODE {CODE} draw_self, got {:?}",
            obs.draws
        ));
    }
    let (sprite, x, y) = obs.draws[0];
    if sprite != LEVELUP_SPRITE {
        return Err(format!("{where_}: draw_self emitted sprite {sprite}, obj_levelup ships sprite {LEVELUP_SPRITE}"));
    }
    if (x, y) != cell.levelup {
        return Err(format!(
            "{where_}: draw_self drew at ({x}, {y}), expected the instance position {:?}",
            cell.levelup
        ));
    }

    // (5) executed instruction path: exactly this cell's path, and exactly one
    // call site (or none when the gate suppresses the burst).
    let expect = expected_ledger(live, cell);
    if obs.ledger != expect {
        return Err(format!(
            "{where_}: executed ledger differs from the bytecode path\n  expected {expect:?}\n  actual   {:?}",
            obs.ledger));
    }
    let hit: Vec<usize> = obs
        .ledger
        .iter()
        .copied()
        .filter(|o| live.call_sites.contains(o))
        .collect();
    if emit {
        let row = row.expect("emit implies a table row");
        if hit != vec![row.5] {
            return Err(format!(
                "{where_}: executed particle call sites {hit:?}, expected exactly [{0}]",
                row.5
            ));
        }
    } else if !hit.is_empty() {
        return Err(format!(
            "{where_}: no burst is expected but call sites {hit:?} executed"
        ));
    }
    Ok(())
}

// ---- 1. the full 6 x 19 matrix ---------------------------------------------

#[test]
// CODE 356
fn every_view_level_cell_emits_three_particles_at_the_shipped_ui_offset() {
    let b = bundle();
    let live = derive(&b).expect("CODE 356 must keep its shipped shape");
    let mut f = setup(&b).expect("fixture");

    // The fixture's own anchors: obj_UI identity and the particle handles the
    // arms load, taken from the shipped initializer rather than invented.
    let xposition = f.scene.instances[&f.levelup]
        .fields
        .get("xposition")
        .copied();
    assert_eq!(xposition, Some(400.0 + 50.0),
        "CODE 352 stores obj_UI.x + 50, so the levelup instance proves which instance selector {UI} resolved");
    let particle2 = f
        .scene
        .globals
        .get("Particle2")
        .copied()
        .expect("global Particle2");
    let p_system2 = f
        .scene
        .globals
        .get("P_System2")
        .copied()
        .expect("global P_System2");
    assert_ne!(
        particle2,
        f.scene.globals.get("Particle1").copied().unwrap(),
        "Particle2 is its own type"
    );
    assert_ne!(
        particle2,
        f.scene.globals.get("Particle3").copied().unwrap(),
        "Particle2 is its own type"
    );
    assert_ne!(
        p_system2,
        f.scene.globals.get("P_System").copied().unwrap(),
        "P_System2 is its own system"
    );
    assert!(
        f.scene.particle_systems.contains(&p_system2),
        "P_System2 is a registered particle system"
    );

    // Two distinct non-zero obj_UI origins: an offset table must follow its base.
    let origins = [(400.0, 300.0), (123.0, 77.0)];
    let mut cells = 0usize;
    for row in ARMS.iter() {
        let (view, level, dx, dy, _, _) = *row;
        for origin in origins {
            let cell = Cell {
                view,
                level,
                showpart: 1.0,
                ui: origin,
                levelup: (100.0, 200.0),
            };
            let obs = observe(&b, &mut f, &cell)
                .unwrap_or_else(|e| panic!("view {view} level {level} ui {origin:?}: {e}"));
            validate_cell(&live, &cell, &obs)
                .unwrap_or_else(|e| panic!("view {view} level {level} ui {origin:?}: {e}"));
            assert_eq!(
                obs.particles.len(),
                3,
                "view {view} level {level}: count is 3"
            );
            assert_eq!(
                obs.p_system2_global, p_system2,
                "view {view} level {level}: the arm's system global is the registered P_System2"
            );
            let want = (origin.0 + dx as f64, origin.1 + dy as f64);
            for p in &obs.particles {
                assert_eq!(
                    (p.0, p.1),
                    want,
                    "view {view} level {level}: obj_UI {origin:?} + ({dx}, {dy})"
                );
                assert_eq!(
                    p.2, particle2,
                    "view {view} level {level}: global.Particle2"
                );
            }
            cells += 1;
        }
    }
    assert_eq!(cells, 228, "114 table cells x 2 obj_UI origins");
}

// ---- 2. the showpart gate ---------------------------------------------------

#[test]
// CODE 356
fn showpart_must_equal_one_and_never_suppresses_draw_self() {
    let b = bundle();
    let live = derive(&b).expect("CODE 356 shape");
    let mut f = setup(&b).expect("fixture");
    let mut cells = 0usize;
    // `showpart == 1` is an equality test, not a truthiness test: 2 and -1 take
    // the same suppression path as 0.
    for showpart in [0.0, 2.0, -1.0] {
        for view in VIEWS {
            for level in [2, 9, 19, 20] {
                let cell = Cell {
                    view,
                    level,
                    showpart,
                    ui: (400.0, 300.0),
                    levelup: (100.0, 200.0),
                };
                let obs = observe(&b, &mut f, &cell).unwrap_or_else(|e| {
                    panic!("showpart {showpart} view {view} level {level}: {e}")
                });
                validate_cell(&live, &cell, &obs).unwrap_or_else(|e| {
                    panic!("showpart {showpart} view {view} level {level}: {e}")
                });
                assert!(
                    obs.particles.is_empty(),
                    "showpart {showpart} view {view} level {level}: the burst is gated off"
                );
                assert_eq!(
                    obs.draws.len(),
                    1,
                    "showpart {showpart} view {view} level {level}: draw_self still runs"
                );
                // no arm body of this view ran
                let arms: Vec<&LiveArm> = live.arms.iter().filter(|a| a.view == view).collect();
                for a in arms {
                    for off in &a.body {
                        assert!(!obs.ledger.contains(off),
                            "showpart {showpart} view {view} level {level}: arm body instruction {off} must not run");
                    }
                }
                cells += 1;
            }
        }
    }
    assert_eq!(cells, 3 * 6 * 4);
}

// ---- 3. levels outside the table -------------------------------------------

#[test]
// CODE 356
fn levels_outside_two_to_twenty_run_all_nineteen_tests_and_emit_nothing() {
    let b = bundle();
    let live = derive(&b).expect("CODE 356 shape");
    let mut f = setup(&b).expect("fixture");
    let mut cells = 0usize;
    // 1 is the fresh-start default (`init_fresh_start_globals` sets level = 1),
    // so an unlevelled run must not spray a particle burst.
    for level in [1, 0, -1, 21, 999] {
        for view in VIEWS {
            let cell = Cell {
                view,
                level,
                showpart: 1.0,
                ui: (400.0, 300.0),
                levelup: (100.0, 200.0),
            };
            let obs = observe(&b, &mut f, &cell)
                .unwrap_or_else(|e| panic!("level {level} view {view}: {e}"));
            validate_cell(&live, &cell, &obs)
                .unwrap_or_else(|e| panic!("level {level} view {view}: {e}"));
            assert!(
                obs.particles.is_empty(),
                "level {level} view {view}: no arm matches"
            );
            assert_eq!(
                obs.draws.len(),
                1,
                "level {level} view {view}: draw_self still runs"
            );
            let arms: Vec<&LiveArm> = live.arms.iter().filter(|a| a.view == view).collect();
            assert_eq!(arms.len(), 19);
            let mut checks = 0usize;
            for a in &arms {
                for off in &a.check {
                    assert!(obs.ledger.contains(off),
                        "level {level} view {view}: test instruction {off} must run (all 19 tests are independent ifs)");
                    checks += 1;
                }
                for off in &a.body {
                    assert!(
                        !obs.ledger.contains(off),
                        "level {level} view {view}: arm body instruction {off} must not run"
                    );
                }
            }
            assert_eq!(
                checks,
                19 * 4,
                "level {level} view {view}: all 19 level tests ran"
            );
            cells += 1;
        }
    }
    assert_eq!(cells, 5 * 6);
}

// ---- 4. view 2 does not exist ----------------------------------------------

#[test]
// CODE 356
fn view_two_has_no_block_and_never_even_reads_showpart() {
    let b = bundle();
    let live = derive(&b).expect("CODE 356 shape");
    let mut f = setup(&b).expect("fixture");
    assert!(!VIEWS.contains(&2), "the shipped table has no view 2 block");
    assert!(!ARMS.iter().any(|a| a.0 == 2), "no arm belongs to view 2");
    assert!(!GATES.iter().any(|g| g.0 == 2), "no guard block for view 2");

    for showpart in [1.0, 0.0] {
        for level in [2, 20] {
            let cell = Cell {
                view: 2,
                level,
                showpart,
                ui: (400.0, 300.0),
                levelup: (100.0, 200.0),
            };
            let obs = observe(&b, &mut f, &cell)
                .unwrap_or_else(|e| panic!("view 2 level {level} showpart {showpart}: {e}"));
            validate_cell(&live, &cell, &obs)
                .unwrap_or_else(|e| panic!("view 2 level {level} showpart {showpart}: {e}"));
            assert!(obs.particles.is_empty(), "view 2 level {level}: no burst");
            assert_eq!(
                obs.draws.len(),
                1,
                "view 2 level {level}: draw_self still runs"
            );
            // The `&&` short-circuit: view_current fails first, so `showpart`
            // is never loaded in ANY of the six guards, and each guard leaves
            // through the shared `constant 0` + gate `bf` pair.
            for g in &live.gates {
                assert!(
                    !obs.ledger.contains(&g.showpart_load),
                    "view 2: guard for view {} must not evaluate showpart",
                    g.view
                );
                assert!(
                    obs.ledger.contains(&g.false_const),
                    "view 2: guard for view {} leaves through `constant 0`",
                    g.view
                );
            }
        }
    }
}

// ---- 5. census + chain order ------------------------------------------------

#[test]
// CODE 356
fn the_table_census_matches_the_bytecode() {
    // 114 calls = 6 views x 19 levels.
    assert_eq!(
        ARMS.len(),
        114,
        "CODE {CODE} ships 114 part_particles_create calls"
    );
    let mut pairs: Vec<(i32, i32)> = ARMS.iter().map(|a| (a.0, a.1)).collect();
    assert_eq!(pairs.len(), 114);
    pairs.sort_unstable();
    pairs.dedup();
    assert_eq!(pairs.len(), 114, "every (view, level) cell is distinct");

    // Views: bytecode order 0,1,3,4,5,6 with no view 2.
    let order: Vec<i32> = ARMS.iter().map(|a| a.0).collect();
    let mut expected_order = Vec::new();
    for v in VIEWS {
        expected_order.extend(std::iter::repeat(v).take(19));
    }
    assert_eq!(
        order, expected_order,
        "arms are laid out 19 per view, in guard order"
    );
    let mut views: Vec<i32> = ARMS.iter().map(|a| a.0).collect();
    views.dedup();
    assert_eq!(
        views,
        VIEWS.to_vec(),
        "view blocks are 0,1,3,4,5,6 - view 2 is absent"
    );

    // Levels: 2..=20 exactly, in order, in every block.
    for v in VIEWS {
        let levels: Vec<i32> = ARMS.iter().filter(|a| a.0 == v).map(|a| a.1).collect();
        assert_eq!(
            levels,
            (2..=20).collect::<Vec<i32>>(),
            "view {v} covers levels 2..=20 in order"
        );
    }

    // Offsets: bodies and call sites are unique; bodies are monotonically laid
    // out, so a switch-style arm order equals the run order.
    let bodies: Vec<usize> = ARMS.iter().map(|a| a.4).collect();
    let calls: Vec<usize> = ARMS.iter().map(|a| a.5).collect();
    let mut bs = bodies.clone();
    bs.sort_unstable();
    let mut cs = calls.clone();
    cs.sort_unstable();
    let mut bd = bs.clone();
    bd.dedup();
    let mut cd = cs.clone();
    cd.dedup();
    assert_eq!(bd.len(), 114, "114 distinct arm bodies");
    assert_eq!(
        cd.len(),
        114,
        "114 distinct call sites - no arm shares a burst call"
    );
    assert!(
        bodies.windows(2).all(|w| w[0] < w[1]),
        "arm bodies are in chain order"
    );
    assert!(
        calls.windows(2).all(|w| w[0] < w[1]),
        "call sites are in chain order"
    );
    for a in ARMS.iter() {
        assert_eq!(
            a.5,
            a.4 + 56,
            "view {} level {}: the call sits 56 bytes into the arm body",
            a.0,
            a.1
        );
        assert_eq!(a.4 % 4, 0, "arm bodies are 4-byte aligned");
    }

    // Structural redundancy that is real and worth pinning: views 3 and 4 are
    // byte-identical to each other, and views 5 and 6 are byte-identical to
    // view 0. Two dx arithmetic runs per view, plus one shared row for 19/20,
    // and a per-view dy band with level 19 raised in every block.
    let table = |v: i32| -> Vec<(i32, i32)> {
        ARMS.iter()
            .filter(|a| a.0 == v)
            .map(|a| (a.2, a.3))
            .collect()
    };
    assert_eq!(table(3), table(4), "views 3 and 4 share one offset table");
    assert_eq!(table(5), table(0), "views 5 and 0 share one offset table");
    assert_eq!(table(6), table(0), "views 6 and 0 share one offset table");

    let dx_base = |v: i32| -> (i32, i32) {
        match v {
            0 | 5 | 6 => (104, 58),
            1 => (85, 40),
            3 | 4 => (103, 58),
            other => panic!("no view {other} in CODE {CODE}"),
        }
    };
    let dy_for = |v: i32, level: i32| -> i32 {
        match v {
            0 | 5 | 6 => {
                if level == 19 {
                    20
                } else {
                    30
                }
            }
            1 => {
                if level == 19 {
                    20
                } else {
                    25
                }
            }
            3 | 4 => match level {
                2..=8 => 38,
                9..=18 => 33,
                19 => 23,
                _ => 33,
            },
            other => panic!("no view {other} in CODE {CODE}"),
        }
    };
    for v in VIEWS {
        let (dx2, dx9) = dx_base(v);
        for a in ARMS.iter().filter(|a| a.0 == v) {
            let level = a.1;
            if (2..=8).contains(&level) {
                assert_eq!(
                    a.2,
                    dx2 + 15 * (level - 2),
                    "view {v} level {level}: dx run from {dx2} step 15"
                );
            } else if (9..=18).contains(&level) {
                assert_eq!(
                    a.2,
                    dx9 + 8 * (level - 9),
                    "view {v} level {level}: dx run from {dx9} step 8"
                );
            } else {
                // Levels 19 and 20 share the last column; view 1 sits at 120.
                assert_eq!(
                    a.2,
                    if v == 1 { 120 } else { 138 },
                    "view {v} level {level}: shared 19/20 column"
                );
            }
            assert_eq!(a.3, dy_for(v, level), "view {v} level {level}: y offset");
        }
    }

    // The live instruction stream must agree with this table entry for entry,
    // and the guard table must match the embedded bytecode too.
    let b = bundle();
    let live = derive(&b).expect("CODE 356 shape");
    assert_eq!(live.call_sites.len(), 114);
    let live_calls: Vec<usize> = live.arms.iter().map(|a| a.call_off).collect();
    assert_eq!(
        live_calls, calls,
        "live call sites equal the embedded table"
    );
    for (emb, got) in GATES.iter().zip(live.gates.iter()) {
        assert_eq!(
            (
                got.view,
                got.view_load,
                got.showpart_load,
                got.false_const,
                got.gate_bf,
                got.skip_to
            ),
            *emb,
            "view {} guard matches the embedded bytecode",
            emb.0
        );
    }
    for (emb, got) in ARMS.iter().zip(live.arms.iter()) {
        assert_eq!(
            (
                got.view,
                got.level,
                got.dx,
                got.dy,
                got.body_off,
                got.call_off
            ),
            *emb,
            "view {} level {} arm matches the embedded bytecode",
            emb.0,
            emb.1
        );
    }
    // Every arm loads the same two globals from the same object and asks for 3.
    for a in &live.arms {
        assert_eq!(a.count, 3);
        assert_eq!(a.type_global, "Particle2");
        assert_eq!(a.system_global, "P_System2");
        assert_eq!(a.xy_object, UI);
    }
    // draw_self is called exactly once, above every branch.
    let draw_self_sites = b
        .codes
        .iter()
        .find(|c| c.id == CODE)
        .unwrap()
        .instructions
        .iter()
        .filter(|i| matches!(&i.op, Op::Call { name, .. } if name == "draw_self"))
        .count();
    assert_eq!(
        draw_self_sites, 1,
        "CODE 356 has exactly one draw_self call"
    );
    assert_eq!(
        live.draw_self_off, 0,
        "the self draw is the first instruction, before any gate"
    );
    // Nothing else is called from this body.
    let other_calls: Vec<String> = b
        .codes
        .iter()
        .find(|c| c.id == CODE)
        .unwrap()
        .instructions
        .iter()
        .filter_map(|i| match &i.op {
            Op::Call { name, .. } if name != "draw_self" && name != "part_particles_create" => {
                Some(name.clone())
            }
            _ => None,
        })
        .collect();
    assert!(
        other_calls.is_empty(),
        "CODE 356 calls nothing else: {other_calls:?}"
    );
}

// ---- 6. negative controls ---------------------------------------------------

fn set_constant(b: &mut Bundle, offset: usize, value: f64) -> bool {
    for c in b.codes.iter_mut().filter(|c| c.id == CODE) {
        for i in c.instructions.iter_mut() {
            if i.code_offset == offset {
                if let Op::Constant { value: v } = &mut i.op {
                    *v = value;
                    return true;
                }
                return false;
            }
        }
    }
    false
}

fn set_jump(b: &mut Bundle, offset: usize, target_abs: usize) -> bool {
    for c in b.codes.iter_mut().filter(|c| c.id == CODE) {
        for i in c.instructions.iter_mut() {
            if i.code_offset == offset {
                match &mut i.op {
                    Op::B { target } | Op::Bt { target } | Op::Bf { target } => {
                        *target = target_abs;
                        return true;
                    }
                    _ => return false,
                }
            }
        }
    }
    false
}

fn set_object_sprite(b: &mut Bundle, object: i32, sprite: i32) -> bool {
    for o in b.objects.iter_mut().filter(|o| o.id == object) {
        o.sprite = sprite;
        return true;
    }
    false
}

#[test]
// CODE 356
fn perturbed_bundle_copies_are_rejected_by_the_same_validator() {
    let b = bundle();
    let live = derive(&b).expect("CODE 356 shape");
    let start = b.codes.iter().find(|c| c.id == CODE).unwrap().start;

    // The cells used for the controls: their pristine run must pass, so a
    // rejection below can only come from the perturbation.
    let cases = [
        (
            Cell {
                view: 3,
                level: 12,
                showpart: 1.0,
                ui: (400.0, 300.0),
                levelup: (100.0, 200.0),
            },
            5usize,
        ),
        (
            Cell {
                view: 1,
                level: 5,
                showpart: 1.0,
                ui: (400.0, 300.0),
                levelup: (100.0, 200.0),
            },
            33usize,
        ),
        (
            Cell {
                view: 4,
                level: 7,
                showpart: 1.0,
                ui: (400.0, 300.0),
                levelup: (100.0, 200.0),
            },
            50usize,
        ),
    ];
    for (cell, _) in cases {
        let mut f = setup(&b).expect("fixture");
        let obs = observe(&b, &mut f, &cell).expect("pristine observation");
        validate_cell(&live, &cell, &obs).unwrap_or_else(|e| {
            panic!(
                "pristine view {} level {} must pass: {e}",
                cell.view, cell.level
            )
        });
    }

    // (a) a written value: view 3 level 12's x offset 82 -> 83.
    let cell_a = Cell {
        view: 3,
        level: 12,
        showpart: 1.0,
        ui: (400.0, 300.0),
        levelup: (100.0, 200.0),
    };
    let row_a = ARMS.iter().find(|a| a.0 == 3 && a.1 == 12).unwrap();
    let mut pa = b.clone();
    // the dx constant is the 8th instruction of the body: body + 40
    assert!(
        set_constant(&mut pa, row_a.4 + 40, 83.0),
        "dx constant of view 3 level 12"
    );
    let live_a = derive(&pa).expect("perturbed bundle still decodes");
    let mut fa = setup(&pa).expect("fixture");
    let obs_a = observe(&pa, &mut fa, &cell_a).expect("observation on the perturbed bundle");
    let err_a = validate_cell(&live_a, &cell_a, &obs_a).expect_err("a changed dx must be rejected");
    assert!(
        err_a.contains("view 3 level 12"),
        "rejection names the cell: {err_a}"
    );
    assert_eq!(
        obs_a.particles.len(),
        3,
        "the burst still happens, with the wrong offset"
    );
    assert_eq!(
        obs_a.particles[0].0,
        400.0 + 83.0,
        "the perturbed constant really changed the emission"
    );

    // (b) a written value: view 1 level 5's count 3 -> 4.
    let cell_b = Cell {
        view: 1,
        level: 5,
        showpart: 1.0,
        ui: (400.0, 300.0),
        levelup: (100.0, 200.0),
    };
    let row_b = ARMS.iter().find(|a| a.0 == 1 && a.1 == 5).unwrap();
    let mut pb = b.clone();
    assert!(
        set_constant(&mut pb, row_b.4, 4.0),
        "count constant of view 1 level 5"
    );
    let live_b = derive(&pb).expect("perturbed bundle still decodes");
    let mut fb = setup(&pb).expect("fixture");
    let obs_b = observe(&pb, &mut fb, &cell_b).expect("observation on the perturbed bundle");
    let err_b =
        validate_cell(&live_b, &cell_b, &obs_b).expect_err("a changed count must be rejected");
    assert!(
        err_b.contains("view 1 level 5"),
        "rejection names the cell: {err_b}"
    );
    assert_eq!(
        obs_b.particles.len(),
        4,
        "the perturbed count really changed the emission"
    );

    // (c) a jump inside the arm chain: view 4 level 7's `bf` normally targets
    // level 8's test (check + 88). Re-target it past level 8 (check + 176), so
    // the level 8 test never runs and its burst never happens. The instruction
    // layout is unchanged, so the rejection has to come from the executed-path
    // comparison, not from the decoder.
    let row_c = ARMS.iter().find(|a| a.0 == 4 && a.1 == 7).unwrap();
    let check_c = row_c.4 - 20;
    let cell_c = Cell {
        view: 4,
        level: 8,
        showpart: 1.0,
        ui: (400.0, 300.0),
        levelup: (100.0, 200.0),
    };
    let mut pc = b.clone();
    assert!(
        set_jump(&mut pc, check_c + 16, start + check_c + 176),
        "view 4 level 7 arm bf"
    );
    let live_c = derive(&pc).expect("perturbed bundle still decodes");
    // The same bundle still passes for a cell whose path the jump does not touch.
    let mut fc = setup(&pc).expect("fixture");
    let cell_c_sane = Cell { level: 7, ..cell_c };
    let obs_sane = observe(&pc, &mut fc, &cell_c_sane).expect("observation");
    validate_cell(&live_c, &cell_c_sane, &obs_sane)
        .unwrap_or_else(|e| panic!("the jump must not disturb view 4 level 7: {e}"));
    let obs_c = observe(&pc, &mut fc, &cell_c).expect("observation on the perturbed bundle");
    let err_c =
        validate_cell(&live_c, &cell_c, &obs_c).expect_err("a re-targeted arm jump must be rejected");
    assert!(
        err_c.contains("view 4 level 8"),
        "rejection names the cell: {err_c}"
    );
    assert!(
        obs_c.particles.is_empty(),
        "the re-targeted arm jump really skipped the level 8 burst"
    );

    // (d) a jump in the guard: view 4's gate `bf` (only taken when
    // `showpart != 1`) re-targeted to view 6's guard. With showpart == 1 that
    // branch is not taken, so the burst still fires - which is exactly why the
    // rejection here must come from the bytecode cross-check, and why the
    // oracle checks both halves instead of only counting particles.
    let mut pd = b.clone();
    assert!(set_jump(&mut pd, 5228, start + 8632), "view 4 gate bf");
    let live_d = derive(&pd).expect("perturbed bundle still decodes");
    let mut fd = setup(&pd).expect("fixture");
    let obs_d = observe(&pd, &mut fd, &cell_c).expect("observation on the perturbed bundle");
    let err_d = validate_cell(&live_d, &cell_c, &obs_d)
        .expect_err("a re-targeted guard jump must be rejected");
    assert!(
        err_d.contains("view 4 level 8") && err_d.contains("guard"),
        "rejection names the guard and the cell: {err_d}"
    );
    assert_eq!(
        obs_d.particles.len(),
        3,
        "showpart == 1 never takes the gate bf, so the burst is untouched"
    );

    // (e) a drawing parameter: obj_levelup's sprite 35 -> 34. The instruction
    // stream is untouched, so only the behavioural half of the oracle can catch
    // this: it must not read its expectation back out of the perturbed bundle.
    let cell_e = Cell {
        view: 0,
        level: 2,
        showpart: 1.0,
        ui: (400.0, 300.0),
        levelup: (100.0, 200.0),
    };
    let mut pe = b.clone();
    assert!(
        set_object_sprite(&mut pe, LEVELUP, 34),
        "obj_levelup sprite"
    );
    let live_e = derive(&pe).expect("perturbed bundle still decodes");
    let mut fe = setup(&pe).expect("fixture");
    let obs_e = observe(&pe, &mut fe, &cell_e).expect("observation on the perturbed bundle");
    let err_e = validate_cell(&live_e, &cell_e, &obs_e)
        .expect_err("a changed draw sprite must be rejected");
    assert!(
        err_e.contains("sprite 34"),
        "rejection names the observed sprite: {err_e}"
    );
    assert_eq!(obs_e.draws.len(), 1, "draw_self still ran once");
    assert_eq!(
        obs_e.draws[0].0, 34,
        "the perturbed sprite really reached the draw queue"
    );
}
