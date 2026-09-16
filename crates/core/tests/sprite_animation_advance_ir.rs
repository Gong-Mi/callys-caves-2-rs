//! Sprite animation advance: the GMS standard per-step cycle
//! image_index += image_speed (wrap forward, reflect backward, stop at 1 frame)
//! is currently missing from Scene::tick — image_index stays 0 forever, so
//! every multi-frame sprite draws frame 0 only. These tests lock the original
//! semantics from the recovered GML (CODE 548 image_speed=0.3, CODE 12
//! image_speed=0.6, image_index=0 resets on sprite switch).
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host, Object};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn fixture_bundle() -> Bundle {
    Bundle {
        schema: 1,
        string_table: vec![],
        objects: vec![Object {
            id: 1,
            name: "anim_object".into(),
            sprite: 10,
            depth: 0,
            parent: -100,
            parent_chain: vec![],
            events: vec![],
        }],
        room_bindings: vec![],
        codes: vec![],
    }
}

#[test]
fn image_index_advances_by_image_speed_and_wraps_over_frames() {
    let bundle = fixture_bundle();
    let mut s = Scene::default();
    s.sprite_bounds.insert(10, SpriteBounds { width: 32.0, height: 32.0, origin_x: 0.0, origin_y: 0.0, frames: 4.0 });
    let id = s.insert_external(1);
    s.instances.get_mut(&id).unwrap().external = false;
    s.write(id, -1, "sprite_index", None, 10.0).unwrap();
    s.write(id, -1, "image_index", None, 0.0).unwrap();
    s.write(id, -1, "image_speed", None, 1.0).unwrap();

    // Default image_speed = 1.0 over a 4-frame sprite: 0,1,2,3,0,...
    for expected in [1.0, 2.0, 3.0, 0.0] {
        s.tick(&bundle).unwrap();
        assert_eq!(s.read(id, -1, "image_index", None).unwrap(), expected);
    }

    // Fractional speed (the CODE 548 / CODE 12 pattern): 0.3 accumulates.
    s.write(id, -1, "image_speed", None, 0.3).unwrap();
    s.write(id, -1, "image_index", None, 0.0).unwrap();
    for expected in [0.3, 0.6, 0.9, 1.2, 1.5, 1.8, 2.1, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 0.2] {
        s.tick(&bundle).unwrap();
        let got = s.read(id, -1, "image_index", None).unwrap();
        assert!((got - expected).abs() < 1e-9, "after speed 0.3 tick: {got} != {expected}");
    }
}

#[test]
fn single_frame_sprite_stays_clamped_and_reversed_play_reflects() {
    let bundle = fixture_bundle();
    let mut s = Scene::default();
    s.sprite_bounds.insert(10, SpriteBounds { width: 32.0, height: 32.0, origin_x: 0.0, origin_y: 0.0, frames: 1.0 });
    let id = s.insert_external(1);
    s.instances.get_mut(&id).unwrap().external = false;
    s.write(id, -1, "sprite_index", None, 10.0).unwrap();
    s.write(id, -1, "image_index", None, 0.0).unwrap();
    s.write(id, -1, "image_speed", None, 1.0).unwrap();

    // 1-frame sprite: advance is a no-op even with the default speed 1.0.
    for _ in 0..3 {
        s.tick(&bundle).unwrap();
        assert_eq!(s.read(id, -1, "image_index", None).unwrap(), 0.0);
    }

    // Reverse playback (GMS image_speed < 0 reflects at sub 0): 0,-0.5 -> 0.5.
    s.sprite_bounds.insert(10, SpriteBounds { width: 32.0, height: 32.0, origin_x: 0.0, origin_y: 0.0, frames: 3.0 });
    s.write(id, -1, "image_speed", None, -0.5).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.read(id, -1, "image_index", None).unwrap(), 0.5);
    s.write(id, -1, "image_index", None, 0.25).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.read(id, -1, "image_index", None).unwrap(), 0.25);
}

#[test]
fn draw_view_emits_advancing_frames_and_image_number_reads() {
    let bundle = fixture_bundle();
    let mut s = Scene::default();
    s.sprite_bounds.insert(10, SpriteBounds { width: 32.0, height: 32.0, origin_x: 0.0, origin_y: 0.0, frames: 4.0 });
    s.view_positions.insert(0, (0.0, 0.0));
    let id = s.create(&bundle, 1, 100.0, 100.0).unwrap();

    assert_eq!(s.read(id, -1, "image_number", None).unwrap(), 4.0);

    let mut seen = Vec::new();
    for _ in 0..6 {
        s.tick(&bundle).unwrap();
        s.draw_view(&bundle, 0).unwrap();
        let d = s.draws.iter().find(|d| d.instance == id).expect("draw_self-less default draw present");
        seen.push(d.frame);
    }
    // The DrawCommand frame must actually walk the 4-frame cycle, not pin 0.
    assert_eq!(seen, vec![1.0, 2.0, 3.0, 0.0, 1.0, 2.0]);
}

#[test]
fn rm_level1_bandit_and_player_animation_runs_from_real_bytecode() {
    use callys_asset::GameDroidAsset;
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
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
    }
    let town = &asset.rooms[0];
    assert_eq!(town.name, "rm_town");
    s.load_room_from_data(&bundle, 0, town).expect("load rm_town");
    let level1 = &asset.rooms[1];
    assert_eq!(level1.name, "rm_level1");
    s.transition_to_room(&bundle, 1, level1).expect("warp town -> rm_level1");

    // obj_knifebandit draws spr_knifebandit (59), a 48-frame sprite. Under the
    // default image_speed = 1.0 the engine cycle advances it every tick while
    // the instance is active; when the original obj_bg dormancy sweep (CODE 361)
    // deactivates it off-screen, image_index must freeze (deactivated instances
    // do not run per-step events, GMS instance_activate_region semantics).
    let bandit = s.instances.iter()
        .find(|(_, i)| i.object == 15 && i.alive && i.active)
        .map(|(id, _)| *id)
        .expect("a live obj_knifebandit exists in rm_level1");
    assert_eq!(s.read(bandit, -1, "sprite_index", None).unwrap(), 59.0);
    assert_eq!(s.read(bandit, -1, "image_number", None).unwrap(), 48.0);
    assert_eq!(s.read(bandit, -1, "image_index", None).unwrap(), 0.0);
    s.tick(&bundle).unwrap();
    assert_eq!(s.read(bandit, -1, "image_index", None).unwrap(), 1.0);

    let mut advanced = 1;
    let mut frozen_inactive = 0;
    for _ in 0..59 {
        let before = s.read(bandit, -1, "image_index", None).unwrap();
        let sprite_before = s.read(bandit, -1, "sprite_index", None).unwrap();
        s.tick(&bundle).unwrap();
        let after = s.instances[&bandit].fields.get("image_index").copied().unwrap();
        let active_now = s.instances[&bandit].active;
        let frames = s.read(bandit, -1, "image_number", None).unwrap();
        assert!(after >= 0.0 && after < frames.max(1.0),
            "frame {after} escaped sprite {sprite_before} (frames {frames})");
        if !active_now {
            // Dormant: the animation cycle must not move it.
            assert_eq!(after, before, "deactivated bandit image_index must freeze");
            frozen_inactive += 1;
        } else if s.instances[&bandit].fields.get("sprite_index").copied() == Some(sprite_before) {
            if after != before { advanced += 1; }
        }
    }
    assert!(frozen_inactive > 30,
        "the CODE 361 dormancy sweep kept the bandit frozen ({frozen_inactive}/59 ticks)");
    assert!(advanced >= 4, "the bandit animated at least one visible cycle before dormancy ({advanced} advances)");

    // The real player runs Step CODE 12 every tick, which force-writes
    // sprite_index (and resets image_index on switch). The engine cycle must
    // therefore keep the player's frame inside its current sprite window and
    // keep advancing while active, whatever the bytecode switches to.
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive && i.active)
        .map(|(id, _)| *id)
        .expect("the persistent player survived the warp");
    s.write(player, -1, "image_speed", None, 0.6).unwrap();
    let mut moved = 0;
    let mut switched = 0;
    let mut sprite_prev = s.read(player, -1, "sprite_index", None).unwrap();
    for _ in 0..40 {
        s.write(player, -1, "image_speed", None, 0.6).unwrap();
        let before = s.read(player, -1, "image_index", None).unwrap();
        s.tick(&bundle).unwrap();
        if !s.instances[&player].active { continue; }
        let after = s.read(player, -1, "image_index", None).unwrap();
        let frames = s.read(player, -1, "image_number", None).unwrap();
        assert!(after >= 0.0 && after < frames.max(1.0),
            "player frame {after} escaped sprite {sprite_prev} window (frames {frames})");
        let sprite_now = s.read(player, -1, "sprite_index", None).unwrap();
        if sprite_now != sprite_prev { switched += 1; sprite_prev = sprite_now; }
        else if after != before { moved += 1; }
    }
    assert!(moved >= 20, "player animation advanced across the run ({moved} moves, {switched} CODE-12 sprite switches)");
}
