//! Contract slice 6 (EGL loss recovery): the resident page-texture set.
//!
//! Shape-only slice. What is provable WITHOUT a GL context is exactly what
//! keeps the shipped recovery path unchanged, so that is what this file pins:
//!
//! * an empty set is inert - `needs_reupload()` stays false, so the hook in
//!   `present()` (exactly `if self.resident.needs_reupload()`) can never run,
//!   and the set is not eligible for a re-upload pass at all;
//! * a refused re-upload (no live display/surface) is not silently consumed:
//!   the set stays dirty and the next frame with a context retries;
//! * registration bookkeeping - extent/byte validation, duplicate-id refusal,
//!   byte accounting, and the context-loss transition that keeps the CALLER's
//!   bytes while dropping every GL name.
//!
//! The GL half (an injected EGL loss, the recovery frame, byte-equal readback
//! and the GPU-side content checksum) is measured on the device by the javm64
//! harness `~/cally-work/gmbench/Recspike64.java`; it cannot run here because
//! this test binary has no EGL context.
//!
//! Android-only: `parts/gles.rs` is compiled under `cfg(target_os = "android")`,
//! so on a host (CI) build the module does not exist and this file compiles to
//! an empty test binary.
#![cfg(target_os = "android")]

use callys_client::gles::{Presenter, ResidentSet, ResidentTexture};

/// 128x64 RGBA = the shape of a small TPAG page.
fn page_bytes() -> Vec<u8> {
    (0..128u32 * 64 * 4).map(|i| (i % 251) as u8).collect()
}

fn entry(id: u32, buffer: &[u8], w: u32, h: u32, texture: u32) -> ResidentTexture {
    ResidentTexture {
        id,
        texture,
        source: buffer.as_ptr(),
        len: buffer.len(),
        width: w,
        height: h,
    }
}

#[test]
fn empty_set_is_inert_on_every_path() {
    let presenter = Presenter::new();
    assert_eq!(presenter.resident_texture_count(), 0);
    assert_eq!(presenter.resident_texture_bytes(), 0);
    assert!(
        !presenter.resident_needs_reupload(),
        "an empty set must never ask present() for recovery work; the hook in \
         present() is exactly `if self.resident.needs_reupload()`"
    );
    assert!(
        !presenter.resident_reupload_ready(),
        "an empty set is not even eligible for a re-upload pass"
    );
    assert_eq!(presenter.resident_upload_totals(), (0, 0));
}

#[test]
fn registration_and_context_loss_bookkeeping() {
    let mut set = ResidentSet::default();
    let small: Vec<u8> = (0..8 * 4 * 4).map(|i| (i % 251) as u8).collect();
    let big = vec![3u8; 32 * 16 * 4];

    assert!(set.is_empty());
    assert!(set.register(entry(3, &small, 8, 4, 0)), "8x4 page");
    assert!(
        !set.register(entry(3, &small, 8, 4, 0)),
        "a duplicate id has one owner; a silent replace would hide a bookkeeping bug"
    );
    assert!(set.register(entry(1, &big, 32, 16, 11)), "32x16 page, live texture 11");
    assert_eq!(set.len(), 2);
    assert_eq!(set.bytes(), small.len() + big.len());
    assert!(set.needs_reupload(), "a fresh registration has no GPU copy yet");

    // What the recovery frame uploads: every entry, in registration order.
    let ids: Vec<u32> = set.entries().iter().map(|e| e.id).collect();
    assert_eq!(ids, vec![3, 1]);

    // Context loss: GL names die, caller bytes survive (that is the slice).
    set.on_context_lost();
    assert!(set.needs_reupload());
    assert!(set.entries().iter().all(|e| e.texture == 0), "stale GL names dropped");
    assert_eq!(set.bytes(), small.len() + big.len(), "caller RAM cache untouched");
    assert_eq!(set.len(), 2, "the resident set survives the loss");

    // Unregister/clear are the caller's to drive; both leave the set inert.
    assert!(set.unregister(3));
    assert!(!set.unregister(3));
    assert_eq!(set.len(), 1);
    set.clear();
    assert!(set.is_empty());
    assert!(!set.needs_reupload());
    assert_eq!(set.bytes(), 0);
}

#[test]
fn rejected_registrations_do_not_touch_the_set() {
    let mut set = ResidentSet::default();
    let buffer = page_bytes();

    // Byte counts that do not cover width*height*4: the driver would read past
    // the caller's buffer, so they are refused rather than truncated.
    assert!(!set.register(entry(1, &buffer, 128, 63, 0)));
    assert!(!set.register(entry(2, &buffer, 128, 65, 0)));
    // Degenerate extents / empty buffer.
    assert!(!set.register(entry(3, &[], 0, 0, 0)));
    assert!(!set.register(ResidentTexture {
        id: 4,
        texture: 0,
        source: std::ptr::null(),
        len: buffer.len(),
        width: 128,
        height: 64,
    }));
    assert!(set.is_empty(), "nothing invalid must reach the set");
    assert!(!set.needs_reupload());
    assert_eq!(set.bytes(), 0);
}

#[test]
fn blocked_reupload_stays_dirty_for_the_next_frame() {
    // A presenter with a registered page but NO display/surface (exactly the
    // state after a `reset_display`, before init_egl rebuilds it): the re-upload
    // must refuse to touch GL and must leave the set dirty, or the recovery
    // frame would come back with a blank page and no retry.
    let mut presenter = Presenter::new();
    let buffer = page_bytes();
    assert!(presenter.register_resident_texture(1, buffer.as_ptr(), buffer.len(), 128, 64));
    assert_eq!(presenter.resident_texture_count(), 1);
    assert_eq!(presenter.resident_texture_bytes(), buffer.len());
    assert!(presenter.resident_needs_reupload());

    assert!(
        !presenter.resident_reupload_ready(),
        "no display/surface: the re-upload is refused instead of calling GL"
    );
    assert!(
        presenter.resident_needs_reupload(),
        "a refused re-upload is not consumed - the next frame with a context retries"
    );
    assert_eq!(presenter.resident_upload_totals(), (0, 0));

    presenter.clear_resident_textures();
    assert_eq!(presenter.resident_texture_count(), 0);
    assert!(!presenter.resident_needs_reupload());
    assert!(!presenter.resident_reupload_ready());
}
