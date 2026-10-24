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
| collision_point | host_impl.rs | inclusive 点测；prec=1 时追加掩码像素门 |
| instance_place / place_meeting | host_impl.rs | 候选位装箱 + inclusive 边相交 |
| collision_line | host_impl.rs | 盒 vs 线（slab 触边不变）；prec=1 走掩码线采样（2026-10-24） |
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

| 目标 | 失败测试（示例） | 根因分类 | 重铸要点（实测盒推导） |
| --- | --- | --- | --- |
| core/woodblock_shattering_ir | blade_step_destroys… / logparts_die… / soundmute_suppresses… | i（WL7b 已修提交） | 刀片/木块夹具接真实 SPRT 框并按 x+hspeed 探针重摆 |
| core/physics_and_motion_ir | （collision_line notme 探针） | i（WL7b 已修提交） | 墙体按整数点盒摆位 |
| core/mp_potential_step_avoidance_ir | （躲避夹具） | i（WL7b 已修提交） | 候选盒几何换框源后墙位按盒推导 |
| core/ballistics_closure_ir | blade_sparks… / boomerang… / energywave_walls… / arrow_sticks… | i（本批） | 接线+墙位移；arrow_sticks 边界从原点距（旧接线点盒兜底）改录制盒距：箭盒 [306,327) 整数右边 326、玩家盒左边 x−6，间隙=x−332，x=348 恰 16 死 / x=347=15 活（实测探针校核） |
| core/bosses_3_5_ir | boss3_projectiles… / boss4_ladder_chase… | i（本批） | boss4 盒 115×120，x±10 探针盒 [220,345)/[240,355)；墙 (350,260) 只命中 x+10 探 ⇒ hspeed=−2（原期望）；墙在 boss 正下方会双探命中翻成 +2 |
| core/final_boss_ir | laser_hits_once… / laser_parry… / grenade… | i（本批） | 激光墙死：激光盒 [293,307)×[198,202)，旧双侧 32×32 默认盒互叠是接线缺口产物；墙 x 320→305（盒重叠 2px） |
| core/enemies2_batch_ir | fireslime_rolls… | i（本批） | 接线即绿：fireblob 落地墙探在录制框下重命中 |
| core/level2_enemy2_jump_ir | enemy2_jump_cycle… | i（本批） | 补 bbox/masks 接线；节奏按实测重导：t15/t90 两次发射（75 tick 周期），观测窗 90→150 |
| client/boss_kill_chains | boss2/3/4/5_kill… | **i（夹具摆位，父代裁决）** | 裸 transition 进 rm_boss2(1280×480) 停在 y=494 界外，旧整矩形盒与地板行 1px 假重叠兜住；录制语义坠落→CODE 361 休眠带挂 boss→击杀链断。进房钉位（x 夹取、y≤h−80、速度清零）重力自沉降。裁决依据：连续通关真实走门击杀全绿=引擎无恙 |
| client/bullet_combat_hit_ir | player_bullet_spawn… | i（本批） | 刀匪录制框 [x−16,x+13) + 每 tick 右移 4px ⇒ 命中 tick 4→5 |
| client/complete_combat_loop_ir | complete_combat_loop… | i（本批） | 同上机制，命中窗 4→5 tick |

**终判：11 目标全部 i 类（夹具按旧整矩形几何摆位/接线缺口），无 ii 类引擎异常。**
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

## 7. instance_place / place_meeting 的掩码差距（2026-10-24 静态定位）

`collision_line` / `collision_point` 的 `prec=1` 已在 wl63 落地（掩码表由
`dump_sprites_c` 从 SPRT 记录生成：178 sprites / 227 frames / 341 KB 位图；
C 与 Rust 双侧同一套 `mask_probe`，并有 95 条 C 断言）。**但
`instance_place` / `place_meeting` 仍只走录制框**，这是当前最大的玩法保真缺口
（全库 599 + 50 个调用点，67 个 body）。

原版路径（libyoyo ARMv7，SHA256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`）：

```
Command_InstancePlace      @0x1ca6d8   (800 B)
  → CInstance::Collision_Instance @0x195558 (884 B)
      → CSprite::PreciseCollision @0x1e4298 (1944 B)
          → CSprite::UnpackWADMask @0x1e3994
```

`PreciseCollision` 的结构（静态读，未运行；旋转分支尚未读定）：

1. 双方对各自 frame 调 `UnpackWADMask`；frame 先对 mask 数（`[sprite+0x3c]`）取模。
2. 两个 `tagYYRECT` 求交：left=max、right=min、top=max、bottom=min。
3. 对交区内每个整数像素 `(x, y)`，分别映射到 A/B 的掩码坐标：

       mask = (int)( base + inv_scale * (world - offset) )     // vcvt.s32 截断，不是 floor

   `base` 取 `[sprite+0x24]` / `[sprite+0x28]`，宽高 `[sprite+0x1c]` / `[sprite+0x20]`，
   掩码字位在 `[sprite+0x40] + frame*8` 表项里；越界即视为该像素不命中。
4. 两个掩码位同时为 1 → 命中；否则继续扫描。

结论与纪律：

* 当前 bbox-only 是**有名有据的近似**，不能写成"原版也这样"。
* 移植前必须先把 `base`/`offset` 的确切定义与旋转分支读定（本循环内没有三角函数项，
  旋转是否另走分支尚未证），再实现；用"盒重叠、掩码不重叠"的合成夹具证明行为变化。
* 只做 C↔VM 对账不能证明这一步：两侧同时改成同一个错误实现也会全绿。原 runner 的
  同输入对拍（或 Unicorn 合成内存 oracle）才是这一步的判据。
