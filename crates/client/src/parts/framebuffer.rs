// ============================================================
// Software-rasterized framebuffer
// ============================================================

pub struct Framebuffer {
    pub width: u32,
    pub height: u32,
    pub pixels: Vec<u8>, // BGRA8888, row-major (fill_rect writes [B, G, R, A]; the Java int[] view reads the same 4 bytes as 0xAARRGGBB)
}

impl Framebuffer {
    pub fn new(width: u32, height: u32) -> Self {
        Self {
            width,
            height,
            pixels: vec![0u8; (width * height * 4) as usize],
        }
    }

    /// Copy the frame into the ARGB int array the Java presenter uploads.
    ///
    /// The buffer is BGRA8888 and a little-endian ARGB int holds exactly those
    /// same four bytes, so this is a byte-identical bulk copy of what the
    /// per-pixel repack in `nativeBlitToIntArray` used to rebuild by hand. That
    /// repack cost ~0.6 ms per frame and allocated a second 2.9 MB buffer for a
    /// transformation that changes nothing (see the equivalence test below).
    pub fn pack_into_i32(&self, out: &mut Vec<i32>) {
        let n = self.pixels.len() / 4;
        out.clear();
        out.reserve(n);
        // SAFETY: every 4-byte chunk of `pixels` is a valid i32 under the
        // little-endian layout above, `out` has room for n elements, and the
        // length is only published once the bytes are written.
        unsafe {
            std::ptr::copy_nonoverlapping(
                self.pixels.as_ptr(),
                out.as_mut_ptr() as *mut u8,
                n * 4,
            );
            out.set_len(n);
        }
    }

    fn put(&mut self, x: i32, y: i32, color: (u8, u8, u8, u8)) {
        if x < 0 || y < 0 {
            return;
        }
        let (x, y) = (x as u32, y as u32);
        if x >= self.width || y >= self.height {
            return;
        }
        let i = ((y * self.width + x) * 4) as usize;
        self.pixels[i] = color.2;     // B
        self.pixels[i + 1] = color.1; // G
        self.pixels[i + 2] = color.0; // R
        self.pixels[i + 3] = color.3; // A
    }

    /// Source-alpha blend onto the current pixel (GM draw alpha semantics).
    fn put_blended(&mut self, x: i32, y: i32, color: (u8, u8, u8, u8), alpha: f32) {
        if x < 0 || y < 0 {
            return;
        }
        let (x, y) = (x as u32, y as u32);
        if x >= self.width || y >= self.height {
            return;
        }
        let a = alpha.clamp(0.0, 1.0);
        if a >= 1.0 {
            self.put(x as i32, y as i32, color);
            return;
        }
        let i = ((y * self.width + x) * 4) as usize;
        let blend = |src: u8, dst: u8| -> u8 {
            (src as f32 * a + dst as f32 * (1.0 - a)).round() as u8
        };
        self.pixels[i] = blend(color.2, self.pixels[i]);
        self.pixels[i + 1] = blend(color.1, self.pixels[i + 1]);
        self.pixels[i + 2] = blend(color.0, self.pixels[i + 2]);
        self.pixels[i + 3] = color.3.max(self.pixels[i + 3]);
    }

    fn fill_rect(&mut self, x: i32, y: i32, w: u32, h: u32, color: (u8, u8, u8, u8)) {
        if w == 0 || h == 0 {
            return;
        }
        let x0 = x.max(0) as u32;
        let y0 = y.max(0) as u32;
        let x1 = (x.saturating_add(w as i32)).min(self.width as i32).max(0) as u32;
        let y1 = (y.saturating_add(h as i32)).min(self.height as i32).max(0) as u32;
        if x1 <= x0 || y1 <= y0 {
            return;
        }
        let pattern = [color.2, color.1, color.0, color.3];
        let stride = self.width as usize * 4;
        for yy in y0..y1 {
            let row_start = yy as usize * stride;
            let row =
                &mut self.pixels[row_start + (x0 as usize) * 4..row_start + (x1 as usize) * 4];
            for px in row.chunks_exact_mut(4) {
                px.copy_from_slice(&pattern);
            }
        }
    }

    fn draw_rect(&mut self, x: i32, y: i32, w: u32, h: u32, color: (u8, u8, u8, u8)) {
        if w == 0 || h == 0 {
            return;
        }
        let x1 = x + w as i32 - 1;
        let y1 = y + h as i32 - 1;
        for xi in x..=x1 {
            self.put(xi, y, color);
            self.put(xi, y1, color);
        }
        for yi in y..=y1 {
            self.put(x, yi, color);
            self.put(x1, yi, color);
        }
    }

    /// One glyph of an original GM font, blitted from the font's atlas page.
    /// `page` is the font's TpagItem rect on the atlas; `(gx, gy)` are the
    /// glyph's coordinates inside that page (probed Gill Sans geometry). The
    /// glyph's own alpha channel carries the antialiased coverage, the draw
    /// colour multiplies channel-wise (GM `draw_set_color` on fonts) and
    /// `draw_alpha` scales coverage further. `scale` is the screen-space
    /// stretch applied to every glyph box (nearest neighbour, like the other
    /// blits). Returns the glyph's advance (`shift`) in scaled pixels.
    fn blit_glyph_gm(
        &mut self,
        atlas: &RgbaImage,
        page: (u32, u32),
        glyph: &callys_asset::GlyphData,
        x: i32,
        y: i32,
        scale: f32,
        color: (u8, u8, u8),
        alpha: f32,
    ) -> u32 {
        let gw = glyph.w as u32;
        let gh = glyph.h as u32;
        if gw == 0 || gh == 0 {
            return ((glyph.shift as f32) * scale).round() as u32;
        }
        let dw = ((gw as f32) * scale).round() as u32;
        let dh = ((gh as f32) * scale).round() as u32;
        for oy in 0..dh {
            let py = y + oy as i32;
            if py < 0 || py >= self.height as i32 {
                continue;
            }
            let src_y = page.1 + glyph.y as u32 + oy * gh / dh;
            for ox in 0..dw {
                let px = x + ox as i32;
                if px < 0 || px >= self.width as i32 {
                    continue;
                }
                let src_x = page.0 + glyph.x as u32 + ox * gw / dw;
                if src_x >= atlas.width() || src_y >= atlas.height() {
                    continue;
                }
                let rgba = atlas.get_pixel(src_x, src_y).0;
                if rgba[3] == 0 {
                    continue;
                }
                // Coverage from the glyph's antialiased alpha, times the
                // command's draw alpha. GM font draws are premultiplied by
                // nothing: the colour comes from draw_set_color.
                let cov = (rgba[3] as f32 / 255.0) * alpha.clamp(0.0, 1.0);
                if cov <= 0.0 {
                    continue;
                }
                let tint = (
                    ((color.0 as f32) * cov).round() as u8,
                    ((color.1 as f32) * cov).round() as u8,
                    ((color.2 as f32) * cov).round() as u8,
                    (cov * 255.0).round() as u8,
                );
                self.put_blended(px, py, tint, cov);
            }
        }
        ((glyph.shift as f32) * scale).round() as u32
    }

    /// A string in one of the original fonts. The pen starts at `(x, y)` — the
    /// top of the line box — and advances by each glyph's `shift` (probed
    /// box model: all ascent inks start 9px down inside their boxes,
    /// descender boxes are taller, so no per-glyph vertical offset exists).
    /// Characters outside the font's 96-glyph ASCII table are skipped by
    /// advancing one space width. Falls back to nothing when the font or its
    /// atlas is missing (the caller decides on a fallback).
    fn draw_text_gm(
        &mut self,
        atlas: &RgbaImage,
        page: (u32, u32),
        glyphs: &[callys_asset::GlyphData],
        space_shift: u16,
        x: i32,
        y: i32,
        text: &str,
        scale: f32,
        color: (u8, u8, u8),
        alpha: f32,
    ) {
        let mut pen = x;
        for ch in text.chars() {
            if ch == '\n' {
                continue;
            }
            let code = ch as u32;
            if !(32..=127).contains(&code) {
                pen += ((space_shift as f32) * scale).round() as i32;
                continue;
            }
            let glyph = glyphs
                .iter()
                .find(|g| g.ch as u32 == code)
                .unwrap_or(&glyphs[0]);
            let adv = self.blit_glyph_gm(atlas, page, glyph, pen, y, scale, color, alpha);
            pen += adv as i32;
        }
    }

    fn blit_scaled(&mut self, atlas: &RgbaImage, src: (u32, u32, u32, u32), dst: (i32, i32, u32, u32), flip_x: bool) {
        self.blit_scaled_alpha(atlas, src, dst, flip_x, 1.0);
    }

    fn blit_scaled_alpha(&mut self, atlas: &RgbaImage, src: (u32, u32, u32, u32), dst: (i32, i32, u32, u32), flip_x: bool, alpha: f32) {
        let (sx, sy, sw, sh) = src;
        let (dx, dy, dw, dh) = dst;
        if sw == 0 || sh == 0 || dw == 0 || dh == 0 { return; }
        // Clip the destination band once. The per-pixel version below tested
        // every pixel against the framebuffer bounds; skipping the same pixels
        // up front is the same set, and it lets the inner loop index directly.
        let py0 = dy.max(0);
        let py1 = (dy + dh as i32).min(self.height as i32);
        let px0 = dx.max(0);
        let px1 = (dx + dw as i32).min(self.width as i32);
        if py0 >= py1 || px0 >= px1 { return; }
        let raw = atlas.as_raw();
        let atlas_w = atlas.width() as usize;
        let aw = atlas.width() as u64;
        let (sh64, dh64) = (sh as u64, dh as u64);
        let (sw64, dw64) = (sw as u64, dw as u64);
        let opaque = alpha >= 1.0;
        // Source row for the first visible scanline, then advanced by
        // incremental division: `row`/`rem` reproduce `oy * sh / dh` exactly
        // without a division per pixel.
        let oy0 = (py0 - dy) as u64;
        let mut row = sy as u64 + (oy0 * sh64) / dh64;
        let mut rem_y = (oy0 * sh64) % dh64;
        let fb_w = self.width as usize;
        for py in py0..py1 {
            if row < atlas.height() as u64 {
                let row_u32 = row as u32;
                let ox0 = (px0 - dx) as u64;
                let mut sample_x = (ox0 * sw64) / dw64;
                let mut rem_x = (ox0 * sw64) % dw64;
                let base = (py as usize) * fb_w * 4;
                for px in px0..px1 {
                    let src_x = sx as u64
                        + if flip_x { sw64 - 1 - sample_x } else { sample_x };
                    if src_x < aw {
                        let si = (row_u32 as usize * atlas_w + src_x as usize) * 4;
                        let rgba = [raw[si], raw[si + 1], raw[si + 2], raw[si + 3]];
                        if rgba[3] >= 16 {
                            // Per-pixel source alpha times draw alpha (GM image_blend alpha).
                            let color = (rgba[0], rgba[1], rgba[2], rgba[3]);
                            if opaque && rgba[3] == 255 {
                                // put() by hand: the destination index is known
                                // to be in range from the band clipped above.
                                let i = base + (px as usize) * 4;
                                self.pixels[i] = color.2;
                                self.pixels[i + 1] = color.1;
                                self.pixels[i + 2] = color.0;
                                self.pixels[i + 3] = color.3;
                            } else {
                                let combined = (rgba[3] as f32 / 255.0) * alpha;
                                self.put_blended(px, py, color, combined);
                            }
                        }
                    }
                    rem_x += sw64;
                    while rem_x >= dw64 {
                        rem_x -= dw64;
                        sample_x += 1;
                    }
                }
            }
            rem_y += sh64;
            while rem_y >= dh64 {
                rem_y -= dh64;
                row += 1;
            }
        }
    }

    /// One original sprite draw, in GameMaker's own terms: the instance position
    /// is where the SPRT origin lands, a negative axis is the original's facing
    /// mirror (`image_xscale = -1`), `image_angle` rotates counter-clockwise on
    /// screen about that same origin, and `blend` multiplies the sampled colour
    /// channel-wise (`image_blend`, c_white = identity). When `flood` is set the
    /// call sat inside `d3d_set_fog(true, c, 0, 0)`: fog start == end == 0 means
    /// the whole sprite is fogged, so the frame keeps only its alpha silhouette
    /// in the fog colour (this is the original's hit-flash trick).
    /// Sampling is nearest-neighbour, exactly like the other blits here.
    #[allow(clippy::too_many_arguments)]
    fn blit_sprite_gm(
        &mut self,
        atlas: &RgbaImage,
        src: (u32, u32, u32, u32),
        sprite_size: (f64, f64),
        sprite_origin: (f64, f64),
        dst_origin: (f64, f64),
        scale: (f64, f64),
        rotation_deg: f64,
        alpha: f32,
        blend: (u8, u8, u8),
        flood: Option<(u8, u8, u8)>,
    ) {
        let (sx, sy, sw, sh) = src;
        let (cw, ch) = sprite_size;
        if cw <= 0.0 || ch <= 0.0 || sw == 0 || sh == 0 { return; }
        if scale.0 == 0.0 || scale.1 == 0.0 { return; }
        let (ox, oy) = sprite_origin;
        let angle = (rotation_deg as f32).to_radians();
        let (sin, cos) = (angle.sin(), angle.cos());
        // Sprite-local (u, v) -> screen, all in one transform.
        let project = |u: f64, v: f64| -> (f32, f32) {
            let lx = (u - ox) * scale.0;
            let ly = (v - oy) * scale.1;
            let rx = lx * cos as f64 + ly * sin as f64;
            let ry = -lx * sin as f64 + ly * cos as f64;
            ((dst_origin.0 + rx) as f32, (dst_origin.1 + ry) as f32)
        };
        let corners = [project(0.0, 0.0), project(cw, 0.0), project(0.0, ch), project(cw, ch)];
        let min_x = corners.iter().map(|c| c.0).fold(f32::INFINITY, f32::min);
        let max_x = corners.iter().map(|c| c.0).fold(f32::NEG_INFINITY, f32::max);
        let min_y = corners.iter().map(|c| c.1).fold(f32::INFINITY, f32::min);
        let max_y = corners.iter().map(|c| c.1).fold(f32::NEG_INFINITY, f32::max);
        let x0 = min_x.floor().max(0.0) as i32;
        let y0 = min_y.floor().max(0.0) as i32;
        let x1 = max_x.ceil().min(self.width as f32 - 1.0) as i32;
        let y1 = max_y.ceil().min(self.height as f32 - 1.0) as i32;
        if x1 < x0 || y1 < y0 { return; }
        // Frame rect stretched onto the sprite canvas, so a frame smaller than
        // the canvas still anchors on the origin the way the hitboxes do.
        let (du, dv) = (sw as f64 / cw, sh as f64 / ch);
        // Exactly-equivalent fast path for the common case: axis-aligned, unit
        // scale (the original's own `image_xscale`/`image_yscale` = ±1), no fog
        // and identity blend. The inverse rotation is then the identity
        // transform (cos == 1, sin == 0 => lx = rx*1 - ry*0 == rx, ly == ry),
        // and dividing by ±1.0 is exact, so the per-pixel f64 rotation, its two
        // divisions and the three identity blend multiplies all drop out.
        // Sampling (`su`/`sv`), every bounds test, the alpha rules and the
        // writes are unchanged, so the produced bytes are identical.
        if rotation_deg == 0.0
            && (scale.0 == 1.0 || scale.0 == -1.0)
            && (scale.1 == 1.0 || scale.1 == -1.0)
            && flood.is_none()
            && blend == (255, 255, 255)
        {
            let (aw, ah) = (atlas.width(), atlas.height());
            let raw = atlas.as_raw();
            let atlas_w = aw as usize;
            for py in y0..=y1 {
                let ry = py as f64 + 0.5 - dst_origin.1;
                let v = if scale.1 == 1.0 { ry + oy } else { -ry + oy };
                if v < 0.0 || v >= ch { continue; }
                let sv_f = sy as f64 + v * dv;
                if sv_f < 0.0 { continue; }
                let sv = sv_f as u32;
                if sv >= ah { continue; }
                let srow = sv as usize * atlas_w;
                for px in x0..=x1 {
                    let rx = px as f64 + 0.5 - dst_origin.0;
                    let u = if scale.0 == 1.0 { rx + ox } else { -rx + ox };
                    if u < 0.0 || u >= cw { continue; }
                    let su_f = sx as f64 + u * du;
                    if su_f < 0.0 { continue; }
                    let su = su_f as u32;
                    if su >= aw { continue; }
                    let si = (srow + su as usize) * 4;
                    let rgba = [raw[si], raw[si + 1], raw[si + 2], raw[si + 3]];
                    if rgba[3] < 16 { continue; }
                    if alpha >= 1.0 && rgba[3] == 255 {
                        self.put(px, py, (rgba[0], rgba[1], rgba[2], rgba[3]));
                    } else {
                        let a = (rgba[3] as f32 / 255.0) * alpha;
                        if a <= 0.0 { continue; }
                        self.put_blended(px, py, (rgba[0], rgba[1], rgba[2], rgba[3]), a);
                    }
                }
            }
            return;
        }
        for py in y0..=y1 {
            for px in x0..=x1 {
                let rx = px as f64 + 0.5 - dst_origin.0;
                let ry = py as f64 + 0.5 - dst_origin.1;
                // Inverse rotation, then inverse scale: no rotation or mirror
                // is handled by the same arithmetic.
                let lx = rx * cos as f64 - ry * sin as f64;
                let ly = rx * sin as f64 + ry * cos as f64;
                let u = lx / scale.0 + ox;
                let v = ly / scale.1 + oy;
                if u < 0.0 || v < 0.0 || u >= cw || v >= ch { continue; }
                // `u`/`v` are already pixel centres in sprite space (the inverse
                // transform added the half-pixel), so they map straight onto the
                // frame rect; a second half-pixel here would sample one texel off.
                let su = sx as f64 + u * du;
                let sv = sy as f64 + v * dv;
                if su < 0.0 || sv < 0.0 { continue; }
                let su = su as u32;
                let sv = sv as u32;
                if su >= atlas.width() || sv >= atlas.height() { continue; }
                let rgba = atlas.get_pixel(su, sv).0;
                if rgba[3] < 16 { continue; }
                let (r, g, b) = match flood {
                    Some(c) => c,
                    None => (
                        (rgba[0] as u32 * blend.0 as u32 / 255) as u8,
                        (rgba[1] as u32 * blend.1 as u32 / 255) as u8,
                        (rgba[2] as u32 * blend.2 as u32 / 255) as u8,
                    ),
                };
                let a = (rgba[3] as f32 / 255.0) * alpha;
                if a <= 0.0 { continue; }
                self.put_blended(px, py, (r, g, b, rgba[3]), a);
            }
        }
    }

    pub fn draw_char(&mut self, x: i32, y: i32, c: char, scale: u32, color: (u8, u8, u8, u8)) -> u32 {
        let ascii = c as usize;
        if !(32..=126).contains(&ascii) {
            return 0;
        }
        let glyph = FONT_5X7[ascii - 32];
        for (col, &bits) in glyph.iter().enumerate() {
            for row in 0..7 {
                if (bits & (1 << row)) != 0 {
                    let px = x + (col as u32 * scale) as i32;
                    let py = y + (row as u32 * scale) as i32;
                    self.fill_rect(px, py, scale, scale, color);
                }
            }
        }
        (5 + 1) * scale
    }

    pub fn draw_text_str(&mut self, mut x: i32, mut y: i32, text: &str, scale: u32, color: (u8, u8, u8, u8)) {
        let start_x = x;
        for c in text.chars() {
            if c == '\n' {
                y += (7 + 2) * scale as i32;
                x = start_x;
            } else {
                let adv = self.draw_char(x, y, c, scale, color);
                x += adv as i32;
            }
        }
    }
}

#[cfg(test)]
mod framebuffer_pack_tests {
    use super::*;

    /// The array this produces is uploaded verbatim by the Java presenter, so
    /// dropping the per-pixel repack is only sound because a little-endian ARGB
    /// int is exactly the framebuffer's BGRA byte order. Assert the integer
    /// values *and* the underlying bytes so the assumption cannot rot silently.
    #[test]
    fn pack_into_i32_is_byte_identical_to_per_pixel_repack() {
        let mut fb = Framebuffer::new(9, 4);
        for (i, b) in fb.pixels.iter_mut().enumerate() {
            *b = ((i * 37 + 11) % 256) as u8;
        }
        let mut reference: Vec<i32> = Vec::new();
        for chunk in fb.pixels.chunks_exact(4) {
            let (b, g, r, a) = (chunk[0], chunk[1], chunk[2], chunk[3]);
            let argb: u32 =
                ((a as u32) << 24) | ((r as u32) << 16) | ((g as u32) << 8) | (b as u32);
            reference.push(argb as i32);
        }
        let mut packed: Vec<i32> = Vec::new();
        fb.pack_into_i32(&mut packed);
        assert_eq!(packed, reference, "bulk pack must equal the per-pixel repack");
        let bytes = unsafe {
            std::slice::from_raw_parts(packed.as_ptr() as *const u8, packed.len() * 4)
        };
        assert_eq!(bytes, &fb.pixels[..], "byte order must be untouched");
        // Reusable destination buffer (the JNI path keeps one across frames).
        fb.pack_into_i32(&mut packed);
        assert_eq!(packed.len(), 9 * 4);
    }
}
