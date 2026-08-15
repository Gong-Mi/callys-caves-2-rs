pub mod save;

use callys_asset::{GameObjectInfo, RoomData, WarpTarget};
use std::collections::HashMap;
use serde::{Deserialize, Serialize};

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
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct WeaponPickup {
    pub rect: Rect,
    pub weapon: WeaponType,
    pub sprite_id: i32,
    pub collected: bool,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Decoration {
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
    pub projectiles: Vec<Projectile>,
    pub gems: Vec<GemDrop>,
    pub weapon_pickups: Vec<WeaponPickup>,
    pub decorations: Vec<Decoration>,
    pub warps: Vec<WarpPoint>,
    pub camera_x: f32,
    pub camera_y: f32,
    pub pending_room_warp: Option<usize>,
    pub pending_spawn: Option<(f32, f32, Facing)>,
    pub checkpoint: Checkpoint,
    pub respawn_timer: f32,
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
            projectiles: Vec::new(),
            gems: Vec::new(),
            weapon_pickups: Vec::new(),
            decorations: Vec::new(),
            warps: Vec::new(),
            camera_x: 0.0,
            camera_y: 0.0,
            pending_room_warp: None,
            pending_spawn: None,
            checkpoint: Checkpoint { room_index: 0, x: 100.0, y: 100.0 },
            respawn_timer: 0.0,
        }
    }

    pub fn load_room(
        &mut self,
        room_idx: usize,
        room: &RoomData,
        objects_info: &[GameObjectInfo],
        warp_targets: &HashMap<i32, WarpTarget>,
    ) {
        self.current_room_index = room_idx;
        self.current_room_name = room.name.clone();
        self.room_width = room.width as f32;
        self.room_height = room.height as f32;
        self.solids.clear();
        self.platforms.clear();
        self.enemies.clear();
        self.projectiles.clear();
        self.gems.clear();
        self.weapon_pickups.clear();
        self.decorations.clear();
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
                    self.gems.push(GemDrop {
                        x: inst.x as f32,
                        y: inst.y as f32,
                        is_coin: false,
                        collected: false,
                        sprite_id: spr_id,
                    });
                }
                "obj_coin" | "obj_silvercoin" => {
                    self.gems.push(GemDrop {
                        x: inst.x as f32,
                        y: inst.y as f32,
                        is_coin: true,
                        collected: false,
                        sprite_id: spr_id,
                    });
                }
                "obj_shotgun" => {
                    self.weapon_pickups.push(WeaponPickup {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        weapon: WeaponType::Shotgun,
                        sprite_id: spr_id,
                        collected: false,
                    });
                }
                "obj_waterfill" | "obj_watersurface" => {
                    self.decorations.push(Decoration {
                        rect: Rect::new(
                            inst.x as f32,
                            inst.y as f32,
                            32.0 * inst.scale_x.abs(),
                            32.0 * inst.scale_y.abs(),
                        ),
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
                "obj_enemy" | "obj_slime" | "obj_fireslime" | "obj_bat" | "obj_zombie" | "obj_skeleton"
                | "obj_shooter1" | "obj_shooter2" | "obj_knifebandit" | "obj_firehulk" => {
                    let enemy_type = match obj_name {
                        "obj_enemy" => EnemyType::Bandit,
                        "obj_slime" => EnemyType::Slime,
                        "obj_fireslime" => EnemyType::FireSlime,
                        "obj_bat" => EnemyType::Bat,
                        "obj_zombie" => EnemyType::Zombie,
                        "obj_skeleton" => EnemyType::Skeleton,
                        "obj_shooter1" | "obj_shooter2" => EnemyType::Shooter,
                        "obj_knifebandit" => EnemyType::KnifeBandit,
                        "obj_firehulk" => EnemyType::FireHulk,
                        _ => EnemyType::Slime,
                    };
                    let (x, y, width, height) = match obj_name {
                        "obj_enemy" => (
                            inst.x as f32 - 32.0,
                            inst.y as f32 - 48.0,
                            64.0,
                            64.0,
                        ),
                        "obj_knifebandit" => (
                            inst.x as f32 - 32.0,
                            inst.y as f32 - 24.0,
                            64.0,
                            48.0,
                        ),
                        _ => (inst.x as f32, inst.y as f32, 32.0, 32.0),
                    };
                    self.enemies.push(Enemy {
                        id: inst_idx,
                        enemy_type,
                        x,
                        y,
                        vx: -50.0,
                        vy: 0.0,
                        width,
                        height,
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

    pub fn update(&mut self, dt: f32, input: &InputState) {
        if self.player.health <= 0 || self.player.state == PlayerState::Dead {
            if self.player.state != PlayerState::Dead {
                self.player.state = PlayerState::Dead;
                self.player.vx = 0.0;
                self.player.vy = 0.0;
                self.respawn_timer = 1.0;
                self.projectiles.clear();
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
        let gravity = 950.0;
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
        self.player.vy += gravity * dt;

        if input.jump && self.player.on_ground {
            self.player.vy = jump_force;
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
                EnemyType::Bandit | EnemyType::KnifeBandit | EnemyType::Slime | EnemyType::Zombie => {
                    enemy.vy += gravity * dt;
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
        }];
        world.load_room(1, &room, &objects, &HashMap::new());
        assert_eq!(world.enemies.len(), 1);
        assert_eq!(world.enemies[0].enemy_type, EnemyType::Bandit);
        assert_eq!(world.enemies[0].sprite_id, 52);
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
            },
            GameObjectInfo {
                id: 1, name: "obj_knifebandit".into(), sprite_id: 53,
                visible: true, solid: false, depth: 0, persistent: false, parent_id: 11,
            },
        ];

        world.load_room(1, &room, &objects, &HashMap::new());

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
    fn collecting_weapon_pickup_unlocks_and_equips_it() {
        let mut world = GameWorld::new();
        world.player.x = 100.0;
        world.player.y = 100.0;
        world.weapon_pickups.push(WeaponPickup {
            rect: Rect::new(100.0, 100.0, 32.0, 32.0),
            weapon: WeaponType::Shotgun,
            sprite_id: 127,
            collected: false,
        });

        world.update(0.0, &InputState::default());
        assert!(world.player.unlocked_weapons.contains(&WeaponType::Shotgun));
        assert_eq!(world.player.current_weapon, WeaponType::Shotgun);
        assert!(world.weapon_pickups[0].collected);
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
        }];
        world.load_room(1, &room, &objects, &HashMap::new());
        assert_eq!(world.decorations.len(), 1);
        assert_eq!(world.decorations[0].rect, Rect::new(1568.0, 1056.0, 192.0, 64.0));
        assert_eq!(world.decorations[0].sprite_id, 103);
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
        }];

        world.load_room(1, &room, &objects, &HashMap::new());

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
}
