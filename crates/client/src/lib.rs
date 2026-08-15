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

// ============================================================
// Save file I/O
// ============================================================

#[derive(Debug)]
pub enum SaveFileError {
    Io(std::io::Error),
    Data(SaveError),
}

impl fmt::Display for SaveFileError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Io(error) => write!(formatter, "save file I/O failed: {error}"),
            Self::Data(error) => write!(formatter, "{error}"),
        }
    }
}

impl std::error::Error for SaveFileError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io(error) => Some(error),
            Self::Data(error) => Some(error),
        }
    }
}

impl From<std::io::Error> for SaveFileError {
    fn from(error: std::io::Error) -> Self {
        Self::Io(error)
    }
}

impl From<SaveError> for SaveFileError {
    fn from(error: SaveError) -> Self {
        Self::Data(error)
    }
}

pub fn save_path_for_asset(droid_path: &Path) -> PathBuf {
    droid_path.with_file_name("save-v1.json")
}

pub fn load_save(path: &Path) -> Result<Option<SaveData>, SaveFileError> {
    let json = match fs::read_to_string(path) {
        Ok(json) => json,
        Err(error) if error.kind() == std::io::ErrorKind::NotFound => return Ok(None),
        Err(error) => return Err(error.into()),
    };
    Ok(Some(SaveData::from_json(&json)?))
}

pub fn write_save_atomic(path: &Path, save: &SaveData) -> Result<(), SaveFileError> {
    let json = save.to_json()?;
    let temp_path = path.with_file_name(format!(
        "{}.tmp",
        path.file_name()
            .and_then(|name| name.to_str())
            .unwrap_or("save-v1.json")
    ));
    match fs::remove_file(&temp_path) {
        Ok(()) => {}
        Err(error) if error.kind() == std::io::ErrorKind::NotFound => {}
        Err(error) => return Err(error.into()),
    }
    let mut temp = OpenOptions::new()
        .write(true)
        .create_new(true)
        .open(&temp_path)?;
    if let Err(error) = (|| -> Result<(), std::io::Error> {
        temp.write_all(json.as_bytes())?;
        temp.sync_all()?;
        drop(temp);
        fs::rename(&temp_path, path)?;
        Ok(())
    })() {
        let _ = fs::remove_file(&temp_path);
        return Err(error.into());
    }
    Ok(())
}

// ============================================================
// Short sound effects
// ============================================================

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum SoundEvent {
    Jump,
    Pistol,
    Shotgun,
    Coin,
    Death,
    WeaponPickup,
}

const SOUND_BINDINGS: [(SoundEvent, &str); 6] = [
    (SoundEvent::Jump, "snd_jump"),
    (SoundEvent::Pistol, "snd_fire"),
    (SoundEvent::Shotgun, "snd_shotgun"),
    (SoundEvent::Coin, "snd_coin"),
    (SoundEvent::Death, "snd_youhavedied"),
    (SoundEvent::WeaponPickup, "snd_pickupstinger"),
];

#[derive(Debug, Clone)]
pub struct SoundCatalog {
    audio_ids: HashMap<SoundEvent, usize>,
}

impl SoundCatalog {
    pub fn from_asset(asset: &GameDroidAsset) -> Result<Self, String> {
        let sounds_by_name: HashMap<&str, usize> = asset
            .sounds
            .iter()
            .map(|sound| (sound.name.as_str(), sound.audio_id))
            .collect();
        let mut audio_ids = HashMap::with_capacity(SOUND_BINDINGS.len());
        for (event, name) in SOUND_BINDINGS {
            let audio_id = sounds_by_name
                .get(name)
                .copied()
                .ok_or_else(|| format!("required SOND resource is missing: {name}"))?;
            if asset.audio.get(audio_id).is_none() {
                return Err(format!(
                    "SOND resource {name} references missing AUDO {audio_id}"
                ));
            }
            audio_ids.insert(event, audio_id);
        }
        Ok(Self { audio_ids })
    }

    pub fn audio_id(&self, event: SoundEvent) -> usize {
        self.audio_ids[&event]
    }
}

pub fn export_required_wavs(
    asset: &GameDroidAsset,
    droid_path: &Path,
) -> Result<Vec<(usize, PathBuf)>, Box<dyn std::error::Error>> {
    let catalog = SoundCatalog::from_asset(asset)?;
    let output_dir = droid_path
        .parent()
        .unwrap_or_else(|| Path::new("."))
        .join("sfx");
    fs::create_dir_all(&output_dir)?;

    let mut exported = Vec::with_capacity(SOUND_BINDINGS.len());
    let mut exported_audio_ids = HashSet::with_capacity(SOUND_BINDINGS.len());
    for (event, _) in SOUND_BINDINGS {
        let audio_id = catalog.audio_id(event);
        if !exported_audio_ids.insert(audio_id) {
            continue;
        }
        let wav = &asset.audio[audio_id].wav_bytes;
        let output_path = output_dir.join(format!("sound_{audio_id}.wav"));
        let already_current = fs::read(&output_path)
            .map(|existing| existing == *wav)
            .unwrap_or(false);
        if !already_current {
            let temp_path = output_dir.join(format!("sound_{audio_id}.wav.tmp"));
            match fs::remove_file(&temp_path) {
                Ok(()) => {}
                Err(error) if error.kind() == std::io::ErrorKind::NotFound => {}
                Err(error) => return Err(error.into()),
            }
            let mut temp = OpenOptions::new()
                .write(true)
                .create_new(true)
                .open(&temp_path)?;
            if let Err(error) = (|| -> Result<(), std::io::Error> {
                temp.write_all(wav)?;
                temp.sync_all()?;
                drop(temp);
                fs::rename(&temp_path, &output_path)?;
                Ok(())
            })() {
                let _ = fs::remove_file(&temp_path);
                return Err(error.into());
            }
        }
        exported.push((audio_id, output_path));
    }
    Ok(exported)
}

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
    pub sound_catalog: SoundCatalog,
    sound_queue: VecDeque<usize>,
    jump_was_active: bool,
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
        let loaded_save = match save_path.as_deref().map(load_save) {
            Some(Ok(save)) => save,
            Some(Err(error)) => {
                let diagnostic = Some(error.to_string());
                return Self::finish_initialization(asset, droid_path, save_path, None, diagnostic);
            }
            None => None,
        };
        Self::finish_initialization(asset, droid_path, save_path, loaded_save, None)
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
        if let Some(room) = asset.rooms.get(room_index) {
            world.load_room(room_index, room, &asset.objects, &asset.warp_targets);
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
            sound_catalog,
            sound_queue: VecDeque::new(),
            jump_was_active: false,
        })
    }

    pub fn step(&mut self, dt: f32) {
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
                self.world.load_room(target, next, &self.asset.objects, &self.asset.warp_targets);
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
    }

    fn queue_sound(&mut self, event: SoundEvent) {
        self.sound_queue.push_back(self.sound_catalog.audio_id(event));
    }

    pub fn poll_sound(&mut self) -> Option<usize> {
        self.sound_queue.pop_front()
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
        assert_eq!(state.poll_sound(), Some(3));
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
        assert_eq!(state.poll_sound(), Some(10));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);

        state.world.player.attack_cooldown = 0.0;
        state.world.player.current_weapon = WeaponType::Shotgun;
        state.step(0.0);
        assert_eq!(state.poll_sound(), Some(11));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn dead_or_dying_player_does_not_enqueue_a_shot() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.input.attack = true;
        state.world.player.current_weapon = WeaponType::Pistol;
        state.world.player.health = 0;

        state.step(0.0);

        assert_eq!(state.poll_sound(), Some(26));
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
        });

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some(19));
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
        });

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some(27));
        state.step(0.0);
        assert_eq!(state.poll_sound(), None);
    }

    #[test]
    fn death_transition_enqueues_once() {
        let mut state = GameState::new(&game_droid_path()).unwrap();
        state.world.player.health = 0;

        state.step(0.0);
        assert_eq!(state.poll_sound(), Some(26));
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

    fn blit_scaled(&mut self, atlas: &RgbaImage, src: (u32, u32, u32, u32), dst: (i32, i32, u32, u32), flip_x: bool) {
        let (sx, sy, sw, sh) = src;
        let (dx, dy, dw, dh) = dst;
        if sw == 0 || sh == 0 || dw == 0 || dh == 0 { return; }
        for oy in 0..dh {
            let py = dy + oy as i32;
            if py < 0 || py >= self.height as i32 { continue; }
            let src_y = sy + oy * sh / dh;
            for ox in 0..dw {
                let px = dx + ox as i32;
                if px < 0 || px >= self.width as i32 { continue; }
                let sample_x = ox * sw / dw;
                let src_x = sx + if flip_x { sw - 1 - sample_x } else { sample_x };
                if src_x >= atlas.width() || src_y >= atlas.height() { continue; }
                let rgba = atlas.get_pixel(src_x, src_y).0;
                if rgba[3] >= 16 { self.put(px, py, (rgba[0], rgba[1], rgba[2], rgba[3])); }
            }
        }
    }
}

fn draw_sprite(fb: &mut Framebuffer, state: &GameState, sprite_id: i32, frame: usize, dst: (i32, i32, u32, u32), flip_x: bool) -> bool {
    let Ok(sprite_id) = usize::try_from(sprite_id) else { return false; };
    let Some(sprite) = state.asset.sprites.get(&sprite_id) else { return false; };
    if sprite.tpag_indices.is_empty() { return false; }
    let frame_ptr = sprite.tpag_indices[frame % sprite.tpag_indices.len()] as usize;
    let Some(page) = state.asset.tpag_items.get(&frame_ptr) else { return false; };
    let Some(atlas) = state.atlases.get(page.tex_id as usize) else { return false; };
    fb.blit_scaled(atlas, (page.x as u32, page.y as u32, page.w as u32, page.h as u32), dst, flip_x);
    true
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
            fb.fill_rect(x, y, w, h, color);
            fb.draw_rect(x, y, w, h, (35, 40, 50, 255));
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
        let color = match p.state {
            PlayerState::Idle => (240, 80, 80, 255),
            PlayerState::Running => (255, 130, 60, 255),
            PlayerState::Jumping | PlayerState::Falling => (255, 210, 80, 255),
            PlayerState::Hurt => (255, 255, 255, 255),
            _ => (240, 80, 80, 255),
        };
        if !draw_sprite(fb, state, p.sprite_id, (state.frame_count / 5) as usize, (px, py, pw, ph), p.facing == Facing::Left) {
            fb.fill_rect(px, py, pw, ph, color);
            let eye_x = if p.facing == Facing::Right { px + pw as i32 - 6 } else { px + 2 };
            fb.fill_rect(eye_x, py + 6, 4, 4, (255, 255, 255, 255));
        }
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
    let bottom = fb.height as i32 - 92;
    fb.draw_rect(24, bottom, 68, 68, (120, 180, 255, 170));
    fb.draw_rect(108, bottom, 68, 68, (120, 180, 255, 170));
    fb.draw_rect(fb.width as i32 - 176, bottom, 68, 68, (255, 190, 80, 170));
    fb.draw_rect(fb.width as i32 - 92, bottom, 68, 68, (255, 90, 90, 170));
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
        pub blit: Vec<jint>,
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
        let st = match GameState::new_persistent(Path::new(&path)) {
            Ok(s) => s,
            Err(e) => {
                log(&format!("GameState::new failed: {}", e));
                return;
            }
        };
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
            fb: Framebuffer::new(960, 540),
            blit: Vec::with_capacity(960 * 540),
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
            s.blit.clear();
            s.blit.reserve((s.fb.width * s.fb.height) as usize);
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
            let previous_room = s.state.world.current_room_index;
            let previous_player_state = s.state.world.player.state;
            let previous_save_diagnostic = s.state.save_diagnostic.clone();
            s.state.step(dt);
            if s.state.save_diagnostic != previous_save_diagnostic {
                if let Some(diagnostic) = s.state.save_diagnostic.as_deref() {
                    log(&format!("save write warning: {diagnostic}"));
                }
            }
            if s.state.world.current_room_index != previous_room {
                log(&format!(
                    "room transition {} -> {} ({}) spawn=({}, {})",
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
                    "player died in room {} checkpoint=({}, {})",
                    s.state.world.current_room_name,
                    s.state.world.checkpoint.x,
                    s.state.world.checkpoint.y,
                ));
            } else if previous_player_state == PlayerState::Dead
                && s.state.world.player.state != PlayerState::Dead
            {
                log(&format!(
                    "player respawned in room {} at=({}, {}) health={}",
                    s.state.world.current_room_name,
                    s.state.world.player.x,
                    s.state.world.player.y,
                    s.state.world.player.health,
                ));
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
        _weapon: jint,
    ) {
        let mut g = slot().lock().unwrap();
        if let Some(s) = g.as_mut() {
            s.state.input.move_left = move_left != 0;
            s.state.input.move_right = move_right != 0;
            s.state.input.jump = jump != 0;
            s.state.input.attack = attack != 0;
            s.state.input.switch_weapon = switch_weapon != 0;

        }
    }

    #[no_mangle]
    pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativePollSound(
        _env: *mut JNIEnv,
        _class: jobject,
    ) -> jint {
        slot()
            .lock()
            .unwrap()
            .as_mut()
            .and_then(|state| state.state.poll_sound())
            .and_then(|audio_id| jint::try_from(audio_id).ok())
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
