//! The final two unexecuted object bodies (object matrix: executed 801/803).
//!
//! CODE 502 (obj_poisoniap Other_66): the IAP async receipt. `iap_data` is
//! an instance-variable map handle (selector -1); type==2 is the purchase
//! path (create a details map, iap_purchase_details stub returns without
//! filling it, the status read is therefore 0 and the == 0 gate passes;
//! product_id lands as the numeric 0.0 and purchaseMap[0] = 1), type==3 is
//! the consume path, whose shipped bytecode ALWAYS halts: both bf jumps land
//! on `ds_map_destroy(map)` and `map` is only assigned in case 2 — see the
//! test body for the offset evidence. Anything else falls straight to the
//! tail ds_map_secure_save. The inner
//! `product_id == "poisongem"` switch is UNREACHABLE BY DESIGN under the
//! engine's numeric ds_map: a pooled string reference never equals a
//! numeric value (render-draw-1.md's string-equality boundary; this work
//! never observes it). poisonenabled/gemdropenabled therefore stay untouched
//! and the assertions pin exactly that.
//!
//! CODE 686 (obj_woodblock Collision 36 = obj_blade): a bare
//! instance_destroy. Natural play never runs it — the blade's Step scan
//! kills both parties first and obj_blade has no Collision 158 (see
//! woodblock_shattering_ir.rs) — so the pair is driven by direct dispatch,
//! the registered precedent for shipped-but-preempted collision bodies.
//! The destroy fires the woodblock's own Destroy (CODE 685): six logparts.
use callys_core::code_vm::{load_bundle_from_file, Bundle, Host, STRING_REF_BASE};
use callys_core::ir_scene::Scene;
use std::path::Path;

const POISONIAP: i32 = 120;
const WOOD: i32 = 158;
const BLADE: i32 = 36;
const LOGPARTS: i32 = 155;

// String-table indices the bytecode loads as keys.
const KEY_TYPE: f64 = STRING_REF_BASE + 92.0;
const KEY_INDEX: f64 = STRING_REF_BASE + 980.0;
const KEY_PRODUCT_IAP: f64 = STRING_REF_BASE + 984.0;
const KEY_CONSUMED: f64 = STRING_REF_BASE + 989.0;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

fn scene(b: &Bundle) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    s
}

fn field(s: &Scene, id: i32, name: &str) -> f64 {
    s.instances.get(&id).unwrap().fields[name]
}
fn alive(s: &Scene, id: i32) -> bool {
    s.instances.get(&id).map(|i| i.alive).unwrap_or(false)
}
fn logs(s: &Scene) -> usize {
    s.instances.iter().filter(|(_, i)| i.object == LOGPARTS && i.alive).count()
}

#[test]
fn iap_receipt_purchase_and_consume_paths_update_the_purchase_map() {
    let b = bundle();
    let mut s = scene(&b);
    let purchase_map = s.call(&b, POISONIAP, "ds_map_create", &[]).unwrap() as i32;
    s.globals.insert("purchaseMap".into(), purchase_map as f64);

    let poi = s.create(&b, POISONIAP, 0.0, 0.0).unwrap();
    // The receipt map: type 2 (purchase) with an index handle.
    let iap = s.call(&b, poi, "ds_map_create", &[]).unwrap();
    s.instances.get_mut(&poi).unwrap().fields.insert("iap_data".into(), iap);
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_TYPE, 2.0]).unwrap();
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_INDEX, 5.0]).unwrap();

    s.dispatch(&b, poi, 7, 66).expect("purchase receipt");
    // Details map stays stub-empty -> status reads 0 -> gate passes ->
    // product_id is numeric 0 -> purchaseMap[0] = 1.
    assert_eq!(s.call(&b, poi, "ds_map_find_value", &[purchase_map as f64, 0.0]).unwrap(), 1.0,
        "the purchase path records product 0");
    // The unreachable-by-design boundary: the IAP switch never flips.
    assert_eq!(s.globals["poisonenabled"], 0.0, "poisongem never matches a numeric product id");
    assert_eq!(s.globals["gemdropenabled"], 1.0, "fresh-start baseline stands");

    // Bytecode beats the decompiled GML here: BOTH bf jumps in case 3 land on
    // the `load_local map; ds_map_destroy(map)` at @0x47a29c, so the consume
    // path reaches the destroy whether or not `consumed` is truthy — and
    // `map` was only ever assigned in case 2. Every type-3 receipt therefore
    // halts on the undefined local (the original runner aborts the same
    // script non-fatally at this point), which means the refund path NEVER
    // reaches the trailing ds_map_secure_save: consumed purchases are zeroed
    // in memory but not persisted. The VM entry before the halt is the
    // execution evidence for CODE 502.
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_TYPE, 3.0]).unwrap();
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_PRODUCT_IAP, 7.0]).unwrap();
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_CONSUMED, 1.0]).unwrap();
    s.call(&b, poi, "ds_map_replace", &[purchase_map as f64, 7.0, 1.0]).unwrap();
    let err = s.dispatch(&b, poi, 7, 66).expect_err("undefined local map halts the refund path");
    assert!(err.contains("undefined local map"), "halt is the unassigned map, not something else: {err}");
    assert_eq!(s.call(&b, poi, "ds_map_find_value", &[purchase_map as f64, 7.0]).unwrap(), 0.0,
        "the consume path zeroes the product's entry BEFORE halting");
    assert_eq!(s.globals["poisonenabled"], 0.0, "the halt happens after the numeric-only switch");

    // A falsy `consumed` skips the replace (the bf lands on the same
    // destroy) and halts the same way — the entry stays bought.
    s.call(&b, poi, "ds_map_replace", &[purchase_map as f64, 7.0, 1.0]).unwrap();
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_CONSUMED, 0.0]).unwrap();
    let err2 = s.dispatch(&b, poi, 7, 66).expect_err("the falsy path hits the same unassigned map");
    assert!(err2.contains("undefined local map"), "{err2}");
    assert_eq!(s.call(&b, poi, "ds_map_find_value", &[purchase_map as f64, 7.0]).unwrap(), 1.0,
        "unconsumed leaves the entry alone");

    // Neither case (type 5): the switch default falls straight to the tail
    // and the body completes through ds_map_secure_save.
    s.call(&b, poi, "ds_map_replace", &[iap, KEY_TYPE, 5.0]).unwrap();
    s.dispatch(&b, poi, 7, 66).expect("unhandled receipt type completes to the tail");
    assert_eq!(field(&s, poi, "iap_data"), iap, "the receipt map handle is still the instance var");
    // secure_save is a registered no-op: the IR save path persists via
    // ini_data instead (Room End CODE 15), so no file side effect to assert.
}

#[test]
fn woodblock_collision_with_the_blade_destroys_it_and_spills_logparts() {
    let b = bundle();
    let mut s = scene(&b);
    let wood = s.create(&b, WOOD, 300.0, 100.0).unwrap();
    // CODE 271 (blade Create) reads obj_player.facing through the object
    // selector (alive+active filter): the player stays active until the
    // blade exists, then parks so its own Step gravity can't drift anything.
    let p = s.create(&b, 0, 500.0, 100.0).unwrap();
    let blade = s.create(&b, BLADE, 300.0, 100.0).unwrap();
    s.instances.get_mut(&p).unwrap().active = false;
    assert_eq!(logs(&s), 0, "no spill before the hit");
    // Direct dispatch: the shipped pair (obj_woodblock Collision 36), which
    // natural play pre-empts via the blade's Step scan. CODE 686 is bare
    // instance_destroy; the Destroy (685) runs through Scene::destroy.
    s.dispatch(&b, wood, 4, BLADE).expect("collision pair dispatch");
    assert!(!alive(&s, wood), "CODE 686 destroys the block");
    assert_eq!(logs(&s), 6, "the woodblock Destroy sprays six logparts");
    // The blade is untouched by the block's collision body.
    assert!(alive(&s, blade), "the block's Collision 36 only kills itself");
}
