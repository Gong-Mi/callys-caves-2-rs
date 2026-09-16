# room34-35（asset rooms 31-32）Boss2 后门链第二段契约

基于 `assets/game.droid` 的原始 room/object/creation-code 记录与运行时探针实测。

## 门链（门实例位置 ↔ creation code ↔ 落点）

- room34（asset room 31，gml `room34`，1600x800）CODE 865（门自身 1536,160）→ asset room 32，落点 (128,268)。
- room34 CODE 867（64,192）→ 返程 room33（asset room 30），落点 (896,140)。
- room34 CODE 866：`obj_weaponswap`(126) 的 creation code，**空体**（零指令，start==end）。
- room35（asset room 32，gml `room35`，2048x480）CODE 868（64,256）→ 返程 room34，落点 (1440,172)。
- room35 CODE 869（1984,224）→ room36（asset room 33），落点 (160,204)。
- room36（asset room 33，gml `room36`，2048x800）CODE 870（1984,672）→ room37（asset room 34，落点 128,1932，房体未进本批）；CODE 871（64,192）→ 返程 room35（1888,236）。
- 八张门卡字节码均含 `unlocked=1`。

注意：gml 房名与 asset 索引从本段起错位 1（gml room34 = asset 31）。CODE 865 的 `warproom=32` 是 asset 索引直写，非 gml 房名。

## room34 卡司（运行时实测，object id 对照 full_ir.json 对象表）

obj_wall(4)×134、obj_wall_2(5)×327、obj_boulder(6)×181、obj_platform(7)×3、
obj_enemy(14)×3、obj_knifebandit(15)×2、obj_zombie(19)×2、obj_fireslime(33)×4、
obj_coin(58)×15、obj_treasurechest(100)×13、obj_boulderblock(156)×3、obj_woodblock(158)×4、
obj_weaponswap(126)×1、UI 族（125/127/128/129/130/131/133）各×1、obj_bg(65)×1、obj_UI(66)×29、obj_muting(67)×1、门×2。

## room35 卡司（进入时实测）

obj_wall(4)×103、obj_wall_2(5)×10、obj_boulder(6)×119、obj_platform(7)×23、
**obj_watersurface(9)×62、obj_waterfill(10)×3**、obj_skeleton(17)×2、obj_bat(31)×1、obj_fireslime(33)×2、
obj_coin(58)×19、**obj_gem(59)×1**、obj_treasurechest(100)×1、obj_triggerintro(186)×2、
weaponswap(126)×1、UI 族各×1、obj_bg(65)×1、obj_UI(66)×30、obj_muting(67)×1、门×2。

## 测试

`crates/core/tests/room34_35_branch_ir.rs`，3 项：

- `room34_cast_matches_asset_and_doors_are_unlocked`： CODE 864 进入 room34 的落点 (128,204)、全量卡司、双门值。
- `room34_to_room35_forward_chain_is_asset_exact`： CODE 865 → room35 落点 (128,268)、全量卡司（含水域瓦片）、双门值。
- `room35_to_room36_door_chain_continues`： CODE 869 → room36 落点 (160,204)，断言 CODE 870/871 门值已就位。

## 边界

- 本批为拓扑/卡司证据批；skeleton/gem 的行为契约未在本批建立（skeleton 首次进入 Mines 后门段）。
- room36（asset room 33）只进门卡断言，全量卡司与房体推进未进本批。
- 真机/GPU 视觉层未验收。
