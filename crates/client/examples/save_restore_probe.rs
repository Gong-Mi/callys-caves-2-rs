//! Temporary probe: replicate ir_save_roundtrip's autosave/cold-restore flow
//! with full instance accounting around the restore, to pin why CODE 361's
//! sweep read has no receiver on room 1 after a cold restore.
use callys_asset::GameDroidAsset;
use callys_client::{load_save, save_path_for_asset, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::sync::Arc;

fn summarize(tag: &str, state: &GameState) {
    let scene = state.scene.as_ref().unwrap();
    let player = scene.instances.values().filter(|i| i.object == 0 && i.alive).count();
    let alive = scene.instances.values().filter(|i| i.alive && !i.external).count();
    let dead: Vec<i32> = scene.instances.iter().filter(|(_, i)| !i.alive).map(|(&id, _)| id).collect();
    let bg = scene.instances.iter().filter(|(_, i)| i.object == 65 && i.alive).count();
    println!("[{tag}] room={} player_alive={} alive={} bg_alive={} dead_ids={:?}",
        scene.current_room, player, alive, bg, dead);
}

fn main() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"));
    let dir = std::env::temp_dir().join(format!("cally-probe-save-{}", std::process::id()));
    let _ = std::fs::remove_dir_all(&dir);
    std::fs::create_dir_all(&dir).unwrap();
    let droid = dir.join("game.droid");
    std::fs::copy(root.join("../../assets/game.droid"), &droid).unwrap();
    let bundle = Arc::new(load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap());
    let asset = GameDroidAsset::parse(&root.join("../../assets/game.droid")).unwrap();
    let level1 = &asset.rooms[1];
    println!("level1 objects contain obj_player(0)? {}", level1.objects.iter().any(|o| o.object_id == 0));

    let mut live = GameState::new_persistent(&droid).unwrap();
    live.enable_ir_gameplay(bundle.clone()).unwrap();
    live.retire_prologue();
    summarize("live-after-retire", &live);
    {
        let scene = live.scene.as_mut().unwrap();
        scene.target_room_warp = Some(1);
        scene.transition_to_room(bundle.as_ref(), 1, level1).unwrap();
        scene.score = 123.0;
        scene.globals.insert("haskey".into(), 1.0);
    }
    summarize("live-after-transition", &live);
    live.step(1.0 / 60.0);
    println!("live diag after 1 step = {:?}", live.runtime_diagnostic);
    summarize("live-after-1step", &live);
    let path = save_path_for_asset(&droid);
    let saved = load_save(&path).unwrap().expect("autosave file");
    println!("save: room={} score={} collected({})={:?}", saved.current_room, saved.score,
        saved.collected_instance_ids.len(), saved.collected_instance_ids);

    let mut cold = GameState::new_persistent(&droid).unwrap();
    cold.enable_ir_gameplay(bundle.clone()).unwrap();
    cold.retire_prologue();
    summarize("cold-after-retire", &cold);
    let save = load_save(&path).unwrap().unwrap();
    cold.restore_ir_snapshot(&save).unwrap();
    summarize("cold-after-restore", &cold);
    for f in 0..10 {
        cold.step(1.0 / 60.0);
        println!("cold frame {f}: diag={:?}", cold.runtime_diagnostic);
        if cold.runtime_diagnostic.is_some() {
            summarize("cold-at-halt", &cold);
            break;
        }
    }
    let _ = std::fs::remove_dir_all(&dir);
}
