//! obj_ghost (24, parent obj_ghost2 11) CODE 152 drives `mp_potential_step`
//! against the real solid set: par_wall (34) and everything under it. WL7
//! moved the candidate box onto the original Compute_BoundingBox, so the
//! fixture now wires the real SPRT records from `assets/game.droid` (the same
//! wiring `GameState::enable_ir_gameplay` does for the app) and derives the
//! wall placement from those boxes instead of the old 32x32 fixture default.
//!
//! Recorded geometry, asserted below:
//!   spr_ghost (81): bbox [13,47]x[4,46], sprite 64x48, origin (32,24)
//!                   => at (300,200) the box is [281,316) x [180,223)
//!   spr_wall  (5):  bbox [0,31]x[0,31], sprite 32x32, origin (0,0)
//!                   => at (x,200) the box is [x, x+32) x [200,232)
//!
//! The original fixture placed the wall 1px beyond the ghost's rectangle.
//! Under the recorded boxes the ghost's right edge is 316, so the wall's left
//! edge goes at 317: clear now, and a forward 3px step re-boxes the ghost at
//! [284,319), two pixels into the wall. Because the ghost's recorded box is
//! 35px wide and the step is only 3px, every small deflection still overlaps
//! and the first clear angle is the perpendicular one — exactly the "e.g. 90
//! or 270 deg" the original comment names.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;
use std::sync::Arc;

const PLAYER: i32 = 0;
const GHOST: i32 = 24;
const WALL: i32 = 4;

const GHOST_POS: (f64, f64) = (300., 200.);
/// Recorded boxes the placement is derived from.
const GHOST_BOX: (f64, f64, f64, f64) = (281., 316., 180., 223.);
const GHOST_STEP_BOX: (f64, f64, f64, f64) = (284., 319., 180., 223.);
/// Wall left edge = ghost right edge + 1px.
const WALL_X: f64 = 317.;

#[test]
fn mp_potential_step_avoids_solid_wall_obstacle() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    let asset = GameDroidAsset::parse(&Path::new(manifest_dir).join("../../assets/game.droid"))
        .expect("parse game.droid");
    bundle.string_table = asset.string_table.clone();
    let bundle = Arc::new(bundle);

    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();
    scene.globals.insert("level".into(), 5.0);
    scene.globals.insert("pwr".into(), 1.0);
    for (sid, sp) in &asset.sprites {
        scene.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
        if let Some(bbox) = sp.bbox {
            scene.sprite_bboxes.insert(*sid as i32, bbox);
        }
        if !sp.masks.is_empty() {
            scene.sprite_masks.insert(*sid as i32, sp.masks.clone());
        }
    }

    // Player at the ghost's target position (500, 200).
    let _player = scene.create(&bundle, PLAYER, 500.0, 200.0).expect("create player");
    // Ghost at (300, 200)
    let ghost = scene.create(&bundle, GHOST, GHOST_POS.0, GHOST_POS.1).expect("create ghost");

    // Box pins: the two recorded boxes must cover the ghost's centre, and the
    // ghost's current box must NOT overlap the wall — the step is what creates
    // the collision.
    assert_eq!(
        scene.bounds_for_instance(ghost),
        Some(GHOST_BOX),
        "ghost box [281,316)x[180,223) from spr_ghost's recorded bbox"
    );

    // Place a solid wall at WALL_X (child of par_wall 34, so it is in the
    // solid set).
    let wall = scene.create(&bundle, WALL, WALL_X, 200.0).expect("create wall");
    assert_eq!(
        scene.bounds_for_instance(wall),
        Some((WALL_X, WALL_X + 32., 200., 232.)),
        "obj_wall box [x, x+32)x[200,232) from spr_wall's recorded bbox"
    );
    assert!(
        GHOST_BOX.1 <= WALL_X && GHOST_STEP_BOX.1 > WALL_X,
        "clear at rest, in the way one step ahead"
    );

    let initial_gy = scene.instances[&ghost].fields["y"];

    // Step the ghost (CODE 152 calls mp_potential_step(player.x, player.y, 3, 0))
    scene.dispatch(&bundle, ghost, 3, 0).expect("ghost step");

    let cur_gy = scene.instances[&ghost].fields["y"];
    let dir = scene.instances[&ghost].fields["direction"];

    // In direct horizontal line (no obstacle), dir would be 0.0 and gy would remain 200.0.
    // With obstacle avoidance, the ghost must steer at an angle around the wall:
    assert!(
        (cur_gy - initial_gy).abs() > 0.01,
        "ghost must steer vertically around the blocking wall, got y={cur_gy} vs initial={initial_gy}"
    );
    assert_ne!(
        dir, 0.0,
        "ghost direction must not be a direct straight line into the wall, got dir={dir}"
    );
}
