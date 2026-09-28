use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

#[test]
fn ini_savefile_produces_standard_section_header_and_roundtrips() {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let bundle = Arc::new(load_bundle_from_file(&bundle_path).expect("load full_ir.json"));

    let temp_dir = std::env::temp_dir().join(format!("cally_ini_test_{}", std::process::id()));
    let _ = std::fs::create_dir_all(&temp_dir);

    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.ini_disk_dir = Some(temp_dir.clone());

    // 1. Open savefile.ini
    let str_savefile = scene.alloc_string(&bundle, "savefile.ini".into());
    let str_sec = scene.alloc_string(&bundle, "Save".into());
    let str_key1 = scene.alloc_string(&bundle, "talkedtolloyd1".into());
    let str_key2 = scene.alloc_string(&bundle, "callylevel".into());

    scene.call(&bundle, 0, "ini_open", &[str_savefile]).expect("ini_open");
    scene.call(&bundle, 0, "ini_write_real", &[str_sec, str_key1, 1.0]).expect("write talkedtolloyd1");
    scene.call(&bundle, 0, "ini_write_real", &[str_sec, str_key2, 5.0]).expect("write callylevel");
    scene.call(&bundle, 0, "ini_close", &[]).expect("ini_close");

    // 2. Read raw disk text: verify [Save] section header exists
    let disk_file = temp_dir.join("savefile.ini");
    assert!(disk_file.exists(), "savefile.ini must be written to disk");
    let raw_text = std::fs::read_to_string(&disk_file).expect("read savefile.ini");
    assert!(
        raw_text.contains("[Save]"),
        "Disk file must contain standard INI section header [Save], got:\n{raw_text}"
    );
    assert!(
        raw_text.contains("talkedtolloyd1=1"),
        "Disk file must contain talkedtolloyd1=1"
    );
    assert!(
        raw_text.contains("callylevel=5"),
        "Disk file must contain callylevel=5"
    );

    // 3. Create fresh scene with disk dir and verify ini_read_real retrieves values under [Save]
    let mut scene2 = Scene::default();
    scene2.init_bundle(&bundle);
    scene2.ini_disk_dir = Some(temp_dir.clone());
    let str_savefile2 = scene2.alloc_string(&bundle, "savefile.ini".into());
    let str_sec2 = scene2.alloc_string(&bundle, "Save".into());
    let str_key2_2 = scene2.alloc_string(&bundle, "callylevel".into());

    scene2.call(&bundle, 0, "ini_open", &[str_savefile2]).expect("ini_open fresh");
    let val = scene2.call(&bundle, 0, "ini_read_real", &[str_sec2, str_key2_2, 0.0]).expect("ini_read_real");
    scene2.call(&bundle, 0, "ini_close", &[]).expect("ini_close fresh");
    assert_eq!(val, 5.0, "Fresh scene must read 5.0 from disk under [Save]");

    // Clean up
    let _ = std::fs::remove_dir_all(&temp_dir);
}
