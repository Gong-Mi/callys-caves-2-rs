# CSprite::LoadFromChunk — 接入的静态 C 译文候选

样本 SHA-256：3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a。
入口 `_ZN7CSprite13LoadFromChunkEP8YYSpritePh`，[0x1e972c,0x1e9b68)：268 条指令 + 3 个 literal pool 字。锚点归属仍在 `cards/All_30.c`，本目录不重复主张锚点。

## 已恢复的静态合同

- 入口先调 Clear；三个指针参数中 WAD 参数在函数体内未被读取，寻址改用 `g_pWADBaseAddress`。
- 普通纹理及特殊 type=0/1/2/其它分流；所有正常出口返回 1，不凭返回值认证加载成功。
- 精灵头四边、宽高、原点、bool 和帧数按原偏移落位；`g_isZeus` 控制尾部格式。
- 两处指针表回填都使用 4B 槽；分配之后重新读取 `+0x18`。
- 掩码数始终写 `+0x64`；仅正数路径写 `+0x68` 和 `+0x35=(mask_count==count)`；非正数不动 `+0x35`。
- 半径保持每平方低32位回绕、有符号 int→float32、逐角 sqrt/ceil、截断和 max，不用 double/hypot 替代。
- 与 Clear 直接共用 `../csprite_clear/src/csprite_clear.h`，不保留第二份 CSprite 定义；公开入口导出原 mangled 符号。

## 本次集成修复

隔离候选的两处 `void **` 写表在 64 位宿主上写了 8B，而索引/槽步长是 4B。旧 26 个用例只比较表内低字，未观察表后写坏。本次增加 T27/T28 的映射内表尾哨兵：原候选 host 26 PASS / 2 FAIL，修为 `uint32_t` 写槽后 host/ARM32 各 28 PASS。独立重引入两处宽写分别只能由 T27/T28 拒绝，不靠崩溃。

## 复跑

在本目录执行；临时根在 Android/Termux 上须可写：

    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/run_tests.py
    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/negctl.py
    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/verify_integration.py
    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/verify_static.py

静态校验默认只读 `~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so`，可用 `CALLY_ORIGINAL_SO` 改位置，但哈希必须一致。需要 clang/LLVM、qemu-arm、capstone、pyelftools；缺 qemu 时不是完整通过。默认夹具临时输出自动清理；`run_tests.py --keep` 保留到 `CALLY_LOADER_OUT` 或本目录 out。

`verify_integration.py` 实际链接 Loader 与 Clear 译文，运行 Load→Clear→再次 Load 的 3 个合成场景，同时验证公开 ARM32 符号和两条宽写负控。其余直接依赖仍是明确标注的替身。

## 未闭合

- 本轮未执行原件、ART、Unicorn；所有执行均为自建译文及合成替身，不是原版差分。
- 分配闭包仍有目标不定的间接调用；尾跳与缺少 throw 动态符号不能证明无异常。原件 compact unwind 与 C 默认 CantUnwind 不同，不认证异常等价。
- 正计数配 NULL 表、超大循环、无效地址、跨32位地址空间、并发与特殊 FPSCR 状态不在默认夹具定义域。
- ARM32/qemu 使用合成 libm 边界；有限浮点向量不认证所有硬件浮点副作用。
- BuildSWFData、骨骼构造、实际分配器和 Clear 下游尚未形成全真实依赖闭包。已有历史记录不作为本轮原件执行证据。

隔离原候选及完整取证材料保留于 `~/cally-work/native-static-loader-r1/`；该目录不是本目录测试的隐式依赖。
