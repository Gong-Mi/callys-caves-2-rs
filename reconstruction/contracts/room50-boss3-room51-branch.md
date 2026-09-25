# room50 / rm_boss3 / room51（asset rooms 47-49）后门链第八段契约

基于 `assets/game.droid` 原始 room/object/creation-code 记录与运行时探针实测；gml 房名以 `full_ir.json` `room_bindings` 的 `room_name` 字段为准（不再按偏移猜）：asset47=`room50`、asset48=`rm_boss3`、asset49=`room51`。

## 门链

- room50（asset 47）CODE 898 → asset room 48（rm_boss3），落点 (128,108)。CODE 899 → 返 asset room 46，落点 (512,908)。
- rm_boss3（asset 48）CODE 900 → 返 asset room 47，落点 (992,620)。CODE 901 → asset room 49，落点 (128,300)。
- room51（asset 49）CODE 902 → 返 asset room 48，落点 (1152,364)。CODE 903 → asset room 50，落点 (128,268)。房体未进本批。
- 六张门卡（CODE 898-903）均 8 条指令、字节码含 `unlocked=1`。

## room50 卡司（asset 47，运行时实测）

obj_wall(4)×221、obj_wall_2(5)×217、obj_boulder(6)×245、obj_platform(7)×8、obj_enemy(14)×1、obj_zombie(19)×2、obj_shooter2(20)×1、obj_hulkingbandit(21)×3、obj_wolf(23)×1、obj_ghost(24)×1、obj_slime(32)×2、obj_coin(58)×40、obj_treasurechest(100)×5、obj_boulderblock(156)×2。Boss3 前哨大房（本段卡司最重）。

## rm_boss3 卡司（asset 48，运行时实测）

obj_boss3(27)×1、obj_bossboulder(3)×18、obj_triggerintro(186)×1、obj_wall(4)×76、obj_wall_2(5)×182、obj_boulder(6)×85；**无 coin/chest/普通敌人**（纯 Boss 竞技场，与 rm_boss1/rm_boss2 同款结构）。

## room51 卡司（asset 49，运行时实测）

obj_wall(4)×201、obj_wall_2(5)×318、obj_boulder(6)×179、obj_platform(7)×2、obj_watersurface(9)×24、obj_waterfill(10)×1、obj_firehulk(18)×2、obj_zombie(19)×1、obj_enemy2(22)×1、obj_slime(32)×2、obj_coin(58)×28、obj_treasurechest(100)×7、obj_iceblock(159)×3、obj_triggerintro(186)×1。

## 房名映射更正（重要）

`room_bindings` 实测：asset30 起 gml `roomNN` 编号 = asset 索引 + 3（asset30=room33 … asset47=room50，asset49=room51），且 **boss 房以 `rm_bossN` 名插入编号序列**（asset48=rm_boss3 打断 roomNN 序列）。此前第六/七段契约中「gml 房名与 asset 索引错位 1」的表述是错的（room46=asset43 偏移为 3），已在第七段契约更正。门卡引用一律用 asset room 索引。

## 测试

`crates/core/tests/room50_52_branch_ir.rs`，3 项：room50 全量卡司+双门、rm_boss3 Boss 竞技场卡司（boss3×1、bossboulder×18、triggerintro×1、无 coin/chest 负断言）、room51 firehulk/iceblock 卡司与门卡延续。

## 边界

asset50（gml room52）房体未进本批；boss3/firehulk/iceblock/triggerintro 行为与击杀链契约未建立（boss1/boss2 击杀链测试是模板）；真机/GPU 视觉层未验收。
