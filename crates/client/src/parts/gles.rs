// Rust-owned GLES3 presentation: EGL14 + GLES30 in the client crate.
//
// WHY: the presentation path was Java (GlesPresenter.java, 345 lines) and the
// frame crossed the JNI boundary as an int[] every frame. The Android side now
// only hands over the window, and the engine's BGRA framebuffer is uploaded
// straight into a texture - no int shuffle, no framework Canvas / HWUI.
//
// Contract ported from the Java presenter that was device-proven:
//   * ES3 config via the 0x40 renderable bit (the EGL14 wrapper has no
//     EGL_OPENGL_ES3_BIT_KHR constant),
//   * `.bgra` swizzle in the fragment shader (engine bytes are BGRA),
//   * GL_NEAREST sampling so the pixel-art upscale never smooths,
//   * per-surface size queried once (per-frame eglQuerySurface is a MIUI
//     system-resource lookup and spams the log),
//   * a failed eglSwapBuffers drops the window surface so the next frame
//     rebuilds it.
//
// Threading: EGL/GL calls happen on whichever thread calls present(); the Java
// host calls it from its render thread and set_window() from the UI thread,
// exactly like the previous synchronized Java presenter. All state is behind
// one mutex, so the two never interleave; the raw handles make the presenter
// !Send by default, which is why the wrapper asserts Send under the mutex.

pub mod gles {
    use std::os::raw::{c_char, c_int, c_void};
    use std::sync::{Arc, Mutex, OnceLock};

    extern "C" {
        // EGL 1.4 (libEGL.so)
        fn eglGetDisplay(display_id: *mut c_void) -> *mut c_void;
        fn eglInitialize(dpy: *mut c_void, major: *mut c_int, minor: *mut c_int) -> u32;
        fn eglChooseConfig(
            dpy: *mut c_void,
            attribs: *const c_int,
            configs: *mut *mut c_void,
            config_size: c_int,
            num_config: *mut c_int,
        ) -> u32;
        fn eglCreateContext(
            dpy: *mut c_void,
            config: *mut c_void,
            share: *mut c_void,
            attribs: *const c_int,
        ) -> *mut c_void;
        fn eglCreateWindowSurface(
            dpy: *mut c_void,
            config: *mut c_void,
            win: *mut c_void,
            attribs: *const c_int,
        ) -> *mut c_void;
        fn eglMakeCurrent(
            dpy: *mut c_void,
            draw: *mut c_void,
            read: *mut c_void,
            ctx: *mut c_void,
        ) -> u32;
        fn eglSwapBuffers(dpy: *mut c_void, surface: *mut c_void) -> u32;
        fn eglDestroySurface(dpy: *mut c_void, surface: *mut c_void) -> u32;
        fn eglQuerySurface(dpy: *mut c_void, surface: *mut c_void, attr: c_int, value: *mut c_int) -> u32;
        fn eglGetError() -> c_int;
        // eglQueryString, NOT eglGetString: the device's libEGL (and the NDK
        // API-24 stub) export only the display-parameterised form; a direct
        // reference to eglGetString is an undefined symbol at dlopen and the
        // whole cdylib fails to load on real devices (found by the on-device
        // acceptance run, absent from CI and emulator evidence).
        fn eglQueryString(dpy: *mut c_void, name: c_int) -> *const c_char;

        // GLES 3.0 (libGLESv3.so)
        fn glGetString(name: u32) -> *const u8;
        fn glGenTextures(n: c_int, textures: *mut u32);
        fn glBindTexture(target: u32, texture: u32);
        fn glTexParameteri(target: u32, pname: u32, param: c_int);
        fn glTexImage2D(
            target: u32,
            level: c_int,
            internal: c_int,
            width: c_int,
            height: c_int,
            border: c_int,
            format: u32,
            ty: u32,
            pixels: *const c_void,
        );
        fn glTexSubImage2D(
            target: u32,
            level: c_int,
            x: c_int,
            y: c_int,
            width: c_int,
            height: c_int,
            format: u32,
            ty: u32,
            pixels: *const c_void,
        );
        fn glActiveTexture(texture: u32);
        fn glViewport(x: c_int, y: c_int, width: c_int, height: c_int);
        fn glClearColor(r: f32, g: f32, b: f32, a: f32);
        fn glClear(mask: u32);
        fn glCreateShader(ty: u32) -> u32;
        fn glShaderSource(shader: u32, count: c_int, string: *const *const c_char, length: *const c_int);
        fn glCompileShader(shader: u32);
        fn glGetShaderiv(shader: u32, pname: u32, params: *mut c_int);
        fn glGetShaderInfoLog(shader: u32, max: c_int, len: *mut c_int, log: *mut c_char);
        fn glDeleteShader(shader: u32);
        fn glCreateProgram() -> u32;
        fn glAttachShader(program: u32, shader: u32);
        fn glLinkProgram(program: u32);
        fn glGetProgramiv(program: u32, pname: u32, params: *mut c_int);
        fn glGetProgramInfoLog(program: u32, max: c_int, len: *mut c_int, log: *mut c_char);
        fn glDeleteProgram(program: u32);
        fn glUseProgram(program: u32);
        fn glGetAttribLocation(program: u32, name: *const c_char) -> c_int;
        fn glGetUniformLocation(program: u32, name: *const c_char) -> c_int;
        fn glGenBuffers(n: c_int, buffers: *mut u32);
        fn glBindBuffer(target: u32, buffer: u32);
        fn glBufferData(target: u32, size: isize, data: *const c_void, usage: u32);
        fn glGenVertexArrays(n: c_int, arrays: *mut u32);
        fn glBindVertexArray(array: u32);
        fn glEnableVertexAttribArray(index: u32);
        fn glVertexAttribPointer(
            index: u32,
            size: c_int,
            ty: u32,
            normalized: u8,
            stride: c_int,
            pointer: *const c_void,
        );
        fn glDrawArrays(mode: u32, first: c_int, count: c_int);
        fn glUniform1i(location: c_int, v0: c_int);
        // Only consumed by the recovery re-upload path (contract slice 6): the
        // first driver error after a resident-set upload is logged once, so a
        // silent no-op upload cannot be mistaken for a successful one.
        fn glGetError() -> u32;
        fn glDeleteTextures(n: c_int, textures: *const u32);

        // libandroid.so: turn a Java Surface into an EGL window.
        fn ANativeWindow_fromSurface(env: *mut c_void, surface: *mut c_void) -> *mut c_void;
        fn ANativeWindow_release(window: *mut c_void);
    }

    const EGL_NO_DISPLAY: *mut c_void = std::ptr::null_mut();
    const EGL_NO_SURFACE: *mut c_void = std::ptr::null_mut();
    const EGL_NO_CONTEXT: *mut c_void = std::ptr::null_mut();
    const EGL_DEFAULT_DISPLAY: *mut c_void = std::ptr::null_mut();
    const EGL_NOT_INITIALIZED: c_int = 0x3001;
    const EGL_RENDERABLE_TYPE: c_int = 0x3040;
    const EGL_OPENGL_ES3_BIT: c_int = 0x40; // EGL_OPENGL_ES3_BIT_KHR
    const EGL_SURFACE_TYPE: c_int = 0x3033;
    const EGL_WINDOW_BIT: c_int = 0x0004;
    // EGL config attribute ids (EGL 1.5 §3.4): the previous values (8/9/10/11)
    // were not attribute ids at all, so eglChooseConfig returned EGL_FALSE with
    // EGL_BAD_ATTRIBUTE and the Rust presenter could never initialise.
    const EGL_RED_SIZE: c_int = 0x3024;
    const EGL_GREEN_SIZE: c_int = 0x3023;
    const EGL_BLUE_SIZE: c_int = 0x3022;
    const EGL_ALPHA_SIZE: c_int = 0x3021;
    const EGL_NONE: c_int = 0x3038;
    const EGL_WIDTH: c_int = 0x3057;
    const EGL_HEIGHT: c_int = 0x3056;
    const EGL_CONTEXT_CLIENT_VERSION: c_int = 0x3098;
    const EGL_VENDOR: c_int = 0x3053;
    const EGL_DRAW: c_int = 0x3059;

    const GL_TEXTURE_2D: u32 = 0x0DE1;
    const GL_RGBA: u32 = 0x1908;
    const GL_UNSIGNED_BYTE: u32 = 0x1401;
    const GL_TEXTURE_MIN_FILTER: u32 = 0x2801;
    const GL_TEXTURE_MAG_FILTER: u32 = 0x2800;
    const GL_TEXTURE_WRAP_S: u32 = 0x2802;
    const GL_TEXTURE_WRAP_T: u32 = 0x2803;
    const GL_NEAREST: c_int = 0x2600;
    const GL_CLAMP_TO_EDGE: c_int = 0x812F;
    const GL_ARRAY_BUFFER: u32 = 0x8892;
    const GL_STATIC_DRAW: u32 = 0x88E4;
    const GL_FLOAT: u32 = 0x1406;
    const GL_TRIANGLE_STRIP: u32 = 0x0005;
    const GL_TEXTURE0: u32 = 0x84C0;
    const GL_COLOR_BUFFER_BIT: u32 = 0x00004000;
    const GL_VERTEX_SHADER: u32 = 0x8B31;
    const GL_FRAGMENT_SHADER: u32 = 0x8B30;
    const GL_COMPILE_STATUS: u32 = 0x8B81;
    const GL_LINK_STATUS: u32 = 0x8B82;

    /// Triangle strip: top-left, top-right, bottom-left, bottom-right. v=0 is
    /// the engine framebuffer's first (top) row, so no flip is needed.
    const QUAD: [f32; 16] = [
        -1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, -1.0, -1.0, 0.0, 1.0, 1.0, -1.0, 1.0, 1.0,
    ];

    const VERTEX_SHADER: &str = "#version 300 es\nin vec2 aPos;\nin vec2 aUv;\nout vec2 vUv;\nvoid main() {\n    vUv = aUv;\n    gl_Position = vec4(aPos, 0.0, 1.0);\n}\n";
    const FRAGMENT_SHADER: &str = "#version 300 es\nprecision mediump float;\nuniform sampler2D uTex;\nin vec2 vUv;\nout vec4 fragColor;\nvoid main() {\n    // Engine bytes are little-endian ARGB ints = B,G,R,A in memory; an RGBA\n    // upload therefore reads back swapped, so swizzle here.\n    fragColor = texture(uTex, vUv).bgra;\n}\n";

    extern "C" {
        fn __android_log_write(prio: c_int, tag: *const c_char, text: *const c_char) -> c_int;
    }

    /// The presenter logs under its own tag (the Java presenter's tag never
    /// showed up on MIUI, so this one is separate on purpose).
    fn log(msg: &str) {
        let tag = std::ffi::CString::new("GlesRust").unwrap_or_default();
        let text = std::ffi::CString::new(msg).unwrap_or_default();
        unsafe {
            __android_log_write(4, tag.as_ptr(), text.as_ptr());
        }
    }

    /// One page texture the command backend keeps on the GPU and wants back
    /// after an EGL context loss (contract slice 6).
    ///
    /// The bytes are OWNED (`Arc<[u8]>`), not borrowed. A `*const u8` from the
    /// caller would have to stay valid across every future `present()`, on a
    /// presenter that is `Send` and locked from more than one thread - a
    /// lifetime no safe API can promise, and a dangling read waiting to happen
    /// in the recovery path. Sharing the caller's decoded page cache costs one
    /// atomic reference count and keeps production callers `unsafe`-free.
    pub struct ResidentTexture {
        /// Caller's page id (the TPAG page id in the command backend).
        pub id: u32,
        /// GL texture name while this entry has a known-good GPU copy; 0 = none.
        pub texture: u32,
        /// The page's bytes, `width * height * 4` of them. Recovery re-uploads
        /// from here - never from a decode.
        pub bytes: Arc<[u8]>,
        pub width: u32,
        pub height: u32,
        /// The GPU copy holds `bytes` (the last upload reported no error).
        resident_on_gpu: bool,
    }

    impl ResidentTexture {
        /// A page with no GPU copy yet: the state a caller registers in. The
        /// extent/byte agreement is not checked here - `ResidentSet::register`
        /// owns that, so nothing can bypass the validation by building the value
        /// directly.
        pub fn new(id: u32, bytes: Arc<[u8]>, width: u32, height: u32) -> Self {
            Self {
                id,
                texture: 0,
                bytes,
                width,
                height,
                resident_on_gpu: false,
            }
        }
    }

    /// Why a registration was refused.
    #[derive(Clone, Copy, Debug, PartialEq, Eq)]
    pub enum ResidentError {
        /// Empty byte buffer.
        Empty,
        /// `width * height * 4` overflowed, or does not equal the byte count.
        ExtentMismatch,
        /// A dimension is zero or does not fit the GL `c_int` argument.
        ExtentTooLarge,
        /// The id is already registered: the page set has one owner.
        DuplicateId,
    }

    /// What one entry's GL upload attempt produced, as the accounting core sees
    /// it. Public so the failure / partial-success / retry matrix is testable
    /// without a GL context in the process.
    #[derive(Clone, Copy, Debug)]
    pub struct ResidentUploadResult {
        /// Index into `ResidentSet::entries()`.
        pub index: usize,
        /// GL error the upload reported; 0 means "nothing reported".
        pub error: u32,
        /// The GL name the entry should hold afterwards. 0 = no usable copy,
        /// whatever `error` says (`glGenTextures` failing returns 0 *without*
        /// setting an error, so an error-only test would call that a success).
        pub texture: u32,
    }

    /// The presenter's resident page-texture set.
    ///
    /// Default-empty, and an empty set is a strict no-op on every path:
    /// `needs_reupload()` stays false, so `present()` runs exactly the frame it
    /// ran before this slice and `reset_display()` only clears a set that was
    /// already empty. That is what keeps the shipped recovery behaviour
    /// bit-identical (regression: the javm64 loss legs stay 8/10 with
    /// first_ok=3 and a byte-equal post-loss frame).
    ///
    /// On a context loss the GL names die but the caller's bytes do not, so the
    /// set keeps its entries and only marks itself dirty: the next present that
    /// gets a live context re-uploads the whole set.
    #[derive(Default)]
    pub struct ResidentSet {
        entries: Vec<ResidentTexture>,
        /// GL names that were alive when their entry left the set. Deleting a
        /// name needs a current context on the calling thread, so they wait here
        /// rather than being forgotten (a forgotten name pins VRAM for the whole
        /// session), and are only dropped once the delete really ran.
        pending_deletes: Vec<u32>,
        uploaded_entries: u64,
        uploaded_bytes: u64,
        failed_entries: u64,
    }

    impl ResidentSet {
        /// Register one page texture. Extent and byte count are checked with
        /// `checked_mul` and against the GL `c_int` argument range, so a bad
        /// registration can never become an out-of-bounds driver read.
        pub fn register(&mut self, entry: ResidentTexture) -> Result<(), ResidentError> {
            if entry.bytes.is_empty() {
                return Err(ResidentError::Empty);
            }
            if entry.width == 0
                || entry.height == 0
                || entry.width > c_int::MAX as u32
                || entry.height > c_int::MAX as u32
            {
                return Err(ResidentError::ExtentTooLarge);
            }
            let expected = (entry.width as usize)
                .checked_mul(entry.height as usize)
                .and_then(|pixels| pixels.checked_mul(4))
                .ok_or(ResidentError::ExtentMismatch)?;
            if expected != entry.bytes.len() {
                return Err(ResidentError::ExtentMismatch);
            }
            if self.entries.iter().any(|e| e.id == entry.id) {
                return Err(ResidentError::DuplicateId);
            }
            self.entries.push(entry);
            Ok(())
        }

        /// Remove one entry. A live GL name is queued for deletion, never
        /// dropped: only a thread with a current context can delete it.
        pub fn unregister(&mut self, id: u32) -> bool {
            let Some(position) = self.entries.iter().position(|e| e.id == id) else {
                return false;
            };
            let entry = self.entries.remove(position);
            if entry.texture != 0 {
                self.pending_deletes.push(entry.texture);
            }
            true
        }

        pub fn clear(&mut self) {
            for entry in self.entries.drain(..) {
                if entry.texture != 0 {
                    self.pending_deletes.push(entry.texture);
                }
            }
        }

        pub fn len(&self) -> usize {
            self.entries.len()
        }

        pub fn is_empty(&self) -> bool {
            self.entries.is_empty()
        }

        pub fn entries(&self) -> &[ResidentTexture] {
            &self.entries
        }

        /// CPU bytes one recovery pass has to move for the whole set.
        pub fn bytes(&self) -> usize {
            self.entries.iter().map(|e| e.bytes.len()).sum()
        }

        /// True while any entry lacks a known-good GPU copy - what the recovery
        /// frame checks. An empty set is never dirty.
        pub fn needs_reupload(&self) -> bool {
            self.entries.iter().any(|e| !e.resident_on_gpu)
        }

        pub fn uploaded_totals(&self) -> (u64, u64) {
            (self.uploaded_entries, self.uploaded_bytes)
        }

        pub fn failed_total(&self) -> u64 {
            self.failed_entries
        }

        /// Resident work is part of the frame's dirty state, even if the
        /// software framebuffer bytes did not change.
        pub fn has_pending_maintenance(&self) -> bool {
            self.needs_reupload() || !self.pending_deletes.is_empty()
        }

        pub fn pending_delete_names(&self) -> &[u32] {
            &self.pending_deletes
        }

        /// Forget the first `n` queued names because their delete really ran.
        pub fn confirm_pending_deletes(&mut self, n: usize) {
            let n = n.min(self.pending_deletes.len());
            self.pending_deletes.drain(..n);
        }

        /// The context died, so every GL name in this set died with it - queued
        /// deletes included. The bytes stay: that RAM cache is the recovery
        /// source, which is the whole point of this slice.
        pub fn on_context_lost(&mut self) {
            self.pending_deletes.clear();
            for entry in &mut self.entries {
                entry.texture = 0;
                entry.resident_on_gpu = false;
            }
        }

        fn entry(&self, index: usize) -> Option<&ResidentTexture> {
            self.entries.get(index)
        }

        /// The accounting core of a re-upload pass: an entry counts as uploaded
        /// ONLY when its upload reported no error AND ended with a usable GL
        /// name; anything else keeps the entry dirty and zeroes its name, so the
        /// next frame retries it instead of a failure being papered over by a
        /// log line. Returns `(entries, bytes)` really uploaded.
        pub fn apply_upload_results(&mut self, results: &[ResidentUploadResult]) -> (usize, usize) {
            let mut entries = 0usize;
            let mut bytes = 0usize;
            let mut failed = 0usize;
            for result in results {
                let Some(entry) = self.entries.get_mut(result.index) else {
                    continue;
                };
                if result.error == 0 && result.texture != 0 {
                    entry.texture = result.texture;
                    entry.resident_on_gpu = true;
                    entries += 1;
                    bytes += entry.bytes.len();
                } else {
                    // Invalidate the copy, not our ownership of its GL name.
                    // A failed refresh still owns the old name; a failed create
                    // may have generated a new one before TexImage failed.
                    for name in [entry.texture, result.texture] {
                        if name != 0 && !self.pending_deletes.contains(&name) {
                            self.pending_deletes.push(name);
                        }
                    }
                    entry.texture = 0;
                    entry.resident_on_gpu = false;
                    failed += 1;
                }
            }
            self.uploaded_entries += entries as u64;
            self.uploaded_bytes += bytes as u64;
            self.failed_entries += failed as u64;
            (entries, bytes)
        }
    }

    pub struct Presenter {
        display: *mut c_void,
        context: *mut c_void,
        surface: *mut c_void,
        config: *mut c_void,
        window: *mut c_void,
        program: u32,
        texture: u32,
        vbo: u32,
        vao: u32,
        a_pos: c_int,
        a_uv: c_int,
        u_tex: c_int,
        texture_allocated: bool,
        surface_width: c_int,
        surface_height: c_int,
        init_failed_logged: bool,
        blit_miss_logged: bool,
        /// Bytes of the frame most recently handed to eglSwapBuffers; the
        /// unchanged-frame skip compares against this (empty before the first
        /// present).
        last_presented: Vec<u8>,
        /// Present unconditionally on the next call: set when a window is
        /// (re)attached, when the window surface is destroyed, and by
        /// `force_next_present` (host surface events). Only a successful
        /// present clears it.
        force_present: bool,
        /// Page textures the command backend keeps resident (contract slice 6).
        /// Empty by default: nothing about the presentation path below depends
        /// on a non-empty set.
        resident: ResidentSet,
        /// Rate-limits the "no current context on this thread" log: a recovery
        /// retry can hit it on every frame until a context comes back.
        resident_context_miss_logged: bool,
        /// Harness-only one-shot upload fault injection, so the failure/retry
        /// branch is exercised against the real driver too (see
        /// `upload_resident_entry`). Never compiled into the shipped `.so`.
        #[cfg(feature = "harness")]
        resident_upload_fault: Option<usize>,
    }

    // Only ever touched behind the mutex below; see the module comment.
    unsafe impl Send for Presenter {}

    impl Default for Presenter {
        fn default() -> Self {
            Self::new()
        }
    }

    impl Presenter {
        pub fn new() -> Self {
            Self {
                display: EGL_NO_DISPLAY,
                context: EGL_NO_CONTEXT,
                surface: EGL_NO_SURFACE,
                config: std::ptr::null_mut(),
                window: std::ptr::null_mut(),
                program: 0,
                texture: 0,
                vbo: 0,
                vao: 0,
                a_pos: -1,
                a_uv: -1,
                u_tex: -1,
                texture_allocated: false,
                surface_width: 0,
                surface_height: 0,
                init_failed_logged: false,
                blit_miss_logged: false,
                last_presented: Vec::new(),
                force_present: true,
                resident: ResidentSet::default(),
                resident_context_miss_logged: false,
                #[cfg(feature = "harness")]
                resident_upload_fault: None,
            }
        }

        /// Attach (or detach, with a null window) the native window. The
        /// previous ANativeWindow reference from ANativeWindow_fromSurface is
        /// released here: it is ours to drop, while EGL keeps its own
        /// reference for as long as the window surface exists.
        pub fn set_window(&mut self, window: *mut c_void) {
            if window == self.window {
                // The caller hands us a fresh ANativeWindow reference from
                // ANativeWindow_fromSurface even when it is the same window
                // (repeated surface events); drop that reference - we keep
                // holding the one stored here.
                if !window.is_null() {
                    unsafe { ANativeWindow_release(window) };
                }
                return;
            }
            log(&format!("set_window valid={}", !window.is_null()));
            unsafe {
                self.destroy_window_surface();
                if !self.window.is_null() {
                    ANativeWindow_release(self.window);
                }
            }
            self.window = window;
            self.force_present = true;
        }

        /// Request one unconditional present on the next call. The Java host
        /// sends this on every surface event (create/change): the current
        /// frame must be shown even when it did not change meanwhile.
        pub fn force_next_present(&mut self) {
            self.force_present = true;
        }

        // ---- resident page-texture set (contract slice 6) -------------------
        //
        // Shape only in this slice: the set is registered, survives a context
        // loss in RAM, and is re-uploaded on the recovery frame. Nothing draws
        // from it yet - the GPU command backend (slice 4) is what registers its
        // page textures here and samples them; until then the default set is
        // empty and every method below is inert.

        /// Register a page texture the caller keeps decoded in RAM. Ownership of
        /// the bytes is shared (`Arc<[u8]>`), so no borrow of caller memory ever
        /// outlives this call. Returns the reason for a refusal (empty bytes,
        /// duplicate id, extent/byte mismatch, extent that does not fit the GL
        /// `c_int` arguments).
        pub fn register_resident_texture(
            &mut self,
            id: u32,
            bytes: Arc<[u8]>,
            width: u32,
            height: u32,
        ) -> Result<(), ResidentError> {
            let len = bytes.len();
            let result = self.resident.register(ResidentTexture {
                id,
                texture: 0,
                bytes,
                width,
                height,
                resident_on_gpu: false,
            });
            match result {
                Ok(()) => log(&format!(
                    "resident register id={id} {width}x{height} bytes={len} set={} set_bytes={}",
                    self.resident.len(),
                    self.resident.bytes()
                )),
                Err(error) => log(&format!("resident register id={id} refused: {error:?}")),
            }
            result
        }

        pub fn unregister_resident_texture(&mut self, id: u32) -> bool {
            self.resident.unregister(id)
        }

        pub fn clear_resident_textures(&mut self) {
            self.resident.clear();
        }

        pub fn resident_texture_count(&self) -> usize {
            self.resident.len()
        }

        pub fn resident_texture_bytes(&self) -> usize {
            self.resident.bytes()
        }

        pub fn resident_needs_reupload(&self) -> bool {
            self.resident.needs_reupload()
        }

        /// `(entries, bytes)` uploaded by every re-upload pass so far - the
        /// evidence that a recovery frame really moved the resident set.
        pub fn resident_upload_totals(&self) -> (u64, u64) {
            self.resident.uploaded_totals()
        }

        pub fn resident_entries(&self) -> &[ResidentTexture] {
            self.resident.entries()
        }

        /// Uploads that reported a usable GL name, cumulatively, and the ones
        /// that did not - the evidence that a recovery pass really moved the set
        /// (and that retries happened instead of failures being swallowed).
        pub fn resident_failed_uploads(&self) -> u64 {
            self.resident.failed_total()
        }

        /// GL names queued by unregister/clear that have not been deleted yet,
        /// because no context was current on the calling thread.
        pub fn resident_pending_deletes(&self) -> usize {
            self.resident.pending_delete_names().len()
        }

        /// The BOOKKEEPING half of the re-upload gate: a non-empty set and EGL
        /// state that looks usable. It deliberately does NOT claim the calling
        /// thread has a current context - only the GL entry can check that, and
        /// `reupload_resident_set()` does, with `eglGetCurrentContext()` /
        /// `eglGetCurrentDisplay()` / `eglGetCurrentSurface()` against this
        /// presenter's handles, before a single GL call. Public and GL-free so
        /// the decision stays testable in a process without a context.
        pub fn resident_reupload_ready(&self) -> bool {
            !self.resident.is_empty() && self.egl_state_live()
        }

        /// The state `present()` maintains while a context is live. Necessarily
        /// weaker than the truth: another thread may own the context.
        fn egl_state_live(&self) -> bool {
            self.display != EGL_NO_DISPLAY
                && self.context != EGL_NO_CONTEXT
                && self.surface != EGL_NO_SURFACE
        }

        /// Whether THIS thread has this presenter's context - and its window
        /// surface - current right now. Asking the driver is the only answer
        /// that also covers "another thread owns the context"; guessing from
        /// state would issue GL calls into whatever the thread really has
        /// current (or none).
        unsafe fn context_is_current_here(&self) -> bool {
            self.egl_state_live()
                && eglGetCurrentContext() == self.context
                && eglGetCurrentDisplay() == self.display
                && eglGetCurrentSurface(EGL_DRAW) == self.surface
        }

        /// Delete the GL names that `unregister`/`clear` queued. They are never
        /// dropped, only queued, and only forgotten after the delete really ran
        /// on a thread with a current context - otherwise the name would pin
        /// VRAM for the session. `present()` calls this every frame; it is
        /// public for teardown paths outside a frame. Returns names deleted.
        pub fn flush_resident_deletes(&mut self) -> usize {
            if self.resident.pending_delete_names().is_empty() {
                return 0;
            }
            if !unsafe { self.context_is_current_here() } {
                // Not our thread / no context: keep them queued.
                return 0;
            }
            let names: Vec<u32> = self.resident.pending_delete_names().to_vec();
            unsafe {
                glDeleteTextures(names.len() as c_int, names.as_ptr());
                if glGetError() != 0 {
                    log(&format!(
                        "resident: glDeleteTextures of {} queued names reported an error; kept queued",
                        names.len()
                    ));
                    return 0;
                }
            }
            let deleted = names.len();
            self.resident.confirm_pending_deletes(deleted);
            log(&format!(
                "resident: deleted {deleted} GL texture(s) queued by unregister/clear"
            ));
            deleted
        }

        /// Re-upload the whole resident set into the live context: the recovery
        /// step of contract slice 6. Per entry, a dead name is rebuilt
        /// (`glTexImage2D`) and a live one refreshed in place
        /// (`glTexSubImage2D`) - upload-only, no decode.
        ///
        /// Returns `(entries, bytes)` REALLY uploaded this pass. `(0, 0)` when
        /// the set is empty, or when this thread does not have the context
        /// current - in which case not a single GL call is made and the set
        /// stays dirty for the next frame. Entries whose upload failed are not
        /// counted and keep their dirty flag, so the next frame retries them
        /// instead of the loss being logged as success.
        pub fn reupload_resident_set(&mut self) -> (usize, usize) {
            if !self.resident_reupload_ready() {
                return (0, 0);
            }
            if !unsafe { self.context_is_current_here() } {
                if !self.resident_context_miss_logged {
                    log(&format!(
                        "resident reupload: {} entries deferred - this thread has no current context (nothing touched)",
                        self.resident.len()
                    ));
                    self.resident_context_miss_logged = true;
                }
                return (0, 0);
            }
            self.resident_context_miss_logged = false;
            let mut results = Vec::with_capacity(self.resident.len());
            for index in 0..self.resident.len() {
                let existing = self.resident.entry(index).map(|e| e.texture).unwrap_or(0);
                let (error, texture) = self.upload_resident_entry(index, existing);
                results.push(ResidentUploadResult {
                    index,
                    error,
                    texture,
                });
            }
            unsafe {
                // Leave unit 0 unbound: the frame upload below owns it next.
                glBindTexture(GL_TEXTURE_2D, 0);
            }
            let (entries, bytes) = self.resident.apply_upload_results(&results);
            let still_dirty = self
                .resident
                .entries()
                .iter()
                .filter(|entry| !entry.resident_on_gpu)
                .count();
            log(&format!(
                "resident reupload: {entries}/{} textures, {bytes} bytes (upload-only from owned RAM), still_dirty={still_dirty}",
                self.resident.len()
            ));
            (entries, bytes)
        }

        /// Uploads entry `index` into the current context. Returns the GL error
        /// (0 = none reported) and the name the entry should hold afterwards.
        /// A `glGenTextures` that returns 0 is a FAILURE even though it sets no
        /// error. A failed rebuild returns any generated name so the owning
        /// ResidentSet can defer deletion without losing its ownership.
        fn upload_resident_entry(&mut self, index: usize, existing: u32) -> (u32, u32) {
            let (bytes, width, height) = match self.resident.entry(index) {
                Some(entry) => (Arc::clone(&entry.bytes), entry.width, entry.height),
                None => return (0, 0),
            };
            #[cfg(feature = "harness")]
            if self.resident_upload_fault == Some(index) {
                // Harness-only, one-shot: exercises the real failure/retry branch
                // against the driver (the unit tests cover the accounting; this
                // covers the branch that talks to the GPU).
                self.resident_upload_fault = None;
                log(&format!(
                    "resident harness fault: upload of entry {index} forced to fail once"
                ));
                return (0x0505 /* GL_OUT_OF_MEMORY */, existing);
            }
            unsafe {
                if existing == 0 {
                    let mut tex = [0u32; 1];
                    glGenTextures(1, tex.as_mut_ptr());
                    if tex[0] == 0 {
                        // No name and no error: still a failure.
                        return (0, 0);
                    }
                    glBindTexture(GL_TEXTURE_2D, tex[0]);
                    // The frame texture's sampling contract, per page: pixel art
                    // is never smoothed and pages are never wrapped.
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                    glTexImage2D(
                        GL_TEXTURE_2D,
                        0,
                        GL_RGBA as c_int,
                        width as c_int,
                        height as c_int,
                        0,
                        GL_RGBA,
                        GL_UNSIGNED_BYTE,
                        bytes.as_ptr() as *const c_void,
                    );
                    let error = glGetError();
                    if error != 0 {
                        // Account for this name even though its upload failed.
                        // The context-owned queue deletes it on the next flush.
                        return (error, tex[0]);
                    }
                    (0, tex[0])
                } else {
                    glBindTexture(GL_TEXTURE_2D, existing);
                    glTexSubImage2D(
                        GL_TEXTURE_2D,
                        0,
                        0,
                        0,
                        width as c_int,
                        height as c_int,
                        GL_RGBA,
                        GL_UNSIGNED_BYTE,
                        bytes.as_ptr() as *const c_void,
                    );
                    let error = glGetError();
                    // The name remains owned even when the refresh fails;
                    // apply_upload_results queues it before invalidating it.
                    (error, existing)
                }
            }
        }

        pub fn release(&mut self) {
            self.set_window(std::ptr::null_mut());
            unsafe { self.reset_display() };
        }

        /// Drop the entire EGL display state (surface -> context -> terminate,
        /// in that order) and every GL handle that died with the context. The
        /// order is load-bearing: the javm64 loss probe on this device's Mali
        /// driver SIGKILLed the process when eglInitialize ran while a live
        /// surface/context still referenced the terminated display. Re-initing
        /// AFTER a full release was proven to rebuild byte-equal frames.
        /// Unlike `release` this keeps the window attached: the next present
        /// re-runs init_egl against it.
        unsafe fn reset_display(&mut self) {
            self.destroy_window_surface();
            if self.display != EGL_NO_DISPLAY {
                eglMakeCurrent(self.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
                if self.context != EGL_NO_CONTEXT {
                    eglDestroyContext(self.display, self.context);
                }
                eglTerminate(self.display);
            }
            self.display = EGL_NO_DISPLAY;
            self.context = EGL_NO_CONTEXT;
            self.config = std::ptr::null_mut();
            // Every GL object died with the context; the rebuild gates must
            // reopen or the next frame would reuse stale ids into a dead
            // context (black screen instead of a recovery).
            self.program = 0;
            self.texture = 0;
            self.vbo = 0;
            self.vao = 0;
            self.a_pos = -1;
            self.a_uv = -1;
            self.u_tex = -1;
            self.texture_allocated = false;
            self.init_failed_logged = false;
            // The framebuffer behind last_presented no longer exists on the
            // GPU: the next present must repaint even on an unchanged frame.
            self.force_present = true;
            // Contract slice 6: the page textures the command backend keeps
            // resident died with this context too - queued deletes included, so
            // they are dropped rather than deleted later into a fresh context.
            // The bytes stay: that RAM cache IS the recovery source. With an
            // empty set this is a no-op, which is why the shipped recovery path
            // is unchanged.
            //
            // TODO(slice 4/6): the GPU command backend registers its page
            // textures here (TPAG page id -> decoded page bytes) and draws from
            // the same ids. Until that lands, the set only holds what a caller
            // (the headless harness) registers, and nothing samples it.
            self.resident.on_context_lost();
        }

        /// Upload one BGRA frame and swap, unless it is byte-identical to the
        /// last presented frame - then nothing is uploaded, drawn or swapped
        /// and the swap chain still shows the same picture. Returns true when
        /// a frame was presented.
        pub fn present(&mut self, pixels: &[u8], width: u32, height: u32) -> bool {
            if self.window.is_null() {
                if !self.blit_miss_logged {
                    log("present skip: no window");
                    self.blit_miss_logged = true;
                }
                return false;
            }
            self.blit_miss_logged = false;
            // Unchanged frame: skip the whole present. Only a successful
            // present clears `force_present`, so a rebuilt surface or a host
            // surface event can never be eaten by this check.
            if !self.force_present
                && !self.resident.has_pending_maintenance()
                && self.last_presented.len() == pixels.len()
                && self.last_presented.as_slice() == pixels
            {
                return false;
            }
            unsafe {
                if self.display == EGL_NO_DISPLAY && !self.init_egl() {
                    return false;
                }
                if self.surface == EGL_NO_SURFACE && !self.create_window_surface() {
                    return false;
                }
                if self.program == 0 && !self.create_program() {
                    return false;
                }
                if !self.ensure_texture() {
                    return false;
                }
                if self.surface_width <= 0 || self.surface_height <= 0 {
                    return false;
                }
                // Contract slice 6, two things that need a live context on THIS
                // thread: names queued by unregister/clear are deleted here, and
                // the recovery frame puts the resident page set back on the GPU
                // - upload-only, from the owned bytes. With an empty set both are
                // no-ops, so the default frame below is untouched.
                self.flush_resident_deletes();
                if self.resident.needs_reupload() {
                    self.reupload_resident_set();
                }
                glViewport(0, 0, self.surface_width, self.surface_height);
                glClearColor(0.0, 0.0, 0.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);
                glUseProgram(self.program);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, self.texture);
                glTexSubImage2D(
                    GL_TEXTURE_2D,
                    0,
                    0,
                    0,
                    width as c_int,
                    height as c_int,
                    GL_RGBA,
                    GL_UNSIGNED_BYTE,
                    pixels.as_ptr() as *const c_void,
                );
                glUniform1i(self.u_tex, 0);
                glBindVertexArray(self.vao);
                glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                glBindVertexArray(0);
                if eglSwapBuffers(self.display, self.surface) == 0 {
                    // The window went away or resized under us: drop the surface
                    // and let the next frame rebuild it.
                    self.destroy_window_surface();
                    return false;
                }
            }
            if self.last_presented.len() != pixels.len() {
                self.last_presented.resize(pixels.len(), 0);
            }
            self.last_presented.copy_from_slice(pixels);
            self.force_present = false;
            true
        }

        unsafe fn init_egl(&mut self) -> bool {
            self.display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
            if self.display == EGL_NO_DISPLAY {
                return self.fail("eglGetDisplay failed");
            }
            let mut major: c_int = 0;
            let mut minor: c_int = 0;
            if eglInitialize(self.display, &mut major, &mut minor) == 0 {
                return self.fail("eglInitialize failed");
            }
            let attribs = [
                EGL_RENDERABLE_TYPE,
                EGL_OPENGL_ES3_BIT,
                EGL_RED_SIZE,
                8,
                EGL_GREEN_SIZE,
                8,
                EGL_BLUE_SIZE,
                8,
                EGL_ALPHA_SIZE,
                8,
                EGL_SURFACE_TYPE,
                EGL_WINDOW_BIT,
                EGL_NONE,
            ];
            let mut config: *mut c_void = std::ptr::null_mut();
            let mut num: c_int = 0;
            if eglChooseConfig(self.display, attribs.as_ptr(), &mut config, 1, &mut num) == 0
                || num == 0
            {
                return self.fail("no ES3 window config");
            }
            self.config = config;
            let context_attribs = [EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE];
            self.context = eglCreateContext(self.display, self.config, EGL_NO_CONTEXT, context_attribs.as_ptr());
            if self.context == EGL_NO_CONTEXT {
                return self.fail("eglCreateContext(ES3) failed");
            }
            if !self.create_window_surface() {
                return false;
            }
            let version = glGetString(0x1F02); // GL_VERSION
            let vendor = eglQueryString(self.display, EGL_VENDOR) as *const u8;
            log(&format!(
                "GLES3 presenter up: EGL {}.{}, GL_VERSION={}, EGL_VENDOR={}",
                major,
                minor,
                cstr(version),
                cstr(vendor)
            ));
            true
        }

        unsafe fn create_window_surface(&mut self) -> bool {
            let attribs = [EGL_NONE];
            self.surface = eglCreateWindowSurface(self.display, self.config, self.window, attribs.as_ptr());
            if self.surface == EGL_NO_SURFACE {
                let err = eglGetError();
                if err == EGL_NOT_INITIALIZED {
                    // The display died under us (driver reset / context loss).
                    // A dead display never yields a surface again - the javm64
                    // loss probe saw every retry fail 0x3001 forever - so drop
                    // the whole display state here; the next frame re-runs
                    // init_egl, which the same probe proved rebuilds
                    // byte-equal output on this device's Mali driver.
                    log(&format!("eglCreateWindowSurface: display dead (0x{err:x}); resetting"));
                    self.reset_display();
                    return false;
                }
                return self.fail_at("eglCreateWindowSurface failed", err);
            }
            if eglMakeCurrent(self.display, self.surface, self.surface, self.context) == 0 {
                let err = eglGetError();
                eglDestroySurface(self.display, self.surface);
                self.surface = EGL_NO_SURFACE;
                if err == EGL_NOT_INITIALIZED {
                    log(&format!("eglMakeCurrent: display dead (0x{err:x}); resetting"));
                    self.reset_display();
                    return false;
                }
                return self.fail_at("eglMakeCurrent failed", err);
            }
            let mut dim: c_int = 0;
            eglQuerySurface(self.display, self.surface, EGL_WIDTH, &mut dim);
            self.surface_width = dim;
            eglQuerySurface(self.display, self.surface, EGL_HEIGHT, &mut dim);
            self.surface_height = dim;
            true
        }

        unsafe fn destroy_window_surface(&mut self) {
            if self.display != EGL_NO_DISPLAY && self.surface != EGL_NO_SURFACE {
                eglMakeCurrent(self.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
                eglDestroySurface(self.display, self.surface);
            }
            self.surface = EGL_NO_SURFACE;
            self.surface_width = 0;
            self.surface_height = 0;
            // The next present must repaint even if the framebuffer has not
            // changed: the surface (or its EGL state) just went away.
            self.force_present = true;
        }

        unsafe fn create_program(&mut self) -> bool {
            let vs = self.compile_shader(GL_VERTEX_SHADER, VERTEX_SHADER);
            let fs = self.compile_shader(GL_FRAGMENT_SHADER, FRAGMENT_SHADER);
            if vs == 0 || fs == 0 {
                return false;
            }
            let program = glCreateProgram();
            glAttachShader(program, vs);
            glAttachShader(program, fs);
            glLinkProgram(program);
            let mut status: c_int = 0;
            glGetProgramiv(program, GL_LINK_STATUS, &mut status);
            glDeleteShader(vs);
            glDeleteShader(fs);
            if status == 0 {
                let mut buf = [0i8; 512];
                glGetProgramInfoLog(program, 512, std::ptr::null_mut(), buf.as_mut_ptr() as *mut c_char);
                log(&format!("program link failed: {}", cstr(buf.as_ptr() as *const u8)));
                glDeleteProgram(program);
                return false;
            }
            self.program = program;
            self.a_pos = glGetAttribLocation(program, b"aPos\0".as_ptr() as *const c_char);
            self.a_uv = glGetAttribLocation(program, b"aUv\0".as_ptr() as *const c_char);
            self.u_tex = glGetUniformLocation(program, b"uTex\0".as_ptr() as *const c_char);
            let mut bufs = [0u32; 2];
            glGenBuffers(1, bufs.as_mut_ptr());
            self.vbo = bufs[0];
            glGenVertexArrays(1, bufs.as_mut_ptr());
            self.vao = bufs[0];
            glBindVertexArray(self.vao);
            glBindBuffer(GL_ARRAY_BUFFER, self.vbo);
            glBufferData(
                GL_ARRAY_BUFFER,
                std::mem::size_of_val(&QUAD) as isize,
                QUAD.as_ptr() as *const c_void,
                GL_STATIC_DRAW,
            );
            glEnableVertexAttribArray(self.a_pos as u32);
            glVertexAttribPointer(self.a_pos as u32, 2, GL_FLOAT, 0, 16, std::ptr::null());
            glEnableVertexAttribArray(self.a_uv as u32);
            glVertexAttribPointer(self.a_uv as u32, 2, GL_FLOAT, 0, 16, 8 as *const c_void);
            glBindVertexArray(0);
            true
        }

        unsafe fn compile_shader(&mut self, ty: u32, source: &str) -> u32 {
            let shader = glCreateShader(ty);
            let c = std::ffi::CString::new(source).unwrap_or_default();
            let ptr = c.as_ptr();
            glShaderSource(shader, 1, &ptr, std::ptr::null());
            glCompileShader(shader);
            let mut status: c_int = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &mut status);
            if status == 0 {
                let mut buf = [0i8; 512];
                glGetShaderInfoLog(shader, 512, std::ptr::null_mut(), buf.as_mut_ptr() as *mut c_char);
                log(&format!("shader compile failed: {}", cstr(buf.as_ptr() as *const u8)));
                glDeleteShader(shader);
                return 0;
            }
            shader
        }

        unsafe fn ensure_texture(&mut self) -> bool {
            if self.texture_allocated {
                return true;
            }
            let mut tex = [0u32; 1];
            glGenTextures(1, tex.as_mut_ptr());
            self.texture = tex[0];
            glBindTexture(GL_TEXTURE_2D, self.texture);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGBA as c_int,
                CANVAS_W as c_int,
                CANVAS_H as c_int,
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                std::ptr::null(),
            );
            self.texture_allocated = true;
            true
        }

        fn fail(&mut self, message: &str) -> bool {
            let err = unsafe { eglGetError() };
            self.fail_at(message, err)
        }

        fn fail_at(&mut self, message: &str, err: c_int) -> bool {
            if !self.init_failed_logged {
                log(&format!("{message} (EGL error 0x{err:x})"));
                self.init_failed_logged = true;
            }
            false
        }
    }

    /// Engine canvas the texture is sized for.
    pub const CANVAS_W: u32 = 1136;
    pub const CANVAS_H: u32 = 640;

    unsafe fn cstr(ptr: *const u8) -> String {
        if ptr.is_null() {
            return "(null)".to_string();
        }
        let mut len = 0usize;
        while *ptr.add(len) != 0 && len < 256 {
            len += 1;
        }
        let slice = std::slice::from_raw_parts(ptr, len);
        String::from_utf8_lossy(slice).into_owned()
    }

    extern "C" {
        fn eglTerminate(dpy: *mut c_void) -> u32;
        fn eglDestroyContext(dpy: *mut c_void, ctx: *mut c_void) -> u32;
        // The only trustworthy answer to "does THIS thread own the context":
        // `reupload_resident_set` asks before it touches any GL state.
        fn eglGetCurrentContext() -> *mut c_void;
        fn eglGetCurrentDisplay() -> *mut c_void;
        fn eglGetCurrentSurface(readdraw: c_int) -> *mut c_void;
    }

    /// The process-wide presenter, behind one mutex (see the module comment).
    pub fn presenter() -> &'static Mutex<Presenter> {
        static SLOT: OnceLock<Mutex<Presenter>> = OnceLock::new();
        SLOT.get_or_init(|| Mutex::new(Presenter::new()))
    }

    /// Turn a Java Surface into an EGL window. Returns the native window the
    /// caller must hand to `set_window` (and which the presenter releases).
    pub fn window_from_surface(env: *mut c_void, surface: *mut c_void) -> *mut c_void {
        if surface.is_null() {
            return std::ptr::null_mut();
        }
        unsafe { ANativeWindow_fromSurface(env, surface) }
    }

    /// Headless-harness bridge for the resident-set recovery measurement
    /// (contract slice 6). Compiled only with `--features android,harness`, so
    /// the shipped APK keeps exactly the production JNI surface: these entry
    /// points exist for `~/cally-work/gmbench/Recspike64.java`, the javm64 shell
    /// that injects an EGL loss and A/Bs "empty set (status quo)" against "N
    /// registered page textures" through the REAL recovery path. Reimplementing
    /// the re-upload in Java would measure the harness instead of the presenter.
    ///
    /// The harness class is not in `android-build/` on purpose (the host's Java
    /// sources are not this slice's to edit): a native's JNI symbol is bound to
    /// its DECLARING class, so the harness declares these natives in its own
    /// class and this module exports the matching names.
    #[cfg(all(target_os = "android", feature = "android", feature = "harness"))]
    mod harness_bridge {
        use super::*;

        const JNI_TRUE: u8 = 1;
        const JNI_FALSE: u8 = 0;

        extern "C" {
            // FBO readback, used only by the content checksum below.
            fn glGenFramebuffers(n: c_int, framebuffers: *mut u32);
            fn glBindFramebuffer(target: u32, framebuffer: u32);
            fn glFramebufferTexture2D(
                target: u32,
                attachment: u32,
                textarget: u32,
                texture: u32,
                level: c_int,
            );
            fn glCheckFramebufferStatus(target: u32) -> u32;
            fn glReadPixels(
                x: c_int,
                y: c_int,
                width: c_int,
                height: c_int,
                format: u32,
                ty: u32,
                pixels: *mut c_void,
            );
            fn glDeleteFramebuffers(n: c_int, framebuffers: *const u32);
        }

        const GL_FRAMEBUFFER: u32 = 0x8D40;
        const GL_COLOR_ATTACHMENT0: u32 = 0x8CE0;
        const GL_FRAMEBUFFER_COMPLETE: u32 = 0x8CD5;

        fn with_presenter<R>(f: impl FnOnce(&mut Presenter) -> R) -> Option<R> {
            let mut guard = match presenter().lock() {
                Ok(guard) => guard,
                Err(poisoned) => poisoned.into_inner(),
            };
            Some(f(&mut guard))
        }

        /// Bridge diagnostics: logcat is flooded on this device, so the harness
        /// needs its evidence on the process' stdout (the run log) as well.
        fn note(message: &str) {
            log(message);
            println!("[recspike-bridge] {message}");
            use std::io::Write;
            let _ = std::io::stdout().flush();
        }

        /// FNV-1a over the GPU-side bytes of a resident texture, or -1 when the
        /// texture is not readable (no GL copy, FBO not renderable). Proves the
        /// re-upload put the caller's bytes BACK on the GPU, not just that some
        /// upload call happened.
        fn gpu_checksum(texture: u32, width: u32, height: u32) -> i64 {
            if texture == 0 || width == 0 || height == 0 {
                return -1;
            }
            unsafe {
                let mut fbo = [0u32; 1];
                glGenFramebuffers(1, fbo.as_mut_ptr());
                glBindFramebuffer(GL_FRAMEBUFFER, fbo[0]);
                glFramebufferTexture2D(
                    GL_FRAMEBUFFER,
                    GL_COLOR_ATTACHMENT0,
                    GL_TEXTURE_2D,
                    texture,
                    0,
                );
                if glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE {
                    glBindFramebuffer(GL_FRAMEBUFFER, 0);
                    glDeleteFramebuffers(1, fbo.as_ptr());
                    return -1;
                }
                let len = (width as usize) * (height as usize) * 4;
                let mut pixels = vec![0u8; len];
                glReadPixels(
                    0,
                    0,
                    width as c_int,
                    height as c_int,
                    GL_RGBA,
                    GL_UNSIGNED_BYTE,
                    pixels.as_mut_ptr() as *mut c_void,
                );
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
                glDeleteFramebuffers(1, fbo.as_ptr());
                let mut hash: u64 = 0xcbf2_9ce4_8422_2325; // FNV-1a 64 offset basis
                for byte in &pixels {
                    hash ^= *byte as u64;
                    hash = hash.wrapping_mul(0x0000_0100_0000_01b3); // FNV-1a 64 prime
                }
                hash as i64
            }
        }

        /// Hard ceiling for one harness-registered page: a typo in the length
        /// argument must not turn into a multi-gigabyte copy.
        const MAX_HARNESS_PAGE_BYTES: i64 = 512 * 1024 * 1024;

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentRegister(
            _env: *mut c_void,
            _class: *mut c_void,
            id: c_int,
            addr: i64,
            len: c_int,
            width: c_int,
            height: c_int,
        ) -> u8 {
            // `addr` is an Android native address: those live at 0xb4000000_00000000
            // and above, so as a SIGNED i64 they are NEGATIVE. An `addr <= 0`
            // guard therefore rejects every real pointer (an earlier revision did
            // exactly that, and both A/B legs silently measured the empty set).
            // Only a null address is invalid.
            if addr == 0
                || len <= 0
                || width <= 0
                || height <= 0
                || (len as i64) > MAX_HARNESS_PAGE_BYTES
            {
                note(&format!(
                    "register REJECTED at the bridge id={id} addr=0x{addr:x} len={len} {width}x{height} (bad argument)"
                ));
                return JNI_FALSE;
            }
            // The ONE unsafe read in this bridge: the harness (Recspike64) hands
            // over a native buffer it allocated with Unsafe.allocateMemory and
            // keeps for the whole run. Copying it into an owned `Arc<[u8]>` here
            // is what keeps the production API safe - no borrow of harness memory
            // survives into a later present() - and it happens outside the
            // measured recovery window.
            let owned: Arc<[u8]> =
                unsafe { std::slice::from_raw_parts(addr as usize as *const u8, len as usize) }.into();
            let result = with_presenter(|p| {
                p.register_resident_texture(id as u32, owned, width as u32, height as u32)
            });
            let accepted = matches!(result, Some(Ok(())));
            note(&format!(
                "bridge register id={id} addr=0x{addr:x} len={len} {width}x{height} accepted={accepted}"
            ));
            if accepted {
                JNI_TRUE
            } else {
                JNI_FALSE
            }
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentUnregister(
            _env: *mut c_void,
            _class: *mut c_void,
            id: c_int,
        ) -> u8 {
            let removed =
                with_presenter(|p| p.unregister_resident_texture(id as u32)).unwrap_or(false);
            if removed {
                JNI_TRUE
            } else {
                JNI_FALSE
            }
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentClear(
            _env: *mut c_void,
            _class: *mut c_void,
        ) {
            let _ = with_presenter(|p| p.clear_resident_textures());
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentCount(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> c_int {
            with_presenter(|p| p.resident_texture_count() as c_int).unwrap_or(0)
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentBytes(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> i64 {
            with_presenter(|p| p.resident_texture_bytes() as i64).unwrap_or(0)
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentNeedsReupload(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> u8 {
            let dirty = with_presenter(|p| p.resident_needs_reupload()).unwrap_or(false);
            if dirty {
                JNI_TRUE
            } else {
                JNI_FALSE
            }
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentReupload(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> c_int {
            with_presenter(|p| p.reupload_resident_set().0 as c_int).unwrap_or(0)
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentUploadedEntries(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> i64 {
            with_presenter(|p| p.resident_upload_totals().0 as i64).unwrap_or(0)
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentUploadedBytes(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> i64 {
            with_presenter(|p| p.resident_upload_totals().1 as i64).unwrap_or(0)
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentChecksum(
            _env: *mut c_void,
            _class: *mut c_void,
            id: c_int,
        ) -> i64 {
            with_presenter(|p| {
                p.resident_entries()
                    .iter()
                    .find(|e| e.id == id as u32)
                    .map(|e| gpu_checksum(e.texture, e.width, e.height))
                    .unwrap_or(-1)
            })
            .unwrap_or(-1)
        }

        /// Failed upload attempts, cumulatively: a non-zero value next to a
        /// restored checksum is the on-device proof that a failure was retried
        /// rather than counted as success.
        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentFailedUploads(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> i64 {
            with_presenter(|p| p.resident_failed_uploads() as i64).unwrap_or(0)
        }

        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentPendingDeletes(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> c_int {
            with_presenter(|p| p.resident_pending_deletes() as c_int).unwrap_or(0)
        }

        /// The bookkeeping half of the re-upload gate (no GL call).
        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentReuploadReady(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> u8 {
            let ready = with_presenter(|p| p.resident_reupload_ready()).unwrap_or(false);
            if ready {
                JNI_TRUE
            } else {
                JNI_FALSE
            }
        }

        /// Whether the presenting thread really has the presenter's context
        /// current (the GL entry's own check, exposed so the harness can show it
        /// flips to 0 when the display is terminated).
        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentContextCurrent(
            _env: *mut c_void,
            _class: *mut c_void,
        ) -> u8 {
            let current = with_presenter(|p| unsafe { p.context_is_current_here() }).unwrap_or(false);
            if current {
                JNI_TRUE
            } else {
                JNI_FALSE
            }
        }

        /// Harness-only, one-shot: make the next upload of `index` fail, so the
        /// failure -> dirty -> retry path is exercised against the real driver.
        #[no_mangle]
        pub extern "C" fn Java_com_gongmi_callyscaves2_Recspike64_nativeResidentInjectUploadFault(
            _env: *mut c_void,
            _class: *mut c_void,
            index: c_int,
        ) {
            let _ = with_presenter(|p| {
                if index >= 0 {
                    p.resident_upload_fault = Some(index as usize);
                } else {
                    p.resident_upload_fault = None;
                }
            });
        }
    }
}
