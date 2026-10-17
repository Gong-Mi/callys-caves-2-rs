//! Arm-level branch coverage for CODE 674 (gml_Object_obj_lloyd_Alarm_0), the
//! Lloyd retirement table: 17 independent `if (room == K) { if (global.FLAG ==
//! 1) instance_destroy(); }` blocks over 16 distinct rooms.
//!
//! Unlike the eight flat `switch (room)` Create tables of PR #121 this body is
//! NOT a switch: there is no `dup`/`bt` chain, no catch-all body and no shared
//! exit. Every block is a self-contained 52-byte unit
//!
//!     +0  load room            (builtin, selector -1)
//!     +8  constant K
//!     +12 cmp 3 (==)
//!     +16 bf  NEXT             <- room gate
//!     +20 load FLAG            (global, selector -5)
//!     +28 constant 1
//!     +32 cmp 3 (==)
//!     +36 bf  NEXT             <- flag gate
//!     +40 call instance_destroy argc 0
//!     +48 popz                 <- discards the call's return value
//!     NEXT: next block head, or the body end after the last arm
//!
//! so the 17 blocks execute in sequence and do NOT exclude each other: with a
//! room that matches two blocks (rm_level1 does - see the duplicate arm below)
//! both gates are evaluated. Only the taken arms' `instance_destroy`/`popz`
//! pair runs; every block's room gate runs on every dispatch, which is what
//! this suite reads back from the engine's own instruction ledger.
//!
//! Provenance of the expected table below (bytecode is authoritative - the
//! recovered GML is a semantic reference, never the source of an expected
//! value):
//!   * IR: `crates/core/src/generated/full_ir.json` CODE 674, span
//!     5014336..5015220 (884 bytes = 17 x 52 = 170 instructions), IR sha256
//!     ffef7314959a84c1951ceeaa5155cbc23e18290f3268b26107c9329239d013ed. The
//!     constants/offsets below were extracted programmatically (scratch, not
//!     checked in: `wl52-lloydretire_extract.py`), never transcribed.
//!   * Asset anchor: `python3 scripts/reverse_code.py assets/game.droid
//!     --output <scratch>/wl52_code_ledger.json` emits the disassembly header
//!     `CODE 674 gml_Object_obj_lloyd_Alarm_0` at 0x004c8340 = 5014336 (the IR
//!     start) and the last arm's `bf target=004c86b4` = 5015220 (the IR end),
//!     with 170 instructions between that header and CODE 675's. So the table
//!     is anchored to the shipped chunk, not only to the IR file.
//!   * Semantic reference: `~/cally-recovered-gml-0ca243a/restored-source/gml/
//!     0674__gml_Object_obj_lloyd_Alarm_0.gml` lists the same 17 blocks in the
//!     same order; its room NAMES (rm_town, rm_level1 x2, rm_level2, rm_level5,
//!     rm_boss1, rm_level9, rm_level13, rm_level14a, rm_boss2, room42, room55,
//!     room103, rm_level7, room46, rm_level4, rm_challenge1) map through the
//!     bundle's own `room_bindings` to exactly the 16 room constants the IR
//!     tests - `the_room_names_backing_each_arm_match_the_recovered_gml`
//!     re-checks that at runtime, so a name/constant drift cannot hide.
//!
//! Arm census (re-derived from the live instruction stream by
//! `..._rederives_from_the_live_instruction_stream`, not copied from a note):
//!   * 17 arms, 16 distinct room constants, 17 distinct flag names.
//!   * Exactly one repeated constant: room 1 (rm_level1) is gated twice, arm 1
//!     on `talkedtolloyd2` and arm 2 on `shotgunbought` - two independent
//!     retirement gates for the same room, which
//!     `the_two_rm_level1_gates_fire_independently_and_the_first_wins` drives
//!     separately.
//!   * The chain is NOT sorted: arms 12/13 go room 103 -> room 7, and the tail
//!     ends on rm_challenge1 (105). Bytecode order is kept verbatim here.
//!   * There is no fall-through/catch-all region at all: 17 x 52 = 884 covers
//!     the whole span and the re-derivation consumes all 170 instructions, so
//!     an unmatched room simply skips all 17 arms and reads no flag.
//!
//! Fixture: the body is alarm[0] of obj_lloyd (event 2/0, parent_chain empty),
//! driven directly with `s.dispatch(&b, LLOYD, 2, 0)` after pinning
//! `Scene::current_room` and the arm's global flag - the same convention as
//! `lloyd_tutorial_ir.rs`. One extra test fires every arm through the real
//! alarm scheduler (`Scene::tick`, fed by the `alarm[0] = 1` that CODE 670's
//! Create arms) instead of dispatching by hand.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::path::Path;

/// obj_lloyd (object table entry 154, sprite 1, non-persistent, no parent).
const LLOYD: i32 = 154;
/// The Destroy event that `instance_destroy` runs (mouse_clear(-1)).
const LLOYD_DESTROY: usize = 671;

// CODE 674 layout, from full_ir.json (start/end re-checked at runtime).
const LLOYD_CODE: usize = 674;
const CODE_START: usize = 5_014_336;
const CODE_END: usize = 5_015_220;
/// Each block is exactly 52 bytes; the ten block-relative instruction offsets.
const BLOCK_LEN: usize = 52;
const D_ROOM_CONST: usize = 8;
const D_ROOM_CMP: usize = 12;
const D_ROOM_BF: usize = 16;
const D_FLAG_LOAD: usize = 20;
const D_FLAG_CONST: usize = 28;
const D_FLAG_CMP: usize = 32;
const D_FLAG_BF: usize = 36;
const D_DESTROY: usize = 40;
const D_POPZ: usize = 48;

/// One arm of CODE 674's retirement table, in bytecode order.
#[derive(Debug, Clone, Copy)]
struct Arm {
    /// The room constant the arm's room gate compares against.
    room: i32,
    /// The room's name in the recovered GML, cross-checked against the
    /// bundle's `room_bindings` (rm_level1 appears twice - two arms).
    room_name: &'static str,
    /// The global flag the arm's second gate reads.
    flag: &'static str,
    /// Absolute offset of `load room` (the block head).
    block: usize,
    /// Absolute offset of the room gate's `bf`.
    room_bf: usize,
    /// Absolute offset of the flag gate's `bf`.
    flag_bf: usize,
    /// Absolute offset of `call instance_destroy`.
    destroy: usize,
    /// Absolute offset of the block's `popz`.
    popz: usize,
}

// ---- extracted arm table (generated from full_ir.json CODE 674) ----
//
// Extracted by `wl52-lloydretire_extract.py` (scratch, not checked in) walking
// the live instruction stream; the offset columns are re-derived from the
// bundle at test time, never trusted as prose.
#[rustfmt::skip]
const ARMS: [Arm; 17] = [
    Arm { room:   0, room_name: "rm_town",       flag: "talkedtolloyd1",  block: 5_014_336, room_bf: 5_014_352, flag_bf: 5_014_372, destroy: 5_014_376, popz: 5_014_384 }, // CODE 674 arm 0
    Arm { room:   1, room_name: "rm_level1",     flag: "talkedtolloyd2",  block: 5_014_388, room_bf: 5_014_404, flag_bf: 5_014_424, destroy: 5_014_428, popz: 5_014_436 }, // CODE 674 arm 1
    Arm { room:   1, room_name: "rm_level1",     flag: "shotgunbought",   block: 5_014_440, room_bf: 5_014_456, flag_bf: 5_014_476, destroy: 5_014_480, popz: 5_014_488 }, // CODE 674 arm 2
    Arm { room:   2, room_name: "rm_level2",     flag: "talkedtolloyd3",  block: 5_014_492, room_bf: 5_014_508, flag_bf: 5_014_528, destroy: 5_014_532, popz: 5_014_540 }, // CODE 674 arm 3
    Arm { room:   5, room_name: "rm_level5",     flag: "talkedtolloyd4",  block: 5_014_544, room_bf: 5_014_560, flag_bf: 5_014_580, destroy: 5_014_584, popz: 5_014_592 }, // CODE 674 arm 4
    Arm { room:  10, room_name: "rm_boss1",      flag: "talkedtolloyd5",  block: 5_014_596, room_bf: 5_014_612, flag_bf: 5_014_632, destroy: 5_014_636, popz: 5_014_644 }, // CODE 674 arm 5
    Arm { room:  11, room_name: "rm_level9",     flag: "talkedtolloyd6",  block: 5_014_648, room_bf: 5_014_664, flag_bf: 5_014_684, destroy: 5_014_688, popz: 5_014_696 }, // CODE 674 arm 6
    Arm { room:  17, room_name: "rm_level13",    flag: "talkedtolloyd7",  block: 5_014_700, room_bf: 5_014_716, flag_bf: 5_014_736, destroy: 5_014_740, popz: 5_014_748 }, // CODE 674 arm 7
    Arm { room:  20, room_name: "rm_level14a",   flag: "talkedtolloyd8",  block: 5_014_752, room_bf: 5_014_768, flag_bf: 5_014_788, destroy: 5_014_792, popz: 5_014_800 }, // CODE 674 arm 8
    Arm { room:  27, room_name: "rm_boss2",      flag: "talkedtolloyd9",  block: 5_014_804, room_bf: 5_014_820, flag_bf: 5_014_840, destroy: 5_014_844, popz: 5_014_852 }, // CODE 674 arm 9
    Arm { room:  39, room_name: "room42",        flag: "talkedtolloyd10", block: 5_014_856, room_bf: 5_014_872, flag_bf: 5_014_892, destroy: 5_014_896, popz: 5_014_904 }, // CODE 674 arm 10
    Arm { room:  53, room_name: "room55",        flag: "talkedtolloyd11", block: 5_014_908, room_bf: 5_014_924, flag_bf: 5_014_944, destroy: 5_014_948, popz: 5_014_956 }, // CODE 674 arm 11
    Arm { room: 103, room_name: "room103",       flag: "talkedtolloyd12", block: 5_014_960, room_bf: 5_014_976, flag_bf: 5_014_996, destroy: 5_015_000, popz: 5_015_008 }, // CODE 674 arm 12
    Arm { room:   7, room_name: "rm_level7",     flag: "talkedtolloyd13", block: 5_015_012, room_bf: 5_015_028, flag_bf: 5_015_048, destroy: 5_015_052, popz: 5_015_060 }, // CODE 674 arm 13
    Arm { room:  43, room_name: "room46",        flag: "talkedtolloyd14", block: 5_015_064, room_bf: 5_015_080, flag_bf: 5_015_100, destroy: 5_015_104, popz: 5_015_112 }, // CODE 674 arm 14
    Arm { room:   4, room_name: "rm_level4",     flag: "talkedtolloyd15", block: 5_015_116, room_bf: 5_015_132, flag_bf: 5_015_152, destroy: 5_015_156, popz: 5_015_164 }, // CODE 674 arm 15
    Arm { room: 105, room_name: "rm_challenge1", flag: "talkedtolloyd16", block: 5_015_168, room_bf: 5_015_184, flag_bf: 5_015_204, destroy: 5_015_208, popz: 5_015_216 }, // CODE 674 arm 16
];

// ---- fixture ---------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s
}

/// Spawn obj_lloyd (which runs its own Create, CODE 670), normalise all 17 arm
/// flags to the requested values, pin the room and clear the ledger. The
/// returned id is the instance the body will retire (or spare).
fn lloyd_in(b: &Bundle, s: &mut Scene, room: i32, flags: &[(&str, f64)]) -> i32 {
    let id = s.create(b, LLOYD, 0.0, 0.0).expect("create obj_lloyd");
    for arm in ARMS.iter() {
        s.globals.insert(arm.flag.into(), 0.0);
    }
    for (name, value) in flags {
        s.globals.insert((*name).into(), *value);
    }
    s.current_room = f64::from(room);
    s.executed.clear();
    id
}

fn alive(s: &Scene, id: i32) -> bool {
    s.instances.get(&id).map(|i| i.alive).unwrap_or(false)
}

/// Every instruction the VM entered for one CODE body, absolute offsets, in
/// execution order.
fn ledger(s: &Scene, code: usize) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(c, _)| *c == code)
        .map(|(_, o)| *o)
        .collect()
}

/// The exact instruction trace CODE 674 must produce. Every block's room gate
/// always runs (the blocks are independent, so nothing short-circuits the
/// chain, even after an arm has fired), `flag_tests` lists the arms whose flag
/// gate is reached - every arm sharing the pinned room, since the flag gate
/// sits behind that arm's own room gate - and `effects` the arms whose
/// `instance_destroy`/`popz` pair actually runs.
fn expected_trace(flag_tests: &[usize], effects: &[usize]) -> Vec<usize> {
    let mut out = Vec::new();
    for (j, a) in ARMS.iter().enumerate() {
        out.push(a.block);
        out.push(a.block + D_ROOM_CONST);
        out.push(a.block + D_ROOM_CMP);
        out.push(a.room_bf);
        if flag_tests.contains(&j) {
            out.push(a.block + D_FLAG_LOAD);
            out.push(a.block + D_FLAG_CONST);
            out.push(a.block + D_FLAG_CMP);
            out.push(a.flag_bf);
        }
        if effects.contains(&j) {
            out.push(a.destroy);
            out.push(a.popz);
        }
    }
    out
}

/// The arms whose room gate passes when `room` is pinned: their flag gates are
/// the ones reached. rm_level1 (room 1) has two such arms.
fn arms_gated_on(room: i32) -> Vec<usize> {
    ARMS.iter()
        .enumerate()
        .filter(|(_, a)| a.room == room)
        .map(|(j, _)| j)
        .collect()
}

// ---- re-derivation from the live instruction stream ------------------------

/// The ten instruction offsets of one arm, read off the bundle's live body.
#[derive(Debug, PartialEq)]
struct LiveArm {
    room: i32,
    flag: String,
    offs: [usize; 10],
}

fn constant(i: &Instruction) -> Option<f64> {
    if let Op::Constant { value } = i.op {
        Some(value)
    } else {
        None
    }
}

fn bf_target(i: &Instruction) -> Option<usize> {
    if let Op::Bf { target } = i.op {
        Some(target)
    } else {
        None
    }
}

fn builtin_load(i: &Instruction) -> Option<&str> {
    if let Op::Load {
        name, selector: -1, ..
    } = &i.op
    {
        Some(name.as_str())
    } else {
        None
    }
}

fn global_load(i: &Instruction) -> Option<&str> {
    if let Op::Load {
        name, selector: -5, ..
    } = &i.op
    {
        Some(name.as_str())
    } else {
        None
    }
}

fn cmp_eq(i: &Instruction) -> bool {
    matches!(i.op, Op::Cmp { comparison: 3 })
}

/// Decode every arm out of the bundle's own instruction stream and assert the
/// ten-instruction block shape + the `bf NEXT` chain. Panics (rather than
/// returning an error) so a drifted body fails as a fixture error.
fn live_arms(b: &Bundle) -> (Vec<LiveArm>, usize, usize) {
    let code = b
        .codes
        .iter()
        .find(|c| c.id == LLOYD_CODE)
        .unwrap_or_else(|| panic!("CODE {LLOYD_CODE} must exist in the bundle"));
    let ins = &code.instructions;
    assert_eq!(
        ins.len() % 10,
        0,
        "CODE {LLOYD_CODE} must be a whole number of ten-instruction blocks"
    );
    let mut arms = Vec::new();
    let mut i = 0;
    while i < ins.len() {
        let b0 = &ins[i];
        assert_eq!(
            builtin_load(b0),
            Some("room"),
            "CODE {LLOYD_CODE} arm {}: block head must be `load room`",
            arms.len()
        );
        let room = constant(&ins[i + 1]).unwrap_or_else(|| {
            panic!(
                "CODE {LLOYD_CODE} arm {}: room constant expected",
                arms.len()
            )
        });
        assert!(
            cmp_eq(&ins[i + 2]),
            "CODE {LLOYD_CODE} arm {}: the room gate must be a cmp(==)",
            arms.len()
        );
        let room_bf = &ins[i + 3];
        let room_bf_off = bf_target(&room_bf).unwrap_or_else(|| {
            panic!(
                "CODE {LLOYD_CODE} arm {}: the room gate must end in bf",
                arms.len()
            )
        });
        let flag = global_load(&ins[i + 4])
            .unwrap_or_else(|| panic!("CODE {LLOYD_CODE} arm {}: flag read expected", arms.len()));
        assert_eq!(
            constant(&ins[i + 5]),
            Some(1.0),
            "CODE {LLOYD_CODE} arm {}: the flag gate compares against 1",
            arms.len()
        );
        assert!(
            cmp_eq(&ins[i + 6]),
            "CODE {LLOYD_CODE} arm {}: the flag gate must be a cmp(==)",
            arms.len()
        );
        let flag_bf = &ins[i + 7];
        let flag_bf_off = bf_target(&flag_bf).unwrap_or_else(|| {
            panic!(
                "CODE {LLOYD_CODE} arm {}: the flag gate must end in bf",
                arms.len()
            )
        });
        assert!(
            matches!(&ins[i + 8].op, Op::Call { name, argc: 0 } if name == "instance_destroy"),
            "CODE {LLOYD_CODE} arm {}: the effect is instance_destroy() with no args",
            arms.len()
        );
        assert!(
            matches!(ins[i + 9].op, Op::Popz),
            "CODE {LLOYD_CODE} arm {}: the effect's return value is dropped by popz",
            arms.len()
        );
        arms.push(LiveArm {
            room: room as i32,
            flag: flag.to_string(),
            offs: [
                b0.offset,
                ins[i + 1].offset,
                ins[i + 2].offset,
                room_bf.offset,
                ins[i + 4].offset,
                ins[i + 5].offset,
                ins[i + 6].offset,
                flag_bf.offset,
                ins[i + 8].offset,
                ins[i + 9].offset,
            ],
        });
        // Every gate jumps to its own next block head (the last one to the body
        // end): no block can skip another, and there is no catch-all region.
        let next = if i + 10 < ins.len() {
            ins[i + 10].offset
        } else {
            code.end
        };
        assert_eq!(
            room_bf_off,
            next,
            "CODE {LLOYD_CODE} arm {}: the room gate must branch to the next block head",
            arms.len() - 1
        );
        assert_eq!(
            flag_bf_off,
            next,
            "CODE {LLOYD_CODE} arm {}: the flag gate must branch to the next block head",
            arms.len() - 1
        );
        i += 10;
    }
    (arms, code.start, code.end)
}

// ---- identity + table re-derivation ---------------------------------------

#[test]
// CODE 674
// CODE 670
// CODE 671
fn the_retirement_table_rederives_from_the_live_instruction_stream() {
    let b = bundle();
    // Body identity: CODE 674 is obj_lloyd's alarm[0], and obj_lloyd has no
    // parent, so a dispatch of event 2/0 runs CODE 674 and nothing inherited.
    let lloyd = b
        .objects
        .iter()
        .find(|o| o.id == LLOYD)
        .expect("obj_lloyd in the object table");
    assert_eq!(lloyd.name, "obj_lloyd");
    assert!(
        lloyd.parent_chain.is_empty(),
        "obj_lloyd inherits no events"
    );
    let alarm0 = lloyd
        .events
        .iter()
        .find(|e| e.event_type == 2 && e.subtype == 0)
        .unwrap_or_else(|| panic!("CODE {LLOYD_CODE} hangs off obj_lloyd alarm[0]"));
    assert_eq!(
        alarm0.codes,
        vec![LLOYD_CODE],
        "obj_lloyd alarm[0] is CODE {LLOYD_CODE} alone"
    );
    assert!(
        lloyd
            .events
            .iter()
            .any(|e| e.event_type == 1 && e.codes.contains(&LLOYD_DESTROY)),
        "CODE {LLOYD_DESTROY} is obj_lloyd's Destroy event, i.e. what instance_destroy runs"
    );

    let (live, start, end) = live_arms(&b);
    assert_eq!(
        start, CODE_START,
        "CODE {LLOYD_CODE} starts at the extracted offset"
    );
    assert_eq!(
        end, CODE_END,
        "CODE {LLOYD_CODE} ends at the extracted offset"
    );
    assert_eq!(
        live.len(),
        ARMS.len(),
        "CODE {LLOYD_CODE}: the embedded table must cover every arm of the live body"
    );
    // Exhaustive span: 17 blocks x 52 bytes is the whole body, so nothing is
    // left over for a default/catch-all region.
    assert_eq!(
        end - start,
        ARMS.len() * BLOCK_LEN,
        "CODE {LLOYD_CODE} span arithmetic"
    );
    for (j, (arm, got)) in ARMS.iter().zip(live.iter()).enumerate() {
        assert_eq!(
            got.room, arm.room,
            "CODE {LLOYD_CODE} arm {j}: room constant differs from the extracted table"
        );
        assert_eq!(
            got.flag, arm.flag,
            "CODE {LLOYD_CODE} arm {j}: flag name differs from the extracted table"
        );
        let expect = [
            arm.block,
            arm.block + D_ROOM_CONST,
            arm.block + D_ROOM_CMP,
            arm.room_bf,
            arm.block + D_FLAG_LOAD,
            arm.block + D_FLAG_CONST,
            arm.block + D_FLAG_CMP,
            arm.flag_bf,
            arm.destroy,
            arm.popz,
        ];
        assert_eq!(
            got.offs, expect,
            "CODE {LLOYD_CODE} arm {j}: the live ten-instruction block layout differs from the \
             extracted offsets (the 52-byte stride assumption is checked here)"
        );
    }
}

#[test]
// CODE 674
fn the_room_names_backing_each_arm_match_the_recovered_gml() {
    let b = bundle();
    for (j, arm) in ARMS.iter().enumerate() {
        let bound: Vec<&str> = b
            .room_bindings
            .iter()
            .filter(|r| r.room_id == arm.room as usize)
            .map(|r| r.room_name.as_str())
            .collect();
        assert!(
            !bound.is_empty(),
            "CODE {LLOYD_CODE} arm {j}: room {} must be a bound room",
            arm.room
        );
        assert!(
            bound.iter().all(|n| *n == arm.room_name),
            "CODE {LLOYD_CODE} arm {j}: room {} is bound to {bound:?}, but the recovered GML names \
             this arm's room {}",
            arm.room,
            arm.room_name
        );
    }
}

// ---- arm census ------------------------------------------------------------

#[test]
// CODE 674
fn the_arm_census_matches_the_bytecode_chain() {
    let rooms: Vec<i32> = ARMS.iter().map(|a| a.room).collect();
    assert_eq!(
        rooms.len(),
        17,
        "CODE {LLOYD_CODE} ships 17 retirement arms"
    );
    let mut distinct = rooms.clone();
    distinct.sort_unstable();
    distinct.dedup();
    assert_eq!(
        distinct.len(),
        16,
        "CODE {LLOYD_CODE}: 17 arms over 16 distinct rooms"
    );
    // Bytecode order, verbatim - and deliberately not sorted (103 -> 7 in the
    // tail, then rm_challenge1 last).
    assert_eq!(
        rooms,
        vec![0, 1, 1, 2, 5, 10, 11, 17, 20, 27, 39, 53, 103, 7, 43, 4, 105],
        "CODE {LLOYD_CODE} tests the rooms in this order"
    );
    assert!(
        rooms.windows(2).any(|w| w[0] > w[1]),
        "CODE {LLOYD_CODE}'s chain is not sorted, so it is a hand-written if-block series, not a \
         generated ramp"
    );
    let repeats: Vec<i32> = distinct
        .iter()
        .copied()
        .filter(|r| rooms.iter().filter(|x| *x == r).count() > 1)
        .collect();
    assert_eq!(
        repeats,
        vec![1],
        "CODE {LLOYD_CODE}: rm_level1 (room 1) is the only room gated twice"
    );
    assert_eq!(ARMS[1].room, 1);
    assert_eq!(ARMS[2].room, 1);
    assert_ne!(
        ARMS[1].flag, ARMS[2].flag,
        "CODE {LLOYD_CODE}'s two rm_level1 arms must read different flags"
    );
    let mut flags: Vec<&str> = ARMS.iter().map(|a| a.flag).collect();
    flags.sort_unstable();
    flags.dedup();
    assert_eq!(flags.len(), 17, "CODE {LLOYD_CODE}: 17 distinct flag names");
    // Block geometry: contiguous 52-byte units whose gates sit at their fixed
    // block-relative offsets. The branch targets themselves (each gate jumping
    // to the next block head, the last one out of the body) are checked against
    // the live instruction stream in
    // `the_retirement_table_rederives_from_the_live_instruction_stream`.
    for (j, pair) in ARMS.windows(2).enumerate() {
        assert_eq!(
            pair[1].block - pair[0].block,
            BLOCK_LEN,
            "CODE {LLOYD_CODE} arm {j}: blocks are contiguous 52-byte units"
        );
    }
    let last = ARMS[ARMS.len() - 1];
    assert_eq!(
        last.block + BLOCK_LEN,
        CODE_END,
        "CODE {LLOYD_CODE}'s last block ends at the body end"
    );
    for (j, arm) in ARMS.iter().enumerate() {
        assert_eq!(
            arm.room_bf - arm.block,
            D_ROOM_BF,
            "CODE {LLOYD_CODE} arm {j}"
        );
        assert_eq!(
            arm.flag_bf - arm.block,
            D_FLAG_BF,
            "CODE {LLOYD_CODE} arm {j}"
        );
        assert_eq!(
            arm.destroy - arm.block,
            D_DESTROY,
            "CODE {LLOYD_CODE} arm {j}"
        );
        assert_eq!(arm.popz - arm.block, D_POPZ, "CODE {LLOYD_CODE} arm {j}");
    }
    // Rooms the table does not gate are real rooms (not invented values), so the
    // negative case below is a real "Lloyd is not retired here" statement.
    let bound: std::collections::BTreeSet<i32> = b_rooms();
    for room in [3, 6, 8, 9, 12, 110] {
        assert!(
            bound.contains(&room) && !distinct.contains(&room),
            "CODE {LLOYD_CODE}: room {room} must be a real room this table does not gate"
        );
    }
}

fn b_rooms() -> std::collections::BTreeSet<i32> {
    bundle()
        .room_bindings
        .iter()
        .map(|r| r.room_id as i32)
        .collect()
}

// ---- per-arm behaviour -----------------------------------------------------

#[test]
// CODE 674
fn every_arm_retires_lloyd_under_its_own_room_and_flag() {
    let b = bundle();
    let mut s = scene(&b);
    for (j, arm) in ARMS.iter().enumerate() {
        let id = lloyd_in(&b, &mut s, arm.room, &[(arm.flag, 1.0)]);
        s.dispatch(&b, id, 2, 0).unwrap_or_else(|e| {
            panic!(
                "CODE {LLOYD_CODE} arm {j} (room {} {}): {e}",
                arm.room, arm.room_name
            )
        });
        assert!(
            !alive(&s, id),
            "CODE {LLOYD_CODE} arm {j}: room {} with {} = 1 retires Lloyd",
            arm.room,
            arm.flag
        );
        // Exactly this arm's effect ran: the other 16 gates are evaluated but
        // their instance_destroy/popz pairs must not be.
        let trace = ledger(&s, LLOYD_CODE);
        assert_eq!(
            trace,
            expected_trace(&arms_gated_on(arm.room), &[j]),
            "CODE {LLOYD_CODE} arm {j} (room {} {}): the instruction trace must be the 17 room \
             gates plus this arm alone",
            arm.room,
            arm.room_name
        );
        assert_eq!(
            trace.iter().filter(|o| **o == arm.destroy).count(),
            1,
            "CODE {LLOYD_CODE} arm {j}: exactly one instance_destroy call site runs"
        );
        // The Destroy event the call triggers is obj_lloyd's own CODE 671.
        let destroyed = ledger(&s, LLOYD_DESTROY);
        assert_eq!(
            destroyed.len(),
            b.codes
                .iter()
                .find(|c| c.id == LLOYD_DESTROY)
                .expect("CODE 671")
                .instructions
                .len(),
            "CODE {LLOYD_CODE} arm {j}: the retirement runs obj_lloyd's Destroy event once"
        );
    }
}

#[test]
// CODE 674
fn every_arm_spares_lloyd_while_its_flag_is_low() {
    let b = bundle();
    let mut s = scene(&b);
    for (j, arm) in ARMS.iter().enumerate() {
        let id = lloyd_in(&b, &mut s, arm.room, &[]);
        s.dispatch(&b, id, 2, 0).unwrap_or_else(|e| {
            panic!(
                "CODE {LLOYD_CODE} arm {j} (room {} {}): {e}",
                arm.room, arm.room_name
            )
        });
        assert!(
            alive(&s, id),
            "CODE {LLOYD_CODE} arm {j}: room {} with {} = 0 keeps Lloyd",
            arm.room,
            arm.flag
        );
        // The room gate still passed, so this arm's flag IS read (and the bf
        // taken); no effect may run anywhere in the chain.
        assert_eq!(
            ledger(&s, LLOYD_CODE),
            expected_trace(&arms_gated_on(arm.room), &[]),
            "CODE {LLOYD_CODE} arm {j} (room {} {}): the flag gate must be read and rejected \
             without running any effect",
            arm.room,
            arm.room_name
        );
        assert!(
            ledger(&s, LLOYD_DESTROY).is_empty(),
            "CODE {LLOYD_CODE} arm {j}: no Destroy event may run for a spared Lloyd"
        );
    }
}

#[test]
// CODE 674
fn every_arm_fires_through_the_real_alarm_scheduler() {
    // CODE 670's Create arms alarm[0] = 1, so one tick dispatches CODE 674 by
    // itself - the same arm must fire without a hand dispatch.
    let b = bundle();
    let mut s = scene(&b);
    for (j, arm) in ARMS.iter().enumerate() {
        let id = lloyd_in(&b, &mut s, arm.room, &[(arm.flag, 1.0)]);
        assert_eq!(
            s.instances[&id].alarms[0], 1,
            "CODE 670 arms obj_lloyd's alarm[0], the {LLOYD_CODE} slot"
        );
        s.tick(&b)
            .unwrap_or_else(|e| panic!("CODE {LLOYD_CODE} arm {j} via the scheduler: {e}"));
        assert!(
            !alive(&s, id),
            "CODE {LLOYD_CODE} arm {j}: room {} with {} = 1 retires Lloyd on the alarm tick",
            arm.room,
            arm.flag
        );
        assert_eq!(
            ledger(&s, LLOYD_CODE),
            expected_trace(&arms_gated_on(arm.room), &[j]),
            "CODE {LLOYD_CODE} arm {j}: the scheduler-driven trace matches the direct dispatch"
        );
    }
    // Control: the same tick with the flag low must consume the alarm and keep
    // Lloyd alive, and a second tick must not replay it.
    let arm = ARMS[0];
    let id = lloyd_in(&b, &mut s, arm.room, &[]);
    s.tick(&b).expect("alarm tick");
    assert!(
        alive(&s, id),
        "CODE {LLOYD_CODE}: room {} with {} = 0 survives the alarm tick",
        arm.room,
        arm.flag
    );
    s.tick(&b).expect("second tick");
    assert!(
        alive(&s, id),
        "CODE {LLOYD_CODE}: the alarm is consumed, not re-armed"
    );
}

// ---- the repeated constant -------------------------------------------------

#[test]
// CODE 674
fn the_two_rm_level1_gates_fire_independently_and_the_first_wins() {
    let b = bundle();
    let mut s = scene(&b);
    let (first, second) = (ARMS[1], ARMS[2]);
    assert_eq!((first.room, second.room), (1, 1));
    assert_eq!(first.room_name, "rm_level1");
    // The two arms are genuinely independent: only the gate whose flag is set
    // may run an effect.
    for (name, fired) in [(first.flag, 1usize), (second.flag, 2usize)] {
        let flags = [
            (first.flag, if fired == 1 { 1.0 } else { 0.0 }),
            (second.flag, if fired == 2 { 1.0 } else { 0.0 }),
        ];
        let id = lloyd_in(&b, &mut s, 1, &flags);
        s.dispatch(&b, id, 2, 0).expect("rm_level1 gate");
        assert!(
            !alive(&s, id),
            "CODE {LLOYD_CODE}: rm_level1/{name} retires Lloyd"
        );
        let trace = ledger(&s, LLOYD_CODE);
        assert_eq!(
            trace,
            expected_trace(&[1, 2], &[fired]),
            "CODE {LLOYD_CODE}: rm_level1 evaluates both room gates, but only the {name} effect \
             runs"
        );
        assert_eq!(
            ledger(&s, LLOYD_DESTROY).len(),
            b.codes
                .iter()
                .find(|c| c.id == LLOYD_DESTROY)
                .expect("CODE 671")
                .instructions
                .len(),
            "CODE {LLOYD_CODE}: one retirement, one Destroy event"
        );
    }
    // Both flags set: the blocks do not exclude each other, so BOTH
    // instance_destroy call sites execute. The first one wins in effect - the
    // second is a no-op because Scene::destroy early-returns on a dead
    // instance - which is visible as a single Destroy event run.
    let id = lloyd_in(&b, &mut s, 1, &[(first.flag, 1.0), (second.flag, 1.0)]);
    s.dispatch(&b, id, 2, 0).expect("both rm_level1 gates");
    assert!(
        !alive(&s, id),
        "CODE {LLOYD_CODE}: both rm_level1 gates retire Lloyd"
    );
    let trace = ledger(&s, LLOYD_CODE);
    assert_eq!(
        trace,
        expected_trace(&[1, 2], &[1, 2]),
        "CODE {LLOYD_CODE}: with both rm_level1 flags set the trace runs both effect pairs in \
         bytecode order"
    );
    let destroy_len = b
        .codes
        .iter()
        .find(|c| c.id == LLOYD_DESTROY)
        .expect("CODE 671")
        .instructions
        .len();
    assert_eq!(
        ledger(&s, LLOYD_DESTROY).len(),
        destroy_len,
        "CODE {LLOYD_CODE}: the second instance_destroy on the already-dead instance must not run \
         the Destroy event a second time ({} instructions, not {})",
        destroy_len,
        2 * destroy_len
    );
}

// ---- unmatched rooms -------------------------------------------------------

#[test]
// CODE 674
fn an_unmatched_room_retires_nobody_and_reads_no_flag() {
    let b = bundle();
    let mut s = scene(&b);
    let every_flag: Vec<(&str, f64)> = ARMS.iter().map(|a| (a.flag, 1.0)).collect();
    // 3/6/8/9/12/110 are real rooms this table does not gate; 999 / -1 / 65535
    // are the out-of-range shapes a stale caller could hand in.
    for room in [3, 6, 8, 9, 12, 110, 999, -1, 65535] {
        let id = lloyd_in(&b, &mut s, room, &every_flag);
        s.dispatch(&b, id, 2, 0)
            .unwrap_or_else(|e| panic!("CODE {LLOYD_CODE} room {room}: {e}"));
        assert!(
            alive(&s, id),
            "CODE {LLOYD_CODE}: room {room} is not in the 17-arm table, so Lloyd survives even \
             with all 17 flags set"
        );
        assert_eq!(
            ledger(&s, LLOYD_CODE),
            expected_trace(&[], &[]),
            "CODE {LLOYD_CODE} room {room}: every room gate runs and fails, so no flag is even \
             read"
        );
        assert!(
            ledger(&s, LLOYD_DESTROY).is_empty(),
            "CODE {LLOYD_CODE} room {room}: no Destroy event may run"
        );
    }
}
