use std::path::{Path, PathBuf};

use callys_client::GameState;
use callys_core::{PlayerState, PROVISIONAL_SPIKE_DAMAGE};

fn game_droid_path() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid")
}

fn enter_warp(state: &mut GameState, creation_code: i32) {
    let warp = state
        .world
        .warps
        .iter()
        .find(|warp| warp.creation_code == creation_code)
        .cloned()
        .unwrap_or_else(|| panic!("room must contain warp creation code {creation_code}"));
    state.world.player.x = warp.rect.x;
    state.world.player.y = warp.rect.y;
    state.step(0.0);
}

#[test]
fn town_to_level2_spike_death_reloads_level2_checkpoint() {
    let mut state = GameState::new(&game_droid_path()).unwrap();
    assert_eq!(state.world.current_room_name, "rm_town");

    enter_warp(&mut state, 804);
    assert_eq!(state.world.current_room_name, "rm_level1");

    enter_warp(&mut state, 805);
    assert_eq!(state.world.current_room_index, 2);
    assert_eq!(state.world.current_room_name, "rm_level2");
    assert_eq!(state.world.checkpoint.room_index, 2);
    assert_eq!(
        (state.world.checkpoint.x, state.world.checkpoint.y),
        (128.0, 492.0)
    );
    assert_eq!(
        (state.world.player.x, state.world.player.y),
        (128.0, 492.0)
    );

    assert_eq!(state.world.hazards.len(), 27);
    assert!(state.world.hazards.iter().all(|hazard| {
        state
            .world
            .decorations
            .iter()
            .any(|decoration| {
                decoration.rect == hazard.rect && decoration.sprite_id == hazard.sprite_id
            })
    }));

    let spike = state.world.hazards[0];
    state.world.player.x = spike.rect.x;
    state.world.player.y = spike.rect.y;
    state.world.player.health = PROVISIONAL_SPIKE_DAMAGE;

    state.step(0.0);
    assert_eq!(state.world.player.state, PlayerState::Dead);
    assert!(state.world.player.invulnerable_timer > 0.0);

    state.step(1.1);
    assert_eq!(state.world.current_room_index, 2);
    assert_eq!(state.world.current_room_name, "rm_level2");
    assert_eq!(
        (state.world.player.x, state.world.player.y),
        (128.0, 492.0)
    );
    assert_eq!(state.world.player.health, state.world.player.max_health);
    assert_eq!(state.world.hazards.len(), 27);
}
