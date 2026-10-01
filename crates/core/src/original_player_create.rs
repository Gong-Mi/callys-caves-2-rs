//! Original obj_player Create (CODE0) runtime boundary.

pub trait PlayerCreateRuntime {
    fn write_self(&mut self, field: &'static str, value: f64);
    fn write_global(&mut self, field: &'static str, value: f64);
    fn read_room(&mut self) -> f64;
    fn write_alarm(&mut self, index: usize, value: f64);
    fn device_mouse_dbclick_enable(&mut self, enabled: bool);
}

/// Replay CODE0 exactly; no inferred engine defaults or final-state coalescing.
/// Global field names omit only the `global.` scope prefix represented by the method.
pub fn create<R: PlayerCreateRuntime>(rt: &mut R, rm_ending: f64) {
    rt.write_self("flashing", 0.0);
    rt.write_self("assaultfire", 4.0);
    rt.write_self("sliding1", 0.0);
    rt.write_self("sliding2", 0.0);
    rt.write_self("invulnerable2", 0.0);
    rt.write_global("gemsfromhouse", 0.0);
    rt.write_global("warpedfromlloyd", 0.0);
    rt.write_global("roomcamefrom", 0.0);
    rt.write_global("roomstart", 0.0);
    if rt.read_room() == rm_ending {
        rt.write_self("hspeed", 1.0);
    }
    rt.write_global("rebuff", 0.0);
    rt.write_self("throwingboomerang", 0.0);
    rt.write_global("keydrop", 2.0);
    rt.write_alarm(10, 30.0);
    rt.write_global("warplock", 0.0);
    rt.device_mouse_dbclick_enable(false);
    rt.write_alarm(11, 300.0);
    rt.write_global("playerdied", 0.0);
    rt.write_global("storemenu", 0.0);
    rt.write_global("musicmute", 0.0);
    rt.write_global("soundmute", 0.0);
    rt.write_global("health1", 4.0);
    rt.write_self("playerdied", 0.0);
    rt.write_self("invulnerable", 0.0);
    rt.write_global("coinpickup", 0.0);
    rt.write_global("swing", 1.0);
    rt.write_self("hspeed", 0.0);
    rt.write_self("vspeed", 0.0);
    rt.write_self("hsp", 0.0);
    rt.write_self("vsp", 0.0);
    rt.write_self("grav", 1.0);
    rt.write_self("grounded", 1.0);
    rt.write_self("friction", 0.08);
    rt.write_self("djump", 0.0);
    rt.write_self("tjump", 0.0);
    rt.write_global("pistol", 1.0);
    rt.write_global("shotgun", 0.0);
    rt.write_global("powerupgrade", 0.0);
    rt.write_global("assaultrifle", 0.0);
    rt.write_global("shotgun", 0.0);
    rt.write_global("rocket", 0.0);
    rt.write_global("laser", 0.0);
    rt.write_global("icegun", 0.0);
    rt.write_global("bladegun", 0.0);
    rt.write_global("flamethrower", 0.0);
    rt.write_global("bow", 0.0);
    rt.write_global("boomerang", 0.0);
    rt.write_global("spikegun", 0.0);
    rt.write_global("bombgun", 0.0);
    rt.write_self("facing", 0.0);
    rt.write_self("hpupgrade2", 0.0);
    rt.write_self("hpupgrade3", 0.0);
    rt.write_self("hpupgrade4", 0.0);
    rt.write_self("hpupgrade5", 0.0);
    rt.write_self("hpupgrade6", 0.0);
    rt.write_self("hpupgrade7", 0.0);
    rt.write_self("hpupgrade8", 0.0);
    rt.write_self("hpupgrade9", 0.0);
    rt.write_self("hpupgrade10", 0.0);
    rt.write_self("hpupgrade11", 0.0);
    rt.write_self("hpupgrade12", 0.0);
    rt.write_self("hpupgrade13", 0.0);
    rt.write_self("hpupgrade14", 0.0);
    rt.write_self("hpupgrade15", 0.0);
    rt.write_self("hpupgrade16", 0.0);
    rt.write_self("hpupgrade17", 0.0);
    rt.write_self("hpupgrade18", 0.0);
    rt.write_self("hpupgrade19", 0.0);
    rt.write_self("hpupgrade20", 0.0);
}
