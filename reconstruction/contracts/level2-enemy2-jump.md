# rm_level2 obj_enemy2 跳跃蛛 AI 契约（enemy2 jump cycle）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 原版机制（恢复 GML + 现场 trace 取证）

obj_enemy2（id 22，spr_enemy2 12 帧，parent par_enemy(11)）——rm_level2 唯一
专属敌人（卡司 obj_enemy2×1，前批 portal 链已核对）：

1. **CODE 123 Create**：`alarm[2]=15` 起跳节拍；pwr1 档 `hptwo=40`；
   `xpdrop=1`、`coindrop/hpdrop=choose(1..5)`。
2. **CODE 130（Alarm 2）**：`distance_to_object(obj_player) <= 192 &&
   jumping == 0` → `jumping=1; alarm[1]=1`，否则清 jumping；两种结局都重新
   `alarm[2]=15` 续拍。
3. **CODE 131（Alarm 1 发射）**：落地时（`instance_place(x,y+1,par_wall)`）按
   玩家方位 `move_towards_point(obj_player.x, obj_player.y - 15, 4)` +
   `vspeed = -8` + `sprite_index = spr_spiderattack(61)` + `alarm[7]=60`。
4. **CODE 133（Step）**：`hptwo<=0 -> alarm[0]=1`；落地 gravity 0.6/0；
   非跳跃态恢复 `sprite_index = spr_enemy2`；`x+hspeed` 前向墙探测清零
   hspeed（空中被墙钉住——trace 实测 t19 起 hspeed≈0 而 vspeed 继续抛物线）。
5. **CODE 125（Alarm 7 复位）**：`jumping=0; sprite_index=spr_enemy2`。
6. **CODE 12 hitenemy2 分支**：与 hitenemy 同构——`health1 -= 1`、方位化
   invulnerable/sliding、`alarm[4/7/8]=10/20/23`、snd_impactsound5(24)。
7. **CODE 284 hit2 分支**：扣 `global.pistoldamage` → `hptwo`、`pistolxp+=1`、
   snd_impactsound2(23)、子弹自毁。
8. **CODE 132（Alarm 0 死亡级联）**：snd_explode(7)、gemdropenabled 生成 gem、
   hpdrop 生成 health、xpdrop 生成 XPorb（xpspread 散射）、coin <20 gate
   档位银币、`action_kill_object()`。

### 现场 trace 锁定的观测语义（不硬猜）

- 闹钟循环先于 dispatch 递减：CODE 131 设置 `alarm[7]=60` 的同一 tick 观测值为
  59；因此断言用「发射 tick alarm[7] ∈ (20,60)」而非钉死 60。
- 运动积分吃掉发射脉冲一帧：`vspeed = -8` 当 tick 末观测 -7.4；发射检测用
  「本 tick vspeed 相对上 tick 突降 >6.5」的脉冲判据。
- 192px 内的跳跃瞄准角 (−100,−15) 给 hspeed≈−3.96；落墙后 CODE 133 前向探测
  把 hspeed 归零，vspeed 继续抛物——两轮发射（launches≥2）+ 中间回落行走精灵
  （walk_gap）才是完整循环证据。

## 测试（`crates/core/tests/level2_enemy2_jump_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `enemy2_jump_cycle_arms_launches_and_resets_attack_sprite` | hp=40/alarm[2]=15 初值；90 tick 内 ≥2 次脉冲发射（vspeed 突降、alarm[7] 60 窗口）；两轮发射间回落到行走精灵（CODE 133/125）；alarm[2] 续拍；全程帧号有界（1 帧攻击精灵被单帧钉住） |
| `player_enemy2_contact_costs_health_with_the_hitenemy2_branch` | health1−1、flashing、右侧 invulnerable+sliding1、alarm[4/7/8]=10/20/23、impactsound5(24) |
| `bullet_enemy2_kill_runs_the_code132_cascade` | CODE 11 实弹 ≤4 tick 命中 hptwo 1→0、pistolxp=1、≤6 tick 内 CODE 132 移除实体、snd_explode(7)、XPorb+gem(gemdropenabled=1)+hpdrop/coin 档、玩家 health 零损耗 |

## 边界

- 跳跃的水平位移量依赖落点墙面几何，本批断言脉冲与相位而不钉轨迹坐标；
- CODE 126 毒续拍（hptwo -= 0.25）、CODE 129（Alarm 3）、CODE 127/128 依赖
  poisoned/stunned 武器态，未单测；
- 真机观感（跳跃节奏、attack 精灵单帧闪烁感）待真机层验收。
