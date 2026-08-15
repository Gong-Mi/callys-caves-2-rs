use callys_asset::{GameObjectInfo, RoomData};
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
    pub attack_cooldown: f32,
    pub invulnerable_timer: f32,
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
            attack_cooldown: 0.0,
            invulnerable_timer: 0.0,
        }
    }

    pub fn bounds(&self) -> Rect {
        Rect::new(self.x, self.y, self.width, self.height)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Serialize, Deserialize)]
pub enum EnemyType {
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
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct WarpPoint {
    pub rect: Rect,
    pub creation_code: i32,
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
    pub enemies: Vec<Enemy>,
    pub projectiles: Vec<Projectile>,
    pub gems: Vec<GemDrop>,
    pub warps: Vec<WarpPoint>,
    pub camera_x: f32,
    pub camera_y: f32,
    pub pending_room_warp: Option<usize>,
}

impl GameWorld {
    pub fn new() -> Self {
        Self {
            current_room_index: 0,
            current_room_name: "rm_town".into(),
            room_width: 1024.0,
            room_height: 768.0,
            player: Player::new(100.0, 100.0),
            solids: Vec::new(),
            enemies: Vec::new(),
            projectiles: Vec::new(),
            gems: Vec::new(),
            warps: Vec::new(),
            camera_x: 0.0,
            camera_y: 0.0,
            pending_room_warp: None,
        }
    }

    pub fn load_room(&mut self, room_idx: usize, room: &RoomData, objects_info: &[GameObjectInfo]) {
        self.current_room_index = room_idx;
        self.current_room_name = room.name.clone();
        self.room_width = room.width as f32;
        self.room_height = room.height as f32;
        self.solids.clear();
        self.enemies.clear();
        self.projectiles.clear();
        self.gems.clear();
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
                }
                "obj_wall" | "obj_wall_2" => {
                    self.solids.push(SolidTile {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        is_boulder: false,
                        sprite_id: spr_id,
                    });
                }
                "obj_boulder" => {
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
                    });
                }
                "obj_coin" | "obj_silvercoin" => {
                    self.gems.push(GemDrop {
                        x: inst.x as f32,
                        y: inst.y as f32,
                        is_coin: true,
                        collected: false,
                    });
                }
                "obj_warpanywhere" => {
                    self.warps.push(WarpPoint {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        creation_code: inst.creation_code_id,
                    });
                }
                "obj_slime" | "obj_fireslime" | "obj_bat" | "obj_zombie" | "obj_skeleton"
                | "obj_shooter1" | "obj_shooter2" | "obj_knifebandit" | "obj_firehulk" => {
                    let enemy_type = match obj_name {
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
                    self.enemies.push(Enemy {
                        id: inst_idx,
                        enemy_type,
                        x: inst.x as f32,
                        y: inst.y as f32,
                        vx: -50.0,
                        vy: 0.0,
                        width: 32.0,
                        height: 32.0,
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
        let move_speed = 220.0;
        let gravity = 950.0;
        let jump_force = -440.0;

        if self.player.attack_cooldown > 0.0 {
            self.player.attack_cooldown -= dt;
        }
        if self.player.invulnerable_timer > 0.0 {
            self.player.invulnerable_timer -= dt;
        }

        // Weapon switching
        if input.switch_weapon {
            self.player.current_weapon = match self.player.current_weapon {
                WeaponType::Pistol => WeaponType::Shotgun,
                WeaponType::Shotgun => WeaponType::AssaultRifle,
                WeaponType::AssaultRifle => WeaponType::RocketLauncher,
                WeaponType::RocketLauncher => WeaponType::Sword,
                WeaponType::Sword => WeaponType::Pistol,
            };
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
        if !collided_y {
            self.player.y = new_y;
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
                EnemyType::Slime | EnemyType::Zombie => {
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
                    for s in &self.solids {
                        if s.rect.intersects(&er_y) {
                            if enemy.vy > 0.0 {
                                enemy.y = s.rect.y - enemy.height;
                                enemy.vy = 0.0;
                            }
                            break;
                        }
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

        // Warp Trigger
        for warp in &self.warps {
            if p_rect.intersects(&warp.rect) {
                // Trigger room transition to next room
                self.pending_room_warp = Some((self.current_room_index + 1) % 114);
                break;
            }
        }

        // Camera follow
        self.camera_x = self.player.x - 400.0;
        self.camera_y = self.player.y - 300.0;
        if self.camera_x < 0.0 { self.camera_x = 0.0; }
        if self.camera_y < 0.0 { self.camera_y = 0.0; }
    }
}
