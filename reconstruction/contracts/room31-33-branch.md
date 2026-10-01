# room31-33（room 28-30）Boss2 后门链契约

基于 `assets/game.droid` 的原始 room/object/creation-code 记录。

## 门链（门实例位置 ↔ creation code ↔ 落点）

- rm_boss2（room 27）CODE 858（门自身 1216,352）→ room31，落点 (128,204)。
- room31（room 28）CODE 859（64,192）→ 返程 rm_boss2，落点 (1152,364)。
- room31 CODE 860（1984,672）→ room32，落点 (128,236)。
- room32（room 29）CODE 861（1984,224）→ room33，落点 (128,1164)。
- room32 CODE 862（64,224）→ 返程 room31，落点 (1888,684)。
- room33（room 30）CODE 863（64,1152）→ 返程 room32，落点 (1888,236)。
- room33 CODE 864（960,128）→ room34（room 31），落点 (128,204)；room34 本体未进本批。
- 六张门卡字节码均含 `unlocked=1`。

## 房间与卡司（asset 精确值）

- **room31**：2048x800。shooter1×2、zombie×8、slime×3、boulder×154、coin×13、platform×6、spikes×3、treasurechest×9、woodblock×6。
- **room32**：2048x384。knifebandit×1、shooter1×1、zombie×2、shooter2×1、bat×3、slime×1、boulder×75、coin×24；无水面/宝箱。
- **room33**：1024x1280 竖井房。enemy×2、knifebandit×3、shooter1×3、fireslime×1、boulder×222、coin×18、platform×7、spikes×4、treasurechest×6、woodblock×6、pickupflare×1、boomerang×1、triggerintro×1。

本批首次出现的新物种（仅盘点，行为复用后续契约）：`obj_zombie`(19)、`obj_fireslime`(33)、`obj_pickupflare`(70)、`obj_boomerang`(71)。

## 测试

`crates/core/tests/room31_branch_ir.rs`，2 项：

- `room31_through_room33_forward_chain_is_asset_exact`：27→28→29→30 正向链路的落点、门卡目标与逐房卡司。
- `reverse_branch_returns_to_boss2_spawn_with_cast_respawn`：30→29→28→27 返程链路，断言返程落点与 zombie/bat/chest/boss2/bossboulder 卡司重新物化。

## 边界

- 本批为拓扑/卡司证据批，zombie/fireslime/boomerang/pickupflare 的行为契约未在本批建立。
- room34（room 31）本体未进本批；真机/GPU 视觉层未验收。
