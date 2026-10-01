use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

#[test]
fn draw_view_dispatches_event_8_subtype_65_draw_gui() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir.json"));

    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();

    // Create obj_viewresolution (id 133), which owns Event 8 Subtype 65 (CODE 539)
    let _res_id = scene.create(&bundle, 133, 0.0, 0.0).expect("create obj_viewresolution");
    scene.view_positions.insert(0, (0.0, 0.0));

    // Clear executed trace before draw pass
    scene.executed.clear();

    // Run draw pass on view 0
    scene.draw_view(&bundle, 0).expect("draw_view must succeed");

    // Assert CODE 539 was executed during the Draw GUI pass
    let code_539_executed = scene.executed.iter().any(|(code, _)| *code == 539);
    assert!(
        code_539_executed,
        "draw_view must dispatch Event 8 Subtype 65 (CODE 539 on obj_viewresolution), executed: {:?}",
        scene.executed
    );
}
