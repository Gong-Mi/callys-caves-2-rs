# room36-37（asset rooms 33-34）后门链第三段契约

基于 `assets/game.droid` 的原始 room/object/creation-code 记录与运行时探针实测。

## 门链（门实例位置 ↔ creation code ↔ 落点）

- room36（asset room 33，gml `room36`，2048x800）CODE 870（门自身 1984,672）→ asset room 34，落点 (128,1932)。
- room36 CODE 871（64,192）→ 返程 room35（asset room 32），落点 (1888,236)。
- room37（asset room 34，gml `room37`，640x2048 竖井房）CODE 872（门自身 576,160）→ asset room 35，落点 (128,428)。
- room37 CODE 873（64,1920）→ 返程 room36，落点 (1888,684)。
- room38（asset room 35）门卡（进入后实测）：CODE 874（1984,448）→ asset room 36，落点 (160,204)；CODE 875（64,416）→ 返程 room37，落点 (512,172)。房体未进本批。
- 六张门卡字节码均含 `unlocked=1`。

`warproom` 使用 asset room 索引；gml 房名编号 = asset 索引 + 3（见 room_bindings，第八段契约实测；旧版误记为错位 1）。

## room36 卡司（运行时实测，object id 对照 full_ir.json 对象表）

obj_wall(4)×231、obj_wall_2(5)×313、obj_boulder(6)×296、obj_platform(7)×3、
obj_watersurface(9)×17、obj_waterfill(10)×4、obj_shooter1(16)×1、obj_skeleton(17)×1、
obj_zombie(19)×5、obj_enemy2(22)×1、obj_bat(31)×2、obj_slime(32)×1、obj_fireslime(33)×2、
obj_coin(58)×22、obj_treasurechest(100)×7、obj_boulderblock(156)×5、obj_woodblock(158)×5、
obj_weaponswap(126)×1、UI 族（125/127/128/129/130/131/133）各×1、obj_bg(65)×1、obj_UI(66)×31、obj_muting(67)×1、门×2。

## room37 卡司（640x2048 竖井房，运行时实测）

obj_wall(4)×156、obj_wall_2(5)×282、obj_boulder(6)×294、**obj_spikes(8)×6**、
obj_watersurface(9)×9、obj_waterfill(10)×3、obj_knifebandit(15)×1、obj_shooter1(16)×2、
obj_skeleton(17)×1、obj_shooter2(20)×3、**obj_wolf(23)×1**、obj_bat(31)×1、
obj_coin(58)×24、UI 族各×1、obj_bg(65)×1、obj_UI(66)×32、obj_muting(67)×1、门×2。

room37 无宝箱/无 weaponswap 之外的可拾取物；spikes 首次进入后门链段。

## 测试

`crates/core/tests/room36_37_branch_ir.rs`，3 项：

- `room36_cast_matches_asset_and_doors_are_unlocked`：CODE 869 进入的落点 (160,204)、全量卡司、双门值。
- `room36_to_room37_forward_chain_is_asset_exact`：CODE 870 → room37 落点 (128,1932)、全量卡司（竖井房+spikes）、双门值。
- `room37_to_room38_door_chain_continues`：CODE 872 → room38 落点 (128,428)，断言 CODE 874/875 门值已就位。

## 边界

- 本批为拓扑/卡司证据批；enemy2(22) 首次出现在后门链段（行为契约已有 level2 批），wolf/shooter2 复用既有契约。
- room38（asset room 35）只进门卡断言，全量卡司与房体推进未进本批。
- 真机/GPU 视觉层未验收。
