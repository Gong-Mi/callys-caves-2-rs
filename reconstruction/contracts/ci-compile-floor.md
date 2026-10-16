# CI 编译侧地板量化与方案评估（WL6，2026-10-16；§2 的 sccache 净账由 WL11 同日实测结清）

基线 run：`38843588741`（main@871f206，4 分片全绿）。口径与数字由
`scripts/ci_floor_baseline.py` 从 run 日志机读（产物 `baseline.md` 留
`~/.hermes/cache/scratch/wl6/`，不入库）。

## 1. 基线（每 run）

| 指标 | 值 |
| --- | --- |
| 关键路径（最慢 job 墙钟） | **505 s** |
| 编译+链接合计（4 分片） | **961 s** |
| 执行合计（nextest Summary） | 258 s |
| 编译+链接 分布 | shard1 298 s / shard2 188 s / shard3 281 s / shard4 194 s |
| 每分片构建 | 全部 168 个测试二进制（`--partition` 只筛跑不筛编）⇒ 每 run 4×168 次编译+链接 |
| sccache 请求/分片 | 198（命中 6 / 不可缓存 192，其中 crate-type 原因 188） |

链接只占单单元墙钟 3–6%（#103 已量化并接入 mold）；**地板在编译侧**。

## 2. sccache：6/192 命中的净账已结——**净账为正，保留**（WL11 实测，2026-10-16）

CI 每分片 198 次请求里，192 次 sccache 自己声明不可缓存（`crate-type` 188 +
`missing input` 2 + 其他 2：test 单元是编译+链接一体的二进制，链接不可缓存），
6 次可缓存请求全部读命中（avg read 0.5–1.2 s）。净账 = 那 6 次命中省下的编译
− 包装器在 192 次不可服务请求上的开销。**本次实测结论：正，保留 CI 的 sccache
步，`.github/workflows/ci.yml` 不改。**

方法：`scripts/ci_floor_sccache_ab.py`——本机 aarch64 Termux、`ci-test` profile、
真实单元上的 sccache 开/关交替 A/B、min-of-N、每轮打印 loadavg、逐轮比对产物
sha256。下表所有运行 exit=0，且两臂产物逐轮同哈希（等价性先过关，再谈时钟）。
本次产物（6 个单元的 A/B 报告 + JSON + 端到端交叉校验）留
`~/.hermes/cache/scratch/wl11/`，不入库（同 WL6 惯例）。

**方法此前跑不起来，本次修好（工具缺陷，与 CI 无关）**：旧脚本只重放 `rustc`
命令行，缺 cargo 按单元注入的编译期环境，6 次运行全部 exit=1、每次约 1 s 的
非运行——

    error: environment variable `CARGO_MANIFEST_DIR` not defined at compile time

（本项目 IR 测试用 `env!("CARGO_MANIFEST_DIR")` 定位仓库根。）现在 argv 与 env
都从一次真实 cargo 调用经 `RUSTC_WRAPPER` 探针捕获（167 个变量）。顺带修了命中
计数：sccache 0.18 的 JSON 把 `cache_hits`/`cache_misses` 嵌成 `{"counts":{...}}`，
旧代码按标量取、被 isinstance 守卫静默丢成 0——"6 次命中"这类归因当时根本印不
出来。

### 2.1 开销侧：192 次不可缓存请求（test 单元）

| 单元 | 测试源 | bare wall min/中位 | sccache wall min/中位 | Δmin | bare CPU min | sccache CPU min |
| --- | --- | --- | --- | --- | --- | --- |
| code_vm | 1.2 KB | 0.871 / 0.876 | 0.881 / 0.914 | +0.010 | 1.542 | 1.526 |
| lloyd_tutorial_ir | 17.6 KB | 4.858 / 5.099 | 4.645 / 5.002 | −0.212 | 17.619 | 17.242 |
| roomcc_cards_ir | 39.2 KB | 3.480 / 3.757 | 3.602 / 3.806 | +0.123 | 10.934 | 11.588 |
| sprite_and_tile_layout_ir | 66.3 KB | 7.193 / 7.686 | 5.840 / 6.178 | −1.353 | 14.273 | 13.944 |

（每单元单次编译 0.9–7.2 s 墙钟；逐轮 loadavg 22–29，见下列各次的载体日志。）

- **无规模相关性**：1.2 KB 与 66 KB 的 Δ 符号随机翻转、量级同落在噪声里 ⇒
  sccache 在不可缓存路径上不做与输入规模成正比的工作。每次包裹调用都被它归因
  `not_cached[crate-type]`（逐轮 stats delta 可见），与 CI 的 188 同类。
- 最紧的一组是 code_vm（0.9 s 量级编译，12 轮、loadavg 39–48）：
  bare min 0.967 s（CPU 1.666 s）vs sccache min 0.948 s（CPU 1.686 s）
  ⇒ **墙钟 −0.018 s，CPU +0.020 s**。
- 结论：**每请求开销 ≤ 0.1 s**（点估计 0.02–0.08 s；主项是进程 spawn + 一次
  socket 往返，不是编译）⇒ 192 次 **≤ 19 s/分片**，中心估计 ≲ 8 s。

### 2.2 收益侧：6 次命中（workspace rlib）

| 单元 | bare wall min（CPU min） | sccache 读命中 wall min（CPU min） | 省 |
| --- | --- | --- | --- |
| callys-core rlib | 12.687 s（32.835 s） | 0.481 s（**0.009 s**） | **12.2 s** |
| callys-asset rlib | 2.815 s（3.418 s） | 0.298 s（**0.008 s**） | **2.5 s** |

- 命中时子进程 CPU ≈ 0（0.008–0.010 s）：编译器确实没跑，不是"跑了但快"。
  逐轮 stats delta 为 `requests_executed 1 / cache_hits 1 / cache_misses 0`。
- ⇒ 6 次命中 = **14.5–76 s/分片**（下界全按 asset 级 2.4 s×6，上界全按 core 级
  12.7 s×6）。
- 命中单元在依赖图头部（asset → core → 168 个 test 二进制都要等它）⇒ 省下的是
  **关键路径上的时间**，不是能被并行吃掉的时间。
- 归因属推断（CI 日志里只有"6 次请求 / 6 次命中"这个总数）：6 ≈ 3 个 workspace
  crate × release/ci-test 两个 profile。依据两条：rust-cache 不缓存 workspace
  crate（其文档明说只缓存 dependency crate，§4 的 `cache-workspace-crates`
  实测也无效），而基线里 release 的 `Build Workspace` 步骤只有 3–6 s——装不下
  任何一次实测 2.7–12.7 s 的 workspace rlib 编译。按此组成（每个 profile 至少
  asset/core/client 各一次）收益下界升到 ≥ 55 s/分片。

### 2.3 端到端交叉校验（12 个真实单元、真 cargo 并行）——**记录为不可用，不进判定**

（产物 `~/.hermes/cache/scratch/wl11/phase2*.md`；12 个 test 目标、每轮前 touch 全部
源文件、两臂交替，`-j8` 3 轮 + `-j2` 对照 2 轮。）

- 有用的输出一：用 `-v` 核对两臂编译的单元集合**完全相同**（都是那 12 个 test 单元，
  都不含 workspace rlib）⇒ 不存在"某臂多干活"的新鲜度差异。
- 有用的输出二：进程树核对（`/proc`）——不可缓存请求下真正的编译器是 **sccache 客户端
  的子进程**（`sccache rustc …` → `.cargo/bin/rustc …`），所以 §2.1/§2.2 的 CPU 口径
  确实覆盖编译器本身；同时看到 sccache 守护进程是**全机共享**的。
- 不可用的部分：墙钟一律偏向 sccache（`-j8` 33.7/30.0/34.4 vs 41.7/37.3/41.4 s；
  `-j2` 54.8/46.0 vs 75.9/67.2 s），而 CPU 时同、时反（`-j8` 154.4 vs 153.7 s；
  `-j2` +30 s 偏向 sccache）。**不可缓存请求不可能因包装器而变快**，两个指标至少在
  一处被污染：同一守护进程在这些窗口里正服务别的工作线（一轮 delta 里出现 31 次
  cache_misses/cache_writes 与 `not_cached[-o]`，那不是本工作区的 Rust 单元）。
  `-j2` 那 +30 s CPU（同单元集）**未查明原因，不作为收益，也不改动 §2.1 的结论**。
- ⇒ 端到端口径在本机（8 核、loadavg 28–51、多工作线并发）分辨不了 ≤0.1 s/请求，
  判定只用 §2.1/§2.2 的定命令重放：那里每臂是**同一条 argv**、每轮产物同哈希、
  每次恰好 1 个请求、CPU 与墙钟方向一致。
- 另：CI 用 GHA 后端，但不可缓存请求在查缓存**之前**就被判掉了（不碰网络）
  ⇒ 本机磁盘模式的每请求开销对 CI 同样适用；命中侧的读延迟在 CI 是 0.5–1.2 s
  （§2.2 已按 CI 数字记）。

### 2.4 判定与处置

| 口径 | 收益（6 命中） | 开销（192 请求） | 净账 |
| --- | --- | --- | --- |
| 中心 | 39–76 s/分片 | ≲8 s/分片 | **+31–68 s/分片** |
| 最保守（收益下界 × 开销上界） | 14.5 s/分片 | 19 s/分片 | −4.5 s/分片（勉强持平） |

⇒ **保留 sccache**。理由与边界：

1. 中心情形净赚 30–68 s/分片，且省下的是关键路径时间（§2.2）。
2. 唯一能翻成负的是"把收益下界（6 次全按最小 rlib）与开销上界（0.1 s/请求，
   比实测紧值高 5–20×）配在一起"的极端组合；两者互不相容——0.1 s/请求意味着
   192 次都被进程/守护进程成本支配，而实测紧值是 +0.010 s 墙钟 / +0.020 s CPU。
3. 摘除的代价不对称：收益侧那 6 次编译会全部回来（还会把 release 腿的 workspace
   rlib 一起带回来，§2.2 归因），而能省回的只是 ≲8 s 的包装开销。
4. 未计入成本侧的两项：`Set up sccache` 步（基线 1 s）与 miss 时的 GHA 写
   （基线 0 miss / 0 write；本 run 不存在，但 Cargo.lock 或源改动会触发，会与
   rust-cache 共享 10 GB 预算，属另一维度的取舍）。

若将来仍要摘（本次不执行），改动点是：去掉 job `env` 的 `SCCACHE_GHA_ENABLED`
与 `RUSTC_WRAPPER`，以及 `Set up sccache` 步。rust-cache 不依赖 sccache（其文档：
只缓存 dependency crate，并自己设 `CARGO_INCREMENTAL=0`）；但 `RUSTC_WRAPPER`
落在 rust-cache `env-vars` 默认前缀 `RUST` 的哈希里，摘除会换 cacheKey
（restore-keys 仍能恢复上一版 target，代价与 ci.yml 里 mold 那条注记同类）。

## 3. nextest archive：可行，但墙钟非收益项（实测）

本地实测（`~/.hermes/cache/scratch/wl6/archive_verify.log`，loadavg 37–44、
同机多工作线并行，取方向不取绝对值）：

- 构建一次 → `cargo nextest archive`：399 MB（zstd 压缩后），命令形态验证通过；
  `run --archive-file` 从归档跑 shard 1/4：**254/254 passed**，与直跑同一 Summary。
- **执行侧墙钟**：shard1 直跑 128 s vs 归档 168 s（+31%）；shard4 59 s vs 67 s
  （+14%）——解压+落盘开销恒在。
- 结论：archive 把 4×168 次重复编译+链接降为 1×168（**计算量收益**：3 次冗余
  rust-cache 恢复与 sccache 开销消失），但用 399 MB 产物传输与 +30~60 s 恢复
  带宽换，**墙钟口径小幅变差**。真正能同时赢墙钟与计算量的只有
  「ci-test 二进制真正进缓存」——而链接单元本质上不可缓存，故等价表述是
  「让 workspace rlib 的新鲜度判定生效」。

## 4. 真正的杠杆候选（未施工，按预期收益排序）

1. **workspace rlib 新鲜度修复**（直击 961 s 的大头）：rust-cache 的
   `cache-workspace-crates` 实测无效——checkout 源文件 mtime 恒新于恢复产物，
   cargo 新鲜度判定失效。出路：nightly `-Z checksum-freshness`（让内容哈希代替
   mtime），或 mtime 启发式（恢复后 touch 对齐）。收益上限 = 每分片省掉 workspace
   crate 重编（_deps 已由缓存恢复，剩余大头是 117 个 core test leaf 的 crate 编译
   本身——注意 leaf 编译不可缓存，真实收益需 `--timings` 分布定量）。
2. **--timings 分布定量**：在 CI build job（archive 方案的单构建 job，或现状任一分片）
   加 `cargo build --timings`，把「rustc 启动/元数据/leaf codegen」的分布落地，
   再决定 debug=1 / codegen-units / 分片策略。
3. ~~**sccache 摘除**（§2，先测后摘）~~ —— **已结（§2，WL11 实测 2026-10-16）**：
   净账为正 ⇒ 保留。
4. **archive 方案**（§3）：仅当要省 GitHub 计算量（并发队列压力）时上；墙钟不变好。

## 5. 风险与边界

- archive 方案的已知坑：`env!("CARGO_MANIFEST_DIR")` 硬编码绝对路径进测试二进制，
  run job 必须同路径 checkout，`--workspace-remap` 救不了 `env!()`。
- 本章全部数字来自单基线 run 与单台高负载开发机；方向性结论（archive 墙钟非收益、
  sccache 命中 6/192）可复现，绝对值需 CI 侧复测。
- §2 的 sccache 净账同属本机（aarch64 Termux/8 核）数据，且是在**同机多工作线并发**
  下取的：逐轮 loadavg 22–51，run 期间另有工作线的 cargo 构建在跑（sccache stats
  delta 里出现的非本单元请求即其痕迹）。因此 §2 的绝对值按"方向 + 数量级"读，
  比值（每请求 spawn 级开销 vs 每次命中一次真实 rlib 编译）才是判定依据；
  CI 侧（x86_64/4 核）的复测仍缺。
- mold 收益（#103：7–26 s/分片）已落地，不在本章重复。
