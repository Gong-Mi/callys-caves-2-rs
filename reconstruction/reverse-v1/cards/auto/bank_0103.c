/* libyoyo.so 覆盖卡组 0103
 * 函数 0x166304..0x167e64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x166304 · CBitmap32::ImproveBoundary() · size=256 · insn=64 */
/* @0x166304 ldrb r3, [r0, #0x4] */
/* @0x166308 push {r4, r5, r6, r7, r8, r9} */
/* @0x16630c cmp r3, #0 */
/* @0x166310 beq 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8> */
/* @0x166314 ldr r4, [r0, #0xc] */
/* @0x166318 cmp r4, #0 */
/* @0x16631c beq 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8> */
/* @0x166320 ldr r1, [r0, #0x8] */
/* @0x166324 cmp r1, #0 */
/* @0x166328 beq 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8> */
/* @0x16632c cmp r4, #0 */
/* @0x166330 ble 0x1663fc <_ZN9CBitmap3215ImproveBoundaryEv+0xf8> */
/* @0x166334 mov r7, #1 */
/* @0x166338 mov r5, #0 */
/* @0x16633c cmp r1, #0 */
/* @0x166340 movle r9, r7 */
/* @0x166344 ble 0x1663ec <_ZN9CBitmap3215ImproveBoundaryEv+0xe8> */
/* @0x166348 ldr r12, [r0, #0x14] */
/* @0x16634c sub r8, r5, #1 */
/* @0x166350 mov r9, r7 */
/* @0x166354 mov r3, #0 */
/* @0x166358 mla r2, r1, r5, r3 */
/* @0x16635c ldr r4, [r12, r2, lsl #2] */
/* @0x166360 add r6, r12, r2, lsl #2 */
/* @0x166364 tst r4, #-16777216 */
/* @0x166368 bne 0x1663dc <_ZN9CBitmap3215ImproveBoundaryEv+0xd8> */
/* @0x16636c cmp r3, #0 */
/* @0x166370 beq 0x166380 <_ZN9CBitmap3215ImproveBoundaryEv+0x7c> */
/* @0x166374 ldr r4, [r6, #-0x4] */
/* @0x166378 tst r4, #-16777216 */
/* @0x16637c bne 0x1663d0 <_ZN9CBitmap3215ImproveBoundaryEv+0xcc> */
/* @0x166380 sub r4, r1, #1 */
/* @0x166384 cmp r4, r3 */
/* @0x166388 ble 0x166398 <_ZN9CBitmap3215ImproveBoundaryEv+0x94> */
/* @0x16638c ldr r4, [r6, #0x4] */
/* @0x166390 tst r4, #-16777216 */
/* @0x166394 bne 0x1663d0 <_ZN9CBitmap3215ImproveBoundaryEv+0xcc> */
/* @0x166398 cmp r5, #0 */
/* @0x16639c ble 0x1663b0 <_ZN9CBitmap3215ImproveBoundaryEv+0xac> */
/* @0x1663a0 mla r4, r1, r8, r3 */
/* @0x1663a4 ldr r4, [r12, r4, lsl #2] */
/* @0x1663a8 tst r4, #-16777216 */
/* @0x1663ac bne 0x1663d0 <_ZN9CBitmap3215ImproveBoundaryEv+0xcc> */
/* @0x1663b0 ldr r4, [r0, #0xc] */
/* @0x1663b4 sub r4, r4, #1 */
/* @0x1663b8 cmp r4, r5 */
/* @0x1663bc ble 0x1663dc <_ZN9CBitmap3215ImproveBoundaryEv+0xd8> */
/* @0x1663c0 mla r4, r7, r1, r3 */
/* @0x1663c4 ldr r4, [r12, r4, lsl #2] */
/* @0x1663c8 tst r4, #-16777216 */
/* @0x1663cc beq 0x1663dc <_ZN9CBitmap3215ImproveBoundaryEv+0xd8> */
/* @0x1663d0 bic r4, r4, #-16777216 */
/* @0x1663d4 str r4, [r12, r2, lsl #2] */
/* @0x1663d8 ldr r1, [r0, #0x8] */
/* @0x1663dc add r3, r3, #1 */
/* @0x1663e0 cmp r1, r3 */
/* @0x1663e4 bgt 0x166358 <_ZN9CBitmap3215ImproveBoundaryEv+0x54> */
/* @0x1663e8 ldr r4, [r0, #0xc] */
/* @0x1663ec cmp r4, r9 */
/* @0x1663f0 add r5, r5, #1 */
/* @0x1663f4 add r7, r7, #1 */
/* @0x1663f8 bgt 0x16633c <_ZN9CBitmap3215ImproveBoundaryEv+0x38> */
/* @0x1663fc pop {r4, r5, r6, r7, r8, r9} */
/* @0x166400 bx lr */

/* ── FUNC 0x166404 · CBitmap32::RemoveBackground() · size=132 · insn=33 */
/* @0x166404 ldrb r3, [r0, #0x4] */
/* @0x166408 push {r4, r5} */
/* @0x16640c cmp r3, #0 */
/* @0x166410 beq 0x166480 <_ZN9CBitmap3216RemoveBackgroundEv+0x7c> */
/* @0x166414 ldr r12, [r0, #0xc] */
/* @0x166418 cmp r12, #0 */
/* @0x16641c beq 0x166480 <_ZN9CBitmap3216RemoveBackgroundEv+0x7c> */
/* @0x166420 ldr r4, [r0, #0x8] */
/* @0x166424 cmp r4, #0 */
/* @0x166428 beq 0x166480 <_ZN9CBitmap3216RemoveBackgroundEv+0x7c> */
/* @0x16642c sub r3, r12, #1 */
/* @0x166430 ldr r2, [r0, #0x14] */
/* @0x166434 mul r3, r3, r4 */
/* @0x166438 add r1, r3, r4 */
/* @0x16643c cmp r1, #0 */
/* @0x166440 ldr r5, [r2, r3, lsl #2] */
/* @0x166444 movgt r3, #0 */
/* @0x166448 bic r5, r5, #-16777216 */
/* @0x16644c ble 0x166478 <_ZN9CBitmap3216RemoveBackgroundEv+0x74> */
/* @0x166450 ldr r1, [r2], #4 */
/* @0x166454 add r3, r3, #1 */
/* @0x166458 bic r1, r1, #-16777216 */
/* @0x16645c cmp r5, r1 */
/* @0x166460 streq r5, [r2, #-0x4] */
/* @0x166464 ldreq r12, [r0, #0xc] */
/* @0x166468 ldreq r4, [r0, #0x8] */
/* @0x16646c mul r1, r4, r12 */
/* @0x166470 cmp r3, r1 */
/* @0x166474 blt 0x166450 <_ZN9CBitmap3216RemoveBackgroundEv+0x4c> */
/* @0x166478 pop {r4, r5} */
/* @0x16647c b 0x166304 <_ZN9CBitmap3215ImproveBoundaryEv> */
/* @0x166480 pop {r4, r5} */
/* @0x166484 bx lr */

/* ── FUNC 0x166488 · CBitmap32::CBitmap32(int, IBitmap*, bool, bool) · size=736 · insn=184 */
/* @0x166488 ldr r1, [pc, #0x2cc] */
/* @0x16648c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x166490 subs r10, r2, #0 */
/* @0x166494 sub sp, sp, #12 */
/* @0x166498 ldr r1, [pc, r1] */
/* @0x16649c mov r5, #0 */
/* @0x1664a0 add r1, r1, #8 */
/* @0x1664a4 mov r6, r0 */
/* @0x1664a8 mov r8, r3 */
/* @0x1664ac strb r5, [r0, #0x4] */
/* @0x1664b0 str r1, [r0] */
/* @0x1664b4 str r5, [r0, #0x8] */
/* @0x1664b8 str r5, [r0, #0xc] */
/* @0x1664bc str r5, [r0, #0x10] */
/* @0x1664c0 str r5, [r0, #0x14] */
/* @0x1664c4 ldrb r9, [sp, #0x30] */
/* @0x1664c8 beq 0x1664fc <_ZN9CBitmap32C2EiP7IBitmapbb+0x74> */
/* @0x1664cc ldr r3, [r10] */
/* @0x1664d0 mov r0, r10 */
/* @0x1664d4 ldr r3, [r3, #0x20] */
/* @0x1664d8 blx r3 */
/* @0x1664dc ldr r3, [r10] */
/* @0x1664e0 cmp r0, #6 */
/* @0x1664e4 beq 0x166508 <_ZN9CBitmap32C2EiP7IBitmapbb+0x80> */
/* @0x1664e8 mov r0, r10 */
/* @0x1664ec ldr r3, [r3, #0x20] */
/* @0x1664f0 blx r3 */
/* @0x1664f4 cmp r0, #7 */
/* @0x1664f8 beq 0x166650 <_ZN9CBitmap32C2EiP7IBitmapbb+0x1c8> */
/* @0x1664fc mov r0, r6 */
/* @0x166500 add sp, sp, #12 */
/* @0x166504 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x166508 mov r4, #1 */
/* @0x16650c ldr r3, [r3, #0x10] */
/* @0x166510 strb r4, [r6, #0x4] */
/* @0x166514 mov r0, r10 */
/* @0x166518 blx r3 */
/* @0x16651c ldr r3, [r10] */
/* @0x166520 ldr r3, [r3, #0x18] */
/* @0x166524 str r0, [r6, #0x8] */
/* @0x166528 mov r0, r10 */
/* @0x16652c blx r3 */
/* @0x166530 ldr r12, [r6, #0x8] */
/* @0x166534 ldr r1, [pc, #0x224] */
/* @0x166538 mov r3, r4 */
/* @0x16653c movw r2, #0x2d9 */
/* @0x166540 add r1, pc, r1 */
/* @0x166544 str r0, [r6, #0xc] */
/* @0x166548 mul r0, r12, r0 */
/* @0x16654c lsl r0, r0, #2 */
/* @0x166550 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x166554 ldr lr, [r6, #0x8] */
/* @0x166558 ldr r4, [r6, #0xc] */
/* @0x16655c add r2, sp, #8 */
/* @0x166560 ldr r12, [r10] */
/* @0x166564 mov r3, sp */
/* @0x166568 str r5, [r2, #-0x4]! */
/* @0x16656c mov r1, r5 */
/* @0x166570 mul lr, r4, lr */
/* @0x166574 str r5, [sp] */
/* @0x166578 lsl lr, lr, #2 */
/* @0x16657c str lr, [r6, #0x10] */
/* @0x166580 str r0, [r6, #0x14] */
/* @0x166584 mov r0, r10 */
/* @0x166588 ldr r12, [r12, #0x24] */
/* @0x16658c blx r12 */
/* @0x166590 ldr r3, [r6, #0xc] */
/* @0x166594 cmp r3, r5 */
/* @0x166598 ble 0x166610 <_ZN9CBitmap32C2EiP7IBitmapbb+0x188> */
/* @0x16659c ldr r7, [sp, #0x4] */
/* @0x1665a0 mov r2, r5 */
/* @0x1665a4 ldr r12, [r6, #0x8] */
/* @0x1665a8 cmp r12, #0 */
/* @0x1665ac ble 0x1665f8 <_ZN9CBitmap32C2EiP7IBitmapbb+0x170> */
/* @0x1665b0 ldr r11, [r6, #0x14] */
/* @0x1665b4 mov lr, #0 */
/* @0x1665b8 mov r4, lr */
/* @0x1665bc mla r12, r12, r2, r4 */
/* @0x1665c0 add r5, r7, lr */
/* @0x1665c4 ldrb r3, [r7, lr] */
/* @0x1665c8 add r4, r4, #1 */
/* @0x1665cc ldrb r1, [r5, #0x2] */
/* @0x1665d0 add lr, lr, #3 */
/* @0x1665d4 ldrb r5, [r5, #0x1] */
/* @0x1665d8 add r3, r3, #-16777216 */
/* @0x1665dc add r3, r3, r1, lsl #16 */
/* @0x1665e0 add r3, r3, r5, lsl #8 */
/* @0x1665e4 str r3, [r11, r12, lsl #2] */
/* @0x1665e8 ldr r12, [r6, #0x8] */
/* @0x1665ec cmp r12, r4 */
/* @0x1665f0 bgt 0x1665bc <_ZN9CBitmap32C2EiP7IBitmapbb+0x134> */
/* @0x1665f4 ldr r3, [r6, #0xc] */
/* @0x1665f8 add r2, r2, #1 */
/* @0x1665fc ldr r1, [sp] */
/* @0x166600 cmp r3, r2 */
/* @0x166604 add r7, r7, r1 */
/* @0x166608 bgt 0x1665a8 <_ZN9CBitmap32C2EiP7IBitmapbb+0x120> */
/* @0x16660c str r7, [sp, #0x4] */
/* @0x166610 ldr r3, [r10] */
/* @0x166614 mov r1, r0 */
/* @0x166618 mov r0, r10 */
/* @0x16661c ldr r3, [r3, #0x28] */
/* @0x166620 blx r3 */
/* @0x166624 cmp r8, #0 */
/* @0x166628 beq 0x1664fc <_ZN9CBitmap32C2EiP7IBitmapbb+0x74> */
/* @0x16662c mov r0, r6 */
/* @0x166630 bl 0x166404 <_ZN9CBitmap3216RemoveBackgroundEv> */
/* @0x166634 cmp r9, #0 */
/* @0x166638 beq 0x1664fc <_ZN9CBitmap32C2EiP7IBitmapbb+0x74> */
/* @0x16663c mov r0, r6 */
/* @0x166640 bl 0x1661fc <_ZN9CBitmap3211SmoothEdgesEv> */
/* @0x166644 mov r0, r6 */
/* @0x166648 add sp, sp, #12 */
/* @0x16664c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x166650 ldr r3, [r10] */
/* @0x166654 mov r4, #1 */
/* @0x166658 mov r0, r10 */
/* @0x16665c strb r4, [r6, #0x4] */
/* @0x166660 ldr r3, [r3, #0x10] */
/* @0x166664 blx r3 */
/* @0x166668 ldr r3, [r10] */
/* @0x16666c ldr r3, [r3, #0x18] */
/* @0x166670 str r0, [r6, #0x8] */
/* @0x166674 mov r0, r10 */
/* @0x166678 blx r3 */
/* @0x16667c ldr r12, [r6, #0x8] */
/* @0x166680 ldr r1, [pc, #0xdc] */
/* @0x166684 mov r3, r4 */
/* @0x166688 movw r2, #0x2f3 */
/* @0x16668c add r1, pc, r1 */
/* @0x166690 str r0, [r6, #0xc] */
/* @0x166694 mul r0, r12, r0 */
/* @0x166698 lsl r0, r0, #2 */
/* @0x16669c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1666a0 ldr lr, [r6, #0x8] */
/* @0x1666a4 ldr r4, [r6, #0xc] */
/* @0x1666a8 add r2, sp, #8 */
/* @0x1666ac ldr r12, [r10] */
/* @0x1666b0 mov r3, sp */
/* @0x1666b4 str r5, [r2, #-0x4]! */
/* @0x1666b8 mov r1, r5 */
/* @0x1666bc mul lr, r4, lr */
/* @0x1666c0 str r5, [sp] */
/* @0x1666c4 lsl lr, lr, #2 */
/* @0x1666c8 str lr, [r6, #0x10] */
/* @0x1666cc str r0, [r6, #0x14] */
/* @0x1666d0 mov r0, r10 */
/* @0x1666d4 ldr r12, [r12, #0x24] */
/* @0x1666d8 blx r12 */
/* @0x1666dc ldr r3, [r6, #0xc] */
/* @0x1666e0 cmp r3, #0 */
/* @0x1666e4 ble 0x166610 <_ZN9CBitmap32C2EiP7IBitmapbb+0x188> */
/* @0x1666e8 ldr r4, [sp, #0x4] */
/* @0x1666ec ldr r12, [r6, #0x8] */
/* @0x1666f0 cmp r12, #0 */
/* @0x1666f4 ble 0x166740 <_ZN9CBitmap32C2EiP7IBitmapbb+0x2b8> */
/* @0x1666f8 ldr r7, [r6, #0x14] */
/* @0x1666fc mov r3, #0 */
/* @0x166700 mov r2, r3 */
/* @0x166704 add lr, r4, r3 */
/* @0x166708 ldrb r1, [r4, r3] */
/* @0x16670c mla r12, r12, r5, r2 */
/* @0x166710 ldrb r11, [lr, #0x2] */
/* @0x166714 ldrb lr, [lr, #0x1] */
/* @0x166718 add r2, r2, #1 */
/* @0x16671c add r3, r3, #4 */
/* @0x166720 add lr, lr, r11, lsl #8 */
/* @0x166724 add lr, r1, lr, lsl #8 */
/* @0x166728 orr lr, lr, #-16777216 */
/* @0x16672c str lr, [r7, r12, lsl #2] */
/* @0x166730 ldr r12, [r6, #0x8] */
/* @0x166734 cmp r12, r2 */
/* @0x166738 bgt 0x166704 <_ZN9CBitmap32C2EiP7IBitmapbb+0x27c> */
/* @0x16673c ldr r3, [r6, #0xc] */
/* @0x166740 add r5, r5, #1 */
/* @0x166744 ldr r2, [sp] */
/* @0x166748 cmp r3, r5 */
/* @0x16674c add r4, r4, r2 */
/* @0x166750 bgt 0x1666f0 <_ZN9CBitmap32C2EiP7IBitmapbb+0x268> */
/* @0x166754 str r4, [sp, #0x4] */
/* @0x166758 b 0x166610 <_ZN9CBitmap32C2EiP7IBitmapbb+0x188> */
/* @0x16675c eoreq r9, r8, r0, ror #24 */
/* @0x166760 andseq r4, lr, r0, lsl #1 */
/* @0x166764 andseq r3, lr, r4, lsr pc */

/* ── FUNC 0x166488 · CBitmap32::CBitmap32(int, IBitmap*, bool, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x166768 · CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int) · size=1796 · insn=447 */
/* @0x166768 ldr r12, [pc, #0x540] */
/* @0x16676c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x166770 vpush {d8, d9, d10} */
/* @0x166774 ldr r12, [pc, r12] */
/* @0x166778 sub sp, sp, #60 */
/* @0x16677c mov r6, #0 */
/* @0x166780 add r12, r12, #8 */
/* @0x166784 strb r6, [r0, #0x4] */
/* @0x166788 str r12, [r0] */
/* @0x16678c mov r11, r2 */
/* @0x166790 str r6, [r0, #0x8] */
/* @0x166794 mov r4, r1 */
/* @0x166798 str r6, [r0, #0xc] */
/* @0x16679c mov r10, r3 */
/* @0x1667a0 str r6, [r0, #0x10] */
/* @0x1667a4 str r6, [r0, #0x14] */
/* @0x1667a8 str r0, [sp, #0x1c] */
/* @0x1667ac ldr r5, [sp, #0x7c] */
/* @0x1667b0 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x1667b4 mov r1, #6 */
/* @0x1667b8 ldr r3, [r0] */
/* @0x1667bc str r0, [sp, #0x18] */
/* @0x1667c0 ldr r3, [r3, #0x1c] */
/* @0x1667c4 blx r3 */
/* @0x1667c8 ldr r0, [sp, #0x18] */
/* @0x1667cc cmp r4, #1 */
/* @0x1667d0 movge r1, r4 */
/* @0x1667d4 movlt r1, #1 */
/* @0x1667d8 ldr r3, [r0] */
/* @0x1667dc ldr r3, [r3, #0xc] */
/* @0x1667e0 blx r3 */
/* @0x1667e4 ldr r1, [sp, #0x18] */
/* @0x1667e8 ldr r3, [r1] */
/* @0x1667ec mov r0, r1 */
/* @0x1667f0 cmp r11, #1 */
/* @0x1667f4 movge r1, r11 */
/* @0x1667f8 movlt r1, #1 */
/* @0x1667fc ldr r3, [r3, #0x14] */
/* @0x166800 blx r3 */
/* @0x166804 ldr r3, [sp, #0x18] */
/* @0x166808 add r2, sp, #56 */
/* @0x16680c mov r1, r6 */
/* @0x166810 str r6, [r2, #-0x4]! */
/* @0x166814 mov r0, r3 */
/* @0x166818 ldr r12, [r3] */
/* @0x16681c add r3, sp, #48 */
/* @0x166820 str r6, [sp, #0x30] */
/* @0x166824 ldr r12, [r12, #0x24] */
/* @0x166828 blx r12 */
/* @0x16682c str r0, [sp, #0x24] */
/* @0x166830 cmp r5, #5 */
/* @0x166834 addls pc, pc, r5, lsl #2 */
/* @0x166838 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x16683c b 0x166b88 <_ZN9CBitmap32C2Eiijji+0x420> */
/* @0x166840 b 0x166c1c <_ZN9CBitmap32C2Eiijji+0x4b4> */
/* @0x166844 b 0x166cb4 <_ZN9CBitmap32C2Eiijji+0x54c> */
/* @0x166848 b 0x166854 <_ZN9CBitmap32C2Eiijji+0xec> */
/* @0x16684c b 0x166dbc <_ZN9CBitmap32C2Eiijji+0x654> */
/* @0x166850 b 0x166ac8 <_ZN9CBitmap32C2Eiijji+0x360> */
/* @0x166854 ldr r0, [sp, #0x34] */
/* @0x166858 cmp r11, #0 */
/* @0x16685c str r0, [sp, #0x28] */
/* @0x166860 ble 0x1668c8 <_ZN9CBitmap32C2Eiijji+0x160> */
/* @0x166864 ldr r1, [sp, #0x28] */
/* @0x166868 ubfx r12, r10, #0x10, #0x8 */
/* @0x16686c ldr r6, [sp, #0x30] */
/* @0x166870 ubfx r0, r10, #0x8, #0x8 */
/* @0x166874 add lr, r1, #3 */
/* @0x166878 add r7, r4, r4, lsl #1 */
/* @0x16687c uxtb r1, r10 */
/* @0x166880 mov r5, #0 */
/* @0x166884 cmp r4, #0 */
/* @0x166888 addgt r2, r7, lr */
/* @0x16688c movgt r3, lr */
/* @0x166890 ble 0x1668ac <_ZN9CBitmap32C2Eiijji+0x144> */
/* @0x166894 strb r12, [r3, #-0x1] */
/* @0x166898 add r3, r3, #3 */
/* @0x16689c strb r1, [r3, #-0x6] */
/* @0x1668a0 strb r0, [r3, #-0x5] */
/* @0x1668a4 cmp r3, r2 */
/* @0x1668a8 bne 0x166894 <_ZN9CBitmap32C2Eiijji+0x12c> */
/* @0x1668ac add r5, r5, #1 */
/* @0x1668b0 add lr, lr, r6 */
/* @0x1668b4 cmp r5, r11 */
/* @0x1668b8 bne 0x166884 <_ZN9CBitmap32C2Eiijji+0x11c> */
/* @0x1668bc ldr r2, [sp, #0x28] */
/* @0x1668c0 mla r6, r6, r11, r2 */
/* @0x1668c4 str r6, [sp, #0x34] */
/* @0x1668c8 cmp r4, r11 */
/* @0x1668cc bge 0x166e60 <_ZN9CBitmap32C2Eiijji+0x6f8> */
/* @0x1668d0 vmov d10, r4, r4 */
/* @0x1668d4 vcvt.f64.s32 d10, d10, #1 */
/* @0x1668d8 vcmpe.f64 d10, #0 */
/* @0x1668dc vmrs APSR_nzcv, fpscr */
/* @0x1668e0 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x1668e4 vmov.f64 d9, #5.000000e-01 */
/* @0x1668e8 add r5, r4, r4, lsl #1 */
/* @0x1668ec mov r9, #0 */
/* @0x1668f0 vldr d7, [pc, #944] */
/* @0x1668f4 str r4, [sp, #0x10] */
/* @0x1668f8 str r11, [sp, #0x14] */
/* @0x1668fc str r10, [sp, #0x2c] */
/* @0x166900 vmov.f64 d8, #1.000000e+00 */
/* @0x166904 ldr r1, [sp, #0x78] */
/* @0x166908 add r11, r9, #1 */
/* @0x16690c ldr r0, [sp, #0x2c] */
/* @0x166910 vdiv.f64 d6, d7, d10 */
/* @0x166914 vmov r2, r3, d6 */
/* @0x166918 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd> */
/* @0x16691c ldr r7, [sp, #0x30] */
/* @0x166920 ldr r2, [sp, #0x28] */
/* @0x166924 ldr r1, [sp, #0x14] */
/* @0x166928 mla r2, r9, r7, r2 */
/* @0x16692c rsb r8, r9, r1 */
/* @0x166930 cmp r8, r9 */
/* @0x166934 str r2, [sp, #0x20] */
/* @0x166938 str r2, [sp, #0x34] */
/* @0x16693c ble 0x166a2c <_ZN9CBitmap32C2Eiijji+0x2c4> */
/* @0x166940 ldr r1, [sp, #0x14] */
/* @0x166944 lsl r3, r9, #1 */
/* @0x166948 ldr r2, [sp, #0x10] */
/* @0x16694c add lr, r11, r11, lsl #1 */
/* @0x166950 rsb r1, r3, r1 */
/* @0x166954 ubfx r6, r0, #0x10, #0x8 */
/* @0x166958 rsb r2, r3, r2 */
/* @0x16695c ldr r3, [sp, #0x10] */
/* @0x166960 vmov s7, r1 */
/* @0x166964 ldr r1, [sp, #0x20] */
/* @0x166968 vmov s6, r2 */
/* @0x16696c rsb r10, r9, r3 */
/* @0x166970 add lr, r1, lr */
/* @0x166974 ubfx r4, r0, #0x8, #0x8 */
/* @0x166978 mov r12, r9 */
/* @0x16697c cmp r10, r9 */
/* @0x166980 ble 0x166a0c <_ZN9CBitmap32C2Eiijji+0x2a4> */
/* @0x166984 vmov s5, r12 */
/* @0x166988 vldr s11, [sp, #20] */
/* @0x16698c vcvt.f64.s32 d6, s11 */
/* @0x166990 add r1, r5, lr */
/* @0x166994 mov r3, lr */
/* @0x166998 mov r2, r9 */
/* @0x16699c vcvt.f64.s32 d7, s5 */
/* @0x1669a0 vmls.f64 d7, d6, d9 */
/* @0x1669a4 vcvt.f64.s32 d6, s7 */
/* @0x1669a8 vmul.f64 d6, d6, d9 */
/* @0x1669ac vmul.f64 d7, d7, d7 */
/* @0x1669b0 vmul.f64 d6, d6, d6 */
/* @0x1669b4 vcvt.f64.s32 d5, s6 */
/* @0x1669b8 vmul.f64 d5, d5, d9 */
/* @0x1669bc vdiv.f64 d4, d7, d6 */
/* @0x1669c0 vldr s15, [sp, #16] */
/* @0x1669c4 vcvt.f64.s32 d6, s15 */
/* @0x1669c8 vmul.f64 d5, d5, d5 */
/* @0x1669cc vmul.f64 d6, d6, d9 */
/* @0x1669d0 vmov s5, r2 */
/* @0x1669d4 add r3, r3, #3 */
/* @0x1669d8 add r2, r2, #1 */
/* @0x1669dc vcvt.f64.s32 d7, s5 */
/* @0x1669e0 vsub.f64 d7, d7, d6 */
/* @0x1669e4 vmul.f64 d7, d7, d7 */
/* @0x1669e8 vdiv.f64 d7, d7, d5 */
/* @0x1669ec vadd.f64 d7, d7, d4 */
/* @0x1669f0 vcmpe.f64 d7, d8 */
/* @0x1669f4 vmrs APSR_nzcv, fpscr */
/* @0x1669f8 strbls r6, [r3, #-0x4] */
/* @0x1669fc strbls r0, [r3, #-0x6] */
/* @0x166a00 strbls r4, [r3, #-0x5] */
/* @0x166a04 cmp r3, r1 */
/* @0x166a08 bne 0x1669d0 <_ZN9CBitmap32C2Eiijji+0x268> */
/* @0x166a0c add r12, r12, #1 */
/* @0x166a10 add lr, lr, r7 */
/* @0x166a14 cmp r8, r12 */
/* @0x166a18 bne 0x16697c <_ZN9CBitmap32C2Eiijji+0x214> */
/* @0x166a1c vmov r0, s7 */
/* @0x166a20 ldr r1, [sp, #0x20] */
/* @0x166a24 mla r7, r7, r0, r1 */
/* @0x166a28 str r7, [sp, #0x34] */
/* @0x166a2c vmov s5, r11 */
/* @0x166a30 mov r9, r11 */
/* @0x166a34 sub r5, r5, #6 */
/* @0x166a38 vcvt.f64.s32 d7, s5 */
/* @0x166a3c vcmpe.f64 d10, d7 */
/* @0x166a40 vmrs APSR_nzcv, fpscr */
/* @0x166a44 bgt 0x166904 <_ZN9CBitmap32C2Eiijji+0x19c> */
/* @0x166a48 ldr r1, [sp, #0x18] */
/* @0x166a4c ldr r0, [sp, #0x18] */
/* @0x166a50 ldr r3, [r1] */
/* @0x166a54 ldr r1, [sp, #0x24] */
/* @0x166a58 ldr r3, [r3, #0x28] */
/* @0x166a5c blx r3 */
/* @0x166a60 mov r0, #24 */
/* @0x166a64 bl 0x27c524 <_Znwj> */
/* @0x166a68 mov r3, #0 */
/* @0x166a6c mov r1, r3 */
/* @0x166a70 ldr r2, [sp, #0x18] */
/* @0x166a74 str r3, [sp] */
/* @0x166a78 mov r4, r0 */
/* @0x166a7c bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb> */
/* @0x166a80 ldr r0, [sp, #0x1c] */
/* @0x166a84 mov r1, r4 */
/* @0x166a88 bl 0x165dac <_ZN9CBitmap326AssignEPS_> */
/* @0x166a8c cmp r4, #0 */
/* @0x166a90 beq 0x166aa4 <_ZN9CBitmap32C2Eiijji+0x33c> */
/* @0x166a94 ldr r3, [r4] */
/* @0x166a98 mov r0, r4 */
/* @0x166a9c ldr r3, [r3, #0x4] */
/* @0x166aa0 blx r3 */
/* @0x166aa4 ldr r2, [sp, #0x18] */
/* @0x166aa8 ldr r3, [r2] */
/* @0x166aac mov r0, r2 */
/* @0x166ab0 ldr r3, [r3, #0x4] */
/* @0x166ab4 blx r3 */
/* @0x166ab8 ldr r0, [sp, #0x1c] */
/* @0x166abc add sp, sp, #60 */
/* @0x166ac0 vpop {d8, d9, d10} */
/* @0x166ac4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x166ac8 cmp r11, #0 */
/* @0x166acc ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166ad0 vmov d8, r11, r11 */
/* @0x166ad4 vcvt.f64.s32 d8, d8, #1 */
/* @0x166ad8 ldr r5, [sp, #0x34] */
/* @0x166adc ldr r9, [sp, #0x78] */
/* @0x166ae0 add r3, r4, r4, lsl #1 */
/* @0x166ae4 mov r8, #0 */
/* @0x166ae8 add r3, r3, #3 */
/* @0x166aec sub r0, r11, #1 */
/* @0x166af0 str r3, [sp, #0x10] */
/* @0x166af4 str r0, [sp, #0xc] */
/* @0x166af8 str r4, [sp, #0x14] */
/* @0x166afc ldr r1, [sp, #0xc] */
/* @0x166b00 ldr r2, [sp, #0x14] */
/* @0x166b04 rsb r3, r8, r1 */
/* @0x166b08 cmp r3, r8 */
/* @0x166b0c movge r3, r8 */
/* @0x166b10 cmp r2, #0 */
/* @0x166b14 vmov s5, r3 */
/* @0x166b18 vcvt.f64.s32 d7, s5 */
/* @0x166b1c vdiv.f64 d6, d7, d8 */
/* @0x166b20 vmov r6, r7, d6 */
/* @0x166b24 ble 0x166b6c <_ZN9CBitmap32C2Eiijji+0x404> */
/* @0x166b28 ldr r0, [sp, #0x10] */
/* @0x166b2c add r4, r5, #3 */
/* @0x166b30 add r5, r5, r0 */
/* @0x166b34 mov r3, r7 */
/* @0x166b38 mov r0, r10 */
/* @0x166b3c mov r1, r9 */
/* @0x166b40 mov r2, r6 */
/* @0x166b44 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd> */
/* @0x166b48 add r4, r4, #3 */
/* @0x166b4c strb r0, [r4, #-0x6] */
/* @0x166b50 lsr r3, r0, #16 */
/* @0x166b54 lsr r0, r0, #8 */
/* @0x166b58 strb r3, [r4, #-0x4] */
/* @0x166b5c strb r0, [r4, #-0x5] */
/* @0x166b60 cmp r4, r5 */
/* @0x166b64 bne 0x166b34 <_ZN9CBitmap32C2Eiijji+0x3cc> */
/* @0x166b68 ldr r5, [sp, #0x34] */
/* @0x166b6c add r8, r8, #1 */
/* @0x166b70 ldr r3, [sp, #0x30] */
/* @0x166b74 cmp r8, r11 */
/* @0x166b78 add r5, r5, r3 */
/* @0x166b7c str r5, [sp, #0x34] */
/* @0x166b80 bne 0x166afc <_ZN9CBitmap32C2Eiijji+0x394> */
/* @0x166b84 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166b88 cmp r4, #0 */
/* @0x166b8c ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166b90 vmov s5, r4 */
/* @0x166b94 ldr r6, [sp, #0x78] */
/* @0x166b98 mov r5, #0 */
/* @0x166b9c vcvt.f64.s32 d8, s5 */
/* @0x166ba0 vmov s11, r5 */
/* @0x166ba4 mov r0, r10 */
/* @0x166ba8 mov r1, r6 */
/* @0x166bac vcvt.f64.s32 d7, s11 */
/* @0x166bb0 vdiv.f64 d6, d7, d8 */
/* @0x166bb4 vmov r2, r3, d6 */
/* @0x166bb8 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd> */
/* @0x166bbc cmp r11, #0 */
/* @0x166bc0 ldr r9, [sp, #0x34] */
/* @0x166bc4 ble 0x166c04 <_ZN9CBitmap32C2Eiijji+0x49c> */
/* @0x166bc8 ldr r1, [sp, #0x30] */
/* @0x166bcc ubfx r8, r0, #0x10, #0x8 */
/* @0x166bd0 uxtb r7, r0 */
/* @0x166bd4 ubfx r0, r0, #0x8, #0x8 */
/* @0x166bd8 add r3, r9, r1 */
/* @0x166bdc rsb lr, r1, #0 */
/* @0x166be0 mov r2, #0 */
/* @0x166be4 add r2, r2, #1 */
/* @0x166be8 add r12, r3, lr */
/* @0x166bec cmp r2, r11 */
/* @0x166bf0 strb r8, [r12, #0x2] */
/* @0x166bf4 strb r7, [r3, lr] */
/* @0x166bf8 add r3, r3, r1 */
/* @0x166bfc strb r0, [r12, #0x1] */
/* @0x166c00 bne 0x166be4 <_ZN9CBitmap32C2Eiijji+0x47c> */
/* @0x166c04 add r5, r5, #1 */
/* @0x166c08 add r9, r9, #3 */
/* @0x166c0c cmp r5, r4 */
/* @0x166c10 str r9, [sp, #0x34] */
/* @0x166c14 bne 0x166ba0 <_ZN9CBitmap32C2Eiijji+0x438> */
/* @0x166c18 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166c1c cmp r11, #0 */
/* @0x166c20 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166c24 vmov s13, r11 */
/* @0x166c28 ldr r7, [sp, #0x78] */
/* @0x166c2c add r5, r4, r4, lsl #1 */
/* @0x166c30 mov r6, #0 */
/* @0x166c34 vcvt.f64.s32 d8, s13 */
/* @0x166c38 vmov s5, r6 */
/* @0x166c3c mov r0, r10 */
/* @0x166c40 mov r1, r7 */
/* @0x166c44 vcvt.f64.s32 d7, s5 */
/* @0x166c48 vdiv.f64 d6, d7, d8 */
/* @0x166c4c vmov r2, r3, d6 */
/* @0x166c50 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd> */
/* @0x166c54 cmp r4, #0 */
/* @0x166c58 ldr r8, [sp, #0x34] */
/* @0x166c5c ble 0x166c8c <_ZN9CBitmap32C2Eiijji+0x524> */
/* @0x166c60 add r3, r8, #3 */
/* @0x166c64 ubfx lr, r0, #0x10, #0x8 */
/* @0x166c68 add r1, r3, r5 */
/* @0x166c6c uxtb r12, r0 */
/* @0x166c70 ubfx r2, r0, #0x8, #0x8 */
/* @0x166c74 strb lr, [r3, #-0x1] */
/* @0x166c78 add r3, r3, #3 */
/* @0x166c7c strb r12, [r3, #-0x6] */
/* @0x166c80 strb r2, [r3, #-0x5] */
/* @0x166c84 cmp r3, r1 */
/* @0x166c88 bne 0x166c74 <_ZN9CBitmap32C2Eiijji+0x50c> */
/* @0x166c8c add r6, r6, #1 */
/* @0x166c90 ldr r3, [sp, #0x30] */
/* @0x166c94 cmp r6, r11 */
/* @0x166c98 add r8, r8, r3 */
/* @0x166c9c str r8, [sp, #0x34] */
/* @0x166ca0 bne 0x166c38 <_ZN9CBitmap32C2Eiijji+0x4d0> */
/* @0x166ca4 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166cb0 eoreq r9, r8, r4, lsl #19 */
/* @0x166cb4 cmp r11, #0 */
/* @0x166cb8 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166cbc ldr r8, [sp, #0x34] */
/* @0x166cc0 cmp r4, r11 */
/* @0x166cc4 sub r0, r11, #1 */
/* @0x166cc8 vmov.f64 d10, #5.000000e-01 */
/* @0x166ccc str r0, [sp, #0xc] */
/* @0x166cd0 sub r6, r4, #1 */
/* @0x166cd4 mov r7, #0 */
/* @0x166cd8 mov r12, r8 */
/* @0x166cdc ldr r9, [sp, #0x78] */
/* @0x166ce0 bge 0x166d94 <_ZN9CBitmap32C2Eiijji+0x62c> */
/* @0x166ce4 vmov s5, r4 */
/* @0x166ce8 ldr r1, [sp, #0xc] */
/* @0x166cec rsb r3, r7, r1 */
/* @0x166cf0 cmp r3, r7 */
/* @0x166cf4 movge r3, r7 */
/* @0x166cf8 cmp r4, #0 */
/* @0x166cfc vcvt.f64.s32 d9, s5 */
/* @0x166d00 vmov s11, r3 */
/* @0x166d04 vmul.f64 d9, d9, d10 */
/* @0x166d08 vcvt.f64.s32 d8, s11 */
/* @0x166d0c ble 0x166d74 <_ZN9CBitmap32C2Eiijji+0x60c> */
/* @0x166d10 add r8, r12, #3 */
/* @0x166d14 mov r5, #0 */
/* @0x166d18 rsb r3, r5, r6 */
/* @0x166d1c mov r0, r10 */
/* @0x166d20 cmp r3, r5 */
/* @0x166d24 movge r3, r5 */
/* @0x166d28 mov r1, r9 */
/* @0x166d2c add r5, r5, #1 */
/* @0x166d30 add r8, r8, #3 */
/* @0x166d34 vmov s11, r3 */
/* @0x166d38 vcvt.f64.s32 d7, s11 */
/* @0x166d3c vcmpe.f64 d7, d8 */
/* @0x166d40 vmrs APSR_nzcv, fpscr */
/* @0x166d44 vmovpl.f64 d7, d8 */
/* @0x166d48 vdiv.f64 d6, d7, d9 */
/* @0x166d4c vmov r2, r3, d6 */
/* @0x166d50 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd> */
/* @0x166d54 cmp r5, r4 */
/* @0x166d58 strb r0, [r8, #-0x6] */
/* @0x166d5c lsr r3, r0, #16 */
/* @0x166d60 lsr r0, r0, #8 */
/* @0x166d64 strb r3, [r8, #-0x4] */
/* @0x166d68 strb r0, [r8, #-0x5] */
/* @0x166d6c bne 0x166d18 <_ZN9CBitmap32C2Eiijji+0x5b0> */
/* @0x166d70 ldr r12, [sp, #0x34] */
/* @0x166d74 add r7, r7, #1 */
/* @0x166d78 ldr r3, [sp, #0x30] */
/* @0x166d7c cmp r7, r11 */
/* @0x166d80 add r12, r12, r3 */
/* @0x166d84 str r12, [sp, #0x34] */
/* @0x166d88 beq 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166d8c cmp r4, r11 */
/* @0x166d90 blt 0x166ce4 <_ZN9CBitmap32C2Eiijji+0x57c> */
/* @0x166d94 vmov s12, r11 */
/* @0x166d98 ldr r0, [sp, #0xc] */
/* @0x166d9c vcvt.f64.s32 d9, s12 */
/* @0x166da0 rsb r3, r7, r0 */
/* @0x166da4 cmp r3, r7 */
/* @0x166da8 movge r3, r7 */
/* @0x166dac vmov s5, r3 */
/* @0x166db0 vmul.f64 d9, d9, d10 */
/* @0x166db4 vcvt.f64.s32 d8, s5 */
/* @0x166db8 b 0x166d10 <_ZN9CBitmap32C2Eiijji+0x5a8> */
/* @0x166dbc cmp r11, #0 */
/* @0x166dc0 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166dc4 vmov.f64 d9, #5.000000e-01 */
/* @0x166dc8 ldr r8, [sp, #0x34] */
/* @0x166dcc ldr r9, [sp, #0x78] */
/* @0x166dd0 sub r6, r4, #1 */
/* @0x166dd4 mov r7, #0 */
/* @0x166dd8 cmp r4, #0 */
/* @0x166ddc ble 0x166e44 <_ZN9CBitmap32C2Eiijji+0x6dc> */
/* @0x166de0 vmov s5, r4 */
/* @0x166de4 add r8, r8, #3 */
/* @0x166de8 mov r5, #0 */
/* @0x166dec vcvt.f64.s32 d8, s5 */
/* @0x166df0 vmul.f64 d8, d8, d9 */
/* @0x166df4 rsb r3, r5, r6 */
/* @0x166df8 mov r0, r10 */
/* @0x166dfc cmp r3, r5 */
/* @0x166e00 movge r3, r5 */
/* @0x166e04 mov r1, r9 */
/* @0x166e08 add r5, r5, #1 */
/* @0x166e0c add r8, r8, #3 */
/* @0x166e10 vmov s11, r3 */
/* @0x166e14 vcvt.f64.s32 d7, s11 */
/* @0x166e18 vdiv.f64 d6, d7, d8 */
/* @0x166e1c vmov r2, r3, d6 */
/* @0x166e20 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd> */
/* @0x166e24 cmp r5, r4 */
/* @0x166e28 strb r0, [r8, #-0x6] */
/* @0x166e2c lsr r3, r0, #16 */
/* @0x166e30 lsr r0, r0, #8 */
/* @0x166e34 strb r3, [r8, #-0x4] */
/* @0x166e38 strb r0, [r8, #-0x5] */
/* @0x166e3c bne 0x166df4 <_ZN9CBitmap32C2Eiijji+0x68c> */
/* @0x166e40 ldr r8, [sp, #0x34] */
/* @0x166e44 add r7, r7, #1 */
/* @0x166e48 ldr r3, [sp, #0x30] */
/* @0x166e4c cmp r7, r11 */
/* @0x166e50 add r8, r8, r3 */
/* @0x166e54 str r8, [sp, #0x34] */
/* @0x166e58 bne 0x166dd8 <_ZN9CBitmap32C2Eiijji+0x670> */
/* @0x166e5c b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0> */
/* @0x166e60 vmov d10, r11, r11 */
/* @0x166e64 vcvt.f64.s32 d10, d10, #1 */
/* @0x166e68 b 0x1668d8 <_ZN9CBitmap32C2Eiijji+0x170> */

/* ── FUNC 0x166768 · CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x166e6c · anon_166e6c · size=4 · insn=1 */
/* @0x166e6c nop */

/* ── FUNC 0x166e70 · CBitmap32::CBitmap32(IBitmap*, bool, bool) · size=352 · insn=88 */
/* @0x166e70 ldr r12, [pc, #0x154] */
/* @0x166e74 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x166e78 subs r6, r1, #0 */
/* @0x166e7c ldr r12, [pc, r12] */
/* @0x166e80 mov r5, #0 */
/* @0x166e84 add r12, r12, #8 */
/* @0x166e88 sub sp, sp, #12 */
/* @0x166e8c mov r4, r0 */
/* @0x166e90 mov r8, r2 */
/* @0x166e94 mov r9, r3 */
/* @0x166e98 str r12, [r0] */
/* @0x166e9c strb r5, [r0, #0x4] */
/* @0x166ea0 str r5, [r0, #0x8] */
/* @0x166ea4 str r5, [r0, #0xc] */
/* @0x166ea8 str r5, [r0, #0x10] */
/* @0x166eac str r5, [r0, #0x14] */
/* @0x166eb0 beq 0x166f50 <_ZN9CBitmap32C2EP7IBitmapbb+0xe0> */
/* @0x166eb4 ldr r3, [r6] */
/* @0x166eb8 mov r0, r6 */
/* @0x166ebc ldr r3, [r3, #0x20] */
/* @0x166ec0 blx r3 */
/* @0x166ec4 cmp r0, #6 */
/* @0x166ec8 beq 0x166f5c <_ZN9CBitmap32C2EP7IBitmapbb+0xec> */
/* @0x166ecc ldr r3, [r6] */
/* @0x166ed0 mov r0, r6 */
/* @0x166ed4 ldr r3, [r3, #0x20] */
/* @0x166ed8 blx r3 */
/* @0x166edc cmp r0, #7 */
/* @0x166ee0 beq 0x166f94 <_ZN9CBitmap32C2EP7IBitmapbb+0x124> */
/* @0x166ee4 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x166ee8 mov r1, r6 */
/* @0x166eec ldr r3, [r0] */
/* @0x166ef0 mov r7, r0 */
/* @0x166ef4 ldr r3, [r3, #0x2c] */
/* @0x166ef8 blx r3 */
/* @0x166efc mov r0, #24 */
/* @0x166f00 bl 0x27c524 <_Znwj> */
/* @0x166f04 mov r1, r5 */
/* @0x166f08 mov r3, r8 */
/* @0x166f0c mov r2, r7 */
/* @0x166f10 str r9, [sp] */
/* @0x166f14 mov r6, r0 */
/* @0x166f18 bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb> */
/* @0x166f1c mov r0, r4 */
/* @0x166f20 mov r1, r6 */
/* @0x166f24 bl 0x165dac <_ZN9CBitmap326AssignEPS_> */
/* @0x166f28 cmp r6, #0 */
/* @0x166f2c beq 0x166f40 <_ZN9CBitmap32C2EP7IBitmapbb+0xd0> */
/* @0x166f30 ldr r3, [r6] */
/* @0x166f34 mov r0, r6 */
/* @0x166f38 ldr r3, [r3, #0x4] */
/* @0x166f3c blx r3 */
/* @0x166f40 ldr r3, [r7] */
/* @0x166f44 mov r0, r7 */
/* @0x166f48 ldr r3, [r3, #0x4] */
/* @0x166f4c blx r3 */
/* @0x166f50 mov r0, r4 */
/* @0x166f54 add sp, sp, #12 */
/* @0x166f58 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x166f5c mov r0, #24 */
/* @0x166f60 bl 0x27c524 <_Znwj> */
/* @0x166f64 mov r1, r5 */
/* @0x166f68 mov r2, r6 */
/* @0x166f6c mov r3, r8 */
/* @0x166f70 str r9, [sp] */
/* @0x166f74 mov r7, r0 */
/* @0x166f78 bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb> */
/* @0x166f7c mov r0, r4 */
/* @0x166f80 mov r1, r7 */
/* @0x166f84 bl 0x165dac <_ZN9CBitmap326AssignEPS_> */
/* @0x166f88 cmp r7, r5 */
/* @0x166f8c bne 0x166f40 <_ZN9CBitmap32C2EP7IBitmapbb+0xd0> */
/* @0x166f90 b 0x166f50 <_ZN9CBitmap32C2EP7IBitmapbb+0xe0> */
/* @0x166f94 mov r0, #24 */
/* @0x166f98 bl 0x27c524 <_Znwj> */
/* @0x166f9c mov r1, r5 */
/* @0x166fa0 mov r2, r6 */
/* @0x166fa4 mov r3, r8 */
/* @0x166fa8 str r9, [sp] */
/* @0x166fac mov r7, r0 */
/* @0x166fb0 bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb> */
/* @0x166fb4 mov r0, r4 */
/* @0x166fb8 mov r1, r7 */
/* @0x166fbc bl 0x165dac <_ZN9CBitmap326AssignEPS_> */
/* @0x166fc0 cmp r7, #0 */
/* @0x166fc4 bne 0x166f40 <_ZN9CBitmap32C2EP7IBitmapbb+0xd0> */
/* @0x166fc8 b 0x166f50 <_ZN9CBitmap32C2EP7IBitmapbb+0xe0> */
/* @0x166fcc eoreq r9, r8, r12, ror r2 */

/* ── FUNC 0x166e70 · CBitmap32::CBitmap32(IBitmap*, bool, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x166fd0 · CBitmap32::CBitmap32(IBitmap*, bool, bool, int) · size=440 · insn=110 */
/* @0x166fd0 ldr r12, [pc, #0x1a8] */
/* @0x166fd4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x166fd8 subs r5, r1, #0 */
/* @0x166fdc ldr r12, [pc, r12] */
/* @0x166fe0 mov r1, #0 */
/* @0x166fe4 add r12, r12, #8 */
/* @0x166fe8 sub sp, sp, #12 */
/* @0x166fec mov r4, r0 */
/* @0x166ff0 mov r7, r2 */
/* @0x166ff4 mov r8, r3 */
/* @0x166ff8 str r12, [r0] */
/* @0x166ffc strb r1, [r0, #0x4] */
/* @0x167000 str r1, [r0, #0x8] */
/* @0x167004 str r1, [r0, #0xc] */
/* @0x167008 str r1, [r0, #0x10] */
/* @0x16700c str r1, [r0, #0x14] */
/* @0x167010 beq 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88> */
/* @0x167014 ldr r3, [r5] */
/* @0x167018 mov r0, r5 */
/* @0x16701c ldr r3, [r3, #0x34] */
/* @0x167020 blx r3 */
/* @0x167024 cmp r0, #0 */
/* @0x167028 beq 0x167040 <_ZN9CBitmap32C2EP7IBitmapbbi+0x70> */
/* @0x16702c ldr r3, [r5] */
/* @0x167030 mov r0, r5 */
/* @0x167034 mov r1, r5 */
/* @0x167038 ldr r3, [r3, #0x2c] */
/* @0x16703c blx r3 */
/* @0x167040 ldr r3, [r5] */
/* @0x167044 mov r0, r5 */
/* @0x167048 ldr r3, [r3, #0x20] */
/* @0x16704c blx r3 */
/* @0x167050 cmp r0, #7 */
/* @0x167054 beq 0x167064 <_ZN9CBitmap32C2EP7IBitmapbbi+0x94> */
/* @0x167058 mov r0, r4 */
/* @0x16705c add sp, sp, #12 */
/* @0x167060 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x167064 ldr r3, [r5] */
/* @0x167068 mov r9, #1 */
/* @0x16706c mov r0, r5 */
/* @0x167070 strb r9, [r4, #0x4] */
/* @0x167074 mov r6, #0 */
/* @0x167078 ldr r3, [r3, #0x10] */
/* @0x16707c blx r3 */
/* @0x167080 ldr r3, [r5] */
/* @0x167084 ldr r3, [r3, #0x18] */
/* @0x167088 str r0, [r4, #0x8] */
/* @0x16708c mov r0, r5 */
/* @0x167090 blx r3 */
/* @0x167094 ldr r12, [r4, #0x8] */
/* @0x167098 ldr r1, [pc, #0xe4] */
/* @0x16709c mov r3, r9 */
/* @0x1670a0 movw r2, #0x342 */
/* @0x1670a4 add r1, pc, r1 */
/* @0x1670a8 str r0, [r4, #0xc] */
/* @0x1670ac mul r0, r12, r0 */
/* @0x1670b0 lsl r0, r0, #2 */
/* @0x1670b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1670b8 ldr r9, [r4, #0xc] */
/* @0x1670bc ldr lr, [r4, #0x8] */
/* @0x1670c0 add r2, sp, #8 */
/* @0x1670c4 ldr r12, [r5] */
/* @0x1670c8 mov r3, sp */
/* @0x1670cc mov r1, r6 */
/* @0x1670d0 str r6, [sp] */
/* @0x1670d4 mul lr, r9, lr */
/* @0x1670d8 str r6, [r2, #-0x4]! */
/* @0x1670dc lsl lr, lr, #2 */
/* @0x1670e0 str lr, [r4, #0x10] */
/* @0x1670e4 str r0, [r4, #0x14] */
/* @0x1670e8 mov r0, r5 */
/* @0x1670ec ldr r12, [r12, #0x24] */
/* @0x1670f0 blx r12 */
/* @0x1670f4 ldr r3, [r4, #0xc] */
/* @0x1670f8 ldr r12, [r4, #0x14] */
/* @0x1670fc cmp r3, r6 */
/* @0x167100 mov r9, r0 */
/* @0x167104 ble 0x167148 <_ZN9CBitmap32C2EP7IBitmapbbi+0x178> */
/* @0x167108 ldr r2, [r4, #0x8] */
/* @0x16710c ldr r1, [sp, #0x4] */
/* @0x167110 lsl r2, r2, #2 */
/* @0x167114 mov r0, r12 */
/* @0x167118 add r6, r6, #1 */
/* @0x16711c bl 0xb65bc <memcpy@plt> */
/* @0x167120 ldr r3, [r4, #0xc] */
/* @0x167124 ldr r2, [r4, #0x8] */
/* @0x167128 ldr r1, [sp, #0x4] */
/* @0x16712c cmp r3, r6 */
/* @0x167130 ldr r3, [sp] */
/* @0x167134 lsl r2, r2, #2 */
/* @0x167138 add r1, r1, r3 */
/* @0x16713c str r1, [sp, #0x4] */
/* @0x167140 add r12, r0, r2 */
/* @0x167144 bgt 0x167114 <_ZN9CBitmap32C2EP7IBitmapbbi+0x144> */
/* @0x167148 ldr r3, [r5] */
/* @0x16714c mov r1, r9 */
/* @0x167150 mov r0, r5 */
/* @0x167154 ldr r3, [r3, #0x28] */
/* @0x167158 blx r3 */
/* @0x16715c cmp r7, #0 */
/* @0x167160 beq 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88> */
/* @0x167164 mov r0, r4 */
/* @0x167168 bl 0x166404 <_ZN9CBitmap3216RemoveBackgroundEv> */
/* @0x16716c cmp r8, #0 */
/* @0x167170 beq 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88> */
/* @0x167174 mov r0, r4 */
/* @0x167178 bl 0x1661fc <_ZN9CBitmap3211SmoothEdgesEv> */
/* @0x16717c b 0x167058 <_ZN9CBitmap32C2EP7IBitmapbbi+0x88> */
/* @0x167180 eoreq r9, r8, r12, lsl r1 */
/* @0x167184 andseq r3, lr, r12, lsl r5 */

/* ── FUNC 0x166fd0 · CBitmap32::CBitmap32(IBitmap*, bool, bool, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x167188 · CBitmap32::CBitmap32(IBitmap*, bool, bool, bool) · size=232 · insn=58 */
/* @0x167188 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x16718c sub sp, sp, #12 */
/* @0x167190 mov r4, r0 */
/* @0x167194 ldr r0, [pc, #0xd0] */
/* @0x167198 ldrb r12, [sp, #0x28] */
/* @0x16719c mov r5, #0 */
/* @0x1671a0 ldr r0, [pc, r0] */
/* @0x1671a4 mov r9, r1 */
/* @0x1671a8 cmp r12, #0 */
/* @0x1671ac add r0, r0, #8 */
/* @0x1671b0 mov r8, r2 */
/* @0x1671b4 str r0, [r4] */
/* @0x1671b8 mov r7, r3 */
/* @0x1671bc strb r5, [r4, #0x4] */
/* @0x1671c0 str r5, [r4, #0x8] */
/* @0x1671c4 mov r0, #24 */
/* @0x1671c8 str r5, [r4, #0xc] */
/* @0x1671cc str r5, [r4, #0x10] */
/* @0x1671d0 str r5, [r4, #0x14] */
/* @0x1671d4 beq 0x167224 <_ZN9CBitmap32C2EP7IBitmapbbb+0x9c> */
/* @0x1671d8 bl 0x27c524 <_Znwj> */
/* @0x1671dc mov r1, r9 */
/* @0x1671e0 mov r2, r8 */
/* @0x1671e4 mov r3, r7 */
/* @0x1671e8 str r5, [sp] */
/* @0x1671ec mov r6, r0 */
/* @0x1671f0 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi> */
/* @0x1671f4 mov r0, r4 */
/* @0x1671f8 mov r1, r6 */
/* @0x1671fc bl 0x165dac <_ZN9CBitmap326AssignEPS_> */
/* @0x167200 cmp r6, r5 */
/* @0x167204 beq 0x167218 <_ZN9CBitmap32C2EP7IBitmapbbb+0x90> */
/* @0x167208 ldr r3, [r6] */
/* @0x16720c mov r0, r6 */
/* @0x167210 ldr r3, [r3, #0x4] */
/* @0x167214 blx r3 */
/* @0x167218 mov r0, r4 */
/* @0x16721c add sp, sp, #12 */
/* @0x167220 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x167224 bl 0x27c524 <_Znwj> */
/* @0x167228 mov r1, r9 */
/* @0x16722c mov r2, r8 */
/* @0x167230 mov r3, r7 */
/* @0x167234 mov r5, r0 */
/* @0x167238 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0x16723c mov r0, r4 */
/* @0x167240 mov r1, r5 */
/* @0x167244 bl 0x165dac <_ZN9CBitmap326AssignEPS_> */
/* @0x167248 cmp r5, #0 */
/* @0x16724c beq 0x167218 <_ZN9CBitmap32C2EP7IBitmapbbb+0x90> */
/* @0x167250 ldr r3, [r5] */
/* @0x167254 mov r0, r5 */
/* @0x167258 ldr r3, [r3, #0x4] */
/* @0x16725c blx r3 */
/* @0x167260 mov r0, r4 */
/* @0x167264 add sp, sp, #12 */
/* @0x167268 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x16726c eoreq r8, r8, r8, asr pc */

/* ── FUNC 0x167188 · CBitmap32::CBitmap32(IBitmap*, bool, bool, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x167270 · CBitmap32::SetAlpha(int) · size=96 · insn=24 */
/* @0x167270 ldrb r3, [r0, #0x4] */
/* @0x167274 str r4, [sp, #-0x4]! */
/* @0x167278 cmp r3, #0 */
/* @0x16727c beq 0x1672c8 <_ZN9CBitmap328SetAlphaEi+0x58> */
/* @0x167280 ldr r3, [r0, #0xc] */
/* @0x167284 lsl r1, r1, #24 */
/* @0x167288 ldr r2, [r0, #0x8] */
/* @0x16728c mul r3, r2, r3 */
/* @0x167290 cmp r3, #0 */
/* @0x167294 ble 0x1672c8 <_ZN9CBitmap328SetAlphaEi+0x58> */
/* @0x167298 ldr r2, [r0, #0x14] */
/* @0x16729c mov r3, #0 */
/* @0x1672a0 ldr r12, [r2] */
/* @0x1672a4 add r3, r3, #1 */
/* @0x1672a8 bic r12, r12, #-16777216 */
/* @0x1672ac add r12, r12, r1 */
/* @0x1672b0 str r12, [r2], #4 */
/* @0x1672b4 ldr r12, [r0, #0xc] */
/* @0x1672b8 ldr r4, [r0, #0x8] */
/* @0x1672bc mul r12, r4, r12 */
/* @0x1672c0 cmp r12, r3 */
/* @0x1672c4 bgt 0x1672a0 <_ZN9CBitmap328SetAlphaEi+0x30> */
/* @0x1672c8 ldr r4, [sp], #4 */
/* @0x1672cc bx lr */

/* ── FUNC 0x1672d0 · CBitmap32::SetAlphaFromBitmap(CBitmap32*) · size=220 · insn=55 */
/* @0x1672d0 ldrb r3, [r0, #0x4] */
/* @0x1672d4 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1672d8 cmp r3, #0 */
/* @0x1672dc sub sp, sp, #8 */
/* @0x1672e0 beq 0x1673a0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xd0> */
/* @0x1672e4 cmp r1, #0 */
/* @0x1672e8 beq 0x1673a0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xd0> */
/* @0x1672ec ldr r2, [r0, #0xc] */
/* @0x1672f0 ldr r10, [r1, #0xc] */
/* @0x1672f4 ldr r3, [r0, #0x8] */
/* @0x1672f8 ldr r7, [r1, #0x8] */
/* @0x1672fc cmp r10, r2 */
/* @0x167300 movge r10, r2 */
/* @0x167304 str r10, [sp, #0x4] */
/* @0x167308 cmp r7, r3 */
/* @0x16730c movge r7, r3 */
/* @0x167310 cmp r10, #0 */
/* @0x167314 ble 0x1673a0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xd0> */
/* @0x167318 movw r9, #0xaaab */
/* @0x16731c movt r9, #0xaaaa */
/* @0x167320 mov r5, #0 */
/* @0x167324 cmp r7, #0 */
/* @0x167328 ble 0x167390 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0xc0> */
/* @0x16732c ldr r8, [r1, #0x14] */
/* @0x167330 mov r3, #0 */
/* @0x167334 ldr r6, [r0, #0x14] */
/* @0x167338 ldr r2, [r1, #0x8] */
/* @0x16733c ldr r12, [r0, #0x8] */
/* @0x167340 mla r2, r2, r5, r3 */
/* @0x167344 mla r12, r12, r5, r3 */
/* @0x167348 add r3, r3, #1 */
/* @0x16734c ldr r2, [r8, r2, lsl #2] */
/* @0x167350 ubfx r4, r2, #0x10, #0x8 */
/* @0x167354 ubfx r11, r2, #0x8, #0x8 */
/* @0x167358 add r11, r11, r4 */
/* @0x16735c ldr r4, [r6, r12, lsl #2] */
/* @0x167360 uxtab r2, r11, r2 */
/* @0x167364 and r11, r4, #-16777216 */
/* @0x167368 bic r4, r4, #-16777216 */
/* @0x16736c umull r10, r2, r9, r2 */
/* @0x167370 lsr r2, r2, #1 */
/* @0x167374 lsl r2, r2, #24 */
/* @0x167378 cmp r2, r11 */
/* @0x16737c addls r4, r4, r2 */
/* @0x167380 addhi r4, r4, r11 */
/* @0x167384 cmp r3, r7 */
/* @0x167388 str r4, [r6, r12, lsl #2] */
/* @0x16738c bne 0x167338 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0x68> */
/* @0x167390 ldr r3, [sp, #0x4] */
/* @0x167394 add r5, r5, #1 */
/* @0x167398 cmp r5, r3 */
/* @0x16739c bne 0x167324 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_+0x54> */
/* @0x1673a0 add sp, sp, #8 */
/* @0x1673a4 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1673a8 bx lr */

/* ── FUNC 0x1673ac · CBitmap32::Stretch(int, int) · size=348 · insn=87 */
/* @0x1673ac ldrb r3, [r0, #0x4] */
/* @0x1673b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1673b4 cmp r3, #0 */
/* @0x1673b8 sub sp, sp, #20 */
/* @0x1673bc mov r5, r0 */
/* @0x1673c0 mov r11, r1 */
/* @0x1673c4 mov r7, r2 */
/* @0x1673c8 beq 0x1674ec <_ZN9CBitmap327StretchEii+0x140> */
/* @0x1673cc ldr r3, [r0, #0x8] */
/* @0x1673d0 cmp r3, r1 */
/* @0x1673d4 beq 0x1674f4 <_ZN9CBitmap327StretchEii+0x148> */
/* @0x1673d8 mul r0, r7, r11 */
/* @0x1673dc ldr r1, [pc, #0x120] */
/* @0x1673e0 movw r2, #0x447 */
/* @0x1673e4 mov r3, #1 */
/* @0x1673e8 add r1, pc, r1 */
/* @0x1673ec lsl r0, r0, #2 */
/* @0x1673f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1673f4 ldr r2, [r5, #0x14] */
/* @0x1673f8 cmp r7, #0 */
/* @0x1673fc str r2, [sp, #0x4] */
/* @0x167400 str r0, [sp, #0xc] */
/* @0x167404 ble 0x1674cc <_ZN9CBitmap327StretchEii+0x120> */
/* @0x167408 mov r6, #0 */
/* @0x16740c lsl r3, r11, #2 */
/* @0x167410 str r0, [sp] */
/* @0x167414 str r3, [sp, #0x8] */
/* @0x167418 cmp r11, #0 */
/* @0x16741c ble 0x1674b0 <_ZN9CBitmap327StretchEii+0x104> */
/* @0x167420 mov r4, #0 */
/* @0x167424 mov r10, r11 */
/* @0x167428 ldr r8, [r5, #0x8] */
/* @0x16742c mov r1, r10 */
/* @0x167430 mul r0, r4, r8 */
/* @0x167434 bl 0x318d10 <__divsi3> */
/* @0x167438 vmov s15, r0 */
/* @0x16743c vcvt.f64.s32 d7, s15 */
/* @0x167440 vmov r0, r1, d7 */
/* @0x167444 bl 0xb6598 <floor@plt> */
/* @0x167448 ldr r9, [r5, #0xc] */
/* @0x16744c vmov d7, r0, r1 */
/* @0x167450 mov r1, r7 */
/* @0x167454 mul r0, r6, r9 */
/* @0x167458 vcvt.s32.f64 s15, d7 */
/* @0x16745c vmov r11, s15 */
/* @0x167460 bl 0x318d10 <__divsi3> */
/* @0x167464 vmov s15, r0 */
/* @0x167468 vcvt.f64.s32 d7, s15 */
/* @0x16746c vmov r0, r1, d7 */
/* @0x167470 bl 0xb6598 <floor@plt> */
/* @0x167474 cmp r8, r11 */
/* @0x167478 vmov d7, r0, r1 */
/* @0x16747c ble 0x1674a0 <_ZN9CBitmap327StretchEii+0xf4> */
/* @0x167480 vcvt.s32.f64 s13, d7 */
/* @0x167484 vmov r2, s13 */
/* @0x167488 mla r8, r2, r8, r11 */
/* @0x16748c cmp r9, r2 */
/* @0x167490 ldrgt r3, [sp, #0x4] */
/* @0x167494 ldrgt r2, [r3, r8, lsl #2] */
/* @0x167498 ldrgt r3, [sp] */
/* @0x16749c strgt r2, [r3, r4, lsl #2] */
/* @0x1674a0 add r4, r4, #1 */
/* @0x1674a4 cmp r4, r10 */
/* @0x1674a8 bne 0x167428 <_ZN9CBitmap327StretchEii+0x7c> */
/* @0x1674ac mov r11, r10 */
/* @0x1674b0 add r6, r6, #1 */
/* @0x1674b4 ldr r2, [sp] */
/* @0x1674b8 ldr r3, [sp, #0x8] */
/* @0x1674bc cmp r6, r7 */
/* @0x1674c0 add r2, r2, r3 */
/* @0x1674c4 str r2, [sp] */
/* @0x1674c8 bne 0x167418 <_ZN9CBitmap327StretchEii+0x6c> */
/* @0x1674cc ldr r0, [sp, #0x4] */
/* @0x1674d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1674d4 ldr r3, [sp, #0xc] */
/* @0x1674d8 str r11, [r5, #0x8] */
/* @0x1674dc str r7, [r5, #0xc] */
/* @0x1674e0 str r3, [r5, #0x14] */
/* @0x1674e4 mov r3, #0 */
/* @0x1674e8 str r3, [r5, #0x10] */
/* @0x1674ec add sp, sp, #20 */
/* @0x1674f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1674f4 ldr r3, [r0, #0xc] */
/* @0x1674f8 cmp r3, r2 */
/* @0x1674fc bne 0x1673d8 <_ZN9CBitmap327StretchEii+0x2c> */
/* @0x167500 b 0x1674ec <_ZN9CBitmap327StretchEii+0x140> */
/* @0x167504 ldrsbeq r3, [lr], -r8 */

/* ── FUNC 0x167508 · CBitmap32::BoundingBox() · size=224 · insn=56 */
/* @0x167508 ldr r1, [pc, #0xd4] */
/* @0x16750c mov r3, #1 */
/* @0x167510 push {r4, r5, r6, r7, r8, lr} */
/* @0x167514 add r1, pc, r1 */
/* @0x167518 mov r5, r0 */
/* @0x16751c movw r2, #0x476 */
/* @0x167520 mov r0, #16 */
/* @0x167524 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x167528 ldrb r3, [r5, #0x4] */
/* @0x16752c cmp r3, #0 */
/* @0x167530 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x167534 ldr r7, [r5, #0xc] */
/* @0x167538 cmp r7, #0 */
/* @0x16753c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x167540 ldr r4, [r5, #0x8] */
/* @0x167544 cmp r4, #0 */
/* @0x167548 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x16754c cmp r7, #0 */
/* @0x167550 mov r12, #0 */
/* @0x167554 sub r2, r4, #1 */
/* @0x167558 sub r3, r7, #1 */
/* @0x16755c str r12, [r0, #0x8] */
/* @0x167560 stm r0, {r2, r3} */
/* @0x167564 str r12, [r0, #0xc] */
/* @0x167568 pople {r4, r5, r6, r7, r8, pc} */
/* @0x16756c lsl r8, r4, #2 */
/* @0x167570 mvn r6, #3 */
/* @0x167574 cmp r4, #0 */
/* @0x167578 ble 0x1675d0 <_ZN9CBitmap3211BoundingBoxEv+0xc8> */
/* @0x16757c ldr r2, [r5, #0x14] */
/* @0x167580 mov r3, #0 */
/* @0x167584 add r2, r2, r6 */
/* @0x167588 ldr r1, [r2, #0x4]! */
/* @0x16758c tst r1, #-16777216 */
/* @0x167590 beq 0x1675c4 <_ZN9CBitmap3211BoundingBoxEv+0xbc> */
/* @0x167594 ldr r1, [r0] */
/* @0x167598 cmp r1, r3 */
/* @0x16759c ldr r1, [r0, #0x8] */
/* @0x1675a0 strgt r3, [r0] */
/* @0x1675a4 cmp r1, r3 */
/* @0x1675a8 ldr r1, [r0, #0x4] */
/* @0x1675ac strlt r3, [r0, #0x8] */
/* @0x1675b0 cmp r1, r12 */
/* @0x1675b4 ldr r1, [r0, #0xc] */
/* @0x1675b8 strgt r12, [r0, #0x4] */
/* @0x1675bc cmp r1, r12 */
/* @0x1675c0 strlt r12, [r0, #0xc] */
/* @0x1675c4 add r3, r3, #1 */
/* @0x1675c8 cmp r3, r4 */
/* @0x1675cc bne 0x167588 <_ZN9CBitmap3211BoundingBoxEv+0x80> */
/* @0x1675d0 add r12, r12, #1 */
/* @0x1675d4 add r6, r6, r8 */
/* @0x1675d8 cmp r12, r7 */
/* @0x1675dc bne 0x167574 <_ZN9CBitmap3211BoundingBoxEv+0x6c> */
/* @0x1675e0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1675e4 andseq r3, lr, r12, lsr #1 */

/* ── FUNC 0x1675e8 · CBitmap32::CreateBitmap24() · size=316 · insn=79 */
/* @0x1675e8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1675ec mov r4, r0 */
/* @0x1675f0 ldrb r0, [r0, #0x4] */
/* @0x1675f4 sub sp, sp, #8 */
/* @0x1675f8 cmp r0, #0 */
/* @0x1675fc beq 0x16771c <_ZN9CBitmap3214CreateBitmap24Ev+0x134> */
/* @0x167600 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x167604 mov r1, #6 */
/* @0x167608 mov r5, #0 */
/* @0x16760c ldr r3, [r0] */
/* @0x167610 mov r7, r0 */
/* @0x167614 ldr r3, [r3, #0x1c] */
/* @0x167618 blx r3 */
/* @0x16761c ldr r3, [r7] */
/* @0x167620 mov r0, r7 */
/* @0x167624 ldr r1, [r4, #0x8] */
/* @0x167628 ldr r3, [r3, #0xc] */
/* @0x16762c blx r3 */
/* @0x167630 ldr r3, [r7] */
/* @0x167634 mov r0, r7 */
/* @0x167638 ldr r1, [r4, #0xc] */
/* @0x16763c ldr r3, [r3, #0x14] */
/* @0x167640 blx r3 */
/* @0x167644 add r2, sp, #8 */
/* @0x167648 mov r3, sp */
/* @0x16764c mov r0, r7 */
/* @0x167650 str r5, [r2, #-0x4]! */
/* @0x167654 mov r1, r5 */
/* @0x167658 ldr r12, [r7] */
/* @0x16765c str r5, [sp] */
/* @0x167660 ldr r12, [r12, #0x24] */
/* @0x167664 blx r12 */
/* @0x167668 ldr r3, [r4, #0xc] */
/* @0x16766c cmp r3, r5 */
/* @0x167670 ble 0x167704 <_ZN9CBitmap3214CreateBitmap24Ev+0x11c> */
/* @0x167674 ldr r6, [sp, #0x4] */
/* @0x167678 mov r12, r5 */
/* @0x16767c ldr r8, [sp] */
/* @0x167680 ldr lr, [r4, #0x8] */
/* @0x167684 cmp lr, #0 */
/* @0x167688 movgt r2, #0 */
/* @0x16768c movgt r3, r2 */
/* @0x167690 ble 0x1676f0 <_ZN9CBitmap3214CreateBitmap24Ev+0x108> */
/* @0x167694 mla lr, lr, r12, r3 */
/* @0x167698 ldr r1, [r4, #0x14] */
/* @0x16769c add r5, r6, r2 */
/* @0x1676a0 ldr r1, [r1, lr, lsl #2] */
/* @0x1676a4 lsr r1, r1, #16 */
/* @0x1676a8 strb r1, [r5, #0x2] */
/* @0x1676ac ldr lr, [r4, #0x8] */
/* @0x1676b0 ldr r1, [r4, #0x14] */
/* @0x1676b4 mla lr, lr, r12, r3 */
/* @0x1676b8 ldr r1, [r1, lr, lsl #2] */
/* @0x1676bc lsr r1, r1, #8 */
/* @0x1676c0 strb r1, [r5, #0x1] */
/* @0x1676c4 ldr r5, [r4, #0x8] */
/* @0x1676c8 ldr lr, [r4, #0x14] */
/* @0x1676cc mla r5, r5, r12, r3 */
/* @0x1676d0 add r3, r3, #1 */
/* @0x1676d4 ldr lr, [lr, r5, lsl #2] */
/* @0x1676d8 strb lr, [r6, r2] */
/* @0x1676dc add r2, r2, #3 */
/* @0x1676e0 ldr lr, [r4, #0x8] */
/* @0x1676e4 cmp lr, r3 */
/* @0x1676e8 bgt 0x167694 <_ZN9CBitmap3214CreateBitmap24Ev+0xac> */
/* @0x1676ec ldr r3, [r4, #0xc] */
/* @0x1676f0 add r12, r12, #1 */
/* @0x1676f4 add r6, r6, r8 */
/* @0x1676f8 cmp r3, r12 */
/* @0x1676fc bgt 0x167684 <_ZN9CBitmap3214CreateBitmap24Ev+0x9c> */
/* @0x167700 str r6, [sp, #0x4] */
/* @0x167704 ldr r3, [r7] */
/* @0x167708 mov r1, r0 */
/* @0x16770c mov r0, r7 */
/* @0x167710 ldr r3, [r3, #0x28] */
/* @0x167714 blx r3 */
/* @0x167718 mov r0, r7 */
/* @0x16771c add sp, sp, #8 */
/* @0x167720 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x167724 · CBitmap32::CreateBitmap32() · size=288 · insn=72 */
/* @0x167724 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x167728 mov r5, r0 */
/* @0x16772c ldrb r0, [r0, #0x4] */
/* @0x167730 sub sp, sp, #8 */
/* @0x167734 cmp r0, #0 */
/* @0x167738 beq 0x16783c <_ZN9CBitmap3214CreateBitmap32Ev+0x118> */
/* @0x16773c bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x167740 mov r1, #7 */
/* @0x167744 mov r9, #0 */
/* @0x167748 ldr r3, [r0] */
/* @0x16774c mov r7, r0 */
/* @0x167750 ldr r3, [r3, #0x1c] */
/* @0x167754 blx r3 */
/* @0x167758 ldr r3, [r7] */
/* @0x16775c mov r0, r7 */
/* @0x167760 ldr r1, [r5, #0x8] */
/* @0x167764 ldr r3, [r3, #0xc] */
/* @0x167768 blx r3 */
/* @0x16776c ldr r3, [r7] */
/* @0x167770 mov r0, r7 */
/* @0x167774 ldr r1, [r5, #0xc] */
/* @0x167778 ldr r3, [r3, #0x14] */
/* @0x16777c blx r3 */
/* @0x167780 add r2, sp, #8 */
/* @0x167784 mov r0, r7 */
/* @0x167788 mov r1, r9 */
/* @0x16778c str r9, [r2, #-0x4]! */
/* @0x167790 mov r3, sp */
/* @0x167794 ldr r12, [r7] */
/* @0x167798 str r9, [sp] */
/* @0x16779c ldr r12, [r12, #0x24] */
/* @0x1677a0 blx r12 */
/* @0x1677a4 ldr r2, [r5, #0xc] */
/* @0x1677a8 cmp r2, r9 */
/* @0x1677ac ble 0x167824 <_ZN9CBitmap3214CreateBitmap32Ev+0x100> */
/* @0x1677b0 ldr r4, [sp, #0x4] */
/* @0x1677b4 ldr r10, [sp] */
/* @0x1677b8 ldr r3, [r5, #0x8] */
/* @0x1677bc cmp r3, #0 */
/* @0x1677c0 movgt r2, #0 */
/* @0x1677c4 movgt r12, r2 */
/* @0x1677c8 ble 0x167810 <_ZN9CBitmap3214CreateBitmap32Ev+0xec> */
/* @0x1677cc mla r3, r3, r9, r12 */
/* @0x1677d0 ldr r1, [r5, #0x14] */
/* @0x1677d4 add lr, r4, r2 */
/* @0x1677d8 add r12, r12, #1 */
/* @0x1677dc ldr r3, [r1, r3, lsl #2] */
/* @0x1677e0 lsr r6, r3, #24 */
/* @0x1677e4 lsr r8, r3, #16 */
/* @0x1677e8 strb r6, [lr, #0x3] */
/* @0x1677ec lsr r6, r3, #8 */
/* @0x1677f0 strb r8, [lr, #0x2] */
/* @0x1677f4 strb r6, [lr, #0x1] */
/* @0x1677f8 strb r3, [r4, r2] */
/* @0x1677fc add r2, r2, #4 */
/* @0x167800 ldr r3, [r5, #0x8] */
/* @0x167804 cmp r3, r12 */
/* @0x167808 bgt 0x1677cc <_ZN9CBitmap3214CreateBitmap32Ev+0xa8> */
/* @0x16780c ldr r2, [r5, #0xc] */
/* @0x167810 add r9, r9, #1 */
/* @0x167814 add r4, r4, r10 */
/* @0x167818 cmp r2, r9 */
/* @0x16781c bgt 0x1677bc <_ZN9CBitmap3214CreateBitmap32Ev+0x98> */
/* @0x167820 str r4, [sp, #0x4] */
/* @0x167824 ldr r3, [r7] */
/* @0x167828 mov r1, r0 */
/* @0x16782c mov r0, r7 */
/* @0x167830 ldr r3, [r3, #0x28] */
/* @0x167834 blx r3 */
/* @0x167838 mov r0, r7 */
/* @0x16783c add sp, sp, #8 */
/* @0x167840 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x167844 · CBitmap32::SaveToStream(CStream*) · size=172 · insn=43 */
/* @0x167844 push {r4, r5, r6, lr} */
/* @0x167848 mov r5, r1 */
/* @0x16784c mov r4, r0 */
/* @0x167850 mov r1, #540 */
/* @0x167854 mov r0, r5 */
/* @0x167858 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x16785c mov r0, r5 */
/* @0x167860 ldrb r1, [r4, #0x4] */
/* @0x167864 bl 0x201bb8 <_ZN7CStream12WriteBooleanEb> */
/* @0x167868 ldrb r3, [r4, #0x4] */
/* @0x16786c cmp r3, #0 */
/* @0x167870 bne 0x16787c <_ZN9CBitmap3212SaveToStreamEP7CStream+0x38> */
/* @0x167874 mov r0, #1 */
/* @0x167878 pop {r4, r5, r6, pc} */
/* @0x16787c mov r0, r5 */
/* @0x167880 ldr r1, [r4, #0x8] */
/* @0x167884 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x167888 ldr r1, [r4, #0xc] */
/* @0x16788c mov r0, r5 */
/* @0x167890 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x167894 mov r0, #32 */
/* @0x167898 bl 0x27c524 <_Znwj> */
/* @0x16789c mov r1, #0 */
/* @0x1678a0 mov r6, r0 */
/* @0x1678a4 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x1678a8 ldr r3, [r4, #0x8] */
/* @0x1678ac mov r0, r6 */
/* @0x1678b0 ldr r2, [r4, #0xc] */
/* @0x1678b4 ldr r1, [r4, #0x14] */
/* @0x1678b8 mul r2, r2, r3 */
/* @0x1678bc lsl r2, r2, #2 */
/* @0x1678c0 bl 0x201728 <_ZN7CStream11WriteBufferEPvi> */
/* @0x1678c4 mov r0, r5 */
/* @0x1678c8 mov r1, r6 */
/* @0x1678cc bl 0x2021fc <_ZN7CStream21WriteCompressedStreamEPS_> */
/* @0x1678d0 cmp r6, #0 */
/* @0x1678d4 beq 0x167874 <_ZN9CBitmap3212SaveToStreamEP7CStream+0x30> */
/* @0x1678d8 mov r0, r6 */
/* @0x1678dc bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1678e0 mov r0, r6 */
/* @0x1678e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1678e8 mov r0, #1 */
/* @0x1678ec pop {r4, r5, r6, pc} */

/* ── FUNC 0x1678f0 · CBitmap32::__Free() · size=44 · insn=11 */
/* @0x1678f0 push {r4, lr} */
/* @0x1678f4 mov r4, r0 */
/* @0x1678f8 ldr r0, [r0, #0x14] */
/* @0x1678fc cmp r0, #0 */
/* @0x167900 popeq {r4, pc} */
/* @0x167904 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x167908 mov r3, #0 */
/* @0x16790c str r3, [r4, #0x14] */
/* @0x167910 str r3, [r4, #0x10] */
/* @0x167914 strb r3, [r4, #0x4] */
/* @0x167918 pop {r4, pc} */

/* ── FUNC 0x16791c · CBitmap32::~CBitmap32() · size=40 · insn=10 */
/* @0x16791c ldr r3, [pc, #0x1c] */
/* @0x167920 push {r4, lr} */
/* @0x167924 ldr r3, [pc, r3] */
/* @0x167928 mov r4, r0 */
/* @0x16792c add r3, r3, #8 */
/* @0x167930 str r3, [r0] */
/* @0x167934 bl 0x1678f0 <_ZN9CBitmap326__FreeEv> */
/* @0x167938 mov r0, r4 */
/* @0x16793c pop {r4, pc} */
/* @0x167940 .word 0x002887d4 */

/* ── FUNC 0x16791c · CBitmap32::~CBitmap32() · alias of the symbol above · insn=0 */

/* ── FUNC 0x167944 · CBitmap32::~CBitmap32() · size=28 · insn=7 */
/* @0x167944 push {r4, lr} */
/* @0x167948 mov r4, r0 */
/* @0x16794c bl 0x16791c <_ZN9CBitmap32D2Ev> */
/* @0x167950 mov r0, r4 */
/* @0x167954 bl 0x27d1d0 <_ZdlPv> */
/* @0x167958 mov r0, r4 */
/* @0x16795c pop {r4, pc} */

/* ── FUNC 0x167960 · CBitmap32::GetWidth() · size=8 · insn=2 */
/* @0x167960 ldr r0, [r0, #0x8] */
/* @0x167964 bx lr */

/* ── FUNC 0x167968 · CBitmap32::GetHeight() · size=8 · insn=2 */
/* @0x167968 ldr r0, [r0, #0xc] */
/* @0x16796c bx lr */

/* ── FUNC 0x167970 · CBitmap32::GetData() · size=8 · insn=2 */
/* @0x167970 add r0, r0, #16 */
/* @0x167974 bx lr */

/* ── FUNC 0x167978 · CBitmap32::SaveToFile(char const*) · size=700 · insn=175 */
/* @0x167978 push {r4, r5, r6, lr} */
/* @0x16797c mov r4, r1 */
/* @0x167980 sub sp, sp, #48 */
/* @0x167984 ldr r1, [pc, #0x278] */
/* @0x167988 str r0, [sp, #0x18] */
/* @0x16798c add r1, pc, r1 */
/* @0x167990 mov r0, r4 */
/* @0x167994 bl 0xb6844 <fopen@plt> */
/* @0x167998 ldr r2, [pc, #0x268] */
/* @0x16799c add r2, pc, r2 */
/* @0x1679a0 str r2, [sp, #0x1c] */
/* @0x1679a4 cmp r0, #0 */
/* @0x1679a8 str r0, [sp, #0x24] */
/* @0x1679ac beq 0x167b98 <_ZN9CBitmap3210SaveToFileEPKc+0x220> */
/* @0x1679b0 ldr r0, [pc, #0x254] */
/* @0x1679b4 mov r1, #0 */
/* @0x1679b8 mov r2, r1 */
/* @0x1679bc mov r3, r1 */
/* @0x1679c0 add r0, pc, r0 */
/* @0x1679c4 blx 0x2b0364 <png_create_write_struct> */
/* @0x1679c8 subs r2, r0, #0 */
/* @0x1679cc str r2, [sp, #0x20] */
/* @0x1679d0 beq 0x167bcc <_ZN9CBitmap3210SaveToFileEPKc+0x254> */
/* @0x1679d4 blx 0x2a5b64 <png_create_info_struct> */
/* @0x1679d8 cmp r0, #0 */
/* @0x1679dc str r0, [sp, #0x28] */
/* @0x1679e0 beq 0x167be4 <_ZN9CBitmap3210SaveToFileEPKc+0x26c> */
/* @0x1679e4 ldr r3, [pc, #0x224] */
/* @0x1679e8 mov r2, #256 */
/* @0x1679ec ldr r12, [sp, #0x1c] */
/* @0x1679f0 ldr r0, [sp, #0x20] */
/* @0x1679f4 ldr r1, [r12, r3] */
/* @0x1679f8 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x1679fc bl 0xb6904 <setjmp@plt> */
/* @0x167a00 cmp r0, #0 */
/* @0x167a04 bne 0x167b48 <_ZN9CBitmap3210SaveToFileEPKc+0x1d0> */
/* @0x167a08 ldr r0, [sp, #0x20] */
/* @0x167a0c ldr r1, [sp, #0x24] */
/* @0x167a10 blx 0x2a5f28 <png_init_io> */
/* @0x167a14 ldr r3, [pc, #0x1f4] */
/* @0x167a18 ldr r12, [sp, #0x1c] */
/* @0x167a1c mov r2, #256 */
/* @0x167a20 ldr r0, [sp, #0x20] */
/* @0x167a24 ldr r1, [r12, r3] */
/* @0x167a28 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x167a2c bl 0xb6904 <setjmp@plt> */
/* @0x167a30 subs r4, r0, #0 */
/* @0x167a34 bne 0x167b88 <_ZN9CBitmap3210SaveToFileEPKc+0x210> */
/* @0x167a38 ldr r0, [sp, #0x18] */
/* @0x167a3c bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x167a40 mov r5, r0 */
/* @0x167a44 ldr r0, [sp, #0x18] */
/* @0x167a48 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x167a4c mov r2, r5 */
/* @0x167a50 mov r12, #6 */
/* @0x167a54 str r4, [sp, #0x8] */
/* @0x167a58 str r12, [sp, #0x4] */
/* @0x167a5c mov r1, #8 */
/* @0x167a60 str r4, [sp, #0xc] */
/* @0x167a64 str r1, [sp] */
/* @0x167a68 str r4, [sp, #0x10] */
/* @0x167a6c ldr r1, [sp, #0x28] */
/* @0x167a70 mov r3, r0 */
/* @0x167a74 ldr r0, [sp, #0x20] */
/* @0x167a78 blx 0x2aea84 <png_set_IHDR> */
/* @0x167a7c ldr r0, [sp, #0x20] */
/* @0x167a80 ldr r1, [sp, #0x28] */
/* @0x167a84 blx 0x2afe14 <png_write_info> */
/* @0x167a88 ldr r3, [pc, #0x180] */
/* @0x167a8c ldr r12, [sp, #0x1c] */
/* @0x167a90 mov r2, #256 */
/* @0x167a94 ldr r0, [sp, #0x20] */
/* @0x167a98 ldr r1, [r12, r3] */
/* @0x167a9c blx 0x2a653c <png_set_longjmp_fn> */
/* @0x167aa0 bl 0xb6904 <setjmp@plt> */
/* @0x167aa4 subs r4, r0, #0 */
/* @0x167aa8 bne 0x167b78 <_ZN9CBitmap3210SaveToFileEPKc+0x200> */
/* @0x167aac ldr r0, [sp, #0x18] */
/* @0x167ab0 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x167ab4 lsl r0, r0, #2 */
/* @0x167ab8 bl 0xb6544 <malloc@plt> */
/* @0x167abc ldr r2, [sp, #0x18] */
/* @0x167ac0 ldr r5, [r2, #0x14] */
/* @0x167ac4 str r0, [sp, #0x2c] */
/* @0x167ac8 sub r6, r0, #4 */
/* @0x167acc b 0x167adc <_ZN9CBitmap3210SaveToFileEPKc+0x164> */
/* @0x167ad0 str r5, [r6, #0x4]! */
/* @0x167ad4 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x167ad8 add r5, r5, r0, lsl #2 */
/* @0x167adc ldr r0, [sp, #0x18] */
/* @0x167ae0 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x167ae4 cmp r4, r0 */
/* @0x167ae8 ldr r0, [sp, #0x18] */
/* @0x167aec add r4, r4, #1 */
/* @0x167af0 blt 0x167ad0 <_ZN9CBitmap3210SaveToFileEPKc+0x158> */
/* @0x167af4 ldr r0, [sp, #0x20] */
/* @0x167af8 ldr r1, [sp, #0x2c] */
/* @0x167afc blx 0x2b0510 <png_write_image> */
/* @0x167b00 ldr r3, [pc, #0x108] */
/* @0x167b04 ldr r12, [sp, #0x1c] */
/* @0x167b08 mov r2, #256 */
/* @0x167b0c ldr r0, [sp, #0x20] */
/* @0x167b10 ldr r1, [r12, r3] */
/* @0x167b14 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x167b18 bl 0xb6904 <setjmp@plt> */
/* @0x167b1c subs r1, r0, #0 */
/* @0x167b20 bne 0x167bf4 <_ZN9CBitmap3210SaveToFileEPKc+0x27c> */
/* @0x167b24 ldr r0, [sp, #0x20] */
/* @0x167b28 blx 0x2b002c <png_write_end> */
/* @0x167b2c ldr r0, [sp, #0x2c] */
/* @0x167b30 bl 0xb655c <free@plt> */
/* @0x167b34 ldr r0, [sp, #0x24] */
/* @0x167b38 bl 0xb6850 <fclose@plt> */
/* @0x167b3c mov r0, #1 */
/* @0x167b40 add sp, sp, #48 */
/* @0x167b44 pop {r4, r5, r6, pc} */
/* @0x167b48 ldr r1, [pc, #0xc4] */
/* @0x167b4c ldr r3, [pc, #0xc4] */
/* @0x167b50 add r1, pc, r1 */
/* @0x167b54 ldr r0, [sp, #0x1c] */
/* @0x167b58 ldr r3, [r0, r3] */
/* @0x167b5c ldr r0, [r3] */
/* @0x167b60 ldr r3, [r0] */
/* @0x167b64 ldr r3, [r3, #0xc] */
/* @0x167b68 blx r3 */
/* @0x167b6c mov r0, #0 */
/* @0x167b70 add sp, sp, #48 */
/* @0x167b74 pop {r4, r5, r6, pc} */
/* @0x167b78 ldr r1, [pc, #0x9c] */
/* @0x167b7c ldr r3, [pc, #0x94] */
/* @0x167b80 add r1, pc, r1 */
/* @0x167b84 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc> */
/* @0x167b88 ldr r1, [pc, #0x90] */
/* @0x167b8c ldr r3, [pc, #0x84] */
/* @0x167b90 add r1, pc, r1 */
/* @0x167b94 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc> */
/* @0x167b98 ldr r12, [sp, #0x1c] */
/* @0x167b9c mov r2, r4 */
/* @0x167ba0 ldr r3, [pc, #0x70] */
/* @0x167ba4 ldr r1, [pc, #0x78] */
/* @0x167ba8 ldr r3, [r12, r3] */
/* @0x167bac add r1, pc, r1 */
/* @0x167bb0 ldr r0, [r3] */
/* @0x167bb4 ldr r3, [r0] */
/* @0x167bb8 ldr r3, [r3, #0xc] */
/* @0x167bbc blx r3 */
/* @0x167bc0 ldr r0, [sp, #0x24] */
/* @0x167bc4 add sp, sp, #48 */
/* @0x167bc8 pop {r4, r5, r6, pc} */
/* @0x167bcc ldr r3, [pc, #0x44] */
/* @0x167bd0 ldr r12, [sp, #0x1c] */
/* @0x167bd4 ldr r1, [pc, #0x4c] */
/* @0x167bd8 ldr r3, [r12, r3] */
/* @0x167bdc add r1, pc, r1 */
/* @0x167be0 b 0x167b5c <_ZN9CBitmap3210SaveToFileEPKc+0x1e4> */
/* @0x167be4 ldr r1, [pc, #0x40] */
/* @0x167be8 ldr r3, [pc, #0x28] */
/* @0x167bec add r1, pc, r1 */
/* @0x167bf0 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc> */
/* @0x167bf4 ldr r1, [pc, #0x34] */
/* @0x167bf8 ldr r3, [pc, #0x18] */
/* @0x167bfc add r1, pc, r1 */
/* @0x167c00 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc> */
/* @0x167c04 ldrheq r8, [sp], -r8 */
/* @0x167c08 .word 0x0028a2b4 */
/* @0x167c0c andseq r2, lr, r12, ror r12 */
/* @0x167c10 .word 0xffffe4ac */
/* @0x167c14 andseq r2, lr, r8, asr r11 */
/* @0x167c18 .word 0xffffbac4 */
/* @0x167c1c andseq r2, lr, r0, lsl #23 */
/* @0x167c20 andseq r2, lr, r0, asr #22 */
/* @0x167c24 andseq r2, lr, r4, asr r10 */
/* @0x167c28 andseq r2, lr, r8, ror #20 */
/* @0x167c2c andseq r2, lr, r12, lsl #21 */
/* @0x167c30 andseq r2, lr, r4, lsr r11 */

/* ── FUNC 0x167c34 · RenderStateManager::Reset() · size=540 · insn=135 */
/* @0x167c34 ldr r3, [pc, #0x1f0] */
/* @0x167c38 mov r2, #1 */
/* @0x167c3c ldr r12, [pc, #0x1ec] */
/* @0x167c40 add r3, pc, r3 */
/* @0x167c44 ldr r1, [pc, #0x1e8] */
/* @0x167c48 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x167c4c mov r7, r2 */
/* @0x167c50 ldr r8, [r3, r12] */
/* @0x167c54 mov r4, #0 */
/* @0x167c58 ldr r6, [pc, #0x1d8] */
/* @0x167c5c mov r12, r4 */
/* @0x167c60 ldr r5, [pc, #0x1d4] */
/* @0x167c64 strb r2, [r8] */
/* @0x167c68 ldr r1, [r3, r1] */
/* @0x167c6c strb r2, [r1] */
/* @0x167c70 ldr r1, [r3, r6] */
/* @0x167c74 ldr r2, [r3, r5] */
/* @0x167c78 strb r7, [r1, r4] */
/* @0x167c7c mov r6, #1 */
/* @0x167c80 strb r12, [r2, r4] */
/* @0x167c84 add r4, r4, r6 */
/* @0x167c88 cmp r4, #8 */
/* @0x167c8c mov r5, #0 */
/* @0x167c90 bne 0x167c78 <_ZN18RenderStateManager5ResetEv+0x44> */
/* @0x167c94 ldr r2, [pc, #0x1a4] */
/* @0x167c98 vldr s15, [pc, #392] */
/* @0x167c9c ldr r8, [pc, #0x1a0] */
/* @0x167ca0 add r12, r0, #12 */
/* @0x167ca4 ldr r7, [pc, #0x19c] */
/* @0x167ca8 mov r1, #36 */
/* @0x167cac ldr r10, [r3, r2] */
/* @0x167cb0 mov r9, #3 */
/* @0x167cb4 ldr r2, [pc, #0x190] */
/* @0x167cb8 mov r11, #1065353216 */
/* @0x167cbc strb r5, [r10] */
/* @0x167cc0 mov r10, #2 */
/* @0x167cc4 ldr r8, [r3, r8] */
/* @0x167cc8 str r5, [r8] */
/* @0x167ccc mov r8, #6 */
/* @0x167cd0 ldr r7, [r3, r7] */
/* @0x167cd4 vstr s15, [r7] */
/* @0x167cd8 ldr r3, [r3, r2] */
/* @0x167cdc mov r7, #5 */
/* @0x167ce0 mvn r2, #0 */
/* @0x167ce4 str r9, [r0, #0x18] */
/* @0x167ce8 str r9, [r0, #0x6c] */
/* @0x167cec mvn r9, #0 */
/* @0x167cf0 str r11, [r3] */
/* @0x167cf4 mvn r3, #0 */
/* @0x167cf8 str r5, [r0, #0x14] */
/* @0x167cfc mov r11, #4 */
/* @0x167d00 strd r2, r3, [r0] */
/* @0x167d04 strd r2, r3, [r0, #8] */
/* @0x167d08 mov r2, #1065353216 */
/* @0x167d0c str r6, [r0, #0x20] */
/* @0x167d10 mov r3, #15 */
/* @0x167d14 str r5, [r0, #0x24] */
/* @0x167d18 str r5, [r0, #0x30] */
/* @0x167d1c str r5, [r0, #0x38] */
/* @0x167d20 str r6, [r0, #0x40] */
/* @0x167d24 str r5, [r0, #0x44] */
/* @0x167d28 str r5, [r0, #0x48] */
/* @0x167d2c str r5, [r0, #0x4c] */
/* @0x167d30 str r6, [r0, #0x50] */
/* @0x167d34 str r5, [r0, #0x54] */
/* @0x167d38 str r5, [r0, #0x5c] */
/* @0x167d3c str r5, [r0, #0x60] */
/* @0x167d40 str r5, [r0, #0x64] */
/* @0x167d44 str r5, [r0, #0x68] */
/* @0x167d48 str r10, [r0, #0x1c] */
/* @0x167d4c str r7, [r0, #0x28] */
/* @0x167d50 str r7, [r0, #0x3c] */
/* @0x167d54 str r8, [r0, #0x2c] */
/* @0x167d58 str r11, [r0, #0x34] */
/* @0x167d5c str r2, [r0, #0x58] */
/* @0x167d60 str r3, [r0, #0x70] */
/* @0x167d64 str r7, [r0, #0x98] */
/* @0x167d68 str r8, [r0, #0x9c] */
/* @0x167d6c str r5, [r0, #0x74] */
/* @0x167d70 str r6, [r0, #0x78] */
/* @0x167d74 str r6, [r0, #0x7c] */
/* @0x167d78 str r6, [r0, #0x80] */
/* @0x167d7c str r4, [r0, #0x84] */
/* @0x167d80 str r5, [r0, #0x88] */
/* @0x167d84 str r5, [r0, #0x94] */
/* @0x167d88 str r9, [r0, #0x8c] */
/* @0x167d8c str r9, [r0, #0x90] */
/* @0x167d90 ldr r3, [r12, #0x4]! */
/* @0x167d94 subs r1, r1, #1 */
/* @0x167d98 str r3, [r12, #0x1d0] */
/* @0x167d9c bne 0x167d90 <_ZN18RenderStateManager5ResetEv+0x15c> */
/* @0x167da0 mov r4, #0 */
/* @0x167da4 movt r4, #0x4180 */
/* @0x167da8 mov r3, r0 */
/* @0x167dac mov r12, #8 */
/* @0x167db0 mov r2, #1 */
/* @0x167db4 mov r6, #16 */
/* @0x167db8 mov r5, #2 */
/* @0x167dbc subs r12, r12, #1 */
/* @0x167dc0 str r2, [r3, #0xa0] */
/* @0x167dc4 str r2, [r3, #0xa4] */
/* @0x167dc8 add r3, r3, #40 */
/* @0x167dcc str r2, [r3, #0x88] */
/* @0x167dd0 str r1, [r3, #0x80] */
/* @0x167dd4 str r1, [r3, #0x84] */
/* @0x167dd8 str r1, [r3, #0x8c] */
/* @0x167ddc str r4, [r3, #0x90] */
/* @0x167de0 str r1, [r3, #0x94] */
/* @0x167de4 str r6, [r3, #0x98] */
/* @0x167de8 str r5, [r3, #0x9c] */
/* @0x167dec bne 0x167dbc <_ZN18RenderStateManager5ResetEv+0x188> */
/* @0x167df0 add r3, r0, #156 */
/* @0x167df4 mov r1, #80 */
/* @0x167df8 ldr r2, [r3, #0x4]! */
/* @0x167dfc subs r1, r1, #1 */
/* @0x167e00 str r2, [r3, #0x1d0] */
/* @0x167e04 bne 0x167df8 <_ZN18RenderStateManager5ResetEv+0x1c4> */
/* @0x167e08 movw r4, #0x3db8 */
/* @0x167e0c mov r12, #944 */
/* @0x167e10 str r1, [r0, r4] */
/* @0x167e14 mvn r2, #0 */
/* @0x167e18 mvn r3, #0 */
/* @0x167e1c strd r2, r3, [r0, r12] */
/* @0x167e20 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x167e24 bx lr */
/* @0x167e28 andeq r0, r0, r0 */
/* @0x167e2c eoreq r10, r8, r0, lsl r0 */
/* @0x167e30 .word 0xffffe4b0 */
/* @0x167e34 .word 0xffffe4b4 */
/* @0x167e38 .word 0xffffe4b8 */
/* @0x167e3c .word 0xffffe4bc */
/* @0x167e40 .word 0xffffe4c0 */
/* @0x167e44 .word 0xffffe4c4 */
/* @0x167e48 .word 0xffffe4c8 */
/* @0x167e4c .word 0xffffe4cc */

/* ── FUNC 0x167e50 · RenderStateManager::RenderStateManager() · size=20 · insn=5 */
/* @0x167e50 push {r4, lr} */
/* @0x167e54 mov r4, r0 */
/* @0x167e58 bl 0x167c34 <_ZN18RenderStateManager5ResetEv> */
/* @0x167e5c mov r0, r4 */
/* @0x167e60 pop {r4, pc} */

/* ── FUNC 0x167e50 · RenderStateManager::RenderStateManager() · alias of the symbol above · insn=0 */

/* ── FUNC 0x167e64 · RenderStateManager::SetRenderState(eRenderState, unsigned int) · size=144 · insn=36 */
/* @0x167e64 add r3, r0, r1, lsl #2 */
/* @0x167e68 push {r4, r5, r6, r7, r8} */
/* @0x167e6c ldr r12, [r3, #0x1e0] */
/* @0x167e70 cmp r12, r2 */
/* @0x167e74 beq 0x167ec4 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej+0x60> */
/* @0x167e78 ldr r12, [r3, #0x10] */
/* @0x167e7c cmp r12, r2 */
/* @0x167e80 mov r12, #1 */
/* @0x167e84 beq 0x167ecc <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej+0x68> */
/* @0x167e88 sub r6, r1, #32 */
/* @0x167e8c rsb r8, r1, #32 */
/* @0x167e90 lsl r5, r12, r6 */
/* @0x167e94 ldrd r6, r7, [r0] */
/* @0x167e98 orr r5, r5, r12, lsr r8 */
/* @0x167e9c lsl r4, r12, r1 */
/* @0x167ea0 orr r4, r4, r6 */
/* @0x167ea4 orr r5, r5, r7 */
/* @0x167ea8 strd r4, r5, [r0] */
/* @0x167eac str r2, [r3, #0x1e0] */
/* @0x167eb0 mov r1, #944 */
/* @0x167eb4 ldrd r2, r3, [r0, #8] */
/* @0x167eb8 orr r2, r2, r4 */
/* @0x167ebc orr r3, r3, r5 */
/* @0x167ec0 strd r2, r3, [r0, r1] */
/* @0x167ec4 pop {r4, r5, r6, r7, r8} */
/* @0x167ec8 bx lr */
/* @0x167ecc sub r4, r1, #32 */
/* @0x167ed0 rsb r8, r1, #32 */
/* @0x167ed4 lsl r7, r12, r4 */
/* @0x167ed8 ldrd r4, r5, [r0] */
/* @0x167edc orr r7, r7, r12, lsr r8 */
/* @0x167ee0 lsl r6, r12, r1 */
/* @0x167ee4 bic r4, r4, r6 */
/* @0x167ee8 bic r5, r5, r7 */
/* @0x167eec strd r4, r5, [r0] */
/* @0x167ef0 b 0x167eac <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej+0x48> */
