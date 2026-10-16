//! Gameplay BGM contract (WL8): the original's `audio_is_playing` anti-stack
//! chain must hold in the shipped client loop.
//!
//! `obj_music` Step (CODE 377) is a 24-deep `if (!audio_is_playing(mus_*))`
//! chain around `audio_play_sound(theme[soundplay], 0, false)`; `soundplay`
//! advances only inside that block. The chain is only a gate if the engine
//! reports a started track as playing for its whole length. When the ledger had
//! no duration for the track, the client's per-frame `drain_audio` retired the
//! voice in the same frame it was issued, every gate answered false, and the
//! tracker advanced one theme per frame — one audible `mus_*` command per frame
//! (dev + device observation: frames 126+ of the boot, ids 29..52 rotating).
//! The Android host consumes every `id >= 29` command as stopBgm + new
//! MediaPlayer, so those frames also restarted the BGM every frame.
//!
//! These tests run the shipped `GameState` boot (`GameState::new` ->
//! `enable_ir_gameplay`, the prologue's real 120-tick taplock, a real tap) and
//! read the platform sound queue with `poll_sound`, exactly what the Android
//! host drains.
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const INTRO: i32 = 137;
/// SOND 31 = mus_new4, the prologue track obj_introduction Create starts
/// (CODE 548 @0x110) and the only sound the boot issues.
const MUS_NEW4: i32 = 31;
/// SOND 51 = mus_bosssong, the looping theme obj_music Room Start gives
/// rm_boss1 (CODE 378 @0x64).
const MUS_BOSSSONG: i32 = 51;
/// SOND 29..53 are the 25 streamed `mus_*` OGGs (the host routes `id >= 29`
/// to the music channel); 0..28 are the embedded `snd_*` one-shots.
const FIRST_MUSIC: usize = 29;
/// rm_boss1's room index in the shipped ROOM table.
const RM_BOSS1: usize = 10;

fn boot_like_android() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).expect("GameState::new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../../crates/core/src/generated/full_ir.json"))
            .expect("load full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state
}

fn scene(state: &GameState) -> &Scene {
    state.scene.as_ref().expect("IR gameplay scene")
}

/// (frame, sound, looping, is_stop) for every command the host would drain.
type Command = (usize, usize, bool, bool);

fn drain(state: &mut GameState, frame: usize, out: &mut Vec<Command>) {
    while let Some((sound, looping, is_stop)) = state.poll_sound() {
        out.push((frame, sound, looping, is_stop));
    }
}

fn music_plays(commands: &[Command]) -> Vec<&Command> {
    commands
        .iter()
        .filter(|(_, sound, _, is_stop)| *sound >= FIRST_MUSIC && !is_stop)
        .collect()
}

/// The mus ids the engine currently reports as playing, from the voice ledger.
fn playing_music(state: &GameState) -> Vec<i32> {
    scene(state)
        .audio_voices
        .iter()
        .filter(|v| v.sound >= FIRST_MUSIC as f64 && !v.stopped && !v.paused)
        .map(|v| v.sound as i32)
        .collect()
}

fn intro_alive(state: &GameState) -> bool {
    state
        .scene
        .as_ref()
        .map(|s| s.instances.values().any(|i| i.object == INTRO && i.alive))
        .unwrap_or(false)
}

/// Boot + the prologue's natural 120-tick taplock + a real tap, returning the
/// frame index of the handover frame. The intro dies on the tap and the same
/// scene continues into rm_town (client handover path, not a scene rebuild).
fn boot_through_prologue(state: &mut GameState) -> usize {
    for _ in 0..125 {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    }
    assert!(intro_alive(state), "the untouched prologue outlives its taplock");
    let handover = 125;
    state.input.tap = true;
    state.step(1.0 / 30.0);
    state.input.tap = false;
    assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    handover
}

/// RED/green core of this file: no frame after the handover may re-issue the
/// BGM. Before the fix every gameplay frame carried one `mus_*` play (the
/// sequencer's gate never held), which the host turns into a BGM restart.
#[test]
fn gameplay_bgm_is_not_reissued_every_frame() {
    let mut state = boot_like_android();
    let handover = boot_through_prologue(&mut state);

    let mut commands = Vec::new();
    drain(&mut state, handover, &mut commands);
    // The queue's backlog through the prologue is exactly one command — the
    // prologue track's initial issue (CODE 548 at intro Create), first drained
    // here. It is not a gameplay re-issue.
    let backlog = music_plays(&commands);
    assert_eq!(
        backlog.len(),
        1,
        "the prologue's only sound is its single mus_new4 issue, got {backlog:?}"
    );
    assert_eq!(
        backlog[0].1,
        MUS_NEW4 as usize,
        "the backlog play is the prologue track itself, got {backlog:?}"
    );

    let mut later = Vec::new();
    for frame in (handover + 1)..(handover + 120) {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        drain(&mut state, frame, &mut later);
    }
    assert!(
        later.is_empty(),
        "no gameplay frame may re-issue the BGM (the host restarts MediaPlayer on \
         every id >= 29); got {:?}",
        music_plays(&later)
    );

    // And the gate holds for a real reason: the prologue's own track is still
    // playing (mus_new4 is 43.624 s = 1309 ticks at the room's 30 Hz).
    assert_eq!(
        playing_music(&state),
        vec![MUS_NEW4],
        "the prologue track is the reason obj_music's chain blocks new music"
    );
    assert!(
        scene(&state).audio_is_playing_sound(MUS_NEW4 as f64),
        "a started track must report playing for its real length"
    );
}

/// The sequencer must still START music: once the current track's real length
/// has elapsed the 24-deep chain reopens and `theme[soundplay]` plays exactly
/// once — not once per frame, and not never.
#[test]
fn the_sequencer_issues_the_next_theme_once_the_track_ends() {
    let mut state = boot_like_android();
    let handover = boot_through_prologue(&mut state);
    let mut commands = Vec::new();
    drain(&mut state, handover, &mut commands);
    // Same backlog as the sibling test: the prologue track's single initial
    // issue, drained here for the first time.
    let backlog = music_plays(&commands);
    assert_eq!(backlog.len(), 1, "unexpected backlog {backlog:?}");
    assert_eq!(backlog[0].1, MUS_NEW4 as usize, "unexpected backlog {backlog:?}");

    {
        assert_eq!(playing_music(&state), vec![MUS_NEW4]);
        // The prologue track ends by itself after 1309 ticks; stepping those
        // frames would take minutes of test time, and `tick_count` (which
        // drives the voice's expiry) has no other consumer in the engine.
        state.scene.as_mut().expect("scene").tick_count = 1309;
    }

    let mut after = Vec::new();
    for frame in 0..30 {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        drain(&mut state, frame, &mut after);
    }
    let plays = music_plays(&after);
    assert_eq!(
        plays.len(),
        1,
        "the reopened gate must start exactly one theme for the whole track, \
         got {plays:?}"
    );
    let (_, sound, looping, _) = *plays[0];
    assert!(
        (FIRST_MUSIC..=53).contains(&sound) && sound != MUS_NEW4 as usize,
        "theme[soundplay] is a fresh mus_* track, got {sound}"
    );
    assert!(!looping, "CODE 377 passes looping=false for theme tracks");
    assert_eq!(
        playing_music(&state),
        vec![sound as i32],
        "the new theme must now hold the gate itself"
    );

    // Steady state after the switch: still exactly one command in the next
    // 60 frames (RED: one per frame, with the ids rotating).
    let mut steady = Vec::new();
    for frame in 30..90 {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        drain(&mut state, frame, &mut steady);
    }
    assert_eq!(
        music_plays(&steady).len(),
        0,
        "the started theme must keep the gate shut; got {:?}",
        music_plays(&steady)
    );
}

/// Room-driven music changes must still reach the host: rm_boss1's obj_music
/// Room Start stop_all's the current track and starts mus_bosssong looping
/// (CODE 378), and the looping voice then holds the gate.
#[test]
fn a_room_music_change_still_reaches_the_host() {
    let mut state = boot_like_android();
    let handover = boot_through_prologue(&mut state);
    let mut commands = Vec::new();
    drain(&mut state, handover, &mut commands);

    // The client's own room handoff: consume the queued warp on the next frame.
    state.scene.as_mut().expect("scene").target_room_warp = Some(RM_BOSS1);
    state.step(1.0 / 30.0);
    drain(&mut state, handover + 1, &mut commands);
    let mut after_change = Vec::new();
    for frame in 0..40 {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        drain(&mut state, frame, &mut after_change);
    }
    commands.extend(after_change);
    assert_eq!(
        scene(&state).current_room as usize,
        RM_BOSS1,
        "the warp must land in rm_boss1"
    );

    let plays = music_plays(&commands);
    assert!(
        plays
            .iter()
            .any(|(_, sound, looping, _)| *sound == MUS_BOSSSONG as usize && *looping),
        "the boss theme must reach the host as a looping mus_* command, got {plays:?}"
    );
    assert_eq!(
        plays.len(),
        2,
        "the prologue backlog (one mus_new4 issue) plus exactly one boss-theme \
         command — not one per frame; got {plays:?}"
    );
    assert_eq!(
        plays[0].1,
        MUS_NEW4 as usize,
        "plays[0] is the prologue backlog, got {plays:?}"
    );
    assert_eq!(
        (plays[1].1, plays[1].2),
        (MUS_BOSSSONG as usize, true),
        "plays[1] is the single looping boss-theme issue, got {plays:?}"
    );
    assert_eq!(
        playing_music(&state),
        vec![MUS_BOSSSONG],
        "the boss theme is the live voice after the room change"
    );
}
