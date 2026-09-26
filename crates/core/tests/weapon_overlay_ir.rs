//! Render batch 1 — the weapon overlay matrix, obj_muting's Draw (CODE 374,
//! 8669 instrs) through the REAL draw_view dispatch. The object draws the held
//! weapon and its muzzle flare for twelve weapon families, each keyed by
//! (level bracket x facing x swing x firing). Every pinned sprite id, frame and
//! offset comes from the shipped body (recovered GML cross-checked); sprite ids
//! resolve through the asset's own sprite names, never a hardcoded 125.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds};
use std::path::Path;

const MUTING: i32 = 67;
const PLAYER: i32 = 0;
const MUTING_DRAW: usize = 374;

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

fn fresh(bundle: &Bundle, asset: &GameDroidAsset, room: usize) -> Scene {
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
    s.load_room_from_data(bundle, room, &asset.rooms[room]).unwrap();
    s
}

fn sprite_id(asset: &GameDroidAsset, name: &str) -> i32 {
    asset.sprites.iter().find(|(_, s)| s.name == name).map(|(id, _)| *id as i32)
        .unwrap_or_else(|| panic!("missing sprite {name}"))
}

/// The overlay's own draw commands (CODE 374), in emission order.
fn overlay(s: &Scene) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == MUTING_DRAW).cloned().collect()
}

/// Test scene: rm_boss3 (room 97 carries obj_muting, obj_UI and obj_weaponswap)
/// with a real player created FIRST — the player's Create (CODE 0) resets the
/// weapon globals, so every weapon gate goes in afterwards.
fn arena(bundle: &Bundle, asset: &GameDroidAsset) -> (Scene, i32, i32, i32) {
    let mut s = fresh(bundle, asset, 97);
    let player = s.create(bundle, PLAYER, 400.0, 300.0).unwrap();
    let muting = s.instances.iter().find(|(_, i)| i.object == MUTING).map(|(id, _)| *id)
        .expect("room 97 carries obj_muting");
    s.view_positions.insert(0, (0.0, 0.0));
    (s, player, muting, 0)
}

fn armed(s: &mut Scene, player: i32, weapon: &str, level: f64, facing: f64, firing: f64) {
    s.write(player, -1, "facing", None, facing).unwrap();
    s.globals.insert(format!("{weapon}"), 1.0);
    s.globals.insert(format!("{weapon}level"), level);
    s.globals.insert("swing".into(), 1.0);
    s.globals.insert("firing".into(), firing);
}

#[test]
fn the_held_pistol_follows_its_level_brackets_and_facing() {
    let (asset, bundle) = game();
    let (mut s, player, _muting, _) = arena(&bundle, &asset);
    let pistol = sprite_id(&asset, "spr_gunpistol");
    // CODE 374: <= 3 / <= 6 / <= 9 / >= 10 select frames 0..3; facing 0 draws
    // at (x + 21, y + 7) with xscale 1, facing 1 at (x - 21, ...) with -1.
    for (level, frame) in [(1.0, 0.0), (4.0, 1.0), (8.0, 2.0), (12.0, 3.0)] {
        armed(&mut s, player, "pistol", level, 0.0, 0.0);
        s.draw_view(&bundle, 0).unwrap();
        let d = overlay(&s).into_iter().find(|d| d.sprite == pistol)
            .unwrap_or_else(|| panic!("pistol level {level} draws the held gun"));
        assert_eq!((d.frame, d.x, d.y, d.scale_x), (frame, 421.0, 307.0, 1.0),
            "level {level} -> frame {frame} at (x + 21, y + 7)");
        assert_eq!(overlay(&s).iter().filter(|d| d.sprite == pistol).count(), 1,
            "exactly one held-gun draw per pass");

        armed(&mut s, player, "pistol", level, 1.0, 0.0);
        s.draw_view(&bundle, 0).unwrap();
        let d = overlay(&s).into_iter().find(|d| d.sprite == pistol).unwrap();
        assert_eq!((d.x, d.y, d.scale_x), (379.0, 307.0, -1.0),
            "facing left mirrors the gun to x - 21");
    }
}

#[test]
fn the_overlay_matrix_switches_sprite_and_offset_per_weapon_family() {
    let (asset, bundle) = game();
    let (mut s, player, _muting, _) = arena(&bundle, &asset);
    // (weapon, held sprite, level, expected x offset, y offset)
    let rows = [
        ("shotgun", "spr_gunshotgun", 2.0, 15.0, 8.0),
        ("rocket", "spr_gunrocketlauncher", 2.0, 2.0, 12.0),
        ("bombgun", "spr_gunbombgun", 2.0, 2.0, 5.0),
        ("spikegun", "spr_spikegun", 2.0, 4.0, 7.0),
    ];
    for (weapon, sprite, level, dx, dy) in rows {
        armed(&mut s, player, weapon, level, 0.0, 0.0);
        s.draw_view(&bundle, 0).unwrap();
        let id = sprite_id(&asset, sprite);
        let d = overlay(&s).into_iter().find(|d| d.sprite == id)
            .unwrap_or_else(|| panic!("{weapon} draws {sprite} while held"));
        assert_eq!((d.x, d.y, d.frame), (400.0 + dx, 300.0 + dy, 0.0),
            "{weapon} level {level} -> frame 0 at (x + {dx}, y + {dy})");
    }

    // Spikegun's higher brackets move one pixel up with their frame:
    // <= 6 -> frame 1, <= 9 -> frame 2, >= 10 -> frame 3, all at y + 6.
    for (level, frame) in [(5.0, 1.0), (7.0, 2.0), (10.0, 3.0)] {
        armed(&mut s, player, "spikegun", level, 0.0, 0.0);
        s.draw_view(&bundle, 0).unwrap();
        let d = overlay(&s).into_iter().find(|d| d.sprite == sprite_id(&asset, "spr_spikegun")).unwrap();
        assert_eq!((d.frame, d.x, d.y), (frame, 404.0, 306.0),
            "spikegun level {level} -> frame {frame} at y + 6");
    }
}

#[test]
fn the_muzzle_flare_fires_with_the_overlays_own_animation_frame() {
    let (asset, bundle) = game();
    let (mut s, player, muting, _) = arena(&bundle, &asset);
    let pistol = sprite_id(&asset, "spr_gunpistol");
    let flare = sprite_id(&asset, "spr_pistolflare");
    armed(&mut s, player, "pistol", 1.0, 0.0, 1.0);
    s.instances.get_mut(&muting).unwrap().fields.insert("frame".into(), 4.0);

    s.draw_view(&bundle, 0).unwrap();
    let ds = overlay(&s);
    // CODE 374 firing branch: the gun steps forward to (x + 19, y + 7) and the
    // flare paints at (x + 15, y + 5) with the overlay's animated frame.
    let gun = ds.iter().find(|d| d.sprite == pistol).expect("the gun still draws while firing");
    assert_eq!((gun.x, gun.y), (419.0, 307.0), "the gun steps to x + 19");
    let f = ds.iter().find(|d| d.sprite == flare).expect("the flare draws while firing");
    assert_eq!((f.frame, f.x, f.y), (4.0, 415.0, 305.0),
        "the flare uses obj_muting.frame at (x + 15, y + 5)");

    // obj_muting's Step (CODE 373) advances that frame and wraps at 6.
    s.dispatch(&bundle, muting, 3, 0).unwrap();
    s.draw_view(&bundle, 0).unwrap();
    assert_eq!(overlay(&s).iter().find(|d| d.sprite == flare).unwrap().frame, 5.0);
    s.instances.get_mut(&muting).unwrap().fields.insert("frame".into(), 5.0);
    s.dispatch(&bundle, muting, 3, 0).unwrap();
    s.draw_view(&bundle, 0).unwrap();
    assert_eq!(overlay(&s).iter().find(|d| d.sprite == flare).unwrap().frame, 0.0,
        "frame wraps at 6");
}

#[test]
fn the_overlay_stays_empty_without_a_swing_and_in_the_ending_room() {
    let (asset, bundle) = game();
    let (mut s, player, _muting, _) = arena(&bundle, &asset);
    armed(&mut s, player, "pistol", 1.0, 0.0, 0.0);
    s.globals.insert("swing".into(), 0.0);
    s.draw_view(&bundle, 0).unwrap();
    assert!(overlay(&s).is_empty(), "no swing, no held weapon");

    // firing without swing draws nothing either (both gates are `== 1`).
    s.globals.insert("swing".into(), 1.0);
    s.globals.insert("firing".into(), 1.0);
    s.draw_view(&bundle, 0).unwrap();
    assert!(!overlay(&s).is_empty(), "the firing branch needs swing == 1 too");
    s.globals.insert("swing".into(), 0.0);
    s.draw_view(&bundle, 0).unwrap();
    assert!(overlay(&s).is_empty(), "firing alone (swing == 0) draws nothing");

    // room == rm_ending (110) gates the whole body off. The ending room's own
    // cast has no overlay object, so place one and hand it a live player — the
    // gate under test is the room check, not instance existence.
    let mut ending = fresh(&bundle, &asset, 110);
    ending.create(&bundle, PLAYER, 400.0, 300.0).unwrap();
    let ending_muting = match ending.instances.iter().find(|(_, i)| i.object == MUTING) {
        Some((id, _)) => *id,
        None => ending.create(&bundle, MUTING, 0.0, 0.0).unwrap(),
    };
    assert!(ending.instances.contains_key(&ending_muting), "the overlay instance exists but stays silent");
    ending.globals.insert("pistol".into(), 1.0);
    ending.globals.insert("pistollevel".into(), 1.0);
    ending.globals.insert("swing".into(), 1.0);
    ending.globals.insert("firing".into(), 0.0);
    ending.view_positions.insert(0, (0.0, 0.0));
    ending.draw_view(&bundle, 0).unwrap();
    assert!(overlay(&ending).is_empty(), "rm_ending draws no weapon overlay");

    // Sanity: the same instance state draws outside the ending room.
    let (mut boss_room, player, _muting, _) = arena(&bundle, &asset);
    armed(&mut boss_room, player, "pistol", 1.0, 0.0, 0.0);
    boss_room.draw_view(&bundle, 0).unwrap();
    assert!(!overlay(&boss_room).is_empty(), "the same setup draws in a normal room");
}
