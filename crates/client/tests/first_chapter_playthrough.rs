//! First-chapter client-level playthrough contract: prologue -> town -> Caves
//! -> Boss 1 -> the Mines door.
//!
//! Everything here goes through the public entry points the Android client
//! itself uses: `GameState::new`, `enable_ir_gameplay` (which runs the real
//! Game Start, CODE 17, and spawns the prologue `obj_introduction` into the
//! full scene), `step`, `pointer_released` and `draw_frame`. No
//! hand-written room walk: every hop is a real CODE 13 collision on the room's
//! own `obj_warpanywhere` instance, consumed by the client's
//! `target_room_warp` handoff, and every fight is fought with the original
//! button bytecode through the client's virtual touch devices.
//!
//! This is the client-layer companion to `crates/core/tests/first_chapter_flow_ir.rs`
//! (room topology) and `boss1_trex_kill_chain_ir.rs` (boss bytecode): those prove
//! the data and the script; this proves the shipped frame loop wires them into a
//! playable run.
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;
use std::sync::Arc;

const PLAYER: i32 = 0;
const WARP: i32 = 69;
const SHOTGUN_PICKUP: i32 = 73;
const FOUND_WEAPON_BANNER: i32 = 82;
const LEFT_BUTTON: i32 = 130;
const INTRO: i32 = 137;
const LLOYD: i32 = 154;
const LLOYD_TUTORIAL1: i32 = 138;
const BULLET: i32 = 39;
const TREX: i32 = 25;
const BOSSBOULDER: i32 = 3;

/// Mirrors `Java_com_gongmi_callyscaves2_MainActivity_nativeInit`: parse the
/// original data and load the full IR bundle; Game Start (CODE 17) runs on a
/// live player and spawns `obj_introduction` (137) into the same scene. The
/// intro is what the device shows first; gameplay continues in that one scene
/// once the intro dies.
fn boot_like_android() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset_path = root.join("../../assets/game.droid");
    let mut state = GameState::new(&asset_path).expect("GameState::new");

    let full_ir_path = root.join("../../crates/core/src/generated/full_ir.json");
    let full_bundle = Arc::new(load_bundle_from_file(&full_ir_path).expect("load full_ir"));
    state.enable_ir_gameplay(full_bundle).expect("enable_ir_gameplay");
    state
}

fn scene(state: &GameState) -> &Scene {
    state.scene.as_ref().expect("IR gameplay scene")
}

fn room(state: &GameState) -> f64 {
    scene(state).current_room
}

fn room_name(state: &GameState, room: f64) -> String {
    state.asset.rooms[room as usize].name.clone()
}

fn cast(state: &GameState, object: i32) -> usize {
    scene(state).instances.values().filter(|i| i.object == object && i.alive).count()
}

fn player_id(state: &GameState) -> i32 {
    *scene(state)
        .instances
        .iter()
        .find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| id)
        .expect("persistent obj_player")
}

fn write_player(state: &mut GameState, x: f64, y: f64) {
    let id = player_id(state);
    let scene = state.scene.as_mut().expect("scene");
    scene.write(id, -1, "x", None, x).expect("write player x");
    scene.write(id, -1, "y", None, y).expect("write player y");
}

fn frames(state: &mut GameState, count: usize) {
    for _ in 0..count {
        state.step(1.0 / 60.0);
        assert!(
            state.runtime_diagnostic.is_none(),
            "the IR frame loop must not halt: {:?}",
            state.runtime_diagnostic
        );
    }
}

/// Skips the prologue exactly like a device tap does: `obj_introduction`
/// alarm[0] = 120 gates the tap (`taplock`), so the wait has to happen first;
/// the tap then destroys the intro and the same scene continues into rm_town.
fn skip_prologue_into_town(state: &mut GameState) {
    for _ in 0..125 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
    }
    let intro_alive = state
        .scene
        .as_ref()
        .map(|s| s.instances.values().any(|i| i.object == INTRO && i.alive))
        .unwrap_or(false);
    assert!(intro_alive, "the untouched prologue outlives 120 frames");
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    frames(state, 2);
    let intro_alive = state
        .scene
        .as_ref()
        .map(|s| s.instances.values().any(|i| i.object == INTRO && i.alive))
        .unwrap_or(false);
    assert!(!intro_alive, "a real tap retires the prologue intro");
    assert!(state.intro_scene.is_none(), "no separate intro scene exists");
    assert_eq!(room(state), 0.0, "the prologue hands over to rm_town");
}

/// obj_lloydtutorial1..16 (138..=153) freeze the world via
/// `instance_deactivate_all(true)`, so no door of that room is reachable until
/// the player taps through them: they are the chapter's own progress gate, and
/// their tap unlocks only at the end of their panel timeline (alarm[5]).
fn dismiss_tutorial_sheet_if_any(state: &mut GameState) {
    let sheet = scene(state)
        .instances
        .iter()
        .find(|(_, i)| (138..=153).contains(&i.object) && i.alive)
        .map(|(id, _)| *id);
    let Some(sheet) = sheet else { return };
    for _ in 0..640 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        if scene(state).instances[&sheet].fields.get("taplock").copied() == Some(1.0) {
            break;
        }
    }
    assert_eq!(
        scene(state).instances[&sheet].fields.get("taplock").copied(),
        Some(1.0),
        "the sheet unlocks its tap at the end of its panel timeline"
    );
    state.pointer_released(480.0, 270.0);
    frames(state, 3);
    assert!(
        !scene(state).instances.get(&sheet).map(|i| i.alive).unwrap_or(false),
        "a real tap dismisses the tutorial sheet"
    );
}

/// Walks the room the player is standing in through its own door instance:
/// find the live `obj_warpanywhere` whose creation code targets `target`, stand
/// the player on it, and let the client consume the queued `room_goto`.
///
/// The door is allowed to be asleep: `obj_bg` Alarm 2 (CODE 361) deactivates
/// obj_warpanywhere whenever it sits more than 480 px from the player, and wakes
/// everything inside the 800x800 region around obj_bg on the next sweep. So the
/// fixture stands the player on the door first and gives the sweep a few frames
/// to wake it — the original sleep mechanism is not a missing door chain.
fn walk_door(state: &mut GameState, target: f64) {
    dismiss_tutorial_sheet_if_any(state);
    let portal = scene(state)
        .instances
        .iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(target))
        .map(|(id, _)| *id)
        .unwrap_or_else(|| {
            let doors: Vec<_> = scene(state)
                .instances
                .iter()
                .filter(|(_, i)| i.object == WARP && i.alive)
                .map(|(_, i)| i.fields.get("warproom").copied())
                .collect();
            panic!("no door to room {target} in room {}: {doors:?}", room(state));
        });
    let (x, y) = {
        let portal = &scene(state).instances[&portal];
        (portal.fields["x"], portal.fields["y"])
    };
    write_player(state, x, y);
    for _ in 0..14 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        if room(state) == target {
            return;
        }
    }
    panic!("door to room {target} never fired: still in room {}", room(state));
}

fn rendered_pixels(state: &GameState) -> usize {
    let mut framebuffer = Framebuffer::new(960, 540);
    draw_frame(&mut framebuffer, state, &state.asset.tpag_items, &state.asset.sprites);
    framebuffer.pixels.iter().filter(|&&pixel| pixel != 0).count()
}

/// The prologue plus the first tutorial of the chapter: the town Lloyd sheet is
/// the game's only cutscene system and freezes the world until it is dismissed.
#[test]
fn the_prologue_hands_over_to_town_and_the_town_tutorial_dismisses_on_a_real_tap() {
    let mut state = boot_like_android();

    // obj_introduction (137): alarm[0] = 120 gates the tap, so a premature tap
    // must not skip the opening sequence.
    frames(&mut state, 5);
    let intro_alive = |s: &GameState| {
        s.scene.as_ref().unwrap().instances.values().any(|i| i.object == INTRO && i.alive)
    };
    state.input.tap = true;
    state.step(1.0 / 60.0);
    state.input.tap = false;
    assert!(intro_alive(&state), "taplock == 0 ignores a premature tap");

    frames(&mut state, 120);
    assert!(rendered_pixels(&state) > 1000, "the prologue renders real pixels");
    skip_prologue_into_town(&mut state);

    // roomstart in town follows the ORIGINAL gates, not Room Start: CODE 16
    // raises it only in rm_ending (room 110); here obj_lloyd's proximity
    // (CODE 675, distance < 100) raises it and the lloydtutorial1 Destroy
    // clears it. The player spawns far from Lloyd, so it must still be 0.
    let roomstart = scene(&state).globals.get("roomstart").copied();
    assert_eq!(roomstart, Some(0.0), "town roomstart waits for the Lloyd gate");
    assert!(rendered_pixels(&state) > 1000, "rm_town renders real pixels");

    // Walk into obj_lloyd (154): the proximity Step freezes the world and hands
    // over to the room's tutorial sheet (rm_town -> obj_lloydtutorial1).
    let (lx, ly) = {
        let lloyd = scene(&state)
            .instances
            .values()
            .find(|i| i.object == LLOYD && i.alive)
            .expect("rm_town contains obj_lloyd");
        (lloyd.fields["x"], lloyd.fields["y"])
    };
    write_player(&mut state, lx + 40.0, ly);
    frames(&mut state, 40);
    let sheet = scene(&state)
        .instances
        .iter()
        .find(|(_, i)| i.object == LLOYD_TUTORIAL1 && i.alive)
        .map(|(id, _)| *id)
        .expect("obj_lloyd hands over to obj_lloydtutorial1");
    assert_eq!(
        scene(&state).globals.get("roomstart").copied(),
        Some(1.0),
        "the sheet freezes the world (CODE 675 raised roomstart)"
    );
    assert_eq!(cast(&state, LEFT_BUTTON), 0, "obj_lloyd destroys the movement controls");
    assert!(
        scene(&state).instances.values().filter(|i| i.alive && i.active).count() == 1,
        "instance_deactivate_all(true) leaves only the sheet active"
    );

    // The sheet's own timeline unlocks the tap at alarm[5] = 600.
    frames(&mut state, 610);
    assert_eq!(
        scene(&state).instances[&sheet].fields.get("taplock").copied(),
        Some(1.0),
        "the sheet unlocks the tap prompt at the end of its panel timeline"
    );

    // A real finger release from the platform (960x540 logical viewport).
    state.pointer_released(480.0, 270.0);
    frames(&mut state, 3);
    assert!(
        !scene(&state).instances.get(&sheet).map(|i| i.alive).unwrap_or(false),
        "a real release dismisses the sheet (CODE 570's device-0 release check)"
    );
    assert_eq!(
        scene(&state).globals.get("talkedtolloyd1").copied(),
        Some(1.0),
        "CODE 566 lands the talkedtolloyd1 save flag"
    );
    assert_eq!(
        scene(&state).globals.get("roomstart").copied(),
        Some(0.0),
        "code 566 unfreezes the world"
    );
    assert!(cast(&state, LEFT_BUTTON) == 1, "the controls are rebuilt after the sheet");
    assert!(rendered_pixels(&state) > 1000, "town renders again after the sheet");
}

/// The chapter's must-pass weapon pickup: obj_shotgun (73) in rm_level1 hands
/// over obj_foundweapon (82), which freezes the world until a left press.
#[test]
fn the_level1_shotgun_banner_takes_a_real_tap_to_resume() {
    let mut state = boot_like_android();
    skip_prologue_into_town(&mut state);
    frames(&mut state, 15);
    walk_door(&mut state, 1.0);
    assert_eq!(room_name(&state, room(&state)), "rm_level1");

    let (px, py) = {
        let pickup = scene(&state)
            .instances
            .values()
            .find(|i| i.object == SHOTGUN_PICKUP && i.alive)
            .expect("rm_level1 places the shotgun pickup");
        (pickup.fields["x"], pickup.fields["y"])
    };
    write_player(&mut state, px, py);
    for _ in 0..6 {
        state.step(1.0 / 60.0);
        if cast(&state, FOUND_WEAPON_BANNER) > 0 {
            break;
        }
    }
    assert_eq!(cast(&state, FOUND_WEAPON_BANNER), 1, "the pickup hands over the banner");
    assert_eq!(
        scene(&state).globals.get("shotgunbought").copied(),
        Some(1.0),
        "CODE 387 raises shotgunbought"
    );
    assert_eq!(cast(&state, SHOTGUN_PICKUP), 0, "CODE 387 destroys the pickup");
    assert!(
        scene(&state).instances.values().filter(|i| i.alive && i.active).count() == 1,
        "the banner freezes the world"
    );

    // CODE 406 unlocks the "Tap to Continue" prompt after 70 ticks.
    frames(&mut state, 75);
    let banner = *scene(&state)
        .instances
        .iter()
        .find(|(_, i)| i.object == FOUND_WEAPON_BANNER && i.alive)
        .map(|(id, _)| id)
        .expect("banner still alive");
    assert_eq!(
        scene(&state).instances[&banner].fields.get("taplock").copied(),
        Some(1.0),
        "CODE 406 unlocks the tap"
    );

    // A real tap: the platform's mb_left press (Java's tap pulse).
    state.input.tap = true;
    frames(&mut state, 1);
    state.input.tap = false;
    frames(&mut state, 2);
    assert_eq!(cast(&state, FOUND_WEAPON_BANNER), 0, "a real tap dismisses the banner");
    assert!(
        scene(&state).instances.values().filter(|i| i.alive && i.active).count() > 1,
        "CODE 405 reactivates the world"
    );
    assert_eq!(
        scene(&state).globals.get("shotgun").copied(),
        Some(1.0),
        "the shotgun row is live after the hand-over"
    );
    assert!(rendered_pixels(&state) > 1000, "rm_level1 renders after the banner");
}

/// Town -> Caves -> Boss 1 through the chapter's real door chain, with a
/// rendered frame in every room. rm_level6 is the vault side room and
/// rm_level8a the weapon side room; both are on the path, not shortcuts.
#[test]
fn every_chapter_door_from_town_to_boss1_loads_and_renders() {
    let mut state = boot_like_android();
    skip_prologue_into_town(&mut state);
    frames(&mut state, 15);

    let route: [(f64, &str); 11] = [
        (1.0, "rm_level1"),
        (2.0, "rm_level2"),
        (3.0, "rm_level3"),
        (4.0, "rm_level4"),
        (5.0, "rm_level5"),
        (6.0, "rm_level6"),
        (5.0, "rm_level5"),
        (7.0, "rm_level7"),
        (8.0, "rm_level8"),
        (9.0, "rm_level8a"),
        (10.0, "rm_boss1"),
    ];
    for (target, expected_name) in route {
        walk_door(&mut state, target);
        assert_eq!(room(&state), target, "the door landed in room {target}");
        assert_eq!(room_name(&state, room(&state)), expected_name);
        assert!(
            cast(&state, PLAYER) == 1,
            "{expected_name}: exactly one live player after the transition"
        );
        assert!(
            rendered_pixels(&state) > 1000,
            "{expected_name} renders real pixels"
        );
    }

    // Boss 1 opening state: the arena ships its own cast and the gate is shut.
    assert_eq!(cast(&state, TREX), 1, "rm_boss1 spawns obj_trex");
    assert!(cast(&state, BOSSBOULDER) >= 1, "rm_boss1 seals the exit with boulders");
    assert_eq!(
        scene(&state).globals.get("boss1dead").copied(),
        Some(0.0),
        "the boss is alive on arrival"
    );
}

/// The chapter's end: kill obj_trex with the real shoot button, watch the
/// boulder gate open, and walk the freed door into rm_level9.
#[test]
fn the_shoot_button_kills_boss1_and_the_freed_door_enters_level9() {
    let mut state = boot_like_android();
    skip_prologue_into_town(&mut state);
    frames(&mut state, 15);

    // Walk the whole chapter with the room order pinned by the contract.
    for target in [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 5.0, 7.0, 8.0, 9.0, 10.0] {
        walk_door(&mut state, target);
    }
    assert_eq!(room_name(&state, room(&state)), "rm_boss1");

    // Stand the player next to the boss, facing it, with the boss on its last
    // HP: the pistol's own damage (global.pistoldamage, recomputed from the
    // weapon level by CODE 12) then lands the lethal blow.
    let (tx, ty) = {
        let trex = scene(&state)
            .instances
            .values()
            .find(|i| i.object == TREX && i.alive)
            .expect("obj_trex");
        (trex.fields["x"], trex.fields["y"])
    };
    let player = player_id(&state);
    {
        let scene = state.scene.as_mut().unwrap();
        scene.write(player, -1, "x", None, tx - 25.0).unwrap();
        scene.write(player, -1, "y", None, ty).unwrap();
        scene.write(player, -1, "facing", None, 0.0).unwrap();
        let trex = scene
            .instances
            .iter()
            .find(|(_, i)| i.object == TREX && i.alive)
            .map(|(id, _)| *id)
            .unwrap();
        scene.write(trex, -1, "hptrex", None, 1.0).unwrap();
    }

    // Hold the shoot button: the press edge arms obj_shootbutton's alarm, the
    // alarm runs the player's own CODE 11 and the bullet does the rest.
    let mut bullets_seen = 0;
    state.input.attack = true;
    for _ in 0..6 {
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none(), "{:?}", state.runtime_diagnostic);
        bullets_seen = bullets_seen.max(cast(&state, BULLET));
        if scene(&state).globals.get("boss1dead").copied() == Some(1.0) {
            break;
        }
        // The trex patrols; keep the player on its flank so the shot connects.
        let flank = scene(&state)
            .instances
            .values()
            .find(|i| i.object == TREX && i.alive)
            .map(|i| (i.fields["x"], i.fields["y"]))
            .unwrap_or((tx, ty));
        write_player(&mut state, flank.0 - 25.0, flank.1);
    }
    state.input.attack = false;
    for _ in 0..8 {
        state.step(1.0 / 60.0);
        if scene(&state).globals.get("boss1dead").copied() == Some(1.0) {
            break;
        }
    }

    assert!(bullets_seen > 0, "the shoot button must spawn a real bullet (CODE 11)");
    assert_eq!(
        scene(&state).globals.get("boss1dead").copied(),
        Some(1.0),
        "the real bullet lands the lethal blow (CODE 284 -> CODE 160)"
    );
    assert_eq!(cast(&state, TREX), 0, "CODE 160 removes the boss");

    // CODE 29 destroys obj_bossboulder within 31 ticks of boss1dead == 1.
    frames(&mut state, 35);
    assert_eq!(cast(&state, BOSSBOULDER), 0, "the gate boulders are destroyed");

    // The freed door leaves the arena for the Mines.
    walk_door(&mut state, 11.0);
    assert_eq!(room_name(&state, room(&state)), "rm_level9");
    assert!(cast(&state, PLAYER) == 1, "the player survives into rm_level9");
    assert!(rendered_pixels(&state) > 1000, "rm_level9 renders real pixels");
}