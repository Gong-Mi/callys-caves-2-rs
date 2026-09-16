# room40-41（asset rooms 37-38）后门链第五段契约

基于 `assets/game.droid` 原始 room/object/creation-code 记录与运行时探针实测。

## 门链

- room40（asset 37，gml `room40`）CODE 878（1984,512）→ asset room 38，落点 (128,204)。
- room40 CODE 879（64,128）→ 返 asset room 36，落点 (1888,172)。
- room41（asset 38，gml `room41`，2048x1280）CODE 880（1984,192）→ asset room 39，落点 (128,204)。
- room41 CODE 881（64,192）→ 返 asset room 37，落点 (1888,524)。
- room42（asset 39，gml `room42`，2048x1280）CODE 882（64,192）→ 返 asset room 38，落点 (1920,204)。
- room42 CODE 883（1984,1152）→ asset room 40，落点 (160,1164)。房体未进本批。
- 六张门卡字节码均含 `unlocked=1`。

`warproom` 使用 asset room 索引；gml 房名与 asset 索引错位 1。

## room41 卡司（asset 38，运行时实测）

obj_wall(4)×181、obj_wall_2(5)×268、obj_boulder(6)×474、obj_platform(7)×3、obj_spikes(8)×50、obj_wolf(23)×1、obj_bat(31)×1、obj_slime(32)×4、obj_fireslime(33)×1、obj_coin(58)×35、obj_pickupflare(70)×1、obj_bow(78)×1；UI/背景/门为系统实例。

## room42 卡司（asset 39，运行时实测）

obj_wall(4)×335、obj_wall_2(5)×767、obj_boulder(6)×317、obj_platform(7)×4、obj_knifebandit(15)×1、obj_zombie(19)×3、obj_enemy2(22)×1、obj_ghost(24)×4、obj_slime(32)×2、obj_fireslime(33)×2、obj_coin(58)×17、obj_gem(59)×1、obj_treasurechest(100)×5、obj_lloyd(154)×1、obj_boulderblock(156)×5、obj_triggerintro(186)×1；本房无 weaponswap。

新增/关键对象 ID 已对照 `full_ir.json` 锚定：wolf=23、ghost=24、gem=59、pickupflare=70、bow=78、lloyd=154。

## 测试

`crates/core/tests/room40_41_branch_ir.rs`，3 项：room40→room41 前置链、room41 卡司与双门、room41→room42 全量卡司及 room43 门卡延续。

## 边界

room43（asset 40）只进门卡断言；ghost/bow/lloyd 行为契约未在本批建立；真机/GPU 视觉层未验收。
