//! Original particle-domain slice: hit particles spawned by real CODE 281
//! (obj_arrow Step) via part_particles_create, with types configured by the
//! real obj_pwrlevelinitialize Create (CODE 458). This is the IR scene host,
//! NOT the original GM runner; RNG parity is a fixture policy (seeded LCG).
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;

fn bundle() -> callys_core::code_vm::Bundle {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let p = Path::new(manifest_dir).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// Baseline globals required by obj_player Create (CODE 0) when the scene
/// materializes instances, mirroring player_step_ir.rs.
fn seed_player_globals(s: &mut Scene) {
    for (k, v) in [
        ("maxhp", 4.0), ("health1", 4.0), ("level", 1.0), ("experience", 0.0),
        ("coinmultiply", 1.0), ("coinpickup", 0.0), ("playerdied", 0.0),
        ("rebuff", 0.0), ("roomstart", 0.0), ("soundmute", 0.0),
        ("swing", 1.0), ("swordupgradebought", 0.0), ("swordupgrade2bought", 0.0),
        ("swordupgrade3bought", 0.0),
    ] {
        s.globals.insert(k.into(), v);
    }
}

#[test]
fn arrow_hit_spawns_real_particles_via_original_code_281() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    seed_player_globals(&mut s);

    // Original initialization order: obj_pwrlevelinitialize is the room-start
    // global initializer (global.pwr + particle types), enemies created after.
    let init = s.create(&b, 103, -1000.0, -1000.0).expect("create obj_pwrlevelinitialize");
    s.instances.get_mut(&init).unwrap().alive = false; // creator ran once; keep it inert
    let p_system = s.globals["P_System"];
    let particle1 = s.globals["Particle1"];
    assert!(p_system >= 1.0, "P_System must hold a real system handle, got {p_system}");
    assert!(particle1 >= 1.0, "Particle1 must hold a real type handle, got {particle1}");
    assert!(s.particle_types.iter().any(|(k, _)| *k == particle1), "type registry must know Particle1");
    assert!(s.particle_systems.contains(&p_system), "system registry must know P_System");

    // Player next to the impact point (arrow Create reads obj_player.facing;
    // distance guard for the wall branch wants player within 16 px).
    let player = s.create(&b, 0, 216.0, 200.0).expect("create obj_player");
    s.instances.get_mut(&player).unwrap().fields.insert("facing".into(), 1.0);

    // The victim: obj_knifebandit (id 15) exactly under the arrow. Its Create
    // reads global.pwr (set by the initializer above) to define hpknife.
    let victim = s.create(&b, 15, 200.0, 200.0).expect("create obj_knifebandit");
    s.globals.insert("bowdamage".into(), 5.0);
    s.globals.insert("bowxp".into(), 0.0);
    s.globals.insert("poisonenabled".into(), 0.0);
    let hp_before = s.instances[&victim].fields.get("hpknife").copied()
        .expect("knifebandit Create must define hpknife from global.pwr/level");

    // The arrow (id 38): Create sets hspeed=-15 for facing 1.
    let arrow = s.create(&b, 38, 200.0, 200.0).expect("create obj_arrow");
    assert_eq!(s.instances[&arrow].fields["hspeed"], -15.0, "arrow Create must set hspeed");

    // Dispatch the real obj_arrow Step (CODE 281): instance_place must hit
    // the knifebandit, and the hit branch must spawn 3 particles at (200,200).
    s.dispatch(&b, arrow, 3, 0).expect("dispatch obj_arrow Step");

    let victim_fields = &s.instances[&victim].fields;
    assert_eq!(victim_fields["flashing"], 1.0, "hit branch must flash the victim");
    assert_eq!(victim_fields["stunned"], 1.0, "hit branch must stun the victim");
    assert_eq!(s.globals["bowxp"], 1.0, "hit branch must award bow xp");
    let hp_after = victim_fields.get("hpknife").copied()
        .expect("hit must not remove hpknife");
    assert_ne!(hp_before, hp_after, "hit branch must damage hpknife via bowdamage");

    assert_eq!(s.particles.len(), 3, "CODE 281 must spawn 3 particles at the impact point");
    for p in &s.particles {
        assert_eq!(p.type_id, particle1, "particles must reference global.Particle1's type");
        assert!(p.life >= 1.0, "spawned life must come from the original life range 1..=12");
        assert_eq!(p.life0, p.life, "life0 must record the spawned lifetime");
        // part_type_color2 semantics: color blends color1 -> color2 over the
        // particle lifetime; at spawn progress is 0, so color == color1
        // (16777215 = white), never a random draw between the endpoints.
        assert_eq!(p.color_min, 16777215, "color_min must carry original color1");
        assert_eq!(p.color_max, 4235519, "color_max must carry original color2");
        assert_eq!(p.color, 16777215, "spawn color must be original color1 (progress 0)");
        // speed 8..=12 at a random direction: the per-tick velocity is nonzero.
        let v = p.vx.hypot(p.vy);
        assert!(v > 0.0, "particle velocity must come from the original speed range 8..=12, v={v}");
    }
}

#[test]
fn particles_integrate_and_expire_in_scene_tick() {
    let b = bundle();
    let mut s = Scene::default();
    s.init_bundle(&b);
    seed_player_globals(&mut s);

    // Original initialization order: pwr initializer first, then actors.
    let init = s.create(&b, 103, -1000.0, -1000.0).expect("create obj_pwrlevelinitialize");
    s.instances.get_mut(&init).unwrap().alive = false;
    let player = s.create(&b, 0, 216.0, 200.0).expect("create obj_player");
    s.instances.get_mut(&player).unwrap().fields.insert("facing".into(), 1.0);
    let victim = s.create(&b, 15, 200.0, 200.0).expect("create obj_knifebandit");
    let arrow = s.create(&b, 38, 200.0, 200.0).expect("create obj_arrow");

    // Hit happens while both actors are alive...
    s.dispatch(&b, arrow, 3, 0).expect("dispatch obj_arrow Step");
    assert_eq!(s.particles.len(), 3, "hit must spawn 3 particles");

    // ...then freeze the world so the next tick integrates particles in isolation.
    s.instances.get_mut(&victim).unwrap().alive = false;
    s.instances.get_mut(&arrow).unwrap().alive = false;
    s.instances.get_mut(&player).unwrap().alive = false;

    let before: Vec<(f64, f64)> = s.particles.iter().map(|p| (p.x, p.y)).collect();
    s.tick(&b).expect("scene tick integrates particles");
    let survivors: Vec<(f64, f64)> = s.particles.iter().map(|p| (p.x, p.y)).collect();
    assert!(!survivors.is_empty(), "life 1..=12 must keep particles alive 1 tick after spawn");
    let any_moved = survivors.iter().enumerate()
        .any(|(i, &(x, y))| (x - before[i].0).hypot(y - before[i].1) > 0.0);
    assert!(any_moved, "scene tick must integrate particle velocity");

    // color2 gradient: after one tick every surviving particle has aged, so
    // its color must have left color1 (white) toward color2 (orange) along
    // every channel: g in (160,255), b in (64,255) for white->orange.
    for p in &s.particles {
        let g = ((p.color >> 8) & 0xFF) as i32;
        let bch = (p.color & 0xFF0000) >> 16;
        assert!(g < 255 && g > 160, "gradient g must leave 255 toward 160, got {g}");
        let b = bch as i32;
        assert!(b < 255 && b > 64, "gradient b must leave 255 toward 64, got {b}");
    }
}
