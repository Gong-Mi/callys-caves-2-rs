//! Per-frame cost of the Android presentation path, measured on host CPU.
//!
//! The device frame loop (MainActivity.RenderLoop -> nativeStep ->
//! nativeBlitToIntArray -> GlesPresenter.present) divides a 16.67 ms budget
//! between four costs that all run on the render thread:
//!
//!   a. logic                -> FrameClock::step_at -> GameState::step
//!   b. raster               -> draw_frame over the whole 1136x640 canvas
//!   c. shuffle + JNI copy   -> parts/jni.rs nativeBlitToIntArray
//!   d. texture upload       -> glTexSubImage2D of the 1136x640 RGBA frame
//!
//! Stages a-c are pure CPU and measurable here; d needs the device GPU and is
//! deliberately reported as bytes/frame only, so the split stays honest.
//!
//! Usage: cargo run --release --example frame_cost
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::load_bundle_from_file;
use std::sync::Arc;
use std::time::Instant;

const W: u32 = 1136;
const H: u32 = 640;
const N: u32 = 600;

fn time_it(label: &str, mut f: impl FnMut()) -> f64 {
    let t = Instant::now();
    for _ in 0..N {
        f();
    }
    let ms = t.elapsed().as_secs_f64() * 1000.0 / N as f64;
    println!("{label:34} {ms:8.2} ms/frame");
    ms
}

fn main() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).unwrap(),
    );
    state.enable_ir_gameplay(bundle).unwrap();
    let mut fb = Framebuffer::new(W, H);
    let dt = 1.0f32 / 60.0;

    println!("canvas {W}x{H}, {N} iterations/frame-cost, dt={dt}");

    // Scene complexity per room: the software raster costs roughly
    // (tiles + objects) blits per frame, so this table is the scaling factor
    // that turns the measured ms/frame into a per-room estimate.
    let mut rooms: Vec<(usize, usize, usize, &str)> = state
        .asset
        .rooms
        .iter()
        .enumerate()
        .map(|(i, r)| (i, r.tiles.len(), r.objects.len(), r.name.as_str()))
        .collect();
    rooms.sort_by_key(|r| std::cmp::Reverse(r.1 + r.2));
    println!("heaviest rooms by tiles+objects (raster cost driver):");
    for (i, t, o, n) in rooms.iter().take(8) {
        println!("  room {i:3} {n:24} tiles={t:5} objects={o:3} sum={:6}", t + o);
    }
    let (ti, tt, to, tn) = rooms[0];
    println!("  == heaviest: {tn} (room {ti}) with {} primitives\n", tt + to);
    for phase_frames in [0u32, 240, 1800] {
        for _ in 0..phase_frames.saturating_sub(0) {
            state.step(dt);
        }
        draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites);
        println!("--- after {phase_frames} warm-up frames ---");
        let a = time_it("a. logic (GameState::step)", || state.step(dt));
        let b = time_it("b. raster (draw_frame)", || {
            draw_frame(&mut fb, &state, &state.asset.tpag_items, &state.asset.sprites)
        });
        // c. exact loop from parts/jni.rs nativeBlitToIntArray
        let mut blit: Vec<i32> = Vec::with_capacity((W * H) as usize);
        let c = time_it("c. shuffle (ABGR->ARGB, per pixel)", || {
            blit.clear();
            for chunk in fb.pixels.chunks_exact(4) {
                let (b_, g_, r_, a_) = (chunk[0], chunk[1], chunk[2], chunk[3]);
                let argb: u32 =
                    ((a_ as u32) << 24) | ((r_ as u32) << 16) | ((g_ as u32) << 8) | (b_ as u32);
                blit.push(argb as i32);
            }
        });
        let total = a + b + c;
        println!(
            "{:34} {total:8.2} ms/frame  -> {:.1} fps ceiling on CPU alone",
            "CPU subtotal (a+b+c)",
            1000.0 / total
        );
        let bytes = (W * H * 4) as f64;
        println!(
            "d. texture upload (device GPU)      {:7.2} MB/frame (JNI copy + driver copy + upload = 3x)",
            bytes / 1e6
        );
        println!(
            "   at 60 fps that is {:.0} MB/s of pixel traffic for the upload leg alone\n",
            bytes * 3.0 * 60.0 / 1e6
        );
        let _ = &blit;
    }
}
