# Coin pickup through real player Step

Scope: test-only slice. No engine, VM or client code changed.

Original chain (all from the recovered source/IR, no hand-written rules):
- rm_level1 carries 34 obj_coin (58) records; 2,150 across all rooms; obj_silvercoin
  (60) has zero room instances, so the player Collision_60 (CODE 14) coin-arm is
  dead code for coins — the live path is Step CODE 12 `instance_place(x, y, par_coin)`
  via the parent-chain selector (par_coin 57), paying type*coinmultiply into the
  shared score, advancing global.coinpickup, creating obj_coinadd (132) and
  destroying the coin instance.
- obj_coin Create (CODE 339) sets type=1/friction=0.3; Destroy (CODE 340) plays
  global.coinsound when not muted; obj_coinadd spawns Create 534 / Alarm 535 / Draw 536.

`coin_pickup_ir.rs` (client): town -> level1 through real transition, all 34
original coins materialized, player parked verbatim on the first coin record,
one real Scene tick of CODE 12 destroys exactly that coin, score/coinpickup
advance by 1*coinmultiply, a second distant coin survives, the Destroy emits
global.coinsound (19, from obj_UI Create) as an audio command, and the next real
client frame drains it into the platform sound queue with no runtime diagnostic.
First observed RED: Destroy audio never reached the platform queue (empty queue).
Now GREEN.

Honesty corrections found while building this slice:
- The earlier `global_score_ir` Collision60 pickup assertion used injected
  dispatch and asserted `other` destruction; the live coin path is Step-scanned,
  not collision-event driven. The injected test stays as a host-callback
  characterization, not evidence about geometric pickup.
- Reload after collection respawns all 34 coins: original rooms here are
  non-persistent and Destroy carries no collected-set bookkeeping. The
  previously drafted "persistence guard" expectation (33 after reload) was
  wrong and was corrected to match original data, not the rewritten client's
  JSON save behavior.

Boundaries: player placement is test-controlled, not walked input; gem (type=2)
and gem physics (yorigin) are not exercised; coinadd Draw/alarm visuals are not
pixel-verified; Android SoundPool playback is not device-verified; permanent
pickup identity remains the rewritten save's contract, separate from original
respawn semantics.
