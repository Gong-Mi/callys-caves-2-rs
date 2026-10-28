/* cally 逆向卡：Variable_Global_Init（原版 libyoyo.so，armv7）
 *
 * @func 0x1f3354 0x1f33b8  size 104  26 条（24 条指令 + 尾 2 池字；无栈实参、无返回值）
 * 级别: 正文（26/26 条逐条解出：resize 目标、字节数、文件/行、cap 与 data 的写序、10000 次逐字节
 *             清零全部钉住。未钉：globdecl 这张表**装什么**（1 B/项 的单位与用途）、为什么是 10000）
 * 符号: _Z20Variable_Global_Initv → void Variable_Global_Init()
 * 来源: libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f…（4,689,844 B，stripped，ELF32 ARM）
 * 锚表: asm/index-Variable_Global_Init.tsv（26 行）
 * 同层: globdecl（dynsym OBJECT，.bss 0x753100，size 8 —— 本函数唯一的写目标）、
 *       builtin_numb 0x753108（4 B）、builtin_variables 0x75310c（8000 B）、
 *       g_builtinVarLookup 0x7530fc、Code_Variable_Find_Name 0x1f3a5c 家族（另一个变量表集群）、
 *       MemoryManager::ReAlloc 0x27cedc、DoTheWork 0x2a16dc（唯一调用者 0x2a16f8）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把全局变量声明表 globdecl 重设成 10000 **字节**，然后把这 10000 字节全清零。
 *   没有「已初始化就返回」的短路，也没有任何尺寸/NULL 判断 —— 它是启动时一次性调用的重置函数，
 *   重入一次就等于「把表清空、容量重设」一次。
 *
 * ── 目标对象怎么钉住的（三方一致）──────────────────────────────
 *   ① 静态：1f335c 取池字 0x001fdabc，1f336c `ldr r4,[pc,r4]`（pc 1f3374）⇒ 地址 0x3f0e30；
 *      该槽是 R_ARM_RELATIVE，槽内 addend = 0x753100。
 *   ② 符号表：llvm-readelf --dyn-syms 里 `0x00753100  8 OBJECT GLOBAL DEFAULT 19 globdecl`
 *      —— 地址、大小（8 B = 一个 int + 一个指针）与下面两条 str 完全对上。
 *   ③ 邻居：+0x08 是 builtin_numb、+0x0c 是 builtin_variables（8000 B），说明它就在
 *      「变量系统」那一簇 .bss 里，不是随手一块匿名内存。
 *   ★ 名字 globdecl 来自原库 dynsym，不是本卡的翻译；它**装什么**仍未证（open 1）。
 *
 * ── 写序（3 条 store，顺序固定）────────────────────────────────
 *   1f3394  [r4+0x0] = 0x2710        cap = 10000
 *   1f3398  [r4+0x4] = ReAlloc 返回值 data = 新基址
 *   1f339c..1f33a8  data[i] = 0, i ∈ [0,10000)   ← 逐**字节**，strb
 *   ⇒ 结构体形状 = { int cap; char* data; }（8 B，与 dynsym 的 size 8 一致）。
 *
 * ── 未定（open）────────────────────────────────────────────
 *   1. globdecl 的语义：只证「10000 个 1 B 元素」。若元素其实是 4 B/16 B 的槽，清零长度就该是
 *      40000/160000 —— 代码写的是 10000，所以本卡只按「1 B/项」记，用途留空
 *   2. 为什么是 10000：与 GML 全局变量号段（Variable_GetName 里 i -= 100000 的那套）是否对应未证
 *   3. 谁读这张表：全库未筛出与本 GOT 槽 0x3f0e30 相同的第二处访问点（本函数是唯一写者）
 *   4. 重入后果：没有短路，第二次调用会把已有内容清零；运行期是否真的只调一次只由 DoTheWork 保证
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 入口：无参数、无返回值 ────────────────────────────────
 *   帧：push {r4,r5,lr} + sub sp,#12（12 B 只为给 ReAlloc 的第 5 实参留一格 + 8 B 对齐）
 *   r5 = 0 兼作「清零值」与「ReAlloc 的 zero 实参」；r4 稍后 = &globdecl。
 */

/* @0x1f3354 push {r4, r5, lr} */
/* @0x1f3358 sub sp, sp, #12 */
/* ── GOT 槽地址：池字 0x001fdabc + pc(1f3374) = 0x3f0e30 ──
 *   槽内 addend = 0x753100 = globdecl（dynsym OBJECT，size 8）。
 */

/* @0x1f335c ldr r4, [pc, #0x50] */
/* @0x1f3360 mov r5, #0 */
/* @0x1f3364 ldr r2, [pc, #0x4c] */
/* ── 常量 0x2710 = 10000：既是 ReAlloc 的字节数，也是随后的计数上限（1f338c 复用）──
 *   注意它被**硬编码**两次（movw r1 / movw r12），不是从任何字段读的。
 */

/* @0x1f3368 movw r1, #0x2710 */
/* @0x1f336c ldr r4, [pc, r4] */
/* ── 行号 106 + 文件串（池字 0x00159ec0 → pc 1f337c + 0x159ec0 = 0x34d23c）──
 *   0x34d23c = "jni/../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"
 *   ★ 与 CRoom::AddTile 的扩容（0x1ac2e4）是**同一文件同一行**：两处都是那个模板
 *     Resize 的内联副本 —— 这也是「globdecl 是一个 CArray 风格 {cap,data}」的最强旁证。
 */

/* @0x1f3370 mov r3, #106 */
/* @0x1f3374 add r2, pc, r2 */
/* ── 取旧 data 指针：[r4+0x4]（second word）──
 *   ⇒ 结构体布局 {int cap@+0; char* data@+4}；ReAlloc 的入参就是这一格，写回也在这一格。
 */

/* @0x1f3378 ldr r0, [r4, #0x4] */
/* ── ReAlloc 的第 5 实参 = 0（不清零）──
 *   函数签名 MemoryManager::ReAlloc(void*, uint, char const*, int, bool)，bool 走栈。
 *   既然不清零，后面的 1f339c 循环就是**必须**的（不是冗余）。
 */

/* @0x1f337c str r5, [sp] */
/* ── ReAlloc(globdecl.data, 10000, cARRAY_STRUCTURE.h, 106, false) ──
 *   没有 NULL 检查、没有「尺寸没变就跳过」的优化：每次都真调。
 */

/* @0x1f3380 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* ── 回写（3 条 store，顺序固定）──────────────────────────
 *   1f3394 str r12,[r4]   → cap = 10000
 *   1f3398 str r0,[r4,#4] → data = 新基址
 *   1f339c strb r2,[r0,r3] → data[i] = 0（r2 = 0）
 *   ⇒ 先 cap 后 data，中间没有别的写；读者若在单线程启动期之外并发读，会看到「cap 已变、data 未变」
 *     的窗口（本卡只记形状，运行期是否可能并发未证）。
 */

/* @0x1f3384 movw r12, #0x2710 */
/* @0x1f3388 mov r3, r5 */
/* @0x1f338c mov r1, r12 */
/* @0x1f3390 mov r2, r5 */
/* @0x1f3394 str r12, [r4] */
/* @0x1f3398 str r0, [r4, #0x4] */
/* ── 清零循环：i = 0..9999，逐字节（strb）──
 *   r1 = 0x2710（上限）、r3 = i、r2 = r5 = 0；bne 回 1f339c。
 *   ★ 单位是 1 B ⇒ 这张表被当成字节数组/位图用，不是 RValue 数组（open 1）。
 */

/* @0x1f339c strb r2, [r0, r3] */
/* @0x1f33a0 add r3, r3, #1 */
/* @0x1f33a4 cmp r3, r1 */
/* @0x1f33a8 bne 0x1f339c <_Z20Variable_Global_Initv+0x48> */
/* ── 收尾：add sp,#12 / pop {r4,r5,pc} —— 无返回值（r0 是 ReAlloc 的残留）──
 */

/* @0x1f33ac add sp, sp, #12 */
/* @0x1f33b0 pop {r4, r5, pc} */
/* ── literal pool（2 字）─────────────────────────────────
 *   1f33b4 = 0x001fdabc  → pc 1f3374 + 0x1fdabc = 0x3f0e30 → .bss 0x753100 = globdecl
 *   1f33b8 = 0x00159ec0  → pc 1f337c + 0x159ec0 = 0x34d23c = "…/Files/Platform/cARRAY_STRUCTURE.h"
 */

/* @0x1f33b4 ldrheq sp, [pc], -r12 */
/* @0x1f33b8 andseq r9, r5, r0, asr #29 */
