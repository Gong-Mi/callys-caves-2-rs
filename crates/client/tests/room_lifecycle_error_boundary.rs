use callys_client::GameState;
use callys_core::code_vm::{load_bundle_from_file, Event};
use std::{path::Path, sync::Arc};

fn assert_boundary(subtype: i32) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap();
    state.enable_ir_gameplay(Arc::new(bundle)).unwrap();
    let mut bundle = state.full_bundle.as_ref().unwrap().as_ref().clone();
    let player = bundle.objects.iter_mut().find(|o| o.id == 0).unwrap();
    player.events.retain(|e| !(e.event_type == 7 && e.subtype == subtype));
    player.events.push(Event { event_type:7, subtype, codes:vec![987654] });
    state.full_bundle = Some(Arc::new(bundle));
    state.scene.as_mut().unwrap().target_room_warp = Some(1);
    state.step(1.0 / 60.0);
    let error = state.runtime_diagnostic.as_deref().expect("lifecycle failure must reach client");
    assert!(error.contains("room transition") && error.contains("CODE 987654"), "{error}");
    assert_eq!(state.frame_count,0);
    assert_eq!(state.rooms_visited,1);
}

#[test]
fn room_end_error_reaches_client_halt_boundary() { assert_boundary(5); }

#[test]
fn room_start_error_reaches_client_halt_boundary() { assert_boundary(4); }
