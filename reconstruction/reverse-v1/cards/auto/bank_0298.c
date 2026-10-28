/* libyoyo.so 覆盖卡组 0298
 * 函数 0x319468..0x31a5fc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

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

/* ── FUNC 0x319630 · anon_319630 · size=1076 · insn=269 */
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

/* ── FUNC 0x319c40 · anon_319c40 · size=40 · insn=10 */
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

/* ── FUNC 0x319cc4 · anon_319cc4 · size=44 · insn=11 */
/* @0x319cc4 push {r0, r1, r2, r3, r4, lr} */
/* @0x319cc8 add r3, sp, #16 */
/* @0x319ccc mov r12, r1 */
/* @0x319cd0 mov r1, #0 */
/* @0x319cd4 str r2, [r3, #-0x4]! */
/* @0x319cd8 mov r2, r12 */
/* @0x319cdc str r3, [sp] */
/* @0x319ce0 mov r3, r1 */
/* @0x319ce4 bl 0x319c68 <_Unwind_VRS_Set> */
/* @0x319ce8 add sp, sp, #20 */
/* @0x319cec ldr pc, [sp], #4 */

/* ── FUNC 0x319cf0 · __gnu_Unwind_Backtrace · size=196 · insn=49 */
/* @0x319cf0 ldr r3, [r2, #0x3c] */
/* @0x319cf4 push {r4, r5, r6, r7, r8, lr} */
/* @0x319cf8 add lr, r2, #4 */
/* @0x319cfc str r3, [r2, #0x40] */
/* @0x319d00 mov r7, r0 */
/* @0x319d04 mov r8, r1 */
/* @0x319d08 sub sp, sp, #568 */
/* @0x319d0c ldm lr!, {r0, r1, r2, r3} */
/* @0x319d10 add r12, sp, #92 */
/* @0x319d14 add r4, sp, #88 */
/* @0x319d18 stm r12!, {r0, r1, r2, r3} */
/* @0x319d1c ldm lr!, {r0, r1, r2, r3} */
/* @0x319d20 stm r12!, {r0, r1, r2, r3} */
/* @0x319d24 ldm lr!, {r0, r1, r2, r3} */
/* @0x319d28 stm r12!, {r0, r1, r2, r3} */
/* @0x319d2c ldm lr, {r0, r1, r2, r3} */
/* @0x319d30 stm r12, {r0, r1, r2, r3} */
/* @0x319d34 mvn r3, #0 */
/* @0x319d38 str r3, [sp, #0x58] */
/* @0x319d3c mov r0, sp */
/* @0x319d40 ldr r1, [sp, #0x98] */
/* @0x319d44 bl 0x319744 <__gnu_uldivmod_helper+0x150> */
/* @0x319d48 cmp r0, #0 */
/* @0x319d4c beq 0x319d58 <__gnu_Unwind_Backtrace+0x68> */
/* @0x319d50 mov r5, #9 */
/* @0x319d54 b 0x319da0 <__gnu_Unwind_Backtrace+0xb0> */
/* @0x319d58 mov r0, r4 */
/* @0x319d5c mov r1, #12 */
/* @0x319d60 mov r2, sp */
/* @0x319d64 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x319d68 mov r0, r4 */
/* @0x319d6c mov r1, r8 */
/* @0x319d70 blx r7 */
/* @0x319d74 cmp r0, #0 */
/* @0x319d78 bne 0x319d50 <__gnu_Unwind_Backtrace+0x60> */
/* @0x319d7c mov r0, #8 */
/* @0x319d80 mov r1, sp */
/* @0x319d84 mov r2, r4 */
/* @0x319d88 ldr r3, [sp, #0x10] */
/* @0x319d8c blx r3 */
/* @0x319d90 cmp r0, #9 */
/* @0x319d94 cmpne r0, #5 */
/* @0x319d98 mov r5, r0 */
/* @0x319d9c bne 0x319d3c <__gnu_Unwind_Backtrace+0x4c> */
/* @0x319da0 mov r0, r4 */
/* @0x319da4 bl 0x319850 <__gnu_uldivmod_helper+0x25c> */
/* @0x319da8 mov r0, r5 */
/* @0x319dac add sp, sp, #568 */
/* @0x319db0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x319db4 · anon_319db4 · size=1008 · insn=252 */
/* @0x319db4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x319db8 mov r6, r2 */
/* @0x319dbc ldr r2, [r1, #0x4c] */
/* @0x319dc0 sub sp, sp, #36 */
/* @0x319dc4 subs r9, r3, #0 */
/* @0x319dc8 mov r4, r1 */
/* @0x319dcc add r5, r2, #4 */
/* @0x319dd0 and r7, r0, #3 */
/* @0x319dd4 ldr r2, [r2] */
/* @0x319dd8 str r5, [sp, #0x18] */
/* @0x319ddc str r2, [sp, #0x14] */
/* @0x319de0 bne 0x319dfc <__gnu_Unwind_Backtrace+0x10c> */
/* @0x319de4 lsl r2, r2, #8 */
/* @0x319de8 mov r3, #3 */
/* @0x319dec str r2, [sp, #0x14] */
/* @0x319df0 strb r9, [sp, #0x1d] */
/* @0x319df4 strb r3, [sp, #0x1c] */
/* @0x319df8 b 0x319e24 <__gnu_Unwind_Backtrace+0x134> */
/* @0x319dfc cmp r9, #2 */
/* @0x319e00 bgt 0x319e24 <__gnu_Unwind_Backtrace+0x134> */
/* @0x319e04 lsr r3, r2, #16 */
/* @0x319e08 strb r3, [sp, #0x1d] */
/* @0x319e0c lsl r2, r2, #16 */
/* @0x319e10 str r2, [sp, #0x14] */
/* @0x319e14 uxtb r3, r3 */
/* @0x319e18 mov r2, #2 */
/* @0x319e1c strb r2, [sp, #0x1c] */
/* @0x319e20 add r5, r5, r3, lsl #2 */
/* @0x319e24 cmp r7, #2 */
/* @0x319e28 ldr r10, [r4, #0x50] */
/* @0x319e2c ldreq r5, [r4, #0x38] */
/* @0x319e30 ands r10, r10, #1 */
/* @0x319e34 bne 0x31a130 <__gnu_Unwind_Backtrace+0x440> */
/* @0x319e38 eor r0, r0, #8 */
/* @0x319e3c ubfx r0, r0, #0x3, #0x1 */
/* @0x319e40 str r0, [sp, #0xc] */
/* @0x319e44 ldr r8, [r5] */
/* @0x319e48 cmp r8, #0 */
/* @0x319e4c beq 0x31a134 <__gnu_Unwind_Backtrace+0x444> */
/* @0x319e50 cmp r9, #2 */
/* @0x319e54 ldr r2, [r4, #0x48] */
/* @0x319e58 mov r0, r6 */
/* @0x319e5c mov r1, #15 */
/* @0x319e60 ldreq r11, [r5, #0x4] */
/* @0x319e64 addeq r5, r5, #8 */
/* @0x319e68 ldrhne r11, [r5, #2] */
/* @0x319e6c ldrhne r8, [r5] */
/* @0x319e70 addne r5, r5, #4 */
/* @0x319e74 bic r3, r11, #1 */
/* @0x319e78 add r3, r3, r2 */
/* @0x319e7c str r3, [sp, #0x4] */
/* @0x319e80 bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x319e84 ldr r3, [sp, #0x4] */
/* @0x319e88 cmp r3, r0 */
/* @0x319e8c movhi r0, #0 */
/* @0x319e90 bhi 0x319ea8 <__gnu_Unwind_Backtrace+0x1b8> */
/* @0x319e94 bic r2, r8, #1 */
/* @0x319e98 add r3, r3, r2 */
/* @0x319e9c cmp r0, r3 */
/* @0x319ea0 movhs r0, #0 */
/* @0x319ea4 movlo r0, #1 */
/* @0x319ea8 and r11, r11, #1 */
/* @0x319eac and r8, r8, #1 */
/* @0x319eb0 orr r8, r8, r11, lsl #1 */
/* @0x319eb4 cmp r8, #1 */
/* @0x319eb8 beq 0x319f1c <__gnu_Unwind_Backtrace+0x22c> */
/* @0x319ebc blo 0x319ecc <__gnu_Unwind_Backtrace+0x1dc> */
/* @0x319ec0 cmp r8, #2 */
/* @0x319ec4 beq 0x319ffc <__gnu_Unwind_Backtrace+0x30c> */
/* @0x319ec8 b 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x319ecc cmp r7, #0 */
/* @0x319ed0 moveq r0, #0 */
/* @0x319ed4 andne r0, r0, #1 */
/* @0x319ed8 add r8, r5, #4 */
/* @0x319edc cmp r0, #0 */
/* @0x319ee0 beq 0x319f14 <__gnu_Unwind_Backtrace+0x224> */
/* @0x319ee4 mov r0, r5 */
/* @0x319ee8 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x319eec str r8, [r4, #0x38] */
/* @0x319ef0 mov r5, r0 */
/* @0x319ef4 mov r0, r4 */
/* @0x319ef8 blx 0x318628 <__cxa_begin_cleanup> */
/* @0x319efc cmp r0, #0 */
/* @0x319f00 beq 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x319f04 mov r0, r6 */
/* @0x319f08 mov r1, #15 */
/* @0x319f0c mov r2, r5 */
/* @0x319f10 b 0x319fe8 <__gnu_Unwind_Backtrace+0x2f8> */
/* @0x319f14 mov r5, r8 */
/* @0x319f18 b 0x319e44 <__gnu_Unwind_Backtrace+0x154> */
/* @0x319f1c cmp r7, #0 */
/* @0x319f20 bne 0x319fa0 <__gnu_Unwind_Backtrace+0x2b0> */
/* @0x319f24 cmp r0, #0 */
/* @0x319f28 beq 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319f2c ldr r3, [r5, #0x4] */
/* @0x319f30 ldr r11, [r5] */
/* @0x319f34 cmn r3, #2 */
/* @0x319f38 lsr r11, r11, #31 */
/* @0x319f3c beq 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x319f40 cmn r3, #1 */
/* @0x319f44 add r2, r4, #88 */
/* @0x319f48 str r2, [sp, #0x10] */
/* @0x319f4c beq 0x319f74 <__gnu_Unwind_Backtrace+0x284> */
/* @0x319f50 add r0, r5, #4 */
/* @0x319f54 bl 0x3198bc <__gnu_uldivmod_helper+0x2c8> */
/* @0x319f58 mov r2, r11 */
/* @0x319f5c add r3, sp, #16 */
/* @0x319f60 mov r1, r0 */
/* @0x319f64 mov r0, r4 */
/* @0x319f68 blx 0x3185b4 <__cxa_type_match> */
/* @0x319f6c subs r8, r0, #0 */
/* @0x319f70 beq 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319f74 mov r0, r6 */
/* @0x319f78 mov r1, #13 */
/* @0x319f7c bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x319f80 cmp r8, #2 */
/* @0x319f84 ldr r2, [sp, #0x10] */
/* @0x319f88 moveq r3, r4 */
/* @0x319f8c strne r2, [r4, #0x24] */
/* @0x319f90 str r0, [r4, #0x20] */
/* @0x319f94 streq r2, [r3, #0x2c]! */
/* @0x319f98 bne 0x31a094 <__gnu_Unwind_Backtrace+0x3a4> */
/* @0x319f9c b 0x31a090 <__gnu_Unwind_Backtrace+0x3a0> */
/* @0x319fa0 mov r0, r6 */
/* @0x319fa4 mov r1, #13 */
/* @0x319fa8 ldr r8, [r4, #0x20] */
/* @0x319fac bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x319fb0 cmp r8, r0 */
/* @0x319fb4 bne 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319fb8 ldr r3, [r4, #0x28] */
/* @0x319fbc cmp r5, r3 */
/* @0x319fc0 bne 0x319ff4 <__gnu_Unwind_Backtrace+0x304> */
/* @0x319fc4 mov r0, r5 */
/* @0x319fc8 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x319fcc mov r1, #15 */
/* @0x319fd0 mov r2, r0 */
/* @0x319fd4 mov r0, r6 */
/* @0x319fd8 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x319fdc mov r0, r6 */
/* @0x319fe0 mov r1, #0 */
/* @0x319fe4 mov r2, r4 */
/* @0x319fe8 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x319fec mov r0, #7 */
/* @0x319ff0 b 0x31a198 <__gnu_Unwind_Backtrace+0x4a8> */
/* @0x319ff4 add r5, r5, #8 */
/* @0x319ff8 b 0x319e44 <__gnu_Unwind_Backtrace+0x154> */
/* @0x319ffc ldr r8, [r5] */
/* @0x31a000 cmp r7, #0 */
/* @0x31a004 bic r8, r8, #-2147483648 */
/* @0x31a008 bne 0x31a0a0 <__gnu_Unwind_Backtrace+0x3b0> */
/* @0x31a00c cmp r0, #0 */
/* @0x31a010 beq 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a014 ldr r3, [sp, #0xc] */
/* @0x31a018 cmp r8, #0 */
/* @0x31a01c orreq r3, r3, #1 */
/* @0x31a020 cmp r3, #0 */
/* @0x31a024 beq 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a028 add r11, sp, #16 */
/* @0x31a02c mov r12, r7 */
/* @0x31a030 add r3, r4, #88 */
/* @0x31a034 str r3, [sp, #0x8] */
/* @0x31a038 cmp r12, r8 */
/* @0x31a03c beq 0x31a07c <__gnu_Unwind_Backtrace+0x38c> */
/* @0x31a040 add r12, r12, #1 */
/* @0x31a044 ldr r3, [sp, #0x8] */
/* @0x31a048 str r12, [sp, #0x4] */
/* @0x31a04c add r0, r5, r12, lsl #2 */
/* @0x31a050 str r3, [sp, #0x10] */
/* @0x31a054 bl 0x3198bc <__gnu_uldivmod_helper+0x2c8> */
/* @0x31a058 mov r2, #0 */
/* @0x31a05c mov r3, r11 */
/* @0x31a060 mov r1, r0 */
/* @0x31a064 mov r0, r4 */
/* @0x31a068 blx 0x3185b4 <__cxa_type_match> */
/* @0x31a06c ldr r12, [sp, #0x4] */
/* @0x31a070 cmp r0, #0 */
/* @0x31a074 beq 0x31a038 <__gnu_Unwind_Backtrace+0x348> */
/* @0x31a078 b 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a07c mov r0, r6 */
/* @0x31a080 mov r1, #13 */
/* @0x31a084 bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x31a088 ldr r3, [sp, #0x10] */
/* @0x31a08c str r0, [r4, #0x20] */
/* @0x31a090 str r3, [r4, #0x24] */
/* @0x31a094 str r5, [r4, #0x28] */
/* @0x31a098 mov r0, #6 */
/* @0x31a09c b 0x31a198 <__gnu_Unwind_Backtrace+0x4a8> */
/* @0x31a0a0 mov r0, r6 */
/* @0x31a0a4 mov r1, #13 */
/* @0x31a0a8 ldr r11, [r4, #0x20] */
/* @0x31a0ac bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x31a0b0 cmp r11, r0 */
/* @0x31a0b4 bne 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a0b8 ldr r3, [r4, #0x28] */
/* @0x31a0bc cmp r5, r3 */
/* @0x31a0c0 bne 0x31a118 <__gnu_Unwind_Backtrace+0x428> */
/* @0x31a0c4 mov r10, #0 */
/* @0x31a0c8 mov r3, #4 */
/* @0x31a0cc str r8, [r4, #0x28] */
/* @0x31a0d0 str r3, [r4, #0x30] */
/* @0x31a0d4 add r3, r5, r3 */
/* @0x31a0d8 str r10, [r4, #0x2c] */
/* @0x31a0dc str r3, [r4, #0x34] */
/* @0x31a0e0 ldr r3, [r5] */
/* @0x31a0e4 cmp r3, r10 */
/* @0x31a0e8 bge 0x31a114 <__gnu_Unwind_Backtrace+0x424> */
/* @0x31a0ec add r0, r8, #1 */
/* @0x31a0f0 add r0, r5, r0, lsl #2 */
/* @0x31a0f4 bl 0x319630 <__gnu_uldivmod_helper+0x3c> */
/* @0x31a0f8 mov r1, #15 */
/* @0x31a0fc mov r2, r0 */
/* @0x31a100 mov r0, r6 */
/* @0x31a104 bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x31a108 mov r0, r6 */
/* @0x31a10c mov r1, r10 */
/* @0x31a110 b 0x319fe4 <__gnu_Unwind_Backtrace+0x2f4> */
/* @0x31a114 mov r10, #1 */
/* @0x31a118 ldr r3, [r5] */
/* @0x31a11c add r8, r8, #1 */
/* @0x31a120 cmp r3, #0 */
/* @0x31a124 addlt r5, r5, #4 */
/* @0x31a128 add r5, r5, r8, lsl #2 */
/* @0x31a12c b 0x319e44 <__gnu_Unwind_Backtrace+0x154> */
/* @0x31a130 mov r10, #0 */
/* @0x31a134 cmp r9, #2 */
/* @0x31a138 ble 0x31a144 <__gnu_Unwind_Backtrace+0x454> */
/* @0x31a13c bl 0x3198d0 <__gnu_uldivmod_helper+0x2dc> */
/* @0x31a140 b 0x31a150 <__gnu_Unwind_Backtrace+0x460> */
/* @0x31a144 mov r0, r6 */
/* @0x31a148 add r1, sp, #20 */
/* @0x31a14c bl 0x31a73c <__gnu_unwind_execute> */
/* @0x31a150 cmp r0, #0 */
/* @0x31a154 bne 0x31a194 <__gnu_Unwind_Backtrace+0x4a4> */
/* @0x31a158 cmp r10, #0 */
/* @0x31a15c moveq r0, #8 */
/* @0x31a160 beq 0x31a198 <__gnu_Unwind_Backtrace+0x4a8> */
/* @0x31a164 mov r1, #15 */
/* @0x31a168 mov r0, r6 */
/* @0x31a16c bl 0x319c40 <_Unwind_VRS_Get+0x5c> */
/* @0x31a170 mov r1, #14 */
/* @0x31a174 mov r2, r0 */
/* @0x31a178 mov r0, r6 */
/* @0x31a17c bl 0x319cc4 <_Unwind_VRS_Set+0x5c> */
/* @0x31a180 ldr r2, [pc, #0x18] */
/* @0x31a184 mov r0, r6 */
/* @0x31a188 mov r1, #15 */
/* @0x31a18c ldr r2, [pc, r2] */
/* @0x31a190 b 0x319fe8 <__gnu_Unwind_Backtrace+0x2f8> */
/* @0x31a194 mov r0, #9 */
/* @0x31a198 add sp, sp, #36 */
/* @0x31a19c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x31a1a0 andeq r7, sp, r0, asr #21 */

/* ── FUNC 0x31a1a4 · __aeabi_unwind_cpp_pr0 · size=8 · insn=2 */
/* @0x31a1a4 mov r3, #0 */
/* @0x31a1a8 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4> */

/* ── FUNC 0x31a1ac · __aeabi_unwind_cpp_pr1 · size=8 · insn=2 */
/* @0x31a1ac mov r3, #1 */
/* @0x31a1b0 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4> */

/* ── FUNC 0x31a1b4 · __aeabi_unwind_cpp_pr2 · size=8 · insn=2 */
/* @0x31a1b4 mov r3, #2 */
/* @0x31a1b8 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4> */

/* ── FUNC 0x31a1bc · _Unwind_VRS_Pop · size=844 · insn=211 */
/* @0x31a1bc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x31a1c0 mov r4, r0 */
/* @0x31a1c4 sub sp, sp, #268 */
/* @0x31a1c8 mov r5, r2 */
/* @0x31a1cc cmp r1, #4 */
/* @0x31a1d0 addls pc, pc, r1, lsl #2 */
/* @0x31a1d4 b 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a1d8 b 0x31a1ec <_Unwind_VRS_Pop+0x30> */
/* @0x31a1dc b 0x31a230 <_Unwind_VRS_Pop+0x74> */
/* @0x31a1e0 b 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a1e4 b 0x31a410 <_Unwind_VRS_Pop+0x254> */
/* @0x31a1e8 b 0x31a48c <_Unwind_VRS_Pop+0x2d0> */
/* @0x31a1ec cmp r3, #0 */
/* @0x31a1f0 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a1f4 uxth r1, r2 */
/* @0x31a1f8 ldr r2, [r0, #0x38] */
/* @0x31a1fc mov r0, #1 */
/* @0x31a200 ands r12, r1, r0, lsl r3 */
/* @0x31a204 addne r12, r4, r3, lsl #2 */
/* @0x31a208 add r3, r3, #1 */
/* @0x31a20c ldrne r6, [r2] */
/* @0x31a210 addne r2, r2, #4 */
/* @0x31a214 strne r6, [r12, #0x4] */
/* @0x31a218 cmp r3, #16 */
/* @0x31a21c bne 0x31a200 <_Unwind_VRS_Pop+0x44> */
/* @0x31a220 ands r0, r5, #8192 */
/* @0x31a224 streq r2, [r4, #0x38] */
/* @0x31a228 beq 0x31a500 <_Unwind_VRS_Pop+0x344> */
/* @0x31a22c b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a230 bic r2, r3, #4 */
/* @0x31a234 cmp r2, #1 */
/* @0x31a238 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a23c cmp r3, #1 */
/* @0x31a240 lsr r6, r5, #16 */
/* @0x31a244 uxth r5, r5 */
/* @0x31a248 add r2, r5, r6 */
/* @0x31a24c movne r1, #32 */
/* @0x31a250 moveq r1, #16 */
/* @0x31a254 cmp r2, r1 */
/* @0x31a258 bhi 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a25c subs r1, r3, #1 */
/* @0x31a260 rsbs r9, r1, #0 */
/* @0x31a264 adcs r9, r9, r1 */
/* @0x31a268 cmp r6, #15 */
/* @0x31a26c movls r8, #0 */
/* @0x31a270 movhi r8, #1 */
/* @0x31a274 tst r9, r8 */
/* @0x31a278 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a27c cmp r8, #0 */
/* @0x31a280 movne r8, r5 */
/* @0x31a284 bne 0x31a290 <_Unwind_VRS_Pop+0xd4> */
/* @0x31a288 cmp r2, #16 */
/* @0x31a28c subhi r8, r2, #16 */
/* @0x31a290 adds r7, r8, #0 */
/* @0x31a294 movne r7, #1 */
/* @0x31a298 cmp r3, #5 */
/* @0x31a29c cmpne r8, #0 */
/* @0x31a2a0 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a2a4 cmp r6, #15 */
/* @0x31a2a8 bhi 0x31a2e8 <_Unwind_VRS_Pop+0x12c> */
/* @0x31a2ac ldr r2, [r4] */
/* @0x31a2b0 tst r2, #1 */
/* @0x31a2b4 beq 0x31a2e8 <_Unwind_VRS_Pop+0x12c> */
/* @0x31a2b8 cmp r3, #5 */
/* @0x31a2bc mov r0, r4 */
/* @0x31a2c0 bic r1, r2, #1 */
/* @0x31a2c4 str r1, [r0], #72 */
/* @0x31a2c8 bne 0x31a2dc <_Unwind_VRS_Pop+0x120> */
/* @0x31a2cc orr r1, r1, #2 */
/* @0x31a2d0 str r1, [r4] */
/* @0x31a2d4 bl 0x31a534 <__gnu_Unwind_Save_VFP_D> */
/* @0x31a2d8 b 0x31a2e8 <_Unwind_VRS_Pop+0x12c> */
/* @0x31a2dc bic r2, r2, #3 */
/* @0x31a2e0 str r2, [r4] */
/* @0x31a2e4 bl 0x31a524 <__gnu_Unwind_Save_VFP> */
/* @0x31a2e8 cmp r7, #0 */
/* @0x31a2ec beq 0x31a30c <_Unwind_VRS_Pop+0x150> */
/* @0x31a2f0 ldr r3, [r4] */
/* @0x31a2f4 tst r3, #4 */
/* @0x31a2f8 beq 0x31a30c <_Unwind_VRS_Pop+0x150> */
/* @0x31a2fc mov r0, r4 */
/* @0x31a300 bic r3, r3, #4 */
/* @0x31a304 str r3, [r0], #208 */
/* @0x31a308 bl 0x31a544 <__gnu_Unwind_Save_VFP_D_16_to_31> */
/* @0x31a30c cmp r9, #0 */
/* @0x31a310 beq 0x31a328 <_Unwind_VRS_Pop+0x16c> */
/* @0x31a314 add r0, sp, #128 */
/* @0x31a318 bl 0x31a524 <__gnu_Unwind_Save_VFP> */
/* @0x31a31c cmp r7, #0 */
/* @0x31a320 bne 0x31a348 <_Unwind_VRS_Pop+0x18c> */
/* @0x31a324 b 0x31a34c <_Unwind_VRS_Pop+0x190> */
/* @0x31a328 cmp r6, #15 */
/* @0x31a32c bhi 0x31a338 <_Unwind_VRS_Pop+0x17c> */
/* @0x31a330 add r0, sp, #128 */
/* @0x31a334 bl 0x31a534 <__gnu_Unwind_Save_VFP_D> */
/* @0x31a338 cmp r7, #0 */
/* @0x31a33c beq 0x31a34c <_Unwind_VRS_Pop+0x190> */
/* @0x31a340 mov r0, sp */
/* @0x31a344 bl 0x31a544 <__gnu_Unwind_Save_VFP_D_16_to_31> */
/* @0x31a348 rsb r5, r6, #16 */
/* @0x31a34c ldr r2, [r4, #0x38] */
/* @0x31a350 cmp r5, #0 */
/* @0x31a354 mov r3, r2 */
/* @0x31a358 ble 0x31a388 <_Unwind_VRS_Pop+0x1cc> */
/* @0x31a35c add r3, sp, #128 */
/* @0x31a360 lsl r5, r5, #1 */
/* @0x31a364 add r3, r3, r6, lsl #3 */
/* @0x31a368 sub r0, r2, #4 */
/* @0x31a36c rsb r3, r2, r3 */
/* @0x31a370 mov r1, r5 */
/* @0x31a374 subs r1, r1, #1 */
/* @0x31a378 ldrhs r12, [r0, #0x4]! */
/* @0x31a37c strhs r12, [r3, r0] */
/* @0x31a380 bhs 0x31a374 <_Unwind_VRS_Pop+0x1b8> */
/* @0x31a384 add r3, r2, r5, lsl #2 */
/* @0x31a388 cmp r7, #0 */
/* @0x31a38c beq 0x31a3cc <_Unwind_VRS_Pop+0x210> */
/* @0x31a390 cmp r6, #16 */
/* @0x31a394 movhs r0, r6 */
/* @0x31a398 movlo r0, #16 */
/* @0x31a39c add r2, sp, #264 */
/* @0x31a3a0 lsl r8, r8, #1 */
/* @0x31a3a4 add r0, r2, r0, lsl #3 */
/* @0x31a3a8 mov r2, #0 */
/* @0x31a3ac sub r0, r0, #392 */
/* @0x31a3b0 cmp r2, r8 */
/* @0x31a3b4 lsl r1, r2, #2 */
/* @0x31a3b8 ldrne r1, [r3, r2, lsl #2] */
/* @0x31a3bc strne r1, [r0, r2, lsl #2] */
/* @0x31a3c0 addne r2, r2, #1 */
/* @0x31a3c4 bne 0x31a3b0 <_Unwind_VRS_Pop+0x1f4> */
/* @0x31a3c8 add r3, r3, r1 */
/* @0x31a3cc cmp r9, #0 */
/* @0x31a3d0 addne r3, r3, #4 */
/* @0x31a3d4 cmp r9, #0 */
/* @0x31a3d8 str r3, [r4, #0x38] */
/* @0x31a3dc beq 0x31a3ec <_Unwind_VRS_Pop+0x230> */
/* @0x31a3e0 add r0, sp, #128 */
/* @0x31a3e4 bl 0x31a51c <__gnu_Unwind_Restore_VFP> */
/* @0x31a3e8 b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a3ec cmp r6, #15 */
/* @0x31a3f0 bhi 0x31a3fc <_Unwind_VRS_Pop+0x240> */
/* @0x31a3f4 add r0, sp, #128 */
/* @0x31a3f8 bl 0x31a52c <__gnu_Unwind_Restore_VFP_D> */
/* @0x31a3fc cmp r7, #0 */
/* @0x31a400 beq 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a404 mov r0, sp */
/* @0x31a408 bl 0x31a53c <__gnu_Unwind_Restore_VFP_D_16_to_31> */
/* @0x31a40c b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a410 cmp r3, #3 */
/* @0x31a414 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a418 lsr r7, r2, #16 */
/* @0x31a41c uxth r5, r2 */
/* @0x31a420 add r3, r5, r7 */
/* @0x31a424 cmp r3, #16 */
/* @0x31a428 bhi 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a42c ldr r3, [r0] */
/* @0x31a430 tst r3, #8 */
/* @0x31a434 beq 0x31a444 <_Unwind_VRS_Pop+0x288> */
/* @0x31a438 bic r3, r3, #8 */
/* @0x31a43c str r3, [r0], #336 */
/* @0x31a440 bl 0x31a590 <__gnu_Unwind_Save_WMMXD> */
/* @0x31a444 add r6, sp, #128 */
/* @0x31a448 lsl r5, r5, #1 */
/* @0x31a44c add r7, r6, r7, lsl #3 */
/* @0x31a450 mov r0, r6 */
/* @0x31a454 bl 0x31a590 <__gnu_Unwind_Save_WMMXD> */
/* @0x31a458 ldr r3, [r4, #0x38] */
/* @0x31a45c mov r2, r5 */
/* @0x31a460 sub r1, r3, #4 */
/* @0x31a464 rsb r7, r3, r7 */
/* @0x31a468 subs r2, r2, #1 */
/* @0x31a46c ldrhs r0, [r1, #0x4]! */
/* @0x31a470 strhs r0, [r7, r1] */
/* @0x31a474 bhs 0x31a468 <_Unwind_VRS_Pop+0x2ac> */
/* @0x31a478 add r5, r3, r5, lsl #2 */
/* @0x31a47c mov r0, r6 */
/* @0x31a480 str r5, [r4, #0x38] */
/* @0x31a484 bl 0x31a54c <__gnu_Unwind_Restore_WMMXD> */
/* @0x31a488 b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a48c cmp r2, #16 */
/* @0x31a490 cmpls r3, #0 */
/* @0x31a494 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338> */
/* @0x31a498 ldr r3, [r0] */
/* @0x31a49c tst r3, #16 */
/* @0x31a4a0 beq 0x31a4b0 <_Unwind_VRS_Pop+0x2f4> */
/* @0x31a4a4 bic r3, r3, #16 */
/* @0x31a4a8 str r3, [r0], #464 */
/* @0x31a4ac bl 0x31a5e8 <__gnu_Unwind_Save_WMMXC> */
/* @0x31a4b0 add r6, sp, #128 */
/* @0x31a4b4 mov r0, r6 */
/* @0x31a4b8 bl 0x31a5e8 <__gnu_Unwind_Save_WMMXC> */
/* @0x31a4bc ldr r2, [r4, #0x38] */
/* @0x31a4c0 mov r3, #0 */
/* @0x31a4c4 mov r1, #1 */
/* @0x31a4c8 ands r12, r5, r1, lsl r3 */
/* @0x31a4cc ldrne r0, [r2] */
/* @0x31a4d0 addne r2, r2, #4 */
/* @0x31a4d4 strne r0, [r6, r3, lsl #2] */
/* @0x31a4d8 add r3, r3, #1 */
/* @0x31a4dc cmp r3, #4 */
/* @0x31a4e0 bne 0x31a4c8 <_Unwind_VRS_Pop+0x30c> */
/* @0x31a4e4 str r2, [r4, #0x38] */
/* @0x31a4e8 mov r0, r6 */
/* @0x31a4ec bl 0x31a5d4 <__gnu_Unwind_Restore_WMMXC> */
/* @0x31a4f0 b 0x31a4fc <_Unwind_VRS_Pop+0x340> */
/* @0x31a4f4 mov r0, #2 */
/* @0x31a4f8 b 0x31a500 <_Unwind_VRS_Pop+0x344> */
/* @0x31a4fc mov r0, #0 */
/* @0x31a500 add sp, sp, #268 */
/* @0x31a504 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x31a508 · __restore_core_regs · size=20 · insn=5 */
/* @0x31a508 add r1, r0, #52 */
/* @0x31a50c ldm r1, {r3, r4, r5} */
/* @0x31a510 push {r3, r4, r5} */
/* @0x31a514 ldm r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x31a518 ldm sp, {sp, lr, pc} */

/* ── FUNC 0x31a508 · restore_core_regs · alias of the symbol above · insn=0 */

/* ── FUNC 0x31a51c · anon_31a51c · size=224 · insn=56 */
/* @0x31a51c fldmiax r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a520 bx lr */
/* @0x31a524 fstmiax r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a528 bx lr */
/* @0x31a52c vldmia r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a530 bx lr */
/* @0x31a534 vstmia r0, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x31a538 bx lr */
/* @0x31a53c vldmia r0, {d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31} */
/* @0x31a540 bx lr */
/* @0x31a544 vstmia r0, {d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31} */
/* @0x31a548 bx lr */
/* @0x31a54c ldcl p1, c0, [r0], #8 */
/* @0x31a550 ldcl p1, c1, [r0], #8 */
/* @0x31a554 ldcl p1, c2, [r0], #8 */
/* @0x31a558 ldcl p1, c3, [r0], #8 */
/* @0x31a55c ldcl p1, c4, [r0], #8 */
/* @0x31a560 ldcl p1, c5, [r0], #8 */
/* @0x31a564 ldcl p1, c6, [r0], #8 */
/* @0x31a568 ldcl p1, c7, [r0], #8 */
/* @0x31a56c ldcl p1, c8, [r0], #8 */
/* @0x31a570 ldcl p1, c9, [r0], #8 */
/* @0x31a574 ldcl p1, c10, [r0], #8 */
/* @0x31a578 ldcl p1, c11, [r0], #8 */
/* @0x31a57c ldcl p1, c12, [r0], #8 */
/* @0x31a580 ldcl p1, c13, [r0], #8 */
/* @0x31a584 ldcl p1, c14, [r0], #8 */
/* @0x31a588 ldcl p1, c15, [r0], #8 */
/* @0x31a58c bx lr */
/* @0x31a590 stcl p1, c0, [r0], #8 */
/* @0x31a594 stcl p1, c1, [r0], #8 */
/* @0x31a598 stcl p1, c2, [r0], #8 */
/* @0x31a59c stcl p1, c3, [r0], #8 */
/* @0x31a5a0 stcl p1, c4, [r0], #8 */
/* @0x31a5a4 stcl p1, c5, [r0], #8 */
/* @0x31a5a8 stcl p1, c6, [r0], #8 */
/* @0x31a5ac stcl p1, c7, [r0], #8 */
/* @0x31a5b0 stcl p1, c8, [r0], #8 */
/* @0x31a5b4 stcl p1, c9, [r0], #8 */
/* @0x31a5b8 stcl p1, c10, [r0], #8 */
/* @0x31a5bc stcl p1, c11, [r0], #8 */
/* @0x31a5c0 stcl p1, c12, [r0], #8 */
/* @0x31a5c4 stcl p1, c13, [r0], #8 */
/* @0x31a5c8 stcl p1, c14, [r0], #8 */
/* @0x31a5cc stcl p1, c15, [r0], #8 */
/* @0x31a5d0 bx lr */
/* @0x31a5d4 ldc2 p1, c8, [r0], #4 */
/* @0x31a5d8 ldc2 p1, c9, [r0], #4 */
/* @0x31a5dc ldc2 p1, c10, [r0], #4 */
/* @0x31a5e0 ldc2 p1, c11, [r0], #4 */
/* @0x31a5e4 bx lr */
/* @0x31a5e8 stc2 p1, c8, [r0], #4 */
/* @0x31a5ec stc2 p1, c9, [r0], #4 */
/* @0x31a5f0 stc2 p1, c10, [r0], #4 */
/* @0x31a5f4 stc2 p1, c11, [r0], #4 */
/* @0x31a5f8 bx lr */

/* ── FUNC 0x31a5fc · _Unwind_RaiseException · size=36 · insn=9 */
/* @0x31a5fc push {sp, lr, pc} */
/* @0x31a600 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12} */
/* @0x31a604 mov r3, #0 */
/* @0x31a608 push {r2, r3} */
/* @0x31a60c add r1, sp, #4 */
/* @0x31a610 bl 0x319a6c <__gnu_Unwind_RaiseException> */
/* @0x31a614 ldr lr, [sp, #0x40] */
/* @0x31a618 add sp, sp, #72 */
/* @0x31a61c bx lr */
