# 项目重启自检（dev restart，2026-10-25）

目标：把"隔一段时间回到这个工程要多久才能确认自己能干活"压到分钟级以内。
两条脚本，都在 `scripts/`，都不改源码：

| 命令 | 做什么 | 实测（prague，Termux aarch64） |
| --- | --- | --- |
| `bash scripts/dev_status.sh` | 只读自检：git HEAD/脏区、rustc/cargo/nextest/mold、javac、aapt2/zipalign/apksigner、android.jar、签名 keystore、libyoyo 哈希、unicorn 版本、上一次全量 Summary | ~1 s，`dev_status: READY` |
| `bash scripts/dev_smoke.sh` | 三步冒烟：C 碰撞单测（107 checks）→ mask-base oracle 探针（base_probe.py）→ Rust 精确碰撞套件（nextest 单目标 5 tests） | 3 s（热 target）；冷构建另算 |

## 设计约束

- **status 不构建**：只回答"缺什么"，缺项打 `MISSING` 并 exit 1，适合会话开场跑。
- **smoke 三步各自独立记 PASS/FAIL**，任何一步红就 exit 1，方便定位是 C 几何、
  oracle 前置、还是 Rust 套件坏了。
- 两者都用 `$TMPDIR` 而不是 `/tmp`：Termux 上 `/tmp` 不可写（本项目已知坑）。
- 冒烟**不替代**全量：全量口径仍是
  `cargo nextest run --workspace --cargo-profile ci-test --no-fail-fast`
  （本机实测 `Summary [307.434s] 1068 passed / 4 skipped`，墙钟 10m30s，
  见 `nextest-prague.log`；CI 侧数字见 `ci-compile-floor.md`）。

## 边界

- status 的 `dirty(src)` 会漏掉 `android-build/` 与 `*.log`（构建产物与日志不算脏），
  其余未提交改动都会被计入。
- smoke 假定 `~/cally/oracle/libyoyo.so` 或 `CALLY_LIBYOYO` 指向原版 ARMv7 库；
  没有它会红在第 2 步，这是预期行为（见 `collision-broad-phase.md` §7.2）。
- 这组脚本只覆盖"碰撞几何 + oracle + 精确套件"这条最常用的回归面，不覆盖
  APK 打包（`scripts/build_apk.sh` + `verify_apk.py`）和真机/无头壳验收。
