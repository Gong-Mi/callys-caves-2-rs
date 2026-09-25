# 渲染 Draw 层批次 5：升级光效徽章、战斗飘字、音频开关与数据擦除对话框

覆盖升级通告、战斗飘字浮动提示、设置音频切换控件、数据擦除二次确认对话框以及暂停主控层，共 12 个 Draw CODE。全部经出货字节码在 IR 宿主上实测后固化，并与恢复 GML 交叉核对。

## 机制 1：角色与武器升级通告（`obj_levelup` / `obj_weaponlevelup`）

1. **角色升级浮动徽章（`obj_levelup`，CODE 356 Draw）**:
   - Create (CODE 352)：`vspeed = -1`（向上飘升），播放 `snd_levelup`（SOND 27），`showpart = 1`，装填 `alarm[0] = 40` 与 `alarm[1] = 94`；
   - Draw 0 (CODE 356)：调用 `draw_self()` 绘制 `spr_levelup`（精灵 35）；在 `showpart == 1 && global.level >= 2` 时调用 `part_particles_create` 经 `P_System2` 持续喷发升级金光粒子；
   - Alarm 0 (CODE 354)：40 帧后置 `showpart = 0`，停止金光粒子生成；
   - Alarm 1 (CODE 353)：94 帧后调用 `instance_destroy()` 自毁。
2. **武器升级横幅（`obj_weaponlevelup`，CODE 359 Draw）**:
   - Create (CODE 357)：播放 `snd_weaponlevelup`（SOND 25），装填 `alarm[1] = 90`；
   - Draw 0 (CODE 359)：在玩家上方 `(player.x - 60, player.y - 60)` 绘制 `spr_weaponlevelup`（精灵 34）；
   - Alarm 1 (CODE 358)：90 帧后调用 `instance_destroy()` 自毁。

---

## 机制 2：战斗浮动文字与淡出销毁（`obj_weaponname` / `obj_dodged`）

1. **武器切换/伤害飘字（`obj_weaponname`，CODE 464 Draw）**:
   - Create (CODE 462)：`vspeed = -2`，`alpha = 1`，将选中的武器名称（或伤害数值）存入 `damage` 字段；
   - Draw 0 (CODE 464)：按 `view_current` 匹配视口字体，调用 `draw_text_color(x, y - 20, damage, c_white, c_white, c_white, c_white, alpha)`；
   - Step 0 (CODE 463)：每帧递减 `alpha -= 0.04`，当 `alpha <= 0`（25 帧寿命）时触发 `instance_destroy()`。
2. **闪避成功飘字（`obj_dodged`，CODE 467 Draw）**:
   - 玩家穿戴闪避强化并在受击时判定成功触发：实例化 `obj_dodged` (106)；
   - Create (CODE 465)：`speed = 2`，随机起跳角度，`alpha = 1`；
   - Draw 0 (CODE 467)：`draw_set_font(2)` + `draw_set_color(c_white)`，在 `(x, y - 20)` 输出 STRG 索引 856 "Dodged!"；
   - Step 0 (CODE 466)：每帧递减 `alpha -= 0.04`，25 帧后自毁。

---

## 机制 3：音频设置切换控件（`obj_volume` / `obj_volumemusic`）

1. **音效开关（`obj_volume`，CODE 469 Draw）**:
   - 绘制按钮框 `spr_weaponbox` (153)；
   - 根据全局状态 `global.soundmute` 分支输出文本：
     * `soundmute == 0` → 输出 "Sounds: ON"（STRG 857）；
     * `soundmute == 1` → 输出 "Sounds: OFF"（STRG 858）。
2. **音乐开关（`obj_volumemusic`，CODE 473 Draw）**:
   - 绘制按钮框 (153)；
   - 根据全局状态 `global.musicmute` 分支输出文本：
     * `musicmute == 0` → 输出 "Music: ON"（STRG 860）；
     * `musicmute == 1` → 输出 "Music: OFF"（STRG 861）。

---

## 机制 4：数据擦除二次确认对话框（CODE 479, 482, 484, 487）

1. **擦除入口按钮（`obj_restoredata`，CODE 487 Draw）**:
   - 绘制按钮框并在 `(x + 12, y)` 输出 "Erase Data"（STRG 873）；点击触发对话框展开。
2. **二次确认提示（`obj_areyousure`，CODE 484 Draw）**:
   - 输出警告提示 "Erase Data?"（STRG 871）。
3. **确认与取消按钮**:
   - `obj_yesrestoredata` (CODE 479 Draw)：输出 "Yes"（STRG 869）；
   - `obj_norestoredata` (CODE 482 Draw)：输出 "No"（STRG 870）。

---

## 机制 5：暂停主控与 HUD 暂停按钮（`obj_pausebutton` / `obj_pause`）

1. **HUD 暂停按钮（`obj_pausebutton`，CODE 518 Draw）**:
   - 在正常游戏循环中，固定在 `(view_xview + 320, view_yview + 0)` 绘制暂停图标按钮 `spr_pausebox` (122)；
   - 点击时实例化 `obj_pause`。
2. **暂停幕布与世界冻结（`obj_pause`，CODE 510 Draw）**:
   - Create (CODE 507)：执行 `instance_deactivate_all(true)`，将整场游戏（包含 HUD 暂停按钮与玩家）冻结停摆；
   - Draw 0 (CODE 510)：绘制全屏深色幕布 `spr_pause` (123)，并在界面上投射当前金币结余 `string(score)`。

---

## 夹具陷阱与实测固化

1. **粒子系统宿主依赖**: `obj_levelup` 生成金光粒子依赖 `global.P_System2` 与 `global.Particle2`，若未由 `obj_pwrlevelinitialize` (103) 初始化则无法发射粒子。
2. **飘字衰减步长**: `obj_weaponname` 与 `obj_dodged` 字节码实测每步固定衰减 `alpha -= 0.04`（非 0.03/0.05），恰好 25 帧完全淡出自毁。
3. **暂停排他性冻结**: `obj_pause` 具有 `instance_deactivate_all(true)` 强排他语义，创建后仅自身存活派发 Draw；HUD 暂停按钮不可在暂停态中同时断言绘制。

---

## 测试套件

`crates/core/tests/pause_and_floaters_draw_ir.rs`（5 项测试全部通过）:
1. `levelup_and_weapon_levelup_draw_badges_and_particles`: 验证 spr_levelup (35) 与 spr_weaponlevelup (34) 绘制、粒子发射、40 帧粒子关闭、90 帧与 94 帧生命周期销毁。
2. `combat_floaters_draw_damage_and_dodged_with_alpha_fade`: 验证伤害飘字与 "Dodged!" (856) 绘制、0.04 逐帧淡出及 25 帧自毁。
3. `audio_toggles_render_on_and_off_labels`: 验证音效/音乐开关分别渲染 "Sounds: ON/OFF" 与 "Music: ON/OFF" 标签。
4. `erase_data_dialog_renders_confirmation_prompts`: 验证 "Erase Data"、"Erase Data?"、"Yes"、"No" 四段对话框元素对齐。
5. `pause_backdrop_and_hud_button`: 验证正常游戏中的暂停按钮绘制与进入暂停后的幕布及金币渲染。

---

## 边界与未验层

- 本批闭环了升级徽章、战斗飘字、音频切换与数据擦除共 12 个 Draw CODE；
- 剩余 Draw 事件主要为 Lloyd 教程对话框（16 个 CODE）与片头/结局序列；
- 真机/GPU 视觉层未验收（NOT RUN）。
