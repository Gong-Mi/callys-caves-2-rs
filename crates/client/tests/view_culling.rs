//! Command-side view culling — contract `gpu-command-backend.md` slice 2.
//!
//! Two different claims have to hold at once, and the equivalence gate alone
//! only covers the first:
//!
//! 1. **The guard cannot change a pixel.** It rejects a command only when the
//!    box `blit_sprite_gm` itself clips against misses the framebuffer *and* the
//!    placeholder an unresolved command falls back to (a 32x32 box at the
//!    command position, not at the sprite anchor) misses it too. These tests
//!    rasterise the same real frames twice — guard on, guard off — and compare
//!    the buffers byte for byte.
//! 2. **The guard actually fires on the real parameters.** A fast path that
//!    never matches anything passes (1) trivially. The counters are read on the
//!    same real frames, over the room the contract measured (rm_level17, room
//!    25: 806 commands per frame, ~71 inside the 448x252 view rect).
use callys_client::{
    draw_frame, reset_view_cull_stats, set_view_cull_enabled, view_cull_stats, Framebuffer,
    GameState, ViewCullStats,
};
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::DrawCommand;
use callys_core::save::SaveData;
use callys_core::{Checkpoint, WeaponType};
use std::collections::BTreeMap;
use std::path::Path;
use std::sync::Arc;

/// draw_hash's canvas: 1136x640 maps the 448x252 view rect onto the full
/// framebuffer at the original's 2.5357x / 2.5397x.
const W: u32 = 1136;
const H: u32 = 640;
const DT: f32 = 1.0 / 60.0;
/// The rooms draw_hash's equivalence gate walks, rm_level17 (25) included.
const ROOMS: [usize; 8] = [0, 1, 2, 23, 25, 39, 109, 111];
const ROOM_FRAMES: u32 = 40;
const LEVEL17: usize = 25;
/// draw_frame's clear colour.
const BG: (u8, u8, u8) = (15, 18, 30);
/// draw_ir_commands' placeholder fill (for an alpha-1 command).
const PLACEHOLDER: (u8, u8, u8) = (60, 60, 70);

fn boot() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let mut state = GameState::new(&root.join("../../assets/game.droid")).expect("GameState::new");
    let bundle = Arc::new(
        load_bundle_from_file(&root.join("../core/src/generated/full_ir.json")).expect("full_ir"),
    );
    state.enable_ir_gameplay(bundle).expect("enable_ir_gameplay");
    state
}

fn save_for(room: usize) -> SaveData {
    SaveData {
        format_version: 2,
        current_room: room,
        checkpoint: Checkpoint { room_index: room, x: 0.0, y: 0.0 },
        max_health: 10,
        gems: 0,
        coins: 0,
        current_weapon: WeaponType::Pistol,
        unlocked_weapons: vec![WeaponType::Pistol],
        collected_instance_ids: Vec::new(),
        scene_globals: BTreeMap::new(),
        score: 0.0,
    }
}

fn add(total: &mut ViewCullStats, frame: ViewCullStats) {
    total.sprite_commands += frame.sprite_commands;
    total.sprite_tested += frame.sprite_tested;
    total.sprite_culled += frame.sprite_culled;
    total.sprite_placeholder_kept += frame.sprite_placeholder_kept;
}

/// One real frame rasterised twice: guard on into `on`, guard off into `off`.
/// Returns the guard's counters for that frame.
///
/// Both passes see the same `GameState` and the raster is a pure function of it,
/// so the buffers must come out byte-identical — that equality is the whole
/// equivalence argument, and it holds on every frame this test walks, not on a
/// sample. The guard-off pass must also contribute nothing to the counters: that
/// is the same switch the A/B wall-clock measurement uses.
fn draw_both(state: &GameState, on: &mut Framebuffer, off: &mut Framebuffer) -> ViewCullStats {
    reset_view_cull_stats();
    set_view_cull_enabled(true);
    draw_frame(on, state, &state.asset.tpag_items, &state.asset.sprites);
    let stats = view_cull_stats();

    set_view_cull_enabled(false);
    draw_frame(off, state, &state.asset.tpag_items, &state.asset.sprites);
    assert_eq!(
        view_cull_stats(),
        stats,
        "the guard-off pass must not report any cull decision",
    );

    set_view_cull_enabled(true);
    assert_eq!(
        on.pixels, off.pixels,
        "culling changed the framebuffer ({} commands, {} culled)",
        stats.sprite_commands, stats.sprite_culled,
    );
    stats
}

/// The prologue the app boots into, the tap that retires it, and every room the
/// equivalence gate walks — culling has to be invisible on all of them, and the
/// counters have to show it firing on the one the contract measured.
#[test]
fn culling_is_pixel_equivalent_and_fires_on_the_gate_frames() {
    let mut state = boot();
    let mut on = Framebuffer::new(W, H);
    let mut off = Framebuffer::new(W, H);
    let mut prologue = ViewCullStats::default();
    for _ in 0..40 {
        state.step(DT);
        add(&mut prologue, draw_both(&state, &mut on, &mut off));
    }
    state.input.tap = true;
    state.step(DT);
    state.input.tap = false;
    for _ in 0..40 {
        state.step(DT);
        add(&mut prologue, draw_both(&state, &mut on, &mut off));
    }
    let mut whole_run = prologue;

    let mut level17 = ViewCullStats::default();
    for room in ROOMS {
        let name = state.asset.rooms[room].name.clone();
        state
            .restore_ir_snapshot(&save_for(room))
            .unwrap_or_else(|e| panic!("restore room{room} {name}: {e}"));
        let mut room_stats = ViewCullStats::default();
        for _ in 0..ROOM_FRAMES {
            state.step(DT);
            add(&mut room_stats, draw_both(&state, &mut on, &mut off));
        }
        if room == LEVEL17 {
            level17 = room_stats;
        }
        add(&mut whole_run, room_stats);
        println!(
            "room{room:03} {name:<12} commands/frame {:>6.1}  tested/frame {:>6.1}  \
             culled/frame {:>6.1}  on screen/frame {:>5.1}  kept-for-placeholder/frame {:>5.1}  \
             hit rate {:.3}",
            room_stats.sprite_commands as f64 / ROOM_FRAMES as f64,
            room_stats.sprite_tested as f64 / ROOM_FRAMES as f64,
            room_stats.sprite_culled as f64 / ROOM_FRAMES as f64,
            room_stats.sprite_kept() as f64 / ROOM_FRAMES as f64,
            room_stats.sprite_placeholder_kept as f64 / ROOM_FRAMES as f64,
            room_stats.sprite_hit_rate().unwrap_or(f64::NAN),
        );
    }

    // rm_level17 is the room the contract measured: 806 static quads per frame,
    // ~71 of them inside the 448x252 view rect. The bounds are wide enough for
    // camera drift across the 40 frames and tight enough that a guard which
    // stops matching — or starts matching everything — fails here.
    let per_frame = |v: u64| v as f64 / ROOM_FRAMES as f64;
    let hit = level17
        .sprite_hit_rate()
        .expect("rm_level17 must test sprite commands");
    println!(
        "rm_level17 per frame: commands {:.1}  tested {:.1}  culled {:.1}  on screen {:.1}  \
         kept-for-placeholder {:.1}  hit {:.3}",
        per_frame(level17.sprite_commands),
        per_frame(level17.sprite_tested),
        per_frame(level17.sprite_culled),
        per_frame(level17.sprite_kept()),
        per_frame(level17.sprite_placeholder_kept),
        hit,
    );
    assert!(
        per_frame(level17.sprite_commands) >= 800.0,
        "rm_level17 should emit the contract's ~806 static quads per frame, got {}",
        per_frame(level17.sprite_commands),
    );
    assert!(
        hit >= 0.90,
        "rm_level17 is ~90% off-screen (§3: 806 commands, 71 in the 448x252 view rect); \
         the guard must reject that share, got {hit:.3}",
    );
    assert!(
        prologue.sprite_tested > 0,
        "the prologue's own sprite commands must be walked too (the guard is not \
         gameplay-only)",
    );
    assert!(
        per_frame(level17.sprite_kept()) > 0.0,
        "a guard that rejects everything would pass the ratio but lose the on-screen commands",
    );
    assert!(
        per_frame(level17.sprite_kept()) <= 120.0,
        "on-screen commands per frame should stay near the census' 71, got {}",
        per_frame(level17.sprite_kept()),
    );
    assert!(
        whole_run.sprite_culled > 0,
        "the guard never fired across the whole gate ({} commands walked)",
        whole_run.sprite_commands,
    );
    assert!(
        whole_run.sprite_commands > level17.sprite_commands,
        "the prologue and the other rooms must have been walked too",
    );
}

/// The one way this guard can lose pixels: a command whose sprite, frame page or
/// atlas does not resolve is replaced by a 32x32 placeholder at the *command*
/// position, which is a different box from the sprite anchor's. A command that
/// is off-screen as a sprite can still be on-screen as a placeholder, so the
/// guard has to keep it. Every case here drives the real asset.
#[test]
fn a_visible_placeholder_is_kept_and_an_unobservable_command_is_rejected() {
    let mut state = boot();
    state.retire_prologue();
    state.scene.as_mut().unwrap().view_visible = [false; 8];
    let (sprite_id, cw, ch, ox, oy) = pick_sprite(&state);
    let page_ptr = state.asset.sprites[&(sprite_id as usize)].tpag_indices[0] as usize;
    let (cam_x, cam_y) = GameState::camera_position_for_scene(state.scene.as_ref().unwrap());
    // Frame-0-left lands at screen x `frame_left`; the canvas keeps its SPRT
    // origin, so the box is [frame_left - ox, frame_left - ox + cw].
    let at = |frame_left: f64, frame_top: f64| {
        (cam_x + frame_left - ox, cam_y + frame_top - oy)
    };
    // a tiny command scale shrinks the box to a pixel or two around the anchor.
    let tiny = command(sprite_id, cam_x - 10.0, cam_y + 100.0, (0.001, 0.001));
    // far enough left that even the placeholder is off-screen.
    let far = command(sprite_id, cam_x - 200.0, cam_y + 100.0, (1.0, 1.0));

    // (a) Resolvable page, off-screen sprite box, on-screen placeholder
    //     position: the sprite itself writes nothing, and the guard still keeps
    //     the command because the placeholder could land on the screen.
    only(&mut state, tiny.clone());
    let stats = render_pair(&state);
    assert_eq!(
        (stats.sprite_tested, stats.sprite_culled),
        (1, 0),
        "the placeholder position is on screen - the command must be kept",
    );
    assert_eq!(
        stats.sprite_placeholder_kept, 1,
        "kept for the placeholder, not for a visible sprite box",
    );
    assert!(
        all_background(&render(&state)),
        "premise: this sprite box misses the framebuffer entirely ({cw}x{ch} at scale 0.001)",
    );

    // (b) The same command with its frame page removed really takes the
    //     placeholder path. The guard must still keep it, and the placeholder
    //     must still be drawn - identically with the guard on and off.
    let removed = state.asset.tpag_items.remove(&page_ptr);
    assert!(removed.is_some(), "frame 0 page must be removable");
    only(&mut state, tiny.clone());
    let stats = render_pair(&state);
    assert_eq!(
        (stats.sprite_tested, stats.sprite_culled),
        (1, 0),
        "an unresolved command whose placeholder is visible must be kept",
    );
    assert!(
        has_colour(&render(&state), 0, 100, 22, 132, PLACEHOLDER),
        "the fallback placeholder is on screen and must be drawn",
    );

    // (c) Only the removal that makes the command unobservable (placeholder
    //     off-screen too) may be rejected - and rejecting it changes nothing,
    //     because the placeholder writes no pixel either.
    only(&mut state, far.clone());
    let stats = render_pair(&state);
    assert_eq!(
        (stats.sprite_tested, stats.sprite_culled, stats.sprite_placeholder_kept),
        (1, 1, 0),
        "a command whose only possible ink is off screen must be rejected, and not \
         counted as a placeholder keep",
    );
    assert!(all_background(&render(&state)), "rejecting it must leave the frame empty");

    // (d) On-screen sprite command: kept, and the sprite actually lands.
    state.asset.tpag_items.insert(page_ptr, removed.unwrap());
    let (x, y) = at(10.0, 200.0);
    only(&mut state, command(sprite_id, x, y, (1.0, 1.0)));
    let stats = render_pair(&state);
    assert_eq!(
        (stats.sprite_tested, stats.sprite_culled),
        (1, 0),
        "an on-screen sprite command must be kept",
    );
    assert!(
        !all_background(&render(&state)),
        "an on-screen sprite command must still draw its sprite",
    );

    // (d2) Straddling the left edge (half the canvas off-screen): still kept -
    //      the visible half is real ink, and the box is not empty.
    let (x, y) = at(-(cw as f64) / 2.0, 200.0);
    only(&mut state, command(sprite_id, x, y, (1.0, 1.0)));
    let stats = render_pair(&state);
    assert_eq!(
        (stats.sprite_tested, stats.sprite_culled),
        (1, 0),
        "a clipped-but-visible command must be kept",
    );

    // (e) The same far-off-screen command with its page back in place is
    //     rejected on the sprite box alone, with no placeholder involved.
    only(&mut state, far);
    let stats = render_pair(&state);
    assert_eq!(
        (stats.sprite_tested, stats.sprite_culled),
        (1, 1),
        "an off-screen command with a resolvable page must be rejected",
    );
    assert!(all_background(&render(&state)));
}

// ---------------------------------------------------------------- fixtures --

fn command(sprite: i32, x: f64, y: f64, scale: (f64, f64)) -> DrawCommand {
    DrawCommand {
        code: 0, offset: 0, instance: -1, view: 0,
        sprite, frame: 0.0, x, y,
        scale_x: scale.0, scale_y: scale.1,
        rotation: 0.0, color: 16777215, alpha: 1.0, fog: false,
    }
}

/// Replace every queue with this one command, so any non-background pixel in the
/// frame belongs to it.
fn only(state: &mut GameState, cmd: DrawCommand) {
    let s = state.scene.as_mut().unwrap();
    s.draws.clear();
    s.backgrounds.clear();
    s.room_tiles.clear();
    s.texts.clear();
    s.healthbars.clear();
    s.particles.clear();
    s.draws.push(cmd);
}

fn render(state: &GameState) -> Framebuffer {
    let mut fb = Framebuffer::new(960, 540);
    draw_frame(&mut fb, state, &state.asset.tpag_items, &state.asset.sprites);
    fb
}

/// Guard on vs guard off for one synthetic frame; asserts the pixels match.
fn render_pair(state: &GameState) -> ViewCullStats {
    reset_view_cull_stats();
    let mut on = Framebuffer::new(960, 540);
    let mut off = Framebuffer::new(960, 540);
    set_view_cull_enabled(true);
    draw_frame(&mut on, state, &state.asset.tpag_items, &state.asset.sprites);
    let stats = view_cull_stats();
    set_view_cull_enabled(false);
    draw_frame(&mut off, state, &state.asset.tpag_items, &state.asset.sprites);
    set_view_cull_enabled(true);
    assert_eq!(on.pixels, off.pixels, "culling changed the synthetic frame");
    stats
}

/// A real sprite small enough to place by hand (frame 0 page resolves, holds a
/// visible pixel, and its SPRT origin lies inside its own canvas), so the
/// synthetic geometry below is predictable from `(width, height, origin)`.
fn pick_sprite(state: &GameState) -> (i32, u32, u32, f64, f64) {
    let mut ids: Vec<i32> = state.asset.sprites.keys().map(|k| *k as i32).collect();
    ids.sort();
    for id in ids {
        let sprite = state.asset.sprites.get(&(id as usize)).unwrap();
        if sprite.tpag_indices.is_empty() || sprite.width < 8 || sprite.height < 8 {
            continue;
        }
        if sprite.width > 128 || sprite.height > 128 {
            continue;
        }
        let ox = sprite.origin_x as f64;
        let oy = sprite.origin_y as f64;
        if ox < 0.0 || oy < 0.0 || ox > sprite.width as f64 || oy > sprite.height as f64 {
            continue;
        }
        let Some(page) = state.asset.tpag_items.get(&(sprite.tpag_indices[0] as usize)) else {
            continue;
        };
        let Some(atlas) = state.atlases.get(page.tex_id as usize) else { continue };
        let opaque = (0..page.h as u32).any(|y| {
            (0..page.w as u32)
                .any(|x| atlas.get_pixel(page.x as u32 + x, page.y as u32 + y).0[3] >= 16)
        });
        if opaque {
            return (id, sprite.width, sprite.height, ox, oy);
        }
    }
    panic!("no sprite in the asset satisfies the fixture requirements");
}

fn px(fb: &Framebuffer, x: i32, y: i32) -> (u8, u8, u8) {
    let i = ((y as u32 * fb.width + x as u32) * 4) as usize;
    (fb.pixels[i + 2], fb.pixels[i + 1], fb.pixels[i])
}

fn all_background(fb: &Framebuffer) -> bool {
    (0..fb.height as i32).all(|y| (0..fb.width as i32).all(|x| px(fb, x, y) == BG))
}

fn has_colour(fb: &Framebuffer, x0: i32, y0: i32, x1: i32, y1: i32, want: (u8, u8, u8)) -> bool {
    (y0..y1).any(|y| (x0..x1).any(|x| px(fb, x, y) == want))
}
