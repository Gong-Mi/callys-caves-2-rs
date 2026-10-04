//! Micro compositing fixtures, not screenshot goldens or an occlusion mock.
//! Real Host emitters -> draw_frame -> the actual atlas-backed CPU rasterizer.
//! Sprite 123's in-memory atlas is made opaque red; original asset files and
//! BYTECODE are never changed. This is a synthetic ordering oracle only.
use callys_asset::RoomTileInstance;
use callys_client::{draw_frame, Framebuffer, GameState};
use callys_core::code_vm::{load_bundle_from_file, Host};
use std::{path::Path, sync::Arc};

fn state() -> GameState {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../..");
    let mut state = GameState::new(&root.join("assets/game.droid")).unwrap();
    state.enable_ir_gameplay(Arc::new(load_bundle_from_file(
        &root.join("crates/core/src/generated/full_ir.json")).unwrap())).unwrap();
    state.retire_prologue();
    // Publish a real gameplay frame/camera before replacing queues. The
    // integration parent keeps draw_frame on this published snapshot, never
    // a compatibility refollow for synthetic fixtures.
    state.step(1.0 / 30.0);
    assert!(state.runtime_diagnostic.is_none(), "real publication frame must not halt: {:?}", state.runtime_diagnostic);
    let sprite = &state.asset.sprites[&123];
    let page = &state.asset.tpag_items[&(sprite.tpag_indices[0] as usize)];
    let atlas = &mut state.atlases[page.tex_id as usize];
    for y in page.y as u32..(page.y + page.h) as u32 {
        for x in page.x as u32..(page.x + page.w) as u32 {
            atlas.get_pixel_mut(x, y).0 = [255, 0, 0, 255];
        }
    }
    let s = state.scene.as_mut().unwrap();
    s.instances.clear();
    s.room_tiles.clear();
    s.particles.clear();
    s.room_views[0].object = -1;
    s.view_positions.insert(0, (0.0, 0.0));
    s.view_visible = [false; 8];
    s.view_visible[0] = true;
    s.draws.clear(); s.texts.clear(); s.healthbars.clear(); s.backgrounds.clear();
    state
}

fn render(state: &GameState) -> Framebuffer {
    let mut fb = Framebuffer::new(1136, 640);
    draw_frame(&mut fb, state, &state.asset.tpag_items, &state.asset.sprites);
    fb
}

fn sprite(s: &mut callys_core::ir_scene::Scene, b: &callys_core::code_vm::Bundle, id: i32) {
    s.call(b, id, "draw_sprite_ext", &[123.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 16777215.0, 1.0]).unwrap();
}

#[test]
fn text_then_opaque_sprite_does_not_leak_later_text_pixels() {
    assert_text_is_covered(false);
    assert_text_is_covered(true);
}

fn assert_text_is_covered(intro: bool) {
    let mut state = state();
    if intro {
        // Select the real prologue consumption branch, without replacing its
        // rasterizer or the Host. No intro timing/event logic is synthesized.
        state.scene.as_mut().unwrap().insert_external(137);
    }
    let b = state.full_bundle.clone().unwrap();
    let s = state.scene.as_mut().unwrap();
    let text = s.alloc_string(&b, "A".into());
    s.call(&b, 12345, "draw_set_color", &[16777215.0]).unwrap();
    s.call(&b, 12345, "draw_set_font", &[0.0]).unwrap();
    s.call(&b, 12345, "draw_text", &[50.0, 50.0, text]).unwrap();
    sprite(s, &b, 12345);
    let fb = render(&state);
    let leaked = fb.pixels.chunks_exact(4).filter(|p| p[..3] != [0, 0, 255]).count();
    eprintln!("intro={intro} text_then_sprite expected_nonred=0 actual_nonred={leaked}");
    assert_eq!(leaked, 0, "later opaque sprite must cover the earlier glyph (old pipeline leaked 506 pixels)");
}

#[test]
fn sprite_then_text_still_displays_the_later_glyph() {
    let mut state = state();
    let b = state.full_bundle.clone().unwrap();
    let s = state.scene.as_mut().unwrap();
    let text = s.alloc_string(&b, "A".into());
    sprite(s, &b, 12345);
    s.call(&b, 12345, "draw_set_color", &[16777215.0]).unwrap();
    s.call(&b, 12345, "draw_text", &[50.0, 50.0, text]).unwrap();
    assert!(render(&state).pixels.chunks_exact(4).any(|p| p[..3] != [0, 0, 255]));
}

fn tile(depth: i32) -> RoomTileInstance {
    RoomTileInstance { x: 0, y: 0, bg_id: 5, src_x: 0, src_y: 0,
        width: 64, height: 64, depth, id: 42, scale_x: 1.0, scale_y: 1.0 }
}

#[test]
fn tiles_and_instances_interleave_by_numeric_depth_not_sign() {
    // Exercise BOTH orderings within both signs; a foreground/background split
    // is not sufficient. The instance is a real default-sprite object (154).
    let mut failures = Vec::new();
    for (tile_depth, instance_depth) in [(300, 200), (100, 200), (-100, -200), (-300, -200), (0, 0)] {
        let mut state = state();
        let page = &state.asset.tpag_items[&state.asset.backgrounds[&5].tpag_ptr];
        for y in page.y as u32..page.y as u32 + 64 {
            for x in page.x as u32..page.x as u32 + 64 {
                state.atlases[page.tex_id as usize].get_pixel_mut(x, y).0 = [0, 255, 0, 255];
            }
        }
        let mut b = state.full_bundle.as_ref().unwrap().as_ref().clone();
        b.objects.iter_mut().find(|o| o.id == 154).unwrap().depth = instance_depth;
        let s = state.scene.as_mut().unwrap();
        let id = s.create(&b, 154, 0.0, 0.0).unwrap();
        let i = s.instances.get_mut(&id).unwrap();
        i.active = true;
        i.fields.insert("sprite_index".into(), 123.0);
        s.room_tiles.push(tile(tile_depth));
        s.draw_view(&b, 0).unwrap();
        let fb = render(&state);
        let p = ((60 * fb.width + 60) * 4) as usize;
        // On equal depth the original's BLE to the instance branch at
        // 0x1b0768 puts the instance BEFORE the tile (so tile wins).
        let expected = if tile_depth > instance_depth { [0, 0, 255] } else { [0, 255, 0] };
        eprintln!("tile={tile_depth} instance={instance_depth} pixel={:?} expected={expected:?}", &fb.pixels[p..p+3]);
        if fb.pixels[p..p+3] != expected {
            failures.push((tile_depth, instance_depth, fb.pixels[p..p+3].to_vec(), expected));
        }
    }
    assert!(failures.is_empty(), "DoSlowDrawRoom descending-depth merge: {failures:?}");
}

#[test]
fn healthbar_and_background_follow_emit_order_not_type_groups() {
    for later_sprite in [true,false] {
        let mut state = state(); let b = state.full_bundle.clone().unwrap();
        let s = state.scene.as_mut().unwrap();
        if !later_sprite { sprite(s,&b,42); }
        s.call(&b,42,"draw_healthbar",&[0.0,0.0,64.0,64.0,100.0,0.0,65280.0,65280.0,0.0,1.0,1.0]).unwrap();
        if later_sprite { sprite(s,&b,42); }
        let fb=render(&state); let p=((60*fb.width+60)*4) as usize;
        let expected=if later_sprite { [0,0,255] } else { [0,255,0] };
        assert_eq!(fb.pixels[p..p+3],expected,"bar/sprite emission order");
    }
    for later_sprite in [true,false] {
        let mut state=state(); let b=state.full_bundle.clone().unwrap();
        let page=&state.asset.tpag_items[&state.asset.backgrounds[&5].tpag_ptr];
        for y in page.y as u32..page.y as u32+64 {
            for x in page.x as u32..page.x as u32+64 {
                state.atlases[page.tex_id as usize].get_pixel_mut(x,y).0=[0,255,0,255];
            }
        }
        let s=state.scene.as_mut().unwrap();
        if !later_sprite { sprite(s,&b,42); }
        s.call(&b,42,"draw_background",&[5.0,0.0,0.0]).unwrap();
        if later_sprite { sprite(s,&b,42); }
        let fb=render(&state); let p=((60*fb.width+60)*4) as usize;
        let expected=if later_sprite { [0,0,255] } else { [0,255,0] };
        assert_eq!(fb.pixels[p..p+3],expected,"background/sprite emission order");
    }
}

#[test]
fn manual_queue_append_and_replacement_still_render_after_tracked_draws() {
    let mut state=state(); let b=state.full_bundle.clone().unwrap();
    let s=state.scene.as_mut().unwrap(); sprite(s,&b,42);
    // Existing public Vec contract: a legitimate appended bar may not vanish
    // merely because an ordered stream exists for the previous Host draw.
    let hb=callys_core::ir_scene::HealthbarCommand { code:0,offset:0,instance:-1,view:0,
        x1:0.0,y1:0.0,x2:64.0,y2:64.0,amount:100.0,back_col:0,min_col:65280,max_col:65280 };
    s.healthbars.push(hb);
    let fb=render(&state); let p=((60*fb.width+60)*4) as usize;
    assert_eq!(fb.pixels[p..p+3],[0,255,0]);
    let s=state.scene.as_mut().unwrap();
    let mut replacement=s.draws[0].clone(); replacement.color=0;
    s.draws.clear(); s.texts.clear(); s.backgrounds.clear(); s.healthbars.clear();
    // Different payload at the same index must never alias stale metadata or
    // disappear. This mirrors existing queue-only consumption fixture setup.
    s.draws.push(replacement);
    let fb=render(&state);
    assert!(fb.pixels.chunks_exact(4).all(|p|p[..3]==[0,0,0]));
}

