//! Contract slice 6 (EGL loss recovery): the resident page-texture set.
//!
//! Shape-only slice. What is provable WITHOUT a GL context is exactly what keeps
//! the shipped recovery path unchanged and what decides whether a failed
//! re-upload is retried instead of being logged as success, so that is what this
//! file pins:
//!
//! * an empty set is inert - `needs_reupload()` stays false (so the hook in
//!   `present()`, `if self.resident.needs_reupload()`, can never run) and the set
//!   is not eligible for a pass at all;
//! * registration validates with `checked_mul` against the byte count and the GL
//!   `c_int` argument range, and refuses a duplicate id;
//! * the accounting core counts an entry as uploaded ONLY when its upload
//!   reported no error AND ended with a usable GL name: a second-page failure
//!   leaves that entry dirty (retryable), a `glGenTextures` returning 0 is a
//!   failure even with no error set, and a blocked pass (no current context) is
//!   never consumed;
//! * removing the last entry leaves the set clean (no dirty flag, no bytes);
//!   names that existed are queued for deletion, never dropped, and a context
//!   loss discards the queue (those names died with the context) while keeping
//!   the owned bytes.
//!
//! The GL half - the injected EGL loss, the recovery frame, the byte-equal frame
//! readback and the FBO content checksum - is measured on the device by the
//! javm64 harness `~/cally-work/gmbench/Recspike64.java`, because a test binary
//! that references GL symbols cannot even exec on this platform (libGLESv3's
//! `egl_get_connection` does not resolve in a Termux process).
//!
//! Android-only: `parts/gles.rs` is compiled under `cfg(target_os = "android")`,
//! so on a host (CI) build this file compiles to an empty test binary.
#![cfg(target_os = "android")]

use callys_client::gles::{
    Presenter, ResidentError, ResidentSet, ResidentTexture, ResidentUploadResult,
};
use std::sync::Arc;

/// Deterministic page bytes of the given size.
fn page_bytes(len: usize) -> Arc<[u8]> {
    (0..len).map(|i| (i % 251) as u8).collect::<Vec<u8>>().into()
}

fn entry(id: u32, bytes: Arc<[u8]>, width: u32, height: u32) -> ResidentTexture {
    ResidentTexture::new(id, bytes, width, height)
}

/// A full pass where every entry succeeds, with distinct texture names.
fn all_ok(len: usize) -> Vec<ResidentUploadResult> {
    (0..len)
        .map(|index| ResidentUploadResult {
            index,
            error: 0,
            texture: (index + 1) as u32,
        })
        .collect()
}

#[test]
fn empty_set_is_inert_on_every_path() {
    let presenter = Presenter::new();
    assert_eq!(presenter.resident_texture_count(), 0);
    assert_eq!(presenter.resident_texture_bytes(), 0);
    assert!(
        !presenter.resident_needs_reupload(),
        "an empty set must never ask present() for recovery work; the hook is \
         exactly `if self.resident.needs_reupload()`"
    );
    assert!(
        !presenter.resident_reupload_ready(),
        "an empty set is not even eligible for a re-upload pass"
    );
    assert_eq!(presenter.resident_upload_totals(), (0, 0));
    assert_eq!(presenter.resident_failed_uploads(), 0);
    assert_eq!(presenter.resident_pending_deletes(), 0);
}

#[test]
fn registration_validates_extent_bytes_and_ids() {
    let mut set = ResidentSet::default();

    // Byte counts that do not cover width*height*4: the driver would read past
    // the caller's buffer, so they are refused rather than truncated.
    assert_eq!(
        set.register(entry(1, page_bytes(128 * 64 * 4 - 4), 128, 64)),
        Err(ResidentError::ExtentMismatch)
    );
    assert_eq!(
        set.register(entry(2, page_bytes(128 * 64 * 4 + 4), 128, 64)),
        Err(ResidentError::ExtentMismatch)
    );
    // width*height*4 must not silently wrap, and a dimension that does not fit
    // the GL c_int argument is refused, not cast.
    assert_eq!(
        set.register(entry(3, page_bytes(64), 0x8000_0001, 0x8000_0001)),
        Err(ResidentError::ExtentTooLarge)
    );
    assert_eq!(
        set.register(entry(4, page_bytes(64), u32::MAX, 1)),
        Err(ResidentError::ExtentTooLarge)
    );
    assert_eq!(
        set.register(entry(5, page_bytes(64), 0, 1)),
        Err(ResidentError::ExtentTooLarge)
    );
    assert_eq!(
        set.register(entry(6, page_bytes(0), 4, 4)),
        Err(ResidentError::Empty)
    );
    assert!(set.is_empty(), "nothing invalid must reach the set");
    assert!(!set.needs_reupload());
    assert_eq!(set.bytes(), 0);

    // The valid one lands; a second registration of that id is refused.
    assert_eq!(set.register(entry(7, page_bytes(8 * 4 * 4), 8, 4)), Ok(()));
    assert_eq!(
        set.register(entry(7, page_bytes(8 * 4 * 4), 8, 4)),
        Err(ResidentError::DuplicateId)
    );
    assert_eq!(set.len(), 1);
    assert_eq!(set.bytes(), 8 * 4 * 4);
    assert!(set.needs_reupload(), "a fresh entry has no GPU copy yet");
}

#[test]
fn a_failing_entry_is_not_counted_and_stays_retryable() {
    let mut set = ResidentSet::default();
    let small = 8 * 4 * 4;
    let big = 32 * 16 * 4;
    assert_eq!(set.register(entry(3, page_bytes(small), 8, 4)), Ok(()));
    assert_eq!(set.register(entry(1, page_bytes(big), 32, 16)), Ok(()));

    // Pass 1: page 0 uploads, page 1 fails with a GL error. The failed entry
    // must not be counted, must lose its name, and must keep the set dirty.
    let pass1 = vec![
        ResidentUploadResult { index: 0, error: 0, texture: 11 },
        ResidentUploadResult { index: 1, error: 0x0505, texture: 0 },
    ];
    assert_eq!(set.apply_upload_results(&pass1), (1, small));
    assert_eq!(set.uploaded_totals(), (1, small as u64));
    assert_eq!(set.failed_total(), 1);
    assert!(set.needs_reupload(), "the failed entry must stay dirty");
    assert_eq!(set.entries()[0].texture, 11);
    assert_eq!(set.entries()[1].texture, 0, "a failed entry holds no name");

    // Pass 2 (the retry): page 0 is refreshed in place, page 1 rebuilt.
    let pass2 = vec![
        ResidentUploadResult { index: 0, error: 0, texture: 11 },
        ResidentUploadResult { index: 1, error: 0, texture: 12 },
    ];
    assert_eq!(set.apply_upload_results(&pass2), (2, small + big));
    assert_eq!(set.uploaded_totals(), (3, (small + big + small) as u64));
    assert_eq!(set.failed_total(), 1, "the failure history is kept");
    assert!(
        !set.needs_reupload(),
        "once every entry is uploaded the set is clean"
    );
    assert_eq!(set.entries()[1].texture, 12);
}

#[test]
fn a_generated_name_of_zero_is_a_failure_even_without_an_error() {
    let mut set = ResidentSet::default();
    let bytes = 8 * 4 * 4;
    assert_eq!(set.register(entry(9, page_bytes(bytes), 8, 4)), Ok(()));

    // glGenTextures returning 0 sets no GL error: an error-only accounting would
    // call this a success and never retry it.
    let pass = vec![ResidentUploadResult { index: 0, error: 0, texture: 0 }];
    assert_eq!(set.apply_upload_results(&pass), (0, 0));
    assert_eq!(set.uploaded_totals(), (0, 0));
    assert_eq!(set.failed_total(), 1);
    assert!(set.needs_reupload());

    let retry = vec![ResidentUploadResult { index: 0, error: 0, texture: 3 }];
    assert_eq!(set.apply_upload_results(&retry), (1, bytes));
    assert_eq!(set.entries()[0].texture, 3);
    assert!(!set.needs_reupload());
}

#[test]
fn partial_results_do_not_touch_untouched_entries() {
    // A pass that reports only the second entry must not mark the first clean
    // (it simply was not attempted this time) and must not zero its name.
    let mut set = ResidentSet::default();
    assert_eq!(set.register(entry(1, page_bytes(16), 2, 2)), Ok(()));
    assert_eq!(set.register(entry(2, page_bytes(16), 2, 2)), Ok(()));
    assert_eq!(set.apply_upload_results(&all_ok(2)), (2, 32));
    assert!(!set.needs_reupload());

    let pass = vec![ResidentUploadResult { index: 1, error: 0x0502, texture: 0 }];
    assert_eq!(set.apply_upload_results(&pass), (0, 0));
    assert_eq!(set.entries()[0].texture, 1, "the untouched entry keeps its name");
    assert_eq!(set.entries()[1].texture, 0);
    assert!(set.needs_reupload());
}

#[test]
fn removing_the_last_entry_leaves_the_set_clean() {
    let mut set = ResidentSet::default();
    assert_eq!(set.register(entry(1, page_bytes(16), 2, 2)), Ok(()));
    assert_eq!(set.apply_upload_results(&all_ok(1)), (1, 16));
    assert!(!set.needs_reupload());

    // unregister: the live name is queued (dropping it here would pin VRAM for
    // the session), and the now-empty set is clean.
    assert!(set.unregister(1));
    assert!(!set.unregister(1));
    assert!(set.is_empty());
    assert!(!set.needs_reupload(), "no entries means nothing to re-upload");
    assert_eq!(set.bytes(), 0);
    assert_eq!(set.pending_delete_names(), &[1]);

    // clear() queues names too, and only a confirmed delete forgets them.
    assert_eq!(set.register(entry(5, page_bytes(16), 2, 2)), Ok(()));
    assert_eq!(set.apply_upload_results(&all_ok(1)), (1, 16));
    set.clear();
    assert!(set.is_empty());
    assert!(!set.needs_reupload());
    assert_eq!(set.pending_delete_names(), &[1, 1]);
    set.confirm_pending_deletes(1);
    assert_eq!(set.pending_delete_names(), &[1]);
    set.confirm_pending_deletes(99);
    assert!(set.pending_delete_names().is_empty());
}

#[test]
fn context_loss_keeps_bytes_drops_names_and_the_delete_queue() {
    let mut set = ResidentSet::default();
    let bytes = 8 * 4 * 4;
    assert_eq!(set.register(entry(3, page_bytes(bytes), 8, 4)), Ok(()));
    assert_eq!(set.apply_upload_results(&all_ok(1)), (1, bytes));
    assert!(!set.needs_reupload());
    assert_eq!(set.register(entry(1, page_bytes(bytes), 8, 4)), Ok(()));
    // Give the new entry a live name first: only then does unregister have
    // something to queue (a name-less entry needs no delete).
    assert_eq!(
        set.apply_upload_results(&[ResidentUploadResult { index: 1, error: 0, texture: 21 }]),
        (1, bytes)
    );
    assert!(set.unregister(1));
    assert_eq!(set.pending_delete_names(), &[21]);

    set.on_context_lost();
    assert!(
        set.needs_reupload(),
        "every name died, so the set must be re-uploaded"
    );
    assert!(set.entries().iter().all(|e| e.texture == 0));
    assert_eq!(set.bytes(), bytes, "the owned bytes survive the loss");
    assert_eq!(set.len(), 1, "the resident set survives the loss");
    assert!(
        set.pending_delete_names().is_empty(),
        "queued names died with the context - deleting them later would target a fresh context"
    );
}

#[test]
fn presenter_bookkeeping_and_the_gl_free_gate() {
    let mut presenter = Presenter::new();
    let bytes = page_bytes(8 * 4 * 4);

    // A page registers with shared ownership of its bytes.
    assert_eq!(
        presenter.register_resident_texture(1, Arc::clone(&bytes), 8, 4),
        Ok(())
    );
    assert_eq!(presenter.resident_texture_count(), 1);
    assert_eq!(presenter.resident_texture_bytes(), bytes.len());
    assert!(presenter.resident_needs_reupload());
    assert_eq!(
        presenter.register_resident_texture(1, Arc::clone(&bytes), 8, 4),
        Err(ResidentError::DuplicateId)
    );
    assert_eq!(
        presenter.register_resident_texture(2, page_bytes(8 * 4 * 4 - 1), 8, 4),
        Err(ResidentError::ExtentMismatch)
    );

    // No display/context/surface (exactly the state after reset_display): the
    // bookkeeping gate refuses, so a pass would touch no GL call at all.
    assert!(
        !presenter.resident_reupload_ready(),
        "no EGL state: the re-upload is refused instead of calling GL"
    );
    assert!(
        presenter.resident_needs_reupload(),
        "a refused pass is not consumed - the next frame with a context retries"
    );
    assert_eq!(presenter.resident_upload_totals(), (0, 0));

    assert!(presenter.unregister_resident_texture(1));
    assert!(!presenter.unregister_resident_texture(1));
    assert_eq!(presenter.resident_texture_count(), 0);
    assert!(!presenter.resident_needs_reupload());
    assert!(!presenter.resident_reupload_ready());

    presenter
        .register_resident_texture(9, Arc::clone(&bytes), 8, 4)
        .unwrap();
    presenter.clear_resident_textures();
    assert_eq!(presenter.resident_texture_count(), 0);
    assert_eq!(presenter.resident_texture_bytes(), 0);
    assert!(!presenter.resident_needs_reupload());
}
