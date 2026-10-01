//! Render batch 2 — the weapon-swap widget, obj_weaponswap's Draw (CODE 520,
//! 13888 instrs) through the REAL draw_view dispatch. The widget is always on
//! screen during play: the swap icon plus, for every owned weapon, its icon
//! (frame = level bracket) and its XP bar + level number. All geometry and
//! gates come from the shipped body (recovered GML cross-checked).
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const SWAP_DRAW: usize = 520;

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

fn arena(bundle: &Bundle, asset: &GameDroidAsset) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(bundle);
    s.init_fresh_start_globals();
    for (sid, sprite) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sprite.width as f64,
            height: sprite.height as f64,
            origin_x: sprite.origin_x as f64,
            origin_y: sprite.origin_y as f64,
            frames: sprite.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(bundle, 97, &asset.rooms[97]).unwrap(); // carries obj_weaponswap
    s.create(bundle, PLAYER, 400.0, 300.0).unwrap();
    s.view_positions.insert(0, (0.0, 0.0));
    s
}

fn sprite_id(asset: &GameDroidAsset, name: &str) -> i32 {
    asset.sprites.iter().find(|(_, s)| s.name == name).map(|(id, _)| *id as i32)
        .unwrap_or_else(|| panic!("missing sprite {name}"))
}

fn widget(s: &Scene, sprite: i32) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == SWAP_DRAW && d.sprite == sprite).cloned().collect()
}

fn text_at(s: &Scene, x: f64, y: f64) -> Option<String> {
    s.texts.iter().find(|t| t.x == x && t.y == y && t.code == SWAP_DRAW).map(|t| t.text.clone())
}

#[test]
fn the_swap_widget_pins_its_icon_and_every_owned_weapon() {
    let (asset, bundle) = game();
    let mut s = arena(&bundle, &asset);
    s.draw_view(&bundle, 0).unwrap();

    // CODE 520 view 0: the swap icon at (view + 360, view + 0), 0.7 scale, and
    // the instance pins itself there.
    let swap = sprite_id(&asset, "spr_weaponswap");
    let icon = widget(&s, swap);
    assert_eq!(icon.len(), 1, "one swap icon per pass");
    assert_eq!((icon[0].frame, icon[0].x, icon[0].y, icon[0].scale_x, icon[0].alpha),
        (0.0, 360.0, 0.0, 0.7, 1.0));
    let swap_inst = s.instances.iter().find(|(_, i)| i.object == 126).map(|(id, _)| *id).unwrap();
    assert_eq!((s.instances[&swap_inst].fields["x"], s.instances[&swap_inst].fields["y"]), (360.0, 0.0));

    // Fresh start owns the pistol only: one weapon icon, at frame 0 <= level 3.
    let pistol = sprite_id(&asset, "spr_gunpistol");
    let p = widget(&s, pistol);
    assert_eq!(p.len(), 1);
    assert_eq!((p[0].frame, p[0].x, p[0].y, p[0].scale_x), (0.0, 422.0, 20.0, 2.0));

    // Level brackets select the frame; >= 10 also shifts the icon by (-4, +2).
    for (level, frame, x, y) in [(4.0, 1.0, 422.0, 20.0), (8.0, 2.0, 422.0, 20.0), (12.0, 3.0, 418.0, 22.0)] {
        s.globals.insert("pistollevel".into(), level);
        s.draw_view(&bundle, 0).unwrap();
        let d = widget(&s, pistol).into_iter().next().unwrap();
        assert_eq!((d.frame, d.x, d.y), (frame, x, y), "pistol level {level}");
    }

    // Buying the shotgun adds its icon with its own per-bracket offsets.
    s.globals.insert("shotgun".into(), 1.0);
    s.globals.insert("shotgunlevel".into(), 1.0);
    s.draw_view(&bundle, 0).unwrap();
    let shotgun = sprite_id(&asset, "spr_gunshotgun");
    let g = widget(&s, shotgun).into_iter().next().expect("the owned shotgun draws");
    assert_eq!((g.frame, g.x, g.y, g.scale_x), (0.0, 405.0, 20.0, 2.0));
    s.globals.insert("shotgunlevel".into(), 5.0);
    s.draw_view(&bundle, 0).unwrap();
    let g = widget(&s, shotgun).into_iter().next().unwrap();
    assert_eq!((g.frame, g.x, g.y), (1.0, 409.0, 20.0), "the <= 6 bracket shifts the shotgun right");
}

#[test]
fn the_swap_widget_shows_each_owned_weapons_xp_bar_and_level() {
    let (asset, bundle) = game();
    let mut s = arena(&bundle, &asset);
    s.globals.insert("pistollevel".into(), 3.0);
    s.globals.insert("pistolxp".into(), 30.0);
    s.globals.insert("pistolxptolevelup".into(), 120.0);
    s.draw_view(&bundle, 0).unwrap();

    // CODE 520: draw_healthbar(view+368, view+3, view+441, view+6,
    // (pistolxp / pistolxptolevelup) * 100, ...) while the level is below 10.
    let bar = s.healthbars.iter().find(|hb| hb.x1 == 368.0 && hb.y1 == 3.0)
        .expect("the pistol XP bar draws");
    assert_eq!((bar.x2, bar.y2, bar.amount), (441.0, 6.0, 25.0), "30/120 -> 25%");
    assert_eq!(text_at(&s, 368.0, 6.0).as_deref(), Some("3"), "string(pistollevel)");

    // At level 10 the bar is gone but the number stays.
    s.globals.insert("pistollevel".into(), 10.0);
    s.draw_view(&bundle, 0).unwrap();
    assert!(s.healthbars.iter().all(|hb| hb.x1 != 368.0), "no XP bar at level 10");
    assert_eq!(text_at(&s, 368.0, 6.0).as_deref(), Some("10"));
}

#[test]
fn unowned_weapons_leave_the_widget_empty() {
    let (asset, bundle) = game();
    let mut s = arena(&bundle, &asset);
    s.draw_view(&bundle, 0).unwrap();

    // Fresh start: the swap icon, the pistol icon, its bar and its level only.
    let weapon_icons: Vec<i32> = s.draws.iter()
        .filter(|d| d.code == SWAP_DRAW)
        .filter(|d| !["spr_weaponswap"].contains(&asset.sprites[&(d.sprite as usize)].name.as_str()))
        .map(|d| d.sprite)
        .collect();
    assert_eq!(weapon_icons, vec![sprite_id(&asset, "spr_gunpistol")],
        "only the owned weapon draws an icon");
    assert_eq!(s.healthbars.iter().filter(|hb| hb.x1 == 368.0).count(), 1);
    assert_eq!(s.texts.iter().filter(|t| t.code == SWAP_DRAW).count(), 1);
    for unowned in ["spr_gunshotgun", "spr_gunassaultrifle", "spr_gunrocketlauncher", "spr_gunlaser"] {
        assert!(widget(&s, sprite_id(&asset, unowned)).is_empty(), "{unowned} stays hidden");
    }
}
