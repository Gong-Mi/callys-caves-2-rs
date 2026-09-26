# Mines 段 obj_shooter2 远程模具与 collision_line 参数缺口（trap gunner）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 一、本批唯一的**引擎修复**：`collision_line` 参数个数

原版 `obj_shooter2` Alarm 1（CODE 108）以 **7 参**调用：

```
if (!collision_line(x, y, obj_player.x, obj_player.y, par_wall, true, true))
```

而 VM 的 `expected_argc` 表把 `collision_line` 登记为 **5 参**（与
`collision_point` 同组），调用时直接返回
`collision_line: expected 5 args, got 7` 并在 alarm 相位抛错——即进入
rm_level10 后该枪手一开火就进错误边界。

修复（`crates/core/src/ir_scene.rs`）：

1. `expected_argc` 由 5 改为 **7**（GMS 签名 `collision_line(x1,y1,x2,y2,obj,prec,notme)`）；
2. 实现里解析 `a[5]`(prec) 与 `a[6]`(notme)：`notme` 真实生效（决定调用者自身
   是否可被判中，原先无条件排除）；`prec` 被接受并在注释里显式声明——本 host
   的**所有**碰撞查询（`collision_point`/`instance_place`/`place_meeting`/
   `collision_line`）都是包围盒语义，不做像素级掩膜检查。

**这是一处真实缺陷，不是测试写法问题**：修复前该 alarm 在任何路径下都无法执行。

同一类缺陷随后由新加的审计脚本又查出**两处**（详见第五节）：`ads_disable`
被 obj_poisoniap Other_66 以 1 参调用、`shop_leave_rating` 被 obj_firstpause
Create 以 4 参调用，而两者在表里都登记为 0 参——**暂停菜单/设置屏一创建就会
抛错**。两处都是平台桩（本客户端无广告、无评分面板），因此改为**接受任意
参数并返回 0**，而不是去猜 SDK 的真实签名。

## 二、obj_shooter2(20)：与 shooter1 完全不同的表

| 维度 | obj_shooter1(16) | **obj_shooter2(20)** |
| --- | --- | --- |
| HP 阶梯（level ≤5/≤10/≤15/≤20 × pwr 1..4） | 35/33/31/28、40/35/34/31、50/45/40/38、60/55/50/45 | **50/45/40/35、54/49/44/39、65/61/57/53、70/65/60/55** |
| 首发节拍 | `alarm[1] = 30` | **`alarm[1] = 60`** |
| 开火条件 | 仅 facing | **facing + 视线**：`!collision_line(x, y, player.x, player.y, par_wall, true, true)`，被墙挡住则**整轮不开火**，但节拍照常重挂 `choose(30,45,60,75)` |
| 枪口 | `(x±8, y+6)`，弹速 ±10，`alarm[2]=10` | **`(x±5, y+11)`**，弹速 ±10，`alarm[2]=1`、`alarm[6]=8` |
| 弹丸 | obj_enemybullet(47) | **obj_enemybullet2(48)**（Step 伤害契约与 47 相同） |
| 银币表（coindrop 1..5） | 3/5/9/8/12 | **5/10/8/11/13**（更肥） |
| 击杀计数 | `pistolthugskilled` | **`trapskilled`**（另加 `enemieskilled`） |
| 朝向 | facing 由墙探测决定 | **每帧朝玩家**（`if (obj_player.x >= x) facing = 0`） |
| 开场音符 | snd_impactsound5 | **snd_fire**(10) |

XP 掉落分档：`xpdrop 1 → 1 球`、`2 → 2 球`（第二球用 `global.xpspread2`），
死亡总表仍受 `instance_number(obj_silvercoin) >= 20` 全局闸门约束。

## 三、原版死代码（本批新增证据）

`obj_enemybullet`(47) 的 CODE 312（Alarm 0）与 `obj_enemybullet2`(48) 的
CODE 314（Alarm 3）都是 `instance_destroy()` 自毁计时器，但**全仓 1,354 份
CODE 里只有两处会生成敌弹**（CODE 65 / CODE 108），且两处都只写
`i1.hspeed`，**从未**给弹丸挂任何 alarm——即「弹丸寿命」是死代码，弹丸只由
撞墙（生成 `obj_bulletspark`）、被 `obj_sword` 格挡（生成 `obj_parry`）或命中
玩家而消失。测试按 `alarms[3] == -1` 断言该计时器始终未被挂起。

## 四、Mines 前段拓扑（房间编号）

| 编号 | 房间 | 门卡 |
| --- | --- | --- |
| 11 | rm_level9 | 826→12 (224,140) / 825→10 (1120,364) |
| 12 | rm_level9a | 827→**13** (1888,172) / 828→11 (1920,204) |
| 13 | rm_level10 | 829→12 (128,1164) / 830→**14** (160,1164) |
| 14 | rm_level11 | 831→13 (1888,492) / 832→**15 (rm_level11a)** (128,172) |

rm_level10 卡司：`obj_shooter2`×4 + `obj_wolf`×4 + `obj_knifebandit`×2 +
`obj_bat`×1（**全房无 obj_shooter1**）；rm_level11 则换回 `obj_shooter1`×1。

## 测试（`crates/core/tests/mines_shooter2_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `the_mines_chain_opens_from_level9_through_level11` | 11→12→13→14 真实踩门：rm_level9a 卡司 14×2/15×4/23×2 + 宝箱 + 门 827/828；rm_level10 卡司 20×4/23×4/15×2/31×1 且无 16，门 829/830；rm_level11 卡司 16×1 且无 20，门 831/832 |
| `shooter2_hp_ladder_is_its_own_table` | CODE 100 八组 (level,pwr) 精确命中自身阶梯；房内枪手以 level1/pwr1 = 50 生成且 `alarm[1] == 60` |
| `shooter2_fires_only_with_line_of_sight` | 先按线段（Liang-Barsky）清掉夹具射线上的 par_wall 并断言**确实清掉了**；视线通畅 → CODE 108 在 `(x+5, y+11)` 生成弹二、`alarm[2]=1`、`alarm[6]=8`、节拍 ∈ {30,45,60,75}、snd_fire、弹自毁计时器未挂；中间放一堵 `obj_wall` → **整轮无弹**且节拍照常重挂；拆墙后恢复开火；facing 1 → `(x-5, y+11)`、hspeed -10 |
| `bullet_two_costs_a_heart_like_bullet_one` | CODE 315 单帧夹具：health1 4→3、`invulnerable`+`sliding1`、玩家 alarm 7/4/8 = 22/10/25、snd_impactsound2 |
| `shooter2_death_spray_has_xp_tiers_and_counts_traps` | CODE 109：xpdrop 2 → 两球（分别挂 `xpspread`/`xpspread2`）、hpdrop→补血、gemdropenabled→宝石、coindrop 2 → **10 枚**银币、y-35 落点、snd_explode；CODE 101 计 `trapskilled` 与 `enemieskilled` 各 +1 并留 smallpuff |

## 施工中的自纠

- 首版把 `coindrop 2` 按 shooter1 的惯性写成 5 枚，实测 10 枚——逐字重读
  CODE 109 后确认 trap gunner 自带更肥的银币表，并把差异写进契约；
- 「视线通畅」夹具最初直接摆在房内任意坐标，被 rm_level10 自带墙体挡住而
  误判为机制失败——改为先按线段清除该射线上的 par_wall 并**断言确实清过**，
  再验证机制；
- `alarm[2] == 0` 的「未开火即无姿势」断言在直派（非 tick）路径下读到上一轮
  残留的 1——改为先显式清零再断言，并补一条恢复开火后 `alarm[2] == 1`。

## 边界

- `prec = true` 的像素级精确检查在本 host 未实现（与既有全部碰撞查询一致，
  统一按包围盒）；这是**显式声明的近似**，不是遗漏；
- 本批只覆盖 rm_level9a/10/11 三房与 shooter2 的远程链；rm_level11a 的
  **obj_slime**(32) 新模具已在队列中；
- 弹丸命中判定沿用既有包围盒夹具，未做真机/GPU 视觉验收。

## 五、配套产线加固：`scripts/audit_builtin_arity.py`

既有 CI 只做**名字**覆盖审计（`audit_builtin_coverage.py`，99/99 通过），因此
「名字在表内但参数个数不对」这一类缺陷可以完整地溜过绿灯。新增
`scripts/audit_builtin_arity.py`：

1. 从恢复字节码里读出**每条 `call` 指令自己记录的 `argc`**（GMS 字节码在
   call 上直接带参数个数，无需推断栈深度）；
2. 用行级解析从 `crates/core/src/ir_scene.rs` 的 `expected_argc` match 块提取
   「名字 → Some(N)/None」表；
3. 逐名比对，报 `MISMATCH`（表里 N 与原版实参不符）与 `UNSUPPORTED`
   （原版调用但表里没有的名字），任一非空即 exit 1。

结果：**原版 99 个不同 builtin、100 条表项**，修复后全绿；把引擎换成修复前
的版本（`git show HEAD:...`）立即报出三条 `MISMATCH`——`collision_line`
（5 vs 7）、`ads_disable`（0 vs 1）、`shop_leave_rating`（0 vs 4），即本批三
处真实缺陷的回归证明。

CI 挂载：`.github/workflows/reverse-code.yml` 在既有名字审计之后新增
`Audit original builtin call arities against VM dispatch` 步骤，并把
`scripts/audit_builtin_arity.py`、`crates/core/src/ir_scene.rs`、
`crates/core/src/generated/full_ir.json` 加入 path 过滤——以后改引擎分发表
或重生成 IR 都会自动跑这条审计。

同时修正既有夹具 `crates/core/tests/physics_and_motion_ir.rs`：它此前按旧的
5 参形式调用 `collision_line`，在签名修正后会假红；现按真实 7 参签名调用，
并补齐 `notme` 双向断言（`notme = 1` 排除调用者自身、`notme = 0` 允许命中
自身）。
