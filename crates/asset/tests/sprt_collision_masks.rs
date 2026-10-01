//! SPRT collision-mask extraction against the real game.droid.
//!
//! Binary probe (2026-09-28, direct SPRT chunk walk): the masks live INLINE
//! in each sprite record — after the TPAG pointer list comes a u32 mask
//! count, then that many 1bpp bitmaps of ceil(w/8)*h bytes (MSB-first rows,
//! rows padded to full bytes). All 178 records end exactly at the next
//! record's offset under this reading, including:
//!   - 53 sprites whose mask is the full solid rect (walls, terrain),
//!   - spr_player (32x34): solid rect columns 9..=22, rows 4..=33 only,
//!   - spr_spikes (32x32): rows 0..=8 transparent, 9..=31 solid,
//!   - spr_boss4 (128x128) and spr_boss4swing (179x160): one mask per frame.
//! The first mask is frame 0's; content of spr_boss4's 30 stored masks is
//! identical, so the count mirrors the animation length, not distinct shapes.

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
    eprintln!("Skipping SPRT mask tests: no game.droid found in candidate paths.");
    None
}

fn sprite<'a>(asset: &'a GameDroidAsset, name: &str) -> &'a callys_asset::SpriteData {
    asset
        .sprites
        .values()
        .find(|s| s.name == name)
        .unwrap_or_else(|| panic!("{name} missing from SPRT"))
}

#[test]
fn every_sprt_record_carries_at_least_one_collision_mask() {
    let Some(asset) = load_asset() else { return };
    assert_eq!(asset.sprites.len(), 178, "SPRT holds 178 sprites");
    for (id, sp) in &asset.sprites {
        assert!(
            !sp.masks.is_empty(),
            "sprite {id} ({}) extracted no mask",
            sp.name
        );
        let expect = (((sp.masks[0].width as usize) + 7) / 8) * sp.masks[0].height as usize;
        assert_eq!(sp.masks[0].bits.len(), expect, "{} mask byte length", sp.name);
    }
}

#[test]
fn spr_player_mask_is_the_solid_14x30_rect_measured_by_the_probe() {
    let Some(asset) = load_asset() else { return };
    let sp = sprite(&asset, "spr_player");
    assert_eq!((sp.width, sp.height), (32, 34));
    let m = &sp.masks[0];
    for y in 0..34i32 {
        for x in 0..32i32 {
            let solid = (9..=22).contains(&x) && (4..=33).contains(&y);
            assert_eq!(m.pixel(x, y), solid, "spr_player pixel ({x},{y})");
        }
    }
}

#[test]
fn spr_spikes_mask_is_transparent_for_the_top_nine_rows() {
    let Some(asset) = load_asset() else { return };
    let sp = sprite(&asset, "spr_spikes");
    let m = &sp.masks[0];
    for y in 0..32i32 {
        let expect_solid = y >= 9;
        for x in 0..32i32 {
            assert_eq!(m.pixel(x, y), expect_solid, "spr_spikes pixel ({x},{y})");
        }
    }
}

#[test]
fn solid_wall_terrain_masks_cover_the_whole_bitmap() {
    let Some(asset) = load_asset() else { return };
    for name in ["spr_set1wall", "spr_set1path", "spr_iceblock"] {
        let m = &sprite(&asset, name).masks[0];
        for y in 0..m.height as i32 {
            for x in 0..m.width as i32 {
                assert!(m.pixel(x, y), "{name} pixel ({x},{y}) must be solid");
            }
        }
    }
}

#[test]
fn boss4_sprites_store_one_mask_per_animation_frame() {
    let Some(asset) = load_asset() else { return };
    assert_eq!(sprite(&asset, "spr_boss4").masks.len(), 30);
    assert_eq!(sprite(&asset, "spr_boss4swing").masks.len(), 21);
    // The probe measured 5883 solid pixels per boss4 frame mask; identical
    // across frames (count mirrors animation length, not distinct shapes).
    let m = &sprite(&asset, "spr_boss4").masks[0];
    let on: usize = m.bits.iter().map(|b| b.count_ones() as usize).sum();
    assert_eq!(on, 5883, "spr_boss4 frame 0 solid pixel count");
}
