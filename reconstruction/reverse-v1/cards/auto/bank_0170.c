/* libyoyo.so 覆盖卡组 0170
 * 函数 0x1f669c..0x1f7ef8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f669c · CVariableList::DeSerialise(IBuffer*) · size=272 · insn=68 */
/* @0x1f669c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f66a0 mov r6, r1 */
/* @0x1f66a4 sub sp, sp, #28 */
/* @0x1f66a8 mov r9, r0 */
/* @0x1f66ac bl 0x1f662c <_ZN13CVariableList5ClearEv> */
/* @0x1f66b0 ldr r3, [r6] */
/* @0x1f66b4 add r4, r6, #44 */
/* @0x1f66b8 mov r1, #6 */
/* @0x1f66bc mov r0, r6 */
/* @0x1f66c0 ldr r3, [r3, #0xc] */
/* @0x1f66c4 mov r2, r4 */
/* @0x1f66c8 blx r3 */
/* @0x1f66cc mov r0, r4 */
/* @0x1f66d0 mov r1, #0 */
/* @0x1f66d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1f66d8 subs r8, r0, #0 */
/* @0x1f66dc ble 0x1f679c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x100> */
/* @0x1f66e0 ldr r3, [pc, #0xbc] */
/* @0x1f66e4 add r10, sp, #8 */
/* @0x1f66e8 mov r4, #0 */
/* @0x1f66ec add r3, pc, r3 */
/* @0x1f66f0 str r3, [sp, #0x4] */
/* @0x1f66f4 b 0x1f6730 <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x94> */
/* @0x1f66f8 bl 0x1f50cc <_ZN13CVariableList5AllocEi> */
/* @0x1f66fc mov r1, r6 */
/* @0x1f6700 str r11, [r0, #0x28] */
/* @0x1f6704 mov r5, r0 */
/* @0x1f6708 add r0, r0, #24 */
/* @0x1f670c bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer> */
/* @0x1f6710 mov r0, r9 */
/* @0x1f6714 mov r1, r5 */
/* @0x1f6718 bl 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable> */
/* @0x1f671c add r4, r4, #1 */
/* @0x1f6720 mov r0, r7 */
/* @0x1f6724 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f6728 cmp r4, r8 */
/* @0x1f672c beq 0x1f679c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x100> */
/* @0x1f6730 mov r0, r6 */
/* @0x1f6734 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1f6738 mov r7, r0 */
/* @0x1f673c bl 0xd1c94 <_Z24Variable_FindNameNoAllocPKc> */
/* @0x1f6740 cmn r0, #1 */
/* @0x1f6744 mov r11, r0 */
/* @0x1f6748 bne 0x1f66f8 <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x5c> */
/* @0x1f674c ldr r3, [pc, #0x54] */
/* @0x1f6750 mov r2, r7 */
/* @0x1f6754 ldr r1, [sp, #0x4] */
/* @0x1f6758 ldr r3, [pc, r3] */
/* @0x1f675c ldr r0, [r3] */
/* @0x1f6760 ldr r3, [r0] */
/* @0x1f6764 ldr r3, [r3, #0xc] */
/* @0x1f6768 blx r3 */
/* @0x1f676c mov r0, r10 */
/* @0x1f6770 mov r1, r6 */
/* @0x1f6774 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer> */
/* @0x1f6778 ldr r3, [sp, #0x14] */
/* @0x1f677c sub r3, r3, #1 */
/* @0x1f6780 bic r3, r3, #-16777216 */
/* @0x1f6784 bic r3, r3, #3 */
/* @0x1f6788 cmp r3, #0 */
/* @0x1f678c bne 0x1f671c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x80> */
/* @0x1f6790 mov r0, r10 */
/* @0x1f6794 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6798 b 0x1f671c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x80> */
/* @0x1f679c add sp, sp, #28 */
/* @0x1f67a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f67a4 andseq r12, r5, r8, ror #3 */
/* @0x1f67a8 ldrheq r6, [pc], -r12 */

/* ── FUNC 0x1f67ac · CVariableList::Free(RVariable*, RVariable**, RVariable**) · size=584 · insn=146 */
/* @0x1f67ac push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f67b0 mov r5, r0 */
/* @0x1f67b4 ldr r3, [r2] */
/* @0x1f67b8 cmp r3, #0 */
/* @0x1f67bc ldr r3, [r0, #0x14] */
/* @0x1f67c0 streq r0, [r2] */
/* @0x1f67c4 sub r3, r3, #1 */
/* @0x1f67c8 ldr r2, [r1] */
/* @0x1f67cc bic r3, r3, #-16777216 */
/* @0x1f67d0 bic r3, r3, #3 */
/* @0x1f67d4 cmp r3, #0 */
/* @0x1f67d8 str r2, [r0, #0x4] */
/* @0x1f67dc str r0, [r1] */
/* @0x1f67e0 beq 0x1f6874 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xc8> */
/* @0x1f67e4 ldr r1, [r5, #0x24] */
/* @0x1f67e8 mov r2, #0 */
/* @0x1f67ec mov r0, #5 */
/* @0x1f67f0 str r2, [r5, #0x10] */
/* @0x1f67f4 sub r3, r1, #1 */
/* @0x1f67f8 str r2, [r5, #0x8] */
/* @0x1f67fc bic r3, r3, #-16777216 */
/* @0x1f6800 str r0, [r5, #0x14] */
/* @0x1f6804 bics r4, r3, #3 */
/* @0x1f6808 beq 0x1f6824 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x78> */
/* @0x1f680c mov r3, #0 */
/* @0x1f6810 mov r2, #5 */
/* @0x1f6814 str r3, [r5, #0x20] */
/* @0x1f6818 str r3, [r5, #0x18] */
/* @0x1f681c str r2, [r5, #0x24] */
/* @0x1f6820 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f6824 bic r1, r1, #-16777216 */
/* @0x1f6828 cmp r1, #2 */
/* @0x1f682c beq 0x1f68a8 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xfc> */
/* @0x1f6830 cmp r1, #3 */
/* @0x1f6834 beq 0x1f6880 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xd4> */
/* @0x1f6838 cmp r1, #1 */
/* @0x1f683c bne 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f6840 ldr r4, [r5, #0x18] */
/* @0x1f6844 cmp r4, #0 */
/* @0x1f6848 beq 0x1f6868 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xbc> */
/* @0x1f684c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6850 ldr r6, [r4, #0x4] */
/* @0x1f6854 sub r6, r6, #1 */
/* @0x1f6858 str r6, [r4, #0x4] */
/* @0x1f685c cmp r6, #0 */
/* @0x1f6860 beq 0x1f68e4 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x138> */
/* @0x1f6864 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6868 mov r3, #0 */
/* @0x1f686c str r3, [r5, #0x18] */
/* @0x1f6870 b 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f6874 add r0, r0, #8 */
/* @0x1f6878 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f687c b 0x1f67e4 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x38> */
/* @0x1f6880 ldr r3, [r5, #0x20] */
/* @0x1f6884 tst r3, #8 */
/* @0x1f6888 beq 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f688c ldr r0, [r5, #0x18] */
/* @0x1f6890 cmp r0, #0 */
/* @0x1f6894 beq 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f6898 ldr r3, [r0] */
/* @0x1f689c ldr r3, [r3, #0x4] */
/* @0x1f68a0 blx r3 */
/* @0x1f68a4 b 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f68a8 ldr r8, [r5, #0x18] */
/* @0x1f68ac cmp r8, #0 */
/* @0x1f68b0 beq 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f68b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f68b8 ldr r3, [r8] */
/* @0x1f68bc ldr r1, [r8, #0x8] */
/* @0x1f68c0 add r2, r5, #24 */
/* @0x1f68c4 sub r3, r3, #1 */
/* @0x1f68c8 str r3, [r8] */
/* @0x1f68cc cmp r1, r2 */
/* @0x1f68d0 streq r4, [r8, #0x8] */
/* @0x1f68d4 cmp r3, #0 */
/* @0x1f68d8 ble 0x1f691c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x170> */
/* @0x1f68dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f68e0 b 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60> */
/* @0x1f68e4 ldr r0, [r4] */
/* @0x1f68e8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f68ec str r6, [r4] */
/* @0x1f68f0 str r6, [r4, #0x8] */
/* @0x1f68f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f68f8 ldr r6, [r4, #0x4] */
/* @0x1f68fc sub r6, r6, #1 */
/* @0x1f6900 str r6, [r4, #0x4] */
/* @0x1f6904 cmp r6, #0 */
/* @0x1f6908 beq 0x1f69d0 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x224> */
/* @0x1f690c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6910 mov r0, r4 */
/* @0x1f6914 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6918 b 0x1f6864 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xb8> */
/* @0x1f691c ldr r3, [r8, #0x10] */
/* @0x1f6920 cmp r3, #0 */
/* @0x1f6924 movgt r7, #0 */
/* @0x1f6928 movgt r11, #5 */
/* @0x1f692c movgt r6, r7 */
/* @0x1f6930 ble 0x1f69a8 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1fc> */
/* @0x1f6934 ldr r3, [r8, #0x4] */
/* @0x1f6938 add r9, r3, r7, lsl #3 */
/* @0x1f693c ldr r10, [r3, r7, lsl #3] */
/* @0x1f6940 ldr r4, [r9, #0x4] */
/* @0x1f6944 add r10, r4, r10, lsl #4 */
/* @0x1f6948 cmp r4, r10 */
/* @0x1f694c blo 0x1f6968 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1bc> */
/* @0x1f6950 b 0x1f69c8 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x21c> */
/* @0x1f6954 str r6, [r4, #0x8] */
/* @0x1f6958 str r11, [r4, #0xc] */
/* @0x1f695c str r6, [r4], #16 */
/* @0x1f6960 cmp r10, r4 */
/* @0x1f6964 bls 0x1f698c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1e0> */
/* @0x1f6968 ldr r3, [r4, #0xc] */
/* @0x1f696c sub r3, r3, #1 */
/* @0x1f6970 bic r3, r3, #-16777216 */
/* @0x1f6974 bic r3, r3, #3 */
/* @0x1f6978 cmp r3, #0 */
/* @0x1f697c bne 0x1f6954 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1a8> */
/* @0x1f6980 mov r0, r4 */
/* @0x1f6984 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6988 b 0x1f6954 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1a8> */
/* @0x1f698c ldr r0, [r9, #0x4] */
/* @0x1f6990 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1f6994 ldr r3, [r8, #0x10] */
/* @0x1f6998 add r7, r7, #1 */
/* @0x1f699c str r6, [r9, #0x4] */
/* @0x1f69a0 cmp r7, r3 */
/* @0x1f69a4 blt 0x1f6934 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x188> */
/* @0x1f69a8 ldr r0, [r8, #0x4] */
/* @0x1f69ac mov r4, #0 */
/* @0x1f69b0 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1f69b4 str r4, [r8, #0x4] */
/* @0x1f69b8 mov r0, r8 */
/* @0x1f69bc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1f69c0 str r4, [r5, #0x18] */
/* @0x1f69c4 b 0x1f68dc <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x130> */
/* @0x1f69c8 mov r0, r4 */
/* @0x1f69cc b 0x1f6990 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1e4> */
/* @0x1f69d0 ldr r0, [r4] */
/* @0x1f69d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f69d8 mov r0, r4 */
/* @0x1f69dc str r6, [r4] */
/* @0x1f69e0 str r6, [r4, #0x8] */
/* @0x1f69e4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f69e8 mov r0, r4 */
/* @0x1f69ec bl 0x27d1d0 <_ZdlPv> */
/* @0x1f69f0 b 0x1f690c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x160> */

/* ── FUNC 0x1f69f4 · FreeRange(CVariableList&, RVariable**, RVariable**) · size=160 · insn=40 */
/* @0x1f69f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f69f8 adds r4, r0, #4 */
/* @0x1f69fc mov r7, r1 */
/* @0x1f6a00 mov r8, r2 */
/* @0x1f6a04 addne r4, r0, #20 */
/* @0x1f6a08 beq 0x1f6a70 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x7c> */
/* @0x1f6a0c cmp r4, r0 */
/* @0x1f6a10 add r6, r0, #4 */
/* @0x1f6a14 beq 0x1f6a20 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x2c> */
/* @0x1f6a18 cmp r4, r6 */
/* @0x1f6a1c bne 0x1f6a7c <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x88> */
/* @0x1f6a20 mov r6, r4 */
/* @0x1f6a24 mov r5, #0 */
/* @0x1f6a28 cmp r5, #0 */
/* @0x1f6a2c beq 0x1f6a6c <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x78> */
/* @0x1f6a30 mov r0, r5 */
/* @0x1f6a34 mov r1, r7 */
/* @0x1f6a38 mov r2, r8 */
/* @0x1f6a3c bl 0x1f67ac <_ZN13CVariableList4FreeEP9RVariablePS1_S2_> */
/* @0x1f6a40 ldr r5, [r5] */
/* @0x1f6a44 cmp r5, #0 */
/* @0x1f6a48 add r3, r6, #4 */
/* @0x1f6a4c bne 0x1f6a28 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x34> */
/* @0x1f6a50 cmp r4, r6 */
/* @0x1f6a54 beq 0x1f6a90 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x9c> */
/* @0x1f6a58 cmp r3, r4 */
/* @0x1f6a5c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1f6a60 ldr r5, [r6, #0x4] */
/* @0x1f6a64 mov r6, r3 */
/* @0x1f6a68 b 0x1f6a44 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x50> */
/* @0x1f6a6c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f6a70 mov r6, r4 */
/* @0x1f6a74 mov r5, r4 */
/* @0x1f6a78 b 0x1f6a28 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x34> */
/* @0x1f6a7c ldr r5, [r0, #0x4] */
/* @0x1f6a80 cmp r5, #0 */
/* @0x1f6a84 bne 0x1f6a28 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x34> */
/* @0x1f6a88 mov r0, r6 */
/* @0x1f6a8c b 0x1f6a0c <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x18> */
/* @0x1f6a90 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1f6a94 · CVariableList::Clear(RVariable**, RVariable**) · size=44 · insn=11 */
/* @0x1f6a94 push {r4, lr} */
/* @0x1f6a98 mov r4, r0 */
/* @0x1f6a9c bl 0x1f69f4 <_Z9FreeRangeR13CVariableListPP9RVariableS3_> */
/* @0x1f6aa0 add r0, r4, #4 */
/* @0x1f6aa4 mov r1, #0 */
/* @0x1f6aa8 mov r2, #16 */
/* @0x1f6aac bl 0xb65b0 <memset@plt> */
/* @0x1f6ab0 mov r3, #0 */
/* @0x1f6ab4 str r3, [r4, #0x18] */
/* @0x1f6ab8 str r3, [r4, #0x14] */
/* @0x1f6abc pop {r4, pc} */

/* ── FUNC 0x1f6ac0 · GetVariable(RValue*, RValue*) · size=564 · insn=141 */
/* @0x1f6ac0 ldr r2, [r0, #0xc] */
/* @0x1f6ac4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1f6ac8 bic r3, r2, #-16777216 */
/* @0x1f6acc cmp r3, #1 */
/* @0x1f6ad0 mov r4, r0 */
/* @0x1f6ad4 mov r5, r1 */
/* @0x1f6ad8 beq 0x1f6b88 <_Z11GetVariableP6RValueS0_+0xc8> */
/* @0x1f6adc cmp r3, #2 */
/* @0x1f6ae0 bne 0x1f6b08 <_Z11GetVariableP6RValueS0_+0x48> */
/* @0x1f6ae4 sub r2, r2, #1 */
/* @0x1f6ae8 bic r2, r2, #-16777216 */
/* @0x1f6aec bic r2, r2, #3 */
/* @0x1f6af0 cmp r2, #0 */
/* @0x1f6af4 beq 0x1f6c5c <_Z11GetVariableP6RValueS0_+0x19c> */
/* @0x1f6af8 mov r2, #0 */
/* @0x1f6afc mov r3, #5 */
/* @0x1f6b00 str r2, [r4, #0x8] */
/* @0x1f6b04 str r3, [r4, #0xc] */
/* @0x1f6b08 ldr r3, [r5, #0xc] */
/* @0x1f6b0c mov r1, #0 */
/* @0x1f6b10 ldr r2, [r5, #0x8] */
/* @0x1f6b14 str r1, [r4] */
/* @0x1f6b18 str r3, [r4, #0xc] */
/* @0x1f6b1c ldr r3, [r5, #0xc] */
/* @0x1f6b20 str r2, [r4, #0x8] */
/* @0x1f6b24 bic r3, r3, #-16777216 */
/* @0x1f6b28 cmp r3, #14 */
/* @0x1f6b2c addls pc, pc, r3, lsl #2 */
/* @0x1f6b30 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b34 b 0x1f6b7c <_Z11GetVariableP6RValueS0_+0xbc> */
/* @0x1f6b38 b 0x1f6be0 <_Z11GetVariableP6RValueS0_+0x120> */
/* @0x1f6b3c b 0x1f6bf8 <_Z11GetVariableP6RValueS0_+0x138> */
/* @0x1f6b40 b 0x1f6b70 <_Z11GetVariableP6RValueS0_+0xb0> */
/* @0x1f6b44 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b48 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b4c b 0x1f6bbc <_Z11GetVariableP6RValueS0_+0xfc> */
/* @0x1f6b50 b 0x1f6b70 <_Z11GetVariableP6RValueS0_+0xb0> */
/* @0x1f6b54 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b58 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b5c b 0x1f6b7c <_Z11GetVariableP6RValueS0_+0xbc> */
/* @0x1f6b60 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b64 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8> */
/* @0x1f6b68 b 0x1f6b7c <_Z11GetVariableP6RValueS0_+0xbc> */
/* @0x1f6b6c b 0x1f6b70 <_Z11GetVariableP6RValueS0_+0xb0> */
/* @0x1f6b70 ldr r3, [r5] */
/* @0x1f6b74 str r3, [r4] */
/* @0x1f6b78 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1f6b7c ldm r5, {r2, r3} */
/* @0x1f6b80 stm r4, {r2, r3} */
/* @0x1f6b84 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1f6b88 ldr r6, [r0] */
/* @0x1f6b8c cmp r6, #0 */
/* @0x1f6b90 beq 0x1f6bb0 <_Z11GetVariableP6RValueS0_+0xf0> */
/* @0x1f6b94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6b98 ldr r7, [r6, #0x4] */
/* @0x1f6b9c sub r7, r7, #1 */
/* @0x1f6ba0 str r7, [r6, #0x4] */
/* @0x1f6ba4 cmp r7, #0 */
/* @0x1f6ba8 beq 0x1f6c24 <_Z11GetVariableP6RValueS0_+0x164> */
/* @0x1f6bac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6bb0 mov r3, #0 */
/* @0x1f6bb4 str r3, [r4] */
/* @0x1f6bb8 b 0x1f6b08 <_Z11GetVariableP6RValueS0_+0x48> */
/* @0x1f6bbc ldr r3, [r5] */
/* @0x1f6bc0 str r3, [r4] */
/* @0x1f6bc4 ldr r3, [r5] */
/* @0x1f6bc8 cmp r3, #0 */
/* @0x1f6bcc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1f6bd0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f6bd4 ldr r1, [r5] */
/* @0x1f6bd8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1f6bdc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f6be0 ldr r3, [r5] */
/* @0x1f6be4 cmp r3, #0 */
/* @0x1f6be8 ldrne r2, [r3, #0x4] */
/* @0x1f6bec addne r2, r2, #1 */
/* @0x1f6bf0 strne r2, [r3, #0x4] */
/* @0x1f6bf4 b 0x1f6b74 <_Z11GetVariableP6RValueS0_+0xb4> */
/* @0x1f6bf8 ldr r3, [r5] */
/* @0x1f6bfc cmp r3, #0 */
/* @0x1f6c00 str r3, [r4] */
/* @0x1f6c04 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1f6c08 ldr r1, [r3, #0x8] */
/* @0x1f6c0c ldr r2, [r3] */
/* @0x1f6c10 cmp r1, #0 */
/* @0x1f6c14 streq r4, [r3, #0x8] */
/* @0x1f6c18 add r2, r2, #1 */
/* @0x1f6c1c str r2, [r3] */
/* @0x1f6c20 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1f6c24 ldr r0, [r6] */
/* @0x1f6c28 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6c2c str r7, [r6] */
/* @0x1f6c30 str r7, [r6, #0x8] */
/* @0x1f6c34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6c38 ldr r7, [r6, #0x4] */
/* @0x1f6c3c sub r7, r7, #1 */
/* @0x1f6c40 str r7, [r6, #0x4] */
/* @0x1f6c44 cmp r7, #0 */
/* @0x1f6c48 beq 0x1f6c64 <_Z11GetVariableP6RValueS0_+0x1a4> */
/* @0x1f6c4c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6c50 mov r0, r6 */
/* @0x1f6c54 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6c58 b 0x1f6bac <_Z11GetVariableP6RValueS0_+0xec> */
/* @0x1f6c5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6c60 b 0x1f6af8 <_Z11GetVariableP6RValueS0_+0x38> */
/* @0x1f6c64 ldr r0, [r6] */
/* @0x1f6c68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6c6c str r7, [r6] */
/* @0x1f6c70 str r7, [r6, #0x8] */
/* @0x1f6c74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6c78 ldr r7, [r6, #0x4] */
/* @0x1f6c7c sub r7, r7, #1 */
/* @0x1f6c80 str r7, [r6, #0x4] */
/* @0x1f6c84 cmp r7, #0 */
/* @0x1f6c88 beq 0x1f6c9c <_Z11GetVariableP6RValueS0_+0x1dc> */
/* @0x1f6c8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6c90 mov r0, r6 */
/* @0x1f6c94 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6c98 b 0x1f6c4c <_Z11GetVariableP6RValueS0_+0x18c> */
/* @0x1f6c9c ldr r0, [r6] */
/* @0x1f6ca0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6ca4 str r7, [r6] */
/* @0x1f6ca8 str r7, [r6, #0x8] */
/* @0x1f6cac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6cb0 ldr r7, [r6, #0x4] */
/* @0x1f6cb4 sub r7, r7, #1 */
/* @0x1f6cb8 str r7, [r6, #0x4] */
/* @0x1f6cbc cmp r7, #0 */
/* @0x1f6cc0 bne 0x1f6ce4 <_Z11GetVariableP6RValueS0_+0x224> */
/* @0x1f6cc4 ldr r0, [r6] */
/* @0x1f6cc8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6ccc mov r0, r6 */
/* @0x1f6cd0 str r7, [r6] */
/* @0x1f6cd4 str r7, [r6, #0x8] */
/* @0x1f6cd8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f6cdc mov r0, r6 */
/* @0x1f6ce0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6ce4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6ce8 mov r0, r6 */
/* @0x1f6cec bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6cf0 b 0x1f6c8c <_Z11GetVariableP6RValueS0_+0x1cc> */

/* ── FUNC 0x1f6cf4 · CVariableList::Alloc(RValue const*) · size=652 · insn=163 */
/* @0x1f6cf4 ldr r3, [pc, #0x280] */
/* @0x1f6cf8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f6cfc ldr r3, [pc, r3] */
/* @0x1f6d00 mov r5, r0 */
/* @0x1f6d04 ldr r4, [r3] */
/* @0x1f6d08 cmp r4, #0 */
/* @0x1f6d0c beq 0x1f6ec4 <_ZN13CVariableList5AllocEPK6RValue+0x1d0> */
/* @0x1f6d10 ldr r2, [r4, #0x4] */
/* @0x1f6d14 add r7, r4, #8 */
/* @0x1f6d18 str r2, [r3] */
/* @0x1f6d1c bl 0xcee94 <_Z11HASH_RValuePK6RValue> */
/* @0x1f6d20 ldr r2, [r4, #0x14] */
/* @0x1f6d24 bic r3, r2, #-16777216 */
/* @0x1f6d28 cmp r3, #1 */
/* @0x1f6d2c str r0, [r4, #0x28] */
/* @0x1f6d30 beq 0x1f6e08 <_ZN13CVariableList5AllocEPK6RValue+0x114> */
/* @0x1f6d34 cmp r3, #2 */
/* @0x1f6d38 bne 0x1f6d60 <_ZN13CVariableList5AllocEPK6RValue+0x6c> */
/* @0x1f6d3c sub r2, r2, #1 */
/* @0x1f6d40 bic r2, r2, #-16777216 */
/* @0x1f6d44 bic r2, r2, #3 */
/* @0x1f6d48 cmp r2, #0 */
/* @0x1f6d4c beq 0x1f6ee0 <_ZN13CVariableList5AllocEPK6RValue+0x1ec> */
/* @0x1f6d50 mov r2, #0 */
/* @0x1f6d54 mov r3, #5 */
/* @0x1f6d58 str r2, [r4, #0x10] */
/* @0x1f6d5c str r3, [r4, #0x14] */
/* @0x1f6d60 ldr r3, [r5, #0xc] */
/* @0x1f6d64 mov r1, #0 */
/* @0x1f6d68 ldr r2, [r5, #0x8] */
/* @0x1f6d6c str r1, [r4, #0x8] */
/* @0x1f6d70 str r3, [r4, #0x14] */
/* @0x1f6d74 ldr r3, [r5, #0xc] */
/* @0x1f6d78 str r2, [r4, #0x10] */
/* @0x1f6d7c bic r3, r3, #-16777216 */
/* @0x1f6d80 cmp r3, #14 */
/* @0x1f6d84 addls pc, pc, r3, lsl #2 */
/* @0x1f6d88 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6d8c b 0x1f6e3c <_ZN13CVariableList5AllocEPK6RValue+0x148> */
/* @0x1f6d90 b 0x1f6e50 <_ZN13CVariableList5AllocEPK6RValue+0x15c> */
/* @0x1f6d94 b 0x1f6dc8 <_ZN13CVariableList5AllocEPK6RValue+0xd4> */
/* @0x1f6d98 b 0x1f6df8 <_ZN13CVariableList5AllocEPK6RValue+0x104> */
/* @0x1f6d9c b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6da0 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6da4 b 0x1f6e68 <_ZN13CVariableList5AllocEPK6RValue+0x174> */
/* @0x1f6da8 b 0x1f6df8 <_ZN13CVariableList5AllocEPK6RValue+0x104> */
/* @0x1f6dac b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6db0 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6db4 b 0x1f6e3c <_ZN13CVariableList5AllocEPK6RValue+0x148> */
/* @0x1f6db8 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6dbc b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6dc0 b 0x1f6e3c <_ZN13CVariableList5AllocEPK6RValue+0x148> */
/* @0x1f6dc4 b 0x1f6df8 <_ZN13CVariableList5AllocEPK6RValue+0x104> */
/* @0x1f6dc8 ldr r3, [r5] */
/* @0x1f6dcc cmp r3, #0 */
/* @0x1f6dd0 str r3, [r4, #0x8] */
/* @0x1f6dd4 beq 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6dd8 ldr r1, [r3, #0x8] */
/* @0x1f6ddc ldr r2, [r3] */
/* @0x1f6de0 cmp r1, #0 */
/* @0x1f6de4 streq r7, [r3, #0x8] */
/* @0x1f6de8 add r2, r2, #1 */
/* @0x1f6dec str r2, [r3] */
/* @0x1f6df0 mov r0, r4 */
/* @0x1f6df4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f6df8 ldr r3, [r5] */
/* @0x1f6dfc str r3, [r4, #0x8] */
/* @0x1f6e00 mov r0, r4 */
/* @0x1f6e04 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f6e08 ldr r6, [r4, #0x8] */
/* @0x1f6e0c cmp r6, #0 */
/* @0x1f6e10 beq 0x1f6e30 <_ZN13CVariableList5AllocEPK6RValue+0x13c> */
/* @0x1f6e14 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6e18 ldr r8, [r6, #0x4] */
/* @0x1f6e1c sub r8, r8, #1 */
/* @0x1f6e20 str r8, [r6, #0x4] */
/* @0x1f6e24 cmp r8, #0 */
/* @0x1f6e28 beq 0x1f6e8c <_ZN13CVariableList5AllocEPK6RValue+0x198> */
/* @0x1f6e2c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6e30 mov r3, #0 */
/* @0x1f6e34 str r3, [r4, #0x8] */
/* @0x1f6e38 b 0x1f6d60 <_ZN13CVariableList5AllocEPK6RValue+0x6c> */
/* @0x1f6e3c ldm r5, {r2, r3} */
/* @0x1f6e40 mov r0, r4 */
/* @0x1f6e44 str r2, [r4, #0x8] */
/* @0x1f6e48 str r3, [r4, #0xc] */
/* @0x1f6e4c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f6e50 ldr r3, [r5] */
/* @0x1f6e54 cmp r3, #0 */
/* @0x1f6e58 ldrne r2, [r3, #0x4] */
/* @0x1f6e5c addne r2, r2, #1 */
/* @0x1f6e60 strne r2, [r3, #0x4] */
/* @0x1f6e64 b 0x1f6dfc <_ZN13CVariableList5AllocEPK6RValue+0x108> */
/* @0x1f6e68 ldr r3, [r5] */
/* @0x1f6e6c str r3, [r4, #0x8] */
/* @0x1f6e70 ldr r3, [r5] */
/* @0x1f6e74 cmp r3, #0 */
/* @0x1f6e78 beq 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6e7c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f6e80 ldr r1, [r5] */
/* @0x1f6e84 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f6e88 b 0x1f6df0 <_ZN13CVariableList5AllocEPK6RValue+0xfc> */
/* @0x1f6e8c ldr r0, [r6] */
/* @0x1f6e90 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6e94 str r8, [r6] */
/* @0x1f6e98 str r8, [r6, #0x8] */
/* @0x1f6e9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6ea0 ldr r8, [r6, #0x4] */
/* @0x1f6ea4 sub r8, r8, #1 */
/* @0x1f6ea8 str r8, [r6, #0x4] */
/* @0x1f6eac cmp r8, #0 */
/* @0x1f6eb0 beq 0x1f6eec <_ZN13CVariableList5AllocEPK6RValue+0x1f8> */
/* @0x1f6eb4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6eb8 mov r0, r6 */
/* @0x1f6ebc bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6ec0 b 0x1f6e2c <_ZN13CVariableList5AllocEPK6RValue+0x138> */
/* @0x1f6ec4 mov r0, #44 */
/* @0x1f6ec8 bl 0x27c524 <_Znwj> */
/* @0x1f6ecc mov r1, r5 */
/* @0x1f6ed0 mov r4, r0 */
/* @0x1f6ed4 bl 0x1f5b60 <_ZN9RVariableC2EPK6RValue> */
/* @0x1f6ed8 mov r0, r4 */
/* @0x1f6edc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f6ee0 mov r0, r7 */
/* @0x1f6ee4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6ee8 b 0x1f6d50 <_ZN13CVariableList5AllocEPK6RValue+0x5c> */
/* @0x1f6eec ldr r0, [r6] */
/* @0x1f6ef0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6ef4 str r8, [r6] */
/* @0x1f6ef8 str r8, [r6, #0x8] */
/* @0x1f6efc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6f00 ldr r8, [r6, #0x4] */
/* @0x1f6f04 sub r8, r8, #1 */
/* @0x1f6f08 str r8, [r6, #0x4] */
/* @0x1f6f0c cmp r8, #0 */
/* @0x1f6f10 beq 0x1f6f24 <_ZN13CVariableList5AllocEPK6RValue+0x230> */
/* @0x1f6f14 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6f18 mov r0, r6 */
/* @0x1f6f1c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6f20 b 0x1f6eb4 <_ZN13CVariableList5AllocEPK6RValue+0x1c0> */
/* @0x1f6f24 ldr r0, [r6] */
/* @0x1f6f28 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6f2c str r8, [r6] */
/* @0x1f6f30 str r8, [r6, #0x8] */
/* @0x1f6f34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6f38 ldr r8, [r6, #0x4] */
/* @0x1f6f3c sub r8, r8, #1 */
/* @0x1f6f40 str r8, [r6, #0x4] */
/* @0x1f6f44 cmp r8, #0 */
/* @0x1f6f48 bne 0x1f6f6c <_ZN13CVariableList5AllocEPK6RValue+0x278> */
/* @0x1f6f4c ldr r0, [r6] */
/* @0x1f6f50 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6f54 mov r0, r6 */
/* @0x1f6f58 str r8, [r6] */
/* @0x1f6f5c str r8, [r6, #0x8] */
/* @0x1f6f60 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f6f64 mov r0, r6 */
/* @0x1f6f68 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6f6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6f70 mov r0, r6 */
/* @0x1f6f74 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6f78 b 0x1f6f14 <_ZN13CVariableList5AllocEPK6RValue+0x220> */
/* @0x1f6f7c andseq r10, pc, r8, lsr r1 */

/* ── FUNC 0x1f6f80 · RVariable::Assign(RVariable const&) · size=1156 · insn=289 */
/* @0x1f6f80 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f6f84 mov r5, r1 */
/* @0x1f6f88 ldr r1, [r0, #0x24] */
/* @0x1f6f8c mov r3, #0 */
/* @0x1f6f90 mov r4, r0 */
/* @0x1f6f94 add r7, r0, #24 */
/* @0x1f6f98 bic r2, r1, #-16777216 */
/* @0x1f6f9c str r3, [r0] */
/* @0x1f6fa0 cmp r2, #1 */
/* @0x1f6fa4 str r3, [r0, #0x4] */
/* @0x1f6fa8 beq 0x1f7124 <_ZN9RVariable6AssignERKS_+0x1a4> */
/* @0x1f6fac cmp r2, #2 */
/* @0x1f6fb0 bne 0x1f6fd8 <_ZN9RVariable6AssignERKS_+0x58> */
/* @0x1f6fb4 sub r1, r1, #1 */
/* @0x1f6fb8 bic r1, r1, #-16777216 */
/* @0x1f6fbc bic r1, r1, #3 */
/* @0x1f6fc0 cmp r1, #0 */
/* @0x1f6fc4 beq 0x1f72cc <_ZN9RVariable6AssignERKS_+0x34c> */
/* @0x1f6fc8 mov r2, #0 */
/* @0x1f6fcc mov r3, #5 */
/* @0x1f6fd0 str r2, [r4, #0x20] */
/* @0x1f6fd4 str r3, [r4, #0x24] */
/* @0x1f6fd8 ldr r3, [r5, #0x24] */
/* @0x1f6fdc mov r1, #0 */
/* @0x1f6fe0 ldr r2, [r5, #0x20] */
/* @0x1f6fe4 str r1, [r4, #0x18] */
/* @0x1f6fe8 str r3, [r4, #0x24] */
/* @0x1f6fec ldr r3, [r5, #0x24] */
/* @0x1f6ff0 str r2, [r4, #0x20] */
/* @0x1f6ff4 bic r3, r3, #-16777216 */
/* @0x1f6ff8 cmp r3, #14 */
/* @0x1f6ffc addls pc, pc, r3, lsl #2 */
/* @0x1f7000 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f7004 b 0x1f70fc <_ZN9RVariable6AssignERKS_+0x17c> */
/* @0x1f7008 b 0x1f71b0 <_ZN9RVariable6AssignERKS_+0x230> */
/* @0x1f700c b 0x1f71c8 <_ZN9RVariable6AssignERKS_+0x248> */
/* @0x1f7010 b 0x1f7040 <_ZN9RVariable6AssignERKS_+0xc0> */
/* @0x1f7014 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f7018 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f701c b 0x1f718c <_ZN9RVariable6AssignERKS_+0x20c> */
/* @0x1f7020 b 0x1f7040 <_ZN9RVariable6AssignERKS_+0xc0> */
/* @0x1f7024 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f7028 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f702c b 0x1f70fc <_ZN9RVariable6AssignERKS_+0x17c> */
/* @0x1f7030 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f7034 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f7038 b 0x1f70fc <_ZN9RVariable6AssignERKS_+0x17c> */
/* @0x1f703c b 0x1f7040 <_ZN9RVariable6AssignERKS_+0xc0> */
/* @0x1f7040 ldr r3, [r5, #0x18] */
/* @0x1f7044 str r3, [r4, #0x18] */
/* @0x1f7048 ldr r2, [r4, #0x14] */
/* @0x1f704c add r7, r4, #8 */
/* @0x1f7050 bic r3, r2, #-16777216 */
/* @0x1f7054 cmp r3, #1 */
/* @0x1f7058 beq 0x1f7158 <_ZN9RVariable6AssignERKS_+0x1d8> */
/* @0x1f705c cmp r3, #2 */
/* @0x1f7060 bne 0x1f7088 <_ZN9RVariable6AssignERKS_+0x108> */
/* @0x1f7064 sub r2, r2, #1 */
/* @0x1f7068 bic r2, r2, #-16777216 */
/* @0x1f706c bic r2, r2, #3 */
/* @0x1f7070 cmp r2, #0 */
/* @0x1f7074 beq 0x1f72d8 <_ZN9RVariable6AssignERKS_+0x358> */
/* @0x1f7078 mov r2, #0 */
/* @0x1f707c mov r3, #5 */
/* @0x1f7080 str r2, [r4, #0x10] */
/* @0x1f7084 str r3, [r4, #0x14] */
/* @0x1f7088 ldr r3, [r5, #0x14] */
/* @0x1f708c mov r1, #0 */
/* @0x1f7090 ldr r2, [r5, #0x10] */
/* @0x1f7094 str r1, [r4, #0x8] */
/* @0x1f7098 str r3, [r4, #0x14] */
/* @0x1f709c ldr r3, [r5, #0x14] */
/* @0x1f70a0 str r2, [r4, #0x10] */
/* @0x1f70a4 bic r3, r3, #-16777216 */
/* @0x1f70a8 cmp r3, #14 */
/* @0x1f70ac addls pc, pc, r3, lsl #2 */
/* @0x1f70b0 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70b4 b 0x1f7110 <_ZN9RVariable6AssignERKS_+0x190> */
/* @0x1f70b8 b 0x1f71f4 <_ZN9RVariable6AssignERKS_+0x274> */
/* @0x1f70bc b 0x1f7230 <_ZN9RVariable6AssignERKS_+0x2b0> */
/* @0x1f70c0 b 0x1f70f0 <_ZN9RVariable6AssignERKS_+0x170> */
/* @0x1f70c4 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70c8 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70cc b 0x1f720c <_ZN9RVariable6AssignERKS_+0x28c> */
/* @0x1f70d0 b 0x1f70f0 <_ZN9RVariable6AssignERKS_+0x170> */
/* @0x1f70d4 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70d8 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70dc b 0x1f7110 <_ZN9RVariable6AssignERKS_+0x190> */
/* @0x1f70e0 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70e4 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178> */
/* @0x1f70e8 b 0x1f7110 <_ZN9RVariable6AssignERKS_+0x190> */
/* @0x1f70ec b 0x1f70f0 <_ZN9RVariable6AssignERKS_+0x170> */
/* @0x1f70f0 ldr r3, [r5, #0x8] */
/* @0x1f70f4 str r3, [r4, #0x8] */
/* @0x1f70f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f70fc ldr r2, [r5, #0x18] */
/* @0x1f7100 ldr r3, [r5, #0x1c] */
/* @0x1f7104 str r2, [r4, #0x18] */
/* @0x1f7108 str r3, [r4, #0x1c] */
/* @0x1f710c b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f7110 ldr r2, [r5, #0x8] */
/* @0x1f7114 ldr r3, [r5, #0xc] */
/* @0x1f7118 str r2, [r4, #0x8] */
/* @0x1f711c str r3, [r4, #0xc] */
/* @0x1f7120 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f7124 ldr r6, [r0, #0x18] */
/* @0x1f7128 cmp r6, #0 */
/* @0x1f712c beq 0x1f714c <_ZN9RVariable6AssignERKS_+0x1cc> */
/* @0x1f7130 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7134 ldr r8, [r6, #0x4] */
/* @0x1f7138 sub r8, r8, #1 */
/* @0x1f713c str r8, [r6, #0x4] */
/* @0x1f7140 cmp r8, #0 */
/* @0x1f7144 beq 0x1f725c <_ZN9RVariable6AssignERKS_+0x2dc> */
/* @0x1f7148 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f714c mov r3, #0 */
/* @0x1f7150 str r3, [r4, #0x18] */
/* @0x1f7154 b 0x1f6fd8 <_ZN9RVariable6AssignERKS_+0x58> */
/* @0x1f7158 ldr r6, [r4, #0x8] */
/* @0x1f715c cmp r6, #0 */
/* @0x1f7160 beq 0x1f7180 <_ZN9RVariable6AssignERKS_+0x200> */
/* @0x1f7164 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7168 ldr r8, [r6, #0x4] */
/* @0x1f716c sub r8, r8, #1 */
/* @0x1f7170 str r8, [r6, #0x4] */
/* @0x1f7174 cmp r8, #0 */
/* @0x1f7178 beq 0x1f7294 <_ZN9RVariable6AssignERKS_+0x314> */
/* @0x1f717c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f7180 mov r3, #0 */
/* @0x1f7184 str r3, [r4, #0x8] */
/* @0x1f7188 b 0x1f7088 <_ZN9RVariable6AssignERKS_+0x108> */
/* @0x1f718c ldr r3, [r5, #0x18] */
/* @0x1f7190 str r3, [r4, #0x18] */
/* @0x1f7194 ldr r3, [r5, #0x18] */
/* @0x1f7198 cmp r3, #0 */
/* @0x1f719c beq 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f71a0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f71a4 ldr r1, [r5, #0x18] */
/* @0x1f71a8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f71ac b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f71b0 ldr r3, [r5, #0x18] */
/* @0x1f71b4 cmp r3, #0 */
/* @0x1f71b8 ldrne r2, [r3, #0x4] */
/* @0x1f71bc addne r2, r2, #1 */
/* @0x1f71c0 strne r2, [r3, #0x4] */
/* @0x1f71c4 b 0x1f7044 <_ZN9RVariable6AssignERKS_+0xc4> */
/* @0x1f71c8 ldr r3, [r5, #0x18] */
/* @0x1f71cc cmp r3, #0 */
/* @0x1f71d0 str r3, [r4, #0x18] */
/* @0x1f71d4 beq 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f71d8 ldr r1, [r3, #0x8] */
/* @0x1f71dc ldr r2, [r3] */
/* @0x1f71e0 cmp r1, #0 */
/* @0x1f71e4 streq r7, [r3, #0x8] */
/* @0x1f71e8 add r2, r2, #1 */
/* @0x1f71ec str r2, [r3] */
/* @0x1f71f0 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8> */
/* @0x1f71f4 ldr r3, [r5, #0x8] */
/* @0x1f71f8 cmp r3, #0 */
/* @0x1f71fc ldrne r2, [r3, #0x4] */
/* @0x1f7200 addne r2, r2, #1 */
/* @0x1f7204 strne r2, [r3, #0x4] */
/* @0x1f7208 b 0x1f70f4 <_ZN9RVariable6AssignERKS_+0x174> */
/* @0x1f720c ldr r3, [r5, #0x8] */
/* @0x1f7210 str r3, [r4, #0x8] */
/* @0x1f7214 ldr r3, [r5, #0x8] */
/* @0x1f7218 cmp r3, #0 */
/* @0x1f721c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1f7220 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f7224 ldr r1, [r5, #0x8] */
/* @0x1f7228 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1f722c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f7230 ldr r3, [r5, #0x8] */
/* @0x1f7234 cmp r3, #0 */
/* @0x1f7238 str r3, [r4, #0x8] */
/* @0x1f723c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1f7240 ldr r1, [r3, #0x8] */
/* @0x1f7244 ldr r2, [r3] */
/* @0x1f7248 cmp r1, #0 */
/* @0x1f724c streq r7, [r3, #0x8] */
/* @0x1f7250 add r2, r2, #1 */
/* @0x1f7254 str r2, [r3] */
/* @0x1f7258 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f725c ldr r0, [r6] */
/* @0x1f7260 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7264 str r8, [r6] */
/* @0x1f7268 str r8, [r6, #0x8] */
/* @0x1f726c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7270 ldr r8, [r6, #0x4] */
/* @0x1f7274 sub r8, r8, #1 */
/* @0x1f7278 str r8, [r6, #0x4] */
/* @0x1f727c cmp r8, #0 */
/* @0x1f7280 beq 0x1f72e4 <_ZN9RVariable6AssignERKS_+0x364> */
/* @0x1f7284 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f7288 mov r0, r6 */
/* @0x1f728c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7290 b 0x1f7148 <_ZN9RVariable6AssignERKS_+0x1c8> */
/* @0x1f7294 ldr r0, [r6] */
/* @0x1f7298 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f729c str r8, [r6] */
/* @0x1f72a0 str r8, [r6, #0x8] */
/* @0x1f72a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f72a8 ldr r8, [r6, #0x4] */
/* @0x1f72ac sub r8, r8, #1 */
/* @0x1f72b0 str r8, [r6, #0x4] */
/* @0x1f72b4 cmp r8, #0 */
/* @0x1f72b8 beq 0x1f731c <_ZN9RVariable6AssignERKS_+0x39c> */
/* @0x1f72bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f72c0 mov r0, r6 */
/* @0x1f72c4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f72c8 b 0x1f717c <_ZN9RVariable6AssignERKS_+0x1fc> */
/* @0x1f72cc mov r0, r7 */
/* @0x1f72d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f72d4 b 0x1f6fc8 <_ZN9RVariable6AssignERKS_+0x48> */
/* @0x1f72d8 mov r0, r7 */
/* @0x1f72dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f72e0 b 0x1f7078 <_ZN9RVariable6AssignERKS_+0xf8> */
/* @0x1f72e4 ldr r0, [r6] */
/* @0x1f72e8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f72ec str r8, [r6] */
/* @0x1f72f0 str r8, [r6, #0x8] */
/* @0x1f72f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f72f8 ldr r8, [r6, #0x4] */
/* @0x1f72fc sub r8, r8, #1 */
/* @0x1f7300 str r8, [r6, #0x4] */
/* @0x1f7304 cmp r8, #0 */
/* @0x1f7308 beq 0x1f7354 <_ZN9RVariable6AssignERKS_+0x3d4> */
/* @0x1f730c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f7310 mov r0, r6 */
/* @0x1f7314 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7318 b 0x1f7284 <_ZN9RVariable6AssignERKS_+0x304> */
/* @0x1f731c ldr r0, [r6] */
/* @0x1f7320 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7324 str r8, [r6] */
/* @0x1f7328 str r8, [r6, #0x8] */
/* @0x1f732c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7330 ldr r8, [r6, #0x4] */
/* @0x1f7334 sub r8, r8, #1 */
/* @0x1f7338 str r8, [r6, #0x4] */
/* @0x1f733c cmp r8, #0 */
/* @0x1f7340 beq 0x1f73ac <_ZN9RVariable6AssignERKS_+0x42c> */
/* @0x1f7344 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f7348 mov r0, r6 */
/* @0x1f734c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7350 b 0x1f72bc <_ZN9RVariable6AssignERKS_+0x33c> */
/* @0x1f7354 ldr r0, [r6] */
/* @0x1f7358 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f735c str r8, [r6] */
/* @0x1f7360 str r8, [r6, #0x8] */
/* @0x1f7364 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7368 ldr r8, [r6, #0x4] */
/* @0x1f736c sub r8, r8, #1 */
/* @0x1f7370 str r8, [r6, #0x4] */
/* @0x1f7374 cmp r8, #0 */
/* @0x1f7378 bne 0x1f739c <_ZN9RVariable6AssignERKS_+0x41c> */
/* @0x1f737c ldr r0, [r6] */
/* @0x1f7380 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7384 mov r0, r6 */
/* @0x1f7388 str r8, [r6] */
/* @0x1f738c str r8, [r6, #0x8] */
/* @0x1f7390 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f7394 mov r0, r6 */
/* @0x1f7398 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f739c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f73a0 mov r0, r6 */
/* @0x1f73a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f73a8 b 0x1f730c <_ZN9RVariable6AssignERKS_+0x38c> */
/* @0x1f73ac ldr r0, [r6] */
/* @0x1f73b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f73b4 str r8, [r6] */
/* @0x1f73b8 str r8, [r6, #0x8] */
/* @0x1f73bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f73c0 ldr r8, [r6, #0x4] */
/* @0x1f73c4 sub r8, r8, #1 */
/* @0x1f73c8 str r8, [r6, #0x4] */
/* @0x1f73cc cmp r8, #0 */
/* @0x1f73d0 bne 0x1f73f4 <_ZN9RVariable6AssignERKS_+0x474> */
/* @0x1f73d4 ldr r0, [r6] */
/* @0x1f73d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f73dc mov r0, r6 */
/* @0x1f73e0 str r8, [r6] */
/* @0x1f73e4 str r8, [r6, #0x8] */
/* @0x1f73e8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f73ec mov r0, r6 */
/* @0x1f73f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f73f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f73f8 mov r0, r6 */
/* @0x1f73fc bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7400 b 0x1f7344 <_ZN9RVariable6AssignERKS_+0x3c4> */

/* ── FUNC 0x1f7404 · RVariable::RVariable(RVariable const*) · size=1164 · insn=291 */
/* @0x1f7404 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f7408 mov r5, r1 */
/* @0x1f740c ldr r1, [r0, #0x24] */
/* @0x1f7410 mov r3, #0 */
/* @0x1f7414 mov r4, r0 */
/* @0x1f7418 add r7, r0, #24 */
/* @0x1f741c bic r2, r1, #-16777216 */
/* @0x1f7420 str r3, [r0] */
/* @0x1f7424 cmp r2, #1 */
/* @0x1f7428 str r3, [r0, #0x4] */
/* @0x1f742c beq 0x1f75b0 <_ZN9RVariableC2EPKS_+0x1ac> */
/* @0x1f7430 cmp r2, #2 */
/* @0x1f7434 bne 0x1f745c <_ZN9RVariableC2EPKS_+0x58> */
/* @0x1f7438 sub r1, r1, #1 */
/* @0x1f743c bic r1, r1, #-16777216 */
/* @0x1f7440 bic r1, r1, #3 */
/* @0x1f7444 cmp r1, #0 */
/* @0x1f7448 beq 0x1f7758 <_ZN9RVariableC2EPKS_+0x354> */
/* @0x1f744c mov r2, #0 */
/* @0x1f7450 mov r3, #5 */
/* @0x1f7454 str r2, [r4, #0x20] */
/* @0x1f7458 str r3, [r4, #0x24] */
/* @0x1f745c ldr r3, [r5, #0x24] */
/* @0x1f7460 mov r1, #0 */
/* @0x1f7464 ldr r2, [r5, #0x20] */
/* @0x1f7468 str r1, [r4, #0x18] */
/* @0x1f746c str r3, [r4, #0x24] */
/* @0x1f7470 ldr r3, [r5, #0x24] */
/* @0x1f7474 str r2, [r4, #0x20] */
/* @0x1f7478 bic r3, r3, #-16777216 */
/* @0x1f747c cmp r3, #14 */
/* @0x1f7480 addls pc, pc, r3, lsl #2 */
/* @0x1f7484 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f7488 b 0x1f7584 <_ZN9RVariableC2EPKS_+0x180> */
/* @0x1f748c b 0x1f763c <_ZN9RVariableC2EPKS_+0x238> */
/* @0x1f7490 b 0x1f7654 <_ZN9RVariableC2EPKS_+0x250> */
/* @0x1f7494 b 0x1f74c4 <_ZN9RVariableC2EPKS_+0xc0> */
/* @0x1f7498 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f749c b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f74a0 b 0x1f7618 <_ZN9RVariableC2EPKS_+0x214> */
/* @0x1f74a4 b 0x1f74c4 <_ZN9RVariableC2EPKS_+0xc0> */
/* @0x1f74a8 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f74ac b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f74b0 b 0x1f7584 <_ZN9RVariableC2EPKS_+0x180> */
/* @0x1f74b4 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f74b8 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f74bc b 0x1f7584 <_ZN9RVariableC2EPKS_+0x180> */
/* @0x1f74c0 b 0x1f74c4 <_ZN9RVariableC2EPKS_+0xc0> */
/* @0x1f74c4 ldr r3, [r5, #0x18] */
/* @0x1f74c8 str r3, [r4, #0x18] */
/* @0x1f74cc ldr r2, [r4, #0x14] */
/* @0x1f74d0 add r7, r4, #8 */
/* @0x1f74d4 bic r3, r2, #-16777216 */
/* @0x1f74d8 cmp r3, #1 */
/* @0x1f74dc beq 0x1f75e4 <_ZN9RVariableC2EPKS_+0x1e0> */
/* @0x1f74e0 cmp r3, #2 */
/* @0x1f74e4 bne 0x1f750c <_ZN9RVariableC2EPKS_+0x108> */
/* @0x1f74e8 sub r2, r2, #1 */
/* @0x1f74ec bic r2, r2, #-16777216 */
/* @0x1f74f0 bic r2, r2, #3 */
/* @0x1f74f4 cmp r2, #0 */
/* @0x1f74f8 beq 0x1f7764 <_ZN9RVariableC2EPKS_+0x360> */
/* @0x1f74fc mov r2, #0 */
/* @0x1f7500 mov r3, #5 */
/* @0x1f7504 str r2, [r4, #0x10] */
/* @0x1f7508 str r3, [r4, #0x14] */
/* @0x1f750c ldr r3, [r5, #0x14] */
/* @0x1f7510 mov r1, #0 */
/* @0x1f7514 ldr r2, [r5, #0x10] */
/* @0x1f7518 str r1, [r4, #0x8] */
/* @0x1f751c str r3, [r4, #0x14] */
/* @0x1f7520 ldr r3, [r5, #0x14] */
/* @0x1f7524 str r2, [r4, #0x10] */
/* @0x1f7528 bic r3, r3, #-16777216 */
/* @0x1f752c cmp r3, #14 */
/* @0x1f7530 addls pc, pc, r3, lsl #2 */
/* @0x1f7534 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f7538 b 0x1f7598 <_ZN9RVariableC2EPKS_+0x194> */
/* @0x1f753c b 0x1f7680 <_ZN9RVariableC2EPKS_+0x27c> */
/* @0x1f7540 b 0x1f76bc <_ZN9RVariableC2EPKS_+0x2b8> */
/* @0x1f7544 b 0x1f7574 <_ZN9RVariableC2EPKS_+0x170> */
/* @0x1f7548 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f754c b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f7550 b 0x1f7698 <_ZN9RVariableC2EPKS_+0x294> */
/* @0x1f7554 b 0x1f7574 <_ZN9RVariableC2EPKS_+0x170> */
/* @0x1f7558 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f755c b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f7560 b 0x1f7598 <_ZN9RVariableC2EPKS_+0x194> */
/* @0x1f7564 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f7568 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f756c b 0x1f7598 <_ZN9RVariableC2EPKS_+0x194> */
/* @0x1f7570 b 0x1f7574 <_ZN9RVariableC2EPKS_+0x170> */
/* @0x1f7574 ldr r3, [r5, #0x8] */
/* @0x1f7578 str r3, [r4, #0x8] */
/* @0x1f757c mov r0, r4 */
/* @0x1f7580 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f7584 ldr r2, [r5, #0x18] */
/* @0x1f7588 ldr r3, [r5, #0x1c] */
/* @0x1f758c str r2, [r4, #0x18] */
/* @0x1f7590 str r3, [r4, #0x1c] */
/* @0x1f7594 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f7598 ldr r2, [r5, #0x8] */
/* @0x1f759c mov r0, r4 */
/* @0x1f75a0 ldr r3, [r5, #0xc] */
/* @0x1f75a4 str r2, [r4, #0x8] */
/* @0x1f75a8 str r3, [r4, #0xc] */
/* @0x1f75ac pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f75b0 ldr r6, [r0, #0x18] */
/* @0x1f75b4 cmp r6, #0 */
/* @0x1f75b8 beq 0x1f75d8 <_ZN9RVariableC2EPKS_+0x1d4> */
/* @0x1f75bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f75c0 ldr r8, [r6, #0x4] */
/* @0x1f75c4 sub r8, r8, #1 */
/* @0x1f75c8 str r8, [r6, #0x4] */
/* @0x1f75cc cmp r8, #0 */
/* @0x1f75d0 beq 0x1f76e8 <_ZN9RVariableC2EPKS_+0x2e4> */
/* @0x1f75d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f75d8 mov r3, #0 */
/* @0x1f75dc str r3, [r4, #0x18] */
/* @0x1f75e0 b 0x1f745c <_ZN9RVariableC2EPKS_+0x58> */
/* @0x1f75e4 ldr r6, [r4, #0x8] */
/* @0x1f75e8 cmp r6, #0 */
/* @0x1f75ec beq 0x1f760c <_ZN9RVariableC2EPKS_+0x208> */
/* @0x1f75f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f75f4 ldr r8, [r6, #0x4] */
/* @0x1f75f8 sub r8, r8, #1 */
/* @0x1f75fc str r8, [r6, #0x4] */
/* @0x1f7600 cmp r8, #0 */
/* @0x1f7604 beq 0x1f7720 <_ZN9RVariableC2EPKS_+0x31c> */
/* @0x1f7608 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f760c mov r3, #0 */
/* @0x1f7610 str r3, [r4, #0x8] */
/* @0x1f7614 b 0x1f750c <_ZN9RVariableC2EPKS_+0x108> */
/* @0x1f7618 ldr r3, [r5, #0x18] */
/* @0x1f761c str r3, [r4, #0x18] */
/* @0x1f7620 ldr r3, [r5, #0x18] */
/* @0x1f7624 cmp r3, #0 */
/* @0x1f7628 beq 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f762c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f7630 ldr r1, [r5, #0x18] */
/* @0x1f7634 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f7638 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f763c ldr r3, [r5, #0x18] */
/* @0x1f7640 cmp r3, #0 */
/* @0x1f7644 ldrne r2, [r3, #0x4] */
/* @0x1f7648 addne r2, r2, #1 */
/* @0x1f764c strne r2, [r3, #0x4] */
/* @0x1f7650 b 0x1f74c8 <_ZN9RVariableC2EPKS_+0xc4> */
/* @0x1f7654 ldr r3, [r5, #0x18] */
/* @0x1f7658 cmp r3, #0 */
/* @0x1f765c str r3, [r4, #0x18] */
/* @0x1f7660 beq 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f7664 ldr r1, [r3, #0x8] */
/* @0x1f7668 ldr r2, [r3] */
/* @0x1f766c cmp r1, #0 */
/* @0x1f7670 streq r7, [r3, #0x8] */
/* @0x1f7674 add r2, r2, #1 */
/* @0x1f7678 str r2, [r3] */
/* @0x1f767c b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8> */
/* @0x1f7680 ldr r3, [r5, #0x8] */
/* @0x1f7684 cmp r3, #0 */
/* @0x1f7688 ldrne r2, [r3, #0x4] */
/* @0x1f768c addne r2, r2, #1 */
/* @0x1f7690 strne r2, [r3, #0x4] */
/* @0x1f7694 b 0x1f7578 <_ZN9RVariableC2EPKS_+0x174> */
/* @0x1f7698 ldr r3, [r5, #0x8] */
/* @0x1f769c str r3, [r4, #0x8] */
/* @0x1f76a0 ldr r3, [r5, #0x8] */
/* @0x1f76a4 cmp r3, #0 */
/* @0x1f76a8 beq 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f76ac bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f76b0 ldr r1, [r5, #0x8] */
/* @0x1f76b4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f76b8 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f76bc ldr r3, [r5, #0x8] */
/* @0x1f76c0 cmp r3, #0 */
/* @0x1f76c4 str r3, [r4, #0x8] */
/* @0x1f76c8 beq 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f76cc ldr r1, [r3, #0x8] */
/* @0x1f76d0 ldr r2, [r3] */
/* @0x1f76d4 cmp r1, #0 */
/* @0x1f76d8 streq r7, [r3, #0x8] */
/* @0x1f76dc add r2, r2, #1 */
/* @0x1f76e0 str r2, [r3] */
/* @0x1f76e4 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178> */
/* @0x1f76e8 ldr r0, [r6] */
/* @0x1f76ec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f76f0 str r8, [r6] */
/* @0x1f76f4 str r8, [r6, #0x8] */
/* @0x1f76f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f76fc ldr r8, [r6, #0x4] */
/* @0x1f7700 sub r8, r8, #1 */
/* @0x1f7704 str r8, [r6, #0x4] */
/* @0x1f7708 cmp r8, #0 */
/* @0x1f770c beq 0x1f7770 <_ZN9RVariableC2EPKS_+0x36c> */
/* @0x1f7710 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f7714 mov r0, r6 */
/* @0x1f7718 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f771c b 0x1f75d4 <_ZN9RVariableC2EPKS_+0x1d0> */
/* @0x1f7720 ldr r0, [r6] */
/* @0x1f7724 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7728 str r8, [r6] */
/* @0x1f772c str r8, [r6, #0x8] */
/* @0x1f7730 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7734 ldr r8, [r6, #0x4] */
/* @0x1f7738 sub r8, r8, #1 */
/* @0x1f773c str r8, [r6, #0x4] */
/* @0x1f7740 cmp r8, #0 */
/* @0x1f7744 beq 0x1f77a8 <_ZN9RVariableC2EPKS_+0x3a4> */
/* @0x1f7748 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f774c mov r0, r6 */
/* @0x1f7750 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7754 b 0x1f7608 <_ZN9RVariableC2EPKS_+0x204> */
/* @0x1f7758 mov r0, r7 */
/* @0x1f775c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f7760 b 0x1f744c <_ZN9RVariableC2EPKS_+0x48> */
/* @0x1f7764 mov r0, r7 */
/* @0x1f7768 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f776c b 0x1f74fc <_ZN9RVariableC2EPKS_+0xf8> */
/* @0x1f7770 ldr r0, [r6] */
/* @0x1f7774 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7778 str r8, [r6] */
/* @0x1f777c str r8, [r6, #0x8] */
/* @0x1f7780 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f7784 ldr r8, [r6, #0x4] */
/* @0x1f7788 sub r8, r8, #1 */
/* @0x1f778c str r8, [r6, #0x4] */
/* @0x1f7790 cmp r8, #0 */
/* @0x1f7794 beq 0x1f77e0 <_ZN9RVariableC2EPKS_+0x3dc> */
/* @0x1f7798 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f779c mov r0, r6 */
/* @0x1f77a0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f77a4 b 0x1f7710 <_ZN9RVariableC2EPKS_+0x30c> */
/* @0x1f77a8 ldr r0, [r6] */
/* @0x1f77ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f77b0 str r8, [r6] */
/* @0x1f77b4 str r8, [r6, #0x8] */
/* @0x1f77b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f77bc ldr r8, [r6, #0x4] */
/* @0x1f77c0 sub r8, r8, #1 */
/* @0x1f77c4 str r8, [r6, #0x4] */
/* @0x1f77c8 cmp r8, #0 */
/* @0x1f77cc beq 0x1f7838 <_ZN9RVariableC2EPKS_+0x434> */
/* @0x1f77d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f77d4 mov r0, r6 */
/* @0x1f77d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f77dc b 0x1f7748 <_ZN9RVariableC2EPKS_+0x344> */
/* @0x1f77e0 ldr r0, [r6] */
/* @0x1f77e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f77e8 str r8, [r6] */
/* @0x1f77ec str r8, [r6, #0x8] */
/* @0x1f77f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f77f4 ldr r8, [r6, #0x4] */
/* @0x1f77f8 sub r8, r8, #1 */
/* @0x1f77fc str r8, [r6, #0x4] */
/* @0x1f7800 cmp r8, #0 */
/* @0x1f7804 bne 0x1f7828 <_ZN9RVariableC2EPKS_+0x424> */
/* @0x1f7808 ldr r0, [r6] */
/* @0x1f780c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7810 mov r0, r6 */
/* @0x1f7814 str r8, [r6] */
/* @0x1f7818 str r8, [r6, #0x8] */
/* @0x1f781c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f7820 mov r0, r6 */
/* @0x1f7824 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7828 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f782c mov r0, r6 */
/* @0x1f7830 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7834 b 0x1f7798 <_ZN9RVariableC2EPKS_+0x394> */
/* @0x1f7838 ldr r0, [r6] */
/* @0x1f783c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7840 str r8, [r6] */
/* @0x1f7844 str r8, [r6, #0x8] */
/* @0x1f7848 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f784c ldr r8, [r6, #0x4] */
/* @0x1f7850 sub r8, r8, #1 */
/* @0x1f7854 str r8, [r6, #0x4] */
/* @0x1f7858 cmp r8, #0 */
/* @0x1f785c bne 0x1f7880 <_ZN9RVariableC2EPKS_+0x47c> */
/* @0x1f7860 ldr r0, [r6] */
/* @0x1f7864 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f7868 mov r0, r6 */
/* @0x1f786c str r8, [r6] */
/* @0x1f7870 str r8, [r6, #0x8] */
/* @0x1f7874 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f7878 mov r0, r6 */
/* @0x1f787c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f7880 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f7884 mov r0, r6 */
/* @0x1f7888 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f788c b 0x1f77d0 <_ZN9RVariableC2EPKS_+0x3cc> */

/* ── FUNC 0x1f7404 · RVariable::RVariable(RVariable const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f7890 · CVariableList::Alloc(RVariable const*) · size=116 · insn=29 */
/* @0x1f7890 ldr r3, [pc, #0x68] */
/* @0x1f7894 push {r4, r5, r6, lr} */
/* @0x1f7898 ldr r3, [pc, r3] */
/* @0x1f789c sub sp, sp, #48 */
/* @0x1f78a0 mov r5, r0 */
/* @0x1f78a4 ldr r4, [r3] */
/* @0x1f78a8 cmp r4, #0 */
/* @0x1f78ac beq 0x1f78e8 <_ZN13CVariableList5AllocEPK9RVariable+0x58> */
/* @0x1f78b0 ldr r2, [r4, #0x4] */
/* @0x1f78b4 add r6, sp, #4 */
/* @0x1f78b8 mov r1, r0 */
/* @0x1f78bc mov r0, r6 */
/* @0x1f78c0 str r2, [r3] */
/* @0x1f78c4 bl 0x1f7404 <_ZN9RVariableC2EPKS_> */
/* @0x1f78c8 mov r0, r4 */
/* @0x1f78cc mov r1, r6 */
/* @0x1f78d0 bl 0x1f6f80 <_ZN9RVariable6AssignERKS_> */
/* @0x1f78d4 ldr r3, [r5, #0x28] */
/* @0x1f78d8 mov r0, r4 */
/* @0x1f78dc str r3, [r4, #0x28] */
/* @0x1f78e0 add sp, sp, #48 */
/* @0x1f78e4 pop {r4, r5, r6, pc} */
/* @0x1f78e8 mov r0, #44 */
/* @0x1f78ec bl 0x27c524 <_Znwj> */
/* @0x1f78f0 mov r1, r5 */
/* @0x1f78f4 mov r4, r0 */
/* @0x1f78f8 bl 0x1f7404 <_ZN9RVariableC2EPKS_> */
/* @0x1f78fc b 0x1f78d4 <_ZN13CVariableList5AllocEPK9RVariable+0x44> */
/* @0x1f7900 mulseq pc, r12, r5 */

/* ── FUNC 0x1f7904 · CVariableList::Assign(CVariableList*) · size=168 · insn=42 */
/* @0x1f7904 push {r3, r4, r5, r6, r7, lr} */
/* @0x1f7908 mov r5, r1 */
/* @0x1f790c mov r7, r0 */
/* @0x1f7910 bl 0x1f662c <_ZN13CVariableList5ClearEv> */
/* @0x1f7914 adds r4, r5, #4 */
/* @0x1f7918 addne r4, r5, #20 */
/* @0x1f791c beq 0x1f7988 <_ZN13CVariableList6AssignEPS_+0x84> */
/* @0x1f7920 cmp r4, r5 */
/* @0x1f7924 add r6, r5, #4 */
/* @0x1f7928 beq 0x1f7934 <_ZN13CVariableList6AssignEPS_+0x30> */
/* @0x1f792c cmp r4, r6 */
/* @0x1f7930 bne 0x1f7994 <_ZN13CVariableList6AssignEPS_+0x90> */
/* @0x1f7934 mov r6, r4 */
/* @0x1f7938 mov r5, #0 */
/* @0x1f793c cmp r5, #0 */
/* @0x1f7940 beq 0x1f7984 <_ZN13CVariableList6AssignEPS_+0x80> */
/* @0x1f7944 mov r0, r5 */
/* @0x1f7948 bl 0x1f7890 <_ZN13CVariableList5AllocEPK9RVariable> */
/* @0x1f794c mov r1, r0 */
/* @0x1f7950 mov r0, r7 */
/* @0x1f7954 bl 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable> */
/* @0x1f7958 ldr r5, [r5] */
/* @0x1f795c cmp r5, #0 */
/* @0x1f7960 add r3, r6, #4 */
/* @0x1f7964 bne 0x1f793c <_ZN13CVariableList6AssignEPS_+0x38> */
/* @0x1f7968 cmp r4, r6 */
/* @0x1f796c beq 0x1f79a8 <_ZN13CVariableList6AssignEPS_+0xa4> */
/* @0x1f7970 cmp r3, r4 */
/* @0x1f7974 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1f7978 ldr r5, [r6, #0x4] */
/* @0x1f797c mov r6, r3 */
/* @0x1f7980 b 0x1f795c <_ZN13CVariableList6AssignEPS_+0x58> */
/* @0x1f7984 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1f7988 mov r6, r4 */
/* @0x1f798c mov r5, r4 */
/* @0x1f7990 b 0x1f793c <_ZN13CVariableList6AssignEPS_+0x38> */
/* @0x1f7994 ldr r5, [r5, #0x4] */
/* @0x1f7998 cmp r5, #0 */
/* @0x1f799c bne 0x1f793c <_ZN13CVariableList6AssignEPS_+0x38> */
/* @0x1f79a0 mov r5, r6 */
/* @0x1f79a4 b 0x1f7920 <_ZN13CVariableList6AssignEPS_+0x1c> */
/* @0x1f79a8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1f79ac · GV_ArgumentRelative(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f79ac ldr r3, [pc, #0x34] */
/* @0x1f79b0 mov r1, #0 */
/* @0x1f79b4 push {r4, r5} */
/* @0x1f79b8 ldr r3, [pc, r3] */
/* @0x1f79bc str r1, [r2, #0xc] */
/* @0x1f79c0 mov r0, #1 */
/* @0x1f79c4 ldrb r4, [r3] */
/* @0x1f79c8 vmov s15, r4 */
/* @0x1f79cc vcvt.f64.s32 d7, s15 */
/* @0x1f79d0 vmov r4, r5, d7 */
/* @0x1f79d4 vmov r1, s14 */
/* @0x1f79d8 mov r3, r5 */
/* @0x1f79dc pop {r4, r5} */
/* @0x1f79e0 stm r2, {r1, r3} */
/* @0x1f79e4 bx lr */
/* @0x1f79e8 andseq r6, pc, r4, lsl #3 */

/* ── FUNC 0x1f79ec · GV_Room(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f79ec ldr r3, [pc, #0x34] */
/* @0x1f79f0 mov r1, #0 */
/* @0x1f79f4 push {r4, r5} */
/* @0x1f79f8 ldr r3, [pc, r3] */
/* @0x1f79fc str r1, [r2, #0xc] */
/* @0x1f7a00 mov r0, #1 */
/* @0x1f7a04 ldr r4, [r3] */
/* @0x1f7a08 vmov s15, r4 */
/* @0x1f7a0c vcvt.f64.s32 d7, s15 */
/* @0x1f7a10 vmov r4, r5, d7 */
/* @0x1f7a14 vmov r1, s14 */
/* @0x1f7a18 mov r3, r5 */
/* @0x1f7a1c pop {r4, r5} */
/* @0x1f7a20 stm r2, {r1, r3} */
/* @0x1f7a24 bx lr */
/* @0x1f7a28 ldrsbeq r7, [pc], -r12 */

/* ── FUNC 0x1f7a2c · GV_TransitionKind(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f7a2c ldr r3, [pc, #0x34] */
/* @0x1f7a30 mov r1, #0 */
/* @0x1f7a34 push {r4, r5} */
/* @0x1f7a38 ldr r3, [pc, r3] */
/* @0x1f7a3c str r1, [r2, #0xc] */
/* @0x1f7a40 mov r0, #1 */
/* @0x1f7a44 ldr r4, [r3] */
/* @0x1f7a48 vmov s15, r4 */
/* @0x1f7a4c vcvt.f64.s32 d7, s15 */
/* @0x1f7a50 vmov r4, r5, d7 */
/* @0x1f7a54 vmov r1, s14 */
/* @0x1f7a58 mov r3, r5 */
/* @0x1f7a5c pop {r4, r5} */
/* @0x1f7a60 stm r2, {r1, r3} */
/* @0x1f7a64 bx lr */
/* @0x1f7a68 andseq r6, pc, r0, ror r6 */

/* ── FUNC 0x1f7a6c · GV_TransitionSteps(CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1f7a6c mov r3, #0 */
/* @0x1f7a70 mov r0, #1 */
/* @0x1f7a74 str r3, [r2, #0xc] */
/* @0x1f7a78 str r3, [r2] */
/* @0x1f7a7c str r3, [r2, #0x4] */
/* @0x1f7a80 bx lr */

/* ── FUNC 0x1f7a84 · GV_Score(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f7a84 ldr r3, [pc, #0x34] */
/* @0x1f7a88 mov r1, #0 */
/* @0x1f7a8c push {r4, r5} */
/* @0x1f7a90 ldr r3, [pc, r3] */
/* @0x1f7a94 str r1, [r2, #0xc] */
/* @0x1f7a98 mov r0, #1 */
/* @0x1f7a9c ldr r4, [r3] */
/* @0x1f7aa0 vmov s15, r4 */
/* @0x1f7aa4 vcvt.f64.s32 d7, s15 */
/* @0x1f7aa8 vmov r4, r5, d7 */
/* @0x1f7aac vmov r1, s14 */
/* @0x1f7ab0 mov r3, r5 */
/* @0x1f7ab4 pop {r4, r5} */
/* @0x1f7ab8 stm r2, {r1, r3} */
/* @0x1f7abc bx lr */
/* @0x1f7ac0 ldrsheq r6, [pc], -r4 */

/* ── FUNC 0x1f7ac4 · GV_Lives(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f7ac4 ldr r3, [pc, #0x34] */
/* @0x1f7ac8 mov r1, #0 */
/* @0x1f7acc push {r4, r5} */
/* @0x1f7ad0 ldr r3, [pc, r3] */
/* @0x1f7ad4 str r1, [r2, #0xc] */
/* @0x1f7ad8 mov r0, #1 */
/* @0x1f7adc ldr r4, [r3] */
/* @0x1f7ae0 vmov s15, r4 */
/* @0x1f7ae4 vcvt.f64.s32 d7, s15 */
/* @0x1f7ae8 vmov r4, r5, d7 */
/* @0x1f7aec vmov r1, s14 */
/* @0x1f7af0 mov r3, r5 */
/* @0x1f7af4 pop {r4, r5} */
/* @0x1f7af8 stm r2, {r1, r3} */
/* @0x1f7afc bx lr */
/* @0x1f7b00 andseq r7, pc, r0, lsl #18 */

/* ── FUNC 0x1f7b04 · GV_Health(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1f7b04 ldr r3, [pc, #0x20] */
/* @0x1f7b08 mov r1, #0 */
/* @0x1f7b0c str r1, [r2, #0xc] */
/* @0x1f7b10 mov r0, #1 */
/* @0x1f7b14 ldr r3, [pc, r3] */
/* @0x1f7b18 ldr r1, [r3] */
/* @0x1f7b1c str r1, [r2] */
/* @0x1f7b20 ldr r3, [r3, #0x4] */
/* @0x1f7b24 str r3, [r2, #0x4] */
/* @0x1f7b28 bx lr */
/* @0x1f7b2c andseq r7, pc, r4, asr #17 */

/* ── FUNC 0x1f7b30 · GV_GameId(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f7b30 ldr r3, [pc, #0x34] */
/* @0x1f7b34 mov r1, #0 */
/* @0x1f7b38 push {r4, r5} */
/* @0x1f7b3c ldr r3, [pc, r3] */
/* @0x1f7b40 str r1, [r2, #0xc] */
/* @0x1f7b44 mov r0, #1 */
/* @0x1f7b48 ldr r4, [r3] */
/* @0x1f7b4c vmov s15, r4 */
/* @0x1f7b50 vcvt.f64.s32 d7, s15 */
/* @0x1f7b54 vmov r4, r5, d7 */
/* @0x1f7b58 vmov r1, s14 */
/* @0x1f7b5c mov r3, r5 */
/* @0x1f7b60 pop {r4, r5} */
/* @0x1f7b64 stm r2, {r1, r3} */
/* @0x1f7b68 bx lr */
/* @0x1f7b6c ldrsbeq r8, [pc], -r8 */

/* ── FUNC 0x1f7b70 · GV_InstanceCount(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f7b70 ldr r3, [pc, #0x38] */
/* @0x1f7b74 mov r1, #0 */
/* @0x1f7b78 push {r4, r5} */
/* @0x1f7b7c ldr r3, [pc, r3] */
/* @0x1f7b80 str r1, [r2, #0xc] */
/* @0x1f7b84 mov r0, #1 */
/* @0x1f7b88 ldr r3, [r3] */
/* @0x1f7b8c ldr r4, [r3, #0x88] */
/* @0x1f7b90 vmov s15, r4 */
/* @0x1f7b94 vcvt.f64.s32 d7, s15 */
/* @0x1f7b98 vmov r4, r5, d7 */
/* @0x1f7b9c vmov r1, s14 */
/* @0x1f7ba0 mov r3, r5 */
/* @0x1f7ba4 pop {r4, r5} */
/* @0x1f7ba8 stm r2, {r1, r3} */
/* @0x1f7bac bx lr */
/* @0x1f7bb0 andseq r5, pc, r12, lsr #27 */

/* ── FUNC 0x1f7bb4 · GV_RoomWidth(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f7bb4 ldr r3, [pc, #0x38] */
/* @0x1f7bb8 mov r1, #0 */
/* @0x1f7bbc push {r4, r5} */
/* @0x1f7bc0 ldr r3, [pc, r3] */
/* @0x1f7bc4 str r1, [r2, #0xc] */
/* @0x1f7bc8 mov r0, #1 */
/* @0x1f7bcc ldr r3, [r3] */
/* @0x1f7bd0 ldr r4, [r3, #0x10] */
/* @0x1f7bd4 vmov s15, r4 */
/* @0x1f7bd8 vcvt.f64.s32 d7, s15 */
/* @0x1f7bdc vmov r4, r5, d7 */
/* @0x1f7be0 vmov r1, s14 */
/* @0x1f7be4 mov r3, r5 */
/* @0x1f7be8 pop {r4, r5} */
/* @0x1f7bec stm r2, {r1, r3} */
/* @0x1f7bf0 bx lr */
/* @0x1f7bf4 andseq r5, pc, r8, ror #26 */

/* ── FUNC 0x1f7bf8 · GV_RoomHeight(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f7bf8 ldr r3, [pc, #0x38] */
/* @0x1f7bfc mov r1, #0 */
/* @0x1f7c00 push {r4, r5} */
/* @0x1f7c04 ldr r3, [pc, r3] */
/* @0x1f7c08 str r1, [r2, #0xc] */
/* @0x1f7c0c mov r0, #1 */
/* @0x1f7c10 ldr r3, [r3] */
/* @0x1f7c14 ldr r4, [r3, #0x14] */
/* @0x1f7c18 vmov s15, r4 */
/* @0x1f7c1c vcvt.f64.s32 d7, s15 */
/* @0x1f7c20 vmov r4, r5, d7 */
/* @0x1f7c24 vmov r1, s14 */
/* @0x1f7c28 mov r3, r5 */
/* @0x1f7c2c pop {r4, r5} */
/* @0x1f7c30 stm r2, {r1, r3} */
/* @0x1f7c34 bx lr */
/* @0x1f7c38 andseq r5, pc, r4, lsr #26 */

/* ── FUNC 0x1f7c3c · GV_RoomPersistent(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f7c3c ldr r3, [pc, #0x38] */
/* @0x1f7c40 mov r1, #0 */
/* @0x1f7c44 push {r4, r5} */
/* @0x1f7c48 ldr r3, [pc, r3] */
/* @0x1f7c4c str r1, [r2, #0xc] */
/* @0x1f7c50 mov r0, #1 */
/* @0x1f7c54 ldr r3, [r3] */
/* @0x1f7c58 ldrb r4, [r3, #0x18] */
/* @0x1f7c5c vmov s15, r4 */
/* @0x1f7c60 vcvt.f64.u32 d7, s15 */
/* @0x1f7c64 vmov r4, r5, d7 */
/* @0x1f7c68 vmov r1, s14 */
/* @0x1f7c6c mov r3, r5 */
/* @0x1f7c70 pop {r4, r5} */
/* @0x1f7c74 stm r2, {r1, r3} */
/* @0x1f7c78 bx lr */
/* @0x1f7c7c andseq r5, pc, r0, ror #25 */

/* ── FUNC 0x1f7c80 · GV_BackgroundColor(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f7c80 ldr r3, [pc, #0x38] */
/* @0x1f7c84 mov r1, #0 */
/* @0x1f7c88 push {r4, r5} */
/* @0x1f7c8c ldr r3, [pc, r3] */
/* @0x1f7c90 str r1, [r2, #0xc] */
/* @0x1f7c94 mov r0, #1 */
/* @0x1f7c98 ldr r3, [r3] */
/* @0x1f7c9c ldr r4, [r3, #0x1c] */
/* @0x1f7ca0 vmov s15, r4 */
/* @0x1f7ca4 vcvt.f64.u32 d7, s15 */
/* @0x1f7ca8 vmov r4, r5, d7 */
/* @0x1f7cac vmov r1, s14 */
/* @0x1f7cb0 mov r3, r5 */
/* @0x1f7cb4 pop {r4, r5} */
/* @0x1f7cb8 stm r2, {r1, r3} */
/* @0x1f7cbc bx lr */
/* @0x1f7cc0 mulseq pc, r12, r12 */

/* ── FUNC 0x1f7cc4 · GV_BackgroundShowColor(CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1f7cc4 ldr r3, [pc, #0x38] */
/* @0x1f7cc8 mov r1, #0 */
/* @0x1f7ccc push {r4, r5} */
/* @0x1f7cd0 ldr r3, [pc, r3] */
/* @0x1f7cd4 str r1, [r2, #0xc] */
/* @0x1f7cd8 mov r0, #1 */
/* @0x1f7cdc ldr r3, [r3] */
/* @0x1f7ce0 ldrb r4, [r3, #0x20] */
/* @0x1f7ce4 vmov s15, r4 */
/* @0x1f7ce8 vcvt.f64.u32 d7, s15 */
/* @0x1f7cec vmov r4, r5, d7 */
/* @0x1f7cf0 vmov r1, s14 */
/* @0x1f7cf4 mov r3, r5 */
/* @0x1f7cf8 pop {r4, r5} */
/* @0x1f7cfc stm r2, {r1, r3} */
/* @0x1f7d00 bx lr */
/* @0x1f7d04 andseq r5, pc, r8, asr r12 */

/* ── FUNC 0x1f7d08 · GV_BackgroundVisible(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f7d08 ldr r3, [pc, #0x48] */
/* @0x1f7d0c cmp r1, #7 */
/* @0x1f7d10 push {r4, r5} */
/* @0x1f7d14 ldr r3, [pc, r3] */
/* @0x1f7d18 movhi r1, #0 */
/* @0x1f7d1c mov r0, #0 */
/* @0x1f7d20 ldr r3, [r3] */
/* @0x1f7d24 str r0, [r2, #0xc] */
/* @0x1f7d28 mov r0, #1 */
/* @0x1f7d2c add r1, r3, r1, lsl #2 */
/* @0x1f7d30 ldr r3, [r1, #0x24] */
/* @0x1f7d34 ldrb r4, [r3] */
/* @0x1f7d38 vmov s15, r4 */
/* @0x1f7d3c vcvt.f64.u32 d7, s15 */
/* @0x1f7d40 vmov r4, r5, d7 */
/* @0x1f7d44 vmov r1, s14 */
/* @0x1f7d48 mov r3, r5 */
/* @0x1f7d4c pop {r4, r5} */
/* @0x1f7d50 stm r2, {r1, r3} */
/* @0x1f7d54 bx lr */
/* @0x1f7d58 andseq r5, pc, r4, lsl r12 */

/* ── FUNC 0x1f7d5c · GV_BackgroundForeground(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f7d5c ldr r3, [pc, #0x48] */
/* @0x1f7d60 cmp r1, #7 */
/* @0x1f7d64 push {r4, r5} */
/* @0x1f7d68 ldr r3, [pc, r3] */
/* @0x1f7d6c movhi r1, #0 */
/* @0x1f7d70 mov r0, #0 */
/* @0x1f7d74 ldr r3, [r3] */
/* @0x1f7d78 str r0, [r2, #0xc] */
/* @0x1f7d7c mov r0, #1 */
/* @0x1f7d80 add r1, r3, r1, lsl #2 */
/* @0x1f7d84 ldr r3, [r1, #0x24] */
/* @0x1f7d88 ldrb r4, [r3, #0x1] */
/* @0x1f7d8c vmov s15, r4 */
/* @0x1f7d90 vcvt.f64.u32 d7, s15 */
/* @0x1f7d94 vmov r4, r5, d7 */
/* @0x1f7d98 vmov r1, s14 */
/* @0x1f7d9c mov r3, r5 */
/* @0x1f7da0 pop {r4, r5} */
/* @0x1f7da4 stm r2, {r1, r3} */
/* @0x1f7da8 bx lr */
/* @0x1f7dac andseq r5, pc, r0, asr #23 */

/* ── FUNC 0x1f7db0 · GV_BackgroundIndex(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f7db0 ldr r3, [pc, #0x48] */
/* @0x1f7db4 cmp r1, #7 */
/* @0x1f7db8 push {r4, r5} */
/* @0x1f7dbc ldr r3, [pc, r3] */
/* @0x1f7dc0 movhi r1, #0 */
/* @0x1f7dc4 mov r0, #0 */
/* @0x1f7dc8 ldr r3, [r3] */
/* @0x1f7dcc str r0, [r2, #0xc] */
/* @0x1f7dd0 mov r0, #1 */
/* @0x1f7dd4 add r1, r3, r1, lsl #2 */
/* @0x1f7dd8 ldr r3, [r1, #0x24] */
/* @0x1f7ddc ldr r4, [r3, #0x4] */
/* @0x1f7de0 vmov s15, r4 */
/* @0x1f7de4 vcvt.f64.s32 d7, s15 */
/* @0x1f7de8 vmov r4, r5, d7 */
/* @0x1f7dec vmov r1, s14 */
/* @0x1f7df0 mov r3, r5 */
/* @0x1f7df4 pop {r4, r5} */
/* @0x1f7df8 stm r2, {r1, r3} */
/* @0x1f7dfc bx lr */
/* @0x1f7e00 andseq r5, pc, r12, ror #22 */

/* ── FUNC 0x1f7e04 · GV_BackgroundX(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f7e04 ldr r3, [pc, #0x44] */
/* @0x1f7e08 cmp r1, #7 */
/* @0x1f7e0c push {r4, r5} */
/* @0x1f7e10 ldr r3, [pc, r3] */
/* @0x1f7e14 movhi r1, #0 */
/* @0x1f7e18 mov r0, #0 */
/* @0x1f7e1c ldr r3, [r3] */
/* @0x1f7e20 str r0, [r2, #0xc] */
/* @0x1f7e24 mov r0, #1 */
/* @0x1f7e28 add r1, r3, r1, lsl #2 */
/* @0x1f7e2c ldr r3, [r1, #0x24] */
/* @0x1f7e30 vldr s15, [r3, #8] */
/* @0x1f7e34 vcvt.f64.f32 d6, s15 */
/* @0x1f7e38 vmov r4, r5, d6 */
/* @0x1f7e3c vmov r1, s12 */
/* @0x1f7e40 mov r3, r5 */
/* @0x1f7e44 pop {r4, r5} */
/* @0x1f7e48 stm r2, {r1, r3} */
/* @0x1f7e4c bx lr */
/* @0x1f7e50 andseq r5, pc, r8, lsl r11 */

/* ── FUNC 0x1f7e54 · GV_BackgroundY(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1f7e54 ldr r3, [pc, #0x44] */
/* @0x1f7e58 cmp r1, #7 */
/* @0x1f7e5c push {r4, r5} */
/* @0x1f7e60 ldr r3, [pc, r3] */
/* @0x1f7e64 movhi r1, #0 */
/* @0x1f7e68 mov r0, #0 */
/* @0x1f7e6c ldr r3, [r3] */
/* @0x1f7e70 str r0, [r2, #0xc] */
/* @0x1f7e74 mov r0, #1 */
/* @0x1f7e78 add r1, r3, r1, lsl #2 */
/* @0x1f7e7c ldr r3, [r1, #0x24] */
/* @0x1f7e80 vldr s15, [r3, #12] */
/* @0x1f7e84 vcvt.f64.f32 d6, s15 */
/* @0x1f7e88 vmov r4, r5, d6 */
/* @0x1f7e8c vmov r1, s12 */
/* @0x1f7e90 mov r3, r5 */
/* @0x1f7e94 pop {r4, r5} */
/* @0x1f7e98 stm r2, {r1, r3} */
/* @0x1f7e9c bx lr */
/* @0x1f7ea0 andseq r5, pc, r8, asr #21 */

/* ── FUNC 0x1f7ea4 · GV_BackgroundHTiled(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f7ea4 ldr r3, [pc, #0x48] */
/* @0x1f7ea8 cmp r1, #7 */
/* @0x1f7eac push {r4, r5} */
/* @0x1f7eb0 ldr r3, [pc, r3] */
/* @0x1f7eb4 movhi r1, #0 */
/* @0x1f7eb8 mov r0, #0 */
/* @0x1f7ebc ldr r3, [r3] */
/* @0x1f7ec0 str r0, [r2, #0xc] */
/* @0x1f7ec4 mov r0, #1 */
/* @0x1f7ec8 add r1, r3, r1, lsl #2 */
/* @0x1f7ecc ldr r3, [r1, #0x24] */
/* @0x1f7ed0 ldrb r4, [r3, #0x10] */
/* @0x1f7ed4 vmov s15, r4 */
/* @0x1f7ed8 vcvt.f64.u32 d7, s15 */
/* @0x1f7edc vmov r4, r5, d7 */
/* @0x1f7ee0 vmov r1, s14 */
/* @0x1f7ee4 mov r3, r5 */
/* @0x1f7ee8 pop {r4, r5} */
/* @0x1f7eec stm r2, {r1, r3} */
/* @0x1f7ef0 bx lr */
/* @0x1f7ef4 andseq r5, pc, r8, ror r10 */

/* ── FUNC 0x1f7ef8 · GV_BackgroundVTiled(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f7ef8 ldr r3, [pc, #0x48] */
/* @0x1f7efc cmp r1, #7 */
/* @0x1f7f00 push {r4, r5} */
/* @0x1f7f04 ldr r3, [pc, r3] */
/* @0x1f7f08 movhi r1, #0 */
/* @0x1f7f0c mov r0, #0 */
/* @0x1f7f10 ldr r3, [r3] */
/* @0x1f7f14 str r0, [r2, #0xc] */
/* @0x1f7f18 mov r0, #1 */
/* @0x1f7f1c add r1, r3, r1, lsl #2 */
/* @0x1f7f20 ldr r3, [r1, #0x24] */
/* @0x1f7f24 ldrb r4, [r3, #0x11] */
/* @0x1f7f28 vmov s15, r4 */
/* @0x1f7f2c vcvt.f64.u32 d7, s15 */
/* @0x1f7f30 vmov r4, r5, d7 */
/* @0x1f7f34 vmov r1, s14 */
/* @0x1f7f38 mov r3, r5 */
/* @0x1f7f3c pop {r4, r5} */
/* @0x1f7f40 stm r2, {r1, r3} */
/* @0x1f7f44 bx lr */
/* @0x1f7f48 andseq r5, pc, r4, lsr #20 */
