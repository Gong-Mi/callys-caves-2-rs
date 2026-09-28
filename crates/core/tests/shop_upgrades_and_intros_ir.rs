use callys_asset::GameDroidAsset;
use callys_core::code_vm::load_bundle_from_file;
use callys_core::ir_scene::Scene;
use std::path::Path;
use std::sync::Arc;

const KNIFE_INTRO: i32 = 167;
const SPIDER_INTRO: i32 = 168;
const BOSS1_INTRO: i32 = 172;

const POWER_UPGRADE_2: i32 = 85;
const TRIPLE_JUMP: i32 = 87;
const MAX_HP_UPGRADE: i32 = 97;

fn load_bundle_with_strings() -> Arc<callys_core::code_vm::Bundle> {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();
    Arc::new(bundle)
}

#[test]
fn enemy_intro_cards_lifecycle_and_text_emission() {
    let bundle = load_bundle_with_strings();

    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();

    // 1. Knife Bandit Intro (167)
    let knife_intro = scene.create(&bundle, KNIFE_INTRO, 500.0, 300.0).expect("create knife intro");
    assert_eq!(
        scene.instances[&knife_intro].alarms[0], 60,
        "knife intro card must arm alarm[0] = 60"
    );

    // Verify Draw event emits "Knife Bandit"
    scene.draws.clear();
    scene.texts.clear();
    scene.dispatch(&bundle, knife_intro, 8, 0).expect("knife intro draw");
    assert!(
        scene.texts.iter().any(|t| t.text.contains("Knife Bandit")),
        "Draw event must render 'Knife Bandit' text, got: {:?}",
        scene.texts
    );

    // Fire Alarm 0: must self-destroy
    scene.dispatch(&bundle, knife_intro, 2, 0).expect("alarm 0 fire");
    assert!(!scene.instances[&knife_intro].alive, "knife intro must self-destroy on alarm 0");

    // 2. Spider Intro (168)
    let spider_intro = scene.create(&bundle, SPIDER_INTRO, 500.0, 300.0).expect("create spider intro");
    scene.draws.clear();
    scene.texts.clear();
    scene.dispatch(&bundle, spider_intro, 8, 0).expect("spider intro draw");
    assert!(
        scene.texts.iter().any(|t| t.text.contains("Spider")),
        "Draw event must render 'Spider' text"
    );

    // 3. Boss 1 Intro (172)
    let boss1_intro = scene.create(&bundle, BOSS1_INTRO, 500.0, 300.0).expect("create boss1 intro");
    scene.draws.clear();
    scene.texts.clear();
    scene.dispatch(&bundle, boss1_intro, 8, 0).expect("boss1 intro draw");
    assert!(
        scene.texts.iter().any(|t| t.text.contains("Mama Bear")),
        "Draw event must render Mama Bear boss intro text, got: {:?}",
        scene.texts
    );
}

#[test]
fn shop_upgrades_purchase_and_state_transitions() {
    let bundle = load_bundle_with_strings();

    let mut scene = Scene::default();
    scene.init_bundle(&bundle);
    scene.init_fresh_start_globals();

    // Seed scene.score = 50,000 (score is scene.score, not in globals)
    scene.score = 50000.0;
    scene.globals.insert("level".into(), 1.0);
    scene.globals.insert("maxhp".into(), 100.0);
    scene.globals.insert("health1".into(), 100.0);

    // 1. Buy Triple Jump (cost 3,000)
    let tj = scene.create(&bundle, TRIPLE_JUMP, 100.0, 100.0).expect("create triple jump");
    scene.dispatch(&bundle, tj, 6, 0).expect("click triple jump");
    assert_eq!(
        scene.score,
        47000.0,
        "score deducted 3000 for triple jump"
    );
    assert_eq!(scene.globals.get("tjumpactive").copied(), Some(1.0));
    assert_eq!(scene.globals.get("triplejumpbought").copied(), Some(1.0));

    // Clicking again must not re-deduct
    scene.dispatch(&bundle, tj, 6, 0).expect("re-click triple jump");
    assert_eq!(scene.score, 47000.0, "cannot double-buy triple jump");

    // 2. Buy Power Upgrade 2 (cost 25,000)
    let pu2 = scene.create(&bundle, POWER_UPGRADE_2, 100.0, 100.0).expect("create power upgrade 2");
    scene.dispatch(&bundle, pu2, 6, 0).expect("click power upgrade 2");
    assert_eq!(
        scene.score,
        22000.0,
        "score deducted 25000 for power upgrade 2"
    );
    assert_eq!(scene.globals.get("pwr").copied(), Some(3.0), "pwr upgraded to 3");
    assert_eq!(scene.globals.get("powerupgrade2bought").copied(), Some(1.0));

    // 3. Buy Max HP Upgrade (cost 10,000)
    let hp = scene.create(&bundle, MAX_HP_UPGRADE, 100.0, 100.0).expect("create max hp upgrade");
    scene.dispatch(&bundle, hp, 6, 0).expect("click max hp upgrade");
    assert_eq!(
        scene.score,
        12000.0,
        "score deducted 10000 for max hp upgrade"
    );
    assert_eq!(scene.globals.get("level").copied(), Some(2.0), "level incremented");
    assert_eq!(scene.globals.get("maxhpupgradebought").copied(), Some(1.0));
}
