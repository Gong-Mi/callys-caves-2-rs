# 地图系统契约（obj_maptile + obj_mapmenu + 迷雾/传送/三缩放）

rm_map(111)/rm_mapview3(112)/rm_mapview0(113) 的 90+ 房间绑定（obj_maptile 160，CODE 1024-1352）与 obj_mapmenu(111, CODE 476/477) 在本批闭环。全部断言经静态解码 + 活实例探针实测后固化进 `crates/core/tests/map_system_ir.rs`（3 项）；探针已删。

## 全量贴片表（静态解码 109 个不同贴片 ×3 房 = 327 绑定）

每个地图贴片的 RoomCC CODE 同构：`if {room}visited == 0 → instance_destroy; goto = N`。109 个 goto 值覆盖全部主线房：level1-8/8a→1-9、boss1→10、level9-17→11-26、boss2→27、room31-103→28-103、boss3/4/5→48/64/82、boss6→104（**6 份绑定**，三房各二）、challenge1-5→105-109。visited global 命名规律：`levelNvisited`/`bossNvisited`/`roomNvisited`/`levelchallengeNvisited`。

三个地图房是**同一张表的三个缩放级**：rm_map/rm_mapview0/rm_mapview3 的贴片 CODE 1024-1352 逐 goto 同表（实测 room42visited 在三房各留 1 贴片）。

## obj_maptile 行为

- **Step (691)**：邻接画路——`(y−1) 或 (y+1)` 有贴片 → sprite 172；`(y+1) 有 且 (y−1) 无` → 173；**全无邻接保持 171**（实测）；`goto == roomcamefrom` → `image_blend = 255`（"你在这里"高亮，实测）。
- **Mouse_7 (692)**（点击传送）：先清 15 种 UI 对象（99/115/122/110/107/109/118/108/116/123/119/120/114/112/113）→ `instance_activate_all` → **`warpfrommap = 1`** → `room_goto(goto)` → **玩家（selector 0）重钉到 `global.startx/starty`**——地图记住你原来的站位（实测 4242/1717 回写）。
- **Draw (693)**：draw_self + font 2 白字 `string_digits(string(goto))` @ (x+6, y+8)——贴片上直接画房间号。
- **Destroy (690)**：清 UI 残留 + 若 obj_bosspuff(68) 不存在则在自身位置补一团（烟雾清理链）。

## obj_mapmenu 行为（分辨率选房）

**Mouse_7 (476)**：16 个分辨率分支选打开哪个地图房：

| window_get_width×height | 打开 |
|---|---|
| 960×640 / 1280×800 / 2560×1600 / 854×480 | rm_map (111) |
| 1024×768 / 2048×1536 | rm_mapview3 (112) |
| 其余全部（1136×640 / 1280×720 / 1334×750 / 2208×1242 / 800×480 / 960×540 / 1920×1080 / 2560×1440） | rm_mapview0 (113) |

**宿主映射**：`window_get_width/height` 读 `scene.display_width/height`（默认 960×540 → mapview0）。实测四分支：960×640→111、1024×768→112、1136×640→113、1280×720→113。

## 迷雾数据流

`roomcamefrom` 由 obj_player Create（CODE 0）种子 + **Room End（Other_5, CODE 15）每换房重钉**——高亮跟随真实所在房。`startx/starty` 由玩家站位写入（地图外流程），点击贴片后回写。

## 夹具事实（本批血泪）

- **rm_map 无玩家绑定**：CODE 692 尾部 `player.x = startx`（selector 0 写）在无玩家实例时**宿主报错 "write has no receiver"**——原版靠 obj_player 持久化（跨房存活）。夹具必须在 tap 前手动 `create(PLAYER)` 模拟持久玩家。
- 邻接贴片判定用 `instance_place(160)`（同对象选择器）——场景里其他贴片即邻接源。

## 测试

`crates/core/tests/map_system_ir.rs` 3 项：迷雾门（无 visited 全灭 + 三 visited 精确保 3 贴片 + 三缩放房同表）；点击传送链（Step 高亮 255 + sprite 171 邻接 + tap 后 warpfrommap=1/target_room_warp=goto/玩家回钉 startx/starty）；分辨率选房（四分支实测）。

## 边界

- Draw 层（贴片房号文字、mapmenu 图标）只静态钉；真机/GPU 视觉未验收。
- boss6 贴片 6 份绑定（每房二份）的坐标重叠未铺测（同 goto 双贴片行为一致）。
- `startx/starty` 的生产端写入（玩家何时记录站位）不在本批——属 warp 流程侧，现有 game-start/portal 批已覆盖传送语义。
