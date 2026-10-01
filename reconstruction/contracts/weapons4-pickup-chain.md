# 四武器拾取链行为契约（bladegun / flamethrower / bombgun / boomerang）

基于 `full_ir.json` 字节码逐条对表，并在 `game.droid` 的真实布置房间中执行 IR 场景。四个对象都保持与已验收拾取族相同的两事件形状：Create 处理已购自毁或 beacon，Step 处理近身交接、独占武器行和自毁。

## 对象与 CODE

| 对象 | ID | sprite | Create / Step | bought 全局 | active 全局 |
|---|---:|---:|---:|---|---|
| `obj_boomerang` | 71 | 144 | 382 / 383 | `boomerangbought` | `boomerang` |
| `obj_bladegun` | 76 | 147 | 392 / 393 | `bladegunbought` | `bladegun` |
| `obj_flamethrower` | 77 | 145 | 394 / 395 | `flamethrowerbought` | `flamethrower` |
| `obj_bombgun` | 79 | 140 | 398 / 399 | `bombgunbought` | `bombgun` |

事件表均为 `(event_type=0, subtype=0, Create)` + `(event_type=3, subtype=0, Step)`；没有把 CODE 编号误当事件类型。

## 宿主房间与 beacon 几何

| 对象 | asset room / GML 名 | 布置坐标（实测） | beacon 坐标相对偏移 |
|---|---|---:|---:|
| `obj_bladegun` | 23 / `rm_level16` | `(714,184)` | `(-12,-16)` |
| `obj_boomerang` | 30 / `room33` | `(736,86)` | `(-8,-16)` |
| `obj_flamethrower` | 63 / `room65` | `(2244,214)` | `(-4,-12)` |
| `obj_bombgun` | 84 / `room84` | `(210,1466)` | `(+12,-16)` |

beacon 是 Create CODE 动态生成的 `obj_pickupflare(70)`，不计入 ROOM 的静态布置实例数量。

## 行为

- **Create**：先写 `image_speed=0`；若对应 `{w}bought == 1`，调用 `instance_destroy()`，不生成 beacon；否则以表中的偏移生成 `obj_pickupflare(70)`。
- **Step**：仅当 `distance_to_object(obj_player) <= 1` 且 `{w}bought == 0` 时，在拾取物自身坐标生成 `obj_foundweapon(82)`，置 `{w}bought=1` 和 `{w}=1`，把其余 11 个武器 active 全部置 0，最后销毁拾取物。
- 交接不是“任意接近就置 active”：测试把玩家钉在拾取物坐标并经过真实 `Scene::tick`，同时断言 banner 坐标、全量独占行和 pickup 自毁。
- 已购路径使用 fresh-start 的 active 基线（仅 `pistol=1`），只注入对应 bought 标志；重新载入四个真实宿主房间后同时断言 pickup 与 beacon 均不存在，且 active 行没有被 Create 改写。

## 测试

`crates/core/tests/weapons4_pickups_ir.rs` 4 项：每项覆盖一个真实宿主房间的 beacon 偏移、近身交接、bought 标志、11 项互斥清零、banner 落点，以及已购重载的双消失路径。

## 边界

- 至此 12 把武器的拾取链均有行为证据：pistol / shotgun / assaultrifle / rocket / laser / icegun / bladegun / flamethrower / bow / bombgun / boomerang / spikegun = **12/12**。
- 四武器的弹道与升级分支不由本契约覆盖；`obj_blade`、`obj_flame`、`obj_bomb`、`obj_boomerangthrow` 及对应玩家开火调度仍需独立行为批次。
- 引擎统一使用既有包围盒碰撞近似（`prec` 像素精确碰撞未实现）；真机/GPU 视觉层未验收。
