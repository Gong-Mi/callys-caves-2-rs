/* libyoyo.so 覆盖卡组 0185
 * 函数 0x205378..0x209a34，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x205378 · DestroyDsList(int) · size=68 · insn=17 */
/* @0x205378 vmov s13, r0 */
/* @0x20537c mov r12, #0 */
/* @0x205380 str lr, [sp, #-0x4]! */
/* @0x205384 vcvt.f64.s32 d7, s13 */
/* @0x205388 sub sp, sp, #44 */
/* @0x20538c mov r1, r12 */
/* @0x205390 add r3, sp, #24 */
/* @0x205394 mov r2, r12 */
/* @0x205398 str r3, [sp] */
/* @0x20539c add r0, sp, #8 */
/* @0x2053a0 mov r3, #1 */
/* @0x2053a4 str r12, [sp, #0x8] */
/* @0x2053a8 str r12, [sp, #0x24] */
/* @0x2053ac vstr d7, [sp, #24] */
/* @0x2053b0 bl 0xfb8e4 <_Z15F_DsListDestroyR6RValueP9CInstanceS2_iPS_> */
/* @0x2053b4 add sp, sp, #44 */
/* @0x2053b8 ldr pc, [sp], #4 */

/* ── FUNC 0x2053bc · DsQueueCreate() · size=52 · insn=13 */
/* @0x2053bc str lr, [sp, #-0x4]! */
/* @0x2053c0 sub sp, sp, #28 */
/* @0x2053c4 add r0, sp, #24 */
/* @0x2053c8 mov r3, #0 */
/* @0x2053cc mov r1, r3 */
/* @0x2053d0 str r3, [sp] */
/* @0x2053d4 mov r2, r3 */
/* @0x2053d8 str r3, [r0, #-0x10]! */
/* @0x2053dc bl 0xfad10 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_> */
/* @0x2053e0 ldrd r0, r1, [sp, #8] */
/* @0x2053e4 bl 0xb66e8 <lrint@plt> */
/* @0x2053e8 add sp, sp, #28 */
/* @0x2053ec ldr pc, [sp], #4 */

/* ── FUNC 0x2053f0 · DsQueueEnqueue(int, int, ...) · size=180 · insn=45 */
/* @0x2053f0 push {r1, r2, r3} */
/* @0x2053f4 cmp r0, #0 */
/* @0x2053f8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2053fc sub sp, sp, #68 */
/* @0x205400 ldr r5, [sp, #0x64] */
/* @0x205404 blt 0x205494 <_Z14DsQueueEnqueueiiz+0xa4> */
/* @0x205408 vmov s13, r0 */
/* @0x20540c cmp r5, #0 */
/* @0x205410 mov r4, #0 */
/* @0x205414 add r10, sp, #104 */
/* @0x205418 vcvt.f64.s32 d7, s13 */
/* @0x20541c str r4, [sp, #0x10] */
/* @0x205420 str r4, [sp, #0x2c] */
/* @0x205424 str r10, [sp, #0xc] */
/* @0x205428 vstr d7, [sp, #32] */
/* @0x20542c ble 0x205494 <_Z14DsQueueEnqueueiiz+0xa4> */
/* @0x205430 add r9, sp, #16 */
/* @0x205434 add r8, sp, #32 */
/* @0x205438 add r7, sp, #48 */
/* @0x20543c mov r6, r4 */
/* @0x205440 add r10, r10, #7 */
/* @0x205444 mov r0, r7 */
/* @0x205448 bic r3, r10, #7 */
/* @0x20544c add r4, r4, #1 */
/* @0x205450 str r6, [sp, #0x3c] */
/* @0x205454 mov r10, r3 */
/* @0x205458 ldr r1, [r3, #0x8] */
/* @0x20545c ldrd r2, r3, [r10], #12 */
/* @0x205460 cmp r1, #0 */
/* @0x205464 strd r2, r3, [sp, #48] */
/* @0x205468 str r10, [sp, #0xc] */
/* @0x20546c beq 0x205474 <_Z14DsQueueEnqueueiiz+0x84> */
/* @0x205470 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x205474 mov r1, #0 */
/* @0x205478 str r8, [sp] */
/* @0x20547c mov r2, r1 */
/* @0x205480 mov r0, r9 */
/* @0x205484 mov r3, #2 */
/* @0x205488 bl 0xfc048 <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_> */
/* @0x20548c cmp r4, r5 */
/* @0x205490 bne 0x205440 <_Z14DsQueueEnqueueiiz+0x50> */
/* @0x205494 add sp, sp, #68 */
/* @0x205498 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x20549c add sp, sp, #12 */
/* @0x2054a0 bx lr */

/* ── FUNC 0x2054a4 · DsQueueEnqueuePtr(int, int, ...) · size=216 · insn=54 */
/* @0x2054a4 push {r1, r2, r3} */
/* @0x2054a8 cmp r0, #0 */
/* @0x2054ac push {r4, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2054b0 sub sp, sp, #68 */
/* @0x2054b4 ldr r7, [sp, #0x64] */
/* @0x2054b8 blt 0x20556c <_Z17DsQueueEnqueuePtriiz+0xc8> */
/* @0x2054bc vmov s13, r0 */
/* @0x2054c0 cmp r7, #0 */
/* @0x2054c4 mov r12, #0 */
/* @0x2054c8 mov r2, #0 */
/* @0x2054cc vcvt.f64.s32 d7, s13 */
/* @0x2054d0 mov r3, #0 */
/* @0x2054d4 mvn r1, #-16777216 */
/* @0x2054d8 add r6, sp, #104 */
/* @0x2054dc str r12, [sp, #0x10] */
/* @0x2054e0 str r12, [sp, #0x28] */
/* @0x2054e4 str r12, [sp, #0x38] */
/* @0x2054e8 str r12, [sp, #0x2c] */
/* @0x2054ec strd r2, r3, [sp, #48] */
/* @0x2054f0 vstr d7, [sp, #32] */
/* @0x2054f4 str r1, [sp, #0x3c] */
/* @0x2054f8 str r6, [sp, #0xc] */
/* @0x2054fc ble 0x20556c <_Z17DsQueueEnqueuePtriiz+0xc8> */
/* @0x205500 add r10, sp, #16 */
/* @0x205504 add r9, sp, #32 */
/* @0x205508 mov r4, r12 */
/* @0x20550c mov r8, r12 */
/* @0x205510 mov r11, #3 */
/* @0x205514 add r6, r6, #7 */
/* @0x205518 mov r1, #0 */
/* @0x20551c bic lr, r6, #7 */
/* @0x205520 mov r0, r10 */
/* @0x205524 mov r2, r1 */
/* @0x205528 mov r3, #2 */
/* @0x20552c mov r6, lr */
/* @0x205530 ldr lr, [lr, #0x8] */
/* @0x205534 mov r12, r6 */
/* @0x205538 add r4, r4, #1 */
/* @0x20553c vldr d7, [r12] */
/* @0x205540 str r9, [sp] */
/* @0x205544 cmp lr, r1 */
/* @0x205548 str r8, [sp, #0x3c] */
/* @0x20554c vstr d7, [sp, #48] */
/* @0x205550 strne r11, [sp, #0x3c] */
/* @0x205554 strne lr, [sp, #0x30] */
/* @0x205558 add r6, r6, #12 */
/* @0x20555c str r6, [sp, #0xc] */
/* @0x205560 bl 0xfc048 <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_> */
/* @0x205564 cmp r4, r7 */
/* @0x205568 bne 0x205514 <_Z17DsQueueEnqueuePtriiz+0x70> */
/* @0x20556c add sp, sp, #68 */
/* @0x205570 pop {r4, r6, r7, r8, r9, r10, r11, lr} */
/* @0x205574 add sp, sp, #12 */
/* @0x205578 bx lr */

/* ── FUNC 0x20557c · DsQueueDequeue(int, RValue&) · size=76 · insn=19 */
/* @0x20557c subs r3, r0, #0 */
/* @0x205580 mov r0, r1 */
/* @0x205584 push {r4, r5, lr} */
/* @0x205588 sub sp, sp, #28 */
/* @0x20558c blt 0x2055c0 <_Z14DsQueueDequeueiR6RValue+0x44> */
/* @0x205590 vmov s13, r3 */
/* @0x205594 add r12, sp, #24 */
/* @0x205598 mov lr, #0 */
/* @0x20559c mov r3, #1 */
/* @0x2055a0 vcvt.f64.s32 d7, s13 */
/* @0x2055a4 mov r1, lr */
/* @0x2055a8 mov r2, lr */
/* @0x2055ac str lr, [sp, #0x14] */
/* @0x2055b0 vmov r4, r5, d7 */
/* @0x2055b4 strd r4, r5, [r12, #-16]! */
/* @0x2055b8 str r12, [sp] */
/* @0x2055bc bl 0x101d8c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_> */
/* @0x2055c0 add sp, sp, #28 */
/* @0x2055c4 pop {r4, r5, pc} */

/* ── FUNC 0x2055c8 · DsQueueSize(int) · size=88 · insn=22 */
/* @0x2055c8 cmp r0, #0 */
/* @0x2055cc str lr, [sp, #-0x4]! */
/* @0x2055d0 movlt r0, #0 */
/* @0x2055d4 sub sp, sp, #44 */
/* @0x2055d8 blt 0x205618 <_Z11DsQueueSizei+0x50> */
/* @0x2055dc vmov s13, r0 */
/* @0x2055e0 mov r12, #0 */
/* @0x2055e4 mov r1, r12 */
/* @0x2055e8 add r3, sp, #24 */
/* @0x2055ec vcvt.f64.s32 d7, s13 */
/* @0x2055f0 str r3, [sp] */
/* @0x2055f4 add r0, sp, #8 */
/* @0x2055f8 mov r2, r12 */
/* @0x2055fc mov r3, #1 */
/* @0x205600 str r12, [sp, #0x8] */
/* @0x205604 str r12, [sp, #0x24] */
/* @0x205608 vstr d7, [sp, #24] */
/* @0x20560c bl 0xfbf24 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_> */
/* @0x205610 ldrd r0, r1, [sp, #8] */
/* @0x205614 bl 0xb66e8 <lrint@plt> */
/* @0x205618 add sp, sp, #44 */
/* @0x20561c ldr pc, [sp], #4 */

/* ── FUNC 0x205620 · DsQueueClear(int) · size=76 · insn=19 */
/* @0x205620 cmp r0, #0 */
/* @0x205624 str lr, [sp, #-0x4]! */
/* @0x205628 sub sp, sp, #44 */
/* @0x20562c blt 0x205664 <_Z12DsQueueCleari+0x44> */
/* @0x205630 vmov s13, r0 */
/* @0x205634 mov r12, #0 */
/* @0x205638 add r3, sp, #24 */
/* @0x20563c mov r1, r12 */
/* @0x205640 vcvt.f64.s32 d7, s13 */
/* @0x205644 str r3, [sp] */
/* @0x205648 mov r2, r12 */
/* @0x20564c add r0, sp, #8 */
/* @0x205650 mov r3, #1 */
/* @0x205654 str r12, [sp, #0x8] */
/* @0x205658 str r12, [sp, #0x24] */
/* @0x20565c vstr d7, [sp, #24] */
/* @0x205660 bl 0xfbe14 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_> */
/* @0x205664 add sp, sp, #44 */
/* @0x205668 ldr pc, [sp], #4 */

/* ── FUNC 0x20566c · CDS_Stack::Push(RValue*) · size=544 · insn=136 */
/* @0x20566c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x205670 mov r5, r1 */
/* @0x205674 ldmib r0, {r1, r3} */
/* @0x205678 mov r4, r0 */
/* @0x20567c cmp r1, r3 */
/* @0x205680 bge 0x205790 <_ZN9CDS_Stack4PushEP6RValue+0x124> */
/* @0x205684 ldr r7, [r4, #0xc] */
/* @0x205688 lsl r8, r1, #4 */
/* @0x20568c add r6, r7, r8 */
/* @0x205690 ldr r2, [r6, #0xc] */
/* @0x205694 bic r3, r2, #-16777216 */
/* @0x205698 cmp r3, #1 */
/* @0x20569c beq 0x20575c <_ZN9CDS_Stack4PushEP6RValue+0xf0> */
/* @0x2056a0 cmp r3, #2 */
/* @0x2056a4 bne 0x2056cc <_ZN9CDS_Stack4PushEP6RValue+0x60> */
/* @0x2056a8 sub r2, r2, #1 */
/* @0x2056ac bic r2, r2, #-16777216 */
/* @0x2056b0 bic r2, r2, #3 */
/* @0x2056b4 cmp r2, #0 */
/* @0x2056b8 beq 0x20587c <_ZN9CDS_Stack4PushEP6RValue+0x210> */
/* @0x2056bc mov r2, #0 */
/* @0x2056c0 mov r3, #5 */
/* @0x2056c4 str r2, [r6, #0x8] */
/* @0x2056c8 str r3, [r6, #0xc] */
/* @0x2056cc ldr r3, [r5, #0xc] */
/* @0x2056d0 mov r1, #0 */
/* @0x2056d4 ldr r2, [r5, #0x8] */
/* @0x2056d8 str r1, [r7, r8] */
/* @0x2056dc str r3, [r6, #0xc] */
/* @0x2056e0 ldr r3, [r5, #0xc] */
/* @0x2056e4 str r2, [r6, #0x8] */
/* @0x2056e8 bic r3, r3, #-16777216 */
/* @0x2056ec cmp r3, #14 */
/* @0x2056f0 addls pc, pc, r3, lsl #2 */
/* @0x2056f4 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x2056f8 b 0x20574c <_ZN9CDS_Stack4PushEP6RValue+0xe0> */
/* @0x2056fc b 0x2057e0 <_ZN9CDS_Stack4PushEP6RValue+0x174> */
/* @0x205700 b 0x2057f8 <_ZN9CDS_Stack4PushEP6RValue+0x18c> */
/* @0x205704 b 0x205734 <_ZN9CDS_Stack4PushEP6RValue+0xc8> */
/* @0x205708 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x20570c b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x205710 b 0x2057bc <_ZN9CDS_Stack4PushEP6RValue+0x150> */
/* @0x205714 b 0x205734 <_ZN9CDS_Stack4PushEP6RValue+0xc8> */
/* @0x205718 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x20571c b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x205720 b 0x20574c <_ZN9CDS_Stack4PushEP6RValue+0xe0> */
/* @0x205724 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x205728 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x20572c b 0x20574c <_ZN9CDS_Stack4PushEP6RValue+0xe0> */
/* @0x205730 b 0x205734 <_ZN9CDS_Stack4PushEP6RValue+0xc8> */
/* @0x205734 ldr r3, [r5] */
/* @0x205738 str r3, [r7, r8] */
/* @0x20573c ldr r3, [r4, #0x4] */
/* @0x205740 add r3, r3, #1 */
/* @0x205744 str r3, [r4, #0x4] */
/* @0x205748 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20574c ldm r5, {r2, r3} */
/* @0x205750 str r2, [r7, r8] */
/* @0x205754 str r3, [r6, #0x4] */
/* @0x205758 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x20575c ldr r9, [r7, r1, lsl #4] */
/* @0x205760 cmp r9, #0 */
/* @0x205764 beq 0x205784 <_ZN9CDS_Stack4PushEP6RValue+0x118> */
/* @0x205768 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20576c ldr r10, [r9, #0x4] */
/* @0x205770 sub r10, r10, #1 */
/* @0x205774 str r10, [r9, #0x4] */
/* @0x205778 cmp r10, #0 */
/* @0x20577c beq 0x205824 <_ZN9CDS_Stack4PushEP6RValue+0x1b8> */
/* @0x205780 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205784 mov r3, #0 */
/* @0x205788 str r3, [r7, r8] */
/* @0x20578c b 0x2056cc <_ZN9CDS_Stack4PushEP6RValue+0x60> */
/* @0x205790 add r1, r1, #16 */
/* @0x205794 ldr r2, [pc, #0xec] */
/* @0x205798 movw r3, #0x25e */
/* @0x20579c add r0, r0, #12 */
/* @0x2057a0 lsl r1, r1, #4 */
/* @0x2057a4 add r2, pc, r2 */
/* @0x2057a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2057ac ldr r1, [r4, #0x4] */
/* @0x2057b0 add r3, r1, #16 */
/* @0x2057b4 str r3, [r4, #0x8] */
/* @0x2057b8 b 0x205684 <_ZN9CDS_Stack4PushEP6RValue+0x18> */
/* @0x2057bc ldr r3, [r5] */
/* @0x2057c0 str r3, [r7, r8] */
/* @0x2057c4 ldr r3, [r5] */
/* @0x2057c8 cmp r3, #0 */
/* @0x2057cc beq 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x2057d0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2057d4 ldr r1, [r5] */
/* @0x2057d8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2057dc b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x2057e0 ldr r3, [r5] */
/* @0x2057e4 cmp r3, #0 */
/* @0x2057e8 ldrne r2, [r3, #0x4] */
/* @0x2057ec addne r2, r2, #1 */
/* @0x2057f0 strne r2, [r3, #0x4] */
/* @0x2057f4 b 0x205738 <_ZN9CDS_Stack4PushEP6RValue+0xcc> */
/* @0x2057f8 ldr r3, [r5] */
/* @0x2057fc cmp r3, #0 */
/* @0x205800 str r3, [r7, r8] */
/* @0x205804 beq 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x205808 ldr r1, [r3, #0x8] */
/* @0x20580c ldr r2, [r3] */
/* @0x205810 cmp r1, #0 */
/* @0x205814 streq r6, [r3, #0x8] */
/* @0x205818 add r2, r2, #1 */
/* @0x20581c str r2, [r3] */
/* @0x205820 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0> */
/* @0x205824 ldr r0, [r9] */
/* @0x205828 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20582c str r10, [r9] */
/* @0x205830 str r10, [r9, #0x8] */
/* @0x205834 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205838 ldr r10, [r9, #0x4] */
/* @0x20583c sub r10, r10, #1 */
/* @0x205840 str r10, [r9, #0x4] */
/* @0x205844 cmp r10, #0 */
/* @0x205848 bne 0x20586c <_ZN9CDS_Stack4PushEP6RValue+0x200> */
/* @0x20584c ldr r0, [r9] */
/* @0x205850 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205854 mov r0, r9 */
/* @0x205858 str r10, [r9] */
/* @0x20585c str r10, [r9, #0x8] */
/* @0x205860 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x205864 mov r0, r9 */
/* @0x205868 bl 0x27d1d0 <_ZdlPv> */
/* @0x20586c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205870 mov r0, r9 */
/* @0x205874 bl 0x27d1d0 <_ZdlPv> */
/* @0x205878 b 0x205780 <_ZN9CDS_Stack4PushEP6RValue+0x114> */
/* @0x20587c mov r0, r6 */
/* @0x205880 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x205884 b 0x2056bc <_ZN9CDS_Stack4PushEP6RValue+0x50> */
/* @0x205888 andseq lr, r4, r8, asr #32 */

/* ── FUNC 0x20588c · CDS_Queue::Enqueue(RValue*) · size=548 · insn=137 */
/* @0x20588c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x205890 mov r5, r1 */
/* @0x205894 ldr r3, [r0, #0xc] */
/* @0x205898 mov r4, r0 */
/* @0x20589c ldr r1, [r0, #0x4] */
/* @0x2058a0 cmp r1, r3 */
/* @0x2058a4 bge 0x2059b4 <_ZN9CDS_Queue7EnqueueEP6RValue+0x128> */
/* @0x2058a8 ldr r7, [r4, #0x10] */
/* @0x2058ac lsl r8, r1, #4 */
/* @0x2058b0 add r6, r7, r8 */
/* @0x2058b4 ldr r2, [r6, #0xc] */
/* @0x2058b8 bic r3, r2, #-16777216 */
/* @0x2058bc cmp r3, #1 */
/* @0x2058c0 beq 0x205980 <_ZN9CDS_Queue7EnqueueEP6RValue+0xf4> */
/* @0x2058c4 cmp r3, #2 */
/* @0x2058c8 bne 0x2058f0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x64> */
/* @0x2058cc sub r2, r2, #1 */
/* @0x2058d0 bic r2, r2, #-16777216 */
/* @0x2058d4 bic r2, r2, #3 */
/* @0x2058d8 cmp r2, #0 */
/* @0x2058dc beq 0x205aa0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x214> */
/* @0x2058e0 mov r2, #0 */
/* @0x2058e4 mov r3, #5 */
/* @0x2058e8 str r2, [r6, #0x8] */
/* @0x2058ec str r3, [r6, #0xc] */
/* @0x2058f0 ldr r3, [r5, #0xc] */
/* @0x2058f4 mov r1, #0 */
/* @0x2058f8 ldr r2, [r5, #0x8] */
/* @0x2058fc str r1, [r7, r8] */
/* @0x205900 str r3, [r6, #0xc] */
/* @0x205904 ldr r3, [r5, #0xc] */
/* @0x205908 str r2, [r6, #0x8] */
/* @0x20590c bic r3, r3, #-16777216 */
/* @0x205910 cmp r3, #14 */
/* @0x205914 addls pc, pc, r3, lsl #2 */
/* @0x205918 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x20591c b 0x205970 <_ZN9CDS_Queue7EnqueueEP6RValue+0xe4> */
/* @0x205920 b 0x205a04 <_ZN9CDS_Queue7EnqueueEP6RValue+0x178> */
/* @0x205924 b 0x205a1c <_ZN9CDS_Queue7EnqueueEP6RValue+0x190> */
/* @0x205928 b 0x205958 <_ZN9CDS_Queue7EnqueueEP6RValue+0xcc> */
/* @0x20592c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205930 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205934 b 0x2059e0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x154> */
/* @0x205938 b 0x205958 <_ZN9CDS_Queue7EnqueueEP6RValue+0xcc> */
/* @0x20593c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205940 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205944 b 0x205970 <_ZN9CDS_Queue7EnqueueEP6RValue+0xe4> */
/* @0x205948 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x20594c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205950 b 0x205970 <_ZN9CDS_Queue7EnqueueEP6RValue+0xe4> */
/* @0x205954 b 0x205958 <_ZN9CDS_Queue7EnqueueEP6RValue+0xcc> */
/* @0x205958 ldr r3, [r5] */
/* @0x20595c str r3, [r7, r8] */
/* @0x205960 ldr r3, [r4, #0x4] */
/* @0x205964 add r3, r3, #1 */
/* @0x205968 str r3, [r4, #0x4] */
/* @0x20596c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x205970 ldm r5, {r2, r3} */
/* @0x205974 str r2, [r7, r8] */
/* @0x205978 str r3, [r6, #0x4] */
/* @0x20597c b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205980 ldr r9, [r7, r1, lsl #4] */
/* @0x205984 cmp r9, #0 */
/* @0x205988 beq 0x2059a8 <_ZN9CDS_Queue7EnqueueEP6RValue+0x11c> */
/* @0x20598c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205990 ldr r10, [r9, #0x4] */
/* @0x205994 sub r10, r10, #1 */
/* @0x205998 str r10, [r9, #0x4] */
/* @0x20599c cmp r10, #0 */
/* @0x2059a0 beq 0x205a48 <_ZN9CDS_Queue7EnqueueEP6RValue+0x1bc> */
/* @0x2059a4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2059a8 mov r3, #0 */
/* @0x2059ac str r3, [r7, r8] */
/* @0x2059b0 b 0x2058f0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x64> */
/* @0x2059b4 add r1, r1, #16 */
/* @0x2059b8 ldr r2, [pc, #0xec] */
/* @0x2059bc mov r3, #936 */
/* @0x2059c0 add r0, r0, #16 */
/* @0x2059c4 lsl r1, r1, #4 */
/* @0x2059c8 add r2, pc, r2 */
/* @0x2059cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2059d0 ldr r1, [r4, #0x4] */
/* @0x2059d4 add r3, r1, #16 */
/* @0x2059d8 str r3, [r4, #0xc] */
/* @0x2059dc b 0x2058a8 <_ZN9CDS_Queue7EnqueueEP6RValue+0x1c> */
/* @0x2059e0 ldr r3, [r5] */
/* @0x2059e4 str r3, [r7, r8] */
/* @0x2059e8 ldr r3, [r5] */
/* @0x2059ec cmp r3, #0 */
/* @0x2059f0 beq 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x2059f4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2059f8 ldr r1, [r5] */
/* @0x2059fc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x205a00 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205a04 ldr r3, [r5] */
/* @0x205a08 cmp r3, #0 */
/* @0x205a0c ldrne r2, [r3, #0x4] */
/* @0x205a10 addne r2, r2, #1 */
/* @0x205a14 strne r2, [r3, #0x4] */
/* @0x205a18 b 0x20595c <_ZN9CDS_Queue7EnqueueEP6RValue+0xd0> */
/* @0x205a1c ldr r3, [r5] */
/* @0x205a20 cmp r3, #0 */
/* @0x205a24 str r3, [r7, r8] */
/* @0x205a28 beq 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205a2c ldr r1, [r3, #0x8] */
/* @0x205a30 ldr r2, [r3] */
/* @0x205a34 cmp r1, #0 */
/* @0x205a38 streq r6, [r3, #0x8] */
/* @0x205a3c add r2, r2, #1 */
/* @0x205a40 str r2, [r3] */
/* @0x205a44 b 0x205960 <_ZN9CDS_Queue7EnqueueEP6RValue+0xd4> */
/* @0x205a48 ldr r0, [r9] */
/* @0x205a4c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205a50 str r10, [r9] */
/* @0x205a54 str r10, [r9, #0x8] */
/* @0x205a58 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205a5c ldr r10, [r9, #0x4] */
/* @0x205a60 sub r10, r10, #1 */
/* @0x205a64 str r10, [r9, #0x4] */
/* @0x205a68 cmp r10, #0 */
/* @0x205a6c bne 0x205a90 <_ZN9CDS_Queue7EnqueueEP6RValue+0x204> */
/* @0x205a70 ldr r0, [r9] */
/* @0x205a74 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205a78 mov r0, r9 */
/* @0x205a7c str r10, [r9] */
/* @0x205a80 str r10, [r9, #0x8] */
/* @0x205a84 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x205a88 mov r0, r9 */
/* @0x205a8c bl 0x27d1d0 <_ZdlPv> */
/* @0x205a90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205a94 mov r0, r9 */
/* @0x205a98 bl 0x27d1d0 <_ZdlPv> */
/* @0x205a9c b 0x2059a4 <_ZN9CDS_Queue7EnqueueEP6RValue+0x118> */
/* @0x205aa0 mov r0, r6 */
/* @0x205aa4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x205aa8 b 0x2058e0 <_ZN9CDS_Queue7EnqueueEP6RValue+0x54> */
/* @0x205aac andseq sp, r4, r4, lsr #28 */

/* ── FUNC 0x205ab0 · CDS_Queue::Dequeue() · size=616 · insn=154 */
/* @0x205ab0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x205ab4 mov r7, r0 */
/* @0x205ab8 ldmib r0, {r2, r9} */
/* @0x205abc sub sp, sp, #12 */
/* @0x205ac0 cmp r9, r2 */
/* @0x205ac4 beq 0x205d10 <_ZN9CDS_Queue7DequeueEv+0x260> */
/* @0x205ac8 add r6, r9, #1 */
/* @0x205acc ldr r3, [r0, #0x10] */
/* @0x205ad0 cmp r6, #16 */
/* @0x205ad4 str r6, [r0, #0x8] */
/* @0x205ad8 add r9, r3, r9, lsl #4 */
/* @0x205adc ble 0x205ba8 <_ZN9CDS_Queue7DequeueEv+0xf8> */
/* @0x205ae0 add r1, r2, r2, lsr #31 */
/* @0x205ae4 cmp r6, r1, asr #1 */
/* @0x205ae8 ble 0x205ba8 <_ZN9CDS_Queue7DequeueEv+0xf8> */
/* @0x205aec rsb r2, r6, r2 */
/* @0x205af0 cmp r2, #0 */
/* @0x205af4 ble 0x205cc0 <_ZN9CDS_Queue7DequeueEv+0x210> */
/* @0x205af8 mov r5, #0 */
/* @0x205afc mov r10, #5 */
/* @0x205b00 mov r8, r5 */
/* @0x205b04 add r4, r3, r5, lsl #4 */
/* @0x205b08 add r6, r5, r6 */
/* @0x205b0c ldr r1, [r4, #0xc] */
/* @0x205b10 add r6, r3, r6, lsl #4 */
/* @0x205b14 bic r2, r1, #-16777216 */
/* @0x205b18 cmp r2, #1 */
/* @0x205b1c beq 0x205c50 <_ZN9CDS_Queue7DequeueEv+0x1a0> */
/* @0x205b20 cmp r2, #2 */
/* @0x205b24 bne 0x205b44 <_ZN9CDS_Queue7DequeueEv+0x94> */
/* @0x205b28 sub r1, r1, #1 */
/* @0x205b2c bic r1, r1, #-16777216 */
/* @0x205b30 bic r1, r1, #3 */
/* @0x205b34 cmp r1, #0 */
/* @0x205b38 beq 0x205cd8 <_ZN9CDS_Queue7DequeueEv+0x228> */
/* @0x205b3c str r8, [r4, #0x8] */
/* @0x205b40 str r10, [r4, #0xc] */
/* @0x205b44 ldr r3, [r6, #0xc] */
/* @0x205b48 ldr r2, [r6, #0x8] */
/* @0x205b4c str r8, [r4] */
/* @0x205b50 str r3, [r4, #0xc] */
/* @0x205b54 ldr r3, [r6, #0xc] */
/* @0x205b58 str r2, [r4, #0x8] */
/* @0x205b5c bic r3, r3, #-16777216 */
/* @0x205b60 cmp r3, #14 */
/* @0x205b64 addls pc, pc, r3, lsl #2 */
/* @0x205b68 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205b6c b 0x205bdc <_ZN9CDS_Queue7DequeueEv+0x12c> */
/* @0x205b70 b 0x205c38 <_ZN9CDS_Queue7DequeueEv+0x188> */
/* @0x205b74 b 0x205c0c <_ZN9CDS_Queue7DequeueEv+0x15c> */
/* @0x205b78 b 0x205bb4 <_ZN9CDS_Queue7DequeueEv+0x104> */
/* @0x205b7c b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205b80 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205b84 b 0x205be8 <_ZN9CDS_Queue7DequeueEv+0x138> */
/* @0x205b88 b 0x205bb4 <_ZN9CDS_Queue7DequeueEv+0x104> */
/* @0x205b8c b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205b90 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205b94 b 0x205bdc <_ZN9CDS_Queue7DequeueEv+0x12c> */
/* @0x205b98 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205b9c b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205ba0 b 0x205bdc <_ZN9CDS_Queue7DequeueEv+0x12c> */
/* @0x205ba4 b 0x205bb4 <_ZN9CDS_Queue7DequeueEv+0x104> */
/* @0x205ba8 mov r0, r9 */
/* @0x205bac add sp, sp, #12 */
/* @0x205bb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x205bb4 ldr r3, [r6] */
/* @0x205bb8 str r3, [r4] */
/* @0x205bbc ldr r6, [r7, #0x8] */
/* @0x205bc0 add r5, r5, #1 */
/* @0x205bc4 ldr r2, [r7, #0x4] */
/* @0x205bc8 rsb r2, r6, r2 */
/* @0x205bcc cmp r2, r5 */
/* @0x205bd0 ble 0x205cc0 <_ZN9CDS_Queue7DequeueEv+0x210> */
/* @0x205bd4 ldr r3, [r7, #0x10] */
/* @0x205bd8 b 0x205b04 <_ZN9CDS_Queue7DequeueEv+0x54> */
/* @0x205bdc ldm r6, {r2, r3} */
/* @0x205be0 stm r4, {r2, r3} */
/* @0x205be4 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205be8 ldr r3, [r6] */
/* @0x205bec str r3, [r4] */
/* @0x205bf0 ldr r3, [r6] */
/* @0x205bf4 cmp r3, #0 */
/* @0x205bf8 beq 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205bfc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x205c00 ldr r1, [r6] */
/* @0x205c04 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x205c08 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205c0c ldr r3, [r6] */
/* @0x205c10 cmp r3, #0 */
/* @0x205c14 str r3, [r4] */
/* @0x205c18 beq 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205c1c ldr r1, [r3, #0x8] */
/* @0x205c20 ldr r2, [r3] */
/* @0x205c24 cmp r1, #0 */
/* @0x205c28 streq r4, [r3, #0x8] */
/* @0x205c2c add r2, r2, #1 */
/* @0x205c30 str r2, [r3] */
/* @0x205c34 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c> */
/* @0x205c38 ldr r3, [r6] */
/* @0x205c3c cmp r3, #0 */
/* @0x205c40 ldrne r2, [r3, #0x4] */
/* @0x205c44 addne r2, r2, #1 */
/* @0x205c48 strne r2, [r3, #0x4] */
/* @0x205c4c b 0x205bb8 <_ZN9CDS_Queue7DequeueEv+0x108> */
/* @0x205c50 ldr r11, [r3, r5, lsl #4] */
/* @0x205c54 cmp r11, #0 */
/* @0x205c58 beq 0x205c78 <_ZN9CDS_Queue7DequeueEv+0x1c8> */
/* @0x205c5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205c60 ldr r3, [r11, #0x4] */
/* @0x205c64 sub r3, r3, #1 */
/* @0x205c68 str r3, [r11, #0x4] */
/* @0x205c6c cmp r3, #0 */
/* @0x205c70 beq 0x205c80 <_ZN9CDS_Queue7DequeueEv+0x1d0> */
/* @0x205c74 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205c78 str r8, [r4] */
/* @0x205c7c b 0x205b44 <_ZN9CDS_Queue7DequeueEv+0x94> */
/* @0x205c80 ldr r0, [r11] */
/* @0x205c84 str r3, [sp, #0x4] */
/* @0x205c88 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205c8c ldr r3, [sp, #0x4] */
/* @0x205c90 str r3, [r11] */
/* @0x205c94 str r3, [r11, #0x8] */
/* @0x205c98 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205c9c ldr r3, [r11, #0x4] */
/* @0x205ca0 sub r3, r3, #1 */
/* @0x205ca4 str r3, [r11, #0x4] */
/* @0x205ca8 cmp r3, #0 */
/* @0x205cac beq 0x205ce4 <_ZN9CDS_Queue7DequeueEv+0x234> */
/* @0x205cb0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205cb4 mov r0, r11 */
/* @0x205cb8 bl 0x27d1d0 <_ZdlPv> */
/* @0x205cbc b 0x205c74 <_ZN9CDS_Queue7DequeueEv+0x1c4> */
/* @0x205cc0 mov r0, r9 */
/* @0x205cc4 mov r3, #0 */
/* @0x205cc8 str r2, [r7, #0x4] */
/* @0x205ccc str r3, [r7, #0x8] */
/* @0x205cd0 add sp, sp, #12 */
/* @0x205cd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x205cd8 mov r0, r4 */
/* @0x205cdc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x205ce0 b 0x205b3c <_ZN9CDS_Queue7DequeueEv+0x8c> */
/* @0x205ce4 ldr r0, [r11] */
/* @0x205ce8 str r3, [sp, #0x4] */
/* @0x205cec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205cf0 ldr r3, [sp, #0x4] */
/* @0x205cf4 mov r0, r11 */
/* @0x205cf8 str r3, [r11] */
/* @0x205cfc str r3, [r11, #0x8] */
/* @0x205d00 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x205d04 mov r0, r11 */
/* @0x205d08 bl 0x27d1d0 <_ZdlPv> */
/* @0x205d0c b 0x205cb0 <_ZN9CDS_Queue7DequeueEv+0x200> */
/* @0x205d10 mov r0, #0 */
/* @0x205d14 b 0x205bac <_ZN9CDS_Queue7DequeueEv+0xfc> */

/* ── FUNC 0x205d18 · CDS_List::Add(RValue*) · size=552 · insn=138 */
/* @0x205d18 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x205d1c mov r5, r1 */
/* @0x205d20 ldmib r0, {r1, r6} */
/* @0x205d24 mov r4, r0 */
/* @0x205d28 cmp r1, r6 */
/* @0x205d2c blt 0x205d64 <_ZN8CDS_List3AddEP6RValue+0x4c> */
/* @0x205d30 asr r6, r6, #3 */
/* @0x205d34 ldr r2, [pc, #0x200] */
/* @0x205d38 cmp r6, #16 */
/* @0x205d3c movlt r6, #16 */
/* @0x205d40 add r0, r0, #12 */
/* @0x205d44 add r1, r6, r1 */
/* @0x205d48 add r2, pc, r2 */
/* @0x205d4c movw r3, #0x4ef */
/* @0x205d50 lsl r1, r1, #4 */
/* @0x205d54 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x205d58 ldr r1, [r4, #0x4] */
/* @0x205d5c add r6, r1, r6 */
/* @0x205d60 str r6, [r4, #0x8] */
/* @0x205d64 ldr r7, [r4, #0xc] */
/* @0x205d68 lsl r8, r1, #4 */
/* @0x205d6c add r6, r7, r8 */
/* @0x205d70 ldr r2, [r6, #0xc] */
/* @0x205d74 bic r3, r2, #-16777216 */
/* @0x205d78 cmp r3, #1 */
/* @0x205d7c beq 0x205e3c <_ZN8CDS_List3AddEP6RValue+0x124> */
/* @0x205d80 cmp r3, #2 */
/* @0x205d84 bne 0x205dac <_ZN8CDS_List3AddEP6RValue+0x94> */
/* @0x205d88 sub r2, r2, #1 */
/* @0x205d8c bic r2, r2, #-16777216 */
/* @0x205d90 bic r2, r2, #3 */
/* @0x205d94 cmp r2, #0 */
/* @0x205d98 beq 0x205f30 <_ZN8CDS_List3AddEP6RValue+0x218> */
/* @0x205d9c mov r2, #0 */
/* @0x205da0 mov r3, #5 */
/* @0x205da4 str r2, [r6, #0x8] */
/* @0x205da8 str r3, [r6, #0xc] */
/* @0x205dac ldr r3, [r5, #0xc] */
/* @0x205db0 mov r1, #0 */
/* @0x205db4 ldr r2, [r5, #0x8] */
/* @0x205db8 str r1, [r7, r8] */
/* @0x205dbc str r3, [r6, #0xc] */
/* @0x205dc0 ldr r3, [r5, #0xc] */
/* @0x205dc4 str r2, [r6, #0x8] */
/* @0x205dc8 bic r3, r3, #-16777216 */
/* @0x205dcc cmp r3, #14 */
/* @0x205dd0 addls pc, pc, r3, lsl #2 */
/* @0x205dd4 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205dd8 b 0x205e2c <_ZN8CDS_List3AddEP6RValue+0x114> */
/* @0x205ddc b 0x205e94 <_ZN8CDS_List3AddEP6RValue+0x17c> */
/* @0x205de0 b 0x205eac <_ZN8CDS_List3AddEP6RValue+0x194> */
/* @0x205de4 b 0x205e14 <_ZN8CDS_List3AddEP6RValue+0xfc> */
/* @0x205de8 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205dec b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205df0 b 0x205e70 <_ZN8CDS_List3AddEP6RValue+0x158> */
/* @0x205df4 b 0x205e14 <_ZN8CDS_List3AddEP6RValue+0xfc> */
/* @0x205df8 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205dfc b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205e00 b 0x205e2c <_ZN8CDS_List3AddEP6RValue+0x114> */
/* @0x205e04 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205e08 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205e0c b 0x205e2c <_ZN8CDS_List3AddEP6RValue+0x114> */
/* @0x205e10 b 0x205e14 <_ZN8CDS_List3AddEP6RValue+0xfc> */
/* @0x205e14 ldr r3, [r5] */
/* @0x205e18 str r3, [r7, r8] */
/* @0x205e1c ldr r3, [r4, #0x4] */
/* @0x205e20 add r3, r3, #1 */
/* @0x205e24 str r3, [r4, #0x4] */
/* @0x205e28 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x205e2c ldm r5, {r2, r3} */
/* @0x205e30 str r2, [r7, r8] */
/* @0x205e34 str r3, [r6, #0x4] */
/* @0x205e38 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205e3c ldr r9, [r7, r1, lsl #4] */
/* @0x205e40 cmp r9, #0 */
/* @0x205e44 beq 0x205e64 <_ZN8CDS_List3AddEP6RValue+0x14c> */
/* @0x205e48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205e4c ldr r10, [r9, #0x4] */
/* @0x205e50 sub r10, r10, #1 */
/* @0x205e54 str r10, [r9, #0x4] */
/* @0x205e58 cmp r10, #0 */
/* @0x205e5c beq 0x205ed8 <_ZN8CDS_List3AddEP6RValue+0x1c0> */
/* @0x205e60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205e64 mov r3, #0 */
/* @0x205e68 str r3, [r7, r8] */
/* @0x205e6c b 0x205dac <_ZN8CDS_List3AddEP6RValue+0x94> */
/* @0x205e70 ldr r3, [r5] */
/* @0x205e74 str r3, [r7, r8] */
/* @0x205e78 ldr r3, [r5] */
/* @0x205e7c cmp r3, #0 */
/* @0x205e80 beq 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205e84 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x205e88 ldr r1, [r5] */
/* @0x205e8c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x205e90 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205e94 ldr r3, [r5] */
/* @0x205e98 cmp r3, #0 */
/* @0x205e9c ldrne r2, [r3, #0x4] */
/* @0x205ea0 addne r2, r2, #1 */
/* @0x205ea4 strne r2, [r3, #0x4] */
/* @0x205ea8 b 0x205e18 <_ZN8CDS_List3AddEP6RValue+0x100> */
/* @0x205eac ldr r3, [r5] */
/* @0x205eb0 cmp r3, #0 */
/* @0x205eb4 str r3, [r7, r8] */
/* @0x205eb8 beq 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205ebc ldr r1, [r3, #0x8] */
/* @0x205ec0 ldr r2, [r3] */
/* @0x205ec4 cmp r1, #0 */
/* @0x205ec8 streq r6, [r3, #0x8] */
/* @0x205ecc add r2, r2, #1 */
/* @0x205ed0 str r2, [r3] */
/* @0x205ed4 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104> */
/* @0x205ed8 ldr r0, [r9] */
/* @0x205edc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205ee0 str r10, [r9] */
/* @0x205ee4 str r10, [r9, #0x8] */
/* @0x205ee8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x205eec ldr r10, [r9, #0x4] */
/* @0x205ef0 sub r10, r10, #1 */
/* @0x205ef4 str r10, [r9, #0x4] */
/* @0x205ef8 cmp r10, #0 */
/* @0x205efc bne 0x205f20 <_ZN8CDS_List3AddEP6RValue+0x208> */
/* @0x205f00 ldr r0, [r9] */
/* @0x205f04 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x205f08 mov r0, r9 */
/* @0x205f0c str r10, [r9] */
/* @0x205f10 str r10, [r9, #0x8] */
/* @0x205f14 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x205f18 mov r0, r9 */
/* @0x205f1c bl 0x27d1d0 <_ZdlPv> */
/* @0x205f20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x205f24 mov r0, r9 */
/* @0x205f28 bl 0x27d1d0 <_ZdlPv> */
/* @0x205f2c b 0x205e60 <_ZN8CDS_List3AddEP6RValue+0x148> */
/* @0x205f30 mov r0, r6 */
/* @0x205f34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x205f38 b 0x205d9c <_ZN8CDS_List3AddEP6RValue+0x84> */
/* @0x205f3c andseq sp, r4, r4, lsr #21 */

/* ── FUNC 0x205f40 · CDS_List::Insert(int, RValue*) · size=384 · insn=96 */
/* @0x205f40 push {r4, r5, r6, r7, r8, lr} */
/* @0x205f44 subs r5, r1, #0 */
/* @0x205f48 mov r4, r0 */
/* @0x205f4c mov r6, r2 */
/* @0x205f50 poplt {r4, r5, r6, r7, r8, pc} */
/* @0x205f54 ldr r2, [r0, #0x4] */
/* @0x205f58 cmp r5, r2 */
/* @0x205f5c popgt {r4, r5, r6, r7, r8, pc} */
/* @0x205f60 ldr r3, [r0, #0x8] */
/* @0x205f64 cmp r2, r3 */
/* @0x205f68 bge 0x206090 <_ZN8CDS_List6InsertEiP6RValue+0x150> */
/* @0x205f6c ldr r8, [r4, #0xc] */
/* @0x205f70 rsb r2, r5, r2 */
/* @0x205f74 add r7, r8, r5, lsl #4 */
/* @0x205f78 lsl r2, r2, #4 */
/* @0x205f7c add r0, r7, #16 */
/* @0x205f80 mov r1, r7 */
/* @0x205f84 bl 0xb6694 <memmove@plt> */
/* @0x205f88 mov r1, #0 */
/* @0x205f8c mov r2, #16 */
/* @0x205f90 mov r0, r7 */
/* @0x205f94 bl 0xb65b0 <memset@plt> */
/* @0x205f98 ldr r3, [r6, #0xc] */
/* @0x205f9c ldr r2, [r6, #0x8] */
/* @0x205fa0 mov r1, #0 */
/* @0x205fa4 str r1, [r8, r5, lsl #4] */
/* @0x205fa8 str r3, [r7, #0xc] */
/* @0x205fac ldr r3, [r6, #0xc] */
/* @0x205fb0 str r2, [r7, #0x8] */
/* @0x205fb4 bic r3, r3, #-16777216 */
/* @0x205fb8 cmp r3, #14 */
/* @0x205fbc addls pc, pc, r3, lsl #2 */
/* @0x205fc0 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205fc4 b 0x206018 <_ZN8CDS_List6InsertEiP6RValue+0xd8> */
/* @0x205fc8 b 0x206078 <_ZN8CDS_List6InsertEiP6RValue+0x138> */
/* @0x205fcc b 0x20604c <_ZN8CDS_List6InsertEiP6RValue+0x10c> */
/* @0x205fd0 b 0x206000 <_ZN8CDS_List6InsertEiP6RValue+0xc0> */
/* @0x205fd4 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205fd8 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205fdc b 0x206028 <_ZN8CDS_List6InsertEiP6RValue+0xe8> */
/* @0x205fe0 b 0x206000 <_ZN8CDS_List6InsertEiP6RValue+0xc0> */
/* @0x205fe4 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205fe8 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205fec b 0x206018 <_ZN8CDS_List6InsertEiP6RValue+0xd8> */
/* @0x205ff0 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205ff4 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x205ff8 b 0x206018 <_ZN8CDS_List6InsertEiP6RValue+0xd8> */
/* @0x205ffc b 0x206000 <_ZN8CDS_List6InsertEiP6RValue+0xc0> */
/* @0x206000 ldr r3, [r6] */
/* @0x206004 str r3, [r8, r5, lsl #4] */
/* @0x206008 ldr r3, [r4, #0x4] */
/* @0x20600c add r3, r3, #1 */
/* @0x206010 str r3, [r4, #0x4] */
/* @0x206014 pop {r4, r5, r6, r7, r8, pc} */
/* @0x206018 ldm r6, {r2, r3} */
/* @0x20601c str r2, [r8, r5, lsl #4] */
/* @0x206020 str r3, [r7, #0x4] */
/* @0x206024 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x206028 ldr r3, [r6] */
/* @0x20602c str r3, [r8, r5, lsl #4] */
/* @0x206030 ldr r3, [r6] */
/* @0x206034 cmp r3, #0 */
/* @0x206038 beq 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x20603c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x206040 ldr r1, [r6] */
/* @0x206044 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x206048 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x20604c ldr r3, [r6] */
/* @0x206050 cmp r3, #0 */
/* @0x206054 str r3, [r8, r5, lsl #4] */
/* @0x206058 beq 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x20605c ldr r1, [r3, #0x8] */
/* @0x206060 ldr r2, [r3] */
/* @0x206064 cmp r1, #0 */
/* @0x206068 streq r7, [r3, #0x8] */
/* @0x20606c add r2, r2, #1 */
/* @0x206070 str r2, [r3] */
/* @0x206074 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8> */
/* @0x206078 ldr r3, [r6] */
/* @0x20607c cmp r3, #0 */
/* @0x206080 ldrne r2, [r3, #0x4] */
/* @0x206084 addne r2, r2, #1 */
/* @0x206088 strne r2, [r3, #0x4] */
/* @0x20608c b 0x206004 <_ZN8CDS_List6InsertEiP6RValue+0xc4> */
/* @0x206090 add r1, r2, #16 */
/* @0x206094 ldr r2, [pc, #0x20] */
/* @0x206098 mov r3, #1296 */
/* @0x20609c add r0, r0, #12 */
/* @0x2060a0 add r2, pc, r2 */
/* @0x2060a4 lsl r1, r1, #4 */
/* @0x2060a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2060ac ldr r2, [r4, #0x4] */
/* @0x2060b0 add r3, r2, #16 */
/* @0x2060b4 str r3, [r4, #0x8] */
/* @0x2060b8 b 0x205f6c <_ZN8CDS_List6InsertEiP6RValue+0x2c> */
/* @0x2060bc andseq sp, r4, r12, asr #14 */

/* ── FUNC 0x2060c0 · CDS_List::Set(int, RValue*, RValue*) · size=1104 · insn=276 */
/* @0x2060c0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2060c4 subs r6, r1, #0 */
/* @0x2060c8 mov r5, r0 */
/* @0x2060cc mov r8, r2 */
/* @0x2060d0 mov r4, r3 */
/* @0x2060d4 blt 0x2064f8 <_ZN8CDS_List3SetEiP6RValueS1_+0x438> */
/* @0x2060d8 ldr r1, [r0, #0x4] */
/* @0x2060dc ldr r3, [r0, #0x8] */
/* @0x2060e0 cmp r6, r1 */
/* @0x2060e4 addge r1, r6, #1 */
/* @0x2060e8 strge r1, [r0, #0x4] */
/* @0x2060ec cmp r3, r1 */
/* @0x2060f0 ble 0x20629c <_ZN8CDS_List3SetEiP6RValueS1_+0x1dc> */
/* @0x2060f4 ldr r7, [r5, #0xc] */
/* @0x2060f8 cmp r4, #0 */
/* @0x2060fc add r5, r7, r6, lsl #4 */
/* @0x206100 beq 0x2062d4 <_ZN8CDS_List3SetEiP6RValueS1_+0x214> */
/* @0x206104 ldr r2, [r4, #0xc] */
/* @0x206108 bic r3, r2, #-16777216 */
/* @0x20610c cmp r3, #1 */
/* @0x206110 beq 0x2062f0 <_ZN8CDS_List3SetEiP6RValueS1_+0x230> */
/* @0x206114 cmp r3, #2 */
/* @0x206118 bne 0x206140 <_ZN8CDS_List3SetEiP6RValueS1_+0x80> */
/* @0x20611c sub r2, r2, #1 */
/* @0x206120 bic r2, r2, #-16777216 */
/* @0x206124 bic r2, r2, #3 */
/* @0x206128 cmp r2, #0 */
/* @0x20612c beq 0x2064e0 <_ZN8CDS_List3SetEiP6RValueS1_+0x420> */
/* @0x206130 mov r2, #0 */
/* @0x206134 mov r3, #5 */
/* @0x206138 str r2, [r4, #0x8] */
/* @0x20613c str r3, [r4, #0xc] */
/* @0x206140 ldr r2, [r5, #0xc] */
/* @0x206144 mov r1, #0 */
/* @0x206148 ldr r3, [r5, #0x8] */
/* @0x20614c str r1, [r4] */
/* @0x206150 str r2, [r4, #0xc] */
/* @0x206154 ldr r2, [r5, #0xc] */
/* @0x206158 str r3, [r4, #0x8] */
/* @0x20615c bic r3, r2, #-16777216 */
/* @0x206160 cmp r3, #14 */
/* @0x206164 addls pc, pc, r3, lsl #2 */
/* @0x206168 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x20616c b 0x206428 <_ZN8CDS_List3SetEiP6RValueS1_+0x368> */
/* @0x206170 b 0x206240 <_ZN8CDS_List3SetEiP6RValueS1_+0x180> */
/* @0x206174 b 0x206438 <_ZN8CDS_List3SetEiP6RValueS1_+0x378> */
/* @0x206178 b 0x2061a8 <_ZN8CDS_List3SetEiP6RValueS1_+0xe8> */
/* @0x20617c b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x206180 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x206184 b 0x2063f4 <_ZN8CDS_List3SetEiP6RValueS1_+0x334> */
/* @0x206188 b 0x2061a8 <_ZN8CDS_List3SetEiP6RValueS1_+0xe8> */
/* @0x20618c b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x206190 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x206194 b 0x206418 <_ZN8CDS_List3SetEiP6RValueS1_+0x358> */
/* @0x206198 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x20619c b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x2061a0 b 0x206428 <_ZN8CDS_List3SetEiP6RValueS1_+0x368> */
/* @0x2061a4 b 0x2061a8 <_ZN8CDS_List3SetEiP6RValueS1_+0xe8> */
/* @0x2061a8 ldr r3, [r7, r6, lsl #4] */
/* @0x2061ac str r3, [r4] */
/* @0x2061b0 ldr r3, [r8, #0xc] */
/* @0x2061b4 mov r1, #0 */
/* @0x2061b8 ldr r2, [r8, #0x8] */
/* @0x2061bc str r1, [r7, r6, lsl #4] */
/* @0x2061c0 str r3, [r5, #0xc] */
/* @0x2061c4 ldr r3, [r8, #0xc] */
/* @0x2061c8 str r2, [r5, #0x8] */
/* @0x2061cc bic r3, r3, #-16777216 */
/* @0x2061d0 cmp r3, #14 */
/* @0x2061d4 addls pc, pc, r3, lsl #2 */
/* @0x2061d8 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x2061dc b 0x206228 <_ZN8CDS_List3SetEiP6RValueS1_+0x168> */
/* @0x2061e0 b 0x20637c <_ZN8CDS_List3SetEiP6RValueS1_+0x2bc> */
/* @0x2061e4 b 0x20634c <_ZN8CDS_List3SetEiP6RValueS1_+0x28c> */
/* @0x2061e8 b 0x206218 <_ZN8CDS_List3SetEiP6RValueS1_+0x158> */
/* @0x2061ec b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x2061f0 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x2061f4 b 0x206324 <_ZN8CDS_List3SetEiP6RValueS1_+0x264> */
/* @0x2061f8 b 0x206218 <_ZN8CDS_List3SetEiP6RValueS1_+0x158> */
/* @0x2061fc b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x206200 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x206204 b 0x206228 <_ZN8CDS_List3SetEiP6RValueS1_+0x168> */
/* @0x206208 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x20620c b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x206210 b 0x206228 <_ZN8CDS_List3SetEiP6RValueS1_+0x168> */
/* @0x206214 b 0x206218 <_ZN8CDS_List3SetEiP6RValueS1_+0x158> */
/* @0x206218 ldr r3, [r8] */
/* @0x20621c mov r0, r4 */
/* @0x206220 str r3, [r7, r6, lsl #4] */
/* @0x206224 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x206228 ldr r2, [r8] */
/* @0x20622c mov r0, r4 */
/* @0x206230 ldr r3, [r8, #0x4] */
/* @0x206234 str r2, [r7, r6, lsl #4] */
/* @0x206238 str r3, [r5, #0x4] */
/* @0x20623c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x206240 ldr r1, [r7, r6, lsl #4] */
/* @0x206244 cmp r1, #0 */
/* @0x206248 ldrne r3, [r1, #0x4] */
/* @0x20624c addne r3, r3, #1 */
/* @0x206250 strne r3, [r1, #0x4] */
/* @0x206254 ldrne r2, [r5, #0xc] */
/* @0x206258 str r1, [r4] */
/* @0x20625c bicne r3, r2, #-16777216 */
/* @0x206260 cmp r3, #1 */
/* @0x206264 bne 0x2062e4 <_ZN8CDS_List3SetEiP6RValueS1_+0x224> */
/* @0x206268 ldr r9, [r7, r6, lsl #4] */
/* @0x20626c cmp r9, #0 */
/* @0x206270 beq 0x206290 <_ZN8CDS_List3SetEiP6RValueS1_+0x1d0> */
/* @0x206274 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206278 ldr r10, [r9, #0x4] */
/* @0x20627c sub r10, r10, #1 */
/* @0x206280 str r10, [r9, #0x4] */
/* @0x206284 cmp r10, #0 */
/* @0x206288 beq 0x20639c <_ZN8CDS_List3SetEiP6RValueS1_+0x2dc> */
/* @0x20628c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206290 mov r3, #0 */
/* @0x206294 str r3, [r7, r6, lsl #4] */
/* @0x206298 b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0> */
/* @0x20629c add r1, r1, #16 */
/* @0x2062a0 ldr r2, [pc, #0x264] */
/* @0x2062a4 movw r3, #0x52b */
/* @0x2062a8 add r0, r0, #12 */
/* @0x2062ac add r2, pc, r2 */
/* @0x2062b0 lsl r1, r1, #4 */
/* @0x2062b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2062b8 ldr r3, [r5, #0x4] */
/* @0x2062bc ldr r7, [r5, #0xc] */
/* @0x2062c0 cmp r4, #0 */
/* @0x2062c4 add r3, r3, #16 */
/* @0x2062c8 str r3, [r5, #0x8] */
/* @0x2062cc add r5, r7, r6, lsl #4 */
/* @0x2062d0 bne 0x206104 <_ZN8CDS_List3SetEiP6RValueS1_+0x44> */
/* @0x2062d4 ldr r2, [r5, #0xc] */
/* @0x2062d8 bic r3, r2, #-16777216 */
/* @0x2062dc cmp r3, #1 */
/* @0x2062e0 beq 0x206268 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a8> */
/* @0x2062e4 cmp r3, #2 */
/* @0x2062e8 beq 0x206460 <_ZN8CDS_List3SetEiP6RValueS1_+0x3a0> */
/* @0x2062ec b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0> */
/* @0x2062f0 ldr r9, [r4] */
/* @0x2062f4 cmp r9, #0 */
/* @0x2062f8 beq 0x206318 <_ZN8CDS_List3SetEiP6RValueS1_+0x258> */
/* @0x2062fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206300 ldr r10, [r9, #0x4] */
/* @0x206304 sub r10, r10, #1 */
/* @0x206308 str r10, [r9, #0x4] */
/* @0x20630c cmp r10, #0 */
/* @0x206310 beq 0x206488 <_ZN8CDS_List3SetEiP6RValueS1_+0x3c8> */
/* @0x206314 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206318 mov r3, #0 */
/* @0x20631c str r3, [r4] */
/* @0x206320 b 0x206140 <_ZN8CDS_List3SetEiP6RValueS1_+0x80> */
/* @0x206324 ldr r3, [r8] */
/* @0x206328 str r3, [r7, r6, lsl #4] */
/* @0x20632c ldr r3, [r8] */
/* @0x206330 cmp r3, #0 */
/* @0x206334 beq 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x206338 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20633c ldr r1, [r8] */
/* @0x206340 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x206344 mov r0, r4 */
/* @0x206348 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20634c ldr r3, [r8] */
/* @0x206350 cmp r3, #0 */
/* @0x206354 str r3, [r7, r6, lsl #4] */
/* @0x206358 beq 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4> */
/* @0x20635c ldr r1, [r3, #0x8] */
/* @0x206360 ldr r2, [r3] */
/* @0x206364 cmp r1, #0 */
/* @0x206368 add r2, r2, #1 */
/* @0x20636c str r2, [r3] */
/* @0x206370 beq 0x206500 <_ZN8CDS_List3SetEiP6RValueS1_+0x440> */
/* @0x206374 mov r0, r4 */
/* @0x206378 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20637c ldr r3, [r8] */
/* @0x206380 mov r0, r4 */
/* @0x206384 cmp r3, #0 */
/* @0x206388 ldrne r2, [r3, #0x4] */
/* @0x20638c addne r2, r2, #1 */
/* @0x206390 strne r2, [r3, #0x4] */
/* @0x206394 str r3, [r7, r6, lsl #4] */
/* @0x206398 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20639c ldr r0, [r9] */
/* @0x2063a0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2063a4 str r10, [r9] */
/* @0x2063a8 str r10, [r9, #0x8] */
/* @0x2063ac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2063b0 ldr r10, [r9, #0x4] */
/* @0x2063b4 sub r10, r10, #1 */
/* @0x2063b8 str r10, [r9, #0x4] */
/* @0x2063bc cmp r10, #0 */
/* @0x2063c0 bne 0x2063e4 <_ZN8CDS_List3SetEiP6RValueS1_+0x324> */
/* @0x2063c4 ldr r0, [r9] */
/* @0x2063c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2063cc mov r0, r9 */
/* @0x2063d0 str r10, [r9] */
/* @0x2063d4 str r10, [r9, #0x8] */
/* @0x2063d8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2063dc mov r0, r9 */
/* @0x2063e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2063e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2063e8 mov r0, r9 */
/* @0x2063ec bl 0x27d1d0 <_ZdlPv> */
/* @0x2063f0 b 0x20628c <_ZN8CDS_List3SetEiP6RValueS1_+0x1cc> */
/* @0x2063f4 ldr r3, [r7, r6, lsl #4] */
/* @0x2063f8 str r3, [r4] */
/* @0x2063fc ldr r3, [r7, r6, lsl #4] */
/* @0x206400 cmp r3, #0 */
/* @0x206404 beq 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0> */
/* @0x206408 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20640c ldr r1, [r7, r6, lsl #4] */
/* @0x206410 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x206414 b 0x2062d4 <_ZN8CDS_List3SetEiP6RValueS1_+0x214> */
/* @0x206418 ldr r2, [r7, r6, lsl #4] */
/* @0x20641c ldr r3, [r5, #0x4] */
/* @0x206420 stm r4, {r2, r3} */
/* @0x206424 b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0> */
/* @0x206428 ldr r0, [r7, r6, lsl #4] */
/* @0x20642c ldr r1, [r5, #0x4] */
/* @0x206430 stm r4, {r0, r1} */
/* @0x206434 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0> */
/* @0x206438 ldr r3, [r7, r6, lsl #4] */
/* @0x20643c cmp r3, #0 */
/* @0x206440 str r3, [r4] */
/* @0x206444 beq 0x206460 <_ZN8CDS_List3SetEiP6RValueS1_+0x3a0> */
/* @0x206448 ldr r0, [r3, #0x8] */
/* @0x20644c ldr r1, [r3] */
/* @0x206450 cmp r0, #0 */
/* @0x206454 streq r4, [r3, #0x8] */
/* @0x206458 add r1, r1, #1 */
/* @0x20645c str r1, [r3] */
/* @0x206460 sub r2, r2, #1 */
/* @0x206464 bic r2, r2, #-16777216 */
/* @0x206468 bic r2, r2, #3 */
/* @0x20646c cmp r2, #0 */
/* @0x206470 beq 0x2064ec <_ZN8CDS_List3SetEiP6RValueS1_+0x42c> */
/* @0x206474 mov r2, #0 */
/* @0x206478 mov r3, #5 */
/* @0x20647c str r2, [r5, #0x8] */
/* @0x206480 str r3, [r5, #0xc] */
/* @0x206484 b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0> */
/* @0x206488 ldr r0, [r9] */
/* @0x20648c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206490 str r10, [r9] */
/* @0x206494 str r10, [r9, #0x8] */
/* @0x206498 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20649c ldr r10, [r9, #0x4] */
/* @0x2064a0 sub r10, r10, #1 */
/* @0x2064a4 str r10, [r9, #0x4] */
/* @0x2064a8 cmp r10, #0 */
/* @0x2064ac bne 0x2064d0 <_ZN8CDS_List3SetEiP6RValueS1_+0x410> */
/* @0x2064b0 ldr r0, [r9] */
/* @0x2064b4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2064b8 mov r0, r9 */
/* @0x2064bc str r10, [r9] */
/* @0x2064c0 str r10, [r9, #0x8] */
/* @0x2064c4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2064c8 mov r0, r9 */
/* @0x2064cc bl 0x27d1d0 <_ZdlPv> */
/* @0x2064d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2064d4 mov r0, r9 */
/* @0x2064d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2064dc b 0x206314 <_ZN8CDS_List3SetEiP6RValueS1_+0x254> */
/* @0x2064e0 mov r0, r4 */
/* @0x2064e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2064e8 b 0x206130 <_ZN8CDS_List3SetEiP6RValueS1_+0x70> */
/* @0x2064ec mov r0, r5 */
/* @0x2064f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2064f4 b 0x206474 <_ZN8CDS_List3SetEiP6RValueS1_+0x3b4> */
/* @0x2064f8 mov r0, #0 */
/* @0x2064fc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x206500 str r5, [r3, #0x8] */
/* @0x206504 mov r0, r4 */
/* @0x206508 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x20650c andseq sp, r4, r0, asr #10 */

/* ── FUNC 0x206510 · CDS_Priority::Add(RValue*, RValue*) · size=1044 · insn=261 */
/* @0x206510 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x206514 mov r6, r1 */
/* @0x206518 ldr r3, [r0, #0x8] */
/* @0x20651c mov r4, r0 */
/* @0x206520 ldr r1, [r0, #0x4] */
/* @0x206524 mov r5, r2 */
/* @0x206528 cmp r1, r3 */
/* @0x20652c bge 0x206738 <_ZN12CDS_Priority3AddEP6RValueS1_+0x228> */
/* @0x206530 ldr r8, [r4, #0xc] */
/* @0x206534 lsl r9, r1, #4 */
/* @0x206538 add r7, r8, r9 */
/* @0x20653c ldr r2, [r7, #0xc] */
/* @0x206540 bic r3, r2, #-16777216 */
/* @0x206544 cmp r3, #1 */
/* @0x206548 beq 0x2066d0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1c0> */
/* @0x20654c cmp r3, #2 */
/* @0x206550 bne 0x206578 <_ZN12CDS_Priority3AddEP6RValueS1_+0x68> */
/* @0x206554 sub r2, r2, #1 */
/* @0x206558 bic r2, r2, #-16777216 */
/* @0x20655c bic r2, r2, #3 */
/* @0x206560 cmp r2, #0 */
/* @0x206564 beq 0x206908 <_ZN12CDS_Priority3AddEP6RValueS1_+0x3f8> */
/* @0x206568 mov r2, #0 */
/* @0x20656c mov r3, #5 */
/* @0x206570 str r2, [r7, #0x8] */
/* @0x206574 str r3, [r7, #0xc] */
/* @0x206578 ldr r3, [r6, #0xc] */
/* @0x20657c mov r1, #0 */
/* @0x206580 ldr r2, [r6, #0x8] */
/* @0x206584 str r1, [r8, r9] */
/* @0x206588 str r3, [r7, #0xc] */
/* @0x20658c ldr r3, [r6, #0xc] */
/* @0x206590 str r2, [r7, #0x8] */
/* @0x206594 bic r3, r3, #-16777216 */
/* @0x206598 cmp r3, #14 */
/* @0x20659c addls pc, pc, r3, lsl #2 */
/* @0x2065a0 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065a4 b 0x2066b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1a0> */
/* @0x2065a8 b 0x2067b4 <_ZN12CDS_Priority3AddEP6RValueS1_+0x2a4> */
/* @0x2065ac b 0x2067cc <_ZN12CDS_Priority3AddEP6RValueS1_+0x2bc> */
/* @0x2065b0 b 0x2065e0 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd0> */
/* @0x2065b4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065b8 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065bc b 0x2067f8 <_ZN12CDS_Priority3AddEP6RValueS1_+0x2e8> */
/* @0x2065c0 b 0x2065e0 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd0> */
/* @0x2065c4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065c8 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065cc b 0x2066b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1a0> */
/* @0x2065d0 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065d4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2065d8 b 0x2066b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1a0> */
/* @0x2065dc b 0x2065e0 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd0> */
/* @0x2065e0 ldr r3, [r6] */
/* @0x2065e4 str r3, [r8, r9] */
/* @0x2065e8 ldr r8, [r4, #0x4] */
/* @0x2065ec ldr r7, [r4, #0x14] */
/* @0x2065f0 add r6, r7, r8, lsl #4 */
/* @0x2065f4 ldr r2, [r6, #0xc] */
/* @0x2065f8 bic r3, r2, #-16777216 */
/* @0x2065fc cmp r3, #1 */
/* @0x206600 beq 0x206704 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1f4> */
/* @0x206604 cmp r3, #2 */
/* @0x206608 bne 0x206630 <_ZN12CDS_Priority3AddEP6RValueS1_+0x120> */
/* @0x20660c sub r2, r2, #1 */
/* @0x206610 bic r2, r2, #-16777216 */
/* @0x206614 bic r2, r2, #3 */
/* @0x206618 cmp r2, #0 */
/* @0x20661c beq 0x206914 <_ZN12CDS_Priority3AddEP6RValueS1_+0x404> */
/* @0x206620 mov r2, #0 */
/* @0x206624 mov r3, #5 */
/* @0x206628 str r2, [r6, #0x8] */
/* @0x20662c str r3, [r6, #0xc] */
/* @0x206630 ldr r3, [r5, #0xc] */
/* @0x206634 mov r1, #0 */
/* @0x206638 ldr r2, [r5, #0x8] */
/* @0x20663c str r1, [r7, r8, lsl #4] */
/* @0x206640 str r3, [r6, #0xc] */
/* @0x206644 ldr r3, [r5, #0xc] */
/* @0x206648 str r2, [r6, #0x8] */
/* @0x20664c bic r3, r3, #-16777216 */
/* @0x206650 cmp r3, #14 */
/* @0x206654 addls pc, pc, r3, lsl #2 */
/* @0x206658 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x20665c b 0x2066c0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1b0> */
/* @0x206660 b 0x206840 <_ZN12CDS_Priority3AddEP6RValueS1_+0x330> */
/* @0x206664 b 0x206788 <_ZN12CDS_Priority3AddEP6RValueS1_+0x278> */
/* @0x206668 b 0x206698 <_ZN12CDS_Priority3AddEP6RValueS1_+0x188> */
/* @0x20666c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206670 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206674 b 0x20681c <_ZN12CDS_Priority3AddEP6RValueS1_+0x30c> */
/* @0x206678 b 0x206698 <_ZN12CDS_Priority3AddEP6RValueS1_+0x188> */
/* @0x20667c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206680 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206684 b 0x2066c0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1b0> */
/* @0x206688 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x20668c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206690 b 0x2066c0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1b0> */
/* @0x206694 b 0x206698 <_ZN12CDS_Priority3AddEP6RValueS1_+0x188> */
/* @0x206698 ldr r3, [r5] */
/* @0x20669c str r3, [r7, r8, lsl #4] */
/* @0x2066a0 ldr r3, [r4, #0x4] */
/* @0x2066a4 add r3, r3, #1 */
/* @0x2066a8 str r3, [r4, #0x4] */
/* @0x2066ac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2066b0 ldm r6, {r2, r3} */
/* @0x2066b4 str r2, [r8, r9] */
/* @0x2066b8 str r3, [r7, #0x4] */
/* @0x2066bc b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2066c0 ldm r5, {r2, r3} */
/* @0x2066c4 str r2, [r7, r8, lsl #4] */
/* @0x2066c8 str r3, [r6, #0x4] */
/* @0x2066cc b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x2066d0 ldr r10, [r8, r1, lsl #4] */
/* @0x2066d4 cmp r10, #0 */
/* @0x2066d8 beq 0x2066f8 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1e8> */
/* @0x2066dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2066e0 ldr r11, [r10, #0x4] */
/* @0x2066e4 sub r11, r11, #1 */
/* @0x2066e8 str r11, [r10, #0x4] */
/* @0x2066ec cmp r11, #0 */
/* @0x2066f0 beq 0x206858 <_ZN12CDS_Priority3AddEP6RValueS1_+0x348> */
/* @0x2066f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2066f8 mov r3, #0 */
/* @0x2066fc str r3, [r8, r9] */
/* @0x206700 b 0x206578 <_ZN12CDS_Priority3AddEP6RValueS1_+0x68> */
/* @0x206704 ldr r9, [r7, r8, lsl #4] */
/* @0x206708 cmp r9, #0 */
/* @0x20670c beq 0x20672c <_ZN12CDS_Priority3AddEP6RValueS1_+0x21c> */
/* @0x206710 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206714 ldr r10, [r9, #0x4] */
/* @0x206718 sub r10, r10, #1 */
/* @0x20671c str r10, [r9, #0x4] */
/* @0x206720 cmp r10, #0 */
/* @0x206724 beq 0x2068b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x3a0> */
/* @0x206728 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20672c mov r3, #0 */
/* @0x206730 str r3, [r7, r8, lsl #4] */
/* @0x206734 b 0x206630 <_ZN12CDS_Priority3AddEP6RValueS1_+0x120> */
/* @0x206738 ldr r7, [pc, #0x1e0] */
/* @0x20673c add r1, r1, #16 */
/* @0x206740 add r0, r0, #12 */
/* @0x206744 movw r3, #0xa5b */
/* @0x206748 add r7, pc, r7 */
/* @0x20674c lsl r1, r1, #4 */
/* @0x206750 mov r2, r7 */
/* @0x206754 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x206758 ldr r1, [r4, #0x4] */
/* @0x20675c movw r3, #0xa5d */
/* @0x206760 mov r2, r7 */
/* @0x206764 add r1, r1, #16 */
/* @0x206768 add r0, r4, #20 */
/* @0x20676c str r1, [r4, #0x8] */
/* @0x206770 lsl r1, r1, #4 */
/* @0x206774 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x206778 ldr r1, [r4, #0x4] */
/* @0x20677c add r3, r1, #16 */
/* @0x206780 str r3, [r4, #0x10] */
/* @0x206784 b 0x206530 <_ZN12CDS_Priority3AddEP6RValueS1_+0x20> */
/* @0x206788 ldr r3, [r5] */
/* @0x20678c cmp r3, #0 */
/* @0x206790 str r3, [r7, r8, lsl #4] */
/* @0x206794 beq 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206798 ldr r1, [r3, #0x8] */
/* @0x20679c ldr r2, [r3] */
/* @0x2067a0 cmp r1, #0 */
/* @0x2067a4 streq r6, [r3, #0x8] */
/* @0x2067a8 add r2, r2, #1 */
/* @0x2067ac str r2, [r3] */
/* @0x2067b0 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x2067b4 ldr r3, [r6] */
/* @0x2067b8 cmp r3, #0 */
/* @0x2067bc ldrne r2, [r3, #0x4] */
/* @0x2067c0 addne r2, r2, #1 */
/* @0x2067c4 strne r2, [r3, #0x4] */
/* @0x2067c8 b 0x2065e4 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd4> */
/* @0x2067cc ldr r3, [r6] */
/* @0x2067d0 cmp r3, #0 */
/* @0x2067d4 str r3, [r8, r9] */
/* @0x2067d8 beq 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2067dc ldr r1, [r3, #0x8] */
/* @0x2067e0 ldr r2, [r3] */
/* @0x2067e4 cmp r1, #0 */
/* @0x2067e8 streq r7, [r3, #0x8] */
/* @0x2067ec add r2, r2, #1 */
/* @0x2067f0 str r2, [r3] */
/* @0x2067f4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x2067f8 ldr r3, [r6] */
/* @0x2067fc str r3, [r8, r9] */
/* @0x206800 ldr r3, [r6] */
/* @0x206804 cmp r3, #0 */
/* @0x206808 beq 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x20680c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x206810 ldr r1, [r6] */
/* @0x206814 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x206818 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8> */
/* @0x20681c ldr r3, [r5] */
/* @0x206820 str r3, [r7, r8, lsl #4] */
/* @0x206824 ldr r3, [r5] */
/* @0x206828 cmp r3, #0 */
/* @0x20682c beq 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206830 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x206834 ldr r1, [r5] */
/* @0x206838 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20683c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190> */
/* @0x206840 ldr r3, [r5] */
/* @0x206844 cmp r3, #0 */
/* @0x206848 ldrne r2, [r3, #0x4] */
/* @0x20684c addne r2, r2, #1 */
/* @0x206850 strne r2, [r3, #0x4] */
/* @0x206854 b 0x20669c <_ZN12CDS_Priority3AddEP6RValueS1_+0x18c> */
/* @0x206858 ldr r0, [r10] */
/* @0x20685c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206860 str r11, [r10] */
/* @0x206864 str r11, [r10, #0x8] */
/* @0x206868 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20686c ldr r11, [r10, #0x4] */
/* @0x206870 sub r11, r11, #1 */
/* @0x206874 str r11, [r10, #0x4] */
/* @0x206878 cmp r11, #0 */
/* @0x20687c bne 0x2068a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x390> */
/* @0x206880 ldr r0, [r10] */
/* @0x206884 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206888 mov r0, r10 */
/* @0x20688c str r11, [r10] */
/* @0x206890 str r11, [r10, #0x8] */
/* @0x206894 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x206898 mov r0, r10 */
/* @0x20689c bl 0x27d1d0 <_ZdlPv> */
/* @0x2068a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2068a4 mov r0, r10 */
/* @0x2068a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2068ac b 0x2066f4 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1e4> */
/* @0x2068b0 ldr r0, [r9] */
/* @0x2068b4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2068b8 str r10, [r9] */
/* @0x2068bc str r10, [r9, #0x8] */
/* @0x2068c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2068c4 ldr r10, [r9, #0x4] */
/* @0x2068c8 sub r10, r10, #1 */
/* @0x2068cc str r10, [r9, #0x4] */
/* @0x2068d0 cmp r10, #0 */
/* @0x2068d4 bne 0x2068f8 <_ZN12CDS_Priority3AddEP6RValueS1_+0x3e8> */
/* @0x2068d8 ldr r0, [r9] */
/* @0x2068dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2068e0 mov r0, r9 */
/* @0x2068e4 str r10, [r9] */
/* @0x2068e8 str r10, [r9, #0x8] */
/* @0x2068ec bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2068f0 mov r0, r9 */
/* @0x2068f4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2068f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2068fc mov r0, r9 */
/* @0x206900 bl 0x27d1d0 <_ZdlPv> */
/* @0x206904 b 0x206728 <_ZN12CDS_Priority3AddEP6RValueS1_+0x218> */
/* @0x206908 mov r0, r7 */
/* @0x20690c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x206910 b 0x206568 <_ZN12CDS_Priority3AddEP6RValueS1_+0x58> */
/* @0x206914 mov r0, r6 */
/* @0x206918 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20691c b 0x206620 <_ZN12CDS_Priority3AddEP6RValueS1_+0x110> */
/* @0x206920 andseq sp, r4, r4, lsr #1 */

/* ── FUNC 0x206924 · CDS_Grid::Get_Max(RValue&, int, int, int, int) · size=1008 · insn=252 */
/* @0x206924 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x206928 sub sp, sp, #12 */
/* @0x20692c mov r6, r0 */
/* @0x206930 mov r9, #0 */
/* @0x206934 ldr r4, [sp, #0x30] */
/* @0x206938 mov r8, r9 */
/* @0x20693c str r1, [sp, #0x4] */
/* @0x206940 cmp r2, r4 */
/* @0x206944 ldr r1, [sp, #0x34] */
/* @0x206948 lsrlt r0, r2, #31 */
/* @0x20694c lsrge r0, r4, #31 */
/* @0x206950 cmp r2, r4 */
/* @0x206954 movlt r11, r2 */
/* @0x206958 movge r11, r4 */
/* @0x20695c cmp r0, #0 */
/* @0x206960 movne r11, #0 */
/* @0x206964 cmp r3, r1 */
/* @0x206968 movlt r0, r3 */
/* @0x20696c movge r0, r1 */
/* @0x206970 cmp r3, r1 */
/* @0x206974 lsrge r12, r1, #31 */
/* @0x206978 lsrlt r12, r3, #31 */
/* @0x20697c cmp r2, r4 */
/* @0x206980 movge r10, r2 */
/* @0x206984 movlt r10, r4 */
/* @0x206988 cmp r12, r9 */
/* @0x20698c movne r0, r9 */
/* @0x206990 str r0, [sp] */
/* @0x206994 ldr r0, [r6, #0x4] */
/* @0x206998 cmp r3, r1 */
/* @0x20699c movge r7, r3 */
/* @0x2069a0 movlt r7, r1 */
/* @0x2069a4 mov r1, #1 */
/* @0x2069a8 cmp r10, r0 */
/* @0x2069ac subge r3, r0, #1 */
/* @0x2069b0 movlt r3, r10 */
/* @0x2069b4 cmp r11, r3 */
/* @0x2069b8 bgt 0x206a60 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x13c> */
/* @0x2069bc ldr r3, [r6, #0x8] */
/* @0x2069c0 ldr r4, [sp] */
/* @0x2069c4 b 0x206a38 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x114> */
/* @0x2069c8 mla r5, r0, r4, r11 */
/* @0x2069cc ldr r2, [r6] */
/* @0x2069d0 cmp r1, #0 */
/* @0x2069d4 add r5, r2, r5, lsl #4 */
/* @0x2069d8 movne r8, r5 */
/* @0x2069dc bne 0x206a30 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x10c> */
/* @0x2069e0 ldr r3, [pc, #0x31c] */
/* @0x2069e4 ldr r3, [pc, r3] */
/* @0x2069e8 ldrb r3, [r3] */
/* @0x2069ec cmp r3, #0 */
/* @0x2069f0 beq 0x206a0c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0xe8> */
/* @0x2069f4 ldr r3, [r8, #0xc] */
/* @0x2069f8 cmp r3, #1 */
/* @0x2069fc ldr r3, [r5, #0xc] */
/* @0x206a00 beq 0x206a54 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x130> */
/* @0x206a04 cmp r3, #1 */
/* @0x206a08 moveq r9, #1 */
/* @0x206a0c ldr r3, [pc, #0x2f4] */
/* @0x206a10 mov r0, r8 */
/* @0x206a14 mov r1, r5 */
/* @0x206a18 ldr r3, [pc, r3] */
/* @0x206a1c ldrd r2, r3, [r3] */
/* @0x206a20 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x206a24 cmp r0, #0 */
/* @0x206a28 ldmib r6, {r0, r3} */
/* @0x206a2c movlt r8, r5 */
/* @0x206a30 add r4, r4, #1 */
/* @0x206a34 mov r1, #0 */
/* @0x206a38 cmp r7, r3 */
/* @0x206a3c subge r2, r3, #1 */
/* @0x206a40 movlt r2, r7 */
/* @0x206a44 cmp r4, r2 */
/* @0x206a48 ble 0x2069c8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0xa4> */
/* @0x206a4c add r11, r11, #1 */
/* @0x206a50 b 0x2069a8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x84> */
/* @0x206a54 cmp r3, #1 */
/* @0x206a58 movne r9, #1 */
/* @0x206a5c b 0x206a0c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0xe8> */
/* @0x206a60 cmp r8, #0 */
/* @0x206a64 beq 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206a68 cmp r9, #0 */
/* @0x206a6c bne 0x206b84 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x260> */
/* @0x206a70 ldr r0, [sp, #0x4] */
/* @0x206a74 ldr r2, [r0, #0xc] */
/* @0x206a78 bic r3, r2, #-16777216 */
/* @0x206a7c cmp r3, #1 */
/* @0x206a80 beq 0x206b48 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x224> */
/* @0x206a84 cmp r3, #2 */
/* @0x206a88 bne 0x206ab4 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x190> */
/* @0x206a8c sub r3, r2, #1 */
/* @0x206a90 bic r3, r3, #-16777216 */
/* @0x206a94 bic r3, r3, #3 */
/* @0x206a98 cmp r3, #0 */
/* @0x206a9c beq 0x206c64 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x340> */
/* @0x206aa0 ldr r0, [sp, #0x4] */
/* @0x206aa4 mov r2, #0 */
/* @0x206aa8 mov r3, #5 */
/* @0x206aac str r2, [r0, #0x8] */
/* @0x206ab0 str r3, [r0, #0xc] */
/* @0x206ab4 ldr r3, [r8, #0xc] */
/* @0x206ab8 mov r1, #0 */
/* @0x206abc ldr r0, [sp, #0x4] */
/* @0x206ac0 ldr r2, [r8, #0x8] */
/* @0x206ac4 str r3, [r0, #0xc] */
/* @0x206ac8 ldr r3, [r8, #0xc] */
/* @0x206acc str r1, [r0] */
/* @0x206ad0 bic r3, r3, #-16777216 */
/* @0x206ad4 str r2, [r0, #0x8] */
/* @0x206ad8 cmp r3, #14 */
/* @0x206adc addls pc, pc, r3, lsl #2 */
/* @0x206ae0 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206ae4 b 0x206b34 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x210> */
/* @0x206ae8 b 0x206bd4 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x2b0> */
/* @0x206aec b 0x206bf8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x2d4> */
/* @0x206af0 b 0x206b20 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x1fc> */
/* @0x206af4 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206af8 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206afc b 0x206ba8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x284> */
/* @0x206b00 b 0x206b20 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x1fc> */
/* @0x206b04 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206b08 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206b0c b 0x206b34 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x210> */
/* @0x206b10 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206b14 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206b18 b 0x206b34 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x210> */
/* @0x206b1c b 0x206b20 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x1fc> */
/* @0x206b20 ldr r3, [r8] */
/* @0x206b24 ldr r1, [sp, #0x4] */
/* @0x206b28 str r3, [r1] */
/* @0x206b2c add sp, sp, #12 */
/* @0x206b30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x206b34 ldm r8, {r2, r3} */
/* @0x206b38 ldr r0, [sp, #0x4] */
/* @0x206b3c stm r0, {r2, r3} */
/* @0x206b40 add sp, sp, #12 */
/* @0x206b44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x206b48 ldr r1, [sp, #0x4] */
/* @0x206b4c ldr r4, [r1] */
/* @0x206b50 cmp r4, #0 */
/* @0x206b54 beq 0x206b74 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x250> */
/* @0x206b58 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206b5c ldr r5, [r4, #0x4] */
/* @0x206b60 sub r5, r5, #1 */
/* @0x206b64 str r5, [r4, #0x4] */
/* @0x206b68 cmp r5, #0 */
/* @0x206b6c beq 0x206c2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x308> */
/* @0x206b70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206b74 ldr r2, [sp, #0x4] */
/* @0x206b78 mov r3, #0 */
/* @0x206b7c str r3, [r2] */
/* @0x206b80 b 0x206ab4 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x190> */
/* @0x206b84 ldr r3, [pc, #0x180] */
/* @0x206b88 ldr r1, [pc, #0x180] */
/* @0x206b8c ldr r3, [pc, r3] */
/* @0x206b90 add r1, pc, r1 */
/* @0x206b94 ldr r0, [r3] */
/* @0x206b98 ldr r3, [r0] */
/* @0x206b9c ldr r3, [r3, #0xc] */
/* @0x206ba0 blx r3 */
/* @0x206ba4 b 0x206a70 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x14c> */
/* @0x206ba8 ldr r3, [r8] */
/* @0x206bac ldr r0, [sp, #0x4] */
/* @0x206bb0 str r3, [r0] */
/* @0x206bb4 ldr r3, [r8] */
/* @0x206bb8 cmp r3, #0 */
/* @0x206bbc beq 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206bc0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x206bc4 ldr r1, [r8] */
/* @0x206bc8 add sp, sp, #12 */
/* @0x206bcc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x206bd0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x206bd4 ldr r3, [r8] */
/* @0x206bd8 cmp r3, #0 */
/* @0x206bdc ldrne r2, [r3, #0x4] */
/* @0x206be0 addne r2, r2, #1 */
/* @0x206be4 strne r2, [r3, #0x4] */
/* @0x206be8 ldr r2, [sp, #0x4] */
/* @0x206bec str r3, [r2] */
/* @0x206bf0 add sp, sp, #12 */
/* @0x206bf4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x206bf8 ldr r3, [r8] */
/* @0x206bfc ldr r1, [sp, #0x4] */
/* @0x206c00 cmp r3, #0 */
/* @0x206c04 str r3, [r1] */
/* @0x206c08 beq 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206c0c ldr r1, [r3, #0x8] */
/* @0x206c10 ldr r2, [r3] */
/* @0x206c14 cmp r1, #0 */
/* @0x206c18 add r2, r2, #1 */
/* @0x206c1c str r2, [r3] */
/* @0x206c20 ldreq r2, [sp, #0x4] */
/* @0x206c24 streq r2, [r3, #0x8] */
/* @0x206c28 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208> */
/* @0x206c2c ldr r0, [r4] */
/* @0x206c30 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206c34 str r5, [r4] */
/* @0x206c38 str r5, [r4, #0x8] */
/* @0x206c3c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206c40 ldr r5, [r4, #0x4] */
/* @0x206c44 sub r5, r5, #1 */
/* @0x206c48 str r5, [r4, #0x4] */
/* @0x206c4c cmp r5, #0 */
/* @0x206c50 beq 0x206c70 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x34c> */
/* @0x206c54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206c58 mov r0, r4 */
/* @0x206c5c bl 0x27d1d0 <_ZdlPv> */
/* @0x206c60 b 0x206b70 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x24c> */
/* @0x206c64 ldr r0, [sp, #0x4] */
/* @0x206c68 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x206c6c b 0x206aa0 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x17c> */
/* @0x206c70 ldr r0, [r4] */
/* @0x206c74 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206c78 str r5, [r4] */
/* @0x206c7c str r5, [r4, #0x8] */
/* @0x206c80 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206c84 ldr r5, [r4, #0x4] */
/* @0x206c88 sub r5, r5, #1 */
/* @0x206c8c str r5, [r4, #0x4] */
/* @0x206c90 cmp r5, #0 */
/* @0x206c94 beq 0x206ca8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x384> */
/* @0x206c98 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206c9c mov r0, r4 */
/* @0x206ca0 bl 0x27d1d0 <_ZdlPv> */
/* @0x206ca4 b 0x206c54 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x330> */
/* @0x206ca8 ldr r0, [r4] */
/* @0x206cac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206cb0 str r5, [r4] */
/* @0x206cb4 str r5, [r4, #0x8] */
/* @0x206cb8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206cbc ldr r5, [r4, #0x4] */
/* @0x206cc0 sub r5, r5, #1 */
/* @0x206cc4 str r5, [r4, #0x4] */
/* @0x206cc8 cmp r5, #0 */
/* @0x206ccc beq 0x206ce0 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x3bc> */
/* @0x206cd0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206cd4 mov r0, r4 */
/* @0x206cd8 bl 0x27d1d0 <_ZdlPv> */
/* @0x206cdc b 0x206c98 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x374> */
/* @0x206ce0 ldr r0, [r4] */
/* @0x206ce4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x206ce8 mov r0, r4 */
/* @0x206cec str r5, [r4] */
/* @0x206cf0 str r5, [r4, #0x8] */
/* @0x206cf4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x206cf8 mov r0, r4 */
/* @0x206cfc bl 0x27d1d0 <_ZdlPv> */
/* @0x206d00 b 0x206cd0 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x3ac> */
/* @0x206d04 andseq r7, lr, r12, lsr #9 */
/* @0x206d08 andseq r10, lr, r12, ror #18 */
/* @0x206d0c ldrheq r6, [lr], -r4 */
/* @0x206d10 andseq r12, r4, r0, lsr #25 */

/* ── FUNC 0x206d14 · CDS_Grid::Get_Min(RValue&, int, int, int, int) · size=1008 · insn=252 */
/* @0x206d14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x206d18 sub sp, sp, #12 */
/* @0x206d1c mov r6, r0 */
/* @0x206d20 mov r9, #0 */
/* @0x206d24 ldr r4, [sp, #0x30] */
/* @0x206d28 mov r7, r9 */
/* @0x206d2c str r1, [sp, #0x4] */
/* @0x206d30 cmp r2, r4 */
/* @0x206d34 ldr r1, [sp, #0x34] */
/* @0x206d38 lsrlt r0, r2, #31 */
/* @0x206d3c lsrge r0, r4, #31 */
/* @0x206d40 cmp r2, r4 */
/* @0x206d44 movlt r11, r2 */
/* @0x206d48 movge r11, r4 */
/* @0x206d4c cmp r0, #0 */
/* @0x206d50 movne r11, #0 */
/* @0x206d54 cmp r3, r1 */
/* @0x206d58 movlt r0, r3 */
/* @0x206d5c movge r0, r1 */
/* @0x206d60 cmp r3, r1 */
/* @0x206d64 lsrge r12, r1, #31 */
/* @0x206d68 lsrlt r12, r3, #31 */
/* @0x206d6c cmp r2, r4 */
/* @0x206d70 movge r10, r2 */
/* @0x206d74 movlt r10, r4 */
/* @0x206d78 cmp r12, r9 */
/* @0x206d7c movne r0, r9 */
/* @0x206d80 str r0, [sp] */
/* @0x206d84 ldr r0, [r6, #0x4] */
/* @0x206d88 cmp r3, r1 */
/* @0x206d8c movge r8, r3 */
/* @0x206d90 movlt r8, r1 */
/* @0x206d94 mov r1, #1 */
/* @0x206d98 cmp r10, r0 */
/* @0x206d9c subge r3, r0, #1 */
/* @0x206da0 movlt r3, r10 */
/* @0x206da4 cmp r11, r3 */
/* @0x206da8 bgt 0x206e50 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x13c> */
/* @0x206dac ldr r3, [r6, #0x8] */
/* @0x206db0 ldr r4, [sp] */
/* @0x206db4 b 0x206e28 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x114> */
/* @0x206db8 mla r5, r0, r4, r11 */
/* @0x206dbc ldr r2, [r6] */
/* @0x206dc0 cmp r1, #0 */
/* @0x206dc4 add r5, r2, r5, lsl #4 */
/* @0x206dc8 bne 0x206e1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x108> */
/* @0x206dcc ldr r3, [pc, #0x320] */
/* @0x206dd0 ldr r3, [pc, r3] */
/* @0x206dd4 ldrb r3, [r3] */
/* @0x206dd8 cmp r3, #0 */
/* @0x206ddc beq 0x206df8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0xe4> */
/* @0x206de0 ldr r3, [r7, #0xc] */
/* @0x206de4 cmp r3, #1 */
/* @0x206de8 ldr r3, [r5, #0xc] */
/* @0x206dec beq 0x206e44 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x130> */
/* @0x206df0 cmp r3, #1 */
/* @0x206df4 moveq r9, #1 */
/* @0x206df8 ldr r3, [pc, #0x2f8] */
/* @0x206dfc mov r1, r5 */
/* @0x206e00 mov r0, r7 */
/* @0x206e04 ldr r3, [pc, r3] */
/* @0x206e08 ldrd r2, r3, [r3] */
/* @0x206e0c bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x206e10 cmp r0, #0 */
/* @0x206e14 ldmib r6, {r0, r3} */
/* @0x206e18 movle r5, r7 */
/* @0x206e1c add r4, r4, #1 */
/* @0x206e20 mov r7, r5 */
/* @0x206e24 mov r1, #0 */
/* @0x206e28 cmp r8, r3 */
/* @0x206e2c subge r2, r3, #1 */
/* @0x206e30 movlt r2, r8 */
/* @0x206e34 cmp r4, r2 */
/* @0x206e38 ble 0x206db8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0xa4> */
/* @0x206e3c add r11, r11, #1 */
/* @0x206e40 b 0x206d98 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x84> */
/* @0x206e44 cmp r3, #1 */
/* @0x206e48 movne r9, #1 */
/* @0x206e4c b 0x206df8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0xe4> */
/* @0x206e50 cmp r7, #0 */
/* @0x206e54 beq 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206e58 cmp r9, #0 */
/* @0x206e5c bne 0x206f74 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x260> */
/* @0x206e60 ldr r0, [sp, #0x4] */
/* @0x206e64 ldr r2, [r0, #0xc] */
/* @0x206e68 bic r3, r2, #-16777216 */
/* @0x206e6c cmp r3, #1 */
/* @0x206e70 beq 0x206f38 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x224> */
/* @0x206e74 cmp r3, #2 */
/* @0x206e78 bne 0x206ea4 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x190> */
/* @0x206e7c sub r3, r2, #1 */
/* @0x206e80 bic r3, r3, #-16777216 */
/* @0x206e84 bic r3, r3, #3 */
/* @0x206e88 cmp r3, #0 */
/* @0x206e8c beq 0x207054 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x340> */
/* @0x206e90 ldr r0, [sp, #0x4] */
/* @0x206e94 mov r2, #0 */
/* @0x206e98 mov r3, #5 */
/* @0x206e9c str r2, [r0, #0x8] */
/* @0x206ea0 str r3, [r0, #0xc] */
/* @0x206ea4 ldr r3, [r7, #0xc] */
/* @0x206ea8 mov r1, #0 */
/* @0x206eac ldr r0, [sp, #0x4] */
/* @0x206eb0 ldr r2, [r7, #0x8] */
/* @0x206eb4 str r3, [r0, #0xc] */
/* @0x206eb8 ldr r3, [r7, #0xc] */
/* @0x206ebc str r1, [r0] */
/* @0x206ec0 bic r3, r3, #-16777216 */
/* @0x206ec4 str r2, [r0, #0x8] */
/* @0x206ec8 cmp r3, #14 */
/* @0x206ecc addls pc, pc, r3, lsl #2 */
/* @0x206ed0 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206ed4 b 0x206f24 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x210> */
/* @0x206ed8 b 0x206fc4 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x2b0> */
/* @0x206edc b 0x206fe8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x2d4> */
/* @0x206ee0 b 0x206f10 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x1fc> */
/* @0x206ee4 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206ee8 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206eec b 0x206f98 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x284> */
/* @0x206ef0 b 0x206f10 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x1fc> */
/* @0x206ef4 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206ef8 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206efc b 0x206f24 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x210> */
/* @0x206f00 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206f04 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206f08 b 0x206f24 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x210> */
/* @0x206f0c b 0x206f10 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x1fc> */
/* @0x206f10 ldr r3, [r7] */
/* @0x206f14 ldr r1, [sp, #0x4] */
/* @0x206f18 str r3, [r1] */
/* @0x206f1c add sp, sp, #12 */
/* @0x206f20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x206f24 ldm r7, {r2, r3} */
/* @0x206f28 ldr r0, [sp, #0x4] */
/* @0x206f2c stm r0, {r2, r3} */
/* @0x206f30 add sp, sp, #12 */
/* @0x206f34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x206f38 ldr r1, [sp, #0x4] */
/* @0x206f3c ldr r4, [r1] */
/* @0x206f40 cmp r4, #0 */
/* @0x206f44 beq 0x206f64 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x250> */
/* @0x206f48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x206f4c ldr r5, [r4, #0x4] */
/* @0x206f50 sub r5, r5, #1 */
/* @0x206f54 str r5, [r4, #0x4] */
/* @0x206f58 cmp r5, #0 */
/* @0x206f5c beq 0x20701c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x308> */
/* @0x206f60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x206f64 ldr r2, [sp, #0x4] */
/* @0x206f68 mov r3, #0 */
/* @0x206f6c str r3, [r2] */
/* @0x206f70 b 0x206ea4 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x190> */
/* @0x206f74 ldr r3, [pc, #0x180] */
/* @0x206f78 ldr r1, [pc, #0x180] */
/* @0x206f7c ldr r3, [pc, r3] */
/* @0x206f80 add r1, pc, r1 */
/* @0x206f84 ldr r0, [r3] */
/* @0x206f88 ldr r3, [r0] */
/* @0x206f8c ldr r3, [r3, #0xc] */
/* @0x206f90 blx r3 */
/* @0x206f94 b 0x206e60 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x14c> */
/* @0x206f98 ldr r3, [r7] */
/* @0x206f9c ldr r0, [sp, #0x4] */
/* @0x206fa0 str r3, [r0] */
/* @0x206fa4 ldr r3, [r7] */
/* @0x206fa8 cmp r3, #0 */
/* @0x206fac beq 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206fb0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x206fb4 ldr r1, [r7] */
/* @0x206fb8 add sp, sp, #12 */
/* @0x206fbc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x206fc0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x206fc4 ldr r3, [r7] */
/* @0x206fc8 cmp r3, #0 */
/* @0x206fcc ldrne r2, [r3, #0x4] */
/* @0x206fd0 addne r2, r2, #1 */
/* @0x206fd4 strne r2, [r3, #0x4] */
/* @0x206fd8 ldr r2, [sp, #0x4] */
/* @0x206fdc str r3, [r2] */
/* @0x206fe0 add sp, sp, #12 */
/* @0x206fe4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x206fe8 ldr r3, [r7] */
/* @0x206fec ldr r1, [sp, #0x4] */
/* @0x206ff0 cmp r3, #0 */
/* @0x206ff4 str r3, [r1] */
/* @0x206ff8 beq 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x206ffc ldr r1, [r3, #0x8] */
/* @0x207000 ldr r2, [r3] */
/* @0x207004 cmp r1, #0 */
/* @0x207008 add r2, r2, #1 */
/* @0x20700c str r2, [r3] */
/* @0x207010 ldreq r2, [sp, #0x4] */
/* @0x207014 streq r2, [r3, #0x8] */
/* @0x207018 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208> */
/* @0x20701c ldr r0, [r4] */
/* @0x207020 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x207024 str r5, [r4] */
/* @0x207028 str r5, [r4, #0x8] */
/* @0x20702c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x207030 ldr r5, [r4, #0x4] */
/* @0x207034 sub r5, r5, #1 */
/* @0x207038 str r5, [r4, #0x4] */
/* @0x20703c cmp r5, #0 */
/* @0x207040 beq 0x207060 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x34c> */
/* @0x207044 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207048 mov r0, r4 */
/* @0x20704c bl 0x27d1d0 <_ZdlPv> */
/* @0x207050 b 0x206f60 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x24c> */
/* @0x207054 ldr r0, [sp, #0x4] */
/* @0x207058 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20705c b 0x206e90 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x17c> */
/* @0x207060 ldr r0, [r4] */
/* @0x207064 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x207068 str r5, [r4] */
/* @0x20706c str r5, [r4, #0x8] */
/* @0x207070 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x207074 ldr r5, [r4, #0x4] */
/* @0x207078 sub r5, r5, #1 */
/* @0x20707c str r5, [r4, #0x4] */
/* @0x207080 cmp r5, #0 */
/* @0x207084 beq 0x207098 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x384> */
/* @0x207088 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20708c mov r0, r4 */
/* @0x207090 bl 0x27d1d0 <_ZdlPv> */
/* @0x207094 b 0x207044 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x330> */
/* @0x207098 ldr r0, [r4] */
/* @0x20709c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2070a0 str r5, [r4] */
/* @0x2070a4 str r5, [r4, #0x8] */
/* @0x2070a8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2070ac ldr r5, [r4, #0x4] */
/* @0x2070b0 sub r5, r5, #1 */
/* @0x2070b4 str r5, [r4, #0x4] */
/* @0x2070b8 cmp r5, #0 */
/* @0x2070bc beq 0x2070d0 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x3bc> */
/* @0x2070c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2070c4 mov r0, r4 */
/* @0x2070c8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2070cc b 0x207088 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x374> */
/* @0x2070d0 ldr r0, [r4] */
/* @0x2070d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2070d8 mov r0, r4 */
/* @0x2070dc str r5, [r4] */
/* @0x2070e0 str r5, [r4, #0x8] */
/* @0x2070e4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2070e8 mov r0, r4 */
/* @0x2070ec bl 0x27d1d0 <_ZdlPv> */
/* @0x2070f0 b 0x2070c0 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x3ac> */
/* @0x2070f4 andseq r7, lr, r0, asr #1 */
/* @0x2070f8 andseq r10, lr, r0, lsl #11 */
/* @0x2070fc andseq r6, lr, r4, asr #19 */
/* @0x207100 andseq r12, r4, r4, lsl #18 */

/* ── FUNC 0x207104 · CDS_Grid::Get_Disk_Max(RValue&, double, double, double) · size=1156 · insn=289 */
/* @0x207104 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x207108 vpush {d8, d9, d10, d11, d12} */
/* @0x20710c vmov d12, r2, r3 */
/* @0x207110 sub sp, sp, #20 */
/* @0x207114 vldr d11, [sp, #104] */
/* @0x207118 vsub.f64 d6, d12, d11 */
/* @0x20711c mov r8, r0 */
/* @0x207120 str r1, [sp, #0xc] */
/* @0x207124 vldr d10, [sp, #96] */
/* @0x207128 vmov r0, r1, d6 */
/* @0x20712c bl 0xb6598 <floor@plt> */
/* @0x207130 ldr r3, [r8, #0x4] */
/* @0x207134 sub r3, r3, #1 */
/* @0x207138 str r3, [sp, #0x8] */
/* @0x20713c vmov d7, r0, r1 */
/* @0x207140 vcmpe.f64 d7, #0 */
/* @0x207144 vmrs APSR_nzcv, fpscr */
/* @0x207148 vcvtpl.s32.f64 s13, d7 */
/* @0x20714c movmi r9, #0 */
/* @0x207150 vadd.f64 d7, d12, d11 */
/* @0x207154 vmovpl r9, s13 */
/* @0x207158 vmov r0, r1, d7 */
/* @0x20715c bl 0xb670c <ceil@plt> */
/* @0x207160 vldr s11, [sp, #8] */
/* @0x207164 vcvt.f64.s32 d6, s11 */
/* @0x207168 vmov d7, r0, r1 */
/* @0x20716c vcmpe.f64 d6, d7 */
/* @0x207170 vmrs APSR_nzcv, fpscr */
/* @0x207174 vcvtpl.s32.f64 s12, d7 */
/* @0x207178 vsub.f64 d7, d10, d11 */
/* @0x20717c vstrpl s12, [sp, #8] */
/* @0x207180 vmov r0, r1, d7 */
/* @0x207184 bl 0xb6598 <floor@plt> */
/* @0x207188 ldr r7, [r8, #0x8] */
/* @0x20718c vadd.f64 d6, d10, d11 */
/* @0x207190 sub r7, r7, #1 */
/* @0x207194 vmov d7, r0, r1 */
/* @0x207198 vcmpe.f64 d7, #0 */
/* @0x20719c vmrs APSR_nzcv, fpscr */
/* @0x2071a0 vcvtpl.s32.f64 s11, d7 */
/* @0x2071a4 movmi r0, #0 */
/* @0x2071a8 strmi r0, [sp, #0x4] */
/* @0x2071ac vmov r0, r1, d6 */
/* @0x2071b0 vstrpl s11, [sp, #4] */
/* @0x2071b4 bl 0xb670c <ceil@plt> */
/* @0x2071b8 vmov s11, r7 */
/* @0x2071bc vcvt.f64.s32 d6, s11 */
/* @0x2071c0 vmov d7, r0, r1 */
/* @0x2071c4 ldr r0, [sp, #0x8] */
/* @0x2071c8 vcmpe.f64 d6, d7 */
/* @0x2071cc vmrs APSR_nzcv, fpscr */
/* @0x2071d0 vcvtpl.s32.f64 s12, d7 */
/* @0x2071d4 vmovpl r7, s12 */
/* @0x2071d8 cmp r9, r0 */
/* @0x2071dc bgt 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x2071e0 mov r6, #0 */
/* @0x2071e4 mov r11, #1 */
/* @0x2071e8 mov r10, r6 */
/* @0x2071ec ldr r1, [sp, #0x4] */
/* @0x2071f0 cmp r1, r7 */
/* @0x2071f4 bgt 0x2072a8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x1a4> */
/* @0x2071f8 vmov s11, r9 */
/* @0x2071fc mov r4, r1 */
/* @0x207200 vmul.f64 d9, d11, d11 */
/* @0x207204 vcvt.f64.s32 d8, s11 */
/* @0x207208 vsub.f64 d8, d8, d12 */
/* @0x20720c vmul.f64 d8, d8, d8 */
/* @0x207210 vmov s11, r4 */
/* @0x207214 vcvt.f64.s32 d7, s11 */
/* @0x207218 vsub.f64 d7, d7, d10 */
/* @0x20721c vmov.f64 d6, d8 */
/* @0x207220 vmla.f64 d6, d7, d7 */
/* @0x207224 vcmpe.f64 d9, d6 */
/* @0x207228 vmrs APSR_nzcv, fpscr */
/* @0x20722c blt 0x20729c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x198> */
/* @0x207230 ldr r5, [r8, #0x4] */
/* @0x207234 cmp r11, #0 */
/* @0x207238 ldr r2, [r8] */
/* @0x20723c ldr r3, [pc, #0x334] */
/* @0x207240 movne r11, #0 */
/* @0x207244 mla r5, r5, r4, r9 */
/* @0x207248 add r5, r2, r5, lsl #4 */
/* @0x20724c movne r6, r5 */
/* @0x207250 bne 0x20729c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x198> */
/* @0x207254 ldr r3, [pc, r3] */
/* @0x207258 ldrb r3, [r3] */
/* @0x20725c cmp r3, #0 */
/* @0x207260 beq 0x20727c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x178> */
/* @0x207264 ldr r3, [r6, #0xc] */
/* @0x207268 cmp r3, #1 */
/* @0x20726c ldr r3, [r5, #0xc] */
/* @0x207270 beq 0x207390 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x28c> */
/* @0x207274 cmp r3, #1 */
/* @0x207278 moveq r10, #1 */
/* @0x20727c ldr r3, [pc, #0x2f8] */
/* @0x207280 mov r0, r6 */
/* @0x207284 mov r1, r5 */
/* @0x207288 ldr r3, [pc, r3] */
/* @0x20728c ldrd r2, r3, [r3] */
/* @0x207290 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x207294 cmp r0, #0 */
/* @0x207298 movlt r6, r5 */
/* @0x20729c add r4, r4, #1 */
/* @0x2072a0 cmp r7, r4 */
/* @0x2072a4 bge 0x207210 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x10c> */
/* @0x2072a8 ldr r0, [sp, #0x8] */
/* @0x2072ac add r9, r9, #1 */
/* @0x2072b0 cmp r0, r9 */
/* @0x2072b4 bge 0x2071ec <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0xe8> */
/* @0x2072b8 cmp r6, #0 */
/* @0x2072bc beq 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x2072c0 cmp r10, #0 */
/* @0x2072c4 bne 0x2073f0 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2ec> */
/* @0x2072c8 ldr r0, [sp, #0xc] */
/* @0x2072cc ldr r2, [r0, #0xc] */
/* @0x2072d0 bic r3, r2, #-16777216 */
/* @0x2072d4 cmp r3, #1 */
/* @0x2072d8 beq 0x2073b4 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2b0> */
/* @0x2072dc cmp r3, #2 */
/* @0x2072e0 bne 0x20730c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x208> */
/* @0x2072e4 sub r3, r2, #1 */
/* @0x2072e8 bic r3, r3, #-16777216 */
/* @0x2072ec bic r3, r3, #3 */
/* @0x2072f0 cmp r3, #0 */
/* @0x2072f4 beq 0x2074d8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x3d4> */
/* @0x2072f8 ldr r0, [sp, #0xc] */
/* @0x2072fc mov r2, #0 */
/* @0x207300 mov r3, #5 */
/* @0x207304 str r2, [r0, #0x8] */
/* @0x207308 str r3, [r0, #0xc] */
/* @0x20730c ldr r3, [r6, #0xc] */
/* @0x207310 mov r1, #0 */
/* @0x207314 ldr r0, [sp, #0xc] */
/* @0x207318 ldr r2, [r6, #0x8] */
/* @0x20731c str r3, [r0, #0xc] */
/* @0x207320 ldr r3, [r6, #0xc] */
/* @0x207324 str r1, [r0] */
/* @0x207328 bic r3, r3, #-16777216 */
/* @0x20732c str r2, [r0, #0x8] */
/* @0x207330 cmp r3, #14 */
/* @0x207334 addls pc, pc, r3, lsl #2 */
/* @0x207338 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x20733c b 0x20739c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x298> */
/* @0x207340 b 0x207444 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x340> */
/* @0x207344 b 0x20746c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x368> */
/* @0x207348 b 0x207378 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x274> */
/* @0x20734c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x207350 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x207354 b 0x207414 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x310> */
/* @0x207358 b 0x207378 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x274> */
/* @0x20735c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x207360 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x207364 b 0x20739c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x298> */
/* @0x207368 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x20736c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x207370 b 0x20739c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x298> */
/* @0x207374 b 0x207378 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x274> */
/* @0x207378 ldr r3, [r6] */
/* @0x20737c ldr r1, [sp, #0xc] */
/* @0x207380 str r3, [r1] */
/* @0x207384 add sp, sp, #20 */
/* @0x207388 vpop {d8, d9, d10, d11, d12} */
/* @0x20738c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x207390 cmp r3, #1 */
/* @0x207394 movne r10, #1 */
/* @0x207398 b 0x20727c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x178> */
/* @0x20739c ldm r6, {r2, r3} */
/* @0x2073a0 ldr r0, [sp, #0xc] */
/* @0x2073a4 stm r0, {r2, r3} */
/* @0x2073a8 add sp, sp, #20 */
/* @0x2073ac vpop {d8, d9, d10, d11, d12} */
/* @0x2073b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2073b4 ldr r1, [sp, #0xc] */
/* @0x2073b8 ldr r4, [r1] */
/* @0x2073bc cmp r4, #0 */
/* @0x2073c0 beq 0x2073e0 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2dc> */
/* @0x2073c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2073c8 ldr r5, [r4, #0x4] */
/* @0x2073cc sub r5, r5, #1 */
/* @0x2073d0 str r5, [r4, #0x4] */
/* @0x2073d4 cmp r5, #0 */
/* @0x2073d8 beq 0x2074a0 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x39c> */
/* @0x2073dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2073e0 ldr r2, [sp, #0xc] */
/* @0x2073e4 mov r3, #0 */
/* @0x2073e8 str r3, [r2] */
/* @0x2073ec b 0x20730c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x208> */
/* @0x2073f0 ldr r3, [pc, #0x188] */
/* @0x2073f4 ldr r1, [pc, #0x188] */
/* @0x2073f8 ldr r3, [pc, r3] */
/* @0x2073fc add r1, pc, r1 */
/* @0x207400 ldr r0, [r3] */
/* @0x207404 ldr r3, [r0] */
/* @0x207408 ldr r3, [r3, #0xc] */
/* @0x20740c blx r3 */
/* @0x207410 b 0x2072c8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x1c4> */
/* @0x207414 ldr r3, [r6] */
/* @0x207418 ldr r0, [sp, #0xc] */
/* @0x20741c str r3, [r0] */
/* @0x207420 ldr r3, [r6] */
/* @0x207424 cmp r3, #0 */
/* @0x207428 beq 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x20742c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x207430 ldr r1, [r6] */
/* @0x207434 add sp, sp, #20 */
/* @0x207438 vpop {d8, d9, d10, d11, d12} */
/* @0x20743c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x207440 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x207444 ldr r3, [r6] */
/* @0x207448 cmp r3, #0 */
/* @0x20744c ldrne r2, [r3, #0x4] */
/* @0x207450 addne r2, r2, #1 */
/* @0x207454 strne r2, [r3, #0x4] */
/* @0x207458 ldr r2, [sp, #0xc] */
/* @0x20745c str r3, [r2] */
/* @0x207460 add sp, sp, #20 */
/* @0x207464 vpop {d8, d9, d10, d11, d12} */
/* @0x207468 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20746c ldr r3, [r6] */
/* @0x207470 ldr r1, [sp, #0xc] */
/* @0x207474 cmp r3, #0 */
/* @0x207478 str r3, [r1] */
/* @0x20747c beq 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x207480 ldr r1, [r3, #0x8] */
/* @0x207484 ldr r2, [r3] */
/* @0x207488 cmp r1, #0 */
/* @0x20748c add r2, r2, #1 */
/* @0x207490 str r2, [r3] */
/* @0x207494 ldreq r2, [sp, #0xc] */
/* @0x207498 streq r2, [r3, #0x8] */
/* @0x20749c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280> */
/* @0x2074a0 ldr r0, [r4] */
/* @0x2074a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2074a8 str r5, [r4] */
/* @0x2074ac str r5, [r4, #0x8] */
/* @0x2074b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2074b4 ldr r5, [r4, #0x4] */
/* @0x2074b8 sub r5, r5, #1 */
/* @0x2074bc str r5, [r4, #0x4] */
/* @0x2074c0 cmp r5, #0 */
/* @0x2074c4 beq 0x2074e4 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x3e0> */
/* @0x2074c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2074cc mov r0, r4 */
/* @0x2074d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2074d4 b 0x2073dc <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2d8> */
/* @0x2074d8 ldr r0, [sp, #0xc] */
/* @0x2074dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2074e0 b 0x2072f8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x1f4> */
/* @0x2074e4 ldr r0, [r4] */
/* @0x2074e8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2074ec str r5, [r4] */
/* @0x2074f0 str r5, [r4, #0x8] */
/* @0x2074f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2074f8 ldr r5, [r4, #0x4] */
/* @0x2074fc sub r5, r5, #1 */
/* @0x207500 str r5, [r4, #0x4] */
/* @0x207504 cmp r5, #0 */
/* @0x207508 beq 0x20751c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x418> */
/* @0x20750c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207510 mov r0, r4 */
/* @0x207514 bl 0x27d1d0 <_ZdlPv> */
/* @0x207518 b 0x2074c8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x3c4> */
/* @0x20751c ldr r0, [r4] */
/* @0x207520 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x207524 str r5, [r4] */
/* @0x207528 str r5, [r4, #0x8] */
/* @0x20752c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x207530 ldr r5, [r4, #0x4] */
/* @0x207534 sub r5, r5, #1 */
/* @0x207538 str r5, [r4, #0x4] */
/* @0x20753c cmp r5, #0 */
/* @0x207540 beq 0x207554 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x450> */
/* @0x207544 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207548 mov r0, r4 */
/* @0x20754c bl 0x27d1d0 <_ZdlPv> */
/* @0x207550 b 0x20750c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x408> */
/* @0x207554 ldr r0, [r4] */
/* @0x207558 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20755c mov r0, r4 */
/* @0x207560 str r5, [r4] */
/* @0x207564 str r5, [r4, #0x8] */
/* @0x207568 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20756c mov r0, r4 */
/* @0x207570 bl 0x27d1d0 <_ZdlPv> */
/* @0x207574 b 0x207544 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x440> */
/* @0x207578 andseq r6, lr, r12, lsr r12 */
/* @0x20757c ldrsheq r10, [lr], -r12 */
/* @0x207580 andseq r6, lr, r8, asr #10 */
/* @0x207584 andseq r12, r4, r4, lsr r4 */

/* ── FUNC 0x207588 · CDS_Grid::Get_Disk_Min(RValue&, double, double, double) · size=1156 · insn=289 */
/* @0x207588 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20758c vpush {d8, d9, d10, d11, d12} */
/* @0x207590 vmov d12, r2, r3 */
/* @0x207594 sub sp, sp, #20 */
/* @0x207598 vldr d11, [sp, #104] */
/* @0x20759c vsub.f64 d6, d12, d11 */
/* @0x2075a0 mov r8, r0 */
/* @0x2075a4 str r1, [sp, #0xc] */
/* @0x2075a8 vldr d10, [sp, #96] */
/* @0x2075ac vmov r0, r1, d6 */
/* @0x2075b0 bl 0xb6598 <floor@plt> */
/* @0x2075b4 ldr r3, [r8, #0x4] */
/* @0x2075b8 sub r3, r3, #1 */
/* @0x2075bc str r3, [sp, #0x8] */
/* @0x2075c0 vmov d7, r0, r1 */
/* @0x2075c4 vcmpe.f64 d7, #0 */
/* @0x2075c8 vmrs APSR_nzcv, fpscr */
/* @0x2075cc vcvtpl.s32.f64 s13, d7 */
/* @0x2075d0 movmi r9, #0 */
/* @0x2075d4 vadd.f64 d7, d12, d11 */
/* @0x2075d8 vmovpl r9, s13 */
/* @0x2075dc vmov r0, r1, d7 */
/* @0x2075e0 bl 0xb670c <ceil@plt> */
/* @0x2075e4 vldr s11, [sp, #8] */
/* @0x2075e8 vcvt.f64.s32 d6, s11 */
/* @0x2075ec vmov d7, r0, r1 */
/* @0x2075f0 vcmpe.f64 d6, d7 */
/* @0x2075f4 vmrs APSR_nzcv, fpscr */
/* @0x2075f8 vcvtpl.s32.f64 s12, d7 */
/* @0x2075fc vsub.f64 d7, d10, d11 */
/* @0x207600 vstrpl s12, [sp, #8] */
/* @0x207604 vmov r0, r1, d7 */
/* @0x207608 bl 0xb6598 <floor@plt> */
/* @0x20760c ldr r7, [r8, #0x8] */
/* @0x207610 vadd.f64 d6, d10, d11 */
/* @0x207614 sub r7, r7, #1 */
/* @0x207618 vmov d7, r0, r1 */
/* @0x20761c vcmpe.f64 d7, #0 */
/* @0x207620 vmrs APSR_nzcv, fpscr */
/* @0x207624 vcvtpl.s32.f64 s11, d7 */
/* @0x207628 movmi r0, #0 */
/* @0x20762c strmi r0, [sp, #0x4] */
/* @0x207630 vmov r0, r1, d6 */
/* @0x207634 vstrpl s11, [sp, #4] */
/* @0x207638 bl 0xb670c <ceil@plt> */
/* @0x20763c vmov s11, r7 */
/* @0x207640 vcvt.f64.s32 d6, s11 */
/* @0x207644 vmov d7, r0, r1 */
/* @0x207648 ldr r0, [sp, #0x8] */
/* @0x20764c vcmpe.f64 d6, d7 */
/* @0x207650 vmrs APSR_nzcv, fpscr */
/* @0x207654 vcvtpl.s32.f64 s12, d7 */
/* @0x207658 vmovpl r7, s12 */
/* @0x20765c cmp r9, r0 */
/* @0x207660 bgt 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x207664 mov r6, #0 */
/* @0x207668 mov r11, #1 */
/* @0x20766c mov r10, r6 */
/* @0x207670 ldr r1, [sp, #0x4] */
/* @0x207674 cmp r1, r7 */
/* @0x207678 bgt 0x20772c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x1a4> */
/* @0x20767c vmov s11, r9 */
/* @0x207680 mov r4, r1 */
/* @0x207684 vmul.f64 d9, d11, d11 */
/* @0x207688 vcvt.f64.s32 d8, s11 */
/* @0x20768c vsub.f64 d8, d8, d12 */
/* @0x207690 vmul.f64 d8, d8, d8 */
/* @0x207694 vmov s11, r4 */
/* @0x207698 vcvt.f64.s32 d7, s11 */
/* @0x20769c vsub.f64 d7, d7, d10 */
/* @0x2076a0 vmov.f64 d6, d8 */
/* @0x2076a4 vmla.f64 d6, d7, d7 */
/* @0x2076a8 vcmpe.f64 d9, d6 */
/* @0x2076ac vmrs APSR_nzcv, fpscr */
/* @0x2076b0 blt 0x207720 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x198> */
/* @0x2076b4 ldr r5, [r8, #0x4] */
/* @0x2076b8 cmp r11, #0 */
/* @0x2076bc ldr r2, [r8] */
/* @0x2076c0 ldr r3, [pc, #0x334] */
/* @0x2076c4 movne r11, #0 */
/* @0x2076c8 mla r5, r5, r4, r9 */
/* @0x2076cc add r5, r2, r5, lsl #4 */
/* @0x2076d0 movne r6, r5 */
/* @0x2076d4 bne 0x207720 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x198> */
/* @0x2076d8 ldr r3, [pc, r3] */
/* @0x2076dc ldrb r3, [r3] */
/* @0x2076e0 cmp r3, #0 */
/* @0x2076e4 beq 0x207700 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x178> */
/* @0x2076e8 ldr r3, [r6, #0xc] */
/* @0x2076ec cmp r3, #1 */
/* @0x2076f0 ldr r3, [r5, #0xc] */
/* @0x2076f4 beq 0x207814 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x28c> */
/* @0x2076f8 cmp r3, #1 */
/* @0x2076fc moveq r10, #1 */
/* @0x207700 ldr r3, [pc, #0x2f8] */
/* @0x207704 mov r0, r6 */
/* @0x207708 mov r1, r5 */
/* @0x20770c ldr r3, [pc, r3] */
/* @0x207710 ldrd r2, r3, [r3] */
/* @0x207714 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x207718 cmp r0, #0 */
/* @0x20771c movgt r6, r5 */
/* @0x207720 add r4, r4, #1 */
/* @0x207724 cmp r7, r4 */
/* @0x207728 bge 0x207694 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x10c> */
/* @0x20772c ldr r0, [sp, #0x8] */
/* @0x207730 add r9, r9, #1 */
/* @0x207734 cmp r0, r9 */
/* @0x207738 bge 0x207670 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0xe8> */
/* @0x20773c cmp r6, #0 */
/* @0x207740 beq 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x207744 cmp r10, #0 */
/* @0x207748 bne 0x207874 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2ec> */
/* @0x20774c ldr r0, [sp, #0xc] */
/* @0x207750 ldr r2, [r0, #0xc] */
/* @0x207754 bic r3, r2, #-16777216 */
/* @0x207758 cmp r3, #1 */
/* @0x20775c beq 0x207838 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2b0> */
/* @0x207760 cmp r3, #2 */
/* @0x207764 bne 0x207790 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x208> */
/* @0x207768 sub r3, r2, #1 */
/* @0x20776c bic r3, r3, #-16777216 */
/* @0x207770 bic r3, r3, #3 */
/* @0x207774 cmp r3, #0 */
/* @0x207778 beq 0x20795c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x3d4> */
/* @0x20777c ldr r0, [sp, #0xc] */
/* @0x207780 mov r2, #0 */
/* @0x207784 mov r3, #5 */
/* @0x207788 str r2, [r0, #0x8] */
/* @0x20778c str r3, [r0, #0xc] */
/* @0x207790 ldr r3, [r6, #0xc] */
/* @0x207794 mov r1, #0 */
/* @0x207798 ldr r0, [sp, #0xc] */
/* @0x20779c ldr r2, [r6, #0x8] */
/* @0x2077a0 str r3, [r0, #0xc] */
/* @0x2077a4 ldr r3, [r6, #0xc] */
/* @0x2077a8 str r1, [r0] */
/* @0x2077ac bic r3, r3, #-16777216 */
/* @0x2077b0 str r2, [r0, #0x8] */
/* @0x2077b4 cmp r3, #14 */
/* @0x2077b8 addls pc, pc, r3, lsl #2 */
/* @0x2077bc b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077c0 b 0x207820 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x298> */
/* @0x2077c4 b 0x2078c8 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x340> */
/* @0x2077c8 b 0x2078f0 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x368> */
/* @0x2077cc b 0x2077fc <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x274> */
/* @0x2077d0 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077d4 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077d8 b 0x207898 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x310> */
/* @0x2077dc b 0x2077fc <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x274> */
/* @0x2077e0 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077e4 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077e8 b 0x207820 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x298> */
/* @0x2077ec b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077f0 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2077f4 b 0x207820 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x298> */
/* @0x2077f8 b 0x2077fc <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x274> */
/* @0x2077fc ldr r3, [r6] */
/* @0x207800 ldr r1, [sp, #0xc] */
/* @0x207804 str r3, [r1] */
/* @0x207808 add sp, sp, #20 */
/* @0x20780c vpop {d8, d9, d10, d11, d12} */
/* @0x207810 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x207814 cmp r3, #1 */
/* @0x207818 movne r10, #1 */
/* @0x20781c b 0x207700 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x178> */
/* @0x207820 ldm r6, {r2, r3} */
/* @0x207824 ldr r0, [sp, #0xc] */
/* @0x207828 stm r0, {r2, r3} */
/* @0x20782c add sp, sp, #20 */
/* @0x207830 vpop {d8, d9, d10, d11, d12} */
/* @0x207834 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x207838 ldr r1, [sp, #0xc] */
/* @0x20783c ldr r4, [r1] */
/* @0x207840 cmp r4, #0 */
/* @0x207844 beq 0x207864 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2dc> */
/* @0x207848 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20784c ldr r5, [r4, #0x4] */
/* @0x207850 sub r5, r5, #1 */
/* @0x207854 str r5, [r4, #0x4] */
/* @0x207858 cmp r5, #0 */
/* @0x20785c beq 0x207924 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x39c> */
/* @0x207860 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207864 ldr r2, [sp, #0xc] */
/* @0x207868 mov r3, #0 */
/* @0x20786c str r3, [r2] */
/* @0x207870 b 0x207790 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x208> */
/* @0x207874 ldr r3, [pc, #0x188] */
/* @0x207878 ldr r1, [pc, #0x188] */
/* @0x20787c ldr r3, [pc, r3] */
/* @0x207880 add r1, pc, r1 */
/* @0x207884 ldr r0, [r3] */
/* @0x207888 ldr r3, [r0] */
/* @0x20788c ldr r3, [r3, #0xc] */
/* @0x207890 blx r3 */
/* @0x207894 b 0x20774c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x1c4> */
/* @0x207898 ldr r3, [r6] */
/* @0x20789c ldr r0, [sp, #0xc] */
/* @0x2078a0 str r3, [r0] */
/* @0x2078a4 ldr r3, [r6] */
/* @0x2078a8 cmp r3, #0 */
/* @0x2078ac beq 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x2078b0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2078b4 ldr r1, [r6] */
/* @0x2078b8 add sp, sp, #20 */
/* @0x2078bc vpop {d8, d9, d10, d11, d12} */
/* @0x2078c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2078c4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2078c8 ldr r3, [r6] */
/* @0x2078cc cmp r3, #0 */
/* @0x2078d0 ldrne r2, [r3, #0x4] */
/* @0x2078d4 addne r2, r2, #1 */
/* @0x2078d8 strne r2, [r3, #0x4] */
/* @0x2078dc ldr r2, [sp, #0xc] */
/* @0x2078e0 str r3, [r2] */
/* @0x2078e4 add sp, sp, #20 */
/* @0x2078e8 vpop {d8, d9, d10, d11, d12} */
/* @0x2078ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2078f0 ldr r3, [r6] */
/* @0x2078f4 ldr r1, [sp, #0xc] */
/* @0x2078f8 cmp r3, #0 */
/* @0x2078fc str r3, [r1] */
/* @0x207900 beq 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x207904 ldr r1, [r3, #0x8] */
/* @0x207908 ldr r2, [r3] */
/* @0x20790c cmp r1, #0 */
/* @0x207910 add r2, r2, #1 */
/* @0x207914 str r2, [r3] */
/* @0x207918 ldreq r2, [sp, #0xc] */
/* @0x20791c streq r2, [r3, #0x8] */
/* @0x207920 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280> */
/* @0x207924 ldr r0, [r4] */
/* @0x207928 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20792c str r5, [r4] */
/* @0x207930 str r5, [r4, #0x8] */
/* @0x207934 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x207938 ldr r5, [r4, #0x4] */
/* @0x20793c sub r5, r5, #1 */
/* @0x207940 str r5, [r4, #0x4] */
/* @0x207944 cmp r5, #0 */
/* @0x207948 beq 0x207968 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x3e0> */
/* @0x20794c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207950 mov r0, r4 */
/* @0x207954 bl 0x27d1d0 <_ZdlPv> */
/* @0x207958 b 0x207860 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2d8> */
/* @0x20795c ldr r0, [sp, #0xc] */
/* @0x207960 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x207964 b 0x20777c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x1f4> */
/* @0x207968 ldr r0, [r4] */
/* @0x20796c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x207970 str r5, [r4] */
/* @0x207974 str r5, [r4, #0x8] */
/* @0x207978 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20797c ldr r5, [r4, #0x4] */
/* @0x207980 sub r5, r5, #1 */
/* @0x207984 str r5, [r4, #0x4] */
/* @0x207988 cmp r5, #0 */
/* @0x20798c beq 0x2079a0 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x418> */
/* @0x207990 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207994 mov r0, r4 */
/* @0x207998 bl 0x27d1d0 <_ZdlPv> */
/* @0x20799c b 0x20794c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x3c4> */
/* @0x2079a0 ldr r0, [r4] */
/* @0x2079a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2079a8 str r5, [r4] */
/* @0x2079ac str r5, [r4, #0x8] */
/* @0x2079b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2079b4 ldr r5, [r4, #0x4] */
/* @0x2079b8 sub r5, r5, #1 */
/* @0x2079bc str r5, [r4, #0x4] */
/* @0x2079c0 cmp r5, #0 */
/* @0x2079c4 beq 0x2079d8 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x450> */
/* @0x2079c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2079cc mov r0, r4 */
/* @0x2079d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2079d4 b 0x207990 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x408> */
/* @0x2079d8 ldr r0, [r4] */
/* @0x2079dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2079e0 mov r0, r4 */
/* @0x2079e4 str r5, [r4] */
/* @0x2079e8 str r5, [r4, #0x8] */
/* @0x2079ec bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2079f0 mov r0, r4 */
/* @0x2079f4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2079f8 b 0x2079c8 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x440> */
/* @0x2079fc ldrheq r6, [lr], -r8 */
/* @0x207a00 andseq r9, lr, r8, ror r12 */
/* @0x207a04 andseq r6, lr, r4, asr #1 */
/* @0x207a08 andseq r12, r4, r8, asr r0 */

/* ── FUNC 0x207a0c · DoOperation(int, RValue*, RValue*) · size=784 · insn=196 */
/* @0x207a0c push {r4, r5, r6, r7, r8, lr} */
/* @0x207a10 vpush {d8} */
/* @0x207a14 cmp r0, #2 */
/* @0x207a18 ldr r4, [pc, #0x2f4] */
/* @0x207a1c sub sp, sp, #1040 */
/* @0x207a20 mov r5, r1 */
/* @0x207a24 mov r6, r2 */
/* @0x207a28 ldr r4, [pc, r4] */
/* @0x207a2c ldr r3, [r4] */
/* @0x207a30 str r3, [sp, #0x40c] */
/* @0x207a34 beq 0x207b68 <_Z11DoOperationiP6RValueS0_+0x15c> */
/* @0x207a38 cmp r0, #3 */
/* @0x207a3c beq 0x207b10 <_Z11DoOperationiP6RValueS0_+0x104> */
/* @0x207a40 cmp r0, #1 */
/* @0x207a44 bne 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207a48 ldr r3, [r1, #0xc] */
/* @0x207a4c bic r2, r3, #-16777216 */
/* @0x207a50 cmp r2, #1 */
/* @0x207a54 beq 0x207bbc <_Z11DoOperationiP6RValueS0_+0x1b0> */
/* @0x207a58 cmp r2, #2 */
/* @0x207a5c bne 0x207a84 <_Z11DoOperationiP6RValueS0_+0x78> */
/* @0x207a60 sub r3, r3, #1 */
/* @0x207a64 bic r3, r3, #-16777216 */
/* @0x207a68 bic r3, r3, #3 */
/* @0x207a6c cmp r3, #0 */
/* @0x207a70 beq 0x207d04 <_Z11DoOperationiP6RValueS0_+0x2f8> */
/* @0x207a74 mov r2, #0 */
/* @0x207a78 mov r3, #5 */
/* @0x207a7c str r2, [r5, #0x8] */
/* @0x207a80 str r3, [r5, #0xc] */
/* @0x207a84 ldr r3, [r6, #0xc] */
/* @0x207a88 mov r1, #0 */
/* @0x207a8c ldr r2, [r6, #0x8] */
/* @0x207a90 str r1, [r5] */
/* @0x207a94 str r3, [r5, #0xc] */
/* @0x207a98 ldr r3, [r6, #0xc] */
/* @0x207a9c str r2, [r5, #0x8] */
/* @0x207aa0 bic r3, r3, #-16777216 */
/* @0x207aa4 cmp r3, #14 */
/* @0x207aa8 addls pc, pc, r3, lsl #2 */
/* @0x207aac b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ab0 b 0x207bb0 <_Z11DoOperationiP6RValueS0_+0x1a4> */
/* @0x207ab4 b 0x207c68 <_Z11DoOperationiP6RValueS0_+0x25c> */
/* @0x207ab8 b 0x207c80 <_Z11DoOperationiP6RValueS0_+0x274> */
/* @0x207abc b 0x207aec <_Z11DoOperationiP6RValueS0_+0xe0> */
/* @0x207ac0 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ac4 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ac8 b 0x207c44 <_Z11DoOperationiP6RValueS0_+0x238> */
/* @0x207acc b 0x207aec <_Z11DoOperationiP6RValueS0_+0xe0> */
/* @0x207ad0 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ad4 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ad8 b 0x207bb0 <_Z11DoOperationiP6RValueS0_+0x1a4> */
/* @0x207adc b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ae0 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207ae4 b 0x207bb0 <_Z11DoOperationiP6RValueS0_+0x1a4> */
/* @0x207ae8 b 0x207aec <_Z11DoOperationiP6RValueS0_+0xe0> */
/* @0x207aec ldr r3, [r6] */
/* @0x207af0 str r3, [r5] */
/* @0x207af4 ldr r2, [sp, #0x40c] */
/* @0x207af8 ldr r3, [r4] */
/* @0x207afc cmp r2, r3 */
/* @0x207b00 bne 0x207d10 <_Z11DoOperationiP6RValueS0_+0x304> */
/* @0x207b04 add sp, sp, #1040 */
/* @0x207b08 vpop {d8} */
/* @0x207b0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x207b10 ldr r3, [r1, #0xc] */
/* @0x207b14 cmp r3, #1 */
/* @0x207b18 beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207b1c ldr r3, [r2, #0xc] */
/* @0x207b20 cmp r3, #1 */
/* @0x207b24 beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207b28 mov r0, r1 */
/* @0x207b2c mov r1, #0 */
/* @0x207b30 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x207b34 vmov d8, r0, r1 */
/* @0x207b38 mov r0, r6 */
/* @0x207b3c mov r1, #0 */
/* @0x207b40 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x207b44 mov r3, #0 */
/* @0x207b48 str r3, [r5, #0xc] */
/* @0x207b4c vmov d7, r0, r1 */
/* @0x207b50 vmul.f64 d7, d8, d7 */
/* @0x207b54 vmov r0, r1, d7 */
/* @0x207b58 vmov r2, s14 */
/* @0x207b5c mov r3, r1 */
/* @0x207b60 stm r5, {r2, r3} */
/* @0x207b64 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207b68 ldr r3, [r1, #0xc] */
/* @0x207b6c ldr r2, [r2, #0xc] */
/* @0x207b70 cmp r3, #1 */
/* @0x207b74 beq 0x207bf0 <_Z11DoOperationiP6RValueS0_+0x1e4> */
/* @0x207b78 cmp r2, #1 */
/* @0x207b7c beq 0x207a4c <_Z11DoOperationiP6RValueS0_+0x40> */
/* @0x207b80 mov r0, r1 */
/* @0x207b84 mov r1, #0 */
/* @0x207b88 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x207b8c vmov d8, r0, r1 */
/* @0x207b90 mov r0, r6 */
/* @0x207b94 mov r1, #0 */
/* @0x207b98 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x207b9c mov r3, #0 */
/* @0x207ba0 str r3, [r5, #0xc] */
/* @0x207ba4 vmov d7, r0, r1 */
/* @0x207ba8 vadd.f64 d7, d8, d7 */
/* @0x207bac b 0x207b54 <_Z11DoOperationiP6RValueS0_+0x148> */
/* @0x207bb0 ldm r6, {r2, r3} */
/* @0x207bb4 stm r5, {r2, r3} */
/* @0x207bb8 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207bbc ldr r7, [r5] */
/* @0x207bc0 cmp r7, #0 */
/* @0x207bc4 beq 0x207be4 <_Z11DoOperationiP6RValueS0_+0x1d8> */
/* @0x207bc8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x207bcc ldr r8, [r7, #0x4] */
/* @0x207bd0 sub r8, r8, #1 */
/* @0x207bd4 str r8, [r7, #0x4] */
/* @0x207bd8 cmp r8, #0 */
/* @0x207bdc beq 0x207cac <_Z11DoOperationiP6RValueS0_+0x2a0> */
/* @0x207be0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207be4 mov r3, #0 */
/* @0x207be8 str r3, [r5] */
/* @0x207bec b 0x207a84 <_Z11DoOperationiP6RValueS0_+0x78> */
/* @0x207bf0 cmp r2, #1 */
/* @0x207bf4 bne 0x207a4c <_Z11DoOperationiP6RValueS0_+0x40> */
/* @0x207bf8 add r7, sp, #12 */
/* @0x207bfc mov r1, #0 */
/* @0x207c00 mov r2, #1024 */
/* @0x207c04 mov r0, r7 */
/* @0x207c08 bl 0xb65b0 <memset@plt> */
/* @0x207c0c ldr r12, [r6] */
/* @0x207c10 ldr r3, [r5] */
/* @0x207c14 mov r0, r7 */
/* @0x207c18 ldr r2, [pc, #0xf8] */
/* @0x207c1c mov r1, #1024 */
/* @0x207c20 ldr r12, [r12] */
/* @0x207c24 ldr r3, [r3] */
/* @0x207c28 add r2, pc, r2 */
/* @0x207c2c str r12, [sp] */
/* @0x207c30 bl 0xb65c8 <snprintf@plt> */
/* @0x207c34 mov r0, r5 */
/* @0x207c38 mov r1, r7 */
/* @0x207c3c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x207c40 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207c44 ldr r3, [r6] */
/* @0x207c48 str r3, [r5] */
/* @0x207c4c ldr r3, [r6] */
/* @0x207c50 cmp r3, #0 */
/* @0x207c54 beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207c58 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x207c5c ldr r1, [r6] */
/* @0x207c60 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x207c64 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207c68 ldr r3, [r6] */
/* @0x207c6c cmp r3, #0 */
/* @0x207c70 ldrne r2, [r3, #0x4] */
/* @0x207c74 addne r2, r2, #1 */
/* @0x207c78 strne r2, [r3, #0x4] */
/* @0x207c7c b 0x207af0 <_Z11DoOperationiP6RValueS0_+0xe4> */
/* @0x207c80 ldr r3, [r6] */
/* @0x207c84 cmp r3, #0 */
/* @0x207c88 str r3, [r5] */
/* @0x207c8c beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207c90 ldr r1, [r3, #0x8] */
/* @0x207c94 ldr r2, [r3] */
/* @0x207c98 cmp r1, #0 */
/* @0x207c9c streq r5, [r3, #0x8] */
/* @0x207ca0 add r2, r2, #1 */
/* @0x207ca4 str r2, [r3] */
/* @0x207ca8 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> */
/* @0x207cac ldr r0, [r7] */
/* @0x207cb0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x207cb4 str r8, [r7] */
/* @0x207cb8 str r8, [r7, #0x8] */
/* @0x207cbc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x207cc0 ldr r8, [r7, #0x4] */
/* @0x207cc4 sub r8, r8, #1 */
/* @0x207cc8 str r8, [r7, #0x4] */
/* @0x207ccc cmp r8, #0 */
/* @0x207cd0 bne 0x207cf4 <_Z11DoOperationiP6RValueS0_+0x2e8> */
/* @0x207cd4 ldr r0, [r7] */
/* @0x207cd8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x207cdc mov r0, r7 */
/* @0x207ce0 str r8, [r7] */
/* @0x207ce4 str r8, [r7, #0x8] */
/* @0x207ce8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x207cec mov r0, r7 */
/* @0x207cf0 bl 0x27d1d0 <_ZdlPv> */
/* @0x207cf4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x207cf8 mov r0, r7 */
/* @0x207cfc bl 0x27d1d0 <_ZdlPv> */
/* @0x207d00 b 0x207be0 <_Z11DoOperationiP6RValueS0_+0x1d4> */
/* @0x207d04 mov r0, r5 */
/* @0x207d08 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x207d0c b 0x207a74 <_Z11DoOperationiP6RValueS0_+0x68> */
/* @0x207d10 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x207d14 andseq r5, lr, r8, lsr #30 */
/* @0x207d18 andseq r12, r2, r12, lsr #31 */

/* ── FUNC 0x207d1c · CDS_Grid::Cell_Operation(int, int, int, int, RValue*) · size=152 · insn=38 */
/* @0x207d1c push {r4, r5, r6, lr} */
/* @0x207d20 cmp r3, #0 */
/* @0x207d24 sub sp, sp, #16 */
/* @0x207d28 ldr r4, [r0, #0x4] */
/* @0x207d2c ldr r12, [sp, #0x20] */
/* @0x207d30 ldr r6, [sp, #0x24] */
/* @0x207d34 blt 0x207d74 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x58> */
/* @0x207d38 cmp r3, r4 */
/* @0x207d3c bge 0x207d74 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x58> */
/* @0x207d40 cmp r12, #0 */
/* @0x207d44 blt 0x207d74 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x58> */
/* @0x207d48 ldr r5, [r0, #0x8] */
/* @0x207d4c cmp r12, r5 */
/* @0x207d50 bge 0x207d78 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x5c> */
/* @0x207d54 mla r12, r12, r4, r3 */
/* @0x207d58 ldr r1, [r0] */
/* @0x207d5c mov r0, r2 */
/* @0x207d60 mov r2, r6 */
/* @0x207d64 add r1, r1, r12, lsl #4 */
/* @0x207d68 add sp, sp, #16 */
/* @0x207d6c pop {r4, r5, r6, lr} */
/* @0x207d70 b 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x207d74 ldr r5, [r0, #0x8] */
/* @0x207d78 ldr r0, [pc, #0x2c] */
/* @0x207d7c mov r2, r1 */
/* @0x207d80 ldr r1, [pc, #0x28] */
/* @0x207d84 ldr r0, [pc, r0] */
/* @0x207d88 add r1, pc, r1 */
/* @0x207d8c ldr r0, [r0] */
/* @0x207d90 ldr lr, [r0] */
/* @0x207d94 str r12, [sp] */
/* @0x207d98 stmib sp, {r4, r5} */
/* @0x207d9c ldr r12, [lr, #0xc] */
/* @0x207da0 blx r12 */
/* @0x207da4 add sp, sp, #16 */
/* @0x207da8 pop {r4, r5, r6, pc} */
/* @0x207dac ldrheq r5, [lr], -r12 */
/* @0x207db0 andseq r0, r3, r4, lsl #18 */

/* ── FUNC 0x207db4 · CDS_Grid::Region_Operation(int, int, int, int, int, RValue*) · size=216 · insn=54 */
/* @0x207db4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x207db8 mov r5, r0 */
/* @0x207dbc ldr r12, [sp, #0x28] */
/* @0x207dc0 mov r7, r1 */
/* @0x207dc4 ldr r1, [sp, #0x2c] */
/* @0x207dc8 cmp r2, r12 */
/* @0x207dcc ldr r8, [sp, #0x30] */
/* @0x207dd0 lsrge r0, r12, #31 */
/* @0x207dd4 lsrlt r0, r2, #31 */
/* @0x207dd8 cmp r2, r12 */
/* @0x207ddc movlt r6, r2 */
/* @0x207de0 movge r6, r12 */
/* @0x207de4 cmp r0, #0 */
/* @0x207de8 movne r6, #0 */
/* @0x207dec cmp r3, r1 */
/* @0x207df0 movlt r0, r3 */
/* @0x207df4 movge r0, r1 */
/* @0x207df8 cmp r3, r1 */
/* @0x207dfc lsrlt r10, r3, #31 */
/* @0x207e00 lsrge r10, r1, #31 */
/* @0x207e04 cmp r2, r12 */
/* @0x207e08 movge r9, r2 */
/* @0x207e0c movlt r9, r12 */
/* @0x207e10 cmp r10, #0 */
/* @0x207e14 ldr r12, [r5, #0x4] */
/* @0x207e18 moveq r10, r0 */
/* @0x207e1c movne r10, #0 */
/* @0x207e20 cmp r3, r1 */
/* @0x207e24 movge r11, r3 */
/* @0x207e28 movlt r11, r1 */
/* @0x207e2c cmp r9, r12 */
/* @0x207e30 subge r3, r12, #1 */
/* @0x207e34 movlt r3, r9 */
/* @0x207e38 cmp r6, r3 */
/* @0x207e3c bgt 0x207e88 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0xd4> */
/* @0x207e40 mov r4, r10 */
/* @0x207e44 b 0x207e58 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0xa4> */
/* @0x207e48 ldr r1, [r5] */
/* @0x207e4c add r1, r1, r3, lsl #4 */
/* @0x207e50 bl 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x207e54 ldr r12, [r5, #0x4] */
/* @0x207e58 ldr r2, [r5, #0x8] */
/* @0x207e5c mov r3, r11 */
/* @0x207e60 mov r0, r7 */
/* @0x207e64 cmp r11, r2 */
/* @0x207e68 subge r3, r2, #1 */
/* @0x207e6c mov r2, r8 */
/* @0x207e70 cmp r4, r3 */
/* @0x207e74 mla r3, r12, r4, r6 */
/* @0x207e78 add r4, r4, #1 */
/* @0x207e7c ble 0x207e48 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0x94> */
/* @0x207e80 add r6, r6, #1 */
/* @0x207e84 b 0x207e2c <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue+0x78> */
/* @0x207e88 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x207e8c · CDS_Grid::Disk_Operation(int, double, double, double, RValue*) · size=348 · insn=87 */
/* @0x207e8c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x207e90 vpush {d8, d9, d10, d11, d12} */
/* @0x207e94 vmov d12, r2, r3 */
/* @0x207e98 vldr d11, [sp, #88] */
/* @0x207e9c mov r7, r0 */
/* @0x207ea0 mov r8, r1 */
/* @0x207ea4 vsub.f64 d6, d12, d11 */
/* @0x207ea8 vldr d10, [sp, #80] */
/* @0x207eac ldr r9, [sp, #0x60] */
/* @0x207eb0 vmov r0, r1, d6 */
/* @0x207eb4 bl 0xb6598 <floor@plt> */
/* @0x207eb8 ldr r11, [r7, #0x4] */
/* @0x207ebc sub r11, r11, #1 */
/* @0x207ec0 vmov d7, r0, r1 */
/* @0x207ec4 vcmpe.f64 d7, #0 */
/* @0x207ec8 vmrs APSR_nzcv, fpscr */
/* @0x207ecc vcvtpl.s32.f64 s13, d7 */
/* @0x207ed0 movmi r6, #0 */
/* @0x207ed4 vadd.f64 d7, d12, d11 */
/* @0x207ed8 vmovpl r6, s13 */
/* @0x207edc vmov r0, r1, d7 */
/* @0x207ee0 bl 0xb670c <ceil@plt> */
/* @0x207ee4 vmov s11, r11 */
/* @0x207ee8 vcvt.f64.s32 d6, s11 */
/* @0x207eec vmov d7, r0, r1 */
/* @0x207ef0 vcmpe.f64 d6, d7 */
/* @0x207ef4 vmrs APSR_nzcv, fpscr */
/* @0x207ef8 vcvtpl.s32.f64 s12, d7 */
/* @0x207efc vsub.f64 d7, d10, d11 */
/* @0x207f00 vmovpl r11, s12 */
/* @0x207f04 vmov r0, r1, d7 */
/* @0x207f08 bl 0xb6598 <floor@plt> */
/* @0x207f0c ldr r5, [r7, #0x8] */
/* @0x207f10 vadd.f64 d6, d10, d11 */
/* @0x207f14 sub r5, r5, #1 */
/* @0x207f18 vmov d7, r0, r1 */
/* @0x207f1c vcmpe.f64 d7, #0 */
/* @0x207f20 vmov r0, r1, d6 */
/* @0x207f24 vmrs APSR_nzcv, fpscr */
/* @0x207f28 vcvtpl.s32.f64 s11, d7 */
/* @0x207f2c movmi r10, #0 */
/* @0x207f30 vmovpl r10, s11 */
/* @0x207f34 bl 0xb670c <ceil@plt> */
/* @0x207f38 vmov s11, r5 */
/* @0x207f3c vcvt.f64.s32 d6, s11 */
/* @0x207f40 vmov d7, r0, r1 */
/* @0x207f44 vcmpe.f64 d6, d7 */
/* @0x207f48 vmrs APSR_nzcv, fpscr */
/* @0x207f4c vcvtpl.s32.f64 s12, d7 */
/* @0x207f50 vmovpl r5, s12 */
/* @0x207f54 cmp r6, r11 */
/* @0x207f58 bgt 0x207fe0 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x154> */
/* @0x207f5c cmp r10, r5 */
/* @0x207f60 bgt 0x207fd4 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x148> */
/* @0x207f64 vmov s13, r6 */
/* @0x207f68 mov r4, r10 */
/* @0x207f6c vmul.f64 d9, d11, d11 */
/* @0x207f70 vcvt.f64.s32 d8, s13 */
/* @0x207f74 vsub.f64 d8, d8, d12 */
/* @0x207f78 vmul.f64 d8, d8, d8 */
/* @0x207f7c b 0x207f8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x100> */
/* @0x207f80 add r4, r4, #1 */
/* @0x207f84 cmp r5, r4 */
/* @0x207f88 blt 0x207fd4 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x148> */
/* @0x207f8c vmov s13, r4 */
/* @0x207f90 vcvt.f64.s32 d7, s13 */
/* @0x207f94 vsub.f64 d7, d7, d10 */
/* @0x207f98 vmov.f64 d6, d8 */
/* @0x207f9c vmla.f64 d6, d7, d7 */
/* @0x207fa0 vcmpe.f64 d6, d9 */
/* @0x207fa4 vmrs APSR_nzcv, fpscr */
/* @0x207fa8 bhi 0x207f80 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0xf4> */
/* @0x207fac ldr r1, [r7, #0x4] */
/* @0x207fb0 mov r0, r8 */
/* @0x207fb4 ldr r3, [r7] */
/* @0x207fb8 mov r2, r9 */
/* @0x207fbc mla r1, r1, r4, r6 */
/* @0x207fc0 add r4, r4, #1 */
/* @0x207fc4 add r1, r3, r1, lsl #4 */
/* @0x207fc8 bl 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x207fcc cmp r5, r4 */
/* @0x207fd0 bge 0x207f8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x100> */
/* @0x207fd4 add r6, r6, #1 */
/* @0x207fd8 cmp r11, r6 */
/* @0x207fdc bge 0x207f5c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0xd0> */
/* @0x207fe0 vpop {d8, d9, d10, d11, d12} */
/* @0x207fe4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x207fe8 · CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int) · size=1616 · insn=404 */
/* @0x207fe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x207fec sub sp, sp, #44 */
/* @0x207ff0 mov r9, r2 */
/* @0x207ff4 mov r4, r0 */
/* @0x207ff8 ldr r12, [sp, #0x54] */
/* @0x207ffc str r1, [sp, #0x24] */
/* @0x208000 cmp r3, r12 */
/* @0x208004 ldr r1, [sp, #0x50] */
/* @0x208008 ldr r2, [sp, #0x58] */
/* @0x20800c bge 0x208024 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3c> */
/* @0x208010 cmp r3, #0 */
/* @0x208014 bge 0x208598 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5b0> */
/* @0x208018 mov r0, #0 */
/* @0x20801c str r0, [sp, #0x10] */
/* @0x208020 b 0x20802c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x44> */
/* @0x208024 bic r0, r12, r12, asr #31 */
/* @0x208028 str r0, [sp, #0x10] */
/* @0x20802c ldr r0, [r9, #0x4] */
/* @0x208030 cmp r3, r12 */
/* @0x208034 movge r5, r3 */
/* @0x208038 movlt r5, r12 */
/* @0x20803c cmp r5, r0 */
/* @0x208040 subge r12, r0, #1 */
/* @0x208044 bge 0x208050 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x68> */
/* @0x208048 cmp r12, r3 */
/* @0x20804c movlt r12, r3 */
/* @0x208050 cmp r1, r2 */
/* @0x208054 bge 0x208068 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x80> */
/* @0x208058 cmp r1, #0 */
/* @0x20805c bge 0x208588 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5a0> */
/* @0x208060 mov r6, #0 */
/* @0x208064 b 0x20806c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x84> */
/* @0x208068 bic r6, r2, r2, asr #31 */
/* @0x20806c ldr r7, [r9, #0x8] */
/* @0x208070 cmp r1, r2 */
/* @0x208074 movge r3, r1 */
/* @0x208078 movlt r3, r2 */
/* @0x20807c cmp r3, r7 */
/* @0x208080 subge r7, r7, #1 */
/* @0x208084 bge 0x208094 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0xac> */
/* @0x208088 cmp r1, r2 */
/* @0x20808c movge r7, r1 */
/* @0x208090 movlt r7, r2 */
/* @0x208094 ldr r3, [sp, #0x5c] */
/* @0x208098 cmp r3, #0 */
/* @0x20809c ldrlt r0, [sp, #0x10] */
/* @0x2080a0 rsblt r0, r3, r0 */
/* @0x2080a4 movlt r3, #0 */
/* @0x2080a8 strlt r3, [sp, #0x5c] */
/* @0x2080ac ldr r3, [sp, #0x60] */
/* @0x2080b0 strlt r0, [sp, #0x10] */
/* @0x2080b4 cmp r3, #0 */
/* @0x2080b8 ldr r0, [sp, #0x5c] */
/* @0x2080bc rsblt r6, r3, r6 */
/* @0x2080c0 movlt r3, #0 */
/* @0x2080c4 strlt r3, [sp, #0x60] */
/* @0x2080c8 ldr r3, [sp, #0x10] */
/* @0x2080cc rsb r2, r3, r12 */
/* @0x2080d0 ldr r3, [r4, #0x4] */
/* @0x2080d4 add r2, r2, r0 */
/* @0x2080d8 cmp r3, r2 */
/* @0x2080dc rsb r2, r6, r7 */
/* @0x2080e0 suble r3, r3, #1 */
/* @0x2080e4 ldrle r12, [sp, #0x10] */
/* @0x2080e8 addle r3, r3, r12 */
/* @0x2080ec rsble r12, r0, r3 */
/* @0x2080f0 ldr r0, [sp, #0x5c] */
/* @0x2080f4 ldr r3, [r4, #0x8] */
/* @0x2080f8 add r2, r2, r0 */
/* @0x2080fc ldr r0, [sp, #0x5c] */
/* @0x208100 cmp r3, r2 */
/* @0x208104 suble r3, r3, #1 */
/* @0x208108 addle r7, r3, r6 */
/* @0x20810c ldrle r3, [sp, #0x60] */
/* @0x208110 rsble r7, r3, r7 */
/* @0x208114 ldr r3, [sp, #0x10] */
/* @0x208118 cmp r3, r0 */
/* @0x20811c movlt r3, #0 */
/* @0x208120 movge r3, #1 */
/* @0x208124 str r3, [sp, #0x18] */
/* @0x208128 ldr r3, [sp, #0x60] */
/* @0x20812c ldr r0, [sp, #0x18] */
/* @0x208130 cmp r6, r3 */
/* @0x208134 movlt r3, #0 */
/* @0x208138 movge r3, #1 */
/* @0x20813c tst r0, r3 */
/* @0x208140 str r3, [sp, #0x1c] */
/* @0x208144 ldr r3, [sp, #0x10] */
/* @0x208148 beq 0x2083f8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x410> */
/* @0x20814c cmp r3, r12 */
/* @0x208150 bgt 0x20843c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x454> */
/* @0x208154 ldr r10, [sp, #0x5c] */
/* @0x208158 mov r11, r3 */
/* @0x20815c str r12, [sp, #0x14] */
/* @0x208160 cmp r6, r7 */
/* @0x208164 bgt 0x2081f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x208> */
/* @0x208168 mvn r3, r10 */
/* @0x20816c ldr r8, [sp, #0x60] */
/* @0x208170 lsr r3, r3, #31 */
/* @0x208174 mvn r12, r11 */
/* @0x208178 mov r5, r6 */
/* @0x20817c lsr r12, r12, #31 */
/* @0x208180 str r12, [sp, #0x20] */
/* @0x208184 ldr r1, [r4, #0x4] */
/* @0x208188 cmp r1, r10 */
/* @0x20818c ble 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8> */
/* @0x208190 ldr r2, [r4, #0x8] */
/* @0x208194 cmp r8, r2 */
/* @0x208198 bge 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8> */
/* @0x20819c ldr r2, [r9, #0x4] */
/* @0x2081a0 cmp r2, r11 */
/* @0x2081a4 ble 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8> */
/* @0x2081a8 ldr r0, [r9, #0x8] */
/* @0x2081ac cmp r0, r5 */
/* @0x2081b0 ble 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8> */
/* @0x2081b4 cmp r8, #0 */
/* @0x2081b8 movlt r0, #0 */
/* @0x2081bc andge r0, r3, #1 */
/* @0x2081c0 cmp r0, #0 */
/* @0x2081c4 beq 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8> */
/* @0x2081c8 ldr r0, [sp, #0x20] */
/* @0x2081cc cmp r5, #0 */
/* @0x2081d0 movlt r0, #0 */
/* @0x2081d4 andge r0, r0, #1 */
/* @0x2081d8 cmp r0, #0 */
/* @0x2081dc bne 0x2085d8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5f0> */
/* @0x2081e0 add r5, r5, #1 */
/* @0x2081e4 add r8, r8, #1 */
/* @0x2081e8 cmp r7, r5 */
/* @0x2081ec bge 0x208184 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x19c> */
/* @0x2081f0 ldr r3, [sp, #0x14] */
/* @0x2081f4 add r11, r11, #1 */
/* @0x2081f8 add r10, r10, #1 */
/* @0x2081fc cmp r3, r11 */
/* @0x208200 bge 0x208160 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x178> */
/* @0x208204 ldr r3, [sp, #0x10] */
/* @0x208208 ldr r0, [sp, #0x5c] */
/* @0x20820c ldr r1, [sp, #0x1c] */
/* @0x208210 cmp r3, r0 */
/* @0x208214 ldr r12, [sp, #0x14] */
/* @0x208218 movge r3, #0 */
/* @0x20821c movlt r3, #1 */
/* @0x208220 tst r1, r3 */
/* @0x208224 str r3, [sp, #0x20] */
/* @0x208228 beq 0x208454 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x46c> */
/* @0x20822c ldr r3, [sp, #0x5c] */
/* @0x208230 mov r11, r12 */
/* @0x208234 str r12, [sp, #0x1c] */
/* @0x208238 add r10, r3, r12 */
/* @0x20823c ldr r3, [sp, #0x10] */
/* @0x208240 rsb r10, r3, r10 */
/* @0x208244 cmp r6, r7 */
/* @0x208248 bgt 0x2082d4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2ec> */
/* @0x20824c mvn r3, r10 */
/* @0x208250 ldr r8, [sp, #0x60] */
/* @0x208254 lsr r3, r3, #31 */
/* @0x208258 mvn r12, r11 */
/* @0x20825c mov r5, r6 */
/* @0x208260 lsr r12, r12, #31 */
/* @0x208264 str r12, [sp, #0x14] */
/* @0x208268 ldr r1, [r4, #0x4] */
/* @0x20826c cmp r10, r1 */
/* @0x208270 bge 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc> */
/* @0x208274 ldr r2, [r4, #0x8] */
/* @0x208278 cmp r8, r2 */
/* @0x20827c bge 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc> */
/* @0x208280 ldr r2, [r9, #0x4] */
/* @0x208284 cmp r2, r11 */
/* @0x208288 ble 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc> */
/* @0x20828c ldr r0, [r9, #0x8] */
/* @0x208290 cmp r0, r5 */
/* @0x208294 ble 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc> */
/* @0x208298 cmp r8, #0 */
/* @0x20829c movlt r0, #0 */
/* @0x2082a0 andge r0, r3, #1 */
/* @0x2082a4 cmp r0, #0 */
/* @0x2082a8 beq 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc> */
/* @0x2082ac ldr r0, [sp, #0x14] */
/* @0x2082b0 cmp r5, #0 */
/* @0x2082b4 movlt r0, #0 */
/* @0x2082b8 andge r0, r0, #1 */
/* @0x2082bc cmp r0, #0 */
/* @0x2082c0 bne 0x208608 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x620> */
/* @0x2082c4 add r5, r5, #1 */
/* @0x2082c8 add r8, r8, #1 */
/* @0x2082cc cmp r7, r5 */
/* @0x2082d0 bge 0x208268 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x280> */
/* @0x2082d4 ldr r3, [sp, #0x10] */
/* @0x2082d8 sub r11, r11, #1 */
/* @0x2082dc sub r10, r10, #1 */
/* @0x2082e0 cmp r3, r11 */
/* @0x2082e4 ble 0x208244 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x25c> */
/* @0x2082e8 ldr r3, [sp, #0x60] */
/* @0x2082ec ldr r0, [sp, #0x18] */
/* @0x2082f0 cmp r6, r3 */
/* @0x2082f4 ldr r12, [sp, #0x1c] */
/* @0x2082f8 movge r3, #0 */
/* @0x2082fc movlt r3, #1 */
/* @0x208300 tst r0, r3 */
/* @0x208304 str r3, [sp, #0x1c] */
/* @0x208308 bne 0x208480 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x498> */
/* @0x20830c ldr r3, [sp, #0x20] */
/* @0x208310 ldr r0, [sp, #0x1c] */
/* @0x208314 tst r3, r0 */
/* @0x208318 beq 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408> */
/* @0x20831c ldr r3, [sp, #0x10] */
/* @0x208320 cmp r3, r12 */
/* @0x208324 bgt 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408> */
/* @0x208328 ldr r3, [sp, #0x5c] */
/* @0x20832c mov r11, r12 */
/* @0x208330 ldr r1, [sp, #0x10] */
/* @0x208334 add r10, r3, r12 */
/* @0x208338 ldr r0, [sp, #0x60] */
/* @0x20833c rsb r10, r1, r10 */
/* @0x208340 add r3, r0, r7 */
/* @0x208344 rsb r3, r6, r3 */
/* @0x208348 str r3, [sp, #0xc] */
/* @0x20834c cmp r6, r7 */
/* @0x208350 bgt 0x2083dc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3f4> */
/* @0x208354 mvn r3, r10 */
/* @0x208358 ldr r8, [sp, #0xc] */
/* @0x20835c lsr r3, r3, #31 */
/* @0x208360 mvn r12, r11 */
/* @0x208364 mov r5, r7 */
/* @0x208368 lsr r12, r12, #31 */
/* @0x20836c str r12, [sp, #0x18] */
/* @0x208370 ldr r1, [r4, #0x4] */
/* @0x208374 cmp r10, r1 */
/* @0x208378 bge 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4> */
/* @0x20837c ldr r2, [r4, #0x8] */
/* @0x208380 cmp r8, r2 */
/* @0x208384 bge 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4> */
/* @0x208388 ldr r2, [r9, #0x4] */
/* @0x20838c cmp r2, r11 */
/* @0x208390 ble 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4> */
/* @0x208394 ldr r0, [r9, #0x8] */
/* @0x208398 cmp r0, r5 */
/* @0x20839c ble 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4> */
/* @0x2083a0 cmp r8, #0 */
/* @0x2083a4 movlt r0, #0 */
/* @0x2083a8 andge r0, r3, #1 */
/* @0x2083ac cmp r0, #0 */
/* @0x2083b0 beq 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4> */
/* @0x2083b4 ldr r0, [sp, #0x18] */
/* @0x2083b8 cmp r5, #0 */
/* @0x2083bc movlt r0, #0 */
/* @0x2083c0 andge r0, r0, #1 */
/* @0x2083c4 cmp r0, #0 */
/* @0x2083c8 bne 0x208558 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x570> */
/* @0x2083cc sub r5, r5, #1 */
/* @0x2083d0 sub r8, r8, #1 */
/* @0x2083d4 cmp r6, r5 */
/* @0x2083d8 ble 0x208370 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x388> */
/* @0x2083dc ldr r3, [sp, #0x10] */
/* @0x2083e0 sub r11, r11, #1 */
/* @0x2083e4 sub r10, r10, #1 */
/* @0x2083e8 cmp r3, r11 */
/* @0x2083ec ble 0x20834c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x364> */
/* @0x2083f0 add sp, sp, #44 */
/* @0x2083f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2083f8 ldr r0, [sp, #0x5c] */
/* @0x2083fc ldr r1, [sp, #0x1c] */
/* @0x208400 cmp r3, r0 */
/* @0x208404 movge r3, #0 */
/* @0x208408 movlt r3, #1 */
/* @0x20840c tst r1, r3 */
/* @0x208410 str r3, [sp, #0x20] */
/* @0x208414 beq 0x208454 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x46c> */
/* @0x208418 ldr r3, [sp, #0x10] */
/* @0x20841c cmp r3, r12 */
/* @0x208420 ble 0x20822c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x244> */
/* @0x208424 ldr r3, [sp, #0x60] */
/* @0x208428 cmp r6, r3 */
/* @0x20842c movge r3, #0 */
/* @0x208430 movlt r3, #1 */
/* @0x208434 str r3, [sp, #0x1c] */
/* @0x208438 b 0x20830c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x324> */
/* @0x20843c ldr r3, [sp, #0x10] */
/* @0x208440 ldr r0, [sp, #0x5c] */
/* @0x208444 cmp r3, r0 */
/* @0x208448 movge r3, #0 */
/* @0x20844c movlt r3, #1 */
/* @0x208450 str r3, [sp, #0x20] */
/* @0x208454 ldr r3, [sp, #0x60] */
/* @0x208458 ldr r0, [sp, #0x18] */
/* @0x20845c cmp r6, r3 */
/* @0x208460 movge r3, #0 */
/* @0x208464 movlt r3, #1 */
/* @0x208468 tst r0, r3 */
/* @0x20846c str r3, [sp, #0x1c] */
/* @0x208470 beq 0x20830c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x324> */
/* @0x208474 ldr r3, [sp, #0x10] */
/* @0x208478 cmp r3, r12 */
/* @0x20847c bgt 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408> */
/* @0x208480 ldr r0, [sp, #0x60] */
/* @0x208484 ldr r10, [sp, #0x5c] */
/* @0x208488 ldr r11, [sp, #0x10] */
/* @0x20848c add r3, r0, r7 */
/* @0x208490 rsb r3, r6, r3 */
/* @0x208494 str r12, [sp, #0x14] */
/* @0x208498 str r3, [sp, #0x18] */
/* @0x20849c cmp r6, r7 */
/* @0x2084a0 bgt 0x20852c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x544> */
/* @0x2084a4 mvn r3, r10 */
/* @0x2084a8 ldr r8, [sp, #0x18] */
/* @0x2084ac lsr r3, r3, #31 */
/* @0x2084b0 mvn r12, r11 */
/* @0x2084b4 mov r5, r7 */
/* @0x2084b8 lsr r12, r12, #31 */
/* @0x2084bc str r12, [sp] */
/* @0x2084c0 ldr r1, [r4, #0x4] */
/* @0x2084c4 cmp r10, r1 */
/* @0x2084c8 bge 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534> */
/* @0x2084cc ldr r2, [r4, #0x8] */
/* @0x2084d0 cmp r8, r2 */
/* @0x2084d4 bge 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534> */
/* @0x2084d8 ldr r2, [r9, #0x4] */
/* @0x2084dc cmp r2, r11 */
/* @0x2084e0 ble 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534> */
/* @0x2084e4 ldr r0, [r9, #0x8] */
/* @0x2084e8 cmp r0, r5 */
/* @0x2084ec ble 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534> */
/* @0x2084f0 cmp r8, #0 */
/* @0x2084f4 movlt r0, #0 */
/* @0x2084f8 andge r0, r3, #1 */
/* @0x2084fc cmp r0, #0 */
/* @0x208500 beq 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534> */
/* @0x208504 ldr r0, [sp] */
/* @0x208508 cmp r5, #0 */
/* @0x20850c movlt r0, #0 */
/* @0x208510 andge r0, r0, #1 */
/* @0x208514 cmp r0, #0 */
/* @0x208518 bne 0x2085a8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5c0> */
/* @0x20851c sub r5, r5, #1 */
/* @0x208520 sub r8, r8, #1 */
/* @0x208524 cmp r6, r5 */
/* @0x208528 ble 0x2084c0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x4d8> */
/* @0x20852c ldr r3, [sp, #0x14] */
/* @0x208530 add r11, r11, #1 */
/* @0x208534 add r10, r10, #1 */
/* @0x208538 cmp r3, r11 */
/* @0x20853c bge 0x20849c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x4b4> */
/* @0x208540 ldr r3, [sp, #0x20] */
/* @0x208544 ldr r0, [sp, #0x1c] */
/* @0x208548 ldr r12, [sp, #0x14] */
/* @0x20854c tst r3, r0 */
/* @0x208550 bne 0x208328 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x340> */
/* @0x208554 b 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408> */
/* @0x208558 mla r2, r2, r5, r11 */
/* @0x20855c ldr lr, [r4] */
/* @0x208560 mla r1, r1, r8, r10 */
/* @0x208564 ldr r12, [r9] */
/* @0x208568 ldr r0, [sp, #0x24] */
/* @0x20856c str r3, [sp, #0x8] */
/* @0x208570 str r2, [sp, #0x14] */
/* @0x208574 add r2, r12, r2, lsl #4 */
/* @0x208578 add r1, lr, r1, lsl #4 */
/* @0x20857c bl 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x208580 ldr r3, [sp, #0x8] */
/* @0x208584 b 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4> */
/* @0x208588 ldr r7, [r9, #0x8] */
/* @0x20858c mov r6, r1 */
/* @0x208590 mov r3, r2 */
/* @0x208594 b 0x20807c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x94> */
/* @0x208598 ldr r0, [r9, #0x4] */
/* @0x20859c mov r5, r12 */
/* @0x2085a0 str r3, [sp, #0x10] */
/* @0x2085a4 b 0x20803c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x54> */
/* @0x2085a8 mla r2, r2, r5, r11 */
/* @0x2085ac ldr lr, [r4] */
/* @0x2085b0 mla r1, r1, r8, r10 */
/* @0x2085b4 ldr r12, [r9] */
/* @0x2085b8 ldr r0, [sp, #0x24] */
/* @0x2085bc str r3, [sp, #0x8] */
/* @0x2085c0 str r2, [sp, #0xc] */
/* @0x2085c4 add r2, r12, r2, lsl #4 */
/* @0x2085c8 add r1, lr, r1, lsl #4 */
/* @0x2085cc bl 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x2085d0 ldr r3, [sp, #0x8] */
/* @0x2085d4 b 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534> */
/* @0x2085d8 mla r2, r2, r5, r11 */
/* @0x2085dc ldr lr, [r4] */
/* @0x2085e0 mla r1, r1, r8, r10 */
/* @0x2085e4 ldr r12, [r9] */
/* @0x2085e8 ldr r0, [sp, #0x24] */
/* @0x2085ec str r3, [sp, #0x8] */
/* @0x2085f0 str r2, [sp, #0xc] */
/* @0x2085f4 add r2, r12, r2, lsl #4 */
/* @0x2085f8 add r1, lr, r1, lsl #4 */
/* @0x2085fc bl 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x208600 ldr r3, [sp, #0x8] */
/* @0x208604 b 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8> */
/* @0x208608 mla r2, r2, r5, r11 */
/* @0x20860c ldr lr, [r4] */
/* @0x208610 mla r1, r1, r8, r10 */
/* @0x208614 ldr r12, [r9] */
/* @0x208618 ldr r0, [sp, #0x24] */
/* @0x20861c str r3, [sp, #0x8] */
/* @0x208620 str r2, [sp, #0xc] */
/* @0x208624 add r2, r12, r2, lsl #4 */
/* @0x208628 add r1, lr, r1, lsl #4 */
/* @0x20862c bl 0x207a0c <_Z11DoOperationiP6RValueS0_> */
/* @0x208630 ldr r3, [sp, #0x8] */
/* @0x208634 b 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc> */

/* ── FUNC 0x208638 · ReadValue(RValue&, CStream&, int) · size=812 · insn=203 */
/* @0x208638 ldr r3, [r0, #0xc] */
/* @0x20863c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x208640 sub r3, r3, #1 */
/* @0x208644 bic r3, r3, #-16777216 */
/* @0x208648 sub sp, sp, #12 */
/* @0x20864c bic r3, r3, #3 */
/* @0x208650 mov r7, r2 */
/* @0x208654 mov r2, #0 */
/* @0x208658 cmp r3, r2 */
/* @0x20865c mov r8, r0 */
/* @0x208660 mov r5, r1 */
/* @0x208664 str r2, [sp, #0x4] */
/* @0x208668 beq 0x208714 <_Z9ReadValueR6RValueR7CStreami+0xdc> */
/* @0x20866c mov r4, #0 */
/* @0x208670 mov r3, #5 */
/* @0x208674 str r4, [r8, #0x8] */
/* @0x208678 mov r0, r5 */
/* @0x20867c str r4, [r8] */
/* @0x208680 str r3, [r8, #0xc] */
/* @0x208684 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x208688 cmp r7, #1 */
/* @0x20868c str r0, [r8, #0xc] */
/* @0x208690 beq 0x208870 <_Z9ReadValueR6RValueR7CStreami+0x238> */
/* @0x208694 cmp r7, #2 */
/* @0x208698 beq 0x20871c <_Z9ReadValueR6RValueR7CStreami+0xe4> */
/* @0x20869c cmp r0, #13 */
/* @0x2086a0 addls pc, pc, r0, lsl #2 */
/* @0x2086a4 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086a8 b 0x208734 <_Z9ReadValueR6RValueR7CStreami+0xfc> */
/* @0x2086ac b 0x208748 <_Z9ReadValueR6RValueR7CStreami+0x110> */
/* @0x2086b0 b 0x20876c <_Z9ReadValueR6RValueR7CStreami+0x134> */
/* @0x2086b4 b 0x208824 <_Z9ReadValueR6RValueR7CStreami+0x1ec> */
/* @0x2086b8 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086bc b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x2086c0 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086c4 b 0x208834 <_Z9ReadValueR6RValueR7CStreami+0x1fc> */
/* @0x2086c8 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086cc b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086d0 b 0x208844 <_Z9ReadValueR6RValueR7CStreami+0x20c> */
/* @0x2086d4 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086d8 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8> */
/* @0x2086dc b 0x208734 <_Z9ReadValueR6RValueR7CStreami+0xfc> */
/* @0x2086e0 ldr r3, [pc, #0x26c] */
/* @0x2086e4 mov r2, r0 */
/* @0x2086e8 ldr r1, [pc, #0x268] */
/* @0x2086ec ldr r3, [pc, r3] */
/* @0x2086f0 add r1, pc, r1 */
/* @0x2086f4 ldr r0, [r3] */
/* @0x2086f8 ldr r3, [r0] */
/* @0x2086fc ldr r3, [r3, #0xc] */
/* @0x208700 blx r3 */
/* @0x208704 mov r3, #5 */
/* @0x208708 str r3, [r8, #0xc] */
/* @0x20870c add sp, sp, #12 */
/* @0x208710 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x208714 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x208718 b 0x20866c <_Z9ReadValueR6RValueR7CStreami+0x34> */
/* @0x20871c cmp r0, #1 */
/* @0x208720 beq 0x208854 <_Z9ReadValueR6RValueR7CStreami+0x21c> */
/* @0x208724 cmp r0, #2 */
/* @0x208728 beq 0x20889c <_Z9ReadValueR6RValueR7CStreami+0x264> */
/* @0x20872c cmp r0, #0 */
/* @0x208730 bne 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208734 mov r0, r5 */
/* @0x208738 bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x20873c stm r8, {r0, r1} */
/* @0x208740 add sp, sp, #12 */
/* @0x208744 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x208748 mov r0, r5 */
/* @0x20874c add r1, sp, #4 */
/* @0x208750 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x208754 mov r0, r8 */
/* @0x208758 ldr r1, [sp, #0x4] */
/* @0x20875c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x208760 ldr r0, [sp, #0x4] */
/* @0x208764 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x208768 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x20876c mov r0, r8 */
/* @0x208770 ldr r11, [pc, #0x1e4] */
/* @0x208774 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x208778 add r11, pc, r11 */
/* @0x20877c mov r10, r0 */
/* @0x208780 mov r0, r5 */
/* @0x208784 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x208788 mov r3, #400 */
/* @0x20878c mov r2, r11 */
/* @0x208790 lsl r1, r0, #3 */
/* @0x208794 str r0, [r10, #0x10] */
/* @0x208798 add r0, r10, #4 */
/* @0x20879c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2087a0 ldr r3, [r10, #0x10] */
/* @0x2087a4 cmp r3, #0 */
/* @0x2087a8 movgt r9, #0 */
/* @0x2087ac ble 0x20881c <_Z9ReadValueR6RValueR7CStreami+0x1e4> */
/* @0x2087b0 mov r0, r5 */
/* @0x2087b4 ldr r4, [r10, #0x4] */
/* @0x2087b8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2087bc mov r3, #404 */
/* @0x2087c0 add r6, r4, r9, lsl #3 */
/* @0x2087c4 mov r2, r11 */
/* @0x2087c8 str r0, [r4, r9, lsl #3] */
/* @0x2087cc lsl r1, r0, #4 */
/* @0x2087d0 add r0, r6, #4 */
/* @0x2087d4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2087d8 ldr r3, [r4, r9, lsl #3] */
/* @0x2087dc cmp r3, #0 */
/* @0x2087e0 movgt r4, #0 */
/* @0x2087e4 ble 0x20880c <_Z9ReadValueR6RValueR7CStreami+0x1d4> */
/* @0x2087e8 ldr r0, [r6, #0x4] */
/* @0x2087ec mov r1, r5 */
/* @0x2087f0 mov r2, r7 */
/* @0x2087f4 add r0, r0, r4, lsl #4 */
/* @0x2087f8 add r4, r4, #1 */
/* @0x2087fc bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x208800 ldr r3, [r6] */
/* @0x208804 cmp r3, r4 */
/* @0x208808 bgt 0x2087e8 <_Z9ReadValueR6RValueR7CStreami+0x1b0> */
/* @0x20880c ldr r3, [r10, #0x10] */
/* @0x208810 add r9, r9, #1 */
/* @0x208814 cmp r3, r9 */
/* @0x208818 bgt 0x2087b0 <_Z9ReadValueR6RValueR7CStreami+0x178> */
/* @0x20881c str r10, [r8] */
/* @0x208820 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208824 mov r0, r5 */
/* @0x208828 bl 0x201784 <_ZN7CStream13ReadInteger64Ev> */
/* @0x20882c str r0, [r8] */
/* @0x208830 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208834 mov r0, r5 */
/* @0x208838 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20883c str r0, [r8] */
/* @0x208840 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208844 mov r0, r5 */
/* @0x208848 bl 0x201784 <_ZN7CStream13ReadInteger64Ev> */
/* @0x20884c stm r8, {r0, r1} */
/* @0x208850 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208854 mov r0, r5 */
/* @0x208858 add r1, sp, #4 */
/* @0x20885c bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x208860 mov r0, r8 */
/* @0x208864 ldr r1, [sp, #0x4] */
/* @0x208868 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x20886c b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208870 mov r0, r5 */
/* @0x208874 bl 0x20187c <_ZN7CStream8ReadRealEv> */
/* @0x208878 str r0, [r8] */
/* @0x20887c mov r0, r5 */
/* @0x208880 str r1, [r8, #0x4] */
/* @0x208884 add r1, sp, #4 */
/* @0x208888 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x20888c mov r0, r8 */
/* @0x208890 ldr r1, [sp, #0x4] */
/* @0x208894 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x208898 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x20889c mov r0, r8 */
/* @0x2088a0 ldr r10, [pc, #0xb8] */
/* @0x2088a4 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x2088a8 add r10, pc, r10 */
/* @0x2088ac mov r9, r0 */
/* @0x2088b0 mov r0, r5 */
/* @0x2088b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2088b8 mov r3, #372 */
/* @0x2088bc mov r2, r10 */
/* @0x2088c0 lsl r1, r0, #3 */
/* @0x2088c4 str r0, [r9, #0x10] */
/* @0x2088c8 add r0, r9, #4 */
/* @0x2088cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2088d0 ldr r3, [r9, #0x10] */
/* @0x2088d4 cmp r3, #0 */
/* @0x2088d8 movgt r7, r4 */
/* @0x2088dc ble 0x20894c <_Z9ReadValueR6RValueR7CStreami+0x314> */
/* @0x2088e0 mov r0, r5 */
/* @0x2088e4 ldr r4, [r9, #0x4] */
/* @0x2088e8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x2088ec mov r3, #376 */
/* @0x2088f0 add r6, r4, r7, lsl #3 */
/* @0x2088f4 mov r2, r10 */
/* @0x2088f8 str r0, [r4, r7, lsl #3] */
/* @0x2088fc lsl r1, r0, #4 */
/* @0x208900 add r0, r6, #4 */
/* @0x208904 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x208908 ldr r3, [r4, r7, lsl #3] */
/* @0x20890c cmp r3, #0 */
/* @0x208910 movgt r4, #0 */
/* @0x208914 ble 0x20893c <_Z9ReadValueR6RValueR7CStreami+0x304> */
/* @0x208918 ldr r0, [r6, #0x4] */
/* @0x20891c mov r1, r5 */
/* @0x208920 mov r2, #2 */
/* @0x208924 add r0, r0, r4, lsl #4 */
/* @0x208928 add r4, r4, #1 */
/* @0x20892c bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x208930 ldr r3, [r6] */
/* @0x208934 cmp r3, r4 */
/* @0x208938 bgt 0x208918 <_Z9ReadValueR6RValueR7CStreami+0x2e0> */
/* @0x20893c ldr r3, [r9, #0x10] */
/* @0x208940 add r7, r7, #1 */
/* @0x208944 cmp r3, r7 */
/* @0x208948 bgt 0x2088e0 <_Z9ReadValueR6RValueR7CStreami+0x2a8> */
/* @0x20894c str r9, [r8] */
/* @0x208950 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4> */
/* @0x208954 andseq r5, lr, r8, lsr #32 */
/* @0x208958 andseq r11, r4, r0, asr #4 */
/* @0x20895c andseq r11, r4, r4, ror r0 */
/* @0x208960 andseq r10, r4, r4, asr #30 */

/* ── FUNC 0x208964 · CDS_List::Replace(int, RValue*) · size=560 · insn=140 */
/* @0x208964 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x208968 subs r6, r1, #0 */
/* @0x20896c mov r8, r0 */
/* @0x208970 mov r5, r2 */
/* @0x208974 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208978 ldr r3, [r0, #0x4] */
/* @0x20897c cmp r6, r3 */
/* @0x208980 popge {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208984 ldr r9, [r0, #0xc] */
/* @0x208988 lsl r4, r6, #4 */
/* @0x20898c add r7, r9, r4 */
/* @0x208990 ldr r3, [r7, #0xc] */
/* @0x208994 sub r3, r3, #1 */
/* @0x208998 bic r3, r3, #-16777216 */
/* @0x20899c bic r3, r3, #3 */
/* @0x2089a0 cmp r3, #0 */
/* @0x2089a4 movne r4, r7 */
/* @0x2089a8 beq 0x208b18 <_ZN8CDS_List7ReplaceEiP6RValue+0x1b4> */
/* @0x2089ac mov r3, #5 */
/* @0x2089b0 str r3, [r7, #0xc] */
/* @0x2089b4 ldr r1, [r4, #0xc] */
/* @0x2089b8 mov r3, #0 */
/* @0x2089bc str r3, [r7, #0x8] */
/* @0x2089c0 bic r2, r1, #-16777216 */
/* @0x2089c4 str r3, [r9, r6, lsl #4] */
/* @0x2089c8 cmp r2, #1 */
/* @0x2089cc beq 0x208ae4 <_ZN8CDS_List7ReplaceEiP6RValue+0x180> */
/* @0x2089d0 cmp r2, #2 */
/* @0x2089d4 bne 0x2089fc <_ZN8CDS_List7ReplaceEiP6RValue+0x98> */
/* @0x2089d8 sub r1, r1, #1 */
/* @0x2089dc bic r1, r1, #-16777216 */
/* @0x2089e0 bic r1, r1, #3 */
/* @0x2089e4 cmp r1, #0 */
/* @0x2089e8 beq 0x208b88 <_ZN8CDS_List7ReplaceEiP6RValue+0x224> */
/* @0x2089ec mov r2, #0 */
/* @0x2089f0 mov r3, #5 */
/* @0x2089f4 str r2, [r4, #0x8] */
/* @0x2089f8 str r3, [r4, #0xc] */
/* @0x2089fc ldr r3, [r5, #0xc] */
/* @0x208a00 mov r1, #0 */
/* @0x208a04 ldr r2, [r5, #0x8] */
/* @0x208a08 str r1, [r4] */
/* @0x208a0c str r3, [r4, #0xc] */
/* @0x208a10 ldr r3, [r5, #0xc] */
/* @0x208a14 str r2, [r4, #0x8] */
/* @0x208a18 bic r3, r3, #-16777216 */
/* @0x208a1c cmp r3, #14 */
/* @0x208a20 addls pc, pc, r3, lsl #2 */
/* @0x208a24 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a28 b 0x208a70 <_ZN8CDS_List7ReplaceEiP6RValue+0x10c> */
/* @0x208a2c b 0x208acc <_ZN8CDS_List7ReplaceEiP6RValue+0x168> */
/* @0x208a30 b 0x208aa0 <_ZN8CDS_List7ReplaceEiP6RValue+0x13c> */
/* @0x208a34 b 0x208a64 <_ZN8CDS_List7ReplaceEiP6RValue+0x100> */
/* @0x208a38 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a3c b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a40 b 0x208a7c <_ZN8CDS_List7ReplaceEiP6RValue+0x118> */
/* @0x208a44 b 0x208a64 <_ZN8CDS_List7ReplaceEiP6RValue+0x100> */
/* @0x208a48 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a4c b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a50 b 0x208a70 <_ZN8CDS_List7ReplaceEiP6RValue+0x10c> */
/* @0x208a54 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a58 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108> */
/* @0x208a5c b 0x208a70 <_ZN8CDS_List7ReplaceEiP6RValue+0x10c> */
/* @0x208a60 b 0x208a64 <_ZN8CDS_List7ReplaceEiP6RValue+0x100> */
/* @0x208a64 ldr r3, [r5] */
/* @0x208a68 str r3, [r4] */
/* @0x208a6c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208a70 ldm r5, {r2, r3} */
/* @0x208a74 stm r4, {r2, r3} */
/* @0x208a78 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208a7c ldr r3, [r5] */
/* @0x208a80 str r3, [r4] */
/* @0x208a84 ldr r3, [r5] */
/* @0x208a88 cmp r3, #0 */
/* @0x208a8c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208a90 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x208a94 ldr r1, [r5] */
/* @0x208a98 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x208a9c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x208aa0 ldr r3, [r5] */
/* @0x208aa4 cmp r3, #0 */
/* @0x208aa8 str r3, [r4] */
/* @0x208aac popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208ab0 ldr r1, [r3, #0x8] */
/* @0x208ab4 ldr r2, [r3] */
/* @0x208ab8 cmp r1, #0 */
/* @0x208abc streq r4, [r3, #0x8] */
/* @0x208ac0 add r2, r2, #1 */
/* @0x208ac4 str r2, [r3] */
/* @0x208ac8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x208acc ldr r3, [r5] */
/* @0x208ad0 cmp r3, #0 */
/* @0x208ad4 ldrne r2, [r3, #0x4] */
/* @0x208ad8 addne r2, r2, #1 */
/* @0x208adc strne r2, [r3, #0x4] */
/* @0x208ae0 b 0x208a68 <_ZN8CDS_List7ReplaceEiP6RValue+0x104> */
/* @0x208ae4 ldr r6, [r4] */
/* @0x208ae8 cmp r6, #0 */
/* @0x208aec beq 0x208b0c <_ZN8CDS_List7ReplaceEiP6RValue+0x1a8> */
/* @0x208af0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x208af4 ldr r7, [r6, #0x4] */
/* @0x208af8 sub r7, r7, #1 */
/* @0x208afc str r7, [r6, #0x4] */
/* @0x208b00 cmp r7, #0 */
/* @0x208b04 beq 0x208b2c <_ZN8CDS_List7ReplaceEiP6RValue+0x1c8> */
/* @0x208b08 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x208b0c mov r3, #0 */
/* @0x208b10 str r3, [r4] */
/* @0x208b14 b 0x2089fc <_ZN8CDS_List7ReplaceEiP6RValue+0x98> */
/* @0x208b18 mov r0, r7 */
/* @0x208b1c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x208b20 ldr r3, [r8, #0xc] */
/* @0x208b24 add r4, r3, r4 */
/* @0x208b28 b 0x2089ac <_ZN8CDS_List7ReplaceEiP6RValue+0x48> */
/* @0x208b2c ldr r0, [r6] */
/* @0x208b30 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x208b34 str r7, [r6] */
/* @0x208b38 str r7, [r6, #0x8] */
/* @0x208b3c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x208b40 ldr r7, [r6, #0x4] */
/* @0x208b44 sub r7, r7, #1 */
/* @0x208b48 str r7, [r6, #0x4] */
/* @0x208b4c cmp r7, #0 */
/* @0x208b50 beq 0x208b64 <_ZN8CDS_List7ReplaceEiP6RValue+0x200> */
/* @0x208b54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x208b58 mov r0, r6 */
/* @0x208b5c bl 0x27d1d0 <_ZdlPv> */
/* @0x208b60 b 0x208b08 <_ZN8CDS_List7ReplaceEiP6RValue+0x1a4> */
/* @0x208b64 ldr r0, [r6] */
/* @0x208b68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x208b6c mov r0, r6 */
/* @0x208b70 str r7, [r6] */
/* @0x208b74 str r7, [r6, #0x8] */
/* @0x208b78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x208b7c mov r0, r6 */
/* @0x208b80 bl 0x27d1d0 <_ZdlPv> */
/* @0x208b84 b 0x208b54 <_ZN8CDS_List7ReplaceEiP6RValue+0x1f0> */
/* @0x208b88 mov r0, r4 */
/* @0x208b8c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x208b90 b 0x2089ec <_ZN8CDS_List7ReplaceEiP6RValue+0x88> */

/* ── FUNC 0x208b94 · CDS_List::Delete(int) · size=168 · insn=42 */
/* @0x208b94 push {r3, r4, r5, r6, r7, lr} */
/* @0x208b98 subs r6, r1, #0 */
/* @0x208b9c mov r4, r0 */
/* @0x208ba0 poplt {r3, r4, r5, r6, r7, pc} */
/* @0x208ba4 ldr r3, [r0, #0x4] */
/* @0x208ba8 cmp r6, r3 */
/* @0x208bac popge {r3, r4, r5, r6, r7, pc} */
/* @0x208bb0 ldr r12, [r0, #0xc] */
/* @0x208bb4 lsl r7, r6, #4 */
/* @0x208bb8 add r5, r12, r7 */
/* @0x208bbc ldr r2, [r5, #0xc] */
/* @0x208bc0 mov r0, r5 */
/* @0x208bc4 sub r2, r2, #1 */
/* @0x208bc8 bic r2, r2, #-16777216 */
/* @0x208bcc bic r2, r2, #3 */
/* @0x208bd0 cmp r2, #0 */
/* @0x208bd4 beq 0x208c28 <_ZN8CDS_List6DeleteEi+0x94> */
/* @0x208bd8 sub r3, r3, #1 */
/* @0x208bdc add r1, r7, #16 */
/* @0x208be0 rsb r2, r6, r3 */
/* @0x208be4 mov r7, #0 */
/* @0x208be8 mov r3, #5 */
/* @0x208bec add r1, r12, r1 */
/* @0x208bf0 lsl r2, r2, #4 */
/* @0x208bf4 str r3, [r5, #0xc] */
/* @0x208bf8 str r7, [r5, #0x8] */
/* @0x208bfc str r7, [r5] */
/* @0x208c00 bl 0xb6694 <memmove@plt> */
/* @0x208c04 ldr r1, [r4, #0x4] */
/* @0x208c08 ldr r3, [r4, #0xc] */
/* @0x208c0c sub r2, r1, #-268435455 */
/* @0x208c10 sub r1, r1, #1 */
/* @0x208c14 add r0, r3, r2, lsl #4 */
/* @0x208c18 str r7, [r3, r2, lsl #4] */
/* @0x208c1c str r7, [r0, #0xc] */
/* @0x208c20 str r1, [r4, #0x4] */
/* @0x208c24 pop {r3, r4, r5, r6, r7, pc} */
/* @0x208c28 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x208c2c ldr r12, [r4, #0xc] */
/* @0x208c30 ldr r3, [r4, #0x4] */
/* @0x208c34 add r0, r12, r7 */
/* @0x208c38 b 0x208bd8 <_ZN8CDS_List6DeleteEi+0x44> */

/* ── FUNC 0x208c3c · CDS_Map::Set(RValue*, RValue*, RValue*) · size=2860 · insn=715 */
/* @0x208c3c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x208c40 sub sp, sp, #8 */
/* @0x208c44 mov r7, r2 */
/* @0x208c48 mov r6, r3 */
/* @0x208c4c mov r8, r0 */
/* @0x208c50 mov r9, r1 */
/* @0x208c54 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x208c58 subs r4, r0, #0 */
/* @0x208c5c beq 0x209204 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5c8> */
/* @0x208c60 cmp r6, #0 */
/* @0x208c64 beq 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208c68 ldr r2, [r6, #0xc] */
/* @0x208c6c bic r3, r2, #-16777216 */
/* @0x208c70 cmp r3, #1 */
/* @0x208c74 beq 0x208f7c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x340> */
/* @0x208c78 cmp r3, #2 */
/* @0x208c7c bne 0x208ca4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x68> */
/* @0x208c80 sub r2, r2, #1 */
/* @0x208c84 bic r2, r2, #-16777216 */
/* @0x208c88 bic r2, r2, #3 */
/* @0x208c8c cmp r2, #0 */
/* @0x208c90 beq 0x2091e0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5a4> */
/* @0x208c94 mov r2, #0 */
/* @0x208c98 mov r3, #5 */
/* @0x208c9c str r2, [r6, #0x8] */
/* @0x208ca0 str r3, [r6, #0xc] */
/* @0x208ca4 ldr r3, [r4, #0x1c] */
/* @0x208ca8 mov r1, #0 */
/* @0x208cac ldr r2, [r4, #0x18] */
/* @0x208cb0 str r1, [r6] */
/* @0x208cb4 str r3, [r6, #0xc] */
/* @0x208cb8 ldr r3, [r4, #0x1c] */
/* @0x208cbc str r2, [r6, #0x8] */
/* @0x208cc0 bic r3, r3, #-16777216 */
/* @0x208cc4 cmp r3, #14 */
/* @0x208cc8 addls pc, pc, r3, lsl #2 */
/* @0x208ccc b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208cd0 b 0x208fb0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x374> */
/* @0x208cd4 b 0x209140 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x504> */
/* @0x208cd8 b 0x209158 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x51c> */
/* @0x208cdc b 0x208d0c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd0> */
/* @0x208ce0 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208ce4 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208ce8 b 0x209184 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x548> */
/* @0x208cec b 0x208d0c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd0> */
/* @0x208cf0 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208cf4 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208cf8 b 0x208fb0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x374> */
/* @0x208cfc b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208d00 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208d04 b 0x208fb0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x374> */
/* @0x208d08 b 0x208d0c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd0> */
/* @0x208d0c ldr r3, [r4, #0x10] */
/* @0x208d10 str r3, [r6] */
/* @0x208d14 ldr r2, [r4, #0xc] */
/* @0x208d18 bic r3, r2, #-16777216 */
/* @0x208d1c cmp r3, #1 */
/* @0x208d20 beq 0x208f14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2d8> */
/* @0x208d24 cmp r3, #2 */
/* @0x208d28 bne 0x208d50 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x114> */
/* @0x208d2c sub r2, r2, #1 */
/* @0x208d30 bic r2, r2, #-16777216 */
/* @0x208d34 bic r2, r2, #3 */
/* @0x208d38 cmp r2, #0 */
/* @0x208d3c beq 0x2091ec <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5b0> */
/* @0x208d40 mov r2, #0 */
/* @0x208d44 mov r3, #5 */
/* @0x208d48 str r2, [r4, #0x8] */
/* @0x208d4c str r3, [r4, #0xc] */
/* @0x208d50 ldr r3, [r9, #0xc] */
/* @0x208d54 mov r1, #0 */
/* @0x208d58 ldr r2, [r9, #0x8] */
/* @0x208d5c str r1, [r4] */
/* @0x208d60 str r3, [r4, #0xc] */
/* @0x208d64 ldr r3, [r9, #0xc] */
/* @0x208d68 str r2, [r4, #0x8] */
/* @0x208d6c bic r3, r3, #-16777216 */
/* @0x208d70 cmp r3, #14 */
/* @0x208d74 addls pc, pc, r3, lsl #2 */
/* @0x208d78 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208d7c b 0x208f08 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2cc> */
/* @0x208d80 b 0x208fc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x384> */
/* @0x208d84 b 0x209040 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x404> */
/* @0x208d88 b 0x208db8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x17c> */
/* @0x208d8c b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208d90 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208d94 b 0x20906c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x430> */
/* @0x208d98 b 0x208db8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x17c> */
/* @0x208d9c b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208da0 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208da4 b 0x208f08 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2cc> */
/* @0x208da8 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208dac b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208db0 b 0x208f08 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2cc> */
/* @0x208db4 b 0x208db8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x17c> */
/* @0x208db8 ldr r3, [r9] */
/* @0x208dbc str r3, [r4] */
/* @0x208dc0 ldr r2, [r4, #0x1c] */
/* @0x208dc4 add r5, r4, #16 */
/* @0x208dc8 bic r3, r2, #-16777216 */
/* @0x208dcc cmp r3, #1 */
/* @0x208dd0 beq 0x208f48 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x30c> */
/* @0x208dd4 cmp r3, #2 */
/* @0x208dd8 bne 0x208e00 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x1c4> */
/* @0x208ddc sub r2, r2, #1 */
/* @0x208de0 bic r2, r2, #-16777216 */
/* @0x208de4 bic r2, r2, #3 */
/* @0x208de8 cmp r2, #0 */
/* @0x208dec beq 0x2091f8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5bc> */
/* @0x208df0 mov r2, #0 */
/* @0x208df4 mov r3, #5 */
/* @0x208df8 str r2, [r4, #0x18] */
/* @0x208dfc str r3, [r4, #0x1c] */
/* @0x208e00 ldr r3, [r7, #0xc] */
/* @0x208e04 mov r1, #0 */
/* @0x208e08 ldr r2, [r7, #0x8] */
/* @0x208e0c str r1, [r4, #0x10] */
/* @0x208e10 str r3, [r4, #0x1c] */
/* @0x208e14 ldr r3, [r7, #0xc] */
/* @0x208e18 str r2, [r4, #0x18] */
/* @0x208e1c bic r3, r3, #-16777216 */
/* @0x208e20 cmp r3, #14 */
/* @0x208e24 addls pc, pc, r3, lsl #2 */
/* @0x208e28 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e2c b 0x208ef4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2b8> */
/* @0x208e30 b 0x208fd8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x39c> */
/* @0x208e34 b 0x208ff0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x3b4> */
/* @0x208e38 b 0x208ee4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a8> */
/* @0x208e3c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e40 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e44 b 0x20901c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x3e0> */
/* @0x208e48 b 0x208ee4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a8> */
/* @0x208e4c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e50 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e54 b 0x208ef4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2b8> */
/* @0x208e58 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e5c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x208e60 b 0x208ef4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2b8> */
/* @0x208e64 b 0x208ee4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a8> */
/* @0x208e68 ldr r3, [r7] */
/* @0x208e6c str r3, [r4, #0x10] */
/* @0x208e70 ldr r5, [r8] */
/* @0x208e74 movw r2, #0x132 */
/* @0x208e78 ldr r1, [pc, #0x8e4] */
/* @0x208e7c mov r3, #1 */
/* @0x208e80 mov r0, #16 */
/* @0x208e84 add r1, pc, r1 */
/* @0x208e88 ldm r5, {r6, r7} */
/* @0x208e8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x208e90 and r7, r10, r7 */
/* @0x208e94 ldr r2, [r6, r7, lsl #3] */
/* @0x208e98 add r3, r6, r7, lsl #3 */
/* @0x208e9c cmp r2, #0 */
/* @0x208ea0 ldrne r2, [r3, #0x4] */
/* @0x208ea4 movne r1, #0 */
/* @0x208ea8 str r10, [r0, #0x8] */
/* @0x208eac str r4, [r0, #0xc] */
/* @0x208eb0 strne r2, [r0] */
/* @0x208eb4 streq r0, [r3, #0x4] */
/* @0x208eb8 strne r0, [r2, #0x4] */
/* @0x208ebc strne r0, [r3, #0x4] */
/* @0x208ec0 ldr r3, [r5, #0x8] */
/* @0x208ec4 streq r0, [r6, r7, lsl #3] */
/* @0x208ec8 strne r1, [r0, #0x4] */
/* @0x208ecc add r3, r3, #1 */
/* @0x208ed0 streq r2, [r0, #0x4] */
/* @0x208ed4 streq r2, [r0] */
/* @0x208ed8 str r3, [r5, #0x8] */
/* @0x208edc add sp, sp, #8 */
/* @0x208ee0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x208ee4 ldr r3, [r7] */
/* @0x208ee8 str r3, [r4, #0x10] */
/* @0x208eec add sp, sp, #8 */
/* @0x208ef0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x208ef4 ldm r7, {r2, r3} */
/* @0x208ef8 str r2, [r4, #0x10] */
/* @0x208efc str r3, [r4, #0x14] */
/* @0x208f00 add sp, sp, #8 */
/* @0x208f04 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x208f08 ldm r9, {r2, r3} */
/* @0x208f0c stm r4, {r2, r3} */
/* @0x208f10 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x208f14 ldr r5, [r4] */
/* @0x208f18 cmp r5, #0 */
/* @0x208f1c beq 0x208f3c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x300> */
/* @0x208f20 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x208f24 ldr r6, [r5, #0x4] */
/* @0x208f28 sub r6, r6, #1 */
/* @0x208f2c str r6, [r5, #0x4] */
/* @0x208f30 cmp r6, #0 */
/* @0x208f34 beq 0x209090 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x454> */
/* @0x208f38 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x208f3c mov r3, #0 */
/* @0x208f40 str r3, [r4] */
/* @0x208f44 b 0x208d50 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x114> */
/* @0x208f48 ldr r6, [r4, #0x10] */
/* @0x208f4c cmp r6, #0 */
/* @0x208f50 beq 0x208f70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x334> */
/* @0x208f54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x208f58 ldr r8, [r6, #0x4] */
/* @0x208f5c sub r8, r8, #1 */
/* @0x208f60 str r8, [r6, #0x4] */
/* @0x208f64 cmp r8, #0 */
/* @0x208f68 beq 0x2090e8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x4ac> */
/* @0x208f6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x208f70 mov r3, #0 */
/* @0x208f74 str r3, [r4, #0x10] */
/* @0x208f78 b 0x208e00 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x1c4> */
/* @0x208f7c ldr r5, [r6] */
/* @0x208f80 cmp r5, #0 */
/* @0x208f84 beq 0x208fa4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x368> */
/* @0x208f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x208f8c ldr r8, [r5, #0x4] */
/* @0x208f90 sub r8, r8, #1 */
/* @0x208f94 str r8, [r5, #0x4] */
/* @0x208f98 cmp r8, #0 */
/* @0x208f9c beq 0x2091a8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x56c> */
/* @0x208fa0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x208fa4 mov r3, #0 */
/* @0x208fa8 str r3, [r6] */
/* @0x208fac b 0x208ca4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x68> */
/* @0x208fb0 ldr r2, [r4, #0x10] */
/* @0x208fb4 ldr r3, [r4, #0x14] */
/* @0x208fb8 stm r6, {r2, r3} */
/* @0x208fbc b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x208fc0 ldr r3, [r9] */
/* @0x208fc4 cmp r3, #0 */
/* @0x208fc8 ldrne r2, [r3, #0x4] */
/* @0x208fcc addne r2, r2, #1 */
/* @0x208fd0 strne r2, [r3, #0x4] */
/* @0x208fd4 b 0x208dbc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x180> */
/* @0x208fd8 ldr r3, [r7] */
/* @0x208fdc cmp r3, #0 */
/* @0x208fe0 ldrne r2, [r3, #0x4] */
/* @0x208fe4 addne r2, r2, #1 */
/* @0x208fe8 strne r2, [r3, #0x4] */
/* @0x208fec b 0x208ee8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2ac> */
/* @0x208ff0 ldr r3, [r7] */
/* @0x208ff4 cmp r3, #0 */
/* @0x208ff8 str r3, [r4, #0x10] */
/* @0x208ffc beq 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x209000 ldr r1, [r3, #0x8] */
/* @0x209004 ldr r2, [r3] */
/* @0x209008 cmp r1, #0 */
/* @0x20900c streq r5, [r3, #0x8] */
/* @0x209010 add r2, r2, #1 */
/* @0x209014 str r2, [r3] */
/* @0x209018 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x20901c ldr r3, [r7] */
/* @0x209020 str r3, [r4, #0x10] */
/* @0x209024 ldr r3, [r7] */
/* @0x209028 cmp r3, #0 */
/* @0x20902c beq 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x209030 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x209034 ldr r1, [r7] */
/* @0x209038 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20903c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0> */
/* @0x209040 ldr r3, [r9] */
/* @0x209044 cmp r3, #0 */
/* @0x209048 str r3, [r4] */
/* @0x20904c beq 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x209050 ldr r1, [r3, #0x8] */
/* @0x209054 ldr r2, [r3] */
/* @0x209058 cmp r1, #0 */
/* @0x20905c streq r4, [r3, #0x8] */
/* @0x209060 add r2, r2, #1 */
/* @0x209064 str r2, [r3] */
/* @0x209068 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x20906c ldr r3, [r9] */
/* @0x209070 str r3, [r4] */
/* @0x209074 ldr r3, [r9] */
/* @0x209078 cmp r3, #0 */
/* @0x20907c beq 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x209080 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x209084 ldr r1, [r9] */
/* @0x209088 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20908c b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184> */
/* @0x209090 ldr r0, [r5] */
/* @0x209094 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209098 str r6, [r5] */
/* @0x20909c str r6, [r5, #0x8] */
/* @0x2090a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2090a4 ldr r6, [r5, #0x4] */
/* @0x2090a8 sub r6, r6, #1 */
/* @0x2090ac str r6, [r5, #0x4] */
/* @0x2090b0 cmp r6, #0 */
/* @0x2090b4 bne 0x2090d8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x49c> */
/* @0x2090b8 ldr r0, [r5] */
/* @0x2090bc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2090c0 mov r0, r5 */
/* @0x2090c4 str r6, [r5] */
/* @0x2090c8 str r6, [r5, #0x8] */
/* @0x2090cc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2090d0 mov r0, r5 */
/* @0x2090d4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2090d8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2090dc mov r0, r5 */
/* @0x2090e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2090e4 b 0x208f38 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2fc> */
/* @0x2090e8 ldr r0, [r6] */
/* @0x2090ec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2090f0 str r8, [r6] */
/* @0x2090f4 str r8, [r6, #0x8] */
/* @0x2090f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2090fc ldr r8, [r6, #0x4] */
/* @0x209100 sub r8, r8, #1 */
/* @0x209104 str r8, [r6, #0x4] */
/* @0x209108 cmp r8, #0 */
/* @0x20910c bne 0x209130 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x4f4> */
/* @0x209110 ldr r0, [r6] */
/* @0x209114 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209118 mov r0, r6 */
/* @0x20911c str r8, [r6] */
/* @0x209120 str r8, [r6, #0x8] */
/* @0x209124 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x209128 mov r0, r6 */
/* @0x20912c bl 0x27d1d0 <_ZdlPv> */
/* @0x209130 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209134 mov r0, r6 */
/* @0x209138 bl 0x27d1d0 <_ZdlPv> */
/* @0x20913c b 0x208f6c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x330> */
/* @0x209140 ldr r3, [r4, #0x10] */
/* @0x209144 cmp r3, #0 */
/* @0x209148 ldrne r2, [r3, #0x4] */
/* @0x20914c addne r2, r2, #1 */
/* @0x209150 strne r2, [r3, #0x4] */
/* @0x209154 b 0x208d10 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd4> */
/* @0x209158 ldr r3, [r4, #0x10] */
/* @0x20915c cmp r3, #0 */
/* @0x209160 str r3, [r6] */
/* @0x209164 beq 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x209168 ldr r1, [r3, #0x8] */
/* @0x20916c ldr r2, [r3] */
/* @0x209170 cmp r1, #0 */
/* @0x209174 streq r6, [r3, #0x8] */
/* @0x209178 add r2, r2, #1 */
/* @0x20917c str r2, [r3] */
/* @0x209180 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x209184 ldr r3, [r4, #0x10] */
/* @0x209188 str r3, [r6] */
/* @0x20918c ldr r3, [r4, #0x10] */
/* @0x209190 cmp r3, #0 */
/* @0x209194 beq 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x209198 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20919c ldr r1, [r4, #0x10] */
/* @0x2091a0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2091a4 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8> */
/* @0x2091a8 ldr r0, [r5] */
/* @0x2091ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2091b0 str r8, [r5] */
/* @0x2091b4 str r8, [r5, #0x8] */
/* @0x2091b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2091bc ldr r8, [r5, #0x4] */
/* @0x2091c0 sub r8, r8, #1 */
/* @0x2091c4 str r8, [r5, #0x4] */
/* @0x2091c8 cmp r8, #0 */
/* @0x2091cc beq 0x2092f0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6b4> */
/* @0x2091d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2091d4 mov r0, r5 */
/* @0x2091d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2091dc b 0x208fa0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x364> */
/* @0x2091e0 mov r0, r6 */
/* @0x2091e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2091e8 b 0x208c94 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x58> */
/* @0x2091ec mov r0, r4 */
/* @0x2091f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2091f4 b 0x208d40 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x104> */
/* @0x2091f8 mov r0, r5 */
/* @0x2091fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x209200 b 0x208df0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x1b4> */
/* @0x209204 ldr r3, [r9, #0xc] */
/* @0x209208 bic r3, r3, #-16777216 */
/* @0x20920c cmp r3, #6 */
/* @0x209210 beq 0x209640 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa04> */
/* @0x209214 bgt 0x209314 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6d8> */
/* @0x209218 cmp r3, #4 */
/* @0x20921c bgt 0x20932c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f0> */
/* @0x209220 cmp r3, #2 */
/* @0x209224 bge 0x209640 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa04> */
/* @0x209228 cmp r3, #1 */
/* @0x20922c bne 0x209654 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa18> */
/* @0x209230 ldr r0, [r9] */
/* @0x209234 cmp r0, #0 */
/* @0x209238 ldrne r0, [r0] */
/* @0x20923c bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x209240 mov r10, r0 */
/* @0x209244 cmp r6, #0 */
/* @0x209248 beq 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x20924c ldr r2, [r6, #0xc] */
/* @0x209250 bic r3, r2, #-16777216 */
/* @0x209254 cmp r3, #1 */
/* @0x209258 beq 0x209600 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9c4> */
/* @0x20925c cmp r3, #2 */
/* @0x209260 bne 0x209288 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x64c> */
/* @0x209264 sub r3, r2, #1 */
/* @0x209268 bic r3, r3, #-16777216 */
/* @0x20926c bic r3, r3, #3 */
/* @0x209270 cmp r3, #0 */
/* @0x209274 beq 0x2096bc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa80> */
/* @0x209278 mov r2, #0 */
/* @0x20927c mov r3, #5 */
/* @0x209280 str r2, [r6, #0x8] */
/* @0x209284 str r3, [r6, #0xc] */
/* @0x209288 ldr r3, [r7, #0xc] */
/* @0x20928c mov r1, #0 */
/* @0x209290 ldr r2, [r7, #0x8] */
/* @0x209294 str r1, [r6] */
/* @0x209298 str r3, [r6, #0xc] */
/* @0x20929c ldr r3, [r7, #0xc] */
/* @0x2092a0 str r2, [r6, #0x8] */
/* @0x2092a4 bic r3, r3, #-16777216 */
/* @0x2092a8 cmp r3, #14 */
/* @0x2092ac addls pc, pc, r3, lsl #2 */
/* @0x2092b0 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092b4 b 0x2094a4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x868> */
/* @0x2092b8 b 0x2095d0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x994> */
/* @0x2092bc b 0x209580 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x944> */
/* @0x2092c0 b 0x209334 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f8> */
/* @0x2092c4 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092c8 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092cc b 0x2095ac <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x970> */
/* @0x2092d0 b 0x209334 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f8> */
/* @0x2092d4 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092d8 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092dc b 0x2094a4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x868> */
/* @0x2092e0 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092e4 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2092e8 b 0x2094a4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x868> */
/* @0x2092ec b 0x209334 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f8> */
/* @0x2092f0 ldr r0, [r5] */
/* @0x2092f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2092f8 mov r0, r5 */
/* @0x2092fc str r8, [r5] */
/* @0x209300 str r8, [r5, #0x8] */
/* @0x209304 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x209308 mov r0, r5 */
/* @0x20930c bl 0x27d1d0 <_ZdlPv> */
/* @0x209310 b 0x2091d0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x594> */
/* @0x209314 cmp r3, #11 */
/* @0x209318 beq 0x209640 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa04> */
/* @0x20931c ble 0x209634 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9f8> */
/* @0x209320 mvn r2, #-16777216 */
/* @0x209324 cmp r3, r2 */
/* @0x209328 bne 0x209654 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa18> */
/* @0x20932c mov r10, #0 */
/* @0x209330 b 0x209244 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x608> */
/* @0x209334 ldr r3, [r7] */
/* @0x209338 str r3, [r6] */
/* @0x20933c mov r0, #32 */
/* @0x209340 bl 0x27c524 <_Znwj> */
/* @0x209344 mov r1, #0 */
/* @0x209348 mov r2, #16 */
/* @0x20934c add r5, r0, #16 */
/* @0x209350 mov r4, r0 */
/* @0x209354 bl 0xb65b0 <memset@plt> */
/* @0x209358 mov r1, #0 */
/* @0x20935c mov r0, r5 */
/* @0x209360 mov r2, #16 */
/* @0x209364 bl 0xb65b0 <memset@plt> */
/* @0x209368 ldr r3, [r4, #0xc] */
/* @0x20936c sub r3, r3, #1 */
/* @0x209370 bic r3, r3, #-16777216 */
/* @0x209374 bic r3, r3, #3 */
/* @0x209378 cmp r3, #0 */
/* @0x20937c beq 0x2095e8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9ac> */
/* @0x209380 mov r3, #5 */
/* @0x209384 str r3, [r4, #0xc] */
/* @0x209388 ldr r3, [r9, #0xc] */
/* @0x20938c mov r2, #0 */
/* @0x209390 str r2, [r4, #0x8] */
/* @0x209394 ldr r1, [r9, #0x8] */
/* @0x209398 str r3, [r4, #0xc] */
/* @0x20939c ldr r3, [r9, #0xc] */
/* @0x2093a0 str r2, [r4] */
/* @0x2093a4 bic r3, r3, #-16777216 */
/* @0x2093a8 str r1, [r4, #0x8] */
/* @0x2093ac cmp r3, #14 */
/* @0x2093b0 addls pc, pc, r3, lsl #2 */
/* @0x2093b4 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093b8 b 0x209488 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x84c> */
/* @0x2093bc b 0x209568 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x92c> */
/* @0x2093c0 b 0x20953c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x900> */
/* @0x2093c4 b 0x2093f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7b8> */
/* @0x2093c8 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093cc b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093d0 b 0x209518 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x8dc> */
/* @0x2093d4 b 0x2093f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7b8> */
/* @0x2093d8 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093dc b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093e0 b 0x209488 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x84c> */
/* @0x2093e4 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093e8 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x2093ec b 0x209488 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x84c> */
/* @0x2093f0 b 0x2093f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7b8> */
/* @0x2093f4 ldr r3, [r9] */
/* @0x2093f8 str r3, [r4] */
/* @0x2093fc ldr r3, [r4, #0x1c] */
/* @0x209400 sub r3, r3, #1 */
/* @0x209404 bic r3, r3, #-16777216 */
/* @0x209408 bic r3, r3, #3 */
/* @0x20940c cmp r3, #0 */
/* @0x209410 beq 0x2095f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9b8> */
/* @0x209414 mov r3, #5 */
/* @0x209418 str r3, [r4, #0x1c] */
/* @0x20941c ldr r3, [r7, #0xc] */
/* @0x209420 mov r2, #0 */
/* @0x209424 str r2, [r4, #0x18] */
/* @0x209428 ldr r1, [r7, #0x8] */
/* @0x20942c str r3, [r4, #0x1c] */
/* @0x209430 ldr r3, [r7, #0xc] */
/* @0x209434 str r2, [r4, #0x10] */
/* @0x209438 bic r3, r3, #-16777216 */
/* @0x20943c str r1, [r4, #0x18] */
/* @0x209440 cmp r3, #14 */
/* @0x209444 addls pc, pc, r3, lsl #2 */
/* @0x209448 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x20944c b 0x209494 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x858> */
/* @0x209450 b 0x209500 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x8c4> */
/* @0x209454 b 0x2094d4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x898> */
/* @0x209458 b 0x208e68 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x22c> */
/* @0x20945c b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x209460 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x209464 b 0x2094b0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x874> */
/* @0x209468 b 0x208e68 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x22c> */
/* @0x20946c b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x209470 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x209474 b 0x209494 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x858> */
/* @0x209478 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x20947c b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x209480 b 0x209494 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x858> */
/* @0x209484 b 0x208e68 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x22c> */
/* @0x209488 ldm r9, {r2, r3} */
/* @0x20948c stm r4, {r2, r3} */
/* @0x209490 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x209494 ldm r7, {r2, r3} */
/* @0x209498 str r2, [r4, #0x10] */
/* @0x20949c str r3, [r4, #0x14] */
/* @0x2094a0 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x2094a4 ldm r7, {r2, r3} */
/* @0x2094a8 stm r6, {r2, r3} */
/* @0x2094ac b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2094b0 ldr r3, [r7] */
/* @0x2094b4 str r3, [r4, #0x10] */
/* @0x2094b8 ldr r3, [r7] */
/* @0x2094bc cmp r3, #0 */
/* @0x2094c0 beq 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x2094c4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2094c8 ldr r1, [r7] */
/* @0x2094cc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2094d0 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x2094d4 ldr r3, [r7] */
/* @0x2094d8 cmp r3, #0 */
/* @0x2094dc str r3, [r4, #0x10] */
/* @0x2094e0 beq 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x2094e4 ldr r1, [r3, #0x8] */
/* @0x2094e8 ldr r2, [r3] */
/* @0x2094ec cmp r1, #0 */
/* @0x2094f0 streq r5, [r3, #0x8] */
/* @0x2094f4 add r2, r2, #1 */
/* @0x2094f8 str r2, [r3] */
/* @0x2094fc b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234> */
/* @0x209500 ldr r3, [r7] */
/* @0x209504 cmp r3, #0 */
/* @0x209508 ldrne r2, [r3, #0x4] */
/* @0x20950c addne r2, r2, #1 */
/* @0x209510 strne r2, [r3, #0x4] */
/* @0x209514 b 0x208e6c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x230> */
/* @0x209518 ldr r3, [r9] */
/* @0x20951c str r3, [r4] */
/* @0x209520 ldr r3, [r9] */
/* @0x209524 cmp r3, #0 */
/* @0x209528 beq 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x20952c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x209530 ldr r1, [r9] */
/* @0x209534 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x209538 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x20953c ldr r3, [r9] */
/* @0x209540 cmp r3, #0 */
/* @0x209544 str r3, [r4] */
/* @0x209548 beq 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x20954c ldr r1, [r3, #0x8] */
/* @0x209550 ldr r2, [r3] */
/* @0x209554 cmp r1, #0 */
/* @0x209558 streq r4, [r3, #0x8] */
/* @0x20955c add r2, r2, #1 */
/* @0x209560 str r2, [r3] */
/* @0x209564 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0> */
/* @0x209568 ldr r3, [r9] */
/* @0x20956c cmp r3, #0 */
/* @0x209570 ldrne r2, [r3, #0x4] */
/* @0x209574 addne r2, r2, #1 */
/* @0x209578 strne r2, [r3, #0x4] */
/* @0x20957c b 0x2093f8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7bc> */
/* @0x209580 ldr r3, [r7] */
/* @0x209584 cmp r3, #0 */
/* @0x209588 str r3, [r6] */
/* @0x20958c beq 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x209590 ldr r1, [r3, #0x8] */
/* @0x209594 ldr r2, [r3] */
/* @0x209598 cmp r1, #0 */
/* @0x20959c streq r6, [r3, #0x8] */
/* @0x2095a0 add r2, r2, #1 */
/* @0x2095a4 str r2, [r3] */
/* @0x2095a8 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2095ac ldr r3, [r7] */
/* @0x2095b0 str r3, [r6] */
/* @0x2095b4 ldr r3, [r7] */
/* @0x2095b8 cmp r3, #0 */
/* @0x2095bc beq 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2095c0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2095c4 ldr r1, [r7] */
/* @0x2095c8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2095cc b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700> */
/* @0x2095d0 ldr r3, [r7] */
/* @0x2095d4 cmp r3, #0 */
/* @0x2095d8 ldrne r2, [r3, #0x4] */
/* @0x2095dc addne r2, r2, #1 */
/* @0x2095e0 strne r2, [r3, #0x4] */
/* @0x2095e4 b 0x209338 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6fc> */
/* @0x2095e8 mov r0, r4 */
/* @0x2095ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2095f0 b 0x209380 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x744> */
/* @0x2095f4 mov r0, r5 */
/* @0x2095f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2095fc b 0x209414 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7d8> */
/* @0x209600 ldr r4, [r6] */
/* @0x209604 cmp r4, #0 */
/* @0x209608 beq 0x209628 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9ec> */
/* @0x20960c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209610 ldr r5, [r4, #0x4] */
/* @0x209614 sub r5, r5, #1 */
/* @0x209618 str r5, [r4, #0x4] */
/* @0x20961c cmp r5, #0 */
/* @0x209620 beq 0x209684 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa48> */
/* @0x209624 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209628 mov r3, #0 */
/* @0x20962c str r3, [r6] */
/* @0x209630 b 0x209288 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x64c> */
/* @0x209634 sub r2, r3, #8 */
/* @0x209638 cmp r2, #1 */
/* @0x20963c bhi 0x209654 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa18> */
/* @0x209640 mov r0, r9 */
/* @0x209644 mov r1, #8 */
/* @0x209648 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20964c mov r10, r0 */
/* @0x209650 b 0x209244 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x608> */
/* @0x209654 cmp r3, #0 */
/* @0x209658 bne 0x2096c8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa8c> */
/* @0x20965c ldm r9, {r0, r1} */
/* @0x209660 mov r4, r0 */
/* @0x209664 add r0, sp, #8 */
/* @0x209668 mov r5, r1 */
/* @0x20966c mov r1, #8 */
/* @0x209670 strd r4, r5, [r0, #-8]! */
/* @0x209674 mov r0, sp */
/* @0x209678 bl 0x27dfa0 <_Z7CalcCRCPKci> */
/* @0x20967c mov r10, r0 */
/* @0x209680 b 0x209244 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x608> */
/* @0x209684 ldr r0, [r4] */
/* @0x209688 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20968c str r5, [r4] */
/* @0x209690 str r5, [r4, #0x8] */
/* @0x209694 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209698 ldr r5, [r4, #0x4] */
/* @0x20969c sub r5, r5, #1 */
/* @0x2096a0 str r5, [r4, #0x4] */
/* @0x2096a4 cmp r5, #0 */
/* @0x2096a8 beq 0x2096d4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa98> */
/* @0x2096ac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2096b0 mov r0, r4 */
/* @0x2096b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2096b8 b 0x209624 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9e8> */
/* @0x2096bc mov r0, r6 */
/* @0x2096c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2096c4 b 0x209278 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x63c> */
/* @0x2096c8 mov r0, r9 */
/* @0x2096cc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x2096d0 b 0x209660 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa24> */
/* @0x2096d4 ldr r0, [r4] */
/* @0x2096d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2096dc str r5, [r4] */
/* @0x2096e0 str r5, [r4, #0x8] */
/* @0x2096e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2096e8 ldr r5, [r4, #0x4] */
/* @0x2096ec sub r5, r5, #1 */
/* @0x2096f0 str r5, [r4, #0x4] */
/* @0x2096f4 cmp r5, #0 */
/* @0x2096f8 beq 0x20970c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xad0> */
/* @0x2096fc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209700 mov r0, r4 */
/* @0x209704 bl 0x27d1d0 <_ZdlPv> */
/* @0x209708 b 0x2096ac <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa70> */
/* @0x20970c ldr r0, [r4] */
/* @0x209710 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x209714 str r5, [r4] */
/* @0x209718 str r5, [r4, #0x8] */
/* @0x20971c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x209720 ldr r5, [r4, #0x4] */
/* @0x209724 sub r5, r5, #1 */
/* @0x209728 str r5, [r4, #0x4] */
/* @0x20972c cmp r5, #0 */
/* @0x209730 bne 0x209754 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xb18> */
/* @0x209734 ldr r0, [r4] */
/* @0x209738 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20973c mov r0, r4 */
/* @0x209740 str r5, [r4] */
/* @0x209744 str r5, [r4, #0x8] */
/* @0x209748 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20974c mov r0, r4 */
/* @0x209750 bl 0x27d1d0 <_ZdlPv> */
/* @0x209754 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x209758 mov r0, r4 */
/* @0x20975c bl 0x27d1d0 <_ZdlPv> */
/* @0x209760 b 0x2096fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xac0> */
/* @0x209764 andseq r3, r4, r8, lsr #28 */

/* ── FUNC 0x209768 · CDS_Priority::Clear() · size=252 · insn=63 */
/* @0x209768 ldr r3, [r0, #0x8] */
/* @0x20976c push {r4, r5, r6, r7, r8, lr} */
/* @0x209770 mov r5, #0 */
/* @0x209774 cmp r3, r5 */
/* @0x209778 mov r6, r0 */
/* @0x20977c str r5, [r0, #0x4] */
/* @0x209780 movgt r7, r5 */
/* @0x209784 ldr r0, [r0, #0xc] */
/* @0x209788 movgt r8, #5 */
/* @0x20978c bgt 0x2097ac <_ZN12CDS_Priority5ClearEv+0x44> */
/* @0x209790 b 0x2097dc <_ZN12CDS_Priority5ClearEv+0x74> */
/* @0x209794 str r7, [r4] */
/* @0x209798 ldr r3, [r6, #0x8] */
/* @0x20979c str r7, [r4, #0x8] */
/* @0x2097a0 cmp r3, r5 */
/* @0x2097a4 str r8, [r4, #0xc] */
/* @0x2097a8 ble 0x2097dc <_ZN12CDS_Priority5ClearEv+0x74> */
/* @0x2097ac add r4, r0, r5, lsl #4 */
/* @0x2097b0 add r5, r5, #1 */
/* @0x2097b4 ldr r3, [r4, #0xc] */
/* @0x2097b8 sub r3, r3, #1 */
/* @0x2097bc bic r3, r3, #-16777216 */
/* @0x2097c0 bic r3, r3, #3 */
/* @0x2097c4 cmp r3, #0 */
/* @0x2097c8 bne 0x209794 <_ZN12CDS_Priority5ClearEv+0x2c> */
/* @0x2097cc mov r0, r4 */
/* @0x2097d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2097d4 ldr r0, [r6, #0xc] */
/* @0x2097d8 b 0x209794 <_ZN12CDS_Priority5ClearEv+0x2c> */
/* @0x2097dc mov r5, #0 */
/* @0x2097e0 str r5, [r6, #0x8] */
/* @0x2097e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2097e8 ldr r3, [r6, #0x10] */
/* @0x2097ec str r5, [r6, #0xc] */
/* @0x2097f0 cmp r3, r5 */
/* @0x2097f4 ldr r0, [r6, #0x14] */
/* @0x2097f8 movgt r7, r5 */
/* @0x2097fc movgt r8, #5 */
/* @0x209800 bgt 0x209820 <_ZN12CDS_Priority5ClearEv+0xb8> */
/* @0x209804 b 0x209850 <_ZN12CDS_Priority5ClearEv+0xe8> */
/* @0x209808 str r7, [r4] */
/* @0x20980c ldr r3, [r6, #0x10] */
/* @0x209810 str r7, [r4, #0x8] */
/* @0x209814 cmp r3, r5 */
/* @0x209818 str r8, [r4, #0xc] */
/* @0x20981c ble 0x209850 <_ZN12CDS_Priority5ClearEv+0xe8> */
/* @0x209820 add r4, r0, r5, lsl #4 */
/* @0x209824 add r5, r5, #1 */
/* @0x209828 ldr r3, [r4, #0xc] */
/* @0x20982c sub r3, r3, #1 */
/* @0x209830 bic r3, r3, #-16777216 */
/* @0x209834 bic r3, r3, #3 */
/* @0x209838 cmp r3, #0 */
/* @0x20983c bne 0x209808 <_ZN12CDS_Priority5ClearEv+0xa0> */
/* @0x209840 mov r0, r4 */
/* @0x209844 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x209848 ldr r0, [r6, #0x14] */
/* @0x20984c b 0x209808 <_ZN12CDS_Priority5ClearEv+0xa0> */
/* @0x209850 mov r4, #0 */
/* @0x209854 str r4, [r6, #0x10] */
/* @0x209858 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20985c str r4, [r6, #0x14] */
/* @0x209860 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x209864 · CDS_Priority::CDS_Priority() · size=108 · insn=27 */
/* @0x209864 ldr r2, [pc, #0x60] */
/* @0x209868 mov r3, #0 */
/* @0x20986c push {r4, lr} */
/* @0x209870 ldr r2, [pc, r2] */
/* @0x209874 mov r4, r0 */
/* @0x209878 strb r3, [r0, #0x10] */
/* @0x20987c strb r3, [r0, #0x11] */
/* @0x209880 add r2, r2, #8 */
/* @0x209884 strb r3, [r0, #0x12] */
/* @0x209888 str r2, [r0] */
/* @0x20988c strb r3, [r0, #0x13] */
/* @0x209890 strb r3, [r0, #0x14] */
/* @0x209894 strb r3, [r0, #0x15] */
/* @0x209898 strb r3, [r0, #0x16] */
/* @0x20989c strb r3, [r0, #0x17] */
/* @0x2098a0 strb r3, [r0, #0x8] */
/* @0x2098a4 strb r3, [r0, #0x9] */
/* @0x2098a8 strb r3, [r0, #0xa] */
/* @0x2098ac strb r3, [r0, #0xb] */
/* @0x2098b0 strb r3, [r0, #0xc] */
/* @0x2098b4 strb r3, [r0, #0xd] */
/* @0x2098b8 strb r3, [r0, #0xe] */
/* @0x2098bc strb r3, [r0, #0xf] */
/* @0x2098c0 bl 0x209768 <_ZN12CDS_Priority5ClearEv> */
/* @0x2098c4 mov r0, r4 */
/* @0x2098c8 pop {r4, pc} */
/* @0x2098cc andseq r7, lr, r12, lsr #22 */

/* ── FUNC 0x209864 · CDS_Priority::CDS_Priority() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2098d0 · CDS_Priority::ReadFromString(char const*, bool) · size=356 · insn=89 */
/* @0x2098d0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2098d4 mov r4, r0 */
/* @0x2098d8 mov r0, #32 */
/* @0x2098dc mov r7, r2 */
/* @0x2098e0 mov r6, r1 */
/* @0x2098e4 bl 0x27c524 <_Znwj> */
/* @0x2098e8 mov r1, #0 */
/* @0x2098ec mov r5, r0 */
/* @0x2098f0 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x2098f4 mov r0, r5 */
/* @0x2098f8 mov r1, r6 */
/* @0x2098fc bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc> */
/* @0x209900 mov r0, r5 */
/* @0x209904 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x209908 sub r3, r0, #500 */
/* @0x20990c sub r3, r3, #1 */
/* @0x209910 cmp r3, #1 */
/* @0x209914 bls 0x209934 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x64> */
/* @0x209918 subs r0, r5, #0 */
/* @0x20991c beq 0x209a14 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x144> */
/* @0x209920 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x209924 mov r0, r5 */
/* @0x209928 bl 0x27d1d0 <_ZdlPv> */
/* @0x20992c mov r0, #0 */
/* @0x209930 pop {r3, r4, r5, r6, r7, pc} */
/* @0x209934 cmp r7, #0 */
/* @0x209938 movne r7, #1 */
/* @0x20993c beq 0x209a18 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x148> */
/* @0x209940 mov r0, r4 */
/* @0x209944 bl 0x209768 <_ZN12CDS_Priority5ClearEv> */
/* @0x209948 mov r0, r5 */
/* @0x20994c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x209950 ldr r2, [pc, #0xd4] */
/* @0x209954 mov r3, #2544 */
/* @0x209958 add r2, pc, r2 */
/* @0x20995c lsl r1, r0, #4 */
/* @0x209960 str r0, [r4, #0x4] */
/* @0x209964 add r0, r4, #20 */
/* @0x209968 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20996c ldr r1, [r4, #0x4] */
/* @0x209970 cmp r1, #0 */
/* @0x209974 str r1, [r4, #0x10] */
/* @0x209978 ble 0x2099a4 <_ZN12CDS_Priority14ReadFromStringEPKcb+0xd4> */
/* @0x20997c mov r6, #0 */
/* @0x209980 ldr r0, [r4, #0x14] */
/* @0x209984 mov r1, r5 */
/* @0x209988 mov r2, r7 */
/* @0x20998c add r0, r0, r6, lsl #4 */
/* @0x209990 add r6, r6, #1 */
/* @0x209994 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x209998 ldr r1, [r4, #0x4] */
/* @0x20999c cmp r1, r6 */
/* @0x2099a0 bgt 0x209980 <_ZN12CDS_Priority14ReadFromStringEPKcb+0xb0> */
/* @0x2099a4 ldr r2, [pc, #0x84] */
/* @0x2099a8 movw r3, #0x9f7 */
/* @0x2099ac lsl r1, r1, #4 */
/* @0x2099b0 add r0, r4, #12 */
/* @0x2099b4 add r2, pc, r2 */
/* @0x2099b8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x2099bc ldr r3, [r4, #0x4] */
/* @0x2099c0 cmp r3, #0 */
/* @0x2099c4 str r3, [r4, #0x8] */
/* @0x2099c8 movgt r6, #0 */
/* @0x2099cc ble 0x2099f4 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x124> */
/* @0x2099d0 ldr r0, [r4, #0xc] */
/* @0x2099d4 mov r1, r5 */
/* @0x2099d8 mov r2, r7 */
/* @0x2099dc add r0, r0, r6, lsl #4 */
/* @0x2099e0 add r6, r6, #1 */
/* @0x2099e4 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x2099e8 ldr r3, [r4, #0x4] */
/* @0x2099ec cmp r3, r6 */
/* @0x2099f0 bgt 0x2099d0 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x100> */
/* @0x2099f4 cmp r5, #0 */
/* @0x2099f8 beq 0x209a0c <_ZN12CDS_Priority14ReadFromStringEPKcb+0x13c> */
/* @0x2099fc mov r0, r5 */
/* @0x209a00 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x209a04 mov r0, r5 */
/* @0x209a08 bl 0x27d1d0 <_ZdlPv> */
/* @0x209a0c mov r0, #1 */
/* @0x209a10 pop {r3, r4, r5, r6, r7, pc} */
/* @0x209a14 pop {r3, r4, r5, r6, r7, pc} */
/* @0x209a18 movw r7, #0x1f5 */
/* @0x209a1c cmp r0, r7 */
/* @0x209a20 moveq r7, #2 */
/* @0x209a24 movne r7, #0 */
/* @0x209a28 b 0x209940 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x70> */
/* @0x209a2c mulseq r4, r4, lr */
/* @0x209a30 andseq r9, r4, r8, lsr lr */

/* ── FUNC 0x209a34 · CDS_Priority::~CDS_Priority() · size=40 · insn=10 */
/* @0x209a34 ldr r3, [pc, #0x1c] */
/* @0x209a38 push {r4, lr} */
/* @0x209a3c ldr r3, [pc, r3] */
/* @0x209a40 mov r4, r0 */
/* @0x209a44 add r3, r3, #8 */
/* @0x209a48 str r3, [r0] */
/* @0x209a4c bl 0x209768 <_ZN12CDS_Priority5ClearEv> */
/* @0x209a50 mov r0, r4 */
/* @0x209a54 pop {r4, pc} */
/* @0x209a58 andseq r7, lr, r0, ror #18 */
