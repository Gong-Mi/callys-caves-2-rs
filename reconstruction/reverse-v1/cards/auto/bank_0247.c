/* libyoyo.so 覆盖卡组 0247
 * 函数 0x29a83c..0x29cb88，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x29a83c · ExecuteDebugScript(char*, VMBuffer*, RValue*) · size=520 · insn=130 */
/* @0x29a83c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29a840 mov r9, r1 */
/* @0x29a844 ldr r5, [pc, #0x1d0] */
/* @0x29a848 sub sp, sp, #124 */
/* @0x29a84c ldr r3, [pc, #0x1cc] */
/* @0x29a850 mov r6, r2 */
/* @0x29a854 add r5, pc, r5 */
/* @0x29a858 ldr r7, [r5, r3] */
/* @0x29a85c ldr r4, [r7] */
/* @0x29a860 cmp r4, #0 */
/* @0x29a864 movne lr, r4 */
/* @0x29a868 beq 0x29a9ec <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x1b0> */
/* @0x29a86c ldr r12, [pc, #0x1b0] */
/* @0x29a870 mov r3, #0 */
/* @0x29a874 mvn r2, #-16777216 */
/* @0x29a878 str r3, [r6] */
/* @0x29a87c str r3, [r6, #0x4] */
/* @0x29a880 mov r1, #1 */
/* @0x29a884 str r2, [r6, #0xc] */
/* @0x29a888 ldr r0, [pc, #0x198] */
/* @0x29a88c ldr r12, [r5, r12] */
/* @0x29a890 ldr r2, [pc, #0x194] */
/* @0x29a894 str r12, [sp, #0x10] */
/* @0x29a898 ldr r0, [r5, r0] */
/* @0x29a89c ldrb r11, [r12] */
/* @0x29a8a0 strb r1, [r12] */
/* @0x29a8a4 mov r12, #16384 */
/* @0x29a8a8 str r0, [sp, #0xc] */
/* @0x29a8ac ldrb r10, [r0] */
/* @0x29a8b0 strb r3, [r0] */
/* @0x29a8b4 mov r0, r12 */
/* @0x29a8b8 ldr r7, [r5, r2] */
/* @0x29a8bc mov r2, #202 */
/* @0x29a8c0 ldr r1, [pc, #0x168] */
/* @0x29a8c4 ldr r3, [r7] */
/* @0x29a8c8 add r1, pc, r1 */
/* @0x29a8cc cmp r3, #0 */
/* @0x29a8d0 ldrne lr, [r3, #0x14] */
/* @0x29a8d4 moveq r4, lr */
/* @0x29a8d8 ldrne r4, [r3, #0x18] */
/* @0x29a8dc ldr r3, [pc, #0x150] */
/* @0x29a8e0 ldr r3, [r5, r3] */
/* @0x29a8e4 str r12, [sp, #0x58] */
/* @0x29a8e8 str lr, [sp, #0x2c] */
/* @0x29a8ec str r3, [sp, #0x14] */
/* @0x29a8f0 mov r3, #1 */
/* @0x29a8f4 ldr r12, [sp, #0x14] */
/* @0x29a8f8 str r4, [sp, #0x30] */
/* @0x29a8fc mov r4, #0 */
/* @0x29a900 strb r4, [r12] */
/* @0x29a904 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29a908 ldr r8, [r7] */
/* @0x29a90c ldr r12, [sp, #0x58] */
/* @0x29a910 ldr r1, [r9, #0x10] */
/* @0x29a914 cmp r8, r4 */
/* @0x29a918 ldr lr, [r9, #0x4] */
/* @0x29a91c sub r12, r12, #16 */
/* @0x29a920 ldr r2, [pc, #0x110] */
/* @0x29a924 str r4, [sp, #0x50] */
/* @0x29a928 add r2, pc, r2 */
/* @0x29a92c str r4, [sp, #0x54] */
/* @0x29a930 str r4, [sp, #0x5c] */
/* @0x29a934 str r4, [sp, #0x64] */
/* @0x29a938 str r4, [sp, #0x74] */
/* @0x29a93c str r9, [sp, #0x44] */
/* @0x29a940 str r1, [sp, #0x3c] */
/* @0x29a944 str lr, [sp, #0x68] */
/* @0x29a948 str r2, [sp, #0x4c] */
/* @0x29a94c str r0, [sp, #0x20] */
/* @0x29a950 add r0, r0, r12 */
/* @0x29a954 str r0, [sp, #0x40] */
/* @0x29a958 beq 0x29a9b8 <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x17c> */
/* @0x29a95c add r12, sp, #24 */
/* @0x29a960 ldr lr, [r8, #0x10] */
/* @0x29a964 mov r2, r4 */
/* @0x29a968 mov r1, r6 */
/* @0x29a96c mov r0, r12 */
/* @0x29a970 str r12, [r7] */
/* @0x29a974 str lr, [sp, #0x28] */
/* @0x29a978 bl 0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb> */
/* @0x29a97c ldr r12, [sp, #0x14] */
/* @0x29a980 str r8, [r7] */
/* @0x29a984 ldrb r2, [r12] */
/* @0x29a988 cmp r2, #0 */
/* @0x29a98c beq 0x29a9a0 <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x164> */
/* @0x29a990 ldr r1, [pc, #0xa4] */
/* @0x29a994 mov r0, r6 */
/* @0x29a998 add r1, pc, r1 */
/* @0x29a99c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x29a9a0 ldr r12, [sp, #0x10] */
/* @0x29a9a4 strb r11, [r12] */
/* @0x29a9a8 ldr r12, [sp, #0xc] */
/* @0x29a9ac strb r10, [r12] */
/* @0x29a9b0 add sp, sp, #124 */
/* @0x29a9b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29a9b8 ldr r2, [pc, #0x80] */
/* @0x29a9bc ldr r2, [r5, r2] */
/* @0x29a9c0 ldr r0, [r2] */
/* @0x29a9c4 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0x29a9c8 add r12, sp, #24 */
/* @0x29a9cc mov r1, r6 */
/* @0x29a9d0 mov r2, #1 */
/* @0x29a9d4 str r8, [sp, #0x24] */
/* @0x29a9d8 str r12, [r7] */
/* @0x29a9dc str r0, [sp, #0x28] */
/* @0x29a9e0 mov r0, r12 */
/* @0x29a9e4 bl 0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb> */
/* @0x29a9e8 b 0x29a97c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x140> */
/* @0x29a9ec mov r0, #432 */
/* @0x29a9f0 bl 0x27c524 <_Znwj> */
/* @0x29a9f4 mov r1, #0 */
/* @0x29a9f8 mov r3, r4 */
/* @0x29a9fc str r4, [sp] */
/* @0x29aa00 str r4, [sp, #0x4] */
/* @0x29aa04 mov r2, r1 */
/* @0x29aa08 mov r8, r0 */
/* @0x29aa0c bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x29aa10 str r8, [r7] */
/* @0x29aa14 mov lr, r8 */
/* @0x29aa18 b 0x29a86c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x30> */
/* @0x29aa1c ldrsheq r7, [r5], -r12 */
/* @0x29aa20 .word 0xfffffdb4 */
/* @0x29aa24 .word 0xffffbfdc */
/* @0x29aa28 .word 0xffffc158 */
/* @0x29aa2c .word 0xffffbf58 */
/* @0x29aa30 .word 0x000bf0fc */
/* @0x29aa34 .word 0xffffbf14 */
/* @0x29aa38 .word 0x000bf0dc */
/* @0x29aa3c andeq pc, r11, r4, ror r0 */
/* @0x29aa40 .word 0xffffc104 */

/* ── FUNC 0x29aa44 · Debug_GetJSInstances(Buffer_Standard*, Buffer_Standard*) · size=328 · insn=82 */
/* @0x29aa44 ldr r12, [r0] */
/* @0x29aa48 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29aa4c add r10, r0, #44 */
/* @0x29aa50 mov r4, r1 */
/* @0x29aa54 sub sp, sp, #12 */
/* @0x29aa58 mov r2, r10 */
/* @0x29aa5c mov r6, #0 */
/* @0x29aa60 ldr r12, [r12, #0xc] */
/* @0x29aa64 mov r1, #5 */
/* @0x29aa68 mov r9, r0 */
/* @0x29aa6c blx r12 */
/* @0x29aa70 mov r1, r6 */
/* @0x29aa74 mov r0, r10 */
/* @0x29aa78 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29aa7c ldr r12, [r4] */
/* @0x29aa80 add r7, r4, #44 */
/* @0x29aa84 str r6, [r4, #0x38] */
/* @0x29aa88 mov r1, #5 */
/* @0x29aa8c mov r2, r7 */
/* @0x29aa90 vmov s13, r0 */
/* @0x29aa94 str r0, [sp, #0x4] */
/* @0x29aa98 mov r0, r4 */
/* @0x29aa9c vcvt.f64.u32 d7, s13 */
/* @0x29aaa0 vstr s14, [r4, #44] */
/* @0x29aaa4 vstr s15, [r4, #48] */
/* @0x29aaa8 ldr r12, [r12, #0x8] */
/* @0x29aaac blx r12 */
/* @0x29aab0 ldr r3, [sp, #0x4] */
/* @0x29aab4 cmp r3, r6 */
/* @0x29aab8 ble 0x29ab84 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0x140> */
/* @0x29aabc mov r11, r6 */
/* @0x29aac0 mov r8, r6 */
/* @0x29aac4 movt r11, #0x3ff0 */
/* @0x29aac8 b 0x29ab00 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0xbc> */
/* @0x29aacc str r8, [r4, #0x2c] */
/* @0x29aad0 add r6, r6, #1 */
/* @0x29aad4 str r11, [r4, #0x30] */
/* @0x29aad8 str r8, [r4, #0x38] */
/* @0x29aadc ldr r12, [r12, #0x8] */
/* @0x29aae0 blx r12 */
/* @0x29aae4 mov r0, r4 */
/* @0x29aae8 mov r1, r5 */
/* @0x29aaec mov r2, #1 */
/* @0x29aaf0 bl 0xd8df4 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb> */
/* @0x29aaf4 ldr r3, [sp, #0x4] */
/* @0x29aaf8 cmp r3, r6 */
/* @0x29aafc beq 0x29ab84 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0x140> */
/* @0x29ab00 ldr r12, [r9] */
/* @0x29ab04 mov r1, #12 */
/* @0x29ab08 mov r2, r10 */
/* @0x29ab0c mov r0, r9 */
/* @0x29ab10 ldr r12, [r12, #0xc] */
/* @0x29ab14 blx r12 */
/* @0x29ab18 ldr r5, [r9, #0x2c] */
/* @0x29ab1c ldr lr, [r9, #0x30] */
/* @0x29ab20 mov r1, #12 */
/* @0x29ab24 ldr r12, [r4] */
/* @0x29ab28 mov r2, r7 */
/* @0x29ab2c str r5, [r4, #0x2c] */
/* @0x29ab30 mov r3, #10 */
/* @0x29ab34 str lr, [r4, #0x30] */
/* @0x29ab38 mov r0, r4 */
/* @0x29ab3c ldr r12, [r12, #0x8] */
/* @0x29ab40 str r3, [r4, #0x38] */
/* @0x29ab44 blx r12 */
/* @0x29ab48 cmp r5, #0 */
/* @0x29ab4c mov r2, r7 */
/* @0x29ab50 mov r0, r4 */
/* @0x29ab54 mov r1, #5 */
/* @0x29ab58 ldr r12, [r4] */
/* @0x29ab5c bne 0x29aacc <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0x88> */
/* @0x29ab60 str r5, [r4, #0x2c] */
/* @0x29ab64 add r6, r6, #1 */
/* @0x29ab68 str r5, [r4, #0x30] */
/* @0x29ab6c str r5, [r4, #0x38] */
/* @0x29ab70 ldr r12, [r12, #0x8] */
/* @0x29ab74 blx r12 */
/* @0x29ab78 ldr r3, [sp, #0x4] */
/* @0x29ab7c cmp r3, r6 */
/* @0x29ab80 bne 0x29ab00 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0xbc> */
/* @0x29ab84 add sp, sp, #12 */
/* @0x29ab88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x29ab8c · Debug_GetInstances(Buffer_Standard*, Buffer_Standard*) · size=428 · insn=107 */
/* @0x29ab8c ldr r12, [r0] */
/* @0x29ab90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29ab94 add r7, r0, #44 */
/* @0x29ab98 mov r10, r1 */
/* @0x29ab9c sub sp, sp, #12 */
/* @0x29aba0 mov r2, r7 */
/* @0x29aba4 mov r6, #0 */
/* @0x29aba8 ldr r12, [r12, #0xc] */
/* @0x29abac mov r1, #5 */
/* @0x29abb0 mov r8, r0 */
/* @0x29abb4 blx r12 */
/* @0x29abb8 mov r1, r6 */
/* @0x29abbc mov r0, r7 */
/* @0x29abc0 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29abc4 ldr r12, [r10] */
/* @0x29abc8 add r9, r10, #44 */
/* @0x29abcc str r6, [r10, #0x38] */
/* @0x29abd0 mov r1, #5 */
/* @0x29abd4 mov r2, r9 */
/* @0x29abd8 vmov s15, r0 */
/* @0x29abdc str r0, [sp, #0x4] */
/* @0x29abe0 mov r0, r10 */
/* @0x29abe4 vcvt.f64.u32 d7, s15 */
/* @0x29abe8 vmov r4, r5, d7 */
/* @0x29abec vstr s14, [r10, #44] */
/* @0x29abf0 str r5, [r10, #0x30] */
/* @0x29abf4 ldr r12, [r12, #0x8] */
/* @0x29abf8 blx r12 */
/* @0x29abfc ldr r3, [sp, #0x4] */
/* @0x29ac00 cmp r3, r6 */
/* @0x29ac04 ble 0x29acec <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x160> */
/* @0x29ac08 mov r11, r6 */
/* @0x29ac0c movt r11, #0x3ff0 */
/* @0x29ac10 mov r5, r6 */
/* @0x29ac14 ldr r12, [r8] */
/* @0x29ac18 mov r2, r7 */
/* @0x29ac1c mov r1, #5 */
/* @0x29ac20 mov r0, r8 */
/* @0x29ac24 ldr r12, [r12, #0xc] */
/* @0x29ac28 blx r12 */
/* @0x29ac2c mov r1, #0 */
/* @0x29ac30 mov r0, r7 */
/* @0x29ac34 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29ac38 ldr r3, [r10] */
/* @0x29ac3c str r5, [r10, #0x38] */
/* @0x29ac40 mov r1, #5 */
/* @0x29ac44 mov r2, r9 */
/* @0x29ac48 vmov s13, r0 */
/* @0x29ac4c mov r4, r0 */
/* @0x29ac50 mov r0, r10 */
/* @0x29ac54 vcvt.f64.u32 d7, s13 */
/* @0x29ac58 vstr s14, [r10, #44] */
/* @0x29ac5c vstr s15, [r10, #48] */
/* @0x29ac60 ldr r12, [r3, #0x8] */
/* @0x29ac64 blx r12 */
/* @0x29ac68 cmp r4, #0 */
/* @0x29ac6c blt 0x29acb8 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x12c> */
/* @0x29ac70 ldr r2, [pc, #0xbc] */
/* @0x29ac74 ldr r2, [pc, r2] */
/* @0x29ac78 ldr r1, [r2, #0x4] */
/* @0x29ac7c ldr r2, [r2] */
/* @0x29ac80 and r1, r4, r1 */
/* @0x29ac84 ldr r2, [r2, r1, lsl #3] */
/* @0x29ac88 cmp r2, #0 */
/* @0x29ac8c beq 0x29acb8 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x12c> */
/* @0x29ac90 ldr r1, [r2, #0x8] */
/* @0x29ac94 cmp r4, r1 */
/* @0x29ac98 bne 0x29acac <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x120> */
/* @0x29ac9c b 0x29acf4 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x168> */
/* @0x29aca0 ldr r3, [r2, #0x8] */
/* @0x29aca4 cmp r4, r3 */
/* @0x29aca8 beq 0x29acf4 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x168> */
/* @0x29acac ldr r2, [r2, #0x4] */
/* @0x29acb0 cmp r2, #0 */
/* @0x29acb4 bne 0x29aca0 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x114> */
/* @0x29acb8 ldr r12, [r10] */
/* @0x29acbc mov r0, r10 */
/* @0x29acc0 str r5, [r10, #0x2c] */
/* @0x29acc4 mov r1, #5 */
/* @0x29acc8 str r5, [r10, #0x30] */
/* @0x29accc mov r2, r9 */
/* @0x29acd0 str r5, [r10, #0x38] */
/* @0x29acd4 ldr r12, [r12, #0x8] */
/* @0x29acd8 blx r12 */
/* @0x29acdc ldr r3, [sp, #0x4] */
/* @0x29ace0 add r6, r6, #1 */
/* @0x29ace4 cmp r3, r6 */
/* @0x29ace8 bne 0x29ac14 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x88> */
/* @0x29acec add sp, sp, #12 */
/* @0x29acf0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29acf4 ldr r4, [r2, #0xc] */
/* @0x29acf8 cmp r4, #0 */
/* @0x29acfc beq 0x29acb8 <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x12c> */
/* @0x29ad00 ldr r12, [r10] */
/* @0x29ad04 mov r0, r10 */
/* @0x29ad08 str r5, [r10, #0x2c] */
/* @0x29ad0c mov r1, #5 */
/* @0x29ad10 str r11, [r10, #0x30] */
/* @0x29ad14 mov r2, r9 */
/* @0x29ad18 str r5, [r10, #0x38] */
/* @0x29ad1c ldr r12, [r12, #0x8] */
/* @0x29ad20 blx r12 */
/* @0x29ad24 mov r0, r10 */
/* @0x29ad28 mov r1, r4 */
/* @0x29ad2c bl 0xd96f0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance> */
/* @0x29ad30 b 0x29acdc <_Z18Debug_GetInstancesP15Buffer_StandardS0_+0x150> */
/* @0x29ad34 ldrsbeq r2, [r5], -r0 */

/* ── FUNC 0x29ad38 · Debug_GetTextures(Buffer_Standard*, Buffer_Standard*) · size=864 · insn=216 */
/* @0x29ad38 ldr r3, [r0] */
/* @0x29ad3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29ad40 vpush {d8} */
/* @0x29ad44 add r8, r0, #44 */
/* @0x29ad48 mov r10, r1 */
/* @0x29ad4c sub sp, sp, #52 */
/* @0x29ad50 mov r2, r8 */
/* @0x29ad54 mov r4, #0 */
/* @0x29ad58 ldr r3, [r3, #0xc] */
/* @0x29ad5c mov r1, #6 */
/* @0x29ad60 mov r9, r0 */
/* @0x29ad64 blx r3 */
/* @0x29ad68 mov r1, r4 */
/* @0x29ad6c mov r0, r8 */
/* @0x29ad70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29ad74 ldr r3, [r10] */
/* @0x29ad78 add r7, r10, #44 */
/* @0x29ad7c str r4, [r10, #0x38] */
/* @0x29ad80 mov r1, #5 */
/* @0x29ad84 mov r2, r7 */
/* @0x29ad88 vmov s13, r0 */
/* @0x29ad8c str r0, [sp, #0x28] */
/* @0x29ad90 mov r0, r10 */
/* @0x29ad94 vcvt.f64.u32 d7, s13 */
/* @0x29ad98 vstr s14, [r10, #44] */
/* @0x29ad9c vstr s15, [r10, #48] */
/* @0x29ada0 ldr r3, [r3, #0x8] */
/* @0x29ada4 blx r3 */
/* @0x29ada8 ldr r12, [sp, #0x28] */
/* @0x29adac cmp r12, r4 */
/* @0x29adb0 ble 0x29b078 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x340> */
/* @0x29adb4 mov r12, r4 */
/* @0x29adb8 str r4, [sp, #0x24] */
/* @0x29adbc movt r12, #0xbff0 */
/* @0x29adc0 mov r6, r4 */
/* @0x29adc4 str r12, [sp, #0x2c] */
/* @0x29adc8 b 0x29af9c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x264> */
/* @0x29adcc mov r0, r4 */
/* @0x29add0 vmov s17, r4 */
/* @0x29add4 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x29add8 cmp r0, #0 */
/* @0x29addc beq 0x29b084 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x34c> */
/* @0x29ade0 ldr r3, [pc, #0x2a8] */
/* @0x29ade4 ldr r4, [r0, #0x4] */
/* @0x29ade8 ldr r3, [pc, r3] */
/* @0x29adec ldrb r11, [r3] */
/* @0x29adf0 cmp r11, #0 */
/* @0x29adf4 beq 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314> */
/* @0x29adf8 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x29adfc mov r0, r4 */
/* @0x29ae00 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x29ae04 subs r11, r0, #0 */
/* @0x29ae08 beq 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314> */
/* @0x29ae0c ldr r12, [r11, #0x4] */
/* @0x29ae10 mov r1, r5 */
/* @0x29ae14 ldr r11, [r11, #0x8] */
/* @0x29ae18 mov r2, r5 */
/* @0x29ae1c mov r3, r12 */
/* @0x29ae20 str r12, [sp, #0x1c] */
/* @0x29ae24 str r11, [sp] */
/* @0x29ae28 str r11, [sp, #0x20] */
/* @0x29ae2c bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0x29ae30 mov r11, r0 */
/* @0x29ae34 cmp r11, #0 */
/* @0x29ae38 beq 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314> */
/* @0x29ae3c vmov s15, r4 */
/* @0x29ae40 ldr r2, [sp, #0x20] */
/* @0x29ae44 ldr r3, [sp, #0x1c] */
/* @0x29ae48 mov r1, #6 */
/* @0x29ae4c vcvt.f64.s32 d7, s15 */
/* @0x29ae50 str r6, [r10, #0x38] */
/* @0x29ae54 mov r0, r10 */
/* @0x29ae58 mul r12, r2, r3 */
/* @0x29ae5c mov r2, r7 */
/* @0x29ae60 vmov r4, r5, d7 */
/* @0x29ae64 vstr s14, [r10, #44] */
/* @0x29ae68 lsl r12, r12, #2 */
/* @0x29ae6c vmov s16, r12 */
/* @0x29ae70 ldr r12, [r10] */
/* @0x29ae74 str r5, [r10, #0x30] */
/* @0x29ae78 ldr r3, [r12, #0x8] */
/* @0x29ae7c blx r3 */
/* @0x29ae80 vcvt.f64.s32 d7, s17 */
/* @0x29ae84 ldr r12, [r10] */
/* @0x29ae88 mov r1, #6 */
/* @0x29ae8c mov r2, r7 */
/* @0x29ae90 mov r0, r10 */
/* @0x29ae94 str r6, [r10, #0x38] */
/* @0x29ae98 vmov r4, r5, d7 */
/* @0x29ae9c vstr s14, [r10, #44] */
/* @0x29aea0 str r5, [r10, #0x30] */
/* @0x29aea4 ldr r3, [r12, #0x8] */
/* @0x29aea8 blx r3 */
/* @0x29aeac vldr s15, [sp, #28] */
/* @0x29aeb0 vcvt.f64.u32 d7, s15 */
/* @0x29aeb4 ldr r12, [r10] */
/* @0x29aeb8 mov r1, #5 */
/* @0x29aebc mov r2, r7 */
/* @0x29aec0 mov r0, r10 */
/* @0x29aec4 str r6, [r10, #0x38] */
/* @0x29aec8 vmov r4, r5, d7 */
/* @0x29aecc vstr s14, [r10, #44] */
/* @0x29aed0 str r5, [r10, #0x30] */
/* @0x29aed4 ldr r3, [r12, #0x8] */
/* @0x29aed8 blx r3 */
/* @0x29aedc vldr s15, [sp, #32] */
/* @0x29aee0 vcvt.f64.u32 d7, s15 */
/* @0x29aee4 ldr r12, [r10] */
/* @0x29aee8 mov r1, #5 */
/* @0x29aeec mov r2, r7 */
/* @0x29aef0 mov r0, r10 */
/* @0x29aef4 str r6, [r10, #0x38] */
/* @0x29aef8 vmov r4, r5, d7 */
/* @0x29aefc vstr s14, [r10, #44] */
/* @0x29af00 str r5, [r10, #0x30] */
/* @0x29af04 ldr r3, [r12, #0x8] */
/* @0x29af08 blx r3 */
/* @0x29af0c vcvt.f64.u32 d7, s16 */
/* @0x29af10 ldr r12, [r10] */
/* @0x29af14 mov r1, #5 */
/* @0x29af18 mov r2, r7 */
/* @0x29af1c mov r0, r10 */
/* @0x29af20 str r6, [r10, #0x38] */
/* @0x29af24 vmov r4, r5, d7 */
/* @0x29af28 vstr s14, [r10, #44] */
/* @0x29af2c str r5, [r10, #0x30] */
/* @0x29af30 ldr r3, [r12, #0x8] */
/* @0x29af34 blx r3 */
/* @0x29af38 ldr lr, [r10, #0x1c] */
/* @0x29af3c vmov r2, s16 */
/* @0x29af40 mvn r3, #0 */
/* @0x29af44 mov r12, #1 */
/* @0x29af48 str r3, [sp] */
/* @0x29af4c mov r1, r11 */
/* @0x29af50 mov r3, #0 */
/* @0x29af54 str r12, [sp, #0x8] */
/* @0x29af58 mov r0, r10 */
/* @0x29af5c str r6, [sp, #0xc] */
/* @0x29af60 str r6, [sp, #0x10] */
/* @0x29af64 str lr, [sp, #0x4] */
/* @0x29af68 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0x29af6c ldr r3, [r10] */
/* @0x29af70 mov r1, #0 */
/* @0x29af74 ldr r3, [r3, #0x10] */
/* @0x29af78 mov r2, r0 */
/* @0x29af7c mov r0, r10 */
/* @0x29af80 blx r3 */
/* @0x29af84 ldr r12, [sp, #0x24] */
/* @0x29af88 ldr r2, [sp, #0x28] */
/* @0x29af8c add r12, r12, #1 */
/* @0x29af90 str r12, [sp, #0x24] */
/* @0x29af94 cmp r12, r2 */
/* @0x29af98 beq 0x29b078 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x340> */
/* @0x29af9c ldr r3, [r9] */
/* @0x29afa0 mov r2, r8 */
/* @0x29afa4 mov r1, #5 */
/* @0x29afa8 mov r0, r9 */
/* @0x29afac ldr r3, [r3, #0xc] */
/* @0x29afb0 blx r3 */
/* @0x29afb4 mov r1, #0 */
/* @0x29afb8 mov r0, r8 */
/* @0x29afbc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29afc0 ldr r3, [r9] */
/* @0x29afc4 mov r1, #5 */
/* @0x29afc8 mov r2, r8 */
/* @0x29afcc ldr r3, [r3, #0xc] */
/* @0x29afd0 mov r4, r0 */
/* @0x29afd4 mov r0, r9 */
/* @0x29afd8 blx r3 */
/* @0x29afdc mov r0, r8 */
/* @0x29afe0 mov r1, #0 */
/* @0x29afe4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29afe8 subs r5, r0, #0 */
/* @0x29afec beq 0x29adcc <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x94> */
/* @0x29aff0 ldr r3, [pc, #0x9c] */
/* @0x29aff4 ldr r3, [pc, r3] */
/* @0x29aff8 ldrb r11, [r3] */
/* @0x29affc cmp r11, #0 */
/* @0x29b000 beq 0x29b040 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x308> */
/* @0x29b004 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x29b008 mov r0, r4 */
/* @0x29b00c bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x29b010 subs r11, r0, #0 */
/* @0x29b014 beq 0x29b040 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x308> */
/* @0x29b018 ldr r12, [r11, #0x4] */
/* @0x29b01c mov r1, #0 */
/* @0x29b020 ldr r11, [r11, #0x8] */
/* @0x29b024 mov r2, r1 */
/* @0x29b028 mov r3, r12 */
/* @0x29b02c str r12, [sp, #0x1c] */
/* @0x29b030 str r11, [sp] */
/* @0x29b034 str r11, [sp, #0x20] */
/* @0x29b038 bl 0x17e2a8 <_ZN8Graphics16Texture_GrabRectEPviiii> */
/* @0x29b03c mov r11, r0 */
/* @0x29b040 cmp r11, #0 */
/* @0x29b044 vldr s17, [pc, #64] */
/* @0x29b048 bne 0x29ae3c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x104> */
/* @0x29b04c ldr r3, [r10] */
/* @0x29b050 mov r0, r10 */
/* @0x29b054 ldr r12, [sp, #0x2c] */
/* @0x29b058 mov r1, #6 */
/* @0x29b05c str r11, [r10, #0x2c] */
/* @0x29b060 mov r2, r7 */
/* @0x29b064 str r11, [r10, #0x38] */
/* @0x29b068 str r12, [r10, #0x30] */
/* @0x29b06c ldr r3, [r3, #0x8] */
/* @0x29b070 blx r3 */
/* @0x29b074 b 0x29af84 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x24c> */
/* @0x29b078 add sp, sp, #52 */
/* @0x29b07c vpop {d8} */
/* @0x29b080 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29b084 mov r11, r0 */
/* @0x29b088 b 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314> */
/* @0x29b08c .word 0xffffffff */
/* @0x29b090 andseq r5, r5, r8, lsr r3 */
/* @0x29b094 andseq r5, r5, r12, lsr #2 */

/* ── FUNC 0x29b098 · Debug_GetBuffers(Buffer_Standard*, Buffer_Standard*) · size=808 · insn=202 */
/* @0x29b098 ldr r3, [r0] */
/* @0x29b09c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29b0a0 add r8, r0, #44 */
/* @0x29b0a4 mov r4, r1 */
/* @0x29b0a8 sub sp, sp, #28 */
/* @0x29b0ac mov r2, r8 */
/* @0x29b0b0 mov r9, #0 */
/* @0x29b0b4 ldr r3, [r3, #0xc] */
/* @0x29b0b8 mov r1, #6 */
/* @0x29b0bc mov r6, r0 */
/* @0x29b0c0 blx r3 */
/* @0x29b0c4 mov r1, r9 */
/* @0x29b0c8 mov r0, r8 */
/* @0x29b0cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29b0d0 ldr r3, [r4] */
/* @0x29b0d4 add r7, r4, #44 */
/* @0x29b0d8 str r9, [r4, #0x38] */
/* @0x29b0dc mov r1, #5 */
/* @0x29b0e0 mov r2, r7 */
/* @0x29b0e4 vmov s15, r0 */
/* @0x29b0e8 str r0, [sp, #0xc] */
/* @0x29b0ec mov r0, r4 */
/* @0x29b0f0 vcvt.f64.u32 d7, s15 */
/* @0x29b0f4 vmov r10, r11, d7 */
/* @0x29b0f8 vstr s14, [r4, #44] */
/* @0x29b0fc str r11, [r4, #0x30] */
/* @0x29b100 ldr r3, [r3, #0x8] */
/* @0x29b104 blx r3 */
/* @0x29b108 ldr r12, [sp, #0xc] */
/* @0x29b10c cmp r12, r9 */
/* @0x29b110 ble 0x29b3b8 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x320> */
/* @0x29b114 mov r12, r9 */
/* @0x29b118 movt r12, #0xffe0 */
/* @0x29b11c str r12, [sp, #0x10] */
/* @0x29b120 movw r12, #0xffff */
/* @0x29b124 movt r12, #0x41ef */
/* @0x29b128 str r12, [sp, #0x14] */
/* @0x29b12c b 0x29b170 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0xd8> */
/* @0x29b130 ldr r12, [sp, #0x10] */
/* @0x29b134 mov lr, #0 */
/* @0x29b138 ldr r3, [r4] */
/* @0x29b13c mov r0, r4 */
/* @0x29b140 mov r1, #5 */
/* @0x29b144 mov r2, r7 */
/* @0x29b148 str r12, [r4, #0x2c] */
/* @0x29b14c add r9, r9, #1 */
/* @0x29b150 ldr r12, [sp, #0x14] */
/* @0x29b154 str lr, [r4, #0x38] */
/* @0x29b158 str r12, [r4, #0x30] */
/* @0x29b15c ldr r3, [r3, #0x8] */
/* @0x29b160 blx r3 */
/* @0x29b164 ldr r12, [sp, #0xc] */
/* @0x29b168 cmp r9, r12 */
/* @0x29b16c beq 0x29b3b8 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x320> */
/* @0x29b170 ldr r3, [r6] */
/* @0x29b174 mov r2, r8 */
/* @0x29b178 mov r1, #6 */
/* @0x29b17c mov r0, r6 */
/* @0x29b180 ldr r3, [r3, #0xc] */
/* @0x29b184 blx r3 */
/* @0x29b188 mov r1, #0 */
/* @0x29b18c mov r0, r8 */
/* @0x29b190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29b194 ldr r3, [r6] */
/* @0x29b198 mov r2, r8 */
/* @0x29b19c mov r1, #5 */
/* @0x29b1a0 ldr r3, [r3, #0xc] */
/* @0x29b1a4 mov r10, r0 */
/* @0x29b1a8 mov r0, r6 */
/* @0x29b1ac blx r3 */
/* @0x29b1b0 mov r1, #0 */
/* @0x29b1b4 mov r0, r8 */
/* @0x29b1b8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b1bc mov r11, r0 */
/* @0x29b1c0 mov r0, r10 */
/* @0x29b1c4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29b1c8 vmov s13, r10 */
/* @0x29b1cc ldr lr, [r4] */
/* @0x29b1d0 mov r2, #0 */
/* @0x29b1d4 vcvt.f64.u32 d7, s13 */
/* @0x29b1d8 str r2, [r4, #0x38] */
/* @0x29b1dc mov r1, #5 */
/* @0x29b1e0 mov r2, r7 */
/* @0x29b1e4 vstr s14, [r4, #44] */
/* @0x29b1e8 vstr s15, [r4, #48] */
/* @0x29b1ec ldr r3, [lr, #0x8] */
/* @0x29b1f0 mov r5, r0 */
/* @0x29b1f4 mov r0, r4 */
/* @0x29b1f8 blx r3 */
/* @0x29b1fc cmp r5, #0 */
/* @0x29b200 cmpne r5, r6 */
/* @0x29b204 movne r10, #0 */
/* @0x29b208 moveq r10, #1 */
/* @0x29b20c beq 0x29b130 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x98> */
/* @0x29b210 ldr r3, [r5, #0x10] */
/* @0x29b214 mov r1, #5 */
/* @0x29b218 ldr lr, [r4] */
/* @0x29b21c mov r2, r7 */
/* @0x29b220 str r10, [r4, #0x38] */
/* @0x29b224 mov r0, r4 */
/* @0x29b228 vmov s13, r3 */
/* @0x29b22c lsl r11, r11, #10 */
/* @0x29b230 vcvt.f64.u32 d7, s13 */
/* @0x29b234 vstr s14, [r4, #44] */
/* @0x29b238 vstr s15, [r4, #48] */
/* @0x29b23c ldr r12, [lr, #0x8] */
/* @0x29b240 str r3, [sp, #0x8] */
/* @0x29b244 blx r12 */
/* @0x29b248 vldr s14, [r5, #24] */
/* @0x29b24c vcvt.f64.u32 d7, s14 */
/* @0x29b250 ldr lr, [r4] */
/* @0x29b254 mov r1, #5 */
/* @0x29b258 mov r2, r7 */
/* @0x29b25c mov r0, r4 */
/* @0x29b260 str r10, [r4, #0x38] */
/* @0x29b264 vstr s14, [r4, #44] */
/* @0x29b268 vstr s15, [r4, #48] */
/* @0x29b26c ldr r12, [lr, #0x8] */
/* @0x29b270 blx r12 */
/* @0x29b274 vldr s14, [r5, #20] */
/* @0x29b278 vcvt.f64.u32 d7, s14 */
/* @0x29b27c ldr lr, [r4] */
/* @0x29b280 mov r1, #5 */
/* @0x29b284 mov r2, r7 */
/* @0x29b288 mov r0, r4 */
/* @0x29b28c str r10, [r4, #0x38] */
/* @0x29b290 vstr s14, [r4, #44] */
/* @0x29b294 vstr s15, [r4, #48] */
/* @0x29b298 ldr r12, [lr, #0x8] */
/* @0x29b29c blx r12 */
/* @0x29b2a0 vldr s14, [r5, #28] */
/* @0x29b2a4 vcvt.f64.u32 d7, s14 */
/* @0x29b2a8 ldr lr, [r4] */
/* @0x29b2ac mov r0, r4 */
/* @0x29b2b0 str r10, [r4, #0x38] */
/* @0x29b2b4 mov r1, #5 */
/* @0x29b2b8 mov r2, r7 */
/* @0x29b2bc vstr s14, [r4, #44] */
/* @0x29b2c0 vstr s15, [r4, #48] */
/* @0x29b2c4 ldr r12, [lr, #0x8] */
/* @0x29b2c8 blx r12 */
/* @0x29b2cc ldr r3, [sp, #0x8] */
/* @0x29b2d0 cmp r11, r3 */
/* @0x29b2d4 blt 0x29b2f4 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x25c> */
/* @0x29b2d8 sub r11, r3, #1 */
/* @0x29b2dc add r2, r11, #1020 */
/* @0x29b2e0 cmp r11, #0 */
/* @0x29b2e4 add r2, r2, #3 */
/* @0x29b2e8 movlt r11, r2 */
/* @0x29b2ec asr r11, r11, #10 */
/* @0x29b2f0 lsl r11, r11, #10 */
/* @0x29b2f4 vmov s13, r11 */
/* @0x29b2f8 ldr lr, [r4] */
/* @0x29b2fc rsb r3, r11, r3 */
/* @0x29b300 mov r2, #0 */
/* @0x29b304 vcvt.f64.u32 d7, s13 */
/* @0x29b308 cmp r3, #1024 */
/* @0x29b30c movge r3, #1024 */
/* @0x29b310 bic r10, r3, r3, asr #31 */
/* @0x29b314 str r2, [r4, #0x38] */
/* @0x29b318 mov r1, #5 */
/* @0x29b31c mov r2, r7 */
/* @0x29b320 mov r0, r4 */
/* @0x29b324 add r9, r9, #1 */
/* @0x29b328 vstr s14, [r4, #44] */
/* @0x29b32c vstr s15, [r4, #48] */
/* @0x29b330 ldr r3, [lr, #0x8] */
/* @0x29b334 blx r3 */
/* @0x29b338 vmov s13, r10 */
/* @0x29b33c ldr lr, [r4] */
/* @0x29b340 mov r2, #0 */
/* @0x29b344 vcvt.f64.s32 d7, s13 */
/* @0x29b348 str r2, [r4, #0x38] */
/* @0x29b34c mov r1, #5 */
/* @0x29b350 mov r2, r7 */
/* @0x29b354 mov r0, r4 */
/* @0x29b358 vstr s14, [r4, #44] */
/* @0x29b35c vstr s15, [r4, #48] */
/* @0x29b360 ldr r3, [lr, #0x8] */
/* @0x29b364 blx r3 */
/* @0x29b368 ldr lr, [r5] */
/* @0x29b36c ldr r12, [r4, #0x1c] */
/* @0x29b370 mov r0, r5 */
/* @0x29b374 mov r1, r11 */
/* @0x29b378 mov r2, r10 */
/* @0x29b37c mov r3, r4 */
/* @0x29b380 str r12, [sp] */
/* @0x29b384 ldr r5, [lr, #0x38] */
/* @0x29b388 str r12, [sp, #0x8] */
/* @0x29b38c blx r5 */
/* @0x29b390 ldr r3, [r4] */
/* @0x29b394 ldr r12, [sp, #0x8] */
/* @0x29b398 mov r0, r4 */
/* @0x29b39c mov r1, #0 */
/* @0x29b3a0 add r2, r10, r12 */
/* @0x29b3a4 ldr r3, [r3, #0x10] */
/* @0x29b3a8 blx r3 */
/* @0x29b3ac ldr r12, [sp, #0xc] */
/* @0x29b3b0 cmp r9, r12 */
/* @0x29b3b4 bne 0x29b170 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0xd8> */
/* @0x29b3b8 add sp, sp, #28 */
/* @0x29b3bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x29b3c0 · Debug_GetArrays(Buffer_Standard*, Buffer_Standard*) · size=744 · insn=186 */
/* @0x29b3c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29b3c4 sub sp, sp, #28 */
/* @0x29b3c8 add r3, r0, #44 */
/* @0x29b3cc mov r4, r1 */
/* @0x29b3d0 str r3, [sp, #0xc] */
/* @0x29b3d4 mov r5, #0 */
/* @0x29b3d8 ldr r3, [r0] */
/* @0x29b3dc mov r1, #5 */
/* @0x29b3e0 ldr r2, [sp, #0xc] */
/* @0x29b3e4 add r10, r4, #44 */
/* @0x29b3e8 str r0, [sp, #0x8] */
/* @0x29b3ec ldr r3, [r3, #0xc] */
/* @0x29b3f0 blx r3 */
/* @0x29b3f4 mov r1, r5 */
/* @0x29b3f8 ldr r0, [sp, #0xc] */
/* @0x29b3fc bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b400 ldr r3, [r4] */
/* @0x29b404 mov r2, r10 */
/* @0x29b408 str r5, [r4, #0x38] */
/* @0x29b40c mov r1, #5 */
/* @0x29b410 vmov s15, r0 */
/* @0x29b414 str r0, [sp, #0x14] */
/* @0x29b418 mov r0, r4 */
/* @0x29b41c vcvt.f64.u32 d7, s15 */
/* @0x29b420 vmov r6, r7, d7 */
/* @0x29b424 vstr s14, [r4, #44] */
/* @0x29b428 str r7, [r4, #0x30] */
/* @0x29b42c ldr r3, [r3, #0x8] */
/* @0x29b430 blx r3 */
/* @0x29b434 ldr r3, [sp, #0x14] */
/* @0x29b438 cmp r3, r5 */
/* @0x29b43c ble 0x29b630 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x270> */
/* @0x29b440 str r5, [sp, #0x10] */
/* @0x29b444 ldr r12, [sp, #0x8] */
/* @0x29b448 mov r1, #12 */
/* @0x29b44c ldr r2, [sp, #0xc] */
/* @0x29b450 ldr r3, [r12] */
/* @0x29b454 mov r0, r12 */
/* @0x29b458 ldr r3, [r3, #0xc] */
/* @0x29b45c blx r3 */
/* @0x29b460 ldr r12, [sp, #0x8] */
/* @0x29b464 ldr r2, [sp, #0xc] */
/* @0x29b468 mov r1, #6 */
/* @0x29b46c ldr r3, [r12] */
/* @0x29b470 mov r0, r12 */
/* @0x29b474 ldr r11, [r12, #0x2c] */
/* @0x29b478 ldr r6, [r12, #0x30] */
/* @0x29b47c ldr r3, [r3, #0xc] */
/* @0x29b480 blx r3 */
/* @0x29b484 mov r1, #0 */
/* @0x29b488 ldr r0, [sp, #0xc] */
/* @0x29b48c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29b490 ldr r3, [r11, #0x10] */
/* @0x29b494 ldr r5, [r11, #0x4] */
/* @0x29b498 mov r12, #10 */
/* @0x29b49c str r11, [r4, #0x2c] */
/* @0x29b4a0 mov r1, #12 */
/* @0x29b4a4 str r3, [sp, #0x4] */
/* @0x29b4a8 cmp r5, #0 */
/* @0x29b4ac ldr r3, [r4] */
/* @0x29b4b0 mov r2, r10 */
/* @0x29b4b4 str r6, [r4, #0x30] */
/* @0x29b4b8 str r12, [r4, #0x38] */
/* @0x29b4bc ldr r3, [r3, #0x8] */
/* @0x29b4c0 mov r7, r0 */
/* @0x29b4c4 mov r0, r4 */
/* @0x29b4c8 beq 0x29b670 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x2b0> */
/* @0x29b4cc blx r3 */
/* @0x29b4d0 vldr s15, [sp, #4] */
/* @0x29b4d4 vcvt.f64.u32 d7, s15 */
/* @0x29b4d8 ldr r3, [r4] */
/* @0x29b4dc mov r1, #0 */
/* @0x29b4e0 mov r0, r4 */
/* @0x29b4e4 str r1, [r4, #0x38] */
/* @0x29b4e8 mov r2, r10 */
/* @0x29b4ec mov r1, #5 */
/* @0x29b4f0 vmov r8, r9, d7 */
/* @0x29b4f4 vstr s14, [r4, #44] */
/* @0x29b4f8 str r9, [r4, #0x30] */
/* @0x29b4fc ldr r3, [r3, #0x8] */
/* @0x29b500 blx r3 */
/* @0x29b504 cmp r7, #0 */
/* @0x29b508 blt 0x29b638 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x278> */
/* @0x29b50c vmov s15, r7 */
/* @0x29b510 ldr r3, [sp, #0x4] */
/* @0x29b514 vcvt.f64.s32 d7, s15 */
/* @0x29b518 rsb r9, r7, r3 */
/* @0x29b51c cmp r9, #10 */
/* @0x29b520 movge r9, #10 */
/* @0x29b524 bic r9, r9, r9, asr #31 */
/* @0x29b528 str r9, [sp, #0x4] */
/* @0x29b52c mov r5, r9 */
/* @0x29b530 vmov r2, r3, d7 */
/* @0x29b534 ldr r12, [r4] */
/* @0x29b538 mov r1, #0 */
/* @0x29b53c str r2, [r4, #0x2c] */
/* @0x29b540 mov r0, r4 */
/* @0x29b544 str r1, [r4, #0x38] */
/* @0x29b548 mov r2, r10 */
/* @0x29b54c str r3, [r4, #0x30] */
/* @0x29b550 mov r1, #5 */
/* @0x29b554 ldr r3, [r12, #0x8] */
/* @0x29b558 blx r3 */
/* @0x29b55c vmov s13, r5 */
/* @0x29b560 ldr r3, [r4] */
/* @0x29b564 mov r1, #0 */
/* @0x29b568 vcvt.f64.u32 d7, s13 */
/* @0x29b56c str r1, [r4, #0x38] */
/* @0x29b570 mov r0, r4 */
/* @0x29b574 mov r1, #5 */
/* @0x29b578 mov r2, r10 */
/* @0x29b57c vstr s14, [r4, #44] */
/* @0x29b580 vstr s15, [r4, #48] */
/* @0x29b584 ldr r3, [r3, #0x8] */
/* @0x29b588 blx r3 */
/* @0x29b58c ldr r3, [sp, #0x4] */
/* @0x29b590 cmp r3, #0 */
/* @0x29b594 lslgt r7, r7, #3 */
/* @0x29b598 movgt r8, #0 */
/* @0x29b59c ble 0x29b618 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x258> */
/* @0x29b5a0 ldr r2, [r11, #0x4] */
/* @0x29b5a4 mov r12, #0 */
/* @0x29b5a8 ldr r3, [r4] */
/* @0x29b5ac mov r0, r4 */
/* @0x29b5b0 add r6, r2, r7 */
/* @0x29b5b4 mov r1, #5 */
/* @0x29b5b8 ldr r5, [r2, r7] */
/* @0x29b5bc mov r2, r10 */
/* @0x29b5c0 str r12, [r4, #0x38] */
/* @0x29b5c4 vmov s13, r5 */
/* @0x29b5c8 vcvt.f64.u32 d7, s13 */
/* @0x29b5cc vstr s14, [r4, #44] */
/* @0x29b5d0 vstr s15, [r4, #48] */
/* @0x29b5d4 ldr r3, [r3, #0x8] */
/* @0x29b5d8 blx r3 */
/* @0x29b5dc cmp r5, #0 */
/* @0x29b5e0 movgt r9, #0 */
/* @0x29b5e4 ble 0x29b604 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x244> */
/* @0x29b5e8 ldr r0, [r6, #0x4] */
/* @0x29b5ec mov r1, r4 */
/* @0x29b5f0 add r0, r0, r9, lsl #4 */
/* @0x29b5f4 add r9, r9, #1 */
/* @0x29b5f8 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0x29b5fc cmp r9, r5 */
/* @0x29b600 bne 0x29b5e8 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x228> */
/* @0x29b604 ldr r3, [sp, #0x4] */
/* @0x29b608 add r8, r8, #1 */
/* @0x29b60c add r7, r7, #8 */
/* @0x29b610 cmp r8, r3 */
/* @0x29b614 bne 0x29b5a0 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x1e0> */
/* @0x29b618 ldr r12, [sp, #0x10] */
/* @0x29b61c ldr r3, [sp, #0x14] */
/* @0x29b620 add r12, r12, #1 */
/* @0x29b624 str r12, [sp, #0x10] */
/* @0x29b628 cmp r3, r12 */
/* @0x29b62c bne 0x29b444 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x84> */
/* @0x29b630 add sp, sp, #28 */
/* @0x29b634 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29b638 ldr r3, [sp, #0x4] */
/* @0x29b63c cmp r3, #10 */
/* @0x29b640 bgt 0x29b658 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x298> */
/* @0x29b644 mov r5, r3 */
/* @0x29b648 mov r2, #0 */
/* @0x29b64c mov r3, #0 */
/* @0x29b650 mov r7, #0 */
/* @0x29b654 b 0x29b534 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x174> */
/* @0x29b658 mov r5, #0 */
/* @0x29b65c mov r2, #0 */
/* @0x29b660 mov r3, #0 */
/* @0x29b664 str r5, [sp, #0x4] */
/* @0x29b668 mov r7, r5 */
/* @0x29b66c b 0x29b534 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x174> */
/* @0x29b670 blx r3 */
/* @0x29b674 ldr r3, [r4] */
/* @0x29b678 str r5, [r4, #0x2c] */
/* @0x29b67c mov r0, r4 */
/* @0x29b680 str r5, [r4, #0x30] */
/* @0x29b684 mov r1, #5 */
/* @0x29b688 str r5, [r4, #0x38] */
/* @0x29b68c mov r2, r10 */
/* @0x29b690 ldr r3, [r3, #0x8] */
/* @0x29b694 blx r3 */
/* @0x29b698 cmp r7, #0 */
/* @0x29b69c str r5, [sp, #0x4] */
/* @0x29b6a0 bge 0x29b50c <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x14c> */
/* @0x29b6a4 b 0x29b648 <_Z15Debug_GetArraysP15Buffer_StandardS0_+0x288> */

/* ── FUNC 0x29b6a8 · Debug_ExecuteBreakCondition(Buffer_Standard*) · size=1232 · insn=308 */
/* @0x29b6a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29b6ac add r11, sp, #32 */
/* @0x29b6b0 ldr r3, [pc, #0x4ac] */
/* @0x29b6b4 sub sp, sp, #84 */
/* @0x29b6b8 ldr r2, [pc, #0x4a8] */
/* @0x29b6bc add r3, pc, r3 */
/* @0x29b6c0 str r3, [r11, #-0x5c] */
/* @0x29b6c4 ldr r12, [r11, #-0x5c] */
/* @0x29b6c8 mov r4, r1 */
/* @0x29b6cc str r0, [r11, #-0x60] */
/* @0x29b6d0 mov r0, r1 */
/* @0x29b6d4 ldr r3, [pc, #0x490] */
/* @0x29b6d8 add r5, r1, #44 */
/* @0x29b6dc ldr r2, [r12, r2] */
/* @0x29b6e0 str r2, [r11, #-0x64] */
/* @0x29b6e4 ldr r2, [r2] */
/* @0x29b6e8 str r2, [r11, #-0x28] */
/* @0x29b6ec ldr r3, [r12, r3] */
/* @0x29b6f0 str r3, [r11, #-0x68] */
/* @0x29b6f4 ldr r3, [r3] */
/* @0x29b6f8 str r3, [r11, #-0x6c] */
/* @0x29b6fc bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29b700 ldr r3, [r4] */
/* @0x29b704 mov r2, r5 */
/* @0x29b708 mov r1, #5 */
/* @0x29b70c ldr r3, [r3, #0xc] */
/* @0x29b710 str r0, [r11, #-0x74] */
/* @0x29b714 mov r0, r4 */
/* @0x29b718 blx r3 */
/* @0x29b71c mov r1, #0 */
/* @0x29b720 mov r0, r5 */
/* @0x29b724 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b728 ldr r12, [r11, #-0x5c] */
/* @0x29b72c ldr r2, [pc, #0x43c] */
/* @0x29b730 mov r3, #0 */
/* @0x29b734 ldr r2, [r12, r2] */
/* @0x29b738 str r3, [r11, #-0x34] */
/* @0x29b73c str r3, [r11, #-0x30] */
/* @0x29b740 str r2, [r11, #-0x70] */
/* @0x29b744 add r2, r2, #8 */
/* @0x29b748 str r3, [r11, #-0x2c] */
/* @0x29b74c str r2, [r11, #-0x44] */
/* @0x29b750 mov r7, r0 */
/* @0x29b754 str r0, [r11, #-0x40] */
/* @0x29b758 bl 0x27d14c <_Znaj> */
/* @0x29b75c cmp r7, #0 */
/* @0x29b760 mov r6, r0 */
/* @0x29b764 str r0, [r11, #-0x34] */
/* @0x29b768 addne r7, r0, r7 */
/* @0x29b76c movne r8, r0 */
/* @0x29b770 beq 0x29b7a4 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0xfc> */
/* @0x29b774 ldr r3, [r4] */
/* @0x29b778 mov r1, #1 */
/* @0x29b77c mov r2, r5 */
/* @0x29b780 mov r0, r4 */
/* @0x29b784 ldr r3, [r3, #0xc] */
/* @0x29b788 blx r3 */
/* @0x29b78c mov r0, r5 */
/* @0x29b790 mov r1, #0 */
/* @0x29b794 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29b798 strb r0, [r8], #1 */
/* @0x29b79c cmp r8, r7 */
/* @0x29b7a0 bne 0x29b774 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0xcc> */
/* @0x29b7a4 ldr r3, [r4] */
/* @0x29b7a8 mov r1, #5 */
/* @0x29b7ac mov r2, r5 */
/* @0x29b7b0 mov r0, r4 */
/* @0x29b7b4 ldr r3, [r3, #0xc] */
/* @0x29b7b8 blx r3 */
/* @0x29b7bc mov r0, r5 */
/* @0x29b7c0 mov r1, #0 */
/* @0x29b7c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b7c8 cmp r0, #0 */
/* @0x29b7cc str r0, [r11, #-0x58] */
/* @0x29b7d0 movne r3, #0 */
/* @0x29b7d4 strne r3, [r11, #-0x54] */
/* @0x29b7d8 beq 0x29b8c4 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x21c> */
/* @0x29b7dc mov r0, r4 */
/* @0x29b7e0 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29b7e4 ldr r3, [r4] */
/* @0x29b7e8 mov r1, #5 */
/* @0x29b7ec mov r2, r5 */
/* @0x29b7f0 ldr r3, [r3, #0xc] */
/* @0x29b7f4 mov r8, r0 */
/* @0x29b7f8 mov r0, r4 */
/* @0x29b7fc blx r3 */
/* @0x29b800 mov r0, r5 */
/* @0x29b804 mov r1, #0 */
/* @0x29b808 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b80c cmp r0, #0 */
/* @0x29b810 str r0, [r11, #-0x50] */
/* @0x29b814 movne r7, #0 */
/* @0x29b818 beq 0x29b8a0 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x1f8> */
/* @0x29b81c ldr r3, [r4] */
/* @0x29b820 mov r2, r5 */
/* @0x29b824 mov r1, #5 */
/* @0x29b828 mov r0, r4 */
/* @0x29b82c add r7, r7, #1 */
/* @0x29b830 ldr r3, [r3, #0xc] */
/* @0x29b834 blx r3 */
/* @0x29b838 mov r1, #0 */
/* @0x29b83c mov r0, r5 */
/* @0x29b840 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b844 ldr r3, [r4] */
/* @0x29b848 mov r2, r5 */
/* @0x29b84c mov r1, #5 */
/* @0x29b850 ldr r3, [r3, #0xc] */
/* @0x29b854 mov r10, r0 */
/* @0x29b858 mov r0, r4 */
/* @0x29b85c blx r3 */
/* @0x29b860 mov r1, #0 */
/* @0x29b864 mov r0, r5 */
/* @0x29b868 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b86c mov r1, r10 */
/* @0x29b870 mov r9, r0 */
/* @0x29b874 mov r0, r8 */
/* @0x29b878 bl 0xd20c0 <_Z22New_Code_Variable_FindPKc13EVariableType> */
/* @0x29b87c add r3, r9, #4 */
/* @0x29b880 ldr r12, [r11, #-0x50] */
/* @0x29b884 ldr r2, [r6, r3] */
/* @0x29b888 cmp r7, r12 */
/* @0x29b88c and r2, r2, #-268435456 */
/* @0x29b890 bic r0, r0, #-268435456 */
/* @0x29b894 orr r2, r2, r0 */
/* @0x29b898 str r2, [r6, r3] */
/* @0x29b89c bne 0x29b81c <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x174> */
/* @0x29b8a0 ldr r12, [r11, #-0x54] */
/* @0x29b8a4 mov r0, r8 */
/* @0x29b8a8 add r12, r12, #1 */
/* @0x29b8ac str r12, [r11, #-0x54] */
/* @0x29b8b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29b8b4 ldr r3, [r11, #-0x54] */
/* @0x29b8b8 ldr r12, [r11, #-0x58] */
/* @0x29b8bc cmp r3, r12 */
/* @0x29b8c0 bne 0x29b7dc <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x134> */
/* @0x29b8c4 ldr r3, [r4] */
/* @0x29b8c8 mov r1, #5 */
/* @0x29b8cc mov r2, r5 */
/* @0x29b8d0 mov r0, r4 */
/* @0x29b8d4 ldr r3, [r3, #0xc] */
/* @0x29b8d8 blx r3 */
/* @0x29b8dc mov r0, r5 */
/* @0x29b8e0 mov r1, #0 */
/* @0x29b8e4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b8e8 cmp r0, #0 */
/* @0x29b8ec str r0, [r11, #-0x50] */
/* @0x29b8f0 subne r12, r11, #72 */
/* @0x29b8f4 strne r12, [r11, #-0x54] */
/* @0x29b8f8 movne r8, #0 */
/* @0x29b8fc beq 0x29b998 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x2f0> */
/* @0x29b900 mov r0, r4 */
/* @0x29b904 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29b908 sub r1, r11, #72 */
/* @0x29b90c mov r10, r0 */
/* @0x29b910 bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x29b914 ldr r12, [r4] */
/* @0x29b918 mov r1, #5 */
/* @0x29b91c mov r2, r5 */
/* @0x29b920 mov r0, r4 */
/* @0x29b924 ldr r12, [r12, #0xc] */
/* @0x29b928 blx r12 */
/* @0x29b92c mov r0, r5 */
/* @0x29b930 mov r1, #0 */
/* @0x29b934 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b938 subs r9, r0, #0 */
/* @0x29b93c movne r7, #0 */
/* @0x29b940 beq 0x29b980 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x2d8> */
/* @0x29b944 ldr r3, [r4] */
/* @0x29b948 mov r1, #5 */
/* @0x29b94c mov r2, r5 */
/* @0x29b950 mov r0, r4 */
/* @0x29b954 add r7, r7, #1 */
/* @0x29b958 ldr r3, [r3, #0xc] */
/* @0x29b95c blx r3 */
/* @0x29b960 mov r0, r5 */
/* @0x29b964 mov r1, #0 */
/* @0x29b968 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b96c ldr r3, [r11, #-0x48] */
/* @0x29b970 cmp r7, r9 */
/* @0x29b974 add r0, r6, r0 */
/* @0x29b978 str r3, [r0, #0x4] */
/* @0x29b97c bne 0x29b944 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x29c> */
/* @0x29b980 mov r0, r10 */
/* @0x29b984 add r8, r8, #1 */
/* @0x29b988 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29b98c ldr r3, [r11, #-0x50] */
/* @0x29b990 cmp r8, r3 */
/* @0x29b994 bne 0x29b900 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x258> */
/* @0x29b998 ldr r3, [r4] */
/* @0x29b99c mov r2, r5 */
/* @0x29b9a0 mov r1, #5 */
/* @0x29b9a4 mov r0, r4 */
/* @0x29b9a8 ldr r3, [r3, #0xc] */
/* @0x29b9ac blx r3 */
/* @0x29b9b0 mov r0, r5 */
/* @0x29b9b4 mov r1, #0 */
/* @0x29b9b8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29b9bc ldr r2, [pc, #0x1b0] */
/* @0x29b9c0 ldr r12, [r11, #-0x5c] */
/* @0x29b9c4 ldr r2, [r12, r2] */
/* @0x29b9c8 str r2, [r11, #-0x54] */
/* @0x29b9cc lsl r3, r0, #2 */
/* @0x29b9d0 cmp r0, #0 */
/* @0x29b9d4 add r3, r3, #14 */
/* @0x29b9d8 mov r7, r0 */
/* @0x29b9dc bic r3, r3, #7 */
/* @0x29b9e0 sub sp, sp, r3 */
/* @0x29b9e4 str sp, [r11, #-0x50] */
/* @0x29b9e8 str sp, [r2] */
/* @0x29b9ec beq 0x29ba14 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x36c> */
/* @0x29b9f0 ldr r12, [r11, #-0x50] */
/* @0x29b9f4 mov r8, #0 */
/* @0x29b9f8 sub r9, r12, #4 */
/* @0x29b9fc mov r0, r4 */
/* @0x29ba00 add r8, r8, #1 */
/* @0x29ba04 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29ba08 cmp r8, r7 */
/* @0x29ba0c str r0, [r9, #0x4]! */
/* @0x29ba10 bne 0x29b9fc <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x354> */
/* @0x29ba14 ldr r3, [r4] */
/* @0x29ba18 mov r1, #5 */
/* @0x29ba1c mov r2, r5 */
/* @0x29ba20 mov r0, r4 */
/* @0x29ba24 ldr r3, [r3, #0xc] */
/* @0x29ba28 blx r3 */
/* @0x29ba2c mov r0, r5 */
/* @0x29ba30 mov r1, #0 */
/* @0x29ba34 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29ba38 subs r9, r0, #0 */
/* @0x29ba3c movne r8, #0 */
/* @0x29ba40 movne r10, #0 */
/* @0x29ba44 movtne r8, #0xc007 */
/* @0x29ba48 beq 0x29ba84 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x3dc> */
/* @0x29ba4c ldr r3, [r4] */
/* @0x29ba50 mov r1, #5 */
/* @0x29ba54 mov r2, r5 */
/* @0x29ba58 mov r0, r4 */
/* @0x29ba5c add r10, r10, #1 */
/* @0x29ba60 ldr r3, [r3, #0xc] */
/* @0x29ba64 blx r3 */
/* @0x29ba68 mov r0, r5 */
/* @0x29ba6c mov r1, #0 */
/* @0x29ba70 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29ba74 cmp r10, r9 */
/* @0x29ba78 add r0, r6, r0 */
/* @0x29ba7c str r8, [r0, #-0x4] */
/* @0x29ba80 bne 0x29ba4c <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x3a4> */
/* @0x29ba84 ldr r3, [r11, #-0x6c] */
/* @0x29ba88 sub r1, r11, #68 */
/* @0x29ba8c ldr r12, [r11, #-0x68] */
/* @0x29ba90 ldr r0, [r11, #-0x74] */
/* @0x29ba94 ldr r2, [r11, #-0x60] */
/* @0x29ba98 str r3, [r12] */
/* @0x29ba9c bl 0x29a83c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue> */
/* @0x29baa0 cmp r7, #0 */
/* @0x29baa4 beq 0x29bac8 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x420> */
/* @0x29baa8 ldr r12, [r11, #-0x50] */
/* @0x29baac mov r4, #0 */
/* @0x29bab0 sub r10, r12, #4 */
/* @0x29bab4 add r4, r4, #1 */
/* @0x29bab8 ldr r0, [r10, #0x4]! */
/* @0x29babc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29bac0 cmp r4, r7 */
/* @0x29bac4 bne 0x29bab4 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x40c> */
/* @0x29bac8 ldr r12, [r11, #-0x70] */
/* @0x29bacc mov r4, #0 */
/* @0x29bad0 ldr r0, [r11, #-0x30] */
/* @0x29bad4 add r3, r12, #8 */
/* @0x29bad8 ldr r1, [r11, #-0x68] */
/* @0x29badc ldr r12, [r11, #-0x6c] */
/* @0x29bae0 cmp r0, r4 */
/* @0x29bae4 str r3, [r11, #-0x44] */
/* @0x29bae8 ldr r3, [r11, #-0x54] */
/* @0x29baec str r12, [r1] */
/* @0x29baf0 str r4, [r3] */
/* @0x29baf4 beq 0x29bb00 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x458> */
/* @0x29baf8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29bafc str r4, [r11, #-0x30] */
/* @0x29bb00 ldr r0, [r11, #-0x2c] */
/* @0x29bb04 cmp r0, #0 */
/* @0x29bb08 beq 0x29bb18 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x470> */
/* @0x29bb0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29bb10 mov r3, #0 */
/* @0x29bb14 str r3, [r11, #-0x2c] */
/* @0x29bb18 ldr r0, [r11, #-0x34] */
/* @0x29bb1c cmp r0, #0 */
/* @0x29bb20 beq 0x29bb40 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x498> */
/* @0x29bb24 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x29bb28 cmp r0, #0 */
/* @0x29bb2c bne 0x29bb40 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x498> */
/* @0x29bb30 ldr r0, [r11, #-0x34] */
/* @0x29bb34 cmp r0, #0 */
/* @0x29bb38 beq 0x29bb40 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x498> */
/* @0x29bb3c bl 0x27d1d4 <_ZdaPv> */
/* @0x29bb40 ldr r12, [r11, #-0x64] */
/* @0x29bb44 ldr r2, [r11, #-0x28] */
/* @0x29bb48 ldr r0, [r11, #-0x60] */
/* @0x29bb4c ldr r3, [r12] */
/* @0x29bb50 cmp r2, r3 */
/* @0x29bb54 bne 0x29bb60 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x4b8> */
/* @0x29bb58 sub sp, r11, #32 */
/* @0x29bb5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29bb60 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x29bb64 mulseq r5, r4, r5 */
/* @0x29bb68 .word 0xffffbd00 */
/* @0x29bb6c .word 0xffffbf58 */
/* @0x29bb70 .word 0xffffbedc */
/* @0x29bb74 .word 0xffffc118 */

/* ── FUNC 0x29bb78 · Debug_PokeStructure(Buffer_Standard*, Buffer_Standard*) · size=524 · insn=131 */
/* @0x29bb78 ldr r3, [r0] */
/* @0x29bb7c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29bb80 add r4, r0, #44 */
/* @0x29bb84 sub sp, sp, #20 */
/* @0x29bb88 ldr r3, [r3, #0xc] */
/* @0x29bb8c mov r2, r4 */
/* @0x29bb90 mov r10, r1 */
/* @0x29bb94 mov r1, #5 */
/* @0x29bb98 mov r11, r0 */
/* @0x29bb9c blx r3 */
/* @0x29bba0 mov r1, #0 */
/* @0x29bba4 mov r0, r4 */
/* @0x29bba8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29bbac ldr r3, [r11] */
/* @0x29bbb0 mov r2, r4 */
/* @0x29bbb4 mov r1, #5 */
/* @0x29bbb8 ldr r3, [r3, #0xc] */
/* @0x29bbbc mov r6, r0 */
/* @0x29bbc0 mov r0, r11 */
/* @0x29bbc4 blx r3 */
/* @0x29bbc8 mov r1, #0 */
/* @0x29bbcc mov r0, r4 */
/* @0x29bbd0 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29bbd4 ldr r3, [r11] */
/* @0x29bbd8 mov r2, r4 */
/* @0x29bbdc mov r1, #5 */
/* @0x29bbe0 ldr r3, [r3, #0xc] */
/* @0x29bbe4 mov r8, r0 */
/* @0x29bbe8 mov r0, r11 */
/* @0x29bbec blx r3 */
/* @0x29bbf0 mov r1, #0 */
/* @0x29bbf4 mov r0, r4 */
/* @0x29bbf8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29bbfc ldr r3, [r11] */
/* @0x29bc00 mov r2, r4 */
/* @0x29bc04 mov r1, #5 */
/* @0x29bc08 ldr r3, [r3, #0xc] */
/* @0x29bc0c mov r7, r0 */
/* @0x29bc10 mov r0, r11 */
/* @0x29bc14 blx r3 */
/* @0x29bc18 mov r1, #0 */
/* @0x29bc1c mov r0, r4 */
/* @0x29bc20 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29bc24 ldr r3, [r11] */
/* @0x29bc28 mov r2, r4 */
/* @0x29bc2c mov r1, #5 */
/* @0x29bc30 ldr r3, [r3, #0xc] */
/* @0x29bc34 mov r9, r0 */
/* @0x29bc38 mov r0, r11 */
/* @0x29bc3c blx r3 */
/* @0x29bc40 mov r0, r4 */
/* @0x29bc44 mov r1, #0 */
/* @0x29bc48 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29bc4c cmp r0, #1 */
/* @0x29bc50 beq 0x29bcdc <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x164> */
/* @0x29bc54 ldr r3, [r11] */
/* @0x29bc58 mov r2, r4 */
/* @0x29bc5c mov r1, #0 */
/* @0x29bc60 mov r0, r11 */
/* @0x29bc64 str r1, [sp, #0xc] */
/* @0x29bc68 mov r1, #9 */
/* @0x29bc6c ldr r3, [r3, #0xc] */
/* @0x29bc70 blx r3 */
/* @0x29bc74 ldr r4, [r11, #0x2c] */
/* @0x29bc78 ldr r5, [r11, #0x30] */
/* @0x29bc7c strd r4, r5, [sp] */
/* @0x29bc80 cmp r6, #5 */
/* @0x29bc84 addls pc, pc, r6, lsl #2 */
/* @0x29bc88 b 0x29bca4 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x12c> */
/* @0x29bc8c b 0x29bd20 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1a8> */
/* @0x29bc90 b 0x29bd34 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1bc> */
/* @0x29bc94 b 0x29bd48 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1d0> */
/* @0x29bc98 b 0x29bd5c <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1e4> */
/* @0x29bc9c b 0x29bd70 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1f8> */
/* @0x29bca0 b 0x29bcf4 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x17c> */
/* @0x29bca4 mov r3, #0 */
/* @0x29bca8 mov r1, r3 */
/* @0x29bcac mov r2, r10 */
/* @0x29bcb0 str r3, [r10, #0x2c] */
/* @0x29bcb4 ldr r3, [r2], #44 */
/* @0x29bcb8 mov r12, #0 */
/* @0x29bcbc str r1, [r10, #0x30] */
/* @0x29bcc0 mov r0, r10 */
/* @0x29bcc4 str r12, [r10, #0x38] */
/* @0x29bcc8 mov r1, #5 */
/* @0x29bccc ldr r3, [r3, #0x8] */
/* @0x29bcd0 blx r3 */
/* @0x29bcd4 add sp, sp, #20 */
/* @0x29bcd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29bcdc mov r0, r11 */
/* @0x29bce0 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29bce4 mov r1, r0 */
/* @0x29bce8 mov r0, sp */
/* @0x29bcec bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x29bcf0 b 0x29bc80 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x108> */
/* @0x29bcf4 mov r0, r8 */
/* @0x29bcf8 mov r1, r7 */
/* @0x29bcfc mov r2, r9 */
/* @0x29bd00 mov r3, sp */
/* @0x29bd04 bl 0xe9bd8 <_ZN2VM10PokeDSGridEiiiR6RValue> */
/* @0x29bd08 cmp r0, #0 */
/* @0x29bd0c beq 0x29bca4 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x12c> */
/* @0x29bd10 mov r1, #0 */
/* @0x29bd14 mov r3, #0 */
/* @0x29bd18 movt r1, #0x3ff0 */
/* @0x29bd1c b 0x29bcac <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x134> */
/* @0x29bd20 mov r0, r8 */
/* @0x29bd24 mov r1, r7 */
/* @0x29bd28 mov r2, sp */
/* @0x29bd2c bl 0xe4ba8 <_ZN2VM10PokeDSListEiiR6RValue> */
/* @0x29bd30 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190> */
/* @0x29bd34 mov r0, r8 */
/* @0x29bd38 mov r1, r7 */
/* @0x29bd3c mov r2, sp */
/* @0x29bd40 bl 0xe6364 <_ZN2VM9PokeDSMapEiiR6RValue> */
/* @0x29bd44 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190> */
/* @0x29bd48 mov r0, r8 */
/* @0x29bd4c mov r1, r7 */
/* @0x29bd50 mov r2, sp */
/* @0x29bd54 bl 0xe4d6c <_ZN2VM11PokeDSStackEiiR6RValue> */
/* @0x29bd58 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190> */
/* @0x29bd5c mov r0, r8 */
/* @0x29bd60 mov r1, r7 */
/* @0x29bd64 mov r2, sp */
/* @0x29bd68 bl 0xe4f18 <_ZN2VM11PokeDSQueueEiiR6RValue> */
/* @0x29bd6c b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190> */
/* @0x29bd70 mov r0, r8 */
/* @0x29bd74 mov r1, r7 */
/* @0x29bd78 mov r2, sp */
/* @0x29bd7c bl 0xe50b4 <_ZN2VM14PokeDSPriorityEiiR6RValue> */
/* @0x29bd80 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190> */

/* ── FUNC 0x29bd84 · Debug_GetStructures(Buffer_Standard*, Buffer_Standard*) · size=580 · insn=145 */
/* @0x29bd84 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29bd88 vpush {d8} */
/* @0x29bd8c add r6, r0, #44 */
/* @0x29bd90 ldr lr, [r0] */
/* @0x29bd94 mov r10, r1 */
/* @0x29bd98 sub sp, sp, #12 */
/* @0x29bd9c mov r2, r6 */
/* @0x29bda0 mov r8, #0 */
/* @0x29bda4 mov r1, #5 */
/* @0x29bda8 ldr r4, [lr, #0xc] */
/* @0x29bdac mov r11, r0 */
/* @0x29bdb0 blx r4 */
/* @0x29bdb4 mov r1, r8 */
/* @0x29bdb8 mov r0, r6 */
/* @0x29bdbc add r7, r10, #44 */
/* @0x29bdc0 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29bdc4 ldr lr, [r10] */
/* @0x29bdc8 mov r2, r7 */
/* @0x29bdcc str r8, [r10, #0x38] */
/* @0x29bdd0 mov r1, #5 */
/* @0x29bdd4 vmov s15, r0 */
/* @0x29bdd8 str r0, [sp, #0x4] */
/* @0x29bddc mov r0, r10 */
/* @0x29bde0 vcvt.f64.u32 d7, s15 */
/* @0x29bde4 vmov r4, r5, d7 */
/* @0x29bde8 vstr s14, [r10, #44] */
/* @0x29bdec str r5, [r10, #0x30] */
/* @0x29bdf0 ldr r4, [lr, #0x8] */
/* @0x29bdf4 blx r4 */
/* @0x29bdf8 ldr r3, [sp, #0x4] */
/* @0x29bdfc cmp r3, r8 */
/* @0x29be00 ble 0x29bf58 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1d4> */
/* @0x29be04 mov r9, r8 */
/* @0x29be08 ldr lr, [r11] */
/* @0x29be0c mov r2, r6 */
/* @0x29be10 mov r1, #5 */
/* @0x29be14 mov r0, r11 */
/* @0x29be18 ldr r4, [lr, #0xc] */
/* @0x29be1c blx r4 */
/* @0x29be20 mov r1, #0 */
/* @0x29be24 mov r0, r6 */
/* @0x29be28 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29be2c ldr lr, [r11] */
/* @0x29be30 mov r2, r6 */
/* @0x29be34 mov r1, #5 */
/* @0x29be38 ldr r4, [lr, #0xc] */
/* @0x29be3c vmov s16, r0 */
/* @0x29be40 mov r0, r11 */
/* @0x29be44 blx r4 */
/* @0x29be48 mov r1, #0 */
/* @0x29be4c mov r0, r6 */
/* @0x29be50 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29be54 ldr lr, [r11] */
/* @0x29be58 mov r2, r6 */
/* @0x29be5c mov r1, #5 */
/* @0x29be60 ldr r4, [lr, #0xc] */
/* @0x29be64 vmov s17, r0 */
/* @0x29be68 mov r0, r11 */
/* @0x29be6c blx r4 */
/* @0x29be70 mov r1, #0 */
/* @0x29be74 mov r0, r6 */
/* @0x29be78 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29be7c vcvt.f64.u32 d7, s16 */
/* @0x29be80 ldr lr, [r10] */
/* @0x29be84 mov r1, #5 */
/* @0x29be88 mov r2, r7 */
/* @0x29be8c str r9, [r10, #0x38] */
/* @0x29be90 vmov r4, r5, d7 */
/* @0x29be94 vstr s14, [r10, #44] */
/* @0x29be98 str r5, [r10, #0x30] */
/* @0x29be9c ldr r4, [lr, #0x8] */
/* @0x29bea0 str r0, [sp] */
/* @0x29bea4 mov r0, r10 */
/* @0x29bea8 blx r4 */
/* @0x29beac vcvt.f64.u32 d7, s17 */
/* @0x29beb0 ldr lr, [r10] */
/* @0x29beb4 mov r1, #5 */
/* @0x29beb8 mov r2, r7 */
/* @0x29bebc mov r0, r10 */
/* @0x29bec0 str r9, [r10, #0x38] */
/* @0x29bec4 vmov r4, r5, d7 */
/* @0x29bec8 vstr s14, [r10, #44] */
/* @0x29becc str r5, [r10, #0x30] */
/* @0x29bed0 ldr r4, [lr, #0x8] */
/* @0x29bed4 blx r4 */
/* @0x29bed8 ldr r3, [sp] */
/* @0x29bedc ldr lr, [r10] */
/* @0x29bee0 mov r0, r10 */
/* @0x29bee4 bic r4, r3, r3, asr #31 */
/* @0x29bee8 str r9, [r10, #0x38] */
/* @0x29beec mov r1, #5 */
/* @0x29bef0 mov r2, r7 */
/* @0x29bef4 vmov s15, r4 */
/* @0x29bef8 vcvt.f64.s32 d7, s15 */
/* @0x29befc vmov r4, r5, d7 */
/* @0x29bf00 vstr s14, [r10, #44] */
/* @0x29bf04 str r5, [r10, #0x30] */
/* @0x29bf08 ldr r4, [lr, #0x8] */
/* @0x29bf0c blx r4 */
/* @0x29bf10 vmov r3, s16 */
/* @0x29bf14 cmp r3, #5 */
/* @0x29bf18 addls pc, pc, r3, lsl #2 */
/* @0x29bf1c b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4> */
/* @0x29bf20 b 0x29bf78 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1f4> */
/* @0x29bf24 b 0x29bf64 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1e0> */
/* @0x29bf28 b 0x29bfa0 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x21c> */
/* @0x29bf2c b 0x29bf8c <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x208> */
/* @0x29bf30 b 0x29bfb4 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x230> */
/* @0x29bf34 b 0x29bf38 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1b4> */
/* @0x29bf38 vmov r1, s17 */
/* @0x29bf3c mov r0, r10 */
/* @0x29bf40 ldr r2, [sp] */
/* @0x29bf44 bl 0xdb70c <_ZN2VM9GetDSGridEP15Buffer_Standardii> */
/* @0x29bf48 ldr r3, [sp, #0x4] */
/* @0x29bf4c add r8, r8, #1 */
/* @0x29bf50 cmp r3, r8 */
/* @0x29bf54 bne 0x29be08 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x84> */
/* @0x29bf58 add sp, sp, #12 */
/* @0x29bf5c vpop {d8} */
/* @0x29bf60 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29bf64 vmov r1, s17 */
/* @0x29bf68 mov r0, r10 */
/* @0x29bf6c ldr r2, [sp] */
/* @0x29bf70 bl 0xdb4b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii> */
/* @0x29bf74 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4> */
/* @0x29bf78 vmov r1, s17 */
/* @0x29bf7c mov r0, r10 */
/* @0x29bf80 ldr r2, [sp] */
/* @0x29bf84 bl 0xdb130 <_ZN2VM9GetDSListEP15Buffer_Standardii> */
/* @0x29bf88 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4> */
/* @0x29bf8c vmov r1, s17 */
/* @0x29bf90 mov r0, r10 */
/* @0x29bf94 ldr r2, [sp] */
/* @0x29bf98 bl 0xdb2dc <_ZN2VM10GetDSQueueEP15Buffer_Standardii> */
/* @0x29bf9c b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4> */
/* @0x29bfa0 vmov r1, s17 */
/* @0x29bfa4 mov r0, r10 */
/* @0x29bfa8 ldr r2, [sp] */
/* @0x29bfac bl 0xdb210 <_ZN2VM10GetDSStackEP15Buffer_Standardii> */
/* @0x29bfb0 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4> */
/* @0x29bfb4 vmov r1, s17 */
/* @0x29bfb8 mov r0, r10 */
/* @0x29bfbc ldr r2, [sp] */
/* @0x29bfc0 bl 0xdb3b0 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii> */
/* @0x29bfc4 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4> */

/* ── FUNC 0x29bfc8 · Debug_InitRemoteInterface() · size=4 · insn=1 */
/* @0x29bfc8 bx lr */

/* ── FUNC 0x29bfcc · Debug_BufferOutput(char const*) · size=180 · insn=45 */
/* @0x29bfcc push {r4, r5, r6, r7, r8, lr} */
/* @0x29bfd0 mov r5, r0 */
/* @0x29bfd4 ldr r4, [pc, #0x94] */
/* @0x29bfd8 add r4, pc, r4 */
/* @0x29bfdc ldr r6, [r4] */
/* @0x29bfe0 cmp r6, #0 */
/* @0x29bfe4 beq 0x29c038 <_Z18Debug_BufferOutputPKc+0x6c> */
/* @0x29bfe8 ldr r7, [r4, #0x4] */
/* @0x29bfec mov r0, r5 */
/* @0x29bff0 bl 0xb6538 <strlen@plt> */
/* @0x29bff4 movw r3, #0x7ffe */
/* @0x29bff8 add r6, r7, r0 */
/* @0x29bffc mov r4, r0 */
/* @0x29c000 cmp r6, r3 */
/* @0x29c004 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x29c008 ldr r8, [pc, #0x64] */
/* @0x29c00c mov r2, r0 */
/* @0x29c010 mov r1, r5 */
/* @0x29c014 add r8, pc, r8 */
/* @0x29c018 ldr r3, [r8] */
/* @0x29c01c add r7, r3, r7 */
/* @0x29c020 mov r0, r7 */
/* @0x29c024 bl 0xb65bc <memcpy@plt> */
/* @0x29c028 mov r3, #0 */
/* @0x29c02c str r6, [r8, #0x4] */
/* @0x29c030 strb r3, [r7, r4] */
/* @0x29c034 pop {r4, r5, r6, r7, r8, pc} */
/* @0x29c038 ldr r1, [pc, #0x38] */
/* @0x29c03c movw r2, #0x3a1 */
/* @0x29c040 mov r3, #1 */
/* @0x29c044 mov r0, #32768 */
/* @0x29c048 add r1, pc, r1 */
/* @0x29c04c mov r7, r6 */
/* @0x29c050 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29c054 ldr r3, [pc, #0x20] */
/* @0x29c058 mov r2, #32768 */
/* @0x29c05c str r6, [r4, #0x4] */
/* @0x29c060 ldr r3, [pc, r3] */
/* @0x29c064 str r2, [r3] */
/* @0x29c068 str r0, [r4] */
/* @0x29c06c b 0x29bfec <_Z18Debug_BufferOutputPKc+0x20> */
/* @0x29c070 subeq r11, r11, r0, lsr r12 */
/* @0x29c074 strdeq r11, r12, [r11], #-180 */
/* @0x29c078 andeq sp, r11, r12, ror r9 */
/* @0x29c07c andseq r5, r5, r8, lsr #19 */

/* ── FUNC 0x29c080 · Debug_WriteOutput(Buffer_Standard*) · size=136 · insn=34 */
/* @0x29c080 push {r4, r5, r6, r7, r8, lr} */
/* @0x29c084 mov r7, r0 */
/* @0x29c088 ldr r6, [pc, #0x70] */
/* @0x29c08c add r6, pc, r6 */
/* @0x29c090 ldr r3, [r6] */
/* @0x29c094 cmp r3, #0 */
/* @0x29c098 beq 0x29c0f0 <_Z17Debug_WriteOutputP15Buffer_Standard+0x70> */
/* @0x29c09c ldr r4, [r6, #0x4] */
/* @0x29c0a0 mov r2, r0 */
/* @0x29c0a4 ldr r3, [r2], #44 */
/* @0x29c0a8 mov r8, #0 */
/* @0x29c0ac add r4, r4, #1 */
/* @0x29c0b0 str r8, [r0, #0x38] */
/* @0x29c0b4 mov r1, #5 */
/* @0x29c0b8 vmov s15, r4 */
/* @0x29c0bc vcvt.f64.u32 d7, s15 */
/* @0x29c0c0 vmov r4, r5, d7 */
/* @0x29c0c4 vstr s14, [r7, #44] */
/* @0x29c0c8 str r5, [r7, #0x30] */
/* @0x29c0cc ldr r3, [r3, #0x8] */
/* @0x29c0d0 blx r3 */
/* @0x29c0d4 mov r0, r7 */
/* @0x29c0d8 ldr r1, [r6] */
/* @0x29c0dc bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x29c0e0 ldr r3, [r6] */
/* @0x29c0e4 str r8, [r6, #0x4] */
/* @0x29c0e8 strb r8, [r3] */
/* @0x29c0ec pop {r4, r5, r6, r7, r8, pc} */
/* @0x29c0f0 ldr r1, [pc, #0xc] */
/* @0x29c0f4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x29c0f8 add r1, pc, r1 */
/* @0x29c0fc b 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29c100 subeq r11, r11, r12, ror r11 */
/* @0x29c104 andeq r2, r9, lr, lsr r10 */

/* ── FUNC 0x29c108 · Debug_WriteErrorMessage(Buffer_Standard*) · size=64 · insn=16 */
/* @0x29c108 push {r4, lr} */
/* @0x29c10c ldr r4, [pc, #0x2c] */
/* @0x29c110 ldr r4, [pc, r4] */
/* @0x29c114 ldr r1, [r4] */
/* @0x29c118 cmp r1, #0 */
/* @0x29c11c beq 0x29c130 <_Z23Debug_WriteErrorMessageP15Buffer_Standard+0x28> */
/* @0x29c120 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29c124 mov r3, #0 */
/* @0x29c128 str r3, [r4] */
/* @0x29c12c pop {r4, pc} */
/* @0x29c130 ldr r1, [pc, #0xc] */
/* @0x29c134 pop {r4, lr} */
/* @0x29c138 add r1, pc, r1 */
/* @0x29c13c b 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29c140 andseq r1, r5, r12, ror r12 */
/* @0x29c144 strdeq r2, r3, [r9], -lr */

/* ── FUNC 0x29c148 · Debug_WriteProfileData(Buffer_Standard*) · size=20 · insn=5 */
/* @0x29c148 ldr r3, [pc, #0x8] */
/* @0x29c14c mov r1, r0 */
/* @0x29c150 ldr r0, [pc, r3] */
/* @0x29c154 b 0x2a0ae0 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard> */
/* @0x29c158 andseq r1, r5, r12, lsl r10 */

/* ── FUNC 0x29c15c · Debug_WriteSurfaceIds(Buffer_Standard*, bool) · size=584 · insn=146 */
/* @0x29c15c subs r3, r1, #0 */
/* @0x29c160 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29c164 mov r7, r0 */
/* @0x29c168 sub sp, sp, #12 */
/* @0x29c16c beq 0x29c368 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x20c> */
/* @0x29c170 ldr r9, [pc, #0x220] */
/* @0x29c174 add r6, r0, #44 */
/* @0x29c178 ldr r3, [r0] */
/* @0x29c17c mov r8, #0 */
/* @0x29c180 ldr r9, [pc, r9] */
/* @0x29c184 vldr s15, [r9] */
/* @0x29c188 vcvt.f64.s32 d7, s15 */
/* @0x29c18c str r8, [r0, #0x38] */
/* @0x29c190 mov r2, r6 */
/* @0x29c194 mov r1, #6 */
/* @0x29c198 vmov r4, r5, d7 */
/* @0x29c19c vstr s14, [r7, #44] */
/* @0x29c1a0 str r5, [r7, #0x30] */
/* @0x29c1a4 ldr r3, [r3, #0x8] */
/* @0x29c1a8 blx r3 */
/* @0x29c1ac ldr r3, [r9] */
/* @0x29c1b0 cmp r3, r8 */
/* @0x29c1b4 ble 0x29c360 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x204> */
/* @0x29c1b8 ldr r3, [pc, #0x1dc] */
/* @0x29c1bc mov r1, #6 */
/* @0x29c1c0 ldr r12, [r7] */
/* @0x29c1c4 mov r2, r6 */
/* @0x29c1c8 ldr r3, [pc, r3] */
/* @0x29c1cc mov r0, r7 */
/* @0x29c1d0 str r8, [r7, #0x38] */
/* @0x29c1d4 ldr r4, [r3] */
/* @0x29c1d8 ldr r9, [pc, #0x1c0] */
/* @0x29c1dc vmov s15, r4 */
/* @0x29c1e0 vcvt.f64.s32 d7, s15 */
/* @0x29c1e4 vmov r4, r5, d7 */
/* @0x29c1e8 vstr s14, [r7, #44] */
/* @0x29c1ec str r5, [r7, #0x30] */
/* @0x29c1f0 ldr r3, [r12, #0x8] */
/* @0x29c1f4 blx r3 */
/* @0x29c1f8 ldr r3, [r7] */
/* @0x29c1fc ldr r12, [r7, #0x1c] */
/* @0x29c200 mov r1, #5 */
/* @0x29c204 str r8, [r7, #0x2c] */
/* @0x29c208 mov r2, r6 */
/* @0x29c20c str r8, [r7, #0x30] */
/* @0x29c210 mov r0, r7 */
/* @0x29c214 str r8, [r7, #0x38] */
/* @0x29c218 ldr r3, [r3, #0x8] */
/* @0x29c21c str r12, [sp, #0x4] */
/* @0x29c220 blx r3 */
/* @0x29c224 ldr r9, [pc, r9] */
/* @0x29c228 mov r2, r8 */
/* @0x29c22c ldr r1, [r9] */
/* @0x29c230 ldr r0, [r9, #0x4] */
/* @0x29c234 b 0x29c240 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0xe4> */
/* @0x29c238 cmp r0, r2 */
/* @0x29c23c blt 0x29c390 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x234> */
/* @0x29c240 ldr r11, [r1, r2, lsl #3] */
/* @0x29c244 mov r10, r2 */
/* @0x29c248 add r2, r2, #1 */
/* @0x29c24c cmp r11, #0 */
/* @0x29c250 beq 0x29c238 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0xdc> */
/* @0x29c254 ldr r2, [r11, #0xc] */
/* @0x29c258 cmp r2, #0 */
/* @0x29c25c moveq r8, r2 */
/* @0x29c260 beq 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c> */
/* @0x29c264 mov r8, #0 */
/* @0x29c268 b 0x29c278 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x11c> */
/* @0x29c26c ldr r2, [r11, #0xc] */
/* @0x29c270 cmp r2, #0 */
/* @0x29c274 beq 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c> */
/* @0x29c278 ldr r4, [r2] */
/* @0x29c27c mov r3, #0 */
/* @0x29c280 ldr lr, [r7] */
/* @0x29c284 mov r0, r7 */
/* @0x29c288 str r3, [r7, #0x38] */
/* @0x29c28c mov r1, #5 */
/* @0x29c290 vmov s15, r4 */
/* @0x29c294 mov r2, r6 */
/* @0x29c298 add r8, r8, #1 */
/* @0x29c29c vcvt.f64.u32 d7, s15 */
/* @0x29c2a0 vmov r4, r5, d7 */
/* @0x29c2a4 vstr s14, [r7, #44] */
/* @0x29c2a8 str r5, [r7, #0x30] */
/* @0x29c2ac ldr r4, [lr, #0x8] */
/* @0x29c2b0 blx r4 */
/* @0x29c2b4 ldr r11, [r11, #0x4] */
/* @0x29c2b8 cmp r11, #0 */
/* @0x29c2bc bne 0x29c26c <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x110> */
/* @0x29c2c0 ldr r0, [r9, #0x4] */
/* @0x29c2c4 add r2, r10, #1 */
/* @0x29c2c8 cmp r2, r0 */
/* @0x29c2cc bgt 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c> */
/* @0x29c2d0 ldr r1, [r9] */
/* @0x29c2d4 add r1, r1, r10, lsl #3 */
/* @0x29c2d8 ldr r11, [r1, #0x8] */
/* @0x29c2dc mov r10, r2 */
/* @0x29c2e0 add r1, r1, #8 */
/* @0x29c2e4 add r2, r2, #1 */
/* @0x29c2e8 cmp r11, #0 */
/* @0x29c2ec bne 0x29c26c <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x110> */
/* @0x29c2f0 cmp r2, r0 */
/* @0x29c2f4 ble 0x29c2d8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x17c> */
/* @0x29c2f8 ldr r3, [r7] */
/* @0x29c2fc mov r1, #0 */
/* @0x29c300 ldr r2, [sp, #0x4] */
/* @0x29c304 mov r0, r7 */
/* @0x29c308 mov r9, r1 */
/* @0x29c30c ldr r10, [r7, #0x1c] */
/* @0x29c310 ldr r3, [r3, #0x10] */
/* @0x29c314 blx r3 */
/* @0x29c318 vmov s15, r8 */
/* @0x29c31c ldr r3, [r7] */
/* @0x29c320 mov r2, r6 */
/* @0x29c324 vcvt.f64.s32 d7, s15 */
/* @0x29c328 mov r1, #5 */
/* @0x29c32c str r9, [r7, #0x38] */
/* @0x29c330 mov r0, r7 */
/* @0x29c334 vmov r4, r5, d7 */
/* @0x29c338 vstr s14, [r7, #44] */
/* @0x29c33c str r5, [r7, #0x30] */
/* @0x29c340 ldr r3, [r3, #0x8] */
/* @0x29c344 blx r3 */
/* @0x29c348 ldr r3, [r7] */
/* @0x29c34c mov r1, r9 */
/* @0x29c350 mov r2, r10 */
/* @0x29c354 mov r0, r7 */
/* @0x29c358 ldr r3, [r3, #0x10] */
/* @0x29c35c blx r3 */
/* @0x29c360 add sp, sp, #12 */
/* @0x29c364 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29c368 mov r2, r0 */
/* @0x29c36c str r3, [r0, #0x2c] */
/* @0x29c370 ldr r12, [r2], #44 */
/* @0x29c374 mov r1, #5 */
/* @0x29c378 str r3, [r0, #0x30] */
/* @0x29c37c str r3, [r0, #0x38] */
/* @0x29c380 ldr r3, [r12, #0x8] */
/* @0x29c384 blx r3 */
/* @0x29c388 add sp, sp, #12 */
/* @0x29c38c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29c390 mov r8, r11 */
/* @0x29c394 b 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c> */
/* @0x29c398 andseq r4, r5, r0, lsr r1 */
/* @0x29c39c andseq r2, r5, r0, lsl r4 */
/* @0x29c3a0 andseq r1, r5, r12, ror #17 */

/* ── FUNC 0x29c3a4 · endian_swap(unsigned int) · size=4 · insn=1 */
/* @0x29c3a4 bx lr */

/* ── FUNC 0x29c3a8 · Debug_QueryHeapMem(unsigned int&, unsigned long long&) · size=68 · insn=17 */
/* @0x29c3a8 push {r4, r5, r6, lr} */
/* @0x29c3ac sub sp, sp, #40 */
/* @0x29c3b0 mov r5, r0 */
/* @0x29c3b4 mov r6, #0 */
/* @0x29c3b8 mov r2, #0 */
/* @0x29c3bc str r6, [r0] */
/* @0x29c3c0 mov r3, #0 */
/* @0x29c3c4 mov r0, sp */
/* @0x29c3c8 strd r2, r3, [r1] */
/* @0x29c3cc mov r4, r1 */
/* @0x29c3d0 bl 0xb6e8c <mallinfo@plt> */
/* @0x29c3d4 ldr r2, [sp, #0x1c] */
/* @0x29c3d8 ldr r3, [sp, #0x20] */
/* @0x29c3dc str r2, [r5] */
/* @0x29c3e0 stm r4, {r3, r6} */
/* @0x29c3e4 add sp, sp, #40 */
/* @0x29c3e8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x29c3ec · Debug_AddTag(eTagNameType, char const*, ...) · size=476 · insn=119 */
/* @0x29c3ec push {r1, r2, r3} */
/* @0x29c3f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x29c3f4 mov r6, r0 */
/* @0x29c3f8 ldr r4, [pc, #0x1a4] */
/* @0x29c3fc sub sp, sp, #12 */
/* @0x29c400 add r4, pc, r4 */
/* @0x29c404 ldrh r3, [r4, #8] */
/* @0x29c408 cmp r3, #4096 */
/* @0x29c40c blo 0x29c42c <_Z12Debug_AddTag12eTagNameTypePKcz+0x40> */
/* @0x29c410 ldrb r3, [r4, #0xa] */
/* @0x29c414 cmp r3, #0 */
/* @0x29c418 beq 0x29c53c <_Z12Debug_AddTag12eTagNameTypePKcz+0x150> */
/* @0x29c41c add sp, sp, #12 */
/* @0x29c420 pop {r4, r5, r6, r7, r8, lr} */
/* @0x29c424 add sp, sp, #12 */
/* @0x29c428 bx lr */
/* @0x29c42c ldr r2, [r4, #0xc] */
/* @0x29c430 cmp r2, #0 */
/* @0x29c434 beq 0x29c578 <_Z12Debug_AddTag12eTagNameTypePKcz+0x18c> */
/* @0x29c438 ldr r12, [pc, #0x168] */
/* @0x29c43c add r3, r3, #1 */
/* @0x29c440 add r12, pc, r12 */
/* @0x29c444 ldrh r2, [r12] */
/* @0x29c448 cmp r3, r2 */
/* @0x29c44c blt 0x29c498 <_Z12Debug_AddTag12eTagNameTypePKcz+0xac> */
/* @0x29c450 lsl r0, r2, #1 */
/* @0x29c454 ldr r1, [pc, #0x150] */
/* @0x29c458 mov r3, #1 */
/* @0x29c45c movw r2, #0x4c1 */
/* @0x29c460 uxth r0, r0 */
/* @0x29c464 add r1, pc, r1 */
/* @0x29c468 strh r0, [r12] */
/* @0x29c46c lsl r0, r0, #2 */
/* @0x29c470 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29c474 ldr r5, [r4, #0xc] */
/* @0x29c478 ldrh r2, [r4, #8] */
/* @0x29c47c mov r1, r5 */
/* @0x29c480 lsl r2, r2, #2 */
/* @0x29c484 mov r7, r0 */
/* @0x29c488 bl 0xb65bc <memcpy@plt> */
/* @0x29c48c mov r0, r5 */
/* @0x29c490 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29c494 str r7, [r4, #0xc] */
/* @0x29c498 ldr r4, [pc, #0x110] */
/* @0x29c49c add r0, sp, #40 */
/* @0x29c4a0 ldr r2, [sp, #0x24] */
/* @0x29c4a4 mov r1, #512 */
/* @0x29c4a8 add r4, pc, r4 */
/* @0x29c4ac mov r3, r0 */
/* @0x29c4b0 add r5, r4, #16 */
/* @0x29c4b4 str r0, [sp, #0x4] */
/* @0x29c4b8 ldr r7, [pc, #0xf4] */
/* @0x29c4bc mov r0, r5 */
/* @0x29c4c0 bl 0xb6610 <vsnprintf@plt> */
/* @0x29c4c4 mov r0, r5 */
/* @0x29c4c8 mov r3, #0 */
/* @0x29c4cc strb r3, [r4, #0x20f] */
/* @0x29c4d0 bl 0xb6538 <strlen@plt> */
/* @0x29c4d4 add r7, pc, r7 */
/* @0x29c4d8 mov r3, #1 */
/* @0x29c4dc movw r2, #0x4cd */
/* @0x29c4e0 mov r1, r7 */
/* @0x29c4e4 add r0, r0, r3 */
/* @0x29c4e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29c4ec mov r1, r5 */
/* @0x29c4f0 mov r8, r0 */
/* @0x29c4f4 bl 0xb65a4 <strcpy@plt> */
/* @0x29c4f8 mov r1, r7 */
/* @0x29c4fc mov r2, #1232 */
/* @0x29c500 mov r3, #1 */
/* @0x29c504 mov r0, #8 */
/* @0x29c508 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29c50c ldrh r2, [r4, #8] */
/* @0x29c510 ldr r1, [r4, #0xc] */
/* @0x29c514 mov r3, r0 */
/* @0x29c518 str r6, [r0] */
/* @0x29c51c add r0, r2, #1 */
/* @0x29c520 str r8, [r3, #0x4] */
/* @0x29c524 strh r0, [r4, #8] */
/* @0x29c528 str r3, [r1, r2, lsl #2] */
/* @0x29c52c add sp, sp, #12 */
/* @0x29c530 pop {r4, r5, r6, r7, r8, lr} */
/* @0x29c534 add sp, sp, #12 */
/* @0x29c538 bx lr */
/* @0x29c53c ldr r3, [pc, #0x74] */
/* @0x29c540 mov r2, #4096 */
/* @0x29c544 ldr r1, [pc, #0x70] */
/* @0x29c548 ldr r3, [pc, r3] */
/* @0x29c54c add r1, pc, r1 */
/* @0x29c550 ldr r0, [r3] */
/* @0x29c554 ldr r3, [r0] */
/* @0x29c558 ldr r3, [r3, #0xc] */
/* @0x29c55c blx r3 */
/* @0x29c560 mov r3, #1 */
/* @0x29c564 strb r3, [r4, #0xa] */
/* @0x29c568 add sp, sp, #12 */
/* @0x29c56c pop {r4, r5, r6, r7, r8, lr} */
/* @0x29c570 add sp, sp, #12 */
/* @0x29c574 bx lr */
/* @0x29c578 ldr r0, [pc, #0x40] */
/* @0x29c57c movw r2, #0x4bd */
/* @0x29c580 ldr r1, [pc, #0x3c] */
/* @0x29c584 mov r3, #1 */
/* @0x29c588 add r0, pc, r0 */
/* @0x29c58c add r1, pc, r1 */
/* @0x29c590 ldrh r0, [r0] */
/* @0x29c594 lsl r0, r0, #2 */
/* @0x29c598 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29c59c str r0, [r4, #0xc] */
/* @0x29c5a0 b 0x29c498 <_Z12Debug_AddTag12eTagNameTypePKcz+0xac> */
/* @0x29c5a4 subeq r11, r11, r8, lsl #16 */
/* @0x29c5a8 ldrsbeq r11, [r5], -r0 */
/* @0x29c5ac andeq sp, r11, r0, ror #10 */
/* @0x29c5b0 subeq r11, r11, r0, ror #14 */
/* @0x29c5b4 strdeq sp, lr, [r11], -r0 */
/* @0x29c5b8 ldrsheq r1, [r5], -r8 */
/* @0x29c5bc ldrdeq sp, lr, [r11], -r4 */
/* @0x29c5c0 andseq r11, r5, r8, lsl #5 */
/* @0x29c5c4 andeq sp, r11, r8, lsr r4 */

/* ── FUNC 0x29c5c8 · Debug_FreeTags() · size=64 · insn=16 */
/* @0x29c5c8 push {r3, r4, r5, lr} */
/* @0x29c5cc ldr r5, [pc, #0x30] */
/* @0x29c5d0 add r5, pc, r5 */
/* @0x29c5d4 ldrh r3, [r5, #8] */
/* @0x29c5d8 cmp r3, #0 */
/* @0x29c5dc popeq {r3, r4, r5, pc} */
/* @0x29c5e0 mov r4, #0 */
/* @0x29c5e4 ldr r3, [r5, #0xc] */
/* @0x29c5e8 ldr r0, [r3, r4, lsl #2] */
/* @0x29c5ec add r4, r4, #1 */
/* @0x29c5f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29c5f4 ldrh r3, [r5, #8] */
/* @0x29c5f8 cmp r3, r4 */
/* @0x29c5fc bgt 0x29c5e4 <_Z14Debug_FreeTagsv+0x1c> */
/* @0x29c600 pop {r3, r4, r5, pc} */
/* @0x29c604 subeq r11, r11, r8, lsr r6 */

/* ── FUNC 0x29c608 · Debug_GetSelectedInstance(Buffer_Standard*, Buffer_Standard*) · size=64 · insn=16 */
/* @0x29c608 mov r2, r1 */
/* @0x29c60c mov r0, #0 */
/* @0x29c610 ldr r12, [r2], #44 */
/* @0x29c614 movt r0, #0xffe0 */
/* @0x29c618 push {r3, lr} */
/* @0x29c61c movw r3, #0xffff */
/* @0x29c620 str r0, [r1, #0x2c] */
/* @0x29c624 movt r3, #0x41ef */
/* @0x29c628 mov r0, #0 */
/* @0x29c62c str r3, [r1, #0x30] */
/* @0x29c630 str r0, [r1, #0x38] */
/* @0x29c634 mov r0, r1 */
/* @0x29c638 ldr r3, [r12, #0x8] */
/* @0x29c63c mov r1, #5 */
/* @0x29c640 blx r3 */
/* @0x29c644 pop {r3, pc} */

/* ── FUNC 0x29c648 · Debug_StartStopTarget(bool) · size=116 · insn=29 */
/* @0x29c648 push {r4, r5, r6, lr} */
/* @0x29c64c mov r1, r0 */
/* @0x29c650 ldr r4, [pc, #0x4c] */
/* @0x29c654 mov r5, r0 */
/* @0x29c658 ldr r3, [pc, #0x48] */
/* @0x29c65c add r4, pc, r4 */
/* @0x29c660 ldr r0, [r4, r3] */
/* @0x29c664 bl 0x2a04b8 <_ZN9CProfiler5PauseEb> */
/* @0x29c668 ldr r2, [pc, #0x3c] */
/* @0x29c66c ldr r0, [pc, #0x3c] */
/* @0x29c670 mvn r12, #0 */
/* @0x29c674 ldr r1, [pc, #0x38] */
/* @0x29c678 mov r3, #0 */
/* @0x29c67c ldr r6, [r4, r2] */
/* @0x29c680 ldr r2, [pc, #0x30] */
/* @0x29c684 strb r5, [r6] */
/* @0x29c688 ldr r0, [r4, r0] */
/* @0x29c68c str r12, [r0] */
/* @0x29c690 ldr r1, [r4, r1] */
/* @0x29c694 str r3, [r1] */
/* @0x29c698 ldr r2, [r4, r2] */
/* @0x29c69c strb r3, [r2] */
/* @0x29c6a0 pop {r4, r5, r6, pc} */
/* @0x29c6a4 ldrsheq r5, [r5], -r4 */
/* @0x29c6a8 .word 0xffffbf1c */
/* @0x29c6ac .word 0xffffdfa0 */
/* @0x29c6b0 .word 0xffffc0f8 */
/* @0x29c6b4 .word 0xffffc0f0 */
/* @0x29c6b8 .word 0xfffffdbc */

/* ── FUNC 0x29c6bc · Debug_RestartTarget() · size=4 · insn=1 */
/* @0x29c6bc b 0x1c9f54 <_Z19Command_RestartGamev> */

/* ── FUNC 0x29c6c0 · Debug_SetRoomSpeedWait(int) · size=28 · insn=7 */
/* @0x29c6c0 ldr r3, [pc, #0x10] */
/* @0x29c6c4 adds r0, r0, #0 */
/* @0x29c6c8 ldr r3, [pc, r3] */
/* @0x29c6cc movne r0, #1 */
/* @0x29c6d0 strb r0, [r3] */
/* @0x29c6d4 bx lr */
/* @0x29c6d8 ldrsbeq r4, [r5], -r8 */

/* ── FUNC 0x29c6dc · Debug_QuitDebugger() · size=68 · insn=17 */
/* @0x29c6dc ldr r2, [pc, #0x30] */
/* @0x29c6e0 mov r12, #1 */
/* @0x29c6e4 push {r3, lr} */
/* @0x29c6e8 ldr r2, [pc, r2] */
/* @0x29c6ec ldr r3, [pc, #0x24] */
/* @0x29c6f0 ldr r0, [r2] */
/* @0x29c6f4 ldr r3, [pc, r3] */
/* @0x29c6f8 ldr r1, [pc, #0x1c] */
/* @0x29c6fc strb r12, [r3] */
/* @0x29c700 add r1, pc, r1 */
/* @0x29c704 ldr r3, [r0] */
/* @0x29c708 ldr r3, [r3, #0xc] */
/* @0x29c70c blx r3 */
/* @0x29c710 pop {r3, pc} */
/* @0x29c714 andseq r1, r5, r8, asr r2 */
/* @0x29c718 andseq r5, r5, r12, lsl r3 */
/* @0x29c71c andeq sp, r11, r4, ror r3 */

/* ── FUNC 0x29c720 · Debug_GetGameStructure(bool) · size=96 · insn=24 */
/* @0x29c720 ldr r3, [pc, #0x44] */
/* @0x29c724 mov r2, #0 */
/* @0x29c728 ldr r1, [pc, #0x40] */
/* @0x29c72c add r3, pc, r3 */
/* @0x29c730 ldr r12, [pc, #0x3c] */
/* @0x29c734 push {r4, r5, r6} */
/* @0x29c738 mvn r4, #0 */
/* @0x29c73c ldr r6, [r3, r1] */
/* @0x29c740 ldr r5, [pc, #0x30] */
/* @0x29c744 ldr r1, [pc, #0x30] */
/* @0x29c748 strb r0, [r6] */
/* @0x29c74c ldr r0, [r3, r5] */
/* @0x29c750 str r4, [r0] */
/* @0x29c754 ldr r0, [r3, r12] */
/* @0x29c758 pop {r4, r5, r6} */
/* @0x29c75c str r2, [r0] */
/* @0x29c760 ldr r3, [r3, r1] */
/* @0x29c764 strb r2, [r3] */
/* @0x29c768 bx lr */
/* @0x29c76c andseq r5, r5, r4, lsr #10 */
/* @0x29c770 .word 0xffffdfa0 */
/* @0x29c774 .word 0xffffc0f0 */
/* @0x29c778 .word 0xffffc0f8 */
/* @0x29c77c .word 0xfffffdbc */

/* ── FUNC 0x29c780 · Debug_DoSingleStep(int) · size=240 · insn=60 */
/* @0x29c780 push {r4, r5, r6, lr} */
/* @0x29c784 mov r6, r0 */
/* @0x29c788 ldr r4, [pc, #0xc4] */
/* @0x29c78c ldr r3, [pc, #0xc4] */
/* @0x29c790 add r4, pc, r4 */
/* @0x29c794 ldr r5, [r4, r3] */
/* @0x29c798 ldr r3, [r5] */
/* @0x29c79c cmp r3, #0 */
/* @0x29c7a0 beq 0x29c828 <_Z18Debug_DoSingleStepi+0xa8> */
/* @0x29c7a4 ldr r1, [r3, #0x44] */
/* @0x29c7a8 ldr r0, [r3, #0x38] */
/* @0x29c7ac bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0x29c7b0 ldr r3, [r5] */
/* @0x29c7b4 mov r2, #0 */
/* @0x29c7b8 ldr r1, [r3, #0x3c] */
/* @0x29c7bc bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0x29c7c0 ldr r1, [pc, #0x94] */
/* @0x29c7c4 ldr r3, [r5] */
/* @0x29c7c8 mov r2, #0 */
/* @0x29c7cc ldr r12, [pc, #0x8c] */
/* @0x29c7d0 ldr r5, [r4, r1] */
/* @0x29c7d4 ldr r1, [r3, #0x3c] */
/* @0x29c7d8 str r0, [r5] */
/* @0x29c7dc ldr r0, [r4, r12] */
/* @0x29c7e0 str r1, [r0] */
/* @0x29c7e4 ldr r1, [r3, #0x4c] */
/* @0x29c7e8 add r2, r2, #1 */
/* @0x29c7ec ldr r3, [r3, #0x4] */
/* @0x29c7f0 add r2, r2, r1 */
/* @0x29c7f4 cmp r3, #0 */
/* @0x29c7f8 bne 0x29c7e4 <_Z18Debug_DoSingleStepi+0x64> */
/* @0x29c7fc ldr r3, [pc, #0x60] */
/* @0x29c800 ldr r3, [r4, r3] */
/* @0x29c804 str r2, [r3] */
/* @0x29c808 ldr r2, [pc, #0x58] */
/* @0x29c80c mov r1, #0 */
/* @0x29c810 ldr r3, [pc, #0x54] */
/* @0x29c814 ldr r2, [r4, r2] */
/* @0x29c818 strb r1, [r2] */
/* @0x29c81c ldr r3, [r4, r3] */
/* @0x29c820 str r6, [r3] */
/* @0x29c824 pop {r4, r5, r6, pc} */
/* @0x29c828 ldr r0, [pc, #0x2c] */
/* @0x29c82c mvn r12, #0 */
/* @0x29c830 ldr r1, [pc, #0x28] */
/* @0x29c834 ldr r2, [pc, #0x28] */
/* @0x29c838 ldr r0, [r4, r0] */
/* @0x29c83c str r12, [r0] */
/* @0x29c840 ldr r1, [r4, r1] */
/* @0x29c844 str r3, [r1] */
/* @0x29c848 ldr r2, [r4, r2] */
/* @0x29c84c str r3, [r2] */
/* @0x29c850 b 0x29c808 <_Z18Debug_DoSingleStepi+0x88> */
/* @0x29c854 andseq r5, r5, r0, asr #9 */
/* @0x29c858 .word 0xffffbf58 */
/* @0x29c85c .word 0xffffc0f8 */
/* @0x29c860 .word 0xffffc0f0 */
/* @0x29c864 .word 0xffffc0f4 */
/* @0x29c868 .word 0xffffdfa0 */
/* @0x29c86c .word 0xffffc0e8 */

/* ── FUNC 0x29c870 · Debug_SetBreakPoint(unsigned int*, bool, unsigned int, unsigned char*) · size=24 · insn=6 */
/* @0x29c870 cmp r1, #0 */
/* @0x29c874 bne 0x29c87c <_Z19Debug_SetBreakPointPjbjPh+0xc> */
/* @0x29c878 b 0xd832c <_ZN2VM15ClearBreakpointEPj> */
/* @0x29c87c mov r1, r2 */
/* @0x29c880 mov r2, r3 */
/* @0x29c884 b 0xd8270 <_ZN2VM13SetBreakpointEPjjPh> */

/* ── FUNC 0x29c888 · Debug_SetBreakpoints(unsigned char*, int) · size=580 · insn=145 */
/* @0x29c888 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29c88c mov r2, #0 */
/* @0x29c890 sub sp, sp, #28 */
/* @0x29c894 bl 0xc6a10 <_Z15AllocateIBufferPvib> */
/* @0x29c898 str r0, [sp, #0x14] */
/* @0x29c89c bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29c8a0 mov r1, #5 */
/* @0x29c8a4 ldr r3, [r0] */
/* @0x29c8a8 add r6, r0, #44 */
/* @0x29c8ac mov r5, r0 */
/* @0x29c8b0 mov r2, r6 */
/* @0x29c8b4 ldr r3, [r3, #0xc] */
/* @0x29c8b8 blx r3 */
/* @0x29c8bc mov r1, #0 */
/* @0x29c8c0 mov r0, r6 */
/* @0x29c8c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29c8c8 ldr r3, [r5] */
/* @0x29c8cc mov r2, r6 */
/* @0x29c8d0 mov r1, #5 */
/* @0x29c8d4 mov r0, r5 */
/* @0x29c8d8 ldr r3, [r3, #0xc] */
/* @0x29c8dc blx r3 */
/* @0x29c8e0 mov r1, #0 */
/* @0x29c8e4 mov r0, r6 */
/* @0x29c8e8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29c8ec ldr r3, [r5] */
/* @0x29c8f0 mov r2, r6 */
/* @0x29c8f4 mov r1, #5 */
/* @0x29c8f8 mov r0, r5 */
/* @0x29c8fc ldr r3, [r3, #0xc] */
/* @0x29c900 blx r3 */
/* @0x29c904 mov r1, #0 */
/* @0x29c908 mov r0, r6 */
/* @0x29c90c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29c910 ldr r3, [r5] */
/* @0x29c914 mov r2, r6 */
/* @0x29c918 mov r1, #5 */
/* @0x29c91c mov r0, r5 */
/* @0x29c920 ldr r3, [r3, #0xc] */
/* @0x29c924 blx r3 */
/* @0x29c928 mov r1, #0 */
/* @0x29c92c mov r0, r6 */
/* @0x29c930 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29c934 ldr r3, [r5] */
/* @0x29c938 mov r2, r6 */
/* @0x29c93c mov r1, #5 */
/* @0x29c940 mov r0, r5 */
/* @0x29c944 ldr r3, [r3, #0xc] */
/* @0x29c948 blx r3 */
/* @0x29c94c mov r0, r6 */
/* @0x29c950 mov r1, #0 */
/* @0x29c954 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29c958 ldr r3, [pc, #0x160] */
/* @0x29c95c mov r2, #1 */
/* @0x29c960 ldr r3, [pc, r3] */
/* @0x29c964 strb r2, [r3] */
/* @0x29c968 cmp r0, #0 */
/* @0x29c96c str r0, [sp, #0xc] */
/* @0x29c970 ble 0x29ca9c <_Z20Debug_SetBreakpointsPhi+0x214> */
/* @0x29c974 ldr r3, [pc, #0x148] */
/* @0x29c978 mov r9, #0 */
/* @0x29c97c str r3, [sp, #0x8] */
/* @0x29c980 ldr r3, [pc, #0x140] */
/* @0x29c984 add r3, pc, r3 */
/* @0x29c988 str r3, [sp, #0x10] */
/* @0x29c98c ldr r3, [sp, #0x8] */
/* @0x29c990 ldr r3, [pc, r3] */
/* @0x29c994 str r3, [sp, #0x8] */
/* @0x29c998 ldr r3, [r5] */
/* @0x29c99c mov r1, #12 */
/* @0x29c9a0 mov r2, r6 */
/* @0x29c9a4 mov r0, r5 */
/* @0x29c9a8 ldr r3, [r3, #0xc] */
/* @0x29c9ac blx r3 */
/* @0x29c9b0 ldr r3, [r5] */
/* @0x29c9b4 mov r2, r6 */
/* @0x29c9b8 mov r1, #5 */
/* @0x29c9bc mov r0, r5 */
/* @0x29c9c0 ldr r11, [r5, #0x2c] */
/* @0x29c9c4 ldr r3, [r3, #0xc] */
/* @0x29c9c8 blx r3 */
/* @0x29c9cc mov r0, r6 */
/* @0x29c9d0 mov r1, #0 */
/* @0x29c9d4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29c9d8 ldr r3, [sp, #0x8] */
/* @0x29c9dc ldrb r2, [r3] */
/* @0x29c9e0 adds r0, r0, #0 */
/* @0x29c9e4 movne r0, #1 */
/* @0x29c9e8 cmp r2, #0 */
/* @0x29c9ec str r0, [sp, #0x4] */
/* @0x29c9f0 beq 0x29caac <_Z20Debug_SetBreakpointsPhi+0x224> */
/* @0x29c9f4 ldr r3, [r5] */
/* @0x29c9f8 mov r2, r6 */
/* @0x29c9fc mov r1, #5 */
/* @0x29ca00 mov r0, r5 */
/* @0x29ca04 ldr r3, [r3, #0xc] */
/* @0x29ca08 blx r3 */
/* @0x29ca0c mov r1, #0 */
/* @0x29ca10 mov r0, r6 */
/* @0x29ca14 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29ca18 ldr r1, [sp, #0x10] */
/* @0x29ca1c movw r2, #0x325 */
/* @0x29ca20 mov r3, #1 */
/* @0x29ca24 mov r7, r0 */
/* @0x29ca28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29ca2c cmp r7, #0 */
/* @0x29ca30 movne r10, #0 */
/* @0x29ca34 movne r4, r10 */
/* @0x29ca38 mov r8, r0 */
/* @0x29ca3c beq 0x29ca78 <_Z20Debug_SetBreakpointsPhi+0x1f0> */
/* @0x29ca40 ldr r3, [r5] */
/* @0x29ca44 mov r1, #1 */
/* @0x29ca48 mov r2, r6 */
/* @0x29ca4c mov r0, r5 */
/* @0x29ca50 add r4, r4, r1 */
/* @0x29ca54 ldr r3, [r3, #0xc] */
/* @0x29ca58 blx r3 */
/* @0x29ca5c mov r0, r6 */
/* @0x29ca60 mov r1, #0 */
/* @0x29ca64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29ca68 cmp r4, r7 */
/* @0x29ca6c strb r0, [r8, r10] */
/* @0x29ca70 mov r10, r4 */
/* @0x29ca74 bne 0x29ca40 <_Z20Debug_SetBreakpointsPhi+0x1b8> */
/* @0x29ca78 mov r0, r11 */
/* @0x29ca7c ldr r1, [sp, #0x4] */
/* @0x29ca80 mov r2, r7 */
/* @0x29ca84 mov r3, r8 */
/* @0x29ca88 bl 0x29c870 <_Z19Debug_SetBreakPointPjbjPh> */
/* @0x29ca8c ldr r3, [sp, #0xc] */
/* @0x29ca90 add r9, r9, #1 */
/* @0x29ca94 cmp r3, r9 */
/* @0x29ca98 bne 0x29c998 <_Z20Debug_SetBreakpointsPhi+0x110> */
/* @0x29ca9c ldr r0, [sp, #0x14] */
/* @0x29caa0 add sp, sp, #28 */
/* @0x29caa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29caa8 b 0xc6a88 <_Z11FreeIBufferi> */
/* @0x29caac mov r0, r11 */
/* @0x29cab0 ldr r1, [sp, #0x4] */
/* @0x29cab4 mov r3, r2 */
/* @0x29cab8 bl 0x29c870 <_Z19Debug_SetBreakPointPjbjPh> */
/* @0x29cabc b 0x29ca8c <_Z20Debug_SetBreakpointsPhi+0x204> */
/* @0x29cac0 ldrsbeq r4, [r5], -r12 */
/* @0x29cac4 mulseq r5, r4, pc */
/* @0x29cac8 andeq sp, r11, r0, asr #32 */

/* ── FUNC 0x29cacc · Debug_DeleteALLBreakPoints() · size=4 · insn=1 */
/* @0x29cacc b 0xd8374 <_ZN2VM16ResetBreakpointsEv> */

/* ── FUNC 0x29cad0 · DebuggerSetConnected(bool) · size=164 · insn=41 */
/* @0x29cad0 push {r3, r4, r5, lr} */
/* @0x29cad4 cmp r0, #0 */
/* @0x29cad8 ldr r3, [pc, #0x78] */
/* @0x29cadc mov r5, r0 */
/* @0x29cae0 ldr r4, [pc, #0x74] */
/* @0x29cae4 add r3, pc, r3 */
/* @0x29cae8 add r4, pc, r4 */
/* @0x29caec strb r0, [r3, #0x210] */
/* @0x29caf0 ldr r3, [pc, #0x68] */
/* @0x29caf4 bne 0x29cb38 <_Z20DebuggerSetConnectedb+0x68> */
/* @0x29caf8 ldr r3, [r4, r3] */
/* @0x29cafc ldr r1, [pc, #0x60] */
/* @0x29cb00 ldr r0, [r3] */
/* @0x29cb04 add r1, pc, r1 */
/* @0x29cb08 ldr r3, [r0] */
/* @0x29cb0c ldr r3, [r3, #0xc] */
/* @0x29cb10 blx r3 */
/* @0x29cb14 ldr r2, [pc, #0x4c] */
/* @0x29cb18 ldr r3, [pc, #0x4c] */
/* @0x29cb1c mov r0, #1 */
/* @0x29cb20 mov r1, r5 */
/* @0x29cb24 ldr r2, [r4, r2] */
/* @0x29cb28 strb r0, [r2] */
/* @0x29cb2c ldr r0, [r4, r3] */
/* @0x29cb30 pop {r3, r4, r5, lr} */
/* @0x29cb34 b 0x2a04d8 <_ZN9CProfiler6EnableEb> */
/* @0x29cb38 ldr r3, [r4, r3] */
/* @0x29cb3c ldr r1, [pc, #0x2c] */
/* @0x29cb40 ldr r0, [r3] */
/* @0x29cb44 add r1, pc, r1 */
/* @0x29cb48 ldr r3, [r0] */
/* @0x29cb4c ldr r3, [r3, #0xc] */
/* @0x29cb50 blx r3 */
/* @0x29cb54 pop {r3, r4, r5, pc} */
/* @0x29cb58 subeq r11, r11, r4, lsr #2 */
/* @0x29cb5c andseq r5, r5, r8, ror #2 */
/* @0x29cb60 .word 0xffffbcf0 */
/* @0x29cb64 andeq r12, r11, r0, lsr #31 */
/* @0x29cb68 .word 0xffffef50 */
/* @0x29cb6c .word 0xffffbf1c */
/* @0x29cb70 andeq r12, r11, r12, asr #30 */

/* ── FUNC 0x29cb74 · DebuggerIsConnected() · size=20 · insn=5 */
/* @0x29cb74 ldr r3, [pc, #0x8] */
/* @0x29cb78 add r3, pc, r3 */
/* @0x29cb7c ldrb r0, [r3, #0x210] */
/* @0x29cb80 bx lr */
/* @0x29cb84 umaaleq r11, r11, r0, r0 */

/* ── FUNC 0x29cb88 · DebuggerRunBackgroundMessageLoop() · size=168 · insn=42 */
/* @0x29cb88 push {r4, r5, r6, r7, r8, lr} */
/* @0x29cb8c mov r1, #1 */
/* @0x29cb90 ldr r5, [pc, #0x84] */
/* @0x29cb94 ldr r0, [pc, #0x84] */
/* @0x29cb98 add r5, pc, r5 */
/* @0x29cb9c ldr r0, [pc, r0] */
/* @0x29cba0 bl 0x2a04b8 <_ZN9CProfiler5PauseEb> */
/* @0x29cba4 ldr r4, [r5, #0x214] */
/* @0x29cba8 cmp r4, #0 */
/* @0x29cbac popne {r4, r5, r6, r7, r8, pc} */
/* @0x29cbb0 ldr r3, [pc, #0x6c] */
/* @0x29cbb4 mov r0, #24 */
/* @0x29cbb8 ldr r3, [pc, r3] */
/* @0x29cbbc strb r4, [r3] */
/* @0x29cbc0 bl 0x27c524 <_Znwj> */
/* @0x29cbc4 mov r6, r0 */
/* @0x29cbc8 mov r0, #8 */
/* @0x29cbcc strb r4, [r6, #0x8] */
/* @0x29cbd0 str r4, [r6] */
/* @0x29cbd4 str r4, [r6, #0x4] */
/* @0x29cbd8 strb r4, [r6, #0x9] */
/* @0x29cbdc str r4, [r6, #0xc] */
/* @0x29cbe0 str r4, [r6, #0x10] */
/* @0x29cbe4 bl 0x27c524 <_Znwj> */
/* @0x29cbe8 ldr r1, [pc, #0x38] */
/* @0x29cbec add r1, pc, r1 */
/* @0x29cbf0 mov r7, r0 */
/* @0x29cbf4 bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x29cbf8 ldr r1, [pc, #0x2c] */
/* @0x29cbfc mov r0, r6 */
/* @0x29cc00 str r7, [r6, #0x14] */
/* @0x29cc04 mov r2, r4 */
/* @0x29cc08 str r6, [r5, #0x214] */
/* @0x29cc0c add r1, pc, r1 */
/* @0x29cc10 mov r3, #1 */
/* @0x29cc14 pop {r4, r5, r6, r7, r8, lr} */
/* @0x29cc18 b 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE> */
/* @0x29cc1c subeq r11, r11, r0, ror r0 */
/* @0x29cc20 ldrsbeq r0, [r5], -r0 */
/* @0x29cc24 andseq r1, r5, r4, lsl #3 */
/* @0x29cc28 andeq r5, r9, r8, asr #23 */
/* @0x29cc2c andeq r0, r0, r12, lsl #22 */
