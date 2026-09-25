//! Client rasterisation acceptance for the original GM fonts.
//!
//! The Draw layer emits TextCommand with the font resource id from
//! `draw_set_font`; the framebuffer used to render every text through the
//! 5x7 fallback bitmap instead of the six Gill Sans MT fonts baked into the
//! FONT chunk (atlas texture 1). These tests drive one synthetic TextCommand
//! through `draw_frame` on the real asset and check the glyph pixels against
//! geometry read independently from the atlas, so they fail if the font path
//! stops being consumed.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::TextCommand;
use std::path::Path;
use std::sync::Arc;

const BG: (u8, u8, u8) = (15, 18, 30);
/// Screen offset of the text box origin (camera-relative), integral by
/// construction so every expected coordinate below is exact.
const AT: (f64, f64) = (320.0, 260.0);

fn state() -> GameState {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    state.retire_prologue();
    state
}

/// Build the TextCommand first (needs &state for the camera), then clear the
/// scene and push it.
fn text_cmd(state: &GameState, text: &str, font: i32, color: i32) -> TextCommand {
    let (cx, cy) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    TextCommand {
        code: 0, offset: 0, instance: -1, view: 0,
        x: cx + AT.0, y: cy + AT.1,
        text: text.to_string(),
        color, alpha: 1.0, font,
    }
}

fn only_text(state: &mut GameState, cmd: TextCommand) {
    let s = state.scene.as_mut().unwrap();
    s.draws.clear();
    s.backgrounds.clear();
    s.room_tiles.clear();
    s.texts.clear();
    s.healthbars.clear();
    s.particles.clear();
    s.texts.push(cmd);
}

fn render(state: &GameState) -> Framebuffer {
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, state, &state.asset.tpag_items, &state.asset.sprites);
    fb
}

fn px(fb: &Framebuffer, x: i32, y: i32) -> (u8, u8, u8, u8) {
    let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
    (fb.pixels[i + 2], fb.pixels[i + 1], fb.pixels[i], fb.pixels[i + 3])
}

fn is_bg(fb: &Framebuffer, x: i32, y: i32) -> bool {
    let (r, g, b, _) = px(fb, x, y);
    (r, g, b) == BG
}

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

/// A single 'G' of font1 (runtime id 0) must land with its probed ink
/// geometry: the box top is at the draw position, ink starts 9 rows down
/// inside the 26-row box — bounds read from the atlas independently.
#[test]
fn font1_g_glyph_lands_with_the_probed_ink_geometry() {
    let mut st = state();

    // Precondition: the fixture must resolve font1's page on atlas 1.
    let font1 = st.asset.fonts.first().expect("FONT chunk parsed");
    assert_eq!(font1.name, "font1");
    let page = st
        .asset
        .tpag_items
        .get(&font1.page_tpag_ptr)
        .expect("font1 page descriptor");
    let atlas = st.atlases.get(page.tex_id as usize).expect("atlas 1");
    let g = font1.glyphs.iter().find(|g| g.ch == b'G' as u16).expect("G glyph");
    assert_eq!((g.w, g.h), (15, 26), "probed G box");
    // Independent ink bounds straight from the atlas (probe: 0,9,14,25).
    let (mut il, mut it, mut ir, mut ib) = (u32::MAX, u32::MAX, 0u32, 0u32);
    for yy in 0..g.h as u32 {
        for xx in 0..g.w as u32 {
            let a = atlas
                .get_pixel(page.x as u32 + g.x as u32 + xx, page.y as u32 + g.y as u32 + yy)
                .0[3];
            if a > 8 {
                il = il.min(xx);
                it = it.min(yy);
                ir = ir.max(xx);
                ib = ib.max(yy);
            }
        }
    }
    assert_eq!((il, it, ir, ib), (0, 9, 14, 25), "probed G ink bounds");

    let cmd = text_cmd(&st, "G", 0, 16777215);
    only_text(&mut st, cmd);
    let fb = render(&st);

    let bbox = drawn_bbox(&fb).expect("the G glyph drew pixels");
    let sx = AT.0 as i32;
    let sy = AT.1 as i32;
    // The box lands at the draw position; the ink bounds inside it are the
    // atlas ones at the 1:1 view scale.
    assert_eq!(
        bbox,
        (sx + il as i32, sy + it as i32, sx + ir as i32, sy + ib as i32),
        "screen ink bbox must equal the atlas ink bounds offset by the box origin"
    );
    // Ink pixels are white: the glyph bake is white-on-transparent and the
    // command colour is c_white. Sample the middle of the G's left stem —
    // a fully covered run far from the antialiased edges.
    let mid_y = sy + (it + ib) as i32 / 2;
    let (r, gch, b, a) = px(&fb, sx + il as i32, mid_y);
    assert_eq!((r, gch, b), (255, 255, 255));
    assert!(a > 200, "fully covered glyph pixel, got alpha {a}");
    // And the box is anchored at the draw position: above the ink (the box's
    // empty head rows) nothing is drawn.
    assert!(is_bg(&fb, sx, sy), "no ink above the box's ink start");
}

/// draw_set_color tints the glyphs multiplicatively: c_red (255) keeps only
/// the red channel of the white bake.
#[test]
fn font_glyphs_tint_with_draw_color() {
    let mut st = state();
    let cmd_red = text_cmd(&st, "G", 0, 255); // c_red
    only_text(&mut st, cmd_red);
    let fb = render(&st);
    let bbox = drawn_bbox(&fb).expect("the G glyph drew pixels");

    // A/B against the same draw in white.
    let mut st2 = state();
    let cmd_white = text_cmd(&st2, "G", 0, 16777215);
    only_text(&mut st2, cmd_white);
    let fb2 = render(&st2);
    assert_eq!(bbox, drawn_bbox(&fb2).expect("white G bbox"));

    // Same shape, red-only channels.
    for y in bbox.1..=bbox.3 {
        for x in bbox.0..=bbox.2 {
            let (r, g, b, a) = px(&fb, x, y);
            let (r2, g2, b2, a2) = px(&fb2, x, y);
            if !is_bg(&fb2, x, y) {
                assert_eq!((r, a), (r2, a2), "red channel and coverage match at {x},{y}");
                assert_eq!((g, b), (0, 0), "green/blue cancelled by c_red at {x},{y}");
            } else {
                assert!(is_bg(&fb, x, y), "tinting changed coverage at {x},{y}");
            }
        }
    }
}

/// Different fonts have different pixel sizes: font5 (runtime id 4, 8 px)
/// must draw a smaller G than font1 (runtime id 0, 18 px). Both ink heights
/// are read from the atlas, not hardcoded twice.
#[test]
fn runtime_font_ids_select_different_pixel_sizes() {
    let mut st = state();
    // Expected ink heights measured independently from the atlas pages.
    let ink_height = |disk_idx: usize| -> i32 {
        let font = st.asset.fonts.get(disk_idx).expect("font");
        let page = st
            .asset
            .tpag_items
            .get(&font.page_tpag_ptr)
            .expect("page");
        let atlas = st.atlases.get(page.tex_id as usize).expect("atlas");
        let g = font.glyphs.iter().find(|g| g.ch == b'G' as u16).expect("G");
        let (mut it, mut ib) = (u32::MAX, 0u32);
        for yy in 0..g.h as u32 {
            for xx in 0..g.w as u32 {
                let a = atlas
                    .get_pixel(page.x as u32 + g.x as u32 + xx, page.y as u32 + g.y as u32 + yy)
                    .0[3];
                if a > 8 {
                    it = it.min(yy);
                    ib = ib.max(yy);
                }
            }
        }
        (ib - it + 1) as i32
    };
    let expected_big = ink_height(0); // font1
    let expected_small = ink_height(4); // font5
    assert!(expected_big > expected_small, "font1 (18px) must ink taller than font5 (8px)");

    let cmd = text_cmd(&st, "G", 4, 16777215);
    only_text(&mut st, cmd);
    let fb_small = render(&st);
    let bbox_small = drawn_bbox(&fb_small).expect("font5 G drew");

    let mut st2 = state();
    let cmd2 = text_cmd(&st2, "G", 0, 16777215);
    only_text(&mut st2, cmd2);
    let fb_big = render(&st2);
    let bbox_big = drawn_bbox(&fb_big).expect("font1 G drew");

    assert_eq!(bbox_big.3 - bbox_big.1 + 1, expected_big, "font1 G ink height");
    assert_eq!(bbox_small.3 - bbox_small.1 + 1, expected_small, "font5 G ink height");
}

/// A text command whose font id has no FONT entry (or a parse failure)
/// must still render through the 5x7 fallback instead of disappearing.
#[test]
fn unknown_font_id_falls_back_to_the_5x7_bitmap() {
    let mut st = state();
    let cmd = text_cmd(&st, "G", 99, 16777215);
    only_text(&mut st, cmd);
    let fb = render(&st);
    let bbox = drawn_bbox(&fb).expect("fallback rendered the text");
    // 5x7 fallback at the fixture's 2x screen scale: 10x14 ink, box top at
    // the draw position (the fallback has no head rows).
    assert_eq!(
        bbox,
        (AT.0 as i32, AT.1 as i32, AT.0 as i32 + 9, AT.1 as i32 + 13),
        "5x7 fallback G at 2x"
    );
    // The fallback is the *old* renderer: its ink must differ from the GM
    // font's (10x14 blocky vs 15x17 Gill Sans).
    let mut st2 = state();
    let cmd2 = text_cmd(&st2, "G", 0, 16777215);
    only_text(&mut st2, cmd2);
    let fb2 = render(&st2);
    let bbox2 = drawn_bbox(&fb2).expect("GM font G drew");
    assert_ne!(bbox, bbox2, "fallback and GM font must not render identically");
}
