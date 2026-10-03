//! Cally's Caves 2 - Native 64-bit client (Rust)
//!
//! On Android, the Java `MainActivity` calls the JNI functions exposed
//! at the bottom of this file. The library has no SDL2 / GLES
//! dependency on Android - it draws into a software ABGR pixel buffer
//! that the Java side uploads to a `TextureView` once per frame.
//!
//! On desktop, run the `callys-client` binary which uses SDL2.

use std::collections::{HashMap, HashSet, VecDeque};
use std::fmt;
use std::fs::{self, OpenOptions};
use std::io::Write;
use std::path::{Path, PathBuf};
use std::time::{Instant, SystemTime, UNIX_EPOCH};

use callys_asset::{GameDroidAsset, SpriteData, TpagItem};
use callys_core::save::{SaveData, SaveError};
use callys_core::{Facing, GameWorld, InputState, PlayerState, WeaponType};
use image::RgbaImage;

include!("parts/save.rs");
include!("parts/audio.rs");
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
    pub atlases: Vec<RgbaImage>,
    pub save_path: Option<PathBuf>,
    pub save_diagnostic: Option<String>,
    /// First fatal IR error. Execution stays halted: failed events can have
    /// partial side effects and must not be retried or fall back to legacy logic.
    pub runtime_diagnostic: Option<String>,
    /// Last IR snapshot written to disk; dedupes autosave comparisons.
    ir_saved_snapshot: Option<SaveData>,
    /// Boot-time IR snapshot held until the prologue hands over. The original
    /// boot always plays the prologue over rm_town (CODE 17 spawns the intro);
    /// restoring while the intro is alive would fight its deactivate-all and
    /// re-run Create/Room Start under a half-active room.
    pending_ir_restore: Option<SaveData>,
    pub sound_catalog: SoundCatalog,
    /// (sound id, looping, is_stop) — looping is the original bytecode's third
    /// audio_play_sound argument; is_stop marks audio_stop_sound/stop_all so
    /// the host can tear down MediaPlayer BGM, not just start new sounds.
    sound_queue: VecDeque<(usize, bool, bool)>,
    /// Platform haptic events: 1 jump, 2 fire, 3 impact, 4 death/explode,
    /// 5 coin, 6 weapon pickup. This is intentionally separate from audio IDs.
    haptic_queue: VecDeque<i32>,
    jump_was_active: bool,
    pub intro_scene: Option<callys_core::ir_scene::Scene>,
    pub intro_bundle: Option<std::sync::Arc<callys_core::code_vm::Bundle>>,
    pub scene: Option<callys_core::ir_scene::Scene>,
    pub full_bundle: Option<std::sync::Arc<callys_core::code_vm::Bundle>>,
    /// Previous frame's physical state of the five virtual devices, so
    /// `pressed`/`released` stay single-frame edges (device_mouse_check_button_
    /// pressed/_released semantics) even when a scene's own `mouse_clear` wipes
    /// the device state mid-tick.
    touch_prev: [bool; 5],
    /// Latches the platform tap pulse to one frame: Java holds `tap` high for a
    /// few frames, the original `mouse_check_button_pressed(mb_left)` lasts one.
    tap_was_active: bool,
    /// Primary-pointer release published by the platform this frame
    /// (`nativePointerRelease`). The original runner's first touch is device 0,
    /// so Draw-time `device_mouse_check_button_released(0, mb_left)` checks
    /// (obj_lloydtutorial1..16, obj_weaponswap) answer to a real tap anywhere.
    primary_release: Option<(f64, f64)>,
    /// Explicit fallback tracking so tests and production logs can warn when
    /// the handwritten GameWorld fallback runs instead of compiled bytecode.
    pub fallback_warned: bool,
}

impl GameState {
    pub fn new(droid_path: &Path) -> Result<Self, Box<dyn std::error::Error>> {
        Self::new_with_save_path(droid_path, None)
    }

    pub fn new_persistent(droid_path: &Path) -> Result<Self, Box<dyn std::error::Error>> {
        Self::new_with_save_path(droid_path, Some(save_path_for_asset(droid_path)))
    }

    pub fn new_with_save_path(
        droid_path: &Path,
        save_path: Option<PathBuf>,
    ) -> Result<Self, Box<dyn std::error::Error>> {
        let asset = GameDroidAsset::parse(droid_path)?;
        let (loaded_save, save_diagnostic) = match save_path
            .as_deref()
            .map(load_save_with_legacy_migration)
        {
            Some(Ok(result)) => result,
            Some(Err(error)) => {
                let diagnostic = Some(error.to_string());
                return Self::finish_initialization(asset, droid_path, save_path, None, diagnostic);
            }
            None => (None, None),
        };
        Self::finish_initialization(
            asset,
            droid_path,
            save_path,
            loaded_save,
            save_diagnostic,
        )
    }

    fn finish_initialization(
        asset: GameDroidAsset,
        droid_path: &Path,
        save_path: Option<PathBuf>,
        loaded_save: Option<SaveData>,
        mut save_diagnostic: Option<String>,
    ) -> Result<Self, Box<dyn std::error::Error>> {
        let mut world = GameWorld::new();
        let requested_room = loaded_save.as_ref().map(|save| save.current_room).unwrap_or(0);
        let room_index = if requested_room < asset.rooms.len() {
            requested_room
        } else {
            save_diagnostic = Some(format!(
                "save room index {requested_room} is outside available room count {}",
                asset.rooms.len()
            ));
            0
        };
        if room_index == requested_room {
            if let Some(save) = loaded_save.as_ref() {
                // Restore collected ROOM identities before materializing the room so
                // already-collected instances are filtered during load.
                world.restore_from_save(save);
            }
        }
        if let Some(room) = asset.rooms.get(room_index) {
            world.load_room(
                room_index,
                room,
                &asset.objects,
                &asset.sprites,
                &asset.warp_targets,
            );
        }
        if room_index == requested_room {
            if let Some(save) = loaded_save.as_ref() {
                // Room instances establish geometry and sprite IDs first; restore
                // persistent player/checkpoint fields afterwards so their coordinates
                // cannot be overwritten by obj_player.
                world.restore_from_save(save);
            }
        }
        let mut atlases = Vec::new();
        let parent = droid_path.parent().unwrap_or_else(|| Path::new("."));
        let texture_dirs = [parent.join("textures"), Path::new("assets/textures").to_path_buf()];
        for index in 0..16 {
            let mut loaded = None;
            for dir in &texture_dirs {
                let path = dir.join(format!("texture_{index}.png"));
                if path.is_file() {
                    loaded = Some(image::open(path)?.to_rgba8());
                    break;
                }
            }
            match loaded {
                Some(atlas) => atlases.push(atlas),
                None => break,
            }
        }
        let sound_catalog = SoundCatalog::from_asset(&asset)?;
        Ok(Self {
            asset,
            world,
            input: InputState::default(),
            frame_count: 0,
            started_at: Instant::now(),
            rooms_visited: 1,
            atlases,
            save_path,
            save_diagnostic,
            runtime_diagnostic: None,
            ir_saved_snapshot: None,
            sound_catalog,
            sound_queue: VecDeque::new(),
            haptic_queue: VecDeque::new(),
            jump_was_active: false,
            intro_scene: None,
            intro_bundle: None,
            pending_ir_restore: None,
            scene: None,
            full_bundle: None,
            touch_prev: [false; 5],
            tap_was_active: false,
            primary_release: None,
            fallback_warned: false,
        })
    }

    /// Calculates the camera origin for the runtime-selected GameMaker view.
    /// The indexed ROOM record supplies its view rect and follow target; GML's
    /// `view_visible[]` array, not the ROOM editor's original bit, selects it.
    pub fn camera_position_for_scene(scene: &callys_core::ir_scene::Scene) -> (f64, f64) {
        if let Some(view_index) = scene.active_view_index() {
            if let Some(v) = scene.room_views.get(view_index) {
                if v.object >= 0 {
                    // GM's view follow only sees instances the scheduler
                    // processes: while the prologue deactivates the player,
                    // the view stays at the room's view rect — the intro film
                    // is composed against that rect (phone at y≈-2).
                    if let Some((px, py)) = scene
                        .instances
                        .values()
                        .find(|i| i.object == v.object && i.alive && i.active)
                        .and_then(|i| Some((i.fields.get("x").copied()?, i.fields.get("y").copied()?)))
                    {
                        let half_w = v.wview as f64 / 2.0;
                        let half_h = v.hview as f64 / 2.0;
                        let hb = (v.hborder as f64).min(half_w);
                        let vb = (v.vborder as f64).min(half_h);
                        let center_x = v.xview as f64 + half_w;
                        let center_y = v.yview as f64 + half_h;
                        let mut cx = center_x;
                        let mut cy = center_y;
                        if (px - center_x).abs() > hb {
                            cx = if px > center_x + hb { px - hb } else { px + hb };
                        }
                        if (py - center_y).abs() > vb {
                            cy = if py > center_y + vb { py - vb } else { py + vb };
                        }
                        let vx = (cx - half_w).clamp(0.0, (scene.room_width - v.wview as f64).max(0.0));
                        let vy = (cy - half_h).clamp(0.0, (scene.room_height - v.hview as f64).max(0.0));
                        return (vx, vy);
                    }
                }
                // A view without a live follow target remains at its ROOM/GML
                // camera position instead of silently following the player.
                return (v.xview as f64, v.yview as f64);
            }
        }
        let (px, py) = scene
            .instances
            .values()
            .find(|i| i.object == 0 && i.alive)
            .and_then(|i| Some((i.fields.get("x").copied()?, i.fields.get("y").copied()?)))
            .unwrap_or((480.0, 270.0));
        let cam_x = (px - 480.0).clamp(0.0, (scene.room_width - 960.0).max(0.0));
        let cam_y = (py - 270.0).clamp(0.0, (scene.room_height - 540.0).max(0.0));
        (cam_x, cam_y)
    }

    /// Transitions gameplay directly into the full data-driven IR scene
    /// backed by the original GameMaker bytecode and room records.
    /// Restores an IR-path snapshot before enabling gameplay. Room data and
    /// the bundle come from this state; globals/score/collected from the file.
    pub fn restore_ir_snapshot(&mut self, save: &SaveData) -> Result<(), String> {
        let bundle = self.full_bundle.clone()
            .ok_or_else(|| "restore before IR bundle load".to_string())?;
        let room_id = save.current_room.min(self.asset.rooms.len().saturating_sub(1));
        let room = self.asset.rooms.get(room_id)
            .ok_or_else(|| format!("save room {room_id} outside room table"))?;
        {
            let scene = self.scene.as_mut()
                .ok_or_else(|| "restore before IR scene load".to_string())?;
            scene.restore_snapshot(
                bundle.as_ref(), room_id, room,
                &save.scene_globals, save.score, &save.collected_instance_ids,
            )?;
        }
        self.ir_saved_snapshot = Some(save.clone());
        Ok(())
    }

    /// Persists the IR scene snapshot when progression changed. Runs after
    /// successful frames only; a failed frame leaves the last good file.
    fn autosave_ir(&mut self) {
        if self.save_path.is_none() || self.runtime_diagnostic.is_some() {
            return;
        }
        let Some(scene) = self.scene.as_ref() else { return; };
        let (room, globals, score, collected) = scene.save_snapshot();
        if !globals.is_empty() || score != 0.0 || !collected.is_empty() || room != 0 {
            let save = SaveData {
                format_version: callys_core::save::CURRENT_SAVE_VERSION,
                current_room: room,
                checkpoint: callys_core::Checkpoint { room_index: room, x: 0.0, y: 0.0 },
                max_health: 4,
                gems: 0,
                coins: 0,
                current_weapon: callys_core::WeaponType::Pistol,
                unlocked_weapons: vec![callys_core::WeaponType::Pistol],
                collected_instance_ids: collected,
                scene_globals: globals,
                score,
            };
            if self.ir_saved_snapshot.as_ref() == Some(&save) {
                return;
            }
            if let Some(path) = self.save_path.as_deref() {
                self.save_diagnostic = write_save_atomic(path, &save)
                    .err()
                    .map(|error| error.to_string());
                if self.save_diagnostic.is_none() {
                    self.ir_saved_snapshot = Some(save);
                }
            }
        }
    }

    /// Boot-time restore queueing (nativeInit and tests share this entry):
    /// a v2 save with scene progress is held until the prologue handover.
    /// Returns true when a restore was queued.
    pub fn queue_boot_ir_restore(&mut self) -> bool {
        let Some(save_path) = self.save_path.clone() else { return false };
        match load_save(&save_path) {
            Ok(Some(save)) if !save.scene_globals.is_empty() => {
                self.pending_ir_restore = Some(save);
                true
            }
            _ => false,
        }
    }

    /// Test seam: queue an explicit snapshot for the prologue handover without
    /// going through the save file.
    pub fn queue_boot_ir_restore_with(&mut self, save: SaveData) -> bool {
        if save.scene_globals.is_empty() {
            return false;
        }
        self.pending_ir_restore = Some(save);
        true
    }

    /// Test fixture: retires the prologue intro through its REAL Destroy event
    /// (CODE 549 — the same code a device tap triggers): instance_activate_all,
    /// global.health1=4, phone/logo cleanup. Scene-level tests that tick the
    /// scene directly need this because the intro's Create has deactivated the
    /// whole room, and the original event scheduler ignores inactive
    /// instances. Full-frame tests should drive `state.step` + a tap instead.
    pub fn retire_prologue(&mut self) {
        let Some(bundle) = self.full_bundle.clone() else { return };
        let intro = self.scene.as_ref().and_then(|s| {
            s.instances.iter().find(|(_, i)| i.object == 137 && i.alive).map(|(&id, _)| id)
        });
        if let Some(id) = intro {
            let _ = self.scene.as_mut().unwrap().destroy(bundle.as_ref(), id);
        }
        if let Some(scene) = self.scene.as_mut() {
            scene.end_frame();
        }
    }

    pub fn enable_ir_gameplay(&mut self, mut bundle: std::sync::Arc<callys_core::code_vm::Bundle>) -> Result<(), String> {
        if bundle.string_table.is_empty() && !self.asset.string_table.is_empty() {
            let mut b = (*bundle).clone();
            b.string_table = self.asset.string_table.clone();
            bundle = std::sync::Arc::new(b);
        }
        let mut scene = callys_core::ir_scene::Scene::default();
        scene.init_bundle(&bundle);
        scene.init_fresh_start_globals();
        // init_bundle already seeds persistent_objects from the IR's
        // persistent flags (asset-verified: obj_player(0), obj_music(68)).
        // Re-seed from the parsed asset as a defensive union in case an older
        // IR file lacks the field: insert is idempotent.
        for obj in &self.asset.objects {
            if obj.persistent {
                scene.persistent_objects.insert(obj.id as i32);
            }
        }
        // Real INI boundary: the original CODE 17 reads savefile{,2,3}.ini from
        // the game's files directory. Without a save path (tests) the INIs stay
        // the in-memory cache.
        scene.ini_disk_dir = self
            .save_path
            .as_deref()
            .and_then(|p| p.parent().map(std::path::Path::to_path_buf));
        for (sid, sp) in &self.asset.sprites {
            scene.sprite_bounds.insert(
                *sid as i32,
                callys_core::ir_scene::SpriteBounds {
                    width: sp.width as f64,
                    height: sp.height as f64,
                    origin_x: sp.origin_x as f64,
                    origin_y: sp.origin_y as f64,
                    frames: sp.tpag_indices.len().max(1) as f64,
                },
            );
            if !sp.masks.is_empty() {
                scene.sprite_masks.insert(*sid as i32, sp.masks.clone());
            }
        }
        // Original boot room: rm_town whenever a boot-time IR restore is
        // queued (the prologue always plays over town; the saved room enters
        // through the handover transition). Without one, keep the world's
        // room (legacy v1 saves boot where the world path says).
        let current_room = if self.pending_ir_restore.is_some() {
            0
        } else {
            self.world.current_room_index
        };
        if let Some(room_data) = self.asset.rooms.get(current_room) {
            // Original first-room order: the room's instances are materialized
            // first (Create events run as each instance is placed), and only
            // then does Game Start (Event 7/2, CODE 17) fire. CODE 17 reads the
            // three INIs, derives every weapon damage ladder, and spawns
            // obj_introduction itself; CODE 548 then deactivates every other
            // instance, so the room waits behind the intro film. Dispatching
            // Game Start *before* the room load left all ~170 room instances
            // (and the touch buttons) ACTIVE through the prologue — the intro
            // film's phone/logo were composed against a view the live town kept
            // dragging away.
            scene.load_room_from_data(&bundle, current_room, room_data)?;
            let player_id = scene
                .instances
                .iter()
                .find(|(_, i)| i.object == 0 && i.alive)
                .map(|(&id, _)| id);
            if let Some(pid) = player_id {
                let has_game_start = bundle.objects.iter().any(|o| {
                    o.id == 0 && o.events.iter().any(|e| e.event_type == 7 && e.subtype == 2)
                });
                if has_game_start {
                    scene.dispatch(&bundle, pid, 7, 2)
                        .map_err(|e| format!("Game Start (CODE 17): {e}"))?;
                }
            }
            // Room Start (Event 7, Subtype 4) reaches ACTIVE instances only:
            // the original engine never processes deactivated instances, and
            // CODE 548 has already deactivated everyone but the intro film.
            let initial_ids: Vec<i32> = scene.instances.iter()
                .filter(|(_, i)| i.alive && i.active && !i.external)
                .map(|(&id, _)| id)
                .collect();
            for id in initial_ids {
                scene.dispatch(&bundle, id, 7, 4)
                    .map_err(|e| format!("Room Start instance {id}: {e}"))?;
            }
        }
        self.scene = Some(scene);
        self.full_bundle = Some(bundle);
        // Fresh scene: no physical edge from the previous one may leak into it.
        self.touch_prev = [false; 5];
        self.primary_release = None;
        Ok(())
    }

    /// Map renderer logical-screen coordinates through the last-presented
    /// runtime-selected view into room world coordinates.
    pub fn screen_to_world(&self, x: f64, y: f64) -> (f64, f64) {
        if let Some(scene) = self.scene.as_ref() {
            if let Some(view_index) = scene.active_view_index() {
                if let Some(view) = scene.room_views.get(view_index) {
                    let (origin_x, origin_y) = scene
                        .view_positions
                        .get(&(view_index as i32))
                        .copied()
                        .unwrap_or((view.xview as f64, view.yview as f64));
                    if view.wview > 0 && view.hview > 0 {
                        let offset_x = x * (view.wview as f64 / scene.display_width.max(1.0));
                        let offset_y = y * (view.hview as f64 / scene.display_height.max(1.0));
                        return (origin_x + offset_x, origin_y + offset_y);
                    }
                    return (origin_x + x, origin_y + y);
                }
            }
            let (cam_x, cam_y) = Self::camera_position_for_scene(scene);
            (cam_x + x, cam_y + y)
        } else {
            (x, y)
        }
    }

    /// Queue an actual press in the renderer's 960x540 logical viewport.
    /// Uses the last presented view origin, not a newly moved camera.
    pub fn pointer_pressed(&mut self, x: f64, y: f64) {
        if self.runtime_diagnostic.is_some() || !x.is_finite() || !y.is_finite()
            || !(0.0..960.0).contains(&x) || !(0.0..540.0).contains(&y) {
            return;
        }
        let (world_x, world_y) = self.screen_to_world(x, y);
        if let Some(scene) = self.scene.as_mut() {
            scene.left_presses.push((world_x, world_y));
        }
    }

    /// Queue an actual release in the renderer's 960x540 logical viewport.
    /// Uses the last presented view origin, not a newly moved camera.
    /// The release also lands on virtual device 0: the original runner's first
    /// touch is device 0, so Draw-time `device_mouse_check_button_released(0,
    /// mb_left)` checks (the Lloyd tutorial sheets, obj_weaponswap) see a real
    /// tap anywhere rather than only the lower-left movement zone.
    pub fn pointer_released(&mut self, x: f64, y: f64) {
        if self.runtime_diagnostic.is_some() || !x.is_finite() || !y.is_finite()
            || !(0.0..960.0).contains(&x) || !(0.0..540.0).contains(&y) {
            return;
        }
        // During the prologue the release still lands on the intro (its Step
        // taps the tap), but the gameplay device-0 edge stays latched off so
        // the handover frame cannot see a phantom tap.
        let intro = self
            .scene
            .as_ref()
            .is_some_and(|s| s.instances.values().any(|i| i.object == 137 && i.alive));
        let (world_x, world_y) = self.screen_to_world(x, y);
        if let Some(scene) = self.scene.as_mut() {
            scene.left_releases.push((world_x, world_y));
            if !intro {
                self.primary_release = Some((world_x, world_y));
            }
        }
    }

    pub fn step(&mut self, dt: f32) {
        if self.runtime_diagnostic.is_some() {
            return;
        }
        if let Err(error) = self.step_inner(dt) {
            let diagnostic = format!("frame {}: {error}", self.frame_count);
            eprintln!("IR execution halted: {diagnostic}");
            self.runtime_diagnostic = Some(diagnostic);
        }
    }

    fn step_inner(&mut self, dt: f32) -> Result<(), String> {
        // Prologue phase: obj_introduction (137) lives inside the FULL scene —
        // the original Game Start (CODE 17) spawns it there and its Create
        // deactivates the room behind it. Same frame contract the old separate
        // intro scene had: any attack/jump/tap input is the mb_left tap the
        // intro's Step reads; draws go through an explicit view pass or the
        // framebuffer stays black.
        if let (Some(bundle), Some(scene)) = (self.full_bundle.as_deref(), self.scene.as_mut()) {
            let intro_alive = scene.instances.values().any(|i| i.object == 137 && i.alive);
            if intro_alive {
                scene.mouse_pressed = self.input.attack || self.input.jump || self.input.tap;
                scene.tick(bundle).map_err(|e| format!("intro tick room {}: {e}", scene.current_room))?;
                // Draw events are dispatched by the runtime-enabled view, which
                // may differ from every ROOM record's original `visible` bit.
                let view = scene.active_view_index().ok_or_else(|| {
                    format!("no visible view for intro room {}", scene.current_room)
                })?;
                let (cam_x, cam_y) = Self::camera_position_for_scene(scene);
                scene.view_positions.insert(view as i32, (cam_x, cam_y));
                scene.draw_view(bundle, view as i32).map_err(|e| format!("intro draw room {}: {e}", scene.current_room))?;
                scene.end_frame();
                // Stop commands precede plays: the original bytecode stops the old
                // BGM before starting the new one; reversing this order would have
                // MediaPlayer kill the freshly started track.
                for stopped_sound in scene.take_stop_commands() {
                    self.sound_queue.push_back((stopped_sound.max(0.0) as usize, false, true));
                }
                let mut prologue_haptics = Vec::new();
                for command in scene.drain_audio() {
                    if let Some(haptic) = Self::haptic_for_sound(command.sound) {
                        prologue_haptics.push(haptic);
                    }
                    self.sound_queue.push_back((command.sound.max(0) as usize, command.looping, false));
                }
                let still_alive = scene.instances.values().any(|i| i.object == 137 && i.alive);
                if still_alive {
                    self.haptic_queue.extend(prologue_haptics);
                    return Ok(());
                }
                // Handover: the intro's Destroy ran instance_activate_all, so the
                // room continues in this same scene from the next frame. The tap
                // that killed the intro must not leak into gameplay as a phantom
                // device-0 release (the old re-enable path cleared these too).
                self.primary_release = None;
                self.touch_prev = [false; 5];
                self.haptic_queue.extend(prologue_haptics);
                // A boot-time IR snapshot restore waits for this handover: the
                // original boot always plays the prologue over rm_town; the
                // saved room loads only once the intro is gone.
                if let Some(save) = self.pending_ir_restore.take() {
                    self.restore_ir_snapshot(&save)
                        .map_err(|e| format!("handover restore: {e}"))?;
                }
                return Ok(());
            }
        }
        // Note: pending_ir_restore is applied only on the intro handover above.
        // If the bundle never loaded, nativeInit already dropped the queue, so
        // a missing full_ir.json still falls through to the legacy world path.

        // Full IR scene gameplay loop
        let mut gameplay_haptics = Vec::new();
        if let (Some(bundle), Some(scene)) = (self.full_bundle.as_deref(), self.scene.as_mut()) {
            let (cam_x, cam_y) = Self::camera_position_for_scene(scene);

            // mb_left: the runner's global primary-pointer press. obj_foundweapon
            // CODE 407 (the "You have found the ..." banner) and
            // obj_weaponchange read `mouse_check_button_pressed(mb_left)` from a
            // Step event, so this must be published before the tick, and both
            // banner systems freeze the world until it arrives. Latched to one
            // frame: Java holds its tap pulse for a few frames, the original edge
            // lasts exactly one.
            scene.mouse_pressed = self.input.tap && !self.tap_was_active;

            // Virtual devices. The original button objects test every one of the
            // four devices against their own hit box in their Draw event, so the
            // triple (position, down, pressed/released) is the whole input
            // contract. Edges are single-frame: down -> pressed, up -> released.
            let held = [
                self.input.move_left,
                self.input.move_right,
                self.input.jump,
                self.input.attack,
                self.input.sword,
            ];
            let zones = [
                (cam_x + 30.0, cam_y + 220.0),
                (cam_x + 130.0, cam_y + 220.0),
                (cam_x + 410.0, cam_y + 220.0),
                (cam_x + 345.0, cam_y + 220.0),
                (cam_x + 440.0, cam_y + 175.0),
            ];
            // A real primary-pointer release belongs to device 0 - the original
            // runner's first touch - carrying its real logical coordinates, so
            // the Lloyd tutorial sheets (obj_lloydtutorial1..16) and
            // obj_weaponswap answer to a tap anywhere on the screen.
            let primary_release = self.primary_release.take();
            for (index, ((x, y), is_held)) in zones.iter().zip(held).enumerate() {
                if index == 0 && primary_release.is_some() {
                    let (px, py) = primary_release.unwrap();
                    let device = &mut scene.touch_devices[0];
                    device.x = px;
                    device.y = py;
                    device.down = false;
                    device.pressed = false;
                    device.released = true;
                    self.touch_prev[0] = false;
                    continue;
                }
                let device = &mut scene.touch_devices[index];
                device.x = *x;
                device.y = *y;
                device.down = is_held;
                device.pressed = is_held && !self.touch_prev[index];
                device.released = !is_held && self.touch_prev[index];
                self.touch_prev[index] = is_held;
            }
            self.tap_was_active = self.input.tap;

            scene.tick(bundle).map_err(|e| format!("gameplay tick room {}: {e}", scene.current_room))?;

            // drain_audio retires non-looping voices; a bare audio.drain here
            // would keep is_playing gates shut forever (SFX play once only).
            // Stop commands precede plays (see the intro-path comment).
            for stopped_sound in scene.take_stop_commands() {
                self.sound_queue.push_back((stopped_sound.max(0.0) as usize, false, true));
            }
            for command in scene.drain_audio() {
                if let Some(haptic) = Self::haptic_for_sound(command.sound) {
                    gameplay_haptics.push(haptic);
                }
                self.sound_queue.push_back((command.sound.max(0) as usize, command.looping, false));
            }

            if let Some(target_room) = scene.target_room_warp.take() {
                let source_room = scene.current_room;
                let next_room = self.asset.rooms.get(target_room).ok_or_else(||
                    format!("room transition {source_room} -> {target_room}: target outside room table"))?;
                scene.transition_to_room(bundle, target_room, next_room)
                    .map_err(|e| format!("room transition {source_room} -> {target_room}: {e}"))?;
                self.rooms_visited = self.rooms_visited.saturating_add(1);
            }

            let view = scene.active_view_index().ok_or_else(|| {
                format!("no visible view for gameplay room {}", scene.current_room)
            })?;
            let (cam_x, cam_y) = Self::camera_position_for_scene(scene);
            scene.view_positions.insert(view as i32, (cam_x, cam_y));
            scene.draw_view(bundle, view as i32).map_err(|e| format!("gameplay draw room {}: {e}", scene.current_room))?;
            // The frame's input edges were visible to this frame's Step, alarm,
            // collision and Draw events; retire them only now (see end_frame).
            scene.end_frame();

            self.frame_count = self.frame_count.wrapping_add(1);
            self.autosave_ir();
            self.haptic_queue.extend(gameplay_haptics);
            return Ok(());
        }
        if !self.fallback_warned {
            eprintln!("WARNING [FALLBACK]: IR scene not active; running legacy handwritten GameWorld. Content and behavior may differ from original GameMaker bytecode.");
            self.fallback_warned = true;
        }
        let progress_before = SaveData::from_world(&self.world);
        let player_state_before = self.world.player.state;
        let coins_before = self.world.player.coins;
        let pickups_before = self
            .world
            .weapon_pickups
            .iter()
            .filter(|pickup| pickup.collected)
            .count();
        let can_jump = self.world.player.on_ground || self.world.player_is_in_water();
        let jump_started = self.input.jump && !self.jump_was_active && can_jump;
        // Mirror GameWorld::update's early death guard as well as its attack
        // cooldown guard. An input attempt is not a shot when update returns
        // before reaching the firing branch.
        let fired_weapon = if self.world.player.health > 0
            && self.world.player.state != PlayerState::Dead
            && self.input.attack
            && self.world.player.attack_cooldown <= dt.max(0.0)
        {
            match self.world.player.current_weapon {
                WeaponType::Pistol => Some(SoundEvent::Pistol),
                WeaponType::Shotgun => Some(SoundEvent::Shotgun),
                _ => None,
            }
        } else {
            None
        };
        self.jump_was_active = self.input.jump;
        self.world.update(dt, &self.input);
        if jump_started {
            self.queue_sound(SoundEvent::Jump);
        }
        if let Some(event) = fired_weapon {
            self.queue_sound(event);
        }
        for _ in coins_before..self.world.player.coins {
            self.queue_sound(SoundEvent::Coin);
        }
        let pickups_after = self
            .world
            .weapon_pickups
            .iter()
            .filter(|pickup| pickup.collected)
            .count();
        for _ in pickups_before..pickups_after {
            self.queue_sound(SoundEvent::WeaponPickup);
        }
        if player_state_before != PlayerState::Dead
            && self.world.player.state == PlayerState::Dead
        {
            self.queue_sound(SoundEvent::Death);
        }
        if let Some(target) = self.world.pending_room_warp.take() {
            let spawn = self.world.pending_spawn.take();
            if let Some(next) = self.asset.rooms.get(target) {
                self.world.load_room(
                    target,
                    next,
                    &self.asset.objects,
                    &self.asset.sprites,
                    &self.asset.warp_targets,
                );
                if let Some((x, y, facing)) = spawn {
                    self.world.player.x = x;
                    self.world.player.y = y;
                    self.world.player.vx = 0.0;
                    self.world.player.vy = 0.0;
                    self.world.player.facing = facing;
                    self.world.checkpoint = callys_core::Checkpoint {
                        room_index: target,
                        x,
                        y,
                    };
                }
                self.rooms_visited = self.rooms_visited.saturating_add(1);
            }
        }
        let progress_after = SaveData::from_world(&self.world);
        if progress_after != progress_before {
            if let Some(path) = self.save_path.as_deref() {
                self.save_diagnostic = write_save_atomic(path, &progress_after)
                    .err()
                    .map(|error| error.to_string());
            }
        }
        self.frame_count = self.frame_count.wrapping_add(1);
        Ok(())
    }

    fn haptic_for_sound(sound: i32) -> Option<i32> {
        match sound {
            3 => Some(1),          // jump
            10 | 11 => Some(2),    // pistol/shotgun fire
            23 | 24 => Some(3),    // impact sounds
            7 | 8 | 26 => Some(4),  // explosion/death
            19 | 20 => Some(5),     // coin pickup
            27 => Some(6),         // weapon pickup
            _ => None,
        }
    }

    fn queue_sound(&mut self, event: SoundEvent) {
        let sound = self.sound_catalog.audio_id(event);
        if let Some(haptic) = Self::haptic_for_sound(sound as i32) {
            self.haptic_queue.push_back(haptic);
        }
        self.sound_queue.push_back((sound, false, false));
    }

    pub fn poll_sound(&mut self) -> Option<(usize, bool, bool)> {
        self.sound_queue.pop_front()
    }

    pub fn poll_haptic(&mut self) -> Option<i32> {
        self.haptic_queue.pop_front()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn game_droid_path() -> PathBuf {
        Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid")
    }

    #[test]
    fn real_sound_names_map_events_to_audo_ids() {
        let asset = GameDroidAsset::parse(game_droid_path()).unwrap();
        let catalog = SoundCatalog::from_asset(&asset).unwrap();

        assert_eq!(catalog.audio_id(SoundEvent::Jump), 3);
        assert_eq!(catalog.audio_id(SoundEvent::Pistol), 10);
        assert_eq!(catalog.audio_id(SoundEvent::Shotgun), 11);
        assert_eq!(catalog.audio_id(SoundEvent::Coin), 19);
        assert_eq!(catalog.audio_id(SoundEvent::Death), 26);
        assert_eq!(catalog.audio_id(SoundEvent::WeaponPickup), 27);
    }

    #[test]
    fn accepted_jump_is_queued_once_while_input_is_held() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.world.solids.clear();
        state.world.platforms.clear();
        state.world.player.on_ground = true;
        state.input.jump = true;

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some((3, false, false)));
        assert_eq!(state.poll_sound(), None);

        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn successful_pistol_and_shotgun_shots_enqueue_once() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.input.attack = true;

        state.world.player.current_weapon = WeaponType::Pistol;
        state.step(0.0);
        assert_eq!(state.poll_sound(), Some((10, false, false)));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);

        state.world.player.attack_cooldown = 0.0;
        state.world.player.current_weapon = WeaponType::Shotgun;
        state.step(0.0);
        assert_eq!(state.poll_sound(), Some((11, false, false)));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn sound_events_queue_distinct_haptic_events() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.queue_sound(SoundEvent::Jump);
        state.queue_sound(SoundEvent::Pistol);
        state.queue_sound(SoundEvent::Coin);
        state.queue_sound(SoundEvent::WeaponPickup);
        assert_eq!(state.poll_haptic(), Some(1));
        assert_eq!(state.poll_haptic(), Some(2));
        assert_eq!(state.poll_haptic(), Some(5));
        assert_eq!(state.poll_haptic(), Some(6));
        assert_eq!(state.poll_haptic(), None);
    }

    #[test]
    fn dead_or_dying_player_does_not_enqueue_a_shot() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.input.attack = true;
        state.world.player.current_weapon = WeaponType::Pistol;
        state.world.player.health = 0;

        state.step(0.0);

        assert_eq!(state.poll_sound(), Some((26, false, false)));
        assert_eq!(state.poll_sound(), None);

        state.world.player.health = state.world.player.max_health;
        state.world.player.state = PlayerState::Dead;
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn collecting_a_coin_enqueues_once() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.world.gems.clear();
        state.world.gems.push(callys_core::GemDrop {
            x: state.world.player.x,
            y: state.world.player.y,
            is_coin: true,
            collected: false,
            sprite_id: -1,
            room_instance_id: None,
        });

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some((19, false, false)));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn collecting_a_weapon_enqueues_once() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.world.weapon_pickups.clear();
        state.world.weapon_pickups.push(callys_core::WeaponPickup {
            rect: callys_core::Rect::new(
                state.world.player.x,
                state.world.player.y,
                32.0,
                32.0,
            ),
            weapon: WeaponType::Shotgun,
            sprite_id: -1,
            collected: false,
            room_instance_id: None,
        });

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some((27, false, false)));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn death_transition_enqueues_once() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.world.player.health = 0;

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some((26, false, false)));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn required_wavs_are_exported_beside_game_droid_with_exact_bytes() {
        let asset = GameDroidAsset::parse(game_droid_path()).unwrap();
        let temp = tempfile::tempdir().unwrap();
        let droid_path = temp.path().join("game.droid");

        let exported = export_required_wavs(&asset, &droid_path).unwrap();

        assert_eq!(exported.len(), 6);
        let unique_audio_ids: HashSet<_> =
            exported.iter().map(|(audio_id, _)| *audio_id).collect();
        let unique_paths: HashSet<_> = exported.iter().map(|(_, path)| path).collect();
        assert_eq!(unique_audio_ids.len(), exported.len());
        assert_eq!(unique_paths.len(), exported.len());
        for (audio_id, path) in exported {
            assert_eq!(path.parent(), Some(temp.path().join("sfx").as_path()));
            assert_eq!(
                path.file_name().and_then(|name| name.to_str()),
                Some(format!("sound_{audio_id}.wav").as_str())
            );
            assert_eq!(fs::read(path).unwrap(), asset.audio[audio_id].wav_bytes);
        }
    }

    #[test]
    fn town_exit_enters_level1_and_death_returns_to_entry_checkpoint() {
        let droid = game_droid_path();
        let mut state = GameState::new(&droid).unwrap();
        let town_exit = state.world.warps.iter()
            .find(|warp| warp.creation_code == 804)
            .cloned()
            .expect("town exit 804");
        state.world.player.x = town_exit.rect.x;
        state.world.player.y = town_exit.rect.y;

        state.step(0.0);
        assert_eq!(state.world.current_room_name, "rm_level1");
        assert_eq!((state.world.player.x, state.world.player.y), (128.0, 492.0));
        assert_eq!(state.world.enemies.len(), 7);
        assert_eq!(state.world.weapon_pickups.len(), 1);
        assert_eq!(state.world.warps.len(), 2);
        assert_eq!(state.world.checkpoint.room_index, 1);

        state.world.player.health = 0;
        state.step(0.1);
        assert_eq!(state.world.player.state, PlayerState::Dead);
        state.step(1.1);
        assert_eq!(state.world.current_room_name, "rm_level1");
        assert_eq!((state.world.player.x, state.world.player.y), (128.0, 492.0));
        assert_eq!(state.world.player.health, state.world.player.max_health);
    }
}

pub fn current_time_ns() -> u64 {
    SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_nanos() as u64)
        .unwrap_or(0)
}

include!("parts/framebuffer.rs");

include!("parts/font.rs");

fn draw_sprite(fb: &mut Framebuffer, state: &GameState, sprite_id: i32, frame: usize, dst: (i32, i32, u32, u32), flip_x: bool) -> bool {
    draw_sprite_alpha(fb, state, sprite_id, frame, dst, flip_x, 1.0)
}

fn draw_sprite_alpha(fb: &mut Framebuffer, state: &GameState, sprite_id: i32, frame: usize, dst: (i32, i32, u32, u32), flip_x: bool, alpha: f32) -> bool {
    let Ok(sprite_id) = usize::try_from(sprite_id) else { return false; };
    let Some(sprite) = state.asset.sprites.get(&sprite_id) else { return false; };
    if sprite.tpag_indices.is_empty() { return false; }
    let frame_ptr = sprite.tpag_indices[frame % sprite.tpag_indices.len()] as usize;
    let Some(page) = state.asset.tpag_items.get(&frame_ptr) else { return false; };
    let Some(atlas) = state.atlases.get(page.tex_id as usize) else { return false; };
    fb.blit_scaled_alpha(atlas, (page.x as u32, page.y as u32, page.w as u32, page.h as u32), dst, flip_x, alpha);
    true
}

/// GM packs colours as 0xAABBGGRR (D3DCOLOR little-endian), so red is the low
/// byte. Values outside the 24-bit range are the original's own arithmetic and
/// not typos: `image_blend -= c_white` wraps through the int32 range on the
/// thaw frame (16711680 -> -65535, already pinned by the core enemy tests), and
/// the 4-argument `draw_sprite` default blend is -1. Both land back on a real
/// colour through the low 24 bits, which is how every other colour site in this
/// engine decodes them.
fn unpack_color(color: i32) -> (u8, u8, u8) {
    let v = (color as i64 & 0xFF_FFFF) as u32;
    ((v & 0xFF) as u8, ((v >> 8) & 0xFF) as u8, ((v >> 16) & 0xFF) as u8)
}

/// Consume one original DrawCommand into pixels: SPRT-origin anchoring, the
/// original's mirror (`image_xscale = -1`), `image_angle` rotation about that
/// origin, `image_blend` tint — or the fog flood when the original wrapped the
/// call in `d3d_set_fog(true, c, 0, 0)` (the hit-flash pipeline).
///
/// Returns false only when the sprite, its frame or its atlas page is missing,
/// so the caller can fall back to a placeholder; a command that is simply
/// invisible (alpha 0, zero scale) returns true with nothing drawn.
fn draw_ir_sprite(
    fb: &mut Framebuffer,
    state: &GameState,
    cmd: &callys_core::ir_scene::DrawCommand,
    cam: (f64, f64),
    screen_scale: (f32, f32),
) -> bool {
    let Ok(sprite_id) = usize::try_from(cmd.sprite) else { return false; };
    let Some(sprite) = state.asset.sprites.get(&sprite_id) else { return false; };
    if sprite.tpag_indices.is_empty() { return false; }
    let frame = cmd.frame.max(0.0) as usize % sprite.tpag_indices.len();
    let Some(page) = state.asset.tpag_items.get(&(sprite.tpag_indices[frame] as usize)) else { return false; };
    let Some(atlas) = state.atlases.get(page.tex_id as usize) else { return false; };
    let alpha = (cmd.alpha as f32).clamp(0.0, 1.0);
    if alpha <= 0.0 { return true; }
    let color = unpack_color(cmd.color);
    let flood = if cmd.fog { Some(color) } else { None };
    // The screen scale folds into BOTH the position and the sprite extent: a
    // GM draw places the sprite at world position with image_xscale in world
    // units, so the on-screen size is w * xscale * view_zoom. Passing the raw
    // cmd.scale kept the extent flat when the view projection zoomed (the
    // view_projection_consumption suite pins this).
    fb.blit_sprite_gm(
        atlas,
        (page.x as u32, page.y as u32, page.w as u32, page.h as u32),
        (sprite.width as f64, sprite.height as f64),
        (sprite.origin_x as f64, sprite.origin_y as f64),
        ((cmd.x - cam.0) * screen_scale.0 as f64, (cmd.y - cam.1) * screen_scale.1 as f64),
        (cmd.scale_x * screen_scale.0 as f64, cmd.scale_y * screen_scale.1 as f64),
        cmd.rotation,
        alpha,
        color,
        flood,
    );
    true
}

fn draw_tile(fb: &mut Framebuffer, state: &GameState, tile: &callys_asset::RoomTileInstance, cam_x: f32, cam_y: f32, scale_x: f32, scale_y: f32) -> bool {
    if tile.bg_id < 0 { return false; }
    let Some(bg) = state.asset.backgrounds.get(&(tile.bg_id as usize)) else { return false; };
    let Some(page) = state.asset.tpag_items.get(&bg.tpag_ptr) else { return false; };
    let Some(atlas) = state.atlases.get(page.tex_id as usize) else { return false; };

    let src_x = (page.x as i32 + tile.src_x).max(0) as u32;
    let src_y = (page.y as i32 + tile.src_y).max(0) as u32;
    let src_w = (tile.width as u32).min(page.w as u32);
    let src_h = (tile.height as u32).min(page.h as u32);

    let dst_x = ((tile.x as f32 - cam_x) * scale_x) as i32;
    let dst_y = ((tile.y as f32 - cam_y) * scale_y) as i32;
    let dst_w = ((tile.width as f32 * tile.scale_x) * scale_x).max(1.0) as u32;
    let dst_h = ((tile.height as f32 * tile.scale_y) * scale_y).max(1.0) as u32;

    fb.blit_scaled(atlas, (src_x, src_y, src_w, src_h), (dst_x, dst_y, dst_w, dst_h), false);
    true
}

pub fn draw_frame(
    fb: &mut Framebuffer,
    state: &GameState,
    _tpag: &HashMap<usize, TpagItem>,
    _sprites: &HashMap<usize, SpriteData>,
) {
    let mut scale_x = fb.width as f32 / 960.0;
    let mut scale_y = fb.height as f32 / 540.0;
    let mut view_origin = (0.0f64, 0.0f64);
    let mut view_active = false;
    // GM8.1 view projection: the runtime-visible index selects the ROOM view
    // rectangle. Keep Draw dispatch, camera origin, pointer unprojection and
    // framebuffer scale on that same index, including during the prologue.
    if let Some(scene) = state.scene.as_ref() {
        if let Some(view_index) = scene.active_view_index() {
            if let Some(v) = scene.room_views.get(view_index) {
                let view_id = view_index as i32;
                let (port_x, port_y) = scene.view_ports.get(&view_id).copied()
                    .unwrap_or((v.wport as f64, v.hport as f64));
                let port_x = if port_x > 0.0 { port_x as f32 } else { scene.display_width as f32 };
                let port_y = if port_y > 0.0 { port_y as f32 } else { scene.display_height as f32 };
                let zoom_x = port_x / v.wview.max(1) as f32;
                let zoom_y = port_y / v.hview.max(1) as f32;
                scale_x = fb.width as f32 / port_x * zoom_x;
                scale_y = fb.height as f32 / port_y * zoom_y;
                view_origin = GameState::camera_position_for_scene(scene);
                view_active = true;
            }
        }
    }

    // Prologue cutscene: render the same world-space queues as gameplay, using
    // the runtime-selected view's camera and projection (no prologue bypass).
    //
    // Layers consumed (probe enumeration on the natural prologue run):
    //   1. `scene.backgrounds` — obj_bg CODE 364 emits `draw_background(bg=5)`
    //      (the sea/cliff backdrop); without this the prologue loses its sky.
    //   2. `scene.draws`       — obj_phone draw_self of spr_intro (161) and the
    //      obj_logo crossfade of spr_logo (160).
    //   3. `scene.texts`       — CODE 370 score strings + CODE 520 pause label
    //      drawn through the original FONT chunk atlases.
    if let Some(scene) = state.scene.as_ref() {
        let intro_alive = scene.instances.values().any(|i| i.object == 137 && i.alive);
        if intro_alive {
            fb.fill_rect(0, 0, fb.width, fb.height, (0, 0, 0, 255));
            // 1. Backgrounds use GM8.1's single-background draw path. Tiling is
            // a distinct builtin and is not implied by draw_background.
            for bg_cmd in &scene.backgrounds {
                let alpha = (bg_cmd.alpha as f32).clamp(0.0, 1.0);
                if alpha <= 0.0 {
                    continue;
                }
                let bg_id = bg_cmd.background.max(0) as usize;
                if let Some(bg_data) = state.asset.backgrounds.get(&bg_id) {
                    if let Some(page) = state.asset.tpag_items.get(&bg_data.tpag_ptr) {
                        if let Some(atlas) = state.atlases.get(page.tex_id as usize) {
                            let dst_x = ((bg_cmd.x - view_origin.0) as f32 * scale_x) as i32;
                            let dst_y = ((bg_cmd.y - view_origin.1) as f32 * scale_y) as i32;
                            let dst_w = ((page.w as f64 * bg_cmd.scale_x) as f32 * scale_x).max(1.0) as u32;
                            let dst_h = ((page.h as f64 * bg_cmd.scale_y) as f32 * scale_y).max(1.0) as u32;
                            fb.blit_scaled_alpha(
                                atlas,
                                (page.x as u32, page.y as u32, page.w as u32, page.h as u32),
                                (dst_x, dst_y, dst_w, dst_h),
                                false,
                                alpha,
                            );
                        }
                    }
                }
            }

            // 1.5. Room background tiles (depth >= 0). Room layers render on
            // every frame in the original runner — DrawTheRoom -> DrawRoomLayers
            // runs over the room's layer set regardless of instance state — so
            // the film rides on top of its room's tile scenery even while all
            // other instances are frozen (binary-verified call order).
            for tile in scene.room_tiles.iter().filter(|t| t.depth >= 0) {
                draw_tile(
                    fb,
                    state,
                    tile,
                    view_origin.0 as f32,
                    view_origin.1 as f32,
                    scale_x,
                    scale_y,
                );
            }

            // 2. Film sprite draws (obj_phone draw_self / obj_logo crossfade)
            for cmd in &scene.draws {
                if !draw_ir_sprite(fb, state, cmd, view_origin, (scale_x, scale_y)) {
                    let dst_x = ((cmd.x - view_origin.0) as f32 * scale_x) as i32;
                    let dst_y = ((cmd.y - view_origin.1) as f32 * scale_y) as i32;
                    let alpha = (cmd.alpha as f32).clamp(0.0, 1.0);
                    if alpha > 0.0 {
                        fb.fill_rect(dst_x, dst_y, 32, 32, (60, 60, 70, (alpha * 255.0) as u8));
                    }
                }
            }

            // 2.5. Foreground tiles (depth < 0) render over the film, matching
            // the gameplay branch's layer ordering.
            for tile in scene.room_tiles.iter().filter(|t| t.depth < 0) {
                draw_tile(
                    fb,
                    state,
                    tile,
                    view_origin.0 as f32,
                    view_origin.1 as f32,
                    scale_x,
                    scale_y,
                );
            }

            // 3. HUD text draws (CODE 370 score strings, CODE 520 pause label):
            // consumed through the FONT-chunk atlases exactly like the gameplay
            // branch so the batched font_consumption evidence holds for the
            // prologue too.
            for cmd in &scene.texts {
                let alpha = (cmd.alpha as f32).clamp(0.0, 1.0);
                if alpha <= 0.0 || cmd.text.is_empty() {
                    continue;
                }
                let x = ((cmd.x - view_origin.0) as f32 * scale_x) as i32;
                let y = ((cmd.y - view_origin.1) as f32 * scale_y) as i32;
                let (r, g, b) = if cmd.color < 0 {
                    (255, 255, 255)
                } else {
                    (
                        (cmd.color & 0xFF) as u8,
                        ((cmd.color >> 8) & 0xFF) as u8,
                        ((cmd.color >> 16) & 0xFF) as u8,
                    )
                };
                let font_disk_index = match cmd.font {
                    0 => Some(0),
                    1 => Some(2),
                    2 => Some(3),
                    3 => Some(1),
                    4 => Some(4),
                    5 => Some(5),
                    _ => None,
                };
                let gm_font = font_disk_index
                    .and_then(|idx| state.asset.fonts.get(idx))
                    .and_then(|font| {
                        let page = state.asset.tpag_items.get(&font.page_tpag_ptr)?;
                        let atlas = state.atlases.get(page.tex_id as usize)?;
                        Some((atlas, (page.x as u32, page.y as u32), font))
                    });
                if let Some((atlas, page, font)) = gm_font {
                    let scale = scale_x.min(scale_y);
                    let space_shift = font
                        .glyphs
                        .iter()
                        .find(|g| g.ch == b' ' as u16)
                        .map(|g| g.shift)
                        .unwrap_or(7);
                    fb.draw_text_gm(
                        atlas,
                        page,
                        &font.glyphs,
                        space_shift,
                        x,
                        y,
                        &cmd.text,
                        scale,
                        (r, g, b),
                        alpha,
                    );
                }
            }
            return;
        }
    }

    // Full IR gameplay scene: render room tiles, original draws, and camera follow
    if let (Some(_bundle), Some(scene)) = (state.full_bundle.as_deref(), state.scene.as_ref()) {
        let (cam_x, cam_y) = if view_active {
            view_origin
        } else {
            GameState::camera_position_for_scene(scene)
        };

        fb.fill_rect(0, 0, fb.width, fb.height, (15, 18, 30, 255));

        // 0. Render the single image emitted by draw_background; the separate
        // tiled builtin is not used at this call site.
        for bg_cmd in &scene.backgrounds {
            let alpha = (bg_cmd.alpha as f32).clamp(0.0, 1.0);
            if alpha <= 0.0 {
                continue;
            }
            let bg_id = bg_cmd.background.max(0) as usize;
            if let Some(bg_data) = state.asset.backgrounds.get(&bg_id) {
                if let Some(page) = state.asset.tpag_items.get(&bg_data.tpag_ptr) {
                    if let Some(atlas) = state.atlases.get(page.tex_id as usize) {
                        let world_x = bg_cmd.x - cam_x;
                        let world_y = bg_cmd.y - cam_y;
                        let dst_x = (world_x as f32 * scale_x) as i32;
                        let dst_y = (world_y as f32 * scale_y) as i32;
                        let dst_w = ((page.w as f64 * bg_cmd.scale_x) as f32 * scale_x).max(1.0) as u32;
                        let dst_h = ((page.h as f64 * bg_cmd.scale_y) as f32 * scale_y).max(1.0) as u32;
                        fb.blit_scaled_alpha(
                            atlas,
                            (page.x as u32, page.y as u32, page.w as u32, page.h as u32),
                            (dst_x, dst_y, dst_w, dst_h),
                            false,
                            alpha,
                        );
                    }
                }
            }
        }

        // 1. Background tiles
        for tile in scene.room_tiles.iter().filter(|t| t.depth >= 0) {
            draw_tile(fb, state, tile, cam_x as f32, cam_y as f32, scale_x, scale_y);
        }

        // 2. Instances from IR draws, each one in GameMaker's own sprite terms:
        // origin anchor, facing mirror, image_angle rotation, image_blend, and
        // the d3d_set_fog hit-flash flood.
        for cmd in &scene.draws {
            if !draw_ir_sprite(fb, state, cmd, (cam_x, cam_y), (scale_x, scale_y)) {
                let dst_x = ((cmd.x - cam_x) as f32 * scale_x) as i32;
                let dst_y = ((cmd.y - cam_y) as f32 * scale_y) as i32;
                let alpha = (cmd.alpha as f32).clamp(0.0, 1.0);
                if alpha > 0.0 {
                    fb.fill_rect(dst_x, dst_y, 32, 32, (60, 60, 70, (alpha * 255.0) as u8));
                }
            }
        }

        // 2.5. Hit particles from the original part_particles_create calls:
        // world-space positions, camera-relative, size-scaled squares blended
        // with the particle's current color2 gradient color.
        for p in &scene.particles {
            let alpha = (p.alpha as f32).clamp(0.0, 1.0);
            if alpha <= 0.0 {
                continue;
            }
            let wx = p.x - cam_x;
            let wy = p.y - cam_y;
            let size_f = (p.size * 4.0).clamp(2.0, 16.0) as f32;
            let w = ((size_f * scale_x) as u32).max(1);
            let h = ((size_f * scale_y) as u32).max(1);
            let x = (wx as f32 * scale_x) as i32 - (w as i32) / 2;
            let y = (wy as f32 * scale_y) as i32 - (h as i32) / 2;
            let r = (p.color & 0xFF) as u8;
            let g = ((p.color >> 8) & 0xFF) as u8;
            let b = ((p.color >> 16) & 0xFF) as u8;
            fb.fill_rect(x, y, w, h, (r, g, b, (alpha * 255.0) as u8));
        }

        // 3. Foreground tiles
        for tile in scene.room_tiles.iter().filter(|t| t.depth < 0) {
            draw_tile(fb, state, tile, cam_x as f32, cam_y as f32, scale_x, scale_y);
        }

        // 3.5. Original draw_healthbar: back_col fills the whole bar, the fill
        // runs from min_col (value 0) to max_col (value 100), and the original
        // asks for the border (its showborder argument is 1 at all 90 call
        // sites, as are direction=0 and showback=1).
        for hb in &scene.healthbars {
            let xs = ((hb.x1 - cam_x) as f32 * scale_x) as i32;
            let ys = ((hb.y1 - cam_y) as f32 * scale_y) as i32;
            let xe = ((hb.x2 - cam_x) as f32 * scale_x) as i32;
            let ye = ((hb.y2 - cam_y) as f32 * scale_y) as i32;
            let (left, right) = (xs.min(xe), xs.max(xe));
            let (top, bottom) = (ys.min(ye), ys.max(ye));
            let w = ((right - left).abs() as u32).max(1);
            let h = ((bottom - top).abs() as u32).max(1);
            let (br, bg, bb) = unpack_color(hb.back_col);
            let (nrr, nrg, nrb) = unpack_color(hb.min_col);
            let (xrr, xrg, xrb) = unpack_color(hb.max_col);
            let pct = (hb.amount as f32 / 100.0).clamp(0.0, 1.0);
            let mix = |lo: u8, hi: u8| -> u8 {
                (lo as f32 + (hi as f32 - lo as f32) * pct).round() as u8
            };
            fb.fill_rect(left, top, w, h, (br, bg, bb, 255));
            let fill_w = (w as f32 * pct).round() as u32;
            if fill_w > 0 {
                fb.fill_rect(left, top, fill_w, h, (mix(nrr, xrr), mix(nrg, xrg), mix(nrb, xrb), 255));
            }
            fb.draw_rect(left, top, w, h, (0, 0, 0, 255));
        }

        // 3.6. Render UI Texts emitted by scene
        for cmd in &scene.texts {
            let alpha = (cmd.alpha as f32).clamp(0.0, 1.0);
            if alpha <= 0.0 || cmd.text.is_empty() {
                continue;
            }
            let world_x = cmd.x - cam_x;
            let world_y = cmd.y - cam_y;
            let x = (world_x as f32 * scale_x) as i32;
            let y = (world_y as f32 * scale_y) as i32;
            let (r, g, b) = if cmd.color < 0 {
                (255, 255, 255)
            } else {
                (
                    (cmd.color & 0xFF) as u8,
                    ((cmd.color >> 8) & 0xFF) as u8,
                    ((cmd.color >> 16) & 0xFF) as u8,
                )
            };
            let color = (r, g, b, (alpha * 255.0) as u8);
            // The original fonts: draw_set_font(N) pushes the alphabetically
            // sorted resource id (font1=0..font6=5); the FONT chunk's disk
            // order is font1,font4,font2,font3,font5,font6, so runtime id N
            // maps to disk index [0,2,3,1,4,5][N]. Text commands predate this
            // mapping when they were emitted without a font (font: 0).
            let font_disk_index = match cmd.font {
                0 => Some(0),
                1 => Some(2),
                2 => Some(3),
                3 => Some(1),
                4 => Some(4),
                5 => Some(5),
                _ => None,
            };
            let gm_font = font_disk_index
                .and_then(|idx| state.asset.fonts.get(idx))
                .and_then(|font| {
                    let page = state.asset.tpag_items.get(&font.page_tpag_ptr)?;
                    let atlas = state.atlases.get(page.tex_id as usize)?;
                    Some((atlas, (page.x as u32, page.y as u32), font))
                });
            if let Some((atlas, page, font)) = gm_font {
                // Scale the original pixel sizes into screen space the same
                // way the sprite blits do: the game's views can be larger than
                // the room pixels, and the fonts were baked for room pixels.
                let scale = scale_x.min(scale_y);
                let space_shift = font
                    .glyphs
                    .iter()
                    .find(|g| g.ch == b' ' as u16)
                    .map(|g| g.shift)
                    .unwrap_or(7);
                fb.draw_text_gm(
                    atlas,
                    page,
                    &font.glyphs,
                    space_shift,
                    x,
                    y,
                    &cmd.text,
                    scale,
                    (r, g, b),
                    alpha,
                );
            } else {
                let scale = ((scale_x.min(scale_y) * 2.0).round() as u32).max(1);
                fb.draw_text_str(x, y, &cmd.text, scale, color);
            }
        }

        // The IR scene already contains the original obj_UI button instances
        // (left/right/jump/shoot/sword/pause) and draw_view has emitted their
        // Draw events above. Do not add the legacy client overlay here: doing
        // so renders a second, differently positioned control set over the
        // original GameMaker controls. The legacy GameWorld branch below still
        // owns its fallback overlay.
        return;
    }

    fb.fill_rect(0, 0, fb.width, fb.height, (15, 18, 30, 255));

    let cam_x = state.world.camera_x;
    let cam_y = state.world.camera_y;

    // Draw background tiles (depth >= 0)
    for tile in state.world.room_tiles.iter().filter(|t| t.depth >= 0) {
        draw_tile(fb, state, tile, cam_x, cam_y, scale_x, scale_y);
    }

    for decoration in &state.world.decorations {
        let x = ((decoration.rect.x - cam_x) * scale_x) as i32;
        let y = ((decoration.rect.y - cam_y) * scale_y) as i32;
        let w = (decoration.rect.w * scale_x) as u32;
        let h = (decoration.rect.h * scale_y) as u32;
        if !draw_sprite(fb, state, decoration.sprite_id, (state.frame_count / 8) as usize, (x, y, w, h), false) {
            fb.fill_rect(x, y, w, h, (40, 100, 190, 180));
        }
    }

    for solid in state.world.solids.iter().chain(&state.world.platforms) {
        let color = if solid.is_boulder {
            (150, 95, 45, 255)
        } else {
            (65, 75, 95, 255)
        };
        let x = ((solid.rect.x - cam_x) * scale_x) as i32;
        let y = ((solid.rect.y - cam_y) * scale_y) as i32;
        let w = (solid.rect.w * scale_x) as u32;
        let h = (solid.rect.h * scale_y) as u32;
        if !draw_sprite(fb, state, solid.sprite_id, 0, (x, y, w, h), false) {
            if state.world.room_tiles.is_empty() {
                fb.fill_rect(x, y, w, h, color);
                fb.draw_rect(x, y, w, h, (35, 40, 50, 255));
            }
        }
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
        if !draw_sprite(fb, state, gem.sprite_id, (state.frame_count / 6) as usize, (x, y, s, s), false) {
            fb.fill_rect(x, y, s, s, color);
        }
    }

    for pickup in &state.world.weapon_pickups {
        if pickup.collected {
            continue;
        }
        let x = ((pickup.rect.x - cam_x) * scale_x) as i32;
        let y = ((pickup.rect.y - cam_y) * scale_y) as i32;
        let w = (pickup.rect.w * scale_x) as u32;
        let h = (pickup.rect.h * scale_y) as u32;
        if !draw_sprite(fb, state, pickup.sprite_id, 0, (x, y, w, h), false) {
            fb.fill_rect(x, y, w, h, (255, 180, 60, 255));
        }
    }

    for warp in &state.world.warps {
        let x = ((warp.rect.x - cam_x) * scale_x) as i32;
        let y = ((warp.rect.y - cam_y) * scale_y) as i32;
        let w = (warp.rect.w * scale_x) as u32;
        let h = (warp.rect.h * scale_y) as u32;
        if !draw_sprite(fb, state, warp.sprite_id, (state.frame_count / 8) as usize, (x, y, w, h), false) {
            fb.draw_rect(x, y, w, h, (140, 220, 255, 180));
        }
    }

    for enemy in &state.world.enemies {
        let x = ((enemy.x - cam_x) * scale_x) as i32;
        let y = ((enemy.y - cam_y) * scale_y) as i32;
        let w = (enemy.width * scale_x) as u32;
        let h = (enemy.height * scale_y) as u32;
        if !draw_sprite(fb, state, enemy.sprite_id, (state.frame_count / 7) as usize, (x, y, w, h), enemy.facing == Facing::Left) {
            fb.fill_rect(x, y, w, h, (220, 60, 60, 255));
        }
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
        let (active_sprite_id, anim_speed) = match p.state {
            PlayerState::Running => (30, 4), // spr_playerrun
            PlayerState::Jumping => (32, 3), // spr_playerjump
            PlayerState::Falling => (33, 4), // spr_playerfall
            PlayerState::Hurt => (36, 1),    // spr_playerhit
            _ => (29, 6),                    // spr_player idle (18 frames)
        };
        let frame = (state.frame_count / anim_speed) as usize;
        let color = match p.state {
            PlayerState::Idle => (240, 80, 80, 255),
            PlayerState::Running => (255, 130, 60, 255),
            PlayerState::Jumping | PlayerState::Falling => (255, 210, 80, 255),
            PlayerState::Hurt => (255, 255, 255, 255),
            _ => (240, 80, 80, 255),
        };
        if !draw_sprite(fb, state, active_sprite_id, frame, (px, py, pw, ph), p.facing == Facing::Left) {
            fb.fill_rect(px, py, pw, ph, color);
            let eye_x = if p.facing == Facing::Right { px + pw as i32 - 6 } else { px + 2 };
            fb.fill_rect(eye_x, py + 6, 4, 4, (255, 255, 255, 255));
        }
    }

    // Draw HUD: Top bar background (spr_UI, id 84)
    if !draw_sprite(fb, state, 84, 0, (10, 10, 300, 52), false) {
        fb.fill_rect(16, 16, 204, 20, (50, 50, 50, 255));
    }
    let hp_pct = (p.health as f32 / p.max_health as f32).max(0.0);
    fb.fill_rect(65, 20, (135.0 * hp_pct) as u32, 12, (230, 40, 40, 255));

    // Touch Controls: On-screen buttons using real sprites
    let bottom = fb.height as i32 - 92;
    // D-Pad Left: spr_leftbutton (id 158)
    if !draw_sprite(fb, state, 158, 0, (20, bottom, 80, 68), false) {
        fb.draw_rect(24, bottom, 68, 68, (120, 180, 255, 170));
    }
    // D-Pad Right: spr_rightbutton (id 159)
    if !draw_sprite(fb, state, 159, 0, (110, bottom, 80, 68), false) {
        fb.draw_rect(108, bottom, 68, 68, (120, 180, 255, 170));
    }
    // Jump: spr_jumpbutton (id 155)
    if !draw_sprite(fb, state, 155, 0, (fb.width as i32 - 180, bottom, 68, 68), false) {
        fb.draw_rect(fb.width as i32 - 176, bottom, 68, 68, (255, 190, 80, 170));
    }
    // Shoot/Attack: spr_shootbutton (id 156)
    if !draw_sprite(fb, state, 156, 0, (fb.width as i32 - 96, bottom, 68, 68), false) {
        fb.draw_rect(fb.width as i32 - 92, bottom, 68, 68, (255, 90, 90, 170));
    }
    // Pause: spr_pausebutton (id 122)
    draw_sprite(fb, state, 122, 0, (fb.width as i32 - 64, 16, 48, 48), false);
}

include!("parts/jni.rs");
