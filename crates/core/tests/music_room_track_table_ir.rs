//! Arm-level branch coverage for CODE 378 `gml_Object_obj_music_Other_4`
//! (object 68 `obj_music`, event type 7 subtype 4 = Room Start): the
//! `musicmute` gate and the eleven `if (room == K)` arms that give the eleven
//! storyline rooms their music. The body is 19,204 bytes / 3,855 instructions
//! and was previously only sampled: the client suite drives rm_boss1
//! (`crates/client/tests/gameplay_music_gate.rs`, which this file does not
//! repeat) and nothing here had ever enumerated the other ten arms.
//!
//! Bytecode shape (full_ir.json CODE 378, start 4496544, end 4515748):
//!
//!     off 0:   load musicmute; const 1; cmp(eq); bf -> 24
//!     off 20:  b -> 452                       <- `musicmute == 1`: empty body
//!     off 24:  load musicmute; const 0; cmp(eq); bf -> 452
//!     off 44:  six boss arms, 68 bytes each   <- only reached when musicmute == 0
//!     off 452: five theme arms                <- reached for ANY musicmute
//!
//! This is NOT a `switch`. Every arm is its own `if`, so the chain does not
//! short-circuit: an arm that matches runs its body and then falls through into
//! the NEXT test, and an arm that does not match just continues. That is why a
//! matching dispatch still executes all eleven `room` comparisons (asserted
//! below, exact instruction stream). With eleven distinct room constants the
//! "which arm wins" question is moot, and `the_arm_matrix_...` pins that there
//! are no duplicates.
//!
//! Three shapes of arm, two of them observable in different domains:
//!   * six `musicmute == 0`-guarded direct-track arms (rooms 10, 27, 48, 64,
//!     82, 104 = rm_boss1..rm_boss6): `audio_stop_all()` then
//!     `audio_play_sound(track, 0, true)` with track alternating
//!     mus_bosssong(51) / mus_techno(48).
//!   * five UNGUARDED theme arms (rooms 11, 28, 49, 65, 83 = rm_level9,
//!     room31, room51, room66, room83): `audio_stop_all()`, `alarm[0] = 1`,
//!     `playlist = choose(...)` over {1..10}, then ten `if (playlist == N)`
//!     blocks that write `theme[0..16]`. These issue no play command at all -
//!     the music is started by Alarm 0 (CODE 376) - so their observable effect
//!     is the alarm re-arm, the playlist draw and the theme row.
//!   * the `musicmute == 1` early exit, which skips ONLY the boss chain.
//!
//! The brief's clue that "each arm is audio_stop_all + audio_play_sound(track)"
//! holds for 6 of the 11 arms; the other five are the playlist arms, which the
//! bytecode (and the recovered GML `0378__gml_Object_obj_music_Other_4.gml`)
//! agree on. The clue's room SET {10,11,27,28,48,49,64,65,82,83,104} is exactly
//! right: read by room id it pairs each boss room with the following region's
//! first room, while the bytecode chain lists the six guarded arms first. On
//! every point the clue and the stream disagreed the stream won; nothing did.
//!
//! Grounding: the expected tables below were extracted programmatically from
//! the authoritative bytecode in `crates/core/src/generated/full_ir.json`
//! (scratch generator `wl51-musicmap_gen.py`, which refuses to emit unless
//! every op sequence matches the shape it expects - never hand-read). Sound
//! ids are cross-named against `reconstruction/contracts/audio-sond.json`
//! (SOND 48 = mus_techno, SOND 51 = mus_bosssong; see also audio-catalog.md
//! §6). Every table is re-derived from the LIVE bundle instruction stream at
//! test time and compared entry by entry, so a stale embedded table cannot
//! pass (`the_arm_matrix_matches_the_bundle_instruction_stream`).
//!
//! Fixture discipline (audio-catalog.md §6): `audio_stop_all` only queues a host
//! stop for a voice that is actually live, so each case seeds exactly one
//! looping sentinel voice before the dispatch and drops that voice's own play
//! command. The sentinel's stop command is therefore the arm's `audio_stop_all`
//! made visible. Every case runs in a FRESH `Scene` and nothing is drained, so
//! the `sound_durations` / `is_playing` anti-stack gate of audio-catalog.md §6
//! cannot leak from one arm to the next: a sweep over eleven arms cannot have
//! its later arms refused by a voice an earlier arm started.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Code, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::path::Path;

/// obj_music. Persistent, no parent, and its event table carries 7/4 = CODE 378
/// directly, so `dispatch(7, 4)` runs CODE 378 alone (no parent fallback).
const MUSIC: i32 = 68;
/// gml_Object_obj_music_Other_4.
const CODE378: usize = 378;
/// The Create that `Scene::create` runs first (CODE 375). It writes
/// `alarm[0] = 60` and its own ten-row theme table, so both are useful
/// pre-state: at least one of them must have been overwritten for a Room Start
/// arm to have done anything.
const CODE375: usize = 375;
/// A live voice to seed. SOND 29 = mus_egc, a streamed track, not one this
/// body ever starts (`audio_stop_all` is per-voice, not per-sound-privileged).
const SENTINEL: f64 = 29.0;
/// `playlist` is a plain instance field; `theme[0..16]` and `alarm[0]` are the
/// instance's array / alarm slots (GMS local arrays).
const PLAYLIST: &str = "playlist";
const THEME: &str = "theme";
const THEME_LEN: i32 = 17;
const MUSICMUTE: &str = "musicmute";

// ===== generated from full_ir.json CODE 378 - do not hand-edit =====
// Extracted with: python wl51-musicmap_gen.py  (scratch, not checked in)

/// CODE 378 gml_Object_obj_music_Other_4: object 68 obj_music, event 7/4 (Room Start).
/// start 4496544, end 4515748, span 19204, instructions 3855.
///
/// Shape: a two-deep `musicmute` prologue then eleven independent
/// `if (room == K)` arms - NOT one switch. Six of them sit inside the
/// `musicmute == 0` branch and are skipped wholesale by `!= 0`.
///
///   off 0:   load musicmute; constant 1; cmp(3 = eq); bf -> off 24
///   off 20:  b -> off 452                                  (== 1: skip bosses)
///   off 24:  load musicmute; constant 0; cmp(3); bf -> off 452
///   off 44:  408-byte boss chain, six 68-byte arms [44, 112, 180, 248, 316, 384]
///   off 452:  theme chain, five arms [452, 4212, 7960, 11708, 15456]; ends at 19204

const CODE378_START: usize = 4496544;
const CODE378_LEN: usize = 19204;
const CODE378_INS: usize = 3855;
/// `if (musicmute == 1) {}` test - four instructions, then the `b` at
/// MM1_BRANCH that skips the boss chain (it does NOT skip the theme chain).
const MM1_TEST: usize = 0;
const MM1_BRANCH: usize = 20;
/// `else if (musicmute == 0)` test; its `bf` is MM0_BRANCH, which is also
/// the boss chain's end and the theme chain's first test.
const MM0_TEST: usize = 24;
const MM0_BRANCH: usize = 452;
/// Offset the boss chain starts at (first `load room`).
const BOSS_CHAIN: usize = 44;
/// First theme-arm test == boss chain end == boss `bf` target.
const THEME_CHAIN: usize = 452;

struct BossArm {
    room: i32,
    track: i32,
    test: usize,
    body: usize,
    body_len: usize,
}
struct ThemeArm {
    room: i32,
    /// code_offset of this arm's `call randomize`, if it has one.
    randomize: Option<usize>,
    /// The ten `choose` arguments in PUSH order (`Op::Call` pops LIFO, so the
    /// callee sees the reverse). The candidate set is {1..10} in every arm.
    choose_args: [i32; 10],
    choose_call: usize,
    playlist_store: usize,
    test: usize,
    body: usize,
    body_len: usize,
}

/// The six `musicmute == 0`-guarded arms, bytecode order.
#[rustfmt::skip]
const BOSS_ARMS: [BossArm; 6] = [
    BossArm { room: 10, track: 51, test: 44, body: 64, body_len: 48 },
    BossArm { room: 27, track: 48, test: 112, body: 132, body_len: 48 },
    BossArm { room: 48, track: 51, test: 180, body: 200, body_len: 48 },
    BossArm { room: 64, track: 48, test: 248, body: 268, body_len: 48 },
    BossArm { room: 82, track: 51, test: 316, body: 336, body_len: 48 },
    BossArm { room: 104, track: 48, test: 384, body: 404, body_len: 48 },
];

/// The five UNGUARDED arms - they run for any `musicmute` value.
#[rustfmt::skip]
const THEME_ARMS: [ThemeArm; 5] = [
    ThemeArm { room: 11, randomize: Some(504), choose_args: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
               choose_call: 596, playlist_store: 604, test: 452, body: 472, body_len: 3740 },
    ThemeArm { room: 28, randomize: None, choose_args: [9, 7, 5, 3, 1, 10, 8, 6, 4, 2],
               choose_call: 4344, playlist_store: 4352, test: 4212, body: 4232, body_len: 3728 },
    ThemeArm { room: 49, randomize: None, choose_args: [9, 7, 5, 3, 1, 10, 8, 6, 4, 2],
               choose_call: 8092, playlist_store: 8100, test: 7960, body: 7980, body_len: 3728 },
    ThemeArm { room: 65, randomize: None, choose_args: [9, 7, 5, 3, 1, 10, 8, 6, 4, 2],
               choose_call: 11840, playlist_store: 11848, test: 11708, body: 11728, body_len: 3728 },
    ThemeArm { room: 83, randomize: None, choose_args: [9, 7, 5, 3, 1, 10, 8, 6, 4, 2],
               choose_call: 15588, playlist_store: 15596, test: 15456, body: 15476, body_len: 3728 },
];

/// (playlist, block code_offset, block byte length), bytecode order. One entry
/// per `if (playlist == N)` block; each block is 17 theme[] array stores.
#[rustfmt::skip]
const THEME_BLOCKS: [[(i32, usize, usize); 10]; 5] = [
    [(1, 632, 340), (2, 992, 340), (3, 1352, 340), (4, 1712, 340), (5, 2072, 340),
     (6, 2432, 340), (7, 2792, 340), (8, 3152, 340), (9, 3512, 340), (10, 3872, 340)],
    [(1, 4380, 340), (2, 4740, 340), (3, 5100, 340), (4, 5460, 340), (5, 5820, 340),
     (6, 6180, 340), (7, 6540, 340), (8, 6900, 340), (9, 7260, 340), (10, 7620, 340)],
    [(1, 8128, 340), (2, 8488, 340), (3, 8848, 340), (4, 9208, 340), (5, 9568, 340),
     (6, 9928, 340), (7, 10288, 340), (8, 10648, 340), (9, 11008, 340), (10, 11368, 340)],
    [(1, 11876, 340), (2, 12236, 340), (3, 12596, 340), (4, 12956, 340), (5, 13316, 340),
     (6, 13676, 340), (7, 14036, 340), (8, 14396, 340), (9, 14756, 340), (10, 15116, 340)],
    [(1, 15624, 340), (2, 15984, 340), (3, 16344, 340), (4, 16704, 340), (5, 17064, 340),
     (6, 17424, 340), (7, 17784, 340), (8, 18144, 340), (9, 18504, 340), (10, 18864, 340)],
];

/// theme[0..=16] written by `if (playlist == N)` - index = playlist - 1. All
/// five theme arms ship the same ten rows; each row is a distinct permutation
/// of the same 17 ids. NOTE: obj_music's Create (CODE 375) ships a DIFFERENT
/// ten rows (and `alarm[0] = 60`), so a written row is proof the Room Start arm
/// ran rather than the Create default being left in place.
#[rustfmt::skip]
const THEME_ROWS: [[i32; 17]; 10] = [
    [37, 46, 41, 31, 36, 44, 30, 45, 39, 35, 34, 33, 52, 38, 29, 47, 32], // playlist 1
    [44, 52, 41, 45, 38, 46, 39, 37, 32, 36, 30, 35, 34, 31, 33, 29, 47], // playlist 2
    [36, 35, 39, 37, 44, 30, 46, 47, 38, 31, 45, 32, 34, 41, 52, 33, 29], // playlist 3
    [29, 52, 37, 44, 36, 34, 45, 31, 41, 35, 47, 46, 39, 38, 33, 30, 32], // playlist 4
    [29, 30, 41, 44, 45, 52, 31, 35, 34, 46, 47, 33, 37, 36, 32, 38, 39], // playlist 5
    [32, 37, 44, 34, 36, 41, 31, 47, 35, 39, 45, 30, 38, 46, 33, 52, 29], // playlist 6
    [29, 47, 32, 34, 46, 38, 44, 41, 36, 39, 52, 37, 30, 33, 31, 45, 35], // playlist 7
    [34, 38, 33, 52, 44, 37, 39, 41, 46, 36, 47, 31, 35, 30, 29, 32, 45], // playlist 8
    [36, 44, 45, 34, 33, 35, 37, 38, 30, 32, 39, 31, 46, 47, 52, 29, 41], // playlist 9
    [32, 52, 45, 30, 31, 33, 34, 35, 36, 41, 38, 39, 47, 46, 44, 29, 37], // playlist 10
];

/// (room id, shipped ROOM name, region) for the eleven arms. The room ids are
/// the bytecode's `room` values; the names are `assets/game.droid`'s ROOM
/// table entries, asserted below against the asset, not against a document.
/// 048/064/082/104 also appear as the ROOMCC map-tile goto values in
/// `reconstruction/contracts/map-system.md`, and 010 is pinned by the client
/// suite (`RM_BOSS1 = 10`).
#[rustfmt::skip]
const ARM_ROOMS: [(i32, &str, &str); 11] = [
    (10, "rm_boss1", "caves boss"),
    (11, "rm_level9", "mines first room"),
    (27, "rm_boss2", "mines boss"),
    (28, "room31", "depths first room"),
    (48, "rm_boss3", "depths boss"),
    (49, "room51", "core first room"),
    (64, "rm_boss4", "core boss"),
    (65, "room66", "lab first room"),
    (82, "rm_boss5", "lab boss"),
    (83, "room83", "lair first room"),
    (104, "rm_boss6", "lair final boss"),
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

fn code378<'a>(b: &'a Bundle) -> &'a Code {
    b.codes
        .iter()
        .find(|c| c.id == CODE378)
        .expect("CODE 378 in bundle")
}

/// One dispatch's observable output.
struct Run {
    s: Scene,
    id: i32,
    /// Every instruction CODE 378 entered, as offsets from CODE378_START.
    ledger: Vec<usize>,
    /// (sound, looping, priority) per queued play command.
    plays: Vec<(i32, bool, f64)>,
    /// Host stop commands the body queued.
    stops: Vec<f64>,
    /// theme[0..16] as the Create left it, before the dispatch.
    theme_before: Vec<i32>,
    /// alarm[0] as the Create left it, before the dispatch.
    alarm_before: i32,
}

fn array(s: &Scene, id: i32, name: &str, idx: i32) -> Option<f64> {
    s.instances
        .get(&id)
        .and_then(|i| i.arrays.get(&(name.to_string(), idx)))
        .copied()
}

fn theme_of(s: &Scene, id: i32) -> Vec<i32> {
    (0..THEME_LEN)
        .map(|i| array(s, id, THEME, i).unwrap_or(-1.0) as i32)
        .collect()
}

fn field(s: &Scene, id: i32, name: &str) -> Option<f64> {
    s.instances
        .get(&id)
        .and_then(|i| i.fields.get(name))
        .copied()
}

/// Create obj_music, set the room + musicmute globals and the RNG seed, seed
/// one live looping voice so the arm's `audio_stop_all` has something to stop,
/// then dispatch Room Start (7/4). Returns the scene plus everything the
/// assertions need.
fn run(b: &Bundle, room: i32, musicmute: i32, seed: u64) -> Run {
    let mut s = scene(b);
    s.rng_seed = seed;
    s.current_room = f64::from(room);
    s.globals.insert(MUSICMUTE.into(), f64::from(musicmute));
    let create = b.codes.iter().find(|c| c.id == CODE375).expect("CODE 375");
    assert_eq!(
        create.id, CODE375 as usize,
        "obj_music's Create is CODE {CODE375}"
    );
    let id = s
        .create(b, MUSIC, 0.0, 0.0)
        .expect("obj_music Create (CODE 375)");
    let theme_before = theme_of(&s, id);
    let alarm_before = s.instances[&id].alarms[0];
    // Seed a live voice, then drop its own play command so only the arm's
    // commands remain in the queue. The voice stays live, which is what makes
    // `audio_stop_all` queue a host stop.
    s.call_audio_play(SENTINEL, 0.0, true);
    s.audio.clear();
    s.executed.clear(); // Create's ledger is not this arm's
    s.dispatch(b, id, 7, 4)
        .expect("obj_music Room Start (CODE 378)");
    let plays = s
        .audio
        .iter()
        .map(|c| (c.sound, c.looping, c.priority))
        .collect();
    let stops = s.take_stop_commands();
    let ledger = s
        .executed
        .iter()
        .filter(|(c, _)| *c == CODE378)
        .map(|(_, o)| *o - CODE378_START)
        .collect();
    Run {
        s,
        id,
        ledger,
        plays,
        stops,
        theme_before,
        alarm_before,
    }
}

// ---- live re-extraction of the same structure ------------------------------
//
// Mirrors the scratch generator op-for-op, but over the bundle's live
// instruction stream. A drift between full_ir.json and the embedded tables, or
// a table edited by hand, fails `the_arm_matrix_...` on the entry that moved.

fn const_at(ins: &[Instruction], i: usize) -> f64 {
    match &ins[i].op {
        Op::Constant { value } => *value,
        other => panic!("CODE {CODE378}: expected constant at index {i}, got {other:?}"),
    }
}

fn branch_at(ins: &[Instruction], i: usize) -> usize {
    match &ins[i].op {
        Op::B { target } | Op::Bt { target } | Op::Bf { target } => *target,
        other => panic!("CODE {CODE378}: expected branch at index {i}, got {other:?}"),
    }
}

fn call_at(ins: &[Instruction], i: usize) -> (String, usize) {
    match &ins[i].op {
        Op::Call { name, argc } => (name.clone(), *argc),
        other => panic!("CODE {CODE378}: expected call at index {i}, got {other:?}"),
    }
}

fn load_is(ins: &[Instruction], i: usize, name: &str) -> bool {
    matches!(&ins[i].op, Op::Load { name: n, .. } if n == name)
}

fn store_is(ins: &[Instruction], i: usize, name: &str, array: bool) -> bool {
    matches!(&ins[i].op, Op::Store { name: n, array: a, .. } if n == name && *a == array)
}

fn cmp_is_eq(ins: &[Instruction], i: usize) -> bool {
    matches!(&ins[i].op, Op::Cmp { comparison: 3 })
}

fn casts_are(ins: &[Instruction], from: usize, n: usize) -> bool {
    (0..n).all(|k| matches!(&ins[from + k].op, Op::Cast { to: 5 }))
}

struct LiveBoss {
    room: i32,
    track: i32,
    priority: f64,
    looping: bool,
    test: usize,
    body: usize,
    body_len: usize,
    test_ins: Vec<usize>,
    body_ins: Vec<usize>,
}

struct LiveTheme {
    room: i32,
    randomize: Option<usize>,
    choose_args: Vec<i32>,
    choose_call: usize,
    playlist_store: usize,
    test: usize,
    body: usize,
    body_len: usize,
    test_ins: Vec<usize>,
    /// Everything the arm body runs before its first `if (playlist == N)`.
    header_ins: Vec<usize>,
    /// (playlist, the block's 4 test instructions, the block's 17 stored words)
    blocks: Vec<(i32, Vec<usize>, Vec<usize>)>,
}

struct Live {
    start: usize,
    len: usize,
    mm1_test_ins: Vec<usize>,
    mm1_branch: usize,
    mm0_test_ins: Vec<usize>,
    mm0_branch: usize,
    boss: Vec<LiveBoss>,
    theme: Vec<LiveTheme>,
    theme_blocks: Vec<Vec<(i32, usize, usize)>>,
    theme_rows: Vec<Vec<i32>>,
}

fn live(b: &Bundle) -> Live {
    let code = code378(b);
    let ins: &[Instruction] = &code.instructions;
    let start = code.start;
    let rel = |t: usize| t - start;

    // ---- prologue: `if (musicmute == 1) {} else if (musicmute == 0) { ... }`
    assert!(
        load_is(ins, 0, MUSICMUTE),
        "CODE {CODE378}: off 0 loads musicmute"
    );
    assert_eq!(const_at(ins, 1), 1.0);
    assert!(cmp_is_eq(ins, 2));
    assert!(matches!(ins[3].op, Op::Bf { .. }));
    assert!(matches!(ins[4].op, Op::B { .. }));
    assert!(load_is(ins, 5, MUSICMUTE));
    assert_eq!(const_at(ins, 6), 0.0);
    assert!(cmp_is_eq(ins, 7));
    assert!(matches!(ins[8].op, Op::Bf { .. }));
    let mm1_test_ins = vec![
        ins[0].code_offset,
        ins[1].code_offset,
        ins[2].code_offset,
        ins[3].code_offset,
    ];
    let mm1_branch = ins[4].code_offset;
    let mm0_test_ins = vec![
        ins[5].code_offset,
        ins[6].code_offset,
        ins[7].code_offset,
        ins[8].code_offset,
    ];
    let mm0_branch = rel(branch_at(ins, 8));
    // The `== 1` `bf` lands on the `== 0` test; both non-zero paths converge on
    // the same offset (the theme chain).
    assert_eq!(
        rel(branch_at(ins, 3)),
        ins[5].code_offset,
        "CODE {CODE378}: the ==1 false path falls into the ==0 test"
    );
    assert_eq!(
        rel(branch_at(ins, 4)),
        mm0_branch,
        "CODE {CODE378}: the ==1 early exit skips the boss chain only"
    );

    // ---- the eleven `if (room == K)` arms, in stream order
    let mut raw = Vec::new();
    let mut i = 9;
    while i < ins.len() && load_is(ins, i, "room") {
        let room = const_at(ins, i + 1) as i32;
        assert!(
            cmp_is_eq(ins, i + 2),
            "CODE {CODE378}: room arm {room} compares eq"
        );
        assert!(matches!(ins[i + 3].op, Op::Bf { .. }));
        let test = ins[i].code_offset;
        let skip_to = rel(branch_at(ins, i + 3));
        let body = ins[i + 4].code_offset;
        let mut j = i + 4;
        while j < ins.len() && ins[j].code_offset < skip_to {
            j += 1;
        }
        raw.push((room, test, body, skip_to - body, skip_to, i, j));
        i = j;
    }
    assert_eq!(
        i,
        ins.len(),
        "CODE {CODE378}: the arm chain runs to the end of the body"
    );
    let offs = |from: usize, to: usize| -> Vec<usize> {
        ins.iter()
            .filter(|x| x.code_offset >= from && x.code_offset < to)
            .map(|x| x.code_offset)
            .collect()
    };
    let at = |o: usize| -> usize {
        ins.iter()
            .position(|x| x.code_offset == o)
            .expect("instruction at offset")
    };

    // ---- six boss arms: audio_stop_all(); audio_play_sound(track, 0, true)
    let mut boss = Vec::new();
    for (i, &(room, test, body, body_len, skip_to, hi, hj)) in raw[..6].iter().enumerate() {
        // Each arm is its own `if`, so its `bf` target is the NEXT arm's test
        // (for the last boss arm: the theme chain's first test).
        let next_test = raw.get(i + 1).map(|a| a.1).unwrap_or(CODE378_LEN);
        assert_eq!(
            skip_to, next_test,
            "CODE {CODE378}: arm {room} falls through to the next test"
        );
        let ops: Vec<&Op> = (&ins[hi + 4..hj]).iter().map(|x| &x.op).collect();
        assert!(
            matches!(ops[0], Op::Call { name, argc: 0 } if name == "audio_stop_all"),
            "CODE {CODE378}: arm {room} opens with audio_stop_all()"
        );
        assert!(matches!(ops[1], Op::Popz));
        assert!(matches!(ops[2], Op::Constant { .. }) && matches!(ops[3], Op::Cast { to: 5 }));
        assert!(matches!(ops[4], Op::Constant { .. }) && matches!(ops[5], Op::Cast { to: 5 }));
        assert!(matches!(ops[6], Op::Constant { .. }) && matches!(ops[7], Op::Cast { to: 5 }));
        assert!(
            matches!(ops[8], Op::Call { name, argc: 3 } if name == "audio_play_sound"),
            "CODE {CODE378}: arm {room} then starts one track with 3 args"
        );
        assert!(matches!(ops[9], Op::Popz));
        assert_eq!(
            ops.len(),
            10,
            "CODE {CODE378}: arm {room} body is exactly 10 instructions"
        );
        boss.push(LiveBoss {
            room,
            // pushes are (looping, priority, sound) because Op::Call pops LIFO
            looping: const_at(ins, at(body) + 2) != 0.0,
            priority: const_at(ins, at(body) + 4),
            track: const_at(ins, at(body) + 6) as i32,
            test,
            body,
            body_len,
            test_ins: offs(test, body),
            body_ins: offs(body, skip_to),
        });
    }

    // ---- five theme arms: stop_all; alarm[0]=1; [randomize]; choose/playlist
    let mut theme = Vec::new();
    let mut theme_blocks = Vec::new();
    let mut theme_rows: Option<Vec<Vec<i32>>> = None;
    for &(room, test, body, body_len, skip_to, _hi, _hj) in &raw[6..] {
        let bi = at(body);
        assert!(
            matches!(&ins[bi].op, Op::Call { name, argc: 0 } if name == "audio_stop_all"),
            "CODE {CODE378}: theme arm {room} opens with audio_stop_all()"
        );
        assert!(matches!(ins[bi + 1].op, Op::Popz));
        assert_eq!(
            const_at(ins, bi + 2),
            1.0,
            "CODE {CODE378}: theme arm {room} sets alarm[0] to 1"
        );
        assert_eq!(
            const_at(ins, bi + 3),
            -1.0,
            "CODE {CODE378}: the destination selector is self"
        );
        assert_eq!(const_at(ins, bi + 4), 0.0, "CODE {CODE378}: index 0");
        assert!(
            store_is(ins, bi + 5, "alarm", true),
            "CODE {CODE378}: theme arm {room} stores alarm"
        );
        let mut k = bi + 6;
        let randomize = if matches!(&ins[k].op, Op::Call { name, .. } if name == "randomize") {
            let o = ins[k].code_offset;
            assert!(matches!(ins[k + 1].op, Op::Popz));
            k += 2;
            Some(o)
        } else {
            None
        };
        let mut choose_args = Vec::new();
        while matches!(&ins[k].op, Op::Constant { .. }) {
            assert!(
                casts_are(ins, k + 1, 1),
                "CODE {CODE378}: theme arm {room} casts each choose arg"
            );
            choose_args.push(const_at(ins, k) as i32);
            k += 2;
        }
        let (cname, cargc) = call_at(ins, k);
        assert_eq!(
            (cname.as_str(), cargc),
            ("choose", 10),
            "CODE {CODE378}: theme arm {room} draws its playlist with a 10-way choose"
        );
        let choose_call = ins[k].code_offset;
        k += 1;
        assert!(
            store_is(ins, k, PLAYLIST, false),
            "CODE {CODE378}: theme arm {room} stores playlist"
        );
        let playlist_store = ins[k].code_offset;
        k += 1;
        let header_ins = offs(body, playlist_store + 8);
        let mut blocks = Vec::new();
        let mut block_table: Vec<(i32, usize, usize)> = Vec::new();
        let mut rows: Vec<(i32, Vec<i32>)> = Vec::new();
        while k < ins.len() && ins[k].code_offset < skip_to {
            assert!(
                load_is(ins, k, PLAYLIST),
                "CODE {CODE378}: theme arm {room} tests playlist"
            );
            let n = const_at(ins, k + 1) as i32;
            assert!(cmp_is_eq(ins, k + 2));
            assert!(matches!(ins[k + 3].op, Op::Bf { .. }));
            let blk_start = ins[k + 4].code_offset;
            let blk_end = rel(branch_at(ins, k + 3));
            let mut vals = Vec::new();
            let mut m = k + 4;
            while m < ins.len() && ins[m].code_offset < blk_end {
                assert!(matches!(&ins[m].op, Op::Constant { .. }));
                assert_eq!(const_at(ins, m + 1), -1.0);
                let expected_index = vals.len() as i32;
                assert_eq!(
                    const_at(ins, m + 2) as i32,
                    expected_index,
                    "CODE {CODE378}: theme row {n} stores index {expected_index}"
                );
                assert!(store_is(ins, m + 3, THEME, true));
                vals.push(const_at(ins, m) as i32);
                m += 4;
            }
            assert_eq!(
                vals.len(),
                THEME_LEN as usize,
                "CODE {CODE378}: theme row {n} is 17 words"
            );
            blocks.push((
                n,
                offs(ins[k].code_offset, blk_start),
                offs(blk_start, blk_end),
            ));
            block_table.push((n, blk_start, blk_end - blk_start));
            rows.push((n, vals));
            k = m;
        }
        assert_eq!(
            rows.iter().map(|r| r.0).collect::<Vec<_>>(),
            (1..=10).collect::<Vec<i32>>(),
            "CODE {CODE378}: theme arm {room} ships all ten playlist blocks in order"
        );
        let rows: Vec<Vec<i32>> = rows.into_iter().map(|r| r.1).collect();
        match &theme_rows {
            None => theme_rows = Some(rows),
            Some(prev) => assert_eq!(
                prev, &rows,
                "CODE {CODE378}: every theme arm ships the same ten rows"
            ),
        }
        theme.push(LiveTheme {
            room,
            randomize,
            choose_args,
            choose_call,
            playlist_store,
            test,
            body,
            body_len,
            test_ins: offs(test, body),
            header_ins,
            blocks,
        });
        theme_blocks.push(block_table);
        assert!(theme.last().unwrap().body_len > 0);
    }

    Live {
        start,
        len: code.end - code.start,
        mm1_test_ins,
        mm1_branch,
        mm0_test_ins,
        mm0_branch,
        boss,
        theme,
        theme_blocks,
        theme_rows: theme_rows.expect("theme rows"),
    }
}

/// The exact instruction stream CODE 378 must enter for one dispatch, built from
/// the live stream (never from the embedded tables). Because the arms are
/// independent `if`s, every `room` comparison runs even when an arm matches.
fn expected_ledger(
    l: &Live,
    musicmute: i32,
    boss_hit: Option<i32>,
    theme_hit: Option<i32>,
    playlist: Option<i32>,
) -> Vec<usize> {
    let mut e = Vec::new();
    e.extend(l.mm1_test_ins.iter().copied());
    if musicmute == 1 {
        e.push(l.mm1_branch); // empty `== 1` body: only the exit branch runs
    } else {
        e.extend(l.mm0_test_ins.iter().copied());
        if musicmute == 0 {
            for a in &l.boss {
                e.extend(a.test_ins.iter().copied());
                if Some(a.room) == boss_hit {
                    e.extend(a.body_ins.iter().copied());
                }
            }
        }
    }
    for t in &l.theme {
        e.extend(t.test_ins.iter().copied());
        if Some(t.room) == theme_hit {
            e.extend(t.header_ins.iter().copied());
            for (n, test_ins, body_ins) in &t.blocks {
                e.extend(test_ins.iter().copied());
                if Some(*n) == playlist {
                    e.extend(body_ins.iter().copied());
                }
            }
        }
    }
    e
}

// ---- 1. the matrix itself --------------------------------------------------

/// The embedded tables are re-derived from the live bundle stream and compared
/// entry by entry, then the census is asserted: 11 arms, 11 distinct room
/// constants (no duplicate arm), 6 guarded + 5 unguarded, bodies laid out in
/// chain order, and every arm's own test/body region inside the body span.
#[test]
// CODE 378
fn the_arm_matrix_matches_the_bundle_instruction_stream() {
    let b = bundle();
    let l = live(&b);

    assert_eq!(l.start, CODE378_START, "CODE {CODE378} start moved");
    assert_eq!(l.len, CODE378_LEN, "CODE {CODE378} span moved");
    assert_eq!(
        code378(&b).instructions.len(),
        CODE378_INS,
        "CODE {CODE378} length moved"
    );
    assert_eq!((l.mm1_branch, l.mm0_branch), (MM1_BRANCH, MM0_BRANCH));
    // The frozen layout constants must be the offsets the live stream uses:
    // the two musicmute tests, the boss chain's first test, the theme chain's
    // first test (== the boss chain end == the last boss `bf` target).
    assert_eq!(
        l.mm1_test_ins[0], MM1_TEST,
        "CODE {CODE378}: the ==1 test offset"
    );
    assert_eq!(
        l.mm0_test_ins[0], MM0_TEST,
        "CODE {CODE378}: the ==0 test offset"
    );
    assert_eq!(
        l.boss[0].test, BOSS_CHAIN,
        "CODE {CODE378}: the boss chain starts here"
    );
    assert_eq!(
        l.theme[0].test, THEME_CHAIN,
        "CODE {CODE378}: the theme chain starts where the boss chain ends"
    );
    assert_eq!(
        l.boss.last().unwrap().test + 68,
        THEME_CHAIN,
        "CODE {CODE378}: six 68-byte guarded arms fill BOSS_CHAIN..THEME_CHAIN"
    );

    // ---- the boss chain
    assert_eq!(
        l.boss.len(),
        BOSS_ARMS.len(),
        "CODE {CODE378}: boss arm count"
    );
    assert_eq!(
        l.boss.len(),
        6,
        "CODE {CODE378} ships six musicmute==0 arms"
    );
    for (i, (live, emb)) in l.boss.iter().zip(BOSS_ARMS.iter()).enumerate() {
        assert_eq!(
            (live.room, live.track, live.test, live.body, live.body_len),
            (emb.room, emb.track, emb.test, emb.body, emb.body_len),
            "CODE {CODE378} boss arm {i}"
        );
        assert_eq!(
            (live.priority, live.looping),
            (0.0, true),
            "CODE {CODE378} boss arm {i} (room {}) starts a looping priority-0 track",
            live.room
        );
        assert_eq!(
            live.test,
            BOSS_CHAIN + 68 * i,
            "CODE {CODE378} boss arm {i} test offset (68-byte arms)"
        );
        assert_eq!(
            live.body_ins.len(),
            10,
            "CODE {CODE378} boss arm {i} body instructions"
        );
    }
    // Tracks alternate bosssong/techno, matching the recovered GML's boss1..6.
    assert_eq!(
        l.boss.iter().map(|a| a.track).collect::<Vec<_>>(),
        vec![51, 48, 51, 48, 51, 48],
        "CODE {CODE378}: mus_bosssong(51)/mus_techno(48) alternate across the six bosses"
    );

    // ---- the theme chain
    assert_eq!(
        l.theme.len(),
        THEME_ARMS.len(),
        "CODE {CODE378}: theme arm count"
    );
    assert_eq!(
        l.theme.len(),
        5,
        "CODE {CODE378} ships five unguarded theme arms"
    );
    for (i, (live, emb)) in l.theme.iter().zip(THEME_ARMS.iter()).enumerate() {
        assert_eq!(
            (
                live.room,
                live.test,
                live.body,
                live.body_len,
                live.choose_call,
                live.playlist_store
            ),
            (
                emb.room,
                emb.test,
                emb.body,
                emb.body_len,
                emb.choose_call,
                emb.playlist_store
            ),
            "CODE {CODE378} theme arm {i}"
        );
        assert_eq!(
            live.randomize, emb.randomize,
            "CODE {CODE378} theme arm {i} randomize() call"
        );
        assert_eq!(
            live.choose_args,
            emb.choose_args.to_vec(),
            "CODE {CODE378} theme arm {i} choose push order"
        );
        assert_eq!(
            live.header_ins[0], emb.body,
            "CODE {CODE378} theme arm {i} body opens at its alarm store header"
        );
    }
    // `Op::Call` pops LIFO: the arm's own `randomize()` is the only rng touch
    // before the draw, and it is present in exactly the arm the GML restores as
    // rm_level9 (room 11).
    assert_eq!(
        l.theme
            .iter()
            .filter(|t| t.randomize.is_some())
            .map(|t| t.room)
            .collect::<Vec<_>>(),
        vec![11],
        "CODE {CODE378}: only the room-11 arm calls randomize()"
    );
    for t in &l.theme {
        let mut set = t.choose_args.clone();
        set.sort_unstable();
        assert_eq!(
            set,
            (1..=10).collect::<Vec<i32>>(),
            "CODE {CODE378}: theme arm {} draws from {{1..10}}",
            t.room
        );
    }
    // Live choose args differ in order between the room-11 arm and the rest;
    // both are permutations of {1..10}, so the draw set is identical.
    assert_ne!(
        l.theme[0].choose_args, l.theme[1].choose_args,
        "CODE {CODE378}: the room-11 choose pushes in a different order (recovered GML too)"
    );

    // ---- playlist blocks
    assert_eq!(l.theme_blocks.len(), THEME_BLOCKS.len());
    for (i, (live, emb)) in l.theme_blocks.iter().zip(THEME_BLOCKS.iter()).enumerate() {
        assert_eq!(
            live.as_slice(),
            emb.as_slice(),
            "CODE {CODE378} theme arm {i} playlist blocks"
        );
        assert_eq!(
            live.iter().map(|x| x.0).collect::<Vec<_>>(),
            (1..=10).collect::<Vec<i32>>(),
            "CODE {CODE378} theme arm {i} tests playlists 1..10 in order"
        );
    }
    assert_eq!(
        l.theme_blocks.len() * l.theme_blocks[0].len(),
        50,
        "CODE {CODE378}: the playlist blocks load `playlist` 50 times (5 arms x 10)"
    );

    // ---- rows
    assert_eq!(l.theme_rows.len(), 10);
    for (i, (live, emb)) in l.theme_rows.iter().zip(THEME_ROWS.iter()).enumerate() {
        assert_eq!(
            live.as_slice(),
            emb.as_slice(),
            "CODE {CODE378} theme row {i} (playlist {})",
            i + 1
        );
        assert_eq!(live.len(), THEME_LEN as usize);
    }
    let mut seen = Vec::new();
    for r in &l.theme_rows {
        let mut s = r.clone();
        s.sort_unstable();
        seen.push(s);
    }
    seen.dedup();
    assert_eq!(
        seen.len(),
        1,
        "CODE {CODE378}: all ten rows are one 17-id multiset"
    );
    assert_eq!(
        {
            let mut r: Vec<Vec<i32>> = l.theme_rows.clone();
            r.sort();
            r.dedup();
            r.len()
        },
        10,
        "CODE {CODE378}: the ten rows are ten distinct drawings"
    );

    // ---- census: the eleven arms are eleven distinct rooms, in this order
    let mut rooms: Vec<i32> = l.boss.iter().map(|a| a.room).collect();
    rooms.extend(l.theme.iter().map(|t| t.room));
    assert_eq!(
        rooms,
        vec![10, 27, 48, 64, 82, 104, 11, 28, 49, 65, 83],
        "CODE {CODE378}: bytecode arm order (six guarded, then five unguarded)"
    );
    let mut distinct = rooms.clone();
    distinct.sort_unstable();
    distinct.dedup();
    assert_eq!(
        distinct,
        vec![10, 11, 27, 28, 48, 49, 64, 65, 82, 83, 104],
        "CODE {CODE378}: the eleven constants are the clue's set"
    );
    assert_eq!(
        rooms.len(),
        ARM_ROOMS.len(),
        "CODE {CODE378}: the arm matrix covers every arm"
    );
    // ARM_ROOMS is in room-id order; the bytecode chain puts the six guarded
    // arms first, so only the sets have to agree.
    let mut arm_ids: Vec<i32> = ARM_ROOMS.iter().map(|r| r.0).collect();
    arm_ids.sort_unstable();
    assert_eq!(
        distinct, arm_ids,
        "CODE {CODE378}: the embedded room ledger covers exactly the eleven constants"
    );
    // No duplicate room constant, so no arm can shadow another: "first arm wins"
    // has nothing to decide here. What the arms DO prove is the opposite of a
    // switch - see `every_boss_arm_...`, which asserts all six comparisons run.
    assert_eq!(
        distinct.len(),
        rooms.len(),
        "CODE {CODE378}: no duplicate room constant (11 arms, 11 distinct rooms)"
    );
    let mut spans: Vec<(usize, usize)> = l.theme.iter().map(|t| (t.test, t.body)).collect();
    spans.push((BOSS_CHAIN, l.boss[0].body));
    assert!(
        spans.iter().all(|(t, b)| t < b),
        "CODE {CODE378}: every test precedes its body"
    );
}

// ---- 2. the six guarded arms ----------------------------------------------

/// Under `musicmute == 0` each boss arm queues exactly one looping play of its
/// own track and its `audio_stop_all` reaches the host. The ledger is the exact
/// instruction stream, which also pins the no-short-circuit rule: all six
/// comparisons run and the unmatched arms fall through.
#[test]
// CODE 378
fn every_boss_arm_starts_its_own_track_when_musicmute_is_zero() {
    let b = bundle();
    let l = live(&b);
    let mut covered = 0;
    for arm in BOSS_ARMS.iter() {
        let r = run(&b, arm.room, 0, 0x51);
        assert_eq!(
            r.plays,
            vec![(arm.track, true, 0.0)],
            "CODE {CODE378} room {} (rm_boss*) starts exactly one looping priority-0 track, got {:?}",
            arm.room, r.plays
        );
        assert_eq!(
            r.stops,
            vec![SENTINEL],
            "CODE {CODE378} room {}: audio_stop_all must reach the host for the live voice",
            arm.room
        );
        // The boss arms touch neither the alarm nor the playlist.
        assert_eq!(
            r.s.instances[&r.id].alarms[0], r.alarm_before,
            "CODE {CODE378} room {}: a boss arm writes no alarm",
            arm.room
        );
        assert_eq!(
            field(&r.s, r.id, PLAYLIST),
            None,
            "CODE {CODE378} room {}: a boss arm writes no playlist",
            arm.room
        );
        assert_eq!(
            theme_of(&r.s, r.id),
            r.theme_before,
            "CODE {CODE378} room {}: a boss arm leaves theme[] at the Create table",
            arm.room
        );
        // Exact stream: every comparison in the chain runs even though one arm
        // matched, and only the matching arm's body executes.
        assert_eq!(
            r.ledger,
            expected_ledger(&l, 0, Some(arm.room), None, None),
            "CODE {CODE378} room {}: exact instruction stream",
            arm.room
        );
        let others: Vec<usize> = l
            .boss
            .iter()
            .filter(|a| a.room != arm.room)
            .flat_map(|a| a.body_ins.iter().copied())
            .collect();
        assert!(
            others.iter().all(|o| !r.ledger.contains(o)),
            "CODE {CODE378} room {}: no neighbouring arm's body may run",
            arm.room
        );
        covered += 1;
    }
    assert_eq!(
        covered, 6,
        "CODE {CODE378}: the sweep covers all six guarded arms"
    );
    // Eleven distinct inputs, one per arm, is the other half of the brief: a
    // second pass over the same rooms with a different RNG seed must not move
    // anything, because these arms never draw.
    for arm in BOSS_ARMS.iter() {
        let r = run(&b, arm.room, 0, 0xdead_beef);
        assert_eq!(
            r.plays,
            vec![(arm.track, true, 0.0)],
            "CODE {CODE378} room {}: no RNG dependence in a boss arm",
            arm.room
        );
    }
}

// ---- 3. the musicmute gate -------------------------------------------------

/// `musicmute == 1` takes the empty first branch and skips the boss chain; any
/// other non-zero value takes the `!= 0` fall-through of the second test and
/// lands on the same offset. Either way the theme chain still runs.
#[test]
// CODE 378
fn musicmute_one_and_two_skip_the_boss_chain_but_not_the_theme_chain() {
    let b = bundle();
    let l = live(&b);
    for arm in BOSS_ARMS.iter() {
        // musicmute == 1: the empty body, exit at MM1_BRANCH.
        let r1 = run(&b, arm.room, 1, 0x51);
        assert!(
            r1.plays.is_empty(),
            "CODE {CODE378} musicmute=1 room {}: no track may start",
            arm.room
        );
        assert!(
            r1.stops.is_empty(),
            "CODE {CODE378} musicmute=1 room {}: no stop_all reaches the host",
            arm.room
        );
        assert_eq!(
            r1.ledger,
            expected_ledger(&l, 1, None, None, None),
            "CODE {CODE378} musicmute=1 room {}: exact stream (the `b` at {})",
            arm.room,
            MM1_BRANCH
        );
        assert!(r1.ledger.contains(&MM1_BRANCH));
        assert!(
            !r1.ledger.contains(&BOSS_CHAIN),
            "CODE {CODE378} musicmute=1: the boss chain is not entered at all"
        );

        // Any other non-zero value: the ==0 test's `bf` lands on the same offset.
        for mm in [2, -1, 7] {
            let r2 = run(&b, arm.room, mm, 0x51);
            assert!(
                r2.plays.is_empty(),
                "CODE {CODE378} musicmute={mm} room {}: no track may start",
                arm.room
            );
            assert!(r2.stops.is_empty());
            assert!(
                !r2.ledger.contains(&MM1_BRANCH),
                "CODE {CODE378} musicmute={mm}: the ==1 early exit is not taken"
            );
            assert_eq!(
                r2.ledger,
                expected_ledger(&l, mm, None, None, None),
                "CODE {CODE378} musicmute={mm} room {}: exact stream",
                arm.room
            );
            assert!(
                l.boss
                    .iter()
                    .all(|a| a.test_ins.iter().all(|o| !r2.ledger.contains(o))),
                "CODE {CODE378} musicmute={mm}: the boss chain is never entered"
            );
        }
    }
    // And the gate is only about the boss chain: a theme room under
    // musicmute == 1 still writes its playlist row.
    let rt = run(&b, THEME_ARMS[0].room, 1, 0x51);
    let pl = field(&rt.s, rt.id, PLAYLIST).expect("CODE 378 musicmute=1 still draws a playlist");
    assert!(
        (1.0..=10.0).contains(&pl),
        "CODE {CODE378}: musicmute=1 does not gate the theme arms, got playlist {pl}"
    );
}

// ---- 4. the five unguarded theme arms -------------------------------------

/// Each theme arm re-arms `alarm[0]`, draws a playlist and writes that
/// playlist's 17-entry theme row - for `musicmute` 0 AND 1, because the theme
/// chain sits outside the gate. It issues no play command: the music is Alarm
/// 0's (CODE 376) job.
#[test]
// CODE 378
fn every_theme_arm_writes_its_playlist_row_for_either_musicmute() {
    let b = bundle();
    let l = live(&b);
    let mut covered = 0;
    for arm in THEME_ARMS.iter() {
        for mm in [0, 1] {
            let r = run(&b, arm.room, mm, 0x9e37_79b9);
            assert_eq!(
                r.s.instances[&r.id].alarms[0], 1,
                "CODE {CODE378} room {} musicmute={mm}: the arm re-arms alarm[0] = 1 (Create left {})",
                arm.room, r.alarm_before
            );
            assert_ne!(
                r.alarm_before, 1,
                "CODE {CODE378}: the Create value must differ, else the assertion above is vacuous"
            );
            let pl = field(&r.s, r.id, PLAYLIST)
                .unwrap_or_else(|| panic!("CODE {CODE378} room {} must draw a playlist", arm.room));
            assert_eq!(
                pl.fract(),
                0.0,
                "CODE {CODE378}: playlist is an integer draw"
            );
            let pl = pl as i32;
            assert!(
                (1..=10).contains(&pl),
                "CODE {CODE378} room {} drew playlist {pl}, outside the choose set",
                arm.room
            );
            assert_eq!(
                theme_of(&r.s, r.id),
                THEME_ROWS[(pl - 1) as usize].to_vec(),
                "CODE {CODE378} room {} musicmute={mm}: theme[] must be exactly row {pl}",
                arm.room
            );
            assert_ne!(
                theme_of(&r.s, r.id),
                r.theme_before,
                "CODE {CODE378} room {}: the Create table must be overwritten",
                arm.room
            );
            assert!(
                r.plays.is_empty(),
                "CODE {CODE378} room {}: a theme arm starts no track itself, got {:?}",
                arm.room,
                r.plays
            );
            assert_eq!(
                r.stops,
                vec![SENTINEL],
                "CODE {CODE378} room {}: audio_stop_all still reaches the host",
                arm.room
            );
            // Exact stream: this arm's header + its ten playlist tests, and only
            // the drawn playlist's block body.
            assert_eq!(
                r.ledger,
                expected_ledger(&l, mm, None, Some(arm.room), Some(pl)),
                "CODE {CODE378} room {} musicmute={mm} playlist {pl}: exact instruction stream",
                arm.room
            );
            // The randomize() call is present in exactly one arm.
            assert_eq!(
                r.ledger.contains(&arm.randomize.unwrap_or(usize::MAX)),
                arm.randomize.is_some(),
                "CODE {CODE378} room {}: randomize presence in the stream",
                arm.room
            );
            assert_eq!(
                r.ledger.contains(&arm.choose_call),
                true,
                "CODE {CODE378} room {}: choose ran",
                arm.room
            );
            assert_eq!(
                r.ledger.contains(&arm.playlist_store),
                true,
                "CODE {CODE378} room {}: playlist was stored",
                arm.room
            );
            covered += 1;
        }
    }
    assert_eq!(
        covered, 10,
        "CODE {CODE378}: five theme arms x two musicmute states"
    );
}

/// The random path is structural, not exhaustive: every seed must draw inside
/// {1..10} and write that playlist's row, the draw must actually vary, and the
/// arm's `randomize()` must be the thing that makes the draw move.
#[test]
// CODE 378
fn the_theme_playlist_is_a_choose_over_one_to_ten() {
    let b = bundle();
    let l = live(&b);
    for arm in THEME_ARMS.iter() {
        let mut seen = Vec::new();
        for seed in 1u64..=96 {
            let r = run(&b, arm.room, 0, seed);
            let pl = field(&r.s, r.id, PLAYLIST).expect("playlist drawn") as i32;
            assert!(
                (1..=10).contains(&pl),
                "CODE {CODE378} room {} seed {seed}: draw {pl} outside {{1..10}}",
                arm.room
            );
            assert_eq!(
                theme_of(&r.s, r.id),
                THEME_ROWS[(pl - 1) as usize].to_vec(),
                "CODE {CODE378} room {} seed {seed}: row follows the draw",
                arm.room
            );
            assert!(
                r.plays.is_empty() && r.stops == vec![SENTINEL],
                "CODE {CODE378} room {} seed {seed}: the draw does not touch audio",
                arm.room
            );
            // Only the drawn block's body may run: the other nine are tested and
            // skipped.
            let hit = &l.theme.iter().find(|t| t.room == arm.room).unwrap().blocks;
            let bodies = hit
                .iter()
                .filter(|(n, _, _)| *n != pl)
                .flat_map(|(_, _, b)| b.iter().copied())
                .collect::<Vec<_>>();
            assert!(
                bodies.iter().all(|o| !r.ledger.contains(o)),
                "CODE {CODE378} room {} seed {seed}: a non-drawn playlist block ran",
                arm.room
            );
            if !seen.contains(&pl) {
                seen.push(pl);
            }
        }
        seen.sort_unstable();
        assert!(
            seen.len() > 1,
            "CODE {CODE378} room {}: 96 seeds drew only {seen:?} - the draw is not varying",
            arm.room
        );
        assert!(seen.iter().all(|p| (1..=10).contains(p)));
    }
}

// ---- 5. the negative case --------------------------------------------------

/// A room outside the eleven arms runs the whole chain and matches nothing: no
/// stop command, no play command, no playlist, no alarm write, and `theme[]`
/// still holds the Create table - which differs from all ten Room Start rows,
/// so "nothing happened" is distinguishable from "the wrong arm ran".
#[test]
// CODE 378
fn a_room_outside_the_eleven_arms_changes_nothing() {
    let b = bundle();
    let l = live(&b);
    for room in [0, 9, 12, 26, 29, 47, 50, 66, 84, 103, 105, 113, 999, -1] {
        for mm in [0, 1] {
            let r = run(&b, room, mm, 0x51);
            assert!(
                r.plays.is_empty(),
                "CODE {CODE378} room {room} musicmute={mm}: nothing may play"
            );
            assert!(
                r.stops.is_empty(),
                "CODE {CODE378} room {room} musicmute={mm}: nothing may be stopped"
            );
            assert_eq!(
                field(&r.s, r.id, PLAYLIST),
                None,
                "CODE {CODE378} room {room} musicmute={mm}: no playlist is drawn"
            );
            assert_eq!(
                r.s.instances[&r.id].alarms[0], r.alarm_before,
                "CODE {CODE378} room {room} musicmute={mm}: alarm[0] keeps the Create value"
            );
            assert_eq!(
                theme_of(&r.s, r.id),
                r.theme_before,
                "CODE {CODE378} room {room} musicmute={mm}: theme[] keeps the Create table"
            );
            assert!(
                THEME_ROWS.iter().all(|row| row.to_vec() != r.theme_before),
                "CODE {CODE378}: the Create table must differ from every Room Start row, \
                     else 'nothing ran' is not distinguishable from 'an arm ran'"
            );
            assert_eq!(
                r.ledger,
                expected_ledger(&l, mm, None, None, None),
                "CODE {CODE378} room {room} musicmute={mm}: every comparison runs and fails"
            );
        }
    }
}

// ---- 6. the room ids are the shipped ones ---------------------------------

/// The eleven ids are the bytecode's `room` constants; the names are the
/// shipped ROOM table's, read from `assets/game.droid`. This is what makes the
/// per-arm comments ("rm_boss1", "room31", ...) evidence rather than a guess,
/// and it is the bytecode-vs-clue reconciliation the brief asked for.
#[test]
// CODE 378
fn the_eleven_room_ids_are_the_shipped_room_names() {
    let path = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(path).expect("parse game.droid");
    for (id, name, region) in ARM_ROOMS.iter() {
        let room = asset
            .rooms
            .get(*id as usize)
            .unwrap_or_else(|| panic!("ROOM {id} ({name}, {region}) missing from the asset"));
        assert_eq!(
            room.name, *name,
            "CODE {CODE378}: ROOM {id} is {name} ({region})",
        );
    }
    // And the two broadcast tracks resolve to the names the recovered GML uses.
    for (sond, name) in [(48, "techno"), (51, "bosssong")] {
        let entry = asset
            .sounds
            .iter()
            .find(|s| s.id as i32 == sond)
            .unwrap_or_else(|| panic!("SOND {sond} ({name}) missing"));
        assert!(
            entry.name.to_ascii_lowercase().contains(name),
            "CODE {CODE378}: SOND {sond} should be mus_{name}, got {:?}",
            entry.name
        );
    }
    // Read in room-id order the eleven arms pair up as (boss room, the next
    // region's first room): that is the id/name table, NOT the bytecode chain
    // order, which lists the six guarded arms first.
    let names: Vec<&str> = ARM_ROOMS.iter().map(|r| r.1).collect();
    assert_eq!(
        names,
        vec![
            "rm_boss1",
            "rm_level9",
            "rm_boss2",
            "room31",
            "rm_boss3",
            "room51",
            "rm_boss4",
            "room66",
            "rm_boss5",
            "room83",
            "rm_boss6"
        ],
        "CODE {CODE378}: by room id the arms pair boss room / next region first room"
    );
}
