// ============================================================
// Android JNI surface. We use only `jni-sys` for the C ABI types,
// avoiding `ndk` / `ndk-sys` re-export churn.
// ============================================================

#[cfg(all(target_os = "android", feature = "android"))]
mod android_jni {
    use super::*;
    use std::ffi::{CStr, CString};
    use std::os::raw::{c_char, c_int};
    use std::sync::OnceLock;

    // JNI table slots verified from NDK r29 jni.h, including all
    // pointer-returning entries in the count:
    //   GetStringUTFChars       169
    //   ReleaseStringUTFChars   170
    //   SetIntArrayRegion       211
    // The old values 161/162/186 caused ART to dispatch to
    // SetStaticFloatField/ReleaseBooleanArrayElements.
    pub type JNIEnv = *mut *const JNIInterface;
    pub type jint = i32;
    pub type jlong = i64;
    pub type jsize = i32;
    pub type jobject = *mut std::ffi::c_void;
    pub type jstring = *mut std::ffi::c_void;
    pub type jintArray = *mut std::ffi::c_void;
    pub type jboolean = u8;
    pub type jsize_t = usize;

    pub enum JNIInterface {}

    pub type GetStringUTFCharsFn = unsafe extern "system" fn(
        *mut JNIEnv,
        jstring,
        *mut jboolean,
    ) -> *const c_char;
    pub type ReleaseStringUTFCharsFn = unsafe extern "system" fn(
        *mut JNIEnv,
        jstring,
        *const c_char,
    );
    pub type SetIntArrayRegionFn = unsafe extern "system" fn(
        *mut JNIEnv,
        jintArray,
        jsize,
        jsize,
        *const jint,
    );

    #[inline]
    unsafe fn jni_table(env: *mut JNIEnv) -> *const usize {
        *env as *const usize
    }

    #[inline]
    unsafe fn jni_func<F>(env: *mut JNIEnv, slot: usize) -> F {
        let table = jni_table(env);
        let fptr = *table.add(slot);
        std::mem::transmute_copy::<usize, F>(&fptr)
    }

    const SLOT_GET_STRING_UTF_CHARS: usize = 169;
    const SLOT_RELEASE_STRING_UTF_CHARS: usize = 170;
    const SLOT_SET_INT_ARRAY_REGION: usize = 211;

    pub struct AndroidState {
        pub state: GameState,
        pub clock: frame_clock::FrameClock,
        pub fb: Framebuffer,
        pub blit: Vec<jint>,
        /// Device-side headless checkpoint cadence, including intro ticks (the
        /// client frame_count intentionally does not advance during the intro).
        trace_ticks: u64,
    }

    /// This is the actual bytecode Scene, not the legacy GameWorld. Log only
    /// phase changes or a sparse periodic checkpoint so logcat can distinguish
    /// intro -> town -> Lloyd sheet -> dismissal without inspecting pixels.
    fn ir_phase(state: &GameState) -> Option<(i32, bool, Option<i32>, bool, bool)> {
        let scene = state.scene.as_ref()?;
        Some((
            scene.current_room as i32,
            scene.instances.values().any(|i| i.alive && i.object == 137),
            scene.instances.values().find(|i| i.alive && (138..=153).contains(&i.object)).map(|i| i.object),
            scene.globals.get("roomstart").copied() == Some(1.0),
            scene.globals.get("talkedtolloyd1").copied() == Some(1.0),
        ))
    }

    static SLOT: OnceLock<std::sync::Mutex<Option<AndroidState>>> = OnceLock::new();

    fn slot() -> &'static std::sync::Mutex<Option<AndroidState>> {
        SLOT.get_or_init(|| std::sync::Mutex::new(None))
    }

    fn cstr(jstr: jstring, env: *mut JNIEnv) -> Option<String> {
        unsafe {
            let f: GetStringUTFCharsFn = jni_func(env, SLOT_GET_STRING_UTF_CHARS);
            let ptr = f(env, jstr, std::ptr::null_mut());
            if ptr.is_null() {
                return None;
            }
            let s = CStr::from_ptr(ptr as *const c_char)
                .to_str()
                .ok()
                .map(|s| s.to_string());
            let r: ReleaseStringUTFCharsFn = jni_func(env, SLOT_RELEASE_STRING_UTF_CHARS);
            r(env, jstr, ptr);
            s
        }
    }

    fn log(msg: &str) {
        let tag = b"callys-rust\0";
        let cmsg = CString::new(msg).unwrap_or_default();
        unsafe {
            ndk_sys_compat::__android_log_write(4, tag.as_ptr() as *const c_char, cmsg.as_ptr());
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeInit(
        env: *mut JNIEnv,
        _class: jobject,
        jpath: jstring,
    ) {
        let path = cstr(jpath, env).unwrap_or_else(|| {
            "/data/data/com.gongmi.callyscaves2/files/game.droid".to_string()
        });
        log(&format!("nativeInit path={}", path));
        let mut st = match GameState::new_persistent(Path::new(&path)) {
            Ok(s) => s,
            Err(e) => {
                log(&format!("GameState::new failed: {}", e));
                return;
            }
        };
        // Boot the full IR scene from real compiled CODE. enable_ir_gameplay
        // runs the original Game Start (CODE 17) on a live player: CODE 17
        // reads the savefile INIs, derives the weapon damage ladders, and
        // spawns obj_introduction itself. The prologue rides the full scene
        // (its Create deactivates the room behind it) — exactly the original
        // single-scene boot. No second enable_ir_gameplay at handover: the
        // old double-init silently discarded a restored save scene.
        let full_ir = Path::new(&path).with_file_name("full_ir.json");
        if !full_ir.exists() {
            log("full IR gameplay bundle missing; refusing silent handwritten fallback");
            return;
        }
        // Read the save BEFORE enable_ir_gameplay: a v2 scene save decides the
        // boot room (town) and queues the handover restore.
        let queued = st.queue_boot_ir_restore();
        if queued {
            log("IR save queued for prologue handover");
        }
        match callys_core::code_vm::load_bundle_from_file(&full_ir) {
            Ok(bundle) => {
                if let Err(error) = st.enable_ir_gameplay(std::sync::Arc::new(bundle)) {
                    log(&format!("full IR gameplay init failed: {error}"));
                    return;
                } else {
                    log("full IR gameplay bundle loaded");
                    if !queued {
                        log("no IR scene save to restore");
                    }
                }
            }
            Err(error) => {
                log(&format!("full IR bundle load failed: {error}"));
                return;
            }
        }
            match export_required_wavs(&st.asset, Path::new(&path)) {
            Ok(exported) => log(&format!("exported {} short sound effects", exported.len())),
            Err(error) => log(&format!("sound export failed: {error}")),
        }
        if let Some(diagnostic) = st.save_diagnostic.as_deref() {
            log(&format!("save load warning: {diagnostic}"));
        }
        let mut g = slot().lock().unwrap();
        *g = Some(AndroidState {
            state: st,
            clock: frame_clock::FrameClock::default(),
            fb: Framebuffer::new(1136, 640),
            blit: Vec::with_capacity(1136 * 640),
            trace_ticks: 0,
        });
        log("nativeInit ok");
        if let Some(phase) = ir_phase(&g.as_ref().unwrap().state) {
            log(&format!("IR boot room={} intro={} sheet={:?} roomstart={} talkedtolloyd1={}",
                phase.0, phase.1, phase.2, phase.3, phase.4));
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeResize(
        _env: *mut JNIEnv,
        _class: jobject,
        width: jint,
        height: jint,
    ) {
        let mut g = slot().lock().unwrap();
        if let Some(s) = g.as_mut() {
            s.fb = Framebuffer::new(width.max(1) as u32, height.max(1) as u32);
            s.blit.clear();
            s.blit.reserve((s.fb.width * s.fb.height) as usize);
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativePointerRelease(
        _env: *mut JNIEnv, _class: jobject, x: f32, y: f32,
    ) {
        if let Some(s) = slot().lock().unwrap().as_mut() {
            s.state.pointer_released(x as f64, y as f64);
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeSetClockPaused(
        _env: *mut JNIEnv,
        _class: jobject,
        paused: jboolean,
    ) {
        if let Some(s) = slot().lock().unwrap().as_mut() {
            s.clock.set_paused(paused != 0);
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeStep(
        _env: *mut JNIEnv,
        _class: jobject,
        now_ns: jlong,
    ) {
        let mut g = slot().lock().unwrap();
        if let Some(s) = g.as_mut() {
            let previous_ir = ir_phase(&s.state);
            let previous_room = s.state.world.current_room_index;
            let previous_player_state = s.state.world.player.state;
            let previous_save_diagnostic = s.state.save_diagnostic.clone();
            let was_halted = s.state.runtime_diagnostic.is_some();
            let ticks = s.clock.step_at(&mut s.state, now_ns);
            if !was_halted {
                if let Some(diagnostic) = s.state.runtime_diagnostic.as_deref() {
                    log(&format!("IR execution halted: {diagnostic}"));
                }
            }
            if s.state.save_diagnostic != previous_save_diagnostic {
                if let Some(diagnostic) = s.state.save_diagnostic.as_deref() {
                    log(&format!("save write warning: {diagnostic}"));
                }
            }
            let previous_trace_ticks = s.trace_ticks;
            s.trace_ticks = s.trace_ticks.wrapping_add(ticks);
            if let Some(phase) = ir_phase(&s.state) {
                if previous_ir != Some(phase) || s.trace_ticks / 120 != previous_trace_ticks / 120 {
                    let scene = s.state.scene.as_ref().unwrap();
                    let player = scene.instances.values().find(|i| i.alive && i.object == 0);
                    let (x, y) = player.map(|i| (
                        i.fields.get("x").copied().unwrap_or(f64::NAN),
                        i.fields.get("y").copied().unwrap_or(f64::NAN),
                    )).unwrap_or((f64::NAN, f64::NAN));
                    log(&format!("IR checkpoint tick={} room={} intro={} sheet={:?} roomstart={} talkedtolloyd1={} player=({x:.1},{y:.1}) active={} halted={}",
                        s.trace_ticks, phase.0, phase.1, phase.2, phase.3, phase.4,
                        scene.instances.values().filter(|i| i.alive && i.active).count(),
                        s.state.runtime_diagnostic.is_some()));
                }
            } else {
                // Legacy GameWorld logs are NOT evidence of IR room changes.
                if s.state.world.current_room_index != previous_room {
                    log(&format!(
                        "legacy room transition {} -> {} ({}) spawn=({}, {})",
                        previous_room,
                        s.state.world.current_room_index,
                        s.state.world.current_room_name,
                        s.state.world.player.x,
                        s.state.world.player.y,
                    ));
                }
                if previous_player_state != PlayerState::Dead
                    && s.state.world.player.state == PlayerState::Dead
                {
                    log(&format!(
                        "legacy player died in room {} checkpoint=({}, {})",
                        s.state.world.current_room_name,
                        s.state.world.checkpoint.x,
                        s.state.world.checkpoint.y,
                    ));
                } else if previous_player_state == PlayerState::Dead
                    && s.state.world.player.state != PlayerState::Dead
                {
                    log(&format!(
                        "legacy player respawned in room {} at=({}, {}) health={}",
                        s.state.world.current_room_name,
                        s.state.world.player.x,
                        s.state.world.player.y,
                        s.state.world.player.health,
                    ));
                }
            }
            draw_frame(&mut s.fb, &s.state, &s.state.asset.tpag_items, &s.state.asset.sprites);
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeInput(
        _env: *mut JNIEnv,
        _class: jobject,
        move_left: jint,
        move_right: jint,
        jump: jint,
        attack: jint,
        switch_weapon: jint,
        sword: jint,
        tap: jint,
    ) {
        let mut g = slot().lock().unwrap();
        if let Some(s) = g.as_mut() {
            s.state.input.move_left = move_left != 0;
            s.state.input.move_right = move_right != 0;
            s.state.input.jump = jump != 0;
            s.state.input.attack = attack != 0;
            s.state.input.sword = sword != 0;
            s.state.input.switch_weapon = switch_weapon != 0;
            s.state.input.tap = tap != 0;
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativePollSound(
        _env: *mut JNIEnv,
        _class: jobject,
    ) -> jint {
        // Pack (sound id, looping, is_stop) into one jint: SOND ids < 2^29,
        // bit 30 carries looping, bit 29 marks a stop command (MediaPlayer
        // teardown for BGM switching).
        slot()
            .lock()
            .unwrap()
            .as_mut()
            .and_then(|state| state.state.poll_sound())
            .and_then(|(audio_id, looping, is_stop)| {
                let packed = audio_id
                    | if looping { 1 << 30 } else { 0 }
                    | if is_stop { 1 << 29 } else { 0 };
                jint::try_from(packed).ok()
            })
            .unwrap_or(-1)
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativePollHaptic(
        _env: *mut JNIEnv,
        _class: jobject,
    ) -> jint {
        slot()
            .lock()
            .unwrap()
            .as_mut()
            .and_then(|state| state.state.poll_haptic())
            .unwrap_or(-1)
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeGetWidth(
        _env: *mut JNIEnv,
        _class: jobject,
    ) -> jint {
        slot()
            .lock()
            .unwrap()
            .as_ref()
            .map(|s| s.fb.width as jint)
            .unwrap_or(0)
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeGetHeight(
        _env: *mut JNIEnv,
        _class: jobject,
    ) -> jint {
        slot()
            .lock()
            .unwrap()
            .as_ref()
            .map(|s| s.fb.height as jint)
            .unwrap_or(0)
    }

    /// Returns the framebuffer as a heap-allocated int[] via
    /// `SetIntArrayRegion`. Caller (Java) passes a preallocated
    /// `int[fb.width * fb.height]` array.
    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeBlitToIntArray(
        env: *mut JNIEnv,
        _class: jobject,
        out: jintArray,
    ) {
        unsafe {
            let mut g = slot().lock().unwrap();
            if g.is_none() {
                return;
            }
            let s = g.as_mut().unwrap();
            let len = (s.fb.width as c_int) * (s.fb.height as c_int);
            // re-interpret ABGR bytes as little-endian ARGB ints.
            // In memory the bytes are [B,G,R,A] and on Android
            // `Bitmap.Config.ARGB_8888` (which we use on the Java
            // side) expects [R,G,B,A] pixels. So we shuffle.
            s.blit.clear();
            for chunk in s.fb.pixels.chunks_exact(4) {
                let b = chunk[0];
                let g_ = chunk[1];
                let r = chunk[2];
                let a = chunk[3];
                // Pack as ARGB8888 in a 32-bit int.  Pixel format
                // is little-endian: 0xAARRGGBB -> int.
                let argb: u32 =
                    ((a as u32) << 24) | ((r as u32) << 16) | ((g_ as u32) << 8) | (b as u32);
                s.blit.push(argb as jint);
            }
            let f: SetIntArrayRegionFn = jni_func(env, SLOT_SET_INT_ARRAY_REGION);
            f(env, out, 0, len, s.blit.as_ptr());
        }
    }

    #[cfg(test)]
    #[test]
    fn headless_phase_reads_live_ir_scene_not_legacy_world() {
        use std::sync::Arc;
        let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"));
        let mut state = GameState::new(&root.join("../../assets/game.droid")).unwrap();
        assert_eq!(ir_phase(&state), None);
        let bundle = callys_core::code_vm::load_bundle_from_file(
            &root.join("../../crates/core/src/generated/full_ir.json"),
        ).unwrap();
        state.enable_ir_gameplay(Arc::new(bundle)).unwrap();
        assert_eq!(ir_phase(&state), Some((0, true, None, false, false)));
        for _ in 0..125 { state.step(1.0 / 60.0); }
        state.input.tap = true;
        state.step(1.0 / 60.0);
        state.input.tap = false;
        state.step(1.0 / 60.0);
        assert!(state.runtime_diagnostic.is_none());
        assert_eq!(ir_phase(&state), Some((0, false, None, false, false)));
        // The legacy world still points at room 0; it cannot certify the
        // prologue handover. Only the Scene's live intro bit did.
    }
    /// Hand the Java Surface to the Rust presenter as an EGL window.
    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeSetSurface(
        env: *mut JNIEnv,
        _class: jobject,
        surface: jobject,
    ) {
        let window = crate::gles::window_from_surface(
            env as *mut std::os::raw::c_void,
            surface as *mut std::os::raw::c_void,
        );
        let mut presenter = crate::gles::presenter().lock().unwrap();
        presenter.set_window(window);
        log(&format!("nativeSetSurface window={}", !window.is_null()));
    }

    /// Upload the current engine frame and swap. Replaces the Java-side blit
    /// (`nativeBlitToIntArray` + Bitmap/Canvas) with a direct texture upload
    /// from the framebuffer, so no int[] crosses JNI per frame.
    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativePresent(
        _env: *mut JNIEnv,
        _class: jobject,
    ) {
        // Lock order is presenter -> state everywhere (set_window takes only
        // the presenter), so this cannot deadlock. Holding the state guard for
        // the swap keeps `pixels` valid: the engine slot is replaced wholesale
        // by nativeInit, which would free the buffer under a raw pointer. The
        // cost is that an input event can wait one eglSwapBuffers; the Java
        // host called into the same two locks from its UI and render threads.
        let mut presenter = crate::gles::presenter().lock().unwrap();
        let mut guard = slot().lock().unwrap();
        let Some(state) = guard.as_mut() else { return };
        presenter.present(&state.fb.pixels, state.fb.width, state.fb.height);
    }

}

#[cfg(all(target_os = "android", feature = "android"))]
mod ndk_sys_compat {
    use std::os::raw::{c_char, c_int};
    extern "C" {
        pub fn __android_log_write(
            prio: c_int,
            tag: *const c_char,
            text: *const c_char,
        ) -> c_int;
    }
}

#[cfg(all(target_os = "android", feature = "android"))]
pub use android_jni::*;
