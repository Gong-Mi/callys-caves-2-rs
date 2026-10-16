# 原版音频内容契约（audio catalog）

来源：`assets/game.droid`（SHA-256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`）
生成：`scripts/audit_audo.py`（AUDO 解析）、`scripts/audit_audio_usage.py`（1,354 份 GML 全量扫描）。
机器可读数据：`audio-sond.json`（54 条目全字段）、`audio-audo.json`（29 条目 WAV 头事实）、`audio-usage.json`（调用统计）。

## 1. 资源层架构

GMS 1.4 bytecode16 打包，两个 chunk 分工：

| chunk | 条目 | 内容 |
|---|---|---|
| SOND | 54 | 36 字节/条（9 词，`UndertaleSound` 顺序）：`name_ptr / flags / type_ptr / file_ptr / effects / volume(f32) / pitch(f32) / audio_group / audo_id`。`flags`：0x65 = Regular\|IsEmbedded（29 个 `snd_*`）、0x64 = Regular（25 个 `mus_*`）；`type` = ".wav"/".mp3"，`file` = "snd_*.wav"/"mus_*.ogg"；`effects`/`pitch`/`audio_group` 全 0（AGRP 为空）。守卫：`sprite_and_tile_layout_ir::the_sound_records_carry_the_streamed_embedded_split` |
| AUDO | 29 | 内嵌完整 RIFF/WAV（含 12 字节 RIFF 头），指针表寻址 |

**音效与音乐分流**：29 个 `snd_*` SOND 条目全部指向 AUDO 内嵌数据（29/29 一一对应，`audo_id` 0..28 按序）；25 个 `mus_*` 条目 `audo_id` 全为占位 **28**——音乐是 APK assets 里的独立 OGG 文件，不进 game.droid。这是 GMS Android 打包的标准策略：短音效内嵌 runner 即时解码，长音乐走外部文件流式播放。

## 2. 格式规格（制作管线证据）

29 个 AUDO WAV **全部单一规格**：PCM fmt=1、单声道、44100Hz、16bit（`audio-audo.json` 中 distinct specs 只有一项）。无任何压缩、重采样或多声道残留——DAW 统一导出流水线的直接证据。时长呈量化分布（coin 恰 0.500s、sound_0 恰 200.000s），剪辑按时间量化而非采样点任意截断。

## 3. 资源级预混（SOND volume 元数据）

大多数 vol=1.0，作者手动压过的条目（`audio-sond.json`）：

| 声音 | volume | 意图 |
|---|---|---|
| laser | 0.28 | 高频刺耳，压到约 1/3 |
| blade | 0.30 | 同上 |
| rocket | 0.70 | 中频过载保护 |
| shotgun | 0.93 | 轻微 |
| townmusic | 0.50 | BGM 让位音效 |

预混发生在资源元数据层，不是运行时。

## 4. 运行时消费拓扑（1,354 CODE 全量）

- **播放**：397 处 `audio_play_sound`。集中度极高：`snd_impactsound2` 180 处（45%，全局通用命中音），`impactsound5` 42、`explode2` 26、`explode` 22、`meetnewenemy` 20、`coin` 18。
- **循环**：仅 4 个调用点传 `true`——`mus_townmusic`(14)、`mus_bosssong`(6)、`mus_techno`(6)、`music`(1)。所有 BGM 循环由字节码第三参数驱动，SOND 元数据不带循环标志。
- **防叠 gate**：86 处 `audio_is_playing`。`impactsound2` 34 处（武器连发防叠）；`obj_music` 对全部 25 首 mus_* 各 2 处构成 9 层嵌套"任何 BGM 在放就不放新"链；`weaponswap`/`assaultrifle` 各防重播。
- **停止**：15 处 `audio_stop_sound`，`mus_townmusic` 独占 14 处（换房间切 BGM）；`assaultrifle` 1 处（射击按钮松手停连发）。
- **静音**：106 处 `audio_sound_gain(x, 0, 0)` 覆盖 53 个不同音效名——`obj_muting` 逐音效硬压，无全局 mute 通道抽象。

## 5. 与本项目 Rust 实现的对接边界

- `AudioCommand.sound` 携带原版字节码的 SOND 序号；29 个 `snd_*` 可由 AUDO 直接取字节。25 个 `mus_*` 不在 AUDO 内，客户端需从 APK assets/OGG 提取（dump_assets.py 只导 AUDO）。
- SOND `volume` 元数据当前未被 `AudioCommand`/SoundPool 消费——原版 runner 播放时应用资源音量，本项未实现，列为 J 分线 Android 验收缺口。
- `audio_sound_gain` 的静音语义已在 VM 层接入 AudioVoice 账本（`665ec0a`），但 gain 数值未下传声音通道，同为设备层缺口。
- AudioFlinger 真机证据（PR #17，旧 legacy 路径）：44100Hz AudioTrack 由 SoundPool 驱动；IR 路径的听感验收待 Android 设备分线。

## 6. 防叠 gate 的引擎侧根因与修复（WL8，2026-10-16）

**现象**（javm64 验收矩阵 WL4 实测）：gameplay 相位第 131 帧起每帧 drain 恰好 1 条
mus_* 播放命令（id 29..52 轮转）；宿主 `handleMusicCommand` 对每条 id≥29 事件
stopBgm + new MediaPlayer + prepare + start ⇒ BGM 每帧重启。

**根因**：音频资产不携带时长（SOND 记录只有 name/flags/type/file/volume），
`audio_is_playing` 的判定依赖「声音设备知道流的真实长度」。引擎的 AudioVoice
账本支持「已知时长的非循环 voice 活到时长结束」，但时长表（
`reconstruction/contracts/audio-durations.json`，54/54 行：29 内嵌 WAV 实测 +
25 OGG granule/rate）此前只由宿主注入，注入路径没进 gameplay ⇒
`Scene::sound_durations` 恒空 ⇒ 每帧 drain 把 voice 同帧退役 ⇒ 86 处防叠 gate
全部恒假 ⇒ obj_music 24 层链每帧放行一首新曲。

**修复语义**：`Scene::sound_durations` 默认值改为仓内生成的
`crates/core/src/sond_durations.rs`（源=audio-durations.json，regen 命令在文件头；
一致性由 `crates/core/tests/sond_durations_guard.rs` 钉住）。已知时长的非循环
voice 活到真实时长，`audio_is_playing` gate 按原版语义工作；未知时长仍走
legacy drain 退役（未登记的声不会永久关门）。`set_sound_duration` 保留单条覆盖。

**验证**：`crates/client/tests/gameplay_music_gate.rs` 3 项——gameplay 不重发 BGM
（序章 track 的唯一条初始发行除外，且 gate 因它在放而保持）；track 真实时长
结束后链重开、恰好发一首新 theme 且随后保持静默；换房（rm_boss1）音乐变更
恰好一条循环命令到达宿主。

**宿主侧待办（仅提案，本线未施工）**：`handleMusicCommand` 加「同曲已在放」守卫
（id+looping 相同且 MediaPlayer 未 release 时跳过 stopBgm/new），作为引擎账本
之外的第二道防叠；需要真机听感验收才能定稿。
