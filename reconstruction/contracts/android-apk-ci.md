# I 线：可移植 APK 构建与本地产物验证

退出条件（roadmap I 行）："可移植APK CI、依赖/16KB/生命周期/实际设备验收"。
本契约覆盖前两项中**不依赖设备**的部分：APK 能在干净 checkout 上从源码
构建出来，且产物满足安装/加载的硬性不变量。真机视觉与帧率仍在 #34 真机
队列里单独记账。

## 产物链路

```
cargo build --release -p callys-client --features android [--target aarch64-linux-android]
  -> libcallys_client.so           (JNI 宿主 + 引擎)
javac --release 17 (android.jar)   -> classes/*.class
d8 --min-api 24                    -> classes.dex
aapt2 compile/link                 -> base.apk (res + AndroidManifest)
python zipfile 注入                -> base.apk += classes.dex + lib/arm64-v8a/libcallys_client.so + assets/*
zipalign -P 16 -f 4                -> aligned.apk
apksigner sign                     -> CallysCaves2_64bit_Rust.apk
python3 scripts/verify_apk.py      -> 10 项不变量断言
```

`scripts/build_apk.sh` 同时支持两条宿主：
- Termux/Android：Rust 宿主**就是** aarch64-linux-android，不带 `--target`，
  走 Termux 自身 clang sysroot（`~/.cargo/config.toml` 里写死 linker），
  产物可能带 `RUNPATH=/data/data/com.termux/files/usr/lib`，脚本用 patchelf 摘除。
- Linux CI：`CALLY_TARGET=aarch64-linux-android`，linker 取
  `$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android24-clang`，
  无宿主 RUNPATH。

## 不可变量的断言（verify_apk.py）

| 检查 | 为什么它是硬性的 |
| --- | --- |
| 必需打包项 | 少任何一项 = 装不上/黑屏/无资产 |
| cdylib STORED | 压缩后 zipalign 无法做页对齐，且加载器要求未压缩映射 |
| ELF 是 aarch64 | 目标设备 arm64-v8a |
| 所有 PT_LOAD 16 KB 对齐 | Android 15+/16 的 16 KB 页设备要求 |
| zip 内 .so 数据偏移 16 KB 对齐 | 同上，加载器按页映射，必须落在页边界 |
| 无 DT_RPATH/DT_RUNPATH | 有宿主路径 = 真机 dlopen 静默失败 |
| 无宿主 sysroot DT_NEEDED | 同上 |
| 每个 GLOBAL 未定义符号可在 NDK API-24 stub 解析 | 设备链接器按系统库命名空间解析；stub 是它的静态替身。真机实锤：`eglGetString` 被 Rust presenter 引用，11/11 全绿的 APK 在 dlopen 时 `cannot locate symbol` 直接崩在 MainActivity.<clinit>（设备 libEGL 与 NDK 各 API 档 stub 都只导出 `eglQueryString`）。缺 stub 目录时报 SKIP，不假装 PASS。 |
| classes.dex 含三个宿主类 | 否则 JNI 入口不存在 |
| AXML 里 package/launch activity | 否则包名/入口不符 |
| apksigner verify | 签名链完整（CI 用一次性身份，见下）。CI 里验证步骤是独立 shell，PATH 上没有 apksigner，所以验证器会自行到 `$ANDROID_SDK_ROOT/build-tools/*` 找；workflow 也把 build-tools 加进了 `GITHUB_PATH`。缺工具时报 SKIP 而不是假装 PASS。 |

这些检查全部做过伪证（扰动产物→对应断言 RED，见提交说明）：删 cdylib、
把 cdylib 改压缩、抹掉 dex 类名、给 cdylib 加回 RUNPATH、截断 AXML、
破坏 ELF magic——每一项都让**它自己那条**断言失败，而不是崩在别处。

## 签名身份边界

- 设备签名身份的证书 SHA-256 = `25f6d992f8e8c0deb373b10cf9e768153e39dad15163509245350cab20819c99`
  （本机 APK 实测，`apksigner verify --print-certs`）。`verify_apk.py
  --expect-signer-sha256 <hex>` 可把它钉成断言：对的摘要 11/11 通过，错的摘要
  该项 FAIL。
- 设备可覆盖安装的身份固定在 `~/.config/callyscaves2/debug.keystore`，脚本
  默认拒绝凭空生成新身份（改名换签名会导致 `pm install -r` 失败或静默清数据）。
- CI 用 `CALLY_GENERATE_CI_KEYSTORE=1` 生成**一次性**身份，只用于构建验证：
  该 APK 不能覆盖设备安装。设备安装仍走本地密钥。

## 本批踩到的坑（已修，写进证据）

- **javac 文件清单不能硬编码**：旧脚本手写三个 `.java`。本批的分支基线取自一个
  较早的工作树（那里只有 GlesPresenter/MainActivity/PointerReleaseQueue），
  照搬后 CI 立刻 RED：`InputViewport.java`（main 上第四个宿主类，指针映射的
  唯一实现）没被编译，8 个 `cannot find symbol`。修法：`find src -name '*.java'`
  全量编译；`verify_apk.py` 的 dex 断言同样改为**从 `android-build/src` 派生**
  期望类名（新增宿主类漏进 dex 会被守护抓出），不再维护手写清单。
- **同名文件可能来自不同工作树**：本批第一次本地构建是在旧工作树上做的，
  只证明旧树的 Java 源可编译，不能替代 main 基线的验证；已在 main 基线的
  PR 工作树重跑（见提交说明的最终证据）。
- **SDK build-tools 的 `d8` 可能是空壳**：本机 `build-tools/36.0.0/d8` 是
  `exit 0` 存根（不产出 dex，退出码 0）。脚本现在检测"d8 退出 0 但没有
  classes.dex"并改用 `cmdline-tools/latest/lib/r8.jar`，随后仍失败才报错。

## 未验层

- CI 侧首次运行尚未发生（本批提交后由 GitHub Actions 实测）。
- 真机：帧率未复测（`#54` 的 GLES presenter 只有 SurfaceFlinger 帧计数，
  无 fps 数字；被关闭的 `#50` 的 57 ticks/s 是已删除的 hardware-canvas 路径）。
- 生命周期（前后台切换/旋转/低内存）与 16 KB 页真机加载均为 NOT RUN。
