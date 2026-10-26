//! Run lowered CODE bodies through the Rust VM and dump state in the protocol
//! `c-recon/src/main.c` speaks, so the C lowering can be diffed against the
//! interpreter it was generated from.
//!
//! One body:
//!     --ir full_ir.json --state in.txt --out out.txt [--asset game.droid]
//!
//! A whole corpus (one process, one bundle load):
//!     --ir full_ir.json --codes codes.txt --outdir out/ [--asset game.droid]
//! where each line of `codes.txt` is `<code> <object>`.
//!
//! The state file is the authority for the fixture: instances are inserted
//! directly (no Create events) so both sides start from identical bytes.
use callys_core::code_vm::{self, load_bundle_from_file, Bundle};
use callys_core::ir_scene::{Instance, Scene, SpriteBounds};
use std::collections::BTreeMap;
use std::fs;
use std::path::{Path, PathBuf};

#[derive(Clone)]
enum Step { Run(usize, i32), Tick(i64), ConsumeWarp, Collide(usize, i32, i32) }

struct Template {
    current: i32,
    other: Option<i32>,
    /// Event sequence, in order. Empty means "run CODE once on `current`".
    runs: Vec<Step>,
    seed: Option<u64>,
    globals: BTreeMap<String, f64>,
    insts: BTreeMap<i32, (i32, bool, bool)>,
    fields: BTreeMap<i32, BTreeMap<String, f64>>,
    arrays: BTreeMap<i32, BTreeMap<(String, i32), f64>>,
    room_w: Option<f64>,
    room_h: Option<f64>,
    room: Option<f64>,
    warp: Option<usize>,
}

fn parse_template(path: &Path) -> Template {
    let text = fs::read_to_string(path).expect("read state");
    let mut t = Template {
        current: 0,
        other: None,
        runs: Vec::new(),
        seed: None,
        globals: BTreeMap::new(),
        insts: BTreeMap::new(),
        fields: BTreeMap::new(),
        arrays: BTreeMap::new(),
        room_w: None,
        room_h: None,
        room: None,
        warp: None,
    };
    for line in text.lines() {
        let w: Vec<&str> = line.split_whitespace().collect();
        match w.first().copied() {
            Some("CODE") => {}
            Some("RUN") => { t.runs.push(Step::Run(w[1].parse().unwrap(), w[2].parse().unwrap())); }
            Some("COLLIDE") => {
                t.runs.push(Step::Collide(w[1].parse().unwrap(), w[2].parse().unwrap(), w[3].parse().unwrap()));
            }
            Some("TICK") => { t.runs.push(Step::Tick(w[1].parse().unwrap())); }
            Some("SEED") => { t.seed = Some(w[1].parse().unwrap()); }
            Some("CURRENT") => t.current = w[1].parse().unwrap(),
            Some("OTHER") => {
                let id = w[1].parse().unwrap();
                t.other = if id >= 0 { Some(id) } else { None };
            }
            Some("INST") => {
                // `<id> <object> [alive [active]]`; both flags default to true so
                // the two-token form keeps its old meaning.
                t.insts.insert(
                    w[1].parse().unwrap(),
                    (w[2].parse().unwrap(),
                     w.get(3).map_or(true, |s| *s != "0"),
                     w.get(4).map_or(true, |s| *s != "0")),
                );
            }
            Some("FIELD") => {
                t.fields.entry(w[1].parse().unwrap()).or_default()
                    .insert(w[2].to_string(), w[3].parse().unwrap());
            }
            Some("ARRAY") => {
                t.arrays.entry(w[1].parse().unwrap()).or_default()
                    .insert((w[2].to_string(), w[3].parse().unwrap()), w[4].parse().unwrap());
            }
            Some("GLOBAL") => { t.globals.insert(w[1].to_string(), w[2].parse().unwrap()); }
            Some("ROOMW") => t.room_w = Some(w[1].parse().unwrap()),
            Some("ROOMH") => t.room_h = Some(w[1].parse().unwrap()),
            Some("ROOM") => t.room = Some(w[1].parse().unwrap()),
            Some("WARP") => {
                if w.len() == 1 { t.runs.push(Step::ConsumeWarp); }
                else { t.warp = Some(w[1].parse().unwrap()); }
            }
            Some(other) => panic!("unexpected token {other}"),
            None => {}
        }
    }
    t
}

fn build(tpl: &Template, bundle: &Bundle, asset: Option<&callys_asset::GameDroidAsset>) -> Scene {
    let mut scene = Scene::default();
    scene.init_bundle(bundle);
    for (id, (object, alive, active)) in &tpl.insts {
        scene.instances.insert(*id, Instance {
            object: *object,
            alive: *alive,
            active: *active,
            external: false,
            spawn_seq: 1,
            fields: tpl.fields.get(id).cloned().unwrap_or_default(),
            arrays: tpl.arrays.get(id).cloned().unwrap_or_default(),
            alarms: [-1; 12],
        });
    }
    if let Some(seed) = tpl.seed { scene.rng_seed = seed; }
    scene.globals = tpl.globals.clone();
    scene.other_instance = tpl.other;
    if let Some(w) = tpl.room_w { scene.room_width = w; }
    if let Some(h) = tpl.room_h { scene.room_height = h; }
    if let Some(room) = tpl.room { scene.current_room = room; }
    if let Some(target) = tpl.warp { scene.target_room_warp = Some(target); }
    // Collision needs the recorded SPRT geometry. Without it every instance
    // degenerates to an integer point and a body that tests `instance_place`
    // takes the "miss" branch — the C host has the table, so the fixture must
    // give the VM the same one or the diff is measuring fixture drift.
    if let Some(asset) = asset {
        for (&sid, sp) in &asset.sprites {
            scene.sprite_bounds.insert(sid as i32, SpriteBounds::with_frames(
                sp.width as f64, sp.height as f64, sp.origin_x as f64, sp.origin_y as f64,
                sp.tpag_indices.len() as f64));
            if let Some(bbox) = sp.bbox { scene.sprite_bboxes.insert(sid as i32, bbox); }
            scene.sprite_masks.insert(sid as i32, sp.masks.clone());
        }
    }
    scene
}

fn dump_state(scene: &Scene) -> String {
    let mut s = String::new();
    s.push_str(&format!("ROOM {}\n", scene.current_room));
    s.push_str(&format!("ROOMW {}\nROOMH {}\n", scene.room_width, scene.room_height));
    if let Some(target) = scene.target_room_warp { s.push_str(&format!("WARP {target}\n")); }
    if let Some(other) = scene.other_instance { s.push_str(&format!("OTHER {other}\n")); }
    for index in 0..8i32 {
        let (x, y) = scene.view_positions.get(&index).copied().unwrap_or((0.0, 0.0));
        let (w, h) = scene.view_ports.get(&index).copied()
            .unwrap_or((scene.display_width, scene.display_height));
        s.push_str(&format!("VIEW {} {} {} {} {} {}\n", index, scene.view_visible[index as usize] as i32, x, y, w, h));
    }
    for (id, inst) in &scene.instances {
        s.push_str(&format!("INST {} {} {}\n", id, inst.object, inst.alive as i32));
        // Output-only marker: fixture input expresses this with INST's fourth
        // token instead. Ordinary active instances keep the old dump shape.
        if !inst.active {
            s.push_str(&format!("ACTIVE {} 0\n", id));
        }
        for (k, v) in &inst.fields {
            s.push_str(&format!("FIELD {} {} {}\n", id, k, v));
        }
        for ((k, idx), v) in &inst.arrays {
            s.push_str(&format!("ARRAY {} {} {} {}\n", id, k, idx, v));
        }
        for (k, v) in inst.alarms.iter().enumerate() {
            if *v != -1 {
                s.push_str(&format!("ARRAY {} alarm {} {}\n", id, k, v));
            }
        }
    }
    for (k, v) in &scene.globals {
        s.push_str(&format!("GLOBAL {} {}\n", k, v));
    }
    s
}

fn consume_warp(scene: &mut Scene, bundle: &Bundle,
                asset: Option<&callys_asset::GameDroidAsset>) -> Result<(), String> {
    let Some(target) = scene.target_room_warp else { return Ok(()); };
    let source = scene.current_room;
    let asset = asset.ok_or_else(|| "room warp requires --asset".to_string())?;
    let room = asset.rooms.get(target).ok_or_else(||
        format!("room transition {source} -> {target}: target outside room table"))?;
    scene.transition_to_room(bundle, target, room)
}

fn main() {
    let mut ir = PathBuf::new();
    let mut state_in = PathBuf::new();
    let mut out = PathBuf::new();
    let mut asset_path: Option<String> = None;
    let mut codes: Option<PathBuf> = None;
    let mut outdir: Option<PathBuf> = None;
    let args: Vec<String> = std::env::args().skip(1).collect();
    let mut i = 0;
    while i < args.len() {
        match args[i].as_str() {
            "--ir" => { ir = PathBuf::from(&args[i + 1]); i += 2; }
            "--state" => { state_in = PathBuf::from(&args[i + 1]); i += 2; }
            "--out" => { out = PathBuf::from(&args[i + 1]); i += 2; }
            "--asset" => { asset_path = Some(args[i + 1].clone()); i += 2; }
            "--codes" => { codes = Some(PathBuf::from(&args[i + 1])); i += 2; }
            "--outdir" => { outdir = Some(PathBuf::from(&args[i + 1])); i += 2; }
            other => panic!("unknown arg {other}"),
        }
    }
    let bundle: Bundle = load_bundle_from_file(&ir).expect("load full_ir.json");
    let asset = asset_path.as_ref().map(|p| {
        callys_asset::GameDroidAsset::parse(Path::new(p)).expect("game.droid")
    });

    if let (Some(codes), Some(outdir)) = (codes, outdir) {
        fs::create_dir_all(&outdir).expect("outdir");
        let list = fs::read_to_string(&codes).expect("read codes");
        let mut ok = 0usize;
        let mut err = 0usize;
        for line in list.lines() {
            let w: Vec<&str> = line.split_whitespace().collect();
            if w.len() < 2 { continue; }
            let code: usize = w[0].parse().unwrap();
            // The fixture path travels with the id: both implementations must
            // parse the very same bytes or the diff measures fixture drift.
            let tpl = parse_template(Path::new(w[1]));
            let mut scene = build(&tpl, &bundle, asset.as_ref());
            let seq: Vec<Step> = if tpl.runs.is_empty() {
                vec![Step::Run(code, tpl.current)]
            } else { tpl.runs.clone() };
            let mut result: Result<(), String> = Ok(());
            for step in &seq {
                result = match step {
                    Step::Run(c, who) => code_vm::execute(&bundle, *c, *who, &mut scene)
                        .map_err(|e| format!("{} offset={}", e.message, e.offset)),
                    Step::Tick(n) => {
                        let mut r = Ok(());
                        for _ in 0..*n { r = scene.tick(&bundle); if r.is_err() { break; } }
                        r
                    },
                    Step::ConsumeWarp => consume_warp(&mut scene, &bundle, asset.as_ref()),
                    Step::Collide(code, who, other) => {
                        let previous = scene.other_instance;
                        scene.other_instance = Some(*other);
                        let result = code_vm::execute(&bundle, *code, *who, &mut scene)
                            .map_err(|e| format!("{} offset={}", e.message, e.offset));
                        scene.other_instance = previous;
                        result
                    },
                };
                if result.is_err() { break; }
            }
            let text = match result {
                Ok(()) => { ok += 1; dump_state(&scene) }
                Err(msg) => { err += 1; format!("ERROR {msg}\n") }
            };
            // One body can be run under several fixtures; name the dump after
            // the fixture so variants never overwrite each other.
            let stem = Path::new(w[1]).file_stem().and_then(|s| s.to_str()).unwrap_or("body");
            fs::write(outdir.join(format!("{stem}.txt")), text).expect("write body");
        }
        eprintln!("bodies: ok={ok} error={err}");
        return;
    }

    let tpl = parse_template(&state_in);
    let mut scene = build(&tpl, &bundle, asset.as_ref());
    let seq: Vec<Step> = if tpl.runs.is_empty() {
        let code: usize = fs::read_to_string(&state_in).expect("read state")
            .lines().find_map(|l| l.strip_prefix("CODE "))
            .expect("CODE line").trim().parse().expect("code id");
        vec![Step::Run(code, tpl.current)]
    } else {
        tpl.runs.clone()
    };
    for step in &seq {
        match step {
            Step::Run(c, who) => code_vm::execute(&bundle, *c, *who, &mut scene).expect("execute"),
            Step::Tick(n) => { for _ in 0..*n { scene.tick(&bundle).expect("tick"); } },
            Step::ConsumeWarp => consume_warp(&mut scene, &bundle, asset.as_ref()).expect("consume warp"),
            Step::Collide(code, who, other) => {
                let previous = scene.other_instance;
                scene.other_instance = Some(*other);
                let result = code_vm::execute(&bundle, *code, *who, &mut scene);
                scene.other_instance = previous;
                result.expect("collide");
            }
        }
    }
    fs::write(&out, dump_state(&scene)).expect("write out");
}
