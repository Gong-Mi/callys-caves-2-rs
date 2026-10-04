//! Temporary probe v2: where does the intro's instance_deactivate_all get
//! undone, and what is the real ordering? Plus room/sprite facts.
//! Delete after diagnosis (probe discipline).

use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{collections::HashMap, path::Path, sync::Arc};

const DUMP_FRAMES: [usize; 15] =
    [0, 1, 2, 4, 6, 8, 10, 12, 14, 16, 30, 60, 90, 120, 239];

fn main() {
    let manifest = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset_path = manifest.join("../../assets/game.droid");
    let bundle_path = manifest.join("../../crates/core/src/generated/full_ir.json");
    let mut state = GameState::new(&asset_path).expect("GameState::new");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");

    let names: HashMap<i32, String> = state
        .asset
        .objects
        .iter()
        .map(|o| (o.id as i32, o.name.clone()))
        .collect();

    // ---- T0: state right after enable, before any step ----
    {
        let scene = state.scene.as_ref().expect("scene");
        println!(
            "T0 after enable: total={} alive={} active={}",
            scene.instances.len(),
            scene.instances.values().filter(|i| i.alive).count(),
            scene.instances.values().filter(|i| i.alive && i.active).count()
        );
        let mut ids: Vec<i32> = scene.instances.keys().copied().collect();
        ids.sort();
        for id in &ids {
            let i = &scene.instances[id];
            let n = names.get(&i.object).cloned().unwrap_or_default();
            println!("  T0 inst[{id}] {n} alive={} active={}", i.alive, i.active);
        }
    }

    // ---- room + object + sprite facts ----
    let room = &state.asset.rooms[0];
    let name_of = |oid: i32| names.get(&oid).cloned().unwrap_or_default();
    println!("rm_town object slots: {}", room.objects.len());
    for (k, o) in room.objects.iter().enumerate() {
        let n = name_of(o.object_id as i32);
        if o.object_id == 137 || o.object_id == 133 || n.contains("phone") || n == "obj_logo" {
            println!("  room slot {k}: obj {} ({n})", o.object_id);
        }
    }
    for (k, o) in room.objects.iter().enumerate().rev().take(6) {
        println!("  tail slot {k}: obj {} ({})", o.object_id, name_of(o.object_id as i32));
    }
    for want in ["obj_phone", "obj_introduction", "obj_logo", "obj_viewresolution", "obj_bg"] {
        if let Some(o) = state.asset.objects.iter().find(|o| o.name == want) {
            println!("object {want}: id={} sprite={}", o.id, o.sprite_id);
        }
    }
    for o in state.asset.objects.iter() {
        if ["obj_phone", "obj_introduction", "obj_logo"].contains(&o.name.as_str()) {
            let sid = o.sprite_id as usize;
            if let Some(sp) = state.asset.sprites.get(&sid) {
                println!(
                    "sprite {sid} of {}: {}x{} origin=({},{})",
                    o.name, sp.width, sp.height, sp.origin_x, sp.origin_y
                );
            }
        }
    }

    // ---- per-frame evolution with actives delta ----
    let mut prev: HashMap<i32, bool> = HashMap::new();
    for f in 0..240usize {
        state.step(1.0 / 60.0);
        if let Some(scene) = state.scene.as_ref() {
            let mut changes: Vec<String> = Vec::new();
            let mut ids: Vec<i32> = scene.instances.keys().copied().collect();
            ids.sort();
            for id in &ids {
                let i = &scene.instances[id];
                let now = i.alive && i.active;
                let was = prev.get(id).copied();
                if let Some(was) = was {
                    if was != now {
                        changes.push(format!(
                            "[{id} {} {was}->{now}]",
                            names.get(&i.object).cloned().unwrap_or_default()
                        ));
                    }
                }
                prev.insert(*id, now);
            }
            if !changes.is_empty() {
                println!("frame {f}: {} changes: {}", changes.len(), changes.join(" "));
            }
        }
        if DUMP_FRAMES.contains(&f) {
            dump(&state, f, &names);
        }
    }
}

fn dump(state: &GameState, frame: usize, names: &HashMap<i32, String>) {
    let Some(scene) = state.scene.as_ref() else {
        println!("==== frame {frame}: NO SCENE ====");
        return;
    };
    let diag = state.runtime_diagnostic.as_deref().unwrap_or("none");
    println!(
        "==== frame {frame} | diag={diag} | view_visible={:?} | active_view={:?}",
        scene.view_visible.iter().map(|&b| b as u8).collect::<Vec<_>>(),
        scene.active_view_index()
    );
    println!("     view_positions={:?}", scene.view_positions);
    println!(
        "     counts: draws={} instances_total={} alive={} active={}",
        scene.draws.len(),
        scene.instances.len(),
        scene.instances.values().filter(|i| i.alive).count(),
        scene.instances.values().filter(|i| i.alive && i.active).count()
    );
    for d in &scene.draws {
        if d.instance >= 200000 || d.sprite == 161 || d.sprite == 162 {
            println!(
                "  draw sprite={} frame={:.0} x={:.1} y={:.1} sx={:.3} sy={:.3} view={} inst={}",
                d.sprite, d.frame, d.x, d.y, d.scale_x, d.scale_y, d.view, d.instance
            );
        }
    }
    for id in [0, 100046, 200001, 200002, 200003] {
        if let Some(i) = scene.instances.get(&id) {
            let n = names.get(&i.object).cloned().unwrap_or_default();
            let g = |k: &str| i.fields.get(k).copied();
            println!(
                "  inst[{id}] {n} active={} x={:?} y={:?} sprite={:?} img={:?}",
                i.active,
                g("x"),
                g("y"),
                g("sprite_index"),
                g("image_index")
            );
        }
    }
}
