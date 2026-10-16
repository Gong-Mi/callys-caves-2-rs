//! GPU command list trace — the artifact of contract `gpu-command-backend.md`
//! section 4 slice 1.
//!
//! It walks exactly the frames `examples/draw_hash.rs` walks (the boot
//! prologue, the tap that retires it, then the eight rooms of the equivalence
//! gate, 40 frames each = 400), but draws them through
//! `draw_frame_with_commands`, so every frame also emits its command list. Two
//! things come out of it:
//!
//! 1. **The equivalence gate, with emission on.** The `name fNNN <fnv> ` lines
//!    are byte-for-byte the format `draw_hash` prints; `grep -v '^#'` on this
//!    output is directly diffable against a `draw_hash` baseline. Identical
//!    hashes here and there mean emitting the command list changed no pixel on
//!    any of the 400 frames.
//! 2. **The list's shape**, per frame and per room: command/quad/fill counts,
//!    consecutive page runs (the census' `page_runs`), the full batch-run count,
//!    how much of the list is on screen, and the float[] staging size - next to
//!    the slice-2 guard's own counters for the same frame, so the relationship
//!    "list = what the guard kept" is visible per frame (`gate=ok`).
//!
//! The per-frame list and staging fingerprints are a *verification* cost: the
//! spike's placebo p5 measured 524 us for an FNV-1a over 64,480 B, which is why
//! section 2 p5 rules out hashing vertices per frame at runtime. Nothing here
//! is a proposal for the render loop.
//!
//! Usage: cargo run --release --example gpu_commands > out.txt
use callys_client::{
    consume_command_list, draw_frame_with_commands, reset_view_cull_stats, view_cull_stats,
    Framebuffer, GameState, GpuBody, GpuCommandList, GpuQuadDst,
};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::DrawPhase;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::path::Path;
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

fn mix(h: &mut u64, bytes: &[u8]) {
    for b in bytes {
        *h ^= *b as u64;
        *h = h.wrapping_mul(0x100_0000_01b3);
    }
}

/// Canonical serialization of the model, folded into an FNV-1a hash: every
/// field of every command, in list order. Two runs that produce the same frame
/// must produce the same bytes here.
fn list_fingerprint(list: &GpuCommandList) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    mix(&mut h, &(list.len() as u64).to_le_bytes());
    for cmd in list.commands() {
        mix(&mut h, &[match cmd.kind {
            callys_client::GpuCommandKind::Sprite => 0,
            callys_client::GpuCommandKind::Tile => 1,
            callys_client::GpuCommandKind::Background => 2,
            callys_client::GpuCommandKind::Glyph => 3,
            callys_client::GpuCommandKind::Fill => 4,
        }]);
        mix(&mut h, &[match cmd.slot.phase { DrawPhase::Room => 0, DrawPhase::Gui => 1 }]);
        mix(&mut h, &cmd.slot.depth.to_le_bytes());
        mix(&mut h, &(cmd.slot.emit_order as u64).to_le_bytes());
        match cmd.body {
            GpuBody::Quad { page, src, dst, paint } => {
                mix(&mut h, &[0]);
                mix(&mut h, &(page.tex as u64).to_le_bytes());
                for v in [page.rect.0, page.rect.1, page.rect.2, page.rect.3, page.atlas.0, page.atlas.1] {
                    mix(&mut h, &v.to_le_bytes());
                }
                for v in [src.0, src.1, src.2, src.3] {
                    mix(&mut h, &v.to_le_bytes());
                }
                match dst {
                    GpuQuadDst::Rect { x, y, w: rw, h: rh, flip_x } => {
                        mix(&mut h, &[0]);
                        mix(&mut h, &(x as i64).to_le_bytes());
                        mix(&mut h, &(y as i64).to_le_bytes());
                        mix(&mut h, &(rw as u64).to_le_bytes());
                        mix(&mut h, &(rh as u64).to_le_bytes());
                        mix(&mut h, &[flip_x as u8]);
                    }
                    GpuQuadDst::Sprite { anchor, canvas, origin, scale, rotation_deg } => {
                        mix(&mut h, &[1]);
                        mix(&mut h, &anchor.0.to_le_bytes());
                        mix(&mut h, &anchor.1.to_le_bytes());
                        mix(&mut h, &(canvas.0 as u64).to_le_bytes());
                        mix(&mut h, &(canvas.1 as u64).to_le_bytes());
                        mix(&mut h, &(origin.0 as i64).to_le_bytes());
                        mix(&mut h, &(origin.1 as i64).to_le_bytes());
                        mix(&mut h, &scale.0.to_le_bytes());
                        mix(&mut h, &scale.1.to_le_bytes());
                        mix(&mut h, &rotation_deg.to_le_bytes());
                    }
                }
                mix(&mut h, &paint.alpha.to_le_bytes());
                mix(&mut h, &[paint.blend.0, paint.blend.1, paint.blend.2]);
                match paint.flood {
                    Some(c) => mix(&mut h, &[1, c.0, c.1, c.2]),
                    None => mix(&mut h, &[0]),
                }
            }
            GpuBody::Fill { rect, rgba } | GpuBody::Outline { rect, rgba } => {
                let is_outline = matches!(cmd.body, GpuBody::Outline { .. });
                mix(&mut h, &[if is_outline { 2 } else { 1 }]);
                mix(&mut h, &(rect.0 as i64).to_le_bytes());
                mix(&mut h, &(rect.1 as i64).to_le_bytes());
                mix(&mut h, &(rect.2 as u64).to_le_bytes());
                mix(&mut h, &(rect.3 as u64).to_le_bytes());
                mix(&mut h, &[rgba.0, rgba.1, rgba.2, rgba.3]);
            }
        }
    }
    h
}

fn fnv1a_floats(xs: &[f32]) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    for x in xs {
        mix(&mut h, &x.to_le_bytes());
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

/// One room's aggregate, printed at the end so the contract's numbers can be
/// read off directly.
#[derive(Default)]
struct RoomAgg {
    label: String,
    frames: u32,
    guard_cmds: u64,
    guard_dropped: u64,
    quads: u64,
    sprite_quads: u64,
    fills: u64,
    outlines: u64,
    page_runs: u64,
    runs: u64,
    in_view_quads: u64,
    in_view_page_runs: u64,
    staging_bytes: u64,
    /// Atlas texture -> commands in the list, over the room's frames.
    pages: BTreeMap<Option<usize>, u64>,
    /// Atlas texture -> *pre-guard* sprite commands, resolved from the scene
    /// stream - the census' "page histogram (emitted)" counterpart.
    pre_pages: BTreeMap<Option<usize>, u64>,
    quads_min: u64,
    quads_max: u64,
    gate_ok: bool,
    /// Frames on which the list held more sprite quads than the guard kept:
    /// impossible, and the one way this slice could be shipping a phantom.
    gate_over: u32,
    /// Consecutive same-page runs over the *pre-guard* sprite stream (the
    /// census' subject), sum/min/max over the room's frames.
    pre_page_runs: u64,
    pre_page_runs_min: u64,
    pre_page_runs_max: u64,
    guard_cmds_min: u64,
    guard_cmds_max: u64,
}

/// The atlas page a sprite command samples, resolved exactly the way the sprite
/// emitter resolves it (frame -> TPAG item -> atlas). Used for the census
/// comparison only; the emitter is the source of truth for the list.
fn page_of_sprite(state: &GameState, cmd: &callys_core::ir_scene::DrawCommand) -> Option<usize> {
    let sprite = state.asset.sprites.get(&(cmd.sprite as usize))?;
    if sprite.tpag_indices.is_empty() {
        return None;
    }
    let frame = cmd.frame.max(0.0) as usize % sprite.tpag_indices.len();
    let page = state.asset.tpag_items.get(&(sprite.tpag_indices[frame] as usize))?;
    Some(page.tex_id as usize)
}

fn main() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap(),
    );
    state.enable_ir_gameplay(bundle).unwrap();
    let mut fb = Framebuffer::new(W, H);
    let mut list = GpuCommandList::new();
    let dt = 1.0f32 / 60.0;

    let trace = |state: &GameState, fb: &mut Framebuffer, list: &mut GpuCommandList, label: &str, frame: u32, agg: &mut RoomAgg| {
        // The guard's counters for exactly this frame, next to the list's own.
        reset_view_cull_stats();
        draw_frame_with_commands(fb, state, &state.asset.tpag_items, &state.asset.sprites, list);
        let cull = view_cull_stats();
        let s = consume_command_list(list, (W, H));
        let gate_ok = s.counts.sprite == cull.sprite_kept() as usize;
        let gate_over = s.counts.sprite > cull.sprite_kept() as usize;
        println!("{label} f{frame:03} {}", fnv1a(&fb.pixels));
        println!(
            "#cmd {label} f{frame:03} cmd={} quads={} sprite_quads={} fills={} outlines={} \
             page_runs={} runs={} in_view_quads={} in_view_page_runs={} vertices={} staging_bytes={} \
             guard_cmds={} guard_tested={} guard_dropped={} guard_kept={} gate={} \
             list_fp={:016x} staging_fp={:016x}",
            s.commands, s.quads, s.counts.sprite, s.fills, s.outlines,
            s.page_runs, s.draw_calls(), s.in_view_quads, s.in_view_page_runs,
            s.vertices, s.staging_bytes,
            cull.sprite_commands, cull.sprite_tested, cull.sprite_culled, cull.sprite_kept(),
            if gate_ok { "ok" } else if gate_over { "OVER" } else { "fewer" },
            list_fingerprint(list), fnv1a_floats(&s.staging),
        );
        for cmd in list.commands() {
            let tex = match cmd.body {
                GpuBody::Quad { page, .. } => Some(page.tex),
                GpuBody::Fill { .. } | GpuBody::Outline { .. } => None,
            };
            *agg.pages.entry(tex).or_insert(0) += 1;
        }
        if let Some(scene) = state.scene.as_ref() {
            // The pre-guard sprite stream: the census' subject (its
            // depth-sorted static layer), and the only way to reconcile the
            // contract's 55 page runs, which was measured over the *whole*
            // static layer rather than over a culled frame's survivors.
            let mut pre_page_runs = 0u64;
            let mut last: Option<Option<usize>> = None;
            for e in scene.ordered_draw_commands() {
                if let callys_core::ir_scene::DrawQueue::Sprite(i) = e.queue {
                    *agg.pre_pages.entry(page_of_sprite(state, &scene.draws[i])).or_insert(0) += 1;
                    let p = page_of_sprite(state, &scene.draws[i]);
                    if last != Some(p) {
                        pre_page_runs += 1;
                        last = Some(p);
                    }
                }
            }
            agg.pre_page_runs += pre_page_runs;
            agg.pre_page_runs_min = agg.pre_page_runs_min.min(pre_page_runs);
            agg.pre_page_runs_max = agg.pre_page_runs_max.max(pre_page_runs);
            agg.guard_cmds_min = agg.guard_cmds_min.min(cull.sprite_commands);
            agg.guard_cmds_max = agg.guard_cmds_max.max(cull.sprite_commands);
        }
        agg.gate_over += gate_over as u32;
        agg.frames += 1;
        agg.guard_cmds += cull.sprite_commands;
        agg.guard_dropped += cull.sprite_culled;
        agg.quads += s.quads as u64;
        agg.sprite_quads += s.counts.sprite as u64;
        agg.fills += s.fills as u64;
        agg.outlines += s.outlines as u64;
        agg.page_runs += s.page_runs as u64;
        agg.runs += s.draw_calls() as u64;
        agg.in_view_quads += s.in_view_quads as u64;
        agg.in_view_page_runs += s.in_view_page_runs as u64;
        agg.staging_bytes += s.staging_bytes as u64;
        if agg.quads_min == 0 || (s.quads as u64) < agg.quads_min {
            agg.quads_min = s.quads as u64;
        }
        agg.quads_max = agg.quads_max.max(s.quads as u64);
        agg.gate_ok &= gate_ok;
    };

    // 1. Boot + prologue, the path the app takes on a cold start.
    let mut prologue = RoomAgg { gate_ok: true, ..Default::default() };
    for frame in 0..FRAMES {
        state.step(dt);
        trace(&state, &mut fb, &mut list, "prologue", frame, &mut prologue);
    }
    state.input.tap = true;
    state.step(dt);
    state.input.tap = false;
    for frame in 0..FRAMES {
        state.step(dt);
        trace(&state, &mut fb, &mut list, "handover", frame, &mut prologue);
    }

    // 2. The rooms the equivalence gate walks; rm_level17 (25) is the one the
    //    contract measured.
    let mut rooms = Vec::new();
    for room in [0usize, 1, 2, 23, 25, 39, 109, 111] {
        let name = state.asset.rooms[room].name.clone();
        if let Err(e) = state.restore_ir_snapshot(&save_for(room)) {
            println!("#room room{room:03} {name} restore failed: {e}");
            continue;
        }
        let mut agg = RoomAgg {
            label: format!("room{room:03}"),
            gate_ok: true,
            pre_page_runs_min: u64::MAX,
            guard_cmds_min: u64::MAX,
            ..Default::default()
        };
        for frame in 0..FRAMES {
            state.step(dt);
            let label = format!("room{room:03} {name}");
            trace(&state, &mut fb, &mut list, &label, frame, &mut agg);
        }
        println!(
            "#room room{room:03} {name:<12} frames={} quads/frame={:.1} sprite_quads/frame={:.1} \
             fills/frame={:.1} outlines/frame={:.1} page_runs/frame={:.1} runs/frame={:.1} \
             in_view_quads/frame={:.1} in_view_page_runs/frame={:.1} staging_bytes/frame={:.0} \
             quads_min={} quads_max={} guard_cmds/frame={:.1} guard_cmds_min={} guard_cmds_max={} \
             guard_dropped/frame={:.1} gate={} over={} pre_page_runs/frame={:.1} pre_page_runs_min={} \
             pre_page_runs_max={} pages(list)={:?} pages(pre_guard)={:?}",
            agg.frames,
            agg.quads as f64 / agg.frames as f64,
            agg.sprite_quads as f64 / agg.frames as f64,
            agg.fills as f64 / agg.frames as f64,
            agg.outlines as f64 / agg.frames as f64,
            agg.page_runs as f64 / agg.frames as f64,
            agg.runs as f64 / agg.frames as f64,
            agg.in_view_quads as f64 / agg.frames as f64,
            agg.in_view_page_runs as f64 / agg.frames as f64,
            agg.staging_bytes as f64 / agg.frames as f64,
            agg.quads_min, agg.quads_max,
            agg.guard_cmds as f64 / agg.frames as f64,
            agg.guard_cmds_min, agg.guard_cmds_max,
            agg.guard_dropped as f64 / agg.frames as f64,
            if agg.gate_ok { "ok" } else { "not-equal" },
            agg.gate_over,
            agg.pre_page_runs as f64 / agg.frames as f64,
            agg.pre_page_runs_min, agg.pre_page_runs_max,
            agg.pages,
            agg.pre_pages,
        );
        rooms.push(agg);
    }
    println!(
        "#prologue frames={} quads/frame={:.1} page_runs/frame={:.1} runs/frame={:.1} \
         in_view_quads/frame={:.1} staging_bytes/frame={:.0} guard_cmds/frame={:.1} gate={}",
        prologue.frames,
        prologue.quads as f64 / prologue.frames as f64,
        prologue.page_runs as f64 / prologue.frames as f64,
        prologue.runs as f64 / prologue.frames as f64,
        prologue.in_view_quads as f64 / prologue.frames as f64,
        prologue.staging_bytes as f64 / prologue.frames as f64,
        prologue.guard_cmds as f64 / prologue.frames as f64,
        if prologue.gate_ok { "ok" } else { "fewer (alpha-0 commands draw nothing; the test pins the gap)" },
    );
}
