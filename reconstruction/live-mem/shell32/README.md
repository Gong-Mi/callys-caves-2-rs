# shell32 — 原版 Cally's Caves 2 无窗口壳（活体 oracle）

不装 APK、不开 Activity，用裸 `dalvikvm32` 跑原版 runner：EGL ES2 PBuffer + 原版
`classes.dex` 上 classpath，`RenderSplash → Startup → Process` 循环照抄
`DemoRenderer` 的调用序列。用途：零前台干扰地读原版运行态（视图/相机/实例/
全局变量）、注入输入、复现 boot 基线。

## 构建与运行（Termux, root）

```sh
S=~/callys-caves-2-rs/reconstruction/live-mem/shell32
AJAR=~/android-sdk/platforms/android-35/android.jar
javac -cp "$AJAR" --release 8 -d build/stubs $(find stubsrc -name '*.java')
javac -cp "$AJAR:build/stubs" --release 8 -d build/classes src/*.java
dx --dex --output=build/shell.dex build/classes      # 本机 dx 会报 InvocationTargetException 但产物有效
su -c "$S/run.sh" > work/logs/runNN.log 2>&1
```

`run.sh` 需要的外部件（不入库，见下）：
- `work/libs/libyoyo.so`、`libopenal.so`：从原版 APK `lib/armeabi-v7a/` 取
  （libyoyo sha256 = 3bbedd09…，与 live-mem/libyoyo_armv7.so 同）
- `work/libs/libbhshell.so`、`work/bootsp.dex`：来自 blockheads shell32 runtime-lab
  （注册 framework natives；`regFramework` 必须在任何 framework 类初始化之前调用）
- `apk/base.apk`：原版 APK（sha256 d608f455…），`apk/classes.dex` 供 classpath

## 关键坑（全部实测）

- **stub 不进 dex**：`stubsrc/` 只做编译期签名；`dx` 的输入只能是 `build/classes`
  （否则 stub 影子化真类，RegisterNatives 会 NoSuchMethodError/静默错绑）。
- **shim 必须先加载**：`System.load(libandroid_runtime.so)` → `libbhshell.so` →
  `BhShell.regFramework()`，在 `Looper.prepare()` 之前。否则 `Looper.<clinit>`
  读 SystemProperties 就崩。
- `RunnerJNILib.ms_context` 必须给（`BhCtx`）：`Startup` 里 `PackageManagerHasSystemFeature`
  对 null 调 CallObjectMethod → ART 直接 abort。
- `RunnerActivity.CurrentActivity` 用 `Unsafe.allocateInstance`（不进 ctor）：
  `Process` 会回调 `HasVsyncHandler()` 解引用 `CurrentActivity.vsyncHandler`。
- `sun.misc.Unsafe` 不在 API 35 android.jar → 编译期 stub + 全反射调用。

## 控制通道与观测

- `work/cmd.txt`：`touch <action> <id> <x> <y>` / `key <type> <keyCode>`。
  **id 必须 0**（id==0 才合成游戏鼠标态，id>0 只进多点数组）。
  ctl 线程是 claim-then-execute（先 rename 再执行）+ enter/done 打点：native
  调用挂住时不再吞掉后续命令。
- `work/paced` + `work/pace_ms`：帧延迟开关（默认 30ms，可调）——游戏未限速时
  以 ~500 步/s 快进，观测/输入时序都会失真。
- 画布 = 1136×640；世界→画布：`(wx - view_x) * 1136/448`, `(wy - view_y) * 640/252`。

## 已用壳验证的结论（详见 ../live-findings-v2.md）

视图/相机、room 绘制表结构、ID2InstanceE 容器、rm_town 全卡司绘制序、相机边界
clamp、全局/实例变量读取（YYObjectBase 哈希布局）、输入注入端到端（走动→换房）。
