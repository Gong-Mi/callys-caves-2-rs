//! Framebuffer byte-hash trace: the equivalence oracle for rasterizer work.
//!
//! Prints an FNV-1a 64 hash of `fb.pixels` after every drawn frame, for the
//! boot/prologue sequence and a set of rooms reached through the normal
//! cross-room transition. Any change that alters a single pixel changes a hash,
//! so a before/after run is a byte-exact equivalence proof for the frames it
//! covers (and a much cheaper one than diffing images).
//!
//! Usage: cargo run --release --example draw_hash > /tmp/draw-hash-before.txt
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::sync::Arc;

const W: u32 = 1136;
const H: u32 = 640;
const FRAMES: u32 = 40;

fn fnv1a(bytes: &[u8]) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    for b in bytes {
        h ^= *b as u64;
        h = h.wrapping_mul(0x100_0000_01b3);
    }
    h
}

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

    // 1. Boot + prologue, the path the app takes on a cold start.
    for frame in 0..FRAMES {
        state.step(dt);
        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
        println!("prologue f{frame:03} {}", fnv1a(&fb.pixels));
    }
    // Tap out of the prologue the way a player does, then keep drawing.
    state.input.tap = true;
    state.step(dt);
    state.input.tap = false;
    for frame in 0..FRAMES {
        state.step(dt);
        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
        println!("handover f{frame:03} {}", fnv1a(&fb.pixels));
    }

    // 2. Representative rooms, including the heaviest by primitive count.
    for room in [0usize, 1, 2, 23, 25, 39, 109, 111] {
        let name = state.asset.rooms[room].name.clone();
        if let Err(e) = state.restore_ir_snapshot(&save_for(room)) {
            println!("room{room:03} {name} restore failed: {e}");
            continue;
        }
        for frame in 0..FRAMES {
            state.step(dt);
            draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
            println!("room{room:03} {name} f{frame:03} {}", fnv1a(&fb.pixels));
        }
    }
}
