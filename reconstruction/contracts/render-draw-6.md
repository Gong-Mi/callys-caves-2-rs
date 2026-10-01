# 渲染 Draw 层批次 6：通关职员表、大结局面板、预告卡、首暂停小贴士与 IAP 覆盖层

全游戏渲染 Draw 层的最终收官批次。闭环最后 9 个 Draw CODE（`obj_endmusic` CODE 716、`obj_final` CODE 699、`obj_tease` CODE 703、`obj_firstpause` CODE 497、`obj_iapmenu` CODE 500、`obj_IAPstore` CODE 516、`obj_poisoniap` CODE 503、`obj_restoreiap` CODE 506、`obj_viewresolution` CODE 539）。全部经出货字节码在 IR 宿主上实测后固化，并与恢复 GML 交叉核对。

## 机制 1：通关演职员名单滚动系统（`obj_endmusic`，CODE 716）

击败 Herbert（Final Boss）后游戏进入结局并触发职员表控制器：
1. **音频与时间轴初始化（Create CODE 704）**:
   - `audio_stop_all()` 停播前置音轨；
   - `audio_play_sound(42, 0, 0)` 播放通关专属音乐 `mus_credits`（SOND 42）；
   - 装填跨越 3100 帧的完整 11 段 Alarm 梯队：
     * `alarm[0] = 50`: `drawcredit1 = 1`（"Art by 0HK0"）
     * `alarm[1] = 400`: `drawcredit2 = 1`（"And Yal"）
     * `alarm[2] = 700`: `drawcredit3 = 1`（"Code and Music", "by Jordan Pearson"）
     * `alarm[3] = 1000`: `drawcredit4 = 1`（"Additional Design", "& Music", "by Dave Stanich"）
     * `alarm[4] = 1300`: `drawcredit5 = 1`（"Testers:", "Dave Stanich", "Trish Doan", "Kim Pearson"）
     * `alarm[5] = 1600`: `drawcredit6 = 1`（"Stephanie di Bona", "TheUltimateGamerEver", ...）
     * `alarm[6] = 1900`: `drawcredit7 = 1`（"Written by Jordan Pearson", "& George Gordon-Tennant"）
     * `alarm[7] = 2200`: `drawcredit8 = 1`（"Vector Logos: Trish Doan"）
     * `alarm[8] = 2400`: `drawcredit9 = 1`（"For our Parents"）
     * `alarm[11] = 2660`: 触发 Alarm 11（CODE 705），调用 `instance_create(x, y, obj_final)` 呼出大结局最终面板。
2. **绘制派发（Draw CODE 716，1929 指令）**:
   - 根据当前被置位的 `drawcreditN` 标志，按视口居中输出纯白 (`c_white`, 16777215) 演职员信息，文字来自 bundle 字符串表 1179..1213。

---

## 机制 2：大结局面板与预告卡（`obj_final` / `obj_tease`）

1. **大结局剧终面板（`obj_final`，CODE 699 Draw）**:
   - Create (CODE 694)：`instance_deactivate_all(true)` 强行冻结背景并置位 `drawpanel1 = 1`；
   - Panel 1：在视口绘制 `spr_theend`（精灵 176）；
   - Panel 3 + `taplock == 1`：在 `(vx + 140, vy + 220)` 输出提示 "Tap to Continue"（STRG 743）；
   - 点击退场：触发 Destroy 写入通关标志并清理场景。
2. **续作预告卡（`obj_tease`，CODE 703 Draw）**:
   - 在挑战房 5 (`rm_challenge5`) 开启终极宝箱 `obj_finalchest` (101, CODE 454) 时实例化；
   - 居中绘制预告卡片 `spr_tease`（精灵 162，"Cally's Caves 3"）。

---

## 机制 3：首次暂停教学贴士与排他性抑制（`obj_firstpause`，CODE 497）

1. **首暂停界面**:
   - 绘制全屏深色幕布 `spr_pause` (123) 与 Lloyd 头像 `spr_lloyd` (152)；
   - 在 `(vx + 90, vy + 135)` 输出标题 "Lloyd's Tip:"（STRG 970），并在下方输出两行具体玩法提示（`tips1`, `tips2`）。
2. **确认弹窗抑制机制**:
   - 原版字节码检测 `if (!instance_exists(obj_areyousure))`；
   - 当玩家在暂停菜单点击数据擦除（弹出 `obj_areyousure` 114 二次确认框）时，Lloyd's Tip 相关文本与立绘**自动隐藏**，防止二次确认提示被文字遮挡。

---

## 机制 4：IAP 内购展台与购买恢复（CODE 500, 503, 506, 516）

1. **IAP 菜单幕布（`obj_iapmenu`，CODE 500 Draw）**: 绘制 `spr_pause` (123) 幕布。
2. **IAP 商店入口按钮（`obj_IAPstore`，CODE 516 Draw）**: 在 `(vx + 315, vy + 1)` 绘制 `spr_iap` (121)。
3. **毒性子弹强化礼包（`obj_poisoniap`，CODE 503 Draw）**: 绘制底座，输出 "Poison Bullets, Gems & Remove Ads:"（STRG 992）与 "$0.99"（STRG 993）。
4. **恢复内购按钮（`obj_restoreiap`，CODE 506 Draw）**: 绘制按钮框，输出 "Restore Purchases:"（STRG 996）；当恢复成功（`drawpurchase == 1`）时，文本自动切换为 "Purchases Restored!"（STRG 997）。

---

## 测试套件

`crates/core/tests/ending_and_menus_draw_ir.rs`（4 项测试全部通过）:
1. `firstpause_draws_lloyd_tip_and_suppresses_under_confirmation`: 验证 Lloyd's Tip 渲染，及在 `obj_areyousure` 对话框存在时的自动抑制逻辑。
2. `iap_store_and_restore_purchases_overlays`: 验证 IAP 菜单底板、IAP 按钮、礼包价格与购买恢复 "Purchases Restored!" 文本切换。
3. `ending_credits_sequence_plays_music_and_rolls_staff_pages`: 验证 credits 音乐播放、50/400/700/1000 帧职员表滚动及 Alarm 11 派发生成 `obj_final`。
4. `finale_the_end_panels_and_teaser_card`: 验证 `spr_theend` (176) 绘制、Panel 3 "Tap to Continue" 解锁提示与 `spr_tease` (162) 预告卡。

---

## 渲染 Draw 层全面闭环审计

全游戏 **118 个 Draw CODE** 至此全部完成实测与契约闭环：
- 批次 1 (da3d0ed): 6 CODE (HUD / 弹字 / 死亡界面 / 持枪覆盖层)
- 批次 2 (ed56bf6): 6 CODE (五触控按钮 + 武器切换挂件)
- 背景层 (6f0b442): 1 CODE (obj_bg draw_background)
- 批次 3 (6287e71): 41 CODE (全实体受击红/白闪烁 + 20 族出场横幅)
- 批次 4 (b2c5c45): 20 CODE (商店强化台座 + 翻页 + 武器获得庆祝屏)
- 批次 5 (0bc1e3f): 12 CODE (升级徽章 + 战斗飘字 + 音频开关 + 擦除对话框 + 暂停控制)
- 批次 6 (本批): 9 CODE (职员表 + 大结局面板 + 预告卡 + 首暂停 + IAP 覆盖层)
- 教程对话 (lloyd_tutorial_ir): 16 CODE (16 个 obj_lloydtutorialN)
- 其他过场/分辨率 (game_start_p0 等): 7 CODE (obj_viewresolution, obj_logo, obj_phone, obj_introduction 等)

**合计：118 / 118 全量闭环，无任何遗漏。**
