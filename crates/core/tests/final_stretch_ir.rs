//! Final overworld stretch: room87-103, rm_boss6, the five challenge rooms and
//! the ending trigger. Door CODEs 977-1021 are checked through live instances
//! reached along the REAL portal chain; the boss6/challenge rooms and the
//! ending entry (obj_finalbosspuff Destroy -> room_goto 110) run from the real
//! bytecode. Scratch probes observed every value first (probes deleted).
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const INIT: i32 = 103;
const WARP: i32 = 69;
const WALL: i32 = 4;
const WALL2: i32 = 5;
const BOULDER: i32 = 6;
const PLATFORM: i32 = 7;
const SPIKES: i32 = 8;
const WATER: i32 = 9;
const COIN: i32 = 58;
const GEM: i32 = 59;
const CHEST: i32 = 100;
const WEAPONSWAP: i32 = 126;
const FINALBOSS: i32 = 30;
const FINALPUFF: i32 = 189;

fn setup() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();
    for (sid, sprite) in &asset.sprites {
        scene.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sprite.width as f64,
            height: sprite.height as f64,
            origin_x: sprite.origin_x as f64,
            origin_y: sprite.origin_y as f64,
            frames: sprite.tpag_indices.len().max(1) as f64,
        });
    }
    scene.load_room_from_data(&bundle, 0, &asset.rooms[0]).unwrap();
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).unwrap();
    scene.view_positions.insert(0, (0.0, 0.0));
    let player = scene.instances.iter()
        .find(|(_, instance)| instance.object == PLAYER && instance.alive)
        .map(|(id, _)| *id)
        .unwrap();
    (bundle, scene, player, asset)
}

fn cast(scene: &Scene, object: i32) -> usize {
    scene.instances.values().filter(|i| i.object == object && i.alive).count()
}

fn doors(scene: &Scene) -> Vec<(f64, f64, f64)> {
    scene.instances.values()
        .filter(|i| i.object == WARP && i.alive)
        .map(|i| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect()
}

fn walk(
    bundle: &callys_core::code_vm::Bundle,
    scene: &mut Scene,
    asset: &GameDroidAsset,
    player: i32,
    target: f64,
) {
    let portal = scene.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id)
        .unwrap();
    let (x, y) = (scene.instances[&portal].fields["x"], scene.instances[&portal].fields["y"]);
    scene.write(player, -1, "x", None, x).unwrap();
    scene.write(player, -1, "y", None, y).unwrap();
    for _ in 0..3 {
        scene.tick(bundle).unwrap();
        if scene.target_room_warp.is_some() { break; }
    }
    let destination = scene.target_room_warp.take().expect("portal CODE 13 warp");
    scene.transition_to_room(bundle, destination, &asset.rooms[destination]).unwrap();
}

fn reach_room86() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut scene, player, asset) = setup();
    scene.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for target in (5i32..=78).filter(|room| *room != 6).map(|room| room as f64) {
        walk(&bundle, &mut scene, &asset, player, target);
    }
    for target in 79i32..=86 {
        walk(&bundle, &mut scene, &asset, player, target as f64);
    }
    (bundle, scene, player, asset)
}

#[test]
fn room87_to_room103_branch_and_boss6_challenges_are_asset_exact() {
    let (bundle, mut scene, player, asset) = reach_room86();

    // room86's forward door (CODE 977) leads to room87.
    walk(&bundle, &mut scene, &asset, player, 87.0);
    assert_eq!(scene.current_room, 87.0, "asset87 = room87 (the last numbered stretch)");
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (128.0, 204.0),
        "CODE 978 pins the return landing");
    assert!(doors(&scene).contains(&(86.0, 1152.0, 1164.0)), "CODE 978 return pin");
    assert!(doors(&scene).contains(&(88.0, 128.0, 204.0)), "CODE 979 forward pin");

    // Walk the whole remaining numbered chain: 88..103.
    for room in 88i32..=103 {
        walk(&bundle, &mut scene, &asset, player, room as f64);
        assert_eq!(scene.current_room, room as f64,
            "the room{room} door chain is unbroken from room87");
        let live = scene.instances.values()
            .filter(|i| i.object == WARP && i.alive)
            .count();
        assert_eq!(live, 2, "room{room} carries exactly two live warp pins");
        assert!(scene.instances.values()
            .filter(|i| i.object == WARP && i.alive)
            .all(|i| i.fields.get("unlocked") == Some(&1.0)),
            "every door CODE 978-1011 pins unlocked=1");
    }

    // room103's forward door (CODE 1010) leads into rm_boss6 (room id 104).
    walk(&bundle, &mut scene, &asset, player, 104.0);
    assert_eq!(scene.current_room, 104.0, "asset104 = rm_boss6");
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (128.0, 140.0),
        "the landing is CODE 1010's warpx/warpy (the entering door's pin)");
    assert!(doors(&scene).contains(&(103.0, 1408.0, 364.0)), "CODE 1012 return pin to room103");
    assert!(cast(&scene, WALL) > 0, "the boss6 arena has geometry");

    // rm_boss6's only door (CODE 1012) leads back to room103 — the challenge
    // rooms are NOT reachable through the numbered-chain doors; they hang off
    // the overworld map (rm_map). Their door codes are still verified live:
    // load each challenge room directly and assert its door pins.
    for (room, back, forward) in [
        (105.0, (104.0, 128.0, 140.0), Some((106.0, 128.0, 140.0))),
        (106.0, (105.0, 1376.0, 908.0), Some((107.0, 128.0, 140.0))),
        (107.0, (106.0, 1888.0, 332.0), Some((108.0, 128.0, 140.0))),
        (108.0, (107.0, 1216.0, 492.0), Some((109.0, 128.0, 428.0))),
        (109.0, (108.0, 1376.0, 1164.0), None),
    ] {
        scene.transition_to_room(&bundle, room as usize, &asset.rooms[room as usize]).unwrap();
        assert_eq!(scene.current_room, room, "asset{room} = the challenge room");
        assert!(doors(&scene).contains(&back),
            "the challenge {room} has its door back (CODE 1013-1021 pin)");
        if let Some(fwd) = forward {
            assert!(doors(&scene).contains(&fwd), "and its forward pin to the next challenge");
        }
    }
}

#[test]
fn killing_the_final_boss_opens_the_ending() {
    let b = load_bundle_from_file(Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json")).unwrap();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.init_fresh_start_globals();
    let init = s.create(&b, INIT, -1000.0, -1000.0).unwrap();
    s.instances.get_mut(&init).unwrap().alive = false;
    let p = s.create(&b, PLAYER, 500.0, 200.0).unwrap();
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    s.instances.get_mut(&p).unwrap().fields.insert("gravity".into(), 0.0);
    s.instances.get_mut(&fb).unwrap().fields.insert("hpfinalboss".into(), 0.0);

    // Death: Step arms a0=1 -> A0 kills -> Destroy spawns obj_finalbosspuff.
    s.dispatch(&b, fb, 3, 0).expect("step at hp 0");
    s.tick(&b).unwrap();
    assert!(!s.instances[&fb].alive);
    let (pid, _) = s.instances.iter().find(|(_, x)| x.object == FINALPUFF && x.alive).unwrap();
    let pid = *pid;
    // The puff fans smoke out in four expanding rings (A0=10/A1=20/A2=30) and dies at a3=129.
    assert_eq!(s.instances[&pid].alarms[0], 10, "CODE 786 arms the 10-tick smoke ring");
    assert_eq!(s.instances[&pid].alarms[1], 20);
    assert_eq!(s.instances[&pid].alarms[2], 30);
    assert_eq!(s.instances[&pid].alarms[3], 129, "the puff's hard lifetime is 129 ticks");

    // The puff's Destroy IS the ending trigger: deactivate everything, room_goto 110.
    s.destroy(&b, pid).expect("puff destroy");
    assert_eq!(s.target_room_warp, Some(110),
        "CODE 787 room_goto(110) — killing the final boss opens rm_ending");
}
