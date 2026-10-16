# 碰撞宽相语义切换（WL7，2026-10-16）

把碰撞宽相从「整张精灵矩形」切到原版 `Compute_BoundingBox`（libyoyo @0x192340）
的录制 SPRT bbox 语义——关闭 WL1 在 mapview3 回程线上钉死的双读数缝（引擎读数
0.7px 假阳命中 vs 原版录制框 3.3px 间隙不命中）。

## 1. 框源（唯一实现，两域共享）

`Scene::bounds_for_instance`（`crates/core/src/ir_scene.rs`）现在返回
Compute_BoundingBox 的半开形式 `[left,right+1)×[top,bottom+1)`（SPRT 字段序
left/right/bottom/top，asset/src/lib.rs:1470 核实）：

- `mask_index >= 0` 优先于 sprite_index；
- 镜像 scale（负值）归一；
- 旋转走变换后的四角包围（原版同款近似）；
- **缺失精灵 = 整数点盒**（不再有 32×32 兜底——原版对真实精灵恒有真值，32×32
  是重写便利，见 §4 爆炸半径第 iii 类）。

共享函数 `compute_bounding_box_for_instance`（读实例字段）与
`compute_bounding_box_at`（显式位置/变换，供「候选位置」消费）；原
`distance_bounds_for_instance` 删除，FindDist 改指共享框（比较语义不变，仅
sentinel 与 wrapping_mul/sqrtf 路径照旧）。半开约定使每个消费者原有比较式
（`x>=left && x<right` 等）一字不改，唯一变量是「盒从哪来」。

## 2. 消费者清单（grep 全量枚举，无遗漏）

| 消费者 | 位置 | 语义 |
| --- | --- | --- |
| Event 4 碰撞派发 | ir_scene.rs tick 内 | 半开盒相交，命中派发 |
| Mouse_7 / Mouse_0 局部派发 | ir_scene.rs | 点命中（UI/贴片点击） |
| collision_point | host_impl.rs | inclusive 点测，prec 掩码二级门保留 |
| instance_place / place_meeting | host_impl.rs | 候选位装箱 + inclusive 边相交 |
| collision_line | host_impl.rs | 盒 vs 线（slab 触边不变），prec 路径不动 |
| mp_potential_step | host_impl.rs | 候选盒走 compute_bounding_box_at（含 mask/角度） |

**不是宽相消费者**（易误判）：CODE 361 休眠带 450px 走 distance_to_object
（本就在录制框域，此次把两域拉齐）；`enemy_instance_geometry` 是静态资产审计。

## 3. 与 distance 域的边界

同框源（Compute_BoundingBox、mask_index 优先、镜像归一、旋转四角、缺精灵=点）
之下仍保留的差异：FindDist 走 inclusive 整数间隙 + `wrapping_mul`/`sqrtf` 与
1_000_000 哨兵（原版 FindDist@0x10ac9c 语义，#37 契约）；宽相走半开盒/含边
相交；`sprite_masks` 并集兜底仅服务夹具精灵（资产注入路径）。

## 4. 爆炸半径（全量 RED 清单，release 全量实测）

11 个测试目标失败（其余全部通过，含全游戏连续通关 full_playthrough 7/7、
distance_bbox 7/7、prec 3/3 重铸后）：

| 目标 | 失败测试（示例） | 根因分类 |
| --- | --- | --- |
| core/woodblock_shattering_ir | blade_step_destroys… / logparts_die… / soundmute_suppresses… | i：刀片/木块夹具位置按整矩形校准，录制框不重叠 ⇒ CODE 274 不触发 |
| core/physics_and_motion_ir | （待重铸逐条登记） | i |
| core/mp_potential_step_avoidance_ir | （待重铸逐条登记） | i：候选盒几何换框源 |
| core/ballistics_closure_ir / bosses_3_5_ir / final_boss_ir / enemies2_batch_ir / level2_enemy2_jump_ir | （待重铸逐条登记） | i：敌我接触/命中夹具按整矩形摆位 |
| client/boss_kill_chains / bullet_combat_hit_ir / complete_combat_loop_ir | （待重铸逐条登记） | i：击杀链/命中夹具按整矩形摆位 |

分类口径：i=夹具按旧整矩形几何摆位（预期 RED，重铸夹具，不动引擎）；
ii=引擎行为耦合（须逐条审）；iii=32×32 兜底依赖（canary 期已处理
precise_collision_masks 一处；本批未见新例）。**初判全为 i 类**——待重铸时
逐条用录制框数据证实或推翻。

重铸纪律（与 WL1 一致）：从录制 bbox 数据推导摆位（先打印双方盒再摆），
不得试凑；每条重铸显式钉住所用盒；测试意图（验证什么行为）不变。
canary（the_map_open_contact_tick…）与缝测试已按 §5 重铸并通过。

## 5. canary 重铸

`the_map_open_contact_tick_hands_the_run_to_the_death_overlay_across_the_map_warp`
（#102）按 WL7 方案重铸：health1=1.0 直接注入（不再依赖接触触发），
6 tick 跨 warp 死亡层链原样钉住；新增双读数零接触守卫（(900,400) 在引擎与
录制两种读数下都必须无接触——这正是修复要守的语义）。
`the_parking_spot_gate_…` 更名为 `…_confirms_the_engine_box_seam_is_closed`：
旧缝关闭的断言 + 录制几何数据钉（y gap ≤8px）+ (428,204) 正控。

## 6. 原版忠实性边界

本切换的依据是原版 Compute_BoundingBox 的静态证据（#37 契约与 libyoyo
反汇编注释）；「切换后行为=原版行为」对 prec=0 路径成立（原版 prec=0 同样走
录制框），prec=1 掩码路径未动。逐像素与原 runner 的碰撞差分属未验层
（原设备实测）。
