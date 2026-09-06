//! Unified immediate host boundary, not a GM VM, scheduler or physics engine.
//! Hosts supply initialized fields, resource bindings, selector/lifetime policy,
//! builtin coupling and RNG. No event-entry snapshot or implicit zero defaults.
use crate::{original_player_combat as combat, original_projectile_create as projectile,
    original_player_create as player};
pub use combat::Object;
pub use crate::original_player::AlarmError;

/// Explicit external resource IDs; no assumed original resource numbering.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct EventResources {
    pub rm_ending: f64,
    pub spr_player: f64,
    pub spr_playerslash: f64,
    pub snd_fire: f64,
    pub snd_laser: f64,
    pub snd_ice: f64,
    pub snd_shotgun: f64,
    pub snd_assaultrifle: f64,
    pub snd_bombgun: f64,
    pub snd_bow: f64,
    pub snd_blade: f64,
    pub snd_flamethrower: f64,
    pub snd_sword: f64,
    pub snd_crescentwave: f64,
}

/// All operations resolve live host state. `read_player` is an object selector,
/// not an alias for self. Missing/undefined numeric values must be rejected.
/// `spawn` registers an identity and executes its Create synchronously, restoring
/// caller self before returning. This layer does not choose exists visibility or
/// suppress nested Create. Slots retain identities, not lossy numeric casts.
pub trait EventRuntime {
    type Instance: Copy;
    fn read_self(&mut self, field: &'static str) -> f64;
    fn write_self(&mut self, field: &'static str, value: f64);
    fn read_player(&mut self, field: &'static str) -> f64;
    fn read_global(&mut self, field: &'static str) -> f64;
    fn write_global(&mut self, field: &'static str, value: f64);
    fn read_room(&mut self) -> f64;
    fn write_alarm(&mut self, index: usize, value: f64);
    fn spawn(&mut self, x: f64, y: f64, object: Object) -> Self::Instance;
    fn write_slot(&mut self, slot: &'static str, instance: Self::Instance);
    fn read_slot(&mut self, slot: &'static str) -> Self::Instance;
    fn write_instance(&mut self, instance: Self::Instance, field: &'static str, value: f64);
    fn audio_is_playing(&mut self, sound: f64) -> bool;
    fn audio_play_sound(&mut self, sound: f64, priority: f64, looping: bool);
    fn random(&mut self, upper: f64) -> f64;
    fn choose(&mut self, values: &[f64]) -> f64;
    fn motion_set(&mut self, direction: f64, speed: f64);
    fn instance_exists(&mut self, object: Object) -> bool;
    fn device_mouse_dbclick_enable(&mut self, enabled: bool);
}

/// Original resource names, exhaustively bound (including direct-only Creates).
pub fn object_name(object: Object) -> &'static str {
    match object {
        Object::Bullet => "obj_bullet", Object::LaserBeam => "obj_laserbeam",
        Object::Iceball => "obj_iceball", Object::Rocket => "obj_rocket",
        Object::Bomb => "obj_bomb", Object::Arrow => "obj_arrow",
        Object::Blade => "obj_blade", Object::Flame => "obj_flame",
        Object::BoomerangThrow => "obj_boomerangthrow",
        Object::SpikegunSpike => "obj_spikegunspike", Object::Sword => "obj_sword",
        Object::EnergyWave => "obj_energywave",
    }
}
fn field(f: combat::Field) -> &'static str {
    use combat::Field::*;
    match f { X=>"x", Y=>"y", Facing=>"facing", SpriteIndex=>"sprite_index",
        ImageIndex=>"image_index", AssaultFire=>"assaultfire", ThrowingBoomerang=>"throwingboomerang" }
}
fn global(f: combat::Global) -> &'static str {
    use combat::Global::*;
    match f { Pistol=>"pistol", Laser=>"laser", Icegun=>"icegun", Shotgun=>"shotgun",
        AssaultRifle=>"assaultrifle", AssaultRifleLevel=>"assaultriflelevel", Rocket=>"rocket",
        Bombgun=>"bombgun", Bow=>"bow", Bladegun=>"bladegun", Flamethrower=>"flamethrower",
        Boomerang=>"boomerang", Spikegun=>"spikegun", SoundMute=>"soundmute", Firing=>"firing",
        Swing=>"swing", EnergyWaveBought=>"energywavebought" }
}
fn slot(s: combat::Slot) -> &'static str {
    use combat::Slot::*;
    match s { I1=>"i1", Bullet1=>"bullet1", Bullet2=>"bullet2", Bullet3=>"bullet3", Bullet4=>"bullet4", Bullet5=>"bullet5" }
}
fn projectile_field(f: projectile::Field) -> &'static str {
    use projectile::Field::*;
    match f { X=>"x", Y=>"y", Facing=>"facing", Hspeed=>"hspeed", Vspeed=>"vspeed",
        Canhit=>"canhit", Hitwall=>"hitwall", Hitblock=>"hitblock", Hitboulder=>"hitboulder",
        ImageSpeed=>"image_speed", ImageIndex=>"image_index", ImageAngle=>"image_angle",
        ImageXscale=>"image_xscale", Direction=>"direction", BoomerangReturn=>"boomerangreturn", Type=>"type" }
}
fn projectile_global(f: projectile::Global) -> &'static str {
    use projectile::Global::*;
    match f { Shotgun=>"shotgun", AssaultRifle=>"assaultrifle", BoomerangLevel=>"boomeranglevel", SoundMute=>"soundmute", SwordSound=>"swordsound" }
}
struct Adapter<'a, R> { host: &'a mut R, resources: &'a EventResources }
impl<R: EventRuntime> Adapter<'_, R> {
    fn sound(&self, sound: combat::Sound) -> f64 {
        use combat::Sound::*;
        let r = self.resources;
        match sound { Fire=>r.snd_fire, Laser=>r.snd_laser, Ice=>r.snd_ice,
            Shotgun=>r.snd_shotgun, AssaultRifle=>r.snd_assaultrifle, Bombgun=>r.snd_bombgun,
            Bow=>r.snd_bow, Blade=>r.snd_blade, Flamethrower=>r.snd_flamethrower, Sword=>r.snd_sword }
    }
}
impl<R: EventRuntime> player::PlayerCreateRuntime for Adapter<'_, R> {
    fn write_self(&mut self, f: &'static str, v: f64) { self.host.write_self(f,v) }
    fn write_global(&mut self, f: &'static str, v: f64) { self.host.write_global(f,v) }
    fn read_room(&mut self) -> f64 { self.host.read_room() }
    fn write_alarm(&mut self, i: usize, v: f64) { self.host.write_alarm(i,v) }
    fn device_mouse_dbclick_enable(&mut self, v: bool) { self.host.device_mouse_dbclick_enable(v) }
}
impl<R: EventRuntime> combat::CombatRuntime for Adapter<'_, R> {
    type Instance = R::Instance;
    fn read_self(&mut self, f: combat::Field) -> f64 { self.host.read_self(field(f)) }
    fn write_self(&mut self, f: combat::Field, v: f64) { self.host.write_self(field(f),v) }
    fn read_player(&mut self, f: combat::Field) -> f64 { self.host.read_player(field(f)) }
    fn read_global(&mut self, f: combat::Global) -> f64 { self.host.read_global(global(f)) }
    fn write_global(&mut self, f: combat::Global, v: f64) { self.host.write_global(global(f),v) }
    fn write_alarm(&mut self, i: usize, v: f64) { self.host.write_alarm(i,v) }
    fn instance_create(&mut self,x:f64,y:f64,o:Object)->R::Instance { self.host.spawn(x,y,o) }
    fn write_slot(&mut self,s:combat::Slot,id:R::Instance) { self.host.write_slot(slot(s),id) }
    fn read_slot(&mut self,s:combat::Slot)->R::Instance { self.host.read_slot(slot(s)) }
    fn write_image_xscale(&mut self,id:R::Instance,v:f64) { self.host.write_instance(id,"image_xscale",v) }
    fn audio_is_playing(&mut self,s:combat::Sound)->bool { let s=self.sound(s); self.host.audio_is_playing(s) }
    fn audio_play_sound(&mut self,s:combat::Sound,p:f64,l:bool) { let s=self.sound(s); self.host.audio_play_sound(s,p,l) }
}
impl<R: EventRuntime> projectile::CreateRuntime for Adapter<'_, R> {
    type Instance = R::Instance;
    fn read_self(&mut self,f:projectile::Field)->f64 { self.host.read_self(projectile_field(f)) }
    fn write_self(&mut self,f:projectile::Field,v:f64) { self.host.write_self(projectile_field(f),v) }
    fn read_player(&mut self,f:projectile::Field)->f64 { self.host.read_player(projectile_field(f)) }
    fn read_global(&mut self,f:projectile::Global)->f64 { self.host.read_global(projectile_global(f)) }
    fn write_alarm(&mut self,i:usize,v:f64) { self.host.write_alarm(i,v) }
    fn audio_play_sound(&mut self,s:projectile::Sound,p:f64,l:bool) {
        let s=match s { projectile::Sound::CrescentWave=>self.resources.snd_crescentwave, projectile::Sound::Resource(id)=>id };
        self.host.audio_play_sound(s,p,l)
    }
    fn random(&mut self,u:f64)->f64 { self.host.random(u) }
    fn choose(&mut self,v:&[f64])->f64 { self.host.choose(v) }
    fn motion_set(&mut self,d:f64,s:f64) { self.host.motion_set(d,s) }
    fn instance_exists(&mut self,o:Object)->bool { self.host.instance_exists(o) }
    fn instance_create(&mut self,x:f64,y:f64,o:Object)->R::Instance { self.host.spawn(x,y,o) }
    fn write_instance(&mut self,id:R::Instance,f:projectile::Field,v:f64) { self.host.write_instance(id,projectile_field(f),v) }
}

pub fn dispatch_player_create<R: EventRuntime>(host: &mut R, resources: &EventResources) {
    player::create(&mut Adapter { host, resources }, resources.rm_ending);
}
pub fn dispatch_projectile_create<R: EventRuntime>(host: &mut R, object: Object, resources: &EventResources) {
    projectile::create(&mut Adapter { host, resources }, object);
}
/// Direct event dispatch only: no ticking/clearing alarms. Errors perform no host calls.
pub fn dispatch_player_alarm<R: EventRuntime>(alarm:u8, host:&mut R, resources:&EventResources)->Result<(),AlarmError> {
    match alarm {
        0=>combat::alarm0(&mut Adapter {host,resources}),
        1=>combat::alarm1(&mut Adapter {host,resources},resources.spr_playerslash),
        2=>{host.write_global("swing",1.0);host.write_self("sprite_index",resources.spr_player);}
        3=>{host.write_global("firing",0.0);host.write_self("throwingboomerang",0.0);}
        4=>{host.write_self("sliding1",0.0);host.write_self("sliding2",0.0);host.write_self("hsp",0.0);}
        5=>host.write_self("playerdied",0.0),
        6=>host.write_global("roomstart",0.0),
        7=>host.write_self("sprite_index",resources.spr_player),
        8=>{host.write_self("invulnerable",0.0);host.write_self("invulnerable2",0.0);}
        9=>return Err(AlarmError::NoDirectEvent(alarm)),
        10=>{let v=host.read_global("timeplayed")+1.0;host.write_global("timeplayed",v);host.write_alarm(10,30.0);}
        11=>{
            if host.read_global("health1") != host.read_global("maxhp") && host.read_global("healthregenbought")==1.0 {
                let v=host.read_global("health1")+1.0;host.write_global("health1",v);
            }
            host.write_alarm(11,300.0);
        }
        _=>return Err(AlarmError::OutOfRange(alarm)),
    }
    Ok(())
}
