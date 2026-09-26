# rm_level15 / rm_level15a 支线门链与卡司契约（level15 branch）

基于 `assets/game.droid` 的原始 room/object 记录。

## 房间与链路

- rm_level14a 的 CODE 843 进入 rm_level15（room 21），落点 `(160,684)`。
- rm_level15 的 CODE 845 返回 rm_level14a（room 20），落点 `(1856,364)`。
- rm_level15 的 CODE 846 进入 rm_level15a（room 22），落点 `(128,204)`。
- rm_level15a 的 CODE 847 进入 rm_level16（room 23），落点 `(128,204)`。
- rm_level15a 的 CODE 848 返回 rm_level15（room 21），落点 `(1888,684)`。

测试从真实前置门链进入 room21，再由 CODE 13 碰撞踩门进入 room22；未手设 `target_room_warp`。

## rm_level15（room 21，2048x800）卡司

- `obj_knifebandit` ×6
- `obj_shooter2` ×2
- `obj_slime` ×1
- `obj_boulder` ×250
- `obj_coin` ×23
- `obj_platform` ×9
- `obj_watersurface` ×6
- `obj_waterfill` ×1
- `obj_treasurechest` ×6
- `obj_woodblock` ×9

## rm_level15a（room 22，2048x480）卡司

- `obj_bat` ×5
- `obj_shooter1` ×1
- `obj_slime` ×4
- `obj_boulder` ×129
- `obj_coin` ×10
- `obj_platform` ×2
- `obj_watersurface` ×0
- `obj_waterfill` ×0
- `obj_treasurechest` ×3
- `obj_woodblock` ×3

## 双向回路

`reverse_branch_returns_to_level15_spawn` 由 room21 的 CODE 846 进入 room22，再由 CODE 848 返回 room21，断言落点 `(1888,684)` 及 knifebandit/boulder 卡司重新物化。

## 测试

`crates/core/tests/level15_mines_branch_ir.rs`，2 项：

- `level15_room_and_forward_branch_are_asset_exact`
- `reverse_branch_returns_to_level15_spawn`

## 边界

- 本批为拓扑/卡司证据批；enemy 行为复用既有物种契约，未在本房重复铺开。
- CODE 847 → rm_level16（room 23）已核对门卡，但 room23 本体未进本批。
- 真机/GPU 视觉层未验收。
