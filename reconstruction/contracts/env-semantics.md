# Environment (with) semantics — closure note (batch E)

The CFG evidence ledger (`progress.tsv` from the reverse-code CI leg) marks
2,494 instructions across 62 CODEs as `environment_ops_pending` — a
structural-CFG-phase marker meaning "with-environment receiver/stack not yet
reviewed at runtime". This note closes that item.

## What the pending sites actually are

All 2,494 sites are instances of four behaviours, verified by direct
inspection of the recovered GML for the top-pending CODEs:

1. `with (instance_id) { ... }` — boss/enemy death alarms addressing XP-orb
   instances by id (`ID = instance_create(...); with (ID) { motion_set }`,
   e.g. obj_trex/obj_boss2..5 Alarm_0, 170 sites each);
2. `with (object) { ... }` — Lloyd sheet Destroy addressing `obj_lloyd`
   (CODE 557..663);
3. `with (buttons) { instance_destroy() }` — pause/menu Destroy events;
4. nested `with` via `obj_finalbosspuff` Create (with obj_leftbutton /
   obj_rightbutton).

## Runtime semantics — pinned at the VM layer

`crates/core/tests/env_semantics_ir.rs` hand-builds IR bodies and pins the
four behaviours against the numeric VM:

- instance-id selector (`>= 100000`) writes only the addressed instance;
- object selector runs the body once per selected instance, in id order;
- empty selection skips the body and still unwinds the environment stack
  (pushenv jumps AT the popenv, not past it — this is the load-bearing
  detail that keeps `environments` balanced at CODE exit);
- nested with restores the OUTER target (not the original self) for the
  remaining outer iterations;
- Load/Store inside the body resolve against the current with target.

## Real-site dispatch evidence (on top of the kernel)

- obj_enemy Alarm_0 (CODE 46) with-XP-fan: `level1_enemy_cast_ir` death
  cascade asserts the orb drops;
- boss Alarm_0 CODE 160/168/184/196/212: `boss_kill_chains` (#47) drives
  each death end-to-end through the client frame loop;
- Lloyd sheet Destroy CODE 557..663: `lloyd_tutorial_all_sheets_ir` (PR #38)
  dispatches all 16;
- finalbosspuff Create with-buttons: `boss_kill_chains` boss6 ending.

## Per-site closure (the population, not just the shape)

The four behaviours above were argued by eye over the top-pending CODEs. The
population is now mechanical and falsifiable in
`crates/core/tests/env_with_sites_ir.rs`:

- the 2,494 sites are counted from the lowered IR, per CODE, and reconciled
  against the CFG-phase ledger's `environment_ops_pending` column - a column
  produced by a different tool (`reverse_cfg.py`). All 62 rows agree, and the
  reverse direction holds too: no CODE outside those 62 carries an environment
  instruction, so the 62 are a complete population;
- every `pushenv` receiver is classified from the instruction that pushes it:
  `cast to=2` (an instance/expression receiver) or a `constant` object index.
  Measured: 1,247 `pushenv` + 1,247 `popenv`; 1,104 expression receivers and
  143 object-index receivers covering 54 objects (`obj_lloyd` 16, `obj_pause` 9,
  `obj_store` 7, ...). Nothing is unclassified, and an unknown push shape is
  reported rather than guessed;
- the five boss death fans (obj_trex/boss2..5 Alarm_0, CODE 160/168/184/196/212)
  are one generated 25-orb block each: `ID`..`ID25` with the multiplicity
  profile 6x5, 5x5, 3x5, 2x5, 1x5 = 85 `with` blocks per alarm, identical in all
  five. The receiver is always `load ID<n>` -> `cast to=2` -> `pushenv`, never an
  object constant.

What that still does not prove: that each of the 1,104 expression sites resolves
to the same instance set at run time as the four pinned behaviours do in
general. The runtime argument stays the kernel plus the representative suites
listed above; this section closes the *enumeration*, not every execution.

## Ledger bookkeeping

`progress.tsv` is a CI artifact of the structural CFG phase; its
`environment_ops_pending` / `stack_semantics` / `behavior_verified` columns
were frozen at that phase and never refreshed. This note + the VM-layer
suite are the authoritative closure; do not read the old columns as current
state.
