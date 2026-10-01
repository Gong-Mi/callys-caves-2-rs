//! Environment (with) semantics pinned at the VM layer — batch E kernel.
//!
//! The CFG evidence ledger (`progress.tsv`, column environment_ops_pending)
//! marks 2,494 `with`-site instructions across 62 CODEs as structurally
//! pending. Those sites are all instances of the four behaviours pinned
//! here with hand-built IR bodies, independent of any single original CODE:
//!
//!   1. `with (instance_id)` — selector >= 100000 addresses one instance;
//!   2. `with (object)`      — the body runs once per selected instance,
//!                             in instance-id order;
//!   3. `with (empty)`       — the body is skipped, the environment stack
//!                             still balances (pushenv jumps AT the popenv);
//!   4. nested `with`        — the inner popenv restores the OUTER target,
//!                             not the original self, for the remaining
//!                             outer iterations.
//!
//! Real-site coverage on top of this kernel: the 62 pending CODEs are
//! dominated by death alarms whose with-bodies are `with(ID){motion_set}`
//! (XP-orb fans) and `with(obj_lloyd){...}` — dispatched end-to-end by
//! level1_enemy_cast_ir (CODE 46), boss kill suites (CODE 160/168/184/196/
//! 212), lloyd_tutorial_all_sheets_ir (CODE 557..663 Destroy) and
//! draw_stream_sensitivities (trex CODE 160 via the real bullet chain).
use callys_core::code_vm::{Bundle, Code, Event, Instruction, Object, Op, execute};
use callys_core::ir_scene::{Instance, Scene};
use std::collections::BTreeMap;

fn inst(object: i32) -> Instance {
    Instance {
        object, alive: true, active: true, external: false,
        fields: BTreeMap::new(), arrays: BTreeMap::new(), alarms: [0; 12],
    }
}

fn instr(offset: usize, start: usize, op: Op) -> Instruction {
    Instruction { offset, code_offset: offset - start, words_raw: vec![0], op }
}

fn bundle(start: usize, ops: Vec<Op>) -> (Bundle, usize) {
    let mut instructions = Vec::new();
    let mut offset = start;
    for op in ops {
        instructions.push(instr(offset, start, op));
        offset += 4;
    }
    let code = Code { id: 9001, start, end: offset, instructions };
    (Bundle { schema: 1, string_table: vec![], objects: vec![], room_bindings: vec![], codes: vec![code] }, 9001)
}

/// `with(sel) { x = 42 }` — the compiled shape is:
///   push sel; pushenv <popenv_addr>; body; popenv <body_addr>; exit
/// Empty selection jumps straight AT the popenv so the pushed frame still
/// unwinds (this is why pushenv's target is the popenv, not the exit).
fn with_store_body(selector: Op) -> Vec<Op> {
    vec![
        selector,                          // push selector
        Op::Pushenv { target: 0x1010 },    // empty -> jump at popenv
        Op::Constant { value: 42.0 },      // body start (0x1008)
        Op::Store { name: "x".into(), selector: -1, array: false, other: false },
        Op::Popenv { target: 0x1008 },     // more -> body; done -> pop frame
        Op::Exit,                          // 0x1014
    ]
}

#[test]
fn with_instance_id_selector_writes_only_that_instance() {
    let (b, code) = bundle(0x1000, with_store_body(Op::Constant { value: 100_001.0 }));
    let mut s = Scene::default();
    s.instances.insert(100_001, inst(99));
    s.instances.insert(100_002, inst(99));
    execute(&b, code, 100_001, &mut s).expect("with(instance_id) executes");
    assert_eq!(s.instances[&100_001].fields["x"], 42.0, "the addressed instance got the store");
    assert!(!s.instances[&100_002].fields.contains_key("x"), "the sibling untouched");
}

#[test]
fn with_object_selector_runs_the_body_per_instance_in_id_order() {
    let (b, code) = bundle(0x1000, with_store_body(Op::Constant { value: 99.0 }));
    let mut s = Scene::default();
    s.instances.insert(100_010, inst(99));
    s.instances.insert(100_020, inst(99));
    s.instances.insert(100_030, inst(99));
    s.instances.insert(100_040, inst(77)); // different object: not selected
    execute(&b, code, 100_010, &mut s).expect("with(object) executes");
    for id in [100_010, 100_020, 100_030] {
        assert_eq!(s.instances[&id].fields["x"], 42.0, "{id} visited");
    }
    assert!(!s.instances[&100_040].fields.contains_key("x"), "other object untouched");
}

#[test]
fn with_empty_selection_skips_the_body_and_still_balances_the_env_stack() {
    let (b, code) = bundle(0x1000, with_store_body(Op::Constant { value: 98.0 }));
    let mut s = Scene::default();
    s.instances.insert(100_001, inst(99)); // no object-98 instance exists
    execute(&b, code, 100_001, &mut s).expect("empty with exits cleanly (no unbalanced-env error)");
    assert!(!s.instances[&100_001].fields.contains_key("x"), "body never ran");
}

#[test]
fn nested_with_restores_the_outer_target_not_the_original_self() {
    // with(99){ with(100001){ y = 7 }  z = 5 }
    // offsets: 0:0x1000 1:0x1004 2:0x1008 3:0x100c 4:0x1010 5:0x1014
    //          6:0x1018 7:0x101c 8:0x1020 9:0x1024 10:0x1028
    let ops = vec![
        Op::Constant { value: 99.0 },                        // 0x1000
        Op::Pushenv { target: 0x1024 },                      // outer empty -> outer popenv
        // outer body start 0x1008:
        Op::Constant { value: 100_001.0 },                   // 0x1008
        Op::Pushenv { target: 0x1018 },                      // inner empty -> inner popenv
        // inner body 0x1010:
        Op::Constant { value: 7.0 },                         // 0x1010
        Op::Store { name: "y".into(), selector: -1, array: false, other: false }, // 0x1014
        Op::Popenv { target: 0x1010 },                       // 0x1018 inner popenv
        // outer body continues 0x101c:
        Op::Constant { value: 5.0 },                         // 0x101c
        Op::Store { name: "z".into(), selector: -1, array: false, other: false }, // 0x1020
        Op::Popenv { target: 0x1008 },                       // 0x1024 outer popenv
        Op::Exit,                                            // 0x1028
    ];
    let (b, code) = bundle(0x1000, ops);
    let mut s = Scene::default();
    s.instances.insert(100_001, inst(98)); // inner target
    s.instances.insert(100_010, inst(99)); // outer target 1
    s.instances.insert(100_020, inst(99)); // outer target 2
    execute(&b, code, 100_010, &mut s).expect("nested with executes");
    assert_eq!(s.instances[&100_001].fields["y"], 7.0, "inner target took the inner store");
    assert!(!s.instances[&100_001].fields.contains_key("z"), "inner target untouched by outer store");
    assert_eq!(s.instances[&100_010].fields["z"], 5.0, "outer target 1 took the outer store");
    assert_eq!(s.instances[&100_020].fields["z"], 5.0, "outer target 2 took the outer store (iteration resumed)");
    assert!(!s.instances[&100_010].fields.contains_key("y"), "outer target untouched by inner store");
}

#[test]
fn with_body_can_read_back_through_the_current_target() {
    // with(99){ x = 41; x = x + 1 } — Load runs against the with target.
    // offsets: 0:0x1000 1:0x1004 2:0x1008 3:0x100c 4:0x1010 5:0x1014
    //          6:0x1018 7:0x101c 8:0x1020 9:0x1024
    let ops = vec![
        Op::Constant { value: 99.0 },                        // 0x1000
        Op::Pushenv { target: 0x1020 },                      // empty -> land ON the popenv
        Op::Constant { value: 41.0 },                        // 0x1008 body start
        Op::Store { name: "x".into(), selector: -1, array: false, other: false }, // 0x100c
        Op::Load { name: "x".into(), selector: -1, array: false, other: false },  // 0x1010
        Op::Constant { value: 1.0 },                         // 0x1014
        Op::Add,                                             // 0x1018
        Op::Store { name: "x".into(), selector: -1, array: false, other: false }, // 0x101c
        Op::Popenv { target: 0x1008 },                       // 0x1020
        Op::Exit,                                            // 0x1024
    ];
    let (b, code) = bundle(0x1000, ops);
    let mut s = Scene::default();
    s.instances.insert(100_010, inst(99));
    execute(&b, code, 100_010, &mut s).expect("read-back with executes");
    assert_eq!(s.instances[&100_010].fields["x"], 42.0, "load+add+store round-tripped on the target");
}

// Silence unused-import-style warnings for the Event/Object items brought in
// for future real-CODE dispatch extensions of this suite.
#[allow(dead_code)]
fn _type_anchors(_: Object, _: Event) {}
