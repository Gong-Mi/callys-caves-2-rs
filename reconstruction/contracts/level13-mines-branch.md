# rm_level13 / rm_level13a 支线门链与卡司契约（level13 branch）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 房间与链路

- rm_level12 的 CODE 836（warproom 17）进入 **rm_level13**（room 17），落点 (128, 268)。
- rm_level13 两张门卡：CODE 837 → rm_level12（16），落点 (1888, 524)；CODE 838 → rm_level13a（18），落点 (128, 236)。
- rm_level13a 两张门卡：CODE 839 → rm_level14（19），落点 (128, 236)；CODE 840 → rm_level13（17），落点 (864, 1164)。

测试全部走真实踩门链：rm_town → rm_level1 → … → rm_level11a（15）→ rm_level12（16）→ rm_level13（17）→ rm_level13a（18），由碰撞事件 CODE 13 的 `room_goto` 泵送，不手设 `target_room_warp`。

## rm_level13（room 17，1024x1280）卡司

bat×2、slime×2、knifebandit×3、spikes×5、platform×3、watersurface×12、waterfill×3、coin×20、gem×5；**无宝箱**（chest×0 单独断言，区别于上游 11a 的 7 箱房）。

## rm_level13a（room 18，2048x640）卡司

knifebandit×5、chest×5、platform×10、watersurface×56、waterfill×1、coin×22——水房+宝箱库形态，与 level6 宝库房同族但规模不同。

## 双向回路

reverse_branch 用例先 CODE 838 进 13a，再 CODE 840 回 13，断言落点 (864, 1164) 与回房后卡司重新物化（bat×2、slime×2）。

## 测试（`crates/core/tests/level13_mines_branch_ir.rs`，2 项）

| 用例 | 断言 |
| --- | --- |
| `level13_room_and_forward_branch_are_asset_exact` | 逐房落点、完整卡司计数、两张门卡三元组 |
| `reverse_branch_returns_to_level13_spawn` | CODE 840 回 13 落点 (864,1164)、卡司重物化 |

## 边界

- 本批为拓扑/卡司证据批：零引擎改动。rm_level13 的 slime/bat 行为已由 `mines_slime_ir`、`level3_bat_air_ir` 各自模具覆盖，未在本房逐只复测。
- CODE 839 → rm_level14（19）的门卡数据在 inspect 中已核对，但 19 房本体未进本批门链。
- 真机/GPU 视觉层未验收。
