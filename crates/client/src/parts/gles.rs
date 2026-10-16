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
    use std::sync::{Mutex, OnceLock};

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

    /// One page texture the command backend keeps decoded in RAM and wants back
    /// on the GPU after an EGL context loss (contract slice 6).
    ///
    /// `source`/`len` are the CALLER's bytes - the resident RAM cache the atlas
    /// loader already holds. The set never copies, re-reads, decodes or frees
    /// them: recovery is "upload what is already in RAM" by construction, which
    /// is the whole point (WL15 measured upload-only 8.7-19 ms against
    /// decode+upload 127-298 ms for the same resident pages).
    #[derive(Clone, Copy, Debug)]
    pub struct ResidentTexture {
        /// Caller's page id (the TPAG page id in the command backend).
        pub id: u32,
        /// GL texture name this id lives at while the context is alive; 0 means
        /// "no GPU copy yet" (a registration, or a context that just died).
        pub texture: u32,
        /// Decoded BGRA/RGBA bytes to upload; owned by the caller, not by us.
        pub source: *const u8,
        pub len: usize,
        pub width: u32,
        pub height: u32,
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
        needs_reupload: bool,
        uploaded_entries: u64,
        uploaded_bytes: u64,
    }

    impl ResidentSet {
        /// Register one page texture. Rejected (false) when the bytes or the
        /// extent are unusable, or when the id is already registered - the page
        /// set has one owner, so a silent replace would hide a bookkeeping bug.
        pub fn register(&mut self, entry: ResidentTexture) -> bool {
            if entry.source.is_null()
                || entry.len == 0
                || entry.width == 0
                || entry.height == 0
            {
                return false;
            }
            // Full-page uploads only for now: the byte count must cover exactly
            // the registered extent, or the driver would read past the caller's
            // buffer. Region/bbox uploads (WL15's packed-bbox variant) need an
            // extent AND an offset and belong to the command backend slice.
            if entry.len != (entry.width as usize) * (entry.height as usize) * 4 {
                return false;
            }
            if self.entries.iter().any(|e| e.id == entry.id) {
                return false;
            }
            self.entries.push(entry);
            // A fresh entry has no GPU copy, so the next present must upload it.
            self.needs_reupload = true;
            true
        }

        pub fn unregister(&mut self, id: u32) -> bool {
            let before = self.entries.len();
            self.entries.retain(|e| e.id != id);
            before != self.entries.len()
        }

        pub fn clear(&mut self) {
            self.entries.clear();
            self.needs_reupload = false;
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

        /// CPU bytes the recovery path has to move for this set.
        pub fn bytes(&self) -> usize {
            self.entries.iter().map(|e| e.len).sum()
        }

        pub fn needs_reupload(&self) -> bool {
            self.needs_reupload
        }

        pub fn uploaded_totals(&self) -> (u64, u64) {
            (self.uploaded_entries, self.uploaded_bytes)
        }

        fn entry_mut(&mut self, index: usize) -> Option<&mut ResidentTexture> {
            self.entries.get_mut(index)
        }

        /// The context died: every GL name in this set is stale. The bytes are
        /// the caller's and survive, so the recovery frame re-uploads them from
        /// RAM instead of going back to decode.
        pub fn on_context_lost(&mut self) {
            if self.entries.is_empty() {
                return;
            }
            for entry in &mut self.entries {
                entry.texture = 0;
            }
            self.needs_reupload = true;
        }

        fn note_uploaded(&mut self, entries: usize, bytes: usize) {
            self.needs_reupload = false;
            self.uploaded_entries += entries as u64;
            self.uploaded_bytes += bytes as u64;
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

        /// Register a page texture the caller keeps decoded in RAM. `source`
        /// must stay valid (and unchanged) until it is unregistered: the set
        /// uploads the caller's bytes, it does not own them. Returns false for
        /// unusable input, a duplicate id, or a byte count that does not match
        /// `width * height * 4` (full-page uploads only - see `ResidentSet`).
        pub fn register_resident_texture(
            &mut self,
            id: u32,
            source: *const u8,
            len: usize,
            width: u32,
            height: u32,
        ) -> bool {
            let accepted = self.resident.register(ResidentTexture {
                id,
                texture: 0,
                source,
                len,
                width,
                height,
            });
            if accepted {
                log(&format!(
                    "resident register id={id} {width}x{height} bytes={len} set={} set_bytes={}",
                    self.resident.len(),
                    self.resident.bytes()
                ));
            }
            accepted
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

        /// Whether a resident re-upload may run right now: a non-empty set plus
        /// the same two gates `present()` establishes before it reaches the
        /// hook (display and window surface alive, so a context is current).
        /// Split out from `reupload_resident_set` so the DECISION is testable in
        /// a process with no GL context - the GL work itself is measured on the
        /// device by the javm64 harness.
        pub fn resident_reupload_ready(&self) -> bool {
            !self.resident.is_empty()
                && self.display != EGL_NO_DISPLAY
                && self.surface != EGL_NO_SURFACE
        }

        /// Upload the whole resident set into the live context: the recovery
        /// step of contract slice 6. Entries whose GL name died get a fresh
        /// texture (glTexImage2D), the rest are refreshed in place
        /// (glTexSubImage2D) - upload-only, no decode.
        ///
        /// Returns `(entries, bytes)`; `(0, 0)` when the set is empty or no
        /// surface/context is current, so a caller that cannot know whether a
        /// context exists can call it unconditionally. A blocked call leaves the
        /// set dirty, so the next frame with a live context retries.
        pub fn reupload_resident_set(&mut self) -> (usize, usize) {
            if !self.resident_reupload_ready() {
                return (0, 0);
            }
            let mut entries = 0usize;
            let mut bytes = 0usize;
            let mut first_error = 0u32;
            unsafe {
                for index in 0..self.resident.len() {
                    let (source, len, width, height, existing) = {
                        let entry = &self.resident.entries()[index];
                        (
                            entry.source,
                            entry.len,
                            entry.width,
                            entry.height,
                            entry.texture,
                        )
                    };
                    if existing == 0 {
                        let mut tex = [0u32; 1];
                        glGenTextures(1, tex.as_mut_ptr());
                        glBindTexture(GL_TEXTURE_2D, tex[0]);
                        // The frame texture's sampling contract, per page: pixel
                        // art is never smoothed and pages are never wrapped.
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
                            source as *const c_void,
                        );
                        if let Some(entry) = self.resident.entry_mut(index) {
                            entry.texture = tex[0];
                        }
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
                            source as *const c_void,
                        );
                    }
                    let err = glGetError();
                    if err != 0 && first_error == 0 {
                        first_error = err;
                    }
                    entries += 1;
                    bytes += len;
                }
                // Leave unit 0 unbound: the frame upload below owns it next.
                glBindTexture(GL_TEXTURE_2D, 0);
            }
            self.resident.note_uploaded(entries, bytes);
            log(&format!(
                "resident reupload: {entries} textures, {bytes} bytes (upload-only from caller RAM){}",
                if first_error != 0 {
                    format!(" first_driver_error=0x{first_error:x}")
                } else {
                    String::new()
                }
            ));
            (entries, bytes)
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
            // resident died with this context too. Keep the registered byte
            // sources - the RAM cache IS the recovery source - and mark the set
            // dirty, so the recovery frame re-uploads instead of re-decoding.
            // With an empty set this is a no-op, which is why the shipped
            // recovery path is unchanged.
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
                // Contract slice 6: the recovery frame is the one that holds a
                // fresh context after a loss, so it is also the frame that has
                // to put the resident page set back on the GPU - upload-only,
                // from the caller's RAM bytes. The flag is false whenever the
                // set is empty, so the default frame below is untouched.
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
            // and above, so as a SIGNED i64 they are NEGATIVE. The old `addr <= 0`
            // guard therefore rejected every real pointer (both A/B legs silently
            // measured the empty set). Only a null address is invalid.
            if addr == 0 || len <= 0 || width <= 0 || height <= 0 {
                note(&format!(
                    "register REJECTED at the bridge id={id} addr=0x{addr:x} len={len} {width}x{height} (bad argument)"
                ));
                return JNI_FALSE;
            }
            let accepted = with_presenter(|p| {
                p.register_resident_texture(
                    id as u32,
                    addr as usize as *const u8,
                    len as usize,
                    width as u32,
                    height as u32,
                )
            })
            .unwrap_or(false);
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
    }
}
