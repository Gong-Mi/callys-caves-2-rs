//! Every ROOM placement field must reach the instance the loader creates.
//! The asset parser read scale and colour but not the rotation stored at record
//! offset +32, and nothing compared the parsed placement against the bytes, so
//! the three rotated placements in the original data (rm_level1 obj_wall,
//! rm_level15 obj_UI, rm_level39 obj_wall_2, all 90 degrees) were materialized
//! unrotated — which also changes their sprite box and therefore collision
//! geometry. The expected values here come from the raw ROOM records, not from
//! the parser under test.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::collections::BTreeMap;
use std::path::{Path, PathBuf};

fn u(b: &[u8], p: usize) -> u32 { u32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn i(b: &[u8], p: usize) -> i32 { i32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn f(b: &[u8], p: usize) -> f32 { f32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }

fn root() -> PathBuf { Path::new(env!("CARGO_MANIFEST_DIR")).join("../..") }

struct Placement { room: usize, instance: i32, object: i32, scale_x: f32, scale_y: f32, rotation: f32 }

/// Independent read of every ROOM instance record: x(+0) y(+4) object(+8)
/// instance id(+12) creation code(+16) scale_x(+20) scale_y(+24) colour(+28)
/// rotation(+32), stride 40.
fn raw_placements(bytes: &[u8]) -> Vec<Placement> {
    let mut p = 8;
    while &bytes[p..p + 4] != b"ROOM" { p += 8 + u(bytes, p + 4) as usize; }
    let lo = p + 8;
    let hi = lo + u(bytes, p + 4) as usize;
    let rooms = u(bytes, lo) as usize;
    let mut out = Vec::new();
    for room in 0..rooms {
        let start = u(bytes, lo + 4 + room * 4) as usize;
        let end = if room + 1 < rooms { u(bytes, lo + 4 + (room + 1) * 4) as usize } else { hi };
        let mut list = None;
        for cand in start..end.saturating_sub(8) {
            let n = u(bytes, cand) as usize;
            if n < 1 || n > 6000 || cand + 4 + 4 * n > end { continue; }
            let offsets: Vec<usize> = (0..n).map(|k| u(bytes, cand + 4 + 4 * k) as usize).collect();
            if !offsets.iter().all(|o| *o >= start && *o + 40 < end) { continue; }
            if !offsets.windows(2).all(|w| w[0] < w[1]) { continue; }
            if !offsets.iter().take(5).all(|o| (100_000..1_000_000).contains(&i(bytes, o + 12)) && (0..200).contains(&i(bytes, o + 8))) { continue; }
            list = Some(offsets);
            break;
        }
        for off in list.unwrap_or_default() {
            out.push(Placement { room, instance: i(bytes, off + 12), object: i(bytes, off + 8),
                scale_x: f(bytes, off + 20), scale_y: f(bytes, off + 24), rotation: f(bytes, off + 32) });
        }
    }
    out
}

fn loaded() -> (GameDroidAsset, std::sync::Arc<callys_core::code_vm::Bundle>) {
    let r = root();
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    let bundle = std::sync::Arc::new(load_bundle_from_file(&r.join("crates/core/src/generated/full_ir.json")).unwrap());
    (asset, bundle)
}

#[test]
fn the_original_rooms_carry_exactly_three_rotated_placements() {
    let bytes = std::fs::read(root().join("assets/game.droid")).unwrap();
    let placements = raw_placements(&bytes);
    assert!(placements.len() > 70_000, "the scan must see the whole room table, saw {}", placements.len());
    let rotated: Vec<_> = placements.iter().filter(|p| p.rotation != 0.0)
        .map(|p| (p.room, p.instance, p.object, p.rotation)).collect();
    assert_eq!(rotated, vec![(1, 100182, 4, 90.0), (15, 111728, 66, 90.0), (39, 130765, 5, 90.0)],
        "the original data rotates exactly three placements by 90 degrees");
}

#[test]
fn the_asset_parser_exposes_the_rotation_the_record_carries() {
    let (asset, _) = loaded();
    let bytes = std::fs::read(root().join("assets/game.droid")).unwrap();
    let mut checked = 0usize;
    for p in raw_placements(&bytes) {
        let room = &asset.rooms[p.room];
        let placed = room.objects.iter().find(|o| o.instance_id == p.instance).expect("placement");
        assert_eq!(placed.rotation, p.rotation, "room {} instance {} rotation", p.room, p.instance);
        assert_eq!(placed.scale_x, p.scale_x, "room {} instance {} scale_x", p.room, p.instance);
        assert_eq!(placed.scale_y, p.scale_y, "room {} instance {} scale_y", p.room, p.instance);
        checked += 1;
    }
    assert_eq!(checked, 71_014, "every placement in the room table was compared");
}

#[test]
fn every_placement_rotation_reaches_the_loaded_instance() {
    let (asset, bundle) = loaded();
    let bytes = std::fs::read(root().join("assets/game.droid")).unwrap();
    let rotated: BTreeMap<usize, Vec<&Placement>> = {
        let mut m: BTreeMap<usize, Vec<&Placement>> = BTreeMap::new();
        let owned = Box::leak(Box::new(raw_placements(&bytes)));
        for p in owned.iter().filter(|p| p.rotation != 0.0) { m.entry(p.room).or_default().push(p); }
        m
    };
    for (room_id, list) in &rotated {
        let mut scene = Scene::default();
        scene.init_bundle(&bundle);
        scene.init_fresh_start_globals();
        scene.load_room_from_data(&bundle, *room_id, &asset.rooms[*room_id]).expect("load room");
        for p in list {
            let inst = scene.instances.get(&p.instance).expect("rotated placement is materialized");
            let angle = inst.fields.get("image_angle").copied().unwrap_or(0.0);
            assert_eq!(angle, p.rotation as f64,
                "room {room_id} instance {} (object {}) must keep its placement rotation", p.instance, p.object);
        }
    }
}
