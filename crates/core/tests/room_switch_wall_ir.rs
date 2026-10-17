//! wl47-wall: arm-level coverage of the two room-switch Create tables.
//!
//! CODE 30 (gml_Object_obj_wall_Create_0) and CODE 31
//! (gml_Object_obj_wall_2_Create_0) are flat `switch (room)` tables: 109
//! `dup; constant K; cmp ==; bt arm` quads in a row, each arm one
//! `constant V; store sprite_index` body, every arm's `b` leaving for the same
//! shared `popz` exit. They are the per-room wall sprite tables, so they are
//! the wall's rendering geometry for every level. The suites that touched them
//! sampled 13 room boundaries (world_ui_id_bodies_ir::TERRAIN_ROOMS); this
//! suite enumerates every arm of both bodies.
//!
//! Every expected value comes out of the bundle's own bytecode at run time -
//! arms and their stores from `Bundle::codes -> Code::instructions`, the
//! fall-through default from `Bundle::objects` - and is additionally pinned in
//! the WALL_ARMS / WALL2_ARMS tables below, which the run cross-checks arm by
//! arm against the live instruction stream. Nothing here is taken from room
//! names.
//!
//! Arm census, extracted and asserted below:
//!   * CODE 30 arms 1..109 - the bt constants are exactly the rooms 1..=109,
//!     109 arms and 109 distinct constants, in numeric order;
//!   * CODE 31 arms 1..109 - the same shape, one sprite step higher.
//!   * spans: rooms 1..10 / 11..27 / 28..48 / 49..64 / 65..82 / 83..109 pick
//!     sprites 5, 8, 11, 14, 17, 20 (CODE 30) and 6, 9, 12, 15, 18, 21 (CODE 31).
//!
//! Neither table repeats a room constant, so "the first matching arm wins" is
//! not exercised by these two bodies; what the suite asserts instead of
//! assuming is that every probed room matches exactly one arm and that bt
//! order is numeric order. The sibling table a brief cited as 114 arms over
//! only 111 room constants (obj_bg_Create_0, id 360) re-extracts out of this
//! same bundle as *114 arms / 114 distinct constants 0..113* whose tail is out
//! of order - bt order ends ...109, 111, 112, 113, 110. The overlap reading is
//! therefore a reading of the value set rather than of the bytecode: order,
//! not the set, decides which arm runs, and a permuted tail is exactly where a
//! numeric-order assumption breaks.
//!
//! Scope: rewritten-end IR regression against the bundle's bytecode, not an
//! equivalence proof against the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Code, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::path::Path;

const WALL: i32 = 4;
const WALL2: i32 = 5;
/// obj_wall / obj_wall_2's own sprite in the object definition: what the switch
/// leaves in place when no arm matches (read from `Bundle::objects`).
const WALL_DEFAULT: f64 = 5.0;
const WALL2_DEFAULT: f64 = 6.0;
/// Rooms in neither chain: 0 is the first room, 110..113 are rm_ending and the
/// four map rooms, and the last two are out of range outright.
const OFF_TABLE_ROOMS: [i32; 7] = [0, 110, 111, 112, 113, 998, 4096];
/// An arm of both chains (the 11..27 span), for the "an unmatched room writes
/// nothing" check.
const ARMED_ROOM: i32 = 11;

/// (room, sprite_index) for every arm of CODE 30 (obj_wall), in bt order.
/// Extracted from crates/core/src/generated/full_ir.json: the `dup; constant K;
/// cmp(3); bt T` quads of gml_Object_obj_wall_Create_0, each arm's body read from T
/// to its `b`. Collapsed runs: 1..10->5, 11..27->8, 28..48->11, 49..64->14, 65..82->17, 83..109->20.
const WALL_ARMS: [(i32, f64); 109] = [
    (1, 5.0),
    (2, 5.0),
    (3, 5.0),
    (4, 5.0),
    (5, 5.0),
    (6, 5.0),
    (7, 5.0),
    (8, 5.0),
    (9, 5.0),
    (10, 5.0),
    (11, 8.0),
    (12, 8.0),
    (13, 8.0),
    (14, 8.0),
    (15, 8.0),
    (16, 8.0),
    (17, 8.0),
    (18, 8.0),
    (19, 8.0),
    (20, 8.0),
    (21, 8.0),
    (22, 8.0),
    (23, 8.0),
    (24, 8.0),
    (25, 8.0),
    (26, 8.0),
    (27, 8.0),
    (28, 11.0),
    (29, 11.0),
    (30, 11.0),
    (31, 11.0),
    (32, 11.0),
    (33, 11.0),
    (34, 11.0),
    (35, 11.0),
    (36, 11.0),
    (37, 11.0),
    (38, 11.0),
    (39, 11.0),
    (40, 11.0),
    (41, 11.0),
    (42, 11.0),
    (43, 11.0),
    (44, 11.0),
    (45, 11.0),
    (46, 11.0),
    (47, 11.0),
    (48, 11.0),
    (49, 14.0),
    (50, 14.0),
    (51, 14.0),
    (52, 14.0),
    (53, 14.0),
    (54, 14.0),
    (55, 14.0),
    (56, 14.0),
    (57, 14.0),
    (58, 14.0),
    (59, 14.0),
    (60, 14.0),
    (61, 14.0),
    (62, 14.0),
    (63, 14.0),
    (64, 14.0),
    (65, 17.0),
    (66, 17.0),
    (67, 17.0),
    (68, 17.0),
    (69, 17.0),
    (70, 17.0),
    (71, 17.0),
    (72, 17.0),
    (73, 17.0),
    (74, 17.0),
    (75, 17.0),
    (76, 17.0),
    (77, 17.0),
    (78, 17.0),
    (79, 17.0),
    (80, 17.0),
    (81, 17.0),
    (82, 17.0),
    (83, 20.0),
    (84, 20.0),
    (85, 20.0),
    (86, 20.0),
    (87, 20.0),
    (88, 20.0),
    (89, 20.0),
    (90, 20.0),
    (91, 20.0),
    (92, 20.0),
    (93, 20.0),
    (94, 20.0),
    (95, 20.0),
    (96, 20.0),
    (97, 20.0),
    (98, 20.0),
    (99, 20.0),
    (100, 20.0),
    (101, 20.0),
    (102, 20.0),
    (103, 20.0),
    (104, 20.0),
    (105, 20.0),
    (106, 20.0),
    (107, 20.0),
    (108, 20.0),
    (109, 20.0),
];

/// (room, sprite_index) for every arm of CODE 31 (obj_wall_2), in bt order.
/// Extracted from crates/core/src/generated/full_ir.json: the `dup; constant K;
/// cmp(3); bt T` quads of gml_Object_obj_wall_2_Create_0, each arm's body read from T
/// to its `b`. Collapsed runs: 1..10->6, 11..27->9, 28..48->12, 49..64->15, 65..82->18, 83..109->21.
const WALL2_ARMS: [(i32, f64); 109] = [
    (1, 6.0),
    (2, 6.0),
    (3, 6.0),
    (4, 6.0),
    (5, 6.0),
    (6, 6.0),
    (7, 6.0),
    (8, 6.0),
    (9, 6.0),
    (10, 6.0),
    (11, 9.0),
    (12, 9.0),
    (13, 9.0),
    (14, 9.0),
    (15, 9.0),
    (16, 9.0),
    (17, 9.0),
    (18, 9.0),
    (19, 9.0),
    (20, 9.0),
    (21, 9.0),
    (22, 9.0),
    (23, 9.0),
    (24, 9.0),
    (25, 9.0),
    (26, 9.0),
    (27, 9.0),
    (28, 12.0),
    (29, 12.0),
    (30, 12.0),
    (31, 12.0),
    (32, 12.0),
    (33, 12.0),
    (34, 12.0),
    (35, 12.0),
    (36, 12.0),
    (37, 12.0),
    (38, 12.0),
    (39, 12.0),
    (40, 12.0),
    (41, 12.0),
    (42, 12.0),
    (43, 12.0),
    (44, 12.0),
    (45, 12.0),
    (46, 12.0),
    (47, 12.0),
    (48, 12.0),
    (49, 15.0),
    (50, 15.0),
    (51, 15.0),
    (52, 15.0),
    (53, 15.0),
    (54, 15.0),
    (55, 15.0),
    (56, 15.0),
    (57, 15.0),
    (58, 15.0),
    (59, 15.0),
    (60, 15.0),
    (61, 15.0),
    (62, 15.0),
    (63, 15.0),
    (64, 15.0),
    (65, 18.0),
    (66, 18.0),
    (67, 18.0),
    (68, 18.0),
    (69, 18.0),
    (70, 18.0),
    (71, 18.0),
    (72, 18.0),
    (73, 18.0),
    (74, 18.0),
    (75, 18.0),
    (76, 18.0),
    (77, 18.0),
    (78, 18.0),
    (79, 18.0),
    (80, 18.0),
    (81, 18.0),
    (82, 18.0),
    (83, 21.0),
    (84, 21.0),
    (85, 21.0),
    (86, 21.0),
    (87, 21.0),
    (88, 21.0),
    (89, 21.0),
    (90, 21.0),
    (91, 21.0),
    (92, 21.0),
    (93, 21.0),
    (94, 21.0),
    (95, 21.0),
    (96, 21.0),
    (97, 21.0),
    (98, 21.0),
    (99, 21.0),
    (100, 21.0),
    (101, 21.0),
    (102, 21.0),
    (103, 21.0),
    (104, 21.0),
    (105, 21.0),
    (106, 21.0),
    (107, 21.0),
    (108, 21.0),
    (109, 21.0),
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

fn body<'a>(b: &'a Bundle, code: usize) -> &'a Code {
    b.codes
        .iter()
        .find(|c| c.id == code)
        .unwrap_or_else(|| panic!("CODE {code} is not in the bundle"))
}

fn is_arm(ins: &[Instruction], k: usize) -> bool {
    k + 3 < ins.len()
        && matches!(ins[k].op, Op::Dup)
        && matches!(ins[k + 1].op, Op::Constant { .. })
        && matches!(ins[k + 2].op, Op::Cmp { comparison: 3 })
        && matches!(ins[k + 3].op, Op::Bt { .. })
}

/// One arm of the table: the constant it compares `room` against, the store
/// its body performs, and the exit it leaves through.
struct Arm {
    /// Position in bt order (1-based): the switch tries arms in this order,
    /// and the arm sequence is the only authority on which one wins.
    ordinal: usize,
    room: i32,
    sprite: f64,
    /// Absolute offset of the arm body.
    target: usize,
    stores: Vec<(String, f64)>,
    exit: usize,
}

struct Table {
    arms: Vec<Arm>,
    /// Absolute offset of the `b` the arm chain falls through into when no arm
    /// matched.
    default_branch: usize,
    /// The offset the default branch - and every arm - jumps to.
    exit: usize,
    /// code_offset of the `load room` the chain compares against.
    subject: usize,
}

/// The body of one arm, from its `bt` target to the unconditional `b` that
/// leaves it: every `constant V; store <field>` pair, plus the `b` target.
fn arm_body(ins: &[Instruction], target: usize) -> (Vec<(String, f64)>, usize) {
    let mut j = ins
        .iter()
        .position(|i| i.offset == target)
        .unwrap_or_else(|| panic!("arm target {target} is not an instruction boundary"));
    let mut stores = Vec::new();
    loop {
        match &ins[j].op {
            Op::B { target } => return (stores, *target),
            Op::Constant { value } => {
                let next = ins
                    .get(j + 1)
                    .unwrap_or_else(|| panic!("the arm body at {target} ends on a bare constant"));
                match &next.op {
                    Op::Store {
                        name,
                        selector,
                        array,
                        other,
                    } => {
                        assert!(
                            !*array && !*other,
                            "the store at {} uses a computed receiver",
                            next.code_offset
                        );
                        assert_eq!(
                            *selector, -1,
                            "the store at {} uses selector {selector}",
                            next.code_offset
                        );
                        stores.push((name.clone(), *value));
                        j += 2;
                    }
                    other => panic!(
                        "the constant at {} is not followed by a store ({other:?})",
                        ins[j].code_offset
                    ),
                }
            }
            other => panic!(
                "unexpected op in an arm body at {}: {other:?}",
                ins[j].code_offset
            ),
        }
    }
}

/// Decode one Create body's `switch (room)` table out of its own instruction
/// stream: the contiguous `dup; constant K; cmp ==; bt T` quads are the arms,
/// the `b` right after them is the fall-through path, and everything the arms
/// jump to is the shared exit.
fn table(b: &Bundle, code: usize) -> Table {
    let ins = &body(b, code).instructions;
    let mut k = 0;
    while k < ins.len() && !is_arm(ins, k) {
        k += 1;
    }
    assert!(
        k < ins.len(),
        "CODE {code}: no `dup; constant; cmp ==; bt` arm in the body"
    );
    let subject = ins[..k]
        .iter()
        .rev()
        .find_map(|i| match &i.op {
            Op::Load { name, selector, .. } => Some((i.code_offset, name.clone(), *selector)),
            _ => None,
        })
        .expect("the arm chain compares a value loaded before it");
    assert_eq!(
        subject.1, "room",
        "CODE {code}: the chain switches on `{}`, not `room`",
        subject.1
    );
    assert_eq!(
        subject.2, -1,
        "CODE {code}: the switch subject is not a plain read of `room`"
    );

    let mut quads = Vec::new();
    while is_arm(ins, k) {
        let room = match &ins[k + 1].op {
            Op::Constant { value } => *value,
            _ => unreachable!("checked by is_arm"),
        };
        let target = match &ins[k + 3].op {
            Op::Bt { target } => *target,
            _ => unreachable!("checked by is_arm"),
        };
        // The constants here are room indices; the VM also compares them as f64.
        assert_eq!(
            room.fract(),
            0.0,
            "CODE {code}: a non-integral arm constant {room}"
        );
        quads.push((room as i32, target));
        k += 4;
    }
    let tail = ins
        .get(k)
        .unwrap_or_else(|| panic!("CODE {code}: the arm chain runs off the end"));
    let default_branch = tail.offset;
    let exit = match &tail.op {
        Op::B { target } => *target,
        other => panic!("CODE {code}: the arm chain does not fall through into a `b` ({other:?})"),
    };
    let exit_ins = ins
        .iter()
        .find(|i| i.offset == exit)
        .unwrap_or_else(|| panic!("CODE {code}: the exit {exit} is not an instruction boundary"));
    assert!(
        matches!(exit_ins.op, Op::Popz),
        "CODE {code}: the shared exit is {:?}, not the `popz` that drops the switched value",
        exit_ins.op
    );
    assert_eq!(
        ins.last().unwrap().offset,
        exit,
        "CODE {code}: the shared exit is not the body's last instruction"
    );

    let arms = quads
        .iter()
        .enumerate()
        .map(|(n, (room, target))| {
            let ordinal = n + 1;
            let (stores, arm_exit) = arm_body(ins, *target);
            assert_eq!(
                arm_exit, exit,
                "CODE {code} arm {ordinal}: an arm leaves for a different exit"
            );
            let sprite = match stores.as_slice() {
                [(name, value)] => {
                    assert_eq!(
                        name, "sprite_index",
                        "CODE {code} arm {ordinal} stores `{name}`"
                    );
                    *value
                }
                other => panic!(
                    "CODE {code} arm {ordinal}: {} stores instead of the single sprite store",
                    other.len()
                ),
            };
            Arm {
                ordinal,
                room: *room,
                sprite,
                target: *target,
                stores,
                exit: arm_exit,
            }
        })
        .collect();

    Table {
        arms,
        default_branch,
        exit,
        subject: subject.0,
    }
}

/// The arm that runs for a room: the first one in bt order whose constant
/// matches. `None` means the chain falls through to the default exit.
fn first_match<'a>(t: &'a Table, room: i32) -> Option<&'a Arm> {
    t.arms.iter().find(|a| a.room == room)
}

/// Every arm of both tables, driven for real: set `room`, run the object's
/// Create (the switch is the Create body), read `sprite_index` back.
#[test]
fn every_arm_of_both_wall_room_switches_stores_its_sprite() {
    let b = bundle();
    for (code, object, pinned) in [
        (30usize, WALL, WALL_ARMS.as_slice()),
        (31usize, WALL2, WALL2_ARMS.as_slice()),
    ] {
        let t = table(&b, code);
        assert_eq!(
            t.arms.len(),
            pinned.len(),
            "CODE {code}: the arm matrix and the bytecode table"
        );
        assert_eq!(t.arms.len(), 109, "CODE {code}: the shipped arm census");
        let mut s = scene(&b);
        for (arm, (room, sprite)) in t.arms.iter().zip(pinned) {
            // The pinned table came out of this same bytecode; a mismatch here
            // means the bundle's table moved under the test.
            assert_eq!(
                arm.room, *room,
                "CODE {code} arm {}: the bytecode's constant",
                arm.ordinal
            );
            assert_eq!(
                arm.sprite, *sprite,
                "CODE {code} arm {}: the bytecode's stored value",
                arm.ordinal
            );
            s.current_room = arm.room as f64;
            let id = s.create(&b, object, 64.0, 64.0).unwrap_or_else(|e| {
                panic!("CODE {code} arm {} (room {}): {e}", arm.ordinal, arm.room)
            });
            let f = &s.instances[&id].fields;
            assert_eq!(
                f["sprite_index"], arm.sprite,
                "CODE {code} arm {} (room {}) must select sprite {}",
                arm.ordinal, arm.room, arm.sprite
            );
            // The pre-switch prologue runs on every path, matched or not.
            assert_eq!(
                f["type"], 1.0,
                "CODE {code} arm {}: `type = 1`",
                arm.ordinal
            );
            if code == 30 {
                assert_eq!(
                    f["activate"], 0.0,
                    "CODE {code} arm {}: `activate = 0`",
                    arm.ordinal
                );
            }
        }
    }
}

/// The duplicate-constant axis: how many arms there are against how many
/// distinct room constants they compare against.
#[test]
fn the_wall_room_switches_repeat_no_room_constant() {
    // bt order is the only authority on which arm wins, so a repeated constant
    // would silently make the later arm unreachable - the duplicate-constant
    // failure mode a census raised for the obj_bg table (id 360). Both of
    // these tables turn out to need no such ruling: 109 arms, 109 distinct
    // constants, bt order == numeric order.
    let b = bundle();
    for (code, object, pinned) in [
        (30usize, WALL, WALL_ARMS.as_slice()),
        (31usize, WALL2, WALL2_ARMS.as_slice()),
    ] {
        // The body under test is this object's whole Create event: one code
        // chunk, the switch itself.
        let create = b
            .objects
            .iter()
            .find(|o| o.id == object)
            .unwrap_or_else(|| panic!("object {object} is not in the bundle"))
            .events
            .iter()
            .find(|e| e.event_type == 0 && e.subtype == 0)
            .unwrap_or_else(|| panic!("object {object} has no Create event"))
            .codes
            .clone();
        assert_eq!(
            create,
            vec![code],
            "CODE {code} is obj {object}'s whole Create event"
        );
        let t = table(&b, code);
        let rooms: Vec<i32> = t.arms.iter().map(|a| a.room).collect();
        assert_eq!(
            rooms.len(),
            pinned.len(),
            "CODE {code}: as many arms as pinned rows"
        );
        let mut distinct = rooms.clone();
        distinct.sort_unstable();
        distinct.dedup();
        assert_eq!(
            distinct.len(),
            rooms.len(),
            "CODE {code}: two arms compare against the same room constant - keep both, in bt order, and the earlier bt wins ({rooms:?})"
        );
        // These two are level-room tables: every arm constant is a level room.
        assert_eq!(
            distinct,
            (1..=109).collect::<Vec<i32>>(),
            "CODE {code}: the arm constants are exactly the level rooms 1..=109"
        );
        assert!(
            rooms.windows(2).all(|w| w[0] < w[1]),
            "CODE {code}: bt order is numeric order here, so the first match is the arm's own bt"
        );
        for room in &rooms {
            assert_eq!(
                t.arms.iter().filter(|a| a.room == *room).count(),
                1,
                "CODE {code}: room {room} matches exactly one arm"
            );
        }
        for room in OFF_TABLE_ROOMS {
            assert!(
                first_match(&t, room).is_none(),
                "room {room} is not an arm of CODE {code}"
            );
        }
    }
}

/// The negative inputs: a room no arm matches falls through the whole chain,
/// and the fall-through path stores nothing at all.
#[test]
fn a_room_outside_a_wall_switch_falls_through_without_storing() {
    let b = bundle();
    for (code, object, default) in [
        (30usize, WALL, WALL_DEFAULT),
        (31usize, WALL2, WALL2_DEFAULT),
    ] {
        let t = table(&b, code);
        // Where the default comes from: the object definition, because the
        // fall-through branch is a bare jump to the shared exit.
        let object_sprite = b
            .objects
            .iter()
            .find(|o| o.id == object)
            .unwrap_or_else(|| panic!("object {object} is not in the bundle"))
            .sprite as f64;
        assert_eq!(
            object_sprite, default,
            "CODE {code}: obj {object}'s own sprite"
        );
        for room in OFF_TABLE_ROOMS {
            assert!(
                first_match(&t, room).is_none(),
                "room {room} is not an arm of CODE {code}"
            );
            let mut s = scene(&b);
            s.current_room = room as f64;
            let id = s.create(&b, object, 64.0, 64.0).expect("wall Create");
            let f = &s.instances[&id].fields;
            assert_eq!(
                f["sprite_index"], default,
                "CODE {code} room {room}: the shared exit stores nothing, the object keeps sprite {default}"
            );
            assert_eq!(
                f["type"], 1.0,
                "CODE {code} room {room}: the prologue still ran"
            );
            if code == 30 {
                assert_eq!(
                    f["activate"], 0.0,
                    "CODE {code} room {room}: `activate = 0`"
                );
            }
        }
        // And the fall-through really writes nothing: a matched arm's value
        // survives a second Create dispatch with an unlisted room.
        let armed = first_match(&t, ARMED_ROOM)
            .expect("room 11 is an arm of both chains")
            .sprite;
        assert_ne!(
            armed, default,
            "room {ARMED_ROOM} is an arm, not the default row"
        );
        let mut s = scene(&b);
        s.current_room = ARMED_ROOM as f64;
        let id = s.create(&b, object, 64.0, 64.0).expect("wall Create");
        assert_eq!(
            s.instances[&id].fields["sprite_index"], armed,
            "CODE {code}: room {ARMED_ROOM}"
        );
        s.current_room = OFF_TABLE_ROOMS[4] as f64;
        s.dispatch(&b, id, 0, 0).expect("second Create dispatch");
        assert_eq!(
            s.instances[&id].fields["sprite_index"], armed,
            "CODE {code}: an unmatched room must leave the arm's sprite alone"
        );
    }
}

/// The tail of the table, read out of the bytecode: the chain falls through
/// into a single `b` that jumps to the shared `popz` exit, which is the body's
/// last instruction and drops the switched value the chain left on the stack.
#[test]
fn the_fall_through_lands_on_the_shared_popz_exit() {
    let b = bundle();
    for code in [30usize, 31usize] {
        let ins = &body(&b, code).instructions;
        let t = table(&b, code);
        assert_eq!(t.arms.len(), 109, "CODE {code}: the shipped arm census");

        // The fall-through instruction: a bare `b`, no store on the way out.
        let branch = ins
            .iter()
            .find(|i| i.offset == t.default_branch)
            .unwrap_or_else(|| panic!("CODE {code}: no instruction at the fall-through"));
        match &branch.op {
            Op::B { target } => assert_eq!(*target, t.exit, "CODE {code}: the default branch"),
            other => panic!("CODE {code}: the fall-through is {other:?}, not a `b`"),
        }

        // The shared exit, and why the leftover `room` value is not a stack leak.
        let exit_ins = ins
            .iter()
            .find(|i| i.offset == t.exit)
            .expect("exit instruction");
        assert!(
            matches!(exit_ins.op, Op::Popz),
            "CODE {code}: the exit drops the switched value"
        );
        assert_eq!(
            ins.last().unwrap().offset,
            t.exit,
            "CODE {code}: the exit ends the body"
        );

        // The switch subject, and the whole body being nothing but the table.
        assert_eq!(
            ins.iter().filter(|i| i.code_offset == t.subject).count(),
            1,
            "CODE {code}: one `load room` feeds the chain"
        );
        assert_eq!(
            ins.iter().filter(|i| matches!(i.op, Op::Bt { .. })).count(),
            t.arms.len(),
            "CODE {code}: every `bt` in the body is an arm of this table"
        );
        assert_eq!(
            ins.iter().filter(|i| matches!(i.op, Op::B { .. })).count(),
            t.arms.len() + 1,
            "CODE {code}: one `b` per arm plus the fall-through branch"
        );

        // Arm bodies are uniform 16-byte slots in bt order, starting right
        // after the fall-through branch's slot, and each stores exactly the
        // one sprite.
        let first = t.arms[0].target;
        assert_eq!(
            t.default_branch + 4,
            first,
            "CODE {code}: the arms start after the default branch"
        );
        for arm in &t.arms {
            assert_eq!(
                arm.exit, t.exit,
                "CODE {code} arm {}: the shared exit",
                arm.ordinal
            );
            assert_eq!(
                arm.stores.len(),
                1,
                "CODE {code} arm {}: exactly one store",
                arm.ordinal
            );
            assert_eq!(
                arm.stores[0].0, "sprite_index",
                "CODE {code} arm {}: the sprite store",
                arm.ordinal
            );
            assert_eq!(
                arm.target,
                first + 16 * (arm.ordinal - 1),
                "CODE {code} arm {}: the contiguous slot",
                arm.ordinal
            );
        }
    }
}
