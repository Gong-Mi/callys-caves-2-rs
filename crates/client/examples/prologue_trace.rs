//! Temporary trace: step the boot scene tick by tick and report exactly when
//! obj_introduction (137) dies with no input, plus the mouse/taplock state at
//! the transition. Deterministic host reproduction of the device "ghost
//! retire" (the film reportedly ends at ~f125-143 with zero input).
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::sync::Arc;

fn main() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap(),
    );
    state.enable_ir_gameplay(bundle).unwrap();

    let mut prev_alive = true;
    for frame in 0..240 {
        state.step(1.0 / 60.0);
        let scene = state.scene.as_ref().unwrap();
        let alive = scene.instances.values().any(|i| i.object == 137 && i.alive);
        let active = scene.instances.values().filter(|i| i.alive && i.active).count();
        let mouse = scene.mouse_pressed;
        let taplock = scene
            .instances
            .values()
            .find(|i| i.object == 137)
            .and_then(|i| i.fields.get("taplock").copied());
        if alive != prev_alive || frame % 30 == 0 {
            println!(
                "f{frame:3} intro_alive={alive} active={active} mouse_pressed={mouse} taplock={taplock:?} diag={:?}",
                state.runtime_diagnostic
            );
        }
        if state.runtime_diagnostic.is_some() {
            break;
        }
        prev_alive = alive;
    }
    println!("done");
}
