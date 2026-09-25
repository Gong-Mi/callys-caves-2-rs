#![allow(dead_code)]
// Standalone rustc --test uses the actual production traits and dispatcher.
#[path = "../src/original_player.rs"] mod original_player;
#[path = "../src/original_player_combat.rs"] mod original_player_combat;
#[path = "../src/original_player_create.rs"] mod original_player_create;
#[path = "../src/original_projectile_create.rs"] mod original_projectile_create;
#[path = "../src/original_events.rs"] mod original_events;
#[path = "../src/original_startup.rs"] mod original_startup;
#[path = "../src/original_player_startup.rs"] mod original_player_startup;
use original_events::{EventRuntime, Object};
use original_startup::*;
use original_player_startup::*;
use std::collections::HashMap;

#[derive(Debug, Clone, PartialEq)]
enum E {
    Read(usize, &'static str), Write(usize, &'static str, f64), Global(&'static str, f64),
    Alarm(usize, usize, f64), Choose(Vec<f64>), Randomize, Range(f64, f64),
    Spawn(usize, usize, f64, f64, &'static str), Return(usize, usize),
    Deactivate(usize, bool), Activate(&'static str), Surface(bool), Mouse(f64), Audio(f64, f64, bool),
    AdColony(&'static str, &'static str, &'static str),
    FileExists(&'static str), IniOpen(&'static str), IniClose,
    IniRead(&'static str, &'static str, f64), IniWrite(&'static str, &'static str, f64),
}

// Activation is TRACE ONLY, deliberately not production engine semantics.
// This host tests synchronous Create/self restoration, not visibility or ticking.
struct Host {
    current: usize, fields: Vec<HashMap<&'static str, f64>>, globals: HashMap<&'static str, f64>,
    events: Vec<E>, resources: StartupResources, coordinate_read: usize, mutate_coordinates: bool,
    choices: usize, nested_intro: bool, files: HashMap<&'static str, bool>,
    ini_store: HashMap<(&'static str, &'static str), f64>,
}

impl Host {
    fn new() -> Self {
        Self {
            current: 0,
            fields: vec![HashMap::from([("x", 10.0), ("y", 20.0)])],
            globals: HashMap::new(),
            events: vec![],
            resources: StartupResources { mb_any: 712.0, mus_new4: 923.0 },
            coordinate_read: 0,
            mutate_coordinates: false,
            choices: 0,
            nested_intro: false,
            files: HashMap::new(),
            ini_store: HashMap::new(),
        }
    }
    fn run(&mut self, name: &str) -> Result<DirectCreateStatus, UnsupportedObject> {
        let r = self.resources;
        dispatch_create(name, self, &r)
    }
}

impl EventRuntime for Host {
    type Instance = usize;
    fn read_self(&mut self, f: &'static str) -> f64 {
        self.events.push(E::Read(self.current, f));
        if self.mutate_coordinates && (f == "x" || f == "y") {
            self.coordinate_read += 1;
            return self.coordinate_read as f64;
        }
        *self.fields[self.current].get(f).unwrap_or_else(|| panic!("missing live field: {}", f))
    }
    fn write_self(&mut self, f: &'static str, v: f64) {
        self.events.push(E::Write(self.current, f, v));
        self.fields[self.current].insert(f, v);
    }
    fn write_global(&mut self, f: &'static str, v: f64) {
        self.events.push(E::Global(f, v));
        self.globals.insert(f, v);
    }
    fn read_global(&mut self, f: &'static str) -> f64 {
        *self.globals.get(f).unwrap_or_else(|| panic!("missing global: {}", f))
    }
    fn write_alarm(&mut self, i: usize, v: f64) {
        self.events.push(E::Alarm(self.current, i, v));
    }
    fn choose(&mut self, v: &[f64]) -> f64 {
        self.events.push(E::Choose(v.to_vec()));
        self.choices += 1;
        if self.choices == 1 { 20.0 } else { 13.0 }
    }
    fn audio_play_sound(&mut self, s: f64, p: f64, l: bool) {
        self.events.push(E::Audio(s, p, l));
    }
    fn read_player(&mut self, _: &'static str) -> f64 { panic!("unexpected") }
    fn read_room(&mut self) -> f64 { panic!("unexpected") }
    fn spawn(&mut self, _: f64, _: f64, _: Object) -> usize { panic!("unexpected") }
    fn write_slot(&mut self, _: &'static str, _: usize) { panic!("unexpected") }
    fn read_slot(&mut self, _: &'static str) -> usize { panic!("unexpected") }
    fn write_instance(&mut self, _: usize, _: &'static str, _: f64) { panic!("unexpected") }
    fn audio_is_playing(&mut self, _: f64) -> bool { panic!("unexpected") }
    fn random(&mut self, _: f64) -> f64 { panic!("unexpected") }
    fn motion_set(&mut self, _: f64, _: f64) { panic!("unexpected") }
    fn instance_exists(&mut self, _: Object) -> bool { panic!("unexpected") }
    fn device_mouse_dbclick_enable(&mut self, _: bool) { panic!("unexpected") }
}

impl StartupRuntime for Host {
    fn randomize(&mut self) { self.events.push(E::Randomize); }
    fn irandom_range(&mut self, l: f64, h: f64) -> f64 { self.events.push(E::Range(l, h)); 7.0 }
    fn instance_deactivate_all(&mut self, n: bool) { self.events.push(E::Deactivate(self.current, n)); }
    fn instance_activate_object(&mut self, o: &'static str) { self.events.push(E::Activate(o)); }
    fn application_surface_enable(&mut self, e: bool) { self.events.push(E::Surface(e)); }
    fn mouse_clear(&mut self, b: f64) { self.events.push(E::Mouse(b)); }
    fn spawn_named(&mut self, x: f64, y: f64, o: &'static str) -> usize {
        let parent = self.current;
        let id = self.fields.len();
        self.fields.push(HashMap::from([("x", x), ("y", y)]));
        self.events.push(E::Spawn(parent, id, x, y, o));
        self.current = id;
        self.run(o).unwrap();
        // Explicit host hook forces deeper nested startup, not an invented GML event.
        if self.nested_intro && o == "obj_viewresolution" {
            self.spawn_named(0.0, 0.0, "obj_introduction");
        }
        self.current = parent;
        self.events.push(E::Return(parent, id));
        id
    }
    fn adcolony_init(&mut self, app: &'static str, zone: &'static str, extra: &'static str) {
        self.events.push(E::AdColony(app, zone, extra));
    }
    fn file_exists(&mut self, path: &'static str) -> bool {
        self.events.push(E::FileExists(path));
        *self.files.get(path).unwrap_or(&false)
    }
    fn ini_open(&mut self, path: &'static str) {
        self.events.push(E::IniOpen(path));
    }
    fn ini_close(&mut self) {
        self.events.push(E::IniClose);
    }
    fn ini_read_real(&mut self, section: &'static str, key: &'static str, default: f64) -> f64 {
        self.events.push(E::IniRead(section, key, default));
        *self.ini_store.get(&(section, key)).unwrap_or(&default)
    }
    fn ini_write_real(&mut self, section: &'static str, key: &'static str, value: f64) {
        self.events.push(E::IniWrite(section, key, value));
        self.ini_store.insert((section, key), value);
    }
}

#[test]
fn no_create_and_unknown_are_distinct_and_make_zero_calls() {
    let mut h = Host::new();
    for n in ["obj_shootbutton", "obj_jumpbutton", "obj_swordbutton", "obj_pausebutton", "obj_phone"] {
        assert_eq!(h.run(n), Ok(DirectCreateStatus::NoDirectEvent));
    }
    for n in ["obj_ui", "obj_player", "", "unknown"] {
        assert_eq!(h.run(n), Err(UnsupportedObject(n.to_owned())));
    }
    assert!(h.events.is_empty());
    assert_eq!(h.fields.len(), 1);
}

#[test]
fn simple_direct_creates_exact_and_resources_not_hardcoded() {
    for (mb, mus) in [(712.0, 923.0), (-4.0, 1532.0)] {
        for name in ["obj_leftbutton", "obj_rightbutton", "obj_viewresolution"] {
            let mut h = Host::new();
            h.resources = StartupResources { mb_any: mb, mus_new4: mus };
            assert_eq!(h.run(name), Ok(DirectCreateStatus::Executed));
            assert_eq!(
                h.events,
                if name == "obj_viewresolution" {
                    vec![E::Surface(false), E::Alarm(0, 0, 1.0)]
                } else {
                    vec![E::Mouse(mb)]
                }
            );
        }
    }
}

fn intro_prefix(id: usize) -> Vec<E> {
    [
        ("taplock", 0.0), ("moving", 1.0), ("moving2", 0.0),
        ("xx1", 110.0), ("x1", 200.0), ("xx2", 100.0), ("x2", 175.0),
        ("xx3", 120.0), ("x3", 240.0), ("xx4", 120.0), ("x4", 240.0),
    ].into_iter().map(|(f, v)| E::Write(id, f, v)).collect()
}

fn intro_suffix(id: usize, mus: f64) -> Vec<E> {
    vec![
        E::Write(id, "image_speed", 0.3),
        E::Audio(mus, 0.0, false),
        E::Alarm(id, 0, 120.0),
        E::Alarm(id, 1, 30.0),
        E::Alarm(id, 2, 70.0),
        E::Alarm(id, 3, 70.0),
    ]
}

#[test]
fn introduction_full_order_phone_is_synchronous_and_restores_self() {
    for mus in [923.0, 1782.0] {
        let mut h = Host::new();
        h.resources.mus_new4 = mus;
        assert_eq!(h.run("obj_introduction"), Ok(DirectCreateStatus::Executed));
        let mut expected = intro_prefix(0);
        expected.extend([
            E::Deactivate(0, true),
            E::Activate("obj_introduction"),
            E::Activate("obj_viewresolution"),
            E::Spawn(0, 1, 0.0, 0.0, "obj_phone"),
            E::Return(0, 1),
        ]);
        expected.extend(intro_suffix(0, mus));
        assert_eq!(h.events, expected);
        assert_eq!(h.current, 0);
        assert_eq!(h.fields[0]["image_speed"], 0.3);
        assert!(!h.fields[1].contains_key("image_speed"));
    }
}

#[test]
fn ui_complete_trace_live_y_then_x_all_seven_and_nested_self_restore() {
    use E::*;
    for nested in [false, true] {
        let mut h = Host::new();
        h.mutate_coordinates = true;
        h.nested_intro = nested;
        assert_eq!(h.run("obj_UI"), Ok(DirectCreateStatus::Executed));
        let mut expected = vec![
            Choose(vec![19.0, 20.0]),
            Global("coinsound", 20.0),
            Choose(vec![13.0, 14.0]),
            Global("swordsound", 13.0),
            Randomize,
            Range(1.0, 10.0),
            Global("playlist", 7.0),
        ];
        for (i, name) in [
            "obj_viewresolution", "obj_shootbutton", "obj_jumpbutton",
            "obj_swordbutton", "obj_leftbutton", "obj_rightbutton", "obj_pausebutton",
        ].into_iter().enumerate() {
            let id = i + 1 + if nested && i > 0 { 2 } else { 0 };
            if i == 6 { expected.push(Global("firing", 0.0)); }
            expected.extend([
                Read(0, "y"), Read(0, "x"),
                Spawn(0, id, (2 * i + 2) as f64, (2 * i + 1) as f64, name),
            ]);
            if i == 0 {
                expected.extend([Surface(false), Alarm(id, 0, 1.0)]);
                if nested {
                    expected.push(Spawn(1, 2, 0.0, 0.0, "obj_introduction"));
                    expected.extend(intro_prefix(2));
                    expected.extend([
                        Deactivate(2, true),
                        Activate("obj_introduction"),
                        Activate("obj_viewresolution"),
                        Spawn(2, 3, 0.0, 0.0, "obj_phone"),
                        Return(2, 3),
                    ]);
                    expected.extend(intro_suffix(2, 923.0));
                    expected.push(Return(1, 2));
                }
            }
            if i == 4 || i == 5 { expected.push(Mouse(712.0)); }
            expected.push(Return(0, id));
        }
        expected.extend([
            Alarm(0, 7, 3.0), Alarm(0, 0, 5.0),
            Global("timespaused", 0.0),
            Write(0, "drawboss1", 0.0), Write(0, "drawboss2", 0.0),
            Write(0, "drawboss3", 0.0), Write(0, "drawboss4", 0.0),
            Alarm(0, 1, 1.0),
        ]);
        assert_eq!(h.events, expected, "nested={nested}");
        assert_eq!(h.current, 0);
        assert_eq!(h.coordinate_read, 14);
        assert_eq!(h.fields[0]["drawboss4"], 0.0);
        for f in &h.fields[1..] { assert!(!f.contains_key("drawboss4")); }
    }
}

#[test]
fn player_other2_fresh_start_no_savefiles_populates_full_defaults_and_writes_savefile() {
    let mut h = Host::new();
    // No savefiles exist
    player_other2(&mut h);

    // Verify AdColony called with exact credentials
    assert!(h.events.contains(&E::AdColony("app73023f81ce5d4f508a", "vz1aca9f7894b44cec93", "")));
    // Verify initial globals
    assert_eq!(*h.globals.get("warpfrommap").unwrap(), 0.0);
    assert_eq!(*h.globals.get("ending").unwrap(), 0.0);
    // Verify fresh start defaults
    assert_eq!(*h.globals.get("maxhp").unwrap(), 4.0);
    assert_eq!(*h.globals.get("health1").unwrap(), 4.0);
    assert_eq!(*h.globals.get("level").unwrap(), 1.0);
    assert_eq!(*h.fields[0].get("score").unwrap(), 100.0);
    assert_eq!(*h.globals.get("xptolevelup").unwrap(), 30.0);
    // Weapons initially 0
    assert_eq!(*h.globals.get("pistolbought").unwrap(), 1.0);
    // savefile2.ini false branch defaults
    assert_eq!(*h.globals.get("levelchallenge1visited").unwrap(), 0.0);
    assert_eq!(*h.globals.get("talkedtolloyd16").unwrap(), 0.0);
    // savefile3.ini false branch defaults
    assert_eq!(*h.globals.get("twentyfivebears").unwrap(), 0.0);
    assert_eq!(*h.globals.get("hitmoney").unwrap(), 0.0);

    // Verify it wrote savefile.ini
    assert!(h.events.contains(&E::IniOpen("savefile.ini")));
    assert!(h.events.contains(&E::IniClose));
    // Verify intro spawned at self coords
    assert_eq!(*h.fields[0].get("x").unwrap(), 10.0);
    assert_eq!(*h.fields[0].get("y").unwrap(), 20.0);
    // Check spawn event for obj_introduction
    assert!(h.events.iter().any(|e| matches!(e, E::Spawn(0, _, 10.0, 20.0, "obj_introduction"))));
}

#[test]
fn player_other2_savefile_exists_restores_weapon_levels_and_damages() {
    let mut h = Host::new();
    h.files.insert("savefile.ini", true);
    h.files.insert("savefile2.ini", true);
    h.files.insert("savefile3.ini", true);
    // Populate INI store with custom progress
    h.ini_store.insert(("Save", "current_maxhp"), 12.0);
    h.ini_store.insert(("Save", "pistollevel"), 5.0);
    h.ini_store.insert(("Save", "shotgunlevel"), 12.0); // clamped to 10
    h.ini_store.insert(("Save", "assaultriflelevel"), 7.0);

    player_other2(&mut h);

    // Verify restored values
    assert_eq!(*h.globals.get("maxhp").unwrap(), 12.0);
    assert_eq!(*h.globals.get("pistollevel").unwrap(), 5.0);
    assert_eq!(*h.globals.get("pistoldamage").unwrap(), 2.4);
    // Shotgun level was 12 -> damage for 10 not directly triggered if only checked ==1..10, then clamped to 10
    assert_eq!(*h.globals.get("shotgunlevel").unwrap(), 10.0);
    assert_eq!(*h.globals.get("assaultriflelevel").unwrap(), 7.0);
    assert_eq!(*h.globals.get("assaultrifledamage").unwrap(), 1.4);
}
