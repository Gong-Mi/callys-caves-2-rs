// Event-level touch state machine, ported from MainActivity's listener +
// RenderLoop so the Java host keeps no input semantics of its own.
//
// WHY: the per-event scan, the four frame pulses (tap/attack/sword/jump?) and
// the one-frame `switchWeapon` flag currently live inside the Android view
// listener and the render loop. They are settled behaviour with a device
// history, so they move here behind `event()` / `begin_frame()`; the Java flip
// is a separate change that needs a device smoke (this module is inert until
// something calls it).
//
// Faithful port of the Java rules, including the parts that look odd on paper:
// every event first clears the six held booleans, a non-primary release does
// not touch the primary, ACTION_UP still scans all pointers before clearing,
// and only ACTION_DOWN (not POINTER_DOWN) sets the primary and the tap pulse.

pub mod touch {
    use super::input::{logical_button, map_x, map_y};

    /// Buttons the engine consumes each frame (the `nativeInput` arguments).
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
    pub struct FrameInput {
        pub move_left: bool,
        pub move_right: bool,
        pub jump: bool,
        pub attack: bool,
        pub switch_weapon: bool,
        pub sword: bool,
        pub tap: bool,
    }

    /// MotionEvent action codes the host forwards (android.view.MotionEvent).
    pub const ACTION_DOWN: i32 = 0;
    pub const ACTION_UP: i32 = 1;
    pub const ACTION_MOVE: i32 = 2;
    pub const ACTION_CANCEL: i32 = 3;
    pub const ACTION_POINTER_DOWN: i32 = 5;
    pub const ACTION_POINTER_UP: i32 = 6;

    /// One pointer in a MotionEvent, already in view coordinates.
    #[derive(Debug, Clone, Copy)]
    pub struct Pointer {
        pub id: i32,
        pub x: f32,
        pub y: f32,
    }

    /// Pulse length the Java host used (frames).
    const PULSE_FRAMES: i32 = 4;
    /// Below this canvas y the host treats the touch as a weapon switch.
    const SWITCH_WEAPON_Y: f32 = 137.0;

    #[derive(Debug, Default)]
    pub struct TouchInput {
        move_left: bool,
        move_right: bool,
        jump: bool,
        attack: bool,
        sword: bool,
        switch_weapon: bool,
        jump_pulse: i32,
        attack_pulse: i32,
        sword_pulse: i32,
        tap_pulse: i32,
        primary: i32,
        releases: super::input::PointerReleaseQueue,
    }

    impl TouchInput {
        pub fn new() -> Self {
            Self { primary: -1, ..Default::default() }
        }

        pub fn releases(&mut self) -> &mut super::input::PointerReleaseQueue {
            &mut self.releases
        }

        /// Clear the held booleans the way the Java listener did at event start.
        fn clear_held(&mut self) {
            self.move_left = false;
            self.move_right = false;
            self.jump = false;
            self.attack = false;
            self.sword = false;
        }

        /// Feed one MotionEvent. Returns the button id whose touch haptic the
        /// host should fire (vibration is framework-only; there is no NDK API).
        #[allow(clippy::too_many_arguments)]
        pub fn event(
            &mut self,
            action: i32,
            action_index: i32,
            pointers: &[Pointer],
            left: i32,
            top: i32,
            width: i32,
            height: i32,
        ) -> Option<u8> {
            if width <= 0 || height <= 0 {
                return None;
            }
            self.clear_held();
            let mut haptic = None;
            if action == ACTION_DOWN || action == ACTION_POINTER_DOWN {
                if let Some(p) = pointers.get(action_index.max(0) as usize) {
                    let lx = map_x(p.x - left as f32, width);
                    let ly = map_y(p.y - top as f32, height);
                    haptic = Some(logical_button(lx, ly));
                    if action == ACTION_DOWN {
                        // Original GameMaker mb_left: any tap counts (prologue skip).
                        self.tap_pulse = PULSE_FRAMES;
                        self.primary = p.id;
                        self.releases.down(p.id);
                    }
                }
            }
            if action == ACTION_CANCEL {
                self.releases.cancel();
            } else if action == ACTION_UP || action == ACTION_POINTER_UP {
                if let Some(p) = pointers.get(action_index.max(0) as usize) {
                    self.releases.release(p.id, p.x, p.y, left, top, width, height);
                }
            }
            let lifted = if action == ACTION_POINTER_UP { action_index } else { -1 };
            for (i, p) in pointers.iter().enumerate() {
                if i as i32 == lifted {
                    continue;
                }
                let lx = map_x(p.x - left as f32, width);
                let ly = map_y(p.y - top as f32, height);
                match logical_button(lx, ly) {
                    1 => self.move_left = true,
                    2 => self.move_right = true,
                    3 => self.jump = true,
                    4 => {
                        self.attack = true;
                        self.attack_pulse = PULSE_FRAMES;
                    }
                    5 => {
                        self.sword = true;
                        self.sword_pulse = PULSE_FRAMES;
                    }
                    _ => {}
                }
                if ly < SWITCH_WEAPON_Y {
                    self.switch_weapon = true;
                }
            }
            if action == ACTION_UP || action == ACTION_CANCEL {
                self.clear_held();
            }
            haptic
        }

        /// The input for this frame, then advance the pulses and clear the
        /// one-frame switch flag — the Java render loop's order.
        pub fn begin_frame(&mut self) -> FrameInput {
            let frame = FrameInput {
                move_left: self.move_left,
                move_right: self.move_right,
                jump: self.jump || self.jump_pulse > 0,
                attack: self.attack || self.attack_pulse > 0,
                switch_weapon: self.switch_weapon,
                sword: self.sword || self.sword_pulse > 0,
                tap: self.tap_pulse > 0,
            };
            if self.jump_pulse > 0 {
                self.jump_pulse -= 1;
            }
            if self.attack_pulse > 0 {
                self.attack_pulse -= 1;
            }
            if self.sword_pulse > 0 {
                self.sword_pulse -= 1;
            }
            if self.tap_pulse > 0 {
                self.tap_pulse -= 1;
            }
            self.switch_weapon = false;
            frame
        }

        /// Handover/resume: the Java host re-synced the pointer state here.
        pub fn reset(&mut self) {
            self.clear_held();
            self.switch_weapon = false;
            self.jump_pulse = 0;
            self.attack_pulse = 0;
            self.sword_pulse = 0;
            self.tap_pulse = 0;
            self.releases.reset();
            self.primary = -1;
        }
    }

    #[cfg(test)]
    mod contract {
        use super::*;

        const W: i32 = 1136;
        const H: i32 = 640;

        fn p(id: i32, x: f32, y: f32) -> Pointer {
            Pointer { id, x, y }
        }

        /// A press in a band, in canvas coordinates (surface == canvas here).
        fn down_in(t: &mut TouchInput, x: f32, y: f32) -> Option<u8> {
            t.event(ACTION_DOWN, 0, &[p(0, x, y)], 0, 0, W, H)
        }

        #[test]
        fn a_tap_stays_true_for_exactly_four_frames() {
            let mut t = TouchInput::new();
            assert_eq!(down_in(&mut t, 600.0, 100.0), Some(0)); // gap: tap only
            for frame in 0..4 {
                assert!(t.begin_frame().tap, "tap must be true on frame {frame}");
            }
            assert!(!t.begin_frame().tap, "tap must retire on the fifth frame");
        }

        #[test]
        fn a_held_band_press_survives_frames_without_new_events() {
            let mut t = TouchInput::new();
            down_in(&mut t, 100.0, 600.0); // left band
            for _ in 0..10 {
                let f = t.begin_frame();
                assert!(f.move_left, "held left must stay down without events");
                assert!(!f.move_right && !f.jump && !f.attack && !f.sword);
            }
        }

        #[test]
        fn each_band_maps_to_its_own_flag() {
            for (x, y, check) in [
                (300.0f32, 600.0f32, 1u8), // right
                (1000.0, 600.0, 3),        // jump
                (800.0, 600.0, 4),         // shoot
                (1000.0, 300.0, 5),        // sword
            ] {
                let mut t = TouchInput::new();
                down_in(&mut t, x, y);
                let f = t.begin_frame();
                match check {
                    1 => assert!(f.move_right, "right band at {x},{y}"),
                    3 => assert!(f.jump, "jump band at {x},{y}"),
                    4 => assert!(f.attack, "shoot band at {x},{y}"),
                    5 => assert!(f.sword, "sword band at {x},{y}"),
                    _ => unreachable!(),
                }
            }
        }

        #[test]
        fn the_release_action_re_arms_the_band_pulse() {
            // JAVA QUIRK (kept deliberately): the release action still scans
            // the pointer list (only POINTER_UP skips the lifted index), so it
            // re-arms the pressed band's pulse. Lifting a finger inside the
            // shoot band therefore leaves FOUR more attack frames, not the
            // remainder of the press's pulse. The device build does this.
            let mut t = TouchInput::new();
            down_in(&mut t, 800.0, 600.0); // shoot: pulse armed and consumed one frame
            assert!(t.begin_frame().attack);
            t.event(ACTION_UP, 0, &[p(0, 800.0, 600.0)], 0, 0, W, H);
            let mut true_frames = 0;
            for _ in 0..8 {
                if t.begin_frame().attack {
                    true_frames += 1;
                }
            }
            assert_eq!(true_frames, 4, "the release packs a full-length pulse");
        }

        #[test]
        fn a_second_finger_is_not_the_primary_and_releases_nothing() {
            let mut t = TouchInput::new();
            down_in(&mut t, 100.0, 600.0); // finger 0 becomes primary
            // Second finger down outside the bands.
            t.event(ACTION_POINTER_DOWN, 1, &[p(0, 100.0, 600.0), p(7, 600.0, 100.0)], 0, 0, W, H);
            // Second finger lifts: not the primary, so no release is queued.
            t.event(ACTION_POINTER_UP, 1, &[p(0, 100.0, 600.0), p(7, 600.0, 100.0)], 0, 0, W, H);
            assert!(t.releases().poll().is_none(), "secondary finger is not the mouse");
            assert!(t.begin_frame().move_left, "the first finger keeps holding left");
            // The primary lifts: a release is queued at canvas coordinates.
            t.event(ACTION_UP, 0, &[p(0, 100.0, 600.0)], 0, 0, W, H);
            let r = t.releases().poll().expect("primary release");
            assert_eq!((r.x, r.y), (100.0, 600.0));
        }

        #[test]
        fn lifting_one_finger_recomputes_the_held_buttons() {
            let mut t = TouchInput::new();
            t.event(ACTION_POINTER_DOWN, 0, &[p(0, 100.0, 600.0), p(1, 300.0, 600.0)], 0, 0, W, H);
            let f = t.begin_frame();
            assert!(f.move_left && f.move_right, "both bands held");
            // The left finger lifts; only the lifted index is skipped.
            t.event(ACTION_POINTER_UP, 0, &[p(0, 100.0, 600.0), p(1, 300.0, 600.0)], 0, 0, W, H);
            let f = t.begin_frame();
            assert!(!f.move_left, "lifted finger must not keep left held");
            assert!(f.move_right, "the remaining finger still holds right");
        }

        #[test]
        fn cancel_clears_everything_and_a_late_up_does_not_release() {
            let mut t = TouchInput::new();
            down_in(&mut t, 100.0, 600.0);
            t.event(ACTION_CANCEL, 0, &[p(0, 100.0, 600.0)], 0, 0, W, H);
            let f = t.begin_frame();
            // JAVA QUIRK (kept deliberately): ACTION_CANCEL clears the held
            // buttons but NOT the tap pulse, so a tap already in flight still
            // reads true for its remaining frames. The device build behaves
            // this way; changing it here would be a behaviour change, not a port.
            assert!(!f.move_left, "cancel clears the held buttons");
            assert!(f.tap, "cancel does not clear the tap pulse (Java quirk)");
            // The primary was cancelled: the later UP is not a mouse release.
            t.event(ACTION_UP, 0, &[p(0, 100.0, 600.0)], 0, 0, W, H);
            assert!(t.releases().poll().is_none());
        }

        #[test]
        fn switch_weapon_is_a_single_frame_flag() {
            let mut t = TouchInput::new();
            down_in(&mut t, 600.0, 100.0); // y < 137
            assert!(t.begin_frame().switch_weapon);
            assert!(!t.begin_frame().switch_weapon, "the flag retires after one frame");
        }

        #[test]
        fn action_up_still_scans_before_clearing() {
            // Java scans every pointer on ACTION_UP (lifted index is only
            // skipped for POINTER_UP) and then clears the held flags.
            let mut t = TouchInput::new();
            t.event(ACTION_UP, 0, &[p(0, 100.0, 600.0)], 0, 0, W, H);
            let f = t.begin_frame();
            assert!(!f.move_left, "ACTION_UP clears the held flags");
        }

        #[test]
        fn offset_and_surface_bounds_are_the_same_as_the_release_queue() {
            let mut t = TouchInput::new();
            // A press 10px inside a window offset by (17, 31) maps to the same
            // canvas point as an unoffset press at (10, 10).
            t.event(ACTION_DOWN, 0, &[p(0, 27.0, 41.0)], 17, 31, W, H);
            t.event(ACTION_UP, 0, &[p(0, 27.0, 41.0)], 17, 31, W, H);
            let r = t.releases().poll().expect("offset release");
            assert!((r.x - 10.0).abs() < 0.001 && (r.y - 10.0).abs() < 0.001,
                    "release must subtract the view offset, got {r:?}");
            // Degenerate surface: no event may index out of the pointer list.
            let mut t2 = TouchInput::new();
            assert_eq!(t2.event(ACTION_DOWN, 0, &[p(0, 1.0, 1.0)], 0, 0, 0, 640), None);
            assert_eq!(t2.event(ACTION_DOWN, 5, &[], 0, 0, W, H), None);
        }

        #[test]
        fn reset_returns_to_the_handover_state() {
            let mut t = TouchInput::new();
            down_in(&mut t, 100.0, 600.0);
            t.reset();
            let f = t.begin_frame();
            assert_eq!(f, FrameInput::default(), "reset clears every input");
            assert!(t.releases().poll().is_none());
        }
    }
}
