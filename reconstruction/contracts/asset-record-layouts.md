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
+24 parent i32 (-100 = none)        +28 texture_mask_id i32 (-1 in all 191)
+32 physics enabled, sensor, collision_shape, density, restitution, group,
    linear damping, angular damping                        (8×u32)
+64 vertex_count u32 (2 in 172 objects, 0 in the 19 parents/effect objects)
+68 friction f32 (0.2 in all 191), +72 awake (1), +76 kinematic (0)
+80 vertex_count × (x f32, y f32)
    — the three scalars precede the vertex pairs (UTMT `UndertaleGameObject`
    order). The block is fixed-size (8·vc + 16), so a reader that takes the
    array first still lands on the same event table but files every vc>0
    object's values under the wrong fields. That defect shipped once; nothing
    failed because the byte span is identical, so
    `the_objt_physics_tail_matches_the_bytes_in_the_engines_field_order`
    now compares the parser against the bytes per object.
+80+8·vc  event_type_count u32 (13 in all 191), then event_type_count × u32
    → event lists
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
`y + h <= page.h` against the font's own page rect (6 fonts, 576 glyphs — the
drop-table survey counts them).

## Words the readers drop, and why that is safe

| Word | Where | This asset | Guard |
| --- | --- | --- | --- |
| CODE entry +16 | `parse_code_entries` | 0 in all 1354 entries | `the_words_the_readers_drop_are_uniform_in_this_asset` |
| CODE entry +8 `locals_count` | discarded | {1:1349, 2:2, 3:1, 5:1, 7:1} | same |
| VARI header `VarCount1` / `VarCount2` | discarded | 691 / 691 — the instance-variable count (records neither Local nor Builtin; matches the live runtime's `g_nInstanceVariables`), **not a record count** | `the_variable_record_list_runs_to_the_end_and_classifies_every_scope` |
| VARI header `MaxLocalVarCount` | discarded | 7 | same |
| VARI entry +4 `instance_type` / +8 `var_id` | discarded | scopes -5 Global ×417, -7 Local ×1,368, -1 Self ×303; `var_id` = slot (-6 Builtin marker ×29, 0 ×1,355, positive otherwise) | `the_variable_record_list_runs_to_the_end_and_classifies_every_scope` |
| action +8/24/40/44/48/52 | raw names on `ObjectAction` | uniform (see above) | `every_objt_action_record_matches_the_parser_and_its_undocumented_words_are_uniform` |
| action +28 function name | `ObjectAction::function_name` | one shared pointer, resolving to an **empty** string, for all 803 actions | same |
| OBJT +28 `texture_mask_id` | `_texture_mask_id` | -1 in all 191 — no mask sprite | `the_words_the_readers_drop_are_uniform_in_this_asset` |
| FONT +24 antialias / +32 aa_level / +36 scale / glyph +14 `unused` | discarded | 127 / 1.0 / 1.0 / 0 across all 6 fonts and 576 glyphs | `the_words_the_readers_drop_are_uniform_in_this_asset` |
| SOND +4 flags / +16 effects / +24 pitch / +28 audio group | enumerated then discarded | 0x65 ×29 / 0x64 ×25; effects 0; pitch 0.0; builtin group 0 — full map in `audio-catalog.md` | `the_sound_records_carry_the_streamed_embedded_split` |

A word that is uniform across the whole table is provably free to drop, and the
count is the evidence for saying so. The guards assert these counts, so the
"free to drop" claim cannot silently become false. Where the values are not
uniform (the VARI entry words), the distribution itself is the evidence and is
asserted the same way.

## GEN8 — general info (588 bytes)

Fixed fields, by offset from the chunk body (UndertaleModTool
`UndertaleGeneralInfo`, GMS1 branch):

| Offset | Field | This asset |
| --- | --- | --- |
| +0 (1 byte) | debugger attached | 1 |
| +1 (1 byte) | **bytecode version** | **16** — the recovered bytecode ledger rejects anything else |
| +2 | u16 padding | 0 |
| +4 / +8 | runner filename / config name | `Real Cally 2 Google Play` / `Default` |
| +12 / +16 / +20 | last object / last tile / game id | 171014 / 10000114 / 778478177 |
| +24 | DirectPlay GUID (16 bytes) | all zero |
| +40 | **game name** | `Real_Cally_2_Google_Play` |
| +44..+56 | runtime version major/minor/release/build | 1 / 0 / 0 / 1804 |
| +60 / +64 | **default window width / height** | **1136 / 640** |
| +68 | info flags (UMT `InfoFlags`) | 0x8A0 = ShowCursor \| ScreenKey \| StudioVersionB3 (no Scale bit) |
| +72 / +76 | license CRC32 / MD5 | — |
| +92 | compile timestamp (u64) | 1540414166 (2018-10-24) |
| +100 | **display name (window title)** | `Callys Caves 2` |
| +112 / +120 / +124 | function classifications / Steam app id / debugger port | — |
| +128 | **room order**: `u32 count` + count × u32 | 114 entries, **identity**, tiling the chunk exactly (128+4+456 = 588) |

Two consequences the tree depends on, both asserted in
`the_general_info_declares_the_canvas_and_the_room_order_that_numbers_the_rooms`:

* **Room indexing.** The room order is the identity permutation, so a room's
  position in the ROOM chunk IS its engine room index — the assumption behind
  every `room_goto` argument and the whole room-numbering table (room 0 =
  `rm_town`, room 8 = `rm_level8`, …).
* **The canvas.** The declared window is 1136×640, and the engine's
  `Scene::display_width/height`, the JNI pointer mapping and the Java presenter
  all hardcode that same pair. The guard compares the asset against
  `Scene::default()`, so either side drifting alone fails.

Note for a future reader: the room-order entries here are room **indices**
(0..113), while the GMS1 spec path in UndertaleModTool would read a resource
list of **pointers**. In this file the values cannot be pointers into a 28 MB
image, and the list tiles the chunk exactly, so indices is the reading that
survives both falsifiers.

`game_name` used to be guessed from the first string-table entry — a tab
character in this asset. It is now GEN8 +40, with the old guess kept only as a
fallback when GEN8 is absent.

## Chunks that are present but empty

| Chunk | Body | Meaning |
| --- | --- | --- |
| PATH, SCPT, GLOB, SHDR, TMLN, AGRP | `u32 0` (4 bytes) | no paths, scripts, shaders, timelines or audio groups; **GLOB holds no global-initialisation code**, so every global can only come from an object event |
| DAFL | 0 bytes | empty marker chunk |

Guard: `the_asset_declares_no_scripts_timelines_paths_shaders_or_audio_groups`.

## VARI (2,088 records, 20 bytes each)

Header: `VarCount1 +0, VarCount2 +4, MaxLocalVarCount +8` (UndertaleModTool
`UndertaleChunkVARI`; obsolete aliases `InstanceVarCount` /
`InstanceVarCountAgain`). **The header counts are metadata, not the record
count** — UTMT reads the list to the end of the chunk (`while Position + 20 <=
end`), and the records tile it exactly: (41,772 − 12) / 20 = 2,088. In this asset `VarCount1 = VarCount2 = 691`
— exactly the number of records that are neither Local (`-7`) nor
Builtin-marked (`-6`): 417 Global + 274 Self. The live runtime reports the same
number as `g_nInstanceVariables` (`reconstruction/live-mem/live-findings-v1.md`);
the exact compiler rule behind the count is not attested beyond this equality.
A reader that trusted
`VarCount1` as the record count dropped the tail: the first 691 records carry
39,263 of the 52,459 reference positions.

Entries: `name_ptr +0, instance_type +4, var_id +8, occurrence_count +12,
first_occurrence +16` (UTMT `UndertaleVariable`). The occurrence pair drives
the same delta-linked chain as FUNC (27-bit forward delta; final node carries
the name's STRG index; all 732 chains land inside code bodies and no position
is claimed twice). Survey of the whole list: 417 Global (`-5`) on positive
slots; 1,368 Local (`-7`) — 1,354 `arguments` (one per CODE body, slot 0) plus
14 named locals (`hcollide` 1, `vcollide` 2, `i` 1 ×2, `pc` 1, `pc2..pc6`
2..6, `val` 1, `map` 2, `purchase_id` 3, `product_id` 4); 303 Self (`-1`) —
273 on positive slots, 29 on the `-6` Builtin marker (`x`, `y`, `room`,
`score`, …), 1 on slot 0 (`prototype`). All 1,356 records without occurrences
carry `-1` (UTMT throws otherwise).

Guard: `the_variable_record_list_runs_to_the_end_and_classifies_every_scope`;
the parser side is pinned by
`crates/asset/src/lib.rs::the_variable_reference_map_covers_the_whole_vari_record_list`.

## FUNC (99 records, 12 bytes each + the code-locals tail)

`name_ptr +0, occurrences +4, first_occurrence +8` (UndertaleModTool
`UndertaleFunction`; `Occurrences` is documented as "how often this
UndertaleFunction is referenced in code"). On the reference asset every
`name_ptr` resolves to a NUL-terminated identifier inside STRG (all 99 unique);
`occurrences` spans 1..2796 with 46 distinct values, summing to 14,731; and
`first_occurrence` is the head of a chain that runs through the CODE bodies —
each node's second word carries the 27-bit forward delta to the next occurrence
(`ReferenceNextOccurrenceOffset = word & 0x07FFFFFF`), while the final node
instead carries the function's STRG table index in its low 24 bits
(`NameStringID`, per `UndertaleInstruction.ParseReferenceChain`). All 14,731
nodes land inside code bodies on 4-byte boundaries, the final node's index
matches the name for all 99 functions, and no position is claimed twice.
`draw_sprite_ext` (2,796) is the most referenced builtin.

The tail is the code-locals table (UTMT `UndertaleCodeLocals`): `count =
1,354`, then per entry `{var_count, code_name_ptr, var_count × {index,
name_ptr}}` — 1,354 entries covering every CODE body exactly once (variable
slot 0 is always `arguments`), 1,368 local variables total; the table exhausts
the chunk (4 + 12×99 = 1,192, then 21,780 bytes of locals = 22,972). UTMT notes
it "seems to be unused" but breaking it can cause segfaults, so the reverse
tooling parses it (`scripts/reverse_code.py` → `references` + `parse_locals`)
and the layout test pins it against the bytes.

Guards: `every_func_record_resolves_a_name_and_a_code_site`,
`the_code_locals_section_binds_every_code_by_name`.

STRG carries 3,210 strings; its pointer table is a counted list of absolute
offsets, with each string record being `u32 length + bytes`.

## The remaining chunks (inventory)

| Chunk | Body | Definition |
| --- | --- | --- |
| OPTN | 80 bytes | NewFormat (`ShaderExtensionFlag` = int.MinValue `0x80000000`), `ShaderExtensionVersion` 2, options info flags `0x00CC7A14`, no loading images, `LoadAlpha` 255, then **2 game constants**: `@@SleepMargin` = `1`, `@@DrawColour` = `4294967295`. `@@DrawColour` is the white the live runtime reports in its `Draw_Color` slot — the data file and the running game agree on the default draw colour. |
| LANG | 12 bytes | `UndertaleLanguage`: `Unknown1 = 1` (meaning unknown upstream), `LanguageCount = 0`, `EntryCount = 0`, then the empty entry-id and language lists — the game ships no localizations. |
| EXTN | 224 bytes | exactly **one extension**: the AdColony ad SDK. Pointer list → extension `{folder "", name "AdColonyExtension", class "AdColonyExt"}` → one file `{filename "AdColony.ext", no cleanup/init script, kind 4 = Generic}` → five function records `{name, id 1..5, kind word 11 (not in UTMT's enum), return type 2 = Double, ext name = the function name, argument types 1 = String}`: `AdColony_Init` (3 args), `AdColony_ShowVideo` / `AdColony_ShowVideoForV4VC` (1 arg), `AdColony_V4VCAvailable` / `AdColony_VideoAvailable` (0 args) — the arg counts match the recovered GML calls. The chunk ends with the 16-byte product-id blob (build 1804 ≥ 1773). The exported symbols are in the FUNC roster and object code calls them; the remake dispatches them as platform no-ops. |
| TXTR | 4 textures, 1.88 MB | `u32 count` + count × u32 record offsets; each record is `{u32 scaled = 0, u32 blob_offset}`; every blob is **128-byte aligned** and starts with the PNG magic. Those 4 PNGs are the only PNGs anywhere in the file. |
| TPAG | 1,791 records | texture-page rects (`l, t, w, h` + PNG source); the SPRT section consumes them. |
| SOND / AUDO | — | audio catalogue; see `audio-sond.json` and `audio-audo.json`. |
| AGRP / PATH / SCPT / GLOB / SHDR / TMLN / DAFL | empty | see "Chunks that are present but empty". |

Structural guard: `every_chunk_in_the_file_is_one_this_contract_names` walks the
chunk table, rejects a repeated tag (the readers key chunks by tag, so a
duplicate would silently win) and requires the walk to end exactly at EOF — a
file that gains a chunk fails there before any per-chunk guard can be fooled by
reading the wrong region.

## Known deviations

* Placement scale/rotation are applied **after** the object's Create event,
  while the engine applies room values first. Measured unobservable in this
  asset (no object whose Create writes `image_xscale/yscale/angle` is placed
  with a non-default transform); recorded, not churned.
* All collision queries go through bounding boxes; pixel-precise `prec` checks
  are not implemented. Declared at each contract boundary, never claimed as
  pixel equivalence.
* `flags` bit 2 (`DoNotClearDisplayBuffer`) is set in all 114 rooms and 113 of
  them clear nothing, so in principle the previous frame is the backdrop there.
  No original pixel evidence covers those rooms, so the clear path is unchanged
  and the question is recorded rather than answered by a guess.
