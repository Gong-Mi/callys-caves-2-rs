use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{collections::BTreeMap, path::Path, sync::Arc};

#[test]
fn ir_gameplay_uses_one_original_ui_control_set() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset_path = root.join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../../crates/core/src/generated/full_ir.json"))
            .expect("load full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable IR gameplay");
    state.step(1.0 / 60.0);

    let scene = state.scene.as_ref().expect("IR scene");
    for object in [125, 127, 128, 129, 130, 131] {
        assert_eq!(
            scene.instances.values().filter(|i| i.object == object && i.alive).count(),
            1,
            "original UI object {object} must be materialized once"
        );
    }

    let mut sprite_draws = BTreeMap::new();
    for draw in &scene.draws {
        *sprite_draws.entry(draw.sprite).or_insert(0usize) += 1;
    }
    for sprite in [122, 155, 156, 157, 158, 159] {
        assert_eq!(
            sprite_draws.get(&sprite).copied().unwrap_or(0),
            1,
            "original UI sprite {sprite} must be emitted once by IR Draw events"
        );
    }
}
