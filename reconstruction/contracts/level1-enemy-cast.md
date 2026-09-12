# rm_level1 obj_enemy 巡逻/接触伤害/弹杀契约（level1 enemy cast）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 现场盘点（真实房间数据）

rm_level1（room 1）1,341 实例的敌人组成为 obj_enemy(14) x5 +
obj_knifebandit(15) x2——前批 H 线只覆盖了 knifebandit；本批补 obj_enemy。
obj_spider/obj_bearcub 不是实体（仅 intro 演出对象），bat/wolf 在更深层房间。

## 原版机制（恢复 GML 证据）

1. **CODE 40 Create**：pwr 分档 `hp`（level<=5 且 pwr1 -> 10）、
   `xpdrop=1`、`coindrop/hpdrop = choose(1..5)`。
2. **CODE 47 Step**：`hp<=0 -> alarm[0]=1`；落地检测 gravity 0.6/0；
   `facing==0 -> hspeed=4 / facing==1 -> hspeed=-4`（image_xscale 同步镜像）；
   前向/悬崖探测在 5px 与 ±27px 处 `instance_place(obj_wall/obj_boulder/obj_platform)`
   翻转 facing（巡逻不坠崖）。
3. **CODE 12 接触伤害分支（hitenemy）**：
   `instance_place(x,y,obj_enemy) != -4 && facing==0 && invulnerable==0 &&
   invulnerable2==0 && global.rebuff != 1` →
   `flashing=1; global.health1 -= 1;` 按 `hitenemy.x > x` 分别武装
   `invulnerable+sliding1`（敌在右）或 `invulnerable2+sliding2`（敌在左）；
   闹钟 `alarm[4]=10`（击退滑行动画窗口）、`alarm[7]=20`（sprite 复原）、
   `alarm[8]=23`（无敌窗口解除）；派发 `snd_impactsound5`（SOND 24）。
   x 相等是原版自身边界（两分支都不武装，只扣血）。
4. **CODE 284 obj_bullet Step（obj_enemy 分支）**：扣 `global.pistoldamage`、
   `pistolxp += 1`、粒子/flashing/snd_impactsound2/子弹自毁。
5. **CODE 46 Alarm 0 死亡级联**：snd_explode、掉落（hpdrop/gemdropenabled/
   xpdrop/coin 档 <20 gate）、`action_kill_object()`。
6. **CODE 361 休眠域**：距玩家 ≥450px 的 obj_enemy 每 15 帧被
   `instance_deactivate_object`——测试选最近敌人并保持 active，冻结期帧号
   不推进（动画引擎契约的既有语义）。

## 施工中的真实修正（调试 example 取证，非猜测）

- 首版三断言全 RED：远处敌人 t4 被 CODE 361 休眠（active_ticks 4/40）→
  改用最近敌人并断言 active ≥30；
- 同 x 放置命中原版 `x>` 与 `x<` 双排除边界（inv=0/0）→ 敌右移 2px 走
  invulnerable+sliding1 分支；
- 接触伤害与射击共存：子弹决斗场景中玩家保持原版 `invulnerable=1` 态，
  health1 不被 CODE 12 扣除（3.0 vs 4.0 差异根因是接触分支先扣血），
  远程决斗断言「扣血为 0」必须建立在原版自身无敌机制上，不伪造标志位。

## 测试（`crates/core/tests/level1_enemy_cast_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `obj_enemy_patrols_with_step_gravity_and_animation` | 5 实例卡司；hp=10；40 帧 hspeed ∈ {4,-4,0}、≥20 位移 tick、active ≥30、image_index 始终 `< image_number` |
| `player_enemy_contact_costs_health_and_arms_knockback_chain` | health1 -1；flashing；invulnerable+sliding1；alarm[4/7/8]=10/20/23；impactsound5(24)；后续 8 帧无敌期不双扣 |
| `bullet_enemy_hit_branch_leads_to_death_cascade` | CODE 11 实弹 25px/帧；hp 1→0；pistolxp=1；≤5 tick 内 CODE 46 移除实体；snd_explode(7)；XPorb + 至少一档掉落；全程玩家 health1 不变 |

## 边界

- 悬崖探测的 facing 翻转由巡逻位移+hspeed 集合间接取证，未逐帧钉死转向时机；
- 毒（Alarm 6/CODE 42）/剑眩晕/冰冻（hpfrozen）分支依赖武器池，未单测；
- Android 真机接触伤害手感（击退距离/闪烁节奏）视觉验收仍待单独一轮。
