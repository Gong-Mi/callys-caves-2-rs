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
    state.retire_prologue();
    let (lx, ly) = {
        let scene = state.scene.as_ref().unwrap();
        let lloyd = scene
            .instances
            .values()
            .find(|i| i.object == 154 && i.alive)
            .expect("rm_town contains obj_lloyd");
        (lloyd.fields["x"], lloyd.fields["y"])
    };
    {
        let scene = state.scene.as_mut().unwrap();
        let player = scene
            .instances
            .values_mut()
            .find(|i| i.object == 0 && i.alive)
            .expect("live player");
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
        .find(|(_, i)| i.object == 138 && i.alive)
        .map(|(&id, _)| id)
        .expect("obj_lloyd hands over to obj_lloydtutorial1");
    (state, sheet)
}

#[test]
fn the_town_story_plays_its_six_panels_verbatim() {
    let (mut state, sheet) = boot_reached_lloyd();
    let mut seen: [Option<Vec<String>>; 6] = Default::default();
    for _ in 0..640 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        let scene = state.scene.as_ref().unwrap();
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
