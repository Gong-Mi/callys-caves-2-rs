# 三武器拾取链行为契约（rocketlauncher / icegun / spikegun）

基于 `full_ir.json` 字节码逐条对表（非命名推断）：三对象与已验收的 shotgun/rifle 完全同构（两事件小对象，Create 19 指令 / Step 46 指令）。

## 对象与 CODE

| 对象 | ID | sprite | CODE | bought 全局 | active 全局 |
|---|---|---|---|---|---|
| obj_rocketlauncher | 75 | 133 | 390/391 | rocketbought | rocket |
| obj_icegun | 81 | 135 | 402/403 | icegunbought | icegun |
| obj_spikegun | 72 | 142 | 384/385 | spikegunbought | spikegun |

## 行为（与 shotgun 模板逐指令 diff，仅常量/全局名不同）

- **Create**：`image_speed=0`；若 `{w}bought==1` → `instance_destroy()`（已购枪在换房重载时消失，不留 beacon）；否则在 `(x+dx, y-dy)` 生成 `obj_pickupflare(70)`：rocket (+8,-20)、ice (+4,-18)、spike (+8,-12)。
- **Step**：`distance_to_object(obj_player) <= 1 && {w}bought == 0` → 在拾取物自身坐标生成 `obj_foundweapon(82)` 横幅、置 `{w}bought=1` 与 `{w}=1`，把其余 11 把武器全局全部置 0（互斥行），然后自毁。
- 指令序列核对：Step 的 12 项 store 序列三对象一致，仅自身武器名排第二（bytecode 顺序不同但语义集合相同）。

## 宿主房间（第九/七段门链实测位置）

- rocketlauncher：asset room 45（gml room48，spikes×57 房，第七段已入卡司）。
- icegun：asset room 51（gml room53，gem×3 房，第九段已入卡司）。
- spikegun：asset room 53（gml room55，lloyd×1 房，第九段已入卡司）。

## 测试

`crates/core/tests/weapons3_pickups_ir.rs` 4 项：三武器各自"beacon 偏移 + 互斥行翻转 + banner 落点"，外加"已购冰枪重进房双消失且不动互斥行"。夹具教训：注入 `bought=1` 时不得同时注入 active=1，fresh-start 互斥行只有 pistol。

## 边界

- 三武器开火行为（obj_rocket / obj_icebullet / obj_spikebullet 弹道族）不在本批；foundweapon 横幅冻结/解锁链由 weapon_acquisition_ir.rs 既有用例覆盖（同 CODE 404-408）。
- 剩余未建链武器：laser、bladegun、flamethrower、bombgun、boomerang（弓已有 weapon-acquisition 契约段落）。
- 真机拾取音效/视觉未验收。
