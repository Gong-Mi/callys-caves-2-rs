//! Original player Alarm callbacks recovered from CODE 1..9.
//!
//! This is an explicit projection of the numeric fields those callbacks access,
//! not a replacement for the complete GML value model or the legacy `Player`.
//! Callers must supply initialized instance/global state and resolved resources.
//! There is no scheduler here: 30/300 remain original alarm tick counts, and
//! dispatching a callback does not implicitly tick or clear any other alarm.
//! The legacy game loop and its JSON save schema are deliberately unchanged.
//!
//! Exact original CODE hashes, GML and direct event bindings are recorded in
//! `reconstruction/contracts/player-alarms.json`; GitHub verifies those bindings.

#[derive(Debug, Clone, PartialEq)]
pub struct AlarmPlayer {
    pub invulnerable: f64,
    pub invulnerable2: f64,
    pub sliding1: f64,
    pub sliding2: f64,
    pub hsp: f64,
    pub sprite_index: f64,
    pub playerdied: f64,
    pub throwingboomerang: f64,
    pub alarms: [f64; 12],
}

#[derive(Debug, Clone, PartialEq)]
pub struct AlarmGlobals {
    pub health1: f64,
    pub maxhp: f64,
    pub healthregenbought: f64,
    pub timeplayed: f64,
    pub roomstart: f64,
    pub firing: f64,
    pub swing: f64,
}

/// Resolved from the original SPRT resource, not inferred from appearance.
#[derive(Debug, Clone, PartialEq)]
pub struct AlarmResources {
    pub spr_player: f64,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum AlarmError {
    NotRestored(u8),
    NoDirectEvent(u8),
    OutOfRange(u8),
}

/// Execute one of the nine complete, numeric callback translations.
///
/// This does not synthesize Create defaults, decrement timers, merge local and
/// global fields, or assume an event which is absent from OBJT. Errors are
/// returned before any state changes. The numeric contract is the game's
/// ordinary flag/counter domain, not general GML coercion/undefined values.
pub fn dispatch_alarm(
    alarm: u8,
    player: &mut AlarmPlayer,
    global: &mut AlarmGlobals,
    resources: &AlarmResources,
) -> Result<(), AlarmError> {
    match alarm {
        // CODE 1: obj_player Alarm 11. Preserve !=, not < or a health clamp.
        11 => {
            if global.health1 != global.maxhp && global.healthregenbought == 1.0 {
                global.health1 += 1.0;
            }
            player.alarms[11] = 300.0;
        }
        // CODE 2: obj_player Alarm 10.
        10 => {
            global.timeplayed += 1.0;
            player.alarms[10] = 30.0;
        }
        // CODE 3: obj_player Alarm 8.
        8 => {
            player.invulnerable = 0.0;
            player.invulnerable2 = 0.0;
        }
        // CODE 4: obj_player Alarm 7.
        7 => player.sprite_index = resources.spr_player,
        // CODE 5: obj_player Alarm 6.
        6 => global.roomstart = 0.0,
        // CODE 6: obj_player Alarm 5 (instance field, not global.playerdied).
        5 => player.playerdied = 0.0,
        // CODE 7: obj_player Alarm 4.
        4 => {
            player.sliding1 = 0.0;
            player.sliding2 = 0.0;
            player.hsp = 0.0;
        }
        // CODE 8: obj_player Alarm 3.
        3 => {
            global.firing = 0.0;
            player.throwingboomerang = 0.0;
        }
        // CODE 9: obj_player Alarm 2.
        2 => {
            global.swing = 1.0;
            player.sprite_index = resources.spr_player;
        }
        0 | 1 => return Err(AlarmError::NotRestored(alarm)),
        9 => return Err(AlarmError::NoDirectEvent(alarm)),
        _ => return Err(AlarmError::OutOfRange(alarm)),
    }
    Ok(())
}
