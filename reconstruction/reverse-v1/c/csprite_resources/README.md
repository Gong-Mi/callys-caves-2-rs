# CSprite 资源释放链 — 静态 C 候选

样本 SHA-256：3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a。

- `FreeMask`：[0x1e3b58,0x1e3bcc)，116B；`has_mask==0` 不动；逐行释放后重读表/计数、清两字，最终 Free 表再清对象字段。
- `FreeTexture`：[0x1e56fc,0x1e5748)，76B；0x1e570c 是 `pople`，初始 count<=0 早退；正数循环跳过负 id，回调后重读表/计数并写槽 -1。
- `ClearSWFData`：[0x1e68b0,0x1e6b4c)，668B；按 tag 和裸偏移释放对象、容器、记录、元素及 dictionary。对象数组为 NULL 时不清其计数；容器计数门是 ==0，内层循环保留无符号比较。

所有实现直接包含 `../csprite_clear/src/csprite_clear.h`，不另建 CSprite 定义，导出原 mangled 名。原有全库锚点仍分别在 All_61/All_64/All_38，不重复分配。

## 父级修正与反例

原候选的两处分支与一个释放点错误已修，不接受其自造全绿作为原件正确性证明：

1. FreeTexture 把 pople 误读为 ==0：修订负计数夹具后先以 `FT_NEG_NO_CALL` 失败，改成 <=0 后通过；错误等零闸作为变异保留。
2. ClearSWFData 在记录指针非空、记录数为0时漏掉 Free(record_base)：t11 先以释放序列 3/4 失败，修复后通过；错误作为 M4 保留。
3. ClearSWFData 把容器 ==0 误写为 <=0：t12 使用合法单条目和回调将负计数收缩到0，避免巨量迭代；修前释放序列失败，修后通过；M5 保留。

## 复跑

在本目录执行：

    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/test_free_resources.py
    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/test_clear_swf.py
    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/test_chain.py

默认输出为独占临时目录并自动清理；显式设置 `CALLY_RESOURCE_OUT` / `CALLY_SWF_OUT` 可保留结果。静态闸默认原件路径与 Loader 相同，允许 `CALLY_ORIGINAL_SO`，但哈希必须匹配。依赖 clang/LLVM、capstone、pyelftools 和 qemu-arm。

FreeMask/FreeTexture 的独立矩阵：host 10 个用例、7 个语义负控、2 个 no-op；ARM32 独立矩阵仅编译。ClearSWFData：host 与 ARM32/qemu 各12例、4个语义负控及no-op。集成消费者实际链接 Loader、Clear、FreeMask、FreeTexture、ClearSWFData 五份译文，host/ARM32 各3场景，验证整链事件序列与状态交接，资源函数不再被替身顶替。

边界：本轮不运行原件、ART 或 Unicorn，不作原版差分。真实分配器/图形驱动、骨骼析构、SWF构建仍为外部依赖或合成替身；非法图、未对齐/无效地址、无限迭代、异常展开、并发及所有权未闭合。候选按原偏移恢复，不替无来源证据的节点编类名。
