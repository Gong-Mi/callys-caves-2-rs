//! Pins the weapon -> boss damage matrix straight from the IR.
//!
//! The matrix is a data fact, not a behaviour: which weapon bodies write
//! `(hittrex|hit15|hit11|...).alarm[N]`. Recomputing it here means an IR
//! regeneration that silently changes weapon coverage (a new weapon, a body
//! that stops arming poison) fails loudly instead of drifting.
//!
//! Point-write shape, per code_vm: value on the stack, `load <var>`,
//! `cast to=2`, optional `constant <index>` for array stores, `store`.
//! Compound assignment (`hp -= dmg`) puts the dest under the value:
//! `load <var>; cast to=2; dup; <value>; store`. Both are handled.

use serde_json::Value;

fn ir() -> Value {
    serde_json::from_str(include_str!("../src/generated/full_ir.json")).expect("full_ir.json")
}

/// (code id, code name, target variable, field, array index) for every
/// point-write in the corpus.
fn point_writes(ir: &Value) -> Vec<(i64, String, String, String, Option<i64>)> {
    let mut out = Vec::new();
    for c in ir["codes"].as_array().expect("codes") {
        let id = c["id"].as_i64().expect("id");
        let name = c["name"].as_str().unwrap_or_default().to_string();
        let ins = c["instructions"].as_array().expect("instructions");
        for (i, x) in ins.iter().enumerate() {
            if x["op"] != "store" {
                continue;
            }
            let field = x["name"].as_str().unwrap_or_default().to_string();
            let mut j = i as i64 - 1;
            let mut idx = None;
            if x["array"].as_bool().unwrap_or(false) {
                if j < 0 || ins[j as usize]["op"] != "constant" {
                    continue;
                }
                idx = ins[j as usize]["value"].as_i64();
                j -= 1;
            }
            if j < 0 {
                continue;
            }
            let plain = ins[j as usize]["op"] == "cast"
                && ins[j as usize]["to"].as_i64() == Some(2)
                && j - 1 >= 0
                && ins[(j - 1) as usize]["op"] == "load";
            let var = if plain {
                ins[(j - 1) as usize]["name"].as_str().map(str::to_string)
            } else {
                // compound: dup within six instructions before the store,
                // preceded by cast(2) and load.
                let mut k = i as i64 - 1;
                while k >= 0 && (i as i64 - k) <= 6 && ins[k as usize]["op"] != "dup" {
                    k -= 1;
                }
                if k >= 2
                    && ins[k as usize]["op"] == "dup"
                    && ins[(k - 1) as usize]["op"] == "cast"
                    && ins[(k - 1) as usize]["to"].as_i64() == Some(2)
                    && ins[(k - 2) as usize]["op"] == "load"
                {
                    ins[(k - 2) as usize]["name"].as_str().map(str::to_string)
                } else {
                    None
                }
            };
            if let Some(var) = var {
                out.push((id, name.clone(), var, field, idx));
            }
        }
    }
    out
}

/// Variables that carry a boss instance, with the object they come from
/// (`instance_place(x, y, obj)` followed by a local store).
fn boss_vars(ir: &Value) -> Vec<(String, i64)> {
    let mut out = Vec::new();
    for c in ir["codes"].as_array().expect("codes") {
        let ins = c["instructions"].as_array().expect("instructions");
        for (i, x) in ins.iter().enumerate() {
            if x["op"] != "call" || x["name"] != "instance_place" {
                continue;
            }
            let mut obj = None;
            for k in (0..i).rev().take(5) {
                if ins[k]["op"] == "constant" {
                    obj = ins[k]["value"].as_i64();
                    break;
                }
            }
            let obj = match obj {
                Some(o) => o,
                None => continue,
            };
            for k in (i + 1)..(i + 3).min(ins.len()) {
                if ins[k]["op"] == "store" && ins[k]["selector"].as_i64() == Some(-1) {
                    if let Some(name) = ins[k]["name"].as_str() {
                        out.push((name.to_string(), obj));
                    }
                    break;
                }
            }
        }
    }
    out.sort();
    out.dedup();
    out
}

#[test]
fn boss_variable_map_is_pinned() {
    let ir = ir();
    let map = boss_vars(&ir);
    let expected = vec![
        ("hit11".to_string(), 30),
        ("hit15".to_string(), 26),
        ("hit16".to_string(), 27),
        ("hit17".to_string(), 30),
        ("hitboss2".to_string(), 26),
        ("hitboss3".to_string(), 27),
        ("hitboss4".to_string(), 28),
        ("hitboss5".to_string(), 29),
        ("hitenemytrex".to_string(), 25),
        ("hitfinalboss".to_string(), 30),
        ("hittrex".to_string(), 25),
    ];
    let mut expected = expected;
    expected.sort();
    // hit11 / hit15 / hit17 also resolve against the final boss through a
    // second instance_place, which is why the pairs are many-to-many.
    let got: Vec<(String, i64)> = map
        .iter()
        .filter(|(v, o)| {
            matches!(
                (v.as_str(), *o),
                ("hittrex", 25)
                    | ("hitenemytrex", 25)
                    | ("hit15", 26)
                    | ("hit16", 27)
                    | ("hitboss2", 26)
                    | ("hitboss3", 27)
                    | ("hitboss4", 28)
                    | ("hitboss5", 29)
                    | ("hitfinalboss", 30)
                    | ("hit11", 30)
                    | ("hit17", 30)
            )
        })
        .cloned()
        .collect();
    assert_eq!(got.len(), 11, "the filter must match the whole boss map");
    assert_eq!(
        got, expected,
        "boss variable -> object mapping changed; check weapon chains"
    );
    assert!(
        map.iter().any(|(v, o)| v == "hit11" && *o == 21),
        "hit11 must also resolve the hulking bandit"
    );
}

#[test]
fn only_three_boss_paths_are_poison_armed_and_none_is_stunned() {
    let ir = ir();
    let writes = point_writes(&ir);
    let armers = |index: i64, var: &str| -> Vec<i64> {
        let mut v: Vec<i64> = writes
            .iter()
            .filter(|(_, _, w, f, i)| f == "alarm" && *i == Some(index) && w == var)
            .map(|(c, _, _, _, _)| *c)
            .collect();
        v.sort_unstable();
        v.dedup();
        v
    };
    assert_eq!(
        armers(6, "hittrex"),
        vec![270, 274, 281, 284, 289, 294, 303],
        "trex poison armers (flame, blade, arrow, bullet, laser, spike, rocket)"
    );
    assert_eq!(
        armers(6, "hit15"),
        vec![270, 274, 281, 284, 289, 294],
        "boss2 is only reached through hit15, and bomb/boomerang/rocket skip it"
    );
    assert_eq!(
        armers(6, "hit11"),
        vec![270, 274, 278, 281, 284, 289, 294, 298, 303],
        "final boss is reached through hit11 with the widest weapon set"
    );
    for var in ["hit16", "hitboss2", "hitboss3", "hitboss4", "hitboss5", "hitfinalboss"] {
        assert!(
            armers(6, var).is_empty(),
            "{var} must have no poison armer: bosses 3/4/5 and the direct final-boss \
             variable are immune to every weapon's poison"
        );
    }
    // Sword stun: the only weapon bodies that touch alarm[5] are the sword
    // (311) and the spike (294), and neither writes a boss variable.
    let boss_vars = [
        "hittrex", "hitenemytrex", "hit15", "hit16", "hit11", "hitbosS2", "hitboss3",
        "hitboss4", "hitboss5", "hitfinalboss",
    ];
    for var in boss_vars {
        assert!(
            armers(5, var).is_empty(),
            "no boss may be sword-stunned ({var})"
        );
    }
    // Bosses 3/4/5 poison themselves from their own alarm chains: no
    // point-write at all targets alarm[10] or alarm[11].
    assert!(writes
        .iter()
        .filter(|(_, _, _, f, i)| f == "alarm" && (*i == Some(10) || *i == Some(11)))
        .count()
        == 0,
        "alarm[10]/alarm[11] are self-armed; a point-write would change that");
}
