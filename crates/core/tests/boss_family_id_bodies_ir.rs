//! WL37 batch 1 — id-level body assertions for the boss-family bodies the census
//! still carried as `object_cited_contract`.
//!
//! obj_finalboss (30): CODE 216, CODE 218, CODE 219, CODE 220, CODE 221, CODE
//! 222, CODE 223, CODE 224, CODE 225, CODE 226, CODE 227, CODE 228, CODE 230,
//! CODE 231.
//! obj_boss5 (29): CODE 201, CODE 202, CODE 203, CODE 204, CODE 205, CODE 206,
//! CODE 207, CODE 208, CODE 209, CODE 210, CODE 211, CODE 213, CODE 214.
//!
//! These are REWRITE-SIDE IR regression semantics: every asserted value was read
//! out of the recovered GML body (`cally-recovered-gml/restored-source/gml/`) and
//! cross-checked against the bytecode constants in
//! `crates/core/src/generated/full_ir.json` on this host. They are NOT a proof of
//! equivalence with the original GameMaker runner. The shared suites
//! (`final_boss_ir`, `bosses_3_5_ir`, `entity_flashing_ir`) already execute these
//! bodies end to end; this file adds the per-body id naming and the explicit
//! assertion of each body's own observable effects.
//!
//! Fixture discipline (shared with `enemy_ladders_ii_ir`, `mines_slime_ir`,
//! `bosses_3_5_ir`):
//!  * the alarm bodies are driven with a DIRECT `dispatch` so no same-tick Step
//!    can overwrite the value being asserted, and their self-firing timers are
//!    verified separately through the real scheduler;
//!  * the timer paths pin the player and the actor every frame;
//!  * SPRT geometry (bounds + bboxes + masks) is wired exactly like the app's
//!    `enable_ir_gameplay` injection, because CODE 213 probes with
//!    `instance_place`;
//!  * `global.pwr` is a level-configuration global (set by the room initializer
//!    in the original), never an engine-recomputed field, so the fixture sets it.
//!
//! hp field lineage: obj_finalboss uses `hpfinalboss`, obj_boss5 `hpboss5`.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const P: i32 = 0;
const INIT: i32 = 103;
const BOSS5: i32 = 29;
const FINALBOSS: i32 = 30;
const WALL: i32 = 4;
const PAR_WALL: i32 = 34;
const LASER: i32 = 49;
const GRENADE: i32 = 50;
const FIREPROJ: i32 = 54;
const DAMAGE: i32 = 104;
const FINALPUFF: i32 = 189;
const BOSSPUFF: i32 = 190;
/// rm_ending: the room every movement beat and boss5's burst are gated on.
const RM_ENDING: f64 = 110.0;
/// Blend constants straight out of the IR constants of CODE 213 (c_red / c_green
/// in the packed GM colour model).
const C_RED: f64 = 255.0;
const C_GREEN: f64 = 32768.0;
/// CODE 228 / CODE 231 / CODE 214 constants.
const SND_EXPLODE: i32 = 7;
const SND_ROCKET: i32 = 12;
const SND_TECHNOENDING: i32 = 49;
const C_WHITE: i32 = 16777215;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// WL7: the app's SPRT wiring (recorded bbox + bounds + masks) so the shared box
/// source reads real geometry instead of integer points.
fn wire_sprite_geometry(s: &mut Scene) {
    let asset = GameDroidAsset::parse(
        &Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid"),
    )
    .expect("parse game.droid");
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
        if let Some(bbox) = sp.bbox {
            s.sprite_bboxes.insert(*sid as i32, bbox);
        }
        if !sp.masks.is_empty() {
            s.sprite_masks.insert(*sid as i32, sp.masks.clone());
        }
    }
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    wire_sprite_geometry(&mut s);
    let init = s.create(b, INIT, -1000.0, -1000.0).expect("initializer");
    s.instances.get_mut(&init).unwrap().alive = false;
    s.globals.insert("pwr".into(), 1.0);
    s
}

fn player(s: &mut Scene, b: &Bundle, x: f64, y: f64) -> i32 {
    let p = s.create(b, P, x, y).expect("player");
    let i = s.instances.get_mut(&p).unwrap();
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
    i.fields.insert("gravity".into(), 0.0);
    p
}

fn park(s: &mut Scene, id: i32) {
    let i = s.instances.get_mut(&id).unwrap();
    i.active = false;
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

fn pin(s: &mut Scene, id: i32, x: f64, y: f64) {
    let i = s.instances.get_mut(&id).unwrap();
    i.fields.insert("x".into(), x);
    i.fields.insert("y".into(), y);
    i.fields.insert("hspeed".into(), 0.0);
    i.fields.insert("vspeed".into(), 0.0);
}

/// Living instances of an object, in id order.
fn lives(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter().filter(|(_, x)| x.object == object && x.alive).map(|(id, _)| *id).collect()
}

fn count(s: &Scene, object: i32) -> usize {
    lives(s, object).len()
}

/// Every instance of an object ever created in this scene, dead or alive:
/// Destroy keeps the storage, so this is the creation tally.
fn created(s: &Scene, object: i32) -> usize {
    s.instances.values().filter(|x| x.object == object).count()
}

fn snapshot(s: &Scene, id: i32) -> [i32; 12] {
    s.instances[&id].alarms
}

/// The body wrote its own slot to `want` and touched no other timer.
fn assert_only_slot(s: &Scene, id: i32, before: &[i32; 12], slot: usize, want: i32, label: &str) {
    let after = snapshot(s, id);
    for i in 0..12 {
        if i == slot {
            assert_eq!(after[i], want, "{label}: alarm[{i}] must be re-armed to {want}");
        } else {
            assert_eq!(after[i], before[i], "{label}: alarm[{i}] must not be touched");
        }
    }
}

fn boss5_scene(b: &Bundle) -> (Scene, i32, i32) {
    let mut s = scene(b);
    let p = player(&mut s, b, 500.0, 200.0);
    let bs = s.create(b, BOSS5, 300.0, 200.0).expect("obj_boss5");
    (s, p, bs)
}

// ---- obj_finalboss (30) ------------------------------------------------------

#[test]
fn finalboss_destroy_stops_the_audio_and_leaves_the_ending_theme_and_a_puff() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);

    // Music is already running: audio_stop_all() must tear the live voice down.
    s.call_audio_play(60.0, 0.0, true);
    assert!(s.audio_voices.iter().any(|v| v.sound == 60.0 && v.looping),
        "fixture: a looping music voice is live");
    s.audio.clear();
    let _ = s.take_stop_commands();

    // CODE 216 (obj_finalboss Destroy_0):
    //   audio_stop_all(); audio_play_sound(mus_technoending, 0, false);
    //   instance_create(x, y, obj_finalbosspuff);
    s.destroy(&b, fb).expect("destroy runs the Destroy body");
    assert!(!s.instances[&fb].alive, "the Destroy event ends with the boss gone");
    assert!(s.audio_voices.iter().any(|v| v.sound == 60.0 && v.stopped),
        "audio_stop_all() stops the live music voice");
    assert!(s.take_stop_commands().contains(&60.0),
        "and queues the host-side stop for the music it killed");
    assert_eq!(s.audio.len(), 1, "the body queues exactly one sound");
    let cmd = &s.audio[0];
    assert_eq!(cmd.sound, SND_TECHNOENDING, "mus_technoending is SOND 49");
    assert!(!cmd.looping, "played with loop = false");
    assert_eq!(cmd.priority, 0.0, "priority 0");
    assert_eq!(cmd.code, 216, "the AudioCommand is attributed to CODE 216");

    let puffs = lives(&s, FINALPUFF);
    assert_eq!(puffs.len(), 1, "one obj_finalbosspuff is left behind");
    let pi = &s.instances[&puffs[0]];
    assert_eq!((pi.fields["x"], pi.fields["y"]), (300.0, 200.0),
        "instance_create(x, y, obj_finalbosspuff) at the boss's own coordinates");
    // The puff's own Create body (obj_finalbosspuff, which CODE 216 spawns) fans
    // out four obj_bosspuff around it: a dependent observation, not CODE 216's
    // own write.
    assert_eq!(count(&s, BOSSPUFF), 4, "the puff Create adds its four puffs");
}

#[test]
fn finalboss_movement_beats_write_their_velocity_and_hand_over() {
    let b = bundle();

    // CODE 224 = Alarm_4: vspeed 2, hspeed -2, alarm[7] = 100.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 4).expect("Alarm_4");
    assert_eq!(s.instances[&fb].fields["vspeed"], 2.0, "CODE 224: vspeed 2");
    assert_eq!(s.instances[&fb].fields["hspeed"], -2.0, "CODE 224: hspeed -2");
    assert_only_slot(&s, fb, &before, 7, 100, "CODE 224");

    // CODE 221 = Alarm_7: vspeed 3, hspeed 0.5, alarm[8] = 50.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 7).expect("Alarm_7");
    assert_eq!(s.instances[&fb].fields["vspeed"], 3.0, "CODE 221: vspeed 3");
    assert_eq!(s.instances[&fb].fields["hspeed"], 0.5, "CODE 221: hspeed 0.5");
    assert_only_slot(&s, fb, &before, 8, 50, "CODE 221");

    // CODE 220 = Alarm_8: the slam, vspeed 10, alarm[9] = 20.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 8).expect("Alarm_8");
    assert_eq!(s.instances[&fb].fields["vspeed"], 10.0, "CODE 220: vspeed 10");
    assert_only_slot(&s, fb, &before, 9, 20, "CODE 220");

    // CODE 219 = Alarm_9: the slow float back up, vspeed -0.5, alarm[10] = 100.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.instances.get_mut(&fb).unwrap().fields.insert("hspeed".into(), 7.0);
    let before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 9).expect("Alarm_9");
    assert_eq!(s.instances[&fb].fields["vspeed"], -0.5, "CODE 219: vspeed -0.5");
    assert_eq!(s.instances[&fb].fields["hspeed"], 7.0,
        "CODE 219 writes vspeed only - hspeed is left exactly as it was");
    assert_only_slot(&s, fb, &before, 10, 100, "CODE 219");

    // CODE 218 = Alarm_10: the horizontal sweep, hspeed 2, vspeed 3, alarm[11] = 100.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 10).expect("Alarm_10");
    assert_eq!(s.instances[&fb].fields["hspeed"], 2.0, "CODE 218: hspeed 2");
    assert_eq!(s.instances[&fb].fields["vspeed"], 3.0, "CODE 218: vspeed 3");
    assert_only_slot(&s, fb, &before, 11, 100, "CODE 218");
}

#[test]
fn finalboss_movement_beats_are_gated_on_the_ending_room() {
    let b = bundle();
    // Every movement beat of obj_finalboss opens with `if (room != rm_ending)`.
    // In rm_ending they must be inert: no velocity write, no alarm re-arm. The
    // gate is per body, so all five are driven in the ending room.
    //   (label, dispatch slot)
    let gated: [(&str, i32); 5] = [
        ("CODE 224", 4), ("CODE 221", 7), ("CODE 220", 8),
        ("CODE 219", 9), ("CODE 218", 10),
    ];
    for (label, slot) in gated {
        let mut s = scene(&b);
        let p = player(&mut s, &b, 500.0, 200.0);
        let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
        park(&mut s, p);
        s.current_room = RM_ENDING;
        {
            let i = s.instances.get_mut(&fb).unwrap();
            i.fields.insert("hspeed".into(), 7.0);
            i.fields.insert("vspeed".into(), -7.0);
        }
        let before = snapshot(&s, fb);
        s.dispatch(&b, fb, 2, slot).expect("gated movement beat");
        assert_eq!(s.instances[&fb].fields["hspeed"], 7.0, "{label}: gated on room");
        assert_eq!(s.instances[&fb].fields["vspeed"], -7.0, "{label}: gated on room");
        assert_eq!(snapshot(&s, fb), before, "{label}: no timer is armed in rm_ending");
    }
}

#[test]
fn finalboss_grenade_volley_and_laser_spread_positions() {
    let b = bundle();

    // CODE 225 = Alarm_3: four grenades (obj_finalbossgrenade, 50) from
    // (x-100, y), (x-80, y-20), (x-80, y+20), (x, y-20) aimed 180/135/225/90.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0); // far away: the Create aims at nobody nearby
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, fb, 2, 3).expect("Alarm_3");
    let mut shots: Vec<(f64, f64, f64)> = lives(&s, GRENADE)
        .iter().map(|id| {
            let i = &s.instances[id];
            (i.fields["x"], i.fields["y"], i.fields["direction"])
        }).collect();
    shots.sort_by(|a, c| a.partial_cmp(c).unwrap());
    assert_eq!(shots, vec![
        (200.0, 200.0, 180.0), (220.0, 180.0, 135.0),
        (220.0, 220.0, 225.0), (300.0, 180.0, 90.0),
    ], "CODE 225 throws exactly four grenades at the shipped offsets/directions");

    // CODE 226 = Alarm_2: six lasers (obj_finalbosslaser, 49) from (x-100, y),
    // (x-80, y-20), (x-80, y+20), (x, y-20), (x, y+20), (x+80, y-20) aimed
    // 180/135/225/90/270/45 - all six compass-ish directions.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.dispatch(&b, fb, 2, 2).expect("Alarm_2");
    let mut beams: Vec<(f64, f64, f64)> = lives(&s, LASER)
        .iter().map(|id| {
            let i = &s.instances[id];
            (i.fields["x"], i.fields["y"], i.fields["direction"])
        }).collect();
    beams.sort_by(|a, c| a.partial_cmp(c).unwrap());
    assert_eq!(beams, vec![
        (200.0, 200.0, 180.0), (220.0, 180.0, 135.0), (220.0, 220.0, 225.0),
        (300.0, 180.0, 90.0), (300.0, 220.0, 270.0), (380.0, 180.0, 45.0),
    ], "CODE 226 fires all six lasers of the spread");

    // Both volleys are gated on `room != rm_ending` as well.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.current_room = RM_ENDING;
    s.dispatch(&b, fb, 2, 3).expect("gated volley");
    s.dispatch(&b, fb, 2, 2).expect("gated spread");
    assert_eq!(count(&s, GRENADE), 0, "CODE 225 shoots nothing in rm_ending");
    assert_eq!(count(&s, LASER), 0, "CODE 226 shoots nothing in rm_ending");
}

#[test]
fn finalboss_poison_slot_bites_and_re_arms_itself() {
    let b = bundle();
    // CODE 222 = Alarm_6: poisoned = 1, hpfinalboss -= 0.25, one obj_damage
    // carrying damage = 0.25, then alarm[6] = 30. Nothing else in the corpus arms
    // slot 6 on the final boss, so the body is its own clock.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let hp0 = s.instances[&fb].fields["hpfinalboss"];
    assert!(hp0 > 0.0, "fixture: the boss starts alive");
    let before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 6).expect("Alarm_6");
    assert_eq!(s.instances[&fb].fields["poisoned"], 1.0, "CODE 222 raises the poison flag");
    assert_eq!(hp0 - s.instances[&fb].fields["hpfinalboss"], 0.25,
        "CODE 222 takes a quarter heart off hpfinalboss");
    assert_only_slot(&s, fb, &before, 6, 30, "CODE 222");
    let dmg = lives(&s, DAMAGE);
    assert_eq!(dmg.len(), 1, "one obj_damage number");
    let di = &s.instances[&dmg[0]];
    assert_eq!(di.fields["damage"], 0.25, "the number carries damage = 0.25");
    assert_eq!((di.fields["x"], di.fields["y"]), (300.0, 200.0),
        "created at the boss's own coordinates");

    // Through the real scheduler: the armed 30-tick timer fires the same body
    // again and re-arms itself.
    for _ in 0..30 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, fb, 300.0, 200.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&fb].fields["hpfinalboss"], 0.5,
        "CODE 222 self-fired once on its own 30-tick alarm");
    assert_eq!(s.instances[&fb].alarms[6], 30, "and re-armed its own slot to 30");
    assert_eq!(created(&s, DAMAGE), 2, "two damage numbers were created in total");
}

#[test]
fn finalboss_stun_clear_and_the_empty_alarm_slot() {
    let b = bundle();
    // CODE 223 = Alarm_5: `swordstunned = 0`, nothing else.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    {
        let i = s.instances.get_mut(&fb).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("hspeed".into(), 5.0);
    }
    let fields_before: Vec<(String, f64)> = s.instances[&fb].fields.iter()
        .map(|(k, v)| (k.clone(), *v)).collect();
    let alarms_before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 5).expect("Alarm_5");
    assert_eq!(s.instances[&fb].fields["swordstunned"], 0.0, "CODE 223 clears the sword stun");
    assert_eq!(s.instances[&fb].fields["hspeed"], 5.0, "and writes nothing else: hspeed intact");
    assert_eq!(snapshot(&s, fb), alarms_before, "no timer armed by CODE 223");
    let mut after_fields: Vec<(String, f64)> = s.instances[&fb].fields.iter()
        .map(|(k, v)| (k.clone(), *v)).collect();
    let mut want = fields_before;
    for e in want.iter_mut() { if e.0 == "swordstunned" { e.1 = 0.0; } }
    after_fields.sort_by(|a, c| a.0.cmp(&c.0));
    want.sort_by(|a, c| a.0.cmp(&c.0));
    assert_eq!(after_fields, want, "CODE 223 touches swordstunned and nothing else");

    // CODE 227 = Alarm_1: a genuinely empty body (zero instructions, start ==
    // end in the IR). Dispatching it must be a no-op, not a panic.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let fields_before: Vec<(String, f64)> = s.instances[&fb].fields.iter()
        .map(|(k, v)| (k.clone(), *v)).collect();
    let alarms_before = snapshot(&s, fb);
    s.dispatch(&b, fb, 2, 1).expect("CODE 227 is an empty body and must run clean");
    let fields_after: Vec<(String, f64)> = s.instances[&fb].fields.iter()
        .map(|(k, v)| (k.clone(), *v)).collect();
    assert_eq!(fields_after, fields_before, "CODE 227 (empty body): no field changes");
    assert_eq!(snapshot(&s, fb), alarms_before, "CODE 227: no timer changes");
    assert!(s.instances[&fb].alive, "CODE 227 kills nothing");
}

#[test]
fn finalboss_death_beat_respects_the_sound_mute_gate_and_kills_the_boss() {
    let b = bundle();
    // CODE 228 = Alarm_0: global.soundmute == 1 -> silence, == 0 -> snd_explode,
    // then action_kill_object() unconditionally.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.globals.insert("soundmute".into(), 0.0);
    s.audio.clear();
    s.dispatch(&b, fb, 2, 0).expect("Alarm_0");
    assert!(!s.instances[&fb].alive, "CODE 228 ends in action_kill_object()");
    // Two commands land: CODE 228's own snd_explode, then the Destroy body that
    // action_kill_object() runs on the boss it just killed (CODE 216).
    assert_eq!(s.audio.len(), 2, "snd_explode, then the Destroy fanfare");
    assert_eq!(s.audio[0].sound, SND_EXPLODE, "first snd_explode (7) from CODE 228");
    assert_eq!(s.audio[0].code, 228, "attributed to CODE 228");
    assert_eq!(s.audio[1].sound, SND_TECHNOENDING, "then the ending theme");
    assert_eq!(s.audio[1].code, 216, "attributed to the Destroy body of CODE 216");
    assert_eq!(count(&s, FINALPUFF), 1, "and the kill leaves its obj_finalbosspuff");

    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.globals.insert("soundmute".into(), 1.0);
    s.audio.clear();
    s.dispatch(&b, fb, 2, 0).expect("Alarm_0 muted");
    assert!(s.audio.iter().all(|c| c.sound != SND_EXPLODE),
        "soundmute 1 silences CODE 228's own snd_explode");
    assert_eq!(s.audio.len(), 1,
        "only the un-gated Destroy fanfare is left: the gate is CODE 228's own");
    assert_eq!(s.audio[0].code, 216, "the Destroy body is not mute-gated");
    assert!(!s.instances[&fb].alive, "the kill happens either way");
}

#[test]
fn finalboss_collision_34_bounces_off_walls() {
    let b = bundle();
    // CODE 230 = Collision with par_wall (34): action_bounce(0, 0), i.e. both
    // velocities flip sign. The wall instance is only needed for the fixture to
    // be a real collision; the body itself is the two negations.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    let _w = s.create(&b, WALL, 290.0, 200.0).expect("wall to bounce off");
    park(&mut s, p);
    {
        let i = s.instances.get_mut(&fb).unwrap();
        i.fields.insert("hspeed".into(), 5.0);
        i.fields.insert("vspeed".into(), -3.0);
    }
    s.dispatch(&b, fb, 4, PAR_WALL).expect("Collision 34");
    assert_eq!(s.instances[&fb].fields["hspeed"], -5.0, "CODE 230 flips hspeed");
    assert_eq!(s.instances[&fb].fields["vspeed"], 3.0, "CODE 230 flips vspeed");
    assert!(s.instances[&fb].alive, "a bounce is not a death");
}

#[test]
fn finalboss_draw_washes_white_while_flashing_and_clears_the_flag() {
    let b = bundle();
    // CODE 231 = Draw_0: with flashing == 1 it wraps draw_self() in
    // d3d_set_fog(true, c_white, 0, 0) and then resets flashing to 0; with
    // flashing == 0 it draws the plain sprite.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    let fb = s.create(&b, FINALBOSS, 300.0, 200.0).unwrap();
    park(&mut s, p);
    let sprite = s.instances[&fb].fields["sprite_index"];
    s.instances.get_mut(&fb).unwrap().fields.insert("flashing".into(), 1.0);
    s.draws.clear();
    s.dispatch(&b, fb, 8, 0).expect("Draw_0 flashing");
    assert_eq!(s.draws.len(), 1, "CODE 231 draws the boss once while flashing");
    let d = &s.draws[0];
    assert_eq!(d.code, 231, "attributed to CODE 231");
    assert!(d.fog, "the draw is wrapped in d3d_set_fog(true, ...)");
    assert_eq!(d.color, C_WHITE, "fog colour c_white (16777215)");
    assert_eq!(d.sprite, sprite as i32, "draw_self of the boss's own sprite");
    assert_eq!(s.instances[&fb].fields["flashing"], 0.0,
        "CODE 231 resets flashing to 0 at the end of the same Draw");
    assert!(!s.fog_enabled, "the body switches the fog back off");

    // Next frame: flashing is 0, so the plain blend is used.
    s.instances.get_mut(&fb).unwrap().fields.insert("image_blend".into(), 255.0);
    s.draws.clear();
    s.dispatch(&b, fb, 8, 0).expect("Draw_0 plain");
    assert_eq!(s.draws.len(), 1);
    let d = &s.draws[0];
    assert_eq!(d.code, 231);
    assert!(!d.fog, "no fog on the non-flashing path");
    assert_eq!(d.color, 255, "the plain path passes image_blend straight through");
    assert_eq!(s.instances[&fb].fields["image_blend"], 255.0,
        "flashing == 0 leaves image_blend untouched");
}

// ---- obj_boss5 (29) ----------------------------------------------------------

#[test]
fn boss5_burst_slot_ladder_fires_one_grenade_and_hands_over() {
    let b = bundle();
    // The eight-slot burst chain of obj_boss5. Each body is identical except for
    // (a) the slot it arms next and (b) CODE 211's extra `room != rm_ending`
    // gate: facing 0 -> create at (x-50, y-5), facing 1 -> (x+50, y-5), then
    // snd_rocket (12), then the next slot.
    //   (label, code id, dispatch slot, next slot, next ticks)
    let ladder: [(&str, i32, i32, usize, i32); 8] = [
        ("CODE 203", 203, 9, 1, 30),
        ("CODE 204", 204, 8, 9, 10),
        ("CODE 205", 205, 7, 8, 10),
        ("CODE 206", 206, 6, 7, 10),
        ("CODE 208", 208, 4, 6, 10),
        ("CODE 209", 209, 3, 4, 10),
        ("CODE 210", 210, 2, 3, 10),
        ("CODE 211", 211, 1, 2, 10),
    ];
    for (label, code, slot, next_slot, next_ticks) in ladder {
        for facing in [0.0, 1.0] {
            let (mut s, _p, bs) = boss5_scene(&b);
            s.instances.get_mut(&bs).unwrap().fields.insert("facing".into(), facing);
            let before = snapshot(&s, bs);
            s.audio.clear();
            s.dispatch(&b, bs, 2, slot).expect("burst beat");
            let shots = lives(&s, FIREPROJ);
            assert_eq!(shots.len(), 1, "{label}: one obj_fireprojectile per beat");
            let si = &s.instances[&shots[0]];
            let want_x = if facing == 0.0 { 250.0 } else { 350.0 };
            assert_eq!((si.fields["x"], si.fields["y"]), (want_x, 195.0),
                "{label}: facing {facing} spawns at (x∓50, y-5)");
            assert_eq!(si.fields["speed"], 8.0,
                "{label}: the projectile's own Create body sets speed 8");
            // The projectile Create aims at obj_player with point_direction.
            let want_dir = (-(200.0 - 195.0_f64)).atan2(500.0 - want_x).to_degrees().rem_euclid(360.0);
            assert!((si.fields["direction"] - want_dir).abs() < 1e-6,
                "{label}: direction {} aims at the player (want {want_dir})",
                si.fields["direction"]);
            assert_eq!(s.audio.iter().filter(|c| c.sound == SND_ROCKET).count(), 1,
                "{label}: exactly one snd_rocket per beat");
            assert_eq!(s.audio.last().unwrap().code, code as usize,
                "{label}: the sound is attributed to the body that played it");
            assert_only_slot(&s, bs, &before, next_slot, next_ticks, label);
        }
    }
}

#[test]
fn boss5_burst_beat_is_gated_on_the_ending_room() {
    let b = bundle();
    // CODE 211 is the only channel slot of obj_boss5 whose firing is gated on
    // `room != rm_ending`; in rm_ending it fires nothing and arms nothing.
    let (mut s, _p, bs) = boss5_scene(&b);
    s.instances.get_mut(&bs).unwrap().fields.insert("facing".into(), 1.0);
    s.current_room = RM_ENDING;
    let before = snapshot(&s, bs);
    s.audio.clear();
    s.dispatch(&b, bs, 2, 1).expect("gated burst");
    assert_eq!(count(&s, FIREPROJ), 0, "CODE 211 fires nothing in rm_ending");
    assert!(s.audio.iter().all(|c| c.sound != SND_ROCKET), "and stays silent");
    assert_eq!(snapshot(&s, bs), before, "and arms no timer");
}

#[test]
fn boss5_flank_placeholder_and_stun_clear() {
    let b = bundle();
    // CODE 201 = Alarm_11: `alarm[11] = 110` with no gate - the flank beat is a
    // pure re-arm placeholder.
    let (mut s, _p, bs) = boss5_scene(&b);
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 11).expect("Alarm_11");
    assert_only_slot(&s, bs, &before, 11, 110, "CODE 201");
    let after = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 11).expect("Alarm_11 again");
    assert_eq!(snapshot(&s, bs), after, "CODE 201 is idempotent");

    // CODE 207 = Alarm_5: `swordstunned = 0` and nothing else.
    let (mut s, _p, bs) = boss5_scene(&b);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("hspeed".into(), 5.0);
    }
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 5).expect("Alarm_5");
    assert_eq!(s.instances[&bs].fields["swordstunned"], 0.0, "CODE 207 clears the stun");
    assert_eq!(s.instances[&bs].fields["hspeed"], 5.0, "CODE 207 writes nothing else");
    assert_eq!(snapshot(&s, bs), before, "CODE 207 arms no timer");
}

#[test]
fn boss5_poison_slot_bites_and_re_arms_itself() {
    let b = bundle();
    // CODE 202 = Alarm_10: poisoned = 1, hpboss5 -= 0.25, one obj_damage with
    // damage = 0.25, alarm[10] = 30. No other body arms slot 10 on obj_boss5.
    let (mut s, p, bs) = boss5_scene(&b);
    let hp0 = s.instances[&bs].fields["hpboss5"];
    assert!(hp0 > 0.0, "fixture: the boss starts alive");
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 10).expect("Alarm_10");
    assert_eq!(s.instances[&bs].fields["poisoned"], 1.0, "CODE 202 raises the poison flag");
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss5"], 0.25,
        "CODE 202 takes a quarter heart off hpboss5");
    assert_only_slot(&s, bs, &before, 10, 30, "CODE 202");
    let dmg = lives(&s, DAMAGE);
    assert_eq!(dmg.len(), 1, "one obj_damage number");
    assert_eq!(s.instances[&dmg[0]].fields["damage"], 0.25, "carrying damage = 0.25");
    assert_eq!((s.instances[&dmg[0]].fields["x"], s.instances[&dmg[0]].fields["y"]),
        (300.0, 200.0), "created at the boss's own coordinates");

    for _ in 0..30 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, bs, 300.0, 200.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss5"], 0.5,
        "CODE 202 self-fired once on its own 30-tick alarm");
    assert_eq!(s.instances[&bs].alarms[10], 30, "and re-armed its own slot");
    assert_eq!(created(&s, DAMAGE), 2, "two damage numbers in total");
}

#[test]
fn boss5_step_gates_the_death_beat_and_reads_the_player_side() {
    let b = bundle();
    let (mut s, p, bs) = boss5_scene(&b);
    // CODE 213 = Step_0, in source order:
    //   hpboss5 >= 0 -> alarm[0] = 0 ; hpboss5 <= 0 -> alarm[0] = 1
    //   vspeed = 0
    //   swordstunned == 1 -> image_blend = c_red, hspeed = vspeed = 0
    //   poisoned == 1 -> image_blend = c_green
    //   player right/left -> image_xscale ±1, facing, hspeed ±1 unless a wall
    //     stands inside the x±100 probe
    //   room == rm_ending -> hspeed = vspeed = 0
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.alarms[0] = 9; // sentinel: the Step owns this slot
        i.fields.insert("hspeed".into(), 7.0);
        i.fields.insert("vspeed".into(), 5.0);
        i.fields.insert("image_xscale".into(), 0.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    assert!(s.instances[&bs].fields["hpboss5"] > 0.0, "fixture: the boss starts alive");
    assert_eq!(s.call(&b, bs, "instance_place", &[400.0, 200.0, PAR_WALL as f64]).unwrap(), -4.0,
        "fixture: the x+100 probe lane is clear");
    s.dispatch(&b, bs, 3, 0).expect("Step_0");
    assert_eq!(s.instances[&bs].alarms[0], 0,
        "hp >= 0 parks the death beat at 0 (the death branch is the only armer)");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0, "the Step zeroes vspeed every tick");
    assert_eq!(s.instances[&bs].fields["facing"], 1.0, "player on the right -> facing 1");
    assert_eq!(s.instances[&bs].fields["image_xscale"], 1.0, "and xscale 1");
    assert_eq!(s.instances[&bs].fields["hspeed"], 1.0, "clear lane -> advance at +1");

    // A wall inside the x+100 probe: the body refuses the step, and facing still
    // follows the player's side.
    let _w = s.create(&b, WALL, 400.0, 200.0).expect("wall at the probe point");
    let probe = s.call(&b, bs, "instance_place", &[400.0, 200.0, PAR_WALL as f64]).unwrap();
    assert!(probe >= 0.0, "fixture: CODE 213's x+100 probe really sees the wall");
    s.instances.get_mut(&bs).unwrap().fields.insert("hspeed".into(), 7.0);
    s.dispatch(&b, bs, 3, 0).expect("Step_0 with a wall");
    assert_eq!(s.instances[&bs].fields["hspeed"], 7.0,
        "a wall in the lane leaves hspeed exactly as it was");
    assert_eq!(s.instances[&bs].fields["facing"], 1.0, "facing still follows the player side");

    // Player on the left: xscale -1, facing 0, hspeed -1 when the left lane is clear.
    pin(&mut s, p, 100.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("hspeed".into(), 7.0);
        i.fields.insert("image_xscale".into(), 0.0);
    }
    assert_eq!(s.call(&b, bs, "instance_place", &[200.0, 200.0, PAR_WALL as f64]).unwrap(), -4.0,
        "fixture: the x-100 probe lane is clear");
    s.dispatch(&b, bs, 3, 0).expect("Step_0 player left");
    assert_eq!(s.instances[&bs].fields["facing"], 0.0, "player on the left -> facing 0");
    assert_eq!(s.instances[&bs].fields["image_xscale"], -1.0, "and xscale -1");
    assert_eq!(s.instances[&bs].fields["hspeed"], -1.0, "clear lane -> advance at -1");

    let _lw = s.create(&b, WALL, 200.0, 200.0).expect("left wall at the probe point");
    assert!(s.call(&b, bs, "instance_place", &[200.0, 200.0, PAR_WALL as f64]).unwrap() >= 0.0,
        "fixture: the x-100 probe sees the left wall");
    s.instances.get_mut(&bs).unwrap().fields.insert("hspeed".into(), -7.0);
    s.dispatch(&b, bs, 3, 0).expect("Step_0 with a left wall");
    assert_eq!(s.instances[&bs].fields["hspeed"], -7.0, "the left wall blocks the step too");

    // hp <= 0: the death beat is armed to 1.
    s.instances.get_mut(&bs).unwrap().fields.insert("hpboss5".into(), 0.0);
    s.instances.get_mut(&bs).unwrap().alarms[0] = 9;
    s.dispatch(&b, bs, 3, 0).expect("Step_0 at hp 0");
    assert_eq!(s.instances[&bs].alarms[0], 1, "hp <= 0 arms the death beat to 1");

    // swordstunned: c_red wash and a dead stop.
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("hpboss5".into(), 1000.0);
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("poisoned".into(), 0.0);
        i.fields.insert("image_blend".into(), 0.0);
        i.fields.insert("hspeed".into(), 5.0);
        i.fields.insert("vspeed".into(), 5.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 stunned");
    assert_eq!(s.instances[&bs].fields["image_blend"], C_RED,
        "swordstunned == 1 paints c_red (255)");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.0, "and stops the boss dead");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0);

    // poisoned: c_green wins, because its branch is later in the body.
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 0.0);
        i.fields.insert("poisoned".into(), 1.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 poisoned");
    assert_eq!(s.instances[&bs].fields["image_blend"], C_GREEN,
        "poisoned == 1 paints c_green (32768)");

    // The ending room zeroes both velocities no matter what the player side said.
    s.current_room = RM_ENDING;
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("poisoned".into(), 0.0);
        i.fields.insert("hspeed".into(), 5.0);
        i.fields.insert("vspeed".into(), 5.0);
        i.fields.insert("image_xscale".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 in rm_ending");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.0, "rm_ending holds the boss still");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0);
    s.current_room = 0.0;
}

#[test]
fn boss5_draw_washes_white_while_flashing_and_clears_the_flag() {
    let b = bundle();
    // CODE 214 = Draw_0: identical shape to the final boss's CODE 231, with its
    // own code site and sprite.
    let (mut s, _p, bs) = boss5_scene(&b);
    let sprite = s.instances[&bs].fields["sprite_index"];
    s.instances.get_mut(&bs).unwrap().fields.insert("flashing".into(), 1.0);
    s.draws.clear();
    s.dispatch(&b, bs, 8, 0).expect("Draw_0 flashing");
    assert_eq!(s.draws.len(), 1, "CODE 214 draws the boss once while flashing");
    let d = &s.draws[0];
    assert_eq!(d.code, 214, "attributed to CODE 214");
    assert!(d.fog, "wrapped in d3d_set_fog(true, c_white, 0, 0)");
    assert_eq!(d.color, C_WHITE, "fog colour c_white (16777215)");
    assert_eq!(d.sprite, sprite as i32, "draw_self of the boss's own sprite");
    assert_eq!(s.instances[&bs].fields["flashing"], 0.0, "CODE 214 resets flashing");
    assert!(!s.fog_enabled, "and switches the fog back off");

    s.instances.get_mut(&bs).unwrap().fields.insert("image_blend".into(), 255.0);
    s.draws.clear();
    s.dispatch(&b, bs, 8, 0).expect("Draw_0 plain");
    assert_eq!(s.draws.len(), 1);
    assert!(!s.draws[0].fog, "no fog on the non-flashing path");
    assert_eq!(s.draws[0].color, 255, "image_blend passes through untouched");
    assert_eq!(s.draws[0].code, 214);
}


// ---- WL37 batch 2 ------------------------------------------------------------
// obj_bosspuff (190) CODE 792-802, obj_finalbosspuff (189) CODE 788-791,
// obj_boss3 (27) CODE 173/174/176/177/178/179/180/181/185/186, obj_boss2 (26)
// CODE 165/166/169/170, obj_boss4 (28) CODE 189/194/195/198,
// obj_finalbossgrenade (50) CODE 319/320/321/322/323/324,
// obj_finalbosslaser (49) CODE 318, obj_parry (12) CODE 36/37.

const BOSS2: i32 = 26;
const BOSS3: i32 = 27;
const BOSS4: i32 = 28;
const PARRYOBJ: i32 = 12;
const BULLETSPARK: i32 = 13;
const SWORD: i32 = 46;
const BOSS3PROJ: i32 = 55;
const BIGPUFF: i32 = 188;
/// CODE 320 / CODE 322 / CODE 794-802's snd_explode2.
const SND_EXPLODE2: i32 = 8;
/// CODE 318 / CODE 323's snd_impactsound2.
const SND_IMPACTSOUND2: i32 = 23;
/// CODE 195's shipped sprite constants (spr_boss4 / spr_boss4swing).
const SPR_BOSS4: f64 = 76.0;
const SPR_BOSS4SWING: f64 = 77.0;
/// CODE 322's explosion art (spr_bigexplosion).
const SPR_BIGEXPLOSION: f64 = 50.0;

/// Every instance of an object ever created in this scene, in id order.
fn ids_of(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter().filter(|(_, i)| i.object == object).map(|(id, _)| *id).collect()
}

/// Instances of `object` created since `before` (Destroy keeps the storage, so
/// this is the creation diff of one dispatch).
fn newly(before: &[i32], s: &Scene, object: i32) -> Vec<i32> {
    ids_of(s, object).into_iter().filter(|id| !before.contains(id)).collect()
}

fn sorted_xy(s: &Scene, ids: &[i32]) -> Vec<(f64, f64)> {
    let mut v: Vec<(f64, f64)> =
        ids.iter().map(|id| (s.instances[id].fields["x"], s.instances[id].fields["y"])).collect();
    v.sort_by(|a, b| a.partial_cmp(b).unwrap());
    v
}

/// Offsets from (x, y) of the instances of `object` created by one dispatch.
fn new_offsets(s: &Scene, before: &[i32], object: i32, x: f64, y: f64) -> Vec<(f64, f64)> {
    let mut v: Vec<(f64, f64)> = newly(before, s, object)
        .iter()
        .map(|id| (s.instances[id].fields["x"] - x, s.instances[id].fields["y"] - y))
        .collect();
    v.sort_by(|a, b| a.partial_cmp(b).unwrap());
    v
}

fn snap(s: &Scene) -> Vec<i32> {
    s.instances.keys().copied().collect()
}

/// A scene with a live player (parked) and one boss at (x, y).
fn boss_scene(b: &Bundle, object: i32, x: f64, y: f64) -> (Scene, i32, i32) {
    let mut s = scene(b);
    let p = player(&mut s, b, 500.0, 200.0);
    let bs = s.create(b, object, x, y).expect("boss");
    park(&mut s, p);
    (s, p, bs)
}

// ---- obj_bosspuff (190) ------------------------------------------------------

#[test]
fn bosspuff_create_arms_the_ten_slot_flash_clock() {
    let b = bundle();
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    // CODE 792 = obj_bosspuff Create_0: one alarm per flash beat, 1..100.
    let pf = s.create(&b, BOSSPUFF, 300.0, 200.0).expect("obj_bosspuff");
    let a = snapshot(&s, pf);
    assert_eq!(&a[0..10], &[1, 10, 20, 30, 40, 50, 60, 70, 80, 100],
        "CODE 792 arms the whole ten-slot flash clock");
    assert_eq!(&a[10..12], &[-1, -1], "CODE 792 leaves the two unused slots unarmed");
}

#[test]
fn bosspuff_flash_alarms_spawn_one_bigpuff_at_their_own_offsets() {
    let b = bundle();
    // CODE 794/795/796/797/798/799/800/801/802 = obj_bosspuff Alarm_8..Alarm_0:
    // each spawns exactly one obj_bigpuff (188) at its own offset from the puff,
    // then plays snd_explode2 behind the global.soundmute gate.
    //   (label, code id, alarm slot, dx, dy)
    let beats: [(&str, i32, i32, f64, f64); 9] = [
        ("CODE 802", 802, 0, 0.0, 0.0),
        ("CODE 801", 801, 1, 10.0, 0.0),
        ("CODE 800", 800, 2, -10.0, 0.0),
        ("CODE 799", 799, 3, 0.0, 10.0),
        ("CODE 798", 798, 4, 0.0, -10.0),
        ("CODE 797", 797, 5, 20.0, 0.0),
        ("CODE 796", 796, 6, -20.0, 0.0),
        ("CODE 795", 795, 7, 0.0, -10.0),
        ("CODE 794", 794, 8, 0.0, 10.0),
    ];
    for (label, code, slot, dx, dy) in beats {
        let mut s = scene(&b);
        let p = player(&mut s, &b, 500.0, 200.0);
        park(&mut s, p);
        let pf = s.create(&b, BOSSPUFF, 300.0, 200.0).expect("obj_bosspuff");
        let before = snap(&s);
        let alarms_before = snapshot(&s, pf);
        s.audio.clear();
        s.dispatch(&b, pf, 2, slot).expect("flash beat");
        assert_eq!(new_offsets(&s, &before, BIGPUFF, 300.0, 200.0), vec![(dx, dy)],
            "{label}: exactly one obj_bigpuff at ({dx}, {dy}) from the puff");
        assert_eq!(s.audio.len(), 1, "{label}: plays exactly one sound");
        assert_eq!(s.audio[0].sound, SND_EXPLODE2, "{label}: snd_explode2 (8)");
        assert_eq!(s.audio[0].code, code as usize,
            "{label}: the sound is attributed to the body that played it");
        assert_eq!(snapshot(&s, pf), alarms_before, "{label}: arms no timer of its own");
        assert!(s.instances[&pf].alive, "{label}: the puff itself survives its own beat");
    }

    // The gate: global.soundmute == 1 silences the beat, but the puff still spawns.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let pf = s.create(&b, BOSSPUFF, 300.0, 200.0).unwrap();
    s.globals.insert("soundmute".into(), 1.0);
    let before = snap(&s);
    s.audio.clear();
    s.dispatch(&b, pf, 2, 0).expect("muted beat");
    assert!(s.audio.is_empty(), "CODE 802 stays silent while soundmute == 1");
    assert_eq!(newly(&before, &s, BIGPUFF).len(), 1, "but the puff still spawns");
}

#[test]
fn bosspuff_and_finalbosspuff_last_alarms_destroy_them() {
    let b = bundle();
    // CODE 793 = obj_bosspuff Alarm_9: instance_destroy(), the end of the flash clock.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let pf = s.create(&b, BOSSPUFF, 300.0, 200.0).unwrap();
    s.dispatch(&b, pf, 2, 9).expect("Alarm_9");
    assert!(!s.instances[&pf].alive, "CODE 793 destroys the puff");

    // CODE 788 = obj_finalbosspuff Alarm_3: the same kill for the big puff.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 500.0, 200.0);
    park(&mut s, p);
    let pf = s.create(&b, FINALPUFF, 300.0, 200.0).unwrap();
    s.dispatch(&b, pf, 2, 3).expect("Alarm_3");
    assert!(!s.instances[&pf].alive, "CODE 788 destroys the final puff");
}

// ---- obj_finalbosspuff (189) -------------------------------------------------

#[test]
fn finalbosspuff_flash_alarms_spawn_bosspuffs_at_their_offsets() {
    let b = bundle();
    // CODE 791/790/789 = obj_finalbosspuff Alarm_0/1/2: expanding rings of
    // obj_bosspuff. The duplicated offsets are in the shipped bytecode, so the
    // assertion is on the full multiset of created positions.
    let beats: [(&str, i32, i32, Vec<(f64, f64)>); 3] = [
        ("CODE 791", 791, 0, vec![(40.0, 0.0), (-40.0, 0.0), (60.0, 0.0), (0.0, -40.0)]),
        ("CODE 790", 790, 1, vec![(60.0, 0.0), (-60.0, 0.0), (-60.0, 0.0), (0.0, -60.0)]),
        ("CODE 789", 789, 2, vec![(80.0, 0.0), (-80.0, 0.0), (80.0, 0.0), (0.0, -80.0), (0.0, 0.0)]),
    ];
    for (label, _code, slot, want) in beats {
        let mut s = scene(&b);
        let p = player(&mut s, &b, 500.0, 200.0);
        park(&mut s, p);
        let pf = s.create(&b, FINALPUFF, 300.0, 200.0).expect("obj_finalbosspuff");
        let before = snap(&s);
        s.audio.clear();
        s.dispatch(&b, pf, 2, slot).expect("flash beat");
        let mut want_sorted = want.clone();
        want_sorted.sort_by(|a, b| a.partial_cmp(b).unwrap());
        assert_eq!(new_offsets(&s, &before, BOSSPUFF, 300.0, 200.0), want_sorted,
            "{label}: the exact ring of obj_bosspuff offsets");
        assert!(s.audio.is_empty(), "{label}: spawns in silence");
        assert!(s.instances[&pf].alive, "{label}: the final puff survives its own beat");
    }
}

// ---- obj_boss3 (27) ----------------------------------------------------------

#[test]
fn boss3_alarm_11_charges_the_player_or_dashes_at_random() {
    let b = bundle();
    // CODE 173 = obj_boss3 Alarm_11: `if (obj_player.x <= x)` random dash
    // (vspeed = choose(-3, 3), hspeed = choose(-2, 2)); `else if
    // (obj_player.x >= x)` move_towards_point(player.x, player.y, 2). Both
    // branches end with alarm[11] = 20.
    let (mut s, p, bs) = boss_scene(&b, BOSS3, 300.0, 200.0);
    pin(&mut s, p, 500.0, 200.0);
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 11).expect("Alarm_11");
    assert_eq!(s.instances[&bs].fields["speed"], 2.0, "CODE 173 charges at speed 2");
    assert_eq!(s.instances[&bs].fields["hspeed"], 2.0, "straight at a player to the right");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0, "and level with them");
    assert_only_slot(&s, bs, &before, 11, 20, "CODE 173");

    // A player strictly to the left takes the random dash branch.
    pin(&mut s, p, 100.0, 200.0);
    s.dispatch(&b, bs, 2, 11).expect("Alarm_11 dash");
    let v = s.instances[&bs].fields["vspeed"];
    let h = s.instances[&bs].fields["hspeed"];
    assert!(v == -3.0 || v == 3.0, "CODE 173 chooses vspeed from {{-3, 3}}, got {v}");
    assert!(h == -2.0 || h == 2.0, "CODE 173 chooses hspeed from {{-2, 2}}, got {h}");
    assert_eq!(s.instances[&bs].alarms[11], 20, "and re-arms its own slot");

    // The `<=` test comes first: a player exactly on the boss's x still dashes
    // instead of charging.
    pin(&mut s, p, 300.0, 200.0);
    s.instances.get_mut(&bs).unwrap().fields.insert("vspeed".into(), 0.0);
    s.dispatch(&b, bs, 2, 11).expect("Alarm_11 at equal x");
    let v = s.instances[&bs].fields["vspeed"];
    assert!(v == -3.0 || v == 3.0, "CODE 173's `<=` branch wins at equal x, got {v}");
}

#[test]
fn boss3_poison_slot_bites_and_re_arms_itself() {
    let b = bundle();
    // CODE 174 = obj_boss3 Alarm_10: poisoned = 1, hpboss3 -= 0.25, one
    // obj_damage with damage = 0.25, alarm[10] = 30.
    let (mut s, p, bs) = boss_scene(&b, BOSS3, 300.0, 200.0);
    let hp0 = s.instances[&bs].fields["hpboss3"];
    assert!(hp0 > 0.0, "fixture: the boss starts alive");
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 10).expect("Alarm_10");
    assert_eq!(s.instances[&bs].fields["poisoned"], 1.0, "CODE 174 raises the poison flag");
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss3"], 0.25,
        "CODE 174 takes a quarter heart off hpboss3");
    assert_only_slot(&s, bs, &before, 10, 30, "CODE 174");
    let dmg = lives(&s, DAMAGE);
    assert_eq!(dmg.len(), 1, "one obj_damage number");
    assert_eq!(s.instances[&dmg[0]].fields["damage"], 0.25, "carrying damage = 0.25");
    assert_eq!((s.instances[&dmg[0]].fields["x"], s.instances[&dmg[0]].fields["y"]),
        (300.0, 200.0), "created at the boss's own coordinates");

    for _ in 0..30 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, bs, 300.0, 200.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss3"], 0.5,
        "CODE 174 self-fired once on its own 30-tick alarm");
    assert_eq!(s.instances[&bs].alarms[10], 30, "and re-armed its own slot");
    assert_eq!(created(&s, DAMAGE), 2, "two damage numbers in total");
}

#[test]
fn boss3_shot_slot_ladder_fires_one_projectile_and_hands_over() {
    let b = bundle();
    // CODE 176/177/178/180/181 = obj_boss3 Alarm_8/7/6/4/3: one
    // obj_boss3projectile (55) at (x - 50, y), then the next slot of the ring.
    //   (label, dispatch slot, next slot, next ticks)
    let ladder: [(&str, i32, usize, i32); 5] = [
        ("CODE 176", 8, 1, 30),
        ("CODE 177", 7, 8, 10),
        ("CODE 178", 6, 7, 10),
        ("CODE 180", 4, 6, 10),
        ("CODE 181", 3, 4, 10),
    ];
    for (label, slot, next_slot, next_ticks) in ladder {
        let (mut s, _p, bs) = boss_scene(&b, BOSS3, 300.0, 200.0);
        let before = snapshot(&s, bs);
        s.dispatch(&b, bs, 2, slot).expect("ring beat");
        let shots = lives(&s, BOSS3PROJ);
        assert_eq!(shots.len(), 1, "{label}: one obj_boss3projectile per beat");
        assert_eq!((s.instances[&shots[0]].fields["x"], s.instances[&shots[0]].fields["y"]),
            (250.0, 200.0), "{label}: spawned at the boss's own x - 50, y");
        assert_only_slot(&s, bs, &before, next_slot, next_ticks, label);
    }
}

#[test]
fn boss3_alarm_5_clears_the_sword_stun_only() {
    let b = bundle();
    // CODE 179 = obj_boss3 Alarm_5: `swordstunned = 0` and nothing else.
    let (mut s, _p, bs) = boss_scene(&b, BOSS3, 300.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("hspeed".into(), 5.0);
    }
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 5).expect("Alarm_5");
    assert_eq!(s.instances[&bs].fields["swordstunned"], 0.0, "CODE 179 clears the stun");
    assert_eq!(s.instances[&bs].fields["hspeed"], 5.0, "CODE 179 writes nothing else");
    assert_eq!(snapshot(&s, bs), before, "CODE 179 arms no timer");
}

#[test]
fn boss3_step_gates_the_death_beat_flips_bounces_and_blends() {
    let b = bundle();
    // CODE 185 = obj_boss3 Step_0: hp gates -> image_xscale = -1 every step ->
    // the (x + hspeed, y + vspeed) wall probe with move_bounce_all(0) -> stun
    // (c_red + dead stop) -> poison (c_green) -> rm_ending stop.
    let (mut s, _p, bs) = boss_scene(&b, BOSS3, 300.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.alarms[0] = 9;
        i.fields.insert("image_xscale".into(), 5.0);
        i.fields.insert("hspeed".into(), 2.0);
        i.fields.insert("vspeed".into(), -3.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    assert!(s.instances[&bs].fields["hpboss3"] > 0.0, "fixture: the boss starts alive");
    assert_eq!(s.call(&b, bs, "instance_place", &[302.0, 197.0, PAR_WALL as f64]).unwrap(), -4.0,
        "fixture: the (x+hspeed, y+vspeed) probe lane is clear");
    s.dispatch(&b, bs, 3, 0).expect("Step_0");
    assert_eq!(s.instances[&bs].alarms[0], 0, "hp >= 0 parks the death beat at 0");
    assert_eq!(s.instances[&bs].fields["image_xscale"], -1.0,
        "CODE 185 pins image_xscale = -1 on every single step");
    assert_eq!(s.instances[&bs].fields["hspeed"], 2.0, "no wall in the probe: hspeed intact");
    assert_eq!(s.instances[&bs].fields["vspeed"], -3.0, "and vspeed intact");

    // A wall under the probe: move_bounce_all(0) flips both components.
    let _w = s.create(&b, WALL, 300.0, 200.0).expect("wall under the boss");
    let probe = s.call(&b, bs, "instance_place", &[302.0, 197.0, PAR_WALL as f64]).unwrap();
    assert!(probe >= 0.0, "fixture: CODE 185's probe really sees the wall");
    s.dispatch(&b, bs, 3, 0).expect("Step_0 with a wall");
    assert_eq!(s.instances[&bs].fields["hspeed"], -2.0, "CODE 185 bounces hspeed");
    assert_eq!(s.instances[&bs].fields["vspeed"], 3.0, "CODE 185 bounces vspeed");

    // stun -> c_red and a dead stop; poison -> c_green (the later branch wins).
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 stunned");
    assert_eq!(s.instances[&bs].fields["image_blend"], C_RED, "swordstunned paints c_red (255)");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.0, "and stops the charge dead");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 0.0);
        i.fields.insert("poisoned".into(), 1.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 poisoned");
    assert_eq!(s.instances[&bs].fields["image_blend"], C_GREEN, "poisoned paints c_green (32768)");

    // hp <= 0 arms the death beat; the ending room holds the boss still.
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("hpboss3".into(), 0.0);
        i.fields.insert("poisoned".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 at hp 0");
    assert_eq!(s.instances[&bs].alarms[0], 1, "hp <= 0 arms the death beat to 1");
    s.current_room = RM_ENDING;
    s.instances.get_mut(&bs).unwrap().fields.insert("hspeed".into(), 5.0);
    s.instances.get_mut(&bs).unwrap().fields.insert("vspeed".into(), 5.0);
    s.dispatch(&b, bs, 3, 0).expect("Step_0 in rm_ending");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.0, "rm_ending holds the boss still");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0);
    s.current_room = 0.0;
}

// ---- obj_boss2 (26) ----------------------------------------------------------

#[test]
fn boss2_poison_slot_bites_and_re_arms_itself() {
    let b = bundle();
    // CODE 165 = obj_boss2 Alarm_6: poisoned = 1, hpboss2 -= 0.25, one obj_damage
    // with damage = 0.25, alarm[6] = 30.
    let (mut s, p, bs) = boss_scene(&b, BOSS2, 600.0, 200.0);
    let hp0 = s.instances[&bs].fields["hpboss2"];
    assert!(hp0 > 0.0, "fixture: the boss starts alive");
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 6).expect("Alarm_6");
    assert_eq!(s.instances[&bs].fields["poisoned"], 1.0, "CODE 165 raises the poison flag");
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss2"], 0.25,
        "CODE 165 takes a quarter heart off hpboss2");
    assert_only_slot(&s, bs, &before, 6, 30, "CODE 165");
    let dmg = lives(&s, DAMAGE);
    assert_eq!(dmg.len(), 1, "one obj_damage number");
    assert_eq!(s.instances[&dmg[0]].fields["damage"], 0.25, "carrying damage = 0.25");
    assert_eq!((s.instances[&dmg[0]].fields["x"], s.instances[&dmg[0]].fields["y"]),
        (600.0, 200.0), "created at the boss's own coordinates");

    for _ in 0..30 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, bs, 600.0, 200.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss2"], 0.5,
        "CODE 165 self-fired once on its own 30-tick alarm");
    assert_eq!(s.instances[&bs].alarms[6], 30, "and re-armed its own slot");
    assert_eq!(created(&s, DAMAGE), 2, "two damage numbers in total");
}

#[test]
fn boss2_alarm_5_clears_the_sword_stun_only() {
    let b = bundle();
    // CODE 166 = obj_boss2 Alarm_5: `swordstunned = 0` and nothing else.
    let (mut s, _p, bs) = boss_scene(&b, BOSS2, 600.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("hspeed".into(), 5.0);
    }
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 5).expect("Alarm_5");
    assert_eq!(s.instances[&bs].fields["swordstunned"], 0.0, "CODE 166 clears the stun");
    assert_eq!(s.instances[&bs].fields["hspeed"], 5.0, "CODE 166 writes nothing else");
    assert_eq!(snapshot(&s, bs), before, "CODE 166 arms no timer");
}

#[test]
fn boss2_step_gravity_facing_bands_and_the_death_beat() {
    let b = bundle();
    // CODE 169 = obj_boss2 Step_0: hp gates -> alarm[1] reseeded to 200 when it
    // has run out -> the (x, y + vspeed) ground probe sets gravity 0.6 / falling 1
    // or clears all three -> facing from the x > 800 / x < 512 bands -> hspeed
    // ±0.3 with image_xscale = -1 in BOTH branches (shipped asymmetry) -> stun ->
    // poison -> rm_ending stop.
    let (mut s, _p, bs) = boss_scene(&b, BOSS2, 600.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.alarms[0] = 9;
        i.alarms[1] = 0;
        i.fields.insert("facing".into(), 0.0);
        i.fields.insert("gravity".into(), 0.0);
        i.fields.insert("falling".into(), 0.0);
        i.fields.insert("vspeed".into(), 0.0);
        i.fields.insert("image_blend".into(), 0.0);
        i.fields.insert("image_xscale".into(), 0.0);
    }
    assert!(s.instances[&bs].fields["hpboss2"] > 0.0, "fixture: the boss starts alive");
    assert_eq!(s.call(&b, bs, "instance_place", &[600.0, 200.0, PAR_WALL as f64]).unwrap(), -4.0,
        "fixture: nothing is under the boss's own position");
    s.dispatch(&b, bs, 3, 0).expect("Step_0 airborne");
    assert_eq!(s.instances[&bs].alarms[0], 0, "hp >= 0 parks the death beat at 0");
    assert_eq!(s.instances[&bs].alarms[1], 200, "CODE 169 reseeds the expired a1 beat to 200");
    assert_eq!(s.instances[&bs].fields["gravity"], 0.6, "no ground below -> gravity 0.6");
    assert_eq!(s.instances[&bs].fields["falling"], 1.0, "and falling = 1");
    assert_eq!(s.instances[&bs].fields["hspeed"], -0.3, "facing 0 walks left at 0.3");
    assert_eq!(s.instances[&bs].fields["image_xscale"], -1.0,
        "CODE 169 pins xscale -1 in the facing-0 branch too");

    // Grounded: a wall under the probe clears gravity, vspeed and falling.
    let _w = s.create(&b, WALL, 600.0, 200.0).expect("ground under the boss");
    s.instances.get_mut(&bs).unwrap().fields.insert("vspeed".into(), 4.0);
    let probe = s.call(&b, bs, "instance_place", &[600.0, 204.0, PAR_WALL as f64]).unwrap();
    assert!(probe >= 0.0, "fixture: CODE 169's (x, y + vspeed) probe sees the ground");
    s.dispatch(&b, bs, 3, 0).expect("Step_0 grounded");
    assert_eq!(s.instances[&bs].fields["gravity"], 0.0, "ground -> gravity 0");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0, "and vspeed 0");
    assert_eq!(s.instances[&bs].fields["falling"], 0.0, "and falling 0");

    // The two facing bands, and the shipped asym=1 (xscale -1 on both sides).
    s.instances.get_mut(&bs).unwrap().fields.insert("x".into(), 900.0);
    s.instances.get_mut(&bs).unwrap().fields.insert("facing".into(), 1.0);
    s.dispatch(&b, bs, 3, 0).expect("Step_0 right band");
    assert_eq!(s.instances[&bs].fields["facing"], 0.0, "x > 800 forces facing 0");
    assert_eq!(s.instances[&bs].fields["hspeed"], -0.3, "and facing 0 walks left");
    pin(&mut s, bs, 300.0, 200.0);
    s.instances.get_mut(&bs).unwrap().fields.insert("facing".into(), 0.0);
    s.dispatch(&b, bs, 3, 0).expect("Step_0 left band");
    assert_eq!(s.instances[&bs].fields["facing"], 1.0, "x < 512 forces facing 1");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.3, "and facing 1 walks right");
    assert_eq!(s.instances[&bs].fields["image_xscale"], -1.0,
        "CODE 169 pins xscale -1 in the facing-1 branch too (shipped asym=1)");

    // stun / poison / hp gate / rm_ending.
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 1.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 stunned");
    assert_eq!(s.instances[&bs].fields["image_blend"], C_RED, "swordstunned paints c_red");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.0, "and stops the walk");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swordstunned".into(), 0.0);
        i.fields.insert("poisoned".into(), 1.0);
        i.fields.insert("image_blend".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 poisoned");
    assert_eq!(s.instances[&bs].fields["image_blend"], C_GREEN, "poisoned paints c_green");
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("hpboss2".into(), 0.0);
        i.fields.insert("poisoned".into(), 0.0);
    }
    s.dispatch(&b, bs, 3, 0).expect("Step_0 at hp 0");
    assert_eq!(s.instances[&bs].alarms[0], 1, "hp <= 0 arms the death beat to 1");
    s.current_room = RM_ENDING;
    s.instances.get_mut(&bs).unwrap().fields.insert("hspeed".into(), 5.0);
    s.instances.get_mut(&bs).unwrap().fields.insert("vspeed".into(), 5.0);
    s.dispatch(&b, bs, 3, 0).expect("Step_0 in rm_ending");
    assert_eq!(s.instances[&bs].fields["hspeed"], 0.0, "rm_ending holds the boss still");
    assert_eq!(s.instances[&bs].fields["vspeed"], 0.0);
    s.current_room = 0.0;
}

// ---- obj_boss4 (28) ----------------------------------------------------------

#[test]
fn boss4_poison_slot_bites_and_re_arms_itself() {
    let b = bundle();
    // CODE 189 = obj_boss4 Alarm_10: poisoned = 1, hpboss4 -= 0.25, one obj_damage
    // with damage = 0.25, alarm[10] = 30.
    let (mut s, p, bs) = boss_scene(&b, BOSS4, 300.0, 200.0);
    let hp0 = s.instances[&bs].fields["hpboss4"];
    assert!(hp0 > 0.0, "fixture: the boss starts alive");
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 10).expect("Alarm_10");
    assert_eq!(s.instances[&bs].fields["poisoned"], 1.0, "CODE 189 raises the poison flag");
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss4"], 0.25,
        "CODE 189 takes a quarter heart off hpboss4");
    assert_only_slot(&s, bs, &before, 10, 30, "CODE 189");
    let dmg = lives(&s, DAMAGE);
    assert_eq!(dmg.len(), 1, "one obj_damage number");
    assert_eq!(s.instances[&dmg[0]].fields["damage"], 0.25, "carrying damage = 0.25");

    for _ in 0..30 {
        pin(&mut s, p, 500.0, 200.0);
        pin(&mut s, bs, 300.0, 200.0);
        s.tick(&b).unwrap();
    }
    assert_eq!(hp0 - s.instances[&bs].fields["hpboss4"], 0.5,
        "CODE 189 self-fired once on its own 30-tick alarm");
    assert_eq!(s.instances[&bs].alarms[10], 30, "and re-armed its own slot");
    assert_eq!(created(&s, DAMAGE), 2, "two damage numbers in total");
}

#[test]
fn boss4_alarm_2_ends_the_swing_and_releases_two_projectiles() {
    let b = bundle();
    // CODE 194 = obj_boss4 Alarm_2: `swinging = 0` first, then - only while
    // chasing - two obj_fireprojectile (54) at (x + 30, y - 10) and (x - 30, y).
    let (mut s, _p, bs) = boss_scene(&b, BOSS4, 300.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swinging".into(), 1.0);
        i.fields.insert("chasing".into(), 1.0);
    }
    let before = snap(&s);
    s.dispatch(&b, bs, 2, 2).expect("Alarm_2");
    assert_eq!(s.instances[&bs].fields["swinging"], 0.0, "CODE 194 clears the swing latch");
    assert_eq!(new_offsets(&s, &before, FIREPROJ, 300.0, 200.0),
        vec![(-30.0, 0.0), (30.0, -10.0)],
        "CODE 194 releases one projectile at (x+30, y-10) and one at (x-30, y)");

    // Not chasing: the latch still clears, but nothing is released.
    let (mut s, _p, bs) = boss_scene(&b, BOSS4, 300.0, 200.0);
    {
        let i = s.instances.get_mut(&bs).unwrap();
        i.fields.insert("swinging".into(), 1.0);
        i.fields.insert("chasing".into(), 0.0);
    }
    let before = snap(&s);
    s.dispatch(&b, bs, 2, 2).expect("Alarm_2 idle");
    assert_eq!(s.instances[&bs].fields["swinging"], 0.0, "CODE 194 clears the latch either way");
    assert!(newly(&before, &s, FIREPROJ).is_empty(), "and releases nothing while not chasing");
}

#[test]
fn boss4_alarm_1_cycles_the_swing_pose_behind_the_room_gate() {
    let b = bundle();
    // CODE 195 = obj_boss4 Alarm_1, gated on `room != rm_ending`:
    //   swinging == 1 -> sprite_index = spr_boss4swing (77) and alarm[2] = 10;
    //   swinging == 0 -> sprite_index = spr_boss4 (76);
    // then alarm[1] = 30 either way.
    let (mut s, _p, bs) = boss_scene(&b, BOSS4, 300.0, 200.0);
    s.instances.get_mut(&bs).unwrap().fields.insert("swinging".into(), 1.0);
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 1).expect("Alarm_1 swinging");
    assert_eq!(s.instances[&bs].fields["sprite_index"], SPR_BOSS4SWING,
        "CODE 195 swings to spr_boss4swing (77)");
    let after = snapshot(&s, bs);
    assert_eq!(after[2], 10, "CODE 195 arms the swing-end beat at 10");
    assert_eq!(after[1], 30, "CODE 195 re-arms the pose cycle at 30");
    for i in 0..12 {
        if i == 1 || i == 2 { continue; }
        assert_eq!(after[i], before[i], "CODE 195 leaves slot {i} alone");
    }

    s.instances.get_mut(&bs).unwrap().fields.insert("swinging".into(), 0.0);
    s.dispatch(&b, bs, 2, 1).expect("Alarm_1 idle");
    assert_eq!(s.instances[&bs].fields["sprite_index"], SPR_BOSS4,
        "CODE 195 drops back to spr_boss4 (76) when not swinging");
    assert_eq!(s.instances[&bs].alarms[1], 30, "and still re-arms the cycle");
    assert_eq!(s.instances[&bs].alarms[2], 10, "leaving the swing-end beat as it was");

    // rm_ending: nothing at all happens.
    s.current_room = RM_ENDING;
    s.instances.get_mut(&bs).unwrap().fields.insert("sprite_index".into(), -7.0);
    let before = snapshot(&s, bs);
    s.dispatch(&b, bs, 2, 1).expect("Alarm_1 gated");
    assert_eq!(s.instances[&bs].fields["sprite_index"], -7.0,
        "CODE 195 is gated on `room != rm_ending`");
    assert_eq!(snapshot(&s, bs), before, "and arms nothing in the ending room");
    s.current_room = 0.0;
}

// ---- the remaining boss Draw_0 bodies ----------------------------------------

#[test]
fn boss2_boss3_boss4_draw_wash_white_while_flashing_and_clear_the_flag() {
    let b = bundle();
    // CODE 170 / CODE 186 / CODE 198 = Draw_0 of obj_boss2 / obj_boss3 /
    // obj_boss4: the same `d3d_set_fog(true, c_white, 0, 0)` wrap of draw_self()
    // and the same `flashing = 0` reset, each attributed to its own code site.
    let cases: [(&str, usize, i32); 3] =
        [("CODE 170", 170, BOSS2), ("CODE 186", 186, BOSS3), ("CODE 198", 198, BOSS4)];
    for (label, code, object) in cases {
        let (mut s, _p, bs) = boss_scene(&b, object, 300.0, 200.0);
        let sprite = s.instances[&bs].fields["sprite_index"];
        s.instances.get_mut(&bs).unwrap().fields.insert("flashing".into(), 1.0);
        s.draws.clear();
        s.dispatch(&b, bs, 8, 0).expect("Draw_0 flashing");
        assert_eq!(s.draws.len(), 1, "{label} draws the boss exactly once while flashing");
        assert_eq!(s.draws[0].code, code, "{label} is attributed to its own body");
        assert!(s.draws[0].fog, "{label} wraps the draw in d3d_set_fog(true, ...)");
        assert_eq!(s.draws[0].color, C_WHITE, "{label} fog colour c_white (16777215)");
        assert_eq!(s.draws[0].sprite, sprite as i32, "{label} draws its own sprite");
        assert_eq!(s.instances[&bs].fields["flashing"], 0.0, "{label} resets flashing to 0");
        assert!(!s.fog_enabled, "{label} switches the fog back off");

        s.instances.get_mut(&bs).unwrap().fields.insert("image_blend".into(), 255.0);
        s.draws.clear();
        s.dispatch(&b, bs, 8, 0).expect("Draw_0 plain");
        assert_eq!(s.draws.len(), 1);
        assert!(!s.draws[0].fog, "{label}: no fog on the non-flashing path");
        assert_eq!(s.draws[0].color, 255, "{label}: image_blend passes straight through");
        assert_eq!(s.draws[0].code, code);
    }
}

// ---- obj_finalbossgrenade (50) ----------------------------------------------

#[test]
fn grenade_create_destroy_fuse_and_hard_kill() {
    let b = bundle();
    // CODE 319 = obj_finalbossgrenade Create_0: canhit = 0, gravity = 0.6,
    // speed = 3, alarm[0] = 45 (fuse), alarm[1] = 63 (hard lifetime).
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).expect("grenade");
    park(&mut s, p);
    assert_eq!(s.instances[&g].fields["canhit"], 0.0, "CODE 319 opens the hit latch");
    assert_eq!(s.instances[&g].fields["gravity"], 0.6, "CODE 319 arcs under gravity 0.6");
    assert_eq!(s.instances[&g].fields["speed"], 3.0, "CODE 319 throws it at speed 3");
    assert_eq!(s.instances[&g].alarms[0], 45, "the 45-tick fuse");
    assert_eq!(s.instances[&g].alarms[1], 63, "and the 63-tick hard lifetime");

    // CODE 320 = Destroy_0: snd_explode2 (8) behind the soundmute gate.
    s.audio.clear();
    s.destroy(&b, g).expect("destroy");
    assert_eq!(s.audio.len(), 1, "CODE 320 plays exactly one sound");
    assert_eq!(s.audio[0].sound, SND_EXPLODE2, "snd_explode2 = 8");
    assert_eq!(s.audio[0].code, 320, "attributed to CODE 320");

    // CODE 321 = Alarm_1: action_kill_object() - the hard lifetime.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    s.audio.clear();
    s.dispatch(&b, g, 2, 1).expect("Alarm_1");
    assert!(!s.instances[&g].alive, "CODE 321 hard-kills the grenade");
    assert_eq!(s.audio.len(), 1, "through its own Destroy body (CODE 320)");
    assert_eq!(s.audio[0].sound, SND_EXPLODE2);
    assert_eq!(s.audio[0].code, 320, "attributed to the Destroy body");

    // CODE 322 = Alarm_0 (the fuse): swap to the explosion art, stop dead, snd 8.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).unwrap();
    park(&mut s, p);
    {
        let i = s.instances.get_mut(&g).unwrap();
        i.fields.insert("image_index".into(), 7.0);
        i.fields.insert("sprite_index".into(), 97.0);
        i.fields.insert("hspeed".into(), 5.0);
        i.fields.insert("vspeed".into(), -5.0);
    }
    s.audio.clear();
    s.dispatch(&b, g, 2, 0).expect("Alarm_0");
    assert_eq!(s.instances[&g].fields["sprite_index"], SPR_BIGEXPLOSION,
        "CODE 322 swaps to spr_bigexplosion (50)");
    assert_eq!(s.instances[&g].fields["image_index"], 0.0, "and restarts the animation");
    assert_eq!(s.instances[&g].fields["hspeed"], 0.0, "the grenade stops dead at the blast");
    assert_eq!(s.instances[&g].fields["vspeed"], 0.0);
    assert_eq!(s.audio.len(), 1, "and plays its blast sound");
    assert_eq!(s.audio[0].sound, SND_EXPLODE2, "snd_explode2 again");
    assert_eq!(s.audio[0].code, 322, "attributed to CODE 322");
    assert!(s.instances[&g].alive, "the blast sprite plays out on the object");

    // CODE 324 = Collision 34 (par_wall): the bounce, same as the slime's.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 2000.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).unwrap();
    let _w = s.create(&b, WALL, 290.0, 200.0).expect("wall to bounce off");
    park(&mut s, p);
    {
        let i = s.instances.get_mut(&g).unwrap();
        i.fields.insert("hspeed".into(), 3.0);
        i.fields.insert("vspeed".into(), -2.0);
    }
    s.dispatch(&b, g, 4, PAR_WALL).expect("Collision 34");
    assert_eq!(s.instances[&g].fields["hspeed"], -3.0, "CODE 324 flips hspeed");
    assert_eq!(s.instances[&g].fields["vspeed"], 2.0, "CODE 324 flips vspeed");
    assert!(s.instances[&g].alive, "a bounce does not detonate the grenade");
}

#[test]
fn grenade_step_damages_the_player_arms_itself_and_can_be_parried() {
    let b = bundle();
    // CODE 323 = obj_finalbossgrenade Step_0: the sword parry first (obj_parry
    // 12 + instance_destroy), then image_angle = direction, then the player hit:
    // snd_impactsound2 (23), the player's flashing / knock side / alarms
    // 22/10/25, one heart, and the grenade's own alarm[0] = 1 with canhit = 1.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let g = s.create(&b, GRENADE, 300.0, 200.0).expect("grenade on top of the player");
    let probe = s.call(&b, g, "instance_place", &[300.0, 200.0, P as f64]).unwrap();
    assert!(probe >= 0.0, "fixture: the grenade's own box really overlaps the player");
    let h0 = s.globals["health1"];
    s.audio.clear();
    s.dispatch(&b, g, 3, 0).expect("Step_0 hit");
    assert_eq!(h0 - s.globals["health1"], 1.0, "CODE 323 costs the player one heart");
    assert_eq!(s.instances[&p].fields["flashing"], 1.0, "and flashes them");
    assert_eq!(s.instances[&g].fields["canhit"], 1.0, "CODE 323 latches canhit");
    assert_eq!(s.instances[&g].alarms[0], 1, "and arms its own detonation beat");
    assert!(s.audio.iter().any(|a| a.sound == SND_IMPACTSOUND2), "snd_impactsound2 (23)");
    assert_eq!(s.instances[&p].fields["invulnerable"], 0.0,
        "at exactly equal x neither knock side is taken");
    assert_eq!(s.instances[&p].fields["invulnerable2"], 0.0);
    assert_eq!(s.instances[&g].fields["image_angle"], s.instances[&g].fields["direction"],
        "CODE 323 keeps image_angle locked to direction");
    s.dispatch(&b, g, 3, 0).expect("Step_0 latched");
    assert_eq!(s.globals["health1"], h0 - 1.0, "canhit blocks the second hit");

    // The knock side: a grenade to the right of the player.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 300.0, 200.0);
    let g = s.create(&b, GRENADE, 305.0, 200.0).expect("grenade right of the player");
    let hs = s.instances[&g].fields["hspeed"];
    let vs = s.instances[&g].fields["vspeed"];
    assert!(s.call(&b, g, "instance_place", &[305.0 + hs, 200.0 + vs, P as f64]).unwrap() >= 0.0,
        "fixture: the (x + hspeed, y + vspeed) probe overlaps the player");
    s.dispatch(&b, g, 3, 0).expect("Step_0 knock");
    assert_eq!(s.instances[&p].fields["invulnerable"], 1.0,
        "grenade.x > player.x takes the first knock side");
    assert_eq!(s.instances[&p].fields["sliding1"], 1.0);
    assert_eq!(s.instances[&p].alarms[7], 22, "and arms the player's own 22");
    assert_eq!(s.instances[&p].alarms[4], 10, "and 10");
    assert_eq!(s.instances[&p].alarms[8], 25, "and 25");

    // Parry: the sword intercepts, an obj_parry (12) spark appears, the grenade dies.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let sw = s.create(&b, SWORD, 300.0, 200.0).expect("sword");
    let g = s.create(&b, GRENADE, 300.0, 200.0).expect("grenade on the sword");
    park(&mut s, p);
    s.dispatch(&b, g, 3, 0).expect("Step_0 parry");
    assert!(!s.instances[&g].alive, "CODE 323: the sword intercepts the grenade");
    assert_eq!(count(&s, PARRYOBJ), 1, "one obj_parry spark");
    assert!(s.instances[&sw].alive, "the sword survives the parry");
}

// ---- obj_finalbosslaser (49) -------------------------------------------------

#[test]
fn laser_step_costs_a_heart_arms_its_death_and_survives_the_impact() {
    let b = bundle();
    // CODE 318 = obj_finalbosslaser Step_0: the sword parry, the par_wall death
    // (obj_bulletspark 13), image_angle = direction, then the player hit. The hit
    // does NOT consume the laser - it arms alarm[0] = 1 and latches canhit.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 310.0, 200.0); // off-axis: the knock chain needs x != player.x
    let lz = s.create(&b, LASER, 300.0, 200.0).expect("laser");
    let h0 = s.globals["health1"];
    s.audio.clear();
    s.dispatch(&b, lz, 3, 0).expect("Step_0 hit");
    assert_eq!(h0 - s.globals["health1"], 1.0, "CODE 318 costs the player one heart");
    assert_eq!(s.instances[&lz].fields["canhit"], 1.0, "CODE 318 latches the single-hit flag");
    assert!(s.instances[&lz].alive, "the laser survives its own hit");
    assert_eq!(s.instances[&lz].alarms[0], 1, "and arms the laser's own alarm[0] = 1");
    assert!(s.audio.iter().any(|a| a.sound == SND_IMPACTSOUND2), "snd_impactsound2 (23)");
    let pi = &s.instances[&p];
    assert_eq!(pi.fields["flashing"], 1.0, "the player is flashed");
    assert_eq!(pi.fields["invulnerable2"], 1.0, "laser.x < player.x takes the second knock side");
    assert_eq!(pi.fields["sliding2"], 1.0);
    assert_eq!(pi.alarms[7], 22);
    assert_eq!(pi.alarms[4], 10);
    assert_eq!(pi.alarms[8], 25);
    assert_eq!(s.instances[&lz].fields["image_angle"], s.instances[&lz].fields["direction"],
        "CODE 318 pins image_angle to direction");

    // Parry: the sword intercepts -> obj_parry (12), laser dies, sword survives.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let sw = s.create(&b, SWORD, 300.0, 200.0).expect("sword");
    let lz = s.create(&b, LASER, 300.0, 200.0).expect("laser on the sword");
    park(&mut s, p);
    s.dispatch(&b, lz, 3, 0).expect("Step_0 parry");
    assert!(!s.instances[&lz].alive, "CODE 318: the sword destroys the beam");
    assert_eq!(count(&s, PARRYOBJ), 1, "one obj_parry spark");
    assert!(s.instances[&sw].alive, "the sword survives");

    // Wall: the beam dies on par_wall and leaves an obj_bulletspark (13).
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let _w = s.create(&b, WALL, 305.0, 200.0).expect("wall");
    let lz = s.create(&b, LASER, 300.0, 200.0).expect("laser");
    park(&mut s, p);
    let hit = s.call(&b, lz, "instance_place", &[300.0, 200.0, PAR_WALL as f64]).unwrap();
    assert!(hit >= 0.0, "fixture: the beam's own box overlaps the wall");
    s.dispatch(&b, lz, 3, 0).expect("Step_0 wall");
    assert!(!s.instances[&lz].alive, "CODE 318: the wall destroys the beam");
    assert_eq!(count(&s, BULLETSPARK), 1, "one obj_bulletspark");
}

// ---- obj_parry (12) ----------------------------------------------------------

#[test]
fn parry_spark_lives_exactly_eight_ticks() {
    let b = bundle();
    // CODE 36 = obj_parry Create_0: `alarm[0] = 8`. CODE 37 = obj_parry Alarm_0:
    // `instance_destroy()` - together the spark's whole lifetime.
    let mut s = scene(&b);
    let p = player(&mut s, &b, 100.0, 100.0);
    let pa = s.create(&b, PARRYOBJ, 300.0, 200.0).expect("obj_parry");
    park(&mut s, p);
    assert_eq!(s.instances[&pa].alarms[0], 8, "CODE 36 arms the 8-tick spark clock");
    let a = snapshot(&s, pa);
    assert!(a.iter().enumerate().all(|(i, v)| i == 0 || *v == -1),
        "CODE 36 arms nothing but slot 0");
    assert!(s.instances[&pa].alive);
    for t in 1..8 {
        pin(&mut s, p, 100.0, 100.0);
        s.tick(&b).unwrap();
        assert!(s.instances[&pa].alive, "the spark is still there after {t} ticks");
        assert_eq!(s.instances[&pa].alarms[0], 8 - t, "its clock reads {t} ticks down");
    }
    pin(&mut s, p, 100.0, 100.0);
    s.tick(&b).unwrap();
    assert!(!s.instances[&pa].alive, "CODE 37 destroys the spark on the eighth tick");
}
