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

第一片单测（未配对的单次采样，仅作方向参考，正式口径见 §6.1）：rm_town 12.22→9.54、
room42 13.69→10.30、rm_level1 14.02→9.39、rm_level17 19.54→12.38、rm_level16 13.43→9.53、
rm_level2 12.97→8.43 ms。

A/B 交替（min-of-3）后：rm_town 10.27→7.87、room42 11.08→8.66、rm_level17 15.44→11.81 ms
（约 1.3×）；`rm_level17` 仍在 16.67 ms 预算内，但余量薄。

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

累积提速——**必须 A/B 交替测**，下表是唯一可辩护的口径：

本机常态 loadavg 20–27（其它会话在跑），单次采样完全不可用：同一二进制同一房间
三次跑出 7.71 / 9.24 / 8.96 ms。早期"1.4–1.8×"的读数就是在未配对、单次采样下取得的，
**已作废**。可辩护口径 = 同一台机器、同一时刻交替跑基线与优化版、各取 min-of-3 重复。

| 房间 | 基线 3b1689d | 优化后 fac4b36 | 倍数 |
| --- | --- | --- | --- |
| rm_town | 10.27 | 7.87 | 1.30× |
| room42 | 11.08 | 8.66 | 1.28× |
| rm_level17 | 15.44 | 11.81 | 1.31× |

（基线 = `~/cally-worktrees/perf-baseline` @3b1689d，同一个 example、同样的 min-of-3；
3 轮交替，上表取各轮最小值。）一处在噪声中无法区分收益的改动（sprite 直写行）已回退——
测不出收益就不留在 diff 里。


### 6.3 第三片：静止帧跳过整个递交（确定性，无哈希假设）

`nativeBlitToIntArray` 现在返回"本帧是否变化"：把 framebuffer 与**上次已递交的那份字节**
做 memcmp，相同就直接返回 0，Java 侧据此**跳过整个 present**（不上传、不画、不 swap）。
同一个纹理里字节相同 ⇒ 屏幕上仍是同一张图，所以这是构造性的等价，不依赖任何指纹/哈希假设。

- 代价：变化帧 +0.22 ms（memcmp 0.15 + pack 0.07，原来 0.07）；静止帧只花 0.15 ms 的 memcmp，
  而原本每帧都要 pack + 2.91 MB `SetIntArrayRegion` + `glTexSubImage2D`(2.2–2.4 ms 串行) + swap。
- **必须同时跳过 swap**：`eglSwapBuffers` 之后的 back buffer 内容未定义，只跳上传不跳 swap
  会把未定义内容显示出去。surface 创建/重建时用 `forcePresent` 强制递交一帧。
- 边界：等价性可证（构造 + `pack_is_unchanged_requires_identical_bytes` 单测），但**收益需要真机
  复验**（CI/本机 emulator 都测不到"跳过一次 EGL 递交"的墙钟收益）。


### 6.4 第四片：静止画面的**光栅化**也跳过（确定性输入全等，`draw_frame_cached`）

第 6.3 只省掉"递交"，光栅化仍满速。本片把 `draw_frame` 的 IR 两个分支（序章过场 / 正式场景）
包成**先比较输入、相同则直接返回、framebuffer 保持原样**（原样 = 与重画逐字节相同）。

- **输入集 = 光栅化实际读到的全部**：程序化产出的发射序 + `scene.draws/texts/healthbars/
  backgrounds/room_tiles/particles` 全部内容 + 相机 + 缩放 + 分支选择位；`asset/atlases`
  在运行时只读，故不在键内。比较是 **`PartialEq` 字段级全等（无哈希、无碰撞假设）**。
- 发射序**只算一次**：`draw_ir_commands` 现在接收已算好的 `&[DrawEmission]`，绘制与比较用的是
  同一份，二者不可能不一致。
- 只有变化的帧才 clone 键（不变帧零分配）；变化帧多付约 0.1 ms 的比较。
- 旧 legacy 路径不缓存，并把缓存置空，避免跨路径误跳过。
- 单测：`draw_cache_skips_the_raster_when_inputs_repeat`（先在 framebuffer 上涂鸦，缓存命中后
  涂鸦必须原样保留 ⇒ 证明真的没重画；改动输入后必须重画）+ `draw_cache_invalidates_on_every_
  captured_category`（逐类别证明该输入确实在键内——将来新增光栅输入会让这条测试失败，
  失败模式是"画面不同步"而非"变慢"）。

实测（同一静止场景，300 次 ×3 取 min；loadavg 21.7）：

| 房间 | 每帧强制重画 | 缓存（静止） | 倍数 |
| --- | --- | --- | --- |
| rm_town | 10.25 ms | 0.017 ms | ~600× |
| room42 | 11.98 ms | 0.087 ms | ~140× |
| rm_level1 | 11.67 ms | 0.089 ms | ~130× |
| rm_level17 | 16.23 ms | 0.079 ms | ~200× |
| rm_level16 | 11.02 ms | 0.074 ms | ~150× |

边界：只覆盖"输入逐帧完全不变"的画面（过场静帧、地图屏、暂停、静止不动的镜头）；角色/敌人
动画一帧一变则照常全量重画——这不是丢帧，是"什么都不变就不重画"。


### 6.5 第五片：轴对齐 sprite 的列映射 LUT（**并更正第一片的一处无效优化**）

**更正**：第一片加进 `blit_sprite_gm` 的快路径守卫是 `scale == ±1`，但 IR 传入的 scale 是
`sprite.scale_x * screen_scale`（即**视图缩放** 2.5357/2.5397），所以那个守卫**在真实 IR 绘制里
几乎从不命中**——它当时是死代码，第一片的 sprite 提速其实来自 `blit_scaled_alpha` 一侧。

本片改成**真正会命中**的轴对齐快路径：守卫 = `rotation == 0 && 无 fog && blend 恒等`（scale 任意非 0）。
旋转为 0 时逆旋转是恒等变换（`cos==1, sin==0 ⇒ lx = rx*1 - ry*0 == rx, ly == ry`），于是
**`u` 只依赖列、`v` 只依赖行**：列映射用一块可复用 scratch LUT 每列只算一次（一次除法），
逐像素的 f64 旋转运算与两次除法、以及三次恒等通道乘法整体消失。采样、全部边界判定、alpha
规则与写入完全不变（`draw_hash` 400 帧逐字节相同）。

A/B 交替（min-of-3，同机同时刻）：

| 房间 | 上一版 | 本片 | 提速 | 对比最初基线 |
| --- | --- | --- | --- | --- |
| rm_town | 8.48 | 4.32 | ~2.0× | 10.27 → 4.32（2.4×） |
| rm_level17 | 12.61 | 5.88 | ~2.1× | 15.44 → 5.88（2.6×） |
| rm_level2 | 8.07 | 4.83 | ~1.7× | — |

教训：**优化守卫必须对着真实调用参数验证**（先打点确认命中率），否则"加了快路径"只是自我安慰；
`draw_hash` 逐字节相同在这类情况下**不能证明快路径被走到**——它是等价性判据，不是命中率判据，
命中率只能靠 A/B 的墙钟差或计数器看出。

### 6.2 这一轮扫出的其它问题（尚未处理）

1. ~~**Rust presenter 若直接接线会 R/B 互换**~~ → **已证伪并更正（2026-10）**：两套 presenter
   的 shader 从 b24e46d 起都带 `.bgra`，原判读错了文件版本。裸 64 位 javm
   （app_process64 + ImageReader Surface，真 Mali-G720 驱动）同帧读回：Rust 与 Java 输出
   **逐字节相等**（18 176 采样像素 × 两帧），各自对引擎帧缓冲期望值 0 mismatch
   （强制呈现路径亦然）。接线不存在颜色前提问题；实施情况见 §7 第 3 条。
2. **帧节拍**（用户实测暂未见问题，降级为观察项）：渲染循环是
   `Thread.sleep(16_666_667 - work)` 自计时，没有 `Choreographer`/vsync 回调，也没有
   `setFrameRate`/display-mode 提示；eglSwapBuffers 本身有 vsync，但工作点固定在任意相位，
   理论上 120 Hz 屏上会周期性错过 vsync（jitter）。
3. **静止内容仍满速重画**：两侧都已修（§6.3 递交 + §6.4 光栅化，均为确定性等价、无哈希）。
4. GPU 仍全程闲置（130 MHz）：架构上未用 GPU 做 sprite/tile 绘制。

## 7. 归因与修法（按性价比排序）
1. **继续压两个 blit 循环**（已做两轮，见 §6/§6.1）：已完成裁剪外提、增量除法、等价快路径、
   批量递交与去重边界检查；剩余成本是**非不透明像素的浮点混合**（`put_blended` 的
   `src*a + dst*(1-a)` 每通道 round）与逐像素 f64 采样。静态层缓存的前提不成立——命令生成
   只占 0.1 ms，且背景坐标随相机移动，缓存会被频繁失效。
2. **帧内容不变时不重光栅化**：实测看到的静止过场（cutscene 静帧）仍在 60 fps 满速重画 12 ms/帧。
3. ~~**接上已存在的 Rust presenter**~~ → **已实施（接线切片）**：MainActivity present 路径切到
   `nativeSetSurface`/`nativePresent`，int[] 跨 JNI 完全移除；未变化帧跳过（对 last-presented
   字节 memcmp）与 surface 事件强制呈现都在 Rust 侧闭环。javm64（真驱动 BufferQueue，
   loadavg ~23）：rust 跳过 0.096–0.103 ms/帧、强制全量 1.36–1.81，对照 javaSkip 0.137–0.144 /
   javaFull 1.79–1.80；输出与 Java 路径逐字节相等。接线时顺带修复两处从未被走到的潜伏缺陷
   （`eglGetString`、EGL size 常量 8/9/10/11）与 set_window 同指针的 ANativeWindow 引用泄漏。
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
