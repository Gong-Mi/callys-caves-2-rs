use callys_core::code_vm::{Bundle, Host};
use callys_core::ir_scene::Scene;

#[test]
fn motion_integration_gravity_friction_and_builtins() {
    let bundle = Bundle {
        schema: 1,
        string_table: vec![],
        objects: vec![],
        room_bindings: vec![],
        codes: vec![],
    };

    let mut s = Scene::default();
    let id = s.insert_external(1);

    // Initial position
    s.write(id, -1, "x", None, 100.0).unwrap();
    s.write(id, -1, "y", None, 200.0).unwrap();

    // 1. Test motion_set builtin: direction 0 (right), speed 10
    s.call(&bundle, id, "motion_set", &[0.0, 10.0]).unwrap();
    assert_eq!(s.read(id, -1, "hspeed", None).unwrap(), 10.0);
    assert_eq!(s.read(id, -1, "vspeed", None).unwrap(), 0.0);
    assert_eq!(s.read(id, -1, "speed", None).unwrap(), 10.0);
    assert_eq!(s.read(id, -1, "direction", None).unwrap(), 0.0);

    // 2. Test motion integration on tick: x advances by hspeed (10.0)
    // Make instance non-external so tick integrates it
    s.instances.get_mut(&id).unwrap().external = false;
    s.tick(&bundle).unwrap();
    assert_eq!(s.read(id, -1, "x", None).unwrap(), 110.0);
    assert_eq!(s.read(id, -1, "y", None).unwrap(), 200.0);

    // 3. Test gravity integration: gravity = 0.5 (default direction 270 / downward)
    s.write(id, -1, "gravity", None, 0.5).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.read(id, -1, "x", None).unwrap(), 120.0);
    // vspeed increased by 0.5, y advanced by 0.5
    assert_eq!(s.read(id, -1, "vspeed", None).unwrap(), 0.5);
    assert_eq!(s.read(id, -1, "y", None).unwrap(), 200.5);

    // 4. Test friction integration: friction = 2.0 on hspeed = 10.0
    s.write(id, -1, "gravity", None, 0.0).unwrap();
    s.write(id, -1, "vspeed", None, 0.0).unwrap();
    s.write(id, -1, "hspeed", None, 10.0).unwrap();
    s.write(id, -1, "friction", None, 2.0).unwrap();
    s.tick(&bundle).unwrap();
    // Speed decayed from 10 to 8, x advanced by 8
    assert_eq!(s.read(id, -1, "hspeed", None).unwrap(), 8.0);
    assert_eq!(s.read(id, -1, "x", None).unwrap(), 128.0);

    // 5. Test point_direction: (0, 0) to (100, 0) = 0 degrees (right)
    let dir_right = s.call(&bundle, id, "point_direction", &[0.0, 0.0, 100.0, 0.0]).unwrap();
    assert_eq!(dir_right, 0.0);
    // (0, 0) to (0, -100) = 90 degrees (up in GMS coordinate space where y is down)
    let dir_up = s.call(&bundle, id, "point_direction", &[0.0, 0.0, 0.0, -100.0]).unwrap();
    assert_eq!(dir_up, 90.0);

    // 6. Test instance_number builtin
    let num = s.call(&bundle, id, "instance_number", &[1.0]).unwrap();
    assert_eq!(num, 1.0);

    println!("Verified: motion_set, gravity, friction, velocity integration, and geometric builtins pass!");
}
