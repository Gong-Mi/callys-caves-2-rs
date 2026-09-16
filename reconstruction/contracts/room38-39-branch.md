# room38-39（asset rooms 35-36）后门链第四段契约

基于 `assets/game.droid` 原始 room/object/creation-code 记录与运行时探针实测。

## 门链

- room38（asset 35，gml `room38`，2048x640）CODE 874（1984,448）→ asset room 36，落点 (160,204)。
- room38 CODE 875（64,416）→ 返 asset room 34，落点 (512,172)。
- room39（asset 36，gml `room39`，2048x704）CODE 876（64,192）→ 返 asset room 35，落点 (1888,460)。
- room39 CODE 877（1984,160）→ asset room 37，落点 (128,140)。
- room40（asset 37，gml `room40`，2048x640）门卡：CODE 878（1984,512）→ asset room 38，落点 (128,204)；CODE 879（64,128）→ 返 asset room 36，落点 (1888,172)。房体未进本批。
- 六张门卡字节码均含 `unlocked=1`。

`warproom` 使用 asset room 索引；gml 房名与 asset 索引错位 1。

## room38 卡司（运行时实测）

obj_wall(4)×115、obj_wall_2(5)×206、obj_boulder(6)×170、obj_platform(7)×1、obj_watersurface(9)×10、obj_waterfill(10)×2、obj_knifebandit(15)×1、obj_skeleton(17)×1、obj_shooter2(20)×1、obj_enemy2(22)×1、obj_bat(31)×1、obj_slime(32)×1、obj_fireslime(33)×1、obj_coin(58)×28、obj_treasurechest(100)×5、obj_woodblock(158)×4、obj_weaponswap(126)×1；UI/背景/门为系统实例。

## room39 卡司（运行时实测）

obj_wall(4)×190、obj_wall_2(5)×283、obj_boulder(6)×210、obj_platform(7)×12、obj_watersurface(9)×11、obj_waterfill(10)×3、obj_enemy(14)×1、obj_knifebandit(15)×1、obj_shooter1(16)×1、obj_hulkingbandit(21)×2、obj_wolf(23)×1、obj_slime(32)×3、obj_fireslime(33)×2、obj_coin(58)×24、obj_treasurechest(100)×4、obj_woodblock(158)×5、obj_triggerintro(186)×1、obj_weaponswap(126)×1；UI/背景/门为系统实例。

`obj_hulkingbandit`(21) 已对照 `full_ir.json` 对象表锚定。

## 测试

`crates/core/tests/room38_39_branch_ir.rs`，3 项：room38 卡司与门、room38→room39 正向全量卡司、room39→room40 门链延续。

## 边界

room40（asset 37）只进门卡断言；hulkingbandit 行为契约未在本批建立；真机/GPU 视觉层未验收。
