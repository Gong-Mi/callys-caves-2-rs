use callys_asset::{GameDroidAsset, ObjectEvent, WarpAuditStatus};
use std::collections::BTreeMap;

fn event_type_name(event_type: u32) -> &'static str {
    match event_type {
        0 => "Create",
        1 => "Destroy",
        2 => "Alarm",
        3 => "Step",
        4 => "Collision",
        5 => "Keyboard",
        6 => "Mouse",
        7 => "Other",
        8 => "Draw",
        9 => "KeyPress",
        10 => "KeyRelease",
        11 => "Trigger",
        12 => "CleanUp",
        _ => "Unknown",
    }
}

fn print_direct_events(asset: &GameDroidAsset, object_name: &str, events: &[ObjectEvent]) {
    if events.is_empty() {
        println!("  direct_events=(none)");
        return;
    }
    for event in events {
        let subtype_resource = if event.event_type == 4 {
            usize::try_from(event.subtype)
                .ok()
                .and_then(|id| asset.objects.get(id))
                .map(|object| object.name.as_str())
        } else {
            None
        };
        println!(
            "  direct_event object={} type={} ({}) subtype={}{} actions={}",
            object_name,
            event.event_type,
            event_type_name(event.event_type),
            event.subtype,
            subtype_resource
                .map(|name| format!(" resource={name}"))
                .unwrap_or_default(),
            event.actions.len()
        );
        for action in &event.actions {
            println!(
                "    action[{}] code_id={} code={} library={} action_id={} kind={} execution_type={} arguments={} who={} raw(use_relative={},question={},apply_to={},relative={},not={},unknown={}) function={:?}",
                action.order,
                action.code_id,
                action.code_name.as_deref().unwrap_or("<none>"),
                action.library_id,
                action.action_id,
                action.kind,
                action.execution_type,
                action.argument_count,
                action.who,
                action.use_relative_raw,
                action.is_question_raw,
                action.use_apply_to_raw,
                action.relative_raw,
                action.is_not_raw,
                action.unknown_raw,
                action.function_name,
            );
        }
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let path = std::env::args().nth(1).unwrap_or_else(|| "assets/game.droid".into());
    let asset = GameDroidAsset::parse(&path)?;
    println!(
        "game={} rooms={} objects={} sprites={} tpag={} audio={} sounds={}",
        asset.game_name,
        asset.rooms.len(),
        asset.objects.len(),
        asset.sprites.len(),
        asset.tpag_items.len(),
        asset.audio.len(),
        asset.sounds.len()
    );
    for audio in &asset.audio {
        println!(
            "audio[{}] offset=0x{:x} wav_bytes={}",
            audio.id,
            audio.file_offset,
            audio.wav_bytes.len()
        );
    }
    for sound in &asset.sounds {
        println!(
            "sound[{}] name={} audio_id={}",
            sound.id,
            sound.name,
            sound.audio_id
        );
    }
    for (ri, room) in asset.rooms.iter().enumerate() {
        let mut names: BTreeMap<&str, usize> = BTreeMap::new();
        for inst in &room.objects {
            let name = asset.objects.get(inst.object_id.max(0) as usize).map(|o| o.name.as_str()).unwrap_or("<invalid>");
            *names.entry(name).or_default() += 1;
        }
        println!("room[{ri}] {} {}x{} objects={} tiles={} {:?}", room.name, room.width, room.height, room.objects.len(), room.tiles.len(), names);
        if ri <= 1 {
            for (ii, inst) in room.objects.iter().enumerate() {
                let name = asset.objects.get(inst.object_id.max(0) as usize).map(|o| o.name.as_str()).unwrap_or("<invalid>");
                if name == "obj_warpanywhere" || name == "obj_player" || name == "obj_lloyd" || name == "obj_enemy" || name == "obj_knifebandit" || name == "obj_waterfill" || name == "obj_watersurface" || name == "obj_shotgun" {
                    println!("  inst[{ii}] {name} x={} y={} scale=({}, {}) creation_code={}", inst.x, inst.y, inst.scale_x, inst.scale_y, inst.creation_code_id);
                }
            }
        }
    }

    println!("-- warp graph --");
    let mut decoded = 0usize;
    let mut special = 0usize;
    let mut unresolved = 0usize;
    for audit in &asset.warp_audits {
        match &audit.status {
            WarpAuditStatus::Decoded(target) => {
                decoded += 1;
                let target_name = &asset.rooms[target.room_index].name;
                println!(
                    "warp source_room[{}]={} instance_id={} creation_code={} ({}) -> target_room[{}]={} spawn=({}, {}) unlocked={}",
                    audit.source_room_index,
                    audit.source_room_name,
                    audit.instance_id,
                    audit.creation_code_id,
                    audit.creation_code_name,
                    target.room_index,
                    target_name,
                    target.x,
                    target.y,
                    target.unlocked
                );
            }
            WarpAuditStatus::SpecialDynamic { .. } => special += 1,
            WarpAuditStatus::Unresolved { .. } => unresolved += 1,
        }
    }
    println!("-- special/dynamic warps --");
    if special == 0 {
        println!("(none)");
    } else {
        for audit in &asset.warp_audits {
            if let WarpAuditStatus::SpecialDynamic { reason } = &audit.status {
                println!(
                    "special source_room[{}]={} instance_id={} creation_code={} ({}) reason={}",
                    audit.source_room_index,
                    audit.source_room_name,
                    audit.instance_id,
                    audit.creation_code_id,
                    audit.creation_code_name,
                    reason
                );
            }
        }
    }
    println!("-- unresolved warps --");
    if unresolved == 0 {
        println!("(none)");
    } else {
        for audit in &asset.warp_audits {
            if let WarpAuditStatus::Unresolved { reason } = &audit.status {
                println!(
                    "unresolved source_room[{}]={} instance_id={} creation_code={} ({}) reason={}",
                    audit.source_room_index,
                    audit.source_room_name,
                    audit.instance_id,
                    audit.creation_code_id,
                    audit.creation_code_name,
                    reason
                );
            }
        }
    }
    println!(
        "warp summary total={} decoded={} special_dynamic={} unresolved={}",
        asset.warp_audits.len(), decoded, special, unresolved
    );

    println!("-- direct OBJT events and potential parent inheritance --");
    for target_name in ["obj_enemy", "obj_enemy2", "obj_knifebandit"] {
        let Some(object) = asset.objects.iter().find(|object| object.name == target_name) else {
            println!("obj <missing> name={target_name}");
            continue;
        };
        let parent = usize::try_from(object.parent_id)
            .ok()
            .and_then(|id| asset.objects.get(id));
        println!(
            "obj[{}] {} parent={} ({}) direct_events={}",
            object.id,
            object.name,
            object.parent_id,
            parent.map(|object| object.name.as_str()).unwrap_or("<none>"),
            object.events.len(),
        );
        print_direct_events(&asset, &object.name, &object.events);
        if let Some(parent) = parent {
            println!(
                "  potential_inherited_from obj[{}] {} direct_events={} (not copied into child direct events)",
                parent.id,
                parent.name,
                parent.events.len(),
            );
            print_direct_events(&asset, &parent.name, &parent.events);
        }
    }

    println!("-- relevant objects --");
    for obj in &asset.objects {
        if matches!(obj.name.as_str(), "obj_player" | "obj_wall" | "obj_wall_2" | "obj_boulder" | "obj_gem" | "obj_coin" | "obj_silvercoin" | "obj_warpanywhere" | "obj_enemy" | "obj_enemy2" | "obj_waterfill" | "obj_watersurface" | "obj_spikes" | "obj_shotgun") || obj.name.contains("slime") || obj.name.contains("zombie") || obj.name.contains("bandit") || obj.name.contains("boss") {
            let sprite = obj.sprite_id.try_into().ok().and_then(|id: usize| asset.sprites.get(&id)).map(|s| s.name.as_str()).unwrap_or("<none>");
            println!("obj[{}] {} sprite={} ({}) parent={} solid={}", obj.id, obj.name, obj.sprite_id, sprite, obj.parent_id, obj.solid);
        }
    }
    Ok(())
}
