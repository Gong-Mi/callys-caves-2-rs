//! Oracle: original CODE1..9 GML/bytecode, pinned in reconstruction/contracts/player-alarms.json.
use callys_core::original_player::{dispatch_alarm, AlarmError, AlarmGlobals, AlarmPlayer, AlarmResources};

fn state() -> (AlarmPlayer, AlarmGlobals, AlarmResources) {
    (AlarmPlayer { invulnerable: 2.0, invulnerable2: 3.0, sliding1: 4.0,
        sliding2: 5.0, hsp: -6.0, sprite_index: 7.0, playerdied: 8.0,
        throwingboomerang: 9.0, alarms: [-1.0; 12] },
     AlarmGlobals { health1: 2.0, maxhp: 4.0, healthregenbought: 1.0,
        timeplayed: 7.5, roomstart: 2.0, firing: 2.0, swing: 2.0 },
     AlarmResources { spr_player: 29.0 })
}

#[test]
fn alarm11_heals_when_not_equal_and_bought_then_rearms() {
    let (mut p, mut g, r) = state();
    let (mut expected_p, mut expected_g) = (p.clone(), g.clone());
    expected_p.alarms[11] = 300.0;
    expected_g.health1 += 1.0;
    dispatch_alarm(11, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (expected_p, expected_g));
}

#[test]
fn alarm11_preserves_original_not_equal_instead_of_clamping() {
    for (hp, maxhp, bought, should_heal) in [
        (4.0, 4.0, 1.0, false), (6.0, 4.0, 1.0, true),
        (2.0, 4.0, 0.0, false), (2.0, 4.0, 2.0, false),
    ] {
        let (mut p, mut g, r) = state();
        g.health1 = hp; g.maxhp = maxhp; g.healthregenbought = bought;
        let (mut expected_p, mut expected_g) = (p.clone(), g.clone());
        if should_heal { expected_g.health1 += 1.0; }
        expected_p.alarms[11] = 300.0;
        dispatch_alarm(11, &mut p, &mut g, &r).unwrap();
        assert_eq!((p, g), (expected_p, expected_g));
    }
}

#[test]
fn alarm10_changes_global_time_and_its_own_alarm_only() {
    let (mut p, mut g, r) = state();
    let (mut expected_p, mut expected_g) = (p.clone(), g.clone());
    expected_p.alarms[10] = 30.0; expected_g.timeplayed += 1.0;
    dispatch_alarm(10, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (expected_p, expected_g));
}

#[test]
fn alarm8_clears_both_invulnerable_fields_only() {
    let (mut p, mut g, r) = state(); let mut expected = p.clone();
    let unchanged_g = g.clone(); expected.invulnerable = 0.0; expected.invulnerable2 = 0.0;
    dispatch_alarm(8, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (expected, unchanged_g));
}

#[test]
fn alarm7_uses_resolved_sprite_instead_of_hardcoded_geometry() {
    let (mut p, mut g, mut r) = state(); let unchanged_g = g.clone();
    r.spr_player = 123.0; let mut expected = p.clone(); expected.sprite_index = r.spr_player;
    dispatch_alarm(7, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (expected, unchanged_g));
}

#[test]
fn alarm6_changes_only_global_roomstart() {
    let (mut p, mut g, r) = state(); let unchanged_p = p.clone();
    let mut expected = g.clone(); expected.roomstart = 0.0;
    dispatch_alarm(6, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (unchanged_p, expected));
}

#[test]
fn alarm5_changes_only_instance_playerdied() {
    let (mut p, mut g, r) = state(); let unchanged_g = g.clone();
    let mut expected = p.clone(); expected.playerdied = 0.0;
    dispatch_alarm(5, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (expected, unchanged_g));
}

#[test]
fn alarm4_clears_both_slide_fields_and_hsp_only() {
    let (mut p, mut g, r) = state(); let unchanged_g = g.clone();
    let mut expected = p.clone(); expected.sliding1 = 0.0; expected.sliding2 = 0.0; expected.hsp = 0.0;
    dispatch_alarm(4, &mut p, &mut g, &r).unwrap();
    assert_eq!((p, g), (expected, unchanged_g));
}

#[test]
fn alarm3_changes_global_firing_and_instance_throwing_only() {
    let (mut p, mut g, r) = state(); let (mut ep, mut eg) = (p.clone(), g.clone());
    ep.throwingboomerang = 0.0; eg.firing = 0.0;
    dispatch_alarm(3, &mut p, &mut g, &r).unwrap(); assert_eq!((p, g), (ep, eg));
}

#[test]
fn alarm2_changes_global_swing_and_sprite_only() {
    let (mut p, mut g, r) = state(); let (mut ep, mut eg) = (p.clone(), g.clone());
    ep.sprite_index = r.spr_player; eg.swing = 1.0;
    dispatch_alarm(2, &mut p, &mut g, &r).unwrap(); assert_eq!((p, g), (ep, eg));
}

#[test]
fn unrestored_absent_and_invalid_alarms_are_distinct_and_atomic() {
    for (alarm, error) in [(0, AlarmError::NotRestored(0)), (1, AlarmError::NotRestored(1)),
        (9, AlarmError::NoDirectEvent(9)), (12, AlarmError::OutOfRange(12))] {
        let (mut p, mut g, r) = state(); let (ep, eg) = (p.clone(), g.clone());
        assert_eq!(dispatch_alarm(alarm, &mut p, &mut g, &r), Err(error));
        assert_eq!((p, g), (ep, eg));
    }
}
