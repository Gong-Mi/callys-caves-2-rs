//! Core trunk progression: room51 -> ... -> rm_boss4 through the shipped
//! obj_warpanywhere door instances only. Chain and BOTH per-room door
//! directions enumerated from the recovered RoomCC creation codes (902..933)
//! against room_bindings — not guessed from names:
//!
//!   49:[902->48,903->50]  50:[904->49,905->51]  51:[906->52,907->50]
//!   52:[908->53,909->51]  53:[910->54,911->52]  54:[912->53,913->55]
//!   55:[914->54,915->56]  56:[916->55,917->57]  57:[918->56,919->58]
//!   58:[920->57,921->59]  59:[922->58,923->60]  60:[924->59,925->61]
//!   61:[926->60,927->62]  62:[928->61,929->63]  63:[930->62,931->64]
//!   64:[932->63,933->65]
//!
//! Seeding enters room51 through the client's own transition_to_room: the
//! boss3 gate (card 901 -> 49) opens only after the boss3 kill chain, which
//! is owned by the boss3 core/client suites — no re-proving, no diluted
//! failure attribution. Per-hop assertions mirror the Mines/Depths trunks.
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

/// Core trunk by enumerated door cards: forward cards 903,905,906,908,910,
/// 912,914,916,918,920,922,924,926,928,930,931 chain 49->64; even cards are
/// the returns. 16 hops.
const TRUNK: [(f64, &str); 16] = [
    (49.0, "room51"), (50.0, "room52"), (51.0, "room53"), (52.0, "room54"),
    (53.0, "room55"), (54.0, "room56"), (55.0, "room57"), (56.0, "room58"),
    (57.0, "room59"), (58.0, "room60"), (59.0, "room61"), (60.0, "room62"),
    (61.0, "room63"), (62.0, "room64"), (63.0, "room65"), (64.0, "rm_boss4"),
];

#[test]
fn the_core_trunk_walks_from_room51_to_boss4_through_real_doors() {
    let mut state = boot_like_android();
    skip_prologue(&mut state);
    {
        let bundle = state.full_bundle.as_ref().expect("bundle").clone();
        let room_data = state.asset.rooms[49].clone();
        let s = state.scene.as_mut().unwrap();
        s.transition_to_room(&bundle, 49, &room_data).expect("enter room51");
    }
    assert_eq!(scene(&state).current_room, 49.0);

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

    // The 16th hop already asserted asset rooms[64] == "rm_boss4"; arena-cast
    // specifics (boss instance, gate) are owned by the boss4 core suites.
}
