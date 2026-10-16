# 宿主生命周期无头验收矩阵（javm64 相位×腿，WL4 / 2026-10-16）

面向 Issue #34 I 线「宿主生命周期缺设备验收」的 **native 层无头验收矩阵**：把真机
Android 生命周期事件映射成引擎相位序列，用 javm64 壳（`su` + `app_process64`，真
GPU、无前台窗口）逐相位驱动 Java 宿主实际执行的私有 native 调用，逐腿输出可复核
数字。

- harness：`~/cally-work/gmbench/src/com/gongmi/callyscaves2/GmLifecycleMatrix64.java`
- 运行：`run_lifecycle_matrix.sh <java|rust> <cycle|order|egldead> [cycles] [settleFrames] [keep]`、
  全矩阵 `run_lifecycle_matrix_all.sh [cycles] [settleFrames]`
- 构建：`build_lifecycle_dex.sh`（只编这一个类 → 独立 `lifecycle.dex`，**不改**
  其他工作线共用的 `gmbench.dex`）
- 证据：`~/cally-work/gmbench/work/logs/lifecycle-matrix-*.log`（stdout+stderr 逐相位），
  汇总 `work/logs/matrix-all.txt`
- 本次二进制 provenance：`lifecycle.dex` sha256 `5433705ede2d0a6e61ed85de5952c0779f9353e513a0827ee04deb57f9385e82`，
  `work/libs/libcallys_client.so` sha256 `829312fdb0c2324d7e7f1d5d39ac5fd08709f094c2cbbc7a10b49293f048397f`（含 #97 `b0a8b80`）
- 运行环境：宿主 loadavg 19–25（同机另有 wl1/wl2/wl3 并行工作线在跑 cargo/构建）；
  本矩阵全部断言为**语义/逐字节**判定，不依赖墙钟时间——负载只影响耗时，不影响结论。

## 0. 结论摘要

- **native 层相位矩阵全绿**（java 与 rust 两个 presenter 逐腿一致）：surface 销毁/重建
  后 present 恢复、post-restore 帧逐字节相等、3 轮前后台往返状态零漂移、onResume 先于
  surfaceCreated 的另一种真实顺序同样只跑一次 nativeInit。
- **EGL display 死亡 + surface 重建叠加腿**复现 #97 登记值（8/10，first_ok=3），且恢复
  后画面逐字节等于死亡前参照帧，surface 重建后仍逐字节相等。
- **nativeInit 重跑语义 = 内存重置（非幂等）+ 无泄漏 + 经 autosave 收敛**：往返后帧
  fingerprint 与「带档冷启动」完全相等，3 轮与两种 presenter 均一致。
- 登记 3 项待办/缺陷候选（均不改码，交父代理）：① gameplay 每帧发出 1 条 `mus_*` 播放
  命令（与原版 `audio_is_playing` 防叠 gate 契约冲突）；② 每次前后台往返都重放序章；
  ③ 后台不暂停音频（真机侧，壳内无法验）。

## 1. 相位序列设计（对照 MainActivity，只读）

`android-build/src/com/gongmi/callyscaves2/MainActivity.java`：

| # | 真机 Android 事件 | MainActivity 行 | native 调用序列 | 壳内腿 |
|---|---|---|---|---|
| P1 | 首次 `Surface` 创建 / 回前台重建 surface | `surfaceCreated` 190-193 | `nativeSetSurface(new)` → `startEngine()`〔`nativeInit()`; `nativeSetClockPaused(false)`〕 | A0、C*-created、O*-created、X5b |
| P2 | surface 尺寸变化（旋转/多窗口 resize，不重建 surface） | `surfaceChanged` 195-203 | `gameRect.set(...)` + `nativeSetSurface(new)`（**不**跑 nativeInit） | A0、A1..A3 重建、X5a |
| P3 | 按 Home / 切走后台 | `onPause` 570-573 | `stopEngine()` 556-567 = `running=false` + `nativeSetClockPaused(true)` + `renderThread.join(500)`（join 为 Java 侧） | C*-background、O*-background |
| P4 | 后台驻留后 surface 销毁 | `surfaceDestroyed` 205-208 | `nativeSetSurface(null)` → `stopEngine()`（同 P3） | A*-destroyed、C*-background、X4 |
| P5 | 回前台（surface 顺序在后，见 §1.2） | `onResume` 576-581 | 仅当 `renderThread==null || !isAlive()` 才 `startEngine()` | C*-onResume（no-op）、O*-resume-before-surface（真跑） |
| P6 | 退出/销毁 | `onDestroy` 584-591 | `stopEngine()` + `nativeSetSurface(null)` + `releaseSoundPool()`（SoundPool/MediaPlayer 为 Java 侧） | 壳内 `detach()` |

`startEngine()` 284-305 的 `if (running) return;` 守卫是全矩阵的关键：一次前后台
往返**只能**跑一次 nativeInit，否则就是双初始化缺陷。

### 1.1 相位序列（壳内实测的调用序）

```
surfaceDestroyed : nativeSetSurface(null) → nativeSetClockPaused(true)   [running=false]
surfaceCreated   : nativeSetSurface(new)  → nativeInit() → nativeSetClockPaused(false)  [running=true]
onResume         : startEngine() → running==true → 直接返回（nativeInit 不再跑）
```

### 1.2 两种真实到达顺序（都测）

- **顺序甲**（`surfaceCreated` 先，常见：窗口先就绪）→ nativeInit 由 surfaceCreated 触发，
  随后 onResume 是 no-op。腿 `cycle` 覆盖：`resume_noop=3/3`、`init_per_cycle=3/3`。
- **顺序乙**（`onResume` 先，`startEngine` 在 **window 仍是 null** 时跑）→ nativeInit 由
  onResume 触发，随后 surfaceCreated 的 startEngine 被 `running` 挡掉，present 在
  surface 回来前必须为 false。腿 `order` 覆盖：`null_window_present_false=3/3`、
  `init_once_per_cycle=3/3`。
- 两条顺序的**终态 fingerprint 相同**（`41cdc0a05b06abf9`）→ 相位到达顺序不影响引擎终态。

### 1.3 壳内偏差（必须与真机区分）

- 壳内**先 boot 后附着 surface**（真机是 `surfaceCreated` 才 `startEngine`）：不影响相位
  对的语义，但真机「引擎首次启动时窗口已就绪」这一组合仍待真机验。
- `renderThread` 用 `running` 布尔建模（`RenderLoop` 307-356 内联进 harness 循环）；
  `renderThread.join(500)`、`pointerReleases.reset()`、`prepareGameDroid()/SoundPool`
  属 Java 侧，不在 native 判定范围。
- 面用 `ImageReader`（真 BufferQueue）代替 `SurfaceHolder`：**无 scanout/vsync**，也不含
  `SurfaceHolder` 回调线程时序。
- Rust 状态行（`IR checkpoint … room=… intro=… active=…`）来自 `callys-rust` tag，
  经 liblog（本环境落到 stderr）与 stdout 交织，构成逐相位时间线。

## 2. 验收矩阵（相位 × 腿 × presenter × 结果）

命令：`run_lifecycle_matrix_all.sh 3 220`；`settleFrames=220`（prologue 自退场在
tick≈128，220 帧保证进入 gameplay；序章 taplock 会吞掉过早的点按，见 §2.3）。

| 腿 | 断言（子项） | java | rust |
|---|---|---|---|
| **a** surface 相位单变量（无 nativeInit） | 分离期 present=false | 3/3 | 3/3 |
| | 重attach 后 present=true（armed） | 3/3 | 3/3 |
| | post-restore 帧 vs 参照帧 **byte-equal**（18176 采样像素） | 3/3 | 3/3 |
| | 引擎 framebuffer fingerprint 不漂移 | 3/3 | 3/3 |
| | 音频事件队列跨 surface 相位存活（5→5） | true | true |
| | 本腿 nativeInit 调用数 | 1（仅 boot） | 1 |
| **c** 3 轮完整前后台往返 | 每轮恰好 1 次 nativeInit | 3/3 | 3/3 |
| | onResume 不二次 init（`running` 守卫） | 3/3 | 3/3 |
| | 后台相位引擎冻结（5 次 paused step，fingerprint 不变） | 3/3 | 3/3 |
| | 后台相位引擎音频事件 = 0 | 3/3 | 3/3 |
| | 往返后 fingerprint 逐轮一致（C2==C1、C3==C1） | 2/2 | 2/2 |
| | 往返后 == 后台前画面 | 0/3（见 §3.3） | 0/3 |
| | RSS 增量（C1/C2/C3） | +31192 / −468 / +204 kB | +29256 / +1256 / +332 kB |
| **order** onResume 先 | 每轮 1 次 nativeInit | 3/3 | 3/3 |
| | window=null 时 present=false | 3/3 | 3/3 |
| | surface 回来自后 present=true | 3/3 | 3/3 |
| | fingerprint 逐轮一致 | 2/2 | 2/2 |
| **egldead** #97 注入 + surface 重建叠加 | 注入前 live present | 10/10 | 3/10（`false`=未变帧按设计跳过，非失败） |
| | `eglTerminate(display)` 返回 | true | true |
| | 死亡后恢复 present | **8/10，first_ok=3** | **8/10，first_ok=3** |
| | 恢复后帧 vs 死亡前参照帧 byte-equal | true | true |
| | 分离期 present=false | true | true |
| | display 死后 surface-only 重建 present=true 且 byte-equal | true / true | true / true |
| | 重建后 10 次 present（armed） | 10/10 | 10/10 |
| | 再叠真实 startEngine（nativeInit）→ present 可用 / 引擎确已重置 | true / true | true / true |

### 2.1 「armed / unarmed」测量纪律（javm64 坑，已内建）

Rust presenter 对**字节相同**的帧按设计跳过整个 present（`parts/gles.rs` present 343-355
的 `last_presented` memcmp；`present skip: no window` 346），因此裸 `nativePresent()` 的
`false` **无法区分「跳过」与「丢失」**。矩阵每个冻结帧测量前先
`nativeSetSurface(同一 surface)`（`parts/jni.rs` 459-481 → `force_next_present()` 293），
日志逐行标注 `(armed)`；活帧测量走真实渲染循环路径（unarmed）。java 侧 `GlesPresenter`
无 memcmp 跳过，恒 present。

### 2.2 关键原始输出（摘）

```
leg=a presenter=java detached_false=3/3 restored_true=3/3 byte_equal=3/3 engine_hash_stable=3/3 audio_survived_surface_phase=true(5/5) init_calls_total=1
leg=c presenter=java cycles=3 init_per_cycle=3/3 resume_noop=3/3 background_frozen=3/3 background_audio_events=0 in 3/3 post_resume_hash_stable=2/2 post_resume==pre_background=0/3 rss_end=358060kB init_calls_total=7
leg=order presenter=java init_once_per_cycle=3/3 null_window_present_false=3/3 created_present_true=3/3 hash_stable=2/2 init_calls_total=4
leg=egldead presenter=java attach=true pre_live=10/10 terminate=true display_recovery=8/10 first_ok=3 byte_equal_after_loss=true detached_present=false rebuilt_surface_only=true byte_equal_after_rebuild=true post_rebuild=10/10 resume_path=true engine_reset=true post_resume=10/10 init_calls_total=2
leg=egldead presenter=rust attach=true pre_live=3/10 terminate=true display_recovery=8/10 first_ok=3 byte_equal_after_loss=true detached_present=false rebuilt_surface_only=true byte_equal_after_rebuild=true post_rebuild=10/10 resume_path=true engine_reset=true post_resume=10/10 init_calls_total=2
[GlesRust] eglCreateWindowSurface: display dead (0x3001); resetting   <- rust 腿恢复路径实证
```

`#97` 的显示恢复链在 `0x3001` gate 上被真实触发：`parts/gles.rs` 471-479（
`EGL_NOT_INITIALIZED` → `reset_display()`）、`GlesPresenter.java` 119-129（
`createWindowSurface failed; dropping display` → `resetDisplay()` 277）。

### 2.3 序章 taplock（相位设计的一个实测约束）

序章 `obj_introduction` 只在 taplock 过期后接受点按退场：实测 220 帧、点按在第 5 帧时
序章**仍在播放**（`IR boot room=0 intro=true`，无 intro=false 迁移日志，无 autosave）；
点按落在第 130 帧（≈tick 128）才退场 → `intro=false, active=177`（无档）/`184`（带档）。
因此所有 settle 腿统一用 `tapAtFor(frames)=clamp(frames-40, 20, 130)`，否则测的是序章而
非 gameplay。逐相位 state 行（`parts/jni.rs` 83-92 `ir_phase`，195 / 269 两条日志）：
`active=5`（序章，仅 intro 存活）→ `177`/`184`（handover 后；带档 184 = 既有登记口径）。

## 3. nativeInit 重跑语义：重置 + 无泄漏 + 经 autosave 收敛

### 3.1 内存语义 = **重置**（非幂等）

`parts/jni.rs` 125-198：nativeInit 构造**全新** `GameState`（`GameState::new_persistent`）
并整体替换 slot 里的 `AndroidState`（新 `Framebuffer(1136,640)`、新 `FrameClock`，
`crates/client/src/lib.rs` 197-198 重建 `sound_queue`/`haptic_queue`）。后果（实测）：

- **未取音频事件随旧 GameState 一起丢**：`cycle` 腿每轮把 5 条事件留在队列里过相位边界
  → 恢复后立刻 drain = **0**；10 帧后只出现新会话自身的序章音乐 `[31]`（java/rust 一致，
  3/3 轮一致）。
- **引擎回到序章**：每轮 nativeInit 后 `IR boot room=0 intro=true`，handover 后
  `intro=false, active=184`（带档）。即每次前后台往返都会重放序章（§5 缺陷候选②）。
- `FrameClock::set_paused` 清 `last_ns`（`frame_clock.rs` 27-33）：resume 重新取基线，
  挂起时间不计费；暂停期间 `step_at` 直接返回 0 tick（同文件 38-41）——这是「后台引擎
  冻结」的源码依据，实测 5 次 paused step 后 fingerprint 不变。

### 3.2 无泄漏（重复 nativeInit 探针）

同进程连续 3 次 `nativeInit` + 各 5 帧（touch 新 framebuffer 页）后的 RSS 增量：

| presenter | L1 | L2 | L3 |
|---|---|---|---|
| java | −784 kB | −272 kB | −716 kB |
| rust | −1368 kB | −896 kB | −476 kB |

无「每次 ≈2.9 MB（1136×640×4）」的线性增长 ⇒ 被替换的 GameState 未泄漏；
`GameState`/`AndroidState` 无 `Drop` 实现（`grep "impl Drop"` 两 crate 均空），不会在替换时
额外写盘/留句柄。nativePresent 在换 slot 期间持 state 锁（`parts/jni.rs` 484-502 注释），
避免释放后指针悬空。

### 3.3 经 autosave 收敛：往返态 == 带档冷启动态（逐字节）

- 每成功 gameplay 帧都会 `autosave_ir()`（`lib.rs` 312-347，调用点 771；按快照去重）；
- boot 时 `queue_boot_ir_restore()`（349-360）读档 → 序章 handover 时应用
  `pending_ir_restore`（646-650）；
- 实测：`hash[C1-post-resume]`（往返腿）= `hash[s1-gameplay]`（带档冷启动，`keep` 跑）
  = `41cdc0a05b06abf9`，**java 与 rust 完全一致**，且 C2/C3 逐轮相同。
- **但画面不等于后台前那一帧**（`post_resume==pre_background=0/3`）：`autosave_ir` 里
  `Checkpoint { room_index: room, x: 0.0, y: 0.0 }`（`lib.rs` 322）**不持久化玩家坐标**，
  room/globals/score/collected 会被恢复、玩家位置回到房间起点 → 这是「重置+收敛」而非
  「续帧」。**判定（WL10）：忠实原版语义**——原版 `savefile.ini` 全量 320 个键无任何
  坐标/房号/门卡字段，且原版自身回房（Room Start/地图传送/「返回游戏」/死亡）一律把玩家
  重置到逐房常量 `global.startx/starty`；证据清单见 `ir-save.md` §Original semantics。
- 存档随每轮被重写（`save-v2.json` 1416B → 1416B → 1417B）。

## 4. 音频相位：可观测替代与边界

壳内**无音频输出设备**（无 AudioFlinger 会话、无听感）。可观测替代＝引擎音频事件队列
（`nativePollSound`，`parts/jni.rs` 342-362，把 SOND id/loop/stop 打包成 jint；宿主侧
`playQueuedSounds` 455-475 每帧消费）。**没有伪造听感结论**。

| 相位 | 实测 | 依据 |
|---|---|---|
| 序章 boot | 第 3 帧 1 条 `[31]`（mus_new4，`MUSIC_ID_BASE`=29，MainActivity 408） | 220 帧不 drain 仍保留 → 队列跨帧留存 |
| gameplay（每帧 drain，忠实于宿主） | **91 条/220 帧**：第 131 帧（handover）起**每帧恰好 1 条**，id 在 29..52（全 `mus_*`）间轮转；3 轮与两种 presenter 数字一致 | `audio-rate` 行 |
| 后台相位（paused） | 5 次 step → **0 条**，fingerprint 不变 | `step_at` 38-41 + `background 5 paused steps` 行 |
| 纯 surface 相位（无 nativeInit） | 5 条 held → 过 3 次销毁/重建后仍 **5 条**（存活） | `PHASE A audio` 行 |
| 前后台往返（重跑 nativeInit） | 5 条 held → 恢复后**立即 drain=0**，10 帧后仅新会话自身 `[31]` | `PHASE C*-audio TEST` 行 |

**边界（未验）**：① 无听感/采样率/延迟结论，`AudioFlinger` 层属真机；② Java 侧
`SoundPool`/`MediaPlayer` 的实际持有与后台播放行为在壳内**不存在**（无 Activity context）
→ §5 待办①；③ SOND `volume` 元数据未下传播放通道（`audio-catalog.md` §5 既有缺口）本
矩阵未触及。

**缺陷候选①（已验现象，根因待定位，不改码）**：gameplay 相位引擎**每帧**发出 1 条
`mus_*` 播放命令（轮转 16 个 id，实测 91/220 帧、逐帧 1 条）。Java 宿主对每条 id≥29 的事件
走 `handleMusicCommand`(501-533)：**先 `stopBgm()`(535-545) 再 `new MediaPlayer` +
`setDataSource` + `prepare()` + `start()`** ⇒ 若宿主按帧消费，BGM 会每帧被停掉重启。
与原版契约冲突：`audio-catalog.md` §4 记录原版有 86 处 `audio_is_playing` 防叠 gate，
`obj_music` 对 25 首 `mus_*` 各 2 处构成 9 层嵌套「任何 BGM 在放就不放新」链。两条待
定位路径：(i) IR/VM 侧 gate 或 AudioVoice 账本未参与判定 → 根在 IR 语义；(ii) 宿主
`handleMusicCommand` 缺少「同一 BGM 已在播放则跳过」守卫。**本任务禁改 crates/ 与
android-app 源，故只登记**。

## 5. 缺口清单与未验层（逐项边界）

**待办/缺陷候选（交父代理）**

1. **后台不暂停音频（真机侧，未验）**：`SoundPool`(358-394)/`MediaPlayer`(501-533) 属 Java
   宿主，壳内无 Activity context、无 AudioFlinger 会话，无法验「后台 BGM/音效是否继续
   播」。引擎侧已验为**后台不 tick、不发事件**（§4）；故「后台仍在响」只能来自 Java 侧
   已启动的流，须真机前台录音/`dumpsys media.audio_flinger` 验收。
2. **缺陷候选①** 每帧 `mus_*` 命令（§4）——现象已验、根因未定位。
3. **缺陷候选②** 每次前后台往返重放序章（§3.1）——native 层确证；真机侧需确认这是否
   与原版 runner 的后台语义一致（若不一致，属 UX 可见回退）。
4. **往返不续帧**：玩家坐标不入档（`lib.rs` 322）→ 回前台回房间起点。**已判定为忠实原版
   语义（WL10）**：原版存档无坐标字段、原版回房一律用逐房 `startx/starty` 常量；契约与
   file:line 证据见 `ir-save.md` §Original semantics，回归由
   `ir_save_roundtrip.rs::ir_autosave_persists_no_player_coordinates_and_restore_lands_at_room_start`
   锁定。不再列为待验缺口。

**未验层（本轮无法覆盖）**

- 真 `SurfaceHolder` 回调时序、`renderThread.join(500)` 竞争、旋转/多窗口 resize 时序；
- 进程被系统杀死后重建（真 `onDestroy`→新进程 `onCreate` 路径）、低内存 trim；
- `ImageReader` 是 BufferQueue，**无 vsync/scanout**，故「实际亮屏帧」需真机；
- `prepareGameDroid()`/`isPackageUpdated()`/`recordPackageUpdated()` 的版本戳与资源重解包
  在相位中的副作用（Java 侧，未验）；
- 触屏/输入在相位切换中的边沿语义（本矩阵只发 tap/jump 级输入）。

## 6. 复现

```sh
cd ~/cally-work/gmbench
sh build_lifecycle_dex.sh                 # 只编 lifecycle harness → lifecycle.dex
sh run_lifecycle_matrix_all.sh 3 220      # 全矩阵（java/rust × cycle/order/egldead + keep 参照）
# 单腿：
sh run_lifecycle_matrix.sh java cycle 3 220
sh run_lifecycle_matrix.sh rust egldead 1 220
sh run_lifecycle_matrix.sh java cycle 1 220 keep   # 保留存档 → 带档冷启动参照
```

`keep` 腿必须在写过档之后再跑（`cycle` 腿会写档）；`fresh`（默认）先删 `save-v2.json`
保证冷启动口径。每腿日志 `work/logs/lifecycle-matrix-<presenter>-<leg>[-keep].log`。

## 历史基线（#98 旧版记录，保留）

- P2（surface 销毁/重建，同一 GameState、无 nativeInit）：attach+present true、分离期
  `present skip: no window`、重建 present true 且与 pre-destroy 帧 byte-equal（18176 px）、
  末次 `setSurface(null)` 干净释放。
- P1（onPause/onResume 重跑 nativeInit）：`IR save queued for prologue handover`、
  带档 `active=184`（冷启动 177）、present 跨 session 存活、expected-color mismatches=0、
  无 SIGKILL/卡死。
- 本轮把 P1/P2 扩成相位×腿矩阵，并新增：order 顺序、3 轮循环、重复 nativeInit 泄漏探针、
  armed/unarmed 测量纪律、音频事件队列相位 A/B、EGL 死亡与 surface 重建叠加腿。
