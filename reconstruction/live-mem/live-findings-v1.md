# Live-mem findings v1 — 原版渲染管线（活体取证）

日期: 2026-10-03 · 进程: com.vdogames.callyscaves2 pid 25295 (32-bit ARM, hbt 翻译层)
工具: `tools/live_read.py` `tools/read_views.py` `tools/read_room.py` `tools/hexdump_range.py`
段映射: rw/bss `live = 0x803c7000 + (va - 0x3f2000)`（rw 文件段与 [anon:.bss] 连续，实测通过）

## 0. 画面/表面事实

- 窗口: freeform `Requested w=1952 h=1220`; SurfaceFlinger geomBufferSize = **[0 0 1952 1220]**（GL 缓冲就是 1952×1220 真实像素，非缩放）。
- 线程: 2×GLThread, RenderThread, Mali 驱动线程组（ged-swd / mali-*）。
- `g_InitialScreenSizeX/Y = 1136×640`（启动期"屏幕"尺寸）；`region_width/height = 1136×640`。
- 房间 FORM/GEN8L 块（0x7b7b2e50）在 +0x4c/+0x50 处烙有 **1136/640**（房间加载时刻的屏幕尺寸）。
- 推论: 房间在 1136×640 时加载；其后窗口被拉到 1952×1220（freeform 可拖拽）。

## 1. 视图系统（渲染核心）

- 视图表挂在当前房间对象 `Run_Room`（BSS 0x54298c，实测 = 0xeafc63e0）的 **+0x48..+0x64**：8 个指针。
- 视图结构（由 GV_View* 访问器反汇编锁定）:
  `+0x00 byte visible / +0x04 f32 xview / +08 f32 yview / +0c f32 wview / +10 f32 hview /
   +0x14 i32 xport / +18 i32 yport / +1c i32 wport / +20 i32 hport /
   +0x24 f32 angle / +0x40 i32 camera_id (-1 = 无 CCamera, 走默认相机)`
- 实测 8 槽（仅 view[0] 可见）:

  | # | vis | view (游戏坐标) | port (屏幕坐标) | cam |
  |---|-----|----------------|----------------|-----|
  | 0 | **1** | **0,0 448×252** | **0,0 1136×640** | -1 |
  | 1 | 0 | 0,0 384×256 | 0,0 960×640 | -1 |
  | 2 | 0 | 0,0 300×200 | 0,0 960×640 | -1 |
  | 3 | 0 | 0,0 512×384 | 0,0 1024×768 | -1 |
  | 4 | 0 | 0,0 512×384 | 0,0 2048×1536 | -1 |
  | 5 | 0 | 0,0 448×250 | 0,0 1334×750 | -1 |
  | 6 | 0 | 0,0 480×270 | 0,0 2208×1242 | -1 |
  | 7 | 0 | 0,0 640×480 | 0,0 640×480 | -1 |

- `room+0x44 = 01`（views enabled）。
- UpdateViews（0x1b0164）行为（反汇编）: 遍历 i=0..7 → 可见的槽: `camera_id` → `CCameraManager::GetCamera` → `CCamera::CameraUpdate`；随后 `GR_Window_View_UnDefine(i)` + 按 view 字段联合重定义视口矩形。

## 2. 缩放链（对重建直接可用）

- 房间加载时: **view 448×252 → port 1136×640**（X 比 2.5357 / Y 比 2.5397，微各向异性）。
- 窗口变为 1952×1220 后: runner 全局 `g_ViewArea`(f32) 与 `g_ViewPort`(i32) = **0,0 1952×1220**（= port × 窗口/初始，**逐轴**缩放后填满窗口）。
- 当前有效缩放: 448×252 → 1952×1220 即 X×4.357 / Y×4.841（Y 多拉 ~11%，**不保持宽高比、无 letterbox**）。
- `g_OutsideViewColour = 0xFF000000`（黑，仅裁切时用）；`g_CoordFixScaleX/Y = 1.0`。
- 重建侧对照: 主工程 MainActivity 的 448/960、252/540 逻辑映射与 view[0] 448×252 同源；重建 960×540 ≈ 2×view[6](480×270) 槽。

## 3. 绘制/GL 状态（最近处理帧）

- 正交投影 `g_ProjIsOrtho=1`；`Draw_Color=0xffffffff`（白）；`Draw_Alpha=255`；
  混合 dst=`0x0303`（ONE_MINUS_SRC_ALPHA，常规 alpha 混合）；cull=0；alpha test=0；顶点格式/步长=24B。
- **application_surface 未创建**: `g_ApplicationSurface=0xFEEEDEAD`（dead 哨兵），`Autodraw=1` → 直接房间绘制管线，无 surface 间接层。
- `g_PrevViewArea*`/`g_PrevViewPort*` 全 = -1：glViewport 变化缓存，在 surface 重建/尺寸变化后清零（当前如此），不是"没渲染"。

## 4. 房间对象 Run_Room=0xeafc63e0 布局速记

- +0x00: -1（fontid）; +0x04: 自指针; +0x0c: 30; +0x10: 1024; +0x14: 576（网格类）。
- +0x20: 1 + 8×ptr(0x7d5a79xx, stride 0x40); +0x44: 01（views enabled）; +0x48..+0x64: 8×视图指针（0x7d4f74xx 一族）。
- +0x78: 10; +0x7c: 0.1f; +0xb0 → **FORM/GEN8L** 块（含 1136/640 烙值、若干 0x4f5xxx 偏移）。

## 5. 运行时边角（同一时刻读数）

- `Run_Room_List=114`（全部房间数）; `Current_View=0`; `Current_Room=0`; `New_Room=-1`; `Draw_Automatic=1`。
- `ms_CurrentCreateCounter=1647`（累计创建实例数）; `ms_ID2InstanceE={ptr,511,180}`（512 容 / 180 在用，容器结构待专项）。
- `obj_col_numb=46`、`obj_col_pairs→0xeadc07f0`、`obj_numb_event=153`（碰撞宽相统计）。
- `g_CrackDetected=0`（无盗版触发）; `g_nInstanceVariables=691`; `g_VariableCount=10443`; `g_YYStringCount=3210`。

## 6. 复现命令

```bash
su -c 'python3 tools/live_read.py   25295 0x803c7000'   # 全局量
su -c 'python3 tools/read_views.py  25295 0x803c7000'   # 8 视图表
su -c 'python3 tools/read_room.py   25295 0x803c7000'   # 房间对象 + 字符串嗅探
su -c 'python3 tools/hexdump_range.py 25295 <addr> <len>'
```

## 7. 未决 / 下一步

- 实例级绘制顺序（深度排序证据）: `ms_ID2InstanceE` 容器 180 条目待解 + 一帧内 Draw 序列捕捉。
- `GR_Window_View_Define` 的精确矩形算式（反汇编 GR_Window_View_Define 可得 port 逐轴缩放公式）。
