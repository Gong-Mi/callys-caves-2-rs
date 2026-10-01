//! Host-backed translations of the twelve direct projectile Create events.
//! Evidence: reconstruction/contracts/player-combat.json (original CODE/hash/GML).
//! No physics world, RNG algorithm, selector resolution or generic GM builtins.
use super::original_player_combat::Object;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Field { X, Y, Facing, Hspeed, Vspeed, Canhit, Hitwall, Hitblock, Hitboulder, ImageSpeed, ImageIndex, ImageAngle, ImageXscale, Direction, BoomerangReturn, Type }
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Global { Shotgun, AssaultRifle, BoomerangLevel, SoundMute, SwordSound }
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Sound { CrescentWave, Resource(f64) }

/// All calls are immediate; reads resolve live state, not an event-entry snapshot.
/// The host owns initialized numeric values, object selectors, builtin coupling
/// (hspeed/direction etc.), RNG and resource IDs. `instance_create` runs Create
/// synchronously and restores the caller's self before returning. Visibility in
/// `instance_exists` is entirely host policy, including the currently creating
/// sword: this layer neither suppresses recursion nor fabricates visibility.
pub trait CreateRuntime {
    type Instance: Copy;
    fn read_self(&mut self, field: Field) -> f64;
    fn write_self(&mut self, field: Field, value: f64);
    fn read_player(&mut self, field: Field) -> f64;
    fn read_global(&mut self, field: Global) -> f64;
    fn write_alarm(&mut self, index: usize, value: f64);
    fn audio_play_sound(&mut self, sound: Sound, priority: f64, looping: bool);
    fn random(&mut self, upper: f64) -> f64;
    /// Arguments are in source order, not VM push order.
    fn choose(&mut self, values: &[f64]) -> f64;
    fn motion_set(&mut self, direction: f64, speed: f64);
    fn instance_exists(&mut self, object: Object) -> bool;
    fn instance_create(&mut self, x: f64, y: f64, object: Object) -> Self::Instance;
    fn write_instance(&mut self, instance: Self::Instance, field: Field, value: f64);
}

// Two independent selector reads are intentional (not an if/else or snapshot).
fn two_facings<R: CreateRuntime>(rt: &mut R, speed: f64, vertical: bool, scale: bool) {
    for (facing, sign) in [(1.0, -1.0), (0.0, 1.0)] {
        if rt.read_player(Field::Facing) == facing {
            rt.write_self(Field::Hspeed, sign * speed);
            if vertical { rt.write_self(Field::Vspeed, -1.0); }
            if scale { rt.write_self(Field::ImageXscale, sign); }
        }
    }
}
fn facing_else<R: CreateRuntime>(rt: &mut R, speed: f64) {
    let speed = if rt.read_player(Field::Facing) == 1.0 { -speed } else { speed };
    rt.write_self(Field::Hspeed, speed);
}
fn sound<R: CreateRuntime>(rt: &mut R, sword: bool) {
    if rt.read_global(Global::SoundMute) == 1.0 {
    } else if rt.read_global(Global::SoundMute) == 0.0 {
        let sound = if sword { Sound::Resource(rt.read_global(Global::SwordSound)) }
                    else { Sound::CrescentWave };
        rt.audio_play_sound(sound, 0.0, false);
    }
}
fn bullet<R: CreateRuntime>(rt: &mut R) {
    rt.write_self(Field::Canhit, 0.0);
    two_facings(rt, 25.0, false, false);
    for (weapon, upper, shotgun) in [(Global::Shotgun, 15.0, true), (Global::AssaultRifle, 3.0, false)] {
        for (facing, speed) in [(0.0, 32.0), (1.0, -32.0)] {
            // CODE 282 uses bitwise AND, so both operands are always evaluated.
            let enabled = rt.read_global(weapon) == 1.0;
            let facing_matches = rt.read_player(Field::Facing) == facing;
            if enabled & facing_matches {
                // Actual bytecode: image_angle read, random call, choose call,
                // multiply/add, motion_set. choose pushes -1 then 1, but its
                // public arguments remain source order [1, -1].
                let angle = rt.read_self(Field::ImageAngle);
                let random = rt.random(upper);
                let sign = rt.choose(&[1.0, -1.0]);
                rt.motion_set(angle + random * sign, speed);
                if shotgun {
                    let direction = rt.read_self(Field::Direction);
                    rt.write_self(Field::ImageAngle, direction);
                }
                if facing == 1.0 { rt.write_self(Field::ImageXscale, -1.0); }
            }
        }
    }
}

/// Executes only the object's direct Create body. In particular SpikegunSpike
/// does not implicitly invoke its parent's Create event.
pub fn create<R: CreateRuntime>(rt: &mut R, object: Object) {
    match object {
        Object::Arrow => two_facings(rt, 15.0, true, false),
        Object::Blade => {
            rt.write_alarm(1, 40.0);
            two_facings(rt, 20.0, false, false);
        }
        Object::Bomb => {
            rt.write_self(Field::Canhit, 0.0);
            rt.write_self(Field::Hitwall, 0.0);
            two_facings(rt, 8.0, false, false);
            rt.write_alarm(0, 30.0);
        }
        Object::BoomerangThrow => {
            rt.write_self(Field::ImageSpeed, 0.0);
            two_facings(rt, 5.0, false, false);
            rt.write_alarm(1, 30.0);
            rt.write_self(Field::BoomerangReturn, 0.0);
            if rt.read_global(Global::BoomerangLevel) <= 3.0 {
                rt.write_self(Field::ImageIndex, 0.0);
            } else if rt.read_global(Global::BoomerangLevel) <= 6.0 {
                rt.write_self(Field::ImageIndex, 1.0);
            } else if rt.read_global(Global::BoomerangLevel) <= 9.0 {
                rt.write_self(Field::ImageIndex, 2.0);
            } else if rt.read_global(Global::BoomerangLevel) >= 10.0 {
                rt.write_self(Field::ImageIndex, 3.0);
            }
        }
        Object::Bullet => bullet(rt),
        Object::EnergyWave => {
            rt.write_self(Field::Canhit, 0.0);
            facing_else(rt, 20.0);
            rt.write_alarm(1, 12.0);
            sound(rt, false);
        }
        Object::Flame => {
            rt.write_alarm(0, 9.0);
            two_facings(rt, 15.0, true, false);
        }
        Object::Iceball => facing_else(rt, 15.0),
        Object::LaserBeam => {
            rt.write_alarm(1, 120.0);
            facing_else(rt, 20.0);
        }
        Object::Rocket => {
            for field in [Field::Hitblock, Field::Hitwall, Field::Canhit, Field::Hitboulder] {
                rt.write_self(field, 0.0);
            }
            facing_else(rt, 16.0);
            rt.write_alarm(0, 10.0);
        }
        Object::SpikegunSpike => {
            rt.write_alarm(1, 240.0);
            rt.write_self(Field::Type, 2.0);
            two_facings(rt, 14.0, false, true);
        }
        Object::Sword => {
            rt.write_self(Field::Canhit, 0.0);
            if !rt.instance_exists(Object::Sword) {
                // CODE 309 pushes the call arguments right-to-left: Y before X.
                let y = rt.read_player(Field::Y);
                let x = rt.read_player(Field::X) + 5.0;
                let child = rt.instance_create(x, y, Object::Sword);
                let angle = rt.read_self(Field::ImageAngle) - 90.0;
                rt.write_instance(child, Field::ImageAngle, angle);
                let angle = rt.read_self(Field::ImageAngle) - 90.0;
                rt.write_instance(child, Field::ImageAngle, angle);
            }
            rt.write_alarm(0, 7.0);
            sound(rt, true);
        }
    }
}
