//! Original runner contracts, not remake-recorded golden hashes:
//! CameraUpdate returns without rewriting the camera when its target is
//! deactivated; a Draw event and its rasterization share one view transform.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::{code_vm::load_bundle_from_file, ir_scene::Scene};
use std::{path::Path, sync::Arc};

fn alive(scene: &Scene, object: i32) -> Option<i32> {
    scene.instances.iter().find(|(_, i)| i.object == object && i.alive).map(|(&id, _)| id)
}
fn frame(state: &mut GameState) {
    state.step(1.0 / 30.0);
    assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
}
fn boot() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut s = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let b = load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap();
    s.enable_ir_gameplay(Arc::new(b)).unwrap();
    // No retire_prologue(), teleport, dispatch shortcut, saved-state injection.
    for _ in 0..125 { frame(&mut s); }
    assert!(alive(s.scene.as_ref().unwrap(), 137).is_some());
    s.input.tap = true;
    frame(&mut s);
    s.input.tap = false;
    frame(&mut s);
    assert!(alive(s.scene.as_ref().unwrap(), 137).is_none());
    s
}
fn walk_into_story() -> (GameState, i32, (f64, f64)) {
    let mut s = boot();
    s.input.move_right = true;
    for _ in 0..300 {
        let scene = s.scene.as_ref().unwrap();
        let v = scene.active_view_index().unwrap() as i32;
        let previous = scene.view_positions[&v];
        frame(&mut s);
        if let Some(sheet) = alive(s.scene.as_ref().unwrap(), 138) {
            s.input.move_right = false;
            assert!(previous.0 > 0.0 && previous.1 > 0.0, "fixture reached Lloyd in a scrolled view");
            return (s, sheet, previous);
        }
    }
    panic!("normal movement never reached the opening story");
}
fn render(s: &GameState) -> Framebuffer {
    let mut fb = Framebuffer::new(1136, 640);
    draw_frame(&mut fb, s, &s.asset.tpag_items, &s.asset.sprites);
    fb
}
#[test]
fn natural_story_entry_keeps_the_last_camera_instead_of_resetting_to_room_origin() {
    let (mut s, sheet, previous) = walk_into_story();
    let scene = s.scene.as_ref().unwrap();
    let view = scene.active_view_index().unwrap() as i32;
    let player = alive(scene, 0).unwrap();
    assert!(!scene.instances[&player].active);
    assert_eq!(scene.view_positions[&view], previous, "story deactivation must freeze the current camera");
    let actual: Vec<_> = scene.texts.iter().filter(|t| t.code == 564).map(|t| t.text.as_str()).collect();
    assert_eq!(actual, ["Hey Cally! It's me, Lloyd.", "Do you like my song?"]);
    for _ in 0..15 { frame(&mut s); }
    let scene = s.scene.as_ref().unwrap();
    assert!(scene.instances[&sheet].alive);
    assert_eq!(scene.view_positions[&view], previous, "the frozen story must not drift");
}
#[test]
fn natural_story_exit_rasterizes_the_draw_event_that_reactivated_the_world() {
    let (mut s, sheet, _) = walk_into_story();
    for _ in 0..610 { frame(&mut s); }
    assert_eq!(s.scene.as_ref().unwrap().instances[&sheet].fields["taplock"], 1.0);
    // Actual client pointer-return boundary, not destroy()/manual alarm dispatch.
    s.pointer_released(568.0, 320.0);
    frame(&mut s);
    let scene = s.scene.as_ref().unwrap();
    assert!(!scene.instances[&sheet].alive);
    let player = alive(scene, 0).unwrap();
    assert!(scene.instances[&player].active);
    assert!(scene.texts.iter().any(|t| t.code == 564 && t.text == "Tap to Continue"));
    let fb = render(&s);
    let visible = fb.pixels.chunks_exact(4).filter(|p| p[..3] != [30, 18, 15]).count();
    assert!(visible > 1000, "story exit frame must not become an all-clear frame; visible={visible}");
    frame(&mut s);
    assert!(s.runtime_diagnostic.is_none());
}
#[test]
fn rasterization_does_not_re_follow_a_target_changed_after_draw_emission() {
    let mut s = boot();
    let before = render(&s);
    let scene = s.scene.as_mut().unwrap();
    let player = alive(scene, 0).unwrap();
    // A Draw event can change this live state after earlier commands were
    // emitted; presentation must not retroactively change their projection.
    scene.instances.get_mut(&player).unwrap().fields.insert("x".into(), 900.0);
    scene.instances.get_mut(&player).unwrap().fields.insert("y".into(), 200.0);
    let after = render(&s);
    assert!(before.pixels == after.pixels, "rasterization must consume the command frame's view, not recalculate follow");
}
