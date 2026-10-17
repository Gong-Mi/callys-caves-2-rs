//! Arm-level branch coverage for CODE 16 (gml_Object_obj_player_Other_4 =
//! obj_player event (7,4) Room Start): the pre-switch common prologue plus the
//! whole 110-arm `switch (room)` table that marks `global.<room>visited = 1`.
//!
//! Body shape, straight off the authoritative bytecode in
//! `crates/core/src/generated/full_ir.json` (CODE 16, start 3817976, end
//! 3822064, 4088 bytes, 877 instructions):
//!
//!     prologue  (0..552)
//!       [load room; constant K; cmp ne; bf skip] x 15   <- AdColony gate
//!       call AdColony_ShowVideo("vz1aca9f7894b44cec93")
//!       global.gemdropenabled = 1; global.poisonenabled = 0
//!       invulnerable = invulnerable2 = sliding1 = sliding2 = 0
//!       if (room != rm_ending) global.roomstart = 1
//!       alarm[6] = 10
//!       if (global.warpfrommap == 1) { x = global.startx; y = global.starty }
//!       if (room != rm_ending) hspeed = 0
//!       vspeed = 0
//!     switch    (552: `load room`)
//!       chain  (560..2320)   [dup; constant K; cmp eq; bt arm_K] x 110
//!       default (2320)       `b exit`   <- untargeted fall-through, EMPTY
//!       arms   (2324..4084)  [constant 1; store global.<flag>; b exit] x 110
//!       exit   (4084)        `popz`
//!
//! Every arm body is exactly three instructions / 16 bytes and writes `1` into
//! one GLOBAL (selector -5) `visited` flag. The default body is the single `b`
//! at code_offset 2320 and is not the target of any `bt`, so a room outside the
//! table (`rm_ending` 110, `rm_map` 111, `rm_mapview3` 112, `rm_mapview0` 113,
//! and anything else) writes nothing at all.
//!
//! The expected table below is generated from that bytecode by
//! `wl49-roomstart_gen16.py` (scratch, not checked in), which additionally
//! asserts that the bytecode's 110 (room, flag) pairs equal the recovered GML's
//! `switch` case list (`0016__gml_Object_obj_player_Other_4.gml`) resolved
//! through `room_bindings` - name for name, in the same order. The test then
//! re-derives the same table from the live instruction stream of the loaded
//! bundle at run time, so a stale or mistyped const table cannot pass.
//!
//! Arm census (re-asserted programmatically below): 110 arms over 110 DISTINCT
//! room constants - exactly 0..=109, no holes, no repeats; 110 distinct flag
//! names. There is therefore no duplicate arm for a "first matching arm wins"
//! rule to arbitrate, which corrects the brief's rough note that "the room-key
//! arms have repeated constants (same room, several arms)". What the suite does
//! pin is the *mechanism* the rule exists for: the chain is a linear sequence of
//! `bt`s with no fall-through sharing, so a room's own comparison is the last one
//! that runs - every arm case asserts the exact comparison prefix that executed.
//!
//! The naming families confirmed against the GML: `rm_town` (0) writes
//! `roomtownvisited`; the chapter-1 levels write `levelNvisited` (including the
//! `-a` variants: `level8avisited`, `level9avisited`, `level11avisited`, ...);
//! the six bosses write `bossNvisited`; `room31`..`room103` write
//! `roomNvisited`; and the challenge rooms 105..109 write
//! `levelchallengeNvisited`.
//!
//! Fixture: `Scene::default()` + `init_bundle` + `init_fresh_start_globals`, one
//! `create(&b, PLAYER, ..)` for the obj_player instance, then Room Start is
//! driven directly as `s.dispatch(&b, player, 7, 4)` - the exact call
//! `Scene::transition_to_room` makes on room entry. `s.current_room` is the
//! `room` the VM reads. Arm-level coverage is read back from the engine's own
//! instruction ledger (`Scene::executed`), so a positive case must show exactly
//! its own chain prefix and its own three-instruction body.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Op};
use callys_core::ir_scene::Scene;
use std::path::Path;

/// obj_player's object id; CODE 16 is its (7,4) Room Start body.
const PLAYER: i32 = 0;
const ROOMSTART_CODE: usize = 16;

// CODE 16 layout, from full_ir.json.
const ROOMSTART_START: usize = 3_817_976;
const ROOMSTART_END: usize = 3_822_064;

// --- prologue -----------------------------------------------------------------
/// First `load room` of the 15-test AdColony gate; the gate tests are 20 bytes
/// each (`load` 8 + `constant` 4 + `cmp` 4 + branch 4).
const GATE_FIRST_TEST_OFF: usize = 0;
const GATE_TEST_STRIDE: usize = 20;
const GATE_TEST_COUNT: usize = 15;
/// `constant 0`: the short-circuit tail a matched gate comparison jumps to.
const GATE_SKIP_CONST_OFF: usize = 300;
/// `bf 332`: consumes the gate result and skips the interstitial.
const GATE_SKIP_BF_OFF: usize = 304;
const GATE_STRING_OFF: usize = 308;
const GATE_CAST_OFF: usize = 316;
/// The AdColony_ShowVideo call site - only reached when no gate comparison
/// matched.
const GATE_CALL_OFF: usize = 320;
const GATE_CALL_POPZ_OFF: usize = 328;
/// `constant 1` / `store global.gemdropenabled` - the first prologue statement
/// after the gate.
const GATE_AFTER_OFF: usize = 332;
/// Prologue statement offsets (the `store` of each pair), read off the body.
const P_GEMDROPENABLED_OFF: usize = 336;
const P_POISONENABLED_OFF: usize = 348;
const P_INVULNERABLE_OFF: usize = 360;
const P_INVULNERABLE2_OFF: usize = 372;
const P_SLIDING1_OFF: usize = 384;
const P_SLIDING2_OFF: usize = 396;
const P_ROOMSTART_OFF: usize = 428;
const P_ALARM_OFF: usize = 448;
const P_X_OFF: usize = 484;
const P_Y_OFF: usize = 500;
const P_HSPEED_OFF: usize = 532;
const P_VSPEED_OFF: usize = 544;

/// The 15 rooms whose Room Start suppresses the AdColony interstitial, in
/// bytecode (chain) order: rm_town, rm_level1..3, the six bosses, rm_ending,
/// the three map rooms and rm_challenge1. Re-derived from the bytecode at run
/// time by the cross-check test.
const GATE_ROOMS: [i32; 15] = [0, 1, 2, 3, 10, 27, 48, 64, 82, 104, 110, 111, 112, 113, 105];

// --- switch -------------------------------------------------------------------
/// `load room` that opens the switch: the `dup` chain starts 8 bytes later.
const SWITCH_LOAD_OFF: usize = 552;
/// First `dup` of the test chain; each test is 16 bytes (`dup`, `constant`,
/// `cmp`, `bt`).
const CHAIN_FIRST_TEST_OFF: usize = 560;
const CHAIN_TEST_STRIDE: usize = 16;
const CHAIN_TEST_COUNT: usize = 110;
/// The untargeted fall-through body: a single `b` to the shared exit.
const DEFAULT_BODY_OFF: usize = 2320;
/// First arm body; arm bodies are contiguous 16-byte blocks in chain order.
const FIRST_ARM_BODY_OFF: usize = 2324;
const ARM_BODY_STRIDE: usize = 16;
/// Shared exit (`popz`) every arm body's trailing `b` jumps to.
const EXIT_POPZ_OFF: usize = 4084;

/// rm_ending: the one shipped room the prologue treats differently (no
/// `global.roomstart`, no `hspeed = 0`) and the switch does not cover.
const ROOM_ENDING: i32 = 110;

/// Distinctive pre-seeded value: a store the prologue does NOT perform leaves
/// this in place, which is how the rm_ending branch is told apart from the
/// ordinary one.
const SENTINEL: f64 = -999.0;

const PX: f64 = 640.0;
const PY: f64 = 480.0;

/// (room constant, `global.<flag>` written, body code_offset) - CODE 16's
/// `switch (room)` chain in bytecode order, one line per arm. Extracted from
/// full_ir.json CODE 16 (start 3817976), never hand written; the extraction
/// script `wl49-roomstart_gen16.py` also asserts this list equals the recovered
/// GML's case list name for name, in the same order.
#[rustfmt::skip]
const ROOMSTART_ARMS: [(i32, &str, usize); 110] = [
    (0, "roomtownvisited", 2324), // CODE 16 arm 0
    (1, "level1visited", 2340), // CODE 16 arm 1
    (2, "level2visited", 2356), // CODE 16 arm 2
    (3, "level3visited", 2372), // CODE 16 arm 3
    (4, "level4visited", 2388), // CODE 16 arm 4
    (5, "level5visited", 2404), // CODE 16 arm 5
    (6, "level6visited", 2420), // CODE 16 arm 6
    (7, "level7visited", 2436), // CODE 16 arm 7
    (8, "level8visited", 2452), // CODE 16 arm 8
    (9, "level8avisited", 2468), // CODE 16 arm 9
    (10, "boss1visited", 2484), // CODE 16 arm 10
    (11, "level9visited", 2500), // CODE 16 arm 11
    (12, "level9avisited", 2516), // CODE 16 arm 12
    (13, "level10visited", 2532), // CODE 16 arm 13
    (14, "level11visited", 2548), // CODE 16 arm 14
    (15, "level11avisited", 2564), // CODE 16 arm 15
    (16, "level12visited", 2580), // CODE 16 arm 16
    (17, "level13visited", 2596), // CODE 16 arm 17
    (18, "level13avisited", 2612), // CODE 16 arm 18
    (19, "level14visited", 2628), // CODE 16 arm 19
    (20, "level14avisited", 2644), // CODE 16 arm 20
    (21, "level15visited", 2660), // CODE 16 arm 21
    (22, "level15avisited", 2676), // CODE 16 arm 22
    (23, "level16visited", 2692), // CODE 16 arm 23
    (24, "level16avisited", 2708), // CODE 16 arm 24
    (25, "level17visited", 2724), // CODE 16 arm 25
    (26, "level17avisited", 2740), // CODE 16 arm 26
    (27, "boss2visited", 2756), // CODE 16 arm 27
    (28, "room31visited", 2772), // CODE 16 arm 28
    (29, "room32visited", 2788), // CODE 16 arm 29
    (30, "room33visited", 2804), // CODE 16 arm 30
    (31, "room34visited", 2820), // CODE 16 arm 31
    (32, "room35visited", 2836), // CODE 16 arm 32
    (33, "room36visited", 2852), // CODE 16 arm 33
    (34, "room37visited", 2868), // CODE 16 arm 34
    (35, "room38visited", 2884), // CODE 16 arm 35
    (36, "room39visited", 2900), // CODE 16 arm 36
    (37, "room40visited", 2916), // CODE 16 arm 37
    (38, "room41visited", 2932), // CODE 16 arm 38
    (39, "room42visited", 2948), // CODE 16 arm 39
    (40, "room43visited", 2964), // CODE 16 arm 40
    (41, "room44visited", 2980), // CODE 16 arm 41
    (42, "room45visited", 2996), // CODE 16 arm 42
    (43, "room46visited", 3012), // CODE 16 arm 43
    (44, "room47visited", 3028), // CODE 16 arm 44
    (45, "room48visited", 3044), // CODE 16 arm 45
    (46, "room49visited", 3060), // CODE 16 arm 46
    (47, "room50visited", 3076), // CODE 16 arm 47
    (48, "boss3visited", 3092), // CODE 16 arm 48
    (49, "room51visited", 3108), // CODE 16 arm 49
    (50, "room52visited", 3124), // CODE 16 arm 50
    (51, "room53visited", 3140), // CODE 16 arm 51
    (52, "room54visited", 3156), // CODE 16 arm 52
    (53, "room55visited", 3172), // CODE 16 arm 53
    (54, "room56visited", 3188), // CODE 16 arm 54
    (55, "room57visited", 3204), // CODE 16 arm 55
    (56, "room58visited", 3220), // CODE 16 arm 56
    (57, "room59visited", 3236), // CODE 16 arm 57
    (58, "room60visited", 3252), // CODE 16 arm 58
    (59, "room61visited", 3268), // CODE 16 arm 59
    (60, "room62visited", 3284), // CODE 16 arm 60
    (61, "room63visited", 3300), // CODE 16 arm 61
    (62, "room64visited", 3316), // CODE 16 arm 62
    (63, "room65visited", 3332), // CODE 16 arm 63
    (64, "boss4visited", 3348), // CODE 16 arm 64
    (65, "room66visited", 3364), // CODE 16 arm 65
    (66, "room67visited", 3380), // CODE 16 arm 66
    (67, "room68visited", 3396), // CODE 16 arm 67
    (68, "room69visited", 3412), // CODE 16 arm 68
    (69, "room70visited", 3428), // CODE 16 arm 69
    (70, "room71visited", 3444), // CODE 16 arm 70
    (71, "room72visited", 3460), // CODE 16 arm 71
    (72, "room73visited", 3476), // CODE 16 arm 72
    (73, "room74visited", 3492), // CODE 16 arm 73
    (74, "room75visited", 3508), // CODE 16 arm 74
    (75, "room76visited", 3524), // CODE 16 arm 75
    (76, "room77visited", 3540), // CODE 16 arm 76
    (77, "room78visited", 3556), // CODE 16 arm 77
    (78, "room79visited", 3572), // CODE 16 arm 78
    (79, "room80visited", 3588), // CODE 16 arm 79
    (80, "room81visited", 3604), // CODE 16 arm 80
    (81, "room82visited", 3620), // CODE 16 arm 81
    (82, "boss5visited", 3636), // CODE 16 arm 82
    (83, "room83visited", 3652), // CODE 16 arm 83
    (84, "room84visited", 3668), // CODE 16 arm 84
    (85, "room85visited", 3684), // CODE 16 arm 85
    (86, "room86visited", 3700), // CODE 16 arm 86
    (87, "room87visited", 3716), // CODE 16 arm 87
    (88, "room88visited", 3732), // CODE 16 arm 88
    (89, "room89visited", 3748), // CODE 16 arm 89
    (90, "room90visited", 3764), // CODE 16 arm 90
    (91, "room91visited", 3780), // CODE 16 arm 91
    (92, "room92visited", 3796), // CODE 16 arm 92
    (93, "room93visited", 3812), // CODE 16 arm 93
    (94, "room94visited", 3828), // CODE 16 arm 94
    (95, "room95visited", 3844), // CODE 16 arm 95
    (96, "room96visited", 3860), // CODE 16 arm 96
    (97, "room97visited", 3876), // CODE 16 arm 97
    (98, "room98visited", 3892), // CODE 16 arm 98
    (99, "room99visited", 3908), // CODE 16 arm 99
    (100, "room100visited", 3924), // CODE 16 arm 100
    (101, "room101visited", 3940), // CODE 16 arm 101
    (102, "room102visited", 3956), // CODE 16 arm 102
    (103, "room103visited", 3972), // CODE 16 arm 103
    (104, "boss6visited", 3988), // CODE 16 arm 104
    (105, "levelchallenge1visited", 4004), // CODE 16 arm 105
    (106, "levelchallenge2visited", 4020), // CODE 16 arm 106
    (107, "levelchallenge3visited", 4036), // CODE 16 arm 107
    (108, "levelchallenge4visited", 4052), // CODE 16 arm 108
    (109, "levelchallenge5visited", 4068), // CODE 16 arm 109
];

// ---- fixture -----------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn fixture(b: &Bundle) -> (Scene, i32) {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    let p = s
        .create(b, PLAYER, PX, PY)
        .expect("obj_player instance (Create CODE 0)");
    (s, p)
}

fn field(s: &Scene, id: i32, name: &str) -> Option<f64> {
    s.instances.get(&id).and_then(|i| i.fields.get(name)).copied()
}

fn set_field(s: &mut Scene, id: i32, name: &str, v: f64) {
    s.instances.get_mut(&id).unwrap().fields.insert(name.into(), v);
}

fn alarm(s: &Scene, id: i32, slot: usize) -> i32 {
    s.instances[&id].alarms[slot]
}

/// Every instruction the VM entered for CODE 16, as code_offsets relative to
/// the body start, in execution order.
fn ledger(s: &Scene) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(c, _)| *c == ROOMSTART_CODE)
        .map(|(_, o)| *o - ROOMSTART_START)
        .collect()
}

fn ran_between(s: &Scene, lo: usize, hi: usize) -> Vec<usize> {
    ledger(s).into_iter().filter(|o| (lo..hi).contains(o)).collect()
}

/// The gate-region instructions the VM must have entered for a given room: the
/// `room != K` comparisons up to and including the one that matched (or all
/// fifteen when none matches), then the short-circuit tail.
///
/// The 15th comparison is compiled with a plain `b` (its result is consumed by
/// the `bf` at [`GATE_SKIP_BF_OFF`]), so the `constant 0` of the skip path at
/// [`GATE_SKIP_CONST_OFF`] is bypassed when that last comparison is the one that
/// decides the gate.
fn expected_gate_offsets(room: i32) -> Vec<usize> {
    let matched = GATE_ROOMS.iter().position(|r| *r == room);
    let last_run = matched.unwrap_or(GATE_TEST_COUNT - 1);
    let mut v = Vec::new();
    for k in 0..=last_run {
        let base = GATE_FIRST_TEST_OFF + GATE_TEST_STRIDE * k;
        v.extend([base, base + 8, base + 12, base + 16]);
    }
    match matched {
        Some(g) if g == GATE_TEST_COUNT - 1 => v.push(GATE_SKIP_BF_OFF),
        Some(_) => v.extend([GATE_SKIP_CONST_OFF, GATE_SKIP_BF_OFF]),
        None => v.extend([
            GATE_SKIP_BF_OFF,
            GATE_STRING_OFF,
            GATE_CAST_OFF,
            GATE_CALL_OFF,
            GATE_CALL_POPZ_OFF,
        ]),
    }
    v
}

/// The chain-region instructions that must have run for the arm at chain index
/// `arm`: the four instructions of every comparison block 0..=arm.
fn expected_chain_offsets(arm: usize) -> Vec<usize> {
    let mut v = Vec::new();
    for k in 0..=arm {
        let base = CHAIN_FIRST_TEST_OFF + CHAIN_TEST_STRIDE * k;
        v.extend([base, base + 4, base + 8, base + 12]);
    }
    v
}

// ---- run-time cross-check of the embedded table -------------------------------

/// Re-derive (room, flag, body code_offset) from the bundle's live CODE 16
/// instruction stream, using only the chain/arm shape the header documents.
fn arms_from_bytecode(b: &Bundle) -> Vec<(i32, String, usize)> {
    let code = b
        .codes
        .iter()
        .find(|c| c.id == ROOMSTART_CODE)
        .expect("CODE 16 present in the bundle");
    // CODE 16 is obj_player's Room Start body, and only obj_player's.
    let owner = b
        .objects
        .iter()
        .find(|o| o.events.iter().any(|e| e.event_type == 7 && e.subtype == 4 && e.codes.contains(&ROOMSTART_CODE)))
        .expect("CODE 16 is bound to an object");
    assert_eq!(owner.id, PLAYER, "CODE 16 belongs to obj_player");
    let ins = &code.instructions;
    let at = |off: usize| ins.iter().find(|i| i.code_offset == off);

    // The chain: `dup; constant K; cmp eq; bt arm` blocks, back to back.
    let mut chain = Vec::new();
    let mut p = CHAIN_FIRST_TEST_OFF;
    while let (Some(d), Some(c), Some(m), Some(t)) =
        (at(p), at(p + 4), at(p + 8), at(p + 12))
    {
        if !matches!(d.op, Op::Dup) {
            break;
        }
        let k = match c.op {
            Op::Constant { value } => value,
            _ => panic!("CODE {ROOMSTART_CODE}: chain test at {p} has no constant"),
        };
        assert!(
            matches!(m.op, Op::Cmp { comparison: 3 }),
            "CODE {ROOMSTART_CODE}: chain test at {p} is not an equality comparison"
        );
        let target = match t.op {
            Op::Bt { target } => target - ROOMSTART_START,
            _ => panic!("CODE {ROOMSTART_CODE}: chain test at {p} does not branch on true"),
        };
        chain.push((k as i32, target));
        p += CHAIN_TEST_STRIDE;
    }

    let mut arms = Vec::new();
    for (room, body) in chain {
        let c = at(body).expect("arm body");
        let s = at(body + 4).expect("arm store");
        let e = at(body + 12).expect("arm exit branch");
        assert!(
            matches!(c.op, Op::Constant { value } if value == 1.0),
            "CODE {ROOMSTART_CODE} arm for room {room}: body does not start with constant 1"
        );
        let flag = match &s.op {
            Op::Store { name, selector: -5, array: false, .. } => name.clone(),
            other => panic!("CODE {ROOMSTART_CODE} arm for room {room}: body store is {other:?}"),
        };
        match e.op {
            Op::B { target } if target - ROOMSTART_START == EXIT_POPZ_OFF => {}
            ref other => panic!("CODE {ROOMSTART_CODE} arm for room {room}: exit is {other:?}"),
        }
        arms.push((room, flag, body));
    }
    arms
}

// ---- 1. the embedded table vs the live stream --------------------------------

#[test]
// CODE 16
fn the_embedded_arm_table_is_re_derived_from_the_live_code_16_stream() {
    let b = bundle();
    let live = arms_from_bytecode(&b);
    // CODE 16's table length, room set and flag set are the embedded ones.
    assert_eq!(
        live.len(),
        ROOMSTART_ARMS.len(),
        "CODE {ROOMSTART_CODE}: the live chain carries {} arms, the embedded table {}",
        live.len(),
        ROOMSTART_ARMS.len()
    );
    assert_eq!(
        live,
        ROOMSTART_ARMS
            .iter()
            .map(|(r, f, o)| (*r, (*f).to_string(), *o))
            .collect::<Vec<_>>(),
        "CODE {ROOMSTART_CODE}: the embedded arm table is not the live instruction stream"
    );

    // Layout constants the rest of the suite leans on.
    let code = b.codes.iter().find(|c| c.id == ROOMSTART_CODE).unwrap();
    assert_eq!(code.start, ROOMSTART_START, "CODE {ROOMSTART_CODE} body start");
    assert_eq!(code.end, ROOMSTART_END, "CODE {ROOMSTART_CODE} body end");
    let ins = &code.instructions;
    let at = |off: usize| ins.iter().find(|i| i.code_offset == off);
    assert!(
        matches!(at(SWITCH_LOAD_OFF).unwrap().op, Op::Load { ref name, .. } if name == "room"),
        "CODE {ROOMSTART_CODE}: the switch opens on `load room`"
    );
    assert!(
        matches!(at(CHAIN_FIRST_TEST_OFF).unwrap().op, Op::Dup),
        "CODE {ROOMSTART_CODE}: the test chain starts at {CHAIN_FIRST_TEST_OFF}"
    );
    // The fall-through body is a bare `b` to the exit and no `bt` targets it.
    match at(DEFAULT_BODY_OFF).unwrap().op {
        Op::B { target } => assert_eq!(
            target - ROOMSTART_START,
            EXIT_POPZ_OFF,
            "CODE {ROOMSTART_CODE}: the untargeted default body jumps to the shared exit"
        ),
        ref other => panic!("CODE {ROOMSTART_CODE}: default body at {DEFAULT_BODY_OFF} is {other:?}"),
    }
    assert!(
        !ROOMSTART_ARMS.iter().any(|a| a.2 == DEFAULT_BODY_OFF),
        "CODE {ROOMSTART_CODE}: the default body at {DEFAULT_BODY_OFF} is no arm target"
    );
    assert!(
        matches!(at(EXIT_POPZ_OFF).unwrap().op, Op::Popz),
        "CODE {ROOMSTART_CODE}: the shared exit at {EXIT_POPZ_OFF} is the popz"
    );
    // Bodies are contiguous 16-byte blocks in chain order, so chain index ==
    // layout index.
    let bodies: Vec<usize> = ROOMSTART_ARMS.iter().map(|a| a.2).collect();
    assert_eq!(
        bodies,
        (0..ROOMSTART_ARMS.len())
            .map(|k| FIRST_ARM_BODY_OFF + ARM_BODY_STRIDE * k)
            .collect::<Vec<_>>(),
        "CODE {ROOMSTART_CODE}: arm bodies are laid out in chain order"
    );

    // The AdColony gate's room list, re-derived from the bytecode.
    let mut gate = Vec::new();
    for k in 0..GATE_TEST_COUNT {
        let base = GATE_FIRST_TEST_OFF + GATE_TEST_STRIDE * k;
        let c = at(base + 8).expect("gate constant");
        assert!(
            matches!(at(base + 12).unwrap().op, Op::Cmp { comparison: 4 }),
            "CODE {ROOMSTART_CODE}: gate test {k} is not a `!=` comparison"
        );
        match c.op {
            Op::Constant { value } => gate.push(value as i32),
            ref other => panic!("CODE {ROOMSTART_CODE}: gate test {k} constant is {other:?}"),
        }
    }
    assert_eq!(
        gate,
        GATE_ROOMS.to_vec(),
        "CODE {ROOMSTART_CODE}: the AdColony gate room list is the documented 15"
    );

    // The prologue's own statements, located by offset (the sweep test asserts
    // their effects; this pins that the offsets name the shipped stores).
    for (off, name, selector) in [
        (P_GEMDROPENABLED_OFF, "gemdropenabled", -5),
        (P_POISONENABLED_OFF, "poisonenabled", -5),
        (P_INVULNERABLE_OFF, "invulnerable", -1),
        (P_INVULNERABLE2_OFF, "invulnerable2", -1),
        (P_SLIDING1_OFF, "sliding1", -1),
        (P_SLIDING2_OFF, "sliding2", -1),
        (P_ROOMSTART_OFF, "roomstart", -5),
        (P_X_OFF, "x", -1),
        (P_Y_OFF, "y", -1),
        (P_HSPEED_OFF, "hspeed", -1),
        (P_VSPEED_OFF, "vspeed", -1),
    ] {
        match &at(off).unwrap_or_else(|| panic!("CODE {ROOMSTART_CODE}: no instruction at {off}")).op {
            Op::Store { name: n, selector: s, .. } if n == name && *s == selector => {}
            other => panic!("CODE {ROOMSTART_CODE}: instruction at {off} is {other:?}, expected store {name} (selector {selector})"),
        }
    }
    // `alarm[6] = 10` is the array-store form: the body pushes the value, the
    // target selector and the index, so the store carries `array: true` (name
    // "alarm", spare selector 0) and the VM routes it to `Instance::alarms[6]`.
    match &at(P_ALARM_OFF).unwrap().op {
        Op::Store { name, selector: 0, array: true, .. } if name == "alarm" => {}
        other => panic!("CODE {ROOMSTART_CODE}: instruction at {P_ALARM_OFF} is {other:?}, expected the array store of alarm"),
    }
    // The gate's skip-path tail and the call site are what the gate tests watch.
    assert!(
        matches!(at(GATE_SKIP_CONST_OFF).unwrap().op, Op::Constant { value } if value == 0.0),
        "CODE {ROOMSTART_CODE}: the skip path pushes 0 before the bf"
    );
    match at(GATE_CALL_OFF).unwrap().op {
        Op::Call { ref name, .. } => assert_eq!(
            name, "AdColony_ShowVideo",
            "CODE {ROOMSTART_CODE}: the ungated path calls the interstitial"
        ),
        ref other => panic!("CODE {ROOMSTART_CODE}: the call site is {other:?}"),
    }
}

// ---- 2. the 110-arm sweep ----------------------------------------------------

#[test]
// CODE 16
fn every_room_start_arm_marks_exactly_its_own_room_visited() {
    let b = bundle();
    let (mut s, player) = fixture(&b);
    // Fresh start: not one of the table's flags is already set, so the arm's own
    // store is the only writer (the challenge flags ship as 0.0 from CODE 17,
    // the rest are simply absent).
    for (_, flag, _) in ROOMSTART_ARMS {
        assert_ne!(
            s.globals.get(flag).copied(),
            Some(1.0),
            "CODE {ROOMSTART_CODE}: {flag} is already 1 at fresh start"
        );
    }

    let arms = ROOMSTART_ARMS.len();
    let mut ran = 0usize;
    for (arm, &(room, flag, body)) in ROOMSTART_ARMS.iter().enumerate() {
        // One arm, one unique input: this room and no other.
        s.globals.insert(flag.into(), 0.0);
        // Neighbouring arms, sampled 4-wide across the table: their flags must
        // come out of this arm's dispatch exactly as they went in.
        let probes: Vec<(&str, Option<f64>)> = [1usize, 37, 73, 109]
            .iter()
            .map(|d| ROOMSTART_ARMS[(arm + d) % arms].1)
            .map(|n| (n, s.globals.get(n).copied()))
            .collect();
        assert!(
            !probes.iter().any(|(n, _)| *n == flag),
            "CODE {ROOMSTART_CODE} arm {arm}: the neighbour probes exclude the arm's own flag"
        );

        s.current_room = f64::from(room);
        s.executed.clear();
        s.dispatch(&b, player, 7, 4)
            .unwrap_or_else(|e| panic!("CODE {ROOMSTART_CODE} arm {arm} (room {room}): {e}"));

        assert_eq!(
            s.globals.get(flag).copied(),
            Some(1.0),
            "CODE {ROOMSTART_CODE} arm {arm} (room {room}) writes {flag} = 1"
        );
        for (n, before) in &probes {
            assert_eq!(
                s.globals.get(*n).copied(),
                *before,
                "CODE {ROOMSTART_CODE} arm {arm} (room {room}) must not touch {n}"
            );
        }

        // The chain is a linear sequence of `bt`s: this arm's own comparison is
        // the last one that runs, and the comparisons after it never execute.
        assert_eq!(
            ran_between(&s, CHAIN_FIRST_TEST_OFF, DEFAULT_BODY_OFF),
            expected_chain_offsets(arm),
            "CODE {ROOMSTART_CODE} arm {arm} (room {room}) must stop the test chain at its own comparison"
        );
        // Exactly this arm's three-instruction body ran, no neighbour's.
        let body_ran = ran_between(&s, DEFAULT_BODY_OFF, EXIT_POPZ_OFF);
        assert_eq!(
            body_ran.first(),
            Some(&body),
            "CODE {ROOMSTART_CODE} arm {arm} (room {room}) must enter the body at code_offset {body}"
        );
        assert!(
            body_ran.iter().all(|o| *o >= body && *o < body + ARM_BODY_STRIDE),
            "CODE {ROOMSTART_CODE} arm {arm} (room {room}) executed instructions outside its own body: {body_ran:?}"
        );
        assert_eq!(
            ledger(&s).last(),
            Some(&EXIT_POPZ_OFF),
            "CODE {ROOMSTART_CODE} arm {arm} (room {room}) joins the shared popz exit"
        );
        ran += 1;
    }
    assert_eq!(
        ran, 110,
        "CODE {ROOMSTART_CODE}: the sweep covers the whole 110-arm chain"
    );
    // Every arm's flag ends up set, and every other flag still is not.
    for (_, flag, _) in ROOMSTART_ARMS {
        assert_eq!(
            s.globals.get(flag).copied(),
            Some(1.0),
            "CODE {ROOMSTART_CODE}: {flag} after the sweep"
        );
    }
    assert_eq!(
        s.globals.iter().filter(|(k, v)| k.ends_with("visited") && **v == 1.0).count(),
        arms,
        "CODE {ROOMSTART_CODE}: exactly the table's {arms} flags are set, no extras"
    );
}

// ---- 3. the prologue ---------------------------------------------------------

#[test]
// CODE 16
fn the_room_start_prologue_runs_on_every_arm_and_the_gate_short_circuits() {
    let b = bundle();

    // (a) A gated room: the full common section, every statement observable.
    let (mut s, player) = fixture(&b);
    s.globals.insert("gemdropenabled".into(), SENTINEL);
    s.globals.insert("poisonenabled".into(), SENTINEL);
    s.globals.insert("roomstart".into(), SENTINEL);
    s.globals.insert("warpfrommap".into(), 0.0);
    s.globals.insert("startx".into(), SENTINEL);
    s.globals.insert("starty".into(), SENTINEL);
    for n in ["invulnerable", "invulnerable2", "sliding1", "sliding2", "hspeed", "vspeed"] {
        set_field(&mut s, player, n, SENTINEL);
    }
    s.current_room = 1.0;
    s.executed.clear();
    s.dispatch(&b, player, 7, 4).expect("CODE 16 room 1");

    assert_eq!(s.globals["gemdropenabled"], 1.0, "CODE {ROOMSTART_CODE}: prologue sets gemdropenabled = 1");
    assert_eq!(s.globals["poisonenabled"], 0.0, "CODE {ROOMSTART_CODE}: prologue sets poisonenabled = 0");
    assert_eq!(s.globals["roomstart"], 1.0, "CODE {ROOMSTART_CODE}: prologue sets roomstart = 1");
    for n in ["invulnerable", "invulnerable2", "sliding1", "sliding2"] {
        assert_eq!(field(&s, player, n), Some(0.0), "CODE {ROOMSTART_CODE}: prologue clears {n}");
    }
    assert_eq!(field(&s, player, "hspeed"), Some(0.0), "CODE {ROOMSTART_CODE}: prologue stops hspeed");
    assert_eq!(field(&s, player, "vspeed"), Some(0.0), "CODE {ROOMSTART_CODE}: prologue stops vspeed");
    assert_eq!(alarm(&s, player, 6), 10, "CODE {ROOMSTART_CODE}: prologue arms alarm[6] = 10");
    // warpfrommap == 0, so the pin branch must not have run.
    assert_eq!(field(&s, player, "x"), Some(PX), "CODE {ROOMSTART_CODE}: no map warp, x untouched");
    assert_eq!(field(&s, player, "y"), Some(PY), "CODE {ROOMSTART_CODE}: no map warp, y untouched");
    assert_eq!(s.globals["level1visited"], 1.0, "CODE {ROOMSTART_CODE}: the arm still marks the room");
    // Room 1 is gate index 1: the interstitial is suppressed.
    assert_eq!(
        ran_between(&s, GATE_FIRST_TEST_OFF, GATE_AFTER_OFF),
        expected_gate_offsets(1),
        "CODE {ROOMSTART_CODE}: a gated room stops the AdColony gate at its own comparison"
    );
    assert!(
        !ledger(&s).contains(&GATE_CALL_OFF),
        "CODE {ROOMSTART_CODE}: room 1 is in the 15-room gate list, so AdColony_ShowVideo is not called"
    );

    // (b) A room outside the gate list: all 15 comparisons fail and the
    // interstitial call is reached.
    let (mut s2, p2) = fixture(&b);
    s2.globals.insert("gemdropenabled".into(), SENTINEL);
    s2.current_room = 4.0;
    s2.executed.clear();
    s2.dispatch(&b, p2, 7, 4).expect("CODE 16 room 4");
    assert_eq!(
        ran_between(&s2, GATE_FIRST_TEST_OFF, GATE_AFTER_OFF),
        expected_gate_offsets(4),
        "CODE {ROOMSTART_CODE}: an ungated room runs the whole gate and the call"
    );
    assert!(
        ledger(&s2).contains(&GATE_CALL_OFF),
        "CODE {ROOMSTART_CODE}: room 4 is not in the gate list, so AdColony_ShowVideo runs"
    );
    assert!(
        ledger(&s2).contains(&GATE_CALL_POPZ_OFF),
        "CODE {ROOMSTART_CODE}: the interstitial call's result is popped - the body stays stack-balanced"
    );
    assert_eq!(s2.globals["gemdropenabled"], 1.0, "CODE {ROOMSTART_CODE}: the prologue continues past the call");

    // (c) The warpfrommap pin: x/y take global.startx/starty.
    let (mut s3, p3) = fixture(&b);
    s3.globals.insert("warpfrommap".into(), 1.0);
    s3.globals.insert("startx".into(), 777.0);
    s3.globals.insert("starty".into(), 888.0);
    s3.current_room = 5.0;
    s3.dispatch(&b, p3, 7, 4).expect("CODE 16 room 5 (warpfrommap)");
    assert_eq!(field(&s3, p3, "x"), Some(777.0), "CODE {ROOMSTART_CODE}: warpfrommap pins x = global.startx");
    assert_eq!(field(&s3, p3, "y"), Some(888.0), "CODE {ROOMSTART_CODE}: warpfrommap pins y = global.starty");
    assert_eq!(field(&s3, p3, "hspeed"), Some(0.0), "CODE {ROOMSTART_CODE}: hspeed is zeroed after the pin");

    // (d) The gate's two shapes at the extremes of its comparison list: the
    // first entry and the last (which is compiled with a plain `b` instead of a
    // `bf`, so the skip-path constant at 300 is bypassed).
    for room in [0, 3, 105] {
        let (mut s4, p4) = fixture(&b);
        s4.current_room = f64::from(room);
        s4.executed.clear();
        s4.dispatch(&b, p4, 7, 4).unwrap_or_else(|e| panic!("CODE {ROOMSTART_CODE} gate room {room}: {e}"));
        assert_eq!(
            ran_between(&s4, GATE_FIRST_TEST_OFF, GATE_AFTER_OFF),
            expected_gate_offsets(room),
            "CODE {ROOMSTART_CODE}: the gate short-circuits at its comparison for room {room}"
        );
        assert!(
            !ledger(&s4).contains(&GATE_CALL_OFF),
            "CODE {ROOMSTART_CODE}: room {room} is gated"
        );
    }
}

// ---- 4. the rooms off the table ----------------------------------------------

#[test]
// CODE 16
fn rooms_off_the_switch_fall_through_and_rm_ending_skips_the_gated_stores() {
    let b = bundle();

    // (a) rm_ending: in the gate list, but the prologue's two `room != rm_ending`
    // statements do not run, and no arm matches.
    let (mut s, player) = fixture(&b);
    s.globals.insert("roomstart".into(), SENTINEL);
    s.globals.insert("gemdropenabled".into(), SENTINEL);
    set_field(&mut s, player, "hspeed", SENTINEL);
    set_field(&mut s, player, "vspeed", SENTINEL);
    s.current_room = f64::from(ROOM_ENDING);
    s.executed.clear();
    s.dispatch(&b, player, 7, 4).expect("CODE 16 rm_ending");

    assert_eq!(
        s.globals["roomstart"], SENTINEL,
        "CODE {ROOMSTART_CODE}: rm_ending leaves global.roomstart alone (the store is gated on room != rm_ending)"
    );
    assert_eq!(
        field(&s, player, "hspeed"),
        Some(SENTINEL),
        "CODE {ROOMSTART_CODE}: rm_ending leaves hspeed alone (gated on room != rm_ending)"
    );
    // vspeed is NOT gated: it is zeroed for every room of the table, rm_ending
    // included.
    assert_eq!(
        field(&s, player, "vspeed"),
        Some(0.0),
        "CODE {ROOMSTART_CODE}: vspeed = 0 is unconditional, so rm_ending gets it too"
    );
    assert_eq!(s.globals["gemdropenabled"], 1.0, "CODE {ROOMSTART_CODE}: the rest of the prologue still runs");
    assert_eq!(alarm(&s, player, 6), 10, "CODE {ROOMSTART_CODE}: alarm[6] is armed for rm_ending as well");
    assert!(
        !ledger(&s).contains(&GATE_CALL_OFF),
        "CODE {ROOMSTART_CODE}: rm_ending is in the 15-room gate list"
    );
    // The switch default is empty: only the bare `b` at 2320 runs, and not one
    // of the 110 flags is written.
    assert_eq!(
        ran_between(&s, CHAIN_FIRST_TEST_OFF, DEFAULT_BODY_OFF),
        expected_chain_offsets(CHAIN_TEST_COUNT - 1),
        "CODE {ROOMSTART_CODE}: an unmatched room runs every comparison"
    );
    assert_eq!(
        ran_between(&s, DEFAULT_BODY_OFF, EXIT_POPZ_OFF),
        vec![DEFAULT_BODY_OFF],
        "CODE {ROOMSTART_CODE}: the untargeted default body is the empty `b` at its code_offset"
    );
    assert_eq!(ledger(&s).last(), Some(&EXIT_POPZ_OFF), "CODE {ROOMSTART_CODE}: fall-through reaches the shared exit");
    for (_, flag, _) in ROOMSTART_ARMS {
        assert_ne!(
            s.globals.get(flag).copied(),
            Some(1.0),
            "CODE {ROOMSTART_CODE}: rm_ending must not mark {flag} visited"
        );
    }

    // (b) The other three rooms the table omits, plus rooms past its ends and a
    // negative value - all fall through, storing nothing.
    for room in [111, 112, 113, 114, 999, -1, 65535] {
        let (mut s2, p2) = fixture(&b);
        s2.globals.insert("roomstart".into(), SENTINEL);
        set_field(&mut s2, p2, "hspeed", SENTINEL);
        s2.current_room = f64::from(room);
        s2.executed.clear();
        s2.dispatch(&b, p2, 7, 4).unwrap_or_else(|e| panic!("CODE {ROOMSTART_CODE} room {room}: {e}"));
        for (_, flag, _) in ROOMSTART_ARMS {
            assert_ne!(
                s2.globals.get(flag).copied(),
                Some(1.0),
                "CODE {ROOMSTART_CODE}: room {room} is off the table and must not mark {flag} visited"
            );
        }
        assert_eq!(
            ran_between(&s2, DEFAULT_BODY_OFF, EXIT_POPZ_OFF),
            vec![DEFAULT_BODY_OFF],
            "CODE {ROOMSTART_CODE}: room {room} runs only the empty default body"
        );
        // Only rm_ending skips the two gated stores; 111/112/113/114/999/-1/65535
        // are `room != rm_ending`.
        assert_eq!(
            s2.globals["roomstart"], 1.0,
            "CODE {ROOMSTART_CODE}: room {room} is not rm_ending, so roomstart = 1 runs"
        );
        assert_eq!(
            field(&s2, p2, "hspeed"),
            Some(0.0),
            "CODE {ROOMSTART_CODE}: room {room} is not rm_ending, so hspeed = 0 runs"
        );
        assert_eq!(
            field(&s2, p2, "vspeed"),
            Some(0.0),
            "CODE {ROOMSTART_CODE}: vspeed = 0 is unconditional"
        );
        assert_eq!(alarm(&s2, p2, 6), 10, "CODE {ROOMSTART_CODE}: alarm[6] is armed for room {room}");
    }

    // The gate list does not contain the out-of-table rooms 111..113 alone: 110
    // shares the property, and 114/-1/65535 do not - the interstitial shape is
    // the same `room != K` chain either way.
    let (mut s3, p3) = fixture(&b);
    s3.current_room = 111.0;
    s3.executed.clear();
    s3.dispatch(&b, p3, 7, 4).expect("CODE 16 room 111");
    assert!(!ledger(&s3).contains(&GATE_CALL_OFF), "CODE {ROOMSTART_CODE}: rm_map is gated");
    let (mut s4, p4) = fixture(&b);
    s4.current_room = 114.0;
    s4.executed.clear();
    s4.dispatch(&b, p4, 7, 4).expect("CODE 16 room 114");
    assert!(
        ledger(&s4).contains(&GATE_CALL_OFF),
        "CODE {ROOMSTART_CODE}: room 114 is off both the gate list and the table - the ad runs, no flag is stored"
    );
}

// ---- 5. the census itself ----------------------------------------------------

#[test]
// CODE 16
fn the_arm_census_has_no_duplicate_rooms_or_flags() {
    let rooms: Vec<i32> = ROOMSTART_ARMS.iter().map(|a| a.0).collect();
    let flags: Vec<&str> = ROOMSTART_ARMS.iter().map(|a| a.1).collect();
    assert_eq!(rooms.len(), 110, "CODE {ROOMSTART_CODE} ships 110 arms");

    // The brief expected duplicate room constants ("same room, several arms");
    // the bytecode has none, and this pins the real shape the way
    // room_switch_bg_boulder_ir.rs pinned it for the flat Create tables.
    let mut distinct = rooms.clone();
    distinct.sort_unstable();
    distinct.dedup();
    assert_eq!(
        distinct.len(),
        rooms.len(),
        "CODE {ROOMSTART_CODE} has NO duplicate room constant: 110 arms over 110 distinct rooms"
    );
    assert_eq!(
        distinct,
        (0..=109).collect::<Vec<i32>>(),
        "CODE {ROOMSTART_CODE}'s room constants are exactly 0..=109 - no holes"
    );
    assert_eq!(
        rooms,
        (0..=109).collect::<Vec<i32>>(),
        "CODE {ROOMSTART_CODE}'s chain is in ascending room order, so chain index == room here"
    );
    let mut df = flags.clone();
    df.sort_unstable();
    df.dedup();
    assert_eq!(
        df.len(),
        flags.len(),
        "CODE {ROOMSTART_CODE} has no duplicate flag either: every arm writes a distinct global"
    );
    assert!(
        flags.iter().all(|f| f.ends_with("visited")),
        "CODE {ROOMSTART_CODE}: every arm writes a `visited` global"
    );

    // The rooms the recovered GML's `switch` does not cover: rm_ending (110),
    // rm_map (111), rm_mapview3 (112), rm_mapview0 (113).
    for room in [ROOM_ENDING, 111, 112, 113] {
        assert!(
            !rooms.contains(&room),
            "CODE {ROOMSTART_CODE}: room {room} is not covered by the table (it falls through)"
        );
    }

    // Naming families, checked against the bundle's own room_bindings: the
    // `roomNN` rooms write `roomNNvisited`.
    let b = bundle();
    let mut name = std::collections::BTreeMap::new();
    for rb in &b.room_bindings {
        name.entry(rb.room_id).or_insert_with(|| rb.room_name.clone());
    }
    let mut room_family = 0;
    for (room, flag, _) in ROOMSTART_ARMS {
        let nm = name.get(&(room as usize)).unwrap_or_else(|| panic!("CODE {ROOMSTART_CODE}: no binding for room {room}"));
        if nm.starts_with("room") && nm[4..].chars().all(|c| c.is_ascii_digit()) {
            assert_eq!(
                flag,
                format!("{nm}visited"),
                "CODE {ROOMSTART_CODE}: room {room} is bound as {nm} and writes {flag}"
            );
            room_family += 1;
        }
    }
    assert_eq!(
        room_family, 73,
        "CODE {ROOMSTART_CODE}: 73 arms carry the `roomNNvisited` family name (room31..room103)"
    );
    // The chapter-1 town flag is the one that does not follow the room name.
    assert_eq!(
        ROOMSTART_ARMS[0].1, "roomtownvisited",
        "CODE {ROOMSTART_CODE}: rm_town's flag is roomtownvisited, not rmtownvisited"
    );
    assert_eq!(name[&0], "rm_town", "room 0 is rm_town");
    assert_eq!(name[&(ROOM_ENDING as usize)], "rm_ending", "room 110 is rm_ending");
}
