# 地图出口与结局入口契约（obj_backtogame + rm_ending 布景）

地图系统批（map-system.md）的收尾：**backtogame 出口按钮**补全地图往返闭环，**rm_ending 房内布景**经真实 loader 落地。静态解码 + 活实例实测后固化进 `crates/core/tests/map_exit_ending_ir.rs`（3 项，一次全绿）；探针已删。

## obj_backtogame（108，sprite 153）

**Mouse_7 (CODE 470)**——地图屏的"返回游戏"按钮：

- **房间门**：`room == 111 || 113 || 112`（bt/bf 链：前两个用 bt=真分支，第三个 b 收尾）——**只在三个地图房内执行传送**，房外只做清扫（实测 target_room_warp=None）。
- **门内路径**：`room_goto(roomcamefrom)` → **玩家（selector 0）重钉 `startx/starty`** → `instance_activate_all`（与 maptile tap 的 CODE 692 完全对称：地图进/出都恢复原站位）。实测回 warp 39 + (4242,1717)。
- **UI 清扫**：15 对象列表与 CODE 692 完全一致（99/115/122/110/107/109/118/108/116/123/119/120/114/112/113）——同一套 UI teardown 复用。
- 房外路径：`musicmute` 双分支 `audio_stop_all` + `activate_all` + 同款清扫，**不 warp**。

**Draw (471)**：按钮图标绘制，属渲染层只静态钉。

## rm_ending（110）房内布景

- **CODE 1022**（玩家绑定）：`sprite_index = 30`——结局把玩家钉进谢幕贴图（实测）。
- **CODE 1023**（obj_enemy 绑定）：`hspeed = vspeed = 0`——谢幕站桩（实测）。
- Room Start 的 roomstart=1 + alarm[6]=10 输入锁链已在 game-start-p0 钉死（CODE 16 仅 room==110 装填；CODE 5 Alarm 6 清零）。
- **结局入口**（final-stretch.md）：finalbosspuff Destroy → `room_goto(110)`。本批补上**到达后**的房内状态：玩家 sprite 30 + 站桩敌 + 全场经真实 loader 可载。

## 数据流闭环（地图往返全链）

```
游戏内 → mapmenu 释放 →(分辨率)→ rm_map/mapview0/3
       → 贴片 tap（CODE 692）→ warpfrommap=1 + room_goto(goto) + 玩家钉 startx/starty
       → backtogame 释放（CODE 470）→ room_goto(roomcamefrom) + 玩家钉 startx/starty
```

进/出对称：都从 `startx/starty` 恢复站位，都做同款 15 对象 UI 清扫。`roomcamefrom` 由玩家 Create 种子 + Room End（CODE 15）每换房重钉（map-system.md 已钉）。

## 测试

`crates/core/tests/map_exit_ending_ir.rs` 3 项：backtogame 在 rm_map 内释放（warp 39 + 玩家 4242/1717 回钉）、房外释放（不 warp 负断言）、rm_ending 布景（玩家 sprite 30 + 敌站桩 + 真实 loader 可载）。

## 边界

- backtogame Draw（471）与 obj_muting 的 8669 指令武器绘制矩阵属 Draw 层，只静态锚定。
- rm_ending 的完整谢幕演出（logo 渐入/滚动字幕/按钮流）由 Draw 层对象驱动，行为侧已由本批+game-start-p0+final-stretch 闭环。
- 真机/GPU 视觉未验收。
