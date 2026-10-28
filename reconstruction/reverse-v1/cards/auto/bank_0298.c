/* libyoyo.so 覆盖卡组 0298
 * 函数 0x31b698..0x31ba7c，共 2 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x31b698 · __udivdi3 · size=996 · insn=249 */
/* @0x31b698 cmp r3, #0 */
/* @0x31b69c push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x31b6a0 mov r6, r0 */
/* @0x31b6a4 mov r5, r1 */
/* @0x31b6a8 mov r4, r2 */
/* @0x31b6ac mov r7, r0 */
/* @0x31b6b0 mov r8, r1 */
/* @0x31b6b4 bne 0x31b91c <__udivdi3+0x284> */
/* @0x31b6b8 cmp r2, r1 */
/* @0x31b6bc bls 0x31b784 <__udivdi3+0xec> */
/* @0x31b6c0 clz r3, r2 */
/* @0x31b6c4 cmp r3, #0 */
/* @0x31b6c8 rsbne r8, r3, #32 */
/* @0x31b6cc lslne r4, r2, r3 */
/* @0x31b6d0 lsrne r8, r0, r8 */
/* @0x31b6d4 lslne r7, r0, r3 */
/* @0x31b6d8 orrne r8, r8, r1, lsl r3 */
/* @0x31b6dc lsr r5, r4, #16 */
/* @0x31b6e0 uxth r9, r4 */
/* @0x31b6e4 mov r0, r8 */
/* @0x31b6e8 mov r1, r5 */
/* @0x31b6ec bl 0x318c48 <__udivsi3> */
/* @0x31b6f0 mov r1, r5 */
/* @0x31b6f4 mov r6, r0 */
/* @0x31b6f8 mul r10, r9, r0 */
/* @0x31b6fc mov r0, r8 */
/* @0x31b700 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b704 lsr r3, r7, #16 */
/* @0x31b708 orr r1, r3, r1, lsl #16 */
/* @0x31b70c cmp r1, r10 */
/* @0x31b710 movhs r8, r6 */
/* @0x31b714 bhs 0x31b730 <__udivdi3+0x98> */
/* @0x31b718 adds r1, r1, r4 */
/* @0x31b71c sub r8, r6, #1 */
/* @0x31b720 bhs 0x31b730 <__udivdi3+0x98> */
/* @0x31b724 cmp r1, r10 */
/* @0x31b728 sublo r8, r6, #2 */
/* @0x31b72c addlo r1, r1, r4 */
/* @0x31b730 rsb r10, r10, r1 */
/* @0x31b734 mov r1, r5 */
/* @0x31b738 uxth r7, r7 */
/* @0x31b73c mov r0, r10 */
/* @0x31b740 bl 0x318c48 <__udivsi3> */
/* @0x31b744 mov r1, r5 */
/* @0x31b748 mov r6, r0 */
/* @0x31b74c mul r9, r9, r0 */
/* @0x31b750 mov r0, r10 */
/* @0x31b754 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b758 orr r1, r7, r1, lsl #16 */
/* @0x31b75c cmp r1, r9 */
/* @0x31b760 movhs r0, r6 */
/* @0x31b764 bhs 0x31b77c <__udivdi3+0xe4> */
/* @0x31b768 adds r4, r1, r4 */
/* @0x31b76c sub r0, r6, #1 */
/* @0x31b770 bhs 0x31b77c <__udivdi3+0xe4> */
/* @0x31b774 cmp r4, r9 */
/* @0x31b778 sublo r0, r6, #2 */
/* @0x31b77c orr r0, r0, r8, lsl #16 */
/* @0x31b780 b 0x31ba60 <__udivdi3+0x3c8> */
/* @0x31b784 cmp r2, #0 */
/* @0x31b788 bne 0x31b79c <__udivdi3+0x104> */
/* @0x31b78c mov r0, #1 */
/* @0x31b790 mov r1, r2 */
/* @0x31b794 bl 0x318c48 <__udivsi3> */
/* @0x31b798 mov r4, r0 */
/* @0x31b79c clz r3, r4 */
/* @0x31b7a0 cmp r3, #0 */
/* @0x31b7a4 rsbeq r10, r4, r5 */
/* @0x31b7a8 moveq r5, #1 */
/* @0x31b7ac beq 0x31b874 <__udivdi3+0x1dc> */
/* @0x31b7b0 lsl r4, r4, r3 */
/* @0x31b7b4 rsb r9, r3, #32 */
/* @0x31b7b8 lsr r11, r5, r9 */
/* @0x31b7bc lsl r7, r6, r3 */
/* @0x31b7c0 lsr r9, r6, r9 */
/* @0x31b7c4 lsr r6, r4, #16 */
/* @0x31b7c8 mov r0, r11 */
/* @0x31b7cc orr r9, r9, r5, lsl r3 */
/* @0x31b7d0 mov r1, r6 */
/* @0x31b7d4 uxth r10, r4 */
/* @0x31b7d8 bl 0x318c48 <__udivsi3> */
/* @0x31b7dc mov r1, r6 */
/* @0x31b7e0 mov r8, r0 */
/* @0x31b7e4 mul r5, r10, r0 */
/* @0x31b7e8 mov r0, r11 */
/* @0x31b7ec bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b7f0 lsr r3, r9, #16 */
/* @0x31b7f4 orr r1, r3, r1, lsl #16 */
/* @0x31b7f8 cmp r1, r5 */
/* @0x31b7fc movhs r11, r8 */
/* @0x31b800 bhs 0x31b81c <__udivdi3+0x184> */
/* @0x31b804 adds r1, r1, r4 */
/* @0x31b808 sub r11, r8, #1 */
/* @0x31b80c bhs 0x31b81c <__udivdi3+0x184> */
/* @0x31b810 cmp r1, r5 */
/* @0x31b814 sublo r11, r8, #2 */
/* @0x31b818 addlo r1, r1, r4 */
/* @0x31b81c rsb r5, r5, r1 */
/* @0x31b820 mov r1, r6 */
/* @0x31b824 uxth r9, r9 */
/* @0x31b828 mov r0, r5 */
/* @0x31b82c bl 0x318c48 <__udivsi3> */
/* @0x31b830 mov r1, r6 */
/* @0x31b834 mov r8, r0 */
/* @0x31b838 mul r10, r10, r0 */
/* @0x31b83c mov r0, r5 */
/* @0x31b840 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b844 orr r1, r9, r1, lsl #16 */
/* @0x31b848 cmp r1, r10 */
/* @0x31b84c movhs r5, r8 */
/* @0x31b850 bhs 0x31b86c <__udivdi3+0x1d4> */
/* @0x31b854 adds r1, r1, r4 */
/* @0x31b858 sub r5, r8, #1 */
/* @0x31b85c bhs 0x31b86c <__udivdi3+0x1d4> */
/* @0x31b860 cmp r1, r10 */
/* @0x31b864 sublo r5, r8, #2 */
/* @0x31b868 addlo r1, r1, r4 */
/* @0x31b86c rsb r10, r10, r1 */
/* @0x31b870 orr r5, r5, r11, lsl #16 */
/* @0x31b874 lsr r6, r4, #16 */
/* @0x31b878 mov r0, r10 */
/* @0x31b87c uxth r9, r4 */
/* @0x31b880 mov r1, r6 */
/* @0x31b884 bl 0x318c48 <__udivsi3> */
/* @0x31b888 mov r1, r6 */
/* @0x31b88c mov r8, r0 */
/* @0x31b890 mul r11, r9, r0 */
/* @0x31b894 mov r0, r10 */
/* @0x31b898 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b89c lsr r3, r7, #16 */
/* @0x31b8a0 orr r1, r3, r1, lsl #16 */
/* @0x31b8a4 cmp r1, r11 */
/* @0x31b8a8 movhs r10, r8 */
/* @0x31b8ac bhs 0x31b8c8 <__udivdi3+0x230> */
/* @0x31b8b0 adds r1, r1, r4 */
/* @0x31b8b4 sub r10, r8, #1 */
/* @0x31b8b8 bhs 0x31b8c8 <__udivdi3+0x230> */
/* @0x31b8bc cmp r1, r11 */
/* @0x31b8c0 sublo r10, r8, #2 */
/* @0x31b8c4 addlo r1, r1, r4 */
/* @0x31b8c8 rsb r11, r11, r1 */
/* @0x31b8cc mov r1, r6 */
/* @0x31b8d0 uxth r7, r7 */
/* @0x31b8d4 mov r0, r11 */
/* @0x31b8d8 bl 0x318c48 <__udivsi3> */
/* @0x31b8dc mov r1, r6 */
/* @0x31b8e0 mov r8, r0 */
/* @0x31b8e4 mul r9, r9, r0 */
/* @0x31b8e8 mov r0, r11 */
/* @0x31b8ec bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b8f0 orr r1, r7, r1, lsl #16 */
/* @0x31b8f4 cmp r1, r9 */
/* @0x31b8f8 movhs r0, r8 */
/* @0x31b8fc bhs 0x31b914 <__udivdi3+0x27c> */
/* @0x31b900 adds r4, r1, r4 */
/* @0x31b904 sub r0, r8, #1 */
/* @0x31b908 bhs 0x31b914 <__udivdi3+0x27c> */
/* @0x31b90c cmp r4, r9 */
/* @0x31b910 sublo r0, r8, #2 */
/* @0x31b914 orr r0, r0, r10, lsl #16 */
/* @0x31b918 b 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31b91c cmp r3, r1 */
/* @0x31b920 bhi 0x31ba68 <__udivdi3+0x3d0> */
/* @0x31b924 clz r7, r3 */
/* @0x31b928 cmp r7, #0 */
/* @0x31b92c bne 0x31b950 <__udivdi3+0x2b8> */
/* @0x31b930 cmp r1, r3 */
/* @0x31b934 cmpls r0, r2 */
/* @0x31b938 movlo r5, #0 */
/* @0x31b93c movhs r5, #1 */
/* @0x31b940 movhs r0, #1 */
/* @0x31b944 movhs r5, r7 */
/* @0x31b948 bhs 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31b94c b 0x31ba6c <__udivdi3+0x3d4> */
/* @0x31b950 rsb r1, r7, #32 */
/* @0x31b954 lsl r8, r2, r7 */
/* @0x31b958 lsr r4, r2, r1 */
/* @0x31b95c orr r4, r4, r3, lsl r7 */
/* @0x31b960 lsr r3, r5, r1 */
/* @0x31b964 lsr r1, r0, r1 */
/* @0x31b968 str r3, [sp] */
/* @0x31b96c lsr r9, r4, #16 */
/* @0x31b970 orr r5, r1, r5, lsl r7 */
/* @0x31b974 mov r0, r3 */
/* @0x31b978 uxth r10, r4 */
/* @0x31b97c mov r1, r9 */
/* @0x31b980 bl 0x318c48 <__udivsi3> */
/* @0x31b984 ldr r3, [sp] */
/* @0x31b988 mov r1, r9 */
/* @0x31b98c mul r2, r10, r0 */
/* @0x31b990 mov r11, r0 */
/* @0x31b994 mov r0, r3 */
/* @0x31b998 str r2, [sp, #0x4] */
/* @0x31b99c bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b9a0 lsr r12, r5, #16 */
/* @0x31b9a4 ldr r2, [sp, #0x4] */
/* @0x31b9a8 orr r1, r12, r1, lsl #16 */
/* @0x31b9ac cmp r1, r2 */
/* @0x31b9b0 movhs r3, r11 */
/* @0x31b9b4 bhs 0x31b9d0 <__udivdi3+0x338> */
/* @0x31b9b8 adds r1, r1, r4 */
/* @0x31b9bc sub r3, r11, #1 */
/* @0x31b9c0 bhs 0x31b9d0 <__udivdi3+0x338> */
/* @0x31b9c4 cmp r1, r2 */
/* @0x31b9c8 sublo r3, r11, #2 */
/* @0x31b9cc addlo r1, r1, r4 */
/* @0x31b9d0 rsb r12, r2, r1 */
/* @0x31b9d4 mov r1, r9 */
/* @0x31b9d8 stm sp, {r3, r12} */
/* @0x31b9dc uxth r5, r5 */
/* @0x31b9e0 mov r0, r12 */
/* @0x31b9e4 bl 0x318c48 <__udivsi3> */
/* @0x31b9e8 ldr r12, [sp, #0x4] */
/* @0x31b9ec mov r1, r9 */
/* @0x31b9f0 mov r11, r0 */
/* @0x31b9f4 mul r10, r10, r0 */
/* @0x31b9f8 mov r0, r12 */
/* @0x31b9fc bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31ba00 ldr r3, [sp] */
/* @0x31ba04 orr r1, r5, r1, lsl #16 */
/* @0x31ba08 cmp r1, r10 */
/* @0x31ba0c movhs r0, r11 */
/* @0x31ba10 bhs 0x31ba2c <__udivdi3+0x394> */
/* @0x31ba14 adds r1, r1, r4 */
/* @0x31ba18 sub r0, r11, #1 */
/* @0x31ba1c bhs 0x31ba2c <__udivdi3+0x394> */
/* @0x31ba20 cmp r1, r10 */
/* @0x31ba24 sublo r0, r11, #2 */
/* @0x31ba28 addlo r1, r1, r4 */
/* @0x31ba2c orr r0, r0, r3, lsl #16 */
/* @0x31ba30 rsb r10, r10, r1 */
/* @0x31ba34 umull r2, r3, r0, r8 */
/* @0x31ba38 cmp r3, r10 */
/* @0x31ba3c bhi 0x31ba5c <__udivdi3+0x3c4> */
/* @0x31ba40 movne r5, #0 */
/* @0x31ba44 moveq r5, #1 */
/* @0x31ba48 cmp r2, r6, lsl r7 */
/* @0x31ba4c movls r5, #0 */
/* @0x31ba50 andhi r5, r5, #1 */
/* @0x31ba54 cmp r5, #0 */
/* @0x31ba58 beq 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31ba5c sub r0, r0, #1 */
/* @0x31ba60 mov r5, #0 */
/* @0x31ba64 b 0x31ba70 <__udivdi3+0x3d8> */
/* @0x31ba68 mov r5, #0 */
/* @0x31ba6c mov r0, r5 */
/* @0x31ba70 mov r1, r5 */
/* @0x31ba74 add sp, sp, #12 */
/* @0x31ba78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x31ba7c · anon_31ba7c · size=252 · insn=64 */
/* @0x31ba7c ldr r12, [pc, #0x4] */
/* @0x31ba80 add r12, pc, r12 */
/* @0x31ba84 bx r12 */
/* @0x31ba88 .word 0xfff88ce5 */
/* @0x31ba8c ldr r12, [pc, #0x4] */
/* @0x31ba90 add r12, pc, r12 */
/* @0x31ba94 bx r12 */
/* @0x31ba98 .word 0xfff888f1 */
/* @0x31ba9c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31baa0 ldr r12, [pc] */
/* @0x31baa4 add pc, r12, pc */
/* @0x31baa8 .word 0xffd9ac24 */
/* @0x31baac uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bab0 ldr r12, [pc] */
/* @0x31bab4 add pc, r12, pc */
/* @0x31bab8 .word 0xffd9b430 */
/* @0x31babc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bac0 ldr r12, [pc] */
/* @0x31bac4 add pc, r12, pc */
/* @0x31bac8 .word 0xffd9aa90 */
/* @0x31bacc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bad0 ldr r12, [pc] */
/* @0x31bad4 add pc, r12, pc */
/* @0x31bad8 .word 0xffd9aad4 */
/* @0x31badc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bae0 ldr r12, [pc] */
/* @0x31bae4 add pc, r12, pc */
/* @0x31bae8 .word 0xffd9b454 */
/* @0x31baec uxtab16mi r4, r0, r8, ror #8 */
/* @0x31baf0 ldr r12, [pc] */
/* @0x31baf4 add pc, r12, pc */
/* @0x31baf8 .word 0xffd9adb4 */
/* @0x31bafc uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb00 ldr r12, [pc] */
/* @0x31bb04 add pc, r12, pc */
/* @0x31bb08 .word 0xffd9aa38 */
/* @0x31bb0c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb10 ldr r12, [pc] */
/* @0x31bb14 add pc, r12, pc */
/* @0x31bb18 .word 0xffd9aaa0 */
/* @0x31bb1c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb20 ldr r12, [pc] */
/* @0x31bb24 add pc, r12, pc */
/* @0x31bb28 .word 0xffd9adf0 */
/* @0x31bb2c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb30 ldr r12, [pc] */
/* @0x31bb34 add pc, r12, pc */
/* @0x31bb38 .word 0xffd9ad8c */
/* @0x31bb3c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb40 ldr r12, [pc] */
/* @0x31bb44 add pc, r12, pc */
/* @0x31bb48 .word 0xffd9b0dc */
/* @0x31bb4c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb50 ldr r12, [pc] */
/* @0x31bb54 add pc, r12, pc */
/* @0x31bb58 .word 0xffd9ab14 */
/* @0x31bb5c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb60 ldr r12, [pc] */
/* @0x31bb64 add pc, r12, pc */
/* @0x31bb68 .word 0xffd9b164 */
/* @0x31bb6c uxtab16mi r4, r0, r8, ror #8 */
/* @0x31bb70 ldr r12, [pc] */
/* @0x31bb74 add pc, r12, pc */
/* @0x31bb78 .word 0xffd9aa7c */
