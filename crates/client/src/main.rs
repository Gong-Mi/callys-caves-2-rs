use std::env;
use std::path::Path;
use std::time::{Duration, Instant};

use callys_asset::GameDroidAsset;
use callys_core::{Facing, GameWorld, InputState, PlayerState};
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
        "[callys-caves-2-rs] Asset parsed successfully! Name: '{}', Objects: {}, Rooms: {}",
        asset.game_name,
        asset.objects.len(),
        asset.rooms.len()
    );

    let mut world = GameWorld::new();
    if let Some(first_room) = asset.rooms.first() {
        println!(
            "[callys-caves-2-rs] Loading room: '{}' (width: {}, height: {}, objects: {})",
            first_room.name,
            first_room.width,
            first_room.height,
            first_room.objects.len()
        );
        world.load_room(first_room, &asset.objects);
    } else {
        return Err("No rooms found in game asset".into());
    }

    let sdl_context = sdl2::init()?;
    let video_subsystem = sdl_context.video()?;

    let window = video_subsystem
        .window("Cally's Caves 2 - 64-bit Native Rust", 800, 600)
        .position_centered()
        .opengl()
        .build()?;

    let mut canvas = window.into_canvas().accelerated().present_vsync().build()?;
    let mut event_pump = sdl_context.event_pump()?;

    let mut input = InputState::default();
    let mut last_time = Instant::now();

    println!("[callys-caves-2-rs] Engine initialized! Starting main loop...");
    'running: loop {
        let now = Instant::now();
        let dt = now.duration_since(last_time).as_secs_f32();
        last_time = now;

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
                    Keycode::J | Keycode::Z => input.attack = true,
                    _ => {}
                },
                Event::KeyUp {
                    keycode: Some(code),
                    ..
                } => match code {
                    Keycode::A | Keycode::Left => input.move_left = false,
                    Keycode::D | Keycode::Right => input.move_right = false,
                    Keycode::Space | Keycode::W | Keycode::Up => input.jump = false,
                    Keycode::J | Keycode::Z => input.attack = false,
                    _ => {}
                },
                _ => {}
            }
        }

        // Fixed / clamped delta time update
        let clamped_dt = dt.min(0.033);
        world.update(clamped_dt, &input);

        // Render
        canvas.set_draw_color(Color::RGB(20, 24, 38));
        canvas.clear();

        let cam_x = world.camera_x;
        let cam_y = world.camera_y;

        // Draw Solids (Walls & Boulders)
        for solid in &world.solids {
            let rx = (solid.rect.x - cam_x) as i32;
            let ry = (solid.rect.y - cam_y) as i32;
            let rw = solid.rect.w as u32;
            let rh = solid.rect.h as u32;

            if solid.is_boulder {
                canvas.set_draw_color(Color::RGB(139, 90, 43));
            } else {
                canvas.set_draw_color(Color::RGB(70, 80, 95));
            }
            let _ = canvas.fill_rect(SdlRect::new(rx, ry, rw, rh));
            canvas.set_draw_color(Color::RGB(40, 45, 55));
            let _ = canvas.draw_rect(SdlRect::new(rx, ry, rw, rh));
        }

        // Draw Gems
        canvas.set_draw_color(Color::RGB(255, 215, 0));
        for gem in &world.gems {
            if !gem.collected {
                let gx = (gem.x - cam_x) as i32;
                let gy = (gem.y - cam_y) as i32;
                let _ = canvas.fill_rect(SdlRect::new(gx, gy, 16, 16));
            }
        }

        // Draw Warps
        canvas.set_draw_color(Color::RGBA(100, 200, 255, 128));
        for warp in &world.warps {
            let wx = (warp.rect.x - cam_x) as i32;
            let wy = (warp.rect.y - cam_y) as i32;
            let _ = canvas.draw_rect(SdlRect::new(wx, wy, warp.rect.w as u32, warp.rect.h as u32));
        }

        // Draw Player
        let px = (world.player.x - cam_x) as i32;
        let py = (world.player.y - cam_y) as i32;
        let pw = world.player.width as u32;
        let ph = world.player.height as u32;

        match world.player.state {
            PlayerState::Idle => canvas.set_draw_color(Color::RGB(230, 80, 80)),
            PlayerState::Running => canvas.set_draw_color(Color::RGB(255, 120, 60)),
            PlayerState::Jumping | PlayerState::Falling => canvas.set_draw_color(Color::RGB(255, 200, 80)),
            _ => canvas.set_draw_color(Color::RGB(230, 80, 80)),
        }
        let _ = canvas.fill_rect(SdlRect::new(px, py, pw, ph));

        // Facing indicator
        canvas.set_draw_color(Color::RGB(255, 255, 255));
        let eye_x = if world.player.facing == Facing::Right { px + pw as i32 - 6 } else { px + 2 };
        let _ = canvas.fill_rect(SdlRect::new(eye_x, py + 6, 4, 4));

        canvas.present();
        std::thread::sleep(Duration::from_millis(16));
    }

    println!("[callys-caves-2-rs] Game exited cleanly.");
    Ok(())
}
