# Shared legacy score

GameMaker's legacy `score` is global in scope, shared by instance contexts:
https://manual.gamemaker.io/lts/en/GameMaker_Language/GML_Overview/Variables/Builtin_Global_Variables/score.htm

The original full IR contains 85 score sites (60 loads / 25 stores) across
25 CODE bodies, all scalar selector=-1, array=false, other=false. Complete
CODE/offset mapping is `score-sites.json`, re-derived and compared in a Rust test.
No bytecode, source recovery, opcode normalization or custom global namespace is
changed. `Scene::score` now backs those scalar self accesses; creating UI/death or
loading another room no longer creates/resets an independent instance score.
Non-finite writes still fail before modifying the balance.

Original behavior exercised in `global_score_ir.rs`:
- Two different instance contexts read/write one balance (regression was RED).
- Player Collision60 CODE14 collects a four-coin pickup, emits original effects
  and destroys the other instance; this is callback injection, not a geometric
  collision test.
- Health-refill Mouse7 CODE447 spends the player's balance and heals once;
  releasing again at full health does not deduct a second time (RED before fix:
  shop sees zero while player has 500).
- Death Mouse7 CODE543 -> Destroy CODE541 deducts coindeduct from that same balance.
- Room restart keeps the resulting balance.

`ui_layer_ir` now seeds score through Host::write rather than directly populating
an instance field which is not the engine-global builtin. Separate synthetic
original_startup host tests are unchanged.

Coverage is shared storage for all enumerated sites; not all 25 CODE bodies or
all shops/pickups are behavior-verified. Full save-to-disk/cold-start persistence,
all builtin-global variables, device UI interaction and original-runner differential
execution remain separate gates. Test fixture intentionally seeds a starting
balance and directly dispatches selected original callbacks; it is not a claim of
an end-to-end geometric pickup/Android shop interaction.
