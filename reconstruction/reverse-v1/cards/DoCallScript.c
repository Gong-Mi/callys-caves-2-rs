/* cally 逆向卡：DoCallScript（原版 libyoyo.so，armv7）
 * @func 0xe8588 0xe8afc  size 1400  350 条（0xe8ad0..0xe8afc 为 literal pool，12 字，非指令）
 * 级别: 骨架（压帧 15 字、进入码十件套、三条退出路、other 绑定、寄存器搬运全证；
 *       栈搬家段的页记账与 flags&4 段的意图未证）
 * 符号: _Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_
 *       → uchar* DoCallScript(CScript* scr, int argc, uchar* sp, VMExec* exec,
 *                              YYObjectBase* self, YYObjectBase* other)
 * 实参: r0=scr(r8) r1=argc(r11) r2=sp(r5) r3=exec(r4)  栈实参 [sp+0x30]=self [sp+0x34]=other
 * 调用点: 只有 DoCall 的三处（脚本路 @0xe8c3c、kind5 带 arguments @0xe8fa4、kind5 无 @0xe9068），
 *         与 batchD「唯一压帧入口」结论一致 —— 本卡把它逐字落到了帧字段上。
 *
 * ── 出口一览（全部只三条）────────────────────────────────────────────
 *   A scr==0        → VMError(exec, "call to non-existent script\n") 后**继续**执行（@0xe89c0/@0xe89d0）
 *   B code[0x50]==0 → 压一个全零 RValue，返回 sp-16（@0xe8978）—— 只写 +0/+8/+12，+4 不清
 *   C 正常           → 返回 frame = sp-60（@0xe87e8）
 *   （除这三处外没有别的 return）
 *
 * ── 值栈：全局 Argument + 1024 字节余量 ───────────────────────────────
 *   Argument（0x47a170）是「当前实参区首槽」指针：@0xe85ec 先把 sp 写进去，旧值留在 r12
 *   （= 调用者的实参区首槽）。sp 与栈基址 exec[0x08] 距离不足 1024 B 时走搬家：
 *   Alloc(limit+16384, "…/Files/Code/VM_Exec.cpp", 0x837, 1) → memcpy 到新基址+16384
 *   → exec[0x08]/exec[0x28]/Argument/sp 全部按 offset 重定位 → exec[0x40] += 16384
 *   → 旧 sp 若落在 stackPages 的页内则做一次四字记账，否则 MemoryManager::Free(旧 sp) → 回到压帧。
 *   搬运前后一律用「相对基址的偏移」表达指针（frame+0x38 = 旧 *Argument - 基址），这是本函数
 *   能在搬家后继续压帧的原因。
 *
 * ── 帧格式（frame = sp-60，15 字写 14 个，+0x34 是空槽）──────────────
 *   +0x00 ← exec[0x44]  pc/返回地址        +0x04 ← exec[0x30]
 *   +0x08 ← g_ArgumentCount                +0x0c ← oldFrame==0 ? -1 : (基址+exec[0x40]-oldFrame)
 *   +0x10 ← exec[0x14] env1                +0x14 ← exec[0x18] env2
 *   +0x18 ← exec[0x2c]（旧 blob）           +0x1c ← exec[0x38]
 *   +0x20 ← exec[0x3c]                     +0x24 ← exec[0x34]
 *   +0x28 ← 0（PerformReturn 会 operator delete 它）+0x2c ← exec[0x0c]
 *   +0x30 ← exec[0x10]                     +0x38 ← 旧 *Argument - 基址
 *   与 PerformReturn 的 14 次读回**逐字段一一对应**（它的读清单正好是除 +0x34 以外的 14 个字）：
 *     +0→exec[0x44] +4→exec[0x50] +8→g_ArgumentCount +0xc→exec[0x28](解码) +0x10→exec[0x14]
 *     +0x14→exec[0x18] +0x18→exec[0x2c] +0x1c→exec[0x38] +0x20→exec[0x3c] +0x24→exec[0x24]
 *     +0x28→operator delete（本函数恒写 0）  +0x2c→exec[0x0c] +0x30→exec[0x10] +0x38→*Argument
 *   ⇒ 帧格式闭合，压/弹两侧互证；-1 表示"没有上一层帧"（PerformReturn 用 movlt 归 0）。
 *
 * ── 进入码（把 exec 从调用者切到被调脚本）────────────────────────────
 *   code = scr->GetCode()（CScript::GetCode 0x1dfba8，本函数调 3 次）
 *   blob = code[0x50]；VMBuffer::convertBuffer(blob) 之后再取表
 *   exec[0x44]=code[0x6c]（入口 pc）      exec[0x24]=blob[0x10]（字节码基址）
 *   exec[0x50]=blob[0x04]                 exec[0x58]=blob[0x14]（处理器表）
 *   exec[0x5c]=blob[0x18]（表基址）        exec[0x48]=blob[0x18][pc/4]（当前表项）
 *   exec[0x38]=code[0x54] exec[0x3c]=code[0x58] exec[0x34]=code[0x5c]
 *   exec[0x2c]=blob  exec[0x30]=0  exec[0x28]=frame  g_ArgumentCount=argc
 *   最后 ++exec[0x4c]（帧深度），g_bProfile 非 0 时 CProfiler::Push(&g_Profiler, 1, code[0x60])。
 *
 * ── 两个 self/other 分支（由 code[0x78] & 4 选）──────────────────────
 *   flags&4 == 0（@0xe87f4）：exec[0xc]=1、exec[0x10]=self；
 *   flags&4 != 0（@0xe8728）：exec[0xc]=1、exec[0x10]=0；
 *   两者之后同一段：g_fJSGarbageCollection 非 0 且 self 非 0 时
 *     PushContextStack(self 或 0) → r6 = self[0x04]（实例变量槽数组首槽），为 0 则 InternalGetYYVar(1)
 *     → 按旧 tag 释放（tag1 走 _RefThing 引用计数 + YYFree + delete，tag2 走 FREE_RValue__Pre）
 *     → 写 {+0=other, +8=5, +0xc=tag6} → DeterminePotentialRoot(GetContextStackTop(), other) → PopContextStack()
 *   ⇒ **other 被绑进 self 的变量槽（tag 6 = 对象）**，并在 GC 开关下登记为潜在根。
 *   flags&4 那支把 exec[0x10] 清 0 后紧接着当指针解引用（@0xe8730 存、@0xe875c 读、@0xe8760 取 [r0+4]），
 *   若该支可达会空指针崩溃 —— 见 open。
 *
 * 结论（新增五条硬事实）:
 *   1. 帧 60 B 的 15 个字里 14 个字段由本函数写入，PerformReturn 恰好读回同一批 14 个字，+0x34 两侧都不用。
 *   2. frame+0x0c 不是指针而是「基址+上限-旧帧」的编码，-1 = 无上层帧；PerformReturn 用基址+上限-d 还原。
 *   3. g_ArgumentCount/Argument 是一对：前者=当前实参个数（帧 +0x08 保存、返回时恢复），
 *      后者=当前实参区首槽（帧 +0x38 以偏移形式保存、返回时恢复）。
 *   4. 一次调用把 code 的十个字段搬进 exec（+0x24/+0x2c/+0x34/+0x38/+0x3c/+0x44/+0x48/+0x50/+0x58/+0x5c），
 *      字节码基址在 exec[0x24]、pc 在 exec[0x44]、处理器表在 exec[0x58] —— 与 DoBreak 的取指段完全一致。
 *   5. 返回值是 frame 本身（不是 sp）；被调脚本跑完后由 PerformReturn 给回 frame+60(+argc*16)。
 * open:
 *   1. 栈搬家段（@0xe882c..@0xe89bc）里 stackPages 的四字记账（+8/+0xc/+0x10 三个计数、0x100000 页跨度）
 *      与 16384 增量不同量级，只做了逐字搬运，语义未证。
 *   2. flags&4 分支在 g_fJSGarbageCollection && self 时会解引用刚清 0 的 exec[0x10]（原版死代码？）。
 *   3. 「实例变量槽数组首槽」与 InternalGetYYVar(1) 的编号不一致（0 vs 1），两者是否同一变量未证。
 *   4. code[0x54]/[0x58]/[0x5c]/[0x60]/[0x6c]/[0x78] 之外的 CScript 字段含义。
 *   5. 为何 argc 只写进 g_ArgumentCount 而本函数不消费它（消费方是 PerformReturn 的实参释放循环）。
 */

/* ── 序：r8=scr r11=argc r5=sp r4=exec；r7=GOT 基址 ── */
/* @0xe8588 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe858c subs r8, r0, #0 */
/* @0xe8590 ldr r7, [pc, #0x538] */
/* @0xe8594 sub sp, sp, #12 */
/* @0xe8598 mov r11, r1 */
/* @0xe859c mov r5, r2 */
/* @0xe85a0 mov r4, r3 */
/* @0xe85a4 add r7, pc, r7 */
/* @0xe85a8 beq 0xe89c0 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x438> */

/* ── code = scr->GetCode()；code[0x50]==0 → 压全零 RValue 返回 sp-16（早退 B） ── */
/* @0xe85ac mov r0, r8 */
/* @0xe85b0 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe85b4 ldr r3, [r0, #0x50] */
/* @0xe85b8 cmp r3, #0 */
/* @0xe85bc beq 0xe8978 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3f0> */

/* ── g_fVMTrace 非 0 → 调试控制台打印 script call = %s（追踪旁路） ── */
/* @0xe85c0 ldr r3, [pc, #0x50c] */
/* @0xe85c4 ldr r3, [r7, r3] */
/* @0xe85c8 ldrb r3, [r3] */
/* @0xe85cc cmp r3, #0 */
/* @0xe85d0 bne 0xe88fc <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x374> */

/* ── 值栈顶全局 Argument：*Argument = sp；距栈基址不足 1024 B → 搬家 ── */
/* @0xe85d4 ldr r3, [pc, #0x4fc] */
/* @0xe85d8 ldr r6, [r4, #0x8] */
/* @0xe85dc ldr r9, [r7, r3] */
/* @0xe85e0 add r3, r6, #1024 */
/* @0xe85e4 cmp r5, r3 */
/* @0xe85e8 ldr r12, [r9] */
/* @0xe85ec str r5, [r9] */
/* @0xe85f0 blo 0xe882c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x2a4> */

/* ── ★帧构建：frame = sp-60，15 个字写 14 个（+0x34 空槽） ── */
/* @0xe85f4 ldr r3, [r4, #0x28] */
/* @0xe85f8 ldr lr, [r4, #0x14] */
/* @0xe85fc cmp r3, #0 */
/* @0xe8600 ldr r0, [r4, #0x18] */
/* @0xe8604 sub r9, r5, #60 */
/* @0xe8608 ldr r1, [r4, #0x44] */
/* @0xe860c ldr r2, [r4, #0x2c] */
/* @0xe8610 ldr r10, [r4, #0x3c] */
/* @0xe8614 str lr, [r5, #-0x2c] */
/* @0xe8618 ldr lr, [r4, #0x38] */
/* @0xe861c str r0, [r5, #-0x28] */
/* @0xe8620 ldr r0, [r4, #0x34] */
/* @0xe8624 str r1, [r5, #-0x3c] */
/* @0xe8628 ldr r1, [r4, #0x30] */
/* @0xe862c str lr, [r5, #-0x20] */
/* @0xe8630 mvneq lr, #0 */
/* @0xe8634 ldrne lr, [r4, #0x40] */
/* @0xe8638 str r2, [r5, #-0x24] */
/* @0xe863c addne lr, r6, lr */
/* @0xe8640 ldr r2, [r4, #0xc] */
/* @0xe8644 rsbne lr, r3, lr */
/* @0xe8648 str r1, [r5, #-0x38] */
/* @0xe864c ldr r3, [pc, #0x488] */
/* @0xe8650 rsb r6, r6, r12 */
/* @0xe8654 ldr r1, [r4, #0x10] */
/* @0xe8658 str r10, [r5, #-0x1c] */
/* @0xe865c mov r10, #0 */
/* @0xe8660 str r0, [r5, #-0x18] */
/* @0xe8664 mov r0, r8 */
/* @0xe8668 str lr, [r5, #-0x30] */
/* @0xe866c str r1, [r5, #-0xc] */
/* @0xe8670 str r2, [r5, #-0x10] */
/* @0xe8674 str r10, [r5, #-0x14] */
/* @0xe8678 ldr r3, [r7, r3] */
/* @0xe867c ldr r2, [r3] */
/* @0xe8680 str r6, [r5, #-0x4] */
/* @0xe8684 str r2, [r5, #-0x34] */
/* @0xe8688 str r3, [sp, #0x4] */

/* ── 进入码：blob/code 的十个字段搬进 exec，并 ++帧深度前的准备 ── */
/* @0xe868c bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8690 ldr r6, [r0, #0x50] */
/* @0xe8694 mov r5, r0 */
/* @0xe8698 ldr r12, [r0, #0x6c] */
/* @0xe869c ldr lr, [r0, #0x54] */
/* @0xe86a0 ldr r1, [r6, #0x10] */
/* @0xe86a4 mov r0, r6 */
/* @0xe86a8 ldr r2, [r6, #0x4] */
/* @0xe86ac str r12, [r4, #0x44] */
/* @0xe86b0 ldr r12, [r5, #0x58] */
/* @0xe86b4 str r1, [r4, #0x24] */
/* @0xe86b8 ldr r1, [r5, #0x5c] */
/* @0xe86bc str r2, [r4, #0x50] */
/* @0xe86c0 str lr, [r4, #0x38] */
/* @0xe86c4 str r12, [r4, #0x3c] */
/* @0xe86c8 str r1, [r4, #0x34] */
/* @0xe86cc str r6, [r4, #0x2c] */
/* @0xe86d0 str r10, [r4, #0x30] */
/* @0xe86d4 str r9, [r4, #0x28] */
/* @0xe86d8 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */
/* @0xe86dc ldr r2, [r4, #0x44] */
/* @0xe86e0 ldr r1, [r4, #0x2c] */
/* @0xe86e4 mov r0, r8 */
/* @0xe86e8 cmp r2, r10 */
/* @0xe86ec add lr, r2, #3 */
/* @0xe86f0 ldr r12, [r6, #0x14] */
/* @0xe86f4 ldr r1, [r1, #0x18] */
/* @0xe86f8 movlt r2, lr */
/* @0xe86fc asr r2, r2, #2 */
/* @0xe8700 ldr r3, [sp, #0x4] */
/* @0xe8704 str r12, [r4, #0x58] */
/* @0xe8708 ldr r2, [r1, r2, lsl #2] */
/* @0xe870c str r1, [r4, #0x5c] */
/* @0xe8710 str r11, [r3] */
/* @0xe8714 str r2, [r4, #0x48] */
/* @0xe8718 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */

/* ── flags(=[code+0x78]) & 4 分流：exec[0x10] = self（不置位）/ 0（置位） ── */
/* @0xe871c ldr r3, [r0, #0x78] */
/* @0xe8720 tst r3, #4 */
/* @0xe8724 beq 0xe87f4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x26c> */
/* @0xe8728 ldr r3, [pc, #0x3b0] */
/* @0xe872c mov r2, #1 */
/* @0xe8730 str r10, [r4, #0x10] */
/* @0xe8734 str r2, [r4, #0xc] */
/* @0xe8738 ldr r3, [r7, r3] */
/* @0xe873c ldrb r3, [r3] */
/* @0xe8740 cmp r3, r10 */
/* @0xe8744 beq 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8748 ldr r3, [sp, #0x30] */
/* @0xe874c cmp r3, #0 */
/* @0xe8750 movne r0, r10 */
/* @0xe8754 beq 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8758 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe875c ldr r0, [r4, #0x10] */
/* @0xe8760 ldr r6, [r0, #0x4] */
/* @0xe8764 cmp r6, #0 */
/* @0xe8768 beq 0xe8a30 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4a8> */
/* @0xe876c ldr r2, [r6, #0xc] */
/* @0xe8770 bic r3, r2, #-16777216 */
/* @0xe8774 cmp r3, #1 */
/* @0xe8778 beq 0xe8944 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3bc> */
/* @0xe877c cmp r3, #2 */
/* @0xe8780 bne 0xe8798 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x210> */
/* @0xe8784 sub r3, r2, #1 */
/* @0xe8788 bic r3, r3, #-16777216 */
/* @0xe878c bic r3, r3, #3 */
/* @0xe8790 cmp r3, #0 */
/* @0xe8794 beq 0xe8a0c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x484> */

/* ── 把 other 绑进 self 的变量槽：写 {+0=other, +8=5, +0xc=tag6} ── */
/* @0xe8798 ldr r1, [sp, #0x34] */
/* @0xe879c mov r2, #6 */
/* @0xe87a0 mov r3, #5 */
/* @0xe87a4 str r2, [r6, #0xc] */
/* @0xe87a8 cmp r1, #0 */
/* @0xe87ac str r3, [r6, #0x8] */
/* @0xe87b0 str r1, [r6] */
/* @0xe87b4 beq 0xe87c4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x23c> */
/* @0xe87b8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe87bc ldr r1, [sp, #0x34] */
/* @0xe87c0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe87c4 bl 0xd3a34 <_Z15PopContextStackv> */

/* ── 收尾：++exec[0x4c] 帧深度 → g_bProfile ? CProfiler::Push → 返回 frame ── */
/* @0xe87c8 ldr r3, [pc, #0x314] */
/* @0xe87cc ldr r2, [r4, #0x4c] */
/* @0xe87d0 add r2, r2, #1 */
/* @0xe87d4 str r2, [r4, #0x4c] */
/* @0xe87d8 ldr r3, [r7, r3] */
/* @0xe87dc ldrb r3, [r3] */
/* @0xe87e0 cmp r3, #0 */
/* @0xe87e4 bne 0xe8924 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x39c> */
/* @0xe87e8 mov r0, r9 */
/* @0xe87ec add sp, sp, #12 */
/* @0xe87f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe87f4 ldr r1, [sp, #0x30] */
/* @0xe87f8 cmp r1, #0 */
/* @0xe87fc beq 0xe8a18 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x490> */
/* @0xe8800 ldr r3, [pc, #0x2d8] */
/* @0xe8804 mov r2, #1 */
/* @0xe8808 ldr r1, [sp, #0x30] */
/* @0xe880c str r2, [r4, #0xc] */
/* @0xe8810 str r1, [r4, #0x10] */
/* @0xe8814 ldr r3, [r7, r3] */
/* @0xe8818 ldrb r3, [r3] */
/* @0xe881c cmp r3, #0 */
/* @0xe8820 beq 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8824 ldr r0, [sp, #0x30] */
/* @0xe8828 b 0xe8758 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x1d0> */

/* ── 栈搬家：Alloc(上限+16384) + memcpy 到新基址+16384 + 全量重定位 ── */
/* @0xe882c ldr r0, [r4, #0x40] */
/* @0xe8830 mov r3, #1 */
/* @0xe8834 ldr r1, [pc, #0x2ac] */
/* @0xe8838 movw r2, #0x837 */
/* @0xe883c add r0, r0, #16384 */
/* @0xe8840 str r12, [sp, #0x4] */
/* @0xe8844 add r1, pc, r1 */
/* @0xe8848 rsb r5, r6, r5 */
/* @0xe884c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe8850 mov r1, r6 */
/* @0xe8854 ldr r2, [r4, #0x40] */
/* @0xe8858 add r5, r5, #16384 */
/* @0xe885c str r0, [r4, #0x8] */
/* @0xe8860 add r0, r0, #16384 */
/* @0xe8864 bl 0xb65bc <memcpy@plt> */
/* @0xe8868 ldr r3, [r4, #0x28] */
/* @0xe886c ldr r0, [r9] */
/* @0xe8870 ldr r1, [pc, #0x274] */
/* @0xe8874 rsb r3, r6, r3 */
/* @0xe8878 ldr r2, [r4, #0x8] */
/* @0xe887c add r3, r3, #16384 */
/* @0xe8880 ldr lr, [r4, #0x40] */
/* @0xe8884 rsb r0, r6, r0 */
/* @0xe8888 add r3, r2, r3 */
/* @0xe888c add r0, r2, r0 */
/* @0xe8890 str r3, [r4, #0x28] */
/* @0xe8894 add lr, lr, #16384 */
/* @0xe8898 str r0, [r9] */
/* @0xe889c add r5, r2, r5 */
/* @0xe88a0 str lr, [r4, #0x40] */
/* @0xe88a4 ldr r9, [r7, r1] */
/* @0xe88a8 ldr r12, [sp, #0x4] */
/* @0xe88ac ldr r1, [r9, #0x4] */
/* @0xe88b0 cmp r1, #0 */
/* @0xe88b4 beq 0xe88e0 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x358> */
/* @0xe88b8 add lr, r1, #8 */
/* @0xe88bc add r0, r1, #1048576 */
/* @0xe88c0 cmp r6, lr */
/* @0xe88c4 add r0, r0, #8 */
/* @0xe88c8 blo 0xe88d4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x34c> */
/* @0xe88cc cmp r0, r6 */
/* @0xe88d0 bhi 0xe8994 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x40c> */
/* @0xe88d4 ldr r1, [r1] */
/* @0xe88d8 cmp r1, #0 */
/* @0xe88dc bne 0xe88b8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x330> */
/* @0xe88e0 mov r0, r6 */
/* @0xe88e4 str r12, [sp, #0x4] */
/* @0xe88e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xe88ec ldr r3, [r4, #0x28] */
/* @0xe88f0 ldr r6, [r4, #0x8] */
/* @0xe88f4 ldr r12, [sp, #0x4] */
/* @0xe88f8 b 0xe85f8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x70> */

/* ── VMTrace：全局指针 dbg_csol(0x3eb70c) 所指对象的 vtable[3](对象, "script call = %s\n", code[0x14]) ── */
/* @0xe88fc ldr r3, [pc, #0x1ec] */
/* @0xe8900 ldr r1, [pc, #0x1ec] */
/* @0xe8904 ldr r2, [r8, #0x14] */
/* @0xe8908 ldr r3, [r7, r3] */
/* @0xe890c add r1, pc, r1 */
/* @0xe8910 ldr r0, [r3] */
/* @0xe8914 ldr r3, [r0] */
/* @0xe8918 ldr r3, [r3, #0xc] */
/* @0xe891c blx r3 */
/* @0xe8920 b 0xe85d4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4c> */
/* @0xe8924 ldr r3, [pc, #0x1cc] */
/* @0xe8928 mov r1, #1 */
/* @0xe892c ldr r2, [r5, #0x60] */
/* @0xe8930 ldr r0, [r7, r3] */
/* @0xe8934 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xe8938 mov r0, r9 */
/* @0xe893c add sp, sp, #12 */
/* @0xe8940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 旧值释放链（tag 1 字符串：引用计数 → YYFree → delete） ── */
/* @0xe8944 ldr r8, [r6] */
/* @0xe8948 cmp r8, #0 */
/* @0xe894c beq 0xe896c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3e4> */
/* @0xe8950 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8954 ldr r10, [r8, #0x4] */
/* @0xe8958 sub r10, r10, #1 */
/* @0xe895c str r10, [r8, #0x4] */
/* @0xe8960 cmp r10, #0 */
/* @0xe8964 beq 0xe89d4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x44c> */
/* @0xe8968 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe896c mov r3, #0 */
/* @0xe8970 str r3, [r6] */
/* @0xe8974 b 0xe8798 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x210> */
/* @0xe8978 sub r9, r5, #16 */
/* @0xe897c str r3, [r5, #-0x4] */
/* @0xe8980 str r3, [r5, #-0x10] */
/* @0xe8984 mov r0, r9 */
/* @0xe8988 str r3, [r5, #-0xc] */
/* @0xe898c add sp, sp, #12 */
/* @0xe8990 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8994 ldr lr, [r9, #0x8] */
/* @0xe8998 ldr r0, [r9, #0x10] */
/* @0xe899c ldr r1, [r9, #0xc] */
/* @0xe89a0 add r0, r0, #1 */
/* @0xe89a4 str lr, [r6] */
/* @0xe89a8 sub r1, r1, #1 */
/* @0xe89ac str r6, [r9, #0x8] */
/* @0xe89b0 str r0, [r9, #0x10] */
/* @0xe89b4 mov r6, r2 */
/* @0xe89b8 str r1, [r9, #0xc] */
/* @0xe89bc b 0xe85f8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x70> */

/* ── scr==0 的 VMError（报错后仍继续执行，会崩） ── */
/* @0xe89c0 ldr r1, [pc, #0x134] */
/* @0xe89c4 mov r0, r3 */
/* @0xe89c8 add r1, pc, r1 */
/* @0xe89cc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe89d0 b 0xe85ac <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x24> */
/* @0xe89d4 ldr r0, [r8] */
/* @0xe89d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe89dc str r10, [r8] */
/* @0xe89e0 str r10, [r8, #0x8] */
/* @0xe89e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe89e8 ldr r10, [r8, #0x4] */
/* @0xe89ec sub r10, r10, #1 */
/* @0xe89f0 str r10, [r8, #0x4] */
/* @0xe89f4 cmp r10, #0 */
/* @0xe89f8 beq 0xe8a40 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4b8> */
/* @0xe89fc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8a00 mov r0, r8 */
/* @0xe8a04 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8a08 b 0xe8968 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3e0> */
/* @0xe8a0c mov r0, r6 */
/* @0xe8a10 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8a14 b 0xe8798 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x210> */
/* @0xe8a18 ldr r0, [r5, #0x70] */
/* @0xe8a1c bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0xe8a20 ldr r3, [sp, #0x30] */
/* @0xe8a24 str r3, [r4, #0xc] */
/* @0xe8a28 str r0, [r4, #0x10] */
/* @0xe8a2c b 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8a30 mov r1, r6 */
/* @0xe8a34 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe8a38 mov r6, r0 */
/* @0xe8a3c b 0xe876c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x1e4> */
/* @0xe8a40 ldr r0, [r8] */
/* @0xe8a44 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8a48 str r10, [r8] */
/* @0xe8a4c str r10, [r8, #0x8] */
/* @0xe8a50 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8a54 ldr r10, [r8, #0x4] */
/* @0xe8a58 sub r10, r10, #1 */
/* @0xe8a5c str r10, [r8, #0x4] */
/* @0xe8a60 cmp r10, #0 */
/* @0xe8a64 beq 0xe8a78 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4f0> */
/* @0xe8a68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8a6c mov r0, r8 */
/* @0xe8a70 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8a74 b 0xe89fc <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x474> */
/* @0xe8a78 ldr r0, [r8] */
/* @0xe8a7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8a80 str r10, [r8] */
/* @0xe8a84 str r10, [r8, #0x8] */
/* @0xe8a88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8a8c ldr r10, [r8, #0x4] */
/* @0xe8a90 sub r10, r10, #1 */
/* @0xe8a94 str r10, [r8, #0x4] */
/* @0xe8a98 cmp r10, #0 */
/* @0xe8a9c bne 0xe8ac0 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x538> */
/* @0xe8aa0 ldr r0, [r8] */
/* @0xe8aa4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8aa8 mov r0, r8 */
/* @0xe8aac str r10, [r8] */
/* @0xe8ab0 str r10, [r8, #0x8] */
/* @0xe8ab4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe8ab8 mov r0, r8 */
/* @0xe8abc bl 0x27d1d0 <_ZdlPv> */
/* @0xe8ac0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8ac4 mov r0, r8 */
/* @0xe8ac8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8acc b 0xe8a68 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4e0> */

/* ── 以下 12 字是 literal pool（GOT 偏移与字符串偏移），objdump 译成指令，非指令 ── */
/* @0xe8ad0 eorseq r9, r0, r12, lsr #13 */
/* @0xe8ad4 .word 0xffffc100 */
/* @0xe8ad8 .word 0xffffc0c0 */
/* @0xe8adc .word 0xffffc0bc */
/* @0xe8ae0 .word 0xffffbf68 */
/* @0xe8ae4 .word 0xffffbf18 */
/* @0xe8ae8 eoreq r9, r4, r8, lsr pc */
/* @0xe8aec .word 0xffffc0e4 */
/* @0xe8af0 .word 0xffffbac4 */
/* @0xe8af4 eoreq r11, r4, r12, lsr #30 */
/* @0xe8af8 .word 0xffffbf1c */
/* @0xe8afc eoreq r11, r4, r0, asr lr */
