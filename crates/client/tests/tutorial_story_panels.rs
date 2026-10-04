//! Story-panel verification: walking to obj_lloyd freezes the town and runs
//! the six-panel intro conversation. Every panel's strings must match the
//! original GML of obj_lloydtutorial1 verbatim — a code-side regression on
//! the game's opening narrative ("剧情介绍") — with the tap unlocking at the
//! alarm[5] end of the panel timeline.
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
use std::sync::Arc;

const PANELS: [&[&str]; 6] = [
    &["Hey Cally! It's me, Lloyd.", "Do you like my song?"],
    &[
        "Hey Cally! It's me, Lloyd.",
        "Do you like my song?",
        "It's nice Lloyd, but I have bad news.",
        "Herbert has my parents again...",
    ],
    &[
        "Oh no... Well if I know Herbert",
        "He took them to the bottom of the Caves.",
    ],
    &[
        "But you're the strongest girl I know,",
        "I will help you rescue them!",
    ],
    &[
        "Thanks Lloyd! You are a good friend...",
        "And decent guitarist.",
    ],
    &[
        "No problem buddy. Head on through this",
        "door, and I'll see you in a bit.",
    ],
];

fn boot_reached_lloyd() -> (GameState, i32) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap(),
    );
    state.enable_ir_gameplay(bundle).unwrap();
    // Enter through the same opening and controls as production. No
    // retire_prologue(), coordinate write or direct event dispatch shortcut.
    for _ in 0..125 { state.step(1.0 / 30.0); }
    assert!(state.scene.as_ref().unwrap().instances.values().any(|i| i.object == 137 && i.alive));
    state.input.tap = true;
    state.step(1.0 / 30.0);
    state.input.tap = false;
    state.step(1.0 / 30.0);
    state.input.move_right = true;
    for _ in 0..300 {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        let sheet = state.scene.as_ref().unwrap().instances.iter()
            .find(|(_, i)| i.object == 138 && i.alive).map(|(&id, _)| id);
        if let Some(sheet) = sheet {
            state.input.move_right = false;
            return (state, sheet);
        }
    }
    panic!("ordinary movement never reached the original Lloyd story gate");
}

#[test]
fn the_town_story_plays_its_six_panels_verbatim() {
    let (mut state, sheet) = boot_reached_lloyd();
    let scene = state.scene.as_ref().unwrap();
    let view = scene.active_view_index().unwrap() as i32;
    let frozen_origin = scene.view_positions[&view];
    let mut seen: [Option<Vec<String>>; 6] = Default::default();
    for _ in 0..640 {
        state.step(1.0 / 30.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        let scene = state.scene.as_ref().unwrap();
        assert_eq!(scene.view_positions[&view], frozen_origin, "all story panels keep the same camera");
        let Some(inst) = scene.instances.get(&sheet) else { break };
        if !inst.alive {
            break;
        }
        for p in 1..=6usize {
            if inst.fields.get(&format!("drawpanel{p}")).copied() == Some(1.0)
                && seen[p - 1].is_none()
            {
                seen[p - 1] = Some(scene.texts.iter().map(|t| t.text.clone()).collect());
            }
        }
    }
    for (i, expected) in PANELS.iter().enumerate() {
        let observed = seen[i]
            .as_ref()
            .unwrap_or_else(|| panic!("panel {} never became active", i + 1));
        let expected: Vec<String> = expected.iter().map(|s| s.to_string()).collect();
        assert_eq!(observed, &expected, "panel {} strings must match the GML verbatim", i + 1);
    }
    // The tap unlocks at the end of the panel timeline (alarm[5] = 600 frames).
    let scene = state.scene.as_ref().unwrap();
    let inst = scene.instances.get(&sheet).expect("sheet alive");
    assert_eq!(inst.fields.get("taplock").copied(), Some(1.0), "tap unlocks at alarm[5]");
    assert!(
        scene.texts.iter().any(|t| t.text == "Tap to Continue"),
        "the unlock frame shows the Tap to Continue prompt"
    );
    assert!(seen.iter().all(|p| p.is_some()), "all six panels observed");
}
