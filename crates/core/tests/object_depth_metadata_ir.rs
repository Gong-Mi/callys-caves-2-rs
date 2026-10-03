//! Differential guard across the two independent readers of the same chunks.
//!
//! `scripts/compile_event_ir.py` (generator) and `crates/asset` (the parser the
//! runtime actually loads) read OBJT and ROOM on their own. When they disagreed
//! on `depth` — the generator read +20, the persistent flag — 91 of 191 objects
//! shipped a boolean as their layer and every green suite stayed green, because
//! nothing compared the readers. These tests compare the generated IR, the asset
//! parser and the raw bytes field by field, so the next silent misread fails a
//! test on the same commit that introduces it.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use std::collections::BTreeMap;
use std::path::{Path, PathBuf};

fn u(b: &[u8], p: usize) -> u32 { u32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn i(b: &[u8], p: usize) -> i32 { i32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }

fn project_root() -> PathBuf { Path::new(env!("CARGO_MANIFEST_DIR")).join("../..") }

/// GBND-style chunk walk; returns (count_field_position, absolute record offsets).
fn chunk_records(bytes: &[u8], tag: &[u8; 4]) -> (usize, Vec<usize>) {
    let mut p = 8;
    while &bytes[p..p + 4] != tag { p += 8 + u(bytes, p + 4) as usize; }
    let count_at = p + 8;
    let count = u(bytes, count_at) as usize;
    let offsets = (0..count).map(|k| u(bytes, count_at + 4 + k * 4) as usize).collect();
    (count_at, offsets)
}

#[test]
fn every_generated_object_depth_matches_original_objt_not_persistent() {
    let root = project_root();
    let bytes = std::fs::read(root.join("assets/game.droid")).unwrap();
    let (count_at, records) = chunk_records(&bytes, b"OBJT");
    let b = load_bundle_from_file(&root.join("crates/core/src/generated/full_ir.json")).unwrap();
    assert_eq!(b.objects.len(), u(&bytes, count_at) as usize);
    for o in &b.objects {
        let r = records[o.id as usize];
        let raw_depth = i(&bytes, r + 16);
        let persistent = u(&bytes, r + 20) != 0;
        assert_eq!(o.depth, raw_depth, "OBJT {} {} depth must use +16, not persistent={persistent}", o.id, o.name);
        assert_eq!(o.persistent, persistent, "OBJT {} persistent source is unchanged", o.id);
    }
}

#[test]
fn the_generator_and_the_asset_parser_agree_on_every_object_field() {
    let root = project_root();
    let asset = GameDroidAsset::parse(root.join("assets/game.droid")).unwrap();
    let b = load_bundle_from_file(&root.join("crates/core/src/generated/full_ir.json")).unwrap();
    assert_eq!(b.objects.len(), asset.objects.len(), "object rosters must match");
    for o in &b.objects {
        let a = asset.objects.iter().find(|a| a.id == o.id as usize).expect("asset object");
        assert_eq!(o.name, a.name, "object {} name", o.id);
        assert_eq!(o.sprite, a.sprite_id, "object {} sprite", o.id);
        assert_eq!(o.depth, a.depth, "object {} depth", o.id);
        assert_eq!(o.persistent, a.persistent, "object {} persistent", o.id);
        assert_eq!(o.parent, a.parent_id, "object {} parent", o.id);
    }
}

#[test]
fn the_asset_parser_reads_every_object_field_at_the_objt_offset_the_bytes_carry() {
    let root = project_root();
    let bytes = std::fs::read(root.join("assets/game.droid")).unwrap();
    let (_, records) = chunk_records(&bytes, b"OBJT");
    let asset = GameDroidAsset::parse(root.join("assets/game.droid")).unwrap();
    for a in &asset.objects {
        let r = records[a.id];
        assert_eq!(a.sprite_id, i(&bytes, r + 4), "asset object {} sprite", a.id);
        assert_eq!(a.visible, u(&bytes, r + 8) != 0, "asset object {} visible", a.id);
        assert_eq!(a.solid, u(&bytes, r + 12) != 0, "asset object {} solid", a.id);
        assert_eq!(a.depth, i(&bytes, r + 16), "asset object {} depth", a.id);
        assert_eq!(a.persistent, u(&bytes, r + 20) != 0, "asset object {} persistent", a.id);
        assert_eq!(a.parent_id, i(&bytes, r + 24), "asset object {} parent", a.id);
    }
}

#[test]
fn every_room_creation_binding_matches_its_asset_placement_and_none_is_dropped() {
    let root = project_root();
    let asset = GameDroidAsset::parse(root.join("assets/game.droid")).unwrap();
    let b = load_bundle_from_file(&root.join("crates/core/src/generated/full_ir.json")).unwrap();
    let mut bindings: BTreeMap<usize, Vec<&callys_core::code_vm::RoomBinding>> = BTreeMap::new();
    for binding in &b.room_bindings { bindings.entry(binding.room_id).or_default().push(binding); }
    let mut expected_total = 0usize;
    for (room_id, list) in &bindings {
        let room = asset.rooms.get(*room_id).unwrap_or_else(|| panic!("binding room {room_id} is outside the room table"));
        let placements: Vec<_> = room.objects.iter().filter(|o| o.creation_code_id >= 0).collect();
        expected_total += placements.len();
        assert_eq!(list.len(), placements.len(),
            "room {room_id} {}: every placement with a creation code must be bound exactly once", room.name);
        for binding in list {
            let placement = placements.iter()
                .find(|o| o.instance_id == binding.instance_id)
                .unwrap_or_else(|| panic!("room {room_id} binding instance {} has no asset placement", binding.instance_id));
            assert_eq!(binding.object_id, placement.object_id, "room {room_id} instance {} object", binding.instance_id);
            assert_eq!(binding.code_id as i32, placement.creation_code_id, "room {room_id} instance {} code", binding.instance_id);
            assert_eq!(binding.room_name, room.name, "room {room_id} name");
        }
    }
    assert_eq!(b.room_bindings.len(), expected_total,
        "the export must carry every room creation code, not a subset");
}
