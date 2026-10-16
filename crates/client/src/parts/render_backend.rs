// ============================================================
// Render backend switch: software raster vs GPU command backend
// ============================================================
//
// Contract: reconstruction/contracts/gpu-command-backend.md section 4 slice 7.
//
// This is the single place that decides which render path composes a frame
// (`draw_frame` / `draw_frame_cached` both land in `draw_frame_inner`, which
// resolves the backend here and dispatches once).
//
// Slice 7 ships the switch and the A/B path, not the command backend: the
// command model and the GPU pipeline are slices 1 and 4, which land on other
// lines. So the two arms of the dispatch are deliberately asymmetric:
//
//   * `Software`  -> the shipped software rasterizer, byte for byte the same
//                    body the frame family ran before this switch existed;
//   * `GpuCommands` -> a typed refusal (see `BackendRefusal::NotWired`).
//
// The refusal is the whole point of "不得半接线". A silent fallback to software
// would turn every future A/B run into software-versus-software and report "the
// command backend makes no difference" as if it had measured one. Failing closed
// with the resolution in the message cannot be misread that way.
//
// Selection (highest priority first):
//
//   1. `set_render_backend(Some(..))` - the in-process lever: used by tests, by
//      a host that wants a same-process A/B, and by the runtime *fallback* a
//      caller takes after a backend failure. Thread-scoped, like the view-cull
//      switch (`parts/view_cull.rs`), so two measurement windows cannot mix.
//   2. `CALLY_RENDER_BACKEND` - the process-wide lever, read once and cached
//      (the idiom of `CALLY_CODE_TRACE` in `crates/core/src/code_vm.rs`): the
//      A/B between two backends is then a two-process run that differs by one
//      environment variable, with no per-frame `getenv`.
//   3. `BUILD_DEFAULT_BACKEND` - `Software`, so a build that is asked for
//      nothing keeps the path the draw_hash equivalence gate already covers.
//
// An unrecognised value is an error, not a silent fall-back to the default: the
// operator asked for a specific backend and the switch must not pretend it
// selected something else.
//
// Android caveat (measured, not assumed): an app process is forked from zygote,
// so an environment variable set in a shell (`adb shell`, Termux) does not reach
// it - the env lever is real for the host/desktop/headless paths and for any
// process the operator starts directly. Device A/B therefore goes through
// `set_render_backend` (or a host-side property read added by slice 4); that is
// a property of the platform, not of this switch.
use std::sync::OnceLock;

/// Environment variable that selects the render backend for a whole process.
/// Case-insensitive value, surrounding whitespace trimmed; an empty value means
/// "unset".
pub const BACKEND_ENV: &str = "CALLY_RENDER_BACKEND";

/// Environment variable that turns the per-frame cost recorder on for a whole
/// process ("1"/"true"/"yes"/"on", case-insensitive). Off unless asked for.
pub const FRAME_COST_ENV: &str = "CALLY_RENDER_COST";

/// The backend a build composes frames with when nothing else asks for one.
///
/// Slice 7 ships `Software`: the default must be the path the equivalence gate
/// (draw_hash, byte-for-byte) already covers, so switching it is an explicit act
/// by the operator, never a side effect of a refactor. Slice 4 flips this line
/// (or turns it into a cargo feature) once the command backend passes its
/// `glReadPixels` differential gate.
pub const BUILD_DEFAULT_BACKEND: RenderBackend = RenderBackend::Software;

/// Which render path composes a frame.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum RenderBackend {
    /// The whole-frame software rasterizer: `Framebuffer` blits over the IR
    /// draw stream, then one texture upload by the host. The shipped path.
    Software,
    /// GPU command backend (contract slices 1/4): the same draw stream submitted
    /// as GPU commands. Not wired yet - selecting it refuses the frame.
    GpuCommands,
}

impl RenderBackend {
    /// Every backend the switch can name, in dispatch order.
    pub const ALL: [RenderBackend; 2] = [RenderBackend::Software, RenderBackend::GpuCommands];

    /// The name this backend is selected by (`CALLY_RENDER_BACKEND` value).
    pub const fn name(self) -> &'static str {
        match self {
            RenderBackend::Software => "software",
            RenderBackend::GpuCommands => "gpu-commands",
        }
    }

    /// Accepted spellings, for diagnostics.
    pub const ACCEPTED: &'static str = "software (alias cpu), gpu-commands (alias gpu)";

    /// Parse a `CALLY_RENDER_BACKEND` value: the canonical name, case-insensitive
    /// and trimmed, plus the two shell-prompt aliases (`cpu`, `gpu`).
    pub fn parse(value: &str) -> Option<RenderBackend> {
        let value = value.trim();
        if let Some(backend) = Self::ALL.iter().copied().find(|b| b.name().eq_ignore_ascii_case(value)) {
            return Some(backend);
        }
        match value.to_ascii_lowercase().as_str() {
            "cpu" => Some(RenderBackend::Software),
            "gpu" => Some(RenderBackend::GpuCommands),
            _ => None,
        }
    }

    /// Whether the frame entry can actually compose a frame on this backend.
    /// `false` is slice 4's work, not a bug: the dispatch refuses instead of
    /// quietly drawing the software frame (see `BackendRefusal`).
    pub const fn is_wired(self) -> bool {
        matches!(self, RenderBackend::Software)
    }

    /// Index into the per-backend cost table (`[0, 1]`).
    const fn index(self) -> usize {
        match self {
            RenderBackend::Software => 0,
            RenderBackend::GpuCommands => 1,
        }
    }
}

/// Where the resolved backend came from.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BackendSource {
    /// `set_render_backend` (in-process; wins over everything).
    Override,
    /// The `CALLY_RENDER_BACKEND` environment variable.
    Env,
    /// `BUILD_DEFAULT_BACKEND`.
    BuildDefault,
}

impl BackendSource {
    pub const fn name(self) -> &'static str {
        match self {
            BackendSource::Override => "override",
            BackendSource::Env => "env",
            BackendSource::BuildDefault => "build-default",
        }
    }
}

/// What the switch selected, and why. Carries a borrow so the per-frame path
/// allocates nothing; `env_value` is present exactly when the env var decided.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct BackendResolution<'a> {
    pub backend: RenderBackend,
    pub source: BackendSource,
    pub env_value: Option<&'a str>,
}

impl fmt::Display for BackendResolution<'_> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match (self.source, self.env_value) {
            (BackendSource::Env, Some(value)) => {
                write!(f, "{} (from {BACKEND_ENV}={value:?})", self.backend.name())
            }
            _ => write!(f, "{} (from {})", self.backend.name(), self.source.name()),
        }
    }
}

/// A `CALLY_RENDER_BACKEND` value that names no backend.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct UnknownBackendValue {
    pub value: String,
}

impl fmt::Display for UnknownBackendValue {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "{BACKEND_ENV}={:?} is not a render backend; accepted: {}",
            self.value,
            RenderBackend::ACCEPTED,
        )
    }
}

impl std::error::Error for UnknownBackendValue {}

/// Why the frame entry refused to compose a frame. This is the payload of the
/// entry's panic, so a caller (and a test) can match on the reason instead of
/// scraping a message - `std::panic::catch_unwind` + `downcast_ref`.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum BackendRefusal {
    /// The selected backend has no implementation yet (contract slices 1/4).
    NotWired { resolution: BackendResolution<'static> },
    /// The env var names no backend, so the switch cannot be trusted to have
    /// selected what the operator asked for.
    UnknownValue(UnknownBackendValue),
}

impl fmt::Display for BackendRefusal {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            BackendRefusal::NotWired { resolution } => write!(
                f,
                "render backend {} is selected but not wired: the GPU command backend is \
                 contract slices 1 (command model/emission) and 4 (GPU backend + glReadPixels \
                 differential gate) of reconstruction/contracts/gpu-command-backend.md, and \
                 slice 7 ships the switch only; refusing to compose a software frame instead, \
                 because a silent fallback would make every A/B run a software-vs-software \
                 comparison reported as \"the command backend changed nothing\"; unset \
                 {BACKEND_ENV} or set it to {} to run the software rasterizer",
                resolution,
                RenderBackend::Software.name(),
            ),
            BackendRefusal::UnknownValue(unknown) => write!(f, "{unknown}"),
        }
    }
}

impl std::error::Error for BackendRefusal {}

impl BackendRefusal {
    /// Fail closed with this refusal as a typed panic payload.
    ///
    /// The message also goes to stderr first: the default panic hook prints a
    /// non-`&str` payload as `Box<dyn Any>`, so without this line the crash log
    /// would lose the diagnostic that the compiled code carries.
    pub(crate) fn into_panic(self) -> ! {
        eprintln!("callys-client: render backend refused: {self}");
        std::panic::panic_any(self)
    }
}

/// The priority rule, as a pure function of its two inputs - no process state,
/// no clock, no cache, which is what makes the priority matrix testable without
/// mutating the process environment.
///
/// An empty (or whitespace-only) `env` counts as unset, the way
/// `CALLY_CODE_TRACE` does: a shell `CALLY_RENDER_BACKEND=` exports "".
pub fn resolve_backend(
    override_: Option<RenderBackend>,
    env: Option<&str>,
) -> Result<BackendResolution<'_>, UnknownBackendValue> {
    if let Some(backend) = override_ {
        return Ok(BackendResolution {
            backend,
            source: BackendSource::Override,
            env_value: None,
        });
    }
    match env.map(str::trim).filter(|value| !value.is_empty()) {
        Some(value) => match RenderBackend::parse(value) {
            Some(backend) => Ok(BackendResolution {
                backend,
                source: BackendSource::Env,
                env_value: Some(value),
            }),
            None => Err(UnknownBackendValue { value: value.to_string() }),
        },
        None => Ok(BackendResolution {
            backend: BUILD_DEFAULT_BACKEND,
            source: BackendSource::BuildDefault,
            env_value: None,
        }),
    }
}

/// The `CALLY_RENDER_BACKEND` value of this process, read once and cached:
/// `None` for unset, empty or non-unicode. One atomic load per frame afterwards.
fn backend_env_value() -> Option<&'static str> {
    static ENV: OnceLock<Option<String>> = OnceLock::new();
    ENV.get_or_init(|| {
        std::env::var(BACKEND_ENV)
            .ok()
            .filter(|value| !value.trim().is_empty())
    })
    .as_deref()
}

/// Whether the per-frame cost recorder is on, from `set_frame_cost_recording`
/// or `CALLY_RENDER_COST` (read once per process).
fn frame_cost_env_enabled() -> bool {
    static ENV: OnceLock<bool> = OnceLock::new();
    *ENV.get_or_init(|| {
        std::env::var(FRAME_COST_ENV)
            .map(|value| {
                matches!(
                    value.trim().to_ascii_lowercase().as_str(),
                    "1" | "true" | "yes" | "on"
                )
            })
            .unwrap_or(false)
    })
}

thread_local! {
    /// The in-process override. Thread-scoped for the same reason as the
    /// view-cull switch: the render loop owns its thread, and a test's two
    /// measurement windows must not mix. `Cell` because it is read once per
    /// frame and holds a two-byte value.
    static OVERRIDE: Cell<Option<RenderBackend>> = const { Cell::new(None) };

    /// Recorder gate for this thread: `None` until `CALLY_RENDER_COST` has been
    /// consulted, then the in-process override if one was set.
    static COST_ENABLED: Cell<Option<bool>> = const { Cell::new(None) };

    /// Per-backend per-frame samples, thread-scoped like the switch itself.
    static COST: Cell<[BackendFrameCost; 2]> = const { Cell::new([BackendFrameCost::EMPTY; 2]) };
}

/// The in-process override, `None` when the env var or the build default decides.
pub fn render_backend_override() -> Option<RenderBackend> {
    OVERRIDE.with(|c| c.get())
}

/// Set (or clear, with `None`) the in-process override on this thread.
///
/// Two callers: a same-process A/B (test or host), and the runtime *fallback* -
/// `set_render_backend(Some(RenderBackend::Software))` is how a caller steps back
/// onto the software rasterizer after a backend fails. Deciding *when* to take
/// that step needs a failure signal, which is slice 4's (the command backend's
/// own error path); this switch provides the lever, not the policy.
pub fn set_render_backend(backend: Option<RenderBackend>) {
    OVERRIDE.with(|c| c.set(backend));
}

/// What this process/thread currently selects, without judging whether the
/// backend is implemented: `Err` only for an unrecognised env value.
pub fn render_backend_config() -> Result<BackendResolution<'static>, UnknownBackendValue> {
    resolve_backend(render_backend_override(), backend_env_value())
}

/// The readiness probe: the selection *plus* whether the frame entry can run on
/// it. `Err(BackendRefusal::NotWired { .. })` is what a host wants to check
/// before it starts a render loop (the frame entry itself panics with the same
/// refusal).
pub fn render_backend_status() -> Result<BackendResolution<'static>, BackendRefusal> {
    let resolution = render_backend_config().map_err(BackendRefusal::UnknownValue)?;
    if !resolution.backend.is_wired() {
        return Err(BackendRefusal::NotWired { resolution });
    }
    Ok(resolution)
}

/// The frame entry's resolver: the selection, or a typed refusal as a panic.
fn resolve_render_backend_or_refuse() -> BackendResolution<'static> {
    match render_backend_config() {
        Ok(resolution) => resolution,
        Err(unknown) => BackendRefusal::UnknownValue(unknown).into_panic(),
    }
}

/// Per-frame composition cost, accumulated per backend.
///
/// This is the hook the A/B reads: the frame entry times every composition and
/// files the sample under the backend that produced it, so after slice 4 the
/// command backend's numbers land in the same table as software's and the
/// comparison is one env var apart - no second harness. The accounting is
/// thread-local `Cell` arithmetic (the view-cull counters' pattern) with no
/// allocation and no shared atomic, and it is off unless asked for, so the
/// default path pays one thread-local read per frame.
///
/// One caveat for whoever reads the numbers: a frame served from the
/// `RasterInputs` cache (`draw_frame_cached`) returns in ~0 ns and is recorded
/// like any other frame, so a scenario must be uniform in what it draws - the
/// A/B in `tests/render_backend_switch_perf.rs` walks uncached frames.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct BackendFrameCost {
    pub frames: u64,
    pub total_ns: u64,
    pub min_ns: u64,
    pub max_ns: u64,
}

impl BackendFrameCost {
    /// An empty accumulator (`min_ns` only becomes meaningful with a sample).
    pub const EMPTY: BackendFrameCost = BackendFrameCost {
        frames: 0,
        total_ns: 0,
        min_ns: 0,
        max_ns: 0,
    };

    /// Record one composition of `ns` nanoseconds.
    pub fn record(&mut self, ns: u64) {
        if self.frames == 0 || ns < self.min_ns {
            self.min_ns = ns;
        }
        if ns > self.max_ns {
            self.max_ns = ns;
        }
        self.frames += 1;
        self.total_ns += ns;
    }

    /// Mean ns/frame, `None` before the first sample.
    pub fn mean_ns(&self) -> Option<f64> {
        (self.frames > 0).then(|| self.total_ns as f64 / self.frames as f64)
    }

    pub const fn is_empty(&self) -> bool {
        self.frames == 0
    }
}

/// Whether the frame entry is timing its compositions on this thread.
pub fn frame_cost_recording_enabled() -> bool {
    COST_ENABLED.with(|c| match c.get() {
        Some(enabled) => enabled,
        None => {
            let enabled = frame_cost_env_enabled();
            c.set(Some(enabled));
            enabled
        }
    })
}

/// Turn the per-frame cost recorder on/off for this thread (an in-process
/// override of `CALLY_RENDER_COST`).
pub fn set_frame_cost_recording(enabled: bool) {
    COST_ENABLED.with(|c| c.set(Some(enabled)));
}

/// The samples recorded for one backend since the last reset.
pub fn backend_frame_cost(backend: RenderBackend) -> BackendFrameCost {
    COST.with(|c| c.get()[backend.index()])
}

/// Both backends' samples, in [`RenderBackend::ALL`] order.
pub fn backend_frame_costs() -> [BackendFrameCost; 2] {
    COST.with(|c| c.get())
}

/// Zero every sample (start of a measurement window).
pub fn reset_backend_frame_costs() {
    COST.with(|c| c.set([BackendFrameCost::EMPTY; 2]));
}

/// Frame-entry side of the hook: `None` (no clock read) unless recording.
fn render_backend_frame_cost_start() -> Option<Instant> {
    frame_cost_recording_enabled().then(Instant::now)
}

fn render_backend_frame_cost_end(backend: RenderBackend, started: Option<Instant>) {
    let Some(started) = started else { return };
    let ns = started.elapsed().as_nanos().min(u64::MAX as u128) as u64;
    COST.with(|c| {
        let mut costs = c.get();
        costs[backend.index()].record(ns);
        c.set(costs);
    });
}
