/* cally 逆向卡：YYAlloc（原版 libyoyo.so，armv7）
 * @func 0xcef4c 0xcef64  size 24  6 条（5 条指令 + 1 个 literal pool 字）
 * 级别: 正文（6/6 条锚定；唯一的字面量已解成源码坐标字符串，尾跳目标已核）
 * 符号: _Z7YYAlloci → void* YYAlloc(int size)
 *
 * ── 一句话 ──────────────────────────────────────────────────────
 *   YYAlloc(size) 就是 MemoryManager::Alloc(size, "…/Files/Code/Code_Main.cpp", 1293, false)：
 *   一条 b 尾跳，不建帧、不检查 0、不清零。它是 Alloc 的「带调用点坐标、不清零」封装。
 *
 * ── 三个实参怎么摆 ──────────────────────────────────────────────
 *   入参 r0 = size，原样保留（尾跳时仍是第 1 参）；
 *   r1 = 文件名字符串：ldr r1,[pc,#0xc] 取 pc(0xcef54)+0xc = 0xcef60 处的字 0x002632a4，
 *      再 add r1,pc,r1 用 pc(0xcef60) 相加 ⇒ 0xcef60 + 0x2632a4 = 0x332204（.rodata），
 *      内容实测为 "jni/../jni/yoyo/../../../Files/Code/Code_Main.cpp"；
 *   r2 = 行号 0x50d = 1293（movw r2,#0x50d）；
 *   r3 = 0（mov r3,#0）⇒ 第 4 参 bool zero = false。
 *   ⇒ 分配点坐标为 Code_Main.cpp:1293，与「MemoryManager::Alloc 带文件/行号、源码坐标以字符串形式在 .rodata」一致。
 *
 * ── 为什么第 4 参是 false ───────────────────────────────────────
 *   同族对照：operator new(_Znwj, 0x27c524) 在同一位置写 mov r3,#1；本函数写 mov r3,#0。
 *   Alloc 用第 4 参门控 memset(p,0,size)（本仓 MemoryManager_Alloc 卡 0x27ce98/0x27cecc），
 *   ⇒ YYAlloc 分配后不清零，operator new 清 —— 两者的差别就在这一个 bit。
 *
 * 结论（新增三条硬事实）:
 *   1. YYAlloc 是 MemoryManager::Alloc 的纯尾调用封装，全部信息（文件、行号、清零位）都是编译期常量。
 *   2. 分配点 = Code_Main.cpp:1293，这个坐标以 .rodata 字符串形式落在 0x332204，可由字面量池独立复现。
 *   3. size==0 的处理不在本函数（没有比较指令），由 Alloc 的 0x27ce7c/0x27ce84 早退负责 ⇒ YYAlloc(0) 返回 0。
 * open:
 *   无 —— 24 字节范围内 5 条指令 + 1 个字面量全部闭合。
 */
/* ── 取字面量池里的文件名字符串偏移（pc 基址 = 0xcef54） */
/* @0xcef4c ldr r1, [pc, #0xc] */
/* 行号 1293 */
/* @0xcef50 movw r2, #0x50d */
/* 清零位 = false（对照 _Znwj 的 #1） */
/* @0xcef54 mov r3, #0 */
/* pc(0xcef60) + 0x2632a4 = 0x332204 → "jni/../jni/yoyo/../../../Files/Code/Code_Main.cpp" */
/* @0xcef58 add r1, pc, r1 */
/* 尾跳 Alloc(size, file, 1293, false)：无帧、无返回后处理 */
/* @0xcef5c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* literal pool 字 0x002632a4（objdump 把它译成 eoreq，按规矩保留原写法；它不是指令） */
/* @0xcef60 eoreq r3, r6, r4, lsr #5 */
