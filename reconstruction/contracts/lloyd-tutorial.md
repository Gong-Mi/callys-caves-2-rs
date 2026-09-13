# obj_lloyd 与十六张教学对话表契约（Lloyd tutorial）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 系统定位

全游戏**唯一的过场/教学系统**：`obj_lloyd`(154) 是场景里的 NPC，靠近后
冻结玩家并交接给该房间专属的 `obj_lloydtutorial1..16`「对话框」；对话框把
整个世界停摆、暂停音乐、在视口上铺暂停底板 + 两个立绘 + 两行文字，点击后
落盘 `talkedtolloydN` 并恢复世界。

## obj_lloyd：四段行为

1. **CODE 670 Create**：`startlloyd = 0`、`alarm[2] = 30`（心跳）、
   `hspeed = vspeed = 0`、`alarm[0] = 1`（开局 1 帧后就做一次退场检查）。
2. **CODE 675 Step**：`distance_to_object(obj_player) <= 100` 时
   `global.roomstart = 1`、销毁 `obj_leftbutton`/`obj_rightbutton`、
   把玩家 `hspeed/vspeed/hsp` 归零、`startlloyd = 1`。
3. **CODE 672 Alarm 2**（每 30 帧重挂）：`startlloyd == 1` → `alarm[1] = 1`；
   随后 `alarm[2] = 30`。
4. **CODE 673 Alarm 1**：按 `room` 生成对应对话框——town→t1、level1→t2、
   level2→t3、level5→t4、boss1→t5、level9→t6、level13→t7、level14a→t8、
   boss2→t9、room42→t10、room55→t11、room103→t12、**level7→t13**、
   room46→t14、level4→t15、challenge1→t16。
5. **CODE 674 Alarm 0**：本房已谈过（`global.talkedtolloydN == 1`）则自毁；
   rm_level1 另有**第二条独立闸门** `global.shotgunbought == 1` 也自毁
   （散弹枪买到就不用再讲）。

## 对话框：Create / 时间轴 / Draw / 点击退场 / Destroy

以 rm_level1 的 `obj_lloydtutorial2`(139) 与 rm_level7 的
`obj_lloydtutorial13`(150) 为两条实测样本：

| 段 | t2（rm_level1） | t13（rm_level7） |
| --- | --- | --- |
| CODE 565/642 Create | `instance_deactivate_all(true)`；`taplock=0`；`drawpanel1=1` 其余 0 | 同左 |
| 时间轴 | `alarm[0]=100`（面板1→2）、`alarm[1]=200`（2→3）、`alarm[5]=300`（`taplock=1`） | `alarm[0]=100`、`[1]=200`、`[2]=300`、`[3]=400`（依次 1→2→3→4→5）、`[5]=500` |
| 音乐 | `global.musicmute == 0` → `audio_pause_all()` + `audio_play_sound(mus_townmusic, 0, true)`（SOND 32，循环） | 同左 |
| CODE 570/649 Draw | 以 `view_current` 分视口（0/1/3/4/5/6）铺 `spr_pause` 底板 + `spr_lloyd` + 镜像 `spr_player`，`taplock == 1` 时加 "Tap to Continue" | 同结构，各视口缩放/坐标不同 |
| 点击退场 | Draw 末段 `taplock == 1 && device_mouse_check_button_released(0, mb_left)` → `instance_destroy()` | 同左 |
| CODE 566/643 Destroy | `global.talkedtolloydN = 1`；`ini_open("savefile.ini")` + `ini_write_real("Save", "talkedtolloydN", …)` + `ini_close`；停 `mus_townmusic`；`instance_activate_all()` + `audio_resume_all()`；销毁 obj_lloyd；重建左右按钮；`global.roomstart = 0` | 同左 |

Draw 的视角几何（rm_level1 / view 0，逐字）：底板 `spr_pause` 帧 1 于
`(view_xview[0]-1, view_yview[0])`、缩放 (0.96, 0.8)；`spr_lloyd` 于
`(+50, +50)`、缩放 (2, 2)、**帧 -3 原样透传给客户端**；镜像 `spr_player` 于
`(+380, +180)`、缩放 (-2, 2)、旋转 1；`taplock == 1` 时 "Tap to Continue"
落在 `(+150, +200)`。面板文字两行固定在 `(+100, +50)` 与 `(+100, +70)`
（view 3/4 用 font4 与 (+130,+80)/(+130,+100)），面板 1/2/3 各自两组文案。

## 测试（`crates/core/tests/lloyd_tutorial_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `lloyd_stops_the_player_and_hands_over_to_the_room_tutorial` | CODE 670 初值（startlloyd/alarm 2=30/alarm 0=1/静止）、obj_UI 已放好左右按钮；CODE 675 后 `roomstart=1`、`startlloyd=1`、两个按钮消失、玩家三项速度归零；心跳走满后 CODE 673 在该 Lloyd 坐标生成 t2 |
| `the_sheet_freezes_the_world_and_runs_its_panel_timeline` | CODE 565 Create：`instance_deactivate_all(true)` 后**全场只剩对话框 active**、面板 1 开、alarm 0/1/5 = 100/200/300、`audio_pause_all` 真的把先前音轨置 paused、townmusic 循环进队列且自身未暂停；时间轴 100/200/300 依次推进面板与 `taplock` |
| `the_panels_draw_their_lines_and_unlock_the_tap_prompt` | CODE 570 view 0：面板 1 两行文字坐标与内容、颜色 c_white、面板 2 文案未出、无 Tap 提示；切面板 3 + `taplock=1` 后换成面板 3 文案并出现 (+150,+200) 的 "Tap to Continue"；底板/立绘三条 DrawCommand 精确几何（含 frame -3 透传） |
| `tapping_the_sheet_dismisses_it_and_lands_the_save_flag` | 释放主指 + draw 触发 CODE 570 末段销毁；CODE 566：`talkedtolloyd2=1`、`savefile.ini [Save] talkedtolloyd2=1` 真写入 ini 层、townmusic 进 host stop 队列、`audio_resume_all` 释放暂停、世界重新激活（active > 1）、obj_lloyd 被清、左右按钮重建、`roomstart=0` |
| `lloyd_retires_once_its_room_is_done_or_the_gun_is_bought` | CODE 674 两条独立闸门：`talkedtolloyd2=1` 自毁；`shotgunbought=1` 亦自毁；未触发的 rm_level1 Lloyd 存活 |
| `level7_lloyd_maps_onto_the_thirteenth_sheet_with_its_own_timeline` | CODE 673 房表把 rm_level7 交给 t13（不生成 t2）；t13 的五段面板时间轴 100/200/300/400/500 与 `taplock` 解锁点；townmusic 同样循环 |

## 边界

- 本批为**证据批**：零引擎改动。`instance_deactivate_all/activate_all`、
  `audio_pause_all/resume_all/stop_sound`、`ini_open/write_real/close`、
  `device_mouse_check_button_released`、`draw_sprite_ext`、
  `draw_set_font/color`、`draw_text`、`view_xview/view_yview` 数组全部走
  既有通道；
- 只实测覆盖 rm_level1(t2) 与 rm_level7(t13) 两张表；其余 14 张按同一模板
  （CODE 642 段、面板数与文案不同），未逐张铺开；
- 左/右虚拟按钮本身的触摸与 `alarm[1]` 效果已在 `ui_layer_ir.rs` 验收，
  本批只验证「对话框接管/交还按钮」这一生命周期；
- 文字**渲染**（TTF/点阵、字号、换行）属客户端 Framebuffer 层，本批只断言
  DrawCommand/TextCommand 的内容与几何，不等于像素级视觉验收。
