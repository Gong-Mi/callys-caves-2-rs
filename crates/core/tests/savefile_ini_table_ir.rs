//! CODE 17 `gml_Object_obj_player_Other_2` — the Game Start body — enumerated
//! arm by arm. This is the biggest remaining branch-debt body: the whole
//! `savefile.ini` key table lives here as 324 `ini_read_real` arms and 324
//! `ini_write_real` arms, followed by 330 fresh-start default stores, three
//! `file_exists` gates (`savefile.ini` / `savefile2.ini` / `savefile3.ini`)
//! and twelve weapon `level -> damage` tables (120 `==` arms plus 12 `> 10`
//! clamps).
//!
//! Body shape, from the recovered GML
//! (`restored-source/gml/0017__gml_Object_obj_player_Other_2.gml`, 1540 lines,
//! SHA-256 dc640893db3b07c6fe5ce278157d039c7223acea70e4d40133aaf8b83569a23b)
//! and the authoritative bytecode in `crates/core/src/generated/full_ir.json`
//! (CODE 17 start 3822064 end 3861316, 6398 instructions):
//!
//! ```text
//! 0     AdColony_Init("app...","vz...","")          <- 3 pushed strings, result popped
//! 48    global.warpfrommap = 0; global.ending = 0;  <- unconditional preamble
//! 84    file_exists("savefile.ini") -> bf 13724     <- gate 1
//! 100   ini_open + 282 reads + ini_close
//! 13672 drawchange/drawlevelup/drawweaponlevelup/drawweaponchange = 0
//! 13720 b 29656                                     <- join of the if/else
//! 13724 file_exists("savefile.ini") cast; not; bf 29656   <- else-if (!exists)
//! 13756 288 default stores; ini_open; 282 writes; ini_close 29644
//! 29656 join
//! 29668 file_exists("savefile2.ini") -> bf 30276    <- gate 2
//! 29696 ini_open + 6 reads + 6 writes + ini_close 30260; b 30380
//! 30276 file_exists cast; not; bf 30380             <- else-if
//! 30308 6 default stores
//! 30380 join
//! 30392 file_exists("savefile3.ini") -> bf 33760    <- gate 3
//! 30420 ini_open + 36 reads + 36 writes + ini_close 33744; b 34224
//! 33760 file_exists cast; not; bf 34224             <- else-if
//! 33792 36 default stores
//! 34224 12 x { 10 x (load level; const K; cmp eq; bf; const dmg; store dmg) ;
//!               load level; const 10; cmp gt; bf; const 10; store level }
//! 39216 instance_create(x, y, obj_introduction); popz 39248
//! ```
//!
//! Census, re-derived from the live instruction stream by
//! `the_read_table_is_the_live_bytecode_table` (the embedded tables below are
//! a snapshot of the same extraction, so a regenerated IR that shifts a key, a
//! default or an offset fails the test instead of silently passing):
//!
//!   * 324 read arms = 282 `savefile.ini` + 6 `savefile2.ini` + 36
//!     `savefile3.ini`, reading 324 DISTINCT keys (no duplicate read arm), all
//!     with default `0` under section `"Save"` (string id 149), storing into
//!     324 distinct global targets (sel -5, except `score` which is the engine
//!     global at sel -1).
//!   * 324 write arms over the same three files, but only 320 DISTINCT keys:
//!     `bladegunbought`, `bowbought`, `bowxp` and `bowxptolevelup` are each
//!     written twice in the `savefile.ini` block. 320 is exactly the distinct
//!     key count `reconstruction/contracts/ir-save.md` records for the
//!     original save surface — the contract number is the union over the three
//!     `[Save]` files, and this suite is the first thing that pins the split
//!     (278 + 6 + 36).
//!   * Read set vs write set is NOT symmetric, and the differences are real
//!     original behaviour, not a reconstruction gap:
//!       - 6 keys are read but never written (`bomgunxp`, `coinmultiply`,
//!         `gemdropenabled`, `poisonenabled`, `timeplayed`, `weaponswapped`),
//!         so they always fall back to the read default `0` on a fresh start;
//!       - 2 keys are written but never read (`bombgunxp`, `grenadelevel`), so
//!         they cannot come back from a save;
//!       - `bomgunxp` (read) vs `bombgunxp` (written) is a key typo in the
//!         original: the save stores the XP under a key the load never asks
//!         for, so `bombgunxp` always reloads as 0.
//!   * 6 key names map to a differently spelled global (`current_level` ->
//!     `level`, `current_maxhp` -> `maxhp`, `current_score` -> `score`,
//!     `current_XP` -> `experience`, `triplejumpactive` -> `tjumpactive`,
//!     `bomgunxp` -> `bombgunxp`). Everything else is name-for-name.
//!   * 330 default stores = 288 (main) + 6 (savefile2) + 36 (savefile3),
//!     covering all 320 write sources plus 10 globals the body resets but never
//!     saves (`drawchange`, `drawlevelup`, `drawweaponlevelup`,
//!     `drawweaponchange`, `health1`, and the five read-only flags above
//!     minus `bomgunxp`, which is saved under its typo'd twin).
//!   * 12 damage tables x 10 arms + 12 clamps = 132 comparisons, which is
//!     every `cmp` in the body.
//!
//! Fixture: the body runs through its real event slot — `s.create(obj_player)`
//! then `s.dispatch(&b, id, 7, 2)` (Other / Game Start) — against a real
//! directory via `Scene::ini_disk_dir`, so `file_exists`, `ini_open`,
//! `ini_read_real` and `ini_close` all take their shipped paths. Arm-level
//! coverage is read back from the engine's instruction ledger
//! (`Scene::executed`), so a positive case must show exactly its own branch's
//! instructions and a negative case only the fall-through.
//!
//! The expected tables below were extracted programmatically from full_ir.json
//! (scratch generator `wl53-savefile-ini_extract.py`, not checked in); nothing
//! here is hand transcribed from the GML.
//!
//! Scope: re-written-end IR regression semantics, not an equivalence proof
//! against the original runner.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use callys_core::ir_scene::Scene;
use std::collections::{BTreeMap, BTreeSet};
use std::path::{Path, PathBuf};

/// CODE 17 = gml_Object_obj_player_Other_2, obj_player event Other_2 (7, 2).
const CODE: usize = 17;
/// Absolute byte offset of CODE 17's first instruction in game.droid.
const START: usize = 3_822_064;
const PLAYER: i32 = 0;
/// `instance_create(x, y, obj_introduction)` constant at code_offset 39216.
const INTRO_OBJECT: i32 = 137;
/// Every `ini_*` call in this body passes section "Save" (STRG id 149).
const SAVE_SECTION_SID: usize = 149;
const SAVE: &str = "savefile.ini";
const SAVE2: &str = "savefile2.ini";
const SAVE3: &str = "savefile3.ini";

/// Distinctive pre-seeded value: a global an arm does not touch keeps it, and a
/// damage/level cell that must not fire leaves it standing.
const SENTINEL: f64 = -999.0;

// ---- block boundaries in code_offset space (see the module doc) ------------
const GATE1: usize = 84;
const THEN1: (usize, usize) = (100, 13_724);
const ELSE1_TEST: usize = 13_736;
const THEN1_TAIL: (usize, usize) = (13_672, 13_720);
const JOIN1: usize = 29_656;
const GATE2: usize = 29_668;
const ELSE2_TEST: usize = 30_288;
const THEN2: (usize, usize) = (29_696, 30_276);
const GATE3: usize = 30_392;
const ELSE3_TEST: usize = 33_772;
const THEN3: (usize, usize) = (30_420, 33_760);
const DAMAGE: (usize, usize) = (34_224, 39_252);
/// `obj_introduction` creation call, the body's last observable side effect.
const EPILOGUE_CREATE: usize = 39_240;
const BODY_END: usize = 39_252;

/// The twelve weapon levels the damage tables read (`pistollevel` ... at
/// sel -5), used to keep the master read test's values inside the legal 1..=10
/// range so the `> 10` clamp never fires there.
const WEAPON_LEVELS: [&str; 12] = [
    "pistollevel",
    "shotgunlevel",
    "assaultriflelevel",
    "rocketlevel",
    "laserlevel",
    "icegunlevel",
    "bowlevel",
    "bladegunlevel",
    "flamethrowerlevel",
    "spikegunlevel",
    "boomeranglevel",
    "bombgunlevel",
];

// ---- embedded row constructors --------------------------------------------

const fn ra(
    key_sid: usize,
    key: &'static str,
    target: &'static str,
    sel: i32,
    default: f64,
    call_off: usize,
    store_off: usize,
) -> ReadArm {
    ReadArm {
        key_sid,
        key,
        target,
        sel,
        default,
        call_off,
        store_off,
    }
}

const fn wa(
    key_sid: usize,
    key: &'static str,
    source: &'static str,
    sel: i32,
    call_off: usize,
    load_off: usize,
) -> WriteArm {
    WriteArm {
        key_sid,
        key,
        source,
        sel,
        call_off,
        load_off,
    }
}

const fn ds(global: &'static str, sel: i32, value: f64, off: usize) -> StoreRow {
    StoreRow {
        global,
        sel,
        value,
        off,
    }
}

const fn da(level: f64, damage: f64, cmp_off: usize, store_off: usize) -> DamageArm {
    DamageArm {
        level,
        damage,
        cmp_off,
        store_off,
    }
}

// ---- extracted tables (generated) ------------------------------------------

#[derive(Clone, Copy, Debug)]
struct ReadArm {
    /// STRG string id of the key, so the table is anchored to the asset.
    key_sid: usize,
    key: &'static str,
    /// Global the read result is stored into (sel -5, or -1 for `score`).
    target: &'static str,
    sel: i32,
    default: f64,
    /// code_offset of the `call ini_read_real`.
    call_off: usize,
    /// code_offset of the `store` that receives its result.
    store_off: usize,
}

/// The 324 `ini_read_real` arms of CODE 17, in bytecode order.
/// Extracted from full_ir.json (CODE 17 start 3822064), never hand written.
#[rustfmt::skip]
const READ_ARMS: [ReadArm; 324] = [
    ra(148, "talkedtolloyd1", "talkedtolloyd1", -5, 0.0, 156, 164), // CODE 17 read arm 0 (savefile.ini)
    ra(151, "talkedtolloyd2", "talkedtolloyd2", -5, 0.0, 204, 212), // CODE 17 read arm 1 (savefile.ini)
    ra(152, "talkedtolloyd3", "talkedtolloyd3", -5, 0.0, 252, 260), // CODE 17 read arm 2 (savefile.ini)
    ra(153, "talkedtolloyd4", "talkedtolloyd4", -5, 0.0, 300, 308), // CODE 17 read arm 3 (savefile.ini)
    ra(154, "talkedtolloyd5", "talkedtolloyd5", -5, 0.0, 348, 356), // CODE 17 read arm 4 (savefile.ini)
    ra(155, "talkedtolloyd6", "talkedtolloyd6", -5, 0.0, 396, 404), // CODE 17 read arm 5 (savefile.ini)
    ra(156, "talkedtolloyd7", "talkedtolloyd7", -5, 0.0, 444, 452), // CODE 17 read arm 6 (savefile.ini)
    ra(157, "talkedtolloyd8", "talkedtolloyd8", -5, 0.0, 492, 500), // CODE 17 read arm 7 (savefile.ini)
    ra(158, "talkedtolloyd9", "talkedtolloyd9", -5, 0.0, 540, 548), // CODE 17 read arm 8 (savefile.ini)
    ra(159, "talkedtolloyd10", "talkedtolloyd10", -5, 0.0, 588, 596), // CODE 17 read arm 9 (savefile.ini)
    ra(160, "talkedtolloyd11", "talkedtolloyd11", -5, 0.0, 636, 644), // CODE 17 read arm 10 (savefile.ini)
    ra(161, "talkedtolloyd12", "talkedtolloyd12", -5, 0.0, 684, 692), // CODE 17 read arm 11 (savefile.ini)
    ra(162, "talkedtolloyd13", "talkedtolloyd13", -5, 0.0, 732, 740), // CODE 17 read arm 12 (savefile.ini)
    ra(163, "talkedtolloyd14", "talkedtolloyd14", -5, 0.0, 780, 788), // CODE 17 read arm 13 (savefile.ini)
    ra(164, "talkedtolloyd15", "talkedtolloyd15", -5, 0.0, 828, 836), // CODE 17 read arm 14 (savefile.ini)
    ra(71, "timeplayed", "timeplayed", -5, 0.0, 876, 884), // CODE 17 read arm 15 (savefile.ini)
    ra(165, "gemdropenabled", "gemdropenabled", -5, 0.0, 924, 932), // CODE 17 read arm 16 (savefile.ini)
    ra(166, "poisonenabled", "poisonenabled", -5, 0.0, 972, 980), // CODE 17 read arm 17 (savefile.ini)
    ra(167, "current_level", "level", -5, 0.0, 1020, 1028), // CODE 17 read arm 18 (savefile.ini)
    ra(168, "current_maxhp", "maxhp", -5, 0.0, 1068, 1076), // CODE 17 read arm 19 (savefile.ini)
    ra(169, "current_score", "score", -1, 0.0, 1116, 1124), // CODE 17 read arm 20 (savefile.ini)
    ra(171, "boss1dead", "boss1dead", -5, 0.0, 1164, 1172), // CODE 17 read arm 21 (savefile.ini)
    ra(172, "boss2dead", "boss2dead", -5, 0.0, 1212, 1220), // CODE 17 read arm 22 (savefile.ini)
    ra(173, "boss3dead", "boss3dead", -5, 0.0, 1260, 1268), // CODE 17 read arm 23 (savefile.ini)
    ra(174, "boss4dead", "boss4dead", -5, 0.0, 1308, 1316), // CODE 17 read arm 24 (savefile.ini)
    ra(175, "boss5dead", "boss5dead", -5, 0.0, 1356, 1364), // CODE 17 read arm 25 (savefile.ini)
    ra(176, "boss6dead", "boss6dead", -5, 0.0, 1404, 1412), // CODE 17 read arm 26 (savefile.ini)
    ra(208, "xptolevelup", "xptolevelup", -5, 0.0, 1452, 1460), // CODE 17 read arm 27 (savefile.ini)
    ra(177, "pistolbought", "pistolbought", -5, 0.0, 1500, 1508), // CODE 17 read arm 28 (savefile.ini)
    ra(78, "energywavebought", "energywavebought", -5, 0.0, 1548, 1556), // CODE 17 read arm 29 (savefile.ini)
    ra(186, "strengthupgradebought", "strengthupgradebought", -5, 0.0, 1596, 1604), // CODE 17 read arm 30 (savefile.ini)
    ra(187, "strengthupgrade2bought", "strengthupgrade2bought", -5, 0.0, 1644, 1652), // CODE 17 read arm 31 (savefile.ini)
    ra(70, "healthregenbought", "healthregenbought", -5, 0.0, 1692, 1700), // CODE 17 read arm 32 (savefile.ini)
    ra(178, "shotgunbought", "shotgunbought", -5, 0.0, 1740, 1748), // CODE 17 read arm 33 (savefile.ini)
    ra(127, "swordupgradebought", "swordupgradebought", -5, 0.0, 1788, 1796), // CODE 17 read arm 34 (savefile.ini)
    ra(129, "swordupgrade2bought", "swordupgrade2bought", -5, 0.0, 1836, 1844), // CODE 17 read arm 35 (savefile.ini)
    ra(130, "swordupgrade3bought", "swordupgrade3bought", -5, 0.0, 1884, 1892), // CODE 17 read arm 36 (savefile.ini)
    ra(179, "powerupgradebought", "powerupgradebought", -5, 0.0, 1932, 1940), // CODE 17 read arm 37 (savefile.ini)
    ra(180, "powerupgrade2bought", "powerupgrade2bought", -5, 0.0, 1980, 1988), // CODE 17 read arm 38 (savefile.ini)
    ra(181, "powerupgrade3bought", "powerupgrade3bought", -5, 0.0, 2028, 2036), // CODE 17 read arm 39 (savefile.ini)
    ra(182, "assaultriflebought", "assaultriflebought", -5, 0.0, 2076, 2084), // CODE 17 read arm 40 (savefile.ini)
    ra(183, "rocketbought", "rocketbought", -5, 0.0, 2124, 2132), // CODE 17 read arm 41 (savefile.ini)
    ra(184, "laserbought", "laserbought", -5, 0.0, 2172, 2180), // CODE 17 read arm 42 (savefile.ini)
    ra(185, "icegunbought", "icegunbought", -5, 0.0, 2220, 2228), // CODE 17 read arm 43 (savefile.ini)
    ra(196, "bladegunbought", "bladegunbought", -5, 0.0, 2268, 2276), // CODE 17 read arm 44 (savefile.ini)
    ra(197, "flamethrowerbought", "flamethrowerbought", -5, 0.0, 2316, 2324), // CODE 17 read arm 45 (savefile.ini)
    ra(195, "bowbought", "bowbought", -5, 0.0, 2364, 2372), // CODE 17 read arm 46 (savefile.ini)
    ra(204, "bombgunbought", "bombgunbought", -5, 0.0, 2412, 2420), // CODE 17 read arm 47 (savefile.ini)
    ra(476, "bomgunxp", "bombgunxp", -5, 0.0, 2460, 2468), // CODE 17 read arm 48 (savefile.ini)
    ra(206, "bombgunxptolevelup", "bombgunxptolevelup", -5, 0.0, 2508, 2516), // CODE 17 read arm 49 (savefile.ini)
    ra(207, "bombgunlevel", "bombgunlevel", -5, 0.0, 2556, 2564), // CODE 17 read arm 50 (savefile.ini)
    ra(202, "bladegunxp", "bladegunxp", -5, 0.0, 2604, 2612), // CODE 17 read arm 51 (savefile.ini)
    ra(203, "bladegunxptolevelup", "bladegunxptolevelup", -5, 0.0, 2652, 2660), // CODE 17 read arm 52 (savefile.ini)
    ra(200, "flamethrowerxp", "flamethrowerxp", -5, 0.0, 2700, 2708), // CODE 17 read arm 53 (savefile.ini)
    ra(201, "flamethrowerxptolevelup", "flamethrowerxptolevelup", -5, 0.0, 2748, 2756), // CODE 17 read arm 54 (savefile.ini)
    ra(229, "boomerangbought", "boomerangbought", -5, 0.0, 2796, 2804), // CODE 17 read arm 55 (savefile.ini)
    ra(230, "boomerangxp", "boomerangxp", -5, 0.0, 2844, 2852), // CODE 17 read arm 56 (savefile.ini)
    ra(231, "boomeranglevel", "boomeranglevel", -5, 0.0, 2892, 2900), // CODE 17 read arm 57 (savefile.ini)
    ra(232, "boomerangxptolevelup", "boomerangxptolevelup", -5, 0.0, 2940, 2948), // CODE 17 read arm 58 (savefile.ini)
    ra(233, "spikegunbought", "spikegunbought", -5, 0.0, 2988, 2996), // CODE 17 read arm 59 (savefile.ini)
    ra(234, "spikegunxp", "spikegunxp", -5, 0.0, 3036, 3044), // CODE 17 read arm 60 (savefile.ini)
    ra(235, "spikegunlevel", "spikegunlevel", -5, 0.0, 3084, 3092), // CODE 17 read arm 61 (savefile.ini)
    ra(236, "spikegunxptolevelup", "spikegunxptolevelup", -5, 0.0, 3132, 3140), // CODE 17 read arm 62 (savefile.ini)
    ra(198, "bowxp", "bowxp", -5, 0.0, 3180, 3188), // CODE 17 read arm 63 (savefile.ini)
    ra(199, "bowxptolevelup", "bowxptolevelup", -5, 0.0, 3228, 3236), // CODE 17 read arm 64 (savefile.ini)
    ra(128, "sword", "sword", -5, 0.0, 3276, 3284), // CODE 17 read arm 65 (savefile.ini)
    ra(188, "triplejumpbought", "triplejumpbought", -5, 0.0, 3324, 3332), // CODE 17 read arm 66 (savefile.ini)
    ra(190, "triplejumpactive", "tjumpactive", -5, 0.0, 3372, 3380), // CODE 17 read arm 67 (savefile.ini)
    ra(191, "coinmultiplier2bought", "coinmultiplier2bought", -5, 0.0, 3420, 3428), // CODE 17 read arm 68 (savefile.ini)
    ra(192, "coinmultiplier5bought", "coinmultiplier5bought", -5, 0.0, 3468, 3476), // CODE 17 read arm 69 (savefile.ini)
    ra(193, "maxhpupgradebought", "maxhpupgradebought", -5, 0.0, 3516, 3524), // CODE 17 read arm 70 (savefile.ini)
    ra(194, "maxhpupgrade2bought", "maxhpupgrade2bought", -5, 0.0, 3564, 3572), // CODE 17 read arm 71 (savefile.ini)
    ra(237, "drawchangepistol4", "drawchangepistol4", -5, 0.0, 3612, 3620), // CODE 17 read arm 72 (savefile.ini)
    ra(238, "drawchangeshotgun4", "drawchangeshotgun4", -5, 0.0, 3660, 3668), // CODE 17 read arm 73 (savefile.ini)
    ra(239, "drawchangeassaultrifle4", "drawchangeassaultrifle4", -5, 0.0, 3708, 3716), // CODE 17 read arm 74 (savefile.ini)
    ra(240, "drawchangerocket4", "drawchangerocket4", -5, 0.0, 3756, 3764), // CODE 17 read arm 75 (savefile.ini)
    ra(241, "drawchangelaser4", "drawchangelaser4", -5, 0.0, 3804, 3812), // CODE 17 read arm 76 (savefile.ini)
    ra(242, "drawchangeicegun4", "drawchangeicegun4", -5, 0.0, 3852, 3860), // CODE 17 read arm 77 (savefile.ini)
    ra(243, "drawchangebow4", "drawchangebow4", -5, 0.0, 3900, 3908), // CODE 17 read arm 78 (savefile.ini)
    ra(244, "drawchangebladegun4", "drawchangebladegun4", -5, 0.0, 3948, 3956), // CODE 17 read arm 79 (savefile.ini)
    ra(245, "drawchangeflamethrower4", "drawchangeflamethrower4", -5, 0.0, 3996, 4004), // CODE 17 read arm 80 (savefile.ini)
    ra(246, "drawchangeboomerang4", "drawchangeboomerang4", -5, 0.0, 4044, 4052), // CODE 17 read arm 81 (savefile.ini)
    ra(247, "drawchangespikegun4", "drawchangespikegun4", -5, 0.0, 4092, 4100), // CODE 17 read arm 82 (savefile.ini)
    ra(248, "drawchangebombgun4", "drawchangebombgun4", -5, 0.0, 4140, 4148), // CODE 17 read arm 83 (savefile.ini)
    ra(249, "drawchangepistol7", "drawchangepistol7", -5, 0.0, 4188, 4196), // CODE 17 read arm 84 (savefile.ini)
    ra(250, "drawchangeshotgun7", "drawchangeshotgun7", -5, 0.0, 4236, 4244), // CODE 17 read arm 85 (savefile.ini)
    ra(251, "drawchangeassaultrifle7", "drawchangeassaultrifle7", -5, 0.0, 4284, 4292), // CODE 17 read arm 86 (savefile.ini)
    ra(252, "drawchangerocket7", "drawchangerocket7", -5, 0.0, 4332, 4340), // CODE 17 read arm 87 (savefile.ini)
    ra(253, "drawchangelaser7", "drawchangelaser7", -5, 0.0, 4380, 4388), // CODE 17 read arm 88 (savefile.ini)
    ra(254, "drawchangeicegun7", "drawchangeicegun7", -5, 0.0, 4428, 4436), // CODE 17 read arm 89 (savefile.ini)
    ra(255, "drawchangebow7", "drawchangebow7", -5, 0.0, 4476, 4484), // CODE 17 read arm 90 (savefile.ini)
    ra(256, "drawchangebladegun7", "drawchangebladegun7", -5, 0.0, 4524, 4532), // CODE 17 read arm 91 (savefile.ini)
    ra(257, "drawchangeflamethrower7", "drawchangeflamethrower7", -5, 0.0, 4572, 4580), // CODE 17 read arm 92 (savefile.ini)
    ra(258, "drawchangeboomerang7", "drawchangeboomerang7", -5, 0.0, 4620, 4628), // CODE 17 read arm 93 (savefile.ini)
    ra(259, "drawchangespikegun7", "drawchangespikegun7", -5, 0.0, 4668, 4676), // CODE 17 read arm 94 (savefile.ini)
    ra(260, "drawchangebombgun7", "drawchangebombgun7", -5, 0.0, 4716, 4724), // CODE 17 read arm 95 (savefile.ini)
    ra(261, "drawchangepistol10", "drawchangepistol10", -5, 0.0, 4764, 4772), // CODE 17 read arm 96 (savefile.ini)
    ra(262, "drawchangeshotgun10", "drawchangeshotgun10", -5, 0.0, 4812, 4820), // CODE 17 read arm 97 (savefile.ini)
    ra(263, "drawchangeassaultrifle10", "drawchangeassaultrifle10", -5, 0.0, 4860, 4868), // CODE 17 read arm 98 (savefile.ini)
    ra(264, "drawchangerocket10", "drawchangerocket10", -5, 0.0, 4908, 4916), // CODE 17 read arm 99 (savefile.ini)
    ra(265, "drawchangelaser10", "drawchangelaser10", -5, 0.0, 4956, 4964), // CODE 17 read arm 100 (savefile.ini)
    ra(266, "drawchangeicegun10", "drawchangeicegun10", -5, 0.0, 5004, 5012), // CODE 17 read arm 101 (savefile.ini)
    ra(267, "drawchangebow10", "drawchangebow10", -5, 0.0, 5052, 5060), // CODE 17 read arm 102 (savefile.ini)
    ra(268, "drawchangebladegun10", "drawchangebladegun10", -5, 0.0, 5100, 5108), // CODE 17 read arm 103 (savefile.ini)
    ra(269, "drawchangeflamethrower10", "drawchangeflamethrower10", -5, 0.0, 5148, 5156), // CODE 17 read arm 104 (savefile.ini)
    ra(270, "drawchangeboomerang10", "drawchangeboomerang10", -5, 0.0, 5196, 5204), // CODE 17 read arm 105 (savefile.ini)
    ra(271, "drawchangespikegun10", "drawchangespikegun10", -5, 0.0, 5244, 5252), // CODE 17 read arm 106 (savefile.ini)
    ra(272, "drawchangebombgun10", "drawchangebombgun10", -5, 0.0, 5292, 5300), // CODE 17 read arm 107 (savefile.ini)
    ra(170, "current_XP", "experience", -5, 0.0, 5340, 5348), // CODE 17 read arm 108 (savefile.ini)
    ra(139, "haskey", "haskey", -5, 0.0, 5388, 5396), // CODE 17 read arm 109 (savefile.ini)
    ra(209, "pistolxp", "pistolxp", -5, 0.0, 5436, 5444), // CODE 17 read arm 110 (savefile.ini)
    ra(210, "pistolxptolevelup", "pistolxptolevelup", -5, 0.0, 5484, 5492), // CODE 17 read arm 111 (savefile.ini)
    ra(211, "shotgunxp", "shotgunxp", -5, 0.0, 5532, 5540), // CODE 17 read arm 112 (savefile.ini)
    ra(212, "shotgunxptolevelup", "shotgunxptolevelup", -5, 0.0, 5580, 5588), // CODE 17 read arm 113 (savefile.ini)
    ra(213, "assaultriflexp", "assaultriflexp", -5, 0.0, 5628, 5636), // CODE 17 read arm 114 (savefile.ini)
    ra(214, "assaultriflexptolevelup", "assaultriflexptolevelup", -5, 0.0, 5676, 5684), // CODE 17 read arm 115 (savefile.ini)
    ra(215, "rocketxp", "rocketxp", -5, 0.0, 5724, 5732), // CODE 17 read arm 116 (savefile.ini)
    ra(216, "rocketxptolevelup", "rocketxptolevelup", -5, 0.0, 5772, 5780), // CODE 17 read arm 117 (savefile.ini)
    ra(217, "laserxp", "laserxp", -5, 0.0, 5820, 5828), // CODE 17 read arm 118 (savefile.ini)
    ra(218, "laserxptolevelup", "laserxptolevelup", -5, 0.0, 5868, 5876), // CODE 17 read arm 119 (savefile.ini)
    ra(219, "icegunxp", "icegunxp", -5, 0.0, 5916, 5924), // CODE 17 read arm 120 (savefile.ini)
    ra(220, "icegunxptolevelup", "icegunxptolevelup", -5, 0.0, 5964, 5972), // CODE 17 read arm 121 (savefile.ini)
    ra(221, "pistollevel", "pistollevel", -5, 0.0, 6012, 6020), // CODE 17 read arm 122 (savefile.ini)
    ra(222, "shotgunlevel", "shotgunlevel", -5, 0.0, 6060, 6068), // CODE 17 read arm 123 (savefile.ini)
    ra(87, "assaultriflelevel", "assaultriflelevel", -5, 0.0, 6108, 6116), // CODE 17 read arm 124 (savefile.ini)
    ra(223, "rocketlevel", "rocketlevel", -5, 0.0, 6156, 6164), // CODE 17 read arm 125 (savefile.ini)
    ra(224, "laserlevel", "laserlevel", -5, 0.0, 6204, 6212), // CODE 17 read arm 126 (savefile.ini)
    ra(225, "icegunlevel", "icegunlevel", -5, 0.0, 6252, 6260), // CODE 17 read arm 127 (savefile.ini)
    ra(226, "bowlevel", "bowlevel", -5, 0.0, 6300, 6308), // CODE 17 read arm 128 (savefile.ini)
    ra(227, "bladegunlevel", "bladegunlevel", -5, 0.0, 6348, 6356), // CODE 17 read arm 129 (savefile.ini)
    ra(228, "flamethrowerlevel", "flamethrowerlevel", -5, 0.0, 6396, 6404), // CODE 17 read arm 130 (savefile.ini)
    ra(274, "knifebanditskilled", "knifebanditskilled", -5, 0.0, 6444, 6452), // CODE 17 read arm 131 (savefile.ini)
    ra(275, "pistolthugskilled", "pistolthugskilled", -5, 0.0, 6492, 6500), // CODE 17 read arm 132 (savefile.ini)
    ra(276, "chomperbotkilled", "chomperbotkilled", -5, 0.0, 6540, 6548), // CODE 17 read arm 133 (savefile.ini)
    ra(277, "greenslimeskilled", "greenslimeskilled", -5, 0.0, 6588, 6596), // CODE 17 read arm 134 (savefile.ini)
    ra(278, "wolfkilled", "wolfkilled", -5, 0.0, 6636, 6644), // CODE 17 read arm 135 (savefile.ini)
    ra(279, "fireslimeskilled", "fireslimeskilled", -5, 0.0, 6684, 6692), // CODE 17 read arm 136 (savefile.ini)
    ra(280, "hulkingbanditskilled", "hulkingbanditskilled", -5, 0.0, 6732, 6740), // CODE 17 read arm 137 (savefile.ini)
    ra(281, "ghostskilled", "ghostskilled", -5, 0.0, 6780, 6788), // CODE 17 read arm 138 (savefile.ini)
    ra(282, "skeletonskilled", "skeletonskilled", -5, 0.0, 6828, 6836), // CODE 17 read arm 139 (savefile.ini)
    ra(283, "zombieskilled", "zombieskilled", -5, 0.0, 6876, 6884), // CODE 17 read arm 140 (savefile.ini)
    ra(284, "firehulkskilled", "firehulkskilled", -5, 0.0, 6924, 6932), // CODE 17 read arm 141 (savefile.ini)
    ra(285, "batskilled", "batskilled", -5, 0.0, 6972, 6980), // CODE 17 read arm 142 (savefile.ini)
    ra(286, "trapskilled", "trapskilled", -5, 0.0, 7020, 7028), // CODE 17 read arm 143 (savefile.ini)
    ra(273, "bearskilled", "bearskilled", -5, 0.0, 7068, 7076), // CODE 17 read arm 144 (savefile.ini)
    ra(287, "enemieskilled", "enemieskilled", -5, 0.0, 7116, 7124), // CODE 17 read arm 145 (savefile.ini)
    ra(288, "boughtallguns", "boughtallguns", -5, 0.0, 7164, 7172), // CODE 17 read arm 146 (savefile.ini)
    ra(289, "triplejumpachievement", "triplejumpachievement", -5, 0.0, 7212, 7220), // CODE 17 read arm 147 (savefile.ini)
    ra(290, "boughtallupgrades", "boughtallupgrades", -5, 0.0, 7260, 7268), // CODE 17 read arm 148 (savefile.ini)
    ra(291, "boughteverything", "boughteverything", -5, 0.0, 7308, 7316), // CODE 17 read arm 149 (savefile.ini)
    ra(292, "achievemaxhp", "achievemaxhp", -5, 0.0, 7356, 7364), // CODE 17 read arm 150 (savefile.ini)
    ra(293, "getmoney", "getmoney", -5, 0.0, 7404, 7412), // CODE 17 read arm 151 (savefile.ini)
    ra(294, "hitmaxlevel", "hitmaxlevel", -5, 0.0, 7452, 7460), // CODE 17 read arm 152 (savefile.ini)
    ra(295, "weaponswapped", "weaponswapped", -5, 0.0, 7500, 7508), // CODE 17 read arm 153 (savefile.ini)
    ra(134, "coinmultiply", "coinmultiply", -5, 0.0, 7548, 7556), // CODE 17 read arm 154 (savefile.ini)
    ra(296, "roomtownvisited", "roomtownvisited", -5, 0.0, 7596, 7604), // CODE 17 read arm 155 (savefile.ini)
    ra(297, "level1visited", "level1visited", -5, 0.0, 7644, 7652), // CODE 17 read arm 156 (savefile.ini)
    ra(298, "level2visited", "level2visited", -5, 0.0, 7692, 7700), // CODE 17 read arm 157 (savefile.ini)
    ra(299, "level3visited", "level3visited", -5, 0.0, 7740, 7748), // CODE 17 read arm 158 (savefile.ini)
    ra(300, "level4visited", "level4visited", -5, 0.0, 7788, 7796), // CODE 17 read arm 159 (savefile.ini)
    ra(301, "level5visited", "level5visited", -5, 0.0, 7836, 7844), // CODE 17 read arm 160 (savefile.ini)
    ra(302, "level6visited", "level6visited", -5, 0.0, 7884, 7892), // CODE 17 read arm 161 (savefile.ini)
    ra(303, "level7visited", "level7visited", -5, 0.0, 7932, 7940), // CODE 17 read arm 162 (savefile.ini)
    ra(304, "level8visited", "level8visited", -5, 0.0, 7980, 7988), // CODE 17 read arm 163 (savefile.ini)
    ra(305, "level8avisited", "level8avisited", -5, 0.0, 8028, 8036), // CODE 17 read arm 164 (savefile.ini)
    ra(306, "boss1visited", "boss1visited", -5, 0.0, 8076, 8084), // CODE 17 read arm 165 (savefile.ini)
    ra(307, "level9visited", "level9visited", -5, 0.0, 8124, 8132), // CODE 17 read arm 166 (savefile.ini)
    ra(308, "level9avisited", "level9avisited", -5, 0.0, 8172, 8180), // CODE 17 read arm 167 (savefile.ini)
    ra(309, "level10visited", "level10visited", -5, 0.0, 8220, 8228), // CODE 17 read arm 168 (savefile.ini)
    ra(310, "level11visited", "level11visited", -5, 0.0, 8268, 8276), // CODE 17 read arm 169 (savefile.ini)
    ra(311, "level11avisited", "level11avisited", -5, 0.0, 8316, 8324), // CODE 17 read arm 170 (savefile.ini)
    ra(312, "level12visited", "level12visited", -5, 0.0, 8364, 8372), // CODE 17 read arm 171 (savefile.ini)
    ra(313, "level13visited", "level13visited", -5, 0.0, 8412, 8420), // CODE 17 read arm 172 (savefile.ini)
    ra(314, "level13avisited", "level13avisited", -5, 0.0, 8460, 8468), // CODE 17 read arm 173 (savefile.ini)
    ra(315, "level14visited", "level14visited", -5, 0.0, 8508, 8516), // CODE 17 read arm 174 (savefile.ini)
    ra(316, "level14avisited", "level14avisited", -5, 0.0, 8556, 8564), // CODE 17 read arm 175 (savefile.ini)
    ra(317, "level15visited", "level15visited", -5, 0.0, 8604, 8612), // CODE 17 read arm 176 (savefile.ini)
    ra(318, "level15avisited", "level15avisited", -5, 0.0, 8652, 8660), // CODE 17 read arm 177 (savefile.ini)
    ra(319, "level16visited", "level16visited", -5, 0.0, 8700, 8708), // CODE 17 read arm 178 (savefile.ini)
    ra(320, "level16avisited", "level16avisited", -5, 0.0, 8748, 8756), // CODE 17 read arm 179 (savefile.ini)
    ra(321, "level17visited", "level17visited", -5, 0.0, 8796, 8804), // CODE 17 read arm 180 (savefile.ini)
    ra(322, "level17avisited", "level17avisited", -5, 0.0, 8844, 8852), // CODE 17 read arm 181 (savefile.ini)
    ra(323, "boss2visited", "boss2visited", -5, 0.0, 8892, 8900), // CODE 17 read arm 182 (savefile.ini)
    ra(324, "room31visited", "room31visited", -5, 0.0, 8940, 8948), // CODE 17 read arm 183 (savefile.ini)
    ra(325, "room32visited", "room32visited", -5, 0.0, 8988, 8996), // CODE 17 read arm 184 (savefile.ini)
    ra(326, "room33visited", "room33visited", -5, 0.0, 9036, 9044), // CODE 17 read arm 185 (savefile.ini)
    ra(327, "room34visited", "room34visited", -5, 0.0, 9084, 9092), // CODE 17 read arm 186 (savefile.ini)
    ra(328, "room35visited", "room35visited", -5, 0.0, 9132, 9140), // CODE 17 read arm 187 (savefile.ini)
    ra(329, "room36visited", "room36visited", -5, 0.0, 9180, 9188), // CODE 17 read arm 188 (savefile.ini)
    ra(330, "room37visited", "room37visited", -5, 0.0, 9228, 9236), // CODE 17 read arm 189 (savefile.ini)
    ra(331, "room38visited", "room38visited", -5, 0.0, 9276, 9284), // CODE 17 read arm 190 (savefile.ini)
    ra(332, "room39visited", "room39visited", -5, 0.0, 9324, 9332), // CODE 17 read arm 191 (savefile.ini)
    ra(333, "room40visited", "room40visited", -5, 0.0, 9372, 9380), // CODE 17 read arm 192 (savefile.ini)
    ra(334, "room41visited", "room41visited", -5, 0.0, 9420, 9428), // CODE 17 read arm 193 (savefile.ini)
    ra(335, "room42visited", "room42visited", -5, 0.0, 9468, 9476), // CODE 17 read arm 194 (savefile.ini)
    ra(336, "room43visited", "room43visited", -5, 0.0, 9516, 9524), // CODE 17 read arm 195 (savefile.ini)
    ra(337, "room44visited", "room44visited", -5, 0.0, 9564, 9572), // CODE 17 read arm 196 (savefile.ini)
    ra(338, "room45visited", "room45visited", -5, 0.0, 9612, 9620), // CODE 17 read arm 197 (savefile.ini)
    ra(339, "room46visited", "room46visited", -5, 0.0, 9660, 9668), // CODE 17 read arm 198 (savefile.ini)
    ra(340, "room47visited", "room47visited", -5, 0.0, 9708, 9716), // CODE 17 read arm 199 (savefile.ini)
    ra(341, "room48visited", "room48visited", -5, 0.0, 9756, 9764), // CODE 17 read arm 200 (savefile.ini)
    ra(342, "room49visited", "room49visited", -5, 0.0, 9804, 9812), // CODE 17 read arm 201 (savefile.ini)
    ra(343, "room50visited", "room50visited", -5, 0.0, 9852, 9860), // CODE 17 read arm 202 (savefile.ini)
    ra(344, "boss3visited", "boss3visited", -5, 0.0, 9900, 9908), // CODE 17 read arm 203 (savefile.ini)
    ra(345, "room51visited", "room51visited", -5, 0.0, 9948, 9956), // CODE 17 read arm 204 (savefile.ini)
    ra(346, "room52visited", "room52visited", -5, 0.0, 9996, 10004), // CODE 17 read arm 205 (savefile.ini)
    ra(347, "room53visited", "room53visited", -5, 0.0, 10044, 10052), // CODE 17 read arm 206 (savefile.ini)
    ra(348, "room54visited", "room54visited", -5, 0.0, 10092, 10100), // CODE 17 read arm 207 (savefile.ini)
    ra(349, "room55visited", "room55visited", -5, 0.0, 10140, 10148), // CODE 17 read arm 208 (savefile.ini)
    ra(350, "room56visited", "room56visited", -5, 0.0, 10188, 10196), // CODE 17 read arm 209 (savefile.ini)
    ra(351, "room57visited", "room57visited", -5, 0.0, 10236, 10244), // CODE 17 read arm 210 (savefile.ini)
    ra(352, "room58visited", "room58visited", -5, 0.0, 10284, 10292), // CODE 17 read arm 211 (savefile.ini)
    ra(353, "room59visited", "room59visited", -5, 0.0, 10332, 10340), // CODE 17 read arm 212 (savefile.ini)
    ra(354, "room60visited", "room60visited", -5, 0.0, 10380, 10388), // CODE 17 read arm 213 (savefile.ini)
    ra(355, "room61visited", "room61visited", -5, 0.0, 10428, 10436), // CODE 17 read arm 214 (savefile.ini)
    ra(356, "room62visited", "room62visited", -5, 0.0, 10476, 10484), // CODE 17 read arm 215 (savefile.ini)
    ra(357, "room63visited", "room63visited", -5, 0.0, 10524, 10532), // CODE 17 read arm 216 (savefile.ini)
    ra(358, "room64visited", "room64visited", -5, 0.0, 10572, 10580), // CODE 17 read arm 217 (savefile.ini)
    ra(359, "room65visited", "room65visited", -5, 0.0, 10620, 10628), // CODE 17 read arm 218 (savefile.ini)
    ra(360, "boss4visited", "boss4visited", -5, 0.0, 10668, 10676), // CODE 17 read arm 219 (savefile.ini)
    ra(361, "room66visited", "room66visited", -5, 0.0, 10716, 10724), // CODE 17 read arm 220 (savefile.ini)
    ra(362, "room67visited", "room67visited", -5, 0.0, 10764, 10772), // CODE 17 read arm 221 (savefile.ini)
    ra(363, "room68visited", "room68visited", -5, 0.0, 10812, 10820), // CODE 17 read arm 222 (savefile.ini)
    ra(364, "room69visited", "room69visited", -5, 0.0, 10860, 10868), // CODE 17 read arm 223 (savefile.ini)
    ra(365, "room70visited", "room70visited", -5, 0.0, 10908, 10916), // CODE 17 read arm 224 (savefile.ini)
    ra(366, "room71visited", "room71visited", -5, 0.0, 10956, 10964), // CODE 17 read arm 225 (savefile.ini)
    ra(367, "room72visited", "room72visited", -5, 0.0, 11004, 11012), // CODE 17 read arm 226 (savefile.ini)
    ra(368, "room73visited", "room73visited", -5, 0.0, 11052, 11060), // CODE 17 read arm 227 (savefile.ini)
    ra(369, "room74visited", "room74visited", -5, 0.0, 11100, 11108), // CODE 17 read arm 228 (savefile.ini)
    ra(370, "room75visited", "room75visited", -5, 0.0, 11148, 11156), // CODE 17 read arm 229 (savefile.ini)
    ra(371, "room76visited", "room76visited", -5, 0.0, 11196, 11204), // CODE 17 read arm 230 (savefile.ini)
    ra(372, "room77visited", "room77visited", -5, 0.0, 11244, 11252), // CODE 17 read arm 231 (savefile.ini)
    ra(373, "room78visited", "room78visited", -5, 0.0, 11292, 11300), // CODE 17 read arm 232 (savefile.ini)
    ra(374, "room79visited", "room79visited", -5, 0.0, 11340, 11348), // CODE 17 read arm 233 (savefile.ini)
    ra(375, "room80visited", "room80visited", -5, 0.0, 11388, 11396), // CODE 17 read arm 234 (savefile.ini)
    ra(376, "room81visited", "room81visited", -5, 0.0, 11436, 11444), // CODE 17 read arm 235 (savefile.ini)
    ra(377, "room82visited", "room82visited", -5, 0.0, 11484, 11492), // CODE 17 read arm 236 (savefile.ini)
    ra(378, "boss5visited", "boss5visited", -5, 0.0, 11532, 11540), // CODE 17 read arm 237 (savefile.ini)
    ra(379, "room83visited", "room83visited", -5, 0.0, 11580, 11588), // CODE 17 read arm 238 (savefile.ini)
    ra(380, "room84visited", "room84visited", -5, 0.0, 11628, 11636), // CODE 17 read arm 239 (savefile.ini)
    ra(381, "room85visited", "room85visited", -5, 0.0, 11676, 11684), // CODE 17 read arm 240 (savefile.ini)
    ra(382, "room86visited", "room86visited", -5, 0.0, 11724, 11732), // CODE 17 read arm 241 (savefile.ini)
    ra(383, "room87visited", "room87visited", -5, 0.0, 11772, 11780), // CODE 17 read arm 242 (savefile.ini)
    ra(384, "room88visited", "room88visited", -5, 0.0, 11820, 11828), // CODE 17 read arm 243 (savefile.ini)
    ra(385, "room89visited", "room89visited", -5, 0.0, 11868, 11876), // CODE 17 read arm 244 (savefile.ini)
    ra(386, "room90visited", "room90visited", -5, 0.0, 11916, 11924), // CODE 17 read arm 245 (savefile.ini)
    ra(387, "room91visited", "room91visited", -5, 0.0, 11964, 11972), // CODE 17 read arm 246 (savefile.ini)
    ra(388, "room92visited", "room92visited", -5, 0.0, 12012, 12020), // CODE 17 read arm 247 (savefile.ini)
    ra(389, "room93visited", "room93visited", -5, 0.0, 12060, 12068), // CODE 17 read arm 248 (savefile.ini)
    ra(390, "room94visited", "room94visited", -5, 0.0, 12108, 12116), // CODE 17 read arm 249 (savefile.ini)
    ra(391, "room95visited", "room95visited", -5, 0.0, 12156, 12164), // CODE 17 read arm 250 (savefile.ini)
    ra(392, "room96visited", "room96visited", -5, 0.0, 12204, 12212), // CODE 17 read arm 251 (savefile.ini)
    ra(393, "room97visited", "room97visited", -5, 0.0, 12252, 12260), // CODE 17 read arm 252 (savefile.ini)
    ra(394, "room98visited", "room98visited", -5, 0.0, 12300, 12308), // CODE 17 read arm 253 (savefile.ini)
    ra(395, "room99visited", "room99visited", -5, 0.0, 12348, 12356), // CODE 17 read arm 254 (savefile.ini)
    ra(396, "room100visited", "room100visited", -5, 0.0, 12396, 12404), // CODE 17 read arm 255 (savefile.ini)
    ra(397, "room101visited", "room101visited", -5, 0.0, 12444, 12452), // CODE 17 read arm 256 (savefile.ini)
    ra(398, "room102visited", "room102visited", -5, 0.0, 12492, 12500), // CODE 17 read arm 257 (savefile.ini)
    ra(399, "room103visited", "room103visited", -5, 0.0, 12540, 12548), // CODE 17 read arm 258 (savefile.ini)
    ra(400, "boss6visited", "boss6visited", -5, 0.0, 12588, 12596), // CODE 17 read arm 259 (savefile.ini)
    ra(23, "soundmute", "soundmute", -5, 0.0, 12636, 12644), // CODE 17 read arm 260 (savefile.ini)
    ra(22, "musicmute", "musicmute", -5, 0.0, 12684, 12692), // CODE 17 read arm 261 (savefile.ini)
    ra(401, "beartouched", "beartouched", -5, 0.0, 12732, 12740), // CODE 17 read arm 262 (savefile.ini)
    ra(402, "knifetouched", "knifetouched", -5, 0.0, 12780, 12788), // CODE 17 read arm 263 (savefile.ini)
    ra(403, "spidertouched", "spidertouched", -5, 0.0, 12828, 12836), // CODE 17 read arm 264 (savefile.ini)
    ra(404, "battouched", "battouched", -5, 0.0, 12876, 12884), // CODE 17 read arm 265 (savefile.ini)
    ra(405, "wolftouched", "wolftouched", -5, 0.0, 12924, 12932), // CODE 17 read arm 266 (savefile.ini)
    ra(406, "pistolbandittouched", "pistolbandittouched", -5, 0.0, 12972, 12980), // CODE 17 read arm 267 (savefile.ini)
    ra(407, "boss1touched", "boss1touched", -5, 0.0, 13020, 13028), // CODE 17 read arm 268 (savefile.ini)
    ra(408, "turrettouched", "turrettouched", -5, 0.0, 13068, 13076), // CODE 17 read arm 269 (savefile.ini)
    ra(409, "slimetouched", "slimetouched", -5, 0.0, 13116, 13124), // CODE 17 read arm 270 (savefile.ini)
    ra(410, "boss2touched", "boss2touched", -5, 0.0, 13164, 13172), // CODE 17 read arm 271 (savefile.ini)
    ra(411, "zombietouched", "zombietouched", -5, 0.0, 13212, 13220), // CODE 17 read arm 272 (savefile.ini)
    ra(412, "redslimetouched", "redslimetouched", -5, 0.0, 13260, 13268), // CODE 17 read arm 273 (savefile.ini)
    ra(413, "skeletontouched", "skeletontouched", -5, 0.0, 13308, 13316), // CODE 17 read arm 274 (savefile.ini)
    ra(414, "hulkingbandittouched", "hulkingbandittouched", -5, 0.0, 13356, 13364), // CODE 17 read arm 275 (savefile.ini)
    ra(415, "beetouched", "beetouched", -5, 0.0, 13404, 13412), // CODE 17 read arm 276 (savefile.ini)
    ra(416, "boss3touched", "boss3touched", -5, 0.0, 13452, 13460), // CODE 17 read arm 277 (savefile.ini)
    ra(417, "firehulktouched", "firehulktouched", -5, 0.0, 13500, 13508), // CODE 17 read arm 278 (savefile.ini)
    ra(418, "boss4touched", "boss4touched", -5, 0.0, 13548, 13556), // CODE 17 read arm 279 (savefile.ini)
    ra(419, "boss5touched", "boss5touched", -5, 0.0, 13596, 13604), // CODE 17 read arm 280 (savefile.ini)
    ra(420, "boss6touched", "boss6touched", -5, 0.0, 13644, 13652), // CODE 17 read arm 281 (savefile.ini)
    ra(423, "levelchallenge1visited", "levelchallenge1visited", -5, 0.0, 29740, 29748), // CODE 17 read arm 282 (savefile2.ini)
    ra(424, "levelchallenge2visited", "levelchallenge2visited", -5, 0.0, 29788, 29796), // CODE 17 read arm 283 (savefile2.ini)
    ra(425, "levelchallenge3visited", "levelchallenge3visited", -5, 0.0, 29836, 29844), // CODE 17 read arm 284 (savefile2.ini)
    ra(426, "levelchallenge4visited", "levelchallenge4visited", -5, 0.0, 29884, 29892), // CODE 17 read arm 285 (savefile2.ini)
    ra(427, "levelchallenge5visited", "levelchallenge5visited", -5, 0.0, 29932, 29940), // CODE 17 read arm 286 (savefile2.ini)
    ra(482, "talkedtolloyd16", "talkedtolloyd16", -5, 0.0, 29980, 29988), // CODE 17 read arm 287 (savefile2.ini)
    ra(429, "twentyfivebears", "twentyfivebears", -5, 0.0, 30464, 30472), // CODE 17 read arm 288 (savefile3.ini)
    ra(430, "onehundredbears", "onehundredbears", -5, 0.0, 30512, 30520), // CODE 17 read arm 289 (savefile3.ini)
    ra(431, "twentyfivewolf", "twentyfivewolf", -5, 0.0, 30560, 30568), // CODE 17 read arm 290 (savefile3.ini)
    ra(432, "onehundredwolf", "onehundredwolf", -5, 0.0, 30608, 30616), // CODE 17 read arm 291 (savefile3.ini)
    ra(433, "twentyfiveknifebandit", "twentyfiveknifebandit", -5, 0.0, 30656, 30664), // CODE 17 read arm 292 (savefile3.ini)
    ra(434, "onehundredknifebandit", "onehundredknifebandit", -5, 0.0, 30704, 30712), // CODE 17 read arm 293 (savefile3.ini)
    ra(435, "twentyfivepistolthug", "twentyfivepistolthug", -5, 0.0, 30752, 30760), // CODE 17 read arm 294 (savefile3.ini)
    ra(436, "onehundredpistolthug", "onehundredpistolthug", -5, 0.0, 30800, 30808), // CODE 17 read arm 295 (savefile3.ini)
    ra(437, "twentyfivespiders", "twentyfivespiders", -5, 0.0, 30848, 30856), // CODE 17 read arm 296 (savefile3.ini)
    ra(438, "onehundredspiders", "onehundredspiders", -5, 0.0, 30896, 30904), // CODE 17 read arm 297 (savefile3.ini)
    ra(439, "twentyfiveslimes", "twentyfiveslimes", -5, 0.0, 30944, 30952), // CODE 17 read arm 298 (savefile3.ini)
    ra(440, "onehundredslimes", "onehundredslimes", -5, 0.0, 30992, 31000), // CODE 17 read arm 299 (savefile3.ini)
    ra(441, "twentyfivefireslimes", "twentyfivefireslimes", -5, 0.0, 31040, 31048), // CODE 17 read arm 300 (savefile3.ini)
    ra(442, "onehundredfireslimes", "onehundredfireslimes", -5, 0.0, 31088, 31096), // CODE 17 read arm 301 (savefile3.ini)
    ra(443, "twentyfivehulking", "twentyfivehulking", -5, 0.0, 31136, 31144), // CODE 17 read arm 302 (savefile3.ini)
    ra(444, "onehundredhulking", "onehundredhulking", -5, 0.0, 31184, 31192), // CODE 17 read arm 303 (savefile3.ini)
    ra(445, "twentyfiveghost", "twentyfiveghost", -5, 0.0, 31232, 31240), // CODE 17 read arm 304 (savefile3.ini)
    ra(446, "onehundredghost", "onehundredghost", -5, 0.0, 31280, 31288), // CODE 17 read arm 305 (savefile3.ini)
    ra(447, "twentyfiveskeleton", "twentyfiveskeleton", -5, 0.0, 31328, 31336), // CODE 17 read arm 306 (savefile3.ini)
    ra(448, "onehundredskeleton", "onehundredskeleton", -5, 0.0, 31376, 31384), // CODE 17 read arm 307 (savefile3.ini)
    ra(449, "twentyfivezombie", "twentyfivezombie", -5, 0.0, 31424, 31432), // CODE 17 read arm 308 (savefile3.ini)
    ra(450, "onehundredzombie", "onehundredzombie", -5, 0.0, 31472, 31480), // CODE 17 read arm 309 (savefile3.ini)
    ra(451, "twentyfivebalrog", "twentyfivebalrog", -5, 0.0, 31520, 31528), // CODE 17 read arm 310 (savefile3.ini)
    ra(452, "onehundredbalrog", "onehundredbalrog", -5, 0.0, 31568, 31576), // CODE 17 read arm 311 (savefile3.ini)
    ra(453, "twentyfivebat", "twentyfivebat", -5, 0.0, 31616, 31624), // CODE 17 read arm 312 (savefile3.ini)
    ra(454, "onehundredbat", "onehundredbat", -5, 0.0, 31664, 31672), // CODE 17 read arm 313 (savefile3.ini)
    ra(455, "twentyfivetrap", "twentyfivetrap", -5, 0.0, 31712, 31720), // CODE 17 read arm 314 (savefile3.ini)
    ra(456, "onehundredtrap", "onehundredtrap", -5, 0.0, 31760, 31768), // CODE 17 read arm 315 (savefile3.ini)
    ra(457, "twentyfiveenemies", "twentyfiveenemies", -5, 0.0, 31808, 31816), // CODE 17 read arm 316 (savefile3.ini)
    ra(458, "onehundredenemies", "onehundredenemies", -5, 0.0, 31856, 31864), // CODE 17 read arm 317 (savefile3.ini)
    ra(459, "fivehundredenemies", "fivehundredenemies", -5, 0.0, 31904, 31912), // CODE 17 read arm 318 (savefile3.ini)
    ra(460, "onethousandenemies", "onethousandenemies", -5, 0.0, 31952, 31960), // CODE 17 read arm 319 (savefile3.ini)
    ra(461, "achievementboughtjump", "achievementboughtjump", -5, 0.0, 32000, 32008), // CODE 17 read arm 320 (savefile3.ini)
    ra(462, "achievmentboughtupgrades", "achievmentboughtupgrades", -5, 0.0, 32048, 32056), // CODE 17 read arm 321 (savefile3.ini)
    ra(463, "hitmaxcallylevel", "hitmaxcallylevel", -5, 0.0, 32096, 32104), // CODE 17 read arm 322 (savefile3.ini)
    ra(464, "hitmoney", "hitmoney", -5, 0.0, 32144, 32152), // CODE 17 read arm 323 (savefile3.ini)
];

#[derive(Clone, Copy, Debug)]
struct WriteArm {
    key_sid: usize,
    key: &'static str,
    /// Global the written value is loaded from (sel -5, or -1 for `score`).
    source: &'static str,
    sel: i32,
    /// code_offset of the `call ini_write_real`.
    call_off: usize,
    /// code_offset of the `load` that pushes its value.
    load_off: usize,
}

/// The 324 `ini_write_real` arms of CODE 17, in bytecode order. Four keys
/// appear twice (278 distinct keys in savefile.ini).
#[rustfmt::skip]
const WRITE_ARMS: [WriteArm; 324] = [
    wa(148, "talkedtolloyd1", "talkedtolloyd1", -5, 17268, 17236), // CODE 17 write arm 0 (savefile.ini)
    wa(151, "talkedtolloyd2", "talkedtolloyd2", -5, 17312, 17280), // CODE 17 write arm 1 (savefile.ini)
    wa(152, "talkedtolloyd3", "talkedtolloyd3", -5, 17356, 17324), // CODE 17 write arm 2 (savefile.ini)
    wa(153, "talkedtolloyd4", "talkedtolloyd4", -5, 17400, 17368), // CODE 17 write arm 3 (savefile.ini)
    wa(154, "talkedtolloyd5", "talkedtolloyd5", -5, 17444, 17412), // CODE 17 write arm 4 (savefile.ini)
    wa(155, "talkedtolloyd6", "talkedtolloyd6", -5, 17488, 17456), // CODE 17 write arm 5 (savefile.ini)
    wa(156, "talkedtolloyd7", "talkedtolloyd7", -5, 17532, 17500), // CODE 17 write arm 6 (savefile.ini)
    wa(157, "talkedtolloyd8", "talkedtolloyd8", -5, 17576, 17544), // CODE 17 write arm 7 (savefile.ini)
    wa(158, "talkedtolloyd9", "talkedtolloyd9", -5, 17620, 17588), // CODE 17 write arm 8 (savefile.ini)
    wa(159, "talkedtolloyd10", "talkedtolloyd10", -5, 17664, 17632), // CODE 17 write arm 9 (savefile.ini)
    wa(160, "talkedtolloyd11", "talkedtolloyd11", -5, 17708, 17676), // CODE 17 write arm 10 (savefile.ini)
    wa(161, "talkedtolloyd12", "talkedtolloyd12", -5, 17752, 17720), // CODE 17 write arm 11 (savefile.ini)
    wa(162, "talkedtolloyd13", "talkedtolloyd13", -5, 17796, 17764), // CODE 17 write arm 12 (savefile.ini)
    wa(163, "talkedtolloyd14", "talkedtolloyd14", -5, 17840, 17808), // CODE 17 write arm 13 (savefile.ini)
    wa(164, "talkedtolloyd15", "talkedtolloyd15", -5, 17884, 17852), // CODE 17 write arm 14 (savefile.ini)
    wa(273, "bearskilled", "bearskilled", -5, 17928, 17896), // CODE 17 write arm 15 (savefile.ini)
    wa(167, "current_level", "level", -5, 17972, 17940), // CODE 17 write arm 16 (savefile.ini)
    wa(168, "current_maxhp", "maxhp", -5, 18016, 17984), // CODE 17 write arm 17 (savefile.ini)
    wa(169, "current_score", "score", -1, 18060, 18028), // CODE 17 write arm 18 (savefile.ini)
    wa(170, "current_XP", "experience", -5, 18104, 18072), // CODE 17 write arm 19 (savefile.ini)
    wa(171, "boss1dead", "boss1dead", -5, 18148, 18116), // CODE 17 write arm 20 (savefile.ini)
    wa(172, "boss2dead", "boss2dead", -5, 18192, 18160), // CODE 17 write arm 21 (savefile.ini)
    wa(173, "boss3dead", "boss3dead", -5, 18236, 18204), // CODE 17 write arm 22 (savefile.ini)
    wa(174, "boss4dead", "boss4dead", -5, 18280, 18248), // CODE 17 write arm 23 (savefile.ini)
    wa(175, "boss5dead", "boss5dead", -5, 18324, 18292), // CODE 17 write arm 24 (savefile.ini)
    wa(176, "boss6dead", "boss6dead", -5, 18368, 18336), // CODE 17 write arm 25 (savefile.ini)
    wa(177, "pistolbought", "pistolbought", -5, 18412, 18380), // CODE 17 write arm 26 (savefile.ini)
    wa(204, "bombgunbought", "bombgunbought", -5, 18456, 18424), // CODE 17 write arm 27 (savefile.ini)
    wa(205, "bombgunxp", "bombgunxp", -5, 18500, 18468), // CODE 17 write arm 28 (savefile.ini)
    wa(206, "bombgunxptolevelup", "bombgunxptolevelup", -5, 18544, 18512), // CODE 17 write arm 29 (savefile.ini)
    wa(207, "bombgunlevel", "bombgunlevel", -5, 18588, 18556), // CODE 17 write arm 30 (savefile.ini)
    wa(196, "bladegunbought", "bladegunbought", -5, 18632, 18600), // CODE 17 write arm 31 (savefile.ini)
    wa(197, "flamethrowerbought", "flamethrowerbought", -5, 18676, 18644), // CODE 17 write arm 32 (savefile.ini)
    wa(195, "bowbought", "bowbought", -5, 18720, 18688), // CODE 17 write arm 33 (savefile.ini)
    wa(78, "energywavebought", "energywavebought", -5, 18764, 18732), // CODE 17 write arm 34 (savefile.ini)
    wa(186, "strengthupgradebought", "strengthupgradebought", -5, 18808, 18776), // CODE 17 write arm 35 (savefile.ini)
    wa(187, "strengthupgrade2bought", "strengthupgrade2bought", -5, 18852, 18820), // CODE 17 write arm 36 (savefile.ini)
    wa(70, "healthregenbought", "healthregenbought", -5, 18896, 18864), // CODE 17 write arm 37 (savefile.ini)
    wa(178, "shotgunbought", "shotgunbought", -5, 18940, 18908), // CODE 17 write arm 38 (savefile.ini)
    wa(127, "swordupgradebought", "swordupgradebought", -5, 18984, 18952), // CODE 17 write arm 39 (savefile.ini)
    wa(129, "swordupgrade2bought", "swordupgrade2bought", -5, 19028, 18996), // CODE 17 write arm 40 (savefile.ini)
    wa(130, "swordupgrade3bought", "swordupgrade3bought", -5, 19072, 19040), // CODE 17 write arm 41 (savefile.ini)
    wa(179, "powerupgradebought", "powerupgradebought", -5, 19116, 19084), // CODE 17 write arm 42 (savefile.ini)
    wa(180, "powerupgrade2bought", "powerupgrade2bought", -5, 19160, 19128), // CODE 17 write arm 43 (savefile.ini)
    wa(181, "powerupgrade3bought", "powerupgrade3bought", -5, 19204, 19172), // CODE 17 write arm 44 (savefile.ini)
    wa(182, "assaultriflebought", "assaultriflebought", -5, 19248, 19216), // CODE 17 write arm 45 (savefile.ini)
    wa(183, "rocketbought", "rocketbought", -5, 19292, 19260), // CODE 17 write arm 46 (savefile.ini)
    wa(184, "laserbought", "laserbought", -5, 19336, 19304), // CODE 17 write arm 47 (savefile.ini)
    wa(185, "icegunbought", "icegunbought", -5, 19380, 19348), // CODE 17 write arm 48 (savefile.ini)
    wa(128, "sword", "sword", -5, 19424, 19392), // CODE 17 write arm 49 (savefile.ini)
    wa(195, "bowbought", "bowbought", -5, 19468, 19436), // CODE 17 write arm 50 (savefile.ini)
    wa(196, "bladegunbought", "bladegunbought", -5, 19512, 19480), // CODE 17 write arm 51 (savefile.ini)
    wa(188, "triplejumpbought", "triplejumpbought", -5, 19556, 19524), // CODE 17 write arm 52 (savefile.ini)
    wa(190, "triplejumpactive", "tjumpactive", -5, 19600, 19568), // CODE 17 write arm 53 (savefile.ini)
    wa(191, "coinmultiplier2bought", "coinmultiplier2bought", -5, 19644, 19612), // CODE 17 write arm 54 (savefile.ini)
    wa(192, "coinmultiplier5bought", "coinmultiplier5bought", -5, 19688, 19656), // CODE 17 write arm 55 (savefile.ini)
    wa(193, "maxhpupgradebought", "maxhpupgradebought", -5, 19732, 19700), // CODE 17 write arm 56 (savefile.ini)
    wa(194, "maxhpupgrade2bought", "maxhpupgrade2bought", -5, 19776, 19744), // CODE 17 write arm 57 (savefile.ini)
    wa(139, "haskey", "haskey", -5, 19820, 19788), // CODE 17 write arm 58 (savefile.ini)
    wa(208, "xptolevelup", "xptolevelup", -5, 19864, 19832), // CODE 17 write arm 59 (savefile.ini)
    wa(209, "pistolxp", "pistolxp", -5, 19908, 19876), // CODE 17 write arm 60 (savefile.ini)
    wa(210, "pistolxptolevelup", "pistolxptolevelup", -5, 19952, 19920), // CODE 17 write arm 61 (savefile.ini)
    wa(202, "bladegunxp", "bladegunxp", -5, 19996, 19964), // CODE 17 write arm 62 (savefile.ini)
    wa(203, "bladegunxptolevelup", "bladegunxptolevelup", -5, 20040, 20008), // CODE 17 write arm 63 (savefile.ini)
    wa(200, "flamethrowerxp", "flamethrowerxp", -5, 20084, 20052), // CODE 17 write arm 64 (savefile.ini)
    wa(201, "flamethrowerxptolevelup", "flamethrowerxptolevelup", -5, 20128, 20096), // CODE 17 write arm 65 (savefile.ini)
    wa(198, "bowxp", "bowxp", -5, 20172, 20140), // CODE 17 write arm 66 (savefile.ini)
    wa(199, "bowxptolevelup", "bowxptolevelup", -5, 20216, 20184), // CODE 17 write arm 67 (savefile.ini)
    wa(211, "shotgunxp", "shotgunxp", -5, 20260, 20228), // CODE 17 write arm 68 (savefile.ini)
    wa(212, "shotgunxptolevelup", "shotgunxptolevelup", -5, 20304, 20272), // CODE 17 write arm 69 (savefile.ini)
    wa(213, "assaultriflexp", "assaultriflexp", -5, 20348, 20316), // CODE 17 write arm 70 (savefile.ini)
    wa(214, "assaultriflexptolevelup", "assaultriflexptolevelup", -5, 20392, 20360), // CODE 17 write arm 71 (savefile.ini)
    wa(215, "rocketxp", "rocketxp", -5, 20436, 20404), // CODE 17 write arm 72 (savefile.ini)
    wa(216, "rocketxptolevelup", "rocketxptolevelup", -5, 20480, 20448), // CODE 17 write arm 73 (savefile.ini)
    wa(217, "laserxp", "laserxp", -5, 20524, 20492), // CODE 17 write arm 74 (savefile.ini)
    wa(218, "laserxptolevelup", "laserxptolevelup", -5, 20568, 20536), // CODE 17 write arm 75 (savefile.ini)
    wa(219, "icegunxp", "icegunxp", -5, 20612, 20580), // CODE 17 write arm 76 (savefile.ini)
    wa(220, "icegunxptolevelup", "icegunxptolevelup", -5, 20656, 20624), // CODE 17 write arm 77 (savefile.ini)
    wa(198, "bowxp", "bowxp", -5, 20700, 20668), // CODE 17 write arm 78 (savefile.ini)
    wa(199, "bowxptolevelup", "bowxptolevelup", -5, 20744, 20712), // CODE 17 write arm 79 (savefile.ini)
    wa(221, "pistollevel", "pistollevel", -5, 20788, 20756), // CODE 17 write arm 80 (savefile.ini)
    wa(222, "shotgunlevel", "shotgunlevel", -5, 20832, 20800), // CODE 17 write arm 81 (savefile.ini)
    wa(87, "assaultriflelevel", "assaultriflelevel", -5, 20876, 20844), // CODE 17 write arm 82 (savefile.ini)
    wa(481, "grenadelevel", "grenadelevel", -5, 20920, 20888), // CODE 17 write arm 83 (savefile.ini)
    wa(223, "rocketlevel", "rocketlevel", -5, 20964, 20932), // CODE 17 write arm 84 (savefile.ini)
    wa(224, "laserlevel", "laserlevel", -5, 21008, 20976), // CODE 17 write arm 85 (savefile.ini)
    wa(225, "icegunlevel", "icegunlevel", -5, 21052, 21020), // CODE 17 write arm 86 (savefile.ini)
    wa(226, "bowlevel", "bowlevel", -5, 21096, 21064), // CODE 17 write arm 87 (savefile.ini)
    wa(227, "bladegunlevel", "bladegunlevel", -5, 21140, 21108), // CODE 17 write arm 88 (savefile.ini)
    wa(228, "flamethrowerlevel", "flamethrowerlevel", -5, 21184, 21152), // CODE 17 write arm 89 (savefile.ini)
    wa(229, "boomerangbought", "boomerangbought", -5, 21228, 21196), // CODE 17 write arm 90 (savefile.ini)
    wa(230, "boomerangxp", "boomerangxp", -5, 21272, 21240), // CODE 17 write arm 91 (savefile.ini)
    wa(231, "boomeranglevel", "boomeranglevel", -5, 21316, 21284), // CODE 17 write arm 92 (savefile.ini)
    wa(232, "boomerangxptolevelup", "boomerangxptolevelup", -5, 21360, 21328), // CODE 17 write arm 93 (savefile.ini)
    wa(233, "spikegunbought", "spikegunbought", -5, 21404, 21372), // CODE 17 write arm 94 (savefile.ini)
    wa(234, "spikegunxp", "spikegunxp", -5, 21448, 21416), // CODE 17 write arm 95 (savefile.ini)
    wa(235, "spikegunlevel", "spikegunlevel", -5, 21492, 21460), // CODE 17 write arm 96 (savefile.ini)
    wa(236, "spikegunxptolevelup", "spikegunxptolevelup", -5, 21536, 21504), // CODE 17 write arm 97 (savefile.ini)
    wa(237, "drawchangepistol4", "drawchangepistol4", -5, 21580, 21548), // CODE 17 write arm 98 (savefile.ini)
    wa(238, "drawchangeshotgun4", "drawchangeshotgun4", -5, 21624, 21592), // CODE 17 write arm 99 (savefile.ini)
    wa(239, "drawchangeassaultrifle4", "drawchangeassaultrifle4", -5, 21668, 21636), // CODE 17 write arm 100 (savefile.ini)
    wa(240, "drawchangerocket4", "drawchangerocket4", -5, 21712, 21680), // CODE 17 write arm 101 (savefile.ini)
    wa(241, "drawchangelaser4", "drawchangelaser4", -5, 21756, 21724), // CODE 17 write arm 102 (savefile.ini)
    wa(242, "drawchangeicegun4", "drawchangeicegun4", -5, 21800, 21768), // CODE 17 write arm 103 (savefile.ini)
    wa(243, "drawchangebow4", "drawchangebow4", -5, 21844, 21812), // CODE 17 write arm 104 (savefile.ini)
    wa(244, "drawchangebladegun4", "drawchangebladegun4", -5, 21888, 21856), // CODE 17 write arm 105 (savefile.ini)
    wa(245, "drawchangeflamethrower4", "drawchangeflamethrower4", -5, 21932, 21900), // CODE 17 write arm 106 (savefile.ini)
    wa(246, "drawchangeboomerang4", "drawchangeboomerang4", -5, 21976, 21944), // CODE 17 write arm 107 (savefile.ini)
    wa(247, "drawchangespikegun4", "drawchangespikegun4", -5, 22020, 21988), // CODE 17 write arm 108 (savefile.ini)
    wa(248, "drawchangebombgun4", "drawchangebombgun4", -5, 22064, 22032), // CODE 17 write arm 109 (savefile.ini)
    wa(249, "drawchangepistol7", "drawchangepistol7", -5, 22108, 22076), // CODE 17 write arm 110 (savefile.ini)
    wa(250, "drawchangeshotgun7", "drawchangeshotgun7", -5, 22152, 22120), // CODE 17 write arm 111 (savefile.ini)
    wa(251, "drawchangeassaultrifle7", "drawchangeassaultrifle7", -5, 22196, 22164), // CODE 17 write arm 112 (savefile.ini)
    wa(252, "drawchangerocket7", "drawchangerocket7", -5, 22240, 22208), // CODE 17 write arm 113 (savefile.ini)
    wa(253, "drawchangelaser7", "drawchangelaser7", -5, 22284, 22252), // CODE 17 write arm 114 (savefile.ini)
    wa(254, "drawchangeicegun7", "drawchangeicegun7", -5, 22328, 22296), // CODE 17 write arm 115 (savefile.ini)
    wa(255, "drawchangebow7", "drawchangebow7", -5, 22372, 22340), // CODE 17 write arm 116 (savefile.ini)
    wa(256, "drawchangebladegun7", "drawchangebladegun7", -5, 22416, 22384), // CODE 17 write arm 117 (savefile.ini)
    wa(257, "drawchangeflamethrower7", "drawchangeflamethrower7", -5, 22460, 22428), // CODE 17 write arm 118 (savefile.ini)
    wa(258, "drawchangeboomerang7", "drawchangeboomerang7", -5, 22504, 22472), // CODE 17 write arm 119 (savefile.ini)
    wa(259, "drawchangespikegun7", "drawchangespikegun7", -5, 22548, 22516), // CODE 17 write arm 120 (savefile.ini)
    wa(260, "drawchangebombgun7", "drawchangebombgun7", -5, 22592, 22560), // CODE 17 write arm 121 (savefile.ini)
    wa(261, "drawchangepistol10", "drawchangepistol10", -5, 22636, 22604), // CODE 17 write arm 122 (savefile.ini)
    wa(262, "drawchangeshotgun10", "drawchangeshotgun10", -5, 22680, 22648), // CODE 17 write arm 123 (savefile.ini)
    wa(263, "drawchangeassaultrifle10", "drawchangeassaultrifle10", -5, 22724, 22692), // CODE 17 write arm 124 (savefile.ini)
    wa(264, "drawchangerocket10", "drawchangerocket10", -5, 22768, 22736), // CODE 17 write arm 125 (savefile.ini)
    wa(265, "drawchangelaser10", "drawchangelaser10", -5, 22812, 22780), // CODE 17 write arm 126 (savefile.ini)
    wa(266, "drawchangeicegun10", "drawchangeicegun10", -5, 22856, 22824), // CODE 17 write arm 127 (savefile.ini)
    wa(267, "drawchangebow10", "drawchangebow10", -5, 22900, 22868), // CODE 17 write arm 128 (savefile.ini)
    wa(268, "drawchangebladegun10", "drawchangebladegun10", -5, 22944, 22912), // CODE 17 write arm 129 (savefile.ini)
    wa(269, "drawchangeflamethrower10", "drawchangeflamethrower10", -5, 22988, 22956), // CODE 17 write arm 130 (savefile.ini)
    wa(270, "drawchangeboomerang10", "drawchangeboomerang10", -5, 23032, 23000), // CODE 17 write arm 131 (savefile.ini)
    wa(271, "drawchangespikegun10", "drawchangespikegun10", -5, 23076, 23044), // CODE 17 write arm 132 (savefile.ini)
    wa(272, "drawchangebombgun10", "drawchangebombgun10", -5, 23120, 23088), // CODE 17 write arm 133 (savefile.ini)
    wa(274, "knifebanditskilled", "knifebanditskilled", -5, 23164, 23132), // CODE 17 write arm 134 (savefile.ini)
    wa(275, "pistolthugskilled", "pistolthugskilled", -5, 23208, 23176), // CODE 17 write arm 135 (savefile.ini)
    wa(276, "chomperbotkilled", "chomperbotkilled", -5, 23252, 23220), // CODE 17 write arm 136 (savefile.ini)
    wa(277, "greenslimeskilled", "greenslimeskilled", -5, 23296, 23264), // CODE 17 write arm 137 (savefile.ini)
    wa(278, "wolfkilled", "wolfkilled", -5, 23340, 23308), // CODE 17 write arm 138 (savefile.ini)
    wa(279, "fireslimeskilled", "fireslimeskilled", -5, 23384, 23352), // CODE 17 write arm 139 (savefile.ini)
    wa(280, "hulkingbanditskilled", "hulkingbanditskilled", -5, 23428, 23396), // CODE 17 write arm 140 (savefile.ini)
    wa(281, "ghostskilled", "ghostskilled", -5, 23472, 23440), // CODE 17 write arm 141 (savefile.ini)
    wa(282, "skeletonskilled", "skeletonskilled", -5, 23516, 23484), // CODE 17 write arm 142 (savefile.ini)
    wa(283, "zombieskilled", "zombieskilled", -5, 23560, 23528), // CODE 17 write arm 143 (savefile.ini)
    wa(284, "firehulkskilled", "firehulkskilled", -5, 23604, 23572), // CODE 17 write arm 144 (savefile.ini)
    wa(285, "batskilled", "batskilled", -5, 23648, 23616), // CODE 17 write arm 145 (savefile.ini)
    wa(286, "trapskilled", "trapskilled", -5, 23692, 23660), // CODE 17 write arm 146 (savefile.ini)
    wa(287, "enemieskilled", "enemieskilled", -5, 23736, 23704), // CODE 17 write arm 147 (savefile.ini)
    wa(288, "boughtallguns", "boughtallguns", -5, 23780, 23748), // CODE 17 write arm 148 (savefile.ini)
    wa(289, "triplejumpachievement", "triplejumpachievement", -5, 23824, 23792), // CODE 17 write arm 149 (savefile.ini)
    wa(290, "boughtallupgrades", "boughtallupgrades", -5, 23868, 23836), // CODE 17 write arm 150 (savefile.ini)
    wa(291, "boughteverything", "boughteverything", -5, 23912, 23880), // CODE 17 write arm 151 (savefile.ini)
    wa(292, "achievemaxhp", "achievemaxhp", -5, 23956, 23924), // CODE 17 write arm 152 (savefile.ini)
    wa(293, "getmoney", "getmoney", -5, 24000, 23968), // CODE 17 write arm 153 (savefile.ini)
    wa(294, "hitmaxlevel", "hitmaxlevel", -5, 24044, 24012), // CODE 17 write arm 154 (savefile.ini)
    wa(296, "roomtownvisited", "roomtownvisited", -5, 24088, 24056), // CODE 17 write arm 155 (savefile.ini)
    wa(297, "level1visited", "level1visited", -5, 24132, 24100), // CODE 17 write arm 156 (savefile.ini)
    wa(298, "level2visited", "level2visited", -5, 24176, 24144), // CODE 17 write arm 157 (savefile.ini)
    wa(299, "level3visited", "level3visited", -5, 24220, 24188), // CODE 17 write arm 158 (savefile.ini)
    wa(300, "level4visited", "level4visited", -5, 24264, 24232), // CODE 17 write arm 159 (savefile.ini)
    wa(301, "level5visited", "level5visited", -5, 24308, 24276), // CODE 17 write arm 160 (savefile.ini)
    wa(302, "level6visited", "level6visited", -5, 24352, 24320), // CODE 17 write arm 161 (savefile.ini)
    wa(303, "level7visited", "level7visited", -5, 24396, 24364), // CODE 17 write arm 162 (savefile.ini)
    wa(304, "level8visited", "level8visited", -5, 24440, 24408), // CODE 17 write arm 163 (savefile.ini)
    wa(305, "level8avisited", "level8avisited", -5, 24484, 24452), // CODE 17 write arm 164 (savefile.ini)
    wa(306, "boss1visited", "boss1visited", -5, 24528, 24496), // CODE 17 write arm 165 (savefile.ini)
    wa(307, "level9visited", "level9visited", -5, 24572, 24540), // CODE 17 write arm 166 (savefile.ini)
    wa(308, "level9avisited", "level9avisited", -5, 24616, 24584), // CODE 17 write arm 167 (savefile.ini)
    wa(309, "level10visited", "level10visited", -5, 24660, 24628), // CODE 17 write arm 168 (savefile.ini)
    wa(310, "level11visited", "level11visited", -5, 24704, 24672), // CODE 17 write arm 169 (savefile.ini)
    wa(311, "level11avisited", "level11avisited", -5, 24748, 24716), // CODE 17 write arm 170 (savefile.ini)
    wa(312, "level12visited", "level12visited", -5, 24792, 24760), // CODE 17 write arm 171 (savefile.ini)
    wa(313, "level13visited", "level13visited", -5, 24836, 24804), // CODE 17 write arm 172 (savefile.ini)
    wa(314, "level13avisited", "level13avisited", -5, 24880, 24848), // CODE 17 write arm 173 (savefile.ini)
    wa(315, "level14visited", "level14visited", -5, 24924, 24892), // CODE 17 write arm 174 (savefile.ini)
    wa(316, "level14avisited", "level14avisited", -5, 24968, 24936), // CODE 17 write arm 175 (savefile.ini)
    wa(317, "level15visited", "level15visited", -5, 25012, 24980), // CODE 17 write arm 176 (savefile.ini)
    wa(318, "level15avisited", "level15avisited", -5, 25056, 25024), // CODE 17 write arm 177 (savefile.ini)
    wa(319, "level16visited", "level16visited", -5, 25100, 25068), // CODE 17 write arm 178 (savefile.ini)
    wa(320, "level16avisited", "level16avisited", -5, 25144, 25112), // CODE 17 write arm 179 (savefile.ini)
    wa(321, "level17visited", "level17visited", -5, 25188, 25156), // CODE 17 write arm 180 (savefile.ini)
    wa(322, "level17avisited", "level17avisited", -5, 25232, 25200), // CODE 17 write arm 181 (savefile.ini)
    wa(323, "boss2visited", "boss2visited", -5, 25276, 25244), // CODE 17 write arm 182 (savefile.ini)
    wa(324, "room31visited", "room31visited", -5, 25320, 25288), // CODE 17 write arm 183 (savefile.ini)
    wa(325, "room32visited", "room32visited", -5, 25364, 25332), // CODE 17 write arm 184 (savefile.ini)
    wa(326, "room33visited", "room33visited", -5, 25408, 25376), // CODE 17 write arm 185 (savefile.ini)
    wa(327, "room34visited", "room34visited", -5, 25452, 25420), // CODE 17 write arm 186 (savefile.ini)
    wa(328, "room35visited", "room35visited", -5, 25496, 25464), // CODE 17 write arm 187 (savefile.ini)
    wa(329, "room36visited", "room36visited", -5, 25540, 25508), // CODE 17 write arm 188 (savefile.ini)
    wa(330, "room37visited", "room37visited", -5, 25584, 25552), // CODE 17 write arm 189 (savefile.ini)
    wa(331, "room38visited", "room38visited", -5, 25628, 25596), // CODE 17 write arm 190 (savefile.ini)
    wa(332, "room39visited", "room39visited", -5, 25672, 25640), // CODE 17 write arm 191 (savefile.ini)
    wa(333, "room40visited", "room40visited", -5, 25716, 25684), // CODE 17 write arm 192 (savefile.ini)
    wa(334, "room41visited", "room41visited", -5, 25760, 25728), // CODE 17 write arm 193 (savefile.ini)
    wa(335, "room42visited", "room42visited", -5, 25804, 25772), // CODE 17 write arm 194 (savefile.ini)
    wa(336, "room43visited", "room43visited", -5, 25848, 25816), // CODE 17 write arm 195 (savefile.ini)
    wa(337, "room44visited", "room44visited", -5, 25892, 25860), // CODE 17 write arm 196 (savefile.ini)
    wa(338, "room45visited", "room45visited", -5, 25936, 25904), // CODE 17 write arm 197 (savefile.ini)
    wa(339, "room46visited", "room46visited", -5, 25980, 25948), // CODE 17 write arm 198 (savefile.ini)
    wa(340, "room47visited", "room47visited", -5, 26024, 25992), // CODE 17 write arm 199 (savefile.ini)
    wa(341, "room48visited", "room48visited", -5, 26068, 26036), // CODE 17 write arm 200 (savefile.ini)
    wa(342, "room49visited", "room49visited", -5, 26112, 26080), // CODE 17 write arm 201 (savefile.ini)
    wa(343, "room50visited", "room50visited", -5, 26156, 26124), // CODE 17 write arm 202 (savefile.ini)
    wa(344, "boss3visited", "boss3visited", -5, 26200, 26168), // CODE 17 write arm 203 (savefile.ini)
    wa(345, "room51visited", "room51visited", -5, 26244, 26212), // CODE 17 write arm 204 (savefile.ini)
    wa(346, "room52visited", "room52visited", -5, 26288, 26256), // CODE 17 write arm 205 (savefile.ini)
    wa(347, "room53visited", "room53visited", -5, 26332, 26300), // CODE 17 write arm 206 (savefile.ini)
    wa(348, "room54visited", "room54visited", -5, 26376, 26344), // CODE 17 write arm 207 (savefile.ini)
    wa(349, "room55visited", "room55visited", -5, 26420, 26388), // CODE 17 write arm 208 (savefile.ini)
    wa(350, "room56visited", "room56visited", -5, 26464, 26432), // CODE 17 write arm 209 (savefile.ini)
    wa(351, "room57visited", "room57visited", -5, 26508, 26476), // CODE 17 write arm 210 (savefile.ini)
    wa(352, "room58visited", "room58visited", -5, 26552, 26520), // CODE 17 write arm 211 (savefile.ini)
    wa(353, "room59visited", "room59visited", -5, 26596, 26564), // CODE 17 write arm 212 (savefile.ini)
    wa(354, "room60visited", "room60visited", -5, 26640, 26608), // CODE 17 write arm 213 (savefile.ini)
    wa(355, "room61visited", "room61visited", -5, 26684, 26652), // CODE 17 write arm 214 (savefile.ini)
    wa(356, "room62visited", "room62visited", -5, 26728, 26696), // CODE 17 write arm 215 (savefile.ini)
    wa(357, "room63visited", "room63visited", -5, 26772, 26740), // CODE 17 write arm 216 (savefile.ini)
    wa(358, "room64visited", "room64visited", -5, 26816, 26784), // CODE 17 write arm 217 (savefile.ini)
    wa(359, "room65visited", "room65visited", -5, 26860, 26828), // CODE 17 write arm 218 (savefile.ini)
    wa(360, "boss4visited", "boss4visited", -5, 26904, 26872), // CODE 17 write arm 219 (savefile.ini)
    wa(361, "room66visited", "room66visited", -5, 26948, 26916), // CODE 17 write arm 220 (savefile.ini)
    wa(362, "room67visited", "room67visited", -5, 26992, 26960), // CODE 17 write arm 221 (savefile.ini)
    wa(363, "room68visited", "room68visited", -5, 27036, 27004), // CODE 17 write arm 222 (savefile.ini)
    wa(364, "room69visited", "room69visited", -5, 27080, 27048), // CODE 17 write arm 223 (savefile.ini)
    wa(365, "room70visited", "room70visited", -5, 27124, 27092), // CODE 17 write arm 224 (savefile.ini)
    wa(366, "room71visited", "room71visited", -5, 27168, 27136), // CODE 17 write arm 225 (savefile.ini)
    wa(367, "room72visited", "room72visited", -5, 27212, 27180), // CODE 17 write arm 226 (savefile.ini)
    wa(368, "room73visited", "room73visited", -5, 27256, 27224), // CODE 17 write arm 227 (savefile.ini)
    wa(369, "room74visited", "room74visited", -5, 27300, 27268), // CODE 17 write arm 228 (savefile.ini)
    wa(370, "room75visited", "room75visited", -5, 27344, 27312), // CODE 17 write arm 229 (savefile.ini)
    wa(371, "room76visited", "room76visited", -5, 27388, 27356), // CODE 17 write arm 230 (savefile.ini)
    wa(372, "room77visited", "room77visited", -5, 27432, 27400), // CODE 17 write arm 231 (savefile.ini)
    wa(373, "room78visited", "room78visited", -5, 27476, 27444), // CODE 17 write arm 232 (savefile.ini)
    wa(374, "room79visited", "room79visited", -5, 27520, 27488), // CODE 17 write arm 233 (savefile.ini)
    wa(375, "room80visited", "room80visited", -5, 27564, 27532), // CODE 17 write arm 234 (savefile.ini)
    wa(376, "room81visited", "room81visited", -5, 27608, 27576), // CODE 17 write arm 235 (savefile.ini)
    wa(377, "room82visited", "room82visited", -5, 27652, 27620), // CODE 17 write arm 236 (savefile.ini)
    wa(378, "boss5visited", "boss5visited", -5, 27696, 27664), // CODE 17 write arm 237 (savefile.ini)
    wa(379, "room83visited", "room83visited", -5, 27740, 27708), // CODE 17 write arm 238 (savefile.ini)
    wa(380, "room84visited", "room84visited", -5, 27784, 27752), // CODE 17 write arm 239 (savefile.ini)
    wa(381, "room85visited", "room85visited", -5, 27828, 27796), // CODE 17 write arm 240 (savefile.ini)
    wa(382, "room86visited", "room86visited", -5, 27872, 27840), // CODE 17 write arm 241 (savefile.ini)
    wa(383, "room87visited", "room87visited", -5, 27916, 27884), // CODE 17 write arm 242 (savefile.ini)
    wa(384, "room88visited", "room88visited", -5, 27960, 27928), // CODE 17 write arm 243 (savefile.ini)
    wa(385, "room89visited", "room89visited", -5, 28004, 27972), // CODE 17 write arm 244 (savefile.ini)
    wa(386, "room90visited", "room90visited", -5, 28048, 28016), // CODE 17 write arm 245 (savefile.ini)
    wa(387, "room91visited", "room91visited", -5, 28092, 28060), // CODE 17 write arm 246 (savefile.ini)
    wa(388, "room92visited", "room92visited", -5, 28136, 28104), // CODE 17 write arm 247 (savefile.ini)
    wa(389, "room93visited", "room93visited", -5, 28180, 28148), // CODE 17 write arm 248 (savefile.ini)
    wa(390, "room94visited", "room94visited", -5, 28224, 28192), // CODE 17 write arm 249 (savefile.ini)
    wa(391, "room95visited", "room95visited", -5, 28268, 28236), // CODE 17 write arm 250 (savefile.ini)
    wa(392, "room96visited", "room96visited", -5, 28312, 28280), // CODE 17 write arm 251 (savefile.ini)
    wa(393, "room97visited", "room97visited", -5, 28356, 28324), // CODE 17 write arm 252 (savefile.ini)
    wa(394, "room98visited", "room98visited", -5, 28400, 28368), // CODE 17 write arm 253 (savefile.ini)
    wa(395, "room99visited", "room99visited", -5, 28444, 28412), // CODE 17 write arm 254 (savefile.ini)
    wa(396, "room100visited", "room100visited", -5, 28488, 28456), // CODE 17 write arm 255 (savefile.ini)
    wa(397, "room101visited", "room101visited", -5, 28532, 28500), // CODE 17 write arm 256 (savefile.ini)
    wa(398, "room102visited", "room102visited", -5, 28576, 28544), // CODE 17 write arm 257 (savefile.ini)
    wa(399, "room103visited", "room103visited", -5, 28620, 28588), // CODE 17 write arm 258 (savefile.ini)
    wa(400, "boss6visited", "boss6visited", -5, 28664, 28632), // CODE 17 write arm 259 (savefile.ini)
    wa(23, "soundmute", "soundmute", -5, 28708, 28676), // CODE 17 write arm 260 (savefile.ini)
    wa(22, "musicmute", "musicmute", -5, 28752, 28720), // CODE 17 write arm 261 (savefile.ini)
    wa(401, "beartouched", "beartouched", -5, 28796, 28764), // CODE 17 write arm 262 (savefile.ini)
    wa(402, "knifetouched", "knifetouched", -5, 28840, 28808), // CODE 17 write arm 263 (savefile.ini)
    wa(403, "spidertouched", "spidertouched", -5, 28884, 28852), // CODE 17 write arm 264 (savefile.ini)
    wa(404, "battouched", "battouched", -5, 28928, 28896), // CODE 17 write arm 265 (savefile.ini)
    wa(405, "wolftouched", "wolftouched", -5, 28972, 28940), // CODE 17 write arm 266 (savefile.ini)
    wa(406, "pistolbandittouched", "pistolbandittouched", -5, 29016, 28984), // CODE 17 write arm 267 (savefile.ini)
    wa(407, "boss1touched", "boss1touched", -5, 29060, 29028), // CODE 17 write arm 268 (savefile.ini)
    wa(408, "turrettouched", "turrettouched", -5, 29104, 29072), // CODE 17 write arm 269 (savefile.ini)
    wa(409, "slimetouched", "slimetouched", -5, 29148, 29116), // CODE 17 write arm 270 (savefile.ini)
    wa(410, "boss2touched", "boss2touched", -5, 29192, 29160), // CODE 17 write arm 271 (savefile.ini)
    wa(411, "zombietouched", "zombietouched", -5, 29236, 29204), // CODE 17 write arm 272 (savefile.ini)
    wa(412, "redslimetouched", "redslimetouched", -5, 29280, 29248), // CODE 17 write arm 273 (savefile.ini)
    wa(413, "skeletontouched", "skeletontouched", -5, 29324, 29292), // CODE 17 write arm 274 (savefile.ini)
    wa(414, "hulkingbandittouched", "hulkingbandittouched", -5, 29368, 29336), // CODE 17 write arm 275 (savefile.ini)
    wa(415, "beetouched", "beetouched", -5, 29412, 29380), // CODE 17 write arm 276 (savefile.ini)
    wa(416, "boss3touched", "boss3touched", -5, 29456, 29424), // CODE 17 write arm 277 (savefile.ini)
    wa(417, "firehulktouched", "firehulktouched", -5, 29500, 29468), // CODE 17 write arm 278 (savefile.ini)
    wa(418, "boss4touched", "boss4touched", -5, 29544, 29512), // CODE 17 write arm 279 (savefile.ini)
    wa(419, "boss5touched", "boss5touched", -5, 29588, 29556), // CODE 17 write arm 280 (savefile.ini)
    wa(420, "boss6touched", "boss6touched", -5, 29632, 29600), // CODE 17 write arm 281 (savefile.ini)
    wa(423, "levelchallenge1visited", "levelchallenge1visited", -5, 30028, 29996), // CODE 17 write arm 282 (savefile2.ini)
    wa(424, "levelchallenge2visited", "levelchallenge2visited", -5, 30072, 30040), // CODE 17 write arm 283 (savefile2.ini)
    wa(425, "levelchallenge3visited", "levelchallenge3visited", -5, 30116, 30084), // CODE 17 write arm 284 (savefile2.ini)
    wa(426, "levelchallenge4visited", "levelchallenge4visited", -5, 30160, 30128), // CODE 17 write arm 285 (savefile2.ini)
    wa(427, "levelchallenge5visited", "levelchallenge5visited", -5, 30204, 30172), // CODE 17 write arm 286 (savefile2.ini)
    wa(482, "talkedtolloyd16", "talkedtolloyd16", -5, 30248, 30216), // CODE 17 write arm 287 (savefile2.ini)
    wa(429, "twentyfivebears", "twentyfivebears", -5, 32192, 32160), // CODE 17 write arm 288 (savefile3.ini)
    wa(430, "onehundredbears", "onehundredbears", -5, 32236, 32204), // CODE 17 write arm 289 (savefile3.ini)
    wa(431, "twentyfivewolf", "twentyfivewolf", -5, 32280, 32248), // CODE 17 write arm 290 (savefile3.ini)
    wa(432, "onehundredwolf", "onehundredwolf", -5, 32324, 32292), // CODE 17 write arm 291 (savefile3.ini)
    wa(433, "twentyfiveknifebandit", "twentyfiveknifebandit", -5, 32368, 32336), // CODE 17 write arm 292 (savefile3.ini)
    wa(434, "onehundredknifebandit", "onehundredknifebandit", -5, 32412, 32380), // CODE 17 write arm 293 (savefile3.ini)
    wa(435, "twentyfivepistolthug", "twentyfivepistolthug", -5, 32456, 32424), // CODE 17 write arm 294 (savefile3.ini)
    wa(436, "onehundredpistolthug", "onehundredpistolthug", -5, 32500, 32468), // CODE 17 write arm 295 (savefile3.ini)
    wa(437, "twentyfivespiders", "twentyfivespiders", -5, 32544, 32512), // CODE 17 write arm 296 (savefile3.ini)
    wa(438, "onehundredspiders", "onehundredspiders", -5, 32588, 32556), // CODE 17 write arm 297 (savefile3.ini)
    wa(439, "twentyfiveslimes", "twentyfiveslimes", -5, 32632, 32600), // CODE 17 write arm 298 (savefile3.ini)
    wa(440, "onehundredslimes", "onehundredslimes", -5, 32676, 32644), // CODE 17 write arm 299 (savefile3.ini)
    wa(441, "twentyfivefireslimes", "twentyfivefireslimes", -5, 32720, 32688), // CODE 17 write arm 300 (savefile3.ini)
    wa(442, "onehundredfireslimes", "onehundredfireslimes", -5, 32764, 32732), // CODE 17 write arm 301 (savefile3.ini)
    wa(443, "twentyfivehulking", "twentyfivehulking", -5, 32808, 32776), // CODE 17 write arm 302 (savefile3.ini)
    wa(444, "onehundredhulking", "onehundredhulking", -5, 32852, 32820), // CODE 17 write arm 303 (savefile3.ini)
    wa(445, "twentyfiveghost", "twentyfiveghost", -5, 32896, 32864), // CODE 17 write arm 304 (savefile3.ini)
    wa(446, "onehundredghost", "onehundredghost", -5, 32940, 32908), // CODE 17 write arm 305 (savefile3.ini)
    wa(447, "twentyfiveskeleton", "twentyfiveskeleton", -5, 32984, 32952), // CODE 17 write arm 306 (savefile3.ini)
    wa(448, "onehundredskeleton", "onehundredskeleton", -5, 33028, 32996), // CODE 17 write arm 307 (savefile3.ini)
    wa(449, "twentyfivezombie", "twentyfivezombie", -5, 33072, 33040), // CODE 17 write arm 308 (savefile3.ini)
    wa(450, "onehundredzombie", "onehundredzombie", -5, 33116, 33084), // CODE 17 write arm 309 (savefile3.ini)
    wa(451, "twentyfivebalrog", "twentyfivebalrog", -5, 33160, 33128), // CODE 17 write arm 310 (savefile3.ini)
    wa(452, "onehundredbalrog", "onehundredbalrog", -5, 33204, 33172), // CODE 17 write arm 311 (savefile3.ini)
    wa(453, "twentyfivebat", "twentyfivebat", -5, 33248, 33216), // CODE 17 write arm 312 (savefile3.ini)
    wa(454, "onehundredbat", "onehundredbat", -5, 33292, 33260), // CODE 17 write arm 313 (savefile3.ini)
    wa(455, "twentyfivetrap", "twentyfivetrap", -5, 33336, 33304), // CODE 17 write arm 314 (savefile3.ini)
    wa(456, "onehundredtrap", "onehundredtrap", -5, 33380, 33348), // CODE 17 write arm 315 (savefile3.ini)
    wa(457, "twentyfiveenemies", "twentyfiveenemies", -5, 33424, 33392), // CODE 17 write arm 316 (savefile3.ini)
    wa(458, "onehundredenemies", "onehundredenemies", -5, 33468, 33436), // CODE 17 write arm 317 (savefile3.ini)
    wa(459, "fivehundredenemies", "fivehundredenemies", -5, 33512, 33480), // CODE 17 write arm 318 (savefile3.ini)
    wa(460, "onethousandenemies", "onethousandenemies", -5, 33556, 33524), // CODE 17 write arm 319 (savefile3.ini)
    wa(461, "achievementboughtjump", "achievementboughtjump", -5, 33600, 33568), // CODE 17 write arm 320 (savefile3.ini)
    wa(462, "achievmentboughtupgrades", "achievmentboughtupgrades", -5, 33644, 33612), // CODE 17 write arm 321 (savefile3.ini)
    wa(463, "hitmaxcallylevel", "hitmaxcallylevel", -5, 33688, 33656), // CODE 17 write arm 322 (savefile3.ini)
    wa(464, "hitmoney", "hitmoney", -5, 33732, 33700), // CODE 17 write arm 323 (savefile3.ini)
];

#[derive(Clone, Copy, Debug)]
struct StoreRow {
    global: &'static str,
    sel: i32,
    value: f64,
    /// code_offset of the `store` instruction.
    off: usize,
}

/// The 288 fresh-start stores of the savefile.ini else-branch (code_offset 13756..17224 / 30308..30380 / 33792..34224).
#[rustfmt::skip]
const MAIN_DEFAULTS: [StoreRow; 288] = [
    ds("talkedtolloyd1", -5, 0.0, 13760), // CODE 17 default store 0
    ds("talkedtolloyd2", -5, 0.0, 13772), // CODE 17 default store 1
    ds("talkedtolloyd3", -5, 0.0, 13784), // CODE 17 default store 2
    ds("talkedtolloyd4", -5, 0.0, 13796), // CODE 17 default store 3
    ds("talkedtolloyd5", -5, 0.0, 13808), // CODE 17 default store 4
    ds("talkedtolloyd6", -5, 0.0, 13820), // CODE 17 default store 5
    ds("talkedtolloyd7", -5, 0.0, 13832), // CODE 17 default store 6
    ds("talkedtolloyd8", -5, 0.0, 13844), // CODE 17 default store 7
    ds("talkedtolloyd9", -5, 0.0, 13856), // CODE 17 default store 8
    ds("talkedtolloyd10", -5, 0.0, 13868), // CODE 17 default store 9
    ds("talkedtolloyd11", -5, 0.0, 13880), // CODE 17 default store 10
    ds("talkedtolloyd12", -5, 0.0, 13892), // CODE 17 default store 11
    ds("talkedtolloyd13", -5, 0.0, 13904), // CODE 17 default store 12
    ds("talkedtolloyd14", -5, 0.0, 13916), // CODE 17 default store 13
    ds("talkedtolloyd15", -5, 0.0, 13928), // CODE 17 default store 14
    ds("coinmultiply", -5, 1.0, 13940), // CODE 17 default store 15
    ds("timeplayed", -5, 0.0, 13952), // CODE 17 default store 16
    ds("gemdropenabled", -5, 1.0, 13964), // CODE 17 default store 17
    ds("poisonenabled", -5, 0.0, 13976), // CODE 17 default store 18
    ds("weaponswapped", -5, 0.0, 13988), // CODE 17 default store 19
    ds("haskey", -5, 1.0, 14000), // CODE 17 default store 20
    ds("level", -5, 1.0, 14012), // CODE 17 default store 21
    ds("maxhp", -5, 4.0, 14024), // CODE 17 default store 22
    ds("xptolevelup", -5, 30.0, 14036), // CODE 17 default store 23
    ds("health1", -5, 4.0, 14048), // CODE 17 default store 24
    ds("score", -1, 100.0, 14060), // CODE 17 default store 25
    ds("boss1dead", -5, 0.0, 14072), // CODE 17 default store 26
    ds("boss2dead", -5, 0.0, 14084), // CODE 17 default store 27
    ds("boss3dead", -5, 0.0, 14096), // CODE 17 default store 28
    ds("boss4dead", -5, 0.0, 14108), // CODE 17 default store 29
    ds("boss5dead", -5, 0.0, 14120), // CODE 17 default store 30
    ds("boss6dead", -5, 0.0, 14132), // CODE 17 default store 31
    ds("strengthupgradebought", -5, 0.0, 14144), // CODE 17 default store 32
    ds("strengthupgrade2bought", -5, 0.0, 14156), // CODE 17 default store 33
    ds("energywavebought", -5, 0.0, 14168), // CODE 17 default store 34
    ds("healthregenbought", -5, 0.0, 14180), // CODE 17 default store 35
    ds("swordupgradebought", -5, 0.0, 14192), // CODE 17 default store 36
    ds("swordupgrade2bought", -5, 0.0, 14204), // CODE 17 default store 37
    ds("swordupgrade3bought", -5, 0.0, 14216), // CODE 17 default store 38
    ds("pistolbought", -5, 1.0, 14228), // CODE 17 default store 39
    ds("spikegunbought", -5, 0.0, 14240), // CODE 17 default store 40
    ds("boomerangbought", -5, 0.0, 14252), // CODE 17 default store 41
    ds("shotgunbought", -5, 0.0, 14264), // CODE 17 default store 42
    ds("powerupgradebought", -5, 0.0, 14276), // CODE 17 default store 43
    ds("powerupgrade2bought", -5, 0.0, 14288), // CODE 17 default store 44
    ds("powerupgrade3bought", -5, 0.0, 14300), // CODE 17 default store 45
    ds("bladegunbought", -5, 0.0, 14312), // CODE 17 default store 46
    ds("flamethrowerbought", -5, 0.0, 14324), // CODE 17 default store 47
    ds("bowbought", -5, 0.0, 14336), // CODE 17 default store 48
    ds("assaultriflebought", -5, 0.0, 14348), // CODE 17 default store 49
    ds("rocketbought", -5, 0.0, 14360), // CODE 17 default store 50
    ds("laserbought", -5, 0.0, 14372), // CODE 17 default store 51
    ds("icegunbought", -5, 0.0, 14384), // CODE 17 default store 52
    ds("bombgunbought", -5, 0.0, 14396), // CODE 17 default store 53
    ds("bombgunxp", -5, 0.0, 14408), // CODE 17 default store 54
    ds("bombgunxptolevelup", -5, 160.0, 14420), // CODE 17 default store 55
    ds("bombgunlevel", -5, 1.0, 14432), // CODE 17 default store 56
    ds("sword", -5, 0.0, 14444), // CODE 17 default store 57
    ds("triplejumpbought", -5, 0.0, 14456), // CODE 17 default store 58
    ds("tjumpactive", -5, 0.0, 14468), // CODE 17 default store 59
    ds("coinmultiplier2bought", -5, 0.0, 14480), // CODE 17 default store 60
    ds("coinmultiplier5bought", -5, 0.0, 14492), // CODE 17 default store 61
    ds("maxhpupgradebought", -5, 0.0, 14504), // CODE 17 default store 62
    ds("maxhpupgrade2bought", -5, 0.0, 14516), // CODE 17 default store 63
    ds("experience", -5, 1.0, 14528), // CODE 17 default store 64
    ds("drawchange", -5, 0.0, 14540), // CODE 17 default store 65
    ds("drawlevelup", -5, 0.0, 14552), // CODE 17 default store 66
    ds("drawweaponlevelup", -5, 0.0, 14564), // CODE 17 default store 67
    ds("drawweaponchange", -5, 0.0, 14576), // CODE 17 default store 68
    ds("drawchangepistol4", -5, 1.0, 14588), // CODE 17 default store 69
    ds("drawchangeshotgun4", -5, 1.0, 14600), // CODE 17 default store 70
    ds("drawchangeassaultrifle4", -5, 1.0, 14612), // CODE 17 default store 71
    ds("drawchangerocket4", -5, 1.0, 14624), // CODE 17 default store 72
    ds("drawchangelaser4", -5, 1.0, 14636), // CODE 17 default store 73
    ds("drawchangeicegun4", -5, 1.0, 14648), // CODE 17 default store 74
    ds("drawchangebow4", -5, 1.0, 14660), // CODE 17 default store 75
    ds("drawchangebladegun4", -5, 1.0, 14672), // CODE 17 default store 76
    ds("drawchangeflamethrower4", -5, 1.0, 14684), // CODE 17 default store 77
    ds("drawchangeboomerang4", -5, 1.0, 14696), // CODE 17 default store 78
    ds("drawchangespikegun4", -5, 1.0, 14708), // CODE 17 default store 79
    ds("drawchangebombgun4", -5, 1.0, 14720), // CODE 17 default store 80
    ds("drawchangepistol7", -5, 1.0, 14732), // CODE 17 default store 81
    ds("drawchangeshotgun7", -5, 1.0, 14744), // CODE 17 default store 82
    ds("drawchangeassaultrifle7", -5, 1.0, 14756), // CODE 17 default store 83
    ds("drawchangerocket7", -5, 1.0, 14768), // CODE 17 default store 84
    ds("drawchangelaser7", -5, 1.0, 14780), // CODE 17 default store 85
    ds("drawchangeicegun7", -5, 1.0, 14792), // CODE 17 default store 86
    ds("drawchangebow7", -5, 1.0, 14804), // CODE 17 default store 87
    ds("drawchangebladegun7", -5, 1.0, 14816), // CODE 17 default store 88
    ds("drawchangeflamethrower7", -5, 1.0, 14828), // CODE 17 default store 89
    ds("drawchangeboomerang7", -5, 1.0, 14840), // CODE 17 default store 90
    ds("drawchangespikegun7", -5, 1.0, 14852), // CODE 17 default store 91
    ds("drawchangebombgun7", -5, 1.0, 14864), // CODE 17 default store 92
    ds("drawchangepistol10", -5, 1.0, 14876), // CODE 17 default store 93
    ds("drawchangeshotgun10", -5, 1.0, 14888), // CODE 17 default store 94
    ds("drawchangeassaultrifle10", -5, 1.0, 14900), // CODE 17 default store 95
    ds("drawchangerocket10", -5, 1.0, 14912), // CODE 17 default store 96
    ds("drawchangelaser10", -5, 1.0, 14924), // CODE 17 default store 97
    ds("drawchangeicegun10", -5, 1.0, 14936), // CODE 17 default store 98
    ds("drawchangebow10", -5, 1.0, 14948), // CODE 17 default store 99
    ds("drawchangebladegun10", -5, 1.0, 14960), // CODE 17 default store 100
    ds("drawchangeflamethrower10", -5, 1.0, 14972), // CODE 17 default store 101
    ds("drawchangeboomerang10", -5, 1.0, 14984), // CODE 17 default store 102
    ds("drawchangespikegun10", -5, 1.0, 14996), // CODE 17 default store 103
    ds("drawchangebombgun10", -5, 1.0, 15008), // CODE 17 default store 104
    ds("bearskilled", -5, 0.0, 15020), // CODE 17 default store 105
    ds("knifebanditskilled", -5, 0.0, 15032), // CODE 17 default store 106
    ds("pistolthugskilled", -5, 0.0, 15044), // CODE 17 default store 107
    ds("wolfkilled", -5, 0.0, 15056), // CODE 17 default store 108
    ds("chomperbotkilled", -5, 0.0, 15068), // CODE 17 default store 109
    ds("greenslimeskilled", -5, 0.0, 15080), // CODE 17 default store 110
    ds("fireslimeskilled", -5, 0.0, 15092), // CODE 17 default store 111
    ds("hulkingbanditskilled", -5, 0.0, 15104), // CODE 17 default store 112
    ds("ghostskilled", -5, 0.0, 15116), // CODE 17 default store 113
    ds("skeletonskilled", -5, 0.0, 15128), // CODE 17 default store 114
    ds("zombieskilled", -5, 0.0, 15140), // CODE 17 default store 115
    ds("firehulkskilled", -5, 0.0, 15152), // CODE 17 default store 116
    ds("batskilled", -5, 0.0, 15164), // CODE 17 default store 117
    ds("trapskilled", -5, 0.0, 15176), // CODE 17 default store 118
    ds("enemieskilled", -5, 0.0, 15188), // CODE 17 default store 119
    ds("boughtallguns", -5, 0.0, 15200), // CODE 17 default store 120
    ds("triplejumpachievement", -5, 0.0, 15212), // CODE 17 default store 121
    ds("boughtallupgrades", -5, 0.0, 15224), // CODE 17 default store 122
    ds("boughteverything", -5, 0.0, 15236), // CODE 17 default store 123
    ds("achievemaxhp", -5, 0.0, 15248), // CODE 17 default store 124
    ds("getmoney", -5, 0.0, 15260), // CODE 17 default store 125
    ds("hitmaxlevel", -5, 0.0, 15272), // CODE 17 default store 126
    ds("bladegunxp", -5, 0.0, 15284), // CODE 17 default store 127
    ds("bladegunxptolevelup", -5, 200.0, 15296), // CODE 17 default store 128
    ds("flamethrowerxp", -5, 0.0, 15308), // CODE 17 default store 129
    ds("flamethrowerxptolevelup", -5, 180.0, 15320), // CODE 17 default store 130
    ds("bowxp", -5, 0.0, 15332), // CODE 17 default store 131
    ds("bowxptolevelup", -5, 62.0, 15344), // CODE 17 default store 132
    ds("pistolxp", -5, 0.0, 15356), // CODE 17 default store 133
    ds("pistolxptolevelup", -5, 46.0, 15368), // CODE 17 default store 134
    ds("shotgunxp", -5, 0.0, 15380), // CODE 17 default store 135
    ds("shotgunxptolevelup", -5, 115.0, 15392), // CODE 17 default store 136
    ds("assaultriflexp", -5, 0.0, 15404), // CODE 17 default store 137
    ds("assaultriflexptolevelup", -5, 120.0, 15416), // CODE 17 default store 138
    ds("rocketxp", -5, 0.0, 15428), // CODE 17 default store 139
    ds("rocketxptolevelup", -5, 80.0, 15440), // CODE 17 default store 140
    ds("laserxp", -5, 0.0, 15452), // CODE 17 default store 141
    ds("laserxptolevelup", -5, 80.0, 15464), // CODE 17 default store 142
    ds("icegunxp", -5, 0.0, 15476), // CODE 17 default store 143
    ds("icegunxptolevelup", -5, 60.0, 15488), // CODE 17 default store 144
    ds("pistollevel", -5, 1.0, 15500), // CODE 17 default store 145
    ds("shotgunlevel", -5, 1.0, 15512), // CODE 17 default store 146
    ds("assaultriflelevel", -5, 1.0, 15524), // CODE 17 default store 147
    ds("grenadelevel", -5, 1.0, 15536), // CODE 17 default store 148
    ds("rocketlevel", -5, 1.0, 15548), // CODE 17 default store 149
    ds("laserlevel", -5, 1.0, 15560), // CODE 17 default store 150
    ds("icegunlevel", -5, 1.0, 15572), // CODE 17 default store 151
    ds("bowlevel", -5, 1.0, 15584), // CODE 17 default store 152
    ds("bladegunlevel", -5, 1.0, 15596), // CODE 17 default store 153
    ds("flamethrowerlevel", -5, 1.0, 15608), // CODE 17 default store 154
    ds("boomerangxp", -5, 0.0, 15620), // CODE 17 default store 155
    ds("boomeranglevel", -5, 1.0, 15632), // CODE 17 default store 156
    ds("boomerangxptolevelup", -5, 250.0, 15644), // CODE 17 default store 157
    ds("spikegunxp", -5, 0.0, 15656), // CODE 17 default store 158
    ds("spikegunlevel", -5, 1.0, 15668), // CODE 17 default store 159
    ds("spikegunxptolevelup", -5, 64.0, 15680), // CODE 17 default store 160
    ds("roomtownvisited", -5, 1.0, 15692), // CODE 17 default store 161
    ds("level1visited", -5, 0.0, 15704), // CODE 17 default store 162
    ds("level2visited", -5, 0.0, 15716), // CODE 17 default store 163
    ds("level3visited", -5, 0.0, 15728), // CODE 17 default store 164
    ds("level4visited", -5, 0.0, 15740), // CODE 17 default store 165
    ds("level5visited", -5, 0.0, 15752), // CODE 17 default store 166
    ds("level6visited", -5, 0.0, 15764), // CODE 17 default store 167
    ds("level7visited", -5, 0.0, 15776), // CODE 17 default store 168
    ds("level8visited", -5, 0.0, 15788), // CODE 17 default store 169
    ds("level8avisited", -5, 0.0, 15800), // CODE 17 default store 170
    ds("boss1visited", -5, 0.0, 15812), // CODE 17 default store 171
    ds("level9visited", -5, 0.0, 15824), // CODE 17 default store 172
    ds("level9avisited", -5, 0.0, 15836), // CODE 17 default store 173
    ds("level10visited", -5, 0.0, 15848), // CODE 17 default store 174
    ds("level11visited", -5, 0.0, 15860), // CODE 17 default store 175
    ds("level11avisited", -5, 0.0, 15872), // CODE 17 default store 176
    ds("level12visited", -5, 0.0, 15884), // CODE 17 default store 177
    ds("level13visited", -5, 0.0, 15896), // CODE 17 default store 178
    ds("level13avisited", -5, 0.0, 15908), // CODE 17 default store 179
    ds("level14visited", -5, 0.0, 15920), // CODE 17 default store 180
    ds("level14avisited", -5, 0.0, 15932), // CODE 17 default store 181
    ds("level15visited", -5, 0.0, 15944), // CODE 17 default store 182
    ds("level15avisited", -5, 0.0, 15956), // CODE 17 default store 183
    ds("level16visited", -5, 0.0, 15968), // CODE 17 default store 184
    ds("level16avisited", -5, 0.0, 15980), // CODE 17 default store 185
    ds("level17visited", -5, 0.0, 15992), // CODE 17 default store 186
    ds("level17avisited", -5, 0.0, 16004), // CODE 17 default store 187
    ds("boss2visited", -5, 0.0, 16016), // CODE 17 default store 188
    ds("room31visited", -5, 0.0, 16028), // CODE 17 default store 189
    ds("room32visited", -5, 0.0, 16040), // CODE 17 default store 190
    ds("room33visited", -5, 0.0, 16052), // CODE 17 default store 191
    ds("room34visited", -5, 0.0, 16064), // CODE 17 default store 192
    ds("room35visited", -5, 0.0, 16076), // CODE 17 default store 193
    ds("room36visited", -5, 0.0, 16088), // CODE 17 default store 194
    ds("room37visited", -5, 0.0, 16100), // CODE 17 default store 195
    ds("room38visited", -5, 0.0, 16112), // CODE 17 default store 196
    ds("room39visited", -5, 0.0, 16124), // CODE 17 default store 197
    ds("room40visited", -5, 0.0, 16136), // CODE 17 default store 198
    ds("room41visited", -5, 0.0, 16148), // CODE 17 default store 199
    ds("room42visited", -5, 0.0, 16160), // CODE 17 default store 200
    ds("room43visited", -5, 0.0, 16172), // CODE 17 default store 201
    ds("room44visited", -5, 0.0, 16184), // CODE 17 default store 202
    ds("room45visited", -5, 0.0, 16196), // CODE 17 default store 203
    ds("room46visited", -5, 0.0, 16208), // CODE 17 default store 204
    ds("room47visited", -5, 0.0, 16220), // CODE 17 default store 205
    ds("room48visited", -5, 0.0, 16232), // CODE 17 default store 206
    ds("room49visited", -5, 0.0, 16244), // CODE 17 default store 207
    ds("room50visited", -5, 0.0, 16256), // CODE 17 default store 208
    ds("boss3visited", -5, 0.0, 16268), // CODE 17 default store 209
    ds("room51visited", -5, 0.0, 16280), // CODE 17 default store 210
    ds("room52visited", -5, 0.0, 16292), // CODE 17 default store 211
    ds("room53visited", -5, 0.0, 16304), // CODE 17 default store 212
    ds("room54visited", -5, 0.0, 16316), // CODE 17 default store 213
    ds("room55visited", -5, 0.0, 16328), // CODE 17 default store 214
    ds("room56visited", -5, 0.0, 16340), // CODE 17 default store 215
    ds("room57visited", -5, 0.0, 16352), // CODE 17 default store 216
    ds("room58visited", -5, 0.0, 16364), // CODE 17 default store 217
    ds("room59visited", -5, 0.0, 16376), // CODE 17 default store 218
    ds("room60visited", -5, 0.0, 16388), // CODE 17 default store 219
    ds("room61visited", -5, 0.0, 16400), // CODE 17 default store 220
    ds("room62visited", -5, 0.0, 16412), // CODE 17 default store 221
    ds("room63visited", -5, 0.0, 16424), // CODE 17 default store 222
    ds("room64visited", -5, 0.0, 16436), // CODE 17 default store 223
    ds("room65visited", -5, 0.0, 16448), // CODE 17 default store 224
    ds("boss4visited", -5, 0.0, 16460), // CODE 17 default store 225
    ds("room66visited", -5, 0.0, 16472), // CODE 17 default store 226
    ds("room67visited", -5, 0.0, 16484), // CODE 17 default store 227
    ds("room68visited", -5, 0.0, 16496), // CODE 17 default store 228
    ds("room69visited", -5, 0.0, 16508), // CODE 17 default store 229
    ds("room70visited", -5, 0.0, 16520), // CODE 17 default store 230
    ds("room71visited", -5, 0.0, 16532), // CODE 17 default store 231
    ds("room72visited", -5, 0.0, 16544), // CODE 17 default store 232
    ds("room73visited", -5, 0.0, 16556), // CODE 17 default store 233
    ds("room74visited", -5, 0.0, 16568), // CODE 17 default store 234
    ds("room75visited", -5, 0.0, 16580), // CODE 17 default store 235
    ds("room76visited", -5, 0.0, 16592), // CODE 17 default store 236
    ds("room77visited", -5, 0.0, 16604), // CODE 17 default store 237
    ds("room78visited", -5, 0.0, 16616), // CODE 17 default store 238
    ds("room79visited", -5, 0.0, 16628), // CODE 17 default store 239
    ds("room80visited", -5, 0.0, 16640), // CODE 17 default store 240
    ds("room81visited", -5, 0.0, 16652), // CODE 17 default store 241
    ds("room82visited", -5, 0.0, 16664), // CODE 17 default store 242
    ds("boss5visited", -5, 0.0, 16676), // CODE 17 default store 243
    ds("room83visited", -5, 0.0, 16688), // CODE 17 default store 244
    ds("room84visited", -5, 0.0, 16700), // CODE 17 default store 245
    ds("room85visited", -5, 0.0, 16712), // CODE 17 default store 246
    ds("room86visited", -5, 0.0, 16724), // CODE 17 default store 247
    ds("room87visited", -5, 0.0, 16736), // CODE 17 default store 248
    ds("room88visited", -5, 0.0, 16748), // CODE 17 default store 249
    ds("room89visited", -5, 0.0, 16760), // CODE 17 default store 250
    ds("room90visited", -5, 0.0, 16772), // CODE 17 default store 251
    ds("room91visited", -5, 0.0, 16784), // CODE 17 default store 252
    ds("room92visited", -5, 0.0, 16796), // CODE 17 default store 253
    ds("room93visited", -5, 0.0, 16808), // CODE 17 default store 254
    ds("room94visited", -5, 0.0, 16820), // CODE 17 default store 255
    ds("room95visited", -5, 0.0, 16832), // CODE 17 default store 256
    ds("room96visited", -5, 0.0, 16844), // CODE 17 default store 257
    ds("room97visited", -5, 0.0, 16856), // CODE 17 default store 258
    ds("room98visited", -5, 0.0, 16868), // CODE 17 default store 259
    ds("room99visited", -5, 0.0, 16880), // CODE 17 default store 260
    ds("room100visited", -5, 0.0, 16892), // CODE 17 default store 261
    ds("room101visited", -5, 0.0, 16904), // CODE 17 default store 262
    ds("room102visited", -5, 0.0, 16916), // CODE 17 default store 263
    ds("room103visited", -5, 0.0, 16928), // CODE 17 default store 264
    ds("boss6visited", -5, 0.0, 16940), // CODE 17 default store 265
    ds("soundmute", -5, 0.0, 16952), // CODE 17 default store 266
    ds("musicmute", -5, 0.0, 16964), // CODE 17 default store 267
    ds("beartouched", -5, 0.0, 16976), // CODE 17 default store 268
    ds("knifetouched", -5, 0.0, 16988), // CODE 17 default store 269
    ds("spidertouched", -5, 0.0, 17000), // CODE 17 default store 270
    ds("battouched", -5, 0.0, 17012), // CODE 17 default store 271
    ds("wolftouched", -5, 0.0, 17024), // CODE 17 default store 272
    ds("pistolbandittouched", -5, 0.0, 17036), // CODE 17 default store 273
    ds("boss1touched", -5, 0.0, 17048), // CODE 17 default store 274
    ds("turrettouched", -5, 0.0, 17060), // CODE 17 default store 275
    ds("slimetouched", -5, 0.0, 17072), // CODE 17 default store 276
    ds("boss2touched", -5, 0.0, 17084), // CODE 17 default store 277
    ds("zombietouched", -5, 0.0, 17096), // CODE 17 default store 278
    ds("redslimetouched", -5, 0.0, 17108), // CODE 17 default store 279
    ds("skeletontouched", -5, 0.0, 17120), // CODE 17 default store 280
    ds("hulkingbandittouched", -5, 0.0, 17132), // CODE 17 default store 281
    ds("beetouched", -5, 0.0, 17144), // CODE 17 default store 282
    ds("boss3touched", -5, 0.0, 17156), // CODE 17 default store 283
    ds("firehulktouched", -5, 0.0, 17168), // CODE 17 default store 284
    ds("boss4touched", -5, 0.0, 17180), // CODE 17 default store 285
    ds("boss5touched", -5, 0.0, 17192), // CODE 17 default store 286
    ds("boss6touched", -5, 0.0, 17204), // CODE 17 default store 287
];

/// The 6 fresh-start stores of the savefile2.ini else-branch (code_offset 13756..17224 / 30308..30380 / 33792..34224).
#[rustfmt::skip]
const SF2_DEFAULTS: [StoreRow; 6] = [
    ds("levelchallenge1visited", -5, 0.0, 30312), // CODE 17 default store 0
    ds("levelchallenge2visited", -5, 0.0, 30324), // CODE 17 default store 1
    ds("levelchallenge3visited", -5, 0.0, 30336), // CODE 17 default store 2
    ds("levelchallenge4visited", -5, 0.0, 30348), // CODE 17 default store 3
    ds("levelchallenge5visited", -5, 0.0, 30360), // CODE 17 default store 4
    ds("talkedtolloyd16", -5, 0.0, 30372), // CODE 17 default store 5
];

/// The 36 fresh-start stores of the savefile3.ini else-branch (code_offset 13756..17224 / 30308..30380 / 33792..34224).
#[rustfmt::skip]
const SF3_DEFAULTS: [StoreRow; 36] = [
    ds("twentyfivebears", -5, 0.0, 33796), // CODE 17 default store 0
    ds("onehundredbears", -5, 0.0, 33808), // CODE 17 default store 1
    ds("twentyfivewolf", -5, 0.0, 33820), // CODE 17 default store 2
    ds("onehundredwolf", -5, 0.0, 33832), // CODE 17 default store 3
    ds("twentyfiveknifebandit", -5, 0.0, 33844), // CODE 17 default store 4
    ds("onehundredknifebandit", -5, 0.0, 33856), // CODE 17 default store 5
    ds("twentyfivepistolthug", -5, 0.0, 33868), // CODE 17 default store 6
    ds("onehundredpistolthug", -5, 0.0, 33880), // CODE 17 default store 7
    ds("twentyfivespiders", -5, 0.0, 33892), // CODE 17 default store 8
    ds("onehundredspiders", -5, 0.0, 33904), // CODE 17 default store 9
    ds("twentyfiveslimes", -5, 0.0, 33916), // CODE 17 default store 10
    ds("onehundredslimes", -5, 0.0, 33928), // CODE 17 default store 11
    ds("twentyfivefireslimes", -5, 0.0, 33940), // CODE 17 default store 12
    ds("onehundredfireslimes", -5, 0.0, 33952), // CODE 17 default store 13
    ds("twentyfivehulking", -5, 0.0, 33964), // CODE 17 default store 14
    ds("onehundredhulking", -5, 0.0, 33976), // CODE 17 default store 15
    ds("twentyfiveghost", -5, 0.0, 33988), // CODE 17 default store 16
    ds("onehundredghost", -5, 0.0, 34000), // CODE 17 default store 17
    ds("twentyfiveskeleton", -5, 0.0, 34012), // CODE 17 default store 18
    ds("onehundredskeleton", -5, 0.0, 34024), // CODE 17 default store 19
    ds("twentyfivezombie", -5, 0.0, 34036), // CODE 17 default store 20
    ds("onehundredzombie", -5, 0.0, 34048), // CODE 17 default store 21
    ds("twentyfivebalrog", -5, 0.0, 34060), // CODE 17 default store 22
    ds("onehundredbalrog", -5, 0.0, 34072), // CODE 17 default store 23
    ds("twentyfivebat", -5, 0.0, 34084), // CODE 17 default store 24
    ds("onehundredbat", -5, 0.0, 34096), // CODE 17 default store 25
    ds("twentyfivetrap", -5, 0.0, 34108), // CODE 17 default store 26
    ds("onehundredtrap", -5, 0.0, 34120), // CODE 17 default store 27
    ds("twentyfiveenemies", -5, 0.0, 34132), // CODE 17 default store 28
    ds("onehundredenemies", -5, 0.0, 34144), // CODE 17 default store 29
    ds("fivehundredenemies", -5, 0.0, 34156), // CODE 17 default store 30
    ds("onethousandenemies", -5, 0.0, 34168), // CODE 17 default store 31
    ds("achievementboughtjump", -5, 0.0, 34180), // CODE 17 default store 32
    ds("achievmentboughtupgrades", -5, 0.0, 34192), // CODE 17 default store 33
    ds("hitmaxcallylevel", -5, 0.0, 34204), // CODE 17 default store 34
    ds("hitmoney", -5, 0.0, 34216), // CODE 17 default store 35
];

#[derive(Clone, Copy, Debug)]
struct DamageArm {
    level: f64,
    damage: f64,
    cmp_off: usize,
    store_off: usize,
}

#[derive(Clone, Copy, Debug)]
struct DamageTable {
    damage_global: &'static str,
    level_global: &'static str,
    arms: [DamageArm; 10],
    /// The trailing `if (level > clamp_level) level = clamp_set;`.
    clamp_level: f64,
    clamp_set: f64,
    clamp_cmp: usize,
}

/// The twelve weapon `level -> damage` tables of CODE 17 (code_offset
/// 34224..39216): ten `==` arms each plus one `> 10` level clamp.
#[rustfmt::skip]
const DAMAGE_TABLES: [DamageTable; 12] = [
    DamageTable {
        damage_global: "pistoldamage",
        level_global: "pistollevel",
        arms: [
            da(1.0, 1.0, 34236, 34248),
            da(2.0, 1.3, 34268, 34288),
            da(3.0, 1.6, 34308, 34328),
            da(4.0, 2.0, 34348, 34360),
            da(5.0, 2.4, 34380, 34400),
            da(6.0, 2.8, 34420, 34440),
            da(7.0, 3.2, 34460, 34480),
            da(8.0, 3.6, 34500, 34520),
            da(9.0, 4.0, 34540, 34552),
            da(10.0, 5.0, 34572, 34584),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 34604,
    },
    DamageTable {
        damage_global: "shotgundamage",
        level_global: "shotgunlevel",
        arms: [
            da(1.0, 0.5, 34636, 34656),
            da(2.0, 0.6, 34676, 34696),
            da(3.0, 0.7, 34716, 34736),
            da(4.0, 0.8, 34756, 34776),
            da(5.0, 0.9, 34796, 34816),
            da(6.0, 1.0, 34836, 34848),
            da(7.0, 1.1, 34868, 34888),
            da(8.0, 1.2, 34908, 34928),
            da(9.0, 1.3, 34948, 34968),
            da(10.0, 1.5, 34988, 35008),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 35028,
    },
    DamageTable {
        damage_global: "assaultrifledamage",
        level_global: "assaultriflelevel",
        arms: [
            da(1.0, 0.6, 35060, 35080),
            da(2.0, 0.7, 35100, 35120),
            da(3.0, 0.8, 35140, 35160),
            da(4.0, 1.0, 35180, 35192),
            da(5.0, 1.1, 35212, 35232),
            da(6.0, 1.2, 35252, 35272),
            da(7.0, 1.4, 35292, 35312),
            da(8.0, 1.5, 35332, 35352),
            da(9.0, 1.7, 35372, 35392),
            da(10.0, 2.0, 35412, 35424),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 35444,
    },
    DamageTable {
        damage_global: "icegundamage",
        level_global: "icegunlevel",
        arms: [
            da(1.0, 1.0, 35476, 35488),
            da(2.0, 1.2, 35508, 35528),
            da(3.0, 1.4, 35548, 35568),
            da(4.0, 1.7, 35588, 35608),
            da(5.0, 1.9, 35628, 35648),
            da(6.0, 2.1, 35668, 35688),
            da(7.0, 2.4, 35708, 35728),
            da(8.0, 2.6, 35748, 35768),
            da(9.0, 2.8, 35788, 35808),
            da(10.0, 3.0, 35828, 35840),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 35860,
    },
    DamageTable {
        damage_global: "laserdamage",
        level_global: "laserlevel",
        arms: [
            da(1.0, 1.5, 35892, 35912),
            da(2.0, 1.6, 35932, 35952),
            da(3.0, 1.7, 35972, 35992),
            da(4.0, 1.8, 36012, 36032),
            da(5.0, 1.9, 36052, 36072),
            da(6.0, 2.0, 36092, 36104),
            da(7.0, 2.1, 36124, 36144),
            da(8.0, 2.2, 36164, 36184),
            da(9.0, 2.3, 36204, 36224),
            da(10.0, 2.5, 36244, 36264),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 36284,
    },
    DamageTable {
        damage_global: "rocketdamage",
        level_global: "rocketlevel",
        arms: [
            da(1.0, 2.5, 36316, 36336),
            da(2.0, 2.6, 36356, 36376),
            da(3.0, 2.7, 36396, 36416),
            da(4.0, 2.8, 36436, 36456),
            da(5.0, 2.9, 36476, 36496),
            da(6.0, 3.0, 36516, 36528),
            da(7.0, 3.2, 36548, 36568),
            da(8.0, 3.4, 36588, 36608),
            da(9.0, 3.6, 36628, 36648),
            da(10.0, 4.0, 36668, 36680),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 36700,
    },
    DamageTable {
        damage_global: "bowdamage",
        level_global: "bowlevel",
        arms: [
            da(1.0, 2.0, 36732, 36744),
            da(2.0, 2.2, 36764, 36784),
            da(3.0, 2.4, 36804, 36824),
            da(4.0, 2.6, 36844, 36864),
            da(5.0, 2.8, 36884, 36904),
            da(6.0, 3.0, 36924, 36936),
            da(7.0, 3.2, 36956, 36976),
            da(8.0, 3.4, 36996, 37016),
            da(9.0, 3.6, 37036, 37056),
            da(10.0, 4.0, 37076, 37088),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 37108,
    },
    DamageTable {
        damage_global: "flamethrowerdamage",
        level_global: "flamethrowerlevel",
        arms: [
            da(1.0, 0.3, 37140, 37160),
            da(2.0, 0.5, 37180, 37200),
            da(3.0, 0.7, 37220, 37240),
            da(4.0, 0.9, 37260, 37280),
            da(5.0, 1.0, 37300, 37312),
            da(6.0, 1.1, 37332, 37352),
            da(7.0, 1.2, 37372, 37392),
            da(8.0, 1.4, 37412, 37432),
            da(9.0, 1.5, 37452, 37472),
            da(10.0, 2.0, 37492, 37504),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 37524,
    },
    DamageTable {
        damage_global: "bladegundamage",
        level_global: "bladegunlevel",
        arms: [
            da(1.0, 1.0, 37556, 37568),
            da(2.0, 1.2, 37588, 37608),
            da(3.0, 1.3, 37628, 37648),
            da(4.0, 1.5, 37668, 37688),
            da(5.0, 1.6, 37708, 37728),
            da(6.0, 1.7, 37748, 37768),
            da(7.0, 2.0, 37788, 37800),
            da(8.0, 2.1, 37820, 37840),
            da(9.0, 2.2, 37860, 37880),
            da(10.0, 2.5, 37900, 37920),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 37940,
    },
    DamageTable {
        damage_global: "spikegundamage",
        level_global: "spikegunlevel",
        arms: [
            da(1.0, 1.5, 37972, 37992),
            da(2.0, 1.6, 38012, 38032),
            da(3.0, 1.7, 38052, 38072),
            da(4.0, 1.8, 38092, 38112),
            da(5.0, 1.9, 38132, 38152),
            da(6.0, 2.0, 38172, 38184),
            da(7.0, 2.2, 38204, 38224),
            da(8.0, 2.4, 38244, 38264),
            da(9.0, 2.6, 38284, 38304),
            da(10.0, 3.0, 38324, 38336),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 38356,
    },
    DamageTable {
        damage_global: "boomerangdamage",
        level_global: "boomeranglevel",
        arms: [
            da(1.0, 0.1, 38388, 38408),
            da(2.0, 0.15, 38428, 38448),
            da(3.0, 0.2, 38468, 38488),
            da(4.0, 0.3, 38508, 38528),
            da(5.0, 0.35, 38548, 38568),
            da(6.0, 0.4, 38588, 38608),
            da(7.0, 0.5, 38628, 38648),
            da(8.0, 0.6, 38668, 38688),
            da(9.0, 0.7, 38708, 38728),
            da(10.0, 1.0, 38748, 38760),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 38780,
    },
    DamageTable {
        damage_global: "bombgundamage",
        level_global: "bombgunlevel",
        arms: [
            da(1.0, 3.5, 38812, 38832),
            da(2.0, 3.7, 38852, 38872),
            da(3.0, 3.9, 38892, 38912),
            da(4.0, 4.0, 38932, 38944),
            da(5.0, 4.1, 38964, 38984),
            da(6.0, 4.2, 39004, 39024),
            da(7.0, 4.4, 39044, 39064),
            da(8.0, 4.5, 39084, 39104),
            da(9.0, 4.6, 39124, 39144),
            da(10.0, 5.0, 39164, 39176),
        ],
        clamp_level: 10.0,
        clamp_set: 10.0,
        clamp_cmp: 39196,
    },
];

// ---- fixture ---------------------------------------------------------------

fn bundle() -> Bundle {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset = GameDroidAsset::parse(&Path::new(manifest_dir).join("../../assets/game.droid"))
        .expect("parse assets/game.droid");
    let mut b = load_bundle_from_file(&Path::new(manifest_dir).join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
    assert!(
        !asset.string_table.is_empty(),
        "the asset STRG table is what makes string_id -> key text decidable"
    );
    b.string_table = asset.string_table;
    b
}

fn body(b: &Bundle) -> &[Instruction] {
    &b.codes
        .iter()
        .find(|c| c.id == CODE)
        .unwrap_or_else(|| panic!("CODE {CODE} body missing from full_ir.json"))
        .instructions
}

/// A throwaway INI directory per test (tests run in parallel: never share one).
fn ini_dir(tag: &str) -> PathBuf {
    let p = std::env::temp_dir().join(format!("cally_wl53_{tag}_{}", std::process::id()));
    let _ = std::fs::remove_dir_all(&p);
    std::fs::create_dir_all(&p).expect("create ini dir");
    p
}

fn gm_text(v: f64) -> String {
    if v == v.trunc() && v.abs() < 1e15 {
        format!("{}", v as i64)
    } else {
        format!("{v}")
    }
}

fn write_ini(dir: &Path, name: &str, rows: &[(&str, f64)]) {
    let mut text = String::from("[Save]\n");
    for (k, v) in rows {
        text.push_str(&format!("{k}={}\n", gm_text(*v)));
    }
    std::fs::write(dir.join(name), text).unwrap_or_else(|e| panic!("write {name}: {e}"));
}

fn scene(b: &Bundle, dir: &Path) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s.ini_disk_dir = Some(dir.to_path_buf());
    s
}

/// Create the player and fire Other_2 with a clean ledger, so `Scene::executed`
/// holds CODE 17 only (obj_introduction's own Create is filtered out by code).
fn start(b: &Bundle, s: &mut Scene) -> i32 {
    let id = s.create(b, PLAYER, 64.0, 96.0).expect("create obj_player");
    s.executed.clear();
    s.dispatch(b, id, 7, 2)
        .unwrap_or_else(|e| panic!("CODE {CODE} Other_2 dispatch failed: {e}"));
    id
}

/// Global reads go through the engine's own routing: `score` is the legacy
/// engine global (sel -1), everything else is `Scene::globals` (sel -5).
fn global_of(s: &Scene, name: &str) -> Option<f64> {
    if name == "score" {
        Some(s.score)
    } else {
        s.globals.get(name).copied()
    }
}

fn seed(s: &mut Scene, name: &str, value: f64) {
    if name == "score" {
        s.score = value;
    } else {
        s.globals.insert(name.to_string(), value);
    }
}

/// CODE 17's instructions that executed, as code_offsets, in order.
fn ledger(s: &Scene) -> Vec<usize> {
    s.executed
        .iter()
        .filter(|(c, _)| *c == CODE)
        .map(|(_, o)| o - START)
        .collect()
}

fn ledger_set(s: &Scene) -> BTreeSet<usize> {
    ledger(s).into_iter().collect()
}

fn in_range(off: usize, (lo, hi): (usize, usize)) -> bool {
    (lo..hi).contains(&off)
}

fn which_file(call_off: usize) -> &'static str {
    if call_off < JOIN1 {
        SAVE
    } else if call_off < 30_380 {
        SAVE2
    } else {
        SAVE3
    }
}

// ---- independent re-derivation from the live instruction stream ------------

#[derive(Debug)]
struct LiveRead {
    call_off: usize,
    store_off: usize,
    section_sid: usize,
    key_sid: usize,
    default: f64,
    target: String,
    sel: i32,
}

#[derive(Debug)]
struct LiveWrite {
    call_off: usize,
    load_off: usize,
    section_sid: usize,
    key_sid: usize,
    source: String,
    sel: i32,
}

/// Walks CODE 17 and decodes every `ini_read_real` call from its operand
/// pushes: GML pushes arguments right-to-left, so the stream is
/// `constant(default); cast; string(key); cast; string(section); cast; call`
/// and the value lands in the very next `store`. Nothing here reads the
/// embedded tables — this is the live side of the cross-check.
fn live_reads(b: &Bundle) -> Vec<LiveRead> {
    let ins = body(b);
    let mut out = Vec::new();
    for (j, i) in ins.iter().enumerate() {
        let Op::Call { name, argc } = &i.op else {
            continue;
        };
        if name != "ini_read_real" || *argc != 3 {
            continue;
        }
        assert!(
            j >= 6,
            "CODE {CODE} @{}: read call has no operand pushes",
            i.code_offset
        );
        let default = match &ins[j - 6].op {
            Op::Constant { value } => *value,
            other => panic!(
                "CODE {CODE} @{}: read default is not a constant ({other:?})",
                i.code_offset
            ),
        };
        let key_sid = match &ins[j - 4].op {
            Op::String { string_id } => *string_id,
            other => panic!(
                "CODE {CODE} @{}: read key is not a string ({other:?})",
                i.code_offset
            ),
        };
        let section_sid = match &ins[j - 2].op {
            Op::String { string_id } => *string_id,
            other => panic!(
                "CODE {CODE} @{}: read section is not a string ({other:?})",
                i.code_offset
            ),
        };
        for k in [j - 5, j - 3, j - 1] {
            assert!(
                matches!(ins[k].op, Op::Cast { to: 5 }),
                "CODE {CODE} @{}: read argument at {} is not cast to a string",
                i.code_offset,
                ins[k].code_offset
            );
        }
        let (target, sel) = match &ins[j + 1].op {
            Op::Store { name, selector, .. } => (name.clone(), *selector),
            other => panic!(
                "CODE {CODE} @{}: read result is not stored ({other:?})",
                i.code_offset
            ),
        };
        out.push(LiveRead {
            call_off: i.code_offset,
            store_off: ins[j + 1].code_offset,
            section_sid,
            key_sid,
            default,
            target,
            sel,
        });
    }
    out
}

/// Same decode for the write arms: `load(source); string(key); cast;
/// string(section); cast; call; popz`.
fn live_writes(b: &Bundle) -> Vec<LiveWrite> {
    let ins = body(b);
    let mut out = Vec::new();
    for (j, i) in ins.iter().enumerate() {
        let Op::Call { name, argc } = &i.op else {
            continue;
        };
        if name != "ini_write_real" || *argc != 3 {
            continue;
        }
        assert!(
            j >= 5,
            "CODE {CODE} @{}: write call has no operand pushes",
            i.code_offset
        );
        let (source, sel) = match &ins[j - 5].op {
            Op::Load { name, selector, .. } => (name.clone(), *selector),
            other => panic!(
                "CODE {CODE} @{}: write value is not a global load ({other:?})",
                i.code_offset
            ),
        };
        let key_sid = match &ins[j - 4].op {
            Op::String { string_id } => *string_id,
            other => panic!(
                "CODE {CODE} @{}: write key is not a string ({other:?})",
                i.code_offset
            ),
        };
        let section_sid = match &ins[j - 2].op {
            Op::String { string_id } => *string_id,
            other => panic!(
                "CODE {CODE} @{}: write section is not a string ({other:?})",
                i.code_offset
            ),
        };
        for k in [j - 3, j - 1] {
            assert!(
                matches!(ins[k].op, Op::Cast { to: 5 }),
                "CODE {CODE} @{}: write argument at {} is not cast to a string",
                i.code_offset,
                ins[k].code_offset
            );
        }
        assert!(
            matches!(ins[j + 1].op, Op::Popz),
            "CODE {CODE} @{}: ini_write_real result is not popped",
            i.code_offset
        );
        out.push(LiveWrite {
            call_off: i.code_offset,
            load_off: ins[j - 5].code_offset,
            section_sid,
            key_sid,
            source,
            sel,
        });
    }
    out
}

// ---- tests -----------------------------------------------------------------

#[test]
// CODE 17
fn the_read_table_is_the_live_bytecode_table() {
    let b = bundle();
    let live = live_reads(&b);
    assert_eq!(live.len(), 324, "CODE {CODE} holds 324 ini_read_real arms");
    assert_eq!(
        live.len(),
        READ_ARMS.len(),
        "the embedded read table must enumerate every read arm, no sampling"
    );

    for (i, (row, got)) in READ_ARMS.iter().zip(&live).enumerate() {
        // CODE 17 read arm {i}: key -> global, exactly as the bytecode orders it.
        assert_eq!(
            got.section_sid, SAVE_SECTION_SID,
            "CODE {CODE} read arm {i}: section string id"
        );
        assert_eq!(
            b.string_table[got.section_sid], "Save",
            "CODE {CODE} read arm {i}: section must resolve to \"Save\""
        );
        assert_eq!(
            got.key_sid, row.key_sid,
            "CODE {CODE} read arm {i}: key string id"
        );
        assert_eq!(
            b.string_table[got.key_sid], row.key,
            "CODE {CODE} read arm {i}: key text"
        );
        assert_eq!(
            READ_ARMS[i].key_sid, got.key_sid,
            "CODE {CODE} read arm {i}: table row and live instruction agree on the key sid"
        );
        assert_eq!(
            got.default, row.default,
            "CODE {CODE} read arm {i}: read default"
        );
        assert_eq!(
            got.default, 0.0,
            "CODE {CODE} read arm {i}: every read default is 0"
        );
        assert_eq!(
            got.target, row.target,
            "CODE {CODE} read arm {i}: target global"
        );
        assert_eq!(
            got.sel, row.sel,
            "CODE {CODE} read arm {i}: target selector"
        );
        assert_eq!(
            got.call_off, row.call_off,
            "CODE {CODE} read arm {i}: call offset"
        );
        assert_eq!(
            got.store_off, row.store_off,
            "CODE {CODE} read arm {i}: store offset"
        );
    }

    // Matrix shape: 282 + 6 + 36 arms, in that file order, offsets ascending.
    let block = |(lo, hi): (usize, usize)| {
        READ_ARMS
            .iter()
            .filter(|r| (lo..hi).contains(&r.call_off))
            .count()
    };
    assert_eq!(
        (
            block((0, 13_724)),
            block((29_656, 30_380)),
            block((30_380, 34_224))
        ),
        (282, 6, 36),
        "CODE {CODE}: read arms split 282 savefile.ini / 6 savefile2.ini / 36 savefile3.ini"
    );
    assert!(
        READ_ARMS.windows(2).all(|w| w[0].call_off < w[1].call_off),
        "CODE {CODE}: the embedded read table keeps bytecode order"
    );

    // 324 distinct keys, 324 distinct target globals: no read arm is a repeat.
    let keys: BTreeSet<&str> = READ_ARMS.iter().map(|r| r.key).collect();
    assert_eq!(
        keys.len(),
        324,
        "CODE {CODE}: every read arm names a distinct key"
    );
    let targets: BTreeSet<&str> = READ_ARMS.iter().map(|r| r.target).collect();
    assert_eq!(
        targets.len(),
        324,
        "CODE {CODE}: every read arm has its own target global"
    );

    // The six renamed keys are the interesting part of the mapping.
    let renames: BTreeSet<(&str, &str)> = READ_ARMS
        .iter()
        .filter(|r| r.key != r.target)
        .map(|r| (r.key, r.target))
        .collect();
    assert_eq!(
        renames,
        BTreeSet::from([
            ("bomgunxp", "bombgunxp"),
            ("current_XP", "experience"),
            ("current_level", "level"),
            ("current_maxhp", "maxhp"),
            ("current_score", "score"),
            ("triplejumpactive", "tjumpactive"),
        ]),
        "CODE {CODE}: exactly six keys are stored under a differently spelled global"
    );

    // Read set vs write set: 320 written keys (the ir-save.md contract number),
    // 6 read-only, 2 write-only, 4 duplicate write arms.
    let write_keys: BTreeSet<&str> = WRITE_ARMS.iter().map(|r| r.key).collect();
    assert_eq!(
        write_keys.len(),
        320,
        "CODE {CODE}: 320 distinct written keys = the ir-save.md contract count"
    );
    let read_only: BTreeSet<&str> = keys.difference(&write_keys).copied().collect();
    assert_eq!(
        read_only,
        BTreeSet::from([
            "bomgunxp",
            "coinmultiply",
            "gemdropenabled",
            "poisonenabled",
            "timeplayed",
            "weaponswapped",
        ]),
        "CODE {CODE}: six keys are read from a save and never written back"
    );
    let write_only: BTreeSet<&str> = write_keys.difference(&keys).copied().collect();
    assert_eq!(
        write_only,
        BTreeSet::from(["bombgunxp", "grenadelevel"]),
        "CODE {CODE}: two globals are saved under keys the load never asks for"
    );
    assert_eq!(
        self::write_key_counts(),
        BTreeMap::from([
            ("bladegunbought".to_string(), 2usize),
            ("bowbought".to_string(), 2),
            ("bowxp".to_string(), 2),
            ("bowxptolevelup".to_string(), 2),
        ]),
        "CODE {CODE}: the only duplicated write keys are the four savefile.ini repeats"
    );
    // 282 + 6 + 36 write arms, 278 distinct in the main file: the four repeats.
    assert_eq!(
        WRITE_ARMS.len(),
        324,
        "CODE {CODE}: 324 ini_write_real arms"
    );
    let main_written: BTreeSet<&str> = WRITE_ARMS
        .iter()
        .filter(|r| which_file(r.call_off) == SAVE)
        .map(|r| r.key)
        .collect();
    assert_eq!(
        main_written.len(),
        278,
        "CODE {CODE}: savefile.ini writes 278 distinct keys"
    );
    // Call-site census, straight from the body: this is the whole branch
    // surface of CODE 17 in one line.
    let calls = |name: &str| {
        body(&b)
            .iter()
            .filter(|i| matches!(&i.op, Op::Call { name: n, .. } if n == name))
            .count()
    };
    assert_eq!(
        (
            calls("ini_read_real"),
            calls("ini_write_real"),
            calls("ini_open"),
            calls("ini_close"),
            calls("file_exists"),
            calls("AdColony_Init"),
            calls("instance_create"),
        ),
        (324, 324, 4, 4, 6, 1, 1),
        "CODE {CODE}: call-site census (reads, writes, opens, closes, gates, ad init, intro)"
    );
    // Every comparison in the body belongs to the damage block: 120 `==` arms
    // plus 12 `> 10` clamps.
    let cmps: Vec<usize> = body(&b)
        .iter()
        .filter(|i| matches!(i.op, Op::Cmp { .. }))
        .map(|i| i.code_offset)
        .collect();
    assert_eq!(cmps.len(), 132, "CODE {CODE}: 132 comparisons in the body");
    assert!(
        cmps.iter().all(|o| in_range(*o, DAMAGE)),
        "CODE {CODE}: every comparison lives in the damage block (34224..39252)"
    );

    // The default tables and the write table fit together exactly: every one
    // of the 320 saved globals is seeded by some default store, and the ten
    // leftover default globals are the ones the body resets without saving.
    let default_globals: BTreeSet<&str> = MAIN_DEFAULTS
        .iter()
        .chain(SF2_DEFAULTS.iter())
        .chain(SF3_DEFAULTS.iter())
        .map(|r| r.global)
        .collect();
    let write_sources: BTreeSet<&str> = WRITE_ARMS.iter().map(|r| r.source).collect();
    assert_eq!(
        write_sources.len(),
        320,
        "CODE {CODE}: 320 distinct write sources"
    );
    assert!(
        write_sources.is_subset(&default_globals),
        "CODE {CODE}: every saved global must be seeded by a default store, missing {:?}",
        write_sources
            .difference(&default_globals)
            .collect::<Vec<_>>()
    );
    assert_eq!(
        default_globals
            .difference(&write_sources)
            .copied()
            .collect::<BTreeSet<_>>(),
        BTreeSet::from([
            "coinmultiply",
            "drawchange",
            "drawlevelup",
            "drawweaponchange",
            "drawweaponlevelup",
            "gemdropenabled",
            "health1",
            "poisonenabled",
            "timeplayed",
            "weaponswapped",
        ]),
        "CODE {CODE}: exactly ten default stores fill globals the body never saves"
    );
}

/// Helper so the census reads as data, not as an inline fold.
fn write_key_counts() -> BTreeMap<String, usize> {
    let mut counts: BTreeMap<String, usize> = BTreeMap::new();
    for r in WRITE_ARMS {
        *counts.entry(r.key.to_string()).or_insert(0) += 1;
    }
    counts.retain(|_, n| *n > 1);
    counts
}

#[test]
// CODE 17
fn the_write_table_is_the_live_bytecode_table() {
    let b = bundle();
    let live = live_writes(&b);
    assert_eq!(live.len(), 324, "CODE {CODE} holds 324 ini_write_real arms");
    assert_eq!(
        live.len(),
        WRITE_ARMS.len(),
        "the embedded write table enumerates every arm"
    );

    for (i, (row, got)) in WRITE_ARMS.iter().zip(&live).enumerate() {
        // CODE 17 write arm {i}: global -> key, exactly as the bytecode orders it.
        assert_eq!(
            got.section_sid, SAVE_SECTION_SID,
            "CODE {CODE} write arm {i}: section string id"
        );
        assert_eq!(
            got.key_sid, row.key_sid,
            "CODE {CODE} write arm {i}: key string id"
        );
        assert_eq!(
            b.string_table[got.key_sid], row.key,
            "CODE {CODE} write arm {i}: key text"
        );
        assert_eq!(
            got.source, row.source,
            "CODE {CODE} write arm {i}: source global"
        );
        assert_eq!(
            got.sel, row.sel,
            "CODE {CODE} write arm {i}: source selector"
        );
        assert_eq!(
            got.call_off, row.call_off,
            "CODE {CODE} write arm {i}: call offset"
        );
        assert_eq!(
            got.load_off, row.load_off,
            "CODE {CODE} write arm {i}: load offset"
        );
    }

    let block = |(lo, hi): (usize, usize)| {
        WRITE_ARMS
            .iter()
            .filter(|r| (lo..hi).contains(&r.call_off))
            .count()
    };
    assert_eq!(
        (
            block((0, 29_656)),
            block((29_656, 30_380)),
            block((30_380, 34_224))
        ),
        (282, 6, 36),
        "CODE {CODE}: write arms split 282 / 6 / 36 across the three files"
    );

    // Every key that both sides touch must use the SAME global on both sides:
    // that equality is what makes a save round trip at all.
    let read_target: BTreeMap<&str, &str> = READ_ARMS.iter().map(|r| (r.key, r.target)).collect();
    for row in WRITE_ARMS.iter() {
        if let Some(&target) = read_target.get(row.key) {
            assert_eq!(
                row.source, target,
                "CODE {CODE}: key {} is read into {} but written from {}",
                row.key, target, row.source
            );
        }
    }

    // The read-only keys never appear here; the two write-only ones always do.
    let write_keys: BTreeSet<&str> = WRITE_ARMS.iter().map(|r| r.key).collect();
    for key in [
        "bomgunxp",
        "coinmultiply",
        "gemdropenabled",
        "poisonenabled",
        "timeplayed",
        "weaponswapped",
    ] {
        assert!(
            !write_keys.contains(key),
            "CODE {CODE}: {key} is read-only, never saved"
        );
    }
    for key in ["bombgunxp", "grenadelevel"] {
        assert!(
            write_keys.contains(key),
            "CODE {CODE}: {key} is saved, never loaded"
        );
    }
}

#[test]
// CODE 17
fn every_read_arm_restores_its_own_key_into_its_own_global() {
    let b = bundle();
    let dir = ini_dir("read_all");

    // One value per arm, unique across the table: a key that reads the wrong
    // value, a target that is written twice, or a swapped pair all show up.
    // Weapon levels stay in 1..=10 so the `> 10` clamp cannot rewrite them.
    let value = |i: usize, target: &str| -> f64 {
        if WEAPON_LEVELS.contains(&target) {
            (i % 10 + 1) as f64
        } else {
            1000.0 + i as f64
        }
    };

    for file in [SAVE, SAVE2, SAVE3] {
        let rows: Vec<(&str, f64)> = READ_ARMS
            .iter()
            .enumerate()
            .filter(|(_, r)| which_file(r.call_off) == file)
            .map(|(i, r)| (r.key, value(i, r.target)))
            .collect();
        write_ini(&dir, file, &rows);
    }

    let mut s = scene(&b, &dir);
    for r in READ_ARMS.iter() {
        seed(&mut s, r.target, SENTINEL);
    }
    start(&b, &mut s);

    for (i, r) in READ_ARMS.iter().enumerate() {
        // CODE 17 read arm {i}: {key} -> global.{target}
        let want = value(i, r.target);
        assert_eq!(
            global_of(&s, r.target),
            Some(want),
            "CODE {CODE} read arm {i}: key {:?} must land in global {} ({}), got {:?}",
            r.key,
            r.target,
            want,
            global_of(&s, r.target)
        );
    }

    // Instruction-level proof of the branch that ran: exactly these 324 read
    // calls in table order, the three opens/closes, and no write at all.
    let got = ledger(&s);
    let read_calls: Vec<usize> = got
        .iter()
        .copied()
        .filter(|o| READ_ARMS.iter().any(|r| r.call_off == *o))
        .collect();
    assert_eq!(
        read_calls,
        READ_ARMS.iter().map(|r| r.call_off).collect::<Vec<_>>(),
        "CODE {CODE}: the 324 read calls must run in bytecode order, each exactly once"
    );
    let write_calls: Vec<usize> = got
        .iter()
        .copied()
        .filter(|o| WRITE_ARMS.iter().any(|r| r.call_off == *o))
        .collect();
    // The main save block writes nothing here; savefile2.ini and savefile3.ini
    // do rewrite themselves on load (they read then write the same keys), so
    // exactly their 6 + 36 arms may appear.
    let secondary_writes: Vec<usize> = WRITE_ARMS
        .iter()
        .filter(|r| which_file(r.call_off) != SAVE)
        .map(|r| r.call_off)
        .collect();
    assert_eq!(
        write_calls, secondary_writes,
        "CODE {CODE}: only the secondary files' read-then-write-back may run"
    );
    assert!(
        !got.contains(&WRITE_ARMS[0].call_off),
        "CODE {CODE}: the main save block must not run when savefile.ini exists"
    );
    for off in [112, 29_696, 30_420] {
        assert!(
            got.contains(&off),
            "CODE {CODE}: ini_open at {off} must run"
        );
    }
    for off in [13_660, 30_260, 33_744] {
        assert!(
            got.contains(&off),
            "CODE {CODE}: ini_close at {off} must run"
        );
    }

    // Neither else-if default block was entered (all three files exist).
    for (name, row) in [
        ("savefile.ini", MAIN_DEFAULTS[0]),
        ("savefile2.ini", SF2_DEFAULTS[0]),
        ("savefile3.ini", SF3_DEFAULTS[0]),
    ] {
        assert!(
            !got.contains(&row.off),
            "CODE {CODE}: {name}'s default store at {} must not run when the file exists",
            row.off
        );
    }

    // The then-branch tail zeroes the four draw flags even on the load path.
    for flag in [
        "drawchange",
        "drawlevelup",
        "drawweaponlevelup",
        "drawweaponchange",
    ] {
        assert_eq!(
            s.globals.get(flag).copied(),
            Some(0.0),
            "CODE {CODE}: the load path still clears {flag}"
        );
    }
    let tail_stores: Vec<usize> = got
        .iter()
        .copied()
        .filter(|o| in_range(*o, THEN1_TAIL))
        .collect();
    assert_eq!(
        tail_stores.len(),
        8,
        "CODE {CODE}: the four tail clears are four constant+store pairs: {tail_stores:?}"
    );

    // Nothing outside the preamble, the three then-branches and the shared tail
    // may execute: no default block, no main save block.
    let allowed: [(usize, usize); 7] = [
        (0, 100),
        THEN1,
        (JOIN1, 29696),
        THEN2,
        (30_380, 30_420),
        THEN3,
        DAMAGE,
    ];
    let stray: Vec<usize> = got
        .iter()
        .copied()
        .filter(|o| !allowed.iter().any(|r| in_range(*o, *r)))
        .collect();
    assert!(
        stray.is_empty(),
        "CODE {CODE}: instructions ran outside the load branches: {stray:?}"
    );
    assert_eq!(
        *got.last().unwrap(),
        BODY_END - 4,
        "CODE {CODE}: the body joins its final popz"
    );
}

#[test]
// CODE 17
fn a_missing_savefile_writes_the_whole_table_and_a_second_start_restores_it() {
    let b = bundle();
    let dir = ini_dir("write_all");

    // Phase 1: no save on disk -> the else-if branch: 330 defaults, 324 writes.
    let mut s = scene(&b, &dir);
    for r in READ_ARMS.iter() {
        seed(&mut s, r.target, SENTINEL);
    }
    start(&b, &mut s);

    for row in MAIN_DEFAULTS
        .iter()
        .chain(SF2_DEFAULTS.iter())
        .chain(SF3_DEFAULTS.iter())
    {
        // CODE 17 default store at {row.off}: global.{row.global} = {row.value}
        assert_eq!(
            global_of(&s, row.global),
            Some(row.value),
            "CODE {CODE}: default store at {} must set {} to {}",
            row.off,
            row.global,
            row.value
        );
        assert_eq!(
            row.sel,
            if row.global == "score" { -1 } else { -5 },
            "CODE {CODE}: default store at {} writes {} at selector {}",
            row.off,
            row.global,
            row.sel
        );
    }
    assert_eq!(
        s.score, 100.0,
        "CODE {CODE}: the fresh-start branch sets score = 100"
    );

    let got = ledger(&s);
    let read_calls = got
        .iter()
        .filter(|o| READ_ARMS.iter().any(|r| r.call_off == **o))
        .count();
    assert_eq!(
        read_calls, 0,
        "CODE {CODE}: no read may run without a save file"
    );
    let write_calls: Vec<usize> = got
        .iter()
        .copied()
        .filter(|o| WRITE_ARMS.iter().any(|r| r.call_off == *o))
        .collect();
    // Only the main savefile.ini else-branch writes here: the secondary files
    // are absent too, so their else-branches set defaults instead of saving.
    let main_writes: Vec<usize> = WRITE_ARMS
        .iter()
        .filter(|r| which_file(r.call_off) == SAVE)
        .map(|r| r.call_off)
        .collect();
    assert_eq!(
        main_writes.len(),
        282,
        "CODE {CODE}: savefile.ini has 282 write arms"
    );
    assert_eq!(
        write_calls, main_writes,
        "CODE {CODE}: all 282 savefile.ini write calls run, in bytecode order"
    );

    // The in-memory INI cache holds the 278 distinct savefile.ini keys, each
    // carrying its source global's fresh-start value; the four duplicate arms
    // collapse onto one key.
    let mut expect: BTreeMap<(String, String, String), f64> = BTreeMap::new();
    for r in WRITE_ARMS.iter().filter(|r| which_file(r.call_off) == SAVE) {
        let val = global_of(&s, r.source)
            .unwrap_or_else(|| panic!("CODE {CODE}: write source {} has no value", r.source));
        expect.insert(
            (SAVE.to_string(), "Save".to_string(), r.key.to_string()),
            val,
        );
    }
    assert_eq!(
        expect.len(),
        278,
        "CODE {CODE}: 278 distinct (file, section, key) triples"
    );
    assert_eq!(
        s.ini_data.len(),
        278,
        "CODE {CODE}: the save cache holds exactly the 278 distinct savefile.ini keys"
    );
    for (k, v) in &expect {
        assert_eq!(
            s.ini_data.get(k).copied(),
            Some(*v),
            "CODE {CODE}: saved key {:?}/{} must carry its global's value {v}",
            k.2,
            k.1
        );
    }

    // On disk: savefile.ini only, [Save] header, 278 distinct key lines. The
    // secondary files are never created from their default branches.
    let text = std::fs::read_to_string(dir.join(SAVE))
        .unwrap_or_else(|e| panic!("CODE {CODE}: {SAVE} must be flushed to disk: {e}"));
    assert!(
        text.starts_with("[Save]\n"),
        "CODE {CODE}: {SAVE} must open with its section header"
    );
    let body_lines: Vec<&str> = text
        .lines()
        .filter(|l| !l.is_empty() && !l.starts_with('['))
        .collect();
    assert_eq!(
        body_lines.len(),
        278,
        "CODE {CODE}: {SAVE} must hold 278 distinct key lines"
    );
    let mut seen = BTreeSet::new();
    for line in &body_lines {
        let (k, v) = line.split_once('=').expect("key=value line");
        assert!(
            seen.insert(k.to_string()),
            "CODE {CODE}: {SAVE} wrote {k} twice"
        );
        assert_eq!(
            v.parse::<f64>().ok(),
            Some(expect[&(SAVE.to_string(), "Save".to_string(), k.to_string())]),
            "CODE {CODE}: {SAVE} line {k} must carry the global's value"
        );
    }
    for absent in [SAVE2, SAVE3] {
        assert!(
            !dir.join(absent).is_file(),
            "CODE {CODE}: {absent}'s default branch must not create the file"
        );
    }

    // Phase 2: a second start on the same directory takes the load branch.
    let mut s2 = scene(&b, &dir);
    for r in READ_ARMS.iter() {
        seed(&mut s2, r.target, SENTINEL);
    }
    // `grenadelevel` is saved but never read: give it a value the load must keep.
    seed(&mut s2, "grenadelevel", SENTINEL);
    start(&b, &mut s2);

    for r in READ_ARMS.iter() {
        let want = if which_file(r.call_off) == SAVE {
            // 276 keys round trip: the saved value comes back under the same
            // key; the six read-only keys were never saved (read default 0).
            expect
                .get(&(SAVE.to_string(), "Save".to_string(), r.key.to_string()))
                .copied()
                .unwrap_or(0.0)
        } else {
            // The secondary files are still absent: their default branches set 0.
            0.0
        };
        assert_eq!(
            global_of(&s2, r.target),
            Some(want),
            "CODE {CODE}: second start must restore {} = {want} (key {})",
            r.target,
            r.key
        );
    }
    // `grenadelevel` is saved but never read: the load leaves it alone.
    assert!(
        WRITE_ARMS.iter().any(|r| r.key == "grenadelevel"),
        "CODE {CODE}: grenadelevel is written"
    );
    assert_eq!(
        s2.globals.get("grenadelevel").copied(),
        Some(SENTINEL),
        "CODE {CODE}: the load never restores grenadelevel - it must keep its pre-start value"
    );
}

#[test]
// CODE 17
fn the_bomgunxp_typo_makes_that_one_key_lossy() {
    let b = bundle();
    let dir = ini_dir("lossy");

    // A save that carries BOTH spellings: the load asks for "bomgunxp", so that
    // is the value the global gets, and the well-formed key is ignored.
    write_ini(
        &dir,
        SAVE,
        &[
            ("bomgunxp", 7.0),
            ("bombgunxp", 9.0),
            ("grenadelevel", 6.0),
            ("coinmultiply", 3.0),
            ("gemdropenabled", 2.0),
            ("poisonenabled", 5.0),
            ("timeplayed", 77.0),
            ("weaponswapped", 4.0),
        ],
    );
    let mut s = scene(&b, &dir);
    for name in [
        "bombgunxp",
        "grenadelevel",
        "coinmultiply",
        "gemdropenabled",
        "poisonenabled",
        "timeplayed",
        "weaponswapped",
    ] {
        seed(&mut s, name, SENTINEL);
    }
    start(&b, &mut s);

    // CODE 17 read arm: "bomgunxp" -> global.bombgunxp (the typo'd read key).
    assert_eq!(
        s.globals.get("bombgunxp").copied(),
        Some(7.0),
        "CODE {CODE}: the load reads the key {:?}, not {:?}",
        "bomgunxp",
        "bombgunxp"
    );
    for (name, want) in [
        ("coinmultiply", 3.0),
        ("gemdropenabled", 2.0),
        ("poisonenabled", 5.0),
        ("timeplayed", 77.0),
        ("weaponswapped", 4.0),
    ] {
        assert_eq!(
            s.globals.get(name).copied(),
            Some(want),
            "CODE {CODE}: {name} is read (but never written back)"
        );
    }
    // `grenadelevel` is not a read key at all, so the 6 on disk is ignored.
    assert_eq!(
        s.globals.get("grenadelevel").copied(),
        Some(SENTINEL),
        "CODE {CODE}: grenadelevel has no read arm, so the saved value is unreachable"
    );

    // And the write side proves the asymmetry: after a start with no save, the
    // file carries "bombgunxp"/"grenadelevel" and none of the six read-only keys.
    let dir2 = ini_dir("lossy_write");
    let mut s2 = scene(&b, &dir2);
    start(&b, &mut s2);
    let disk = std::fs::read_to_string(dir2.join(SAVE)).expect("savefile.ini");
    let disk_keys: BTreeSet<&str> = disk
        .lines()
        .filter(|l| !l.is_empty() && !l.starts_with('['))
        .map(|l| l.split_once('=').expect("key=value").0)
        .collect();
    assert!(
        disk_keys.contains("bombgunxp"),
        "CODE {CODE}: the save writes bombgunxp"
    );
    assert!(
        disk_keys.contains("grenadelevel"),
        "CODE {CODE}: the save writes grenadelevel"
    );
    assert!(
        !disk_keys.contains("bomgunxp"),
        "CODE {CODE}: the save never writes the key the load reads"
    );
    for key in [
        "coinmultiply",
        "gemdropenabled",
        "poisonenabled",
        "timeplayed",
        "weaponswapped",
    ] {
        assert!(
            !disk_keys.contains(key),
            "CODE {CODE}: {key} is read-only, so a save cannot carry it"
        );
    }
}

#[test]
// CODE 17
fn the_three_file_gates_select_their_own_branches() {
    let b = bundle();
    // Every presence combination of the three save files.
    for main in [false, true] {
        for sf2 in [false, true] {
            for sf3 in [false, true] {
                let dir = ini_dir(&format!(
                    "gate_{}{}{}",
                    u8::from(main),
                    u8::from(sf2),
                    u8::from(sf3)
                ));
                if main {
                    write_ini(&dir, SAVE, &[(READ_ARMS[0].key, 1.0)]);
                }
                if sf2 {
                    write_ini(&dir, SAVE2, &[(READ_ARMS[282].key, 1.0)]);
                }
                if sf3 {
                    write_ini(&dir, SAVE3, &[(READ_ARMS[288].key, 1.0)]);
                }
                let mut s = scene(&b, &dir);
                start(&b, &mut s);
                let got = ledger_set(&s);

                // CODE 17 gate {main}{sf2}{sf3}: reads, writes and defaults by branch.
                let reads = got
                    .iter()
                    .filter(|o| READ_ARMS.iter().any(|r| r.call_off == **o))
                    .count();
                let writes = got
                    .iter()
                    .filter(|o| WRITE_ARMS.iter().any(|r| r.call_off == **o))
                    .count();
                let expect_reads =
                    282 * usize::from(main) + 6 * usize::from(sf2) + 36 * usize::from(sf3);
                // A present secondary file is read AND written back in the same
                // branch; the main file only writes when it is absent.
                let expect_writes =
                    282 * usize::from(!main) + 6 * usize::from(sf2) + 36 * usize::from(sf3);
                assert_eq!(
                    reads, expect_reads,
                    "CODE {CODE}: main={main} sf2={sf2} sf3={sf3} read arms"
                );
                assert_eq!(
                    writes, expect_writes,
                    "CODE {CODE}: main={main} sf2={sf2} sf3={sf3} write arms"
                );

                for (name, present, table) in [
                    ("savefile.ini", main, &MAIN_DEFAULTS[..]),
                    ("savefile2.ini", sf2, &SF2_DEFAULTS[..]),
                    ("savefile3.ini", sf3, &SF3_DEFAULTS[..]),
                ] {
                    for row in table {
                        let ran = got.contains(&row.off);
                        assert_eq!(
                            ran, !present,
                            "CODE {CODE}: {name} default store at {} ran={ran} but present={present}",
                            row.off
                        );
                    }
                }

                // `file_exists` is evaluated twice per missing file (gate + the
                // else-if's `not file_exists`), once per present file.
                let mut expect_exists = BTreeSet::new();
                expect_exists.insert(GATE1);
                expect_exists.insert(GATE2);
                expect_exists.insert(GATE3);
                if !main {
                    expect_exists.insert(ELSE1_TEST);
                }
                if !sf2 {
                    expect_exists.insert(ELSE2_TEST);
                }
                if !sf3 {
                    expect_exists.insert(ELSE3_TEST);
                }
                assert_eq!(
                    file_exists_offsets(&s),
                    expect_exists,
                    "CODE {CODE}: main={main} sf2={sf2} sf3={sf3} file_exists evaluations"
                );

                let mut expect_open = BTreeSet::new();
                expect_open.insert(if main { 112 } else { 17_224 });
                if sf2 {
                    expect_open.insert(29_696);
                }
                if sf3 {
                    expect_open.insert(30_420);
                }
                let opens: BTreeSet<usize> = got
                    .iter()
                    .copied()
                    .filter(|o| [112usize, 17_224, 29_696, 30_420].contains(o))
                    .collect();
                assert_eq!(
                    opens, expect_open,
                    "CODE {CODE}: main={main} sf2={sf2} sf3={sf3} ini_open sites"
                );

                // The if/else join is reached exactly once per gate.
                assert!(
                    got.contains(&JOIN1),
                    "CODE {CODE}: gate 1 must reach its join"
                );
            }
        }
    }
}

/// The `file_exists` call offsets CODE 17 actually entered.
fn file_exists_offsets(s: &Scene) -> BTreeSet<usize> {
    ledger_set(s)
        .into_iter()
        .filter(|o| [GATE1, ELSE1_TEST, GATE2, ELSE2_TEST, GATE3, ELSE3_TEST].contains(o))
        .collect()
}

#[test]
// CODE 17
fn every_weapon_damage_arm_maps_its_level() {
    let b = bundle();
    assert_eq!(
        DAMAGE_TABLES.len(),
        12,
        "CODE {CODE} carries twelve weapon damage tables"
    );

    // Cross-check the embedded tables against the live instruction stream:
    // each arm is `load level; constant K; cmp eq; bf; constant dmg; store`,
    // followed at the end of the table by `load level; constant 10; cmp gt; bf;
    // constant 10; store level`.
    let live = live_damage_tables(&b);
    assert_eq!(
        live.len(),
        DAMAGE_TABLES.len(),
        "CODE {CODE}: live damage table count"
    );
    for (i, (row, got)) in DAMAGE_TABLES.iter().zip(&live).enumerate() {
        assert_eq!(
            got.level_global, row.level_global,
            "CODE {CODE}: damage table {i} level source"
        );
        assert_eq!(
            got.damage_global, row.damage_global,
            "CODE {CODE}: damage table {i} target"
        );
        for (k, (arm, live_arm)) in row.arms.iter().zip(&got.arms).enumerate() {
            assert_eq!(
                arm.level, live_arm.level,
                "CODE {CODE}: table {} arm {k} level",
                row.damage_global
            );
            assert_eq!(
                arm.damage, live_arm.damage,
                "CODE {CODE}: table {} arm {k} damage",
                row.damage_global
            );
            assert_eq!(
                arm.cmp_off, live_arm.cmp_off,
                "CODE {CODE}: table {} arm {k} cmp offset",
                row.damage_global
            );
            assert_eq!(
                arm.store_off, live_arm.store_off,
                "CODE {CODE}: table {} arm {k} store offset",
                row.damage_global
            );
        }
        assert_eq!(
            got.clamp_level, row.clamp_level,
            "CODE {CODE}: table {} clamp threshold",
            row.damage_global
        );
        assert_eq!(
            got.clamp_set, row.clamp_set,
            "CODE {CODE}: table {} clamp value",
            row.damage_global
        );
        assert_eq!(
            got.clamp_cmp, row.clamp_cmp,
            "CODE {CODE}: table {} clamp cmp offset",
            row.damage_global
        );
    }

    // Every level global the tables read must be one the save table restores.
    let read_targets: BTreeSet<&str> = READ_ARMS.iter().map(|r| r.target).collect();
    for t in DAMAGE_TABLES.iter() {
        assert!(
            read_targets.contains(t.level_global),
            "CODE {CODE}: {} comes from the save table, so it must have a read arm",
            t.level_global
        );
    }

    for table in DAMAGE_TABLES.iter() {
        for arm in table.arms.iter() {
            // CODE 17 damage table {table.damage_global} arm level {arm.level}
            let dir = ini_dir("dmg");
            write_ini(&dir, SAVE, &[(table.level_global, arm.level)]);
            let mut s = scene(&b, &dir);
            for other in DAMAGE_TABLES.iter() {
                seed(&mut s, other.damage_global, SENTINEL);
            }
            start(&b, &mut s);

            assert_eq!(
                s.globals.get(table.damage_global).copied(),
                Some(arm.damage),
                "CODE {CODE}: {} level {level} must yield damage {}",
                table.damage_global,
                arm.damage,
                level = arm.level
            );
            // Cross-table isolation: the other eleven tables must not fire.
            for other in DAMAGE_TABLES
                .iter()
                .filter(|o| o.damage_global != table.damage_global)
            {
                assert_eq!(
                    s.globals.get(other.damage_global).copied(),
                    Some(SENTINEL),
                    "CODE {CODE}: {} level {} must not touch {}",
                    table.level_global,
                    arm.level,
                    other.damage_global
                );
            }
            // Exactly one damage store executed: this arm, nothing else.
            let got = ledger_set(&s);
            let stores: Vec<usize> = got
                .iter()
                .copied()
                .filter(|o| {
                    DAMAGE_TABLES
                        .iter()
                        .flat_map(|t| t.arms.iter())
                        .any(|a| a.store_off == *o)
                })
                .collect();
            assert_eq!(
                stores,
                vec![arm.store_off],
                "CODE {CODE}: {} level {} must execute exactly its own store",
                table.damage_global,
                arm.level
            );
            // All ten `==` comparisons plus the clamp comparison ran (independent
            // `if`s, not a switch), and the level was not clamped at 1..=10.
            for a in table.arms.iter() {
                assert!(
                    got.contains(&a.cmp_off),
                    "CODE {CODE}: every == arm is tested"
                );
            }
            assert!(
                got.contains(&table.clamp_cmp),
                "CODE {CODE}: the > 10 clamp is always tested"
            );
            assert_eq!(
                s.globals.get(table.level_global).copied(),
                Some(arm.level),
                "CODE {CODE}: a legal level must survive the clamp"
            );
        }

        // Negative cells: levels the table does not cover. `> 10` clamps the
        // level but no arm fires, so damage keeps the sentinel; 0 and negatives
        // match nothing and are not clamped either.
        for (level, clamped) in [
            (0.0, false),
            (-1.0, false),
            (11.0, true),
            (99.0, true),
            (2.5, false),
        ] {
            // CODE 17 damage table {table.damage_global} negative level {level}
            let dir = ini_dir("dmg_neg");
            write_ini(&dir, SAVE, &[(table.level_global, level)]);
            let mut s = scene(&b, &dir);
            for other in DAMAGE_TABLES.iter() {
                seed(&mut s, other.damage_global, SENTINEL);
                seed(&mut s, other.level_global, SENTINEL);
            }
            seed(&mut s, table.level_global, SENTINEL);
            start(&b, &mut s);

            assert_eq!(
                s.globals.get(table.damage_global).copied(),
                Some(SENTINEL),
                "CODE {CODE}: {} level {level} matches no arm, so damage must stay untouched",
                table.damage_global
            );
            let want_level = if clamped { 10.0 } else { level };
            assert_eq!(
                s.globals.get(table.level_global).copied(),
                Some(want_level),
                "CODE {CODE}: {} level {level} must {} the clamp",
                table.level_global,
                if clamped { "hit" } else { "miss" }
            );
            let got = ledger_set(&s);
            let stores = got
                .iter()
                .filter(|o| {
                    DAMAGE_TABLES
                        .iter()
                        .flat_map(|t| t.arms.iter())
                        .any(|a| a.store_off == **o)
                })
                .count();
            assert_eq!(
                stores, 0,
                "CODE {CODE}: no damage arm may fire for level {level}"
            );
            assert_eq!(
                got.contains(&table.clamp_cmp),
                true,
                "CODE {CODE}: the clamp comparison always runs"
            );
            for other in DAMAGE_TABLES
                .iter()
                .filter(|o| o.damage_global != table.damage_global)
            {
                if other.level_global == table.level_global {
                    continue;
                }
                assert_eq!(
                    s.globals.get(other.damage_global).copied(),
                    Some(SENTINEL),
                    "CODE {CODE}: a negative level in one table must not touch {}",
                    other.damage_global
                );
            }
        }
    }
}

#[derive(Debug)]
struct LiveDamageTable {
    damage_global: String,
    level_global: String,
    arms: Vec<DamageArm>,
    clamp_level: f64,
    clamp_set: f64,
    clamp_cmp: usize,
}

/// Decode the twelve `if (level == K) damage = D;` chains plus their trailing
/// `if (level > 10) level = 10;` from the live instruction stream, starting at
/// [`DAMAGE`].
fn live_damage_tables(b: &Bundle) -> Vec<LiveDamageTable> {
    let ins = body(b);
    let mut out: Vec<LiveDamageTable> = Vec::new();
    let mut k = 0usize;
    while k < ins.len() {
        let i = &ins[k];
        if !in_range(i.code_offset, DAMAGE) {
            k += 1;
            continue;
        }
        let Op::Cmp { comparison } = i.op else {
            k += 1;
            continue;
        };
        let Op::Constant { value: threshold } = &ins[k - 1].op else {
            panic!(
                "CODE {CODE} @{}: comparison has no level constant",
                i.code_offset
            )
        };
        let Op::Load {
            name: level_global,
            selector: -5,
            ..
        } = &ins[k - 2].op
        else {
            panic!(
                "CODE {CODE} @{}: comparison does not follow a global level load",
                i.code_offset
            )
        };
        assert!(
            matches!(ins[k + 1].op, Op::Bf { .. }),
            "CODE {CODE} @{}: comparison must guard a body with bf",
            i.code_offset
        );
        let Op::Constant { value: result } = &ins[k + 2].op else {
            panic!(
                "CODE {CODE} @{}: arm body is not a single constant store",
                i.code_offset
            )
        };
        let Op::Store {
            name: stored,
            selector: -5,
            ..
        } = &ins[k + 3].op
        else {
            panic!(
                "CODE {CODE} @{}: arm body does not store a global",
                i.code_offset
            )
        };
        let store_off = ins[k + 3].code_offset;
        match comparison {
            3 => {
                if out.last().map(|t| t.level_global.as_str()) != Some(level_global.as_str()) {
                    out.push(LiveDamageTable {
                        damage_global: stored.clone(),
                        level_global: level_global.clone(),
                        arms: Vec::new(),
                        clamp_level: 0.0,
                        clamp_set: 0.0,
                        clamp_cmp: 0,
                    });
                }
                let t = out.last_mut().expect("table");
                assert_eq!(
                    t.damage_global, *stored,
                    "CODE {CODE}: one damage global per table"
                );
                t.arms.push(DamageArm {
                    level: *threshold,
                    damage: *result,
                    cmp_off: i.code_offset,
                    store_off,
                });
            }
            6 => {
                let t = out
                    .last_mut()
                    .unwrap_or_else(|| panic!("CODE {CODE}: clamp before any arm"));
                assert_eq!(
                    t.level_global, *level_global,
                    "CODE {CODE}: clamp reads its own level"
                );
                t.clamp_level = *threshold;
                t.clamp_set = *result;
                t.clamp_cmp = i.code_offset;
                assert_eq!(
                    stored, level_global,
                    "CODE {CODE}: the clamp writes the level back"
                );
            }
            other => panic!(
                "CODE {CODE} @{}: unexpected comparison {other} in the damage block",
                i.code_offset
            ),
        }
        k += 1;
    }
    out
}

#[test]
// CODE 17
fn the_preamble_and_epilogue_run_once_on_every_path() {
    let b = bundle();
    let dir = ini_dir("head_tail");
    write_ini(&dir, SAVE, &[(READ_ARMS[0].key, 1.0)]);

    let mut s = scene(&b, &dir);
    seed(&mut s, "warpfrommap", SENTINEL);
    seed(&mut s, "ending", SENTINEL);
    let before = s.instances.len();
    start(&b, &mut s);

    // CODE 17 preamble: AdColony_Init(app, zone, "") then two global clears.
    let got = ledger_set(&s);
    assert!(
        got.contains(&0),
        "CODE {CODE}: the first pushed string is the empty third arg"
    );
    assert!(
        got.contains(&36),
        "CODE {CODE}: AdColony_Init must be called exactly once"
    );
    assert_eq!(
        s.globals.get("warpfrommap").copied(),
        Some(0.0),
        "CODE {CODE}: the preamble clears warpfrommap on the load path"
    );
    assert_eq!(
        s.globals.get("ending").copied(),
        Some(0.0),
        "CODE {CODE}: the preamble clears ending"
    );

    // The three AdColony string constants, resolved through the asset table.
    let intro_calls = body(&b)
        .iter()
        .filter(|i| matches!(&i.op, Op::Call { name, .. } if name == "AdColony_Init"))
        .count();
    assert_eq!(
        intro_calls, 1,
        "CODE {CODE}: exactly one AdColony_Init call site"
    );
    let sids: Vec<usize> = body(&b)
        .iter()
        .take(7)
        .filter_map(|i| match &i.op {
            Op::String { string_id } => Some(*string_id),
            _ => None,
        })
        .collect();
    assert_eq!(
        sids.iter()
            .map(|s| b.string_table[*s].clone())
            .collect::<Vec<_>>(),
        vec![
            "".to_string(),
            "vz1aca9f7894b44cec93".to_string(),
            "app73023f81ce5d4f508a".to_string()
        ],
        "CODE {CODE}: AdColony_Init's three arguments, pushed right-to-left"
    );

    // CODE 17 epilogue: instance_create(x, y, obj_introduction) and its popz.
    assert!(
        got.contains(&EPILOGUE_CREATE),
        "CODE {CODE}: the epilogue must create obj_introduction"
    );
    assert_eq!(
        ledger(&s).last().copied(),
        Some(BODY_END - 4),
        "CODE {CODE}: the body ends on its final popz"
    );
    let intros = s
        .instances
        .values()
        .filter(|i| i.object == INTRO_OBJECT)
        .count();
    assert_eq!(
        intros, 1,
        "CODE {CODE}: exactly one obj_introduction is created"
    );
    assert!(
        s.instances.len() > before,
        "CODE {CODE}: the epilogue adds an instance"
    );

    // The same two clears happen on the fresh-start (no save) path.
    let dir2 = ini_dir("head_tail_fresh");
    let mut s2 = scene(&b, &dir2);
    seed(&mut s2, "warpfrommap", SENTINEL);
    seed(&mut s2, "ending", SENTINEL);
    start(&b, &mut s2);
    assert_eq!(
        (
            s2.globals.get("warpfrommap").copied(),
            s2.globals.get("ending").copied()
        ),
        (Some(0.0), Some(0.0)),
        "CODE {CODE}: the preamble runs before the gate, so it clears on both paths"
    );
    assert_eq!(
        s2.instances
            .values()
            .filter(|i| i.object == INTRO_OBJECT)
            .count(),
        1,
        "CODE {CODE}: the epilogue runs after the join on both paths"
    );
}
