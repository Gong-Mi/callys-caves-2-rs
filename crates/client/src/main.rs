use std::env;
use std::path::Path;
use std::time::{Duration, Instant};

use callys_asset::GameDroidAsset;
use callys_core::{Facing, GameWorld, InputState, PlayerState, WeaponType};
use sdl2::event::Event;
use sdl2::keyboard::Keycode;
use sdl2::pixels::Color;
use sdl2::rect::Rect as SdlRect;

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
        .window("Cally's Caves 2 - Native 64-bit Rust Engine", 960, 540)
        .position_centered()
        .opengl()
        .build()?;

    let mut canvas = window.into_canvas().accelerated().present_vsync().build()?;
    let mut event_pump = sdl_context.event_pump()?;

    let mut input = InputState::default();
    let mut last_time = Instant::now();

    println!("[callys-caves-2-rs] Engine active! Controls: [A/D] Move | [Space/W] Jump | [J/Z] Shoot | [Tab/1-5] Weapon");
    'running: loop {
        let now = Instant::now();
        let dt = now.duration_since(last_time).as_secs_f32();
        last_time = now;

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

        // Fixed / clamped delta time update
        let clamped_dt = dt.min(0.033);
        world.update(clamped_dt, &input);

        // Room Warp Handler
        if let Some(target_room_idx) = world.pending_room_warp.take() {
            if let Some(next_room) = asset.rooms.get(target_room_idx) {
                println!(
                    "[callys-caves-2-rs] Teleporting to Room {}: '{}'",
                    target_room_idx, next_room.name
                );
                world.load_room(target_room_idx, next_room, &asset.objects);
            }
        }

        // Canvas Rendering
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

            if solid.is_boulder {
                canvas.set_draw_color(Color::RGB(150, 95, 45));
            } else {
                canvas.set_draw_color(Color::RGB(65, 75, 95));
            }
            let _ = canvas.fill_rect(SdlRect::new(rx, ry, rw, rh));
            canvas.set_draw_color(Color::RGB(35, 40, 50));
            let _ = canvas.draw_rect(SdlRect::new(rx, ry, rw, rh));
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

            canvas.set_draw_color(Color::RGB(220, 60, 60));
            let _ = canvas.fill_rect(SdlRect::new(ex, ey, ew, eh));

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

        // 6. Draw Player
        let px = (world.player.x - cam_x) as i32;
        let py = (world.player.y - cam_y) as i32;
        let pw = world.player.width as u32;
        let ph = world.player.height as u32;

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

        // Facing Eye
        canvas.set_draw_color(Color::RGB(255, 255, 255));
        let eye_x = if world.player.facing == Facing::Right { px + pw as i32 - 6 } else { px + 2 };
        let _ = canvas.fill_rect(SdlRect::new(eye_x, py + 6, 4, 4));

        // 7. Draw HUD Overlay
        // Health Bar
        canvas.set_draw_color(Color::RGB(50, 50, 50));
        let _ = canvas.fill_rect(SdlRect::new(16, 16, 204, 20));
        let player_hp_pct = (world.player.health as f32 / world.player.max_health as f32).max(0.0);
        canvas.set_draw_color(Color::RGB(230, 40, 40));
        let _ = canvas.fill_rect(SdlRect::new(18, 18, (200.0 * player_hp_pct) as u32, 16));

        // Weapon Selector HUD
        let _weapon_name = match world.player.current_weapon {
            WeaponType::Pistol => "PISTOL",
            WeaponType::Shotgun => "SHOTGUN",
            WeaponType::AssaultRifle => "ASSAULT RIFLE",
            WeaponType::RocketLauncher => "ROCKET LAUNCHER",
            WeaponType::Sword => "SWORD",
        };
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
