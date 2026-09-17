# room46-49（asset rooms 43-46）后门链第七段契约

基于 `assets/game.droid` 原始 room/object/creation-code 记录与运行时探针实测（`full_ir.json` CODE 名 `gml_RoomCC_room46_890_Create` 等确认 gml 房名）。

## 门链

- room46（asset 43，gml `room46`）CODE 890 → asset room 44，落点 (1120,76)。CODE 891 → 返 asset room 42，落点 (128,524)。
- room47（asset 44，gml `room47`）CODE 892 → asset room 45，落点 (128,204)。CODE 893 → 返 asset room 43，落点 (128,204)。
- room48（asset 45，gml `room48`）CODE 894 → 返 asset room 44，落点 (1152,524)。CODE 895 → asset room 46，落点 (128,108)。
- room49（asset 46，gml `room49`）CODE 896 → 返 asset room 45，落点 (1408,684)。CODE 897 → asset room 47，落点 (128,140)。房体未进本批。
- 八张门卡（CODE 890-897）字节码均含 `unlocked=1`。

`warproom` 使用 asset room 索引；gml 房名与 asset 索引错位 1（room46=asset43）。

## room46 卡司（asset 43，运行时实测）

obj_lloyd(154)×1、obj_treasurechest(100)×3、obj_boulder(6)×104；**无 obj_wall/obj_wall_2**（特殊剧情房）。

## room47 卡司（asset 44，运行时实测）

obj_wall(4)×107、obj_wall_2(5)×87、obj_boulder(6)×112、obj_platform(7)×8、obj_watersurface(9)×32、obj_waterfill(10)×1、obj_enemy(14)×1、obj_knifebandit(15)×2、obj_skeleton(17)×1、obj_zombie(19)×1、obj_enemy2(22)×1、obj_bat(31)×1、obj_coin(58)×24、obj_treasurechest(100)×3、obj_boulderblock(156)×3。

## room48 卡司（asset 45，运行时实测）

obj_wall(4)×110、obj_wall_2(5)×134、obj_boulder(6)×323、obj_spikes(8)×57、obj_knifebandit(15)×2、obj_hulkingbandit(21)×2、obj_ghost(24)×2、obj_slime(32)×1、obj_coin(58)×20、obj_pickupflare(70)×1、obj_rocketlauncher(75)×1、obj_boulderblock(156)×4。火箭筒取得房。

## room49 卡司（asset 46，运行时实测）

obj_wall(4)×43、obj_wall_2(5)×10、obj_boulder(6)×170、obj_watersurface(9)×12、obj_waterfill(10)×1、obj_knifebandit(15)×2、obj_hulkingbandit(21)×1、obj_bat(31)×2、obj_coin(58)×12、obj_treasurechest(100)×1、obj_boulderblock(156)×2。

## 测试

`crates/core/tests/room46_49_branch_ir.rs`，4 项：room45→room46 前置链与 Lloyd 房卡司、room46→room47 卡司与双门、room47→room48 卡司（含水/尖刺/火箭）、room48→room49 卡司与门卡延续。

## 边界

room50（asset 47）房体未进本批；skeleton/lloyd/hulkingbandit/rocketlauncher 行为契约不在本批；真机/GPU 视觉层未验收。
