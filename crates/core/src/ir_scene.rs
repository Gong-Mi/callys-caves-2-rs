//! Headless event host for a bounded IR scene, NOT GameWorld or a full GM runner.
//! Event bodies come exclusively from CODE IR/OBJT bindings. No intro timers or
//! coordinates are hand-translated here. External instances are explicitly inert.
use crate::code_vm::{self, Bundle, Host, STRING_REF_BASE};
use serde::Serialize;
use std::collections::{BTreeMap, BTreeSet};

#[derive(Debug, Clone)]
pub struct Instance {
    pub object: i32, pub alive: bool, pub active: bool, pub external: bool,
    pub fields: BTreeMap<String, f64>, pub arrays: BTreeMap<(String, i32), f64>, pub alarms: [i32; 12],
}
#[derive(Debug, Clone, Default)]
pub struct TouchDevice {
    pub x: f64, pub y: f64, pub down: bool, pub pressed: bool, pub released: bool,
}
#[derive(Debug, Clone, Default)]
pub struct SpriteBounds {
    pub width: f64, pub height: f64, pub origin_x: f64, pub origin_y: f64,
    /// Frame count from the original SPRT record; drives the per-step
    /// image_index advance. 0 means no animation data (never advances).
    pub frames: f64,
}
#[derive(Debug, Clone, Serialize, PartialEq)]
pub struct DrawCommand {
    pub code: usize, pub offset: usize, pub instance: i32, pub view: i32,
    pub sprite: i32, pub frame: f64, pub x: f64, pub y: f64,
    pub scale_x: f64, pub scale_y: f64, pub rotation: f64, pub color: i32, pub alpha: f64,
    /// True when the original wrapped this draw in `d3d_set_fog(true, c, 0, 0)`.
    /// `color` is then the fog colour (the hit-flash pipeline), which floods the
    /// sprite instead of multiplying it like `image_blend` does. Both are packed
    /// GM colours, so the consumer cannot tell them apart from `color` alone.
    pub fog: bool,
}
#[derive(Debug, Clone, Serialize, PartialEq)]
pub struct TextCommand {
    pub code: usize, pub offset: usize, pub instance: i32, pub view: i32,
    pub x: f64, pub y: f64, pub text: String, pub color: i32, pub alpha: f64,
    /// The font resource id from `draw_set_font` (GMS alphabetical order:
    /// 0=font1 18px, 1=font2 10px, 2=font3 10px, 3=font4 14px, 4=font5 8px,
    /// 5=font6 14px). Zero is the default when a Draw never sets a font.
    pub font: i32,
}
#[derive(Debug, Clone, Serialize, PartialEq)]
pub struct HealthbarCommand {
    pub code: usize, pub offset: usize, pub instance: i32, pub view: i32,
    pub x1: f64, pub y1: f64, pub x2: f64, pub y2: f64, pub amount: f64,
    pub back_col: i32, pub min_col: i32, pub max_col: i32,
}
#[derive(Debug, Clone, Serialize, PartialEq)]
pub struct BackgroundCommand {
    pub code: usize, pub offset: usize, pub instance: i32, pub view: i32,
    pub background: i32, pub x: f64, pub y: f64,
    pub scale_x: f64, pub scale_y: f64, pub rotation: f64, pub color: i32, pub alpha: f64,
}
/// Index into the existing public queues: payload structs and Vec interfaces
/// stay compatible with headless consumers and queue-only rasterizer fixtures.
#[derive(Debug, Clone, Copy, Serialize, PartialEq, Eq, PartialOrd, Ord)]
pub enum DrawQueue {
    Sprite(usize), Text(usize), Healthbar(usize), Background(usize),
    RoomTile(usize), Particle(usize),
}
#[derive(Debug, Clone, Copy, Serialize, PartialEq, Eq, PartialOrd, Ord)]
pub enum DrawPhase { Room, Gui }
#[derive(Debug, Clone, Copy, Serialize, PartialEq)]
pub struct DrawEmission {
    pub queue: DrawQueue, pub emit_order: usize, pub depth: f64,
    pub view: i32, pub phase: DrawPhase,
}
/// Provenance copies prevent stale indices from aliasing DIFFERENT public Vec
/// replacements/edits. Unmatched entries remain in the compatibility tail;
/// identical direct replacements necessarily retain their original provenance.
#[derive(Debug)]
enum DrawPayload {
    Sprite(DrawCommand), Text(TextCommand), Healthbar(HealthbarCommand),
    Background(BackgroundCommand),
}
#[derive(Debug)]
struct RecordedDraw { emission: DrawEmission, payload: DrawPayload }

/// Particle type configured by the original part_type_* builtins
/// (real source of truth: obj_pwrlevelinitialize Create, CODE 458).
/// Distances in px, speeds in px/tick, directions in GMS degrees (CW, 0=+x).
#[derive(Debug, Clone)]
pub struct ParticleType {
    pub size_min: f64, pub size_max: f64, pub size_delta: f64,
    pub speed_min: f64, pub speed_max: f64, pub speed_delta: f64,
    pub dir_min: f64, pub dir_max: f64, pub dir_delta: f64,
    pub grav_amount: f64, pub grav_dir: f64,
    pub life_min: f64, pub life_max: f64,
    pub color_min: i32, pub color_max: i32,
    pub alpha: f64,
}
impl SpriteBounds {
    /// Bounds with an explicit original SPRT frame count.
    pub fn with_frames(width: f64, height: f64, origin_x: f64, origin_y: f64, frames: f64) -> Self {
        Self { width, height, origin_x, origin_y, frames }
    }
}
impl Default for ParticleType {
    fn default() -> Self {
        Self { size_min: 1.0, size_max: 1.0, size_delta: 0.0,
            speed_min: 0.0, speed_max: 0.0, speed_delta: 0.0,
            dir_min: 0.0, dir_max: 360.0, dir_delta: 0.0,
            grav_amount: 0.0, grav_dir: 270.0,
            life_min: 1.0, life_max: 1.0,
            color_min: 16777215, color_max: 16777215, alpha: 1.0 }
    }
}
/// Live particle spawned by part_particles_create.
#[derive(Debug, Clone)]
pub struct Particle {
    pub type_id: f64,
    pub x: f64, pub y: f64,
    pub vx: f64, pub vy: f64,
    pub size: f64,
    /// Remaining lifetime in ticks.
    pub life: f64,
    /// Lifetime at spawn; drives the color2 blend progress.
    pub life0: f64,
    /// Current blended color; == color_min at spawn (progress 0).
    pub color: i32,
    /// Original part_type_color2 endpoints (BGR packed), kept per particle.
    pub color_min: i32,
    pub color_max: i32,
    pub alpha: f64,
}
#[derive(Debug, Clone)]
pub struct AudioVoice {
    pub sound: f64,
    pub voice: f64,
    pub looping: bool,
    pub stopped: bool,
    pub paused: bool,
}
#[derive(Debug, Clone, Serialize)]
pub struct AudioCommand { pub code: usize, pub offset: usize, pub sound: i32, pub priority: f64, pub looping: bool, pub voice: i32 }
#[derive(Debug)]
pub struct Scene {
    pub instances: BTreeMap<i32, Instance>, pub globals: BTreeMap<String, f64>,
    /// Legacy engine-global score, shared by player, UI, shops and death events.
    pub score: f64,
    pub draws: Vec<DrawCommand>, pub texts: Vec<TextCommand>, pub healthbars: Vec<HealthbarCommand>,
    pub backgrounds: Vec<BackgroundCommand>, pub audio: Vec<AudioCommand>,
    draw_emissions: Vec<RecordedDraw>,
    draw_phase: DrawPhase,
    draw_depth_context: Option<f64>,
    pub executed: Vec<(usize,usize)>,
    pub view: i32, pub view_positions: BTreeMap<i32,(f64,f64)>, pub mouse_pressed: bool,
    pub view_ports: BTreeMap<i32,(f64,f64)>,
    pub touch_devices: [TouchDevice; 5],
    /// Actual pointer releases in room coordinates; separate from virtual buttons.
    pub left_releases: Vec<(f64, f64)>,
    /// Actual pointer presses in room coordinates for local Mouse_0 events.
    pub left_presses: Vec<(f64, f64)>,
    pub sprite_bounds: BTreeMap<i32, SpriteBounds>,
    /// Manual inclusive bounding boxes supplied by the asset loader, not
    /// cached resource IDs or dimensions inferred from an unrelated bitmap.
    pub sprite_bboxes: BTreeMap<i32, [i32; 4]>,
    /// Per-sprite collision masks extracted from the SPRT chunk (GMS1
    /// inline 1bpp bitmaps, one entry per frame). Sprites with no masks
    /// (test fixtures wiring only `sprite_bounds`) fall back to the bbox
    /// answer on precise queries.
    pub sprite_masks: BTreeMap<i32, Vec<callys_asset::CollisionMask>>,
    pub object_parents: BTreeMap<i32, Vec<i32>>,
    pub display_width: f64, pub display_height: f64, pub current_room: f64,
    pub room_width: f64, pub room_height: f64,
    /// The ROOM editor's indexed VIEW table for the current room. Its static
    /// `visible` bits seed the runtime `view_visible` array on room entry; GML
    /// may then switch indices at run time. The canvas is 1136x640 — the same
    /// display size the original runner reports on this device class, which is
    /// exactly the CODE 538 branch that selects view 0 (448x252 view window,
    /// 1136x640 port). 960x540 would be its own branch (view 6).
    pub room_views: Vec<callys_asset::RoomView>,
    pub current_font: f64, pub draw_color: i32, pub draw_alpha: f64,
    pub rng_seed: u64,
    pub view_visible: [bool; 8],
    pub ini_open_file: Option<String>,
    pub ini_data: BTreeMap<(String, String, String), f64>,
    /// Real-directory boundary for the original savefile INIs. When set,
    /// `file_exists` checks the directory, `ini_open` loads the disk file into
    /// `ini_data`, and `ini_close` flushes the open file back to disk. Without
    /// it the INIs stay an in-memory cache (legacy test behavior).
    pub ini_disk_dir: Option<std::path::PathBuf>,
    pub ds_maps: BTreeMap<i32, BTreeMap<String, f64>>,
    pub other_instance: Option<i32>,
    pub room_tiles: Vec<callys_asset::RoomTileInstance>,
    /// Runtime-built strings (`string()`, `string_format()`, `string_digits()`,
    /// concatenations). They live after the bundle's string table inside the
    /// pooled reference space: index = STRING_REF_BASE + table.len() + position.
    pub dynamic_strings: Vec<String>,
    pub particle_systems: Vec<f64>,
    pub particle_types: Vec<(f64, ParticleType)>,
    pub particles: Vec<Particle>,
    pub audio_voices: Vec<AudioVoice>,
    pending_stops: Vec<f64>,
    next_particle_system_id: f64,
    next_particle_type_id: f64,
    next_voice_id: f64,
    pub target_room_warp: Option<usize>,
    pub persistent_objects: BTreeSet<i32>,
    pub fog_enabled: bool,
    pub fog_color: i32,
    next_id: i32, next_ds_map_id: i32, site: (usize,usize), depth: usize,
}
impl Default for Scene {
    fn default() -> Self {
        Self {
            instances: BTreeMap::new(), globals: BTreeMap::new(),
            score: 0.0,
            draws: Vec::new(), texts: Vec::new(), healthbars: Vec::new(), backgrounds: Vec::new(), audio: Vec::new(), executed: Vec::new(),
            draw_emissions: Vec::new(), draw_phase: DrawPhase::Room, draw_depth_context: None,
            view: 0, view_positions: BTreeMap::new(), mouse_pressed: false,
            view_ports: BTreeMap::new(),
            room_views: Vec::new(),
            touch_devices: Default::default(),
            left_releases: Vec::new(),
            left_presses: Vec::new(),
            sprite_bounds: BTreeMap::new(),
            sprite_bboxes: BTreeMap::new(),
            sprite_masks: BTreeMap::new(),
            object_parents: BTreeMap::new(),
            display_width: 1136.0, display_height: 640.0, current_room: 0.0,
            room_width: 1024.0, room_height: 768.0,
            current_font: 0.0, draw_color: -1, draw_alpha: 1.0,
            rng_seed: 0x12345678,
            view_visible: [true, false, false, false, false, false, false, false],
            ini_open_file: None,
            ini_data: BTreeMap::new(),
            ini_disk_dir: None,
            ds_maps: BTreeMap::new(),
            particle_systems: Vec::new(),
            particle_types: Vec::new(),
            particles: Vec::new(),
            audio_voices: Vec::new(),
            pending_stops: Vec::new(),
            next_particle_system_id: 1.0,
            next_particle_type_id: 1.0,
            next_voice_id: 1.0,
            other_instance: None,
            room_tiles: Vec::new(),
            dynamic_strings: Vec::new(),
            target_room_warp: None,
            persistent_objects: BTreeSet::new(),
            fog_enabled: false,
            fog_color: 0,
            next_id: 0, next_ds_map_id: 1, site: (0, 0), depth: 0,
        }
    }
}
/// Formats a GM real the way the original ini files store them: integers
/// without a decimal point, everything else through Rust's shortest round-trip
/// form. Parsing back with `str::parse::<f64>` restores the exact value.
fn format_gm_real(value: f64) -> String {
    if value == value.trunc() && value.abs() < 1e15 {
        format!("{}", value as i64)
    } else {
        format!("{value}")
    }
}
fn next_rand(seed: &mut u64) -> f64 {
    *seed = seed.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
    ((*seed >> 11) as f64) / ((1u64 << 53) as f64)
}
/// Index carried by a pooled string reference, or None when the value is a
/// plain number. The reference space starts at `STRING_REF_BASE`, far above
/// every gameplay number, so the two can never be confused.
fn pool_index(v: f64) -> Option<usize> {
    if !v.is_finite() || v < STRING_REF_BASE { return None; }
    let offset = v - STRING_REF_BASE;
    if offset.fract() != 0.0 { return None; }
    Some(offset as usize)
}
/// GMS 1.4 number rendering, shared by `string()` and draw_text's implicit
/// coercion: whole numbers print without a decimal point, fractional values
/// with two decimals. (The original `string(1/3)` is "0.33".)
pub(crate) fn gm_real_text(v: f64) -> String {
    if !v.is_finite() { return "0".into(); }
    if v.fract() == 0.0 && v.abs() < 9.0e15 { format!("{}", v as i64) } else { format!("{v:.2}") }
}
/// `string_format`'s `tot` field: left-pad to the requested width.
fn pad_left(text: &str, tot: usize) -> String {
    if text.len() >= tot { return text.to_string(); }
    let mut out = "0".repeat(tot - text.len());
    out.push_str(text);
    out
}
/// Seeded inclusive range draw; single LCG advance like every other builtin.
fn rand_range(seed: &mut u64, min: f64, max: f64) -> f64 {
    if max < min { return min; }
    let r = next_rand(seed);
    min + r * (max - min)
}

fn line_intersects_box(x1: f64, y1: f64, x2: f64, y2: f64, min_x: f64, max_x: f64, min_y: f64, max_y: f64) -> bool {
    let dx = x2 - x1;
    let dy = y2 - y1;
    let mut t0 = 0.0f64;
    let mut t1 = 1.0f64;

    for (p, q) in [
        (-dx, x1 - min_x),
        (dx, max_x - x1),
        (-dy, y1 - min_y),
        (dy, max_y - y1),
    ] {
        if p == 0.0 {
            if q < 0.0 { return false; }
        } else {
            let r = q / p;
            if p < 0.0 {
                if r > t1 { return false; }
                if r > t0 { t0 = r; }
            } else {
                if r < t0 { return false; }
                if r < t1 { t1 = r; }
            }
        }
    }
    t0 <= t1
}

fn int(v:f64)->Result<i32,String> {
    if v.is_finite() && v.fract()==0.0 && v>=i32::MIN as f64 && v<=i32::MAX as f64 {Ok(v as i32)}
    else {Err(format!("expected i32, got {v}"))}
}
impl Scene {
    /// Looks up a configured particle type by its runtime handle.
    fn particle_type(&self, id: f64) -> Result<&ParticleType, String> {
        self.particle_types.iter()
            .find(|(k, _)| *k == id)
            .map(|(_, t)| t)
            .ok_or_else(|| format!("unknown particle type {id}"))
    }
    /// Mutable lookup used by the part_type_* configurators.
    fn particle_type_mut(&mut self, id: f64) -> Result<&mut ParticleType, String> {
        self.particle_types.iter_mut()
            .find(|(k, _)| *k == id)
            .map(|(_, t)| t)
            .ok_or_else(|| format!("unknown particle type {id}"))
    }

    // ---- Audio voice domain (public seam for tests/client) ----
    /// True while any undrained voice of this sound is playing (not stopped,
    /// not paused).
    pub fn audio_is_playing_sound(&self, sound: f64) -> bool {
        self.audio_voices.iter()
            .any(|v| v.sound == sound && !v.stopped && !v.paused)
    }
    /// Emits an AudioCommand and opens a looping-capable voice; returns its handle.
    pub fn call_audio_play(&mut self, sound: f64, priority: f64, looping: bool) -> f64 {
        let voice = self.next_voice_id;
        self.next_voice_id += 1.0;
        self.audio.push(AudioCommand {
            code: self.site.0, offset: self.site.1, sound: sound as i32,
            priority, looping, voice: voice as i32,
        });
        self.audio_voices.push(AudioVoice { sound, voice, looping, stopped: false, paused: false });
        voice
    }
    /// Stops every undrained voice of this sound (audio_stop_sound) and
    /// queues a host stop command so the platform tears the sound down.
    pub fn call_audio_stop_sound(&mut self, sound: f64) {
        let mut stopped_any = false;
        for v in &mut self.audio_voices {
            if v.sound == sound && !v.stopped { v.stopped = true; stopped_any = true; }
        }
        if stopped_any && !self.pending_stops.contains(&sound) {
            self.pending_stops.push(sound);
        }
    }
    pub fn call_audio_pause_all(&mut self) {
        for v in &mut self.audio_voices { v.paused = true; }
    }
    pub fn call_audio_resume_all(&mut self) {
        for v in &mut self.audio_voices { v.paused = false; }
    }
    pub fn call_audio_stop_all(&mut self) {
        for v in &mut self.audio_voices {
            if !v.stopped {
                v.stopped = true;
                if !self.pending_stops.contains(&v.sound) {
                    self.pending_stops.push(v.sound);
                }
            }
        }
    }
    /// Host-bound stop commands accumulated since the last drain; the client
    /// forwards them so MediaPlayer/SoundPool actually tear sounds down.
    pub fn take_stop_commands(&mut self) -> Vec<f64> {
        std::mem::take(&mut self.pending_stops)
    }
    pub fn call_audio_sound_gain(&mut self, sound: f64, _gain: f64, _time: f64) {
        // Gain has no audible effect in this projection; recorded by no-op.
    }
    /// Drains audible commands; non-looping voices retire so the original
    /// is_playing gates reopen after playback ends.
    pub fn drain_audio(&mut self) -> Vec<AudioCommand> {
        let drained = std::mem::take(&mut self.audio);
        self.audio_voices.retain(|v| v.looping && !v.stopped);
        drained
    }

    pub fn call_object_exists(&self, id: f64) -> bool {
        self.object_parents.contains_key(&(id as i32))
    }

    pub fn init_bundle(&mut self, b: &Bundle) {
        for obj in &b.objects {
            self.object_parents.insert(obj.id, obj.parent_chain.clone());
            // Original GM persistent flag drives room-switch retention
            // (transition_to_room) and the save-snapshot collected filter.
            if obj.persistent {
                self.persistent_objects.insert(obj.id);
            }
        }
    }

    /// Populates the full verified baseline of fresh-start globals defined by
    /// the original GameMaker Other_2 (Game Start) event (CODE 17).
    pub fn init_fresh_start_globals(&mut self) {
        for (k, v) in [
            ("level", 1.0), ("maxhp", 4.0), ("health1", 4.0), ("experience", 0.0),
            ("xptolevelup", 30.0), ("roomstart", 0.0), ("soundmute", 0.0), ("musicmute", 0.0),
            ("haskey", 0.0), ("warplock", 0.0), ("warpfrommap", 0.0), ("ending", 0.0),
            ("coinmultiply", 1.0), ("timeplayed", 0.0), ("gemdropenabled", 1.0),
            ("poisonenabled", 0.0), ("weaponswapped", 0.0), ("firing", 0.0), ("swing", 1.0),
            ("rebuff", 0.0), ("boss1touched", 0.0), ("sword", 0.0),
            ("tjumpactive", 0.0), ("triplejumpbought", 0.0),
            ("strengthupgradebought", 0.0), ("strengthupgrade2bought", 0.0),
            ("energywavebought", 0.0), ("healthregenbought", 0.0),
            ("swordupgradebought", 0.0), ("swordupgrade2bought", 0.0), ("swordupgrade3bought", 0.0),
            ("powerupgradebought", 0.0), ("powerupgrade2bought", 0.0), ("powerupgrade3bought", 0.0),
            ("coinmultiplier2bought", 0.0), ("coinmultiplier5bought", 0.0),
            ("maxhpupgradebought", 0.0), ("maxhpupgrade2bought", 0.0),
            ("drawchange", 0.0), ("drawlevelup", 0.0), ("drawweaponlevelup", 0.0), ("drawweaponchange", 0.0),
            ("drawchangepistol4", 1.0), ("drawchangeshotgun4", 1.0),
            ("drawchangeassaultrifle4", 1.0), ("drawchangerocket4", 1.0),
            ("twentyfivebears", 0.0), ("hitmoney", 0.0),
        ] {
            self.globals.insert(k.into(), v);
        }
        for b in 1..=6 {
            self.globals.insert(format!("boss{b}dead"), 0.0);
            self.globals.insert(format!("levelchallenge{b}visited"), 0.0);
        }
        for i in 1..=16 {
            self.globals.insert(format!("talkedtolloyd{i}"), 0.0);
        }
        for w in [
            "assaultriflelevel", "bladegunlevel", "bombgunlevel", "boomeranglevel", "bowlevel",
            "flamethrowerlevel", "icegunlevel", "laserlevel", "pistollevel", "rocketlevel",
            "shotgunlevel", "spikegunlevel",
        ] {
            self.globals.insert(w.into(), 1.0);
        }
        for (w, bought) in [
            ("pistol", 1.0), ("pistolbought", 1.0),
            ("shotgun", 0.0), ("shotgunbought", 0.0),
            ("assaultrifle", 0.0), ("assaultriflebought", 0.0),
            ("rocket", 0.0), ("rocketbought", 0.0),
            ("laser", 0.0), ("laserbought", 0.0),
            ("icegun", 0.0), ("icegunbought", 0.0),
            ("bladegun", 0.0), ("bladegunbought", 0.0),
            ("flamethrower", 0.0), ("flamethrowerbought", 0.0),
            ("bow", 0.0), ("bowbought", 0.0),
            ("bombgun", 0.0), ("bombgunbought", 0.0),
            ("boomerang", 0.0), ("boomerangbought", 0.0),
            ("spikegun", 0.0), ("spikegunbought", 0.0),
        ] {
            self.globals.insert(w.into(), bought);
        }
        for (w, xp_up) in [
            ("pistol", 46.0), ("shotgun", 115.0), ("assaultrifle", 120.0),
            ("rocket", 80.0), ("laser", 80.0), ("icegun", 60.0),
            ("bow", 62.0), ("flamethrower", 180.0), ("bladegun", 200.0),
            ("boomerang", 250.0), ("spikegun", 64.0), ("bombgun", 160.0),
        ] {
            self.globals.insert(format!("{w}xp"), 0.0);
            self.globals.insert(format!("{w}xptolevelup"), xp_up);
            for lvl in [4, 7, 10] {
                self.globals.insert(format!("drawchange{w}{lvl}"), 1.0);
            }
        }
        for (w, dmg) in [
            ("pistol", 1.0), ("shotgun", 0.5), ("assaultrifle", 0.6),
            ("rocket", 6.0), ("laser", 3.0), ("icegun", 1.0),
            ("bow", 2.0), ("flamethrower", 0.3), ("bladegun", 3.0),
            ("boomerang", 2.0), ("spikegun", 3.0), ("bombgun", 4.0),
        ] {
            self.globals.insert(format!("{w}damage"), dmg);
        }
        for k in ["bearskilled", "knifebanditskilled", "pistolthugskilled", "wolfkilled", "chomperbotkilled"] {
            self.globals.insert(k.into(), 0.0);
        }
    }
    /// Progress snapshot for the IR path: persistent room index, the
    /// SCENE_SAVE_GLOBALS subset, shared score, and CONSUMED transient
    /// instance identities of the current room. Same contract as the legacy
    /// world's `collected_instance_ids`: pickups insert their id at
    /// consumption time, and a loader skips listed placements. Destroyed-
    /// but-listed instances (alive=false) are exactly the consumed ones.
    /// External/test instances are never captured.
    pub fn save_snapshot(&self) -> (usize, BTreeMap<String, f64>, f64, Vec<i32>) {
        let mut globals = BTreeMap::new();
        for name in crate::save::SCENE_SAVE_GLOBALS {
            if let Some(v) = self.globals.get(*name) {
                globals.insert((*name).to_string(), *v);
            }
        }
        let collected = self.instances.iter()
            .filter(|(_, i)| {
                !i.alive
                    && !i.external
                    // Persistent-object instances cross rooms and are never
                    // consumption-marked; every transient (UI included: each
                    // room re-places one) is room-local and captured here as
                    // consumed so a restore keeps picked-up loot gone.
                    && !self.persistent_objects.contains(&i.object)
            })
            .map(|(id, _)| *id)
            .collect();
        (self.current_room as usize, globals, self.score, collected)
    }

    /// Restores a snapshot produced by save_snapshot. Globals in the file are
    /// applied over init_fresh_start_defaults; missing keys keep fresh values.
    /// Instance identities list consumed transients: the room is re-placed
    /// (load / transition), then those identities are removed again so loot
    /// picked up in the saved session stays gone.
    pub fn restore_snapshot(
        &mut self,
        b: &Bundle,
        room_id: usize,
        room: &callys_asset::RoomData,
        globals: &BTreeMap<String, f64>,
        score: f64,
        collected: &[i32],
    ) -> Result<(), String> {
        self.restore_snapshot_cross_room(b, room_id, room, globals, score, collected)
    }

    /// Cross-room variant of restore_snapshot: when the live scene sits in a
    /// different room than the snapshot (original boot order: the prologue
    /// always plays over rm_town, the saved room loads at handover), the
    /// snapshot room is entered through the full transition (Room End on the
    /// old room, transient purge, load, Room Start) instead of a same-room
    /// re-materialization that would leak the old room's transient instances.
    pub fn restore_snapshot_cross_room(
        &mut self,
        b: &Bundle,
        room_id: usize,
        room: &callys_asset::RoomData,
        globals: &BTreeMap<String, f64>,
        score: f64,
        collected: &[i32],
    ) -> Result<(), String> {
        self.globals.extend(globals.iter().map(|(k, v)| (k.clone(), *v)));
        self.score = score;
        if self.current_room != room_id as f64 {
            self.transition_to_room(b, room_id, room)?;
        } else {
            self.load_room_from_data(b, room_id, room)?;
        }
        self.instances.retain(|id, i| !(collected.contains(id) && i.alive && !i.external));
        Ok(())
    }

    /// Test/embedding boundary, not an implicit fake room loader.
    pub fn insert_external(&mut self, object:i32)->i32 {
        self.next_id=self.next_id.max(200000)+1; let id=self.next_id;
        self.instances.insert(id,Instance{object,alive:true,active:true,external:true,fields:BTreeMap::new(),arrays:BTreeMap::new(),alarms:[-1;12]}); id
    }

    /// Data-driven room loader: instantiates all objects and tiles from RoomData.
    /// Runs each instance's Create event, then if a room_binding exists for that
    /// (room_id, instance_id), executes its creation code in the instance's context.
    pub fn load_room_from_data(
        &mut self,
        bundle: &Bundle,
        room_id: usize,
        room: &callys_asset::RoomData,
    ) -> Result<(), String> {
        self.current_room = room_id as f64;
        self.room_width = room.width as f64;
        self.room_height = room.height as f64;
        self.room_views = room.views.clone();
        self.view_visible = [false; 8];
        self.view_positions.clear();
        self.view_ports.clear();
        for (index, view) in self.room_views.iter().take(8).enumerate() {
            let index = index as i32;
            self.view_visible[index as usize] = view.visible;
            self.view_positions.insert(index, (view.xview as f64, view.yview as f64));
            self.view_ports.insert(index, (view.wport as f64, view.hport as f64));
        }
        self.target_room_warp = None;
        self.room_tiles = room.tiles.clone();
        self.clear_draw_commands();

        // Materialize objects from RoomData
        for inst in &room.objects {
            let obj_id = inst.object_id;
            let x = inst.x as f64;
            let y = inst.y as f64;

            // If a persistent instance already exists and is alive, do not
            // duplicate it (GM: rooms re-place their persistent objects, the
            // runner keeps the live instance). obj_player is persistent in the
            // original data, so it is covered by the set, not a hardcode.
            if self.persistent_objects.contains(&obj_id)
                && self.instances.values().any(|i| i.object == obj_id && i.alive)
            {
                continue;
            }

            // Instantiate object
            let inst_id = self.create_with_id(bundle, inst.instance_id, obj_id, x, y)?;

            // Apply scale if specified
            if inst.scale_x.is_finite() && inst.scale_x != 0.0 {
                let _ = self.write(inst_id, -1, "image_xscale", None, inst.scale_x as f64);
            }
            if inst.scale_y.is_finite() && inst.scale_y != 0.0 {
                let _ = self.write(inst_id, -1, "image_yscale", None, inst.scale_y as f64);
            }

            // Run creation code if bound
            if let Some(binding) = bundle.room_bindings.iter().find(|b| {
                b.room_id == room_id && (b.instance_id == inst.instance_id || (b.object_id == obj_id && b.code_id == inst.creation_code_id as usize))
            }) {
                code_vm::execute(bundle, binding.code_id, inst_id, self)
                    .map_err(|e| format!("Creation code error: {e}"))?;
            }
        }

        Ok(())
    }

    /// Transitions to a target room: preserves persistent instances (player, UI, etc.)
    /// while clearing transient room instances and loading new geometry and bindings.
    /// Emits Event 7 Subtype 5 (Room End) before exit, and Event 7 Subtype 4 (Room Start) on entry.
    pub fn transition_to_room(
        &mut self,
        bundle: &Bundle,
        room_id: usize,
        room: &callys_asset::RoomData,
    ) -> Result<(), String> {
        // 1. Dispatch Room End (Event 7, Subtype 5)
        let current_ids: Vec<i32> = self.instances.iter()
            .filter(|(_, i)| i.alive && i.active && !i.external)
            .map(|(&id, _)| id)
            .collect();
        for id in current_ids {
            self.dispatch(bundle, id, 7, 5)
                .map_err(|e| format!("Room End instance {id}: {e}"))?;
        }

        // 2. Retain persistent instances, purge transient
        // Original GM8.1 semantics: an instance survives the room switch iff
        // its object is persistent. obj_player(0) and obj_music(68) are the
        // only persistent objects in the original data; obj_UI(66) is a
        // normal per-room object that every room re-places (so retaining it
        // here would stack a second UI every hop).
        self.instances.retain(|_, i| i.alive && self.persistent_objects.contains(&i.object));

        // 3. Load new room data and bindings
        self.load_room_from_data(bundle, room_id, room)?;

        // 4. Dispatch Room Start (Event 7, Subtype 4)
        let new_ids: Vec<i32> = self.instances.iter()
            .filter(|(_, i)| i.alive && i.active && !i.external)
            .map(|(&id, _)| id)
            .collect();
        for id in new_ids {
            self.dispatch(bundle, id, 7, 4)
                .map_err(|e| format!("Room Start instance {id}: {e}"))?;
        }

        Ok(())
    }

    /// Computes instance bounding box from position and sprite bounds.
    pub fn bounds_for_instance(&self, id: i32) -> Option<(f64, f64, f64, f64)> {
        let inst = self.instances.get(&id)?;
        let ix = inst.fields.get("x").copied()?;
        let iy = inst.fields.get("y").copied()?;
        let spr = inst.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
        let (w, h, ox, oy) = self.sprite_bounds.get(&spr).map_or((32.0, 32.0, 0.0, 0.0), |b| (b.width, b.height, b.origin_x, b.origin_y));
        let sx = inst.fields.get("image_xscale").copied().unwrap_or(1.0);
        let sy = inst.fields.get("image_yscale").copied().unwrap_or(1.0);
        let x0 = ix - ox * sx; let y0 = iy - oy * sy;
        let x1 = x0 + w * sx; let y1 = y0 + h * sy;
        let (min_x, max_x) = if x0 < x1 { (x0, x1) } else { (x1, x0) };
        let (min_y, max_y) = if y0 < y1 { (y0, y1) } else { (y1, y0) };
        Some((min_x, max_x, min_y, max_y))
    }

    /// Inclusive integer bbox used specifically by FindDist, not the legacy
    /// collision broad phase. Original Compute_BoundingBox @0x192340 prefers
    /// mask_index >= 0, normalizes mirrored scales, and subtracts one from the
    /// transformed exclusive right/bottom edge. A missing sprite is a point.
    fn distance_bounds_for_instance(&self, id: i32) -> Option<(f64, f64, f64, f64)> {
        let inst = self.instances.get(&id)?;
        let x = inst.fields.get("x").copied()? as f32;
        let y = inst.fields.get("y").copied()? as f32;
        let mask = inst.fields.get("mask_index").copied().unwrap_or(-1.0) as i32;
        let sid = if mask >= 0 { mask } else {
            inst.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32
        };
        let point = || (x.trunc() as f64, x.trunc() as f64, y.trunc() as f64, y.trunc() as f64);
        let sp = match self.sprite_bounds.get(&sid) {
            Some(sp) => sp,
            None => return Some(point()),
        };
        // The loader retains the original manual SPRT bbox. Width/origin or
        // occupied mask pixels cannot substitute for its independent edges.
        let (left,right,top,bottom) = if let Some(&[l,r,t,b]) = self.sprite_bboxes.get(&sid) {
            (l as f32,r as f32,t as f32,b as f32)
        } else if let Some(masks) = self.sprite_masks.get(&sid).filter(|m| !m.is_empty()) {
            // Unknown/custom sprites: derive the union bbox without pretending
            // this is a loader for arbitrary GameMaker manual bbox metadata.
            let mut bbox: Option<(i32,i32,i32,i32)> = None;
            for m in masks {
                let stride = (m.width as usize + 7) / 8;
                if stride == 0 { continue; }
                for (offset,&byte) in m.bits.iter().enumerate() {
                    if byte == 0 { continue; }
                    let row = offset / stride;
                    if row >= m.height as usize { break; }
                    for bit in 0..8 {
                        let col = (offset % stride) * 8 + bit;
                        if col >= m.width as usize || byte & (0x80 >> bit) == 0 { continue; }
                        let (col,row) = (col as i32,row as i32);
                        bbox = Some(match bbox {
                            Some((l,r,t,b)) => (l.min(col),r.max(col),t.min(row),b.max(row)),
                            None => (col,col,row,row),
                        });
                    }
                }
            }
            match bbox {
                Some((l,r,t,b)) => (l as f32,r as f32,t as f32,b as f32),
                None => return Some(point()),
            }
        } else {
            (0.0,sp.width as f32 - 1.0,0.0,sp.height as f32 - 1.0)
        };
        let ox = sp.origin_x as f32;
        let oy = sp.origin_y as f32;
        let sx = inst.fields.get("image_xscale").copied().unwrap_or(1.0) as f32;
        let sy = inst.fields.get("image_yscale").copied().unwrap_or(1.0) as f32;
        let angle = inst.fields.get("image_angle").copied().unwrap_or(0.0) as f32;
        let (l,r,t,b) = if angle == 0.0 {
            // Runner's lrint path rounds the low edge FIRST, then adds the
            // scaled width/height to that integer; scaling is not point distance.
            let l = (x + (left - ox) * sx).round_ties_even();
            let r = (l + (right - left + 1.0) * sx).round_ties_even();
            let t = (y + (top - oy) * sy).round_ties_even();
            let b = (t + (bottom - top + 1.0) * sy).round_ties_even();
            (l.min(r), l.max(r)-1.0, t.min(b), t.max(b)-1.0)
        } else {
            let rad = angle * std::f32::consts::PI / 180.0;
            let (sin,cos) = rad.sin_cos();
            let mut l = f32::INFINITY; let mut r = f32::NEG_INFINITY;
            let mut t = f32::INFINITY; let mut b = f32::NEG_INFINITY;
            for cx in [left - ox,right + 1.0 - ox] {
                for cy in [top - oy,bottom + 1.0 - oy] {
                    let (cx,cy) = (cx * sx,cy * sy);
                    let px = x + cx * cos + cy * sin;
                    let py = y + cy * cos - cx * sin;
                    l = l.min(px); r = r.max(px); t = t.min(py); b = b.max(py);
                }
            }
            (l.round_ties_even(),r.round_ties_even()-1.0,t.round_ties_even(),b.round_ties_even()-1.0)
        };
        Some((l as f64,r as f64,t as f64,b as f64))
    }

    pub fn create_with_id(&mut self, b: &Bundle, id: i32, object: i32, x: f64, y: f64) -> Result<i32, String> {
        let obj = b.objects.iter().find(|o| o.id == object)
            .ok_or(format!("object {object} not compiled; no fallback Create"))?;
        self.next_id = self.next_id.max(id);
        self.instances.insert(id, Instance {
            object, alive: true, active: true, external: false,
            fields: BTreeMap::new(), arrays: BTreeMap::new(), alarms: [-1; 12],
        });
        let i = self.instances.get_mut(&id).unwrap();
        for (n, v) in [
            ("id", id as f64),
            ("x", x), ("y", y), ("sprite_index", obj.sprite as f64), ("image_index", 0.0),
            ("image_xscale", 1.0), ("image_yscale", 1.0), ("image_angle", 0.0),
            ("image_blend", 16777215.0), ("image_alpha", 1.0), ("image_speed", 1.0),
            ("hspeed", 0.0), ("vspeed", 0.0), ("speed", 0.0),
            ("direction", 0.0), ("friction", 0.0), ("gravity", 0.0), ("gravity_direction", 270.0),
            ("visible", 1.0),
        ] {
            i.fields.insert(n.into(), v);
        }
        self.dispatch(b, id, 0, 0)?;
        Ok(id)
    }
    pub fn create(&mut self,b:&Bundle,object:i32,x:f64,y:f64)->Result<i32,String> {
        let obj=b.objects.iter().find(|o|o.id==object).ok_or(format!("object {object} not compiled; no fallback Create"))?;
        let id=self.insert_external(object);
        let i=self.instances.get_mut(&id).unwrap(); i.external=false;
        // Named engine defaults only, never default-zero reads of user fields.
        for (n,v) in [("id", id as f64), ("x",x),("y",y),("sprite_index",obj.sprite as f64),("image_index",0.0),
                      ("image_xscale",1.0),("image_yscale",1.0),("image_angle",0.0),
                      ("image_blend",16777215.0),("image_alpha",1.0),("image_speed",1.0),
                      ("hspeed",0.0),("vspeed",0.0),("speed",0.0),
                      ("direction",0.0),("friction",0.0),("gravity",0.0),("gravity_direction",270.0),
                      ("visible",1.0)] {
            i.fields.insert(n.into(),v);
        }
        self.dispatch(b,id,0,0)?; Ok(id)
    }
    pub fn dispatch(&mut self,b:&Bundle,id:i32,event_type:i32,subtype:i32)->Result<(),String> {
        if self.depth>=64 {return Err("event recursion budget exhausted".into());}
        let i=self.instances.get(&id).ok_or("unknown instance")?;
        if i.external {return Err("cannot dispatch an externally managed instance".into());}
        let o=b.objects.iter().find(|o|o.id==i.object).ok_or("missing object definition")?;
        let mut codes = o.events.iter()
            .find(|e| e.event_type == event_type && e.subtype == subtype)
            .map(|e| e.codes.clone());
        if codes.is_none() {
            for &pid in &o.parent_chain {
                if let Some(parent_obj) = b.objects.iter().find(|obj| obj.id == pid) {
                    if let Some(parent_event) = parent_obj.events.iter().find(|e| e.event_type == event_type && e.subtype == subtype) {
                        codes = Some(parent_event.codes.clone());
                        break;
                    }
                }
            }
        }
        let codes = codes.unwrap_or_default();
        self.depth+=1;
        let result=(|| {for code in codes {code_vm::execute(b,code,id,self).map_err(|e|e.to_string())?;} Ok(())})();
        self.depth-=1; result
    }
    pub fn destroy(&mut self,b:&Bundle,id:i32)->Result<(),String> {
        let i=self.instances.get_mut(&id).ok_or("destroy unknown instance")?;
        if !i.alive {return Ok(());}
        // Retain self storage during Destroy; prevent recursive destruction.
        i.alive=false;
        self.dispatch(b,id,1,0)
    }
    /// Bounded scheduler contract: active snapshot; alarm decrement/dispatch,
    /// then Step. New instances enter the next tick. No physics/animation advance.
    pub fn tick(&mut self,b:&Bundle)->Result<(),String> {
        let ids:Vec<_>=self.instances.iter().filter(|(_,i)|i.alive&&i.active&&!i.external).map(|(id,_)|*id).collect();
        for id in &ids {
            for index in 0..12 {
                let i=self.instances.get_mut(id).unwrap();
                if !i.alive||!i.active {break;}
                if i.alarms[index]>0 {
                    i.alarms[index]-=1;
                    if i.alarms[index]==0 { i.alarms[index]=-1; self.dispatch(b,*id,2,index as i32)?; }
                }
            }
        }
        // Mouse_7 is local LeftReleased (not pressed/global). Use a separate
        // physical-pointer queue so virtual control-zone changes cannot click UI.
        // Consume even locked/missed releases; never replay them after an alarm.
        for (x, y) in std::mem::take(&mut self.left_releases) {
            if !x.is_finite() || !y.is_finite() { continue; }
            for id in &ids {
                if !self.instances.get(id).is_some_and(|i| i.alive && i.active && !i.external) {
                    continue;
                }
                if let Some((left, right, top, bottom)) = self.bounds_for_instance(*id) {
                    if x >= left && x < right && y >= top && y < bottom {
                        self.dispatch(b, *id, 6, 7)?;
                    }
                }
            }
        }
        // Mouse_0 is local LeftPressed / Button Down on instance.
        for (x, y) in std::mem::take(&mut self.left_presses) {
            if !x.is_finite() || !y.is_finite() { continue; }
            for id in &ids {
                if !self.instances.get(id).is_some_and(|i| i.alive && i.active && !i.external) {
                    continue;
                }
                if let Some((left, right, top, bottom)) = self.bounds_for_instance(*id) {
                    if x >= left && x < right && y >= top && y < bottom {
                        self.dispatch(b, *id, 6, 0)?;
                    }
                }
            }
        }
        for id in ids { let i=&self.instances[&id]; if i.alive&&i.active {self.dispatch(b,id,3,0)?;} }

        // Particle integration: position += velocity, gravity along grav_dir
        // (GMS degrees, 270 = down), life decrements; expired particles die.
        if !self.particles.is_empty() {
            let types = self.particle_types.clone();
            for p in self.particles.iter_mut() {
                let t = types.iter().find(|(k, _)| *k == p.type_id).map(|(_, t)| t);
                p.x += p.vx; p.y += p.vy;
                if let Some(t) = t {
                    if t.grav_amount != 0.0 {
                        let rad = t.grav_dir * std::f64::consts::PI / 180.0;
                        p.vx += t.grav_amount * rad.cos();
                        p.vy += -t.grav_amount * rad.sin();
                    }
                    // part_type_color2: blend color_min -> color_max over the
                    // particle lifetime. Packed GMS BGR: r=bits0-7, g=8-15,
                    // b=16-23. Aging first: after this tick's decrement the
                    // progress advances, so the very first tick already blends.
                    if p.life0 > 0.0 && (p.color_min != p.color_max) {
                        p.life -= 1.0;
                        let progress = (1.0 - p.life / p.life0).clamp(0.0, 1.0);
                        let mix = |a: i32, b: i32| -> i32 {
                            (a as f64 + (b - a) as f64 * progress).round() as i32
                        };
                        let r = mix(p.color_min & 0xFF, p.color_max & 0xFF);
                        let g = mix((p.color_min >> 8) & 0xFF, (p.color_max >> 8) & 0xFF);
                        let bl = mix((p.color_min >> 16) & 0xFF, (p.color_max >> 16) & 0xFF);
                        p.color = r | (g << 8) | (bl << 16);
                    } else {
                        p.life -= 1.0;
                    }
                }
            }
            self.particles.retain(|p| p.life > 0.0);
        }

        // Event-driven collision dispatch (event_type == 4)
        let colliders: Vec<(i32, i32)> = self.instances.iter()
            .filter(|(_, i)| i.alive && i.active && !i.external)
            .map(|(id, i)| (*id, i.object))
            .collect();

        for (id, obj_id) in colliders {
            if !self.instances.get(&id).map_or(false, |i| i.alive && i.active) {
                continue;
            }
            let mut col_events = Vec::new();
            if let Some(obj) = b.objects.iter().find(|o| o.id == obj_id) {
                for e in &obj.events {
                    if e.event_type == 4 {
                        col_events.push(e.subtype);
                    }
                }
                for &pid in &obj.parent_chain {
                    if let Some(p) = b.objects.iter().find(|o| o.id == pid) {
                        for e in &p.events {
                            if e.event_type == 4 && !col_events.contains(&e.subtype) {
                                col_events.push(e.subtype);
                            }
                        }
                    }
                }
            }
            if col_events.is_empty() { continue; }

            let (a_min_x, a_max_x, a_min_y, a_max_y) = match self.bounds_for_instance(id) {
                Some(bnd) => bnd,
                None => continue,
            };

            for target_obj in col_events {
                let targets = match self.select(id, target_obj) {
                    Ok(t) => t,
                    Err(_) => continue,
                };
                for tid in targets {
                    if tid == id { continue; }
                    if !self.instances.get(&tid).map_or(false, |i| i.alive && i.active) {
                        continue;
                    }
                    if let Some((b_min_x, b_max_x, b_min_y, b_max_y)) = self.bounds_for_instance(tid) {
                        if a_min_x < b_max_x && a_max_x > b_min_x && a_min_y < b_max_y && a_max_y > b_min_y {
                            self.other_instance = Some(tid);
                            let res = self.dispatch(b, id, 4, target_obj);
                            self.other_instance = None;
                            res?;
                            if !self.instances.get(&id).map_or(false, |i| i.alive && i.active) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Standard GameMaker motion integration: gravity, friction, velocity advance
        let anim_frames: BTreeMap<i32, f64> = self.sprite_bounds.iter()
            .map(|(k, b)| (*k, b.frames)).collect();
        for i in self.instances.values_mut() {
            if !i.alive || !i.active || i.external { continue; }

            // 1. Gravity integration
            let grav = i.fields.get("gravity").copied().unwrap_or(0.0);
            if grav != 0.0 {
                let grav_dir = i.fields.get("gravity_direction").copied().unwrap_or(270.0);
                let rad = grav_dir * std::f64::consts::PI / 180.0;
                let gh = grav * rad.cos();
                let gv = -grav * rad.sin();
                if let Some(h) = i.fields.get_mut("hspeed") { *h += gh; }
                if let Some(v) = i.fields.get_mut("vspeed") { *v += gv; }
            }

            // 2. Friction integration
            let frict = i.fields.get("friction").copied().unwrap_or(0.0);
            let mut hsp = i.fields.get("hspeed").copied().unwrap_or(0.0);
            let mut vsp = i.fields.get("vspeed").copied().unwrap_or(0.0);
            if frict != 0.0 {
                let spd = (hsp * hsp + vsp * vsp).sqrt();
                if spd > 0.0 {
                    let new_spd = (spd - frict).max(0.0);
                    hsp = hsp * new_spd / spd;
                    vsp = vsp * new_spd / spd;
                    if let Some(h) = i.fields.get_mut("hspeed") { *h = hsp; }
                    if let Some(v) = i.fields.get_mut("vspeed") { *v = vsp; }
                }
            }

            // 3. Position integration
            if hsp != 0.0 {
                if let Some(x) = i.fields.get_mut("x") { *x += hsp; }
            }
            if vsp != 0.0 {
                if let Some(y) = i.fields.get_mut("y") { *y += vsp; }
            }

            // 4. Synchronize speed and direction fields if non-zero
            if hsp != 0.0 || vsp != 0.0 {
                let cur_spd = (hsp * hsp + vsp * vsp).sqrt();
                let mut dir = (-vsp).atan2(hsp) * 180.0 / std::f64::consts::PI;
                if dir < 0.0 { dir += 360.0; }
                i.fields.insert("speed".into(), cur_spd);
                i.fields.insert("direction".into(), dir);
            }

            // 5. Standard GMS sprite animation cycle: image_index += image_speed
            // at the end of the step. Forward play wraps into [0, frames);
            // reversed play (image_speed < 0) reflects at sub 0; a 1-frame or
            // unknown sprite never moves. image_index itself is numeric-only.
            let speed = i.fields.get("image_speed").copied().unwrap_or(1.0);
            if speed != 0.0 {
                let spr = i.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
                let frames = anim_frames.get(&spr).copied().unwrap_or(0.0);
                if frames > 1.0 {
                    let idx = i.fields.get("image_index").copied().unwrap_or(0.0);
                    let mut next = idx + speed;
                    if next >= frames { next %= frames; }
                    else if next < 0.0 {
                        // Triangular reflection over [0, frames-1].
                        let span = frames - 1.0;
                        let d = -next;
                        let pos = (d % (2.0 * span)).abs();
                        next = if pos <= span { pos } else { 2.0 * span - pos };
                    }
                    i.fields.insert("image_index".into(), next);
                } else if frames == 1.0 {
                    i.fields.insert("image_index".into(), 0.0);
                }
            }
        }

        Ok(())
    }
    /// Retires this frame's input edges (`mouse_pressed`, device `pressed`/
    /// `released`). The original runner's frame is "platform input update ->
    /// alarms / Step / collision -> Draw -> next frame": an edge stays visible
    /// to every original event of the frame that saw the touch, Draw included.
    /// The Draw-time button checks (obj_shootbutton/jumpbutton/swordbutton,
    /// obj_lloydtutorial1..16, obj_weaponswap) read these edges, so the frame
    /// boundary belongs to whoever also runs the draw pass: call this after
    /// `draw_view`. `down` is physical state and is never retired here.
    pub fn end_frame(&mut self) {
        self.mouse_pressed = false;
        for d in &mut self.touch_devices {
            d.pressed = false;
            d.released = false;
        }
    }
    /// Runtime-selected visible view. The room table supplies the per-index
    /// geometry; `view_visible` is authoritative after GML has run.
    pub fn active_view_index(&self) -> Option<usize> {
        self.view_visible.iter().position(|visible| *visible)
    }
    /// Clear all four queues AND provenance at the room/view/frame boundary.
    /// Direct Vec edits remain supported, but cannot express cross-type order;
    /// use Host draw builtins to retain exact emission provenance.
    pub fn clear_draw_commands(&mut self) {
        self.draws.clear(); self.texts.clear(); self.healthbars.clear(); self.backgrounds.clear();
        self.draw_emissions.clear();
        self.draw_phase = DrawPhase::Room;
        self.draw_depth_context = None;
    }
    fn record_draw(&mut self, b: &Bundle, id: i32, queue: DrawQueue) {
        let payload = match queue {
            DrawQueue::Sprite(i) => DrawPayload::Sprite(self.draws[i].clone()),
            DrawQueue::Text(i) => DrawPayload::Text(self.texts[i].clone()),
            DrawQueue::Healthbar(i) => DrawPayload::Healthbar(self.healthbars[i].clone()),
            DrawQueue::Background(i) => DrawPayload::Background(self.backgrounds[i].clone()),
            _ => unreachable!("room geometry is merged at consumption"),
        };
        let depth = self.draw_depth_context.unwrap_or_else(|| {
            self.instances.get(&id).map_or(0.0, |i| {
                i.fields.get("depth").copied().unwrap_or_else(||
                    b.objects.iter().find(|o| o.id == i.object).map_or(0.0, |o| o.depth as f64))
            })
        });
        let emission = DrawEmission { queue, emit_order: self.draw_emissions.len(),
            depth, view: self.view, phase: self.draw_phase };
        self.draw_emissions.push(RecordedDraw { emission, payload });
    }
    /// Effective CPU command stream. Original emissions retain event depth,
    /// phase and cross-type order. Tiles merge by numeric descending depth;
    /// equal-depth instances precede tiles (DoSlowDrawRoom@0x1b0768 BLE).
    ///
    /// Legacy queue-only edits have no inter-type timestamp. Unmatched payloads
    /// are consumed ONCE in historical grouped order, after tracked commands.
    /// If all queues were replaced, this is the whole historical fixture path.
    /// Particles still have no system-depth metadata: their existing square
    /// approximation uses depth 0 after equal-depth instance commands.
    pub fn ordered_draw_commands(&self) -> Vec<DrawEmission> {
        let mut seen = BTreeSet::new();
        let mut ordered = Vec::new();
        // Latest emission owns a reused index after a public Vec clear/push.
        for recorded in self.draw_emissions.iter().rev() {
            let e = recorded.emission;
            if !seen.insert(e.queue) { continue; }
            let matches = match (&recorded.payload, e.queue) {
                (DrawPayload::Sprite(c), DrawQueue::Sprite(i)) => self.draws.get(i) == Some(c),
                (DrawPayload::Text(c), DrawQueue::Text(i)) => self.texts.get(i) == Some(c),
                (DrawPayload::Healthbar(c), DrawQueue::Healthbar(i)) => self.healthbars.get(i) == Some(c),
                (DrawPayload::Background(c), DrawQueue::Background(i)) => self.backgrounds.get(i) == Some(c),
                _ => false,
            };
            if matches { ordered.push(e); }
        }
        let tracked: BTreeSet<_> = ordered.iter().map(|e| e.queue).collect();
        let emission = |queue, emit_order, depth| DrawEmission {
            queue, emit_order, depth, view: self.view, phase: DrawPhase::Room,
        };
        let mut tiles: Vec<_> = self.room_tiles.iter().enumerate().collect();
        tiles.sort_by_key(|(i, t)| (std::cmp::Reverse(t.depth), *i));
        if !ordered.is_empty() {
            for (i, t) in &tiles {
                ordered.push(emission(DrawQueue::RoomTile(*i), *i, t.depth as f64));
            }
            for i in 0..self.particles.len() {
                ordered.push(emission(DrawQueue::Particle(i), self.draw_emissions.len() + i, 0.0));
            }
            ordered.sort_by(|a, b| {
                a.phase.cmp(&b.phase)
                    .then_with(|| b.depth.total_cmp(&a.depth))
                    .then_with(|| matches!(a.queue, DrawQueue::RoomTile(_))
                        .cmp(&matches!(b.queue, DrawQueue::RoomTile(_))))
                    .then_with(|| a.emit_order.cmp(&b.emit_order))
            });
        }
        let tracked_stream = !ordered.is_empty();
        let mut append = |queue, depth| {
            if !tracked.contains(&queue) {
                ordered.push(emission(queue, ordered.len(), depth));
            }
        };
        for i in 0..self.backgrounds.len() { append(DrawQueue::Background(i), 0.0); }
        if !tracked_stream {
            for (i, t) in tiles.iter().filter(|(_, t)| t.depth >= 0) {
                append(DrawQueue::RoomTile(*i), t.depth as f64);
            }
        }
        for i in 0..self.draws.len() { append(DrawQueue::Sprite(i), 0.0); }
        if !tracked_stream {
            for i in 0..self.particles.len() { append(DrawQueue::Particle(i), 0.0); }
            for (i, t) in tiles.iter().filter(|(_, t)| t.depth < 0) {
                append(DrawQueue::RoomTile(*i), t.depth as f64);
            }
        }
        for i in 0..self.healthbars.len() { append(DrawQueue::Healthbar(i), 0.0); }
        for i in 0..self.texts.len() { append(DrawQueue::Text(i), 0.0); }
        ordered
    }
    /// One explicit view pass. Camera positions must be supplied by caller.
    /// OBJT depth determines order; equal-depth creation-id order is provisional.
    pub fn draw_view(&mut self,b:&Bundle,view:i32)->Result<(),String> {
        if !self.view_positions.contains_key(&view) {return Err(format!("view {view} is not configured"));}
        self.view=view;
        self.clear_draw_commands();
        self.fog_enabled = false;
        let mut ids = Vec::new();
        for (&id, i) in &self.instances {
            // The original skips +0x69 deactivated instances before BOTH the
            // Draw event and default-sprite branch, in the same depth walk.
            if i.alive && i.active && !i.external {
                let o = b.objects.iter().find(|o| o.id == i.object).ok_or("missing draw object")?;
                let has_draw = o.events.iter().any(|e| e.event_type == 8 && e.subtype == 0)
                    || o.parent_chain.iter().any(|&pid| {
                        b.objects.iter().find(|p| p.id == pid)
                            .map_or(false, |p| p.events.iter().any(|e| e.event_type == 8 && e.subtype == 0))
                    });
                let depth = i.fields.get("depth").copied().unwrap_or(o.depth as f64);
                ids.push((depth, id, has_draw));
            }
        }
        ids.sort_by(|a, b| b.0.total_cmp(&a.0).then(a.1.cmp(&b.1)));
        for (depth, id, has_draw) in ids {
            self.draw_depth_context = Some(depth);
            let result = if has_draw {
                self.dispatch(b, id, 8, 0)
            } else {
                // Read sprite fields at this instance's turn, not before a
                // preceding Draw event has had a chance to change them.
                let i = &self.instances[&id];
                let visible = i.fields.get("visible").copied().unwrap_or(1.0) >= 0.5;
                let fields = ["sprite_index","image_index","x","y","image_xscale","image_yscale","image_angle","image_blend","image_alpha"];
                let args = fields.iter().map(|n| i.fields.get(*n).copied()).collect::<Option<Vec<_>>>();
                if i.alive && i.active && visible {
                    if let Some(args) = args { self.draw(b, id, &args) } else { Ok(()) }
                } else { Ok(()) }
            };
            self.draw_depth_context = None;
            result?;
        }

        // Preserve the separate original Draw GUI pass (event 8/subtype 65).
        let mut gui_ids = Vec::new();
        for (&id, i) in &self.instances {
            if i.alive && i.active && !i.external {
                if let Some(o) = b.objects.iter().find(|o| o.id == i.object) {
                    if o.events.iter().any(|e| e.event_type == 8 && e.subtype == 65) {
                        gui_ids.push((i.fields.get("depth").copied().unwrap_or(o.depth as f64), id));
                    }
                }
            }
        }
        gui_ids.sort_by(|a, b| b.0.total_cmp(&a.0).then(a.1.cmp(&b.1)));
        self.draw_phase = DrawPhase::Gui;
        let result = (|| {
            for (depth, id) in gui_ids {
                self.draw_depth_context = Some(depth);
                self.dispatch(b, id, 8, 65)?;
            }
            Ok(())
        })();
        self.draw_phase = DrawPhase::Room;
        self.draw_depth_context = None;
        result
    }
    /// GMS precise-mask point test. Transforms the room point through the
    /// inverse of the draw pipeline — translate to the instance position,
    /// undo `image_angle` (clockwise on the y-down screen), undo scale, then
    /// re-add the sprite origin — and samples the instance's current-frame
    /// collision mask. Returns None when the sprite carries no mask data
    /// (fixtures wiring only `sprite_bounds`), letting callers fall back to
    /// the bounding-box answer.
    fn mask_hit(&self, tid: i32, px: f64, py: f64) -> Option<bool> {
        let inst = self.instances.get(&tid)?;
        let spr = inst.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
        let masks = self.sprite_masks.get(&spr)?;
        let frame = inst.fields.get("image_index").copied().unwrap_or(0.0);
        let mask = masks.get(if frame < 0.0 {
            0usize
        } else {
            (frame as usize).min(masks.len() - 1)
        })?;
        let ix = inst.fields.get("x").copied().unwrap_or(0.0);
        let iy = inst.fields.get("y").copied().unwrap_or(0.0);
        let sx = inst.fields.get("image_xscale").unwrap_or(&1.0).clone();
        let sy = inst.fields.get("image_yscale").unwrap_or(&1.0).clone();
        if sx == 0.0 || sy == 0.0 { return Some(false); }
        let ang = inst.fields.get("image_angle").copied().unwrap_or(0.0).to_radians();
        let (ox, oy) = self
            .sprite_bounds
            .get(&spr)
            .map(|b| (b.origin_x, b.origin_y))
            .unwrap_or((0.0, 0.0));
        let dx = px - ix;
        let dy = py - iy;
        let ca = ang.cos();
        let sa = ang.sin();
        // Inverse rotation (transpose), then un-scale, then origin offset.
        let rx = dx * ca + dy * sa;
        let ry = -dx * sa + dy * ca;
        let lx = (rx / sx).floor() + ox;
        let ly = (ry / sy).floor() + oy;
        Some(mask.pixel(lx as i32, ly as i32))
    }
    /// Walk a room-space line through `tid`'s mask at half-pixel resolution.
    /// `Some(true)` any mask pixel touches the line; `Some(false)` none do;
    /// None = no mask data (bbox fallback).
    fn line_mask_hit(&self, tid: i32, x1: f64, y1: f64, x2: f64, y2: f64) -> Option<bool> {
        let len = ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)).sqrt();
        let steps = ((len * 2.0).ceil() as usize).clamp(1, 4000);
        for s in 0..=steps {
            let t = s as f64 / steps as f64;
            match self.mask_hit(tid, x1 + (x2 - x1) * t, y1 + (y2 - y1) * t) {
                None => return None,
                Some(true) => return Some(true),
                Some(false) => {}
            }
        }
        Some(false)
    }
    fn self_field(&self,id:i32,n:&str)->Result<f64,String> {
        if n == "id" { return Ok(id as f64); }
        // GMS read-only sprite metadata: frame count of the instance's current
        // sprite_index straight from the original SPRT record.
        if n == "image_number" || n == "image_single" {
            let i = self.instances.get(&id).ok_or(format!("missing instance {id}"))?;
            let spr = i.fields.get("sprite_index").copied().unwrap_or(-1.0) as i32;
            return Ok(self.sprite_bounds.get(&spr).map_or(0.0, |b| b.frames));
        }
        // GMS 1.4 semantics: reading an uninitialized instance variable
        // yields 0, never an error. A missing instance, however, is a real
        // scheduling bug and must stay loud.
        match self.instances.get(&id) {
            Some(i) => Ok(i.fields.get(n).copied().unwrap_or(0.0)),
            None => Err(format!("missing instance {id}")),
        }
    }
    fn draw(&mut self,b:&Bundle,id:i32,args:&[f64])->Result<(),String> {
        let fogged = self.fog_enabled;
        let color = if fogged {
            self.fog_color
        } else {
            int(args[7])?
        };
        self.draws.push(DrawCommand{code:self.site.0,offset:self.site.1,instance:id,view:self.view,
            sprite:int(args[0])?,frame:args[1],x:args[2],y:args[3],scale_x:args[4],scale_y:args[5],
            rotation:args[6],color,alpha:args[8],fog:fogged});
        self.record_draw(b, id, DrawQueue::Sprite(self.draws.len() - 1));
        Ok(())
    }
    /// Text behind a pooled string reference: the bundle's string table first,
    /// then this scene's runtime entries (`string()`/`string_format()` results).
    fn pool_text(&self, b: &Bundle, v: f64) -> Option<String> {
        let idx = pool_index(v)?;
        if idx < b.string_table.len() { return b.string_table.get(idx).cloned(); }
        self.dynamic_strings.get(idx - b.string_table.len()).cloned()
    }
    /// Store a runtime-built string and hand back a fresh reference.
    pub fn alloc_string(&mut self, b: &Bundle, text: String) -> f64 {
        self.dynamic_strings.push(text);
        STRING_REF_BASE + (b.string_table.len() + self.dynamic_strings.len() - 1) as f64
    }
    /// A string argument as text: pooled references resolve, plain numbers
    /// render the way GMS renders them (`string()` / implicit coercion).
    fn arg_text(&self, b: &Bundle, v: f64) -> String {
        self.pool_text(b, v).unwrap_or_else(|| gm_real_text(v))
    }
    /// Strict selection with GM variable-access semantics: active instances
    /// first (event semantics); when none match, alive-only matching — GM's
    /// variable access reaches deactivated instances (a deactivated
    /// obj_player still answers `obj_player.x`), only the event scheduler
    /// ignores them.
    fn select_for_access(&self, id: i32, s: i32) -> Vec<i32> {
        if s < 0 {
            return self.select(id, s).unwrap_or_default();
        }
        let strict = self.select(id, s).unwrap_or_default();
        if !strict.is_empty() {
            return strict;
        }
        self.instances.iter().filter(|(key, i)| {
            if !i.alive { return false; }
            if s >= 100000 {
                **key == s
            } else if i.object == s {
                true
            } else {
                self.object_parents.get(&i.object).map_or(false, |c| c.contains(&s))
            }
        }).map(|(id, _)| *id).collect()
    }
}
include!("parts/host_impl.rs");
