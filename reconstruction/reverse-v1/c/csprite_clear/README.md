# CSprite::Clear ARM32 静态译文候选

原版 `libyoyo_armv7.so` SHA-256：`3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。
函数 `_ZN7CSprite5ClearEv`：`0x1e6b4c..0x1e6cb0`（356 字节，89 条 ARM 指令）。
逐条原版锚点在 `../../cards/All_47.c` 的 Clear 段；主张见 `../../claims-batchSPRCLEAR-STATIC.jsonl`。

`src/csprite_clear.c` 和头文件是依静态指令编写的 C 候选，外部依赖都是未实现符号。
调用多重集和字段集合一致并不等于行为等价；真实分配器、析构、SWF/纹理/掩码
依赖及真实输入状态未在此闭合。目标代码的 ARM 异常展开元数据也与原件不同。
原件未执行，不能把本目录的测试描述成原版差分或真实游戏验收。

本目录测试运行方式：

    python3 tools/run_fixtures.py

需要 clang、lld、qemu-arm；缺 qemu-arm 则返回 2，不冒充全矩阵成功。
默认使用 TMPDIR 下的临时目录并在退出时清理；设置 `CALLY_CLEAR_OUT` 可保留
各构建和 fixture 输出。host 对依赖 32 位虚表调用的 4 个场景显式跳过；
ARM32 qemu 运行的是译文及测试替身，不是原版。五个已知错误变异应分别被指定
场景拒绝；T13 检查 bitmap Free 返回后再读取 texture_ids 的顺序。

原版 `0x1e6bf8` 的 Free 回调是否能在实际游戏中改变 `self+0x50` 尚未确认；
T13 是用于锁住指令顺序的合成负控，不声称现实调用链必然重入。
