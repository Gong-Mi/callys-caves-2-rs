# room52-55（asset rooms 50-53）Boss3 后门链第九段契约

基于 `assets/game.droid` 原始记录与运行时探针实测；gml 房名以 `room_bindings.room_name` 为准：asset50=room52、asset51=room53、asset52=room54、asset53=room55（偏移 +2——rm_boss3 打断后规律，见 room68-71-branch.md 更正；本段无 boss 房插入）。

## 门链

- room52（asset 50）CODE 904 → 返 asset room 49，落点 (1920,332)。CODE 905 → asset room 51，落点 (128,140)。
- room53（asset 51）CODE 906 → 返 asset room 50，落点 (640,268)。CODE 907 → asset room 52，落点 (128,204)。
- room54（asset 52）CODE 908 → 返 asset room 51，落点 (480,1484)。CODE 909 → asset room 53，落点 (128,204)。
- room55（asset 53）CODE 910 → 返 asset room 52，落点 (1760,1164)。CODE 911 → asset room 54，落点 (128,140)。房体未进本批。
- 八张门卡（CODE 904-911）均 8 指令、字节码含 `unlocked=1`。

## room52 卡司（asset 50，运行时实测）

obj_wall(4)×46、obj_boulder(6)×260、obj_coin(58)×16；**无 obj_wall_2**（负断言）、无 chest、无敌人——巨石阵走廊房。

## room53 卡司（asset 51，运行时实测）

obj_wall(4)×127、obj_wall_2(5)×214、obj_boulder(6)×226、obj_platform(7)×14、obj_knifebandit(15)×1、obj_shooter1(16)×1、obj_zombie(19)×2、obj_ghost(24)×2、obj_bat(31)×2、obj_fireslime(33)×2、obj_coin(58)×15、obj_gem(59)×3、obj_pickupflare(70)×1、obj_icegun(81)×1、obj_boulderblock(156)×3。冰枪取得房。

## room54 卡司（asset 52，运行时实测）

obj_wall(4)×434、obj_wall_2(5)×579（全游戏最重墙体房）、obj_boulder(6)×259、obj_platform(7)×2、obj_spikes(8)×16、obj_knifebandit(15)×1、obj_firehulk(18)×2、obj_hulkingbandit(21)×2、obj_enemy2(22)×1、obj_wolf(23)×1、obj_bat(31)×1、obj_slime(32)×1、obj_coin(58)×13、obj_gem(59)×1、obj_treasurechest(100)×6、obj_boulderblock(156)×3、obj_iceblock(159)×2。

## room55 卡司（asset 53，运行时实测）

obj_wall(4)×77、obj_wall_2(5)×53、obj_boulder(6)×151、obj_spikes(8)×14、obj_knifebandit(15)×1、obj_skeleton(17)×1、obj_hulkingbandit(21)×1、obj_ghost(24)×1、obj_coin(58)×18、obj_pickupflare(70)×1、obj_spikegun(72)×1、obj_lloyd(154)×1。尖刺枪 + Lloyd 剧情房。

## 本批新钉定对象 ID（对照 full_ir.json objects）

gem=59、spikegun=72、icegun=81。

## 测试

`crates/core/tests/room52_55_branch_ir.rs`，4 项：逐房全量卡司 + 双门断言，链尾 room55→asset54 门卡延续。

## 边界

asset54（gml room56）房体未进本批；icegun/spikegun 武器取得链、firehulk/iceblock/gem 行为契约未建立；真机/GPU 视觉层未验收。
