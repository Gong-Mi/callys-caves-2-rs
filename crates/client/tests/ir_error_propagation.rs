use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::{code_vm::{Bundle, Event, Object}, ir_scene::Scene};
use std::{path::Path, sync::Arc};

fn state_with_event(event_type: i32, intro: bool) -> GameState {
    let mut state = GameState::new(&Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid")).unwrap();
    // The prologue lives inside the full scene since the real Game Start boot:
    // object 137 alive makes step_inner run the intro phase, so injecting the
    // broken event on 137 exercises the intro phase and 9999 (a plain fixture
    // instance added to the same scene) exercises the gameplay phase.
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
    state.full_bundle = Some(bundle);
    state.scene = Some(scene);
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
    assert!(state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive));
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
        let before = format!("{:?}", &state.scene);
        for _ in 0..3 { state.step(1.0 / 60.0); }
        assert_eq!(state.runtime_diagnostic.as_deref(), Some(diagnostic.as_str()));
        assert_eq!(format!("{:?}", &state.scene), before);
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
    // The single-scene boot has no handover rebuild anymore: when the intro
    // dies and the queued restore fails, the failure surfaces and the frame
    // halts — the legacy world path is never touched.
    let mut state = GameState::new(&Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(
        &Path::new(env!("CARGO_MANIFEST_DIR")).join("../core/src/generated/full_ir.json")
    ).unwrap();
    // Break the Room Start the cross-room restore dispatches at handover.
    let mut player = bundle.objects.iter().find(|o| o.id == 0).unwrap().clone();
    // Replace (not append) the Room Start event: dispatch finds the FIRST
    // matching event, so an appended duplicate would never run.
    player.events.retain(|e| !(e.event_type == 7 && e.subtype == 4));
    player.events.push(Event { event_type: 7, subtype: 4, codes: vec![987654] });
    bundle.objects.retain(|o| o.id != 0);
    bundle.objects.push(player);
    assert!(state.queue_boot_ir_restore_with(callys_core::save::SaveData {
        format_version: callys_core::save::CURRENT_SAVE_VERSION,
        current_room: 1,
        checkpoint: callys_core::Checkpoint { room_index: 1, x: 0.0, y: 0.0 },
        max_health: 4, gems: 0, coins: 0,
        current_weapon: callys_core::WeaponType::Pistol,
        unlocked_weapons: vec![callys_core::WeaponType::Pistol],
        collected_instance_ids: Vec::new(),
        scene_globals: [("maxhp".to_string(), 5.0)].into_iter().collect(),
        score: 3.0,
    }));
    state.enable_ir_gameplay(Arc::new(bundle)).unwrap();
    // Real intro lifecycle: alarm[0]=120 gate, then the tap that kills it.
    for _ in 0..125 {
        state.step(1.0 / 60.0);
        assert_eq!(state.runtime_diagnostic, None);
    }
    state.input.tap = true;
    let before = state.world.player.x;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    let error = state.runtime_diagnostic.as_deref().unwrap();
    assert!(error.contains("handover restore"), "{error}");
    assert!(error.contains("missing CODE body"), "{error}");
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
    state.retire_prologue();
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
