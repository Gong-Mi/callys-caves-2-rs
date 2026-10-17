//! The room-id switch tables that select every platform and boss-boulder
//! sprite: CODE 33 obj_platform_Create_0 (109 arms) and CODE 28
//! obj_bossboulder_Create_0 (105 arms). Both bodies are a flat
//! `load room; [dup; constant K; cmp(==); bt <arm entry>] x N` chain, each arm
//! storing one `sprite_index` and branching to a single shared exit; they were
//! executed (body-level) before, but never enumerated arm by arm.
//!
//! Authority and direction of the expectation. The expected table is extracted
//! from `crates/core/src/generated/full_ir.json` bytecode only - the guard
//! constants, the arm entry offsets and the stored values are read out of the
//! instruction stream, not guessed from room names and not transcribed by hand.
//! The extraction is committed twice on purpose:
//!   * as the const tables below (`PLATFORM_ARMS`, `BOULDER_ARMS`), in bytecode
//!     order, one row per arm, so the census can see each `CODE 33 arm#N`;
//!   * by `extract()`, which re-reads the same switch out of the loaded bundle
//!     at run time, so the tables cannot drift from the bundle they came from.
//! The seeding extraction was a scratch probe over that JSON - read `d['codes']`,
//! walk the `dup/constant/cmp/bt` quadruples, decode each arm body from its `bt`
//! target - and it is `extract()` below that stays in the tree and is re-run on
//! every test run, so the committed table is checked, not trusted.
//!
//! Arm accounting measured on this bundle (the programmatic check the discipline
//! asks for, both bodies and the whole family):
//!   * CODE 33: 109 arms, 109 DISTINCT guard constants, rooms 1..=109,
//!     no duplicate arm, no two arms sharing an entry offset;
//!   * CODE 28: 105 arms, 105 distinct, rooms 0..=104, likewise clean;
//!   * the same scan over the six other room-guard Create tables in the bundle
//!     (the wall, wall-2, boulder, watersurface, waterfill and background
//!     themes) finds ZERO duplicate guard constants as well: the largest of
//!     them, the 114-arm background table, carries 114 distinct constants over
//!     rooms 0..=113. The commonly repeated `114 arms over only 111 room
//!     constants, i.e. duplicate arms` reading does not reproduce against this
//!     bundle, so the duplicate-arm case the order-preserving rule exists for
//!     has no witness in the shipped data. The rule is enforced regardless:
//!     bytecode-ordered table, guard order asserted, first-match resolution
//!     asserted, and the resolver pinned with a synthetic duplicated table -
//!     never by re-reading a table as a map, which is how a duplicate arm would
//!     be silently dropped.
//!
//! Drive. `create` is the shipped path: the room materializer sets
//! `current_room` and then instantiates (ir_scene::load_room_from_data ->
//! create_with_id -> dispatch(0,0)), and the Create event is exactly these two
//! bodies. Every arm here is driven the same way: `s.current_room = room;`
//! then `s.create(&b, OBJ, x, y)`, asserting only the arm's own store
//! (`sprite_index`, with the IR constant value - never a sprite name) plus the
//! one preamble store both bodies perform before the switch (`type`).
//!
//! Rewrite-side IR regression semantics, not a runner-equivalence proof: what is
//! pinned is that this VM, on these bodies, reproduces the shipped store per
//! arm, the fall-through behaviour and the guard order. It is not evidence about
//! the original runner beyond the bytecode these arms were read from.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Op};
use callys_core::ir_scene::Scene;
use std::collections::BTreeSet;
use std::path::Path;

/// obj_platform; its Create event is CODE 33.
const PLATFORM: i32 = 7;
/// obj_bossboulder; its Create event is CODE 28.
const BOULDER: i32 = 3;
const PLATFORM_CODE: usize = 33;
const BOULDER_CODE: usize = 28;

/// CODE 33's arm table, bytecode order: 109 arms over rooms 1..=109, every
/// guard constant distinct, arm#N = row N. The values are the IR `constant`
/// operands feeding `store sprite_index`.
const PLATFORM_ARMS: [(i32, f64); 109] = [
    (1, 23.0),   // CODE 33 arm#0 room 1
    (2, 23.0),   // CODE 33 arm#1 room 2
    (3, 23.0),   // CODE 33 arm#2 room 3
    (4, 23.0),   // CODE 33 arm#3 room 4
    (5, 23.0),   // CODE 33 arm#4 room 5
    (6, 23.0),   // CODE 33 arm#5 room 6
    (7, 23.0),   // CODE 33 arm#6 room 7
    (8, 23.0),   // CODE 33 arm#7 room 8
    (9, 23.0),   // CODE 33 arm#8 room 9
    (10, 23.0),  // CODE 33 arm#9 room 10
    (11, 24.0),  // CODE 33 arm#10 room 11
    (12, 24.0),  // CODE 33 arm#11 room 12
    (13, 24.0),  // CODE 33 arm#12 room 13
    (14, 24.0),  // CODE 33 arm#13 room 14
    (15, 24.0),  // CODE 33 arm#14 room 15
    (16, 24.0),  // CODE 33 arm#15 room 16
    (17, 24.0),  // CODE 33 arm#16 room 17
    (18, 24.0),  // CODE 33 arm#17 room 18
    (19, 24.0),  // CODE 33 arm#18 room 19
    (20, 24.0),  // CODE 33 arm#19 room 20
    (21, 24.0),  // CODE 33 arm#20 room 21
    (22, 24.0),  // CODE 33 arm#21 room 22
    (23, 24.0),  // CODE 33 arm#22 room 23
    (24, 24.0),  // CODE 33 arm#23 room 24
    (25, 24.0),  // CODE 33 arm#24 room 25
    (26, 24.0),  // CODE 33 arm#25 room 26
    (27, 24.0),  // CODE 33 arm#26 room 27
    (28, 25.0),  // CODE 33 arm#27 room 28
    (29, 25.0),  // CODE 33 arm#28 room 29
    (30, 25.0),  // CODE 33 arm#29 room 30
    (31, 25.0),  // CODE 33 arm#30 room 31
    (32, 25.0),  // CODE 33 arm#31 room 32
    (33, 25.0),  // CODE 33 arm#32 room 33
    (34, 25.0),  // CODE 33 arm#33 room 34
    (35, 25.0),  // CODE 33 arm#34 room 35
    (36, 25.0),  // CODE 33 arm#35 room 36
    (37, 25.0),  // CODE 33 arm#36 room 37
    (38, 25.0),  // CODE 33 arm#37 room 38
    (39, 25.0),  // CODE 33 arm#38 room 39
    (40, 25.0),  // CODE 33 arm#39 room 40
    (41, 25.0),  // CODE 33 arm#40 room 41
    (42, 25.0),  // CODE 33 arm#41 room 42
    (43, 25.0),  // CODE 33 arm#42 room 43
    (44, 25.0),  // CODE 33 arm#43 room 44
    (45, 25.0),  // CODE 33 arm#44 room 45
    (46, 25.0),  // CODE 33 arm#45 room 46
    (47, 25.0),  // CODE 33 arm#46 room 47
    (48, 25.0),  // CODE 33 arm#47 room 48
    (49, 26.0),  // CODE 33 arm#48 room 49
    (50, 26.0),  // CODE 33 arm#49 room 50
    (51, 26.0),  // CODE 33 arm#50 room 51
    (52, 26.0),  // CODE 33 arm#51 room 52
    (53, 26.0),  // CODE 33 arm#52 room 53
    (54, 26.0),  // CODE 33 arm#53 room 54
    (55, 26.0),  // CODE 33 arm#54 room 55
    (56, 26.0),  // CODE 33 arm#55 room 56
    (57, 26.0),  // CODE 33 arm#56 room 57
    (58, 26.0),  // CODE 33 arm#57 room 58
    (59, 26.0),  // CODE 33 arm#58 room 59
    (60, 26.0),  // CODE 33 arm#59 room 60
    (61, 26.0),  // CODE 33 arm#60 room 61
    (62, 26.0),  // CODE 33 arm#61 room 62
    (63, 26.0),  // CODE 33 arm#62 room 63
    (64, 26.0),  // CODE 33 arm#63 room 64
    (65, 27.0),  // CODE 33 arm#64 room 65
    (66, 27.0),  // CODE 33 arm#65 room 66
    (67, 27.0),  // CODE 33 arm#66 room 67
    (68, 27.0),  // CODE 33 arm#67 room 68
    (69, 27.0),  // CODE 33 arm#68 room 69
    (70, 27.0),  // CODE 33 arm#69 room 70
    (71, 27.0),  // CODE 33 arm#70 room 71
    (72, 27.0),  // CODE 33 arm#71 room 72
    (73, 27.0),  // CODE 33 arm#72 room 73
    (74, 27.0),  // CODE 33 arm#73 room 74
    (75, 27.0),  // CODE 33 arm#74 room 75
    (76, 27.0),  // CODE 33 arm#75 room 76
    (77, 27.0),  // CODE 33 arm#76 room 77
    (78, 27.0),  // CODE 33 arm#77 room 78
    (79, 27.0),  // CODE 33 arm#78 room 79
    (80, 27.0),  // CODE 33 arm#79 room 80
    (81, 27.0),  // CODE 33 arm#80 room 81
    (82, 27.0),  // CODE 33 arm#81 room 82
    (83, 28.0),  // CODE 33 arm#82 room 83
    (84, 28.0),  // CODE 33 arm#83 room 84
    (85, 28.0),  // CODE 33 arm#84 room 85
    (86, 28.0),  // CODE 33 arm#85 room 86
    (87, 28.0),  // CODE 33 arm#86 room 87
    (88, 28.0),  // CODE 33 arm#87 room 88
    (89, 28.0),  // CODE 33 arm#88 room 89
    (90, 28.0),  // CODE 33 arm#89 room 90
    (91, 28.0),  // CODE 33 arm#90 room 91
    (92, 28.0),  // CODE 33 arm#91 room 92
    (93, 28.0),  // CODE 33 arm#92 room 93
    (94, 28.0),  // CODE 33 arm#93 room 94
    (95, 28.0),  // CODE 33 arm#94 room 95
    (96, 28.0),  // CODE 33 arm#95 room 96
    (97, 28.0),  // CODE 33 arm#96 room 97
    (98, 28.0),  // CODE 33 arm#97 room 98
    (99, 28.0),  // CODE 33 arm#98 room 99
    (100, 28.0), // CODE 33 arm#99 room 100
    (101, 28.0), // CODE 33 arm#100 room 101
    (102, 28.0), // CODE 33 arm#101 room 102
    (103, 28.0), // CODE 33 arm#102 room 103
    (104, 28.0), // CODE 33 arm#103 room 104
    (105, 28.0), // CODE 33 arm#104 room 105
    (106, 28.0), // CODE 33 arm#105 room 106
    (107, 28.0), // CODE 33 arm#106 room 107
    (108, 28.0), // CODE 33 arm#107 room 108
    (109, 28.0), // CODE 33 arm#108 room 109
];

/// CODE 28's arm table, bytecode order: 105 arms over rooms 0..=104, every
/// guard constant distinct, arm#N = row N.
const BOULDER_ARMS: [(i32, f64); 105] = [
    (0, 7.0),    // CODE 28 arm#0 room 0
    (1, 7.0),    // CODE 28 arm#1 room 1
    (2, 7.0),    // CODE 28 arm#2 room 2
    (3, 7.0),    // CODE 28 arm#3 room 3
    (4, 7.0),    // CODE 28 arm#4 room 4
    (5, 7.0),    // CODE 28 arm#5 room 5
    (6, 7.0),    // CODE 28 arm#6 room 6
    (7, 7.0),    // CODE 28 arm#7 room 7
    (8, 7.0),    // CODE 28 arm#8 room 8
    (9, 7.0),    // CODE 28 arm#9 room 9
    (10, 7.0),   // CODE 28 arm#10 room 10
    (11, 10.0),  // CODE 28 arm#11 room 11
    (12, 10.0),  // CODE 28 arm#12 room 12
    (13, 10.0),  // CODE 28 arm#13 room 13
    (14, 10.0),  // CODE 28 arm#14 room 14
    (15, 10.0),  // CODE 28 arm#15 room 15
    (16, 10.0),  // CODE 28 arm#16 room 16
    (17, 10.0),  // CODE 28 arm#17 room 17
    (18, 10.0),  // CODE 28 arm#18 room 18
    (19, 10.0),  // CODE 28 arm#19 room 19
    (20, 10.0),  // CODE 28 arm#20 room 20
    (21, 10.0),  // CODE 28 arm#21 room 21
    (22, 10.0),  // CODE 28 arm#22 room 22
    (23, 10.0),  // CODE 28 arm#23 room 23
    (24, 10.0),  // CODE 28 arm#24 room 24
    (25, 10.0),  // CODE 28 arm#25 room 25
    (26, 10.0),  // CODE 28 arm#26 room 26
    (27, 10.0),  // CODE 28 arm#27 room 27
    (28, 13.0),  // CODE 28 arm#28 room 28
    (29, 13.0),  // CODE 28 arm#29 room 29
    (30, 13.0),  // CODE 28 arm#30 room 30
    (31, 13.0),  // CODE 28 arm#31 room 31
    (32, 13.0),  // CODE 28 arm#32 room 32
    (33, 13.0),  // CODE 28 arm#33 room 33
    (34, 13.0),  // CODE 28 arm#34 room 34
    (35, 13.0),  // CODE 28 arm#35 room 35
    (36, 13.0),  // CODE 28 arm#36 room 36
    (37, 13.0),  // CODE 28 arm#37 room 37
    (38, 13.0),  // CODE 28 arm#38 room 38
    (39, 13.0),  // CODE 28 arm#39 room 39
    (40, 13.0),  // CODE 28 arm#40 room 40
    (41, 13.0),  // CODE 28 arm#41 room 41
    (42, 13.0),  // CODE 28 arm#42 room 42
    (43, 13.0),  // CODE 28 arm#43 room 43
    (44, 13.0),  // CODE 28 arm#44 room 44
    (45, 13.0),  // CODE 28 arm#45 room 45
    (46, 13.0),  // CODE 28 arm#46 room 46
    (47, 13.0),  // CODE 28 arm#47 room 47
    (48, 13.0),  // CODE 28 arm#48 room 48
    (49, 16.0),  // CODE 28 arm#49 room 49
    (50, 16.0),  // CODE 28 arm#50 room 50
    (51, 16.0),  // CODE 28 arm#51 room 51
    (52, 16.0),  // CODE 28 arm#52 room 52
    (53, 16.0),  // CODE 28 arm#53 room 53
    (54, 16.0),  // CODE 28 arm#54 room 54
    (55, 16.0),  // CODE 28 arm#55 room 55
    (56, 16.0),  // CODE 28 arm#56 room 56
    (57, 16.0),  // CODE 28 arm#57 room 57
    (58, 16.0),  // CODE 28 arm#58 room 58
    (59, 16.0),  // CODE 28 arm#59 room 59
    (60, 16.0),  // CODE 28 arm#60 room 60
    (61, 16.0),  // CODE 28 arm#61 room 61
    (62, 16.0),  // CODE 28 arm#62 room 62
    (63, 16.0),  // CODE 28 arm#63 room 63
    (64, 16.0),  // CODE 28 arm#64 room 64
    (65, 19.0),  // CODE 28 arm#65 room 65
    (66, 19.0),  // CODE 28 arm#66 room 66
    (67, 19.0),  // CODE 28 arm#67 room 67
    (68, 19.0),  // CODE 28 arm#68 room 68
    (69, 19.0),  // CODE 28 arm#69 room 69
    (70, 19.0),  // CODE 28 arm#70 room 70
    (71, 19.0),  // CODE 28 arm#71 room 71
    (72, 19.0),  // CODE 28 arm#72 room 72
    (73, 19.0),  // CODE 28 arm#73 room 73
    (74, 19.0),  // CODE 28 arm#74 room 74
    (75, 19.0),  // CODE 28 arm#75 room 75
    (76, 19.0),  // CODE 28 arm#76 room 76
    (77, 19.0),  // CODE 28 arm#77 room 77
    (78, 19.0),  // CODE 28 arm#78 room 78
    (79, 19.0),  // CODE 28 arm#79 room 79
    (80, 19.0),  // CODE 28 arm#80 room 80
    (81, 19.0),  // CODE 28 arm#81 room 81
    (82, 19.0),  // CODE 28 arm#82 room 82
    (83, 22.0),  // CODE 28 arm#83 room 83
    (84, 22.0),  // CODE 28 arm#84 room 84
    (85, 22.0),  // CODE 28 arm#85 room 85
    (86, 22.0),  // CODE 28 arm#86 room 86
    (87, 22.0),  // CODE 28 arm#87 room 87
    (88, 22.0),  // CODE 28 arm#88 room 88
    (89, 22.0),  // CODE 28 arm#89 room 89
    (90, 22.0),  // CODE 28 arm#90 room 90
    (91, 22.0),  // CODE 28 arm#91 room 91
    (92, 22.0),  // CODE 28 arm#92 room 92
    (93, 22.0),  // CODE 28 arm#93 room 93
    (94, 22.0),  // CODE 28 arm#94 room 94
    (95, 22.0),  // CODE 28 arm#95 room 95
    (96, 22.0),  // CODE 28 arm#96 room 96
    (97, 22.0),  // CODE 28 arm#97 room 97
    (98, 22.0),  // CODE 28 arm#98 room 98
    (99, 22.0),  // CODE 28 arm#99 room 99
    (100, 22.0), // CODE 28 arm#100 room 100
    (101, 22.0), // CODE 28 arm#101 room 101
    (102, 22.0), // CODE 28 arm#102 room 102
    (103, 22.0), // CODE 28 arm#103 room 103
    (104, 22.0), // CODE 28 arm#104 room 104
];

/// What `extract()` reads back out of the bytecode.
struct Table {
    /// (guard room constant, stored sprite_index) per arm, bytecode order.
    arms: Vec<(i32, f64)>,
    /// code_offset of the `b` that follows the last `bt`: the unmatched-room
    /// fall-through edge, which jumps over the whole arm block.
    tail_b: usize,
    /// code_offset of the shared exit the tail edge and every arm's `b` land on.
    exit: usize,
    /// (room, first arm#, later arm#) for guard constants that repeat; empty
    /// here, kept so a duplicated arm can never be silently collapsed.
    duplicates: Vec<(i32, usize, usize)>,
}

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

fn field(s: &Scene, id: i32, name: &str) -> Option<f64> {
    s.instances
        .get(&id)
        .and_then(|i| i.fields.get(name))
        .copied()
}

/// Decodes the switch table for `code_id` out of the bundle's bytecode: the
/// guard chain, each arm body (`constant V; store sprite_index; b <exit>`), the
/// unmatched-room tail edge and the shared exit.
fn extract(b: &Bundle, code_id: usize) -> Table {
    let code = b
        .codes
        .iter()
        .find(|c| c.id == code_id)
        .unwrap_or_else(|| panic!("CODE {code_id} is in the bundle"));
    let ins = &code.instructions;
    let start = code.start;
    let at = |offset: usize| {
        ins.iter()
            .position(|x| x.code_offset == offset)
            .unwrap_or_else(|| {
                panic!("CODE {code_id}: offset {offset} is not an instruction boundary")
            })
    };
    // The preamble may not touch the field the arms own, so a per-arm store is
    // the only writer of sprite_index in this body.
    let mut p = ins
        .iter()
        .position(|x| {
            matches!(&x.op, Op::Load { name, selector, array, other }
                if name == "room" && *selector == -1 && !*array && !*other)
        })
        .unwrap_or_else(|| panic!("CODE {code_id}: the switch guard reads `room`"));
    for x in &ins[..p] {
        assert!(
            !matches!(&x.op, Op::Store { name, .. } if name == "sprite_index"),
            "CODE {code_id}: the preamble at co {} must not store sprite_index",
            x.code_offset
        );
    }
    let mut arms: Vec<(i32, f64)> = Vec::new();
    let mut exits: Vec<usize> = Vec::new();
    p += 1;
    while p + 3 < ins.len() {
        let (dup, constant, cmp, bt) = (&ins[p].op, &ins[p + 1].op, &ins[p + 2].op, &ins[p + 3].op);
        let (room, target) = match (dup, constant, cmp, bt) {
            (Op::Dup, Op::Constant { value }, Op::Cmp { comparison: 3 }, Op::Bt { target }) => {
                (*value as i32, *target - start)
            }
            _ => break,
        };
        // The arm body, decoded from its own bt target: exactly one constant
        // feeding exactly one store of exactly one field, then the branch out.
        let k = at(target);
        let value = match &ins[k].op {
            Op::Constant { value } => *value,
            other => panic!(
                "CODE {code_id} arm#{}: entry is not a constant: {other:?}",
                arms.len()
            ),
        };
        match &ins[k + 1].op {
            Op::Store {
                name,
                selector,
                array,
                other,
            } => assert!(
                name == "sprite_index" && *selector == -1 && !*array && !*other,
                "CODE {code_id} arm#{}: unexpected store {name} (selector {selector})",
                arms.len()
            ),
            other => panic!(
                "CODE {code_id} arm#{}: entry + 1 is not a store: {other:?}",
                arms.len()
            ),
        }
        let exit = match &ins[k + 2].op {
            Op::B { target } => *target - start,
            other => panic!(
                "CODE {code_id} arm#{}: arm does not branch out: {other:?}",
                arms.len()
            ),
        };
        arms.push((room, value));
        exits.push(exit);
        p += 4;
    }
    // The switch chain ends exactly at the unmatched-room edge: a lone `b` that
    // jumps over the arm block to the shared exit.
    let (tail_co, exit) = match ins.get(p).map(|x| (&x.op, x.code_offset)) {
        Some((Op::B { target }, co)) => (co, *target - start),
        other => panic!(
            "CODE {code_id}: no `b` edge after the last bt at index {p} (arms so far {}): {other:?}",
            arms.len()
        ),
    };
    // Every arm joins the same exit, and that exit is the body's last
    // instruction: a lone `popz`. Nothing between the tail edge and the exit
    // (i.e. no arm body) can store, so an unmatched room stores nothing at all.
    for (n, e) in exits.iter().enumerate() {
        assert_eq!(*e, exit, "CODE {code_id} arm#{n}: arms share one exit");
    }
    let last = ins.last().expect("non-empty body");
    assert!(
        matches!(last.op, Op::Popz),
        "CODE {code_id}: the body ends in popz"
    );
    assert_eq!(
        last.code_offset, exit,
        "CODE {code_id}: the shared exit is the body's tail"
    );
    assert_eq!(
        code.end - start,
        exit + 4,
        "CODE {code_id}: nothing follows the exit"
    );
    let mut duplicates = Vec::new();
    let mut seen: Vec<(i32, usize)> = Vec::new();
    for (n, (room, _)) in arms.iter().enumerate() {
        if let Some((_, first)) = seen.iter().find(|(r, _)| r == room) {
            duplicates.push((*room, *first, n));
        } else {
            seen.push((*room, n));
        }
    }
    Table {
        arms,
        tail_b: tail_co,
        exit,
        duplicates,
    }
}

/// The rule the shipped `bt` chain implements: the arms are a linear chain in
/// bytecode order, arm i+1 is only reached when arm i did not match, so the
/// FIRST arm carrying the room constant is the one that runs.
fn first_match(arms: &[(i32, f64)], room: i32) -> Option<f64> {
    arms.iter().find(|(k, _)| *k == room).map(|(_, v)| *v)
}

/// Every arm of CODE 33: set the room, create the platform, the Create body
/// selects that room's sprite.
#[test]
fn code_33_platform_every_arm_selects_its_shipped_sprite() {
    let b = bundle();
    let t = extract(&b, PLATFORM_CODE);
    assert_eq!(
        t.arms,
        PLATFORM_ARMS.to_vec(),
        "the embedded table is the bytecode table"
    );
    let mut s = scene(&b);
    for (n, (room, sprite)) in PLATFORM_ARMS.iter().enumerate() {
        s.current_room = *room as f64;
        let id = s
            .create(&b, PLATFORM, 100.0, 100.0)
            .unwrap_or_else(|e| panic!("CODE 33 arm#{n} (room {room}): {e}"));
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(*sprite),
            "CODE 33 arm#{n}: room {room} selects sprite {sprite}"
        );
        assert_eq!(
            field(&s, id, "type"),
            Some(2.0),
            "CODE 33 arm#{n}: preamble keeps type = 2"
        );
    }
    assert_eq!(PLATFORM_ARMS.len(), 109, "CODE 33: the shipped arm count");
}

/// Every arm of CODE 28, same drive on the boulder.
#[test]
fn code_28_bossboulder_every_arm_selects_its_shipped_sprite() {
    let b = bundle();
    let t = extract(&b, BOULDER_CODE);
    assert_eq!(
        t.arms,
        BOULDER_ARMS.to_vec(),
        "the embedded table is the bytecode table"
    );
    let mut s = scene(&b);
    for (n, (room, sprite)) in BOULDER_ARMS.iter().enumerate() {
        s.current_room = *room as f64;
        let id = s
            .create(&b, BOULDER, 100.0, 100.0)
            .unwrap_or_else(|e| panic!("CODE 28 arm#{n} (room {room}): {e}"));
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(*sprite),
            "CODE 28 arm#{n}: room {room} selects sprite {sprite}"
        );
        assert_eq!(
            field(&s, id, "type"),
            Some(1.0),
            "CODE 28 arm#{n}: preamble keeps type = 1"
        );
    }
    assert_eq!(BOULDER_ARMS.len(), 105, "CODE 28: the shipped arm count");
}

/// The accounting the branch-table discipline asks for: arm count against
/// distinct guard constants, bytecode order preserved, duplicates surfaced
/// rather than collapsed, and the first-match resolution rule pinned.
#[test]
fn arm_accounting_guard_order_and_first_match_rule() {
    let b = bundle();
    let cases: [(usize, &[(i32, f64)], usize); 2] = [
        (PLATFORM_CODE, &PLATFORM_ARMS[..], 109),
        (BOULDER_CODE, &BOULDER_ARMS[..], 105),
    ];
    for (code_id, table, expected_arms) in cases {
        let t = extract(&b, code_id);
        let distinct: BTreeSet<i32> = table.iter().map(|(r, _)| *r).collect();
        assert_eq!(
            table.len(),
            expected_arms,
            "CODE {code_id}: shipped arm count"
        );
        assert_eq!(
            t.arms.len(),
            table.len(),
            "CODE {code_id}: IR arms == table rows"
        );
        assert_eq!(
            distinct.len(),
            table.len(),
            "CODE {code_id}: {} arms carry {} distinct room constants",
            table.len(),
            distinct.len()
        );
        assert!(
            t.duplicates.is_empty(),
            "CODE {code_id}: this body has no duplicate guard constant; if it ever gains one, \
             the earlier arm wins and the duplicate must stay in the table: {:?}",
            t.duplicates
        );
        // Bytecode order, preserved: the guards ascend one at a time, so row N
        // is arm#N and the census comment on each row is that arm's number.
        for (n, w) in table.windows(2).enumerate() {
            assert_eq!(
                w[1].0,
                w[0].0 + 1,
                "CODE {code_id}: guard order around arm#{}",
                n + 1
            );
        }
        for (n, (room, sprite)) in table.iter().enumerate() {
            assert_eq!(
                first_match(table, *room),
                Some(*sprite),
                "CODE {code_id} arm#{n}: room {room} resolves to the first matching arm"
            );
            assert_eq!(
                t.arms[n],
                (*room, *sprite),
                "CODE {code_id} arm#{n}: row order"
            );
        }
    }
    // The duplicate-arm shape the rule exists for: synthetic, because this
    // bundle ships none (the background table's 114 arms are 114 distinct
    // constants over rooms 0..=113, not 111). Under that chain the earlier arm
    // is the live one: a later arm carrying the same constant is only reachable
    // when control falls past its predecessor, and the predecessor's own `b`
    // jumps over it, so the late arm never runs.
    let synthetic = [(1, 8.0), (1, 9.0), (2, 10.0)];
    assert_eq!(first_match(&synthetic, 1), Some(8.0), "the first arm wins");
    assert_eq!(first_match(&synthetic, 2), Some(10.0));
    assert_eq!(
        first_match(&synthetic, 3),
        None,
        "no arm matches: fall through"
    );
}

/// The negative case, read out of the bytecode tail rather than assumed: after
/// the last `bt` comes a lone `b` (CODE 33 co 1764, CODE 28 co 1720) that jumps
/// over the whole arm block to the shared exit (co 3512 / 3404), and that exit
/// is the body's last instruction, a single `popz`. An unmatched room therefore
/// runs no arm and no store.
#[test]
fn rooms_outside_the_guard_set_fall_through_without_storing() {
    let b = bundle();
    let p = extract(&b, PLATFORM_CODE);
    let bd = extract(&b, BOULDER_CODE);
    assert_eq!(
        (p.tail_b, p.exit),
        (1764, 3512),
        "CODE 33: the unmatched-room edge"
    );
    assert_eq!(
        (bd.tail_b, bd.exit),
        (1720, 3404),
        "CODE 28: the unmatched-room edge"
    );
    // The object records behind the two tables, which is all that is left in
    // sprite_index when nothing stores: obj_platform 23, obj_bossboulder 10.
    let default_of = |object: i32| {
        b.objects
            .iter()
            .find(|o| o.id == object)
            .expect("object record")
            .sprite as f64
    };
    assert_eq!(default_of(PLATFORM), 23.0);
    assert_eq!(default_of(BOULDER), 10.0);

    let mut s = scene(&b);
    // Rooms 1..=109 own an arm on CODE 33: 0 is below the table, 110/111/999
    // above it. CODE 28's table starts at room 0, so only the upper side exists.
    for room in [0, 110, 111, 999] {
        s.current_room = room as f64;
        let id = s.create(&b, PLATFORM, 100.0, 100.0).expect("platform");
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(23.0),
            "CODE 33: room {room} matches no arm - obj_platform keeps its own sprite"
        );
        // Room 1 also selects 23, so the value alone cannot separate "arm#0 ran"
        // from "nothing ran". The sentinel does: only a real store can overwrite
        // it, and an out-of-table room must leave it untouched.
        s.instances
            .get_mut(&id)
            .unwrap()
            .fields
            .insert("sprite_index".into(), -999.0);
        s.dispatch(&b, id, 0, 0).expect("re-run the Create body");
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(-999.0),
            "CODE 33: room {room} runs no store at all (the fall-through never executes an arm)"
        );
    }
    for room in [105, 106, 999] {
        s.current_room = room as f64;
        let id = s.create(&b, BOULDER, 100.0, 100.0).expect("boulder");
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(10.0),
            "CODE 28: room {room} matches no arm - obj_bossboulder keeps its own sprite"
        );
        s.instances
            .get_mut(&id)
            .unwrap()
            .fields
            .insert("sprite_index".into(), -999.0);
        s.dispatch(&b, id, 0, 0).expect("re-run the Create body");
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(-999.0),
            "CODE 28: room {room} runs no store at all"
        );
    }
    // Control for the sentinel probe: an in-table room does overwrite it, on the
    // same drive, so the assertions above are about the arm chain, not about a
    // body that stopped running.
    for (object, room, sprite, code) in [
        (PLATFORM, 16, 24.0, PLATFORM_CODE),
        (PLATFORM, 109, 28.0, PLATFORM_CODE),
        (BOULDER, 0, 7.0, BOULDER_CODE),
        (BOULDER, 104, 22.0, BOULDER_CODE),
    ] {
        s.current_room = room as f64;
        let id = s.create(&b, object, 100.0, 100.0).expect("instance");
        s.instances
            .get_mut(&id)
            .unwrap()
            .fields
            .insert("sprite_index".into(), -999.0);
        s.dispatch(&b, id, 0, 0).expect("re-run the Create body");
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(sprite),
            "CODE {code}: room {room} overwrites the sentinel - the arm really runs"
        );
    }
}
