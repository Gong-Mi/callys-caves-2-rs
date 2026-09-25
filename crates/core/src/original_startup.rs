//! Direct startup event boundary, not a scheduler or production GameMaker engine.
use crate::original_events::EventRuntime;

/// Host methods are immediate and live, including nested Create dispatch.
/// `spawn_named` must register the child, run its Create synchronously, and
/// restore caller self before returning. Activation/visibility policy belongs
/// to the host; this module does not simulate the real engine's active set.
pub trait StartupRuntime: EventRuntime {
    fn adcolony_init(&mut self, app: &'static str, zone: &'static str, extra: &'static str);
    fn file_exists(&mut self, path: &'static str) -> bool;
    fn ini_open(&mut self, path: &'static str);
    fn ini_close(&mut self);
    fn ini_read_real(&mut self, section: &'static str, key: &'static str, default: f64) -> f64;
    fn ini_write_real(&mut self, section: &'static str, key: &'static str, value: f64);
    fn spawn_named(&mut self, x: f64, y: f64, object: &'static str) -> Self::Instance;
    fn randomize(&mut self);
    fn irandom_range(&mut self, low: f64, high: f64) -> f64;
    fn instance_deactivate_all(&mut self, notme: bool);
    fn instance_activate_object(&mut self, object: &'static str);
    fn application_surface_enable(&mut self, enabled: bool);
    fn mouse_clear(&mut self, button: f64);
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct StartupResources {
    pub mb_any: f64,
    pub mus_new4: f64,
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum DirectCreateStatus { Executed, NoDirectEvent }
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct UnsupportedObject(pub String);
impl std::fmt::Display for UnsupportedObject {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "unsupported startup object: {}", self.0)
    }
}
impl std::error::Error for UnsupportedObject {}

/// Dispatch only audited OBJT bindings, never silently accept unknown names.
/// OBJT 66/130/131/133/137 bind CODE 365/528/531/537/548 respectively.
/// OBJT 125/127/128/129/136 have no Create and parent_id=-100 (no parent).
/// This is direct-event coverage, not general inherited-event resolution.
pub fn dispatch_create<R: StartupRuntime>(name: &str, rt: &mut R, resources: &StartupResources) -> Result<DirectCreateStatus, UnsupportedObject> {
    match name {
        "obj_UI" => ui_create(rt),
        "obj_viewresolution" => {
            rt.application_surface_enable(false);
            rt.write_alarm(0, 1.0);
        }
        "obj_leftbutton" | "obj_rightbutton" => rt.mouse_clear(resources.mb_any),
        "obj_introduction" => introduction_create(rt, resources),
        "obj_shootbutton" | "obj_jumpbutton" | "obj_swordbutton" | "obj_pausebutton" | "obj_phone" => return Ok(DirectCreateStatus::NoDirectEvent),
        _ => return Err(UnsupportedObject(name.to_owned())),
    }
    Ok(DirectCreateStatus::Executed)
}

// Original VM argument evaluation reads Y before X, once per spawn. A child
// Create can change live parent coordinates; never cache at event entry.
fn spawn_at_self<R: StartupRuntime>(rt: &mut R, object: &'static str) {
    let y = rt.read_self("y");
    let x = rt.read_self("x");
    rt.spawn_named(x, y, object);
}

/// CODE365: preserve both pre-randomize choices (numeric source literals).
pub fn ui_create<R: StartupRuntime>(rt: &mut R) {
    let coinsound = rt.choose(&[19.0, 20.0]);
    rt.write_global("coinsound", coinsound);
    let swordsound = rt.choose(&[13.0, 14.0]);
    rt.write_global("swordsound", swordsound);
    rt.randomize();
    let i = rt.irandom_range(1.0, 10.0);
    rt.write_global("playlist", i);
    spawn_at_self(rt, "obj_viewresolution");
    spawn_at_self(rt, "obj_shootbutton");
    spawn_at_self(rt, "obj_jumpbutton");
    spawn_at_self(rt, "obj_swordbutton");
    spawn_at_self(rt, "obj_leftbutton");
    spawn_at_self(rt, "obj_rightbutton");
    rt.write_global("firing", 0.0);
    spawn_at_self(rt, "obj_pausebutton");
    rt.write_alarm(7, 3.0);
    rt.write_alarm(0, 5.0);
    rt.write_global("timespaused", 0.0);
    rt.write_self("drawboss1", 0.0);
    rt.write_self("drawboss2", 0.0);
    rt.write_self("drawboss3", 0.0);
    rt.write_self("drawboss4", 0.0);
    rt.write_alarm(1, 1.0);
}

/// CODE548. Activation and synchronous phone creation remain host operations.
pub fn introduction_create<R: StartupRuntime>(rt: &mut R, resources: &StartupResources) {
    rt.write_self("taplock", 0.0);
    rt.write_self("moving", 1.0);
    rt.write_self("moving2", 0.0);
    rt.write_self("xx1", 110.0);
    rt.write_self("x1", 200.0);
    rt.write_self("xx2", 100.0);
    rt.write_self("x2", 175.0);
    rt.write_self("xx3", 120.0);
    rt.write_self("x3", 240.0);
    rt.write_self("xx4", 120.0);
    rt.write_self("x4", 240.0);
    rt.instance_deactivate_all(true);
    rt.instance_activate_object("obj_introduction");
    rt.instance_activate_object("obj_viewresolution");
    rt.spawn_named(0.0, 0.0, "obj_phone");
    rt.write_self("image_speed", 0.3);
    rt.audio_play_sound(resources.mus_new4, 0.0, false);
    rt.write_alarm(0, 120.0);
    rt.write_alarm(1, 30.0);
    rt.write_alarm(2, 70.0);
    rt.write_alarm(3, 70.0);
}
