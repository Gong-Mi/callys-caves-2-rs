# room43-45（asset rooms 40-42）后门链第六段契约

基于 `assets/game.droid` 原始 room/object/creation-code 记录与运行时探针实测。

## 门链

- room43（asset 40，gml `room43`，1024x1280）CODE 884（960,160）→ asset room 41，落点 (128,204)。
- room43 CODE 885（64,1152）→ 返 asset room 39，落点 (1888,1164)。
- room44（asset 41，gml `room44`，2848x384）CODE 886（64,192）→ 返 asset room 40，落点 (864,172)。
- room44 CODE 887（2784,192）→ asset room 42，落点 (128,204)。
- room45（asset 42，gml `room45`，1536x640）CODE 888（64,192）→ 返 asset room 41，落点 (2656,204)。
- room45 CODE 889（64,512）→ asset room 43，落点 (576,204)。房体未进本批。
- 六张门卡字节码均含 `unlocked=1`。

`warproom` 使用 asset room 索引；gml 房名编号 = asset 索引 + 3（见 room_bindings，第八段契约实测；旧版误记为错位 1）。

## room43 卡司（asset 40，运行时实测）

obj_wall(4)×232、obj_wall_2(5)×224、obj_boulder(6)×187、obj_platform(7)×13、obj_shooter1(16)×1、obj_zombie(19)×2、obj_ghost(24)×2、obj_bat(31)×1、obj_slime(32)×1、obj_fireslime(33)×1、obj_coin(58)×23；UI/背景/门为系统实例。

## room44 卡司（asset 41，运行时实测）

obj_wall(4)×176、obj_wall_2(5)×308、obj_boulder(6)×165、obj_hulkingbandit(21)×3、obj_enemy2(22)×5、obj_bat(31)×1、obj_slime(32)×2、obj_coin(58)×13；UI/背景/门为系统实例。

本房无 treasurechest。
## room45 卡司（asset 42，运行时实测）

obj_wall(4)×130、obj_wall_2(5)×151、obj_boulder(6)×251、obj_platform(7)×1、obj_knifebandit(15)×1、obj_enemy2(22)×3、obj_bat(31)×3、obj_slime(32)×1、obj_fireslime(33)×2、obj_coin(58)×10；UI/背景/门为系统实例。

## 测试

`crates/core/tests/room43_45_branch_ir.rs`，3 项：room43→room44 前置链与全量卡司、room44→room45 全量卡司、room45→room46 门卡延续。

## 边界

room46（asset 43）房体未进；ghost/hulkingbandit 行为契约未在本批建立；真机/GPU 视觉层未验收。
