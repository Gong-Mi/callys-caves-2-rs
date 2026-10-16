//! Guard: the engine's sound-duration table (crates/core/src/sond_durations.rs,
//! WL8) must match the audio contract it is generated from
//! (reconstruction/contracts/audio-durations.json, 54/54 SOND rows).
//!
//! If the contract is regenerated with new measurements, the generated Rust
//! table must be regenerated too — a silent drift re-opens every
//! `audio_is_playing` anti-stack gate the durations feed (86 sites, incl.
//! obj_music's 24-deep BGM chain).

use std::collections::BTreeMap;
use std::path::Path;

#[test]
fn sond_durations_table_matches_the_audio_contract() {
    let manifest = Path::new(env!("CARGO_MANIFEST_DIR"));
    let contract_path = manifest.join("../../reconstruction/contracts/audio-durations.json");
    let text = std::fs::read_to_string(&contract_path)
        .unwrap_or_else(|e| panic!("read {}: {e}", contract_path.display()));
    let rows: serde_json::Value = serde_json::from_str(&text).expect("audio-durations.json parses");
    let rows = rows.as_array().expect("contract is a JSON array");

    assert_eq!(rows.len(), 54, "the contract holds 54/54 SOND rows");
    let contract: BTreeMap<i32, (String, f64)> = rows
        .iter()
        .map(|r| {
            (
                r["sond_id"].as_i64().expect("sond_id int") as i32,
                (
                    r["name"].as_str().expect("name str").to_string(),
                    r["seconds"].as_f64().expect("seconds f64"),
                ),
            )
        })
        .collect();

    let table: BTreeMap<i32, f64> = callys_core::sond_durations::table();

    assert_eq!(
        table.len(),
        contract.len(),
        "engine table row count must equal the contract's"
    );
    for (id, (name, seconds)) in &contract {
        let engine = table
            .get(id)
            .unwrap_or_else(|| panic!("contract row {id} ({name}) missing from the engine table"));
        assert_eq!(
            *engine, *seconds,
            "duration drift for sond {id} ({name}): engine {engine}s vs contract {seconds}s; \
             regenerate crates/core/src/sond_durations.rs from the contract"
        );
    }
}
