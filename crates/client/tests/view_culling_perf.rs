//! View culling A/B: what the guard buys, and how much of it this phone can
//! resolve.
//!
//! `tests/view_culling.rs` proves the guard cannot change a frame and that it
//! fires on the real rooms (rm_level17: 813 of 865 commands per frame). These
//! two measurements cover the cost side.
//!
//! * `off_screen_dispatch_is_cheaper_with_the_guard` — a scene whose entire
//!   sprite stream is off-screen, so a frame's cost is the clear plus the
//!   command path with no pixel work to hide behind: the slice-2 win, isolated.
//! * `guard_on_vs_off_raster_cost_per_room` — the same comparison on the real
//!   rooms, with an A/A placebo (the two halves of one side) reported as the
//!   resolution floor. On this phone (load average near 20) that floor is
//!   ±1–2 ms/frame, so the real-room table says "not resolvable", not "no
//!   effect"; the isolated probe is what carries the number.
//!
//! Both use the project's perf discipline: ON/OFF blocks alternate so
//! frequency drift cancels within a pair, min-of-N (median next to it), and the
//! process' own CPU time (`/proc/self/stat` utime+stime) beside wall clock.
//!
//! Ignored by default: they are measurements, not gates.
//! `cargo test --release -p callys-client --test view_culling_perf -- --ignored --nocapture --test-threads=1`
use callys_client::{
    draw_frame, reset_view_cull_stats, set_view_cull_enabled, view_cull_stats, Framebuffer,
    GameState, ViewCullStats,
};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::DrawCommand;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::path::Path;
use std::sync::Arc;
use std::time::Instant;

const W: u32 = 1136;
const H: u32 = 640;
const DT: f32 = 1.0 / 60.0;
const ROOMS: [usize; 8] = [0, 1, 2, 23, 25, 39, 109, 111];
/// Real-room blocks: long enough that one scheduling hiccup cannot move the
/// block minimum, short enough that eight rooms fit in a few minutes.
const ROOM_ITERS: u32 = 300;
const ROOM_PAIRS: usize = 2;
/// Dispatch probe: 20k off-screen commands per frame put the command path well
/// above the clear + capture constants that both sides pay.
const PROBE_COMMANDS: usize = 20_000;
const PROBE_ITERS: u32 = 150;
const PROBE_PAIRS: usize = 4;

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

/// One timed block: `iters` frames with the guard forced to `enabled`.
/// Returns (wall ms/frame, cpu ms/frame).
fn block(state: &GameState, fb: &mut Framebuffer, enabled: bool, iters: u32) -> (f64, f64) {
    set_view_cull_enabled(enabled);
    let cpu0 = proc_cpu_secs();
    let t = Instant::now();
    for _ in 0..iters {
        draw_frame(fb, state, &state.asset.tpag_items, &state.asset.sprites);
    }
    let wall = t.elapsed().as_secs_f64() * 1000.0 / iters as f64;
    let cpu = cpu0
        .zip(proc_cpu_secs())
        .map(|(a, b)| (b - a) * 1000.0 / iters as f64)
        .unwrap_or(f64::NAN);
    (wall, cpu)
}

fn stats_for_one_frame(state: &GameState, fb: &mut Framebuffer) -> ViewCullStats {
    set_view_cull_enabled(true);
    reset_view_cull_stats();
    draw_frame(fb, state, &state.asset.tpag_items, &state.asset.sprites);
    view_cull_stats()
}

fn min(xs: &[f64]) -> f64 {
    xs.iter().copied().fold(f64::INFINITY, f64::min)
}

fn median(xs: &[f64]) -> f64 {
    let mut v = xs.to_vec();
    v.sort_by(|a, b| a.total_cmp(b));
    v[v.len() / 2]
}

/// A real sprite whose frame 0 page resolves and holds a visible pixel.
fn pick_sprite(state: &GameState) -> i32 {
    let mut ids: Vec<i32> = state.asset.sprites.keys().map(|k| *k as i32).collect();
    ids.sort();
    for id in ids {
        let sprite = state.asset.sprites.get(&(id as usize)).unwrap();
        if sprite.tpag_indices.is_empty() || sprite.width < 8 || sprite.height < 8 {
            continue;
        }
        let Some(page) = state.asset.tpag_items.get(&(sprite.tpag_indices[0] as usize)) else {
            continue;
        };
        let Some(atlas) = state.atlases.get(page.tex_id as usize) else { continue };
        let opaque = (0..page.h as u32).any(|y| {
            (0..page.w as u32)
                .any(|x| atlas.get_pixel(page.x as u32 + x, page.y as u32 + y).0[3] >= 16)
        });
        if opaque {
            return id;
        }
    }
    panic!("no sprite in the asset satisfies the probe requirements");
}

/// The slice-2 win with no pixel work in the frame: 20k real sprite commands,
/// all off-screen, so on-versus-off measures the command path itself (sprite
/// resolution, page/atlas resolution, blit entry). Every probe command is
/// asserted off-screen first, so a probe that silently became visible work fails
/// instead of reporting a fantasy number.
///
/// The frame also clears the framebuffer and captures the raster inputs
/// (20k command clones) on both sides; those constants cancel in the difference
/// and are not attributed to the guard.
#[test]
#[ignore = "wall-clock A/B measurement, run explicitly with --ignored"]
fn off_screen_dispatch_is_cheaper_with_the_guard() {
    let mut state = boot();
    state.retire_prologue();
    state.scene.as_mut().unwrap().view_visible = [false; 8];
    let sprite_id = pick_sprite(&state);
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    {
        let scene = state.scene.as_mut().unwrap();
        scene.draws.clear();
        scene.backgrounds.clear();
        scene.room_tiles.clear();
        scene.texts.clear();
        scene.healthbars.clear();
        scene.particles.clear();
        for i in 0..PROBE_COMMANDS {
            // Far off-screen, with positions varying so the guard's box test
            // sees real variety instead of one repeated constant.
            scene.draws.push(DrawCommand {
                code: 0,
                offset: 0,
                instance: -1,
                view: 0,
                sprite: sprite_id,
                frame: (i % 4) as f64,
                x: cam_x - 100_000.0 - i as f64,
                y: cam_y + 100.0 + (i % 97) as f64,
                scale_x: 1.0,
                scale_y: 1.0,
                rotation: 0.0,
                color: 16777215,
                alpha: 1.0,
                fog: false,
            });
        }
    }
    let mut fb = Framebuffer::new(W, H);
    let stats = stats_for_one_frame(&state, &mut fb);
    assert_eq!(
        stats.sprite_tested, PROBE_COMMANDS as u64,
        "probe premise: every command resolves to a real sprite",
    );
    assert_eq!(
        stats.sprite_culled, PROBE_COMMANDS as u64,
        "probe premise: every command is off the framebuffer (otherwise this measures pixels)",
    );

    // Warm-up, then alternating ON/OFF pairs.
    block(&state, &mut fb, true, PROBE_ITERS);
    block(&state, &mut fb, false, PROBE_ITERS);
    let (mut on_wall, mut off_wall) = (Vec::new(), Vec::new());
    let (mut on_cpu, mut off_cpu) = (Vec::new(), Vec::new());
    let mut pairs = Vec::new();
    for pair in 0..PROBE_PAIRS {
        let order = if pair % 2 == 0 { [true, false] } else { [false, true] };
        let (mut p_on, mut p_off) = (None, None);
        for enabled in order {
            let (wall, cpu) = block(&state, &mut fb, enabled, PROBE_ITERS);
            if enabled {
                on_wall.push(wall);
                on_cpu.push(cpu);
                p_on = Some(cpu);
            } else {
                off_wall.push(wall);
                off_cpu.push(cpu);
                p_off = Some(cpu);
            }
        }
        pairs.push(p_on.unwrap() - p_off.unwrap());
    }

    let per_cmd = |ms: f64| ms * 1.0e6 / PROBE_COMMANDS as f64;
    let (on_min, off_min) = (min(&on_wall), min(&off_wall));
    let saved_ns = per_cmd(off_min - on_min);
    println!(
        "\n{} sprite commands, all off screen, {} frames per block, {} ON/OFF pairs; loadavg {}",
        PROBE_COMMANDS, PROBE_ITERS, PROBE_PAIRS, loadavg(),
    );
    println!(
        "  wall ms/frame: on min {on_min:.3} med {:.3} | off min {off_min:.3} med {:.3}",
        median(&on_wall),
        median(&off_wall),
    );
    println!(
        "  cpu  ms/frame: on min {:.3} med {:.3} | off min {:.3} med {:.3}",
        min(&on_cpu),
        median(&on_cpu),
        min(&off_cpu),
        median(&off_cpu),
    );
    println!(
        "  paired cpu deltas (on - off): {}",
        pairs.iter().map(|d| format!("{d:+.3}")).collect::<Vec<_>>().join(" "),
    );
    println!(
        "  per culled command: {:.1} ns with the guard, {:.1} ns without, saved {:.1} ns",
        per_cmd(on_min),
        per_cmd(off_min),
        saved_ns,
    );
    assert!(
        saved_ns > 0.0,
        "the guard replaces a full dispatch with a box test - it cannot cost more \
         (on {on_min:.3} ms vs off {off_min:.3} ms)",
    );
    // Sign consistency is the claim that survives a loaded phone: every pair
    // runs ON/OFF back to back, so drift cancels within the pair.
    let negatives = pairs.iter().filter(|d| **d < 0.0).count();
    assert!(
        negatives * 4 >= pairs.len() * 3,
        "the guard must be faster in almost every ON/OFF pair (CPU deltas: {})",
        pairs.iter().map(|d| format!("{d:+.3}")).collect::<Vec<_>>().join(" "),
    );
}

#[test]
#[ignore = "wall-clock A/B measurement, run explicitly with --ignored"]
fn guard_on_vs_off_raster_cost_per_room() {
    let mut state = boot();
    let mut fb = Framebuffer::new(W, H);
    println!(
        "\n{}x{} canvas, {} frames per block, {} ON/OFF pairs; loadavg {}",
        W, H, ROOM_ITERS, ROOM_PAIRS, loadavg(),
    );
    println!(
        "{:>14} {:>7} {:>7} {:>5} {:>8} {:>8} {:>9} {:>9} {:>9} {:>9}",
        "room", "cmds/f", "cull/f", "hit", "on min", "off min", "on med", "off med",
        "pair Δmed", "placebo",
    );
    for room in ROOMS {
        let name = state.asset.rooms[room].name.clone();
        state
            .restore_ir_snapshot(&save_for(room))
            .unwrap_or_else(|e| panic!("restore room{room} {name}: {e}"));
        for _ in 0..30 {
            state.step(DT);
        }
        let stats = stats_for_one_frame(&state, &mut fb);
        block(&state, &mut fb, true, ROOM_ITERS);
        block(&state, &mut fb, false, ROOM_ITERS);

        let (mut on_wall, mut off_wall) = (Vec::new(), Vec::new());
        let (mut on_cpu, mut off_cpu) = (Vec::new(), Vec::new());
        let mut pairs = Vec::new();
        for pair in 0..ROOM_PAIRS {
            let order = if pair % 2 == 0 { [true, false] } else { [false, true] };
            let (mut p_on, mut p_off) = (None, None);
            for enabled in order {
                let (wall, cpu) = block(&state, &mut fb, enabled, ROOM_ITERS);
                if enabled {
                    on_wall.push(wall);
                    on_cpu.push(cpu);
                    p_on = Some(cpu);
                } else {
                    off_wall.push(wall);
                    off_cpu.push(cpu);
                    p_off = Some(cpu);
                }
            }
            pairs.push(p_on.unwrap() - p_off.unwrap());
        }
        // A/A placebo: the same statistic (min of half the samples) computed
        // between the two halves of the OFF side = this machine's resolution.
        let (off_lo, off_hi) = off_wall.split_at(off_wall.len() / 2);
        let placebo = min(off_lo) - min(off_hi);
        println!(
            "{:>14} {:>7.1} {:>7.1} {:>5.3} {:>8.3} {:>8.3} {:>9.3} {:>9.3} {:>9.3} {:>9.3}",
            name,
            stats.sprite_commands as f64,
            stats.sprite_culled as f64,
            stats.sprite_hit_rate().unwrap_or(f64::NAN),
            min(&on_wall),
            min(&off_wall),
            median(&on_wall),
            median(&off_wall),
            median(&pairs),
            placebo,
        );
        println!(
            "  (cpu ms/frame: on min {:.3} med {:.3} | off min {:.3} med {:.3})",
            min(&on_cpu),
            median(&on_cpu),
            min(&off_cpu),
            median(&off_cpu),
        );
    }
    println!("\nloadavg after: {}", loadavg());
}
