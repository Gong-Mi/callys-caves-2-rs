/* cally 逆向卡：尾跳 / 空桩合辑（原版 libyoyo.so，armv7）
 *
 * @card  0x000cef90 .. 0x0027d1dc（非连续，12 个函数 / 27 条锚点，地址各出现一次）
 *        —— 每个函数一个 @func 小节；verify_reverse_v1 的 range 列只取文件里第一个 @func
 *           （0x000cef90..0x000cef94），本卡真实覆盖面看 @card 这一行与 12 个 @func 小节。
 * 级别: 骨架（27/27 条锚定 EXACT；每条指令都解出语义：尾跳目标 + 参数处置，或「直接返回、r0 原值」；无函数体可读）
 * 符号:  _Z6YYFreePKv                      void YYFree(void const*)
 *        _Z9YYStrFreePKc                   void YYStrFree(char const*)
 *        _Z17LOCK_RVALUE_MUTEXv            void LOCK_RVALUE_MUTEX()
 *        _Z19UNLOCK_RVALUE_MUTEXv          void UNLOCK_RVALUE_MUTEX()
 *        _Z22DeterminePotentialRootP12YYObjectBaseS0_
 *                                          DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 *        _Znwj                             void* operator new(unsigned int)
 *        _ZnwjPKci                         void* operator new(unsigned int, char const*, int)
 *        _ZnwjRKSt9nothrow_t               void* operator new(unsigned int, std::nothrow_t const&)
 *        _ZdlPvRKSt9nothrow_t              void  operator delete(void*, std::nothrow_t const&)
 *        _ZdlPvj                           void  operator delete(void*, unsigned int)
 *        _ZdlPv                            void  operator delete(void*)
 *        _ZdlPvPKci                        void  operator delete(void*, char const*, int)
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f…（4,689,844 B，stripped，ELF32 ARM）
 * 锚表:  reconstruction/reverse-v1/asm/index-Stubs_TailJumps.tsv
 *        —— scripts/asm_index.py 对 9 段连续区间各跑一次（0xcef90/0xdc414/0x190f2c..0x190f34/0x191710/
 *           0x27c524/0x27d17c..0x27d1ac/0x27d1c4/0x27d1cc..0x27d1d4/0x27d1dc），按地址升序拼接成 27 行。
 *           卡与 index 两侧都是二进制直出，一次 RESULT EXACT（missing=0 extra=0 mismatch=0）。
 *
 * ── 这张卡在说什么 ───────────────────────────────────────────────
 *   12 个函数一共 27 条锚点 = 24 条指令 + 3 条 literal pool 数据字。指令只落两种形状：
 *     9 个用 b  尾跳（YYFree / YYStrFree / operator new ×3 / operator delete ×4）—— 不建帧、不存寄存器、
 *               lr 原封不动，被调者返回时直接回到桩的调用者 ⇒ 栈深度在转移那一刻不变，等价于「函数体 =
 *               目标函数的一次调用」，参数寄存器 r0..r3 全部原样可见于被调者。
 *     3 个用 bx lr（LOCK / UNLOCK_RVALUE_MUTEX、DeterminePotentialRoot）—— 一条指令返回，不改任何寄存器，
 *               严格意义上的空操作（唯一可观测副作用是耗时）。
 *   剩下 12 条（= 3 个 operator new × 4 条 ldr/movw/mov/add）只是把 __FILE__/__LINE__/清零位摆进 r1..r3，
 *   摆完就进上表的 b 尾跳；全程没有条件分支、没有循环、没有函数内调用返回点。
 *   三族的尾跳目标只有两个：MemoryManager::Free(0x27c2d0) 与 MemoryManager::Alloc(0x27ce78)，
 *   外加一个例外 —— operator delete(void*, char const*, int) 直接 b 到 free@plt(0xb655c)，绕开 MemoryManager。
 *
 * ── 参数处置总表（本卡的「一句话结论」）───────────────────────────
 *   函数                              r0        r1              r2              r3      返回
 *   YYFree(void const*)               原样下传  —               —               —       被调者的 void
 *   YYStrFree(char const*)            原样下传  —               —               —       被调者的 void
 *   LOCK / UNLOCK_RVALUE_MUTEX        —         —               —               —       直接 bx lr
 *   DeterminePotentialRoot(a,b)       原样返回  (丢弃)          —               —       = a（调用者都不读）
 *   operator new(unsigned)            原样下传  被覆写=__FILE__  被覆写=__LINE__  #1       被调者返回的指针
 *   operator new(u, char const*, int) 原样下传  被覆写=__FILE__  被覆写=__LINE__  #1       同上（调用方 file/line 丢弃）
 *   operator new(u, nothrow_t const&) 原样下传  被覆写=__FILE__  被覆写=__LINE__  #1       同上（nothrow 实参丢弃）
 *   operator delete(void*)            原样下传  —               —               —       被调者的 void
 *   operator delete(void*, nothrow&)  原样下传  丢弃(nothrow)    —               —       被调者的 void
 *   operator delete(void*, unsigned)  原样下传  丢弃(size)       —               —       被调者的 void
 *   operator delete(void*, char*, int)原样下传  丢弃            丢弃            —       被调者的 void（走 libc free）
 *   ⇒ 只有 r0 在所有 12 个函数里有语义；r1..r3 只在 operator new 里被「改写成本模块自己的调试信息」。
 *
 * ── 引用面（asm/instructions.jsonl.xz 全 .text 扫描，b/bl 直呼目标计数）────
 *   YYFree 702(693 bl + 9 b) | YYStrFree 70(全 bl) | LOCK 544(全 bl) | UNLOCK 540(537 bl + 3 b)
 *   DeterminePotentialRoot 207(176 bl + 31 b) | _Znwj 427(全 bl) | _ZdlPv 882(862 bl + 20 b)
 *   _ZnwjPKci 0 | _ZnwjRKSt9nothrow_t 0 | _ZdlPvRKSt9nothrow_t 0 | _ZdlPvj 0 | _ZdlPvPKci 0
 *   —— 后 5 个在 .text 内没有任何调用点，但 llvm-readelf --dyn-syms 显示 12 个符号全是
 *      GLOBAL DEFAULT FUNC（导出），所以「0 内部调用点」只说明本模块不用它，不等于死代码。
 */

/* ══════════════════════════════════════════════════════════════════
 * 1) YYFree —— 释放族最短入口（4 B）
 * ══════════════════════════════════════════════════════════════════ */

#include <stdbool.h>
#include <stdlib.h>

extern void MemoryManager_Free(void const *p); /* _ZN13MemoryManager4FreeEPKv，目标地址 0x27c2d0（他卡范围） */

/* @func 0x000cef90 0x000cef94  size 4   1 条（YYFree(void const*)，_Z6YYFreePKv） */
void YYFree(void const *p) {
    /* @0xcef90 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— 唯一一条：前跳 +1,758,008 B，不建帧、不存 lr */
    MemoryManager_Free(p);
}

/* 逐条语义（1/1 条已解）：
 *   0xcef90 ea06b4ce  b #+0x1AD338 —— 目标 = (0xcef90+8) + 0x6B4CE*4 = 0xcef98 + 0x1AD338 = 0x27c2d0。
 *   · 用 b 不用 bl ⇒ lr 仍是 YYFree 调用者的返回地址，Free 的 pop {…,pc} 直接返回到那一层；
 *     YYFree 本身没有 push/pop，因此转移前后 sp 一致，帧数为零。
 *   · r0..r3 一条都不动（本函数没有任何 mov/ldr），所以 Free 看到的就是调用者摆好的实参；
 *     Free 只读 r0（0x27c2d4 subs r4,r0,#0 做 NULL 早退），r1..r3 在 Free 里不被读。
 *   · 本函数不做 NULL 检查、不知道长度、不区分标量/数组/对象 —— 三件事全在被调者里。
 * 引用面：702 处（693 bl + 9 b），是 RValue 机制的主要释放口（tag1 字符串 text 即走这里，见 FREE-002）。 */

/* ══════════════════════════════════════════════════════════════════
 * 2) YYStrFree —— 与 YYFree 机器码等价的「字符串」释放口（4 B）
 * ══════════════════════════════════════════════════════════════════ */

/* @func 0x000dc414 0x000dc418  size 4   1 条（YYStrFree(char const*)，_Z9YYStrFreePKc） */
void YYStrFree(char const *s) {
    /* @0xdc414 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— 同一目标，另一条 b（前跳 +1,703,604 B） */
    MemoryManager_Free(s);
}

/* 逐条语义（1/1 条已解）：
 *   0xdc414 ea067fad  b #+0x19FEB4 —— 目标 = (0xdc414+8) + 0x67FAD*4 = 0xdc41c + 0x19FEB4 = 0x27c2d0。
 *   · 和 YYFree 的差别只有 b 的位移编码（两条 4 B 函数、同一目标、同样只传 r0）⇒ 机器码层面两者等价，
 *     区别纯粹在名字与调用约定：YYStrFree 的形参是 char const*，但函数体不读内容、不 strlen、不处理 NUL，
 *     也不做任何「字符串池」记账 —— 「Str」在本构建里只是符号命名，不是行为。
 *   · 引用面 70 处（全 bl），集中在 FREE_RValue__Pre 的 tag2 数组销毁（元素块 / chunk 表 / 容器本体
 *     三处都走它，见 FREE-004），与 tag1 走 YYFree 形成两套并行的释放通道。 */

/* ══════════════════════════════════════════════════════════════════
 * 3) LOCK_RVALUE_MUTEX / UNLOCK_RVALUE_MUTEX —— 编译期被抹平的加解锁（各 4 B）
 * ══════════════════════════════════════════════════════════════════ */

/* @func 0x00190f2c 0x00190f30  size 4   1 条（LOCK_RVALUE_MUTEX()，_Z17LOCK_RVALUE_MUTEXv） */
void LOCK_RVALUE_MUTEX(void) {
    /* @0x190f2c bx lr —— 空操作：直接返回，任何寄存器都不改 */
}

/* @func 0x00190f30 0x00190f34  size 4   1 条（UNLOCK_RVALUE_MUTEX()，_Z19UNLOCK_RVALUE_MUTEXv） */
void UNLOCK_RVALUE_MUTEX(void) {
    /* @0x190f30 bx lr —— 同构空操作 */
}

/* 逐条语义（2/2 条已解）：
 *   0x190f2c e12fff1e bx lr、0x190f30 e12fff1e bx lr —— 同一编码，两条 4 B 函数体。
 *   · bx lr 只改 pc，不改 r0..r12、不改标志位 ⇒ 对调用者完全透明；两条各占 4 B，无 literal pool。
 *   · 名字里的 MUTEX 是个陷阱：互斥体对象本身是真的 —— 同一族 CREATE_RVALUE_MUTEX(0x190ef0，60 B)
 *     确实 malloc(8)、把指针写进 GOT 单例，并尾跳 Mutex::Init(0x27e038)，传入的名字字符串落在
 *     0x34c5e4 = "MemoryManagerMutex"。也就是说：对象被创建、被初始化，唯独加锁/解锁两个入口被编译成
 *     bx lr ⇒ 本构建里这条锁从来没被真正拿过。
 *   · 后果：RVALUE/引用计数相关的临界区（FREE_RValue__Pre 里 28 条 LOCK/UNLOCK 就是例子）没有任何同步，
 *     递归释放也不需要可重入锁 —— 这套代码按单线程语义成立。与他卡 FREE-012 独立同结论。
 *   · 引用面 544 / 540 处（LOCK 全 bl；UNLOCK 537 bl + 3 b）。 */

/* ══════════════════════════════════════════════════════════════════
 * 4) DeterminePotentialRoot —— GC/写屏障钩子被编译成空（4 B）
 * ══════════════════════════════════════════════════════════════════ */

typedef struct YYObjectBase YYObjectBase;

/* @func 0x00191710 0x00191714  size 4   1 条（DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)） */
YYObjectBase *DeterminePotentialRoot(YYObjectBase *a, YYObjectBase *b) {
    (void)b;
    /* @0x191710 bx lr —— 直接返回；r0 仍是第一个实参，因此返回值 == a */
    return a;
}

/* 逐条语义（1/1 条已解）：
 *   0x191710 e12fff1e bx lr —— 唯一一条。返回值寄存器 r0 从入口到出口没被写过，所以「返回」的其实是
 *   调用者传进来的第一个实参；第二个实参 r1 连读都没读。
 *   · 207 个调用点（176 bl + 31 b）逐个检查后继指令，没有一条以 r0 为操作数 ⇒ 全二进制都按 void 用它
 *     （典型后继：ldr 93 / b 91 / mov 16 / bl 4 / cmp r4 1 / cmp r8 1 / subs r7 1）。
 *     31 个 b 尾跳更进一步说明它是「调用链末端的一次空跳」：bx lr 直接返回到更上一层。
 *   · 调用形状（0xcfa20、0xcfefc 两处实测）：先 bl GetContextStackTop(0xd3a54) 取当前上下文栈顶 → r0，
 *     要登记的对象 → r1，然后 bl 本函数。结合邻居（0x191714 YYObjectBase::GetDispose、0x190f58
 *     CGCGeneration）判断这是写屏障/潜在根登记钩子；本构建里它什么都不做 ⇒ 这条路径从不登记任何根。
 *   · 严格说只能钉到「代码是空桩」；「cyclic GC 因此缺根、会不会漏回收」属于运行期后果，未验证（见 claims 的 narrowed）。 */

/* ══════════════════════════════════════════════════════════════════
 * 5) operator new(unsigned int) —— 分配族模板（24 B = 20 B 指令 + 4 B 字面量）
 * ══════════════════════════════════════════════════════════════════ */

extern void *MemoryManager_Alloc(unsigned int size, char const *file, int line, bool zero); /* 0x27ce78 */

/* @func 0x0027c524 0x0027c53c  size 24  6 条（operator new(unsigned int)，_Znwj；末条是 literal pool 数据字） */
void *operator_new(unsigned int size) {
    /* @0x27c524 ldr r1, [pc, #0xc] —— 取字面量槽 0x27c538 的内容 0x000dacb0（= __FILE__ - pc 的差） */
    /* @0x27c528 movw r2, #0x525 —— r2 = 1317 = 本文件的 __LINE__ */
    /* @0x27c52c mov r3, #1 —— 第 4 参 = 清零位 = true */
    /* @0x27c530 add r1, pc, r1 —— r1 = (0x27c530+8) + 0x000dacb0 = 0x27c538 + 0x000dacb0 = 0x3571e8 */
    /* @0x27c534 b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— 尾跳 Alloc(size, __FILE__, 1317, true) */
    return MemoryManager_Alloc(size, "jni/../jni/yoyo/../../../Platform/MemoryManager.cpp", 1317, true);
}

/* @0x27c538 strheq r10, [sp], -r0 —— 数据字 0x000dacb0（literal pool，非指令；objdump 把数据当指令译了） */

/* 逐条语义（6/6 条已解，其中 1 条是数据）：
 *   · 0x27c524 的 ldr 与 0x27c530 的 add 是标准的「ldr r1,=字符串」PC 相对解引用：ARM 下两条都以
 *     (自身地址+8) 为 pc；ldr 落在 0x27c538，add 的 pc 也正好是 0x27c538，所以字面量存的是
 *     (串地址 - 字面量槽地址) 而不是绝对地址 —— 这也是三条 new 各有不同字面量却落到同一个串的原因。
 *   · 0x3571e8 处的字符串由 .rodata 直读实测：jni/../jni/yoyo/../../../Platform/MemoryManager.cpp
 *     （ELF 的 PT_LOAD#2 是 VA==偏移 的恒等映射；前一串在 0x3571e0 收尾于 "bytes\n\0\0"，
 *     紧接其后就是本串起点，边界干净，没有指到别的串中间）。
 *   · r0(size) 一条指令都没碰 ⇒ 调用者的 size 原样进 Alloc；r3 被写成 1 ⇒ Alloc 的「分配后清零」为真
 *     （MMALLOC-004 已证第 4 参语义：既门控 memset 又下传 bucketAlloc，同族 YYAlloc 固定 #0）。
 *   · 引用面 427 处（全 bl），是本模块 C++ 侧分配的唯一入口。 */

/* ══════════════════════════════════════════════════════════════════
 * 6) operator new(unsigned int, char const*, int) —— 调用方的 file/line 被丢弃（24 B）
 * ══════════════════════════════════════════════════════════════════ */

/* @func 0x0027d17c 0x0027d194  size 24  6 条（operator new(unsigned int, char const*, int)，_ZnwjPKci） */
void *operator_new_fp(unsigned int size, char const *file, int line) {
    (void)file;
    (void)line; /* 形参在寄存器 r1/r2 里，但下面两条写指令把它们覆盖掉 */
    /* @0x27d17c ldr r1, [pc, #0xc] —— 字面量槽 0x27d190 = 0x000da058 */
    /* @0x27d180 movw r2, #0x537 —— r2 = 1335（本 wrapper 自己的 __LINE__） */
    /* @0x27d184 mov r3, #1 —— 清零位 = true */
    /* @0x27d188 add r1, pc, r1 —— r1 = (0x27d188+8) + 0x000da058 = 0x27d190 + 0x000da058 = 0x3571e8 */
    /* @0x27d18c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— Alloc(size, __FILE__, 1335, true) */
    return MemoryManager_Alloc(size, "jni/../jni/yoyo/../../../Platform/MemoryManager.cpp", 1335, true);
}

/* @0x27d190 andeq r10, sp, r8, asr r0 —— 数据字 0x000da058（literal pool，非指令） */

/* 逐条语义（6/6 条已解，其中 1 条是数据）：
 *   · 这是 Itanium ABI 的 operator new(size_t, char const*, int)「带调试信息」形式。语义上它该把调用方
 *     传的 file/line 一起交给分配器，但二进制里 r1/r2 在 0x27d17c/0x27d180 被无条件覆写成本文件自己的
 *     __FILE__/__LINE__ ⇒ 调用方那对实参彻底丢弃（不是「覆盖后仍保留副本」，本函数没有读 r1/r2 的任何指令）。
 *   · 三条 new 的 __FILE__ 全部落到 0x3571e8 同一个串，__LINE__ 分别是 1317 / 1335 / 1342 ——
 *     也就是说分配记录归属到 MemoryManager.cpp 的三个不同行，而 MMALLOC-002 已证 file/line 在这条
 *     分配链路上完全不落地（Alloc 不读、_Alloc 又覆盖 r1/r2）⇒ 这 3 个行号只活在寄存器里。
 *   · 引用面 0（.text 内无调用点）；符号仍是 .dynsym GLOBAL DEFAULT，供外部模块/模板实例使用。 */

/* ══════════════════════════════════════════════════════════════════
 * 7) operator new(unsigned int, std::nothrow_t const&) —— 没有 catch 的 nothrow（24 B）
 * ══════════════════════════════════════════════════════════════════ */

/* @func 0x0027d194 0x0027d1ac  size 24  6 条（operator new(unsigned int, std::nothrow_t const&)，_ZnwjRKSt9nothrow_t） */
void *operator_new_nothrow(unsigned int size, void const *nothrow_tag) {
    (void)nothrow_tag; /* r1 被下面第一条覆写：nothrow_t& 实参整个丢弃 */
    /* @0x27d194 ldr r1, [pc, #0xc] —— 字面量槽 0x27d1a8 = 0x000da040 */
    /* @0x27d198 movw r2, #0x53e —— r2 = 1342 */
    /* @0x27d19c mov r3, #1 —— 清零位 = true */
    /* @0x27d1a0 add r1, pc, r1 —— r1 = (0x27d1a0+8) + 0x000da040 = 0x27d1a8 + 0x000da040 = 0x3571e8 */
    /* @0x27d1a4 b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— Alloc(size, __FILE__, 1342, true) */
    return MemoryManager_Alloc(size, "jni/../jni/yoyo/../../../Platform/MemoryManager.cpp", 1342, true);
}

/* @0x27d1a8 andeq r10, sp, r0, asr #32 —— 数据字 0x000da040（literal pool，非指令） */

/* 逐条语义（6/6 条已解，其中 1 条是数据）：
 *   · 函数体里既没有 push 也没有 bl（没有任何 __cxa_* 落脚点），失败兜底全在被调者：
 *     nothrow 语义在这里不是「catch 后返回 NULL」，而是「被调者根本不会抛」—— Alloc 失败时自己
 *     mov r0,#0 返回（内存分配链见 MMALLOC-001），于是 nullptr 自然传回调用者。
 *   · r0(size) 原样；nothrow_t const& 只占形参位置，不参与任何指令。
 *   · 引用面 0；符号导出。 */

/* ══════════════════════════════════════════════════════════════════
 * 8) operator delete 四个变体（各 4 B，同一条 b，两个不同目标）
 * ══════════════════════════════════════════════════════════════════ */

/* @func 0x0027d1c4 0x0027d1c8  size 4   1 条（operator delete(void*, std::nothrow_t const&)，_ZdlPvRKSt9nothrow_t） */
void operator_delete_nothrow(void *p, void const *nothrow_tag) {
    (void)nothrow_tag;
    /* @0x27d1c4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— nothrow_t& 实参丢弃 */
    MemoryManager_Free(p);
}

/* @func 0x0027d1cc 0x0027d1d0  size 4   1 条（operator delete(void*, unsigned int)，_ZdlPvj） */
void operator_delete_sized(void *p, unsigned int size) {
    (void)size;
    /* @0x27d1cc b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— sized-delete 的大小提示丢弃 */
    MemoryManager_Free(p);
}

/* @func 0x0027d1d0 0x0027d1d4  size 4   1 条（operator delete(void*)，_ZdlPv） */
void operator_delete(void *p) {
    /* @0x27d1d0 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— 主力释放口：882 处引用（862 bl + 20 b） */
    MemoryManager_Free(p);
}

/* @func 0x0027d1dc 0x0027d1e0  size 4   1 条（operator delete(void*, char const*, int)，_ZdlPvPKci） */
void operator_delete_fp(void *p, char const *file, int line) {
    (void)file;
    (void)line;
    /* @0x27d1dc b 0xb655c <free@plt> —— 唯一不经过 MemoryManager 的释放桩：直接调 libc free */
    free(p);
}

/* 逐条语义（4/4 条已解）：
 *   · 0x27d1c4 eafffc41、0x27d1cc eafffc3f、0x27d1d0 eafffc3e —— 三条 b 的 imm24 分别是
 *     -0x3BF/-0x3C1/-0x3C2（*4 = -0xEFC/-0xF04/-0xF08），pc 分别是 0x27d1cc/0x27d1d4/0x27d1d8，
 *     三条独立算到同一个 0x27c2d0：(0x27d1cc)-0xEFC = (0x27d1d4)-0xF04 = (0x27d1d8)-0xF08 = 0x27c2d0。
 *   · 三个变体在机器码层面只差位移编码：nothrow_t const&、unsigned int(size) 两个实参全被丢弃，
 *     只有 r0 有语义 ⇒ sized delete 的「大小提示」在这版二进制里没有任何用处。
 *   · 0x27d1dc eaf8e4de 的 imm24 是负数：0x27d1e4 - 0x71B22*4 = 0x27d1e4 - 0x1C6C88 = 0xb655c，
 *     即 free@plt。它跟同族三个兄弟分道扬镳：不进 MemoryManager 的桶/计数，file/line 也丢弃。
 *     MemoryManager::Free 内部自己既可能 free(p)（0x27c340 一路）也可能先 ldr r3,[r0,#-0x10]!
 *     再 free（0x27c374 一路，对应 _Alloc 的 16 字节头），所以这条直连路径与分配侧是否严格配对
 *     需要单独审（0 个内部调用点也说明模块自己不这么用）⇒ 记 open，不在本卡下结论。
 *   · 布局：0x27d1c4..0x27d1e0 这 28 B 里挤着 8 个 4 B 函数，本卡只锚其中 4 个（delete 的非数组形式），
 *     三个 delete[] 兄弟 0x27d1c8（delete[](void*, nothrow_t const&)）、0x27d1d4（delete[](void*)，
 *     31 处引用）、0x27d1d8（delete[](void*, char const*, int)）不在本卡范围 —— 不提锚点，避免跨卡撞地址。
 *
 * ── 结论（本卡新增的硬事实）─────────────────────────────────────
 *   1. 12 个函数 / 27 条锚点（24 条指令 + 3 条数据字）：控制转移只有 9 条 b 尾跳与 3 条 bx lr 空返回，
 *      其余 12 条全在 operator new 里摆参数；没有条件分支、没有循环、没有函数内调用返回点
 *      ⇒ 语义完全由「目标 + 参数」两件事决定，本卡把 12 个的两件事都钉死了。
 *   2. 释放侧有 5 个入口指向同一函数：YYFree、YYStrFree、operator delete(void*)、
 *      operator delete(void*, nothrow_t const&)、operator delete(void*, unsigned int) → 0x27c2d0；
 *      其中前两者在机器码层面完全等价，差别只在符号名。
 *   3. 释放侧唯一例外是 operator delete(void*, char const*, int) → free@plt(0xb655c)，绕开 MemoryManager，
 *      而且它是 5 个 delete 变体里唯一在本模块内 0 调用的一个。
 *   4. 分配侧三个 operator new 是同一模板的三个行号：__FILE__ 恒为 Platform/MemoryManager.cpp(0x3571e8)、
 *      清零位恒 1、size 原样；带 file/line 与带 nothrow 的两个变体都会把调用方的 r1/r2 覆写掉。
 *   5. 同步与 GC 钩子被编译掉：LOCK/UNLOCK_RVALUE_MUTEX（各 4 B，544/540 处引用）什么都不做，
 *      尽管同名 Mutex 对象确实被 CREATE_RVALUE_MUTEX 创建并初始化为 "MemoryManagerMutex"；
 *      DeterminePotentialRoot（207 处引用）同样 bx lr，且没有任何调用点读它的返回值。
 *   6. 12 个符号全部 .dynsym GLOBAL DEFAULT FUNC ⇒ 5 个 0 内部引用的桩仍对外可达。
 *
 * ── open ────────────────────────────────────────────────────────
 *   · operator delete(void*, char const*, int) 的 free@plt 直连是否与 MemoryManager::Alloc 的
 *     16 字节头/桶记账冲突（真机双释放或指针偏移错配），未验证；本卡只钉「它调的是 libc free」。
 *   · DeterminePotentialRoot 空桩对 cyclic GC 可达性的实际影响（是否漏回收）需要运行期证据。
 *   · 为什么 LOCK/UNLOCK 被抹平而 MemoryManager::Free 内部的 Mutex::Lock(0x27e084)/Unlock(0x27e09c)
 *     是真的 —— 两套锁是不同宏/不同编译单元，源码级原因未知。
 */
