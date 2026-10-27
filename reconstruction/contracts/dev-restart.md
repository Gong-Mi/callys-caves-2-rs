# 项目重启自检（dev restart，2026-10-25）

目标：把"隔一段时间回到这个工程要多久才能确认自己能干活"压到分钟级以内。
两条脚本，都在 `scripts/`，都不改源码：

| 命令 | 做什么 | 实测（prague，Termux aarch64） |
| --- | --- | --- |
| `bash scripts/dev_status.sh` | 只读自检：git HEAD/脏区、rustc/cargo/nextest/mold、javac、aapt2/zipalign/apksigner、android.jar、签名 keystore、libyoyo 哈希、unicorn 版本、上一次全量 Summary | ~1 s，`dev_status: READY` |
| `bash scripts/dev_smoke.sh` | 八步冒烟：C 碰撞（109）→ C 对象（140）→ C with/destroy（142）→ C 房间数据/builtin（29）→ 6 个环境场景（101 expectations）→ 15 个 Draw 命令流场景（60 expectations）→ mask-base oracle → Rust 精确碰撞（6） | 热 target 约 20 s；冷构建另算 |
| `bash scripts/dev_smoke.sh --deep` | 上面八步 + boss 链 3/3 identical（六个失败/缺口计数器全 0）+ 9 个真实换房场景（79 expectations）+ 4 个真实房间 Draw 场景（24 expectations）+ 118 个 Draw body 命令流普查（含负控） | 约 1 分钟（含全量 C 生成+编译） |

## 设计约束

- **status 不构建**：只回答"缺什么"，缺项打 `MISSING` 并 exit 1，适合会话开场跑。
- **smoke 八步各自独立记 PASS/FAIL**，任何一步红就 exit 1，方便定位是 C 几何、
  对象/环境/房间、场景差分、Draw 命令流、oracle 前置、还是 Rust 套件坏了；每步同时核对退出码和非零计数。
- 两者都用 `$TMPDIR` 而不是 `/tmp`：Termux 上 `/tmp` 不可写（本项目已知坑）。
- 冒烟**不替代**全量：全量口径仍是
  `cargo nextest run --workspace --cargo-profile ci-test --no-fail-fast`
  （本机实测 `Summary [307.434s] 1068 passed / 4 skipped`，墙钟 10m30s，
  见 `nextest-prague.log`；CI 侧数字见 `ci-compile-floor.md`）。

## 边界

- **C 线（c-recon）只本地验证、不接 CI**（用户裁决 2026-10-25）：CI 对 C 线做不了
  什么、只会拖时间；验证口径 = 本机 `dev_smoke.sh` + `batch_diff.py`，不把
  c-recon 写进任何 workflow。任何"给 C 线加 CI 门"的建议默认驳回，除非用户改口。
- status 的 `dirty(src)` 会漏掉 `android-build/` 与 `*.log`（构建产物与日志不算脏），
  其余未提交改动都会被计入。
- smoke 假定 `~/cally/oracle/libyoyo.so` 或 `CALLY_LIBYOYO` 指向原版 ARMv7 库；
  没有它会红在第 7 步，这是预期行为（见 `collision-broad-phase.md` §7.2）。
- 这组脚本覆盖碰撞几何、对象/with/destroy、房间生命周期、真实 CODE 场景差分、GML Draw 命令流和 oracle，不覆盖
  ROOM tile/粒子命令合流、C 光栅化、APK 打包（`scripts/build_apk.sh` + `verify_apk.py`）和真机/无头壳验收。
