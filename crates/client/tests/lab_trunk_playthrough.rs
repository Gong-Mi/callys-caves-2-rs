//! Lab trunk progression: room66 -> ... -> rm_boss5 through the shipped
//! obj_warpanywhere door instances only. Chain and BOTH per-room door
//! directions enumerated from the recovered RoomCC creation codes (934..969)
//! against room_bindings — not guessed from names:
//!
//!   65:[934->64,935->66]  66:[936->65,937->67]  67:[938->66,939->68]
//!   68:[940->69,941->67]  69:[942->70,943->68]  70:[944->69,945->71]
//!   71:[946->70,947->72]  72:[948->73,949->71]  73:[950->72,951->74]
//!   74:[952->73,953->75]  75:[954->76,955->74]  76:[956->75,957->77]
//!   77:[958->76,959->78]  78:[960->77,961->79]  79:[962->78,963->80]
//!   80:[964->79,965->81]  81:[966->80,967->82]  82:[968->81,969->83]
//!
//! Seeding enters room66 through the client's own transition_to_room: the
//! boss4 gate (card 933 -> 65) opens only after the boss4 kill chain, which
//! is owned by the boss4 core/client suites. Per-hop assertions mirror the
//! other trunks.
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

/// Lab trunk by enumerated door cards: forward cards 935,937,938,940,942,944,
/// 946,948,950,952,954,956,958,960,962,964,966,967 chain 65->82; even cards
/// are the returns. 17 hops.
const TRUNK: [(f64, &str); 18] = [
    (65.0, "room66"), (66.0, "room67"), (67.0, "room68"), (68.0, "room69"),
    (69.0, "room70"), (70.0, "room71"), (71.0, "room72"), (72.0, "room73"),
    (73.0, "room74"), (74.0, "room75"), (75.0, "room76"), (76.0, "room77"),
    (77.0, "room78"), (78.0, "room79"), (79.0, "room80"), (80.0, "room81"),
    (81.0, "room82"), (82.0, "rm_boss5"),
];

#[test]
fn the_lab_trunk_walks_from_room66_to_boss5_through_real_doors() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    {
        let bundle = state.full_bundle.as_ref().expect("bundle").clone();
        let room_data = state.asset.rooms[65].clone();
        let s = state.scene.as_mut().unwrap();
        s.transition_to_room(&bundle, 65, &room_data).expect("enter room66");
    }
    assert_eq!(scene(&state).current_room, 65.0);

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

    // The 17th hop already asserted asset rooms[82] == "rm_boss5"; arena-cast
    // specifics are owned by the boss5 core suites.
}
