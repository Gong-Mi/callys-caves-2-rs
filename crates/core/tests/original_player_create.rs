//! Standalone: rustc --edition=2021 --test crates/core/tests/original_player_create.rs -o /tmp/player-create-tests
//! Oracle transcribed from 0000__gml_Object_obj_player_Create_0.gml, not final-state defaults.
#[path = "../src/original_player_create.rs"]
mod original_player_create;

use original_player_create::{create, PlayerCreateRuntime};

#[derive(Debug, PartialEq)]
enum Event {
    SelfWrite(&'static str, f64),
    GlobalWrite(&'static str, f64),
    RoomRead,
    Alarm(usize, f64),
    DoubleClick(bool),
}
use Event::{Alarm as A, DoubleClick as D, GlobalWrite as G, RoomRead as R, SelfWrite as S};

struct RecordingRuntime {
    room: f64,
    events: Vec<Event>,
}
impl PlayerCreateRuntime for RecordingRuntime {
    fn write_self(&mut self, field: &'static str, value: f64) {
        self.events.push(S(field, value));
    }
    fn write_global(&mut self, field: &'static str, value: f64) {
        self.events.push(G(field, value));
    }
    fn read_room(&mut self) -> f64 {
        self.events.push(R);
        self.room
    }
    fn write_alarm(&mut self, index: usize, value: f64) {
        self.events.push(A(index, value));
    }
    fn device_mouse_dbclick_enable(&mut self, enabled: bool) {
        self.events.push(D(enabled));
    }
}

fn run(room: f64, ending: f64) -> Vec<Event> {
    let mut rt = RecordingRuntime { room, events: Vec::new() };
    create(&mut rt, ending);
    rt.events
}

// Independent, explicit source-order oracle; no field sorting or deduplication.
fn expected(ending: bool) -> Vec<Event> {
    let mut events = vec![
        S("flashing", 0.0),
        S("assaultfire", 4.0),
        S("sliding1", 0.0),
        S("sliding2", 0.0),
        S("invulnerable2", 0.0),
        G("gemsfromhouse", 0.0),
        G("warpedfromlloyd", 0.0),
        G("roomcamefrom", 0.0),
        G("roomstart", 0.0),
        R,
    ];
    if ending {
        events.push(S("hspeed", 1.0));
    }
    events.extend([
        G("rebuff", 0.0),
        S("throwingboomerang", 0.0),
        G("keydrop", 2.0),
        A(10, 30.0),
        G("warplock", 0.0),
        D(false),
        A(11, 300.0),
        G("playerdied", 0.0),
        G("storemenu", 0.0),
        G("musicmute", 0.0),
        G("soundmute", 0.0),
        G("health1", 4.0),
        S("playerdied", 0.0),
        S("invulnerable", 0.0),
        G("coinpickup", 0.0),
        G("swing", 1.0),
        S("hspeed", 0.0),
        S("vspeed", 0.0),
        S("hsp", 0.0),
        S("vsp", 0.0),
        S("grav", 1.0),
        S("grounded", 1.0),
        S("friction", 0.08),
        S("djump", 0.0),
        S("tjump", 0.0),
        G("pistol", 1.0),
        G("shotgun", 0.0),
        G("powerupgrade", 0.0),
        G("assaultrifle", 0.0),
        G("shotgun", 0.0),
        G("rocket", 0.0),
        G("laser", 0.0),
        G("icegun", 0.0),
        G("bladegun", 0.0),
        G("flamethrower", 0.0),
        G("bow", 0.0),
        G("boomerang", 0.0),
        G("spikegun", 0.0),
        G("bombgun", 0.0),
        S("facing", 0.0),
        S("hpupgrade2", 0.0),
        S("hpupgrade3", 0.0),
        S("hpupgrade4", 0.0),
        S("hpupgrade5", 0.0),
        S("hpupgrade6", 0.0),
        S("hpupgrade7", 0.0),
        S("hpupgrade8", 0.0),
        S("hpupgrade9", 0.0),
        S("hpupgrade10", 0.0),
        S("hpupgrade11", 0.0),
        S("hpupgrade12", 0.0),
        S("hpupgrade13", 0.0),
        S("hpupgrade14", 0.0),
        S("hpupgrade15", 0.0),
        S("hpupgrade16", 0.0),
        S("hpupgrade17", 0.0),
        S("hpupgrade18", 0.0),
        S("hpupgrade19", 0.0),
        S("hpupgrade20", 0.0),
    ]);
    events
}

#[test]
fn non_ending_preserves_every_event_in_source_order() {
    assert_eq!(run(6.0, 7.0), expected(false));
}

#[test]
fn ending_preserves_every_event_including_overwritten_hspeed() {
    assert_eq!(run(7.0, 7.0), expected(true));
}

#[test]
fn hpupgrade_range_is_exact_and_complete_in_both_branches() {
    for room in [6.0, 7.0] {
        let events = run(room, 7.0);
        let upgrades: Vec<_> = events.iter().filter_map(|e| match e {
            S(name, value) if name.starts_with("hpupgrade") => Some((*name, *value)),
            _ => None,
        }).collect();
        let names: Vec<_> = (2..=20).map(|i| format!("hpupgrade{i}")).collect();
        let wanted: Vec<_> = names.iter().map(|name| (name.as_str(), 0.0)).collect();
        assert_eq!(upgrades, wanted);
    }
}

#[test]
fn duplicate_shotgun_and_hspeed_overwrite_are_not_optimized_away() {
    for room in [6.0, 7.0] {
        let events = run(room, 7.0);
        let shotgun: Vec<_> = events.iter().filter(|e| matches!(e, G("shotgun", _))).collect();
        assert_eq!(shotgun, vec![&G("shotgun", 0.0), &G("shotgun", 0.0)]);
        let speeds: Vec<_> = events.iter().filter_map(|e| match e {
            S("hspeed", v) => Some(*v),
            _ => None,
        }).collect();
        assert_eq!(speeds, if room == 7.0 { vec![1.0, 0.0] } else { vec![0.0] });
    }
}

#[test]
fn ending_argument_is_not_a_hardcoded_room_id() {
    assert_eq!(run(1234.0, 1234.0), expected(true));
    assert_eq!(run(1234.0, 1235.0), expected(false));
}
