//! Precise (prec=1) collision against the real SPRT masks (ledger T3).
//!
//! Binary attestation (2026-09-28 probe, `sprt_collision_masks.rs`): the
//! spike strip `spr_spikes` (32x32, origin 0,0) is transparent for rows
//! 0..=8 and solid for rows 9..=31; wall sprites are fully solid. The
//! original's ranged moulds gate fire with
//! `collision_line(x, y, obj_player.x, obj_player.y, par_wall, true, true)`
//! — with prec=1 the runner tests the mask, so a sight line crossing only
//! the empty top of a spike sprite is CLEAR, while the same line through a
//! wall is blocked. Before this feature the host answered both queries from
//! the bounding box, so spikes falsely suppressed volleys.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const SPR_SPIKES: i32 = 93;
const SPR_PLAYER: i32 = 29;
const OBJ_PLAYER: i32 = 0;
const OBJ_WALL: i32 = 4;
const OBJ_SPIKES: i32 = 8;

fn scene_with_masks() -> (callys_core::code_vm::Bundle, Scene) {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
        if !sp.masks.is_empty() {
            s.sprite_masks.insert(*sid as i32, sp.masks.clone());
        }
    }
    (bundle, s)
}

/// Place one instance with a pinned sprite at (x, y).
fn place(
    s: &mut Scene,
    b: &callys_core::code_vm::Bundle,
    object: i32,
    spr: i32,
    x: f64,
    y: f64,
) -> i32 {
    let id = s.create(b, object, x, y).expect("create");
    s.write(id, -1, "sprite_index", None, spr as f64).unwrap();
    id
}

#[test]
fn prec_line_ignores_the_spikes_transparent_top_while_a_wall_still_blocks() {
    let (b, mut s) = scene_with_masks();
    // Bounding boxes: spikes x [200,232), y [100,132); wall x [300,332), y [100,132).
    let spikes = place(&mut s, &b, OBJ_SPIKES, SPR_SPIKES, 200.0, 100.0);
    let wall = place(&mut s, &b, OBJ_WALL, 5, 300.0, 100.0);

    // y=105 crosses both bboxes (mask rows 5). Spike mask rows 0..=8 are
    // transparent, wall mask is fully solid.
    let over_spikes = s
        .call(&b, wall, "collision_line", &[150.0, 105.0, 231.0, 105.0, OBJ_SPIKES as f64, 1.0, 1.0])
        .unwrap();
    assert_eq!(over_spikes, -4.0, "prec=1 line through the empty spike top must NOT hit (noone)");

    let over_wall = s
        .call(&b, spikes, "collision_line", &[250.0, 105.0, 310.0, 105.0, OBJ_WALL as f64, 1.0, 1.0])
        .unwrap();
    assert_eq!(over_wall, wall as f64, "prec=1 line through a solid wall must hit");

    // Same spike-crossing line answered by the bounding box: prec=0 hits.
    let bbox_hit = s
        .call(&b, wall, "collision_line", &[150.0, 105.0, 231.0, 105.0, OBJ_SPIKES as f64, 0.0, 1.0])
        .unwrap();
    assert_eq!(bbox_hit, spikes as f64, "prec=0 stays bounding-box based");

    // A line into the solid body (row 20 -> room y=120) hits with prec=1.
    let solid_hit = s
        .call(&b, wall, "collision_line", &[150.0, 120.0, 231.0, 120.0, OBJ_SPIKES as f64, 1.0, 1.0])
        .unwrap();
    assert_eq!(solid_hit, spikes as f64, "prec=1 line into the spike body must hit");
}

#[test]
fn prec_point_test_respects_the_player_mask_transparent_corners() {
    let (b, mut s) = scene_with_masks();
    // spr_player: 32x34, origin (15,16); mask solid cols 9..=22, rows 4..=33.
    let player = place(&mut s, &b, OBJ_PLAYER, SPR_PLAYER, 200.0, 150.0);
    let observer = place(&mut s, &b, OBJ_WALL, 5, 400.0, 400.0);

    // Bounding box: x [185,217), y [134,168).
    // (200,145) -> texture pixel (15,11): inside the solid rect — hit.
    let on_body = s
        .call(&b, observer, "collision_point", &[200.0, 145.0, OBJ_PLAYER as f64, 1.0, 1.0])
        .unwrap();
    assert_eq!(on_body, player as f64, "solid pixel must hit with prec=1");

    // (185,134) -> texture pixel (0,0): transparent corner inside the bbox.
    let on_corner = s
        .call(&b, observer, "collision_point", &[185.0, 134.0, OBJ_PLAYER as f64, 1.0, 1.0])
        .unwrap();
    assert_eq!(on_corner, 0.0, "prec=1 must miss the transparent bbox corner");

    // The same corner with prec=0: bounding box says hit.
    let bbox_corner = s
        .call(&b, observer, "collision_point", &[185.0, 134.0, OBJ_PLAYER as f64, 0.0, 1.0])
        .unwrap();
    assert_eq!(bbox_corner, player as f64, "prec=0 keeps the bbox answer");
}

#[test]
fn maskless_fixture_falls_back_to_the_bounding_box() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle = load_bundle_from_file(Path::new(manifest_dir).join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
    let mut s = Scene::default();
    s.init_bundle(&bundle);
    // Fixture wiring: no sprite_bounds, no sprite_masks — the query must
    // behave exactly like before the feature (default 32x32 bbox), with no
    // silent gap where precise mode now answers "clear".
    let target = s.create(&bundle, OBJ_SPIKES, 150.0, 100.0).expect("create");
    s.write(target, -1, "sprite_index", None, SPR_SPIKES as f64).unwrap();
    let hit = s
        .call(&bundle, target, "collision_line", &[150.0, 105.0, 170.0, 105.0, -1.0, 1.0, 0.0])
        .unwrap();
    assert_eq!(hit, target as f64, "mask-less sprite keeps the bbox behaviour");
}
