/* libyoyo.so 覆盖卡组 0015
 * 函数 0xd83a8..0xdc414，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xd83a8 · VM::Init() · size=36 · insn=9 */
/* @0xd83a8 push {r3, lr} */
/* @0xd83ac bl 0xd8374 <_ZN2VM16ResetBreakpointsEv> */
/* @0xd83b0 mov r2, #0 */
/* @0xd83b4 ldr r3, [pc, #0xc] */
/* @0xd83b8 ldr r3, [pc, r3] */
/* @0xd83bc str r2, [r3] */
/* @0xd83c0 pop {r3, lr} */
/* @0xd83c4 b 0xd3edc <_Z26InitialiseHandledContainerv> */
/* @0xd83c8 eorseq r5, r1, r0, lsr r9 */

/* ── FUNC 0xd83cc · VM::WriteBreakpointsToMemory() · size=56 · insn=14 */
/* @0xd83cc ldr r1, [pc, #0x2c] */
/* @0xd83d0 mov r0, #0 */
/* @0xd83d4 movt r0, #0xffff */
/* @0xd83d8 mov r3, #0 */
/* @0xd83dc ldr r1, [pc, r1] */
/* @0xd83e0 add r2, r1, r3 */
/* @0xd83e4 add r3, r3, #16 */
/* @0xd83e8 ldr r2, [r2, #0x4] */
/* @0xd83ec cmn r2, #1 */
/* @0xd83f0 strne r0, [r2] */
/* @0xd83f4 cmp r3, #4096 */
/* @0xd83f8 bne 0xd83e0 <_ZN2VM24WriteBreakpointsToMemoryEv+0x14> */
/* @0xd83fc bx lr */
/* @0xd8400 eorseq r5, r1, r8, lsl #18 */

/* ── FUNC 0xd8404 · VM::ClearBreakpointsFromMemory() · size=48 · insn=12 */
/* @0xd8404 ldr r3, [pc, #0x24] */
/* @0xd8408 ldr r3, [pc, r3] */
/* @0xd840c sub r0, r3, #4096 */
/* @0xd8410 ldr r2, [r3, #0xff4] */
/* @0xd8414 cmn r2, #1 */
/* @0xd8418 ldrne r1, [r3, #0xff0] */
/* @0xd841c sub r3, r3, #16 */
/* @0xd8420 strne r1, [r2] */
/* @0xd8424 cmp r3, r0 */
/* @0xd8428 bne 0xd8410 <_ZN2VM26ClearBreakpointsFromMemoryEv+0xc> */
/* @0xd842c bx lr */
/* @0xd8430 ldrsbteq r5, [r1], -r12 */

/* ── FUNC 0xd8434 · DoBreak(unsigned int, unsigned char, unsigned char*, unsigned char const*, VMExec*, bool) · size=560 · insn=140 */
/* @0xd8434 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xd8438 uxth r7, r0 */
/* @0xd843c sub sp, sp, #24 */
/* @0xd8440 ldr r6, [pc, #0x1f0] */
/* @0xd8444 cmp r7, #0 */
/* @0xd8448 mov r4, r2 */
/* @0xd844c add r6, pc, r6 */
/* @0xd8450 ldr r5, [sp, #0x38] */
/* @0xd8454 ldrb r8, [sp, #0x3c] */
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
/* @0xd8488 ldr r3, [pc, #0x1ac] */
/* @0xd848c ldr r3, [r6, r3] */
/* @0xd8490 ldrb r3, [r3] */
/* @0xd8494 cmp r3, #0 */
/* @0xd8498 bne 0xd8580 <_Z7DoBreakjhPhPKhP6VMExecb+0x14c> */
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
/* @0xd8544 ldr r3, [pc, #0x104] */
/* @0xd8548 ldr r3, [r6, r3] */
/* @0xd854c ldr r3, [r3] */
/* @0xd8550 cmp r3, #0 */
/* @0xd8554 beq 0xd84cc <_Z7DoBreakjhPhPKhP6VMExecb+0x98> */
/* @0xd8558 bl 0x29d634 <_Z19DebuggerMessageLoopv> */
/* @0xd855c b 0xd84cc <_Z7DoBreakjhPhPKhP6VMExecb+0x98> */
/* @0xd8560 ldr r1, [pc, #0xec] */
/* @0xd8564 mov r0, r5 */
/* @0xd8568 mov r2, #32000 */
/* @0xd856c add r1, pc, r1 */
/* @0xd8570 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd8574 mov r0, r4 */
/* @0xd8578 add sp, sp, #24 */
/* @0xd857c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
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

/* ── FUNC 0xd8664 · VM::WriteRenderStates(Buffer_Standard*, bool) · size=328 · insn=82 */
/* @0xd8664 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xd8668 subs r3, r1, #0 */
/* @0xd866c ldr r7, [pc, #0x124] */
/* @0xd8670 mov r6, r0 */
/* @0xd8674 add r7, pc, r7 */
/* @0xd8678 beq 0xd8774 <_ZN2VM17WriteRenderStatesEP15Buffer_Standardb+0x110> */
/* @0xd867c ldr r12, [r0] */
/* @0xd8680 add r9, r0, #44 */
/* @0xd8684 mov r3, #0 */
/* @0xd8688 mov r1, #5 */
/* @0xd868c mov r8, r3 */
/* @0xd8690 mov r2, r9 */
/* @0xd8694 str r8, [r0, #0x2c] */
/* @0xd8698 movt r3, #0x4043 */
/* @0xd869c str r8, [r0, #0x38] */
/* @0xd86a0 str r3, [r0, #0x30] */
/* @0xd86a4 ldr r3, [r12, #0x8] */
/* @0xd86a8 blx r3 */
/* @0xd86ac ldr r3, [pc, #0xe8] */
/* @0xd86b0 mov r1, r6 */
/* @0xd86b4 ldr r0, [r7, r3] */
/* @0xd86b8 bl 0x1682cc <_ZN18RenderStateManager19WriteStatesToBufferEP15Buffer_Standard> */
/* @0xd86bc ldr r12, [pc, #0xdc] */
/* @0xd86c0 ldr r3, [r6] */
/* @0xd86c4 mov r2, r9 */
/* @0xd86c8 mov r0, r6 */
/* @0xd86cc mov r1, #5 */
/* @0xd86d0 ldr r12, [r7, r12] */
/* @0xd86d4 str r8, [r6, #0x38] */
/* @0xd86d8 ldr r4, [r12] */
/* @0xd86dc vmov s15, r4 */
/* @0xd86e0 vcvt.f64.u32 d7, s15 */
/* @0xd86e4 vmov r4, r5, d7 */
/* @0xd86e8 vstr s14, [r6, #44] */
/* @0xd86ec str r5, [r6, #0x30] */
/* @0xd86f0 ldr r3, [r3, #0x8] */
/* @0xd86f4 blx r3 */
/* @0xd86f8 ldr r12, [pc, #0xa4] */
/* @0xd86fc ldr r3, [r6] */
/* @0xd8700 mov r2, r9 */
/* @0xd8704 mov r0, r6 */
/* @0xd8708 mov r1, #5 */
/* @0xd870c ldr r12, [r7, r12] */
/* @0xd8710 str r8, [r6, #0x38] */
/* @0xd8714 ldr r4, [r12] */
/* @0xd8718 vmov s15, r4 */
/* @0xd871c vcvt.f64.u32 d7, s15 */
/* @0xd8720 vmov r4, r5, d7 */
/* @0xd8724 vstr s14, [r6, #44] */
/* @0xd8728 str r5, [r6, #0x30] */
/* @0xd872c ldr r3, [r3, #0x8] */
/* @0xd8730 blx r3 */
/* @0xd8734 ldr r12, [pc, #0x6c] */
/* @0xd8738 ldr r3, [r6] */
/* @0xd873c mov r2, r9 */
/* @0xd8740 mov r0, r6 */
/* @0xd8744 mov r1, #5 */
/* @0xd8748 ldr r12, [r7, r12] */
/* @0xd874c str r8, [r6, #0x38] */
/* @0xd8750 ldrb r4, [r12] */
/* @0xd8754 vmov s15, r4 */
/* @0xd8758 vcvt.f64.u32 d7, s15 */
/* @0xd875c vmov r4, r5, d7 */
/* @0xd8760 vstr s14, [r6, #44] */
/* @0xd8764 str r5, [r6, #0x30] */
/* @0xd8768 ldr r3, [r3, #0x8] */
/* @0xd876c blx r3 */
/* @0xd8770 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd8774 mov r2, r0 */
/* @0xd8778 str r3, [r0, #0x2c] */
/* @0xd877c ldr r12, [r2], #44 */
/* @0xd8780 mov r1, #5 */
/* @0xd8784 str r3, [r0, #0x30] */
/* @0xd8788 str r3, [r0, #0x38] */
/* @0xd878c ldr r3, [r12, #0x8] */
/* @0xd8790 blx r3 */
/* @0xd8794 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xd8798 ldrsbteq r9, [r1], -r12 */
/* @0xd879c .word 0xffffc0a8 */
/* @0xd87a0 .word 0xffffc0ac */
/* @0xd87a4 .word 0xffffc0b0 */
/* @0xd87a8 .word 0xffffc0b4 */

/* ── FUNC 0xd87ac · VM::GetAllInstanceIDs(Buffer_Standard*, bool) · size=352 · insn=88 */
/* @0xd87ac push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd87b0 vpush {d8} */
/* @0xd87b4 add r7, r0, #44 */
/* @0xd87b8 ldr r3, [r0] */
/* @0xd87bc mov r11, #0 */
/* @0xd87c0 mov r4, r1 */
/* @0xd87c4 str r11, [r0, #0x2c] */
/* @0xd87c8 str r11, [r0, #0x30] */
/* @0xd87cc mov r2, r7 */
/* @0xd87d0 mov r1, #5 */
/* @0xd87d4 str r11, [r0, #0x38] */
/* @0xd87d8 ldr r3, [r3, #0x8] */
/* @0xd87dc mov r6, r0 */
/* @0xd87e0 ldr r9, [r0, #0x1c] */
/* @0xd87e4 blx r3 */
/* @0xd87e8 cmp r4, r11 */
/* @0xd87ec beq 0xd88f8 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0x14c> */
/* @0xd87f0 ldr r3, [pc, #0x110] */
/* @0xd87f4 ldr r3, [pc, r3] */
/* @0xd87f8 ldr r3, [r3] */
/* @0xd87fc cmp r3, r11 */
/* @0xd8800 vmoveq s16, r3 */
/* @0xd8804 beq 0xd8894 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0xe8> */
/* @0xd8808 ldr r10, [r3, #0x80] */
/* @0xd880c cmp r10, r11 */
/* @0xd8810 beq 0xd8900 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0x154> */
/* @0xd8814 mov r8, r11 */
/* @0xd8818 ldr r4, [r10, #0x78] */
/* @0xd881c mov r1, #5 */
/* @0xd8820 ldr r3, [r6] */
/* @0xd8824 mov r2, r7 */
/* @0xd8828 mov r0, r6 */
/* @0xd882c str r8, [r6, #0x38] */
/* @0xd8830 vmov s15, r4 */
/* @0xd8834 add r11, r11, #1 */
/* @0xd8838 vcvt.f64.u32 d7, s15 */
/* @0xd883c vmov r4, r5, d7 */
/* @0xd8840 vstr s14, [r6, #44] */
/* @0xd8844 str r5, [r6, #0x30] */
/* @0xd8848 ldr r3, [r3, #0x8] */
/* @0xd884c blx r3 */
/* @0xd8850 ldr r4, [r10, #0x7c] */
/* @0xd8854 ldr r3, [r6] */
/* @0xd8858 mov r0, r6 */
/* @0xd885c str r8, [r6, #0x38] */
/* @0xd8860 mov r1, #5 */
/* @0xd8864 vmov s15, r4 */
/* @0xd8868 mov r2, r7 */
/* @0xd886c vcvt.f64.u32 d7, s15 */
/* @0xd8870 vmov r4, r5, d7 */
/* @0xd8874 vstr s14, [r6, #44] */
/* @0xd8878 str r5, [r6, #0x30] */
/* @0xd887c ldr r3, [r3, #0x8] */
/* @0xd8880 blx r3 */
/* @0xd8884 ldr r10, [r10, #0x178] */
/* @0xd8888 cmp r10, #0 */
/* @0xd888c bne 0xd8818 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0x6c> */
/* @0xd8890 vmov s16, r11 */
/* @0xd8894 ldr r3, [r6] */
/* @0xd8898 mov r2, r9 */
/* @0xd889c mov r1, #0 */
/* @0xd88a0 mov r0, r6 */
/* @0xd88a4 mov r8, r1 */
/* @0xd88a8 ldr r9, [r6, #0x1c] */
/* @0xd88ac ldr r3, [r3, #0x10] */
/* @0xd88b0 blx r3 */
/* @0xd88b4 vcvt.f64.u32 d7, s16 */
/* @0xd88b8 ldr r3, [r6] */
/* @0xd88bc mov r2, r7 */
/* @0xd88c0 mov r1, #5 */
/* @0xd88c4 str r8, [r6, #0x38] */
/* @0xd88c8 mov r0, r6 */
/* @0xd88cc vmov r4, r5, d7 */
/* @0xd88d0 vstr s14, [r6, #44] */
/* @0xd88d4 str r5, [r6, #0x30] */
/* @0xd88d8 ldr r3, [r3, #0x8] */
/* @0xd88dc blx r3 */
/* @0xd88e0 ldr r3, [r6] */
/* @0xd88e4 mov r1, r8 */
/* @0xd88e8 mov r2, r9 */
/* @0xd88ec mov r0, r6 */
/* @0xd88f0 ldr r3, [r3, #0x10] */
/* @0xd88f4 blx r3 */
/* @0xd88f8 vpop {d8} */
/* @0xd88fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd8900 vmov s16, r10 */
/* @0xd8904 b 0xd8894 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0xe8> */
/* @0xd8908 eorseq r5, r1, r4, lsr r1 */

/* ── FUNC 0xd890c · VM::GetStructureCounts(Buffer_Standard*) · size=380 · insn=95 */
/* @0xd890c push {r4, r5, r6, r7, r8, lr} */
/* @0xd8910 sub sp, sp, #16 */
/* @0xd8914 mov r6, r0 */
/* @0xd8918 add r8, r6, #44 */
/* @0xd891c mov r0, sp */
/* @0xd8920 mov r7, #0 */
/* @0xd8924 bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xd8928 add r0, sp, #4 */
/* @0xd892c bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xd8930 add r0, sp, #8 */
/* @0xd8934 bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xd8938 add r0, sp, #12 */
/* @0xd893c bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xd8940 ldr r3, [pc, #0x138] */
/* @0xd8944 ldr r12, [r6] */
/* @0xd8948 mov r2, r8 */
/* @0xd894c ldr r3, [pc, r3] */
/* @0xd8950 str r7, [r6, #0x38] */
/* @0xd8954 mov r0, r6 */
/* @0xd8958 mov r1, #5 */
/* @0xd895c ldr r4, [r3] */
/* @0xd8960 vmov s15, r4 */
/* @0xd8964 vcvt.f64.u32 d7, s15 */
/* @0xd8968 vmov r4, r5, d7 */
/* @0xd896c vstr s14, [r6, #44] */
/* @0xd8970 str r5, [r6, #0x30] */
/* @0xd8974 ldr r3, [r12, #0x8] */
/* @0xd8978 blx r3 */
/* @0xd897c vldr s15, [sp] */
/* @0xd8980 vcvt.f64.u32 d7, s15 */
/* @0xd8984 ldr r3, [r6] */
/* @0xd8988 mov r2, r8 */
/* @0xd898c str r7, [r6, #0x38] */
/* @0xd8990 mov r0, r6 */
/* @0xd8994 mov r1, #5 */
/* @0xd8998 vmov r4, r5, d7 */
/* @0xd899c vstr s14, [r6, #44] */
/* @0xd89a0 str r5, [r6, #0x30] */
/* @0xd89a4 ldr r3, [r3, #0x8] */
/* @0xd89a8 blx r3 */
/* @0xd89ac ldr r3, [pc, #0xd0] */
/* @0xd89b0 ldr r12, [r6] */
/* @0xd89b4 mov r2, r8 */
/* @0xd89b8 ldr r3, [pc, r3] */
/* @0xd89bc str r7, [r6, #0x38] */
/* @0xd89c0 mov r0, r6 */
/* @0xd89c4 mov r1, #5 */
/* @0xd89c8 ldr r4, [r3] */
/* @0xd89cc vmov s15, r4 */
/* @0xd89d0 vcvt.f64.u32 d7, s15 */
/* @0xd89d4 vmov r4, r5, d7 */
/* @0xd89d8 vstr s14, [r6, #44] */
/* @0xd89dc str r5, [r6, #0x30] */
/* @0xd89e0 ldr r3, [r12, #0x8] */
/* @0xd89e4 blx r3 */
/* @0xd89e8 vldr s15, [sp, #4] */
/* @0xd89ec vcvt.f64.u32 d7, s15 */
/* @0xd89f0 ldr r3, [r6] */
/* @0xd89f4 mov r2, r8 */
/* @0xd89f8 str r7, [r6, #0x38] */
/* @0xd89fc mov r0, r6 */
/* @0xd8a00 mov r1, #5 */
/* @0xd8a04 vmov r4, r5, d7 */
/* @0xd8a08 vstr s14, [r6, #44] */
/* @0xd8a0c str r5, [r6, #0x30] */
/* @0xd8a10 ldr r3, [r3, #0x8] */
/* @0xd8a14 blx r3 */
/* @0xd8a18 vldr s15, [sp, #8] */
/* @0xd8a1c vcvt.f64.u32 d7, s15 */
/* @0xd8a20 ldr r3, [r6] */
/* @0xd8a24 mov r2, r8 */
/* @0xd8a28 str r7, [r6, #0x38] */
/* @0xd8a2c mov r0, r6 */
/* @0xd8a30 mov r1, #5 */
/* @0xd8a34 vmov r4, r5, d7 */
/* @0xd8a38 vstr s14, [r6, #44] */
/* @0xd8a3c str r5, [r6, #0x30] */
/* @0xd8a40 ldr r3, [r3, #0x8] */
/* @0xd8a44 blx r3 */
/* @0xd8a48 vldr s15, [sp, #12] */
/* @0xd8a4c vcvt.f64.u32 d7, s15 */
/* @0xd8a50 ldr r3, [r6] */
/* @0xd8a54 mov r2, r8 */
/* @0xd8a58 str r7, [r6, #0x38] */
/* @0xd8a5c mov r0, r6 */
/* @0xd8a60 mov r1, #5 */
/* @0xd8a64 vmov r4, r5, d7 */
/* @0xd8a68 vstr s14, [r6, #44] */
/* @0xd8a6c str r5, [r6, #0x30] */
/* @0xd8a70 ldr r3, [r3, #0x8] */
/* @0xd8a74 blx r3 */
/* @0xd8a78 add sp, sp, #16 */
/* @0xd8a7c pop {r4, r5, r6, r7, r8, pc} */
/* @0xd8a80 eorseq r5, r1, r0, lsr r3 */
/* @0xd8a84 eorseq r5, r1, r0, asr #5 */

/* ── FUNC 0xd8a88 · VM::WriteRValueToBuffer(RValue*, Buffer_Standard*) · size=408 · insn=102 */
/* @0xd8a88 push {r4, r5, r6, r7, r8, lr} */
/* @0xd8a8c add r8, r1, #44 */
/* @0xd8a90 ldr r4, [r0, #0xc] */
/* @0xd8a94 mov r6, r1 */
/* @0xd8a98 ldr r3, [r1] */
/* @0xd8a9c mov r7, r0 */
/* @0xd8aa0 mov r1, #0 */
/* @0xd8aa4 mov r2, r8 */
/* @0xd8aa8 vmov s15, r4 */
/* @0xd8aac str r1, [r6, #0x38] */
/* @0xd8ab0 mov r0, r6 */
/* @0xd8ab4 mov r1, #5 */
/* @0xd8ab8 vcvt.f64.u32 d7, s15 */
/* @0xd8abc vmov r4, r5, d7 */
/* @0xd8ac0 vstr s14, [r6, #44] */
/* @0xd8ac4 str r5, [r6, #0x30] */
/* @0xd8ac8 ldr r3, [r3, #0x8] */
/* @0xd8acc blx r3 */
/* @0xd8ad0 ldr r2, [r7, #0xc] */
/* @0xd8ad4 bic r3, r2, #-268435456 */
/* @0xd8ad8 cmp r3, #13 */
/* @0xd8adc addls pc, pc, r3, lsl #2 */
/* @0xd8ae0 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8ae4 b 0xd8bc4 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x13c> */
/* @0xd8ae8 b 0xd8bf8 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x170> */
/* @0xd8aec b 0xd8b50 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc8> */
/* @0xd8af0 b 0xd8b50 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc8> */
/* @0xd8af4 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8af8 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8afc b 0xd8b50 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc8> */
/* @0xd8b00 b 0xd8b88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x100> */
/* @0xd8b04 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8b08 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8b0c b 0xd8b1c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x94> */
/* @0xd8b10 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8b14 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4> */
/* @0xd8b18 b 0xd8bc4 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x13c> */
/* @0xd8b1c ldr r1, [r7] */
/* @0xd8b20 mov r12, #10 */
/* @0xd8b24 ldr lr, [r7, #0x4] */
/* @0xd8b28 mov r2, r8 */
/* @0xd8b2c ldr r3, [r6] */
/* @0xd8b30 mov r0, r6 */
/* @0xd8b34 str r1, [r6, #0x2c] */
/* @0xd8b38 mov r1, #12 */
/* @0xd8b3c str lr, [r6, #0x30] */
/* @0xd8b40 str r12, [r6, #0x38] */
/* @0xd8b44 ldr r3, [r3, #0x8] */
/* @0xd8b48 blx r3 */
/* @0xd8b4c pop {r4, r5, r6, r7, r8, pc} */
/* @0xd8b50 ldr r3, [r7] */
/* @0xd8b54 mov r1, #10 */
/* @0xd8b58 ldr r12, [r6] */
/* @0xd8b5c mov r2, r8 */
/* @0xd8b60 str r1, [r6, #0x38] */
/* @0xd8b64 mov r0, r6 */
/* @0xd8b68 asr r5, r3, #31 */
/* @0xd8b6c mov r4, r3 */
/* @0xd8b70 str r3, [r6, #0x2c] */
/* @0xd8b74 mov r1, #12 */
/* @0xd8b78 str r5, [r6, #0x30] */
/* @0xd8b7c ldr r3, [r12, #0x8] */
/* @0xd8b80 blx r3 */
/* @0xd8b84 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd8b88 ldr r4, [r7] */
/* @0xd8b8c mov r1, #0 */
/* @0xd8b90 ldr r3, [r6] */
/* @0xd8b94 mov r2, r8 */
/* @0xd8b98 str r1, [r6, #0x38] */
/* @0xd8b9c mov r0, r6 */
/* @0xd8ba0 vmov s15, r4 */
/* @0xd8ba4 mov r1, #6 */
/* @0xd8ba8 vcvt.f64.s32 d7, s15 */
/* @0xd8bac vmov r4, r5, d7 */
/* @0xd8bb0 vstr s14, [r6, #44] */
/* @0xd8bb4 str r5, [r6, #0x30] */
/* @0xd8bb8 ldr r3, [r3, #0x8] */
/* @0xd8bbc blx r3 */
/* @0xd8bc0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd8bc4 ldr r1, [r7] */
/* @0xd8bc8 mov r12, #0 */
/* @0xd8bcc ldr lr, [r7, #0x4] */
/* @0xd8bd0 mov r2, r8 */
/* @0xd8bd4 ldr r3, [r6] */
/* @0xd8bd8 mov r0, r6 */
/* @0xd8bdc str r1, [r6, #0x2c] */
/* @0xd8be0 mov r1, #9 */
/* @0xd8be4 str lr, [r6, #0x30] */
/* @0xd8be8 str r12, [r6, #0x38] */
/* @0xd8bec ldr r3, [r3, #0x8] */
/* @0xd8bf0 blx r3 */
/* @0xd8bf4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd8bf8 bic r2, r2, #-16777216 */
/* @0xd8bfc cmp r2, #1 */
/* @0xd8c00 movne r1, #0 */
/* @0xd8c04 bne 0xd8c14 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x18c> */
/* @0xd8c08 ldr r1, [r7] */
/* @0xd8c0c cmp r1, #0 */
/* @0xd8c10 ldrne r1, [r1] */
/* @0xd8c14 mov r0, r6 */
/* @0xd8c18 pop {r4, r5, r6, r7, r8, lr} */
/* @0xd8c1c b 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */

/* ── FUNC 0xd8c20 · VM::GetGlobalVariables(Buffer_Standard*, bool) · size=424 · insn=106 */
/* @0xd8c20 ldr r3, [r0] */
/* @0xd8c24 ldr r12, [r0, #0x1c] */
/* @0xd8c28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd8c2c vpush {d8} */
/* @0xd8c30 add r9, r0, #44 */
/* @0xd8c34 sub sp, sp, #12 */
/* @0xd8c38 mov r7, #0 */
/* @0xd8c3c mov r4, r1 */
/* @0xd8c40 str r7, [r0, #0x2c] */
/* @0xd8c44 str r7, [r0, #0x30] */
/* @0xd8c48 mov r2, r9 */
/* @0xd8c4c mov r1, #5 */
/* @0xd8c50 str r7, [r0, #0x38] */
/* @0xd8c54 ldr r3, [r3, #0x8] */
/* @0xd8c58 mov r6, r0 */
/* @0xd8c5c str r12, [sp, #0x4] */
/* @0xd8c60 blx r3 */
/* @0xd8c64 cmp r4, r7 */
/* @0xd8c68 beq 0xd8d8c <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x16c> */
/* @0xd8c6c ldr r10, [pc, #0x14c] */
/* @0xd8c70 ldr r10, [pc, r10] */
/* @0xd8c74 ldr r3, [r10] */
/* @0xd8c78 cmp r3, r7 */
/* @0xd8c7c ble 0xd8db8 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x198> */
/* @0xd8c80 ldr r8, [pc, #0x13c] */
/* @0xd8c84 mov r11, r7 */
/* @0xd8c88 str r7, [sp] */
/* @0xd8c8c ldr r8, [pc, r8] */
/* @0xd8c90 ldr r0, [r8] */
/* @0xd8c94 ldr r2, [r0, #0x4] */
/* @0xd8c98 cmp r2, #0 */
/* @0xd8c9c add r12, r2, r7 */
/* @0xd8ca0 beq 0xd8d98 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x178> */
/* @0xd8ca4 ldr r12, [r12, #0xc] */
/* @0xd8ca8 mvn r3, #-16777216 */
/* @0xd8cac mov r1, #6 */
/* @0xd8cb0 mov r2, r9 */
/* @0xd8cb4 cmp r12, r3 */
/* @0xd8cb8 mov r0, r6 */
/* @0xd8cbc beq 0xd8d10 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0xf0> */
/* @0xd8cc0 vmov s15, r11 */
/* @0xd8cc4 mov r12, #0 */
/* @0xd8cc8 str r12, [r6, #0x38] */
/* @0xd8ccc vcvt.f64.s32 d7, s15 */
/* @0xd8cd0 ldr r12, [r6] */
/* @0xd8cd4 vmov r4, r5, d7 */
/* @0xd8cd8 vstr s14, [r6, #44] */
/* @0xd8cdc str r5, [r6, #0x30] */
/* @0xd8ce0 ldr r12, [r12, #0x8] */
/* @0xd8ce4 blx r12 */
/* @0xd8ce8 ldr r1, [r8] */
/* @0xd8cec ldr r2, [r1, #0x4] */
/* @0xd8cf0 cmp r2, #0 */
/* @0xd8cf4 add r0, r2, r7 */
/* @0xd8cf8 beq 0xd8da8 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x188> */
/* @0xd8cfc ldr r3, [sp] */
/* @0xd8d00 mov r1, r6 */
/* @0xd8d04 add r3, r3, #1 */
/* @0xd8d08 str r3, [sp] */
/* @0xd8d0c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd8d10 ldr r2, [r10] */
/* @0xd8d14 add r11, r11, #1 */
/* @0xd8d18 add r7, r7, #16 */
/* @0xd8d1c cmp r2, r11 */
/* @0xd8d20 bgt 0xd8c90 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x70> */
/* @0xd8d24 vldr s16, [sp] */
/* @0xd8d28 ldr r3, [r6] */
/* @0xd8d2c mov r1, #0 */
/* @0xd8d30 ldr r2, [sp, #0x4] */
/* @0xd8d34 mov r0, r6 */
/* @0xd8d38 mov r7, r1 */
/* @0xd8d3c ldr r8, [r6, #0x1c] */
/* @0xd8d40 ldr r3, [r3, #0x10] */
/* @0xd8d44 blx r3 */
/* @0xd8d48 vcvt.f64.u32 d7, s16 */
/* @0xd8d4c ldr r3, [r6] */
/* @0xd8d50 mov r2, r9 */
/* @0xd8d54 mov r1, #5 */
/* @0xd8d58 str r7, [r6, #0x38] */
/* @0xd8d5c mov r0, r6 */
/* @0xd8d60 vmov r4, r5, d7 */
/* @0xd8d64 vstr s14, [r6, #44] */
/* @0xd8d68 str r5, [r6, #0x30] */
/* @0xd8d6c ldr r3, [r3, #0x8] */
/* @0xd8d70 blx r3 */
/* @0xd8d74 ldr r3, [r6] */
/* @0xd8d78 mov r1, r7 */
/* @0xd8d7c mov r2, r8 */
/* @0xd8d80 mov r0, r6 */
/* @0xd8d84 ldr r3, [r3, #0x10] */
/* @0xd8d88 blx r3 */
/* @0xd8d8c add sp, sp, #12 */
/* @0xd8d90 vpop {d8} */
/* @0xd8d94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd8d98 mov r1, r11 */
/* @0xd8d9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xd8da0 mov r12, r0 */
/* @0xd8da4 b 0xd8ca4 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x84> */
/* @0xd8da8 mov r0, r1 */
/* @0xd8dac mov r1, r11 */
/* @0xd8db0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xd8db4 b 0xd8cfc <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0xdc> */
/* @0xd8db8 vmov s16, r7 */
/* @0xd8dbc b 0xd8d28 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb+0x108> */
/* @0xd8dc0 mlaseq r1, r8, r0, r5 */
/* @0xd8dc4 eorseq r4, r1, r8, lsr #30 */

/* ── FUNC 0xd8dc8 · VM::GetRuntimeStateRealtime(Buffer_Standard*, int) · size=44 · insn=11 */
/* @0xd8dc8 push {r3, r4, r5, lr} */
/* @0xd8dcc mov r4, r0 */
/* @0xd8dd0 mov r5, r1 */
/* @0xd8dd4 ubfx r1, r1, #0x3, #0x1 */
/* @0xd8dd8 bl 0xd8c20 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb> */
/* @0xd8ddc mov r0, r4 */
/* @0xd8de0 bl 0xd890c <_ZN2VM18GetStructureCountsEP15Buffer_Standard> */
/* @0xd8de4 mov r0, r4 */
/* @0xd8de8 and r1, r5, #1 */
/* @0xd8dec pop {r3, r4, r5, lr} */
/* @0xd8df0 b 0xd87ac <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb> */

/* ── FUNC 0xd8df4 · VM::GetObjectBaseVariables(Buffer_Standard*, YYObjectBase*, bool) · size=340 · insn=85 */
/* @0xd8df4 ldr r12, [r0] */
/* @0xd8df8 mov r3, #0 */
/* @0xd8dfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd8e00 add r11, r0, #44 */
/* @0xd8e04 str r3, [r0, #0x2c] */
/* @0xd8e08 sub sp, sp, #76 */
/* @0xd8e0c str r3, [r0, #0x30] */
/* @0xd8e10 mov r5, r2 */
/* @0xd8e14 ldr r12, [r12, #0x8] */
/* @0xd8e18 eor r5, r5, #1 */
/* @0xd8e1c str r3, [r0, #0x38] */
/* @0xd8e20 mov r7, r1 */
/* @0xd8e24 ldr r3, [r0, #0x1c] */
/* @0xd8e28 mov r2, r11 */
/* @0xd8e2c mov r1, #5 */
/* @0xd8e30 cmp r7, #0 */
/* @0xd8e34 orreq r5, r5, #1 */
/* @0xd8e38 mov r4, r0 */
/* @0xd8e3c str r3, [sp, #0x4] */
/* @0xd8e40 blx r12 */
/* @0xd8e44 cmp r5, #0 */
/* @0xd8e48 beq 0xd8e54 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb+0x60> */
/* @0xd8e4c add sp, sp, #76 */
/* @0xd8e50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd8e54 add r8, sp, #44 */
/* @0xd8e58 mov r1, r7 */
/* @0xd8e5c mov r2, r5 */
/* @0xd8e60 add r9, sp, #12 */
/* @0xd8e64 mov r0, r8 */
/* @0xd8e68 mov r10, #5 */
/* @0xd8e6c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0xd8e70 add r6, sp, #28 */
/* @0xd8e74 mov r3, #1 */
/* @0xd8e78 strb r3, [sp, #0x3d] */
/* @0xd8e7c b 0xd8eb0 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb+0xbc> */
/* @0xd8e80 ldr r3, [sp, #0xc] */
/* @0xd8e84 add r5, r5, #1 */
/* @0xd8e88 str r10, [sp, #0x28] */
/* @0xd8e8c ldr r2, [r3] */
/* @0xd8e90 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0xd8e94 ldr r3, [sp, #0xc] */
/* @0xd8e98 mov r0, r4 */
/* @0xd8e9c ldr r1, [r3] */
/* @0xd8ea0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0xd8ea4 mov r0, r6 */
/* @0xd8ea8 mov r1, r4 */
/* @0xd8eac bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd8eb0 mov r1, r9 */
/* @0xd8eb4 mov r0, r8 */
/* @0xd8eb8 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0xd8ebc mov r1, r6 */
/* @0xd8ec0 subs r3, r0, #0 */
/* @0xd8ec4 mov r0, r7 */
/* @0xd8ec8 bne 0xd8e80 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb+0x8c> */
/* @0xd8ecc ldr r12, [r4] */
/* @0xd8ed0 mov r1, r3 */
/* @0xd8ed4 ldr r8, [r4, #0x1c] */
/* @0xd8ed8 mov r0, r4 */
/* @0xd8edc ldr r2, [sp, #0x4] */
/* @0xd8ee0 ldr r12, [r12, #0x10] */
/* @0xd8ee4 str r3, [sp] */
/* @0xd8ee8 blx r12 */
/* @0xd8eec vmov s15, r5 */
/* @0xd8ef0 ldr r3, [sp] */
/* @0xd8ef4 mov r2, r11 */
/* @0xd8ef8 vcvt.f64.s32 d7, s15 */
/* @0xd8efc ldr r12, [r4] */
/* @0xd8f00 mov r0, r4 */
/* @0xd8f04 mov r1, #5 */
/* @0xd8f08 str r3, [r4, #0x38] */
/* @0xd8f0c vmov r6, r7, d7 */
/* @0xd8f10 vstr s14, [r4, #44] */
/* @0xd8f14 str r7, [r4, #0x30] */
/* @0xd8f18 ldr r12, [r12, #0x8] */
/* @0xd8f1c str r3, [sp] */
/* @0xd8f20 blx r12 */
/* @0xd8f24 ldr r3, [sp] */
/* @0xd8f28 ldr r12, [r4] */
/* @0xd8f2c mov r2, r8 */
/* @0xd8f30 mov r0, r4 */
/* @0xd8f34 mov r1, r3 */
/* @0xd8f38 ldr r3, [r12, #0x10] */
/* @0xd8f3c blx r3 */
/* @0xd8f40 add sp, sp, #76 */
/* @0xd8f44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xd8f48 · VM::GetLocalVariables(Buffer_Standard*, YYObjectBase*, bool, int) · size=352 · insn=88 */
/* @0xd8f48 ldr r3, [r0] */
/* @0xd8f4c ldr r12, [r0, #0x1c] */
/* @0xd8f50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd8f54 add r9, r0, #44 */
/* @0xd8f58 sub sp, sp, #12 */
/* @0xd8f5c mov r4, #0 */
/* @0xd8f60 mov r8, r1 */
/* @0xd8f64 str r4, [r0, #0x2c] */
/* @0xd8f68 str r4, [r0, #0x30] */
/* @0xd8f6c mov r5, r2 */
/* @0xd8f70 ldr r3, [r3, #0x8] */
/* @0xd8f74 mov r2, r9 */
/* @0xd8f78 mov r1, #5 */
/* @0xd8f7c str r4, [r0, #0x38] */
/* @0xd8f80 str r12, [sp, #0x4] */
/* @0xd8f84 mov r7, r0 */
/* @0xd8f88 blx r3 */
/* @0xd8f8c cmp r8, r4 */
/* @0xd8f90 beq 0xd90a0 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x158> */
/* @0xd8f94 ldr r3, [r8, #0x60] */
/* @0xd8f98 cmp r3, r4 */
/* @0xd8f9c beq 0xd90a0 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x158> */
/* @0xd8fa0 cmp r5, r4 */
/* @0xd8fa4 beq 0xd90a0 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x158> */
/* @0xd8fa8 ldr r2, [r3, #0x4] */
/* @0xd8fac mov r11, r4 */
/* @0xd8fb0 cmp r2, r4 */
/* @0xd8fb4 ble 0xd9038 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0xf0> */
/* @0xd8fb8 mov r10, r4 */
/* @0xd8fbc ldr r6, [r3, #0x10] */
/* @0xd8fc0 mov r3, #0 */
/* @0xd8fc4 b 0xd8fcc <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x84> */
/* @0xd8fc8 add r6, r6, #12 */
/* @0xd8fcc ldr r2, [r6, #0x8] */
/* @0xd8fd0 cmp r2, #0 */
/* @0xd8fd4 ble 0xd8fc8 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x80> */
/* @0xd8fd8 cmp r3, r11 */
/* @0xd8fdc add r3, r3, #1 */
/* @0xd8fe0 bne 0xd8fc8 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x80> */
/* @0xd8fe4 ldr r4, [r6] */
/* @0xd8fe8 mov r2, r9 */
/* @0xd8fec ldr r3, [r7] */
/* @0xd8ff0 mov r1, #6 */
/* @0xd8ff4 mov r0, r7 */
/* @0xd8ff8 str r10, [r7, #0x38] */
/* @0xd8ffc vmov s15, r4 */
/* @0xd9000 add r11, r11, #1 */
/* @0xd9004 vcvt.f64.s32 d7, s15 */
/* @0xd9008 vmov r4, r5, d7 */
/* @0xd900c vstr s14, [r7, #44] */
/* @0xd9010 str r5, [r7, #0x30] */
/* @0xd9014 ldr r3, [r3, #0x8] */
/* @0xd9018 blx r3 */
/* @0xd901c ldr r0, [r6, #0x4] */
/* @0xd9020 mov r1, r7 */
/* @0xd9024 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd9028 ldr r3, [r8, #0x60] */
/* @0xd902c ldr r2, [r3, #0x4] */
/* @0xd9030 cmp r2, r11 */
/* @0xd9034 bgt 0xd8fbc <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x74> */
/* @0xd9038 ldr r3, [r7] */
/* @0xd903c mov r1, #0 */
/* @0xd9040 ldr r2, [sp, #0x4] */
/* @0xd9044 mov r0, r7 */
/* @0xd9048 mov r6, r1 */
/* @0xd904c ldr r8, [r7, #0x1c] */
/* @0xd9050 ldr r3, [r3, #0x10] */
/* @0xd9054 blx r3 */
/* @0xd9058 vmov s15, r11 */
/* @0xd905c ldr r3, [r7] */
/* @0xd9060 mov r2, r9 */
/* @0xd9064 vcvt.f64.s32 d7, s15 */
/* @0xd9068 mov r1, #5 */
/* @0xd906c str r6, [r7, #0x38] */
/* @0xd9070 mov r0, r7 */
/* @0xd9074 vmov r4, r5, d7 */
/* @0xd9078 vstr s14, [r7, #44] */
/* @0xd907c str r5, [r7, #0x30] */
/* @0xd9080 ldr r3, [r3, #0x8] */
/* @0xd9084 blx r3 */
/* @0xd9088 ldr r3, [r7] */
/* @0xd908c mov r1, r6 */
/* @0xd9090 mov r2, r8 */
/* @0xd9094 mov r0, r7 */
/* @0xd9098 ldr r3, [r3, #0x10] */
/* @0xd909c blx r3 */
/* @0xd90a0 add sp, sp, #12 */
/* @0xd90a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xd90a8 · VM::WriteCallStack(Buffer_Standard*, VMExec*, bool) · size=1184 · insn=296 */
/* @0xd90a8 subs r3, r2, #0 */
/* @0xd90ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd90b0 mov r7, r1 */
/* @0xd90b4 sub sp, sp, #12 */
/* @0xd90b8 mov r4, r0 */
/* @0xd90bc beq 0xd9508 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x460> */
/* @0xd90c0 ldr r10, [pc, #0x478] */
/* @0xd90c4 add r5, r0, #44 */
/* @0xd90c8 ldr r3, [r0] */
/* @0xd90cc mov r6, #0 */
/* @0xd90d0 ldr r10, [pc, r10] */
/* @0xd90d4 vldr s15, [r10] */
/* @0xd90d8 vcvt.f64.u32 d7, s15 */
/* @0xd90dc str r6, [r0, #0x38] */
/* @0xd90e0 mov r2, r5 */
/* @0xd90e4 mov r1, #5 */
/* @0xd90e8 vmov r8, r9, d7 */
/* @0xd90ec vstr s14, [r4, #44] */
/* @0xd90f0 str r9, [r4, #0x30] */
/* @0xd90f4 ldr r3, [r3, #0x8] */
/* @0xd90f8 blx r3 */
/* @0xd90fc ldr r3, [r10] */
/* @0xd9100 cmp r3, r6 */
/* @0xd9104 ble 0xd9130 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x88> */
/* @0xd9108 ldr r8, [pc, #0x434] */
/* @0xd910c ldr r8, [pc, r8] */
/* @0xd9110 ldr r0, [r8] */
/* @0xd9114 mov r1, r4 */
/* @0xd9118 add r0, r0, r6, lsl #4 */
/* @0xd911c add r6, r6, #1 */
/* @0xd9120 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd9124 ldr r3, [r10] */
/* @0xd9128 cmp r3, r6 */
/* @0xd912c bgt 0xd9110 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x68> */
/* @0xd9130 ldr r3, [r4] */
/* @0xd9134 mov r9, #0 */
/* @0xd9138 ldr r12, [r4, #0x1c] */
/* @0xd913c mov r0, r4 */
/* @0xd9140 str r9, [r4, #0x2c] */
/* @0xd9144 mov r1, #5 */
/* @0xd9148 str r9, [r4, #0x30] */
/* @0xd914c mov r2, r5 */
/* @0xd9150 str r9, [r4, #0x38] */
/* @0xd9154 ldr r3, [r3, #0x8] */
/* @0xd9158 str r12, [sp, #0x4] */
/* @0xd915c blx r3 */
/* @0xd9160 cmp r7, r9 */
/* @0xd9164 moveq r6, r7 */
/* @0xd9168 beq 0xd9498 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3f0> */
/* @0xd916c mov r6, r9 */
/* @0xd9170 str r9, [sp] */
/* @0xd9174 ldr r10, [r7, #0x4c] */
/* @0xd9178 ldr r11, [r7, #0x28] */
/* @0xd917c cmp r10, #100 */
/* @0xd9180 movge r10, #100 */
/* @0xd9184 cmp r10, #0 */
/* @0xd9188 ble 0xd9320 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x278> */
/* @0xd918c ldr r3, [r11, #0x18] */
/* @0xd9190 cmp r3, #0 */
/* @0xd9194 beq 0xd9320 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x278> */
/* @0xd9198 ldr lr, [r3, #0x10] */
/* @0xd919c mov r1, #12 */
/* @0xd91a0 ldr r8, [r4] */
/* @0xd91a4 mov r3, #10 */
/* @0xd91a8 mov r2, r5 */
/* @0xd91ac str r3, [r4, #0x38] */
/* @0xd91b0 str lr, [r4, #0x2c] */
/* @0xd91b4 asr r3, lr, #31 */
/* @0xd91b8 mov r0, r4 */
/* @0xd91bc str r3, [r4, #0x30] */
/* @0xd91c0 ldr r3, [r8, #0x8] */
/* @0xd91c4 blx r3 */
/* @0xd91c8 ldr r8, [r11] */
/* @0xd91cc ldr r3, [r4] */
/* @0xd91d0 mov r1, #5 */
/* @0xd91d4 mov r2, r5 */
/* @0xd91d8 mov r0, r4 */
/* @0xd91dc vmov s15, r8 */
/* @0xd91e0 str r6, [r4, #0x38] */
/* @0xd91e4 vcvt.f64.u32 d7, s15 */
/* @0xd91e8 vmov r8, r9, d7 */
/* @0xd91ec vstr s14, [r4, #44] */
/* @0xd91f0 str r9, [r4, #0x30] */
/* @0xd91f4 ldr r3, [r3, #0x8] */
/* @0xd91f8 blx r3 */
/* @0xd91fc ldr r2, [r11, #0x10] */
/* @0xd9200 ldr r3, [r4] */
/* @0xd9204 mov r1, #5 */
/* @0xd9208 mov r0, r4 */
/* @0xd920c ldr r8, [r2, #0x78] */
/* @0xd9210 mov r2, r5 */
/* @0xd9214 str r6, [r4, #0x38] */
/* @0xd9218 vmov s15, r8 */
/* @0xd921c vcvt.f64.u32 d7, s15 */
/* @0xd9220 vmov r8, r9, d7 */
/* @0xd9224 vstr s14, [r4, #44] */
/* @0xd9228 str r9, [r4, #0x30] */
/* @0xd922c ldr r3, [r3, #0x8] */
/* @0xd9230 blx r3 */
/* @0xd9234 ldr r2, [r11, #0x14] */
/* @0xd9238 ldr r3, [r4] */
/* @0xd923c mov r1, #5 */
/* @0xd9240 mov r0, r4 */
/* @0xd9244 ldr r8, [r2, #0x78] */
/* @0xd9248 mov r2, r5 */
/* @0xd924c str r6, [r4, #0x38] */
/* @0xd9250 vmov s15, r8 */
/* @0xd9254 vcvt.f64.u32 d7, s15 */
/* @0xd9258 vmov r8, r9, d7 */
/* @0xd925c vstr s14, [r4, #44] */
/* @0xd9260 str r9, [r4, #0x30] */
/* @0xd9264 ldr r3, [r3, #0x8] */
/* @0xd9268 blx r3 */
/* @0xd926c ldr r8, [r11, #0x8] */
/* @0xd9270 ldr r3, [r4] */
/* @0xd9274 mov r0, r4 */
/* @0xd9278 str r6, [r4, #0x38] */
/* @0xd927c mov r1, #5 */
/* @0xd9280 vmov s15, r8 */
/* @0xd9284 mov r2, r5 */
/* @0xd9288 vcvt.f64.u32 d7, s15 */
/* @0xd928c vmov r8, r9, d7 */
/* @0xd9290 vstr s14, [r4, #44] */
/* @0xd9294 str r9, [r4, #0x30] */
/* @0xd9298 ldr r3, [r3, #0x8] */
/* @0xd929c blx r3 */
/* @0xd92a0 ldr r3, [r11, #0x8] */
/* @0xd92a4 ldr r8, [r7, #0x8] */
/* @0xd92a8 cmp r3, #0 */
/* @0xd92ac ldr r3, [r11, #0x38] */
/* @0xd92b0 add r8, r8, r3 */
/* @0xd92b4 ble 0xd92dc <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x234> */
/* @0xd92b8 mov r9, #0 */
/* @0xd92bc mov r0, r8 */
/* @0xd92c0 mov r1, r4 */
/* @0xd92c4 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd92c8 ldr r3, [r11, #0x8] */
/* @0xd92cc add r9, r9, #1 */
/* @0xd92d0 add r8, r8, #16 */
/* @0xd92d4 cmp r3, r9 */
/* @0xd92d8 bgt 0xd92bc <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x214> */
/* @0xd92dc ldr r12, [sp] */
/* @0xd92e0 mov r2, #1 */
/* @0xd92e4 ldr r1, [r11, #0x30] */
/* @0xd92e8 mov r3, #3392 */
/* @0xd92ec mov r0, r4 */
/* @0xd92f0 movt r3, #0x3 */
/* @0xd92f4 add r12, r12, r2 */
/* @0xd92f8 sub r10, r10, #1 */
/* @0xd92fc str r12, [sp] */
/* @0xd9300 bl 0xd8f48 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi> */
/* @0xd9304 ldr r2, [r11, #0xc] */
/* @0xd9308 cmp r10, #0 */
/* @0xd930c ldr r12, [r7, #0x40] */
/* @0xd9310 ldr r3, [r7, #0x8] */
/* @0xd9314 rsb r12, r2, r12 */
/* @0xd9318 add r11, r3, r12 */
/* @0xd931c bgt 0xd918c <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0xe4> */
/* @0xd9320 ldr r7, [r7, #0x4] */
/* @0xd9324 cmp r7, #0 */
/* @0xd9328 beq 0xd9494 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3ec> */
/* @0xd932c ldr r3, [r7, #0x2c] */
/* @0xd9330 mov lr, #10 */
/* @0xd9334 ldr r12, [r4] */
/* @0xd9338 mov r1, #12 */
/* @0xd933c mov r2, r5 */
/* @0xd9340 mov r0, r4 */
/* @0xd9344 ldr r3, [r3, #0x10] */
/* @0xd9348 str lr, [r4, #0x38] */
/* @0xd934c asr r9, r3, #31 */
/* @0xd9350 str r3, [r4, #0x2c] */
/* @0xd9354 str r9, [r4, #0x30] */
/* @0xd9358 ldr r3, [r12, #0x8] */
/* @0xd935c blx r3 */
/* @0xd9360 ldr r8, [r7, #0x44] */
/* @0xd9364 ldr r3, [r4] */
/* @0xd9368 mov r1, #5 */
/* @0xd936c mov r2, r5 */
/* @0xd9370 mov r0, r4 */
/* @0xd9374 vmov s15, r8 */
/* @0xd9378 str r6, [r4, #0x38] */
/* @0xd937c vcvt.f64.u32 d7, s15 */
/* @0xd9380 vmov r8, r9, d7 */
/* @0xd9384 vstr s14, [r4, #44] */
/* @0xd9388 str r9, [r4, #0x30] */
/* @0xd938c ldr r3, [r3, #0x8] */
/* @0xd9390 blx r3 */
/* @0xd9394 ldr r12, [r7, #0x14] */
/* @0xd9398 ldr r3, [r4] */
/* @0xd939c mov r1, #5 */
/* @0xd93a0 mov r2, r5 */
/* @0xd93a4 mov r0, r4 */
/* @0xd93a8 ldr r8, [r12, #0x78] */
/* @0xd93ac str r6, [r4, #0x38] */
/* @0xd93b0 vmov s15, r8 */
/* @0xd93b4 vcvt.f64.u32 d7, s15 */
/* @0xd93b8 vmov r8, r9, d7 */
/* @0xd93bc vstr s14, [r4, #44] */
/* @0xd93c0 str r9, [r4, #0x30] */
/* @0xd93c4 ldr r3, [r3, #0x8] */
/* @0xd93c8 blx r3 */
/* @0xd93cc ldr r12, [r7, #0x18] */
/* @0xd93d0 ldr r3, [r4] */
/* @0xd93d4 mov r1, #5 */
/* @0xd93d8 mov r2, r5 */
/* @0xd93dc mov r0, r4 */
/* @0xd93e0 ldr r8, [r12, #0x78] */
/* @0xd93e4 str r6, [r4, #0x38] */
/* @0xd93e8 vmov s15, r8 */
/* @0xd93ec vcvt.f64.u32 d7, s15 */
/* @0xd93f0 vmov r8, r9, d7 */
/* @0xd93f4 vstr s14, [r4, #44] */
/* @0xd93f8 str r9, [r4, #0x30] */
/* @0xd93fc ldr r3, [r3, #0x8] */
/* @0xd9400 blx r3 */
/* @0xd9404 ldr r8, [r7, #0x20] */
/* @0xd9408 ldr r3, [r4] */
/* @0xd940c mov r0, r4 */
/* @0xd9410 str r6, [r4, #0x38] */
/* @0xd9414 mov r1, #5 */
/* @0xd9418 vmov s15, r8 */
/* @0xd941c mov r2, r5 */
/* @0xd9420 vcvt.f64.u32 d7, s15 */
/* @0xd9424 vmov r8, r9, d7 */
/* @0xd9428 vstr s14, [r4, #44] */
/* @0xd942c str r9, [r4, #0x30] */
/* @0xd9430 ldr r3, [r3, #0x8] */
/* @0xd9434 blx r3 */
/* @0xd9438 ldr r3, [r7, #0x20] */
/* @0xd943c ldr r8, [r7, #0x1c] */
/* @0xd9440 cmp r3, #0 */
/* @0xd9444 movgt r9, #0 */
/* @0xd9448 ble 0xd946c <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3c4> */
/* @0xd944c mov r0, r8 */
/* @0xd9450 mov r1, r4 */
/* @0xd9454 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd9458 ldr r3, [r7, #0x20] */
/* @0xd945c add r9, r9, #1 */
/* @0xd9460 add r8, r8, #16 */
/* @0xd9464 cmp r3, r9 */
/* @0xd9468 bgt 0xd944c <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3a4> */
/* @0xd946c ldr r12, [sp] */
/* @0xd9470 mov r2, #1 */
/* @0xd9474 mov r3, #3392 */
/* @0xd9478 mov r0, r4 */
/* @0xd947c movt r3, #0x3 */
/* @0xd9480 ldr r1, [r7, #0x10] */
/* @0xd9484 add r12, r12, r2 */
/* @0xd9488 str r12, [sp] */
/* @0xd948c bl 0xd8f48 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi> */
/* @0xd9490 b 0xd9174 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0xcc> */
/* @0xd9494 ldr r6, [sp] */
/* @0xd9498 ldr r3, [r4] */
/* @0xd949c mov r1, #0 */
/* @0xd94a0 ldr r2, [sp, #0x4] */
/* @0xd94a4 mov r0, r4 */
/* @0xd94a8 mov r8, r1 */
/* @0xd94ac ldr r9, [r4, #0x1c] */
/* @0xd94b0 ldr r3, [r3, #0x10] */
/* @0xd94b4 blx r3 */
/* @0xd94b8 vmov s15, r6 */
/* @0xd94bc ldr r3, [r4] */
/* @0xd94c0 mov r2, r5 */
/* @0xd94c4 vcvt.f64.u32 d7, s15 */
/* @0xd94c8 str r8, [r4, #0x38] */
/* @0xd94cc mov r0, r4 */
/* @0xd94d0 mov r1, #5 */
/* @0xd94d4 vmov r6, r7, d7 */
/* @0xd94d8 vstr s14, [r4, #44] */
/* @0xd94dc str r7, [r4, #0x30] */
/* @0xd94e0 ldr r3, [r3, #0x8] */
/* @0xd94e4 blx r3 */
/* @0xd94e8 ldr r3, [r4] */
/* @0xd94ec mov r1, r8 */
/* @0xd94f0 mov r2, r9 */
/* @0xd94f4 mov r0, r4 */
/* @0xd94f8 ldr r3, [r3, #0x10] */
/* @0xd94fc blx r3 */
/* @0xd9500 add sp, sp, #12 */
/* @0xd9504 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd9508 mov r2, r0 */
/* @0xd950c str r3, [r0, #0x38] */
/* @0xd9510 ldr r12, [r2], #44 */
/* @0xd9514 mov r1, #0 */
/* @0xd9518 movw r3, #0xffff */
/* @0xd951c movt r1, #0xffe0 */
/* @0xd9520 movt r3, #0x41ef */
/* @0xd9524 str r1, [r0, #0x2c] */
/* @0xd9528 str r3, [r0, #0x30] */
/* @0xd952c mov r1, #5 */
/* @0xd9530 ldr r3, [r12, #0x8] */
/* @0xd9534 blx r3 */
/* @0xd9538 add sp, sp, #12 */
/* @0xd953c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd9540 eorseq r4, r1, r12, lsr r12 */
/* @0xd9544 eorseq r4, r1, r4, lsl #24 */

/* ── FUNC 0xd9548 · VM::GetInstanceVariables(Buffer_Standard*, YYObjectBase*, bool, int, int) · size=424 · insn=106 */
/* @0xd9548 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd954c vpush {d8} */
/* @0xd9550 sub sp, sp, #20 */
/* @0xd9554 ldr lr, [r0] */
/* @0xd9558 add r12, r0, #44 */
/* @0xd955c str r3, [sp, #0x8] */
/* @0xd9560 mov r4, r2 */
/* @0xd9564 ldr r3, [r0, #0x1c] */
/* @0xd9568 eor r4, r4, #1 */
/* @0xd956c str r12, [sp, #0x4] */
/* @0xd9570 mov r7, r1 */
/* @0xd9574 mov r12, #0 */
/* @0xd9578 ldr r2, [sp, #0x4] */
/* @0xd957c str r12, [r0, #0x2c] */
/* @0xd9580 mov r1, #5 */
/* @0xd9584 str r12, [r0, #0x30] */
/* @0xd9588 cmp r7, #0 */
/* @0xd958c orreq r4, r4, #1 */
/* @0xd9590 ldr r6, [lr, #0x8] */
/* @0xd9594 mov r5, r0 */
/* @0xd9598 str r12, [r0, #0x38] */
/* @0xd959c str r3, [sp, #0xc] */
/* @0xd95a0 blx r6 */
/* @0xd95a4 cmp r4, #0 */
/* @0xd95a8 bne 0xd96dc <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x194> */
/* @0xd95ac ldr r2, [r7, #0x60] */
/* @0xd95b0 cmp r2, #0 */
/* @0xd95b4 beq 0xd96dc <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x194> */
/* @0xd95b8 ldr r8, [r2, #0x4] */
/* @0xd95bc cmp r8, #0 */
/* @0xd95c0 ble 0xd96e8 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x1a0> */
/* @0xd95c4 mvn r11, #-16777216 */
/* @0xd95c8 mov r9, r4 */
/* @0xd95cc ldr r3, [r2, #0x4] */
/* @0xd95d0 cmp r3, r4 */
/* @0xd95d4 movlt r3, #0 */
/* @0xd95d8 blt 0xd9608 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xc0> */
/* @0xd95dc ldr r3, [r2, #0x10] */
/* @0xd95e0 mov r2, #0 */
/* @0xd95e4 b 0xd95ec <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xa4> */
/* @0xd95e8 add r3, r3, #12 */
/* @0xd95ec ldr r1, [r3, #0x8] */
/* @0xd95f0 cmp r1, #0 */
/* @0xd95f4 ble 0xd95e8 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xa0> */
/* @0xd95f8 cmp r4, r2 */
/* @0xd95fc add r2, r2, #1 */
/* @0xd9600 bne 0xd95e8 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0xa0> */
/* @0xd9604 ldr r10, [r3], #4 */
/* @0xd9608 ldr r6, [r3] */
/* @0xd960c ldr r3, [r6, #0xc] */
/* @0xd9610 bic r3, r3, #-16777216 */
/* @0xd9614 cmp r3, r11 */
/* @0xd9618 beq 0xd9664 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x11c> */
/* @0xd961c ldr r12, [sp, #0x8] */
/* @0xd9620 mov r2, #0 */
/* @0xd9624 mov r1, #6 */
/* @0xd9628 str r2, [r5, #0x38] */
/* @0xd962c add r3, r12, r10 */
/* @0xd9630 ldr r12, [r5] */
/* @0xd9634 mov r0, r5 */
/* @0xd9638 ldr r2, [sp, #0x4] */
/* @0xd963c vmov s13, r3 */
/* @0xd9640 add r9, r9, #1 */
/* @0xd9644 vcvt.f64.s32 d7, s13 */
/* @0xd9648 vstr s14, [r5, #44] */
/* @0xd964c vstr s15, [r5, #48] */
/* @0xd9650 ldr r3, [r12, #0x8] */
/* @0xd9654 blx r3 */
/* @0xd9658 mov r0, r6 */
/* @0xd965c mov r1, r5 */
/* @0xd9660 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xd9664 add r4, r4, #1 */
/* @0xd9668 cmp r4, r8 */
/* @0xd966c ldrne r2, [r7, #0x60] */
/* @0xd9670 bne 0xd95cc <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x84> */
/* @0xd9674 vmov s16, r9 */
/* @0xd9678 ldr r3, [r5] */
/* @0xd967c mov r1, #0 */
/* @0xd9680 ldr r2, [sp, #0xc] */
/* @0xd9684 mov r0, r5 */
/* @0xd9688 mov r4, r1 */
/* @0xd968c ldr r8, [r5, #0x1c] */
/* @0xd9690 ldr r3, [r3, #0x10] */
/* @0xd9694 blx r3 */
/* @0xd9698 vcvt.f64.u32 d7, s16 */
/* @0xd969c ldr r3, [r5] */
/* @0xd96a0 mov r1, #5 */
/* @0xd96a4 ldr r2, [sp, #0x4] */
/* @0xd96a8 mov r0, r5 */
/* @0xd96ac str r4, [r5, #0x38] */
/* @0xd96b0 vmov r6, r7, d7 */
/* @0xd96b4 vstr s14, [r5, #44] */
/* @0xd96b8 str r7, [r5, #0x30] */
/* @0xd96bc ldr r3, [r3, #0x8] */
/* @0xd96c0 blx r3 */
/* @0xd96c4 ldr r3, [r5] */
/* @0xd96c8 mov r1, r4 */
/* @0xd96cc mov r2, r8 */
/* @0xd96d0 mov r0, r5 */
/* @0xd96d4 ldr r3, [r3, #0x10] */
/* @0xd96d8 blx r3 */
/* @0xd96dc add sp, sp, #20 */
/* @0xd96e0 vpop {d8} */
/* @0xd96e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd96e8 vmov s16, r4 */
/* @0xd96ec b 0xd9678 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii+0x130> */

/* ── FUNC 0xd96f0 · VM::WriteInstanceBuiltInVariables(Buffer_Standard*, CInstance*) · size=5848 · insn=1462 */
/* @0xd96f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd96f4 add r6, r0, #44 */
/* @0xd96f8 ldr r4, [r1, #0x78] */
/* @0xd96fc mov r9, r0 */
/* @0xd9700 ldr r3, [r0] */
/* @0xd9704 sub sp, sp, #28 */
/* @0xd9708 mov r8, #0 */
/* @0xd970c mov r7, r1 */
/* @0xd9710 vmov s13, r4 */
/* @0xd9714 str r8, [r0, #0x38] */
/* @0xd9718 mov r2, r6 */
/* @0xd971c mov r1, #5 */
/* @0xd9720 vcvt.f64.u32 d6, s13 */
/* @0xd9724 vmov r4, r5, d6 */
/* @0xd9728 vstr s12, [r9, #44] */
/* @0xd972c str r5, [r9, #0x30] */
/* @0xd9730 ldr r3, [r3, #0x8] */
/* @0xd9734 blx r3 */
/* @0xd9738 ldr r4, [r7, #0x7c] */
/* @0xd973c ldr r3, [r9] */
/* @0xd9740 mov r2, r6 */
/* @0xd9744 mov r1, #5 */
/* @0xd9748 str r8, [r9, #0x38] */
/* @0xd974c vmov s15, r4 */
/* @0xd9750 mov r0, r9 */
/* @0xd9754 vcvt.f64.u32 d7, s15 */
/* @0xd9758 vmov r4, r5, d7 */
/* @0xd975c vstr s14, [r9, #44] */
/* @0xd9760 str r5, [r9, #0x30] */
/* @0xd9764 ldr r3, [r3, #0x8] */
/* @0xd9768 blx r3 */
/* @0xd976c vldr s15, [r7, #180] */
/* @0xd9770 vcvt.f64.f32 d6, s15 */
/* @0xd9774 ldr r3, [r9] */
/* @0xd9778 mov r2, r6 */
/* @0xd977c mov r1, #8 */
/* @0xd9780 str r8, [r9, #0x38] */
/* @0xd9784 mov r0, r9 */
/* @0xd9788 vmov r4, r5, d6 */
/* @0xd978c vstr s12, [r9, #44] */
/* @0xd9790 str r5, [r9, #0x30] */
/* @0xd9794 ldr r3, [r3, #0x8] */
/* @0xd9798 blx r3 */
/* @0xd979c vldr s15, [r7, #184] */
/* @0xd97a0 vcvt.f64.f32 d6, s15 */
/* @0xd97a4 ldr r3, [r9] */
/* @0xd97a8 mov r2, r6 */
/* @0xd97ac mov r1, #8 */
/* @0xd97b0 str r8, [r9, #0x38] */
/* @0xd97b4 mov r0, r9 */
/* @0xd97b8 vmov r4, r5, d6 */
/* @0xd97bc vstr s12, [r9, #44] */
/* @0xd97c0 str r5, [r9, #0x30] */
/* @0xd97c4 ldr r3, [r3, #0x8] */
/* @0xd97c8 blx r3 */
/* @0xd97cc vldr s15, [r7, #204] */
/* @0xd97d0 vcvt.f64.f32 d6, s15 */
/* @0xd97d4 ldr r3, [r9] */
/* @0xd97d8 mov r2, r6 */
/* @0xd97dc mov r1, #8 */
/* @0xd97e0 str r8, [r9, #0x38] */
/* @0xd97e4 mov r0, r9 */
/* @0xd97e8 vmov r4, r5, d6 */
/* @0xd97ec vstr s12, [r9, #44] */
/* @0xd97f0 str r5, [r9, #0x30] */
/* @0xd97f4 ldr r3, [r3, #0x8] */
/* @0xd97f8 blx r3 */
/* @0xd97fc vldr s15, [r7, #212] */
/* @0xd9800 vcvt.f64.f32 d6, s15 */
/* @0xd9804 ldr r3, [r9] */
/* @0xd9808 mov r2, r6 */
/* @0xd980c mov r1, #8 */
/* @0xd9810 str r8, [r9, #0x38] */
/* @0xd9814 mov r0, r9 */
/* @0xd9818 vmov r4, r5, d6 */
/* @0xd981c vstr s12, [r9, #44] */
/* @0xd9820 str r5, [r9, #0x30] */
/* @0xd9824 ldr r3, [r3, #0x8] */
/* @0xd9828 blx r3 */
/* @0xd982c vldr s15, [r7, #220] */
/* @0xd9830 vcvt.f64.f32 d6, s15 */
/* @0xd9834 ldr r3, [r9] */
/* @0xd9838 mov r2, r6 */
/* @0xd983c mov r1, #8 */
/* @0xd9840 str r8, [r9, #0x38] */
/* @0xd9844 mov r0, r9 */
/* @0xd9848 vmov r4, r5, d6 */
/* @0xd984c vstr s12, [r9, #44] */
/* @0xd9850 str r5, [r9, #0x30] */
/* @0xd9854 ldr r3, [r3, #0x8] */
/* @0xd9858 blx r3 */
/* @0xd985c vldr s15, [r7, #216] */
/* @0xd9860 vcvt.f64.f32 d6, s15 */
/* @0xd9864 ldr r3, [r9] */
/* @0xd9868 mov r2, r6 */
/* @0xd986c mov r1, #8 */
/* @0xd9870 str r8, [r9, #0x38] */
/* @0xd9874 mov r0, r9 */
/* @0xd9878 vmov r4, r5, d6 */
/* @0xd987c vstr s12, [r9, #44] */
/* @0xd9880 str r5, [r9, #0x30] */
/* @0xd9884 ldr r3, [r3, #0x8] */
/* @0xd9888 blx r3 */
/* @0xd988c vldr s15, [r7, #224] */
/* @0xd9890 vcvt.f64.f32 d6, s15 */
/* @0xd9894 ldr r3, [r9] */
/* @0xd9898 mov r2, r6 */
/* @0xd989c mov r1, #8 */
/* @0xd98a0 str r8, [r9, #0x38] */
/* @0xd98a4 mov r0, r9 */
/* @0xd98a8 vmov r4, r5, d6 */
/* @0xd98ac vstr s12, [r9, #44] */
/* @0xd98b0 str r5, [r9, #0x30] */
/* @0xd98b4 ldr r3, [r3, #0x8] */
/* @0xd98b8 blx r3 */
/* @0xd98bc vldr s15, [r7, #228] */
/* @0xd98c0 vcvt.f64.f32 d6, s15 */
/* @0xd98c4 ldr r3, [r9] */
/* @0xd98c8 mov r2, r6 */
/* @0xd98cc mov r1, #8 */
/* @0xd98d0 str r8, [r9, #0x38] */
/* @0xd98d4 mov r0, r9 */
/* @0xd98d8 vmov r4, r5, d6 */
/* @0xd98dc vstr s12, [r9, #44] */
/* @0xd98e0 str r5, [r9, #0x30] */
/* @0xd98e4 ldr r3, [r3, #0x8] */
/* @0xd98e8 blx r3 */
/* @0xd98ec vldr s15, [r7, #208] */
/* @0xd98f0 vcvt.f64.f32 d6, s15 */
/* @0xd98f4 ldr r3, [r9] */
/* @0xd98f8 mov r2, r6 */
/* @0xd98fc mov r1, #8 */
/* @0xd9900 str r8, [r9, #0x38] */
/* @0xd9904 mov r0, r9 */
/* @0xd9908 vmov r4, r5, d6 */
/* @0xd990c vstr s12, [r9, #44] */
/* @0xd9910 str r5, [r9, #0x30] */
/* @0xd9914 ldr r3, [r3, #0x8] */
/* @0xd9918 blx r3 */
/* @0xd991c vldr s15, [r7, #196] */
/* @0xd9920 vcvt.f64.f32 d6, s15 */
/* @0xd9924 ldr r3, [r9] */
/* @0xd9928 mov r2, r6 */
/* @0xd992c mov r1, #8 */
/* @0xd9930 str r8, [r9, #0x38] */
/* @0xd9934 mov r0, r9 */
/* @0xd9938 vmov r4, r5, d6 */
/* @0xd993c vstr s12, [r9, #44] */
/* @0xd9940 str r5, [r9, #0x30] */
/* @0xd9944 ldr r3, [r3, #0x8] */
/* @0xd9948 blx r3 */
/* @0xd994c vldr s15, [r7, #200] */
/* @0xd9950 vcvt.f64.f32 d6, s15 */
/* @0xd9954 ldr r3, [r9] */
/* @0xd9958 mov r2, r6 */
/* @0xd995c mov r1, #8 */
/* @0xd9960 str r8, [r9, #0x38] */
/* @0xd9964 mov r0, r9 */
/* @0xd9968 vmov r4, r5, d6 */
/* @0xd996c vstr s12, [r9, #44] */
/* @0xd9970 str r5, [r9, #0x30] */
/* @0xd9974 ldr r3, [r3, #0x8] */
/* @0xd9978 blx r3 */
/* @0xd997c ldr r4, [r7, #0x8c] */
/* @0xd9980 ldr r3, [r9] */
/* @0xd9984 mov r2, r6 */
/* @0xd9988 mov r1, #5 */
/* @0xd998c str r8, [r9, #0x38] */
/* @0xd9990 vmov s15, r4 */
/* @0xd9994 mov r0, r9 */
/* @0xd9998 vcvt.f64.u32 d7, s15 */
/* @0xd999c vmov r4, r5, d7 */
/* @0xd99a0 vstr s14, [r9, #44] */
/* @0xd99a4 str r5, [r9, #0x30] */
/* @0xd99a8 ldr r3, [r3, #0x8] */
/* @0xd99ac blx r3 */
/* @0xd99b0 vldr s15, [r7, #164] */
/* @0xd99b4 vcvt.f64.f32 d6, s15 */
/* @0xd99b8 ldr r3, [r9] */
/* @0xd99bc mov r2, r6 */
/* @0xd99c0 mov r1, #8 */
/* @0xd99c4 str r8, [r9, #0x38] */
/* @0xd99c8 mov r0, r9 */
/* @0xd99cc vmov r4, r5, d6 */
/* @0xd99d0 vstr s12, [r9, #44] */
/* @0xd99d4 str r5, [r9, #0x30] */
/* @0xd99d8 ldr r3, [r3, #0x8] */
/* @0xd99dc blx r3 */
/* @0xd99e0 vldr s15, [r7, #160] */
/* @0xd99e4 vcvt.f64.f32 d6, s15 */
/* @0xd99e8 ldr r3, [r9] */
/* @0xd99ec mov r2, r6 */
/* @0xd99f0 mov r1, #8 */
/* @0xd99f4 str r8, [r9, #0x38] */
/* @0xd99f8 mov r0, r9 */
/* @0xd99fc vmov r4, r5, d6 */
/* @0xd9a00 vstr s12, [r9, #44] */
/* @0xd9a04 str r5, [r9, #0x30] */
/* @0xd9a08 ldr r3, [r3, #0x8] */
/* @0xd9a0c blx r3 */
/* @0xd9a10 ldr r4, [r7, #0xa8] */
/* @0xd9a14 ldr r3, [r9] */
/* @0xd9a18 mov r2, r6 */
/* @0xd9a1c mov r1, #5 */
/* @0xd9a20 str r8, [r9, #0x38] */
/* @0xd9a24 vmov s15, r4 */
/* @0xd9a28 mov r0, r9 */
/* @0xd9a2c vcvt.f64.u32 d7, s15 */
/* @0xd9a30 vmov r4, r5, d7 */
/* @0xd9a34 vstr s14, [r9, #44] */
/* @0xd9a38 str r5, [r9, #0x30] */
/* @0xd9a3c ldr r3, [r3, #0x8] */
/* @0xd9a40 blx r3 */
/* @0xd9a44 vldr s15, [r7, #144] */
/* @0xd9a48 vcvt.f64.f32 d6, s15 */
/* @0xd9a4c ldr r3, [r9] */
/* @0xd9a50 mov r2, r6 */
/* @0xd9a54 mov r1, #8 */
/* @0xd9a58 str r8, [r9, #0x38] */
/* @0xd9a5c mov r0, r9 */
/* @0xd9a60 vmov r4, r5, d6 */
/* @0xd9a64 vstr s12, [r9, #44] */
/* @0xd9a68 str r5, [r9, #0x30] */
/* @0xd9a6c ldr r3, [r3, #0x8] */
/* @0xd9a70 blx r3 */
/* @0xd9a74 mov r0, r7 */
/* @0xd9a78 bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0xd9a7c ldr r3, [r9] */
/* @0xd9a80 mov r2, r6 */
/* @0xd9a84 mov r1, #5 */
/* @0xd9a88 str r8, [r9, #0x38] */
/* @0xd9a8c vmov s15, r0 */
/* @0xd9a90 mov r0, r9 */
/* @0xd9a94 vcvt.f64.u32 d7, s15 */
/* @0xd9a98 vmov r4, r5, d7 */
/* @0xd9a9c vstr s14, [r9, #44] */
/* @0xd9aa0 str r5, [r9, #0x30] */
/* @0xd9aa4 ldr r3, [r3, #0x8] */
/* @0xd9aa8 blx r3 */
/* @0xd9aac vldr s15, [r7, #148] */
/* @0xd9ab0 vcvt.f64.f32 d6, s15 */
/* @0xd9ab4 ldr r3, [r9] */
/* @0xd9ab8 mov r2, r6 */
/* @0xd9abc mov r1, #8 */
/* @0xd9ac0 str r8, [r9, #0x38] */
/* @0xd9ac4 mov r0, r9 */
/* @0xd9ac8 vmov r4, r5, d6 */
/* @0xd9acc vstr s12, [r9, #44] */
/* @0xd9ad0 str r5, [r9, #0x30] */
/* @0xd9ad4 ldr r3, [r3, #0x8] */
/* @0xd9ad8 blx r3 */
/* @0xd9adc vldr s15, [r7, #152] */
/* @0xd9ae0 vcvt.f64.f32 d6, s15 */
/* @0xd9ae4 ldr r3, [r9] */
/* @0xd9ae8 mov r2, r6 */
/* @0xd9aec mov r1, #8 */
/* @0xd9af0 str r8, [r9, #0x38] */
/* @0xd9af4 mov r0, r9 */
/* @0xd9af8 vmov r4, r5, d6 */
/* @0xd9afc vstr s12, [r9, #44] */
/* @0xd9b00 str r5, [r9, #0x30] */
/* @0xd9b04 ldr r3, [r3, #0x8] */
/* @0xd9b08 blx r3 */
/* @0xd9b0c vldr s15, [r7, #156] */
/* @0xd9b10 vcvt.f64.f32 d6, s15 */
/* @0xd9b14 ldr r3, [r9] */
/* @0xd9b18 mov r2, r6 */
/* @0xd9b1c mov r1, #8 */
/* @0xd9b20 str r8, [r9, #0x38] */
/* @0xd9b24 mov r0, r9 */
/* @0xd9b28 vmov r4, r5, d6 */
/* @0xd9b2c vstr s12, [r9, #44] */
/* @0xd9b30 str r5, [r9, #0x30] */
/* @0xd9b34 ldr r3, [r3, #0x8] */
/* @0xd9b38 blx r3 */
/* @0xd9b3c mov r1, r8 */
/* @0xd9b40 mov r0, r7 */
/* @0xd9b44 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9b48 ldr r3, [r9] */
/* @0xd9b4c mov r2, r6 */
/* @0xd9b50 mov r1, #5 */
/* @0xd9b54 str r8, [r9, #0x38] */
/* @0xd9b58 vmov s15, r0 */
/* @0xd9b5c mov r0, r9 */
/* @0xd9b60 vcvt.f64.u32 d7, s15 */
/* @0xd9b64 vmov r4, r5, d7 */
/* @0xd9b68 vstr s14, [r9, #44] */
/* @0xd9b6c str r5, [r9, #0x30] */
/* @0xd9b70 ldr r3, [r3, #0x8] */
/* @0xd9b74 blx r3 */
/* @0xd9b78 mov r1, #1 */
/* @0xd9b7c mov r0, r7 */
/* @0xd9b80 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9b84 ldr r3, [r9] */
/* @0xd9b88 mov r2, r6 */
/* @0xd9b8c mov r1, #5 */
/* @0xd9b90 str r8, [r9, #0x38] */
/* @0xd9b94 vmov s13, r0 */
/* @0xd9b98 mov r0, r9 */
/* @0xd9b9c vcvt.f64.u32 d6, s13 */
/* @0xd9ba0 vmov r4, r5, d6 */
/* @0xd9ba4 vstr s12, [r9, #44] */
/* @0xd9ba8 str r5, [r9, #0x30] */
/* @0xd9bac ldr r3, [r3, #0x8] */
/* @0xd9bb0 blx r3 */
/* @0xd9bb4 mov r1, #2 */
/* @0xd9bb8 mov r0, r7 */
/* @0xd9bbc bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9bc0 ldr r3, [r9] */
/* @0xd9bc4 mov r2, r6 */
/* @0xd9bc8 mov r1, #5 */
/* @0xd9bcc str r8, [r9, #0x38] */
/* @0xd9bd0 vmov s15, r0 */
/* @0xd9bd4 mov r0, r9 */
/* @0xd9bd8 vcvt.f64.u32 d7, s15 */
/* @0xd9bdc vmov r4, r5, d7 */
/* @0xd9be0 vstr s14, [r9, #44] */
/* @0xd9be4 str r5, [r9, #0x30] */
/* @0xd9be8 ldr r3, [r3, #0x8] */
/* @0xd9bec blx r3 */
/* @0xd9bf0 mov r1, #3 */
/* @0xd9bf4 mov r0, r7 */
/* @0xd9bf8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9bfc ldr r3, [r9] */
/* @0xd9c00 mov r2, r6 */
/* @0xd9c04 mov r1, #5 */
/* @0xd9c08 str r8, [r9, #0x38] */
/* @0xd9c0c vmov s13, r0 */
/* @0xd9c10 mov r0, r9 */
/* @0xd9c14 vcvt.f64.u32 d6, s13 */
/* @0xd9c18 vmov r4, r5, d6 */
/* @0xd9c1c vstr s12, [r9, #44] */
/* @0xd9c20 str r5, [r9, #0x30] */
/* @0xd9c24 ldr r3, [r3, #0x8] */
/* @0xd9c28 blx r3 */
/* @0xd9c2c mov r1, #4 */
/* @0xd9c30 mov r0, r7 */
/* @0xd9c34 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9c38 ldr r3, [r9] */
/* @0xd9c3c mov r2, r6 */
/* @0xd9c40 mov r1, #5 */
/* @0xd9c44 str r8, [r9, #0x38] */
/* @0xd9c48 vmov s15, r0 */
/* @0xd9c4c mov r0, r9 */
/* @0xd9c50 vcvt.f64.u32 d7, s15 */
/* @0xd9c54 vmov r4, r5, d7 */
/* @0xd9c58 vstr s14, [r9, #44] */
/* @0xd9c5c str r5, [r9, #0x30] */
/* @0xd9c60 ldr r3, [r3, #0x8] */
/* @0xd9c64 blx r3 */
/* @0xd9c68 mov r1, #5 */
/* @0xd9c6c mov r0, r7 */
/* @0xd9c70 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9c74 ldr r3, [r9] */
/* @0xd9c78 mov r2, r6 */
/* @0xd9c7c mov r1, #5 */
/* @0xd9c80 str r8, [r9, #0x38] */
/* @0xd9c84 vmov s13, r0 */
/* @0xd9c88 mov r0, r9 */
/* @0xd9c8c vcvt.f64.u32 d6, s13 */
/* @0xd9c90 vmov r4, r5, d6 */
/* @0xd9c94 vstr s12, [r9, #44] */
/* @0xd9c98 str r5, [r9, #0x30] */
/* @0xd9c9c ldr r3, [r3, #0x8] */
/* @0xd9ca0 blx r3 */
/* @0xd9ca4 mov r1, #6 */
/* @0xd9ca8 mov r0, r7 */
/* @0xd9cac bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9cb0 ldr r3, [r9] */
/* @0xd9cb4 mov r2, r6 */
/* @0xd9cb8 mov r1, #5 */
/* @0xd9cbc str r8, [r9, #0x38] */
/* @0xd9cc0 vmov s15, r0 */
/* @0xd9cc4 mov r0, r9 */
/* @0xd9cc8 vcvt.f64.u32 d7, s15 */
/* @0xd9ccc vmov r4, r5, d7 */
/* @0xd9cd0 vstr s14, [r9, #44] */
/* @0xd9cd4 str r5, [r9, #0x30] */
/* @0xd9cd8 ldr r3, [r3, #0x8] */
/* @0xd9cdc blx r3 */
/* @0xd9ce0 mov r1, #7 */
/* @0xd9ce4 mov r0, r7 */
/* @0xd9ce8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9cec ldr r3, [r9] */
/* @0xd9cf0 mov r2, r6 */
/* @0xd9cf4 mov r1, #5 */
/* @0xd9cf8 str r8, [r9, #0x38] */
/* @0xd9cfc vmov s13, r0 */
/* @0xd9d00 mov r0, r9 */
/* @0xd9d04 vcvt.f64.u32 d6, s13 */
/* @0xd9d08 vmov r4, r5, d6 */
/* @0xd9d0c vstr s12, [r9, #44] */
/* @0xd9d10 str r5, [r9, #0x30] */
/* @0xd9d14 ldr r3, [r3, #0x8] */
/* @0xd9d18 blx r3 */
/* @0xd9d1c mov r1, #8 */
/* @0xd9d20 mov r0, r7 */
/* @0xd9d24 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9d28 ldr r3, [r9] */
/* @0xd9d2c mov r2, r6 */
/* @0xd9d30 mov r1, #5 */
/* @0xd9d34 str r8, [r9, #0x38] */
/* @0xd9d38 vmov s15, r0 */
/* @0xd9d3c mov r0, r9 */
/* @0xd9d40 vcvt.f64.u32 d7, s15 */
/* @0xd9d44 vmov r4, r5, d7 */
/* @0xd9d48 vstr s14, [r9, #44] */
/* @0xd9d4c str r5, [r9, #0x30] */
/* @0xd9d50 ldr r3, [r3, #0x8] */
/* @0xd9d54 blx r3 */
/* @0xd9d58 mov r1, #9 */
/* @0xd9d5c mov r0, r7 */
/* @0xd9d60 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9d64 ldr r3, [r9] */
/* @0xd9d68 mov r2, r6 */
/* @0xd9d6c mov r1, #5 */
/* @0xd9d70 str r8, [r9, #0x38] */
/* @0xd9d74 vmov s13, r0 */
/* @0xd9d78 mov r0, r9 */
/* @0xd9d7c vcvt.f64.u32 d6, s13 */
/* @0xd9d80 vmov r4, r5, d6 */
/* @0xd9d84 vstr s12, [r9, #44] */
/* @0xd9d88 str r5, [r9, #0x30] */
/* @0xd9d8c ldr r3, [r3, #0x8] */
/* @0xd9d90 blx r3 */
/* @0xd9d94 mov r1, #10 */
/* @0xd9d98 mov r0, r7 */
/* @0xd9d9c bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9da0 ldr r3, [r9] */
/* @0xd9da4 mov r2, r6 */
/* @0xd9da8 mov r1, #5 */
/* @0xd9dac str r8, [r9, #0x38] */
/* @0xd9db0 vmov s15, r0 */
/* @0xd9db4 mov r0, r9 */
/* @0xd9db8 vcvt.f64.u32 d7, s15 */
/* @0xd9dbc vmov r4, r5, d7 */
/* @0xd9dc0 vstr s14, [r9, #44] */
/* @0xd9dc4 str r5, [r9, #0x30] */
/* @0xd9dc8 ldr r3, [r3, #0x8] */
/* @0xd9dcc blx r3 */
/* @0xd9dd0 mov r1, #11 */
/* @0xd9dd4 mov r0, r7 */
/* @0xd9dd8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0xd9ddc ldr r3, [r9] */
/* @0xd9de0 mov r2, r6 */
/* @0xd9de4 mov r1, #5 */
/* @0xd9de8 str r8, [r9, #0x38] */
/* @0xd9dec vmov s13, r0 */
/* @0xd9df0 mov r0, r9 */
/* @0xd9df4 vcvt.f64.u32 d6, s13 */
/* @0xd9df8 vmov r4, r5, d6 */
/* @0xd9dfc vstr s12, [r9, #44] */
/* @0xd9e00 str r5, [r9, #0x30] */
/* @0xd9e04 ldr r3, [r3, #0x8] */
/* @0xd9e08 blx r3 */
/* @0xd9e0c ldr r4, [r7, #0x128] */
/* @0xd9e10 ldr r3, [r9] */
/* @0xd9e14 mov r2, r6 */
/* @0xd9e18 mov r1, #5 */
/* @0xd9e1c str r8, [r9, #0x38] */
/* @0xd9e20 vmov s15, r4 */
/* @0xd9e24 mov r0, r9 */
/* @0xd9e28 vcvt.f64.u32 d7, s15 */
/* @0xd9e2c vmov r4, r5, d7 */
/* @0xd9e30 vstr s14, [r9, #44] */
/* @0xd9e34 str r5, [r9, #0x30] */
/* @0xd9e38 ldr r3, [r3, #0x8] */
/* @0xd9e3c blx r3 */
/* @0xd9e40 vldr s15, [r7, #300] */
/* @0xd9e44 vcvt.f64.f32 d6, s15 */
/* @0xd9e48 ldr r3, [r9] */
/* @0xd9e4c mov r2, r6 */
/* @0xd9e50 mov r1, #8 */
/* @0xd9e54 str r8, [r9, #0x38] */
/* @0xd9e58 mov r0, r9 */
/* @0xd9e5c vmov r4, r5, d6 */
/* @0xd9e60 vstr s12, [r9, #44] */
/* @0xd9e64 str r5, [r9, #0x30] */
/* @0xd9e68 ldr r3, [r3, #0x8] */
/* @0xd9e6c blx r3 */
/* @0xd9e70 vldr s15, [r7, #304] */
/* @0xd9e74 vcvt.f64.f32 d6, s15 */
/* @0xd9e78 ldr r3, [r9] */
/* @0xd9e7c mov r2, r6 */
/* @0xd9e80 mov r1, #8 */
/* @0xd9e84 str r8, [r9, #0x38] */
/* @0xd9e88 mov r0, r9 */
/* @0xd9e8c vmov r4, r5, d6 */
/* @0xd9e90 vstr s12, [r9, #44] */
/* @0xd9e94 str r5, [r9, #0x30] */
/* @0xd9e98 ldr r3, [r3, #0x8] */
/* @0xd9e9c blx r3 */
/* @0xd9ea0 ldr r4, [r7, #0x140] */
/* @0xd9ea4 ldr r3, [r9] */
/* @0xd9ea8 mov r2, r6 */
/* @0xd9eac mov r1, #5 */
/* @0xd9eb0 str r8, [r9, #0x38] */
/* @0xd9eb4 vmov s15, r4 */
/* @0xd9eb8 mov r0, r9 */
/* @0xd9ebc vcvt.f64.u32 d7, s15 */
/* @0xd9ec0 vmov r4, r5, d7 */
/* @0xd9ec4 vstr s14, [r9, #44] */
/* @0xd9ec8 str r5, [r9, #0x30] */
/* @0xd9ecc ldr r3, [r3, #0x8] */
/* @0xd9ed0 blx r3 */
/* @0xd9ed4 vldr s15, [r7, #312] */
/* @0xd9ed8 vcvt.f64.f32 d6, s15 */
/* @0xd9edc ldr r3, [r9] */
/* @0xd9ee0 mov r2, r6 */
/* @0xd9ee4 mov r1, #8 */
/* @0xd9ee8 str r8, [r9, #0x38] */
/* @0xd9eec mov r0, r9 */
/* @0xd9ef0 vmov r4, r5, d6 */
/* @0xd9ef4 vstr s12, [r9, #44] */
/* @0xd9ef8 str r5, [r9, #0x30] */
/* @0xd9efc ldr r3, [r3, #0x8] */
/* @0xd9f00 blx r3 */
/* @0xd9f04 vldr s15, [r7, #308] */
/* @0xd9f08 vcvt.f64.f32 d6, s15 */
/* @0xd9f0c ldr r3, [r9] */
/* @0xd9f10 mov r2, r6 */
/* @0xd9f14 mov r1, #8 */
/* @0xd9f18 str r8, [r9, #0x38] */
/* @0xd9f1c mov r0, r9 */
/* @0xd9f20 vmov r4, r5, d6 */
/* @0xd9f24 vstr s12, [r9, #44] */
/* @0xd9f28 str r5, [r9, #0x30] */
/* @0xd9f2c ldr r3, [r3, #0x8] */
/* @0xd9f30 blx r3 */
/* @0xd9f34 vldr s15, [r7, #316] */
/* @0xd9f38 vcvt.f64.f32 d6, s15 */
/* @0xd9f3c ldr r3, [r9] */
/* @0xd9f40 mov r2, r6 */
/* @0xd9f44 mov r1, #8 */
/* @0xd9f48 str r8, [r9, #0x38] */
/* @0xd9f4c mov r0, r9 */
/* @0xd9f50 vmov r4, r5, d6 */
/* @0xd9f54 vstr s12, [r9, #44] */
/* @0xd9f58 str r5, [r9, #0x30] */
/* @0xd9f5c ldr r3, [r3, #0x8] */
/* @0xd9f60 blx r3 */
/* @0xd9f64 vldr s15, [r7, #188] */
/* @0xd9f68 vcvt.f64.f32 d6, s15 */
/* @0xd9f6c ldr r3, [r9] */
/* @0xd9f70 mov r2, r6 */
/* @0xd9f74 mov r1, #8 */
/* @0xd9f78 str r8, [r9, #0x38] */
/* @0xd9f7c mov r0, r9 */
/* @0xd9f80 vmov r4, r5, d6 */
/* @0xd9f84 vstr s12, [r9, #44] */
/* @0xd9f88 str r5, [r9, #0x30] */
/* @0xd9f8c ldr r3, [r3, #0x8] */
/* @0xd9f90 blx r3 */
/* @0xd9f94 vldr s15, [r7, #192] */
/* @0xd9f98 vcvt.f64.f32 d6, s15 */
/* @0xd9f9c ldr r3, [r9] */
/* @0xd9fa0 mov r2, r6 */
/* @0xd9fa4 mov r1, #8 */
/* @0xd9fa8 str r8, [r9, #0x38] */
/* @0xd9fac mov r0, r9 */
/* @0xd9fb0 vmov r4, r5, d6 */
/* @0xd9fb4 vstr s12, [r9, #44] */
/* @0xd9fb8 str r5, [r9, #0x30] */
/* @0xd9fbc ldr r3, [r3, #0x8] */
/* @0xd9fc0 blx r3 */
/* @0xd9fc4 ldrb r4, [r7, #0x67] */
/* @0xd9fc8 ldr r3, [r9] */
/* @0xd9fcc mov r2, r6 */
/* @0xd9fd0 mov r1, #5 */
/* @0xd9fd4 str r8, [r9, #0x38] */
/* @0xd9fd8 vmov s15, r4 */
/* @0xd9fdc mov r0, r9 */
/* @0xd9fe0 vcvt.f64.u32 d7, s15 */
/* @0xd9fe4 vmov r4, r5, d7 */
/* @0xd9fe8 vstr s14, [r9, #44] */
/* @0xd9fec str r5, [r9, #0x30] */
/* @0xd9ff0 ldr r3, [r3, #0x8] */
/* @0xd9ff4 blx r3 */
/* @0xd9ff8 vldr s15, [r7, #384] */
/* @0xd9ffc vcvt.f64.f32 d6, s15 */
/* @0xda000 ldr r3, [r9] */
/* @0xda004 mov r2, r6 */
/* @0xda008 mov r1, #8 */
/* @0xda00c str r8, [r9, #0x38] */
/* @0xda010 mov r0, r9 */
/* @0xda014 vmov r4, r5, d6 */
/* @0xda018 vstr s12, [r9, #44] */
/* @0xda01c str r5, [r9, #0x30] */
/* @0xda020 ldr r3, [r3, #0x8] */
/* @0xda024 blx r3 */
/* @0xda028 ldrb r4, [r7, #0x65] */
/* @0xda02c ldr r3, [r9] */
/* @0xda030 mov r2, r6 */
/* @0xda034 mov r1, #5 */
/* @0xda038 str r8, [r9, #0x38] */
/* @0xda03c vmov s15, r4 */
/* @0xda040 mov r0, r9 */
/* @0xda044 vcvt.f64.u32 d7, s15 */
/* @0xda048 vmov r4, r5, d7 */
/* @0xda04c vstr s14, [r9, #44] */
/* @0xda050 str r5, [r9, #0x30] */
/* @0xda054 ldr r3, [r3, #0x8] */
/* @0xda058 blx r3 */
/* @0xda05c ldr r4, [r7, #0xac] */
/* @0xda060 ldr r3, [r9] */
/* @0xda064 mov r2, r6 */
/* @0xda068 mov r1, #6 */
/* @0xda06c str r8, [r9, #0x38] */
/* @0xda070 vmov s13, r4 */
/* @0xda074 mov r0, r9 */
/* @0xda078 vcvt.f64.s32 d6, s13 */
/* @0xda07c vmov r4, r5, d6 */
/* @0xda080 vstr s12, [r9, #44] */
/* @0xda084 str r5, [r9, #0x30] */
/* @0xda088 ldr r3, [r3, #0x8] */
/* @0xda08c blx r3 */
/* @0xda090 ldrb r4, [r7, #0x66] */
/* @0xda094 ldr r3, [r9] */
/* @0xda098 mov r2, r6 */
/* @0xda09c str r8, [r9, #0x38] */
/* @0xda0a0 mov r0, r9 */
/* @0xda0a4 vmov s15, r4 */
/* @0xda0a8 mov r1, #5 */
/* @0xda0ac vcvt.f64.u32 d7, s15 */
/* @0xda0b0 vmov r4, r5, d7 */
/* @0xda0b4 vstr s14, [r9, #44] */
/* @0xda0b8 str r5, [r9, #0x30] */
/* @0xda0bc ldr r3, [r3, #0x8] */
/* @0xda0c0 blx r3 */
/* @0xda0c4 ldrb r3, [r7, #0x64] */
/* @0xda0c8 cmp r3, r8 */
/* @0xda0cc bne 0xdaa98 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x13a8> */
/* @0xda0d0 ldr r4, [r7, #0xec] */
/* @0xda0d4 mov r8, #0 */
/* @0xda0d8 ldr r3, [r9] */
/* @0xda0dc mov r1, #6 */
/* @0xda0e0 mov r2, r6 */
/* @0xda0e4 mov r0, r9 */
/* @0xda0e8 vmov s13, r4 */
/* @0xda0ec str r8, [r9, #0x38] */
/* @0xda0f0 vcvt.f64.s32 d6, s13 */
/* @0xda0f4 vmov r4, r5, d6 */
/* @0xda0f8 vstr s12, [r9, #44] */
/* @0xda0fc str r5, [r9, #0x30] */
/* @0xda100 ldr r3, [r3, #0x8] */
/* @0xda104 blx r3 */
/* @0xda108 ldr r4, [r7, #0xf4] */
/* @0xda10c ldr r3, [r9] */
/* @0xda110 mov r1, #6 */
/* @0xda114 mov r2, r6 */
/* @0xda118 mov r0, r9 */
/* @0xda11c vmov s15, r4 */
/* @0xda120 str r8, [r9, #0x38] */
/* @0xda124 vcvt.f64.s32 d7, s15 */
/* @0xda128 vmov r4, r5, d7 */
/* @0xda12c vstr s14, [r9, #44] */
/* @0xda130 str r5, [r9, #0x30] */
/* @0xda134 ldr r3, [r3, #0x8] */
/* @0xda138 blx r3 */
/* @0xda13c ldr r4, [r7, #0xe8] */
/* @0xda140 ldr r3, [r9] */
/* @0xda144 mov r1, #6 */
/* @0xda148 mov r2, r6 */
/* @0xda14c mov r0, r9 */
/* @0xda150 vmov s13, r4 */
/* @0xda154 str r8, [r9, #0x38] */
/* @0xda158 vcvt.f64.s32 d6, s13 */
/* @0xda15c vmov r4, r5, d6 */
/* @0xda160 vstr s12, [r9, #44] */
/* @0xda164 str r5, [r9, #0x30] */
/* @0xda168 ldr r3, [r3, #0x8] */
/* @0xda16c blx r3 */
/* @0xda170 ldr r4, [r7, #0xf0] */
/* @0xda174 ldr r3, [r9] */
/* @0xda178 mov r1, #6 */
/* @0xda17c mov r2, r6 */
/* @0xda180 mov r0, r9 */
/* @0xda184 vmov s15, r4 */
/* @0xda188 str r8, [r9, #0x38] */
/* @0xda18c vcvt.f64.s32 d7, s15 */
/* @0xda190 vmov r4, r5, d7 */
/* @0xda194 vstr s14, [r9, #44] */
/* @0xda198 str r5, [r9, #0x30] */
/* @0xda19c ldr r3, [r3, #0x8] */
/* @0xda1a0 blx r3 */
/* @0xda1a4 ldr r0, [r7, #0x8c] */
/* @0xda1a8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xda1ac subs r10, r0, #0 */
/* @0xda1b0 beq 0xdad34 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1644> */
/* @0xda1b4 vldr s15, [r10, #28] */
/* @0xda1b8 vcvt.f32.s32 s15, s15 */
/* @0xda1bc vldr s14, [r7, #152] */
/* @0xda1c0 ldr r3, [r9] */
/* @0xda1c4 mov r1, #8 */
/* @0xda1c8 mov r2, r6 */
/* @0xda1cc mov r0, r9 */
/* @0xda1d0 str r8, [r9, #0x38] */
/* @0xda1d4 vmul.f32 s15, s15, s14 */
/* @0xda1d8 vcvt.f64.f32 d6, s15 */
/* @0xda1dc vmov r4, r5, d6 */
/* @0xda1e0 vstr s12, [r9, #44] */
/* @0xda1e4 str r5, [r9, #0x30] */
/* @0xda1e8 ldr r3, [r3, #0x8] */
/* @0xda1ec blx r3 */
/* @0xda1f0 vldr s15, [r10, #32] */
/* @0xda1f4 vcvt.f32.s32 s15, s15 */
/* @0xda1f8 vldr s14, [r7, #156] */
/* @0xda1fc ldr r3, [r9] */
/* @0xda200 mov r1, #8 */
/* @0xda204 mov r2, r6 */
/* @0xda208 str r8, [r9, #0x38] */
/* @0xda20c mov r0, r9 */
/* @0xda210 vmul.f32 s15, s15, s14 */
/* @0xda214 vcvt.f64.f32 d6, s15 */
/* @0xda218 vmov r4, r5, d6 */
/* @0xda21c vstr s12, [r9, #44] */
/* @0xda220 str r5, [r9, #0x30] */
/* @0xda224 ldr r3, [r3, #0x8] */
/* @0xda228 blx r3 */
/* @0xda22c vldr s15, [r10, #36] */
/* @0xda230 vcvt.f32.s32 s15, s15 */
/* @0xda234 vldr s14, [r7, #152] */
/* @0xda238 ldr r3, [r9] */
/* @0xda23c mov r1, #8 */
/* @0xda240 mov r2, r6 */
/* @0xda244 str r8, [r9, #0x38] */
/* @0xda248 mov r0, r9 */
/* @0xda24c vmul.f32 s15, s15, s14 */
/* @0xda250 vcvt.f64.f32 d6, s15 */
/* @0xda254 vmov r4, r5, d6 */
/* @0xda258 vstr s12, [r9, #44] */
/* @0xda25c str r5, [r9, #0x30] */
/* @0xda260 ldr r3, [r3, #0x8] */
/* @0xda264 blx r3 */
/* @0xda268 vldr s15, [r10, #40] */
/* @0xda26c vcvt.f32.s32 s15, s15 */
/* @0xda270 vldr s14, [r7, #156] */
/* @0xda274 ldr r3, [r9] */
/* @0xda278 mov r0, r9 */
/* @0xda27c str r8, [r9, #0x38] */
/* @0xda280 mov r1, #8 */
/* @0xda284 mov r2, r6 */
/* @0xda288 vmul.f32 s15, s15, s14 */
/* @0xda28c vcvt.f64.f32 d6, s15 */
/* @0xda290 vmov r4, r5, d6 */
/* @0xda294 vstr s12, [r9, #44] */
/* @0xda298 str r5, [r9, #0x30] */
/* @0xda29c ldr r3, [r3, #0x8] */
/* @0xda2a0 blx r3 */
/* @0xda2a4 ldr r8, [r7, #0x84] */
/* @0xda2a8 cmp r8, #0 */
/* @0xda2ac beq 0xdaaa8 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x13b8> */
/* @0xda2b0 ldr r12, [r8] */
/* @0xda2b4 mov r11, #0 */
/* @0xda2b8 ldr r3, [r9] */
/* @0xda2bc mov r1, #5 */
/* @0xda2c0 mov r2, r6 */
/* @0xda2c4 mov r0, r9 */
/* @0xda2c8 ldrh r4, [r12, #4] */
/* @0xda2cc add r10, sp, #8 */
/* @0xda2d0 str r11, [r9, #0x38] */
/* @0xda2d4 ubfx r4, r4, #0x5, #0x1 */
/* @0xda2d8 vmov s15, r4 */
/* @0xda2dc vcvt.f64.u32 d7, s15 */
/* @0xda2e0 vmov r4, r5, d7 */
/* @0xda2e4 vstr s14, [r9, #44] */
/* @0xda2e8 str r5, [r9, #0x30] */
/* @0xda2ec ldr r3, [r3, #0x8] */
/* @0xda2f0 blx r3 */
/* @0xda2f4 ldr r12, [r8] */
/* @0xda2f8 ldr r3, [r9] */
/* @0xda2fc mov r1, #5 */
/* @0xda300 mov r2, r6 */
/* @0xda304 mov r0, r9 */
/* @0xda308 ldrh r4, [r12, #4] */
/* @0xda30c str r11, [r9, #0x38] */
/* @0xda310 ubfx r4, r4, #0x4, #0x1 */
/* @0xda314 vmov s13, r4 */
/* @0xda318 vcvt.f64.u32 d6, s13 */
/* @0xda31c vmov r4, r5, d6 */
/* @0xda320 vstr s12, [r9, #44] */
/* @0xda324 str r5, [r9, #0x30] */
/* @0xda328 ldr r3, [r3, #0x8] */
/* @0xda32c blx r3 */
/* @0xda330 ldr r3, [r8] */
/* @0xda334 vldr s15, [pc, #784] */
/* @0xda338 vldr s14, [r3, #88] */
/* @0xda33c vmul.f32 s15, s14, s15 */
/* @0xda340 vldr s14, [pc, #776] */
/* @0xda344 ldr r3, [r9] */
/* @0xda348 mov r1, #8 */
/* @0xda34c mov r2, r6 */
/* @0xda350 mov r0, r9 */
/* @0xda354 str r11, [r9, #0x38] */
/* @0xda358 vdiv.f32 s15, s15, s14 */
/* @0xda35c vcvt.f64.f32 d6, s15 */
/* @0xda360 vmov r4, r5, d6 */
/* @0xda364 vstr s12, [r9, #44] */
/* @0xda368 str r5, [r9, #0x30] */
/* @0xda36c ldr r3, [r3, #0x8] */
/* @0xda370 blx r3 */
/* @0xda374 mov r1, r11 */
/* @0xda378 mov r2, r10 */
/* @0xda37c mov r0, r7 */
/* @0xda380 bl 0x1f9684 <_Z25GV_PhysicsLinearVelocityXP9CInstanceiP6RValue> */
/* @0xda384 subs r3, r0, #0 */
/* @0xda388 beq 0xda930 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1240> */
/* @0xda38c ldr r3, [r9] */
/* @0xda390 mov r0, r9 */
/* @0xda394 str r11, [r9, #0x2c] */
/* @0xda398 mov r1, #8 */
/* @0xda39c str r11, [r9, #0x30] */
/* @0xda3a0 mov r2, r6 */
/* @0xda3a4 str r11, [r9, #0x38] */
/* @0xda3a8 ldr r3, [r3, #0x8] */
/* @0xda3ac blx r3 */
/* @0xda3b0 mov r0, r7 */
/* @0xda3b4 mov r1, #0 */
/* @0xda3b8 mov r2, r10 */
/* @0xda3bc bl 0x1f96e8 <_Z25GV_PhysicsLinearVelocityYP9CInstanceiP6RValue> */
/* @0xda3c0 subs r3, r0, #0 */
/* @0xda3c4 bne 0xdaa6c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x137c> */
/* @0xda3c8 vldr d7, [sp, #8] */
/* @0xda3cc vcvt.f32.f64 s14, d7 */
/* @0xda3d0 ldr r12, [r9] */
/* @0xda3d4 mov r0, r9 */
/* @0xda3d8 str r3, [r9, #0x38] */
/* @0xda3dc mov r1, #8 */
/* @0xda3e0 mov r2, r6 */
/* @0xda3e4 vcvt.f64.f32 d6, s14 */
/* @0xda3e8 vmov r4, r5, d6 */
/* @0xda3ec vstr s12, [r9, #44] */
/* @0xda3f0 str r5, [r9, #0x30] */
/* @0xda3f4 ldr r3, [r12, #0x8] */
/* @0xda3f8 blx r3 */
/* @0xda3fc mov r0, r7 */
/* @0xda400 mov r1, #0 */
/* @0xda404 mov r2, r10 */
/* @0xda408 bl 0x1f9d58 <_Z16GV_PhysicsSpeedXP9CInstanceiP6RValue> */
/* @0xda40c subs r3, r0, #0 */
/* @0xda410 bne 0xdaa40 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1350> */
/* @0xda414 vldr d7, [sp, #8] */
/* @0xda418 vcvt.f32.f64 s14, d7 */
/* @0xda41c ldr r12, [r9] */
/* @0xda420 mov r0, r9 */
/* @0xda424 str r3, [r9, #0x38] */
/* @0xda428 mov r1, #8 */
/* @0xda42c mov r2, r6 */
/* @0xda430 vcvt.f64.f32 d6, s14 */
/* @0xda434 vmov r4, r5, d6 */
/* @0xda438 vstr s12, [r9, #44] */
/* @0xda43c str r5, [r9, #0x30] */
/* @0xda440 ldr r3, [r12, #0x8] */
/* @0xda444 blx r3 */
/* @0xda448 mov r0, r7 */
/* @0xda44c mov r1, #0 */
/* @0xda450 mov r2, r10 */
/* @0xda454 bl 0x1f9e3c <_Z16GV_PhysicsSpeedYP9CInstanceiP6RValue> */
/* @0xda458 subs r3, r0, #0 */
/* @0xda45c bne 0xdaa14 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1324> */
/* @0xda460 vldr d7, [sp, #8] */
/* @0xda464 vcvt.f32.f64 s14, d7 */
/* @0xda468 ldr r12, [r9] */
/* @0xda46c mov r0, r9 */
/* @0xda470 str r3, [r9, #0x38] */
/* @0xda474 mov r1, #8 */
/* @0xda478 mov r2, r6 */
/* @0xda47c vcvt.f64.f32 d6, s14 */
/* @0xda480 vmov r4, r5, d6 */
/* @0xda484 vstr s12, [r9, #44] */
/* @0xda488 str r5, [r9, #0x30] */
/* @0xda48c ldr r3, [r12, #0x8] */
/* @0xda490 blx r3 */
/* @0xda494 mov r0, r7 */
/* @0xda498 mov r1, #0 */
/* @0xda49c mov r2, r10 */
/* @0xda4a0 bl 0x1f95bc <_Z19GV_PhysicsPositionXP9CInstanceiP6RValue> */
/* @0xda4a4 subs r3, r0, #0 */
/* @0xda4a8 bne 0xda9e8 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x12f8> */
/* @0xda4ac vldr d7, [sp, #8] */
/* @0xda4b0 vcvt.f32.f64 s14, d7 */
/* @0xda4b4 ldr r12, [r9] */
/* @0xda4b8 mov r0, r9 */
/* @0xda4bc str r3, [r9, #0x38] */
/* @0xda4c0 mov r1, #8 */
/* @0xda4c4 mov r2, r6 */
/* @0xda4c8 vcvt.f64.f32 d6, s14 */
/* @0xda4cc vmov r4, r5, d6 */
/* @0xda4d0 vstr s12, [r9, #44] */
/* @0xda4d4 str r5, [r9, #0x30] */
/* @0xda4d8 ldr r3, [r12, #0x8] */
/* @0xda4dc blx r3 */
/* @0xda4e0 mov r0, r7 */
/* @0xda4e4 mov r1, #0 */
/* @0xda4e8 mov r2, r10 */
/* @0xda4ec bl 0x1f9620 <_Z19GV_PhysicsPositionYP9CInstanceiP6RValue> */
/* @0xda4f0 subs r3, r0, #0 */
/* @0xda4f4 bne 0xda990 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x12a0> */
/* @0xda4f8 vldr d7, [sp, #8] */
/* @0xda4fc vcvt.f32.f64 s14, d7 */
/* @0xda500 ldr r12, [r9] */
/* @0xda504 mov r0, r9 */
/* @0xda508 str r3, [r9, #0x38] */
/* @0xda50c mov r1, #8 */
/* @0xda510 mov r2, r6 */
/* @0xda514 vcvt.f64.f32 d6, s14 */
/* @0xda518 vmov r4, r5, d6 */
/* @0xda51c vstr s12, [r9, #44] */
/* @0xda520 str r5, [r9, #0x30] */
/* @0xda524 ldr r3, [r12, #0x8] */
/* @0xda528 blx r3 */
/* @0xda52c ldr r3, [r8] */
/* @0xda530 vldr s15, [pc, #276] */
/* @0xda534 vldr s14, [r3, #72] */
/* @0xda538 vmul.f32 s15, s14, s15 */
/* @0xda53c vldr s14, [pc, #268] */
/* @0xda540 ldr r3, [r9] */
/* @0xda544 mov r11, #0 */
/* @0xda548 mov r1, #8 */
/* @0xda54c mov r2, r6 */
/* @0xda550 mov r0, r9 */
/* @0xda554 str r11, [r9, #0x38] */
/* @0xda558 vdiv.f32 s15, s15, s14 */
/* @0xda55c vcvt.f64.f32 d6, s15 */
/* @0xda560 vmov r4, r5, d6 */
/* @0xda564 vstr s12, [r9, #44] */
/* @0xda568 str r5, [r9, #0x30] */
/* @0xda56c ldr r3, [r3, #0x8] */
/* @0xda570 blx r3 */
/* @0xda574 ldr r12, [r8] */
/* @0xda578 ldr r3, [r9] */
/* @0xda57c mov r1, #5 */
/* @0xda580 mov r2, r6 */
/* @0xda584 mov r0, r9 */
/* @0xda588 ldrh r4, [r12, #4] */
/* @0xda58c str r11, [r9, #0x38] */
/* @0xda590 ubfx r4, r4, #0x3, #0x1 */
/* @0xda594 vmov s15, r4 */
/* @0xda598 vcvt.f64.u32 d7, s15 */
/* @0xda59c vmov r4, r5, d7 */
/* @0xda5a0 vstr s14, [r9, #44] */
/* @0xda5a4 str r5, [r9, #0x30] */
/* @0xda5a8 ldr r3, [r3, #0x8] */
/* @0xda5ac blx r3 */
/* @0xda5b0 mov r0, r7 */
/* @0xda5b4 mov r1, r11 */
/* @0xda5b8 mov r2, r10 */
/* @0xda5bc bl 0x1f97cc <_Z15GV_PhysicsCOM_XP9CInstanceiP6RValue> */
/* @0xda5c0 subs r3, r0, #0 */
/* @0xda5c4 bne 0xda968 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1278> */
/* @0xda5c8 vldr d7, [sp, #8] */
/* @0xda5cc vcvt.f32.f64 s14, d7 */
/* @0xda5d0 ldr r12, [r9] */
/* @0xda5d4 mov r0, r9 */
/* @0xda5d8 str r3, [r9, #0x38] */
/* @0xda5dc mov r1, #8 */
/* @0xda5e0 mov r2, r6 */
/* @0xda5e4 vcvt.f64.f32 d6, s14 */
/* @0xda5e8 vmov r4, r5, d6 */
/* @0xda5ec vstr s12, [r9, #44] */
/* @0xda5f0 str r5, [r9, #0x30] */
/* @0xda5f4 ldr r3, [r12, #0x8] */
/* @0xda5f8 blx r3 */
/* @0xda5fc mov r2, r10 */
/* @0xda600 mov r0, r7 */
/* @0xda604 mov r1, #0 */
/* @0xda608 bl 0x1f9830 <_Z15GV_PhysicsCOM_YP9CInstanceiP6RValue> */
/* @0xda60c subs r3, r0, #0 */
/* @0xda610 bne 0xda9bc <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x12cc> */
/* @0xda614 vldr d7, [sp, #8] */
/* @0xda618 vcvt.f32.f64 s14, d7 */
/* @0xda61c ldr r12, [r9] */
/* @0xda620 mov r0, r9 */
/* @0xda624 str r3, [r9, #0x38] */
/* @0xda628 mov r1, #8 */
/* @0xda62c mov r2, r6 */
/* @0xda630 vcvt.f64.f32 d6, s14 */
/* @0xda634 vmov r4, r5, d6 */
/* @0xda638 vstr s12, [r9, #44] */
/* @0xda63c str r5, [r9, #0x30] */
/* @0xda640 ldr r3, [r12, #0x8] */
/* @0xda644 blx r3 */
/* @0xda648 b 0xda65c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xf6c> */
/* @0xda64c teqmi r4, #0 */
/* @0xda650 ldrdmi r0, r1, [r9], #-251 */
/* @0xda654 eorseq r3, r1, r8, ror r0 */
/* @0xda658 eorseq r3, r1, r4, lsl #8 */
/* @0xda65c ldr r12, [r8] */
/* @0xda660 mov r10, #0 */
/* @0xda664 ldr r3, [r9] */
/* @0xda668 mov r1, #5 */
/* @0xda66c mov r2, r6 */
/* @0xda670 mov r0, r9 */
/* @0xda674 ldr r4, [r12] */
/* @0xda678 str r10, [r9, #0x38] */
/* @0xda67c subs r12, r4, #2 */
/* @0xda680 rsbs r4, r12, #0 */
/* @0xda684 adcs r4, r4, r12 */
/* @0xda688 vmov s15, r4 */
/* @0xda68c vcvt.f64.u32 d7, s15 */
/* @0xda690 vmov r4, r5, d7 */
/* @0xda694 vstr s14, [r9, #44] */
/* @0xda698 str r5, [r9, #0x30] */
/* @0xda69c ldr r3, [r3, #0x8] */
/* @0xda6a0 blx r3 */
/* @0xda6a4 ldr r12, [r8] */
/* @0xda6a8 ldr r3, [r9] */
/* @0xda6ac mov r1, #5 */
/* @0xda6b0 mov r2, r6 */
/* @0xda6b4 mov r0, r9 */
/* @0xda6b8 ldr r4, [r12] */
/* @0xda6bc str r10, [r9, #0x38] */
/* @0xda6c0 subs lr, r4, #1 */
/* @0xda6c4 rsbs r4, lr, #0 */
/* @0xda6c8 adcs r4, r4, lr */
/* @0xda6cc vmov s13, r4 */
/* @0xda6d0 vcvt.f64.u32 d6, s13 */
/* @0xda6d4 vmov r4, r5, d6 */
/* @0xda6d8 vstr s12, [r9, #44] */
/* @0xda6dc str r5, [r9, #0x30] */
/* @0xda6e0 ldr r3, [r3, #0x8] */
/* @0xda6e4 blx r3 */
/* @0xda6e8 ldr r3, [r8] */
/* @0xda6ec vldr s14, [r3, #48] */
/* @0xda6f0 vmul.f32 s14, s14, s14 */
/* @0xda6f4 vldr s13, [r3, #44] */
/* @0xda6f8 vldr s12, [r3, #132] */
/* @0xda6fc vldr s15, [r3, #140] */
/* @0xda700 ldr r3, [r9] */
/* @0xda704 mov r1, #8 */
/* @0xda708 mov r2, r6 */
/* @0xda70c str r10, [r9, #0x38] */
/* @0xda710 mov r0, r9 */
/* @0xda714 vmla.f32 s14, s13, s13 */
/* @0xda718 vmla.f32 s15, s14, s12 */
/* @0xda71c vcvt.f64.f32 d6, s15 */
/* @0xda720 vmov r4, r5, d6 */
/* @0xda724 vstr s12, [r9, #44] */
/* @0xda728 str r5, [r9, #0x30] */
/* @0xda72c ldr r3, [r3, #0x8] */
/* @0xda730 blx r3 */
/* @0xda734 ldr r3, [r8] */
/* @0xda738 vldr s15, [r3, #132] */
/* @0xda73c vcvt.f64.f32 d6, s15 */
/* @0xda740 ldr r3, [r9] */
/* @0xda744 mov r1, #8 */
/* @0xda748 mov r2, r6 */
/* @0xda74c mov r0, r9 */
/* @0xda750 str r10, [r9, #0x38] */
/* @0xda754 vmov r4, r5, d6 */
/* @0xda758 vstr s12, [r9, #44] */
/* @0xda75c str r5, [r9, #0x30] */
/* @0xda760 ldr r3, [r3, #0x8] */
/* @0xda764 blx r3 */
/* @0xda768 ldr r12, [r8] */
/* @0xda76c ldr r3, [r9] */
/* @0xda770 mov r0, r9 */
/* @0xda774 mov r1, #5 */
/* @0xda778 mov r2, r6 */
/* @0xda77c ldrh r4, [r12, #4] */
/* @0xda780 str r10, [r9, #0x38] */
/* @0xda784 eor r4, r4, #2 */
/* @0xda788 ubfx r4, r4, #0x1, #0x1 */
/* @0xda78c vmov s15, r4 */
/* @0xda790 vcvt.f64.u32 d7, s15 */
/* @0xda794 vmov r4, r5, d7 */
/* @0xda798 vstr s14, [r9, #44] */
/* @0xda79c str r5, [r9, #0x30] */
/* @0xda7a0 ldr r3, [r3, #0x8] */
/* @0xda7a4 blx r3 */
/* @0xda7a8 ldr r4, [r7, #0x14c] */
/* @0xda7ac mov r8, #0 */
/* @0xda7b0 ldr r3, [r9] */
/* @0xda7b4 mov r1, #5 */
/* @0xda7b8 mov r2, r6 */
/* @0xda7bc mov r0, r9 */
/* @0xda7c0 vmov s13, r4 */
/* @0xda7c4 str r8, [r9, #0x38] */
/* @0xda7c8 vcvt.f64.u32 d6, s13 */
/* @0xda7cc vmov r4, r5, d6 */
/* @0xda7d0 vstr s12, [r9, #44] */
/* @0xda7d4 str r5, [r9, #0x30] */
/* @0xda7d8 ldr r3, [r3, #0x8] */
/* @0xda7dc blx r3 */
/* @0xda7e0 ldrb r4, [r7, #0x15c] */
/* @0xda7e4 ldr r3, [r9] */
/* @0xda7e8 mov r1, #5 */
/* @0xda7ec mov r2, r6 */
/* @0xda7f0 mov r0, r9 */
/* @0xda7f4 vmov s15, r4 */
/* @0xda7f8 str r8, [r9, #0x38] */
/* @0xda7fc vcvt.f64.u32 d7, s15 */
/* @0xda800 vmov r4, r5, d7 */
/* @0xda804 vstr s14, [r9, #44] */
/* @0xda808 str r5, [r9, #0x30] */
/* @0xda80c ldr r3, [r3, #0x8] */
/* @0xda810 blx r3 */
/* @0xda814 vldr s15, [r7, #344] */
/* @0xda818 vcvt.f64.f32 d6, s15 */
/* @0xda81c ldr r3, [r9] */
/* @0xda820 mov r1, #8 */
/* @0xda824 mov r2, r6 */
/* @0xda828 str r8, [r9, #0x38] */
/* @0xda82c mov r0, r9 */
/* @0xda830 vmov r4, r5, d6 */
/* @0xda834 vstr s12, [r9, #44] */
/* @0xda838 str r5, [r9, #0x30] */
/* @0xda83c ldr r3, [r3, #0x8] */
/* @0xda840 blx r3 */
/* @0xda844 vldr s15, [r7, #340] */
/* @0xda848 vcvt.f64.f32 d6, s15 */
/* @0xda84c ldr r3, [r9] */
/* @0xda850 mov r1, #8 */
/* @0xda854 mov r2, r6 */
/* @0xda858 str r8, [r9, #0x38] */
/* @0xda85c mov r0, r9 */
/* @0xda860 vmov r4, r5, d6 */
/* @0xda864 vstr s12, [r9, #44] */
/* @0xda868 str r5, [r9, #0x30] */
/* @0xda86c ldr r3, [r3, #0x8] */
/* @0xda870 blx r3 */
/* @0xda874 ldrb r4, [r7, #0x15d] */
/* @0xda878 ldr r3, [r9] */
/* @0xda87c mov r0, r9 */
/* @0xda880 str r8, [r9, #0x38] */
/* @0xda884 mov r1, #5 */
/* @0xda888 vmov s15, r4 */
/* @0xda88c mov r2, r6 */
/* @0xda890 vcvt.f64.u32 d7, s15 */
/* @0xda894 vmov r4, r5, d7 */
/* @0xda898 vstr s14, [r9, #44] */
/* @0xda89c str r5, [r9, #0x30] */
/* @0xda8a0 ldr r3, [r3, #0x8] */
/* @0xda8a4 blx r3 */
/* @0xda8a8 ldr r3, [pc, #-0x25c] */
/* @0xda8ac ldr r3, [pc, r3] */
/* @0xda8b0 ldrb r3, [r3] */
/* @0xda8b4 cmp r3, r8 */
/* @0xda8b8 beq 0xda900 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x1210> */
/* @0xda8bc mov r1, r8 */
/* @0xda8c0 add r2, sp, #8 */
/* @0xda8c4 mov r0, r7 */
/* @0xda8c8 bl 0x1fadd4 <_Z8GV_LayerP9CInstanceiP6RValue> */
/* @0xda8cc vldr d7, [sp, #8] */
/* @0xda8d0 vcvt.f32.f64 s14, d7 */
/* @0xda8d4 ldr r3, [r9] */
/* @0xda8d8 mov r2, r6 */
/* @0xda8dc str r8, [r9, #0x38] */
/* @0xda8e0 mov r0, r9 */
/* @0xda8e4 mov r1, #8 */
/* @0xda8e8 vcvt.f64.f32 d6, s14 */
/* @0xda8ec vmov r4, r5, d6 */
/* @0xda8f0 vstr s12, [r9, #44] */
/* @0xda8f4 str r5, [r9, #0x30] */
/* @0xda8f8 ldr r3, [r3, #0x8] */
/* @0xda8fc blx r3 */
/* @0xda900 ldr r12, [pc, #-0x2b0] */
/* @0xda904 mov r0, r9 */
/* @0xda908 mov r1, r7 */
/* @0xda90c mov r2, #1 */
/* @0xda910 ldr r12, [pc, r12] */
/* @0xda914 movw r3, #0x86a0 */
/* @0xda918 movt r3, #0x1 */
/* @0xda91c ldr r12, [r12] */
/* @0xda920 str r12, [sp] */
/* @0xda924 bl 0xd9548 <_ZN2VM20GetInstanceVariablesEP15Buffer_StandardP12YYObjectBasebii> */
/* @0xda928 add sp, sp, #28 */
/* @0xda92c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xda930 vldr d7, [sp, #8] */
/* @0xda934 vcvt.f32.f64 s14, d7 */
/* @0xda938 ldr r12, [r9] */
/* @0xda93c mov r0, r9 */
/* @0xda940 str r3, [r9, #0x38] */
/* @0xda944 mov r1, #8 */
/* @0xda948 mov r2, r6 */
/* @0xda94c vcvt.f64.f32 d6, s14 */
/* @0xda950 vmov r4, r5, d6 */
/* @0xda954 vstr s12, [r9, #44] */
/* @0xda958 str r5, [r9, #0x30] */
/* @0xda95c ldr r3, [r12, #0x8] */
/* @0xda960 blx r3 */
/* @0xda964 b 0xda3b0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xcc0> */
/* @0xda968 ldr r3, [r9] */
/* @0xda96c mov r0, r9 */
/* @0xda970 str r11, [r9, #0x2c] */
/* @0xda974 mov r1, #8 */
/* @0xda978 str r11, [r9, #0x30] */
/* @0xda97c mov r2, r6 */
/* @0xda980 str r11, [r9, #0x38] */
/* @0xda984 ldr r3, [r3, #0x8] */
/* @0xda988 blx r3 */
/* @0xda98c b 0xda5fc <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xf0c> */
/* @0xda990 ldr r12, [r9] */
/* @0xda994 mov r3, #0 */
/* @0xda998 mov r0, r9 */
/* @0xda99c str r3, [r9, #0x2c] */
/* @0xda9a0 str r3, [r9, #0x30] */
/* @0xda9a4 mov r1, #8 */
/* @0xda9a8 str r3, [r9, #0x38] */
/* @0xda9ac mov r2, r6 */
/* @0xda9b0 ldr r3, [r12, #0x8] */
/* @0xda9b4 blx r3 */
/* @0xda9b8 b 0xda52c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xe3c> */
/* @0xda9bc ldr r12, [r9] */
/* @0xda9c0 mov r3, #0 */
/* @0xda9c4 mov r0, r9 */
/* @0xda9c8 str r3, [r9, #0x2c] */
/* @0xda9cc str r3, [r9, #0x30] */
/* @0xda9d0 mov r1, #8 */
/* @0xda9d4 str r3, [r9, #0x38] */
/* @0xda9d8 mov r2, r6 */
/* @0xda9dc ldr r3, [r12, #0x8] */
/* @0xda9e0 blx r3 */
/* @0xda9e4 b 0xda65c <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xf6c> */
/* @0xda9e8 ldr r12, [r9] */
/* @0xda9ec mov r3, #0 */
/* @0xda9f0 mov r0, r9 */
/* @0xda9f4 str r3, [r9, #0x2c] */
/* @0xda9f8 str r3, [r9, #0x30] */
/* @0xda9fc mov r1, #8 */
/* @0xdaa00 str r3, [r9, #0x38] */
/* @0xdaa04 mov r2, r6 */
/* @0xdaa08 ldr r3, [r12, #0x8] */
/* @0xdaa0c blx r3 */
/* @0xdaa10 b 0xda4e0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xdf0> */
/* @0xdaa14 ldr r12, [r9] */
/* @0xdaa18 mov r3, #0 */
/* @0xdaa1c mov r0, r9 */
/* @0xdaa20 str r3, [r9, #0x2c] */
/* @0xdaa24 str r3, [r9, #0x30] */
/* @0xdaa28 mov r1, #8 */
/* @0xdaa2c str r3, [r9, #0x38] */
/* @0xdaa30 mov r2, r6 */
/* @0xdaa34 ldr r3, [r12, #0x8] */
/* @0xdaa38 blx r3 */
/* @0xdaa3c b 0xda494 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xda4> */
/* @0xdaa40 ldr r12, [r9] */
/* @0xdaa44 mov r3, #0 */
/* @0xdaa48 mov r0, r9 */
/* @0xdaa4c str r3, [r9, #0x2c] */
/* @0xdaa50 str r3, [r9, #0x30] */
/* @0xdaa54 mov r1, #8 */
/* @0xdaa58 str r3, [r9, #0x38] */
/* @0xdaa5c mov r2, r6 */
/* @0xdaa60 ldr r3, [r12, #0x8] */
/* @0xdaa64 blx r3 */
/* @0xdaa68 b 0xda448 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xd58> */
/* @0xdaa6c ldr r12, [r9] */
/* @0xdaa70 mov r3, #0 */
/* @0xdaa74 mov r0, r9 */
/* @0xdaa78 str r3, [r9, #0x2c] */
/* @0xdaa7c str r3, [r9, #0x30] */
/* @0xdaa80 mov r1, #8 */
/* @0xdaa84 str r3, [r9, #0x38] */
/* @0xdaa88 mov r2, r6 */
/* @0xdaa8c ldr r3, [r12, #0x8] */
/* @0xdaa90 blx r3 */
/* @0xdaa94 b 0xda3fc <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xd0c> */
/* @0xdaa98 mov r0, r7 */
/* @0xdaa9c mov r1, #1 */
/* @0xdaaa0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0xdaaa4 b 0xda0d0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x9e0> */
/* @0xdaaa8 ldr r3, [r9] */
/* @0xdaaac mov r2, r6 */
/* @0xdaab0 str r8, [r9, #0x2c] */
/* @0xdaab4 mov r0, r9 */
/* @0xdaab8 str r8, [r9, #0x30] */
/* @0xdaabc mov r1, #5 */
/* @0xdaac0 str r8, [r9, #0x38] */
/* @0xdaac4 ldr r3, [r3, #0x8] */
/* @0xdaac8 blx r3 */
/* @0xdaacc ldr r3, [r9] */
/* @0xdaad0 str r8, [r9, #0x2c] */
/* @0xdaad4 mov r2, r6 */
/* @0xdaad8 str r8, [r9, #0x30] */
/* @0xdaadc mov r0, r9 */
/* @0xdaae0 mov r1, #5 */
/* @0xdaae4 str r8, [r9, #0x38] */
/* @0xdaae8 ldr r3, [r3, #0x8] */
/* @0xdaaec blx r3 */
/* @0xdaaf0 ldr r3, [r9] */
/* @0xdaaf4 str r8, [r9, #0x2c] */
/* @0xdaaf8 mov r2, r6 */
/* @0xdaafc str r8, [r9, #0x30] */
/* @0xdab00 mov r0, r9 */
/* @0xdab04 mov r1, #8 */
/* @0xdab08 str r8, [r9, #0x38] */
/* @0xdab0c ldr r3, [r3, #0x8] */
/* @0xdab10 blx r3 */
/* @0xdab14 ldr r3, [r9] */
/* @0xdab18 str r8, [r9, #0x2c] */
/* @0xdab1c mov r2, r6 */
/* @0xdab20 str r8, [r9, #0x30] */
/* @0xdab24 mov r0, r9 */
/* @0xdab28 mov r1, #8 */
/* @0xdab2c str r8, [r9, #0x38] */
/* @0xdab30 ldr r3, [r3, #0x8] */
/* @0xdab34 blx r3 */
/* @0xdab38 ldr r3, [r9] */
/* @0xdab3c str r8, [r9, #0x2c] */
/* @0xdab40 mov r2, r6 */
/* @0xdab44 str r8, [r9, #0x30] */
/* @0xdab48 mov r0, r9 */
/* @0xdab4c mov r1, #8 */
/* @0xdab50 str r8, [r9, #0x38] */
/* @0xdab54 ldr r3, [r3, #0x8] */
/* @0xdab58 blx r3 */
/* @0xdab5c ldr r3, [r9] */
/* @0xdab60 str r8, [r9, #0x2c] */
/* @0xdab64 mov r2, r6 */
/* @0xdab68 str r8, [r9, #0x30] */
/* @0xdab6c mov r0, r9 */
/* @0xdab70 mov r1, #8 */
/* @0xdab74 str r8, [r9, #0x38] */
/* @0xdab78 ldr r3, [r3, #0x8] */
/* @0xdab7c blx r3 */
/* @0xdab80 ldr r3, [r9] */
/* @0xdab84 str r8, [r9, #0x2c] */
/* @0xdab88 mov r2, r6 */
/* @0xdab8c str r8, [r9, #0x30] */
/* @0xdab90 mov r0, r9 */
/* @0xdab94 mov r1, #8 */
/* @0xdab98 str r8, [r9, #0x38] */
/* @0xdab9c ldr r3, [r3, #0x8] */
/* @0xdaba0 blx r3 */
/* @0xdaba4 ldr r3, [r9] */
/* @0xdaba8 str r8, [r9, #0x2c] */
/* @0xdabac mov r2, r6 */
/* @0xdabb0 str r8, [r9, #0x30] */
/* @0xdabb4 mov r0, r9 */
/* @0xdabb8 mov r1, #8 */
/* @0xdabbc str r8, [r9, #0x38] */
/* @0xdabc0 ldr r3, [r3, #0x8] */
/* @0xdabc4 blx r3 */
/* @0xdabc8 ldr r3, [r9] */
/* @0xdabcc str r8, [r9, #0x2c] */
/* @0xdabd0 mov r2, r6 */
/* @0xdabd4 str r8, [r9, #0x30] */
/* @0xdabd8 mov r0, r9 */
/* @0xdabdc mov r1, #8 */
/* @0xdabe0 str r8, [r9, #0x38] */
/* @0xdabe4 ldr r3, [r3, #0x8] */
/* @0xdabe8 blx r3 */
/* @0xdabec ldr r3, [r9] */
/* @0xdabf0 str r8, [r9, #0x2c] */
/* @0xdabf4 mov r2, r6 */
/* @0xdabf8 str r8, [r9, #0x30] */
/* @0xdabfc mov r0, r9 */
/* @0xdac00 mov r1, #8 */
/* @0xdac04 str r8, [r9, #0x38] */
/* @0xdac08 ldr r3, [r3, #0x8] */
/* @0xdac0c blx r3 */
/* @0xdac10 ldr r3, [r9] */
/* @0xdac14 str r8, [r9, #0x2c] */
/* @0xdac18 mov r2, r6 */
/* @0xdac1c str r8, [r9, #0x30] */
/* @0xdac20 mov r0, r9 */
/* @0xdac24 mov r1, #5 */
/* @0xdac28 str r8, [r9, #0x38] */
/* @0xdac2c ldr r3, [r3, #0x8] */
/* @0xdac30 blx r3 */
/* @0xdac34 ldr r3, [r9] */
/* @0xdac38 str r8, [r9, #0x2c] */
/* @0xdac3c mov r2, r6 */
/* @0xdac40 str r8, [r9, #0x30] */
/* @0xdac44 mov r0, r9 */
/* @0xdac48 mov r1, #8 */
/* @0xdac4c str r8, [r9, #0x38] */
/* @0xdac50 ldr r3, [r3, #0x8] */
/* @0xdac54 blx r3 */
/* @0xdac58 ldr r3, [r9] */
/* @0xdac5c str r8, [r9, #0x2c] */
/* @0xdac60 mov r2, r6 */
/* @0xdac64 str r8, [r9, #0x30] */
/* @0xdac68 mov r0, r9 */
/* @0xdac6c mov r1, #8 */
/* @0xdac70 str r8, [r9, #0x38] */
/* @0xdac74 ldr r3, [r3, #0x8] */
/* @0xdac78 blx r3 */
/* @0xdac7c ldr r3, [r9] */
/* @0xdac80 str r8, [r9, #0x2c] */
/* @0xdac84 mov r2, r6 */
/* @0xdac88 str r8, [r9, #0x30] */
/* @0xdac8c mov r0, r9 */
/* @0xdac90 mov r1, #5 */
/* @0xdac94 str r8, [r9, #0x38] */
/* @0xdac98 ldr r3, [r3, #0x8] */
/* @0xdac9c blx r3 */
/* @0xdaca0 ldr r3, [r9] */
/* @0xdaca4 str r8, [r9, #0x2c] */
/* @0xdaca8 mov r2, r6 */
/* @0xdacac str r8, [r9, #0x30] */
/* @0xdacb0 mov r0, r9 */
/* @0xdacb4 mov r1, #5 */
/* @0xdacb8 str r8, [r9, #0x38] */
/* @0xdacbc ldr r3, [r3, #0x8] */
/* @0xdacc0 blx r3 */
/* @0xdacc4 ldr r3, [r9] */
/* @0xdacc8 str r8, [r9, #0x2c] */
/* @0xdaccc mov r2, r6 */
/* @0xdacd0 str r8, [r9, #0x30] */
/* @0xdacd4 mov r0, r9 */
/* @0xdacd8 mov r1, #8 */
/* @0xdacdc str r8, [r9, #0x38] */
/* @0xdace0 ldr r3, [r3, #0x8] */
/* @0xdace4 blx r3 */
/* @0xdace8 ldr r3, [r9] */
/* @0xdacec str r8, [r9, #0x2c] */
/* @0xdacf0 mov r2, r6 */
/* @0xdacf4 str r8, [r9, #0x30] */
/* @0xdacf8 mov r0, r9 */
/* @0xdacfc mov r1, #8 */
/* @0xdad00 str r8, [r9, #0x38] */
/* @0xdad04 ldr r3, [r3, #0x8] */
/* @0xdad08 blx r3 */
/* @0xdad0c ldr r3, [r9] */
/* @0xdad10 str r8, [r9, #0x2c] */
/* @0xdad14 mov r0, r9 */
/* @0xdad18 str r8, [r9, #0x30] */
/* @0xdad1c mov r1, #8 */
/* @0xdad20 str r8, [r9, #0x38] */
/* @0xdad24 mov r2, r6 */
/* @0xdad28 ldr r3, [r3, #0x8] */
/* @0xdad2c blx r3 */
/* @0xdad30 b 0xda7a8 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0x10b8> */
/* @0xdad34 ldr r3, [r9] */
/* @0xdad38 mov r2, r6 */
/* @0xdad3c str r10, [r9, #0x2c] */
/* @0xdad40 mov r0, r9 */
/* @0xdad44 str r10, [r9, #0x30] */
/* @0xdad48 mov r1, #8 */
/* @0xdad4c str r10, [r9, #0x38] */
/* @0xdad50 ldr r3, [r3, #0x8] */
/* @0xdad54 blx r3 */
/* @0xdad58 ldr r3, [r9] */
/* @0xdad5c str r10, [r9, #0x2c] */
/* @0xdad60 mov r2, r6 */
/* @0xdad64 str r10, [r9, #0x30] */
/* @0xdad68 mov r0, r9 */
/* @0xdad6c mov r1, #8 */
/* @0xdad70 str r10, [r9, #0x38] */
/* @0xdad74 ldr r3, [r3, #0x8] */
/* @0xdad78 blx r3 */
/* @0xdad7c ldr r3, [r9] */
/* @0xdad80 str r10, [r9, #0x2c] */
/* @0xdad84 mov r2, r6 */
/* @0xdad88 str r10, [r9, #0x30] */
/* @0xdad8c mov r0, r9 */
/* @0xdad90 mov r1, #8 */
/* @0xdad94 str r10, [r9, #0x38] */
/* @0xdad98 ldr r3, [r3, #0x8] */
/* @0xdad9c blx r3 */
/* @0xdada0 ldr r3, [r9] */
/* @0xdada4 str r10, [r9, #0x2c] */
/* @0xdada8 mov r0, r9 */
/* @0xdadac str r10, [r9, #0x30] */
/* @0xdadb0 mov r1, #8 */
/* @0xdadb4 str r10, [r9, #0x38] */
/* @0xdadb8 mov r2, r6 */
/* @0xdadbc ldr r3, [r3, #0x8] */
/* @0xdadc0 blx r3 */
/* @0xdadc4 b 0xda2a4 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance+0xbb4> */

/* ── FUNC 0xdadc8 · VM::GetRuntimeState(Buffer_Standard*, int) · size=696 · insn=174 */
/* @0xdadc8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xdadcc mov r8, r1 */
/* @0xdadd0 ldr r7, [pc, #0x2a0] */
/* @0xdadd4 sub sp, sp, #20 */
/* @0xdadd8 mov r6, r0 */
/* @0xdaddc ldr r7, [pc, r7] */
/* @0xdade0 ldr r3, [r7] */
/* @0xdade4 cmp r3, #0 */
/* @0xdade8 beq 0xdb04c <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x284> */
/* @0xdadec ldr r3, [r3, #0x24] */
/* @0xdadf0 add r9, r0, #44 */
/* @0xdadf4 ldr r12, [r0] */
/* @0xdadf8 mov lr, #10 */
/* @0xdadfc mov r2, r9 */
/* @0xdae00 mov r1, #12 */
/* @0xdae04 asr r5, r3, #31 */
/* @0xdae08 str r3, [r0, #0x2c] */
/* @0xdae0c str r5, [r0, #0x30] */
/* @0xdae10 str lr, [r0, #0x38] */
/* @0xdae14 ldr r3, [r12, #0x8] */
/* @0xdae18 blx r3 */
/* @0xdae1c ldr r1, [r7] */
/* @0xdae20 ldr r3, [r6] */
/* @0xdae24 mov r12, #0 */
/* @0xdae28 mov r2, r9 */
/* @0xdae2c mov r0, r6 */
/* @0xdae30 ldr r4, [r1, #0x44] */
/* @0xdae34 mov r1, #5 */
/* @0xdae38 str r12, [r6, #0x38] */
/* @0xdae3c vmov s15, r4 */
/* @0xdae40 vcvt.f64.u32 d7, s15 */
/* @0xdae44 vmov r4, r5, d7 */
/* @0xdae48 vstr s14, [r6, #44] */
/* @0xdae4c str r5, [r6, #0x30] */
/* @0xdae50 ldr r3, [r3, #0x8] */
/* @0xdae54 blx r3 */
/* @0xdae58 ldr r3, [pc, #0x21c] */
/* @0xdae5c ldr r3, [pc, r3] */
/* @0xdae60 ldrb r3, [r3] */
/* @0xdae64 cmp r3, #0 */
/* @0xdae68 ldr r3, [r7] */
/* @0xdae6c bne 0xdafcc <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x204> */
/* @0xdae70 ldr r3, [r3, #0x14] */
/* @0xdae74 mov r0, r6 */
/* @0xdae78 ldr r1, [r6] */
/* @0xdae7c cmp r3, #0 */
/* @0xdae80 ldrne r2, [r3, #0x78] */
/* @0xdae84 moveq r2, #0 */
/* @0xdae88 moveq r3, #0 */
/* @0xdae8c vmovne s15, r2 */
/* @0xdae90 vcvtne.f64.u32 d7, s15 */
/* @0xdae94 vmovne r2, r3, d7 */
/* @0xdae98 str r2, [r6, #0x2c] */
/* @0xdae9c mov r2, #0 */
/* @0xdaea0 str r3, [r6, #0x30] */
/* @0xdaea4 ldr r3, [r1, #0x8] */
/* @0xdaea8 mov r1, #5 */
/* @0xdaeac str r2, [r6, #0x38] */
/* @0xdaeb0 mov r2, r9 */
/* @0xdaeb4 blx r3 */
/* @0xdaeb8 ldr r3, [r7] */
/* @0xdaebc mov r2, #0 */
/* @0xdaec0 mov r0, r6 */
/* @0xdaec4 mov r1, #5 */
/* @0xdaec8 ldr r3, [r3, #0x18] */
/* @0xdaecc cmp r3, #0 */
/* @0xdaed0 ldrne r4, [r3, #0x78] */
/* @0xdaed4 moveq r4, #0 */
/* @0xdaed8 ldr r3, [r6] */
/* @0xdaedc moveq r5, #0 */
/* @0xdaee0 vmovne s15, r4 */
/* @0xdaee4 vcvtne.f64.u32 d7, s15 */
/* @0xdaee8 vmovne r4, r5, d7 */
/* @0xdaeec str r4, [r6, #0x2c] */
/* @0xdaef0 str r5, [r6, #0x30] */
/* @0xdaef4 ldr r3, [r3, #0x8] */
/* @0xdaef8 str r2, [r6, #0x38] */
/* @0xdaefc mov r2, r9 */
/* @0xdaf00 blx r3 */
/* @0xdaf04 ldr r1, [r7] */
/* @0xdaf08 mov r3, #3392 */
/* @0xdaf0c mov r0, r6 */
/* @0xdaf10 movt r3, #0x3 */
/* @0xdaf14 ubfx r2, r8, #0x4, #0x1 */
/* @0xdaf18 ldr r1, [r1, #0x10] */
/* @0xdaf1c bl 0xd8f48 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi> */
/* @0xdaf20 tst r8, #32 */
/* @0xdaf24 beq 0xdaf44 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x17c> */
/* @0xdaf28 ldr r3, [r7] */
/* @0xdaf2c ldr r3, [r3, #0x14] */
/* @0xdaf30 cmp r3, #0 */
/* @0xdaf34 beq 0xdaf44 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x17c> */
/* @0xdaf38 ldr r3, [r3, #0x48] */
/* @0xdaf3c cmp r3, #1 */
/* @0xdaf40 beq 0xdb008 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x240> */
/* @0xdaf44 ldr r12, [r6] */
/* @0xdaf48 mov r3, #0 */
/* @0xdaf4c mov r2, r9 */
/* @0xdaf50 str r3, [r6, #0x2c] */
/* @0xdaf54 str r3, [r6, #0x30] */
/* @0xdaf58 mov r0, r6 */
/* @0xdaf5c str r3, [r6, #0x38] */
/* @0xdaf60 mov r1, #5 */
/* @0xdaf64 ldr r3, [r12, #0x8] */
/* @0xdaf68 blx r3 */
/* @0xdaf6c ldr r1, [r7] */
/* @0xdaf70 mov r0, r6 */
/* @0xdaf74 ubfx r2, r8, #0x6, #0x1 */
/* @0xdaf78 bl 0xd90a8 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb> */
/* @0xdaf7c ubfx r1, r8, #0x3, #0x1 */
/* @0xdaf80 mov r0, r6 */
/* @0xdaf84 bl 0xd8c20 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb> */
/* @0xdaf88 mov r0, r6 */
/* @0xdaf8c bl 0x29c080 <_Z17Debug_WriteOutputP15Buffer_Standard> */
/* @0xdaf90 mov r0, r6 */
/* @0xdaf94 bl 0xd890c <_ZN2VM18GetStructureCountsEP15Buffer_Standard> */
/* @0xdaf98 mov r0, r6 */
/* @0xdaf9c and r1, r8, #1 */
/* @0xdafa0 bl 0xd87ac <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb> */
/* @0xdafa4 mov r0, r6 */
/* @0xdafa8 ubfx r1, r8, #0x1, #0x1 */
/* @0xdafac bl 0xd8664 <_ZN2VM17WriteRenderStatesEP15Buffer_Standardb> */
/* @0xdafb0 mov r0, r6 */
/* @0xdafb4 ubfx r1, r8, #0x2, #0x1 */
/* @0xdafb8 bl 0x29c15c <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb> */
/* @0xdafbc mov r0, r6 */
/* @0xdafc0 bl 0x29c108 <_Z23Debug_WriteErrorMessageP15Buffer_Standard> */
/* @0xdafc4 add sp, sp, #20 */
/* @0xdafc8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xdafcc ldr r3, [r3, #0x14] */
/* @0xdafd0 add r4, sp, #16 */
/* @0xdafd4 mov r1, r6 */
/* @0xdafd8 mov r0, sp */
/* @0xdafdc mov r2, #6 */
/* @0xdafe0 str r2, [sp, #0xc] */
/* @0xdafe4 str r3, [r4, #-0x10]! */
/* @0xdafe8 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdafec ldr r3, [r7] */
/* @0xdaff0 mov r0, sp */
/* @0xdaff4 mov r1, r6 */
/* @0xdaff8 ldr r3, [r3, #0x18] */
/* @0xdaffc str r3, [sp] */
/* @0xdb000 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb004 b 0xdaf04 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x13c> */
/* @0xdb008 ldr r12, [r6] */
/* @0xdb00c mov r1, #0 */
/* @0xdb010 mov r3, r1 */
/* @0xdb014 mov r2, r9 */
/* @0xdb018 str r3, [r6, #0x2c] */
/* @0xdb01c movt r1, #0x3ff0 */
/* @0xdb020 str r3, [r6, #0x38] */
/* @0xdb024 mov r0, r6 */
/* @0xdb028 str r1, [r6, #0x30] */
/* @0xdb02c mov r1, #5 */
/* @0xdb030 ldr r3, [r12, #0x8] */
/* @0xdb034 blx r3 */
/* @0xdb038 ldr r3, [r7] */
/* @0xdb03c mov r0, r6 */
/* @0xdb040 ldr r1, [r3, #0x14] */
/* @0xdb044 bl 0xd96f0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance> */
/* @0xdb048 b 0xdaf6c <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x1a4> */
/* @0xdb04c mov r2, r0 */
/* @0xdb050 mvn r3, #0 */
/* @0xdb054 ldr lr, [r2], #44 */
/* @0xdb058 mov r12, #10 */
/* @0xdb05c str r3, [r0, #0x2c] */
/* @0xdb060 mov r1, #12 */
/* @0xdb064 str r3, [r0, #0x30] */
/* @0xdb068 ldr r3, [lr, #0x8] */
/* @0xdb06c str r12, [r0, #0x38] */
/* @0xdb070 blx r3 */
/* @0xdb074 b 0xdaf7c <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x1b4> */
/* @0xdb078 eorseq r2, r1, r12, asr #27 */
/* @0xdb07c eorseq r2, r1, r12, asr sp */

/* ── FUNC 0xdb080 · VM::WriteDSSizeCount(Buffer_Standard*, int, int&) · size=176 · insn=44 */
/* @0xdb080 vmov s15, r1 */
/* @0xdb084 ldr r3, [r0] */
/* @0xdb088 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xdb08c vcvt.f64.u32 d7, s15 */
/* @0xdb090 add r8, r0, #44 */
/* @0xdb094 mov r6, r0 */
/* @0xdb098 mov r10, r2 */
/* @0xdb09c mov r9, #0 */
/* @0xdb0a0 mov r7, r1 */
/* @0xdb0a4 str r9, [r0, #0x38] */
/* @0xdb0a8 mov r1, #5 */
/* @0xdb0ac mov r2, r8 */
/* @0xdb0b0 vmov r4, r5, d7 */
/* @0xdb0b4 vstr s14, [r6, #44] */
/* @0xdb0b8 str r5, [r6, #0x30] */
/* @0xdb0bc ldr r3, [r3, #0x8] */
/* @0xdb0c0 blx r3 */
/* @0xdb0c4 ldr r3, [r10] */
/* @0xdb0c8 cmp r3, r9 */
/* @0xdb0cc blt 0xdb118 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi+0x98> */
/* @0xdb0d0 rsb r7, r3, r7 */
/* @0xdb0d4 cmp r7, #50 */
/* @0xdb0d8 movge r7, #50 */
/* @0xdb0dc vmov s15, r7 */
/* @0xdb0e0 vcvt.f64.u32 d7, s15 */
/* @0xdb0e4 vmov r4, r5, d7 */
/* @0xdb0e8 ldr r3, [r6] */
/* @0xdb0ec mov r12, #0 */
/* @0xdb0f0 str r4, [r6, #0x2c] */
/* @0xdb0f4 mov r2, r8 */
/* @0xdb0f8 str r5, [r6, #0x30] */
/* @0xdb0fc mov r0, r6 */
/* @0xdb100 ldr r3, [r3, #0x8] */
/* @0xdb104 mov r1, #5 */
/* @0xdb108 str r12, [r6, #0x38] */
/* @0xdb10c blx r3 */
/* @0xdb110 mov r0, r7 */
/* @0xdb114 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xdb118 cmp r7, #50 */
/* @0xdb11c str r9, [r10] */
/* @0xdb120 movgt r7, r9 */
/* @0xdb124 movgt r4, #0 */
/* @0xdb128 movgt r5, #0 */
/* @0xdb12c b 0xdb0e8 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi+0x68> */

/* ── FUNC 0xdb130 · VM::GetDSList(Buffer_Standard*, int, int) · size=224 · insn=56 */
/* @0xdb130 push {r4, r5, r6, r7, r8, lr} */
/* @0xdb134 cmp r1, #0 */
/* @0xdb138 sub sp, sp, #8 */
/* @0xdb13c mov r8, r0 */
/* @0xdb140 str r2, [sp, #0x4] */
/* @0xdb144 blt 0xdb1c8 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x98> */
/* @0xdb148 ldr r3, [pc, #0xb8] */
/* @0xdb14c ldr r3, [pc, r3] */
/* @0xdb150 ldr r3, [r3] */
/* @0xdb154 cmp r1, r3 */
/* @0xdb158 bge 0xdb1c8 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x98> */
/* @0xdb15c ldr r3, [pc, #0xa8] */
/* @0xdb160 ldr r3, [pc, r3] */
/* @0xdb164 ldr r3, [r3, #0x4] */
/* @0xdb168 ldr r7, [r3, r1, lsl #2] */
/* @0xdb16c cmp r7, #0 */
/* @0xdb170 beq 0xdb1c8 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x98> */
/* @0xdb174 ldr r1, [r7, #0x4] */
/* @0xdb178 add r2, sp, #4 */
/* @0xdb17c bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi> */
/* @0xdb180 ldr r4, [sp, #0x4] */
/* @0xdb184 add r3, r0, r4 */
/* @0xdb188 mov r6, r0 */
/* @0xdb18c cmp r4, r3 */
/* @0xdb190 bge 0xdb1c0 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x90> */
/* @0xdb194 lsl r5, r4, #4 */
/* @0xdb198 ldr r0, [r7, #0xc] */
/* @0xdb19c mov r1, r8 */
/* @0xdb1a0 add r4, r4, #1 */
/* @0xdb1a4 add r0, r0, r5 */
/* @0xdb1a8 add r5, r5, #16 */
/* @0xdb1ac bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb1b0 ldr r3, [sp, #0x4] */
/* @0xdb1b4 add r3, r6, r3 */
/* @0xdb1b8 cmp r3, r4 */
/* @0xdb1bc bgt 0xdb198 <_ZN2VM9GetDSListEP15Buffer_Standardii+0x68> */
/* @0xdb1c0 add sp, sp, #8 */
/* @0xdb1c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xdb1c8 mov r2, r8 */
/* @0xdb1cc mov r1, #0 */
/* @0xdb1d0 ldr r0, [r2], #44 */
/* @0xdb1d4 movt r1, #0xffe0 */
/* @0xdb1d8 movw r3, #0xffff */
/* @0xdb1dc str r1, [r8, #0x2c] */
/* @0xdb1e0 movt r3, #0x41ef */
/* @0xdb1e4 mov r1, #0 */
/* @0xdb1e8 str r3, [r8, #0x30] */
/* @0xdb1ec ldr r3, [r0, #0x8] */
/* @0xdb1f0 mov r0, r8 */
/* @0xdb1f4 str r1, [r8, #0x38] */
/* @0xdb1f8 mov r1, #5 */
/* @0xdb1fc blx r3 */
/* @0xdb200 add sp, sp, #8 */
/* @0xdb204 pop {r4, r5, r6, r7, r8, pc} */
/* @0xdb208 eorseq r2, r1, r0, lsr r11 */
/* @0xdb20c eorseq r2, r1, r0, lsr #22 */

/* ── FUNC 0xdb210 · VM::GetDSStack(Buffer_Standard*, int, int) · size=204 · insn=51 */
/* @0xdb210 push {r4, r5, r6, r7, r8, lr} */
/* @0xdb214 sub sp, sp, #16 */
/* @0xdb218 mov r5, r0 */
/* @0xdb21c add r0, sp, #12 */
/* @0xdb220 mov r4, r1 */
/* @0xdb224 str r2, [sp, #0x4] */
/* @0xdb228 bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xdb22c cmp r4, #0 */
/* @0xdb230 blt 0xdb29c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x8c> */
/* @0xdb234 ldr r3, [sp, #0xc] */
/* @0xdb238 cmp r4, r3 */
/* @0xdb23c bge 0xdb29c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x8c> */
/* @0xdb240 ldr r7, [r0, r4, lsl #2] */
/* @0xdb244 cmp r7, #0 */
/* @0xdb248 beq 0xdb29c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x8c> */
/* @0xdb24c ldr r6, [r7, #0x4] */
/* @0xdb250 mov r0, r5 */
/* @0xdb254 add r2, sp, #4 */
/* @0xdb258 mov r1, r6 */
/* @0xdb25c bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi> */
/* @0xdb260 subs r8, r0, #0 */
/* @0xdb264 ble 0xdb294 <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x84> */
/* @0xdb268 mov r4, #1 */
/* @0xdb26c ldr r2, [sp, #0x4] */
/* @0xdb270 mov r1, r5 */
/* @0xdb274 ldr r0, [r7, #0xc] */
/* @0xdb278 rsb r2, r2, r6 */
/* @0xdb27c rsb r2, r4, r2 */
/* @0xdb280 add r4, r4, #1 */
/* @0xdb284 add r0, r0, r2, lsl #4 */
/* @0xdb288 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb28c cmp r8, r4 */
/* @0xdb290 bge 0xdb26c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x5c> */
/* @0xdb294 add sp, sp, #16 */
/* @0xdb298 pop {r4, r5, r6, r7, r8, pc} */
/* @0xdb29c mov r2, r5 */
/* @0xdb2a0 mov r1, #0 */
/* @0xdb2a4 ldr r0, [r2], #44 */
/* @0xdb2a8 movt r1, #0xffe0 */
/* @0xdb2ac movw r3, #0xffff */
/* @0xdb2b0 str r1, [r5, #0x2c] */
/* @0xdb2b4 movt r3, #0x41ef */
/* @0xdb2b8 mov r1, #0 */
/* @0xdb2bc str r3, [r5, #0x30] */
/* @0xdb2c0 ldr r3, [r0, #0x8] */
/* @0xdb2c4 mov r0, r5 */
/* @0xdb2c8 str r1, [r5, #0x38] */
/* @0xdb2cc mov r1, #5 */
/* @0xdb2d0 blx r3 */
/* @0xdb2d4 add sp, sp, #16 */
/* @0xdb2d8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0xdb2dc · VM::GetDSQueue(Buffer_Standard*, int, int) · size=212 · insn=53 */
/* @0xdb2dc push {r4, r5, r6, r7, lr} */
/* @0xdb2e0 sub sp, sp, #20 */
/* @0xdb2e4 mov r6, r0 */
/* @0xdb2e8 add r0, sp, #12 */
/* @0xdb2ec mov r4, r1 */
/* @0xdb2f0 str r2, [sp, #0x4] */
/* @0xdb2f4 bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xdb2f8 cmp r4, #0 */
/* @0xdb2fc blt 0xdb370 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x94> */
/* @0xdb300 ldr r3, [sp, #0xc] */
/* @0xdb304 cmp r4, r3 */
/* @0xdb308 bge 0xdb370 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x94> */
/* @0xdb30c ldr r5, [r0, r4, lsl #2] */
/* @0xdb310 cmp r5, #0 */
/* @0xdb314 beq 0xdb370 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x94> */
/* @0xdb318 ldr r1, [r5, #0x4] */
/* @0xdb31c mov r0, r6 */
/* @0xdb320 ldr r3, [r5, #0x8] */
/* @0xdb324 add r2, sp, #4 */
/* @0xdb328 rsb r1, r3, r1 */
/* @0xdb32c bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi> */
/* @0xdb330 subs r7, r0, #0 */
/* @0xdb334 ble 0xdb368 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x8c> */
/* @0xdb338 mov r4, #0 */
/* @0xdb33c ldr r3, [r5, #0x8] */
/* @0xdb340 mov r1, r6 */
/* @0xdb344 ldr r2, [sp, #0x4] */
/* @0xdb348 ldr r0, [r5, #0x10] */
/* @0xdb34c add r2, r3, r2 */
/* @0xdb350 add r2, r2, r4 */
/* @0xdb354 add r4, r4, #1 */
/* @0xdb358 add r0, r0, r2, lsl #4 */
/* @0xdb35c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb360 cmp r4, r7 */
/* @0xdb364 bne 0xdb33c <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x60> */
/* @0xdb368 add sp, sp, #20 */
/* @0xdb36c pop {r4, r5, r6, r7, pc} */
/* @0xdb370 mov r2, r6 */
/* @0xdb374 mov r1, #0 */
/* @0xdb378 ldr r0, [r2], #44 */
/* @0xdb37c movt r1, #0xffe0 */
/* @0xdb380 movw r3, #0xffff */
/* @0xdb384 str r1, [r6, #0x2c] */
/* @0xdb388 movt r3, #0x41ef */
/* @0xdb38c mov r1, #0 */
/* @0xdb390 str r3, [r6, #0x30] */
/* @0xdb394 ldr r3, [r0, #0x8] */
/* @0xdb398 mov r0, r6 */
/* @0xdb39c str r1, [r6, #0x38] */
/* @0xdb3a0 mov r1, #5 */
/* @0xdb3a4 blx r3 */
/* @0xdb3a8 add sp, sp, #20 */
/* @0xdb3ac pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0xdb3b0 · VM::GetDSPriority(Buffer_Standard*, int, int) · size=260 · insn=65 */
/* @0xdb3b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdb3b4 sub sp, sp, #20 */
/* @0xdb3b8 mov r4, r0 */
/* @0xdb3bc add r0, sp, #12 */
/* @0xdb3c0 mov r5, r1 */
/* @0xdb3c4 str r2, [sp, #0x4] */
/* @0xdb3c8 bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xdb3cc cmp r5, #0 */
/* @0xdb3d0 blt 0xdb474 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xc4> */
/* @0xdb3d4 ldr r3, [sp, #0xc] */
/* @0xdb3d8 cmp r5, r3 */
/* @0xdb3dc bge 0xdb474 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xc4> */
/* @0xdb3e0 ldr r8, [r0, r5, lsl #2] */
/* @0xdb3e4 cmp r8, #0 */
/* @0xdb3e8 beq 0xdb474 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xc4> */
/* @0xdb3ec mov r0, r4 */
/* @0xdb3f0 ldr r1, [r8, #0x4] */
/* @0xdb3f4 add r2, sp, #4 */
/* @0xdb3f8 bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi> */
/* @0xdb3fc subs r9, r0, #0 */
/* @0xdb400 ble 0xdb46c <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0xbc> */
/* @0xdb404 mov r5, #0 */
/* @0xdb408 add r11, r4, #44 */
/* @0xdb40c mov r10, r5 */
/* @0xdb410 ldr r6, [sp, #0x4] */
/* @0xdb414 mov r1, r4 */
/* @0xdb418 ldr r0, [r8, #0xc] */
/* @0xdb41c add r6, r5, r6 */
/* @0xdb420 add r5, r5, #1 */
/* @0xdb424 lsl r7, r6, #4 */
/* @0xdb428 add r0, r0, r7 */
/* @0xdb42c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb430 ldr r3, [r8, #0x14] */
/* @0xdb434 ldr r12, [r4] */
/* @0xdb438 mov r0, r4 */
/* @0xdb43c add r7, r3, r7 */
/* @0xdb440 mov r1, #9 */
/* @0xdb444 ldr lr, [r3, r6, lsl #4] */
/* @0xdb448 mov r2, r11 */
/* @0xdb44c ldr r3, [r7, #0x4] */
/* @0xdb450 str r10, [r4, #0x38] */
/* @0xdb454 str lr, [r4, #0x2c] */
/* @0xdb458 str r3, [r4, #0x30] */
/* @0xdb45c ldr r3, [r12, #0x8] */
/* @0xdb460 blx r3 */
/* @0xdb464 cmp r5, r9 */
/* @0xdb468 bne 0xdb410 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii+0x60> */
/* @0xdb46c add sp, sp, #20 */
/* @0xdb470 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdb474 mov r2, r4 */
/* @0xdb478 mov r1, #0 */
/* @0xdb47c ldr r0, [r2], #44 */
/* @0xdb480 movt r1, #0xffe0 */
/* @0xdb484 movw r3, #0xffff */
/* @0xdb488 str r1, [r4, #0x2c] */
/* @0xdb48c movt r3, #0x41ef */
/* @0xdb490 mov r1, #0 */
/* @0xdb494 str r3, [r4, #0x30] */
/* @0xdb498 ldr r3, [r0, #0x8] */
/* @0xdb49c mov r0, r4 */
/* @0xdb4a0 str r1, [r4, #0x38] */
/* @0xdb4a4 mov r1, #5 */
/* @0xdb4a8 blx r3 */
/* @0xdb4ac add sp, sp, #20 */
/* @0xdb4b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xdb4b4 · VM::GetDSMap(Buffer_Standard*, int, int) · size=600 · insn=150 */
/* @0xdb4b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdb4b8 sub sp, sp, #36 */
/* @0xdb4bc add r10, sp, #28 */
/* @0xdb4c0 mov r7, r0 */
/* @0xdb4c4 mov r4, r1 */
/* @0xdb4c8 str r2, [sp, #0x14] */
/* @0xdb4cc mov r0, r10 */
/* @0xdb4d0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xdb4d4 cmp r4, #0 */
/* @0xdb4d8 blt 0xdb6b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x200> */
/* @0xdb4dc ldr r3, [pc, #0x218] */
/* @0xdb4e0 ldr r3, [pc, r3] */
/* @0xdb4e4 ldr r3, [r3] */
/* @0xdb4e8 cmp r4, r3 */
/* @0xdb4ec bge 0xdb6b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x200> */
/* @0xdb4f0 ldr r3, [pc, #0x208] */
/* @0xdb4f4 ldr r3, [pc, r3] */
/* @0xdb4f8 ldr r3, [r3, #0x4] */
/* @0xdb4fc ldr r4, [r3, r4, lsl #2] */
/* @0xdb500 cmp r4, #0 */
/* @0xdb504 beq 0xdb6b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x200> */
/* @0xdb508 mov r0, r4 */
/* @0xdb50c bl 0x2052c0 <_ZN7CDS_Map4SizeEv> */
/* @0xdb510 add r2, sp, #20 */
/* @0xdb514 str r0, [sp, #0xc] */
/* @0xdb518 mov r0, r7 */
/* @0xdb51c ldr r1, [sp, #0xc] */
/* @0xdb520 bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi> */
/* @0xdb524 subs r9, r0, #0 */
/* @0xdb528 ble 0xdb670 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1bc> */
/* @0xdb52c ldr r8, [r4] */
/* @0xdb530 mov r5, #0 */
/* @0xdb534 ldr r12, [r8] */
/* @0xdb538 b 0xdb54c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x98> */
/* @0xdb53c ldr r3, [r8, #0x4] */
/* @0xdb540 add r5, r5, #1 */
/* @0xdb544 cmp r5, r3 */
/* @0xdb548 bgt 0xdb6ac <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1f8> */
/* @0xdb54c ldr r4, [r12, r5, lsl #3] */
/* @0xdb550 cmp r4, #0 */
/* @0xdb554 beq 0xdb53c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x88> */
/* @0xdb558 ldr lr, [sp, #0x14] */
/* @0xdb55c cmp lr, #0 */
/* @0xdb560 movgt r1, #0 */
/* @0xdb564 bgt 0xdb578 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xc4> */
/* @0xdb568 b 0xdb5d0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x11c> */
/* @0xdb56c add r1, r1, #1 */
/* @0xdb570 cmp r1, lr */
/* @0xdb574 beq 0xdb5d0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x11c> */
/* @0xdb578 cmp r4, #0 */
/* @0xdb57c beq 0xdb56c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xb8> */
/* @0xdb580 ldr r4, [r4, #0x4] */
/* @0xdb584 cmp r4, #0 */
/* @0xdb588 bne 0xdb56c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xb8> */
/* @0xdb58c ldr r0, [r8, #0x4] */
/* @0xdb590 add r2, r5, #1 */
/* @0xdb594 cmp r2, r0 */
/* @0xdb598 bgt 0xdb5c0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x10c> */
/* @0xdb59c add r3, r12, r5, lsl #3 */
/* @0xdb5a0 ldr r4, [r3, #0x8] */
/* @0xdb5a4 mov r5, r2 */
/* @0xdb5a8 add r3, r3, #8 */
/* @0xdb5ac add r2, r2, #1 */
/* @0xdb5b0 cmp r4, #0 */
/* @0xdb5b4 bne 0xdb56c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xb8> */
/* @0xdb5b8 cmp r0, r2 */
/* @0xdb5bc bge 0xdb5a0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xec> */
/* @0xdb5c0 add r1, r1, #1 */
/* @0xdb5c4 mvn r5, #0 */
/* @0xdb5c8 cmp r1, lr */
/* @0xdb5cc bne 0xdb578 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xc4> */
/* @0xdb5d0 ldr r3, [pc, #0x12c] */
/* @0xdb5d4 mov r6, #0 */
/* @0xdb5d8 add r3, pc, r3 */
/* @0xdb5dc str r3, [sp, #0x10] */
/* @0xdb5e0 b 0xdb5f0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x13c> */
/* @0xdb5e4 add r6, r6, #1 */
/* @0xdb5e8 cmp r6, r9 */
/* @0xdb5ec beq 0xdb670 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1bc> */
/* @0xdb5f0 cmp r4, #0 */
/* @0xdb5f4 beq 0xdb680 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1cc> */
/* @0xdb5f8 ldr r11, [r4, #0xc] */
/* @0xdb5fc cmp r11, #0 */
/* @0xdb600 beq 0xdb680 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1cc> */
/* @0xdb604 mov r0, r11 */
/* @0xdb608 mov r1, r7 */
/* @0xdb60c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb610 add r0, r11, #16 */
/* @0xdb614 mov r1, r7 */
/* @0xdb618 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb61c ldr r4, [r4, #0x4] */
/* @0xdb620 cmp r4, #0 */
/* @0xdb624 bne 0xdb5e4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x130> */
/* @0xdb628 ldr r1, [r8, #0x4] */
/* @0xdb62c add r2, r5, #1 */
/* @0xdb630 cmp r2, r1 */
/* @0xdb634 bgt 0xdb660 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1ac> */
/* @0xdb638 ldr r3, [r8] */
/* @0xdb63c add r3, r3, r5, lsl #3 */
/* @0xdb640 ldr r4, [r3, #0x8] */
/* @0xdb644 mov r5, r2 */
/* @0xdb648 add r3, r3, #8 */
/* @0xdb64c add r2, r2, #1 */
/* @0xdb650 cmp r4, #0 */
/* @0xdb654 bne 0xdb5e4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x130> */
/* @0xdb658 cmp r2, r1 */
/* @0xdb65c ble 0xdb640 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x18c> */
/* @0xdb660 add r6, r6, #1 */
/* @0xdb664 mvn r5, #0 */
/* @0xdb668 cmp r6, r9 */
/* @0xdb66c bne 0xdb5f0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x13c> */
/* @0xdb670 mov r0, r10 */
/* @0xdb674 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xdb678 add sp, sp, #36 */
/* @0xdb67c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdb680 ldr r0, [pc, #0x80] */
/* @0xdb684 ldr r1, [sp, #0x10] */
/* @0xdb688 ldr r0, [pc, r0] */
/* @0xdb68c ldr r3, [sp, #0x14] */
/* @0xdb690 ldr r2, [sp, #0xc] */
/* @0xdb694 ldr r0, [r0] */
/* @0xdb698 ldr r12, [r0] */
/* @0xdb69c str r9, [sp] */
/* @0xdb6a0 ldr r12, [r12, #0xc] */
/* @0xdb6a4 blx r12 */
/* @0xdb6a8 b 0xdb5e4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x130> */
/* @0xdb6ac mvn r5, #0 */
/* @0xdb6b0 b 0xdb558 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xa4> */
/* @0xdb6b4 mov r2, r7 */
/* @0xdb6b8 mov r1, #0 */
/* @0xdb6bc ldr r0, [r2], #44 */
/* @0xdb6c0 movt r1, #0xffe0 */
/* @0xdb6c4 movw r3, #0xffff */
/* @0xdb6c8 str r1, [r7, #0x2c] */
/* @0xdb6cc movt r3, #0x41ef */
/* @0xdb6d0 mov r1, #0 */
/* @0xdb6d4 str r3, [r7, #0x30] */
/* @0xdb6d8 ldr r3, [r0, #0x8] */
/* @0xdb6dc mov r0, r7 */
/* @0xdb6e0 str r1, [r7, #0x38] */
/* @0xdb6e4 mov r1, #5 */
/* @0xdb6e8 blx r3 */
/* @0xdb6ec mov r0, r10 */
/* @0xdb6f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xdb6f4 add sp, sp, #36 */
/* @0xdb6f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdb6fc mlaseq r1, r8, r7, r2 */
/* @0xdb700 eorseq r2, r1, r8, asr #8 */
/* @0xdb704 eoreq r7, r5, r4, ror #12 */
/* @0xdb708 eorseq r2, r1, r12, lsl #1 */

/* ── FUNC 0xdb70c · VM::GetDSGrid(Buffer_Standard*, int, int) · size=444 · insn=111 */
/* @0xdb70c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdb710 sub sp, sp, #20 */
/* @0xdb714 mov r8, r0 */
/* @0xdb718 add r0, sp, #12 */
/* @0xdb71c mov r4, r1 */
/* @0xdb720 mov r7, r2 */
/* @0xdb724 bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xdb728 cmp r4, #0 */
/* @0xdb72c blt 0xdb888 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x17c> */
/* @0xdb730 ldr r3, [sp, #0xc] */
/* @0xdb734 cmp r4, r3 */
/* @0xdb738 bge 0xdb888 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x17c> */
/* @0xdb73c ldr r6, [r0, r4, lsl #2] */
/* @0xdb740 cmp r6, #0 */
/* @0xdb744 beq 0xdb888 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x17c> */
/* @0xdb748 ldr r3, [r6, #0x4] */
/* @0xdb74c add r10, r8, #44 */
/* @0xdb750 ldr r12, [r8] */
/* @0xdb754 mov r11, #0 */
/* @0xdb758 ldr r9, [r6, #0x8] */
/* @0xdb75c mov r2, r10 */
/* @0xdb760 vmov s15, r3 */
/* @0xdb764 str r11, [r8, #0x38] */
/* @0xdb768 mov r1, #5 */
/* @0xdb76c mov r0, r8 */
/* @0xdb770 vcvt.f64.u32 d7, s15 */
/* @0xdb774 vmov r4, r5, d7 */
/* @0xdb778 vstr s14, [r8, #44] */
/* @0xdb77c str r5, [r8, #0x30] */
/* @0xdb780 ldr r12, [r12, #0x8] */
/* @0xdb784 str r3, [sp, #0x4] */
/* @0xdb788 blx r12 */
/* @0xdb78c vmov s13, r9 */
/* @0xdb790 ldr lr, [r8] */
/* @0xdb794 mov r2, r10 */
/* @0xdb798 vcvt.f64.u32 d7, s13 */
/* @0xdb79c str r11, [r8, #0x38] */
/* @0xdb7a0 mov r0, r8 */
/* @0xdb7a4 mov r1, #5 */
/* @0xdb7a8 vstr s14, [r8, #44] */
/* @0xdb7ac vstr s15, [r8, #48] */
/* @0xdb7b0 ldr r12, [lr, #0x8] */
/* @0xdb7b4 blx r12 */
/* @0xdb7b8 cmp r7, r11 */
/* @0xdb7bc ldr r3, [sp, #0x4] */
/* @0xdb7c0 blt 0xdb84c <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x140> */
/* @0xdb7c4 mov r5, #0 */
/* @0xdb7c8 movt r5, #0x3ff0 */
/* @0xdb7cc mov r4, #0 */
/* @0xdb7d0 mov r3, #1 */
/* @0xdb7d4 ldr r0, [r8] */
/* @0xdb7d8 mov r2, r10 */
/* @0xdb7dc str r4, [r8, #0x2c] */
/* @0xdb7e0 add r10, r7, r3 */
/* @0xdb7e4 str r5, [r8, #0x30] */
/* @0xdb7e8 mov r1, #0 */
/* @0xdb7ec ldr r3, [r0, #0x8] */
/* @0xdb7f0 mov r0, r8 */
/* @0xdb7f4 str r1, [r8, #0x38] */
/* @0xdb7f8 mov r1, #5 */
/* @0xdb7fc blx r3 */
/* @0xdb800 cmp r7, r10 */
/* @0xdb804 bge 0xdb844 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x138> */
/* @0xdb808 cmp r9, #0 */
/* @0xdb80c ble 0xdb838 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x12c> */
/* @0xdb810 mov r4, #0 */
/* @0xdb814 ldr r0, [r6, #0x4] */
/* @0xdb818 mov r1, r8 */
/* @0xdb81c ldr r3, [r6] */
/* @0xdb820 mla r0, r0, r4, r7 */
/* @0xdb824 add r4, r4, #1 */
/* @0xdb828 add r0, r3, r0, lsl #4 */
/* @0xdb82c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0xdb830 cmp r4, r9 */
/* @0xdb834 bne 0xdb814 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0x108> */
/* @0xdb838 add r7, r7, #1 */
/* @0xdb83c cmp r7, r10 */
/* @0xdb840 bne 0xdb808 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0xfc> */
/* @0xdb844 add sp, sp, #20 */
/* @0xdb848 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdb84c mul r2, r9, r3 */
/* @0xdb850 cmp r2, #400 */
/* @0xdb854 movle r7, r11 */
/* @0xdb858 ble 0xdb7d4 <_ZN2VM9GetDSGridEP15Buffer_Standardii+0xc8> */
/* @0xdb85c ldr r3, [r8] */
/* @0xdb860 mov r2, r10 */
/* @0xdb864 str r11, [r8, #0x2c] */
/* @0xdb868 mov r0, r8 */
/* @0xdb86c str r11, [r8, #0x30] */
/* @0xdb870 mov r1, #5 */
/* @0xdb874 str r11, [r8, #0x38] */
/* @0xdb878 ldr r3, [r3, #0x8] */
/* @0xdb87c blx r3 */
/* @0xdb880 add sp, sp, #20 */
/* @0xdb884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdb888 mov r2, r8 */
/* @0xdb88c mov r1, #0 */
/* @0xdb890 ldr r0, [r2], #44 */
/* @0xdb894 movt r1, #0xffe0 */
/* @0xdb898 movw r3, #0xffff */
/* @0xdb89c str r1, [r8, #0x2c] */
/* @0xdb8a0 movt r3, #0x41ef */
/* @0xdb8a4 mov r1, #0 */
/* @0xdb8a8 str r3, [r8, #0x30] */
/* @0xdb8ac ldr r3, [r0, #0x8] */
/* @0xdb8b0 mov r0, r8 */
/* @0xdb8b4 str r1, [r8, #0x38] */
/* @0xdb8b8 mov r1, #5 */
/* @0xdb8bc blx r3 */
/* @0xdb8c0 add sp, sp, #20 */
/* @0xdb8c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xdb8c8 · YYStrDup(char const*) · size=108 · insn=27 */
/* @0xdb8c8 push {r4, r5, r6, lr} */
/* @0xdb8cc mov r4, r0 */
/* @0xdb8d0 ldr r0, [pc, #0x54] */
/* @0xdb8d4 add r0, pc, r0 */
/* @0xdb8d8 bl 0x27b948 <_Z17memLogPushContextPKc> */
/* @0xdb8dc cmp r4, #0 */
/* @0xdb8e0 beq 0xdb924 <_Z8YYStrDupPKc+0x5c> */
/* @0xdb8e4 mov r0, r4 */
/* @0xdb8e8 bl 0xb6538 <strlen@plt> */
/* @0xdb8ec mov r3, #1 */
/* @0xdb8f0 ldr r1, [pc, #0x38] */
/* @0xdb8f4 movw r2, #0x2cbd */
/* @0xdb8f8 add r1, pc, r1 */
/* @0xdb8fc add r5, r0, r3 */
/* @0xdb900 mov r0, r5 */
/* @0xdb904 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xdb908 mov r1, r4 */
/* @0xdb90c mov r2, r5 */
/* @0xdb910 mov r6, r0 */
/* @0xdb914 bl 0xb65bc <memcpy@plt> */
/* @0xdb918 bl 0x27b94c <_Z16memLogPopContextv> */
/* @0xdb91c mov r0, r6 */
/* @0xdb920 pop {r4, r5, r6, pc} */
/* @0xdb924 mov r6, r4 */
/* @0xdb928 b 0xdb918 <_Z8YYStrDupPKc+0x50> */
/* @0xdb92c mlaeq r5, r12, r3, r7 */
/* @0xdb930 eoreq r6, r5, r4, lsl #29 */

/* ── FUNC 0xdb934 · vmGetCallStack() · size=2336 · insn=584 */
/* @0xdb934 ldr r3, [pc, #0x8f0] */
/* @0xdb938 mov r2, #0 */
/* @0xdb93c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdb940 ldr r3, [pc, r3] */
/* @0xdb944 sub sp, sp, #60 */
/* @0xdb948 ldr r6, [r3] */
/* @0xdb94c str r2, [sp, #0x2c] */
/* @0xdb950 cmp r6, r2 */
/* @0xdb954 str r2, [sp, #0x30] */
/* @0xdb958 str r2, [sp, #0x34] */
/* @0xdb95c beq 0xdc218 <_Z14vmGetCallStackv+0x8e4> */
/* @0xdb960 ldr r3, [pc, #0x8c8] */
/* @0xdb964 add r10, sp, #44 */
/* @0xdb968 add r3, pc, r3 */
/* @0xdb96c str r3, [sp, #0x20] */
/* @0xdb970 ldr r3, [pc, #0x8bc] */
/* @0xdb974 add r3, pc, r3 */
/* @0xdb978 str r3, [sp, #0x24] */
/* @0xdb97c ldr r3, [pc, #0x8b4] */
/* @0xdb980 add r3, pc, r3 */
/* @0xdb984 str r3, [sp, #0x18] */
/* @0xdb988 ldr r3, [pc, #0x8ac] */
/* @0xdb98c add r3, pc, r3 */
/* @0xdb990 str r3, [sp, #0x1c] */
/* @0xdb994 ldr r3, [pc, #0x8a4] */
/* @0xdb998 add r3, pc, r3 */
/* @0xdb99c str r3, [sp, #0x10] */
/* @0xdb9a0 ldr r3, [pc, #0x89c] */
/* @0xdb9a4 add r3, pc, r3 */
/* @0xdb9a8 str r3, [sp, #0x14] */
/* @0xdb9ac ldr r0, [r6, #0x38] */
/* @0xdb9b0 mov r3, #0 */
/* @0xdb9b4 str r3, [sp, #0x28] */
/* @0xdb9b8 cmp r0, r3 */
/* @0xdb9bc beq 0xdc050 <_Z14vmGetCallStackv+0x71c> */
/* @0xdb9c0 ldr r1, [r6, #0x54] */
/* @0xdb9c4 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xdb9c8 ldr r1, [r6, #0x3c] */
/* @0xdb9cc add r2, sp, #40 */
/* @0xdb9d0 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xdb9d4 ldr r8, [r6, #0x34] */
/* @0xdb9d8 cmp r8, #0 */
/* @0xdb9dc ldreq r4, [sp, #0x34] */
/* @0xdb9e0 mov r5, r0 */
/* @0xdb9e4 beq 0xdba88 <_Z14vmGetCallStackv+0x154> */
/* @0xdb9e8 mov r0, r8 */
/* @0xdb9ec bl 0xb6538 <strlen@plt> */
/* @0xdb9f0 ldr r2, [sp, #0x34] */
/* @0xdb9f4 ldr r3, [sp, #0x30] */
/* @0xdb9f8 add r1, r0, #1 */
/* @0xdb9fc mov r4, r0 */
/* @0xdba00 mvn r0, r2 */
/* @0xdba04 add r0, r3, r0 */
/* @0xdba08 cmp r1, r0 */
/* @0xdba0c ble 0xdba6c <_Z14vmGetCallStackv+0x138> */
/* @0xdba10 cmp r3, #0 */
/* @0xdba14 add r2, r1, r2 */
/* @0xdba18 ldr r7, [sp, #0x2c] */
/* @0xdba1c moveq r3, r1 */
/* @0xdba20 add r3, r3, r3, lsl #1 */
/* @0xdba24 add r3, r3, r3, lsr #31 */
/* @0xdba28 asr r9, r3, #1 */
/* @0xdba2c cmp r9, r2 */
/* @0xdba30 addlt r2, r2, r2, lsl #1 */
/* @0xdba34 addlt r2, r2, r2, lsr #31 */
/* @0xdba38 asrlt r9, r2, #1 */
/* @0xdba3c mov r0, r9 */
/* @0xdba40 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdba44 ldr r2, [sp, #0x30] */
/* @0xdba48 mov r1, r7 */
/* @0xdba4c str r0, [sp, #0x2c] */
/* @0xdba50 bl 0xb65bc <memcpy@plt> */
/* @0xdba54 cmp r7, #0 */
/* @0xdba58 str r9, [sp, #0x30] */
/* @0xdba5c beq 0xdba68 <_Z14vmGetCallStackv+0x134> */
/* @0xdba60 mov r0, r7 */
/* @0xdba64 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdba68 ldr r2, [sp, #0x34] */
/* @0xdba6c ldr r0, [sp, #0x2c] */
/* @0xdba70 mov r1, r8 */
/* @0xdba74 add r0, r0, r2 */
/* @0xdba78 bl 0xb65a4 <strcpy@plt> */
/* @0xdba7c ldr r3, [sp, #0x34] */
/* @0xdba80 add r4, r4, r3 */
/* @0xdba84 str r4, [sp, #0x34] */
/* @0xdba88 ldr r3, [sp, #0x30] */
/* @0xdba8c mvn r2, r4 */
/* @0xdba90 add r2, r3, r2 */
/* @0xdba94 cmp r2, #1 */
/* @0xdba98 bgt 0xdbaf8 <_Z14vmGetCallStackv+0x1c4> */
/* @0xdba9c cmp r3, #0 */
/* @0xdbaa0 add r4, r4, #2 */
/* @0xdbaa4 addne r3, r3, r3, lsl #1 */
/* @0xdbaa8 moveq r7, #3 */
/* @0xdbaac addne r3, r3, r3, lsr #31 */
/* @0xdbab0 asrne r7, r3, #1 */
/* @0xdbab4 cmp r4, r7 */
/* @0xdbab8 addgt r4, r4, r4, lsl #1 */
/* @0xdbabc addgt r4, r4, r4, lsr #31 */
/* @0xdbac0 asrgt r7, r4, #1 */
/* @0xdbac4 ldr r4, [sp, #0x2c] */
/* @0xdbac8 mov r0, r7 */
/* @0xdbacc bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbad0 ldr r2, [sp, #0x30] */
/* @0xdbad4 mov r1, r4 */
/* @0xdbad8 str r0, [sp, #0x2c] */
/* @0xdbadc bl 0xb65bc <memcpy@plt> */
/* @0xdbae0 cmp r4, #0 */
/* @0xdbae4 str r7, [sp, #0x30] */
/* @0xdbae8 beq 0xdbaf4 <_Z14vmGetCallStackv+0x1c0> */
/* @0xdbaec mov r0, r4 */
/* @0xdbaf0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbaf4 ldr r4, [sp, #0x34] */
/* @0xdbaf8 ldr r0, [sp, #0x18] */
/* @0xdbafc mov r1, r5 */
/* @0xdbb00 ldr r3, [sp, #0x2c] */
/* @0xdbb04 ldrh r2, [r0] */
/* @0xdbb08 mov r0, r10 */
/* @0xdbb0c strh r2, [r3, r4] */
/* @0xdbb10 ldr r3, [sp, #0x34] */
/* @0xdbb14 add r3, r3, #1 */
/* @0xdbb18 str r3, [sp, #0x34] */
/* @0xdbb1c bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0xdbb20 ldmib r0, {r2, r3} */
/* @0xdbb24 mov r5, r0 */
/* @0xdbb28 mvn r1, r3 */
/* @0xdbb2c add r1, r2, r1 */
/* @0xdbb30 cmp r1, #1 */
/* @0xdbb34 bgt 0xdbb94 <_Z14vmGetCallStackv+0x260> */
/* @0xdbb38 cmp r2, #0 */
/* @0xdbb3c add r3, r3, #2 */
/* @0xdbb40 addne r2, r2, r2, lsl #1 */
/* @0xdbb44 ldr r4, [r5] */
/* @0xdbb48 moveq r7, #3 */
/* @0xdbb4c addne r2, r2, r2, lsr #31 */
/* @0xdbb50 asrne r7, r2, #1 */
/* @0xdbb54 cmp r3, r7 */
/* @0xdbb58 addgt r3, r3, r3, lsl #1 */
/* @0xdbb5c addgt r3, r3, r3, lsr #31 */
/* @0xdbb60 asrgt r7, r3, #1 */
/* @0xdbb64 mov r0, r7 */
/* @0xdbb68 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbb6c ldr r2, [r5, #0x4] */
/* @0xdbb70 mov r1, r4 */
/* @0xdbb74 str r0, [r5] */
/* @0xdbb78 bl 0xb65bc <memcpy@plt> */
/* @0xdbb7c cmp r4, #0 */
/* @0xdbb80 str r7, [r5, #0x4] */
/* @0xdbb84 beq 0xdbb90 <_Z14vmGetCallStackv+0x25c> */
/* @0xdbb88 mov r0, r4 */
/* @0xdbb8c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbb90 ldr r3, [r5, #0x8] */
/* @0xdbb94 ldr r2, [r5] */
/* @0xdbb98 ldr r0, [sp, #0x1c] */
/* @0xdbb9c ldrh r1, [r0] */
/* @0xdbba0 strh r1, [r2, r3] */
/* @0xdbba4 ldr r3, [r5, #0x8] */
/* @0xdbba8 ldr r4, [r6, #0x28] */
/* @0xdbbac add r3, r3, #1 */
/* @0xdbbb0 str r3, [r5, #0x8] */
/* @0xdbbb4 ldr r3, [pc, #0x68c] */
/* @0xdbbb8 ldr r5, [r6, #0x4c] */
/* @0xdbbbc add r3, pc, r3 */
/* @0xdbbc0 str r3, [sp, #0x8] */
/* @0xdbbc4 ldr r3, [pc, #0x680] */
/* @0xdbbc8 add r3, pc, r3 */
/* @0xdbbcc str r3, [sp, #0xc] */
/* @0xdbbd0 b 0xdbe00 <_Z14vmGetCallStackv+0x4cc> */
/* @0xdbbd4 ldr r1, [r4] */
/* @0xdbbd8 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xdbbdc add r2, sp, #56 */
/* @0xdbbe0 mov r3, #0 */
/* @0xdbbe4 ldr r1, [r4, #0x20] */
/* @0xdbbe8 str r3, [r2, #-0x10]! */
/* @0xdbbec bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xdbbf0 ldr r11, [r4, #0x24] */
/* @0xdbbf4 cmp r11, #0 */
/* @0xdbbf8 ldreq r7, [sp, #0x34] */
/* @0xdbbfc mov r8, r0 */
/* @0xdbc00 beq 0xdbcac <_Z14vmGetCallStackv+0x378> */
/* @0xdbc04 mov r0, r11 */
/* @0xdbc08 bl 0xb6538 <strlen@plt> */
/* @0xdbc0c ldr r2, [sp, #0x34] */
/* @0xdbc10 ldr r3, [sp, #0x30] */
/* @0xdbc14 add r1, r0, #1 */
/* @0xdbc18 mov r7, r0 */
/* @0xdbc1c mvn r0, r2 */
/* @0xdbc20 add r0, r3, r0 */
/* @0xdbc24 cmp r1, r0 */
/* @0xdbc28 ble 0xdbc90 <_Z14vmGetCallStackv+0x35c> */
/* @0xdbc2c cmp r3, #0 */
/* @0xdbc30 add r2, r1, r2 */
/* @0xdbc34 ldr r9, [sp, #0x2c] */
/* @0xdbc38 moveq r3, r1 */
/* @0xdbc3c add r3, r3, r3, lsl #1 */
/* @0xdbc40 add r3, r3, r3, lsr #31 */
/* @0xdbc44 asr r3, r3, #1 */
/* @0xdbc48 cmp r3, r2 */
/* @0xdbc4c addlt r2, r2, r2, lsl #1 */
/* @0xdbc50 addlt r2, r2, r2, lsr #31 */
/* @0xdbc54 asrlt r3, r2, #1 */
/* @0xdbc58 str r3, [sp, #0x4] */
/* @0xdbc5c mov r0, r3 */
/* @0xdbc60 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbc64 ldr r2, [sp, #0x30] */
/* @0xdbc68 mov r1, r9 */
/* @0xdbc6c str r0, [sp, #0x2c] */
/* @0xdbc70 bl 0xb65bc <memcpy@plt> */
/* @0xdbc74 ldr r3, [sp, #0x4] */
/* @0xdbc78 cmp r9, #0 */
/* @0xdbc7c str r3, [sp, #0x30] */
/* @0xdbc80 beq 0xdbc8c <_Z14vmGetCallStackv+0x358> */
/* @0xdbc84 mov r0, r9 */
/* @0xdbc88 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbc8c ldr r2, [sp, #0x34] */
/* @0xdbc90 ldr r0, [sp, #0x2c] */
/* @0xdbc94 mov r1, r11 */
/* @0xdbc98 add r0, r0, r2 */
/* @0xdbc9c bl 0xb65a4 <strcpy@plt> */
/* @0xdbca0 ldr r3, [sp, #0x34] */
/* @0xdbca4 add r7, r7, r3 */
/* @0xdbca8 str r7, [sp, #0x34] */
/* @0xdbcac ldr r3, [sp, #0x30] */
/* @0xdbcb0 mvn r2, r7 */
/* @0xdbcb4 add r2, r3, r2 */
/* @0xdbcb8 cmp r2, #1 */
/* @0xdbcbc bgt 0xdbd1c <_Z14vmGetCallStackv+0x3e8> */
/* @0xdbcc0 cmp r3, #0 */
/* @0xdbcc4 add r7, r7, #2 */
/* @0xdbcc8 addne r3, r3, r3, lsl #1 */
/* @0xdbccc moveq r9, #3 */
/* @0xdbcd0 addne r3, r3, r3, lsr #31 */
/* @0xdbcd4 asrne r9, r3, #1 */
/* @0xdbcd8 cmp r7, r9 */
/* @0xdbcdc addgt r7, r7, r7, lsl #1 */
/* @0xdbce0 addgt r7, r7, r7, lsr #31 */
/* @0xdbce4 asrgt r9, r7, #1 */
/* @0xdbce8 ldr r7, [sp, #0x2c] */
/* @0xdbcec mov r0, r9 */
/* @0xdbcf0 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbcf4 ldr r2, [sp, #0x30] */
/* @0xdbcf8 mov r1, r7 */
/* @0xdbcfc str r0, [sp, #0x2c] */
/* @0xdbd00 bl 0xb65bc <memcpy@plt> */
/* @0xdbd04 cmp r7, #0 */
/* @0xdbd08 str r9, [sp, #0x30] */
/* @0xdbd0c beq 0xdbd18 <_Z14vmGetCallStackv+0x3e4> */
/* @0xdbd10 mov r0, r7 */
/* @0xdbd14 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbd18 ldr r7, [sp, #0x34] */
/* @0xdbd1c ldr r0, [sp, #0x8] */
/* @0xdbd20 mov r1, r8 */
/* @0xdbd24 ldr r3, [sp, #0x2c] */
/* @0xdbd28 ldrh r2, [r0] */
/* @0xdbd2c mov r0, r10 */
/* @0xdbd30 strh r2, [r3, r7] */
/* @0xdbd34 ldr r3, [sp, #0x34] */
/* @0xdbd38 add r3, r3, #1 */
/* @0xdbd3c str r3, [sp, #0x34] */
/* @0xdbd40 bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0xdbd44 ldr r3, [r0, #0x8] */
/* @0xdbd48 mov r8, r0 */
/* @0xdbd4c ldr r9, [r0, #0x4] */
/* @0xdbd50 mvn r2, r3 */
/* @0xdbd54 add r2, r9, r2 */
/* @0xdbd58 cmp r2, #1 */
/* @0xdbd5c bgt 0xdbdbc <_Z14vmGetCallStackv+0x488> */
/* @0xdbd60 cmp r9, #0 */
/* @0xdbd64 add r3, r3, #2 */
/* @0xdbd68 addne r9, r9, r9, lsl #1 */
/* @0xdbd6c ldr r7, [r8] */
/* @0xdbd70 moveq r9, #3 */
/* @0xdbd74 addne r9, r9, r9, lsr #31 */
/* @0xdbd78 asrne r9, r9, #1 */
/* @0xdbd7c cmp r3, r9 */
/* @0xdbd80 addgt r3, r3, r3, lsl #1 */
/* @0xdbd84 addgt r3, r3, r3, lsr #31 */
/* @0xdbd88 asrgt r9, r3, #1 */
/* @0xdbd8c mov r0, r9 */
/* @0xdbd90 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbd94 ldr r2, [r8, #0x4] */
/* @0xdbd98 mov r1, r7 */
/* @0xdbd9c str r0, [r8] */
/* @0xdbda0 bl 0xb65bc <memcpy@plt> */
/* @0xdbda4 cmp r7, #0 */
/* @0xdbda8 str r9, [r8, #0x4] */
/* @0xdbdac beq 0xdbdb8 <_Z14vmGetCallStackv+0x484> */
/* @0xdbdb0 mov r0, r7 */
/* @0xdbdb4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbdb8 ldr r3, [r8, #0x8] */
/* @0xdbdbc ldr r0, [sp, #0xc] */
/* @0xdbdc0 ldr r2, [r8] */
/* @0xdbdc4 ldrh r1, [r0] */
/* @0xdbdc8 strh r1, [r2, r3] */
/* @0xdbdcc ldr r0, [sp, #0x28] */
/* @0xdbdd0 ldr r3, [r8, #0x8] */
/* @0xdbdd4 cmp r0, #0 */
/* @0xdbdd8 add r3, r3, #1 */
/* @0xdbddc str r3, [r8, #0x8] */
/* @0xdbde0 beq 0xdbde8 <_Z14vmGetCallStackv+0x4b4> */
/* @0xdbde4 bl 0xb655c <free@plt> */
/* @0xdbde8 ldr r2, [r4, #0xc] */
/* @0xdbdec sub r5, r5, #1 */
/* @0xdbdf0 ldr r4, [r6, #0x40] */
/* @0xdbdf4 ldr r3, [r6, #0x8] */
/* @0xdbdf8 rsb r4, r2, r4 */
/* @0xdbdfc add r4, r3, r4 */
/* @0xdbe00 cmp r5, #0 */
/* @0xdbe04 ble 0xdc008 <_Z14vmGetCallStackv+0x6d4> */
/* @0xdbe08 ldr r3, [r4, #0x18] */
/* @0xdbe0c cmp r3, #0 */
/* @0xdbe10 beq 0xdc008 <_Z14vmGetCallStackv+0x6d4> */
/* @0xdbe14 ldr r0, [r4, #0x1c] */
/* @0xdbe18 cmp r0, #0 */
/* @0xdbe1c bne 0xdbbd4 <_Z14vmGetCallStackv+0x2a0> */
/* @0xdbe20 ldr r9, [r4, #0x24] */
/* @0xdbe24 cmp r9, #0 */
/* @0xdbe28 ldreq r7, [sp, #0x34] */
/* @0xdbe2c beq 0xdbed8 <_Z14vmGetCallStackv+0x5a4> */
/* @0xdbe30 mov r0, r9 */
/* @0xdbe34 bl 0xb6538 <strlen@plt> */
/* @0xdbe38 ldr r2, [sp, #0x34] */
/* @0xdbe3c ldr r3, [sp, #0x30] */
/* @0xdbe40 add r1, r0, #1 */
/* @0xdbe44 mov r7, r0 */
/* @0xdbe48 mvn r0, r2 */
/* @0xdbe4c add r0, r3, r0 */
/* @0xdbe50 cmp r1, r0 */
/* @0xdbe54 ble 0xdbebc <_Z14vmGetCallStackv+0x588> */
/* @0xdbe58 cmp r3, #0 */
/* @0xdbe5c add r2, r1, r2 */
/* @0xdbe60 ldr r8, [sp, #0x2c] */
/* @0xdbe64 moveq r3, r1 */
/* @0xdbe68 add r3, r3, r3, lsl #1 */
/* @0xdbe6c add r3, r3, r3, lsr #31 */
/* @0xdbe70 asr r3, r3, #1 */
/* @0xdbe74 cmp r3, r2 */
/* @0xdbe78 addlt r2, r2, r2, lsl #1 */
/* @0xdbe7c addlt r2, r2, r2, lsr #31 */
/* @0xdbe80 asrlt r3, r2, #1 */
/* @0xdbe84 str r3, [sp, #0x4] */
/* @0xdbe88 mov r0, r3 */
/* @0xdbe8c bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbe90 ldr r2, [sp, #0x30] */
/* @0xdbe94 mov r1, r8 */
/* @0xdbe98 str r0, [sp, #0x2c] */
/* @0xdbe9c bl 0xb65bc <memcpy@plt> */
/* @0xdbea0 ldr r3, [sp, #0x4] */
/* @0xdbea4 cmp r8, #0 */
/* @0xdbea8 str r3, [sp, #0x30] */
/* @0xdbeac beq 0xdbeb8 <_Z14vmGetCallStackv+0x584> */
/* @0xdbeb0 mov r0, r8 */
/* @0xdbeb4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbeb8 ldr r2, [sp, #0x34] */
/* @0xdbebc ldr r0, [sp, #0x2c] */
/* @0xdbec0 mov r1, r9 */
/* @0xdbec4 add r0, r0, r2 */
/* @0xdbec8 bl 0xb65a4 <strcpy@plt> */
/* @0xdbecc ldr r3, [sp, #0x34] */
/* @0xdbed0 add r7, r7, r3 */
/* @0xdbed4 str r7, [sp, #0x34] */
/* @0xdbed8 ldr r3, [sp, #0x30] */
/* @0xdbedc mvn r2, r7 */
/* @0xdbee0 add r2, r3, r2 */
/* @0xdbee4 cmp r2, #1 */
/* @0xdbee8 bgt 0xdbf48 <_Z14vmGetCallStackv+0x614> */
/* @0xdbeec cmp r3, #0 */
/* @0xdbef0 add r7, r7, #2 */
/* @0xdbef4 addne r3, r3, r3, lsl #1 */
/* @0xdbef8 moveq r8, #3 */
/* @0xdbefc addne r3, r3, r3, lsr #31 */
/* @0xdbf00 asrne r8, r3, #1 */
/* @0xdbf04 cmp r7, r8 */
/* @0xdbf08 addgt r7, r7, r7, lsl #1 */
/* @0xdbf0c addgt r7, r7, r7, lsr #31 */
/* @0xdbf10 asrgt r8, r7, #1 */
/* @0xdbf14 ldr r7, [sp, #0x2c] */
/* @0xdbf18 mov r0, r8 */
/* @0xdbf1c bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbf20 ldr r2, [sp, #0x30] */
/* @0xdbf24 mov r1, r7 */
/* @0xdbf28 str r0, [sp, #0x2c] */
/* @0xdbf2c bl 0xb65bc <memcpy@plt> */
/* @0xdbf30 cmp r7, #0 */
/* @0xdbf34 str r8, [sp, #0x30] */
/* @0xdbf38 beq 0xdbf44 <_Z14vmGetCallStackv+0x610> */
/* @0xdbf3c mov r0, r7 */
/* @0xdbf40 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbf44 ldr r7, [sp, #0x34] */
/* @0xdbf48 ldr r1, [sp, #0x10] */
/* @0xdbf4c mov r0, r10 */
/* @0xdbf50 ldr r3, [sp, #0x2c] */
/* @0xdbf54 ldrh r2, [r1] */
/* @0xdbf58 mvn r1, #0 */
/* @0xdbf5c strh r2, [r3, r7] */
/* @0xdbf60 ldr r3, [sp, #0x34] */
/* @0xdbf64 add r3, r3, #1 */
/* @0xdbf68 str r3, [sp, #0x34] */
/* @0xdbf6c bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0xdbf70 ldr r3, [r0, #0x8] */
/* @0xdbf74 mov r8, r0 */
/* @0xdbf78 ldr r9, [r0, #0x4] */
/* @0xdbf7c mvn r2, r3 */
/* @0xdbf80 add r2, r9, r2 */
/* @0xdbf84 cmp r2, #1 */
/* @0xdbf88 bgt 0xdbfe8 <_Z14vmGetCallStackv+0x6b4> */
/* @0xdbf8c cmp r9, #0 */
/* @0xdbf90 add r3, r3, #2 */
/* @0xdbf94 addne r9, r9, r9, lsl #1 */
/* @0xdbf98 ldr r7, [r8] */
/* @0xdbf9c moveq r9, #3 */
/* @0xdbfa0 addne r9, r9, r9, lsr #31 */
/* @0xdbfa4 asrne r9, r9, #1 */
/* @0xdbfa8 cmp r3, r9 */
/* @0xdbfac addgt r3, r3, r3, lsl #1 */
/* @0xdbfb0 addgt r3, r3, r3, lsr #31 */
/* @0xdbfb4 asrgt r9, r3, #1 */
/* @0xdbfb8 mov r0, r9 */
/* @0xdbfbc bl 0xcef4c <_Z7YYAlloci> */
/* @0xdbfc0 ldr r2, [r8, #0x4] */
/* @0xdbfc4 mov r1, r7 */
/* @0xdbfc8 str r0, [r8] */
/* @0xdbfcc bl 0xb65bc <memcpy@plt> */
/* @0xdbfd0 cmp r7, #0 */
/* @0xdbfd4 str r9, [r8, #0x4] */
/* @0xdbfd8 beq 0xdbfe4 <_Z14vmGetCallStackv+0x6b0> */
/* @0xdbfdc mov r0, r7 */
/* @0xdbfe0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdbfe4 ldr r3, [r8, #0x8] */
/* @0xdbfe8 ldr r0, [sp, #0x14] */
/* @0xdbfec ldr r2, [r8] */
/* @0xdbff0 ldrh r1, [r0] */
/* @0xdbff4 strh r1, [r2, r3] */
/* @0xdbff8 ldr r3, [r8, #0x8] */
/* @0xdbffc add r3, r3, #1 */
/* @0xdc000 str r3, [r8, #0x8] */
/* @0xdc004 b 0xdbde8 <_Z14vmGetCallStackv+0x4b4> */
/* @0xdc008 ldr r6, [r6, #0x4] */
/* @0xdc00c cmp r6, #0 */
/* @0xdc010 bne 0xdb9ac <_Z14vmGetCallStackv+0x78> */
/* @0xdc014 ldr r3, [sp, #0x34] */
/* @0xdc018 cmp r3, #0 */
/* @0xdc01c mov r3, #0 */
/* @0xdc020 addeq r0, sp, #52 */
/* @0xdc024 str r3, [sp, #0x34] */
/* @0xdc028 ldrne r0, [sp, #0x2c] */
/* @0xdc02c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xdc030 mov r4, r0 */
/* @0xdc034 ldr r0, [sp, #0x2c] */
/* @0xdc038 cmp r0, #0 */
/* @0xdc03c beq 0xdc044 <_Z14vmGetCallStackv+0x710> */
/* @0xdc040 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc044 mov r0, r4 */
/* @0xdc048 add sp, sp, #60 */
/* @0xdc04c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdc050 ldr r7, [r6, #0x34] */
/* @0xdc054 cmp r7, #0 */
/* @0xdc058 ldreq r4, [sp, #0x34] */
/* @0xdc05c beq 0xdc100 <_Z14vmGetCallStackv+0x7cc> */
/* @0xdc060 mov r0, r7 */
/* @0xdc064 bl 0xb6538 <strlen@plt> */
/* @0xdc068 ldr r2, [sp, #0x34] */
/* @0xdc06c ldr r3, [sp, #0x30] */
/* @0xdc070 add r1, r0, #1 */
/* @0xdc074 mov r4, r0 */
/* @0xdc078 mvn r0, r2 */
/* @0xdc07c add r0, r3, r0 */
/* @0xdc080 cmp r1, r0 */
/* @0xdc084 ble 0xdc0e4 <_Z14vmGetCallStackv+0x7b0> */
/* @0xdc088 cmp r3, #0 */
/* @0xdc08c add r2, r1, r2 */
/* @0xdc090 ldr r5, [sp, #0x2c] */
/* @0xdc094 moveq r3, r1 */
/* @0xdc098 add r3, r3, r3, lsl #1 */
/* @0xdc09c add r3, r3, r3, lsr #31 */
/* @0xdc0a0 asr r8, r3, #1 */
/* @0xdc0a4 cmp r8, r2 */
/* @0xdc0a8 addlt r2, r2, r2, lsl #1 */
/* @0xdc0ac addlt r2, r2, r2, lsr #31 */
/* @0xdc0b0 asrlt r8, r2, #1 */
/* @0xdc0b4 mov r0, r8 */
/* @0xdc0b8 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdc0bc ldr r2, [sp, #0x30] */
/* @0xdc0c0 mov r1, r5 */
/* @0xdc0c4 str r0, [sp, #0x2c] */
/* @0xdc0c8 bl 0xb65bc <memcpy@plt> */
/* @0xdc0cc cmp r5, #0 */
/* @0xdc0d0 str r8, [sp, #0x30] */
/* @0xdc0d4 beq 0xdc0e0 <_Z14vmGetCallStackv+0x7ac> */
/* @0xdc0d8 mov r0, r5 */
/* @0xdc0dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc0e0 ldr r2, [sp, #0x34] */
/* @0xdc0e4 ldr r0, [sp, #0x2c] */
/* @0xdc0e8 mov r1, r7 */
/* @0xdc0ec add r0, r0, r2 */
/* @0xdc0f0 bl 0xb65a4 <strcpy@plt> */
/* @0xdc0f4 ldr r3, [sp, #0x34] */
/* @0xdc0f8 add r4, r4, r3 */
/* @0xdc0fc str r4, [sp, #0x34] */
/* @0xdc100 ldr r3, [sp, #0x30] */
/* @0xdc104 mvn r2, r4 */
/* @0xdc108 add r2, r3, r2 */
/* @0xdc10c cmp r2, #1 */
/* @0xdc110 bgt 0xdc170 <_Z14vmGetCallStackv+0x83c> */
/* @0xdc114 cmp r3, #0 */
/* @0xdc118 add r4, r4, #2 */
/* @0xdc11c addne r3, r3, r3, lsl #1 */
/* @0xdc120 moveq r5, #3 */
/* @0xdc124 addne r3, r3, r3, lsr #31 */
/* @0xdc128 asrne r5, r3, #1 */
/* @0xdc12c cmp r4, r5 */
/* @0xdc130 addgt r4, r4, r4, lsl #1 */
/* @0xdc134 addgt r4, r4, r4, lsr #31 */
/* @0xdc138 asrgt r5, r4, #1 */
/* @0xdc13c ldr r4, [sp, #0x2c] */
/* @0xdc140 mov r0, r5 */
/* @0xdc144 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdc148 ldr r2, [sp, #0x30] */
/* @0xdc14c mov r1, r4 */
/* @0xdc150 str r0, [sp, #0x2c] */
/* @0xdc154 bl 0xb65bc <memcpy@plt> */
/* @0xdc158 cmp r4, #0 */
/* @0xdc15c str r5, [sp, #0x30] */
/* @0xdc160 beq 0xdc16c <_Z14vmGetCallStackv+0x838> */
/* @0xdc164 mov r0, r4 */
/* @0xdc168 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc16c ldr r4, [sp, #0x34] */
/* @0xdc170 ldr r1, [sp, #0x20] */
/* @0xdc174 mov r0, r10 */
/* @0xdc178 ldr r3, [sp, #0x2c] */
/* @0xdc17c ldrh r2, [r1] */
/* @0xdc180 mvn r1, #0 */
/* @0xdc184 strh r2, [r3, r4] */
/* @0xdc188 ldr r3, [sp, #0x34] */
/* @0xdc18c add r3, r3, #1 */
/* @0xdc190 str r3, [sp, #0x34] */
/* @0xdc194 bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0xdc198 ldmib r0, {r2, r3} */
/* @0xdc19c mov r5, r0 */
/* @0xdc1a0 mvn r1, r3 */
/* @0xdc1a4 add r1, r2, r1 */
/* @0xdc1a8 cmp r1, #1 */
/* @0xdc1ac bgt 0xdc20c <_Z14vmGetCallStackv+0x8d8> */
/* @0xdc1b0 cmp r2, #0 */
/* @0xdc1b4 add r3, r3, #2 */
/* @0xdc1b8 addne r2, r2, r2, lsl #1 */
/* @0xdc1bc ldr r4, [r5] */
/* @0xdc1c0 moveq r7, #3 */
/* @0xdc1c4 addne r2, r2, r2, lsr #31 */
/* @0xdc1c8 asrne r7, r2, #1 */
/* @0xdc1cc cmp r3, r7 */
/* @0xdc1d0 addgt r3, r3, r3, lsl #1 */
/* @0xdc1d4 addgt r3, r3, r3, lsr #31 */
/* @0xdc1d8 asrgt r7, r3, #1 */
/* @0xdc1dc mov r0, r7 */
/* @0xdc1e0 bl 0xcef4c <_Z7YYAlloci> */
/* @0xdc1e4 ldr r2, [r5, #0x4] */
/* @0xdc1e8 mov r1, r4 */
/* @0xdc1ec str r0, [r5] */
/* @0xdc1f0 bl 0xb65bc <memcpy@plt> */
/* @0xdc1f4 cmp r4, #0 */
/* @0xdc1f8 str r7, [r5, #0x4] */
/* @0xdc1fc beq 0xdc208 <_Z14vmGetCallStackv+0x8d4> */
/* @0xdc200 mov r0, r4 */
/* @0xdc204 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xdc208 ldr r3, [r5, #0x8] */
/* @0xdc20c ldr r2, [r5] */
/* @0xdc210 ldr r0, [sp, #0x24] */
/* @0xdc214 b 0xdbb9c <_Z14vmGetCallStackv+0x268> */
/* @0xdc218 ldr r0, [pc, #0x30] */
/* @0xdc21c add r0, pc, r0 */
/* @0xdc220 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xdc224 mov r4, r0 */
/* @0xdc228 b 0xdc034 <_Z14vmGetCallStackv+0x700> */
/* @0xdc22c eorseq r2, r1, r8, ror #4 */
/* @0xdc230 eoreq r7, r5, r12, lsr #6 */
/* @0xdc234 eoreq r7, r5, r4, lsr #6 */
/* @0xdc238 eoreq r7, r5, r4, lsl r3 */
/* @0xdc23c eoreq r7, r5, r12, lsl #6 */
/* @0xdc240 .word 0x002572fc */
/* @0xdc244 .word 0x002572f4 */
/* @0xdc248 .word 0x002570d8 */
/* @0xdc24c .word 0x002570d0 */
/* @0xdc250 eoreq r6, r5, r0, ror #20 */

/* ── FUNC 0xdc254 · YYGML_AddString(char const*, char const*) · size=180 · insn=45 */
/* @0xdc254 push {r3, r4, r5, r6, r7, lr} */
/* @0xdc258 adds r3, r0, #0 */
/* @0xdc25c mov r4, r1 */
/* @0xdc260 mov r5, r0 */
/* @0xdc264 movne r3, #1 */
/* @0xdc268 adds r2, r1, #0 */
/* @0xdc26c movne r2, #1 */
/* @0xdc270 tst r3, r2 */
/* @0xdc274 bne 0xdc2ac <_Z15YYGML_AddStringPKcS0_+0x58> */
/* @0xdc278 cmp r1, #0 */
/* @0xdc27c movne r3, #0 */
/* @0xdc280 andeq r3, r3, #1 */
/* @0xdc284 cmp r3, #0 */
/* @0xdc288 bne 0xdc2a4 <_Z15YYGML_AddStringPKcS0_+0x50> */
/* @0xdc28c cmp r0, #0 */
/* @0xdc290 movne r2, #0 */
/* @0xdc294 andeq r2, r2, #1 */
/* @0xdc298 cmp r2, #0 */
/* @0xdc29c beq 0xdc2f8 <_Z15YYGML_AddStringPKcS0_+0xa4> */
/* @0xdc2a0 mov r0, r1 */
/* @0xdc2a4 pop {r3, r4, r5, r6, r7, lr} */
/* @0xdc2a8 b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xdc2ac bl 0xb6538 <strlen@plt> */
/* @0xdc2b0 mov r7, r0 */
/* @0xdc2b4 mov r0, r4 */
/* @0xdc2b8 bl 0xb6538 <strlen@plt> */
/* @0xdc2bc ldr r1, [pc, #0x40] */
/* @0xdc2c0 mov r3, #1 */
/* @0xdc2c4 movw r2, #0x2ca8 */
/* @0xdc2c8 add r1, pc, r1 */
/* @0xdc2cc add r0, r7, r0 */
/* @0xdc2d0 add r0, r0, r3 */
/* @0xdc2d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xdc2d8 mov r1, r5 */
/* @0xdc2dc mov r6, r0 */
/* @0xdc2e0 bl 0xb65a4 <strcpy@plt> */
/* @0xdc2e4 add r0, r6, r7 */
/* @0xdc2e8 mov r1, r4 */
/* @0xdc2ec bl 0xb65a4 <strcpy@plt> */
/* @0xdc2f0 mov r0, r6 */
/* @0xdc2f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0xdc2f8 mov r6, r2 */
/* @0xdc2fc mov r0, r6 */
/* @0xdc300 pop {r3, r4, r5, r6, r7, pc} */
/* @0xdc304 .word 0x002564b4 */

/* ── FUNC 0xdc308 · YYSetString(RValue*, char const*) · size=68 · insn=17 */
/* @0xdc308 push {r4, r5, r6, lr} */
/* @0xdc30c mov r6, r0 */
/* @0xdc310 mov r0, #12 */
/* @0xdc314 mov r5, r1 */
/* @0xdc318 bl 0x27c524 <_Znwj> */
/* @0xdc31c mov r4, r0 */
/* @0xdc320 subs r0, r5, #0 */
/* @0xdc324 beq 0xdc32c <_Z11YYSetStringP6RValuePKc+0x24> */
/* @0xdc328 bl 0xb6538 <strlen@plt> */
/* @0xdc32c str r0, [r4, #0x8] */
/* @0xdc330 mov r0, r5 */
/* @0xdc334 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xdc338 mov r3, #1 */
/* @0xdc33c stm r4, {r0, r3} */
/* @0xdc340 str r3, [r6, #0xc] */
/* @0xdc344 str r4, [r6] */
/* @0xdc348 pop {r4, r5, r6, pc} */

/* ── FUNC 0xdc34c · YYSetString(RValue*, _RefThing<char const*>*) · size=48 · insn=12 */
/* @0xdc34c push {r3, r4, r5, lr} */
/* @0xdc350 mov r5, r0 */
/* @0xdc354 mov r3, #1 */
/* @0xdc358 mov r0, #12 */
/* @0xdc35c str r3, [r5, #0xc] */
/* @0xdc360 mov r4, r1 */
/* @0xdc364 bl 0x27c524 <_Znwj> */
/* @0xdc368 mov r3, r0 */
/* @0xdc36c ldm r4, {r0, r1, r2} */
/* @0xdc370 stm r3, {r0, r1, r2} */
/* @0xdc374 str r3, [r5] */
/* @0xdc378 pop {r3, r4, r5, pc} */

/* ── FUNC 0xdc37c · YYSetInstance(RValue*) · size=52 · insn=13 */
/* @0xdc37c ldr r3, [pc, #0x28] */
/* @0xdc380 mov r2, #6 */
/* @0xdc384 push {r4, lr} */
/* @0xdc388 ldr r3, [pc, r3] */
/* @0xdc38c str r2, [r0, #0xc] */
/* @0xdc390 mov r4, r0 */
/* @0xdc394 mvn r1, #-16777216 */
/* @0xdc398 mov r2, #0 */
/* @0xdc39c ldr r0, [r3] */
/* @0xdc3a0 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0xdc3a4 str r0, [r4] */
/* @0xdc3a8 pop {r4, pc} */
/* @0xdc3ac eorseq r1, r1, r12, lsl #19 */

/* ── FUNC 0xdc3b0 · YYSetScriptRef(RValue*) · size=60 · insn=15 */
/* @0xdc3b0 push {r3, r4, r5, lr} */
/* @0xdc3b4 mov r4, r0 */
/* @0xdc3b8 mov r3, #6 */
/* @0xdc3bc mov r0, #156 */
/* @0xdc3c0 str r3, [r4, #0xc] */
/* @0xdc3c4 bl 0x27c524 <_Znwj> */
/* @0xdc3c8 ldr r3, [pc, #0x18] */
/* @0xdc3cc mvn r2, #-16777216 */
/* @0xdc3d0 ldr r3, [pc, r3] */
/* @0xdc3d4 ldr r1, [r3] */
/* @0xdc3d8 mov r5, r0 */
/* @0xdc3dc bl 0x191de0 <_ZN10CScriptRefC2Eii> */
/* @0xdc3e0 str r5, [r4] */
/* @0xdc3e4 pop {r3, r4, r5, pc} */
/* @0xdc3e8 eorseq r1, r1, r4, asr #18 */

/* ── FUNC 0xdc3ec · YYstrnlen(char const*, int) · size=40 · insn=10 */
/* @0xdc3ec push {r3, r4, r5, lr} */
/* @0xdc3f0 mov r4, r1 */
/* @0xdc3f4 mov r2, r4 */
/* @0xdc3f8 mov r1, #0 */
/* @0xdc3fc mov r5, r0 */
/* @0xdc400 bl 0xb66a0 <memchr@plt> */
/* @0xdc404 cmp r0, #0 */
/* @0xdc408 rsbne r0, r5, r0 */
/* @0xdc40c moveq r0, r4 */
/* @0xdc410 pop {r3, r4, r5, pc} */

/* ── FUNC 0xdc414 · YYStrFree(char const*) · size=4 · insn=1 */
/* @0xdc414 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
