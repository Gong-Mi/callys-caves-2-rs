# rm_level6 宝库房与宝物箱七表契约（chest vault）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 现场卡司与链路

rm_level6（room 6）：**零敌人**，14 个 `obj_treasurechest`(100) + 53 片
`obj_watersurface`(9) + 1 个 `obj_waterfill`(10)，唯一出口是 CODE 816 回门。
进入方式沿用真实踩门：town→L1→（transition 直达 L4，与 wolf/mixed 两批同构）
→CODE 812 门→rm_level5→CODE 814 门（warproom=6，落点 1856,1164）。

门卡事实（recovered GML 逐字）：

| CODE | 房 | warproom | 落点 |
| --- | --- | --- | --- |
| 814 | rm_level5 | 6（本批入口） | 1856,1164 |
| 816 | rm_level6 | 5（唯一出口） | 128,1164 |

rm_level5 的三张卡 813/814/815 = 回 L4 / 本房 / →L7，所以本批是 L5 之后的
第一个真实支线房，回来后 L5 卡司原样恢复（2 enemy / 2 wolf）。

## 机制：宝物箱是「两个对象」而不是一个

1. **obj_treasurechest(100)** —— CODE 449 `chestcontents = choose(1,2,3,4)`、
   CODE 450 `vspeed=0; hspeed=0`、CODE 451 与玩家碰撞即
   `instance_create(x, y, obj_treasurechestopen); instance_destroy();`。
2. **obj_treasurechestopen(102)** —— CODE 455 **重新** `chestcontents =
   choose(1..7)` 并 `alarm[0] = 20`；CODE 456 是七张掉落表；CODE 457 每帧
   把自身速度归零（弹开的盖子不动）。

**原版怪癖（照实保留，不修）**：开箱对象从不读取箱体的 `chestcontents`，
所以 CODE 449 的 1..4 掷点是死数据；CODE 456 的表覆盖 1..7，其中 5/6/7
是箱体永远掷不出来的——这是原版的两段独立掷点，不是移植缺陷。

## 七张掉落表（CODE 456 逐字清点）

| 表 | 银币 | 宝石 | 补血 | 全部 `motion_set(global.coinspreadN, spd)` |
| --- | --- | --- | --- | --- |
| 1 | 9 | 2 | 0 | coinspread…11 + 2 个 coinspread8/9，speed 5 |
| 2 | 1 | 1 | 1 | **唯一混速表**：coinspread23(8) / coinspread2(5) / coinspread25(8) |
| 3 | 7 | 2 | 0 | coinspread…8 全 8，且第 9 个是原版唯一字面量 `motion_set(90, 5)` |
| 4 | 3 | 1 | 1 | coinspread/2/3/5/6，speed 8/8/5/5/5 |
| 5 | 5 | 2 | 1 | coinspread…8 |
| 6 | 6 | 1 | 1 | coinspread…8 |
| 7 | 2 | 1 | 2 | 唯一双补血表；coinspread/2/3/7/8 |

掉落坐标固定在箱体 `(x±20, y-64 \| y-35)` 两行；七张表都**不含** XP 球。

## 方向源：CODE 371 的三十个全局

七表的方向全部来自 `global.coinspread`…`coinspread25`（无 coinspread1）与
`global.xpspread`…`xpspread5`——共 30 个，由每个房间都携带的
`obj_muting`(67) Create（CODE 371）用 `random_range(0,180)` 一次性掷出。
本批断言该播种真实发生（30 个键、值域 [0,180)），而不是让未定义全局读 0
把整表打成「朝正右手飞」。

## 附加验证：CODE 35 的 switch 穿透

`obj_waterfill` Create 是 `switch (room)`，编译成 110 个**数字** case
（房间索引，不是名字）。原版源码 `case rm_town:` 后**没有 break**，字节码
实测为：case 0 存 spr_lavafill(100) → 直接落进 case 1 存 spr_waterfill(103)
→ break。于是 rm_town 最终拿到的是**水面**贴图。测试按字节码断言：
room 0 → 103（穿透）、room 6 → 103、room 28（room31 熔岩区）→ 100。

## 测试（`crates/core/tests/level6_chest_vault_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `portal_level5_to_level6_lands_in_the_chest_vault` | CODE 814 落点 (1856,1164)、14 箱且每箱 1..4、0 敌人、箱体无 par_enemy 父链、唯一门 816→5/(128,1164)、53 水面 + 1 水面填充、20 帧 health1=4 |
| `chest_lid_pops_into_the_opener_and_arms_its_timer` | CODE 451 在原坐标生成开箱实体、CODE 455 掷 1..7 并 alarm[0]=20、CODE 457 归零速度、**由计时器**（非手工 dispatch）触发炸表并移除自身 |
| `every_one_of_the_seven_tables_sprays_its_original_payload` | 七表逐表：银币/宝石/补血精确直方图、无额外实体、掉落落在 (x±20, y-64\|y-35)、方向精确等于某个 coinspread 全局（表 3 第 9 个为字面量 90）、speed 只允许 5/8、hspeed/vspeed 由 motion_set 三角换算出；表 2 另比对三条 (x 偏移, coinspread 槽位, speed) 精确元组 |
| `muting_create_seeds_the_thirty_spread_globals_the_tables_use` | CODE 371 播种 25 coinspread + 5 xpspread，值域 [0,180) |
| `vault_loot_is_real_currency_the_player_collects` | 表 3 的 7 枚银币被玩家 Step 拾取扫描消费，score 增量 = 4 × 实际拾取枚数（type 3 × coinmultiply） |
| `waterfill_picks_its_sprite_from_the_room_switch_with_the_original_fallthrough` | CODE 35 穿透语义：room 0→103、room 6→103、room 28→100 |
| `the_single_return_door_walks_back_into_level5` | CODE 816 回 rm_level5 落点 (128,1164)、L5 卡司 2/2 原样恢复、落点 10 帧 health1=4 |

## 施工中的自纠

- 首版把「掉落 y 偏移」写成按对象类型（银币 y-64／其余 y-35），表 3 立刻
  RED：原版表 3 的**宝石**也在 y-64（`x-6, y-64` / `x+8, y-64`）。改为断言
  「偏移 ∈ {64, 35} 两行」并保留表 2 的精确元组；
- 首版把「方向必须等于某个 coinspread」写成无条件，表 3 第 9 个是原版唯一
  字面量 `motion_set(90, 5)`——按字节码放行并显式记录；
- 首版用 `s.globals["score"]` 读分（本仓库 score 是 Scene 共享字段，
  `read/write` 才把它投影成实例变量），改 `s.score`；
- 首版断言「拾取只吃一枚」，实测玩家站位覆盖整片散射（±11px 内互相重叠），
  一次扫描全收 7 枚——改为断言 `score 增量 = 4 × 实际死亡枚数`，保留原版
  per-instance 扫描语义而非按帧限流。

## 边界

- 本批为**证据批**：宝库房与七表全程零引擎改动，全部走既有 IR/字节码通道
  （choose、alarm[]、instance_create、motion_set、with、switch 穿透、
  global 读取、碰撞派发）；
- 开箱后的掉落物水面溶解、水面致死、货币拾取细节已在 enemy-death-drops /
  water-hazard / combat-loop 三批验收，本批只做一次箱→币→分的端到端串联；
- rm_level6 的 14 箱具体位置不在契约内（房数据即事实），测试按「离水面最远」
  排序选靶，避免武器/掉落被 53 片水面溶解干扰；
- rm_level7（knifebandit/shooter1/wolf/bat 混编 + obj_shooter1 远程链）已侦察，
  未在本批施工。
