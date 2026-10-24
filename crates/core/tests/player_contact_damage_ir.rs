//! CODE 12 `obj_player` Step — the obj_knifebandit (15) contact matrix,
//! enumerated rather than sampled.
//!
//! CODE 12 is the player's per-frame state machine (6163 instructions, start
//! 3770532): input/movement first, then one contact block per enemy family.
//! This suite drives exactly one family block — the knifebandit one, which is
//! the template the others repeat — and enumerates its whole gate tree:
//!
//!     constant 15; cast; instance_exists          -> bf past the family
//!     hitknifebandit != -4;  facing == K
//!     invulnerable == 0 && invulnerable2 == 0     (&& short-circuit: the `b`
//!                                                  skips the pushed `0`)
//!     rebuff != 1  -> HIT
//!         flashing = 1;  global.health1 -= 1
//!         hit.x > x -> invulnerable  = 1; sliding1 = 1
//!         hit.x < x -> invulnerable2 = 1; sliding1 = 1 (facing 0)
//!                                         sliding2 = 1 (facing 1)
//!         alarm[4] = 10; alarm[7] = 20; alarm[8] = 23
//!         global.soundmute == 0 -> audio_play_sound(24, 0, false)
//!         place_meeting(x + hspeed, y, par_wall) -> hspeed = 0
//!     rebuff == 1  -> DODGE
//!         !instance_exists(106) -> instance_create(x, y - 10, 106)
//!
//! Every constant above was read off the shipped bytecode stream (instruction
//! indices [430..600]), not off the recovered GML; the GML (`0012__gml_Object
//! _obj_player_Step_0.gml`) was navigation only. `the_block_carries_...`
//! re-derives those constants from the live bundle at run time, so a
//! regenerated IR that changed the block fails here instead of silently
//! leaving the matrix aimed at a shape that no longer exists.
//!
//! Fixture discipline: the player is re-pinned on every dispatch (its own Step
//! integrates gravity into y), the enemy is placed with an explicit x/y after
//! its Create ran, and the sprite geometry is wired from `assets/game.droid`
//! exactly like `GameState::enable_ir_gameplay` does — without it the broad
//! phase boxes every instance as its integer point and the contact cells would
//! pass for the wrong reason.
//!
//! Scope: re-written-end IR regression semantics. This is one phase of CODE
//! 12, not the whole body: the remaining families, the death cascade and the
//! pickup/water phases are separate batches.

use callys_asset::GameDroidAsset;
use callys_core::code_vm::{load_bundle_from_file, Bundle, Instruction, Op};
use callys_core::ir_scene::{Scene, SpriteBounds};
use std::path::Path;

const PLAYER: i32 = 0;
const KNIFE: i32 = 15;
const WALL: i32 = 4;
const DODGED: i32 = 106;
const PAR_WALL: f64 = 34.0;
const CODE_STEP: usize = 12;
/// `snd_impactsound5` (audio table): the shipped hurt voice.
const SND_IMPACT5: f64 = 24.0;
const PX: f64 = 500.0;
const PY: f64 = 200.0;
const HP0: f64 = 4.0;

fn bundle() -> Bundle {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("src/generated/full_ir.json");
    load_bundle_from_file(&p).expect("load full_ir.json")
}

/// The app's SPRT wiring: width/origin as bounds, the recorded manual bbox and
/// the per-frame masks travel with it (see collision-broad-phase.md).
fn wire_sprite_geometry(s: &mut Scene) {
    let asset = GameDroidAsset::parse(
        &Path::new(env!("CARGO_MANIFEST_DIR")).join("../../assets/game.droid"),
    )
    .expect("parse game.droid");
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
        if let Some(bbox) = sp.bbox {
            s.sprite_bboxes.insert(*sid as i32, bbox);
        }
        if !sp.masks.is_empty() {
            s.sprite_masks.insert(*sid as i32, sp.masks.clone());
        }
    }
}

/// One cell of the contact matrix.
#[derive(Clone, Copy, Debug)]
struct Cell {
    facing: f64,
    inv: f64,
    inv2: f64,
    rebuff: f64,
    /// +1: the enemy stands right of the player, -1: left, 0: same x.
    side: i32,
    soundmute: f64,
    wall: bool,
    hspeed: f64,
}

impl Cell {
    fn base() -> Self {
        Cell { facing: 0.0, inv: 0.0, inv2: 0.0, rebuff: 0.0, side: 1, soundmute: 0.0, wall: false, hspeed: 0.0 }
    }
    /// The gates are open: both invulnerability latches clear.
    fn entered(&self) -> bool {
        self.inv == 0.0 && self.inv2 == 0.0
    }
    fn hit(&self) -> bool {
        self.entered() && self.rebuff == 0.0
    }
    fn label(&self) -> String {
        format!(
            "facing {} inv {} inv2 {} rebuff {} side {} mute {} wall {}",
            self.facing, self.inv, self.inv2, self.rebuff, self.side, self.soundmute, self.wall
        )
    }
}

fn run(b: &Bundle, c: &Cell) -> (Scene, i32) {
    let mut s = Scene::default();
    s.init_bundle(b);
    s.init_fresh_start_globals();
    wire_sprite_geometry(&mut s);

    let p = s.create(b, PLAYER, PX, PY).expect("create obj_player");
    {
        let i = s.instances.get_mut(&p).expect("player");
        for (k, v) in [
            ("facing", c.facing),
            ("invulnerable", c.inv),
            ("invulnerable2", c.inv2),
            ("hspeed", c.hspeed),
            ("hsp", 0.0),
            ("vsp", 0.0),
            ("grounded", 1.0),
            ("sliding1", 0.0),
            ("sliding2", 0.0),
            ("flashing", 0.0),
            ("image_blend", 16777215.0),
        ] {
            i.fields.insert(k.into(), v);
        }
    }

    let ex = PX + 8.0 * c.side as f64;
    let k = s.create(b, KNIFE, ex, PY).expect("create obj_knifebandit");
    {
        let i = s.instances.get_mut(&k).expect("knifebandit");
        // Its Create may have re-placed it; the cell owns the geometry.
        i.fields.insert("x".into(), ex);
        i.fields.insert("y".into(), PY);
        i.fields.insert("facing".into(), 0.0);
    }

    if c.wall {
        // par_wall (34) accepts obj_wall (4) whose Create sets type=1: the
        // movement phase's own wall branch reads that field.
        let w = s.create(b, WALL, PX + c.hspeed, PY).expect("create obj_wall");
        s.instances.get_mut(&w).expect("wall").fields.insert("type".into(), 1.0);
    }

    // The player's own Create re-seeds these globals, so the cell writes them
    // after every create has run and immediately before the Step.
    s.globals.insert("health1".into(), HP0);
    s.globals.insert("maxhp".into(), HP0);
    s.globals.insert("rebuff".into(), c.rebuff);
    s.globals.insert("soundmute".into(), c.soundmute);

    s.dispatch(b, p, 3, 0).expect("CODE 12 player Step");
    (s, p)
}

fn field(s: &Scene, id: i32, name: &str) -> f64 {
    *s.instances[&id]
        .fields
        .get(name)
        .unwrap_or_else(|| panic!("instance {id} has no field {name}"))
}

fn dodged_count(s: &Scene) -> usize {
    s.instances.values().filter(|i| i.object == DODGED).count()
}

fn impact_voices(s: &Scene) -> usize {
    s.audio_voices.iter().filter(|v| v.sound == SND_IMPACT5).count()
}

// ---------------------------------------------------------------------------
// the block, as the shipped bundle spells it
// ---------------------------------------------------------------------------

/// The family gate: `constant 15; cast; instance_exists` — the first one in the
/// body (earlier families query their own ids).
fn family_block(b: &Bundle) -> &[Instruction] {
    let body = &b.codes.iter().find(|c| c.id == CODE_STEP).expect("CODE 12").instructions;
    let gate = body
        .windows(3)
        .position(|w| {
            matches!(&w[0].op, Op::Constant { value } if *value == KNIFE as f64)
                && matches!(w[1].op, Op::Cast { to: 5 })
                && matches!(&w[2].op, Op::Call { name, argc: 1 } if name == "instance_exists")
        })
        .expect("the obj_knifebandit family gate");
    let end = match &body[gate + 4].op {
        Op::Bf { target } => *target,
        other => panic!("the family gate ends on {:?}, expected a bf", other),
    };
    let start = body[gate].offset;
    let len = body[gate..].iter().take_while(|i| i.offset < end).count();
    assert!(len > 100, "the knifebandit block is {len} instructions");
    &body[gate..gate + len]
}

#[test]
fn the_block_carries_the_shipped_constants_the_matrix_asserts() {
    let b = bundle();
    let block = family_block(&b);

    // Two facing trees, each with the alarm triple and the impact voice.
    let mut alarms: Vec<(f64, f64)> = Vec::new();
    for w in block.windows(4) {
        if let (
            Op::Constant { value },
            Op::Constant { value: minus_one },
            Op::Constant { value: slot },
            Op::Store { name, selector, array, .. },
        ) = (&w[0].op, &w[1].op, &w[2].op, &w[3].op)
        {
            if name == "alarm" && *array && *selector == 0 && *minus_one == -1.0 {
                alarms.push((*slot, *value));
            }
        }
    }
    assert_eq!(
        alarms,
        vec![(4.0, 10.0), (7.0, 20.0), (8.0, 23.0), (4.0, 10.0), (7.0, 20.0), (8.0, 23.0)],
        "alarm[4]=10, alarm[7]=20, alarm[8]=23 in each facing tree"
    );

    // args pop in reverse push order, so the sound is the LAST constant pushed:
    //   constant <priority>; cast; constant <looping>; cast; constant <sound>
    let sounds: Vec<f64> = block
        .windows(7)
        .filter_map(|w| match (&w[0].op, &w[1].op, &w[2].op, &w[3].op, &w[4].op, &w[5].op, &w[6].op) {
            (Op::Constant { value: prio }, Op::Cast { to: 5 }, Op::Constant { value: looping }, Op::Cast { to: 5 },
             Op::Constant { value: snd }, Op::Cast { to: 5 }, Op::Call { name, argc: 3 })
                if *prio == 0.0 && *looping == 0.0 && name == "audio_play_sound" => Some(*snd),
            _ => None,
        })
        .collect();
    assert_eq!(sounds, vec![SND_IMPACT5, SND_IMPACT5], "one impact voice per facing tree");

    let walls = block
        .iter()
        .filter(|i| matches!(&i.op, Op::Constant { value } if *value == PAR_WALL))
        .count();
    assert_eq!(walls, 2, "one place_meeting(x + hspeed, y, par_wall) per facing tree");

    // The dodge spawn, as its whole argument push:
    //   constant <obj>; cast; load y; constant <dy>; sub; load x; instance_create/3
    let creations: Vec<f64> = block
        .windows(7)
        .filter_map(|w| match (&w[0].op, &w[1].op, &w[2].op, &w[3].op, &w[4].op, &w[5].op, &w[6].op) {
            (Op::Constant { value: obj }, Op::Cast { to: 5 }, Op::Load { name: yn, .. },
             Op::Constant { .. }, Op::Sub | Op::Add, Op::Load { name: xn, .. },
             Op::Call { name, argc: 3 })
                if yn == "y" && xn == "x" && name == "instance_create" => Some(*obj),
            _ => None,
        })
        .collect();
    assert_eq!(
        creations,
        vec![DODGED as f64, DODGED as f64],
        "one dodge spawn per facing tree"
    );
    assert_eq!(
        block.iter().filter(|i| matches!(i.op, Op::Not)).count(),
        2,
        "each dodge branch negates instance_exists"
    );
}

// ---------------------------------------------------------------------------
// the matrix
// ---------------------------------------------------------------------------

#[test]
fn every_facing_gate_and_side_cell_matches_the_bytecode() {
    let b = bundle();
    let mut cells = 0usize;
    let mut hits = 0usize;
    for facing in [0.0, 1.0] {
        for (inv, inv2) in [(0.0, 0.0), (1.0, 0.0), (0.0, 1.0), (1.0, 1.0)] {
            for side in [1, -1, 0] {
                let c = Cell { facing, inv, inv2, side, ..Cell::base() };
                let (s, p) = run(&b, &c);
                let hit = c.hit();
                if hit {
                    hits += 1;
                }
                let want_hp = if hit { HP0 - 1.0 } else { HP0 };
                assert_eq!(s.globals["health1"], want_hp, "{}", c.label());
                assert_eq!(field(&s, p, "flashing"), if hit { 1.0 } else { 0.0 }, "{}", c.label());

                if hit {
                    // The side decides which latch (and which slide) is armed.
                    let (want_inv, want_inv2, want_s1, want_s2) = match side {
                        1 => (1.0, 0.0, 1.0, 0.0),
                        -1 if facing == 0.0 => (0.0, 1.0, 1.0, 0.0),
                        -1 => (0.0, 1.0, 0.0, 1.0),
                        // hit.x == x: neither `>` nor `<` matches, so no latch
                        // is armed at all (the shipped quirk pinned below).
                        _ => (0.0, 0.0, 0.0, 0.0),
                    };
                    assert_eq!(
                        (field(&s, p, "invulnerable"), field(&s, p, "invulnerable2"),
                         field(&s, p, "sliding1"), field(&s, p, "sliding2")),
                        (want_inv, want_inv2, want_s1, want_s2),
                        "{}",
                        c.label()
                    );
                    let alarms = &s.instances[&p].alarms;
                    assert_eq!((alarms[4], alarms[7], alarms[8]), (10, 20, 23), "{}", c.label());
                    assert_eq!(impact_voices(&s), 1, "{}", c.label());
                } else {
                    // Nothing armed, nothing spent.
                    assert_eq!(
                        (field(&s, p, "invulnerable"), field(&s, p, "invulnerable2"),
                         field(&s, p, "sliding1"), field(&s, p, "sliding2")),
                        (c.inv, c.inv2, 0.0, 0.0),
                        "{}",
                        c.label()
                    );
                    let alarms = &s.instances[&p].alarms;
                    assert_eq!((alarms[4], alarms[7], alarms[8]), (-1, -1, -1), "{}", c.label());
                    assert_eq!(impact_voices(&s), 0, "{}", c.label());
                }
                cells += 1;
            }
        }
    }
    assert_eq!(cells, 2 * 4 * 3, "2 facings x 4 latch combinations x 3 sides");
    assert_eq!(hits, 2 * 3, "the gates are open in 2 facings x 3 sides");
}

#[test]
fn an_exactly_overlapping_enemy_arms_no_latch() {
    // hit.x == x matches neither `>` nor `<`, so health1 drops while
    // invulnerable/invulnerable2 stay 0: the next frame costs another life.
    let b = bundle();
    let c = Cell { side: 0, ..Cell::base() };
    let (mut s, p) = run(&b, &c);
    assert_eq!(s.globals["health1"], HP0 - 1.0);
    assert_eq!(field(&s, p, "invulnerable"), 0.0);
    assert_eq!(field(&s, p, "invulnerable2"), 0.0);

    // Re-pin the geometry the way a real frame would leave it, then hit again.
    {
        let i = s.instances.get_mut(&p).expect("player");
        i.fields.insert("y".into(), PY);
        i.fields.insert("vsp".into(), 0.0);
    }
    let k = s.instances.iter().find(|(_, i)| i.object == KNIFE).map(|(id, _)| *id).expect("knife");
    {
        let i = s.instances.get_mut(&k).expect("knife");
        i.fields.insert("y".into(), PY);
    }
    s.dispatch(&b, p, 3, 0).expect("CODE 12 player Step, second frame");
    assert_eq!(s.globals["health1"], HP0 - 2.0, "no latch was armed, so it hits again");
}

#[test]
fn a_set_latch_blocks_the_second_hit() {
    let b = bundle();
    for (inv, inv2) in [(1.0, 0.0), (0.0, 1.0), (1.0, 1.0)] {
        let c = Cell { inv, inv2, side: 1, ..Cell::base() };
        let (s, _) = run(&b, &c);
        assert_eq!(s.globals["health1"], HP0, "{}", c.label());
    }
    // A real hit arms the latch that the following frame must respect.
    let open = Cell { side: 1, ..Cell::base() };
    let (mut s, p) = run(&b, &open);
    assert_eq!(s.globals["health1"], HP0 - 1.0);
    {
        let i = s.instances.get_mut(&p).expect("player");
        i.fields.insert("y".into(), PY);
        i.fields.insert("vsp".into(), 0.0);
    }
    let k = s.instances.iter().find(|(_, i)| i.object == KNIFE).map(|(id, _)| *id).expect("knife");
    s.instances.get_mut(&k).expect("knife").fields.insert("y".into(), PY);
    s.dispatch(&b, p, 3, 0).expect("second frame");
    assert_eq!(s.globals["health1"], HP0 - 1.0, "invulnerable=1 must block the retry");
}

#[test]
fn rebuff_turns_the_hit_into_a_single_dodge_overlay() {
    let b = bundle();
    for facing in [0.0, 1.0] {
        // Both latches clear: the dodge branch re-tests them.
        let c = Cell { facing, rebuff: 1.0, side: 1, ..Cell::base() };
        let (mut s, p) = run(&b, &c);
        assert_eq!(s.globals["health1"], HP0, "{}: a dodge never costs a life", c.label());
        assert_eq!(field(&s, p, "flashing"), 0.0, "{}: no hit flash", c.label());
        assert_eq!(dodged_count(&s), 1, "{}: one obj_dodged", c.label());
        let did = s
            .instances
            .iter()
            .find(|(_, i)| i.object == DODGED)
            .map(|(id, _)| *id)
            .expect("dodged instance");
        assert_eq!(field(&s, did, "x"), PX, "{}: spawned at the player's x", c.label());
        let dy = PY - field(&s, did, "y");
        assert!(
            (8.0..=12.0).contains(&dy),
            "{}: spawned at y - 10 (got {} - {})",
            c.label(),
            PY,
            field(&s, did, "y")
        );
        assert_eq!(impact_voices(&s), 0, "{}: no hurt voice on a dodge", c.label());

        // `!instance_exists(106)` makes it one-shot while the overlay lives.
        {
            let i = s.instances.get_mut(&p).expect("player");
            i.fields.insert("y".into(), PY);
            i.fields.insert("vsp".into(), 0.0);
            i.fields.insert("invulnerable".into(), 0.0);
            i.fields.insert("invulnerable2".into(), 0.0);
        }
        let k = s.instances.iter().find(|(_, i)| i.object == KNIFE).map(|(id, _)| *id).expect("knife");
        s.instances.get_mut(&k).expect("knife").fields.insert("y".into(), PY);
        s.dispatch(&b, p, 3, 0).expect("second frame");
        assert_eq!(dodged_count(&s), 1, "{}: the overlay is not re-spawned", c.label());
    }
}

#[test]
fn the_dodge_branch_still_requires_open_latches() {
    let b = bundle();
    for (inv, inv2) in [(1.0, 0.0), (0.0, 1.0)] {
        let c = Cell { inv, inv2, rebuff: 1.0, side: 1, ..Cell::base() };
        let (s, _) = run(&b, &c);
        assert_eq!(dodged_count(&s), 0, "{}: a latched player does not dodge", c.label());
        assert_eq!(s.globals["health1"], HP0, "{}", c.label());
    }
}

#[test]
fn soundmute_gates_the_impact_voice() {
    let b = bundle();
    let loud = Cell { soundmute: 0.0, side: 1, ..Cell::base() };
    assert_eq!(impact_voices(&run(&b, &loud).0), 1, "soundmute=0 plays the hurt voice");
    let mute = Cell { soundmute: 1.0, side: 1, ..Cell::base() };
    assert_eq!(impact_voices(&run(&b, &mute).0), 0, "soundmute=1 silences it");
    // The damage itself is not gated by the sound switch.
    let (s, _) = run(&b, &mute);
    assert_eq!(s.globals["health1"], HP0 - 1.0);
}

#[test]
fn the_wall_behind_the_knockback_zeroes_hspeed() {
    let b = bundle();
    let free = Cell { hspeed: 4.0, wall: false, side: 1, ..Cell::base() };
    let (s, p) = run(&b, &free);
    assert_eq!(field(&s, p, "hspeed"), 4.0, "no wall ahead: hspeed keeps its value");

    let blocked = Cell { hspeed: 4.0, wall: true, side: 1, ..Cell::base() };
    let (s, p) = run(&b, &blocked);
    assert_eq!(field(&s, p, "hspeed"), 0.0, "place_meeting(x + hspeed, y, par_wall) cancels it");
    assert_eq!(s.globals["health1"], HP0 - 1.0, "the hit still lands");
}
