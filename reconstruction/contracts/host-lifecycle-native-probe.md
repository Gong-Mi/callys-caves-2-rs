# 宿主生命周期 native 层验收（javm64 无头壳，2026-10-12）

Issue #34 I 线登记的"宿主生命周期缺设备验收"中的 **native 层部分**，用 javm64 壳
（`su` + `app_process64`，真 GPU、无前台窗口）驱动 Java 宿主实际执行的私有 native
调用序列。harness：`~/cally-work/gmbench/src/com/gongmi/callyscaves2/GmLifecycle64.java`
+ `run_lifecycle.sh`（壳工具，不入库；跑前删 `save-v2.json`，本 run 会重写）。

## P2 — surface 销毁/重建（同一 GameState 存活）

`surfaceDestroyed`→`nativeSetSurface(null)`、`surfaceCreated`→`nativeSetSurface(new)`：

- attach+present = **true**（`set_window valid=true`，GLES3 up）；
- 分离期间 present = **false**，日志 `present skip: no window`（不触碰死窗口）；
- 重建 present = **true**，post-rebuild 帧与 pre-destroy 帧 **byte-equal
  （18176 采样像素，同一冻结引擎帧）**——换窗不扰动画面；
- 末次 `setSurface(null)` 释放干净（`set_window valid=false`，无崩溃）。

## P1 — 后台/回前台（onResume 重跑 nativeInit）

`stopEngine` 语义（`nativeSetClockPaused(true)`）→ `startEngine` 语义（再
`nativeInit` + paused(false)）：

- session 2 的 nativeInit 日志 `IR save queued for prologue handover`——
  session 1 的 autosave 被 boot 读到并排进序章交棒恢复；
- 带档 boot 与无档差异复现登记值：退场后 `active=184`（冷启动基线是 177，
  skill 既有口径"带档 boot 为 184"）；
- **present 跨 session 存活**：presenter 是进程级单例，nativeInit 只换引擎
  SLOT——resume 后同一窗口直接 present = true，expected-color **mismatches=0**；
- 无 SIGKILL/无卡死（对比 #97 的教训：display 死时"旧句柄未释放就重 init"才
  被驱动杀；这里 display 从未死，替换只是内存状态）。

## 结论与剩余边界

- native 层生命周期语义**验收通过、无需改码**：状态替换与 presenter 存活是
  安全组合；恢复链（autosave→boot queue→handover）在真驱动 BufferQueue 上闭环。
- 未验层（保留登记）：
  - Java 侧真 Activity 序列（onPause/onResume/旋转/低内存的 SurfaceHolder 时序、
    renderThread join 竞争）——需要真机前台；
  - **音频后台不暂停**：SoundPool/MediaPlayer 属 Java 宿主，壳里无 Activity
    context 无法测——这是登记行为的复述（后台 BGM 继续），修与不修待前台验收后定；
  - ImageReader 是 BufferQueue：不含 scanout/vsync。
