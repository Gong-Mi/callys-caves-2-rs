// ============================================================
// GPU command list: the command model, its emitters, and the frame-end consumer
// ============================================================
//
// Contract: reconstruction/contracts/gpu-command-backend.md section 4 slice 1.
// Slice 2's `parts/view_cull.rs` guard sits at `draw_ir_sprite`'s entry and has
// already dropped every command that cannot put a pixel on the framebuffer; the
// emitters here take their data *downstream* of it, so the list carries exactly
// the commands the raster consumed as visible work - not the ~90% of the room's
// static layer that never reaches the blit (rm_level17: 806 commands/frame, 71
// in the 448x252 view rect, 735 of them rejected, contract section 3).
//
// Nothing in this file touches GL. A frame emits commands into a
// `GpuCommandList` *while* the software rasterizer draws the same frame, and
// `consume_command_list` turns the finished list into batch-run statistics plus
// the float[] vertex staging the spike measured (section 2 p4: staging must be
// float[], never a direct ByteBuffer - 10x on the placebo write probe). Slice 4
// is what submits the list; a list that never leaves the process is a pure
// description of the frame, which is why the equivalence gate is unchanged: the
// emitters copy numbers the raster has already computed and write nothing back.
//
// Observed while wiring this up (recorded, not changed): the raster's
// background blit applies `alpha` only and ignores `BackgroundCommand::color`,
// so a background command's blend is staged as the identity. Slice 4's
// per-pixel equivalence gate owns that question (contract section 5).
use callys_core::ir_scene::DrawPhase;

/// Which queue of the ordered stream emitted a command. Provenance and
/// statistics only: batching keys on the atlas page, not on the kind.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord)]
pub enum GpuCommandKind {
    Sprite,
    Tile,
    Background,
    /// One glyph of a `draw_text_gm` string.
    Glyph,
    /// Untextured: a healthbar segment, a particle, an outline, or the 32x32
    /// placeholder a command whose sprite/page/atlas does not resolve falls
    /// back to.
    Fill,
}

/// The atlas page a quad samples from: which atlas texture, which rectangle
/// inside it, and the texture's own pixel size. The size is carried because it
/// is the UV denominator the spike's staging used (`u = sx / page_w`), so the
/// staging stays comparable with section 2's numbers.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct AtlasPage {
    /// `TpagItem::tex_id` - the index into `GameState::atlases` (and, in slice
    /// 4, the GL texture).
    pub tex: usize,
    /// The sampled rectangle inside that atlas, in texels.
    pub rect: (u32, u32, u32, u32),
    /// The atlas texture's size, in texels.
    pub atlas: (u32, u32),
}

impl AtlasPage {
    /// Normalized UV of `src`'s corners on this page, in the vertex order the
    /// staging uses: (left, top), (right, top), (left, bottom), (right, bottom).
    pub fn uv_rect(&self, src: (u32, u32, u32, u32)) -> [(f32, f32); 4] {
        let (aw, ah) = (self.atlas.0.max(1) as f32, self.atlas.1.max(1) as f32);
        let (x, y, w, h) = src;
        let (u0, v0) = (x as f32 / aw, y as f32 / ah);
        let (u1, v1) = ((x + w) as f32 / aw, (y + h) as f32 / ah);
        [(u0, v0), (u1, v0), (u0, v1), (u1, v1)]
    }
}

/// A command's place in the painter order, copied verbatim from the
/// `DrawEmission` the raster consumed: the phase barrier (Room before Gui), the
/// original object depth, and the FIFO tie-break the ordered stream already
/// applied. Never recomputed here - the list has to be able to prove it is in
/// the same order the raster drew in.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct DepthSlot {
    pub phase: DrawPhase,
    pub depth: f64,
    pub emit_order: usize,
}

/// Per-quad paint state, exactly the arguments the blit was called with.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct GpuPaint {
    pub alpha: f32,
    /// GM `image_blend` as RGB (channel-wise multiply; (255,255,255) is the
    /// identity the 4-argument `draw_sprite` default lands on).
    pub blend: (u8, u8, u8),
    /// `d3d_set_fog(true, c, 0, 0)`: the quad keeps only its alpha silhouette,
    /// in this colour. Not expressible as a vertex tint - it replaces the
    /// texture colour instead of multiplying it - so it breaks a batch run.
    pub flood: Option<(u8, u8, u8)>,
}

impl Default for GpuPaint {
    fn default() -> Self {
        Self { alpha: 1.0, blend: (255, 255, 255), flood: None }
    }
}

/// Destination geometry of a textured quad, in the exact form the raster's
/// blit takes it - so slice 4's per-pixel gate can start from the raster's own
/// parameters instead of a re-derivation.
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum GpuQuadDst {
    /// `blit_scaled` / `blit_scaled_alpha` / `blit_glyph_gm`: an axis-aligned
    /// destination rectangle in framebuffer pixels.
    Rect { x: i32, y: i32, w: u32, h: u32, flip_x: bool },
    /// `blit_sprite_gm`: the sprite canvas anchored on its SPRT origin, scaled
    /// (`scale.0 < 0` is the original's mirror), rotated about that origin and
    /// placed at `anchor` - all in the raster's own f64 numbers.
    Sprite {
        anchor: (f64, f64),
        canvas: (u32, u32),
        origin: (i32, i32),
        scale: (f64, f64),
        rotation_deg: f64,
    },
}

impl GpuQuadDst {
    /// The quad's four screen-space corners, in the raster's own corner order:
    /// sprite-local (0,0), (cw,0), (0,ch), (cw,ch). The projection is the one
    /// `sprite_screen_rect` spells out (f64 transform, f32 result, rotation
    /// clockwise in screen coordinates because y grows downward), so the
    /// consumer's box and the blit's clip box cannot drift apart - which
    /// `gpu_commands_tests::corners_match_the_blits_own_clip_box` pins against
    /// the real helper.
    pub fn corners(&self) -> [(f32, f32); 4] {
        match *self {
            GpuQuadDst::Rect { x, y, w, h, .. } => {
                let (x0, y0) = (x as f32, y as f32);
                let (x1, y1) = ((x as i64 + w as i64) as f32, (y as i64 + h as i64) as f32);
                [(x0, y0), (x1, y0), (x0, y1), (x1, y1)]
            }
            GpuQuadDst::Sprite { anchor, canvas, origin, scale, rotation_deg } => {
                let (cw, ch) = (canvas.0 as f64, canvas.1 as f64);
                let (ox, oy) = (origin.0 as f64, origin.1 as f64);
                if rotation_deg == 0.0 {
                    [(0.0, 0.0), (cw, 0.0), (0.0, ch), (cw, ch)].map(|(u, v)| {
                        (
                            (anchor.0 + (u - ox) * scale.0) as f32,
                            (anchor.1 + (v - oy) * scale.1) as f32,
                        )
                    })
                } else {
                    let angle = (rotation_deg as f32).to_radians();
                    let (sin, cos) = (angle.sin(), angle.cos());
                    [(0.0, 0.0), (cw, 0.0), (0.0, ch), (cw, ch)].map(|(u, v)| {
                        let lx = (u - ox) * scale.0;
                        let ly = (v - oy) * scale.1;
                        let rx = lx * cos as f64 + ly * sin as f64;
                        let ry = -lx * sin as f64 + ly * cos as f64;
                        ((anchor.0 + rx) as f32, (anchor.1 + ry) as f32)
                    })
                }
            }
        }
    }

    /// The quad's axis-aligned screen bounds, unclipped: `(min_x, min_y,
    /// max_x, max_y)`. Clipping is the consumer's business - a command that
    /// straddles the framebuffer edge is emitted and staged with its full box,
    /// because that is the only form slice 4's rasterizer can compare against.
    pub fn bounds(&self) -> (f32, f32, f32, f32) {
        let c = self.corners();
        let min_x = c.iter().map(|p| p.0).fold(f32::INFINITY, f32::min);
        let max_x = c.iter().map(|p| p.0).fold(f32::NEG_INFINITY, f32::max);
        let min_y = c.iter().map(|p| p.1).fold(f32::INFINITY, f32::min);
        let max_y = c.iter().map(|p| p.1).fold(f32::NEG_INFINITY, f32::max);
        (min_x, min_y, max_x, max_y)
    }
}

/// What a command draws.
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum GpuBody {
    /// A textured quad: atlas page, source rectangle inside the texture, and
    /// destination geometry.
    Quad { page: AtlasPage, src: (u32, u32, u32, u32), dst: GpuQuadDst, paint: GpuPaint },
    /// Untextured axis-aligned fill: exactly the pixels `fill_rect` writes
    /// (healthbar segments, particles, a sprite command's fallback placeholder).
    Fill { rect: (i32, i32, u32, u32), rgba: (u8, u8, u8, u8) },
    /// Untextured 1px border: exactly the pixels `draw_rect` writes (the
    /// healthbar frame).
    Outline { rect: (i32, i32, u32, u32), rgba: (u8, u8, u8, u8) },
}

/// One entry of the frame's command list.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct GpuCommand {
    pub kind: GpuCommandKind,
    pub slot: DepthSlot,
    pub body: GpuBody,
}

/// One frame's commands, in the order the raster consumed them.
///
/// The emitters are the *only* way in, and each mirrors one blit call site, so
/// a reviewer can check the list against the raster call by call. Emission is
/// opt-in: `draw_frame` passes no list and therefore pays nothing (not even the
/// empty-Vec check per command).
#[derive(Clone, Debug, Default)]
pub struct GpuCommandList {
    commands: Vec<GpuCommand>,
}

impl GpuCommandList {
    pub fn new() -> Self {
        Self { commands: Vec::new() }
    }

    /// Drop the previous frame's commands (each frame emits its own list).
    pub fn clear(&mut self) {
        self.commands.clear();
    }

    pub fn commands(&self) -> &[GpuCommand] {
        &self.commands
    }

    pub fn len(&self) -> usize {
        self.commands.len()
    }

    pub fn is_empty(&self) -> bool {
        self.commands.is_empty()
    }

    /// Reserve room for a frame of `n` commands, so the first frame after a
    /// clear does not grow the Vec inside the frame's raster profile.
    pub fn reserve(&mut self, n: usize) {
        self.commands.reserve(n);
    }

    fn push(&mut self, kind: GpuCommandKind, slot: DepthSlot, body: GpuBody) {
        self.commands.push(GpuCommand { kind, slot, body });
    }

    /// A sprite command the raster *drew*: one call of
    /// `Framebuffer::blit_sprite_gm`. Emitted after the slice-2 guard kept it,
    /// after its atlas page and atlas resolved and after the alpha test, so
    /// there is exactly one quad here per blit call.
    pub fn emit_sprite(
        &mut self,
        slot: DepthSlot,
        page: AtlasPage,
        src: (u32, u32, u32, u32),
        dst: GpuQuadDst,
        paint: GpuPaint,
    ) {
        self.push(GpuCommandKind::Sprite, slot, GpuBody::Quad { page, src, dst, paint });
    }

    /// A room tile the raster *drew* (one `blit_scaled` under `draw_tile`).
    /// Tiles carry no blend, flood or rotation: `draw_tile` passes `flip_x =
    /// false` and alpha 1.0, and rm_level17 has no tiles at all (contract
    /// section 3) - the emitter exists so the model is complete, not because
    /// this room exercises it.
    pub fn emit_tile(
        &mut self,
        slot: DepthSlot,
        page: AtlasPage,
        src: (u32, u32, u32, u32),
        dst: GpuQuadDst,
    ) {
        self.push(
            GpuCommandKind::Tile,
            slot,
            GpuBody::Quad { page, src, dst, paint: GpuPaint::default() },
        );
    }

    /// A background the raster *drew* (one `blit_scaled_alpha` in the
    /// `DrawQueue::Background` arm). `paint.alpha` is the command's clamped
    /// alpha; the blend stays the identity because the raster ignores
    /// `BackgroundCommand::color` (see the module note).
    pub fn emit_background(
        &mut self,
        slot: DepthSlot,
        page: AtlasPage,
        src: (u32, u32, u32, u32),
        dst: GpuQuadDst,
        paint: GpuPaint,
    ) {
        self.push(GpuCommandKind::Background, slot, GpuBody::Quad { page, src, dst, paint });
    }

    /// One glyph of an original FONT string: one call of
    /// `Framebuffer::blit_glyph_gm`, whose caller (`draw_text_gm`) already
    /// resolved the pen position, the glyph's box inside the font page and the
    /// screen-space `scale`. The glyph's own alpha channel carries the
    /// antialiased coverage; `paint.blend` is the `draw_set_color` tint.
    ///
    /// The integer source mapping `blit_glyph_gm` uses (`src = page + ox * gw /
    /// dw`) is *not* a linear UV map; the model records the box and the staging
    /// records its corners, and slice 4's per-pixel gate is what has to choose
    /// between reproducing the integer rule and GL_NEAREST sampling (contract
    /// section 5).
    pub fn emit_glyph(
        &mut self,
        slot: DepthSlot,
        page: AtlasPage,
        src: (u32, u32, u32, u32),
        dst: GpuQuadDst,
        paint: GpuPaint,
    ) {
        self.push(GpuCommandKind::Glyph, slot, GpuBody::Quad { page, src, dst, paint });
    }

    /// An untextured fill (one `fill_rect`).
    pub fn emit_fill(&mut self, slot: DepthSlot, rect: (i32, i32, u32, u32), rgba: (u8, u8, u8, u8)) {
        self.push(GpuCommandKind::Fill, slot, GpuBody::Fill { rect, rgba });
    }

    /// An untextured 1px border (one `draw_rect`).
    pub fn emit_outline(
        &mut self,
        slot: DepthSlot,
        rect: (i32, i32, u32, u32),
        rgba: (u8, u8, u8, u8),
    ) {
        self.push(GpuCommandKind::Fill, slot, GpuBody::Outline { rect, rgba });
    }
}

/// A maximal run of commands one draw call can carry: same provenance kind,
/// same atlas texture and same fog state, *consecutive* in the painter order.
///
/// Nothing here sorts. Contract section 3: the room's static layer paints
/// 1424 quads in object-depth order and two of them can overlap, so a
/// page-sorted list would reorder them and change the pixels; the only batching
/// a depth-ordered backend may do is merge runs that were already adjacent
/// (`page_runs = 55` for the whole static layer, `9` for the 71 in-view quads).
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct GpuBatchRun {
    pub kind: GpuCommandKind,
    /// The atlas texture, `None` for untextured commands.
    pub tex: Option<usize>,
    /// Index of the run's first command in `GpuCommandList::commands`.
    pub first: usize,
    /// Commands in the run.
    pub len: usize,
}

/// Command counts per provenance kind.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct GpuKindCounts {
    pub sprite: usize,
    pub tile: usize,
    pub background: usize,
    pub glyph: usize,
    /// Every untextured command: fills *and* outlines.
    pub fill: usize,
}

/// What one frame's command list comes to, for the consumer that will submit it.
#[derive(Clone, Debug, Default)]
pub struct GpuFrameStats {
    pub commands: usize,
    pub quads: usize,
    pub fills: usize,
    pub outlines: usize,
    pub counts: GpuKindCounts,
    /// Textured quads x 4.
    pub vertices: usize,
    /// Textured quads x 32 (4 vertices x 8 floats).
    pub staging_floats: usize,
    pub staging_bytes: usize,
    /// Consecutive same-atlas-texture runs over the whole list - the number the
    /// census' `page_runs` counts, so it is comparable with contract section 3
    /// (55 whole static layer / 9 in-view).
    pub page_runs: usize,
    /// The real draw-call count: the same consecutive runs under the full batch
    /// key (`kind`, `tex`, fog state).
    pub runs: Vec<GpuBatchRun>,
    /// Commands whose screen box intersects the viewport. Not a cull: this is
    /// the consumer's own measurement of how much of the list is on screen.
    pub in_view_quads: usize,
    pub in_view_fills: usize,
    pub in_view_page_runs: usize,
    /// Vertex staging, float[] per contract section 2 p4: 4 vertices per quad,
    /// 8 floats per vertex (x, y, u, v, r, g, b, a), corners in the raster's
    /// order (tl, tr, bl, br), uv normalized by the atlas texture size.
    pub staging: Vec<f32>,
}

impl GpuFrameStats {
    pub fn draw_calls(&self) -> usize {
        self.runs.len()
    }
}

/// The batch key a run breaks on. `GpuQuadDst` deliberately does *not* appear:
/// the consumer expands both destination forms into the same 8-float vertex
/// layout, so a rotated sprite quad and a rect quad on the same page are one
/// draw. Alpha and blend are per-vertex too. Fog is a shader-state change.
fn batch_key(cmd: &GpuCommand) -> (GpuCommandKind, Option<usize>, bool) {
    match cmd.body {
        GpuBody::Quad { page, paint, .. } => (cmd.kind, Some(page.tex), paint.flood.is_some()),
        GpuBody::Fill { .. } | GpuBody::Outline { .. } => (cmd.kind, None, false),
    }
}

/// The page-only key the census counts runs with.
fn page_key(cmd: &GpuCommand) -> Option<usize> {
    match cmd.body {
        GpuBody::Quad { page, .. } => Some(page.tex),
        GpuBody::Fill { .. } | GpuBody::Outline { .. } => None,
    }
}

/// Whether a command's screen box intersects the viewport. A box that straddles
/// the edge counts as inside, which is the same "writes a pixel" direction
/// slice 2's guard takes.
fn in_view(cmd: &GpuCommand, viewport: (u32, u32)) -> bool {
    let (w, h) = (viewport.0 as f32, viewport.1 as f32);
    let (x0, y0, x1, y1) = match cmd.body {
        GpuBody::Quad { dst, .. } => dst.bounds(),
        GpuBody::Fill { rect, .. } | GpuBody::Outline { rect, .. } => {
            let (x, y, rw, rh) = rect;
            (x as f32, y as f32, (x as i64 + rw as i64) as f32, (y as i64 + rh as i64) as f32)
        }
    };
    x1 > 0.0 && x0 < w && y1 > 0.0 && y0 < h
}

/// Consume one frame's command list: batch-run statistics plus the float[]
/// vertex staging a GL submission would upload.
///
/// This is the only place the list is interpreted, and it is deliberately
/// read-only: `staging` is sized from the quad count, and the runs are built in
/// one pass in painter order - the list is never sorted.
pub fn consume_command_list(list: &GpuCommandList, viewport: (u32, u32)) -> GpuFrameStats {
    let cmds = list.commands();
    let mut stats = GpuFrameStats { commands: cmds.len(), ..Default::default() };
    let mut last_batch: Option<(GpuCommandKind, Option<usize>, bool)> = None;
    let mut last_page: Option<Option<usize>> = None;
    let mut last_in_view_page: Option<Option<usize>> = None;
    for (i, cmd) in cmds.iter().enumerate() {
        match cmd.kind {
            GpuCommandKind::Sprite => stats.counts.sprite += 1,
            GpuCommandKind::Tile => stats.counts.tile += 1,
            GpuCommandKind::Background => stats.counts.background += 1,
            GpuCommandKind::Glyph => stats.counts.glyph += 1,
            GpuCommandKind::Fill => stats.counts.fill += 1,
        }
        match cmd.body {
            GpuBody::Quad { .. } => stats.quads += 1,
            GpuBody::Fill { .. } => stats.fills += 1,
            GpuBody::Outline { .. } => stats.outlines += 1,
        }
        let key = batch_key(cmd);
        match stats.runs.last_mut() {
            Some(run) if last_batch == Some(key) => run.len += 1,
            _ => {
                stats.runs.push(GpuBatchRun { kind: key.0, tex: key.1, first: i, len: 1 });
                last_batch = Some(key);
            }
        }
        let page = page_key(cmd);
        if last_page != Some(page) {
            stats.page_runs += 1;
            last_page = Some(page);
        }
        if in_view(cmd, viewport) {
            match cmd.body {
                GpuBody::Quad { .. } => stats.in_view_quads += 1,
                GpuBody::Fill { .. } | GpuBody::Outline { .. } => stats.in_view_fills += 1,
            }
            if last_in_view_page != Some(page) {
                stats.in_view_page_runs += 1;
                last_in_view_page = Some(page);
            }
        }
    }
    let staged = stats.quads * 32;
    stats.vertices = stats.quads * 4;
    stats.staging_floats = staged;
    stats.staging_bytes = staged * std::mem::size_of::<f32>();
    if staged > 0 {
        stats.staging.reserve(staged);
    }
    for cmd in cmds {
        if let GpuBody::Quad { page, src, dst, paint } = cmd.body {
            let uv = page.uv_rect(src);
            let (r, g, b) = match paint.flood {
                Some(c) => c,
                None => paint.blend,
            };
            let (r, g, b, a) = (
                r as f32 / 255.0,
                g as f32 / 255.0,
                b as f32 / 255.0,
                paint.alpha.clamp(0.0, 1.0),
            );
            for (corner, uv) in dst.corners().iter().zip(uv.iter()) {
                stats.staging.extend_from_slice(&[corner.0, corner.1, uv.0, uv.1, r, g, b, a]);
            }
        }
    }
    debug_assert_eq!(stats.staging.len(), staged);
    stats
}

#[cfg(test)]
mod gpu_commands_tests {
    use super::*;

    /// The command model's quad projection and the blit's own clip box must
    /// agree bit for bit: `sprite_screen_rect` is what the raster clips against
    /// (and what the slice-2 guard decides on), so a command whose bounds are
    /// derived differently could disagree with the pixels. The cases are the
    /// helper's own: rotations, mirrors (negative scale), a sprite origin
    /// outside the canvas, degenerate canvas sizes.
    #[test]
    fn corners_match_the_blits_own_clip_box() {
        const FB: (u32, u32) = (1136, 640);
        type Case = (f64, (u32, u32), (i32, i32), (f64, f64), (f64, f64));
        let cases: [Case; 14] = [
            (0.0, (32, 48), (16, 24), (600.0, 300.0), (2.5357, 2.5397)),
            (0.0, (32, 48), (16, 24), (0.0, 0.0), (1.0, 1.0)),
            (0.0, (32, 48), (16, 24), (-16.0, 300.0), (1.0, 1.0)),
            (0.0, (32, 48), (16, 24), (1136.0, 300.0), (1.0, 1.0)),
            (0.0, (32, 48), (16, 24), (600.0, -24.0), (1.0, 1.0)),
            (0.0, (8, 8), (0, 0), (300.0, 120.0), (0.5, 0.5)),
            (0.0, (8, 8), (4, 4), (300.0, 120.0), (-1.0, 1.0)),
            (45.0, (32, 48), (16, 24), (600.0, 300.0), (1.0, 1.0)),
            (90.0, (64, 16), (32, 8), (200.0, 400.0), (3.0, 1.5)),
            (-30.0, (32, 48), (16, 24), (1000.0, 600.0), (1.0, 1.0)),
            (180.0, (32, 48), (0, 0), (500.0, 300.0), (1.0, 1.0)),
            (0.0, (4, 4), (2, 2), (0.5, 0.5), (1.0, 1.0)),
            (12.5, (128, 128), (64, 64), (560.0, 320.0), (2.0, 2.0)),
            (0.0, (16, 16), (16, 16), (1135.0, 639.0), (1.0, 1.0)),
        ];
        for (i, (rot, canvas, origin, anchor, scale)) in cases.iter().enumerate() {
            let dst = GpuQuadDst::Sprite {
                anchor: *anchor,
                canvas: *canvas,
                origin: *origin,
                scale: *scale,
                rotation_deg: *rot,
            };
            let expected = crate::sprite_screen_rect(
                FB.0,
                FB.1,
                (canvas.0 as f64, canvas.1 as f64),
                (origin.0 as f64, origin.1 as f64),
                *anchor,
                *scale,
                *rot,
            );
            let (min_x, min_y, max_x, max_y) = dst.bounds();
            let got = {
                let x0 = min_x.floor().max(0.0) as i32;
                let y0 = min_y.floor().max(0.0) as i32;
                let x1 = max_x.ceil().min(FB.0 as f32 - 1.0) as i32;
                let y1 = max_y.ceil().min(FB.1 as f32 - 1.0) as i32;
                if x1 < x0 || y1 < y0 { None } else { Some((x0, y0, x1, y1)) }
            };
            assert_eq!(got, expected, "case {i}: the model's box must be the blit's box");
            // The corner order has to be the raster's: (0,0), (cw,0), (0,ch), (cw,ch).
            let c = dst.corners();
            if *rot == 0.0 {
                let (cw, ch) = (canvas.0 as f64, canvas.1 as f64);
                let (ox, oy) = (origin.0 as f64, origin.1 as f64);
                let project = |u: f64, v: f64| {
                    ((anchor.0 + (u - ox) * scale.0) as f32, (anchor.1 + (v - oy) * scale.1) as f32)
                };
                assert_eq!(c, [project(0.0, 0.0), project(cw, 0.0), project(0.0, ch), project(cw, ch)]);
            }
        }
    }

    /// Untextured commands carry no page and never join a textured run: a fill
    /// between two quads of the same page splits the page run, so the batcher
    /// cannot claim two draws where the raster interleaved a rectangle.
    #[test]
    fn untextured_commands_break_page_runs() {
        let mut list = GpuCommandList::new();
        let slot = DepthSlot { phase: DrawPhase::Room, depth: 0.0, emit_order: 0 };
        let page = AtlasPage { tex: 1, rect: (0, 0, 8, 8), atlas: (512, 512) };
        let rect = GpuQuadDst::Rect { x: 0, y: 0, w: 8, h: 8, flip_x: false };
        list.emit_sprite(slot, page, (0, 0, 8, 8), rect, GpuPaint::default());
        list.emit_fill(slot, (0, 0, 4, 4), (1, 2, 3, 255));
        list.emit_sprite(slot, page, (0, 0, 8, 8), rect, GpuPaint::default());
        let stats = consume_command_list(&list, (64, 64));
        assert_eq!(stats.page_runs, 3);
        assert_eq!(stats.draw_calls(), 3);
        assert_eq!(stats.quads, 2);
        assert_eq!(stats.fills, 1);
        assert_eq!(stats.counts.fill, 1);
    }

    /// A rotated quad's staging must be the rotated corners, not its axis-aligned
    /// box: slice 4 compares against the raster per pixel, so the geometry that
    /// reaches it has to be the geometry the blit projected.
    #[test]
    fn rotated_quads_stage_their_rotated_corners() {
        let mut list = GpuCommandList::new();
        let slot = DepthSlot { phase: DrawPhase::Room, depth: 0.0, emit_order: 0 };
        list.emit_sprite(
            slot,
            AtlasPage { tex: 0, rect: (0, 0, 100, 100), atlas: (100, 100) },
            (0, 0, 100, 100),
            GpuQuadDst::Sprite {
                anchor: (400.0, 300.0),
                canvas: (10, 10),
                origin: (5, 5),
                scale: (2.0, 2.0),
                rotation_deg: 90.0,
            },
            GpuPaint::default(),
        );
        let stats = consume_command_list(&list, (1136, 640));
        // A 20x20 box centred on (400,300), rotated 90 degrees clockwise in
        // screen coordinates (y down): the local corners (0,0), (cw,0), (0,ch),
        // (cw,ch) land at (390,310), (390,290), (410,310), (410,290).
        let corner = |i: usize| (stats.staging[i * 8], stats.staging[i * 8 + 1]);
        let want = [(390.0, 310.0), (390.0, 290.0), (410.0, 310.0), (410.0, 290.0)];
        for (i, w) in want.iter().enumerate() {
            let got = corner(i);
            assert!(
                (got.0 - w.0).abs() < 0.01 && (got.1 - w.1).abs() < 0.01,
                "vertex {i}: got {got:?}, want {w:?}",
            );
        }
    }
}
