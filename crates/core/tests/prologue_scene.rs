use callys_core::code_vm::prologue_bundle;
use callys_core::ir_scene::Scene;

/// Full prologue run against real compiled CODE bodies: Create -> 120 ticks
/// (alarm flow: logo spawn, movement phases, tap unlock) -> tap exit ->
/// Destroy activates everything and kills phone/logo draws.
#[test]
fn prologue_real_code_full_lifecycle() {
    let b = prologue_bundle();
    let mut s = Scene::default();
    // obj_introduction spawns at player position (view 0 at origin).
    s.view_positions.insert(0, (0.0, 0.0));
    let intro = s.create(&b, 137, 0.0, 0.0).expect("create obj_introduction");

    // Create ran: 68 instructions, deactivated all, spawned obj_phone,
    // scheduled alarms 0..=3 and queued mus_new4 audio.
    assert!(s.instances[&intro].alarms.iter().any(|&a| a > 0), "alarms scheduled");
    let created_phone = s.instances.values().filter(|i| i.object == 136).count();
    assert_eq!(created_phone, 1, "obj_phone spawned by Create");
    assert!(s.instances[&intro].fields["taplock"] == 0.0);
    assert!(!s.audio.is_empty(), "mus_new4 queued at Create");

    // 30 ticks: alarm1 -> moving=0, moving2=1 (CODE552).
    for _ in 0..30 { s.tick(&b).expect("tick 1..30"); }
    assert_eq!(s.instances[&intro].fields["moving"], 0.0);
    assert_eq!(s.instances[&intro].fields["moving2"], 1.0);

    // 40 more ticks (total 70): alarm2 spawns obj_logo (CODE551),
    // alarm3 stops moving2 (CODE550).
    for _ in 0..40 { s.tick(&b).expect("tick 31..70"); }
    let logo = s.instances.values().filter(|i| i.object == 135).count();
    assert_eq!(logo, 1, "obj_logo spawned by alarm2");
    assert_eq!(s.instances[&intro].fields["moving2"], 0.0);

    // 50 more ticks (total 120): alarm0 sets taplock=1 (CODE553).
    for _ in 0..50 { s.tick(&b).expect("tick 71..120"); }
    assert_eq!(s.instances[&intro].fields["taplock"], 1.0);

    // View-configured draw pass over the frozen scene: introduction Draw +
    // phone/logo Draw must emit commands with view 0 recorded.
    let draws_before = s.draws.len();
    s.draw_view(&b, 0).expect("draw view 0");
    assert!(s.draws.len() > draws_before, "draw commands emitted");
    assert!(s.draws.iter().all(|d| d.view == 0));

    // Tap exits: Step sees mouse_pressed and destroys the instance (CODE554),
    // then Destroy (CODE549) reactivates everything and removes phone/logo.
    s.mouse_pressed = true;
    s.tick(&b).expect("tap tick");
    assert!(!s.instances[&intro].alive, "introduction destroyed on tap");

    // Step of a destroyed instance no longer runs; next tick is clean.
    s.tick(&b).expect("post-exit tick");

    // Verify movement totals with original event order: alarm decrement
    // happens BEFORE Step. Ticks 1..29 move -2 (moving=1); tick 30 fires
    // alarm1 (moving=0, moving2=1) then Step moves -1; ticks 30..69 move -1
    // (40 ticks); tick 70 fires alarms 2/3 (moving2=0) so Step is stationary;
    // ticks 71..120 stationary.
    let xx1 = s.instances[&intro].fields["xx1"];
    assert_eq!(xx1, 110.0 - 2.0 * 29.0 - 1.0 * 40.0, "xx1 exact original arithmetic");
}
