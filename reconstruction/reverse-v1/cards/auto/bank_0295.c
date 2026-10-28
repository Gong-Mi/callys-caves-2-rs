/* libyoyo.so 覆盖卡组 0295
 * 函数 0x319360..0x319c68，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x319360 · __aeabi_ui2f · size=40 · insn=2 */
/* @0x319360 mov r3, #0 */
/* @0x319364 b 0x319370 <__floatsisf+0x8> */

/* ── FUNC 0x319360 · __floatunsisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319368 · __aeabi_i2f · size=32 · insn=8 */
/* @0x319368 ands r3, r0, #-2147483648 */
/* @0x31936c rsbmi r0, r0, #0 */
/* @0x319370 movs r12, r0 */
/* @0x319374 bxeq lr */
/* @0x319378 orr r3, r3, #1258291200 */
/* @0x31937c mov r1, r0 */
/* @0x319380 mov r0, #0 */
/* @0x319384 b 0x3193c8 <__floatdisf+0x30> */

/* ── FUNC 0x319368 · __floatsisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319388 · __aeabi_ul2f · size=140 · insn=4 */
/* @0x319388 orrs r2, r0, r1 */
/* @0x31938c bxeq lr */
/* @0x319390 mov r3, #0 */
/* @0x319394 b 0x3193b0 <__floatdisf+0x18> */

/* ── FUNC 0x319388 · __floatundisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319398 · __aeabi_l2f · size=124 · insn=31 */
/* @0x319398 orrs r2, r0, r1 */
/* @0x31939c bxeq lr */
/* @0x3193a0 ands r3, r1, #-2147483648 */
/* @0x3193a4 bpl 0x3193b0 <__floatdisf+0x18> */
/* @0x3193a8 rsbs r0, r0, #0 */
/* @0x3193ac rsc r1, r1, #0 */
/* @0x3193b0 movs r12, r1 */
/* @0x3193b4 moveq r12, r0 */
/* @0x3193b8 moveq r1, r0 */
/* @0x3193bc moveq r0, #0 */
/* @0x3193c0 orr r3, r3, #1526726656 */
/* @0x3193c4 subeq r3, r3, #268435456 */
/* @0x3193c8 sub r3, r3, #8388608 */
/* @0x3193cc clz r2, r12 */
/* @0x3193d0 subs r2, r2, #8 */
/* @0x3193d4 sub r3, r3, r2, lsl #23 */
/* @0x3193d8 blt 0x3193f8 <__floatdisf+0x60> */
/* @0x3193dc add r3, r3, r1, lsl r2 */
/* @0x3193e0 lsl r12, r0, r2 */
/* @0x3193e4 rsb r2, r2, #32 */
/* @0x3193e8 cmp r12, #-2147483648 */
/* @0x3193ec adc r0, r3, r0, lsr r2 */
/* @0x3193f0 biceq r0, r0, #1 */
/* @0x3193f4 bx lr */
/* @0x3193f8 add r2, r2, #32 */
/* @0x3193fc lsl r12, r1, r2 */
/* @0x319400 rsb r2, r2, #32 */
/* @0x319404 orrs r0, r0, r12, lsl #1 */
/* @0x319408 adc r0, r3, r1, lsr r2 */
/* @0x31940c biceq r0, r0, r12, lsr #31 */
/* @0x319410 bx lr */

/* ── FUNC 0x319398 · __floatdisf · alias of the symbol above · insn=0 */

/* ── FUNC 0x319414 · anon_319414 · size=64 · insn=17 */
/* @0x319414 cmp r3, #0 */
/* @0x319418 cmpeq r2, #0 */
/* @0x31941c bne 0x31943c <__aeabi_ldivmod+0x28> */
/* @0x319420 cmp r1, #0 */
/* @0x319424 cmpeq r0, #0 */
/* @0x319428 movlt r1, #-2147483648 */
/* @0x31942c movlt r0, #0 */
/* @0x319430 mvngt r1, #-2147483648 */
/* @0x319434 mvngt r0, #0 */
/* @0x319438 b 0x319458 <__aeabi_ldiv0> */
/* @0x31943c sub sp, sp, #8 */
/* @0x319440 push {sp, lr} */
/* @0x319444 bl 0x3195b8 <__gnu_ldivmod_helper> */
/* @0x319448 ldr lr, [sp, #0x4] */
/* @0x31944c add sp, sp, #8 */
/* @0x319450 pop {r2, r3} */
/* @0x319454 bx lr */

/* ── FUNC 0x319458 · __aeabi_idiv0 · size=16 · insn=4 */
/* @0x319458 push {r1, lr} */
/* @0x31945c mov r0, #8 */
/* @0x319460 bl 0xb6fb8 <raise@plt> */
/* @0x319464 pop {r1, pc} */

/* ── FUNC 0x319458 · __aeabi_ldiv0 · alias of the symbol above · insn=0 */

/* ── FUNC 0x319468 · __aeabi_f2lz · size=56 · insn=14 */
/* @0x319468 push {r4, lr} */
/* @0x31946c mov r1, #0 */
/* @0x319470 mov r4, r0 */
/* @0x319474 bl 0x31b1d0 <__aeabi_fcmplt> */
/* @0x319478 cmp r0, #0 */
/* @0x31947c beq 0x319494 <__fixsfdi+0x2c> */
/* @0x319480 add r0, r4, #-2147483648 */
/* @0x319484 bl 0x3194e4 <__fixunssfdi> */
/* @0x319488 rsbs r0, r0, #0 */
/* @0x31948c rsc r1, r1, #0 */
/* @0x319490 pop {r4, pc} */
/* @0x319494 mov r0, r4 */
/* @0x319498 pop {r4, lr} */
/* @0x31949c b 0x3194e4 <__fixunssfdi> */

/* ── FUNC 0x319468 · __fixsfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x3194a0 · __aeabi_d2lz · size=68 · insn=17 */
/* @0x3194a0 push {r3, r4, r5, lr} */
/* @0x3194a4 mov r2, #0 */
/* @0x3194a8 mov r3, #0 */
/* @0x3194ac mov r5, r0 */
/* @0x3194b0 mov r4, r1 */
/* @0x3194b4 bl 0x31b080 <__aeabi_dcmplt> */
/* @0x3194b8 cmp r0, #0 */
/* @0x3194bc mov r0, r5 */
/* @0x3194c0 beq 0x3194d8 <__fixdfdi+0x38> */
/* @0x3194c4 add r1, r4, #-2147483648 */
/* @0x3194c8 bl 0x319550 <__fixunsdfdi> */
/* @0x3194cc rsbs r0, r0, #0 */
/* @0x3194d0 rsc r1, r1, #0 */
/* @0x3194d4 pop {r3, r4, r5, pc} */
/* @0x3194d8 mov r1, r4 */
/* @0x3194dc pop {r3, r4, r5, lr} */
/* @0x3194e0 b 0x319550 <__fixunsdfdi> */

/* ── FUNC 0x3194a0 · __fixdfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x3194e4 · __aeabi_f2ulz · size=108 · insn=27 */
/* @0x3194e4 push {r4, r5, r6, lr} */
/* @0x3194e8 bl 0x319110 <__extendsfdf2> */
/* @0x3194ec mov r2, #0 */
/* @0x3194f0 ldr r3, [pc, #0x50] */
/* @0x3194f4 mov r4, r0 */
/* @0x3194f8 mov r5, r1 */
/* @0x3194fc bl 0x31ab34 <__muldf3> */
/* @0x319500 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x319504 mov r6, r0 */
/* @0x319508 bl 0x3190c4 <__floatunsidf> */
/* @0x31950c mov r2, #0 */
/* @0x319510 ldr r3, [pc, #0x34] */
/* @0x319514 bl 0x31ab34 <__muldf3> */
/* @0x319518 mov r2, r0 */
/* @0x31951c mov r3, r1 */
/* @0x319520 mov r0, r4 */
/* @0x319524 mov r1, r5 */
/* @0x319528 bl 0x318e14 <__subdf3> */
/* @0x31952c mov r5, r6 */
/* @0x319530 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x319534 mov r2, #0 */
/* @0x319538 mov r1, r6 */
/* @0x31953c orr r4, r2, r0 */
/* @0x319540 mov r0, r4 */
/* @0x319544 pop {r4, r5, r6, pc} */
/* @0x319548 ldcllo p0, c0, [r0, #0]! */
/* @0x31954c mvnsmi r0, r0 */

/* ── FUNC 0x3194e4 · __fixunssfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x319550 · __aeabi_d2ulz · size=104 · insn=26 */
/* @0x319550 push {r4, r5, r6, lr} */
/* @0x319554 mov r2, #0 */
/* @0x319558 ldr r3, [pc, #0x50] */
/* @0x31955c mov r4, r0 */
/* @0x319560 mov r5, r1 */
/* @0x319564 bl 0x31ab34 <__muldf3> */
/* @0x319568 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x31956c mov r6, r0 */
/* @0x319570 bl 0x3190c4 <__floatunsidf> */
/* @0x319574 mov r2, #0 */
/* @0x319578 ldr r3, [pc, #0x34] */
/* @0x31957c bl 0x31ab34 <__muldf3> */
/* @0x319580 mov r2, r0 */
/* @0x319584 mov r3, r1 */
/* @0x319588 mov r0, r4 */
/* @0x31958c mov r1, r5 */
/* @0x319590 bl 0x318e14 <__subdf3> */
/* @0x319594 mov r5, r6 */
/* @0x319598 bl 0x31b0d0 <__fixunsdfsi> */
/* @0x31959c mov r2, #0 */
/* @0x3195a0 mov r1, r6 */
/* @0x3195a4 orr r4, r2, r0 */
/* @0x3195a8 mov r0, r4 */
/* @0x3195ac pop {r4, r5, r6, pc} */
/* @0x3195b0 ldcllo p0, c0, [r0, #0]! */
/* @0x3195b4 mvnsmi r0, r0 */

/* ── FUNC 0x319550 · __fixunsdfdi · alias of the symbol above · insn=0 */

/* ── FUNC 0x3195b8 · __gnu_ldivmod_helper · size=60 · insn=15 */
/* @0x3195b8 push {r3, r4, r5, r6, r7, lr} */
/* @0x3195bc mov r6, r2 */
/* @0x3195c0 mov r4, r0 */
/* @0x3195c4 mov r5, r1 */
/* @0x3195c8 mov r7, r3 */
/* @0x3195cc bl 0x31b220 <__divdi3> */
/* @0x3195d0 ldr r12, [sp, #0x18] */
/* @0x3195d4 mul r3, r6, r1 */
/* @0x3195d8 mla r7, r0, r7, r3 */
/* @0x3195dc umull r2, r3, r6, r0 */
/* @0x3195e0 add r3, r7, r3 */
/* @0x3195e4 subs r2, r4, r2 */
/* @0x3195e8 sbc r3, r5, r3 */
/* @0x3195ec strd r2, r3, [r12] */
/* @0x3195f0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x3195f4 · __gnu_uldivmod_helper · size=60 · insn=15 */
/* @0x3195f4 push {r3, r4, r5, r6, r7, lr} */
/* @0x3195f8 mov r6, r2 */
/* @0x3195fc mov r4, r0 */
/* @0x319600 mov r5, r1 */
/* @0x319604 mov r7, r3 */
/* @0x319608 bl 0x31b698 <__udivdi3> */
/* @0x31960c ldr r12, [sp, #0x18] */
/* @0x319610 mul r7, r0, r7 */
/* @0x319614 umull r2, r3, r0, r6 */
/* @0x319618 mla r7, r6, r1, r7 */
/* @0x31961c add r3, r7, r3 */
/* @0x319620 subs r2, r4, r2 */
/* @0x319624 sbc r3, r5, r3 */
/* @0x319628 strd r2, r3, [r12] */
/* @0x31962c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x319630 · anon_319630 · size=1072 · insn=269 */
/* @0x319630 ldr r3, [r0] */
/* @0x319634 tst r3, #1073741824 */
/* @0x319638 orrne r3, r3, #-2147483648 */
/* @0x31963c biceq r3, r3, #-2147483648 */
/* @0x319640 add r0, r0, r3 */
/* @0x319644 bx lr */
/* @0x319648 push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x31964c cmp r1, #0 */
/* @0x319650 mov r9, r0 */
/* @0x319654 mov r6, r2 */
/* @0x319658 beq 0x3196d0 <__gnu_uldivmod_helper+0xdc> */
/* @0x31965c sub r8, r1, #1 */
/* @0x319660 mov r7, #0 */
/* @0x319664 mov r10, r8 */
/* @0x319668 add r4, r7, r10 */
/* @0x31966c add r4, r4, r4, lsr #31 */
/* @0x319670 asr r4, r4, #1 */
/* @0x319674 lsl r3, r4, #3 */
/* @0x319678 str r3, [sp, #0x4] */
/* @0x31967c add r5, r9, r3 */
/* @0x319680 mov r0, r5 */
/* @0x319684 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x319688 cmp r4, r8 */
/* @0x31968c ldr r3, [sp, #0x4] */
/* @0x319690 mov r11, r0 */
/* @0x319694 beq 0x3196e0 <__gnu_uldivmod_helper+0xec> */
/* @0x319698 add r0, r3, #8 */
/* @0x31969c add r0, r9, r0 */
/* @0x3196a0 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x3196a4 cmp r6, r11 */
/* @0x3196a8 bhs 0x3196bc <__gnu_uldivmod_helper+0xc8> */
/* @0x3196ac cmp r4, r7 */
/* @0x3196b0 beq 0x3196d8 <__gnu_uldivmod_helper+0xe4> */
/* @0x3196b4 sub r10, r4, #1 */
/* @0x3196b8 b 0x319668 <__gnu_uldivmod_helper+0x74> */
/* @0x3196bc sub r0, r0, #1 */
/* @0x3196c0 cmp r6, r0 */
/* @0x3196c4 bls 0x3196e8 <__gnu_uldivmod_helper+0xf4> */
/* @0x3196c8 add r7, r4, #1 */
/* @0x3196cc b 0x319668 <__gnu_uldivmod_helper+0x74> */
/* @0x3196d0 mov r5, r1 */
/* @0x3196d4 b 0x3196e8 <__gnu_uldivmod_helper+0xf4> */
/* @0x3196d8 mov r5, #0 */
/* @0x3196dc b 0x3196e8 <__gnu_uldivmod_helper+0xf4> */
/* @0x3196e0 cmp r6, r0 */
/* @0x3196e4 blo 0x3196ac <__gnu_uldivmod_helper+0xb8> */
/* @0x3196e8 mov r0, r5 */
/* @0x3196ec add sp, sp, #12 */
/* @0x3196f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x3196f4 cmp r0, #1 */
/* @0x3196f8 beq 0x319718 <__gnu_uldivmod_helper+0x124> */
/* @0x3196fc cmp r0, #2 */
/* @0x319700 beq 0x319724 <__gnu_uldivmod_helper+0x130> */
/* @0x319704 cmp r0, #0 */
/* @0x319708 bne 0x319730 <__gnu_uldivmod_helper+0x13c> */
/* @0x31970c ldr r0, [pc, #0x24] */
/* @0x319710 ldr r0, [pc, r0] */
/* @0x319714 bx lr */
/* @0x319718 ldr r0, [pc, #0x1c] */
/* @0x31971c ldr r0, [pc, r0] */
/* @0x319720 bx lr */
/* @0x319724 ldr r0, [pc, #0x14] */
/* @0x319728 ldr r0, [pc, r0] */
/* @0x31972c bx lr */
/* @0x319730 mov r0, #0 */
/* @0x319734 bx lr */
/* @0x319738 andeq r8, sp, r4, lsr #10 */
/* @0x31973c andeq r8, sp, r12, lsl r5 */
/* @0x319740 andeq r8, sp, r4, lsl r5 */
/* @0x319744 ldr r3, [pc, #0xf8] */
/* @0x319748 push {r0, r1, r2, r4, r5, lr} */
/* @0x31974c ldr r3, [pc, r3] */
/* @0x319750 cmp r3, #0 */
/* @0x319754 mov r4, r0 */
/* @0x319758 sub r5, r1, #2 */
/* @0x31975c beq 0x319780 <__gnu_uldivmod_helper+0x18c> */
/* @0x319760 mov r0, r5 */
/* @0x319764 add r1, sp, #4 */
/* @0x319768 bl 0xb6fc4 <raise@plt+0xc> */
/* @0x31976c mov r12, r0 */
/* @0x319770 cmp r0, #0 */
/* @0x319774 streq r12, [r4, #0x10] */
/* @0x319778 bne 0x3197a0 <__gnu_uldivmod_helper+0x1ac> */
/* @0x31977c b 0x3197b8 <__gnu_uldivmod_helper+0x1c4> */
/* @0x319780 ldr r12, [pc, #0xc0] */
/* @0x319784 ldr r3, [pc, #0xc0] */
/* @0x319788 ldr r12, [pc, r12] */
/* @0x31978c ldr r3, [pc, r3] */
/* @0x319790 rsb r12, r3, r12 */
/* @0x319794 mov r0, r3 */
/* @0x319798 asr r12, r12, #3 */
/* @0x31979c str r12, [sp, #0x4] */
/* @0x3197a0 mov r2, r5 */
/* @0x3197a4 ldr r1, [sp, #0x4] */
/* @0x3197a8 bl 0x319648 <__gnu_uldivmod_helper+0x54> */
/* @0x3197ac subs r5, r0, #0 */
/* @0x3197b0 bne 0x3197c0 <__gnu_uldivmod_helper+0x1cc> */
/* @0x3197b4 str r5, [r4, #0x10] */
/* @0x3197b8 mov r0, #9 */
/* @0x3197bc b 0x31983c <__gnu_uldivmod_helper+0x248> */
/* @0x3197c0 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x3197c4 ldr r3, [r5, #0x4] */
/* @0x3197c8 cmp r3, #1 */
/* @0x3197cc str r0, [r4, #0x48] */
/* @0x3197d0 moveq r3, #0 */
/* @0x3197d4 moveq r0, #5 */
/* @0x3197d8 streq r3, [r4, #0x10] */
/* @0x3197dc beq 0x31983c <__gnu_uldivmod_helper+0x248> */
/* @0x3197e0 cmp r3, #0 */
/* @0x3197e4 add r0, r5, #4 */
/* @0x3197e8 strlt r0, [r4, #0x4c] */
/* @0x3197ec movlt r3, #1 */
/* @0x3197f0 blt 0x319800 <__gnu_uldivmod_helper+0x20c> */
/* @0x3197f4 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x3197f8 mov r3, #0 */
/* @0x3197fc str r0, [r4, #0x4c] */
/* @0x319800 ldr r0, [r4, #0x4c] */
/* @0x319804 str r3, [r4, #0x50] */
/* @0x319808 ldr r3, [r0] */
/* @0x31980c cmp r3, #0 */
/* @0x319810 bge 0x319830 <__gnu_uldivmod_helper+0x23c> */
/* @0x319814 ubfx r0, r3, #0x18, #0x4 */
/* @0x319818 bl 0x3196f4 <__gnu_uldivmod_helper+0x100> */
/* @0x31981c cmp r0, #0 */
/* @0x319820 str r0, [r4, #0x10] */
/* @0x319824 moveq r0, #9 */
/* @0x319828 movne r0, #0 */
/* @0x31982c b 0x31983c <__gnu_uldivmod_helper+0x248> */
/* @0x319830 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x319834 str r0, [r4, #0x10] */
/* @0x319838 mov r0, #0 */
/* @0x31983c add sp, sp, #12 */
/* @0x319840 pop {r4, r5, pc} */
/* @0x319844 strdeq r8, r9, [sp], -r4 */
/* @0x319848 strheq r8, [sp], -r12 */
/* @0x31984c strheq r8, [sp], -r12 */
/* @0x319850 ldr r3, [r0] */
/* @0x319854 push {r4, lr} */
/* @0x319858 tst r3, #1 */
/* @0x31985c mov r4, r0 */
/* @0x319860 bne 0x31987c <__gnu_uldivmod_helper+0x288> */
/* @0x319864 tst r3, #2 */
/* @0x319868 add r0, r0, #72 */
/* @0x31986c beq 0x319878 <__gnu_uldivmod_helper+0x284> */
/* @0x319870 bl 0x31a52c <__gnu_Unwind_Restore_VFP_D> */
/* @0x319874 b 0x31987c <__gnu_uldivmod_helper+0x288> */
/* @0x319878 bl 0x31a51c <__gnu_Unwind_Restore_VFP> */
/* @0x31987c ldr r3, [r4] */
/* @0x319880 tst r3, #4 */
/* @0x319884 bne 0x319890 <__gnu_uldivmod_helper+0x29c> */
/* @0x319888 add r0, r4, #208 */
/* @0x31988c bl 0x31a53c <__gnu_Unwind_Restore_VFP_D_16_to_31> */
/* @0x319890 ldr r3, [r4] */
/* @0x319894 tst r3, #8 */
/* @0x319898 bne 0x3198a4 <__gnu_uldivmod_helper+0x2b0> */
/* @0x31989c add r0, r4, #336 */
/* @0x3198a0 bl 0x31a54c <__gnu_Unwind_Restore_WMMXD> */
/* @0x3198a4 ldr r3, [r4] */
/* @0x3198a8 tst r3, #16 */
/* @0x3198ac popne {r4, pc} */
/* @0x3198b0 add r0, r4, #464 */
/* @0x3198b4 pop {r4, lr} */
/* @0x3198b8 b 0x31a5d4 <__gnu_Unwind_Restore_WMMXC> */
/* @0x3198bc ldr r3, [r0] */
/* @0x3198c0 cmp r3, #0 */
/* @0x3198c4 ldrne r0, [r3, r0] */
/* @0x3198c8 moveq r0, r3 */
/* @0x3198cc bx lr */
/* @0x3198d0 mov r0, #9 */
/* @0x3198d4 bx lr */
/* @0x3198d8 bx lr */
/* @0x3198dc push {r4, r5, r6, lr} */
/* @0x3198e0 mov r5, r0 */
/* @0x3198e4 mov r4, r1 */
/* @0x3198e8 mov r0, r5 */
/* @0x3198ec ldr r1, [r4, #0x40] */
/* @0x3198f0 bl 0x319744 <__gnu_uldivmod_helper+0x150> */
/* @0x3198f4 subs r6, r0, #0 */
/* @0x3198f8 beq 0x319900 <__gnu_uldivmod_helper+0x30c> */
/* @0x3198fc bl 0xb6c88 <abort@plt> */
/* @0x319900 ldr r3, [r4, #0x40] */
/* @0x319904 mov r0, #1 */
/* @0x319908 mov r1, r5 */
/* @0x31990c mov r2, r4 */
/* @0x319910 str r3, [r5, #0x14] */
/* @0x319914 ldr r3, [r5, #0x10] */
/* @0x319918 blx r3 */
/* @0x31991c cmp r0, #8 */
/* @0x319920 beq 0x3198e8 <__gnu_uldivmod_helper+0x2f4> */
/* @0x319924 cmp r0, #7 */
/* @0x319928 bne 0x3198fc <__gnu_uldivmod_helper+0x308> */
/* @0x31992c mov r0, r6 */
/* @0x319930 ldr r1, [r4, #0x40] */
/* @0x319934 bl 0x3198d8 <__gnu_uldivmod_helper+0x2e4> */
/* @0x319938 add r0, r4, #4 */
/* @0x31993c bl 0x31a508 <restore_core_regs> */
/* @0x319940 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x319944 add lr, r1, #4 */
/* @0x319948 ldr r8, [r0, #0xc] */
/* @0x31994c mov r4, r0 */
/* @0x319950 ldr r9, [r0, #0x18] */
/* @0x319954 mov r5, r2 */
/* @0x319958 ldm lr!, {r0, r1, r2, r3} */
/* @0x31995c sub sp, sp, #972 */
/* @0x319960 add r12, sp, #12 */
/* @0x319964 add r10, sp, #8 */
/* @0x319968 add r11, sp, #488 */
/* @0x31996c mov r7, #0 */
/* @0x319970 stm r12!, {r0, r1, r2, r3} */
/* @0x319974 ldm lr!, {r0, r1, r2, r3} */
/* @0x319978 stm r12!, {r0, r1, r2, r3} */
/* @0x31997c ldm lr!, {r0, r1, r2, r3} */
/* @0x319980 stm r12!, {r0, r1, r2, r3} */
/* @0x319984 ldm lr, {r0, r1, r2, r3} */
/* @0x319988 stm r12, {r0, r1, r2, r3} */
/* @0x31998c str r7, [sp, #0x8] */
/* @0x319990 mov r0, r4 */
/* @0x319994 ldr r1, [sp, #0x48] */
/* @0x319998 bl 0x319744 <__gnu_uldivmod_helper+0x150> */
/* @0x31999c cmp r5, #0 */
/* @0x3199a0 movne r6, #10 */
/* @0x3199a4 moveq r6, #9 */
/* @0x3199a8 subs r5, r0, #0 */
/* @0x3199ac orrne r6, r6, #16 */
/* @0x3199b0 ldrne r3, [sp, #0x40] */
/* @0x3199b4 bne 0x3199ec <__gnu_uldivmod_helper+0x3f8> */
/* @0x3199b8 ldr r3, [sp, #0x48] */
/* @0x3199bc mov r1, r10 */
/* @0x3199c0 mov r2, #480 */
/* @0x3199c4 mov r0, r11 */
/* @0x3199c8 str r3, [r4, #0x14] */
/* @0x3199cc bl 0xb65bc <memcpy@plt> */
/* @0x3199d0 ldr r3, [r4, #0x10] */
/* @0x3199d4 mov r0, r6 */
/* @0x3199d8 mov r1, r4 */
/* @0x3199dc mov r2, r11 */
/* @0x3199e0 blx r3 */
/* @0x3199e4 ldr r3, [sp, #0x220] */
/* @0x3199e8 mov r7, r0 */
/* @0x3199ec str r3, [sp, #0x4c] */
/* @0x3199f0 mov r0, #1 */
/* @0x3199f4 str r10, [sp] */
/* @0x3199f8 mov r1, r6 */
/* @0x3199fc str r9, [sp, #0x4] */
/* @0x319a00 mov r2, r4 */
/* @0x319a04 mov r3, r4 */
/* @0x319a08 blx r8 */
/* @0x319a0c cmp r0, #0 */
/* @0x319a10 bne 0x319a50 <__gnu_uldivmod_helper+0x45c> */
/* @0x319a14 cmp r5, #0 */
/* @0x319a18 bne 0x319a58 <__gnu_uldivmod_helper+0x464> */
/* @0x319a1c mov r0, r10 */
/* @0x319a20 mov r1, r11 */
/* @0x319a24 mov r2, #480 */
/* @0x319a28 bl 0xb65bc <memcpy@plt> */
/* @0x319a2c cmp r7, #8 */
/* @0x319a30 beq 0x319990 <__gnu_uldivmod_helper+0x39c> */
/* @0x319a34 cmp r7, #7 */
/* @0x319a38 bne 0x319a50 <__gnu_uldivmod_helper+0x45c> */
/* @0x319a3c mov r0, r5 */
/* @0x319a40 ldr r1, [sp, #0x48] */
/* @0x319a44 bl 0x3198d8 <__gnu_uldivmod_helper+0x2e4> */
/* @0x319a48 add r0, sp, #12 */
/* @0x319a4c bl 0x31a508 <restore_core_regs> */
/* @0x319a50 mov r0, #9 */
/* @0x319a54 b 0x319a5c <__gnu_uldivmod_helper+0x468> */
/* @0x319a58 mov r0, r5 */
/* @0x319a5c add sp, sp, #972 */
/* @0x319a60 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x319a64 · _Unwind_GetCFA · size=8 · insn=2 */
/* @0x319a64 ldr r0, [r0, #0x44] */
/* @0x319a68 bx lr */

/* ── FUNC 0x319a6c · __gnu_Unwind_RaiseException · size=164 · insn=41 */
/* @0x319a6c ldr r3, [r1, #0x3c] */
/* @0x319a70 push {r4, r5, r6, r7, lr} */
/* @0x319a74 add lr, r1, #4 */
/* @0x319a78 str r3, [r1, #0x40] */
/* @0x319a7c mov r5, r0 */
/* @0x319a80 mov r4, r1 */
/* @0x319a84 sub sp, sp, #484 */
/* @0x319a88 ldm lr!, {r0, r1, r2, r3} */
/* @0x319a8c add r12, sp, #4 */
/* @0x319a90 add r6, sp, #480 */
/* @0x319a94 stm r12!, {r0, r1, r2, r3} */
/* @0x319a98 ldm lr!, {r0, r1, r2, r3} */
/* @0x319a9c stm r12!, {r0, r1, r2, r3} */
/* @0x319aa0 ldm lr!, {r0, r1, r2, r3} */
/* @0x319aa4 stm r12!, {r0, r1, r2, r3} */
/* @0x319aa8 ldm lr, {r0, r1, r2, r3} */
/* @0x319aac stm r12, {r0, r1, r2, r3} */
/* @0x319ab0 mvn r3, #0 */
/* @0x319ab4 str r3, [r6, #-0x1e0]! */
/* @0x319ab8 mov r0, r5 */
/* @0x319abc ldr r1, [sp, #0x40] */
/* @0x319ac0 bl 0x319744 <__gnu_uldivmod_helper+0x150> */
/* @0x319ac4 cmp r0, #0 */
/* @0x319ac8 bne 0x319b04 <__gnu_Unwind_RaiseException+0x98> */
/* @0x319acc ldr r3, [r5, #0x10] */
/* @0x319ad0 mov r1, r5 */
/* @0x319ad4 mov r2, sp */
/* @0x319ad8 blx r3 */
/* @0x319adc cmp r0, #8 */
/* @0x319ae0 mov r7, r0 */
/* @0x319ae4 beq 0x319ab8 <__gnu_Unwind_RaiseException+0x4c> */
/* @0x319ae8 mov r0, sp */
/* @0x319aec bl 0x319850 <__gnu_uldivmod_helper+0x25c> */
/* @0x319af0 cmp r7, #6 */
/* @0x319af4 bne 0x319b04 <__gnu_Unwind_RaiseException+0x98> */
/* @0x319af8 mov r0, r5 */
/* @0x319afc mov r1, r4 */
/* @0x319b00 bl 0x3198dc <__gnu_uldivmod_helper+0x2e8> */
/* @0x319b04 mov r0, #9 */
/* @0x319b08 add sp, sp, #484 */
/* @0x319b0c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x319b10 · __gnu_Unwind_ForcedUnwind · size=28 · insn=7 */
/* @0x319b10 str r2, [r0, #0x18] */
/* @0x319b14 ldr r2, [r3, #0x3c] */
/* @0x319b18 str r1, [r0, #0xc] */
/* @0x319b1c mov r1, r3 */
/* @0x319b20 str r2, [r3, #0x40] */
/* @0x319b24 mov r2, #0 */
/* @0x319b28 b 0x319940 <__gnu_uldivmod_helper+0x34c> */

/* ── FUNC 0x319b2c · __gnu_Unwind_Resume · size=116 · insn=29 */
/* @0x319b2c push {r4, r5, r6, lr} */
/* @0x319b30 mov r5, r0 */
/* @0x319b34 ldr r6, [r0, #0xc] */
/* @0x319b38 mov r4, r1 */
/* @0x319b3c ldr r3, [r0, #0x14] */
/* @0x319b40 cmp r6, #0 */
/* @0x319b44 str r3, [r1, #0x40] */
/* @0x319b48 beq 0x319b58 <__gnu_Unwind_Resume+0x2c> */
/* @0x319b4c mov r2, #1 */
/* @0x319b50 bl 0x319940 <__gnu_uldivmod_helper+0x34c> */
/* @0x319b54 b 0x319b9c <__gnu_Unwind_Resume+0x70> */
/* @0x319b58 ldr r3, [r0, #0x10] */
/* @0x319b5c mov r1, r5 */
/* @0x319b60 mov r0, #2 */
/* @0x319b64 mov r2, r4 */
/* @0x319b68 blx r3 */
/* @0x319b6c cmp r0, #7 */
/* @0x319b70 beq 0x319b88 <__gnu_Unwind_Resume+0x5c> */
/* @0x319b74 cmp r0, #8 */
/* @0x319b78 bne 0x319b9c <__gnu_Unwind_Resume+0x70> */
/* @0x319b7c mov r0, r5 */
/* @0x319b80 mov r1, r4 */
/* @0x319b84 bl 0x3198dc <__gnu_uldivmod_helper+0x2e8> */
/* @0x319b88 mov r0, r6 */
/* @0x319b8c ldr r1, [r4, #0x40] */
/* @0x319b90 bl 0x3198d8 <__gnu_uldivmod_helper+0x2e4> */
/* @0x319b94 add r0, r4, #4 */
/* @0x319b98 bl 0x31a508 <restore_core_regs> */
/* @0x319b9c bl 0xb6c88 <abort@plt> */

/* ── FUNC 0x319ba0 · __gnu_Unwind_Resume_or_Rethrow · size=32 · insn=8 */
/* @0x319ba0 ldr r2, [r0, #0xc] */
/* @0x319ba4 cmp r2, #0 */
/* @0x319ba8 bne 0x319bb0 <__gnu_Unwind_Resume_or_Rethrow+0x10> */
/* @0x319bac b 0x319a6c <__gnu_Unwind_RaiseException> */
/* @0x319bb0 ldr r2, [r1, #0x3c] */
/* @0x319bb4 str r2, [r1, #0x40] */
/* @0x319bb8 mov r2, #0 */
/* @0x319bbc b 0x319940 <__gnu_uldivmod_helper+0x34c> */

/* ── FUNC 0x319bc0 · _Unwind_Complete · size=4 · insn=1 */
/* @0x319bc0 bx lr */

/* ── FUNC 0x319bc4 · _Unwind_DeleteException · size=32 · insn=8 */
/* @0x319bc4 push {r3, lr} */
/* @0x319bc8 mov r1, r0 */
/* @0x319bcc ldr r3, [r0, #0x8] */
/* @0x319bd0 cmp r3, #0 */
/* @0x319bd4 popeq {r3, pc} */
/* @0x319bd8 mov r0, #1 */
/* @0x319bdc blx r3 */
/* @0x319be0 pop {r3, pc} */

/* ── FUNC 0x319be4 · _Unwind_VRS_Get · size=92 · insn=23 */
/* @0x319be4 cmp r1, #4 */
/* @0x319be8 addls pc, pc, r1, lsl #2 */
/* @0x319bec b 0x319c38 <_Unwind_VRS_Get+0x54> */
/* @0x319bf0 b 0x319c0c <_Unwind_VRS_Get+0x28> */
/* @0x319bf4 b 0x319c04 <_Unwind_VRS_Get+0x20> */
/* @0x319bf8 b 0x319c38 <_Unwind_VRS_Get+0x54> */
/* @0x319bfc b 0x319c04 <_Unwind_VRS_Get+0x20> */
/* @0x319c00 b 0x319c04 <_Unwind_VRS_Get+0x20> */
/* @0x319c04 mov r0, #1 */
/* @0x319c08 bx lr */
/* @0x319c0c cmp r2, #15 */
/* @0x319c10 cmpls r3, #0 */
/* @0x319c14 moveq r3, #0 */
/* @0x319c18 movne r3, #1 */
/* @0x319c1c bne 0x319c38 <_Unwind_VRS_Get+0x54> */
/* @0x319c20 add r2, r0, r2, lsl #2 */
/* @0x319c24 mov r0, r3 */
/* @0x319c28 ldr r1, [r2, #0x4] */
/* @0x319c2c ldr r2, [sp] */
/* @0x319c30 str r1, [r2] */
/* @0x319c34 bx lr */
/* @0x319c38 mov r0, #2 */
/* @0x319c3c bx lr */

/* ── FUNC 0x319c40 · anon_319c40 · size=36 · insn=10 */
/* @0x319c40 push {r0, r1, r2, r3, r4, lr} */
/* @0x319c44 mov r2, r1 */
/* @0x319c48 mov r1, #0 */
/* @0x319c4c add r3, sp, #12 */
/* @0x319c50 str r3, [sp] */
/* @0x319c54 mov r3, r1 */
/* @0x319c58 bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x319c5c ldr r0, [sp, #0xc] */
/* @0x319c60 add sp, sp, #20 */
/* @0x319c64 ldr pc, [sp], #4 */

/* ── FUNC 0x319c68 · _Unwind_VRS_Set · size=92 · insn=23 */
/* @0x319c68 cmp r1, #4 */
/* @0x319c6c addls pc, pc, r1, lsl #2 */
/* @0x319c70 b 0x319cbc <_Unwind_VRS_Set+0x54> */
/* @0x319c74 b 0x319c90 <_Unwind_VRS_Set+0x28> */
/* @0x319c78 b 0x319c88 <_Unwind_VRS_Set+0x20> */
/* @0x319c7c b 0x319cbc <_Unwind_VRS_Set+0x54> */
/* @0x319c80 b 0x319c88 <_Unwind_VRS_Set+0x20> */
/* @0x319c84 b 0x319c88 <_Unwind_VRS_Set+0x20> */
/* @0x319c88 mov r0, #1 */
/* @0x319c8c bx lr */
/* @0x319c90 cmp r2, #15 */
/* @0x319c94 cmpls r3, #0 */
/* @0x319c98 moveq r3, #0 */
/* @0x319c9c movne r3, #1 */
/* @0x319ca0 bne 0x319cbc <_Unwind_VRS_Set+0x54> */
/* @0x319ca4 ldr r1, [sp] */
/* @0x319ca8 add r2, r0, r2, lsl #2 */
/* @0x319cac mov r0, r3 */
/* @0x319cb0 ldr r1, [r1] */
/* @0x319cb4 str r1, [r2, #0x4] */
/* @0x319cb8 bx lr */
/* @0x319cbc mov r0, #2 */
/* @0x319cc0 bx lr */
