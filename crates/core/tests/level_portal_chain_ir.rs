//! Room chain through real warp portals: rm_town -> rm_level1 -> rm_level2 ->
//! rm_level1, every hop triggered by the original CODE 13 collision event on
//! obj_warpanywhere (id 69) — the player physically walks onto the portal,
//! the creation-code-pinned `other.warproom/warpx/warpy/unlocked` fields drive
//! `room_goto` plus player reposition, and the client's transition loop
//! consumes target_room_warp exactly as GameState::step does. The rm_level2
//! leg also verifies the room's distinct cast (obj_enemy2) and the CODE 12
//! spike hazard branch (distance_to_object(obj_spikes) <= 1 -> health1 = 1).
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn level1_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
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
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("warp town -> rm_level1");
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, s, player, asset)
}

/// Client-equivalent transition: CODE 13 queued target_room_warp via room_goto;
/// the loop mirrors GameState::step's consumption of the warp slot.
fn pump_transition(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset) -> Option<usize> {
    let target = s.target_room_warp.take()?;
    let room = &asset.rooms[target];
    s.transition_to_room(bundle, target, room).expect("transition after room_goto");
    Some(target)
}

/// Walk the player onto the level1 -> level2 portal and let the collision
/// event fire; returns the room after the client-equivalent transition pump.
fn step_onto_portal_to(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, want_room: f64) -> Option<usize> {
    // Find obj_warpanywhere instance whose creation code pinned this target.
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == 69 && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(want_room))
        .map(|(id, _)| *id)
        .expect("portal instance with pinned warproom");
    let px = s.instances[&portal].fields["x"];
    let py = s.instances[&portal].fields["y"];
    let player = s.instances.iter()
        .find(|(_, i)| i.object == 0 && i.alive)
        .map(|(id, _)| *id)
        .unwrap();
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    assert!(s.target_room_warp.is_some(), "CODE 13 must queue room_goto on portal overlap");
    pump_transition(bundle, s, asset)
}

#[test]
fn level1_to_level2_portal_chain_carries_player_and_cast() {
    let (bundle, mut s, player, asset) = level1_scene();

    // CODE 805 pinned this portal pre-unlocked (warproom 2, spawn 128,492).
    let arrived = step_onto_portal_to(&bundle, &mut s, &asset, 2.0).expect("transition pumps to Some");
    assert_eq!(arrived, 2, "rm_level2 is room index 2");
    assert_eq!(s.current_room, 2.0);

    // CODE 13's own reposition: obj_player.x/y := other.warpx/warpy (128/492).
    let p = &s.instances[&player];
    assert_eq!(p.fields["x"], 128.0, "warp destination x pinned by CODE 805");
    assert_eq!(p.fields["y"], 492.0, "warp destination y pinned by CODE 805");

    // rm_level2 geometry + distinct cast survive a few clean ticks.
    assert_eq!(s.room_tiles.len(), asset.rooms[2].tiles.len());
    assert!(s.instances.values().any(|i| i.object == 22 && i.alive),
        "obj_enemy2 patrols rm_level2");
    let enemy2 = s.instances.iter()
        .filter(|(_, i)| i.object == 22 && i.alive)
        .count();
    assert_eq!(enemy2, 1, "rm_level2 casts exactly one obj_enemy2");
    let spikes = s.instances.values().filter(|i| i.object == 8 && i.alive).count();
    assert_eq!(spikes, 27, "rm_level2 keeps its 27-spike field");
    for _ in 0..20 {
        s.tick(&bundle).unwrap();
    }
    assert_eq!(s.globals["health1"], 4.0, "standing away from hazards costs nothing");

    // Portal back: CODE 808 (warproom 1, spawn 1856,1164, pre-unlocked).
    let back = step_onto_portal_to(&bundle, &mut s, &asset, 1.0).expect("back transition");
    assert_eq!(back, 1, "portal chain returns to rm_level1");
    let p = &s.instances[&player];
    assert_eq!(p.fields["x"], 1856.0, "CODE 808 reposition to the level1 side");
    assert_eq!(p.fields["y"], 1164.0);
    // Persistent player/UI survived both hops; the transient cast re-materialized.
    assert!(s.instances.values().any(|i| i.object == 66 && i.alive), "obj_UI persistent");
    assert_eq!(s.instances.values().filter(|i| i.object == 14 && i.alive).count(), 5,
        "rm_level1's obj_enemy cast re-materialized");
}

#[test]
fn spike_field_in_level2_downs_the_player_through_code12() {
    let (bundle, mut s, player, asset) = level1_scene();
    step_onto_portal_to(&bundle, &mut s, &asset, 2.0).expect("in rm_level2");

    // Land the player on a spike: CODE 12 distance_to_object(obj_spikes) <= 1
    // force-sets health1 = 1 / playerhp = 1; the following tick's branch spawns
    // obj_youhavedied (134), queues snd_youhavedied (26) and bumps playerdied.
    let spike = s.instances.iter()
        .find(|(_, i)| i.object == 8 && i.alive)
        .map(|(id, _)| *id)
        .expect("spike present");
    let sx = s.instances[&spike].fields["x"];
    let sy = s.instances[&spike].fields["y"];
    s.write(player, -1, "x", None, sx).unwrap();
    s.write(player, -1, "y", None, sy).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.globals["health1"], 1.0, "spike contact forces health1 = 1 (CODE 12)");
    assert_eq!(s.instances[&player].fields["playerhp"], 1.0);

    s.tick(&bundle).unwrap();
    assert!(s.instances.values().any(|i| i.object == 134 && i.alive),
        "death controller obj_youhavedied spawned");
    assert_eq!(s.globals["playerdied"], 1.0, "death counter latched once");
    assert!(s.audio.iter().any(|c| c.sound == 26 && !c.looping), "snd_youhavedied queued");
}

#[test]
fn locked_level1_portal_blocks_without_the_key() {
    // town -> level1 first; then exercise the LOCKED branch of CODE 13 against
    // the same portal by rewriting unlocked/haskey like a fresh player would
    // encounter a pre-CODE-805 world (unlocked==0, haskey==0 -> warplock).
    let (bundle, mut s, player, _asset) = level1_scene();
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == 69 && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(2.0))
        .map(|(id, _)| *id)
        .expect("level1 -> level2 portal");
    let px = s.instances[&portal].fields["x"];
    let py = s.instances[&portal].fields["y"];
    s.write(portal, -1, "unlocked", None, 0.0).unwrap();
    s.globals.insert("haskey".into(), 0.0);
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(&bundle).unwrap();
    }
    assert!(s.target_room_warp.is_none(), "locked portal must not room_goto");
    assert_eq!(s.globals["warplock"], 1.0, "CODE 13 no-key branch arms global.warplock");
    assert_eq!(s.current_room, 1.0, "player stays in rm_level1");
}
