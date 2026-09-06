//! Source oracle: restored-source/gml/0010* and 0011* at 59dd348.
//! Preservation oracle: reconstruction/contracts/player-combat.json bindings.
//! This instrumented host exercises Rust event methods, NOT a GameMaker runtime
//! or the real projectile Create events, selector resolution, audio or scheduler.
//! Path import also permits `rustc --test` without the workspace dependencies.
#[path = "../src/original_player_combat.rs"]
mod combat;
use combat::*;
use std::collections::HashMap;

#[derive(Debug, Clone, PartialEq)]
enum Op { ReadSelf(Field), ReadPlayer(Field), ReadGlobal(Global), SelfWrite(Field,f64), GlobalWrite(Global,f64), Alarm(usize,f64), Create(Object,f64,f64,u64), SlotWrite(Slot,u64), SlotRead(Slot), Scale(u64,f64), Query(Sound), Play(Sound,f64,bool) }
#[derive(Default)]
struct Host {
    local: HashMap<Field,f64>, player: HashMap<Field,f64>, global: HashMap<Global,f64>,
    slots: HashMap<Slot,u64>, ops: Vec<Op>, next: u64, playing: bool,
    on_create: Option<fn(&mut Host,Object)>,
    // Simulated host-side slot resolution override, not GM selector semantics.
    slot_read_override: Option<u64>,
}
impl Host {
    fn new() -> Self {
        let mut h=Self::default();
        h.local.extend([(Field::X,100.0),(Field::Y,200.0)]);
        h.player.extend([(Field::X,1000.0),(Field::Y,2000.0)]);
        h
    }
    fn enable(&mut self,g:Global) { self.global.insert(g,1.0); }
    fn facing(&mut self,f:f64) { self.local.insert(Field::Facing,f); self.player.insert(Field::Facing,f); }
    fn effects(&self)->Vec<Op> { self.ops.iter().filter(|o| !matches!(o,Op::ReadSelf(_)|Op::ReadPlayer(_)|Op::ReadGlobal(_))).cloned().collect() }
    fn creates(&self)->Vec<(Object,f64,f64)> { self.ops.iter().filter_map(|o| if let Op::Create(a,b,c,_)=o {Some((*a,*b,*c))} else {None}).collect() }
}
impl CombatRuntime for Host {
    type Instance=u64;
    fn read_self(&mut self,f:Field)->f64 {self.ops.push(Op::ReadSelf(f)); *self.local.get(&f).unwrap_or(&0.0)}
    fn write_self(&mut self,f:Field,v:f64) {self.ops.push(Op::SelfWrite(f,v));self.local.insert(f,v);}
    fn read_player(&mut self,f:Field)->f64 {self.ops.push(Op::ReadPlayer(f)); *self.player.get(&f).unwrap_or(&0.0)}
    fn read_global(&mut self,f:Global)->f64 {self.ops.push(Op::ReadGlobal(f)); *self.global.get(&f).unwrap_or(&0.0)}
    fn write_global(&mut self,f:Global,v:f64) {self.ops.push(Op::GlobalWrite(f,v));self.global.insert(f,v);}
    fn write_alarm(&mut self,i:usize,v:f64) {self.ops.push(Op::Alarm(i,v));}
    fn instance_create(&mut self,x:f64,y:f64,o:Object)->u64 {self.next+=1;let id=self.next;self.ops.push(Op::Create(o,x,y,id));if let Some(hook)=self.on_create {hook(self,o);} id}
    fn write_slot(&mut self,s:Slot,id:u64) {self.ops.push(Op::SlotWrite(s,id));self.slots.insert(s,id);}
    fn read_slot(&mut self,s:Slot)->u64 {self.ops.push(Op::SlotRead(s));self.slot_read_override.unwrap_or(self.slots[&s])}
    fn write_image_xscale(&mut self,id:u64,v:f64) {self.ops.push(Op::Scale(id,v));}
    fn audio_is_playing(&mut self,s:Sound)->bool {self.ops.push(Op::Query(s));self.playing}
    // `playing` models only the assault sound queried by these two events.
    fn audio_play_sound(&mut self,s:Sound,p:f64,l:bool) {self.ops.push(Op::Play(s,p,l));if s==Sound::AssaultRifle {self.playing=true;}}
}

// Tables below are transcribed from the GML binding, not extracted from Rust.
const WEAPONS: [Global; 12] = [Global::Pistol, Global::Laser, Global::Icegun,
    Global::Shotgun, Global::AssaultRifle, Global::Rocket, Global::Bombgun,
    Global::Bow, Global::Bladegun, Global::Flamethrower, Global::Boomerang,
    Global::Spikegun];
const PELLET_SLOTS: [Slot; 5] = [Slot::Bullet1, Slot::Bullet2, Slot::Bullet3,
    Slot::Bullet4, Slot::Bullet5];

fn finish(e: &mut Vec<Op>) {
    e.extend([Op::GlobalWrite(Global::Firing, 1.0), Op::Alarm(3, 5.0)]);
}
fn play(e: &mut Vec<Op>, mute: f64, s: Sound) {
    if mute == 0.0 { e.push(Op::Play(s, 0.0, false)); }
}
fn expected_weapon(g: Global, f: f64, mute: f64) -> Vec<Op> {
    let mut e = vec![];
    let valid = f == 0.0 || f == 1.0;
    let right = f == 0.0;
    let sign = if right { 1.0 } else { -1.0 };
    if !valid && g != Global::Pistol && g != Global::Icegun { return e; }
    match g {
        Global::Pistol => {
            if valid { e.push(Op::Create(Object::Bullet, if right {110.0} else {90.0}, if right {206.0} else {205.0}, 1)); }
            play(&mut e, mute, Sound::Fire);
        }
        Global::Laser => {
            e.extend([Op::Create(Object::LaserBeam,100.0+sign*8.0,206.0,1),
                Op::SlotWrite(Slot::I1,1),Op::SlotRead(Slot::I1),Op::Scale(1,2.0)]);
            finish(&mut e);
            play(&mut e,mute,Sound::Laser);
            return e;
        }
        Global::Shotgun => {
            for (i, slot) in PELLET_SLOTS.into_iter().enumerate() {
                let id = i as u64 + 1;
                e.extend([Op::Create(Object::Bullet,100.0+sign*8.0,if i==0 {201.0} else {207.0},id),Op::SlotWrite(slot,id)]);
            }
            play(&mut e,mute,Sound::Shotgun);
        }
        Global::AssaultRifle => {
            e.push(Op::Create(Object::Bullet,100.0+sign*8.0,208.0,1));
            if mute==0.0 {e.push(Op::Query(Sound::AssaultRifle));}
            play(&mut e,mute,Sound::AssaultRifle);
        }
        _ => {
            let (object, dx, dy, sound, throwing) = match g {
                Global::Icegun => (Object::Iceball,1.0,6.0,Sound::Ice,false),
                Global::Rocket => (Object::Rocket,sign*30.0,3.0,Sound::Bombgun,false),
                Global::Bombgun => (Object::Bomb,sign*20.0,5.0,Sound::Bombgun,false),
                Global::Bow => (Object::Arrow,if right {0.0} else {-3.0},3.0,Sound::Bow,true),
                Global::Bladegun => (Object::Blade,sign*3.0,6.0,Sound::Blade,false),
                Global::Flamethrower => (Object::Flame,sign*10.0,7.0,Sound::Flamethrower,false),
                Global::Boomerang => (Object::BoomerangThrow,sign*10.0,7.0,Sound::Sword,true),
                Global::Spikegun => (Object::SpikegunSpike,sign*24.0,-3.0,Sound::Bombgun,false),
                _ => unreachable!(),
            };
            if throwing {e.push(Op::SelfWrite(Field::ThrowingBoomerang,1.0));}
            e.push(Op::Create(object,100.0+dx,200.0+dy,1));
            play(&mut e,mute,sound);
        }
    }
    finish(&mut e);
    e
}

#[test]
fn every_weapon_facing_and_mute_matrix_preserves_exact_effects() {
    for g in WEAPONS { for f in [0.0,1.0,2.0,-1.0] { for mute in [0.0,1.0,2.0] {
        let mut h=Host::new();h.enable(g);h.facing(f);
        h.global.insert(Global::SoundMute,mute);
        h.local.insert(Field::AssaultFire,3.0);
        alarm0(&mut h);
        assert_eq!(h.effects(),expected_weapon(g,f,mute),"weapon={g:?}, facing={f}, mute={mute}");
    }}}
}

#[test]
fn weapon_flags_are_numeric_equal_one_not_truthy() {
    for g in WEAPONS {for flag in [0.0,2.0,-1.0] {for f in [0.0,1.0,2.0] {
        let mut h=Host::new();h.global.insert(g,flag);h.facing(f);
        h.local.insert(Field::AssaultFire,3.0);
        alarm0(&mut h);
        assert_eq!(h.effects(),vec![],"weapon={g:?}, flag={flag}, facing={f}");
    }}}
}

#[test]
fn object_selector_facing_is_not_event_self_facing() {
    for g in WEAPONS {for (local,player) in [(0.0,1.0),(1.0,0.0),(2.0,0.0),(0.0,2.0)] {
        let mut h=Host::new();h.enable(g);
        h.local.insert(Field::Facing,local);h.player.insert(Field::Facing,player);
        h.local.insert(Field::AssaultFire,3.0);
        let selector = matches!(g,Global::Laser|Global::AssaultRifle|Global::Flamethrower|Global::Boomerang);
        alarm0(&mut h);
        assert_eq!(h.effects(),expected_weapon(g,if selector {player} else {local},0.0),"{g:?} self={local} player={player}");
    }}
}

#[test]
fn all_weapons_stack_in_gml_order_without_deduping_firing_or_alarms() {
    for (f,mute) in [0.0,1.0,2.0].into_iter().flat_map(|f| [0.0,1.0,2.0].map(|m| (f,m))) {
        let mut h=Host::new();h.facing(f);h.global.insert(Global::SoundMute,mute);
        h.local.insert(Field::AssaultFire,3.0);
        let mut expected=vec![];let mut offset=0;
        for g in WEAPONS {
            h.enable(g);
            let mut part=expected_weapon(g,f,mute);
            let count=part.iter().filter(|op| matches!(op,Op::Create(..))).count() as u64;
            for op in &mut part {match op {
                Op::Create(_,_,_,id)|Op::SlotWrite(_,id)|Op::Scale(id,_) => *id+=offset,
                _=>(),
            }}
            offset+=count;expected.extend(part);
        }
        alarm0(&mut h);assert_eq!(h.effects(),expected,"facing={f}");
    }
}

#[test]
fn assault_level_fire_mute_and_audio_query_matrix() {
    for f in [0.0,1.0,2.0] {for level in [-1.0,0.0,9.0,9.5,10.0,11.0] {
        for fire in [0.0,2.0,3.0,4.0] {for mute in [0.0,1.0,2.0] {for playing in [false,true] {
            let mut h=Host::new();h.enable(Global::AssaultRifle);h.facing(f);
            h.global.insert(Global::AssaultRifleLevel,level);h.global.insert(Global::SoundMute,mute);
            h.local.insert(Field::AssaultFire,fire);h.playing=playing;
            let mut e=vec![];
            if f!=2.0 && fire==3.0 {
                let sign=if f==0.0 {1.0} else {-1.0};
                if level<=9.0 {e.push(Op::Create(Object::Bullet,100.0+sign*8.0,208.0,1));}
                else if level==10.0 {e.push(Op::Create(Object::Bullet,100.0+sign*16.0,210.0,1));}
                if mute==0.0 {
                    e.push(Op::Query(Sound::AssaultRifle));
                    if !playing {play(&mut e,mute,Sound::AssaultRifle);}
                }
                finish(&mut e);
            }
            alarm0(&mut h);
            assert_eq!(h.effects(),e,"f={f} level={level} fire={fire} mute={mute} playing={playing}");
            assert_eq!(h.local[&Field::AssaultFire],fire,"Alarm 0 does not reset assaultfire");
        }}}
    }}
}

#[test]
fn laser_rereads_assigned_slot_then_scales_before_firing_and_sound() {
    for f in [0.0,1.0] {
        let mut h=Host::new();h.enable(Global::Laser);h.facing(f);
        h.slots.insert(Slot::I1,444);h.slot_read_override=Some(999);
        h.on_create=Some(|h,o| {assert_eq!(o,Object::LaserBeam);h.slots.insert(Slot::I1,555);});
        alarm0(&mut h);
        let mut e=expected_weapon(Global::Laser,f,0.0);
        e[3]=Op::Scale(999,2.0);
        assert_eq!(h.effects(),e);
        assert_eq!(h.slots[&Slot::I1],1,"assignment occurs after synchronous Create");
    }
}

#[test]
fn shotgun_every_create_can_change_later_positions_flags_and_mute() {
    for f in [0.0,1.0] {
        let mut h=Host::new();h.enable(Global::Shotgun);h.facing(f);
        h.on_create=Some(|h,o| {
            assert_eq!(o,Object::Bullet);
            // Each previous Create has completed its assignment before the next.
            for i in 0..h.next as usize-1 {assert_eq!(h.slots[&PELLET_SLOTS[i]],i as u64+1);}
            assert!(!h.slots.contains_key(&PELLET_SLOTS[h.next as usize-1]));
            if h.next>1 {assert_eq!(h.global[&Global::Shotgun],0.0);}
            *h.local.get_mut(&Field::X).unwrap()+=10.0;
            *h.local.get_mut(&Field::Y).unwrap()+=20.0;
            h.local.insert(Field::Facing,2.0);
            h.global.insert(Global::Shotgun,0.0);
            h.global.insert(Global::SoundMute,if h.next==5 {0.0} else {1.0});
        });
        alarm0(&mut h);
        let mut e=vec![];
        let sign=if f==0.0 {1.0} else {-1.0};
        for (i,slot) in PELLET_SLOTS.into_iter().enumerate() {
            e.extend([Op::Create(Object::Bullet,100.0+10.0*i as f64+sign*8.0,
                200.0+20.0*i as f64+if i==0 {1.0} else {7.0},i as u64+1),Op::SlotWrite(slot,i as u64+1)]);
        }
        play(&mut e,0.0,Sound::Shotgun);finish(&mut e);
        assert_eq!(h.effects(),e,"entered branch stays selected, but coordinates are live: {f}");
        for i in 1..5 {
            let create=h.ops.iter().position(|op|matches!(op,Op::Create(_,_,_,id) if *id==i+1)).unwrap();
            assert_eq!(&h.ops[create-3..create],&[Op::SlotWrite(PELLET_SLOTS[i as usize-1],i),Op::ReadSelf(Field::Y),Op::ReadSelf(Field::X)]);
        }
    }
}

#[test]
fn create_changes_later_weapon_flags_selector_and_sound_immediately() {
    let mut h=Host::new();h.enable(Global::Pistol);h.enable(Global::Icegun);
    h.on_create=Some(|h,o| {if o==Object::Bullet {
        h.enable(Global::Laser);h.global.insert(Global::Icegun,0.0);
        h.global.insert(Global::SoundMute,1.0);h.player.insert(Field::Facing,1.0);
        h.local.insert(Field::X,300.0);h.local.insert(Field::Y,400.0);
    } else {assert_eq!(o,Object::LaserBeam);h.global.insert(Global::SoundMute,0.0);}});
    alarm0(&mut h);
    assert_eq!(h.effects(),vec![Op::Create(Object::Bullet,110.0,206.0,1),
        Op::GlobalWrite(Global::Firing,1.0),Op::Alarm(3,5.0),
        Op::Create(Object::LaserBeam,292.0,406.0,2),Op::SlotWrite(Slot::I1,2),
        Op::SlotRead(Slot::I1),Op::Scale(2,2.0),Op::GlobalWrite(Global::Firing,1.0),
        Op::Alarm(3,5.0),Op::Play(Sound::Laser,0.0,false)]);
}

#[test]
fn independent_direction_ifs_can_both_fire_after_create_changes_facing() {
    for g in [Global::AssaultRifle,Global::Rocket,Global::Bombgun,Global::Bow,
        Global::Bladegun,Global::Flamethrower,Global::Boomerang,Global::Spikegun] {
        let selector=matches!(g,Global::AssaultRifle|Global::Flamethrower|Global::Boomerang);
        let first=if selector {1.0} else {0.0};let second=1.0-first;
        let mut h=Host::new();h.enable(g);h.facing(first);
        h.global.insert(Global::SoundMute,1.0);h.local.insert(Field::AssaultFire,3.0);
        h.on_create=Some(|h,_| {if h.next==1 {
            let f=1.0-h.local[&Field::Facing];h.facing(f);
        }});
        let mut e=expected_weapon(g,first,1.0);let mut second_e=expected_weapon(g,second,1.0);
        for op in &mut second_e {if let Op::Create(_,_,_,id)=op {*id+=1;}}
        e.extend(second_e);alarm0(&mut h);
        assert_eq!(h.effects(),e,"{g:?}: independent if, not else-if");
    }
}

#[test]
fn disabled_eager_pairs_still_read_facing_but_short_circuit_pairs_do_not() {
    let mut h=Host::new();alarm0(&mut h);
    for g in [Global::Rocket,Global::Bombgun,Global::Bow,Global::Bladegun,Global::Spikegun] {
        let indices:Vec<_>=h.ops.iter().enumerate().filter_map(|(i,o)|(*o==Op::ReadGlobal(g)).then_some(i)).collect();
        assert_eq!(indices.len(),2);
        for i in indices {assert_eq!(h.ops[i+1],Op::ReadSelf(Field::Facing),"eager &: {g:?}");}
    }
    for g in [Global::Pistol,Global::Laser,Global::Shotgun] {
        for (i,o) in h.ops.iter().enumerate() {if *o==Op::ReadGlobal(g) {
            assert!(!matches!(h.ops[i+1],Op::ReadSelf(Field::Facing)),"disabled self-facing gate: {g:?}");
            // The final shotgun else-if is followed by assault's independent
            // obj_player.facing read; do not attribute that read to shotgun.
            if g!=Global::Shotgun {
                assert!(!matches!(h.ops[i+1],Op::ReadPlayer(Field::Facing)),"disabled selector gate: {g:?}");
            }
        }}
    }
    assert!(!h.ops.contains(&Op::ReadSelf(Field::AssaultFire)));
}

#[test]
fn slash_facing_swing_wave_and_existing_sprite_matrix() {
    for f in [0.0,1.0,2.0,-1.0] {for swing in [0.0,1.0,2.0] {
        for wave in [0.0,1.0,2.0] {for existing in [false,true] {
            let mut h=Host::new();h.facing(f);h.global.insert(Global::Swing,swing);
            h.global.insert(Global::EnergyWaveBought,wave);
            h.local.insert(Field::SpriteIndex,if existing {77.0} else {88.0});
            h.local.insert(Field::ImageIndex,4.5);
            let mut e=vec![];
            if !existing {e.extend([Op::SelfWrite(Field::ImageIndex,0.0),Op::SelfWrite(Field::SpriteIndex,77.0)]);}
            if swing==1.0 && (f==0.0 || f==1.0) {
                let x=if f==1.0 {1015.0} else {985.0};
                e.extend([Op::Create(Object::Sword,x,1985.0,1),Op::GlobalWrite(Global::Swing,0.0),Op::Alarm(2,9.0)]);
                if wave==1.0 {e.push(Op::Create(Object::EnergyWave,x,1995.0,2));}
            }
            alarm1(&mut h,77.0);assert_eq!(h.effects(),e,"f={f} swing={swing} wave={wave} existing={existing}");
            assert_eq!(h.local[&Field::ImageIndex],if existing {4.5} else {0.0});
        }}
    }}
}

#[test]
fn slash_create_rereads_selector_wave_flag_and_independent_facing_after_swing_reset() {
    let mut h=Host::new();h.enable(Global::Swing);h.facing(1.0);
    h.local.insert(Field::SpriteIndex,77.0);h.local.insert(Field::ImageIndex,6.0);
    h.on_create=Some(|h,o| {match (h.next,o) {
        (1,Object::Sword)=> {
            assert_eq!(h.global[&Global::Swing],1.0);
            h.player.insert(Field::X,3000.0);h.player.insert(Field::Y,4000.0);
            h.enable(Global::EnergyWaveBought);
            h.global.insert(Global::Swing,2.0); // caller must still overwrite to 0
        }
        (2,Object::EnergyWave)=> {
            assert_eq!(h.global[&Global::Swing],0.0);
            h.local.insert(Field::Facing,0.0);
            h.player.insert(Field::X,5000.0);h.player.insert(Field::Y,6000.0);
            h.global.insert(Global::EnergyWaveBought,0.0);
        }
        (3,Object::Sword)=> {assert_eq!(h.global[&Global::Swing],0.0);}
        _=>panic!("unexpected Create"),
    }});
    alarm1(&mut h,77.0);
    assert_eq!(h.effects(),vec![Op::Create(Object::Sword,1015.0,1985.0,1),
        Op::GlobalWrite(Global::Swing,0.0),Op::Alarm(2,9.0),
        Op::Create(Object::EnergyWave,3015.0,3995.0,2),
        Op::Create(Object::Sword,4985.0,5985.0,3),Op::GlobalWrite(Global::Swing,0.0),Op::Alarm(2,9.0)]);
    assert_eq!(h.local[&Field::ImageIndex],6.0);
    assert_eq!(h.ops.iter().filter(|o|**o==Op::ReadGlobal(Global::Swing)).count(),1,"swing checked only on entry");
    let first=h.ops.iter().position(|o|matches!(o,Op::Create(Object::Sword,_,_,1))).unwrap();
    assert_eq!(&h.ops[first+1..first+6],&[Op::GlobalWrite(Global::Swing,0.0),Op::Alarm(2,9.0),
        Op::ReadGlobal(Global::EnergyWaveBought),Op::ReadPlayer(Field::Y),Op::ReadPlayer(Field::X)]);
}

#[test]
fn slash_left_create_does_not_revisit_already_tested_right_if() {
    let mut h=Host::new();h.enable(Global::Swing);h.facing(0.0);
    h.on_create=Some(|h,_| {h.facing(1.0);});
    alarm1(&mut h,77.0);
    assert_eq!(h.creates(),vec![(Object::Sword,985.0,1985.0)]);
}

#[test]
fn exclusive_direction_branches_do_not_run_again_when_create_flips_facing() {
    for g in [Global::Pistol,Global::Laser,Global::Shotgun] {for f in [0.0,1.0] {
        let mut h=Host::new();h.enable(g);h.facing(f);
        h.on_create=Some(|h,_| {if h.next==1 {h.facing(1.0-h.local[&Field::Facing]);}});
        alarm0(&mut h);assert_eq!(h.effects(),expected_weapon(g,f,0.0),"{g:?}, {f}");
    }}
}

#[test]
fn independent_direction_second_branch_rereads_weapon_flag() {
    for g in [Global::AssaultRifle,Global::Rocket,Global::Bombgun,Global::Bow,
        Global::Bladegun,Global::Flamethrower,Global::Boomerang,Global::Spikegun] {
        let selector=matches!(g,Global::AssaultRifle|Global::Flamethrower|Global::Boomerang);
        let first=if selector {1.0} else {0.0};
        let mut h=Host::new();h.enable(g);h.facing(first);h.local.insert(Field::AssaultFire,3.0);
        h.on_create=Some(|h,_| {
            h.facing(1.0-h.local[&Field::Facing]);
            for weapon in WEAPONS {h.global.insert(weapon,0.0);}
        });
        alarm0(&mut h);assert_eq!(h.effects(),expected_weapon(g,first,0.0),"{g:?}");
    }
}

#[test]
fn assault_create_updates_next_level_fire_and_current_audio_query() {
    for stop_fire in [false,true] {
        let mut h=Host::new();h.enable(Global::AssaultRifle);h.facing(1.0);
        h.global.insert(Global::AssaultRifleLevel,9.0);h.local.insert(Field::AssaultFire,3.0);
        // Reuse a test-only unused local field as hook configuration.
        h.local.insert(Field::ImageIndex,if stop_fire {1.0} else {0.0});
        h.on_create=Some(|h,_| {if h.next==1 {
            h.player.insert(Field::Facing,0.0);h.global.insert(Global::AssaultRifleLevel,10.0);
            h.local.insert(Field::X,300.0);h.local.insert(Field::Y,400.0);h.playing=true;
            if h.local[&Field::ImageIndex]==1.0 {h.local.insert(Field::AssaultFire,4.0);}
        }});
        let mut e=vec![Op::Create(Object::Bullet,92.0,208.0,1),Op::Query(Sound::AssaultRifle)];finish(&mut e);
        if !stop_fire {e.extend([Op::Create(Object::Bullet,316.0,410.0,2),Op::Query(Sound::AssaultRifle)]);finish(&mut e);}
        alarm0(&mut h);assert_eq!(h.effects(),e,"stop_fire={stop_fire}");
    }
}

#[test]
fn mute_read_count_and_query_order_preserve_numeric_else_if() {
    for g in WEAPONS {for mute in [0.0,1.0,2.0] {
        let mut h=Host::new();h.enable(g);h.global.insert(Global::SoundMute,mute);
        h.local.insert(Field::AssaultFire,3.0);alarm0(&mut h);
        let indices:Vec<_>=h.ops.iter().enumerate().filter_map(|(i,o)|(*o==Op::ReadGlobal(Global::SoundMute)).then_some(i)).collect();
        assert_eq!(indices.len(),if mute==1.0 {1} else {2},"{g:?}, {mute}");
        let last=*indices.last().unwrap();
        if g==Global::AssaultRifle && mute==0.0 {
            assert_eq!(&h.ops[last+1..last+5],&[Op::Query(Sound::AssaultRifle),Op::Play(Sound::AssaultRifle,0.0,false),Op::GlobalWrite(Global::Firing,1.0),Op::Alarm(3,5.0)]);
        }
    }}
}

#[test]
fn slash_sword_create_can_cancel_previously_enabled_wave_on_either_side() {
    for f in [0.0,1.0] {
        let mut h=Host::new();h.enable(Global::Swing);h.enable(Global::EnergyWaveBought);h.facing(f);
        h.on_create=Some(|h,o| {
            assert_eq!(o,Object::Sword);h.global.insert(Global::EnergyWaveBought,2.0);
            // No sprite reset is repeated after Create changes the sprite.
            h.local.insert(Field::SpriteIndex,88.0);h.local.insert(Field::ImageIndex,7.0);
        });
        alarm1(&mut h,77.0);
        assert_eq!(h.effects(),vec![Op::SelfWrite(Field::ImageIndex,0.0),Op::SelfWrite(Field::SpriteIndex,77.0),
            Op::Create(Object::Sword,if f==0.0 {985.0} else {1015.0},1985.0,1),
            Op::GlobalWrite(Global::Swing,0.0),Op::Alarm(2,9.0)]);
        assert_eq!(h.local[&Field::SpriteIndex],88.0);assert_eq!(h.local[&Field::ImageIndex],7.0);
    }
}

#[test]
fn pistol_exact_effect_order() {
    let mut h=Host::new();h.enable(Global::Pistol);alarm0(&mut h);
    assert_eq!(h.effects(),vec![Op::Create(Object::Bullet,110.0,206.0,1),Op::Play(Sound::Fire,0.0,false),Op::GlobalWrite(Global::Firing,1.0),Op::Alarm(3,5.0)]);
}
#[test]
fn slash_uses_object_coordinates_and_orders_sprite_sword_reset_wave() {
    let mut h=Host::new();h.enable(Global::Swing);h.enable(Global::EnergyWaveBought);h.facing(1.0);alarm1(&mut h,77.0);
    assert_eq!(h.effects(),vec![Op::SelfWrite(Field::ImageIndex,0.0),Op::SelfWrite(Field::SpriteIndex,77.0),Op::Create(Object::Sword,1015.0,1985.0,1),Op::GlobalWrite(Global::Swing,0.0),Op::Alarm(2,9.0),Op::Create(Object::EnergyWave,1015.0,1995.0,2)]);
}
