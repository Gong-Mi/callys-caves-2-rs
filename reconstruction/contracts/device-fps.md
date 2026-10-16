# 真机端到端帧率（nativeStep + present，javm64 无头壳）

测量日期 2026-10-16；装置 = 本机（Termux aarch64 + Mali，Android 16）。
证据层：**真机真 GPU（GLES3 驱动真上传/绘制/swap）、无头 app_process64 壳**；
不含 Activity/窗口/SurfaceFlinger 合成与 scanout。这一点贯穿全文，见 §6。

## 0. 汇报值（两轮共 6 轮取 min-of-N，与仓内既有 min-of-2/min-of-3 口径一致）

| 场景 | presenter | 口径 | 帧时间 p50 | fps(p50 帧) | 帧时间 min | fps(最好帧) | 帧时间 p95 | fps(p95 帧) |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rm_town（静止为主） | native(Rust) | skip 命中 | 10.34 ms | **96.7** | 9.48 ms | 105.5 | 11.96 ms | 83.6 |
| rm_town | native(Rust) | 变帧全量 present | 11.14 ms | **89.7** | 10.31 ms | 97.0 | 11.87 ms | 84.3 |
| rm_town | java(GlesPresenter) | skip 命中 | 10.68 ms | **93.7** | 9.49 ms | 105.4 | 12.30 ms | 81.3 |
| rm_town | java | 变帧全量 present | 11.70 ms | **85.5** | 10.43 ms | 95.9 | 12.80 ms | 78.1 |
| rm_level17（活动，797 活跃实例） | native(Rust) | skip 命中 | 16.53 ms | **60.5** | 15.36 ms | 65.1 | 18.83 ms | 53.1 |
| rm_level17 | native(Rust) | 变帧全量 present | 17.62 ms | **56.8** | 16.22 ms | 61.7 | 22.74 ms | 44.0 |
| rm_level17 | java(GlesPresenter) | skip 命中 | 16.59 ms | **60.3** | 15.37 ms | 65.1 | 19.29 ms | 51.8 |
| rm_level17 | java | 变帧全量 present | 18.15 ms | **55.1** | 16.43 ms | 60.9 | 23.36 ms | 42.8 |

每格 = 该 (场景×presenter×口径) 6 轮里最快一轮的 p50；全 6 轮明细见 §4。fps = 1e9/frame_ns，
fps(p95 帧) = 95% 的帧都不慢于此的保守值，fps(最好帧) = 该轮最快单帧。

**一句话**：rm_town 稳态 ≈ 90–97 fps（最好 105），rm_level17 ≈ 57–60 fps（最好 65）——都远高于
60 的常见目标，但 **rm_level17 的 17.6–18.8 ms/帧已经越过 16.67 ms 预算**：app 那条
`16_666_667 - elapsed` 的 sleep 在 17 房恒为 0，即该房间在这台机器上守不住 60 fps
（且 §6 的握手开销还没算进去，只会更低）。

## 1. 方法

### 1.1 被驱动的帧序列（与 `MainActivity.RenderLoop` 逐调用对齐）

```
long now = <synthetic monotonic>;      // 或 System.nanoTime()，见 1.2
nativeInput(0, holdRight, 0, 0, 0, 0, tapFlag);
nativeStep(now);                       // 逻辑 + 软件光栅化（整帧）
nativePresent();                       // Rust presenter：上传+绘制+swap，或整段跳过
// Java 腿： nativeBlitToIntArray(int[]) -> 变化才 GlesPresenter.present(int[])
// 无 sleep：app 睡觉对齐 16.67 ms，这里背靠背跑，所以数字是「可持续上限」而非 app 目标帧率
```

三段时间戳各自成对采样：`step`、`present`（java 腿另加 `blit`）。`frame_ns = step + blit + present`，
即 app 渲染线程上真正属于「出一帧」的工作。

### 1.2 时间模型：固定 30 Hz 逻辑帧（dt=33 333 333 ns）

`nativeStep` 喂的是**固定 dt**（= 仓内既有分量基线的同一模型：`GmEngine64`/`GmPresent64`
也是 33.33 ms/帧），所以「一帧」= 一次逻辑 tick + 一次整帧光栅化 + 一次 present，
与 2026-10-09 分量基线同工作量，才可与分量加和对照（§5）。

给**真实时钟**也能跑（`DT_NS=0`），但已实测该口径不可用：引擎是定 tick 游戏，
背靠背循环里实际 dt ≈ 0.1 ms，几乎不触发逻辑 tick —— 测得的是「空转帧」，
rm_town 一度跑出 8191 fps（显然是假象）。真实时钟口径只保留作边界探针。

### 1.3 两场景的构造（都在真引擎里、用引擎自己的存档机制，不改 crates/）

- `town`：`work/files-fps/town/`（`game.droid`/`full_ir.json`/`textures`/`sfx` 符号链接到
  `work/files/`，每轮删除 `save-v2.json` 保证冷启动路径逐轮一致）。boot 300 帧，
  第 130 帧注入真实 tap 脉冲（`nativeInput(tap=1)` 4 帧 + 第 131 帧
  `nativePointerRelease(568,320)`）退场序章 → tick 128 起 `room=0 intro=false`，
  `active=147`，无 halt。
- `level17`：`work/files-fps/level17/save-v2.json`（v2 快照，`current_room=25`，
  `checkpoint.room_index=25`）。IR v2 存档是**序章交接后**才 load 房间的
  （`crates/client/src/lib.rs:643-649`），所以**同样**要在 boot 里点掉序章：
  实测 tick 128 起 `room=25 roomstart=false active=797`，直到 tick 1200 全程
  room=25、`halted=false`（每轮日志的 IR checkpoint 就是房间证据）。
- 两场景都不用 `HOLD_RIGHT`/输入来造活动（见 §7.1 的观察）。

### 1.4 两口径（按 presenter 自己的裁决分帧，不是外部假设）

- `skip 命中`：presenter 判定本帧与上次已递交字节相同 → 整个 present 跳过
  （不上传/不绘制/不 swap）。
- `变帧`：全量 present（上传 + 绘制 + `eglSwapBuffers`）。

rm_town/rm_level17 的变帧节奏是**严格每 3 个 tick 一次**（30 Hz tick 上的 10 Hz 变化，
900 帧恰好 300/600），所以两口径样本数固定且干净。

### 1.5 单线程相位纪律

两个 presenter 都在各自进程里保持唯一 current 的 EGL context，BufferQueue 单生产者：
**一个进程只测一个 presenter**，java 腿与 native 腿分进程跑，绝不交错。
每轮 = 全新 `app_process64` 进程（含 ART/JIT 冷启动，boot 300 帧即热身）。

### 1.6 统计与推导

- 每帧记 `step/blit/present`（+ `input`/`drain` 记账，见 §3）→ 每口径取 min/p50/p95/max，
  `fps = 1e9/frame_ns`，因此 fps(最好帧)=1e9/frame_min、fps(p95 帧)=1e9/frame_p95。
- 每轮 900 帧测量 + 300 帧 boot，两场景各跑 2 轮 × 3 次（两个 pass），
  每轮打印 `loadavg` 与当前 top CPU 进程（归因用）。
- 另有整进程 CPU 时间（`/proc/self/stat` utime+stime，1 tick=10 ms）作**与负载无关**的对照。

## 2. 环境

| 项 | 值 |
| --- | --- |
| 装置 | 2407FRK8EC，Android 16（SDK 36），内核平台 mt6989，8 核（cpu0 小核 ≤2.0 GHz，cpu7 大核 ≤3.4 GHz），governor `sugov_ext`，Mali（`13000000.mali`） |
| 引擎 .so | `libcallys_client.so` sha256 `829312fdb0c2324d7e7f1d5d39ac5fd08709f094c2cbbc7a10b49293f048397f`（前缀 `829312fd`），`readelf -W --dyn-syms \| grep -c Java_` = **13**；javm64-build 工作树 `f75a702` + EGL 丢失修复，与 `egl-context-loss-recovery.md` 记录的同一产物；`patchelf --remove-rpath` 后落 `work/libs` |
| 承载 dex | pass1 `gmfps.dex` sha256 `48907b5c618a…`；pass2 `be7a741d902a…`（仅多整进程 CPU 计数，被测代码/引擎未变） |
| harness | `gmfps64-v1` = `src/com/gongmi/callyscaves2/Gmfps64.java` + `run_fps_endtoend.sh` + `fps_build_gmbench.sh`（javac --release 17 + r8.jar D8，min-api 24，源集与 `build_gmbench.sh` 相同：harness `src/` + `android-build/src`） |
| 运行容器 | `app_process64 -Djava.class.path=gmfps.dex -Djava.library.path=work/libs`，无 Activity/窗口/`Surface`；呈现目标是 `ImageReader(w,h,RGBA_8888,4)` 的 Surface（真 BufferQueue） |
| 数据 | `work/files-fps/{town,level17}`；画布 1136×640（`nativeGetWidth/Height`） |
| 负载 | 全程 loadavg(1m) **18.98–24.71**；常态基线是 4 个 python3 观察进程（各 10–14%）；期间兄弟工作线在编译，`rustc`/`javac`/`cargo`/`gh` 峰值 85–331% —— 每轮 `top_cpu` 已记进日志，§4 逐轮标注 |
| 热/频 | 测量期 thermal_zone0 ≈ 45.7 ℃（未触限），scaling_cur_freq 采样 cpu0 0.6 / cpu4 2.6 / cpu7 3.0 GHz |

## 3. 校准：A/A、安慰剂、环内开销归账

**A/A（同脚本同参数两轮，逐字段对照）**，取第一轮 campaign 的前两轮（那两轮 top_cpu 仅
python3 观察进程，无编译器）：

| 量 | round 1 | round 2 | 差 |
| --- | --- | --- | --- |
| rm_town/native 变帧 frame p50 | 11.14 ms | 11.25 ms | **+0.9%** |
| rm_town/native skip frame p50 | 10.34 ms | 10.44 ms | **+0.9%** |
| rm_town/native 变帧 present p50 | 1.163 ms | 1.104 ms | −5.1% |
| rm_town/native skip present p50 | 0.214 ms | 0.213 ms | −0.5% |
| 变帧数 | 300/900 | 300/900 | 0 |

结论：**测量本身噪声 <5%**（帧级 p50 0.9%，present 级 ≤5%）；跨轮更大差异来自环境
（§4 逐轮 top_cpu/负载即证据），不是脚本抖动。pass2 的 rm_level17/native 三轮
frame p50 为 17.62/17.79/17.73（±0.5%）、整进程 CPU 17.41/17.42/17.49 ms/帧（±0.2%），
是同一结论的第二个独立样例。

**安慰剂（脚本自身开销）**

| 项 | 值 | 说明 |
| --- | --- | --- |
| p1：采样骨架（3×`nanoTime` + 一个平凡依赖写） | min 0 / p50 0 / p95 231 ns | `nanoTime` 采样密度的上限 |
| p2：p1 + 每帧 `ImageReader.acquireLatestImage/close`（无 GL） | min 307 / p50 384–615 / p95 1000 ns | 只计「拿图」本身的调用开销 |
| `input`（`nativeInput` 7 参反射 + JNI） | p50 3.7–9.3 µs | 环内、不计入 frame_ns |
| `drain`（环内真拿图，见下） | skip 帧 p50 0.010 ms；**变帧 p50 3.2–4.3 ms** | 环内、不计入 frame_ns |

**环内开销归账**（`RECON`）：`wall_us_per_frame − (step+blit+present+input+drain)` =
1.5 µs（rm_town 120 帧样例）——加了两个额外采样点后，整环已无未归账时间
（此前未插桩时该缺口是 1.3–1.4 ms/frame，正是 drain 的墙钟）。

**整进程 CPU/帧 vs 墙钟**（`CPU` 行，pass2）：rm_town 11.2–12.8 ms、rm_level17
17.4–17.7 ms、rm_level17+按右 17.7–18.2 ms；`cpu_over_wall` 0.91–0.97 ⇒ 环内
3–9% 的墙钟不在 CPU 上（等待缓冲握手，绝大部分是 harness 的 drain），
也说明 step/present 段是 CPU 受限、不是等待受限。

## 4. 数字表

### 4.1 pass2（loadavg 19.0–21.6）逐轮

| 配置 | 轮 | loadavg(1m) / 轮首 top CPU | skip 命中 frame p50 → fps | 变帧 frame p50 → fps | CPU/帧 |
| --- | --- | --- | --- | --- | --- |
| town/native | 1 | 19.0→19.6 / python3 | 11.81 → 84.7 | 12.66 → 79.0 | 12.43 ms |
| town/native | 2 | 19.6→19.2 / python3 | 11.64 → 85.9 | 12.40 → 80.6 | 12.13 ms |
| town/native | 3 | 19.2→18.6 / python3 | **10.54 → 94.9** | **11.46 → 87.2** | 11.18 ms |
| town/java | 1 | 18.6→18.3 / python3 | 10.91 → 91.6 | 11.90 → 84.0 | 11.48 ms |
| town/java | 2 | 18.3→19.7 / `/data/d` 140% + cargo 36% | 11.95 → 83.7 | 13.07 → 76.5 | 12.76 ms |
| town/java | 3 | 19.7→19.9 / `/data/d` 235% | 11.06 → 90.4 | 12.29 → 81.4 | 11.74 ms |
| l17/native | 1 | 20.0→20.2 / python3 | **16.53 → 60.5** | **17.62 → 56.8** | 17.41 ms |
| l17/native | 2 | 20.2→19.4 / python3 | 16.54 → 60.5 | 17.79 → 56.2 | 17.42 ms |
| l17/native | 3 | 19.0→19.3 / python3 | 16.70 → 59.9 | 17.73 → 56.4 | 17.49 ms |
| l17/java | 1 | 19.3→19.0 / python3 | **16.59 → 60.3** | **18.15 → 55.1** | 17.61 ms |
| l17/java | 2 | 19.0→18.9 / python3 | 17.15 → 58.3 | 18.68 → 53.5 | 17.67 ms |
| l17/java | 3 | 18.9→19.5 / python3 | 16.82 → 59.5 | 18.19 → 55.0 | 17.68 ms |
| l17/native+按右 | 1 | 19.5→19.8 / python3 | 18.00 → 55.6 | 20.05 → 49.9（n=26） | 18.20 ms |
| l17/native+按右 | 2 | 19.7→19.3 / python3+gh | 17.93 → 55.8 | 20.17 → 49.6（n=26） | 18.20 ms |
| l17/native+按右 | 3 | 19.3→19.4 / python3 | **17.31 → 57.8** | **19.17 → 52.2**（n=26） | 17.70 ms |

### 4.2 pass1（loadavg 20.5–24.7，兄弟线在编译）逐轮

| 配置 | 轮 | loadavg(1m) / 轮首 top CPU | skip frame p50 → fps | 变帧 frame p50 → fps |
| --- | --- | --- | --- | --- |
| town/native | 1 | 21.1 / python3 | **10.34 → 96.7** | **11.14 → 89.7** |
| town/native | 2 | 21.4 / python3 | 10.44 → 95.8 | 11.25 → 88.9 |
| town/native | 3 | 21.2 / javac 142% | 10.47 → 95.5 | 11.30 → 88.5 |
| town/java | 1 | 20.7 / python3 | **10.68 → 93.7** | **11.70 → 85.5** |
| town/java | 2 | 20.5 / `ps` 快照 | 12.00 → 83.3 | 13.30 → 75.2 |
| town/java | 3 | 23.6 / rustc 100% + git 86% | 20.26 → 49.4 | 22.18 → 45.1 |
| l17/native | 1 | 23.6→24.6 / rustc 245% + rustc 86% | 22.62 → 44.2 | 25.47 → 39.3 |
| l17/native | 2 | 24.6→23.8 / python3 | **17.63 → 56.7** | **18.49 → 54.1** |
| l17/native | 3 | 23.8→22.8 / python3 | 22.93 → 43.6 | 24.72 → 40.5 |
| l17/java | 1 | 22.8→22.0 / `/data/d` 232% | **19.36 → 51.6** | **21.40 → 46.7** |
| l17/java | 2 | 22.0→24.7 / rustc 273% | 30.29 → 33.0 | 33.58 → 29.8 |
| l17/java | 3 | 24.7→24.1 / rustc 313% + `/data/d` 165% | 25.71 → 38.9 | 28.79 → 34.7 |
| l17/native+按右 | 1 | 24.1→24.4 / rustc 331% + cargo | 30.99 → 32.3 | 35.74 → 28.0（n=26） |
| l17/native+按右 | 2 | 24.4 / `/data/d` 251% + rustc 241% | 19.53 → 51.2 | 21.09 → 47.4（n=26） |
| l17/native+按右 | 3 | 24.3→23.5 / `/data/d` 172% | **17.99 → 55.6** | **20.10 → 49.7**（n=26） |

同一配置同二进制，跨轮最大差 **2.3×**（l17/java skip：19.36 → 30.29 ms），且大差都落在
`top_cpu` 有编译器占满核的轮次上 —— 与 `#75` 正文记录的教训一致（「本机常态
loadavg 20–27，同一二进制同一房间连续三次跑出 7.71/9.24/8.96 ms」）。
**所以汇报值只能用 min-of-N 的「轻污染口径」，并同时给出保守端**（§0 的 p95 帧一列）。

### 4.3 两场景的差异来自哪一段

| 量（pass2 p50） | rm_town | rm_level17 | 备注 |
| --- | --- | --- | --- |
| skip 帧 step | 10.5–11.8 ms | 16.3–16.9 ms | 整帧光栅化 + 逻辑（active 147 vs 797） |
| 变帧 step | 10.3–11.7 ms | 16.5–17.2 ms | **与 skip 帧几乎相同**（见 §7.2） |
| skip present | 0.207–0.229 ms | 0.211–0.215 ms | 两房一致 |
| 变帧 present（native） | 1.124–1.156 ms | 1.023–1.061 ms | 两房一致 |
| 变帧 present（java） | 0.805–0.900 ms | 0.877–0.922 ms | 比 native 低 ~0.2 ms |
| blit（java 腿，变帧 / skip） | 0.506 ms / 0.205 ms | 0.439 ms / 0.198 ms | 只在 java 腿存在 |

即：**场景差全在 step（逻辑+光栅化）**，present 段与房间无关；
presenter 之间的差别是 native 比 java 高 ~0.2 ms（java 腿把 int[] 导出记在 blit 里，
两条腿的「导出+上传」总账相当：java 0.51+0.86 ≈ 1.37 ms vs native 1.15 ms，见 §5）。

## 5. 与 2026-10-09 分量基线的合成对照

### 5.1 分量表（同一装置、同一 .so 家族）

| 分量 | 口径 | 既有基线 | 本次（环内） | 差 |
| --- | --- | --- | --- | --- |
| `rustFull` present | 全量递交 | 1.52（2026-10-09, min-of-2, lavg≈18）/ 1.295（2026-10-12, lavg≈21） | 1.02–1.16 | −0.2 ~ −0.5 |
| `rustSkip` present | 未变跳过 | 0.08 / 0.09 | 0.21–0.23 | +0.13 |
| `javaFull` present | 全量递交 | 1.50 / 1.88 | 0.81–0.92 | −0.6 ~ −1.0 |
| `javaSkip` | 未变跳过 | 0.13 / 0.126 | （java 腿不走 present）blit skip 0.20–0.29 | ≈ |
| 整帧软件光栅化 | 强制重画 | `#75` A/B min-of-3：rm_town **4.32** / rm_level17 **5.88**（静止命中 0.017/0.079） | 未单独测（含在 step 内） | — |
| 逻辑 tick | — | 未单独测 | 未单独测（step − 光栅化 的推断值，见 5.2） | — |

### 5.2 分量加和 vs 端到端实测

以 rm_town / native / skip 帧为例（pass1 r1，最轻污染轮）：

```
实测帧 p50                  = 10.34 ms   (= step 10.10 + present 0.21 + blit 0)
分量加和（逻辑 + 4.32 光栅化 + 0.21 skip present） = 逻辑 + 4.53
⇒ 推出逻辑 ≈ 5.8 ms / 帧（147 活跃实例）
```

rm_level17 / native / 变帧（pass2 r1）：

```
实测帧 p50 = 17.62 ms (= step 16.54 + present 1.02)
分量加和 = 逻辑 + 5.88 光栅化 + 1.02 present
⇒ 推出逻辑 ≈ 9.6 ms / 帧（797 活跃实例）
```

两点必须先说清楚，否则加和会虚高：

1. **`#75` 的光栅化数字若是 960×540 画布下测的**（`Framebuffer::new(960,540)` 是 client
   测试/example 的常见尺寸），在真机 1136×640 画布上要按像素数放大 ≈1.40×：
   rm_town 4.32 → ≈6.0 ms、rm_level17 5.88 → ≈8.2 ms；上面推得的逻辑值相应变成 ≈4.1 / 7.3 ms。
   文档里没有记录那次测量的画布尺寸，**两个版本都在可辩护区间内**，故逻辑值只当区间看
   （rm_town ≈4–6 ms、rm_level17 ≈7–10 ms）。
2. **present 分量普遍比 2026-10-09/-12 的隔离测量低 0.2–1.0 ms**：那两次是在
   **只跑 present 的紧循环**里测的（`GmPresent64` 不 step）；本次 present 夹在
   1/3 递交比例的真实帧环里，前面有 10–17 ms 的 step 把 GPU/BufferQueue 排空，
   递交几乎不撞 back-pressure。这是**测量语境差，不是代码变快**：两次用的都是
   同一 `.so`（`829312fd`）与同一 presenter 实现。

### 5.3 差值归因（端到端 − 分量加和）

| 观察 | 归因 |
| --- | --- |
| 端到端 frame ≈ step + present，无第三个隐藏量 | `RECON` 残差 1.5 µs（§3），环内已逐段记账 |
| 两场景差 = step 差（10.5→16.5 ms），present 不变 | step = 逻辑（实例数 147→797）+ 光栅化；present 与房间无关 |
| 变帧与 skip 帧的 step 相同（差 <0.3 ms） | **未变帧并没有省下光栅化**：见 §7.2（与 `#75` 第四片的缓存预期相悖） |
| present 比隔离基线低 0.2–1.0 ms | 递交比例 1/3 的环内语境 vs isolo 紧循环（§5.2-2），非回归 |
| 跨轮 2.3× 差异、CPU/帧却只 ±0.5% | 兄弟编译负载 + DVFS/调度；**CPU/帧是更可信的稳定量**（§3） |
| loadavg 20 常态下帧 p95 是 p50 的 1.1–1.3 倍 | 后台负载尖峰；汇报值用 min-of-N，尾部用 fps(p95 帧) |

## 6. 测量边界（未验层，按证据分层列出）

1. **不含显示路径**：ImageReader 是 BufferQueue，含真上传/绘制/`queueBuffer`/swap 的
   GPU 与驱动成本；**不含** SurfaceFlinger 合成、BLAST、scanout、vsync。
   本壳里没有窗口，所以也没有 `eglSwapInterval` 的 vsync 等待。
2. **不含消费端 back-pressure 的完整形态**：harness 自己 drain（变帧 3.2–4.3 ms 墙钟，
   skip 帧 0.01 ms），实测整进程 `cpu_over_wall` 0.91–0.97 ⇒ 环内 3–9% 墙钟在等缓冲握手。
   若把这部分按「每次递交都要付」算，端到端帧要再 +≈1.2 ms（1/3 比例 ×3.5 ms）：
   rm_town ≈81 fps、rm_level17 ≈53 fps。**这是上界估计，不是实测**。
3. **无 sleep 的背靠背循环**：app 的 `RenderLoop` 用 `16_666_667 − elapsed` 睡眠对齐 60 Hz；
   本次测的是可持续上限。对 app 的含义是可判定的：rm_town 有余量、rm_level17 超预算
   （17.6–18.8 ms > 16.67 ms ⇒ 该房必掉帧）。
4. **不是全游戏覆盖**：只测 rm_town（room 0）与 rm_level17（room 25）；Boss 房、
   粒子密集房、地图屏、菜单、序章动画帧都未测。
5. **MIUI 前台真 app 未验**：`#54` 的备注（presenter 自己的 logcat tag 在 MIUI 上不出现）
   依旧成立 —— 本次所有数字都来自 app 类在 javm64 里的真实执行 + 真实 GL，
   **不等于** Activity/SurfaceView 前台路径的实测（没有 SurfaceFlinger 帧计数交叉验证）。
6. **`nativeStep` 的内部分解未测**：只知 step 总量，逻辑 tick / 光栅化 / 光栅化命中的
   含量是推断（§5.2），没有计数器证据。
7. **热与频率未做受控实验**：测量期 thermal 45.7 ℃、`sugov_ext`，未绑核/未锁频；
   跨轮差异无法在外部进一步分解成 DVFS 与调度两部分。
8. **输入驱动的活动场景未成立**：见 §7.1，所以「活动」口径实际来自房间自带的动画/敌人活动。

## 7. 观测登记（不是缺陷结论；本线不改 crates/，交父代理判定）

### 7.1 存档交接后的 rm_level17：按住「右」只带来 26/300 变帧

- 事实：`level17` 场景 boot 里点掉序章后 IR checkpoint 已是 `room=25`（房间切换成功），
  但 checkpoint 的 `player=(416.0,494.0)` 与 rm_town 的出生点**完全相同**；
  `holdRight=1` 时 300 帧只有 26 帧变帧（自然活动是 100/300），且变帧节奏从
  「每 3 tick」变成不规则；引擎无 halt、无诊断。
- 两种可能未区分：(a) 玩家被恢复在 rm_town 的坐标上、在 25 房里正好贴住地形，
  于是"走路"没有位移；(b) 25 房的自然动画节律本身就是不规则的低频。
- 影响：本线的 fps 数字不依赖它（活动口径用自然活动）；但**输入驱动的"每次绘制都变"
  场景无法在当前壳里造出来**，这是本线的一条测量边界。
- 需要什么才能定性：引擎侧的玩家坐标/速度读数（生产侧仪表），或一次真实门链进 25 房
  （`crates/client/tests/full_playthrough.rs:241` 断言真门进来时的 pin 是 (128,204)，
  本壳的存档交接路径没有把它复现出来）——**是否算缺陷取决于「v2 存档交接是否应该
  把玩家放到目标房自己的 pin」这个产品问题**，本线只登记事实。

### 7.2 未变帧的 step 与变帧几乎相同：`#75` 第四片的光栅化缓存在这两房没见收益

- 事实（pass2 逐轮 p50）：rm_town `step(full)=11.44/11.24/10.29` vs `step(skip)=11.57/11.41/10.31`
  （差 −0.13 ~ −0.02 ms）；rm_level17 `16.54/16.60/16.65` vs `16.26/16.25/16.41`
  （差 +0.2 ~ +0.4 ms）。**差都在噪声内（<0.3 ms）**。
- 而 `#75` 记录：强制重画 4.32（town）/5.88（level17）ms，静止命中 0.017/0.079 ms ——
  相差 4 ms 级。若那两条房的"未变帧"命中了输入等价缓存，step 应当低约 4 ms。
- 结论（就时长而言）：**这两房的实时帧循环里，未变帧没有省下光栅化**；
  只有 present 被跳过（0.9 ms 级）。可能原因（未证实）：缓存键里有每 tick 变化的字段；
  或该路径在这两条房/这条调用路上没有被走到。确认需要命中/未命中计数器
  （生产侧仪表，不在本线所有权）。
- 价值：若真能把静止帧的光栅化整段省掉，rm_town 一帧可省 ≈4–6 ms（10.5 → 约 5 ms 级），
  也就是本线测到的最大单块余量。**本线只登记，不动 crates/**。

### 7.3 变帧节奏是严格 10 Hz

两房都是每 3 个 tick 变一次（900 帧恰好 300 变 600 不变），说明稳态画面里有稳定的
10 Hz 动画源。对"静止帧跳过"的任何后续评估，**必须用这种真实节律**，而不是人为的
"完全静止"假设（`GmPresent64` 那种不 step 的紧循环会给出 0/300 的人造静止，
与真机稳态不符）。

## 8. 复现

```sh
cd ~/cally-work/gmbench
sh fps_build_gmbench.sh                 # -> gmfps.dex（不动共享 gmbench.dex）
sh run_fps_endtoend.sh town    native 900 300 3 town-na      # 单配置 3 轮
FR=900 TAGSUF=-c3 sh fps_campaign.sh                          # 全 5 配置
awk -f fps_stats.awk work/raw/fps-town-na-native-r*.txt       # 逐轮百分位
awk -v POOL=1 -f fps_stats.awk work/raw/fps-town-na-native-r*.txt
```

产物：`work/logs/fps-<tag>-<mode>-r<N>.log`（含每轮 loadavg/top_cpu/STAT/PLACEBO/RECON/CPU）、
`work/raw/fps-<tag>-<mode>-r<N>.txt`（逐帧 `i step_ns blit_ns present_ns presented frame_ns
input_ns drain_ns`）。`DT_NS`/`TAP_EVERY`/`HOLD_RIGHT`/`BOOT_TAP` 可覆盖。

## 9. Issue #54 回写草稿（由父代理发 gh）

> 端到端帧率首次量化（javm64 无头壳、真 GPU，2026-10-16，方法/边界见
> reconstruction/contracts/device-fps.md）：
>
> - **java 腿（GlesPresenter 真类、真 GL）**：rm_town 85.5–93.7 fps（最好 95.9）、
>   rm_level17 55.1–60.3 fps（最好 60.9）；present 分量 0.81–1.15 ms、
>   blit（nativeBlitToIntArray）分量 0.44–0.51 ms。
> - **native(Rust) presenter 腿**：town 89.7–96.7、level17 56.8–60.5 fps，
>   与 java 腿同量级（差 <5%，两腿的瓶颈同为整帧光栅化）。
> - **预算结论**：rm_level17 变帧 17.6–18.8 ms/帧已越过 16.67 ms 预算，该房在
>   本机守不住 60 fps（不含 SF 合成/scanout/vsync 的握手开销，只会更低）。
> - **未验层依旧成立**：MIUI 上 presenter 自己的 logcat tag 不出现，设备侧仍只有
>   SurfaceFlinger 帧计数；壳内数字无 Activity/前台路径。后台不暂停音频的宿主
>   行为另见 host-lifecycle-native-probe.md 的真机侧待办。
>
> 证据：`work/raw/fps-*.txt` 逐帧表 + `work/logs/fps-*.log`（loadavg/top_cpu 归因：
> 同机编译负载可致 2.3× 轮间差，汇报值取 min-of-N）。
