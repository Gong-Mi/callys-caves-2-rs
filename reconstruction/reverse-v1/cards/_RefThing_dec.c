/* cally 逆向卡：_RefThing<char const*>::dec（原版 libyoyo.so，armv7）
 * @func 0xc09f8 0xc0a7c  size 132  33 条（无 literal pool；帧 16 字节，无 canary）
 * 级别: 正文（33/33 条锚定；两条出口、双次加锁/解锁配平、不可达块的静态证明都写死；1 处源码层意图留 open）
 * 符号: _ZN9_RefThingIPKcE3decEv → void _RefThing<char const*>::dec()
 *
 * ── 对象布局（三条指令各自钉死一个字段）───────────────────────────
 *   +0  char const* thing   0xc0a20 ldr r0,[r4] 后送 YYFree；0xc0a28 归零
 *   +4  int         refcnt  0xc0a04/0xc0a08/0xc0a0c 读-减-写；第二次递减在 0xc0a34..0xc0a3c
 *   +8  int         size    0xc0a2c 归零（0xc0a58 再清一次）
 *   12 字节对象 = DoConv 里内联同一段模板时 mov r0,#12 + _Znwj 的尺寸（0xeb8a0）互证。
 *
 * ── 出口一：计数未归零（0xc0a10..0xc0a1c）──────────────────────
 *   LOCK_RVALUE_MUTEX(0x190f2c) → --refcnt → cmp #0 → 非 0 则 pop {r3,r4,r5,lr} + b UNLOCK_RVALUE_MUTEX(0x190f30)。
 *   注意这是尾跳：解锁在返回之后（b 而不是 bl+pop），锁一定被释放，对象不删。
 *
 * ── 出口二：计数归零（0xc0a20..0xc0a78）────────────────────────
 *   ① 0xc0a20 YYFree(thing)（0xcef90 是 `b MemoryManager::Free` 的单指令尾跳，符号长度 4）
 *   ② 0xc0a28/0xc0a2c 双清 0：thing=NULL、size=0（防二次释放）
 *   ③ 0xc0a30 再次 LOCK（此时第一把锁仍持有 ⇒ 只有递归/计数锁才不会死锁，见 open 1）
 *   ④ 0xc0a34..0xc0a3c 对同一个 +4 再减 1（值已是 0 ⇒ 得 -1），cmp #0 必不相等 ⇒ 0xc0a44 恒跳 0xc0a68
 *   ⑤ 0xc0a68 UNLOCK → 0xc0a6c/0xc0a70 operator delete(this)（0x27d1d0 = `b MemoryManager::Free`）
 *       → 0xc0a74 pop → 0xc0a78 尾跳 UNLOCK
 *   锁 2 次（0xc0a00、0xc0a30）/解锁 2 次（0xc0a68、0xc0a78），配平；delete 后不再解引用 this。
 *
 * ── 0xc0a48..0xc0a64 是静态死块（本卡的关键结论）───────────────────
 *   该块（YYFree + 清 0 + 递归 bl 0xc09f8 + delete）只能从 0xc0a44 的「相等」分支进入；
 *   而进入 0xc0a30 的唯一入口 0xc0a14 刚刚把 [r4+4] 写成 0（0xc0a0c 的 str），
 *   0xc0a38 sub 之后是 -1、0xc0a40 cmp #0 必不等 ⇒ 0xc0a44 永远走 bne，0xc0a48 永远取不到。
 *   前提只有一条：0xc0a24 的 YYFree 不写 this（它只释放 +0 的载荷缓冲区）—— 该前提成立。
 *   ⇒ 运行时不存在 double free / 二次 delete 路径；这段只能是编译器从嵌套 _RefThing 释放里合并出的残留。
 *
 * 结论（新增四条硬事实）:
 *   1. dec() 是「互斥锁保护的计数递减」：非零路径只减计数，零路径还要释放载荷并自杀（delete this）。
 *   2. 载荷用 YYFree、对象用 operator delete，两者在本二进制里都是 MemoryManager::Free 的单指令尾跳 ⇒ 同一分配器。
 *   3. 归零路径会对同一个 +4 再减一次（0 → -1），这个 -1 是必然结果，不是竞态；随后的 delete 不依赖它。
 *   4. 0xc0a48..0xc0a64 静态不可达 ⇒ 该函数不会二次释放；把它当可达会得出错误的 double-free 结论。
 * open:
 *   1. 0xc0a30 的第二次 LOCK 与 0xc0a78 的第二次 UNLOCK 在源码层的意图未定（两把嵌套计数？两处 release 被合并？）；
 *      可编译的等价实现必须保留「二次加锁 + 尾部解锁」才能逐条对齐指令。
 *   2. 递归调用 bl 0xc09f8（自调）在死块里，无法从运行时行为反证其存在意义，只能记为编译器产物。
 */
/* ── 帧：r3 一起入栈只为凑 4 字对齐，r3 本身没用到 */
/* @0xc09f8 push {r3, r4, r5, lr} */
/* r4 = this（全函数不变） */
/* @0xc09fc mov r4, r0 */
/* ── 第一把锁（出口一与出口二共用） */
/* @0xc0a00 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* 读计数 */
/* @0xc0a04 ldr r5, [r4, #0x4] */
/* --refcnt */
/* @0xc0a08 sub r5, r5, #1 */
/* 写回（零路径在 0xc0a30 再减一次时读的就是这个 0） */
/* @0xc0a0c str r5, [r4, #0x4] */
/* 判零 */
/* @0xc0a10 cmp r5, #0 */
/* 非零 → 出口一；零 → 出口二（0xc0a20） */
/* @0xc0a14 beq 0xc0a20 <_ZN9_RefThingIPKcE3decEv+0x28> */
/* 出口一收尾：先恢复寄存器，再尾跳解锁（锁在返回前释放） */
/* @0xc0a18 pop {r3, r4, r5, lr} */
/* 尾跳 UNLOCK_RVALUE_MUTEX，不返回本函数 */
/* @0xc0a1c b 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* ── 出口二 ①：释放载荷（+0 的 char const*） */
/* @0xc0a20 ldr r0, [r4] */
/* YYFree = `b MemoryManager::Free`（0xcef90，4 字节） */
/* @0xc0a24 bl 0xcef90 <_Z6YYFreePKv> */
/* thing = 0 */
/* @0xc0a28 str r5, [r4] */
/* size = 0 */
/* @0xc0a2c str r5, [r4, #0x8] */
/* ── 出口二 ③：第二次加锁（第一把仍持有） */
/* @0xc0a30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* 重读计数（此时必为 0） */
/* @0xc0a34 ldr r5, [r4, #0x4] */
/* 再减 1 ⇒ -1 */
/* @0xc0a38 sub r5, r5, #1 */
/* 写回 -1 */
/* @0xc0a3c str r5, [r4, #0x4] */
/* 判零：-1 与 0 不等 */
/* @0xc0a40 cmp r5, #0 */
/* 恒跳 0xc0a68 ⇒ 0xc0a48 起的块静态不可达 */
/* @0xc0a44 bne 0xc0a68 <_ZN9_RefThingIPKcE3decEv+0x70> */
/* （死块）再读 thing —— 已是 0 */
/* @0xc0a48 ldr r0, [r4] */
/* （死块）YYFree(NULL) */
/* @0xc0a4c bl 0xcef90 <_Z6YYFreePKv> */
/* （死块）r0 = this，为递归调用准备 */
/* @0xc0a50 mov r0, r4 */
/* （死块）thing = 0 */
/* @0xc0a54 str r5, [r4] */
/* （死块）size = 0 */
/* @0xc0a58 str r5, [r4, #0x8] */
/* （死块）递归 bl 自身 */
/* @0xc0a5c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* （死块）r0 = this，为 delete 准备 */
/* @0xc0a60 mov r0, r4 */
/* （死块）operator delete(this) */
/* @0xc0a64 bl 0x27d1d0 <_ZdlPv> */
/* ── 出口二 ⑤：第一把解锁 */
/* @0xc0a68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* r0 = this */
/* @0xc0a6c mov r0, r4 */
/* operator delete(this)（0x27d1d0 = `b MemoryManager::Free`） */
/* @0xc0a70 bl 0x27d1d0 <_ZdlPv> */
/* 恢复寄存器（含 lr，供尾跳解锁返回） */
/* @0xc0a74 pop {r3, r4, r5, lr} */
/* 尾跳 UNLOCK：第二次解锁，函数真正返回调用者 */
/* @0xc0a78 b 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
