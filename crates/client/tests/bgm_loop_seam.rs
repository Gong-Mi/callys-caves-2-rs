//! BGM channel seam: the sound queue must carry the original bytecode's
//! looping flag so the Android host can route mus_* to MediaPlayer with
//! setLooping, instead of flattening everything into one-shot SoundPool sfx.
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

#[test]
fn sound_queue_carries_loop_flag_for_bgm_routing() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");

    // Original bytecode semantics: mus_townmusic (SOND id 32) plays looping.
    state.scene.as_mut().unwrap().call_audio_play(32.0, 0.0, true);
    // A one-shot sfx (snd_coin, SOND id 19) must stay non-looping.
    state.scene.as_mut().unwrap().call_audio_play(19.0, 0.0, false);

    state.step(1.0 / 60.0);

    assert_eq!(
        state.poll_sound(),
        Some((32, true, false)),
        "BGM command must surface its looping flag for MediaPlayer routing"
    );
    assert_eq!(
        state.poll_sound(),
        Some((19, false, false)),
        "sfx command must stay one-shot for SoundPool"
    );
    assert_eq!(state.poll_sound(), None);

    // Original BGM switching: stop_sound(mus_townmusic) then a fresh play.
    // The stop must reach the host as its own command or the old BGM loops
    // forever under the new one.
    state.scene.as_mut().unwrap().call_audio_stop_sound(32.0);
    state.scene.as_mut().unwrap().call_audio_play(51.0, 0.0, true); // mus_bosssong
    state.step(1.0 / 60.0);
    assert_eq!(state.poll_sound(), Some((32, false, true)), "stop_sound must produce a host stop command");
    assert_eq!(state.poll_sound(), Some((51, true, false)));
    assert_eq!(state.poll_sound(), None);
}
