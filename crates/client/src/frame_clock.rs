//! Monotonic render-loop boundary shared by Android JNI and headless tests.
//! `GameState::step` remains one discrete logic tick, including its IR Draw pass.
use crate::GameState;

const NS_PER_SECOND: u128 = 1_000_000_000;

#[derive(Debug)]
pub struct FrameClock {
    last_ns: Option<i64>,
    paused: bool,
    // Exact rational nanoseconds: 1/30s is not an integer number of ns.
    // Keeping the denominator also preserves real elapsed time across ROOM
    // speed changes, instead of reinterpreting a fractional tick at a new rate.
    pending_num: u128,
    pending_den: u128,
}

impl Default for FrameClock {
    fn default() -> Self {
        Self { last_ns: None, paused: false, pending_num: 0, pending_den: 1 }
    }
}

impl FrameClock {
    /// Lifecycle suspension discards both the baseline and partial tick. The
    /// first sample after resume only establishes a fresh baseline: no catch-up.
    pub fn set_paused(&mut self, paused: bool) {
        if self.paused != paused {
            self.paused = paused;
            self.last_ns = None;
            self.clear_pending();
        }
    }

    /// Sample System.nanoTime (Java long / JNI jlong). Its origin can be negative;
    /// wrapping subtraction handles a signed wrap without converting to ms/f32.
    /// Active stalls are consumed in full; presentation is not a logic tick.
    pub fn step_at(&mut self, state: &mut GameState, now_ns: i64) -> u64 {
        if self.paused || state.runtime_diagnostic.is_some() {
            return 0;
        }
        // Presentation boundary: observe the physical input levels even when no
        // logic tick follows, so a DOWN/UP between two ticks is not invisible.
        state.observe_platform_input();
        let Some(last) = self.last_ns else {
            self.last_ns = Some(now_ns);
            return 0;
        };
        let elapsed_ns = now_ns.wrapping_sub(last);
        if elapsed_ns <= 0 {
            // Repeated/backwards samples neither tick nor move the baseline
            // backwards (which would count the same elapsed interval twice).
            return 0;
        }
        self.last_ns = Some(now_ns);
        self.pending_num += elapsed_ns as u128 * self.pending_den;
        let mut ticks = 0;
        loop {
            // A step may transition rooms. Read the current IR ROOM again for
            // every tick within a presentation; the legacy world can be stale.
            let room = state.scene.as_ref()
                .map_or(state.world.current_room_index, |scene| scene.current_room as usize);
            let rate = state.asset.rooms.get(room).map_or(0, |room| room.speed);
            if rate == 0 {
                self.clear_pending();
                break;
            }
            let rate = rate as u128;
            let common = gcd(self.pending_den, rate);
            let multiplier = rate / common;
            let tick_num = NS_PER_SECOND * (self.pending_den / common);
            let available_num = self.pending_num * multiplier;
            if available_num < tick_num {
                break;
            }
            self.pending_num = available_num - tick_num;
            self.pending_den *= multiplier;
            let common = gcd(self.pending_num, self.pending_den);
            self.pending_num /= common;
            self.pending_den /= common;

            // GameState owns input edge publication/retirement: pending physical
            // UP survives zero-tick presentations and is consumed only once in
            // a multi-tick presentation. Never republish it inside this loop.
            state.step(1.0 / rate as f32);
            ticks += 1;
            if state.runtime_diagnostic.is_some() {
                self.clear_pending();
                break;
            }
        }
        ticks
    }

    fn clear_pending(&mut self) {
        self.pending_num = 0;
        self.pending_den = 1;
    }
}

fn gcd(mut a: u128, mut b: u128) -> u128 {
    while b != 0 {
        (a, b) = (b, a % b);
    }
    a
}
