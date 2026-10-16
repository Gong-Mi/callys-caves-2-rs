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
3. **纹理集懒加载/驻留**：页 1+3 = 16.9 MB vs 现 2.9 MB 帧缓冲；按引用页加载。
4. **GPU 后端**：命令绘制 + `glReadPixels` 差分等价门（对 CPU 光栅逐帧对拍）。
5. **skip 语义**：换成 RasterInputs 字段全等（已存在，~0.1 ms），顶点不哈希（§2 p5）。
6. **EGL 丢失恢复**（#97 语义在命令后端下）：门树清零 + 页纹理重传。
7. **运行时回退开关**：命令后端 ↔ 软件光栅化，A/B 可用。

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
