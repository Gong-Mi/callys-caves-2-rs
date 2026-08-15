//! Cally's Caves 2 - Native 64-bit client (Rust)
//!
//! On Android, the Java `MainActivity` calls the JNI functions exposed
//! at the bottom of this file. The library has no SDL2 / GLES
//! dependency on Android - it draws into a software ABGR pixel buffer
//! that the Java side uploads to a `TextureView` once per frame.
//!
//! On desktop, run the `callys-client` binary which uses SDL2.

use std::collections::HashMap;
use std::path::Path;
use std::time::{Instant, SystemTime, UNIX_EPOCH};

use callys_asset::{GameDroidAsset, SpriteData, TpagItem};
use callys_core::{Facing, GameWorld, InputState, PlayerState, WeaponType};

// ============================================================
// Game state container
// ============================================================

pub struct GameState {
    pub asset: GameDroidAsset,
    pub world: GameWorld,
    pub input: InputState,
    pub frame_count: u64,
    pub started_at: Instant,
    pub rooms_visited: u32,
}

impl GameState {
    pub fn new(droid_path: &Path) -> Result<Self, Box<dyn std::error::Error>> {
        let asset = GameDroidAsset::parse(droid_path)?;
        let mut world = GameWorld::new();
        if let Some(first_room) = asset.rooms.first() {
            world.load_room(0, first_room, &asset.objects);
        }
        Ok(Self {
            asset,
            world,
            input: InputState::default(),
            frame_count: 0,
            started_at: Instant::now(),
            rooms_visited: 1,
        })
    }

    pub fn step(&mut self, dt: f32) {
        self.world.update(dt, &self.input);
        if let Some(target) = self.world.pending_room_warp.take() {
            if let Some(next) = self.asset.rooms.get(target) {
                self.world.load_room(target, next, &self.asset.objects);
                self.rooms_visited = self.rooms_visited.saturating_add(1);
            }
        }
        self.frame_count = self.frame_count.wrapping_add(1);
    }
}

pub fn current_time_ns() -> u64 {
    SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_nanos() as u64)
        .unwrap_or(0)
}

// ============================================================
// Software-rasterized framebuffer
// ============================================================

pub struct Framebuffer {
    pub width: u32,
    pub height: u32,
    pub pixels: Vec<u8>, // ABGR8888, row-major
}

impl Framebuffer {
    pub fn new(width: u32, height: u32) -> Self {
        Self {
            width,
            height,
            pixels: vec![0u8; (width * height * 4) as usize],
        }
    }

    fn put(&mut self, x: i32, y: i32, color: (u8, u8, u8, u8)) {
        if x < 0 || y < 0 {
            return;
        }
        let (x, y) = (x as u32, y as u32);
        if x >= self.width || y >= self.height {
            return;
        }
        let i = ((y * self.width + x) * 4) as usize;
        self.pixels[i] = color.2;     // B
        self.pixels[i + 1] = color.1; // G
        self.pixels[i + 2] = color.0; // R
        self.pixels[i + 3] = color.3; // A
    }

    fn fill_rect(&mut self, x: i32, y: i32, w: u32, h: u32, color: (u8, u8, u8, u8)) {
        if w == 0 || h == 0 {
            return;
        }
        let x0 = x.max(0) as u32;
        let y0 = y.max(0) as u32;
        let x1 = (x.saturating_add(w as i32)).min(self.width as i32).max(0) as u32;
        let y1 = (y.saturating_add(h as i32)).min(self.height as i32).max(0) as u32;
        if x1 <= x0 || y1 <= y0 {
            return;
        }
        for yy in y0..y1 {
            let row_start = (yy * self.width * 4) as usize;
            for xx in x0..x1 {
                let i = row_start + (xx * 4) as usize;
                self.pixels[i] = color.2;
                self.pixels[i + 1] = color.1;
                self.pixels[i + 2] = color.0;
                self.pixels[i + 3] = color.3;
            }
        }
    }

    fn draw_rect(&mut self, x: i32, y: i32, w: u32, h: u32, color: (u8, u8, u8, u8)) {
        if w == 0 || h == 0 {
            return;
        }
        let x1 = x + w as i32 - 1;
        let y1 = y + h as i32 - 1;
        for xi in x..=x1 {
            self.put(xi, y, color);
            self.put(xi, y1, color);
        }
        for yi in y..=y1 {
            self.put(x, yi, color);
            self.put(x1, yi, color);
        }
    }
}

pub fn draw_frame(
    fb: &mut Framebuffer,
    state: &GameState,
    _tpag: &HashMap<usize, TpagItem>,
    _sprites: &HashMap<usize, SpriteData>,
) {
    let scale_x = fb.width as f32 / 960.0;
    let scale_y = fb.height as f32 / 540.0;

    fb.fill_rect(0, 0, fb.width, fb.height, (15, 18, 30, 255));

    let cam_x = state.world.camera_x;
    let cam_y = state.world.camera_y;

    for solid in &state.world.solids {
        let color = if solid.is_boulder {
            (150, 95, 45, 255)
        } else {
            (65, 75, 95, 255)
        };
        let x = ((solid.rect.x - cam_x) * scale_x) as i32;
        let y = ((solid.rect.y - cam_y) * scale_y) as i32;
        let w = (solid.rect.w * scale_x) as u32;
        let h = (solid.rect.h * scale_y) as u32;
        fb.fill_rect(x, y, w, h, color);
        fb.draw_rect(x, y, w, h, (35, 40, 50, 255));
    }

    for gem in &state.world.gems {
        if gem.collected {
            continue;
        }
        let color = if gem.is_coin {
            (220, 220, 100, 255)
        } else {
            (80, 220, 255, 255)
        };
        let x = ((gem.x - cam_x) * scale_x) as i32;
        let y = ((gem.y - cam_y) * scale_y) as i32;
        let s = ((18.0 * scale_x) as u32).max(8);
        fb.fill_rect(x, y, s, s, color);
    }

    for warp in &state.world.warps {
        let x = ((warp.rect.x - cam_x) * scale_x) as i32;
        let y = ((warp.rect.y - cam_y) * scale_y) as i32;
        let w = (warp.rect.w * scale_x) as u32;
        let h = (warp.rect.h * scale_y) as u32;
        fb.draw_rect(x, y, w, h, (140, 220, 255, 180));
    }

    for enemy in &state.world.enemies {
        let x = ((enemy.x - cam_x) * scale_x) as i32;
        let y = ((enemy.y - cam_y) * scale_y) as i32;
        let w = (enemy.width * scale_x) as u32;
        let h = (enemy.height * scale_y) as u32;
        fb.fill_rect(x, y, w, h, (220, 60, 60, 255));
        let hp_pct = (enemy.health as f32 / enemy.max_health as f32).max(0.0);
        fb.fill_rect(x, (y - 6).max(0), w, 4, (40, 40, 40, 255));
        fb.fill_rect(x, (y - 6).max(0), (w as f32 * hp_pct) as u32, 4, (40, 220, 40, 255));
    }

    for p in &state.world.projectiles {
        let x = ((p.x - cam_x) * scale_x) as i32;
        let y = ((p.y - cam_y) * scale_y) as i32;
        let w = (p.width * scale_x) as u32;
        let h = (p.height * scale_y) as u32;
        let color = if p.is_player {
            (255, 240, 100, 255)
        } else {
            (255, 80, 80, 255)
        };
        fb.fill_rect(x, y, w, h, color);
    }

    let p = &state.world.player;
    let px = ((p.x - cam_x) * scale_x) as i32;
    let py = ((p.y - cam_y) * scale_y) as i32;
    let pw = (p.width * scale_x) as u32;
    let ph = (p.height * scale_y) as u32;

    let invuln = p.invulnerable_timer > 0.0 && ((p.invulnerable_timer * 15.0) as i32 % 2 == 0);
    if !invuln {
        let color = match p.state {
            PlayerState::Idle => (240, 80, 80, 255),
            PlayerState::Running => (255, 130, 60, 255),
            PlayerState::Jumping | PlayerState::Falling => (255, 210, 80, 255),
            PlayerState::Hurt => (255, 255, 255, 255),
            _ => (240, 80, 80, 255),
        };
        fb.fill_rect(px, py, pw, ph, color);
        let eye_x = if p.facing == Facing::Right {
            px + pw as i32 - 6
        } else {
            px + 2
        };
        fb.fill_rect(eye_x, py + 6, 4, 4, (255, 255, 255, 255));
    }

    fb.fill_rect(16, 16, 204, 20, (50, 50, 50, 255));
    let hp_pct = (p.health as f32 / p.max_health as f32).max(0.0);
    fb.fill_rect(18, 18, (200.0 * hp_pct) as u32, 16, (230, 40, 40, 255));
    fb.fill_rect(16, 42, 160, 24, (30, 35, 50, 255));
    fb.draw_rect(16, 42, 160, 24, (80, 200, 255, 255));
    let weapon_color = match p.current_weapon {
        WeaponType::Pistol => (200, 200, 200, 255),
        WeaponType::Shotgun => (255, 180, 60, 255),
        WeaponType::AssaultRifle => (255, 220, 100, 255),
        WeaponType::RocketLauncher => (255, 100, 80, 255),
        WeaponType::Sword => (180, 220, 255, 255),
    };
    fb.fill_rect(180, 42, 24, 24, weapon_color);
}

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
        pub fb: Framebuffer,
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
        let st = match GameState::new(Path::new(&path)) {
            Ok(s) => s,
            Err(e) => {
                log(&format!("GameState::new failed: {}", e));
                return;
            }
        };
        let mut g = slot().lock().unwrap();
        *g = Some(AndroidState {
            state: st,
            fb: Framebuffer::new(960, 540),
        });
        log("nativeInit ok");
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
        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeStep(
        _env: *mut JNIEnv,
        _class: jobject,
        dt_ms: jint,
    ) {
        let mut g = slot().lock().unwrap();
        if let Some(s) = g.as_mut() {
            let dt = (dt_ms as f32) / 1000.0;
            s.state.step(dt);
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
        weapon: jint,
    ) {
        let mut g = slot().lock().unwrap();
        if let Some(s) = g.as_mut() {
            s.state.input.move_left = move_left != 0;
            s.state.input.move_right = move_right != 0;
            s.state.input.jump = jump != 0;
            s.state.input.attack = attack != 0;
            s.state.input.switch_weapon = switch_weapon != 0;
            s.state.world.player.current_weapon = match weapon {
                0 => WeaponType::Pistol,
                1 => WeaponType::Shotgun,
                2 => WeaponType::AssaultRifle,
                3 => WeaponType::RocketLauncher,
                4 => WeaponType::Sword,
                _ => s.state.world.player.current_weapon,
            };
        }
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
            let g = slot().lock().unwrap();
            if g.is_none() {
                return;
            }
            let s = g.as_ref().unwrap();
            let len = (s.fb.width as c_int) * (s.fb.height as c_int);
            // re-interpret ABGR bytes as little-endian ARGB ints.
            // In memory the bytes are [B,G,R,A] and on Android
            // `Bitmap.Config.ARGB_8888` (which we use on the Java
            // side) expects [R,G,B,A] pixels. So we shuffle.
            let pixels = &s.fb.pixels;
            let mut ints: Vec<jint> = Vec::with_capacity(len as usize);
            for chunk in pixels.chunks_exact(4) {
                let b = chunk[0];
                let g_ = chunk[1];
                let r = chunk[2];
                let a = chunk[3];
                // Pack as ARGB8888 in a 32-bit int.  Pixel format
                // is little-endian: 0xAARRGGBB -> int.
                let argb: u32 =
                    ((a as u32) << 24) | ((r as u32) << 16) | ((g_ as u32) << 8) | (b as u32);
                ints.push(argb as jint);
            }
            let f: SetIntArrayRegionFn = jni_func(env, SLOT_SET_INT_ARRAY_REGION);
            f(env, out, 0, len, ints.as_ptr());
        }
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
