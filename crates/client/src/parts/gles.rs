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

        // libandroid.so: turn a Java Surface into an EGL window.
        fn ANativeWindow_fromSurface(env: *mut c_void, surface: *mut c_void) -> *mut c_void;
        fn ANativeWindow_release(window: *mut c_void);
    }

    const EGL_NO_DISPLAY: *mut c_void = std::ptr::null_mut();
    const EGL_NO_SURFACE: *mut c_void = std::ptr::null_mut();
    const EGL_NO_CONTEXT: *mut c_void = std::ptr::null_mut();
    const EGL_DEFAULT_DISPLAY: *mut c_void = std::ptr::null_mut();
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
            }
        }

        /// Attach (or detach, with a null window) the native window. The
        /// previous ANativeWindow reference from ANativeWindow_fromSurface is
        /// released here: it is ours to drop, while EGL keeps its own
        /// reference for as long as the window surface exists.
        pub fn set_window(&mut self, window: *mut c_void) {
            if window == self.window {
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
        }

        pub fn release(&mut self) {
            self.set_window(std::ptr::null_mut());
            unsafe {
                if self.display != EGL_NO_DISPLAY {
                    eglMakeCurrent(self.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
                    if self.context != EGL_NO_CONTEXT {
                        eglDestroyContext(self.display, self.context);
                    }
                    eglTerminate(self.display);
                }
            }
            self.display = EGL_NO_DISPLAY;
            self.context = EGL_NO_CONTEXT;
            self.config = std::ptr::null_mut();
        }

        /// Upload one BGRA frame and swap. Returns true when a frame was
        /// presented.
        pub fn present(&mut self, pixels: &[u8], width: u32, height: u32) -> bool {
            if self.window.is_null() {
                if !self.blit_miss_logged {
                    log("present skip: no window");
                    self.blit_miss_logged = true;
                }
                return false;
            }
            self.blit_miss_logged = false;
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
                return self.fail("eglCreateWindowSurface failed");
            }
            if eglMakeCurrent(self.display, self.surface, self.surface, self.context) == 0 {
                eglDestroySurface(self.display, self.surface);
                self.surface = EGL_NO_SURFACE;
                return self.fail("eglMakeCurrent failed");
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
            if !self.init_failed_logged {
                let err = unsafe { eglGetError() };
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
}
