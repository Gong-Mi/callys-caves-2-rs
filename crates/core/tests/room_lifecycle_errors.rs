use callys_asset::RoomData;
use callys_core::{code_vm::{Bundle, Code, Event, Object}, ir_scene::Scene};

fn fixture(subtype: i32, has_code: bool) -> (Bundle, Scene, RoomData, i32) {
    let b = Bundle {
        schema: 1, string_table: vec![], room_bindings: vec![],
        objects: vec![Object { id: 0, name: "persistent_player".into(), sprite: -1,
            depth: 0, parent: -100, parent_chain: vec![],
            events: vec![Event { event_type: 7, subtype, codes: vec![42] }] }],
        codes: if has_code { vec![Code { id:42, start:0, end:0, instructions:vec![] }] } else { vec![] },
    };
    let mut s = Scene::default();
    s.current_room = 3.0;
    s.room_width = 320.0;
    let id = s.create(&b,0,10.0,20.0).unwrap();
    let room = RoomData { name:"next".into(), caption:String::new(), width:640, height:480,
        speed:60, persistent:false, objects:vec![], tiles:vec![] };
    (b,s,room,id)
}

#[test]
fn room_end_failure_aborts_before_loading_target_geometry() {
    let (b,mut s,room,id) = fixture(5,false);
    let error = s.transition_to_room(&b,4,&room).expect_err("Room End error must not be swallowed");
    assert!(error.contains("CODE 42") && error.contains("missing CODE body"), "{error}");
    assert_eq!(s.current_room,3.0);
    assert_eq!(s.room_width,320.0);
    assert!(s.instances.contains_key(&id));
}

#[test]
fn room_start_failure_is_returned_after_target_load_without_fake_rollback() {
    let (b,mut s,room,id) = fixture(4,false);
    let error = s.transition_to_room(&b,4,&room).expect_err("Room Start error must not be swallowed");
    assert!(error.contains("CODE 42") && error.contains("missing CODE body"), "{error}");
    assert_eq!(s.current_room,4.0, "no transaction rollback is claimed");
    assert_eq!(s.room_width,640.0);
    assert!(s.instances.contains_key(&id));
}

#[test]
fn valid_room_callbacks_still_allow_transition() {
    for subtype in [4,5] {
        let (b,mut s,room,id) = fixture(subtype,true);
        s.transition_to_room(&b,4,&room).unwrap();
        assert_eq!(s.current_room,4.0);
        assert!(s.instances.contains_key(&id));
    }
}
