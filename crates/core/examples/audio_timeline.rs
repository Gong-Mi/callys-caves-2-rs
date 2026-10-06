//! Per-tick audio timeline from the rebuild's IR simulation.
//!
//! Boots rm_town exactly like the room tests (asset parse + fresh-start
//! globals + room load), then ticks and drains `Scene::audio` every tick.
//! Each drained `AudioCommand` carries {code, offset, sound, priority,
//! looping, voice}; `code` is the CODE id that issued the play, which joins
//! directly to reconstruction/live-mem/audio-call-table.json (code_id key).
//!
//! Run: cargo run --example audio_timeline -p callys-core --offline
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn main() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid"))
        .expect("parse game.droid");
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sp.width as f64,
            height: sp.height as f64,
            origin_x: sp.origin_x as f64,
            origin_y: sp.origin_y as f64,
            frames: sp.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load rm_town");
    println!("room=rm_town instances={}", s.instances.len());

    let ticks: usize = std::env::args().nth(1).and_then(|v| v.parse().ok()).unwrap_or(600);
    let mut total = 0usize;
    for tick in 0..ticks {
        match s.tick(&bundle) {
            Ok(()) => {}
            Err(e) => { eprintln!("tick {}: {}", tick, e); break; }
        }
        let drained = s.drain_audio();
        for cmd in &drained {
            total += 1;
            println!("tick {:4}  code {:4}  sound {:4}  loop {:5}  prio {:4}",
                     tick, cmd.code, cmd.sound, cmd.looping, cmd.priority);
        }
    }
    println!("drained audio commands: {}", total);
}
