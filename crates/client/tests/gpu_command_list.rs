//! GPU command model — contract `gpu-command-backend.md` slice 1.
//!
//! Three claims have to hold at once, and none of them is implied by the
//! others:
//!
//! 1. **Emitting the command list changes no pixel.** Every frame the
//!    equivalence gate walks is rasterised twice — with and without the list —
//!    and the two framebuffers are compared byte for byte. This is the same
//!    construction `tests/view_culling.rs` uses for the slice-2 guard, and it
//!    is what makes `cargo run --example draw_hash` (no list at all) a valid
//!    baseline for a build that does have the emitters.
//! 2. **The list is exactly what the raster drew.** The emitters sit downstream
//!    of the slice-2 guard and of the alpha test, so the number of sprite quads
//!    in one frame's list can never exceed the guard's kept count, and on the
//!    rooms the contract measured it has to *equal* it: a list that quietly
//!    dropped or duplicated a command would still pass (1).
//! 3. **The shape reconciles with the census.** rm_level17 (room 25) is the
//!    room section 3 measured: 806 commands per frame of which 71 are inside
//!    the 448x252 view rect, 735 rejected; the whole 1424-quad static layer
//!    batches into 55 consecutive page runs and the in-view 71 into 9. The
//!    consumer's own counts are checked against those numbers - the 55 on the
//!    pre-guard stream (which slice 2 removes) and the 9 on the list this slice
//!    produces.
//!
//! The shape of the list itself (depth order, page bucketing that may only
//! merge adjacent runs, a quad that straddles the framebuffer edge, the float[]
//! staging layout) has its own tests at the bottom.
use callys_client::{
    consume_command_list, draw_frame, draw_frame_with_commands, reset_view_cull_stats,
    view_cull_stats, AtlasPage, DepthSlot, Framebuffer, GameState, GpuBody, GpuCommand,
    GpuCommandKind, GpuCommandList, GpuFrameStats, GpuPaint, GpuQuadDst,
};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{DrawCommand, DrawPhase};
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::path::Path;
use std::sync::Arc;

/// draw_hash's canvas: 1136x640 maps the 448x252 view rect onto the whole
/// framebuffer at the original's 2.5357x / 2.5397x.
const W: u32 = 1136;
const H: u32 = 640;
const DT: f32 = 1.0 / 60.0;
/// The rooms draw_hash's equivalence gate walks, rm_level17 (25) included.
const ROOMS: [usize; 8] = [0, 1, 2, 23, 25, 39, 109, 111];
const ROOM_FRAMES: u32 = 40;
const PROLOGUE_FRAMES: u32 = 40;
const LEVEL17: usize = 25;
/// draw_frame's clear colour.
const BG: (u8, u8, u8) = (15, 18, 30);
/// The spike's float[] vertex layout (contract section 2 p4): 4 vertices per
/// quad, 8 floats per vertex.
const FLOATS_PER_VERTEX: usize = 8;
const FLOATS_PER_QUAD: usize = FLOATS_PER_VERTEX * 4;

fn boot() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).expect("GameState::new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).expect("full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state
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

/// One real frame, drawn twice: once with the command list (`list`) and once
/// without it, into two framebuffers that must come out byte-identical.
///
/// Both passes see the same `GameState` and the raster is a pure function of it,
/// so the equality holds on every frame this file walks, not on a sample. The
/// guard's counters are read on the emitting pass, because that is the pass the
/// list has to agree with.
struct FrameOutcome {
    stats: GpuFrameStats,
    guard_kept: u64,
    guard_commands: u64,
    guard_dropped: u64,
}

fn draw_both(
    state: &GameState,
    with_list: &mut Framebuffer,
    without_list: &mut Framebuffer,
    list: &mut GpuCommandList,
    label: &str,
) -> FrameOutcome {
    reset_view_cull_stats();
    draw_frame_with_commands(with_list, state, &state.asset.tpag_items, &state.asset.sprites, list);
    let cull = view_cull_stats();
    let stats = consume_command_list(list, (W, H));

    draw_frame(without_list, state, &state.asset.tpag_items, &state.asset.sprites);

    assert_eq!(
        with_list.pixels, without_list.pixels,
        "{label}: emitting the command list changed the framebuffer \
         ({} commands, {} quads)",
        stats.commands, stats.quads,
    );
    FrameOutcome {
        stats,
        guard_kept: cull.sprite_kept(),
        guard_commands: cull.sprite_commands,
        guard_dropped: cull.sprite_culled,
    }
}

// ---------------------------------------------------------------- claim 1+2 --

/// Emitting the list is pixel-neutral on every frame of the equivalence gate,
/// and the list never holds more sprite quads than the guard kept — with
/// equality on the rooms, which is the evidence that the emitters are wired to
/// the raster's own decisions rather than to a re-derivation of them.
#[test]
fn emitting_changes_no_pixel_and_the_list_matches_the_guard() {
    let mut state = boot();
    let mut with_list = Framebuffer::new(W, H);
    let mut without_list = Framebuffer::new(W, H);
    let mut list = GpuCommandList::new();

    let mut prologue_commands = 0u64;
    let mut prologue_frames = 0u32;
    for phase in ["prologue", "handover"] {
        for frame in 0..PROLOGUE_FRAMES {
            state.step(DT);
            let label = format!("{phase} f{frame:03}");
            let outcome = draw_both(&state, &mut with_list, &mut without_list, &mut list, &label);
            // The prologue's cross-fading sprites reach alpha 0, and the raster
            // draws nothing for those: the list is allowed to be *smaller* than
            // the guard's kept count, never larger. The gap has exactly one
            // legal source, so it is bounded by it here and required to vanish
            // on the frames that have no zero-alpha command.
            let alpha0 = alpha_zero_sprite_commands(&state);
            let gap = outcome.guard_kept.saturating_sub(outcome.stats.counts.sprite as u64);
            assert!(
                gap <= alpha0,
                "{label}: the list lost {gap} kept commands but only {alpha0} zero-alpha \
                 commands exist - the guard's survivors are not reaching the emitter",
            );
            if alpha0 == 0 {
                assert_eq!(
                    outcome.stats.counts.sprite, outcome.guard_kept as usize,
                    "{label}: with no zero-alpha command, the list must be the guard's survivors",
                );
            }
            assert!(
                outcome.stats.counts.sprite <= outcome.guard_kept as usize,
                "{label}: the list holds more sprite quads ({}) than the guard kept ({}) - \
                 the emitter is not downstream of the guard",
                outcome.stats.counts.sprite, outcome.guard_kept,
            );
            prologue_commands += outcome.guard_commands;
            prologue_frames += 1;
        }
        // Match draw_hash: the tap is between the two 40-frame phases, not
        // after the very first boot frame.
        if phase == "prologue" {
            state.input.tap = true;
            state.step(DT);
            state.input.tap = false;
        }
    }
    assert!(
        prologue_commands > 0,
        "the prologue must walk sprite commands for the guard to have decided anything",
    );
    let _ = prologue_frames;

    println!(
        "{:>18} {:>8} {:>8} {:>8} {:>9} {:>8} {:>8} {:>9} {:>9}",
        "room", "cmds/f", "quads/f", "fills/f", "in-view/f", "page_runs", "runs/f", "guard_kept", "gate"
    );
    let mut level17: Option<FrameOutcome> = None;
    for room in ROOMS {
        let name = state.asset.rooms[room].name.clone();
        state
            .restore_ir_snapshot(&save_for(room))
            .unwrap_or_else(|e| panic!("restore room{room} {name}: {e}"));
        let mut quads = 0u64;
        let mut fills = 0u64;
        let mut commands = 0u64;
        let mut in_view = 0u64;
        let mut page_runs = 0u64;
        let mut runs = 0u64;
        let mut kept = 0u64;
        for frame in 0..ROOM_FRAMES {
            state.step(DT);
            let label = format!("room{room:03} {name} f{frame:03}");
            let outcome = draw_both(&state, &mut with_list, &mut without_list, &mut list, &label);
            // The rooms are static + a moving camera: every command the guard
            // kept is a command the raster drew, so the list's sprite quads are
            // exactly the guarded stream.
            assert_eq!(
                outcome.stats.counts.sprite, outcome.guard_kept as usize,
                "{label}: list sprite quads {} != guard kept {} - a kept command must \
                 appear in the list exactly once",
                outcome.stats.counts.sprite, outcome.guard_kept,
            );
            assert_eq!(
                outcome.stats.quads,
                outcome.stats.counts.sprite
                    + outcome.stats.counts.tile
                    + outcome.stats.counts.background
                    + outcome.stats.counts.glyph,
                "{label}: every non-fill command must be a quad",
            );
            assert_eq!(
                outcome.stats.staging.len(),
                outcome.stats.quads * FLOATS_PER_QUAD,
                "{label}: staging must hold 8 floats per vertex, 4 vertices per quad",
            );
            quads += outcome.stats.quads as u64;
            fills += outcome.stats.fills as u64;
            commands += outcome.stats.commands as u64;
            in_view += outcome.stats.in_view_quads as u64;
            page_runs += outcome.stats.page_runs as u64;
            runs += outcome.stats.draw_calls() as u64;
            kept += outcome.guard_kept;
            if room == LEVEL17 {
                level17 = Some(outcome);
            }
        }
        let f = ROOM_FRAMES as f64;
        println!(
            "{:>18} {:>8.1} {:>8.1} {:>8.1} {:>9.1} {:>8.1} {:>8.1} {:>9.1} {:>9}",
            format!("room{room:03} {name}"),
            commands as f64 / f,
            quads as f64 / f,
            fills as f64 / f,
            in_view as f64 / f,
            page_runs as f64 / f,
            runs as f64 / f,
            kept as f64 / f,
            "ok",
        );
    }
    assert!(level17.is_some(), "rm_level17 must have been walked");
}

// ------------------------------------------------------------------ claim 3 --

/// Sprite commands in the current queue whose alpha is 0: the raster draws
/// nothing for them (`draw_ir_sprite` returns before the blit), so they are the
/// only legal reason for a kept command to be missing from the list.
fn alpha_zero_sprite_commands(state: &GameState) -> u64 {
    let Some(scene) = state.scene.as_ref() else { return 0 };
    scene
        .ordered_draw_commands()
        .iter()
        .filter(|e| matches!(e.queue, callys_core::ir_scene::DrawQueue::Sprite(_)))
        .filter(|e| match e.queue {
            callys_core::ir_scene::DrawQueue::Sprite(i) => scene.draws[i].alpha <= 0.0,
            _ => false,
        })
        .count() as u64
}

/// The atlas page a sprite command samples, resolved the way the sprite emitter
/// resolves it. Used here to measure the *pre-guard* stream — the census'
/// subject — because the contract's 55 page runs was measured over the whole
/// static layer (1424 quads), not over a culled frame's survivors.
fn page_of_sprite(state: &GameState, cmd: &DrawCommand) -> Option<usize> {
    let sprite = state.asset.sprites.get(&(cmd.sprite as usize))?;
    if sprite.tpag_indices.is_empty() {
        return None;
    }
    let frame = cmd.frame.max(0.0) as usize % sprite.tpag_indices.len();
    let page = state.asset.tpag_items.get(&(sprite.tpag_indices[frame] as usize))?;
    Some(page.tex_id as usize)
}

/// rm_level17 against contract section 3, on real frames.
///
/// The two page-run numbers answer two different questions, and this test keeps
/// them apart: **9** is the in-view set the command list carries (the list is
/// downstream of the guard), **55** is the whole static layer batching into
/// consecutive runs — measurable on the pre-guard stream, which the contract
/// itself measures with the census. Nothing here asserts the exact census
/// values (the live stream's size varies frame to frame); the bounds are wide
/// enough for that drift and tight enough that a list which started sorting by
/// page, or a guard that stopped firing, fails.
#[test]
fn rm_level17_reconciles_with_the_contract() {
    let mut state = boot();
    state
        .restore_ir_snapshot(&save_for(LEVEL17))
        .expect("restore rm_level17");
    assert_eq!(state.asset.rooms[LEVEL17].name, "rm_level17");
    let mut fb = Framebuffer::new(W, H);
    let mut other = Framebuffer::new(W, H);
    let mut list = GpuCommandList::new();

    let mut commands = 0u64;
    let mut quads = 0u64;
    let mut sprite_quads = 0u64;
    let mut page_runs = 0u64;
    let mut in_view_quads = 0u64;
    let mut in_view_page_runs = 0u64;
    let mut staging_bytes = 0u64;
    let mut outlines = 0u64;
    let mut page3 = 0u64;
    let mut page_runs_max = 0u64;
    // Two regimes in one 40-frame run, split by the queue's own size - the
    // measurement, not a frame index: the frames right after the restore carry
    // the room's whole static layer, the settled ones do not.
    let mut load_frames = 0u32;
    let mut load_stream = 0u64;
    let mut load_kept = 0u64;
    let mut load_quads_sum = 0u64;
    let mut load_pre_runs_min = u64::MAX;
    let mut load_pre_runs_max = 0u64;
    let mut steady_frames = 0u32;
    let mut steady_stream = 0u64;
    let mut steady_kept = 0u64;
    let mut steady_quads = 0u64;
    let mut steady_pre_runs_min = u64::MAX;
    let mut steady_pre_runs_max = 0u64;

    for frame in 0..ROOM_FRAMES {
        state.step(DT);
        let label = format!("rm_level17 f{frame:03}");
        let outcome = draw_both(&state, &mut fb, &mut other, &mut list, &label);
        let s = &outcome.stats;
        page_runs_max = page_runs_max.max(s.page_runs as u64);
        // The float[] staging is 128 B per quad (section 2: 103,168 B for 806
        // quads), on every frame, not on average.
        assert_eq!(s.staging_bytes, s.quads * FLOATS_PER_QUAD * 4, "{label}: staging size");
        assert_eq!(s.vertices, s.quads * 4, "{label}: four vertices per quad");
        assert_eq!(
            s.counts.sprite, outcome.guard_kept as usize,
            "{label}: the list must be the guarded stream's survivors",
        );
        for cmd in list.commands() {
            if let GpuBody::Quad { page, .. } = cmd.body {
                if cmd.kind == GpuCommandKind::Sprite && page.tex == 3 {
                    page3 += 1;
                }
            }
        }

        // The pre-guard sprite stream: the census' static layer, measured with
        // the live pages rather than the census' own.
        let (mut pre_runs, mut pre_commands) = (0u64, 0u64);
        let mut last: Option<Option<usize>> = None;
        if let Some(scene) = state.scene.as_ref() {
            for emission in scene.ordered_draw_commands() {
                if let callys_core::ir_scene::DrawQueue::Sprite(i) = emission.queue {
                    pre_commands += 1;
                    let p = page_of_sprite(&state, &scene.draws[i]);
                    if last != Some(p) {
                        pre_runs += 1;
                        last = Some(p);
                    }
                }
            }
        }
        let load = pre_commands >= 1400;
        if load {
            load_frames += 1;
            load_stream += pre_commands as u64;
            load_kept += outcome.guard_kept;
            load_quads_sum += s.quads as u64;
            load_pre_runs_min = load_pre_runs_min.min(pre_runs);
            load_pre_runs_max = load_pre_runs_max.max(pre_runs);
        } else {
            steady_frames += 1;
            steady_stream += pre_commands as u64;
            steady_kept += outcome.guard_kept;
            steady_quads += s.quads as u64;
            steady_pre_runs_min = steady_pre_runs_min.min(pre_runs);
            steady_pre_runs_max = steady_pre_runs_max.max(pre_runs);
        }
        // The regime bounds are read off the two queues themselves, so they say
        // what each regime *is*: the load queue is the room's static layer (the
        // census' 1424 quads, batching into its 55 runs) and the steady queue is
        // the settled ~800-command stream (the census' own live figure, 806).
        if load {
            assert!(
                (50..=60).contains(&pre_runs),
                "f{frame:03}: the load queue ({pre_commands} quads) must batch into ~55 page runs, got {pre_runs}",
            );
            assert!(
                outcome.guard_kept >= 40,
                "f{frame:03}: the load queue must keep a screenful of quads, got {}",
                outcome.guard_kept,
            );
        } else {
            assert!(
                pre_runs <= 20,
                "f{frame:03}: the steady queue is a subset of the layer; its page runs stay below the layer's, got {pre_runs}",
            );
            assert!(
                s.quads <= 160,
                "f{frame:03}: the steady list holds the on-screen quads for a 1136x640 framebuffer, got {}",
                s.quads,
            );
        }
        // Removing commands can merge or keep page runs, never split them: the
        // culled list cannot have more runs than the queue it came from.
        assert!(
            s.page_runs <= pre_runs as usize,
            "f{frame:03}: list page runs {} exceed the queue's {pre_runs} - a cull cannot split a run",
            s.page_runs,
        );

        commands += s.commands as u64;
        quads += s.quads as u64;
        sprite_quads += s.counts.sprite as u64;
        page_runs += s.page_runs as u64;
        in_view_quads += s.in_view_quads as u64;
        in_view_page_runs += s.in_view_page_runs as u64;
        staging_bytes += s.staging_bytes as u64;
        outlines += s.outlines as u64;
    }
    let f = ROOM_FRAMES as f64;
    let mean = |sum: u64, n: u32| sum as f64 / n.max(1) as f64;
    println!(
        "\nrm_level17 (room 25), {ROOM_FRAMES} frames - two regimes, split by the stream's own size\n\
         \x20 census section 3 (static, and its own live figure):\n\
         \x20   806 commands/frame (live), 71 quads in the 448x252 view rect at its centroid camera, 735 rejected\n\
         \x20   1424-quad static layer -> 55 page runs; in-view 71 -> 9\n\
         \x20 whole run            : {} commands/frame, {:.1} list quads/frame ({:.1} sprite), {:.1} page runs/frame\n\
         \x20                        {:.1} quads in the framebuffer/frame, {:.1} B float[] staging/frame ({:.0} B/quad)\n\
         \x20 load regime   (n={:>2}) : stream {:>7.1}/frame, kept {:>6.1}, list quads {:>6.1}, pre-guard page runs {}..{}\n\
         \x20 steady regime (n={:>2}) : stream {:>7.1}/frame, kept {:>6.1}, list quads {:>6.1}, pre-guard page runs {}..{}\n\
         \x20 page-3 share of the list's sprite quads: {:.3}\n",
        commands as f64 / f,
        quads as f64 / f,
        sprite_quads as f64 / f,
        page_runs as f64 / f,
        in_view_quads as f64 / f,
        staging_bytes as f64 / f,
        staging_bytes as f64 / quads.max(1) as f64,
        load_frames,
        mean(load_stream, load_frames),
        mean(load_kept, load_frames),
        mean(load_quads_sum, load_frames),
        load_pre_runs_min,
        load_pre_runs_max,
        steady_frames,
        mean(steady_stream, steady_frames),
        mean(steady_kept, steady_frames),
        mean(steady_quads, steady_frames),
        steady_pre_runs_min,
        steady_pre_runs_max,
        page3 as f64 / sprite_quads.max(1) as f64,
    );

    // Both regimes are real and both carry the contract's numbers:
    //  * the *load* frames (the room's whole static layer in the queue) are the
    //    live counterpart of the census' 1424-quad layer, and batch into the
    //    census' 55 page runs;
    //  * the *steady* frames carry the census' own live figure, 806
    //    commands/frame.
    // Splitting by the stream's size instead of by frame index is what keeps
    // this explainable: a 40-frame mean over both regimes answers neither
    // question, and the census' static numbers are a snapshot, not a golden for
    // a dynamic frame.
    assert!(
        load_frames > 0 && steady_frames > 0,
        "both regimes must appear ({load_frames} load / {steady_frames} steady)",
    );
    assert!(
        (50..=60).contains(&load_pre_runs_max),
        "the load regime's static layer must batch into the census' 55 page runs, got {}",
        load_pre_runs_max,
    );
    assert!(
        mean(load_stream, load_frames) >= 1400.0,
        "the load regime must carry the static layer (~1424 quads), got {:.1}",
        mean(load_stream, load_frames),
    );
    assert!(
        steady_pre_runs_max <= 20,
        "the steady stream is the settled ~800-command subset; its page runs stay far below the layer's, got {}",
        steady_pre_runs_max,
    );
    let steady_stream_mean = mean(steady_stream, steady_frames);
    assert!(
        (780.0..=860.0).contains(&steady_stream_mean),
        "the census' live figure is 806 commands/frame; the steady stream must sit on it, got {:.1}",
        steady_stream_mean,
    );
    // The list is downstream of the guard, so what it carries is the *on-screen*
    // set - the census' 9 in-view page runs, not the layer's 55.
    let runs_per_frame = page_runs as f64 / f;
    assert!(
        (8.0..=12.0).contains(&runs_per_frame),
        "the list is the in-view set, whose census page_runs is 9; got {runs_per_frame:.1}",
    );
    assert!(
        page_runs_max <= 12,
        "no frame may carry more page runs than the in-view set has (9, census); got {page_runs_max}",
    );
    // Fills and outlines are the healthbars plus (on some frames) the 32x32
    // placeholder; a list of quads only would mean the emitter dropped ink.
    assert!(
        outlines > 0,
        "the healthbar outline must be modelled ({outlines} outlines over {ROOM_FRAMES} frames)",
    );
    assert!(
        page3 as f64 / sprite_quads.max(1) as f64 > 0.5,
        "rm_level17's visible sprites are page-3 dominated (census: 1378 of 1424 of the layer)",
    );
    assert!(
        in_view_page_runs <= page_runs,
        "the in-view subsequence cannot have more page runs than the list",
    );
}

// ------------------------------------------------------------- list shape ----

fn slot(depth: f64, emit_order: usize) -> DepthSlot {
    DepthSlot { phase: DrawPhase::Room, depth, emit_order }
}

fn page(tex: usize) -> AtlasPage {
    AtlasPage { tex, rect: (0, 0, 64, 64), atlas: (1024, 1024) }
}

fn rect_quad(slot: DepthSlot, tex: usize, _x: i32, paint: GpuPaint) -> (DepthSlot, AtlasPage, GpuPaint) {
    (slot, page(tex), paint)
}

/// Page bucketing may only merge commands that were already adjacent: two
/// quads of the same page with a different page between them are three runs, and
/// a consumer that sorted by page (the census' rejected alternative, contract
/// section 3) would report one or two. The run list also has to cover the
/// command list in order without gaps - that is what "no global sort" means.
#[test]
fn page_bucketing_only_merges_adjacent_runs() {
    let mut list = GpuCommandList::new();
    let paint = GpuPaint::default();
    // A, B, A, A, fogged A, B
    for (tex, flood) in [(1usize, false), (2, false), (1, false), (1, false), (1, true), (2, false)] {
        let (s, p, mut paint) = rect_quad(slot(0.0, 0), tex, 0, paint);
        paint.flood = flood.then_some((0, 0, 0));
        list.emit_sprite(s, p, (0, 0, 64, 64), GpuQuadDst::Rect { x: 0, y: 0, w: 64, h: 64, flip_x: false }, paint);
    }
    let stats = consume_command_list(&list, (W, H));

    // Consecutive page runs: 1 | 2 | 1,1,1 | 2 = four page stretches, even
    // though the fogged quad in the middle would need its own state.
    assert_eq!(stats.page_runs, 4, "page runs are consecutive, not sorted");
    // The batch key is stricter: fog needs its own shader state.
    assert_eq!(stats.draw_calls(), 5, "a fog-state change must break a batch run");
    let runs: Vec<(GpuCommandKind, Option<usize>, usize, usize)> = stats
        .runs
        .iter()
        .map(|r| (r.kind, r.tex, r.first, r.len))
        .collect();
    assert_eq!(
        runs,
        vec![
            (GpuCommandKind::Sprite, Some(1), 0, 1),
            (GpuCommandKind::Sprite, Some(2), 1, 1),
            (GpuCommandKind::Sprite, Some(1), 2, 2),
            (GpuCommandKind::Sprite, Some(1), 4, 1),
            (GpuCommandKind::Sprite, Some(2), 5, 1),
        ],
        "runs must tile the list in painter order",
    );
    // Adjacent same-page quads *must* merge, or the batcher buys nothing.
    let mut adjacent = GpuCommandList::new();
    for tex in [1usize, 1, 1] {
        let (s, p, paint) = rect_quad(slot(0.0, 0), tex, 0, GpuPaint::default());
        adjacent.emit_sprite(s, p, (0, 0, 64, 64), GpuQuadDst::Rect { x: 0, y: 0, w: 64, h: 64, flip_x: false }, paint);
    }
    let stats = consume_command_list(&adjacent, (W, H));
    assert_eq!(stats.page_runs, 1);
    assert_eq!(stats.draw_calls(), 1);
    assert_eq!(stats.runs[0].len, 3);
    // ... and a page-sorted list would report 2 runs for A,B,A, which is
    // exactly the reordering the contract forbids.
    let mut ab = GpuCommandList::new();
    for tex in [1usize, 2, 1] {
        let (s, p, paint) = rect_quad(slot(0.0, 0), tex, 0, GpuPaint::default());
        ab.emit_sprite(s, p, (0, 0, 64, 64), GpuQuadDst::Rect { x: 0, y: 0, w: 64, h: 64, flip_x: false }, paint);
    }
    let stats = consume_command_list(&ab, (W, H));
    assert_eq!(stats.page_runs, 3, "A,B,A is three runs - the list may not be reordered");
}

/// The depth slot a command carries is the slot of the emission the raster
/// consumed, and the list keeps the stream's order: read off the real frames,
/// where the stream is sorted by (phase, descending object depth).
#[test]
fn depth_slots_and_order_are_the_streams_own() {
    let mut state = boot();
    state
        .restore_ir_snapshot(&save_for(LEVEL17))
        .expect("restore rm_level17");
    let mut fb = Framebuffer::new(W, H);
    let mut list = GpuCommandList::new();
    let mut checked = 0usize;

    for frame in 0..ROOM_FRAMES {
        state.step(DT);
        draw_frame_with_commands(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites, &mut list);
        let scene = state.scene.as_ref().expect("scene");
        let emissions = scene.ordered_draw_commands();

        // The stream's sprite slots, in stream order.
        let stream: Vec<DepthSlot> = emissions
            .iter()
            .filter(|e| matches!(e.queue, callys_core::ir_scene::DrawQueue::Sprite(_)))
            .map(|e| DepthSlot { phase: e.phase, depth: e.depth, emit_order: e.emit_order })
            .collect();
        let emitted: Vec<DepthSlot> = list
            .commands()
            .iter()
            .filter(|c| c.kind == GpuCommandKind::Sprite)
            .map(|c| c.slot)
            .collect();
        // A subsequence: the list drops what the guard rejected, and never
        // reorders or invents a slot.
        assert!(
            is_subsequence(&emitted, &stream),
            "f{frame:03}: the list's depth slots are not the stream's, in order \
             ({} emitted of {} streamed)",
            emitted.len(),
            stream.len(),
        );

        // Phase is a barrier: no Gui command may precede a Room one.
        let mut seen_gui = false;
        let mut last_depth = f64::INFINITY;
        let mut phase = DrawPhase::Room;
        for cmd in list.commands() {
            if cmd.slot.phase != phase {
                assert_eq!(cmd.slot.phase, DrawPhase::Gui, "f{frame:03}: phase went Gui -> Room");
                seen_gui = true;
                phase = DrawPhase::Gui;
                last_depth = f64::INFINITY;
            }
            if cmd.kind == GpuCommandKind::Sprite {
                // Painter order inside a phase: descending object depth.
                assert!(
                    cmd.slot.depth <= last_depth,
                    "f{frame:03}: depth rose from {last_depth} to {} inside one phase",
                    cmd.slot.depth,
                );
                last_depth = cmd.slot.depth;
            }
        }
        let _ = seen_gui;
        checked += 1;
    }
    assert_eq!(checked, ROOM_FRAMES as usize);
}

fn is_subsequence<T: PartialEq>(needle: &[T], haystack: &[T]) -> bool {
    let mut it = haystack.iter();
    needle.iter().all(|n| it.any(|h| h == n))
}

/// A quad that straddles the framebuffer edge is a command the raster really
/// draws, so it has to be in the list, counted as in view, and staged with its
/// full unclipped box (slice 2's argument: "clipped but visible" is ink, and
/// only the *unobservable* command may be dropped). A command that cannot put a
/// pixel anywhere is rejected before the emitter and appears in neither.
#[test]
fn a_quad_straddling_the_edge_is_kept_and_staged_unclipped() {
    let mut state = boot();
    state.retire_prologue();
    state.scene.as_mut().unwrap().view_visible = [false; 8];
    let (sprite_id, cw, ch, ox, oy) = pick_sprite(&state);
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    let at = |frame_left: f64, frame_top: f64| (cam_x + frame_left - ox, cam_y + frame_top - oy);

    // (a) Half the canvas off the left edge: kept, counted in view, and its
    //     staged corners reach outside the framebuffer.
    let (x, y) = at(-(cw as f64) / 2.0, 200.0);
    only(&mut state, command(sprite_id, x, y, (1.0, 1.0)));
    let mut fb = Framebuffer::new(W, H);
    let mut list = GpuCommandList::new();
    draw_frame_with_commands(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites, &mut list);
    let stats = consume_command_list(&list, (W, H));
    assert_eq!(stats.counts.sprite, 1, "a clipped-but-visible quad must be emitted");
    assert_eq!(stats.in_view_quads, 1, "and counted as in view");
    let (min_x, _, _, _) = quad_bounds(&list, 0);
    assert!(min_x < 0.0, "the staged box must be the unclipped one, got min_x {min_x}");
    assert!(!all_background(&fb), "and the raster must have drawn it");

    // (b) Entirely off screen: rejected by the guard, so the list is empty and
    //     so is the frame.
    let (x, y) = at(-10_000.0, 200.0);
    only(&mut state, command(sprite_id, x, y, (1.0, 1.0)));
    draw_frame_with_commands(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites, &mut list);
    let stats = consume_command_list(&list, (W, H));
    assert_eq!(stats.commands, 0, "an unobservable command must not reach the list");
    assert!(all_background(&fb));
    let _ = (cw, ch, oy);
}

/// The staging is the spike's float[] layout (contract section 2 p4), checked
/// on a command whose geometry is known by hand: 4 vertices per quad, 8 floats
/// per vertex, corners in the raster's order (tl, tr, bl, br) and uv normalized
/// by the atlas texture size.
#[test]
fn staging_is_the_spikes_float_layout() {
    let mut list = GpuCommandList::new();
    list.emit_tile(
        slot(-1.0, 7),
        AtlasPage { tex: 3, rect: (0, 0, 100, 50), atlas: (100, 50) },
        (10, 20, 5, 5),
        GpuQuadDst::Rect { x: 4, y: 8, w: 8, h: 16, flip_x: false },
    );
    let stats = consume_command_list(&list, (W, H));
    assert_eq!(stats.quads, 1);
    assert_eq!(stats.vertices, 4);
    assert_eq!(stats.staging_floats, FLOATS_PER_QUAD);
    assert_eq!(stats.staging_bytes, FLOATS_PER_QUAD * 4);
    assert_eq!(stats.counts.tile, 1);

    let v = |i: usize| -> [f32; FLOATS_PER_VERTEX] {
        let s = &stats.staging[i * FLOATS_PER_VERTEX..(i + 1) * FLOATS_PER_VERTEX];
        [s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]]
    };
    // tl, tr, bl, br with uv u0=0.1,u1=0.15, v0=0.4,v1=0.5 (atlas 100x50).
    assert_eq!(v(0), [4.0, 8.0, 0.10, 0.40, 1.0, 1.0, 1.0, 1.0]);
    assert_eq!(v(1), [12.0, 8.0, 0.15, 0.40, 1.0, 1.0, 1.0, 1.0]);
    assert_eq!(v(2), [4.0, 24.0, 0.10, 0.50, 1.0, 1.0, 1.0, 1.0]);
    assert_eq!(v(3), [12.0, 24.0, 0.15, 0.50, 1.0, 1.0, 1.0, 1.0]);

    // A fogged quad stages the fog colour, not the blend (the raster replaces
    // the sampled colour with it).
    let mut fogged = GpuCommandList::new();
    fogged.emit_sprite(
        slot(0.0, 0),
        AtlasPage { tex: 1, rect: (0, 0, 100, 50), atlas: (100, 50) },
        (0, 0, 50, 50),
        GpuQuadDst::Rect { x: 0, y: 0, w: 50, h: 50, flip_x: false },
        GpuPaint { alpha: 0.5, blend: (255, 255, 255), flood: Some((255, 0, 0)) },
    );
    let stats = consume_command_list(&fogged, (W, H));
    assert_eq!(&stats.staging[4..8], &[1.0, 0.0, 0.0, 0.5]);
    // ... and a glyph quad carries the same layout, with the glyph's box inside
    // the font page as its source and the scaled pen box as its destination
    // (contract slice 1: the glyph emitter mirrors `blit_glyph_gm`).
    let mut glyphs = GpuCommandList::new();
    glyphs.emit_glyph(
        slot(0.0, 3),
        AtlasPage { tex: 2, rect: (100, 200, 40, 20), atlas: (512, 256) },
        (110, 220, 4, 6),
        GpuQuadDst::Rect { x: 50, y: 60, w: 8, h: 12, flip_x: false },
        GpuPaint { alpha: 0.25, blend: (10, 20, 30), flood: None },
    );
    let gs = consume_command_list(&glyphs, (W, H));
    assert_eq!(gs.counts.glyph, 1);
    assert_eq!(gs.quads, 1);
    assert_eq!(gs.staging_floats, FLOATS_PER_QUAD);
    let gv = |i: usize| -> [f32; FLOATS_PER_VERTEX] {
        let s = &gs.staging[i * FLOATS_PER_VERTEX..(i + 1) * FLOATS_PER_VERTEX];
        [s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]]
    };
    assert_eq!(gv(0), [50.0, 60.0, 110.0 / 512.0, 220.0 / 256.0, 10.0 / 255.0, 20.0 / 255.0, 30.0 / 255.0, 0.25]);
    assert_eq!(gv(3), [58.0, 72.0, 114.0 / 512.0, 226.0 / 256.0, 10.0 / 255.0, 20.0 / 255.0, 30.0 / 255.0, 0.25]);
}

// ------------------------------------------------- model sufficiency --------

/// The list has to carry every input the CPU sampler uses, and invent nothing:
/// each command's fields are re-derived *from the scene* here (frame page rect,
/// SPRT canvas/origin, the original's mirror sign, rotation, blend, fog, alpha)
/// and compared with what the emitter recorded. Slice 4 can therefore rebuild
/// the raster from the list alone.
///
/// Mirroring is `image_xscale = -1`, i.e. a negative scale - there is no flip
/// flag on the sprite path - and the frame's atlas rect (`src`) is the SPRT
/// frame page, which together with the canvas gives the sampler's `du`/`dv`.
#[test]
fn the_model_carries_every_sampling_input() {
    let mut state = boot();
    state.retire_prologue();
    state.scene.as_mut().unwrap().view_visible = [false; 8];
    let (sprite_id, _, _, _, _) = pick_sprite(&state);
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    let scale = (W as f32 / 960.0, H as f32 / 540.0);
    // Four sprites with the sampler's awkward cases, all well inside the frame.
    let mut plain = command(sprite_id, cam_x + 100.0, cam_y + 80.0, (1.0, 1.0));
    let mut mirrored = command(sprite_id, cam_x + 200.0, cam_y + 80.0, (-1.0, 1.0));
    let mut rotated = command(sprite_id, cam_x + 300.0, cam_y + 80.0, (1.0, 1.0));
    rotated.rotation = 30.0;
    let mut fogged = command(sprite_id, cam_x + 400.0, cam_y + 80.0, (1.0, 1.0));
    fogged.color = 0x00FF0000; // GM colour, low byte red
    fogged.alpha = 0.5;
    fogged.fog = true;
    plain.alpha = 0.75;
    mirrored.color = 0x0000FF00;
    let bg_cmd = background(&state, cam_x, cam_y, 0.75);
    let draws = vec![plain.clone(), mirrored.clone(), rotated.clone(), fogged.clone()];
    only_frame(&mut state, draws.clone(), Some(bg_cmd.clone()));

    let mut fb = Framebuffer::new(W, H);
    let mut list = GpuCommandList::new();
    draw_frame_with_commands(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites, &mut list);

    // Re-derive what the raster is handed for each command, from the scene.
    let sprite = state.asset.sprites.get(&(sprite_id as usize)).unwrap();
    let frame = 0usize;
    let page_item = state.asset.tpag_items.get(&(sprite.tpag_indices[frame] as usize)).unwrap();
    let atlas = state.atlases.get(page_item.tex_id as usize).unwrap();
    let src = (page_item.x as u32, page_item.y as u32, page_item.w as u32, page_item.h as u32);
    let expect_sprite = |cmd: &DrawCommand| -> String {
        let anchor = ((cmd.x - cam_x) * scale.0 as f64, (cmd.y - cam_y) * scale.1 as f64);
        let scale_eff = (cmd.scale_x * scale.0 as f64, cmd.scale_y * scale.1 as f64);
        let blend = (
            (cmd.color as i64 & 0xFF) as u8,
            ((cmd.color as i64 >> 8) & 0xFF) as u8,
            ((cmd.color as i64 >> 16) & 0xFF) as u8,
        );
        format!(
            "sprite tex={} src={:?} atlas={:?} anchor={:?} canvas={:?} origin={:?} scale={:?} rot={:?} \
             alpha={:?} blend={:?} flood={:?}",
            page_item.tex_id,
            src,
            (atlas.width(), atlas.height()),
            anchor,
            (sprite.width, sprite.height),
            (sprite.origin_x, sprite.origin_y),
            scale_eff,
            cmd.rotation,
            (cmd.alpha as f32).clamp(0.0, 1.0),
            blend,
            cmd.fog.then_some(blend),
        )
    };
    let expect_bg = {
        let bg = state.asset.backgrounds.get(&(bg_cmd.background as usize)).unwrap();
        let page = state.asset.tpag_items.get(&bg.tpag_ptr).unwrap();
        let atlas = state.atlases.get(page.tex_id as usize).unwrap();
        format!(
            "bg tex={} src={:?} atlas={:?} rect={:?} alpha={:?} blend=(255, 255, 255) flood=None",
            page.tex_id,
            (page.x as u32, page.y as u32, page.w as u32, page.h as u32),
            (atlas.width(), atlas.height()),
            (
                (((bg_cmd.x - cam_x) as f32 * scale.0) as i32),
                (((bg_cmd.y - cam_y) as f32 * scale.1) as i32),
                ((page.w as f64 * bg_cmd.scale_x) as f32 * scale.0).max(1.0) as u32,
                ((page.h as f64 * bg_cmd.scale_y) as f32 * scale.1).max(1.0) as u32,
            ),
            (bg_cmd.alpha as f32).clamp(0.0, 1.0),
        )
    };

    let render = |cmd: &GpuCommand| -> String {
        match cmd.body {
            GpuBody::Quad { page, src, dst, paint } => match dst {
                GpuQuadDst::Sprite { anchor, canvas, origin, scale, rotation_deg } => {
                    assert_eq!(cmd.kind, GpuCommandKind::Sprite, "only sprites anchor on an origin");
                    format!(
                        "sprite tex={} src={:?} atlas={:?} anchor={:?} canvas={:?} origin={:?} \
                         scale={:?} rot={:?} alpha={:?} blend={:?} flood={:?}",
                        page.tex, src, page.atlas, anchor, canvas, origin, scale, rotation_deg,
                        paint.alpha, paint.blend, paint.flood,
                    )
                }
                GpuQuadDst::Rect { x, y, w, h, .. } => {
                    assert_eq!(cmd.kind, GpuCommandKind::Background, "rect quads are backgrounds/tiles");
                    format!(
                        "bg tex={} src={:?} atlas={:?} rect={:?} alpha={:?} blend={:?} flood={:?}",
                        page.tex, src, page.atlas, (x, y, w, h), paint.alpha, paint.blend, paint.flood,
                    )
                }
            },
            other => panic!("expected a quad, got {other:?}"),
        }
    };

    let mut got: Vec<String> = Vec::new();
    let mut got_bg: Vec<String> = Vec::new();
    for cmd in list.commands() {
        match cmd.kind {
            GpuCommandKind::Sprite => got.push(render(cmd)),
            GpuCommandKind::Background => got_bg.push(render(cmd)),
            other => panic!("unexpected kind {other:?}"),
        }
    }
    assert_eq!(got.len(), draws.len(), "one quad per drawn sprite command");
    assert_eq!(got_bg.len(), 1, "the background command must be in the list");
    let mut expect: Vec<String> = draws.iter().map(expect_sprite).collect();
    expect.sort();
    got.sort();
    assert_eq!(got, expect, "the list must carry exactly the sampler's inputs");
    assert_eq!(got_bg[0], expect_bg, "the background's colour stays unapplied (raster ignores it)");

    // Reconstructing the anchor's texel from the command alone must land inside
    // the frame page - i.e. `du`/`dv` and the inverse transform are all present.
    let s = consume_command_list(&list, (W, H));
    let (page_rect, src_rect, anchor, canvas, origin, scale_eff) = match list
        .commands()
        .iter()
        .find(|c| c.kind == GpuCommandKind::Sprite)
        .map(|c| c.body)
        .unwrap()
    {
        GpuBody::Quad { page, src, dst, .. } => match dst {
            GpuQuadDst::Sprite { anchor, canvas, origin, scale, .. } => {
                (page.rect, src, anchor, canvas, origin, scale)
            }
            other => panic!("{other:?}"),
        },
        other => panic!("{other:?}"),
    };
    let _ = page_rect;
    let du = src_rect.2 as f64 / canvas.0 as f64;
    let dv = src_rect.3 as f64 / canvas.1 as f64;
    // Screen pixel at the canvas centre of the first (unrotated) command.
    let s_cmd = &draws[0];
    let anchor0 = ((s_cmd.x - cam_x) * scale.0 as f64, (s_cmd.y - cam_y) * scale.1 as f64);
    let px = (anchor0.0 + (canvas.0 as f64 / 2.0 - origin.0 as f64 + origin.0 as f64) * scale_eff.0,
              anchor0.1 + (canvas.1 as f64 / 2.0 - origin.1 as f64 + origin.1 as f64) * scale_eff.1);
    let u = (px.0 + 0.5 - anchor0.0) / scale_eff.0 + origin.0 as f64;
    let v = (px.1 + 0.5 - anchor0.1) / scale_eff.1 + origin.1 as f64;
    let su = src_rect.0 as f64 + u * du;
    let sv = src_rect.1 as f64 + v * dv;
    assert!(
        su >= src_rect.0 as f64 && su < (src_rect.0 + src_rect.2) as f64,
        "the reconstructed texel column {su} must lie inside the frame page {:?}",
        src_rect,
    );
    assert!(
        sv >= src_rect.1 as f64 && sv < (src_rect.1 + src_rect.3) as f64,
        "the reconstructed texel row {sv} must lie inside the frame page {:?}",
        src_rect,
    );
    assert!(stats_has_sprite(&s), "the quad must be in view for this geometry");
    let _ = anchor;
}

fn stats_has_sprite(s: &GpuFrameStats) -> bool {
    s.counts.sprite >= 1
}

// ---------------------------------------------------------------- fixtures ---

fn quad_bounds(list: &GpuCommandList, index: usize) -> (f32, f32, f32, f32) {
    match list.commands()[index].body {
        GpuBody::Quad { dst, .. } => dst.bounds(),
        _ => panic!("command {index} is not a quad"),
    }
}

fn command(sprite: i32, x: f64, y: f64, scale: (f64, f64)) -> DrawCommand {
    DrawCommand {
        code: 0, offset: 0, instance: -1, view: 0,
        sprite, frame: 0.0, x, y,
        scale_x: scale.0, scale_y: scale.1,
        rotation: 0.0, color: 16777215, alpha: 1.0, fog: false,
    }
}

/// Replace every queue with this one command, so any non-background pixel in the
/// frame belongs to it.
fn only(state: &mut GameState, cmd: DrawCommand) {
    only_frame(state, vec![cmd], None);
}

/// The same, with several sprite commands and an optional background — the
/// frame's whole ink, so the list can be compared against it field by field.
fn only_frame(
    state: &mut GameState,
    draws: Vec<DrawCommand>,
    background: Option<callys_core::ir_scene::BackgroundCommand>,
) {
    let s = state.scene.as_mut().unwrap();
    s.draws = draws;
    s.backgrounds = background.into_iter().collect();
    s.room_tiles.clear();
    s.texts.clear();
    s.healthbars.clear();
    s.particles.clear();
}

/// A real background whose TPAG page and atlas resolve, placed at the camera so
/// its quad is on screen.
fn background(state: &GameState, cam_x: f64, cam_y: f64, alpha: f64) -> callys_core::ir_scene::BackgroundCommand {
    let mut ids: Vec<i32> = state.asset.backgrounds.keys().map(|k| *k as i32).collect();
    ids.sort();
    for id in ids {
        let bg = state.asset.backgrounds.get(&(id as usize)).unwrap();
        if let Some(page) = state.asset.tpag_items.get(&bg.tpag_ptr) {
            if state.atlases.get(page.tex_id as usize).is_some() {
                return callys_core::ir_scene::BackgroundCommand {
                    code: 0,
                    offset: 0,
                    instance: -1,
                    view: 0,
                    background: id,
                    x: cam_x,
                    y: cam_y,
                    scale_x: 1.0,
                    scale_y: 1.0,
                    rotation: 0.0,
                    color: 0,
                    alpha,
                };
            }
        }
    }
    panic!("no background in the asset resolves to an atlas page");
}

/// A real sprite small enough to place by hand (frame 0 page resolves and its
/// SPRT origin lies inside its own canvas), so the geometry below is predictable
/// from `(width, height, origin)`.
fn pick_sprite(state: &GameState) -> (i32, f64, f64, f64, f64) {
    let mut ids: Vec<i32> = state.asset.sprites.keys().map(|k| *k as i32).collect();
    ids.sort();
    for id in ids {
        let sprite = state.asset.sprites.get(&(id as usize)).unwrap();
        if sprite.tpag_indices.is_empty() || sprite.width < 8 || sprite.height < 8 {
            continue;
        }
        if sprite.width > 128 || sprite.height > 128 {
            continue;
        }
        let (ox, oy) = (sprite.origin_x as f64, sprite.origin_y as f64);
        if ox < 0.0 || oy < 0.0 || ox > sprite.width as f64 || oy > sprite.height as f64 {
            continue;
        }
        if state.asset.tpag_items.contains_key(&(sprite.tpag_indices[0] as usize)) {
            return (id, sprite.width as f64, sprite.height as f64, ox, oy);
        }
    }
    panic!("no sprite in the asset satisfies the fixture requirements");
}

fn px(fb: &Framebuffer, x: i32, y: i32) -> (u8, u8, u8) {
    let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
    (fb.pixels[i + 2], fb.pixels[i + 1], fb.pixels[i])
}

fn all_background(fb: &Framebuffer) -> bool {
    (0..fb.height as i32).all(|y| (0..fb.width as i32).all(|x| px(fb, x, y) == BG))
}
