//! FONT chunk parsing against the real game.droid: the six Gill Sans MT fonts,
//! their page descriptors, and glyph box records — all pinned by the hex/ink
//! probes (see reconstruction/contracts/font-atlas-1.md).

use callys_asset::GameDroidAsset;

fn load_asset() -> Option<GameDroidAsset> {
    let candidates = [
        "assets/game.droid",
        "../../assets/game.droid",
        "/data/data/com.termux/files/usr/tmp/cally_caves_2/apk/assets/game.droid",
    ];
    for path in candidates {
        if std::path::Path::new(path).exists() {
            return GameDroidAsset::parse(path).ok();
        }
    }
    eprintln!("Skipping font tests: no game.droid found in candidate paths.");
    None
}

/// Disk order of the FONT chunk is font1, font4, font2, font3, font5, font6 —
/// the runtime ids the bytecode pushes (draw_set_font(0..5)) are the
/// alphabetically sorted resource ids, not this disk order.
#[test]
fn font_chunk_parses_six_gill_sans_fonts_with_disk_order() {
    let Some(asset) = load_asset() else { return };
    let fonts = &asset.fonts;
    assert_eq!(fonts.len(), 6, "the FONT chunk holds six fonts");

    let names: Vec<&str> = fonts.iter().map(|f| f.name.as_str()).collect();
    assert_eq!(names, ["font1", "font4", "font2", "font3", "font5", "font6"]);

    let sizes: Vec<u32> = fonts.iter().map(|f| f.size).collect();
    assert_eq!(sizes, [18, 14, 10, 10, 8, 14]);

    for font in fonts {
        assert_eq!(font.system_name, "Gill Sans MT");
        assert!(!font.bold);
        assert!(!font.italic);
        assert_eq!(font.glyph_count, 96);
        assert_eq!(font.glyphs.len(), 96, "every glyph record decodes");
        assert_eq!(font.tex_id, 1, "all six pages live on atlas texture 1");
    }
}

/// Glyph records are u16 ch, x, y, w, h, shift, offset, unused boxes into the
/// font's TpagItem page rectangle. The 'G' of font1 is the probe-proven sample.
#[test]
fn font_glyph_records_carry_box_geometry_and_advances() {
    let Some(asset) = load_asset() else { return };
    let font1 = &asset.fonts[0];
    assert_eq!(font1.name, "font1");

    let g = font1
        .glyphs
        .iter()
        .find(|g| g.ch == b'G' as u16)
        .expect("font1 has a 'G' glyph");
    assert_eq!((g.x, g.y, g.w, g.h), (53, 35, 15, 26));
    assert_eq!(g.shift, 18, "advance includes the side bearing");

    // Space: a blank 7x34 box whose advance is its shift alone.
    let space = &font1.glyphs[0];
    assert_eq!(space.ch, b' ' as u16);
    assert_eq!((space.w, space.h), (7, 34));
    assert_eq!(space.shift, 7);

    // Descenders carry taller boxes (g: 10x32) with lower ink tops; the parser
    // keeps the raw box so the consumer can blit without re-deriving it.
    let g_lower = font1
        .glyphs
        .iter()
        .find(|g| g.ch == b'g' as u16)
        .expect("font1 has a lowercase 'g'");
    assert_eq!((g_lower.w, g_lower.h), (10, 32));

    // Character codes cover the printable ASCII range the original prints.
    for ch in 32..=126u16 {
        assert!(
            font1.glyphs.iter().any(|g| g.ch == ch),
            "font1 is missing glyph {ch}"
        );
    }
}

/// The page descriptor is an absolute TpagItem offset; the parser resolves it
/// to the atlas texture id and the page rectangle stays reachable through the
/// existing tpag_items map.
#[test]
fn font_page_descriptors_resolve_into_tpag_items() {
    let Some(asset) = load_asset() else { return };
    for font in &asset.fonts {
        let page = asset
            .tpag_items
            .get(&font.page_tpag_ptr)
            .expect("font page descriptor resolves to a TpagItem");
        assert_eq!(page.tex_id as u16, font.tex_id);
        assert!(
            page.w == 256 || page.w == 128,
            "font pages are 256x256 or 256x128/128x128 rects"
        );
        // Glyph boxes must lie inside the page rectangle.
        for g in &font.glyphs {
            assert!(
                g.x + g.w as u16 <= page.w,
                "glyph {} x-range exceeds page width",
                g.ch
            );
            assert!(
                g.y + g.h as u16 <= page.h,
                "glyph {} y-range exceeds page height",
                g.ch
            );
        }
    }
}
