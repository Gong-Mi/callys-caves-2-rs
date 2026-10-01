use callys_core::original_introduction::IntroductionState;
use callys_core::original_boss_trex::TrexState;

#[test]
fn introduction_state_machine_advances_and_exits_on_tap() {
    let mut intro = IntroductionState::new();
    assert_eq!(intro.moving, 1.0);
    assert_eq!(intro.moving2, 0.0);
    assert_eq!(intro.taplock, 0.0);
    assert!(!intro.destroyed);

    let mut spawned = Vec::new();

    // Advance 30 frames: Alarm 1 fires -> moving=0, moving2=1
    for _ in 0..30 {
        intro.tick_frame(false, |_, _, obj| spawned.push(obj));
    }
    assert_eq!(intro.moving, 0.0);
    assert_eq!(intro.moving2, 1.0);

    // Advance 40 frames (total 70): Alarm 2 fires -> spawns obj_logo, Alarm 3 fires -> moving2=0
    for _ in 0..40 {
        intro.tick_frame(false, |_, _, obj| spawned.push(obj));
    }
    assert_eq!(intro.moving2, 0.0);
    assert!(spawned.contains(&"obj_logo"));

    // Advance 50 frames (total 120): Alarm 0 fires -> taplock=1
    for _ in 0..50 {
        intro.tick_frame(false, |_, _, obj| spawned.push(obj));
    }
    assert_eq!(intro.taplock, 1.0);

    // Tap to skip introduction
    let destroyed = intro.tick_frame(true, |_, _, obj| spawned.push(obj));
    assert!(destroyed);
    assert!(intro.destroyed);
}

#[test]
fn trex_boss_state_machine_takes_damage_and_triggers_death() {
    let mut trex = TrexState::new(1.0); // pwr = 1 -> 275 HP
    assert_eq!(trex.hptrex, 275.0);
    assert_eq!(trex.boss1maxhp, 275.0);
    assert_eq!(trex.facing, 0.0); // Left
    assert_eq!(trex.hspeed, 0.0); // Initial speed before first step

    let mut dead_sound = None;

    // Simulate stepping on ground (player is far right, so player does not force facing=0)
    trex.tick_frame(true, false, false, 800.0, 200.0, 600.0, |snd| dead_sound = Some(snd));
    assert_eq!(trex.gravity, 0.0);
    assert_eq!(trex.falling, 0.0);
    assert_eq!(trex.hspeed, -3.0);
    assert!(!trex.dead);

    // Hit left wall -> facing turns right (facing=1)
    trex.tick_frame(true, true, false, 800.0, 200.0, 600.0, |snd| dead_sound = Some(snd));
    assert_eq!(trex.facing, 1.0);

    // Next step facing=1 sets hspeed = 3.0
    trex.tick_frame(true, false, false, 800.0, 200.0, 600.0, |snd| dead_sound = Some(snd));
    assert_eq!(trex.hspeed, 3.0);

    // Apply lethal damage
    trex.apply_damage(280.0);
    assert!(trex.hptrex <= 0.0);

    // Tick to allow Alarm 0 to trigger
    trex.tick_frame(true, false, false, 800.0, 200.0, 600.0, |snd| dead_sound = Some(snd));
    assert!(trex.dead);
    assert_eq!(dead_sound, Some("snd_explode"));
}
