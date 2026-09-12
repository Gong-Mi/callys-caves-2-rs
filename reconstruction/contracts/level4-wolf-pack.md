# rm_level4 obj_wolf 地面狼群契约（wolf pack）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 现场卡司

rm_level4（room 4）：obj_bat×2（批 5 已覆盖其相位机）+ obj_wolf(23)×2——
本批补狼群。rm_level5~8 卡司经 dump 盘点（enemy/bandit/wolf 混编，同模具）。

## 原版机制（恢复 GML 取证）

obj_wolf 与 obj_enemy2 同一字节码模具、狼型几何：

1. **CODE 135 Create**：pwr1 档 `hpwolf=40`、`alarm[2]=15` 节拍、
   xpdrop=1、choose 档掉落、spr_wolf(106) 12 帧。
2. **CODE 143 Step**：`hpwolf<=0 -> alarm[0]=1`；落地重力 0.6/0；
   facing 强制 `hspeed=±4` + `image_xscale` 镜像；深 20px 前向墙/岩探测与
   40px 悬崖探测翻转 facing；≤50px 且玩家无敌时 hspeed=0（对峙）；
   `stunned==1 -> sprite_index = choose(spr_wolfhurt(105), spr_wolf(106));
   vspeed=0`——随机但值域封闭，测试断言定义域而非样本。
3. **CODE 12 hitwolf 分支**：hitenemy 家族同款（health1−1、方位化
   invulnerable+sliding1、alarm[4/7/8]=10/20/23、impactsound5/24）。
4. **CODE 284 hitwolf 分支 → CODE 142 死亡级联**：hpfour 家族字段名
   `hpwolf`、pistolxp 反哺、snd_explode(7)、gemdrop/hpdrop/xpdrop/coin
   <20 档位、instance_destroy。
5. **CODE 361 休眠域**：远处狼群 deactivate，测试取最近狼。

## 测试（`crates/core/tests/level4_wolf_pack_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `wolf_patrol_and_stunned_choice_follow_the_original_mold` | 卡司×2；hp=40、a2=15、sprite=106/image_number=12；40 tick hspeed ∈{4,-4,0}、≥20 位移、active≥30、帧窗有界；置 stunned 后 6 tick sprite 恒 ∈{105,106} |
| `wolf_contact_costs_health_and_the_bullet_finishes_the_pack` | 接触链五件套+impactsound5(24)；决斗弹 CODE 284→143→142：击杀、pistolxp≥1、总 health 消耗恰为 1（仅战前接触）、snd_explode(7)、XPorb+档位掉落 |

## 边界

- choose() 随机样本不断言，断言封闭值域（引擎 rng_seed 固定但序列不锁死）；
- CODE 137~141（Alarm 3~7 毒/眩晕/冰冻续拍）依赖武器态未单测；
- 与 level1/2/3 敌人共同构成「四关敌人行为矩阵」，5~8 关混编复用同模具，
  未逐关再铺。
