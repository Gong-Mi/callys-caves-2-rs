//! Precise collision (`CSprite::PreciseCollision`, libyoyo 0x1e4298) inside the
//! Rust VM: two recorded boxes can overlap while the sprites do not, and the
//! runner asks the masks. These fixtures are synthetic masks with known halves,
//! so the expected answer is arithmetic rather than a recording.
//!
//! Layer boundary: this pins our VM's implementation of the rule we read out of
//! the runner (rect intersection -> per-pixel mask map -> both bits set). It is
//! not an oracle diff against libyoyo; that needs the Unicorn/synthetic-memory
//! harness and is registered as an open layer.
use callys_asset::CollisionMask;
use callys_core::code_vm::{Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};

fn empty_bundle() -> Bundle {
    Bundle { schema: 1, string_table: vec![], objects: vec![], room_bindings: vec![], codes: vec![] }
}

fn rect(s: &mut Scene, sid: i32, w: f64, h: f64, ox: f64, oy: f64) {
    s.sprite_bounds.insert(sid, SpriteBounds::with_frames(w, h, ox, oy, 1.0));
}

fn instance(s: &mut Scene, object: i32, x: f64, y: f64, sprite: i32) -> i32 {
    let id = s.insert_external(object);
    for (key, value) in [("x", x), ("y", y), ("sprite_index", sprite as f64),
                         ("mask_index", -1.0), ("image_xscale", 1.0),
                         ("image_yscale", 1.0), ("image_angle", 0.0)] {
        s.write(id, -1, key, None, value).unwrap();
    }
    id
}

/// 8x8 mask whose left four columns are solid.
fn left_half() -> CollisionMask {
    CollisionMask { width: 8, height: 8, bits: vec![0xf0; 8] }
}

/// 8x8 mask whose right four columns are solid.
fn right_half() -> CollisionMask {
    CollisionMask { width: 8, height: 8, bits: vec![0x0f; 8] }
}

#[test]
fn overlapping_boxes_with_disjoint_pixels_do_not_collide() {
    let mut s = Scene::default();
    s.sprite_masks.insert(10, vec![left_half()]);
    s.sprite_masks.insert(11, vec![right_half()]);
    rect(&mut s, 10, 8.0, 8.0, 0.0, 0.0);
    rect(&mut s, 11, 8.0, 8.0, 0.0, 0.0);
    let a = instance(&mut s, 10, 0.0, 0.0, 10);
    let b = instance(&mut s, 11, 0.0, 0.0, 11);

    // Same spot: boxes are identical, but A only owns columns 0..3 and B owns
    // 4..7, so no world pixel is solid in both.
    assert!(!s.precise_overlap(a, 0.0, 0.0, b), "disjoint halves at the same spot");

    // Shift B left by four: its solid half lands on A's solid half.
    s.write(b, -1, "x", None, -4.0).unwrap();
    assert!(s.precise_overlap(a, 0.0, 0.0, b), "shifted so the halves meet");

    // The other way they miss again (B's solid half lands right of A's).
    s.write(b, -1, "x", None, 4.0).unwrap();
    assert!(!s.precise_overlap(a, 0.0, 0.0, b), "shifted the other way");
}

#[test]
fn instance_place_uses_the_pixel_gate() {
    let mut s = Scene::default();
    let bundle = empty_bundle();
    s.sprite_masks.insert(10, vec![left_half()]);
    s.sprite_masks.insert(11, vec![right_half()]);
    rect(&mut s, 10, 8.0, 8.0, 0.0, 0.0);
    rect(&mut s, 11, 8.0, 8.0, 0.0, 0.0);
    let a = instance(&mut s, 10, 0.0, 0.0, 10);
    let b = instance(&mut s, 11, 0.0, 0.0, 11);

    // Box overlap would answer `b` here; the masks answer -4.
    let hit = s.call(&bundle, a, "instance_place", &[0.0, 0.0, 11.0]).unwrap();
    assert_eq!(hit, -4.0, "overlapping boxes must not be enough");
    // place_meeting is the same call, boolean.
    let meeting = s.call(&bundle, a, "place_meeting", &[0.0, 0.0, 11.0]).unwrap();
    assert_eq!(meeting, 0.0);

    s.write(b, -1, "x", None, -4.0).unwrap();
    let hit = s.call(&bundle, a, "instance_place", &[0.0, 0.0, 11.0]).unwrap();
    assert_eq!(hit, b as f64, "shared solid pixel is a hit");
    let meeting = s.call(&bundle, a, "place_meeting", &[0.0, 0.0, 11.0]).unwrap();
    assert_eq!(meeting, 1.0);
}

#[test]
fn a_sprite_without_masks_keeps_the_box_verdict() {
    let mut s = Scene::default();
    let bundle = empty_bundle();
    s.sprite_masks.insert(10, vec![left_half()]);
    rect(&mut s, 10, 8.0, 8.0, 0.0, 0.0);
    rect(&mut s, 12, 8.0, 8.0, 0.0, 0.0);          // no mask data for sprite 12
    let a = instance(&mut s, 10, 0.0, 0.0, 10);
    let b = instance(&mut s, 11, 0.0, 0.0, 12);
    let hit = s.call(&bundle, a, "instance_place", &[0.0, 0.0, 11.0]).unwrap();
    assert_eq!(hit, b as f64, "no mask data -> the recorded box decides");
}

#[test]
fn rotation_falls_back_until_the_rotated_path_is_pinned() {
    let mut s = Scene::default();
    let bundle = empty_bundle();
    s.sprite_masks.insert(10, vec![left_half()]);
    s.sprite_masks.insert(11, vec![right_half()]);
    rect(&mut s, 10, 8.0, 8.0, 0.0, 0.0);
    rect(&mut s, 11, 8.0, 8.0, 0.0, 0.0);
    let a = instance(&mut s, 10, 0.0, 0.0, 10);
    let b = instance(&mut s, 11, 0.0, 0.0, 11);
    s.write(a, -1, "image_angle", None, 90.0).unwrap();
    // The masks are disjoint, so a live pixel gate would answer false; the
    // rotation guard is what keeps this at the box verdict. (instance_place is
    // not used here because rotating the caller also moves its recorded box.)
    assert!(s.precise_overlap(a, 0.0, 0.0, b),
            "rotated sprites keep the box verdict for now");
}
