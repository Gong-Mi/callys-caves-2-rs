# rm_level16 / rm_level16a 支线门链与卡司契约（level16 branch）

基于 `assets/game.droid` 的原始 room/object 记录与 CODE 849-852 门卡字节码。

## 房间与链路

- rm_level15a 的 CODE 847 进入 rm_level16（room 23），落点 `(128,204)`。
- rm_level16 的 CODE 849 返回 rm_level15a（room 22），落点 `(1888,364)`。
- rm_level16 的 CODE 850 进入 rm_level16a（room 24），落点 `(128,108)`。
- rm_level16a 的 CODE 851 进入 rm_level17（room 25），落点 `(128,204)`。
- rm_level16a 的 CODE 852 返回 rm_level16（room 23），落点 `(1760,1164)`。

测试从真实前置门链进入 room22，再由 CODE 13 碰撞踩门依次进入 room23、room24；未手设 `target_room_warp`。

四张门卡均含 `unlocked=1` 常量存储。

## rm_level16（room 23，1920x1280）卡司

- `obj_enemy` ×3
- `obj_knifebandit` ×4
- `obj_wolf` ×2
- `obj_slime` ×4
- `obj_boulder` ×263
- `obj_coin` ×4
- `obj_platform` ×3
- `obj_spikes` ×29
- `obj_woodblock` ×9
- 无 watersurface / waterfill / treasurechest

## rm_level16a（room 24，800x1600 竖房）卡司

- `obj_enemy` ×1
- `obj_shooter1` ×2
- `obj_bat` ×4
- `obj_slime` ×2
- `obj_boulder` ×180
- `obj_coin` ×26
- `obj_platform` ×7
- `obj_watersurface` ×38
- `obj_waterfill` ×9
- 无 spikes / woodblock / treasurechest

room24 是 800x1600 的竖井房，返程门落点 `(1760,1164)` 贴 room23 的 1920x1280 右下区。

## 双向回路

`reverse_branch_returns_to_level16_spawn` 由 room23 的 CODE 850 进入 room24，再由 CODE 852 返回 room23，断言落点 `(1760,1164)` 及 knifebandit/boulder 卡司重新物化。

## 测试

`crates/core/tests/level16_mines_branch_ir.rs`，2 项：

- `level16_room_and_forward_branch_are_asset_exact`
- `reverse_branch_returns_to_level16_spawn`

## 边界

- 本批为拓扑/卡司证据批；enemy 行为复用既有物种契约（enemy/knifebandit/wolf/slime/bat/shooter1），未在本房重复铺开。
- CODE 851 → rm_level17（room 25）已核对门卡，但 room25 本体未进本批。
- 真机/GPU 视觉层未验收。
