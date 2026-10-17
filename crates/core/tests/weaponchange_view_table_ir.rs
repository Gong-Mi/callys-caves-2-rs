//! CODE 413 `gml_Object_obj_weaponchange_Draw_0` - full arm enumeration of the
//! pause-overlay draw table (branch debt batch 5, wl56-weaponchange).
//!
//! The body is one flat pass of 312 `if` tests over 8736 instructions, with no
//! `else` between the top-level blocks, so one Draw call can run several arms:
//!
//! ```text
//!   [pause sheet]     6 independent `if (view_current == V)` blocks, V in
//!                     0,1,3,4,5,6, each `draw_sprite_ext(spr_pause, 1,
//!                     view_xview[V]-1, view_yview[V], sx, sy, 0, -1, 1)` plus
//!                     a `taplock == 1` sub-block that sets font+colour and
//!                     draws "Tap to Continue" at view_xview[V]+dx,
//!                     view_yview[V]+dy. NOTE: there is no view 2 - the
//!                     shipped table skips it, and neither the sheet nor any
//!                     banner draws for view 2 (asserted below as a real hole,
//!                     not an omission).
//!   [12 banners]      12 independent `if (global.<weapon> == 1)` blocks, in
//!                     bytecode order pistol, shotgun, assaultrifle, spikegun,
//!                     boomerang, rocket, bladegun, flamethrower, bow,
//!                     bombgun, laser, icegun. Each sets font+colour once, then
//!                     runs an `if/else if` chain over the SAME six views, and
//!                     each view body runs `if/else if` over
//!                     `global.<weapon>level` in {4,7,10}:
//!                       draw_text(x + tdx, y + tdy, "Your <X> is now level N!")
//!                       draw_sprite_ext(<gun sprite>, 1|2|3, x + dx, y + dy,
//!                                       sx, sy, 0, -1, 1)
//!                     so the family is NOT else-if: arming several weapons
//!                     stacks their banners in stream order.
//! ```
//!
//! Arm census (re-derived from the shipped bytecode by every test below, not
//! trusted on sight): 6 sheet arms + 12 x 6 x 3 = 216 banner arms = 222
//! `draw_sprite_ext` sites and 222 `draw_text` sites, 444 call sites in all;
//! 312 equality tests (6 view + 6 taplock + 12 flags + 72 view re-tests +
//! 216 tier tests), 312 `bf` guards, 204 `b` jumps out of the else-if chains.
//! The view 2 gap shows up as 78 `view_current` loads = 6 + 72.
//!
//! The two const tables below were generated from `crates/core/src/generated/
//! full_ir.json` by a ~90-line read-only stack machine over the CODE 413
//! instruction stream (scratch script `wl56-weaponchange_gen.py` +
//! `wl56-weaponchange_emit.py`, not checked in). That decoder knows only the
//! opcodes this body uses and takes every number - sprite id, frame, scale,
//! offsets, string id, call offset - from the bytecode's own argument pushes;
//! the strings themselves come from the shipped STRG chunk in
//! `assets/game.droid`, anchored by id 743 == "Tap to Continue". Nothing here
//! is transcribed from the recovered GML, and the GML was only read to know
//! what to look for.
//!
//! The embedded table is then cross-checked at run time against the bundle the
//! engine actually loads: the 444 table offsets must be a bijection onto the
//! body's real `draw_sprite_ext`/`draw_text` call sites, the body span and
//! instruction count must match, and each arm's own call offset must be what
//! appears in the engine's instruction ledger. Per arm the suite pins the whole
//! observable tuple (sprite id, frame, x, y, scale, rotation, colour, alpha,
//! view, instance) plus the text (literal, x, y, font, colour, offset) and
//! proves from the ledger that no neighbouring arm's body ran.
//!
//! Scope: re-written-end IR regression semantics. This is not an equivalence
//! proof against the original runner, and it says nothing about how the client
//! rasterises the resulting draw queue.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Op};
use callys_core::ir_scene::{DrawCommand, Scene, TextCommand};
use std::collections::BTreeSet;
use std::path::Path;

/// `obj_weaponchange` (object 83), the overlay CODE 409 creates: it pauses all
/// audio, deactivates every other instance, lands `taplock = 0` and arms
/// alarm[0] = 70.
const OVERLAY: i32 = 83;

/// Body identity, straight out of full_ir.json: 42880 bytes, 8736
/// instructions. Pinned so a regenerated IR that shifts the body cannot leave
/// this table silently pointing at the wrong call sites.
const CODE: usize = 413;
const CODE_START: usize = 4_536_832;
const CODE_END: usize = 4_579_712;
const N_INS: usize = 8_736;

/// Instance anchor for every cell. Deliberately far from every literal offset
/// in the body, so a backend that dropped the `+ dx`/`+ dy` and drew at the
/// raw offset could not pass by coincidence.
const INST_X: f64 = 1000.0;
const INST_Y: f64 = 2000.0;

/// `draw_set_font(font1)` / `draw_set_color(c_white)` as CODE 413 pushes them:
/// font1 is resource 0, c_white is 16777215.
const FONT1: i32 = 0;
const C_WHITE: i32 = 16777215;

/// Six views, six distinct camera origins. They are the only thing the sheet
/// and the tap prompt are anchored to, so per-view anchoring is provable from
/// the numbers alone (e.g. view 3 adds dx 180, dy 300 while view 1 adds 110,
/// 200 to a different origin).
#[rustfmt::skip]
const VIEW_POS: [(i32, f64, f64); 6] = [
    (0, 10.0, 500.0),
    (1, 110.0, 501.0),
    (3, 310.0, 503.0),
    (4, 410.0, 504.0),
    (5, 510.0, 505.0),
    (6, 610.0, 506.0),
];

/// The 12 shipped families in bytecode block order, as
/// (global flag, global level). Order matters: it is the banner stacking order.
#[rustfmt::skip]
const FAMILIES: [(&str, &str); 12] = [
    ("pistol", "pistollevel"),
    ("shotgun", "shotgunlevel"),
    ("assaultrifle", "assaultriflelevel"),
    ("spikegun", "spikegunlevel"),
    ("boomerang", "boomeranglevel"),
    ("rocket", "rocketlevel"),
    ("bladegun", "bladegunlevel"),
    ("flamethrower", "flamethrowerlevel"),
    ("bow", "bowlevel"),
    ("bombgun", "bombgunlevel"),
    ("laser", "laserlevel"),
    ("icegun", "icegunlevel"),
];

/// One `view_current` sheet block: `draw_sprite_ext(spr_pause` (= `spr`), frame,
/// view_xview[view] - 1, view_yview[view], sx, sy, 0, color, alpha)` and, when
/// `taplock == 1`, the font+colour+`draw_text(view_xview[view] + tdx,
/// view_yview[view] + tdy, text)` triple. `text_call`/`spr_call` are
/// CODE-relative instruction offsets, i.e. the ledger keys.
struct PauseArm {
    view: i32,
    spr: i32,
    frame: i32,
    sx: f64,
    sy: f64,
    color: i32,
    alpha: f64,
    tdx: f64,
    tdy: f64,
    text: &'static str,
    str_id: u32,
    text_call: usize,
    spr_call: usize,
}

/// One `(family, view_current, level)` banner arm: `draw_text(x + tdx,
/// y + tdy, text)` then `draw_sprite_ext(spr, frame, x + dx, y + dy, sx, sy,
/// 0, color, alpha)`, anchored to the overlay instance's own x/y - never to a
/// view.
struct WArm {
    weapon: &'static str,
    level_var: &'static str,
    view: i32,
    level: i32,
    spr: i32,
    frame: i32,
    sx: f64,
    sy: f64,
    dx: f64,
    dy: f64,
    tdx: f64,
    tdy: f64,
    color: i32,
    alpha: f64,
    text: &'static str,
    str_id: u32,
    text_call: usize,
    spr_call: usize,
}

// ---- generated arm tables (see the module docs for the extraction) ---------

// ---- CODE 413 pause overlay: 6 view arms (spr_pause 123, frame 1) ----
#[rustfmt::skip]
const PAUSE_ARMS: [PauseArm; 6] = [
    PauseArm { view: 0, spr: 123, frame: 1, sx: 0.96, sy: 0.8, color: -1, alpha: 1.0, tdx: 150.0, tdy: 200.0, text: "Tap to Continue", str_id: 743, text_call: 268, spr_call: 132 }, // CODE 413 pause view 0
    PauseArm { view: 1, spr: 123, frame: 1, sx: 0.82, sy: 0.8, color: -1, alpha: 1.0, tdx: 110.0, tdy: 200.0, text: "Tap to Continue", str_id: 743, text_call: 548, spr_call: 412 }, // CODE 413 pause view 1
    PauseArm { view: 3, spr: 123, frame: 1, sx: 1.08, sy: 1.2, color: -1, alpha: 1.0, tdx: 180.0, tdy: 300.0, text: "Tap to Continue", str_id: 743, text_call: 828, spr_call: 692 }, // CODE 413 pause view 3
    PauseArm { view: 4, spr: 123, frame: 1, sx: 1.08, sy: 1.2, color: -1, alpha: 1.0, tdx: 180.0, tdy: 300.0, text: "Tap to Continue", str_id: 743, text_call: 1108, spr_call: 972 }, // CODE 413 pause view 4
    PauseArm { view: 5, spr: 123, frame: 1, sx: 0.97, sy: 0.8, color: -1, alpha: 1.0, tdx: 150.0, tdy: 200.0, text: "Tap to Continue", str_id: 743, text_call: 1388, spr_call: 1252 }, // CODE 413 pause view 5
    PauseArm { view: 6, spr: 123, frame: 1, sx: 1.04, sy: 0.87, color: -1, alpha: 1.0, tdx: 160.0, tdy: 200.0, text: "Tap to Continue", str_id: 743, text_call: 1668, spr_call: 1532 }, // CODE 413 pause view 6
];

// ---- CODE 413 weapon banners: 12 families x 6 views x 3 levels ----
#[rustfmt::skip]
const W_ARMS: [WArm; 216] = [
    WArm { weapon: "pistol", level_var: "pistollevel", view: 0, level: 4, spr: 125, frame: 1, sx: 8.0, sy: 8.0, dx: 290.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 4!", str_id: 757, text_call: 1828, spr_call: 1928 }, // CODE 413 pistol view 0 level 4
    WArm { weapon: "pistol", level_var: "pistollevel", view: 0, level: 7, spr: 125, frame: 2, sx: 8.0, sy: 8.0, dx: 290.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 7!", str_id: 758, text_call: 2008, spr_call: 2108 }, // CODE 413 pistol view 0 level 7
    WArm { weapon: "pistol", level_var: "pistollevel", view: 0, level: 10, spr: 125, frame: 3, sx: 8.0, sy: 8.0, dx: 285.0, dy: 125.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 10!", str_id: 759, text_call: 2188, spr_call: 2288 }, // CODE 413 pistol view 0 level 10
    WArm { weapon: "pistol", level_var: "pistollevel", view: 1, level: 4, spr: 125, frame: 1, sx: 8.0, sy: 8.0, dx: 255.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 4!", str_id: 757, text_call: 2388, spr_call: 2488 }, // CODE 413 pistol view 1 level 4
    WArm { weapon: "pistol", level_var: "pistollevel", view: 1, level: 7, spr: 125, frame: 2, sx: 8.0, sy: 8.0, dx: 255.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 7!", str_id: 758, text_call: 2568, spr_call: 2668 }, // CODE 413 pistol view 1 level 7
    WArm { weapon: "pistol", level_var: "pistollevel", view: 1, level: 10, spr: 125, frame: 3, sx: 8.0, sy: 8.0, dx: 240.0, dy: 140.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 10!", str_id: 759, text_call: 2748, spr_call: 2848 }, // CODE 413 pistol view 1 level 10
    WArm { weapon: "pistol", level_var: "pistollevel", view: 3, level: 4, spr: 125, frame: 1, sx: 10.0, sy: 10.0, dx: 340.0, dy: 180.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 4!", str_id: 757, text_call: 2948, spr_call: 3048 }, // CODE 413 pistol view 3 level 4
    WArm { weapon: "pistol", level_var: "pistollevel", view: 3, level: 7, spr: 125, frame: 2, sx: 10.0, sy: 10.0, dx: 336.0, dy: 180.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 7!", str_id: 758, text_call: 3128, spr_call: 3228 }, // CODE 413 pistol view 3 level 7
    WArm { weapon: "pistol", level_var: "pistollevel", view: 3, level: 10, spr: 125, frame: 3, sx: 10.0, sy: 10.0, dx: 326.0, dy: 180.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 10!", str_id: 759, text_call: 3308, spr_call: 3408 }, // CODE 413 pistol view 3 level 10
    WArm { weapon: "pistol", level_var: "pistollevel", view: 4, level: 4, spr: 125, frame: 1, sx: 10.0, sy: 10.0, dx: 340.0, dy: 180.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 4!", str_id: 757, text_call: 3508, spr_call: 3608 }, // CODE 413 pistol view 4 level 4
    WArm { weapon: "pistol", level_var: "pistollevel", view: 4, level: 7, spr: 125, frame: 2, sx: 10.0, sy: 10.0, dx: 336.0, dy: 180.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 7!", str_id: 758, text_call: 3688, spr_call: 3788 }, // CODE 413 pistol view 4 level 7
    WArm { weapon: "pistol", level_var: "pistollevel", view: 4, level: 10, spr: 125, frame: 3, sx: 10.0, sy: 10.0, dx: 326.0, dy: 180.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 10!", str_id: 759, text_call: 3868, spr_call: 3968 }, // CODE 413 pistol view 4 level 10
    WArm { weapon: "pistol", level_var: "pistollevel", view: 5, level: 4, spr: 125, frame: 1, sx: 8.0, sy: 8.0, dx: 290.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 4!", str_id: 757, text_call: 4068, spr_call: 4168 }, // CODE 413 pistol view 5 level 4
    WArm { weapon: "pistol", level_var: "pistollevel", view: 5, level: 7, spr: 125, frame: 2, sx: 8.0, sy: 8.0, dx: 290.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 7!", str_id: 758, text_call: 4248, spr_call: 4348 }, // CODE 413 pistol view 5 level 7
    WArm { weapon: "pistol", level_var: "pistollevel", view: 5, level: 10, spr: 125, frame: 3, sx: 8.0, sy: 8.0, dx: 285.0, dy: 125.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 10!", str_id: 759, text_call: 4428, spr_call: 4528 }, // CODE 413 pistol view 5 level 10
    WArm { weapon: "pistol", level_var: "pistollevel", view: 6, level: 4, spr: 125, frame: 1, sx: 8.0, sy: 8.0, dx: 300.0, dy: 120.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 4!", str_id: 757, text_call: 4628, spr_call: 4728 }, // CODE 413 pistol view 6 level 4
    WArm { weapon: "pistol", level_var: "pistollevel", view: 6, level: 7, spr: 125, frame: 2, sx: 8.0, sy: 8.0, dx: 300.0, dy: 120.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 7!", str_id: 758, text_call: 4808, spr_call: 4908 }, // CODE 413 pistol view 6 level 7
    WArm { weapon: "pistol", level_var: "pistollevel", view: 6, level: 10, spr: 125, frame: 3, sx: 8.0, sy: 8.0, dx: 295.0, dy: 125.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Pistol is now level 10!", str_id: 759, text_call: 4988, spr_call: 5088 }, // CODE 413 pistol view 6 level 10
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 0, level: 4, spr: 127, frame: 1, sx: 8.0, sy: 8.0, dx: 262.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 4!", str_id: 760, text_call: 5248, spr_call: 5348 }, // CODE 413 shotgun view 0 level 4
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 0, level: 7, spr: 127, frame: 2, sx: 8.0, sy: 8.0, dx: 231.0, dy: 120.0, tdx: 89.0, tdy: 19.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 7!", str_id: 761, text_call: 5428, spr_call: 5528 }, // CODE 413 shotgun view 0 level 7
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 0, level: 10, spr: 127, frame: 3, sx: 8.0, sy: 8.0, dx: 232.0, dy: 120.0, tdx: 84.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 10!", str_id: 762, text_call: 5608, spr_call: 5708 }, // CODE 413 shotgun view 0 level 10
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 1, level: 4, spr: 127, frame: 1, sx: 8.0, sy: 8.0, dx: 222.0, dy: 120.0, tdx: 50.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 4!", str_id: 760, text_call: 5808, spr_call: 5908 }, // CODE 413 shotgun view 1 level 4
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 1, level: 7, spr: 127, frame: 2, sx: 8.0, sy: 8.0, dx: 195.0, dy: 120.0, tdx: 50.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 7!", str_id: 761, text_call: 5988, spr_call: 6088 }, // CODE 413 shotgun view 1 level 7
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 1, level: 10, spr: 127, frame: 3, sx: 8.0, sy: 8.0, dx: 188.0, dy: 120.0, tdx: 48.0, tdy: 19.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 10!", str_id: 762, text_call: 6168, spr_call: 6268 }, // CODE 413 shotgun view 1 level 10
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 3, level: 4, spr: 127, frame: 1, sx: 10.0, sy: 10.0, dx: 298.0, dy: 180.0, tdx: 115.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 4!", str_id: 760, text_call: 6368, spr_call: 6468 }, // CODE 413 shotgun view 3 level 4
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 3, level: 7, spr: 127, frame: 2, sx: 10.0, sy: 10.0, dx: 256.0, dy: 180.0, tdx: 115.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 7!", str_id: 761, text_call: 6548, spr_call: 6648 }, // CODE 413 shotgun view 3 level 7
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 3, level: 10, spr: 127, frame: 3, sx: 10.0, sy: 10.0, dx: 256.0, dy: 180.0, tdx: 115.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 10!", str_id: 762, text_call: 6728, spr_call: 6828 }, // CODE 413 shotgun view 3 level 10
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 4, level: 4, spr: 127, frame: 1, sx: 10.0, sy: 10.0, dx: 298.0, dy: 180.0, tdx: 115.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 4!", str_id: 760, text_call: 6928, spr_call: 7028 }, // CODE 413 shotgun view 4 level 4
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 4, level: 7, spr: 127, frame: 2, sx: 10.0, sy: 10.0, dx: 256.0, dy: 180.0, tdx: 115.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 7!", str_id: 761, text_call: 7108, spr_call: 7208 }, // CODE 413 shotgun view 4 level 7
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 4, level: 10, spr: 127, frame: 3, sx: 10.0, sy: 10.0, dx: 256.0, dy: 180.0, tdx: 115.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 10!", str_id: 762, text_call: 7288, spr_call: 7388 }, // CODE 413 shotgun view 4 level 10
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 5, level: 4, spr: 127, frame: 1, sx: 8.0, sy: 8.0, dx: 262.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 4!", str_id: 760, text_call: 7488, spr_call: 7588 }, // CODE 413 shotgun view 5 level 4
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 5, level: 7, spr: 127, frame: 2, sx: 8.0, sy: 8.0, dx: 231.0, dy: 120.0, tdx: 89.0, tdy: 19.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 7!", str_id: 761, text_call: 7668, spr_call: 7768 }, // CODE 413 shotgun view 5 level 7
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 5, level: 10, spr: 127, frame: 3, sx: 8.0, sy: 8.0, dx: 232.0, dy: 120.0, tdx: 84.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 10!", str_id: 762, text_call: 7848, spr_call: 7948 }, // CODE 413 shotgun view 5 level 10
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 6, level: 4, spr: 127, frame: 1, sx: 8.0, sy: 8.0, dx: 272.0, dy: 120.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 4!", str_id: 760, text_call: 8048, spr_call: 8148 }, // CODE 413 shotgun view 6 level 4
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 6, level: 7, spr: 127, frame: 2, sx: 8.0, sy: 8.0, dx: 241.0, dy: 120.0, tdx: 99.0, tdy: 19.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 7!", str_id: 761, text_call: 8228, spr_call: 8328 }, // CODE 413 shotgun view 6 level 7
    WArm { weapon: "shotgun", level_var: "shotgunlevel", view: 6, level: 10, spr: 127, frame: 3, sx: 8.0, sy: 8.0, dx: 242.0, dy: 120.0, tdx: 94.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Shotgun is now level 10!", str_id: 762, text_call: 8408, spr_call: 8508 }, // CODE 413 shotgun view 6 level 10
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 0, level: 4, spr: 129, frame: 1, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 4!", str_id: 763, text_call: 8668, spr_call: 8768 }, // CODE 413 assaultrifle view 0 level 4
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 0, level: 7, spr: 129, frame: 2, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 7!", str_id: 764, text_call: 8848, spr_call: 8948 }, // CODE 413 assaultrifle view 0 level 7
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 0, level: 10, spr: 129, frame: 3, sx: 8.0, sy: 8.0, dx: 85.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 10!", str_id: 765, text_call: 9028, spr_call: 9128 }, // CODE 413 assaultrifle view 0 level 10
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 1, level: 4, spr: 129, frame: 1, sx: 8.0, sy: 8.0, dx: 85.0, dy: 120.0, tdx: 30.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 4!", str_id: 763, text_call: 9228, spr_call: 9328 }, // CODE 413 assaultrifle view 1 level 4
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 1, level: 7, spr: 129, frame: 2, sx: 8.0, sy: 8.0, dx: 80.0, dy: 120.0, tdx: 30.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 7!", str_id: 764, text_call: 9408, spr_call: 9508 }, // CODE 413 assaultrifle view 1 level 7
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 1, level: 10, spr: 129, frame: 3, sx: 8.0, sy: 8.0, dx: 48.0, dy: 120.0, tdx: 26.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 10!", str_id: 765, text_call: 9588, spr_call: 9688 }, // CODE 413 assaultrifle view 1 level 10
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 3, level: 4, spr: 129, frame: 1, sx: 8.0, sy: 8.0, dx: 155.0, dy: 160.0, tdx: 95.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 4!", str_id: 763, text_call: 9788, spr_call: 9888 }, // CODE 413 assaultrifle view 3 level 4
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 3, level: 7, spr: 129, frame: 2, sx: 8.0, sy: 8.0, dx: 151.0, dy: 160.0, tdx: 95.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 7!", str_id: 764, text_call: 9968, spr_call: 10068 }, // CODE 413 assaultrifle view 3 level 7
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 3, level: 10, spr: 129, frame: 3, sx: 8.0, sy: 8.0, dx: 120.0, dy: 160.0, tdx: 92.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 10!", str_id: 765, text_call: 10148, spr_call: 10248 }, // CODE 413 assaultrifle view 3 level 10
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 4, level: 4, spr: 129, frame: 1, sx: 8.0, sy: 8.0, dx: 155.0, dy: 160.0, tdx: 95.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 4!", str_id: 763, text_call: 10348, spr_call: 10448 }, // CODE 413 assaultrifle view 4 level 4
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 4, level: 7, spr: 129, frame: 2, sx: 8.0, sy: 8.0, dx: 151.0, dy: 160.0, tdx: 95.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 7!", str_id: 764, text_call: 10528, spr_call: 10628 }, // CODE 413 assaultrifle view 4 level 7
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 4, level: 10, spr: 129, frame: 3, sx: 8.0, sy: 8.0, dx: 120.0, dy: 160.0, tdx: 92.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 10!", str_id: 765, text_call: 10708, spr_call: 10808 }, // CODE 413 assaultrifle view 4 level 10
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 5, level: 4, spr: 129, frame: 1, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 4!", str_id: 763, text_call: 10908, spr_call: 11008 }, // CODE 413 assaultrifle view 5 level 4
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 5, level: 7, spr: 129, frame: 2, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 7!", str_id: 764, text_call: 11088, spr_call: 11188 }, // CODE 413 assaultrifle view 5 level 7
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 5, level: 10, spr: 129, frame: 3, sx: 8.0, sy: 8.0, dx: 85.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 10!", str_id: 765, text_call: 11268, spr_call: 11368 }, // CODE 413 assaultrifle view 5 level 10
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 6, level: 4, spr: 129, frame: 1, sx: 8.0, sy: 8.0, dx: 130.0, dy: 120.0, tdx: 70.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 4!", str_id: 763, text_call: 11468, spr_call: 11568 }, // CODE 413 assaultrifle view 6 level 4
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 6, level: 7, spr: 129, frame: 2, sx: 8.0, sy: 8.0, dx: 130.0, dy: 120.0, tdx: 70.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 7!", str_id: 764, text_call: 11648, spr_call: 11748 }, // CODE 413 assaultrifle view 6 level 7
    WArm { weapon: "assaultrifle", level_var: "assaultriflelevel", view: 6, level: 10, spr: 129, frame: 3, sx: 8.0, sy: 8.0, dx: 95.0, dy: 120.0, tdx: 70.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Assault Rifle is now level 10!", str_id: 765, text_call: 11828, spr_call: 11928 }, // CODE 413 assaultrifle view 6 level 10
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 0, level: 4, spr: 142, frame: 1, sx: 8.0, sy: 8.0, dx: 130.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 4!", str_id: 766, text_call: 12088, spr_call: 12188 }, // CODE 413 spikegun view 0 level 4
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 0, level: 7, spr: 142, frame: 2, sx: 8.0, sy: 8.0, dx: 110.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 7!", str_id: 767, text_call: 12268, spr_call: 12368 }, // CODE 413 spikegun view 0 level 7
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 0, level: 10, spr: 142, frame: 3, sx: 8.0, sy: 8.0, dx: 88.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 10!", str_id: 768, text_call: 12448, spr_call: 12548 }, // CODE 413 spikegun view 0 level 10
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 1, level: 4, spr: 142, frame: 1, sx: 8.0, sy: 8.0, dx: 86.0, dy: 120.0, tdx: 40.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 4!", str_id: 766, text_call: 12648, spr_call: 12748 }, // CODE 413 spikegun view 1 level 4
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 1, level: 7, spr: 142, frame: 2, sx: 8.0, sy: 8.0, dx: 66.0, dy: 120.0, tdx: 40.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 7!", str_id: 767, text_call: 12828, spr_call: 12928 }, // CODE 413 spikegun view 1 level 7
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 1, level: 10, spr: 142, frame: 3, sx: 8.0, sy: 8.0, dx: 46.0, dy: 120.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 10!", str_id: 768, text_call: 13008, spr_call: 13108 }, // CODE 413 spikegun view 1 level 10
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 3, level: 4, spr: 142, frame: 1, sx: 8.0, sy: 8.0, dx: 150.0, dy: 170.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 4!", str_id: 766, text_call: 13208, spr_call: 13308 }, // CODE 413 spikegun view 3 level 4
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 3, level: 7, spr: 142, frame: 2, sx: 8.0, sy: 8.0, dx: 135.0, dy: 170.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 7!", str_id: 767, text_call: 13388, spr_call: 13488 }, // CODE 413 spikegun view 3 level 7
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 3, level: 10, spr: 142, frame: 3, sx: 8.0, sy: 8.0, dx: 110.0, dy: 170.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 10!", str_id: 768, text_call: 13568, spr_call: 13668 }, // CODE 413 spikegun view 3 level 10
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 4, level: 4, spr: 142, frame: 1, sx: 8.0, sy: 8.0, dx: 150.0, dy: 170.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 4!", str_id: 766, text_call: 13768, spr_call: 13868 }, // CODE 413 spikegun view 4 level 4
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 4, level: 7, spr: 142, frame: 2, sx: 8.0, sy: 8.0, dx: 135.0, dy: 170.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 7!", str_id: 767, text_call: 13948, spr_call: 14048 }, // CODE 413 spikegun view 4 level 7
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 4, level: 10, spr: 142, frame: 3, sx: 8.0, sy: 8.0, dx: 110.0, dy: 170.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 10!", str_id: 768, text_call: 14128, spr_call: 14228 }, // CODE 413 spikegun view 4 level 10
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 5, level: 4, spr: 142, frame: 1, sx: 8.0, sy: 8.0, dx: 130.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 4!", str_id: 766, text_call: 14328, spr_call: 14428 }, // CODE 413 spikegun view 5 level 4
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 5, level: 7, spr: 142, frame: 2, sx: 8.0, sy: 8.0, dx: 110.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 7!", str_id: 767, text_call: 14508, spr_call: 14608 }, // CODE 413 spikegun view 5 level 7
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 5, level: 10, spr: 142, frame: 3, sx: 8.0, sy: 8.0, dx: 88.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 10!", str_id: 768, text_call: 14688, spr_call: 14788 }, // CODE 413 spikegun view 5 level 10
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 6, level: 4, spr: 142, frame: 1, sx: 8.0, sy: 8.0, dx: 130.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 4!", str_id: 766, text_call: 14888, spr_call: 14988 }, // CODE 413 spikegun view 6 level 4
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 6, level: 7, spr: 142, frame: 2, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 7!", str_id: 767, text_call: 15068, spr_call: 15168 }, // CODE 413 spikegun view 6 level 7
    WArm { weapon: "spikegun", level_var: "spikegunlevel", view: 6, level: 10, spr: 142, frame: 3, sx: 8.0, sy: 8.0, dx: 100.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Spike Gun is now level 10!", str_id: 768, text_call: 15248, spr_call: 15348 }, // CODE 413 spikegun view 6 level 10
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 0, level: 4, spr: 144, frame: 1, sx: 8.0, sy: 8.0, dx: 220.0, dy: 120.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 4!", str_id: 769, text_call: 15508, spr_call: 15608 }, // CODE 413 boomerang view 0 level 4
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 0, level: 7, spr: 144, frame: 2, sx: 8.0, sy: 8.0, dx: 220.0, dy: 120.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 7!", str_id: 770, text_call: 15688, spr_call: 15788 }, // CODE 413 boomerang view 0 level 7
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 0, level: 10, spr: 144, frame: 3, sx: 7.0, sy: 7.0, dx: 220.0, dy: 130.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 10!", str_id: 771, text_call: 15868, spr_call: 15968 }, // CODE 413 boomerang view 0 level 10
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 1, level: 4, spr: 144, frame: 1, sx: 8.0, sy: 8.0, dx: 180.0, dy: 120.0, tdx: 33.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 4!", str_id: 769, text_call: 16068, spr_call: 16168 }, // CODE 413 boomerang view 1 level 4
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 1, level: 7, spr: 144, frame: 2, sx: 7.0, sy: 7.0, dx: 180.0, dy: 120.0, tdx: 33.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 7!", str_id: 770, text_call: 16248, spr_call: 16348 }, // CODE 413 boomerang view 1 level 7
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 1, level: 10, spr: 144, frame: 3, sx: 7.0, sy: 7.0, dx: 180.0, dy: 130.0, tdx: 27.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 10!", str_id: 771, text_call: 16428, spr_call: 16528 }, // CODE 413 boomerang view 1 level 10
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 3, level: 4, spr: 144, frame: 1, sx: 10.0, sy: 10.0, dx: 250.0, dy: 180.0, tdx: 93.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 4!", str_id: 769, text_call: 16628, spr_call: 16728 }, // CODE 413 boomerang view 3 level 4
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 3, level: 7, spr: 144, frame: 2, sx: 10.0, sy: 10.0, dx: 245.0, dy: 180.0, tdx: 93.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 7!", str_id: 770, text_call: 16808, spr_call: 16908 }, // CODE 413 boomerang view 3 level 7
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 3, level: 10, spr: 144, frame: 3, sx: 9.0, sy: 9.0, dx: 245.0, dy: 190.0, tdx: 93.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 10!", str_id: 771, text_call: 16988, spr_call: 17088 }, // CODE 413 boomerang view 3 level 10
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 4, level: 4, spr: 144, frame: 1, sx: 10.0, sy: 10.0, dx: 250.0, dy: 180.0, tdx: 93.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 4!", str_id: 769, text_call: 17188, spr_call: 17288 }, // CODE 413 boomerang view 4 level 4
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 4, level: 7, spr: 144, frame: 2, sx: 10.0, sy: 10.0, dx: 245.0, dy: 180.0, tdx: 93.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 7!", str_id: 770, text_call: 17368, spr_call: 17468 }, // CODE 413 boomerang view 4 level 7
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 4, level: 10, spr: 144, frame: 3, sx: 9.0, sy: 9.0, dx: 245.0, dy: 190.0, tdx: 93.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 10!", str_id: 771, text_call: 17548, spr_call: 17648 }, // CODE 413 boomerang view 4 level 10
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 5, level: 4, spr: 144, frame: 1, sx: 8.0, sy: 8.0, dx: 220.0, dy: 120.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 4!", str_id: 769, text_call: 17748, spr_call: 17848 }, // CODE 413 boomerang view 5 level 4
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 5, level: 7, spr: 144, frame: 2, sx: 8.0, sy: 8.0, dx: 220.0, dy: 120.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 7!", str_id: 770, text_call: 17928, spr_call: 18028 }, // CODE 413 boomerang view 5 level 7
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 5, level: 10, spr: 144, frame: 3, sx: 7.0, sy: 7.0, dx: 220.0, dy: 130.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 10!", str_id: 771, text_call: 18108, spr_call: 18208 }, // CODE 413 boomerang view 5 level 10
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 6, level: 4, spr: 144, frame: 1, sx: 8.0, sy: 8.0, dx: 230.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 4!", str_id: 769, text_call: 18308, spr_call: 18408 }, // CODE 413 boomerang view 6 level 4
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 6, level: 7, spr: 144, frame: 2, sx: 8.0, sy: 8.0, dx: 230.0, dy: 120.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 7!", str_id: 770, text_call: 18488, spr_call: 18588 }, // CODE 413 boomerang view 6 level 7
    WArm { weapon: "boomerang", level_var: "boomeranglevel", view: 6, level: 10, spr: 144, frame: 3, sx: 7.0, sy: 7.0, dx: 230.0, dy: 130.0, tdx: 75.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Boomerang is now level 10!", str_id: 771, text_call: 18668, spr_call: 18768 }, // CODE 413 boomerang view 6 level 10
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 0, level: 4, spr: 133, frame: 1, sx: 8.0, sy: 8.0, dx: 120.0, dy: 200.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 4!", str_id: 772, text_call: 18928, spr_call: 19028 }, // CODE 413 rocket view 0 level 4
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 0, level: 7, spr: 133, frame: 2, sx: 8.0, sy: 8.0, dx: 108.0, dy: 200.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 7!", str_id: 773, text_call: 19108, spr_call: 19208 }, // CODE 413 rocket view 0 level 7
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 0, level: 10, spr: 133, frame: 3, sx: 8.0, sy: 8.0, dx: 100.0, dy: 200.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 10!", str_id: 774, text_call: 19288, spr_call: 19388 }, // CODE 413 rocket view 0 level 10
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 1, level: 4, spr: 133, frame: 1, sx: 8.0, sy: 8.0, dx: 85.0, dy: 180.0, tdx: 40.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Launcher is now level 4!", str_id: 775, text_call: 19488, spr_call: 19588 }, // CODE 413 rocket view 1 level 4
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 1, level: 7, spr: 133, frame: 2, sx: 8.0, sy: 8.0, dx: 75.0, dy: 180.0, tdx: 40.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Launcher is now level 7!", str_id: 776, text_call: 19668, spr_call: 19768 }, // CODE 413 rocket view 1 level 7
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 1, level: 10, spr: 133, frame: 3, sx: 8.0, sy: 8.0, dx: 64.0, dy: 180.0, tdx: 40.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Launcher is now level 10!", str_id: 777, text_call: 19848, spr_call: 19948 }, // CODE 413 rocket view 1 level 10
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 3, level: 4, spr: 133, frame: 1, sx: 8.0, sy: 8.0, dx: 150.0, dy: 240.0, tdx: 71.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 4!", str_id: 772, text_call: 20048, spr_call: 20148 }, // CODE 413 rocket view 3 level 4
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 3, level: 7, spr: 133, frame: 2, sx: 8.0, sy: 8.0, dx: 140.0, dy: 240.0, tdx: 71.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 7!", str_id: 773, text_call: 20228, spr_call: 20328 }, // CODE 413 rocket view 3 level 7
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 3, level: 10, spr: 133, frame: 3, sx: 8.0, sy: 8.0, dx: 133.0, dy: 240.0, tdx: 66.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 10!", str_id: 774, text_call: 20408, spr_call: 20508 }, // CODE 413 rocket view 3 level 10
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 4, level: 4, spr: 133, frame: 1, sx: 8.0, sy: 8.0, dx: 150.0, dy: 240.0, tdx: 71.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 4!", str_id: 772, text_call: 20608, spr_call: 20708 }, // CODE 413 rocket view 4 level 4
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 4, level: 7, spr: 133, frame: 2, sx: 8.0, sy: 8.0, dx: 140.0, dy: 240.0, tdx: 71.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 7!", str_id: 773, text_call: 20788, spr_call: 20888 }, // CODE 413 rocket view 4 level 7
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 4, level: 10, spr: 133, frame: 3, sx: 8.0, sy: 8.0, dx: 133.0, dy: 240.0, tdx: 66.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 10!", str_id: 774, text_call: 20968, spr_call: 21068 }, // CODE 413 rocket view 4 level 10
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 5, level: 4, spr: 133, frame: 1, sx: 8.0, sy: 8.0, dx: 120.0, dy: 200.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 4!", str_id: 772, text_call: 21168, spr_call: 21268 }, // CODE 413 rocket view 5 level 4
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 5, level: 7, spr: 133, frame: 2, sx: 8.0, sy: 8.0, dx: 108.0, dy: 200.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 7!", str_id: 773, text_call: 21348, spr_call: 21448 }, // CODE 413 rocket view 5 level 7
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 5, level: 10, spr: 133, frame: 3, sx: 8.0, sy: 8.0, dx: 100.0, dy: 200.0, tdx: 35.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 10!", str_id: 774, text_call: 21528, spr_call: 21628 }, // CODE 413 rocket view 5 level 10
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 6, level: 4, spr: 133, frame: 1, sx: 8.0, sy: 8.0, dx: 130.0, dy: 200.0, tdx: 45.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 4!", str_id: 772, text_call: 21728, spr_call: 21828 }, // CODE 413 rocket view 6 level 4
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 6, level: 7, spr: 133, frame: 2, sx: 8.0, sy: 8.0, dx: 118.0, dy: 200.0, tdx: 45.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 7!", str_id: 773, text_call: 21908, spr_call: 22008 }, // CODE 413 rocket view 6 level 7
    WArm { weapon: "rocket", level_var: "rocketlevel", view: 6, level: 10, spr: 133, frame: 3, sx: 8.0, sy: 8.0, dx: 110.0, dy: 200.0, tdx: 45.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Rocket Launcher is now level 10!", str_id: 774, text_call: 22088, spr_call: 22188 }, // CODE 413 rocket view 6 level 10
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 0, level: 4, spr: 147, frame: 1, sx: 8.0, sy: 8.0, dx: 278.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 4!", str_id: 778, text_call: 22348, spr_call: 22448 }, // CODE 413 bladegun view 0 level 4
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 0, level: 7, spr: 147, frame: 2, sx: 8.0, sy: 8.0, dx: 268.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 7!", str_id: 779, text_call: 22528, spr_call: 22628 }, // CODE 413 bladegun view 0 level 7
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 0, level: 10, spr: 147, frame: 3, sx: 8.0, sy: 8.0, dx: 234.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 10!", str_id: 780, text_call: 22708, spr_call: 22808 }, // CODE 413 bladegun view 0 level 10
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 1, level: 4, spr: 147, frame: 1, sx: 8.0, sy: 8.0, dx: 246.0, dy: 120.0, tdx: 48.0, tdy: 19.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 4!", str_id: 778, text_call: 22908, spr_call: 23008 }, // CODE 413 bladegun view 1 level 4
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 1, level: 7, spr: 147, frame: 2, sx: 8.0, sy: 8.0, dx: 226.0, dy: 120.0, tdx: 48.0, tdy: 19.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 7!", str_id: 779, text_call: 23088, spr_call: 23188 }, // CODE 413 bladegun view 1 level 7
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 1, level: 10, spr: 147, frame: 3, sx: 8.0, sy: 8.0, dx: 196.0, dy: 120.0, tdx: 44.0, tdy: 18.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 10!", str_id: 780, text_call: 23268, spr_call: 23368 }, // CODE 413 bladegun view 1 level 10
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 3, level: 4, spr: 147, frame: 1, sx: 10.0, sy: 10.0, dx: 320.0, dy: 160.0, tdx: 104.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 4!", str_id: 778, text_call: 23468, spr_call: 23568 }, // CODE 413 bladegun view 3 level 4
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 3, level: 7, spr: 147, frame: 2, sx: 10.0, sy: 10.0, dx: 290.0, dy: 160.0, tdx: 104.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 7!", str_id: 779, text_call: 23648, spr_call: 23748 }, // CODE 413 bladegun view 3 level 7
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 3, level: 10, spr: 147, frame: 3, sx: 10.0, sy: 10.0, dx: 260.0, dy: 160.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 10!", str_id: 780, text_call: 23828, spr_call: 23928 }, // CODE 413 bladegun view 3 level 10
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 4, level: 4, spr: 147, frame: 1, sx: 10.0, sy: 10.0, dx: 320.0, dy: 160.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 4!", str_id: 778, text_call: 24028, spr_call: 24128 }, // CODE 413 bladegun view 4 level 4
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 4, level: 7, spr: 147, frame: 2, sx: 10.0, sy: 10.0, dx: 290.0, dy: 160.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 7!", str_id: 779, text_call: 24208, spr_call: 24308 }, // CODE 413 bladegun view 4 level 7
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 4, level: 10, spr: 147, frame: 3, sx: 10.0, sy: 10.0, dx: 260.0, dy: 160.0, tdx: 100.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 10!", str_id: 780, text_call: 24388, spr_call: 24488 }, // CODE 413 bladegun view 4 level 10
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 5, level: 4, spr: 147, frame: 1, sx: 8.0, sy: 8.0, dx: 278.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 4!", str_id: 778, text_call: 24588, spr_call: 24688 }, // CODE 413 bladegun view 5 level 4
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 5, level: 7, spr: 147, frame: 2, sx: 8.0, sy: 8.0, dx: 268.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 7!", str_id: 779, text_call: 24768, spr_call: 24868 }, // CODE 413 bladegun view 5 level 7
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 5, level: 10, spr: 147, frame: 3, sx: 8.0, sy: 8.0, dx: 234.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 10!", str_id: 780, text_call: 24948, spr_call: 25048 }, // CODE 413 bladegun view 5 level 10
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 6, level: 4, spr: 147, frame: 1, sx: 8.0, sy: 8.0, dx: 288.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 4!", str_id: 778, text_call: 25148, spr_call: 25248 }, // CODE 413 bladegun view 6 level 4
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 6, level: 7, spr: 147, frame: 2, sx: 8.0, sy: 8.0, dx: 278.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 7!", str_id: 779, text_call: 25328, spr_call: 25428 }, // CODE 413 bladegun view 6 level 7
    WArm { weapon: "bladegun", level_var: "bladegunlevel", view: 6, level: 10, spr: 147, frame: 3, sx: 8.0, sy: 8.0, dx: 244.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bladegun is now level 10!", str_id: 780, text_call: 25508, spr_call: 25608 }, // CODE 413 bladegun view 6 level 10
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 0, level: 4, spr: 145, frame: 1, sx: 8.0, sy: 8.0, dx: 222.0, dy: 120.0, tdx: 55.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 4!", str_id: 781, text_call: 25768, spr_call: 25868 }, // CODE 413 flamethrower view 0 level 4
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 0, level: 7, spr: 145, frame: 2, sx: 8.0, sy: 8.0, dx: 210.0, dy: 120.0, tdx: 55.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 7!", str_id: 782, text_call: 25948, spr_call: 26048 }, // CODE 413 flamethrower view 0 level 7
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 0, level: 10, spr: 145, frame: 3, sx: 7.0, sy: 7.0, dx: 170.0, dy: 130.0, tdx: 54.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 10!", str_id: 783, text_call: 26128, spr_call: 26228 }, // CODE 413 flamethrower view 0 level 10
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 1, level: 4, spr: 145, frame: 1, sx: 8.0, sy: 8.0, dx: 185.0, dy: 120.0, tdx: 18.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 4!", str_id: 781, text_call: 26328, spr_call: 26428 }, // CODE 413 flamethrower view 1 level 4
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 1, level: 7, spr: 145, frame: 2, sx: 8.0, sy: 8.0, dx: 170.0, dy: 120.0, tdx: 18.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 7!", str_id: 782, text_call: 26508, spr_call: 26608 }, // CODE 413 flamethrower view 1 level 7
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 1, level: 10, spr: 145, frame: 3, sx: 6.4, sy: 6.4, dx: 136.0, dy: 120.0, tdx: 16.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 10!", str_id: 783, text_call: 26688, spr_call: 26804 }, // CODE 413 flamethrower view 1 level 10
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 3, level: 4, spr: 145, frame: 1, sx: 8.0, sy: 8.0, dx: 246.0, dy: 160.0, tdx: 85.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 4!", str_id: 781, text_call: 26904, spr_call: 27004 }, // CODE 413 flamethrower view 3 level 4
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 3, level: 7, spr: 145, frame: 2, sx: 8.0, sy: 8.0, dx: 235.0, dy: 160.0, tdx: 85.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 7!", str_id: 782, text_call: 27084, spr_call: 27184 }, // CODE 413 flamethrower view 3 level 7
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 3, level: 10, spr: 145, frame: 3, sx: 8.0, sy: 8.0, dx: 195.0, dy: 170.0, tdx: 85.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 10!", str_id: 783, text_call: 27264, spr_call: 27364 }, // CODE 413 flamethrower view 3 level 10
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 4, level: 4, spr: 145, frame: 1, sx: 8.0, sy: 8.0, dx: 246.0, dy: 160.0, tdx: 85.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 4!", str_id: 781, text_call: 27464, spr_call: 27564 }, // CODE 413 flamethrower view 4 level 4
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 4, level: 7, spr: 145, frame: 2, sx: 8.0, sy: 8.0, dx: 235.0, dy: 160.0, tdx: 85.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 7!", str_id: 782, text_call: 27644, spr_call: 27744 }, // CODE 413 flamethrower view 4 level 7
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 4, level: 10, spr: 145, frame: 3, sx: 8.0, sy: 8.0, dx: 195.0, dy: 170.0, tdx: 85.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 10!", str_id: 783, text_call: 27824, spr_call: 27924 }, // CODE 413 flamethrower view 4 level 10
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 5, level: 4, spr: 145, frame: 1, sx: 8.0, sy: 8.0, dx: 222.0, dy: 120.0, tdx: 55.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 4!", str_id: 781, text_call: 28024, spr_call: 28124 }, // CODE 413 flamethrower view 5 level 4
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 5, level: 7, spr: 145, frame: 2, sx: 8.0, sy: 8.0, dx: 210.0, dy: 120.0, tdx: 55.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 7!", str_id: 782, text_call: 28204, spr_call: 28304 }, // CODE 413 flamethrower view 5 level 7
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 5, level: 10, spr: 145, frame: 3, sx: 7.0, sy: 7.0, dx: 170.0, dy: 130.0, tdx: 54.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 10!", str_id: 783, text_call: 28384, spr_call: 28484 }, // CODE 413 flamethrower view 5 level 10
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 6, level: 4, spr: 145, frame: 1, sx: 8.0, sy: 8.0, dx: 232.0, dy: 120.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 4!", str_id: 781, text_call: 28584, spr_call: 28684 }, // CODE 413 flamethrower view 6 level 4
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 6, level: 7, spr: 145, frame: 2, sx: 8.0, sy: 8.0, dx: 220.0, dy: 120.0, tdx: 65.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 7!", str_id: 782, text_call: 28764, spr_call: 28864 }, // CODE 413 flamethrower view 6 level 7
    WArm { weapon: "flamethrower", level_var: "flamethrowerlevel", view: 6, level: 10, spr: 145, frame: 3, sx: 6.0, sy: 6.0, dx: 190.0, dy: 130.0, tdx: 64.0, tdy: 30.0, color: -1, alpha: 1.0, text: "Your Flamethrower is now level 10!", str_id: 783, text_call: 28944, spr_call: 29044 }, // CODE 413 flamethrower view 6 level 10
    WArm { weapon: "bow", level_var: "bowlevel", view: 0, level: 4, spr: 146, frame: 1, sx: 5.6, sy: 5.6, dx: 230.0, dy: 130.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 4!", str_id: 784, text_call: 29204, spr_call: 29320 }, // CODE 413 bow view 0 level 4
    WArm { weapon: "bow", level_var: "bowlevel", view: 0, level: 7, spr: 146, frame: 2, sx: 5.6, sy: 5.6, dx: 230.0, dy: 130.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 7!", str_id: 785, text_call: 29400, spr_call: 29516 }, // CODE 413 bow view 0 level 7
    WArm { weapon: "bow", level_var: "bowlevel", view: 0, level: 10, spr: 146, frame: 3, sx: 5.2, sy: 5.2, dx: 225.0, dy: 130.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 10!", str_id: 786, text_call: 29596, spr_call: 29712 }, // CODE 413 bow view 0 level 10
    WArm { weapon: "bow", level_var: "bowlevel", view: 1, level: 4, spr: 146, frame: 1, sx: 5.0, sy: 5.0, dx: 190.0, dy: 120.0, tdx: 70.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 4!", str_id: 784, text_call: 29812, spr_call: 29912 }, // CODE 413 bow view 1 level 4
    WArm { weapon: "bow", level_var: "bowlevel", view: 1, level: 7, spr: 146, frame: 2, sx: 5.0, sy: 5.0, dx: 190.0, dy: 120.0, tdx: 70.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 7!", str_id: 785, text_call: 29992, spr_call: 30092 }, // CODE 413 bow view 1 level 7
    WArm { weapon: "bow", level_var: "bowlevel", view: 1, level: 10, spr: 146, frame: 3, sx: 5.0, sy: 5.0, dx: 190.0, dy: 130.0, tdx: 68.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 10!", str_id: 786, text_call: 30172, spr_call: 30272 }, // CODE 413 bow view 1 level 10
    WArm { weapon: "bow", level_var: "bowlevel", view: 3, level: 4, spr: 146, frame: 1, sx: 8.0, sy: 8.0, dx: 260.0, dy: 190.0, tdx: 140.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bow is now level 4!", str_id: 784, text_call: 30372, spr_call: 30472 }, // CODE 413 bow view 3 level 4
    WArm { weapon: "bow", level_var: "bowlevel", view: 3, level: 7, spr: 146, frame: 2, sx: 8.0, sy: 8.0, dx: 255.0, dy: 190.0, tdx: 140.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bow is now level 7!", str_id: 785, text_call: 30552, spr_call: 30652 }, // CODE 413 bow view 3 level 7
    WArm { weapon: "bow", level_var: "bowlevel", view: 3, level: 10, spr: 146, frame: 3, sx: 7.0, sy: 7.0, dx: 255.0, dy: 195.0, tdx: 140.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bow is now level 10!", str_id: 786, text_call: 30732, spr_call: 30832 }, // CODE 413 bow view 3 level 10
    WArm { weapon: "bow", level_var: "bowlevel", view: 4, level: 4, spr: 146, frame: 1, sx: 8.0, sy: 8.0, dx: 260.0, dy: 190.0, tdx: 140.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bow is now level 4!", str_id: 784, text_call: 30932, spr_call: 31032 }, // CODE 413 bow view 4 level 4
    WArm { weapon: "bow", level_var: "bowlevel", view: 4, level: 7, spr: 146, frame: 2, sx: 8.0, sy: 8.0, dx: 255.0, dy: 190.0, tdx: 140.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bow is now level 7!", str_id: 785, text_call: 31112, spr_call: 31212 }, // CODE 413 bow view 4 level 7
    WArm { weapon: "bow", level_var: "bowlevel", view: 4, level: 10, spr: 146, frame: 3, sx: 7.0, sy: 7.0, dx: 255.0, dy: 195.0, tdx: 140.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bow is now level 10!", str_id: 786, text_call: 31292, spr_call: 31392 }, // CODE 413 bow view 4 level 10
    WArm { weapon: "bow", level_var: "bowlevel", view: 5, level: 4, spr: 146, frame: 1, sx: 5.6, sy: 5.6, dx: 230.0, dy: 130.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 4!", str_id: 784, text_call: 31492, spr_call: 31608 }, // CODE 413 bow view 5 level 4
    WArm { weapon: "bow", level_var: "bowlevel", view: 5, level: 7, spr: 146, frame: 2, sx: 5.6, sy: 5.6, dx: 230.0, dy: 130.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 7!", str_id: 785, text_call: 31688, spr_call: 31804 }, // CODE 413 bow view 5 level 7
    WArm { weapon: "bow", level_var: "bowlevel", view: 5, level: 10, spr: 146, frame: 3, sx: 5.2, sy: 5.2, dx: 225.0, dy: 130.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 10!", str_id: 786, text_call: 31884, spr_call: 32000 }, // CODE 413 bow view 5 level 10
    WArm { weapon: "bow", level_var: "bowlevel", view: 6, level: 4, spr: 146, frame: 1, sx: 5.6, sy: 5.6, dx: 240.0, dy: 130.0, tdx: 110.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 4!", str_id: 784, text_call: 32100, spr_call: 32216 }, // CODE 413 bow view 6 level 4
    WArm { weapon: "bow", level_var: "bowlevel", view: 6, level: 7, spr: 146, frame: 2, sx: 5.6, sy: 5.6, dx: 240.0, dy: 130.0, tdx: 110.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 7!", str_id: 785, text_call: 32296, spr_call: 32412 }, // CODE 413 bow view 6 level 7
    WArm { weapon: "bow", level_var: "bowlevel", view: 6, level: 10, spr: 146, frame: 3, sx: 5.2, sy: 5.2, dx: 235.0, dy: 130.0, tdx: 110.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bow is now level 10!", str_id: 786, text_call: 32492, spr_call: 32608 }, // CODE 413 bow view 6 level 10
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 0, level: 4, spr: 140, frame: 1, sx: 8.0, sy: 8.0, dx: 138.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 4!", str_id: 787, text_call: 32768, spr_call: 32868 }, // CODE 413 bombgun view 0 level 4
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 0, level: 7, spr: 140, frame: 2, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 7!", str_id: 788, text_call: 32948, spr_call: 33048 }, // CODE 413 bombgun view 0 level 7
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 0, level: 10, spr: 140, frame: 3, sx: 8.0, sy: 8.0, dx: 95.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 10!", str_id: 789, text_call: 33128, spr_call: 33228 }, // CODE 413 bombgun view 0 level 10
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 1, level: 4, spr: 140, frame: 1, sx: 8.0, sy: 8.0, dx: 96.0, dy: 120.0, tdx: 36.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 4!", str_id: 787, text_call: 33328, spr_call: 33428 }, // CODE 413 bombgun view 1 level 4
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 1, level: 7, spr: 140, frame: 2, sx: 8.0, sy: 8.0, dx: 72.0, dy: 120.0, tdx: 36.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 7!", str_id: 788, text_call: 33508, spr_call: 33608 }, // CODE 413 bombgun view 1 level 7
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 1, level: 10, spr: 140, frame: 3, sx: 8.0, sy: 8.0, dx: 58.0, dy: 120.0, tdx: 31.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 10!", str_id: 789, text_call: 33688, spr_call: 33788 }, // CODE 413 bombgun view 1 level 10
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 3, level: 4, spr: 140, frame: 1, sx: 8.0, sy: 8.0, dx: 160.0, dy: 160.0, tdx: 98.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 4!", str_id: 787, text_call: 33888, spr_call: 33988 }, // CODE 413 bombgun view 3 level 4
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 3, level: 7, spr: 140, frame: 2, sx: 8.0, sy: 8.0, dx: 142.0, dy: 160.0, tdx: 98.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 7!", str_id: 788, text_call: 34068, spr_call: 34168 }, // CODE 413 bombgun view 3 level 7
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 3, level: 10, spr: 140, frame: 3, sx: 8.0, sy: 8.0, dx: 126.0, dy: 160.0, tdx: 96.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 10!", str_id: 789, text_call: 34248, spr_call: 34348 }, // CODE 413 bombgun view 3 level 10
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 4, level: 4, spr: 140, frame: 1, sx: 8.0, sy: 8.0, dx: 160.0, dy: 160.0, tdx: 98.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 4!", str_id: 787, text_call: 34448, spr_call: 34548 }, // CODE 413 bombgun view 4 level 4
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 4, level: 7, spr: 140, frame: 2, sx: 8.0, sy: 8.0, dx: 142.0, dy: 160.0, tdx: 98.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 7!", str_id: 788, text_call: 34628, spr_call: 34728 }, // CODE 413 bombgun view 4 level 7
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 4, level: 10, spr: 140, frame: 3, sx: 8.0, sy: 8.0, dx: 126.0, dy: 160.0, tdx: 96.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 10!", str_id: 789, text_call: 34808, spr_call: 34908 }, // CODE 413 bombgun view 4 level 10
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 5, level: 4, spr: 140, frame: 1, sx: 8.0, sy: 8.0, dx: 138.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 4!", str_id: 787, text_call: 35008, spr_call: 35108 }, // CODE 413 bombgun view 5 level 4
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 5, level: 7, spr: 140, frame: 2, sx: 8.0, sy: 8.0, dx: 120.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 7!", str_id: 788, text_call: 35188, spr_call: 35288 }, // CODE 413 bombgun view 5 level 7
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 5, level: 10, spr: 140, frame: 3, sx: 8.0, sy: 8.0, dx: 95.0, dy: 120.0, tdx: 80.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 10!", str_id: 789, text_call: 35368, spr_call: 35468 }, // CODE 413 bombgun view 5 level 10
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 6, level: 4, spr: 140, frame: 1, sx: 8.0, sy: 8.0, dx: 148.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 4!", str_id: 787, text_call: 35568, spr_call: 35668 }, // CODE 413 bombgun view 6 level 4
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 6, level: 7, spr: 140, frame: 2, sx: 8.0, sy: 8.0, dx: 130.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 7!", str_id: 788, text_call: 35748, spr_call: 35848 }, // CODE 413 bombgun view 6 level 7
    WArm { weapon: "bombgun", level_var: "bombgunlevel", view: 6, level: 10, spr: 140, frame: 3, sx: 8.0, sy: 8.0, dx: 105.0, dy: 120.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Bomb Gun is now level 10!", str_id: 789, text_call: 35928, spr_call: 36028 }, // CODE 413 bombgun view 6 level 10
    WArm { weapon: "laser", level_var: "laserlevel", view: 0, level: 4, spr: 137, frame: 1, sx: 8.0, sy: 8.0, dx: 204.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 4!", str_id: 790, text_call: 36188, spr_call: 36288 }, // CODE 413 laser view 0 level 4
    WArm { weapon: "laser", level_var: "laserlevel", view: 0, level: 7, spr: 137, frame: 2, sx: 8.0, sy: 8.0, dx: 188.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 7!", str_id: 791, text_call: 36368, spr_call: 36468 }, // CODE 413 laser view 0 level 7
    WArm { weapon: "laser", level_var: "laserlevel", view: 0, level: 10, spr: 137, frame: 3, sx: 8.0, sy: 8.0, dx: 174.0, dy: 120.0, tdx: 88.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 10!", str_id: 792, text_call: 36548, spr_call: 36648 }, // CODE 413 laser view 0 level 10
    WArm { weapon: "laser", level_var: "laserlevel", view: 1, level: 4, spr: 137, frame: 1, sx: 8.0, sy: 8.0, dx: 162.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 4!", str_id: 790, text_call: 36748, spr_call: 36848 }, // CODE 413 laser view 1 level 4
    WArm { weapon: "laser", level_var: "laserlevel", view: 1, level: 7, spr: 137, frame: 2, sx: 8.0, sy: 8.0, dx: 148.0, dy: 120.0, tdx: 60.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 7!", str_id: 791, text_call: 36928, spr_call: 37028 }, // CODE 413 laser view 1 level 7
    WArm { weapon: "laser", level_var: "laserlevel", view: 1, level: 10, spr: 137, frame: 3, sx: 8.0, sy: 8.0, dx: 134.0, dy: 120.0, tdx: 58.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 10!", str_id: 792, text_call: 37108, spr_call: 37208 }, // CODE 413 laser view 1 level 10
    WArm { weapon: "laser", level_var: "laserlevel", view: 3, level: 4, spr: 137, frame: 1, sx: 10.0, sy: 10.0, dx: 225.0, dy: 160.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Laser is now level 4!", str_id: 790, text_call: 37308, spr_call: 37408 }, // CODE 413 laser view 3 level 4
    WArm { weapon: "laser", level_var: "laserlevel", view: 3, level: 7, spr: 137, frame: 2, sx: 10.0, sy: 10.0, dx: 206.0, dy: 160.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Laser is now level 7!", str_id: 791, text_call: 37488, spr_call: 37588 }, // CODE 413 laser view 3 level 7
    WArm { weapon: "laser", level_var: "laserlevel", view: 3, level: 10, spr: 137, frame: 3, sx: 10.0, sy: 10.0, dx: 188.0, dy: 160.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Laser is now level 10!", str_id: 792, text_call: 37668, spr_call: 37768 }, // CODE 413 laser view 3 level 10
    WArm { weapon: "laser", level_var: "laserlevel", view: 4, level: 4, spr: 137, frame: 1, sx: 10.0, sy: 10.0, dx: 225.0, dy: 160.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Laser is now level 4!", str_id: 790, text_call: 37868, spr_call: 37968 }, // CODE 413 laser view 4 level 4
    WArm { weapon: "laser", level_var: "laserlevel", view: 4, level: 7, spr: 137, frame: 2, sx: 10.0, sy: 10.0, dx: 206.0, dy: 160.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Laser is now level 7!", str_id: 791, text_call: 38048, spr_call: 38148 }, // CODE 413 laser view 4 level 7
    WArm { weapon: "laser", level_var: "laserlevel", view: 4, level: 10, spr: 137, frame: 3, sx: 10.0, sy: 10.0, dx: 188.0, dy: 160.0, tdx: 125.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Laser is now level 10!", str_id: 792, text_call: 38228, spr_call: 38328 }, // CODE 413 laser view 4 level 10
    WArm { weapon: "laser", level_var: "laserlevel", view: 5, level: 4, spr: 137, frame: 1, sx: 8.0, sy: 8.0, dx: 204.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 4!", str_id: 790, text_call: 38428, spr_call: 38528 }, // CODE 413 laser view 5 level 4
    WArm { weapon: "laser", level_var: "laserlevel", view: 5, level: 7, spr: 137, frame: 2, sx: 8.0, sy: 8.0, dx: 188.0, dy: 120.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 7!", str_id: 791, text_call: 38608, spr_call: 38708 }, // CODE 413 laser view 5 level 7
    WArm { weapon: "laser", level_var: "laserlevel", view: 5, level: 10, spr: 137, frame: 3, sx: 8.0, sy: 8.0, dx: 174.0, dy: 120.0, tdx: 88.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 10!", str_id: 792, text_call: 38788, spr_call: 38888 }, // CODE 413 laser view 5 level 10
    WArm { weapon: "laser", level_var: "laserlevel", view: 6, level: 4, spr: 137, frame: 1, sx: 8.0, sy: 8.0, dx: 214.0, dy: 120.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 4!", str_id: 790, text_call: 38988, spr_call: 39088 }, // CODE 413 laser view 6 level 4
    WArm { weapon: "laser", level_var: "laserlevel", view: 6, level: 7, spr: 137, frame: 2, sx: 8.0, sy: 8.0, dx: 198.0, dy: 120.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 7!", str_id: 791, text_call: 39168, spr_call: 39268 }, // CODE 413 laser view 6 level 7
    WArm { weapon: "laser", level_var: "laserlevel", view: 6, level: 10, spr: 137, frame: 3, sx: 8.0, sy: 8.0, dx: 184.0, dy: 120.0, tdx: 98.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Laser is now level 10!", str_id: 792, text_call: 39348, spr_call: 39448 }, // CODE 413 laser view 6 level 10
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 0, level: 4, spr: 135, frame: 1, sx: 8.0, sy: 8.0, dx: 150.0, dy: 180.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 4!", str_id: 793, text_call: 39608, spr_call: 39708 }, // CODE 413 icegun view 0 level 4
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 0, level: 7, spr: 135, frame: 2, sx: 8.0, sy: 8.0, dx: 130.0, dy: 180.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 7!", str_id: 794, text_call: 39788, spr_call: 39888 }, // CODE 413 icegun view 0 level 7
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 0, level: 10, spr: 135, frame: 3, sx: 8.0, sy: 8.0, dx: 100.0, dy: 180.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 10!", str_id: 795, text_call: 39968, spr_call: 40068 }, // CODE 413 icegun view 0 level 10
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 1, level: 4, spr: 135, frame: 1, sx: 8.0, sy: 8.0, dx: 108.0, dy: 180.0, tdx: 58.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 4!", str_id: 793, text_call: 40168, spr_call: 40268 }, // CODE 413 icegun view 1 level 4
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 1, level: 7, spr: 135, frame: 2, sx: 8.0, sy: 8.0, dx: 92.0, dy: 180.0, tdx: 58.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 7!", str_id: 794, text_call: 40348, spr_call: 40448 }, // CODE 413 icegun view 1 level 7
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 1, level: 10, spr: 135, frame: 3, sx: 8.0, sy: 8.0, dx: 64.0, dy: 180.0, tdx: 54.0, tdy: 18.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 10!", str_id: 795, text_call: 40528, spr_call: 40628 }, // CODE 413 icegun view 1 level 10
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 3, level: 4, spr: 135, frame: 1, sx: 10.0, sy: 10.0, dx: 150.0, dy: 240.0, tdx: 120.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 4!", str_id: 793, text_call: 40728, spr_call: 40828 }, // CODE 413 icegun view 3 level 4
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 3, level: 7, spr: 135, frame: 2, sx: 10.0, sy: 10.0, dx: 130.0, dy: 240.0, tdx: 120.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 7!", str_id: 794, text_call: 40908, spr_call: 41008 }, // CODE 413 icegun view 3 level 7
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 3, level: 10, spr: 135, frame: 3, sx: 10.0, sy: 10.0, dx: 100.0, dy: 240.0, tdx: 120.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 10!", str_id: 795, text_call: 41088, spr_call: 41188 }, // CODE 413 icegun view 3 level 10
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 4, level: 4, spr: 135, frame: 1, sx: 10.0, sy: 10.0, dx: 150.0, dy: 240.0, tdx: 120.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 4!", str_id: 793, text_call: 41288, spr_call: 41388 }, // CODE 413 icegun view 4 level 4
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 4, level: 7, spr: 135, frame: 2, sx: 10.0, sy: 10.0, dx: 130.0, dy: 240.0, tdx: 120.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 7!", str_id: 794, text_call: 41468, spr_call: 41568 }, // CODE 413 icegun view 4 level 7
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 4, level: 10, spr: 135, frame: 3, sx: 10.0, sy: 10.0, dx: 100.0, dy: 240.0, tdx: 120.0, tdy: 50.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 10!", str_id: 795, text_call: 41648, spr_call: 41748 }, // CODE 413 icegun view 4 level 10
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 5, level: 4, spr: 135, frame: 1, sx: 8.0, sy: 8.0, dx: 150.0, dy: 180.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 4!", str_id: 793, text_call: 41848, spr_call: 41948 }, // CODE 413 icegun view 5 level 4
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 5, level: 7, spr: 135, frame: 2, sx: 8.0, sy: 8.0, dx: 130.0, dy: 180.0, tdx: 92.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 7!", str_id: 794, text_call: 42028, spr_call: 42128 }, // CODE 413 icegun view 5 level 7
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 5, level: 10, spr: 135, frame: 3, sx: 8.0, sy: 8.0, dx: 100.0, dy: 180.0, tdx: 90.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 10!", str_id: 795, text_call: 42208, spr_call: 42308 }, // CODE 413 icegun view 5 level 10
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 6, level: 4, spr: 135, frame: 1, sx: 8.0, sy: 8.0, dx: 160.0, dy: 180.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 4!", str_id: 793, text_call: 42408, spr_call: 42508 }, // CODE 413 icegun view 6 level 4
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 6, level: 7, spr: 135, frame: 2, sx: 8.0, sy: 8.0, dx: 140.0, dy: 180.0, tdx: 102.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 7!", str_id: 794, text_call: 42588, spr_call: 42688 }, // CODE 413 icegun view 6 level 7
    WArm { weapon: "icegun", level_var: "icegunlevel", view: 6, level: 10, spr: 135, frame: 3, sx: 8.0, sy: 8.0, dx: 110.0, dy: 180.0, tdx: 100.0, tdy: 20.0, color: -1, alpha: 1.0, text: "Your Icegun is now level 10!", str_id: 795, text_call: 42768, spr_call: 42868 }, // CODE 413 icegun view 6 level 10
];

// census: 216 weapon arms, 6 pause arms, 222 draw_sprite_ext sites, 222 draw_text sites
// unique (text_call, spr_call) pairs: 216
// distinct visual tuples among weapon arms: 143
// visual tuples shared by >1 arm: 70
//    (125, 1, 8.0, 8.0, 92.0, 20.0, 757) -> [('pistol', 0, 4), ('pistol', 5, 4)]
//    (125, 2, 8.0, 8.0, 92.0, 20.0, 758) -> [('pistol', 0, 7), ('pistol', 5, 7)]
//    (125, 3, 8.0, 8.0, 92.0, 20.0, 759) -> [('pistol', 0, 10), ('pistol', 5, 10)]
//    (125, 1, 10.0, 10.0, 125.0, 50.0, 757) -> [('pistol', 3, 4), ('pistol', 4, 4)]
//    (125, 2, 10.0, 10.0, 125.0, 50.0, 758) -> [('pistol', 3, 7), ('pistol', 4, 7)]
//    (125, 3, 10.0, 10.0, 125.0, 50.0, 759) -> [('pistol', 3, 10), ('pistol', 4, 10)]

// ---- fixture ---------------------------------------------------------------

/// The IR carries string *ids* only: `draw_text`'s third argument is a pooled
/// reference that only resolves once the shipped STRG table is attached, so the
/// fixture parses `assets/game.droid` exactly like the other draw suites do.
/// Without it every banner text would read back as `1099511627776 + str_id`.
fn bundle() -> Bundle {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = callys_asset::GameDroidAsset::parse(root.join("../../assets/game.droid"))
        .expect("parse game.droid");
    let mut b = load_bundle_from_file(&root.join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
    b.string_table = asset.string_table.clone();
    b
}

/// A bare scene with the six camera origins configured. No room is loaded: the
/// overlay's Create (CODE 409) deactivates every other instance, so the only
/// thing any Draw can come from is the overlay itself, and nothing but CODE 413
/// can contribute to `s.draws`/`s.texts`.
fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    for &(v, x, y) in VIEW_POS.iter() {
        s.view_positions.insert(v, (x, y));
    }
    // View 2 is not in the draw table, but a camera still exists for it in a
    // real room: the negative test drives a live view whose arms are absent,
    // which is stronger than asking the engine to draw an unconfigured one.
    s.view_positions.insert(2, (210.0, 502.0));
    s
}

fn view_pos(view: i32) -> (f64, f64) {
    VIEW_POS
        .iter()
        .find(|p| p.0 == view)
        .map(|p| (p.1, p.2))
        .unwrap_or_else(|| panic!("view {view} is not in the shipped table"))
}

/// Arms exactly the listed families and disarms every other one.
///
/// `init_fresh_start_globals` ships `pistol == 1` and all twelve levels at 1, so
/// the whole family vector is pinned on every call: an "unarmed" cell must not
/// inherit the pistol default, and level 1 matches none of the three tiers.
fn arm(s: &mut Scene, on: &[(&str, f64)]) {
    for &(flag, lvl) in FAMILIES.iter() {
        s.globals.insert(flag.into(), 0.0);
        s.globals.insert(lvl.into(), 1.0);
    }
    for &(flag, level) in on {
        let lvl = FAMILIES
            .iter()
            .find(|f| f.0 == flag)
            .unwrap_or_else(|| panic!("unknown weapon family {flag}"))
            .1;
        s.globals.insert(flag.into(), 1.0);
        s.globals.insert(lvl.into(), level);
    }
}

/// Real path: `s.create` runs CODE 409 Create, which pauses audio, deactivates
/// the rest of the world, lands `taplock = 0` and arms alarm[0] = 70.
fn spawn(b: &Bundle, s: &mut Scene) -> i32 {
    s.create(b, OVERLAY, INST_X, INST_Y)
        .expect("CODE 413 obj_weaponchange Create (CODE 409)")
}

/// The field CODE 411 flips when the taplock timer expires. Writing it directly
/// keeps the 222-cell sweep cheap; `the_taplock_timer_arms_the_prompt_...`
/// drives the real alarm to prove the field is not just settable.
fn set_taplock(s: &mut Scene, id: i32, value: f64) {
    s.instances
        .get_mut(&id)
        .expect("overlay instance")
        .fields
        .insert("taplock".into(), value);
}

fn draws_from(s: &Scene, code: usize) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.code == code).cloned().collect()
}

fn texts_from(s: &Scene, code: usize) -> Vec<TextCommand> {
    s.texts.iter().filter(|t| t.code == code).cloned().collect()
}

/// Every instruction the VM entered for CODE 413, as CODE-relative offsets, in
/// execution order (the engine's own ledger, not a re-interpretation).
fn ledger(s: &Scene) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(code, _)| *code == CODE)
        .map(|(_, off)| off - CODE_START)
        .collect()
}

/// The 444 draw call sites the embedded table claims, sorted. Any ledger
/// intersection with this set is a draw arm that actually ran.
fn table_sites() -> Vec<usize> {
    let mut v: Vec<usize> = PAUSE_ARMS
        .iter()
        .map(|a| a.spr_call)
        .chain(PAUSE_ARMS.iter().map(|a| a.text_call))
        .chain(W_ARMS.iter().map(|a| a.spr_call))
        .chain(W_ARMS.iter().map(|a| a.text_call))
        .collect();
    v.sort_unstable();
    v
}

/// Which draw arms ran, in execution order. Nothing else can appear here: only
/// these offsets are draw calls in the whole body (proved by the bijection in
/// the census test), so an empty result means literally no draw happened.
fn sites_ran(s: &Scene) -> Vec<usize> {
    let all = table_sites();
    ledger(s).into_iter().filter(|o| all.contains(o)).collect()
}

/// Call sites of one builtin inside CODE 413, from the bundle the engine loads.
fn call_sites(b: &Bundle, name: &str) -> Vec<usize> {
    b.codes
        .iter()
        .find(|c| c.id == CODE)
        .expect("CODE 413 present")
        .instructions
        .iter()
        .filter(|i| matches!(&i.op, Op::Call { name: n, .. } if n.as_str() == name))
        .map(|i| i.code_offset)
        .collect()
}

/// Full assertion for one sheet arm: the whole draw tuple plus the ledger key.
/// Returns nothing - every field is pinned, so a false pass is impossible.
fn expect_sheet(s: &Scene, p: &PauseArm, id: i32) {
    let (vx, vy) = view_pos(p.view);
    let d = draws_from(s, CODE);
    let sheet = d.first().unwrap_or_else(|| {
        panic!(
            "CODE 413 pause view {}: the sheet must be the first draw of the body",
            p.view
        )
    });
    assert_eq!(
        (sheet.sprite, sheet.frame),
        (p.spr, f64::from(p.frame)),
        "CODE 413 pause view {}: spr_pause / frame",
        p.view
    );
    assert_eq!(
        (sheet.x, sheet.y),
        (vx - 1.0, vy),
        "CODE 413 pause view {}: the sheet sits at view_xview[{0}] - 1, view_yview[{0}] \
         (origin {vx}, {vy})",
        p.view
    );
    assert_eq!(
        (sheet.scale_x, sheet.scale_y),
        (p.sx, p.sy),
        "CODE 413 pause view {}: the sheet's own scale pair",
        p.view
    );
    assert_eq!(
        (sheet.rotation, sheet.color, sheet.alpha),
        (0.0, p.color, p.alpha),
        "CODE 413 pause view {}: rotation / blend / alpha",
        p.view
    );
    assert_eq!(
        (sheet.view, sheet.instance),
        (p.view, id),
        "CODE 413 pause view {}: drawn into its own view, by the overlay itself",
        p.view
    );
    assert_eq!(
        sheet.offset,
        CODE_START + p.spr_call,
        "CODE 413 pause view {}: the sheet draw is the table's own call site",
        p.view
    );
}

/// Full assertion for one banner arm: text literal + position + font/colour,
/// sprite tuple, and both ledger keys.
fn expect_banner(s: &Scene, a: &WArm) {
    let d = draws_from(s, CODE);
    assert_eq!(
        d.len(),
        2,
        "CODE 413 {} view {} level {}: sheet + one banner, nothing else",
        a.weapon,
        a.view,
        a.level
    );
    let ban = &d[1];
    assert_eq!(
        ban.sprite, a.spr,
        "CODE 413 {} view {} level {}: gun sprite id",
        a.weapon, a.view, a.level
    );
    assert_eq!(
        (ban.frame, ban.scale_x, ban.scale_y),
        (f64::from(a.frame), a.sx, a.sy),
        "CODE 413 {} view {} level {}: frame / scale",
        a.weapon,
        a.view,
        a.level
    );
    assert_eq!(
        (ban.x, ban.y),
        (INST_X + a.dx, INST_Y + a.dy),
        "CODE 413 {} view {} level {}: banner anchored to the overlay's own x/y",
        a.weapon,
        a.view,
        a.level
    );
    assert_eq!(
        (ban.rotation, ban.color, ban.alpha),
        (0.0, a.color, a.alpha),
        "CODE 413 {} view {} level {}: rotation / blend / alpha",
        a.weapon,
        a.view,
        a.level
    );
    assert_eq!(
        ban.offset,
        CODE_START + a.spr_call,
        "CODE 413 {} view {} level {}: banner draw call site",
        a.weapon,
        a.view,
        a.level
    );

    let t = texts_from(s, CODE);
    assert_eq!(
        t.len(),
        1,
        "CODE 413 {} view {} level {}: taplock is 0 here, so only the banner text",
        a.weapon,
        a.view,
        a.level
    );
    let txt = &t[0];
    assert_eq!(
        txt.text, a.text,
        "CODE 413 {} view {} level {}: banner wording (STRG {})",
        a.weapon, a.view, a.level, a.str_id
    );
    assert_eq!(
        (txt.x, txt.y),
        (INST_X + a.tdx, INST_Y + a.tdy),
        "CODE 413 {} view {} level {}: banner text offset",
        a.weapon,
        a.view,
        a.level
    );
    assert_eq!(
        (txt.font, txt.color),
        (FONT1, C_WHITE),
        "CODE 413 {} view {} level {}: draw_set_font(font1) + draw_set_color(c_white)",
        a.weapon,
        a.view,
        a.level
    );
    assert_eq!(
        txt.offset,
        CODE_START + a.text_call,
        "CODE 413 {} view {} level {}: banner text call site",
        a.weapon,
        a.view,
        a.level
    );
}

// ---- the census: does the table describe the body that is loaded? ----------

#[test]
// CODE 413
fn the_embedded_table_is_a_bijection_onto_the_bodys_four_hundred_forty_four_draw_calls() {
    let b = bundle();
    let body = b
        .codes
        .iter()
        .find(|c| c.id == CODE)
        .expect("CODE 413 in bundle");

    // The table was extracted from one specific body; if the IR is regenerated
    // and this span moves, every offset below is meaningless.
    assert_eq!(body.start, CODE_START, "CODE 413 start offset");
    assert_eq!(body.end, CODE_END, "CODE 413 end offset");
    assert_eq!(body.instructions.len(), N_INS, "CODE 413 instruction count");

    let mut sprs = Vec::new();
    let mut txts = Vec::new();
    let mut fonts = 0usize;
    let mut colors = 0usize;
    let mut cmps = 0usize;
    let mut bfs = 0usize;
    let mut branches = 0usize;
    let mut loads_view_current = 0usize;
    let mut loads_xview = 0usize;
    let mut loads_yview = 0usize;
    let mut loads_taplock = 0usize;
    let mut loads_x = 0usize;
    let mut loads_y = 0usize;
    let mut loads_flag = 0usize;
    let mut loads_level = 0usize;
    for i in &body.instructions {
        match &i.op {
            Op::Call { name, argc } => match name.as_str() {
                "draw_sprite_ext" => {
                    assert_eq!(*argc, 9, "CODE 413 draw_sprite_ext arity");
                    sprs.push(i.code_offset);
                }
                "draw_text" => {
                    assert_eq!(*argc, 3, "CODE 413 draw_text arity");
                    txts.push(i.code_offset);
                }
                "draw_set_font" => {
                    assert_eq!(*argc, 1);
                    fonts += 1;
                }
                "draw_set_color" => {
                    assert_eq!(*argc, 1);
                    colors += 1;
                }
                other => panic!("CODE 413 has an unexpected builtin call: {other}"),
            },
            Op::Cmp { comparison } => {
                assert_eq!(
                    *comparison, 3,
                    "CODE 413: every single test in this body is an equality"
                );
                cmps += 1;
            }
            Op::Bf { .. } => bfs += 1,
            Op::B { .. } => branches += 1,
            Op::Load { name, .. } => match name.as_str() {
                "view_current" => loads_view_current += 1,
                "view_xview" => loads_xview += 1,
                "view_yview" => loads_yview += 1,
                "taplock" => loads_taplock += 1,
                "x" => loads_x += 1,
                "y" => loads_y += 1,
                n if FAMILIES.iter().any(|f| f.0 == n) => loads_flag += 1,
                n if FAMILIES.iter().any(|f| f.1 == n) => loads_level += 1,
                other => panic!("CODE 413 reads an unexpected variable: {other}"),
            },
            _ => {}
        }
    }

    // 222 sheet+banner sprites, 222 matching texts, 18 font/colour sets
    // (6 sheet blocks + 12 families), and the 312-arm test count.
    assert_eq!(sprs.len(), 222, "CODE 413 draw_sprite_ext call sites");
    assert_eq!(txts.len(), 222, "CODE 413 draw_text call sites");
    assert_eq!(
        fonts, 18,
        "CODE 413 draw_set_font sites (6 views + 12 families)"
    );
    assert_eq!(colors, 18, "CODE 413 draw_set_color sites");
    assert_eq!(cmps, 312, "CODE 413 equality tests");
    assert_eq!(bfs, 312, "every test guards a `bf`");
    assert_eq!(branches, 204, "204 `b` jumps leave the else-if chains");
    assert_eq!(
        loads_view_current, 78,
        "6 sheet tests + 72 banner view tests"
    );
    assert_eq!(loads_xview, 12, "6 sheets + 6 prompts read view_xview");
    assert_eq!(loads_yview, 12, "6 sheets + 6 prompts read view_yview");
    assert_eq!(loads_taplock, 6, "one taplock gate per sheet block");
    // Every banner reads the overlay's own x and y once for the text and once
    // for the sprite - the anchor is the instance, never a view.
    assert_eq!(loads_x, 432, "216 banner texts + 216 banner sprites read x");
    assert_eq!(loads_y, 432, "216 banner texts + 216 banner sprites read y");
    assert_eq!(loads_flag, 12, "one global flag test per family");
    assert_eq!(loads_level, 216, "12 families x 6 views x 3 tiers");

    // The table must be exactly the body's call sites: no invented row, no
    // unpinned arm, and no duplicate claim on one instruction.
    let mut table_spr: Vec<usize> = PAUSE_ARMS
        .iter()
        .map(|a| a.spr_call)
        .chain(W_ARMS.iter().map(|a| a.spr_call))
        .collect();
    let mut table_txt: Vec<usize> = PAUSE_ARMS
        .iter()
        .map(|a| a.text_call)
        .chain(W_ARMS.iter().map(|a| a.text_call))
        .collect();
    table_spr.sort_unstable();
    table_txt.sort_unstable();
    assert_eq!(
        table_spr, sprs,
        "CODE 413: every draw_sprite_ext site is one table arm, exactly once"
    );
    assert_eq!(
        table_txt, txts,
        "CODE 413: every draw_text site is one table arm, exactly once"
    );

    // Arm census: the full 12 x 6 x 3 cross product, one row each.
    assert_eq!(PAUSE_ARMS.len(), 6, "six sheet arms");
    assert_eq!(W_ARMS.len(), 216, "12 families x 6 views x 3 tiers");
    for fam in FAMILIES.iter() {
        let rows: Vec<&WArm> = W_ARMS.iter().filter(|a| a.weapon == fam.0).collect();
        assert_eq!(rows.len(), 18, "CODE 413 {}: 6 views x 3 tiers", fam.0);
        for view in [0, 1, 3, 4, 5, 6] {
            for level in [4, 7, 10] {
                assert_eq!(
                    rows.iter()
                        .filter(|a| a.view == view && a.level == level)
                        .count(),
                    1,
                    "CODE 413 {} view {view} level {level}: exactly one arm",
                    fam.0
                );
            }
        }
        assert!(
            rows.iter().all(|a| a.level_var == fam.1),
            "CODE 413 {}: every arm reads its own level global {}",
            fam.0,
            fam.1
        );
        let sprites: BTreeSet<i32> = rows.iter().map(|a| a.spr).collect();
        assert_eq!(
            sprites.len(),
            1,
            "CODE 413 {}: one gun sprite across all 18 arms: {sprites:?}",
            fam.0
        );
    }

    // The view 2 hole is real: it exists in neither the sheet table nor any
    // family table. This is the gap the task called out, pinned as shipped
    // behaviour rather than assumed.
    assert!(
        !PAUSE_ARMS.iter().any(|a| a.view == 2),
        "CODE 413: no sheet arm for view 2"
    );
    assert!(
        !W_ARMS.iter().any(|a| a.view == 2),
        "CODE 413: no banner arm for view 2"
    );
    let views: Vec<i32> = PAUSE_ARMS.iter().map(|a| a.view).collect();
    assert_eq!(
        views,
        vec![0, 1, 3, 4, 5, 6],
        "CODE 413: sheet arms in bytecode order"
    );

    // Tier -> frame law: level 4/7/10 always picks subimage 1/2/3.
    for a in W_ARMS.iter() {
        let want = match a.level {
            4 => 1,
            7 => 2,
            10 => 3,
            other => panic!("CODE 413 {}: unexpected tier {other}", a.weapon),
        };
        assert_eq!(
            a.frame, want,
            "CODE 413 {} view {} level {}: tier selects subimage {want}",
            a.weapon, a.view, a.level
        );
    }

    // 12 gun sprites + spr_pause(123) = 13 distinct sprite ids across the body.
    let mut all_sprites: BTreeSet<i32> = W_ARMS.iter().map(|a| a.spr).collect();
    all_sprites.extend(PAUSE_ARMS.iter().map(|a| a.spr));
    assert_eq!(
        all_sprites.len(),
        13,
        "CODE 413 draws 12 gun sprites plus spr_pause: {all_sprites:?}"
    );
    assert!(
        PAUSE_ARMS.iter().all(|a| a.spr == 123),
        "CODE 413: every sheet arm is spr_pause 123"
    );
    // One literal for all six sheet arms: STRG 743, "Tap to Continue".
    let pause_strings: BTreeSet<u32> = PAUSE_ARMS.iter().map(|a| a.str_id).collect();
    assert_eq!(
        pause_strings,
        BTreeSet::from([743u32]),
        "CODE 413: all six sheet arms draw the same prompt literal (STRG 743)"
    );
    assert!(
        PAUSE_ARMS
            .iter()
            .all(|a| a.frame == 1 && a.alpha == 1.0 && a.color == -1),
        "CODE 413: every sheet arm is frame 1, alpha 1, blend -1"
    );
}

#[test]
// CODE 413
fn visually_identical_arms_stay_separate_rows_with_their_own_call_sites() {
    // The shipped table repeats itself on purpose: several (family, view, tier)
    // combinations draw the exact same pixels. Folding them into one row would
    // be a coverage lie, so the duplicates are counted and each member is
    // required to keep its own call site.
    let same = |a: &WArm, b: &WArm| {
        a.spr == b.spr
            && a.frame == b.frame
            && a.sx == b.sx
            && a.sy == b.sy
            && a.dx == b.dx
            && a.dy == b.dy
            && a.tdx == b.tdx
            && a.tdy == b.tdy
            && a.str_id == b.str_id
            && a.color == b.color
            && a.alpha == b.alpha
    };
    let mut groups: Vec<Vec<usize>> = Vec::new();
    for (i, a) in W_ARMS.iter().enumerate() {
        match groups.iter_mut().find(|g| same(&W_ARMS[g[0]], a)) {
            Some(g) => g.push(i),
            None => groups.push(vec![i]),
        }
    }
    assert_eq!(
        groups.len(),
        145,
        "CODE 413: 216 banner arms collapse to 145 distinct visual tuples"
    );
    assert_eq!(
        groups.iter().filter(|g| g.len() > 1).count(),
        70,
        "70 visual tuples are drawn by more than one arm"
    );
    for g in groups.iter().filter(|g| g.len() > 1) {
        let sites: BTreeSet<(usize, usize)> = g
            .iter()
            .map(|&i| (W_ARMS[i].text_call, W_ARMS[i].spr_call))
            .collect();
        assert_eq!(
            sites.len(),
            g.len(),
            "CODE 413: duplicate visual rows still execute different instructions: {:?}",
            g.iter()
                .map(|&i| (W_ARMS[i].weapon, W_ARMS[i].view, W_ARMS[i].level))
                .collect::<Vec<_>>()
        );
    }

    // The sharpest duplicate: spikegun level 4 draws the same tuple in views 0,
    // 5 and 6 (x+75, y+20, sprite at x+130, y+120, scale 8) - three arms, three
    // call sites, one picture.
    let spike: Vec<&WArm> = W_ARMS
        .iter()
        .filter(|a| a.weapon == "spikegun" && a.level == 4 && [0, 5, 6].contains(&a.view))
        .collect();
    assert_eq!(spike.len(), 3);
    for a in &spike {
        assert_eq!(
            (a.spr, a.frame, a.sx, a.sy, a.dx, a.dy, a.tdx, a.tdy, a.str_id),
            (142, 1, 8.0, 8.0, 130.0, 120.0, 75.0, 20.0, 766),
            "CODE 413 spikegun view {} level 4 tuple",
            a.view
        );
    }
    assert_eq!(
        spike
            .iter()
            .map(|a| a.spr_call)
            .collect::<BTreeSet<_>>()
            .len(),
        3,
        "CODE 413: the three identical spikegun level-4 arms are three distinct draw sites"
    );

    // ...and the counter-example: bladegun views 3 and 4 differ ONLY in the
    // text x offset (104 vs 100), so "identical view" is not a safe assumption.
    let b3 = W_ARMS
        .iter()
        .find(|a| a.weapon == "bladegun" && a.view == 3 && a.level == 4)
        .unwrap();
    let b4 = W_ARMS
        .iter()
        .find(|a| a.weapon == "bladegun" && a.view == 4 && a.level == 4)
        .unwrap();
    assert_eq!(
        (b3.spr, b3.frame, b3.dx, b3.dy),
        (b4.spr, b4.frame, b4.dx, b4.dy),
        "CODE 413 bladegun views 3/4 level 4 share the sprite tuple"
    );
    assert_eq!(
        (b3.tdx, b4.tdx),
        (104.0, 100.0),
        "CODE 413 bladegun views 3/4 level 4 differ in the text offset"
    );
    assert_eq!((b3.tdy, b4.tdy), (50.0, 50.0));

    // The sheet table has its own duplicate: views 3 and 4 are identical in
    // scale AND prompt offset, and differ only by which view origin anchors
    // them - so the arm split is the view, never the picture.
    let p3 = PAUSE_ARMS.iter().find(|a| a.view == 3).unwrap();
    let p4 = PAUSE_ARMS.iter().find(|a| a.view == 4).unwrap();
    assert_eq!(
        (p3.spr, p3.frame, p3.sx, p3.sy, p3.tdx, p3.tdy),
        (p4.spr, p4.frame, p4.sx, p4.sy, p4.tdx, p4.tdy),
        "CODE 413: sheet views 3 and 4 draw the same picture"
    );
    let sheet_scales: BTreeSet<(u64, u64)> = PAUSE_ARMS
        .iter()
        .map(|a| (a.sx.to_bits(), a.sy.to_bits()))
        .collect();
    assert_eq!(
        sheet_scales.len(),
        5,
        "CODE 413: six sheet arms use five distinct scale pairs (3 and 4 share one)"
    );
}

#[test]
// CODE 413
fn every_one_of_the_444_call_sites_executes_at_least_once() {
    // One sweep, one purpose: prove the suite really reaches all 222 sprites
    // and all 222 texts, rather than inferring it from the row count.
    let b = bundle();
    let mut hit: BTreeSet<usize> = BTreeSet::new();
    for p in PAUSE_ARMS.iter() {
        for taplock in [0.0, 1.0] {
            let mut s = scene(&b);
            arm(&mut s, &[]);
            let id = spawn(&b, &mut s);
            set_taplock(&mut s, id, taplock);
            s.draw_view(&b, p.view).unwrap();
            hit.extend(sites_ran(&s));
        }
    }
    for a in W_ARMS.iter() {
        let mut s = scene(&b);
        arm(&mut s, &[(a.weapon, f64::from(a.level))]);
        spawn(&b, &mut s);
        s.draw_view(&b, a.view).unwrap();
        hit.extend(sites_ran(&s));
    }
    let all: BTreeSet<usize> = table_sites().into_iter().collect();
    assert_eq!(all.len(), 444, "CODE 413: 222 draws + 222 texts");
    assert_eq!(
        hit.len(),
        444,
        "CODE 413: every table site must run; missing {:?}",
        all.difference(&hit).collect::<Vec<_>>()
    );
}

// ---- the sheet: six view arms ---------------------------------------------

#[test]
// CODE 413
fn every_pause_view_arm_draws_the_sheet_and_gates_the_prompt_on_taplock() {
    let b = bundle();
    let mut cells = 0usize;
    for p in PAUSE_ARMS.iter() {
        for taplock in [0.0, 1.0] {
            let mut s = scene(&b);
            arm(&mut s, &[]);
            let id = spawn(&b, &mut s);
            set_taplock(&mut s, id, taplock);
            s.executed.clear();
            s.draw_view(&b, p.view).unwrap();

            // No family armed, so exactly one sprite: the sheet, and nothing
            // else in the body can draw.
            let d = draws_from(&s, CODE);
            assert_eq!(
                d.len(),
                1,
                "CODE 413 pause view {} taplock {taplock}: sheet only",
                p.view
            );
            expect_sheet(&s, p, id);

            let t = texts_from(&s, CODE);
            if taplock == 1.0 {
                let (vx, vy) = view_pos(p.view);
                assert_eq!(t.len(), 1, "CODE 413 pause view {}: the prompt", p.view);
                assert_eq!(
                    (t[0].x, t[0].y),
                    (vx + p.tdx, vy + p.tdy),
                    "CODE 413 pause view {}: prompt anchored to its own view origin \
                     ({vx}, {vy}) with offset ({}, {})",
                    p.view,
                    p.tdx,
                    p.tdy
                );
                assert_eq!(
                    t[0].text, p.text,
                    "CODE 413 pause view {}: prompt wording",
                    p.view
                );
                assert_eq!(
                    (t[0].font, t[0].color),
                    (FONT1, C_WHITE),
                    "CODE 413 pause view {}: draw_set_font(font1) + draw_set_color(c_white) \
                     inside the taplock branch",
                    p.view
                );
                assert_eq!(
                    t[0].offset,
                    CODE_START + p.text_call,
                    "CODE 413 pause view {}: prompt call site",
                    p.view
                );
                assert_eq!(
                    sites_ran(&s),
                    vec![p.spr_call, p.text_call],
                    "CODE 413 pause view {} taplock 1: sheet then prompt, no other arm",
                    p.view
                );
            } else {
                assert!(
                    t.is_empty(),
                    "CODE 413 pause view {} taplock {taplock}: no prompt without taplock 1, got {:?}",
                    p.view,
                    t.iter().map(|t| (t.text.as_str(), t.x, t.y)).collect::<Vec<_>>()
                );
                assert_eq!(
                    sites_ran(&s),
                    vec![p.spr_call],
                    "CODE 413 pause view {} taplock {taplock}: the sheet arm alone",
                    p.view
                );
            }
            // The prompt must never leak into another view's block: only this
            // view's test can have taken its `bf`.
            assert!(
                ledger(&s).contains(&p.spr_call),
                "CODE 413 pause view {}: this block's own body ran",
                p.view
            );
            cells += 1;
        }
    }
    assert_eq!(cells, 12, "CODE 413: six views x two taplock states");
}

// ---- the banners: 216 arms ------------------------------------------------

#[test]
// CODE 413
fn every_weapon_banner_arm_draws_its_shipped_tuple() {
    let b = bundle();
    let mut cells = 0usize;
    for a in W_ARMS.iter() {
        let mut s = scene(&b);
        arm(&mut s, &[(a.weapon, f64::from(a.level))]);
        let id = spawn(&b, &mut s);
        s.executed.clear();
        s.draw_view(&b, a.view).unwrap();

        let p = PAUSE_ARMS
            .iter()
            .find(|p| p.view == a.view)
            .unwrap_or_else(|| panic!("CODE 413: no sheet arm for view {}", a.view));
        expect_sheet(&s, p, id);
        expect_banner(&s, a);

        // Instruction-level proof of exclusivity: the sheet body, this arm's
        // text, this arm's sprite - and no other draw site in the body.
        assert_eq!(
            sites_ran(&s),
            vec![p.spr_call, a.text_call, a.spr_call],
            "CODE 413 {} view {} level {}: only this arm may draw",
            a.weapon,
            a.view,
            a.level
        );
        // The family block ran its font+colour prelude exactly once, so the
        // `global.{0} == 1` test genuinely took its branch.
        // taplock is 0 throughout this sweep, so the sheet's prompt branch is
        // shut and the only draw_set_font that can run is the family prelude.
        let font_ran: Vec<usize> = ledger(&s)
            .into_iter()
            .filter(|o| call_sites(&b, "draw_set_font").contains(o))
            .collect();
        assert_eq!(
            font_ran.len(),
            1,
            "CODE 413 {} view {} level {}: exactly one draw_set_font (the family prelude)",
            a.weapon,
            a.view,
            a.level
        );
        cells += 1;
    }
    assert_eq!(cells, 216, "CODE 413: 12 families x 6 views x 3 tiers");
}

// ---- negatives: the branches the table does NOT take ----------------------

#[test]
// CODE 413
fn view_two_matches_no_arm_at_all() {
    // The shipped table skips view 2 in the sheet pass AND in all 12 family
    // chains. Nothing draws - not a blanked banner, nothing - and this is a
    // property of the bytecode, so it is asserted for every family/tier pair
    // rather than one representative value.
    let b = bundle();
    let font_sites = call_sites(&b, "draw_set_font");
    let mut cells = 0usize;
    for fam in FAMILIES.iter() {
        for level in [4.0, 7.0, 10.0] {
            let mut s = scene(&b);
            arm(&mut s, &[(fam.0, level)]);
            let _id = spawn(&b, &mut s);
            s.executed.clear();
            s.draw_view(&b, 2).unwrap();

            assert!(
                draws_from(&s, CODE).is_empty(),
                "CODE 413 {} level {level} view 2: no sprite at all",
                fam.0
            );
            assert!(
                texts_from(&s, CODE).is_empty(),
                "CODE 413 {} level {level} view 2: no text at all",
                fam.0
            );
            assert!(
                sites_ran(&s).is_empty(),
                "CODE 413 {} level {level} view 2: no draw call site may run",
                fam.0
            );
            // ...but the family block WAS entered: it set the font and colour
            // before its view chain. So view 2 is a hole in the view table, not
            // a short-circuit of the whole banner pass.
            let fonts_ran = ledger(&s)
                .into_iter()
                .filter(|o| font_sites.contains(o))
                .count();
            assert_eq!(
                fonts_ran, 1,
                "CODE 413 {} level {level} view 2: the family block's draw_set_font ran, \
                 so only the view chain failed to match",
                fam.0
            );
            cells += 1;
        }
    }
    assert_eq!(cells, 36, "CODE 413: 12 families x 3 tiers at view 2");
}

#[test]
// CODE 413
fn levels_off_the_three_tiers_leave_the_banner_blank() {
    let b = bundle();
    let mut cells = 0usize;
    for level in [0.0, 1.0, 3.0, 5.0, 6.0, 8.0, 9.0, 11.0, 12.0, -4.0] {
        for view in [0, 1, 3, 4, 5, 6] {
            let mut s = scene(&b);
            arm(&mut s, &[("pistol", level)]);
            spawn(&b, &mut s);
            s.executed.clear();
            s.draw_view(&b, view).unwrap();

            let d = draws_from(&s, CODE);
            assert_eq!(
                d.len(),
                1,
                "CODE 413 pistol level {level} view {view}: the sheet still draws, \
                 the banner tier chain matches nothing"
            );
            assert_eq!(
                d[0].sprite, 123,
                "CODE 413 pistol level {level} view {view}: sheet"
            );
            assert!(
                texts_from(&s, CODE).is_empty(),
                "CODE 413 pistol level {level} view {view}: no banner text"
            );
            cells += 1;
        }
    }
    assert_eq!(cells, 60, "CODE 413: 10 off-tier levels x 6 views");
}

#[test]
// CODE 413
fn a_weapon_flag_other_than_one_draws_no_banner() {
    // The gate is `global.<weapon> == 1`: 0 is the disarmed default, but 2 and
    // -1 and 7 must not slip through either, and a level that WOULD match a
    // tier must not be enough on its own.
    let b = bundle();
    let mut cells = 0usize;
    for flag in [0.0, 2.0, -1.0, 7.0] {
        for view in [0, 1, 3, 4, 5, 6] {
            let mut s = scene(&b);
            arm(&mut s, &[]);
            s.globals.insert("pistol".into(), flag);
            s.globals.insert("pistollevel".into(), 4.0);
            spawn(&b, &mut s);
            s.executed.clear();
            s.draw_view(&b, view).unwrap();

            let d = draws_from(&s, CODE);
            assert_eq!(
                d.len(),
                1,
                "CODE 413 pistol flag {flag} view {view}: sheet only"
            );
            assert_eq!(d[0].sprite, 123, "CODE 413 pistol flag {flag} view {view}");
            assert!(
                texts_from(&s, CODE).is_empty(),
                "CODE 413 pistol flag {flag} view {view}: level 4 alone must not draw a banner"
            );
            cells += 1;
        }
    }
    assert_eq!(cells, 24, "CODE 413: 4 flag values x 6 views");
}

#[test]
// CODE 413
fn taplock_values_other_than_one_suppress_the_prompt() {
    let b = bundle();
    let mut cells = 0usize;
    for taplock in [0.0, 2.0, -1.0, 70.0] {
        for view in [0, 1, 3, 4, 5, 6] {
            let mut s = scene(&b);
            arm(&mut s, &[("pistol", 4.0)]);
            let id = spawn(&b, &mut s);
            set_taplock(&mut s, id, taplock);
            s.executed.clear();
            s.draw_view(&b, view).unwrap();

            let d = draws_from(&s, CODE);
            assert_eq!(
                d.len(),
                2,
                "CODE 413 taplock {taplock} view {view}: sheet + banner, unaffected"
            );
            let t = texts_from(&s, CODE);
            assert_eq!(
                t.len(),
                1,
                "CODE 413 taplock {taplock} view {view}: only the banner text"
            );
            assert_eq!(
                t[0].text, "Your Pistol is now level 4!",
                "CODE 413 taplock {taplock} view {view}: no prompt leaked"
            );
            cells += 1;
        }
    }
    assert_eq!(cells, 24, "CODE 413: 4 taplock values x 6 views");
}

// ---- stacking: the family blocks are independent `if`s --------------------

#[test]
// CODE 413
fn all_twelve_families_stack_in_bytecode_order() {
    let b = bundle();
    let mut s = scene(&b);
    let on: Vec<(&str, f64)> = FAMILIES.iter().map(|f| (f.0, 7.0)).collect();
    arm(&mut s, &on);
    let id = spawn(&b, &mut s);
    set_taplock(&mut s, id, 1.0);
    s.executed.clear();
    s.draw_view(&b, 5).unwrap();

    let p = PAUSE_ARMS.iter().find(|p| p.view == 5).unwrap();
    expect_sheet(&s, p, id);

    let d = draws_from(&s, CODE);
    assert_eq!(
        d.len(),
        13,
        "CODE 413: sheet + 12 banners for view 5 level 7"
    );
    let t = texts_from(&s, CODE);
    assert_eq!(t.len(), 13, "CODE 413: prompt + 12 banner texts");

    // Prompt first: the six sheet blocks precede every family block.
    assert_eq!(
        t[0].text, "Tap to Continue",
        "CODE 413: prompt is the first text"
    );
    assert_eq!(
        (t[0].x, t[0].y),
        (510.0 + 150.0, 505.0 + 200.0),
        "CODE 413: prompt anchored to view 5"
    );

    let mut expect_sites = vec![p.spr_call, p.text_call];
    for (i, fam) in FAMILIES.iter().enumerate() {
        let a = W_ARMS
            .iter()
            .find(|a| a.weapon == fam.0 && a.view == 5 && a.level == 7)
            .unwrap_or_else(|| panic!("CODE 413 {} view 5 level 7", fam.0));
        // Banner i+1 in bytecode order, not sorted by anything else.
        assert_eq!(
            d[i + 1].sprite,
            a.spr,
            "CODE 413: banner {} is {} (sprite {}) in its own stream slot",
            i,
            fam.0,
            a.spr
        );
        assert_eq!(
            (d[i + 1].x, d[i + 1].y),
            (INST_X + a.dx, INST_Y + a.dy),
            "CODE 413 {} banner anchor",
            fam.0
        );
        assert_eq!(
            t[i + 1].text,
            a.text,
            "CODE 413: banner text {} is {}",
            i,
            fam.0
        );
        assert_eq!(
            (t[i + 1].x, t[i + 1].y),
            (INST_X + a.tdx, INST_Y + a.tdy),
            "CODE 413 {} banner text anchor",
            fam.0
        );
        expect_sites.push(a.text_call);
        expect_sites.push(a.spr_call);
    }
    // Distinct sprite ids, so the stacking order is visible in the queue.
    let banner_sprites: Vec<i32> = d[1..].iter().map(|d| d.sprite).collect();
    assert_eq!(
        banner_sprites.iter().collect::<BTreeSet<_>>().len(),
        12,
        "CODE 413: 12 distinct gun sprites stacked"
    );
    assert_eq!(
        sites_ran(&s),
        expect_sites,
        "CODE 413: all 26 draw calls in stream order, nothing else"
    );

    // Same twelve families at view 2: the whole stack collapses to nothing.
    s.executed.clear();
    s.draw_view(&b, 2).unwrap();
    assert!(
        draws_from(&s, CODE).is_empty() && texts_from(&s, CODE).is_empty(),
        "CODE 413: twelve armed families still draw nothing for view 2"
    );
    assert!(sites_ran(&s).is_empty());
}

// ---- the timer path: taplock is not just a writable field -----------------

#[test]
// CODE 413
fn the_taplock_timer_arms_the_prompt_and_the_prompt_follows_the_view() {
    let b = bundle();
    let mut s = scene(&b);
    arm(&mut s, &[("pistol", 4.0)]);
    let id = spawn(&b, &mut s);

    // CODE 409 leaves the gate shut and arms alarm[0] = 70.
    assert_eq!(
        s.instances[&id].fields["taplock"], 0.0,
        "CODE 413 path: CODE 409 lands taplock at 0"
    );
    assert_eq!(
        s.instances[&id].alarms[0], 70,
        "CODE 413 path: alarm[0] armed at 70"
    );
    s.draw_view(&b, 3).unwrap();
    let before = texts_from(&s, CODE);
    assert_eq!(
        before.len(),
        1,
        "CODE 413 path: banner only before the timer"
    );
    assert_eq!(before[0].text, "Your Pistol is now level 4!");

    for _ in 0..70 {
        s.tick(&b).expect("tick with the overlay active");
    }
    assert_eq!(
        s.instances[&id].fields["taplock"], 1.0,
        "CODE 413 path: CODE 411 (Alarm 0) released the tap gate"
    );

    // The prompt now appears, and each view anchors it to its own origin - the
    // one thing that makes the six sheet arms distinguishable in practice.
    for view in [0, 1, 3, 4, 5, 6] {
        let p = PAUSE_ARMS.iter().find(|p| p.view == view).unwrap();
        let (vx, vy) = view_pos(view);
        s.executed.clear();
        s.draw_view(&b, view).unwrap();
        let t = texts_from(&s, CODE);
        let tap = t
            .iter()
            .find(|t| t.text == "Tap to Continue")
            .unwrap_or_else(|| panic!("CODE 413 path: view {view} must show the prompt"));
        assert_eq!(
            (tap.x, tap.y),
            (vx + p.tdx, vy + p.tdy),
            "CODE 413 path: view {view} prompt position"
        );
        assert_eq!(
            tap.offset,
            CODE_START + p.text_call,
            "CODE 413 path: view {view} prompt call site"
        );
        let d = draws_from(&s, CODE);
        assert_eq!(d.len(), 2, "CODE 413 path: view {view} sheet + banner");
        assert_eq!(d[0].sprite, 123, "CODE 413 path: view {view} sheet");
        assert_eq!(
            d[1].sprite, 125,
            "CODE 413 path: view {view} pistol banner stays drawn alongside the prompt"
        );
    }
}
