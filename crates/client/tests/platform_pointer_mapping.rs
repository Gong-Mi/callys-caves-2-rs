//! Execute real Java adapters, then feed their coordinates through the real
//! Rust client pointer entry points. JNI/ART delivery itself is a separate gate.
use callys_client::GameState;
use callys_core::code_vm::load_bundle_from_file;
use std::{path::Path, process::Command, sync::Arc};
#[test]
fn physical_java_edges_reach_the_same_world_point_through_the_client() {
    let root=Path::new(env!("CARGO_MANIFEST_DIR")).join("../..");
    let dir=tempfile::tempdir().unwrap();
    let src=root.join("android-build/src/com/gongmi/callyscaves2");
    let output=Command::new("javac").args(["--release","17","-d"]).arg(dir.path())
        .arg(src.join("InputViewport.java")).arg(src.join("PointerReleaseQueue.java"))
        .arg(root.join("android-build/tests/PointerMappingBridge.java"))
        .output().expect("javac must exercise the production Java adapter");
    assert!(output.status.success(),"{}",String::from_utf8_lossy(&output.stderr));
    let output=Command::new("java").arg("-cp").arg(dir.path())
        .arg("com.gongmi.callyscaves2.PointerMappingBridge").output().unwrap();
    assert!(output.status.success(),"{}",String::from_utf8_lossy(&output.stderr));
    let mut s=GameState::new(&root.join("assets/game.droid")).unwrap();
    let b=load_bundle_from_file(&root.join("crates/core/src/generated/full_ir.json")).unwrap();
    s.enable_ir_gameplay(Arc::new(b)).unwrap();
    for _ in 0..125 {s.step(1.0/30.0);}
    s.input.tap=true; s.step(1.0/30.0); s.input.tap=false; s.step(1.0/30.0);
    assert!(s.runtime_diagnostic.is_none());
    let scene=s.scene.as_ref().unwrap(); let v=scene.active_view_index().unwrap();
    let origin=scene.view_positions[&(v as i32)]; let view=&scene.room_views[v];
    let extent=(view.wview as f64,view.hview as f64);
    let stdout=String::from_utf8(output.stdout).unwrap(); let mut cases=0;
    for line in stdout.lines() {
        let n:Vec<f64>=line.split_whitespace().map(|v|v.parse().unwrap()).collect();
        assert_eq!(n.len(),5);
        let expected=(origin.0+extent.0*n[0],origin.1+extent.1*n[0]);
        s.pointer_pressed(n[1],n[2]); s.pointer_released(n[3],n[4]);
        let scene=s.scene.as_ref().unwrap();
        let down=*scene.left_presses.last().unwrap(); let up=*scene.left_releases.last().unwrap();
        for actual in [down,up] {
            assert!((actual.0-expected.0).abs()<1e-4 && (actual.1-expected.1).abs()<1e-4,
                "physical fraction {} must reach {expected:?}, got {actual:?}",n[0]);
        }
        assert_eq!(down,up,"one physical pointer may not split into two world points");
        cases+=1;
    }
    assert_eq!(cases,12,"all surfaces and pointer samples executed");
}
