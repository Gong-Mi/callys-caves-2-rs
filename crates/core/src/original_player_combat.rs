//! Direct event-method translations of recovered CODE 10 (Alarm 1) and 11
//! (Alarm 0). The sibling Create module is host-callable; no scheduler or legacy wiring.
//! Numeric fields retain the original equality tests (not Rust boolean flags).

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Field { X, Y, Facing, SpriteIndex, ImageIndex, AssaultFire, ThrowingBoomerang }
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Global { Pistol, Laser, Icegun, Shotgun, AssaultRifle, AssaultRifleLevel, Rocket, Bombgun, Bow, Bladegun, Flamethrower, Boomerang, Spikegun, SoundMute, Firing, Swing, EnergyWaveBought }
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Object { Bullet, LaserBeam, Iceball, Rocket, Bomb, Arrow, Blade, Flame, BoomerangThrow, SpikegunSpike, Sword, EnergyWave }
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Sound { Fire, Laser, Ice, Shotgun, AssaultRifle, Bombgun, Bow, Blade, Flamethrower, Sword }
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Slot { I1, Bullet1, Bullet2, Bullet3, Bullet4, Bullet5 }

/// Host boundary for this specific pair of events, not a general-purpose VM.
/// Reads must resolve live state on every call. `read_player` resolves the GML
/// `obj_player` selector each time, and must not silently alias event `self`.
/// `instance_create` must run Create synchronously before returning its identity;
/// writes and audio calls likewise take effect immediately, never via an effects
/// queue. The host owns resource binding, selector/undefined-value errors and
/// instance lifetime semantics. Numeric fields here require initialized numbers.
pub trait CombatRuntime {
    type Instance: Copy;
    fn read_self(&mut self, field: Field) -> f64;
    fn write_self(&mut self, field: Field, value: f64);
    fn read_player(&mut self, field: Field) -> f64;
    fn read_global(&mut self, field: Global) -> f64;
    fn write_global(&mut self, field: Global, value: f64);
    fn write_alarm(&mut self, index: usize, value: f64);
    fn instance_create(&mut self, x: f64, y: f64, object: Object) -> Self::Instance;
    fn write_slot(&mut self, slot: Slot, instance: Self::Instance);
    fn read_slot(&mut self, slot: Slot) -> Self::Instance;
    fn write_image_xscale(&mut self, instance: Self::Instance, value: f64);
    fn audio_is_playing(&mut self, sound: Sound) -> bool;
    fn audio_play_sound(&mut self, sound: Sound, priority: f64, looping: bool);
}

// Only arguments of one immediate call are held in locals. No state survives
// across a Create call without a new runtime read.
fn create<R: CombatRuntime>(rt: &mut R, object: Object, dx: f64, dy: f64) -> R::Instance {
    // CODE11 pushes instance_create arguments right-to-left.
    let y = rt.read_self(Field::Y) + dy;
    let x = rt.read_self(Field::X) + dx;
    rt.instance_create(x, y, object)
}
fn sound<R: CombatRuntime>(rt: &mut R, sound: Sound, query: bool) {
    if rt.read_global(Global::SoundMute) == 1.0 {
    } else if rt.read_global(Global::SoundMute) == 0.0
        && (!query || !rt.audio_is_playing(sound)) {
        rt.audio_play_sound(sound, 0.0, false);
    }
}
fn firing<R: CombatRuntime>(rt: &mut R) {
    rt.write_global(Global::Firing, 1.0);
    rt.write_alarm(3, 5.0);
}
fn laser<R: CombatRuntime>(rt: &mut R, dx: f64) {
    let id = create(rt, Object::LaserBeam, dx, 6.0);
    rt.write_slot(Slot::I1, id);
    let id = rt.read_slot(Slot::I1);
    rt.write_image_xscale(id, 2.0);
    firing(rt);
    sound(rt, Sound::Laser, false);
}
fn shotgun<R: CombatRuntime>(rt: &mut R, dx: f64) {
    for (slot, dy) in [(Slot::Bullet1, 1.0), (Slot::Bullet2, 7.0),
        (Slot::Bullet3, 7.0), (Slot::Bullet4, 7.0), (Slot::Bullet5, 7.0)] {
        let id = create(rt, Object::Bullet, dx, dy);
        rt.write_slot(slot, id);
    }
    sound(rt, Sound::Shotgun, false);
    firing(rt);
}
fn assault<R: CombatRuntime>(rt: &mut R, sign: f64) {
    if rt.read_global(Global::AssaultRifle) == 1.0 && rt.read_self(Field::AssaultFire) == 3.0 {
        if rt.read_global(Global::AssaultRifleLevel) <= 9.0 {
            create(rt, Object::Bullet, sign * 8.0, 8.0);
        } else if rt.read_global(Global::AssaultRifleLevel) == 10.0 {
            create(rt, Object::Bullet, sign * 16.0, 10.0);
        }
        sound(rt, Sound::AssaultRifle, true);
        firing(rt);
    }
}
fn shot<R: CombatRuntime>(rt: &mut R, object: Object, dx: f64, dy: f64, s: Sound) {
    create(rt, object, dx, dy);
    sound(rt, s, false);
    firing(rt);
}

/// Complete original Alarm 0 (CODE 11). Weapon tests are not exclusive.
pub fn alarm0<R: CombatRuntime>(rt: &mut R) {
    if rt.read_global(Global::Pistol) == 1.0 {
        if rt.read_self(Field::Facing) == 0.0 {
            create(rt, Object::Bullet, 10.0, 6.0);
        } else if rt.read_self(Field::Facing) == 1.0 {
            create(rt, Object::Bullet, -10.0, 5.0);
        }
        sound(rt, Sound::Fire, false);
        firing(rt);
    }
    if rt.read_global(Global::Laser) == 1.0 && rt.read_player(Field::Facing) == 0.0 {
        laser(rt, 8.0);
    } else if rt.read_global(Global::Laser) == 1.0 && rt.read_player(Field::Facing) == 1.0 {
        laser(rt, -8.0);
    }
    if rt.read_global(Global::Icegun) == 1.0 {
        shot(rt, Object::Iceball, 1.0, 6.0, Sound::Ice);
    }
    if rt.read_global(Global::Shotgun) == 1.0 && rt.read_self(Field::Facing) == 0.0 {
        shotgun(rt, 8.0);
    } else if rt.read_global(Global::Shotgun) == 1.0 && rt.read_self(Field::Facing) == 1.0 {
        shotgun(rt, -8.0);
    }
    if rt.read_player(Field::Facing) == 1.0 { assault(rt, -1.0); }
    if rt.read_player(Field::Facing) == 0.0 { assault(rt, 1.0); }
    // GML uses eager `&`, not short-circuit `&&`, for these pairs.
    if (rt.read_global(Global::Rocket) == 1.0) & (rt.read_self(Field::Facing) == 0.0) {
        shot(rt, Object::Rocket, 30.0, 3.0, Sound::Bombgun);
    }
    if (rt.read_global(Global::Rocket) == 1.0) & (rt.read_self(Field::Facing) == 1.0) {
        shot(rt, Object::Rocket, -30.0, 3.0, Sound::Bombgun);
    }
    if (rt.read_global(Global::Bombgun) == 1.0) & (rt.read_self(Field::Facing) == 0.0) {
        shot(rt, Object::Bomb, 20.0, 5.0, Sound::Bombgun);
    }
    if (rt.read_global(Global::Bombgun) == 1.0) & (rt.read_self(Field::Facing) == 1.0) {
        shot(rt, Object::Bomb, -20.0, 5.0, Sound::Bombgun);
    }
    if (rt.read_global(Global::Bow) == 1.0) & (rt.read_self(Field::Facing) == 0.0) {
        rt.write_self(Field::ThrowingBoomerang, 1.0);
        shot(rt, Object::Arrow, 0.0, 3.0, Sound::Bow);
    }
    if (rt.read_global(Global::Bow) == 1.0) & (rt.read_self(Field::Facing) == 1.0) {
        rt.write_self(Field::ThrowingBoomerang, 1.0);
        shot(rt, Object::Arrow, -3.0, 3.0, Sound::Bow);
    }
    if (rt.read_global(Global::Bladegun) == 1.0) & (rt.read_self(Field::Facing) == 0.0) {
        shot(rt, Object::Blade, 3.0, 6.0, Sound::Blade);
    }
    if (rt.read_global(Global::Bladegun) == 1.0) & (rt.read_self(Field::Facing) == 1.0) {
        shot(rt, Object::Blade, -3.0, 6.0, Sound::Blade);
    }
    if rt.read_player(Field::Facing) == 1.0 {
        if rt.read_global(Global::Flamethrower) == 1.0 {
            shot(rt, Object::Flame, -10.0, 7.0, Sound::Flamethrower);
        }
    }
    if rt.read_player(Field::Facing) == 0.0 {
        if rt.read_global(Global::Flamethrower) == 1.0 {
            shot(rt, Object::Flame, 10.0, 7.0, Sound::Flamethrower);
        }
    }
    if rt.read_player(Field::Facing) == 1.0 {
        if rt.read_global(Global::Boomerang) == 1.0 {
            rt.write_self(Field::ThrowingBoomerang, 1.0);
            shot(rt, Object::BoomerangThrow, -10.0, 7.0, Sound::Sword);
        }
    }
    if rt.read_player(Field::Facing) == 0.0 {
        if rt.read_global(Global::Boomerang) == 1.0 {
            rt.write_self(Field::ThrowingBoomerang, 1.0);
            shot(rt, Object::BoomerangThrow, 10.0, 7.0, Sound::Sword);
        }
    }
    if (rt.read_global(Global::Spikegun) == 1.0) & (rt.read_self(Field::Facing) == 0.0) {
        shot(rt, Object::SpikegunSpike, 24.0, -3.0, Sound::Bombgun);
    }
    if (rt.read_global(Global::Spikegun) == 1.0) & (rt.read_self(Field::Facing) == 1.0) {
        shot(rt, Object::SpikegunSpike, -24.0, -3.0, Sound::Bombgun);
    }
}

fn slash<R: CombatRuntime>(rt: &mut R, dx: f64) {
    let y = rt.read_player(Field::Y) - 15.0;
    let x = rt.read_player(Field::X) + dx;
    rt.instance_create(x, y, Object::Sword);
    rt.write_global(Global::Swing, 0.0);
    rt.write_alarm(2, 9.0);
    if rt.read_global(Global::EnergyWaveBought) == 1.0 {
        let y = rt.read_player(Field::Y) - 5.0;
        let x = rt.read_player(Field::X) + dx;
        rt.instance_create(x, y, Object::EnergyWave);
    }
}
/// Complete original Alarm 1 (CODE 10); sprite resource is resolved by caller.
pub fn alarm1<R: CombatRuntime>(rt: &mut R, spr_playerslash: f64) {
    if rt.read_self(Field::SpriteIndex) != spr_playerslash {
        rt.write_self(Field::ImageIndex, 0.0);
        rt.write_self(Field::SpriteIndex, spr_playerslash);
    }
    if rt.read_global(Global::Swing) == 1.0 {
        if rt.read_self(Field::Facing) == 1.0 { slash(rt, 15.0); }
        // Independent if: Create may change facing, even though swing is now 0.
        if rt.read_self(Field::Facing) == 0.0 { slash(rt, -15.0); }
    }
}
