# obj_iceblock (159) 融化行为契约

CODE 687 (Create) / 688 (Step) / 689 (Collision 35 = obj_flame) 三条全部经字节码在本引擎宿主实测后固化。

## 机制

- Create：`melting=0`、`type=1`。`type` 是**写而不读的死字段**——全 GML 语料无任何 `obj_iceblock.type` 读取（grep 0 命中），契约只钉原始值。
- 唯一融化触发器：与 obj_flame 碰撞（CODE 689 一行 `melting=1`），经活 tick 路径验证（Step-before-Collision 派发序使 tick-1 只置位、不衰减）。
- Step 守卫：`melting==1` 时双轴 scale 每帧 −0.1；未融化时步进完全不碰 scale（负对照 30 tick 验证）。

## 浮点与比较（修正）

衰减是 double 链：tick 1 因 Step-before-Collision 只置位；tick 2..10 从 1.0 逐次减 0.1，得到 0.9 → 0.8 → 0.7000000000000001 → … → 0.10000000000000014。tick 11 第十次递减得到 `1.3877787807814457e-16`，并非精确 0。**但销毁守卫不是硬件精确相等**：CODE 688 的 `cmp` 是 DoSet K=3；`reconstruction/contracts/value-model.md` 记录 DoSet 的实数比较采用 ±1e-05 容差。因此该正值比较为“等于 0”，CODE 688 在 tick 11 调用 `instance_destroy()`。此前“严格 `image_xscale == 0`、永不销毁”的解释遗漏了共享比较算子的容差，现以指令级比较契约修正。点火火焰仍在第 9 tick 经 alarm[0]=9→CODE 269 销毁。

## 测试

`crates/core/tests/iceblock_melting_ir.rs` 4 项：Create 原值+死字段、活 tick 点火、tick 1..10 衰减链逐帧 IEEE 精确断言（含火焰死亡窗口 t>=9），tick 11 near-zero 值按 DoSet K=3 容差触发销毁，以及未融化负对照 30 tick。夹具按纪律：玩家保持 active 到火焰 Create（CODE 268 读 obj_player.facing 走选择器过滤 alive+active）后 park。

## 边界

- 引擎近似为包围盒碰撞（全批同口径），prec 像素检查当时未实现（68d80e5 起 prec=1 走 SPRT 真实掩码）。
- iceblock 作为推箱阻挡物的语义存在于 obj_leftbutton/rightbutton Alarm 1（CODE 529/532 `instance_place(..., obj_iceblock)` 七连否决），但推箱机制本身未入引擎——该障碍语义待推箱批次一并建立。
- room60×3/room61×2/room62×2 的卡司密度已在 room60-63 契约固化；真机/GPU 视觉层未验收。
