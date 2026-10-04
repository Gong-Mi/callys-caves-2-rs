# Asset record layouts — `game.droid` (GMS1.4 / bytecode 16, 28 MB)

Definitions, not narration: the field order and width of every record family the
runtime reads out of the original data file, plus the words the readers
deliberately drop and the survey counts that make dropping them safe.

Standing proof for all of it is `crates/core/tests/sprite_and_tile_layout_ir.rs`
(field-by-field against the bytes **and** an invariant a shifted read cannot
satisfy) and `crates/core/tests/object_depth_metadata_ir.rs` (the
generator/parser/bytes differential). A layout that passes bounds checks but
fails containment, resolution or a fixed-shape invariant is wrong; the tests
exist so the next silent misread fails on the commit that introduces it.

Chunk walk: `FORM` + u32 total; tags at offset 8; body = tag + 8; advance
`8 + ((size + 3) & !3)`. Present chunks: GEN8 OPTN LANG EXTN SOND AGRP SPRT
BGND PATH SCPT GLOB SHDR FONT TMLN OBJT ROOM DAFL TPAG CODE VARI FUNC STRG TXTR
AUDO. `FORM`+counted sub-tables are `u32 count` then `count × u32` absolute
offsets, and every record below is reached that way.

## SPRT (178 records, inline 1bpp masks)

```
+0   name_ptr → STRG record (u32 len + NUL bytes, NOT through the table)
+4   w u32, +8 h u32
+12  bbox left/right/bottom/top  4×i32
+28  transparent, smooth, preload, bboxmode, sepmasks  5×u32
+48  origin_x i32, +52 origin_y i32
+56  tpag_count u32, then tpag_count × u32 TPAG pointers
+60+4·tpag_count  mask_count u32, then mask_count × ceil(w/8)·h bytes
     (row-major, MSB-first, rows padded to whole bytes, blob padded to 4)
```
Guard: every record must consume exactly its span and land on the next record
offset (± the 0..3 pad). 178/178 do. spr_player (id 29) is 32×34, origin (15,16).

## TPAG

`l, t, w, h` 4×u32 then PNG file offset + length at +16. TXTR holds the PNG
blobs (128-byte aligned).

## OBJT (191 records)

```
+0  name_ptr → STRG record          +4  sprite i32
+8  visible u32                     +12 solid u32
+16 depth i32   ← the layer          +20 persistent u32
+24 parent i32 (-28 = no parent)    +28 texture_mask_id i32
+32 physics enabled, sensor, collision_shape, density, restitution, group,
    linear/angular damping  (7×u32)
+60 vertex_count u32, then vertex_count × 2×u32
+60+8·vc  friction, awake, kinematic, event_type_count  (3×u32)
+44+8·vc  event_type_count × u32 → event lists
event list: u32 count, count × u32 → event records
event record: subtype i32, u32 action_count, action_count × u32 → actions
action record: 56 bytes, see below
```
`depth` and `persistent` are adjacent same-width fields: a reader that takes
+20 for depth yields `depth == persistent` on every record and stays plausible.
That defect shipped once; `object_depth_metadata_ir` now compares the generated
IR, the asset parser and the bytes on every object.

### Action record (56 bytes) and its undocumented words

```
+0 library_id   +4 action_id    +8 kind        +12 use_relative
+16 is_question +20 use_apply_to +24 execution_type
+28 function_name_ptr          +32 code_id i32 +36 argument_count
+40 who i32     +44 relative    +48 is_not     +52 unknown
```
In this asset all 803 actions carry: `library_id` 1, `kind` 7,
`execution_type` 2, `who` -1, `use_relative` 0, `is_question` 0,
`use_apply_to` 1, `argument_count` 1, `relative` 0, `is_not` 0, `unknown` 0,
and `code_id` walks the CODE roster 0..802 in order. The words whose meaning GM
never documents (`kind`, `execution_type`, `who`, `relative`, `is_not`,
`unknown`) are carried as raw names precisely because they are uniform here;
the guard asserts those counts, so a future file that varies them fails instead
of being read as "the same as always".

## ROOM (114 records)

Header:

```
+0  name_ptr, +4 caption_ptr
+8  width u32, +12 height u32, +16 speed u32, +20 persistent u32
+24 background_colour u32      +28 draw_background_colour u32 (flag)
+32 creation_code_id i32 (-1 = none)
+36 flags u32                  +40 backgrounds, +44 views, +48 objects, +52 tiles
```
`flags` bits (UMT `RoomEntryFlags`): 1 = EnableViews, 2 = ClearViewBackground
(ShowColor), 4 = DoNotClearDisplayBuffer. **This asset: 5 in all 114 rooms**
(views enabled, display buffer not cleared), `creation_code_id == -1` in all
114 (no room runs a creation code), `background_colour` 0 in 110 rooms and
0x00C0C0C0 in 4, `draw_background_colour` set in exactly one room (rm_town,
whose colour is black) — so the remake's constant black clear is faithful for
this data. Whether the original actually leaves the previous frame as the
backdrop in the 113 rooms that clear nothing is **not** settled here: no
original pixel evidence has been recorded for those rooms, and this batch does
not change the clear path.

Sub-tables (all four present in all 114 rooms; each is count + absolute
offsets):

* **object placement** (71,014 total): `x +0, y +4, object +8, instance_id +12,
  creation_code_id +16, scale_x f32 +20, scale_y f32 +24, colour u32 +28,
  rotation f32 +32`, stride 40. Stopping at colour (28 bytes) drops rotation;
  three placements rotate 90° and the angle feeds the rotated sprite box, so
  the damage is collision geometry.
* **tile** (one room only, rm_level1, 114): `x +0, y +4, bg_id +8, src_x +12,
  src_y +16, width +20, height +24, depth +28 (1_000_000), id +32
  (10_000_000+), scale_x f32 +36, scale_y f32 +40`, stride 48. Every record has
  `bg_id = -1` and no CODE calls a `tile_*` builtin, so the faithful render is
  nothing — not a dropped layer.
* **view** (8/room, 912): `visible +0, xview +4, yview +8, wview +12, hview +16,
  xport +20, yport +24, wport +28, hport +32, hborder +36, vborder +40,
  hspeed +44, vspeed +48 (both -1 = no auto-scroll), object +52 (-1 or a real
  object id = follow target)`, stride 56. Only slot 0 is visible in this asset;
  it is the camera state the renderer follows.
* **background** (8/room, 912): `enabled +0, foreground +4, background_id +8
  (-1 = none, else a BGND index), x +12, y +16, tiled_horizontally +20,
  tiled_vertically +24, speed_x +28, speed_y +32, stretch +36`, stride 40.
  Field order is attested against UndertaleModTool's `UndertaleRoom.Background`
  (`ChildObjectsSize = 40`) **and** against all 912 slots here.
  Survey: 106 slots enabled, 0 foreground, 2 naming a background (rm_town →
  BGND 5, rm_level1 → BGND 0, **both disabled**), tiling 802/802, stretch 103,
  every slot at 0,0 with zero speed. Therefore **no room draws a background
  layer**; a renderer that adds one is inventing a layer the data does not
  have. `RoomBackground` carries the comment so the next reader does not read
  "no background on screen" as a missing feature.

## BGND (8 records)

`name_ptr +0, transparent +4, smooth +8, preload +12, tpag_ptr +16` (absolute
TPAG record offset). Flags are 0/1 and every `tpag_ptr` resolves a non-empty
page rect — a background that resolves no page cannot be blitted at all.

## FONT (glyph boxes)

```
+0 name_ptr, +4 system_name_ptr, +8 size, +12 bold, +16 italic, +20 charset,
+24 antialias, +28 page_tpag_ptr, +32 aa_level f32, +36 scale f32,
+40 glyph_count u32, then glyph_count × u32 glyph record offsets
glyph record = 8 × u16: ch, x, y, w, h, shift, offset, unused (16 bytes)
```
Falsifier is containment: every glyph box must satisfy `x + w <= page.w` and
`y + h <= page.h` against the font's own page rect (8 fonts, >500 glyphs).

## Words the readers drop, and why that is safe

| Word | Where | This asset | Guard |
| --- | --- | --- | --- |
| CODE entry +16 | `parse_code_entries` | 0 in all 1354 entries | `the_words_the_readers_drop_are_uniform_in_this_asset` |
| CODE entry +8 `locals_count` | discarded | {1:1349, 2:2, 3:1, 5:1, 7:1} | same |
| VARI header +4 `max_variable_count` | discarded | 691 (= count) | same |
| VARI header +8 `locals_count` | discarded | 7 | same |
| action +8/24/40/44/48/52 | raw names on `ObjectAction` | uniform (see above) | `every_objt_action_record_matches_the_parser_and_its_undocumented_words_are_uniform` |
| action +28 function name | `ObjectAction::function_name` | one shared pointer, resolving to an **empty** string, for all 803 actions | same |

A word that is uniform across the whole table is provably free to drop, and the
count is the evidence for saying so. The guards assert these counts, so the
"free to drop" claim cannot silently become false.

## Known deviations

* Placement scale/rotation are applied **after** the object's Create event,
  while the engine applies room values first. Measured unobservable in this
  asset (no object whose Create writes `image_xscale/yscale/angle` is placed
  with a non-default transform); recorded, not churned.
* All collision queries go through bounding boxes; pixel-precise `prec` checks
  are not implemented. Declared at each contract boundary, never claimed as
  pixel equivalence.
