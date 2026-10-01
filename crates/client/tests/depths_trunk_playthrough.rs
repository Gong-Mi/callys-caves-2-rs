//! Depths trunk progression: rm_boss2's forward door into room31, then the
//! 20-hop linear trunk room31..room50 to rm_boss3, exclusively through live
//! obj_warpanywhere instances whose own `warproom` fields target the next
//! room. The chain AND both door directions per room were enumerated from the
//! recovered RoomCC creation codes (857..901) against room_bindings — not
//! guessed from names. (The topology contract doc's region table predates the
//! full enumeration; where they disagree, these cards are the shipped truth:
//! rm_boss3 is asset room 48, and room34 has a second, backward door card 867.)
//!
//! Seeding enters room31 through the client's own transition_to_room: the
//! boss2 arena gate (card 858) is reachable only after the boss2 kill chain,
//! which is owned by the boss2/kill suites; re-proving it here would double
//! the runtime and dilute failure attribution. Per-hop assertions mirror
//! mines_trunk_playthrough: named landing, one persistent player, obj_music
//! alive across the whole trunk, and a visible reseeded runtime view.
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

/// Depths trunk by enumerated door cards: 28=room31 .. 47=room50, then the
/// arena. Forward cards 860,861,864,865,869,870,872,874,877,878,880,883,884,
/// 887,888,890,892,895,897,898 chain 28->48 without a single backwards hop.
const TRUNK: [(f64, &str); 21] = [
    (28.0, "room31"), (29.0, "room32"), (30.0, "room33"), (31.0, "room34"),
    (32.0, "room35"), (33.0, "room36"), (34.0, "room37"), (35.0, "room38"),
    (36.0, "room39"), (37.0, "room40"), (38.0, "room41"), (39.0, "room42"),
    (40.0, "room43"), (41.0, "room44"), (42.0, "room45"), (43.0, "room46"),
    (44.0, "room47"), (45.0, "room48"), (46.0, "room49"), (47.0, "room50"),
    (48.0, "rm_boss3"),
];

#[test]
fn the_depths_trunk_walks_from_room31_to_boss3_through_real_doors() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    {
        let bundle = state.full_bundle.as_ref().expect("bundle").clone();
        let room_data = state.asset.rooms[28].clone();
        let s = state.scene.as_mut().unwrap();
        s.transition_to_room(&bundle, 28, &room_data).expect("enter room31");
    }
    assert_eq!(scene(&state).current_room, 28.0);

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

    // The 21st hop already asserted the landing name via asset rooms[48] ==
    // "rm_boss3"; arena-cast specifics (boss instance, gate) are owned by the
    // boss3 core suites and the hud_draw chain, not re-proven here.
}
