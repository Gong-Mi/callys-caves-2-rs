/* cally 逆向卡：DoBreak（原版 libyoyo.so，armv7）
 * @func 0xd8434 0xd8660  size 560  140 条（0xd8638..0xd8660 为 literal pool，11 字，非指令）
 * 级别: 骨架（三态分派、断点记录布局、内存补丁、单步派发全证；条件求值链与 DebuggerMessageLoop 内部未展开）
 * 符号: _Z7DoBreakjhPhPKhP6VMExecb
 *       → uchar* DoBreak(uint32 arg, uchar unused, uchar* sp, const uchar* base, VMExec* exec, bool rewind)
 * 实参: r0=arg(r7=uxth) r1=**从未读取**（死参数） r2=sp(r4，返回值) r3=base
 *       栈实参 [sp+0x38]=exec(r5) [sp+0x3c]=rewind(r8，按字节读)
 *
 * ── 按 arg 低 16 位三态（uxth，不做符号扩展）──────────────────────────
 *   n == 0      → 断点命中/单步路：本函数唯一有副作用的分支
 *   n == 0xFFFF → 数组下标守卫：*(int*)base 必须 0 <= v < 32000，否则
 *                 v<0 → VMError(exec, "Array index must be positive")
 *                 v>=32000 → VMError(exec, "Array index must be < %d", 32000)
 *                 校验通过（或报错后）都**原样返回 sp**
 *   其它        → 原样返回 sp（纯 no-op）
 *
 * ── 断点机制（本卡新增的硬事实）──────────────────────────────────────
 *   VM::WriteBreakpointsToMemory 把每个断点地址的首字写成 0xFFFF0000（mov #0 + movt #0xffff）；
 *   VM::ClearBreakpointsFromMemory 用记录 +0x00 保存的原指令字恢复。
 *   VM::m_breakpoints 是 256 项 × 16 B = 4096 B 的数组（ResetBreakpoints 的循环 0..4096 步 16 可证），
 *   记录布局 { +0x00 原指令字, +0x04 地址(+4 == -1 表示空项), +0x08 条件长度, +0x0c 条件字节指针 }。
 *   ⇒ 补丁字 0xFFFF0000 的 uxth 正好是 0，落进本函数的单步路；arg 的最高字节是 0xFF 也是这个字的指纹
 *     （DoPopNull 用 arg>>24 == 0xFF 判「带断点前缀」，同源）。
 *
 * ── 单步路（n == 0）的完整骨架 ───────────────────────────────────────
 *   if (g_isZeus)                                  ; 0x5428e8：调试器（Zeus）在线标志
 *       bp = VM::GetBreakpoint(码基址 + pc - 4)     ; 线性扫 256 项比 +0x04
 *       hit = (bp != 0 && bp[0x0c] == 0)            ; 无条件断点直接命中
 *       否则 new(64) 一个 Buffer_Standard（IBuffer ctor 后手写 vptr = _ZTV15Buffer_Standard+8），
 *         喂 { 条件字指针 = bp[0x0c], 长度 = bp[0x08] } 给 Debug_ExecuteBreakCondition，
 *         结果双精度落在栈上 sp+8，> 0.5 记为命中（否则 r7=0 = 未命中）
 *   if (Code_Error_Occured != 0) 直接当命中，不再求值
 *   命中 → CProfiler::Pause(&g_Profiler, true) →（rewind 为真时 pc -= 4）→ ClearBreakpointsFromMemory()
 *         → *g_pServer ? DebuggerMessageLoop() → 取指并单步
 *   未命中 → 跳过 Pause，直接（同样按 rewind 回退 pc）→ ClearBreakpointsFromMemory() → 取指并单步
 *   取指单步（@0xd84cc）：
 *     码基址 = exec[0x24]，pc = exec[0x44]，word = *(uint32*)(码基址+pc)，pc += 4；
 *     word 位 30 → pc += g_paramSize[bits19:16]（g_paramSize 是 .data 里的 16 项表）；
 *     *g_pCurrentExec = exec；blx g_instructions[bits28:24](word, sp, 码基址+pc_after, exec)；
 *     *g_pCurrentExec = exec；WriteBreakpointsToMemory()；返回 handler 给的新 sp。
 *     base 正好指在 opcode 字之后 —— 与全部 DoXxx 的 (arg, sp, base, exec) 约定字字对上。
 *   ⇒ DoBreak 本质是「被补丁进去的 0xFFFF0000 的处理器」：先撤补丁、单步执行一条原指令、再打回补丁。
 *
 * 结论（新增四条硬事实）:
 *   1. arg 低 16 位是唯一的分派依据，三态（0 / 0xFFFF / 其它）；第 2 实参 uchar 全程未被读。
 *   2. 断点补丁字 = 0xFFFF0000，记录 16 B 四项，表 256 项；这就是「arg 最高字节 0xFF」的来历。
 *   3. 处理器表不在 exec 里而是全局 g_instructions，索引取 bits28:24（5 位），与 DoCallScript 的
 *      per-script 表 exec[0x58] 是两套（本函数走全局表）。
 *   4. g_paramSize[kind] 是位 30 附带的内联参数字节数（kind = bits19:16），这一步只有本函数做。
 * open:
 *   1. Debug_ExecuteBreakCondition 的符号名只声明了一个 Buffer_Standard 实参，实际调用传了两路（结果 + 条件缓冲），
 *      0.5 阈值的语义（条件为真/假）与双精度结果的编码未证。
 *   2. DebuggerMessageLoop / g_pServer 的交互（命中后是否阻塞到 UI 返回）。
 *   3. Code_Error_Occured 已被置位时为何仍走"命中"（错误态下强制暂停？）。
 *   4. rewind 为真时 pc 回退 4 字节会让单步执行「刚被取指的那条」；若那条正是 0xFFFF0000 会自我重入，
 *      只有 n != 0 被提前返回挡住 —— 原版是否依赖这一点未证。
 *   5. g_isZeus 之外是否还有别的调试开关（本函数只读这一个字节）。
 */

/* ── 序：r7=uxth(arg)；r4=sp（返回值）r5=exec r8=bool；r1 全程未读 ── */
/* @0xd8434 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xd8438 uxth r7, r0 */
/* @0xd843c sub sp, sp, #24 */
/* @0xd8440 ldr r6, [pc, #0x1f0] */
/* @0xd8444 cmp r7, #0 */
/* @0xd8448 mov r4, r2 */
/* @0xd844c add r6, pc, r6 */
/* @0xd8450 ldr r5, [sp, #0x38] */
/* @0xd8454 ldrb r8, [sp, #0x3c] */

/* ── 三态分派：0 → 单步路；0xFFFF → 数组下标守卫；其它 → 原样返回 sp ── */
/* @0xd8458 beq 0xd8488 <_Z7DoBreakjhPhPKhP6VMExecb+0x54> */
/* @0xd845c movw r3, #0xffff */
/* @0xd8460 cmp r7, r3 */
/* @0xd8464 bne 0xd847c <_Z7DoBreakjhPhPKhP6VMExecb+0x48> */
/* @0xd8468 ldr r3, [r2] */
/* @0xd846c cmp r3, #0 */
/* @0xd8470 blt 0xd8624 <_Z7DoBreakjhPhPKhP6VMExecb+0x1f0> */
/* @0xd8474 cmp r3, #32000 */
/* @0xd8478 bge 0xd8560 <_Z7DoBreakjhPhPKhP6VMExecb+0x12c> */
/* @0xd847c mov r0, r4 */
/* @0xd8480 add sp, sp, #24 */
/* @0xd8484 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 单步路：g_isZeus 分流（离线 = 直接单步） ── */
/* @0xd8488 ldr r3, [pc, #0x1ac] */
/* @0xd848c ldr r3, [r6, r3] */
/* @0xd8490 ldrb r3, [r3] */
/* @0xd8494 cmp r3, #0 */
/* @0xd8498 bne 0xd8580 <_Z7DoBreakjhPhPKhP6VMExecb+0x14c> */

/* ── 命中：CProfiler::Pause + 可能回退 pc + 撤补丁 + 调试消息循环 ── */
/* @0xd849c ldr r3, [pc, #0x19c] */
/* @0xd84a0 mov r1, #1 */
/* @0xd84a4 mov r7, r1 */
/* @0xd84a8 ldr r0, [r6, r3] */
/* @0xd84ac bl 0x2a04b8 <_ZN9CProfiler5PauseEb> */
/* @0xd84b0 cmp r8, #0 */
/* @0xd84b4 ldrne r3, [r5, #0x44] */
/* @0xd84b8 subne r3, r3, #4 */
/* @0xd84bc strne r3, [r5, #0x44] */
/* @0xd84c0 bl 0xd8404 <_ZN2VM26ClearBreakpointsFromMemoryEv> */
/* @0xd84c4 cmp r7, #0 */
/* @0xd84c8 bne 0xd8544 <_Z7DoBreakjhPhPKhP6VMExecb+0x110> */

/* ── 取指单步：全局 g_instructions[bits28:24] 派发一条指令后重新打补丁 ── */
/* @0xd84cc ldr r1, [r5, #0x44] */
/* @0xd84d0 ldr r2, [r5, #0x24] */
/* @0xd84d4 ldr r12, [pc, #0x168] */
/* @0xd84d8 add r3, r1, #4 */
/* @0xd84dc ldr r0, [r2, r1] */
/* @0xd84e0 add r2, r2, r3 */
/* @0xd84e4 str r3, [r5, #0x44] */
/* @0xd84e8 ldr r7, [r6, r12] */
/* @0xd84ec tst r0, #1073741824 */
/* @0xd84f0 str r5, [r7] */
/* @0xd84f4 beq 0xd8510 <_Z7DoBreakjhPhPKhP6VMExecb+0xdc> */
/* @0xd84f8 ldr r1, [pc, #0x148] */
/* @0xd84fc ubfx r12, r0, #0x10, #0x4 */
/* @0xd8500 ldr r1, [r6, r1] */
/* @0xd8504 ldr r1, [r1, r12, lsl #2] */
/* @0xd8508 add r3, r3, r1 */
/* @0xd850c str r3, [r5, #0x44] */
/* @0xd8510 ldr r12, [pc, #0x134] */
/* @0xd8514 ubfx lr, r0, #0x18, #0x5 */
/* @0xd8518 mov r1, r4 */
/* @0xd851c mov r3, r5 */
/* @0xd8520 ldr r12, [r6, r12] */
/* @0xd8524 ldr r12, [r12, lr, lsl #2] */
/* @0xd8528 blx r12 */
/* @0xd852c str r5, [r7] */
/* @0xd8530 mov r4, r0 */
/* @0xd8534 bl 0xd83cc <_ZN2VM24WriteBreakpointsToMemoryEv> */
/* @0xd8538 mov r0, r4 */
/* @0xd853c add sp, sp, #24 */
/* @0xd8540 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 命中后轮询调试服务器（g_pServer != 0 → DebuggerMessageLoop） ── */
/* @0xd8544 ldr r3, [pc, #0x104] */
/* @0xd8548 ldr r3, [r6, r3] */
/* @0xd854c ldr r3, [r3] */
/* @0xd8550 cmp r3, #0 */
/* @0xd8554 beq 0xd84cc <_Z7DoBreakjhPhPKhP6VMExecb+0x98> */
/* @0xd8558 bl 0x29d634 <_Z19DebuggerMessageLoopv> */
/* @0xd855c b 0xd84cc <_Z7DoBreakjhPhPKhP6VMExecb+0x98> */

/* ── 下标守卫的两条 VMError（负 / >= 32000） ── */
/* @0xd8560 ldr r1, [pc, #0xec] */
/* @0xd8564 mov r0, r5 */
/* @0xd8568 mov r2, #32000 */
/* @0xd856c add r1, pc, r1 */
/* @0xd8570 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd8574 mov r0, r4 */
/* @0xd8578 add sp, sp, #24 */
/* @0xd857c pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 断点记录查询（VM::GetBreakpoint）与条件求值（Buffer_Standard + 双精度阈值 0.5） ── */
/* @0xd8580 ldr r3, [r5, #0x44] */
/* @0xd8584 ldr r0, [r5, #0x24] */
/* @0xd8588 sub r3, r3, #4 */
/* @0xd858c add r0, r0, r3 */
/* @0xd8590 bl 0xd82ec <_ZN2VM13GetBreakpointEPj> */
/* @0xd8594 subs r9, r0, #0 */
/* @0xd8598 beq 0xd849c <_Z7DoBreakjhPhPKhP6VMExecb+0x68> */
/* @0xd859c ldr r3, [r9, #0xc] */
/* @0xd85a0 cmp r3, #0 */
/* @0xd85a4 beq 0xd849c <_Z7DoBreakjhPhPKhP6VMExecb+0x68> */
/* @0xd85a8 mov r0, #64 */
/* @0xd85ac bl 0x27c524 <_Znwj> */
/* @0xd85b0 ldr r2, [r9, #0x8] */
/* @0xd85b4 ldr r1, [r9, #0xc] */
/* @0xd85b8 mov r12, #1 */
/* @0xd85bc mov r3, #3 */
/* @0xd85c0 str r12, [sp] */
/* @0xd85c4 str r7, [sp, #0x4] */
/* @0xd85c8 mov r10, r0 */
/* @0xd85cc bl 0xcca38 <_ZN7IBufferC2EPvi14eBuffer_Formatib> */
/* @0xd85d0 ldr r3, [pc, #0x80] */
/* @0xd85d4 mov r1, r10 */
/* @0xd85d8 add r0, sp, #8 */
/* @0xd85dc ldr r3, [r6, r3] */
/* @0xd85e0 add r3, r3, #8 */
/* @0xd85e4 str r3, [r10] */
/* @0xd85e8 bl 0x29b6a8 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard> */
/* @0xd85ec ldr r3, [pc, #0x68] */
/* @0xd85f0 ldr r3, [r6, r3] */
/* @0xd85f4 ldrb r2, [r3] */
/* @0xd85f8 cmp r2, #0 */
/* @0xd85fc bne 0xd861c <_Z7DoBreakjhPhPKhP6VMExecb+0x1e8> */
/* @0xd8600 vmov.f64 d6, #5.000000e-01 */
/* @0xd8604 vldr d7, [sp, #8] */
/* @0xd8608 vcmpe.f64 d7, d6 */
/* @0xd860c vmrs APSR_nzcv, fpscr */
/* @0xd8610 movle r7, r2 */
/* @0xd8614 ble 0xd84b0 <_Z7DoBreakjhPhPKhP6VMExecb+0x7c> */
/* @0xd8618 b 0xd849c <_Z7DoBreakjhPhPKhP6VMExecb+0x68> */
/* @0xd861c strb r7, [r3] */
/* @0xd8620 b 0xd849c <_Z7DoBreakjhPhPKhP6VMExecb+0x68> */
/* @0xd8624 ldr r1, [pc, #0x34] */
/* @0xd8628 mov r0, r5 */
/* @0xd862c add r1, pc, r1 */
/* @0xd8630 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd8634 b 0xd847c <_Z7DoBreakjhPhPKhP6VMExecb+0x48> */

/* ── 以下 11 字是 literal pool（GOT 偏移与字符串偏移），objdump 译成指令，非指令 ── */
/* @0xd8638 eorseq r9, r1, r4, lsl #16 */
/* @0xd863c .word 0xffffbcd4 */
/* @0xd8640 .word 0xffffbf1c */
/* @0xd8644 .word 0xffffbf58 */
/* @0xd8648 .word 0xffffc09c */
/* @0xd864c .word 0xffffc0a0 */
/* @0xd8650 .word 0xffffc0a4 */
/* @0xd8654 .word 0x0025a6b4 */
/* @0xd8658 .word 0xffffbd60 */
/* @0xd865c .word 0xffffbf14 */
/* @0xd8660 .word 0x0025a5d4 */
