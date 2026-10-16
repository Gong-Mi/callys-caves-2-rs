# CI 编译侧地板量化与方案评估（WL6，2026-10-16）

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

## 2. sccache：6/192 命中的净账未结

CI 每分片用 `RUSTC_WRAPPER=sccache` 跑 198 次请求，其中 192 次它自己声明
不可缓存（test 单元是编译+链接一体二进制，链接不可缓存；另 6 次 workspace
rlib 读命中，avg read 0.5–1.2 s）。**「包装器在不可服务请求上的开销 vs 6 次
读命中」从未被测量**。

- 方法已就绪：`scripts/ci_floor_sccache_ab.py`——本项目真实 ci-test 单元上的
  sccache 开/关 A/B（交替、min-of-3、打印 loadavg）。
- 若净账为负（大概率：deps 已由 rust-cache 恢复，workspace rlib 因 mtime
  新鲜度失效，6 次命中省不了编译），建议直接摘除 CI 的 sccache 步
  （Swatinem/rust-cache 不依赖它）。

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
3. **sccache 摘除**（§2，先测后摘）。
4. **archive 方案**（§3）：仅当要省 GitHub 计算量（并发队列压力）时上；墙钟不变好。

## 5. 风险与边界

- archive 方案的已知坑：`env!("CARGO_MANIFEST_DIR")` 硬编码绝对路径进测试二进制，
  run job 必须同路径 checkout，`--workspace-remap` 救不了 `env!()`。
- 本章全部数字来自单基线 run 与单台高负载开发机；方向性结论（archive 墙钟非收益、
  sccache 命中 6/192）可复现，绝对值需 CI 侧复测。
- mold 收益（#103：7–26 s/分片）已落地，不在本章重复。
