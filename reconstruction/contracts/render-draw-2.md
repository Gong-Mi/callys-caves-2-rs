# 渲染 Draw 层批次 2：触控按钮层与武器切换挂件

CODE 522（obj_jumpbutton）/525（obj_shootbutton）/527（obj_swordbutton）/530（obj_leftbutton）/533（obj_rightbutton）与 520（obj_weaponswap Draw，13888 指令）经字节码在本引擎宿主实测后固化（恢复 GML 交叉核对）。这一层是每帧常驻的触控 HUD：五个按钮 + 武器切换挂件。

## 机制：五个触控按钮

- **共同结构**：按 `view_current` 分支（0/1/3/4/5/6，**view 2 空支**）；先 `draw_sprite_ext(spr_X, 0, view_xview[v]+dx, view_yview[v]+dy, s, s, 0, -1, 0.6)`（idle 帧 0、alpha 0.6），随后**自钉** `x/y`——钉值与绘制偏移可不同（left 绘 `+0` 钉 `−10`；right 绘 `+86` 钉 `+88`），碰撞盒按**实例 x/y** 计算（游戏自己查询的就是这个盒）。遍历设备 0..4。
- **left/right（530/533）**：`device_mouse_check_button`（**按住态**）∧ 命中 ∧ `global.roomstart != 1` → `alarm[1]=1` + 帧 1 alpha 1；按住但**未命中** → `obj_player.hsp = 0`。释放 ∧ 命中（同一 roomstart 门）→ `hsp=0` + 帧 0 **alpha 1**；释放 ∧ 未命中 → `hsp=0`（无额外绘制）。
- **jump（522）**：`device_mouse_check_button_pressed`（**按下边沿**）∧ 命中 → `alarm[1]=1` + 帧 1 alpha 1。
- **shoot（525）**：pressed 边沿 ∧ 命中 → `alarm[2]=1` + 帧 1 alpha 1；`global.assaultrifle == 1` 时**按住**也会重复触发同一分支（连发视觉）。
- **sword（527）**：pressed 边沿 ∧ 命中 → `alarm[1]=1` + 帧 1 alpha 1。
- **view 0 几何**：left `(vx+0, vy+190) 0.9`、right `(vx+86, vy+190) 0.9`、jump `(vx+380, vy+190) 0.9`、shoot `(vx+315, vy+190) 0.9`、sword `(vx+380, vy+125) 0.9`；**view 1**：left `+2/+200`、right `+77/+200`、jump `+330/+200`、shoot `+275/+200`、sword `+330/+145`，全部 0.8。
- **Alarm 处理（行为侧，非本批断言）**：jump alarm[1] → `obj_player.vsp`（grounded −12 / djump −9 / tjump −9，配 snd_jump 与 spr_playerjump）；shoot alarm[2] → `obj_player.alarm[0]=1`；sword alarm[1] → `obj_player.alarm[1]=1`；left/right alarm[1] → 玩家朝向/贴图 + `hsp=∓7`（带 boulder/wall/wall_2/bossboulder/boulderblock/woodblock/iceblock 探测）。

## 机制：武器切换挂件（obj_weaponswap Draw CODE 520）

- **挂件本体**：`draw_sprite_ext(spr_weaponswap, 0, vx+360, vy+0, 0.7, 0.7, 0, -1, 1)` + 自钉 `(vx+360, vy+0)`；释放命中盒 → `alarm[0]=1`（行为侧已由 `weaponswap_rotation_ir` 覆盖）。
- **已购武器**：每族 `if (global.<w> == 1)` 时画族图标（档位 ≤3/≤6/≤9/≥10 → 帧 0..3，各族偏移与缩放不同），再画该武器 XP 条与等级：
  - 等级 < 10 时 `draw_healthbar(vx+368, vy+3, vx+441, vy+6, (global.<w>xp / global.<w>xptolevelup) * 100, c_gray, c_green, c_yellow, 0, 1, 1)`；
  - `draw_text(vx+368, vy+6, string(global.<w>level))`（等级 ≥ 10 只隐去血条，数字仍在）。
- **12 族 view-0 图标表（帧 0/1/2/3 → (dx, dy, scale)）**：

| 族 | 帧 0 | 帧 1 | 帧 2 | 帧 3 |
| --- | --- | --- | --- | --- |
| pistol | +422,20 ×2 | +422,20 ×2 | +422,20 ×2 | +418,22 ×2 |
| shotgun | +405,20 ×2 | +409,20 ×2 | +405,20 ×2 | +405,20 ×2 |
| assaultrifle | +382,19 ×1.8 | +380,19 ×1.8 | +380,19 ×1.8 | +375,19 ×1.8 |
| rocket | +381,34 ×2 | +377,36 ×2 | +377,36 ×1.8 | +377,33 ×1.8 |
| icegun | +388,37 ×2.2 | +385,36 ×2 | +381,36 ×1.9 | +375,36 ×1.8 |
| laser | +403,19 ×2 | +395,19 ×1.8 | +393,19 ×1.8 | +392,19 ×1.7 |
| bow | +402,20 ×1.1 | +402,20 ×0.9 | +402,20 ×0.9 | +402,20 ×0.9 |
| flamethrower | +407,16 ×1.5 | +404,16 ×1.4 | +400,16 ×1.3 | +395,20 ×1.1 |
| bladegun | +416,18 ×1.5 | +411,18 ×1.5 | +408,18 ×1.4 | +404,18 ×1.4 |
| boomerang | +400,20 ×1.5 | +400,19 ×1.5 | +400,19 ×1.5 | +400,19 ×1.1 |
| spikegun | +388,19 ×1.5 | +386,19 ×1.5 | +380,19 ×1.5 | +380,19 ×1.5 |
| bombgun | +386,19 ×1.5 | +386,19 ×1.5 | +382,19 ×1.5 | +380,19 ×1.5 |

## 夹具陷阱（本批 RED 实证）

- **实例 id ≠ 对象 id**：房间放置的实例 id 是资产里的实例号（如 obj_leftbutton 的实例 id 不是 130），夹具必须按 `i.object == obj` 查实例，直接以对象 id 索引 `instances` 会 panic。
- **left/right 是"按住"态、其余是"按下边沿"**：给 left/right 只设 `pressed` 会得到"没有 pressed 帧"的假失败；正确姿态是 `down`（left/right）/ `pressed`（jump/shoot/sword）。
- **按钮自钉位置 ≠ 绘制位置**：`aim_at` 必须用实例 x/y 算碰撞盒（left 差 10px、right 差 2px），用绘制坐标会落在盒外。

## 测试

- `crates/core/tests/touch_controls_ir.rs` 6 项：五按钮 view-0 idle 几何表 + 自钉位置、逐按钮 pressed 帧/alpha/alarm 槽（左·右按住态，jump·shoot·sword 边沿态）、left 释放回 idle（alpha 1）+ `hsp=0` 与"盒外按住清 hsp 且无第二帧"、shoot 仅在 `assaultrifle==1` 时按住连发（含阴性）、盒外按下全员 idle 且警报未动、view 1 布局表与 view 2 全空。
- `crates/core/tests/swap_widget_ir.rs` 3 项：挂件图标 + pistol/shotgun 逐档图标与偏移（含 ≥10 位移）、XP 条与等级文本（level 10 隐条留字）、未购武器与未拥有族不画（只 1 图标 + 1 条 + 1 文本）。

## 边界

- **`draw_healthbar` 的后三参**：命令层（`HealthbarCommand`）只带 x1/y1/x2/y2/amount/back_col/min_col/max_col，丢弃 `direction/showback/showborder`。全语料 **90 处调用点**（obj_UI 18 + obj_weaponswap 72）的后三参恒为 `(0, 1, 1)`（恢复 GML 全表核对；decompiler 往返已由 CI 证明 `same_gml=1354/1354`）——本作无损失；若将来出现其他取值需扩命令。
- 按钮 view 1/3/4/5/6 五个分支中只抽验了 **view 1**；view 3/4/5/6 未逐项断言。
- 挂件 12 族中只逐档锁了 **pistol/shotgun**；其余 10 族的 view-0 表在契约但未进断言。
- 按钮 Alarm 的实际效果（跳跃/射击/挥剑/移动）属行为批；本批只验 Draw 侧的"arming"。
- 真机/GPU 视觉层未验收（NOT RUN）。
