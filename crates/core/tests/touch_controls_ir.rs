//! Render batch 2 — the touch-control layer's Draw pass through the REAL
//! draw_view dispatch: obj_leftbutton (CODE 530), obj_rightbutton (533),
//! obj_jumpbutton (522), obj_shootbutton (525) and obj_swordbutton (527).
//! Every geometry pin comes from the shipped bodies (recovered GML
//! cross-checked); the buttons pin their own x/y inside the Draw, so the
//! interactive box used here is the one the game itself queries.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const LEFT: i32 = 130;
const RIGHT: i32 = 131;
const JUMP: i32 = 127;
const SHOOT: i32 = 128;
const SWORD: i32 = 129;

const LEFT_DRAW: usize = 530;
const RIGHT_DRAW: usize = 533;
const JUMP_DRAW: usize = 522;
const SHOOT_DRAW: usize = 525;
const SWORD_DRAW: usize = 527;

/// (object id, Draw CODE, sprite name, view-0 draw offset x/y, scale)
const BUTTONS: [(i32, usize, &str, f64, f64, f64); 5] = [
    (LEFT, LEFT_DRAW, "spr_leftbutton", 0.0, 190.0, 0.9),
    (RIGHT, RIGHT_DRAW, "spr_rightbutton", 86.0, 190.0, 0.9),
    (JUMP, JUMP_DRAW, "spr_jumpbutton", 380.0, 190.0, 0.9),
    (SHOOT, SHOOT_DRAW, "spr_shootbutton", 315.0, 190.0, 0.9),
    (SWORD, SWORD_DRAW, "spr_swordbutton", 380.0, 125.0, 0.9),
];

/// The self-pinned instance position per view-0 branch (CODE 530/533/522/525/527).
const PINS: [(i32, f64, f64); 5] = [
    (LEFT, -10.0, 190.0),
    (RIGHT, 88.0, 190.0),
    (JUMP, 380.0, 190.0),
    (SHOOT, 315.0, 190.0),
    (SWORD, 380.0, 125.0),
];

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
    s.load_room_from_data(bundle, 97, &asset.rooms[97]).unwrap();
    s.create(bundle, PLAYER, 400.0, 300.0).unwrap();
    s.view_positions.insert(0, (0.0, 0.0));
    s.view_positions.insert(1, (0.0, 0.0));
    s.view_positions.insert(2, (0.0, 0.0));
    s
}

fn sprite_id(asset: &GameDroidAsset, name: &str) -> i32 {
    asset.sprites.iter().find(|(_, s)| s.name == name).map(|(id, _)| *id as i32)
        .unwrap_or_else(|| panic!("missing sprite {name}"))
}

fn drawn(s: &Scene, code: usize, sprite: i32) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == code && d.sprite == sprite).cloned().collect()
}

/// Point device 0 at the button's own collision box (its instance x/y plus the
/// button sprite's bounds), the same box CODE 522/525/527/530/533 query.
fn aim_at(s: &mut Scene, btn: i32, sprite: i32, offset: (f64, f64)) {
    let i = &s.instances[&instance_of(s, btn)];
    let b = s.sprite_bounds.get(&sprite).cloned().unwrap_or_default();
    let sx = i.fields["image_xscale"];
    let sy = i.fields["image_yscale"];
    let cx = i.fields["x"] - b.origin_x * sx + b.width * sx / 2.0 + offset.0;
    let cy = i.fields["y"] - b.origin_y * sy + b.height * sy / 2.0 + offset.1;
    let d = &mut s.touch_devices[0];
    d.x = cx;
    d.y = cy;
}

/// Instance id of the single live instance of `object` (rooms place one of each
/// touch button; instance ids are not object ids).
fn instance_of(s: &Scene, object: i32) -> i32 {
    s.instances.iter().find(|(_, i)| i.object == object && i.alive).map(|(id, _)| *id)
        .unwrap_or_else(|| panic!("no live instance of object {object}"))
}

#[test]
fn the_buttons_pin_their_geometry_and_their_idle_frame() {
    let (asset, bundle) = game();
    let mut s = arena(&bundle, &asset);
    s.draw_view(&bundle, 0).unwrap();

    for (obj, code, sprite, dx, dy, scale) in BUTTONS {
        let id = sprite_id(&asset, sprite);
        let ds = drawn(&s, code, id);
        assert_eq!(ds.len(), 1, "{sprite}: one idle draw per pass");
        let d = &ds[0];
        assert_eq!((d.frame, d.x, d.y, d.scale_x, d.alpha), (0.0, dx, dy, scale, 0.6),
            "{sprite} idle frame geometry");
        instance_of(&s, obj); // the room places exactly one of each button
    }

    // The self-pinned positions the interactive boxes are built from.
    for (obj, px, py) in PINS {
        let i = &s.instances[&instance_of(&s, obj)];
        assert_eq!((i.fields["x"], i.fields["y"]), (px, py),
            "object {obj} pins its own position");
    }
}

#[test]
fn each_button_swaps_to_its_pressed_sprite_and_arms_its_alarm() {
    let (asset, bundle) = game();
    // (object, Draw CODE, sprite, alarm slot armed, held-down or press-edge)
    // CODE 530/533 check the HELD state (with the roomstart gate), CODE
    // 522/525/527 check the press EDGE.
    let cases = [(LEFT, LEFT_DRAW, "spr_leftbutton", 1usize, true), (RIGHT, RIGHT_DRAW, "spr_rightbutton", 1, true),
                 (JUMP, JUMP_DRAW, "spr_jumpbutton", 1, false), (SHOOT, SHOOT_DRAW, "spr_shootbutton", 2, false),
                 (SWORD, SWORD_DRAW, "spr_swordbutton", 1, false)];
    for (obj, code, sprite, slot, held) in cases {
        let mut s = arena(&bundle, &asset);
        let id = sprite_id(&asset, sprite);
        s.draw_view(&bundle, 0).unwrap();          // pin x/y
        aim_at(&mut s, obj, id, (0.0, 0.0));
        if held {
            s.touch_devices[0].down = true;
        } else {
            s.touch_devices[0].pressed = true;
        }
        s.draw_view(&bundle, 0).unwrap();

        let ds = drawn(&s, code, id);
        assert_eq!(ds.len(), 2, "{sprite}: idle + pressed frame");
        let pressed = ds.iter().find(|d| d.frame == 1.0)
            .unwrap_or_else(|| panic!("{sprite} draws its pressed frame"));
        assert_eq!(pressed.alpha, 1.0, "{sprite} pressed frame is fully opaque");
        let inst = instance_of(&s, obj);
        assert_eq!(s.instances[&inst].alarms[slot], 1, "{sprite} arms alarm[{slot}]");
    }
}

#[test]
fn the_move_buttons_release_back_to_idle_and_stop_the_player() {
    let (asset, bundle) = game();
    let id = sprite_id(&asset, "spr_leftbutton");
    let mut s = arena(&bundle, &asset);
    let player = s.instances.iter().find(|(_, i)| i.object == PLAYER).map(|(id, _)| *id).unwrap();
    s.write(player, -1, "hsp", None, -7.0).unwrap();
    s.draw_view(&bundle, 0).unwrap();

    // A release inside the box: idle frame again, at full alpha, player stopped.
    aim_at(&mut s, LEFT, id, (0.0, 0.0));
    s.touch_devices[0].released = true;
    s.draw_view(&bundle, 0).unwrap();
    let ds = drawn(&s, LEFT_DRAW, id);
    assert_eq!(ds.len(), 2, "idle draw + release redraw");
    assert!(ds.iter().any(|d| d.frame == 0.0 && d.alpha == 1.0),
        "the release branch re-draws the idle frame at alpha 1");
    assert_eq!(s.instances[&player].fields["hsp"], 0.0, "release stops horizontal motion");

    // Holding OUTSIDE the box keeps the player stopped without a second draw.
    s.write(player, -1, "hsp", None, -7.0).unwrap();
    aim_at(&mut s, LEFT, id, (4000.0, 0.0));
    s.touch_devices[0].down = true;
    s.draw_view(&bundle, 0).unwrap();
    assert_eq!(drawn(&s, LEFT_DRAW, id).len(), 1, "no pressed frame outside the box");
    assert_eq!(s.instances[&player].fields["hsp"], 0.0,
        "holding outside the box clears hsp (CODE 530's else-if)");
}

#[test]
fn the_shoot_button_repeats_while_held_only_with_the_assault_rifle() {
    let (asset, bundle) = game();
    let id = sprite_id(&asset, "spr_shootbutton");
    let mut s = arena(&bundle, &asset);
    s.draw_view(&bundle, 0).unwrap();
    aim_at(&mut s, SHOOT, id, (0.0, 0.0));
    s.touch_devices[0].down = true; // held, no press edge

    s.draw_view(&bundle, 0).unwrap();
    assert_eq!(drawn(&s, SHOOT_DRAW, id).iter().filter(|d| d.frame == 1.0).count(), 0,
        "a plain hold does not press the button");
    assert_eq!(s.instances[&instance_of(&s, SHOOT)].alarms[2], -1, "no auto-fire without the rifle");

    s.globals.insert("assaultrifle".into(), 1.0);
    s.draw_view(&bundle, 0).unwrap();
    assert_eq!(drawn(&s, SHOOT_DRAW, id).iter().filter(|d| d.frame == 1.0).count(), 1,
        "with the assault rifle a hold repeats the pressed frame");
    assert_eq!(s.instances[&instance_of(&s, SHOOT)].alarms[2], 1, "the hold re-arms alarm[2]");
}

#[test]
fn a_press_outside_the_box_leaves_every_button_idle() {
    let (asset, bundle) = game();
    let mut s = arena(&bundle, &asset);
    s.draw_view(&bundle, 0).unwrap();
    s.touch_devices[0].x = 9000.0;
    s.touch_devices[0].y = 9000.0;
    s.touch_devices[0].pressed = true;
    s.draw_view(&bundle, 0).unwrap();
    for (obj, code, sprite, ..) in BUTTONS {
        let id = sprite_id(&asset, sprite);
        let ds = drawn(&s, code, id);
        assert_eq!(ds.len(), 1, "{sprite}: only the idle frame");
        assert_eq!(ds[0].alpha, 0.6, "{sprite} stays translucent");
        let inst = instance_of(&s, obj);
        assert_eq!(s.instances[&inst].alarms[1], -1, "object {obj} stays unarmed");
        assert_eq!(s.instances[&inst].alarms[2], -1, "object {obj} stays unarmed (alarm 2)");
    }
}

#[test]
fn the_button_layout_follows_the_active_view() {
    let (asset, bundle) = game();
    let mut s = arena(&bundle, &asset);
    // view 1 offsets/scales straight from CODE 522/525/527/530/533.
    let view1 = [(LEFT, LEFT_DRAW, "spr_leftbutton", 2.0, 200.0),
                 (RIGHT, RIGHT_DRAW, "spr_rightbutton", 77.0, 200.0),
                 (JUMP, JUMP_DRAW, "spr_jumpbutton", 330.0, 200.0),
                 (SHOOT, SHOOT_DRAW, "spr_shootbutton", 275.0, 200.0),
                 (SWORD, SWORD_DRAW, "spr_swordbutton", 330.0, 145.0)];
    s.draw_view(&bundle, 1).unwrap();
    for (_obj, code, sprite, dx, dy) in view1 {
        let id = sprite_id(&asset, sprite);
        let d = drawn(&s, code, id).into_iter().next()
            .unwrap_or_else(|| panic!("{sprite} draws in view 1"));
        assert_eq!((d.x, d.y, d.scale_x), (dx, dy, 0.8), "{sprite} view-1 layout");
    }

    // View 2 has empty branches: the whole control layer disappears.
    s.draw_view(&bundle, 2).unwrap();
    for (_obj, code, sprite, ..) in view1 {
        let id = sprite_id(&asset, sprite);
        assert!(drawn(&s, code, id).is_empty(), "{sprite} draws nothing in view 2");
    }
}
