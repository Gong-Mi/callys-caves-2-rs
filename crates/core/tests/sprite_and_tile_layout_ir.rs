//! Raw-record layout guards for the asset readers.
//!
//! Same class as the OBJT depth and ROOM rotation defects: a reader consumes a
//! record at wrong offsets and nothing can tell, because no test checks the
//! layout against the bytes. Each check below compares the parser against the
//! bytes field by field *and* asserts an invariant the record must satisfy, so a
//! shifted read cannot pass silently:
//!
//! * SPRT — every record consumes exactly its span (60-byte fixed part + TPAG
//!   pointers + mask count + `ceil(w/8)*h` per mask + 4-byte pad);
//! * ROOM tiles — the only tiled room's records carry `bg_id = -1` and every
//!   parsed field must equal the bytes;
//! * ROOM views — 8 slots per room, `visible` is a flag, live views carry
//!   positive source/viewport rects, a bounded border band and a follow target
//!   that is either -1 or a real object id;
//! * ROOM header — the colour/clear words, the room creation code and the flag
//!   word match the bytes, only GameMaker's documented flag bits are set, and a
//!   creation code resolves or is -1;
//! * ROOM backgrounds — 8 slots per room (40-byte records), flags are booleans,
//!   a slot names a real BGND entry or none, and no slot in this asset both
//!   shows and names a background;
//! * BGND — flags are booleans and every background resolves a TPAG page rect;
//! * FONT — every glyph box lies inside its font's page rect;
//! * the OBJT action tail — every 56-byte action record matches the parser, and
//!   the words whose meaning this format does not document (`kind`,
//!   `execution_type`, `who`, `relative`, `is_not`, `unknown`) are pinned to the
//!   single value the whole asset carries;
//! * the CODE entry and VARI header words the readers deliberately drop — the
//!   survey counts that make dropping them safe are asserted, so a future file
//!   that varies them fails here instead of silently losing a field.
//!
//! The tile check also pins what the original data contains, because the open
//! issue #31 assumed the remake was dropping something. It is not: the game has
//! exactly one tiled room (rm_level1, 114 records), every record carries
//! `bg_id = -1`, and no CODE calls any `tile_*` builtin — the tiles are
//! ROOM-format data the bytecode never touches. `draw_tile` skips `bg_id < 0`,
//! so the correct visual result is "nothing". The same holds for the room
//! BACKGROUND table: all 912 slots are disabled or nameless, so no room draws a
//! background layer and adding one would be inventing a layer the data lacks.
use callys_asset::GameDroidAsset;
use std::collections::BTreeMap;
use std::path::{Path, PathBuf};

fn u16le(b: &[u8], p: usize) -> u16 { u16::from_le_bytes(b[p..p + 2].try_into().unwrap()) }
fn u32le(b: &[u8], p: usize) -> u32 { u32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn i32le(b: &[u8], p: usize) -> i32 { i32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }
fn f32le(b: &[u8], p: usize) -> f32 { f32::from_le_bytes(b[p..p + 4].try_into().unwrap()) }

fn root() -> PathBuf { Path::new(env!("CARGO_MANIFEST_DIR")).join("../..") }

/// A chunk's body start, the absolute offsets of its counted record table, and
/// the chunk body end.
fn counted_table(bytes: &[u8], tag: &[u8; 4]) -> (usize, Vec<usize>, usize) {
    let mut p = 8;
    while &bytes[p..p + 4] != tag { p += 8 + u32le(bytes, p + 4) as usize; }
    let lo = p + 8;
    let end = lo + u32le(bytes, p + 4) as usize;
    let n = u32le(bytes, lo) as usize;
    (lo, (0..n).map(|k| u32le(bytes, lo + 4 + 4 * k) as usize).collect(), end)
}

/// Independent read of every ROOM tile list: the room record holds a pointer to
/// a counted offset array whose records are 48 bytes and carry depth 1000000.
fn raw_tiles(bytes: &[u8]) -> Vec<(usize, Vec<usize>)> {
    let (_, room_offsets, end) = counted_table(bytes, b"ROOM");
    let mut out = Vec::new();
    for (room, &start) in room_offsets.iter().enumerate() {
        let stop = room_offsets.get(room + 1).copied().unwrap_or(end);
        for cand in start..stop.saturating_sub(8) {
            let n = u32le(bytes, cand) as usize;
            if n < 1 || n > 2000 || cand + 4 + 4 * n > stop { continue; }
            let offsets: Vec<usize> = (0..n).map(|k| u32le(bytes, cand + 4 + 4 * k) as usize).collect();
            if !offsets.iter().all(|o| *o >= start && *o + 48 <= stop) { continue; }
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
    let (_, offsets, end) = counted_table(&bytes, b"SPRT");
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

/// The room VIEW table seeds the camera the renderer follows, so a shifted read
/// here is a camera bug. Records are 14 u32s: visible, xview, yview, wview,
/// hview, xport, yport, wport, hport, hborder, vborder, hspeed, vspeed, object.
#[test]
fn every_room_view_record_matches_the_parser_and_forms_a_valid_view_table() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (_, room_offsets, _) = counted_table(&bytes, b"ROOM");
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    let object_count = asset.objects.len() as i32;
    let mut total = 0usize;
    for (room_id, &room_off) in room_offsets.iter().enumerate() {
        let views_offset = u32le(&bytes, room_off + 44) as usize;
        assert_ne!(views_offset, 0, "room {room_id} has no view table pointer");
        assert_eq!(u32le(&bytes, views_offset), 8, "room {room_id} must carry the eight GM8 view slots");
        let views = &asset.rooms[room_id].views;
        assert_eq!(views.len(), 8, "room {room_id} parser view count");
        for slot in 0..8 {
            let vo = u32le(&bytes, views_offset + 4 + 4 * slot) as usize;
            let v = &views[slot];
            let visible = u32le(&bytes, vo);
            assert!(visible <= 1, "room {room_id} view {slot}: visible raw {visible} is not a flag");
            assert_eq!(v.visible, visible != 0, "room {room_id} view {slot} visible");
            assert_eq!(v.xview, i32le(&bytes, vo + 4), "room {room_id} view {slot} xview");
            assert_eq!(v.yview, i32le(&bytes, vo + 8), "room {room_id} view {slot} yview");
            assert_eq!(v.wview, u32le(&bytes, vo + 12), "room {room_id} view {slot} wview");
            assert_eq!(v.hview, u32le(&bytes, vo + 16), "room {room_id} view {slot} hview");
            assert_eq!(v.xport, i32le(&bytes, vo + 20), "room {room_id} view {slot} xport");
            assert_eq!(v.yport, i32le(&bytes, vo + 24), "room {room_id} view {slot} yport");
            assert_eq!(v.wport, u32le(&bytes, vo + 28), "room {room_id} view {slot} wport");
            assert_eq!(v.hport, u32le(&bytes, vo + 32), "room {room_id} view {slot} hport");
            assert_eq!(v.hborder, u32le(&bytes, vo + 36), "room {room_id} view {slot} hborder");
            assert_eq!(v.vborder, u32le(&bytes, vo + 40), "room {room_id} view {slot} vborder");
            assert_eq!(v.hspeed, i32le(&bytes, vo + 44), "room {room_id} view {slot} hspeed");
            assert_eq!(v.vspeed, i32le(&bytes, vo + 48), "room {room_id} view {slot} vspeed");
            assert_eq!(v.object, i32le(&bytes, vo + 52), "room {room_id} view {slot} object");
            if v.visible {
                assert!(v.wview > 0 && v.hview > 0 && v.wport > 0 && v.hport > 0,
                    "room {room_id} view {slot}: a live view needs non-empty source and viewport rects");
                assert!(v.hborder <= 4096 && v.vborder <= 4096,
                    "room {room_id} view {slot}: border band {}x{} is out of range", v.hborder, v.vborder);
                assert!(v.object == -1 || (0..object_count).contains(&v.object),
                    "room {room_id} view {slot}: follow target {} is neither -1 nor a real object", v.object);
            }
            total += 1;
        }
    }
    assert_eq!(total, 912, "eight slots for each of the 114 rooms");
}

#[test]
fn every_background_record_matches_the_parser_and_resolves_a_texture_page() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (_, offsets, _) = counted_table(&bytes, b"BGND");
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    assert_eq!(offsets.len(), asset.backgrounds.len(), "background count");
    for (idx, &off) in offsets.iter().enumerate() {
        let bg = asset.backgrounds.get(&idx).expect("background");
        for (name, at, parsed) in [
            ("transparent", 4, bg.transparent),
            ("smooth", 8, bg.smooth),
            ("preload", 12, bg.preload),
        ] {
            let raw = u32le(&bytes, off + at);
            assert!(raw <= 1, "background {idx} {name} raw {raw} is not a flag");
            assert_eq!(parsed, raw != 0, "background {idx} {name}");
        }
        assert_eq!(bg.tpag_ptr, u32le(&bytes, off + 16) as usize, "background {idx} TPAG pointer");
        let page = asset.tpag_items.get(&bg.tpag_ptr)
            .unwrap_or_else(|| panic!("background {idx} {} resolves no TPAG page rect", bg.name));
        assert!(page.w > 0 && page.h > 0, "background {idx} {} has an empty page rect", bg.name);
    }
}

/// Glyph records are eight u16s: ch, x, y, w, h, shift, offset, unused. Their box
/// must sit inside the font's own page rect, which a shifted read cannot satisfy.
#[test]
fn every_font_glyph_box_matches_the_bytes_and_lies_inside_its_page() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (lo, font_offsets, _) = counted_table(&bytes, b"FONT");
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    assert_eq!(asset.fonts.len(), u32le(&bytes, lo) as usize, "font count");
    let mut glyphs = 0usize;
    for (idx, &base) in font_offsets.iter().enumerate() {
        let font = asset.fonts.get(idx).expect("font");
        assert_eq!(font.page_tpag_ptr, u32le(&bytes, base + 28) as usize, "font {idx} page pointer");
        assert_eq!(font.glyph_count, u32le(&bytes, base + 40), "font {idx} glyph count");
        let page = asset.tpag_items.get(&font.page_tpag_ptr)
            .unwrap_or_else(|| panic!("font {idx} {} resolves no page rect", font.name));
        for g in 0..font.glyph_count as usize {
            let gp = u32le(&bytes, base + 44 + 4 * g) as usize;
            let parsed = &font.glyphs[g];
            assert_eq!(parsed.ch, u16le(&bytes, gp), "font {idx} glyph {g} char");
            assert_eq!(parsed.x, u16le(&bytes, gp + 2), "font {idx} glyph {g} x");
            assert_eq!(parsed.y, u16le(&bytes, gp + 4), "font {idx} glyph {g} y");
            assert_eq!(parsed.w, u16le(&bytes, gp + 6), "font {idx} glyph {g} w");
            assert_eq!(parsed.h, u16le(&bytes, gp + 8), "font {idx} glyph {g} h");
            assert_eq!(parsed.shift, u16le(&bytes, gp + 10), "font {idx} glyph {g} shift");
            assert_eq!(parsed.offset, u16le(&bytes, gp + 12), "font {idx} glyph {g} offset");
            assert!(parsed.x as u32 + parsed.w as u32 <= page.w as u32
                 && parsed.y as u32 + parsed.h as u32 <= page.h as u32,
                "font {idx} {} glyph {g} box {}+{}x{}+{} escapes its page rect {}x{}",
                font.name, parsed.x, parsed.w, parsed.y, parsed.h, page.w, page.h);
            glyphs += 1;
        }
    }
    assert!(glyphs > 500, "the fonts carry {glyphs} glyphs; the scan must see them all");
    println!("font glyphs checked: {glyphs}");
}

/// GameMaker's room flag bits, from UndertaleModTool's `RoomEntryFlags`.
const ENABLE_VIEWS: u32 = 1;
const CLEAR_VIEW_BACKGROUND: u32 = 2;
const DO_NOT_CLEAR_DISPLAY_BUFFER: u32 = 4;

/// The room header words the loader used to drop: the background colour and
/// its clear flag, the room creation code and the flag word. They are parsed
/// now, so a shifted read is room state, not a private implementation detail —
/// the flag bits are pinned to GameMaker's documented set and the creation
/// code must resolve to a real CODE entry or be absent.
#[test]
fn every_room_header_word_matches_the_parser_and_carries_only_known_flag_bits() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (_, room_offsets, _) = counted_table(&bytes, b"ROOM");
    let (code_lo, code_offsets, _) = counted_table(&bytes, b"CODE");
    let code_count = u32le(&bytes, code_lo) as i32;
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    assert_eq!(room_offsets.len(), 114, "the room table");
    assert_eq!(code_offsets.len(), code_count as usize, "the CODE roster");
    let mut clears_to_own_colour = 0;
    let mut black_colour = 0;
    for (id, &off) in room_offsets.iter().enumerate() {
        let room = &asset.rooms[id];
        assert_eq!(room.background_colour, u32le(&bytes, off + 24),
            "room {id} {} background colour", room.name);
        let raw_clear = u32le(&bytes, off + 28);
        assert!(raw_clear <= 1, "room {id} clear word {raw_clear} is not a flag");
        assert_eq!(room.draw_background_colour, raw_clear != 0, "room {id} clear flag");
        assert_eq!(room.creation_code_id, i32le(&bytes, off + 32), "room {id} creation code");
        assert!(room.creation_code_id == -1 || (0..code_count).contains(&room.creation_code_id),
            "room {id} creation code {} resolves no CODE entry", room.creation_code_id);
        assert_eq!(room.flags, u32le(&bytes, off + 36), "room {id} flags");
        assert_eq!(room.flags & !(ENABLE_VIEWS | CLEAR_VIEW_BACKGROUND | DO_NOT_CLEAR_DISPLAY_BUFFER), 0,
            "room {id} sets a room flag bit GameMaker does not define: {:#x}", room.flags);
        assert_eq!(room.flags & ENABLE_VIEWS, ENABLE_VIEWS,
            "room {id} carries a view table, so EnableViews must be set");
        assert_eq!(room.backgrounds.len(), 8, "room {id} background slot count");
        if room.draw_background_colour { clears_to_own_colour += 1; }
        if room.background_colour == 0 { black_colour += 1; }
    }
    assert_eq!(clears_to_own_colour, 1, "exactly one room clears to its own colour");
    assert_eq!(black_colour, 110, "the four 0x00C0C0C0 rooms never clear to it");
    assert!(asset.rooms.iter().all(|room| room.flags == 5),
        "every room in this asset carries EnableViews | DoNotClearDisplayBuffer");
    assert!(asset.rooms.iter().all(|room| room.creation_code_id == -1),
        "no room in this asset runs a creation code");
}

/// The room BACKGROUND table: 8 slots per room, 40-byte records. Every field
/// must equal the bytes, a slot must name a real BGND entry or none, and the
/// renderer-relevant conclusion is asserted rather than assumed — in this asset
/// no slot both shows and names a background, so no room draws one.
#[test]
fn every_room_background_slot_matches_the_parser_and_no_room_draws_a_layer() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (_, room_offsets, _) = counted_table(&bytes, b"ROOM");
    let (_, bgnd_offsets, _) = counted_table(&bytes, b"BGND");
    let bgnd_count = bgnd_offsets.len() as i32;
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    let (mut slots, mut visible, mut foreground, mut named, mut drawable) = (0usize, 0usize, 0usize, 0usize, 0usize);
    let (mut tiled_x, mut tiled_y, mut stretch, mut offset_slots) = (0usize, 0usize, 0usize, 0usize);
    for (id, &off) in room_offsets.iter().enumerate() {
        let list = u32le(&bytes, off + 40) as usize;
        assert_eq!(u32le(&bytes, list), 8, "room {id} must carry the eight GM background slots");
        let room = &asset.rooms[id];
        assert_eq!(room.backgrounds.len(), 8, "room {id} parser slot count");
        for (slot, parsed) in room.backgrounds.iter().enumerate() {
            let so = u32le(&bytes, list + 4 + 4 * slot) as usize;
            if slot > 0 {
                let prev = u32le(&bytes, list + 4 * slot) as usize;
                assert_eq!(so - prev, 40, "room {id} slot {slot} background record stride");
            }
            for (field, at) in [("visible", 0usize), ("foreground", 4), ("tiled_x", 20), ("tiled_y", 24), ("stretch", 36)] {
                let raw = u32le(&bytes, so + at);
                assert!(raw <= 1, "room {id} slot {slot} {field} raw {raw} is not a flag");
            }
            assert_eq!(parsed.visible, u32le(&bytes, so) != 0, "room {id} slot {slot} visible");
            assert_eq!(parsed.foreground, u32le(&bytes, so + 4) != 0, "room {id} slot {slot} foreground");
            assert_eq!(parsed.background_id, i32le(&bytes, so + 8), "room {id} slot {slot} background id");
            assert!(parsed.background_id == -1 || (0..bgnd_count).contains(&parsed.background_id),
                "room {id} slot {slot} names background {} but BGND holds {bgnd_count} entries",
                parsed.background_id);
            assert_eq!(parsed.x, i32le(&bytes, so + 12), "room {id} slot {slot} x");
            assert_eq!(parsed.y, i32le(&bytes, so + 16), "room {id} slot {slot} y");
            assert_eq!(parsed.tiled_horizontally, u32le(&bytes, so + 20) != 0, "room {id} slot {slot} tiling x");
            assert_eq!(parsed.tiled_vertically, u32le(&bytes, so + 24) != 0, "room {id} slot {slot} tiling y");
            assert_eq!(parsed.speed_x, i32le(&bytes, so + 28), "room {id} slot {slot} speed x");
            assert_eq!(parsed.speed_y, i32le(&bytes, so + 32), "room {id} slot {slot} speed y");
            assert_eq!(parsed.stretch, u32le(&bytes, so + 36) != 0, "room {id} slot {slot} stretch");
            assert_eq!((parsed.speed_x, parsed.speed_y), (0, 0),
                "room {id} slot {slot} scrolls; nothing in this tree implements a scrolling background");
            slots += 1;
            if parsed.visible { visible += 1; }
            if parsed.foreground { foreground += 1; }
            if parsed.background_id >= 0 { named += 1; }
            if parsed.tiled_horizontally { tiled_x += 1; }
            if parsed.tiled_vertically { tiled_y += 1; }
            if parsed.stretch { stretch += 1; }
            if parsed.x != 0 || parsed.y != 0 { offset_slots += 1; }
            if parsed.visible && parsed.background_id >= 0 { drawable += 1; }
        }
    }
    assert_eq!(slots, 912, "eight slots for each of the 114 rooms");
    assert_eq!(visible, 106, "the slots the room editor left ticked");
    assert_eq!(foreground, 0, "no room in this asset draws a foreground background");
    assert_eq!(named, 2, "only rm_town (background 5) and rm_level1 (background 0) name one, both unticked");
    assert_eq!((tiled_x, tiled_y), (802, 802), "the tiling flags travel together in this asset");
    assert_eq!(stretch, 103, "the stretch flag is set on a minority of slots");
    assert_eq!(offset_slots, 0, "every slot sits at 0,0");
    assert_eq!(drawable, 0,
        "no slot both shows and names a background, so no room draws a background layer; \
         a renderer that invents one is adding a layer the original data does not have");
}

/// Actions are reached through three tables (object → event list → action
/// pointer table). This walk is independent of the parser and must find exactly
/// the actions the parser reports before any of their words is trusted.
fn raw_actions_per_object(bytes: &[u8]) -> Vec<Vec<usize>> {
    let (_, records, _) = counted_table(bytes, b"OBJT");
    records.iter().map(|&r| {
        let vertex_count = u32le(bytes, r + 64) as usize;
        let event_types_at = r + 68 + 8 * vertex_count + 12;
        let mut actions = Vec::new();
        for et in 0..u32le(bytes, event_types_at) as usize {
            let list = u32le(bytes, event_types_at + 4 + 4 * et) as usize;
            for e in 0..u32le(bytes, list) as usize {
                let event = u32le(bytes, list + 4 + 4 * e) as usize;
                for a in 0..u32le(bytes, event + 4) as usize {
                    actions.push(u32le(bytes, event + 8 + 4 * a) as usize);
                }
            }
        }
        actions
    }).collect()
}

/// The OBJT action record (56 bytes) and the tail words the asset format does
/// not document. Every field is compared against the bytes, and the words whose
/// meaning stays unknown are pinned to the single value the whole asset carries
/// (`kind` 7, `execution_type` 2, `who` -1, `relative` 0, `is_not` 0,
/// `unknown` 0) so a future file that varies them cannot slip through unnamed.
#[test]
fn every_objt_action_record_matches_the_parser_and_its_undocumented_words_are_uniform() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let asset = GameDroidAsset::parse(r.join("assets/game.droid")).unwrap();
    let raw = raw_actions_per_object(&bytes);
    assert_eq!(raw.len(), asset.objects.len(), "every object record was walked");
    let mut total = 0usize;
    for (id, actions) in raw.iter().enumerate() {
        let object = &asset.objects[id];
        let parsed: Vec<&callys_asset::ObjectAction> =
            object.events.iter().flat_map(|e| e.actions.iter()).collect();
        assert_eq!(actions.len(), parsed.len(),
            "object {id} {}: the independent walk and the parser disagree on action count", object.name);
        for (ap, action) in actions.iter().zip(parsed.iter()) {
            let ap = *ap;
            assert_eq!(action.library_id, u32le(&bytes, ap), "object {id} action library");
            assert_eq!(action.action_id, u32le(&bytes, ap + 4), "object {id} action id");
            assert_eq!(action.kind, u32le(&bytes, ap + 8), "object {id} action kind");
            assert_eq!(action.use_relative_raw, u32le(&bytes, ap + 12), "object {id} use_relative");
            assert_eq!(action.is_question_raw, u32le(&bytes, ap + 16), "object {id} is_question");
            assert_eq!(action.use_apply_to_raw, u32le(&bytes, ap + 20), "object {id} use_apply_to");
            assert_eq!(action.execution_type, u32le(&bytes, ap + 24), "object {id} execution type");
            assert_eq!(action.code_id, i32le(&bytes, ap + 32), "object {id} code id");
            assert_eq!(action.argument_count, u32le(&bytes, ap + 36), "object {id} argument count");
            assert_eq!(action.who, i32le(&bytes, ap + 40), "object {id} who");
            assert_eq!(action.relative_raw, u32le(&bytes, ap + 44), "object {id} relative");
            assert_eq!(action.is_not_raw, u32le(&bytes, ap + 48), "object {id} is_not");
            assert_eq!(action.unknown_raw, u32le(&bytes, ap + 52), "object {id} unknown word");
            // Words this format does not document: they are uniform here, and
            // that count is the only reason they can be carried as raw names.
            assert_eq!(action.kind, 7, "object {id} action kind");
            assert_eq!(action.execution_type, 2, "object {id} execution type");
            assert_eq!(action.who, -1, "object {id} action target");
            assert_eq!(action.relative_raw, 0, "object {id} relative word");
            assert_eq!(action.is_not_raw, 0, "object {id} negate word");
            assert_eq!(action.unknown_raw, 0, "object {id} trailing word");
            assert_eq!((action.use_relative_raw, action.is_question_raw), (0, 0),
                "object {id} relative/question words");
            assert_eq!((action.use_apply_to_raw, action.argument_count), (1, 1),
                "object {id} apply-to and argument words");
            total += 1;
        }
    }
    assert_eq!(total, 803, "the asset carries {total} actions, not a subset");
}

/// The words the readers deliberately drop, and the survey that makes dropping
/// them safe. `CODE` entry word +16 is zero in every record; `locals_count` is
/// data the reader discards, so its distribution is asserted whether or not the
/// reader keeps it; the `VARI` header's second and third words are the counts
/// the loader reads only to skip past.
#[test]
fn the_words_the_readers_drop_are_uniform_in_this_asset() {
    let r = root();
    let bytes = std::fs::read(r.join("assets/game.droid")).unwrap();
    let (_, code_offsets, code_end) = counted_table(&bytes, b"CODE");
    assert_eq!(code_offsets.len(), 1354);
    let mut locals = BTreeMap::new();
    for &off in &code_offsets {
        let bytecode_len = u32le(&bytes, off + 4) as usize;
        let relative = i32le(&bytes, off + 12) as i64;
        let bytecode_pos = (off as i64 + 12).checked_add(relative).expect("bytecode offset overflow");
        assert!(bytecode_pos >= 0 && bytecode_pos as usize + bytecode_len <= code_end,
            "CODE at {off}: bytecode escapes the CODE chunk");
        assert_eq!(u32le(&bytes, off + 16), 0,
            "CODE at {off} carries a non-zero trailing word the reader drops");
        *locals.entry(u32le(&bytes, off + 8)).or_insert(0usize) += 1;
    }
    assert_eq!(locals, BTreeMap::from([(1u32, 1349usize), (2, 2), (3, 1), (5, 1), (7, 1)]),
        "CODE locals_count distribution");
    let (vari_lo, _, vari_end) = counted_table(&bytes, b"VARI");
    let vari_count = u32le(&bytes, vari_lo) as usize;
    assert_eq!(vari_count, 691, "VARI record count");
    assert_eq!(u32le(&bytes, vari_lo + 4), 691, "VARI max_variable_count (dropped by the reader)");
    assert_eq!(u32le(&bytes, vari_lo + 8), 7, "VARI locals_count (dropped by the reader)");
    assert!(vari_lo + 12 + vari_count * 20 <= vari_end,
        "VARI's 20-byte records must tile inside the chunk");
}
