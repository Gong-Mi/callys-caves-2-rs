# obj_woodblock (158) 碎裂与碎木契约

CODE 684（Create）/685（Destroy）/686（Collision 36 = obj_blade）与 obj_logparts(155) 的 CODE 676/677/678、obj_blade(36) 的 CODE 271/272/274 全部经字节码在本引擎宿主实测后固化。由 room72-75 契约的卡司欠账触发（本分支首个 woodblock 房）。

## 机制

- **Create CODE 684**：`type=1`。全 GML 语料零读取（`obj_woodblock` 仅出现在 obj_blade Step CODE 274 与 obj_leftbutton/rightbutton Alarm 1 CODE 529/532，均不读 `.type`）——写而不读的死字段，契约只钉原始值。
- **销毁路径是刀片 Step 扫描，不是碰撞事件**：obj_blade **没有** Collision 158；CODE 274 首分支 `hitblock = instance_place(x + hspeed, y, obj_woodblock)` → `with(hitblock) instance_destroy()` + 自身 `instance_destroy()`——同 tick 双杀。Collision 36 CODE 686 只是一行 `instance_destroy()`（引擎侧冗余路径）。
- **Destroy CODE 685**：六枚 obj_logparts 固定偏移生成 `(x,y−8)/(x+8,y)/(x−8,y)/(x,y+8)/(x−8,y+8)/(x+8,y+8)`；`global.soundmute==0` 时播 snd_explode（sond 7），`==1` 空分支。
- **obj_logparts CODE 676**：`sprite_index` 取 spr_logstop/spr_logsbottom（choose，实测 167/168）、双轴 `choose(1,−1)`、`speed=7`、`direction=choose(70,110)`、`alarm[0]=30`；Step CODE 678 `gravity=1`；Alarm 0 CODE 677 自毁。
- **刀片 CODE 271**：`facing==1 → hspeed=−20`、`facing==0 → hspeed=+20`、`alarm[1]=40`；Alarm 1 CODE 272 超时自毁（Alarm 0 CODE 273 同款 handler 但全语料无 arm 站点——死分支）。

## 时序（本宿主实测，非 GMS 直觉）

- 碎裂发生在刀片存在后的第 1 tick；logparts 生成时 alarm 读回 30。
- 第 t tick 读回 `31 − t`：tick 30 时为 1，tick 31 归零派发 CODE 677，六枚同时消失。
- 刀片在开阔地第 40 tick 自毁（alarm 装载 40，逐 tick 递减到 0 派发）。

## 夹具陷阱（本批 RED 教训）

`obj_player` Create（CODE 0）会写 `global.soundmute = 0`——夹具里 `soundmute=1` 必须在**玩家创建之后**注入，否则被覆盖（首版 RED 实证）。刀片 Create CODE 271 经对象选择器读 `obj_player.facing`（alive+active 过滤），玩家须保持 active 到刀片创建完成再 park。

## 测试

`crates/core/tests/woodblock_shattering_ir.rs` 6 项：Create 死字段+无刀片负对照 5 tick、刀片 Step 双杀+六偏移逐项（偏移集排序比对，非遗漏任一）+choose 值域（direction ∈{70,110}、sprite ∈{167,168}、scale ∈{1,−1}）+snd_explode 恰一次、facing 镜像投掷、logparts 31 tick 寿命逐帧报警递减断言、刀片 40 tick 超时、soundmute 分支。

## 边界

- 推箱阻挡语义（CODE 529/532 的 `instance_place(..., obj_woodblock)` 否决）仍属推箱批次，本契约未含。
- `choose()` 为随机取值，断言只覆盖值域与偏移集，不锁具体实例取值。
- 引擎统一包围盒碰撞近似（全批同口径）；真机/GPU 视觉层未验收。