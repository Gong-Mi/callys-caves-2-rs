# 武器切换 HUD 旋转梯契约（weaponswap rotation ladder）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 触发拓扑（全量 IR 扫描 + 恢复 GML 取证）

1,354 CODE 中把选择器 126（obj_weaponswap）的 alarm 当左值写的只有 CODE 520
自身——武器按钮不走实例 Mouse_6，而是 HUD Draw 轮询（与左/右键 CODE 522/525
同构）：

1. **CODE 520（obj_weaponswap Draw，对象 126 无 Create 事件）**：
   每帧把图标 `spr_weaponswap(151)` 钉到 `view_xview[0]+360, view_yview[0]`
   并同步实例 x/y；随后对设备 0..4 检查
   `device_mouse_check_button_released(i, mb_left) && collision_point(
   device_mouse_x(i), device_mouse_y(i), obj_weaponswap, 0, 0)` →
   `alarm[0] = 1`。
2. **CODE 519（Alarm 0，3,981 条指令）**：
   - `audio_is_playing(snd_weaponswap)` 防叠门 → 播放 SOND 5；
   - `global.weaponswapped += 1` **原样双写**（反编译逐句保留，两连击）；
   - 购买顺序旋转梯（60+ 分支）：`pistol && shotgunbought` → shotgun；
     否则逐级 assaultrifle→rocket→icegun→laser→bow→bladegun→flamethrower→
     boomerang→spikegun→bombgun→回到 pistol；当前武器同款收尾
     （如 `shotgun && 无后续购买` → pistol）；每次选中新武器即清零其余 11 项；
   - 尾部 `instance_create(obj_player.x - 16, obj_player.y, obj_weaponname)`。
3. **CODE 462（obj_weaponname Create）**：`vspeed=-6` 上飘、`image_speed=0`
   定格，`damage` 按当前 global 武器标志写成 STRG 标签 id（Pistol=843、
   Shotgun=844，顺序 if 链——后命中的选中武器覆写标签）。

## 测试（`crates/core/tests/weaponswap_rotation_ir.rs`）

合成输入仅限设备释放事件（touch_devices 是引擎既有输入面，非伪造状态）：

| 用例 | 断言 |
| --- | --- |
| `hud_release_arms_ladder_and_rotates_pistol_to_shotgun` | Draw 钉位 (360,0) 后 icon 中心释放 → a0=1；无购买时旋转保持 pistol（末分支）且 weaponswapped += 2（双写取证）；置 shotgunbought 再点 → shotgun=1/pistol=0、snd_weaponswap(5) 过 is_playing 门、标签代次：首轮 Pistol(843) 次轮 Shotgun(844)（每次切换各浮一条）；标签生成坐标 = 派发瞬间 player.x−16 / player.y−6（同 tick 运动积分吃掉一帧上飘，trace 488=494−6）；不释放不重武装 |
| `ladder_follows_purchase_order_from_shotgun_to_assaultrifle` | shotgun 选中 + riflebought → assaultrifle；rifle + 无 rocketbought → 绕回 pistol；weaponswapped 每轮 +2；最新标签读 Pistol |

## 施工中的真实修正（调试 example 逐帧取证）

- 标签 y 断言初版差 6：CODE 519 的 instance_create 在玩家 Alarm 相位（先于
  运动积分），标签自身 vspeed=−6 在同一 tick 的积分段生效——断言改为
  player.y − 6 并记录该相位；
- 标签代次断言初版取错实例：每次切换都新浮一条 obj_weaponname（旧条尚未
  飘完生命周期），首轮标签 Pistol(843)、次轮 Shotgun(844)——`instance_create`
  在 CODE 519 尾部、旋转完成后执行，标签携带的是当次选择结果；断言按
  「最大 id 实例读 Shotgun + 历史存在 Pistol 标签」双条核对。

## 边界

- 旋转梯静态穷举 60+ 分支不经济；本批以代表性转移链（pistol→shotgun、
  shotgun→assaultrifle、rifle→wrap→pistol、无购买自锁）取证分支机器，
  其余分支共享同一 `global.X = 1; 其余 = 0` 模板。
- 真机触摸到 device 索引的映射（多指 0..4）在 Java 层已有 pointer 管线，
  本批走引擎输入面；实机 HUD 点击手感待真机验收。
- obj_weaponchange（切换动画覆盖层，CODE 409~413）与 obj_muting 的
  weaponswap 音量门未在本批链路内。
