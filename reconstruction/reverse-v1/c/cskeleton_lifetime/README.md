# CSkeletonSprite 生命周期与字节解码 — 静态 C 候选

固定样本 SHA-256：3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a。

- SimpleDecode：[0xbd840,0xbd86c)，11 条指令。len<=0 不读缓冲区；正数逐字节减 key（初值42），key 按32位递推 key*key+key；每次调用重置。
- C1/C2：[0xbd86c,0xbd910)，39 条指令 + 8B literal pool。三个32位槽清零，写匿名16B上下文，再解码两段、构造 atlas/json/data。readData 接收 name 基址。
- D1/D2：[0xbd910,0xbd96c)，22 条指令 + 4B literal pool。data→json→flag=1→atlas→flag=0，不清槽、不 delete。空 atlas 也最终将旗标归0。

C1/C2 与 D1/D2 在原件中同址，译文保留真正链接别名；两者正常返回 this。共享 Loader/Clear C 头已从 void 修成 void*，原有替身一并更新并回归，不以“调用者没用返回值”丢掉原 ABI。

匿名 `0x479c98` 只恢复为四个32位字 `{end,w04,w08,w0c}`，不替后三个字起业务名字。`g_yy_479c98` 是译文宿主绑定名，不是原件动态符号；没有提供者时链接必须失败。`g_bFreeingSpineSprite` 绑定原同名全局，volatile 写固定强制1→0窗口。本批不认证并发或重入生命周期。

## 复跑

    TMPDIR="$HOME/.hermes/cache/scratch" LLVM_PROFILE_FILE=/dev/null python3 tools/run_tests.py

默认输出在独占临时目录，结束清理。原件只读静态校验位置可用 `CALLY_ORIGINAL_SO` 指定，哈希不可漂。依赖 clang/LLVM、capstone、pyelftools、qemu-arm。

- 生命周期：host/ARM32各17项具名断言；2个语义负控精确退出1且仅命中指定断言，no-op输出逐字节一致。
- 解码：host/ARM32各4场景，包括256种单字节值、16步固定递推向量、准确写入跨度与每次调用复位；2个安全变异被具名断言拒绝。
- 静态校准：原件条件码、正常返回this、同址别名、两个literal/GOT目标与空串字节。
- 集成：同一执行件链接 Loader、Clear、三项资源释放、骨骼构造/析构与 SimpleDecode 的8个实际函数译文；host/ARM32各4场景。骨骼路径实际经过 Loader→构造→字节解码→spine合成边界→Clear→析构，检查真正被消费者读到的解码字节、参数、全局、释放顺序和状态交接。

ARM32 实测使用 freestanding 静态镜像与 qemu-arm，不需要 ARM libc/sysroot；缺 qemu 返回2，不能用“交叉编译通过”冒充运行通过。

证据边界：没有运行原件、ART或Unicorn。spine六个实际库函数、真实分配器/图形后端和SWF构建仍为外部依赖或明确合成替身；真实匿名上下文消费者、异常展开、并发、无效/回绕地址及全部资源格式未闭合。三份 C 体是静态还原，不是整体原版等价证明。全库锚点仍归 All_67/All_57/All_63，不重复发锚。
