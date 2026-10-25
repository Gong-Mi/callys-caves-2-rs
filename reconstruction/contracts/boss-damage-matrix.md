# Boss damage matrix (weapon → boss)

Status: **static, IR-backed** (2026-10-25). Covers which GML weapon bodies arm a
boss's poison/stun alarm. Does **not** cover in-play reachability (range, aim,
AI timing) or the engine-side (libyoyo) weapon system.

## Method

1. `var → object`: every `call instance_place` in the corpus, taking the object
   constant before it and the local store after it. Boss instances flow through
   these variables:

   | variable | object(s) |
   |---|---|
   | `hittrex`, `hitenemytrex` | `obj_trex` (25) |
   | `hit15` | `obj_boss2` (26), `obj_finalboss` (30) |
   | `hit16` | `obj_boss3` (27), `obj_finalboss` (30) |
   | `hit17` | `obj_finalboss` (30) |
   | `hit11` | `obj_hulkingbandit` (21), `obj_finalboss` (30) |
   | `hitboss2..5` | `obj_boss2..5` (26–29) |
   | `hitfinalboss` | `obj_finalboss` (30) |

2. `point-write` = `load <var>; cast to=2; [constant <idx>;] store` (plain) or
   `load <var>; cast to=2; dup; <value>; store` (compound, `hp -= dmg`).
   `scripts/scan_point_writes.py` implements both and reproduces the proxy's
   stack-model ground truth exactly: **1532** point-writes in the corpus.

3. Poison arming = a point-write `(var).alarm[6] = 1`; stun = `(var).alarm[5]`.

## Matrix

| boss | poison arming bodies | stun |
|---|---|---|
| `obj_trex` (25) | 270 flame, 274 blade, 281 arrow, 284 bullet, 289 laser, 294 spike, 303 rocket | none |
| `obj_boss2` (26) | 270, 274, 281, 284, 289, 294 (via `hit15`; bomb 278, boomerang 298 and rocket 303 skip it) | none |
| `obj_boss3` (27) | **none** (`hit16` has no alarm write) | none |
| `obj_boss4` (28) | **none** (`hitboss4` has no alarm write) | none |
| `obj_boss5` (29) | **none** (`hitboss5` has no alarm write) | none |
| `obj_finalboss` (30) | 270, 274, 278, 281, 284, 289, 294, 298, 303 (via `hit11`, the widest set) | none |

Two invariants fall out and are pinned as tests:

- **No boss can be sword-stunned.** The only bodies that touch `alarm[5]` are
  the sword (311, 13 hit variables) and the spike (294, `hit7`/`hit7alt`); none
  of their variables ever holds a boss instance.
- **Bosses 3/4/5 have no weapon poison path at all.** They do have a poison
  alarm body (`Alarm_10` in each), but no point-write in the corpus targets
  `alarm[10]` or `alarm[11]` — those chains are self-armed only. Whoever wants
  to poison boss 3/4/5 in play needs a different mechanism; the weapon path
  cannot do it.

## Regression

`crates/core/tests/boss_damage_matrix_ir.rs` recomputes the variable map and
both alarm tables from `full_ir.json` and compares against the pinned
expectations, so an IR regeneration that changes weapon coverage fails loudly.

Mutation gate (run 2026-10-25): changing `hitboss4 → 29` in the expected map
turns `boss_variable_map_is_pinned` red; restoring it returns 2/2 green.

## Open

- Boss 3/4/5 poison in play: their `Alarm_10` bodies exist and are tested
  (`bosses_3_5_ir.rs` dispatches them), but nothing found so far *arms* them —
  find the trigger (player contact? scripted phase?) or record that poison is
  unreachable for those bosses.
- In-play reachability of the armed paths (bullet/flame actually overlapping the
  boss hitbox) is not covered here.
