# 武器获取链与洞窟→矿道拓扑契约（weapon acquisition）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 一、拓扑纠正（重要，前几批的门卡描述有误）

按房间**编号**逐条核对（编号即 `room_goto` 的实参）：

| 编号 | 房间 | 本房出口门卡 | 落点 |
| --- | --- | --- | --- |
| 8 | rm_level8 | 819→7 / **820→9** | (1888,140) / (128,1132) |
| 9 | **rm_level8a**（不是 rm_level9） | 821→10 / 822→8 | (160,140) / (1888,236) |
| 10 | rm_boss1 | 823→9 / **824→11** | (1888,1164) / (128,524) |
| 11 | **rm_level9**（Mines 首关） | 825→10 / 826→12 | (1120,364) / (224,140) |

因此：**Mines 的真正入口是 rm_boss1 的 CODE 824（warproom 11）**，而不是
rm_level8 的 CODE 820（那是去 8a 支线房）。rm_boss1 内 `obj_bossboulder`(3)×2
依旧是物理封门，`obj_trex`(25) 驻场。

## 二、武器拾取：两事件小对象

`obj_shotgun`(73, spr 127) 与 `obj_assaultrifle`(74, spr 129) 完全同构：

1. **CODE 386 / 388 Create**：`image_speed = 0`；若 `global.{w}bought == 1`
   → `instance_destroy()`（**已买过的枪在换房重载时自动消失**）；否则生成
   `obj_pickupflare`(70)——散弹枪在 `(x, y-16)`，步枪在 `(x+8, y-14)`。
2. **CODE 387 / 389 Step**：`distance_to_object(obj_player) <= 1 &&
   global.{w}bought == 0` → 生成 `obj_foundweapon`(82)、置
   `global.{w}bought = 1` 与 `global.{w} = 1`，并把**其余 11 把武器全部置 0**
   （独占武器槽，含 `global.pistol = 0`），最后 `instance_destroy()`。

## 三、`obj_pickupflare`(70)：漂浮信标

CODE 380 `alarm[0] = 30`；CODE 381 每 30 帧重挂，且
`distance_to_object(obj_player) <= 30` 时 `instance_destroy()`。**远看常亮、
近身熄灭**（双向已断言）。

## 四、`obj_foundweapon`(82)：第二套「冻结世界」过场

| CODE | 事件 | 行为 |
| --- | --- | --- |
| 404 | Create | `audio_pause_all()`、`instance_deactivate_all(true)`、`global.soundmute == 0` 时 `audio_play_sound(snd_pickupstinger, 0, false)`（SOND 27）、`taplock = 0`、`alarm[0] = 70` |
| 406 | Alarm 0 | `taplock = 1`（70 帧后解锁点击） |
| 407 | Step | `taplock == 1 && mouse_check_button_pressed(mb_left)` → `instance_destroy()` |
| 408 | Draw | 按 `view_current` 铺 `spr_pause`(123) 底板；按**当前生效武器**（`global.shotgun == 1` 等）叠该武器贴图与标题，view 0 为 `spr_gunshotgun` 于 `(+220,+120)`、缩放 7，标题 "You have found the Shotgun!" 于 `(+80,+30)`，"Tap to Continue" 于 `(+150,+200)` |
| 405 | Destroy | `global.musicmute == 0` 时 `audio_resume_all()`、`instance_activate_all()` |

## 测试（`crates/core/tests/weapon_acquisition_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `the_shotgun_pickup_flips_the_whole_weapon_row` | CODE 386 信标落点 (x, y-16) 且 `alarm[0]=30`；拾取前唯一生效武器是 pistol；CODE 387 后 `shotgunbought=1`、唯一生效武器变 shotgun、foundweapon 生成在拾取物自身坐标 |
| `the_pickup_beacon_retires_only_next_to_the_player` | CODE 381 双向：远距（2000px）30 帧后仍存活且 `alarm[0]` 重挂回 30；近身（同点）31 帧内自毁 |
| `the_found_weapon_banner_freezes_the_world_and_unlocks_on_a_tap` | CODE 404 全场停摆（只剩 banner active）、`taplock=0`、`alarm[0]=70`、pickupstinger 入队；70 帧后 `taplock=1`；CODE 408 view 0 精确几何（spr_gunshotgun 帧 0 于 (+220,+120)×7、标题 (+80,+30)、Tap 提示 (+150,+200)、spr_pause 底板）；左键按下 → CODE 407 销毁 → CODE 405 重新激活世界与音频 |
| `an_already_bought_weapon_leaves_no_pickup_in_the_room` | 带 `shotgunbought=1` 从 rm_level2 折返 rm_level1：CODE 386 令拾取物在房载时自毁，信标也不生成，已购武器跨房存活 |
| `level8_swarm_hands_over_to_the_mines_door` | CODE 818 落点 (160,428)、卡司 14×3/15×8/23×1（迄今最密人形群）、两门 819→7/(1888,140) 与 820→9/(128,1132)、落点 20 帧无伤 |
| `the_cave_area_hands_over_through_level8a_and_the_boss_arena` | 真实门链 8→9→10→11：rm_level8a 卡司 14×5/15×3/16×2/23×3 与门 821/822；rm_boss1 内 bossboulder×2 与 obj_trex(25)×1 与门 823/824；rm_level9 卡司与门 825/826 |
| `the_mines_assault_rifle_mirrors_the_shotgun_path` | CODE 388 信标偏移改为 (x+8, y-14)（与散弹枪的 (x, y-16) 不同）；CODE 389 后 `assaultriflebought=1`、唯一生效武器是步枪、同一套 70 帧 banner 时间轴 |

## 施工中的自纠

- 首版把 CODE 820 当作 Mines 入口（沿用前批总结），实测 room 9 是
  **rm_level8a**；真正入口是 boss1 的 CODE 824→room 11。已按房间编号重排
  拓扑表，并把「门牌标签」写进测试注释；
- `obj_trex` 初版按 12 断言（错），实为 **25**；
- 信标远距断言初版取 31 帧，读到 `alarm[0] == 29`（30 帧处触发并重挂后又被
  扣 1），改为 30 帧断言 30；
- 信标近身断言初版把玩家位置只写一次，玩家自身 Step 的重力使其漂离夹具，
  改为每帧重钉。

## 边界

- 本批为**证据批**：零引擎改动（`instance_deactivate_all/activate_all`、
  `audio_pause_all/resume_all`、`mouse_check_button_pressed`、
  `distance_to_object`、`draw_sprite_ext/text` 全走既有通道）；
- 武器**切换 UI**（obj_weaponswap 的购买阶梯轮转）已在
  `weaponswap_rotation_ir.rs` 验收，本批只验证「哪把枪是当前生效武器」这一
  独占槽语义；
- rm_level8a / rm_level9 的敌人行为（含新模具 obj_shooter1 的远程链）已在
  level7 批次与后续批次分别验收，本批只断言卡司与门链；
- 拾取物的像素级视觉（贴图/闪烁帧）属客户端渲染层，本批只断言
  DrawCommand/TextCommand 内容与几何。
