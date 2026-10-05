//! Every `with` site in the 62 pending CODEs, classified and reconciled.
//!
//! The kernel above pins the four `with` behaviours with hand-built bodies and
//! the real-site suites drive them end to end. What was still hand-waved is the
//! *population*: "all 2,494 sites are instances of those four behaviours" was a
//! claim made by eye. This module makes it mechanical and falsifiable:
//!
//!   * each of the 2,494 sites is counted from the lowered IR per CODE and
//!     reconciled against the CFG-phase ledger's `environment_ops_pending`
//!     column, which was produced by a different tool (reverse_cfg.py) - the
//!     two agree on every one of the 62 rows;
//!   * each `pushenv` receiver is classified from the instruction that pushes
//!     it: `cast to=2` (an instance/expression receiver, GMS's instance
//!     coercion) or `constant` resolving to an object index in the asset's
//!     object table (a `with (object)` receiver). Anything else fails;
//!   * the split is pinned: 1,247 `pushenv` + 1,247 `popenv`, of which 1,104 are
//!     expression receivers and 143 are object-index receivers covering 54
//!     objects - `obj_lloyd` (16) and the pause/store/volume buttons the
//!     contract names.
//!
//! The ledger table below is a CI artefact (`progress.tsv` from the Reverse
//! CODE evidence leg). It is embedded so the reconciliation runs in every test
//! run without needing that artefact on the machine.
use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use std::path::Path;

/// (code id, name, environment_ops_pending) for all 62 rows the ledger marks.
const LEDGER_PENDING: [(usize, &str, usize); 62] = [
    (160, "gml_Object_obj_trex_Alarm_0", 170),
    (168, "gml_Object_obj_boss2_Alarm_0", 170),
    (184, "gml_Object_obj_boss3_Alarm_0", 170),
    (196, "gml_Object_obj_boss4_Alarm_0", 170),
    (212, "gml_Object_obj_boss5_Alarm_0", 170),
    (241, "gml_Object_obj_bat_Alarm_0", 124),
    (109, "gml_Object_obj_shooter2_Alarm_0", 106),
    (456, "gml_Object_obj_treasurechestopen_Alarm_0", 98),
    (262, "gml_Object_obj_fireslime_Alarm_2", 94),
    (77, "gml_Object_obj_skeleton_Alarm_0", 90),
    (151, "gml_Object_obj_ghost_Alarm_0", 88),
    (88, "gml_Object_obj_firehulk_Alarm_0", 86),
    (142, "gml_Object_obj_wolf_Alarm_0", 86),
    (120, "gml_Object_obj_hulkingbandit_Alarm_0", 82),
    (132, "gml_Object_obj_enemy2_Alarm_0", 82),
    (97, "gml_Object_obj_zombie_Alarm_0", 78),
    (250, "gml_Object_obj_slime_Alarm_2", 78),
    (66, "gml_Object_obj_shooter1_Alarm_0", 76),
    (55, "gml_Object_obj_knifebandit_Alarm_0", 64),
    (46, "gml_Object_obj_enemy_Alarm_0", 58),
    (274, "gml_Object_obj_blade_Step_0", 30),
    (470, "gml_Object_obj_backtogame_Mouse_7", 30),
    (478, "gml_Object_obj_yesrestoredata_Mouse_7", 30),
    (692, "gml_Object_obj_maptile_Mouse_7", 30),
    (476, "gml_Object_obj_mapmenu_Mouse_7", 28),
    (508, "gml_Object_obj_pause_Destroy_0", 26),
    (513, "gml_Object_obj_pause2_Destroy_0", 26),
    (361, "gml_Object_obj_bg_Alarm_2", 24),
    (21, "gml_Object_obj_house_Alarm_6", 20),
    (495, "gml_Object_obj_firstpause_Destroy_0", 12),
    (12, "gml_Object_obj_player_Step_0", 10),
    (481, "gml_Object_obj_norestoredata_Mouse_7", 6),
    (499, "gml_Object_obj_iapmenu_Destroy_0", 6),
    (690, "gml_Object_obj_maptile_Destroy_0", 6),
    (164, "gml_Object_obj_boss2_Destroy_0", 4),
    (172, "gml_Object_obj_boss3_Destroy_0", 4),
    (529, "gml_Object_obj_leftbutton_Alarm_1", 4),
    (532, "gml_Object_obj_rightbutton_Alarm_1", 4),
    (549, "gml_Object_obj_introduction_Destroy_0", 4),
    (675, "gml_Object_obj_lloyd_Step_0", 4),
    (786, "gml_Object_obj_finalbosspuff_Create_0", 4),
    (14, "gml_Object_obj_player_Collision_60", 2),
    (294, "gml_Object_obj_spikegunspike_Step_0", 2),
    (303, "gml_Object_obj_rocket_Step_0", 2),
    (489, "gml_Object_obj_storepageswitch_Mouse_7", 2),
    (492, "gml_Object_obj_storepageswitch2_Mouse_7", 2),
    (557, "gml_Object_obj_lloydtutorial1_Destroy_0", 2),
    (566, "gml_Object_obj_lloydtutorial2_Destroy_0", 2),
    (572, "gml_Object_obj_lloydtutorial3_Destroy_0", 2),
    (577, "gml_Object_obj_lloydtutorial4_Destroy_0", 2),
    (585, "gml_Object_obj_lloydtutorial5_Destroy_0", 2),
    (593, "gml_Object_obj_lloydtutorial6_Destroy_0", 2),
    (601, "gml_Object_obj_lloydtutorial7_Destroy_0", 2),
    (607, "gml_Object_obj_lloydtutorial8_Destroy_0", 2),
    (615, "gml_Object_obj_lloydtutorial9_Destroy_0", 2),
    (620, "gml_Object_obj_lloydtutorial10_Destroy_0", 2),
    (625, "gml_Object_obj_lloydtutorial11_Destroy_0", 2),
    (634, "gml_Object_obj_lloydtutorial12_Destroy_0", 2),
    (643, "gml_Object_obj_lloydtutorial13_Destroy_0", 2),
    (651, "gml_Object_obj_lloydtutorial14_Destroy_0", 2),
    (655, "gml_Object_obj_lloydtutorial15_Destroy_0", 2),
    (663, "gml_Object_obj_lloydtutorial16_Destroy_0", 2)
];

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// How a `pushenv` receiver was pushed.
#[derive(Debug, PartialEq)]
enum Receiver {
    /// `cast to=2`: an instance id or an expression, resolved at run time.
    InstanceExpression,
    /// `constant <n>` naming an object index in the asset's object table.
    ObjectIndex(usize),
    /// Anything else: a shape the four pinned behaviours do not cover.
    Unclassified(&'static str, f64),
}

fn classify(instructions: &[Instruction], index: usize, object_count: usize) -> Receiver {
    if index == 0 {
        return Receiver::Unclassified("pushenv with no preceding push", 0.0);
    }
    match &instructions[index - 1].op {
        Op::Cast { to: 2 } => Receiver::InstanceExpression,
        Op::Constant { value }
            if value.fract() == 0.0 && *value >= 0.0 && (*value as usize) < object_count =>
        {
            Receiver::ObjectIndex(*value as usize)
        }
        Op::Constant { value } => Receiver::Unclassified("constant out of object range", *value),
        _ => Receiver::Unclassified("push is not a cast or an object index", 0.0),
    }
}

fn env_counts(instructions: &[Instruction]) -> (usize, usize) {
    let push = instructions.iter().filter(|i| matches!(i.op, Op::Pushenv { .. })).count();
    let pop = instructions.iter().filter(|i| matches!(i.op, Op::Popenv { .. })).count();
    (push, pop)
}

#[test]
fn every_pending_code_matches_the_cfg_ledger() {
    let bundle = bundle();
    let by_id: std::collections::HashMap<usize, &callys_core::code_vm::Code> =
        bundle.codes.iter().map(|c| (c.id, c)).collect();
    let mut total = 0usize;
    let mut push_total = 0usize;
    let mut pop_total = 0usize;
    for (id, name, pending) in LEDGER_PENDING {
        let code = by_id.get(&id).unwrap_or_else(|| panic!("CODE {id} ({name}) missing from the IR"));
        let (push, pop) = env_counts(&code.instructions);
        assert_eq!(
            push + pop,
            pending,
            "CODE {id} ({name}): the IR has {push} pushenv + {pop} popenv but the CFG ledger              counted {pending} environment sites"
        );
        total += push + pop;
        push_total += push;
        pop_total += pop;
    }
    assert_eq!(total, 2494, "the 62 rows must account for every pending site");
    assert_eq!(push_total, 1247, "pushenv sites");
    assert_eq!(pop_total, 1247, "popenv sites (each with-block is closed)");
}

#[test]
fn no_pending_code_holds_an_environment_site_the_ledger_missed() {
    // The other direction: a CODE the ledger does NOT mark must hold no
    // environment instruction at all, so "62 CODEs" is a complete population
    // and not just the ones a phase happened to notice.
    let bundle = bundle();
    let marked: std::collections::HashSet<usize> =
        LEDGER_PENDING.iter().map(|(id, _, _)| *id).collect();
    let mut offenders = Vec::new();
    for code in &bundle.codes {
        if marked.contains(&code.id) {
            continue;
        }
        let (push, pop) = env_counts(&code.instructions);
        if push + pop > 0 {
            offenders.push((code.id, push, pop));
        }
    }
    assert!(
        offenders.is_empty(),
        "CODEs with environment sites that the ledger does not mark: {offenders:?}"
    );
}

#[test]
fn every_receiver_is_an_expression_or_an_object_index() {
    let bundle = bundle();
    let objects = &bundle.objects;
    let by_id: std::collections::HashMap<usize, &callys_core::code_vm::Code> =
        bundle.codes.iter().map(|c| (c.id, c)).collect();
    let mut expression = 0usize;
    let mut per_object: std::collections::BTreeMap<&str, usize> = std::collections::BTreeMap::new();
    let mut unclassified = Vec::new();
    for (id, name, _) in LEDGER_PENDING {
        let code = by_id[&id];
        for (k, instr) in code.instructions.iter().enumerate() {
            if !matches!(instr.op, Op::Pushenv { .. }) {
                continue;
            }
            match classify(&code.instructions, k, objects.len()) {
                Receiver::InstanceExpression => expression += 1,
                Receiver::ObjectIndex(idx) => {
                    *per_object.entry(objects[idx].name.as_str()).or_default() += 1;
                }
                Receiver::Unclassified(why, value) => {
                    unclassified.push((id, name, why, value));
                }
            }
        }
    }
    assert!(
        unclassified.is_empty(),
        "sites outside the four pinned behaviours: {unclassified:?}"
    );
    assert_eq!(expression, 1104, "expression (cast to=2) receivers");
    assert_eq!(
        per_object.values().sum::<usize>(),
        143,
        "object-index receivers across {} objects",
        per_object.len()
    );
    assert_eq!(per_object.len(), 54, "distinct objects addressed by with(object)");
    // Anchors the contract names explicitly.
    assert_eq!(per_object.get("obj_lloyd").copied(), Some(16), "Lloyd sheet with-blocks");
    assert_eq!(per_object.get("obj_pause").copied(), Some(9), "pause menu with-blocks");
    assert_eq!(per_object.get("obj_store").copied(), Some(7), "store with-blocks");
}

/// The per-orb multiplicity of a boss death fan: 25 orbs, each with its own
/// `ID`n variable, and the drawn-out tail (6,6,6,6,6, 5,5,5,5,5, 3x5, 2x5, 1x5)
/// is the same in all five boss alarms - the fan is one generated block, not
/// five hand-written ones.
const FAN_PROFILE: [(usize, usize); 25] = [
    (1, 6), (2, 6), (3, 6), (4, 6), (5, 6),
    (6, 5), (7, 5), (8, 5), (9, 5), (10, 5),
    (11, 3), (12, 3), (13, 3), (14, 3), (15, 3),
    (16, 2), (17, 2), (18, 2), (19, 2), (20, 2),
    (21, 1), (22, 1), (23, 1), (24, 1), (25, 1),
];

#[test]
fn every_boss_death_fan_addresses_its_orbs_through_its_own_id_variable() {
    // Contract claim: the XP-orb fan is `ID = instance_create(...);
    // with (ID) { motion_set }`. The real bytecode adjacency must be
    // `load ID<n>` -> `cast to=2` -> `pushenv`, never an object constant, and
    // all five boss alarms must share the same 25-orb profile.
    let bundle = bundle();
    for id in [160usize, 168, 184, 196, 212] {
        let code = bundle.codes.iter().find(|c| c.id == id).expect("boss alarm");
        let mut seen: std::collections::BTreeMap<usize, usize> = std::collections::BTreeMap::new();
        let mut sites = 0usize;
        for (k, instr) in code.instructions.iter().enumerate() {
            if !matches!(instr.op, Op::Pushenv { .. }) {
                continue;
            }
            sites += 1;
            let cast = &code.instructions[k - 1];
            let load = &code.instructions[k - 2];
            assert!(
                matches!(cast.op, Op::Cast { to: 2 }),
                "CODE {id}: receiver must be a cast-to-instance, got {:?}",
                cast.op
            );
            let name = match &load.op {
                Op::Load { name, .. } => name.clone(),
                other => panic!("CODE {id}: receiver must come from a variable, got {other:?}"),
            };
            // The GML names the first orb plainly `ID` and the rest `ID2`..`ID25`.
            let suffix = name.strip_prefix("ID").unwrap_or_else(|| {
                panic!("CODE {id}: orb variable must be an ID<n>, got {name:?}")
            });
            let index: usize = if suffix.is_empty() {
                1
            } else {
                suffix.parse().expect("numeric ID suffix")
            };
            *seen.entry(index).or_default() += 1;
        }
        assert_eq!(sites, 85, "CODE {id}: 25-orb fan with-blocks");
        let profile: Vec<(usize, usize)> = seen.into_iter().collect();
        assert_eq!(profile, FAN_PROFILE, "CODE {id}: orb fan multiplicity profile");
    }
}

#[test]
fn an_unknown_receiver_shape_is_reported_not_guessed() {
    // Falsification: the classifier must key off the pushed operand. A body
    // that pushes something else before `pushenv` has to be flagged, otherwise
    // "0 unclassified" above would be a rubber stamp.
    let start = 0x1000;
    let instructions = vec![
        Instruction { offset: start, code_offset: 0, words_raw: vec![0], op: Op::Popz },
        Instruction { offset: start + 4, code_offset: 4, words_raw: vec![0], op: Op::Pushenv { target: start } },
    ];
    assert_eq!(
        classify(&instructions, 1, 191),
        Receiver::Unclassified("push is not a cast or an object index", 0.0)
    );
    // A constant that is not an object index is not an object receiver either.
    let out_of_range = vec![
        Instruction { offset: start, code_offset: 0, words_raw: vec![0], op: Op::Constant { value: 100000.0 } },
        Instruction { offset: start + 8, code_offset: 8, words_raw: vec![0], op: Op::Pushenv { target: start } },
    ];
    assert_eq!(
        classify(&out_of_range, 1, 191),
        Receiver::Unclassified("constant out of object range", 100000.0)
    );
}
