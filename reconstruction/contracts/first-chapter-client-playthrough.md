# 第一章客户端可玩闭环：序章 → Boss 1 → Mines 门

本契约把「序章到第一个关底 BOSS」从**数据/字节码层**（`first_chapter_flow_ir.rs`、
`boss1_trex_kill_chain_ir.rs`）推进到**出货客户端帧循环层**：`GameState::new` +
`obj_introduction` 序幕场景 + `enable_ir_gameplay` + `step` + `pointer_released` +
`draw_frame`，即 Android APK 真实走的入口。测试入口
`crates/client/tests/first_chapter_playthrough.rs`（4 项）。

## 本批修复的真实缺陷：输入边沿在 Draw 之前被清除

原版帧序是「平台输入更新 → Alarm/Step/Collision → Draw → 下一帧」：一次触摸的
`pressed`/`released` 边沿对**同一帧的所有事件**可见，Draw 也在内，下一帧才复位。
而本引擎 `Scene::tick` 在**末尾**清 `mouse_pressed` 与四个虚拟设备的
`pressed`/`released`，客户端又在 `tick` **之后**才跑 `draw_view`——于是所有在
Draw 事件里读输入边沿的原版控件全部失效。

RED 实测（客户端路径，修复前）：

| 原版控件 | 读法 | 修复前实测 |
| --- | --- | --- |
| obj_shootbutton Draw（CODE 522 族） | `device_mouse_check_button_pressed` | 按住射击键 3 帧 + 释放 + 6 帧：`obj_bullet(39)` 存活数 = **0** |
| obj_jumpbutton Draw | `device_mouse_check_button_pressed` | 按住跳跃键 4 帧：玩家 y 494 → 494、`vsp` = 0（根本没离地） |
| obj_lloydtutorial1..16 Draw | `device_mouse_check_button_released` | 序幕镇教学对话框 taplock=1 后，真实手指释放（`pointer_released`）→ 面板仍存活、世界仍冻结（永久卡死） |
| obj_foundweapon Step（CODE 407） | `mouse_check_button_pressed` | 客户端只在序幕路径写 `scene.mouse_pressed`，游戏中恒 false → 「You have found the Shotgun!」横幅（rm_level1 必经拾取）永久冻结 |

结论：这不是「手感问题」，而是序章第一个教学面板就会永久冻结、以及无法开枪
（= 无法击杀 Boss 1）的硬阻断，「序章到第一个关底 BOSS」在真机上不可达。

## 修复（保持原版语义，不引入新机制）

1. `Scene::end_frame()`：把 `mouse_pressed` 与设备 `pressed`/`released` 的复位
   从 `tick` 末尾移出，作为**显式帧边界**，由同时负责 Draw 的一方在
   `draw_view` 之后调用。`down` 是物理状态，不在复位之列。原版 `mouse_clear`
   在 tick 内清设备状态的行为保持不变（对话框 Create 正是要在同帧 Draw 前清掉）。
2. 客户端两条路径（序幕、游戏）都在 `draw_view` 后调用 `scene.end_frame()`。
3. 四个虚拟设备改为真正的**单帧边沿**：`pressed = held && !prev_held`、
   `released = !held && prev_held`、`down = held`。此前 `pressed` 在按住期间
   每帧都为真，若只挪动清除位置就会把「一次点击」放大成「按住连发」，与原版
   手枪语义不符。
4. 游戏中补上全局 mb_left：`scene.mouse_pressed = input.tap && !tap_was_active`，
   并把 Java 的 `tapPulse`（多帧）钉成单帧边沿，供 `obj_foundweapon` /
   `obj_weaponchange` 的 Step 检查使用。
5. `pointer_released`（Java `nativePointerRelease`）同时落到**设备 0**并携带真实
   逻辑坐标：原版 runner 的首触点就是设备 0，故任意位置的单击都能被
   `device_mouse_check_button_released(0, mb_left)` 看见（教学面板、
   obj_weaponswap），而不再只认左下移动区。

## 测试覆盖（`crates/client/tests/first_chapter_playthrough.rs`）

| 用例 | 断言 |
| --- | --- |
| `the_prologue_hands_over_to_town_and_the_town_tutorial_dismisses_on_a_real_tap` | 序幕 120 帧前点击不跳、序幕后 framebuffer 非黑、落 rm_town、Room Start 锁 10 tick 后自动解锁；走到 obj_lloyd 触发房间专属对话框（世界只剩它 active、左右按钮被销毁）；600 tick 后面板时间轴解锁 taplock；**真实 `pointer_released`** 关闭面板并落 `talkedtolloyd1`、世界复活、控件重建、画面恢复 |
| `the_level1_shotgun_banner_takes_a_real_tap_to_resume` | rm_level1 的真实 obj_shotgun 拾取 → 世界冻结 + `shotgunbought=1` + 拾取物消失；70 tick 后 taplock 解锁；**真实 tap** 关闭横幅、世界复活、shotgun 武器行生效、画面恢复 |
| `every_chapter_door_from_town_to_boss1_loads_and_renders` | 镇 → level1 → level2 → level3 → level4 → level5 → level6（宝库支线）→ level5 → level7 → level8 → level8a（武器支线）→ rm_boss1 逐门真 CODE 13 命中换房；每房渲染非黑、玩家唯一存活、无 `runtime_diagnostic`；到 Boss 1 时 trex 1 只、封门巨石在、`boss1dead=0` |
| `the_shoot_button_kills_boss1_and_the_freed_door_enters_level9` | 用**真实射击键输入**（pressed 边沿 → obj_shootbutton alarm → 玩家 CODE 11）打出真实子弹；`hptrex=1` 时一枪致死，CODE 284 命中 → CODE 160 死亡级联 → `boss1dead=1`、trex 移除；35 tick 内 CODE 29 清空封门巨石；走 CODE 824 门进入 rm_level9，画面非黑 |

## 两个夹具纪律（本批实证）

- **门会睡觉，不是门链缺失**：`obj_bg` Alarm 2（CODE 361）对 `obj_warpanywhere`
  等对象按 `distance_to_object(obj_player) > 480` 执行
  `instance_deactivate_object`，同时又用 `instance_activate_region(obj_bg.x-400,
  obj_bg.y-400, 800, 800, true)` 唤醒区域内的全部实例（每 2 tick 一次）。
  实测：进 rm_town 后 17 帧，177 个实例有 143 个 active，两张门都
  `alive=true, active=false`。夹具必须**先把玩家写到门上**再步进等 sweep 唤醒，
  不能把休眠当缺门。
- **教学面板就是进度门**：`obj_lloydtutorialN` 用 `instance_deactivate_all(true)`
  冻结全世界，房里任何门在被点掉之前都不可达（这也解释了为什么 walk 夹具要先
  清面板），其 tap 解锁点在各自面板时间轴末端（最长 600 tick）。

## 边界

- 只验证到**设备 0 + 三个合成按钮区**的主指模型。多点触控里「非主指」的释放
  Java 侧 `PointerReleaseQueue` 本就不上报（`pointerId != primary` 直接丢弃），
  故第二个手指的 UI 点击不在本批范围。
- 桌面（`--features desktop`）键盘路径未改语义；它仍走同一套设备合成。
- 仍未做真机/GPU 视觉与音频验收（CI 绿 ≠ 真机已验），也未验证触感强度。
- 镜头/平移等序幕动画只是逐帧跑过，未与原始 runner 逐像素比对。