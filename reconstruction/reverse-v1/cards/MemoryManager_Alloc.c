/* cally 逆向卡：MemoryManager::Alloc（原版 libyoyo.so，armv7）
 * @func 0x27ce78 0x27cedc  size 100  25 条（无 literal pool；帧 16 字节，无 canary）
 * 级别: 正文（25/25 条锚定；四条出口、清零门控、空桩日志全部用被调函数/同族调用点互证）
 * 符号: _ZN13MemoryManager5AllocEjPKcib → void* MemoryManager::Alloc(uint32 size, char const* file, int line, bool zero)
 *
 * ── 一句话 ──────────────────────────────────────────────────────
 *   这是 _Alloc 的外壳：空 size 早退 → 转调 _Alloc → 需要就 memset 清零 → 记一条日志（本构建是空桩）→ 返回。
 *   四个参数里真正有作用的是 size 和第 4 个 bool；file/line 在本函数内是死参数（见下）。
 *
 * ── 四条出口（全部实测，无第五条）────────────────────────────────
 *   A. size == 0        → 0x27ce84 → 0x27cec4 → mov r0,#0 + pop ⇒ 返回 NULL，连 _Alloc 都不进（唯一不记账的路径）
 *   B. _Alloc 失败      → 0x27cea0 cmp r1,#0 + beq 0x27cec4 ⇒ 返回 NULL，且不打日志
 *   C. 成功且需清零     → 0x27ce98 tst + 0x27ce9c bne 0x27cecc ⇒ memset(p,0,size) 后 b 0x27cea8 汇入日志路
 *   D. 成功不需清零     → 0x27cea0 后直落 0x27cea8 ⇒ 日志后 0x27cebc mov r0,r4 + pop 返回 p
 *   失败在 memset 之前就判掉（0x27cea0 相对于 0x27ce98 是两条独立判断），所以不存在「清零掩盖失败」。
 *
 * ── file / line 是死参数 ─────────────────────────────────────────
 *   0x27ce88 的 bl _Alloc 直接吃 r0..r3 —— 进函数后只写过 r4/r5/r6，r1/r2 从未被改写，
 *   所以 (size, file, line, zero) 四参数原样下传。此后本函数再也不读 r1/r2。
 *   而被调 _Alloc(0x27cd54) 同样把 file/line 丢掉：它只留 r0=size、r3=zero（mov r4,r3），
 *   随后 mov r1,r4 把 r1 覆盖成 zero 传给 bucketAlloc(j,b)，r2 被 ldr r2,[pc,#0xf8] 覆盖。
 *   ⇒ 「带文件/行号」的签名在这版二进制里只剩形参位置：真实落地的是 _Alloc 的 16 字节头
 *     {size, 0xDEADC0DE, 0xBAADB00B, 0}（0x27cde4..0x27ce00，malloc 兜底路径，返回 p+16）。
 *
 * ── 第 4 参数 = 清零开关（两个方向都证）──────────────────────────
 *   正向：0x27ce98 tst r1,r5（r1 已归一化成 0/1，r5 = 第 4 参）→ 真则 0x27cecc memset(p,0,size)。
 *   旁证：同族 operator new（_Znwj，0x27c524） 在同一位置写 mov r3,#1 ⇒ new 走的是「分配即清零」。
 *   同时它又原样传进 _Alloc→bucketAlloc 的第 2 参（0x27cd80 mov r1,r4）⇒ 桶分配路径也带着同一面旗。
 *
 * ── 日志调用是空桩 ──────────────────────────────────────────────
 *   0x27cea8..0x27ceb8 摆出 (r0=0, r1=0, r2=p, r3=size) 调 logLocation(ELogType,void const*,void const*,uint32)；
 *   但 logLocation(0x27bcf4) 符号长度 4、体只有一条 bx lr ⇒ 编译期把日志实现成空函数了。
 *   ⇒ Alloc 的可观测副作用只有「清零」与「计数」（计数在 _Alloc：m_Total/m_InUse/m_Number/m_MaxSize 四组 add/sub）。
 *
 * 结论（新增四条硬事实）:
 *   1. Alloc = 早退 + 转调 + 可选清零 + 空桩日志；失败路径不写日志、不清零，直接返回 NULL。
 *   2. file/line 在本构建的分配链路上完全不落地（Alloc 不读、_Alloc 覆盖），内存头只有 size 与两个魔数。
 *   3. 第 4 参数是「分配后清零」：既门控 0x27cecc 的 memset，又一路传到 bucketAlloc 的第 2 参。
 *   4. logLocation 是 bx lr 空桩 ⇒ 任何「分配会被记录到日志」的推断在本二进制上都不成立。
 * open:
 *   1. ELogType 实参为 0 的枚举名未知（logLocation 被编译成空桩，没有第二个可比对的调用点）。
 *   2. _Alloc 的 0xDEADC0DE / 0xBAADB00B 两个魔数是谁在读（越界/重复释放检测路径）未展开，不属本卡范围。
 */
/* ── 段1：帧与入参（16 字节，只保存 callee-saved 的 r4/r5/r6） */
/* @0x27ce78 push {r4, r5, r6, lr} */
/* r6 = size；subs 置 Z 标志给下一条 beq */
/* @0x27ce7c subs r6, r0, #0 */
/* r5 = 第 4 参（bool zero） */
/* @0x27ce80 mov r5, r3 */
/* 出口 A：size==0 直接跳失败返回，不进 _Alloc */
/* @0x27ce84 beq 0x27cec4 <_ZN13MemoryManager5AllocEjPKcib+0x4c> */
/* ── 段2：转调真身。注意此刻 r0..r3 仍是原始四参数 ⇒ (size,file,line,zero) 原样下传 */
/* @0x27ce88 bl 0x27cd54 <_ZN13MemoryManager6_AllocEjPKcib> */
/* r1 = (p != 0)，用 adds 的进位/Z 结果归一化 */
/* @0x27ce8c adds r1, r0, #0 */
/* r4 = p（存住返回值，r0 后面要当 memset 的落点） */
/* @0x27ce90 mov r4, r0 */
/* 仅当 p != 0：r1 = 1（把 add 产生的非 0 值收敛成 1） */
/* @0x27ce94 movne r1, #1 */
/* ── 段3：清零门控 tst(p!=0, zero)：两者都真才 memset */
/* @0x27ce98 tst r1, r5 */
/* → 0x27cecc 的 memset 块；memset 后 b 0x27cea8 汇入日志路 */
/* @0x27ce9c bne 0x27cecc <_ZN13MemoryManager5AllocEjPKcib+0x54> */
/* ── 段4：失败判据（在清零之后、日志之前，独立一条） */
/* @0x27cea0 cmp r1, #0 */
/* 出口 B：p==0 → 返回 NULL，不写日志 */
/* @0x27cea4 beq 0x27cec4 <_ZN13MemoryManager5AllocEjPKcib+0x4c> */
/* ── 段5：日志调用 logLocation(0, NULL, p, size)。r0 先清 0 */
/* @0x27cea8 mov r0, #0 */
/* r3 = size（第 4 实参） */
/* @0x27ceac mov r3, r6 */
/* r1 = r0 = 0（第 2 实参恒为 NULL） */
/* @0x27ceb0 mov r1, r0 */
/* r2 = p（第 3 实参） */
/* @0x27ceb4 mov r2, r4 */
/* 第 1 实参 ELogType = 0；被调 logLocation(0x27bcf4) 只有 bx lr ⇒ 空桩 */
/* @0x27ceb8 bl 0x27bcf4 <_Z11logLocation8ELogTypePKvS1_j> */
/* ── 段6：成功返回 p */
/* @0x27cebc mov r0, r4 */
/* 出口 D 收尾（pop 里带 pc，单次返回） */
/* @0x27cec0 pop {r4, r5, r6, pc} */
/* 出口 A/B 共用：r0 = 0 */
/* @0x27cec4 mov r0, #0 */
/* @0x27cec8 pop {r4, r5, r6, pc} */
/* ── 段7：memset(p, 0, size)（r0 仍是 _Alloc 的返回值） */
/* @0x27cecc mov r1, #0 */
/* r2 = size */
/* @0x27ced0 mov r2, r6 */
/* 清零完成后 b 0x27cea8，与「不需清零」的成功路汇合 */
/* @0x27ced4 bl 0xb65b0 <memset@plt> */
/* @0x27ced8 b 0x27cea8 <_ZN13MemoryManager5AllocEjPKcib+0x30> */
