# Mines 首个史莱姆房与 obj_slime 双时钟模具（blob）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 一、房间与链路

rm_level11a（room 15）是 Mines 段第一个史莱姆房，也是**新模具 obj_slime**(32)
的首发地：`obj_slime`×5 + `obj_treasurechest`×7 + `obj_knifebandit`×5 +
`obj_shooter1`×1 + `obj_wolf`×1 + `obj_enemy`×1 + `obj_bat`×1。

| 门卡 | warproom | 落点 |
| --- | --- | --- |
| CODE 833（rm_level11a） | 14（回 rm_level11） | 864,172 |
| CODE 834（rm_level11a） | 16（→rm_level12） | 128,204 |

进入路径：rm_level11（14）的 CODE 832 → warproom 15，落点 (128,172)。

## 二、obj_slime(32)：与所有既有敌人不同的运动系统

1. **CODE 244 Create**：`choose(-3,3)` 决定初始巡逻方向并直接写入 `hspeed`；
   `blobjump = 45`（跳跃精灵 id，与其他对象的常量写法一致）；`alarm[0]=30`、
   `alarm[1]=40`；`hpdrop/coindrop = choose(1..5)`、`xpdrop = 1`；`jumping = 0`；
   HP 阶梯（level ≤5/≤10/≤15/≤20 × pwr 1..4）：
   **50/46/42/38、55/50/46/41、65/60/55/50、75/70/65/60**。
2. **CODE 253 Step**：HP 闸门 → `alarm[2]=0/1`（死亡）；`gravity = 0.7`、
   `gravity_direction = 270`；地面探针 `instance_place(x, y + vspeed, par_wall)`
   → `vspeed = 0`；**天花板探针** `instance_place(x, y - 3, par_wall)` → 非冻结时
   `vspeed = 0`（把上升动作压掉）；左右 ±5 探针把 `hspeed` 反向为 **∓2**（注意
   反弹后速度变成 2，与原速 3 不同）；按玩家位置镜像 `image_xscale`；
   冻结态 `image_blend = c_blue`、中毒 `c_green`、眩晕/剑眩晕切 `spr_blobhurt`(71)
   并清速度；`room == rm_ending` 时静止；精灵按 `jumping/stunned/swordstunned`
   在 `spr_blobidle`(68) 与 `spr_blobjump`(73) 间切换。
3. **两条独立跳跃时钟**：
   - **CODE 252（Alarm 0，60 帧心跳）**：着地且未冻结 → `vspeed = -5`、跳姿、
     `jumping = 1`，随后 `alarm[0] = 60` 重挂。
   - **CODE 253 扑击**：着地且未冻结且
     **`!collision_line(obj_player.x, obj_player.y, x, y, par_wall, false, false)`**
     ——即**看得见玩家**时 → `sprite_index = spr_blobjump`、`vspeed = -8`、
     `jumping = 1`。（本次首个版本把语义读反成「被墙挡住才跳」，被实测纠正：
     挡住时 Step 保持安静，看得见才扑。）
   - 两条时钟相互作用：扑击在 **Step** 相位执行，若玩家可见，同一帧会把心跳刚
     挂上的 -5 覆写成 -8；反之（玩家被墙挡住）心跳的 -5 才能保留下来。
4. **CODE 251（Alarm 1）**：`jumping = 0` 并重挂 60——清空滞空窗。
5. **CODE 254（Collision 34 / par_wall）**：`action_bounce(0, 0)`，与 Step 的
   ±5 探针构成**双保险反弹**。
6. **CODE 250（Alarm 2）死亡表**：`snd_explode`；`hpdrop == 1` → 在 **y-35**
   掉一颗心，**紧接着第二个独立的 `hpdrop == 1` 块**又在 **y-20** 掉一颗
   ——一次击杀掉**两颗心**（原版重复块，不是笔误）；`gemdropenabled` → 宝石；
   `xpdrop == 1` → 经验球（`motion_set(global.xpspread, 5)`）；银币表
   `coindrop` 1..5 → **3/5/9/10/11**（与 shooter1 的 3/5/9/8/12、
   shooter2 的 5/10/8/11/13 都不同）；末尾 `action_kill_object()`。
7. **CODE 245 Destroy**：`global.greenslimeskilled += 1`、
   `global.enemieskilled += 1`、生成 `obj_smallpuff`。

## 三、测试（`crates/core/tests/mines_slime_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `the_slime_room_opens_from_level11` | CODE 832 落点 (128,172)、卡司 32×5/100×7/15×5/16×1/23×1/14×1/31×1、门 833/834、史莱姆同属 par_enemy 父链 |
| `slime_rolls_its_own_state_and_hp_ladder` | CODE 244 八组 (level,pwr) 精确命中；`slimedirection ∈ {-3,3}` 且 `hspeed == slimedirection`；`blobjump == 45`；`jumping == 0`；`alarm[0]=30`、`alarm[1]=40`；hpdrop/coindrop ∈ 1..5 整数 |
| `the_heartbeat_hop_rearms_every_sixty_ticks` | CODE 252 直派：`vspeed == -5`、跳姿、`jumping == 1`、重挂 60；再按真实调度器验证心跳确实自行触发；CODE 251 清 `jumping` 并重挂 60，之后精灵回落 idle |
| `the_blob_pounces_at_a_visible_player_only` | 视线通畅 → CODE 253 扑击（-8 经同帧重力后为 -7.3）、跳姿、滞空；两场景都先用 `collision_line` 断言夹具的可见/遮挡状态，中间放一堵 `obj_wall` 后 Step 保持安静 |
| `the_blob_bounces_off_walls_by_probe_and_by_collision` | 右侧墙 → `hspeed` 反向为 -2；左侧墙 → 反向为 +2；重叠墙触发 Collision 34 的 `action_bounce` 后仍在运动 |
| `the_blob_sprays_double_health_and_counts_green_slimes` | CODE 250：`hpdrop==1` → **两颗心**（y-35 与 y-20，按值排序断言）、宝石 1、经验球 1、`coindrop==2` → **5 枚**银币、smallpuff 1；CODE 245 计 `greenslimeskilled`/`enemieskilled` 各 +1 |

## 四、夹具教训（写入契约以免重犯）

- **天花板探针会吃掉向上的速度**：CODE 253 在 `(x, y - 3)` 探到 par_wall 就把
  `vspeed` 归零；把史莱姆摆在任意坐标时，房间自身的遮挡瓦片会命中该探针，导致
  心跳的 -5 与扑击的 -8 都观察不到。夹具改为**先清掉本点上方会命中探针的
  par_wall（band 覆盖 -3/-5/-8/…/-32，并用跳跃精灵 73 的盒做清除）**，随后用
  原版同款的两个 builtin 断言「确实着地、确实无顶」。
- **同一帧的重力会让升速偏移 0.7**：`gravity = 0.7` 在积分阶段生效，所以 tick
  之后读到的是 -4.3 / -7.3；心跳的精确 -5 只能在**直派**（dispatch）时断言。
- **精灵切换会改变碰撞盒**：跳跃姿（73）与常态（68）盒不同，清遮挡时必须用与
  Step 同款精灵盒，否则会漏清。
- **扑击语义初版读反**（「被挡才跳」）——实测挡住时安静、看得见时 -8，已按证据
  翻转并在契约中记录。

## 五、边界

- 本批为**证据批**：零引擎改动（`choose`/`collision_line`/`instance_place`/
  `place_meeting`/`action_bounce`/`motion_set` 全走既有通道；`collision_line`
  的 7 参签名与 `notme` 语义由上一批 `297524a` 修复，本批是其第二个调用点）。
- 只实测覆盖 rm_level11a；rm_level12 起（room 16 及之后）的 slime 变体
  （`obj_fireslime`）与其他 Mines 关未施工。
- 像素级视觉（跳跃帧动画、冻结蓝色/中毒绿色的实际观感）属客户端渲染层，
  本批只断言字段、DrawCommand 与内置调用的语义。
