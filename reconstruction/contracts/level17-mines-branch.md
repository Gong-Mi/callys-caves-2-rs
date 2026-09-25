# rm_level17 / rm_level17a 支线门链与卡司契约（level17 branch）

基于 `assets/game.droid` 的原始 room/object 记录。

## 房间与链路

- rm_level16a 的 CODE 851 进入 rm_level17（room 25），落点 `(128,204)`。
- rm_level17 的 CODE 853 返回 rm_level16a（room 24），落点 `(672,1484)`。
- rm_level17 的 CODE 854 进入 rm_level17a（room 26），落点 `(128,204)`。
- rm_level17a 的 CODE 855 返回 rm_level17（room 25），落点 `(1920,1164)`。
- rm_level17a 的 CODE 856 进入 rm_boss2（room 27），落点 `(128,140)`。

测试从真实前置门链进入 room25，再由 CODE 13 碰撞踩门进入 room26；未手设 `target_room_warp`。

## rm_level17（room 25，2048x1280）卡司

- `obj_enemy` ×3
- `obj_knifebandit` ×3
- `obj_shooter1` ×2
- `obj_shooter2` ×1
- `obj_slime` ×4
- `obj_wolf` ×2
- `obj_boulder` ×343
- `obj_coin` ×18
- `obj_treasurechest` ×4
- `obj_woodblock` ×5

## rm_level17a（room 26，512x1600）卡司

- `obj_bat` ×5
- `obj_knifebandit` ×1
- `obj_boulder` ×184
- `obj_coin` ×27
- `obj_platform` ×1
- 无 `obj_watersurface` 与 `obj_waterfill`

## 双向回路

`reverse_branch_returns_to_level17_spawn` 由 room25 的 CODE 854 进入 room26，再由 CODE 855 返回 room25，断言落点 `(1920,1164)` 与 enemy/boulder 卡司重新物化。

## 测试

`crates/core/tests/level17_mines_branch_ir.rs`，2 项：

- `level17_room_and_forward_branch_are_asset_exact`
- `reverse_branch_returns_to_level17_spawn`

## 边界

- 本批为拓扑/卡司证据批；enemy、knifebandit、shooter、slime、wolf、bat 行为复用既有物种契约，未在本房重复铺开。
- CODE 856 → rm_boss2（room 27）已核对门卡，但 Boss2 本体未进本批。
- 真机/GPU 视觉层未验收。
