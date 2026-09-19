# obj_iceblock (159) 融化行为契约

CODE 687 (Create) / 688 (Step) / 689 (Collision 35 = obj_flame) 三条全部经字节码在本引擎宿主实测后固化。

## 机制

- Create：`melting=0`、`type=1`。`type` 是**写而不读的死字段**——全 GML 语料无任何 `obj_iceblock.type` 读取（grep 0 命中），契约只钉原始值。
- 唯一融化触发器：与 obj_flame 碰撞（CODE 689 一行 `melting=1`），经活 tick 路径验证（Step-before-Collision 派发序使 tick-1 只置位、不衰减）。
- Step 守卫：`melting==1` 时双轴 scale 每帧 −0.1；未融化时步进完全不碰 scale（负对照 30 tick 验证）。

## 硬浮点发现（本宿主实测）

销毁守卫是严格 `image_xscale == 0`，而衰减是 double 链：1.0 → 0.9 → 0.8 → 0.7000000000000001 → … → 第 10 个递减值 1.3877787807814457e-16（永不精确为 0）→ 负值。**融化的冰块永远不会被自身收缩销毁**——30 tick 后 scale≈−0.3 仍存活。点火火焰自身在第 9 tick 经 alarm[0]=9→CODE 269 销毁，融化状态在无火后持续。此语义与原版 GMS 浮点一致（同 IEEE754 链），不是移植缺陷。

## 测试

`crates/core/tests/iceblock_melting_ir.rs` 4 项：Create 原值+死字段、活 tick 点火、完整 12+18 tick 衰减链逐帧 IEEE 精确断言（含火焰死亡窗口 t>=9）、未融化负对照 30 tick。夹具按纪律：玩家保持 active 到火焰 Create（CODE 268 读 obj_player.facing 走选择器过滤 alive+active）后 park。

## 边界

- 引擎近似为包围盒碰撞（全批同口径），prec 像素检查未实现。
- iceblock 作为推箱阻挡物的语义存在于 obj_leftbutton/rightbutton Alarm 1（CODE 529/532 `instance_place(..., obj_iceblock)` 七连否决），但推箱机制本身未入引擎——该障碍语义待推箱批次一并建立。
- room60×3/room61×2/room62×2 的卡司密度已在 room60-63 契约固化；真机/GPU 视觉层未验收。
