# EGL 上下文丢失恢复（javm64 定向破坏实验，2026-10-12）

I 线设备侧欠账第一项（Issue #34 登记："EGL 上下文丢失恢复——需定向破坏实验"）。
本批用无头壳注入真实驱动丢失，证明缺陷、修复两侧 presenter、并钉回归。

## 实验装置

- 壳：javm64（`su` + `app_process64`，framework natives、真 GPU、无前台窗口），
  工具 `~/cally-work/gmbench/`；注入 harness `GmEglLost64.java`（同包直呼
  `GlesPresenter`，反射驱动 `nativeSetSurface`/`nativePresent`）。
- 注入 = 对 `EGL_DEFAULT_DISPLAY` 调 `eglTerminate`：驱动层让该 display 的一切
  handle（context/surface/config）失效，同时 presenter 仍持旧句柄——与真实
  driver reset / GPU 挂死后的可观测状态同型。ImageReader surface 保持有效，
  readback 可证明"恢复后真的画出了帧"。
- 每次跑前删 `work/files/save-v2.json`（autosave 会再生成，污染纯净 boot）。

## 丢失后该驱动的真实行为（修复前的实测）

- 基线 present=true、readback 采样 `1f 7a 73 ff`（rowStride 4544, RGBA）。
- terminate 后**旧 presenter 不释放就直接 `eglInitialize`**：进程被 SIGKILL
  （exit 137）——驱动拒绝在有存活 surface/context 引用已终止 display 时重开。
  这决定了复位顺序：makeCurrent(NO) → DestroyContext → Terminate → 清门。
- 只重试 surface（destroy+create）永不自愈：`eglCreateWindowSurface` 恒失败
  `EGL_NOT_INITIALIZED (0x3001)`，Java 腿与 Rust 腿修复前均 **0/10 presents、
  post-loss NO IMAGE**（永久黑屏）。

## 修复（两侧同构，语义：死 display 必须整链复位）

1. swap 失败 → 只丢 window surface（维持既有语义；resize/离屏走这条）。
2. 下一帧 createWindowSurface 拿到 `EGL_NOT_INITIALIZED` → `resetDisplay()` /
   `reset_display()`：surface→context→terminate 全链释放 + 所有 GL 门
   （program/texture/vbo/vao/locations/textureAllocated）清零 +
   `force_present=true`（旧 framebuffer 已死，未变化帧也必须重画）。
3. 下一帧的 `eglDisplay == NO_DISPLAY` / `display == EGL_NO_DISPLAY` 门自然
   重跑 initEgl/init_egl。
- Rust 侧错误码必须在 `create_window_surface` 内首次消费——`fail()` 会吃掉
  eglGetError，调用方二次读取恒为 0（首版踩中，RED 于 0/10 不恢复）。
- 恒等语义保持：非 0x3001 的失败仍走原 fail 路径，不动既有 skip/force 契约。

## 修复后实测（同装置、同注入）

- Java 腿：`recovery: 8/10, first_ok=3`（帧1 swap 失败→丢 surface；帧2 撞 0x3001
  →resetDisplay；帧3 initEgl 重建成功），post-loss 采样 `1f 7a 73 ff`、
  **byte-equal vs baseline: true**（18176 采样像素）。
- Rust 腿：同 8/10 first_ok=3，日志钉死链路
  `eglCreateWindowSurface: display dead (0x3001); resetting` → `GLES3 presenter up`
  → byte-equal true。
- 回归（`run_gmpresent.sh 300 300`，修复后的 .so/dex）：
  javaFull 300/300、javaSkip 0/300、rust present#2(未变)=false、
  同面 setSurface 后 forced=true、rustSkip 0/300、rustForcedPresent 300/300、
  rust-vs-java byte-equal=true、expected-color mismatches=0；
  timing(loadavg≈21): javaFull 1.88 / javaSkip 0.126 / rustPresent 1.295 /
  rustSkip 0.09 ms/帧（与 main=4a847be 基线同量级，load 污染下口径）。
- 本地全量（主树，`--profile ci-test -p callys-core -p callys-client --lib --tests`）：
  164 suites / 681 passed / 0 failed。

## 证据边界

- 注入丢失（terminate）≠ 驱动自发 reset；后者在 Android 上还会经
  `EGL_CONTEXT_LOST`（EGL 1.5）通知 + Activity 生命周期重建路径，本壳实验不覆盖
  通知路径，只覆盖"句柄全死、重试必须整链复位"这一最坏语义。
- ImageReader 是 BufferQueue：含真实上传/绘制/queueBuffer，不含 scanout/vsync。
- 宿主生命周期（前后台重跑 nativeInit、后台不暂停音频）仍未验——需要真 app
  前台或定向实验，继续登记在 I 线。
- .so 产物：修复后 `829312fd…`（剥 RUNPATH 后落 `work/libs`）；壳 scratch 树
  `~/cally-worktrees/javm64-build` 对齐 main + eprintln 日志镜像重放。
