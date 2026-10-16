//! Render-backend A/B — contract `gpu-command-backend.md` slice 7.
//!
//! The switch exists so that "which render path" is one environment variable (or
//! one call) apart. Two measurements back that up, both on the draw_hash rooms:
//!
//! * `resolving_the_backend_is_not_a_per_frame_getenv` — what the switch itself
//!   costs per resolution, with a per-frame `std::env::var` as the reference it
//!   had to beat. The switch resolves once and caches, so a frame pays a
//!   thread-local read plus one atomic load.
//! * `software_vs_software_a_a_is_within_the_noise_floor` — the A/A: the software
//!   path reached through the build default (leg B) and through an explicit
//!   override (leg A). Both legs compose the same frames with the same code, so
//!   the difference between them *is* the switch's own overhead plus this phone's
//!   resolution - which is why the A/A placebo (the two halves of one leg) is
//!   printed beside it. Once slice 4 wires the command backend,
//!   `CALLY_RENDER_BACKEND=gpu-commands` turns the same file into the real A/B,
//!   with the per-backend hook table (`backend_frame_cost`) reporting each leg.
//!
//! Both use the project's perf discipline: ABBA blocks so frequency drift
//! cancels within a pair, min-of-N (median beside it), and the process' own CPU
//! time (`/proc/self/stat` utime+stime) as the primary number - wall clock on a
//! phone whose load average sits near 20 mostly measures the neighbours.
//!
//! Ignored by default: they are measurements, not gates.
//! `cargo nextest run -p callys-client --cargo-profile ci-test --run-ignored all -E 'binary(render_backend_switch_perf)'`
use callys_client::{
    backend_frame_cost, draw_frame, render_backend_config, reset_backend_frame_costs,
    set_frame_cost_recording, set_render_backend, BackendFrameCost, BackendRefusal, Framebuffer,
    GameState, RenderBackend, BACKEND_ENV, BUILD_DEFAULT_BACKEND,
};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::hint::black_box;
use std::path::Path;
use std::sync::Arc;
use std::time::Instant;

const W: u32 = 1136;
const H: u32 = 640;
const DT: f32 = 1.0 / 60.0;
/// draw_hash's rooms: the heaviest by primitive count plus the prologue's room.
const ROOMS: [usize; 8] = [0, 1, 2, 23, 25, 39, 109, 111];
/// Frames per block: long enough that one scheduling hiccup cannot move the block
/// minimum, short enough that 8 rooms x 2 legs fit in a few minutes on a phone.
const ROOM_ITERS: u32 = 200;
/// ABBA pairs per room. Four, not two: the A/A placebo is the min of the two
/// halves of one leg, and with two samples per leg each "half" is a single
/// sample - a placebo that noisy cannot label anything.
const ROOM_PAIRS: usize = 4;
const RESOLUTION_ITERS: u32 = 200_000;

fn loadavg() -> String {
    std::fs::read_to_string("/proc/loadavg")
        .map(|s| s.split_whitespace().take(3).collect::<Vec<_>>().join(" "))
        .unwrap_or_else(|_| "n/a (Android restricts /proc/loadavg for the app uid)".to_string())
}

/// The process' own CPU time in seconds (`/proc/self/stat` utime+stime, USER_HZ
/// ticks). Wall clock on a phone whose load average sits near 20 mostly measures
/// the neighbours; this does not.
fn proc_cpu_secs() -> Option<f64> {
    let stat = std::fs::read_to_string("/proc/self/stat").ok()?;
    let fields: Vec<&str> = stat.get(stat.rfind(')')? + 2..)?.split_whitespace().collect();
    let utime: u64 = fields.get(11)?.parse().ok()?;
    let stime: u64 = fields.get(12)?.parse().ok()?;
    Some((utime + stime) as f64 / 100.0)
}

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

/// The backend this process was asked for: `CALLY_RENDER_BACKEND` when it is
/// set, the build default otherwise. `Err` is the refusal a not-yet-wired
/// backend produces - a measurement must report that, not measure the wrong
/// leg's numbers.
fn ambient_leg() -> Result<RenderBackend, BackendRefusal> {
    match render_backend_config() {
        Err(unknown) => Err(BackendRefusal::UnknownValue(unknown)),
        Ok(cfg) => {
            if cfg.backend.is_wired() {
                Ok(cfg.backend)
            } else {
                Err(BackendRefusal::NotWired { resolution: cfg })
            }
        }
    }
}

/// One timed block: `iters` uncached frames on `override_`.
struct Block {
    wall_ms: f64,
    cpu_ms: f64,
    hook: BackendFrameCost,
}

fn block(state: &GameState, fb: &mut Framebuffer, override_: Option<RenderBackend>, iters: u32) -> Block {
    set_render_backend(override_);
    let backend = render_backend_config().expect("the legs are resolved before they are timed").backend;
    reset_backend_frame_costs();
    let cpu0 = proc_cpu_secs();
    let t = Instant::now();
    for _ in 0..iters {
        draw_frame(fb, state, &state.asset.tpag_items, &state.asset.sprites);
    }
    let wall_ms = t.elapsed().as_secs_f64() * 1000.0 / iters as f64;
    let cpu_ms = cpu0
        .zip(proc_cpu_secs())
        .map(|(a, b)| (b - a) * 1000.0 / iters as f64)
        .unwrap_or(f64::NAN);
    let hook = backend_frame_cost(backend);
    assert_eq!(
        hook.frames, iters as u64,
        "the per-frame hook must sample every composed frame on this leg",
    );
    assert!(hook.mean_ns().unwrap() > 0.0, "a composed frame takes time");
    Block { wall_ms, cpu_ms, hook }
}

fn min(xs: &[f64]) -> f64 {
    xs.iter().copied().fold(f64::INFINITY, f64::min)
}

fn median(xs: &[f64]) -> f64 {
    let mut v = xs.to_vec();
    v.sort_by(|a, b| a.total_cmp(b));
    v[v.len() / 2]
}

/// What the switch costs per resolution, against the per-frame env read it
/// replaces. `CALLY_RENDER_BACKEND` is resolved (and cached) on the first frame;
/// every frame after that is a thread-local read plus one atomic load, so the
/// A/B lever cannot itself move the numbers it compares.
#[test]
#[ignore = "measurement, run explicitly with --ignored"]
fn resolving_the_backend_is_not_a_per_frame_getenv() {
    set_render_backend(None);
    // Warm the cache the way a render loop would.
    let _ = render_backend_config().expect("nothing to reject");

    let t = Instant::now();
    for _ in 0..RESOLUTION_ITERS {
        black_box(render_backend_config().expect("nothing to reject"));
    }
    let cached_ns = t.elapsed().as_secs_f64() * 1.0e9 / RESOLUTION_ITERS as f64;

    let t = Instant::now();
    for _ in 0..RESOLUTION_ITERS {
        let _ = black_box(std::env::var(BACKEND_ENV));
    }
    let env_ns = t.elapsed().as_secs_f64() * 1.0e9 / RESOLUTION_ITERS as f64;

    println!(
        "\n{} cached resolutions and {} uncached env reads; loadavg {}",
        RESOLUTION_ITERS, RESOLUTION_ITERS, loadavg(),
    );
    println!(
        "  cached switch resolution {cached_ns:6.1} ns/call  (thread-local read + cached atomic load)"
    );
    println!("  raw std::env::var        {env_ns:6.1} ns/call  (what a per-frame getenv would pay)");
    println!(
        "  frame cost for scale: ~6 ms software composition, so both are < {:.4}% of a frame",
        cached_ns / 6.0e6 * 100.0,
    );
    assert!(
        cached_ns < 1_000.0,
        "one resolution must stay far below a microsecond (got {cached_ns:.1} ns) - if this \
         ever reaches the env read, something moved the lookup into the frame path",
    );
}

/// The A/A: software composed through two different resolution sources.
///
/// Both legs run the identical code on the identical frames, so the difference
/// between them is the switch's own cost plus noise. The A/A placebo (min of the
/// two halves of one leg against each other) is this phone's resolution floor; a
/// real difference would have to exceed it to mean anything. Once slice 4 wires
/// the command backend, the same file with `CALLY_RENDER_BACKEND=gpu-commands`
/// measures the real A/B, and the hook table reports each leg's distribution.
#[test]
#[ignore = "wall-clock A/B measurement, run explicitly with --ignored"]
fn software_vs_software_a_a_is_within_the_noise_floor() {
    set_render_backend(None);
    let ambient = ambient_leg();
    match &ambient {
        Err(refusal) => {
            println!("\nleg B unavailable in this process: {refusal}");
            println!(
                "run without {BACKEND_ENV} (or with it set to {}) to measure the A/A",
                RenderBackend::Software.name(),
            );
            return;
        }
        Ok(backend) => {
            let cfg = render_backend_config().expect("resolved above");
            println!(
                "\nleg A = {} (explicit override), leg B = {} (from {}); {}",
                RenderBackend::Software.name(),
                backend.name(),
                cfg.source.name(),
                if *backend == RenderBackend::Software {
                    "A/A: the same path reached through two resolution sources"
                } else {
                    "A/B: the requested backend against software"
                },
            );
        }
    }
    let leg_b = ambient.expect("checked above");
    let leg_a = Some(RenderBackend::Software);
    let leg_b_override = if leg_b == RenderBackend::Software { None } else { Some(leg_b) };
    println!(
        "build default is {}; {} frames per block, {} ABBA pairs per room, {} rooms; loadavg {}",
        BUILD_DEFAULT_BACKEND.name(),
        ROOM_ITERS,
        ROOM_PAIRS,
        ROOMS.len(),
        loadavg(),
    );

    let mut state = boot();
    let mut fb = Framebuffer::new(W, H);
    set_frame_cost_recording(true);

    println!(
        "{:>14} {:>9} {:>9} {:>9} {:>9} {:>9} {:>9} {:>9} {:>9} {:>9} {:>7}",
        "room", "A cpu", "B cpu", "A wall", "B wall", "A hook", "B hook", "pairΔcpu",
        "cpu floor", "wall A/A", "wall Δ/f",
    );
    let mut deltas: Vec<f64> = Vec::new();
    let mut a_cpu_all: Vec<f64> = Vec::new();
    let mut b_cpu_all: Vec<f64> = Vec::new();
    let mut worst_cpu_placebo = 0.0f64;
    for room in ROOMS {
        let name = state.asset.rooms[room].name.clone();
        state
            .restore_ir_snapshot(&save_for(room))
            .unwrap_or_else(|e| panic!("restore room{room} {name}: {e}"));
        for _ in 0..30 {
            state.step(DT);
        }
        // Warm-up on both legs, so the first room's block is not paying for
        // caches the others do not.
        block(&state, &mut fb, leg_a, ROOM_ITERS);
        block(&state, &mut fb, leg_b_override, ROOM_ITERS);

        let (mut a_cpu, mut b_cpu) = (Vec::new(), Vec::new());
        let (mut a_wall, mut b_wall) = (Vec::new(), Vec::new());
        let (mut a_hook, mut b_hook) = (Vec::new(), Vec::new());
        for pair in 0..ROOM_PAIRS {
            // ABBA: the leg order alternates, so a drift in clocks or thermal
            // state cancels inside a pair instead of loading onto one leg.
            let order = if pair % 2 == 0 {
                [leg_a, leg_b_override]
            } else {
                [leg_b_override, leg_a]
            };
            let (mut pair_a, mut pair_b) = (None, None);
            for leg in order {
                let b = block(&state, &mut fb, leg, ROOM_ITERS);
                if leg == leg_a {
                    a_cpu.push(b.cpu_ms);
                    a_wall.push(b.wall_ms);
                    a_hook.push(b.hook.mean_ns().unwrap());
                    pair_a = Some(b.cpu_ms);
                } else {
                    b_cpu.push(b.cpu_ms);
                    b_wall.push(b.wall_ms);
                    b_hook.push(b.hook.mean_ns().unwrap());
                    pair_b = Some(b.cpu_ms);
                }
            }
            deltas.push(pair_a.unwrap() - pair_b.unwrap());
        }
        // The placebo for the *primary* statistic (process CPU time) is the same
        // paired-ish statistic computed inside leg B: the two halves of its own
        // samples. That is this machine's resolution on this room, measured in
        // the same run and under the same load - so a real difference has to
        // clear it to mean anything.
        let (b_lo, b_hi) = b_cpu.split_at(b_cpu.len() / 2);
        let cpu_placebo = (median(b_lo) - median(b_hi)).abs();
        worst_cpu_placebo = worst_cpu_placebo.max(cpu_placebo);
        a_cpu_all.extend_from_slice(&a_cpu);
        b_cpu_all.extend_from_slice(&b_cpu);
        // Wall clock is reported beside it, never asserted on: on this phone its
        // A/A placebo is milliseconds wide (see the `wall A/A` column).
        let (bw_lo, bw_hi) = b_wall.split_at(b_wall.len() / 2);
        let wall_placebo = (min(bw_lo) - min(bw_hi)).abs();
        let wall_excess = (min(&a_wall) - min(&b_wall)).abs();
        println!(
            "{:>14} {:>9.3} {:>9.3} {:>9.3} {:>9.3} {:>9.0} {:>9.0} {:>9.3} {:>9.3} {:>9.3} {:>7.2}",
            name,
            median(&a_cpu),
            median(&b_cpu),
            min(&a_wall),
            min(&b_wall),
            min(&a_hook),
            min(&b_hook),
            median(&deltas[deltas.len() - ROOM_PAIRS..]),
            cpu_placebo,
            wall_placebo,
            wall_excess / wall_placebo.max(1.0e-3),
        );
    }
    let paired = median(&deltas);
    let frame_cpu = median(&a_cpu_all);
    println!(
        "\npaired cpu deltas (A - B, ms/frame, ABBA-cancelled): {}",
        deltas.iter().map(|d| format!("{d:+.3}")).collect::<Vec<_>>().join(" "),
    );
    println!(
        "cpu ms/frame: A median {frame_cpu:.3}, B median {:.3}; paired median {paired:+.3}, \
         worst in-run A/A placebo {worst_cpu_placebo:.3}",
        median(&b_cpu_all),
    );
    println!("loadavg after: {}", loadavg());
    set_frame_cost_recording(false);
    set_render_backend(None);

    // A/A verdict on the primary metric. The two legs run the same code on the
    // same frames, so this is the switch's own overhead: it has to stay inside
    // this machine's resolution (the in-run A/A placebo) or, on a quiet machine
    // where that placebo is tiny, inside 5% of a frame. The direct measurement
    // in `resolving_the_backend_is_not_a_per_frame_getenv` (tens of ns per
    // resolution) is the number that carries the zero-overhead claim; this block
    // bounds it at frame granularity.
    let floor = (0.05 * frame_cpu).max(worst_cpu_placebo);
    assert!(
        paired.abs() <= floor,
        "the same backend reached through two resolution sources must not differ measurably \
         (paired median Δcpu = {paired:+.3} ms/frame, floor {floor:.3} ms = max(5% of a frame, \
         worst in-run A/A placebo {worst_cpu_placebo:.3} ms))",
    );
    println!(
        "A/A verdict: paired median Δcpu {paired:+.3} ms/frame <= floor {floor:.3} ms \
         (max(5% of {frame_cpu:.3} ms, worst A/A placebo {worst_cpu_placebo:.3} ms))",
    );
    let positive = deltas.iter().filter(|d| **d > 0.0).count();
    println!(
        "sign of (A - B) across {} pairs: {} positive, {} negative",
        deltas.len(),
        positive,
        deltas.len() - positive,
    );
}
