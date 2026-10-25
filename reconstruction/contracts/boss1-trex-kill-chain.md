# Boss 1 全链击杀契约（obj_trex kill chain）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 原版机制（恢复 GML 证据）

真实 `rm_boss1`（room 10）逐帧字节码驱动，无手写 Boss 逻辑：

1. **CODE 154 obj_trex Create**：pwr 分档 HP（pwr1=275/pwr2=225/pwr3=150/pwr4=100），
   `boss1maxhp` 同步；巡逻闹钟 `alarm[2]=80`、`alarm[3]=100`；
   `xpdrop=1`、`hpdrop=1`、`coindrop=choose(1..5)`。
2. **CODE 161 Step**：`hptrex<=0 -> alarm[0]=1`（下一 tick 闹钟派发）；
   `facing==0 -> hspeed=-3 / facing==1 -> hspeed=+3` 巡逻；落地检测
   （`instance_place(x,y+1,par_wall)`）控制 gravity 0.6/0；玩家过界转向。
3. **CODE 284 obj_bullet Step（trex 分支，源码第 179 行起）**：
   `instance_place` 命中 → `flashing=1`、粒子、`hspeed=0`、按武器全局伤害扣
   `hptrex`、生成 obj_damage、`global.pistolxp += 1`、`snd_impactsound2`、
   消耗子弹（`canhit` 单次锁）。
4. **CODE 160 Alarm 0 死亡级联**：`snd_explode`（7）→ `global.boss1dead = 1`
   → gemdropenabled 生成 obj_gem、hpdrop 生成 obj_health、xpdrop 生成 10 颗
   obj_XPorb（motion_set 按 coinspread* 散射）、coindrop 档位 5..30 银币 →
   `action_kill_object()`。
5. **CODE 29 obj_bossboulder Alarm 0**：每 30 帧检查 `global.boss1dead == 1`
   → `instance_destroy()` 开门（前批已验收的封门对偶面）。
6. **动画周期联动**（sprite-animation-advance.md）：Boss 行走精灵
   （spr_bear 56）在巡逻中帧号持续推进且有界。

## 测试（`crates/core/tests/boss1_trex_kill_chain_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `trex_create_alarms_and_patrol_run_from_real_bytecode` | CODE 154 初值（275/275/80/100）；CODE 161 左巡逻 hspeed=-3 与 x 递减；40 帧巡逻中 image_index ≥20 次推进、始终 `< image_number` |
| `bullets_kill_trex_and_death_cascade_opens_the_gate` | 玩家 CODE 11 实弹 25px/帧 → CODE 284 trex 分支消耗、hptrex 1→0、flashing、pistolxp=1 → CODE 161 装填 alarm[0] → CODE 160 死亡级联（boss1dead=1、snd_explode、gem/health/10×XPorb/银币档、action_kill_object 实体移除）→ CODE 29 巨石 31 tick 内全部销毁 |

关键纪律：`global.pistoldamage` 每步被玩家 CODE 12 从武器等级重算（1.0），
测试不预置假数值，用真实 1 伤子弹斩杀 `hptrex=1` 的 Boss，与原版逐帧语义一致。

## 边界

- obj_trex 的 CODE 161 巡逻与 Alarm 2/3 转向在本批以 hspeed/x/帧窗行为取证；
  毒（Alarm 6/CODE 156）与剑眩晕（Alarm 5/CODE 157）已直派 alarm 覆盖：
  `trex_alarm6_poisons_and_spawns_a_damage_cloud`（poisoned=1、hptrex−0.25、
  alarm[6]=30、在 Boss 坐标生成 obj_damage(104) 且 damage=0.25）与
  `trex_alarm5_clears_sword_stun`（swordstunned 1→0）。两条都驱动真实字节码，
  不是手写逻辑；武器池只负责**武装**这两个 alarm，武装链本身仍未单测。
  已定位到一条真实的武装路径（**修正前一版"无跨实例写"的错误结论**：IR 里
  `selector == 0` 就是 `other`，不是没有这类写）：`CODE 308
  gml_Object_obj_energywave_Step_0` 的 `instance_place` 链包含 obj_trex(25)，
  命中块（≈指令 45–72）做的是 `i = instance_create(x, y, 104)`、`i.damage = 3`、
  `(hit).stunned = 1`、`(hit).alarm[4] = 10`、`canhit = 1`——注意它是
  **stunned + alarm[4]**，与剑族的 `swordstunned + alarm[5]` 是两套标志。
  毒仍无着落：全库没有任何跨实例 `poisoned` 写（只有敌人自己 Create 清零、
  Alarm 6 置 1），所以首发毒要么走 alarm[6] 的跨实例写（本次扫描未命中），
  要么在 engine 侧。下一批直接驱动 CODE 308 对 trex 的命中块写夹具，
  并继续找 `(hit).alarm[6]`。
- Android 真机 Boss 战视觉与音效验收仍需单独一轮（CI 绿≠真机已验）。
