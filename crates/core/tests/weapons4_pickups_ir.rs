//! The remaining four placed weapon pickups: bladegun, flamethrower,
//! bombgun and boomerang. Each is checked in its real asset room against the
//! original Create/Step bytecode, including beacon geometry, exclusive weapon
//! globals, banner hand-off, and the already-bought room-load path.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const PICKUP_FLARE: i32 = 70;
const FOUND_WEAPON: i32 = 82;
const WEAPONS: [&str; 12] = [
    "pistol", "shotgun", "assaultrifle", "rocket", "laser", "icegun",
    "bladegun", "flamethrower", "bow", "bombgun", "boomerang", "spikegun",
];

#[derive(Clone, Copy)]
struct PickupSpec {
    room: usize,
    object: i32,
    bought: &'static str,
    active: &'static str,
    beacon_dx: f64,
    beacon_dy: f64,
}

fn setup() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid"))
        .expect("parse game.droid");
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
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
    scene.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load town");
    scene.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("load level1");
    scene.view_positions.insert(0, (0.0, 0.0));
    let player = scene.instances.iter()
        .find(|(_, instance)| instance.object == PLAYER && instance.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, scene, player, asset)
}

fn live_ids(scene: &Scene, object: i32) -> Vec<i32> {
    scene.instances.iter()
        .filter(|(_, instance)| instance.object == object && instance.alive)
        .map(|(id, _)| *id)
        .collect()
}

fn active_weapons(scene: &Scene) -> Vec<String> {
    WEAPONS.iter()
        .filter(|weapon| scene.globals.get(**weapon).copied() == Some(1.0))
        .map(|weapon| (*weapon).to_string())
        .collect()
}

fn enter_pickup_room(
    bundle: &callys_core::code_vm::Bundle,
    scene: &mut Scene,
    asset: &GameDroidAsset,
    spec: &PickupSpec,
) -> i32 {
    scene.transition_to_room(bundle, spec.room, &asset.rooms[spec.room])
        .expect("enter pickup room");
    assert_eq!(
        asset.rooms[spec.room].objects.iter()
            .filter(|instance| instance.object_id == spec.object)
            .count(),
        1,
        "the real asset room has exactly one placed pickup"
    );
    let ids = live_ids(scene, spec.object);
    assert_eq!(ids.len(), 1, "Create leaves one live placed pickup");
    ids[0]
}

fn collect(
    bundle: &callys_core::code_vm::Bundle,
    scene: &mut Scene,
    player: i32,
    pickup: i32,
) {
    let (x, y) = (
        scene.instances[&pickup].fields["x"],
        scene.instances[&pickup].fields["y"],
    );
    scene.write(player, -1, "x", None, x).unwrap();
    scene.write(player, -1, "y", None, y).unwrap();
    for _ in 0..4 {
        scene.tick(bundle).unwrap();
        if !scene.instances[&pickup].alive {
            break;
        }
    }
    assert!(!scene.instances[&pickup].alive, "Step destroys the collected pickup");
}

fn assert_pickup(spec: PickupSpec) {
    let (bundle, mut scene, player, asset) = setup();
    let pickup = enter_pickup_room(&bundle, &mut scene, &asset, &spec);
    let (x, y) = (
        scene.instances[&pickup].fields["x"],
        scene.instances[&pickup].fields["y"],
    );

    let beacons = live_ids(&scene, PICKUP_FLARE);
    assert_eq!(beacons.len(), 1, "Create emits one pickup beacon");
    assert_eq!(scene.instances[&beacons[0]].fields["x"], x + spec.beacon_dx);
    assert_eq!(scene.instances[&beacons[0]].fields["y"], y + spec.beacon_dy);
    assert_eq!(active_weapons(&scene), vec!["pistol".to_string()]);

    collect(&bundle, &mut scene, player, pickup);
    assert_eq!(scene.globals[spec.bought], 1.0, "Step raises the bought flag");
    assert_eq!(active_weapons(&scene), vec![spec.active.to_string()]);
    let banner = *live_ids(&scene, FOUND_WEAPON).first().expect("found-weapon banner");
    assert_eq!(
        (scene.instances[&banner].fields["x"], scene.instances[&banner].fields["y"]),
        (x, y),
        "banner uses the pickup's own coordinates"
    );
}

fn assert_bought_room_load(spec: PickupSpec) {
    let (bundle, mut scene, _player, asset) = setup();
    scene.globals.insert(spec.bought.to_string(), 1.0);
    scene.transition_to_room(&bundle, spec.room, &asset.rooms[spec.room])
        .expect("enter owned pickup room");
    assert_eq!(
        asset.rooms[spec.room].objects.iter()
            .filter(|instance| instance.object_id == spec.object)
            .count(),
        1,
        "the real asset room has exactly one placed pickup"
    );
    assert!(live_ids(&scene, spec.object).is_empty(), "owned pickup is destroyed by Create");
    assert!(live_ids(&scene, PICKUP_FLARE).is_empty(), "owned pickup leaves no beacon");
    assert_eq!(active_weapons(&scene), vec!["pistol".to_string()]);
}

#[test]
fn bladegun_pickup_chain_and_owned_room_load() {
    let spec = PickupSpec { room: 23, object: 76, bought: "bladegunbought", active: "bladegun", beacon_dx: -12.0, beacon_dy: -16.0 };
    assert_pickup(spec);
    assert_bought_room_load(spec);
}

#[test]
fn flamethrower_pickup_chain_and_owned_room_load() {
    let spec = PickupSpec { room: 63, object: 77, bought: "flamethrowerbought", active: "flamethrower", beacon_dx: -4.0, beacon_dy: -12.0 };
    assert_pickup(spec);
    assert_bought_room_load(spec);
}

#[test]
fn bombgun_pickup_chain_and_owned_room_load() {
    let spec = PickupSpec { room: 84, object: 79, bought: "bombgunbought", active: "bombgun", beacon_dx: 12.0, beacon_dy: -16.0 };
    assert_pickup(spec);
    assert_bought_room_load(spec);
}

#[test]
fn boomerang_pickup_chain_and_owned_room_load() {
    let spec = PickupSpec { room: 30, object: 71, bought: "boomerangbought", active: "boomerang", beacon_dx: -8.0, beacon_dy: -16.0 };
    assert_pickup(spec);
    assert_bought_room_load(spec);
}
