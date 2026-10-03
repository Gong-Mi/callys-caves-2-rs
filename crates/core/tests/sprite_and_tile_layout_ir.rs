//! Raw-record layout guards for the SPRT and ROOM-tile readers.
//!
//! Same class as the OBJT depth and ROOM rotation defects: a reader consumes a
//! record at wrong offsets and nothing can tell, because no test checks the
//! layout against the bytes. The SPRT check is falsifiable on its own: every
//! record must consume exactly its span (60-byte fixed part + TPAG pointers +
//! mask count + `ceil(w/8)*h` per mask + 4-byte pad).
//!
//! The tile check pins what the original data actually contains, because the
//! open issue #31 assumed the remake was dropping something. It is not: the game
//! has exactly one tiled room (rm_level1, 114 records), every one of those
//! records carries `bg_id = -1`, and no CODE in the whole game calls any
//! `tile_*` builtin — the tiles are ROOM-format data the bytecode never touches.
//! `draw_tile` skips `bg_id < 0`, so the correct visual result is "nothing".
use callys_asset::GameDroidAsset;
use std::path::{Path, PathBuf};

fn u32le(b: &[u8], p: usize) -> u32 { u32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn i32le(b: &[u8], p: usize) -> i32 { i32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn f32le(b: &[u8], p: usize) -> f32 { f32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }

fn root() -> PathBuf { Path::new(env!("CARGO_MANIFEST_DIR")).join("../..") }

fn spr_records(bytes: &[u8]) -> (Vec<usize>, usize) {
    let mut p = 8;
    while &bytes[p..p + 4] != b"SPRT" { p += 8 + u32le(bytes, p + 4) as usize; }
    let lo = p + 8;
    let end = lo + u32le(bytes, p + 4) as usize;
    let n = u32le(bytes, lo) as usize;
    ((0..n).map(|k| u32le(bytes, lo + 4 + 4 * k) as usize).collect(), end)
}

/// Independent read of every ROOM tile list: the room record holds a pointer to
/// a counted offset array whose records are 48 bytes and carry depth 1000000.
fn raw_tiles(bytes: &[u8]) -> Vec<(usize, Vec<usize>)> {
    let mut p = 8;
    while &bytes[p..p + 4] != b"ROOM" { p += 8 + u32le(bytes, p + 4) as usize; }
    let lo = p + 8;
    let hi = lo + u32le(bytes, p + 4) as usize;
    let rooms = u32le(bytes, lo) as usize;
    let mut out = Vec::new();
    for room in 0..rooms {
        let start = u32le(bytes, lo + 4 + room * 4) as usize;
        let end = if room + 1 < rooms { u32le(bytes, lo + 4 + (room + 1) * 4) as usize } else { hi };
        for cand in start..end.saturating_sub(8) {
            let n = u32le(bytes, cand) as usize;
            if n < 1 || n > 2000 || cand + 4 + 4 * n > end { continue; }
            let offsets: Vec<usize> = (0..n).map(|k| u32le(bytes, cand + 4 + 4 * k) as usize).collect();
            if !offsets.iter().all(|o| *o >= start && *o + 48 <= end) { continue; }
            if !offsets.windows(2).all(|w| w[0] < w[1]) { continue; }
            if !offsets.iter().take(4).all(|o| u32le(bytes, o + 28) == 1_000_000) { continue; }
            out.push((room, offsets));
            break;
        }
    }
    out
}

#[test]
fn every_sprite_record_consumes_its_span_and_matches_the_parsed_fields() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (offsets, end) = spr_records(&bytes);
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    assert_eq!(offsets.len(), asset.sprites.len(), "sprite count");
    for (idx, &off) in offsets.iter().enumerate() {
        let w = u32le(&bytes, off + 4) as usize;
        let h = u32le(&bytes, off + 8) as usize;
        let tcount = u32le(&bytes, off + 56) as usize;
        let row_bytes = ((w + 7) / 8).max(1);
        let mask_count = u32le(&bytes, off + 60 + 4 * tcount) as usize;
        let consumed = 60 + 4 * tcount + 4 + mask_count * row_bytes * h.max(1);
        let skip_to = offsets.get(idx + 1).copied().unwrap_or(end);
        assert!(off + consumed <= skip_to,
            "sprite {idx} layout overruns its record: consumed {consumed} of {}", skip_to - off);
        assert!(skip_to - off - consumed <= 3,
            "sprite {idx} leaves {} bytes unaccounted (mask pad must be 0..3)", skip_to - off - consumed);

        let s = asset.sprites.get(&idx).unwrap_or_else(|| panic!("sprite {idx} missing from the parser"));
        assert_eq!(s.width as usize, w, "sprite {idx} width");
        assert_eq!(s.height as usize, h, "sprite {idx} height");
        assert_eq!(s.origin_x, i32le(&bytes, off + 48), "sprite {idx} origin_x");
        assert_eq!(s.origin_y, i32le(&bytes, off + 52), "sprite {idx} origin_y");
        assert_eq!(s.bbox, Some([
            i32le(&bytes, off + 12), i32le(&bytes, off + 16),
            i32le(&bytes, off + 24), i32le(&bytes, off + 20),
        ]), "sprite {idx} manual bbox [left, right, top, bottom]");
        assert_eq!(s.tpag_indices.len(), tcount, "sprite {idx} TPAG pointer count");
    }
    assert_eq!(offsets.len(), 178, "every sprite record was checked");
}

#[test]
fn the_only_tiled_room_carries_background_less_tiles_the_parser_reads_correctly() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    let lists = raw_tiles(&bytes);
    assert_eq!(lists.iter().map(|(room, l)| (*room, l.len())).collect::<Vec<_>>(), vec![(1, 114)],
        "the original data tiles exactly one room: rm_level1 with 114 records");
    for (room_id, offsets) in &lists {
        let room = &asset.rooms[*room_id];
        assert_eq!(room.tiles.len(), offsets.len(), "room {room_id} {} tile count", room.name);
        for (offset, tile) in offsets.iter().zip(room.tiles.iter()) {
            let offset = *offset;
            assert_eq!(tile.x, i32le(&bytes, offset), "tile x");
            assert_eq!(tile.y, i32le(&bytes, offset + 4), "tile y");
            assert_eq!(tile.bg_id, i32le(&bytes, offset + 8), "tile bg_id");
            assert_eq!(tile.src_x, i32le(&bytes, offset + 12), "tile src_x");
            assert_eq!(tile.src_y, i32le(&bytes, offset + 16), "tile src_y");
            assert_eq!(tile.width, i32le(&bytes, offset + 20), "tile width");
            assert_eq!(tile.height, i32le(&bytes, offset + 24), "tile height");
            assert_eq!(tile.depth, i32le(&bytes, offset + 28), "tile depth");
            assert_eq!(tile.id, i32le(&bytes, offset + 32), "tile id");
            assert_eq!(tile.scale_x, f32le(&bytes, offset + 36), "tile scale_x");
            assert_eq!(tile.scale_y, f32le(&bytes, offset + 40), "tile scale_y");
            assert_eq!(tile.bg_id, -1, "every record in the only tiled room has no background");
            assert_eq!((tile.width, tile.height), (32, 32), "tile source is one 32x32 cell");
            assert_eq!(tile.depth, 1_000_000, "GM default tile depth");
        }
    }
}
