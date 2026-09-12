//! Audio voice domain: audio_play_sound / audio_is_playing / stop / pause /
//! gain over real Scene state, gated through the REAL original code
//! gml_Object_obj_weaponswap_Alarm_0 (CODE 519). The stub returned Ok(0.0)
//! for every query, which restarted BGM every music tick and stacked SFX.
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;

fn bundle() -> callys_core::code_vm::Bundle {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let p = Path::new(manifest_dir).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

const SND_WEAPONSWAP: f64 = 412.0; // original asset id pushed by CODE 519
const SND_OTHER: f64 = 413.0;

#[test]
fn audio_play_query_stop_form_a_real_voice_state() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);

    assert_eq!(s.audio_is_playing_sound(SND_WEAPONSWAP), false, "nothing playing yet");

    let v1 = s.call_audio_play(SND_WEAPONSWAP, 0.0, false);
    assert!(v1 > 0.0, "play must return a real voice handle");
    assert_eq!(s.audio_is_playing_sound(SND_WEAPONSWAP), true, "voice must report playing");
    assert_eq!(s.audio_is_playing_sound(SND_OTHER), false, "gates must not cross sounds");

    s.call_audio_stop_sound(SND_WEAPONSWAP);
    assert_eq!(s.audio_is_playing_sound(SND_WEAPONSWAP), false, "stop_sound must clear the voice");

    // Gate reopens: a second play issues a second audible command.
    s.call_audio_play(SND_WEAPONSWAP, 0.0, false);
    assert_eq!(s.audio_is_playing_sound(SND_WEAPONSWAP), true);
    assert_eq!(s.audio.len(), 2, "each gated play emits its own AudioCommand");
}

#[test]
fn looping_voices_survive_ticks_and_stop_all_pause_all_resume_all() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);

    s.call_audio_play(SND_OTHER, 0.0, true); // BGM-style looping voice
    s.tick(&b).expect("tick");
    assert_eq!(s.audio_is_playing_sound(SND_OTHER), true, "looping BGM must keep playing across ticks");

    s.call_audio_pause_all();
    assert_eq!(s.audio_is_playing_sound(SND_OTHER), false, "paused voice is not playing");
    s.call_audio_resume_all();
    assert_eq!(s.audio_is_playing_sound(SND_OTHER), true, "resume must restore the voice");

    s.call_audio_stop_all();
    assert_eq!(s.audio_is_playing_sound(SND_OTHER), false, "stop_all must clear every voice");
}

#[test]
fn original_weaponswap_alarm_gates_repeat_plays() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.globals.insert("weaponswapped".into(), 0.0);
    s.globals.insert("soundmute".into(), 0.0);

    let obj_weaponswap = b.objects.iter().find(|o| o.name == "obj_weaponswap")
        .map(|o| o.id).expect("obj_weaponswap in bundle");
    let inst = s.create(&b, obj_weaponswap, 0.0, 0.0).expect("create weaponswap");
    // CODE 519 spawns obj_foundweapon at obj_player.x/y (selector 0 = object id 0).
    s.create(&b, 0, 100.0, 100.0).expect("create obj_player for the weaponswap spawn");

    s.dispatch(&b, inst, 2, 0).expect("weaponswap Alarm 0 first run");
    let after_first = s.audio.len();
    assert!(after_first >= 1, "first alarm must play the swap sound");
    // Original CODE 519 increments global.weaponswapped twice per run
    // (two sequential +1 stores preserved from the bytecode).
    assert_eq!(s.globals["weaponswapped"], 2.0, "alarm must count the swap (x2 original stores)");

    // Second run inside the same undrained window: original gate
    // if (!audio_is_playing(snd_weaponswap)) must suppress the repeat.
    s.dispatch(&b, inst, 2, 0).expect("weaponswap Alarm 0 second run");
    assert_eq!(s.audio.len(), after_first, "gate must suppress stacking while the sound plays");
    assert_eq!(s.globals["weaponswapped"], 4.0);

    // Host drains the audible commands: non-looping voices retire, gate reopens.
    let drained = s.drain_audio();
    assert_eq!(drained.len(), after_first, "drain must return the audible commands");
    s.dispatch(&b, inst, 2, 0).expect("weaponswap Alarm 0 third run");
    assert_eq!(s.audio.len(), 1, "after drain the gate must allow exactly one fresh play");
}

#[test]
fn object_exists_checks_the_bundle_resource_table() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    let real_id = b.objects.iter().map(|o| o.id).max().expect("objects present") as f64;
    assert_eq!(s.call_object_exists(real_id), true);
    assert_eq!(s.call_object_exists(9999.0), false, "unknown object id must not exist");
}
