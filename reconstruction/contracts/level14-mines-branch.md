# rm_level14 / rm_level14a 支线门链与卡司契约（level14 branch）

基于哈希固定的原版资产 `assets/game.droid`。

## 房间与链路

- rm_level13a 的 CODE 839 进入 rm_level14（room 19），落点 `(128,236)`。
- rm_level14 的 CODE 841 返回 rm_level13a（room 18），落点 `(1888,524)`。
- rm_level14 的 CODE 842 进入 rm_level14a（room 20），落点 `(256,204)`。
- rm_level14a 的 CODE 843 进入 rm_level15（room 21），落点 `(160,684)`。
- rm_level14a 的 CODE 844 返回 rm_level14（room 19），落点 `(512,1420)`。

测试走真实踩门链：rm_town → rm_level1 → … → rm_level13a（18）→ rm_level14（19）→ rm_level14a（20），由碰撞事件 CODE 13 的 `room_goto` 泵送，不手设 `target_room_warp`。

## rm_level14（room 19，640x1536）卡司

- `obj_bat` ×4
- `obj_enemy2` ×1
- `obj_shooter1` ×1
- `obj_shooter2` ×2
- `obj_slime` ×1
- `obj_wolf` ×1
- `obj_boulder` ×166
- `obj_coin` ×38
- `obj_watersurface` ×7
- `obj_waterfill` ×1
- `obj_treasurechest` ×0
- 另有 `obj_bg`、`obj_muting`、`obj_weaponswap` 及墙体对象

## rm_level14a（room 20，2048x480）卡司

- `obj_enemy` ×2
- `obj_shooter2` ×1
- `obj_slime` ×1
- `obj_wolf` ×1
- `obj_boulder` ×136
- `obj_coin` ×23
- `obj_spikes` ×7
- `obj_treasurechest` ×7
- `obj_woodblock` ×5
- `obj_watersurface` ×0
- `obj_waterfill` ×0

## 双向回路

`reverse_branch_returns_to_level14_spawn` 先由 CODE 842 进入 rm_level14a，再由 CODE 844 返回 rm_level14，断言回房落点 `(512,1420)` 与 bat/boulder 卡司重新物化。

## 测试（`crates/core/tests/level14_mines_branch_ir.rs`，2 项）

| 用例 | 断言 |
| --- | --- |
| `level14_room_and_forward_branch_are_asset_exact` | room19/20 落点、完整卡司、四张门卡 |
| `reverse_branch_returns_to_level14_spawn` | CODE 844 回 room19 落点与卡司重物化 |

## 边界

- 本批为拓扑/卡司证据批：零引擎改动。bat、slime、wolf、shooter1、shooter2、enemy2 行为复用既有物种契约，未在本房重复铺开行为测试。
- CODE 843 → rm_level15（room 21）门卡已核对，但 room21 本体未进本批。
- 真机/GPU 视觉层未验收。
