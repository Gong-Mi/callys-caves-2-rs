//! Original obj_introduction runtime contract and state machine (CODE 548..555).
//!
//! Direct events:
//! - CODE 548: Create
//! - CODE 549: Destroy
//! - CODE 550: Alarm 3
//! - CODE 551: Alarm 2
//! - CODE 552: Alarm 1
//! - CODE 553: Alarm 0
//! - CODE 554: Step
//! - CODE 555: Draw coordinates layout

#[derive(Debug, Clone, PartialEq)]
pub struct IntroductionState {
    pub taplock: f64,
    pub moving: f64,
    pub moving2: f64,
    pub xx1: f64,
    pub x1: f64,
    pub xx2: f64,
    pub x2: f64,
    pub xx3: f64,
    pub x3: f64,
    pub xx4: f64,
    pub x4: f64,
    pub image_speed: f64,
    pub alarms: [f64; 4],
    pub destroyed: bool,
}

impl IntroductionState {
    pub fn new() -> Self {
        Self {
            taplock: 0.0,
            moving: 1.0,
            moving2: 0.0,
            xx1: 110.0,
            x1: 200.0,
            xx2: 100.0,
            x2: 175.0,
            xx3: 120.0,
            x3: 240.0,
            xx4: 120.0,
            x4: 240.0,
            image_speed: 0.3,
            alarms: [120.0, 30.0, 70.0, 70.0], // Alarm 0..3
            destroyed: false,
        }
    }

    /// CODE 553: Alarm 0
    pub fn on_alarm0(&mut self) {
        self.taplock = 1.0;
    }

    /// CODE 552: Alarm 1
    pub fn on_alarm1(&mut self) {
        self.moving = 0.0;
        self.moving2 = 1.0;
    }

    /// CODE 551: Alarm 2 (creates obj_logo at 0, 50)
    pub fn on_alarm2<F: FnMut(f64, f64, &'static str)>(&mut self, mut spawn: F) {
        spawn(0.0, 50.0, "obj_logo");
    }

    /// CODE 550: Alarm 3
    pub fn on_alarm3(&mut self) {
        self.moving2 = 0.0;
    }

    /// CODE 554: Step (returns true if tap resulted in destroy)
    pub fn on_step(&mut self, mouse_pressed: bool) -> bool {
        if self.destroyed {
            return false;
        }
        if self.moving == 1.0 {
            self.xx1 -= 2.0;
            self.xx2 -= 2.0;
            self.xx3 -= 2.0;
            self.xx4 -= 2.0;
        }
        if self.moving2 == 1.0 {
            self.xx1 -= 1.0;
            self.xx2 -= 1.0;
            self.xx3 -= 1.0;
            self.xx4 -= 1.0;
        }
        if self.taplock == 1.0 && mouse_pressed {
            self.destroyed = true;
            true
        } else {
            false
        }
    }

    /// Advance alarms by dt frames (e.g. 1 frame)
    pub fn tick_frame<F: FnMut(f64, f64, &'static str)>(&mut self, mouse_pressed: bool, mut spawn: F) -> bool {
        if self.destroyed {
            return false;
        }
        let destroyed = self.on_step(mouse_pressed);
        if destroyed {
            return true;
        }
        for i in 0..4 {
            if self.alarms[i] > 0.0 {
                self.alarms[i] -= 1.0;
                if self.alarms[i] == 0.0 {
                    match i {
                        0 => self.on_alarm0(),
                        1 => self.on_alarm1(),
                        2 => self.on_alarm2(&mut spawn),
                        3 => self.on_alarm3(),
                        _ => {}
                    }
                }
            }
        }
        false
    }
}
