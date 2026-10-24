//! Complete HUD matrix for CODE 370 `gml_Object_obj_UI_Draw_0` (obj_UI, Draw).
//!
//! The body is a *flat table*, not an arbitrary FSM: every comparison in it
//! keys off one of three globals/environment reads and nothing else —
//!
//!   * `view_current` (environment read, selector -1): 30 equality guards, five
//!     groups of the same six views in source order
//!       - 6 UI blocks      (`if (view_current == K)`, K in {0,1,3,4,5,6}),
//!       - 6 score blocks   (same six views),
//!       - 6 XP-bar blocks under `if (global.level < 20)`,
//!       - 6 XP-bar blocks under `else if (global.level >= 20)`,
//!       - 6 health blocks  (each holding the 22 health1 guard arms below).
//!     View 2 is never compared: there is no `view_current == 2` guard anywhere
//!     in the body, so view 2 (and every out-of-table view) draws no HUD at all.
//!   * `global.level` (selector -5): 14 guards — a `< 10` / `>= 10` pair inside
//!     every UI block (level text x offset), and one `< 20` / `>= 20` pair on
//!     the XP bar (computed percentage vs. a pinned 100).
//!   * `global.health1` (selector -5): 132 guards = 6 views x 22 values
//!     (2..=23), one independent `if` per value — *not* a switch: all 22
//!     comparisons of the entered block run on every pass, only the matching
//!     arm's body draws.
//!
//! Every count in this file was read off the authoritative bytecode
//! (`crates/core/src/generated/full_ir.json`, `codes[].id == 370`, start
//! 4228800, end 4445192, 41164 instructions) by an independent walker
//! (`~/.hermes/cache/scratch/wl58-hud_walk.py` + `wl58-hud_rustgen.py`, scratch
//! only, not part of the tree). The recovered GML
//! (`0370__gml_Object_obj_UI_Draw_0.gml`) was used for navigation only; the
//! constants, offsets and branch ownership below are the IR's.
//!
//! What this suite pins (and how):
//!   * the *complete* emitted output — every sprite draw (sprite id, frame,
//!     x, y, both scales, rotation, blend, alpha), every text (x, y, string,
//!     font, colour) and every healthbar (x1,y1,x2,y2, amount, three colours) —
//!     for the whole enumerable `view x level x health1` cross product, not one
//!     command per cell. Expected tables are independent of the producing VM:
//!     they are bytecode-derived data (see the `VIEW_SPECS` / `SMALL_*` /
//!     `BIG_*` / `BOSS_GATES` comments), and the test cross-reads the *live*
//!     instruction stream for the branch census, the guard spans and the
//!     per-guard ledger below.
//!   * per-guard positive AND negative cases through the engine's own
//!     instruction ledger (`Scene::executed`, one entry per VM instruction):
//!     for every one of the body's 176 comparisons the test asserts whether
//!     its `cmp` and its arm body ran, so a guard that fires for the wrong
//!     input (or a neighbouring arm's body) fails even when the emitted queue
//!     happens to look plausible.
//!   * a non-zero camera per view, and an explicit translation test: the HUD is
//!     drawn in camera space (CODE 370 stores `obj_UI.x = view_xview[view_current]`
//!     first), so every coordinate must move exactly with the view origin.
//!   * the boss gates (trex / boss2 / boss3 / boss4 / boss5 / finalboss): each
//!     is `if (instance_exists(obj_X))`, independent of view, level, health1 and
//!     of the player, with its own `(hp field, max hp field, rect)` row; boss5's
//!     shipped rect has x2 < x1 (a right-to-left bar) and stays that way.
//!   * the semantic exceptions the bytecode really has, instead of the
//!     handbooks' intuition: health1 outside 2..=23 (including 0, 1, 24 and any
//!     fractional value) draws no segments but still walks all 22 comparisons;
//!     a boss whose `maxhp` is 0 and an XP bar with `xptolevelup == 0` abort the
//!     whole Draw with a division-by-zero error (the earlier commands stay in
//!     the queue because the host records as it goes).
//!   * a reusable validator (`check`) whose negative control perturbs a *copy of
//!     the fixture bundle* — an arm's draw constant, a view guard's constant, a
//!     health guard's jump target and the XP threshold — and requires the same
//!     validator used by the matrix to reject every one of them. Two
//!     self-consistent derivations of the same algorithm could not do that.
//!
//! Not verified here: rasterisation, pixels, viewport scaling or the original
//! runner. This is re-written-end IR regression semantics — the Draw body's
//! command production, the branch table and its ledger — with no GPU, no
//! window and no device involved.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use callys_core::ir_scene::{DrawCommand, HealthbarCommand, Scene, TextCommand};
use std::path::Path;

/// CODE 370, obj_UI Draw (event type 8, subtype 0).
const CODE: usize = 370;
/// obj_UI (the emitted commands' owner; also the selector of its x/y stores).
const UI_OBJ: i32 = 66;
/// obj_player: only its existence is read (`instance_exists(obj_player)`).
const PLAYER_OBJ: i32 = 0;
/// Score the UI prints verbatim (`draw_text(..., score)`).
const SCORE: f64 = 1370.0;
/// c_white, the only colour any `draw_set_color` in this body sets.
const WHITE: i32 = 16777215;
/// obj_UI is staged here; a Draw that used the instance position instead of the
/// camera would land visibly away from every expected coordinate.
const STAGED_AT: (f64, f64) = (-7.0, -9.0);

/// Deterministic non-zero camera per view: the HUD is drawn relative to the
/// view origin, so a zero camera would hide projection mistakes.
fn cam(view: i32) -> (f64, f64) {
    (1000.0 + 37.0 * view as f64, 500.0 + 11.0 * view as f64)
}

// ---------------------------------------------------------------------------
// bytecode-derived tables (generated from full_ir.json, never hand-typed)
// ---------------------------------------------------------------------------

struct ViewSpec {
    view: i32,
    /// `y` offset of the UI back sprite (`spr_UI`) from the view origin.
    ui_dy: f64,
    /// Both scales of that sprite (0.7 only in view 1).
    ui_scale: f64,
    /// Font id the level text is drawn with (`draw_set_font`).
    level_font: i32,
    /// Level text x offsets: `global.level < 10` and `>= 10` respectively.
    level_dx_lt10: f64,
    level_dx_ge10: f64,
    level_dy: f64,
    /// Score text offset (font 3 in every block).
    score_dx: f64,
    score_dy: f64,
    /// XP bar rect relative to the view origin.
    bar: (f64, f64, f64, f64),
}

/// (view, ui_dy, ui_scale, level_font, level_dx_lt10, level_dx_ge10, level_dy,
///  score_dx, score_dy, (bar_x1, bar_y1, bar_x2, bar_y2))
#[rustfmt::skip]
const VIEW_SPECS: [ViewSpec; 6] = [
    ViewSpec { view: 0, ui_dy: 1.0, ui_scale: 1.0, level_font: 0,
        level_dx_lt10: 10.0, level_dx_ge10: 2.0, level_dy: 8.0,
        score_dx: 170.0, score_dy: 1.0, bar: (46.0, 4.0, 140.0, 11.0) },
    ViewSpec { view: 1, ui_dy: 0.0, ui_scale: 0.7, level_font: 2,
        level_dx_lt10: 10.0, level_dx_ge10: 2.0, level_dy: 8.0,
        score_dx: 116.0, score_dy: -2.0, bar: (32.0, 3.0, 100.0, 6.0) },
    ViewSpec { view: 3, ui_dy: 0.0, ui_scale: 1.0, level_font: 0,
        level_dx_lt10: 10.0, level_dx_ge10: 2.0, level_dy: 8.0,
        score_dx: 165.0, score_dy: 1.0, bar: (50.0, 5.0, 136.0, 9.0) },
    ViewSpec { view: 4, ui_dy: 0.0, ui_scale: 1.0, level_font: 0,
        level_dx_lt10: 10.0, level_dx_ge10: 2.0, level_dy: 8.0,
        score_dx: 165.0, score_dy: 1.0, bar: (50.0, 5.0, 136.0, 9.0) },
    ViewSpec { view: 5, ui_dy: 1.0, ui_scale: 1.0, level_font: 0,
        level_dx_lt10: 10.0, level_dx_ge10: 2.0, level_dy: 8.0,
        score_dx: 170.0, score_dy: 1.0, bar: (46.0, 4.0, 140.0, 11.0) },
    ViewSpec { view: 6, ui_dy: 1.0, ui_scale: 1.0, level_font: 0,
        level_dx_lt10: 10.0, level_dx_ge10: 2.0, level_dy: 8.0,
        score_dx: 170.0, score_dy: 1.0, bar: (46.0, 4.0, 140.0, 11.0) },
];

/// `spr_UI` (all views) and `spr_health` (all segments) as the bytecode passes
/// them; the UI sprite is a `draw_sprite_ext`, the segments `draw_sprite` for
/// health1 2..=11 and `draw_sprite_ext` with scale 0.5 for 12..=23.
const UI_SPRITE: f64 = 84.0;
const UI_FRAME: f64 = 0.0;
const UI_ROT: f64 = 0.0;
const UI_COLOR: i32 = -1;
const UI_ALPHA: f64 = 1.0;
const HEALTH_SPRITE: f64 = 86.0;
const HEALTH_FRAME: f64 = 1.0;
const HEALTH_ROT: f64 = 0.0;
const HEALTH_COLOR: i32 = -1;
const HEALTH_ALPHA: f64 = 1.0;

/// XP bar colours: c_gray / c_green / c_yellow.
const XP_BACK: i32 = 8421504;
const XP_MIN: i32 = 32768;
const XP_MAX: i32 = 65535;
/// Boss bar colours: c_black / c_red / c_green.
const BOSS_BACK: i32 = 0;
const BOSS_MIN: i32 = 255;
const BOSS_MAX: i32 = 32768;

/// view 0 (and, byte-identically, views 3/4/5/6): the ten full-scale arms for
/// health1 2..=11. Row for health1=h is the first `SMALL_COUNT_A[h-2]` entries.
#[rustfmt::skip]
const SMALL_A: [(f64, f64, f64); 10] = [
    (58.0, 30.0, 1.0), // 1
    (73.0, 30.0, 1.0), // 2
    (88.0, 30.0, 1.0), // 3
    (103.0, 30.0, 1.0), // 4
    (118.0, 30.0, 1.0), // 5
    (133.0, 30.0, 1.0), // 6
    (148.0, 30.0, 1.0), // 7
    (163.0, 30.0, 1.0), // 8
    (178.0, 30.0, 1.0), // 9
    (193.0, 30.0, 1.0), // 10
];
/// view 0: the twelve half-scale arms (health1 12..=23). Row for health1=h is
/// the first `BIG_COUNT_A[h-12]` entries; the tail spills onto a third x (138).
#[rustfmt::skip]
const BIG_A: [(f64, f64, f64); 22] = [
    (58.0, 20.0, 0.5), // 1
    (66.0, 20.0, 0.5), // 2
    (74.0, 20.0, 0.5), // 3
    (82.0, 20.0, 0.5), // 4
    (90.0, 20.0, 0.5), // 5
    (98.0, 20.0, 0.5), // 6
    (106.0, 20.0, 0.5), // 7
    (114.0, 20.0, 0.5), // 8
    (122.0, 20.0, 0.5), // 9
    (130.0, 20.0, 0.5), // 10
    (58.0, 30.0, 0.5), // 11
    (66.0, 30.0, 0.5), // 12
    (74.0, 30.0, 0.5), // 13
    (82.0, 30.0, 0.5), // 14
    (90.0, 30.0, 0.5), // 15
    (98.0, 30.0, 0.5), // 16
    (106.0, 30.0, 0.5), // 17
    (114.0, 30.0, 0.5), // 18
    (122.0, 30.0, 0.5), // 19
    (130.0, 30.0, 0.5), // 20
    (138.0, 20.0, 0.5), // 21
    (138.0, 30.0, 0.5), // 22
];
#[rustfmt::skip]
const SMALL_COUNT_A: [usize; 10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
#[rustfmt::skip]
const BIG_COUNT_A: [usize; 12] = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22];

/// view 1: same structure, its own base x / row y (40 / 20) and a tighter half
/// scale step (8 instead of 8 at x, but rows at 15/25).
#[rustfmt::skip]
const SMALL_B: [(f64, f64, f64); 10] = [
    (40.0, 20.0, 1.0), // 1
    (55.0, 20.0, 1.0), // 2
    (70.0, 20.0, 1.0), // 3
    (85.0, 20.0, 1.0), // 4
    (100.0, 20.0, 1.0), // 5
    (115.0, 20.0, 1.0), // 6
    (130.0, 20.0, 1.0), // 7
    (145.0, 20.0, 1.0), // 8
    (160.0, 20.0, 1.0), // 9
    (175.0, 20.0, 1.0), // 10
];
#[rustfmt::skip]
const BIG_B: [(f64, f64, f64); 22] = [
    (40.0, 15.0, 0.5), // 1
    (48.0, 15.0, 0.5), // 2
    (56.0, 15.0, 0.5), // 3
    (64.0, 15.0, 0.5), // 4
    (72.0, 15.0, 0.5), // 5
    (80.0, 15.0, 0.5), // 6
    (88.0, 15.0, 0.5), // 7
    (96.0, 15.0, 0.5), // 8
    (104.0, 15.0, 0.5), // 9
    (112.0, 15.0, 0.5), // 10
    (40.0, 25.0, 0.5), // 11
    (48.0, 25.0, 0.5), // 12
    (56.0, 25.0, 0.5), // 13
    (64.0, 25.0, 0.5), // 14
    (72.0, 25.0, 0.5), // 15
    (80.0, 25.0, 0.5), // 16
    (88.0, 25.0, 0.5), // 17
    (96.0, 25.0, 0.5), // 18
    (104.0, 25.0, 0.5), // 19
    (112.0, 25.0, 0.5), // 20
    (120.0, 15.0, 0.5), // 21
    (120.0, 25.0, 0.5), // 22
];
#[rustfmt::skip]
const SMALL_COUNT_B: [usize; 10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
#[rustfmt::skip]
const BIG_COUNT_B: [usize; 12] = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22];

/// (object id, hp field, max hp field, x1 dx, y1 dy, x2 dx, y2 dy). One
/// `instance_exists` gate per row, in this order, independent of everything
/// else the Draw reads.
const BOSS_GATES: [(i32, &str, &str, f64, f64, f64, f64); 6] = [
    (25, "hptrex", "boss1maxhp", 0.0, -70.0, 20.0, -60.0),
    (26, "hpboss2", "boss2maxhp", 0.0, -60.0, 20.0, -50.0),
    (27, "hpboss3", "boss3maxhp", -20.0, -50.0, 0.0, -40.0),
    (28, "hpboss4", "boss4maxhp", 10.0, -80.0, 30.0, -70.0),
    (29, "hpboss5", "boss5maxhp", 0.0, -70.0, -20.0, -60.0),
    (30, "hpfinalboss", "finalbossmaxhp", -10.0, -70.0, 10.0, -60.0),
];

// ---------------------------------------------------------------------------
// fixture
// ---------------------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn ui_body(b: &Bundle) -> &[Instruction] {
    &b.codes.iter().find(|c| c.id == CODE).expect("CODE 370").instructions
}

/// GMS `string(x)` as the host renders a plain number: integers without a
/// decimal point, anything else with two decimals. Pinned here only so the
/// expected text of a fractional level is written down explicitly.
fn text_of(v: f64) -> String {
    if v.fract() == 0.0 && v.abs() < 9.0e15 {
        format!("{}", v as i64)
    } else {
        format!("{v:.2}")
    }
}

#[derive(Clone, Debug)]
struct Boss {
    object: i32,
    x: f64,
    y: f64,
    hp: f64,
    maxhp: f64,
}

#[derive(Clone, Debug)]
struct Case {
    view: i32,
    level: f64,
    health1: f64,
    player: bool,
    bosses: Vec<Boss>,
    cam: (f64, f64),
    exp: f64,
    xpneed: f64,
}

impl Case {
    fn new(view: i32, level: f64, health1: f64) -> Self {
        Case {
            view,
            level,
            health1,
            player: true,
            bosses: Vec::new(),
            cam: cam(view),
            exp: 30.0,
            xpneed: 120.0,
        }
    }

    fn boss(mut self, object: i32, x: f64, y: f64, hp: f64, maxhp: f64) -> Self {
        self.bosses.push(Boss { object, x, y, hp, maxhp });
        self
    }

    fn no_player(mut self) -> Self {
        self.player = false;
        self
    }

    fn label(&self) -> String {
        format!(
            "CODE {CODE} view {} level {} health1 {} player {} bosses {:?}",
            self.view,
            self.level,
            self.health1,
            self.player,
            self.bosses.iter().map(|b| b.object).collect::<Vec<_>>()
        )
    }
}

/// Stages obj_UI with the engine's named defaults plus the interesting globals.
///
/// obj_UI's Create (CODE 365) is deliberately NOT run: it spawns seven sound
/// emitters and consumes the rng (`choose`/`randomize`/`irandom_range`), none of
/// which belongs to the Draw pass under test. The Draw body itself is the
/// shipped CODE 370, executed by the ordinary VM through `draw_view`.
fn stage(b: &Bundle, c: &Case) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.globals.insert("level".into(), c.level);
    s.globals.insert("health1".into(), c.health1);
    s.globals.insert("experience".into(), c.exp);
    s.globals.insert("xptolevelup".into(), c.xpneed);
    s.score = SCORE;

    let id = s.insert_external(UI_OBJ);
    {
        let shipped_sprite = b
            .objects
            .iter()
            .find(|o| o.id == UI_OBJ)
            .expect("obj_UI in the object table")
            .sprite as f64;
        let inst = s.instances.get_mut(&id).expect("staged obj_UI");
        inst.external = false;
        for (n, v) in [
            ("id", id as f64),
            ("x", STAGED_AT.0),
            ("y", STAGED_AT.1),
            ("sprite_index", shipped_sprite),
            ("image_index", 0.0),
            ("image_xscale", 1.0),
            ("image_yscale", 1.0),
            ("image_angle", 0.0),
            ("image_blend", WHITE as f64),
            ("image_alpha", 1.0),
            ("visible", 1.0),
        ] {
            inst.fields.insert(n.into(), v);
        }
    }

    // obj_player and the bosses are only read through `instance_exists` and
    // `obj_X.field`, never drawn by this pass: they stay external so the
    // scheduler does not run their own Draw events into the same queues.
    if c.player {
        let pid = s.insert_external(PLAYER_OBJ);
        let inst = s.instances.get_mut(&pid).expect("staged player");
        inst.fields.insert("x".into(), 400.0);
        inst.fields.insert("y".into(), 300.0);
    }
    for boss in &c.bosses {
        let bid = s.insert_external(boss.object);
        let (hpf, maxf) = BOSS_GATES
            .iter()
            .find(|g| g.0 == boss.object)
            .map(|g| (g.1, g.2))
            .expect("boss gate row");
        let inst = s.instances.get_mut(&bid).expect("staged boss");
        inst.fields.insert("x".into(), boss.x);
        inst.fields.insert("y".into(), boss.y);
        inst.fields.insert(hpf.into(), boss.hp);
        inst.fields.insert(maxf.into(), boss.maxhp);
    }

    s.view_positions.insert(c.view, c.cam);
    s
}

fn run(b: &Bundle, c: &Case) -> Result<Scene, String> {
    let mut s = stage(b, c);
    s.executed.clear();
    s.draw_view(b, c.view)?;
    Ok(s)
}

// ---------------------------------------------------------------------------
// expected output, assembled from the bytecode-derived tables
// ---------------------------------------------------------------------------

#[derive(Debug, PartialEq)]
struct ExpDraw {
    sprite: f64,
    frame: f64,
    x: f64,
    y: f64,
    scale_x: f64,
    scale_y: f64,
    rotation: f64,
    color: i32,
    alpha: f64,
}

#[derive(Debug, PartialEq)]
struct ExpText {
    x: f64,
    y: f64,
    text: String,
    font: i32,
    color: i32,
}

#[derive(Debug, PartialEq)]
struct ExpBar {
    x1: f64,
    y1: f64,
    x2: f64,
    y2: f64,
    amount: f64,
    back: i32,
    min: i32,
    max: i32,
}

#[derive(Default, Debug)]
struct Expect {
    draws: Vec<ExpDraw>,
    texts: Vec<ExpText>,
    bars: Vec<ExpBar>,
}

/// Health segment table for one (view, health1) cell. Only the six shipped
/// views have a health block at all; health1 outside the 22 shipped values
/// (2..=23, integers) matches no arm.
fn segments(view: i32, health1: f64) -> &'static [(f64, f64, f64)] {
    if !(2.0..=23.0).contains(&health1) || health1.fract() != 0.0 {
        return &[];
    }
    let h = health1 as usize;
    match view {
        1 => {
            if h <= 11 {
                &SMALL_B[..SMALL_COUNT_B[h - 2]]
            } else {
                &BIG_B[..BIG_COUNT_B[h - 12]]
            }
        }
        0 | 3 | 4 | 5 | 6 => {
            if h <= 11 {
                &SMALL_A[..SMALL_COUNT_A[h - 2]]
            } else {
                &BIG_A[..BIG_COUNT_A[h - 12]]
            }
        }
        _ => &[],
    }
}

fn expected(c: &Case) -> Expect {
    let (vx, vy) = c.cam;
    let mut e = Expect::default();

    if let Some(v) = VIEW_SPECS.iter().find(|v| v.view == c.view) {
        e.draws.push(ExpDraw {
            sprite: UI_SPRITE,
            frame: UI_FRAME,
            x: vx,
            y: vy + v.ui_dy,
            scale_x: v.ui_scale,
            scale_y: v.ui_scale,
            rotation: UI_ROT,
            color: UI_COLOR,
            alpha: UI_ALPHA,
        });
        let level_dx = if c.level < 10.0 { v.level_dx_lt10 } else { v.level_dx_ge10 };
        e.texts.push(ExpText {
            x: vx + level_dx,
            y: vy + v.level_dy,
            text: text_of(c.level),
            font: v.level_font,
            color: WHITE,
        });
        e.texts.push(ExpText {
            x: vx + v.score_dx,
            y: vy + v.score_dy,
            text: text_of(SCORE),
            font: 3,
            color: WHITE,
        });
        // `if (global.level < 20) { computed } else if (>= 20) { pinned 100 }`
        let amount = if c.level < 20.0 {
            (c.exp / c.xpneed) * 100.0
        } else {
            100.0
        };
        let (x1, y1, x2, y2) = v.bar;
        e.bars.push(ExpBar {
            x1: vx + x1,
            y1: vy + y1,
            x2: vx + x2,
            y2: vy + y2,
            amount,
            back: XP_BACK,
            min: XP_MIN,
            max: XP_MAX,
        });
    }

    for gate in BOSS_GATES {
        if let Some(boss) = c.bosses.iter().find(|b| b.object == gate.0) {
            e.bars.push(ExpBar {
                x1: boss.x + gate.3,
                y1: boss.y + gate.4,
                x2: boss.x + gate.5,
                y2: boss.y + gate.6,
                amount: (boss.hp / boss.maxhp) * 100.0,
                back: BOSS_BACK,
                min: BOSS_MIN,
                max: BOSS_MAX,
            });
        }
    }

    if c.player {
        for &(dx, dy, s) in segments(c.view, c.health1) {
            e.draws.push(ExpDraw {
                sprite: HEALTH_SPRITE,
                frame: HEALTH_FRAME,
                x: vx + dx,
                y: vy + dy,
                scale_x: s,
                scale_y: s,
                rotation: HEALTH_ROT,
                color: HEALTH_COLOR,
                alpha: HEALTH_ALPHA,
            });
        }
    }
    e
}

/// The reusable validator: run the shipped body on a (possibly perturbed)
/// bundle and require the *complete* emitted output to equal the table above.
/// Used by the matrix and by the negative control, so a perturbation the
/// validator cannot see would be a hole in both.
fn check(b: &Bundle, c: &Case) -> Result<Scene, String> {
    let s = run(b, c)?;
    let e = expected(c);
    let label = c.label();

    let draws: Vec<&DrawCommand> = s.draws.iter().filter(|d| d.code == CODE).collect();
    if draws.len() != e.draws.len() {
        return Err(format!(
            "{label}: {} sprite draws, expected {} (got {:?})",
            draws.len(),
            e.draws.len(),
            draws.iter().map(|d| (d.sprite, d.x, d.y, d.scale_x)).collect::<Vec<_>>()
        ));
    }
    for (i, (got, want)) in draws.iter().zip(e.draws.iter()).enumerate() {
        let got = ExpDraw {
            sprite: got.sprite as f64,
            frame: got.frame,
            x: got.x,
            y: got.y,
            scale_x: got.scale_x,
            scale_y: got.scale_y,
            rotation: got.rotation,
            color: got.color,
            alpha: got.alpha,
        };
        if got != *want {
            return Err(format!("{label}: sprite draw {i} = {got:?}, expected {want:?}"));
        }
        if got.fog {
            return Err(format!("{label}: sprite draw {i} carries fog, this body sets none"));
        }
        if draws[i].view != c.view {
            return Err(format!("{label}: sprite draw {i} tagged view {}", draws[i].view));
        }
    }

    let texts: Vec<&TextCommand> = s.texts.iter().filter(|t| t.code == CODE).collect();
    if texts.len() != e.texts.len() {
        return Err(format!(
            "{label}: {} texts, expected {} (got {:?})",
            texts.len(),
            e.texts.len(),
            texts.iter().map(|t| (t.x, t.y, t.text.clone())).collect::<Vec<_>>()
        ));
    }
    for (i, (got, want)) in texts.iter().zip(e.texts.iter()).enumerate() {
        let got = ExpText {
            x: got.x,
            y: got.y,
            text: got.text.clone(),
            font: got.font,
            color: got.color,
        };
        if got != *want {
            return Err(format!("{label}: text {i} = {got:?}, expected {want:?}"));
        }
    }

    let bars: Vec<&HealthbarCommand> = s.healthbars.iter().filter(|h| h.code == CODE).collect();
    if bars.len() != e.bars.len() {
        return Err(format!(
            "{label}: {} healthbars, expected {} (got {:?})",
            bars.len(),
            e.bars.len(),
            bars.iter().map(|b| (b.x1, b.y1, b.x2, b.y2, b.amount)).collect::<Vec<_>>()
        ));
    }
    for (i, (got, want)) in bars.iter().zip(e.bars.iter()).enumerate() {
        let got = ExpBar {
            x1: got.x1,
            y1: got.y1,
            x2: got.x2,
            y2: got.y2,
            amount: got.amount,
            back: got.back_col,
            min: got.min_col,
            max: got.max_col,
        };
        if got != *want {
            return Err(format!("{label}: healthbar {i} = {got:?}, expected {want:?}"));
        }
    }
    Ok(s)
}

// ---------------------------------------------------------------------------
// live-bytecode structure: guards, their spans and their ledger
// ---------------------------------------------------------------------------

#[derive(Clone, Copy, Debug, PartialEq)]
enum Axis {
    View,
    Level,
    Health,
}

#[derive(Clone, Copy, Debug, PartialEq)]
enum Role {
    /// `if (view_current == K)` UI block.
    Ui,
    /// `if (view_current == K)` score block.
    Score,
    /// `if (view_current == K)` XP bar under `level < 20`.
    BarLt,
    /// `if (view_current == K)` XP bar under `level >= 20`.
    BarGe,
    /// `if (health1 == K)` arm inside the health block of view `owner`.
    Health(i32),
    /// `if (global.level < 10)` level-text offset inside view `owner`.
    TextLt(i32),
    /// `if (global.level >= 10)` level-text offset inside view `owner`.
    TextGe(i32),
    /// `if (global.level < 20)` around the six XP bar blocks.
    XpLt,
    /// `else if (global.level >= 20)` around the six XP bars.
    XpGe,
}

#[derive(Clone, Copy, Debug)]
struct Guard {
    axis: Axis,
    /// `cmp` comparison code: 1 = `<`, 3 = `==`, 5 = `>=`.
    compare: u8,
    /// The constant the key is compared against.
    key: f64,
    /// Offsets are absolute byte offsets into the CODE chunk.
    at: usize,
    const_off: usize,
    cmp_off: usize,
    bf_off: usize,
    /// First instruction of the guarded body.
    body_start: usize,
    /// The `bf` target: the first instruction after the guarded body.
    body_end: usize,
    role: Option<Role>,
}

/// Reads the body's own `load key; constant K; cmp; bf target` guards. All 176
/// comparisons of CODE 370 match this shape and belong to exactly one of the
/// three keys, which is why the axis is enumerable at all.
fn guards(b: &Bundle) -> Vec<Guard> {
    let ins = ui_body(b);
    let mut out = Vec::new();
    for i in 0..ins.len().saturating_sub(4) {
        let (name, selector, array, other) = match &ins[i].op {
            Op::Load { name, selector, array, other } => (name.as_str(), *selector, *array, *other),
            _ => continue,
        };
        if array || other {
            continue;
        }
        let axis = match (name, selector) {
            ("view_current", -1) => Axis::View,
            ("level", -5) => Axis::Level,
            ("health1", -5) => Axis::Health,
            _ => continue,
        };
        let key = match ins[i + 1].op {
            Op::Constant { value } => value,
            _ => continue,
        };
        let compare = match ins[i + 2].op {
            Op::Cmp { comparison } => comparison,
            _ => continue,
        };
        let body_end = match ins[i + 3].op {
            Op::Bf { target } => target,
            _ => continue,
        };
        out.push(Guard {
            axis,
            compare,
            key,
            at: ins[i].offset,
            const_off: ins[i + 1].offset,
            cmp_off: ins[i + 2].offset,
            bf_off: ins[i + 3].offset,
            body_start: ins[i + 4].offset,
            body_end,
            role: None,
        });
    }

    // Roles follow the shipped source order, which is also layout order (the
    // census test asserts the monotonic spans): 6 UI, 6 score, 6 XP bars under
    // level < 20, 6 XP bars under level >= 20, then 6 health blocks of 22 arms.
    let view_idx: Vec<usize> = out
        .iter()
        .enumerate()
        .filter(|(_, g)| g.axis == Axis::View)
        .map(|(i, _)| i)
        .collect();
    assert!(view_idx.len() >= 30, "expected at least the 30 view guards");
    let block_view = |pos: usize| out[view_idx[pos]].key as i32;
    for pos in 0..view_idx.len() {
        let role = match pos / 6 {
            0 => Role::Ui,
            1 => Role::Score,
            2 => Role::BarLt,
            3 => Role::BarGe,
            _ => Role::Health(block_view(pos)),
        };
        out[view_idx[pos]].role = Some(role);
    }
    // Level guards: the text pairs sit inside a UI block, the XP pair at top
    // level. Ownership is decided by the enclosing UI span, not by guesswork.
    for g in out.iter_mut().filter(|g| g.axis == Axis::Level) {
        let owner = view_idx
            .iter()
            .take(6)
            .map(|&i| out[i])
            .find(|b| g.at >= b.body_start && g.at < b.body_end)
            .map(|b| b.key as i32);
        g.role = Some(match (g.compare, owner) {
            (1, Some(v)) => Role::TextLt(v),
            (5, Some(v)) => Role::TextGe(v),
            (1, None) => Role::XpLt,
            (5, None) => Role::XpGe,
            other => panic!("unexpected level guard {other:?}"),
        });
    }
    for g in out.iter_mut().filter(|g| g.axis == Axis::Health) {
        let owner = view_idx
            .iter()
            .skip(24)
            .map(|&i| out[i])
            .find(|b| g.at >= b.body_start && g.at < b.body_end)
            .map(|b| b.key as i32)
            .expect("every health1 arm sits inside a view block");
        g.role = Some(Role::Health(owner));
    }
    out
}

fn executed(s: &Scene) -> Vec<usize> {
    s.executed.iter().filter(|(c, _)| *c == CODE).map(|(_, o)| *o).collect()
}

fn ran(s: &Scene, off: usize) -> bool {
    s.executed.iter().any(|(c, o)| *c == CODE && *o == off)
}

fn ran_in(s: &Scene, span: (usize, usize)) -> usize {
    s.executed
        .iter()
        .filter(|(c, o)| *c == CODE && *o >= span.0 && *o < span.1)
        .count()
}

/// Every guard must fire exactly on its own input: its `cmp` on the inputs that
/// reach it at all, its arm body only when the key matched (plus the enclosing
/// gates the shipped nesting implies).
fn assert_guard_ledger(s: &Scene, c: &Case, g: &[Guard]) -> Result<(), String> {
    for gd in g {
        let (want_cmp, want_body) = match gd.role.expect("role assigned") {
            Role::Ui | Role::Score => (true, c.view == gd.key as i32),
            Role::BarLt => (c.level < 20.0, c.level < 20.0 && c.view == gd.key as i32),
            Role::BarGe => (c.level >= 20.0, c.level >= 20.0 && c.view == gd.key as i32),
            Role::Health(owner) => {
                let entered = c.player && c.view == owner;
                (entered, entered && c.health1 == gd.key)
            }
            Role::TextLt(owner) => (c.view == owner, c.view == owner && c.level < 10.0),
            Role::TextGe(owner) => (c.view == owner, c.view == owner && c.level >= 10.0),
            Role::XpLt => (true, c.level < 20.0),
            Role::XpGe => (true, c.level >= 20.0),
        };
        let got_cmp = ran(s, gd.cmp_off);
        if got_cmp != want_cmp {
            return Err(format!(
                "{}: guard {:?} key {} cmp at {} ran={} expected={}",
                c.label(),
                gd.role.unwrap(),
                gd.key,
                gd.cmp_off,
                got_cmp,
                want_cmp
            ));
        }
        let got_body = ran(s, gd.body_start);
        if got_body != want_body {
            return Err(format!(
                "{}: guard {:?} key {} body at {} ran={} expected={}",
                c.label(),
                gd.role.unwrap(),
                gd.key,
                gd.body_start,
                got_body,
                want_body
            ));
        }
    }
    Ok(())
}

// ---------------------------------------------------------------------------
// tests
// ---------------------------------------------------------------------------

#[test]
// CODE 370
fn the_ui_draw_body_census_is_the_shipped_branch_table() {
    let b = bundle();
    let ins = ui_body(&b);
    let calls = |n: &str| {
        ins.iter()
            .filter(|i| matches!(&i.op, Op::Call { name, .. } if name == n))
            .count()
    };

    // Call census of the whole body.
    assert_eq!(calls("draw_sprite_ext"), 1194, "CODE {CODE} draw_sprite_ext sites");
    assert_eq!(calls("draw_sprite"), 330, "CODE {CODE} draw_sprite sites");
    assert_eq!(calls("draw_text"), 18, "CODE {CODE} draw_text sites");
    assert_eq!(calls("draw_healthbar"), 18, "CODE {CODE} draw_healthbar sites");
    assert_eq!(calls("draw_set_font"), 15, "CODE {CODE} draw_set_font sites");
    assert_eq!(calls("draw_set_color"), 15, "CODE {CODE} draw_set_color sites");
    assert_eq!(calls("string"), 12, "CODE {CODE} string() sites (one per level text)");
    assert_eq!(calls("instance_exists"), 7, "CODE {CODE} instance_exists sites");

    // These numbers close arithmetically on the tables: the six views share the
    // same segment counts (55 full-scale arms + 198 half-scale arms per view).
    let small_per_view: usize = SMALL_COUNT_A.iter().sum();
    let big_per_view: usize = BIG_COUNT_A.iter().sum();
    assert_eq!(small_per_view, 55);
    assert_eq!(big_per_view, 198);
    assert_eq!(SMALL_COUNT_A, SMALL_COUNT_B);
    assert_eq!(BIG_COUNT_A, BIG_COUNT_B);
    assert_eq!(
        6 * small_per_view,
        330,
        "the 330 draw_sprite sites are exactly 6 views x 55 full-scale segments"
    );
    assert_eq!(
        6 * big_per_view + 6,
        1194,
        "the 1194 draw_sprite_ext sites are exactly 6 UI sprites + 6 views x 198 half-scale segments"
    );
    assert_eq!(6 * (small_per_view + big_per_view) + 6, 1194 + 330);

    // Branch shape.
    assert_eq!(
        ins.iter().filter(|i| matches!(i.op, Op::Bf { .. })).count(),
        183,
        "CODE {CODE} conditional jumps"
    );
    assert_eq!(
        ins.iter().filter(|i| matches!(i.op, Op::B { .. })).count(),
        7,
        "CODE {CODE} unconditional jumps"
    );

    // Guard census: 30 view guards (5 groups of 6), 14 level guards, 132 health
    // guards (6 blocks x 22 values) = the body's 176 comparisons.
    let g = guards(&b);
    let views: Vec<&Guard> = g.iter().filter(|g| g.axis == Axis::View).collect();
    assert_eq!(views.len(), 30, "view_current guards");
    let mut want_views = Vec::new();
    for _ in 0..5 {
        want_views.extend([0.0, 1.0, 3.0, 4.0, 5.0, 6.0]);
    }
    assert_eq!(
        views.iter().map(|g| g.key).collect::<Vec<_>>(),
        want_views,
        "UI / score / XP<20 / XP>=20 / health blocks, each in view order"
    );
    assert!(
        !views.iter().any(|g| g.key == 2.0),
        "the body never compares view_current against 2: view 2 has no HUD block"
    );
    assert!(
        views.windows(2).all(|w| w[0].body_start < w[1].body_start),
        "the blocks are laid out in source order"
    );

    let level: Vec<&Guard> = g.iter().filter(|g| g.axis == Axis::Level).collect();
    assert_eq!(level.len(), 14, "global.level guards");
    let mut want_level: Vec<(u8, f64)> = Vec::new();
    for _ in 0..6 {
        want_level.extend([(1, 10.0), (5, 10.0)]);
    }
    want_level.extend([(1, 20.0), (5, 20.0)]);
    assert_eq!(
        level.iter().map(|g| (g.compare, g.key)).collect::<Vec<_>>(),
        want_level,
        "level < 10 / >= 10 per UI block, then level < 20 / >= 20 on the XP bar"
    );

    let health: Vec<&Guard> = g.iter().filter(|g| g.axis == Axis::Health).collect();
    assert_eq!(health.len(), 132, "global.health1 guards");
    let mut want_health = Vec::new();
    for _ in 0..6 {
        want_health.extend((2..=23).map(|k| k as f64));
    }
    assert_eq!(
        health.iter().map(|g| g.key).collect::<Vec<_>>(),
        want_health,
        "each health block is 22 independent `if (health1 == K)` arms, K = 2..=23"
    );
    assert!(
        health.iter().all(|g| g.compare == 3),
        "the health arms are equality tests, not a range ladder"
    );
    assert_eq!(views.len() + level.len() + health.len(), 176);
    assert_eq!(
        ins.iter().filter(|i| matches!(i.op, Op::Cmp { .. })).count(),
        176,
        "every comparison in CODE {CODE} is one of the 176 guards above"
    );
}

#[test]
// CODE 370
fn every_view_level_health_cell_emits_the_pinned_commands() {
    let b = bundle();
    let g = guards(&b);
    let views = [0, 1, 3, 4, 5, 6];
    let levels = [0.0, 9.0, 9.5, 10.0, 19.0, 20.0, 21.0];
    let healths: [f64; 26] = [
        0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
        16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 12.5,
    ];

    let mut cells = 0usize;
    let mut shipped_segments = 0usize;
    for &view in &views {
        for &level in &levels {
            for &health1 in &healths {
                let c = Case::new(view, level, health1);
                let s = check(&b, &c).unwrap_or_else(|e| panic!("{e}"));
                assert_guard_ledger(&s, &c, &g).unwrap_or_else(|e| panic!("{e}"));
                assert!(
                    !executed(&s).is_empty(),
                    "{}: the VM ran nothing",
                    c.label()
                );
                assert!(
                    !s.instances.values().any(|i| i.fields.get("x") == Some(&STAGED_AT.0)
                        && s.draws.iter().any(|d| d.x == STAGED_AT.0)),
                    "{}: a draw used the staged instance position instead of the camera",
                    c.label()
                );
                cells += 1;
                if level == 9.0 && health1.fract() == 0.0 && health1 >= 2.0 {
                    shipped_segments += segments(view, health1).len();
                }
            }
        }
    }
    assert_eq!(cells, 6 * 7 * 26, "the view x level x health1 cross product");
    assert_eq!(
        shipped_segments,
        6 * (55 + 198),
        "all 1518 shipped health segments executed at least once (6 views x 253)"
    );
}

#[test]
// CODE 370
fn the_hud_follows_a_non_zero_camera_by_exact_translation() {
    let b = bundle();
    for view in [0, 1, 3, 4, 5, 6] {
        let mut a = Case::new(view, 9.0, 12.0);
        a.cam = (1000.0, 500.0);
        let mut c = Case::new(view, 9.0, 12.0);
        c.cam = (-321.0, 654.0);
        let sa = check(&b, &a).unwrap_or_else(|e| panic!("{e}"));
        let sc = check(&b, &c).unwrap_or_else(|e| panic!("{e}"));
        let (dx, dy) = (c.cam.0 - a.cam.0, c.cam.1 - a.cam.1);
        let da: Vec<&DrawCommand> = sa.draws.iter().filter(|d| d.code == CODE).collect();
        let dc: Vec<&DrawCommand> = sc.draws.iter().filter(|d| d.code == CODE).collect();
        assert_eq!(da.len(), dc.len());
        for (x, y) in da.iter().zip(dc.iter()) {
            assert_eq!(y.x - x.x, dx, "view {view}: a sprite x must translate with the camera");
            assert_eq!(y.y - x.y, dy, "view {view}: a sprite y must translate with the camera");
            assert_eq!((x.sprite, x.scale_x), (y.sprite, y.scale_x));
        }
        let ta: Vec<&TextCommand> = sa.texts.iter().filter(|t| t.code == CODE).collect();
        let tc: Vec<&TextCommand> = sc.texts.iter().filter(|t| t.code == CODE).collect();
        assert_eq!(ta.len(), tc.len());
        for (x, y) in ta.iter().zip(tc.iter()) {
            assert_eq!((y.x - x.x, y.y - x.y), (dx, dy), "view {view}: text translates");
            assert_eq!(x.text, y.text);
        }
        let ba: Vec<&HealthbarCommand> = sa.healthbars.iter().filter(|h| h.code == CODE).collect();
        let bc: Vec<&HealthbarCommand> = sc.healthbars.iter().filter(|h| h.code == CODE).collect();
        assert_eq!(ba.len(), bc.len());
        for (x, y) in ba.iter().zip(bc.iter()) {
            assert_eq!(
                (y.x1 - x.x1, y.y1 - x.y1, y.x2 - x.x2, y.y2 - x.y2),
                (dx, dy, dx, dy),
                "view {view}: bar geometry translates"
            );
            assert_eq!(x.amount, y.amount, "the bar amount does not depend on the camera");
        }
    }
}

#[test]
// CODE 370
fn views_without_a_block_emit_only_the_boss_gates() {
    let b = bundle();
    let g = guards(&b);
    // Out-of-table views: 2 (the gap), 7 (past the shipped set) and a negative.
    for &view in &[2, 7, -1] {
        let mut c = Case::new(view, 20.0, 23.0);
        for gate in BOSS_GATES {
            c = c.boss(gate.0, 300.0, 200.0, 425.0, 850.0);
        }
        let s = check(&b, &c).unwrap_or_else(|e| panic!("{e}"));
        assert_guard_ledger(&s, &c, &g).unwrap_or_else(|e| panic!("{e}"));
        let draws: Vec<&DrawCommand> = s.draws.iter().filter(|d| d.code == CODE).collect();
        let texts: Vec<&TextCommand> = s.texts.iter().filter(|t| t.code == CODE).collect();
        assert!(draws.is_empty(), "view {view}: no UI sprite and no health segments");
        assert!(texts.is_empty(), "view {view}: no level or score text");
        let bars: Vec<&HealthbarCommand> = s.healthbars.iter().filter(|h| h.code == CODE).collect();
        assert_eq!(bars.len(), 6, "view {view}: only the six boss bars");
        // No view block ran: zero executed instructions inside any of the six
        // per-view health spans.
        let view_guards: Vec<&Guard> = g.iter().filter(|g| g.axis == Axis::View).collect();
        for gd in view_guards.iter().skip(24) {
            assert_eq!(
                ran_in(&s, (gd.body_start, gd.body_end)),
                0,
                "view {view}: health block of view {} must not run",
                gd.key
            );
        }
        for gd in view_guards.iter().take(6) {
            assert_eq!(
                ran_in(&s, (gd.body_start, gd.body_end)),
                0,
                "view {view}: UI block of view {} must not run",
                gd.key
            );
        }
    }
}

#[test]
// CODE 370
fn the_boss_gate_table_draws_each_shipped_bar() {
    let b = bundle();
    // Every gate on its own: geometry is a fixed offset from the boss instance,
    // the amount is hp/max*100 and nothing about the view or the level leaks in.
    for gate in BOSS_GATES {
        let c = Case::new(0, 9.0, 0.0).boss(gate.0, 300.0, 200.0, 425.0, 850.0);
        let s = check(&b, &c).unwrap_or_else(|e| panic!("{e}"));
        let bars: Vec<&HealthbarCommand> = s.healthbars.iter().filter(|h| h.code == CODE).collect();
        assert_eq!(bars.len(), 2, "boss {}: the XP bar plus its own bar", gate.0);
        let bar = bars[1];
        assert_eq!(
            (bar.x1, bar.y1, bar.x2, bar.y2),
            (300.0 + gate.3, 200.0 + gate.4, 300.0 + gate.5, 200.0 + gate.6),
            "boss {} geometry",
            gate.0
        );
        assert_eq!(bar.amount, 50.0, "boss {}: 425/850 -> 50%", gate.0);
        assert_eq!((bar.back_col, bar.min_col, bar.max_col), (0, 255, 32768));
        // Edge amounts through the same gate.
        for (hp, amount) in [(0.0, 0.0), (850.0, 100.0), (212.5, 25.0)] {
            let e = Case::new(0, 9.0, 0.0).boss(gate.0, 300.0, 200.0, hp, 850.0);
            let se = check(&b, &e).unwrap_or_else(|err| panic!("{err}"));
            let eb: Vec<&HealthbarCommand> =
                se.healthbars.iter().filter(|h| h.code == CODE).collect();
            assert_eq!(eb[1].amount, amount, "boss {} {hp}/850", gate.0);
        }
    }

    // boss5's shipped rect runs right-to-left: x2 = x - 20 < x1 = x. Keep it.
    let b5 = Case::new(0, 9.0, 0.0).boss(29, 300.0, 200.0, 425.0, 850.0);
    let s5 = check(&b, &b5).unwrap_or_else(|e| panic!("{e}"));
    let bar5 = s5.healthbars.iter().filter(|h| h.code == CODE).nth(1).expect("boss5 bar");
    assert!(bar5.x2 < bar5.x1, "boss5 draws its bar right-to-left: {bar5:?}");

    // All six at once, plus a second instance of one gate: the gates are
    // independent `if`s in shipped order, and `instance_exists` is a boolean.
    let mut all = Case::new(3, 25.0, 14.0);
    for gate in BOSS_GATES {
        all = all.boss(gate.0, 100.0 + gate.0 as f64, 300.0, 300.0, 600.0);
    }
    let s = check(&b, &all).unwrap_or_else(|e| panic!("{e}"));
    let bars: Vec<&HealthbarCommand> = s.healthbars.iter().filter(|h| h.code == CODE).collect();
    assert_eq!(bars.len(), 7, "six boss bars plus the XP bar");
    assert_eq!(bars[0].y1, all.cam.1 + 5.0, "the XP bar comes first");
    let order: Vec<f64> = bars[1..].iter().map(|b| b.y1).collect();
    assert_eq!(
        order,
        vec![300.0 - 70.0, 300.0 - 60.0, 300.0 - 50.0, 300.0 - 80.0, 300.0 - 70.0, 300.0 - 70.0],
        "trex, boss2, boss3, boss4, boss5, finalboss - in that order"
    );

    // No boss present: the XP bar is the only bar.
    let none = check(&b, &Case::new(0, 9.0, 4.0)).unwrap_or_else(|e| panic!("{e}"));
    assert_eq!(none.healthbars.iter().filter(|h| h.code == CODE).count(), 1);
}

#[test]
// CODE 370
fn a_missing_player_removes_only_the_health_segments() {
    let b = bundle();
    let with = check(&b, &Case::new(0, 9.0, 23.0)).unwrap_or_else(|e| panic!("{e}"));
    let without = check(&b, &Case::new(0, 9.0, 23.0).no_player()).unwrap_or_else(|e| panic!("{e}"));
    let n = |s: &Scene| s.draws.iter().filter(|d| d.code == CODE).count();
    assert_eq!(n(&with), 1 + 22, "obj_UI sprite + 22 segments");
    assert_eq!(n(&without), 1, "without obj_player the segments are gone");
    assert_eq!(
        without.texts.iter().filter(|t| t.code == CODE).count(),
        2,
        "the level and score texts sit outside the player gate"
    );
    assert_eq!(
        without.healthbars.iter().filter(|h| h.code == CODE).count(),
        1,
        "the XP bar sits outside the player gate"
    );
}

#[test]
// CODE 370
fn the_zero_denominators_abort_the_draw_where_the_bytecode_divides() {
    let b = bundle();

    // Boss gate: `(hp / maxhp) * 100` with maxhp = 0. The trex gate is the
    // first one, so everything before it is already in the queue and nothing
    // after it runs.
    let c = Case::new(0, 9.0, 23.0).boss(25, 300.0, 200.0, 425.0, 0.0);
    let err = run(&b, &c).expect_err("a zero boss maxhp must abort the UI Draw");
    assert!(err.contains("division by zero"), "unexpected error: {err}");
    let mut s = stage(&b, &c);
    s.executed.clear();
    let _ = s.draw_view(&b, c.view);
    let draws: Vec<&DrawCommand> = s.draws.iter().filter(|d| d.code == CODE).collect();
    assert_eq!(draws.len(), 1, "the UI sprite was recorded before the abort");
    assert_eq!(
        s.healthbars.iter().filter(|h| h.code == CODE).count(),
        1,
        "the XP bar was recorded before the abort"
    );

    // XP bar: `(experience / xptolevelup) * 100` with xptolevelup = 0 and a
    // level below 20. The level text is drawn first, the bar fails.
    let mut xp = Case::new(0, 9.0, 4.0);
    xp.xpneed = 0.0;
    let err = run(&b, &xp).expect_err("a zero xptolevelup must abort the UI Draw");
    assert!(err.contains("division by zero"), "unexpected error: {err}");

    // Above level 20 the same body never divides: the bar is pinned to 100.
    let mut xp20 = Case::new(0, 20.0, 4.0);
    xp20.xpneed = 0.0;
    let s = check(&b, &xp20).expect("level >= 20 never divides");
    let bar = s.healthbars.iter().find(|h| h.code == CODE).expect("XP bar");
    assert_eq!(bar.amount, 100.0);

    // health1 outside the table neither aborts nor draws: it just walks all 22
    // comparisons (asserted per-guard by the matrix, re-checked here for 0/24).
    for h in [0.0, 24.0, 12.5, -3.0] {
        let s = check(&b, &Case::new(0, 9.0, h)).unwrap_or_else(|e| panic!("{e}"));
        assert_eq!(
            s.draws.iter().filter(|d| d.code == CODE).count(),
            1,
            "health1 {h}: only the UI sprite"
        );
    }
}

#[test]
// CODE 370
fn the_reusable_validator_rejects_perturbed_bundle_copies() {
    let b = bundle();
    let g = guards(&b);

    // Positive control: the untouched bundle passes the same validator.
    let base = Case::new(0, 9.0, 2.0);
    check(&b, &base).expect("the shipped bundle passes the validator");

    let patch = |at: usize, op: Op| -> Bundle {
        let mut nb = b.clone();
        let body = nb.codes.iter_mut().find(|c| c.id == CODE).expect("CODE 370");
        let ins = body
            .instructions
            .iter_mut()
            .find(|i| i.offset == at)
            .unwrap_or_else(|| panic!("no instruction at offset {at}"));
        ins.op = op;
        nb
    };

    // (1) A draw parameter: the first health segment's x constant, 58 -> 59.
    let health0: Vec<&Guard> = g
        .iter()
        .filter(|gd| gd.axis == Axis::View)
        .skip(24)
        .take(1)
        .collect();
    let x58 = ui_body(&b)
        .iter()
        .find(|i| {
            i.offset >= health0[0].body_start
                && i.offset < health0[0].body_end
                && matches!(i.op, Op::Constant { value } if value == 58.0)
        })
        .expect("the first segment x constant")
        .offset;
    let perturbed = patch(x58, Op::Constant { value: 59.0 });
    let err = check(&perturbed, &base).expect_err("a moved segment must be rejected");
    assert!(err.contains("sprite draw"), "unexpected rejection: {err}");

    // (2) A guard key: view 0's first UI guard re-keyed to view 2, so view 0
    // loses its whole UI/level/score/XP block and view 2 gains one.
    let v0 = g.iter().filter(|gd| gd.axis == Axis::View).next().expect("view 0 guard");
    assert_eq!(v0.key, 0.0);
    let perturbed = patch(v0.const_off, Op::Constant { value: 2.0 });
    let err = check(&perturbed, &base).expect_err("a re-keyed view guard must be rejected");
    assert!(err.contains("sprite draw"), "unexpected rejection: {err}");
    let view2 = Case::new(2, 9.0, 2.0);
    let err = check(&perturbed, &view2).expect_err("the re-keyed guard must also reject view 2");
    assert!(err.contains("sprite draw") || err.contains("healthbar"), "unexpected: {err}");
    // The unperturbed bundle still rejects nothing.
    check(&perturbed, &Case::new(3, 9.0, 2.0)).expect_err("view 3 uses its own block");

    // (3) A jump target: health1 == 2's `bf` skips its own arm and the next
    // one, so health1 = 2 draws nothing where one segment is expected.
    let h2 = g
        .iter()
        .find(|gd| gd.axis == Axis::Health && gd.key == 2.0)
        .expect("health1 == 2 guard");
    let next_guard = g
        .iter()
        .filter(|gd| gd.axis == Axis::Health)
        .find(|gd| gd.body_start == h2.body_end)
        .expect("the health1 == 3 guard follows immediately");
    let perturbed = patch(h2.bf_off, Op::Bf { target: next_guard.body_end });
    let err = check(&perturbed, &base).expect_err("a redirected health guard must be rejected");
    assert!(err.contains("sprite draw"), "unexpected rejection: {err}");

    // (4) A threshold: `level < 20` -> `< 21`, so level 20 takes both XP
    // branches and emits two bars.
    let xp_lt = g
        .iter()
        .find(|gd| gd.axis == Axis::Level && gd.key == 20.0 && gd.compare == 1)
        .expect("the level < 20 guard");
    let perturbed = patch(xp_lt.const_off, Op::Constant { value: 21.0 });
    let level20 = Case::new(0, 20.0, 4.0);
    let err = check(&perturbed, &level20).expect_err("a moved threshold must be rejected");
    assert!(err.contains("healthbar"), "unexpected rejection: {err}");

    // The perturbation helper is honest: patching an instruction back to its
    // shipped value restores the passing case.
    let restored = patch(x58, Op::Constant { value: 58.0 });
    check(&restored, &base).expect("restoring the shipped constant restores the output");
}
