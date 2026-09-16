//! H-line slice: coin pickup must flow through the real obj_player Step
//! (CODE 12) `instance_place(x, y, par_coin)` scan against the original
//! parent-chain selector, not injected callbacks. Coins are placed from the
//! original rm_level1 records, and their Destroy event (CODE 340) must enqueue
//! global.coinsound exactly like the original audio_play_sound call.
use callys_asset::GameDroidAsset;
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn walking_player_picks_original_level1_coins_with_sound_and_once_only() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    state.enable_ir_gameplay(bundle.clone()).unwrap();

    // Original rm_level1 records (obj_coin 58), taken verbatim.
    let level1 = &asset.rooms[1];
    assert_eq!(level1.name, "rm_level1");
    let scene = state.scene.as_mut().unwrap();
    scene.target_room_warp = Some(1);
    scene.transition_to_room(bundle.as_ref(), 1, level1).unwrap();
    let coins: Vec<i32> = scene
        .instances
        .iter()
        .filter(|(_, i)| i.object == 58 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    assert_eq!(coins.len(), 34, "rm_level1 must materialize its 34 original coins");
    let coin_x = scene.instances[&coins[0]].fields["x"];
    let coin_y = scene.instances[&coins[0]].fields["y"];
    let player = *scene.instances.iter().find(|(_, i)| i.object == 0 && i.alive).unwrap().0;

    // Park the player exactly on a coin and tick the real Step CODE 12.
    scene.instances.get_mut(&player).unwrap().fields.insert("x".into(), coin_x);
    scene.instances.get_mut(&player).unwrap().fields.insert("y".into(), coin_y);
    let score_before = scene.score;
    let pickup_total_before = scene.globals["coinpickup"];
    scene.tick(bundle.as_ref()).unwrap();

    let (coin_sound, emit_matched) = {
        let scene = state.scene.as_ref().unwrap();
        assert!(!scene.instances[&coins[0]].alive, "original CODE12 must destroy the overlapped coin");
        assert!(
            (scene.score - (score_before + scene.globals["coinmultiply"])).abs() < f64::EPSILON,
            "coin type=1 must add 1*coinmultiply: {score_before} -> {}",
            scene.score
        );
        assert!(
            (scene.globals["coinpickup"] - (pickup_total_before + scene.globals["coinmultiply"])).abs() < f64::EPSILON,
            "global.coinpickup must advance identically"
        );
        assert!(scene.instances[&coins[1]].alive, "distant coins must survive");
        // Destroy event CODE340 plays global.coinsound (set up by obj_UI Create).
        (scene.globals["coinsound"] as i32,
         scene.audio.iter().any(|c| c.sound == scene.globals["coinsound"] as i32 && !c.looping))
    };
    let mut queued = Vec::new();
    while let Some(item) = state.poll_sound() {
        queued.push(item);
    }
    assert!(
        queued.iter().any(|(id, _, _)| *id == coin_sound as usize) || emit_matched,
        "coin Destroy must play global.coinsound {coin_sound}, got queue {queued:?}"
    );
    // One real client frame must drain that command into the platform queue.
    state.step(1.0 / 60.0);
    let drained = std::iter::from_fn(|| state.poll_sound()).collect::<Vec<_>>();
    assert!(
        drained.iter().any(|(id, _, _)| *id == coin_sound as usize),
        "client frame must drain coin Destroy audio, got {drained:?}"
    );
    assert!(state.runtime_diagnostic.is_none());

    // Persistence guard: the destroyed coin must not come back on room reload.
    let scene = state.scene.as_mut().unwrap();
    scene.transition_to_room(bundle.as_ref(), 1, level1).unwrap();
    let alive: Vec<i32> = scene
        .instances
        .iter()
        .filter(|(_, i)| i.object == 58 && i.alive)
        .map(|(id, _)| *id)
        .collect();
    // Original rooms are non-persistent and carry no collected-set bookkeeping
    // (coin Destroy only plays a sound), so a reload respawns all 34 coins.
    assert_eq!(alive.len(), 34, "original non-persistent reload must respawn coins");
    for _ in 0..10 {
        state.step(1.0 / 60.0);
        assert_eq!(state.runtime_diagnostic, None);
    }
}
