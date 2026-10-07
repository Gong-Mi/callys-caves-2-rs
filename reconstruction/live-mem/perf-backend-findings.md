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

## 5. 归因与修法（按性价比排序）

1. **静态几何缓存**：这些房间 tiles 大多是 0，成本来自 700–1500 个 room object
   （墙/实体）每帧重复逐像素 blit。把不动的层烘进背景缓冲，只重画变化区域/动态实例，
   可直接砍掉大头（原始 GM runner 也是 GPU 绘制，不重画静态层）。
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
