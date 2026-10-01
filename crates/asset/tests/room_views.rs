//! Room-editor VIEW table parsing against the real game.droid.
//!
//! Binary probe (2026-09-26, direct ROOM chunk read of game.droid):
//! rm_town's view table sits at file offset 474572 (8 slots × 14 u32s after a
//! u32 count + 8 u32 offsets). view[0] is the ONLY visible view:
//!
//!     visible=1  xview=0  yview=0  wview=448  hview=252
//!     xport=0    yport=0  wport=1136  hport=640
//!     hborder=512  vborder=512  hspeed=-1  vspeed=-1  object=0 (obj_player)
//!
//! The original runner zooms the 448x252 view into the 1136x640 port
//! (~2.54x) — the device-vs-original capture comparison showed the original's
//! world sprites at ~2.5x our flat 960x540 projection, which is what makes
//! this table the next render-parity layer.

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
    eprintln!("Skipping view tests: no game.droid found in candidate paths.");
    None
}

#[test]
fn rm_town_view0_is_the_only_visible_view_and_zooms_448x252_into_1136x640() {
    let Some(asset) = load_asset() else { return };
    let town = &asset.rooms[0];
    assert_eq!(town.name, "rm_town", "room 0 is rm_town");
    assert_eq!(town.views.len(), 8, "GM8.1 rooms hold 8 view slots");

    let v0 = &town.views[0];
    assert!(v0.visible, "rm_town view[0] is visible");
    assert_eq!((v0.xview, v0.yview, v0.wview, v0.hview), (0, 0, 448, 252));
    assert_eq!((v0.xport, v0.yport, v0.wport, v0.hport), (0, 0, 1136, 640));
    assert_eq!((v0.hborder, v0.vborder), (512, 512));
    assert_eq!((v0.hspeed, v0.vspeed), (-1, -1), "no auto-scroll");
    assert_eq!(v0.object, 0, "view[0] follows obj_player (object 0)");

    let others: Vec<usize> = town.views[1..]
        .iter()
        .enumerate()
        .filter(|(_, v)| v.visible)
        .map(|(i, _)| i + 1)
        .collect();
    assert!(others.is_empty(), "no other visible view in rm_town, got {others:?}");

    // The zoom factor is the parity-critical number: the original's world
    // sprites appear at wport/wview ≈ 2.54x a flat projection.
    let zoom_x = v0.wport as f64 / v0.wview as f64;
    let zoom_y = v0.hport as f64 / v0.hview as f64;
    assert!((zoom_x - 1136.0 / 448.0).abs() < 1e-9);
    assert!((zoom_y - 640.0 / 252.0).abs() < 1e-9);
    assert!((2.5..=2.6).contains(&zoom_x), "zoom_x {zoom_x} is the ~2.54x the device capture pinned");
}
