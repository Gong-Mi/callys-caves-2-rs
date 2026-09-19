# obj_laser (80) 激光枪拾取链契约

基于 `full_ir.json` 字节码逐条对表（非命名推断）。obj_laser 与已验收的 shotgun/rifle/rocket/ice/spike 完全同构（两事件小对象），补齐 `weapons3-pickup-chain.md` 边界所列未建链武器名单中的 **laser**；剩余未建链：bladegun、flamethrower、bombgun、boomerang。

## 对象与 CODE

| 对象 | ID | sprite | CODE | bought 全局 | active 全局 |
|---|---|---|---|---|---|
| obj_laser | 80 | 137 | 400 / 401 | laserbought | laser |

事件类型实测：`(0,0,Create)` + `(3,0,Step)`——**无 Destroy 事件**（早期把 401 读成 Destroy 是事件类型编号误读，1 才是 Destroy，3 是 Step）。

## 行为

- **Create CODE 400**：`image_speed=0`；若 `laserbought==1` → `instance_destroy()`（已购枪换房重载即消失，不留 beacon）；否则在 `(x, y-16)` 生成 `obj_pickupflare(70)`。**激光的 beacon 偏移是本家族最平的一个**：`(x+0, y-16)`，对照 rocket `(+8,-20)`、ice `(+4,-18)`、spike `(+8,-12)`。
- **Step CODE 401**：`distance_to_object(obj_player) <= 1 && laserbought == 0` → 在拾取物自身坐标生成 `obj_foundweapon(82)` 横幅、置 `laserbought=1` 与 `laser=1`，其余 11 把武器全局全置 0（互斥行，冰枪在序列首位与其它枪的字节码顺序不同、语义集合相同），然后自毁。

## 宿主房间

asset room 76（gml room77，+1 偏移，第十五段门链卡司内）：2048x480 的 ghost×6 房；obj_laser×1 是**布置实例**，信标 obj_pickupflare 由 CODE 400 在房间载入时生成、不属布置卡司。

## 测试

`crates/core/tests/laser_pickup_ir.rs` 2 项：「beacon 偏移 + 互斥行翻转 + 横幅落点」与「已购激光再进房双消失且不动互斥行」。夹具沿用 weapons3 约定：`bought=1` 不叠加 `active=1`，fresh-start 互斥行只有 pistol。

## 边界

- 激光**弹道**（obj_laserbeam，由 obj_player Alarm 0 CODE 11 生成）未建契约，本契约只覆盖拾取链。
- 引擎统一包围盒碰撞近似（全批同口径）；真机/GPU 视觉层未验收。