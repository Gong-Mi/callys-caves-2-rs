# live oracle 契约（原版运行态可读性 + 边界）

本文件定义"从原版 Cally's Caves 2 活体进程能读到什么、怎么读、什么读不到"，
以及音频时间线任务的正确拼法。证据见 `../live-mem/live-findings-v2.md`（第 1–15 节），
工具见 `../live-mem/tools/`，壳见 `../live-mem/shell32/`。

## 1. 绑定与寻址

| 项 | 值 |
|---|---|
| 原版 APK | sha256 `d608f455…`（package `com.vdogames.callyscaves2`，2.1.9） |
| libyoyo | sha256 `3bbedd09…`（armeabi-v7a，4,689,844 B） |
| rw 段寻址 | `live = rw_base + (va - 0x3F2000)`，**data 与 bss 同式**（0x3F1000 变体是错的） |
| 数据区 | 大量二级指针：`[slot]` = 堆指针，需再 deref 一层 |
| 读内存 | root 直读 `/proc/<pid>/mem`（pread 用地址，不落盘） |

## 2. 可读对象（已实证）

- **房间/实例**：Run_Room(0x54298C)；绘制链表 +0x80/+0x84，CInstance +0x78 id、
  +0x80 CObjectGM*（+0x14 名字）、+0x180 depth、+0x17C next、+0x65/68/69 标志、
  +0xb4/+0xb8 x/y；`room_census.py` 全量走读。
- **视图/相机**：room+0x48+4i，view{+0 visible, +4 xview, +8 yview, +c wview,
  +10 hview, +14.. xport/…}。
- **ID 映射**：0x536F28 {table,511,count}，项=id&511，8B 双词同值；
  `verify_id2inst.py` 6/6。
- **全局变量**：scope=*(0x544BE0)，map=[scope+0x60]，mask=[map+8]，data=[map+16]，
  **hash(i)=i+1**，条目 12B {?,RValue*@+4,hash@+8}，RValue 16B（类型字 +12 高 8 位）。
  名字表 0x47A19C（691/417 有名）。
- **实例变量**：CInstance 即 YYObjectBase（同上布局，scope=instance）；名字表
  0x47A18C（691/274 有名）。
- **输入态**：g_MouseX/Y(0x5346B8/0x5346B4)、g_DoMouseButton(0x535700)、
  g_MousePosX/Y(0x53468C/0x534664)。
- **音频意图**：F_AudioPlaySound→Audio_PlaySound(0x21b5D8) 汇合点；源结构
  +20 播放序/+24 声音索引；管理器 S(0x7553AC)。

## 3. 读不到 / 不可靠

- **音频播放态**：壳内 OpenAL 设备打开失败（hbt 下 OpenSL dlsym IID 全挂）→
  音频子系统被禁用 → 管理器空、F_ 层 gate 字节非 0（调用被短路）。
  修法（下轮，hbt 安全）: 清 gate 字节 + libopenal 导出叶函数 noop 补丁。
- **逐事件时间序**：单全局变量采样无法重建事件序列（帧内工作微秒级完成，
  采样必然落在帧末）。**不要用内存轮询做事件流**；改用 Rust IR 仿真出事件序列
  + live 状态交叉校验。
- **hbt 代码补丁限制**：.text 无动态重定位（绝对 literal 不重定位）、
  add-pc/寄存器间接跳转 SIGILL、lr 是 thunk 编号非真 VA。可用子集：纯直链 bl +
  不依赖 pc/lr 的指令（libopenal 叶函数 `mov r0,#0; bx lr` 即在此子集内）。

## 4. 音频时间线的正确拼法

1. 事件序列：`crates` 的 IR 仿真（obj/event/tick），逐 tick。
2. 状态交叉校验：本契约 §2 的 live 读取（全局/实例/房间）对仿真状态抽查比对。
3. 播放判定：`tools/guard_eval2.py` 的守卫求值器（static 表 450 条调用 × live 值）
   → 每次事件的"实际播放集合"。
4. 静态表：`tools/audio_static_table.py` → `live-mem/audio-call-table.json`
   （169 事件/450 调用，带音效实参 + 分支守卫）。

## 5. 声音时长表（audio-durations.json，54/54）

生成器 `../live-mem/tools/sond_durations.py`，两个来源：
- music（sond kind 5199697，`*.ogg`）→ APK `assets/mus_<ext>`：OGG 末页 granule /
  Vorbis 识别头采样率。25 首，25–296 s。
- sfx（sond kind 5198594，内嵌）→ `assets/game.droid` 的 AUDO 分块：RIFF/WAVE 的
  fmt byte-rate 与 data 长度。29 条，0.19–200 s。

用途：`Scene::set_sound_duration` + `set_room_speed` 让非循环声部在真实时长内保持
`audio_is_playing`，原版的门（obj_music 序列器、SFX 重播抑制）才成立。
注意 sond 0 (`bee`) 数据本身就是 200 s / 17.6 MB 单声道 16-bit 44.1 kHz；
`ticks_at_30hz` 列按 30 Hz 换算，供 IR 侧直接使用。
