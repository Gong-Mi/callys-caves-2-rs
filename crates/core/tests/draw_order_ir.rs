//! Order oracle: shipped ARMv7 DoSlowDrawRoom@0x1b06a0 compares the next
//! tile's depth with instance+0x180, dispatching Draw/default sprite in the
//! SAME descending-depth walk (0x1b0754..0x1b0768, 0x1b0954..0x1b0a40).
//! Synthetic OBJT depths isolate this rule; all events remain original BYTECODE.
use callys_core::{code_vm::load_bundle_from_file, ir_scene::Scene};
use std::path::Path;

#[test]
fn default_sprite_and_explicit_draw_share_descending_depth() {
    for (default_depth, explicit_depth) in [(-100, 100), (-300, -200), (300, 200)] {
        let mut b = load_bundle_from_file(&Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("src/generated/full_ir.json")).unwrap();
        b.objects.iter_mut().find(|o| o.id == 154).unwrap().depth = default_depth;
        b.objects.iter_mut().find(|o| o.id == 138).unwrap().depth = explicit_depth;
        let mut s = Scene::default();
        s.init_bundle(&b);
        s.init_fresh_start_globals();
        s.view_positions.insert(0, (0.0, 0.0));
        let npc = s.create(&b, 154, 50.0, 50.0).unwrap();
        let sheet = s.create(&b, 138, 0.0, 0.0).unwrap();
        s.instances.get_mut(&npc).unwrap().active = true;
        s.draw_view(&b, 0).unwrap();
        assert!(s.draws.iter().any(|c| c.instance == npc), "default sprite fixture");
        assert!(s.draws.iter().any(|c| c.instance == sheet), "real CODE 564 fixture");
        let order: Vec<i32> = s.draws.iter().map(|c| c.instance).collect();
        eprintln!("depths default={default_depth} explicit={explicit_depth} order={order:?}");
        if default_depth < explicit_depth {
            assert_eq!(order.last(), Some(&npc), "default foreground must emit AFTER explicit background");
            assert!(order[..order.len() - 1].iter().all(|id| *id == sheet));
        } else {
            assert_eq!(order[0], npc);
            assert!(order[1..].iter().all(|id| *id == sheet));
        }
    }
}

use callys_core::{code_vm::{Bundle, Host, Op}, ir_scene::{DrawPhase, DrawQueue}};

fn bundle() -> Bundle {
    load_bundle_from_file(&Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("src/generated/full_ir.json")).unwrap()
}
fn fresh(b: &Bundle) -> Scene {
    let mut s = Scene::default(); s.init_bundle(b); s.init_fresh_start_globals();
    s.view_positions.insert(0, (0.0, 0.0)); s
}
fn queues(s: &Scene) -> Vec<DrawQueue> {
    s.ordered_draw_commands().iter().map(|e| e.queue).collect()
}
fn emit_sprite(s: &mut Scene, b: &Bundle, id: i32) {
    s.call(b, id, "draw_sprite", &[123.0, 0.0, 0.0, 0.0]).unwrap();
}

#[test]
fn engine_default_sprite_does_not_claim_the_previous_objects_bytecode_site() {
    let mut b = bundle();
    b.objects.iter_mut().find(|o| o.id == 154).unwrap().depth = -100;
    b.objects.iter_mut().find(|o| o.id == 138).unwrap().depth = 100;
    let mut s = fresh(&b);
    let npc = s.create(&b, 154, 50.0, 50.0).unwrap();
    let sheet = s.create(&b, 138, 0.0, 0.0).unwrap();
    s.instances.get_mut(&npc).unwrap().active = true;
    s.draw_view(&b, 0).unwrap();
    assert!(s.draws.iter().filter(|d| d.instance == sheet).all(|d| d.code == 564));
    let default = s.draws.iter().find(|d| d.instance == npc).unwrap();
    assert_eq!((default.code, default.offset), (usize::MAX, 0),
        "the engine default draw has no bytecode site; it must not inherit CODE564");
}

#[test]
fn same_depth_new_instances_precede_old_instances_regardless_of_placement_id() {
    for (first_id, second_id) in [(100001, 100002), (800000, 100000)] {
        let mut b = bundle();
        b.objects.iter_mut().find(|o| o.id == 138).unwrap().depth = 0;
        b.objects.iter_mut().find(|o| o.id == 154).unwrap().depth = 0;
        let mut s = fresh(&b);
        let first = s.create_with_id(&b, first_id, 138, 0.0, 0.0).unwrap();
        let last = s.create_with_id(&b, second_id, 154, 50.0, 50.0).unwrap();
        s.draw_view(&b, 0).unwrap();
        assert_eq!(s.draws.first().unwrap().instance, last,
            "CRoom::AddInstance inserts equal-depth newcomer before older entries, not by ID");
        assert!(s.draws.iter().skip(1).all(|d| d.instance == first));
    }
}

#[test]
fn signed_zero_depth_enters_the_numeric_equal_depth_tile_rule() {
    let b = bundle(); let mut s = fresh(&b);
    let id = s.create(&b, 154, 50.0, 50.0).unwrap();
    s.instances.get_mut(&id).unwrap().fields.insert("depth".into(), -0.0);
    s.room_tiles.push(tile(0, 42));
    s.draw_view(&b, 0).unwrap();
    let stream=s.ordered_draw_commands();
    assert_eq!(stream[0].queue, DrawQueue::Sprite(0), "numeric -0 equals tile depth +0; instance goes first");
    assert_eq!(stream[1].queue, DrawQueue::RoomTile(0));
}

#[test]
fn every_host_draw_builtin_records_one_cross_type_emission() {
    let b = bundle(); let mut s = fresh(&b);
    let id = s.create(&b, 154, 0.0, 0.0).unwrap();
    s.clear_draw_commands();
    let text = s.alloc_string(&b, "ordered".into());
    s.call(&b, id, "draw_text", &[1.0, 2.0, text]).unwrap();
    emit_sprite(&mut s, &b, id);
    s.call(&b, id, "draw_healthbar", &[0.0,0.0,10.0,10.0,50.0,0.0,65280.0,65280.0,0.0,1.0,1.0]).unwrap();
    s.call(&b, id, "draw_background", &[5.0,0.0,0.0]).unwrap();
    s.call(&b, id, "draw_text_color", &[1.0,2.0,text,16777215.0,16777215.0,16777215.0,16777215.0,1.0]).unwrap();
    s.call(&b, id, "draw_sprite_ext", &[123.0,0.0,0.0,0.0,1.0,1.0,0.0,16777215.0,1.0]).unwrap();
    s.call(&b, id, "draw_background_ext", &[5.0,0.0,0.0,1.0,1.0,0.0,16777215.0,1.0]).unwrap();
    s.call(&b, id, "draw_self", &[]).unwrap();
    assert_eq!(queues(&s), vec![DrawQueue::Text(0),DrawQueue::Sprite(0),DrawQueue::Healthbar(0),DrawQueue::Background(0),
        DrawQueue::Text(1),DrawQueue::Sprite(1),DrawQueue::Background(1),DrawQueue::Sprite(2)]);
    let stream = s.ordered_draw_commands();
    assert_eq!(stream.iter().map(|e| e.emit_order).collect::<Vec<_>>(), (0..8).collect::<Vec<_>>());
    assert!(stream.iter().all(|e| e.view == 0 && e.phase == DrawPhase::Room));
}

#[test]
fn real_code370_cross_type_stream_matches_original_vm_call_order() {
    let b = bundle(); let mut s = fresh(&b);
    let asset = callys_asset::GameDroidAsset::parse(Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../../assets/game.droid")).unwrap();
    s.load_room_from_data(&b, 97, &asset.rooms[97]).unwrap();
    s.view_positions.insert(0, (0.0,0.0)); s.executed.clear();
    s.draw_view(&b, 0).unwrap();
    let code = b.codes.iter().find(|c| c.id == 370).unwrap();
    let call_offsets: std::collections::BTreeSet<_> = code.instructions.iter().filter_map(|i| {
        match &i.op {
            Op::Call { name, .. } if matches!(name.as_str(), "draw_sprite"|"draw_sprite_ext"|"draw_text"|"draw_healthbar") => Some(i.offset),
            _ => None,
        }
    }).collect();
    let expected: Vec<_> = s.executed.iter().filter(|(c, o)| *c == 370 && call_offsets.contains(o)).map(|(_, o)| *o).collect();
    let mut kinds = std::collections::BTreeSet::new();
    let actual: Vec<_> = s.ordered_draw_commands().iter().filter_map(|e| {
        let (code, offset, kind) = match e.queue {
            DrawQueue::Sprite(i) => (s.draws[i].code, s.draws[i].offset, 0),
            DrawQueue::Text(i) => (s.texts[i].code, s.texts[i].offset, 1),
            DrawQueue::Healthbar(i) => (s.healthbars[i].code, s.healthbars[i].offset, 2),
            _ => return None,
        };
        if code == 370 { kinds.insert(kind); Some(offset) } else { None }
    }).collect();
    assert_eq!(kinds.len(), 3, "real HUD must exercise sprites, texts AND bars");
    assert_eq!(actual, expected, "the original BYTECODE's actual cross-type calls must retain their order");
}

fn tile(depth: i32, id: i32) -> callys_asset::RoomTileInstance {
    callys_asset::RoomTileInstance { x:0,y:0,bg_id:5,src_x:0,src_y:0,width:16,height:16,
        depth,id,scale_x:1.0,scale_y:1.0 }
}

#[test]
fn interleaved_tile_instance_walk_keeps_runtime_negative_and_fractional_depth() {
    let b = bundle(); let mut s = fresh(&b);
    for depth in [-350.25,110.5,-150.75] {
        let id = s.create(&b,154,0.0,0.0).unwrap();
        let i = s.instances.get_mut(&id).unwrap(); i.active = true;
        i.fields.insert("depth".into(),depth);
    }
    s.room_tiles = vec![tile(-300,1),tile(300,2),tile(-400,3),tile(100,4),tile(-100,5)];
    s.draw_view(&b,0).unwrap();
    let stream = s.ordered_draw_commands();
    assert_eq!(stream.iter().map(|e| e.depth).collect::<Vec<_>>(),
        vec![300.0,110.5,100.0,-100.0,-150.75,-300.0,-350.25,-400.0]);
    assert_eq!(stream.iter().map(|e| matches!(e.queue,DrawQueue::RoomTile(_))).collect::<Vec<_>>(),
        vec![true,false,true,true,false,true,false,true]);
}

#[test]
fn clear_next_frame_view_and_room_load_reset_all_emit_metadata() {
    let b = bundle(); let mut s = fresh(&b);
    let id = s.create(&b,154,0.0,0.0).unwrap(); s.instances.get_mut(&id).unwrap().active = true;
    let text = s.alloc_string(&b,"retired".into());
    s.call(&b,id,"draw_text",&[0.0,0.0,text]).unwrap();
    s.draw_view(&b,0).unwrap();
    assert_eq!(queues(&s),vec![DrawQueue::Sprite(0)]);
    assert_eq!(s.ordered_draw_commands()[0].emit_order,0);
    s.view_positions.insert(1,(0.0,0.0)); s.draw_view(&b,1).unwrap();
    assert_eq!(queues(&s),vec![DrawQueue::Sprite(0)]);
    assert_eq!(s.draws[0].view,1);
    assert_eq!(s.ordered_draw_commands()[0].view,1);
    s.clear_draw_commands(); assert!(s.ordered_draw_commands().is_empty());
    emit_sprite(&mut s,&b,id);
    let room = callys_asset::RoomData { name:"empty".into(),caption:"".into(),width:100,height:100,
        speed:30,persistent:false,
        background_colour:0,draw_background_colour:false,creation_code_id:-1,flags:0,backgrounds:vec![],
        objects:vec![],tiles:vec![],views:vec![] };
    s.load_room_from_data(&b,999,&room).unwrap();
    assert!(s.draws.is_empty() && s.texts.is_empty() && s.healthbars.is_empty() && s.backgrounds.is_empty());
    assert!(s.ordered_draw_commands().is_empty());
    emit_sprite(&mut s,&b,id);
    assert_eq!(s.ordered_draw_commands()[0].emit_order,0);
}

#[test]
fn public_vec_replacement_append_and_index_reuse_never_drop_or_duplicate_commands() {
    let b = bundle(); let mut s = fresh(&b);
    let text = s.alloc_string(&b,"A".into());
    s.call(&b,42,"draw_text",&[0.0,0.0,text]).unwrap();
    emit_sprite(&mut s,&b,42);
    let replacement = s.draws[0].clone();
    s.draws.clear(); s.draws.push(replacement.clone());
    // Re-emitting an identical payload at a reused index still owns a fresh
    // timestamp; stale equality alone must NOT resurrect the earlier emission.
    s.draws.clear(); emit_sprite(&mut s,&b,42);
    assert_eq!(queues(&s),vec![DrawQueue::Text(0),DrawQueue::Sprite(0)]);
    assert_eq!(s.ordered_draw_commands()[1].emit_order,2);
    s.draws.push(replacement.clone()); // legitimate queue-only append
    assert_eq!(queues(&s),vec![DrawQueue::Text(0),DrawQueue::Sprite(0),DrawQueue::Sprite(1)]);
    s.texts.clear();
    assert_eq!(queues(&s),vec![DrawQueue::Sprite(0),DrawQueue::Sprite(1)]);
    s.draws[0].x = 123.0; // direct editing invalidates provenance, not payload
    assert_eq!(queues(&s),vec![DrawQueue::Sprite(0),DrawQueue::Sprite(1)]);
    s.clear_draw_commands(); s.draws.push(replacement);
    assert_eq!(queues(&s),vec![DrawQueue::Sprite(0)],"legacy queue-only fixture remains renderable");
}

#[test]
fn gui_commands_remain_after_all_room_depths_and_reset_phase_afterward() {
    let mut b = bundle();
    // Synthetic GUI binding, NOT synthetic BYTECODE: use original background
    // CODE 364 on GUI-only obj_viewresolution to make the phase observable.
    b.objects.iter_mut().find(|o|o.id==133).unwrap().events.iter_mut()
        .find(|e|e.event_type==8 && e.subtype==65).unwrap().codes=vec![364];
    let mut s = fresh(&b);
    s.create(&b,133,0.0,0.0).unwrap();
    let npc = s.create(&b,154,0.0,0.0).unwrap(); s.instances.get_mut(&npc).unwrap().active=true;
    s.instances.get_mut(&npc).unwrap().fields.insert("depth".into(),-1000.0);
    s.room_tiles.push(tile(-2000,1)); s.draw_view(&b,0).unwrap();
    let stream = s.ordered_draw_commands();
    assert!(stream.iter().any(|e|e.phase==DrawPhase::Gui));
    assert_eq!(stream.last().unwrap().phase,DrawPhase::Gui);
    let first_gui = stream.iter().position(|e|e.phase==DrawPhase::Gui).unwrap();
    assert!(stream[first_gui..].iter().all(|e|e.phase==DrawPhase::Gui));
    emit_sprite(&mut s,&b,npc);
    assert_eq!(s.ordered_draw_commands().iter().find(|e|e.queue==DrawQueue::Sprite(1)).unwrap().phase,DrawPhase::Room);
}

#[test]
fn invalid_default_sprite_is_an_error_not_a_silently_ignored_emission() {
    let b = bundle(); let mut s = fresh(&b);
    let id=s.create(&b,154,0.0,0.0).unwrap();
    let i=s.instances.get_mut(&id).unwrap(); i.active=true;
    i.fields.insert("sprite_index".into(),f64::NAN);
    assert!(s.draw_view(&b,0).is_err());
    assert!(s.draws.is_empty() && s.ordered_draw_commands().is_empty());
    s.instances.get_mut(&id).unwrap().fields.insert("sprite_index".into(),123.0);
    s.draw_view(&b,0).unwrap(); assert_eq!(s.ordered_draw_commands()[0].emit_order,0);
}

