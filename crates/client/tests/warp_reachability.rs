use std::collections::{BTreeSet, VecDeque};
use std::path::{Path, PathBuf};

use callys_asset::WarpAuditStatus;
use callys_client::GameState;
use callys_core::{Facing, PlayerState};

const EXPECTED_ROOM_COUNT: usize = 114;
const EXPECTED_WARP_EDGE_COUNT: usize = 218;

fn game_droid_path() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid")
}

fn directed_reachable(adjacency: &[BTreeSet<usize>], start: usize) -> Vec<usize> {
    let mut visited = vec![false; adjacency.len()];
    let mut queue = VecDeque::from([start]);
    visited[start] = true;
    let mut order = Vec::new();

    while let Some(room) = queue.pop_front() {
        order.push(room);
        for &target in &adjacency[room] {
            if !visited[target] {
                visited[target] = true;
                queue.push_back(target);
            }
        }
    }
    order
}

fn weakly_connected_components(adjacency: &[BTreeSet<usize>]) -> Vec<Vec<usize>> {
    let mut undirected = adjacency.to_vec();
    for (source, targets) in adjacency.iter().enumerate() {
        for &target in targets {
            undirected[target].insert(source);
        }
    }

    let mut visited = vec![false; adjacency.len()];
    let mut components = Vec::new();
    for start in 0..adjacency.len() {
        if visited[start] {
            continue;
        }
        visited[start] = true;
        let mut queue = VecDeque::from([start]);
        let mut component = Vec::new();
        while let Some(room) = queue.pop_front() {
            component.push(room);
            for &neighbor in &undirected[room] {
                if !visited[neighbor] {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                }
            }
        }
        component.sort_unstable();
        components.push(component);
    }
    components
}

fn room_labels(state: &GameState, rooms: &[usize]) -> Vec<String> {
    rooms
        .iter()
        .map(|&room| format!("{room}:{}", state.asset.rooms[room].name))
        .collect()
}

#[test]
fn real_warp_graph_reports_deterministic_town_reachability() {
    let state = GameState::new(&game_droid_path()).expect("load shipped game.droid");
    assert_eq!(state.asset.rooms.len(), EXPECTED_ROOM_COUNT);
    assert_eq!(state.asset.warp_audits.len(), EXPECTED_WARP_EDGE_COUNT);

    let mut adjacency = vec![BTreeSet::new(); state.asset.rooms.len()];
    for audit in &state.asset.warp_audits {
        let WarpAuditStatus::Decoded(target) = audit.status else {
            panic!(
                "warp {} in {} is not statically decoded: {:?}",
                audit.creation_code_id, audit.source_room_name, audit.status
            );
        };
        adjacency[audit.source_room_index].insert(target.room_index);
    }

    let reachable = directed_reachable(&adjacency, 0);
    let reachable_set: BTreeSet<_> = reachable.iter().copied().collect();
    let unreachable: Vec<_> = (0..state.asset.rooms.len())
        .filter(|room| !reachable_set.contains(room))
        .collect();
    let components = weakly_connected_components(&adjacency);

    eprintln!(
        "warp graph: rooms={} edges={} town_reachable={} town_unreachable={} weak_components={}",
        state.asset.rooms.len(),
        state.asset.warp_audits.len(),
        reachable.len(),
        unreachable.len(),
        components.len()
    );
    eprintln!("town BFS reachable: {}", room_labels(&state, &reachable).join(", "));
    eprintln!(
        "town unreachable (structural fact, not automatically a gameplay bug): {}",
        room_labels(&state, &unreachable).join(", ")
    );
    for (index, component) in components.iter().enumerate() {
        eprintln!(
            "weak component {index} ({} rooms): {}",
            component.len(),
            room_labels(&state, component).join(", ")
        );
    }

    assert_eq!(reachable_set, (0..=104).collect());
    assert_eq!(
        unreachable,
        vec![105, 106, 107, 108, 109, 110, 111, 112, 113]
    );
    assert_eq!(
        components,
        vec![
            (0..=109).collect(),
            vec![110],
            vec![111],
            vec![112],
            vec![113],
        ]
    );
}

// This is structural loader/reference acceptance only. It deliberately does not
// claim that every room is reachable through normal play or fully playable.
#[test]
fn every_room_passes_structural_product_loader_and_resource_validation() {
    let mut state = GameState::new(&game_droid_path()).expect("load shipped game.droid");
    assert_eq!(state.asset.rooms.len(), EXPECTED_ROOM_COUNT);

    for (room_index, room) in state.asset.rooms.iter().enumerate() {
        for instance in &room.objects {
            let object = usize::try_from(instance.object_id)
                .ok()
                .and_then(|object_id| state.asset.objects.get(object_id))
                .unwrap_or_else(|| {
                    panic!(
                        "room[{room_index}] {} instance {} references invalid object {}",
                        room.name, instance.instance_id, instance.object_id
                    )
                });
            if let Ok(sprite_id) = usize::try_from(object.sprite_id) {
                let sprite = state.asset.sprites.get(&sprite_id).unwrap_or_else(|| {
                    panic!(
                        "room[{room_index}] {} object {} references missing sprite {sprite_id}",
                        room.name, object.name
                    )
                });
                for frame_pointer in &sprite.tpag_indices {
                    let frame = state
                        .asset
                        .tpag_items
                        .get(&(*frame_pointer as usize))
                        .unwrap_or_else(|| {
                            panic!(
                                "room[{room_index}] {} sprite {} references missing TPAG {frame_pointer}",
                                room.name, sprite.name
                            )
                        });
                    assert!(
                        usize::from(frame.tex_id) < state.atlases.len(),
                        "room[{room_index}] {} sprite {} TPAG {frame_pointer} references texture {} but only {} atlases loaded",
                        room.name,
                        sprite.name,
                        frame.tex_id,
                        state.atlases.len()
                    );
                }
            }
        }

        state.world.load_room(
            room_index,
            room,
            &state.asset.objects,
            &state.asset.warp_targets,
        );
        assert_eq!(state.world.current_room_index, room_index);
        assert_eq!(state.world.current_room_name, room.name);
    }
}

#[test]
fn every_real_warp_instance_loads_its_decoded_target_and_checkpoint() {
    let mut state = GameState::new(&game_droid_path()).expect("load shipped game.droid");
    assert_eq!(state.asset.warp_audits.len(), EXPECTED_WARP_EDGE_COUNT);

    for edge_index in 0..state.asset.warp_audits.len() {
        let audit = state.asset.warp_audits[edge_index].clone();
        let WarpAuditStatus::Decoded(target) = audit.status else {
            panic!(
                "warp {} in {} is not statically decoded: {:?}",
                audit.creation_code_id, audit.source_room_name, audit.status
            );
        };
        let source_room = &state.asset.rooms[audit.source_room_index];
        let source_instance = source_room
            .objects
            .iter()
            .find(|instance| {
                instance.instance_id == audit.instance_id
                    && instance.creation_code_id == audit.creation_code_id
            })
            .unwrap_or_else(|| {
                panic!(
                    "edge {edge_index} source {} lacks audited instance {} / creation code {}",
                    source_room.name, audit.instance_id, audit.creation_code_id
                )
            });

        state.world.load_room(
            audit.source_room_index,
            source_room,
            &state.asset.objects,
            &state.asset.warp_targets,
        );
        assert_eq!(state.world.current_room_index, audit.source_room_index);
        assert_eq!(state.world.current_room_name, audit.source_room_name);

        let matching_warps: Vec<_> = state
            .world
            .warps
            .iter()
            .filter(|warp| warp.creation_code == audit.creation_code_id)
            .cloned()
            .collect();
        assert_eq!(
            matching_warps.len(),
            1,
            "edge {edge_index} must materialize exactly one real warp {} in {}",
            audit.creation_code_id,
            audit.source_room_name
        );
        let warp = &matching_warps[0];
        assert_eq!(warp.rect.x, source_instance.x as f32);
        assert_eq!(warp.rect.y, source_instance.y as f32);
        assert_eq!(warp.target_room, target.room_index);
        assert_eq!((warp.target_x, warp.target_y), (target.x as f32, target.y as f32));

        // Isolate the warp event from unrelated source-room combat/collision while
        // preserving the product-loaded, audited WarpPoint instance itself.
        state.world.solids.clear();
        state.world.platforms.clear();
        state.world.enemies.clear();
        state.world.hazards.clear();
        state.world.player.health = state.world.player.max_health;
        state.world.player.state = PlayerState::Falling;
        state.world.player.invulnerable_timer = 1.0;
        state.world.player.vx = 0.0;
        state.world.player.vy = 0.0;
        state.world.player.facing = Facing::Left;
        state.world.player.x = warp.rect.x;
        state.world.player.y = warp.rect.y;

        let visits_before = state.rooms_visited;
        state.step(0.0);

        assert_eq!(
            state.world.current_room_index, target.room_index,
            "edge {edge_index} warp {} loaded the wrong target",
            audit.creation_code_id
        );
        assert_eq!(state.world.current_room_name, state.asset.rooms[target.room_index].name);
        assert_eq!(
            (state.world.player.x, state.world.player.y),
            (target.x as f32, target.y as f32),
            "edge {edge_index} warp {} used the wrong spawn",
            audit.creation_code_id
        );
        assert_eq!(state.world.player.facing, Facing::Left);
        assert_eq!(state.world.checkpoint.room_index, target.room_index);
        assert_eq!(
            (state.world.checkpoint.x, state.world.checkpoint.y),
            (target.x as f32, target.y as f32)
        );
        assert_eq!(state.rooms_visited, visits_before + 1);
        assert_eq!(state.world.pending_room_warp, None);
        assert_eq!(state.world.pending_spawn, None);
    }
}
