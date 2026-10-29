/* cally 逆向卡：PushContextStack（原版 libyoyo.so，armv7）
 * @func 0xd3968 0xd3a34  size 204  51 条（45 条代码 + 6 个字面量池字）
 * 级别: 正文（门控字节、三个静态槽、容量翻倍、ReAlloc 实参、写入序、深度上限与失败行为全部逐条落锚；
 *            open 3 条见文末）
 * 符号: _Z16PushContextStackP12YYObjectBase → void PushContextStack(YYObjectBase* inst)
 *
 * ── 上下文栈存在哪里（单例形态）────────────────────────────────────────
 *   不是 C++ 类静态成员、没有 vtable、没有构造/析构函数；就是 .bss 里四个独立全局，全部经 PIC 的 GOT 取址：
 *     本函数 0xd3968 取池字 0x0031e2e0，0xd3970 add r12,pc,r12 → r12 = GOT 基址 0x3f1c58
 *     （全二进制只有这一个 GOT 基址：36 处 add r12,pc,r12 的求值全部等于 0x3f1c58）
 *   GOT 槽（全 R_ARM_RELATIVE，槽内容即文件内 addend，可直读复核）：
 *     0x3edbc0 → 0x47f295  u8              模式/开关字节（本函数唯一的门）
 *     0x3edc08 → 0x47f280  int32           count = 栈深，也等于下一个空位下标
 *     0x3edc0c → 0x47f27c  int32           capacity = 以元素计的容量（字节数 = capacity*4）
 *     0x3edc10 → 0x47f284  YYObjectBase**  data = 堆上数组基址
 *   0x47f27c / 0x47f280 / 0x47f284 在 .bss 里连续 12 字节，布局就是
 *     { int cap; int count; YYObjectBase** data; }；0x47f295 是 17 字节之后的独立单字节。
 *   对 .got 全量扫 addend：0x47f295 / 0x47f280 / 0x47f27c / 0x47f284 各只命中一个槽
 *     ⇒ 四个全局各只有一个 GOT 槽，不存在「同一变量两个槽」的歧义。
 *
 * ── 谁碰这个结构 ───────────────────────────────────────────────────────
 *   capacity 槽在 .text 里只有本函数一个引用点（0xd3994）；data 槽只有本函数（0xd39b0、0xd39d0）
 *   与 GetContextStackTop（pc 相对形式）用；count 槽被本函数、PopContextStack、GetContextStackTop 三家读写。
 *   全二进制没有任何清零 / 遍历 / 释放 data 的函数 —— 数组一旦分配就永不 free，
 *   count 也只会被 PopContextStack 一个个减回去，没有「整栈清空」入口。
 *
 * ── 语义草案（逐条落在下面的锚点上）────────────────────────────────────
 *   void PushContextStack(YYObjectBase* inst) {
 *     if (!g_mode) return;                          // 0xd397c..0xd398c
 *     if (g_count == g_cap) {                       // 0xd39a0..0xd39ac
 *       int n = g_count ? g_count * 2 : 1;          // 0xd39d4..0xd39e4（lsls 定符号位 + moveq 专路）
 *       g_cap = n;                                  // 同上（先写容量）
 *       g_data = (YYObjectBase**)MemoryManager::ReAlloc(
 *                  g_data, n * 4, "jni/../jni/yoyo/../../../Platform/MemoryManager.h", 74, false);
 *     }                                             // 0xd39e8..0xd3a18
 *     g_data[g_count] = inst;                       // 0xd39c4
 *     g_count = g_count + 1;                        // 0xd39bc / 0xd39c0（注意先写 count，后写元素）
 *   }
 *
 * ── 深度上限与溢出行为（本卡要回答的核心问题）──────────────────────────
 *   ① 没有深度上限常数：全函数不存在与任何上界比较的指令，唯一的容量条件是 count == capacity。
 *      容量按 1 → 2 → 4 → … 翻倍 ⇒ 「上限」= MemoryManager::ReAlloc 能给出的最大块，代码里没有第二道闸。
 *   ② 只有 count == capacity 才增长，且一次只翻到 2*count（刚好够这一次），不预留余量、不跳档。
 *   ③ ReAlloc 返回值不判空：0xd3a14 把 r0 直接写进 data 槽，紧接着 0xd39bc..0xd39c4 就用它当基址写第
 *      count 个元素 ⇒ 分配失败时是「data=0、count 未增，然后写地址 0+4*count」，必然崩；
 *      不存在「返回错误 / 丢掉这次压栈」的分支。
 *   ④ 容量先写、再 ReAlloc、再写数据：0xd39d8 / 0xd39e4 已经改了 capacity，0xd3a08 才可能失败，
 *      所以失败后结构停在「cap 已翻倍、data=0、count 未增」的撕裂态。
 *   ⑤ int32 溢出路径：count == cap == 0x40000000 时 lsls 得 0x80000000（非零，照样写进 cap），
 *      lslne 得 count*8 = 0（mod 2^32）→ ReAlloc(ptr, 0)：静态可推、实际不可达（要 2^30 个实例同时入栈）。
 *   ⑥ 元素写入序：0xd39c0 先写新 count，0xd39c4 才写 data[旧_count] ⇒ 两条指令之间若被打断
 *      （信号 / 另一个线程读这个结构），会看到 count 多算了一个尚未写入的槽。
 *      本函数 0xd3968..0xd3a18 里没有任何锁调用（既没有 RVALUE 锁也没有别的互斥），Pop / Top 同样无锁。
 *
 * ── 调用面（42 个 bl 点，全部是 bl，无尾跳）─────────────────────────────
 *   VM::Exec(0xe8234)、DoPush(0xe9ec0)、DoPop(0xe6b54/0xe6bf0/0xe6ee4/0xe6fa0/0xe7b94)、
 *   DoPopLocalVariable、DoCallLibrary、DoCallScript(0xe8758)、DoCall、Code_Constant_Find、AddConstant、
 *   Variable_Scope_SetVar、Variable_Scope_DeleteVar、Variable_Global_SetVar、YYObjectBase::Add、
 *   SetArrayEntry、F_NewGMLArray、JS_DefineOwnProperty_Internal×3、CreateArgumentsObject×2、
 *   Call_Accessor_Get×3、Call_Accessor_Set×3、Call_ScriptRef、JS_Argument_Put×2、JS_Argument_Get、
 *   F_JSNewArray / F_JSNew / F_JSNewObject、F_JS_Object_keys / getOwnPropertyNames、F_JSArrayCall×2、
 *   JS_Array_prototype_unshift
 *   ⇒ 用法是「临时把某个实例置为当前上下文」。最典型的两处：
 *     DoPop 0xe6b54 先 push 目标实例，随后按 [inst+0x24] 的变量数走变量解析；
 *     VM::Exec 0xe8234 push 后紧接着读 [inst+0x4] 的 RValue。
 *
 * ── 已证（每条指到指令）───────────────────────────────────────────────
 *   1. 门是 .bss 0x47f295 的字节：0xd397c 取槽、0xd3984 ldrb、0xd3988/0xd398c 为 0 直接走 0xd39c8 返回，
 *      连 count / capacity 都不读 ⇒ 门关时本函数是纯 no-op。
 *   2. count 在 0x47f280、capacity 在 0x47f27c：0xd3998 取 &count → 0xd39a0 ldr；
 *      0xd399c 取 &capacity → 0xd39a4 ldr；0xd39a8 cmp 的正是这两个值。
 *   3. cap==count 才增长：0xd39ac beq 到 0xd39d0；0xd39d4 lsls（×2）+ 0xd39dc lslne（字节 = count*8）
 *      + 0xd39e0/0xd39e4 的 cap:0→1、0xd39ec 的 bytes:0→4 是「首次分配」专路。
 *   4. 增长走 MemoryManager::ReAlloc：0xd39f8 line=74、0xd3a00 file=0x331038 =
 *      "jni/../jni/yoyo/../../../Platform/MemoryManager.h"、0xd39fc 第 5 实参 = 0(false)、
 *      0xd3a04 old=*data、0xd3a08 bl 0x27cedc；0xd3a14 把返回值写回 data 槽，0xd3a18 跳回写入段。
 *   5. 写入段顺序与基址：0xd39b0/0xd39b4 第三次 GOT 取址拿到 &data；0xd39bc 新 count、0xd39c0 存 count、
 *      0xd39c4 data[旧_count] = inst。
 *   6. 无上限、无失败分支、无锁：见「深度上限与溢出行为」①③⑥。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. 门字节 0x47f295 的语义与写入者未定。本卡只证「为 0 → 本函数 no-op」。同一字节在 .text 里另有
 *      23 个「字面量 0xffffbf68」的 ldr 点（本函数 0xd396c 是其中之一），与本仓库 DoGenerationalGC 卡
 *      （称「GC 开关」）、Code_Variable_Find_Slot_From_Name 卡（称「模式字节」）互证是同一字节；
 *      但全 .got 只有一个槽指向它，且这些点里没有写点（本卡未做全量写点穷举）。
 *   2. ReAlloc 第 5 实参（bool，恒 0）的语义未证（是否「清零新块」）。
 *   3. 关闭 / 切房间时谁清空这个数组：没有任何函数引用 capacity 槽，也没有函数对 data 做 free；
 *      静态侧看不到回收点（可能是进程级常驻，也可能是原版泄漏）。
 */

/* ---- 入口：建 GOT 基址 + 门判 ---- */
/* @0xd3968 ldr r12, [pc, #0xac] */
/* @0xd396c ldr r3, [pc, #0xac] */
/* @0xd3970 add r12, pc, r12 */
/* @0xd3974 push {r4, r5, r6, lr} */
/* @0xd3978 mov r5, r0 */
/* @0xd397c ldr r3, [r12, r3] */
/* @0xd3980 sub sp, sp, #8 */
/* @0xd3984 ldrb r3, [r3] */
/* @0xd3988 cmp r3, #0 */
/* @0xd398c beq 0xd39c8 <_Z16PushContextStackP12YYObjectBase+0x60> */
/* ---- 取 &count / &capacity 并比较 ---- */
/* @0xd3990 ldr r2, [pc, #0x8c] */
/* @0xd3994 ldr r3, [pc, #0x8c] */
/* @0xd3998 ldr r4, [r12, r2] */
/* @0xd399c ldr r3, [r12, r3] */
/* @0xd39a0 ldr r1, [r4] */
/* @0xd39a4 ldr r2, [r3] */
/* @0xd39a8 cmp r1, r2 */
/* @0xd39ac beq 0xd39d0 <_Z16PushContextStackP12YYObjectBase+0x68> */
/* ---- 常规路径：data[count] = inst，count++ ---- */
/* @0xd39b0 ldr r3, [pc, #0x74] */
/* @0xd39b4 ldr r3, [r12, r3] */
/* @0xd39b8 ldr r2, [r3] */
/* @0xd39bc add r3, r1, #1 */
/* @0xd39c0 str r3, [r4] */
/* @0xd39c4 str r5, [r2, r1, lsl #2] */
/* ---- 统一出口（两处共用） ---- */
/* @0xd39c8 add sp, sp, #8 */
/* @0xd39cc pop {r4, r5, r6, pc} */
/* ---- 增长路径：cap = 2*count（0→1 专路）+ ReAlloc ---- */
/* @0xd39d0 ldr lr, [pc, #0x54] */
/* @0xd39d4 lsls r2, r1, #1 */
/* @0xd39d8 strne r2, [r3] */
/* @0xd39dc lslne r1, r1, #3 */
/* @0xd39e0 moveq r2, #1 */
/* @0xd39e4 streq r2, [r3] */
/* @0xd39e8 ldr r6, [r12, lr] */
/* @0xd39ec moveq r1, #4 */
/* @0xd39f0 ldr r2, [pc, #0x38] */
/* @0xd39f4 mov r0, #0 */
/* @0xd39f8 mov r3, #74 */
/* @0xd39fc str r0, [sp] */
/* @0xd3a00 add r2, pc, r2 */
/* @0xd3a04 ldr r0, [r6] */
/* @0xd3a08 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd3a0c ldr r1, [r4] */
/* @0xd3a10 mov r2, r0 */
/* @0xd3a14 str r0, [r6] */
/* @0xd3a18 b 0xd39bc <_Z16PushContextStackP12YYObjectBase+0x54> */
/* ---- 字面量池 6 字（前两字被 0xd3968 / 0xd396c 取走） ---- */
/* @0xd3a1c eorseq lr, r1, r0, ror #5 */
/* @0xd3a20 .word 0xffffbf68 */
/* @0xd3a24 .word 0xffffbfb0 */
/* @0xd3a28 .word 0xffffbfb4 */
/* @0xd3a2c .word 0xffffbfb8 */
/* @0xd3a30 eoreq sp, r5, r0, lsr r6 */
