// ============================================================
// Command-side view culling: runtime switch and hit-rate counters
// ============================================================
//
// Contract: reconstruction/contracts/gpu-command-backend.md section 4 slice 2.
// The renderer emits every draw command of the room each frame (rm_level17: 806
// static quads) while the 448x252 view rect covers only ~71 of them, so the
// consumer rasterises ~90% commands that cannot put a pixel on the screen. The
// guard in `draw_ir_sprite` rejects those commands before the frame's atlas page
// and atlas are resolved and before the blit is entered.
//
// Pixel equivalence is constructive, not empirical: a command is rejected only
// when the box the blit itself clips against misses the framebuffer *and* the
// 32x32 placeholder this command would fall back to (missing sprite/page/atlas)
// misses it too. Both are exact "writes no pixel" conditions, so the raster
// output cannot change - which `tests/view_culling.rs` pins by rasterising the
// same real frames with the guard on and off, byte for byte.
//
// The counters exist because the equivalence gate alone does not prove the guard
// *fires*: a fast path that never matches anything passes it trivially.
// `sprite_tested` counts the real sprite commands whose geometry reached the
// guard and `sprite_culled` the ones it rejected, so the hit rate is measured on
// the real call parameters.
use std::cell::Cell;

/// Hit-rate counters for the view-culling guard, cumulative until
/// [`reset_view_cull_stats`]. Published once per rasterised frame, so a frame
/// served from the `RasterInputs` cache adds nothing.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct ViewCullStats {
    /// Every sprite command the consumer walked past in the ordered stream.
    pub sprite_commands: u64,
    /// ... that resolved to a real sprite with frames, i.e. whose geometry the
    /// guard could actually decide (the rest take the placeholder path).
    pub sprite_tested: u64,
    /// ... that the guard rejected as unobservable.
    pub sprite_culled: u64,
    /// ... that the guard *kept* even though their sprite box misses the
    /// framebuffer, because the 32x32 placeholder they would fall back to could
    /// land on it. This is the measured price of "宁可不漏剔，不可错剔": with the
    /// real assets every page resolves, so these commands draw nothing anyway.
    pub sprite_placeholder_kept: u64,
}

impl ViewCullStats {
    /// Commands whose geometry was decided and kept (the observable ones).
    pub fn sprite_kept(&self) -> u64 {
        self.sprite_tested.saturating_sub(self.sprite_culled)
    }

    /// Hit rate over the commands the guard could decide, `None` before it saw
    /// any. Reporting this as a fraction of *all* commands would understate the
    /// guard on rooms that draw sprites the raster has no frames for.
    pub fn sprite_hit_rate(&self) -> Option<f64> {
        (self.sprite_tested > 0)
            .then(|| self.sprite_culled as f64 / self.sprite_tested as f64)
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct ViewCullState {
    enabled: bool,
    stats: ViewCullStats,
}

impl ViewCullState {
    const fn new() -> Self {
        Self {
            enabled: true,
            stats: ViewCullStats {
                sprite_commands: 0,
                sprite_tested: 0,
                sprite_culled: 0,
                sprite_placeholder_kept: 0,
            },
        }
    }
}

thread_local! {
    /// The guard's switch and counters. Thread-scoped because the guard runs on
    /// the thread that owns the render loop: it keeps the per-command path free
    /// of shared atomics, and it keeps two concurrent measurement windows (a
    /// test's guard-on vs guard-off passes) from mixing into each other.
    static CULL: Cell<ViewCullState> = const { Cell::new(ViewCullState::new()) };
}

/// Whether the render loop runs the guard. On by default; the switch exists so
/// the A/B (guard on vs off) is measurable in one process on the same real
/// frames, and so a caller has a runtime fallback (contract slice 7).
pub fn view_cull_enabled() -> bool {
    CULL.with(|c| c.get().enabled)
}

/// Enable/disable the guard on this thread. Disabling it restores the
/// pre-slice-2 behaviour exactly (every sprite command reaches the rasterizer).
pub fn set_view_cull_enabled(enabled: bool) {
    CULL.with(|c| {
        let mut state = c.get();
        state.enabled = enabled;
        c.set(state);
    });
}

/// Hit-rate counters since the last reset, accumulated over rasterised frames.
pub fn view_cull_stats() -> ViewCullStats {
    CULL.with(|c| c.get().stats)
}

/// Zero the counters (start of a measurement window).
pub fn reset_view_cull_stats() {
    CULL.with(|c| {
        let mut state = c.get();
        state.stats = ViewCullStats::default();
        c.set(state);
    });
}

fn publish_view_cull_stats(stats: ViewCullStats) {
    if stats == ViewCullStats::default() {
        return;
    }
    CULL.with(|c| {
        let mut state = c.get();
        state.stats.sprite_commands += stats.sprite_commands;
        state.stats.sprite_tested += stats.sprite_tested;
        state.stats.sprite_culled += stats.sprite_culled;
        state.stats.sprite_placeholder_kept += stats.sprite_placeholder_kept;
        c.set(state);
    });
}
