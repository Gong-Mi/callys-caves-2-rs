//! Lair trunk progression: room83 -> ... -> rm_boss6 through the shipped
//! obj_warpanywhere door instances only. Chain and BOTH per-room door
//! directions enumerated from the recovered RoomCC creation codes (970..1012)
//! against room_bindings — not guessed from names.
//!
//! Notable deviation from the other trunks: rm_boss6 (room 104) has ONLY a
//! backward card (1012 -> 103) — no forward door. The ending is not a door
//! hop but the boss6 kill chain: hpfinalboss=0 -> Step spawns
//! obj_finalbosspuff (189) -> its Destroy (CODE 787) does
//! instance_deactivate_object(obj_player); room_goto(rm_ending=110). That
//! chain is owned by the boss kill-suite batch; this suite stops at the
//! arena like the other trunks.
//!
//! Forward cards 971,973,974,976,978,980,982,984,986,988,990,992,994,996,
//! 998,1000,1002,1004,1006,1008,1010 chain 83->103; even cards are returns.
use callys_client::GameState;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const INTRO: i32 = 137;
const PLAYER: i32 = 0;
const WARP: i32 = 69;
const MUSIC: i32 = 68;

fn boot_like_android() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).expect("GameState::new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../../crates/core/src/generated/full_ir.json"))
            .expect("load full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state
}

fn scene(state: &GameState) -> &Scene {
    state.scene.as_ref().expect("IR gameplay scene")
}

fn step(state: &mut GameState) {
    state.step(1.0 / 60.0);
    assert!(state.runtime_diagnostic.is_none(), "IR frame loop halted: {:?}", state.runtime_diagnostic);
}

fn skip_prologue(state: &mut GameState) {
    for _ in 0..125 { step(state); }
    state.input.tap = true;
    step(state);
    state.input.tap = false;
    for _ in 0..2 { step(state); }
    assert!(!scene(state).instances.values().any(|i| i.object == INTRO && i.alive));
}

fn walk_door(state: &mut GameState, target: f64) {
    let portal = scene(state).instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id)
        .unwrap_or_else(|| {
            let doors: Vec<_> = scene(state).instances.iter()
                .filter(|(_, i)| i.object == WARP && i.alive)
                .map(|(_, i)| (i.fields.get("warproom").copied(), i.active))
                .collect();
            panic!("no door to room {target} in room {}: doors {doors:?}", scene(state).current_room);
        });
    let (x, y) = {
        let p = &scene(state).instances[&portal];
        (p.fields["x"], p.fields["y"])
    };
    let player = *scene(state).instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| id).unwrap();
    {
        let s = state.scene.as_mut().unwrap();
        s.write(player, -1, "x", None, x).unwrap();
        s.write(player, -1, "y", None, y).unwrap();
    }
    for _ in 0..14 {
        step(state);
        if scene(state).current_room == target { return; }
    }
    panic!("door to room {target} never fired: still in room {}", scene(state).current_room);
}

/// Lair trunk by enumerated door cards. 21 hops.
const TRUNK: [(f64, &str); 22] = [
    (83.0, "room83"), (84.0, "room84"), (85.0, "room85"), (86.0, "room86"),
    (87.0, "room87"), (88.0, "room88"), (89.0, "room89"), (90.0, "room90"),
    (91.0, "room91"), (92.0, "room92"), (93.0, "room93"), (94.0, "room94"),
    (95.0, "room95"), (96.0, "room96"), (97.0, "room97"), (98.0, "room98"),
    (99.0, "room99"), (100.0, "room100"), (101.0, "room101"), (102.0, "room102"),
    (103.0, "room103"), (104.0, "rm_boss6"),
];

#[test]
fn the_lair_trunk_walks_from_room83_to_boss6_through_real_doors() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    {
        let bundle = state.full_bundle.as_ref().expect("bundle").clone();
        let room_data = state.asset.rooms[83].clone();
        let s = state.scene.as_mut().unwrap();
        s.transition_to_room(&bundle, 83, &room_data).expect("enter room83");
    }
    assert_eq!(scene(&state).current_room, 83.0);

    for (id, name) in &TRUNK[1..] {
        walk_door(&mut state, *id);
        assert_eq!(scene(&state).current_room, *id, "door landed in {name}");
        assert_eq!(state.asset.rooms[scene(&state).current_room as usize].name, *name);
        assert_eq!(
            scene(&state).instances.values().filter(|i| i.object == PLAYER && i.alive).count(),
            1, "{name}: exactly one persistent player after the hop"
        );
        assert!(
            scene(&state).instances.values().any(|i| i.object == MUSIC && i.alive),
            "{name}: obj_music survives the hop (asset persistent set)"
        );
        assert!(
            scene(&state).room_views.iter().any(|v| v.visible),
            "{name}: the reseeded runtime view is visible"
        );
    }

    // rm_boss6 has no forward door card (1012 is the only backward one) — the
    // ending comes from the boss6 kill chain, owned by the kill-suite batch.
    // Arena entry is the assertion boundary of this suite, like the other
    // trunks.
}
