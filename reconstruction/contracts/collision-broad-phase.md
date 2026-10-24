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
| instance_place / place_meeting | host_impl.rs | 候选位装箱 + inclusive 边相交；两侧都有掩码且未旋转时追加逐像素掩码门（2026-10-24） |
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
C 与 Rust 双侧同一套 `mask_probe`，并有 98 条 C 断言）。2026-10-24 起
`instance_place` / `place_meeting`（全库 599 + 50 个调用点，67 个 body）也在
**两侧都有掩码且未旋转**时走逐像素掩码门：先求录制框交集，再在交集内逐像素
映射到两张掩码、两边都为 1 才算命中；无掩码数据的一侧仍由录制框决定（对应
runner 的 `[sprite+0x31] == 0` 分支）。**旋转仍是缺口，但路径已读**：轴对齐快速
路径（@0x1e4484 起，scale==1）没有三角函数；一般分支（@0x1e47a8）对两个角度分别
调用 `sinf`/`cosf`，再按

    mask_x = base_x + ( dx·cosA − dy·sinA ) / sx
    mask_y = base_y + ( −dx·sinA − dy·cosA ) / sy

进入同一套截断采样（符号按"实参取了负角"解读，仍需 oracle 确认）。当前旋转实例
在两侧都回退到盒子判定，不得声称已支持。

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

### 7.1 独立佐证：GM8Emulator 的碰撞笔记（不同引擎世代，只作结构参照）

`Adamcake/Legacy-GM8Emulator` 的 notes.txt 记录的 GM8 精确碰撞流程与我们读到的
GMS1.4 结构一致，且补上了两处我们尚未钉死的细节：

* AABB 由旋转后的四角求 min/max；四条失败条件是 `(self.right+1) <= other.left`
  这类**包含边**比较，与我们的 inclusive 盒一致。
* 精确阶段：取两个 AABB 交集里的每个**整数**像素，分别在两张掩码的坐标系里
  "反旋转 → 反缩放 → 查位"，两边都有像素才算命中——与我们实现的顺序相同。
* 两处我们**当前没有对齐**的细节：
  1. 旋转中心是 `FISTP(x), FISTP(y)`（银行家舍入），而我们现在直接用未取整的
     x/y；
  2. 反旋转/反缩放后的取整：GM8 笔记写 floor，本二进制反汇编是 `vcvt.s32`
     （向零截断）。两者只在负坐标上不同，未定。
* 掩码基址：GM8 用掩码自身的 bbox 偏移；我们用 sprite origin。字段级来源
  （`[sprite+0x24]/+0x28`）尚未证到具体语义。

结论不变：axis-aligned 路径已接、C↔VM 全绿；但要宣称"等于原版"，必须先确定
上面三点，最好用 Unicorn 合成内存 oracle 直接对拍 `0x1e4298`。

### 7.2 oracle 前置事实（为 Unicorn 合成内存准备）

* `CSprite::UnpackWADMask` @0x1e3994 的第一条判断是 `[sprite+0x31] != 0` → 直接
  返回。所以 oracle 可以预先造好掩码表并把 +0x31 置 1，不必实现 WAD 解包。
* 解包后的掩码是**每像素一字节**（查位：`[bits + row*width + col]`），与资产里
  位压缩的 `CollisionMask`（0x80>>x%8）只是存储差异，占位语义相同；对拍时不要
  把两种存储当成两种规则。
* 调用点 `CInstance::Collision_Instance` @0x1957ac 的实参布局可直接照着造：
  YYRECT 内嵌在 instance 的 +0xe8/+0xec 附近，r0..r3 与栈槽 0、4、8、12、16、20、
  24、28、32、36、40、44 依次是 spriteA/frame/rectA/…/spriteB/frame/rectB/…。
  具体寄存器—参数对应仍需逐条读，但不必从签名猜。

### 7.3 Unicorn oracle：三处细节已由原函数判定

工装：`c-recon/tools/oracle/precise_oracle.py`（Unicorn 2.1.4 映射 libyoyo
ARMv7，`CSprite::PreciseCollision` @0x1e4298 直接调用）。踩过的必要件：
VFP 需先写 CPACR=0x00F00000 与 FPEXC=0x40000000，否则 `vpush` 报非法指令；
`sinf`/`cosf` 走 PLT（0xb6580/0xb658c），GOT 未重定位，须在 Python 里按
softfp（实参/返回值都在 r0）接管；掩码表 `[sprite+0x40]` **直接**指向帧条目
数组（条目 +4 是位图指针），不能再套一层指针；`[sprite+0x18] > 0` 是序言
早退门，`[sprite+0x31]=1` 让 UnpackWADMask 立即返回。

用原函数判定的事实：

1. **取整是截断**：把世界像素 −1 映射到局部 −0.5（scale 2）时命中第 0 列，
   只有 `vcvt.s32`（向零）能做到；floor 会落到 −1 越界。
2. **base 是掩码偏移**：`base_x=1` 使同一世界像素从命中变不命中，说明基址直接
   加到掩码列上。
3. **旋转方向**：掩码像素 local (row 0, col 4) 在 +90° 时落到世界 (0, −4)，
   在 −90° 时落到 (−1, 4)（后者含 float32 三角噪声的一位偏移）。由此
   `world = (c·lx + s·ly, −s·lx + c·ly)`，即
   `local = (c·dx − s·dy, s·dx + c·dy)`；旋转中心是调用方已经 `vcvt.s32`
   过的整数 x/y，不是原始小数。

随机对拍：`c-recon/tools/oracle/random_differential.py`（8–16 px 随机掩码、
位置 ±10、scale ∈ {0.5,1,2}、角度 ∈ {0,±90,45}，共 200 例）——**200/200 一致**。

对拍过程中还钉出一条**路径相关的边界语义**（首版只差这一条）：
旋转分支先对"未截断"的局部值做 `[0, dim)` 比较（`vcmpe` + `bmi`），
所以局部 −0.5 会被拒绝；轴对齐分支先 `vcvt.s32` 再比较，−0.5 截成 0 反而命中。
`debug_mismatch.py` 用 1×1 探针逐像素定位到这条差异（A 侧、x=−8、y=9..13）。

据此本轮已修并在两侧打开：`MaskCtx` / `mask_probe_pixel` 全部改用 **float32**
（与原函数一致，f64 会在掩码边界翻一位），旋转符号、旋转中心 `trunc(x/y)`、
截断与"旋转分支浮点边界检查"都按 oracle 结果实现；
`instance_place` / `place_meeting` 的旋转路径已启用（不再是回退）。
