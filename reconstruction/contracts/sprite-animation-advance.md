# 精灵动画推进契约（sprite animation advance）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 原版语义（恢复 GML 证据）

- 标准 GMS 每步周期：实例 Step 之后 `image_index += image_speed`，正向越过
  `image_number` 回绕（wrap），负速在 0 处反射（reflect），单帧精灵不动。
- 1,354 份 CODE 中 20 处写 `image_speed`（无负值）：
  - CODE 548 obj_introduction Create：`image_speed = 0.3`（序章胶片 96 帧）；
  - CODE 12 obj_player Step：`room == rm_ending` 分支 `image_speed = 0.6`；
  - CODE 382/384/386/388/390/392/394/396/398/400/402 等武器 Create：
    `image_speed = 0`（商店图标定格首帧）；
  - CODE 10/45/53/61 精灵切换处 `image_index = 0` 复位。
- 帧数来自 SPRT 记录：178 精灵中 99 个多帧（spr_player 18、spr_playerrun 8、
  spr_playerslash 6、spr_playerjump 25、spr_playerfall 20、spr_knifebandit 48、
  spr_bat 54、spr_gem 26、spr_silvercoin 9 …），由 `crates/asset` 的
  `SpriteData.tpag_indices` 长度携带。
- 休眠域（obj_bg Alarm 2，CODE 361）：距玩家 ≥450px 的敌人/掉落物被
  `instance_deactivate_object` 冻结，不跑步进事件——动画同样必须冻结。

## Rust 实现（`crates/core/src/ir_scene.rs`）

1. `SpriteBounds.frames`：SPRT 帧数，0 = 无动画数据（永不推进）。
2. `Scene::tick` 运动积分段第 5 步：`image_index += image_speed`；
   - `frames > 1`：正向 `next %= frames`；负向三角反射到 `[0, frames-1]`；
   - `frames == 1`：钉回 0；`frames == 0` 或未知精灵：不动；
   - 仅 `alive && active && !external` 实例参与（与移动积分同一谓词）。
3. `self_field` 新增只读 `image_number`/`image_single`：按实例当前
   `sprite_index` 查 `sprite_bounds`，无数据返回 0（未初始化读 0 纪律不变）。
4. 客户端接入（`crates/client/src/lib.rs` enable_ir_gameplay）：帧数以
   `tpag_indices.len().max(1)` 填充；既有 fixture 无帧数据精灵填 `frames: 1.0`
   保持定格首帧旧行为，不制造隐式动画。

## 测试（`crates/core/tests/sprite_animation_advance_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `image_index_advances_by_image_speed_and_wraps_over_frames` | 整数速 0→1→2→3→0 回绕；CODE 548 型 0.3 分数速逐帧累加并回绕 |
| `single_frame_sprite_stays_clamped_and_reversed_play_reflects` | 单帧钉 0；负速 0→0.5 反射、反射点镜像 |
| `draw_view_emits_advancing_frames_and_image_number_reads` | DrawCommand.frame 序列 [1,2,3,0,1,2]；image_number 读出 SPRT 帧数 |
| `rm_level1_bandit_and_player_animation_runs_from_real_bytecode` | 真实 rm_level1 字节码驱动：bandit 激活期推进、CODE 361 休眠后冻结且帧始终在窗内；玩家被 CODE 12 连续改写 sprite_index 下 40 帧仍持续推进且不越界 |

## 边界

- image_speed=0 与未注册精灵（frames 0）保持首帧，与商店图标 CODE 行为一致。
- 帧读取到 GPU 光栅化仍走既有 `draw_sprite_alpha(frame % len)` 取模，本批只
  补引擎推进与只读元数据；Android 真机视觉验收需单独一轮（CI 绿≠真机已验）。
