//! Regression: the client main loop must drain audio through
//! Scene::drain_audio (voice ledger retire) instead of a bare
//! scene.audio.drain(..), which left non-looping voices alive forever and
//! permanently closed the original audio_is_playing gates.
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

#[test]
fn game_loop_drain_reopens_audio_gates() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir"));
    state.enable_ir_gameplay(bundle.clone()).expect("enable IR gameplay");

    let s = state.scene.as_mut().unwrap();
    // Open a non-looping voice the way the original bytecode would.
    s.call_audio_play(5.0, 0.0, false);
    assert_eq!(s.audio_is_playing_sound(5.0), true);

    // One client step must consume the audible command AND retire the
    // non-looping voice, reopening the original gate.
    state.step(1.0 / 60.0);
    let s = state.scene.as_ref().unwrap();
    assert!(s.audio.is_empty(), "client step must drain audible commands");
    assert_eq!(
        s.audio_is_playing_sound(5.0),
        false,
        "non-looping voice must retire after the client drains, reopening is_playing gates"
    );
}
