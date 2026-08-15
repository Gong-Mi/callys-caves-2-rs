//! Cally's Caves 2 - desktop binary using SDL2.
//! Enable with `--features desktop`.

use std::env;
use std::path::Path;
use std::time::{Duration, Instant};

use callys_client::{draw_frame, Framebuffer, GameState};
use sdl2::event::Event;
use sdl2::keyboard::Keycode;
use sdl2::pixels::PixelFormatEnum;
use sdl2::rect::Rect as SdlRect;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<String> = env::args().collect();
    let droid_path = if args.len() > 1 {
        args[1].clone()
    } else {
        "/data/data/com.termux/files/usr/tmp/cally_caves_2/apk/assets/game.droid".into()
    };

    println!("[callys-caves-2-rs] Loading game asset from: {}", droid_path);
    let mut state = GameState::new(Path::new(&droid_path))?;
    println!(
        "[callys-caves-2-rs] Asset parsed! Rooms: {}, Objects: {}, Sprites: {}",
        state.asset.rooms.len(),
        state.asset.objects.len(),
        state.asset.sprites.len()
    );

    let sdl_context = sdl2::init()?;
    let video = sdl_context.video()?;
    let window = video
        .window("Cally's Caves 2 - Native 64-bit Rust Engine", 960, 540)
        .position_centered()
        .opengl()
        .build()?;
    let mut canvas = window.into_canvas().accelerated().present_vsync().build()?;
    let tex_creator = canvas.texture_creator();

    let mut fb = Framebuffer::new(960, 540);
    let mut texture = tex_creator.create_texture_streaming(
        PixelFormatEnum::ABGR8888,
        960,
        540,
    )?;
    texture.set_blend_mode(sdl2::render::BlendMode::None);

    let mut event_pump = sdl_context.event_pump()?;
    let mut last = Instant::now();
    let frame_duration = Duration::from_millis(16);

    println!("[callys-caves-2-rs] Controls: A/D move | W/Space jump | J/Z attack | 1-5 weapon");

    'main: loop {
        for event in event_pump.poll_iter() {
            match event {
                Event::Quit { .. } => break 'main,
                Event::KeyDown {
                    keycode: Some(Keycode::Escape),
                    ..
                } => break 'main,
                Event::KeyDown {
                    keycode: Some(code),
                    ..
                } => match code {
                    Keycode::A | Keycode::Left => state.input.move_left = true,
                    Keycode::D | Keycode::Right => state.input.move_right = true,
                    Keycode::Space | Keycode::W | Keycode::Up => state.input.jump = true,
                    Keycode::J | Keycode::Z => state.input.attack = true,
                    Keycode::Num1 => state.world.player.current_weapon =
                        callys_core::WeaponType::Pistol,
                    Keycode::Num2 => state.world.player.current_weapon =
                        callys_core::WeaponType::Shotgun,
                    Keycode::Num3 => state.world.player.current_weapon =
                        callys_core::WeaponType::AssaultRifle,
                    Keycode::Num4 => state.world.player.current_weapon =
                        callys_core::WeaponType::RocketLauncher,
                    Keycode::Num5 => state.world.player.current_weapon =
                        callys_core::WeaponType::Sword,
                    _ => {}
                },
                Event::KeyUp {
                    keycode: Some(code),
                    ..
                } => match code {
                    Keycode::A | Keycode::Left => state.input.move_left = false,
                    Keycode::D | Keycode::Right => state.input.move_right = false,
                    Keycode::Space | Keycode::W | Keycode::Up => state.input.jump = false,
                    Keycode::J | Keycode::Z => state.input.attack = false,
                    _ => {}
                },
                _ => {}
            }
        }

        let now = Instant::now();
        let dt = now.duration_since(last).as_secs_f32().min(0.033);
        last = now;

        state.step(dt);
        draw_frame(
            &mut fb,
            &state,
            &state.asset.tpag_items,
            &state.asset.sprites,
        );

        texture.update(None, &fb.pixels, (fb.width * 4) as usize)?;
        canvas.clear();
        canvas.copy(
            &texture,
            None,
            Some(SdlRect::new(0, 0, 960, 540)),
        )?;
        canvas.present();

        std::thread::sleep(frame_duration);
    }
    Ok(())
}
