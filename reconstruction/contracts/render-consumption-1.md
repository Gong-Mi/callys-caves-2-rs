# 客户端像素消费批次 1：DrawCommand 全字段与 draw_healthbar 三色

渲染 Draw 层批次 1..6 已把 118 个 Draw CODE 全部在 IR 宿主上闭环（命令侧 100%），但客户端光栅化器当时只消费 `sprite / frame / x / y / scale / alpha` 六个字段：精灵按帧左上角落位（忽略 SPRT origin）、`image_xscale = -1` 朝向翻转被 `.max(1.0)` 压成 1 像素列、`image_angle` 完全忽略、`image_blend` 与 `d3d_set_fog` 受击闪烁都不上色、`draw_healthbar` 用自造红→绿渐变压掉了原版三色。本批把命令里剩下的字段真正画到像素上。

## 机制 1：SPRT origin 锚点与朝向镜像

- **原版语义**：`draw_sprite_ext` / `draw_self` 的 `(x, y)` 是**精灵原点**落点，实例几何一律以原点展开；20 族敌人与玩家的朝向用 `image_xscale = 1 / -1` 表达（`0047__gml_Object_obj_enemy_Step_0.gml:23,28`、`obj_knifebandit` / `obj_shooter1` / `obj_skeleton` / `obj_shooter2` / `obj_hulkingbandit` 同构）。
- **核心侧早已按原点建模**：`crates/core/src/lib.rs:111-116` 与 `ir_scene.rs` 的 `collision_point` / `instance_place` 都是 `x - origin_x * image_xscale` 展开碰撞盒，所以渲染必须与命中盒用同一套锚点，否则画面与判定会错位。
- **客户端**：`Framebuffer::blit_sprite_gm` 以 `dst_origin = instance - camera` 为原点落点，`scale` 允许为负；镜像按连续空间关于原点翻转（`obj` 帧落在 `[AT±...]`，见测试断言"镜像盒是原盒关于原点的精确反射"）。

## 机制 2：`image_angle` 绕原点旋转

- **原版使用面**：弹体/投掷物几乎全部靠默认绘制（无 Draw 事件）输出 `image_angle`——`obj_bullet`（CODE 282 Create 设 `image_angle = direction`）、`obj_blade`、`obj_rocket`、`obj_flame`、`obj_laserbeam`、`obj_boomerangthrow`、`obj_energywave`、`obj_enemybullet`、`obj_finalbosslaser`、`obj_finalbossgrenade`、`obj_sword`（`image_angle ±= 25` 挥砍）等。
- **客户端**：GMS 角度为屏幕逆时针（y 向下），绕精灵原点旋转，最近邻采样。`lx = -ry, ly = rx` 的 90° 映射在测试里被逐边钉死（帧的左右边落在屏幕上下边）。

## 机制 3：`image_blend` 乘性着色与 `d3d_set_fog` 受击闪烁

- **受击闪烁（21 个 Draw CODE）**：`obj_player_Draw_0` 用 `d3d_set_fog(true, c_red, 0, 0)` 包住 `draw_self()`，20 族敌人/Boss 用 `c_white`，随后立刻 `d3d_set_fog(false, c_black, 0, 0)`（`0018/0048/0057/0068/0090/0099/0111/0134/0162/0186/0079/0122/0144/0153/0170/0198/0267/0231/0243/0214` 等）。fog 的 `start == end == 0` 表示整块被雾色完全覆盖，因此语义是**保留 alpha 剪影、颜色整体置为雾色**，与 `image_blend` 的乘法着色是两种不同运算——核心侧过去只留一个 `color`，客户端无法区分，本批给 `DrawCommand` 增加 `fog: bool`（`ir_scene.rs` 的 `draw()` 记录 `fog_enabled`）。
- **状态色（乘法）**：冻结 `image_blend = c_blue`（16711680）、中毒 `c_green`（65280）、地图"你在这里"高亮 `image_blend = 255`（`map_system_ir` 已钉死）；解冻 `image_blend -= c_white`。
- **越界色值的解码**：`image_blend -= c_white` 从 16711680 得到 **−65535**（`enemies2_batch_ir` 已实测），4 参 `draw_sprite` 的默认 blend 是 `-1`。两者都按 GM 的低 24 位（0xAABBGGRR，红在最低字节）解码：−65535 → (1,0,255)（仍是蓝色，和冻结前肉眼几乎一致），−1 → c_white（无着色）。这条与引擎内其它颜色解码（文字、粒子）保持同一约定。
- **可达性**：`hpfrozen == 0 → image_blend = c_white` 出现在各 `Step_0` 中，而 Alarm 在 Step 之前执行，所以解冻当帧的负值对多数族在下一次 Draw 前已被复位；`obj_bat` / `obj_enemy` / `obj_skeleton` 三族没有复位语句，负值会留在实例上——按上面的解码它们仍呈蓝色。

## 机制 4：`draw_healthbar` 三色与边框

- **原版 90 处调用点**全部是 `(direction=0, showback=1, showborder=1)`：经验/武器经验条用 `c_gray, c_green, c_yellow`（`obj_UI` CODE 370、`obj_weaponswap` CODE 520），Boss 血条用 `c_black, c_red, c_green`。
- **客户端**：整条先铺 `back_col`，再按 `amount/100` 从 `min_col` 线性插值到 `max_col` 填充，最后画 1px 黑边框；坐标仍是房间坐标（原版传 `view_xview[view_current] + 46` 等），由客户端减去相机。

## 边界与未验收

- `draw_background_ext` 的 colour 参数在全部调用点恒为 `-1`（= c_white，无着色），因此 `BackgroundCommand.color` 仍未被消费：这是登记边界，不是遗漏；若将来出现非 -1 的调用点必须补上。
- `draw_healthbar` 的 `direction / showback / showborder` 三个参数仍不进命令（全语料恒为 0/1/1，批次 2 已登记）。`rm_boss5` 的 Boss 条是唯一 `x2 < x1`（`obj_boss5.x - 20`）的倒挂矩形，客户端与其余 89 处一样先归一化再从左填充；GM 对倒挂矩形的填充锚点尚无证据钉死。
- 雾只有全强度形态（21 处全部 `start == end == 0`）；若出现非零 start，需要把雾因子一并入命令。
- 帧矩形按 SPRT 画布拉伸后以原点锚定（与核心命中盒模型一致），未建模"帧比画布小"的画布内偏移。
- 文字仍走 5x7 兜底字模，不是原版字体表。
- **真机/GPU 视觉层仍未验收（NOT RUN）**：本轮全部证据来自 IR 宿主 + 软件光栅 A/B 像素断言，没有设备截图或 GPU 读回。

## 测试套件

`crates/client/tests/draw_field_consumption.rs`（4 项测试，全部在真实 `assets/game.droid` 上跑 `draw_frame`）：
1. `sprite_origin_anchors_and_negative_scale_mirrors_on_the_axis`：SPRT origin 锚点、镜像盒关于原点的精确反射、镜像不改变覆盖像素数。
2. `image_angle_rotates_the_frame_about_the_sprite_origin`：90° 旋转的包围盒交换与逆时针方向（帧左边落到屏幕下边）。
3. `image_blend_multiplies_and_fog_floods_the_frame`：c_white / `-1` 为恒等，c_blue 只留蓝通道，−65535 解码为 (1,0,255)，fog 用 c_red / c_white 整体覆盖。
4. `healthbar_uses_the_original_back_min_and_max_colours`：满值 = `max_col`、半值 = `min_col→max_col` 插值中值、未填充区 = `back_col`、边框为黑。

夹具纪律：期望几何全部来自**独立读取 atlas**（帧的不透明包围盒、首个不透明像素），不是被测代码的复述；夹具自带前置断言（origin 非零、x 不对称、无与清屏色相同的像素、摆放不越界），不满足就 panic 而不是静默跳过。

RED 证据：把 `crates/client/src/lib.rs` 单独回退到上一版光栅器后，上述 4 项测试全部失败（`0 passed; 4 failed`），其中健康条实测得到 `(30,240,40)`——旧的自造红→绿渐变；恢复本批后 4/4 通过。

同时修掉一条**假信号**：`crates/client/tests/ir_scene_gameplay.rs` 原先用"非零字节数 ≥ 房间渲染非零字节数"来验证健康条，这个度量只靠旧渐变的非零灰字节成立；原版 `c_black` 背景合法地是零值字节，改为与"同一帧但不含血条"的 A/B 像素差（`changed >= 1000`）来隔离血条贡献。
