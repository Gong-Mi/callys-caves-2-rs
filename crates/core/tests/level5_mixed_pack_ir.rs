//! rm_level5's mixed pack: every first-tier ground enemy (obj_enemy 14,
//! obj_knifebandit 15, obj_wolf 23) shares the par_enemy (11) parent chain,
//! and one obj_bullet mold (CODE 284) dispatches species-specific HP fields
//! and death cascades. Reached through the real CODE 812 portal from
//! rm_level4 (warproom 5, landing 160,300). Also proves CODE 361's
//! `with (par_enemy)` dormancy sweep is polymorphic: a far-away bandit
//! sleeps through the parent-chain selector while the near wolf patrols.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level5_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
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
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load rm_town");
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("town -> level1");
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, s, player, asset)
}

/// Walk the CODE-pinned portal toward `want_room` and pump the transition.
fn walk_portal(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, want_room: f64) {
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == 69 && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(want_room))
        .map(|(id, _)| *id)
        .expect("portal instance with pinned warproom");
    let px = s.instances[&portal].fields["x"];
    let py = s.instances[&portal].fields["y"];
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    assert!(s.target_room_warp.is_some(), "CODE 13 must queue room_goto on portal overlap");
    let target = s.target_room_warp.take().unwrap();
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("portal transition");
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

#[test]
fn portal_level4_to_level5_delivers_the_mixed_pack() {
    let (bundle, mut s, player, asset) = level5_scene();
    walk_portal(&bundle, &mut s, &asset, player, 5.0);
    assert_eq!(s.current_room, 5.0, "CODE 812 pinned warproom 5");
    let p = &s.instances[&player];
    assert_eq!(p.fields["x"], 160.0, "CODE 812 landing x");
    assert_eq!(p.fields["y"], 300.0, "CODE 812 landing y");

    assert_eq!(cast(&s, 14).len(), 2, "two obj_enemy");
    assert_eq!(cast(&s, 15).len(), 1, "one obj_knifebandit");
    assert_eq!(cast(&s, 23).len(), 2, "two obj_wolf");
    // Parent chain data proves the shared mold: all three resolve par_enemy 11.
    for o in [14i32, 15, 23] {
        assert!(s.object_parents[&o].contains(&11), "object {o} chains through par_enemy");
    }
    // 20 clean frames with three species' Steps interlocking.
    for _ in 0..20 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], 4.0, "the landing zone is safe");
}

#[test]
fn one_bullet_mold_kills_three_species_through_their_own_fields() {
    let (bundle, mut s, player, asset) = level5_scene();
    walk_portal(&bundle, &mut s, &asset, player, 5.0);

    // Arena: clear ground at y=584, player invulnerable, three species
    // 80 px apart down the firing lane, each on its last HP.
    s.write(player, -1, "x", None, 500.0).unwrap();
    s.write(player, -1, "y", None, 584.0).unwrap();
    s.write(player, -1, "facing", None, 0.0).unwrap();
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();

    let bandit = cast(&s, 15)[0];
    let enemy = cast(&s, 14)[0];
    let wolf = cast(&s, 23)[0];
    let field: [(&str, i32); 3] = [("hpknife", bandit), ("hp", enemy), ("hpwolf", wolf)];
    for (n, (fname, id)) in field.iter().enumerate() {
        s.write(*id, -1, "x", None, 580.0 + 80.0 * n as f64).unwrap();
        s.write(*id, -1, "y", None, 584.0).unwrap();
        s.write(*id, -1, fname, None, 1.0).unwrap();
        s.instances.get_mut(id).unwrap().active = true;
    }

    // Verified duel geometry from the earlier species batches: target 40 px
    // downrange at the player's y, consumed by the first or second tick.
    // Each round the next survivor is dragged into that slot; hits must land
    // on a still-alive species through that species' own HP field.
    let mut xp_expected = 1.0;
    let mut kills = 0;
    for round in 0..3 {
        let (fname, target) = *field.iter()
            .find(|(_, id)| s.instances[id].alive)
            .expect("a survivor remains");
        let px2 = s.instances[&player].fields["x"];
        s.write(target, -1, "x", None, px2 + 40.0).unwrap();
        s.write(target, -1, "y", None, s.instances[&player].fields["y"]).unwrap();
        s.write(target, -1, fname, None, 1.0).unwrap();
        s.instances.get_mut(&target).unwrap().active = true;
        s.write(player, -1, "facing", None, 0.0).unwrap();

        s.dispatch(&bundle, player, 2, 0).unwrap(); // CODE 11
        let bullet = s.instances.iter()
            .filter(|(_, i)| i.object == 39 && i.alive)
            .map(|(id, _)| *id)
            .last()
            .expect("bullet queued");
        let mut consumed = false;
        for _ in 0..6 {
            s.write(player, -1, "x", None, px2).unwrap();
            s.write(target, -1, "x", None, px2 + 40.0).unwrap();
            s.write(target, -1, "y", None, s.instances[&player].fields["y"]).unwrap();
            s.instances.get_mut(&target).unwrap().active = true;
            s.tick(&bundle).unwrap();
            if !s.instances[&bullet].alive { consumed = true; break; }
        }
        assert!(consumed, "round {round}: bullet spent itself on the lane");
        assert_eq!(s.instances[&target].fields[fname], 0.0,
            "round {round}: {fname} zeroed through the species' CODE 284 branch");
        assert_eq!(s.globals["pistolxp"], xp_expected, "each species refunds xp once");
        xp_expected += 1.0;

        let mut died = false;
        for _ in 0..6 {
            s.instances.get_mut(&target).unwrap().active = true;
            s.tick(&bundle).unwrap();
            if !s.instances[&target].alive { died = true; break; }
        }
        assert!(died, "round {round}: species death cascade removed the body");
        kills += 1;
    }
    assert_eq!(kills, 3, "three species, one shared bullet mold");
    assert!(!s.instances[&bandit].alive && !s.instances[&enemy].alive && !s.instances[&wolf].alive,
        "all three species died through the shared bullet mold");
    // Fresh-start pistolxp is 0.0; three hits refund one each.
    assert_eq!(s.globals["pistolxp"], 3.0, "xp ledger: three kills, one refund each");
    assert_eq!(s.globals["health1"], 4.0, "the arena spent no player health");
    assert!(s.audio.iter().any(|c| c.sound == 7 && !c.looping), "snd_explode for the cascades");
}

#[test]
fn dormancy_sweep_sleeps_the_far_bandit_while_the_near_wolf_paces() {
    let (bundle, mut s, player, asset) = level5_scene();
    walk_portal(&bundle, &mut s, &asset, player, 5.0);

    let wolf = cast(&s, 23)[0];
    let bandit = cast(&s, 15)[0];
    // Wolf right beside the player, bandit parked 700 px away.
    s.write(player, -1, "x", None, 500.0).unwrap();
    s.write(player, -1, "y", None, 584.0).unwrap();
    s.write(wolf, -1, "x", None, 560.0).unwrap();
    s.write(wolf, -1, "y", None, 584.0).unwrap();
    s.write(bandit, -1, "x", None, 1200.0).unwrap();
    s.write(bandit, -1, "y", None, 584.0).unwrap();
    s.instances.get_mut(&wolf).unwrap().active = true;
    s.instances.get_mut(&bandit).unwrap().active = true;

    // obj_bg Alarm 2 (CODE 361) runs its par_enemy sweep every 15 ticks.
    let mut bandit_slept = false;
    let mut wolf_alive_active = true;
    for _ in 0..40 {
        // Hold the player and the near wolf in place so the sweep's distances
        // stay pinned to the arena layout.
        s.write(player, -1, "x", None, 500.0).unwrap();
        s.write(player, -1, "y", None, 584.0).unwrap();
        s.tick(&bundle).unwrap();
        if let Some(b) = s.instances.get(&bandit) {
            if !b.active { bandit_slept = true; }
        }
        if let Some(w) = s.instances.get(&wolf) {
            if w.alive && !w.active { wolf_alive_active = false; }
        }
        s.write(bandit, -1, "x", None, 1200.0).unwrap();
        s.write(bandit, -1, "y", None, 584.0).unwrap();
    }
    assert!(bandit_slept,
        "CODE 361's with (par_enemy) reached the far bandit through the parent chain");
    assert!(wolf_alive_active,
        "the near wolf was NOT swept out — the 450 px gate is per-instance distance");
}
