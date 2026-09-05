pub mod save;
pub mod original_player;
pub mod original_player_combat;
pub mod original_projectile_create;

use callys_asset::{GameObjectInfo, RoomData, RoomObjectInstance, SpriteData, WarpTarget};
use serde::{Deserialize, Serialize};
use std::collections::{BTreeSet, HashMap};

// These water-physics values are provisional until CODE disassembly or
// original-runtime measurements establish the game's exact constants.
pub const PROVISIONAL_WATER_GRAVITY: f32 = 250.0;
pub const PROVISIONAL_WATER_MAX_FALL_SPEED: f32 = 120.0;
pub const PROVISIONAL_WATER_RISE_SPEED: f32 = -180.0;
// Exact spike damage, invulnerability duration, and collision mask remain
// provisional until CODE disassembly or original-runtime measurements exist.
pub const PROVISIONAL_SPIKE_DAMAGE: i32 = 20;
pub const PROVISIONAL_SPIKE_INVULNERABILITY_SECONDS: f32 = 1.0;

// SPRT resource 93 (`spr_spikes`) is 32x32 with origin (0, 0).
const SPIKE_SPRITE_WIDTH: f32 = 32.0;
const SPIKE_SPRITE_HEIGHT: f32 = 32.0;

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub struct Rect {
    pub x: f32,
    pub y: f32,
    pub w: f32,
    pub h: f32,
}

impl Rect {
    pub fn new(x: f32, y: f32, w: f32, h: f32) -> Self {
        Self { x, y, w, h }
    }

    pub fn intersects(&self, other: &Rect) -> bool {
        self.x < other.x + other.w
            && self.x + self.w > other.x
            && self.y < other.y + other.h
            && self.y + self.h > other.y
    }
}

#[derive(Debug, Clone, PartialEq)]
pub enum EnemyGeometryError {
    UnexpectedParent { parent_id: i32 },
    NoSprite,
    MissingSpriteResource { sprite_id: i32 },
    InvalidSpriteDimensions {
        sprite_id: i32,
        width: u32,
        height: u32,
    },
    InvalidScale { scale_x: f32, scale_y: f32 },
}

#[derive(Debug, Clone, PartialEq)]
pub struct EnemyGeometryDiagnostic {
    pub room_index: usize,
    pub room_name: String,
    pub instance_index: usize,
    pub instance_id: i32,
    pub object_id: i32,
    pub object_name: String,
    pub error: EnemyGeometryError,
}

fn enemy_instance_geometry(
    object: &GameObjectInfo,
    instance: &RoomObjectInstance,
    sprites: &HashMap<usize, SpriteData>,
) -> Result<Rect, EnemyGeometryError> {
    if object.parent_id != 11 {
        return Err(EnemyGeometryError::UnexpectedParent {
            parent_id: object.parent_id,
        });
    }
    let sprite_id = usize::try_from(object.sprite_id).map_err(|_| EnemyGeometryError::NoSprite)?;
    let sprite = sprites
        .get(&sprite_id)
        .ok_or(EnemyGeometryError::MissingSpriteResource {
            sprite_id: object.sprite_id,
        })?;
    if sprite.width == 0 || sprite.height == 0 {
        return Err(EnemyGeometryError::InvalidSpriteDimensions {
            sprite_id: object.sprite_id,
            width: sprite.width,
            height: sprite.height,
        });
    }
    if !instance.scale_x.is_finite()
        || !instance.scale_y.is_finite()
        || instance.scale_x == 0.0
        || instance.scale_y == 0.0
    {
        return Err(EnemyGeometryError::InvalidScale {
            scale_x: instance.scale_x,
            scale_y: instance.scale_y,
        });
    }

    let x0 = instance.x as f32 - sprite.origin_x as f32 * instance.scale_x;
    let x1 = instance.x as f32
        + (sprite.width as f32 - sprite.origin_x as f32) * instance.scale_x;
    let y0 = instance.y as f32 - sprite.origin_y as f32 * instance.scale_y;
    let y1 = instance.y as f32
        + (sprite.height as f32 - sprite.origin_y as f32) * instance.scale_y;
    Ok(Rect::new(
        x0.min(x1),
        y0.min(y1),
        (x1 - x0).abs(),
        (y1 - y0).abs(),
    ))
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub enum Facing {
    Left,
    Right,
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub enum PlayerState {
    Idle,
    Running,
    Jumping,
    Falling,
    Attacking,
    Hurt,
    Dead,
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub enum WeaponType {
    Pistol,
    Shotgun,
    AssaultRifle,
    RocketLauncher,
    Sword,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Player {
    pub x: f32,
    pub y: f32,
    pub vx: f32,
    pub vy: f32,
    pub width: f32,
    pub height: f32,
    pub facing: Facing,
    pub state: PlayerState,
    pub on_ground: bool,
    pub health: i32,
    pub max_health: i32,
    pub gems: u32,
    pub coins: u32,
    pub current_weapon: WeaponType,
    pub unlocked_weapons: Vec<WeaponType>,
    pub attack_cooldown: f32,
    pub invulnerable_timer: f32,
    pub sprite_id: i32,
}

impl Player {
    pub fn new(x: f32, y: f32) -> Self {
        Self {
            x,
            y,
            vx: 0.0,
            vy: 0.0,
            width: 24.0,
            height: 38.0,
            facing: Facing::Right,
            state: PlayerState::Idle,
            on_ground: false,
            health: 100,
            max_health: 100,
            gems: 0,
            coins: 0,
            current_weapon: WeaponType::Pistol,
            unlocked_weapons: vec![WeaponType::Pistol],
            attack_cooldown: 0.0,
            invulnerable_timer: 0.0,
            sprite_id: -1,
        }
    }

    pub fn bounds(&self) -> Rect {
        Rect::new(self.x, self.y, self.width, self.height)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub enum EnemyType {
    Bandit,
    Enemy2,
    Slime,
    FireSlime,
    Bat,
    Zombie,
    Skeleton,
    Shooter,
    KnifeBandit,
    FireHulk,
    Boss,
}

fn enemy_type_for_object_name(name: &str) -> Option<EnemyType> {
    match name {
        "obj_enemy" => Some(EnemyType::Bandit),
        "obj_enemy2" => Some(EnemyType::Enemy2),
        "obj_slime" => Some(EnemyType::Slime),
        "obj_fireslime" => Some(EnemyType::FireSlime),
        "obj_bat" => Some(EnemyType::Bat),
        "obj_zombie" => Some(EnemyType::Zombie),
        "obj_skeleton" => Some(EnemyType::Skeleton),
        "obj_shooter1" | "obj_shooter2" => Some(EnemyType::Shooter),
        "obj_knifebandit" => Some(EnemyType::KnifeBandit),
        "obj_firehulk" => Some(EnemyType::FireHulk),
        _ => None,
    }
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Enemy {
    pub id: usize,
    pub enemy_type: EnemyType,
    pub x: f32,
    pub y: f32,
    pub vx: f32,
    pub vy: f32,
    pub width: f32,
    pub height: f32,
    pub health: i32,
    pub max_health: i32,
    pub facing: Facing,
    pub sprite_id: i32,
}

impl Enemy {
    pub fn bounds(&self) -> Rect {
        Rect::new(self.x, self.y, self.width, self.height)
    }
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Projectile {
    pub x: f32,
    pub y: f32,
    pub vx: f32,
    pub vy: f32,
    pub width: f32,
    pub height: f32,
    pub damage: i32,
    pub is_player: bool,
    pub lifetime: f32,
}

impl Projectile {
    pub fn bounds(&self) -> Rect {
        Rect::new(self.x, self.y, self.width, self.height)
    }
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct SolidTile {
    pub rect: Rect,
    pub is_boulder: bool,
    pub sprite_id: i32,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct GemDrop {
    pub x: f32,
    pub y: f32,
    pub is_coin: bool,
    pub collected: bool,
    pub sprite_id: i32,
    pub room_instance_id: Option<i32>,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct WeaponPickup {
    pub rect: Rect,
    pub weapon: WeaponType,
    pub sprite_id: i32,
    pub collected: bool,
    pub room_instance_id: Option<i32>,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Decoration {
    pub rect: Rect,
    pub sprite_id: i32,
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub struct WaterRegion {
    pub rect: Rect,
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub struct HazardRegion {
    pub rect: Rect,
    pub sprite_id: i32,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct WarpPoint {
    pub rect: Rect,
    pub creation_code: i32,
    pub sprite_id: i32,
    pub target_room: usize,
    pub target_x: f32,
    pub target_y: f32,
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub struct Checkpoint {
    pub room_index: usize,
    pub x: f32,
    pub y: f32,
}

#[derive(Debug, Clone, Default)]
pub struct InputState {
    pub move_left: bool,
    pub move_right: bool,
    pub jump: bool,
    pub attack: bool,
    pub switch_weapon: bool,
}

pub struct GameWorld {
    pub current_room_index: usize,
    pub current_room_name: String,
    pub room_width: f32,
    pub room_height: f32,
    pub player: Player,
    pub solids: Vec<SolidTile>,
    pub platforms: Vec<SolidTile>,
    pub enemies: Vec<Enemy>,
    pub enemy_geometry_diagnostics: Vec<EnemyGeometryDiagnostic>,
    pub projectiles: Vec<Projectile>,
    pub gems: Vec<GemDrop>,
    pub weapon_pickups: Vec<WeaponPickup>,
    pub decorations: Vec<Decoration>,
    pub water_regions: Vec<WaterRegion>,
    pub hazards: Vec<HazardRegion>,
    pub warps: Vec<WarpPoint>,
    pub camera_x: f32,
    pub camera_y: f32,
    pub pending_room_warp: Option<usize>,
    pub pending_spawn: Option<(f32, f32, Facing)>,
    pub checkpoint: Checkpoint,
    pub respawn_timer: f32,
    pub collected_instance_ids: BTreeSet<i32>,
}

impl GameWorld {
    pub fn new() -> Self {
        Self {
            current_room_index: 0,
            current_room_name: "rm_town".into(),
            room_width: 1024.0,
            room_height: 768.0,
            player: Player::new(96.0, 96.0),
            solids: Vec::new(),
            platforms: Vec::new(),
            enemies: Vec::new(),
            enemy_geometry_diagnostics: Vec::new(),
            projectiles: Vec::new(),
            gems: Vec::new(),
            weapon_pickups: Vec::new(),
            decorations: Vec::new(),
            water_regions: Vec::new(),
            hazards: Vec::new(),
            warps: Vec::new(),
            camera_x: 0.0,
            camera_y: 0.0,
            pending_room_warp: None,
            pending_spawn: None,
            checkpoint: Checkpoint { room_index: 0, x: 100.0, y: 100.0 },
            respawn_timer: 0.0,
            collected_instance_ids: BTreeSet::new(),
        }
    }

    pub fn restore_from_save(&mut self, save: &save::SaveData) {
        self.current_room_index = save.current_room;
        self.checkpoint = save.checkpoint;
        self.player.x = save.checkpoint.x;
        self.player.y = save.checkpoint.y;
        self.player.vx = 0.0;
        self.player.vy = 0.0;
        self.player.health = save.max_health;
        self.player.max_health = save.max_health;
        self.player.gems = save.gems;
        self.player.coins = save.coins;
        self.player.current_weapon = save.current_weapon;
        self.player.unlocked_weapons = save.unlocked_weapons.clone();
        self.collected_instance_ids = save.collected_instance_ids.iter().copied().collect();
    }

    pub fn load_room(
        &mut self,
        room_idx: usize,
        room: &RoomData,
        objects_info: &[GameObjectInfo],
        sprites: &HashMap<usize, SpriteData>,
        warp_targets: &HashMap<i32, WarpTarget>,
    ) {
        self.current_room_index = room_idx;
        self.current_room_name = room.name.clone();
        self.room_width = room.width as f32;
        self.room_height = room.height as f32;
        self.solids.clear();
        self.platforms.clear();
        self.enemies.clear();
        self.enemy_geometry_diagnostics.clear();
        self.projectiles.clear();
        self.gems.clear();
        self.weapon_pickups.clear();
        self.decorations.clear();
        self.water_regions.clear();
        self.hazards.clear();
        self.warps.clear();
        self.pending_room_warp = None;

        for (inst_idx, inst) in room.objects.iter().enumerate() {
            let obj_info = objects_info.get(inst.object_id as usize);
            let obj_name = obj_info.map(|o| o.name.as_str()).unwrap_or("");
            let spr_id = obj_info.map(|o| o.sprite_id).unwrap_or(-1);

            match obj_name {
                "obj_player" => {
                    self.player.x = inst.x as f32;
                    self.player.y = inst.y as f32;
                    self.player.vx = 0.0;
                    self.player.vy = 0.0;
                    self.player.sprite_id = spr_id;
                    self.checkpoint = Checkpoint {
                        room_index: room_idx,
                        x: inst.x as f32,
                        y: inst.y as f32,
                    };
                }
                "obj_wall" | "obj_wall_2" | "obj_woodblock" | "obj_iceblock" => {
                    self.solids.push(SolidTile {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        is_boulder: false,
                        sprite_id: spr_id,
                    });
                }
                "obj_platform" => {
                    self.platforms.push(SolidTile {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 8.0),
                        is_boulder: false,
                        sprite_id: spr_id,
                    });
                }
                "obj_boulder" | "obj_boulderblock" | "obj_bossboulder" => {
                    self.solids.push(SolidTile {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        is_boulder: true,
                        sprite_id: spr_id,
                    });
                }
                "obj_gem" => {
                    if self.collected_instance_ids.contains(&inst.instance_id) {
                        continue;
                    }
                    self.gems.push(GemDrop {
                        x: inst.x as f32,
                        y: inst.y as f32,
                        is_coin: false,
                        collected: false,
                        sprite_id: spr_id,
                        room_instance_id: Some(inst.instance_id),
                    });
                }
                "obj_coin" | "obj_silvercoin" => {
                    if self.collected_instance_ids.contains(&inst.instance_id) {
                        continue;
                    }
                    self.gems.push(GemDrop {
                        x: inst.x as f32,
                        y: inst.y as f32,
                        is_coin: true,
                        collected: false,
                        sprite_id: spr_id,
                        room_instance_id: Some(inst.instance_id),
                    });
                }
                "obj_shotgun" => {
                    if self.collected_instance_ids.contains(&inst.instance_id) {
                        continue;
                    }
                    self.weapon_pickups.push(WeaponPickup {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        weapon: WeaponType::Shotgun,
                        sprite_id: spr_id,
                        collected: false,
                        room_instance_id: Some(inst.instance_id),
                    });
                }
                "obj_waterfill" | "obj_watersurface" => {
                    let rect = Rect::new(
                        inst.x as f32,
                        inst.y as f32,
                        32.0 * inst.scale_x.abs(),
                        32.0 * inst.scale_y.abs(),
                    );
                    self.decorations.push(Decoration {
                        rect,
                        sprite_id: spr_id,
                    });
                    self.water_regions.push(WaterRegion { rect });
                }
                "obj_spikes" => {
                    let rect = Rect::new(
                        inst.x as f32,
                        inst.y as f32,
                        SPIKE_SPRITE_WIDTH * inst.scale_x.abs(),
                        SPIKE_SPRITE_HEIGHT * inst.scale_y.abs(),
                    );
                    self.decorations.push(Decoration {
                        rect,
                        sprite_id: spr_id,
                    });
                    self.hazards.push(HazardRegion {
                        rect,
                        sprite_id: spr_id,
                    });
                }
                "obj_warpanywhere" => {
                    if let Some(target) = warp_targets.get(&inst.creation_code_id) {
                        self.warps.push(WarpPoint {
                            rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                            creation_code: inst.creation_code_id,
                            sprite_id: spr_id,
                            target_room: target.room_index,
                            target_x: target.x as f32,
                            target_y: target.y as f32,
                        });
                    }
                }
                name if enemy_type_for_object_name(name).is_some() => {
                    let enemy_type = enemy_type_for_object_name(name)
                        .expect("guarded enemy object name must have an enemy type");
                    let rect = match enemy_instance_geometry(
                        obj_info.expect("matched enemy object must have object info"),
                        inst,
                        sprites,
                    ) {
                        Ok(rect) => rect,
                        Err(error) => {
                            self.enemy_geometry_diagnostics.push(EnemyGeometryDiagnostic {
                                room_index: room_idx,
                                room_name: room.name.clone(),
                                instance_index: inst_idx,
                                instance_id: inst.instance_id,
                                object_id: inst.object_id,
                                object_name: obj_name.to_owned(),
                                error,
                            });
                            continue;
                        }
                    };
                    self.enemies.push(Enemy {
                        id: inst_idx,
                        enemy_type,
                        x: rect.x,
                        y: rect.y,
                        vx: -50.0,
                        vy: 0.0,
                        width: rect.w,
                        height: rect.h,
                        health: 30,
                        max_health: 30,
                        facing: Facing::Left,
                        sprite_id: spr_id,
                    });
                }
                _ => {}
            }
        }
    }

    pub fn player_is_in_water(&self) -> bool {
        let player_bounds = self.player.bounds();
        self.water_regions
            .iter()
            .any(|region| region.rect.intersects(&player_bounds))
    }

    fn begin_player_death(&mut self) {
        self.player.state = PlayerState::Dead;
        self.player.vx = 0.0;
        self.player.vy = 0.0;
        self.respawn_timer = 1.0;
        self.projectiles.clear();
    }

    pub fn update(&mut self, dt: f32, input: &InputState) {
        if self.player.health <= 0 || self.player.state == PlayerState::Dead {
            if self.player.state != PlayerState::Dead {
                self.begin_player_death();
            } else {
                self.respawn_timer -= dt;
                if self.respawn_timer <= 0.0 {
                    self.player.health = self.player.max_health;
                    self.player.x = self.checkpoint.x;
                    self.player.y = self.checkpoint.y;
                    self.player.invulnerable_timer = 1.0;
                    self.player.state = PlayerState::Falling;
                    self.pending_room_warp = Some(self.checkpoint.room_index);
                    self.pending_spawn = Some((
                        self.checkpoint.x,
                        self.checkpoint.y,
                        Facing::Right,
                    ));
                }
            }
            return;
        }

        let move_speed = 220.0;
        let normal_gravity = 950.0;
        let jump_force = -440.0;

        if self.player.attack_cooldown > 0.0 {
            self.player.attack_cooldown -= dt;
        }
        if self.player.invulnerable_timer > 0.0 {
            self.player.invulnerable_timer -= dt;
        }

        // Weapon switching only cycles weapons collected in the game world.
        if input.switch_weapon {
            if let Some(index) = self.player.unlocked_weapons.iter()
                .position(|weapon| *weapon == self.player.current_weapon)
            {
                let next = (index + 1) % self.player.unlocked_weapons.len();
                self.player.current_weapon = self.player.unlocked_weapons[next];
            }
        }

        // Horizontal Movement
        let mut move_dir = 0.0;
        if input.move_left {
            move_dir -= 1.0;
            self.player.facing = Facing::Left;
        }
        if input.move_right {
            move_dir += 1.0;
            self.player.facing = Facing::Right;
        }

        self.player.vx = move_dir * move_speed;
        let new_x = self.player.x + self.player.vx * dt;

        let player_rect_x = Rect::new(new_x, self.player.y, self.player.width, self.player.height);
        let mut collided_x = false;
        for s in &self.solids {
            if s.rect.intersects(&player_rect_x) {
                collided_x = true;
                if self.player.vx > 0.0 {
                    self.player.x = s.rect.x - self.player.width;
                } else if self.player.vx < 0.0 {
                    self.player.x = s.rect.x + s.rect.w;
                }
                break;
            }
        }
        if !collided_x {
            self.player.x = new_x;
        }

        // Vertical Movement + Gravity
        let player_in_water = self.player_is_in_water();
        let player_gravity = if player_in_water {
            PROVISIONAL_WATER_GRAVITY
        } else {
            normal_gravity
        };
        self.player.vy += player_gravity * dt;
        if player_in_water {
            self.player.vy = self.player.vy.min(PROVISIONAL_WATER_MAX_FALL_SPEED);
        }

        if input.jump && (self.player.on_ground || player_in_water) {
            self.player.vy = if player_in_water {
                PROVISIONAL_WATER_RISE_SPEED
            } else {
                jump_force
            };
            self.player.on_ground = false;
        }

        let new_y = self.player.y + self.player.vy * dt;
        let player_rect_y = Rect::new(self.player.x, new_y, self.player.width, self.player.height);
        let mut collided_y = false;

        self.player.on_ground = false;
        for s in &self.solids {
            if s.rect.intersects(&player_rect_y) {
                collided_y = true;
                if self.player.vy > 0.0 {
                    self.player.y = s.rect.y - self.player.height;
                    self.player.vy = 0.0;
                    self.player.on_ground = true;
                } else if self.player.vy < 0.0 {
                    self.player.y = s.rect.y + s.rect.h;
                    self.player.vy = 0.0;
                }
                break;
            }
        }
        if !collided_y && self.player.vy > 0.0 {
            let previous_bottom = self.player.y + self.player.height;
            let next_bottom = new_y + self.player.height;
            for platform in &self.platforms {
                let overlaps_x = self.player.x < platform.rect.x + platform.rect.w
                    && self.player.x + self.player.width > platform.rect.x;
                if overlaps_x
                    && previous_bottom <= platform.rect.y
                    && next_bottom >= platform.rect.y
                {
                    self.player.y = platform.rect.y - self.player.height;
                    self.player.vy = 0.0;
                    self.player.on_ground = true;
                    collided_y = true;
                    break;
                }
            }
        }
        if !collided_y {
            self.player.y = new_y;
        }

        if self.player.invulnerable_timer <= 0.0 {
            self.player.state = if !self.player.on_ground {
                if self.player.vy < 0.0 { PlayerState::Jumping } else { PlayerState::Falling }
            } else if move_dir != 0.0 {
                PlayerState::Running
            } else {
                PlayerState::Idle
            };
        }

        // Attack firing
        if input.attack && self.player.attack_cooldown <= 0.0 {
            self.player.attack_cooldown = match self.player.current_weapon {
                WeaponType::Pistol => 0.2,
                WeaponType::Shotgun => 0.5,
                WeaponType::AssaultRifle => 0.09,
                WeaponType::RocketLauncher => 0.8,
                WeaponType::Sword => 0.3,
            };

            let bullet_dir = if self.player.facing == Facing::Right { 1.0 } else { -1.0 };
            let spawn_x = if self.player.facing == Facing::Right {
                self.player.x + self.player.width
            } else {
                self.player.x - 12.0
            };

            match self.player.current_weapon {
                WeaponType::Pistol | WeaponType::AssaultRifle => {
                    self.projectiles.push(Projectile {
                        x: spawn_x,
                        y: self.player.y + 12.0,
                        vx: bullet_dir * 600.0,
                        vy: 0.0,
                        width: 10.0,
                        height: 6.0,
                        damage: 15,
                        is_player: true,
                        lifetime: 2.0,
                    });
                }
                WeaponType::Shotgun => {
                    for angle_offset in &[-80.0, 0.0, 80.0] {
                        self.projectiles.push(Projectile {
                            x: spawn_x,
                            y: self.player.y + 12.0,
                            vx: bullet_dir * 550.0,
                            vy: *angle_offset,
                            width: 8.0,
                            height: 6.0,
                            damage: 10,
                            is_player: true,
                            lifetime: 0.6,
                        });
                    }
                }
                WeaponType::Sword => {
                    self.projectiles.push(Projectile {
                        x: spawn_x,
                        y: self.player.y,
                        vx: bullet_dir * 150.0,
                        vy: 0.0,
                        width: 32.0,
                        height: 38.0,
                        damage: 35,
                        is_player: true,
                        lifetime: 0.15,
                    });
                }
                _ => {}
            }
        }

        // Update Projectiles
        for p in &mut self.projectiles {
            p.x += p.vx * dt;
            p.y += p.vy * dt;
            p.lifetime -= dt;
        }

        // Projectile collisions with solids
        self.projectiles.retain(|p| {
            if p.lifetime <= 0.0 {
                return false;
            }
            let pb = p.bounds();
            for s in &self.solids {
                if s.rect.intersects(&pb) {
                    return false;
                }
            }
            true
        });

        // Update Enemies AI & Physics
        for enemy in &mut self.enemies {
            match enemy.enemy_type {
                EnemyType::Bandit | EnemyType::Enemy2 | EnemyType::KnifeBandit | EnemyType::Slime | EnemyType::Zombie => {
                    enemy.vy += normal_gravity * dt;
                    let ex = enemy.x + enemy.vx * dt;
                    let ey = enemy.y + enemy.vy * dt;

                    let er_x = Rect::new(ex, enemy.y, enemy.width, enemy.height);
                    let mut e_collided_x = false;
                    for s in &self.solids {
                        if s.rect.intersects(&er_x) {
                            e_collided_x = true;
                            enemy.vx = -enemy.vx; // reverse direction
                            break;
                        }
                    }
                    if !e_collided_x {
                        enemy.x = ex;
                    }

                    let er_y = Rect::new(enemy.x, ey, enemy.width, enemy.height);
                    let mut e_collided_y = false;
                    for s in &self.solids {
                        if s.rect.intersects(&er_y) {
                            e_collided_y = true;
                            if enemy.vy > 0.0 {
                                enemy.y = s.rect.y - enemy.height;
                                enemy.vy = 0.0;
                            }
                            break;
                        }
                    }
                    if !e_collided_y {
                        enemy.y = ey;
                    }
                }
                EnemyType::Bat => {
                    // Bat flies towards player
                    let dx = self.player.x - enemy.x;
                    let dy = self.player.y - enemy.y;
                    let dist = (dx * dx + dy * dy).sqrt().max(1.0);
                    enemy.vx = (dx / dist) * 80.0;
                    enemy.vy = (dy / dist) * 80.0;
                    enemy.x += enemy.vx * dt;
                    enemy.y += enemy.vy * dt;
                }
                _ => {}
            }
        }

        // Projectile vs Enemy collision
        for p in &mut self.projectiles {
            if !p.is_player { continue; }
            let pb = p.bounds();
            for enemy in &mut self.enemies {
                if enemy.health > 0 && enemy.bounds().intersects(&pb) {
                    enemy.health -= p.damage;
                    p.lifetime = 0.0; // destroy projectile
                }
            }
        }

        // Remove dead enemies
        self.enemies.retain(|e| e.health > 0);

        // Player vs spike hazard collision. The full sprite rectangle is a
        // provisional hit region because the original collision mask is unknown.
        if self.player.invulnerable_timer <= 0.0 {
            let player_bounds = self.player.bounds();
            if self
                .hazards
                .iter()
                .any(|hazard| hazard.rect.intersects(&player_bounds))
            {
                self.player.health =
                    (self.player.health - PROVISIONAL_SPIKE_DAMAGE).max(0);
                self.player.invulnerable_timer =
                    PROVISIONAL_SPIKE_INVULNERABILITY_SECONDS;
                self.player.state = PlayerState::Hurt;
                if self.player.health == 0 {
                    self.begin_player_death();
                    return;
                }
            }
        }

        // Player vs Enemy collision
        if self.player.invulnerable_timer <= 0.0 {
            let p_bounds = self.player.bounds();
            for enemy in &self.enemies {
                if enemy.bounds().intersects(&p_bounds) {
                    self.player.health -= 15;
                    self.player.invulnerable_timer = 1.0;
                    self.player.state = PlayerState::Hurt;
                    if self.player.health < 0 { self.player.health = 0; }
                    break;
                }
            }
        }

        // Gems collection
        let p_rect = self.player.bounds();
        for gem in &mut self.gems {
            if !gem.collected {
                let g_rect = Rect::new(gem.x, gem.y, 20.0, 20.0);
                if p_rect.intersects(&g_rect) {
                    gem.collected = true;
                    if let Some(instance_id) = gem.room_instance_id {
                        self.collected_instance_ids.insert(instance_id);
                    }
                    if gem.is_coin {
                        self.player.coins += 1;
                    } else {
                        self.player.gems += 1;
                    }
                }
            }
        }

        for pickup in &mut self.weapon_pickups {
            if !pickup.collected && pickup.rect.intersects(&p_rect) {
                pickup.collected = true;
                if let Some(instance_id) = pickup.room_instance_id {
                    self.collected_instance_ids.insert(instance_id);
                }
                if !self.player.unlocked_weapons.contains(&pickup.weapon) {
                    self.player.unlocked_weapons.push(pickup.weapon);
                }
                self.player.current_weapon = pickup.weapon;
            }
        }

        // Warp Trigger
        for warp in &self.warps {
            if p_rect.intersects(&warp.rect) {
                self.pending_room_warp = Some(warp.target_room);
                self.pending_spawn = Some((warp.target_x, warp.target_y, self.player.facing));
                break;
            }
        }

        // Camera follow
        self.camera_x = (self.player.x - 480.0).clamp(0.0, (self.room_width - 960.0).max(0.0));
        self.camera_y = (self.player.y - 270.0).clamp(0.0, (self.room_height - 540.0).max(0.0));
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn movement_updates_player_state() {
        let mut world = GameWorld::new();
        world.player.on_ground = true;
        world.solids.push(SolidTile {
            rect: Rect::new(0.0, world.player.y + world.player.height, 1000.0, 32.0),
            is_boulder: false,
            sprite_id: -1,
        });
        world.update(
            1.0 / 60.0,
            &InputState { move_right: true, ..InputState::default() },
        );
        assert_eq!(world.player.state, PlayerState::Running);
    }

    #[test]
    fn dead_player_respawns_at_checkpoint() {
        let mut world = GameWorld::new();
        world.checkpoint = Checkpoint { room_index: 3, x: 96.0, y: 128.0 };
        world.player.health = 0;

        world.update(0.1, &InputState::default());
        assert_eq!(world.player.state, PlayerState::Dead);
        assert_eq!(world.pending_room_warp, None);

        world.update(1.1, &InputState::default());
        assert_eq!(world.pending_room_warp, Some(3));
        assert_eq!(world.pending_spawn, Some((96.0, 128.0, Facing::Right)));
        assert_eq!(world.player.health, world.player.max_health);
    }

    #[test]
    fn warp_uses_decoded_creation_code_target() {
        let mut world = GameWorld::new();
        world.player.x = 64.0;
        world.player.y = 64.0;
        world.player.facing = Facing::Left;
        world.warps.push(WarpPoint {
            rect: Rect::new(64.0, 64.0, 32.0, 32.0),
            creation_code: 804,
            sprite_id: -1,
            target_room: 1,
            target_x: 128.0,
            target_y: 492.0,
        });

        world.update(0.0, &InputState::default());
        assert_eq!(world.pending_room_warp, Some(1));
        assert_eq!(world.pending_spawn, Some((128.0, 492.0, Facing::Left)));
    }

    #[test]
    fn room_loader_maps_generic_enemy_instances() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "rm_level1".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 60, persistent: false,
            objects: vec![callys_asset::RoomObjectInstance {
                x: 800, y: 992, object_id: 0, instance_id: 1,
                creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
            }],
            tiles: Vec::new(),
        };
        let objects = vec![GameObjectInfo {
            id: 0, name: "obj_enemy".into(), sprite_id: 52,
            visible: true, solid: false, depth: 0, persistent: false, parent_id: 11,
            events: Vec::new(), physics_raw: Default::default(),
        }];
        let sprites = HashMap::from([(
            52,
            SpriteData {
                id: 52,
                name: "spr_enemy".into(),
                width: 64,
                height: 64,
                origin_x: 32,
                origin_y: 48,
                tpag_indices: Vec::new(),
            },
        )]);
        world.load_room(1, &room, &objects, &sprites, &HashMap::new());
        assert_eq!(world.enemies.len(), 1);
        assert_eq!(world.enemies[0].enemy_type, EnemyType::Bandit);
        assert_eq!(world.enemies[0].sprite_id, 52);
    }

    #[test]
    fn enemy_geometry_uses_object_sprite_origin_and_negative_instance_scale() {
        let object = GameObjectInfo {
            id: 7,
            name: "obj_bat".into(),
            sprite_id: 123,
            visible: true,
            solid: false,
            depth: 0,
            persistent: false,
            parent_id: 11,
            events: Vec::new(),
            physics_raw: Default::default(),
        };
        let instance = callys_asset::RoomObjectInstance {
            x: 100,
            y: 200,
            object_id: 7,
            instance_id: 42,
            creation_code_id: -1,
            scale_x: -2.0,
            scale_y: 0.5,
            color: 0xffff_ffff,
        };
        let sprites = HashMap::from([(
            123,
            callys_asset::SpriteData {
                id: 123,
                name: "test_sprite".into(),
                width: 20,
                height: 30,
                origin_x: 4,
                origin_y: 6,
                tpag_indices: Vec::new(),
            },
        )]);

        assert_eq!(
            enemy_instance_geometry(&object, &instance, &sprites),
            Ok(Rect::new(68.0, 197.0, 40.0, 15.0))
        );
    }

    #[test]
    fn enemy_geometry_rejects_unexpected_parent_inheritance() {
        let object = GameObjectInfo {
            id: 7,
            name: "obj_bat".into(),
            sprite_id: 123,
            visible: true,
            solid: false,
            depth: 0,
            persistent: false,
            parent_id: -100,
            events: Vec::new(),
            physics_raw: Default::default(),
        };
        let instance = callys_asset::RoomObjectInstance {
            x: 100,
            y: 200,
            object_id: 7,
            instance_id: 42,
            creation_code_id: -1,
            scale_x: 1.0,
            scale_y: 1.0,
            color: 0xffff_ffff,
        };
        let sprites = HashMap::from([(
            123,
            SpriteData {
                id: 123,
                name: "test_sprite".into(),
                width: 20,
                height: 30,
                origin_x: 4,
                origin_y: 6,
                tpag_indices: Vec::new(),
            },
        )]);

        assert_eq!(
            enemy_instance_geometry(&object, &instance, &sprites),
            Err(EnemyGeometryError::UnexpectedParent { parent_id: -100 })
        );
    }

    #[test]
    fn room_loader_uses_sprite_geometry_and_records_missing_sprite_diagnostics() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "geometry".into(),
            caption: String::new(),
            width: 320,
            height: 240,
            speed: 60,
            persistent: false,
            objects: vec![
                callys_asset::RoomObjectInstance {
                    x: 100,
                    y: 200,
                    object_id: 0,
                    instance_id: 10,
                    creation_code_id: -1,
                    scale_x: -2.0,
                    scale_y: 0.5,
                    color: 0xffff_ffff,
                },
                callys_asset::RoomObjectInstance {
                    x: 30,
                    y: 40,
                    object_id: 1,
                    instance_id: 11,
                    creation_code_id: -1,
                    scale_x: 1.0,
                    scale_y: 1.0,
                    color: 0xffff_ffff,
                },
            ],
            tiles: Vec::new(),
        };
        let objects = vec![
            GameObjectInfo {
                id: 0,
                name: "obj_bat".into(),
                sprite_id: 123,
                visible: true,
                solid: false,
                depth: 0,
                persistent: false,
                parent_id: 11,
                events: Vec::new(),
                physics_raw: Default::default(),
            },
            GameObjectInfo {
                id: 1,
                name: "obj_slime".into(),
                sprite_id: -1,
                visible: true,
                solid: false,
                depth: 0,
                persistent: false,
                parent_id: 11,
                events: Vec::new(),
                physics_raw: Default::default(),
            },
        ];
        let sprites = HashMap::from([(
            123,
            callys_asset::SpriteData {
                id: 123,
                name: "bat_test".into(),
                width: 20,
                height: 30,
                origin_x: 4,
                origin_y: 6,
                tpag_indices: Vec::new(),
            },
        )]);

        world.load_room(
            9,
            &room,
            &objects,
            &sprites,
            &HashMap::new(),
        );

        assert_eq!(world.enemies.len(), 1);
        assert_eq!(world.enemies[0].bounds(), Rect::new(68.0, 197.0, 40.0, 15.0));
        assert_eq!(world.enemy_geometry_diagnostics.len(), 1);
        assert_eq!(world.enemy_geometry_diagnostics[0].instance_id, 11);
        assert_eq!(
            world.enemy_geometry_diagnostics[0].error,
            EnemyGeometryError::NoSprite
        );
    }

    #[test]
    fn room_loader_applies_confirmed_enemy_sprite_geometry_and_origins() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "rm_level1".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 60, persistent: false,
            objects: vec![
                callys_asset::RoomObjectInstance {
                    x: 800, y: 992, object_id: 0, instance_id: 1,
                    creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
                },
                callys_asset::RoomObjectInstance {
                    x: 640, y: 512, object_id: 1, instance_id: 2,
                    creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
                },
            ],
            tiles: Vec::new(),
        };
        let objects = vec![
            GameObjectInfo {
                id: 0, name: "obj_enemy".into(), sprite_id: 52,
                visible: true, solid: false, depth: 0, persistent: false, parent_id: 11,
            events: Vec::new(), physics_raw: Default::default(),
            },
            GameObjectInfo {
                id: 1, name: "obj_knifebandit".into(), sprite_id: 59,
                visible: true, solid: false, depth: 0, persistent: false, parent_id: 11,
            events: Vec::new(), physics_raw: Default::default(),
            },
        ];
        let sprites = HashMap::from([
            (52, SpriteData {
                id: 52, name: "spr_enemy".into(), width: 64, height: 64,
                origin_x: 32, origin_y: 48, tpag_indices: Vec::new(),
            }),
            (59, SpriteData {
                id: 59, name: "spr_knifebandit".into(), width: 64, height: 48,
                origin_x: 32, origin_y: 24, tpag_indices: Vec::new(),
            }),
        ]);

        world.load_room(1, &room, &objects, &sprites, &HashMap::new());

        assert_eq!(world.enemies[0].bounds(), Rect::new(768.0, 944.0, 64.0, 64.0));
        assert_eq!(world.enemies[1].bounds(), Rect::new(608.0, 488.0, 64.0, 48.0));
    }

    #[test]
    fn ground_enemy_falls_until_it_reaches_solid_ground() {
        let mut world = GameWorld::new();
        world.player.x = 1000.0;
        world.player.y = 1000.0;
        world.enemies.push(Enemy {
            id: 1,
            enemy_type: EnemyType::Bandit,
            x: 100.0,
            y: 100.0,
            vx: 0.0,
            vy: 0.0,
            width: 64.0,
            height: 64.0,
            health: 30,
            max_health: 30,
            facing: Facing::Left,
            sprite_id: 52,
        });
        world.solids.push(SolidTile {
            rect: Rect::new(0.0, 300.0, 500.0, 32.0),
            is_boulder: false,
            sprite_id: -1,
        });

        for _ in 0..120 {
            world.update(1.0 / 60.0, &InputState::default());
        }

        assert_eq!(world.enemies[0].y, 300.0 - world.enemies[0].height);
        assert_eq!(world.enemies[0].vy, 0.0);
    }

    #[test]
    fn enemy2_falls_until_it_reaches_solid_ground() {
        let mut world = GameWorld::new();
        world.player.x = 1000.0;
        world.player.y = 1000.0;
        world.enemies.push(Enemy {
            id: 1,
            enemy_type: EnemyType::Enemy2,
            x: 100.0,
            y: 100.0,
            vx: 0.0,
            vy: 0.0,
            width: 32.0,
            height: 32.0,
            health: 30,
            max_health: 30,
            facing: Facing::Left,
            sprite_id: 62,
        });
        world.solids.push(SolidTile {
            rect: Rect::new(0.0, 300.0, 500.0, 32.0),
            is_boulder: false,
            sprite_id: -1,
        });

        for _ in 0..120 {
            world.update(1.0 / 60.0, &InputState::default());
        }

        assert_eq!(world.enemies[0].y, 300.0 - world.enemies[0].height);
        assert_eq!(world.enemies[0].vy, 0.0);
    }

    #[test]
    fn collecting_weapon_pickup_unlocks_and_equips_it() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.weapon_pickups.push(WeaponPickup {
            rect: Rect::new(100.0, 100.0, 32.0, 32.0),
            weapon: WeaponType::Shotgun,
            sprite_id: 127,
            collected: false,
            room_instance_id: None,
        });

        world.update(0.0, &InputState::default());
        assert!(world.player.unlocked_weapons.contains(&WeaponType::Shotgun));
        assert_eq!(world.player.current_weapon, WeaponType::Shotgun);
        assert!(world.weapon_pickups[0].collected);
    }

    #[test]
    fn collected_room_weapon_is_not_recreated_when_room_reloads() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "rm_level1".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 60, persistent: false,
            objects: vec![callys_asset::RoomObjectInstance {
                x: 100, y: 100, object_id: 0, instance_id: 4242,
                creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
            }], tiles: Vec::new(),
        };
        let objects = vec![GameObjectInfo {
            id: 0, name: "obj_shotgun".into(), sprite_id: 127,
            visible: true, solid: false, depth: 0, persistent: false, parent_id: -100,
            events: Vec::new(), physics_raw: Default::default(),
        }];

        world.load_room(1, &room, &objects, &HashMap::new(), &HashMap::new());
        assert_eq!(world.weapon_pickups[0].room_instance_id, Some(4242));
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.update(0.0, &InputState::default());
        assert!(world.collected_instance_ids.contains(&4242));

        world.load_room(1, &room, &objects, &HashMap::new(), &HashMap::new());
        assert!(world.weapon_pickups.is_empty());
    }

    #[test]
    fn collected_room_gem_and_coin_stay_absent_after_visiting_another_room() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "rm_level1".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 60, persistent: false,
            objects: vec![
                callys_asset::RoomObjectInstance {
                    x: 100, y: 100, object_id: 0, instance_id: 5001,
                    creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
                },
                callys_asset::RoomObjectInstance {
                    x: 100, y: 100, object_id: 1, instance_id: 5002,
                    creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
                },
            ], tiles: Vec::new(),
        };
        let other_room = RoomData {
            name: "rm_level2".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 60, persistent: false, objects: Vec::new(), tiles: Vec::new(),
        };
        let objects = vec![
            GameObjectInfo {
                id: 0, name: "obj_gem".into(), sprite_id: 1,
                visible: true, solid: false, depth: 0, persistent: false, parent_id: -100,
            events: Vec::new(), physics_raw: Default::default(),
            },
            GameObjectInfo {
                id: 1, name: "obj_coin".into(), sprite_id: 2,
                visible: true, solid: false, depth: 0, persistent: false, parent_id: -100,
            events: Vec::new(), physics_raw: Default::default(),
            },
        ];

        world.load_room(1, &room, &objects, &HashMap::new(), &HashMap::new());
        assert_eq!(world.gems.iter().map(|drop| drop.room_instance_id).collect::<Vec<_>>(), vec![Some(5001), Some(5002)]);
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.update(0.0, &InputState::default());
        assert_eq!((world.player.gems, world.player.coins), (1, 1));
        assert!(world.collected_instance_ids.contains(&5001));
        assert!(world.collected_instance_ids.contains(&5002));

        world.load_room(2, &other_room, &objects, &HashMap::new(), &HashMap::new());
        world.load_room(1, &room, &objects, &HashMap::new(), &HashMap::new());
        assert!(world.gems.is_empty());
    }

    #[test]
    fn runtime_drop_has_no_room_identity_and_is_not_persisted_as_collected() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.gems.push(GemDrop {
            x: 100.0,
            y: 100.0,
            is_coin: false,
            collected: false,
            sprite_id: 1,
            room_instance_id: None,
        });

        world.update(0.0, &InputState::default());

        assert!(world.gems[0].collected);
        assert!(world.collected_instance_ids.is_empty());
    }

    #[test]
    fn room_loader_preserves_scaled_water_geometry() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "rm_level1".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 60, persistent: false,
            objects: vec![callys_asset::RoomObjectInstance {
                x: 1568, y: 1056, object_id: 0, instance_id: 1,
                creation_code_id: -1, scale_x: 6.0, scale_y: 2.0, color: 0xffff_ffff,
            }], tiles: Vec::new(),
        };
        let objects = vec![GameObjectInfo {
            id: 0, name: "obj_waterfill".into(), sprite_id: 103,
            visible: true, solid: false, depth: 0, persistent: false, parent_id: -100,
            events: Vec::new(), physics_raw: Default::default(),
        }];
        world.load_room(1, &room, &objects, &HashMap::new(), &HashMap::new());
        assert_eq!(world.decorations.len(), 1);
        assert_eq!(world.decorations[0].rect, Rect::new(1568.0, 1056.0, 192.0, 64.0));
        assert_eq!(world.decorations[0].sprite_id, 103);
        assert_eq!(world.water_regions.len(), 1);
        assert_eq!(world.water_regions[0].rect, Rect::new(1568.0, 1056.0, 192.0, 64.0));

        world.player.x = 1600.0;
        world.player.y = 1060.0;
        assert!(world.player_is_in_water());
    }

    #[test]
    fn water_limits_falling_player_to_provisional_terminal_speed() {
        let mut accelerating = GameWorld::new();
        accelerating.player.x = 100.0;
        accelerating.player.y = 100.0;
        accelerating.water_regions.push(WaterRegion {
            rect: Rect::new(80.0, 80.0, 200.0, 200.0),
        });

        accelerating.update(0.1, &InputState::default());
        assert_eq!(accelerating.player.vy, PROVISIONAL_WATER_GRAVITY * 0.1);

        let mut terminal = GameWorld::new();
        terminal.player.x = 100.0;
        terminal.player.y = 100.0;
        terminal.player.vy = 500.0;
        terminal.water_regions.push(WaterRegion {
            rect: Rect::new(80.0, 80.0, 200.0, 200.0),
        });

        terminal.update(0.1, &InputState::default());
        assert_eq!(terminal.player.vy, PROVISIONAL_WATER_MAX_FALL_SPEED);
    }

    #[test]
    fn jump_input_makes_player_rise_while_in_water() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.player.on_ground = false;
        world.water_regions.push(WaterRegion {
            rect: Rect::new(80.0, 80.0, 200.0, 200.0),
        });

        world.update(
            0.1,
            &InputState { jump: true, ..InputState::default() },
        );

        assert_eq!(world.player.vy, PROVISIONAL_WATER_RISE_SPEED);
        assert!(world.player.y < 100.0);
    }

    #[test]
    fn leaving_water_horizontally_restores_normal_gravity_same_tick() {
        let mut world = GameWorld::new();
        world.player.x = 70.0;
        world.player.y = 100.0;
        world.player.vy = 0.0;
        world.water_regions.push(WaterRegion {
            rect: Rect::new(0.0, 80.0, 100.0, 200.0),
        });
        assert!(world.player_is_in_water());

        world.update(
            0.2,
            &InputState { move_right: true, ..InputState::default() },
        );

        assert!(!world.player_is_in_water());
        assert_eq!(world.player.vy, 950.0 * 0.2);
    }

    #[test]
    fn room_loader_keeps_platforms_thin_and_one_way() {
        let mut world = GameWorld::new();
        let room = RoomData {
            name: "rm_level1".into(), caption: String::new(), width: 2048, height: 1280,
            speed: 30, persistent: false,
            objects: vec![callys_asset::RoomObjectInstance {
                x: 320, y: 400, object_id: 0, instance_id: 1,
                creation_code_id: -1, scale_x: 1.0, scale_y: 1.0, color: 0xffff_ffff,
            }], tiles: Vec::new(),
        };
        let objects = vec![GameObjectInfo {
            id: 0, name: "obj_platform".into(), sprite_id: 35,
            visible: true, solid: false, depth: 0, persistent: false, parent_id: 34,
            events: Vec::new(), physics_raw: Default::default(),
        }];

        world.load_room(1, &room, &objects, &HashMap::new(), &HashMap::new());

        assert!(world.solids.is_empty());
        assert_eq!(world.platforms.len(), 1);
        assert_eq!(world.platforms[0].rect, Rect::new(320.0, 400.0, 32.0, 8.0));
    }

    #[test]
    fn falling_player_lands_on_one_way_platform() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 350.0;
        world.player.vy = 100.0;
        world.platforms.push(SolidTile {
            rect: Rect::new(96.0, 400.0, 64.0, 8.0),
            is_boulder: false,
            sprite_id: 35,
        });

        world.update(0.1, &InputState::default());

        assert_eq!(world.player.y, 400.0 - world.player.height);
        assert_eq!(world.player.vy, 0.0);
        assert!(world.player.on_ground);
    }

    #[test]
    fn spike_contact_applies_provisional_damage_once() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.hazards.push(HazardRegion {
            rect: Rect::new(100.0, 100.0, 32.0, 32.0),
            sprite_id: 93,
        });

        world.update(0.0, &InputState::default());

        assert_eq!(world.player.health, 100 - PROVISIONAL_SPIKE_DAMAGE);
        assert_eq!(world.player.state, PlayerState::Hurt);
        assert_eq!(
            world.player.invulnerable_timer,
            PROVISIONAL_SPIKE_INVULNERABILITY_SECONDS
        );
    }

    #[test]
    fn spike_contact_is_suppressed_while_player_is_invulnerable() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.hazards.push(HazardRegion {
            rect: Rect::new(100.0, 100.0, 32.0, 32.0),
            sprite_id: 93,
        });
        world.update(0.0, &InputState::default());
        let health_after_first_contact = world.player.health;

        world.update(0.1, &InputState::default());

        assert_eq!(world.player.health, health_after_first_contact);
        assert!(world.player.invulnerable_timer > 0.0);
    }

    #[test]
    fn spike_contact_damages_again_after_invulnerability_expires() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.hazards.push(HazardRegion {
            rect: Rect::new(100.0, 100.0, 32.0, 32.0),
            sprite_id: 93,
        });
        world.solids.push(SolidTile {
            rect: Rect::new(0.0, 138.0, 1000.0, 32.0),
            is_boulder: false,
            sprite_id: -1,
        });
        world.update(0.0, &InputState::default());

        for _ in 0..11 {
            world.update(0.1, &InputState::default());
        }

        assert_eq!(world.player.health, 100 - 2 * PROVISIONAL_SPIKE_DAMAGE);
        assert_eq!(world.player.state, PlayerState::Hurt);
    }

    #[test]
    fn lethal_spike_contact_uses_checkpoint_respawn_path() {
        let mut world = GameWorld::new();
        world.checkpoint = Checkpoint {
            room_index: 2,
            x: 64.0,
            y: 480.0,
        };
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.player.health = PROVISIONAL_SPIKE_DAMAGE;
        world.hazards.push(HazardRegion {
            rect: Rect::new(100.0, 100.0, 32.0, 32.0),
            sprite_id: 93,
        });

        world.update(0.0, &InputState::default());
        assert_eq!(world.player.health, 0);
        assert_eq!(world.player.state, PlayerState::Dead);

        world.update(1.1, &InputState::default());
        assert_eq!(world.player.health, world.player.max_health);
        assert_eq!(world.pending_room_warp, Some(2));
        assert_eq!(world.pending_spawn, Some((64.0, 480.0, Facing::Right)));
    }

    #[test]
    fn real_asset_all_supported_enemy_instances_use_sprite_origin_scale_geometry() {
        use std::collections::BTreeMap;

        const SUPPORTED: [&str; 11] = [
            "obj_enemy",
            "obj_enemy2",
            "obj_slime",
            "obj_fireslime",
            "obj_bat",
            "obj_zombie",
            "obj_skeleton",
            "obj_shooter1",
            "obj_shooter2",
            "obj_knifebandit",
            "obj_firehulk",
        ];

        let asset_path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../assets/game.droid");
        let asset = callys_asset::GameDroidAsset::parse(asset_path).expect("parse game.droid");
        assert_eq!(asset.rooms.len(), 114);

        let mut report: BTreeMap<String, (i32, u32, u32, i32, i32, usize, usize)> =
            BTreeMap::new();
        for name in SUPPORTED {
            let object = asset
                .objects
                .iter()
                .find(|object| object.name == name)
                .unwrap_or_else(|| panic!("supported object {name}"));
            let sprite = usize::try_from(object.sprite_id)
                .ok()
                .and_then(|id| asset.sprites.get(&id));
            let (width, height, origin_x, origin_y) = sprite
                .map(|sprite| (sprite.width, sprite.height, sprite.origin_x, sprite.origin_y))
                .unwrap_or_default();
            report.insert(
                name.to_owned(),
                (object.sprite_id, width, height, origin_x, origin_y, 0, 0),
            );
        }

        for (room_index, room) in asset.rooms.iter().enumerate() {
            let mut world = GameWorld::new();
            world.load_room(
                room_index,
                room,
                &asset.objects,
                &asset.sprites,
                &asset.warp_targets,
            );

            let supported_instances: Vec<_> = room
                .objects
                .iter()
                .enumerate()
                .filter_map(|(instance_index, instance)| {
                    let object = usize::try_from(instance.object_id)
                        .ok()
                        .and_then(|id| asset.objects.get(id))?;
                    SUPPORTED
                        .contains(&object.name.as_str())
                        .then_some((instance_index, instance, object))
                })
                .collect();
            assert_eq!(
                world.enemies.len() + world.enemy_geometry_diagnostics.len(),
                supported_instances.len(),
                "room[{room_index}] {} classified every supported enemy",
                room.name
            );

            for (instance_index, instance, object) in supported_instances {
                let entry = report.get_mut(&object.name).expect("report class");
                entry.5 += 1;
                let sprite = usize::try_from(object.sprite_id)
                    .ok()
                    .and_then(|id| asset.sprites.get(&id));
                let valid_scale = instance.scale_x.is_finite()
                    && instance.scale_y.is_finite()
                    && instance.scale_x != 0.0
                    && instance.scale_y != 0.0;
                let Some(sprite) = sprite.filter(|sprite| {
                    sprite.width > 0 && sprite.height > 0 && valid_scale
                }) else {
                    entry.6 += 1;
                    assert!(world.enemy_geometry_diagnostics.iter().any(|diagnostic| {
                        diagnostic.instance_index == instance_index
                            && diagnostic.instance_id == instance.instance_id
                            && diagnostic.object_name == object.name
                    }));
                    continue;
                };

                let left = (instance.x as f32 - sprite.origin_x as f32 * instance.scale_x)
                    .min(instance.x as f32
                        + (sprite.width as f32 - sprite.origin_x as f32) * instance.scale_x);
                let top = (instance.y as f32 - sprite.origin_y as f32 * instance.scale_y)
                    .min(instance.y as f32
                        + (sprite.height as f32 - sprite.origin_y as f32) * instance.scale_y);
                let expected = Rect::new(
                    left,
                    top,
                    sprite.width as f32 * instance.scale_x.abs(),
                    sprite.height as f32 * instance.scale_y.abs(),
                );
                assert_eq!(
                    enemy_instance_geometry(object, instance, &asset.sprites),
                    Ok(expected),
                    "room[{room_index}] {} instance {instance_index}",
                    room.name
                );
                let enemy = world
                    .enemies
                    .iter()
                    .find(|enemy| enemy.id == instance_index)
                    .expect("valid supported instance loaded");
                assert_eq!(enemy.sprite_id, object.sprite_id);
                assert_eq!(
                    enemy.bounds(),
                    expected,
                    "room[{room_index}] {} instance {instance_index}",
                    room.name
                );
                assert!(enemy.width > 0.0 && enemy.height > 0.0);
            }
        }

        for (name, (sprite_id, width, height, origin_x, origin_y, instances, anomalies))
            in &report
        {
            println!(
                "{name}: sprite={sprite_id} size={width}x{height} origin=({origin_x},{origin_y}) instances={instances} anomalies={anomalies}"
            );
        }
        assert!(report.values().all(|entry| entry.6 == 0));
    }

    #[test]
    fn real_rm_level2_loads_confirmed_enemy_composition_and_enemy2_geometry() {
        let asset_path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../assets/game.droid");
        let asset = callys_asset::GameDroidAsset::parse(asset_path).expect("parse game.droid");
        let level2 = &asset.rooms[2];
        assert_eq!(level2.name, "rm_level2");
        let enemy2_object = &asset.objects[22];
        assert_eq!(enemy2_object.name, "obj_enemy2");
        assert_eq!(enemy2_object.sprite_id, 62);
        assert_eq!(enemy2_object.parent_id, 11);
        assert!(!enemy2_object.solid);
        let enemy2_sprite = asset.sprites.get(&62).expect("spr_enemy2");
        assert_eq!(enemy2_sprite.name, "spr_enemy2");
        assert_eq!((enemy2_sprite.width, enemy2_sprite.height), (32, 32));
        assert_eq!((enemy2_sprite.origin_x, enemy2_sprite.origin_y), (16, 16));
        let enemy2_instances: Vec<_> = level2
            .objects
            .iter()
            .filter(|instance| instance.object_id == 22)
            .collect();
        assert_eq!(enemy2_instances.len(), 1);
        let enemy2_instance = enemy2_instances[0];
        assert_eq!((enemy2_instance.x, enemy2_instance.y), (288, 784));
        assert_eq!((enemy2_instance.scale_x, enemy2_instance.scale_y), (1.0, 1.0));

        let mut world = GameWorld::new();
        world.load_room(2, level2, &asset.objects, &asset.sprites, &asset.warp_targets);

        assert_eq!(
            world
                .enemies
                .iter()
                .filter(|enemy| enemy.enemy_type == EnemyType::Bandit)
                .count(),
            6
        );
        assert_eq!(
            world
                .enemies
                .iter()
                .filter(|enemy| enemy.enemy_type == EnemyType::Enemy2)
                .count(),
            1
        );
        assert_eq!(
            world
                .enemies
                .iter()
                .filter(|enemy| enemy.enemy_type == EnemyType::KnifeBandit)
                .count(),
            1
        );
        let enemy2 = world
            .enemies
            .iter()
            .find(|enemy| enemy.enemy_type == EnemyType::Enemy2)
            .expect("rm_level2 enemy2");
        assert_eq!(enemy2.sprite_id, 62);
        assert_eq!(enemy2.bounds(), Rect::new(272.0, 768.0, 32.0, 32.0));
    }

    #[test]
    fn real_rm_level2_enemy2_takes_player_projectile_damage() {
        let asset_path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../assets/game.droid");
        let asset = callys_asset::GameDroidAsset::parse(asset_path).expect("parse game.droid");
        let mut world = GameWorld::new();
        world.load_room(2, &asset.rooms[2], &asset.objects, &asset.sprites, &asset.warp_targets);
        world.player.x = -1000.0;
        world.player.y = -1000.0;
        world.solids.clear();
        let enemy2 = world
            .enemies
            .iter()
            .find(|enemy| enemy.enemy_type == EnemyType::Enemy2)
            .expect("rm_level2 enemy2");
        let initial_health = enemy2.health;
        let bounds = enemy2.bounds();
        world.projectiles.push(Projectile {
            x: bounds.x,
            y: bounds.y,
            vx: 0.0,
            vy: 0.0,
            width: bounds.w,
            height: bounds.h,
            damage: 15,
            is_player: true,
            lifetime: 1.0,
        });

        world.update(0.0, &InputState::default());

        let enemy2 = world
            .enemies
            .iter()
            .find(|enemy| enemy.enemy_type == EnemyType::Enemy2)
            .expect("damaged enemy2 remains alive");
        assert_eq!(enemy2.health, initial_health - 15);
    }

    #[test]
    fn real_asset_has_no_spikes_in_rm_level1_and_loads_rm_level2_spikes() {
        let asset_path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../assets/game.droid");
        let asset = callys_asset::GameDroidAsset::parse(asset_path).expect("parse game.droid");
        let level1 = &asset.rooms[1];
        let level2 = &asset.rooms[2];
        let spike_count = |room: &RoomData| {
            room.objects
                .iter()
                .filter(|instance| {
                    asset.objects[instance.object_id as usize].name == "obj_spikes"
                })
                .count()
        };
        assert_eq!(level1.name, "rm_level1");
        assert_eq!(spike_count(level1), 0);
        assert_eq!(level2.name, "rm_level2");
        assert_eq!(spike_count(level2), 27);

        let spike_object = asset
            .objects
            .iter()
            .find(|object| object.name == "obj_spikes")
            .expect("obj_spikes resource");
        assert!(!spike_object.solid);
        assert_eq!(spike_object.parent_id, -100);
        let spike_sprite = &asset.sprites[&(spike_object.sprite_id as usize)];
        assert_eq!(
            (spike_sprite.width, spike_sprite.height),
            (32, 32)
        );
        assert_eq!((spike_sprite.origin_x, spike_sprite.origin_y), (0, 0));

        let level2_spikes: Vec<_> = level2
            .objects
            .iter()
            .filter(|instance| instance.object_id as usize == spike_object.id)
            .collect();
        let expected_x = [
            800, 832, 864, 896, 928, 960, 992, 1024, 1056, 1632, 1600, 1568,
            1536, 1504, 1472, 1440, 1408, 1376, 1344, 1312, 1280, 1248, 1216,
            1184, 1152, 1120, 1088,
        ];
        assert_eq!(
            level2_spikes.iter().map(|instance| instance.x).collect::<Vec<_>>(),
            expected_x
        );
        assert!(level2_spikes.iter().all(|instance| {
            instance.y == 1152 && instance.scale_x == 1.0 && instance.scale_y == 1.0
        }));

        let mut world = GameWorld::new();
        world.load_room(2, level2, &asset.objects, &asset.sprites, &asset.warp_targets);

        assert_eq!(world.hazards.len(), 27);
        let spike_decorations: Vec<_> = world
            .decorations
            .iter()
            .filter(|decoration| decoration.sprite_id == spike_object.sprite_id)
            .collect();
        assert_eq!(spike_decorations.len(), 27);
        assert!(world
            .solids
            .iter()
            .all(|solid| solid.sprite_id != spike_object.sprite_id));
        assert_eq!(world.hazards[0].rect, Rect::new(800.0, 1152.0, 32.0, 32.0));
        assert_eq!(world.hazards[26].rect, Rect::new(1088.0, 1152.0, 32.0, 32.0));
        assert_eq!(world.hazards[0].sprite_id, 93);
        assert_eq!(spike_decorations[0].rect, world.hazards[0].rect);
        assert_eq!(spike_decorations[26].rect, world.hazards[26].rect);
    }
}
