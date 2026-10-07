//! Raster cost per room: the software rasterizer's per-frame price scales with
//! the room's primitive count, so a single town measurement understates what
//! real gameplay costs. Restores the IR scene into each candidate room through
//! the normal cross-room transition (Room End -> purge -> load -> Room Start)
//! and times draw_frame there.
//!
//! Usage: cargo run --release --example room_raster_cost
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::sync::Arc;
use std::time::Instant;

const W: u32 = 1136;
const H: u32 = 640;
const N: u32 = 300;

fn save_for(room: usize) -> SaveData {
    SaveData {
        format_version: 2,
        current_room: room,
        checkpoint: Checkpoint { room_index: room, x: 0.0, y: 0.0 },
        max_health: 10,
        gems: 0,
        coins: 0,
        current_weapon: WeaponType::Pistol,
        unlocked_weapons: vec![WeaponType::Pistol],
        collected_instance_ids: Vec::new(),
        scene_globals: BTreeMap::new(),
        score: 0.0,
    }
}

fn main() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap(),
    );
    state.enable_ir_gameplay(bundle).unwrap();
    let mut fb = Framebuffer::new(W, H);
    let dt = 1.0f32 / 60.0;

    // Heaviest rooms by (tiles + objects), plus town as the known-good baseline.
    let mut ranked: Vec<(usize, usize, String)> = state
        .asset
        .rooms
        .iter()
        .enumerate()
        .map(|(i, r)| (i, r.tiles.len() + r.objects.len(), r.name.clone()))
        .collect();
    ranked.sort_by_key(|r| std::cmp::Reverse(r.1));
    let mut targets: Vec<(usize, String)> = vec![(0, state.asset.rooms[0].name.clone())];
    for (i, c, n) in ranked.iter().take(5) {
        println!("  candidate: room {i} {n} primitives={c}");
        if *i != 0 {
            targets.push((*i, n.clone()));
        }
        let _ = c;
    }

    println!("{W}x{H} canvas, {N} iterations per room\n");
    println!("{:>5} {:>22} {:>8} {:>10} {:>10}", "room", "name", "alive", "raster ms", "fps@raster");
    for (room, name) in targets {
        if let Err(e) = state.restore_ir_snapshot(&save_for(room)) {
            println!("{room:>5} {name:>22} restore failed: {e}");
            continue;
        }
        for _ in 0..30 {
            state.step(dt);
        }
        let alive = state
            .scene
            .as_ref()
            .map(|s| s.instances.values().filter(|i| i.alive && i.active).count())
            .unwrap_or(0);
        let t = Instant::now();
        for _ in 0..N {
            draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
        }
        let ms = t.elapsed().as_secs_f64() * 1000.0 / N as f64;
        println!("{room:>5} {name:>22} {alive:>8} {ms:>10.2} {:>10.1}", 1000.0 / ms);
    }
}
