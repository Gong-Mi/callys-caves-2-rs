//! CODE 34 (obj_watersurface Create) and CODE 35 (obj_waterfill Create): the
//! per-room water-surface / water-fill `sprite_index` tables, enumerated arm by
//! arm. Both bodies are the same shipped shape - a flat `switch (room)`:
//!
//!   load room; [dup; constant K; cmp eq; bt L_K] * 110; b <popz>; L_0 .. L_109
//!
//! 110 arms, room constants 0..=109, one `constant V; store sprite_index` pair
//! per arm, every arm body ending in `b <popz>`. The expected tables below are
//! generated straight from the bundle bytecode
//! (`crates/core/src/generated/full_ir.json`), never from room names or sprite
//! names: the extraction walks each `bt` target and decodes the
//! `constant V; store sprite_index` pairs it reaches before the arm's `b`.
//!
//! Extraction (exactly what produced the tables below; run from the repo root):
//!
//!   python3 - <<'PY'
//!   import json
//!   codes = {c["id"]: c for c in json.load(open("crates/core/src/generated/full_ir.json"))["codes"]}
//!   for cid in (34, 35):
//!       c = codes[cid]
//!       ins = sorted(c["instructions"], key=lambda i: i["code_offset"])
//!       idx = {i["code_offset"]: n for n, i in enumerate(ins)}
//!       n, chain = 1, []
//!       while ins[n]["op"] == "dup":                    # dup; constant K; cmp eq; bt L_K
//!           chain.append((ins[n + 1]["value"], ins[n + 3]["target"] - c["start"]))
//!           n += 4
//!       print(cid, "tail:", ins[n]["op"], ins[n]["target"] - c["start"])   # bare `b` -> popz
//!       for room, target in chain:                      # walk each arm body
//!           stores, j = [], idx[target]
//!           while ins[j]["op"] != "b":                  # constant V; store sprite_index
//!               stores.append(ins[j + 1]["value"]); j += 2
//!           print(cid, "room", room, "stores", stores, "final", stores[-1])
//!   PY
//!
//! Every arm printed exactly one pair except arm 0, whose list carries two.
//!
//! Semantics pinned here that no suite owned before:
//! - each of the 110 arms is selected by exactly one room value and writes one
//!   shipped constant; the arms that write the object's own default sprite
//!   (104 for obj_watersurface, 103 for obj_waterfill) are still real per-arm
//!   stores, not fall-through - the distinction only becomes visible with the
//!   executed-trace assertions below;
//! - arm 0 is the ONE arm with no `b`: its body is just `constant V; store
//!   sprite_index` and control falls THROUGH into arm 1's body, so room 0 runs
//!   two stores and the second wins (watersurface: 104 then 104; waterfill:
//!   100 then 103). The tables carry the surviving value;
//! - an unmatched room never reaches a store: the chain's tail is a bare
//!   `b <popz>`, so `sprite_index` keeps the object definition's sprite. Because
//!   that default equals what many arms store, the negative case also asserts
//!   that not one store instruction ran.
//!
//! Arm-count audit (the discipline the RoomCC sweep taught): both bodies carry
//! 110 arms with 110 distinct room constants, asserted by re-parsing the live
//! bundle in `arm_count_equals_distinct_constants_and_the_body_shape_is_the_flat_switch`.
//! That check is not a formality - a switched body can carry MORE arms than it
//! has distinct constants, and there first-match-wins makes the later arms dead
//! code that an arm-level table must not flatten. The brief cited CODE 360 as
//! such a body (114 arms over roughly 111 values); re-parsing it here gives 114
//! `dup/constant/cmp/bt` groups over 114 distinct constants 0..=113 with no
//! duplicate, so that hazard does not show up in the shipped IR - which is the
//! reason this suite asserts the shape per body instead of assuming either way.
//!
//! Evidence boundary: this is regression evidence over the rewritten runtime's
//! IR - it pins the shipped bytecode's arm-level semantics, not equivalence with
//! the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Op};
use callys_core::ir_scene::Scene;
use std::path::Path;

/// obj_watersurface - its Create body is CODE 34.
const WATERSURFACE: i32 = 9;
/// obj_waterfill - its Create body is CODE 35.
const WATERFILL: i32 = 10;

// CODE 34 (obj_watersurface Create) - 110 arms, rooms 0..=109.
// Room runs: 0..=27 -> 104.0, 28..=48 -> 101.0, 49..=64 -> 104.0, 65..=109 -> 101.0.
// 44 arms store 104.0 (the object's own sprite, still a real per-arm store) and
// 66 arms store 101.0.
const WATERSURFACE_TABLE: [(i32, f64); 110] = [
    // The one arm with no `b`: room 0 executes its own `constant 104; store
    // sprite_index` and then falls THROUGH into arm 1's body, so the second
    // store (104) is what survives on the instance.
    // Both writes are 104 here (the object's own default); room 1 below
    // reaches the same final sprite from a single store.
    (0, 104.0),   // CODE 34 arm 0
    (1, 104.0),   // CODE 34 arm 1
    (2, 104.0),   // CODE 34 arm 2
    (3, 104.0),   // CODE 34 arm 3
    (4, 104.0),   // CODE 34 arm 4
    (5, 104.0),   // CODE 34 arm 5
    (6, 104.0),   // CODE 34 arm 6
    (7, 104.0),   // CODE 34 arm 7
    (8, 104.0),   // CODE 34 arm 8
    (9, 104.0),   // CODE 34 arm 9
    (10, 104.0),  // CODE 34 arm 10
    (11, 104.0),  // CODE 34 arm 11
    (12, 104.0),  // CODE 34 arm 12
    (13, 104.0),  // CODE 34 arm 13
    (14, 104.0),  // CODE 34 arm 14
    (15, 104.0),  // CODE 34 arm 15
    (16, 104.0),  // CODE 34 arm 16
    (17, 104.0),  // CODE 34 arm 17
    (18, 104.0),  // CODE 34 arm 18
    (19, 104.0),  // CODE 34 arm 19
    (20, 104.0),  // CODE 34 arm 20
    (21, 104.0),  // CODE 34 arm 21
    (22, 104.0),  // CODE 34 arm 22
    (23, 104.0),  // CODE 34 arm 23
    (24, 104.0),  // CODE 34 arm 24
    (25, 104.0),  // CODE 34 arm 25
    (26, 104.0),  // CODE 34 arm 26
    (27, 104.0),  // CODE 34 arm 27
    (28, 101.0),  // CODE 34 arm 28
    (29, 101.0),  // CODE 34 arm 29
    (30, 101.0),  // CODE 34 arm 30
    (31, 101.0),  // CODE 34 arm 31
    (32, 101.0),  // CODE 34 arm 32
    (33, 101.0),  // CODE 34 arm 33
    (34, 101.0),  // CODE 34 arm 34
    (35, 101.0),  // CODE 34 arm 35
    (36, 101.0),  // CODE 34 arm 36
    (37, 101.0),  // CODE 34 arm 37
    (38, 101.0),  // CODE 34 arm 38
    (39, 101.0),  // CODE 34 arm 39
    (40, 101.0),  // CODE 34 arm 40
    (41, 101.0),  // CODE 34 arm 41
    (42, 101.0),  // CODE 34 arm 42
    (43, 101.0),  // CODE 34 arm 43
    (44, 101.0),  // CODE 34 arm 44
    (45, 101.0),  // CODE 34 arm 45
    (46, 101.0),  // CODE 34 arm 46
    (47, 101.0),  // CODE 34 arm 47
    (48, 101.0),  // CODE 34 arm 48
    (49, 104.0),  // CODE 34 arm 49
    (50, 104.0),  // CODE 34 arm 50
    (51, 104.0),  // CODE 34 arm 51
    (52, 104.0),  // CODE 34 arm 52
    (53, 104.0),  // CODE 34 arm 53
    (54, 104.0),  // CODE 34 arm 54
    (55, 104.0),  // CODE 34 arm 55
    (56, 104.0),  // CODE 34 arm 56
    (57, 104.0),  // CODE 34 arm 57
    (58, 104.0),  // CODE 34 arm 58
    (59, 104.0),  // CODE 34 arm 59
    (60, 104.0),  // CODE 34 arm 60
    (61, 104.0),  // CODE 34 arm 61
    (62, 104.0),  // CODE 34 arm 62
    (63, 104.0),  // CODE 34 arm 63
    (64, 104.0),  // CODE 34 arm 64
    (65, 101.0),  // CODE 34 arm 65
    (66, 101.0),  // CODE 34 arm 66
    (67, 101.0),  // CODE 34 arm 67
    (68, 101.0),  // CODE 34 arm 68
    (69, 101.0),  // CODE 34 arm 69
    (70, 101.0),  // CODE 34 arm 70
    (71, 101.0),  // CODE 34 arm 71
    (72, 101.0),  // CODE 34 arm 72
    (73, 101.0),  // CODE 34 arm 73
    (74, 101.0),  // CODE 34 arm 74
    (75, 101.0),  // CODE 34 arm 75
    (76, 101.0),  // CODE 34 arm 76
    (77, 101.0),  // CODE 34 arm 77
    (78, 101.0),  // CODE 34 arm 78
    (79, 101.0),  // CODE 34 arm 79
    (80, 101.0),  // CODE 34 arm 80
    (81, 101.0),  // CODE 34 arm 81
    (82, 101.0),  // CODE 34 arm 82
    (83, 101.0),  // CODE 34 arm 83
    (84, 101.0),  // CODE 34 arm 84
    (85, 101.0),  // CODE 34 arm 85
    (86, 101.0),  // CODE 34 arm 86
    (87, 101.0),  // CODE 34 arm 87
    (88, 101.0),  // CODE 34 arm 88
    (89, 101.0),  // CODE 34 arm 89
    (90, 101.0),  // CODE 34 arm 90
    (91, 101.0),  // CODE 34 arm 91
    (92, 101.0),  // CODE 34 arm 92
    (93, 101.0),  // CODE 34 arm 93
    (94, 101.0),  // CODE 34 arm 94
    (95, 101.0),  // CODE 34 arm 95
    (96, 101.0),  // CODE 34 arm 96
    (97, 101.0),  // CODE 34 arm 97
    (98, 101.0),  // CODE 34 arm 98
    (99, 101.0),  // CODE 34 arm 99
    (100, 101.0), // CODE 34 arm 100
    (101, 101.0), // CODE 34 arm 101
    (102, 101.0), // CODE 34 arm 102
    (103, 101.0), // CODE 34 arm 103
    (104, 101.0), // CODE 34 arm 104
    (105, 101.0), // CODE 34 arm 105
    (106, 101.0), // CODE 34 arm 106
    (107, 101.0), // CODE 34 arm 107
    (108, 101.0), // CODE 34 arm 108
    (109, 101.0), // CODE 34 arm 109
];

// CODE 35 (obj_waterfill Create) - 110 arms, rooms 0..=109.
// Room runs: 0..=27 -> 103.0, 28..=48 -> 100.0, 49..=64 -> 103.0, 65..=109 -> 100.0.
// 44 arms store 103.0 (the object's own sprite, still a real per-arm store) and
// 66 arms store 100.0.
const WATERFILL_TABLE: [(i32, f64); 110] = [
    // The one arm with no `b`: room 0 executes its own `constant 100; store
    // sprite_index` and then falls THROUGH into arm 1's body, so the second
    // store (103) is what survives on the instance.
    (0, 103.0),   // CODE 35 arm 0
    (1, 103.0),   // CODE 35 arm 1
    (2, 103.0),   // CODE 35 arm 2
    (3, 103.0),   // CODE 35 arm 3
    (4, 103.0),   // CODE 35 arm 4
    (5, 103.0),   // CODE 35 arm 5
    (6, 103.0),   // CODE 35 arm 6
    (7, 103.0),   // CODE 35 arm 7
    (8, 103.0),   // CODE 35 arm 8
    (9, 103.0),   // CODE 35 arm 9
    (10, 103.0),  // CODE 35 arm 10
    (11, 103.0),  // CODE 35 arm 11
    (12, 103.0),  // CODE 35 arm 12
    (13, 103.0),  // CODE 35 arm 13
    (14, 103.0),  // CODE 35 arm 14
    (15, 103.0),  // CODE 35 arm 15
    (16, 103.0),  // CODE 35 arm 16
    (17, 103.0),  // CODE 35 arm 17
    (18, 103.0),  // CODE 35 arm 18
    (19, 103.0),  // CODE 35 arm 19
    (20, 103.0),  // CODE 35 arm 20
    (21, 103.0),  // CODE 35 arm 21
    (22, 103.0),  // CODE 35 arm 22
    (23, 103.0),  // CODE 35 arm 23
    (24, 103.0),  // CODE 35 arm 24
    (25, 103.0),  // CODE 35 arm 25
    (26, 103.0),  // CODE 35 arm 26
    (27, 103.0),  // CODE 35 arm 27
    (28, 100.0),  // CODE 35 arm 28
    (29, 100.0),  // CODE 35 arm 29
    (30, 100.0),  // CODE 35 arm 30
    (31, 100.0),  // CODE 35 arm 31
    (32, 100.0),  // CODE 35 arm 32
    (33, 100.0),  // CODE 35 arm 33
    (34, 100.0),  // CODE 35 arm 34
    (35, 100.0),  // CODE 35 arm 35
    (36, 100.0),  // CODE 35 arm 36
    (37, 100.0),  // CODE 35 arm 37
    (38, 100.0),  // CODE 35 arm 38
    (39, 100.0),  // CODE 35 arm 39
    (40, 100.0),  // CODE 35 arm 40
    (41, 100.0),  // CODE 35 arm 41
    (42, 100.0),  // CODE 35 arm 42
    (43, 100.0),  // CODE 35 arm 43
    (44, 100.0),  // CODE 35 arm 44
    (45, 100.0),  // CODE 35 arm 45
    (46, 100.0),  // CODE 35 arm 46
    (47, 100.0),  // CODE 35 arm 47
    (48, 100.0),  // CODE 35 arm 48
    (49, 103.0),  // CODE 35 arm 49
    (50, 103.0),  // CODE 35 arm 50
    (51, 103.0),  // CODE 35 arm 51
    (52, 103.0),  // CODE 35 arm 52
    (53, 103.0),  // CODE 35 arm 53
    (54, 103.0),  // CODE 35 arm 54
    (55, 103.0),  // CODE 35 arm 55
    (56, 103.0),  // CODE 35 arm 56
    (57, 103.0),  // CODE 35 arm 57
    (58, 103.0),  // CODE 35 arm 58
    (59, 103.0),  // CODE 35 arm 59
    (60, 103.0),  // CODE 35 arm 60
    (61, 103.0),  // CODE 35 arm 61
    (62, 103.0),  // CODE 35 arm 62
    (63, 103.0),  // CODE 35 arm 63
    (64, 103.0),  // CODE 35 arm 64
    (65, 100.0),  // CODE 35 arm 65
    (66, 100.0),  // CODE 35 arm 66
    (67, 100.0),  // CODE 35 arm 67
    (68, 100.0),  // CODE 35 arm 68
    (69, 100.0),  // CODE 35 arm 69
    (70, 100.0),  // CODE 35 arm 70
    (71, 100.0),  // CODE 35 arm 71
    (72, 100.0),  // CODE 35 arm 72
    (73, 100.0),  // CODE 35 arm 73
    (74, 100.0),  // CODE 35 arm 74
    (75, 100.0),  // CODE 35 arm 75
    (76, 100.0),  // CODE 35 arm 76
    (77, 100.0),  // CODE 35 arm 77
    (78, 100.0),  // CODE 35 arm 78
    (79, 100.0),  // CODE 35 arm 79
    (80, 100.0),  // CODE 35 arm 80
    (81, 100.0),  // CODE 35 arm 81
    (82, 100.0),  // CODE 35 arm 82
    (83, 100.0),  // CODE 35 arm 83
    (84, 100.0),  // CODE 35 arm 84
    (85, 100.0),  // CODE 35 arm 85
    (86, 100.0),  // CODE 35 arm 86
    (87, 100.0),  // CODE 35 arm 87
    (88, 100.0),  // CODE 35 arm 88
    (89, 100.0),  // CODE 35 arm 89
    (90, 100.0),  // CODE 35 arm 90
    (91, 100.0),  // CODE 35 arm 91
    (92, 100.0),  // CODE 35 arm 92
    (93, 100.0),  // CODE 35 arm 93
    (94, 100.0),  // CODE 35 arm 94
    (95, 100.0),  // CODE 35 arm 95
    (96, 100.0),  // CODE 35 arm 96
    (97, 100.0),  // CODE 35 arm 97
    (98, 100.0),  // CODE 35 arm 98
    (99, 100.0),  // CODE 35 arm 99
    (100, 100.0), // CODE 35 arm 100
    (101, 100.0), // CODE 35 arm 101
    (102, 100.0), // CODE 35 arm 102
    (103, 100.0), // CODE 35 arm 103
    (104, 100.0), // CODE 35 arm 104
    (105, 100.0), // CODE 35 arm 105
    (106, 100.0), // CODE 35 arm 106
    (107, 100.0), // CODE 35 arm 107
    (108, 100.0), // CODE 35 arm 108
    (109, 100.0), // CODE 35 arm 109
];

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

fn body(b: &Bundle, code: usize) -> &callys_core::code_vm::Code {
    b.codes
        .iter()
        .find(|c| c.id == code)
        .unwrap_or_else(|| panic!("CODE {code} body"))
}

fn index_of(b: &Bundle, code: usize, offset: usize) -> usize {
    body(b, code)
        .instructions
        .iter()
        .position(|i| i.offset == offset)
        .unwrap_or_else(|| panic!("CODE {code}: no instruction at {offset}"))
}

fn field(s: &Scene, id: i32, name: &str) -> Option<f64> {
    s.instances
        .get(&id)
        .and_then(|i| i.fields.get(name))
        .copied()
}

/// The arm chain of a switched Create body, in arm order:
/// `load room; [dup; constant K; cmp eq; bt L_K] * N; b <shared exit>`.
/// Each entry is (room constant, absolute address of that arm's body).
fn arms(b: &Bundle, code: usize) -> Vec<(i32, usize)> {
    let ins = &body(b, code).instructions;
    assert!(
        matches!(&ins[0].op, Op::Load { name, .. } if name == "room"),
        "CODE {code}: the chain opens with `load room`"
    );
    let mut n = 1;
    let mut out = Vec::new();
    while n + 3 < ins.len() {
        if !matches!(&ins[n].op, Op::Dup) {
            break;
        }
        let k = match &ins[n + 1].op {
            Op::Constant { value } => *value,
            other => panic!(
                "CODE {code} arm {}: expected `constant K`, got {other:?}",
                out.len()
            ),
        };
        match &ins[n + 2].op {
            Op::Cmp { comparison } => {
                assert_eq!(*comparison, 3, "CODE {code} arm {k}: compares eq")
            }
            other => panic!("CODE {code} arm {k}: expected `cmp eq`, got {other:?}"),
        }
        let target = match &ins[n + 3].op {
            Op::Bt { target } => *target,
            other => panic!("CODE {code} arm {k}: expected `bt`, got {other:?}"),
        };
        out.push((k as i32, target));
        n += 4;
    }
    assert!(
        matches!(&ins[n].op, Op::B { .. }),
        "CODE {code}: the chain is followed by a bare jump (the unmatched path)"
    );
    out
}

/// The shipped driver: the arm selector reads `room` through the global
/// selector, which the host answers from `Scene::current_room`; `create` then
/// runs the Create event on the fresh instance - the same path
/// load_room_from_data takes.
fn create_in_room(b: &Bundle, s: &mut Scene, room: f64, object: i32) -> i32 {
    s.current_room = room;
    s.executed.clear();
    s.create(b, object, 64.0, 64.0)
        .unwrap_or_else(|e| panic!("create obj {object} in room {room}: {e}"))
}

/// Offsets of every `store` instruction in a body (the executed trace is a
/// (code, offset) ledger, so store offsets are what prove a store happened).
fn store_offsets(b: &Bundle, code: usize) -> Vec<usize> {
    body(b, code)
        .instructions
        .iter()
        .filter(|i| matches!(&i.op, Op::Store { name, .. } if name == "sprite_index"))
        .map(|i| i.offset)
        .collect()
}

#[test]
fn every_watersurface_arm_selects_its_shipped_sprite() {
    let b = bundle();
    let mut s = scene(&b);
    let chain = arms(&b, 34);
    assert_eq!(
        chain.len(),
        WATERSURFACE_TABLE.len(),
        "CODE 34: the extracted matrix enumerates every arm in the bytecode"
    );
    for ((room, addr), (want_room, sprite)) in chain.iter().zip(WATERSURFACE_TABLE) {
        assert_eq!(
            *room, want_room,
            "CODE 34: arm order follows the bytecode constants"
        );
        let id = create_in_room(&b, &mut s, *room as f64, WATERSURFACE);
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(sprite),
            "CODE 34 room {room} -> sprite_index"
        );
        assert!(
            s.executed.contains(&(34, *addr)),
            "CODE 34 room {room}: the arm body at {addr} did not run"
        );
    }
}

#[test]
fn every_waterfill_arm_selects_its_shipped_sprite() {
    let b = bundle();
    let mut s = scene(&b);
    let chain = arms(&b, 35);
    assert_eq!(
        chain.len(),
        WATERFILL_TABLE.len(),
        "CODE 35: the extracted matrix enumerates every arm in the bytecode"
    );
    for ((room, addr), (want_room, sprite)) in chain.iter().zip(WATERFILL_TABLE) {
        assert_eq!(
            *room, want_room,
            "CODE 35: arm order follows the bytecode constants"
        );
        let id = create_in_room(&b, &mut s, *room as f64, WATERFILL);
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(sprite),
            "CODE 35 room {room} -> sprite_index"
        );
        assert!(
            s.executed.contains(&(35, *addr)),
            "CODE 35 room {room}: the arm body at {addr} did not run"
        );
    }
}

/// 110 arms over 110 distinct room constants, for both bodies - so neither
/// table needs the first-match-wins tie-break the brief warns about (a body can
/// carry more arms than it has distinct constants; CODE 360 is cited as such a
/// table, and there the arms after the first occurrence are dead code that the
/// extraction must not flatten). This asserts the shape rather than assuming it,
/// so a future IR regeneration that introduces a duplicate fails here instead of
/// silently re-ordering a table.
#[test]
fn arm_count_equals_distinct_constants_and_the_body_shape_is_the_flat_switch() {
    let b = bundle();
    for (code, object, table_len) in [
        (34usize, WATERSURFACE, WATERSURFACE_TABLE.len()),
        (35, WATERFILL, WATERFILL_TABLE.len()),
    ] {
        let chain = arms(&b, code);
        assert_eq!(chain.len(), 110, "CODE {code}: arm count");
        assert_eq!(
            chain.len(),
            table_len,
            "CODE {code}: the matrix has one row per arm"
        );
        let mut ks: Vec<i32> = chain.iter().map(|(k, _)| *k).collect();
        let arms_n = ks.len();
        ks.sort_unstable();
        ks.dedup();
        assert_eq!(
            ks.len(),
            arms_n,
            "CODE {code} (obj {object}): 110 arms but only {} distinct room constants - \
             a duplicate arm would make the later one dead code (first match wins)",
            ks.len()
        );
        assert_eq!(
            (ks.first(), ks.last()),
            (Some(&0), Some(&109)),
            "CODE {code}: the shipped table covers room 0 through 109"
        );

        let c = body(&b, code);
        let count = |f: &dyn Fn(&Op) -> bool| c.instructions.iter().filter(|i| f(&i.op)).count();
        assert_eq!(
            count(&|o| matches!(o, Op::Load { .. })),
            1,
            "CODE {code}: one `load room`"
        );
        assert_eq!(
            count(&|o| matches!(o, Op::Dup)),
            110,
            "CODE {code}: one `dup` per arm"
        );
        assert_eq!(
            count(&|o| matches!(o, Op::Constant { .. })),
            220,
            "CODE {code}: 110 room constants + 110 shipped sprite constants"
        );
        assert_eq!(
            count(&|o| matches!(o, Op::Cmp { .. })),
            110,
            "CODE {code}: one `cmp eq` per arm"
        );
        assert_eq!(
            count(&|o| matches!(o, Op::Bt { .. })),
            110,
            "CODE {code}: one `bt` per arm"
        );
        assert_eq!(count(&|o| matches!(o, Op::B { .. })), 110,
            "CODE {code}: 109 arm-ending jumps + the chain tail - arm 0 has none (it falls through)");
        assert_eq!(
            store_offsets(&b, code).len(),
            110,
            "CODE {code}: one sprite store per arm"
        );
        assert_eq!(
            count(&|o| matches!(o, Op::Popz)),
            1,
            "CODE {code}: one shared `popz` exit"
        );
        assert_eq!(
            c.instructions.len(),
            772,
            "CODE {code}: shipped instruction count"
        );
        assert_eq!(
            c.end - c.start,
            3532,
            "CODE {code}: shipped body length in bytes"
        );
    }
}

/// The unmatched path, read out of the bytecode tail rather than assumed: after
/// the last `bt` the flow reaches a bare `b` whose target is the body's single
/// `popz`. No arm body is on that path, so an unmatched room leaves
/// `sprite_index` at the object definition's own sprite - and because that
/// default happens to equal what many arms store, the value assertion alone is
/// weak; the executed-trace assertion (zero stores ran) is the real one.
#[test]
fn an_unmatched_room_falls_through_to_the_popz_without_storing() {
    let b = bundle();
    for (code, object, default) in [(34usize, WATERSURFACE, 104.0), (35, WATERFILL, 103.0)] {
        let c = body(&b, code);
        // Bytecode tail: chain tail is a bare jump onto the body's last `popz`.
        // Index 0 is `load room`; the chain behind it is 110 four-instruction arms.
        let chain_end = 1 + 110 * 4;
        let tail = &c.instructions[chain_end];
        let popz = c.instructions.last().expect("body has instructions");
        assert!(
            matches!(&popz.op, Op::Popz),
            "CODE {code}: the exit is `popz`"
        );
        match &tail.op {
            Op::B { target } => assert_eq!(
                *target, popz.offset,
                "CODE {code}: the unmatched path jumps straight to the shared exit"
            ),
            other => panic!("CODE {code}: the chain tail is not a bare jump: {other:?}"),
        }
        // The object's own sprite is what survives the unmatched path.
        let shipped = b
            .objects
            .iter()
            .find(|o| o.id == object)
            .expect("object")
            .sprite as f64;
        assert_eq!(
            shipped, default,
            "CODE {code}: obj {object} ships sprite {default}"
        );

        let stores = store_offsets(&b, code);
        assert_eq!(stores.len(), 110);
        let mut s = scene(&b);
        for room in [110.0, 111.0, 200.0, -1.0] {
            let id = create_in_room(&b, &mut s, room, object);
            assert_eq!(
                field(&s, id, "sprite_index"),
                Some(default),
                "CODE {code} room {room}: the unmatched path keeps the object sprite"
            );
            let ran: Vec<usize> = s
                .executed
                .iter()
                .filter(|(c0, o)| *c0 == code && stores.contains(o))
                .map(|(_, o)| *o)
                .collect();
            assert!(
                ran.is_empty(),
                "CODE {code} room {room}: the unmatched path executed stores {ran:?}"
            );
            assert_eq!(
                s.executed.last(),
                Some(&(code, popz.offset)),
                "CODE {code} room {room}: the body runs to the shared popz"
            );
        }
    }
}

/// Arm 0 is the one arm whose body has no `b`: it keeps running into arm 1's
/// body. Room 0 therefore executes TWO stores and the second one wins. For
/// obj_watersurface both stores write 104 (invisible); for obj_waterfill they
/// write 100 then 103, which is the case that proves the fall-through is real
/// and not an artefact of the extraction.
#[test]
fn room_0_falls_through_into_arm_1_and_the_second_store_wins() {
    let b = bundle();
    for (code, object, want_state, first, second) in [
        (34usize, WATERSURFACE, 104.0, 104.0, 104.0),
        (35, WATERFILL, 103.0, 100.0, 103.0),
    ] {
        // Structural proof of "arm 0 has no `b`": its body is exactly
        // `constant V; store sprite_index`, and arm 1's body starts right after.
        let chain = arms(&b, code);
        let a0 = chain[0].1;
        let i0 = index_of(&b, code, a0);
        let ins = &body(&b, code).instructions;
        assert!(
            matches!(&ins[i0].op, Op::Constant { value } if *value == first),
            "CODE {code}: arm 0 starts with `constant {first}`"
        );
        assert!(
            matches!(&ins[i0 + 1].op, Op::Store { .. }),
            "CODE {code}: arm 0 stores next"
        );
        assert!(
            matches!(&ins[i0 + 2].op, Op::Constant { value } if *value == second),
            "CODE {code}: arm 0 runs straight into arm 1's `constant {second}` - no `b`"
        );
        assert_eq!(
            chain[1].1,
            a0 + 12,
            "CODE {code}: arm 1's body follows arm 0's pair"
        );
        assert_eq!(
            ins[i0 + 3].offset,
            chain[1].1 + 4,
            "CODE {code}: arm 1 stores at +4"
        );

        // And the runtime consequence, in order: two stores, second one lands.
        let mut s = scene(&b);
        let id = create_in_room(&b, &mut s, 0.0, object);
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(want_state),
            "CODE {code} room 0"
        );
        let stores = store_offsets(&b, code);
        let ran: Vec<usize> = s
            .executed
            .iter()
            .filter(|(c0, o)| *c0 == code && stores.contains(o))
            .map(|(_, o)| *o)
            .collect();
        assert_eq!(
            ran,
            vec![a0 + 4, chain[1].1 + 4],
            "CODE {code} room 0: arm 0's store then arm 1's store, in that order"
        );
        // Room 1 (the legitimate arm 1 hit) writes the same surviving value with
        // a single store - so room 0 and room 1 agree on the final sprite while
        // only room 0 runs the fall-through.
        let id1 = create_in_room(&b, &mut s, 1.0, object);
        assert_eq!(
            field(&s, id1, "sprite_index"),
            Some(second),
            "CODE {code} room 1"
        );
        assert_eq!(
            s.executed
                .iter()
                .filter(|(c0, o)| *c0 == code && stores.contains(o))
                .count(),
            1,
            "CODE {code} room 1: a single store"
        );
    }
}
