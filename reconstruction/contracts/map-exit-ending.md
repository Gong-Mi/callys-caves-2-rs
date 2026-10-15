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

**商店中缝（`crates/core/tests/store_pause_round_trip_ir.rs`，本批新增）**：#90 钉了 firstpause 的 **mapmenu** 分支，这里补它的 **store** 分支并串完商店中缝——firstpause view0 分支激活 obj_store → 点店（CODE 474 在 backtogame 处建 obj_pause）→ pause Create `storemenu=1` + 再次 deactivate_all(true)（keep-self=pause）+ 建九件货架 → **真购买**走货架件自己的 Mouse_0（swordupgrade 价 3000，live score 扣到 0、sword=1、swordupgradebought=1——门控矩阵归 store_sweep，本处只证"在活页面上可点着"）→ backtogame **ELSE 分支**（CODE 470，地图房路径已由本契约上方测）清扫整张菜单（pause/store/firstpause/货架件全消）+ `instance_activate_all` 唤醒冻结玩家 + pause Destroy 清 storemenu；HUD pausebutton 不在 teardown 名单故存活（负断言钉住清扫边界）。

**连续往返（`crates/core/tests/map_pause_round_trip_ir.rs`）**：首项保留 rm_mapview0（1136×640）链路；新增第二项在同一 `Scene`/持久玩家中，依次走 CODE 476 的三组代表分支：1136×640→rm_mapview0(113)、1024×768→rm_mapview3(112)、960×640→rm_map(111)。每站均经 pausebutton→firstpause→mapmenu、visited fog tile→CODE 692、返回原房 pin/玩家唤醒；三个地图室的当前访问标记相同，故各只保留 goto==5 一块。这里通过 `Scene::transition_to_room` 消费房间切换，是 core/IR 连续场景证据，不是客户端帧循环或地图像素验收。全 client-loop 扩展另受 rm_mapview3 的无可见 ROOM view 阻塞：改宽高后实跑 client `step` 在 room112 报 `no visible view for gameplay room 112`；未据此改引擎，因为该变体需先厘清原 runner 的 no-view 绘制语义。夹具先把玩家走离 pin（2000,700），回钉才可观测。

## 测试

`crates/core/tests/map_exit_ending_ir.rs` 3 项：backtogame 在 rm_map 内释放（warp 39 + 玩家 4242/1717 回钉）、房外释放（不 warp 负断言）、rm_ending 布景（玩家 sprite 30 + 敌站桩 + 真实 loader 可载）。

## 边界

- backtogame Draw（471）与 obj_muting 的 8669 指令武器绘制矩阵属 Draw 层，只静态锚定。
- rm_ending 的完整谢幕演出（logo 渐入/滚动字幕/按钮流）由 Draw 层对象驱动，行为侧已由本批+game-start-p0+final-stretch 闭环。
- 真机/GPU 视觉未验收。
