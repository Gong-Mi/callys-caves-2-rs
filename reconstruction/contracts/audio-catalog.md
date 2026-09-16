# 原版音频内容契约（audio catalog）

来源：`assets/game.droid`（SHA-256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`）
生成：`scripts/audit_audo.py`（AUDO 解析）、`scripts/audit_audio_usage.py`（1,354 份 GML 全量扫描）。
机器可读数据：`audio-sond.json`（54 条目全字段）、`audio-audo.json`（29 条目 WAV 头事实）、`audio-usage.json`（调用统计）。

## 1. 资源层架构

GMS 1.4 bytecode16 打包，两个 chunk 分工：

| chunk | 条目 | 内容 |
|---|---|---|
| SOND | 54 | 36 字节/条：`name_ptr / flags / kind / ext_ptr / effects / volume(f32) / audo_id` |
| AUDO | 29 | 内嵌完整 RIFF/WAV（含 12 字节 RIFF 头），指针表寻址 |

**音效与音乐分流**：29 个 `snd_*` SOND 条目全部指向 AUDO 内嵌数据（29/29 一一对应）；25 个 `mus_*` 条目 `audo_id` 全为占位——音乐是 APK assets 里的独立 OGG 文件，不进 game.droid。这是 GMS Android 打包的标准策略：短音效内嵌 runner 即时解码，长音乐走外部文件流式播放。

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
