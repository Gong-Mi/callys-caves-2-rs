#![allow(dead_code)]
// Also runnable with rustc --test; use the real sibling Object, never a copy.
#[path = "../src/original_player_combat.rs"] mod original_player_combat;
#[path = "../src/original_projectile_create.rs"] mod original_projectile_create;
use original_player_combat::Object;
use original_projectile_create::*;
use std::collections::{HashMap, VecDeque};
#[derive(Debug, Clone, PartialEq)]
enum Event { Read(Field), Player(Field), Global(Global), Write(usize,Field,f64), Alarm(usize,usize,f64), Audio(Sound), Random(f64), Choose(Vec<f64>), Motion(f64,f64), Exists, Create(f64,f64,Object) }
struct Host { fields: Vec<HashMap<Field,f64>>, current: usize, player: HashMap<Field,f64>, globals: HashMap<Global,f64>, events: Vec<Event>, exists: VecDeque<bool>, facing_reads: VecDeque<f64>, global_reads: HashMap<Global,VecDeque<f64>>, random_values: VecDeque<f64>, choose_values: VecDeque<f64>, mutate_on_random: bool, mutate_on_write: bool }
impl Host {
 fn new(facing: f64) -> Self { Self { fields: vec![HashMap::from([(Field::ImageAngle,10.0),(Field::Hspeed,99.0),(Field::ImageIndex,99.0)])], current:0, player:HashMap::from([(Field::Facing,facing),(Field::X,100.0),(Field::Y,200.0)]),globals:HashMap::new(),events:vec![],exists:VecDeque::new(),facing_reads:VecDeque::new(),global_reads:HashMap::new(),random_values:VecDeque::new(),choose_values:VecDeque::new(),mutate_on_random:false,mutate_on_write:false } }
 fn value(&self, f:Field)->f64 { *self.fields[0].get(&f).unwrap_or(&0.0) }
 fn written(&self,f:Field,v:f64)->bool { self.events.contains(&Event::Write(0,f,v)) }
}
impl CreateRuntime for Host {
 type Instance=usize;
 fn read_self(&mut self,f:Field)->f64 {self.events.push(Event::Read(f)); *self.fields[self.current].get(&f).unwrap_or(&0.0)}
 fn write_self(&mut self,f:Field,v:f64) { self.fields[self.current].insert(f,v);self.events.push(Event::Write(self.current,f,v)); }
 fn read_player(&mut self,f:Field)->f64 {self.events.push(Event::Player(f));if f==Field::Facing {if let Some(v)=self.facing_reads.pop_front(){return v;}} *self.player.get(&f).unwrap_or(&0.0)}
 fn read_global(&mut self,f:Global)->f64 {self.events.push(Event::Global(f));if let Some(v)=self.global_reads.get_mut(&f).and_then(VecDeque::pop_front){return v;}*self.globals.get(&f).unwrap_or(&0.0)}
 fn write_alarm(&mut self,i:usize,v:f64){self.events.push(Event::Alarm(self.current,i,v));}
 fn audio_play_sound(&mut self,s:Sound,p:f64,l:bool){assert_eq!(p,0.0);assert!(!l);self.events.push(Event::Audio(s));}
 fn random(&mut self,u:f64)->f64 {self.events.push(Event::Random(u));if self.mutate_on_random{self.fields[self.current].insert(Field::ImageAngle,900.0);}self.random_values.pop_front().unwrap_or(u/3.0)}
 fn choose(&mut self,v:&[f64])->f64 {self.events.push(Event::Choose(v.to_vec()));self.choose_values.pop_front().unwrap_or(-1.0)}
 // Test-double motion: intentionally observable direction readback, not a claim
 // to implement GameMaker's negative-speed normalization/physics.
 fn motion_set(&mut self,d:f64,s:f64){self.events.push(Event::Motion(d,s));self.fields[self.current].insert(Field::Direction,d+100.0);}
 fn instance_exists(&mut self,o:Object)->bool{assert_eq!(o,Object::Sword);self.events.push(Event::Exists);self.exists.pop_front().unwrap_or(true)}
 fn instance_create(&mut self,x:f64,y:f64,o:Object)->usize {self.events.push(Event::Create(x,y,o));let parent=self.current;let child=self.fields.len();self.fields.push(HashMap::new());self.current=child;create(self,o);self.current=parent;child}
 fn write_instance(&mut self,id:usize,f:Field,v:f64){self.fields[id].insert(f,v);self.events.push(Event::Write(id,f,v));if self.mutate_on_write {self.fields[self.current].insert(Field::ImageAngle,40.0);}}
}
// Exact traces below test the host boundary, not a fabricated physics engine.
#[test]
fn arrow_behavior_red_green(){let mut h=Host::new(1.0);create(&mut h,Object::Arrow);assert_eq!(h.value(Field::Hspeed),-15.0);assert_eq!(h.value(Field::Vspeed),-1.0);}

#[test]
fn simple_objects_exact_traces_both_facings_and_nonbinary() {
 use Event::*; use Field::*;
 let cases = [
  (Object::Arrow,15.0,true,false,vec![],vec![]),
  (Object::Blade,20.0,false,false,vec![Alarm(0,1,40.0)],vec![]),
  (Object::Bomb,8.0,false,false,vec![Write(0,Canhit,0.0),Write(0,Hitwall,0.0)],vec![Alarm(0,0,30.0)]),
  (Object::Flame,15.0,true,false,vec![Alarm(0,0,9.0)],vec![]),
  (Object::SpikegunSpike,14.0,false,true,vec![Alarm(0,1,240.0),Write(0,Type,2.0)],vec![]),
 ];
 for (object,speed,vertical,scale,prefix,suffix) in cases {
  for facing in [0.0,1.0,2.0] {
   let mut h=Host::new(facing);create(&mut h,object);
   let mut expected=prefix.clone();
   for (test,sign) in [(1.0,-1.0),(0.0,1.0)] {
    expected.push(Player(Facing));
    if facing==test {expected.push(Write(0,Hspeed,sign*speed));if vertical {expected.push(Write(0,Vspeed,-1.0));}if scale {expected.push(Write(0,ImageXscale,sign));}}
   }
   expected.extend(suffix.clone());assert_eq!(h.events,expected,"{object:?} facing={facing}");
  }
 }
}
#[test]
fn else_objects_exact_traces_both_facings_and_nonbinary() {
 use Event::*;use Field::*;
 for (object,speed,prefix,suffix) in [
  (Object::Iceball,15.0,vec![],vec![]),
  (Object::LaserBeam,20.0,vec![Alarm(0,1,120.0)],vec![]),
  (Object::Rocket,16.0,vec![Write(0,Hitblock,0.0),Write(0,Hitwall,0.0),Write(0,Canhit,0.0),Write(0,Hitboulder,0.0)],vec![Alarm(0,0,10.0)]),
 ] {for facing in [0.0,1.0,2.0] {
   let mut h=Host::new(facing);create(&mut h,object);
   let mut expected=prefix.clone();expected.extend([Player(Facing),Write(0,Hspeed,if facing==1.0 {-speed}else{speed})]);expected.extend(suffix.clone());
   assert_eq!(h.events,expected,"{object:?} facing={facing}");
 }}
}
#[test]
fn independent_facing_reads_are_live_not_else_or_cached() {
 for object in [Object::Arrow,Object::Blade,Object::Bomb,Object::Flame,Object::BoomerangThrow,Object::SpikegunSpike,Object::Bullet] {
  let mut h=Host::new(2.0);h.facing_reads=VecDeque::from([1.0,0.0]);create(&mut h,object);
  let speeds:Vec<_>=h.events.iter().filter_map(|e|if let Event::Write(0,Field::Hspeed,v)=e{Some(*v)}else{None}).collect();
  assert_eq!(speeds.len(),2,"{object:?}");assert!(speeds[0]<0.0);assert_eq!(speeds[1],-speeds[0]);
 }
}
#[test]
fn boomerang_all_level_boundaries_and_no_match_gap() {
 use Event::*;use Field::*;
 for (level,index,reads) in [(-1.0,0.0,1),(3.0,0.0,1),(3.5,1.0,2),(6.0,1.0,2),(6.5,2.0,3),(9.0,2.0,3),(9.5,99.0,4),(10.0,3.0,4),(100.0,3.0,4),(f64::NAN,99.0,4)] {
  for facing in [0.0,1.0,2.0] {
   let mut h=Host::new(facing);h.globals.insert(crate::Global::BoomerangLevel,level);create(&mut h,Object::BoomerangThrow);
   let mut expected=vec![Write(0,ImageSpeed,0.0),Player(Facing)];
   if facing==1.0{expected.push(Write(0,Hspeed,-5.0));}expected.push(Player(Facing));if facing==0.0{expected.push(Write(0,Hspeed,5.0));}
   expected.extend([Alarm(0,1,30.0),Write(0,BoomerangReturn,0.0)]);
   for _ in 0..reads{expected.push(Global(crate::Global::BoomerangLevel));}if index!=99.0{expected.push(Write(0,ImageIndex,index));}
   assert_eq!(h.events,expected,"level={level} facing={facing}");assert_eq!(h.value(ImageIndex),index);
  }
 }
}
#[test]
fn energywave_and_existing_sword_mute_branches() {
 use Event::*;use Field::*;
 for object in [Object::EnergyWave,Object::Sword] {for facing in [0.0,1.0,2.0] {for mute in [0.0,1.0,2.0] {
  let mut h=Host::new(facing);h.globals.insert(crate::Global::SoundMute,mute);h.globals.insert(crate::Global::SwordSound,123.0);create(&mut h,object);
  let mut expected=vec![Write(0,Canhit,0.0)];
  if object==Object::Sword {expected.extend([Exists,Alarm(0,0,7.0)]);}else{expected.extend([Player(Facing),Write(0,Hspeed,if facing==1.0{-20.0}else{20.0}),Alarm(0,1,12.0)]);}
  expected.push(Global(crate::Global::SoundMute));
  if mute!=1.0 {expected.push(Global(crate::Global::SoundMute));if mute==0.0 {if object==Object::Sword {expected.push(Global(crate::Global::SwordSound));expected.push(Audio(Sound::Resource(123.0)));}else{expected.push(Audio(Sound::CrescentWave));}}}
  assert_eq!(h.events,expected,"{object:?} facing={facing} mute={mute}");
 }}}
}
#[test]
fn bullet_all_weapon_facing_combinations_exact_vm_order() {
 use Event::*;use Field::*;
 // Includes simultaneous weapons, disabled and nonboolean flags, unmatched facing.
 for facing in [0.0,1.0,2.0] {for shotgun in [0.0,1.0,2.0] {for assault in [0.0,1.0,2.0] {
  let mut h=Host::new(facing);h.globals.insert(crate::Global::Shotgun,shotgun);h.globals.insert(crate::Global::AssaultRifle,assault);create(&mut h,Object::Bullet);
  let mut expected=vec![Write(0,Canhit,0.0),Player(Facing)];if facing==1.0{expected.push(Write(0,Hspeed,-25.0));}expected.push(Player(Facing));if facing==0.0{expected.push(Write(0,Hspeed,25.0));}
  let mut angle=10.0;
  for (global,flag,upper,is_shotgun) in [(crate::Global::Shotgun,shotgun,15.0,true),(crate::Global::AssaultRifle,assault,3.0,false)] {for (test,speed) in [(0.0,32.0),(1.0,-32.0)] {
   expected.extend([Global(global),Player(Facing)]);
   if flag==1.0 && facing==test {
    let direction=angle-upper/3.0;
    expected.extend([Read(ImageAngle),Random(upper),Choose(vec![1.0,-1.0]),Motion(direction,speed)]);
    if is_shotgun {angle=direction+100.0;expected.extend([Read(Direction),Write(0,ImageAngle,angle)]);}
    if test==1.0 {expected.push(Write(0,ImageXscale,-1.0));}
   }
  }}
  assert_eq!(h.events,expected,"facing={facing}, shotgun={shotgun}, assault={assault}");assert_eq!(h.value(ImageAngle),angle);
 }}}
}
#[test]
fn sword_synchronous_child_and_duplicate_live_angle_writes() {
 use Event::*;use Field::*;
 for mutate in [false,true] {for mute in [0.0,1.0,2.0] {
  let mut h=Host::new(0.0);h.exists=VecDeque::from([false,true]);h.mutate_on_write=mutate;h.globals.insert(crate::Global::SoundMute,mute);h.globals.insert(crate::Global::SwordSound,456.0);create(&mut h,Object::Sword);
  let mut expected=vec![Write(0,Canhit,0.0),Exists,Player(Y),Player(X),Create(105.0,200.0,Object::Sword),Write(1,Canhit,0.0),Exists,Alarm(1,0,7.0)];
  let mut audio=vec![Global(crate::Global::SoundMute)];if mute!=1.0 {audio.push(Global(crate::Global::SoundMute));if mute==0.0{audio.extend([Global(crate::Global::SwordSound),Audio(Sound::Resource(456.0))]);}}
  expected.extend(audio.clone());expected.extend([Read(ImageAngle),Write(1,ImageAngle,-80.0),Read(ImageAngle),Write(1,ImageAngle,if mutate{-50.0}else{-80.0}),Alarm(0,0,7.0)]);expected.extend(audio);
  assert_eq!(h.events,expected);assert_eq!(h.fields.len(),2);assert_eq!(h.current,0);assert!(h.exists.is_empty());
 }}
}
#[test]
fn sword_does_not_suppress_host_requested_deeper_recursion() {
 use Event::*;use Field::*;
 let mut h=Host::new(0.0);h.exists=VecDeque::from([false,false,true]);h.globals.insert(crate::Global::SoundMute,1.0);create(&mut h,Object::Sword);
 assert_eq!(h.events,vec![Write(0,Canhit,0.0),Exists,Player(Y),Player(X),Create(105.0,200.0,Object::Sword),Write(1,Canhit,0.0),Exists,Player(Y),Player(X),Create(105.0,200.0,Object::Sword),Write(2,Canhit,0.0),Exists,Alarm(2,0,7.0),Global(crate::Global::SoundMute),Read(ImageAngle),Write(2,ImageAngle,-90.0),Read(ImageAngle),Write(2,ImageAngle,-90.0),Alarm(1,0,7.0),Global(crate::Global::SoundMute),Read(ImageAngle),Write(1,ImageAngle,-80.0),Read(ImageAngle),Write(1,ImageAngle,-80.0),Alarm(0,0,7.0),Global(crate::Global::SoundMute)]);
 assert_eq!(h.current,0);assert_eq!(h.fields.len(),3);
}