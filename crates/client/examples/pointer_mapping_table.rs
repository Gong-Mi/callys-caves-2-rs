//! Prints the pointer-mapping table that the JVM bridge prints, so the two
//! implementations can be diffed line by line (scripts/test_pointer_mapping_parity.py).
//! Same surface list and fractions as android-build/tests/PointerMappingBridge.java.
use callys_client::input::{map_x, map_y, PointerReleaseQueue};

fn main() {
    let surfaces = [[2712, 1220], [1952, 1220], [2340, 1080], [1136, 640]];
    for [w, h] in surfaces {
        for fraction in [0.25f32, 0.5, 0.75] {
            let dx = map_x(w as f32 * fraction, w);
            let dy = map_y(h as f32 * fraction, h);
            let mut q = PointerReleaseQueue::new();
            q.down(0);
            q.release(0, 17.0 + w as f32 * fraction, 31.0 + h as f32 * fraction, 17, 31, w, h);
            let up = q.poll().expect("physical release was lost");
            println!("{:.6} {:.6} {:.6} {:.6} {:.6}", fraction, dx, dy, up.x, up.y);
        }
    }
}
