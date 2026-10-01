//! Synthetic synchronous host executing both real recovered method modules.
//! This is NOT a GM registry/physics implementation or original-runner oracle.
#![allow(dead_code)]
#[path = "../src/original_player_combat.rs"] mod original_player_combat;
#[path = "../src/original_projectile_create.rs"] mod original_projectile_create;
use original_player_combat as c;
use original_projectile_create as p;
use std::collections::HashMap;

#[derive(Debug)]
struct Spawn { object: c::Object, x: f64, y: f64, fields: HashMap<p::Field,f64>, alarms: HashMap<usize,f64> }
#[derive(Debug,PartialEq)]
enum Event { Begin(usize), End(usize), Slot(c::Slot,usize), Scale(usize), PlayerAlarm(usize), Motion(usize), CombatSound(c::Sound), CreateSound(usize), Random(usize), Choose(usize) }
struct Host {
    local: HashMap<c::Field,f64>, player: HashMap<c::Field,f64>, globals: HashMap<c::Global,f64>,
    slots: HashMap<c::Slot,usize>, alarms: HashMap<usize,f64>, spawned: Vec<Spawn>, current: Option<usize>, events: Vec<Event>, coordinate_reads: Vec<c::Field>,
}
impl Host {
    fn new(facing:f64)->Self {
        Self { local: HashMap::from([(c::Field::X,100.0),(c::Field::Y,200.0),(c::Field::Facing,facing),(c::Field::AssaultFire,3.0)]),
            player: HashMap::from([(c::Field::X,1000.0),(c::Field::Y,2000.0),(c::Field::Facing,facing)]),
            globals:HashMap::new(),slots:HashMap::new(),alarms:HashMap::new(),spawned:vec![],current:None,events:vec![],coordinate_reads:vec![] }
    }
    fn spawn(&mut self,x:f64,y:f64,object:c::Object)->usize {
        let id=self.spawned.len();
        // Explicit fixture builtin values, not recovered GameMaker defaults.
        self.spawned.push(Spawn {object,x,y,fields:HashMap::from([(p::Field::ImageAngle,0.0)]),alarms:HashMap::new()});
        let previous=self.current.replace(id);
        self.events.push(Event::Begin(id));
        p::create(self,object);
        self.events.push(Event::End(id));
        self.current=previous;
        id
    }
    fn value(&self,id:usize,field:p::Field)->f64 {self.spawned[id].fields[&field]}
}
impl c::CombatRuntime for Host {
    type Instance=usize;
    fn read_self(&mut self,f:c::Field)->f64 {assert!(self.current.is_none()); if matches!(f,c::Field::X|c::Field::Y) {self.coordinate_reads.push(f);} *self.local.get(&f).unwrap_or(&0.0)}
    fn write_self(&mut self,f:c::Field,v:f64){assert!(self.current.is_none()); self.local.insert(f,v);}
    fn read_player(&mut self,f:c::Field)->f64 {if matches!(f,c::Field::X|c::Field::Y) {self.coordinate_reads.push(f);} self.player[&f]}
    fn read_global(&mut self,f:c::Global)->f64 {*self.globals.get(&f).unwrap_or(&0.0)}
    fn write_global(&mut self,f:c::Global,v:f64){self.globals.insert(f,v);}
    fn write_alarm(&mut self,i:usize,v:f64){assert!(self.current.is_none());self.alarms.insert(i,v);self.events.push(Event::PlayerAlarm(i));}
    fn instance_create(&mut self,x:f64,y:f64,o:c::Object)->usize{self.spawn(x,y,o)}
    fn write_slot(&mut self,s:c::Slot,id:usize){assert!(self.current.is_none());self.slots.insert(s,id);self.events.push(Event::Slot(s,id));}
    fn read_slot(&mut self,s:c::Slot)->usize{self.slots[&s]}
    fn write_image_xscale(&mut self,id:usize,v:f64){self.spawned[id].fields.insert(p::Field::ImageXscale,v);self.events.push(Event::Scale(id));}
    fn audio_is_playing(&mut self,_:c::Sound)->bool{false}
    fn audio_play_sound(&mut self,s:c::Sound,priority:f64,looping:bool){assert_eq!(priority,0.0);assert!(!looping);self.events.push(Event::CombatSound(s));}
}
impl p::CreateRuntime for Host {
    type Instance=usize;
    fn read_self(&mut self,f:p::Field)->f64 {self.spawned[self.current.unwrap()].fields[&f]}
    fn write_self(&mut self,f:p::Field,v:f64){self.spawned[self.current.unwrap()].fields.insert(f,v);}
    fn read_player(&mut self,f:p::Field)->f64 {
        self.player[&match f {p::Field::Facing=>c::Field::Facing,p::Field::X=>c::Field::X,p::Field::Y=>c::Field::Y,_=>panic!("unexpected selector field {f:?}")}]
    }
    fn read_global(&mut self,f:p::Global)->f64 {
        match f {
            p::Global::Shotgun=>*self.globals.get(&c::Global::Shotgun).unwrap_or(&0.0),
            p::Global::AssaultRifle=>*self.globals.get(&c::Global::AssaultRifle).unwrap_or(&0.0),
            p::Global::SoundMute=>*self.globals.get(&c::Global::SoundMute).unwrap_or(&0.0),
            p::Global::BoomerangLevel=>10.0,p::Global::SwordSound=>77.0,
        }
    }
    fn write_alarm(&mut self,i:usize,v:f64){self.spawned[self.current.unwrap()].alarms.insert(i,v);}
    fn audio_play_sound(&mut self,_:p::Sound,priority:f64,looping:bool){assert_eq!(priority,0.0);assert!(!looping);self.events.push(Event::CreateSound(self.current.unwrap()));}
    fn random(&mut self,upper:f64)->f64{self.events.push(Event::Random(self.current.unwrap()));upper/3.0}
    fn choose(&mut self,values:&[f64])->f64{assert_eq!(values,&[1.0,-1.0]);self.events.push(Event::Choose(self.current.unwrap()));1.0}
    fn motion_set(&mut self,direction:f64,_speed:f64){let id=self.current.unwrap();self.events.push(Event::Motion(id));self.spawned[id].fields.insert(p::Field::Direction,direction);}
    fn instance_exists(&mut self,o:c::Object)->bool{self.spawned.iter().any(|s|s.object==o)}
    fn instance_create(&mut self,x:f64,y:f64,o:c::Object)->usize{self.spawn(x,y,o)}
    fn write_instance(&mut self,id:usize,f:p::Field,v:f64){self.spawned[id].fields.insert(f,v);}
}

#[test]
fn combat_spawn_coordinates_follow_original_vm_y_then_x_order() {
    // CODE11: 0039731c self.y, 0039732c self.x, 0039733c instance_create.
    // CODE10: 003971a8 player.y, 003971b8 player.x, 003971c8 instance_create.
    let mut h=Host::new(1.0);h.globals.insert(c::Global::Pistol,1.0);c::alarm0(&mut h);
    assert_eq!(h.coordinate_reads,vec![c::Field::Y,c::Field::X]);
    h.coordinate_reads.clear();h.globals.insert(c::Global::Swing,1.0);h.globals.insert(c::Global::EnergyWaveBought,1.0);
    c::alarm1(&mut h,123.0);
    assert_eq!(h.coordinate_reads,vec![c::Field::Y,c::Field::X,c::Field::Y,c::Field::X]);
}
#[test]
fn shotgun_five_real_creates_finish_before_slot_and_next_spawn() {
    for facing in [0.0,1.0] {
        let mut h=Host::new(facing);h.globals.insert(c::Global::Shotgun,1.0);c::alarm0(&mut h);
        assert_eq!(h.spawned.len(),5);
        let mut expected=vec![];
        for (id,slot) in [c::Slot::Bullet1,c::Slot::Bullet2,c::Slot::Bullet3,c::Slot::Bullet4,c::Slot::Bullet5].into_iter().enumerate() {
            assert_eq!(h.value(id,p::Field::Canhit),0.0);
            assert_eq!(h.value(id,p::Field::Hspeed),if facing==0.0 {25.0}else{-25.0});
            assert_eq!(h.spawned[id].x,if facing==0.0 {108.0}else{92.0});
            assert_eq!(h.spawned[id].y,if id==0 {201.0}else{207.0});
            assert_eq!(h.slots[&slot],id);
            expected.extend([Event::Begin(id),Event::Random(id),Event::Choose(id),Event::Motion(id),Event::End(id),Event::Slot(slot,id)]);
        }
        expected.extend([Event::CombatSound(c::Sound::Shotgun),Event::PlayerAlarm(3)]);
        assert_eq!(h.events,expected);assert!(h.current.is_none());assert_eq!(h.alarms[&3],5.0);
    }
}
#[test]
fn laser_create_alarm_is_child_scoped_and_scale_is_post_create() {
    let mut h=Host::new(1.0);h.globals.insert(c::Global::Laser,1.0);c::alarm0(&mut h);
    assert_eq!(h.value(0,p::Field::Hspeed),-20.0);assert_eq!(h.value(0,p::Field::ImageXscale),2.0);
    assert_eq!(h.spawned[0].alarms,HashMap::from([(1,120.0)]));assert_eq!(h.alarms,HashMap::from([(3,5.0)]));
    assert_eq!(h.events,vec![Event::Begin(0),Event::End(0),Event::Slot(c::Slot::I1,0),Event::Scale(0),Event::PlayerAlarm(3),Event::CombatSound(c::Sound::Laser)]);
}
#[test]
fn slash_runs_sword_and_wave_create_and_restores_player_context() {
    for facing in [0.0,1.0] {
        let mut h=Host::new(facing);h.globals.insert(c::Global::Swing,1.0);h.globals.insert(c::Global::EnergyWaveBought,1.0);
        c::alarm1(&mut h,123.0);
        assert_eq!(h.spawned.len(),2);assert_eq!(h.spawned[0].object,c::Object::Sword);assert_eq!(h.spawned[1].object,c::Object::EnergyWave);
        assert_eq!(h.spawned[0].x,if facing==1.0 {1015.0}else{985.0});assert_eq!(h.spawned[0].y,1985.0);assert_eq!(h.spawned[1].y,1995.0);
        assert_eq!(h.spawned[0].alarms,HashMap::from([(0,7.0)]));assert_eq!(h.spawned[1].alarms,HashMap::from([(1,12.0)]));
        assert_eq!(h.alarms,HashMap::from([(2,9.0)]));assert_eq!(h.value(1,p::Field::Hspeed),if facing==1.0 {-20.0}else{20.0});
        assert_eq!(h.events,vec![Event::Begin(0),Event::CreateSound(0),Event::End(0),Event::PlayerAlarm(2),Event::Begin(1),Event::CreateSound(1),Event::End(1)]);
        assert_eq!(h.globals[&c::Global::Swing],0.0);assert!(h.current.is_none());
    }
}
#[test]
fn every_direct_spawn_object_executes_its_real_create_in_one_batch() {
    use c::Global::*;
    for facing in [0.0,1.0] {
        let mut h=Host::new(facing);
        for flag in [Pistol,Laser,Icegun,Shotgun,AssaultRifle,Rocket,Bombgun,Bow,Bladegun,Flamethrower,Boomerang,Spikegun,Swing,EnergyWaveBought] {h.globals.insert(flag,1.0);}
        c::alarm0(&mut h);c::alarm1(&mut h,123.0);
        let mut counts=HashMap::new();for s in &h.spawned {*counts.entry(s.object).or_insert(0)+=1;}
        assert_eq!(counts.len(),12);assert_eq!(counts[&c::Object::Bullet],7);
        for object in [c::Object::LaserBeam,c::Object::Iceball,c::Object::Rocket,c::Object::Bomb,c::Object::Arrow,c::Object::Blade,c::Object::Flame,c::Object::BoomerangThrow,c::Object::SpikegunSpike,c::Object::Sword,c::Object::EnergyWave] {assert_eq!(counts[&object],1);}
        for (id,s) in h.spawned.iter().enumerate() {assert!(!s.fields.is_empty());assert!(h.events.contains(&Event::End(id)));}
        assert!(h.current.is_none());
    }
}
