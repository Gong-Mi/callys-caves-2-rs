# rm_boss2 房间与 Boss2 行为契约

基于 `assets/game.droid` 的原始 room/object/CODE 记录。

## 房间

- rm_level17a 的 CODE 856 进入 rm_boss2（room 27），玩家落点 `(128,140)`。
- rm_boss2 的 CODE 857 返回 rm_level17a（room 26），落点 `(352,1484)`。
- rm_boss2 的 CODE 858 进入 room31（room 28），落点 `(128,204)`。
- 房间尺寸：`1280x480`。

## 卡司

- `obj_boss2` ×1
- `obj_bossboulder` ×8
- `obj_boulder` ×111
- `obj_platform` ×9
- `obj_UI`、`obj_bg`、`obj_muting`、`obj_weaponswap` 各 ×1
- 另有 `obj_wall` ×76、`obj_wall_2` ×116、`obj_warpanywhere` ×2

## Boss2 Create 初始字段

真实执行 `gml_Object_obj_boss2_Create_0`（CODE 163）后，在默认 `global.pwr=1` 下确认：

- `flashing=0`
- `poisoned=0`
- `swordstunned=0`
- `xpdrop=1`
- `hpdrop=1`
- `hpboss2=750`
- `boss2maxhp=750`

## Boss2 Alarm1

真实执行 `gml_Object_obj_boss2_Alarm_1`（CODE 167）确认：

- room index 27 下，满足原版 `obj_slime` 数量门禁时生成 3 个 `obj_slime` 攻击实体。
- 三个实体均执行原版 Create，拥有 `alarm[0]=30`。
- 原版 `damage=0.25` 是对新实体的数组/selector 0 写入，不是普通实例字段。
- 原始代码包含 `room==110` 跳过分支；当前 asset 使用 room index 27，不能把资源 ID 110 与 room index 混同。

## 测试

`crates/core/tests/boss2_room_ir.rs`，3 项：

- `boss2_room_and_doors_are_asset_exact`
- `boss2_create_initializes_original_state_for_power_one`
- `boss2_alarm1_emits_three_original_attack_entities_when_room_gate_matches`

## 边界

- 已验证房间、门链、Create 初值和 Alarm1 攻击实体生成。
- Boss2 Step 的重力/巡逻、Alarm6 中毒、Alarm5 剑眩晕、Alarm0 死亡掉落、Boss2intro 和 Android 真机视觉仍未完成。
