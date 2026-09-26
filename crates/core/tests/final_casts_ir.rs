//! Cast tables for the final overworld stretch: room87-103 and challenge1-5,
//! loaded through the real room loader in FRESH scenes (the earlier probe
//! walked the portal chain and the persistent obj_UI accumulated across
//! rooms — probe-proven; fresh scenes pin each room's true cast). Boss4's
//! rest/chase/movelock relay is asserted through direct alarm dispatches.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const BOSS4: i32 = 28;
const MUSIC: i32 = 68;
const KNIFE: i32 = 15;
const SHOOTER1: i32 = 16;
const SKELETON: i32 = 17;
const FIREHULK: i32 = 18;
const ZOMBIE: i32 = 19;
const SHOOTER2: i32 = 20;
const HULKING: i32 = 21;
const ENEMY2: i32 = 22;
const ENEMY: i32 = 14;
const WOLF: i32 = 23;
const GHOST: i32 = 24;
const SLIME: i32 = 32;
const FIRESLIME: i32 = 33;
const BAT: i32 = 31;
const COIN: i32 = 58;
const GEM: i32 = 59;
const CHEST: i32 = 100;
const BOULDERBLOCK: i32 = 156;
const LLOYD: i32 = 154;
const ICEBLOCK: i32 = 159;
const FINALCHEST: i32 = 101;
const WALL: i32 = 4;
const WALL2: i32 = 5;
const BOULDER: i32 = 6;
const PLATFORM: i32 = 7;
const SPIKES: i32 = 8;
const WATER: i32 = 9;
const WATERFILL: i32 = 10;

fn fresh(bundle: &callys_core::code_vm::Bundle, asset: &GameDroidAsset, room: usize) -> Scene {
    let mut s = Scene::default();
    s.init_bundle(bundle);
    s.init_fresh_start_globals();
    for (sid, sprite) in &asset.sprites {
        s.sprite_bounds.insert(*sid as i32, SpriteBounds {
            width: sprite.width as f64,
            height: sprite.height as f64,
            origin_x: sprite.origin_x as f64,
            origin_y: sprite.origin_y as f64,
            frames: sprite.tpag_indices.len().max(1) as f64,
        });
    }
    s.load_room_from_data(bundle, room, &asset.rooms[room]).unwrap();
    s
}

fn assert_cast(scene: &Scene, room: &str, table: &[(i32, usize)]) {
    let mut m = std::collections::BTreeMap::new();
    for i in scene.instances.values().filter(|i| i.alive) {
        *m.entry(i.object).or_insert(0usize) += 1;
    }
    for &(obj, want) in table {
        assert_eq!(m.get(&obj).copied().unwrap_or(0), want, "{room}: obj {obj}");
    }
    // The shared chassis: every room in this stretch carries one each of the
    // UI/resolution/button set and two warp doors (challenge5 has one door
    // plus the final chest).
    for &obj in &[65, 66, 67, 125, 126, 127, 128, 129, 130, 131, 133] {
        assert_eq!(m.get(&obj).copied().unwrap_or(0), 1, "{room}: chassis obj {obj}");
    }
    let doors = m.get(&69).copied().unwrap_or(0);
    assert!(doors == 2 || (room == "challenge5" && doors == 1),
        "{room}: two warp doors (challenge5 carries one)");
}

#[test]
fn final_casts_are_asset_exact() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();

    let s = fresh(&bundle, &asset, 87);
    assert_cast(&s, "room87", &[(4,142), (5,138), (6,70), (8,46), (58,15), (24,5), (59,4)]);

    let s = fresh(&bundle, &asset, 88);
    assert_cast(&s, "room88", &[(5,178), (4,110), (6,108), (58,22), (24,3), (21,2), (16,1), (17,1), (18,1), (31,1)]);

    let s = fresh(&bundle, &asset, 89);
    assert_cast(&s, "room89", &[(5,175), (4,124), (6,108), (19,17), (58,12), (68,1)]);

    let s = fresh(&bundle, &asset, 90);
    assert_cast(&s, "room90", &[(4,234), (6,142), (5,107), (58,23), (9,20), (7,10), (19,3), (100,3), (18,2), (21,2), (22,2), (10,1), (15,1), (17,1), (23,1), (24,1)]);

    let s = fresh(&bundle, &asset, 91);
    assert_cast(&s, "room91", &[(4,126), (6,62), (5,35), (58,20), (14,11)]);

    let s = fresh(&bundle, &asset, 92);
    assert_cast(&s, "room92", &[(5,262), (6,180), (4,140), (58,18), (33,4), (22,3), (24,3), (100,2), (15,1), (20,1)]);

    let s = fresh(&bundle, &asset, 93);
    assert_cast(&s, "room93", &[(4,137), (5,135), (6,114), (58,35), (8,26), (9,15), (10,4), (17,3), (24,3), (15,1), (21,1), (23,1)]);

    let s = fresh(&bundle, &asset, 94);
    assert_cast(&s, "room94", &[(4,101), (9,64), (6,26), (58,16), (7,7), (21,4), (10,1)]);

    let s = fresh(&bundle, &asset, 95);
    assert_cast(&s, "room95", &[(5,330), (4,250), (6,197), (58,24), (100,5), (24,4), (17,3), (159,3), (18,2), (19,2), (33,2), (21,1), (31,1)]);

    let s = fresh(&bundle, &asset, 96);
    assert_cast(&s, "room96", &[(4,114), (6,79), (5,55), (9,38), (58,28), (8,12), (17,4), (100,3), (7,1), (10,1), (22,1), (31,1)]);

    let s = fresh(&bundle, &asset, 97);
    assert_cast(&s, "room97", &[(6,125), (4,91), (5,62), (58,36), (16,14)]);

    let s = fresh(&bundle, &asset, 98);
    assert_cast(&s, "room98", &[(6,195), (5,171), (4,25), (7,24), (58,11), (31,7), (59,7)]);

    let s = fresh(&bundle, &asset, 99);
    assert_cast(&s, "room99", &[(5,119), (4,112), (6,81), (8,14), (9,11), (58,4), (18,3), (100,3), (10,2), (19,2), (156,2), (159,2)]);

    let s = fresh(&bundle, &asset, 100);
    assert_cast(&s, "room100", &[(5,109), (6,84), (4,54), (24,8), (9,6), (10,3)]);

    let s = fresh(&bundle, &asset, 101);
    assert_cast(&s, "room101", &[(5,174), (4,119), (6,82), (7,10), (58,6), (9,5), (18,4), (100,2), (159,2), (10,1), (33,1)]);

    let s = fresh(&bundle, &asset, 102);
    assert_cast(&s, "room102", &[(6,112), (4,78), (5,44), (58,23), (7,12), (24,4), (21,2), (59,2), (20,1), (23,1), (31,1), (100,1)]);

    let s = fresh(&bundle, &asset, 103);
    assert_cast(&s, "room103", &[(5,194), (4,119), (6,117), (31,3), (58,3), (100,3), (19,2), (16,1), (17,1), (18,1), (20,1), (21,1), (22,1), (154,1)]);

    let s = fresh(&bundle, &asset, 105);
    assert_cast(&s, "challenge1", &[(5,393), (4,248), (6,124), (9,12), (31,4), (10,3), (21,3), (33,3), (23,2), (24,1), (154,1)]);

    let s = fresh(&bundle, &asset, 106);
    assert_cast(&s, "challenge2", &[(5,461), (4,124), (6,64), (19,6), (22,4), (31,3), (33,3), (24,2), (32,1)]);

    let s = fresh(&bundle, &asset, 107);
    assert_cast(&s, "challenge3", &[(5,355), (6,204), (4,192), (24,4), (32,4), (59,4), (22,3), (21,2), (31,2), (33,2), (17,1)]);

    let s = fresh(&bundle, &asset, 108);
    assert_cast(&s, "challenge4", &[(4,290), (6,240), (5,234), (9,65), (8,34), (31,11), (10,6), (33,5), (24,3), (32,3), (18,2)]);

    let s = fresh(&bundle, &asset, 109);
    assert_cast(&s, "challenge5", &[(5,498), (4,234), (6,57), (100,13), (24,4), (17,3), (59,3), (21,2), (31,2), (101,1)]);

}

#[test]
fn boss4_rests_and_resumes_his_chase_through_the_alarm_relay() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR"));
    let asset = GameDroidAsset::parse(root.join("../../assets/game.droid")).unwrap();
    let mut bundle = load_bundle_from_file(&root.join("src/generated/full_ir.json")).unwrap();
    bundle.string_table = asset.string_table.clone();
    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
    let bs = s.create(&bundle, BOSS4, 300.0, 200.0).unwrap();
    // The rest/chase relay: A4 (192) drops chasing + arms the 30-tick rest (a6);
    // A6 (190) resumes chasing + re-arms the 60-tick resync (a4). A3 (193)
    // locks the walk direction; A5 (191) clears swordstunned.
    s.instances.get_mut(&bs).unwrap().fields.insert("chasing".into(), 1.0);
    s.dispatch(&bundle, bs, 2, 4).expect("A4 rest");
    assert_eq!(s.instances[&bs].fields["chasing"], 0.0, "A4 (CODE 192) drops the chase");
    assert_eq!(s.instances[&bs].alarms[6], 30, "A4 arms the 30-tick rest");
    s.dispatch(&bundle, bs, 2, 6).expect("A6 resume");
    assert_eq!(s.instances[&bs].fields["chasing"], 1.0, "A6 (CODE 190) resumes the chase");
    assert_eq!(s.instances[&bs].alarms[4], 60, "A6 re-arms the 60-tick resync");
    s.dispatch(&bundle, bs, 2, 3).expect("A3 movelock");
    assert_eq!(s.instances[&bs].fields["movelock"], 1.0, "A3 (CODE 193) sets movelock");
    s.instances.get_mut(&bs).unwrap().fields.insert("swordstunned".into(), 1.0);
    s.dispatch(&bundle, bs, 2, 5).expect("A5 recovery");
    assert_eq!(s.instances[&bs].fields["swordstunned"], 0.0, "A5 (CODE 191) clears swordstunned");
}
