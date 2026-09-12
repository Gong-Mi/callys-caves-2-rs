use callys_core::{code_vm::Bundle, ir_scene::Scene};

fn fixture() -> (Bundle, Scene, i32) {
    let b: Bundle = serde_json::from_value(serde_json::json!({
        "schema":1,"objects":[
            {"id":1,"name":"receiver","sprite":1,"depth":0,"events":[{"event_type":6,"subtype":7,"codes":[1]}]},
            {"id":2,"name":"child","sprite":1,"depth":0,"parent":1,"parent_chain":[1],"events":[]}
        ],
        "codes":[{"id":1,"start":0,"end":8,"instructions":[
            {"offset":0,"code_offset":0,"words_raw":[0],"op":"constant","value":1},
            {"offset":4,"code_offset":4,"words_raw":[0],"op":"store","name":"clicked","selector":-1,"array":false}
        ]}]
    })).unwrap();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.sprite_bounds.insert(1, callys_core::ir_scene::SpriteBounds { width:20.0,height:10.0,origin_x:5.0,origin_y:2.0,frames:1.0 });
    let id = s.create(&b,2,100.0,50.0).unwrap();
    (b,s,id)
}

#[test]
fn local_release_hits_origin_adjusted_bounds_and_inherited_event_once() {
    let (b,mut s,id) = fixture();
    s.left_releases.push((95.0,48.0));
    s.tick(&b).unwrap();
    assert_eq!(s.instances[&id].fields["clicked"],1.0);
    assert!(s.left_releases.is_empty());
    s.instances.get_mut(&id).unwrap().fields.insert("clicked".into(),0.0);
    s.tick(&b).unwrap();
    assert_eq!(s.instances[&id].fields["clicked"],0.0);
}

#[test]
fn missed_and_nonfinite_releases_do_not_become_global_clicks() {
    let (b,mut s,id) = fixture();
    s.left_releases.extend([(94.0,48.0),(115.0,48.0),(95.0,58.0),(f64::NAN,50.0)]);
    s.tick(&b).unwrap();
    assert!(!s.instances[&id].fields.contains_key("clicked"));
    assert!(s.left_releases.is_empty());
}

#[test]
fn inactive_dead_and_external_instances_cannot_receive_release() {
    for mode in 0..3 {
        let (b,mut s,id) = fixture();
        let i = s.instances.get_mut(&id).unwrap();
        match mode { 0 => i.active=false, 1 => i.alive=false, _ => i.external=true }
        s.left_releases.push((100.0,50.0));
        s.tick(&b).unwrap();
        assert!(!s.instances[&id].fields.contains_key("clicked"));
        assert!(s.left_releases.is_empty());
    }
}

#[test]
fn release_vm_error_propagates_and_queue_is_consumed() {
    let (mut b,mut s,_) = fixture();
    b.codes.clear();
    s.left_releases.push((100.0,50.0));
    assert!(s.tick(&b).unwrap_err().contains("missing CODE body"));
    assert!(s.left_releases.is_empty());
}
