//! Client rasterisation acceptance for the remaining DrawCommand fields.
//!
//! The core Draw layer already emits every original sprite term — SPRT origin,
//! facing mirror (`image_xscale = -1`), `image_angle`, `image_blend`, and the
//! `d3d_set_fog(true, c, 0, 0)` hit-flash colour — but the framebuffer used to
//! consume only sprite/frame/position/scale/alpha: sprites landed with their
//! top-left on the instance position, a facing flip collapsed to one pixel, a
//! rotated bullet drew upright, frozen/poisoned tints and the red/white flash
//! disappeared, and healthbars ignored the colours the original passes.
//!
//! These tests drive one synthetic DrawCommand through `draw_frame` on the real
//! asset and compare the resulting pixels against geometry read independently
//! from the atlas, so they fail if any of those terms stops being consumed.
use callys_asset::SpriteData;
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{DrawCommand, HealthbarCommand};
use std::path::Path;
use std::sync::Arc;

/// draw_frame's clear colour; anything else in the buffer came from the scene.
const BG: (u8, u8, u8) = (15, 18, 30);
/// Sprite-local offset of the instance under test.
const AT: (f64, f64) = (320.0, 260.0);

fn state() -> GameState {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    // The prologue film owns the first frames; these tests are about gameplay
    // draws, so retire it through the real CODE 549 path.
    state.retire_prologue();
    state
}

fn camera(state: &GameState) -> (f64, f64) {
    GameState::camera_position_for_scene(state.scene.as_ref().unwrap())
}

/// Instance position that puts the origin at a fixed offset from the camera, so
/// every expected screen coordinate below is an exact integer.
fn at(state: &GameState) -> (f64, f64) {
    let (cx, cy) = camera(state);
    (cx + AT.0, cy + AT.1)
}

/// Replace the scene's draw list with a single command and drop everything
/// drawn before it, so any non-background pixel is that command's.
fn only(state: &mut GameState, cmd: DrawCommand) {
    let s = state.scene.as_mut().unwrap();
    s.draws.clear();
    s.backgrounds.clear();
    s.room_tiles.clear();
    s.texts.clear();
    s.healthbars.clear();
    s.particles.clear();
    s.draws.push(cmd);
}

fn command(sprite: i32, x: f64, y: f64, scale: (f64, f64)) -> DrawCommand {
    DrawCommand {
        code: 0, offset: 0, instance: -1, view: 0,
        sprite, frame: 0.0, x, y,
        scale_x: scale.0, scale_y: scale.1,
        rotation: 0.0, color: 16777215, alpha: 1.0, fog: false,
    }
}

fn render(state: &GameState) -> Framebuffer {
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, state, &state.asset.tpag_items, &state.asset.sprites);
    fb
}

/// Pixel decode for the ABGR8888 row-major buffer.
fn px(fb: &Framebuffer, x: i32, y: i32) -> (u8, u8, u8, u8) {
    let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
    (fb.pixels[i + 2], fb.pixels[i + 1], fb.pixels[i], fb.pixels[i + 3])
}

fn is_bg(fb: &Framebuffer, x: i32, y: i32) -> bool {
    let (r, g, b, _) = px(fb, x, y);
    (r, g, b) == BG
}

/// Opaque bounding box of everything drawn into the buffer.
fn drawn_bbox(fb: &Framebuffer) -> Option<(i32, i32, i32, i32)> {
    let (mut x0, mut y0, mut x1, mut y1) = (i32::MAX, i32::MAX, i32::MIN, i32::MIN);
    for y in 0..fb.height as i32 {
        for x in 0..fb.width as i32 {
            if !is_bg(fb, x, y) {
                x0 = x0.min(x);
                y0 = y0.min(y);
                x1 = x1.max(x);
                y1 = y1.max(y);
            }
        }
    }
    if x0 == i32::MAX { None } else { Some((x0, y0, x1, y1)) }
}

fn frame_atlas<'a>(state: &'a GameState, sprite: &SpriteData, frame: usize)
    -> (&'a image::RgbaImage, (u32, u32, u32, u32)) {
    let page = state.asset.tpag_items
        .get(&(sprite.tpag_indices[frame] as usize)).expect("frame page");
    let atlas = state.atlases.get(page.tex_id as usize).expect("atlas");
    (atlas, (page.x as u32, page.y as u32, page.w as u32, page.h as u32))
}

/// The frame's own opaque extent, read straight from the atlas.
fn frame_bbox(state: &GameState, sprite: &SpriteData, frame: usize) -> Option<(i32, i32, i32, i32)> {
    let (atlas, (sx, sy, sw, sh)) = frame_atlas(state, sprite, frame);
    let (mut x0, mut y0, mut x1, mut y1) = (i32::MAX, i32::MAX, i32::MIN, i32::MIN);
    for y in 0..sh {
        for x in 0..sw {
            if atlas.get_pixel(sx + x, sy + y).0[3] >= 16 {
                x0 = x0.min(x as i32); y0 = y0.min(y as i32);
                x1 = x1.max(x as i32); y1 = y1.max(y as i32);
            }
        }
    }
    if x0 == i32::MAX { None } else { Some((x0, y0, x1, y1)) }
}

/// First fully opaque pixel of the frame, so the tint arithmetic is checked
/// against a real source colour instead of a guessed one.
fn opaque_pixel(state: &GameState, sprite: &SpriteData, frame: usize) -> Option<(i32, i32, (u8, u8, u8))> {
    let (atlas, (sx, sy, sw, sh)) = frame_atlas(state, sprite, frame);
    for y in 0..sh {
        for x in 0..sw {
            let p = atlas.get_pixel(sx + x, sy + y).0;
            if p[3] == 255 && p[0].min(p[1]).min(p[2]) >= 80 {
                return Some((x as i32, y as i32, (p[0], p[1], p[2])));
            }
        }
    }
    None
}

/// A sprite whose frame 0 is exactly its canvas, carries a non-zero SPRT
/// origin, has an asymmetric opaque extent, contains no pixel that would read
/// as the clear colour, offers a fully opaque mid-bright pixel for the tint
/// checks, and whose frame plus mirror stay well inside the framebuffer.
fn usable_sprite(state: &GameState, want_non_square_extent: bool)
    -> (i32, SpriteData, (i32, i32, i32, i32), (i32, i32, (u8, u8, u8))) {
    let mut ids: Vec<i32> = state.asset.sprites.keys().map(|k| *k as i32).collect();
    ids.sort();
    for id in ids {
        let sprite = state.asset.sprites.get(&(id as usize)).unwrap().clone();
        if sprite.tpag_indices.is_empty() { continue; }
        let (atlas, (fx, fy, sw, sh)) = frame_atlas(state, &sprite, 0);
        if sw != sprite.width || sh != sprite.height { continue; }  // canvas == frame
        if sprite.width > 128 || sprite.height > 128 || sprite.width < 8 || sprite.height < 8 { continue; }
        let (ox, oy) = (sprite.origin_x as f64, sprite.origin_y as f64);
        if ox == 0.0 && oy == 0.0 { continue; }  // the origin anchor must be observable
        let Some((u0, v0, u1, v1)) = frame_bbox(state, &sprite, 0) else { continue };
        let Some((bu, bv, rgb)) = opaque_pixel(state, &sprite, 0) else { continue };
        if u0 + u1 == sprite.width as i32 - 1 { continue; }  // needs x asymmetry
        if want_non_square_extent && (u1 - u0) == (v1 - v0) { continue; }
        let mut clear_coloured = false;
        for y in 0..sh {
            for x in 0..sw {
                let p = atlas.get_pixel(fx + x, fy + y).0;
                if p[3] >= 16 && (p[0], p[1], p[2]) == BG { clear_coloured = true; }
            }
        }
        if clear_coloured { continue; }  // a pixel identical to the clear colour would hide the extent
        // Unmirrored placement (sprite pixel k lands on AT + k - origin) plus the
        // mirrored and 90-degree placements, which flip the pixel grid about the
        // origin and swap the axes respectively (see the assertions below).
        let left = AT.0 - ox + u0 as f64;
        let right = AT.0 - ox + u1 as f64;
        let m_left = AT.0 + ox - u1 as f64 - 1.0;
        let m_right = AT.0 + ox - u0 as f64 - 1.0;
        let top = AT.1 - oy + v0 as f64;
        let bottom = AT.1 - oy + v1 as f64;
        let r_left = AT.0 - oy + v0 as f64;
        let r_right = AT.0 - oy + v1 as f64;
        let r_top = AT.1 - ox + u0 as f64;
        let r_bottom = AT.1 - ox + u1 as f64;
        let fits = |lo: f64, hi: f64, max: f64| lo >= 24.0 && hi <= max - 24.0;
        if !fits(left, right, 960.0) || !fits(m_left, m_right, 960.0) || !fits(top, bottom, 540.0) {
            continue;
        }
        if !fits(r_left, r_right, 960.0) || !fits(r_top, r_bottom, 540.0) { continue; }
        if !fits(AT.0 - ox + bu as f64, AT.0 - ox + bu as f64, 960.0) { continue; }
        if !fits(AT.1 - oy + bv as f64, AT.1 - oy + bv as f64, 540.0) { continue; }
        return (id, sprite, (u0, v0, u1, v1), (bu, bv, rgb));
    }
    panic!("no sprite in the asset satisfies the fixture requirements");
}

#[test]
fn sprite_origin_anchors_and_negative_scale_mirrors_on_the_axis() {
    let mut state = state();
    let (id, sprite, (u0, v0, u1, v1), _) = usable_sprite(&state, false);
    let (x, y) = at(&state);
    let (ox, oy) = (sprite.origin_x as f64, sprite.origin_y as f64);
    // The old consumer put the frame's top-left on the instance position; the
    // SPRT origin must land there instead, which shifts the opaque extent.
    let expect_left = (AT.0 - ox + u0 as f64) as i32;
    let expect_top = (AT.1 - oy + v0 as f64) as i32;
    let expect_w = u1 - u0;
    let expect_h = v1 - v0;
    assert!(expect_w * expect_h > 4, "fixture must have a real extent: {id}");

    only(&mut state, command(id, x, y, (1.0, 1.0)));
    let fb = render(&state);
    let bbox = drawn_bbox(&fb).expect("the command must draw something");
    assert_eq!(bbox, (expect_left, expect_top, expect_left + expect_w, expect_top + expect_h),
        "sprite {id} must anchor its SPRT origin ({ox},{oy}) on the instance position");
    assert!(is_bg(&fb, expect_left - 1, expect_top), "nothing may draw left of the origin anchor");
    assert!(is_bg(&fb, expect_left + expect_w + 1, expect_top + expect_h),
        "nothing may draw right of the frame box");

    // image_xscale = -1 is the original's facing mirror: the frame flips about
    // the origin, so the opaque extent lands on the other side of it, one pixel
    // over because the mirror flips the pixel grid as well as the content.
    only(&mut state, command(id, x, y, (-1.0, 1.0)));
    let mirrored = render(&state);
    let mbox = drawn_bbox(&mirrored).expect("the mirrored command must draw something");
    let m_left = (AT.0 + ox - u1 as f64 - 1.0) as i32;
    let m_top = (AT.1 - oy + v0 as f64) as i32;
    assert_eq!(mbox, (m_left, m_top, m_left + expect_w, m_top + expect_h),
        "negative image_xscale must mirror the frame about the origin, not collapse it");
    assert_eq!(mbox.2 - mbox.0, bbox.2 - bbox.0, "a mirror preserves the drawn width");
    assert_eq!(mbox.3 - mbox.1, bbox.3 - bbox.1, "a mirror preserves the drawn height");
    assert_eq!(m_left + bbox.2 + 1, 2 * AT.0 as i32,
        "the mirrored box is the exact reflection of the unmirrored one about the origin");

    let count = |fb: &Framebuffer| -> usize {
        let mut n = 0;
        for y in 0..fb.height as i32 {
            for x in 0..fb.width as i32 {
                if !is_bg(fb, x, y) { n += 1; }
            }
        }
        n
    };
    assert_eq!(count(&mirrored), count(&fb),
        "the mirror draws exactly as many pixels as the unmirrored frame");
}

#[test]
fn image_angle_rotates_the_frame_about_the_sprite_origin() {
    let mut state = state();
    let (id, sprite, (u0, v0, u1, v1), _) = usable_sprite(&state, true);
    let (x, y) = at(&state);
    let (ox, oy) = (sprite.origin_x as f64, sprite.origin_y as f64);
    // Opaque extent around the origin, in sprite space.
    let (lx0, lx1) = (u0 as f64 - ox, u1 as f64 - ox);
    let (ly0, ly1) = (v0 as f64 - oy, v1 as f64 - oy);

    only(&mut state, command(id, x, y, (1.0, 1.0)));
    let flat = drawn_bbox(&render(&state)).expect("upright frame");
    assert_eq!((flat.0, flat.1), ((AT.0 + lx0) as i32, (AT.1 + ly0) as i32));
    let (w, h) = (flat.2 - flat.0 + 1, flat.3 - flat.1 + 1);

    // image_angle = 90: a sprite that points right points up. GMS rotates
    // counter-clockwise on screen, about the sprite origin.
    let mut turned = command(id, x, y, (1.0, 1.0));
    turned.rotation = 90.0;
    only(&mut state, turned);
    let rotated = drawn_bbox(&render(&state)).expect("rotated frame");
    let (rw, rh) = (rotated.2 - rotated.0 + 1, rotated.3 - rotated.1 + 1);
    assert!((rw as i32 - h).abs() <= 1 && (rh as i32 - w).abs() <= 1,
        "a 90 degree turn swaps the drawn extent: {w}x{h} became {rw}x{rh}");
    assert_eq!(rw > rh, h > w, "the rotated extent must swap the aspect ratio");
    // Counter-clockwise on screen about the origin: the sprite's x extent lands
    // on the screen's y axis and vice versa (lx = -ry, ly = rx), which is why
    // the frame's left edge ends up at the bottom.
    let expect = ((AT.0 + ly0) as i32, (AT.1 - lx1 - 1.0) as i32,
                  (AT.0 + ly1) as i32, (AT.1 - lx0 - 1.0) as i32);
    let near = |got: i32, want: i32| (got - want).abs() <= 1;
    assert!(near(rotated.0, expect.0) && near(rotated.1, expect.1)
        && near(rotated.2, expect.2) && near(rotated.3, expect.3),
        "rotated frame {rotated:?} must land on the image_angle-90 placement {expect:?}");
}

#[test]
fn image_blend_multiplies_and_fog_floods_the_frame() {
    let mut state = state();
    let (id, sprite, _, (bu, bv, (sr, sg, sb))) = usable_sprite(&state, false);
    let (x, y) = at(&state);
    let (ox, oy) = (sprite.origin_x as f64, sprite.origin_y as f64);
    let (ux, uy) = ((AT.0 - ox) as i32 + bu, (AT.1 - oy) as i32 + bv);

    // image_blend default (c_white) and the 4-argument draw_sprite default (-1)
    // are both "no tint": the pixel keeps the sprite's own colour.
    for (label, color) in [("c_white", 16777215i32), ("draw_sprite default", -1i32)] {
        only(&mut state, command(id, x, y, (1.0, 1.0)));
        state.scene.as_mut().unwrap().draws[0].color = color;
        let fb = render(&state);
        assert_eq!(px(&fb, ux, uy), (sr, sg, sb, 255),
            "{label} must multiply the frame by white (identity), got {:?}", px(&fb, ux, uy));
    }

    // Frozen enemies run with image_blend = c_blue (16711680): red and green are
    // multiplied out, blue survives.
    only(&mut state, command(id, x, y, (1.0, 1.0)));
    state.scene.as_mut().unwrap().draws[0].color = 16711680;
    let fb = render(&state);
    assert_eq!(px(&fb, ux, uy), (0, 0, sb, 255),
        "c_blue blend must keep only the blue channel, got {:?}", px(&fb, ux, uy));

    // The thaw frame's wrapped blend value (16711680 - 16777215 = -65535, pinned
    // by the core enemy tests) decodes through the low 24 bits: (1, 0, 255).
    only(&mut state, command(id, x, y, (1.0, 1.0)));
    state.scene.as_mut().unwrap().draws[0].color = -65535;
    let fb = render(&state);
    let (r, g, b, _) = px(&fb, ux, uy);
    assert_eq!((r, g, b), (sr * 1 / 255, 0, sb), "the wrapped blend decodes to (1,0,255)");

    // The hit flash is fog, not blend: d3d_set_fog(true, c, 0, 0) floods the
    // frame with the fog colour and keeps only its alpha silhouette.
    for (color, expect) in [(255i32, (255u8, 0u8, 0u8)), (16777215, (255, 255, 255))] {
        only(&mut state, command(id, x, y, (1.0, 1.0)));
        {
            let d = &mut state.scene.as_mut().unwrap().draws[0];
            d.color = color;
            d.fog = true;
        }
        let fb = render(&state);
        assert_eq!(px(&fb, ux, uy), (expect.0, expect.1, expect.2, 255),
            "fog {color} must flood the frame colour, got {:?}", px(&fb, ux, uy));
    }
}

#[test]
fn healthbar_uses_the_original_back_min_and_max_colours() {
    const BACK: i32 = 0x333333;  // distinguishable from both c_black and c_gray
    const MIN: i32 = 65280;      // c_green
    const MAX: i32 = 65535;      // c_yellow
    let mut state = state();
    let bar = |amount: f64| HealthbarCommand {
        code: 0, offset: 0, instance: -1, view: 0,
        x1: 100.0, y1: 120.0, x2: 200.0, y2: 140.0,
        amount, back_col: BACK, min_col: MIN, max_col: MAX,
    };
    let (cx, cy) = camera(&state);
    // draw_healthbar takes room coordinates (the original passes view_xview +
    // offset), so the client projects them through the same camera.
    let (l, t) = ((100.0 - cx) as i32, (120.0 - cy) as i32);

    let setup = |state: &mut GameState, amount: f64| {
        let s = state.scene.as_mut().unwrap();
        s.draws.clear(); s.backgrounds.clear(); s.room_tiles.clear();
        s.texts.clear(); s.particles.clear();
        s.healthbars.clear();
        s.healthbars.push(bar(amount));
    };

    setup(&mut state, 100.0);
    let fb = render(&state);
    assert_eq!(px(&fb, l + 50, t + 10), (255, 255, 0, 255),
        "a full bar is the original's max_col (c_yellow), got {:?}", px(&fb, l + 50, t + 10));
    assert_eq!(px(&fb, l, t), (0, 0, 0, 255),
        "the original asks for the border (showborder == 1)");

    setup(&mut state, 50.0);
    let fb = render(&state);
    assert_eq!(px(&fb, l + 20, t + 10), (128, 255, 0, 255),
        "half a bar interpolates min_col -> max_col (c_green -> c_yellow)");
    assert_eq!(px(&fb, l + 80, t + 10), (0x33, 0x33, 0x33, 255),
        "the unfilled part is the original's back_col");
}