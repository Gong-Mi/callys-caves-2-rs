use callys_asset::GameDroidAsset;
use callys_core::{code_vm::{load_bundle_from_file, Host}, ir_scene::Scene};
use std::path::Path;

#[test]
fn original_score_site_ledger_covers_every_access() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let b = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    let mut sites = Vec::new();
    for code in &b.codes {
        for i in &code.instructions {
            let (op, name, selector, array, other) = match &i.op {
                callys_core::code_vm::Op::Load {name,selector,array,other} => ("load",name,selector,array,other),
                callys_core::code_vm::Op::Store {name,selector,array,other} => ("store",name,selector,array,other),
                _ => continue,
            };
            if name != "score" { continue; }
            assert_eq!((*selector,*array,*other),(-1,false,false));
            sites.push(serde_json::json!({"code":code.id,"offset":i.offset,"op":op,
                "selector":selector,"array":array,"other":other}));
        }
    }
    let ledger: serde_json::Value = serde_json::from_str(&std::fs::read_to_string(
        root.join("../../reconstruction/contracts/score-sites.json")).unwrap()).unwrap();
    assert_eq!(sites.len(),85);
    assert_eq!(ledger["sites"],serde_json::json!(sites));
}

#[test]
fn legacy_score_is_shared_between_instance_contexts() {
    let mut s = Scene::default();
    let a = s.insert_external(1);
    let b = s.insert_external(2);
    s.write(a,-1,"score",None,500.0).unwrap();
    assert_eq!(s.read(b,-1,"score",None).unwrap(),500.0);
    s.write(b,-1,"score",None,250.0).unwrap();
    assert_eq!(s.read(a,-1,"score",None).unwrap(),250.0);
}

#[test]
fn original_health_shop_spends_players_coins_and_death_deducts_same_balance() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut b = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    b.string_table = asset.string_table.clone();
    let mut s = Scene::default();
    s.init_bundle(&b);
    s.init_fresh_start_globals();
    s.load_room_from_data(&b,0,&asset.rooms[0]).unwrap();
    let player = *s.instances.iter().find(|(_,i)| i.object==0 && i.alive).unwrap().0;
    s.write(player,-1,"score",None,500.0).unwrap();
    // Original player Collision60 CODE14 adds four coins and destroys other.
    let pickup = s.create(&b,60,10.0,10.0).unwrap();
    s.other_instance = Some(pickup);
    s.dispatch(&b,player,4,60).unwrap();
    s.other_instance = None;
    assert!(!s.instances[&pickup].alive);
    let collected = 500.0 + 4.0 * s.globals["coinmultiply"];
    assert_eq!(s.read(player,-1,"score",None).unwrap(),collected);
    let after_shop = collected - 250.0;
    s.globals.insert("health1".into(),3.0);
    s.globals.insert("maxhp".into(),4.0);
    let shop = s.create(&b,99,0.0,0.0).unwrap();
    assert_eq!(s.read(shop,-1,"score",None).unwrap(),collected,"creating a UI must not reset shared score");
    s.dispatch(&b,shop,6,7).unwrap(); // original CODE447
    assert_eq!(s.globals["health1"],4.0);
    assert_eq!(s.read(player,-1,"score",None).unwrap(),after_shop);
    s.dispatch(&b,shop,6,7).unwrap(); // full health: no second deduction
    assert_eq!(s.read(player,-1,"score",None).unwrap(),after_shop);
    let death = s.create(&b,134,0.0,0.0).unwrap();
    let deduction = s.instances[&death].fields["coindeduct"];
    s.instances.get_mut(&death).unwrap().fields.insert("taplock".into(),1.0);
    s.dispatch(&b,death,6,7).unwrap(); // CODE543 -> Destroy CODE541
    assert_eq!(s.read(player,-1,"score",None).unwrap(),after_shop-deduction);
    s.transition_to_room(&b,0,&asset.rooms[0]).unwrap();
    assert_eq!(s.read(player,-1,"score",None).unwrap(),after_shop-deduction,"room load must not reset shared score");
}
