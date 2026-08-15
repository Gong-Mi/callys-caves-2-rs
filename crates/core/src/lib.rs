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
    pub selected_weapon: usize,
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
            selected_weapon: 0,
        }
    }

    pub fn bounds(&self) -> Rect {
        Rect::new(self.x, self.y, self.width, self.height)
    }
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct SolidTile {
    pub rect: Rect,
    pub is_boulder: bool,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct GemDrop {
    pub x: f32,
    pub y: f32,
    pub collected: bool,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct WarpPoint {
    pub rect: Rect,
    pub target_creation_code: i32,
}

#[derive(Debug, Clone, Default)]
pub struct InputState {
    pub move_left: bool,
    pub move_right: bool,
    pub jump: bool,
    pub attack: bool,
}

pub struct GameWorld {
    pub current_room_name: String,
    pub room_width: f32,
    pub room_height: f32,
    pub player: Player,
    pub solids: Vec<SolidTile>,
    pub gems: Vec<GemDrop>,
    pub warps: Vec<WarpPoint>,
    pub camera_x: f32,
    pub camera_y: f32,
}

impl GameWorld {
    pub fn new() -> Self {
        Self {
            current_room_name: "rm_town".into(),
            room_width: 1024.0,
            room_height: 768.0,
            player: Player::new(100.0, 100.0),
            solids: Vec::new(),
            gems: Vec::new(),
            warps: Vec::new(),
            camera_x: 0.0,
            camera_y: 0.0,
        }
    }

    pub fn load_room(&mut self, room: &RoomData, objects_info: &[GameObjectInfo]) {
        self.current_room_name = room.name.clone();
        self.room_width = room.width as f32;
        self.room_height = room.height as f32;
        self.solids.clear();
        self.gems.clear();
        self.warps.clear();

        for inst in &room.objects {
            let obj_name = objects_info
                .get(inst.object_id as usize)
                .map(|o| o.name.as_str())
                .unwrap_or("");

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
                    });
                }
                "obj_boulder" => {
                    self.solids.push(SolidTile {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        is_boulder: true,
                    });
                }
                "obj_gem" => {
                    self.gems.push(GemDrop {
                        x: inst.x as f32,
                        y: inst.y as f32,
                        collected: false,
                    });
                }
                "obj_warpanywhere" => {
                    self.warps.push(WarpPoint {
                        rect: Rect::new(inst.x as f32, inst.y as f32, 32.0, 32.0),
                        target_creation_code: inst.creation_code_id,
                    });
                }
                _ => {}
            }
        }
    }

    pub fn update(&mut self, dt: f32, input: &InputState) {
        let speed = 200.0;
        let gravity = 900.0;
        let jump_force = -420.0;

        // X movement
        let mut move_dir = 0.0;
        if input.move_left {
            move_dir -= 1.0;
            self.player.facing = Facing::Left;
        }
        if input.move_right {
            move_dir += 1.0;
            self.player.facing = Facing::Right;
        }

        self.player.vx = move_dir * speed;
        let new_x = self.player.x + self.player.vx * dt;

        // X collision
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

        // Y movement + Gravity
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

        // Update player state
        if !self.player.on_ground {
            if self.player.vy < 0.0 {
                self.player.state = PlayerState::Jumping;
            } else {
                self.player.state = PlayerState::Falling;
            }
        } else if self.player.vx.abs() > 10.0 {
            self.player.state = PlayerState::Running;
        } else {
            self.player.state = PlayerState::Idle;
        }

        // Gem collection check
        let player_rect = self.player.bounds();
        for gem in &mut self.gems {
            if !gem.collected {
                let gem_rect = Rect::new(gem.x, gem.y, 24.0, 24.0);
                if player_rect.intersects(&gem_rect) {
                    gem.collected = true;
                    self.player.gems += 1;
                }
            }
        }

        // Camera follow
        self.camera_x = self.player.x - 400.0;
        self.camera_y = self.player.y - 300.0;
        if self.camera_x < 0.0 { self.camera_x = 0.0; }
        if self.camera_y < 0.0 { self.camera_y = 0.0; }
    }
}
