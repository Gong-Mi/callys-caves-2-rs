# 渲染 Draw 层批次 3：全实体受击闪烁与怪物出场横幅

包含全实体受击着色矩阵（玩家 CODE 18 + 20 族敌人/Boss 绘制事件 CODE 48..267）与怪物出场横幅系统（obj_triggerintro CODE 781 + 20 族横幅 CODE 721..780 + 双翼飞线 CODE 717..720）。全部经出货字节码在 IR 宿主上实测后固化，并与恢复 GML 交叉核对。

## 机制 1：全实体受击闪烁与 d3d_set_fog 管道（21 个 Draw CODE）

在原版 GameMaker 1.4 中，当实体（玩家或 20 族敌人/Boss）受到伤害时，逻辑层置位 `flashing = 1`。在其实例 Draw 0 事件中，出货字节码统一执行严格同构的三段管道：
```gml
if (flashing == 1) {
    d3d_set_fog(true, color, 0, 0);
    draw_self();
    d3d_set_fog(false, 0, 0, 0);
} else {
    draw_self();
}
if (flashing == 1) {
    flashing = 0;
}
```

### 实体着色与字节码常量

| 实体族群 | 对象 ID | Draw CODE | 雾效颜色 (color) | BGR 视觉语义 | 附加指令 |
| --- | --- | --- | --- | --- | --- |
| 玩家 (obj_player) | 0 | 18 | `255` | 纯红 (`c_red`, `0x0000FF`) | 开头无条件 `mask_index = 29` (spr_playerstand) |
| 普通敌人 (14 族) | 14..24, 31..33 | 48, 57, 68, 79, 90, 99, 111, 122, 134, 144, 153, 243, 255, 267 | `16777215` | 纯白 (`c_white`, `0x00FFFFFF`) | 纯同构 39 指令体 |
| Boss (6 族) | 25..30 | 162, 170, 186, 198, 214, 231 | `16777215` | 纯白 (`c_white`, `0x00FFFFFF`) | 纯同构 39 指令体 |

### 引擎宿主还原（crates/core/src/ir_scene.rs）
- **移出无操作桩**: 原实现中 `d3d_set_fog` 曾被归入平台 SDK 空桩列表返回静态 0；现接入真实 4 参数分发（`enable = a[0] >= 0.5`，`color = int(a[1])`）。
- **着色写入 DrawCommand**: `Scene::draw` 在 `self.fog_enabled == true` 时，将当前 `fog_color` 覆盖写入 `DrawCommand.color`（受击红/白闪烁直达命令流）。
- **帧边界重置**: `draw_view` 每帧开始重置 `fog_enabled = false`，防止上一帧异常残留；每个 CODE 体在 `draw_self` 后立即调用 `d3d_set_fog(false, 0, 0, 0)` 关闭雾效，并在末尾将 `flashing` 消费归零。

---

## 机制 2：怪物与 Boss 出场横幅系统（20 个 Intro 对象，20 Draw CODE）

当玩家在主线推进中初次接近某种敌人时，关卡放置的 `obj_triggerintro` (186, CODE 781 Step_0) 负责触发剧情横幅：

1. **触发门控（CODE 781）**:
   - `distance_to_object(obj_player) <= 32`；
   - 匹配当前房间 `room == R` 且对应首杀/初遇标记 `global.<enemy>touched == 0`（全语料 20 组分发：level1 的 bearcub/knifebandit、boss1 的 Mama Bear 直至 boss6 的 Herbert）；
   - 触发时调用 `instance_create(x, y, obj_<enemy>intro)`，并将 `global.<enemy>touched` 立即置为 1（防重复触发）。
2. **横幅生命周期（`obj_<enemy>intro`，CODE 721..780）**:
   - **Create**: 当 `soundmute == 0` 时调用 `audio_play_sound(4, 0, 0)` 播放号角音效（`snd_fanfare`，SOND 4）；装填自毁计时器 `alarm[0] = 60`；以相对坐标生成双翼装饰飞线：`instance_create(x + 320, y - 30, obj_lineleft)` (164) 与 `instance_create(x - 320, y - 5, obj_lineright)` (165)。
   - **Draw 0**: `draw_set_color(16777215)` (白) + `draw_set_font(0)` + `draw_text(fixed_x, fixed_y, name)`，文本直引 bundle 字符串表索引 1214..1233（1214="Bear Cub"、1220="Mama Bear"、1233="Herbert" 等全部 20 族全量对应）。
   - **Alarm 0**: 60 tick 后调用 `instance_destroy()` 销毁横幅。
3. **双翼飞线（`obj_lineleft` / `obj_lineright`，CODE 717..720）**:
   - **Create**: 分别装填 `hspeed = -12`（向左）与 `hspeed = +12`（向右），装填 `alarm[0] = 89`。
   - **飞行与消亡**: 在 89 帧的生命周期内以 12px/tick 双向外扩散飞出屏幕；89 tick 时 Alarm 0 触发 `instance_destroy()` 自动清场。

---

## 夹具陷阱与实测固化

1. **Boss 血条除零陷阱**: `rm_boss3` 等房间自带 `obj_UI` (CODE 370)，其实例 Draw 会遍历检测场上活跃的 Boss 并读取 `boss1maxhp`/`boss3maxhp` 等属性做百分比除法；若全局缺少难度种子 `global.pwr`，Boss Create 无法写入 `maxhp`，UI 绘制即刻抛出 division by zero。夹具中必须保持 `global.pwr = 1`。
2. **实例归因与实例查找**: 场景自带实体（如房内置墙体与敌人）与测试创建的实例共存，过滤命令时必须按 `DrawCommand.instance == id` 精准归因，不能仅按 CODE 计数。
3. **Touched 全局首查**: `global.<enemy>touched` 在未触发前读取返回 0（`unwrap_or(0.0)`），触发后成为明确的 1.0。

---

## 测试套件

1. `crates/core/tests/entity_flashing_ir.rs`（4 项通过）:
   - `player_damage_flash_emits_red_fog_and_resets_flashing`: 玩家受击闪红（`color=255`）、`mask_index=29` 保持、Draw 后 `flashing=0` 自动归零、下一帧恢复无雾效绘制。
   - `enemies_damage_flash_emits_white_fog_and_resets_flashing`: 普通敌人（mooks 抽样）受击闪白（`color=16777215`）、`flashing` 消费归零。
   - `bosses_damage_flash_emits_white_fog_and_resets_flashing`: Boss 族（Trex、Boss3、FinalBoss）受击闪白与自复位。
   - `non_flashing_entities_emit_normal_blend_without_fog`: 无伤状态下不产生雾效着色（`color != 255`）。
2. `crates/core/tests/enemy_intro_banners_ir.rs`（4 项通过）:
   - `triggerintro_trips_banner_and_sets_touched_latch`: 玩家接近 (<=32px) 触发横幅、`beartouched` 锁存防重发。
   - `intro_banner_draw_renders_enemy_name_from_string_table`: Bear Cub、Mama Bear、Herbert 等 20 族字符串表真名称及固定布局坐标渲染。
   - `banner_plays_fanfare_and_respects_soundmute`: 开局 fanfare 播放及 `soundmute` 静音门控。
   - `flanking_lines_spawn_fly_outward_and_destroy_on_alarm`: 双翼飞线偏移生成、±12px 航行速率、60 帧横幅消亡与 89 帧飞线完全消散。

---

## 边界与未验层

- 本批覆盖了全部 21 个实体闪烁 Draw CODE 与全部 20 个 Intro 横幅 Draw CODE，合计 41 个 Draw CODE 闭环；
- 商店/升级物品（obj_powerupgrade*、obj_store 等 20 个 CODE）与暂停/菜单层（16 个 CODE）留待后续批次；
- 真机/GPU 视觉层未验收（NOT RUN）。
