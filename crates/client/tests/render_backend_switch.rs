//! Runtime render-backend switch — contract `gpu-command-backend.md` slice 7.
//!
//! Slice 7 ships the *switch*, not the command backend (that is slices 1/4), so
//! the claims this file has to hold are:
//!
//! 1. **The switch is a select, not a rewrite.** Reaching the software path
//!    through two different resolution sources (build default vs in-process
//!    override) yields byte-identical frames on every frame the draw_hash
//!    equivalence gate walks. The build default resolves to `software`, so the
//!    shipped path is the pre-slice path.
//! 2. **The priority rule is explicit**: override > env > build default, and it
//!    is testable without mutating a process-wide environment
//!    (`resolve_backend` is a pure function of its two inputs).
//! 3. **The env var really drives a process.** The child re-executed below
//!    resolves from its own environment; an unrecognised value is an error there,
//!    not a silent fall-back to the default.
//! 4. **An unwired backend is a typed refusal, never a silent software frame.**
//!    The frame entry panics with `BackendRefusal` as the payload, the
//!    framebuffer is left untouched (nothing was composed), and the A/B cost
//!    table stays empty (a refusal cannot pad a measurement).
use callys_client::{
    backend_frame_cost, draw_frame, render_backend_config, render_backend_status,
    reset_backend_frame_costs, resolve_backend, set_frame_cost_recording, set_render_backend,
    BackendRefusal, BackendSource, Framebuffer, GameState, RenderBackend, UnknownBackendValue,
    BACKEND_ENV, BUILD_DEFAULT_BACKEND,
};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::panic::{catch_unwind, AssertUnwindSafe};
use std::path::Path;
use std::sync::Arc;

/// draw_hash's canvas and frame budget: 1136x640, 40 prologue frames + 40 after
/// the tap that retires the prologue + 8 rooms x 40 frames = the 400 frames the
/// equivalence gate hashes.
const W: u32 = 1136;
const H: u32 = 640;
const DT: f32 = 1.0 / 60.0;
const ROOMS: [usize; 8] = [0, 1, 2, 23, 25, 39, 109, 111];
const PROLOGUE_FRAMES: u32 = 40;
const ROOM_FRAMES: u32 = 40;
const GATE_FRAMES: u32 = 2 * PROLOGUE_FRAMES + ROOMS.len() as u32 * ROOM_FRAMES;
/// The 400 baseline frames produced 284 distinct FNV hashes; a leg that stopped
/// animating (or drew one cached frame 400 times) must not pass the equality
/// check vacuously.
const BASELINE_DISTINCT_HASHES: usize = 284;

fn fnv1a(bytes: &[u8]) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    for b in bytes {
        h ^= *b as u64;
        h = h.wrapping_mul(0x100_0000_01b3);
    }
    h
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

/// `resolve_backend` for a value that must be rejected, naming the value when it
/// is not.
fn resolve_rejected(value: &str) -> UnknownBackendValue {
    match resolve_backend(None, Some(value)) {
        Err(err) => err,
        Ok(cfg) => panic!("{value:?} must not resolve, but it selected {cfg}"),
    }
}

/// One real frame drawn twice — build-default resolution, then an explicit
/// software override — and compared byte for byte.
///
/// Both resolutions must report the source they came from, and both must land
/// on `software`: that is the "the switch selects, it does not rewrite the
/// frame" claim, on the same 400 frames draw_hash freezes.
///
/// The frame's FNV hash is printed in draw_hash's own format (`<label> <hash>`)
/// under `--nocapture`, so the suite's default-path frames can be diffed against
/// a recorded draw_hash run of the same scenario - the same gate, reproducible
/// from inside the test suite.
fn draw_pair(
    state: &GameState,
    default_fb: &mut Framebuffer,
    override_fb: &mut Framebuffer,
    label: &str,
    hashes: &mut Vec<(String, u64)>,
) {
    set_render_backend(None);
    let default_cfg = render_backend_config().expect("no env value to reject");
    assert_eq!(
        default_cfg.source,
        BackendSource::BuildDefault,
        "{label}: nothing set an override, so the build default must decide",
    );
    assert_eq!(
        default_cfg.backend, BUILD_DEFAULT_BACKEND,
        "{label}: the build default is the software rasterizer",
    );
    draw_frame(default_fb, state, &state.asset.tpag_items, &state.asset.sprites);

    set_render_backend(Some(RenderBackend::Software));
    let override_cfg = render_backend_config().expect("no env value to reject");
    assert_eq!(override_cfg.source, BackendSource::Override, "{label}: the override must win");
    assert_eq!(override_cfg.backend, RenderBackend::Software, "{label}");
    draw_frame(override_fb, state, &state.asset.tpag_items, &state.asset.sprites);

    set_render_backend(None);
    assert_eq!(
        default_fb.pixels, override_fb.pixels,
        "{label}: the same software path reached through two resolution sources must \
         produce the same pixels ({} bytes)",
        default_fb.pixels.len(),
    );
    let hash = fnv1a(&default_fb.pixels);
    println!("{label} {hash}");
    hashes.push((label.to_string(), hash));
}

/// The switch must be invisible on the frames the equivalence gate covers, and
/// the default resolution must be the pre-slice software path.
#[test]
fn the_build_default_and_the_software_override_draw_identical_frames() {
    let mut state = boot();
    let mut default_fb = Framebuffer::new(W, H);
    let mut override_fb = Framebuffer::new(W, H);
    let mut hashes: Vec<(String, u64)> = Vec::with_capacity(GATE_FRAMES as usize);

    for frame in 0..PROLOGUE_FRAMES {
        state.step(DT);
        draw_pair(&state, &mut default_fb, &mut override_fb, &format!("prologue f{frame:03}"), &mut hashes);
    }
    state.input.tap = true;
    state.step(DT);
    state.input.tap = false;
    for frame in 0..PROLOGUE_FRAMES {
        state.step(DT);
        draw_pair(&state, &mut default_fb, &mut override_fb, &format!("handover f{frame:03}"), &mut hashes);
    }
    for room in ROOMS {
        let name = state.asset.rooms[room].name.clone();
        state
            .restore_ir_snapshot(&save_for(room))
            .unwrap_or_else(|e| panic!("restore room{room} {name}: {e}"));
        for frame in 0..ROOM_FRAMES {
            state.step(DT);
            draw_pair(
                &state,
                &mut default_fb,
                &mut override_fb,
                &format!("room{room:03} {name} f{frame:03}"),
                &mut hashes,
            );
        }
    }

    assert_eq!(hashes.len(), GATE_FRAMES as usize, "the gate walks exactly {GATE_FRAMES} frames");
    let distinct: std::collections::HashSet<u64> = hashes.iter().map(|(_, h)| *h).collect();
    println!(
        "{} frames drawn twice (build default vs software override), all byte-identical; \
         {} distinct frame hashes (baseline {})",
        hashes.len(),
        distinct.len(),
        BASELINE_DISTINCT_HASHES,
    );
    assert!(
        distinct.len() >= BASELINE_DISTINCT_HASHES,
        "the legs must actually animate - {} distinct hashes over {} frames is below the \
         baseline's {} (the equality check above would otherwise be near-vacuous)",
        distinct.len(),
        hashes.len(),
        BASELINE_DISTINCT_HASHES,
    );
}

/// The priority rule, as a pure function: an override beats the env var, the env
/// var beats the build default, the value's spelling is generous and an
/// unrecognised value is an error rather than a silent fall-back.
#[test]
fn resolve_backend_pins_the_priority_rule_and_the_accepted_values() {
    // Nothing asked for anything -> the build default.
    let cfg = resolve_backend(None, None).expect("unset env is not an error");
    assert_eq!((cfg.backend, cfg.source, cfg.env_value), (BUILD_DEFAULT_BACKEND, BackendSource::BuildDefault, None));

    // An empty or whitespace-only value counts as unset (a shell `VAR=` exports "").
    for empty in ["", "   ", "\t"] {
        let cfg = resolve_backend(None, Some(empty)).expect("empty is not an error");
        assert_eq!(
            (cfg.backend, cfg.source),
            (BUILD_DEFAULT_BACKEND, BackendSource::BuildDefault),
            "{empty:?} must mean unset, not a value",
        );
    }

    // The env var decides when there is no override, and is reported as the source.
    for (value, backend) in [
        ("software", RenderBackend::Software),
        ("Software", RenderBackend::Software),
        ("  cpu  ", RenderBackend::Software),
        ("gpu-commands", RenderBackend::GpuCommands),
        ("GPU", RenderBackend::GpuCommands),
        ("gpu", RenderBackend::GpuCommands),
    ] {
        let cfg = resolve_backend(None, Some(value)).expect("accepted value");
        assert_eq!(cfg.backend, backend, "{value:?}");
        assert_eq!(cfg.source, BackendSource::Env, "{value:?}");
        assert_eq!(cfg.env_value, Some(value.trim()), "{value:?}: the diagnostic keeps the value");
    }

    // The override wins over the env var, including when it asks for the other
    // backend - and it must not claim the env var selected anything.
    for backend in RenderBackend::ALL {
        let cfg = resolve_backend(Some(backend), Some("gpu-commands")).expect("override is always valid");
        assert_eq!((cfg.backend, cfg.source, cfg.env_value), (backend, BackendSource::Override, None));
    }

    // An unrecognised value names the variable, the value and the accepted set.
    for bad in ["metal", "vulkan", "software2", "0"] {
        let err = resolve_rejected(bad);
        assert_eq!(err, UnknownBackendValue { value: bad.to_string() });
        let text = err.to_string();
        assert!(text.contains(BACKEND_ENV), "{text}");
        assert!(text.contains(bad), "{text}");
        for accepted in [RenderBackend::Software.name(), RenderBackend::GpuCommands.name()] {
            assert!(text.contains(accepted), "{text} must list {accepted}");
        }
    }
}

/// Selecting the command backend before slice 4 wires it must fail closed and
/// diagnosably — no software frame behind the operator's back, no phantom sample
/// in the A/B table, and a payload a caller can match on.
#[test]
fn an_unwired_backend_is_a_typed_refusal_not_a_silent_software_frame() {
    set_render_backend(None);
    let state = boot();
    let mut fb = Framebuffer::new(W, H);
    // A sentinel the frame entry would have to overwrite to compose anything:
    // draw_frame's software path clears the whole framebuffer first.
    fb.pixels.fill(0xAB);
    set_frame_cost_recording(true);
    reset_backend_frame_costs();

    set_render_backend(Some(RenderBackend::GpuCommands));

    // The selection itself is valid: config() reports what was asked for...
    let cfg = render_backend_config().expect("'gpu-commands' is a backend, just not a wired one");
    assert_eq!((cfg.backend, cfg.source), (RenderBackend::GpuCommands, BackendSource::Override));
    // ...and the readiness probe is what refuses it.
    match render_backend_status() {
        Err(BackendRefusal::NotWired { resolution }) => {
            assert_eq!(resolution.backend, RenderBackend::GpuCommands);
            assert_eq!(resolution.source, BackendSource::Override);
            let text = BackendRefusal::NotWired { resolution }.to_string();
            for needle in ["gpu-commands", "not wired", BACKEND_ENV, "slice", "software"] {
                assert!(text.contains(needle), "the refusal must name {needle:?}: {text}");
            }
        }
        other => panic!("an unwired backend must refuse the frame entry, got {other:?}"),
    }

    // The frame entry refuses with the same diagnostic as a typed payload.
    let payload = catch_unwind(AssertUnwindSafe(|| {
        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites)
    }))
    .expect_err("draw_frame must not compose a frame on an unwired backend");
    let typed = payload
        .downcast_ref::<BackendRefusal>()
        .expect("the panic payload is the typed refusal, not a formatted string");
    match typed {
        BackendRefusal::NotWired { resolution } => {
            assert_eq!(resolution.backend, RenderBackend::GpuCommands);
        }
        other => panic!("expected NotWired, got {other:?}"),
    }

    // Nothing was composed, and no measurement window was polluted.
    assert!(
        fb.pixels.iter().all(|b| *b == 0xAB),
        "the refused frame must leave the framebuffer alone (a silent software fallback \
         would have cleared it)",
    );
    for backend in RenderBackend::ALL {
        assert!(
            backend_frame_cost(backend).is_empty(),
            "a refused frame must not enter the {backend:?} cost table",
        );
    }

    // The lever works in the other direction too: the same call composes once the
    // operator (or a runtime fallback) steps back onto software.
    set_render_backend(Some(RenderBackend::Software));
    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    assert!(
        !fb.pixels.iter().all(|b| *b == 0xAB),
        "stepping back to software must compose the frame again",
    );
    assert_eq!(backend_frame_cost(RenderBackend::Software).frames, 1);
    assert_eq!(
        backend_frame_cost(RenderBackend::GpuCommands).frames,
        0,
        "only the software leg drew",
    );
    set_frame_cost_recording(false);
    set_render_backend(None);
}

/// The per-frame cost hook files each composition under the backend that
/// produced it, and costs nothing (no clock read, no sample) while it is off.
#[test]
fn the_frame_cost_hook_records_per_backend_samples() {
    set_render_backend(None);
    let state = boot();
    let mut fb = Framebuffer::new(W, H);
    const FRAMES: u64 = 48;

    set_frame_cost_recording(false);
    reset_backend_frame_costs();
    for _ in 0..16 {
        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    }
    assert!(
        RenderBackend::ALL.iter().all(|b| backend_frame_cost(*b).is_empty()),
        "the recorder is off by default: nothing may be sampled",
    );

    set_frame_cost_recording(true);
    reset_backend_frame_costs();
    for _ in 0..FRAMES {
        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    }
    let cost = backend_frame_cost(RenderBackend::Software);
    assert_eq!(cost.frames, FRAMES, "one sample per composed frame");
    let mean = cost.mean_ns().expect("mean of a non-empty table");
    assert!(
        cost.min_ns as f64 <= mean && mean <= cost.max_ns as f64,
        "min {mean} mean {} max {} must bracket each other",
        cost.min_ns,
        cost.max_ns,
    );
    println!(
        "software composition: {} frames, mean {mean:.0} ns, min {} ns, max {} ns",
        cost.frames, cost.min_ns, cost.max_ns,
    );
    assert!(cost.total_ns >= cost.max_ns, "the total must contain the largest sample");
    assert!(
        backend_frame_cost(RenderBackend::GpuCommands).is_empty(),
        "the backend that never composed a frame must have no samples",
    );

    set_frame_cost_recording(false);
    set_render_backend(None);
}

// ---------------------------------------------------------------------------
// The env lever, in a real process
// ---------------------------------------------------------------------------

/// Re-executes this test binary with `CALLY_RENDER_BACKEND` set (or removed),
/// running only `env_probe_child`, and returns its output.
///
/// The env lever is process-wide, so a test cannot flip it in-process without
/// racing every other thread in this binary (`std::env::set_var` is global).
/// A child process has its own environment, its own resolution cache and its own
/// hook state, which makes the probe deterministic - and it is the same path an
/// operator's `CALLY_RENDER_BACKEND=... ./binary` takes.
fn run_env_probe(child_env: Option<&str>) -> String {
    let exe = std::env::current_exe().expect("test binary path");
    let mut cmd = std::process::Command::new(exe);
    cmd.args(["--exact", "env_probe_child", "--nocapture", "--test-threads=1"]);
    match child_env {
        Some(value) => cmd.env(BACKEND_ENV, value),
        None => cmd.env_remove(BACKEND_ENV),
    };
    let out = cmd.output().expect("re-exec the test binary");
    let stdout = String::from_utf8_lossy(&out.stdout).into_owned();
    let stderr = String::from_utf8_lossy(&out.stderr).into_owned();
    assert!(
        out.status.success(),
        "the child failed for {BACKEND_ENV}={child_env:?}\n--- stdout ---\n{stdout}\n--- stderr ---\n{stderr}",
    );
    assert!(
        stdout.contains("1 passed"),
        "the child must have run exactly env_probe_child\n--- stdout ---\n{stdout}",
    );
    format!("{stdout}\n{stderr}")
}

#[test]
fn the_env_var_selects_the_backend_in_a_fresh_process() {
    for (value, backend) in [
        ("software", RenderBackend::Software),
        ("  gpu-commands  ", RenderBackend::GpuCommands),
        ("GPU", RenderBackend::GpuCommands),
        ("cpu", RenderBackend::Software),
    ] {
        let text = run_env_probe(Some(value));
        let trimmed = value.trim();
        assert!(
            text.contains(&format!("RESOLVED backend={} source=env env={trimmed}", backend.name())),
            "the child must resolve {BACKEND_ENV}={value:?} to {}:\n{text}",
            backend.name(),
        );
        if backend == RenderBackend::GpuCommands {
            assert!(
                text.contains("REFUSED-FRAME backend=gpu-commands"),
                "the child's frame entry must refuse the unwired backend:\n{text}",
            );
        }
    }

    // An unsolicited environment variable must not be silently ignored.
    let text = run_env_probe(Some("metal"));
    assert!(text.contains("is not a render backend"), "the unknown value must be named:\n{text}");
    assert!(text.contains("metal"), "{text}");
    assert!(
        text.contains("REFUSED-FRAME backend=unknown-value"),
        "an unrecognised value must refuse the frame entry rather than fall back:\n{text}",
    );

    // And the default path in a process that was asked for nothing.
    let text = run_env_probe(None);
    assert!(
        text.contains(&format!(
            "RESOLVED backend={} source=build-default",
            BUILD_DEFAULT_BACKEND.name()
        )),
        "an unset {BACKEND_ENV} must resolve to the build default:\n{text}",
    );
}

/// The child half of [`run_env_probe`]: resolves from its own environment and
/// drives the real frame entry. Runs in the parent too (where the environment is
/// whatever the harness has), so it must report whichever case it is in.
#[test]
fn env_probe_child() {
    // Thread-locals survive between tests on a reused harness thread.
    set_render_backend(None);
    let raw = std::env::var(BACKEND_ENV).ok();
    let value = raw.as_deref().map(str::trim).filter(|v| !v.is_empty());

    match value {
        None => {
            let cfg = render_backend_config().expect("nothing to reject");
            assert_eq!((cfg.backend, cfg.source), (BUILD_DEFAULT_BACKEND, BackendSource::BuildDefault));
            println!("RESOLVED backend={} source=build-default", cfg.backend.name());
        }
        Some(value) => match render_backend_config() {
            Ok(cfg) => {
                assert_eq!(cfg.source, BackendSource::Env);
                assert_eq!(cfg.env_value, Some(value));
                assert_eq!(
                    cfg.backend,
                    RenderBackend::parse(value).expect("the probe only passes accepted values"),
                );
                println!("RESOLVED backend={} source=env env={value}", cfg.backend.name());
                if cfg.backend.is_wired() {
                    let state = boot();
                    let mut fb = Framebuffer::new(W, H);
                    fb.pixels.fill(0xAB);
                    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
                    assert!(fb.pixels.iter().any(|b| *b != 0xAB), "the software leg composes");
                    println!("DREW backend={}", cfg.backend.name());
                } else {
                    let state = boot();
                    let mut fb = Framebuffer::new(W, H);
                    fb.pixels.fill(0xAB);
                    let payload = catch_unwind(AssertUnwindSafe(|| {
                        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites)
                    }))
                    .expect_err("an unwired backend must refuse the frame entry");
                    let refusal = payload.downcast_ref::<BackendRefusal>().expect("typed payload");
                    assert!(matches!(refusal, BackendRefusal::NotWired { .. }));
                    assert!(fb.pixels.iter().all(|b| *b == 0xAB), "nothing was composed");
                    println!("REFUSED-FRAME backend={}", cfg.backend.name());
                }
            }
            Err(unknown) => {
                let state = boot();
                let mut fb = Framebuffer::new(W, H);
                fb.pixels.fill(0xAB);
                let payload = catch_unwind(AssertUnwindSafe(|| {
                    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites)
                }))
                .expect_err("an unrecognised value must refuse the frame entry");
                let refusal = payload.downcast_ref::<BackendRefusal>().expect("typed payload");
                assert_eq!(*refusal, BackendRefusal::UnknownValue(unknown.clone()));
                assert!(fb.pixels.iter().all(|b| *b == 0xAB), "nothing was composed");
                println!("UNKNOWN {unknown}");
                println!("REFUSED-FRAME backend=unknown-value");
            }
        },
    }
    set_render_backend(None);
}
