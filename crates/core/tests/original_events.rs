//! Preservation/integration fixture, NOT the original GM runtime. External
//! progression seeds and builtin defaults below are explicit test inputs. RNG,
//! motion coupling, sound and instance visibility are fixture policies only.
#[path = "../src/original_player.rs"] mod original_player;
#[path = "../src/original_player_combat.rs"] mod original_player_combat;
#[path = "../src/original_projectile_create.rs"] mod original_projectile_create;
#[path = "../src/original_player_create.rs"] mod original_player_create;
#[path = "../src/original_events.rs"] mod original_events;
use original_events::*;
use std::collections::HashMap;

const RES: EventResources = EventResources {
    rm_ending:901.0,spr_player:902.0,spr_playerslash:903.0,
    snd_fire:911.0,snd_laser:912.0,snd_ice:913.0,snd_shotgun:914.0,
    snd_assaultrifle:915.0,snd_bombgun:916.0,snd_bow:917.0,snd_blade:918.0,
    snd_flamethrower:919.0,snd_sword:920.0,snd_crescentwave:921.0,
};
#[derive(Clone,Copy,Debug,PartialEq,Eq,Hash)] enum Scope { Global, Instance(u64) }
#[derive(Clone,Copy,Debug,PartialEq)] enum Value { Number(f64), Identity(u64) }
#[derive(Clone,Debug,PartialEq)] struct Host {
    // One shared store for every self, selector, global, slot and builtin write.
    values:HashMap<(Scope,&'static str),Value>,
    alarms:HashMap<(u64,usize),f64>, registry:HashMap<u64,Object>, stack:Vec<u64>,
    next:u64, room:f64, sounds:Vec<f64>, queries:Vec<f64>, mouse:Vec<bool>,
    motions:Vec<(u64,f64,f64)>, randoms:Vec<f64>, choices:Vec<Vec<f64>>,
    exists_calls:usize, hide_first_sword:bool,
}
impl Host {
    fn empty()->Self { Self { values:HashMap::new(),alarms:HashMap::new(),registry:HashMap::new(),stack:vec![1], next:2,room:0.0,sounds:vec![],queries:vec![],mouse:vec![],motions:vec![],randoms:vec![],choices:vec![],exists_calls:0,hide_first_sword:false } }
    fn id(&self)->u64 {*self.stack.last().expect("event self")}
    fn get(&self,s:Scope,f:&'static str)->f64 {
        match self.values.get(&(s,f)).unwrap_or_else(||panic!("uninitialized {s:?}.{f}")) {
            Value::Number(v)=>*v, Value::Identity(_)=>panic!("identity is not numeric: {f}")
        }
    }
    fn n(&self,id:u64,f:&'static str)->f64 {self.get(Scope::Instance(id),f)}
    fn g(&self,f:&'static str)->f64 {self.get(Scope::Global,f)}
    fn fixture()->Self {
        let mut h=Self::empty();
        // Builtin state is supplied externally, not attributed to CODE0.
        for (f,v) in [("x",100.0),("y",200.0),("sprite_index",RES.spr_player),("image_index",4.0)] {h.write_self(f,v);}
        // Progression/session globals absent from Player Create.
        for (f,v) in [("energywavebought",1.0),("swordsound",777.0),("boomeranglevel",10.0),("assaultriflelevel",10.0),("maxhp",6.0),("healthregenbought",1.0),("timeplayed",40.0)] {h.write_global(f,v);}
        dispatch_player_create(&mut h,&RES); h
    }
    fn alarm(&mut self,i:u8) {dispatch_player_alarm(i,self,&RES).unwrap();}
    fn ids(&self,o:Object)->Vec<u64> {self.registry.iter().filter_map(|(id,x)|(*x==o).then_some(*id)).collect()}
}
impl EventRuntime for Host {
    type Instance=u64;
    fn read_self(&mut self,f:&'static str)->f64 {self.n(self.id(),f)}
    fn write_self(&mut self,f:&'static str,v:f64) {self.write_instance(self.id(),f,v)}
    fn read_player(&mut self,f:&'static str)->f64 {self.n(1,f)}
    fn read_global(&mut self,f:&'static str)->f64 {self.g(f)}
    fn write_global(&mut self,f:&'static str,v:f64) {self.values.insert((Scope::Global,f),Value::Number(v));}
    fn read_room(&mut self)->f64 {self.room}
    fn write_alarm(&mut self,i:usize,v:f64) {self.alarms.insert((self.id(),i),v);}
    fn spawn(&mut self,x:f64,y:f64,o:Object)->u64 {
        let caller=self.id(); let id=self.next;self.next+=1;
        assert!(self.registry.insert(id,o).is_none());
        self.stack.push(id);
        // Deliberate fixture builtin seeds. No arbitrary missing-field fallback.
        for (f,v) in [("x",x),("y",y),("image_angle",0.0),("image_xscale",1.0)] {self.write_self(f,v);}
        dispatch_projectile_create(self,o,&RES);
        assert_eq!(self.stack.pop(),Some(id));assert_eq!(self.id(),caller);id
    }
    fn write_slot(&mut self,f:&'static str,id:u64) {assert!(self.registry.contains_key(&id));self.values.insert((Scope::Instance(self.id()),f),Value::Identity(id));}
    fn read_slot(&mut self,f:&'static str)->u64 {match self.values.get(&(Scope::Instance(self.id()),f)).expect("missing identity slot") {Value::Identity(id)=>*id,_=>panic!("not an identity")}}
    fn write_instance(&mut self,id:u64,f:&'static str,v:f64) {assert!(id==1||self.registry.contains_key(&id));self.values.insert((Scope::Instance(id),f),Value::Number(v));}
    fn audio_is_playing(&mut self,s:f64)->bool {self.queries.push(s);self.sounds.contains(&s)}
    fn audio_play_sound(&mut self,s:f64,p:f64,l:bool) {assert_eq!(p,0.0);assert!(!l);self.sounds.push(s);}
    fn random(&mut self,u:f64)->f64 {self.randoms.push(u);u/2.0}
    fn choose(&mut self,v:&[f64])->f64 {self.choices.push(v.to_vec());assert_eq!(v,&[1.0,-1.0]);v[0]}
    fn motion_set(&mut self,d:f64,s:f64) {
        // Intentionally minimal fixture coupling, NOT GM movement/physics.
        self.motions.push((self.id(),d,s));self.write_self("direction",d);
    }
    fn instance_exists(&mut self,o:Object)->bool {self.exists_calls+=1;if self.hide_first_sword&&self.exists_calls==1 {return false;}self.registry.values().any(|x|*x==o)}
    fn device_mouse_dbclick_enable(&mut self,b:bool) {self.mouse.push(b);}
}

#[test] fn create_fire_melee_release_heal_and_time_share_live_store() {
    let mut h=Host::fixture();assert_eq!(h.mouse,vec![false]);assert_eq!(h.n(1,"facing"),0.0);
    h.alarm(0);let bullet=h.ids(Object::Bullet)[0];
    assert_eq!((h.n(bullet,"x"),h.n(bullet,"y"),h.n(bullet,"hspeed")),(110.0,206.0,25.0));
    assert_eq!(h.g("firing"),1.0);assert_eq!(h.alarms[&(1,3)],5.0);assert_eq!(h.stack,vec![1]);
    h.alarm(1);assert_eq!(h.g("swing"),0.0);assert_eq!(h.n(1,"sprite_index"),RES.spr_playerslash);
    let sword=h.ids(Object::Sword)[0];let wave=h.ids(Object::EnergyWave)[0];
    assert_eq!(h.n(sword,"x"),85.0);assert_eq!(h.n(wave,"y"),195.0);
    assert_eq!(h.alarms[&(sword,0)],7.0);assert_eq!(h.alarms[&(wave,1)],12.0);
    assert_eq!(h.sounds,vec![RES.snd_fire,777.0,RES.snd_crescentwave]);
    h.alarm(3);h.alarm(2);assert_eq!(h.g("firing"),0.0);assert_eq!(h.g("swing"),1.0);
    assert_eq!(h.n(1,"sprite_index"),RES.spr_player);
    h.alarm(11);h.alarm(10);assert_eq!(h.g("health1"),5.0);assert_eq!(h.g("timeplayed"),41.0);
    assert_eq!(h.alarms[&(1,11)],300.0);assert_eq!(h.alarms[&(1,10)],30.0);
}
#[test] fn simple_events_only_touch_required_fields_and_scopes() {
    for alarm in [2,3,4,5,6,7,8,10,11] {
        let mut h=Host::empty();
        if alarm==10 {h.write_global("timeplayed",5.0);}
        if alarm==11 {h.write_global("health1",9.0);h.write_global("maxhp",4.0);h.write_global("healthregenbought",1.0);}
        h.alarm(alarm);
        match alarm {
            2=>{assert_eq!(h.g("swing"),1.0);assert_eq!(h.n(1,"sprite_index"),RES.spr_player);}
            3=>{assert_eq!(h.g("firing"),0.0);assert_eq!(h.n(1,"throwingboomerang"),0.0);}
            4=>for f in ["sliding1","sliding2","hsp"] {assert_eq!(h.n(1,f),0.0);},
            5=>assert_eq!(h.n(1,"playerdied"),0.0),6=>assert_eq!(h.g("roomstart"),0.0),
            7=>assert_eq!(h.n(1,"sprite_index"),RES.spr_player),
            8=>for f in ["invulnerable","invulnerable2"] {assert_eq!(h.n(1,f),0.0);},
            10=>assert_eq!(h.g("timeplayed"),6.0),11=>assert_eq!(h.g("health1"),10.0),_=>unreachable!(),
        }
    }
    let mut h=Host::fixture();
    h.write_global("playerdied",8.0);h.write_self("playerdied",7.0);h.alarm(5);
    assert_eq!(h.g("playerdied"),8.0);assert_eq!(h.n(1,"playerdied"),0.0);
    h.write_self("roomstart",8.0);h.write_global("roomstart",7.0);h.alarm(6);assert_eq!(h.n(1,"roomstart"),8.0);
    h.write_self("swing",8.0);h.write_self("firing",9.0);h.alarm(2);h.alarm(3);
    assert_eq!(h.n(1,"swing"),8.0);assert_eq!(h.n(1,"firing"),9.0);
}
#[test] fn heal_equality_and_upgrade_branches() {
    for (hp,max,bought,want) in [(4.0,4.0,None,4.0),(3.0,4.0,Some(0.0),3.0),(3.0,4.0,Some(2.0),3.0),(3.0,4.0,Some(1.0),4.0)] {
        let mut h=Host::empty();h.write_global("health1",hp);h.write_global("maxhp",max);
        if let Some(v)=bought {h.write_global("healthregenbought",v);}
        h.alarm(11);assert_eq!(h.g("health1"),want);assert_eq!(h.alarms[&(1,11)],300.0);
    }
}
#[test] fn absent_and_out_of_range_are_side_effect_free() {
    let mut h=Host::empty();let before=h.clone();
    assert_eq!(dispatch_player_alarm(9,&mut h,&RES),Err(AlarmError::NoDirectEvent(9)));
    for i in 12..=255 {assert_eq!(dispatch_player_alarm(i,&mut h,&RES),Err(AlarmError::OutOfRange(i)));}
    assert_eq!(h,before);
}
#[test] #[should_panic(expected="uninitialized Global.timeplayed")] fn missing_read_is_rejected() {Host::empty().alarm(10);}

const OBJECTS:[Object;12]=[Object::Bullet,Object::LaserBeam,Object::Iceball,Object::Rocket,Object::Bomb,Object::Arrow,Object::Blade,Object::Flame,Object::BoomerangThrow,Object::SpikegunSpike,Object::Sword,Object::EnergyWave];
#[test] fn all_weapons_both_facings_use_real_registered_creates_slots_and_resources() {
    for facing in [0.0,1.0] {
        let mut h=Host::fixture();h.write_self("facing",facing);h.write_self("assaultfire",3.0);
        for f in ["pistol","laser","icegun","shotgun","assaultrifle","rocket","bombgun","bow","bladegun","flamethrower","boomerang","spikegun"] {h.write_global(f,1.0);}
        h.alarm(0);h.alarm(1);
        for object in OBJECTS {assert!(!h.ids(object).is_empty(),"{object:?}");}
        let laser=h.read_slot("i1");assert_eq!(h.registry[&laser],Object::LaserBeam);assert_eq!(h.n(laser,"image_xscale"),2.0);
        for slot in ["bullet1","bullet2","bullet3","bullet4","bullet5"] {let id=h.read_slot(slot);assert_eq!(h.registry[&id],Object::Bullet);assert_eq!(h.n(id,"canhit"),0.0);}
        assert_eq!(h.randoms.len(),14);assert_eq!(h.choices.len(),14);assert_eq!(h.motions.len(),14);
        for sound in [RES.snd_fire,RES.snd_laser,RES.snd_ice,RES.snd_shotgun,RES.snd_assaultrifle,RES.snd_bombgun,RES.snd_bow,RES.snd_blade,RES.snd_flamethrower,RES.snd_sword,RES.snd_crescentwave,777.0] {assert!(h.sounds.contains(&sound),"missing sound {sound}");}
        assert_eq!(h.queries,vec![RES.snd_assaultrifle]);assert_eq!(h.stack,vec![1]);
        assert_eq!(h.n(1,"x"),100.0);assert_eq!(h.n(1,"y"),200.0);
    }
}
#[test] fn all_object_names_and_direct_creates_have_exhaustive_oracles() {
    let names=["obj_bullet","obj_laserbeam","obj_iceball","obj_rocket","obj_bomb","obj_arrow","obj_blade","obj_flame","obj_boomerangthrow","obj_spikegunspike","obj_sword","obj_energywave"];
    for (object,name) in OBJECTS.into_iter().zip(names) {
        assert_eq!(object_name(object),name);let mut h=Host::fixture();let id=h.spawn(7.0,8.0,object);
        assert_eq!(h.n(id,"x"),7.0);assert_eq!(h.n(id,"y"),8.0);
        match object {
            Object::Bullet=>{assert_eq!(h.n(id,"canhit"),0.0);assert_eq!(h.n(id,"hspeed"),25.0);}
            Object::LaserBeam=>{assert_eq!(h.n(id,"hspeed"),20.0);assert_eq!(h.alarms[&(id,1)],120.0);}
            Object::Iceball=>assert_eq!(h.n(id,"hspeed"),15.0),
            Object::Rocket=>{for f in ["hitblock","hitwall","canhit","hitboulder"] {assert_eq!(h.n(id,f),0.0);}assert_eq!(h.alarms[&(id,0)],10.0);}
            Object::Bomb=>{assert_eq!(h.n(id,"hitwall"),0.0);assert_eq!(h.alarms[&(id,0)],30.0);}
            Object::Arrow=>{assert_eq!(h.n(id,"hspeed"),15.0);assert_eq!(h.n(id,"vspeed"),-1.0);}
            Object::Blade=>assert_eq!(h.alarms[&(id,1)],40.0),
            Object::Flame=>{assert_eq!(h.alarms[&(id,0)],9.0);assert_eq!(h.n(id,"vspeed"),-1.0);}
            Object::BoomerangThrow=>{assert_eq!(h.n(id,"boomerangreturn"),0.0);assert_eq!(h.n(id,"image_index"),3.0);}
            Object::SpikegunSpike=>{assert_eq!(h.n(id,"type"),2.0);assert_eq!(h.alarms[&(id,1)],240.0);assert!(!h.values.contains_key(&(Scope::Instance(id),"canhit")));}
            Object::Sword=>{assert_eq!(h.n(id,"canhit"),0.0);assert_eq!(h.alarms[&(id,0)],7.0);}
            Object::EnergyWave=>{assert_eq!(h.n(id,"hspeed"),20.0);assert_eq!(h.alarms[&(id,1)],12.0);}
        }
    }
}
#[test] fn nested_sword_create_restores_self_and_writes_registered_child() {
    let mut h=Host::fixture();h.hide_first_sword=true;
    let parent=h.spawn(17.0,18.0,Object::Sword);let child=h.ids(Object::Sword).into_iter().find(|id|*id!=parent).unwrap();
    assert_eq!(h.n(child,"image_angle"),-90.0);assert_eq!(h.n(parent,"image_angle"),0.0);
    assert_eq!(h.n(child,"x"),105.0);assert_eq!(h.n(child,"y"),200.0);
    assert_eq!(h.alarms[&(parent,0)],7.0);assert_eq!(h.alarms[&(child,0)],7.0);assert_eq!(h.stack,vec![1]);
}
#[test] fn remaining_combat_gates_and_projectile_level_branches() {
    for (level,image) in [(3.0,0.0),(4.0,1.0),(6.0,1.0),(7.0,2.0),(9.0,2.0),(10.0,3.0)] {
        let mut h=Host::fixture();h.write_global("boomeranglevel",level);
        let id=h.spawn(0.0,0.0,Object::BoomerangThrow);assert_eq!(h.n(id,"image_index"),image);
    }
    for (level,expected) in [(9.0,1),(10.0,1),(11.0,0)] {
        for facing in [0.0,1.0] {
            let mut h=Host::fixture();h.write_global("pistol",0.0);h.write_global("assaultrifle",1.0);
            h.write_global("assaultriflelevel",level);h.write_self("assaultfire",3.0);h.write_self("facing",facing);
            h.alarm(0);assert_eq!(h.ids(Object::Bullet).len(),expected);assert_eq!(h.g("firing"),1.0);
            if expected==1 {let id=h.ids(Object::Bullet)[0];let sign=if facing==0.0 {1.0}else{-1.0};assert_eq!(h.n(id,"x"),100.0+sign*if level==9.0 {8.0}else{16.0});}
        }
    }
    for mute in [1.0,2.0] {
        let mut h=Host::fixture();h.write_global("soundmute",mute);h.alarm(0);h.alarm(1);assert!(h.sounds.is_empty());
    }
    let mut h=Host::fixture();h.write_global("swing",0.0);h.write_self("sprite_index",RES.spr_playerslash);
    h.alarm(1);assert!(h.registry.is_empty());assert_eq!(h.n(1,"image_index"),4.0);
    h.write_global("swing",1.0);h.write_global("energywavebought",0.0);h.alarm(1);
    assert_eq!(h.ids(Object::Sword).len(),1);assert!(h.ids(Object::EnergyWave).is_empty());
    let mut h=Host::fixture();h.write_self("facing",2.0);h.alarm(0);h.alarm(1);
    assert!(h.registry.is_empty());assert_eq!(h.g("firing"),1.0);assert_eq!(h.g("swing"),1.0);
    // Invalid facing: two-if projectile creates do not invent hspeed, but the
    // original if/else creates deliberately select their else speed.
    for o in [Object::Arrow,Object::Blade,Object::Bomb,Object::Flame,Object::SpikegunSpike] {
        let id=h.spawn(0.0,0.0,o);assert!(!h.values.contains_key(&(Scope::Instance(id),"hspeed")));
    }
    for (o,speed) in [(Object::Iceball,15.0),(Object::LaserBeam,20.0),(Object::Rocket,16.0),(Object::EnergyWave,20.0)] {
        let id=h.spawn(0.0,0.0,o);assert_eq!(h.n(id,"hspeed"),speed);
    }
}
#[test] fn create_room_resource_is_external_and_final_hspeed_is_still_zero() {
    for room in [RES.rm_ending,RES.rm_ending+1.0] {
        let mut h=Host::empty();h.room=room;dispatch_player_create(&mut h,&RES);
        assert_eq!(h.n(1,"hspeed"),0.0);assert_eq!(h.mouse,vec![false]);
        assert_eq!(h.g("playerdied"),0.0);assert_eq!(h.n(1,"playerdied"),0.0);
        assert!(!h.values.contains_key(&(Scope::Global,"maxhp")));
    }
}
#[test] fn nine_simple_events_match_existing_callbacks_and_preserve_unrelated_state() {
    use original_player::{AlarmPlayer,AlarmGlobals,AlarmResources,dispatch_alarm};
    fn populate(h:&mut Host,p:&AlarmPlayer,g:&AlarmGlobals) {
        for (f,v) in [("invulnerable",p.invulnerable),("invulnerable2",p.invulnerable2),
            ("sliding1",p.sliding1),("sliding2",p.sliding2),("hsp",p.hsp),
            ("sprite_index",p.sprite_index),("playerdied",p.playerdied),
            ("throwingboomerang",p.throwingboomerang)] {h.write_self(f,v);}
        for (f,v) in [("health1",g.health1),("maxhp",g.maxhp),("healthregenbought",g.healthregenbought),
            ("timeplayed",g.timeplayed),("roomstart",g.roomstart),("firing",g.firing),("swing",g.swing)] {h.write_global(f,v);}
        for (i,v) in p.alarms.into_iter().enumerate() {h.write_alarm(i,v);}
    }
    for alarm in [2,3,4,5,6,7,8,10,11] {
        for hp in [3.0,4.0,8.0] {for bought in [0.0,1.0,2.0] {
            let mut p=AlarmPlayer {invulnerable:2.0,invulnerable2:3.0,sliding1:4.0,sliding2:5.0,
                hsp:6.0,sprite_index:7.0,playerdied:8.0,throwingboomerang:9.0,
                alarms:std::array::from_fn(|i|i as f64+80.0)};
            let mut g=AlarmGlobals {health1:hp,maxhp:4.0,healthregenbought:bought,timeplayed:123.0,
                roomstart:13.0,firing:14.0,swing:15.0};
            let mut h=Host::empty();populate(&mut h,&p,&g);h.write_self("unrelated",999.0);h.write_global("unrelated",888.0);
            let mut expected=h.clone();
            dispatch_alarm(alarm,&mut p,&mut g,&AlarmResources {spr_player:RES.spr_player}).unwrap();
            populate(&mut expected,&p,&g);
            h.alarm(alarm);
            assert_eq!(h,expected,"alarm={alarm}, hp={hp}, bought={bought}");
        }}
    }
}

#[test] fn player_selector_is_not_current_projectile_self() {
    let mut h=Host::fixture();h.write_self("facing",1.0);
    let id=h.spawn(1.0,2.0,Object::Arrow);assert_eq!(h.n(id,"hspeed"),-15.0);
    assert!(!h.values.contains_key(&(Scope::Instance(id),"facing")));
}
