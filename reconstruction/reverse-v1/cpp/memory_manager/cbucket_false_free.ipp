/* cbucket_false_free.ipp — 分片交付（false-mode 批次·分片二）：
 * CBucket<ChunkBytes, AreaBytes, Mode> 的两个真实模板成员
 *   uint32_t GetSize();
 *   uint32_t Free(const void *block);
 * 本文件只做上述两个定义，覆盖两个 false 实例的 4 个入口：
 *   CBucket<16,1048576,false>::GetSize   0x190cd0  8 B / 2 词
 *   CBucket<16,1048576,false>::Free      0x190bc8  120 B / 30 词
 *   CBucket<32768,1048576,false>::GetSize 0xd341c  8 B / 2 词
 *   CBucket<32768,1048576,false>::Free    0xd3314  120 B / 30 词
 * 不定义 Init/Check（另一分片负责），不做整类实例化，不引用 vtable/RTTI。
 * 在冻结模板类头 cbucket_classes.hpp（活树 cpp/memory_manager/ 已提交；
 * 依赖的 6 个 memory_manager 头以 S/headers/ 冻结哈希为准）之后包含。
 *
 * 原件 ELF: ~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a（只读）。
 * 基线 ced3359d6a853560a54255e91d728566162d4c49。4 个原符号均 STB_WEAK
 * （模板实例化产物），ARM(32-bit word) 编码，0 literal words。
 */

/* ── uint32_t CBucket<...>::GetSize() ─────────────────────────────────────
 * 与 true-mode 完全同形：无 receiver 读取——入口 r0 直接被子常量覆盖，
 * 本体从不触碰 this，只返回模板实参 ChunkBytes。
 *   0x190cd0  e3a00010 mov r0, #16      e12fff1e bx lr   // CBucket<16,1048576,false>
 *   0xd341c   e3a00902 mov r0, #32768   e12fff1e bx lr   // CBucket<32768,1048576,false>
 */
template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
uint32_t CBucket<ChunkBytes, AreaBytes, Mode>::GetSize()
{
    return ChunkBytes; /* e3a00XXX mov r0, #ChunkBytes; e12fff1e bx lr */
}

/* ── uint32_t CBucket<...>::Free(const void *block) ───────────────────────
 * 与 true 的 14 词 / 56 B 纯 freelist 推入根本不同：false-mode Free 为
 * 30 词 / 120 B，先做页链归属查找，命中才推 freelist。两条原字
 * 0x190bc8 与 0xd3314 逐词完全相同（仅地址不同，交付说明附核对结论），
 * 本体同样与 ChunkBytes/AreaBytes 无关——AreaBytes=1048576 以
 * `add r2, r3, #1048576; add r2, r2, #8` 两条可编码立即数加法语义出现。
 * 代表锚 0x190bc8（全 30 词）：
 *   e5903004 ldr r3, [r0, #0x4]     ; 读 pageHead(+4)，唯一的 receiver 前置读取
 *   e52d4004 str r4, [sp, #-0x4]!   ; 保存调用者保留寄存器 r4
 *   e3530000 cmp r3, #0
 *   e1a04000 mov r4, r0             ; r4 = this（尾巴用）
 *   0a000009 beq +0x3c              ; 空链头 → mov r0, r3 返回其值(=0)，不写任何状态
 *   e283c008 add r12, r3, #8        ; lo = page + 8（数据区起点，跳过 next/owner 前缀）
 *   e2832601 add r2, r3, #1048576
 *   e151000c cmp r1, r12            ; r1 = block（无符号域判定 1）
 *   e2822008 add r2, r2, #8         ; hi = page + AreaBytes + 8
 *   3a000001 blo +0x30              ; block <  lo → 换下一链节点
 *   e1520001 cmp r2, r1             ; 无符号域判定 2
 *   8a000005 bhi +0x48              ; hi > block（即 block < hi）→ 命中，跳共享尾巴
 *                                    ;   block == hi 不命中（bhi 不含等号）→ 落 NEXT
 *   NEXT: e5933000 ldr r3, [r3]     ; 沿页链裸 ldr 走 next（页节点 +0，BucketPagePrefix::next）
 *         e3530000 cmp r3, #0
 *         1afffff5 bne -0x2c         ; 非空回环重试域判定
 *   EMPTY/EXHAUSTED: e1a00003 mov r0, r3  ; 两条路径抵达时 r3 恒为 0 → 返回 0
 *         e49d4004 ldr r4, [sp], #4
 *         e12fff1e bx lr
 *   HIT 共享尾巴（与 true-mode 尾巴同形，多一条域判定后跳入）：
 *         e594c008 ldr r12, [r4, #0x8]    ; LIVE 快照1: freeHead(+8) 旧头
 *         e3a00001 mov r0, #1             ; 返回字 1 提前置入
 *         e5942010 ldr r2, [r4, #0x10]    ; LIVE 快照2: freeCount(+10)
 *         e594300c ldr r3, [r4, #0xc]     ; LIVE 快照3: activeCount(+c)
 *         e0822000 add r2, r2, r0         ; freeCount + 1（u32）
 *         e581c000 str r12, [r1]          ; 向 block+0 以原宽（32-bit 词）写旧头
 *         e2433001 sub r3, r3, #1         ; activeCount - 1（u32 回绕）
 *         e5841008 str r1, [r4, #0x8]     ; 发布 +8 = block（新头）
 *         e5842010 str r2, [r4, #0x10]    ; 发布 +10 = freeCount+1
 *         e584300c str r3, [r4, #0xc]     ; 发布 +c = activeCount-1
 *         e49d4004 ldr r4, [sp], #4
 *         e12fff1e bx lr                   ; r0 = 1
 * 关键语义差异（vs true 批恒返 1）：false-mode 的返回值是归属判定结果——
 * pageHead 为空、或整条页链耗尽都没有命中 [page+8, page+AreaBytes+8) 时，
 * 走 `mov r0, r3`（此刻 r3 必为 0）返回 0，且不写任何状态（freelist/计数器
 * 一字不动）；只有命中的 block 才被链入并返回 1。mangle 不编码返回类型：
 * 原件 C++ 拼写（bool/uint32_t）未证，本文按已证返回字写 uint32_t。
 * gap：block == NULL 时行为 = 域判定自然失败走完链后返回 0，无显式判空；
 * 越界/回绕域边界（page + AreaBytes + 8 溢出 2^32）原字按无符号比较，此处
 * 如实照抄，不添加原件没有的防护。
 */
template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
uint32_t CBucket<ChunkBytes, AreaBytes, Mode>::Free(const void *block)
{
    BucketPagePrefix *page = pageHead;
    if (page == nullptr)
        return 0u; /* beq → mov r0, r3：r3 此刻恒为 0，不写任何状态 */

    const uintptr_t addr = reinterpret_cast<uintptr_t>(block); /* r1，本体不读 block 内容 */
    for (;;) {
        const uintptr_t lo = reinterpret_cast<uintptr_t>(page) + 8u; /* add r12, r3, #8 */
        const uintptr_t hi = lo + AreaBytes;      /* add #1048576; add #8（同一值，拆序等价） */
        if (addr >= lo && addr < hi) {            /* blo 未跳 && bhi 命中：无符号域 [lo, hi) */
            uint8_t *const head = freeHead;           /* ldr r12,[r4,#8]   LIVE 快照1(+8) */
            uint32_t freed  = freeCount + 1u;         /* ldr r2,[r4,#0x10]; add  LIVE 快照2(+10) */
            uint32_t active = activeCount - 1u;       /* ldr r3,[r4,#0xc];  sub  LIVE 快照3(+c)，u32 回绕 */

            *reinterpret_cast<uint8_t **>(const_cast<void *>(block)) = head;
            /* str r12, [r1]：旧头写进 block+0，原宽，无判空 */
            freeHead    = const_cast<uint8_t *>(static_cast<const uint8_t *>(block));
            /* str r1, [r4,#8]：发布 +8 = block */
            freeCount   = freed;   /* str r2, [r4,#0x10] */
            activeCount = active;  /* str r3, [r4,#0xc] */
            return 1u;             /* mov r0, #1; bx lr（原件在首个快照后即置 1，顺序差异无内存效应） */
        }
        page = page->next;         /* ldr r3, [r3]：沿页链裸词走 */
        if (page == nullptr)
            return 0u;             /* 链耗尽 → mov r0, r3：r3 必为 0，返回 0 */
    }
}
