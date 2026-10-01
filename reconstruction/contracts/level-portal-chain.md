# 关卡传送门链契约（level portal chain，CODE 13 + RoomCC 805-808）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 原版机制（恢复 GML 证据）

1. **obj_warpanywhere（69）Create（CODE 379）**：`unlocked = 0`、
   `treasuredoor = 0`（每个传送门实例再被 RoomCC 覆写）。
2. **房间创建码（room_bindings）**：
   - rm_level1 instance 100171 → CODE 805：`warproom = 2; warpx = 128; warpy = 492; unlocked = 1`（预解锁，通往 rm_level2）；
   - rm_level1 instance 100172 → CODE 806：`warproom = 0; warpx = 832; warpy = 480; unlocked = 1`（回镇门）；
   - rm_level2 instance 101513 → CODE 807：`warproom = 3; warpx = 128; warpy = 140; unlocked = 1`；
   - rm_level2 instance 102793 → CODE 808：`warproom = 1; warpx = 1856; warpy = 1164; unlocked = 1`（回 level1）。
3. **CODE 13（obj_player 与 69 的碰撞事件）**：
   - `haskey >= 1 && other.unlocked == 0` → `room_goto(other.warproom)` +
     `obj_player.x/y := other.warpx/warpy`、清零速度、`haskey -= 1`、`unlocked = 1`；
   - `haskey == 0 && other.unlocked == 0` → `global.warplock = 1`（不切关）；
   - `other.unlocked == 1` → 直接 `room_goto(other.warproom)` + 重定位。
4. **客户端泵送**（`crates/client/src/lib.rs` step 循环）：`room_goto` 内置函数
   置 `Scene::target_room_warp`，主循环 `take()` 后调用
   `transition_to_room`（Room End → 持久实例保留 → 加载新房间 → Room Start）。
   测试用 `pump_transition` 镜像该消费序列。
5. **rm_level2 危险域**：27 个 obj_spikes（对象 8）；玩家 Step CODE 12
   `distance_to_object(obj_spikes) <= 1` → `global.health1 = 1; playerhp = 1`，
   下一 tick 生成 obj_youhavedied（134）、`playerdied += 1`、snd_youhavedied（26）。

## 测试（`crates/core/tests/level_portal_chain_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `level1_to_level2_portal_chain_carries_player_and_cast` | 走上 CODE 805 门 → CODE 13 排队 room_goto → 泵送后 current_room=2、玩家被重定位 (128,492)（门 pin 的坐标，非硬编码）；rm_level2 卡司 obj_enemy2×1、spikes×27、tiles 与资产一致；20 帧空跑 health1=4 不变；反向走 CODE 808 门回 rm_level1 (1856,1164)，obj_UI 持久存活、5 只 obj_enemy 重新物化 |
| `spike_field_in_level2_downs_the_player_through_code12` | 落上尖刺 → health1=1/playerhp=1 → 次 tick obj_youhavedied 生成、playerdied=1、snd_youhavedied(26) 排队 |
| `locked_level1_portal_blocks_without_the_key` | 覆写 unlocked=0、haskey=0 的无钥匙路径：room_goto 不排队、global.warplock=1、留在 rm_level1 |

## 边界

- 门碰撞为 `instance_place` 中心重叠模型，与既有 warp_reachability 全图验收同一
  几何前提；本批首次用「真实踩门 → CODE 13 → 泵送」贯通 town→1→2→1 往返，
  替代此前测试里手设 `target_room_warp` 的旁路。
- 上锁门路径（haskey ≥1 消耗钥匙分支）已由 CODE 803 镇门在前批验收；本批补齐
  warplock 无钥匙分支与预解锁直通门。
- rm_level3 及更深的门（809/810+）沿用同一机制，未逐关铺测试。
- Android 真机切关黑屏/加载时序仍需真机层验收。
