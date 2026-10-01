//! The Mines' first blob mould: obj_slime (32) in rm_level11a (room 15) and
//! later Mines rooms. Distinct from every previous enemy: it walks at
//! choose(-3, 3), bounces off walls through both the Step probe (which flips
//! hspeed to -/+2) and its own Collision 34 (action_bounce), and hops on two
//! independent clocks - CODE 252's 60-tick heartbeat (vspeed = -5, only
//! observable when the blob cannot see the player) and CODE 253's pounce, which
//! fires when `!collision_line(player.x, player.y, x, y, par_wall, false, false)`
//! reports a CLEAR path: a blob that can see the player leaps at it for -8,
//! overwriting the heartbeat in the same tick. CODE 250 sprays a death
//! table that drops health twice (y - 35 and y - 20, two separate hpdrop == 1
//! blocks) plus its own coin tier 3/5/9/10/11, and CODE 245 counts
//! global.greenslimeskilled.
use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Host};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const WALL: i32 = 4;
const BOULDER: i32 = 6;
const PAR_WALL: i32 = 34;
const WARP: i32 = 69;
const SLIME: i32 = 32;
const GEM: i32 = 59;
const COIN: i32 = 60;
const XPORB: i32 = 61;
const HEALTH: i32 = 62;
const SMALLPUFF: i32 = 187;
/// CODE 253's sprite constants.
const SPR_BLOBIDLE: f64 = 68.0;
const SPR_BLOBJUMP: f64 = 73.0;
const C_GREEN: i32 = 32768;
/// SOND id from reconstruction/contracts/audio-sond.json.
const SND_EXPLODE: i32 = 7;
const ENEMIES: [i32; 7] = [14, 15, 16, 20, 23, 31, 32];

fn load_scene() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let manifest_dir = env!("CARGO_MANIFEST_DIR");
    let asset_path = Path::new(manifest_dir).join("../../assets/game.droid");
    let asset = GameDroidAsset::parse(&asset_path).expect("parse game.droid");
    let bundle_path = Path::new(manifest_dir).join("src/generated/full_ir.json");
    let mut bundle = load_bundle_from_file(&bundle_path).expect("load full_ir.json");
    bundle.string_table = asset.string_table.clone();

    let mut s = Scene::default();
    s.init_bundle(&bundle);
    s.init_fresh_start_globals();
    for (sid, sp) in &asset.sprites {
        s.sprite_bounds.insert(
            *sid as i32,
            SpriteBounds {
                width: sp.width as f64,
                height: sp.height as f64,
                origin_x: sp.origin_x as f64,
                origin_y: sp.origin_y as f64,
                frames: sp.tpag_indices.len().max(1) as f64,
            },
        );
    }
    s.load_room_from_data(&bundle, 0, &asset.rooms[0]).expect("load rm_town");
    s.transition_to_room(&bundle, 1, &asset.rooms[1]).expect("town -> level1");
    s.view_positions.insert(0, (0.0, 0.0));
    let player = s.instances.iter()
        .find(|(_, i)| i.object == PLAYER && i.alive)
        .map(|(id, _)| *id)
        .expect("persistent player");
    (bundle, s, player, asset)
}

fn walk_portal(bundle: &callys_core::code_vm::Bundle, s: &mut Scene, asset: &GameDroidAsset, player: i32, want_room: f64) {
    let portal = s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive && i.active)
        .find(|(_, i)| i.fields.get("warproom").copied() == Some(want_room))
        .map(|(id, _)| *id)
        .expect("portal instance with pinned warproom");
    let (px, py) = (s.instances[&portal].fields["x"], s.instances[&portal].fields["y"]);
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    for _ in 0..3 {
        s.tick(bundle).unwrap();
        if s.target_room_warp.is_some() { break; }
    }
    let target = s.target_room_warp.take().expect("CODE 13 warp");
    s.transition_to_room(bundle, target, &asset.rooms[target]).expect("portal transition");
}

fn cast(s: &Scene, object: i32) -> Vec<i32> {
    s.instances.iter()
        .filter(|(_, i)| i.object == object && i.alive)
        .map(|(id, _)| *id)
        .collect()
}

fn one(s: &Scene, object: i32) -> i32 {
    *cast(s, object).first().unwrap_or_else(|| panic!("no live object {object}"))
}

fn doors(s: &Scene) -> Vec<(f64, f64, f64)> {
    s.instances.iter()
        .filter(|(_, i)| i.object == WARP && i.alive)
        .map(|(_, i)| (i.fields["warproom"], i.fields["warpx"], i.fields["warpy"]))
        .collect()
}

/// rm_town -> ... -> rm_level11 (14) -> rm_level11a (15).
fn slime_room() -> (callys_core::code_vm::Bundle, Scene, i32, GameDroidAsset) {
    let (bundle, mut s, player, asset) = load_scene();
    s.transition_to_room(&bundle, 4, &asset.rooms[4]).expect("level1 -> level4");
    for want in [5.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0] {
        walk_portal(&bundle, &mut s, &asset, player, want);
    }
    (bundle, s, player, asset)
}

/// Quarantine every other enemy, then find a spot where the blob is genuinely
/// standing on the room's own tiles with open air above: CODE 253 probes
/// `(x, y + 1)` to decide it is grounded and `(x, y - 3)` to zero any upward
/// launch, so both must be true of the fixture. The spot is searched over a
/// grid (the room's geometry is not otherwise known to the test) and asserted
/// through the same two builtins the original uses. Returns the spot.
fn grounded_blob(s: &mut Scene, bundle: &callys_core::code_vm::Bundle, player: i32, blob: i32) -> (f64, f64) {
    let others: Vec<i32> = s.instances.iter()
        .filter(|(id, i)| i.alive && i.active && **id != blob && ENEMIES.contains(&i.object))
        .map(|(id, _)| *id)
        .collect();
    for id in others {
        s.write(id, -1, "x", None, 8000.0).unwrap();
        s.write(id, -1, "y", None, 8000.0).unwrap();
    }
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
    s.write(blob, -1, "hpslime", None, 50.0).unwrap();

    // The blob stands wherever the room put it; what the fixture must fix is the
    // ROOF. CODE 253 zeroes any upward launch when a par_wall reaches (x, y - 3),
    // and a tile drawn behind/above the blob does exactly that - so clear the
    // tiles that roof this one spot, then assert both probes the original uses.
    let sx = s.read(blob, -1, "x", None).unwrap();
    let sy = s.read(blob, -1, "y", None).unwrap();
    // The blob swaps to a different sprite for its jump/launch poses, so the
    // clearance band covers every height the two probes and the launches can
    // reach with either box.
    s.write(blob, -1, "sprite_index", None, SPR_BLOBJUMP).unwrap();
    for _ in 0..40 {
        let mut cleared = false;
        for offset in [-3.0, -5.0, -8.0, -12.0, -16.0, -20.0, -24.0, -28.0, -32.0] {
            let roof = s.call(bundle, blob, "instance_place", &[sx, sy + offset, PAR_WALL as f64]).unwrap();
            if roof >= 0.0 {
                s.destroy(bundle, roof as i32).expect("clear the roof tile");
                cleared = true;
                break;
            }
        }
        if !cleared { break; }
    }
    let grounded = s.call(bundle, blob, "place_meeting", &[sx, sy + 1.0, PAR_WALL as f64]).unwrap();
    let roofed = s.call(bundle, blob, "instance_place", &[sx, sy - 3.0, PAR_WALL as f64]).unwrap();
    assert_eq!(grounded, 1.0, "fixture: the blob stands on par_wall at its room spot");
    assert!(roofed < 0.0, "fixture: nothing roofs the blob at (x, y - 3)");
    s.write(blob, -1, "x", None, sx).unwrap();
    s.write(blob, -1, "y", None, sy).unwrap();
    s.write(blob, -1, "vspeed", None, 0.0).unwrap();
    s.write(blob, -1, "hspeed", None, 0.0).unwrap();
    s.write(blob, -1, "gravity", None, 0.0).unwrap();
    s.write(blob, -1, "gravity_direction", None, 270.0).unwrap();
    if let Some(i) = s.instances.get_mut(&blob) { i.active = true; }
    (sx, sy)
}

fn pin(s: &mut Scene, player: i32, blob: i32, px: f64, py: f64, sx: f64, sy: f64) {
    s.write(player, -1, "x", None, px).unwrap();
    s.write(player, -1, "y", None, py).unwrap();
    s.write(player, -1, "invulnerable", None, 1.0).unwrap();
    s.write(player, -1, "invulnerable2", None, 1.0).unwrap();
    s.write(blob, -1, "x", None, sx).unwrap();
    s.write(blob, -1, "y", None, sy).unwrap();
    s.write(blob, -1, "vspeed", None, 0.0).unwrap();
    s.write(blob, -1, "gravity", None, 0.0).unwrap();
    if let Some(i) = s.instances.get_mut(&blob) { i.active = true; }
}

fn visible_player_spot(
    s: &mut Scene,
    bundle: &callys_core::code_vm::Bundle,
    blob: i32,
    sx: f64,
    sy: f64,
) -> (f64, f64) {
    for (dx, dy) in [(40.0, 0.0), (40.0, -40.0), (40.0, -80.0), (80.0, -80.0), (-40.0, -40.0), (-40.0, 0.0)] {
        let px = sx + dx;
        let py = sy + dy;
        let hit = s.call(bundle, blob, "collision_line",
            &[px, py, sx, sy, PAR_WALL as f64, 0.0, 0.0]).unwrap();
        if hit == -4.0 {
            return (px, py);
        }
    }
    panic!("no clear player position found around the blob fixture");
}


#[test]
fn the_slime_room_opens_from_level11() {
    let (bundle, mut s, player, asset) = slime_room();
    let _ = &bundle;
    assert_eq!(s.current_room, 15.0, "CODE 832 lands in rm_level11a");
    assert_eq!((s.instances[&player].fields["x"], s.instances[&player].fields["y"]), (128.0, 172.0),
        "CODE 832 landing");
    assert_eq!(cast(&s, SLIME).len(), 5, "five obj_slime - the blob mould debuts here");
    assert_eq!(cast(&s, 100).len(), 7, "seven treasure chests share the room");
    assert_eq!(cast(&s, 15).len(), 5, "five obj_knifebandit");
    assert_eq!(cast(&s, 16).len(), 1, "one obj_shooter1");
    assert_eq!(cast(&s, 23).len(), 1, "one obj_wolf");
    assert_eq!(cast(&s, 14).len(), 1, "one obj_enemy");
    assert_eq!(cast(&s, 31).len(), 1, "one obj_bat");
    assert!(doors(&s).contains(&(14.0, 864.0, 172.0)), "CODE 833 returns to rm_level11");
    assert!(doors(&s).contains(&(16.0, 128.0, 204.0)), "CODE 834 opens rm_level12");
    assert!(s.object_parents[&SLIME].contains(&11),
        "the blob chains through par_enemy like every other species");
    let _ = (bundle, asset);
}

#[test]
fn slime_rolls_its_own_state_and_hp_ladder() {
    let (bundle, mut s, _player, _asset) = slime_room();
    let ladder: [(f64, f64, f64); 8] = [
        (1.0, 1.0, 50.0), (5.0, 4.0, 38.0), (10.0, 1.0, 55.0), (10.0, 4.0, 41.0),
        (15.0, 1.0, 65.0), (15.0, 4.0, 50.0), (20.0, 1.0, 75.0), (20.0, 4.0, 60.0),
    ];
    for (level, pwr, want) in ladder {
        s.globals.insert("level".into(), level);
        s.globals.insert("pwr".into(), pwr);
        let id = s.create(&bundle, SLIME, 64.0, 64.0).expect("create obj_slime");
        assert_eq!(s.instances[&id].fields["hpslime"], want,
            "level {level} / pwr {pwr} must set hpslime = {want}");
        let _ = s.destroy(&bundle, id);
    }
    s.globals.insert("level".into(), 1.0);
    s.globals.insert("pwr".into(), 1.0);
    let blob = one(&s, SLIME);
    let i = &s.instances[&blob];
    let dir = i.fields["slimedirection"];
    assert!(dir == -3.0 || dir == 3.0, "CODE 244 chooses the walk direction from {{-3, 3}}, got {dir}");
    assert_eq!(i.fields["hspeed"], dir, "the blob starts walking at slimedirection");
    assert_eq!(i.fields["blobjump"], 45.0, "CODE 244 stores the jump sprite id");
    assert_eq!(i.fields["jumping"], 0.0, "it starts grounded, not airborne");
    assert_eq!(i.fields["xpdrop"], 1.0, "CODE 244 always drops experience");
    assert_eq!(i.alarms[0], 30, "CODE 244 arms the first heartbeat hop at 30");
    assert_eq!(i.alarms[1], 40, "CODE 244 arms the jump-state clear at 40");
    for (name, value) in [("hpdrop", i.fields["hpdrop"]), ("coindrop", i.fields["coindrop"])] {
        assert!((1.0..=5.0).contains(&value) && value.fract() == 0.0,
            "CODE 244 rolls {name} from 1..5, got {value}");
    }
}

#[test]
fn the_heartbeat_hop_rearms_every_sixty_ticks() {
    let (bundle, mut s, player, _asset) = slime_room();
    let blob = one(&s, SLIME);
    let (sx, sy) = grounded_blob(&mut s, &bundle, player, blob);
    // Wall the player off: with a clear line CODE 253's pounce would overwrite
    // the heartbeat's -5 in the same tick.
    let (vx, vy) = visible_player_spot(&mut s, &bundle, blob, sx, sy);
    s.create(&bundle, WALL, (vx + sx) / 2.0, vy).expect("sight blocker");
    let blocked = s.call(&bundle, blob, "collision_line",
        &[vx, vy, sx, sy, PAR_WALL as f64, 0.0, 0.0]).unwrap();
    assert!(blocked > 0.0, "fixture: the heartbeat frame hides the player behind a wall");

    // CODE 252's body is asserted by dispatching it: the launch is -5, the jump
    // pose is set, jumping rises and the heartbeat re-arms to 60. (Observed
    // through a tick instead, the same frame's Step would run its own probes
    // first and can zero the launch, so the exact value is only visible here.)
    pin(&mut s, player, blob, vx, vy, sx, sy);
    s.instances.get_mut(&blob).unwrap().alarms[0] = -1;
    s.dispatch(&bundle, blob, 2, 0).unwrap();
    assert_eq!(s.instances[&blob].fields["vspeed"], -5.0, "CODE 252 launches at -5");
    assert_eq!(s.instances[&blob].fields["sprite_index"], SPR_BLOBJUMP, "the hop pose");
    assert_eq!(s.instances[&blob].fields["jumping"], 1.0, "CODE 252 raises jumping");
    assert_eq!(s.instances[&blob].alarms[0], 60, "CODE 252 re-arms the heartbeat to 60");

    // The heartbeat also fires on its own clock: one tick before expiry is
    // enough for the blob to be airborne without a manual dispatch.
    pin(&mut s, player, blob, vx, vy, sx, sy);
    s.write(blob, -1, "jumping", None, 0.0).unwrap();
    s.instances.get_mut(&blob).unwrap().alarms[0] = 1;
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&blob].fields["jumping"], 1.0,
        "the armed heartbeat really fires through the scheduler");

    // CODE 251 clears the airborne state on its own 60-tick clock.
    pin(&mut s, player, blob, vx, vy, sx, sy);
    s.instances.get_mut(&blob).unwrap().alarms[1] = 1;
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&blob].fields["jumping"], 0.0, "CODE 251 clears jumping");
    assert_eq!(s.instances[&blob].alarms[1], 60, "CODE 251 re-arms to 60");
    // With jumping cleared and no stun, the Step falls back to the idle pose.
    pin(&mut s, player, blob, vx, vy, sx, sy);
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&blob].fields["sprite_index"], SPR_BLOBIDLE, "idle pose restored");
}

#[test]
fn the_blob_pounces_at_a_visible_player_only() {
    let (bundle, mut s, player, _asset) = slime_room();
    let blob = one(&s, SLIME);
    let (sx, sy) = grounded_blob(&mut s, &bundle, player, blob);

    // Visible player: the Step launches the blob (-8) - the pounce is triggered
    // by a CLEAR collision_line, i.e. by seeing the player.
    let (vx, vy) = visible_player_spot(&mut s, &bundle, blob, sx, sy);
    let clear = s.call(&bundle, blob, "collision_line",
        &[vx, vy, sx, sy, PAR_WALL as f64, 0.0, 0.0]).unwrap();
    assert_eq!(clear, -4.0, "fixture: nothing stands between the blob and the player");
    s.write(blob, -1, "jumping", None, 0.0).unwrap();
    s.write(blob, -1, "vspeed", None, 0.0).unwrap();
    pin(&mut s, player, blob, vx, vy, sx, sy);
    s.write(blob, -1, "jumping", None, 0.0).unwrap();
    s.write(blob, -1, "vspeed", None, 0.0).unwrap();
    s.instances.get_mut(&blob).unwrap().alarms[0] = -1; // keep the heartbeat out of this frame
    s.tick(&bundle).unwrap();
    assert!((s.instances[&blob].fields["vspeed"] + 7.3).abs() < 1e-9,
        "a player in plain sight gets pounced on (-8 plus the tick's gravity 0.7), got {}",
        s.instances[&blob].fields["vspeed"]);
    assert_eq!(s.instances[&blob].fields["jumping"], 1.0, "the blob is airborne");
    assert_eq!(s.instances[&blob].fields["sprite_index"], SPR_BLOBJUMP, "the pounce pose");

    // Walled off: the same Step stays quiet (no -8, no airborne flag).
    s.create(&bundle, WALL, (vx + sx) / 2.0, vy).expect("sight blocker");
    let blocked = s.call(&bundle, blob, "collision_line",
        &[vx, vy, sx, sy, PAR_WALL as f64, 0.0, 0.0]).unwrap();
    assert!(blocked > 0.0, "fixture: the wall really cuts the blob's view of the player");
    pin(&mut s, player, blob, vx, vy, sx, sy);
    s.write(blob, -1, "jumping", None, 0.0).unwrap();
    s.write(blob, -1, "vspeed", None, 0.0).unwrap();
    s.instances.get_mut(&blob).unwrap().alarms[0] = -1;
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&blob].fields["jumping"], 0.0, "no pounce through a wall");
    assert!(s.instances[&blob].fields["vspeed"] > -7.0, "no -8 launch without sight");
}

#[test]
fn the_blob_bounces_off_walls_by_probe_and_by_collision() {
    let (bundle, mut s, player, _asset) = slime_room();
    let blob = one(&s, SLIME);
    let (sx, sy) = grounded_blob(&mut s, &bundle, player, blob);

    // CODE 253's own probes: a wall 5 px ahead flips the walk to -2 ...
    s.create(&bundle, WALL, sx + 24.0, sy).expect("right wall");
    s.write(blob, -1, "hspeed", None, 3.0).unwrap();
    pin(&mut s, player, blob, sx + 40.0, sy, sx, sy);
    s.write(blob, -1, "hspeed", None, 3.0).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&blob].fields["hspeed"], -2.0,
        "the right-hand probe reverses the walk to -2");

    // ... and the mirrored probe on the left flips it back to +2.
    s.create(&bundle, WALL, sx - 24.0, sy).expect("left wall");
    pin(&mut s, player, blob, sx + 40.0, sy, sx, sy);
    s.write(blob, -1, "hspeed", None, -3.0).unwrap();
    s.tick(&bundle).unwrap();
    assert_eq!(s.instances[&blob].fields["hspeed"], 2.0,
        "the left-hand probe reverses the walk to +2");

    // Collision 34 is the belt-and-braces bounce the original also carries.
    s.create(&bundle, WALL, sx + 2.0, sy).expect("overlapping wall");
    pin(&mut s, player, blob, sx + 40.0, sy, sx, sy);
    s.write(blob, -1, "hspeed", None, 3.0).unwrap();
    s.instances.get_mut(&blob).unwrap().alarms[0] = -1;
    s.tick(&bundle).unwrap();
    assert!(s.instances[&blob].fields["hspeed"].abs() >= 2.0,
        "Collision 34 (action_bounce) keeps the blob moving after the overlap");
}

#[test]
fn the_blob_sprays_double_health_and_counts_green_slimes() {
    let (bundle, mut s, player, _asset) = slime_room();
    let blob = one(&s, SLIME);
    grounded_blob(&mut s, &bundle, player, blob);
    // The spray drops are positioned relative to the blob's own coordinates.
    let sy = s.read(blob, -1, "y", None).unwrap();
    s.write(blob, -1, "hpdrop", None, 1.0).unwrap();
    s.write(blob, -1, "xpdrop", None, 1.0).unwrap();
    s.write(blob, -1, "coindrop", None, 2.0).unwrap();

    let before: Vec<i32> = s.instances.keys().copied().collect();
    s.dispatch(&bundle, blob, 2, 2).unwrap(); // CODE 250 (alarm[2])
    let mut spawned: Vec<i32> = s.instances.keys().copied().filter(|k| !before.contains(k)).collect();
    spawned.sort();
    let count = |o: i32| spawned.iter().filter(|id| s.instances[*id].object == o).count();

    // The original carries two separate `if (hpdrop == 1)` blocks - one at
    // y - 35 and one at y - 20 - so a single kill drops two hearts.
    assert_eq!(count(HEALTH), 2, "CODE 250 drops health twice for one hpdrop roll");
    let healths: Vec<i32> = spawned.iter()
        .filter(|id| s.instances[*id].object == HEALTH).copied().collect();
    let mut ys: Vec<f64> = healths.iter().map(|id| s.instances[id].fields["y"]).collect();
    ys.sort_by(|a, b| a.partial_cmp(b).unwrap());
    assert_eq!(ys, vec![sy - 35.0, sy - 20.0], "one heart at y - 35 and one at y - 20");
    assert_eq!(count(GEM), 1, "gemdropenabled == 1 drops one gem");
    assert_eq!(count(XPORB), 1, "xpdrop == 1 drops one orb");
    assert_eq!(count(COIN), 5, "coindrop == 2 is the blob's five-coin tier");
    assert_eq!(count(SMALLPUFF), 1, "CODE 245 leaves one obj_smallpuff");
    assert!(s.audio.iter().any(|c| c.sound == SND_EXPLODE && !c.looping), "snd_explode queues");
    assert!(!s.instances[&blob].alive, "the spray ends in action_kill_object()");
    assert_eq!(s.globals.get("greenslimeskilled").copied().unwrap_or(0.0), 1.0,
        "global.greenslimeskilled counts the blob");
    assert_eq!(s.globals.get("enemieskilled").copied().unwrap_or(0.0), 1.0,
        "global.enemieskilled counts it too");
    assert_eq!(C_GREEN, 32768, "the poisoned blend the shared mould uses is still c_green");
}
