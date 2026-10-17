//! Arm-level branch coverage for CODE 538,
//! `gml_Object_obj_viewresolution_Alarm_0` (obj_viewresolution 133, Alarm 0).
//!
//! The body is a flat else-if chain over the two display dimensions. Each test
//! compiles to a 10-instruction block:
//!
//!     <block>: call display_get_width; constant W; cmp 3 (= eq); bf AFTER_H;
//!              call display_get_height; constant H; cmp 3 (= eq); b TEST;
//!     AFTER_H: constant 0;                    <- the `&&` short-circuit's false
//!     TEST:    bf NEXT_TEST;
//!              <arm body: push value; push -1 (self); push index; store>
//!              b EXIT;
//!
//! so an arm fires iff width == W AND height == H, otherwise control falls to
//! the next block. The last TEST's `bf` reaches the untargeted else body, which
//! carries no trailing `b` and simply runs off the end of the CODE.
//!
//! Every arm writes the runtime `view_visible` array (indexes 0..=6, exactly one
//! of them true, in a per-arm scrambled order - the GML author's write order is
//! not index order) and eight of the fifteen arms additionally write
//! `view_wport`/`view_hport` for one view. `view_visible` is what the renderer
//! then uses to pick the visible view (`Scene::visible_view`) and `view_ports`
//! is what `view_wport`/`view_hport` reads resolve to, so this table is the
//! shipped resolution -> view-window mapping.
//!
//! The expected table below was extracted straight from the authoritative
//! bytecode in `crates/core/src/generated/full_ir.json` (CODE 538, start
//! 4837552, end 4840892, 677 instructions) - never guessed, never hand
//! transcribed. Extraction (scratch, not checked in):
//! `~/.hermes/cache/scratch/wl36-census-20261016/wl50-viewmatrix_emit.py`, which
//! walks the `call/cmp/bf` chain, decodes every arm body up to its terminating
//! `b`, and emits these tables (the dump it is built on is
//! `wl50-viewmatrix_dump.py` beside it). The same scratch run independently
//! parses the recovered GML
//! (`cally-recovered-gml-0ca243a/restored-source/gml/0538__gml_Object_obj_viewresolution_Alarm_0.gml`)
//! and diffs it against the IR: all 15 branch constants, all 15 write vectors
//! (order included) and the else body agree, so the IR is not drifting from the
//! restored source.
//! The test re-derives the whole table from the LIVE instruction stream at run
//! time (`extract` below) and asserts equality with the embedded constants, so
//! the embedded table cannot rot away from the bytecode it claims to encode.
//!
//! Arm census (checked by `the_arm_census_...`, and reported by the extraction):
//!   * 15 arms, 15 DISTINCT (W,H) constants - so there is no duplicate to
//!     disambiguate. The mechanism that would decide a duplicate is asserted
//!     anyway: the chain stops at the first equal comparison, so every block
//!     after the winning arm stays unexecuted (the per-arm ledger equality
//!     proves it, block by block).
//!   * The chain genuinely short-circuits per dimension, and the ledger pins it:
//!     a block entered with a wrong width runs only 6 instructions (the width
//!     half, the `bf` onto the pushed 0, the `bf` itself) and never touches
//!     `display_get_height`; a block whose width matches runs 9 (width half,
//!     height half, `b` over the pushed 0, `bf`). Arms 0 and 9 share width 960,
//!     so dispatching 960x540 must run arm 0's height half - the ledger asserts
//!     exactly that, block by block, for every sweep case and every negative.
//!   * Test blocks are 44 bytes and are laid out in chain order interleaved with
//!     their bodies: block0, body0, block1, body1, ..., block14, body14, else.
//!     Arms 0..=6 have 7-store bodies (144 bytes), arms 7..=14 have 9-store
//!     bodies (184 bytes).
//!   * All fifteen arms jump to the one exit that is the CODE's own end
//!     (code_offset 3340 = 4840892 - 4837552), so the body is left by running
//!     off the end rather than by a return: no `popz`, no `exit`.
//!   * The visible writes are not in index order for thirteen of the fifteen
//!     arms. Six distinct orders ship; only arms 0 (960x640) and 1 (1136x640)
//!     write `view_visible` in index order, and arms 6..=14 all share
//!     `6,5,4,0,1,2,3`. The sweep asserts the VM executes each arm's order
//!     store-by-store against the bytecode, so the scrambling is pinned, not
//!     normalised away.
//!   * `else` (code_offset 3200..3340, 7 stores, no trailing `b`) selects view 0
//!     and writes NO port. Its visible vector [1,0,0,0,0,0,0] is IDENTICAL to
//!     arm 1's (1136x640), and arm 1 writes no port either - so for that one
//!     pair the visible vector and the port map are both unable to tell the
//!     matched arm from the fall-through. The execution ledger is the only
//!     discriminator, which is exactly why this suite asserts it per arm; the
//!     pair gets its own test rather than being left implicit.
//!   * Port writes carry the arm's own display size but only three distinct
//!     target indexes: 6 (arms 7/10/11/13), 5 (arm 8), 1 (arms 9/12/14). Arm 9
//!     (960x540) is the odd one: it makes view 6 visible and writes the port of
//!     view 1 - pinned below as the shipped quirk, not corrected.
//!
//! Negative cases: what no arm matches is the whole table of near misses (for
//! every arm, ±1 on each axis) plus resolutions nowhere near it (123x456,
//! 1x1, 0x0, 3840x2160). Each must run all fifteen blocks and land in the else
//! body with no port written, with the ledger asserting the short-circuit shape
//! of every block on the way.
//!
//! Contract cross-check (the `skill` claim "960x540->view6, 1136x640->view0"):
//! both agree with the bytecode (arm 9 sets view_visible[6], arm 1 sets
//! view_visible[0]), and so do the downstream notes in `crates/client` that
//! treat 1136x640 as view 0 and 1024x768 as view 3. The older wording "everything
//! else defaults to view 0" holds for the visible vector, but it is not a whole
//! description of the shipped behaviour: (a) the fall-through does not *default*
//! to view 0, its own else body writes view 0 explicitly over all seven slots;
//! (b) 1136x640 is a real arm that lands on exactly the same visible vector, so
//! "unmatched == view 0" and "1136x640 == view 0" are only distinguishable
//! through execution; and (c) eight of the fifteen arms also resize a view port,
//! which the else body never does. The IR is authoritative here; no contract
//! file is touched, and nothing here is a fix - the shipped behaviour is pinned
//! as it is.
//!
//! Fixture: obj_viewresolution is instantiated once through the materializer
//! (`s.create`), then each arm is driven by a direct
//! `s.dispatch(&b, id, 2, 0)` with `s.display_width/s.display_height` set to
//! that arm's constant - `display_get_width`/`display_get_height` resolve to
//! exactly those fields. Arm-level coverage is read back from the engine's own
//! instruction ledger (`Scene::executed`), so a positive case must show its own
//! block and body and nothing else.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::collections::BTreeMap;
use std::path::Path;

/// obj_viewresolution (133). Its Create (537) arms `alarm[0] = 1` and calls
/// `application_surface_enable(false)`; its Alarm 0 is CODE 538.
const VIEWRES: i32 = 133;
const VIEWRES_CREATE_CODE: usize = 537;
const VIEWRES_CODE: usize = 538;
/// CODE 538's absolute span in the asset, from full_ir.json.
const CODE_START: usize = 4_837_552;
const CODE_END: usize = 4_840_892;
/// (event_type, subtype) of Alarm 0.
const ALARM_0: (i32, i32) = (2, 0);

// ---- extracted arm table (generated from full_ir.json CODE 538) ------------

/// Which view table entry a store targets.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Target {
    Vis,
    WPort,
    HPort,
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Store {
    target: Target,
    index: usize,
    value: f64,
}

/// One arm of the else-if chain, in bytecode order.
#[derive(Debug, Clone, Copy)]
struct Arm {
    w: f64,
    h: f64,
    /// code_offset of the arm's first instruction (`call display_get_width`).
    block_off: usize,
    /// code_offset of the arm's `bf` - the last comparison of its test.
    test_off: usize,
    /// code_offset of the arm body's first store.
    body_off: usize,
    /// Full body span, including the terminating `b` to the shared exit.
    body_len: usize,
    /// The arm body's stores, in bytecode (i.e. execution) order.
    writes: &'static [Store],
}

const A0: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
];
const A1: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 0,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
];
const A2: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
];
const A3: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 3,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
];
const A4: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 4,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
];
const A5: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 5,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
];
const A6: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
];
const A7: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 6,
        value: 800.0,
    },
    Store {
        target: Target::HPort,
        index: 6,
        value: 480.0,
    },
];
const A8: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 5,
        value: 854.0,
    },
    Store {
        target: Target::HPort,
        index: 5,
        value: 480.0,
    },
];
const A9: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 1,
        value: 960.0,
    },
    Store {
        target: Target::HPort,
        index: 1,
        value: 540.0,
    },
];
const A10: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 6,
        value: 1280.0,
    },
    Store {
        target: Target::HPort,
        index: 6,
        value: 720.0,
    },
];
const A11: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 6,
        value: 1920.0,
    },
    Store {
        target: Target::HPort,
        index: 6,
        value: 1080.0,
    },
];
const A12: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 1,
        value: 1280.0,
    },
    Store {
        target: Target::HPort,
        index: 1,
        value: 800.0,
    },
];
const A13: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 6,
        value: 2560.0,
    },
    Store {
        target: Target::HPort,
        index: 6,
        value: 1440.0,
    },
];
const A14: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 0,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::WPort,
        index: 1,
        value: 2560.0,
    },
    Store {
        target: Target::HPort,
        index: 1,
        value: 1600.0,
    },
];

/// The else body: view 0 visible, no port write.
const ELSE_WRITES: &[Store] = &[
    Store {
        target: Target::Vis,
        index: 0,
        value: 1.0,
    },
    Store {
        target: Target::Vis,
        index: 1,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 2,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 3,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 4,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 5,
        value: 0.0,
    },
    Store {
        target: Target::Vis,
        index: 6,
        value: 0.0,
    },
];

#[rustfmt::skip]
const ARMS: &[Arm] = &[
    Arm { w: 960.0, h: 640.0, block_off: 0, test_off: 44, body_off: 48, body_len: 144, writes: A0 },
    Arm { w: 1136.0, h: 640.0, block_off: 192, test_off: 236, body_off: 240, body_len: 144, writes: A1 },
    Arm { w: 480.0, h: 320.0, block_off: 384, test_off: 428, body_off: 432, body_len: 144, writes: A2 },
    Arm { w: 1024.0, h: 768.0, block_off: 576, test_off: 620, body_off: 624, body_len: 144, writes: A3 },
    Arm { w: 2048.0, h: 1536.0, block_off: 768, test_off: 812, body_off: 816, body_len: 144, writes: A4 },
    Arm { w: 1334.0, h: 750.0, block_off: 960, test_off: 1004, body_off: 1008, body_len: 144, writes: A5 },
    Arm { w: 2208.0, h: 1242.0, block_off: 1152, test_off: 1196, body_off: 1200, body_len: 144, writes: A6 },
    Arm { w: 800.0, h: 480.0, block_off: 1344, test_off: 1388, body_off: 1392, body_len: 184, writes: A7 },
    Arm { w: 854.0, h: 480.0, block_off: 1576, test_off: 1620, body_off: 1624, body_len: 184, writes: A8 },
    Arm { w: 960.0, h: 540.0, block_off: 1808, test_off: 1852, body_off: 1856, body_len: 184, writes: A9 },
    Arm { w: 1280.0, h: 720.0, block_off: 2040, test_off: 2084, body_off: 2088, body_len: 184, writes: A10 },
    Arm { w: 1920.0, h: 1080.0, block_off: 2272, test_off: 2316, body_off: 2320, body_len: 184, writes: A11 },
    Arm { w: 1280.0, h: 800.0, block_off: 2504, test_off: 2548, body_off: 2552, body_len: 184, writes: A12 },
    Arm { w: 2560.0, h: 1440.0, block_off: 2736, test_off: 2780, body_off: 2784, body_len: 184, writes: A13 },
    Arm { w: 2560.0, h: 1600.0, block_off: 2968, test_off: 3012, body_off: 3016, body_len: 184, writes: A14 },
];

/// The untargeted else body, and the shared exit every arm's `b` jumps to
/// (the CODE's own end, so the VM leaves the body).
const ELSE_OFF: usize = 3200;
const ELSE_LEN: usize = 140;
const EXIT_OFF: usize = 3340;
const ARM_COUNT: usize = 15;

// ---- fixture ---------------------------------------------------------------

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// A live obj_viewresolution instance, created through the materializer so its
/// Create (CODE 537) has run and `alarm[0]` is armed.
fn scene(b: &Bundle) -> (Scene, i32) {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    let id = s
        .create(b, VIEWRES, 0.0, 0.0)
        .expect("create obj_viewresolution");
    // CODE 537 arms the alarm the original runner fires; the alarm body itself
    // is what this suite drives, so only the arming needs to be real.
    assert_eq!(
        s.instances[&id].alarms[0], 1,
        "// CODE {VIEWRES_CREATE_CODE} arms alarm[0]"
    );
    (s, id)
}

fn body(b: &Bundle) -> &[Instruction] {
    &b.codes
        .iter()
        .find(|c| c.id == VIEWRES_CODE)
        .expect("CODE 538 body")
        .instructions
}

fn as_const(i: &Instruction) -> f64 {
    match &i.op {
        Op::Constant { value } => *value,
        o => panic!("// CODE {VIEWRES_CODE} expected a constant, got {o:?}"),
    }
}

fn call_name(i: &Instruction) -> &str {
    match &i.op {
        Op::Call { name, .. } => name,
        o => panic!("// CODE {VIEWRES_CODE} expected a call, got {o:?}"),
    }
}

fn branch_target(i: &Instruction, want: &str) -> usize {
    let t = match &i.op {
        Op::B { target } | Op::Bf { target } => *target,
        o => panic!("// CODE {VIEWRES_CODE} expected a branch, got {o:?}"),
    };
    let got = match &i.op {
        Op::B { .. } => "b",
        _ => "bf",
    };
    assert_eq!(
        got, want,
        "// CODE {VIEWRES_CODE} branch kind at {:#x}",
        i.offset
    );
    t
}

/// Absolute end of one instruction.
fn end_of(i: &Instruction) -> usize {
    i.offset + i.words_raw.len() * 4
}

/// `push value; push -1 (self); push index; store array` - the 4-instruction
/// write shape every arm body of this CODE uses. The store is located by
/// code_offset in the LIVE stream, so the decoded write is the bytecode's, not
/// a restatement of the embedded table.
fn store_at(stream: &[Instruction], off: usize) -> (Target, usize, f64) {
    let k = stream
        .iter()
        .position(|i| i.code_offset == off)
        .unwrap_or_else(|| panic!("// CODE {VIEWRES_CODE} no instruction at code_offset {off}"));
    let (name, selector, array, other) = match &stream[k].op {
        Op::Store {
            name,
            selector,
            array,
            other,
        } => (name, *selector, *array, *other),
        o => panic!("// CODE {VIEWRES_CODE} expected a store at {off}, got {o:?}"),
    };
    assert_eq!(
        selector, 0,
        "// CODE {VIEWRES_CODE} stores go to self (selector 0)"
    );
    assert!(
        array && !other,
        "// CODE {VIEWRES_CODE} stores are array writes"
    );
    let value = as_const(&stream[k - 3]);
    assert_eq!(
        as_const(&stream[k - 2]),
        -1.0,
        "// CODE {VIEWRES_CODE} array stores carry the self selector -1"
    );
    let index = as_const(&stream[k - 1]);
    assert_eq!(
        index.fract(),
        0.0,
        "// CODE {VIEWRES_CODE} store index is an integer"
    );
    let target = match name.as_str() {
        "view_visible" => Target::Vis,
        "view_wport" => Target::WPort,
        "view_hport" => Target::HPort,
        other => panic!("// CODE {VIEWRES_CODE} unexpected store target {other}"),
    };
    (target, index as usize, value)
}

// ---- runtime re-extraction of the whole table ------------------------------

struct LiveArm {
    w: f64,
    h: f64,
    block_off: usize,
    test_off: usize,
    body_off: usize,
    body_len: usize,
    exit: usize,
    writes: Vec<(Target, usize, f64)>,
}

struct LiveTable {
    arms: Vec<LiveArm>,
    else_off: usize,
    else_len: usize,
    else_writes: Vec<(Target, usize, f64)>,
}

/// Re-derive the arm table from the live instruction stream by walking the
/// chain, exactly as the extraction script did offline.
fn extract(b: &Bundle) -> LiveTable {
    let stream = body(b);
    let mut arms: Vec<LiveArm> = Vec::new();
    let mut k = 0usize;
    let else_start;
    loop {
        // ---- the two-dimension test block ----
        assert_eq!(
            call_name(&stream[k]),
            "display_get_width",
            "// CODE {VIEWRES_CODE} every arm test opens on display_get_width"
        );
        let block_off = stream[k].code_offset;
        let w = as_const(&stream[k + 1]);
        match stream[k + 2].op {
            Op::Cmp { comparison } => {
                assert_eq!(comparison, 3, "// CODE {VIEWRES_CODE} `==` is comparison 3")
            }
            ref o => panic!("// CODE {VIEWRES_CODE} expected cmp, got {o:?}"),
        }
        let miss_w = branch_target(&stream[k + 3], "bf") - CODE_START;
        assert_eq!(
            call_name(&stream[k + 4]),
            "display_get_height",
            "// CODE {VIEWRES_CODE} the width test is followed by the height test"
        );
        let h = as_const(&stream[k + 5]);
        match stream[k + 6].op {
            Op::Cmp { comparison } => {
                assert_eq!(comparison, 3, "// CODE {VIEWRES_CODE} `==` is comparison 3")
            }
            ref o => panic!("// CODE {VIEWRES_CODE} expected cmp, got {o:?}"),
        }
        assert_eq!(
            stream[k + 8].code_offset,
            miss_w,
            "// CODE {VIEWRES_CODE} a width miss lands on the short-circuit's pushed 0"
        );
        assert_eq!(
            as_const(&stream[k + 8]),
            0.0,
            "// CODE {VIEWRES_CODE} `&&` pushes 0 for a failed width test"
        );
        assert_eq!(
            branch_target(&stream[k + 7], "b") - CODE_START,
            stream[k + 9].code_offset,
            "// CODE {VIEWRES_CODE} the height pass jumps over the pushed 0 straight to the test"
        );
        let test_off = stream[k + 9].code_offset;
        let next_test = branch_target(&stream[k + 9], "bf") - CODE_START;

        // ---- the arm body ----
        let body_off = stream[k + 10].code_offset;
        let mut writes = Vec::new();
        let mut j = k + 10;
        while !matches!(stream[j].op, Op::B { .. }) {
            writes.push(store_at(stream, stream[j + 3].code_offset));
            j += 4;
        }
        let exit = branch_target(&stream[j], "b") - CODE_START;
        let body_len = end_of(&stream[j]) - CODE_START - body_off;
        arms.push(LiveArm {
            w,
            h,
            block_off,
            test_off,
            body_off,
            body_len,
            exit,
            writes,
        });

        match stream.iter().position(|i| i.code_offset == next_test) {
            Some(nk) if matches!(&stream[nk].op, Op::Call { name, .. } if name == "display_get_width") => {
                k = nk
            }
            Some(nk) => {
                assert!(
                    !matches!(stream[nk].op, Op::Call { .. }),
                    "// CODE {VIEWRES_CODE} the chain's last bf target starts the else body"
                );
                else_start = nk;
                break;
            }
            None => panic!(
                "// CODE {VIEWRES_CODE} bf target {next_test} is not an instruction boundary"
            ),
        }
    }

    // ---- the else body: 7 stores and no trailing branch ----
    let mut j = else_start;
    let mut else_writes = Vec::new();
    while j < stream.len() && !matches!(stream[j].op, Op::B { .. }) {
        else_writes.push(store_at(stream, stream[j + 3].code_offset));
        j += 4;
    }
    assert_eq!(
        j,
        stream.len(),
        "// CODE {VIEWRES_CODE} the else body carries no `b` and runs off the end of the CODE"
    );
    assert_eq!(
        end_of(&stream[stream.len() - 1]),
        CODE_END,
        "// CODE {VIEWRES_CODE} the else body's last store is the CODE's last instruction"
    );
    let else_off = stream[else_start].code_offset;
    LiveTable {
        arms,
        else_off,
        else_len: EXIT_OFF - else_off,
        else_writes,
    }
}

/// The code_offsets one test block enters when it is reached with display width
/// `w`: the width half always runs; the height half runs only if the width
/// already matched, because a width miss takes the `bf` straight onto the
/// `&&`'s pushed 0 (`block_off + 40`), and the height pass takes its own `b`
/// straight over that pushed 0 onto the block's `bf`.
///
/// So a chain step is 6 instructions for a width miss and 9 for a width hit,
/// and the winning block adds its 1-instruction `bf`. This is the bytecode's
/// short-circuit, not a simplification: the ledger proves the chain never
/// evaluates the height of a resolution whose width is already known to differ.
fn block_ran(stream: &[Instruction], arm: &Arm, w_matches: bool) -> Vec<usize> {
    let lo = arm.block_off;
    let in_range = |a: usize, b: usize| -> Vec<usize> {
        stream
            .iter()
            .filter(|i| i.code_offset >= a && i.code_offset <= b)
            .map(|i| i.code_offset)
            .collect()
    };
    let mut out = in_range(lo, lo + 16); // call display_get_width; W; cmp; bf
    if w_matches {
        out.extend(in_range(lo + 20, lo + 36)); // height; H; cmp; b
        out.push(arm.test_off); // bf, with nothing pushed between
    } else {
        out.extend(in_range(arm.test_off - 4, arm.test_off)); // the pushed 0, then bf
    }
    out
}

/// The code_offsets the VM must have entered, in order, for a dispatch that
/// stops at arm `n`: test blocks 0..=n (each short-circuiting per its own
/// width), then that arm's whole body. The bodies of arms 0..n sit between
/// those blocks in layout and must NOT appear.
fn expected_ledger(stream: &[Instruction], n: usize) -> Vec<usize> {
    let w = ARMS[n].w;
    let mut out = Vec::new();
    for arm in &ARMS[..=n] {
        out.extend(block_ran(stream, arm, arm.w == w));
    }
    let arm = &ARMS[n];
    out.extend(
        stream
            .iter()
            .filter(|i| {
                i.code_offset >= arm.body_off && i.code_offset < arm.body_off + arm.body_len
            })
            .map(|i| i.code_offset),
    );
    out
}

/// Every test block (short-circuiting per its own width), then the else body,
/// for a resolution `w` no arm matches.
fn expected_fallthrough_ledger(stream: &[Instruction], w: f64) -> Vec<usize> {
    let mut out = Vec::new();
    for arm in ARMS {
        out.extend(block_ran(stream, arm, arm.w == w));
    }
    out.extend(
        stream
            .iter()
            .filter(|i| i.code_offset >= ELSE_OFF && i.code_offset < ELSE_OFF + ELSE_LEN)
            .map(|i| i.code_offset),
    );
    out
}

/// The VM's own ledger for CODE 538, as start-relative code_offsets.
fn ledger(s: &Scene) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(code, _)| *code == VIEWRES_CODE)
        .map(|(_, off)| *off - CODE_START)
        .collect()
}

/// The stores the VM actually executed, decoded from the LIVE instruction
/// stream at the offsets the ledger recorded - so this is bytecode, not the
/// embedded table.
fn executed_stores(s: &Scene, stream: &[Instruction]) -> Vec<(Target, usize, f64)> {
    s.executed
        .iter()
        .filter(|(code, _)| *code == VIEWRES_CODE)
        .map(|(_, off)| *off - CODE_START)
        .filter(|off| {
            matches!(
                stream.iter().find(|i| i.code_offset == *off).unwrap().op,
                Op::Store { .. }
            )
        })
        .map(|off| store_at(stream, off))
        .collect()
}

/// Expected visible slots 0..=6 for a write list.
fn vis_vector(writes: &[(Target, usize, f64)]) -> [f64; 7] {
    let mut v = [f64::NAN; 7];
    for &(t, i, val) in writes {
        if t == Target::Vis {
            v[i] = val;
        }
    }
    v
}

/// Expected `view_ports` entries for a write list: (index, (wport, hport)).
fn port_map(writes: &[(Target, usize, f64)]) -> BTreeMap<i32, (f64, f64)> {
    let mut m = BTreeMap::new();
    for &(t, i, val) in writes {
        if t == Target::Vis {
            continue;
        }
        let e = m.entry(i as i32).or_insert((f64::NAN, f64::NAN));
        if t == Target::WPort {
            e.0 = val;
        } else {
            e.1 = val;
        }
    }
    m
}

fn const_stores(writes: &[Store]) -> Vec<(Target, usize, f64)> {
    writes
        .iter()
        .map(|s| (s.target, s.index, s.value))
        .collect()
}

// ---- the embedded table against the live bytecode --------------------------

#[test]
// CODE 538
fn the_arm_table_matches_the_live_instruction_stream() {
    let b = bundle();
    let t = extract(&b);
    assert_eq!(
        t.arms.len(),
        ARM_COUNT,
        "// CODE {VIEWRES_CODE} the live chain carries {ARM_COUNT} arms"
    );
    for (n, (live, pinned)) in t.arms.iter().zip(ARMS).enumerate() {
        assert_eq!(
            (live.w, live.h),
            (pinned.w, pinned.h),
            "// CODE {VIEWRES_CODE} arm {n} constant"
        );
        assert_eq!(
            (live.block_off, live.test_off, live.body_off, live.body_len),
            (
                pinned.block_off,
                pinned.test_off,
                pinned.body_off,
                pinned.body_len
            ),
            "// CODE {VIEWRES_CODE} arm {n} layout"
        );
        assert_eq!(
            live.writes,
            const_stores(pinned.writes),
            "// CODE {VIEWRES_CODE} arm {n} write list, in bytecode order"
        );
        assert_eq!(
            live.exit, EXIT_OFF,
            "// CODE {VIEWRES_CODE} arm {n} jumps to the shared exit"
        );
    }
    assert_eq!(
        (t.else_off, t.else_len),
        (ELSE_OFF, ELSE_LEN),
        "// CODE {VIEWRES_CODE} else body layout"
    );
    assert_eq!(
        t.else_writes,
        const_stores(ELSE_WRITES),
        "// CODE {VIEWRES_CODE} else body write list, in bytecode order"
    );
    // The else body is reached by exactly one bf (the last test's), and no arm
    // body is a branch target at all: an arm is entered by its own test's `bf`
    // NOT branching, i.e. by fall-through.
    let stream = body(&b);
    let bf_to_else = stream
        .iter()
        .filter(|i| matches!(i.op, Op::Bf { target } if target == ELSE_OFF + CODE_START))
        .count();
    assert_eq!(
        bf_to_else, 1,
        "// CODE {VIEWRES_CODE} only the last test's bf reaches the else body"
    );
    for arm in ARMS {
        let targeted = stream.iter().any(|i| match i.op {
            Op::B { target } | Op::Bf { target } | Op::Bt { target } => {
                target == arm.body_off + CODE_START
            }
            _ => false,
        });
        assert!(
            !targeted,
            "// CODE {VIEWRES_CODE} arm body at {} is entered by fall-through, not by a jump",
            arm.body_off
        );
    }
}

// ---- the arm sweep ---------------------------------------------------------

#[test]
// CODE 538
fn every_resolution_arm_selects_its_view_vector_and_port() {
    let b = bundle();
    let (mut s, id) = scene(&b);
    let stream = body(&b).to_vec();
    let mut ran = 0usize;
    for (n, arm) in ARMS.iter().enumerate() {
        let expected = const_stores(arm.writes);
        let want_vis = vis_vector(&expected);
        let want_ports = port_map(&expected);
        // The visible array is pre-seeded to a sentinel and asserted whole, so
        // an arm that skipped a slot shows up whatever direction the sentinel
        // points: with all-true a missing 0 stands out, with all-false a
        // missing 1 does. The sentinel also proves no arm touches index 7.
        for sentinel in [true, false] {
            s.view_visible = [sentinel; 8];
            // Sentinel port entry on an index no arm writes: the else body and
            // the seven port-less arms must leave it alone.
            s.view_ports.clear();
            s.view_ports.insert(7, (1234.0, 5678.0));
            s.display_width = arm.w;
            s.display_height = arm.h;
            s.executed.clear();
            s.dispatch(&b, id, ALARM_0.0, ALARM_0.1)
                .unwrap_or_else(|e| {
                    panic!("// CODE {VIEWRES_CODE} arm {n} ({}x{}): {e}", arm.w, arm.h)
                });
            // CODE 538 arm {n}
            assert_eq!(
                s.view_visible, [want_vis[0] >= 0.5, want_vis[1] >= 0.5, want_vis[2] >= 0.5,
                                 want_vis[3] >= 0.5, want_vis[4] >= 0.5, want_vis[5] >= 0.5,
                                 want_vis[6] >= 0.5, sentinel],
                "// CODE {VIEWRES_CODE} arm {n} ({}x{}) writes view_visible[0..6] to {want_vis:?}; \
                 index 7 must stay untouched", arm.w, arm.h
            );
            let mut want = want_ports.clone();
            want.insert(7, (1234.0, 5678.0));
            assert_eq!(
                s.view_ports, want,
                "// CODE {VIEWRES_CODE} arm {n} ({}x{}) writes exactly {want_ports:?} to the view ports",
                arm.w, arm.h
            );
            // The chain stops at this arm's own comparison: blocks 0..=n ran,
            // the rest never did, and only this arm's body executed.
            assert_eq!(
                ledger(&s),
                expected_ledger(&stream, n),
                "// CODE {VIEWRES_CODE} arm {n} ({}x{}) runs blocks 0..={n} then its own body only",
                arm.w,
                arm.h
            );
            // The write ORDER the body executed is the bytecode's order.
            assert_eq!(
                executed_stores(&s, &stream),
                expected,
                "// CODE {VIEWRES_CODE} arm {n} ({}x{}) executes its stores in bytecode order",
                arm.w,
                arm.h
            );
            // The arm body ends on its `b` into the shared exit.
            assert_eq!(
                ledger(&s).last(),
                Some(&(arm.body_off + arm.body_len - 4)),
                "// CODE {VIEWRES_CODE} arm {n} ({}x{}) leaves through the shared exit jump",
                arm.w,
                arm.h
            );
        }
        ran += 1;
    }
    assert_eq!(
        ran, ARM_COUNT,
        "// CODE {VIEWRES_CODE} the sweep covers all {ARM_COUNT} arms"
    );
}

// ---- unmatched resolutions -------------------------------------------------

/// One dispatch of a resolution, with the sentinels in place, returning the
/// scene so the caller can assert on it.
fn run(s: &mut Scene, b: &Bundle, id: i32, w: f64, h: f64) -> Result<(), String> {
    s.view_visible = [true; 8];
    s.view_ports.clear();
    s.view_ports.insert(7, (1234.0, 5678.0));
    s.display_width = w;
    s.display_height = h;
    s.executed.clear();
    s.dispatch(b, id, ALARM_0.0, ALARM_0.1)
}

#[test]
// CODE 538
fn an_unmatched_resolution_falls_through_to_the_else_body() {
    let b = bundle();
    let (mut s, id) = scene(&b);
    let stream = body(&b).to_vec();
    let want_vis = vis_vector(&const_stores(ELSE_WRITES));
    // One near miss per arm on each axis - a resolution that shares one
    // coordinate with an arm must NOT take that arm - plus resolutions that are
    // nowhere near the table.
    let mut cases: Vec<(f64, f64)> = vec![(123.0, 456.0), (1.0, 1.0), (0.0, 0.0), (3840.0, 2160.0)];
    for arm in ARMS {
        cases.push((arm.w + 1.0, arm.h));
        cases.push((arm.w, arm.h + 1.0));
        cases.push((arm.w - 1.0, arm.h));
        cases.push((arm.w, arm.h - 1.0));
    }
    for (w, h) in cases {
        assert!(
            !ARMS.iter().any(|a| a.w == w && a.h == h),
            "// CODE {VIEWRES_CODE} {w}x{h} is not an arm of the table"
        );
        run(&mut s, &b, id, w, h)
            .unwrap_or_else(|e| panic!("// CODE {VIEWRES_CODE} {w}x{h} dispatch: {e}"));
        // No test matched, so the chain ran to its last block and control fell
        // into the untargeted else body: view 0 only, no port write.
        assert_eq!(
            s.view_visible,
            [
                want_vis[0] >= 0.5,
                want_vis[1] >= 0.5,
                want_vis[2] >= 0.5,
                want_vis[3] >= 0.5,
                want_vis[4] >= 0.5,
                want_vis[5] >= 0.5,
                want_vis[6] >= 0.5,
                true
            ],
            "// CODE {VIEWRES_CODE} {w}x{h} falls through to the else body: view 0 visible, \
             and index 7 still holds its sentinel"
        );
        assert_eq!(
            s.view_ports,
            BTreeMap::from([(7, (1234.0, 5678.0))]),
            "// CODE {VIEWRES_CODE} {w}x{h} the else body writes no view port"
        );
        assert_eq!(
            ledger(&s),
            expected_fallthrough_ledger(&stream, w),
            "// CODE {VIEWRES_CODE} {w}x{h} runs every test block and then the else body"
        );
        assert_eq!(
            executed_stores(&s, &stream),
            const_stores(ELSE_WRITES),
            "// CODE {VIEWRES_CODE} {w}x{h} executes the else body's stores in bytecode order"
        );
        assert_eq!(
            ledger(&s).last(),
            Some(&(ELSE_OFF + ELSE_LEN - 8)),
            "// CODE {VIEWRES_CODE} {w}x{h} ends on the else body's last store"
        );
    }
}

/// The one place the visible vector is not enough: arm 1 (1136x640) is the
/// real-device canvas, and the else body produces the SAME visible vector and
/// the SAME (empty) port map. Only the ledger separates them - so the pair is
/// pinned here rather than left implicit.
#[test]
// CODE 538
fn arm_one_and_the_else_body_share_a_visible_vector_and_differ_only_in_the_ledger() {
    let b = bundle();
    let (mut s, id) = scene(&b);
    let stream = body(&b).to_vec();
    let arm1 = &ARMS[1];
    assert_eq!(
        (arm1.w, arm1.h),
        (1136.0, 640.0),
        "// CODE {VIEWRES_CODE} arm 1 is the real-device canvas"
    );
    let a1_vis_groups: Vec<Vec<usize>> = {
        let mut m: BTreeMap<[u8; 7], Vec<usize>> = BTreeMap::new();
        for (n, a) in ARMS.iter().enumerate() {
            let v = vis_vector(&const_stores(a.writes));
            m.entry(v.map(|x| x as u8)).or_default().push(n);
        }
        m.into_values().collect()
    };
    let else_vis = vis_vector(&const_stores(ELSE_WRITES));
    assert_eq!(
        vis_vector(&const_stores(arm1.writes)),
        else_vis,
        "// CODE {VIEWRES_CODE} arm 1's visible vector equals the else body's"
    );
    assert_eq!(
        port_map(&const_stores(arm1.writes)),
        BTreeMap::new(),
        "// CODE {VIEWRES_CODE} arm 1 writes no port either"
    );
    // Same observable view state, different execution: dispatch both.
    run(&mut s, &b, id, 1136.0, 640.0).expect("arm 1");
    let matched_ledger = ledger(&s);
    let matched_ports = s.view_ports.clone();
    run(&mut s, &b, id, 1137.0, 640.0).expect("else");
    assert_eq!(
        s.view_ports, matched_ports,
        "// CODE {VIEWRES_CODE} the matched arm and the fall-through leave the same port map"
    );
    assert_eq!(
        s.view_visible,
        [true, false, false, false, false, false, false, true],
        "// CODE {VIEWRES_CODE} and the same visible array"
    );
    assert_ne!(
        ledger(&s),
        matched_ledger,
        "// CODE {VIEWRES_CODE} only the executed instructions tell arm 1 from the else body"
    );
    assert_eq!(
        matched_ledger,
        expected_ledger(&stream, 1),
        "// CODE {VIEWRES_CODE} 1136x640 takes arm 1"
    );
    assert_eq!(
        ledger(&s),
        expected_fallthrough_ledger(&stream, 1137.0),
        "// CODE {VIEWRES_CODE} 1137x640 takes the else body"
    );
    // The grouping itself: exactly one group holds arm 1, and the else vector
    // is shared with that arm alone.
    assert_eq!(
        a1_vis_groups.len(),
        6,
        "// CODE {VIEWRES_CODE} six distinct visible vectors"
    );
}

// ---- the arm census --------------------------------------------------------

#[test]
// CODE 538
fn the_arm_census_pins_the_shipped_resolution_table() {
    let b = bundle();
    let t = extract(&b);
    let stream = body(&b);

    // ---- arm count and constants ----
    assert_eq!(ARM_COUNT, 15, "// CODE {VIEWRES_CODE} ships 15 arms");
    assert_eq!(t.arms.len(), ARM_COUNT, "// CODE {VIEWRES_CODE} arm count");
    let consts: Vec<(i64, i64)> = t.arms.iter().map(|a| (a.w as i64, a.h as i64)).collect();
    let mut distinct = consts.clone();
    distinct.sort_unstable();
    distinct.dedup();
    assert_eq!(
        distinct.len(), consts.len(),
        "// CODE {VIEWRES_CODE} has NO duplicate (W,H) constant: 15 arms, 15 distinct resolutions - \
         so no duplicate arm needs a first-wins decision. The mechanism is still asserted below."
    );
    // Bytecode order, verbatim. Not sorted on either axis.
    let order: Vec<(i64, i64)> = vec![
        (960, 640),
        (1136, 640),
        (480, 320),
        (1024, 768),
        (2048, 1536),
        (1334, 750),
        (2208, 1242),
        (800, 480),
        (854, 480),
        (960, 540),
        (1280, 720),
        (1920, 1080),
        (1280, 800),
        (2560, 1440),
        (2560, 1600),
    ];
    assert_eq!(
        consts, order,
        "// CODE {VIEWRES_CODE} chain order is the bytecode order"
    );
    // Not sorted on either axis: the widths alone are not monotonic.
    let widths: Vec<i64> = consts.iter().map(|c| c.0).collect();
    let mut widths_sorted = widths.clone();
    widths_sorted.sort_unstable();
    assert_ne!(
        widths, widths_sorted,
        "// CODE {VIEWRES_CODE} the chain is not sorted: the widths are not monotonic"
    );
    let mut distinct_widths = widths_sorted.clone();
    distinct_widths.dedup();
    assert_eq!(
        distinct_widths,
        vec![480, 800, 854, 960, 1024, 1136, 1280, 1334, 1920, 2048, 2208, 2560],
        "// CODE {VIEWRES_CODE} the distinct widths the chain tests"
    );
    // The three resolutions sharing a width 960 and the two sharing 2560 are
    // told apart by height alone - the reason the test compares BOTH halves.
    let w960: Vec<i64> = consts.iter().filter(|c| c.0 == 960).map(|c| c.1).collect();
    assert_eq!(
        w960,
        vec![640, 540],
        "// CODE {VIEWRES_CODE} two arms share width 960"
    );
    let w2560: Vec<i64> = consts.iter().filter(|c| c.0 == 2560).map(|c| c.1).collect();
    assert_eq!(
        w2560,
        vec![1440, 1600],
        "// CODE {VIEWRES_CODE} two arms share width 2560"
    );

    // ---- layout: blocks and bodies interleave in chain order ----
    for (n, a) in t.arms.iter().enumerate() {
        // A width miss lands on this block's own pushed 0; the block's `bf` -
        // reached only when the width matched - misses into the NEXT block
        // (or, for the last block, into the else body). Neither ever targets
        // an arm body.
        assert_eq!(
            a.test_off - a.block_off,
            44,
            "// CODE {VIEWRES_CODE} arm {n} test block is 44 bytes"
        );
        assert_eq!(
            a.test_off - 4,
            a.block_off + 40,
            "// CODE {VIEWRES_CODE} arm {n}'s pushed 0 sits 4 bytes above its bf"
        );
        assert_eq!(
            a.test_off + 4,
            a.body_off,
            "// CODE {VIEWRES_CODE} arm {n} body starts right after its bf"
        );
        let next = t.arms.get(n + 1).map(|x| x.block_off).unwrap_or(t.else_off);
        let k = k_of(stream, a.block_off);
        assert_eq!(
            branch_target(&stream[k + 3], "bf") - CODE_START,
            a.test_off - 4,
            "// CODE {VIEWRES_CODE} arm {n}'s width miss lands on its own pushed 0"
        );
        assert_eq!(
            branch_target(&stream[k + 9], "bf") - CODE_START,
            next,
            "// CODE {VIEWRES_CODE} arm {n}'s test misses into the next block"
        );
        assert_eq!(
            branch_target(&stream[k + 7], "b") - CODE_START,
            a.test_off,
            "// CODE {VIEWRES_CODE} arm {n}'s height pass jumps over the pushed 0 onto its bf"
        );
    }
    for n in 0..t.arms.len() - 1 {
        assert_eq!(
            t.arms[n].body_off + t.arms[n].body_len,
            t.arms[n + 1].block_off,
            "// CODE {VIEWRES_CODE} body {n} is followed immediately by block {}",
            n + 1
        );
    }
    assert_eq!(
        t.arms.last().unwrap().body_off + t.arms.last().unwrap().body_len,
        t.else_off,
        "// CODE {VIEWRES_CODE} the last body is followed by the else body"
    );
    assert_eq!(
        t.else_off + t.else_len,
        EXIT_OFF,
        "// CODE {VIEWRES_CODE} the else body runs out at the shared exit"
    );
    assert_eq!(
        t.else_len, 140,
        "// CODE {VIEWRES_CODE} the else body is 7 stores"
    );
    assert_eq!(
        stream[stream.len() - 1].code_offset,
        ELSE_OFF + ELSE_LEN - 8,
        "// CODE {VIEWRES_CODE} the else body's final store is the CODE's last instruction"
    );
    // All 15 arms jump to the one exit, which is the CODE's own end.
    for a in &t.arms {
        assert_eq!(
            a.exit, EXIT_OFF,
            "// CODE {VIEWRES_CODE} one shared exit, at the CODE's end"
        );
    }
    assert_eq!(
        EXIT_OFF + CODE_START,
        CODE_END,
        "// CODE {VIEWRES_CODE} the exit is the end of the CODE span"
    );

    // ---- every arm writes the whole visible vector ----
    for (n, a) in t.arms.iter().enumerate() {
        let vis: Vec<usize> = a
            .writes
            .iter()
            .filter(|s| s.0 == Target::Vis)
            .map(|s| s.1)
            .collect();
        let mut sorted = vis.clone();
        sorted.sort_unstable();
        assert_eq!(
            sorted,
            (0..=6).collect::<Vec<usize>>(),
            "// CODE {VIEWRES_CODE} arm {n} writes view_visible[0..=6] exactly once each"
        );
        assert_eq!(
            vis.len(),
            7,
            "// CODE {VIEWRES_CODE} arm {n} writes 7 visible slots"
        );
        let trues = a
            .writes
            .iter()
            .filter(|s| s.0 == Target::Vis && s.2 == 1.0)
            .count();
        assert_eq!(
            trues, 1,
            "// CODE {VIEWRES_CODE} arm {n} makes exactly one view visible"
        );
        assert!(
            a.writes
                .iter()
                .all(|s| s.0 != Target::Vis || s.2 == 0.0 || s.2 == 1.0),
            "// CODE {VIEWRES_CODE} arm {n} only writes 0/1 into view_visible"
        );
        assert!(
            a.writes.iter().all(|s| s.1 < 7 || s.0 != Target::Vis),
            "// CODE {VIEWRES_CODE} arm {n} never touches view_visible[7]"
        );
    }
    let else_vis: Vec<usize> = t
        .else_writes
        .iter()
        .filter(|s| s.0 == Target::Vis)
        .map(|s| s.1)
        .collect();
    assert_eq!(
        else_vis,
        (0..=6).collect::<Vec<usize>>(),
        "// CODE {VIEWRES_CODE} the else body writes view_visible[0..=6] in index order"
    );
    // ---- the write ORDER (the GML author's, not index order) ----
    // Each arm writes its seven slots in a fixed but scrambled order, and only
    // two of the fifteen write in index order. The sweep above asserts the VM
    // executes exactly this order, so these groups are the shipped order census.
    let mut orders: BTreeMap<Vec<usize>, Vec<usize>> = BTreeMap::new();
    for (n, a) in t.arms.iter().enumerate() {
        let vis: Vec<usize> = a
            .writes
            .iter()
            .filter(|s| s.0 == Target::Vis)
            .map(|s| s.1)
            .collect();
        orders.entry(vis).or_default().push(n);
    }
    assert_eq!(
        orders.len(),
        6,
        "// CODE {VIEWRES_CODE} the fifteen arms ship six distinct write orders"
    );
    assert_eq!(
        orders
            .get(&(0..=6).collect::<Vec<usize>>())
            .cloned()
            .unwrap_or_default(),
        vec![0, 1],
        "// CODE {VIEWRES_CODE} only arms 0 (960x640) and 1 (1136x640) write view_visible in \
         index order; the other thirteen write the visible slot region first"
    );
    assert_eq!(
        orders
            .get(&vec![6, 5, 4, 0, 1, 2, 3])
            .cloned()
            .unwrap_or_default(),
        vec![6, 7, 8, 9, 10, 11, 12, 13, 14],
        "// CODE {VIEWRES_CODE} arms 6..=14 all share the order 6,5,4,0,1,2,3 - the port-writing \
         arms among them write their ports after all seven visible slots"
    );
    assert_eq!(
        orders
            .get(&vec![2, 0, 1, 3, 4, 5, 6])
            .cloned()
            .unwrap_or_default(),
        vec![2],
        "// CODE {VIEWRES_CODE} arm 2 (480x320) is the only arm that writes its own visible slot \
         first and then the rest of 0..=6 in order"
    );
    assert_eq!(
        t.else_writes.iter().filter(|s| s.2 == 1.0).count(),
        1,
        "// CODE {VIEWRES_CODE} the else body leaves exactly one view visible, index 0"
    );

    // ---- port writes: which arms, which index, which value ----
    let portless: Vec<usize> = t
        .arms
        .iter()
        .enumerate()
        .filter(|(_, a)| a.writes.iter().all(|s| s.0 == Target::Vis))
        .map(|(n, _)| n)
        .collect();
    assert_eq!(
        portless,
        (0..=6).collect::<Vec<usize>>(),
        "// CODE {VIEWRES_CODE} arms 0..=6 write no view port; 7..=14 do"
    );
    let mut port_indexes: BTreeMap<usize, Vec<usize>> = BTreeMap::new();
    for (n, a) in t.arms.iter().enumerate() {
        let ports: Vec<(Target, usize, f64)> = a
            .writes
            .iter()
            .filter(|s| s.0 != Target::Vis)
            .copied()
            .collect();
        if ports.is_empty() {
            continue;
        }
        assert_eq!(
            ports.len(),
            2,
            "// CODE {VIEWRES_CODE} arm {n} writes one wport and one hport"
        );
        assert_eq!(
            ports[0].0,
            Target::WPort,
            "// CODE {VIEWRES_CODE} arm {n} writes wport first"
        );
        assert_eq!(
            ports[1].0,
            Target::HPort,
            "// CODE {VIEWRES_CODE} arm {n} writes hport second"
        );
        assert_eq!(
            ports[0].1, ports[1].1,
            "// CODE {VIEWRES_CODE} arm {n} writes the same view index"
        );
        assert_eq!(
            (ports[0].2, ports[1].2),
            (a.w, a.h),
            "// CODE {VIEWRES_CODE} arm {n} writes its own display size into the port"
        );
        port_indexes.entry(ports[0].1).or_default().push(n);
    }
    assert_eq!(
        port_indexes,
        BTreeMap::from([
            (1usize, vec![9usize, 12, 14]),
            (5, vec![8]),
            (6, vec![7, 10, 11, 13]),
        ]),
        "// CODE {VIEWRES_CODE} the port target indexes are 6, 5 and 1 - never 0, 2, 3 or 4"
    );
    // The visible index of a port-writing arm matches its port index except for
    // 960x540, which makes view 6 visible and writes view 1's port.
    let mismatched: Vec<usize> = t
        .arms
        .iter()
        .enumerate()
        .filter(|(_, a)| {
            let vis = a
                .writes
                .iter()
                .find(|s| s.0 == Target::Vis && s.2 == 1.0)
                .map(|s| s.1);
            let port = a.writes.iter().find(|s| s.0 == Target::WPort).map(|s| s.1);
            match (vis, port) {
                (Some(v), Some(p)) => v != p,
                _ => false,
            }
        })
        .map(|(n, _)| n)
        .collect();
    assert_eq!(
        mismatched,
        vec![9],
        "// CODE {VIEWRES_CODE} only 960x540 makes one view visible and writes another view's port"
    );

    // ---- the visible-vector groups ----
    let mut groups: BTreeMap<[u8; 7], Vec<usize>> = BTreeMap::new();
    for (n, a) in t.arms.iter().enumerate() {
        let v = vis_vector(&a.writes);
        groups.entry(v.map(|x| x as u8)).or_default().push(n);
    }
    let by_index = |i: usize| -> Vec<usize> {
        let mut key = [0u8; 7];
        key[i] = 1;
        groups.get(&key).cloned().unwrap_or_default()
    };
    assert_eq!(
        by_index(0),
        vec![1],
        "// CODE {VIEWRES_CODE} view 0 alone: 1136x640"
    );
    assert_eq!(
        by_index(1),
        vec![0, 2, 12, 14],
        "// CODE {VIEWRES_CODE} view 1: 960x640, 480x320, 1280x800, 2560x1600"
    );
    assert_eq!(
        by_index(2),
        Vec::<usize>::new(),
        "// CODE {VIEWRES_CODE} no arm makes view 2 visible"
    );
    assert_eq!(
        by_index(3),
        vec![3],
        "// CODE {VIEWRES_CODE} view 3 alone: 1024x768"
    );
    assert_eq!(
        by_index(4),
        vec![4],
        "// CODE {VIEWRES_CODE} view 4 alone: 2048x1536"
    );
    assert_eq!(
        by_index(5),
        vec![5, 8],
        "// CODE {VIEWRES_CODE} view 5: 1334x750, 854x480"
    );
    assert_eq!(by_index(6), vec![6, 7, 9, 10, 11, 13],
        "// CODE {VIEWRES_CODE} view 6: 2208x1242, 800x480, 960x540, 1280x720, 1920x1080, 2560x1440");
    assert_eq!(
        groups.len(),
        6,
        "// CODE {VIEWRES_CODE} six distinct visible vectors over 15 arms"
    );
    // Arm 1 is the only arm whose vector matches the else body's.
    let same_as_else: Vec<usize> = t
        .arms
        .iter()
        .enumerate()
        .filter(|(_, a)| vis_vector(&a.writes) == vis_vector(&t.else_writes))
        .map(|(n, _)| n)
        .collect();
    assert_eq!(
        same_as_else,
        vec![1],
        "// CODE {VIEWRES_CODE} arm 1 (1136x640) is the only arm the else body's vector cannot be \
         told apart from by view_visible alone - hence the per-arm ledger assertions"
    );
    // Every arm's visible vector agrees with the visible index it claims and the
    // one it does not write (index 7) is never touched.
    assert!(
        t.arms.iter().all(|a| a.writes.iter().all(|s| s.1 <= 6)),
        "// CODE {VIEWRES_CODE} no arm reaches view 7"
    );
}

/// Index of the instruction at start-relative `code_offset` in the live stream.
fn k_of(stream: &[Instruction], code_offset: usize) -> usize {
    stream
        .iter()
        .position(|i| i.code_offset == code_offset)
        .unwrap_or_else(|| {
            panic!("// CODE {VIEWRES_CODE} no instruction at code_offset {code_offset}")
        })
}
