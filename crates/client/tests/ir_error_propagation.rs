use callys_client::GameState;
use callys_core::{code_vm::{Bundle, Event, Object}, ir_scene::Scene};
use std::{path::Path, sync::Arc};

fn state_with_event(event_type: i32, intro: bool) -> GameState {
    let mut state = GameState::new(&Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid")).unwrap();
    let object = if intro { 137 } else { 9999 };
    let bundle = Arc::new(Bundle {
        schema: 1, string_table: vec![], room_bindings: vec![], codes: vec![],
        objects: vec![Object {
            id: object, name: "error_fixture".into(), sprite: -1, depth: 0,
            parent: -100, parent_chain: vec![],
            events: vec![Event { event_type, subtype: 0, codes: vec![987654] }],
        }],
    });
    let mut scene = Scene::default();
    scene.create(&bundle, object, 0.0, 0.0).unwrap();
    if intro {
        state.intro_bundle = Some(bundle);
        state.intro_scene = Some(scene);
    } else {
        state.full_bundle = Some(bundle);
        state.scene = Some(scene);
    }
    state
}

#[test]
fn failed_gameplay_tick_does_not_commit_frame_or_transition() {
    let mut state = state_with_event(3, false);
    state.scene.as_mut().unwrap().target_room_warp = Some(1);
    state.step(1.0 / 60.0);
    assert_eq!(state.frame_count, 0, "failed tick must not count as completed frame");
    assert_eq!(state.rooms_visited, 1, "failed tick must not execute pending warp");
    assert_eq!(state.scene.as_ref().unwrap().target_room_warp, Some(1));
}

#[test]
fn failed_gameplay_draw_does_not_commit_frame() {
    let mut state = state_with_event(8, false);
    state.step(1.0 / 60.0);
    assert_eq!(state.frame_count, 0, "failed draw must not count as completed frame");
}

#[test]
fn failed_intro_tick_does_not_panic_across_native_boundary() {
    let mut state = state_with_event(3, true);
    state.step(1.0 / 60.0);
    assert!(state.intro_scene.is_some());
    assert!(state.runtime_diagnostic.as_deref().unwrap().contains("intro tick"));
}

#[test]
fn first_error_is_retained_and_failed_scene_is_not_retried() {
    for (event, intro, phase) in [(3, false, "gameplay tick"), (8, false, "gameplay draw"),
                                  (3, true, "intro tick"), (8, true, "intro draw")] {
        let mut state = state_with_event(event, intro);
        state.step(1.0 / 60.0);
        let diagnostic = state.runtime_diagnostic.clone().expect("error must be visible");
        assert!(diagnostic.contains(phase), "{diagnostic}");
        assert!(diagnostic.contains("CODE 987654 @0x0: missing CODE body"), "{diagnostic}");
        let before = format!("{:?}", if intro { &state.intro_scene } else { &state.scene });
        for _ in 0..3 { state.step(1.0 / 60.0); }
        assert_eq!(state.runtime_diagnostic.as_deref(), Some(diagnostic.as_str()));
        assert_eq!(format!("{:?}", if intro { &state.intro_scene } else { &state.scene }), before);
        assert_eq!(state.frame_count, 0);
    }
}

#[test]
fn invalid_warp_is_diagnosed_without_counting_a_visit() {
    let mut state = state_with_event(99, false); // no scheduled event
    state.scene.as_mut().unwrap().target_room_warp = Some(usize::MAX);
    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.as_deref().unwrap().contains("target outside room table"));
    assert_eq!(state.rooms_visited, 1);
    assert_eq!(state.frame_count, 0);
}

#[test]
fn failed_room_create_is_diagnosed_without_counting_a_visit() {
    let mut state = state_with_event(99, false);
    let mut bundle = (*state.full_bundle.as_ref().unwrap().as_ref()).clone();
    // Actual target-room player Create dispatch, deliberately missing CODE.
    let mut player = bundle.objects[0].clone();
    player.id = 0;
    player.events[0].event_type = 0;
    bundle.objects.push(player);
    state.full_bundle = Some(Arc::new(bundle));
    state.scene.as_mut().unwrap().target_room_warp = Some(0);
    state.step(1.0 / 60.0);
    let error = state.runtime_diagnostic.as_deref().unwrap();
    assert!(error.contains("room transition"), "{error}");
    assert!(error.contains("missing CODE body"), "{error}");
    assert_eq!(state.rooms_visited, 1);
    assert_eq!(state.frame_count, 0);
}

#[test]
fn failed_intro_handoff_does_not_fall_back_to_legacy_world() {
    let mut state = state_with_event(99, true);
    state.intro_scene.as_mut().unwrap().instances.clear();
    let mut bundle = (*state.intro_bundle.as_ref().unwrap().as_ref()).clone();
    bundle.objects[0].id = 0;
    bundle.objects[0].events[0].event_type = 0;
    state.full_bundle = Some(Arc::new(bundle));
    let before = state.world.player.x;
    state.input.move_right = true;
    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.as_deref().unwrap().contains("intro gameplay initialization"));
    assert!(state.scene.is_none());
    assert_eq!(state.world.player.x, before);
    assert_eq!(state.frame_count, 0);
}

#[test]
fn real_town_to_level1_frames_remain_error_free() {
    let mut state = state_with_event(99, false);
    let bundle = callys_core::code_vm::load_bundle_from_file(
        &Path::new(env!("CARGO_MANIFEST_DIR")).join("../core/src/generated/full_ir.json")
    ).unwrap();
    state.enable_ir_gameplay(Arc::new(bundle)).unwrap();
    for _ in 0..15 {
        state.step(1.0 / 60.0);
        assert_eq!(state.runtime_diagnostic, None);
    }
    state.scene.as_mut().unwrap().target_room_warp = Some(1);
    for _ in 0..60 {
        state.step(1.0 / 60.0);
        assert_eq!(state.runtime_diagnostic, None);
    }
    assert_eq!(state.scene.as_ref().unwrap().current_room, 1.0);
    assert_eq!(state.frame_count, 75);
}
