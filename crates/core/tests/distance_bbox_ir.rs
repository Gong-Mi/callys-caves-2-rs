//! Original libyoyo ARMv7 (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
//! FindDist @10ac9c reads inclusive integer bbox edges, returns sqrtf(dx²+dy²),
//! excludes self/destroyed/deactivated targets with 1_000_000 (NOT 100_000).
//! F_DistanceToObject @10ad88 uses WithObjIterator @19d060; CObjectGM::AddInstance
//! @19e02c adds children to ancestor lists. Caller flags are not filtered by
//! FindDist: F passes the candidate as its first argument, caller as its second.
//! Micro geometry, independent raw SPRT fixtures, and real CODE675 walk are
//! separate layers. No screenshot/GPU/original-device execution is claimed.
use callys_asset::{CollisionMask, GameDroidAsset};
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

fn empty_bundle() -> Bundle {
    Bundle { schema: 1, string_table: vec![], objects: vec![], room_bindings: vec![], codes: vec![] }
}
fn instance(s: &mut Scene, object: i32, x: f64, y: f64, sprite: i32) -> i32 {
    let id = s.insert_external(object);
    for (key,value) in [("x",x),("y",y),("sprite_index",sprite as f64),
        ("mask_index",-1.0),("image_xscale",1.0),("image_yscale",1.0),("image_angle",0.0)] {
        s.write(id,-1,key,None,value).unwrap();
    }
    id
}
fn distance(s: &mut Scene, caller: i32, selector: i32) -> f64 {
    s.call(&empty_bundle(),caller,"distance_to_object",&[selector as f64]).unwrap()
}
fn rect(s: &mut Scene, sid: i32, w: f64, h: f64, ox: f64, oy: f64) {
    s.sprite_bounds.insert(sid,SpriteBounds::with_frames(w,h,ox,oy,1.0));
}

#[test]
fn edge_distance_overlap_horizontal_vertical_and_diagonal() {
    // Inclusive 10x10 rectangles: [0,9] not [0,10]. The 3/4/5 triangle is
    // independent numeric ground truth, also executed through ARM FindDist.
    let mut s=Scene::default(); rect(&mut s,1000,10.0,10.0,0.0,0.0);
    let a=instance(&mut s,10,0.0,0.0,1000);
    let b=instance(&mut s,11,0.0,0.0,1000);
    for (x,y,want) in [(5.0,5.0,0.0),(12.0,0.0,3.0),(0.0,13.0,4.0),(12.0,13.0,5.0),
                          (-12.0,0.0,3.0),(0.0,-13.0,4.0),(-12.0,-13.0,5.0)] {
        s.write(b,-1,"x",None,x).unwrap(); s.write(b,-1,"y",None,y).unwrap();
        assert_eq!(distance(&mut s,a,b),want,"gap at ({x},{y})");
        assert_eq!(distance(&mut s,b,a),want,"symmetry at ({x},{y})");
    }
}

#[test]
fn masks_override_sprite_extents_and_mirrors_normalize_edges() {
    let mut s=Scene::default(); rect(&mut s,1000,200.0,200.0,0.0,0.0);
    rect(&mut s,1001,16.0,16.0,5.0,6.0);
    // Mask bbox [2,7]x[3,8], unlike the enormous visible sprite. Independent
    // Compute_BoundingBox @192340 ARM probe: (-2,+3) -> [14,25]x[21,38].
    let mut m=CollisionMask { width:16,height:16,bits:vec![0;32] };
    for y in 3..=8 { m.bits[y*2]=0x3f; }
    s.sprite_masks.insert(1001,vec![m]);
    let a=instance(&mut s,10,20.0,30.0,1000);
    s.write(a,-1,"mask_index",None,1001.0).unwrap();
    let b=instance(&mut s,11,28.0,42.0,-1);
    s.write(a,-1,"image_xscale",None,-2.0).unwrap();
    s.write(a,-1,"image_yscale",None,3.0).unwrap();
    assert_eq!(distance(&mut s,a,b),5.0,"mask edge gaps are 3 and 4");
    s.write(a,-1,"image_xscale",None,2.0).unwrap();
    s.write(a,-1,"image_yscale",None,-3.0).unwrap();
    assert_eq!(distance(&mut s,a,b),5.0,"both signed scale directions normalize");
    s.write(a,-1,"image_yscale",None,3.0).unwrap();
    s.write(a,-1,"image_angle",None,90.0).unwrap();
    s.write(b,-1,"x",None,31.0).unwrap();s.write(b,-1,"y",None,39.0).unwrap();
    assert_eq!(distance(&mut s,a,b),5.0,"ARM rotated bbox [11,28]x[24,35] still has 3/4 gaps");
    s.write(a,-1,"image_angle",None,0.0).unwrap();
    s.write(a,-1,"image_yscale",None,-3.0).unwrap();
    s.write(b,-1,"x",None,28.0).unwrap();s.write(b,-1,"y",None,42.0).unwrap();
    s.write(a,-1,"mask_index",None,-1.0).unwrap();
    assert_eq!(distance(&mut s,a,b),13.0,"negative mask_index restores visible sprite's mirrored vertical extent");
    s.write(a,-1,"image_yscale",None,1.0).unwrap();
    assert_eq!(distance(&mut s,a,b),0.0,"unmirrored visible sprite overlaps the point");
}

#[test]
fn runner_selectors_self_active_and_one_million_sentinel() {
    let mut s=Scene::default();
    let a=instance(&mut s,10,0.0,0.0,-1);
    let child=instance(&mut s,11,3.0,4.0,-1);
    let far=instance(&mut s,11,30.0,40.0,-1);
    s.object_parents.insert(11,vec![12]);
    assert_eq!(distance(&mut s,a,12),5.0,"parent selector includes child and minimizes");
    assert_eq!(distance(&mut s,a,-3),5.0,"all includes every active live target, excluding self");
    assert_eq!(distance(&mut s,a,-4),1_000_000.0,"noone");
    assert_eq!(distance(&mut s,a,999),1_000_000.0,"absent object");
    assert_eq!(distance(&mut s,a,-1),1_000_000.0,"self is not zero distance");
    assert_eq!(distance(&mut s,a,a),1_000_000.0,"explicit self instance");
    assert_eq!(distance(&mut s,a,10),1_000_000.0,"same object contains only caller");
    s.other_instance=Some(child);
    assert_eq!(distance(&mut s,a,-2),5.0,"other iterator");
    s.instances.get_mut(&child).unwrap().active=false;
    assert_eq!(distance(&mut s,a,child),1_000_000.0,"explicit inactive target");
    assert_eq!(distance(&mut s,a,-2),1_000_000.0,"other does not bypass candidate flags");
    assert_eq!(distance(&mut s,a,12),50.0,"inactive near child does not win minimum");
    s.instances.get_mut(&child).unwrap().active=true;
    s.instances.get_mut(&far).unwrap().alive=false;
    s.instances.get_mut(&a).unwrap().active=false;
    assert_eq!(distance(&mut s,a,12),5.0,"direct call with inactive caller still measures active target");
    s.instances.get_mut(&child).unwrap().alive=false;
    assert_eq!(distance(&mut s,a,12),1_000_000.0,"all candidates destroyed");
}

#[test]
fn sprite_less_instances_are_integer_points_not_default_32px_boxes() {
    let mut s=Scene::default();
    let a=instance(&mut s,10,-10.9,-20.9,-1);
    let b=instance(&mut s,11,-7.1,-16.1,-1);
    assert_eq!(distance(&mut s,a,b),5.0,"Compute_BoundingBox no sprite truncates x/y to integer");
}

fn asset_path() -> std::path::PathBuf { Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid") }
fn u32_at(b: &[u8], off: usize) -> u32 { u32::from_le_bytes(b[off..off+4].try_into().unwrap()) }
fn raw_sprite_records() -> Vec<(i32,[i32;8])> {
    let b=std::fs::read(asset_path()).unwrap(); assert_eq!(&b[..4],b"FORM");
    let mut pos=8;
    while &b[pos..pos+4]!=b"SPRT" {pos+=8+u32_at(&b,pos+4) as usize;}
    let pos=pos+8;
    (0..u32_at(&b,pos)).map(|sid| {
        let off=u32_at(&b,pos+4+sid as usize*4) as usize;
        // Raw record: width,height,left,right,bottom,top,...,origin_x,origin_y.
        (sid as i32,[u32_at(&b,off+4) as i32,u32_at(&b,off+8) as i32,
            u32_at(&b,off+48) as i32,u32_at(&b,off+52) as i32,
            u32_at(&b,off+12) as i32,u32_at(&b,off+16) as i32,
            u32_at(&b,off+24) as i32,u32_at(&b,off+20) as i32])
    }).collect()
}
fn install_geometry(s: &mut Scene, asset: &GameDroidAsset) {
    for (&sid,sp) in &asset.sprites {
        s.sprite_bounds.insert(sid as i32,SpriteBounds::with_frames(sp.width as f64,sp.height as f64,
            sp.origin_x as f64,sp.origin_y as f64,sp.tpag_indices.len() as f64));
        if let Some(bbox) = sp.bbox { s.sprite_bboxes.insert(sid as i32, bbox); }
        s.sprite_masks.insert(sid as i32,sp.masks.clone());
    }
}

#[test]
fn all_original_sprt_bbox_edges_are_independently_pinned() {
    let asset=GameDroidAsset::parse(&asset_path()).unwrap();
    let raw=raw_sprite_records(); assert_eq!(raw.len(),178);
    assert_eq!(raw[1].1,[32,64,16,32,1,29,21,63],"Lloyd geometry, not full bitmap");
    assert_eq!(raw[29].1,[32,34,15,16,9,22,4,33],"player standing mask");
    assert_eq!(raw[36].1,[32,32,15,16,1,26,1,33],"raw bbox can exceed bitmap height");
    assert!(!asset.sprites[&49].masks[0].pixel(53,32),"explosion raw right edge is NOT occupied-mask extent");
    let mut s=Scene::default(); install_geometry(&mut s,&asset);
    let a=instance(&mut s,1000,1000.0,1000.0,-1);
    let b=instance(&mut s,1001,0.0,0.0,-1);
    for (sid,[w,h,ox,oy,l,r,t,bt]) in raw {
        let sp=&asset.sprites[&(sid as usize)];
        assert_eq!((sp.width as i32,sp.height as i32,sp.origin_x,sp.origin_y),(w,h,ox,oy),"parsed geometry fixture {sid}");
        s.write(a,-1,"sprite_index",None,sid as f64).unwrap();
        let (left,right,top,bottom)=(1000+l-ox,1000+r-ox,1000+t-oy,1000+bt-oy);
        for (x,y) in [(left-10,top),(right+10,top),(left,top-10),(left,bottom+10)] {
            s.write(b,-1,"x",None,x as f64).unwrap();s.write(b,-1,"y",None,y as f64).unwrap();
            assert_eq!(distance(&mut s,a,b),10.0,"SPRT {sid} bbox edge against point ({x},{y})");
        }
    }
}

fn real_scene() -> (Bundle,Scene,i32,i32) {
    let asset=GameDroidAsset::parse(&asset_path()).unwrap();
    let mut b=load_bundle_from_file(&Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json")).unwrap();
    b.string_table=asset.string_table.clone();
    let mut s=Scene::default(); s.init_bundle(&b);s.init_fresh_start_globals();install_geometry(&mut s,&asset);
    s.load_room_from_data(&b,0,&asset.rooms[0]).unwrap();s.view_positions.insert(0,(0.0,0.0));
    let one=|obj|s.instances.iter().find(|(_,i)|i.object==obj && i.alive).map(|(&id,_)|id).unwrap();
    let p=one(0);let l=one(154);(b,s,p,l)
}

#[test]
fn code675_keeps_inclusive_100px_gate_with_real_player_and_lloyd_geometry() {
    let (b,mut s,p,l)=real_scene();
    assert_eq!((s.instances[&l].fields["x"],s.instances[&l].fields["y"]),(768.0,480.0));
    // Independent original boxes at this site: Lloyd [753,781]x[469,511],
    // player masked standing [x-6,x+7]x[y-12,y+17]. Bounds touch the <=100
    // gate at x646, outside it at x645; origin gap remains >100 at both.
    s.write(p,-1,"mask_index",None,29.0).unwrap();
    s.write(p,-1,"x",None,645.0).unwrap();s.write(p,-1,"y",None,494.0).unwrap();
    assert_eq!(distance(&mut s,l,0),101.0);
    s.dispatch(&b,l,3,0).unwrap();assert_eq!(s.instances[&l].fields["startlloyd"],0.0);
    s.write(p,-1,"x",None,646.0).unwrap();
    assert_eq!(distance(&mut s,l,0),100.0);
    assert!((s.instances[&l].fields["x"]-s.instances[&p].fields["x"]).abs()>100.0);
    s.dispatch(&b,l,3,0).unwrap();assert_eq!(s.instances[&l].fields["startlloyd"],1.0);
    assert_eq!(s.globals["roomstart"],1.0);
    assert!(s.instances.values().filter(|i|[130,131].contains(&i.object)).all(|i|!i.alive));
}

#[test]
fn original_town_walk_reaches_code675_before_origins_close_to_100px() {
    let (b,mut s,p,l)=real_scene();
    assert_eq!((s.instances[&p].fields["x"],s.instances[&p].fields["y"]),(416.0,494.0),"original ROOM placement");
    // Real prologue Create/alarms/tap, not retire_prologue or a player teleport.
    let intro=s.create(&b,137,416.0,494.0).unwrap();
    for _ in 0..120 {s.tick(&b).unwrap();s.draw_view(&b,0).unwrap();s.end_frame();}
    assert_eq!(s.instances[&intro].fields["taplock"],1.0);
    s.mouse_pressed=true;s.tick(&b).unwrap();s.draw_view(&b,0).unwrap();s.end_frame();
    assert!(!s.instances[&intro].alive);assert!(s.instances[&p].active);
    let (x,y)=(s.instances[&p].fields["x"],s.instances[&p].fields["y"]);
    assert_eq!(s.call(&b,p,"place_meeting",&[x+1.0,y,34.0]).unwrap(),0.0,"rightward path fixture starts unobstructed");
    assert_eq!(s.call(&b,p,"place_meeting",&[x,y+1.0,34.0]).unwrap(),1.0,"town walking fixture is grounded");
    // Drive the original right-button Draw input seam, exactly where the client
    // publishes its virtual device. No hsp/x/y injection during the walk.
    s.touch_devices[0].x=130.0;s.touch_devices[0].y=200.0;s.touch_devices[0].down=true;s.touch_devices[0].pressed=true;
    let mut previous=x; let mut fired=false;
    for tick in 1..=200 {
        s.draw_view(&b,0).unwrap();s.end_frame();s.tick(&b).unwrap();
        let px=s.instances[&p].fields["x"];
        if s.instances[&l].fields["startlloyd"]==1.0 {
            let origin=(768.0-px).hypot(480.0-s.instances[&p].fields["y"]);
            assert!(origin>100.0,"CODE675 must trigger from near bbox while origin is still outside; x={px} origin={origin}");
            assert!(previous<px,"natural approach advanced before trigger");
            assert!(distance(&mut s,l,0)<=100.0);
            assert_eq!(s.globals["roomstart"],1.0);
            eprintln!("CODE675 natural walk tick={tick} previous_x={previous} trigger_x={px} origin_distance={origin}");
            fired=true;break;
        }
        previous=px;
    }
    assert!(fired,"original right-button input must naturally reach the story gate");
}
