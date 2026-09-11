use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, sync::Arc};

#[test]
fn death_release_unlocks_once_and_resumes_original_room() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap();
    let death_object = bundle.objects.iter().find(|o| o.name == "obj_youhavedied").unwrap().id;
    state.enable_ir_gameplay(Arc::new(bundle)).unwrap();
    state.scene.as_mut().unwrap().target_room_warp = Some(1);
    state.step(1.0 / 60.0);
    assert_eq!(state.runtime_diagnostic, None);
    state.scene.as_mut().unwrap().globals.insert("health1".into(), 1.0);
    state.step(1.0 / 60.0);
    assert_eq!(state.runtime_diagnostic, None);
    let death = *state.scene.as_ref().unwrap().instances.iter()
        .find(|(_, i)| i.object == death_object && i.alive).unwrap().0;
    // Original Draw places the screen-covering death sprite at view origin.
    state.pointer_released(10.0, 10.0);
    state.step(1.0 / 60.0);
    assert!(state.scene.as_ref().unwrap().instances[&death].alive);
    assert!(state.scene.as_ref().unwrap().left_releases.is_empty(), "early release must be consumed, not deferred until unlock");
    for _ in 0..69 {
        state.step(1.0 / 60.0);
        assert_eq!(state.runtime_diagnostic, None);
    }
    assert_eq!(state.scene.as_ref().unwrap().instances[&death].fields["taplock"], 1.0);
    assert!(state.scene.as_ref().unwrap().texts.iter().any(|t| t.text == "Tap to Continue"));
    let visits = state.rooms_visited;
    state.pointer_released(10.0, 10.0);
    state.step(1.0 / 60.0);
    assert_eq!(state.runtime_diagnostic, None);
    let scene = state.scene.as_ref().unwrap();
    assert!(!scene.instances.values().any(|i| i.object == death_object && i.alive), "actual release must dispatch Mouse_7 and restart room");
    assert_eq!(scene.current_room, 1.0);
    assert_eq!(scene.globals["health1"], 4.0);
    assert_eq!(state.rooms_visited, visits + 1);
    for _ in 0..15 {
        state.step(1.0 / 60.0);
        assert_eq!(state.runtime_diagnostic, None);
    }
    assert_eq!(state.rooms_visited, visits + 1, "release must not repeat");
}
