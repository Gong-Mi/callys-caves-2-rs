use callys_asset::GameDroidAsset;
use callys_core::{EnemyType, GameWorld, InputState, WeaponType};
use std::path::Path;

#[test]
fn rm_boss1_spawns_trex_and_death_removes_bossboulder() {
    let asset_path = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(asset_path).expect("parse game.droid");

    let boss1_index = asset
        .rooms
        .iter()
        .position(|r| r.name == "rm_boss1")
        .expect("rm_boss1 room exists");

    let mut world = GameWorld::new();
    world.load_room(
        boss1_index,
        &asset.rooms[boss1_index],
        &asset.objects,
        &asset.sprites,
        &asset.warp_targets,
    );

    // Verify boss1 boulder blocks initially
    assert!(world.solids.iter().any(|s| s.is_bossboulder));
    assert!(!world.boss1_dead);

    // Verify Trex is materialized as Boss enemy
    let trex = world.enemies.iter().find(|e| e.enemy_type == EnemyType::Boss);
    assert!(trex.is_some(), "Trex boss must be materialized in rm_boss1");
    let initial_hp = trex.unwrap().health;
    assert!(initial_hp > 0);

    // Equip pistol and fire at Trex
    world.player.current_weapon = WeaponType::Pistol;
    world.player.attack_cooldown = 0.0;
    let attack_input = InputState {
        attack: true,
        ..Default::default()
    };
    world.update(0.016, &attack_input);
    assert!(!world.projectiles.is_empty(), "Player must have fired a projectile");

    // Let the projectile travel and hit the boss
    for _ in 0..10 {
        world.update(0.016, &InputState::default());
    }

    // Now inflict lethal damage to simulate completing boss fight
    for enemy in &mut world.enemies {
        if enemy.enemy_type == EnemyType::Boss {
            enemy.health = 0;
        }
    }

    // Update world to process boss death
    world.update(0.016, &InputState::default());

    // Boss1 must be registered dead, and bossboulder must be removed
    assert!(world.boss1_dead, "boss1_dead flag must be set upon boss death");
    assert!(
        !world.solids.iter().any(|s| s.is_bossboulder),
        "All bossboulders must be removed upon boss death"
    );
}
