# rm_level3 门链纵深 + obj_bat 空中相位机契约（level3 bat air）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 关卡链

rm_level2 --CODE 807--> rm_level3（warproom=3，落点 128,140，预解锁），
与上批 level1↔level2 同机制：玩家真实踩 obj_warpanywhere(69) → CODE 13
碰撞事件 `room_goto` + 重定位 → 客户端等价泵送。rm_level3 卡司经数据驱动
加载核对：obj_bat×2（id 31，spr_bat 54 帧睡态）、obj_watersurface×59、
obj_treasurechest×6。

## obj_bat 相位机（恢复 GML + 逐帧 trace 取证）

1. **CODE 232 Create**：`sprite_index = spr_bat(66)`、`awake=0`、`moving=0`、
   `alarm[7]=30` 探测节拍、`hpfour` pwr 分档（pwr1 lvl<=5 -> 12）。
2. **CODE 234（Alarm 7 探测）**：`distance_to_object(obj_player) <= 150 &&
   obj_player.y > y` → `awake = 1`；无条件续拍 `alarm[7]=30`。
   trace：t0-28 睡（a7 30→1），t29 awake=1 且 tick 末 a7=30（发射+续拍同 tick）。
3. **CODE 242（Step）**：`awake==1 -> alarm[1]=1`；`moving==1 -> sprite=
   spr_batfly(67) + move_towards_point(player, 3)`。
4. **CODE 240（Alarm 1）**：`awake=0; sprite=spr_batawake(65); alarm[2]=1`。
5. **CODE 239（Alarm 2）**：`awake=0; moving=1`。

### trace 锁定的观测语义（不硬猜）

- 闹钟索引升序扫描：t30 同一 sweep 内 alarm[1]（CODE 240 设 alarm[2]=1）之后
  才轮到 alarm[2] → CODE 239 的 `moving=1`，随后 Step CODE 242 fly 分支把
  sprite 覆写为 spr_batfly——**tick 末观测链是 66 → (awake 1 tick) → 67**，
  spr_batawake(65) 是同 sweep 瞬态、tick 末不可见。测试按 66→67 + awake 锁存
  + alarm[7] 续拍断言，不伪造 65 的出现。
- CODE 242 在玩家 invulnerable 且 ≤50px 时清零 hspeed/vspeed（悬停）。

## 接触伤害与死亡（CODE 12 / 284 / 242 / 241 / 361）

1. **CODE 12 hitenemybat 分支**：与 hitenemy/hitenemy2 同构——health1−1、
   方位化 invulnerable+sliding1、alarm[4/7/8]=10/20/23、snd_impactsound5(24)。
2. **CODE 284 hit4 分支**：实弹扣 `hpfour`、`pistolxp += 1`、snd_impactsound2(23)、
   子弹自毁。
3. **CODE 242 → CODE 241**：`hpfour <= 0 -> alarm[0]=1`，闹钟派发死亡级联
   （snd_explode(7)、`instance_place(x,y-4,par_wall)` 门控的 health/gem/XPorb/
   coin 档、`instance_destroy()`）。
4. **CODE 361 休眠竞态（trace 决定性发现）**：dormancy sweep 用
   `instance_deactivate_object(id)`——GMS 语义作用于该 object 的**全部**实例。
   决斗 bat（距玩家 <450）因远处同类 bat 而被整组休眠：bullet t1 已消耗、
   hp 已 0、a0 已装填，但 t3 起 bat active=false、死亡停留在挂起态。
   测试用「走回巢穴」镜像 CODE 361 自己的
   `instance_activate_region(player ±400)` 再激活路径，a0 闹钟随即派发
   CODE 241 完成击杀——与原版巡逻半径内死亡必然可见的行为一致。

## 测试（`crates/core/tests/level3_bat_air_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `portal_level2_to_level3_delivers_the_bat_and_water_cast` | CODE 807 门真实踩中→room 3、落点 (128,140)、bat×2/water×59/chest×6 卡司、20 帧空跑零 dispatch 错误、health1 无损 |
| `bat_sleep_wake_fly_phase_machine_runs_from_alarm7_probe` | 睡态 66/awake=0/a7=30；玩家置于下方 100px 后 t29 awake=1 + 续拍、飞行态 67+moving=1、逐 tick 逼近 ≥5 帧（speed 3 收敛）、fly 帧窗有界 |
| `bat_contact_spends_health_then_the_bullet_finishes_it` | 接触链（health1−1/invulnerable/sliding1/alarm 4-7-8/impactsound5）→ 决斗弹 CODE 284 消耗、hpfour→0、pistolxp=1 → CODE 361 整组休眠挂起死亡 → 再激活路径下 CODE 241 击杀 + snd_explode(7) |

## 边界

- spr_batawake(65) 的瞬态仅存在于同一 tick 的 sweep 内，tick 末黑盒不可见——
  本契约记录该观测边界，测试不为其伪造断言；若未来接 sweep 内钩子可补。
- CODE 241 掉落被 `instance_place(x, y-4, par_wall)` 门控：空中无墙死亡可能
  零掉落，属原版语义；本批击杀发生在巢穴坐标，wall 门按现场 trace 通过。
- 毒/冰冻（Alarm 4/5/6、CODE 235/236/237）依赖武器态，未单测；
  真机飞行轨迹观感待真机层验收。
