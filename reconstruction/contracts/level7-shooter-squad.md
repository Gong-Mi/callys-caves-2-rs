# rm_level7 四族混编与 obj_shooter1 远程全链契约（pistol thug）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 现场卡司与链路

rm_level7（room 7）：`obj_knifebandit`(15)×1 + `obj_shooter1`(16)×1 +
`obj_wolf`(23)×1 + `obj_bat`(31)×2——第一处**地面 + 空中 + 弹道**三类同时
在场。进入沿用真实踩门：town→L1→（transition 直达 L4）→CODE 812→rm_level5
→**CODE 815**（warproom=7，落点 128,364）。

两张门卡（recovered GML 逐字）：

| CODE | 房 | warproom | 落点 |
| --- | --- | --- | --- |
| 817 | rm_level7 | 5（回 L5） | 1888,1164 |
| 818 | rm_level7 | 8（→L8） | 160,428 |

rm_level8 侧回门 819→7/(1888,140)、820→9/(128,1132)——Mines 入口在下一批。
四族 `parent_chain` 均含 par_enemy(11)，与 L1–L5 的父链多态一致。

## 机制：obj_shooter1 的六段行为

1. **CODE 58 Create —— 等级/强度双层 HP 阶梯**：
   `global.level <= 5 / <= 10 / <= 15 / <= 20` 分四档，每档按
   `global.pwr`(1..4) 取值：35/33/31/28、40/35/34/31、50/45/40/38、
   60/55/50/45。同时 `alarm[1] = 30`（首发射击节拍）、
   `coindrop = choose(1..5)`、`hpdrop = choose(0..5)`、`xpdrop = 1`。
2. **CODE 67 Step —— 巡逻、威慑与自毁闸门**：首行 `sprite_index =
   spr_pistolbandit`(114)；`hpshooter1 >= 0` → `alarm[0] = 0`，
   `<= 0` → `alarm[0] = 1`（**0 = 惰性、1 = 下一帧引爆**，是本引擎与
   GM 计数器语义的一致解释，否则开箱即死）；facing 决定 hspeed ±3 与
   image_xscale 镜像；玩家在 50px 内且处于无敌时自身 hspeed 归零；
   `image_blend` 在冻结(c_blue 16711680)与常态(c_white)间切换；
   尾行 `instance_place(x, y, obj_watersurface)` → `alarm[0] = 1`（落水自毁）。
3. **CODE 65 Alarm 1 —— 开火**：`image_xscale == 1` 时在 `(x+8, y+6)` 生成
   `obj_enemybullet`(47) 并 `hspeed = 10`；镜像侧在 `(x-8, y+6)`、`hspeed =
   -10`；两路都 `sprite_index = spr_pistolbanditfire`(115)、`alarm[2] = 10`、
   `snd_impactsound5`(24)，并把 `alarm[1]` 重置为 `choose(45,50,55,60)`。
4. **CODE 64 Alarm 2** —— 把 sprite 复位成 spr_pistolbandit；CODE 61/62/63
   分别清 swordstunned / stunned / 解冻（`image_blend -= c_white`）。
5. **CODE 66 Alarm 0 —— 死亡散射**：`snd_explode`(7)；`hpdrop == 1` 掉
   obj_health，`gemdropenabled == 1` 掉 obj_gem，`xpdrop == 1` 掉 obj_XPorb
   并以 `motion_set(global.xpspread, 5)` 喷洒；银币段受
   `instance_number(obj_silvercoin) >= 20` 全局闸门约束，否则按
   `coindrop` 1..5 撒 3/5/9/8/12 枚（各绑定 coinspread 槽位，速度 5）；
   结尾 `action_kill_object()`。
6. **CODE 59 Destroy** —— `global.pistolthugskilled += 1`、
   `global.enemieskilled += 1`、生成 `obj_smallpuff`(187)。

弹道侧 `obj_enemybullet`(47，parent 11)：CODE 313 Step 命中玩家时
`global.health1 -= 1`，按 **子弹 x 与玩家 x 的大小** 决定
`invulnerable`+`sliding1`（自右打来）或 `invulnerable2`+`sliding2`（自左），
并挂玩家 `alarm[7]=22 / alarm[4]=10 / alarm[8]=25`、`flashing = 1`、
粒子与 `snd_impactsound2`(23)；撞 `par_wall` 生成 `bulletspark` 自毁；
遇 `obj_sword` 生成 `obj_parry` 自毁。CODE 312 Alarm 0 = `instance_destroy()`。

## 两条原版「死代码」，照实保留

- **CODE 65 的开火姿势画不出来**：alarm 相位把 sprite 设成
  spr_pistolbanditfire(115)，但同一帧的 CODE 67 Step **首行**又把它写回
  spr_pistolbandit(114)，Draw 阶段看到的永远是常态姿势；因此 CODE 64
  （alarm[2] 复位）是冗余的。测试按相位断言（dispatch 后为 115，跑过一帧
  必回 114）。
- **rm_town 的水面填充穿透**（见 level6 契约）：`case rm_town` 无 break，
  最终落在 spr_waterfill。

## 测试（`crates/core/tests/level7_shooter_squad_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `portal_level5_to_level7_delivers_the_four_species_squad` | CODE 815 落点 (128,364)、卡司 15×1/16×1/23×1/31×2、四族父链含 11、`global.pwr == 1`（rm_town 的 CODE 458 生效）与 level 1 下 `hpshooter1 == 35`、两门 817→5/(1888,1164)、818→8/(160,428)、20 帧 health1=4 |
| `shooter1_hp_ladder_reads_level_and_pwr` | CODE 58 八组 (level,pwr)→HP 精确命中；(5,1..4)/(10,1)/(15,4)/(20,1)/(20,4)；删掉 `global.pwr` 后创建的同族**不写** hpshooter1——证明 rm_town 的 CODE 458 是承重件 |
| `shooter1_fires_on_its_thirty_tick_rhythm_and_the_bullet_costs_a_heart` | `alarm[1] == 30` 计时器在第 30 帧真的开火、弹速 +10；CODE 65 直派：精确 (x+8,y+6)/(-8)、`alarm[2]=10`、`alarm[1] ∈ {45,50,55,60}`、snd_impactsound5、相位内 sprite=115 而跑帧后回 114；CODE 313 单帧结算：health1 4→3、invulnerable/sliding1、玩家 alarm 7/4/8 = 22/10/25、snd_impactsound2 |
| `shooter1_sprays_its_death_loot_and_counts_the_kill` | CODE 66 直派：hpdrop/gem/xp 各 1、coindrop 3 → 9 枚银币、1 个 smallpuff、XP 球方向 == global.xpspread 且 speed 5、银币各自绑定真实 coinspread 槽位且 y = y-35；`pistolthugskilled`/`enemieskilled` 各 +1（fresh start 均未预置，读 0 → 1） |
| `the_twenty_silvercoin_cap_suppresses_the_coin_tier` | 预置 20 枚 obj_silvercoin 后 coindrop 5（12 枚档）整段被 `instance_number >= 20` 闸门压掉，但怪照常死亡 |
| `water_kills_the_shooter_through_its_own_alarm_zero` | CODE 67 尾行落水探测 arm alarm[0]=1 → 两帧内自毁，且 CODE 59 计数照常 |
| `the_second_door_hands_over_to_level8` | CODE 818 落点 (160,428)、rm_level8 卡司 14×3/15×8/23×1 无 shooter1、两门 819→7/(1888,140)、820→9/(128,1132) |

## 施工中的自纠

- 隔离夹具首版把**所有**非玩家/非目标实例搬走，连 18 片水面一起搬到
  (6000,6000)——落水自毁测直接失效；改为只隔离 `ENEMIES`(15/16/23/31)；
- 死亡散射原先走 alarm 计时器路径，弹速读出 4.7 而非 5（同帧已完成一次
  `friction 0.3` 积分）；改为**直派 CODE 66** 断言原始 motion_set 值，
  计时器路径单独由落水测试覆盖；
- 「开火姿势」初版断言 115，实测 114：按相位修正为「alarm 相位内 115、
  跑帧后 114」，并如实记录成原版死代码；
- XP 球方向首版用 `==` 比较，实测差 2e-14：`motion_set` 之后速度积分会
  用 hspeed/vspeed 反算 direction，改为 1e-9 容差并写明原因；
- 弹道命中相位原为 3 帧循环，可能被同批其它子弹先消耗；改为清空弹道后
  **单帧**夹具断言（health1 出栈前先断 4）。

## 边界

- 本批同为**证据批**：零引擎改动。`choose`、`alarm[]`、`instance_create`、
  `motion_set`、`with`、`instance_place`、`distance_to_object`、
  `instance_number`、`action_kill_object`、`part_*`、`image_blend -=` 全部
  走既有通道；
- CODE 58 的 `global.level > 20` 分支不存在——原版等级上限由 obj_UI
  (CODE 368) 封在 20，超出档位不写 HP（本批只验证 1..20 八组代表值）；
- `obj_sword` 格挡分支（CODE 313 首段）依赖剑术升级链，未在本批铺开；
- rm_level8（14×3/15×8/23×1）已按门卡与卡司侦察，未施工。
