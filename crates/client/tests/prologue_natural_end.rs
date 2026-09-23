//! P0 completion condition: the prologue's NATURAL run — no tap until the
//! film reaches its end state. Bytecode facts (CODE 548/550-555, full_ir.json):
//! alarm[0]=120 unlocks taplock; alarm[1]=30 stops the fast scroll (moving=0,
//! moving2=1); alarm[3]=70 stops the slow scroll (moving2=0); alarm[2]=70
//! spawns obj_logo (135) at (50, 0); the Step scrolls xx1..xx4 while
//! moving/moving2 say so; ONLY a mouse press with taplock==1 destroys the
//! intro (CODE 554 tail). Death is impossible without a tap — the original
//! gate is a real input, not a timer.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

fn intro(state: &GameState) -> &callys_core::ir_scene::Instance {
    state
        .scene
        .as_ref()
        .unwrap()
        .instances
        .values()
        .find(|i| i.object == 137 && i.alive)
        .expect("intro alive")
}

#[test]
fn prologue_natural_timeline_unlocks_tap_and_only_a_tap_ends_it() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState::new");
    let full_ir_path = Path::new(manifest_dir).join("../../crates/core/src/generated/full_ir.json");
    state
        .enable_ir_gameplay(Arc::new(load_bundle_from_file(&full_ir_path).expect("load full_ir")))
        .expect("enable_ir_gameplay");

    // Film scroll phase 1 (moving=1): xx1..xx4 decrement by 2 per Step.
    let xx_before = intro(&state).fields["xx1"];
    for _ in 0..20 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    }
    assert_eq!(
        intro(&state).fields["xx1"],
        xx_before - 40.0,
        "moving=1 scrolls xx1 by -2 per frame"
    );

    // alarm[1] fires at frame 30: moving=0, moving2=1 — the slow scroll phase.
    // Measure the per-frame delta inside the phase instead of assuming the
    // phase boundary lands on a block edge: step one frame at a time until
    // moving has flipped, then assert the slow rate (-1/frame).
    let _ = intro(&state).fields["xx1"];
    let mut rate_samples: Vec<f64> = Vec::new();
    for _ in 0..40 {
        let before = intro(&state).fields["xx1"];
        let moving_before = intro(&state).fields["moving"];
        state.step(1.0 / 60.0);
        let after = intro(&state).fields["xx1"];
        if moving_before == 0.0 && intro(&state).fields["moving2"] == 1.0 {
            rate_samples.push(before - after);
        }
        if intro(&state).fields["moving2"] == 0.0 && !rate_samples.is_empty() {
            break;
        }
    }
    assert!(
        !rate_samples.is_empty() && rate_samples.iter().all(|&d| (d - 1.0).abs() < f64::EPSILON),
        "phase 2 (moving2=1) scrolls xx1 by -1 per frame, got {rate_samples:?}"
    );

    // alarm[2] fires around frame 69-70: run past it, then obj_logo (135) exists.
    for _ in 0..20 {
        state.step(1.0 / 60.0);
    }
    assert!(
        state
            .scene
            .as_ref()
            .unwrap()
            .instances
            .values()
            .any(|i| i.object == 135 && i.alive),
        "alarm[2]=70 spawns obj_logo into the scene"
    );

    // alarm[3] fired at frame 70: moving2=0 — the scroll is over.
    let xx_end = intro(&state).fields["xx1"];
    for _ in 0..30 {
        state.step(1.0 / 60.0);
    }
    assert_eq!(
        intro(&state).fields["xx1"], xx_end,
        "after alarm[3] the film is parked (no scroll)"
    );

    // alarm[0] fires around frame 119: wait for taplock=1 (the film's end
    // state), then verify the intro STILL waits for input — no timer death
    // exists in CODE 554.
    let mut taplock_frames = 0;
    let mut parked_frames = 0;
    let xx_parked;
    loop {
        let xx_before = intro(&state).fields["xx1"];
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        if intro(&state).fields["xx1"] == xx_before {
            parked_frames += 1;
        }
        taplock_frames += 1;
        if intro(&state).fields["taplock"] == 1.0 {
            break;
        }
        assert!(taplock_frames < 300, "taplock never unlocked");
    }
    xx_parked = intro(&state).fields["xx1"];
    assert!(parked_frames > 0, "the film parks before taplock unlocks");
    let _ = xx_parked;
    for _ in 0..40 {
        state.step(1.0 / 60.0);
    }
    assert!(
        state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive),
        "the intro never dies without a tap (CODE 554 has no timer death)"
    );

    // A real tap now retires it through Destroy 549: same scene continues.
    let intro_alive = |s: &GameState| {
        s.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive)
    };
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    state.step(1.0 / 60.0);
    assert!(!intro_alive(&state), "the tap ends the film");
    assert_eq!(
        state.scene.as_ref().unwrap().globals.get("health1").copied(),
        Some(4.0),
        "CODE 549 sets global.health1=4 at the handover"
    );
    assert_eq!(state.scene.as_ref().unwrap().current_room, 0.0,
        "the same scene continues into town");

    // The rendered frame after the handover is town, not the film.
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
    let non_zero = fb.pixels.iter().filter(|&&p| p != 0).count();
    assert!(non_zero > 1000, "town renders after the natural film end, got {non_zero}");
}
