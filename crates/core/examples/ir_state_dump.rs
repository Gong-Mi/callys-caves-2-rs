//! Run one lowered CODE body through the Rust VM and dump the state in the
//! protocol `c-recon/src/main.c` speaks, so the C lowering can be diffed
//! against the interpreter it was generated from.
//!
//!     cargo run -p callys-core --example ir_state_dump -- \
//!         --ir crates/core/src/generated/full_ir.json \
//!         --state in.txt --out out.txt
//!
//! The state file is the authority for the fixture: instances are inserted
//! directly (no Create events) so both sides start from identical bytes.
use callys_core::code_vm::{self, load_bundle_from_file, Bundle};
use callys_core::ir_scene::{Instance, Scene, SpriteBounds};
use std::collections::BTreeMap;
use std::fs;
use std::path::PathBuf;

fn main() {
    let mut ir = PathBuf::new();
    let mut state_in = PathBuf::new();
    let mut out = PathBuf::new();
    let mut asset_path: Option<String> = None;
    let args: Vec<String> = std::env::args().skip(1).collect();
    let mut i = 0;
    while i < args.len() {
        match args[i].as_str() {
            "--ir" => { ir = PathBuf::from(&args[i + 1]); i += 2; }
            "--state" => { state_in = PathBuf::from(&args[i + 1]); i += 2; }
            "--out" => { out = PathBuf::from(&args[i + 1]); i += 2; }
            "--asset" => { asset_path = Some(args[i + 1].clone()); i += 2; }
            other => panic!("unknown arg {other}"),
        }
    }
    let bundle: Bundle = load_bundle_from_file(&ir).expect("load full_ir.json");
    let mut scene = Scene::default();
    scene.init_bundle(&bundle);

    let text = fs::read_to_string(&state_in).expect("read state");
    let mut code: Option<usize> = None;
    let mut current: i32 = 0;
    let mut globals: BTreeMap<String, f64> = BTreeMap::new();
    let mut insts: BTreeMap<i32, (i32, bool)> = BTreeMap::new();
    let mut fields: BTreeMap<i32, BTreeMap<String, f64>> = BTreeMap::new();
    let mut arrays: BTreeMap<i32, BTreeMap<(String, i32), f64>> = BTreeMap::new();
    let mut room_w: Option<f64> = None;
    let mut room_h: Option<f64> = None;
    for line in text.lines() {
        let w: Vec<&str> = line.split_whitespace().collect();
        match w.first().copied() {
            Some("CODE") => code = Some(w[1].parse().unwrap()),
            Some("CURRENT") => current = w[1].parse().unwrap(),
            Some("INST") => {
                insts.insert(w[1].parse().unwrap(), (w[2].parse().unwrap(), w[3] != "0"));
            }
            Some("FIELD") => {
                fields.entry(w[1].parse().unwrap()).or_default()
                    .insert(w[2].to_string(), w[3].parse().unwrap());
            }
            Some("ARRAY") => {
                arrays.entry(w[1].parse().unwrap()).or_default()
                    .insert((w[2].to_string(), w[3].parse().unwrap()), w[4].parse().unwrap());
            }
            Some("GLOBAL") => { globals.insert(w[1].to_string(), w[2].parse().unwrap()); }
            Some("ROOMW") => room_w = Some(w[1].parse().unwrap()),
            Some("ROOMH") => room_h = Some(w[1].parse().unwrap()),
            Some(other) => panic!("unexpected token {other}"),
            None => {}
        }
    }
    for (id, (object, alive)) in &insts {
        scene.instances.insert(*id, Instance {
            object: *object,
            alive: *alive,
            active: true,
            external: false,
            spawn_seq: 1,
            fields: fields.get(id).cloned().unwrap_or_default(),
            arrays: arrays.get(id).cloned().unwrap_or_default(),
            alarms: [-1; 12],
        });
    }
    scene.globals = globals;
    if let Some(w) = room_w { scene.room_width = w; }
    if let Some(h) = room_h { scene.room_height = h; }
    // Collision needs the recorded SPRT geometry. Without it every instance
    // degenerates to an integer point and a body that tests `instance_place`
    // takes the "miss" branch — the C host has the table, so the fixture must
    // give the VM the same one or the diff is measuring fixture drift.
    if let Some(path) = &asset_path {
        let asset = callys_asset::GameDroidAsset::parse(std::path::Path::new(path)).expect("game.droid");
        for (&sid, sp) in &asset.sprites {
            scene.sprite_bounds.insert(sid as i32, SpriteBounds::with_frames(
                sp.width as f64, sp.height as f64, sp.origin_x as f64, sp.origin_y as f64,
                sp.tpag_indices.len() as f64));
            if let Some(bbox) = sp.bbox { scene.sprite_bboxes.insert(sid as i32, bbox); }
            scene.sprite_masks.insert(sid as i32, sp.masks.clone());
        }
    }
    // `next_id`/`next_spawn_seq` stay at their Scene::default values: this
    // harness runs one body, and any body that creates instances needs the
    // host table (not the fixture) to own allocation.

    let code = code.expect("CODE line");
    code_vm::execute(&bundle, code, current, &mut scene).expect("execute");

    let mut out_text = String::new();
    out_text.push_str(&format!("ROOMW {}\nROOMH {}\n", scene.room_width, scene.room_height));
    for (id, inst) in &scene.instances {
        out_text.push_str(&format!("INST {} {} {}\n", id, inst.object, inst.alive as i32));
        for (k, v) in &inst.fields {
            out_text.push_str(&format!("FIELD {} {} {}\n", id, k, v));
        }
        for ((k, idx), v) in &inst.arrays {
            out_text.push_str(&format!("ARRAY {} {} {} {}\n", id, k, idx, v));
        }
        for (k, v) in inst.alarms.iter().enumerate() {
            if *v != -1 {
                out_text.push_str(&format!("ARRAY {} alarm {} {}\n", id, k, v));
            }
        }
    }
    for (k, v) in &scene.globals {
        out_text.push_str(&format!("GLOBAL {} {}\n", k, v));
    }
    fs::write(&out, out_text).expect("write out");
}
