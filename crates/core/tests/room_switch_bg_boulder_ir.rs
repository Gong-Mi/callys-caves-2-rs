//! Arm-level branch coverage for the two flat `switch (room)` Create tables:
//! CODE 360 (gml_Object_obj_bg_Create_0, 114 arms) and CODE 32
//! (gml_Object_obj_boulder_Create_0, 113 arms). Both bodies are bytecode-shaped
//!
//!     load room;
//!     [dup; constant K; cmp(3 = eq); bt arm_K] x N
//!     catch-all body; b exit                        <- untargeted fall-through
//!     arm bodies ...; b exit
//!     exit: popz
//!
//! and every arm writes the room's static geometry choice: obj_bg stores the
//! instance field `bg` plus the GLOBAL player pin `startx`/`starty` (selector
//! -5), obj_boulder stores `sprite_index`. These are the shipped per-room
//! background/sprite tables, i.e. the data the renderer and the room-entry
//! player pin depend on.
//!
//! The expected tables below were extracted straight from the authoritative
//! bytecode in `crates/core/src/generated/full_ir.json` - constant -> store per
//! arm, never guessed from room names, never hand transcribed. Extraction
//! (scratch, not checked in): `wl45-bg-boulder_gen.py`, which loads the JSON,
//! walks each body's `dup; constant; cmp; bt` chain, decodes every arm body up
//! to its terminating `b`, and prints these consts. The same script cross-reads
//! the shipped `assets/game.droid` CODE chunk through `scripts/reverse_code.py`
//! (CODE 360 @4209768 len 6436, CODE 32 @3874728 len 3644 - the IR start/length
//! agree), so the table is anchored to the asset and not only to the IR file.
//!
//! Arm census, re-checked programmatically by
//! `the_arm_census_...` (the extraction reports the same numbers):
//!   * CODE 360: 114 arms, 114 DISTINCT room constants (exactly 0..=113, no
//!     repeats). The chain is NOT sorted - room 110's test is the LAST of the
//!     four tail arms, after 111/112/113. A prior census note claimed "114 arms
//!     but room constants only 0..110 (111 values), therefore duplicate arms";
//!     the bytecode says otherwise, and this suite pins the real shape. Because
//!     there is no duplicate constant the "first matching arm wins" rule has no
//!     duplicate to choose between here, but the tables keep bytecode order
//!     verbatim and the per-arm ledger check asserts the mechanism that makes
//!     the rule: the test chain stops at the first equal comparison, so the
//!     comparisons after the winning arm never execute.
//!   * CODE 32: 113 arms, 113 distinct constants, room 110 absent - the single
//!     hole in 0..=113, so room 110 is this body's own fall-through case.
//!   * Neither table's first body (code_offset 1964 for CODE 360, 1828 for
//!     CODE 32) is the target of any `bt`: that is the catch-all, and it is
//!     EMPTY. An unmatched room therefore stores nothing at all - `bg` stays
//!     absent, a sentinel `startx`/`starty` survives, obj_boulder keeps the
//!     object's shipped sprite (10) from `create`.
//!
//! Fixture: the Create body runs through the materializer's own path,
//! `s.create(&b, OBJ, x, y)` -> `dispatch(0, 0)`, with the VM reading `room`
//! from `Scene::current_room`. Arm-level coverage is read back from the
//! engine's own instruction ledger (`Scene::executed`, one entry per VM
//! instruction), so a positive case must show exactly its own arm body and a
//! negative case only the catch-all.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::Scene;
use std::path::Path;

/// Object ids, read off the bytecode IR / object table (obj_bg 65, obj_boulder
/// 6; obj_boulder's parent 34 is par_wall and carries no Create of its own, so
/// `dispatch(0, 0)` runs CODE 32 alone).
const BG: i32 = 65;
const BOULDER: i32 = 6;

// CODE 360 layout, from full_ir.json: start 4209768, end 4216204.
const BG_CODE: usize = 360;
const BG_START: usize = 4_209_768;
/// First `dup` of the test chain: chain tests are 16 bytes each.
const BG_CHAIN_OFF: usize = 140;
/// The untargeted catch-all body - the first body in layout order.
const BG_FIRST_BODY_OFF: usize = 1964;
/// Shared exit that drops the `dup`ed room value.
const BG_POPZ_OFF: usize = 6432;

// CODE 32 layout, from full_ir.json: start 3874728, end 3878372.
const BOULDER_CODE: usize = 32;
const BOULDER_START: usize = 3_874_728;
const BOULDER_CHAIN_OFF: usize = 20;
const BOULDER_FIRST_BODY_OFF: usize = 1828;
const BOULDER_POPZ_OFF: usize = 3640;

/// Distinctive pre-seeded global pin value: an arm that does not store
/// startx/starty leaves this in place, which is how the four tail arms of
/// CODE 360 are told apart from arms that store the same numbers twice.
const SENTINEL: f64 = -999.0;

// ---- extracted arm tables (generated) ----

/// (room, bg, startx/starty global pin, body code_offset) - CODE 360's
/// test chain in bytecode order, one line per arm. `None` means the arm
/// stores `bg` only (rooms 111/112/113/110). The `arm N` in the trailing
/// comment is the CHAIN POSITION, not the room - room 110's arm is the
/// LAST row (arm index 113).
/// Extracted from full_ir.json CODE 360 (start 4209768), never hand written.
#[rustfmt::skip]
const BG_ARMS: [(i32, i32, Option<(i32, i32)>, usize); 114] = [
    (0, 5, Some((416, 492)), 1968), // CODE 360 arm 0
    (1, 1, Some((128, 492)), 2008), // CODE 360 arm 1
    (2, 2, Some((128, 492)), 2048), // CODE 360 arm 2
    (3, 1, Some((128, 140)), 2088), // CODE 360 arm 3
    (4, 3, Some((128, 524)), 2128), // CODE 360 arm 4
    (5, 2, Some((128, 300)), 2168), // CODE 360 arm 5
    (6, 2, Some((1856, 1164)), 2208), // CODE 360 arm 6
    (7, 0, Some((128, 364)), 2248), // CODE 360 arm 7
    (8, 3, Some((128, 428)), 2288), // CODE 360 arm 8
    (9, 4, Some((128, 1132)), 2328), // CODE 360 arm 9
    (10, 6, Some((128, 140)), 2368), // CODE 360 arm 10
    (11, 1, Some((128, 524)), 2408), // CODE 360 arm 11
    (12, 4, Some((224, 140)), 2448), // CODE 360 arm 12
    (13, 3, Some((1888, 172)), 2488), // CODE 360 arm 13
    (14, 2, Some((128, 1164)), 2528), // CODE 360 arm 14
    (15, 1, Some((128, 172)), 2568), // CODE 360 arm 15
    (16, 4, Some((128, 204)), 2608), // CODE 360 arm 16
    (17, 3, Some((128, 268)), 2648), // CODE 360 arm 17
    (18, 2, Some((128, 236)), 2688), // CODE 360 arm 18
    (19, 1, Some((128, 236)), 2728), // CODE 360 arm 19
    (20, 4, Some((256, 204)), 2768), // CODE 360 arm 20
    (21, 3, Some((128, 684)), 2808), // CODE 360 arm 21
    (22, 2, Some((128, 204)), 2848), // CODE 360 arm 22
    (23, 1, Some((128, 204)), 2888), // CODE 360 arm 23
    (24, 4, Some((128, 108)), 2928), // CODE 360 arm 24
    (25, 2, Some((128, 204)), 2968), // CODE 360 arm 25
    (26, 3, Some((128, 204)), 3008), // CODE 360 arm 26
    (27, 6, Some((128, 140)), 3048), // CODE 360 arm 27
    (28, 1, Some((128, 204)), 3088), // CODE 360 arm 28
    (29, 7, Some((128, 236)), 3128), // CODE 360 arm 29
    (30, 3, Some((128, 1164)), 3168), // CODE 360 arm 30
    (31, 4, Some((128, 204)), 3208), // CODE 360 arm 31
    (32, 1, Some((128, 268)), 3248), // CODE 360 arm 32
    (33, 7, Some((128, 204)), 3288), // CODE 360 arm 33
    (34, 2, Some((128, 1932)), 3328), // CODE 360 arm 34
    (35, 3, Some((128, 428)), 3368), // CODE 360 arm 35
    (36, 1, Some((128, 204)), 3408), // CODE 360 arm 36
    (37, 4, Some((128, 140)), 3448), // CODE 360 arm 37
    (38, 7, Some((128, 204)), 3488), // CODE 360 arm 38
    (39, 2, Some((128, 204)), 3528), // CODE 360 arm 39
    (40, 3, Some((128, 1164)), 3568), // CODE 360 arm 40
    (41, 1, Some((128, 204)), 3608), // CODE 360 arm 41
    (42, 4, Some((128, 204)), 3648), // CODE 360 arm 42
    (43, 1, Some((544, 204)), 3688), // CODE 360 arm 43
    (44, 3, Some((1120, 76)), 3728), // CODE 360 arm 44
    (45, 2, Some((128, 204)), 3768), // CODE 360 arm 45
    (46, 1, Some((128, 108)), 3808), // CODE 360 arm 46
    (47, 7, Some((128, 140)), 3848), // CODE 360 arm 47
    (48, 6, Some((128, 140)), 3888), // CODE 360 arm 48
    (49, 2, Some((128, 300)), 3928), // CODE 360 arm 49
    (50, 3, Some((128, 268)), 3968), // CODE 360 arm 50
    (51, 0, Some((128, 140)), 4008), // CODE 360 arm 51
    (52, 4, Some((128, 204)), 4048), // CODE 360 arm 52
    (53, 1, Some((128, 204)), 4088), // CODE 360 arm 53
    (54, 2, Some((128, 140)), 4128), // CODE 360 arm 54
    (55, 3, Some((608, 556)), 4168), // CODE 360 arm 55
    (56, 7, Some((128, 300)), 4208), // CODE 360 arm 56
    (57, 4, Some((128, 364)), 4248), // CODE 360 arm 57
    (58, 1, Some((128, 204)), 4288), // CODE 360 arm 58
    (59, 2, Some((128, 204)), 4328), // CODE 360 arm 59
    (60, 3, Some((128, 140)), 4368), // CODE 360 arm 60
    (61, 0, Some((128, 108)), 4408), // CODE 360 arm 61
    (62, 4, Some((1664, 620)), 4448), // CODE 360 arm 62
    (63, 1, Some((128, 204)), 4488), // CODE 360 arm 63
    (64, 6, Some((128, 140)), 4528), // CODE 360 arm 64
    (65, 3, Some((128, 108)), 4568), // CODE 360 arm 65
    (66, 4, Some((128, 204)), 4608), // CODE 360 arm 66
    (67, 2, Some((128, 108)), 4648), // CODE 360 arm 67
    (68, 1, Some((640, 364)), 4688), // CODE 360 arm 68
    (69, 3, Some((1888, 172)), 4728), // CODE 360 arm 69
    (70, 2, Some((128, 684)), 4768), // CODE 360 arm 70
    (71, 1, Some((128, 204)), 4808), // CODE 360 arm 71
    (72, 4, Some((448, 684)), 4848), // CODE 360 arm 72
    (73, 3, Some((128, 108)), 4888), // CODE 360 arm 73
    (74, 2, Some((128, 204)), 4928), // CODE 360 arm 74
    (75, 1, Some((672, 684)), 4968), // CODE 360 arm 75
    (76, 4, Some((128, 204)), 5008), // CODE 360 arm 76
    (77, 3, Some((128, 172)), 5048), // CODE 360 arm 77
    (78, 2, Some((128, 108)), 5088), // CODE 360 arm 78
    (79, 1, Some((128, 204)), 5128), // CODE 360 arm 79
    (80, 4, Some((128, 204)), 5168), // CODE 360 arm 80
    (81, 3, Some((128, 204)), 5208), // CODE 360 arm 81
    (82, 6, Some((128, 140)), 5248), // CODE 360 arm 82
    (83, 3, Some((128, 204)), 5288), // CODE 360 arm 83
    (84, 2, Some((128, 108)), 5328), // CODE 360 arm 84
    (85, 1, Some((128, 204)), 5368), // CODE 360 arm 85
    (86, 4, Some((128, 204)), 5408), // CODE 360 arm 86
    (87, 3, Some((128, 204)), 5448), // CODE 360 arm 87
    (88, 2, Some((128, 204)), 5488), // CODE 360 arm 88
    (89, 1, Some((1888, 204)), 5528), // CODE 360 arm 89
    (90, 4, Some((640, 108)), 5568), // CODE 360 arm 90
    (91, 3, Some((128, 76)), 5608), // CODE 360 arm 91
    (92, 2, Some((128, 140)), 5648), // CODE 360 arm 92
    (93, 1, Some((128, 108)), 5688), // CODE 360 arm 93
    (94, 3, Some((128, 140)), 5728), // CODE 360 arm 94
    (95, 2, Some((128, 108)), 5768), // CODE 360 arm 95
    (96, 3, Some((128, 204)), 5808), // CODE 360 arm 96
    (97, 1, Some((128, 172)), 5848), // CODE 360 arm 97
    (98, 3, Some((128, 204)), 5888), // CODE 360 arm 98
    (99, 4, Some((128, 204)), 5928), // CODE 360 arm 99
    (100, 2, Some((128, 204)), 5968), // CODE 360 arm 100
    (101, 1, Some((128, 204)), 6008), // CODE 360 arm 101
    (102, 4, Some((128, 204)), 6048), // CODE 360 arm 102
    (103, 3, Some((128, 204)), 6088), // CODE 360 arm 103
    (104, 6, Some((128, 140)), 6128), // CODE 360 arm 104
    (105, 2, Some((128, 140)), 6168), // CODE 360 arm 105
    (106, 1, Some((128, 140)), 6208), // CODE 360 arm 106
    (107, 4, Some((128, 140)), 6248), // CODE 360 arm 107
    (108, 3, Some((128, 140)), 6288), // CODE 360 arm 108
    (109, 7, Some((128, 428)), 6328), // CODE 360 arm 109
    (111, 5, None, 6368), // CODE 360 arm 110
    (112, 5, None, 6384), // CODE 360 arm 111
    (113, 5, None, 6400), // CODE 360 arm 112
    (110, 5, None, 6416), // CODE 360 arm 113
];

/// (room, sprite_index, body code_offset) - CODE 32's test chain in
/// bytecode order, one line per arm.
/// Extracted from full_ir.json CODE 32 (start 3874728), never hand written.
#[rustfmt::skip]
const BOULDER_ARMS: [(i32, i32, usize); 113] = [
    (0, 7, 1832), // CODE 32 arm 0
    (1, 7, 1848), // CODE 32 arm 1
    (2, 7, 1864), // CODE 32 arm 2
    (3, 7, 1880), // CODE 32 arm 3
    (4, 7, 1896), // CODE 32 arm 4
    (5, 7, 1912), // CODE 32 arm 5
    (6, 7, 1928), // CODE 32 arm 6
    (7, 7, 1944), // CODE 32 arm 7
    (8, 7, 1960), // CODE 32 arm 8
    (9, 7, 1976), // CODE 32 arm 9
    (10, 7, 1992), // CODE 32 arm 10
    (11, 10, 2008), // CODE 32 arm 11
    (12, 10, 2024), // CODE 32 arm 12
    (13, 10, 2040), // CODE 32 arm 13
    (14, 10, 2056), // CODE 32 arm 14
    (15, 10, 2072), // CODE 32 arm 15
    (16, 10, 2088), // CODE 32 arm 16
    (17, 10, 2104), // CODE 32 arm 17
    (18, 10, 2120), // CODE 32 arm 18
    (19, 10, 2136), // CODE 32 arm 19
    (20, 10, 2152), // CODE 32 arm 20
    (21, 10, 2168), // CODE 32 arm 21
    (22, 10, 2184), // CODE 32 arm 22
    (23, 10, 2200), // CODE 32 arm 23
    (24, 10, 2216), // CODE 32 arm 24
    (25, 10, 2232), // CODE 32 arm 25
    (26, 10, 2248), // CODE 32 arm 26
    (27, 10, 2264), // CODE 32 arm 27
    (28, 13, 2280), // CODE 32 arm 28
    (29, 13, 2296), // CODE 32 arm 29
    (30, 13, 2312), // CODE 32 arm 30
    (31, 13, 2328), // CODE 32 arm 31
    (32, 13, 2344), // CODE 32 arm 32
    (33, 13, 2360), // CODE 32 arm 33
    (34, 13, 2376), // CODE 32 arm 34
    (35, 13, 2392), // CODE 32 arm 35
    (36, 13, 2408), // CODE 32 arm 36
    (37, 13, 2424), // CODE 32 arm 37
    (38, 13, 2440), // CODE 32 arm 38
    (39, 13, 2456), // CODE 32 arm 39
    (40, 13, 2472), // CODE 32 arm 40
    (41, 13, 2488), // CODE 32 arm 41
    (42, 13, 2504), // CODE 32 arm 42
    (43, 13, 2520), // CODE 32 arm 43
    (44, 13, 2536), // CODE 32 arm 44
    (45, 13, 2552), // CODE 32 arm 45
    (46, 13, 2568), // CODE 32 arm 46
    (47, 13, 2584), // CODE 32 arm 47
    (48, 13, 2600), // CODE 32 arm 48
    (49, 16, 2616), // CODE 32 arm 49
    (50, 16, 2632), // CODE 32 arm 50
    (51, 16, 2648), // CODE 32 arm 51
    (52, 16, 2664), // CODE 32 arm 52
    (53, 16, 2680), // CODE 32 arm 53
    (54, 16, 2696), // CODE 32 arm 54
    (55, 16, 2712), // CODE 32 arm 55
    (56, 16, 2728), // CODE 32 arm 56
    (57, 16, 2744), // CODE 32 arm 57
    (58, 16, 2760), // CODE 32 arm 58
    (59, 16, 2776), // CODE 32 arm 59
    (60, 16, 2792), // CODE 32 arm 60
    (61, 16, 2808), // CODE 32 arm 61
    (62, 16, 2824), // CODE 32 arm 62
    (63, 16, 2840), // CODE 32 arm 63
    (64, 16, 2856), // CODE 32 arm 64
    (65, 19, 2872), // CODE 32 arm 65
    (66, 19, 2888), // CODE 32 arm 66
    (67, 19, 2904), // CODE 32 arm 67
    (68, 19, 2920), // CODE 32 arm 68
    (69, 19, 2936), // CODE 32 arm 69
    (70, 19, 2952), // CODE 32 arm 70
    (71, 19, 2968), // CODE 32 arm 71
    (72, 19, 2984), // CODE 32 arm 72
    (73, 19, 3000), // CODE 32 arm 73
    (74, 19, 3016), // CODE 32 arm 74
    (75, 19, 3032), // CODE 32 arm 75
    (76, 19, 3048), // CODE 32 arm 76
    (77, 19, 3064), // CODE 32 arm 77
    (78, 19, 3080), // CODE 32 arm 78
    (79, 19, 3096), // CODE 32 arm 79
    (80, 19, 3112), // CODE 32 arm 80
    (81, 19, 3128), // CODE 32 arm 81
    (82, 19, 3144), // CODE 32 arm 82
    (83, 22, 3160), // CODE 32 arm 83
    (84, 22, 3176), // CODE 32 arm 84
    (85, 22, 3192), // CODE 32 arm 85
    (86, 22, 3208), // CODE 32 arm 86
    (87, 22, 3224), // CODE 32 arm 87
    (88, 22, 3240), // CODE 32 arm 88
    (89, 22, 3256), // CODE 32 arm 89
    (90, 22, 3272), // CODE 32 arm 90
    (91, 22, 3288), // CODE 32 arm 91
    (92, 22, 3304), // CODE 32 arm 92
    (93, 22, 3320), // CODE 32 arm 93
    (94, 22, 3336), // CODE 32 arm 94
    (95, 22, 3352), // CODE 32 arm 95
    (96, 22, 3368), // CODE 32 arm 96
    (97, 22, 3384), // CODE 32 arm 97
    (98, 22, 3400), // CODE 32 arm 98
    (99, 22, 3416), // CODE 32 arm 99
    (100, 22, 3432), // CODE 32 arm 100
    (101, 22, 3448), // CODE 32 arm 101
    (102, 22, 3464), // CODE 32 arm 102
    (103, 22, 3480), // CODE 32 arm 103
    (104, 22, 3496), // CODE 32 arm 104
    (105, 22, 3512), // CODE 32 arm 105
    (106, 22, 3528), // CODE 32 arm 106
    (107, 22, 3544), // CODE 32 arm 107
    (108, 22, 3560), // CODE 32 arm 108
    (109, 22, 3576), // CODE 32 arm 109
    (111, 7, 3592), // CODE 32 arm 110
    (112, 7, 3608), // CODE 32 arm 111
    (113, 7, 3624), // CODE 32 arm 112
];

// ---- fixture ---------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s
}

fn field(s: &Scene, id: i32, name: &str) -> Option<f64> {
    s.instances
        .get(&id)
        .and_then(|i| i.fields.get(name))
        .copied()
}

/// Every instruction the VM entered for one CODE body, as code_offsets
/// (absolute offset - CODE start), in execution order.
fn ledger(s: &Scene, code: usize, start: usize) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(c, _)| *c == code)
        .map(|(_, o)| *o - start)
        .collect()
}

/// (body code_offset, byte length) for every body of a switch table, derived
/// from the arm table itself: the bodies are contiguous from the untargeted
/// catch-all body to the shared `popz` exit.
fn body_spans(arm_bodies: &[usize], first_body: usize, popz: usize) -> Vec<(usize, usize)> {
    let mut offs: Vec<usize> = arm_bodies.to_vec();
    offs.push(first_body);
    offs.sort_unstable();
    offs.dedup();
    let mut out = Vec::new();
    for (i, &o) in offs.iter().enumerate() {
        let end = if i + 1 < offs.len() {
            offs[i + 1]
        } else {
            popz
        };
        out.push((o, end - o));
    }
    out
}

fn body_len(spans: &[(usize, usize)], body: usize) -> usize {
    spans
        .iter()
        .find(|(o, _)| *o == body)
        .map(|(_, l)| *l)
        .unwrap_or_else(|| panic!("no switch body starts at code_offset {body}"))
}

/// The test-chain comparison blocks that must have run for the arm at index
/// `arm` (block 0..=arm) or for an unmatched room (`all = true`).
fn chain_prefix(chain_off: usize, blocks: usize) -> Vec<usize> {
    (0..4 * blocks).map(|k| chain_off + 4 * k).collect()
}

/// The comparisons that ran: the chain slice between the first `dup` and the
/// body region. The Create prologue sits above the chain and is excluded.
fn chain_ran(
    s: &Scene,
    code: usize,
    start: usize,
    chain_off: usize,
    first_body: usize,
) -> Vec<usize> {
    ledger(s, code, start)
        .into_iter()
        .filter(|o| (chain_off..first_body).contains(o))
        .collect()
}

fn bodies_ran(s: &Scene, code: usize, start: usize, first_body: usize, popz: usize) -> Vec<usize> {
    ledger(s, code, start)
        .into_iter()
        .filter(|o| (first_body..popz).contains(o))
        .collect()
}

// ---- CODE 360 (obj_bg Create): 114 arms ------------------------------------

#[test]
// CODE 360
fn every_bg_create_arm_selects_its_shipped_background_and_start_pin() {
    let b = bundle();
    let mut s = scene(&b);
    let spans = body_spans(
        &BG_ARMS.iter().map(|a| a.3).collect::<Vec<_>>(),
        BG_FIRST_BODY_OFF,
        BG_POPZ_OFF,
    );
    let mut ran = 0usize;
    for (arm, &(room, bg, pin, body)) in BG_ARMS.iter().enumerate() {
        // CODE 360 arm {arm} (rooms 0..=109 and the 111/112/113/110 tail).
        s.globals.insert("startx".into(), SENTINEL);
        s.globals.insert("starty".into(), SENTINEL);
        s.current_room = f64::from(room);
        s.executed.clear();
        let id = s
            .create(&b, BG, 0.0, 0.0)
            .unwrap_or_else(|e| panic!("CODE {BG_CODE} arm {arm} (room {room}): {e}"));
        assert_eq!(
            field(&s, id, "bg"),
            Some(f64::from(bg)),
            "CODE {BG_CODE} arm {arm} (room {room}) selects background {bg}"
        );
        match pin {
            Some((x, y)) => {
                assert_eq!(
                    s.globals.get("startx").copied(),
                    Some(f64::from(x)),
                    "CODE {BG_CODE} arm {arm} (room {room}) pins global startx to {x}"
                );
                assert_eq!(
                    s.globals.get("starty").copied(),
                    Some(f64::from(y)),
                    "CODE {BG_CODE} arm {arm} (room {room}) pins global starty to {y}"
                );
            }
            None => {
                // Rooms 111/112/113/110: the arm stores `bg` only, so the pin
                // the previous room left behind must survive untouched.
                assert_eq!(s.globals.get("startx").copied(), Some(SENTINEL),
                    "CODE {BG_CODE} arm {arm} (room {room}) stores only bg - startx must not be written");
                assert_eq!(s.globals.get("starty").copied(), Some(SENTINEL),
                    "CODE {BG_CODE} arm {arm} (room {room}) stores only bg - starty must not be written");
            }
        }
        // The chain short-circuits at the first equal comparison: comparisons
        // 0..=arm ran, arm+1.. never did.
        let expect_chain = chain_prefix(BG_CHAIN_OFF, arm + 1);
        assert_eq!(
            chain_ran(&s, BG_CODE, BG_START, BG_CHAIN_OFF, BG_FIRST_BODY_OFF),
            expect_chain,
            "CODE {BG_CODE} arm {arm} (room {room}) must stop the chain at its own comparison"
        );
        // Exactly this arm's body ran, nothing from a neighbouring arm.
        let len = body_len(&spans, body);
        let body_ran = bodies_ran(&s, BG_CODE, BG_START, BG_FIRST_BODY_OFF, BG_POPZ_OFF);
        assert_eq!(
            body_ran.first(),
            Some(&body),
            "CODE {BG_CODE} arm {arm} (room {room}) must enter the body at code_offset {body}"
        );
        assert!(body_ran.iter().all(|o| *o >= body && *o < body + len),
            "CODE {BG_CODE} arm {arm} (room {room}) executed instructions outside its own body: {body_ran:?}");
        assert_eq!(
            ledger(&s, BG_CODE, BG_START).last(),
            Some(&BG_POPZ_OFF),
            "CODE {BG_CODE} arm {arm} (room {room}) joins the shared popz exit"
        );
        ran += 1;
    }
    assert_eq!(
        ran, 114,
        "the sweep covers CODE {BG_CODE}'s whole 114-arm chain"
    );
}

#[test]
// CODE 360
fn an_unmatched_room_falls_through_the_bg_table_without_storing() {
    let b = bundle();
    let mut s = scene(&b);
    let arms = BG_ARMS.len();
    // Out-of-table rooms, including the two shapes a stale caller could hand in:
    // past the end of the 0..=113 range and a negative value.
    for room in [114, 999, -1, 65535] {
        s.globals.insert("startx".into(), SENTINEL);
        s.globals.insert("starty".into(), SENTINEL);
        s.current_room = f64::from(room);
        s.executed.clear();
        let id = s
            .create(&b, BG, 0.0, 0.0)
            .unwrap_or_else(|e| panic!("CODE {BG_CODE} room {room}: {e}"));
        // The catch-all body of CODE 360 is EMPTY (code_offset {BG_FIRST_BODY_OFF}
        // holds the `b` to the exit and nothing else), so an unmatched room
        // writes neither the background nor the player pin - the field stays
        // unwritten rather than being defaulted to a background id.
        assert_eq!(
            field(&s, id, "bg"),
            None,
            "CODE {BG_CODE} room {room}: no arm matched, so bg must stay unwritten"
        );
        assert_eq!(
            s.globals.get("startx").copied(),
            Some(SENTINEL),
            "CODE {BG_CODE} room {room}: the catch-all stores no startx"
        );
        assert_eq!(
            s.globals.get("starty").copied(),
            Some(SENTINEL),
            "CODE {BG_CODE} room {room}: the catch-all stores no starty"
        );
        // All 114 comparisons run and fail, then the catch-all's `b` and the exit.
        assert_eq!(
            chain_ran(&s, BG_CODE, BG_START, BG_CHAIN_OFF, BG_FIRST_BODY_OFF),
            chain_prefix(BG_CHAIN_OFF, arms),
            "CODE {BG_CODE} room {room}: every comparison must run and fail"
        );
        assert_eq!(
            bodies_ran(&s, BG_CODE, BG_START, BG_FIRST_BODY_OFF, BG_POPZ_OFF),
            vec![BG_FIRST_BODY_OFF],
            "CODE {BG_CODE} room {room}: only the empty catch-all body may run"
        );
        assert_eq!(
            ledger(&s, BG_CODE, BG_START).last(),
            Some(&BG_POPZ_OFF),
            "CODE {BG_CODE} room {room}: the fall-through still reaches the shared exit"
        );
    }
}

// ---- CODE 32 (obj_boulder Create): 113 arms --------------------------------

#[test]
// CODE 32
fn every_boulder_create_arm_stores_its_shipped_sprite_index() {
    let b = bundle();
    let mut s = scene(&b);
    let spans = body_spans(
        &BOULDER_ARMS.iter().map(|a| a.2).collect::<Vec<_>>(),
        BOULDER_FIRST_BODY_OFF,
        BOULDER_POPZ_OFF,
    );
    let mut ran = 0usize;
    for (arm, &(room, sprite, body)) in BOULDER_ARMS.iter().enumerate() {
        // CODE 32 arm {arm} (rooms 0..=109 plus the 111/112/113 tail).
        s.current_room = f64::from(room);
        s.executed.clear();
        let id = s
            .create(&b, BOULDER, 0.0, 0.0)
            .unwrap_or_else(|e| panic!("CODE {BOULDER_CODE} arm {arm} (room {room}): {e}"));
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(f64::from(sprite)),
            "CODE {BOULDER_CODE} arm {arm} (room {room}) selects sprite {sprite}"
        );
        let expect_chain = chain_prefix(BOULDER_CHAIN_OFF, arm + 1);
        assert_eq!(
            chain_ran(
                &s,
                BOULDER_CODE,
                BOULDER_START,
                BOULDER_CHAIN_OFF,
                BOULDER_FIRST_BODY_OFF
            ),
            expect_chain,
            "CODE {BOULDER_CODE} arm {arm} (room {room}) must stop the chain at its own comparison"
        );
        let len = body_len(&spans, body);
        let body_ran = bodies_ran(
            &s,
            BOULDER_CODE,
            BOULDER_START,
            BOULDER_FIRST_BODY_OFF,
            BOULDER_POPZ_OFF,
        );
        assert_eq!(
            body_ran.first(),
            Some(&body),
            "CODE {BOULDER_CODE} arm {arm} (room {room}) must enter the body at code_offset {body}"
        );
        assert!(body_ran.iter().all(|o| *o >= body && *o < body + len),
            "CODE {BOULDER_CODE} arm {arm} (room {room}) executed instructions outside its own body: {body_ran:?}");
        assert_eq!(
            ledger(&s, BOULDER_CODE, BOULDER_START).last(),
            Some(&BOULDER_POPZ_OFF),
            "CODE {BOULDER_CODE} arm {arm} (room {room}) joins the shared popz exit"
        );
        ran += 1;
    }
    assert_eq!(
        ran, 113,
        "the sweep covers CODE {BOULDER_CODE}'s whole 113-arm chain"
    );
}

#[test]
// CODE 32
fn room_110_and_the_out_of_table_rooms_fall_through_the_boulder_table() {
    let b = bundle();
    let mut s = scene(&b);
    let shipped = b
        .objects
        .iter()
        .find(|o| o.id == BOULDER)
        .expect("obj_boulder definition")
        .sprite;
    // The object table's own sprite is what `create` initializes sprite_index
    // to, i.e. the value the body's catch-all leaves in place.
    assert_eq!(shipped, 10, "obj_boulder ships sprite 10");
    assert!(
        !BOULDER_ARMS.iter().any(|a| a.0 == 110),
        "room 110 is the one hole in CODE {BOULDER_CODE}'s 0..=113 chain"
    );
    let arms = BOULDER_ARMS.len();
    // 110 is a real gap in the shipped table; 999 / -1 are past its ends.
    for room in [110, 999, -1] {
        s.current_room = f64::from(room);
        s.executed.clear();
        let id = s
            .create(&b, BOULDER, 0.0, 0.0)
            .unwrap_or_else(|e| panic!("CODE {BOULDER_CODE} room {room}: {e}"));
        // The catch-all body of CODE 32 is EMPTY (code_offset {BOULDER_FIRST_BODY_OFF}
        // is just the `b` to the exit), so sprite_index keeps the shipped
        // create-time value - no arm value is written.
        assert_eq!(
            field(&s, id, "sprite_index"),
            Some(f64::from(shipped)),
            "CODE {BOULDER_CODE} room {room}: the catch-all leaves the shipped sprite 10 in place"
        );
        assert_eq!(
            chain_ran(
                &s,
                BOULDER_CODE,
                BOULDER_START,
                BOULDER_CHAIN_OFF,
                BOULDER_FIRST_BODY_OFF
            ),
            chain_prefix(BOULDER_CHAIN_OFF, arms),
            "CODE {BOULDER_CODE} room {room}: every comparison must run and fail"
        );
        assert_eq!(
            bodies_ran(
                &s,
                BOULDER_CODE,
                BOULDER_START,
                BOULDER_FIRST_BODY_OFF,
                BOULDER_POPZ_OFF
            ),
            vec![BOULDER_FIRST_BODY_OFF],
            "CODE {BOULDER_CODE} room {room}: only the empty catch-all body may run"
        );
        assert_eq!(
            ledger(&s, BOULDER_CODE, BOULDER_START).last(),
            Some(&BOULDER_POPZ_OFF),
            "CODE {BOULDER_CODE} room {room}: the fall-through still reaches the shared exit"
        );
    }
}

// ---- the arm census itself -------------------------------------------------

#[test]
// CODE 360
// CODE 32
fn the_arm_census_matches_the_bytecode_where_the_duplicate_arm_note_does_not() {
    // ---- CODE 360: 114 arms over 114 distinct room constants ----------------
    let bg_rooms: Vec<i32> = BG_ARMS.iter().map(|a| a.0).collect();
    assert_eq!(bg_rooms.len(), 114, "CODE {BG_CODE} ships 114 arms");
    let mut distinct: Vec<i32> = bg_rooms.clone();
    distinct.sort_unstable();
    distinct.dedup();
    assert_eq!(
        distinct.len(),
        114,
        "CODE {BG_CODE} has NO duplicate room constant: 114 arms, 114 distinct rooms (the earlier \
         'duplicates across 0..110' note is contradicted by the bytecode - full_ir.json CODE 360 \
         tests rooms 0..=113 exactly once each)"
    );
    assert_eq!(
        distinct,
        (0..=113).collect::<Vec<i32>>(),
        "CODE {BG_CODE}'s constants are exactly 0..=113"
    );
    // Bytecode order is preserved verbatim, and it is not sorted: room 110 is
    // the LAST arm tested, after 111/112/113.
    let mut expect_order: Vec<i32> = (0..=109).collect();
    expect_order.extend([111, 112, 113, 110]);
    assert_eq!(bg_rooms, expect_order,
        "CODE {BG_CODE}'s chain order: 0..=109 then 111, 112, 113, 110 - room 110's arm is the tail");
    let no_pin: Vec<i32> = BG_ARMS
        .iter()
        .filter(|a| a.2.is_none())
        .map(|a| a.0)
        .collect();
    assert_eq!(
        no_pin,
        vec![111, 112, 113, 110],
        "the four tail arms of CODE {BG_CODE} store bg = 5 and no player pin"
    );
    assert!(
        BG_ARMS.iter().filter(|a| a.2.is_none()).all(|a| a.1 == 5),
        "all four pin-less arms of CODE {BG_CODE} select background 5"
    );
    let mut bgs: Vec<i32> = BG_ARMS.iter().map(|a| a.1).collect();
    bgs.sort_unstable();
    bgs.dedup();
    assert_eq!(
        bgs,
        vec![0, 1, 2, 3, 4, 5, 6, 7],
        "CODE {BG_CODE} spans the shipped background set 0..=7"
    );
    let bg_bodies: Vec<usize> = BG_ARMS.iter().map(|a| a.3).collect();
    let mut bg_sorted = bg_bodies.clone();
    bg_sorted.sort_unstable();
    bg_sorted.dedup();
    assert_eq!(
        bg_sorted.len(),
        bg_bodies.len(),
        "every CODE {BG_CODE} arm is a distinct bt target"
    );
    assert!(
        bg_bodies.windows(2).all(|w| w[0] < w[1]),
        "CODE {BG_CODE}'s bodies are laid out in chain order, so the arm order is the run order"
    );

    // ---- CODE 32: 113 arms, room 110 missing --------------------------------
    let bo_rooms: Vec<i32> = BOULDER_ARMS.iter().map(|a| a.0).collect();
    assert_eq!(bo_rooms.len(), 113, "CODE {BOULDER_CODE} ships 113 arms");
    let mut distinct: Vec<i32> = bo_rooms.clone();
    distinct.sort_unstable();
    distinct.dedup();
    assert_eq!(
        distinct.len(),
        113,
        "CODE {BOULDER_CODE} has no duplicate room constant either: 113 arms, 113 distinct rooms"
    );
    let missing: Vec<i32> = (0..=113).filter(|r| !distinct.contains(r)).collect();
    assert_eq!(
        missing,
        vec![110],
        "room 110 is the single gap in CODE {BOULDER_CODE}'s 0..=113 chain"
    );
    let mut expect_order: Vec<i32> = (0..=109).collect();
    expect_order.extend([111, 112, 113]);
    assert_eq!(
        bo_rooms, expect_order,
        "CODE {BOULDER_CODE}'s chain order is 0..=109 then 111, 112, 113"
    );
    let mut sprites: Vec<i32> = BOULDER_ARMS.iter().map(|a| a.1).collect();
    sprites.sort_unstable();
    sprites.dedup();
    assert_eq!(
        sprites,
        vec![7, 10, 13, 16, 19, 22],
        "CODE {BOULDER_CODE} spans six shipped sprite ids, in room runs"
    );
    let bo_bodies: Vec<usize> = BOULDER_ARMS.iter().map(|a| a.2).collect();
    let mut bo_sorted = bo_bodies.clone();
    bo_sorted.sort_unstable();
    bo_sorted.dedup();
    assert_eq!(
        bo_sorted.len(),
        bo_bodies.len(),
        "every CODE {BOULDER_CODE} arm is a distinct bt target"
    );
    assert!(
        bo_bodies.windows(2).all(|w| w[0] < w[1]),
        "CODE {BOULDER_CODE}'s bodies are laid out in chain order"
    );

    // ---- the catch-all is not an arm of either table ------------------------
    assert!(
        !bg_bodies.contains(&BG_FIRST_BODY_OFF),
        "CODE {BG_CODE}'s fall-through body at code_offset {BG_FIRST_BODY_OFF} is no bt target"
    );
    assert!(!bo_bodies.contains(&BOULDER_FIRST_BODY_OFF),
        "CODE {BOULDER_CODE}'s fall-through body at code_offset {BOULDER_FIRST_BODY_OFF} is no bt target");
}
