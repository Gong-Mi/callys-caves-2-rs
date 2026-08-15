use std::collections::HashMap;
use std::env;
use std::path::Path;
use std::time::{Duration, Instant};

use callys_asset::{GameDroidAsset, SpriteData, TpagItem};
use callys_core::{Facing, GameWorld, InputState, PlayerState, WeaponType};
use image::GenericImageView;
use sdl2::event::Event;
use sdl2::keyboard::Keycode;
use sdl2::pixels::{Color, PixelFormatEnum};
use sdl2::rect::Rect as SdlRect;
use sdl2::render::{Texture, TextureCreator};
use sdl2::video::WindowContext;

pub struct TextureAtlas<'a> {
    pub textures: Vec<Texture<'a>>,
}

impl<'a> TextureAtlas<'a> {
    pub fn load(
        texture_creator: &'a TextureCreator<WindowContext>,
        base_dir: &Path,
    ) -> Result<Self, Box<dyn std::error::Error>> {
        let mut textures = Vec::new();
        for idx in 0..4 {
            let tex_path = base_dir.join(format!("textures/texture_{}.png", idx));
            if tex_path.exists() {
                let img = image::open(&tex_path)?;
                let (width, height) = img.dimensions();
                let rgba = img.to_rgba8();

                let mut texture = texture_creator.create_texture_streaming(
                    PixelFormatEnum::ABGR8888,
                    width,
                    height,
                )?;
                texture.update(None, &rgba, (width * 4) as usize)?;
                texture.set_blend_mode(sdl2::render::BlendMode::Blend);
                textures.push(texture);
            }
        }
        Ok(Self { textures })
    }
}

pub fn draw_sprite(
    canvas: &mut sdl2::render::Canvas<sdl2::video::Window>,
    atlases: &TextureAtlas,
    sprite: &SpriteData,
    tpag_items: &HashMap<usize, TpagItem>,
    frame: usize,
    dest_x: i32,
    dest_y: i32,
    flip_x: bool,
) {
    if sprite.tpag_indices.is_empty() {
        return;
    }
    let tpag_idx = sprite.tpag_indices[frame % sprite.tpag_indices.len()] as usize;
    if let Some(tpag) = tpag_items.get(&tpag_idx) {
        let tex_id = tpag.tex_id as usize;
        if let Some(texture) = atlases.textures.get(tex_id) {
            let src_rect = SdlRect::new(tpag.x as i32, tpag.y as i32, tpag.w as u32, tpag.h as u32);
            let dst_x = dest_x - sprite.origin_x + tpag.rx as i32;
            let dst_y = dest_y - sprite.origin_y + tpag.ry as i32;
            let dst_rect = SdlRect::new(dst_x, dst_y, tpag.w as u32, tpag.h as u32);

            let _ = canvas.copy_ex(
                texture,
                Some(src_rect),
                Some(dst_rect),
                0.0,
                None,
                flip_x,
                false,
            );
        }
    }
}

pub fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = env::args().collect();
    let droid_path = if args.len() > 1 {
        args[1].clone()
    } else {
        "/data/data/com.termux/files/usr/tmp/cally_caves_2/apk/assets/game.droid".into()
    };

    println!("[callys-caves-2-rs] Loading game asset from: {}", droid_path);
    let asset = GameDroidAsset::parse(Path::new(&droid_path))?;
    println!(
        "[callys-caves-2-rs] Asset parsed! Rooms: {}, Objects: {}, Sprites: {}, TPAG: {}",
        asset.rooms.len(),
        asset.objects.len(),
        asset.sprites.len(),
        asset.tpag_items.len()
    );

    let mut world = GameWorld::new();
    if let Some(first_room) = asset.rooms.first() {
        println!(
            "[callys-caves-2-rs] Starting Room 0: '{}' (width: {}, height: {}, objects: {})",
            first_room.name,
            first_room.width,
            first_room.height,
            first_room.objects.len()
        );
        world.load_room(0, first_room, &asset.objects);
    } else {
        return Err("No rooms found in game asset".into());
    }

    let sdl_context = sdl2::init()?;
    let video_subsystem = sdl_context.video()?;

    let window = video_subsystem
        .window("Cally's Caves 2 - 64-bit Native Rust Engine", 960, 540)
        .position_centered()
        .opengl()
        .build()?;

    let mut canvas = window.into_canvas().accelerated().present_vsync().build()?;
    let texture_creator = canvas.texture_creator();

    let asset_dir = Path::new("/data/data/com.termux/files/home/callys-caves-2-rs/assets");
    let atlases = TextureAtlas::load(&texture_creator, asset_dir)?;
    println!("[callys-caves-2-rs] Loaded {} texture atlases into GPU memory!", atlases.textures.len());

    let mut event_pump = sdl_context.event_pump()?;
    let mut input = InputState::default();
    let mut last_time = Instant::now();
    let mut frame_count: usize = 0;

    println!("[callys-caves-2-rs] Engine active! Controls: [A/D] Move | [Space/W] Jump | [J/Z] Shoot | [Tab/1-5] Weapon");
    'running: loop {
        let now = Instant::now();
        let dt = now.duration_since(last_time).as_secs_f32();
        last_time = now;
        frame_count += 1;

        input.switch_weapon = false;
        for event in event_pump.poll_iter() {
            match event {
                Event::Quit { .. }
                | Event::KeyDown {
                    keycode: Some(Keycode::Escape),
                    ..
                } => break 'running,
                Event::KeyDown {
                    keycode: Some(code),
                    ..
                } => match code {
                    Keycode::A | Keycode::Left => input.move_left = true,
                    Keycode::D | Keycode::Right => input.move_right = true,
                    Keycode::Space | Keycode::W | Keycode::Up => input.jump = true,
                    Keycode::J | Keycode::Z | Keycode::K => input.attack = true,
                    Keycode::Tab => input.switch_weapon = true,
                    Keycode::Num1 => world.player.current_weapon = WeaponType::Pistol,
                    Keycode::Num2 => world.player.current_weapon = WeaponType::Shotgun,
                    Keycode::Num3 => world.player.current_weapon = WeaponType::AssaultRifle,
                    Keycode::Num4 => world.player.current_weapon = WeaponType::RocketLauncher,
                    Keycode::Num5 => world.player.current_weapon = WeaponType::Sword,
                    _ => {}
                },
                Event::KeyUp {
                    keycode: Some(code),
                    ..
                } => match code {
                    Keycode::A | Keycode::Left => input.move_left = false,
                    Keycode::D | Keycode::Right => input.move_right = false,
                    Keycode::Space | Keycode::W | Keycode::Up => input.jump = false,
                    Keycode::J | Keycode::Z | Keycode::K => input.attack = false,
                    _ => {}
                },
                _ => {}
            }
        }

        // Physics Update
        let clamped_dt = dt.min(0.033);
        world.update(clamped_dt, &input);

        // Room Transition Handler
        if let Some(target_room_idx) = world.pending_room_warp.take() {
            if let Some(next_room) = asset.rooms.get(target_room_idx) {
                println!(
                    "[callys-caves-2-rs] Teleporting to Room {}: '{}'",
                    target_room_idx, next_room.name
                );
                world.load_room(target_room_idx, next_room, &asset.objects);
            }
        }

        // Render Frame
        canvas.set_draw_color(Color::RGB(15, 18, 30));
        canvas.clear();

        let cam_x = world.camera_x;
        let cam_y = world.camera_y;

        // 1. Draw Level Solids (Walls & Boulders)
        for solid in &world.solids {
            let rx = (solid.rect.x - cam_x) as i32;
            let ry = (solid.rect.y - cam_y) as i32;
            let rw = solid.rect.w as u32;
            let rh = solid.rect.h as u32;

            if solid.sprite_id >= 0 {
                if let Some(spr) = asset.sprites.get(&(solid.sprite_id as usize)) {
                    draw_sprite(
                        &mut canvas,
                        &atlases,
                        spr,
                        &asset.tpag_items,
                        0,
                        rx,
                        ry,
                        false,
                    );
                } else {
                    canvas.set_draw_color(Color::RGB(65, 75, 95));
                    let _ = canvas.fill_rect(SdlRect::new(rx, ry, rw, rh));
                }
            } else {
                if solid.is_boulder {
                    canvas.set_draw_color(Color::RGB(150, 95, 45));
                } else {
                    canvas.set_draw_color(Color::RGB(65, 75, 95));
                }
                let _ = canvas.fill_rect(SdlRect::new(rx, ry, rw, rh));
            }
        }

        // 2. Draw Gems & Coins
        for gem in &world.gems {
            if !gem.collected {
                let gx = (gem.x - cam_x) as i32;
                let gy = (gem.y - cam_y) as i32;
                if gem.is_coin {
                    canvas.set_draw_color(Color::RGB(220, 220, 100));
                } else {
                    canvas.set_draw_color(Color::RGB(80, 220, 255));
                }
                let _ = canvas.fill_rect(SdlRect::new(gx, gy, 18, 18));
            }
        }

        // 3. Draw Teleporters / Warps
        for warp in &world.warps {
            let wx = (warp.rect.x - cam_x) as i32;
            let wy = (warp.rect.y - cam_y) as i32;
            canvas.set_draw_color(Color::RGBA(140, 220, 255, 180));
            let _ = canvas.draw_rect(SdlRect::new(wx, wy, warp.rect.w as u32, warp.rect.h as u32));
        }

        // 4. Draw Enemies
        for enemy in &world.enemies {
            let ex = (enemy.x - cam_x) as i32;
            let ey = (enemy.y - cam_y) as i32;
            let ew = enemy.width as u32;
            let eh = enemy.height as u32;

            let anim_frame = (frame_count / 10) % 4;
            if enemy.sprite_id >= 0 {
                if let Some(spr) = asset.sprites.get(&(enemy.sprite_id as usize)) {
                    draw_sprite(
                        &mut canvas,
                        &atlases,
                        spr,
                        &asset.tpag_items,
                        anim_frame,
                        ex,
                        ey,
                        enemy.facing == Facing::Left,
                    );
                } else {
                    canvas.set_draw_color(Color::RGB(220, 60, 60));
                    let _ = canvas.fill_rect(SdlRect::new(ex, ey, ew, eh));
                }
            } else {
                canvas.set_draw_color(Color::RGB(220, 60, 60));
                let _ = canvas.fill_rect(SdlRect::new(ex, ey, ew, eh));
            }

            // Enemy HP bar
            let hp_pct = (enemy.health as f32 / enemy.max_health as f32).max(0.0);
            canvas.set_draw_color(Color::RGB(40, 40, 40));
            let _ = canvas.fill_rect(SdlRect::new(ex, ey - 6, ew, 4));
            canvas.set_draw_color(Color::RGB(40, 220, 40));
            let _ = canvas.fill_rect(SdlRect::new(ex, ey - 6, (ew as f32 * hp_pct) as u32, 4));
        }

        // 5. Draw Projectiles
        for p in &world.projectiles {
            let px = (p.x - cam_x) as i32;
            let py = (p.y - cam_y) as i32;
            if p.is_player {
                canvas.set_draw_color(Color::RGB(255, 240, 100));
            } else {
                canvas.set_draw_color(Color::RGB(255, 80, 80));
            }
            let _ = canvas.fill_rect(SdlRect::new(px, py, p.width as u32, p.height as u32));
        }

        // 6. Draw Player (Cally Sprite)
        let px = (world.player.x - cam_x) as i32;
        let py = (world.player.y - cam_y) as i32;
        let pw = world.player.width as u32;
        let ph = world.player.height as u32;

        let player_spr_id = 177; // Cally player sprite in OBJT/SPRT table
        let p_anim_frame = match world.player.state {
            PlayerState::Running => (frame_count / 6) % 6,
            PlayerState::Jumping => 2,
            PlayerState::Falling => 4,
            _ => 0,
        };

        if let Some(spr) = asset.sprites.get(&player_spr_id) {
            draw_sprite(
                &mut canvas,
                &atlases,
                spr,
                &asset.tpag_items,
                p_anim_frame,
                px,
                py,
                world.player.facing == Facing::Left,
            );
        } else {
            if world.player.invulnerable_timer > 0.0 && ((world.player.invulnerable_timer * 15.0) as i32 % 2 == 0) {
                canvas.set_draw_color(Color::RGBA(255, 255, 255, 128));
            } else {
                match world.player.state {
                    PlayerState::Idle => canvas.set_draw_color(Color::RGB(240, 80, 80)),
                    PlayerState::Running => canvas.set_draw_color(Color::RGB(255, 130, 60)),
                    PlayerState::Jumping | PlayerState::Falling => canvas.set_draw_color(Color::RGB(255, 210, 80)),
                    PlayerState::Hurt => canvas.set_draw_color(Color::RGB(255, 255, 255)),
                    _ => canvas.set_draw_color(Color::RGB(240, 80, 80)),
                }
            }
            let _ = canvas.fill_rect(SdlRect::new(px, py, pw, ph));
        }

        // 7. Draw HUD Overlay
        // Health Bar
        canvas.set_draw_color(Color::RGB(50, 50, 50));
        let _ = canvas.fill_rect(SdlRect::new(16, 16, 204, 20));
        let player_hp_pct = (world.player.health as f32 / world.player.max_health as f32).max(0.0);
        canvas.set_draw_color(Color::RGB(230, 40, 40));
        let _ = canvas.fill_rect(SdlRect::new(18, 18, (200.0 * player_hp_pct) as u32, 16));

        // Weapon Selector HUD Box
        canvas.set_draw_color(Color::RGB(30, 35, 50));
        let _ = canvas.fill_rect(SdlRect::new(16, 42, 160, 24));
        canvas.set_draw_color(Color::RGB(80, 200, 255));
        let _ = canvas.draw_rect(SdlRect::new(16, 42, 160, 24));

        canvas.present();
        std::thread::sleep(Duration::from_millis(16));
    }

    println!("[callys-caves-2-rs] Main loop completed cleanly.");
    Ok(())
}
