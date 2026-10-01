//! Render batch 3 (part 1) — Entity damage flashing (d3d_set_fog pipeline).
//!
//! In GameMaker 1.4, when an entity (player or any of the 20 enemy/boss classes)
//! takes damage, `flashing = 1` is latched. In its Draw 0 event, the shipped bytecode
//! runs:
//! ```gml
//! if (flashing == 1) {
//!     d3d_set_fog(true, color, 0, 0);
//!     draw_self();
//!     d3d_set_fog(false, 0, 0, 0);
//! } else {
//!     draw_self();
//! }
//! if (flashing == 1) { flashing = 0; }
//! ```
//! Shipped color values (from full_ir.json bytecode constants):
//!   * obj_player (CODE 18): color = 255 (c_red fog in GM BGR model)
//!   * 20 enemy & boss types (CODE 48, 57, 68, 79, 90, 99, 111, 122, 134, 144,
//!     153, 162, 170, 186, 198, 214, 231, 243, 255, 267):
//!     color = 16777215 (c_white fog, 0x00FFFFFF)
//!
//! This suite validates:
//! 1. Player Draw (CODE 18) sets mask_index=29, emits red fog DrawCommand (color=255)
//!    when flashing=1, and automatically clears flashing back to 0.
//! 2. Player Draw on subsequent frame (flashing=0) emits normal blend DrawCommand.
//! 3. Enemy classes (sampling mooks and bosses) emit white fog DrawCommand (color=16777215)
//!    when flashing=1, and automatically clear flashing back to 0.
//! 4. Enemy Draw on subsequent frame (flashing=0) emits normal blend DrawCommand.
//! 5. Fog state does not leak across frames (scene.fog_enabled remains false).

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle};
use callys_core::ir_scene::{DrawCommand, Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const ENEMY: i32 = 14;
const KNIFEBANDIT: i32 = 15;
const SKELETON: i32 = 17;
const TREX: i32 = 25;
const BOSS3: i32 = 27;
const FINALBOSS: i32 = 30;
const SLIME: i32 = 32;

fn game() -> (GameDroidAsset, Bundle) {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    (asset, bundle)
}

fn fresh(bundle: &Bundle, asset: &GameDroidAsset, room: usize) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(bundle);
    s.init_fresh_start_globals();
    for (sid, sprite) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sprite.width as f64,
            height: sprite.height as f64,
            origin_x: sprite.origin_x as f64,
            origin_y: sprite.origin_y as f64,
            frames: sprite.tpag_indices.len().max(1) as f64,
        });
    }
    s.create(bundle, PLAYER, 400.0, 300.0).unwrap();
    s.load_room_from_data(bundle, room, &asset.rooms[room]).unwrap();
    s.view_positions.insert(0, (0.0, 0.0));
    s
}

fn draws_for_instance(s: &Scene, instance_id: i32) -> Vec<DrawCommand> {
    s.draws.iter().filter(|d| d.instance == instance_id).cloned().collect()
}

#[test]
fn player_damage_flash_emits_red_fog_and_resets_flashing() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1); // rm_level1

    let p = s.instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| *id).unwrap();

    // 1. Set flashing = 1 to simulate taking damage
    s.instances.get_mut(&p).unwrap().fields.insert("flashing".into(), 1.0);

    // 2. Draw view 0 (runs obj_player Draw, CODE 18)
    s.draw_view(&bundle, 0).expect("draw view 0");

    let p_draws = draws_for_instance(&s, p);
    assert_eq!(p_draws.len(), 1, "exactly one DrawCommand emitted by CODE 18");
    assert_eq!(p_draws[0].color, 255, "player flashing DrawCommand must have color=255 (c_red fog)");
    assert_eq!(p_draws[0].code, 18, "CODE 18 is obj_player_Draw_0");

    // 3. Bytecode CODE 18 must pin mask_index = 29 (spr_playerstand)
    let mask = s.instances[&p].fields.get("mask_index").copied().unwrap_or(0.0);
    assert_eq!(mask, 29.0, "CODE 18 unconditionally sets mask_index = 29");

    // 4. Bytecode must have cleared flashing back to 0
    let flashing_after = s.instances[&p].fields.get("flashing").copied().unwrap_or(0.0);
    assert_eq!(flashing_after, 0.0, "flashing is reset to 0 by bytecode at end of Draw");

    // 5. Fog state in scene is cleaned up
    assert!(!s.fog_enabled, "fog_enabled must be false after draw_view");

    // 6. Next frame: flashing is 0, normal draw without fog
    s.draw_view(&bundle, 0).expect("draw view 0 frame 2");
    let p_draws_2 = draws_for_instance(&s, p);
    assert_eq!(p_draws_2.len(), 1);
    assert_ne!(p_draws_2[0].color, 255, "non-flashing player draw must not have red fog color");
}

#[test]
fn enemies_damage_flash_emits_white_fog_and_resets_flashing() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1); // rm_level1

    // Spawn sample enemies
    let e_enemy = s.create(&bundle, ENEMY, 200.0, 100.0).unwrap();
    let e_knife = s.create(&bundle, KNIFEBANDIT, 300.0, 100.0).unwrap();
    let e_skel = s.create(&bundle, SKELETON, 400.0, 100.0).unwrap();
    let e_slime = s.create(&bundle, SLIME, 500.0, 100.0).unwrap();

    // Set flashing = 1 for all of them
    for &eid in &[e_enemy, e_knife, e_skel, e_slime] {
        s.instances.get_mut(&eid).unwrap().fields.insert("flashing".into(), 1.0);
    }

    s.draw_view(&bundle, 0).expect("draw view 0");

    let cases = [
        (e_enemy, 48, "obj_enemy"),
        (e_knife, 57, "obj_knifebandit"),
        (e_skel, 79, "obj_skeleton"),
        (e_slime, 255, "obj_slime"),
    ];

    for (eid, code, name) in cases {
        let d = draws_for_instance(&s, eid);
        assert_eq!(d.len(), 1, "exactly one draw command for {name}");
        assert_eq!(d[0].code, code, "code matches for {name}");
        assert_eq!(d[0].color, 16777215, "{name} flashing DrawCommand must have color=16777215 (c_white fog)");

        let flashing_after = s.instances[&eid].fields.get("flashing").copied().unwrap_or(0.0);
        assert_eq!(flashing_after, 0.0, "{name} flashing reset to 0 by bytecode");
    }

    assert!(!s.fog_enabled, "fog_enabled must be false after draw_view");
}

#[test]
fn bosses_damage_flash_emits_white_fog_and_resets_flashing() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 97); // rm_boss3 (room 97)

    // Boss difficulty level pwr=1 gives baseline maxhp (trex=275, boss3=850, finalboss=1750)
    s.globals.insert("pwr".into(), 1.0);

    // Spawn sample bosses: Trex (Boss 1), Boss 3, Final Boss
    let b_trex = s.create(&bundle, TREX, 200.0, 100.0).unwrap();
    let b_boss3 = s.create(&bundle, BOSS3, 300.0, 100.0).unwrap();
    let b_final = s.create(&bundle, FINALBOSS, 400.0, 100.0).unwrap();

    for &bid in &[b_trex, b_boss3, b_final] {
        s.instances.get_mut(&bid).unwrap().fields.insert("flashing".into(), 1.0);
    }

    s.draw_view(&bundle, 0).expect("draw view 0");

    let cases = [
        (b_trex, 162, "obj_trex"),
        (b_boss3, 186, "obj_boss3"),
        (b_final, 231, "obj_finalboss"),
    ];

    for (bid, code, name) in cases {
        let d = draws_for_instance(&s, bid);
        assert_eq!(d.len(), 1, "exactly one draw command for {name}");
        assert_eq!(d[0].code, code, "code matches for {name}");
        assert_eq!(d[0].color, 16777215, "{name} flashing DrawCommand must have color=16777215 (c_white fog)");

        let flashing_after = s.instances[&bid].fields.get("flashing").copied().unwrap_or(0.0);
        assert_eq!(flashing_after, 0.0, "{name} flashing reset to 0 by bytecode");
    }

    assert!(!s.fog_enabled, "fog_enabled must be false after draw_view");
}

#[test]
fn non_flashing_entities_emit_normal_blend_without_fog() {
    let (asset, bundle) = game();
    let mut s = fresh(&bundle, &asset, 1);

    let p = s.instances.iter().find(|(_, i)| i.object == PLAYER && i.alive).map(|(id, _)| *id).unwrap();
    let e_enemy = s.create(&bundle, ENEMY, 200.0, 100.0).unwrap();

    // Ensure flashing is 0
    s.instances.get_mut(&p).unwrap().fields.insert("flashing".into(), 0.0);
    s.instances.get_mut(&e_enemy).unwrap().fields.insert("flashing".into(), 0.0);

    s.draw_view(&bundle, 0).expect("draw view 0");

    let p_draws = draws_for_instance(&s, p);
    assert_eq!(p_draws.len(), 1);
    assert_ne!(p_draws[0].color, 255, "non-flashing player does not get red fog color");

    let e_draws = draws_for_instance(&s, e_enemy);
    assert_eq!(e_draws.len(), 1);
    assert_eq!(s.instances[&e_enemy].fields.get("flashing").copied(), Some(0.0));
    assert!(!s.fog_enabled);
}
