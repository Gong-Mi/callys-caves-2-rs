# GPU 命令后端：幅度 spike 结果与施工设计（WL9，2026-10-16）

结论先行：**GO**。spike 在真机真驱动（Mali-G720，ES 3.2，真 BufferQueue）上实测：
命令路径递交一帧 **0.116–0.228 ms**（含 swap 底线 0.078 ms）+ 命令生成 ~0.13 ms
（已知），上传 **64 KB vs 现 2.91 MB**——被替换掉的是 **8.2 ms/帧的整帧 CPU
软件光栅化**。rm_level17 端到端投影 **16.5 → ≈8.7–9.0 ms/帧（≈110 fps 上限）**，
逻辑 tick（≈8.3 ms 推断）成为新的墙。

## 1. Spike 方法

- 清单：`gpuspike_census.py` 直接读 game.droid 的真实 ROOM/OBJT/SPRT/TPAG 记录，
  产出 rm_level17（room 25）静态 draw 命令清单（806 quad，
  `work/gpuspike/gpuspike-commands-level17.txt` sha256 082d17f0…）。
- harness：`Gpuspike64.java`（gpuspike-v1，私有 gpuspike.dex sha256
  62888e01…）+ `run_gpuspike.sh`；atlas = 4 张真实 TPAG 页（共 29.5 MB RGBA，
  解码 285–399 ms、上传 26–40 ms，均一次性）。
- 腿：legacy（整帧上传+1 quad+swap）/ swaponly（底线）/ cmd806（806 quad 按页
  分桶 2 draw）/ cmdview（71 quad 视口剔除）/ cmd806nb（806 draw 不分桶）/
  cmd806f32（float[] 顶点 staging）。min-of-4 轮内 p50，loadavg 40–41.5。

## 2. A/B 数字（递交+swap 腿，ms/帧）

| 腿 | 默认（不 finish） | 严格（glFinish） | 上传/帧 |
| --- | --- | --- | --- |
| legacy 整帧 | 0.307 | 0.963 | 2,908,160 B |
| swaponly 底线 | 0.078 | 0.262 | 0 |
| cmd806（2 draw） | 0.228 | 0.928 | 64,480 B |
| cmdview（71 quad） | 0.116 | 0.626 | 5,680 B |
| cmd806nb（806 draw） | 0.585 | 1.791 | 64,480 B |
| cmd806f32（float[]） | 0.163 | 0.975 | 103,168 B |

安慰剂：p1 采样 0 ns；p2 drain 307/385 ns；p3 顶点写 direct ByteBuffer
124,923/132,616 ns；p4 写 float[] 12,077/12,923 ns（**10× 差 ⇒ 顶点 staging
必须用 float[]**）；p5 FNV-1a over 64,480 B 524,307/559,308 ns（⇒ 静止帧跳过
不能对顶点哈希）。

校准边界：legacy 腿 0.307 ms 低于 device-fps 契约的 present 分量 1.02 ms——
测量语境差（背靠背递交 vs 16 ms step 后递交），**不是回归**。

## 3. 资产事实（实测，非推断）

- rm_level17 = room 25：2048×1280、1426 摆放、**0 tile**（tile 只在 rm_level1，
  与 asset-record-layouts.md 一致）；1424 个可解析 sprite quad 只用 TPAG
  页 1(46)+页 3(1378)；15 种 sprite（spr_set1wall 702 / boulder 343 / path 333）。
- 该房 view rect 448×252，**剔除后屏内只有 71 个静态 quad，而渲染器每帧发射
  806 条命令——全程无视口剔除，~90% 命令在屏外**（rm_town 157/33、rm_level2
  700/74、rm_level16 686/101，同规律）。
  **WL12 更正（2026-10-16 实测）**：「切片②是与 GPU 后端无关的 CPU 收益」的
  推断**不成立**——软光栅的 blit 在像素循环前已按同一盒 clip 早退，屏外命令
  本来就不写像素；命令侧剔除省下的只有分发（隔离探针：guard on 64.0 ns/命令
  vs off 71.9 ns/命令，省 7.9 ns/命令；813.5 命令/帧 ⇒ ≈6.4 µs/帧 ≈
  0.11–0.13% 的 5.7–6.2 ms 帧，ABBA+安慰剂实测，配对 CPU 差值 4/4 为负）。
  真实房间 A/B 不可分辨（本机噪声 ≫ 效应）。该守卫的真实价值在**命令腿**
  （§2 实测 0.112 ms/帧 @735 quad = 152 ns/quad，是光栅侧分发的 19×）——
  即它是 GPU 后端的前置必要件，不是独立的 CPU 优化。
- 画家算法约束：按 depth 排序后同页连续 run = 55（整层）/ 9（屏内集）——
  **不能按页全排序**（像素序冲突），只能批连续 run；真实 draw 数落在
  cmd806(2) 与 cmd806nb(806) 之间。
- 字体：真实资产走 FONT chunk glyph 页（与 TPAG 同页集）；FONT_5X7 只是
  lookup 失败 fallback——**设计按真实资产做，不引入 5×7 字模**（否则像素不同）。

## 4. 施工切片（各自独立可验）

1. **命令模型/发射**：draw command → GPU command list，保留软件光栅化；
   等价门 = `draw_hash` 每帧 sha256 不变。
2. **命令侧视口剔除**：✅ 已施工（WL12，2026-10-16）。`parts/view_cull.rs` 守卫
   在 `draw_ir_sprite` 入口（解析页图集之前）拒绝视口外交命令；传 `None` 逐位
   复现旧路径。等价门：draw_hash 400 帧逐字节相等（隔离基线 worktree 对照）。
   实测收益见 §3 更正（≈0.11–0.13% 帧时间；真实价值在命令腿，是 GPU 后端的
   前置件）。tile/background/healthbar/particle 队列不加守卫（其 blit 已
   clip 早退，加守卫只多付几何计算）；文字队列未剔除（需 glyph 步进量才能
   保守打包）。
3. **纹理集懒加载/驻留**：✅ 方案验证完成（WL15，2026-10-16；atlas spike 落
   `~/cally-work/gmbench/atlspike*`，契约只记结论）。
   - **全 114 房页引用普查**：按引用页加载可行；常驻全集 28.13 MB，单房页集
     最大 3 页。
   - **trace A**（114 房×3 轮=342 次切换实测）：全预载稳态 min 0.646 ms；
     pin_lru1（cap≥3）命中 99.1%、仅 6 次冷载（冷载 p50 50 ms）、峰值 24.1 MB、
     342 帧中 6 帧超 16.67 ms 预算、684 稳态帧 0 超；**cap<单房页集（3）的
     LRU 不可行**（lru1/lru2 cap 溢出 366/42；lru3 有 12 次冷载含 page1 重载
     p50 151 ms）。
   - **EGL 丢失恢复交互**（#97）：驻留 28.13 MB 时上传-only 12–19 ms vs
     解码+上传 191–298 ms；驻留 {1,3} 时 8.7 ms vs 126.7 ms；GL 对象重建
     9.6–19.5 ms ⇒ 恢复时应按驻留集重传而非重解码。
   - 更正：WL9「页 1+3 = 16.9 MB」实测为 **16.125 MB**（2048²×4 + 128×256×4），
     以实测为准。
   - 未跑（如实登记）：trace B（地图往返）、ref806 对照腿；不影响策略结论。
4. **GPU 后端**：命令绘制 + `glReadPixels` 差分等价门（对 CPU 光栅逐帧对拍）。
5. **skip 语义**：换成 RasterInputs 字段全等（已存在，~0.1 ms），顶点不哈希（§2 p5）。
6. **EGL 丢失恢复**（#97 语义在命令后端下）：门树清零 + 页纹理重传。
7. **运行时回退开关**：✅ 开关机制已施工（WL18，2026-10-16）；**命令后端接入待切片①/④**。
   - **单一选择点**：`draw_frame` / `draw_frame_cached` → `draw_frame_inner`
     （`crates/client/src/lib.rs`）解析后端一次并 dispatch。软件臂就是把原 `draw_frame_inner`
     全体改名为 `draw_frame_software`（函数体零改动），所以这个 match 是切片⑦在默认路径上的
     唯一调度改动。父代理以 Git blob 校验：改名前后从软件合成函数起的源码尾部逐字节一致。
   - **模块**：`crates/client/src/parts/render_backend.rs`（`include!` 进 lib.rs，与
     `parts/view_cull.rs` 同款）。`RenderBackend = Software | GpuCommands`。
     优先级：`set_render_backend(Some(..))`（线程作用域覆盖；进程内 A/B 与运行时回退的杠杆）
     > `CALLY_RENDER_BACKEND`（进程级，首次解析后缓存；大小写不敏感、裁剪空白、空值=未设；
     别名 `cpu`/`gpu`）> `BUILD_DEFAULT_BACKEND = Software`。
     未识别取值是**错误**而不是静默默认值：操作员点名了后端，开关不能假装选了别的。
   - **未接线后端 = typed refusal（失败关闭）**：帧入口以 `BackendRefusal::NotWired` 为 panic
     payload 拒绝合成，同一条诊断先写 stderr（默认 panic hook 对非 `&str` payload 只打印
     `Box<dyn Any>`，不先写就丢诊断）。**不静默渲染软件帧**：静默回退会让将来的 A/B 变成
     software-vs-software 并把「命令后端没有差别」当结论报出来——这正是本切片最该防的假证据。
     `render_backend_status()` 是同一判定的非 panic 就绪探测，供 host 起循环前查询。
   - **A/B 路径**：帧入口逐帧计时并按后端归档（`BackendFrameCost`：thread-local `Cell`，
     无分配、无共享原子，默认关闭；`CALLY_RENDER_COST=1` 或 `set_frame_cost_recording(true)` 打开）。
     命中 `RasterInputs` 缓存的帧样本≈0，读表时场景须一致（perf 测试走非缓存帧）。
     切片④接入后，同场景 A/B = **一行 env 之差**：`CALLY_RENDER_BACKEND=gpu-commands` 跑
     `crates/client/tests/render_backend_switch_perf.rs` 即成 A/B（该文件无需改动），
     该变量未设时同一文件退化为 A/A。
   - **等价门（默认路径逐字节不变）**：7394f1f 基线 release draw_hash 400 帧
     `sha256 2b24681a656763633945375a55a47ec954c4556748dd9b2b8ed5b50817aafc65`
     = 改后 release 同名文件 = 套件内 ci-test profile 逐帧 hash 拼接（三者相同，跨 profile 亦相同）。
     `tests/render_backend_switch.rs` 对同样 400 帧（40 序幕 + 40 交接 + 8 房×40）做双源
     A/A 逐字节比较，并按 draw_hash 同格式打印逐帧 hash，可直接 diff 复现该门。
   - **A/A 证据（实测，本机 ci-test profile，3 次运行）**：① 开关自身成本：缓存后的解析
     **18.3／44.8／47.9 ns/次**（三次运行）vs 每帧裸 `std::env::var` **301–517 ns/次**
     ⇒ 解析不是每帧 getenv，占 10 ms 帧的 0.0007% 以下。② 同后端双源 A/A 分块测量
     （8 房×200 帧×4 ABBA 对=32 对，A=显式覆盖 software，B=构建默认 software）：进程 CPU 时间
     两腿中位数 **A 10.150 = B 10.150 ms/帧**，配对 Δcpu 中位数 **+0.000 ms/帧**、正负
     旧报告正负 **15/17**（旧程序把零差也计入“负”，该符号数不作证据），最差单对 |Δ| 2.45 ms，本机同轮 A/A 安慰剂（leg B 自身两半）
     最差 **1.000 ms**。墙钟在分块 min-of-N 下 A/A 安慰剂 0.03–6.7 ms/帧、Δ/floor 高达 44×
     ⇒ 本机墙钟不可用于分辨该量级（这也是判据取 CPU 时间、墙钟只登记不断言的原因）。
     上述①是旧候选的单次墙钟开销估计，并非“零开销”证明；②为同次观测，不能推出普遍帧级上界。
     CPU 读数来自 `/proc/self/stat` 的 tick 计时；本轮未取得高分辨率 CPU 置信区间，不能据此声称性能等价。
     父代理已修正两处测量门：未接线后端必须非零退出；真实 GPU A/B 不再受 A/A 零差断言约束。
     原始日志 `~/cally-work/wl18/perf3.log`（含逐房表）／`perf2.log`／`perf.log`。
   - **Android 平台边界（本轮未跑前台 app）**：app 进程由 zygote fork，shell/Termux 设的环境变量
     **不进入** app 进程 ⇒ 设备侧 A/B 走 `set_render_backend`（或切片④在 host 侧加系统属性读取，
     那需要 android-build/ 配合，不在本切片）。env 杠杆对 host／桌面／headless／操作员直接启动的
     进程有效（已用 release example 实测：`CALLY_RENDER_BACKEND=gpu-commands` → exit 101 +
     完整诊断；`=metal` → exit 101 + 可接受取值清单）。

## 5. 风险清单

- 深度序 vs 分桶的像素序冲突（只能批 run，§3）。
- 软件采样规则（增量除法 / alpha≥16 / round）与 GL_NEAREST+blend 的逐像素
  对齐——等价门必须逐帧对拍到换相。
- 旋转 / fog / 缩放路径的正确性。
- GL_NEAREST / CLAMP_TO_EDGE 约束（像素艺术缩放不得出现设备默认过滤）。
- ImageReader 呈现链不变；仍无 SurfaceFlinger/scanout 证据。
- 顶点 staging 必须 float[]（§2 p4）。

## 6. 未验层

spike 不追像素等价（任务边界）；命令路径的正确性以切片④的 glReadPixels
对拍门为入口。端到端收益投影（16.5→8.7–9.0 ms）是「实测命令腿 + 已知分量」
的合成，非端到端实测。

切片⑦（开关，WL18）明确**不含**：命令后端本身（①/④）；**自动**回退策略——回退需要失败信号，
那是切片④的错误路径，本切片只给杠杆（`set_render_backend`）；设备侧 env 传递（zygote fork，
见 §4.7，设备 A/B 走覆盖 API）；A/B 的**真机 GPU 侧**数字（需④）。按本机噪声（A/A 安慰剂
2–9 ms/帧），命令后端接入后的真机 A/B 也应主要依据分层计数与 GPU 侧计时，而非本机的墙钟块差。
父代理已同步 `SOURCE_LAYOUT.md` 的后端开关入口。命令后端仍未接线；以上不表示 GPU 渲染或自动回退已经完成。
