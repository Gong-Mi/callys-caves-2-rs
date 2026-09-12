# obj_weaponchange 切换演出覆盖层契约（weaponchange overlay）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 触发拓扑（恢复 GML 取证）

武器跨过 4/7/10 级质变时，obj_UI Alarm 0（CODE 368）的 36 组
`level==X && drawchange<X>` 门闩（fresh start 由 CODE 17 预置全部 drawchange*=1）
清标志、置 `drawweaponchange=1`，末尾统一 `instance_create(x, y, obj_weaponchange)`。
本批真实走该链：`pistollevel=4` + drawchangepistol4=1 → dispatch UI Alarm 0。

## obj_weaponchange（id 83）生命周期

1. **CODE 409 Create**：`audio_pause_all()`（全语音 paused，is_playing 门随即
   为假）；`instance_deactivate_all(true)` 冻结除自身外全部实例（含玩家——
   GMS 语义：true=保留当前实例）；mute 门后播 snd_weaponlevelup（SOND 28）；
   `taplock=0; alarm[0]=70`。
2. **CODE 411 Alarm 0**：70 tick 后 `taplock = 1`。
3. **CODE 413 Draw**：view 0 合成 `spr_pause(123)` 480×320 幕布（scale
   0.96/0.8）、taplock 门后 `draw_text "Tap to Continue"`，并按当前
   `pistollevel` 画 "Your Pistol is now level 4!" 与 spr_gunpistol 帧 1 大图。
4. **CODE 412 Step**：`taplock==1 && mouse_check_button_pressed(mb_left)` →
   `instance_destroy()`（引擎面 `mouse_pressed`，与序章/商店同一输入通路）。
5. **CODE 410 Destroy**：musicmute 门外 `audio_resume_all()` +
   `instance_activate_all()`——整世界解冻，巡逻物理当场恢复。

## 测试（`crates/core/tests/weaponchange_overlay_ir.rs`）

`weaponchange_overlay_freezes_the_world_then_tap_restores_it`：
- 真门闩触发（drawchange 消费、latch 清零）+ 覆盖层实例化；
- Create 内联效应：SOND 28 排队、alarm[0]=70、bandit/玩家/全场 active=false
  而覆盖层自身保持 active；
- 70 tick 世界冻结期间 bandit 的 x 严格不动（不是隐身，是不步进）；
- CODE 411 解锁 taplock；CODE 413 draw_view 产出幕布 sprite 123、
  "Tap to Continue"、"Your Pistol is now level 4!" 三命令，冻结 bandit 零绘制；
- CODE 412 左键按下销毁覆盖层；CODE 410 解冻全场（alive 即 active）、
  audio_voices paused 清零；
- 后续 20 tick bandit 巡逻位移恢复——闭环「冻结→解冻→再步进」。

## 施工中的一处自纠

初版断言 "player frozen too" 逻辑写反（`!any(!active)` 实为「无人被冻」，
恰好被 CODE 409 正确冻结所打破）——按真实目标语义改正为
`any(object==0 && alive && !active)`，非实现缺陷，RED→GREEN 有效。

## 边界

- 4/7/10 三档 × 12 武器的门闩组合共享同一 `drawweaponchange` 出口，本批
  以 pistol-4 代表链取证；spr_gunpistol 帧选择（0..3 按 level 段）在 Draw
  断言中未逐帧核对；
- obj_firstpause/obj_pause 家族（同 pause 素材）是另一条覆盖层链，未入本批；
- 真机演出观感（幕布+横幅+音效停顿感）待真机层验收。
