# 渲染后端性能归因（真机 + 本机可复现测量）

面向问题："现在性能很差"。结论先行：**渲染后端是单线程 CPU 软件光栅化 + 整帧纹理上传**，
GPU 只被当上传目标用（真机观测 GPU 130 MHz 空闲），因此每帧绘制成本全部压在一颗 CPU 核上，
真实关卡里单独"绘图"就吃掉 12–20 ms（60 fps 预算 16.67 ms）。

## 1. 真机现场（截屏叠加层，用户提供屏上读数）

| 指标 | 读数 | 含义 |
| --- | --- | --- |
| #FPS | 120.0 | 屏幕/合成刷新，非本 app 帧率 |
| GPU | **130 MHz** | GPU 处于最低频，图形工作几乎为零 |
| CPU 0–7 | 94–100% @1.6 GHz，CPU 104.7 °C | 全部 CPU 时间在被判绘制/逻辑线程吃掉（含其它会话负载） |
| 进程表 | 本 app 52.3% | 软件光栅化是本 app 的主要 CPU 消耗 |

## 2. 每帧实际做了什么（代码路径）

    MainActivity.RenderLoop（单线程）
      nativeStep(now)
        FrameClock::step_at      -> 逻辑步进          (crates/client/src/parts/jni.rs:231)
        draw_frame(&mut s.fb)    -> 整帧 CPU 软件光栅化 (jni.rs:302, lib.rs:1178)
      nativeBlitToIntArray(int[])
        逐像素 ABGR->ARGB 重排 (727,040 次标量循环)     (jni.rs:410)
        SetIntArrayRegion -> 2.91 MB 拷进 Java 堆数组  (jni.rs:421)
      GlesPresenter.present(int[])                      (android-build/src/.../GlesPresenter.java:148)
        IntBuffer.wrap(堆数组) -> glTexSubImage2D 全帧上传 2.91 MB
        glDrawArrays(1 quad) + eglSwapBuffers(vsync)

    parts/gles.rs 里另有一套 Rust presenter（nativeSetWindow / nativePresent，直接吃
    state.fb.pixels），**从未被 MainActivity 调用**：`git log -S'nativeSetWindow' -- MainActivity.java`
    为空，说明它 0 次接入过。它存在的意义正是省掉上面的"逐像素重排 + JNI 数组拷贝"。

## 3. 本机可复现测量

### 3.1 CPU 侧（release，本机 aarch64 = 设备同款 CPU）

    cargo run --release --example frame_cost      # 逻辑/光栅化/重排 三相分解
    cargo run --release --example room_raster_cost # 逐房间软件光栅化成本

| 阶段 | ms/帧 | 备注 |
| --- | --- | --- |
| a. 逻辑 GameState::step | 0.04 | 与场景无关 |
| b. 光栅化 draw_frame（rm_town，prologue 态） | 5.0–5.7 | 见 3.2 的真实关卡数字 |
| c. 重排 ABGR->ARGB（727k 像素） | 0.6 | 纯浪费，Rust presenter 可消除 |

逐房间（restore_ir_snapshot 走完整换房流程后测，300 次平均）：

| 房间 | 活跃实例 | 光栅化 ms/帧 | 仅绘图上限 |
| --- | --- | --- | --- |
| rm_town | 149 | 12.22 | 82 fps |
| room42 | 787 | 13.69 | 73 fps |
| rm_level1 | 805 | 14.02 | 71 fps |
| **rm_level17** | 797 | **19.54** | **51 fps** |
| rm_level16 | 678 | 13.43 | 74 fps |
| rm_level2 | 700 | 12.97 | 77 fps |

即：**只算绘图**就已经逼近/突破 16.67 ms 的 60 fps 预算，重场景 51 fps 上限；
加上 0.6 ms 重排 + 2.9 MB JNI 拷贝 + 上传 + vsync swap，实际落到 ~40 fps 且抖动。

### 3.2 GPU 侧（真机 Mali-G720，裸 dalvikvm + PBuffer，见 §4）

    GL_RENDERER = Mali-G720-Immortalis MC12   (ES 3.2 v1.r44p1)

| 上传变体 | ms/帧 | 结论 |
| --- | --- | --- |
| A. heap IntBuffer.wrap（app 现路）RGBA8888 | 2.234 | 与 B 无实质差异 |
| B. direct ByteBuffer RGBA8888 | 2.400 | 堆数组不是瓶颈 |
| C. direct ShortBuffer RGB565（独立 GL_RGB 纹理） | 2.394 | 与 A/B 持平 |
| D/E. RGBA8888 / heap，4 帧流水 | 0.33 / 0.21 | 帧内异步，真正代价取决于同步点 |

**纠错**：早先一次测量给出"RGB565 快 4.4 倍（0.52 ms）"，那是**假象**——上传被驱动拒绝
（glGetError=1282 = GL_INVALID_OPERATION）而变成空操作；用独立 GL_RGB 纹理重测后
RGB565 与 RGBA8888 持平。格式不是本后端的优化点（这条写进来是为了防止后人重复踩）。

## 4. 本机 javm 也能调 GPU（测量配方，已实测）

裸 dlopen(`/system/lib64/libEGL.so`) **拿不到 display**：`eglGetDisplay(EGL_DEFAULT_DISPLAY)` 返回 NULL，
且 libGLESv3.so 因 `android::egl_get_connection()` 不可见而无法 dlopen。可行路径是复用壳的 shim：

    1. System.load("/system/lib/libandroid_runtime.so")   # 32 位；framework 环境由此建立
    2. System.load(work/libs/libbhshell.so); BhShell.regFramework()
    3. EGL10 + PBuffer 1136x640（框架 EGLImpl，真驱动）
    4. GLES 入口若 libGLESv3 不可 dlopen，可用 eglGetProcAddress 直接取

必须在 **su** 下跑（32 位 ELF 走 hbt 翻译，需 /dev/hbt）：

    javac -bootclasspath $ANDROID_JAR -cp $SHELL32/build/classes -d out GlBench.java
    dx --dex --output=glbench.dex out
    su -c 'sh ~/cally-work/glbench/run_glbench.sh'

工具位置：`~/cally-work/glbench/{GlBench.java,run_glbench.sh}`。

## 5. 逐类归因（临时仪表，`CALLY_DRAW_PROFILE=1`，测完已回退）

`draw_frame` 按队列分类计时（每帧 ms）：

| 房间 | 原语/帧 | gen | clear | bg | sprite | 其它 |
| --- | --- | --- | --- | --- | --- | --- |
| rm_town | 157 | 0.03 | 0.00 | 3.97 | 6.82 | text/hb/tile/particle ≈ 0.02 |
| room42 | 796 | 0.10 | 0.72 | 3.99 | 7.71 | ≈ 0.02 |
| rm_level1 | 928 | 0.12 | 0.73 | 4.05 | 7.93 | ≈ 0.03 |
| rm_level17 | 806 | 0.13 | 0.79 | 4.27 | **12.90** | ≈ 0.02 |
| rm_level16 | 686 | 0.09 | 0.72 | 4.02 | 6.38 | ≈ 0.03 |
| rm_level2 | 700 | 0.11 | 0.82 | 4.43 | 7.70 | ≈ 0.13 |

结论修正：命令生成/排序（`ordered_draw_commands` 每帧建 Vec+BTreeSet+排序）只占 0.1 ms，
**不是**瓶颈（先前的"静态层缓存"设想的收益基础不成立）；成本全在**两个逐像素循环**：
整屏缩放的背景 blit（恒定 ~4 ms）与 sprite blit（6–13 ms）。

## 6. 已实施的等价优化（本 PR）

`parts/framebuffer.rs` 两处快路径，**输出逐字节不变**：

1. `blit_scaled_alpha`（背景/缩放 blit）：目标可见区间一次裁剪（原来每像素判边界）、
   采样映射改为**增量除法**（`rem += sw; while rem >= dw { rem -= dw; x += 1 }`，与
   `ox*sw/dw` 整数结果逐位相同）、不透明像素直写不再走 `put_blended` 的浮点路径。
2. `blit_sprite_gm`：轴对齐 + 单位缩放(±1) + 无 fog + 恒等 blend 时走快路径——此时逆旋转
   就是恒等变换（`cos==1, sin==0 ⇒ lx=rx`），除以 ±1.0 精确，于是逐像素 f64 旋转、
   两次除法与三次恒等通道乘法整体消失；采样、全部边界判定、alpha 规则与写入保持不变。

等价性判据：`cargo run --release --example draw_hash` 输出 400 帧帧缓冲 FNV-1a 哈希
（序章 40 帧 + 退场 40 帧 + 8 个房间各 40 帧），优化前后**同为 sha256
`790d13ea1aba5b1581898f8ee1b25a8ec4010523e32cc58d6cd787f21fdc993e`**（diff 0 行）。

提速（300 次平均，同一台机器）：

| 房间 | 优化前 ms | 优化后 ms | 仅绘图上限 |
| --- | --- | --- | --- |
| rm_town | 12.22 | 9.54 | 82 → 105 fps |
| room42 | 13.69 | 10.30 | 73 → 97 fps |
| rm_level1 | 14.02 | 9.39 | 71 → 106 fps |
| rm_level17 | 19.54 | 12.38 | 51 → 81 fps |
| rm_level16 | 13.43 | 9.53 | 74 → 105 fps |
| rm_level2 | 12.97 | 8.43 | 77 → 119 fps |

rem_level17 从"单独绘图就超 16.67 ms 预算"回到预算内（12.38 ms），但余量仍薄。

### 6.1 第二片：整帧递交路径 + 采样（同一 PR 内）

- **`nativeBlitToIntArray` 的逐像素重排是空转**：framebuffer 就是 BGRA8888，而小端
  `0xAARRGGBB` int 在内存里正是同样四字节 ⇒ 原来的"读 chunk、移位打包、写回 int"是
  **逐字节恒等变换**。改为 `Framebuffer::pack_into_i32`（`copy_nonoverlapping` 批量拷贝），
  附单测同时断言 int 序列与底层字节序列一致，防这个假设悄悄失效。
  实测 **0.50 → 0.07 ms/帧**（并少一次 2.9 MB 分配）。
- `fill_rect` 改 4 字节 pattern 的 `chunks_exact_mut` 填充（字节相同，指令更少）。
- 两个 blit 的采样改走 `atlas.as_raw()`，不再每像素调 `get_pixel` 的重复边界检查
  （我们自己的判定已经保证下标在范围内）。

等价性判据：`draw_hash` 400 帧哈希仍与基线**完全相同**（sha256 `790d13ea…`）；新增
`pack_into_i32_is_byte_identical_to_per_pixel_repack` 单测通过；Android 目标
`cargo check --features android --target aarch64-linux-android` 通过。

累积提速（300 次平均）：

| 房间 | 基线 | 一片后 | 二片后 | 总计 |
| --- | --- | --- | --- | --- |
| rm_town | 12.22 | 9.54 | 7.51 | 1.63× |
| room42 | 13.69 | 10.30 | 9.31 | 1.47× |
| rm_level1 | 14.02 | 9.39 | 8.51 | 1.65× |
| rm_level17 | 19.54 | 12.38 | 11.49 | 1.70× |
| rm_level16 | 13.43 | 9.53 | 7.43 | 1.81× |
| rm_level2 | 12.97 | 8.43 | 7.32 | 1.77× |

### 6.2 这一轮扫出的其它问题（尚未处理）

1. **Rust presenter 若直接接线会 R/B 互换**：`GlesPresenter` 的 fragment shader 注释写着
   "Engine bytes are little-endian ARGB ints = B,G,R,A in memory; an RGBA upload therefore
   reads back swapped, so swizzle here" 并 `texture(...).bgra`。而 `parts/gles.rs` 是直接把
   `state.fb.pixels` 当 `GL_RGBA` 上传的——**它接上后颜色会反**，除非同样做 swizzle/换格式。
   这解释了它为何停在被合并但未接线的状态，也是接线前必须先解决的点。
2. **帧节拍**：渲染循环是 `Thread.sleep(16_666_667 - work)` 自计时，没有 `Choreographer`
   / vsync 回调，也没有 `setFrameRate`/display-mode 提示；eglSwapBuffers 本身有 vsync，
   但工作点固定在任意相位，120 Hz 屏上会周期性错过 vsync（jitter）。
3. **静止内容仍满速重画**：过场静帧/菜单不改画面也每帧重光栅化 + 重上传（屏上看到的正是静帧）。
4. GPU 仍全程闲置（130 MHz）：架构上未用 GPU 做 sprite/tile 绘制。

## 7. 归因与修法（按性价比排序）
1. **继续压两个 blit 循环**（已做两轮，见 §6/§6.1）：已完成裁剪外提、增量除法、等价快路径、
   批量递交与去重边界检查；剩余成本是**非不透明像素的浮点混合**（`put_blended` 的
   `src*a + dst*(1-a)` 每通道 round）与逐像素 f64 采样。静态层缓存的前提不成立——命令生成
   只占 0.1 ms，且背景坐标随相机移动，缓存会被频繁失效。
2. **帧内容不变时不重光栅化**：实测看到的静止过场（cutscene 静帧）仍在 60 fps 满速重画 12 ms/帧。
3. **接上已存在的 Rust presenter**：省掉 0.6 ms 重排 + 2.91 MB JNI 拷贝（约 1–2 ms）。
4. **把 sprite/tile 绘制搬到 GPU**（结构改造，Issue #54 的"GlesPresenter 只上传整帧、不是
   GPU 命令后端"正是这个缺口）：GPU 空在 130 MHz，算力完全没用上。
5. 多线程化软件光栅化（瓦片/sprite blit 天然可并行）：中等改造，收益随核数。

## 6. 复现命令

    cd ~/callys-caves-2-rs
    cargo run --release --example frame_cost
    cargo run --release --example room_raster_cost

## 7. 证据边界

- CPU 侧为**宿主=同款 CPU** 的 release 实测；真机叠加层显示 CPU 104.7 °C 已热限制，
  真机数字只会更差，不会更好。
- GPU 侧为真机驱动实测，但在 **32 位 dalvikvm + 框架 EGL/GLES（ES2 上下文）+ PBuffer** 下取得；
  与 app 的 64 位 ES3 窗口上下文不同，上传成本量级可比、绝对值不可直接当 app 帧时间。
- swap/vsync 段无法无窗口测量，未计入。
