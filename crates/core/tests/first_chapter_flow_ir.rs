//! First-chapter playable-flow contract: town -> Caves -> Boss 1.
//! Every hop is triggered through the room's real obj_warpanywhere creation-code
//! fields; this is intentionally a flow test, not a direct room-index smoke test.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const ENEMY: i32 = 14;
const KNIFEBANDIT: i32 = 15;
const SHOOTER1: i32 = 16;
const ENEMY2: i32 = 22;
const WOLF: i32 = 23;
const BAT: i32 = 31;
const SLIME: i32 = 32;
const BOULDER: i32 = 6;
const SPIKES: i32 = 8;
const WATERSURFACE: i32 = 9;
const TREASURE_CHEST: i32 = 100;
const TREX: i32 = 25;
const BOSSBOULDER: i32 = 3;

fn scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sp.width as f64,
            height: sp.height as f64,
            origin_x: sp.origin_x as f64,
            origin_y: sp.origin_y as f64,
            frames: sp.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).unwrap();
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();
    let player = s.instances.iter().find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id).unwrap();
    (bundle, s, player, asset)
}

fn cast(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|i| i.object == object && i.alive).count()
}

fn walk_to(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, target: f64) {
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id).unwrap_or_else(|| {
            let doors: Vec<_> = s.instances.iter()
                .filter(|(_, i)| i.object == WARP && i.alive && i.active)
                .map(|(_, i)| i.fields.get("warproom").copied())
                .collect();
            panic!("expected chapter portal target {target} in room {}: {doors:?}", s.current_room);
        });
    let (x, y) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, x).unwrap();
    s.write(player, -1, "y", None, y).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    let room = s.target_room_warp.take().expect("portal must queue room_goto");
    s.transition_to_room(bundle, room, &asset.rooms[room]).unwrap();
}

#[test]
fn first_chapter_walks_every_mainline_and_side_portal_to_boss1() {
    let (bundle, mut s, player, asset) = scene();
    assert_eq!(s.current_room, 1.0);
    assert_eq!(asset.rooms[1].name, "rm_level1");
    assert_eq!(cast(&s, ENEMY), 5);
    assert_eq!(cast(&s, KNIFEBANDIT), 2);
    assert_eq!(s.globals["level1visited"], 1.0);

    walk_to(&bundle, &mut s, &asset, player, 2.0);
    assert_eq!(asset.rooms[2].name, "rm_level2");
    assert_eq!(cast(&s, ENEMY2), 1);
    assert_eq!(cast(&s, SPIKES), 27);

    walk_to(&bundle, &mut s, &asset, player, 3.0);
    assert_eq!(asset.rooms[3].name, "rm_level3");
    assert_eq!(cast(&s, BAT), 2);
    assert_eq!(cast(&s, WATERSURFACE), 59);
    assert_eq!(cast(&s, TREASURE_CHEST), 6);

    walk_to(&bundle, &mut s, &asset, player, 4.0);
    assert_eq!(asset.rooms[4].name, "rm_level4");
    assert_eq!(cast(&s, WOLF), 2);
    assert_eq!(cast(&s, BAT), 2);

    walk_to(&bundle, &mut s, &asset, player, 5.0);
    assert_eq!(asset.rooms[5].name, "rm_level5");
    assert_eq!(cast(&s, ENEMY), 2);
    assert_eq!(cast(&s, KNIFEBANDIT), 1);
    assert_eq!(cast(&s, WOLF), 2);

    // Mainline room 5 -> room 6 (CODE 814), then the only return path is kept.
    walk_to(&bundle, &mut s, &asset, player, 6.0);
    assert_eq!(asset.rooms[6].name, "rm_level6");
    assert_eq!(cast(&s, TREASURE_CHEST), 14);
    assert_eq!(cast(&s, ENEMY), 0);

    // Room 6 returns to room 5; room 5's CODE 815 opens room 7.
    walk_to(&bundle, &mut s, &asset, player, 5.0);
    walk_to(&bundle, &mut s, &asset, player, 7.0);
    assert_eq!(asset.rooms[7].name, "rm_level7");
    assert_eq!(cast(&s, KNIFEBANDIT), 1);
    assert_eq!(cast(&s, SHOOTER1), 1);
    assert_eq!(cast(&s, WOLF), 1);
    assert_eq!(cast(&s, BAT), 2);

    walk_to(&bundle, &mut s, &asset, player, 8.0);
    assert_eq!(asset.rooms[8].name, "rm_level8");
    assert_eq!(cast(&s, ENEMY), 3);
    assert_eq!(cast(&s, KNIFEBANDIT), 8);
    assert_eq!(cast(&s, WOLF), 1);

    // The chapter's weapon side room is not skipped: level8 -> level8a.
    walk_to(&bundle, &mut s, &asset, player, 9.0);
    assert_eq!(asset.rooms[9].name, "rm_level8a");
    assert_eq!(cast(&s, ENEMY), 5);
    assert_eq!(cast(&s, KNIFEBANDIT), 3);
    assert_eq!(cast(&s, SHOOTER1), 2);
    assert_eq!(cast(&s, WOLF), 3);

    // CODE 821 exits the side room into Boss 1, not rm_level9.
    walk_to(&bundle, &mut s, &asset, player, 10.0);
    assert_eq!(asset.rooms[10].name, "rm_boss1");
    assert_eq!(cast(&s, TREX), 1);
    assert!(cast(&s, BOSSBOULDER) >= 1);
    assert_eq!(s.globals["boss1dead"], 0.0);
    assert!(s.instances[&player].alive);
}
