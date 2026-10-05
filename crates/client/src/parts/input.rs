// Input semantics: one canvas mapping and one physical-release queue, in Rust.
//
// WHY here: the pointer rules were Java-side (InputViewport.java,
// PointerReleaseQueue.java, MainActivity.logicalButton) and duplicated across
// three files; a second coordinate formula is exactly the bug this project
// already fought once (the DOWN and UP adapters disagreeing about the canvas).
// The semantics are settled and have JVM fixtures, so they move to Rust first
// and the fixtures come along as the equivalence oracle.
//
// Byte-for-byte port of the Java rules; the numbers are the ones the JVM tests
// pin (x*1136/w, y*640/h, the 6-button bands, primary-pointer-only releases).

pub mod input {
    use std::collections::VecDeque;

    /// Engine canvas the original runner draws in (CODE 538's real-device view).
    pub const CANVAS_W: f32 = 1136.0;
    pub const CANVAS_H: f32 = 640.0;

    /// Physical edge -> canvas X. One formula for every pointer edge.
    pub fn map_x(relative_x: f32, surface_width: i32) -> f32 {
        relative_x * CANVAS_W / surface_width as f32
    }

    pub fn map_y(relative_y: f32, surface_height: i32) -> f32 {
        relative_y * CANVAS_H / surface_height as f32
    }

    /// Screen bands -> logical button id, in canvas coordinates.
    /// Anchors (canvas): left (vx-10, vy+190), right (vx+88, vy+190),
    /// jump (vx+380, vy+190), shoot (vx+315, vy+190), sword (vx+380, vy+125).
    pub fn logical_button(x: f32, y: f32) -> u8 {
        if y >= 444.0 {
            if x < 225.0 {
                return 1; // left
            }
            if x < 466.0 {
                return 2; // right
            }
            if x < 760.0 {
                return 0;
            }
            if x < 956.0 {
                return 4; // shoot
            }
            return 3; // jump
        }
        if y >= 279.0 && x >= 913.0 {
            return 5; // sword
        }
        0
    }

    /// A physical primary-pointer release, already mapped to canvas space.
    #[derive(Debug, Clone, Copy, PartialEq)]
    pub struct Release {
        pub x: f32,
        pub y: f32,
    }

    /// Physical primary-pointer releases, independent of virtual button state.
    #[derive(Default)]
    pub struct PointerReleaseQueue {
        primary: i32,
        events: VecDeque<Release>,
    }

    impl PointerReleaseQueue {
        pub fn new() -> Self {
            Self { primary: -1, events: VecDeque::new() }
        }

        pub fn down(&mut self, pointer_id: i32) {
            self.primary = pointer_id;
        }

        pub fn cancel(&mut self) {
            self.primary = -1;
        }

        pub fn reset(&mut self) {
            self.cancel();
            self.events.clear();
        }

        /// A release only counts for the primary pointer, must land inside the
        /// surface after the view offset, and is then mapped to canvas space.
        /// A rejected release still clears the primary (Java drops it the same
        /// way), and a non-primary release does not touch the primary at all.
        pub fn release(
            &mut self,
            pointer_id: i32,
            x: f32,
            y: f32,
            left: i32,
            top: i32,
            width: i32,
            height: i32,
        ) {
            if pointer_id != self.primary || self.primary < 0 {
                return;
            }
            self.primary = -1;
            let x = x - left as f32;
            let y = y - top as f32;
            if width <= 0
                || height <= 0
                || !x.is_finite()
                || !y.is_finite()
                || x < 0.0
                || y < 0.0
                || x >= width as f32
                || y >= height as f32
            {
                return;
            }
            self.events.push_back(Release { x: map_x(x, width), y: map_y(y, height) });
        }

        pub fn poll(&mut self) -> Option<Release> {
            self.events.pop_front()
        }
    }

    #[cfg(test)]
    mod contract {
        // Fixtures are ports of the JVM tests (PointerCoordinateAgreementTest,
        // PointerMappingBridge, PointerReleaseQueueTest) so the two
        // implementations are pinned to the same vectors.
        use super::*;

        const SURFACES: [[i32; 2]; 4] = [[2712, 1220], [1136, 640], [2340, 1080], [1952, 1220]];
        const FRACTIONS: [f32; 3] = [0.25, 0.5, 0.75];

        fn close(a: f32, b: f32, what: &str) {
            assert!((a - b).abs() < 0.001, "{what}: actual={a} expected={b}");
        }

        #[test]
        fn down_and_up_share_one_canvas_on_every_surface() {
            for [w, h] in SURFACES {
                let mut q = PointerReleaseQueue::new();
                q.down(0);
                q.release(0, 17.0 + w as f32 / 2.0, 31.0 + h as f32 / 2.0, 17, 31, w, h);
                let r = q.poll().expect("valid primary release was lost");
                close(map_x(w as f32 / 2.0, w), 568.0, "physical DOWN center X");
                close(map_y(h as f32 / 2.0, h), 320.0, "physical DOWN center Y");
                close(r.x, 568.0, "UP X must match 1136-wide DOWN center");
                close(r.y, 320.0, "UP Y must match 640-high DOWN center");
                assert!(q.poll().is_none());
            }
        }

        #[test]
        fn every_physical_edge_maps_to_the_same_canvas_fraction() {
            for [w, h] in SURFACES {
                for fraction in FRACTIONS {
                    let dx = map_x(w as f32 * fraction, w);
                    let dy = map_y(h as f32 * fraction, h);
                    close(dx, 1136.0 * fraction, "x fraction");
                    close(dy, 640.0 * fraction, "y fraction");
                    let mut q = PointerReleaseQueue::new();
                    q.down(0);
                    q.release(0, 17.0 + w as f32 * fraction, 31.0 + h as f32 * fraction,
                             17, 31, w, h);
                    let up = q.poll().expect("physical release was lost");
                    close(up.x, dx, "UP x must equal the DOWN mapping");
                    close(up.y, dy, "UP y must equal the DOWN mapping");
                }
            }
        }

        #[test]
        fn only_the_primary_pointer_releases() {
            let mut q = PointerReleaseQueue::new();
            q.down(3);
            q.release(8, 580.0, 320.0, 100, 50, 960, 540); // secondary finger is not the mouse
            assert!(q.poll().is_none());
            q.release(3, 580.0, 320.0, 100, 50, 960, 540);
            let r = q.poll().expect("primary release");
            close(r.x, 568.0, "primary x");
            close(r.y, 320.0, "primary y");
            assert!(q.poll().is_none());
            q.release(3, 580.0, 320.0, 100, 50, 960, 540); // duplicate up
            assert!(q.poll().is_none());
        }

        #[test]
        fn cancel_drops_the_primary() {
            let mut q = PointerReleaseQueue::new();
            q.down(0);
            q.cancel();
            q.release(0, 10.0, 10.0, 0, 0, 960, 540);
            assert!(q.poll().is_none());
        }

        #[test]
        fn out_of_surface_and_non_finite_releases_are_rejected() {
            let mut q = PointerReleaseQueue::new();
            for bad_x in [-1.0f32, 960.0, f32::NAN, f32::INFINITY] {
                q.down(0);
                q.release(0, bad_x, 10.0, 0, 0, 960, 540);
                assert!(q.poll().is_none(), "x={bad_x} must be rejected");
            }
            for (w, h) in [(0, 540), (960, 0), (0, 0)] {
                q.down(0);
                q.release(0, 10.0, 10.0, 0, 0, w, h);
                assert!(q.poll().is_none(), "{w}x{h} must be rejected");
            }
            // y is checked the same way x is.
            for bad_y in [-1.0f32, 540.0, f32::NAN, f32::NEG_INFINITY] {
                q.down(0);
                q.release(0, 10.0, bad_y, 0, 0, 960, 540);
                assert!(q.poll().is_none(), "y={bad_y} must be rejected");
            }
        }

        #[test]
        fn reset_clears_pending_and_the_primary() {
            let mut q = PointerReleaseQueue::new();
            q.down(0);
            q.release(0, 10.0, 10.0, 0, 0, 960, 540);
            q.reset();
            assert!(q.poll().is_none());
            q.release(0, 10.0, 10.0, 0, 0, 960, 540); // primary already cleared
            assert!(q.poll().is_none());
        }

        #[test]
        fn view_offset_is_subtracted_before_the_surface_test() {
            let mut q = PointerReleaseQueue::new();
            // Inside the surface only after the offset is applied.
            q.down(0);
            q.release(0, 100.0, 50.0, 100, 50, 960, 540);
            let r = q.poll().expect("release at the surface origin");
            close(r.x, 0.0, "x at origin");
            close(r.y, 0.0, "y at origin");
            // One pixel left of the surface after the offset is rejected.
            q.down(0);
            q.release(0, 99.0, 50.0, 100, 50, 960, 540);
            assert!(q.poll().is_none());
        }

        #[test]
        fn button_bands_partition_the_bottom_hold_jump_and_sword() {
            assert_eq!(logical_button(10.0, 630.0), 1, "left");
            assert_eq!(logical_button(224.9, 630.0), 1, "left edge");
            assert_eq!(logical_button(225.0, 630.0), 2, "right start");
            assert_eq!(logical_button(465.9, 630.0), 2, "right end");
            assert_eq!(logical_button(466.0, 630.0), 0, "gap after right");
            assert_eq!(logical_button(759.9, 630.0), 0, "gap before shoot");
            assert_eq!(logical_button(760.0, 630.0), 4, "shoot start");
            assert_eq!(logical_button(955.9, 630.0), 4, "shoot end");
            assert_eq!(logical_button(956.0, 630.0), 3, "jump start");
            assert_eq!(logical_button(1136.0, 640.0), 3, "jump corner");
            assert_eq!(logical_button(912.9, 300.0), 0, "sword needs x >= 913");
            assert_eq!(logical_button(913.0, 279.0), 5, "sword band start");
            assert_eq!(logical_button(913.0, 443.9), 5, "sword band end");
            assert_eq!(logical_button(300.0, 444.0), 2, "right band starts at y = 444");
            assert_eq!(logical_button(913.0, 444.0), 4, "shoot band wins at x = 913");
            assert_eq!(logical_button(600.0, 444.0), 0, "gap between right and shoot");
            assert_eq!(logical_button(913.0, 278.9), 0, "above the sword band");
        }
    }
}
