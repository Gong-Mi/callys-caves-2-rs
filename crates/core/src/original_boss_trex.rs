//! Original obj_trex (Boss 1) runtime contract and state machine (CODE 154..162).
//!
//! Direct events:
//! - CODE 154: Create
//! - CODE 155: Destroy
//! - CODE 156: Alarm 6 (poison tick)
//! - CODE 157: Alarm 5 (swordstunned reset)
//! - CODE 158: Alarm 3 (move right hspeed=3)
//! - CODE 159: Alarm 2 (move left hspeed=-3)
//! - CODE 160: Alarm 0 (death explosion, gem/hp/xp drop, global.boss1dead=1)
//! - CODE 161: Step (gravity, facing, wall bounce, hptrex<=0 triggers Alarm 0)
//! - CODE 162: Draw (flashing blend)

#[derive(Debug, Clone, PartialEq)]
pub struct TrexState {
    pub flashing: f64,
    pub poisoned: f64,
    pub swordstunned: f64,
    pub xpdrop: f64,
    pub facing: f64, // 0 = Left, 1 = Right
    pub hpdrop: f64,
    pub coindrop: f64,
    pub hptrex: f64,
    pub boss1maxhp: f64,
    pub hspeed: f64,
    pub vspeed: f64,
    pub gravity: f64,
    pub falling: f64,
    pub image_xscale: f64,
    pub alarms: [f64; 7], // 0..6
    pub dead: bool,
}

impl TrexState {
    /// CODE 154: Create
    pub fn new(pwr: f64) -> Self {
        let (hp, maxhp) = match pwr as i32 {
            1 => (275.0, 275.0),
            2 => (225.0, 225.0),
            3 => (150.0, 150.0),
            4 => (100.0, 100.0),
            _ => (275.0, 275.0),
        };
        let mut alarms = [0.0; 7];
        alarms[2] = 80.0;
        alarms[3] = 100.0;

        Self {
            flashing: 0.0,
            poisoned: 0.0,
            swordstunned: 0.0,
            xpdrop: 1.0,
            facing: 0.0,
            hpdrop: 1.0,
            coindrop: 3.0,
            hptrex: hp,
            boss1maxhp: maxhp,
            hspeed: 0.0,
            vspeed: 0.0,
            gravity: 0.6,
            falling: 1.0,
            image_xscale: -1.0,
            alarms,
            dead: false,
        }
    }

    /// CODE 159: Alarm 2 (Move Left)
    pub fn on_alarm2(&mut self, rm_ending: bool) {
        if !rm_ending {
            self.hspeed = -3.0;
            self.alarms[2] = 90.0;
        }
    }

    /// CODE 158: Alarm 3 (Move Right)
    pub fn on_alarm3(&mut self, rm_ending: bool) {
        if !rm_ending {
            self.hspeed = 3.0;
            self.alarms[3] = 90.0;
        }
    }

    /// CODE 157: Alarm 5 (Sword stunned recover)
    pub fn on_alarm5(&mut self) {
        self.swordstunned = 0.0;
    }

    /// CODE 156: Alarm 6 (Poison tick)
    pub fn on_alarm6(&mut self) {
        self.poisoned = 1.0;
        self.hptrex -= 0.25;
        self.alarms[6] = 30.0;
    }

    /// CODE 160: Alarm 0 (Boss Death)
    pub fn on_alarm0<F: FnMut(&'static str)>(&mut self, mut on_dead: F) {
        self.dead = true;
        on_dead("snd_explode");
    }

    /// Apply player weapon damage to Trex
    pub fn apply_damage(&mut self, damage: f64) {
        self.hptrex -= damage;
        self.flashing = 1.0;
    }

    /// CODE 161: Step
    /// - on_ground: whether instance_place(x, y + 1, par_wall) is true
    /// - left_wall: whether instance_place(x - 30, y, par_wall) is true
    /// - right_wall: whether instance_place(x + 5, y, par_wall) is true
    /// - player_x, player_y: player position for aggression tracking
    pub fn on_step(
        &mut self,
        on_ground: bool,
        left_wall: bool,
        right_wall: bool,
        player_x: f64,
        player_y: f64,
        trex_x: f64,
    ) {
        if self.dead {
            return;
        }

        // hptrex check
        if self.hptrex <= 0.0 {
            self.alarms[0] = 1.0;
        }

        // Gravity
        if on_ground {
            self.gravity = 0.0;
            self.vspeed = 0.0;
            self.falling = 0.0;
        } else {
            self.gravity = 0.6;
            self.falling = 1.0;
        }

        // Facing speed
        if self.facing == 0.0 {
            self.hspeed = -3.0;
            self.image_xscale = -1.0;
        } else if self.facing == 1.0 {
            self.hspeed = 3.0;
            self.image_xscale = -1.0;
        }

        // Player proximity turns boss
        if player_y >= 320.0 && player_x < trex_x {
            self.facing = 0.0;
        }

        // Wall collisions turn boss around
        if right_wall {
            self.facing = 0.0;
        }
        if left_wall {
            self.facing = 1.0;
        }
    }

    /// Advance boss frame
    pub fn tick_frame<F: FnMut(&'static str)>(
        &mut self,
        on_ground: bool,
        left_wall: bool,
        right_wall: bool,
        player_x: f64,
        player_y: f64,
        trex_x: f64,
        mut on_dead: F,
    ) {
        if self.dead {
            return;
        }
        self.on_step(on_ground, left_wall, right_wall, player_x, player_y, trex_x);

        for i in 0..7 {
            if self.alarms[i] > 0.0 {
                self.alarms[i] -= 1.0;
                if self.alarms[i] == 0.0 {
                    match i {
                        0 => self.on_alarm0(&mut on_dead),
                        2 => self.on_alarm2(false),
                        3 => self.on_alarm3(false),
                        5 => self.on_alarm5(),
                        6 => self.on_alarm6(),
                        _ => {}
                    }
                }
            }
        }
    }
}
