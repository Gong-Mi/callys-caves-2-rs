//! room80-83 (asset rooms 79-82) post-Boss4 branch chain, sixteenth
//! segment. Door CODEs 962-969 are checked through live instances; all four
//! rooms are reached through the existing portal chain and returned in reverse.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const WALL: i32 = 4;
const WALL2: i32 = 5;
const BOULDER: i32 = 6;
const PLATFORM: i32 = 7;
const WATER: i32 = 9;
const WATERFILL: i32 = 10;
const ZOMBIE: i32 = 19;
const ENEMY2: i32 = 22;
const GHOST: i32 = 24;
const FIRESLIME: i32 = 33;
const COIN: i32 = 58;
const CHEST: i32 = 100;
const BOSS5: i32 = 29;
const WEAPONSWAP: i32 = 126;

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

fn assert_doors(scene: &Scene, asset_room: usize) {
    let live: Vec<_> = scene.instances.values()
        .filter(|i| i.object == WARP && i.alive)
        .collect();
    assert_eq!(live.len(), 2, "asset room {asset_room} has two live warp pins");
    assert!(live.iter().all(|i| i.fields.get("unlocked") == Some(&1.0)),
        "CODE 962-969 pins unlocked=1 in asset room {asset_room}");
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

fn reach78() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut scene, player, asset) = setup();
    scene.transition_to_room(&bundle, 4, &asset.rooms[4]).unwrap();
    for target in (5i32..=78).filter(|room| *room != 6).map(|room| room as f64) {
        walk(&bundle, &mut scene, &asset, player, target);
    }
    (bundle, scene, player, asset)
}

#[test]
fn room80_to_boss5_branch_and_full_return_chain_are_asset_exact() {
    let (bundle, mut scene, player, asset) = reach78();

    walk(&bundle, &mut scene, &asset, player, 79.0);
    assert_eq!(scene.current_room, 79.0, "asset79 = room80");
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&scene, WALL), 60);
    assert_eq!(cast(&scene, WALL2), 169);
    assert_eq!(cast(&scene, BOULDER), 152);
    assert_eq!(cast(&scene, FIRESLIME), 8);
    assert_eq!(cast(&scene, COIN), 2);
    assert_eq!(cast(&scene, WEAPONSWAP), 1);
    assert!(doors(&scene).contains(&(78.0, 1440.0, 524.0)), "CODE 962 return pin");
    assert!(doors(&scene).contains(&(80.0, 128.0, 204.0)), "CODE 963 forward pin");
    assert_doors(&scene, 79);

    walk(&bundle, &mut scene, &asset, player, 80.0);
    assert_eq!(scene.current_room, 80.0, "asset80 = room81");
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&scene, WALL), 81);
    assert_eq!(cast(&scene, WALL2), 63);
    assert_eq!(cast(&scene, BOULDER), 156);
    assert_eq!(cast(&scene, ENEMY2), 1);
    assert_eq!(cast(&scene, ZOMBIE), 6);
    assert_eq!(cast(&scene, COIN), 12);
    assert_eq!(cast(&scene, CHEST), 1);
    assert_eq!(cast(&scene, WEAPONSWAP), 1);
    assert!(doors(&scene).contains(&(79.0, 896.0, 204.0)), "CODE 964 return pin");
    assert!(doors(&scene).contains(&(81.0, 128.0, 204.0)), "CODE 965 forward pin");
    assert_doors(&scene, 80);

    walk(&bundle, &mut scene, &asset, player, 81.0);
    assert_eq!(scene.current_room, 81.0, "asset81 = room82");
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (128.0, 204.0));
    assert_eq!(cast(&scene, WALL), 69);
    assert_eq!(cast(&scene, WALL2), 120);
    assert_eq!(cast(&scene, BOULDER), 45);
    assert_eq!(cast(&scene, ENEMY2), 2);
    assert_eq!(cast(&scene, GHOST), 4);
    assert_eq!(cast(&scene, WATER), 21);
    assert_eq!(cast(&scene, WATERFILL), 9);
    assert_eq!(cast(&scene, COIN), 13);
    assert_eq!(cast(&scene, WEAPONSWAP), 1);
    assert!(doors(&scene).contains(&(80.0, 1152.0, 364.0)), "CODE 966 return pin");
    assert!(doors(&scene).contains(&(82.0, 128.0, 140.0)), "CODE 967 forward pin");
    assert_doors(&scene, 81);

    walk(&bundle, &mut scene, &asset, player, 82.0);
    assert_eq!(scene.current_room, 82.0, "asset82 = rm_boss5");
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (128.0, 140.0));
    assert_eq!(cast(&scene, WALL), 76);
    assert_eq!(cast(&scene, WALL2), 120);
    assert_eq!(cast(&scene, BOULDER), 56);
    assert_eq!(cast(&scene, PLATFORM), 5);
    assert_eq!(cast(&scene, BOSS5), 1);
    assert_eq!(cast(&scene, WEAPONSWAP), 1);
    assert!(doors(&scene).contains(&(81.0, 1440.0, 204.0)), "CODE 968 return pin");
    assert!(doors(&scene).contains(&(83.0, 128.0, 204.0)), "CODE 969 forward pin");
    assert_doors(&scene, 82);

    walk(&bundle, &mut scene, &asset, player, 81.0);
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (1440.0, 204.0));
    walk(&bundle, &mut scene, &asset, player, 80.0);
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (1152.0, 364.0));
    walk(&bundle, &mut scene, &asset, player, 79.0);
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (896.0, 204.0));
    walk(&bundle, &mut scene, &asset, player, 78.0);
    assert_eq!(scene.current_room, 78.0);
    assert_eq!((scene.instances[&player].fields["x"], scene.instances[&player].fields["y"]), (1440.0, 524.0));
    assert_eq!(cast(&scene, WEAPONSWAP), 1, "room79 respawns its weaponswap on return");
}
