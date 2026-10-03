//! Wall-clock regressions at the exact scheduler entry called by Android JNI.
//! Oracles are the original CODE 548/550..554 and 556/558..564, not mock ticks.
use callys_client::{frame_clock::FrameClock, GameState};
use callys_core::{code_vm::load_bundle_from_file, ir_scene::Instance};
use std::{path::Path, sync::Arc};

const SECOND: i64 = 1_000_000_000;

fn boot() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap(),
    );
    state.enable_ir_gameplay(bundle).unwrap();
    state
}

fn instance(state: &GameState, object: i32) -> &Instance {
    assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    state.scene.as_ref().unwrap().instances.values()
        .find(|i| i.object == object && i.alive).expect("original IR instance alive")
}

fn present_until(state: &mut GameState, clock: &mut FrameClock, hz: i64, end: i64) -> u64 {
    let mut ticks = 0;
    for frame in 1.. {
        let now = (frame * SECOND / hz).min(end);
        ticks += clock.step_at(state, now);
        if now == end { return ticks; }
    }
    unreachable!()
}

fn lloyd_sheet() -> GameState {
    let mut state = boot();
    // Isolate the timeline under test through the real Destroy/Create events.
    // This is not a claim about naturally walking into the proximity trigger.
    state.retire_prologue();
    let bundle = state.full_bundle.clone().unwrap();
    state.scene.as_mut().unwrap().create(&bundle, 138, 0.0, 0.0).unwrap();
    assert_eq!(instance(&state, 138).alarms[5], 600, "CODE 556 real 600-tick gate");
    state
}

#[test]
fn original_114_rooms_all_use_30hz() {
    let state = boot();
    assert_eq!(state.asset.rooms.len(), 114);
    assert!(state.asset.rooms.iter().all(|r| r.speed == 30));
}

#[test]
fn equal_elapsed_at_60_30_and_5_presentations_advances_the_same_original_film() {
    for hz in [60, 30, 5] {
        let mut state = boot();
        let mut clock = FrameClock::default();
        clock.step_at(&mut state, 0);
        let ticks = present_until(&mut state, &mut clock, hz, SECOND);
        let intro = instance(&state, 137);
        assert_eq!(intro.alarms[0], 90, "{hz} presentations/s: one second is 30 IR ticks");
        assert_eq!(intro.alarms[1], -1, "original Alarm 1 fires at one second");
        assert_eq!(intro.alarms[2], 40);
        assert_eq!(intro.fields["xx1"], 51.0, "real original Step movement, not just a tick counter");
        assert_eq!(intro.fields["moving"], 0.0);
        assert_eq!(intro.fields["moving2"], 1.0);
        assert_eq!(ticks, 30);
    }
}

#[test]
fn original_intro_alarm_120_unlocks_at_exactly_four_seconds_at_every_cadence() {
    for hz in [60, 30, 5] {
        let mut state = boot();
        let mut clock = FrameClock::default();
        clock.step_at(&mut state, 0);
        let ticks = present_until(&mut state, &mut clock, hz, 4 * SECOND - 1);
        assert_eq!(instance(&state, 137).fields["taplock"], 0.0, "{hz}Hz must not unlock before 4s");
        assert_eq!(instance(&state, 137).alarms[0], 1);
        assert_eq!(ticks, 119);
        assert_eq!(clock.step_at(&mut state, 4 * SECOND), 1);
        assert_eq!(instance(&state, 137).fields["taplock"], 1.0);
        assert_eq!(instance(&state, 137).alarms[0], -1);
    }
}

#[test]
fn original_lloyd_panels_and_alarm_600_take_twenty_seconds_at_every_cadence() {
    for hz in [60, 30, 5] {
        let mut state = lloyd_sheet();
        let mut clock = FrameClock::default();
        clock.step_at(&mut state, 0);
        let ticks = present_until(&mut state, &mut clock, hz, 20 * SECOND - 1);
        let sheet = instance(&state, 138);
        assert_eq!(sheet.fields["taplock"], 0.0, "{hz}Hz: CODE 558 must wait 20s");
        assert_eq!(sheet.alarms[5], 1);
        assert_eq!(sheet.fields["drawpanel1"], 0.0);
        assert_eq!(sheet.fields["drawpanel6"], 1.0, "all original panel alarms have run");
        assert_eq!(ticks, 599);
        assert_eq!(clock.step_at(&mut state, 20 * SECOND), 1);
        assert_eq!(instance(&state, 138).fields["taplock"], 1.0);
        assert_eq!(instance(&state, 138).alarms[5], -1);
        assert!(state.scene.as_ref().unwrap().texts.iter().any(|t| t.text == "Tap to Continue"));
    }
}

#[test]
fn initial_and_repeated_zero_elapsed_presentations_do_not_step_or_consume_input() {
    let mut state = lloyd_sheet();
    let mut clock = FrameClock::default();
    state.pointer_released(480.0, 270.0);
    for _ in 0..5 {
        assert_eq!(clock.step_at(&mut state, -SECOND), 0);
        assert_eq!(instance(&state, 138).alarms[5], 600);
        assert_eq!(state.scene.as_ref().unwrap().left_releases.len(), 1);
    }
}

#[test]
fn sub_millisecond_samples_keep_fractional_ns_without_drift_or_a_50ms_cap() {
    let mut state = boot();
    let mut clock = FrameClock::default();
    clock.step_at(&mut state, 0);
    let mut ticks = 0;
    // Every sample would truncate to zero milliseconds in the old Java loop.
    for now in (123_457..SECOND).step_by(123_457) {
        ticks += clock.step_at(&mut state, now);
    }
    ticks += clock.step_at(&mut state, SECOND);
    assert_eq!(instance(&state, 137).alarms[0], 90);
    assert_eq!(ticks, 30);
    // One active stall must consume all three seconds, not only 50ms/one tick.
    assert_eq!(clock.step_at(&mut state, 4 * SECOND), 90);
    assert_eq!(instance(&state, 137).fields["taplock"], 1.0);
}

#[test]
fn clock_uses_current_ir_room_speed_not_render_rate_or_legacy_world_room() {
    let mut state = boot();
    state.asset.rooms[0].speed = 60;
    state.asset.rooms[1].speed = 7;
    state.world.current_room_index = 1;
    let mut clock = FrameClock::default();
    clock.step_at(&mut state, 0);
    let ticks = clock.step_at(&mut state, SECOND);
    assert_eq!(instance(&state, 137).alarms[0], 60);
    assert_eq!(ticks, 60);
}

#[test]
fn speed_is_resampled_after_a_real_room_transition_inside_one_presentation() {
    let mut state = boot();
    state.retire_prologue();
    state.asset.rooms[1].speed = 60;
    state.scene.as_mut().unwrap().target_room_warp = Some(1);
    let mut clock = FrameClock::default();
    clock.step_at(&mut state, 0);
    // 1/30s in town, then 1/60s in level1: exactly two ticks in 50ms.
    assert_eq!(clock.step_at(&mut state, 50_000_000), 2);
    assert_eq!(state.scene.as_ref().unwrap().current_room, 1.0);
    assert_eq!(state.frame_count, 2);
    assert!(instance(&state, 0).active);
}

#[test]
fn pause_discards_partial_tick_and_resume_never_catches_up_suspended_time() {
    let mut state = boot();
    let mut clock = FrameClock::default();
    clock.step_at(&mut state, 0);
    assert_eq!(clock.step_at(&mut state, 20_000_000), 0);
    clock.set_paused(true);
    assert_eq!(clock.step_at(&mut state, 100 * SECOND), 0);
    assert_eq!(instance(&state, 137).alarms[0], 120);
    clock.set_paused(false);
    assert_eq!(clock.step_at(&mut state, 200 * SECOND), 0);
    assert_eq!(clock.step_at(&mut state, 200 * SECOND + 20_000_000), 0);
    assert_eq!(instance(&state, 137).alarms[0], 120);
    assert_eq!(clock.step_at(&mut state, 201 * SECOND), 30);
    assert_eq!(instance(&state, 137).alarms[0], 90);
}

#[test]
fn one_up_is_not_replayed_into_a_later_tick_that_unlocks_the_story() {
    let mut state = lloyd_sheet();
    let mut clock = FrameClock::default();
    clock.step_at(&mut state, 0);
    let before = 19 * SECOND + 933_333_334;
    clock.step_at(&mut state, before);
    assert_eq!(instance(&state, 138).alarms[5], 2);
    state.pointer_released(480.0, 270.0);
    assert_eq!(clock.step_at(&mut state, before), 0, "a zero-tick presentation must retain UP");
    assert_eq!(state.scene.as_ref().unwrap().left_releases.len(), 1);
    assert_eq!(clock.step_at(&mut state, before + 100_000_000), 3);
    assert_eq!(instance(&state, 138).fields["taplock"], 1.0, "locked UP is consumed only once; sheet survives subsequent unlock");
    assert!(state.scene.as_ref().unwrap().left_releases.is_empty());
    assert!(!state.scene.as_ref().unwrap().touch_devices[0].released);
    state.pointer_released(480.0, 270.0);
    assert_eq!(clock.step_at(&mut state, before + 200_000_000), 3);
    let scene = state.scene.as_ref().unwrap();
    assert!(!scene.instances.values().any(|i| i.object == 138 && i.alive));
    assert_eq!(scene.globals.get("talkedtolloyd1"), Some(&1.0));
    assert!(!scene.touch_devices[0].released);
}

#[test]
fn an_early_held_press_is_not_replayed_when_a_later_catchup_tick_unlocks_the_film() {
    let mut state = boot();
    let mut clock = FrameClock::default();
    clock.step_at(&mut state, 0);
    clock.step_at(&mut state, 3_950_000_000);
    assert_eq!(instance(&state, 137).fields["taplock"], 0.0);
    state.input.tap = true;
    // The press belongs to the first tick, while the film is still locked.
    // Catch-up then reaches the unlocking tick without another physical DOWN.
    clock.step_at(&mut state, 4 * SECOND);
    assert_eq!(instance(&state, 137).fields["taplock"], 1.0,
        "one held DOWN must not become a new press on a later tick");
    clock.step_at(&mut state, 5 * SECOND);
    assert!(state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive));
    state.input.tap = false;
    clock.step_at(&mut state, 5 * SECOND + 40_000_000);
    state.input.tap = true;
    clock.step_at(&mut state, 5 * SECOND + 80_000_000);
    assert!(!state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive),
        "a fresh physical DOWN after unlock still dismisses the film");
}

#[test]
fn signed_monotonic_wrap_and_backward_samples_do_not_duplicate_elapsed_time() {
    let mut state = boot();
    let mut clock = FrameClock::default();
    let origin = i64::MAX - SECOND / 2;
    assert_eq!(clock.step_at(&mut state, origin), 0);
    assert_eq!(clock.step_at(&mut state, origin - 1), 0);
    assert_eq!(instance(&state, 137).alarms[0], 120);
    let after_wrap = origin.wrapping_add(SECOND);
    assert_eq!(clock.step_at(&mut state, after_wrap), 30);
    assert_eq!(instance(&state, 137).alarms[0], 90);
    assert_eq!(clock.step_at(&mut state, after_wrap - 10), 0);
    assert_eq!(clock.step_at(&mut state, after_wrap), 0);
    assert_eq!(instance(&state, 137).alarms[0], 90);
    assert_eq!(clock.step_at(&mut state, after_wrap + SECOND), 30);
    assert_eq!(instance(&state, 137).alarms[0], 60);
}
