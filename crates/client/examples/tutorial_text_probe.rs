//! Code-side verification: walk to Lloyd, then dump the tutorial sheet's
//! emitted texts (strings/fonts/positions) across the 6-panel timeline
//! (alarm[0..5] at 100-frame steps) and compare verbatim against the
//! recovered GML of obj_lloydtutorial1.
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
    state.retire_prologue();

    // Stand the player next to obj_lloyd (154) to trip the proximity gate
    // (CODE 675, distance < 100).
    let (lx, ly) = {
        let scene = state.scene.as_ref().unwrap();
        let lloyd = scene.instances.values().find(|i| i.object == 154 && i.alive).expect("lloyd");
        (lloyd.fields["x"], lloyd.fields["y"])
    };
    {
        let scene = state.scene.as_mut().unwrap();
        let player = scene
            .instances
            .values_mut()
            .find(|i| i.object == 0 && i.alive)
            .expect("player");
        player.fields.insert("x".into(), lx + 40.0);
        player.fields.insert("y".into(), ly);
    }
    for _ in 0..40 {
        state.step(1.0 / 60.0);
    }
    let sheet = state
        .scene
        .as_ref()
        .unwrap()
        .instances
        .iter()
        .find(|(_, i)| (138..=153).contains(&i.object) && i.alive)
        .map(|(&id, i)| (id, i.object));
    let Some((sheet_id, sheet_obj)) = sheet else {
        println!("NO SHEET appeared");
        return;
    };
    println!("sheet obj={sheet_obj} id={sheet_id} appeared");

    let mut frame = 0usize;
    for sample in 0..14 {
        for _ in 0..50 {
            state.step(1.0 / 60.0);
            frame += 1;
        }
        let scene = state.scene.as_ref().unwrap();
        let alive = scene.instances.get(&sheet_id).map(|i| i.alive).unwrap_or(false);
        let flags: Vec<(&str, f64)> = scene
            .instances
            .get(&sheet_id)
            .map(|i| {
                (1..=6)
                    .filter_map(|p| {
                        i.fields
                            .get(&format!("drawpanel{p}"))
                            .map(|v| (Box::leak(format!("panel{p}").into_boxed_str()) as &str, *v))
                    })
                    .collect()
            })
            .unwrap_or_default();
        let taplock = scene.instances.get(&sheet_id).and_then(|i| i.fields.get("taplock").copied());
        println!("--- f{frame} sheet_alive={alive} taplock={taplock:?} flags={flags:?}");
        for t in &scene.texts {
            println!("    text font={} ({:.0},{:.0}) {:?}", t.font, t.x, t.y, t.text);
        }
        if !alive {
            break;
        }
    }
}
