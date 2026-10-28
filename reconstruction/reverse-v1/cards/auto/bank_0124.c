/* libyoyo.so 覆盖卡组 0124
 * 函数 0x18b538..0x18c2e0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x18b538 · anon_18b538 · size=136 · insn=35 */
/* @0x18b538 ldr r3, [r0, #0xc] */
/* @0x18b53c push {r4, r5, r6, lr} */
/* @0x18b540 sub r3, r3, #1 */
/* @0x18b544 bic r3, r3, #-16777216 */
/* @0x18b548 sub sp, sp, #48 */
/* @0x18b54c bic r3, r3, #3 */
/* @0x18b550 mov r4, r0 */
/* @0x18b554 cmp r3, #0 */
/* @0x18b558 mov r5, r2 */
/* @0x18b55c bne 0x18b56c <_ZN11CIAPProduct11PopulateMapEi+0x224> */
/* @0x18b560 str r1, [sp, #0xc] */
/* @0x18b564 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x18b568 ldr r1, [sp, #0xc] */
/* @0x18b56c vmov s13, r1 */
/* @0x18b570 mov r3, #5 */
/* @0x18b574 str r3, [r4, #0xc] */
/* @0x18b578 add r6, sp, #48 */
/* @0x18b57c vcvt.f64.s32 d7, s13 */
/* @0x18b580 mov r1, r5 */
/* @0x18b584 add r0, sp, #32 */
/* @0x18b588 mov r5, #0 */
/* @0x18b58c str r5, [r4, #0x8] */
/* @0x18b590 str r5, [r4] */
/* @0x18b594 str r5, [sp, #0x1c] */
/* @0x18b598 vmov r2, r3, d7 */
/* @0x18b59c strd r2, r3, [r6, #-32]! */
/* @0x18b5a0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x18b5a4 mov r1, r5 */
/* @0x18b5a8 str r6, [sp] */
/* @0x18b5ac mov r0, r4 */
/* @0x18b5b0 mov r2, r5 */
/* @0x18b5b4 mov r3, #2 */
/* @0x18b5b8 bl 0x106bcc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_> */
/* @0x18b5bc add sp, sp, #48 */
/* @0x18b5c0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x18b5c4 · CIAPProduct::SetFromMap(int) · size=732 · insn=183 */
/* @0x18b5c4 push {r4, r5, r6, r7, lr} */
/* @0x18b5c8 sub sp, sp, #20 */
/* @0x18b5cc ldr r2, [pc, #0x2ac] */
/* @0x18b5d0 mov r4, r0 */
/* @0x18b5d4 mov r0, sp */
/* @0x18b5d8 mov r3, #0 */
/* @0x18b5dc add r2, pc, r2 */
/* @0x18b5e0 str r3, [sp] */
/* @0x18b5e4 str r3, [sp, #0x4] */
/* @0x18b5e8 mov r6, r1 */
/* @0x18b5ec str r3, [sp, #0x8] */
/* @0x18b5f0 str r3, [sp, #0xc] */
/* @0x18b5f4 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0> */
/* @0x18b5f8 ldr r3, [sp, #0xc] */
/* @0x18b5fc bic r3, r3, #-16777216 */
/* @0x18b600 cmp r3, #1 */
/* @0x18b604 beq 0x18b7d4 <_ZN11CIAPProduct10SetFromMapEi+0x210> */
/* @0x18b608 ldr r2, [pc, #0x274] */
/* @0x18b60c mov r0, sp */
/* @0x18b610 mov r1, r6 */
/* @0x18b614 add r2, pc, r2 */
/* @0x18b618 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0> */
/* @0x18b61c ldr r3, [sp, #0xc] */
/* @0x18b620 bic r3, r3, #-16777216 */
/* @0x18b624 cmp r3, #1 */
/* @0x18b628 beq 0x18b79c <_ZN11CIAPProduct10SetFromMapEi+0x1d8> */
/* @0x18b62c ldr r2, [pc, #0x254] */
/* @0x18b630 mov r0, sp */
/* @0x18b634 mov r1, r6 */
/* @0x18b638 add r2, pc, r2 */
/* @0x18b63c bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0> */
/* @0x18b640 ldr r3, [sp, #0xc] */
/* @0x18b644 bic r3, r3, #-16777216 */
/* @0x18b648 cmp r3, #1 */
/* @0x18b64c beq 0x18b728 <_ZN11CIAPProduct10SetFromMapEi+0x164> */
/* @0x18b650 ldr r2, [pc, #0x234] */
/* @0x18b654 mov r0, sp */
/* @0x18b658 mov r1, r6 */
/* @0x18b65c add r2, pc, r2 */
/* @0x18b660 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0> */
/* @0x18b664 ldr r3, [sp, #0xc] */
/* @0x18b668 cmp r3, #0 */
/* @0x18b66c beq 0x18b6cc <_ZN11CIAPProduct10SetFromMapEi+0x108> */
/* @0x18b670 bic r3, r3, #-16777216 */
/* @0x18b674 cmp r3, #1 */
/* @0x18b678 beq 0x18b848 <_ZN11CIAPProduct10SetFromMapEi+0x284> */
/* @0x18b67c ldr r2, [pc, #0x20c] */
/* @0x18b680 mov r0, sp */
/* @0x18b684 mov r1, r6 */
/* @0x18b688 add r2, pc, r2 */
/* @0x18b68c bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0> */
/* @0x18b690 ldr r3, [sp, #0xc] */
/* @0x18b694 bic r3, r3, #-16777216 */
/* @0x18b698 cmp r3, #1 */
/* @0x18b69c beq 0x18b760 <_ZN11CIAPProduct10SetFromMapEi+0x19c> */
/* @0x18b6a0 ldr r2, [pc, #0x1ec] */
/* @0x18b6a4 mov r0, sp */
/* @0x18b6a8 mov r1, r6 */
/* @0x18b6ac add r2, pc, r2 */
/* @0x18b6b0 bl 0x18b538 <_ZN11CIAPProduct11PopulateMapEi+0x1f0> */
/* @0x18b6b4 ldr r3, [sp, #0xc] */
/* @0x18b6b8 bic r3, r3, #-16777216 */
/* @0x18b6bc cmp r3, #1 */
/* @0x18b6c0 beq 0x18b80c <_ZN11CIAPProduct10SetFromMapEi+0x248> */
/* @0x18b6c4 add sp, sp, #20 */
/* @0x18b6c8 pop {r4, r5, r6, r7, pc} */
/* @0x18b6cc ldr r1, [pc, #0x1c4] */
/* @0x18b6d0 mov r2, #133 */
/* @0x18b6d4 mov r3, #1 */
/* @0x18b6d8 mov r0, #512 */
/* @0x18b6dc add r1, pc, r1 */
/* @0x18b6e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18b6e4 ldr r1, [pc, #0x1b0] */
/* @0x18b6e8 ldrd r2, r3, [sp] */
/* @0x18b6ec add r1, pc, r1 */
/* @0x18b6f0 mov r7, r0 */
/* @0x18b6f4 bl 0xb6550 <sprintf@plt> */
/* @0x18b6f8 ldr r0, [r4, #0xc] */
/* @0x18b6fc cmp r0, #0 */
/* @0x18b700 beq 0x18b708 <_ZN11CIAPProduct10SetFromMapEi+0x144> */
/* @0x18b704 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b708 mov r0, r7 */
/* @0x18b70c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b710 cmp r7, #0 */
/* @0x18b714 str r0, [r4, #0xc] */
/* @0x18b718 beq 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8> */
/* @0x18b71c mov r0, r7 */
/* @0x18b720 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18b724 b 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8> */
/* @0x18b728 ldr r3, [sp] */
/* @0x18b72c cmp r3, #0 */
/* @0x18b730 beq 0x18b650 <_ZN11CIAPProduct10SetFromMapEi+0x8c> */
/* @0x18b734 ldr r7, [r3] */
/* @0x18b738 cmp r7, #0 */
/* @0x18b73c beq 0x18b650 <_ZN11CIAPProduct10SetFromMapEi+0x8c> */
/* @0x18b740 ldr r0, [r4, #0x8] */
/* @0x18b744 cmp r0, #0 */
/* @0x18b748 beq 0x18b750 <_ZN11CIAPProduct10SetFromMapEi+0x18c> */
/* @0x18b74c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b750 mov r0, r7 */
/* @0x18b754 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b758 str r0, [r4, #0x8] */
/* @0x18b75c b 0x18b650 <_ZN11CIAPProduct10SetFromMapEi+0x8c> */
/* @0x18b760 ldr r3, [sp] */
/* @0x18b764 cmp r3, #0 */
/* @0x18b768 beq 0x18b6a0 <_ZN11CIAPProduct10SetFromMapEi+0xdc> */
/* @0x18b76c ldr r7, [r3] */
/* @0x18b770 cmp r7, #0 */
/* @0x18b774 beq 0x18b6a0 <_ZN11CIAPProduct10SetFromMapEi+0xdc> */
/* @0x18b778 ldr r0, [r4, #0x10] */
/* @0x18b77c cmp r0, #0 */
/* @0x18b780 beq 0x18b788 <_ZN11CIAPProduct10SetFromMapEi+0x1c4> */
/* @0x18b784 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b788 mov r0, r7 */
/* @0x18b78c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b790 str r0, [r4, #0x10] */
/* @0x18b794 add sp, sp, #20 */
/* @0x18b798 pop {r4, r5, r6, r7, pc} */
/* @0x18b79c ldr r3, [sp] */
/* @0x18b7a0 cmp r3, #0 */
/* @0x18b7a4 beq 0x18b62c <_ZN11CIAPProduct10SetFromMapEi+0x68> */
/* @0x18b7a8 ldr r7, [r3] */
/* @0x18b7ac cmp r7, #0 */
/* @0x18b7b0 beq 0x18b62c <_ZN11CIAPProduct10SetFromMapEi+0x68> */
/* @0x18b7b4 ldr r0, [r4, #0x4] */
/* @0x18b7b8 cmp r0, #0 */
/* @0x18b7bc beq 0x18b7c4 <_ZN11CIAPProduct10SetFromMapEi+0x200> */
/* @0x18b7c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b7c4 mov r0, r7 */
/* @0x18b7c8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b7cc str r0, [r4, #0x4] */
/* @0x18b7d0 b 0x18b62c <_ZN11CIAPProduct10SetFromMapEi+0x68> */
/* @0x18b7d4 ldr r3, [sp] */
/* @0x18b7d8 cmp r3, #0 */
/* @0x18b7dc beq 0x18b608 <_ZN11CIAPProduct10SetFromMapEi+0x44> */
/* @0x18b7e0 ldr r7, [r3] */
/* @0x18b7e4 cmp r7, #0 */
/* @0x18b7e8 beq 0x18b608 <_ZN11CIAPProduct10SetFromMapEi+0x44> */
/* @0x18b7ec ldr r0, [r4] */
/* @0x18b7f0 cmp r0, #0 */
/* @0x18b7f4 beq 0x18b7fc <_ZN11CIAPProduct10SetFromMapEi+0x238> */
/* @0x18b7f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b7fc mov r0, r7 */
/* @0x18b800 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b804 str r0, [r4] */
/* @0x18b808 b 0x18b608 <_ZN11CIAPProduct10SetFromMapEi+0x44> */
/* @0x18b80c ldr r3, [sp] */
/* @0x18b810 cmp r3, #0 */
/* @0x18b814 beq 0x18b6c4 <_ZN11CIAPProduct10SetFromMapEi+0x100> */
/* @0x18b818 ldr r5, [r3] */
/* @0x18b81c cmp r5, #0 */
/* @0x18b820 beq 0x18b6c4 <_ZN11CIAPProduct10SetFromMapEi+0x100> */
/* @0x18b824 ldr r0, [r4, #0x10] */
/* @0x18b828 cmp r0, #0 */
/* @0x18b82c beq 0x18b834 <_ZN11CIAPProduct10SetFromMapEi+0x270> */
/* @0x18b830 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b834 mov r0, r5 */
/* @0x18b838 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b83c str r0, [r4, #0x10] */
/* @0x18b840 add sp, sp, #20 */
/* @0x18b844 pop {r4, r5, r6, r7, pc} */
/* @0x18b848 ldr r3, [sp] */
/* @0x18b84c cmp r3, #0 */
/* @0x18b850 beq 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8> */
/* @0x18b854 ldr r7, [r3] */
/* @0x18b858 cmp r7, #0 */
/* @0x18b85c beq 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8> */
/* @0x18b860 ldr r0, [r4, #0xc] */
/* @0x18b864 cmp r0, #0 */
/* @0x18b868 beq 0x18b870 <_ZN11CIAPProduct10SetFromMapEi+0x2ac> */
/* @0x18b86c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b870 mov r0, r7 */
/* @0x18b874 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b878 str r0, [r4, #0xc] */
/* @0x18b87c b 0x18b67c <_ZN11CIAPProduct10SetFromMapEi+0xb8> */
/* @0x18b880 andseq r5, r10, r4, ror #8 */
/* @0x18b884 ldrheq lr, [r11], -r8 */
/* @0x18b888 andseq r10, r11, r4, lsl #31 */
/* @0x18b88c mulseq r12, r4, r11 */
/* @0x18b890 andseq r10, r11, r0, lsr #21 */
/* @0x18b894 mulseq r12, r0, r11 */
/* @0x18b898 andseq r0, r12, r8, lsr #22 */
/* @0x18b89c andseq r6, r10, r4, lsl lr */

/* ── FUNC 0x18b8a0 · IO_Quit() · size=76 · insn=19 */
/* @0x18b8a0 push {r4, lr} */
/* @0x18b8a4 bl 0x1909f8 <_Z12GamepadQuitMv> */
/* @0x18b8a8 ldr r3, [pc, #0x34] */
/* @0x18b8ac ldr r3, [pc, r3] */
/* @0x18b8b0 ldr r0, [r3] */
/* @0x18b8b4 cmp r0, #0 */
/* @0x18b8b8 beq 0x18b8c0 <_Z7IO_Quitv+0x20> */
/* @0x18b8bc bl 0xb6850 <fclose@plt> */
/* @0x18b8c0 ldr r4, [pc, #0x20] */
/* @0x18b8c4 ldr r4, [pc, r4] */
/* @0x18b8c8 ldr r0, [r4] */
/* @0x18b8cc cmp r0, #0 */
/* @0x18b8d0 popeq {r4, pc} */
/* @0x18b8d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18b8d8 mov r3, #0 */
/* @0x18b8dc str r3, [r4] */
/* @0x18b8e0 pop {r4, pc} */
/* @0x18b8e4 eoreq r4, r6, r0, lsr #26 */
/* @0x18b8e8 mlaeq r6, r0, r2, r4 */

/* ── FUNC 0x18b8ec · IO_Playback_Update() · size=532 · insn=133 */
/* @0x18b8ec push {r4, r5, r6, lr} */
/* @0x18b8f0 ldr r4, [pc, #0x1bc] */
/* @0x18b8f4 ldr r3, [pc, #0x1bc] */
/* @0x18b8f8 add r4, pc, r4 */
/* @0x18b8fc ldr r5, [r4, r3] */
/* @0x18b900 ldr r0, [r5] */
/* @0x18b904 cmp r0, #0 */
/* @0x18b908 popeq {r4, r5, r6, pc} */
/* @0x18b90c bl 0xb6874 <feof@plt> */
/* @0x18b910 cmp r0, #0 */
/* @0x18b914 popne {r4, r5, r6, pc} */
/* @0x18b918 ldr r0, [pc, #0x19c] */
/* @0x18b91c mov r1, #2 */
/* @0x18b920 ldr r3, [r5] */
/* @0x18b924 mov r2, #1 */
/* @0x18b928 ldr r0, [r4, r0] */
/* @0x18b92c bl 0xb68c8 <fread@plt> */
/* @0x18b930 ldr r0, [pc, #0x188] */
/* @0x18b934 ldr r3, [r5] */
/* @0x18b938 movw r1, #0x802 */
/* @0x18b93c mov r2, #1 */
/* @0x18b940 ldr r0, [r4, r0] */
/* @0x18b944 bl 0xb68c8 <fread@plt> */
/* @0x18b948 ldr r0, [pc, #0x174] */
/* @0x18b94c ldr r3, [r5] */
/* @0x18b950 mov r1, #4 */
/* @0x18b954 mov r2, #1 */
/* @0x18b958 ldr r0, [r4, r0] */
/* @0x18b95c bl 0xb68c8 <fread@plt> */
/* @0x18b960 ldr r0, [pc, #0x160] */
/* @0x18b964 ldr r3, [r5] */
/* @0x18b968 mov r1, #4 */
/* @0x18b96c mov r2, #1 */
/* @0x18b970 ldr r0, [r4, r0] */
/* @0x18b974 bl 0xb68c8 <fread@plt> */
/* @0x18b978 ldr r0, [pc, #0x14c] */
/* @0x18b97c ldr r3, [r5] */
/* @0x18b980 mov r1, #256 */
/* @0x18b984 mov r2, #1 */
/* @0x18b988 ldr r0, [r4, r0] */
/* @0x18b98c bl 0xb68c8 <fread@plt> */
/* @0x18b990 ldr r0, [pc, #0x138] */
/* @0x18b994 ldr r3, [r5] */
/* @0x18b998 mov r1, #256 */
/* @0x18b99c mov r2, #1 */
/* @0x18b9a0 ldr r0, [r4, r0] */
/* @0x18b9a4 bl 0xb68c8 <fread@plt> */
/* @0x18b9a8 ldr r0, [pc, #0x124] */
/* @0x18b9ac ldr r3, [r5] */
/* @0x18b9b0 mov r1, #256 */
/* @0x18b9b4 mov r2, #1 */
/* @0x18b9b8 ldr r0, [r4, r0] */
/* @0x18b9bc bl 0xb68c8 <fread@plt> */
/* @0x18b9c0 ldr r0, [pc, #0x110] */
/* @0x18b9c4 ldr r3, [r5] */
/* @0x18b9c8 mov r1, #40 */
/* @0x18b9cc mov r2, #1 */
/* @0x18b9d0 ldr r0, [r4, r0] */
/* @0x18b9d4 bl 0xb68c8 <fread@plt> */
/* @0x18b9d8 ldr r0, [pc, #0xfc] */
/* @0x18b9dc ldr r3, [r5] */
/* @0x18b9e0 mov r1, #40 */
/* @0x18b9e4 mov r2, #1 */
/* @0x18b9e8 ldr r0, [r4, r0] */
/* @0x18b9ec bl 0xb68c8 <fread@plt> */
/* @0x18b9f0 ldr r0, [pc, #0xe8] */
/* @0x18b9f4 ldr r3, [r5] */
/* @0x18b9f8 mov r1, #30 */
/* @0x18b9fc mov r2, #1 */
/* @0x18ba00 ldr r0, [r4, r0] */
/* @0x18ba04 bl 0xb68c8 <fread@plt> */
/* @0x18ba08 ldr r0, [pc, #0xd4] */
/* @0x18ba0c ldr r3, [r5] */
/* @0x18ba10 mov r1, #30 */
/* @0x18ba14 mov r2, #1 */
/* @0x18ba18 ldr r0, [r4, r0] */
/* @0x18ba1c bl 0xb68c8 <fread@plt> */
/* @0x18ba20 ldr r0, [pc, #0xc0] */
/* @0x18ba24 ldr r3, [r5] */
/* @0x18ba28 mov r1, #30 */
/* @0x18ba2c mov r2, #1 */
/* @0x18ba30 ldr r0, [r4, r0] */
/* @0x18ba34 bl 0xb68c8 <fread@plt> */
/* @0x18ba38 ldr r0, [pc, #0xac] */
/* @0x18ba3c ldr r3, [r5] */
/* @0x18ba40 mov r1, #10 */
/* @0x18ba44 mov r2, #1 */
/* @0x18ba48 ldr r0, [r4, r0] */
/* @0x18ba4c bl 0xb68c8 <fread@plt> */
/* @0x18ba50 ldr r0, [pc, #0x98] */
/* @0x18ba54 ldr r3, [r5] */
/* @0x18ba58 mov r1, #10 */
/* @0x18ba5c mov r2, #1 */
/* @0x18ba60 ldr r0, [r4, r0] */
/* @0x18ba64 bl 0xb68c8 <fread@plt> */
/* @0x18ba68 ldr r0, [pc, #0x84] */
/* @0x18ba6c ldr r3, [r5] */
/* @0x18ba70 mov r1, #8 */
/* @0x18ba74 mov r2, #1 */
/* @0x18ba78 ldr r0, [r4, r0] */
/* @0x18ba7c bl 0xb68c8 <fread@plt> */
/* @0x18ba80 ldr r0, [pc, #0x70] */
/* @0x18ba84 ldr r3, [r5] */
/* @0x18ba88 mov r1, #4 */
/* @0x18ba8c mov r2, #1 */
/* @0x18ba90 ldr r0, [r4, r0] */
/* @0x18ba94 bl 0xb68c8 <fread@plt> */
/* @0x18ba98 ldr r0, [pc, #0x5c] */
/* @0x18ba9c ldr r3, [r5] */
/* @0x18baa0 mov r1, #4 */
/* @0x18baa4 mov r2, #1 */
/* @0x18baa8 ldr r0, [r4, r0] */
/* @0x18baac pop {r4, r5, r6, lr} */
/* @0x18bab0 b 0xb68c8 <fread@plt> */
/* @0x18bab4 eoreq r6, r6, r8, asr r3 */
/* @0x18bab8 .word 0xffffe97c */
/* @0x18babc .word 0xffffe980 */
/* @0x18bac0 .word 0xffffe984 */
/* @0x18bac4 .word 0xffffe988 */
/* @0x18bac8 .word 0xffffe98c */
/* @0x18bacc .word 0xffffe990 */
/* @0x18bad0 .word 0xffffe994 */
/* @0x18bad4 .word 0xffffe998 */
/* @0x18bad8 .word 0xffffe99c */
/* @0x18badc .word 0xffffe9a0 */
/* @0x18bae0 .word 0xffffe9a4 */
/* @0x18bae4 .word 0xffffe9a8 */
/* @0x18bae8 .word 0xffffe9ac */
/* @0x18baec .word 0xffffe9b0 */
/* @0x18baf0 .word 0xffffe9b4 */
/* @0x18baf4 .word 0xffffe9b8 */
/* @0x18baf8 .word 0xffffe720 */
/* @0x18bafc .word 0xffffe724 */

/* ── FUNC 0x18bb00 · IO_Record() · size=524 · insn=131 */
/* @0x18bb00 push {r3, r4, r5, lr} */
/* @0x18bb04 ldr r4, [pc, #0x1b4] */
/* @0x18bb08 ldr r3, [pc, #0x1b4] */
/* @0x18bb0c add r4, pc, r4 */
/* @0x18bb10 ldr r5, [r4, r3] */
/* @0x18bb14 ldr r3, [r5] */
/* @0x18bb18 cmp r3, #0 */
/* @0x18bb1c popeq {r3, r4, r5, pc} */
/* @0x18bb20 ldr r0, [pc, #0x1a0] */
/* @0x18bb24 mov r1, #2 */
/* @0x18bb28 mov r2, #1 */
/* @0x18bb2c ldr r0, [r4, r0] */
/* @0x18bb30 bl 0xb68bc <fwrite@plt> */
/* @0x18bb34 ldr r0, [pc, #0x190] */
/* @0x18bb38 ldr r3, [r5] */
/* @0x18bb3c movw r1, #0x802 */
/* @0x18bb40 mov r2, #1 */
/* @0x18bb44 ldr r0, [r4, r0] */
/* @0x18bb48 bl 0xb68bc <fwrite@plt> */
/* @0x18bb4c ldr r0, [pc, #0x17c] */
/* @0x18bb50 ldr r3, [r5] */
/* @0x18bb54 mov r1, #4 */
/* @0x18bb58 mov r2, #1 */
/* @0x18bb5c ldr r0, [r4, r0] */
/* @0x18bb60 bl 0xb68bc <fwrite@plt> */
/* @0x18bb64 ldr r0, [pc, #0x168] */
/* @0x18bb68 ldr r3, [r5] */
/* @0x18bb6c mov r1, #4 */
/* @0x18bb70 mov r2, #1 */
/* @0x18bb74 ldr r0, [r4, r0] */
/* @0x18bb78 bl 0xb68bc <fwrite@plt> */
/* @0x18bb7c ldr r0, [pc, #0x154] */
/* @0x18bb80 ldr r3, [r5] */
/* @0x18bb84 mov r1, #256 */
/* @0x18bb88 mov r2, #1 */
/* @0x18bb8c ldr r0, [r4, r0] */
/* @0x18bb90 bl 0xb68bc <fwrite@plt> */
/* @0x18bb94 ldr r0, [pc, #0x140] */
/* @0x18bb98 ldr r3, [r5] */
/* @0x18bb9c mov r1, #256 */
/* @0x18bba0 mov r2, #1 */
/* @0x18bba4 ldr r0, [r4, r0] */
/* @0x18bba8 bl 0xb68bc <fwrite@plt> */
/* @0x18bbac ldr r0, [pc, #0x12c] */
/* @0x18bbb0 ldr r3, [r5] */
/* @0x18bbb4 mov r1, #256 */
/* @0x18bbb8 mov r2, #1 */
/* @0x18bbbc ldr r0, [r4, r0] */
/* @0x18bbc0 bl 0xb68bc <fwrite@plt> */
/* @0x18bbc4 ldr r0, [pc, #0x118] */
/* @0x18bbc8 ldr r3, [r5] */
/* @0x18bbcc mov r1, #40 */
/* @0x18bbd0 mov r2, #1 */
/* @0x18bbd4 ldr r0, [r4, r0] */
/* @0x18bbd8 bl 0xb68bc <fwrite@plt> */
/* @0x18bbdc ldr r0, [pc, #0x104] */
/* @0x18bbe0 ldr r3, [r5] */
/* @0x18bbe4 mov r1, #40 */
/* @0x18bbe8 mov r2, #1 */
/* @0x18bbec ldr r0, [r4, r0] */
/* @0x18bbf0 bl 0xb68bc <fwrite@plt> */
/* @0x18bbf4 ldr r0, [pc, #0xf0] */
/* @0x18bbf8 ldr r3, [r5] */
/* @0x18bbfc mov r1, #30 */
/* @0x18bc00 mov r2, #1 */
/* @0x18bc04 ldr r0, [r4, r0] */
/* @0x18bc08 bl 0xb68bc <fwrite@plt> */
/* @0x18bc0c ldr r0, [pc, #0xdc] */
/* @0x18bc10 ldr r3, [r5] */
/* @0x18bc14 mov r1, #30 */
/* @0x18bc18 mov r2, #1 */
/* @0x18bc1c ldr r0, [r4, r0] */
/* @0x18bc20 bl 0xb68bc <fwrite@plt> */
/* @0x18bc24 ldr r0, [pc, #0xc8] */
/* @0x18bc28 ldr r3, [r5] */
/* @0x18bc2c mov r1, #30 */
/* @0x18bc30 mov r2, #1 */
/* @0x18bc34 ldr r0, [r4, r0] */
/* @0x18bc38 bl 0xb68bc <fwrite@plt> */
/* @0x18bc3c ldr r0, [pc, #0xb4] */
/* @0x18bc40 ldr r3, [r5] */
/* @0x18bc44 mov r1, #10 */
/* @0x18bc48 mov r2, #1 */
/* @0x18bc4c ldr r0, [r4, r0] */
/* @0x18bc50 bl 0xb68bc <fwrite@plt> */
/* @0x18bc54 ldr r0, [pc, #0xa0] */
/* @0x18bc58 ldr r3, [r5] */
/* @0x18bc5c mov r1, #10 */
/* @0x18bc60 mov r2, #1 */
/* @0x18bc64 ldr r0, [r4, r0] */
/* @0x18bc68 bl 0xb68bc <fwrite@plt> */
/* @0x18bc6c ldr r0, [pc, #0x8c] */
/* @0x18bc70 ldr r3, [r5] */
/* @0x18bc74 mov r1, #8 */
/* @0x18bc78 mov r2, #1 */
/* @0x18bc7c ldr r0, [r4, r0] */
/* @0x18bc80 bl 0xb68bc <fwrite@plt> */
/* @0x18bc84 ldr r0, [pc, #0x78] */
/* @0x18bc88 ldr r3, [r5] */
/* @0x18bc8c mov r1, #4 */
/* @0x18bc90 mov r2, #1 */
/* @0x18bc94 ldr r0, [r4, r0] */
/* @0x18bc98 bl 0xb68bc <fwrite@plt> */
/* @0x18bc9c ldr r0, [pc, #0x64] */
/* @0x18bca0 ldr r3, [r5] */
/* @0x18bca4 mov r1, #4 */
/* @0x18bca8 mov r2, #1 */
/* @0x18bcac ldr r0, [r4, r0] */
/* @0x18bcb0 bl 0xb68bc <fwrite@plt> */
/* @0x18bcb4 ldr r0, [r5] */
/* @0x18bcb8 pop {r3, r4, r5, lr} */
/* @0x18bcbc b 0xb691c <fflush@plt> */
/* @0x18bcc0 eoreq r6, r6, r4, asr #2 */
/* @0x18bcc4 .word 0xffffe97c */
/* @0x18bcc8 .word 0xffffe980 */
/* @0x18bccc .word 0xffffe984 */
/* @0x18bcd0 .word 0xffffe988 */
/* @0x18bcd4 .word 0xffffe98c */
/* @0x18bcd8 .word 0xffffe990 */
/* @0x18bcdc .word 0xffffe994 */
/* @0x18bce0 .word 0xffffe998 */
/* @0x18bce4 .word 0xffffe99c */
/* @0x18bce8 .word 0xffffe9a0 */
/* @0x18bcec .word 0xffffe9a4 */
/* @0x18bcf0 .word 0xffffe9a8 */
/* @0x18bcf4 .word 0xffffe9ac */
/* @0x18bcf8 .word 0xffffe9b0 */
/* @0x18bcfc .word 0xffffe9b4 */
/* @0x18bd00 .word 0xffffe9b8 */
/* @0x18bd04 .word 0xffffe720 */
/* @0x18bd08 .word 0xffffe724 */

/* ── FUNC 0x18bd0c · IO_Char_Last_Get() · size=20 · insn=5 */
/* @0x18bd0c ldr r3, [pc, #0x8] */
/* @0x18bd10 ldr r3, [pc, r3] */
/* @0x18bd14 ldrh r0, [r3] */
/* @0x18bd18 bx lr */
/* @0x18bd1c eoreq r4, r6, r0, asr #17 */

/* ── FUNC 0x18bd20 · IO_Char_Last_Set(char) · size=20 · insn=5 */
/* @0x18bd20 ldr r3, [pc, #0x8] */
/* @0x18bd24 ldr r3, [pc, r3] */
/* @0x18bd28 strh r0, [r3] */
/* @0x18bd2c bx lr */
/* @0x18bd30 eoreq r4, r6, r12, lsr #17 */

/* ── FUNC 0x18bd34 · IO_String_Get() · size=128 · insn=32 */
/* @0x18bd34 push {r4, r5, r6, r7, lr} */
/* @0x18bd38 sub sp, sp, #12 */
/* @0x18bd3c ldr r5, [pc, #0x64] */
/* @0x18bd40 ldr r5, [pc, r5] */
/* @0x18bd44 mov r0, r5 */
/* @0x18bd48 bl 0xf6c78 <_Z8yywcslenPKt> */
/* @0x18bd4c ldr r3, [pc, #0x58] */
/* @0x18bd50 add r3, pc, r3 */
/* @0x18bd54 str r3, [sp, #0x4] */
/* @0x18bd58 subs r7, r0, #0 */
/* @0x18bd5c subne r5, r5, #2 */
/* @0x18bd60 addne r6, sp, #4 */
/* @0x18bd64 movne r4, #0 */
/* @0x18bd68 beq 0x18bda0 <_Z13IO_String_Getv+0x6c> */
/* @0x18bd6c add r4, r4, #1 */
/* @0x18bd70 mov r0, r6 */
/* @0x18bd74 ldrh r1, [r5, #2]! */
/* @0x18bd78 bl 0x10fe28 <utf8_add_char> */
/* @0x18bd7c cmp r4, r7 */
/* @0x18bd80 bne 0x18bd6c <_Z13IO_String_Getv+0x38> */
/* @0x18bd84 mov r0, r6 */
/* @0x18bd88 mov r1, #0 */
/* @0x18bd8c bl 0x10fe28 <utf8_add_char> */
/* @0x18bd90 ldr r0, [pc, #0x18] */
/* @0x18bd94 add r0, pc, r0 */
/* @0x18bd98 add sp, sp, #12 */
/* @0x18bd9c pop {r4, r5, r6, r7, pc} */
/* @0x18bda0 add r6, sp, #4 */
/* @0x18bda4 b 0x18bd84 <_Z13IO_String_Getv+0x50> */
/* @0x18bda8 mlaeq r6, r4, r8, r4 */
/* @0x18bdac eorseq r7, r10, r8, ror r2 */
/* @0x18bdb0 eorseq r7, r10, r4, lsr r2 */

/* ── FUNC 0x18bdb4 · IO_String_Set(char const*) · size=172 · insn=43 */
/* @0x18bdb4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18bdb8 subs r4, r0, #0 */
/* @0x18bdbc ldr r8, [pc, #0x90] */
/* @0x18bdc0 sub sp, sp, #12 */
/* @0x18bdc4 add r8, pc, r8 */
/* @0x18bdc8 beq 0x18be34 <_Z13IO_String_SetPKc+0x80> */
/* @0x18bdcc bl 0x110648 <utf8_strlen> */
/* @0x18bdd0 ldr r3, [pc, #0x80] */
/* @0x18bdd4 subs r6, r0, #0 */
/* @0x18bdd8 ldrle r9, [r8, r3] */
/* @0x18bddc ble 0x18be14 <_Z13IO_String_SetPKc+0x60> */
/* @0x18bde0 add r7, sp, #8 */
/* @0x18bde4 cmp r6, #1024 */
/* @0x18bde8 movge r6, #1024 */
/* @0x18bdec str r4, [r7, #-0x4]! */
/* @0x18bdf0 mov r4, #0 */
/* @0x18bdf4 ldr r9, [r8, r3] */
/* @0x18bdf8 sub r5, r9, #2 */
/* @0x18bdfc mov r0, r7 */
/* @0x18be00 add r4, r4, #1 */
/* @0x18be04 bl 0x10fb38 <utf8_extract_char> */
/* @0x18be08 cmp r6, r4 */
/* @0x18be0c strh r0, [r5, #2]! */
/* @0x18be10 bgt 0x18bdfc <_Z13IO_String_SetPKc+0x48> */
/* @0x18be14 ldr r3, [pc, #0x40] */
/* @0x18be18 lsl r2, r6, #1 */
/* @0x18be1c mov r1, #0 */
/* @0x18be20 strh r1, [r9, r2] */
/* @0x18be24 ldr r3, [r8, r3] */
/* @0x18be28 str r6, [r3] */
/* @0x18be2c add sp, sp, #12 */
/* @0x18be30 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18be34 ldr r2, [pc, #0x1c] */
/* @0x18be38 ldr r3, [pc, #0x1c] */
/* @0x18be3c ldr r2, [r8, r2] */
/* @0x18be40 strh r4, [r2] */
/* @0x18be44 ldr r3, [r8, r3] */
/* @0x18be48 str r4, [r3] */
/* @0x18be4c add sp, sp, #12 */
/* @0x18be50 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18be54 eoreq r5, r6, r12, lsl #29 */
/* @0x18be58 .word 0xffffe984 */
/* @0x18be5c .word 0xffffe9bc */

/* ── FUNC 0x18be60 · IO_String_Clear() · size=52 · insn=13 */
/* @0x18be60 ldr r0, [pc, #0x24] */
/* @0x18be64 movw r2, #0x401 */
/* @0x18be68 push {r3, lr} */
/* @0x18be6c mov r1, #0 */
/* @0x18be70 ldr r0, [pc, r0] */
/* @0x18be74 bl 0xb65b0 <memset@plt> */
/* @0x18be78 ldr r3, [pc, #0x10] */
/* @0x18be7c mov r2, #0 */
/* @0x18be80 ldr r3, [pc, r3] */
/* @0x18be84 str r2, [r3] */
/* @0x18be88 pop {r3, pc} */
/* @0x18be8c eoreq r4, r6, r4, ror #14 */
/* @0x18be90 eoreq r4, r6, r12, lsl #15 */

/* ── FUNC 0x18be94 · IO_Key_Last_Get() · size=20 · insn=5 */
/* @0x18be94 ldr r3, [pc, #0x8] */
/* @0x18be98 ldr r3, [pc, r3] */
/* @0x18be9c ldr r0, [r3] */
/* @0x18bea0 bx lr */
/* @0x18bea4 eoreq r4, r6, r0, asr #14 */

/* ── FUNC 0x18bea8 · IO_Key_Current_Get() · size=20 · insn=5 */
/* @0x18bea8 ldr r3, [pc, #0x8] */
/* @0x18beac ldr r3, [pc, r3] */
/* @0x18beb0 ldr r0, [r3] */
/* @0x18beb4 bx lr */
/* @0x18beb8 eoreq r4, r6, r0, lsr r7 */

/* ── FUNC 0x18bebc · IO_Key_Last_Set(int) · size=20 · insn=5 */
/* @0x18bebc ldr r3, [pc, #0x8] */
/* @0x18bec0 ldr r3, [pc, r3] */
/* @0x18bec4 str r0, [r3] */
/* @0x18bec8 bx lr */
/* @0x18becc eoreq r4, r6, r8, lsl r7 */

/* ── FUNC 0x18bed0 · IO_Key_Current_Set(int) · size=24 · insn=6 */
/* @0x18bed0 cmp r0, #255 */
/* @0x18bed4 ldrls r3, [pc, #0x8] */
/* @0x18bed8 ldrls r3, [pc, r3] */
/* @0x18bedc strls r0, [r3] */
/* @0x18bee0 bx lr */
/* @0x18bee4 eoreq r4, r6, r4, lsl #14 */

/* ── FUNC 0x18bee8 · IO_Key_Down(int) · size=36 · insn=9 */
/* @0x18bee8 cmp r0, #255 */
/* @0x18beec bhi 0x18bf00 <_Z11IO_Key_Downi+0x18> */
/* @0x18bef0 ldr r3, [pc, #0x10] */
/* @0x18bef4 ldr r3, [pc, r3] */
/* @0x18bef8 ldrb r0, [r3, r0] */
/* @0x18befc bx lr */
/* @0x18bf00 mov r0, #0 */
/* @0x18bf04 bx lr */
/* @0x18bf08 eoreq r4, r6, r12, ror #13 */

/* ── FUNC 0x18bf0c · IO_Key_Pressed(int) · size=36 · insn=9 */
/* @0x18bf0c cmp r0, #255 */
/* @0x18bf10 bhi 0x18bf24 <_Z14IO_Key_Pressedi+0x18> */
/* @0x18bf14 ldr r3, [pc, #0x10] */
/* @0x18bf18 ldr r3, [pc, r3] */
/* @0x18bf1c ldrb r0, [r3, r0] */
/* @0x18bf20 bx lr */
/* @0x18bf24 mov r0, #0 */
/* @0x18bf28 bx lr */
/* @0x18bf2c .word 0x002646d0 */

/* ── FUNC 0x18bf30 · IO_Key_Released(int) · size=36 · insn=9 */
/* @0x18bf30 cmp r0, #255 */
/* @0x18bf34 bhi 0x18bf48 <_Z15IO_Key_Releasedi+0x18> */
/* @0x18bf38 ldr r3, [pc, #0x10] */
/* @0x18bf3c ldr r3, [pc, r3] */
/* @0x18bf40 ldrb r0, [r3, r0] */
/* @0x18bf44 bx lr */
/* @0x18bf48 mov r0, #0 */
/* @0x18bf4c bx lr */
/* @0x18bf50 eoreq r4, r6, r8, lsr #13 */

/* ── FUNC 0x18bf54 · IO_Key_Clear(int) · size=64 · insn=16 */
/* @0x18bf54 cmp r0, #255 */
/* @0x18bf58 bxhi lr */
/* @0x18bf5c ldr r12, [pc, #0x24] */
/* @0x18bf60 mov r2, #0 */
/* @0x18bf64 ldr r1, [pc, #0x20] */
/* @0x18bf68 ldr r3, [pc, #0x20] */
/* @0x18bf6c ldr r12, [pc, r12] */
/* @0x18bf70 ldr r1, [pc, r1] */
/* @0x18bf74 ldr r3, [pc, r3] */
/* @0x18bf78 strb r2, [r12, r0] */
/* @0x18bf7c strb r2, [r1, r0] */
/* @0x18bf80 strb r2, [r3, r0] */
/* @0x18bf84 bx lr */
/* @0x18bf88 eoreq r4, r6, r4, ror r6 */
/* @0x18bf8c eoreq r4, r6, r8, ror r6 */
/* @0x18bf90 eoreq r4, r6, r0, ror r6 */

/* ── FUNC 0x18bf94 · IO_Key_Clear_All() · size=144 · insn=36 */
/* @0x18bf94 ldr r1, [pc, #0x6c] */
/* @0x18bf98 mov r0, #0 */
/* @0x18bf9c ldr r12, [pc, #0x68] */
/* @0x18bfa0 mov r3, r0 */
/* @0x18bfa4 add r1, pc, r1 */
/* @0x18bfa8 mov r2, r0 */
/* @0x18bfac push {r4, r5, r6, r7} */
/* @0x18bfb0 ldr r7, [r1, r12] */
/* @0x18bfb4 ldr r4, [pc, #0x54] */
/* @0x18bfb8 ldr r6, [pc, #0x54] */
/* @0x18bfbc str r0, [r7] */
/* @0x18bfc0 ldr r7, [r1, r4] */
/* @0x18bfc4 ldr r12, [pc, #0x4c] */
/* @0x18bfc8 ldr r5, [pc, #0x4c] */
/* @0x18bfcc str r0, [r7] */
/* @0x18bfd0 ldr r4, [pc, #0x48] */
/* @0x18bfd4 ldr r6, [r1, r6] */
/* @0x18bfd8 strh r0, [r6] */
/* @0x18bfdc ldr r12, [r1, r12] */
/* @0x18bfe0 ldr r0, [r1, r5] */
/* @0x18bfe4 ldr r1, [r1, r4] */
/* @0x18bfe8 strb r2, [r12, r3] */
/* @0x18bfec strb r2, [r0, r3] */
/* @0x18bff0 strb r2, [r1, r3] */
/* @0x18bff4 add r3, r3, #1 */
/* @0x18bff8 cmp r3, #256 */
/* @0x18bffc bne 0x18bfe8 <_Z16IO_Key_Clear_Allv+0x54> */
/* @0x18c000 pop {r4, r5, r6, r7} */
/* @0x18c004 bx lr */
/* @0x18c008 eoreq r5, r6, r12, lsr #25 */
/* @0x18c00c .word 0xffffe988 */
/* @0x18c010 .word 0xffffe98c */
/* @0x18c014 .word 0xffffe980 */
/* @0x18c018 .word 0xffffe990 */
/* @0x18c01c .word 0xffffe998 */
/* @0x18c020 .word 0xffffe994 */

/* ── FUNC 0x18c024 · IO_Button_Last_Get(int) · size=36 · insn=9 */
/* @0x18c024 cmp r0, #9 */
/* @0x18c028 bhi 0x18c03c <_Z18IO_Button_Last_Geti+0x18> */
/* @0x18c02c ldr r3, [pc, #0x10] */
/* @0x18c030 ldr r3, [pc, r3] */
/* @0x18c034 ldr r0, [r3, r0, lsl #2] */
/* @0x18c038 bx lr */
/* @0x18c03c mov r0, #0 */
/* @0x18c040 bx lr */
/* @0x18c044 .word 0x002645bc */

/* ── FUNC 0x18c048 · IO_Button_Current_Get(int) · size=36 · insn=9 */
/* @0x18c048 cmp r0, #9 */
/* @0x18c04c bhi 0x18c060 <_Z21IO_Button_Current_Geti+0x18> */
/* @0x18c050 ldr r3, [pc, #0x10] */
/* @0x18c054 ldr r3, [pc, r3] */
/* @0x18c058 ldr r0, [r3, r0, lsl #2] */
/* @0x18c05c bx lr */
/* @0x18c060 mov r0, #0 */
/* @0x18c064 bx lr */
/* @0x18c068 mlaeq r6, r12, r5, r4 */

/* ── FUNC 0x18c06c · IO_Button_Last_Set(int, int) · size=36 · insn=9 */
/* @0x18c06c sub r3, r0, #1 */
/* @0x18c070 cmp r3, #2 */
/* @0x18c074 bxhi lr */
/* @0x18c078 cmp r1, #9 */
/* @0x18c07c ldrls r3, [pc, #0x8] */
/* @0x18c080 ldrls r3, [pc, r3] */
/* @0x18c084 strls r0, [r3, r1, lsl #2] */
/* @0x18c088 bx lr */
/* @0x18c08c eoreq r4, r6, r12, ror #10 */

/* ── FUNC 0x18c090 · IO_Button_Current_Set(int, int) · size=36 · insn=9 */
/* @0x18c090 sub r3, r0, #1 */
/* @0x18c094 cmp r3, #2 */
/* @0x18c098 bxhi lr */
/* @0x18c09c cmp r1, #9 */
/* @0x18c0a0 ldrls r3, [pc, #0x8] */
/* @0x18c0a4 ldrls r3, [pc, r3] */
/* @0x18c0a8 strls r0, [r3, r1, lsl #2] */
/* @0x18c0ac bx lr */
/* @0x18c0b0 eoreq r4, r6, r12, asr #10 */

/* ── FUNC 0x18c0b4 · IO_Button_Down(int, int) · size=60 · insn=15 */
/* @0x18c0b4 sub r3, r0, #1 */
/* @0x18c0b8 cmp r3, #2 */
/* @0x18c0bc bhi 0x18c0e4 <_Z14IO_Button_Downii+0x30> */
/* @0x18c0c0 cmp r1, #9 */
/* @0x18c0c4 bhi 0x18c0e4 <_Z14IO_Button_Downii+0x30> */
/* @0x18c0c8 ldr r3, [pc, #0x1c] */
/* @0x18c0cc add r1, r1, r1, lsl #1 */
/* @0x18c0d0 ldr r3, [pc, r3] */
/* @0x18c0d4 add r3, r3, r1 */
/* @0x18c0d8 add r0, r3, r0 */
/* @0x18c0dc ldrb r0, [r0, #-0x1] */
/* @0x18c0e0 bx lr */
/* @0x18c0e4 mov r0, #0 */
/* @0x18c0e8 bx lr */
/* @0x18c0ec eoreq r4, r6, r4, lsr #10 */

/* ── FUNC 0x18c0f0 · IO_Button_Pressed(int, int) · size=60 · insn=15 */
/* @0x18c0f0 sub r3, r0, #1 */
/* @0x18c0f4 cmp r3, #2 */
/* @0x18c0f8 bhi 0x18c120 <_Z17IO_Button_Pressedii+0x30> */
/* @0x18c0fc cmp r1, #9 */
/* @0x18c100 bhi 0x18c120 <_Z17IO_Button_Pressedii+0x30> */
/* @0x18c104 ldr r3, [pc, #0x1c] */
/* @0x18c108 add r1, r1, r1, lsl #1 */
/* @0x18c10c ldr r3, [pc, r3] */
/* @0x18c110 add r3, r3, r1 */
/* @0x18c114 add r0, r3, r0 */
/* @0x18c118 ldrb r0, [r0, #-0x1] */
/* @0x18c11c bx lr */
/* @0x18c120 mov r0, #0 */
/* @0x18c124 bx lr */
/* @0x18c128 .word 0x002644f0 */

/* ── FUNC 0x18c12c · IO_Button_Released(int, int) · size=60 · insn=15 */
/* @0x18c12c sub r3, r0, #1 */
/* @0x18c130 cmp r3, #2 */
/* @0x18c134 bhi 0x18c15c <_Z18IO_Button_Releasedii+0x30> */
/* @0x18c138 cmp r1, #9 */
/* @0x18c13c bhi 0x18c15c <_Z18IO_Button_Releasedii+0x30> */
/* @0x18c140 ldr r3, [pc, #0x1c] */
/* @0x18c144 add r1, r1, r1, lsl #1 */
/* @0x18c148 ldr r3, [pc, r3] */
/* @0x18c14c add r3, r3, r1 */
/* @0x18c150 add r0, r3, r0 */
/* @0x18c154 ldrb r0, [r0, #-0x1] */
/* @0x18c158 bx lr */
/* @0x18c15c mov r0, #0 */
/* @0x18c160 bx lr */
/* @0x18c164 .word 0x002644b0 */

/* ── FUNC 0x18c168 · IO_Wheel_Up(int) · size=36 · insn=9 */
/* @0x18c168 cmp r0, #9 */
/* @0x18c16c bhi 0x18c180 <_Z11IO_Wheel_Upi+0x18> */
/* @0x18c170 ldr r3, [pc, #0x10] */
/* @0x18c174 ldr r3, [pc, r3] */
/* @0x18c178 ldrb r0, [r3, r0] */
/* @0x18c17c bx lr */
/* @0x18c180 mov r0, #0 */
/* @0x18c184 bx lr */
/* @0x18c188 eoreq r4, r6, r12, lsl #9 */

/* ── FUNC 0x18c18c · IO_Wheel_Down(int) · size=36 · insn=9 */
/* @0x18c18c cmp r0, #9 */
/* @0x18c190 bhi 0x18c1a4 <_Z13IO_Wheel_Downi+0x18> */
/* @0x18c194 ldr r3, [pc, #0x10] */
/* @0x18c198 ldr r3, [pc, r3] */
/* @0x18c19c ldrb r0, [r3, r0] */
/* @0x18c1a0 bx lr */
/* @0x18c1a4 mov r0, #0 */
/* @0x18c1a8 bx lr */
/* @0x18c1ac eoreq r4, r6, r12, ror #8 */

/* ── FUNC 0x18c1b0 · IO_Button_Clear(int, int) · size=92 · insn=23 */
/* @0x18c1b0 sub r0, r0, #1 */
/* @0x18c1b4 cmp r0, #2 */
/* @0x18c1b8 str r4, [sp, #-0x4]! */
/* @0x18c1bc bhi 0x18c1f8 <_Z15IO_Button_Clearii+0x48> */
/* @0x18c1c0 cmp r1, #9 */
/* @0x18c1c4 bhi 0x18c1f8 <_Z15IO_Button_Clearii+0x48> */
/* @0x18c1c8 ldr r4, [pc, #0x30] */
/* @0x18c1cc add r1, r1, r1, lsl #1 */
/* @0x18c1d0 ldr r12, [pc, #0x2c] */
/* @0x18c1d4 add r0, r1, r0 */
/* @0x18c1d8 ldr r3, [pc, #0x28] */
/* @0x18c1dc ldr r4, [pc, r4] */
/* @0x18c1e0 ldr r12, [pc, r12] */
/* @0x18c1e4 mov r2, #0 */
/* @0x18c1e8 ldr r3, [pc, r3] */
/* @0x18c1ec strb r2, [r4, r0] */
/* @0x18c1f0 strb r2, [r12, r0] */
/* @0x18c1f4 strb r2, [r3, r0] */
/* @0x18c1f8 ldr r4, [sp], #4 */
/* @0x18c1fc bx lr */
/* @0x18c200 eoreq r4, r6, r8, lsl r4 */
/* @0x18c204 eoreq r4, r6, r12, lsl r4 */
/* @0x18c208 eoreq r4, r6, r0, lsl r4 */

/* ── FUNC 0x18c20c · IO_Button_Clear_All(int) · size=188 · insn=47 */
/* @0x18c20c cmp r0, #9 */
/* @0x18c210 ldr r2, [pc, #0x90] */
/* @0x18c214 push {r4, r5, r6, r7, r8} */
/* @0x18c218 add r2, pc, r2 */
/* @0x18c21c bhi 0x18c2a0 <_Z19IO_Button_Clear_Alli+0x94> */
/* @0x18c220 ldr r5, [pc, #0x84] */
/* @0x18c224 mov r3, #0 */
/* @0x18c228 ldr r4, [pc, #0x80] */
/* @0x18c22c add r1, r0, r0, lsl #1 */
/* @0x18c230 ldr r12, [pc, #0x7c] */
/* @0x18c234 ldr r7, [r2, r5] */
/* @0x18c238 ldr r6, [pc, #0x78] */
/* @0x18c23c ldr r5, [pc, #0x78] */
/* @0x18c240 str r3, [r7, r0, lsl #2] */
/* @0x18c244 ldr r4, [r2, r4] */
/* @0x18c248 ldr r8, [pc, #0x70] */
/* @0x18c24c ldr r7, [pc, #0x70] */
/* @0x18c250 str r3, [r4, r0, lsl #2] */
/* @0x18c254 ldr r4, [r2, r12] */
/* @0x18c258 add r12, r4, r1 */
/* @0x18c25c strb r3, [r4, r1] */
/* @0x18c260 ldr r4, [r2, r6] */
/* @0x18c264 add r6, r4, r1 */
/* @0x18c268 strb r3, [r4, r1] */
/* @0x18c26c ldr r5, [r2, r5] */
/* @0x18c270 strb r3, [r6, #0x1] */
/* @0x18c274 add r4, r5, r1 */
/* @0x18c278 strb r3, [r6, #0x2] */
/* @0x18c27c strb r3, [r5, r1] */
/* @0x18c280 strb r3, [r12, #0x1] */
/* @0x18c284 strb r3, [r4, #0x1] */
/* @0x18c288 strb r3, [r4, #0x2] */
/* @0x18c28c strb r3, [r12, #0x2] */
/* @0x18c290 ldr r1, [r2, r8] */
/* @0x18c294 strb r3, [r1, r0] */
/* @0x18c298 ldr r2, [r2, r7] */
/* @0x18c29c strb r3, [r2, r0] */
/* @0x18c2a0 pop {r4, r5, r6, r7, r8} */
/* @0x18c2a4 bx lr */
/* @0x18c2a8 eoreq r5, r6, r8, lsr r10 */
/* @0x18c2ac .word 0xffffe99c */
/* @0x18c2b0 .word 0xffffe9a0 */
/* @0x18c2b4 .word 0xffffe9a4 */
/* @0x18c2b8 .word 0xffffe9ac */
/* @0x18c2bc .word 0xffffe9a8 */
/* @0x18c2c0 .word 0xffffe9b0 */
/* @0x18c2c4 .word 0xffffe9b4 */

/* ── FUNC 0x18c2c8 · IO_Clear() · size=24 · insn=6 */
/* @0x18c2c8 push {r3, lr} */
/* @0x18c2cc bl 0x18be60 <_Z15IO_String_Clearv> */
/* @0x18c2d0 bl 0x18bf94 <_Z16IO_Key_Clear_Allv> */
/* @0x18c2d4 mov r0, #0 */
/* @0x18c2d8 pop {r3, lr} */
/* @0x18c2dc b 0x18c20c <_Z19IO_Button_Clear_Alli> */

/* ── FUNC 0x18c2e0 · IO_Keymap_Get(int) · size=28 · insn=7 */
/* @0x18c2e0 cmp r0, #255 */
/* @0x18c2e4 bxhi lr */
/* @0x18c2e8 ldr r3, [pc, #0x8] */
/* @0x18c2ec ldr r3, [pc, r3] */
/* @0x18c2f0 ldr r0, [r3, r0, lsl #2] */
/* @0x18c2f4 bx lr */
/* @0x18c2f8 eoreq r4, r6, r4, lsr #6 */
