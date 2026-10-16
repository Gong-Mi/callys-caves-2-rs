# CI 链接器换 mold（176 个链接单元地板的量化与接入）

本契约覆盖 `.github/workflows/ci.yml` 宿主腿的链接步：把 x86_64 CI runner 上的
链接器从 `cc` 默认（GNU ld / bfd）换成 mold，并把"链接不可缓存"这条既定杠杆
量化到底。**结论先行：链接器确实快约 2 倍，但 3–4.5 min/shard 的地板由编译
主导、不由链接主导；mold 的收益是 7–26 s/分片（≈最慢腿 431 s 的 2–6%），不是
分钟级。**

## 一、基线（口径与数字都来自真实 run）

基线 run：`38843588741`（main，`head_sha=871f206`，即本线基线 origin/main，
2026-10-16T03:03:31Z，4 分片全绿）。

口径：`Run Tests (shard N/4)` 步内部两件事——
`cargo nextest run …` 打印的 ``Finished `ci-test` profile … in Xm Ys`` 是
**编译+链接**结束点；nextest 的 ``Starting N tests across M binaries`` 与
``Summary [ Zs]`` 是**执行**起止点。

| step（Run Tests shard N/4） | 编译+链接 | 执行 | 步总计 | tests / binaries |
| --- | --- | --- | --- | --- |
| shard 1/4 | 299 s（4m58s） | 132 s | 431 s | 254 / **168** |
| shard 2/4 | 188 s（3m08s） | 51 s | 240 s | 188 / **168** |
| shard 3/4 | 281 s（4m41s） | 50 s | 331 s | 152 / **168** |
| shard 4/4 | 195 s（3m14s） | 24 s | 219 s | 113 / **168** |

两个结构性事实：

1. **每个分片都构建全部 168 个测试二进制**：`--partition count:N/4` 只筛"跑
   哪些测试"，不筛"编哪些二进制"（4 个分片的 `Starting … across 168 binaries`
   全一致）。所以每 run 实际发生 4×168 = 672 次链接，brief 里的"176 个链接
   单元"是去重后的单元数（cargo metadata 实测：165 个 test target = core 117 +
   client 45 + asset 3，再加 lib/bin 单元）。
2. 编译+链接合计 963 s、执行合计 258 s。**地板在编译侧**（详见第三节）。

## 二、本地可行性：链接器 A/B/C（真实测量）

环境：Termux/Android aarch64（8 核，**同一台机上还并行跑着 4 条工作线，
loadavg 20–24**，故同时记墙钟与子进程 CPU 时间）。

- `pkg install mold` → `mold 3.0.0 (compatible with GNU ld)`；`/usr/bin/ld.mold`
  符号链接存在；`clang -fuse-ld=mold` 能力探测通过（`int main` 探针链接并运行
  exit=42 符合预期）。
- 方法：从 `cargo test --no-run --profile ci-test -v` 的日志里取出**该单元真实的
  rustc 命令行**，用一个计时 linker wrapper 顶到 `-C linker=` 位置，wrapper 只把
  `-fuse-ld=<臂>` 追加给真 clang，并只记录那一次驱动+链接器的毫秒数。三臂交替
  （每轮正序/反序，ABBA），每臂 3–4 次，取 min 与中位。

| 单元（profile ci-test，debug=1） | 产物 | lld | bfd | mold | mold/bfd |
| --- | --- | --- | --- | --- | --- |
| `ballistics_closure_ir`（core） | 8.68 MB | 131 / 170 ms | 236 / 246 ms | **104 / 119 ms** | 2.07× |
| `sprite_and_tile_layout_ir`（core） | 8.84 MB | 150 / 260 ms | 237 / 271 ms | **120 / 139 ms** | 1.95× |
| `full_playthrough`（client） | 24.2 MB | 206 / 210 ms | 456 / 476 ms | **140 / 175 ms** | 2.72× |
| `room_views`（asset） | 2.34 MB | 145 / 156 ms | 174 / 186 ms | **108 / 131 ms** | 1.42× |

（表内为 min / 中位，单位 ms，墙钟。）

**同一批测量里，整条 rustc 调用（含 LLVM codegen）三臂之间没有可分辨差异**
（例如 `full_playthrough`：lld 4.53/4.98 s、bfd 5.42/5.55 s、mold 5.02/5.25 s 墙
钟）。也就是说：链接步只占单单元墙钟的 **3–6%**，其余是 rustc 启动 + 元数据 +
leaf crate codegen。CI 侧每单元约 1.78 s（299 s / 168）也是同一结构——所以
换链接器能省的只有那 3–6% 里的链接部分。

为什么基线定成 bfd 而不是 lld：`rustc -Z unstable-options --print
target-spec-json --target x86_64-unknown-linux-gnu` 给出 `"linker-flavor":
"gnu-cc"` 且**没有** `linker` 覆盖项 → rustc 用的是 `cc` 驱动；Ubuntu runner 的
`cc` 是 gcc，落到 binutils 的 GNU ld（bfd）。为了不让结论依赖"runner 上 cc 到底
是谁"，上表同时给 mold vs bfd 与 mold vs lld 两个比值。

## 三、预期量化口径（本线不 push，由父代理在 CI 复测）

- 基线 run：`38843588741`（main@871f206）。
- 对比 step：`test-and-build (1) / Run Tests (shard 1/4)`（最慢腿，431 s）与
  四个分片的 `Run Tests (shard N/4)` 全体；同时看步内 cargo 的
  ``Finished `ci-test` profile … in`` 与 nextest `Summary [Zs]` 两个数字。
- 预期差值（按上表每单元差值 × 168 单元/分片）：
  - vs bfd（runner 真实基线）：0.13–0.16 s/单元 → **≈ 22–27 s/分片**
  - vs lld（保守下界）：0.04–0.06 s/单元 → **≈ 7–10 s/分片**
  - 落到整条 run（≈最慢腿）：**-7 ~ -26 s，即 2–6%**。
- 采样覆盖 core（2 个，含最大源文件 `sprite_and_tile_layout_ir.rs`）、client
  （最大产物 24 MB）、asset，共 4 个单元；保守起见按"典型单元"外推，未按
  45 个 client 单元的更大链接时间加权，故上界取 27 s。
- 新自检会在 `GITHUB_STEP_SUMMARY` 里写下实际链接器版本（见第四节），
  量化时先看这一行确认换到了 mold，再读步耗时。

## 四、改动点

| 文件 | 位置 | 改动 |
| --- | --- | --- |
| `.cargo/config.toml`（新建） | `[target.x86_64-unknown-linux-gnu] rustflags = ["-C","link-arg=-fuse-ld=mold"]` | 只对宿主三元组生效的链接器选择；驱动保持工具链默认 `cc` |
| `.github/workflows/ci.yml` | `Install dependencies` 步 | apt 增加 `mold`（noble：2.30.0+dfsg-1build1，universe） |
| 同上 | 新增 `Verify the host linker driver resolves mold`（apt 之后，`if: code`） | 打印 `mold --version` 并用 `cc -fuse-ld=mold` 链接一个 C 探针并运行——mold 不可解析时在这里当场红，而不是在 cargo 里出一个看不懂的链接错误 |
| 同上 | 新增 `Prove the test binaries were linked by mold`（测试步之后，`if: code`） | 对 `target/ci-test/deps/font_chunk-*` 断言 mold 的版本戳（见下） |
| 同上 | `Detect change scope` 的 `code` 过滤 | 增加 `.cargo/**`：链接器配置变更是"代码"，不能落进 docs-only 跳过构建 |
| 同上 | `Cache cargo artifacts` 步注释 | 写明 rust-cache 键构成与一次性指纹失效 |

mold 会把版本号写进产物（实测：`mold 3.0.0 (compatible with GNU ld)`；
lld 写 `LLD 21.1.8`，bfd 那支没有可匹配串），所以自检是**对实际二进制取观测**，
不是复述配置：静默回退到 bfd/lld 会红。该断言已做伪证（本地 RED/GREEN，
`font_chunk` 就是默认 lld 链接的那支）：

- lld 链接的 `font_chunk-861dd8d98c3c7a2e` → 退出 1，stderr 报 `LLD 21.1.8`；
- mold 链接的单元 → 退出 0，输出 `linked by: mold 3.0.0 (compatible with GNU ld)`；
- 二进制不存在 → 退出 1（不假装 PASS）。

`[target.x86_64-unknown-linux-gnu]` 只对宿主三元组生效这一点也做了双向验证：
`cargo build --target x86_64-unknown-linux-gnu -vv` 的命令行里出现
`-C link-arg=-fuse-ld=mold`（本机缺 x86_64 std，随后按预期 `error[E0463]`）；
本机默认三元组（aarch64-linux-android，与 android/apk 腿同三元组）构建的
rustc 命令行里 `fuse-ld=mold` 出现 **0 次**。

## 五、风险与回退

1. **本机 Linux 开发机没有 mold**（最直接的副作用）：这份 rustflags 对所有
   x86_64-unknown-linux-gnu 构建生效，缺 mold 时链接会失败。回退：删除
   `.cargo/config.toml` 的 `[target.x86_64-unknown-linux-gnu]` 段（CI 的
   `mold` 安装与两个自检步可留着，自检会红——要一起回退就把 apt 参数与两个
   步骤一并去掉）。带注释写明"需要 `apt-get install -y mold`"。
2. **rust-cache**：`add-rust-environment-hash-key` 默认为 true，所以
   `cacheKey` 会吃进 `.cargo/config.toml` 的哈希与 `RUST*` 环境变量；
   但 `restoreKey`（前缀 + rustc 版本/env 哈希）**不含** 该文件哈希，restore 走
   restore-keys 前缀匹配，因此旧 target 目录仍会被恢复，先跑完的分片把新 key
   写出去。真正的一次性代价是 **cargo 因 rustflags 变化判定所有单元指纹失效**
   → 换配置后的**第一次 run 会重编**（4 个分片各一次），第二次起回到缓存稳态。
   这就是为什么用 `.cargo/config.toml` 而不是工作流级 `env: RUSTFLAGS`：后者会
   改 `restoreKey`，直接丢缓存恢复。
3. **LTO 交互**：本仓库没有任何 `[profile] lto`（`grep -rn lto --include=Cargo.toml`
   为空），所以不存在"LTO 链接与普通链接换不同链接器"的混用问题；将来若加
   fat LTO，mold 仍承担该 target 的链接，需要重新量化（mold 的 LTO 场景与
   bfd 差异未必同比例）。
4. **android/apk 腿与 compare-visuals 腿**：两者都交叉编译到
   aarch64-linux-android / x86_64-linux-android，target 段不命中，保持 NDK 链接器；
   本机已验证默认三元组构建命令行无 mold 参数（见第四节）。
5. **sccache**：链接本来就不进 sccache（这与"每 run 672 次链接"是同一件事）；
   但 rustflags 变化会改变 sccache 的编译键，可能让那 6/182 的命中失效一次。
6. **产物体积**：三臂差异 <1.5%（如 core 单元 lld 8 675 048 / mold 8 640 800 B），
   不构成风险。

## 六、未验层（不得当成已验证）

- **CI 侧零执行**：本线按要求不 push、不开 PR；Ubuntu runner 上 mold 2.30 的
  实际表现、以及自检步的真实输出都还没有实测证据。
- **runner 上的绝对链接时间未知**：本地是 8 核 Termux、loadavg 20–24；runner 是
  4 vCPU 且相对空闲。收益区间（7–26 s/分片）是按"每单元链接占比 3–6%"外推，
  只保证量级，不保证数值；真正的数字必须由换配置后的 CI run 对着第三节口径读。
- 采样的 4 个单元未覆盖 client 的 45 个测试全部，也没测 `--features desktop`
  那支 release 链接（它同样走 mold，但不在测试腿的量化范围内）。
- 本契约不主张 mold 能解决"每分片重复构建 168 个二进制"这件事：那是编译侧
  （rust-cache 覆盖 rlib、test leaf 每次必编）与 sccache 命中率的问题，属于
  另一条线。
