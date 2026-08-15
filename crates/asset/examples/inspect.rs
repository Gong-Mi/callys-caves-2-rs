use callys_asset::GameDroidAsset;
use std::collections::BTreeMap;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let path = std::env::args().nth(1).unwrap_or_else(|| "assets/game.droid".into());
    let asset = GameDroidAsset::parse(&path)?;
    println!("game={} rooms={} objects={} sprites={} tpag={}", asset.game_name, asset.rooms.len(), asset.objects.len(), asset.sprites.len(), asset.tpag_items.len());
    for (ri, room) in asset.rooms.iter().enumerate() {
        let mut names: BTreeMap<&str, usize> = BTreeMap::new();
        for inst in &room.objects {
            let name = asset.objects.get(inst.object_id.max(0) as usize).map(|o| o.name.as_str()).unwrap_or("<invalid>");
            *names.entry(name).or_default() += 1;
        }
        println!("room[{ri}] {} {}x{} objects={} tiles={} {:?}", room.name, room.width, room.height, room.objects.len(), room.tiles.len(), names);
    }
    println!("-- relevant objects --");
    for obj in &asset.objects {
        if matches!(obj.name.as_str(), "obj_player" | "obj_wall" | "obj_wall_2" | "obj_boulder" | "obj_gem" | "obj_coin" | "obj_silvercoin" | "obj_warpanywhere") || obj.name.contains("slime") || obj.name.contains("zombie") || obj.name.contains("bandit") || obj.name.contains("boss") {
            let sprite = obj.sprite_id.try_into().ok().and_then(|id: usize| asset.sprites.get(&id)).map(|s| s.name.as_str()).unwrap_or("<none>");
            println!("obj[{}] {} sprite={} ({}) parent={} solid={}", obj.id, obj.name, obj.sprite_id, sprite, obj.parent_id, obj.solid);
        }
    }
    Ok(())
}
