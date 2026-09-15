# rm_boss2 房间与 Boss2 初始化契约

基于 `assets/game.droid` 的原始 room/object 记录。

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

Boss2 的 alarm/Step 相位不在本批以房间装载后的数组值断言；它需要单独按 tick/Alarm 事件验证。

## Boss2 Alarm1

真实执行 `gml_Object_obj_boss2_Alarm_1`（CODE 167）确认：

- 当当前 room 不是原版资源 ID 110，且 `obj_slime` 数量同时满足原版门禁时，生成 3 个 `obj_slime` 攻击实体。
- 三个新实体均由原版 Create 执行，并设置 `alarm[0]=30`。
- `room==110` 是该段逻辑的跳过分支，不是 Boss2 房间的进入条件。

## 测试

`crates/core/tests/boss2_room_ir.rs`，3 项：

- `boss2_room_and_doors_are_asset_exact`
- `boss2_create_initializes_original_state_for_power_one`
- `boss2_alarm1_emits_three_original_attack_entities_when_room_gate_matches`

## 边界

- 本批完成房间、门链和 Boss2 Create 字段，不声称 Boss2 移动、投射物、受伤、死亡掉落或 Boss2intro 已完成。
- 真机/GPU 视觉层未验收。
