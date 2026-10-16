//! wl40-world: id-level behavioural bodies for the world / UI / outro family.
//!
//! These bodies sat in the census' `object_cited_contract` tier: the object
//! name was cited by some contract but no id-level test named the CODE, so no
//! per-body behaviour was asserted. Every test here drives the real event
//! dispatch (or the real timer path through `tick`) and asserts the observable
//! original semantics recovered from the GML and pinned in the bytecode IR.
//!
//! Fixture conventions follow enemy_ladders_ii_ir / mines_slime_ir: raw values
//! through direct dispatch, self-firing timers run for real, and the app's
//! `enable_ir_gameplay` sprite wiring (bounds + recorded bbox + masks) so the
//! shared box source used by `instance_place` reads real geometry.
//!
//! Families covered: obj_house (2) porch poll ladder, obj_endmusic (163)
//! credits ladder, obj_final (161) / obj_tease (162) panel reveals, obj_logo
//! (135), obj_finalchest (101), obj_lloyd (154) destroy, the three
//! obj_lloydtutorial sheets whose alarm bodies and one Draw were unnamed, and
//! obj_lloydtutorial13's Draw layout.
//!
//! Scope: these are re-written-end IR regressions, not an equivalence proof
//! against the original runner.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const HOUSE: i32 = 2;
const FINALCHEST: i32 = 101;
const LOGO: i32 = 135;
const SHEET1: i32 = 138;
const SHEET2: i32 = 139;
const SHEET13: i32 = 150;
const LLOYD: i32 = 154;
const FINAL: i32 = 161;
const TEASE: i32 = 162;
const ENDMUSIC: i32 = 163;

/// Sprite ids from assets/json/sprites.json (names the recovered GML uses).
const SPR_LLOYD: i32 = 1;
const SPR_PLAYER: i32 = 29;
const SPR_PAUSE: i32 = 123;

// Batch 2 ids, all read off the bytecode IR (object definitions / constants).
const WALL: i32 = 4;
const WALL2: i32 = 5;
const BOULDER: i32 = 6;
const WATER: i32 = 9;
const BG: i32 = 65;
const MUTING: i32 = 67;
const MUSIC: i32 = 68;
const VOLUME: i32 = 107;
const BACKTOGAME: i32 = 108;
const VOLUMEMUSIC: i32 = 109;
const STORE: i32 = 110;
const MAPMENU: i32 = 111;
const RESTOREDATA: i32 = 115;
const FIRSTPAUSE: i32 = 118;
const PAUSE: i32 = 122;
const PAUSE2: i32 = 123;
const SHOOTBUTTON: i32 = 128;
const SWORDBUTTON: i32 = 129;
const LEFTBUTTON: i32 = 130;
const RIGHTBUTTON: i32 = 131;
const BOULDERBLOCK: i32 = 156;
const ROCKPARTS: i32 = 157;
const LINELEFT: i32 = 164;
const LINERIGHT: i32 = 165;
const SMALLPUFF: i32 = 187;
const BIGPUFF: i32 = 188;
const SPR_COIN: i32 = 88;
const SPR_PAUSEBOX: i32 = 153;
const SPR_SHOOTBUTTON: i32 = 156;
const SPR_SWORDBUTTON: i32 = 157;
const SPR_RIGHTBUTTON: i32 = 159;
/// SOND ids (reconstruction/contracts/audio-sond.json).
const SND_EXPLODE: i32 = 7;
const SND_ASSAULTRIFLE: i32 = 9;
/// rm_ending, the room CODE 19 hands the player to.
const RM_ENDING: usize = 110;

/// obj_house sits at (400, 300); spr_house is 288x256 with origin (0, 0), so a
/// player parked at (+50, +50) is inside the porch box and one at (+1000,
/// +1000) is far outside it.
const PORCH: (f64, f64) = (450.0, 350.0);
const AWAY: (f64, f64) = (1400.0, 1300.0);

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).expect("game.droid");
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json"))
        .expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

/// The app's SPRT wiring: bounds + recorded bbox + collision masks.
fn fresh(asset: &GameDroidAsset, b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
        if let Some(bbox) = sp.bbox {
            s.sprite_bboxes.insert(*sid as i32, bbox);
        }
        if !sp.masks.is_empty() {
            s.sprite_masks.insert(*sid as i32, sp.masks.clone());
        }
    }
    for v in 0..8 {
        s.view_positions.insert(v, (0.0, 0.0));
    }
    s
}

// ---- obj_house --------------------------------------------------------------

struct House {
    s: Scene,
    house: i32,
    player: i32,
}

fn pin_player(s: &mut Scene, p: i32, at: (f64, f64)) {
    for (n, v) in [
        ("x", at.0),
        ("y", at.1),
        ("hspeed", 0.0),
        ("vspeed", 0.0),
        ("gravity", 0.0),
        ("invulnerable", 1.0),
    ] {
        s.write(p, -1, n, None, v).unwrap();
    }
}

fn house_scene(asset: &GameDroidAsset, b: &Bundle, player_at: (f64, f64)) -> House {
    let mut s = fresh(asset, b);
    let house = s.create(b, HOUSE, 400.0, 300.0).expect("obj_house");
    let player = s.create(b, PLAYER, player_at.0, player_at.1).expect("player");
    pin_player(&mut s, player, player_at);
    House { s, house, player }
}

/// The four-step house ladder: each Alarm_k body arms the next slot only while
/// the player still stands on the porch, otherwise it re-arms the 30-tick poll.
/// (Alarm_0 .. Alarm_5; the Alarm_6 payout body is outside this batch.)
const HOUSE_LADDER: [(i32, usize, usize); 6] = [
    // CODE 27
    (27, 0, 1),
    // CODE 26
    (26, 1, 2),
    // CODE 25
    (25, 2, 3),
    // CODE 24
    (24, 3, 4),
    // CODE 23
    (23, 4, 5),
    // CODE 22
    (22, 5, 6),
];

#[test]
fn house_create_arms_its_type_and_the_poll_alarm() {
    let (asset, b) = game();
    let mut s = fresh(&asset, &b);
    // CODE 20: type = 1; alarm[0] = 30.
    let h = s.create(&b, HOUSE, 400.0, 300.0).expect("obj_house");
    assert_eq!(s.instances[&h].fields["type"], 1.0, "CODE 20 writes type = 1");
    assert_eq!(s.instances[&h].alarms[0], 30, "CODE 20 arms the 30-tick porch poll");
    assert_eq!(s.instances[&h].alarms[6], -1, "the payout slot stays unarmed at create");
    // The alarm[0] slot really fires on the 30th tick of the real schedule, and
    // with nobody on the porch CODE 27's else branch re-arms it instead of
    // handing the ladder on.
    for _ in 0..29 {
        s.tick(&b).unwrap();
    }
    assert_eq!(s.instances[&h].alarms[0], 1, "29 ticks in: one tick left");
    s.tick(&b).unwrap();
    assert_eq!(s.instances[&h].alarms[0], 30, "CODE 27 re-arms the poll from an empty porch");
    assert_eq!(s.instances[&h].alarms[1], -1, "and the ladder does not start");
}

#[test]
fn house_ladder_arms_the_next_slot_only_while_the_player_stands_on_the_porch() {
    let (asset, b) = game();
    for (code, slot, next) in HOUSE_LADDER {
        // Porch: the body hands the ladder on (alarm[next] = 600).
        let mut on = house_scene(&asset, &b, PORCH);
        let hit = on.s.call(&b, on.house, "instance_place", &[400.0, 300.0, PLAYER as f64]).unwrap();
        assert_eq!(hit, on.player as f64, "fixture: the porch player overlaps the house box");
        on.s.dispatch(&b, on.house, 2, slot as i32).expect("house alarm");
        assert_eq!(on.s.instances[&on.house].alarms[next], 600,
            "CODE {code} arms alarm[{next}] = 600 on the porch");
        assert_eq!(on.s.instances[&on.house].alarms[0], 30,
            "CODE {code} leaves the porch poll for the next tick");

        // Away: the body drops out of the ladder and restarts the poll.
        let mut off = house_scene(&asset, &b, AWAY);
        let miss = off.s.call(&b, off.house, "instance_place", &[400.0, 300.0, PLAYER as f64]).unwrap();
        assert!(miss < 0.0, "fixture: the far player misses the house box");
        off.s.dispatch(&b, off.house, 2, slot as i32).expect("house alarm");
        assert_eq!(off.s.instances[&off.house].alarms[next], -1,
            "CODE {code} refuses to advance while the player is away");
        assert_eq!(off.s.instances[&off.house].alarms[0], 30,
            "CODE {code} re-arms the 30-tick poll instead");
    }
}

#[test]
fn house_ladder_climbs_on_its_own_timers_from_the_porch() {
    let (asset, b) = game();
    let mut h = house_scene(&asset, &b, PORCH);
    let mut fired_at = Vec::new();
    let mut t = 0usize;
    for (_, _, next) in HOUSE_LADDER {
        let mut waited = 0usize;
        while h.s.instances[&h.house].alarms[next] == -1 && waited < 700 {
            pin_player(&mut h.s, h.player, PORCH);
            h.s.tick(&b).unwrap();
            waited += 1;
        }
        assert!(waited < 700, "alarm[{next}] was never armed by the timer path");
        t += waited;
        fired_at.push(t);
        assert_eq!(h.s.instances[&h.house].alarms[next - 1], -1,
            "slot {} is consumed when it fires", next - 1);
    }
    // Measured frames on this host (the arming tick also decrements the new
    // slot once, in slot order, so every hop after the first is 599 ticks):
    // CODE 27 fires at 30, then CODE 26/25/24/23/22 each 599 ticks later.
    assert_eq!(fired_at, vec![30, 629, 1228, 1827, 2426, 3025],
        "house ladder frames");
}

#[test]
fn house_ladder_falls_back_to_the_poll_when_the_player_leaves_mid_chain() {
    let (asset, b) = game();
    let mut h = house_scene(&asset, &b, PORCH);
    // Walk to the first rung: CODE 27 fires at tick 30 and arms alarm[1] = 600.
    for _ in 0..30 {
        pin_player(&mut h.s, h.player, PORCH);
        h.s.tick(&b).unwrap();
    }
    assert!(h.s.instances[&h.house].alarms[1] > 0, "the ladder left the porch poll");
    // Leave before the 600 ticks elapse.
    let mut waited = 0usize;
    while h.s.instances[&h.house].alarms[1] != -1 && waited < 700 {
        pin_player(&mut h.s, h.player, AWAY);
        h.s.tick(&b).unwrap();
        waited += 1;
    }
    assert_eq!(h.s.instances[&h.house].alarms[1], -1, "CODE 26 fired once the player had left");
    assert_eq!(h.s.instances[&h.house].alarms[0], 30,
        "CODE 26's else branch restarts the 30-tick poll");
    assert_eq!(h.s.instances[&h.house].alarms[2], -1,
        "the chain stops: no rung is armed from an empty porch");
}

// ---- obj_endmusic -----------------------------------------------------------

/// (CODE, alarm slot, drawn row, previous row cleared) from CODE 704's ladder.
const CREDIT_BODIES: [(i32, i32, &str, &str); 6] = [
    // CODE 706
    (706, 9, "drawcredit10", "drawcredit9"),
    // CODE 707
    (707, 8, "drawcredit9", "drawcredit8"),
    // CODE 708
    (708, 7, "drawcredit8", "drawcredit7"),
    // CODE 709
    (709, 6, "drawcredit7", "drawcredit6"),
    // CODE 710
    (710, 5, "drawcredit6", "drawcredit5"),
    // CODE 711
    (711, 4, "drawcredit5", "drawcredit4"),
];

fn endmusic(asset: &GameDroidAsset, b: &Bundle) -> (Scene, i32) {
    let mut s = fresh(asset, b);
    let e = s.create(b, ENDMUSIC, 0.0, 0.0).expect("obj_endmusic");
    (s, e)
}

#[test]
fn endmusic_credit_bodies_advance_exactly_one_row() {
    let (asset, b) = game();
    for (code, slot, on, off) in CREDIT_BODIES {
        let (mut s, e) = endmusic(&asset, &b);
        // Opposite sentinels, so both writes of the body are observed.
        s.write(e, -1, on, None, 0.0).unwrap();
        s.write(e, -1, off, None, 1.0).unwrap();
        let others: Vec<f64> = (1..=10)
            .map(|i| s.instances[&e].fields[&format!("drawcredit{i}")])
            .collect();
        s.dispatch(&b, e, 2, slot).expect("credits alarm");
        assert_eq!(s.instances[&e].fields[on], 1.0, "CODE {code} raises {on}");
        assert_eq!(s.instances[&e].fields[off], 0.0, "CODE {code} clears {off}");
        let after: Vec<f64> = (1..=10)
            .map(|i| s.instances[&e].fields[&format!("drawcredit{i}")])
            .collect();
        for (i, (before, now)) in others.iter().zip(after.iter()).enumerate() {
            let name = format!("drawcredit{}", i + 1);
            if name != on && name != off {
                assert_eq!(before, now, "CODE {code} leaves {name} alone");
            }
        }
    }
}

#[test]
fn endmusic_credit_ladder_runs_on_its_own_alarms() {
    let (asset, b) = game();
    let (mut s, e) = endmusic(&asset, &b);
    // CODE 704 arms alarm[7] = 2200, alarm[8] = 2400, alarm[9] = 2800 and the
    // alarm[11] = 2660 handoff to obj_final, all at create.
    assert_eq!(s.instances[&e].alarms[8], 2400, "the credits clock is armed at create");
    assert_eq!(s.instances[&e].alarms[9], 2800, "CODE 706's slot is armed at create");
    while s.tick_count < 2200 {
        s.tick(&b).unwrap();
    }
    // CODE 708: drawcredit8 = 1; drawcredit7 = 0.
    assert_eq!(s.instances[&e].fields["drawcredit8"], 1.0, "CODE 708 at tick 2200");
    while s.tick_count < 2400 {
        s.tick(&b).unwrap();
    }
    // CODE 707: drawcredit9 = 1; drawcredit8 = 0 (the row above goes dark).
    assert_eq!(s.instances[&e].fields["drawcredit9"], 1.0, "CODE 707 at tick 2400");
    assert_eq!(s.instances[&e].fields["drawcredit8"], 0.0, "CODE 707 clears the previous row");
    // The natural run hands off to the final screen at 2660, and that screen's
    // own Create deactivates the world — so the credits object stops ticking
    // and its own alarm[9] (CODE 706) never gets the chance to fire.
    while s.tick_count < 2660 {
        s.tick(&b).unwrap();
    }
    assert!(!s.instances[&e].active, "the 2660 handoff parks the credits screen");
    while s.tick_count < 2800 {
        s.tick(&b).unwrap();
    }
    assert_eq!(s.instances[&e].fields["drawcredit10"], 0.0,
        "a parked credits screen never reaches CODE 706's tick");
}

#[test]
fn endmusic_last_credit_row_fires_on_its_own_clock_in_isolation() {
    let (asset, b) = game();
    let (mut s, e) = endmusic(&asset, &b);
    // Park every sibling slot so CODE 706's own 2800-tick clock is the only one
    // left running (the 2660 handoff would otherwise preempt it, see above).
    for slot in 0..12 {
        if slot != 9 {
            s.instances.get_mut(&e).unwrap().alarms[slot] = -1;
        }
    }
    s.write(e, -1, "drawcredit9", None, 1.0).unwrap();
    while s.tick_count < 2799 {
        s.tick(&b).unwrap();
    }
    assert_eq!(s.instances[&e].fields["drawcredit10"], 0.0, "one tick early: row 10 is dark");
    s.tick(&b).unwrap();
    // CODE 706: drawcredit10 = 1; drawcredit9 = 0.
    assert_eq!(s.instances[&e].fields["drawcredit10"], 1.0, "CODE 706 fires at tick 2800");
    assert_eq!(s.instances[&e].fields["drawcredit9"], 0.0, "CODE 706 clears the previous row");
}

// ---- obj_final / obj_tease / obj_logo ---------------------------------------

#[test]
fn final_panel_alarms_reveal_panel2_then_panel3_and_unlock_the_tap() {
    let (asset, b) = game();
    let mut s = fresh(&asset, &b);
    let f = s.create(&b, FINAL, 0.0, 0.0).expect("obj_final");
    // CODE 697 = Alarm_0 -> drawpanel2; CODE 696 = Alarm_1 -> taplock;
    // CODE 695 = Alarm_3 -> drawpanel3.
    s.dispatch(&b, f, 2, 0).expect("final A0");
    assert_eq!(s.instances[&f].fields["drawpanel2"], 1.0, "CODE 697 reveals panel 2");
    assert_eq!(s.instances[&f].fields["drawpanel3"], 0.0, "CODE 697 does not reveal panel 3");
    s.dispatch(&b, f, 2, 1).expect("final A1");
    assert_eq!(s.instances[&f].fields["taplock"], 1.0, "CODE 696 unlocks the tap");
    s.dispatch(&b, f, 2, 3).expect("final A3");
    assert_eq!(s.instances[&f].fields["drawpanel3"], 1.0, "CODE 695 reveals panel 3");

    // The same three steps on their own alarms: 100 / 300 / 300.
    let mut s2 = fresh(&asset, &b);
    let f2 = s2.create(&b, FINAL, 0.0, 0.0).expect("obj_final");
    assert_eq!(s2.instances[&f2].fields["drawpanel2"], 0.0, "panel 2 waits for alarm[0]");
    while s2.tick_count < 100 {
        s2.tick(&b).unwrap();
    }
    assert_eq!(s2.instances[&f2].fields["drawpanel2"], 1.0, "CODE 697 fires at tick 100");
    while s2.tick_count < 300 {
        s2.tick(&b).unwrap();
    }
    assert_eq!(s2.instances[&f2].fields["taplock"], 1.0, "CODE 696 fires at tick 300");
    assert_eq!(s2.instances[&f2].fields["drawpanel3"], 1.0, "CODE 695 fires at tick 300");
}

#[test]
fn tease_alarm_reveals_panel3_and_unlocks_the_tap() {
    let (asset, b) = game();
    let mut s = fresh(&asset, &b);
    let t = s.create(&b, TEASE, 0.0, 0.0).expect("obj_tease");
    assert_eq!(s.instances[&t].fields["drawpanel3"], 0.0, "panel 3 is hidden at create");
    // CODE 701 = Alarm_0.
    s.dispatch(&b, t, 2, 0).expect("tease A0");
    assert_eq!(s.instances[&t].fields["drawpanel3"], 1.0, "CODE 701 reveals panel 3");
    assert_eq!(s.instances[&t].fields["taplock"], 1.0, "CODE 701 unlocks the tap");

    // On its own alarm: CODE 700 arms alarm[0] = 600.
    let mut s2 = fresh(&asset, &b);
    let t2 = s2.create(&b, TEASE, 0.0, 0.0).expect("obj_tease");
    while s2.tick_count < 599 {
        s2.tick(&b).unwrap();
    }
    assert_eq!(s2.instances[&t2].fields["taplock"], 0.0, "still tap-locked one tick early");
    s2.tick(&b).unwrap();
    assert_eq!(s2.instances[&t2].fields["drawpanel3"], 1.0, "CODE 701 fires at tick 600");
    assert_eq!(s2.instances[&t2].fields["taplock"], 1.0, "CODE 701 fires at tick 600");
}

#[test]
fn logo_create_zeroes_its_own_alpha() {
    let (asset, b) = game();
    let mut s = fresh(&asset, &b);
    // CODE 545: logoalpha = 0 — the field must exist after Create, not merely
    // read back as the VM's default zero for an unknown name.
    let l = s.create(&b, LOGO, 0.0, 0.0).expect("obj_logo");
    assert!(s.instances[&l].fields.contains_key("logoalpha"),
        "CODE 545 writes logoalpha (the name is absent before Create)");
    assert_eq!(s.instances[&l].fields["logoalpha"], 0.0, "CODE 545 writes 0");
}

// ---- obj_finalchest / obj_lloyd ---------------------------------------------

#[test]
fn finalchest_create_rolls_one_of_exactly_four_contents() {
    let (asset, b) = game();
    // CODE 452: chestcontents = choose(1, 2, 3, 4); touched = 0.
    let mut tiers = std::collections::BTreeSet::new();
    for seed in 0..64u64 {
        let mut s = fresh(&asset, &b);
        s.rng_seed = s.rng_seed.wrapping_add(seed.wrapping_mul(0x9e3779b97f4a7c15));
        let c = s.create(&b, FINALCHEST, 0.0, 0.0).expect("obj_finalchest");
        let contents = s.instances[&c].fields["chestcontents"];
        assert!(contents.fract() == 0.0 && (1.0..=4.0).contains(&contents),
            "CODE 452 rolls one of 1..=4, got {contents}");
        assert_eq!(s.instances[&c].fields["touched"], 0.0, "CODE 452 starts untouched");
        tiers.insert(contents as i64);
    }
    assert!(tiers.len() >= 2,
        "CODE 452's choose is RNG-driven, not a constant: {tiers:?}");
}

#[test]
fn finalchest_step_keeps_the_chest_planted() {
    let (asset, b) = game();
    let mut s = fresh(&asset, &b);
    let c = s.create(&b, FINALCHEST, 0.0, 0.0).expect("obj_finalchest");
    s.write(c, -1, "vspeed", None, 7.0).unwrap();
    s.write(c, -1, "hspeed", None, -3.0).unwrap();
    // CODE 453: vspeed = 0; hspeed = 0.
    s.dispatch(&b, c, 3, 0).expect("finalchest Step");
    assert_eq!(s.instances[&c].fields["vspeed"], 0.0, "CODE 453 pins the vertical speed");
    assert_eq!(s.instances[&c].fields["hspeed"], 0.0, "CODE 453 pins the horizontal speed");
}

#[test]
fn lloyd_destroy_clears_every_touch_device() {
    let (asset, b) = game();
    let mut s = fresh(&asset, &b);
    let l = s.create(&b, LLOYD, 100.0, 100.0).expect("obj_lloyd");
    for d in s.touch_devices.iter_mut() {
        d.down = true;
        d.pressed = true;
        d.released = true;
    }
    // CODE 671: mouse_clear(mb_any).
    s.destroy(&b, l).expect("obj_lloyd destroy");
    assert!(!s.instances[&l].alive, "CODE 671 runs on a destroyed instance");
    assert!(s.touch_devices.iter().all(|d| !d.down && !d.pressed && !d.released),
        "CODE 671 mouse_clear(mb_any) clears all five devices");
}

// ---- obj_lloydtutorial1 / 2 / 13 --------------------------------------------

/// Panel pair bodies: (object, CODE, alarm slot, flag set to 0, flag set to 1).
const PANEL_BODIES: [(i32, i32, i32, usize, usize); 11] = [
    // CODE 563
    (SHEET1, 563, 0, 1, 2),
    // CODE 562
    (SHEET1, 562, 1, 2, 3),
    // CODE 561
    (SHEET1, 561, 2, 3, 4),
    // CODE 560
    (SHEET1, 560, 3, 4, 5),
    // CODE 559
    (SHEET1, 559, 4, 5, 6),
    // CODE 569
    (SHEET2, 569, 0, 1, 2),
    // CODE 568
    (SHEET2, 568, 1, 2, 3),
    // CODE 648
    (SHEET13, 648, 0, 1, 2),
    // CODE 647
    (SHEET13, 647, 1, 2, 3),
    // CODE 646
    (SHEET13, 646, 2, 3, 4),
    // CODE 645
    (SHEET13, 645, 3, 4, 5),
];

/// Tap-unlock bodies: (object, CODE, alarm slot) — CODE 567 / CODE 644.
const UNLOCK_BODIES: [(i32, i32, i32); 2] = [
    // CODE 567
    (SHEET2, 567, 5),
    // CODE 644
    (SHEET13, 644, 5),
];

/// [drawpanel1..6, taplock] with every flag parked on an impossible sentinel,
/// so a body that writes anything else is caught instead of masked.
fn seed_panels(s: &mut Scene, id: i32) {
    for p in 1..=6 {
        s.write(id, -1, &format!("drawpanel{p}"), None, 7.0).unwrap();
    }
    s.write(id, -1, "taplock", None, 7.0).unwrap();
}

fn flags(s: &Scene, id: i32) -> Vec<f64> {
    let f = &s.instances[&id].fields;
    (1..=6)
        .map(|p| f[&format!("drawpanel{p}")])
        .chain(std::iter::once(f["taplock"]))
        .collect()
}

#[test]
fn tutorial_panel_bodies_write_exactly_their_two_flags() {
    let (asset, b) = game();
    for (object, code, slot, off, on) in PANEL_BODIES {
        let mut s = fresh(&asset, &b);
        let sheet = s.create(&b, object, 200.0, 200.0).expect("tutorial sheet");
        seed_panels(&mut s, sheet);
        s.dispatch(&b, sheet, 2, slot).expect("panel alarm");
        let got = flags(&s, sheet);
        assert_eq!(got[off - 1], 0.0, "CODE {code} clears drawpanel{off}");
        assert_eq!(got[on - 1], 1.0, "CODE {code} raises drawpanel{on}");
        for p in 1..=6 {
            if p != off && p != on {
                assert_eq!(got[p - 1], 7.0, "CODE {code} leaves drawpanel{p} untouched");
            }
        }
        assert_eq!(got[6], 7.0, "CODE {code} leaves taplock alone");
    }
}

#[test]
fn tutorial_unlock_bodies_only_unlock_the_tap() {
    let (asset, b) = game();
    for (object, code, slot) in UNLOCK_BODIES {
        let mut s = fresh(&asset, &b);
        let sheet = s.create(&b, object, 200.0, 200.0).expect("tutorial sheet");
        seed_panels(&mut s, sheet);
        s.dispatch(&b, sheet, 2, slot).expect("unlock alarm");
        let got = flags(&s, sheet);
        assert_eq!(got[6], 1.0, "CODE {code} unlocks the tap");
        for p in 1..=6 {
            assert_eq!(got[p - 1], 7.0, "CODE {code} leaves drawpanel{p} untouched");
        }
    }
}

#[test]
fn tutorial_panel_ladders_climb_on_their_own_alarms() {
    let (asset, b) = game();
    // (object, Create's alarm ladder, per-checkpoint (tick, CODE, [0-flag, 1-flag] | unlock))
    struct Step {
        at: usize,
        code: i32,
        write: Option<(usize, usize)>,
    }
    let ladders: [(i32, Vec<Step>); 3] = [
        // CODE 563, CODE 562, CODE 561, CODE 560, CODE 559 on sheet 1.
        (SHEET1, vec![
            Step { at: 100, code: 563, write: Some((1, 2)) },
            Step { at: 200, code: 562, write: Some((2, 3)) },
            Step { at: 300, code: 561, write: Some((3, 4)) },
            Step { at: 400, code: 560, write: Some((4, 5)) },
            Step { at: 500, code: 559, write: Some((5, 6)) },
        ]),
        // CODE 569, CODE 568, CODE 567 on sheet 2.
        (SHEET2, vec![
            Step { at: 100, code: 569, write: Some((1, 2)) },
            Step { at: 200, code: 568, write: Some((2, 3)) },
            Step { at: 300, code: 567, write: None },
        ]),
        // CODE 648, CODE 647, CODE 646, CODE 645, CODE 644 on sheet 13.
        (SHEET13, vec![
            Step { at: 100, code: 648, write: Some((1, 2)) },
            Step { at: 200, code: 647, write: Some((2, 3)) },
            Step { at: 300, code: 646, write: Some((3, 4)) },
            Step { at: 400, code: 645, write: Some((4, 5)) },
            Step { at: 500, code: 644, write: None },
        ]),
    ];
    for (object, steps) in ladders {
        let mut s = fresh(&asset, &b);
        let sheet = s.create(&b, object, 200.0, 200.0).expect("tutorial sheet");
        for step in &steps {
            while s.tick_count < step.at as u64 {
                s.tick(&b).unwrap();
            }
            let got = flags(&s, sheet);
            match step.write {
                Some((off, on)) => {
                    assert_eq!(got[off - 1], 0.0,
                        "sheet {object}: CODE {} clears drawpanel{off} at tick {}", step.code, step.at);
                    assert_eq!(got[on - 1], 1.0,
                        "sheet {object}: CODE {} raises drawpanel{on} at tick {}", step.code, step.at);
                }
                None => {
                    assert_eq!(got[6], 1.0,
                        "sheet {object}: CODE {} unlocks the tap at tick {}", step.code, step.at);
                }
            }
        }
    }
}

#[test]
fn lloydtutorial13_draw_lays_out_view_zero_and_the_tap_gate() {
    let (asset, b) = game();
    let (vx, vy) = (123.0, 456.0);
    // CODE 649: x/y snap to view_xview[view_current] / view_yview[view_current],
    // then spr_pause (123) + spr_lloyd at +50 and mirrored spr_player at +380.
    let mut s = fresh(&asset, &b);
    s.view_positions.insert(0, (vx, vy));
    let sheet = s.create(&b, SHEET13, 700.0, 500.0).expect("sheet 13");
    assert_eq!(s.instances[&sheet].fields["x"], 700.0, "Create leaves x alone");
    s.draw_view(&b, 0).expect("sheet 13 draw");
    assert_eq!(s.instances[&sheet].fields["x"], vx, "CODE 649 snaps x to the view");
    assert_eq!(s.instances[&sheet].fields["y"], vy, "CODE 649 snaps y to the view");
    let backdrop = s.draws.iter()
        .find(|d| d.sprite == SPR_PAUSE && d.instance == sheet)
        .expect("CODE 649 draws the spr_pause backdrop");
    assert_eq!((backdrop.x, backdrop.y), (vx - 1.0, vy), "backdrop at view - (1, 0)");
    assert_eq!((backdrop.scale_x, backdrop.scale_y), (0.96, 0.8), "view 0 backdrop scale");
    assert_eq!(backdrop.frame, 1.0, "backdrop frame 1");
    let lloyd = s.draws.iter()
        .find(|d| d.sprite == SPR_LLOYD && d.instance == sheet)
        .expect("CODE 649 draws Lloyd");
    assert_eq!((lloyd.x, lloyd.y), (vx + 50.0, vy + 50.0));
    assert_eq!((lloyd.scale_x, lloyd.scale_y), (2.0, 2.0));
    let player = s.draws.iter()
        .find(|d| d.sprite == SPR_PLAYER && d.instance == sheet)
        .expect("CODE 649 draws the mirrored player portrait");
    assert_eq!((player.x, player.y), (vx + 380.0, vy + 180.0));
    assert_eq!((player.scale_x, player.scale_y), (-2.0, 2.0), "mirrored portrait");
    assert!(!s.texts.iter().any(|t| t.text == "Tap to Continue"),
        "CODE 649 only shows the tap prompt once taplock == 1");

    // taplock == 1 adds "Tap to Continue" at view + (150, 200) ...
    let mut s2 = fresh(&asset, &b);
    s2.view_positions.insert(0, (vx, vy));
    let sheet2 = s2.create(&b, SHEET13, 700.0, 500.0).expect("sheet 13");
    s2.write(sheet2, -1, "taplock", None, 1.0).unwrap();
    s2.draw_view(&b, 0).expect("sheet 13 draw");
    assert!(s2.texts.iter().any(|t| t.text == "Tap to Continue" && (t.x, t.y) == (vx + 150.0, vy + 200.0)),
        "CODE 649 draws the tap prompt at view + (150, 200) when taplock == 1: {:?}",
        s2.texts.iter().map(|t| (&t.text, t.x, t.y)).collect::<Vec<_>>());

    // ... and a released touch at that point destroys the sheet.
    s2.touch_devices[0].released = true;
    s2.draw_view(&b, 0).expect("sheet 13 draw with a released tap");
    assert!(!s2.instances[&sheet2].alive, "CODE 649's tap gate dismisses the sheet");
}

// ---- obj_firstpause (118) --------------------------------------------------

/// The 44 Lloyd's Tip rows, each with the seed that makes CODE 494's
/// `irandom_range(1, 44)` land on that row. The VM's single LCG advance is
/// `seed = seed*6364136223846793005 + 1442695040888963407`, so the seeds below
/// were solved from that relation and the row text is transcribed from the
/// recovered GML (CODE 494).
const TIPS: [(u64, i32, &str, &str); 44] = [
    (23, 1, "The Reduce Enemy HP upgrade", "is great for lowering the overall difficulty"),
    (81, 2, "Unlock the crescent wave for", "explosive power with every sword swing!"),
    (26, 3, "The first chance to dodge upgrade", "gives you a 1 in 4 chance to avoid attacks!"),
    (0, 4, "Avoid water and spikes", "at all cost!"),
    (3, 5, "The Ice Pistol doesn't freeze Skeletons,", "but works great on Bats!"),
    (32, 6, "The Heavy Bandit's Rocket Launcher", "deals devastating damage."),
    (6, 7, "Zombies will mindlessly follow you,", "even off the edge of a cliff!"),
    (93, 8, "The Coin Multiplier upgrades are the", "best bang for your buck."),
    (9, 9, "Try using your sword attack", "on Spiders, Bats, and Bees."),
    (12, 10, "XP Orbs drop from every enemy,", "gather enough and you will level up!"),
    (70, 11, "Levelling up increases your maximum HP.", "You can also buy 2 level ups from the store."),
    (15, 12, "Be careful near the edges of platforms.", "Enemies will follow you off them!"),
    (18, 13, "Hebert's experiments have", "turned the animals evil..."),
    (76, 14, "You lose coins when you are defeated,", "and you will have to start the level over."),
    (21, 15, "Deflect Projectiles using your", "Sword attack!  Timing is key..."),
    (24, 16, "Herbert was once a close", "friend of your parents..."),
    (82, 17, "The Boomerang is slow, but powerful.", "It has no effect on bosses."),
    (27, 18, "The Bow and Arrow's arc makes it ideal", "for shooting enemies that are lower than you."),
    (1, 19, "Health Regeneration replenishes a heart", "every ten seconds..."),
    (59, 20, "Poison bullets, Gem drops, and remove ads", "are available in the in app purchase menu."),
    (4, 21, "Like the music and want to support the", "Developers? Go to callyscaves.bandcamp.com"),
    (7, 22, "The Bomb Gun causes chaos and confusion.", "It makes enemies fly all over the place!"),
    (65, 23, "The Spikes from the Spike Gun", "will destroy enemy projectiles."),
    (10, 24, "Bees follow you, but aren't very smart.", "See if you can get them stuck on the walls!"),
    (13, 25, "The Flamethrower shoots through walls,", "making it ideal for fighting tougher enemies."),
    (42, 26, "Use your sword attack to keep yourself", "protected, but watch out for wolves."),
    (16, 27, "Buy the Coin Multiplier x2 first.", " "),
    (19, 28, "The Chance to Dodge 2 upgrade gives", "you a 50/50 chance at dodging each attack."),
    (48, 29, "Sometimes a Heavy Bandit will self-destruct", "just to take you out!"),
    (22, 30, "A minor is my favorite guitar chord.", ""),
    (25, 31, "Keep well clear of the Heavy Bandit.", ""),
    (54, 32, "The boomerang is weak and slow, but it", "can hit enemies many times on its way back!"),
    (28, 33, "There are 3 flowers in a vase...", "The third flower is green."),
    (2, 34, "Buy sword upgrades to increase its power", "and upgrade its appearance!"),
    (31, 35, "The Balor's Fireball takes off", "3 hearts if it hits you."),
    (5, 36, "The Rocket Launcher can push some", "enemies off ledges."),
    (8, 37, "Weapons are usually weak when you find them.", "But they are powerful when levelled up!"),
    (37, 38, "You will probably get defeated many times...", "The Caves are pretty tough!"),
    (11, 39, "You can buy consumable health refills at", "the store, but they aren't cheap!"),
    (14, 40, "Please don't like us on Facebook.", "That's just weird..."),
    (43, 41, "Thank you for playing Cally's Caves 2.", "I hope you have some fun!"),
    (17, 42, "Some of the animals have been", "turned into animatronics."),
    (104, 43, "The Bomb Gun doesn't seem to", "work on bosses."),
    (20, 44, "Check out Cally's Caves 3", "as well!"),
];

/// Pause/menu screens run with the world parked and their own globals.
fn ui_scene(asset: &GameDroidAsset, b: &Bundle) -> Scene {
    let mut s = fresh(asset, b);
    for (n, v) in [
        ("musicmute", 0.0),
        ("soundmute", 0.0),
        ("timespaused", 0.0),
        ("assaultrifle", 0.0),
        ("roomstart", 0.0),
    ] {
        s.globals.insert(n.into(), v);
    }
    s
}

/// CODE 494's `irandom_range(1, 44)` picks one of the 44 tip rows, and the row
/// it picks is the one the pause screen draws (observed through CODE 497's
/// "Lloyd's Tip:" lines, the game's own display path).
#[test]
fn firstpause_create_picks_one_of_the_44_lloyd_tips() {
    let (asset, b) = game();
    for (seed, tip, line1, line2) in TIPS {
        let mut s = ui_scene(&asset, &b);
        s.rng_seed = seed;
        let fp = s.create(&b, FIRSTPAUSE, 0.0, 0.0).expect("obj_firstpause");
        assert_eq!(s.instances[&fp].fields["lloydtips"], tip as f64,
            "CODE 494 draws tip {tip} from seed {seed}");
        s.draw_view(&b, 0).expect("first pause draw");
        for (want, y) in [(line1, 150.0), (line2, 165.0)] {
            assert!(s.texts.iter().any(|t| t.text == want && (t.x, t.y) == (90.0, y)),
                "tip {tip}: CODE 494's row line '{want}' must be drawn at (90, {y}), got {:?}",
                s.texts.iter().map(|t| (&t.text, t.x, t.y)).collect::<Vec<_>>());
        }
    }
}

/// CODE 494's view-0 branch: park the world, spawn the pause column, reactivate
/// the controls, and gate the music on global.musicmute.
#[test]
fn firstpause_create_builds_the_view_zero_pause_column() {
    let (asset, b) = game();
    let (vx, vy) = (200.0, 100.0);
    let mut s = ui_scene(&asset, &b);
    s.view_positions.insert(0, (vx, vy));
    // A room-resident control and a world prop, both of which CODE 494 must
    // deactivate, plus the muting toggle it must bring back.
    let muting = s.create(&b, MUTING, 700.0, 700.0).expect("obj_muting");
    let bystander = s.create(&b, WALL, 800.0, 700.0).expect("bystander wall");
    let music = s.call_audio_play(55.0, 0.0, false);
    assert!(s.audio_is_playing_sound(55.0));
    let fp = s.create(&b, FIRSTPAUSE, 0.0, 0.0).expect("obj_firstpause");

    // The six menu children, at their GML offsets (CODE 494).
    let want = [
        (VOLUME, vx + 100.0, vy + 60.0),
        (VOLUMEMUSIC, vx + 100.0, vy + 100.0),
        (STORE, vx + 240.0, vy + 60.0),
        (MAPMENU, vx + 240.0, vy + 100.0),
        (BACKTOGAME, vx + 290.0, vy + 190.0),
        (RESTOREDATA, vx + 50.0, vy + 190.0),
    ];
    for (object, x, y) in want {
        let hit = s.instances.values().any(|i| i.alive && i.object == object
            && i.fields["x"] == x && i.fields["y"] == y);
        assert!(hit, "CODE 494 spawns object {object} at ({x}, {y})");
    }
    assert!(!s.instances[&bystander].active, "CODE 494 parks the world");
    assert!(s.instances[&fp].active, "the pause screen itself keeps running");
    assert!(s.instances[&muting].active,
        "CODE 494 re-activates obj_muting after the deactivate_all");
    for object in [VOLUME, VOLUMEMUSIC, STORE, MAPMENU, BACKTOGAME, RESTOREDATA] {
        assert!(s.instances.values().any(|i| i.alive && i.object == object && i.active),
            "CODE 494 activates the spawned object {object}");
    }
    // Music gate: musicmute == 0 -> audio_stop_all then a looping theme.
    assert!(!s.audio_is_playing_sound(55.0), "CODE 494 stops the running music");
    assert!(s.take_stop_commands().contains(&55.0), "and hands the stop to the host");
    let played = s.audio.last().expect("theme command");
    assert!(matches!(played.sound, 40 | 42 | 43),
        "CODE 494's choose(42, 40, 43) theme, got {}", played.sound);
    assert!(played.looping, "the pause theme loops");
    let _ = music;

    // musicmute == 1 silences the whole gate.
    let mut s2 = ui_scene(&asset, &b);
    s2.globals.insert("musicmute".into(), 1.0);
    s2.view_positions.insert(0, (vx, vy));
    s2.call_audio_play(55.0, 0.0, false);
    s2.create(&b, FIRSTPAUSE, 0.0, 0.0).expect("obj_firstpause");
    assert!(s2.audio_is_playing_sound(55.0), "musicmute 1 leaves the music alone");
    assert!(!s2.audio.iter().any(|c| matches!(c.sound, 40 | 42 | 43)),
        "musicmute 1 cues no pause theme");

    // global.timespaused: the rating prompt at 5 is a platform stub, and 20
    // rolls the counter back to zero.
    let mut s3 = ui_scene(&asset, &b);
    s3.view_positions.insert(0, (vx, vy));
    s3.globals.insert("timespaused".into(), 5.0);
    s3.create(&b, FIRSTPAUSE, 0.0, 0.0).expect("obj_firstpause");
    assert_eq!(s3.globals["timespaused"], 5.0, "the rating prompt leaves the counter");
    let mut s4 = ui_scene(&asset, &b);
    s4.view_positions.insert(0, (vx, vy));
    s4.globals.insert("timespaused".into(), 20.0);
    s4.create(&b, FIRSTPAUSE, 0.0, 0.0).expect("obj_firstpause");
    assert_eq!(s4.globals["timespaused"], 0.0, "CODE 494 rolls the pause counter back at 20");
}

#[test]
fn firstpause_and_pause_alarm_zero_destroy_their_own_screen() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    s.view_positions.insert(0, (0.0, 0.0));
    let fp = s.create(&b, FIRSTPAUSE, 0.0, 0.0).expect("obj_firstpause");
    // CODE 496: instance_destroy().
    s.dispatch(&b, fp, 2, 0).expect("firstpause A0");
    assert!(!s.instances[&fp].alive, "CODE 496 dismisses the first-pause screen");

    let mut s2 = ui_scene(&asset, &b);
    let p = s2.create(&b, PAUSE, 0.0, 0.0).expect("obj_pause");
    // CODE 509: instance_destroy(), also reached through its own alarm slot.
    s2.dispatch(&b, p, 2, 0).expect("pause A0");
    assert!(!s2.instances[&p].alive, "CODE 509 dismisses the pause screen");

    let mut s3 = ui_scene(&asset, &b);
    let p3 = s3.create(&b, PAUSE, 0.0, 0.0).expect("obj_pause");
    s3.write(p3, -1, "alarm", Some(0), 1.0).expect("seed the dismiss alarm");
    s3.tick(&b).unwrap();
    assert!(!s3.instances[&p3].alive, "CODE 509 runs from the real schedule");
}

#[test]
fn pause_keypress_27_arms_its_own_dismiss_alarm() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let p = s.create(&b, PAUSE, 0.0, 0.0).expect("obj_pause");
    assert!(s.instances[&p].alarms[0] == -1, "the pause screen opens without a dismiss alarm");
    // CODE 511: alarm[0] = 1.
    s.dispatch(&b, p, 9, 27).expect("pause KeyPress 27");
    assert_eq!(s.instances[&p].alarms[0], 1, "CODE 511 arms the 1-tick dismiss");
    s.tick(&b).unwrap();
    assert!(!s.instances[&p].alive, "CODE 509 then dismisses it one tick later");
}

/// CODE 514: the pause-2 backdrop, the coin icon and the score row, per view.
#[test]
fn pause2_draw_lays_out_the_backdrop_score_and_coin() {
    let (asset, b) = game();
    // (view, view origin, backdrop scale, coin offset, score offset, font)
    let cases = [
        (0, (200.0, 100.0), (0.96, 0.8), (10.0, 40.0), (20.0, 31.0)),
        (1, (300.0, 150.0), (0.82, 0.8), (140.0, 210.0), (150.0, 200.0)),
        (3, (400.0, 200.0), (1.08, 1.2), (10.0, 60.0), (20.0, 51.0)),
    ];
    for (view, (vx, vy), (sx, sy), (cx, cy), (tx, ty)) in cases {
        let mut s = ui_scene(&asset, &b);
        s.view_positions.insert(view, (vx, vy));
        s.score = 1234.0;
        let p = s.create(&b, PAUSE2, 0.0, 0.0).expect("obj_pause2");
        s.draw_view(&b, view).expect("pause2 draw");
        let backdrop = s.draws.iter()
            .find(|d| d.sprite == SPR_PAUSE && d.instance == p)
            .unwrap_or_else(|| panic!("view {view}: spr_pause backdrop"));
        assert_eq!((backdrop.x, backdrop.y), (vx - 1.0, vy), "view {view} backdrop anchor");
        assert_eq!((backdrop.scale_x, backdrop.scale_y), (sx, sy), "view {view} backdrop scale");
        assert_eq!(backdrop.frame, 1.0, "view {view} backdrop frame");
        assert!(s.draws.iter().any(|d| d.sprite == SPR_COIN && d.instance == p
                && (d.x, d.y) == (vx + cx, vy + cy)),
            "view {view}: coin icon at view + ({cx}, {cy})");
        assert!(s.texts.iter().any(|t| t.text == "1234" && (t.x, t.y) == (vx + tx, vy + ty)),
            "view {view}: score text at view + ({tx}, {ty}), got {:?}",
            s.texts.iter().map(|t| (&t.text, t.x, t.y)).collect::<Vec<_>>());
    }
}

/// CODE 477: the Map row re-anchors itself to the active view while drawing.
#[test]
fn mapmenu_draw_writes_its_own_anchor_per_view() {
    let (asset, b) = game();
    // view 0 draws where the instance already stands; the others move it.
    let mut s = ui_scene(&asset, &b);
    s.view_positions.insert(0, (200.0, 100.0));
    let m = s.create(&b, MAPMENU, 40.0, 50.0).expect("obj_mapmenu");
    s.draw_view(&b, 0).expect("mapmenu draw");
    assert_eq!((s.instances[&m].fields["x"], s.instances[&m].fields["y"]), (40.0, 50.0),
        "view 0 keeps the instance where it was placed");
    assert!(s.draws.iter().any(|d| d.sprite == SPR_PAUSEBOX && d.instance == m
            && (d.x, d.y) == (40.0, 50.0) && (d.scale_x, d.scale_y) == (1.0, 1.0)),
        "view 0: spr_pausebox at the instance, unscaled");
    assert!(s.texts.iter().any(|t| t.text == "Map" && (t.x, t.y) == (82.0, 50.0)),
        "view 0: the Map label at x + 42");

    let mut s2 = ui_scene(&asset, &b);
    s2.view_positions.insert(1, (300.0, 150.0));
    let m2 = s2.create(&b, MAPMENU, 40.0, 50.0).expect("obj_mapmenu");
    s2.draw_view(&b, 1).expect("mapmenu draw");
    assert_eq!((s2.instances[&m2].fields["x"], s2.instances[&m2].fields["y"]), (502.0, 265.0),
        "view 1 anchors the row at view + (202, 115)");
    assert!(s2.draws.iter().any(|d| d.sprite == SPR_PAUSEBOX && d.instance == m2
            && (d.scale_x, d.scale_y) == (0.8, 0.8)),
        "view 1: spr_pausebox scaled 0.8");
    assert!(s2.texts.iter().any(|t| t.text == "Map" && (t.x, t.y) == (537.0, 265.0)),
        "view 1: the Map label at x + 35");

    let mut s3 = ui_scene(&asset, &b);
    s3.view_positions.insert(3, (400.0, 200.0));
    let m3 = s3.create(&b, MAPMENU, 40.0, 50.0).expect("obj_mapmenu");
    s3.draw_view(&b, 3).expect("mapmenu draw");
    assert_eq!((s3.instances[&m3].fields["x"], s3.instances[&m3].fields["y"]), (590.0, 385.0),
        "view 3 anchors the row at view + (190, 185)");
    assert!(s3.draws.iter().any(|d| d.sprite == SPR_PAUSEBOX && d.instance == m3
            && (d.x, d.y) == (590.0, 385.0)),
        "view 3: spr_pausebox at the re-anchored instance");
    assert!(s3.texts.iter().any(|t| t.text == "Map" && (t.x, t.y) == (635.0, 385.0)),
        "view 3: the Map label at x + 45");
}

// ---- virtual buttons --------------------------------------------------------

#[test]
fn shootbutton_alarm_two_pokes_the_player_fire_alarm() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let p = s.create(&b, PLAYER, 100.0, 100.0).expect("player");
    let sb = s.create(&b, SHOOTBUTTON, 200.0, 200.0).expect("obj_shootbutton");
    assert_eq!(s.instances[&p].alarms[0], -1, "the player opens with no fire alarm");
    // CODE 523: obj_player.alarm[0] = 1.
    s.dispatch(&b, sb, 2, 2).expect("shootbutton A2");
    assert_eq!(s.instances[&p].alarms[0], 1, "CODE 523 arms the player's fire slot");
    assert_eq!(s.instances[&sb].alarms[2], -1, "and touches nothing of its own");
}

#[test]
fn swordbutton_alarm_one_pokes_the_player_swing_alarm() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let p = s.create(&b, PLAYER, 100.0, 100.0).expect("player");
    let wb = s.create(&b, SWORDBUTTON, 200.0, 200.0).expect("obj_swordbutton");
    assert_eq!(s.instances[&p].alarms[1], -1, "the player opens with no swing alarm");
    // CODE 526: obj_player.alarm[1] = 1.
    s.dispatch(&b, wb, 2, 1).expect("swordbutton A1");
    assert_eq!(s.instances[&p].alarms[1], 1, "CODE 526 arms the player's swing slot");
}

#[test]
fn shootbutton_mouse_three_stops_the_assault_rifle_loop() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let sb = s.create(&b, SHOOTBUTTON, 200.0, 200.0).expect("obj_shootbutton");
    // Nothing playing: the body's guard leaves the host alone.
    s.dispatch(&b, sb, 6, 3).expect("shootbutton Mouse_3");
    assert!(s.take_stop_commands().is_empty(), "no rifle loop to stop yet");
    // CODE 524: audio_stop_sound(snd_assaultrifle) only while it plays.
    s.set_sound_duration(SND_ASSAULTRIFLE, 30.0);
    s.call_audio_play(SND_ASSAULTRIFLE as f64, 0.0, true);
    assert!(s.audio_is_playing_sound(SND_ASSAULTRIFLE as f64));
    s.dispatch(&b, sb, 6, 3).expect("shootbutton Mouse_3");
    assert!(!s.audio_is_playing_sound(SND_ASSAULTRIFLE as f64),
        "CODE 524 stops the assault-rifle loop on its own release");
    assert!(s.take_stop_commands().contains(&(SND_ASSAULTRIFLE as f64)),
        "and hands the stop to the host");
}

#[test]
fn shootbutton_draw_presses_into_its_fire_alarm() {
    let (asset, b) = game();
    let (vx, vy) = (200.0, 100.0);
    let mut s = ui_scene(&asset, &b);
    s.view_positions.insert(0, (vx, vy));
    let sb = s.create(&b, SHOOTBUTTON, 0.0, 0.0).expect("obj_shootbutton");
    let (bx, by) = (vx + 315.0, vy + 190.0);
    s.touch_devices[0].pressed = true;
    s.touch_devices[0].x = bx + 10.0;
    s.touch_devices[0].y = by + 10.0;
    s.draw_view(&b, 0).expect("shootbutton draw");
    assert_eq!((s.instances[&sb].fields["x"], s.instances[&sb].fields["y"]), (bx, by),
        "CODE 525 anchors the button at view + (315, 190)");
    assert_eq!(s.instances[&sb].alarms[2], 1,
        "CODE 525 arms alarm[2] when a press lands inside the button box");
    assert!(s.draws.iter().any(|d| d.sprite == SPR_SHOOTBUTTON && d.instance == sb
            && d.frame == 1.0 && d.alpha == 1.0),
        "and draws the pressed frame");
    let idle = s.draws.iter().find(|d| d.sprite == SPR_SHOOTBUTTON && d.instance == sb)
        .expect("idle button draw");
    assert_eq!(idle.alpha, 0.6, "the idle button is drawn faded");

    // No press: the alarm stays untouched.
    let mut s2 = ui_scene(&asset, &b);
    s2.view_positions.insert(0, (vx, vy));
    let sb2 = s2.create(&b, SHOOTBUTTON, 0.0, 0.0).expect("obj_shootbutton");
    s2.draw_view(&b, 0).expect("shootbutton draw");
    assert_eq!(s2.instances[&sb2].alarms[2], -1, "an idle frame never arms the fire alarm");
    assert!(!s2.draws.iter().any(|d| d.sprite == SPR_SHOOTBUTTON && d.frame == 1.0),
        "and never draws the pressed frame");

    // global.assaultrifle == 1 turns a HELD touch into the same auto-fire.
    let mut s3 = ui_scene(&asset, &b);
    s3.view_positions.insert(0, (vx, vy));
    s3.globals.insert("assaultrifle".into(), 1.0);
    let sb3 = s3.create(&b, SHOOTBUTTON, 0.0, 0.0).expect("obj_shootbutton");
    s3.touch_devices[0].down = true;
    s3.touch_devices[0].x = bx + 10.0;
    s3.touch_devices[0].y = by + 10.0;
    s3.draw_view(&b, 0).expect("shootbutton draw");
    assert_eq!(s3.instances[&sb3].alarms[2], 1,
        "CODE 525's assault-rifle branch auto-fires on a held touch");
}

#[test]
fn swordbutton_draw_presses_into_its_swing_alarm() {
    let (asset, b) = game();
    let (vx, vy) = (200.0, 100.0);
    let mut s = ui_scene(&asset, &b);
    s.view_positions.insert(0, (vx, vy));
    let wb = s.create(&b, SWORDBUTTON, 0.0, 0.0).expect("obj_swordbutton");
    let (bx, by) = (vx + 380.0, vy + 125.0);
    s.touch_devices[0].pressed = true;
    s.touch_devices[0].x = bx + 10.0;
    s.touch_devices[0].y = by + 10.0;
    s.draw_view(&b, 0).expect("swordbutton draw");
    assert_eq!((s.instances[&wb].fields["x"], s.instances[&wb].fields["y"]), (bx, by),
        "CODE 527 anchors the button at view + (380, 125)");
    assert_eq!(s.instances[&wb].alarms[1], 1,
        "CODE 527 arms alarm[1] when a press lands inside the button box");
    assert!(s.draws.iter().any(|d| d.sprite == SPR_SWORDBUTTON && d.instance == wb
            && d.frame == 1.0 && d.alpha == 1.0),
        "and draws the pressed frame");

    let mut s2 = ui_scene(&asset, &b);
    s2.view_positions.insert(0, (vx, vy));
    let wb2 = s2.create(&b, SWORDBUTTON, 0.0, 0.0).expect("obj_swordbutton");
    s2.draw_view(&b, 0).expect("swordbutton draw");
    assert_eq!(s2.instances[&wb2].alarms[1], -1, "an idle frame never arms the swing alarm");
}

#[test]
fn both_loose_buttons_clear_the_mouse_on_create() {
    let (asset, b) = game();
    // CODE 528 (obj_leftbutton) and CODE 531 (obj_rightbutton): mouse_clear.
    for (object, code) in [(LEFTBUTTON, 528), (RIGHTBUTTON, 531)] {
        let mut s = ui_scene(&asset, &b);
        for d in s.touch_devices.iter_mut() {
            d.down = true;
            d.pressed = true;
            d.released = true;
        }
        s.create(&b, object, 100.0, 100.0).expect("virtual button");
        assert!(s.touch_devices.iter().all(|d| !d.down && !d.pressed && !d.released),
            "CODE {code} clears every touch device when its button is created");
    }
}

#[test]
fn rightbutton_draw_moves_the_player_and_arms_its_alarm() {
    let (asset, b) = game();
    let (vx, vy) = (200.0, 100.0);
    // Held inside the button, world running: arm alarm[1] and draw the press.
    let mut s = ui_scene(&asset, &b);
    s.view_positions.insert(0, (vx, vy));
    let p = s.create(&b, PLAYER, 0.0, 0.0).expect("player");
    let rb = s.create(&b, RIGHTBUTTON, 0.0, 0.0).expect("obj_rightbutton");
    s.touch_devices[0].down = true;
    s.touch_devices[0].x = vx + 88.0 + 10.0;
    s.touch_devices[0].y = vy + 190.0 + 10.0;
    s.draw_view(&b, 0).expect("rightbutton draw");
    assert_eq!((s.instances[&rb].fields["x"], s.instances[&rb].fields["y"]),
        (vx + 88.0, vy + 190.0), "CODE 533 anchors the row at view + (88, 190)");
    assert_eq!(s.instances[&rb].alarms[1], 1, "CODE 533 arms alarm[1] on a button hold");
    assert!(s.draws.iter().any(|d| d.sprite == SPR_RIGHTBUTTON && d.instance == rb
            && d.frame == 1.0 && d.alpha == 1.0), "and draws the pressed frame");

    // Held outside: the player's walk speed is zeroed, no alarm.
    let mut s2 = ui_scene(&asset, &b);
    s2.view_positions.insert(0, (vx, vy));
    let p2 = s2.create(&b, PLAYER, 0.0, 0.0).expect("player");
    let rb2 = s2.create(&b, RIGHTBUTTON, 0.0, 0.0).expect("obj_rightbutton");
    s2.write(p2, -1, "hsp", None, 5.0).unwrap();
    s2.touch_devices[0].down = true;
    s2.touch_devices[0].x = 2000.0;
    s2.touch_devices[0].y = 2000.0;
    s2.draw_view(&b, 0).expect("rightbutton draw");
    assert_eq!(s2.instances[&p2].fields["hsp"], 0.0,
        "CODE 533 zeroes the walk speed for a hold outside the button");
    assert_eq!(s2.instances[&rb2].alarms[1], -1, "and arms nothing");

    // Released inside with the world running: zero the speed, drop the highlight.
    let mut s3 = ui_scene(&asset, &b);
    s3.view_positions.insert(0, (vx, vy));
    let p3 = s3.create(&b, PLAYER, 0.0, 0.0).expect("player");
    let rb3 = s3.create(&b, RIGHTBUTTON, 0.0, 0.0).expect("obj_rightbutton");
    s3.write(p3, -1, "hsp", None, 5.0).unwrap();
    s3.touch_devices[0].released = true;
    s3.touch_devices[0].x = vx + 88.0 + 10.0;
    s3.touch_devices[0].y = vy + 190.0 + 10.0;
    s3.draw_view(&b, 0).expect("rightbutton draw");
    assert_eq!(s3.instances[&p3].fields["hsp"], 0.0, "CODE 533 zeroes the speed on release");
    assert!(s3.draws.iter().any(|d| d.sprite == SPR_RIGHTBUTTON && d.instance == rb3
            && d.frame == 0.0 && d.alpha == 1.0), "and draws the released frame");

    // global.roomstart == 1 locks the row out entirely.
    let mut s4 = ui_scene(&asset, &b);
    s4.view_positions.insert(0, (vx, vy));
    let p4 = s4.create(&b, PLAYER, 0.0, 0.0).expect("player");
    let rb4 = s4.create(&b, RIGHTBUTTON, 0.0, 0.0).expect("obj_rightbutton");
    // obj_player's own Create lowers global.roomstart, so raise it afterwards.
    s4.globals.insert("roomstart".into(), 1.0);
    s4.write(p4, -1, "hsp", None, 5.0).unwrap();
    s4.touch_devices[0].released = true;
    s4.touch_devices[0].x = vx + 88.0 + 10.0;
    s4.touch_devices[0].y = vy + 190.0 + 10.0;
    s4.draw_view(&b, 0).expect("rightbutton draw");
    assert_eq!(s4.instances[&p4].fields["hsp"], 5.0,
        "CODE 533 refuses the release while global.roomstart == 1");
    assert_eq!(s4.instances[&rb4].alarms[1], -1, "and arms nothing");
    assert_eq!(s.instances[&rb].alarms[1], 1, "the running-world hold still armed its alarm");
    let _ = (p, rb);
}

// ---- obj_lineright / obj_lineleft / puffs -----------------------------------

#[test]
fn lineright_create_arms_its_lifetime_and_launch_speed() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    // CODE 719: alarm[0] = 89; hspeed = 12.
    let lr = s.create(&b, LINERIGHT, 0.0, 0.0).expect("obj_lineright");
    assert_eq!(s.instances[&lr].alarms[0], 89, "CODE 719 arms the 89-tick lifetime");
    assert_eq!(s.instances[&lr].fields["hspeed"], 12.0, "CODE 719 launches at 12 px/frame");
}

#[test]
fn line_bodies_retire_on_their_own_alarms() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let lr = s.create(&b, LINERIGHT, 0.0, 0.0).expect("obj_lineright");
    // CODE 720: instance_destroy().
    s.dispatch(&b, lr, 2, 0).expect("lineright A0");
    assert!(!s.instances[&lr].alive, "CODE 720 retires the right line on its alarm");

    let mut s2 = ui_scene(&asset, &b);
    let ll = s2.create(&b, LINELEFT, 0.0, 0.0).expect("obj_lineleft");
    // CODE 718: instance_destroy().
    s2.dispatch(&b, ll, 2, 0).expect("lineleft A0");
    assert!(!s2.instances[&ll].alive, "CODE 718 retires the left line on its alarm");

    // The right line also expires on its own 89-tick clock.
    let mut s3 = ui_scene(&asset, &b);
    let lr3 = s3.create(&b, LINERIGHT, 0.0, 0.0).expect("obj_lineright");
    for _ in 0..88 {
        s3.tick(&b).unwrap();
    }
    assert!(s3.instances[&lr3].alive, "still flying one tick short of its lifetime");
    s3.tick(&b).unwrap();
    assert!(!s3.instances[&lr3].alive, "CODE 720 fires at tick 89");
}

#[test]
fn puff_bodies_expire_on_their_own_eighteen_tick_alarm() {
    let (asset, b) = game();
    // CODE 782 / CODE 783 (obj_smallpuff) and CODE 784 / CODE 785 (obj_bigpuff).
    for (object, create_code, alarm_code) in
        [(SMALLPUFF, 782, 783), (BIGPUFF, 784, 785)]
    {
        let mut s = ui_scene(&asset, &b);
        let puff = s.create(&b, object, 0.0, 0.0).expect("puff");
        assert_eq!(s.instances[&puff].alarms[0], 18, "CODE {create_code} arms an 18-tick puff");
        // CODE 783 / CODE 785 reachable both ways.
        let mut direct = ui_scene(&asset, &b);
        let d = direct.create(&b, object, 0.0, 0.0).expect("puff");
        direct.dispatch(&b, d, 2, 0).expect("puff A0");
        assert!(!direct.instances[&d].alive, "CODE {alarm_code} destroys the puff directly");
        for _ in 0..17 {
            s.tick(&b).unwrap();
        }
        assert!(s.instances[&puff].alive, "object {object}: still visible at tick 17");
        s.tick(&b).unwrap();
        assert!(!s.instances[&puff].alive, "CODE {alarm_code} fires at tick 18");
    }
}

// ---- obj_boulderblock / obj_busterrockparts ---------------------------------

#[test]
fn boulderblock_create_marks_its_type() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    // CODE 679: type = 1.
    let bb = s.create(&b, BOULDERBLOCK, 0.0, 0.0).expect("obj_boulderblock");
    assert_eq!(s.instances[&bb].fields["type"], 1.0, "CODE 679 writes type = 1");
}

#[test]
fn boulderblock_destroy_scatters_six_rock_parts_and_cues_the_explosion() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let bb = s.create(&b, BOULDERBLOCK, 500.0, 400.0).expect("obj_boulderblock");
    // CODE 680: six parts plus snd_explode.
    s.destroy(&b, bb).expect("boulderblock destroy");
    let want = [(0.0, -8.0), (8.0, 0.0), (-8.0, 0.0), (0.0, 8.0), (-8.0, 8.0), (8.0, 8.0)];
    for (dx, dy) in want {
        let hit = s.instances.values().any(|i| i.alive && i.object == ROCKPARTS
            && i.fields["x"] == 500.0 + dx && i.fields["y"] == 400.0 + dy);
        assert!(hit, "CODE 680 scatters a part at ({dx}, {dy})");
    }
    assert_eq!(s.instances.values().filter(|i| i.alive && i.object == ROCKPARTS).count(), 6,
        "CODE 680 scatters exactly six parts");
    assert!(s.audio.iter().any(|c| c.sound == SND_EXPLODE),
        "CODE 680 cues snd_explode while global.soundmute == 0");

    // soundmute == 1 keeps the parts but silences the cue.
    let mut s2 = ui_scene(&asset, &b);
    s2.globals.insert("soundmute".into(), 1.0);
    let bb2 = s2.create(&b, BOULDERBLOCK, 0.0, 0.0).expect("obj_boulderblock");
    s2.destroy(&b, bb2).expect("boulderblock destroy");
    assert_eq!(s2.instances.values().filter(|i| i.alive && i.object == ROCKPARTS).count(), 6,
        "the parts still scatter with the sound muted");
    assert!(s2.audio.is_empty(), "global.soundmute == 1 cues no explosion");
}

#[test]
fn busterrockparts_create_rolls_its_scatter_pose() {
    let (asset, b) = game();
    for seed in 0..16u64 {
        let mut s = ui_scene(&asset, &b);
        s.rng_seed = s.rng_seed.wrapping_add(seed.wrapping_mul(0x9e3779b97f4a7c15));
        // CODE 681: mirrored scales, speed 7, a 70/110 toss, alarm[0] = 30.
        let rp = s.create(&b, ROCKPARTS, 0.0, 0.0).expect("obj_busterrockparts");
        let f = &s.instances[&rp].fields;
        assert!(f["image_xscale"] == 1.0 || f["image_xscale"] == -1.0,
            "CODE 681 rolls the x mirror, got {}", f["image_xscale"]);
        assert!(f["image_yscale"] == 1.0 || f["image_yscale"] == -1.0,
            "CODE 681 rolls the y mirror, got {}", f["image_yscale"]);
        assert_eq!(f["speed"], 7.0, "CODE 681 sets speed 7");
        assert!(f["direction"] == 70.0 || f["direction"] == 110.0,
            "CODE 681 tosses at 70 or 110 degrees, got {}", f["direction"]);
        assert_eq!(s.instances[&rp].alarms[0], 30, "CODE 681 arms its 30-tick lifetime");
    }
}

#[test]
fn busterrockparts_step_turns_gravity_back_on() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let rp = s.create(&b, ROCKPARTS, 0.0, 0.0).expect("obj_busterrockparts");
    assert_eq!(s.instances[&rp].fields["gravity"], 0.0, "a fresh part falls under no gravity yet");
    // CODE 683: gravity = 1.
    s.dispatch(&b, rp, 3, 0).expect("rock parts Step");
    assert_eq!(s.instances[&rp].fields["gravity"], 1.0, "CODE 683 turns gravity on");
    s.write(rp, -1, "gravity", None, 0.0).unwrap();
    s.tick(&b).unwrap();
    assert_eq!(s.instances[&rp].fields["gravity"], 1.0, "and again on every Step");
}

// ---- terrain objects --------------------------------------------------------

/// The room -> sprite tables of CODE 30 / 31 / 32 / 34, read straight off the
/// bytecode's `switch (room)` jump targets (each `bt` after `constant <room>;
/// cmp ==` lands on a body that stores one sprite constant). The boundaries are
/// the interesting part, so every set is probed at both ends.
const TERRAIN_ROOMS: [(i32, i32, i32, i32, i32); 13] = [
    // room, obj_wall path, obj_wall_2 wall, obj_boulder, obj_watersurface
    // CODE 30 / CODE 31 / CODE 32 / CODE 34
    (0, 5, 6, 7, 104),
    (1, 5, 6, 7, 104),
    (10, 5, 6, 7, 104),
    (11, 8, 9, 10, 104),
    (27, 8, 9, 10, 104),
    (28, 11, 12, 13, 101),
    (48, 11, 12, 13, 101),
    (49, 14, 15, 16, 104),
    (64, 14, 15, 16, 104),
    (65, 17, 18, 19, 101),
    (82, 17, 18, 19, 101),
    (83, 20, 21, 22, 101),
    (109, 20, 21, 22, 101),
];

#[test]
fn terrain_objects_pick_their_sprite_from_the_room() {
    let (asset, b) = game();
    for (room, path, wall, boulder, water) in TERRAIN_ROOMS {
        for (object, want, code) in [(WALL, path, 30), (WALL2, wall, 31), (BOULDER, boulder, 32)] {
            let mut s = ui_scene(&asset, &b);
            s.current_room = room as f64;
            let id = s.create(&b, object, 0.0, 0.0).expect("terrain object");
            assert_eq!(s.instances[&id].fields["sprite_index"], want as f64,
                "room {room}: CODE {code} on object {object} picks sprite {want}");
            assert_eq!(s.instances[&id].fields["type"], 1.0,
                "room {room}: CODE {code} writes type = 1");
            if code == 30 {
                assert_eq!(s.instances[&id].fields["activate"], 0.0, "CODE 30 writes activate = 0");
            }
        }
        let mut s = ui_scene(&asset, &b);
        s.current_room = room as f64;
        let id = s.create(&b, WATER, 0.0, 0.0).expect("obj_watersurface");
        assert_eq!(s.instances[&id].fields["sprite_index"], water as f64,
            "room {room}: CODE 34 picks sprite {water} for the surface row");
    }
}

#[test]
fn terrain_objects_keep_their_defaults_outside_the_switch() {
    let (asset, b) = game();
    // Room 110 (rm_ending) is in none of the four switches, so each object
    // keeps the sprite its object definition carries; the map rooms are only
    // in the boulder switch (CODE 32's rm_map / rm_mapview group).
    for (room, wall, wall2, boulder, water) in [(110, 5, 6, 10, 104), (111, 5, 6, 7, 104)] {
        for (object, want) in [(WALL, wall), (WALL2, wall2), (BOULDER, boulder)] {
            let mut s = ui_scene(&asset, &b);
            s.current_room = room as f64;
            let id = s.create(&b, object, 0.0, 0.0).expect("terrain object");
            assert_eq!(s.instances[&id].fields["sprite_index"], want as f64,
                "room {room}: object {object} keeps sprite {want}");
        }
        let mut s = ui_scene(&asset, &b);
        s.current_room = room as f64;
        let id = s.create(&b, WATER, 0.0, 0.0).expect("obj_watersurface");
        assert_eq!(s.instances[&id].fields["sprite_index"], water as f64,
            "room {room}: the water surface keeps sprite {water}");
    }
}

// ---- obj_player / obj_bg / obj_muting / obj_music ---------------------------

#[test]
fn player_keyrelease_38_queues_the_ending_room() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let p = s.create(&b, PLAYER, 100.0, 100.0).expect("player");
    assert!(s.target_room_warp.is_none(), "nothing queued before the key release");
    // CODE 19: room_goto(rm_ending).
    s.dispatch(&b, p, 10, 38).expect("player KeyRelease 38");
    assert_eq!(s.target_room_warp, Some(RM_ENDING),
        "CODE 19 queues rm_ending ({RM_ENDING})");
}

#[test]
fn bg_step_keeps_its_own_heartbeat_armed() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    // CODE 361's frame body walks the world around obj_player, so one must be
    // alive and in the scene for the heartbeat to be observable at all.
    let p = s.create(&b, PLAYER, 100.0, 100.0).expect("player");
    let bg = s.create(&b, BG, 0.0, 0.0).expect("obj_bg");
    // A dangling slot is re-armed; a live one is left alone.
    s.instances.get_mut(&bg).unwrap().alarms[2] = -1;
    s.dispatch(&b, bg, 3, 0).expect("bg Step");
    assert_eq!(s.instances[&bg].alarms[2], 15, "CODE 363 arms a dangling slot at 15");
    s.instances.get_mut(&bg).unwrap().alarms[2] = 7;
    s.dispatch(&b, bg, 3, 0).expect("bg Step");
    assert_eq!(s.instances[&bg].alarms[2], 7, "CODE 363 leaves a live slot alone");

    // Its own clock: obj_bg's Create seeds alarm[2] = 5, the frame body (which
    // itself writes alarm[2] = 15) runs, and CODE 363 keeps the 15-tick beat.
    let mut s2 = ui_scene(&asset, &b);
    let p2 = s2.create(&b, PLAYER, 100.0, 100.0).expect("player");
    let bg2 = s2.create(&b, BG, 0.0, 0.0).expect("obj_bg");
    for (n, v) in [("hspeed", 0.0), ("vspeed", 0.0), ("gravity", 0.0)] {
        s2.write(p2, -1, n, None, v).unwrap();
    }
    assert_eq!(s2.instances[&bg2].alarms[2], 5, "obj_bg opens on a 5-tick frame");
    for _ in 0..4 {
        s2.tick(&b).unwrap();
    }
    assert_eq!(s2.instances[&bg2].alarms[2], 1, "one tick short of the frame");
    s2.tick(&b).unwrap();
    assert_eq!(s2.instances[&bg2].alarms[2], 15,
        "CODE 363 re-arms the 15-tick frame right after it fires");
    for _ in 0..14 {
        s2.tick(&b).unwrap();
    }
    assert_eq!(s2.instances[&bg2].alarms[2], 1, "the next beat is a 15-tick wait");
    s2.tick(&b).unwrap();
    assert_eq!(s2.instances[&bg2].alarms[2], 15, "and it keeps beating every 15 ticks");
    let _ = p;
}

#[test]
fn muting_alarm_five_freezes_the_player_and_the_loose_buttons() {
    let (asset, b) = game();
    let mut s = ui_scene(&asset, &b);
    let p = s.create(&b, PLAYER, 100.0, 100.0).expect("player");
    let left = s.create(&b, LEFTBUTTON, 0.0, 0.0).expect("obj_leftbutton");
    let right = s.create(&b, RIGHTBUTTON, 0.0, 0.0).expect("obj_rightbutton");
    let muting = s.create(&b, MUTING, 0.0, 0.0).expect("obj_muting");
    for (n, v) in [("hspeed", 7.0), ("vspeed", 8.0), ("hsp", 9.0)] {
        s.write(p, -1, n, None, v).unwrap();
    }
    s.write(left, -1, "alarm", Some(1), 3.0).unwrap();
    s.write(right, -1, "alarm", Some(1), 4.0).unwrap();
    // CODE 372: the player's three speed fields and both buttons' alarm[1].
    s.dispatch(&b, muting, 2, 5).expect("muting A5");
    for n in ["hspeed", "vspeed", "hsp"] {
        assert_eq!(s.instances[&p].fields[n], 0.0, "CODE 372 zeroes the player's {n}");
    }
    assert_eq!(s.instances[&left].alarms[1], 0, "CODE 372 clears obj_leftbutton's alarm[1]");
    assert_eq!(s.instances[&right].alarms[1], 0, "CODE 372 clears obj_rightbutton's alarm[1]");
}

/// obj_music's own playlist: theme[0..16] as CODE 375 writes them, with the
/// sound ids read off CODE 376's `audio_is_playing` guard chain.
const MUSIC_THEME: [i32; 17] = [37, 46, 52, 35, 36, 44, 30, 45, 39, 31, 34, 33, 32, 38, 29, 47, 41];

#[test]
fn music_alarm_zero_starts_a_theme_only_when_the_gate_is_open() {
    let (asset, b) = game();
    // Open gate: no track playing, musicmute == 0 -> play theme[soundplay] and
    // freeze the sprite animation.
    let mut s = ui_scene(&asset, &b);
    s.globals.insert("playlist".into(), 1.0);
    let m = s.create(&b, MUSIC, 0.0, 0.0).expect("obj_music");
    assert_eq!(s.instances[&m].fields["soundplay"], 0.0, "the playlist opens on index 0");
    assert_eq!(s.instances[&m].arrays[&("theme".to_string(), 0)], MUSIC_THEME[0] as f64,
        "CODE 375 seeds theme[0]");
    s.write(m, -1, "image_speed", None, 5.0).unwrap();
    s.dispatch(&b, m, 2, 0).expect("music A0");
    let played = s.audio.last().expect("theme start");
    assert_eq!(played.sound, MUSIC_THEME[0], "CODE 376 starts theme[soundplay]");
    assert!(!played.looping, "the theme is started non-looping");
    assert_eq!(s.instances[&m].fields["image_speed"], 0.0,
        "CODE 376 freezes the music icon after the gate opens");

    // A later index plays that row.
    let mut s2 = ui_scene(&asset, &b);
    s2.globals.insert("playlist".into(), 1.0);
    let m2 = s2.create(&b, MUSIC, 0.0, 0.0).expect("obj_music");
    s2.write(m2, -1, "soundplay", None, 5.0).unwrap();
    s2.dispatch(&b, m2, 2, 0).expect("music A0");
    assert_eq!(s2.audio.last().expect("theme start").sound, MUSIC_THEME[5],
        "CODE 376 follows soundplay into the playlist");

    // Every one of the guard ids closes the gate: no start. The innermost guard
    // (52 = mus_blooddragon) only shields the start — the original's
    // `image_speed = 0;` sits outside that one check, so reaching it with 52
    // playing still freezes the icon.
    for id in 29..=52 {
        let mut s3 = ui_scene(&asset, &b);
        s3.globals.insert("playlist".into(), 1.0);
        let m3 = s3.create(&b, MUSIC, 0.0, 0.0).expect("obj_music");
        s3.call_audio_play(id as f64, 0.0, true);
        let before = s3.audio.len();
        s3.write(m3, -1, "image_speed", None, 5.0).unwrap();
        s3.dispatch(&b, m3, 2, 0).expect("music A0");
        assert_eq!(s3.audio.len(), before,
            "CODE 376 holds the gate while sound {id} plays");
        let frozen = s3.instances[&m3].fields["image_speed"];
        if id == 52 {
            assert_eq!(frozen, 0.0,
                "sound 52's guard is the innermost one: the freeze still runs");
        } else {
            assert_eq!(frozen, 5.0,
                "sound {id} playing skips both the start and the freeze");
        }
    }

    // musicmute == 1 skips the body entirely.
    let mut s4 = ui_scene(&asset, &b);
    s4.globals.insert("musicmute".into(), 1.0);
    let m4 = s4.create(&b, MUSIC, 0.0, 0.0).expect("obj_music");
    s4.write(m4, -1, "image_speed", None, 5.0).unwrap();
    s4.dispatch(&b, m4, 2, 0).expect("music A0");
    assert!(s4.audio.is_empty(), "CODE 376 is silent while global.musicmute == 1");
    assert_eq!(s4.instances[&m4].fields["image_speed"], 5.0,
        "and it does not even touch the animation");

    // The sequencer's own clock: CODE 375 arms alarm[0] = 60. obj_music's Step
    // (CODE 377) would start a track the moment the gate opens, so that Step is
    // held off by a guard track which is stopped exactly one tick before the
    // alarm arrives - the tick that then proves CODE 376 fires by itself.
    let mut s5 = ui_scene(&asset, &b);
    s5.globals.insert("playlist".into(), 1.0);
    let m5 = s5.create(&b, MUSIC, 0.0, 0.0).expect("obj_music");
    assert_eq!(s5.instances[&m5].alarms[0], 60, "CODE 375 arms the theme check at 60");
    s5.call_audio_play(52.0, 0.0, true);
    let held: Vec<i32> = s5.audio.iter().map(|c| c.sound).collect();
    for _ in 0..59 {
        s5.tick(&b).unwrap();
    }
    assert_eq!(s5.instances[&m5].alarms[0], 1, "one tick short of the alarm");
    assert_eq!(s5.instances[&m5].fields["soundplay"], 0.0,
        "the guard track kept the Step sequencer quiet");
    let after_ticks: Vec<i32> = s5.audio.iter().map(|c| c.sound).collect();
    assert_eq!(after_ticks, held, "no track started while the gate was closed");
    s5.call_audio_stop_sound(52.0);
    s5.write(m5, -1, "image_speed", None, 5.0).unwrap();
    s5.tick(&b).unwrap();
    assert_eq!(s5.instances[&m5].alarms[0], -1, "CODE 376 fired on its own 60-tick alarm");
    assert_eq!(s5.audio.last().expect("theme start").sound, MUSIC_THEME[0],
        "and started theme[soundplay] once the gate opened");
    assert_eq!(s5.instances[&m5].fields["image_speed"], 0.0,
        "freezing the music icon on the same tick");
}
