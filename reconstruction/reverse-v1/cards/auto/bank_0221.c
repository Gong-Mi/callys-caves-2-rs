/* libyoyo.so 覆盖卡组 0221
 * 函数 0x247904..0x24bf1c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x247904 · SetArrayEntry(YYObjectBase*, unsigned int, RValue*) · size=868 · insn=217 */
/* @0x247904 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x247908 mov r4, r0 */
/* @0x24790c sub sp, sp, #8 */
/* @0x247910 mov r6, r1 */
/* @0x247914 mov r7, r2 */
/* @0x247918 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x24791c ldr r5, [r4, #0x2c] */
/* @0x247920 cmp r5, r6 */
/* @0x247924 bls 0x247a64 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x160> */
/* @0x247928 ldr r0, [r4, #0x4] */
/* @0x24792c cmp r0, #0 */
/* @0x247930 beq 0x247a54 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x150> */
/* @0x247934 ldr r3, [r4, #0x24] */
/* @0x247938 cmp r6, r3 */
/* @0x24793c blo 0x247988 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x84> */
/* @0x247940 ldr r2, [r4, #0x2c] */
/* @0x247944 cmp r6, r2 */
/* @0x247948 bhs 0x247988 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x84> */
/* @0x24794c rsb r12, r3, r6 */
/* @0x247950 add r3, r0, r3, lsl #4 */
/* @0x247954 cmp r12, #1 */
/* @0x247958 mvnhi r1, #-16777216 */
/* @0x24795c movhi lr, #5 */
/* @0x247960 bls 0x247980 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x7c> */
/* @0x247964 ldr r2, [r3, #0xc] */
/* @0x247968 sub r12, r12, #1 */
/* @0x24796c add r3, r3, #16 */
/* @0x247970 cmp r2, r1 */
/* @0x247974 streq lr, [r3, #-0x4] */
/* @0x247978 cmp r12, #1 */
/* @0x24797c bne 0x247964 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x60> */
/* @0x247980 add r3, r6, #1 */
/* @0x247984 str r3, [r4, #0x24] */
/* @0x247988 lsl r8, r6, #4 */
/* @0x24798c add r5, r0, r8 */
/* @0x247990 ldr r2, [r5, #0xc] */
/* @0x247994 bic r3, r2, #-16777216 */
/* @0x247998 cmp r3, #1 */
/* @0x24799c beq 0x247ad8 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1d4> */
/* @0x2479a0 cmp r3, #2 */
/* @0x2479a4 bne 0x2479cc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0xc8> */
/* @0x2479a8 sub r3, r2, #1 */
/* @0x2479ac bic r3, r3, #-16777216 */
/* @0x2479b0 bic r3, r3, #3 */
/* @0x2479b4 cmp r3, #0 */
/* @0x2479b8 beq 0x247bb8 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2b4> */
/* @0x2479bc mov r2, #0 */
/* @0x2479c0 mov r3, #5 */
/* @0x2479c4 str r2, [r5, #0x8] */
/* @0x2479c8 str r3, [r5, #0xc] */
/* @0x2479cc ldr r3, [r7, #0xc] */
/* @0x2479d0 mov r1, #0 */
/* @0x2479d4 ldr r2, [r7, #0x8] */
/* @0x2479d8 str r1, [r5] */
/* @0x2479dc str r3, [r5, #0xc] */
/* @0x2479e0 ldr r3, [r7, #0xc] */
/* @0x2479e4 str r2, [r5, #0x8] */
/* @0x2479e8 bic r3, r3, #-16777216 */
/* @0x2479ec cmp r3, #14 */
/* @0x2479f0 addls pc, pc, r3, lsl #2 */
/* @0x2479f4 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x2479f8 b 0x247b0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x208> */
/* @0x2479fc b 0x247b68 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x264> */
/* @0x247a00 b 0x247b3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x238> */
/* @0x247a04 b 0x247a34 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x130> */
/* @0x247a08 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247a0c b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247a10 b 0x247b18 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x214> */
/* @0x247a14 b 0x247a34 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x130> */
/* @0x247a18 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247a1c b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247a20 b 0x247b0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x208> */
/* @0x247a24 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247a28 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247a2c b 0x247b0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x208> */
/* @0x247a30 b 0x247a34 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x130> */
/* @0x247a34 ldr r3, [r7] */
/* @0x247a38 str r3, [r5] */
/* @0x247a3c ldr r3, [r4, #0x4] */
/* @0x247a40 cmp r3, #0 */
/* @0x247a44 beq 0x247bc4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2c0> */
/* @0x247a48 add r0, r3, r8 */
/* @0x247a4c mov r2, #6 */
/* @0x247a50 str r2, [r0, #0x8] */
/* @0x247a54 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x247a58 mov r0, #1 */
/* @0x247a5c add sp, sp, #8 */
/* @0x247a60 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x247a64 add r5, r5, r5, lsl #1 */
/* @0x247a68 ldr r2, [pc, #0x1f4] */
/* @0x247a6c ldr r0, [r4, #0x4] */
/* @0x247a70 mov r3, #0 */
/* @0x247a74 lsr r5, r5, #1 */
/* @0x247a78 str r3, [sp] */
/* @0x247a7c cmp r6, r5 */
/* @0x247a80 add r2, pc, r2 */
/* @0x247a84 addhs r5, r6, #1 */
/* @0x247a88 mov r3, #74 */
/* @0x247a8c lsl r1, r5, #4 */
/* @0x247a90 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x247a94 cmp r0, #0 */
/* @0x247a98 str r0, [r4, #0x4] */
/* @0x247a9c beq 0x247a54 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x150> */
/* @0x247aa0 ldr r12, [r4, #0x2c] */
/* @0x247aa4 subs r3, r5, r12 */
/* @0x247aa8 add r12, r0, r12, lsl #4 */
/* @0x247aac mvnne r2, #-16777216 */
/* @0x247ab0 beq 0x247ac4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1c0> */
/* @0x247ab4 subs r3, r3, #1 */
/* @0x247ab8 str r2, [r12, #0xc] */
/* @0x247abc add r12, r12, #16 */
/* @0x247ac0 bne 0x247ab4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1b0> */
/* @0x247ac4 ldr r3, [r4, #0x24] */
/* @0x247ac8 str r5, [r4, #0x2c] */
/* @0x247acc cmp r6, r3 */
/* @0x247ad0 blo 0x247988 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x84> */
/* @0x247ad4 b 0x247940 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x3c> */
/* @0x247ad8 ldr r9, [r0, r6, lsl #4] */
/* @0x247adc cmp r9, #0 */
/* @0x247ae0 beq 0x247b00 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1fc> */
/* @0x247ae4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x247ae8 ldr r10, [r9, #0x4] */
/* @0x247aec sub r10, r10, #1 */
/* @0x247af0 str r10, [r9, #0x4] */
/* @0x247af4 cmp r10, #0 */
/* @0x247af8 beq 0x247b80 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x27c> */
/* @0x247afc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247b00 mov r3, #0 */
/* @0x247b04 str r3, [r5] */
/* @0x247b08 b 0x2479cc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0xc8> */
/* @0x247b0c ldm r7, {r2, r3} */
/* @0x247b10 stm r5, {r2, r3} */
/* @0x247b14 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247b18 ldr r3, [r7] */
/* @0x247b1c str r3, [r5] */
/* @0x247b20 ldr r3, [r7] */
/* @0x247b24 cmp r3, #0 */
/* @0x247b28 beq 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247b2c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x247b30 ldr r1, [r7] */
/* @0x247b34 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x247b38 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247b3c ldr r3, [r7] */
/* @0x247b40 cmp r3, #0 */
/* @0x247b44 str r3, [r5] */
/* @0x247b48 beq 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247b4c ldr r1, [r3, #0x8] */
/* @0x247b50 ldr r2, [r3] */
/* @0x247b54 cmp r1, #0 */
/* @0x247b58 streq r5, [r3, #0x8] */
/* @0x247b5c add r2, r2, #1 */
/* @0x247b60 str r2, [r3] */
/* @0x247b64 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138> */
/* @0x247b68 ldr r3, [r7] */
/* @0x247b6c cmp r3, #0 */
/* @0x247b70 ldrne r2, [r3, #0x4] */
/* @0x247b74 addne r2, r2, #1 */
/* @0x247b78 strne r2, [r3, #0x4] */
/* @0x247b7c b 0x247a38 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x134> */
/* @0x247b80 ldr r0, [r9] */
/* @0x247b84 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x247b88 str r10, [r9] */
/* @0x247b8c str r10, [r9, #0x8] */
/* @0x247b90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x247b94 ldr r10, [r9, #0x4] */
/* @0x247b98 sub r10, r10, #1 */
/* @0x247b9c str r10, [r9, #0x4] */
/* @0x247ba0 cmp r10, #0 */
/* @0x247ba4 beq 0x247bd4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2d0> */
/* @0x247ba8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247bac mov r0, r9 */
/* @0x247bb0 bl 0x27d1d0 <_ZdlPv> */
/* @0x247bb4 b 0x247afc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1f8> */
/* @0x247bb8 mov r0, r5 */
/* @0x247bbc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x247bc0 b 0x2479bc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0xb8> */
/* @0x247bc4 mov r0, r4 */
/* @0x247bc8 mov r1, r6 */
/* @0x247bcc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x247bd0 b 0x247a4c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x148> */
/* @0x247bd4 ldr r0, [r9] */
/* @0x247bd8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x247bdc str r10, [r9] */
/* @0x247be0 str r10, [r9, #0x8] */
/* @0x247be4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x247be8 ldr r10, [r9, #0x4] */
/* @0x247bec sub r10, r10, #1 */
/* @0x247bf0 str r10, [r9, #0x4] */
/* @0x247bf4 cmp r10, #0 */
/* @0x247bf8 beq 0x247c0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x308> */
/* @0x247bfc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247c00 mov r0, r9 */
/* @0x247c04 bl 0x27d1d0 <_ZdlPv> */
/* @0x247c08 b 0x247ba8 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2a4> */
/* @0x247c0c ldr r0, [r9] */
/* @0x247c10 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x247c14 str r10, [r9] */
/* @0x247c18 str r10, [r9, #0x8] */
/* @0x247c1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x247c20 ldr r10, [r9, #0x4] */
/* @0x247c24 sub r10, r10, #1 */
/* @0x247c28 str r10, [r9, #0x4] */
/* @0x247c2c cmp r10, #0 */
/* @0x247c30 bne 0x247c54 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x350> */
/* @0x247c34 ldr r0, [r9] */
/* @0x247c38 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x247c3c mov r0, r9 */
/* @0x247c40 str r10, [r9] */
/* @0x247c44 str r10, [r9, #0x8] */
/* @0x247c48 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x247c4c mov r0, r9 */
/* @0x247c50 bl 0x27d1d0 <_ZdlPv> */
/* @0x247c54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x247c58 mov r0, r9 */
/* @0x247c5c bl 0x27d1d0 <_ZdlPv> */
/* @0x247c60 b 0x247bfc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2f8> */
/* @0x247c64 strheq r9, [lr], -r0 */

/* ── FUNC 0x247c68 · JSArrayPut(RValue*, RValue*, RValue*) · size=220 · insn=55 */
/* @0x247c68 cmp r0, #0 */
/* @0x247c6c push {r4, r5, r6, r7, r8, lr} */
/* @0x247c70 mov r6, r1 */
/* @0x247c74 mov r8, r2 */
/* @0x247c78 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x247c7c ldr r3, [r0, #0xc] */
/* @0x247c80 cmp r3, #6 */
/* @0x247c84 beq 0x247c90 <_Z10JSArrayPutP6RValueS0_S0_+0x28> */
/* @0x247c88 mov r0, #0 */
/* @0x247c8c pop {r4, r5, r6, r7, r8, pc} */
/* @0x247c90 ldr r7, [r0] */
/* @0x247c94 ldr r1, [pc, #0xa4] */
/* @0x247c98 ldr r0, [r7, #0x40] */
/* @0x247c9c add r1, pc, r1 */
/* @0x247ca0 bl 0xb6574 <strcmp@plt> */
/* @0x247ca4 cmp r0, #0 */
/* @0x247ca8 bne 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8> */
/* @0x247cac ldr r3, [r7, #0x4] */
/* @0x247cb0 cmp r3, #0 */
/* @0x247cb4 beq 0x247d30 <_Z10JSArrayPutP6RValueS0_S0_+0xc8> */
/* @0x247cb8 add r0, r3, #16 */
/* @0x247cbc ldr r2, [r6, #0xc] */
/* @0x247cc0 ldr r7, [r0] */
/* @0x247cc4 cmp r2, #0 */
/* @0x247cc8 bne 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8> */
/* @0x247ccc ldm r6, {r4, r5} */
/* @0x247cd0 vmov d5, r4, r5 */
/* @0x247cd4 vcvt.s32.f64 s13, d5 */
/* @0x247cd8 vcvt.f64.s32 d7, s13 */
/* @0x247cdc vcmp.f64 d5, d7 */
/* @0x247ce0 vmrs APSR_nzcv, fpscr */
/* @0x247ce4 bne 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8> */
/* @0x247ce8 vmov r3, s13 */
/* @0x247cec cmp r3, #0 */
/* @0x247cf0 blt 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8> */
/* @0x247cf4 mov r0, r7 */
/* @0x247cf8 vmov r1, s13 */
/* @0x247cfc mov r2, r8 */
/* @0x247d00 bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue> */
/* @0x247d04 cmp r0, #0 */
/* @0x247d08 beq 0x247d10 <_Z10JSArrayPutP6RValueS0_S0_+0xa8> */
/* @0x247d0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x247d10 ldr r1, [r6] */
/* @0x247d14 mov r0, r7 */
/* @0x247d18 mov r2, r8 */
/* @0x247d1c mov r3, #0 */
/* @0x247d20 ldr r1, [r1] */
/* @0x247d24 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi> */
/* @0x247d28 mov r0, #0 */
/* @0x247d2c pop {r4, r5, r6, r7, r8, pc} */
/* @0x247d30 mov r0, r7 */
/* @0x247d34 mov r1, #1 */
/* @0x247d38 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x247d3c b 0x247cbc <_Z10JSArrayPutP6RValueS0_S0_+0x54> */
/* @0x247d40 andeq r12, lr, r12, ror r12 */

/* ── FUNC 0x247d44 · JS_DefineOwnProperty_Internal(YYObjectBase*, char const*, RValue*, bool) · size=1616 · insn=404 */
/* @0x247d44 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x247d48 sub sp, sp, #16 */
/* @0x247d4c mov r9, r3 */
/* @0x247d50 mov r8, r1 */
/* @0x247d54 mov r4, r0 */
/* @0x247d58 mov r6, r2 */
/* @0x247d5c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x247d60 mov r12, #0 */
/* @0x247d64 cmp r9, r12 */
/* @0x247d68 mov r0, r4 */
/* @0x247d6c mov r2, r8 */
/* @0x247d70 mov r1, sp */
/* @0x247d74 mvn r5, #-16777216 */
/* @0x247d78 moveq r9, r12 */
/* @0x247d7c str r12, [sp, #0x8] */
/* @0x247d80 movne r9, #2 */
/* @0x247d84 str r12, [sp, #0x4] */
/* @0x247d88 str r12, [sp] */
/* @0x247d8c str r5, [sp, #0xc] */
/* @0x247d90 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x247d94 ldr r12, [sp, #0xc] */
/* @0x247d98 ldr r3, [r4, #0x28] */
/* @0x247d9c and r12, r12, r5 */
/* @0x247da0 cmp r12, #5 */
/* @0x247da4 cmpne r12, r5 */
/* @0x247da8 bne 0x247dc8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x84> */
/* @0x247dac tst r3, #1 */
/* @0x247db0 bne 0x247f50 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x20c> */
/* @0x247db4 mov r4, r9 */
/* @0x247db8 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x247dbc mov r0, r4 */
/* @0x247dc0 add sp, sp, #16 */
/* @0x247dc4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x247dc8 ldr r3, [r6, #0xc] */
/* @0x247dcc bic r3, r3, #-16777216 */
/* @0x247dd0 cmp r3, r5 */
/* @0x247dd4 beq 0x247f3c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1f8> */
/* @0x247dd8 mov r0, sp */
/* @0x247ddc mov r1, r6 */
/* @0x247de0 bl 0x24089c <_Z12JS_SameValueP6RValueS0_> */
/* @0x247de4 ldr r2, [sp, #0x8] */
/* @0x247de8 ldr r5, [r6, #0x8] */
/* @0x247dec cmp r0, #0 */
/* @0x247df0 beq 0x247dfc <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0xb8> */
/* @0x247df4 cmp r2, r5 */
/* @0x247df8 beq 0x247f3c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1f8> */
/* @0x247dfc tst r2, #2 */
/* @0x247e00 bne 0x247e14 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0xd0> */
/* @0x247e04 tst r5, #2 */
/* @0x247e08 bne 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70> */
/* @0x247e0c tst r5, #1 */
/* @0x247e10 bne 0x248058 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x314> */
/* @0x247e14 mov r0, r6 */
/* @0x247e18 bl 0x240858 <_Z22JS_IsGenericDescriptorP6RValue> */
/* @0x247e1c cmp r0, #0 */
/* @0x247e20 bne 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114> */
/* @0x247e24 mov r0, sp */
/* @0x247e28 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x247e2c mov r10, r0 */
/* @0x247e30 mov r0, r6 */
/* @0x247e34 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x247e38 cmp r10, r0 */
/* @0x247e3c beq 0x248254 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x510> */
/* @0x247e40 ldr r3, [sp, #0x8] */
/* @0x247e44 tst r3, #2 */
/* @0x247e48 beq 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70> */
/* @0x247e4c mvn r3, r3, lsl #30 */
/* @0x247e50 mvn r3, r3, lsr #30 */
/* @0x247e54 and r5, r5, r3 */
/* @0x247e58 mov r0, r4 */
/* @0x247e5c mov r1, r8 */
/* @0x247e60 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x247e64 cmp r0, #0 */
/* @0x247e68 blt 0x247f28 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1e4> */
/* @0x247e6c ldr r3, [r4, #0x4] */
/* @0x247e70 cmp r3, #0 */
/* @0x247e74 beq 0x248274 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x530> */
/* @0x247e78 add r7, r3, r0, lsl #4 */
/* @0x247e7c mov r0, r4 */
/* @0x247e80 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x247e84 ldr r2, [r7, #0xc] */
/* @0x247e88 bic r3, r2, #-16777216 */
/* @0x247e8c cmp r3, #1 */
/* @0x247e90 beq 0x248184 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x440> */
/* @0x247e94 cmp r3, #2 */
/* @0x247e98 bne 0x247ec0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x17c> */
/* @0x247e9c sub r3, r2, #1 */
/* @0x247ea0 bic r3, r3, #-16777216 */
/* @0x247ea4 bic r3, r3, #3 */
/* @0x247ea8 cmp r3, #0 */
/* @0x247eac beq 0x248234 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4f0> */
/* @0x247eb0 mov r2, #0 */
/* @0x247eb4 mov r3, #5 */
/* @0x247eb8 str r2, [r7, #0x8] */
/* @0x247ebc str r3, [r7, #0xc] */
/* @0x247ec0 ldr r3, [r6, #0xc] */
/* @0x247ec4 mov r1, #0 */
/* @0x247ec8 ldr r2, [r6, #0x8] */
/* @0x247ecc str r1, [r7] */
/* @0x247ed0 str r3, [r7, #0xc] */
/* @0x247ed4 ldr r3, [r6, #0xc] */
/* @0x247ed8 str r2, [r7, #0x8] */
/* @0x247edc bic r3, r3, #-16777216 */
/* @0x247ee0 cmp r3, #14 */
/* @0x247ee4 addls pc, pc, r3, lsl #2 */
/* @0x247ee8 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247eec b 0x248074 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x330> */
/* @0x247ef0 b 0x24810c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x3c8> */
/* @0x247ef4 b 0x248124 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x3e0> */
/* @0x247ef8 b 0x248040 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2fc> */
/* @0x247efc b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247f00 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247f04 b 0x2480e8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x3a4> */
/* @0x247f08 b 0x248040 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2fc> */
/* @0x247f0c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247f10 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247f14 b 0x248074 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x330> */
/* @0x247f18 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247f1c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x247f20 b 0x248074 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x330> */
/* @0x247f24 b 0x248040 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2fc> */
/* @0x247f28 mov r0, r4 */
/* @0x247f2c mov r1, r8 */
/* @0x247f30 mov r2, r6 */
/* @0x247f34 mov r3, r5 */
/* @0x247f38 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x247f3c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x247f40 mov r4, #1 */
/* @0x247f44 mov r0, r4 */
/* @0x247f48 add sp, sp, #16 */
/* @0x247f4c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x247f50 mov r1, r8 */
/* @0x247f54 mov r0, r4 */
/* @0x247f58 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc> */
/* @0x247f5c subs r5, r0, #0 */
/* @0x247f60 blt 0x247f3c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1f8> */
/* @0x247f64 mov r0, r4 */
/* @0x247f68 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x247f6c ldr r3, [r4, #0x4] */
/* @0x247f70 cmp r3, #0 */
/* @0x247f74 beq 0x248240 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4fc> */
/* @0x247f78 add r4, r3, r5, lsl #4 */
/* @0x247f7c ldr r2, [r4, #0xc] */
/* @0x247f80 bic r3, r2, #-16777216 */
/* @0x247f84 cmp r3, #1 */
/* @0x247f88 beq 0x248150 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x40c> */
/* @0x247f8c cmp r3, #2 */
/* @0x247f90 bne 0x247fb8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x274> */
/* @0x247f94 sub r3, r2, #1 */
/* @0x247f98 bic r3, r3, #-16777216 */
/* @0x247f9c bic r3, r3, #3 */
/* @0x247fa0 cmp r3, #0 */
/* @0x247fa4 beq 0x2481f0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4ac> */
/* @0x247fa8 mov r2, #0 */
/* @0x247fac mov r3, #5 */
/* @0x247fb0 str r2, [r4, #0x8] */
/* @0x247fb4 str r3, [r4, #0xc] */
/* @0x247fb8 ldr r3, [r6, #0xc] */
/* @0x247fbc mov r1, #0 */
/* @0x247fc0 ldr r2, [r6, #0x8] */
/* @0x247fc4 str r1, [r4] */
/* @0x247fc8 str r3, [r4, #0xc] */
/* @0x247fcc ldr r3, [r6, #0xc] */
/* @0x247fd0 str r2, [r4, #0x8] */
/* @0x247fd4 bic r3, r3, #-16777216 */
/* @0x247fd8 cmp r3, #14 */
/* @0x247fdc addls pc, pc, r3, lsl #2 */
/* @0x247fe0 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x247fe4 b 0x248068 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x324> */
/* @0x247fe8 b 0x2480ac <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x368> */
/* @0x247fec b 0x248080 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x33c> */
/* @0x247ff0 b 0x248020 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2dc> */
/* @0x247ff4 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x247ff8 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x247ffc b 0x2480c4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x380> */
/* @0x248000 b 0x248020 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2dc> */
/* @0x248004 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x248008 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x24800c b 0x248068 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x324> */
/* @0x248010 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x248014 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x248018 b 0x248068 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x324> */
/* @0x24801c b 0x248020 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2dc> */
/* @0x248020 ldr r3, [r6] */
/* @0x248024 str r3, [r4] */
/* @0x248028 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x24802c mov r4, #1 */
/* @0x248030 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x248034 mov r0, r4 */
/* @0x248038 add sp, sp, #16 */
/* @0x24803c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x248040 ldr r3, [r6] */
/* @0x248044 str r3, [r7] */
/* @0x248048 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x24804c mov r4, #1 */
/* @0x248050 str r5, [r7, #0x8] */
/* @0x248054 b 0x247db8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x74> */
/* @0x248058 eor r2, r2, r5 */
/* @0x24805c tst r2, #1 */
/* @0x248060 beq 0x247e14 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0xd0> */
/* @0x248064 b 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70> */
/* @0x248068 ldm r6, {r2, r3} */
/* @0x24806c stm r4, {r2, r3} */
/* @0x248070 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x248074 ldm r6, {r2, r3} */
/* @0x248078 stm r7, {r2, r3} */
/* @0x24807c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x248080 ldr r3, [r6] */
/* @0x248084 cmp r3, #0 */
/* @0x248088 str r3, [r4] */
/* @0x24808c beq 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x248090 ldr r1, [r3, #0x8] */
/* @0x248094 ldr r2, [r3] */
/* @0x248098 cmp r1, #0 */
/* @0x24809c streq r4, [r3, #0x8] */
/* @0x2480a0 add r2, r2, #1 */
/* @0x2480a4 str r2, [r3] */
/* @0x2480a8 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x2480ac ldr r3, [r6] */
/* @0x2480b0 cmp r3, #0 */
/* @0x2480b4 ldrne r2, [r3, #0x4] */
/* @0x2480b8 addne r2, r2, #1 */
/* @0x2480bc strne r2, [r3, #0x4] */
/* @0x2480c0 b 0x248024 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e0> */
/* @0x2480c4 ldr r3, [r6] */
/* @0x2480c8 str r3, [r4] */
/* @0x2480cc ldr r3, [r6] */
/* @0x2480d0 cmp r3, #0 */
/* @0x2480d4 beq 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x2480d8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x2480dc ldr r1, [r6] */
/* @0x2480e0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2480e4 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4> */
/* @0x2480e8 ldr r3, [r6] */
/* @0x2480ec str r3, [r7] */
/* @0x2480f0 ldr r3, [r6] */
/* @0x2480f4 cmp r3, #0 */
/* @0x2480f8 beq 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x2480fc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x248100 ldr r1, [r6] */
/* @0x248104 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x248108 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x24810c ldr r3, [r6] */
/* @0x248110 cmp r3, #0 */
/* @0x248114 ldrne r2, [r3, #0x4] */
/* @0x248118 addne r2, r2, #1 */
/* @0x24811c strne r2, [r3, #0x4] */
/* @0x248120 b 0x248044 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x300> */
/* @0x248124 ldr r3, [r6] */
/* @0x248128 cmp r3, #0 */
/* @0x24812c str r3, [r7] */
/* @0x248130 beq 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x248134 ldr r1, [r3, #0x8] */
/* @0x248138 ldr r2, [r3] */
/* @0x24813c cmp r1, #0 */
/* @0x248140 streq r7, [r3, #0x8] */
/* @0x248144 add r2, r2, #1 */
/* @0x248148 str r2, [r3] */
/* @0x24814c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304> */
/* @0x248150 ldr r5, [r4] */
/* @0x248154 cmp r5, #0 */
/* @0x248158 beq 0x248178 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x434> */
/* @0x24815c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248160 ldr r7, [r5, #0x4] */
/* @0x248164 sub r7, r7, #1 */
/* @0x248168 str r7, [r5, #0x4] */
/* @0x24816c cmp r7, #0 */
/* @0x248170 beq 0x2481b8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x474> */
/* @0x248174 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248178 mov r3, #0 */
/* @0x24817c str r3, [r4] */
/* @0x248180 b 0x247fb8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x274> */
/* @0x248184 ldr r4, [r7] */
/* @0x248188 cmp r4, #0 */
/* @0x24818c beq 0x2481ac <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x468> */
/* @0x248190 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248194 ldr r8, [r4, #0x4] */
/* @0x248198 sub r8, r8, #1 */
/* @0x24819c str r8, [r4, #0x4] */
/* @0x2481a0 cmp r8, #0 */
/* @0x2481a4 beq 0x2481fc <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4b8> */
/* @0x2481a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2481ac mov r3, #0 */
/* @0x2481b0 str r3, [r7] */
/* @0x2481b4 b 0x247ec0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x17c> */
/* @0x2481b8 ldr r0, [r5] */
/* @0x2481bc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2481c0 str r7, [r5] */
/* @0x2481c4 str r7, [r5, #0x8] */
/* @0x2481c8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2481cc ldr r7, [r5, #0x4] */
/* @0x2481d0 sub r7, r7, #1 */
/* @0x2481d4 str r7, [r5, #0x4] */
/* @0x2481d8 cmp r7, #0 */
/* @0x2481dc beq 0x248288 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x544> */
/* @0x2481e0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2481e4 mov r0, r5 */
/* @0x2481e8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2481ec b 0x248174 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x430> */
/* @0x2481f0 mov r0, r4 */
/* @0x2481f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2481f8 b 0x247fa8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x264> */
/* @0x2481fc ldr r0, [r4] */
/* @0x248200 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248204 str r8, [r4] */
/* @0x248208 str r8, [r4, #0x8] */
/* @0x24820c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248210 ldr r8, [r4, #0x4] */
/* @0x248214 sub r8, r8, #1 */
/* @0x248218 str r8, [r4, #0x4] */
/* @0x24821c cmp r8, #0 */
/* @0x248220 beq 0x2482ac <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x568> */
/* @0x248224 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248228 mov r0, r4 */
/* @0x24822c bl 0x27d1d0 <_ZdlPv> */
/* @0x248230 b 0x2481a8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x464> */
/* @0x248234 mov r0, r7 */
/* @0x248238 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24823c b 0x247eb0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x16c> */
/* @0x248240 mov r0, r4 */
/* @0x248244 mov r1, r5 */
/* @0x248248 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24824c mov r4, r0 */
/* @0x248250 b 0x247f7c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x238> */
/* @0x248254 mov r0, sp */
/* @0x248258 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x24825c cmp r0, #0 */
/* @0x248260 bne 0x2482e4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x5a0> */
/* @0x248264 ldr r0, [pc, #0x124] */
/* @0x248268 add r0, pc, r0 */
/* @0x24826c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x248270 b 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114> */
/* @0x248274 mov r1, r0 */
/* @0x248278 mov r0, r4 */
/* @0x24827c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x248280 mov r7, r0 */
/* @0x248284 b 0x247e7c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x138> */
/* @0x248288 ldr r0, [r5] */
/* @0x24828c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248290 mov r0, r5 */
/* @0x248294 str r7, [r5] */
/* @0x248298 str r7, [r5, #0x8] */
/* @0x24829c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2482a0 mov r0, r5 */
/* @0x2482a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2482a8 b 0x2481e0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x49c> */
/* @0x2482ac ldr r0, [r4] */
/* @0x2482b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2482b4 str r8, [r4] */
/* @0x2482b8 str r8, [r4, #0x8] */
/* @0x2482bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2482c0 ldr r8, [r4, #0x4] */
/* @0x2482c4 sub r8, r8, #1 */
/* @0x2482c8 str r8, [r4, #0x4] */
/* @0x2482cc cmp r8, #0 */
/* @0x2482d0 beq 0x248338 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x5f4> */
/* @0x2482d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2482d8 mov r0, r4 */
/* @0x2482dc bl 0x27d1d0 <_ZdlPv> */
/* @0x2482e0 b 0x248224 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4e0> */
/* @0x2482e4 mov r0, r6 */
/* @0x2482e8 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x2482ec cmp r0, #0 */
/* @0x2482f0 beq 0x248264 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x520> */
/* @0x2482f4 ldr r3, [sp, #0x8] */
/* @0x2482f8 tst r3, #6 */
/* @0x2482fc bne 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114> */
/* @0x248300 ldr r3, [r6, #0x8] */
/* @0x248304 tst r3, #4 */
/* @0x248308 bne 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70> */
/* @0x24830c ldr r2, [r6, #0xc] */
/* @0x248310 mvn r3, #-16777216 */
/* @0x248314 and r2, r2, r3 */
/* @0x248318 cmp r2, r3 */
/* @0x24831c beq 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114> */
/* @0x248320 mov r0, sp */
/* @0x248324 mov r1, r6 */
/* @0x248328 bl 0x24089c <_Z12JS_SameValueP6RValueS0_> */
/* @0x24832c cmp r0, #0 */
/* @0x248330 bne 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114> */
/* @0x248334 b 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70> */
/* @0x248338 ldr r0, [r4] */
/* @0x24833c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248340 str r8, [r4] */
/* @0x248344 str r8, [r4, #0x8] */
/* @0x248348 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24834c ldr r8, [r4, #0x4] */
/* @0x248350 sub r8, r8, #1 */
/* @0x248354 str r8, [r4, #0x4] */
/* @0x248358 cmp r8, #0 */
/* @0x24835c bne 0x248380 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x63c> */
/* @0x248360 ldr r0, [r4] */
/* @0x248364 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248368 mov r0, r4 */
/* @0x24836c str r8, [r4] */
/* @0x248370 str r8, [r4, #0x8] */
/* @0x248374 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x248378 mov r0, r4 */
/* @0x24837c bl 0x27d1d0 <_ZdlPv> */
/* @0x248380 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248384 mov r0, r4 */
/* @0x248388 bl 0x27d1d0 <_ZdlPv> */
/* @0x24838c b 0x2482d4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x590> */
/* @0x248390 ldrheq sp, [r0], -r8 */

/* ── FUNC 0x248394 · JS_DefineOwnProperty(YYObjectBase*, char const*, RValue*, bool) · size=72 · insn=18 */
/* @0x248394 push {r4, lr} */
/* @0x248398 ldr r4, [r0, #0x54] */
/* @0x24839c cmp r4, #0 */
/* @0x2483a0 bne 0x2483cc <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x38> */
/* @0x2483a4 ldr r12, [r0, #0x18] */
/* @0x2483a8 cmp r12, #0 */
/* @0x2483ac bne 0x2483c0 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x2c> */
/* @0x2483b0 b 0x2483d4 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x40> */
/* @0x2483b4 ldr r12, [r12, #0x18] */
/* @0x2483b8 cmp r12, #0 */
/* @0x2483bc beq 0x2483d4 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x40> */
/* @0x2483c0 ldr r4, [r12, #0x54] */
/* @0x2483c4 cmp r4, #0 */
/* @0x2483c8 beq 0x2483b4 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x20> */
/* @0x2483cc blx r4 */
/* @0x2483d0 pop {r4, pc} */
/* @0x2483d4 pop {r4, lr} */
/* @0x2483d8 b 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb> */

/* ── FUNC 0x2483dc · anon_2483dc · size=0 · insn=1 */
/* @0x2483dc andeq r0, r0, r0 */

/* ── FUNC 0x2483e0 · F_JS_FromPropertyDescriptor(RValue*, RValue*) · size=560 · insn=138 */
/* @0x2483e0 ldr r3, [r1, #0xc] */
/* @0x2483e4 mvn r12, #-16777216 */
/* @0x2483e8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2483ec vpush {d8, d9} */
/* @0x2483f0 cmp r3, #5 */
/* @0x2483f4 cmpne r3, r12 */
/* @0x2483f8 sub sp, sp, #24 */
/* @0x2483fc mov r6, r1 */
/* @0x248400 moveq r3, #5 */
/* @0x248404 mov r8, r0 */
/* @0x248408 movne r7, #0 */
/* @0x24840c moveq r7, #1 */
/* @0x248410 streq r3, [r0, #0xc] */
/* @0x248414 bne 0x248424 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x44> */
/* @0x248418 add sp, sp, #24 */
/* @0x24841c vpop {d8, d9} */
/* @0x248420 pop {r4, r5, r6, r7, r8, pc} */
/* @0x248424 mov r1, r7 */
/* @0x248428 mov r2, r7 */
/* @0x24842c mov r3, r7 */
/* @0x248430 str r7, [sp] */
/* @0x248434 mov r5, #0 */
/* @0x248438 str r12, [sp, #0x14] */
/* @0x24843c str r7, [sp, #0x10] */
/* @0x248440 mov r4, #0 */
/* @0x248444 strd r4, r5, [sp, #8] */
/* @0x248448 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24844c mov r0, r6 */
/* @0x248450 ldr r5, [r8] */
/* @0x248454 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x248458 cmp r0, #0 */
/* @0x24845c bne 0x248558 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x178> */
/* @0x248460 ldr r0, [r6] */
/* @0x248464 ldr r1, [r0, #0x4] */
/* @0x248468 cmp r1, #0 */
/* @0x24846c beq 0x2485e0 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x200> */
/* @0x248470 ldr r12, [r1] */
/* @0x248474 add r4, sp, #8 */
/* @0x248478 ldr r1, [pc, #0x178] */
/* @0x24847c mov r3, #0 */
/* @0x248480 ldr lr, [sp, #0x10] */
/* @0x248484 mov r0, r5 */
/* @0x248488 mov r2, r4 */
/* @0x24848c add r1, pc, r1 */
/* @0x248490 str r12, [sp, #0x8] */
/* @0x248494 orr lr, lr, #7 */
/* @0x248498 mov r12, #6 */
/* @0x24849c str lr, [sp, #0x10] */
/* @0x2484a0 str r12, [sp, #0x14] */
/* @0x2484a4 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x2484a8 ldr r0, [r6] */
/* @0x2484ac ldr r3, [r0, #0x4] */
/* @0x2484b0 cmp r3, #0 */
/* @0x2484b4 beq 0x2485d4 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x1f4> */
/* @0x2484b8 add r0, r3, #16 */
/* @0x2484bc ldr r12, [r0] */
/* @0x2484c0 mov r2, r4 */
/* @0x2484c4 ldr r1, [pc, #0x130] */
/* @0x2484c8 mov r0, r5 */
/* @0x2484cc mov r3, #0 */
/* @0x2484d0 add r1, pc, r1 */
/* @0x2484d4 str r12, [sp, #0x8] */
/* @0x2484d8 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x2484dc vmov.f64 d8, #1.000000e+00 */
/* @0x2484e0 ldr r3, [r6, #0x8] */
/* @0x2484e4 ldr r1, [pc, #0x114] */
/* @0x2484e8 mov r2, r4 */
/* @0x2484ec ldr lr, [sp, #0x10] */
/* @0x2484f0 tst r3, #1 */
/* @0x2484f4 mov r0, r5 */
/* @0x2484f8 add r1, pc, r1 */
/* @0x2484fc mov r3, #0 */
/* @0x248500 orr lr, lr, #7 */
/* @0x248504 mov r12, #13 */
/* @0x248508 vldr d9, [pc, #224] */
/* @0x24850c str lr, [sp, #0x10] */
/* @0x248510 str r12, [sp, #0x14] */
/* @0x248514 vmovne.f64 d7, d8 */
/* @0x248518 vmoveq.f64 d7, d9 */
/* @0x24851c vstr d7, [sp, #8] */
/* @0x248520 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x248524 ldr r3, [r6, #0x8] */
/* @0x248528 ldr r1, [pc, #0xd4] */
/* @0x24852c mov r0, r5 */
/* @0x248530 tst r3, #2 */
/* @0x248534 mov r2, r4 */
/* @0x248538 add r1, pc, r1 */
/* @0x24853c mov r3, #0 */
/* @0x248540 vmoveq.f64 d8, d9 */
/* @0x248544 vstr d8, [sp, #8] */
/* @0x248548 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x24854c add sp, sp, #24 */
/* @0x248550 vpop {d8, d9} */
/* @0x248554 pop {r4, r5, r6, r7, r8, pc} */
/* @0x248558 add r4, sp, #8 */
/* @0x24855c ldr r0, [r6] */
/* @0x248560 ldr r1, [r6, #0x4] */
/* @0x248564 ldr r2, [r6, #0x8] */
/* @0x248568 mov r12, r4 */
/* @0x24856c ldr r3, [r6, #0xc] */
/* @0x248570 stm r12!, {r0, r1, r2, r3} */
/* @0x248574 mov r2, r4 */
/* @0x248578 ldr r1, [pc, #0x88] */
/* @0x24857c mov r3, r7 */
/* @0x248580 ldr r12, [sp, #0x10] */
/* @0x248584 mov r0, r5 */
/* @0x248588 add r1, pc, r1 */
/* @0x24858c orr r12, r12, #7 */
/* @0x248590 str r12, [sp, #0x10] */
/* @0x248594 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x248598 vmov.f64 d7, #1.000000e+00 */
/* @0x24859c ldr r1, [r6, #0x8] */
/* @0x2485a0 mov r3, r7 */
/* @0x2485a4 mov r2, r4 */
/* @0x2485a8 mov r0, r5 */
/* @0x2485ac tst r1, #4 */
/* @0x2485b0 ldr r1, [pc, #0x54] */
/* @0x2485b4 vldr d6, [pc, #52] */
/* @0x2485b8 mov r12, #13 */
/* @0x2485bc add r1, pc, r1 */
/* @0x2485c0 str r12, [sp, #0x14] */
/* @0x2485c4 vmoveq.f64 d7, d6 */
/* @0x2485c8 vstr d7, [sp, #8] */
/* @0x2485cc bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x2485d0 b 0x2484dc <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0xfc> */
/* @0x2485d4 mov r1, #1 */
/* @0x2485d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2485dc b 0x2484bc <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0xdc> */
/* @0x2485e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2485e4 mov r1, r0 */
/* @0x2485e8 b 0x248470 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x90> */
/* @0x2485ec nop */
/* @0x2485f8 andseq sp, r0, r8, lsr #3 */
/* @0x2485fc andseq sp, r0, r8, ror #2 */
/* @0x248600 andseq sp, r0, r4, lsl r1 */
/* @0x248604 andseq sp, r0, r0, ror #1 */
/* @0x248608 ldrdeq lr, pc, [lr], -r8 */
/* @0x24860c andseq sp, r0, r12, rrx */

/* ── FUNC 0x248610 · JS_DefineOwnPropertyRV(YYObjectBase*, RValue*, RValue*, bool) · size=12 · insn=3 */
/* @0x248610 ldr r1, [r1] */
/* @0x248614 ldr r1, [r1] */
/* @0x248618 b 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */

/* ── FUNC 0x24861c · JS_Array_Put(YYObjectBase*, RValue*, char const*) · size=156 · insn=39 */
/* @0x24861c ldr r3, [pc, #0x90] */
/* @0x248620 mov r12, r2 */
/* @0x248624 push {r4, r5, r6, lr} */
/* @0x248628 ldr r3, [pc, r3] */
/* @0x24862c sub sp, sp, #32 */
/* @0x248630 mov r5, r0 */
/* @0x248634 ldr lr, [r3] */
/* @0x248638 mov r6, r1 */
/* @0x24863c ldrb r4, [r12], #1 */
/* @0x248640 cmp r4, #0 */
/* @0x248644 add r3, lr, r4 */
/* @0x248648 bne 0x24868c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc+0x70> */
/* @0x24864c mov r0, r2 */
/* @0x248650 bl 0xb66c4 <atol@plt> */
/* @0x248654 add r3, sp, #32 */
/* @0x248658 mov r2, r6 */
/* @0x24865c mov r1, sp */
/* @0x248660 str r5, [r3, #-0x10]! */
/* @0x248664 mov r12, #6 */
/* @0x248668 str r4, [sp, #0xc] */
/* @0x24866c str r12, [sp, #0x1c] */
/* @0x248670 vmov s13, r0 */
/* @0x248674 mov r0, r3 */
/* @0x248678 vcvt.f64.s32 d7, s13 */
/* @0x24867c vstr d7, [sp] */
/* @0x248680 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x248684 add sp, sp, #32 */
/* @0x248688 pop {r4, r5, r6, pc} */
/* @0x24868c ldrb r3, [r3, #0x1] */
/* @0x248690 and r3, r3, #4 */
/* @0x248694 ands r3, r3, #255 */
/* @0x248698 bne 0x24863c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc+0x20> */
/* @0x24869c mov r1, r2 */
/* @0x2486a0 mov r0, r5 */
/* @0x2486a4 mov r2, r6 */
/* @0x2486a8 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x2486ac add sp, sp, #32 */
/* @0x2486b0 pop {r4, r5, r6, pc} */
/* @0x2486b4 andseq r5, r10, r8, asr r3 */

/* ── FUNC 0x2486b8 · JS_String_prototype_split_RegEx(RValue&, YYObjectBase*, char const*, int, int, RValue*) · size=1036 · insn=259 */
/* @0x2486b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2486bc sub sp, sp, #508 */
/* @0x2486c0 mov r11, r2 */
/* @0x2486c4 ldr r12, [sp, #0x220] */
/* @0x2486c8 str r0, [sp, #0x18] */
/* @0x2486cc cmp r12, #0 */
/* @0x2486d0 str r1, [sp, #0x24] */
/* @0x2486d4 str r3, [sp, #0x2c] */
/* @0x2486d8 beq 0x248a48 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x390> */
/* @0x2486dc mov r3, #0 */
/* @0x2486e0 add r12, sp, #104 */
/* @0x2486e4 add r6, sp, #88 */
/* @0x2486e8 str r12, [sp, #0x10] */
/* @0x2486ec add r12, sp, #72 */
/* @0x2486f0 str r12, [sp, #0x14] */
/* @0x2486f4 ldr r12, [sp, #0x2c] */
/* @0x2486f8 mov r9, r3 */
/* @0x2486fc mov r4, r3 */
/* @0x248700 mov r5, r3 */
/* @0x248704 sub r12, r12, #2 */
/* @0x248708 str r3, [sp, #0x20] */
/* @0x24870c str r12, [sp, #0x34] */
/* @0x248710 add r12, sp, #56 */
/* @0x248714 str r3, [sp, #0x3c] */
/* @0x248718 str r12, [sp, #0x1c] */
/* @0x24871c str r3, [sp, #0x40] */
/* @0x248720 str r3, [sp, #0x44] */
/* @0x248724 str r3, [sp, #0x48] */
/* @0x248728 str r3, [sp, #0x4c] */
/* @0x24872c str r3, [sp, #0x50] */
/* @0x248730 str r3, [sp, #0x54] */
/* @0x248734 str r3, [sp, #0x58] */
/* @0x248738 str r3, [sp, #0x5c] */
/* @0x24873c str r3, [sp, #0x60] */
/* @0x248740 str r3, [sp, #0x64] */
/* @0x248744 ldr r12, [sp, #0x24] */
/* @0x248748 add lr, sp, #104 */
/* @0x24874c mov r2, r11 */
/* @0x248750 ldr r3, [sp, #0x220] */
/* @0x248754 ldr r0, [r12, #0x1c] */
/* @0x248758 ldr r1, [r12, #0x20] */
/* @0x24875c mov r12, #100 */
/* @0x248760 str r9, [sp] */
/* @0x248764 str r5, [sp, #0x4] */
/* @0x248768 str lr, [sp, #0x8] */
/* @0x24876c str r12, [sp, #0xc] */
/* @0x248770 bl 0x279390 <pcre_exec> */
/* @0x248774 subs r7, r0, #0 */
/* @0x248778 ble 0x248934 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x27c> */
/* @0x24877c ldr r12, [sp, #0x6c] */
/* @0x248780 ldr r10, [sp, #0x68] */
/* @0x248784 cmp r12, r4 */
/* @0x248788 str r12, [sp, #0x28] */
/* @0x24878c beq 0x248934 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x27c> */
/* @0x248790 cmp r10, r4 */
/* @0x248794 str r5, [sp, #0x44] */
/* @0x248798 ble 0x248a98 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x3e0> */
/* @0x24879c add r4, r11, r4 */
/* @0x2487a0 add r9, r11, r10 */
/* @0x2487a4 mov r2, #0 */
/* @0x2487a8 str r6, [sp, #0x30] */
/* @0x2487ac ldr r3, [sp, #0x40] */
/* @0x2487b0 mvn r1, r2 */
/* @0x2487b4 ldrb r8, [r4], #1 */
/* @0x2487b8 add r1, r3, r1 */
/* @0x2487bc cmp r1, #1 */
/* @0x2487c0 bgt 0x24881c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x164> */
/* @0x2487c4 add r1, r3, r3, lsl #1 */
/* @0x2487c8 cmp r3, #0 */
/* @0x2487cc add r2, r2, #2 */
/* @0x2487d0 mov r10, #3 */
/* @0x2487d4 add r1, r1, r1, lsr #31 */
/* @0x2487d8 ldr r6, [sp, #0x3c] */
/* @0x2487dc asrne r10, r1, #1 */
/* @0x2487e0 cmp r2, r10 */
/* @0x2487e4 add r2, r2, r2, lsl #1 */
/* @0x2487e8 addgt r2, r2, r2, lsr #31 */
/* @0x2487ec asrgt r10, r2, #1 */
/* @0x2487f0 mov r0, r10 */
/* @0x2487f4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x2487f8 mov r1, r6 */
/* @0x2487fc ldr r2, [sp, #0x40] */
/* @0x248800 str r0, [sp, #0x3c] */
/* @0x248804 bl 0xb65bc <memcpy@plt> */
/* @0x248808 subs r0, r6, #0 */
/* @0x24880c str r10, [sp, #0x40] */
/* @0x248810 beq 0x248818 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x160> */
/* @0x248814 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248818 ldr r2, [sp, #0x44] */
/* @0x24881c ldr r3, [sp, #0x3c] */
/* @0x248820 cmp r4, r9 */
/* @0x248824 add r1, r3, r2 */
/* @0x248828 strb r8, [r3, r2] */
/* @0x24882c strb r5, [r1, #0x1] */
/* @0x248830 ldr r2, [sp, #0x44] */
/* @0x248834 add r2, r2, #1 */
/* @0x248838 str r2, [sp, #0x44] */
/* @0x24883c bne 0x2487ac <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0xf4> */
/* @0x248840 vldr s13, [sp, #32] */
/* @0x248844 vcvt.f64.s32 d7, s13 */
/* @0x248848 cmp r2, #0 */
/* @0x24884c ldr r6, [sp, #0x30] */
/* @0x248850 addeq r1, sp, #68 */
/* @0x248854 ldrne r1, [sp, #0x3c] */
/* @0x248858 vstr d7, [sp, #72] */
/* @0x24885c mov r0, r6 */
/* @0x248860 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x248864 ldr r12, [sp, #0x20] */
/* @0x248868 ldr r0, [sp, #0x18] */
/* @0x24886c add r1, sp, #72 */
/* @0x248870 mov r2, r6 */
/* @0x248874 add r4, r12, #1 */
/* @0x248878 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x24887c ldr r12, [sp, #0x2c] */
/* @0x248880 cmp r4, r12 */
/* @0x248884 beq 0x24891c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x264> */
/* @0x248888 cmp r7, #1 */
/* @0x24888c beq 0x248a38 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x380> */
/* @0x248890 ldr lr, [sp, #0x20] */
/* @0x248894 mov r10, #0 */
/* @0x248898 ldr r12, [sp, #0x34] */
/* @0x24889c add r8, lr, r7 */
/* @0x2488a0 rsb r9, lr, r12 */
/* @0x2488a4 mov r3, r8 */
/* @0x2488a8 mov r8, r4 */
/* @0x2488ac mov r4, r3 */
/* @0x2488b0 b 0x2488bc <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x204> */
/* @0x2488b4 cmp r8, r4 */
/* @0x2488b8 beq 0x248a34 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x37c> */
/* @0x2488bc vmov s13, r8 */
/* @0x2488c0 mov r3, r10 */
/* @0x2488c4 add r2, sp, #56 */
/* @0x2488c8 add r1, sp, #104 */
/* @0x2488cc vcvt.f64.s32 d7, s13 */
/* @0x2488d0 str r2, [sp] */
/* @0x2488d4 mov r0, r11 */
/* @0x2488d8 mov r2, r7 */
/* @0x2488dc str r5, [sp, #0x38] */
/* @0x2488e0 add r8, r8, #1 */
/* @0x2488e4 vstr d7, [sp, #72] */
/* @0x2488e8 bl 0x25f5e8 <pcre_get_substring> */
/* @0x2488ec mov r0, r6 */
/* @0x2488f0 ldr r1, [sp, #0x38] */
/* @0x2488f4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2488f8 add r1, sp, #72 */
/* @0x2488fc mov r2, r6 */
/* @0x248900 ldr r0, [sp, #0x18] */
/* @0x248904 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x248908 ldr r0, [sp, #0x38] */
/* @0x24890c bl 0x25f6ac <pcre_free_substring> */
/* @0x248910 cmp r10, r9 */
/* @0x248914 add r10, r10, #1 */
/* @0x248918 bne 0x2488b4 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x1fc> */
/* @0x24891c ldr r0, [sp, #0x3c] */
/* @0x248920 cmp r0, #0 */
/* @0x248924 beq 0x24892c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x274> */
/* @0x248928 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24892c add sp, sp, #508 */
/* @0x248930 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x248934 add r9, r9, #1 */
/* @0x248938 ldr r12, [sp, #0x220] */
/* @0x24893c cmp r12, r9 */
/* @0x248940 bne 0x248744 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x8c> */
/* @0x248944 cmp r12, r4 */
/* @0x248948 mov r3, #0 */
/* @0x24894c str r3, [sp, #0x44] */
/* @0x248950 ble 0x248aac <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x3f4> */
/* @0x248954 add r4, r11, r4 */
/* @0x248958 add r9, r11, r12 */
/* @0x24895c mov r7, r3 */
/* @0x248960 ldr r2, [sp, #0x40] */
/* @0x248964 mvn r1, r3 */
/* @0x248968 ldrb r8, [r4], #1 */
/* @0x24896c add r1, r2, r1 */
/* @0x248970 cmp r1, #1 */
/* @0x248974 bgt 0x2489d0 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x318> */
/* @0x248978 add r1, r2, r2, lsl #1 */
/* @0x24897c cmp r2, #0 */
/* @0x248980 add r3, r3, #2 */
/* @0x248984 mov r5, #3 */
/* @0x248988 add r1, r1, r1, lsr #31 */
/* @0x24898c ldr r10, [sp, #0x3c] */
/* @0x248990 asrne r5, r1, #1 */
/* @0x248994 cmp r3, r5 */
/* @0x248998 add r3, r3, r3, lsl #1 */
/* @0x24899c addgt r3, r3, r3, lsr #31 */
/* @0x2489a0 asrgt r5, r3, #1 */
/* @0x2489a4 mov r0, r5 */
/* @0x2489a8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x2489ac mov r1, r10 */
/* @0x2489b0 ldr r2, [sp, #0x40] */
/* @0x2489b4 str r0, [sp, #0x3c] */
/* @0x2489b8 bl 0xb65bc <memcpy@plt> */
/* @0x2489bc subs r0, r10, #0 */
/* @0x2489c0 str r5, [sp, #0x40] */
/* @0x2489c4 beq 0x2489cc <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x314> */
/* @0x2489c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2489cc ldr r3, [sp, #0x44] */
/* @0x2489d0 ldr r2, [sp, #0x3c] */
/* @0x2489d4 cmp r4, r9 */
/* @0x2489d8 add r1, r2, r3 */
/* @0x2489dc strb r8, [r2, r3] */
/* @0x2489e0 strb r7, [r1, #0x1] */
/* @0x2489e4 ldr r3, [sp, #0x44] */
/* @0x2489e8 add r3, r3, #1 */
/* @0x2489ec str r3, [sp, #0x44] */
/* @0x2489f0 bne 0x248960 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x2a8> */
/* @0x2489f4 vldr s13, [sp, #32] */
/* @0x2489f8 vcvt.f64.s32 d7, s13 */
/* @0x2489fc cmp r3, #0 */
/* @0x248a00 addeq r1, sp, #68 */
/* @0x248a04 ldrne r1, [sp, #0x3c] */
/* @0x248a08 vstr d7, [sp, #72] */
/* @0x248a0c mov r0, r6 */
/* @0x248a10 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x248a14 ldr r0, [sp, #0x18] */
/* @0x248a18 add r1, sp, #72 */
/* @0x248a1c mov r2, r6 */
/* @0x248a20 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x248a24 ldr r0, [sp, #0x3c] */
/* @0x248a28 cmp r0, #0 */
/* @0x248a2c bne 0x248928 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x270> */
/* @0x248a30 b 0x24892c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x274> */
/* @0x248a34 mov r4, r8 */
/* @0x248a38 ldr r9, [sp, #0x28] */
/* @0x248a3c str r4, [sp, #0x20] */
/* @0x248a40 mov r4, r9 */
/* @0x248a44 b 0x248938 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x280> */
/* @0x248a48 ldr r0, [r1, #0x1c] */
/* @0x248a4c mov r3, r12 */
/* @0x248a50 ldr r1, [r1, #0x20] */
/* @0x248a54 add lr, sp, #104 */
/* @0x248a58 str r12, [sp] */
/* @0x248a5c mov r12, #100 */
/* @0x248a60 str r3, [sp, #0x4] */
/* @0x248a64 str lr, [sp, #0x8] */
/* @0x248a68 str r12, [sp, #0xc] */
/* @0x248a6c bl 0x279390 <pcre_exec> */
/* @0x248a70 cmp r0, #0 */
/* @0x248a74 ble 0x24892c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x274> */
/* @0x248a78 ldr r12, [sp, #0x18] */
/* @0x248a7c ldr r2, [pc, #0x3c] */
/* @0x248a80 ldr r1, [sp, #0x224] */
/* @0x248a84 ldr r0, [r12] */
/* @0x248a88 add r2, pc, r2 */
/* @0x248a8c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x248a90 add sp, sp, #508 */
/* @0x248a94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x248a98 vldr s13, [sp, #32] */
/* @0x248a9c vcvt.f64.s32 d7, s13 */
/* @0x248aa0 add r1, sp, #68 */
/* @0x248aa4 vstr d7, [sp, #72] */
/* @0x248aa8 b 0x24885c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x1a4> */
/* @0x248aac vldr s13, [sp, #32] */
/* @0x248ab0 vcvt.f64.s32 d7, s13 */
/* @0x248ab4 add r1, sp, #68 */
/* @0x248ab8 vstr d7, [sp, #72] */
/* @0x248abc b 0x248a0c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x354> */
/* @0x248ac0 andeq r9, lr, r4, ror #20 */

/* ── FUNC 0x248ac4 · JS_Array_DefineOwnProperty(YYObjectBase*, char const*, RValue*, bool) · size=148 · insn=37 */
/* @0x248ac4 push {r4, r5, r6, lr} */
/* @0x248ac8 sub sp, sp, #40 */
/* @0x248acc ldr lr, [pc, #0x80] */
/* @0x248ad0 mov r6, r0 */
/* @0x248ad4 mov r12, r1 */
/* @0x248ad8 ldr lr, [pc, lr] */
/* @0x248adc ldr r5, [lr] */
/* @0x248ae0 ldrb r4, [r12], #1 */
/* @0x248ae4 cmp r4, #0 */
/* @0x248ae8 add lr, r5, r4 */
/* @0x248aec bne 0x248b38 <_Z26JS_Array_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x74> */
/* @0x248af0 mov r0, r1 */
/* @0x248af4 str r2, [sp, #0x4] */
/* @0x248af8 bl 0xb66c4 <atol@plt> */
/* @0x248afc add r3, sp, #40 */
/* @0x248b00 ldr r2, [sp, #0x4] */
/* @0x248b04 add r1, sp, #8 */
/* @0x248b08 str r6, [r3, #-0x10]! */
/* @0x248b0c mov r12, #6 */
/* @0x248b10 str r4, [sp, #0x14] */
/* @0x248b14 str r12, [sp, #0x24] */
/* @0x248b18 vmov s13, r0 */
/* @0x248b1c mov r0, r3 */
/* @0x248b20 vcvt.f64.s32 d7, s13 */
/* @0x248b24 vstr d7, [sp, #8] */
/* @0x248b28 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_> */
/* @0x248b2c mov r0, #1 */
/* @0x248b30 add sp, sp, #40 */
/* @0x248b34 pop {r4, r5, r6, pc} */
/* @0x248b38 ldrb lr, [lr, #0x1] */
/* @0x248b3c tst lr, #4 */
/* @0x248b40 bne 0x248ae0 <_Z26JS_Array_DefineOwnPropertyP12YYObjectBasePKcP6RValueb+0x1c> */
/* @0x248b44 mov r0, r6 */
/* @0x248b48 bl 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb> */
/* @0x248b4c add sp, sp, #40 */
/* @0x248b50 pop {r4, r5, r6, pc} */
/* @0x248b54 andseq r4, r10, r8, lsr #29 */

/* ── FUNC 0x248b58 · CreateArgumentsObject(RValue&, YYObjectBase*, int, RValue*, bool) · size=1172 · insn=293 */
/* @0x248b58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x248b5c sub sp, sp, #60 */
/* @0x248b60 mov r12, #0 */
/* @0x248b64 mov r7, r2 */
/* @0x248b68 str r1, [sp, #0x10] */
/* @0x248b6c mov r2, r12 */
/* @0x248b70 mov r1, r12 */
/* @0x248b74 str r12, [sp] */
/* @0x248b78 mov r5, r3 */
/* @0x248b7c mov r3, r12 */
/* @0x248b80 ldrb r12, [sp, #0x60] */
/* @0x248b84 mov r4, r0 */
/* @0x248b88 str r12, [sp, #0x14] */
/* @0x248b8c bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x248b90 ldr r4, [r4] */
/* @0x248b94 str r4, [sp, #0xc] */
/* @0x248b98 ldr r0, [sp, #0xc] */
/* @0x248b9c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x248ba0 ldr lr, [sp, #0xc] */
/* @0x248ba4 ldr r4, [pc, #0x430] */
/* @0x248ba8 mov r2, r7 */
/* @0x248bac ldr r12, [pc, #0x42c] */
/* @0x248bb0 ldr r1, [lr, #0x28] */
/* @0x248bb4 add r4, pc, r4 */
/* @0x248bb8 ldr r3, [pc, #0x424] */
/* @0x248bbc add r12, pc, r12 */
/* @0x248bc0 mov r0, lr */
/* @0x248bc4 str r12, [lr, #0x40] */
/* @0x248bc8 ldr r3, [pc, r3] */
/* @0x248bcc orr r1, r1, #1 */
/* @0x248bd0 str r3, [lr, #0x4c] */
/* @0x248bd4 mov r3, #6 */
/* @0x248bd8 str r1, [lr, #0x28] */
/* @0x248bdc mov r1, r4 */
/* @0x248be0 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x248be4 ldr r0, [sp, #0x10] */
/* @0x248be8 mov r2, r4 */
/* @0x248bec add r1, sp, #24 */
/* @0x248bf0 mov r3, #5 */
/* @0x248bf4 str r3, [sp, #0x24] */
/* @0x248bf8 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x248bfc vmov s15, r7 */
/* @0x248c00 mov r1, #5 */
/* @0x248c04 mov r2, #0 */
/* @0x248c08 vcvt.f64.s32 d6, s15 */
/* @0x248c0c vldr d7, [sp, #24] */
/* @0x248c10 vcmpe.f64 d7, d6 */
/* @0x248c14 vmrs APSR_nzcv, fpscr */
/* @0x248c18 vcvtgt.s32.f64 s13, d7 */
/* @0x248c1c movle r0, r7 */
/* @0x248c20 vmovgt r0, s13 */
/* @0x248c24 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x248c28 ldr r12, [sp, #0xc] */
/* @0x248c2c ldr r3, [r12, #0x4] */
/* @0x248c30 cmp r3, #0 */
/* @0x248c34 mov r6, r0 */
/* @0x248c38 beq 0x248f1c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x3c4> */
/* @0x248c3c add r3, r3, #16 */
/* @0x248c40 mov r2, #6 */
/* @0x248c44 str r6, [r3] */
/* @0x248c48 ldr r0, [sp, #0xc] */
/* @0x248c4c mov r1, r6 */
/* @0x248c50 str r2, [r3, #0xc] */
/* @0x248c54 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x248c58 subs r4, r7, #1 */
/* @0x248c5c bmi 0x248d54 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1fc> */
/* @0x248c60 movw r8, #0xfff0 */
/* @0x248c64 movt r8, #0xffff */
/* @0x248c68 rsb r8, r5, r8 */
/* @0x248c6c add r11, r5, r7, lsl #4 */
/* @0x248c70 mov r7, #0 */
/* @0x248c74 ldr r3, [r6, #0x4] */
/* @0x248c78 add r5, r8, r11 */
/* @0x248c7c sub r9, r11, #16 */
/* @0x248c80 cmp r3, #0 */
/* @0x248c84 beq 0x248e88 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x330> */
/* @0x248c88 add r5, r3, r5 */
/* @0x248c8c mov r0, r6 */
/* @0x248c90 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x248c94 ldr r2, [r5, #0xc] */
/* @0x248c98 bic r3, r2, #-16777216 */
/* @0x248c9c cmp r3, #1 */
/* @0x248ca0 beq 0x248e0c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2b4> */
/* @0x248ca4 cmp r3, #2 */
/* @0x248ca8 bne 0x248ccc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x174> */
/* @0x248cac sub r2, r2, #1 */
/* @0x248cb0 bic r2, r2, #-16777216 */
/* @0x248cb4 bic r2, r2, #3 */
/* @0x248cb8 cmp r2, #0 */
/* @0x248cbc beq 0x248e7c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x324> */
/* @0x248cc0 mov lr, #5 */
/* @0x248cc4 str r7, [r5, #0x8] */
/* @0x248cc8 str lr, [r5, #0xc] */
/* @0x248ccc str r7, [r5] */
/* @0x248cd0 ldr r3, [r11, #-0x4] */
/* @0x248cd4 str r3, [r5, #0xc] */
/* @0x248cd8 ldr r3, [r11, #-0x8] */
/* @0x248cdc str r3, [r5, #0x8] */
/* @0x248ce0 ldr r3, [r11, #-0x4] */
/* @0x248ce4 bic r3, r3, #-16777216 */
/* @0x248ce8 cmp r3, #14 */
/* @0x248cec addls pc, pc, r3, lsl #2 */
/* @0x248cf0 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248cf4 b 0x248d98 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x240> */
/* @0x248cf8 b 0x248df4 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x29c> */
/* @0x248cfc b 0x248dc8 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x270> */
/* @0x248d00 b 0x248d30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1d8> */
/* @0x248d04 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248d08 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248d0c b 0x248da4 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x24c> */
/* @0x248d10 b 0x248d30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1d8> */
/* @0x248d14 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248d18 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248d1c b 0x248d98 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x240> */
/* @0x248d20 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248d24 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248d28 b 0x248d98 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x240> */
/* @0x248d2c b 0x248d30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1d8> */
/* @0x248d30 ldr r3, [r11, #-0x10] */
/* @0x248d34 str r3, [r5] */
/* @0x248d38 sub r4, r4, #1 */
/* @0x248d3c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x248d40 cmn r4, #1 */
/* @0x248d44 mov r2, #7 */
/* @0x248d48 mov r11, r9 */
/* @0x248d4c str r2, [r5, #0x8] */
/* @0x248d50 bne 0x248c74 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x11c> */
/* @0x248d54 ldr r12, [sp, #0x14] */
/* @0x248d58 cmp r12, #0 */
/* @0x248d5c bne 0x248d8c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x234> */
/* @0x248d60 ldr r12, [sp, #0x10] */
/* @0x248d64 add r2, sp, #40 */
/* @0x248d68 ldr r1, [pc, #0x278] */
/* @0x248d6c ldr r0, [sp, #0xc] */
/* @0x248d70 ldr r3, [sp, #0x14] */
/* @0x248d74 add r1, pc, r1 */
/* @0x248d78 str r12, [sp, #0x28] */
/* @0x248d7c mov r12, #6 */
/* @0x248d80 str r12, [sp, #0x34] */
/* @0x248d84 str r12, [sp, #0x30] */
/* @0x248d88 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x248d8c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x248d90 add sp, sp, #60 */
/* @0x248d94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x248d98 ldm r9, {r2, r3} */
/* @0x248d9c stm r5, {r2, r3} */
/* @0x248da0 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248da4 ldr r3, [r11, #-0x10] */
/* @0x248da8 str r3, [r5] */
/* @0x248dac ldr r3, [r11, #-0x10] */
/* @0x248db0 cmp r3, #0 */
/* @0x248db4 beq 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248db8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x248dbc ldr r1, [r11, #-0x10] */
/* @0x248dc0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x248dc4 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248dc8 ldr r3, [r11, #-0x10] */
/* @0x248dcc cmp r3, #0 */
/* @0x248dd0 str r3, [r5] */
/* @0x248dd4 beq 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248dd8 ldr r1, [r3, #0x8] */
/* @0x248ddc ldr r2, [r3] */
/* @0x248de0 cmp r1, #0 */
/* @0x248de4 streq r5, [r3, #0x8] */
/* @0x248de8 add r2, r2, #1 */
/* @0x248dec str r2, [r3] */
/* @0x248df0 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0> */
/* @0x248df4 ldr r3, [r11, #-0x10] */
/* @0x248df8 cmp r3, #0 */
/* @0x248dfc ldrne r2, [r3, #0x4] */
/* @0x248e00 addne r2, r2, #1 */
/* @0x248e04 strne r2, [r3, #0x4] */
/* @0x248e08 b 0x248d34 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1dc> */
/* @0x248e0c ldr r10, [r5] */
/* @0x248e10 cmp r10, #0 */
/* @0x248e14 beq 0x248e34 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2dc> */
/* @0x248e18 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248e1c ldr r3, [r10, #0x4] */
/* @0x248e20 sub r3, r3, #1 */
/* @0x248e24 str r3, [r10, #0x4] */
/* @0x248e28 cmp r3, #0 */
/* @0x248e2c beq 0x248e3c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2e4> */
/* @0x248e30 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248e34 str r7, [r5] */
/* @0x248e38 b 0x248ccc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x174> */
/* @0x248e3c ldr r0, [r10] */
/* @0x248e40 str r3, [sp, #0x8] */
/* @0x248e44 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248e48 ldr r3, [sp, #0x8] */
/* @0x248e4c str r3, [r10] */
/* @0x248e50 str r3, [r10, #0x8] */
/* @0x248e54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248e58 ldr r3, [r10, #0x4] */
/* @0x248e5c sub r3, r3, #1 */
/* @0x248e60 str r3, [r10, #0x4] */
/* @0x248e64 cmp r3, #0 */
/* @0x248e68 beq 0x248e9c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x344> */
/* @0x248e6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248e70 mov r0, r10 */
/* @0x248e74 bl 0x27d1d0 <_ZdlPv> */
/* @0x248e78 b 0x248e30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2d8> */
/* @0x248e7c mov r0, r5 */
/* @0x248e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x248e84 b 0x248cc0 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x168> */
/* @0x248e88 mov r0, r6 */
/* @0x248e8c mov r1, r4 */
/* @0x248e90 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x248e94 mov r5, r0 */
/* @0x248e98 b 0x248c8c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x134> */
/* @0x248e9c ldr r0, [r10] */
/* @0x248ea0 str r3, [sp, #0x8] */
/* @0x248ea4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248ea8 ldr r3, [sp, #0x8] */
/* @0x248eac str r3, [r10] */
/* @0x248eb0 str r3, [r10, #0x8] */
/* @0x248eb4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248eb8 ldr r3, [r10, #0x4] */
/* @0x248ebc sub r3, r3, #1 */
/* @0x248ec0 str r3, [r10, #0x4] */
/* @0x248ec4 cmp r3, #0 */
/* @0x248ec8 beq 0x248edc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x384> */
/* @0x248ecc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248ed0 mov r0, r10 */
/* @0x248ed4 bl 0x27d1d0 <_ZdlPv> */
/* @0x248ed8 b 0x248e6c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x314> */
/* @0x248edc ldr r0, [r10] */
/* @0x248ee0 str r3, [sp, #0x8] */
/* @0x248ee4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248ee8 ldr r3, [sp, #0x8] */
/* @0x248eec str r3, [r10] */
/* @0x248ef0 str r3, [r10, #0x8] */
/* @0x248ef4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248ef8 ldr r3, [r10, #0x4] */
/* @0x248efc sub r3, r3, #1 */
/* @0x248f00 str r3, [r10, #0x4] */
/* @0x248f04 cmp r3, #0 */
/* @0x248f08 beq 0x248f30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x3d8> */
/* @0x248f0c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248f10 mov r0, r10 */
/* @0x248f14 bl 0x27d1d0 <_ZdlPv> */
/* @0x248f18 b 0x248ecc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x374> */
/* @0x248f1c ldr r0, [sp, #0xc] */
/* @0x248f20 mov r1, #1 */
/* @0x248f24 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x248f28 mov r3, r0 */
/* @0x248f2c b 0x248c40 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0xe8> */
/* @0x248f30 ldr r0, [r10] */
/* @0x248f34 str r3, [sp, #0x8] */
/* @0x248f38 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248f3c ldr r3, [sp, #0x8] */
/* @0x248f40 str r3, [r10] */
/* @0x248f44 str r3, [r10, #0x8] */
/* @0x248f48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248f4c ldr r3, [r10, #0x4] */
/* @0x248f50 sub r3, r3, #1 */
/* @0x248f54 str r3, [r10, #0x4] */
/* @0x248f58 cmp r3, #0 */
/* @0x248f5c beq 0x248f70 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x418> */
/* @0x248f60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248f64 mov r0, r10 */
/* @0x248f68 bl 0x27d1d0 <_ZdlPv> */
/* @0x248f6c b 0x248f0c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x3b4> */
/* @0x248f70 ldr r0, [r10] */
/* @0x248f74 str r3, [sp, #0x8] */
/* @0x248f78 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248f7c ldr r3, [sp, #0x8] */
/* @0x248f80 str r3, [r10] */
/* @0x248f84 str r3, [r10, #0x8] */
/* @0x248f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x248f8c ldr r3, [r10, #0x4] */
/* @0x248f90 sub r3, r3, #1 */
/* @0x248f94 str r3, [r10, #0x4] */
/* @0x248f98 cmp r3, #0 */
/* @0x248f9c beq 0x248fb0 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x458> */
/* @0x248fa0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x248fa4 mov r0, r10 */
/* @0x248fa8 bl 0x27d1d0 <_ZdlPv> */
/* @0x248fac b 0x248f60 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x408> */
/* @0x248fb0 ldr r0, [r10] */
/* @0x248fb4 str r3, [sp, #0x8] */
/* @0x248fb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x248fbc ldr r3, [sp, #0x8] */
/* @0x248fc0 mov r0, r10 */
/* @0x248fc4 str r3, [r10] */
/* @0x248fc8 str r3, [r10, #0x8] */
/* @0x248fcc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x248fd0 mov r0, r10 */
/* @0x248fd4 bl 0x27d1d0 <_ZdlPv> */
/* @0x248fd8 b 0x248fa0 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x448> */
/* @0x248fdc strheq r7, [lr], -r8 */
/* @0x248fe0 andseq sp, r0, r8, lsl #5 */
/* @0x248fe4 andseq r8, r10, r0, lsl #24 */
/* @0x248fe8 ldrsbeq sp, [r0], -r12 */

/* ── FUNC 0x248fec · Call_Accessor_Get(YYObjectBase*, RValue*, RValue*) · size=596 · insn=149 */
/* @0x248fec ldr r12, [r2, #0xc] */
/* @0x248ff0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x248ff4 bic r12, r12, #-16777216 */
/* @0x248ff8 ldr r6, [pc, #0x22c] */
/* @0x248ffc cmp r12, #6 */
/* @0x249000 sub sp, sp, #52 */
/* @0x249004 mov r7, r0 */
/* @0x249008 add r6, pc, r6 */
/* @0x24900c mov r8, r1 */
/* @0x249010 beq 0x24901c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x249014 add sp, sp, #52 */
/* @0x249018 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24901c ldr r4, [r2] */
/* @0x249020 ldr r3, [r4, #0x48] */
/* @0x249024 cmp r3, #2 */
/* @0x249028 bne 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x24902c ldr r1, [r4, #0x4] */
/* @0x249030 cmp r1, #0 */
/* @0x249034 beq 0x2491c4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1d8> */
/* @0x249038 ldr r2, [r1, #0xc] */
/* @0x24903c mvn r3, #-16777216 */
/* @0x249040 cmp r2, r3 */
/* @0x249044 moveq r3, #5 */
/* @0x249048 streq r3, [r8, #0xc] */
/* @0x24904c beq 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x249050 ldr r1, [r4, #0x4] */
/* @0x249054 cmp r1, #0 */
/* @0x249058 beq 0x2491d4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1e8> */
/* @0x24905c ldr r10, [r1] */
/* @0x249060 cmp r10, #0 */
/* @0x249064 beq 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x249068 ldr r9, [r10, #0x64] */
/* @0x24906c cmp r9, #0 */
/* @0x249070 beq 0x24914c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x160> */
/* @0x249074 ldr r3, [pc, #0x1b4] */
/* @0x249078 mov r4, #0 */
/* @0x24907c mov r5, #0 */
/* @0x249080 ldr r3, [r6, r3] */
/* @0x249084 ldr r0, [r3] */
/* @0x249088 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0x24908c ldr r3, [r10, #0x78] */
/* @0x249090 mvn r2, #-16777216 */
/* @0x249094 strd r4, r5, [sp, #32] */
/* @0x249098 cmp r3, #6 */
/* @0x24909c ldreq r3, [r10, #0x6c] */
/* @0x2490a0 mov r11, r0 */
/* @0x2490a4 streq r3, [r0, #0xc] */
/* @0x2490a8 mov r0, r9 */
/* @0x2490ac mov r3, #0 */
/* @0x2490b0 str r2, [sp, #0x2c] */
/* @0x2490b4 str r3, [sp, #0x28] */
/* @0x2490b8 str r3, [sp, #0x1c] */
/* @0x2490bc bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x2490c0 ldr r3, [sp, #0x1c] */
/* @0x2490c4 ldr r2, [r0, #0x78] */
/* @0x2490c8 tst r2, #1 */
/* @0x2490cc bne 0x249180 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x194> */
/* @0x2490d0 ldr r3, [pc, #0x15c] */
/* @0x2490d4 ldr r4, [r6, r3] */
/* @0x2490d8 ldrb r3, [r4] */
/* @0x2490dc cmp r3, #0 */
/* @0x2490e0 bne 0x2491a8 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1bc> */
/* @0x2490e4 mov r0, r7 */
/* @0x2490e8 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x2490ec ldr r12, [sp, #0x20] */
/* @0x2490f0 ldr r0, [r9, #0x8] */
/* @0x2490f4 mov r3, r8 */
/* @0x2490f8 mov r1, r7 */
/* @0x2490fc mov r2, r7 */
/* @0x249100 str r12, [sp, #0x10] */
/* @0x249104 mov r12, #0 */
/* @0x249108 str r11, [sp] */
/* @0x24910c str r12, [sp, #0x4] */
/* @0x249110 str r12, [sp, #0x8] */
/* @0x249114 str r12, [sp, #0xc] */
/* @0x249118 bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_> */
/* @0x24911c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x249120 ldrb r3, [r4] */
/* @0x249124 cmp r3, #0 */
/* @0x249128 bne 0x249198 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1ac> */
/* @0x24912c mov r0, r9 */
/* @0x249130 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x249134 ldr r3, [r0, #0x78] */
/* @0x249138 tst r3, #2 */
/* @0x24913c bne 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x249140 mov r0, r11 */
/* @0x249144 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0x249148 b 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x24914c ldr r4, [r10, #0x68] */
/* @0x249150 cmp r4, #0 */
/* @0x249154 beq 0x2491e4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1f8> */
/* @0x249158 mov r0, r7 */
/* @0x24915c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x249160 mov r1, r7 */
/* @0x249164 mov r0, r8 */
/* @0x249168 mov r3, r9 */
/* @0x24916c mov r2, r7 */
/* @0x249170 str r9, [sp] */
/* @0x249174 blx r4 */
/* @0x249178 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x24917c b 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x249180 mov r2, r3 */
/* @0x249184 str r3, [sp] */
/* @0x249188 mov r1, r10 */
/* @0x24918c add r0, sp, #32 */
/* @0x249190 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b> */
/* @0x249194 b 0x2490d0 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0xe4> */
/* @0x249198 ldr r3, [pc, #0x98] */
/* @0x24919c ldr r0, [r6, r3] */
/* @0x2491a0 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x2491a4 b 0x24912c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x140> */
/* @0x2491a8 ldr r2, [pc, #0x88] */
/* @0x2491ac mov r1, #1 */
/* @0x2491b0 ldr r3, [r9, #0x8] */
/* @0x2491b4 ldr r0, [r6, r2] */
/* @0x2491b8 ldr r2, [r3, #0x60] */
/* @0x2491bc bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x2491c0 b 0x2490e4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0xf8> */
/* @0x2491c4 mov r0, r4 */
/* @0x2491c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2491cc mov r1, r0 */
/* @0x2491d0 b 0x249038 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x4c> */
/* @0x2491d4 mov r0, r4 */
/* @0x2491d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2491dc mov r1, r0 */
/* @0x2491e0 b 0x24905c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x70> */
/* @0x2491e4 ldr r1, [pc, #0x50] */
/* @0x2491e8 mov r0, r10 */
/* @0x2491ec add r1, pc, r1 */
/* @0x2491f0 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x2491f4 subs r3, r0, #0 */
/* @0x2491f8 beq 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x2491fc ldr r2, [r3, #0xc] */
/* @0x249200 cmp r2, #3 */
/* @0x249204 bne 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x249208 mov r0, r7 */
/* @0x24920c ldr r5, [r3] */
/* @0x249210 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x249214 mov r1, r4 */
/* @0x249218 mov r2, r8 */
/* @0x24921c mov r0, r7 */
/* @0x249220 blx r5 */
/* @0x249224 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x249228 b 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28> */
/* @0x24922c andseq r8, r10, r8, asr #24 */
/* @0x249230 .word 0xffffc104 */
/* @0x249234 .word 0xffffbf18 */
/* @0x249238 .word 0xffffbf1c */
/* @0x24923c andseq r12, r0, r12, lsr #4 */

/* ── FUNC 0x249240 · F_JS_Object_Get(YYObjectBase*, RValue*, char const*) · size=220 · insn=55 */
/* @0x249240 push {r4, r5, lr} */
/* @0x249244 mov r4, r1 */
/* @0x249248 sub sp, sp, #20 */
/* @0x24924c mov r5, r0 */
/* @0x249250 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x249254 ldr r3, [r4, #0xc] */
/* @0x249258 mvn r2, #-16777216 */
/* @0x24925c cmp r3, #5 */
/* @0x249260 cmpne r3, r2 */
/* @0x249264 bne 0x249270 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x30> */
/* @0x249268 add sp, sp, #20 */
/* @0x24926c pop {r4, r5, pc} */
/* @0x249270 mov r0, r4 */
/* @0x249274 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x249278 cmp r0, #0 */
/* @0x24927c bne 0x249268 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x28> */
/* @0x249280 ldr r0, [r4] */
/* @0x249284 ldr r1, [r0, #0x4] */
/* @0x249288 cmp r1, #0 */
/* @0x24928c beq 0x249304 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xc4> */
/* @0x249290 ldr r3, [r1, #0xc] */
/* @0x249294 cmp r3, #5 */
/* @0x249298 beq 0x2492e8 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xa8> */
/* @0x24929c ldr r0, [r4] */
/* @0x2492a0 ldr r1, [r0, #0x4] */
/* @0x2492a4 cmp r1, #0 */
/* @0x2492a8 beq 0x249310 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xd0> */
/* @0x2492ac ldr r2, [r1, #0xc] */
/* @0x2492b0 mvn r3, #-16777216 */
/* @0x2492b4 cmp r2, r3 */
/* @0x2492b8 beq 0x2492e8 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0xa8> */
/* @0x2492bc mov r0, r5 */
/* @0x2492c0 mov r2, r4 */
/* @0x2492c4 mov r1, sp */
/* @0x2492c8 bl 0x248fec <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_> */
/* @0x2492cc mov r12, sp */
/* @0x2492d0 ldm r12!, {r0, r1, r2, r3} */
/* @0x2492d4 str r0, [r4] */
/* @0x2492d8 str r1, [r4, #0x4] */
/* @0x2492dc str r2, [r4, #0x8] */
/* @0x2492e0 str r3, [r4, #0xc] */
/* @0x2492e4 b 0x249268 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x28> */
/* @0x2492e8 mov r3, #0 */
/* @0x2492ec mov r2, #5 */
/* @0x2492f0 str r3, [r4] */
/* @0x2492f4 str r3, [r4, #0x4] */
/* @0x2492f8 str r3, [r4, #0x8] */
/* @0x2492fc str r2, [r4, #0xc] */
/* @0x249300 b 0x249268 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x28> */
/* @0x249304 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x249308 mov r1, r0 */
/* @0x24930c b 0x249290 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x50> */
/* @0x249310 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x249314 mov r1, r0 */
/* @0x249318 b 0x2492ac <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc+0x6c> */

/* ── FUNC 0x24931c · Call_Accessor_Set(YYObjectBase*, RValue*, RValue*) · size=628 · insn=157 */
/* @0x24931c ldr r12, [r2, #0xc] */
/* @0x249320 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x249324 bic r12, r12, #-16777216 */
/* @0x249328 sub sp, sp, #68 */
/* @0x24932c ldr r6, [pc, #0x248] */
/* @0x249330 cmp r12, #6 */
/* @0x249334 mov r4, #5 */
/* @0x249338 add r6, pc, r6 */
/* @0x24933c mov r7, r0 */
/* @0x249340 mov r8, r1 */
/* @0x249344 str r4, [sp, #0x2c] */
/* @0x249348 beq 0x249354 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x38> */
/* @0x24934c add sp, sp, #68 */
/* @0x249350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x249354 ldr r4, [r2] */
/* @0x249358 ldr r3, [r4, #0x48] */
/* @0x24935c cmp r3, #2 */
/* @0x249360 bne 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x249364 ldr r3, [r4, #0x4] */
/* @0x249368 cmp r3, #0 */
/* @0x24936c beq 0x24950c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1f0> */
/* @0x249370 add r0, r3, #16 */
/* @0x249374 ldr r1, [r0, #0xc] */
/* @0x249378 mvn r3, #-16777216 */
/* @0x24937c cmp r1, r3 */
/* @0x249380 moveq r3, #5 */
/* @0x249384 streq r3, [r2, #0xc] */
/* @0x249388 beq 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x24938c ldr r3, [r4, #0x4] */
/* @0x249390 cmp r3, #0 */
/* @0x249394 beq 0x249524 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x208> */
/* @0x249398 add r0, r3, #16 */
/* @0x24939c ldr r9, [r0] */
/* @0x2493a0 cmp r9, #0 */
/* @0x2493a4 beq 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x2493a8 ldr r10, [r9, #0x64] */
/* @0x2493ac cmp r10, #0 */
/* @0x2493b0 beq 0x249490 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x174> */
/* @0x2493b4 ldr r3, [pc, #0x1c4] */
/* @0x2493b8 mov r4, #0 */
/* @0x2493bc mov r5, #0 */
/* @0x2493c0 ldr r3, [r6, r3] */
/* @0x2493c4 ldr r0, [r3] */
/* @0x2493c8 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0x2493cc ldr r3, [r9, #0x78] */
/* @0x2493d0 mvn r2, #-16777216 */
/* @0x2493d4 strd r4, r5, [sp, #48] */
/* @0x2493d8 cmp r3, #6 */
/* @0x2493dc ldreq r3, [r9, #0x6c] */
/* @0x2493e0 mov r11, r0 */
/* @0x2493e4 streq r3, [r0, #0xc] */
/* @0x2493e8 mov r0, r10 */
/* @0x2493ec mov r3, #0 */
/* @0x2493f0 str r2, [sp, #0x3c] */
/* @0x2493f4 str r3, [sp, #0x38] */
/* @0x2493f8 str r3, [sp, #0x1c] */
/* @0x2493fc bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x249400 ldr r3, [sp, #0x1c] */
/* @0x249404 ldr r2, [r0, #0x78] */
/* @0x249408 tst r2, #1 */
/* @0x24940c bne 0x2494c4 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1a8> */
/* @0x249410 ldr r3, [pc, #0x16c] */
/* @0x249414 ldr r4, [r6, r3] */
/* @0x249418 ldrb r3, [r4] */
/* @0x24941c cmp r3, #0 */
/* @0x249420 bne 0x2494f0 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1d4> */
/* @0x249424 mov r0, r7 */
/* @0x249428 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x24942c ldr r3, [sp, #0x30] */
/* @0x249430 ldr r0, [r10, #0x8] */
/* @0x249434 mov r12, #1 */
/* @0x249438 mov r1, r7 */
/* @0x24943c mov r2, r7 */
/* @0x249440 str r3, [sp, #0x10] */
/* @0x249444 mov r3, #0 */
/* @0x249448 str r12, [sp, #0x4] */
/* @0x24944c str r3, [sp, #0xc] */
/* @0x249450 add r3, sp, #32 */
/* @0x249454 str r11, [sp] */
/* @0x249458 str r8, [sp, #0x8] */
/* @0x24945c bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_> */
/* @0x249460 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x249464 ldrb r3, [r4] */
/* @0x249468 cmp r3, #0 */
/* @0x24946c bne 0x2494e0 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x1c4> */
/* @0x249470 mov r0, r10 */
/* @0x249474 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x249478 ldr r3, [r0, #0x78] */
/* @0x24947c tst r3, #2 */
/* @0x249480 bne 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x249484 mov r0, r11 */
/* @0x249488 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0x24948c b 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x249490 ldr r4, [r9, #0x68] */
/* @0x249494 cmp r4, #0 */
/* @0x249498 beq 0x249534 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x218> */
/* @0x24949c mov r0, r7 */
/* @0x2494a0 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x2494a4 mov r1, r7 */
/* @0x2494a8 mov r2, r7 */
/* @0x2494ac add r0, sp, #32 */
/* @0x2494b0 mov r3, #1 */
/* @0x2494b4 str r8, [sp] */
/* @0x2494b8 blx r4 */
/* @0x2494bc bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x2494c0 b 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x2494c4 str r3, [sp] */
/* @0x2494c8 mov r1, r9 */
/* @0x2494cc add r0, sp, #48 */
/* @0x2494d0 mov r2, #1 */
/* @0x2494d4 mov r3, r8 */
/* @0x2494d8 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b> */
/* @0x2494dc b 0x249410 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0xf4> */
/* @0x2494e0 ldr r3, [pc, #0xa0] */
/* @0x2494e4 ldr r0, [r6, r3] */
/* @0x2494e8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x2494ec b 0x249470 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x154> */
/* @0x2494f0 ldr r2, [pc, #0x90] */
/* @0x2494f4 mov r1, #1 */
/* @0x2494f8 ldr r3, [r10, #0x8] */
/* @0x2494fc ldr r0, [r6, r2] */
/* @0x249500 ldr r2, [r3, #0x60] */
/* @0x249504 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x249508 b 0x249424 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x108> */
/* @0x24950c mov r0, r4 */
/* @0x249510 mov r1, #1 */
/* @0x249514 str r2, [sp, #0x1c] */
/* @0x249518 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24951c ldr r2, [sp, #0x1c] */
/* @0x249520 b 0x249374 <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x58> */
/* @0x249524 mov r0, r4 */
/* @0x249528 mov r1, #1 */
/* @0x24952c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x249530 b 0x24939c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x80> */
/* @0x249534 ldr r1, [pc, #0x50] */
/* @0x249538 mov r0, r9 */
/* @0x24953c add r1, pc, r1 */
/* @0x249540 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x249544 subs r3, r0, #0 */
/* @0x249548 beq 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x24954c ldr r2, [r3, #0xc] */
/* @0x249550 cmp r2, #3 */
/* @0x249554 bne 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x249558 mov r0, r7 */
/* @0x24955c ldr r5, [r3] */
/* @0x249560 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x249564 mov r1, r4 */
/* @0x249568 mov r2, r8 */
/* @0x24956c mov r0, r7 */
/* @0x249570 blx r5 */
/* @0x249574 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x249578 b 0x24934c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_+0x30> */
/* @0x24957c andseq r8, r10, r8, lsl r9 */
/* @0x249580 .word 0xffffc104 */
/* @0x249584 .word 0xffffbf18 */
/* @0x249588 .word 0xffffbf1c */
/* @0x24958c ldrsbeq r11, [r0], -r12 */

/* ── FUNC 0x249590 · Call_ScriptRef(YYObjectBase*, RValue*, CScriptRef*, int, RValue*) · size=720 · insn=180 */
/* @0x249590 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x249594 mov r8, r2 */
/* @0x249598 ldr r2, [r2, #0x88] */
/* @0x24959c mov r7, r0 */
/* @0x2495a0 ldr r5, [r8, #0x64] */
/* @0x2495a4 sub sp, sp, #52 */
/* @0x2495a8 cmp r2, #6 */
/* @0x2495ac ldr r4, [pc, #0x28c] */
/* @0x2495b0 mov r9, r1 */
/* @0x2495b4 mov r6, r3 */
/* @0x2495b8 ldreq r7, [r8, #0x7c] */
/* @0x2495bc cmp r5, #0 */
/* @0x2495c0 add r4, pc, r4 */
/* @0x2495c4 beq 0x24976c <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x1dc> */
/* @0x2495c8 ldr r3, [pc, #0x274] */
/* @0x2495cc ldr r3, [r4, r3] */
/* @0x2495d0 ldr r0, [r3] */
/* @0x2495d4 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0x2495d8 ldr r3, [r8, #0x78] */
/* @0x2495dc cmp r3, #6 */
/* @0x2495e0 ldreq r3, [r8, #0x6c] */
/* @0x2495e4 streq r3, [r0, #0xc] */
/* @0x2495e8 mov r10, r0 */
/* @0x2495ec ldr r3, [pc, #0x254] */
/* @0x2495f0 ldr r11, [r4, r3] */
/* @0x2495f4 ldr r0, [r11] */
/* @0x2495f8 cmn r0, #1 */
/* @0x2495fc movne r1, r0 */
/* @0x249600 beq 0x249818 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x288> */
/* @0x249604 ldr r3, [r8, #0x4] */
/* @0x249608 cmp r3, #0 */
/* @0x24960c beq 0x249834 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x2a4> */
/* @0x249610 add r0, r3, r1, lsl #4 */
/* @0x249614 vmov s12, r6 */
/* @0x249618 ldm r0, {r2, r3} */
/* @0x24961c vcvt.f64.s32 d7, s12 */
/* @0x249620 vmov d6, r2, r3 */
/* @0x249624 vcmpe.f64 d6, d7 */
/* @0x249628 vmrs APSR_nzcv, fpscr */
/* @0x24962c bgt 0x2496e8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x158> */
/* @0x249630 mov r11, #0 */
/* @0x249634 mov r0, r5 */
/* @0x249638 mov r3, #0 */
/* @0x24963c str r3, [sp, #0x20] */
/* @0x249640 str r3, [sp, #0x1c] */
/* @0x249644 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x249648 ldr r3, [sp, #0x1c] */
/* @0x24964c ldr r2, [r0, #0x78] */
/* @0x249650 tst r2, #1 */
/* @0x249654 bne 0x2497fc <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x26c> */
/* @0x249658 ldr r3, [pc, #0x1ec] */
/* @0x24965c ldr r8, [r4, r3] */
/* @0x249660 ldrb r3, [r8] */
/* @0x249664 cmp r3, #0 */
/* @0x249668 bne 0x2497e0 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x250> */
/* @0x24966c ldr r12, [sp, #0x58] */
/* @0x249670 mov r3, r9 */
/* @0x249674 ldr lr, [sp, #0x20] */
/* @0x249678 mov r1, r7 */
/* @0x24967c ldr r0, [r5, #0x8] */
/* @0x249680 mov r2, r7 */
/* @0x249684 str r12, [sp, #0x8] */
/* @0x249688 mov r12, #0 */
/* @0x24968c str r10, [sp] */
/* @0x249690 str r6, [sp, #0x4] */
/* @0x249694 str lr, [sp, #0x10] */
/* @0x249698 str r12, [sp, #0xc] */
/* @0x24969c bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_> */
/* @0x2496a0 ldrb r3, [r8] */
/* @0x2496a4 cmp r3, #0 */
/* @0x2496a8 bne 0x2497d0 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x240> */
/* @0x2496ac cmp r11, #0 */
/* @0x2496b0 bne 0x2497c4 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x234> */
/* @0x2496b4 mov r0, r5 */
/* @0x2496b8 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x2496bc ldr r3, [r0, #0x78] */
/* @0x2496c0 tst r3, #2 */
/* @0x2496c4 beq 0x2497a4 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x214> */
/* @0x2496c8 ldr r3, [pc, #0x180] */
/* @0x2496cc ldr r3, [r4, r3] */
/* @0x2496d0 ldrb r0, [r3] */
/* @0x2496d4 cmp r0, #0 */
/* @0x2496d8 movne r0, #2 */
/* @0x2496dc moveq r0, #0 */
/* @0x2496e0 add sp, sp, #52 */
/* @0x2496e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2496e8 vcvt.s32.f64 s13, d6 */
/* @0x2496ec vmov r12, s13 */
/* @0x2496f0 cmp r6, r12 */
/* @0x2496f4 bge 0x249630 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xa0> */
/* @0x2496f8 lsl r11, r12, #4 */
/* @0x2496fc ldr r1, [pc, #0x150] */
/* @0x249700 lsl r6, r6, #4 */
/* @0x249704 mov r3, #1 */
/* @0x249708 add r1, pc, r1 */
/* @0x24970c mov r2, #70 */
/* @0x249710 mov r0, r11 */
/* @0x249714 vstr s13, [sp, #28] */
/* @0x249718 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x24971c mov r2, r6 */
/* @0x249720 ldr r1, [sp, #0x58] */
/* @0x249724 bl 0xb65bc <memcpy@plt> */
/* @0x249728 ldr r12, [sp, #0x1c] */
/* @0x24972c mov r2, #0 */
/* @0x249730 mov r1, #5 */
/* @0x249734 add r6, r0, r6 */
/* @0x249738 add r11, r0, r11 */
/* @0x24973c mov r3, r0 */
/* @0x249740 str r2, [r6] */
/* @0x249744 add r6, r6, #16 */
/* @0x249748 str r2, [r6, #-0xc] */
/* @0x24974c str r2, [r6, #-0x8] */
/* @0x249750 str r1, [r6, #-0x4] */
/* @0x249754 cmp r6, r11 */
/* @0x249758 bne 0x249740 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x1b0> */
/* @0x24975c str r3, [sp, #0x58] */
/* @0x249760 mov r6, r12 */
/* @0x249764 mov r11, #1 */
/* @0x249768 b 0x249634 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xa4> */
/* @0x24976c ldr r5, [r8, #0x68] */
/* @0x249770 cmp r5, #0 */
/* @0x249774 beq 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138> */
/* @0x249778 mov r0, r7 */
/* @0x24977c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x249780 ldr r12, [sp, #0x58] */
/* @0x249784 mov r1, r7 */
/* @0x249788 mov r0, r9 */
/* @0x24978c mov r3, r6 */
/* @0x249790 mov r2, r7 */
/* @0x249794 str r12, [sp] */
/* @0x249798 blx r5 */
/* @0x24979c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x2497a0 b 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138> */
/* @0x2497a4 mov r0, r5 */
/* @0x2497a8 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0x2497ac ldr r3, [r0, #0x78] */
/* @0x2497b0 tst r3, #1 */
/* @0x2497b4 bne 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138> */
/* @0x2497b8 mov r0, r10 */
/* @0x2497bc bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0x2497c0 b 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138> */
/* @0x2497c4 ldr r0, [sp, #0x58] */
/* @0x2497c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2497cc b 0x2496b4 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x124> */
/* @0x2497d0 ldr r3, [pc, #0x80] */
/* @0x2497d4 ldr r0, [r4, r3] */
/* @0x2497d8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x2497dc b 0x2496ac <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x11c> */
/* @0x2497e0 ldr r2, [pc, #0x70] */
/* @0x2497e4 mov r1, #1 */
/* @0x2497e8 ldr r3, [r5, #0x8] */
/* @0x2497ec ldr r0, [r4, r2] */
/* @0x2497f0 ldr r2, [r3, #0x60] */
/* @0x2497f4 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x2497f8 b 0x24966c <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xdc> */
/* @0x2497fc str r3, [sp] */
/* @0x249800 mov r1, r8 */
/* @0x249804 add r0, sp, #32 */
/* @0x249808 mov r2, r6 */
/* @0x24980c ldr r3, [sp, #0x58] */
/* @0x249810 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b> */
/* @0x249814 b 0x249658 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xc8> */
/* @0x249818 ldr r1, [pc, #0x3c] */
/* @0x24981c mov r0, r8 */
/* @0x249820 add r1, pc, r1 */
/* @0x249824 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x249828 mov r1, r0 */
/* @0x24982c str r0, [r11] */
/* @0x249830 b 0x249604 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x74> */
/* @0x249834 mov r0, r8 */
/* @0x249838 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24983c b 0x249614 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x84> */
/* @0x249840 mulseq r10, r0, r6 */
/* @0x249844 .word 0xffffc104 */
/* @0x249848 .word 0xffffc05c */
/* @0x24984c .word 0xffffbf18 */
/* @0x249850 .word 0xffffc0cc */
/* @0x249854 andeq r7, lr, r8, lsr #18 */
/* @0x249858 .word 0xffffbf1c */
/* @0x24985c andeq r7, lr, r12, asr #32 */

/* ── FUNC 0x249860 · Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) · size=56 · insn=14 */
/* @0x249860 ldr r12, [r2, #0xc] */
/* @0x249864 str r4, [sp, #-0x4]! */
/* @0x249868 bic r12, r12, #-16777216 */
/* @0x24986c cmp r12, #6 */
/* @0x249870 beq 0x249880 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_+0x20> */
/* @0x249874 mov r0, #1 */
/* @0x249878 ldr r4, [sp], #4 */
/* @0x24987c bx lr */
/* @0x249880 ldr r2, [r2] */
/* @0x249884 ldr r12, [r2, #0x48] */
/* @0x249888 cmp r12, #3 */
/* @0x24988c bne 0x249874 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_+0x14> */
/* @0x249890 ldr r4, [sp], #4 */
/* @0x249894 b 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_> */

/* ── FUNC 0x249898 · JS_Array_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x249898 push {r4, r5, r6, r7, r8, lr} */
/* @0x24989c sub sp, sp, #24 */
/* @0x2498a0 add r4, sp, #8 */
/* @0x2498a4 mov r7, r2 */
/* @0x2498a8 ldr r2, [pc, #0x74] */
/* @0x2498ac mov r5, r1 */
/* @0x2498b0 mov r6, r0 */
/* @0x2498b4 mov r0, r1 */
/* @0x2498b8 add r2, pc, r2 */
/* @0x2498bc mov r1, r4 */
/* @0x2498c0 mov r12, #5 */
/* @0x2498c4 mov r8, r3 */
/* @0x2498c8 str r12, [sp, #0x14] */
/* @0x2498cc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2498d0 mov r0, r4 */
/* @0x2498d4 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x2498d8 cmp r0, #0 */
/* @0x2498dc bne 0x249904 <_Z27JS_Array_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x2498e0 ldr r3, [sp, #0x30] */
/* @0x2498e4 mov r0, r6 */
/* @0x2498e8 mov r1, r5 */
/* @0x2498ec mov r2, r7 */
/* @0x2498f0 str r3, [sp] */
/* @0x2498f4 mov r3, r8 */
/* @0x2498f8 bl 0x23cb44 <_Z30F_JS_Object_prototype_toStringR6RValueP9CInstanceS2_iPS_> */
/* @0x2498fc add sp, sp, #24 */
/* @0x249900 pop {r4, r5, r6, r7, r8, pc} */
/* @0x249904 mov r3, #0 */
/* @0x249908 mov r0, r5 */
/* @0x24990c mov r1, r6 */
/* @0x249910 mov r2, r4 */
/* @0x249914 str r3, [sp] */
/* @0x249918 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x24991c add sp, sp, #24 */
/* @0x249920 pop {r4, r5, r6, r7, r8, pc} */
/* @0x249924 andseq r11, r0, r12, lsl #31 */

/* ── FUNC 0x249928 · SortCompareProvided(RValue*, RValue*, RValue*) · size=164 · insn=41 */
/* @0x249928 push {r4, r5, r6, lr} */
/* @0x24992c mov r3, r1 */
/* @0x249930 sub sp, sp, #56 */
/* @0x249934 mov r4, r2 */
/* @0x249938 add r5, sp, #24 */
/* @0x24993c ldr r2, [r3, #0x8] */
/* @0x249940 mov r6, r0 */
/* @0x249944 ldr r3, [r3, #0xc] */
/* @0x249948 ldr r0, [r1] */
/* @0x24994c mov lr, r5 */
/* @0x249950 ldr r1, [r1, #0x4] */
/* @0x249954 add r12, sp, #40 */
/* @0x249958 str r5, [sp] */
/* @0x24995c mov r5, #5 */
/* @0x249960 str r5, [sp, #0x14] */
/* @0x249964 stm lr!, {r0, r1, r2, r3} */
/* @0x249968 ldr r0, [r4] */
/* @0x24996c ldr r1, [r4, #0x4] */
/* @0x249970 ldr r2, [r4, #0x8] */
/* @0x249974 ldr r3, [r4, #0xc] */
/* @0x249978 stm r12!, {r0, r1, r2, r3} */
/* @0x24997c mov r2, r6 */
/* @0x249980 mov r0, #0 */
/* @0x249984 add r1, sp, #8 */
/* @0x249988 mov r3, #2 */
/* @0x24998c bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x249990 cmp r0, #0 */
/* @0x249994 bne 0x2499c0 <_Z19SortCompareProvidedP6RValueS0_S0_+0x98> */
/* @0x249998 vldr d7, [sp, #8] */
/* @0x24999c vcvt.s32.f64 s14, d7 */
/* @0x2499a0 vmov r3, s14 */
/* @0x2499a4 cmp r3, #0 */
/* @0x2499a8 mvnlt r0, #0 */
/* @0x2499ac blt 0x2499b8 <_Z19SortCompareProvidedP6RValueS0_S0_+0x90> */
/* @0x2499b0 moveq r0, #0 */
/* @0x2499b4 movne r0, #1 */
/* @0x2499b8 add sp, sp, #56 */
/* @0x2499bc pop {r4, r5, r6, pc} */
/* @0x2499c0 bl 0x242ebc <_Z9translate9EJSRetVal> */
/* @0x2499c4 add sp, sp, #56 */
/* @0x2499c8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2499cc · JS_Argument_Put(YYObjectBase*, RValue*, char const*) · size=784 · insn=196 */
/* @0x2499cc push {r3, r4, r5, r6, r7, lr} */
/* @0x2499d0 mov r7, r2 */
/* @0x2499d4 mov r5, r1 */
/* @0x2499d8 mov r6, r0 */
/* @0x2499dc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x2499e0 ldr r3, [pc, #0x2f0] */
/* @0x2499e4 mov r12, r7 */
/* @0x2499e8 ldr r3, [pc, r3] */
/* @0x2499ec ldr r4, [r3] */
/* @0x2499f0 ldrb r3, [r12], #1 */
/* @0x2499f4 cmp r3, #0 */
/* @0x2499f8 add lr, r4, r3 */
/* @0x2499fc bne 0x249aec <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x120> */
/* @0x249a00 mov r0, r7 */
/* @0x249a04 bl 0xb66c4 <atol@plt> */
/* @0x249a08 ldr r3, [r6, #0x4] */
/* @0x249a0c cmp r3, #0 */
/* @0x249a10 mov r4, r0 */
/* @0x249a14 beq 0x249c0c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x240> */
/* @0x249a18 add r0, r3, #16 */
/* @0x249a1c ldr r0, [r0] */
/* @0x249a20 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x249a24 ldr r3, [r6, #0x4] */
/* @0x249a28 cmp r3, #0 */
/* @0x249a2c beq 0x249c60 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x294> */
/* @0x249a30 add r0, r3, #16 */
/* @0x249a34 ldr r0, [r0] */
/* @0x249a38 ldr r3, [r0, #0x4] */
/* @0x249a3c cmp r3, #0 */
/* @0x249a40 beq 0x249c70 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x2a4> */
/* @0x249a44 add r4, r3, r4, lsl #4 */
/* @0x249a48 ldr r2, [r4, #0xc] */
/* @0x249a4c bic r3, r2, #-16777216 */
/* @0x249a50 cmp r3, #1 */
/* @0x249a54 beq 0x249ba0 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1d4> */
/* @0x249a58 cmp r3, #2 */
/* @0x249a5c bne 0x249a84 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xb8> */
/* @0x249a60 sub r3, r2, #1 */
/* @0x249a64 bic r3, r3, #-16777216 */
/* @0x249a68 bic r3, r3, #3 */
/* @0x249a6c cmp r3, #0 */
/* @0x249a70 beq 0x249c54 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x288> */
/* @0x249a74 mov r2, #0 */
/* @0x249a78 mov r3, #5 */
/* @0x249a7c str r2, [r4, #0x8] */
/* @0x249a80 str r3, [r4, #0xc] */
/* @0x249a84 ldr r3, [r5, #0xc] */
/* @0x249a88 mov r1, #0 */
/* @0x249a8c ldr r2, [r5, #0x8] */
/* @0x249a90 str r1, [r4] */
/* @0x249a94 str r3, [r4, #0xc] */
/* @0x249a98 ldr r3, [r5, #0xc] */
/* @0x249a9c str r2, [r4, #0x8] */
/* @0x249aa0 bic r3, r3, #-16777216 */
/* @0x249aa4 cmp r3, #14 */
/* @0x249aa8 addls pc, pc, r3, lsl #2 */
/* @0x249aac b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ab0 b 0x249b28 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x15c> */
/* @0x249ab4 b 0x249b88 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1bc> */
/* @0x249ab8 b 0x249b5c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x190> */
/* @0x249abc b 0x249b14 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x148> */
/* @0x249ac0 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ac4 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ac8 b 0x249b38 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x16c> */
/* @0x249acc b 0x249b14 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x148> */
/* @0x249ad0 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ad4 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ad8 b 0x249b28 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x15c> */
/* @0x249adc b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ae0 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249ae4 b 0x249b28 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x15c> */
/* @0x249ae8 b 0x249b14 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x148> */
/* @0x249aec ldrb r3, [lr, #0x1] */
/* @0x249af0 and r3, r3, #4 */
/* @0x249af4 ands r3, r3, #255 */
/* @0x249af8 bne 0x2499f0 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x24> */
/* @0x249afc mov r0, r6 */
/* @0x249b00 mov r1, r7 */
/* @0x249b04 mov r2, r5 */
/* @0x249b08 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x249b0c pop {r3, r4, r5, r6, r7, lr} */
/* @0x249b10 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x249b14 ldr r3, [r5] */
/* @0x249b18 str r3, [r4] */
/* @0x249b1c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x249b20 pop {r3, r4, r5, r6, r7, lr} */
/* @0x249b24 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x249b28 ldm r5, {r2, r3} */
/* @0x249b2c stm r4, {r2, r3} */
/* @0x249b30 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x249b34 b 0x249b20 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x154> */
/* @0x249b38 ldr r3, [r5] */
/* @0x249b3c str r3, [r4] */
/* @0x249b40 ldr r3, [r5] */
/* @0x249b44 cmp r3, #0 */
/* @0x249b48 beq 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249b4c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x249b50 ldr r1, [r5] */
/* @0x249b54 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x249b58 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249b5c ldr r3, [r5] */
/* @0x249b60 cmp r3, #0 */
/* @0x249b64 str r3, [r4] */
/* @0x249b68 beq 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249b6c ldr r1, [r3, #0x8] */
/* @0x249b70 ldr r2, [r3] */
/* @0x249b74 cmp r1, #0 */
/* @0x249b78 streq r4, [r3, #0x8] */
/* @0x249b7c add r2, r2, #1 */
/* @0x249b80 str r2, [r3] */
/* @0x249b84 b 0x249b1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x150> */
/* @0x249b88 ldr r3, [r5] */
/* @0x249b8c cmp r3, #0 */
/* @0x249b90 ldrne r2, [r3, #0x4] */
/* @0x249b94 addne r2, r2, #1 */
/* @0x249b98 strne r2, [r3, #0x4] */
/* @0x249b9c b 0x249b18 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x14c> */
/* @0x249ba0 ldr r6, [r4] */
/* @0x249ba4 cmp r6, #0 */
/* @0x249ba8 beq 0x249bc8 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1fc> */
/* @0x249bac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x249bb0 ldr r7, [r6, #0x4] */
/* @0x249bb4 sub r7, r7, #1 */
/* @0x249bb8 str r7, [r6, #0x4] */
/* @0x249bbc cmp r7, #0 */
/* @0x249bc0 beq 0x249bd4 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x208> */
/* @0x249bc4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x249bc8 mov r3, #0 */
/* @0x249bcc str r3, [r4] */
/* @0x249bd0 b 0x249a84 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xb8> */
/* @0x249bd4 ldr r0, [r6] */
/* @0x249bd8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x249bdc str r7, [r6] */
/* @0x249be0 str r7, [r6, #0x8] */
/* @0x249be4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x249be8 ldr r7, [r6, #0x4] */
/* @0x249bec sub r7, r7, #1 */
/* @0x249bf0 str r7, [r6, #0x4] */
/* @0x249bf4 cmp r7, #0 */
/* @0x249bf8 beq 0x249c1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x250> */
/* @0x249bfc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x249c00 mov r0, r6 */
/* @0x249c04 bl 0x27d1d0 <_ZdlPv> */
/* @0x249c08 b 0x249bc4 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x1f8> */
/* @0x249c0c mov r0, r6 */
/* @0x249c10 mov r1, #1 */
/* @0x249c14 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x249c18 b 0x249a1c <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x50> */
/* @0x249c1c ldr r0, [r6] */
/* @0x249c20 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x249c24 str r7, [r6] */
/* @0x249c28 str r7, [r6, #0x8] */
/* @0x249c2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x249c30 ldr r7, [r6, #0x4] */
/* @0x249c34 sub r7, r7, #1 */
/* @0x249c38 str r7, [r6, #0x4] */
/* @0x249c3c cmp r7, #0 */
/* @0x249c40 beq 0x249c80 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x2b4> */
/* @0x249c44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x249c48 mov r0, r6 */
/* @0x249c4c bl 0x27d1d0 <_ZdlPv> */
/* @0x249c50 b 0x249bfc <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x230> */
/* @0x249c54 mov r0, r4 */
/* @0x249c58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x249c5c b 0x249a74 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xa8> */
/* @0x249c60 mov r0, r6 */
/* @0x249c64 mov r1, #1 */
/* @0x249c68 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x249c6c b 0x249a34 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x68> */
/* @0x249c70 mov r1, r4 */
/* @0x249c74 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x249c78 mov r4, r0 */
/* @0x249c7c b 0x249a48 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x7c> */
/* @0x249c80 ldr r0, [r6] */
/* @0x249c84 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x249c88 str r7, [r6] */
/* @0x249c8c str r7, [r6, #0x8] */
/* @0x249c90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x249c94 ldr r7, [r6, #0x4] */
/* @0x249c98 sub r7, r7, #1 */
/* @0x249c9c str r7, [r6, #0x4] */
/* @0x249ca0 cmp r7, #0 */
/* @0x249ca4 bne 0x249cc8 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x2fc> */
/* @0x249ca8 ldr r0, [r6] */
/* @0x249cac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x249cb0 mov r0, r6 */
/* @0x249cb4 str r7, [r6] */
/* @0x249cb8 str r7, [r6, #0x8] */
/* @0x249cbc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x249cc0 mov r0, r6 */
/* @0x249cc4 bl 0x27d1d0 <_ZdlPv> */
/* @0x249cc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x249ccc mov r0, r6 */
/* @0x249cd0 bl 0x27d1d0 <_ZdlPv> */
/* @0x249cd4 b 0x249c44 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0x278> */
/* @0x249cd8 mulseq r10, r8, pc */

/* ── FUNC 0x249cdc · JSArrayGet(RValue*, RValue*, RValue*) · size=1164 · insn=291 */
/* @0x249cdc cmp r0, #0 */
/* @0x249ce0 push {r4, r5, r6, r7, r8, lr} */
/* @0x249ce4 mov r7, r1 */
/* @0x249ce8 mov r6, r2 */
/* @0x249cec beq 0x249cfc <_Z10JSArrayGetP6RValueS0_S0_+0x20> */
/* @0x249cf0 ldr r3, [r0, #0xc] */
/* @0x249cf4 cmp r3, #6 */
/* @0x249cf8 beq 0x249d04 <_Z10JSArrayGetP6RValueS0_S0_+0x28> */
/* @0x249cfc mov r0, #0 */
/* @0x249d00 pop {r4, r5, r6, r7, r8, pc} */
/* @0x249d04 ldr r4, [r0] */
/* @0x249d08 ldr r1, [pc, #0x454] */
/* @0x249d0c ldr r0, [r4, #0x40] */
/* @0x249d10 add r1, pc, r1 */
/* @0x249d14 bl 0xb6574 <strcmp@plt> */
/* @0x249d18 cmp r0, #0 */
/* @0x249d1c bne 0x249e34 <_Z10JSArrayGetP6RValueS0_S0_+0x158> */
/* @0x249d20 ldr r3, [r4, #0x4] */
/* @0x249d24 cmp r3, #0 */
/* @0x249d28 beq 0x24a0e0 <_Z10JSArrayGetP6RValueS0_S0_+0x404> */
/* @0x249d2c add r0, r3, #16 */
/* @0x249d30 ldr r2, [r7, #0xc] */
/* @0x249d34 ldr r8, [r0] */
/* @0x249d38 cmp r2, #5 */
/* @0x249d3c streq r2, [r6, #0xc] */
/* @0x249d40 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249d44 mov r1, #0 */
/* @0x249d48 mov r0, r7 */
/* @0x249d4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x249d50 ldr r3, [r7, #0xc] */
/* @0x249d54 cmp r3, #0 */
/* @0x249d58 ldr r3, [r8, #0x24] */
/* @0x249d5c ldmeq r7, {r4, r5} */
/* @0x249d60 vmoveq d7, r4, r5 */
/* @0x249d64 vcvteq.s32.f64 s15, d7 */
/* @0x249d68 movne r1, r0 */
/* @0x249d6c vmoveq r1, s15 */
/* @0x249d70 cmp r1, r3 */
/* @0x249d74 movhs r3, #5 */
/* @0x249d78 strhs r3, [r6, #0xc] */
/* @0x249d7c bhs 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249d80 ldr r3, [r8, #0x4] */
/* @0x249d84 cmp r3, #0 */
/* @0x249d88 beq 0x24a154 <_Z10JSArrayGetP6RValueS0_S0_+0x478> */
/* @0x249d8c add r4, r3, r1, lsl #4 */
/* @0x249d90 ldr r2, [r6, #0xc] */
/* @0x249d94 bic r3, r2, #-16777216 */
/* @0x249d98 cmp r3, #1 */
/* @0x249d9c beq 0x24a048 <_Z10JSArrayGetP6RValueS0_S0_+0x36c> */
/* @0x249da0 cmp r3, #2 */
/* @0x249da4 bne 0x249dcc <_Z10JSArrayGetP6RValueS0_S0_+0xf0> */
/* @0x249da8 sub r3, r2, #1 */
/* @0x249dac bic r3, r3, #-16777216 */
/* @0x249db0 bic r3, r3, #3 */
/* @0x249db4 cmp r3, #0 */
/* @0x249db8 beq 0x24a148 <_Z10JSArrayGetP6RValueS0_S0_+0x46c> */
/* @0x249dbc mov r2, #0 */
/* @0x249dc0 mov r3, #5 */
/* @0x249dc4 str r2, [r6, #0x8] */
/* @0x249dc8 str r3, [r6, #0xc] */
/* @0x249dcc ldr r3, [r4, #0xc] */
/* @0x249dd0 mov r1, #0 */
/* @0x249dd4 ldr r2, [r4, #0x8] */
/* @0x249dd8 str r1, [r6] */
/* @0x249ddc str r3, [r6, #0xc] */
/* @0x249de0 ldr r3, [r4, #0xc] */
/* @0x249de4 str r2, [r6, #0x8] */
/* @0x249de8 bic r3, r3, #-16777216 */
/* @0x249dec cmp r3, #14 */
/* @0x249df0 addls pc, pc, r3, lsl #2 */
/* @0x249df4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249df8 b 0x249fa0 <_Z10JSArrayGetP6RValueS0_S0_+0x2c4> */
/* @0x249dfc b 0x249ffc <_Z10JSArrayGetP6RValueS0_S0_+0x320> */
/* @0x249e00 b 0x249fac <_Z10JSArrayGetP6RValueS0_S0_+0x2d0> */
/* @0x249e04 b 0x249ef0 <_Z10JSArrayGetP6RValueS0_S0_+0x214> */
/* @0x249e08 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249e0c b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249e10 b 0x249fd8 <_Z10JSArrayGetP6RValueS0_S0_+0x2fc> */
/* @0x249e14 b 0x249ef0 <_Z10JSArrayGetP6RValueS0_S0_+0x214> */
/* @0x249e18 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249e1c b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249e20 b 0x249fa0 <_Z10JSArrayGetP6RValueS0_S0_+0x2c4> */
/* @0x249e24 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249e28 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249e2c b 0x249fa0 <_Z10JSArrayGetP6RValueS0_S0_+0x2c4> */
/* @0x249e30 b 0x249ef0 <_Z10JSArrayGetP6RValueS0_S0_+0x214> */
/* @0x249e34 ldr r3, [r7] */
/* @0x249e38 mov r0, r4 */
/* @0x249e3c ldr r1, [r3] */
/* @0x249e40 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x249e44 subs r4, r0, #0 */
/* @0x249e48 beq 0x249cfc <_Z10JSArrayGetP6RValueS0_S0_+0x20> */
/* @0x249e4c ldr r2, [r6, #0xc] */
/* @0x249e50 bic r3, r2, #-16777216 */
/* @0x249e54 cmp r3, #1 */
/* @0x249e58 beq 0x24a014 <_Z10JSArrayGetP6RValueS0_S0_+0x338> */
/* @0x249e5c cmp r3, #2 */
/* @0x249e60 bne 0x249e88 <_Z10JSArrayGetP6RValueS0_S0_+0x1ac> */
/* @0x249e64 sub r3, r2, #1 */
/* @0x249e68 bic r3, r3, #-16777216 */
/* @0x249e6c bic r3, r3, #3 */
/* @0x249e70 cmp r3, #0 */
/* @0x249e74 beq 0x24a0d4 <_Z10JSArrayGetP6RValueS0_S0_+0x3f8> */
/* @0x249e78 mov r2, #0 */
/* @0x249e7c mov r3, #5 */
/* @0x249e80 str r2, [r6, #0x8] */
/* @0x249e84 str r3, [r6, #0xc] */
/* @0x249e88 ldr r3, [r4, #0xc] */
/* @0x249e8c mov r1, #0 */
/* @0x249e90 ldr r2, [r4, #0x8] */
/* @0x249e94 str r1, [r6] */
/* @0x249e98 str r3, [r6, #0xc] */
/* @0x249e9c ldr r3, [r4, #0xc] */
/* @0x249ea0 str r2, [r6, #0x8] */
/* @0x249ea4 bic r3, r3, #-16777216 */
/* @0x249ea8 cmp r3, #14 */
/* @0x249eac addls pc, pc, r3, lsl #2 */
/* @0x249eb0 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249eb4 b 0x249f10 <_Z10JSArrayGetP6RValueS0_S0_+0x234> */
/* @0x249eb8 b 0x249f4c <_Z10JSArrayGetP6RValueS0_S0_+0x270> */
/* @0x249ebc b 0x249f6c <_Z10JSArrayGetP6RValueS0_S0_+0x290> */
/* @0x249ec0 b 0x249f00 <_Z10JSArrayGetP6RValueS0_S0_+0x224> */
/* @0x249ec4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249ec8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249ecc b 0x249f24 <_Z10JSArrayGetP6RValueS0_S0_+0x248> */
/* @0x249ed0 b 0x249f00 <_Z10JSArrayGetP6RValueS0_S0_+0x224> */
/* @0x249ed4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249ed8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249edc b 0x249f10 <_Z10JSArrayGetP6RValueS0_S0_+0x234> */
/* @0x249ee0 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249ee4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249ee8 b 0x249f10 <_Z10JSArrayGetP6RValueS0_S0_+0x234> */
/* @0x249eec b 0x249f00 <_Z10JSArrayGetP6RValueS0_S0_+0x224> */
/* @0x249ef0 ldr r3, [r4] */
/* @0x249ef4 str r3, [r6] */
/* @0x249ef8 mov r0, #1 */
/* @0x249efc pop {r4, r5, r6, r7, r8, pc} */
/* @0x249f00 ldr r3, [r4] */
/* @0x249f04 mov r0, #1 */
/* @0x249f08 str r3, [r6] */
/* @0x249f0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x249f10 ldr r2, [r4] */
/* @0x249f14 mov r0, #1 */
/* @0x249f18 ldr r3, [r4, #0x4] */
/* @0x249f1c stm r6, {r2, r3} */
/* @0x249f20 pop {r4, r5, r6, r7, r8, pc} */
/* @0x249f24 ldr r3, [r4] */
/* @0x249f28 str r3, [r6] */
/* @0x249f2c ldr r3, [r4] */
/* @0x249f30 cmp r3, #0 */
/* @0x249f34 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249f38 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x249f3c ldr r1, [r4] */
/* @0x249f40 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x249f44 mov r0, #1 */
/* @0x249f48 pop {r4, r5, r6, r7, r8, pc} */
/* @0x249f4c ldr r3, [r4] */
/* @0x249f50 mov r0, #1 */
/* @0x249f54 cmp r3, #0 */
/* @0x249f58 ldrne r2, [r3, #0x4] */
/* @0x249f5c addne r2, r2, #1 */
/* @0x249f60 strne r2, [r3, #0x4] */
/* @0x249f64 str r3, [r6] */
/* @0x249f68 pop {r4, r5, r6, r7, r8, pc} */
/* @0x249f6c ldr r3, [r4] */
/* @0x249f70 cmp r3, #0 */
/* @0x249f74 str r3, [r6] */
/* @0x249f78 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249f7c ldr r1, [r3, #0x8] */
/* @0x249f80 ldr r2, [r3] */
/* @0x249f84 cmp r1, #0 */
/* @0x249f88 add r2, r2, #1 */
/* @0x249f8c str r2, [r3] */
/* @0x249f90 bne 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249f94 str r6, [r3, #0x8] */
/* @0x249f98 mov r0, #1 */
/* @0x249f9c pop {r4, r5, r6, r7, r8, pc} */
/* @0x249fa0 ldm r4, {r2, r3} */
/* @0x249fa4 stm r6, {r2, r3} */
/* @0x249fa8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249fac ldr r3, [r4] */
/* @0x249fb0 cmp r3, #0 */
/* @0x249fb4 str r3, [r6] */
/* @0x249fb8 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249fbc ldr r1, [r3, #0x8] */
/* @0x249fc0 ldr r2, [r3] */
/* @0x249fc4 cmp r1, #0 */
/* @0x249fc8 streq r6, [r3, #0x8] */
/* @0x249fcc add r2, r2, #1 */
/* @0x249fd0 str r2, [r3] */
/* @0x249fd4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249fd8 ldr r3, [r4] */
/* @0x249fdc str r3, [r6] */
/* @0x249fe0 ldr r3, [r4] */
/* @0x249fe4 cmp r3, #0 */
/* @0x249fe8 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249fec bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x249ff0 ldr r1, [r4] */
/* @0x249ff4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x249ff8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c> */
/* @0x249ffc ldr r3, [r4] */
/* @0x24a000 cmp r3, #0 */
/* @0x24a004 ldrne r2, [r3, #0x4] */
/* @0x24a008 addne r2, r2, #1 */
/* @0x24a00c strne r2, [r3, #0x4] */
/* @0x24a010 b 0x249ef4 <_Z10JSArrayGetP6RValueS0_S0_+0x218> */
/* @0x24a014 ldr r5, [r6] */
/* @0x24a018 cmp r5, #0 */
/* @0x24a01c beq 0x24a03c <_Z10JSArrayGetP6RValueS0_S0_+0x360> */
/* @0x24a020 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24a024 ldr r7, [r5, #0x4] */
/* @0x24a028 sub r7, r7, #1 */
/* @0x24a02c str r7, [r5, #0x4] */
/* @0x24a030 cmp r7, #0 */
/* @0x24a034 beq 0x24a07c <_Z10JSArrayGetP6RValueS0_S0_+0x3a0> */
/* @0x24a038 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24a03c mov r3, #0 */
/* @0x24a040 str r3, [r6] */
/* @0x24a044 b 0x249e88 <_Z10JSArrayGetP6RValueS0_S0_+0x1ac> */
/* @0x24a048 ldr r5, [r6] */
/* @0x24a04c cmp r5, #0 */
/* @0x24a050 beq 0x24a070 <_Z10JSArrayGetP6RValueS0_S0_+0x394> */
/* @0x24a054 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24a058 ldr r7, [r5, #0x4] */
/* @0x24a05c sub r7, r7, #1 */
/* @0x24a060 str r7, [r5, #0x4] */
/* @0x24a064 cmp r7, #0 */
/* @0x24a068 beq 0x24a0f0 <_Z10JSArrayGetP6RValueS0_S0_+0x414> */
/* @0x24a06c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24a070 mov r3, #0 */
/* @0x24a074 str r3, [r6] */
/* @0x24a078 b 0x249dcc <_Z10JSArrayGetP6RValueS0_S0_+0xf0> */
/* @0x24a07c ldr r0, [r5] */
/* @0x24a080 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a084 str r7, [r5] */
/* @0x24a088 str r7, [r5, #0x8] */
/* @0x24a08c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24a090 ldr r7, [r5, #0x4] */
/* @0x24a094 sub r7, r7, #1 */
/* @0x24a098 str r7, [r5, #0x4] */
/* @0x24a09c cmp r7, #0 */
/* @0x24a0a0 bne 0x24a0c4 <_Z10JSArrayGetP6RValueS0_S0_+0x3e8> */
/* @0x24a0a4 ldr r0, [r5] */
/* @0x24a0a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a0ac mov r0, r5 */
/* @0x24a0b0 str r7, [r5] */
/* @0x24a0b4 str r7, [r5, #0x8] */
/* @0x24a0b8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24a0bc mov r0, r5 */
/* @0x24a0c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x24a0c4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24a0c8 mov r0, r5 */
/* @0x24a0cc bl 0x27d1d0 <_ZdlPv> */
/* @0x24a0d0 b 0x24a038 <_Z10JSArrayGetP6RValueS0_S0_+0x35c> */
/* @0x24a0d4 mov r0, r6 */
/* @0x24a0d8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24a0dc b 0x249e78 <_Z10JSArrayGetP6RValueS0_S0_+0x19c> */
/* @0x24a0e0 mov r0, r4 */
/* @0x24a0e4 mov r1, #1 */
/* @0x24a0e8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24a0ec b 0x249d30 <_Z10JSArrayGetP6RValueS0_S0_+0x54> */
/* @0x24a0f0 ldr r0, [r5] */
/* @0x24a0f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a0f8 str r7, [r5] */
/* @0x24a0fc str r7, [r5, #0x8] */
/* @0x24a100 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24a104 ldr r7, [r5, #0x4] */
/* @0x24a108 sub r7, r7, #1 */
/* @0x24a10c str r7, [r5, #0x4] */
/* @0x24a110 cmp r7, #0 */
/* @0x24a114 bne 0x24a138 <_Z10JSArrayGetP6RValueS0_S0_+0x45c> */
/* @0x24a118 ldr r0, [r5] */
/* @0x24a11c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a120 mov r0, r5 */
/* @0x24a124 str r7, [r5] */
/* @0x24a128 str r7, [r5, #0x8] */
/* @0x24a12c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x24a130 mov r0, r5 */
/* @0x24a134 bl 0x27d1d0 <_ZdlPv> */
/* @0x24a138 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24a13c mov r0, r5 */
/* @0x24a140 bl 0x27d1d0 <_ZdlPv> */
/* @0x24a144 b 0x24a06c <_Z10JSArrayGetP6RValueS0_S0_+0x390> */
/* @0x24a148 mov r0, r6 */
/* @0x24a14c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24a150 b 0x249dbc <_Z10JSArrayGetP6RValueS0_S0_+0xe0> */
/* @0x24a154 mov r0, r8 */
/* @0x24a158 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24a15c mov r4, r0 */
/* @0x24a160 b 0x249d90 <_Z10JSArrayGetP6RValueS0_S0_+0xb4> */
/* @0x24a164 andeq r10, lr, r8, lsl #24 */

/* ── FUNC 0x24a168 · JS_Array_GetOwnProperty(YYObjectBase*, RValue*, char const*) · size=148 · insn=37 */
/* @0x24a168 ldr r12, [pc, #0x88] */
/* @0x24a16c mov r3, r2 */
/* @0x24a170 push {r4, r5, r6, lr} */
/* @0x24a174 ldr r12, [pc, r12] */
/* @0x24a178 sub sp, sp, #32 */
/* @0x24a17c mov r5, r0 */
/* @0x24a180 ldr lr, [r12] */
/* @0x24a184 mov r6, r1 */
/* @0x24a188 ldrb r4, [r3], #1 */
/* @0x24a18c cmp r4, #0 */
/* @0x24a190 add r12, lr, r4 */
/* @0x24a194 bne 0x24a1d8 <_Z23JS_Array_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x70> */
/* @0x24a198 mov r0, r2 */
/* @0x24a19c bl 0xb66c4 <atol@plt> */
/* @0x24a1a0 add r3, sp, #32 */
/* @0x24a1a4 mov r2, r6 */
/* @0x24a1a8 mov r1, sp */
/* @0x24a1ac str r5, [r3, #-0x10]! */
/* @0x24a1b0 mov r12, #6 */
/* @0x24a1b4 str r4, [sp, #0xc] */
/* @0x24a1b8 str r12, [sp, #0x1c] */
/* @0x24a1bc vmov s13, r0 */
/* @0x24a1c0 mov r0, r3 */
/* @0x24a1c4 vcvt.f64.s32 d7, s13 */
/* @0x24a1c8 vstr d7, [sp] */
/* @0x24a1cc bl 0x249cdc <_Z10JSArrayGetP6RValueS0_S0_> */
/* @0x24a1d0 add sp, sp, #32 */
/* @0x24a1d4 pop {r4, r5, r6, pc} */
/* @0x24a1d8 ldrb r12, [r12, #0x1] */
/* @0x24a1dc tst r12, #4 */
/* @0x24a1e0 bne 0x24a188 <_Z23JS_Array_GetOwnPropertyP12YYObjectBaseP6RValuePKc+0x20> */
/* @0x24a1e4 mov r0, r5 */
/* @0x24a1e8 mov r1, r6 */
/* @0x24a1ec bl 0x23d0f0 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24a1f0 add sp, sp, #32 */
/* @0x24a1f4 pop {r4, r5, r6, pc} */
/* @0x24a1f8 andseq r3, r10, r12, lsl #16 */

/* ── FUNC 0x24a1fc · YYObject_PropertyNameIterator::Next(RValue*) · size=572 · insn=143 */
/* @0x24a1fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24a200 sub sp, sp, #60 */
/* @0x24a204 add r4, sp, #8 */
/* @0x24a208 mov r6, #0 */
/* @0x24a20c mov r7, #0 */
/* @0x24a210 mov r11, r0 */
/* @0x24a214 mov r10, r1 */
/* @0x24a218 mov r8, #0 */
/* @0x24a21c mvn r9, #-16777216 */
/* @0x24a220 add r3, sp, #24 */
/* @0x24a224 str r3, [sp, #0x4] */
/* @0x24a228 ldr r3, [r11, #0x4] */
/* @0x24a22c cmp r3, #2 */
/* @0x24a230 beq 0x24a34c <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x150> */
/* @0x24a234 mov r0, r11 */
/* @0x24a238 mov r1, r10 */
/* @0x24a23c mov r2, r4 */
/* @0x24a240 strd r6, r7, [sp, #8] */
/* @0x24a244 str r8, [sp, #0x10] */
/* @0x24a248 str r9, [sp, #0x14] */
/* @0x24a24c bl 0x240134 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_> */
/* @0x24a250 ldr r5, [r10, #0xc] */
/* @0x24a254 bic r3, r5, #-16777216 */
/* @0x24a258 cmp r3, #1 */
/* @0x24a25c bne 0x24a228 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x2c> */
/* @0x24a260 ldrb r2, [r11, #0x11] */
/* @0x24a264 ldr r3, [r10] */
/* @0x24a268 cmp r2, #0 */
/* @0x24a26c ldr r12, [r3] */
/* @0x24a270 bne 0x24a298 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x9c> */
/* @0x24a274 mov r0, r12 */
/* @0x24a278 str r12, [sp] */
/* @0x24a27c bl 0xb6538 <strlen@plt> */
/* @0x24a280 ldr r12, [sp] */
/* @0x24a284 cmp r0, #2 */
/* @0x24a288 bls 0x24a298 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x9c> */
/* @0x24a28c ldrb r3, [r12] */
/* @0x24a290 cmp r3, #91 */
/* @0x24a294 beq 0x24a380 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x184> */
/* @0x24a298 ldr r3, [r11, #0xc] */
/* @0x24a29c ldr r2, [sp, #0x10] */
/* @0x24a2a0 tst r3, r2 */
/* @0x24a2a4 movne r3, #0 */
/* @0x24a2a8 andeq r3, r3, #1 */
/* @0x24a2ac cmp r3, #0 */
/* @0x24a2b0 bne 0x24a38c <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x190> */
/* @0x24a2b4 ldr r2, [sp, #0x14] */
/* @0x24a2b8 cmp r2, r9 */
/* @0x24a2bc beq 0x24a38c <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x190> */
/* @0x24a2c0 ldr r0, [r11, #0x14] */
/* @0x24a2c4 cmp r0, #0 */
/* @0x24a2c8 beq 0x24a3c0 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1c4> */
/* @0x24a2cc mov r2, r12 */
/* @0x24a2d0 add r1, sp, #24 */
/* @0x24a2d4 str r3, [sp, #0x20] */
/* @0x24a2d8 str r3, [sp, #0x30] */
/* @0x24a2dc str r12, [sp] */
/* @0x24a2e0 strd r6, r7, [sp, #24] */
/* @0x24a2e4 str r9, [sp, #0x24] */
/* @0x24a2e8 strd r6, r7, [sp, #40] */
/* @0x24a2ec str r9, [sp, #0x34] */
/* @0x24a2f0 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24a2f4 ldr r12, [sp] */
/* @0x24a2f8 add r1, sp, #40 */
/* @0x24a2fc ldr r0, [r11] */
/* @0x24a300 mov r2, r12 */
/* @0x24a304 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24a308 ldr r2, [sp, #0x24] */
/* @0x24a30c ldr r3, [sp, #0x34] */
/* @0x24a310 cmp r2, r3 */
/* @0x24a314 beq 0x24a3ac <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1b0> */
/* @0x24a318 ldr r3, [r10, #0xc] */
/* @0x24a31c sub r3, r3, #1 */
/* @0x24a320 bic r3, r3, #-16777216 */
/* @0x24a324 bic r3, r3, #3 */
/* @0x24a328 cmp r3, #0 */
/* @0x24a32c beq 0x24a3a0 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1a4> */
/* @0x24a330 str r8, [r10] */
/* @0x24a334 mov r3, #5 */
/* @0x24a338 str r3, [r10, #0xc] */
/* @0x24a33c ldr r3, [r11, #0x4] */
/* @0x24a340 str r8, [r10, #0x8] */
/* @0x24a344 cmp r3, #2 */
/* @0x24a348 bne 0x24a234 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x38> */
/* @0x24a34c ldrb r0, [r11, #0x10] */
/* @0x24a350 cmp r0, #0 */
/* @0x24a354 beq 0x24a378 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x17c> */
/* @0x24a358 ldr r0, [r11, #0x18] */
/* @0x24a35c cmp r0, #0 */
/* @0x24a360 beq 0x24a3cc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1d0> */
/* @0x24a364 mov r1, r10 */
/* @0x24a368 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x24a36c subs r4, r0, #0 */
/* @0x24a370 beq 0x24a428 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x22c> */
/* @0x24a374 mov r0, r4 */
/* @0x24a378 add sp, sp, #60 */
/* @0x24a37c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24a380 ldrb r3, [r12, #0x1] */
/* @0x24a384 cmp r3, #91 */
/* @0x24a388 bne 0x24a298 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x9c> */
/* @0x24a38c sub r5, r5, #1 */
/* @0x24a390 bic r5, r5, #-16777216 */
/* @0x24a394 bic r5, r5, #3 */
/* @0x24a398 cmp r5, #0 */
/* @0x24a39c bne 0x24a330 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x134> */
/* @0x24a3a0 mov r0, r10 */
/* @0x24a3a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24a3a8 b 0x24a330 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x134> */
/* @0x24a3ac ldrd r0, r1, [sp, #24] */
/* @0x24a3b0 ldrd r2, r3, [sp, #40] */
/* @0x24a3b4 cmp r1, r3 */
/* @0x24a3b8 cmpeq r0, r2 */
/* @0x24a3bc bne 0x24a318 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x11c> */
/* @0x24a3c0 mov r0, #1 */
/* @0x24a3c4 add sp, sp, #60 */
/* @0x24a3c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24a3cc ldr r3, [r11] */
/* @0x24a3d0 ldr r5, [r3, #0x18] */
/* @0x24a3d4 cmp r5, #0 */
/* @0x24a3d8 moveq r0, r5 */
/* @0x24a3dc beq 0x24a378 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x17c> */
/* @0x24a3e0 mov r0, #28 */
/* @0x24a3e4 bl 0x27c524 <_Znwj> */
/* @0x24a3e8 mov r1, r5 */
/* @0x24a3ec ldr r2, [r11, #0xc] */
/* @0x24a3f0 mov r4, r0 */
/* @0x24a3f4 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x24a3f8 ldr r3, [r11, #0x14] */
/* @0x24a3fc mov r2, #1 */
/* @0x24a400 str r4, [r11, #0x18] */
/* @0x24a404 mov r0, r4 */
/* @0x24a408 cmp r3, #0 */
/* @0x24a40c strb r2, [r4, #0x10] */
/* @0x24a410 mov r1, r10 */
/* @0x24a414 ldreq r3, [r11] */
/* @0x24a418 str r3, [r4, #0x14] */
/* @0x24a41c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x24a420 subs r4, r0, #0 */
/* @0x24a424 bne 0x24a374 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x178> */
/* @0x24a428 ldr r0, [r11, #0x18] */
/* @0x24a42c bl 0x27d1d0 <_ZdlPv> */
/* @0x24a430 str r4, [r11, #0x18] */
/* @0x24a434 b 0x24a374 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x178> */

/* ── FUNC 0x24a438 · F_JSForInIteratorGetNext(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x24a438 push {r3, r4, r5, lr} */
/* @0x24a43c mov r4, r0 */
/* @0x24a440 ldr r5, [sp, #0x10] */
/* @0x24a444 ldr r3, [r5, #0xc] */
/* @0x24a448 bic r3, r3, #-16777216 */
/* @0x24a44c cmp r3, #14 */
/* @0x24a450 beq 0x24a460 <_Z24F_JSForInIteratorGetNextR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x24a454 ldr r0, [pc, #0x2c] */
/* @0x24a458 add r0, pc, r0 */
/* @0x24a45c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x24a460 ldr r0, [r5] */
/* @0x24a464 mov r1, r4 */
/* @0x24a468 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x24a46c cmp r0, #0 */
/* @0x24a470 streq r0, [r4] */
/* @0x24a474 streq r0, [r4, #0x4] */
/* @0x24a478 moveq r3, #5 */
/* @0x24a47c streq r0, [r4, #0x8] */
/* @0x24a480 streq r3, [r4, #0xc] */
/* @0x24a484 pop {r3, r4, r5, pc} */
/* @0x24a488 ldrsheq r10, [r0], -r12 */

/* ── FUNC 0x24a48c · ObjectBaseToString(YYObjectBase*) · size=900 · insn=225 */
/* @0x24a48c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24a490 sub sp, sp, #108 */
/* @0x24a494 add r6, sp, #76 */
/* @0x24a498 mov r1, r0 */
/* @0x24a49c mov r2, #0 */
/* @0x24a4a0 mov r8, r0 */
/* @0x24a4a4 mov r0, r6 */
/* @0x24a4a8 add r7, sp, #44 */
/* @0x24a4ac bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x24a4b0 mov r2, #1 */
/* @0x24a4b4 ldr r0, [pc, #0x34c] */
/* @0x24a4b8 mov r3, #0 */
/* @0x24a4bc strb r2, [sp, #0x5d] */
/* @0x24a4c0 mov r10, #5 */
/* @0x24a4c4 ldr r2, [pc, #0x340] */
/* @0x24a4c8 add r0, pc, r0 */
/* @0x24a4cc add r5, sp, #60 */
/* @0x24a4d0 str r3, [sp, #0x20] */
/* @0x24a4d4 add r2, pc, r2 */
/* @0x24a4d8 str r3, [sp, #0x24] */
/* @0x24a4dc str r3, [sp, #0x28] */
/* @0x24a4e0 str r0, [sp, #0x8] */
/* @0x24a4e4 str r2, [sp, #0xc] */
/* @0x24a4e8 b 0x24a7b8 <_Z18ObjectBaseToStringP12YYObjectBase+0x32c> */
/* @0x24a4ec ldr r3, [sp, #0x2c] */
/* @0x24a4f0 mov r0, r8 */
/* @0x24a4f4 mov r1, r5 */
/* @0x24a4f8 str r10, [sp, #0x48] */
/* @0x24a4fc ldr r2, [r3] */
/* @0x24a500 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24a504 ldr r3, [sp, #0x2c] */
/* @0x24a508 ldr r9, [r3] */
/* @0x24a50c cmp r9, #0 */
/* @0x24a510 ldreq r4, [sp, #0x28] */
/* @0x24a514 beq 0x24a5c0 <_Z18ObjectBaseToStringP12YYObjectBase+0x134> */
/* @0x24a518 mov r0, r9 */
/* @0x24a51c bl 0xb6538 <strlen@plt> */
/* @0x24a520 ldr r2, [sp, #0x28] */
/* @0x24a524 ldr r3, [sp, #0x24] */
/* @0x24a528 add r1, r0, #1 */
/* @0x24a52c mov r4, r0 */
/* @0x24a530 mvn r0, r2 */
/* @0x24a534 add r0, r3, r0 */
/* @0x24a538 cmp r1, r0 */
/* @0x24a53c ble 0x24a5a4 <_Z18ObjectBaseToStringP12YYObjectBase+0x118> */
/* @0x24a540 cmp r3, #0 */
/* @0x24a544 add r2, r1, r2 */
/* @0x24a548 ldr r11, [sp, #0x20] */
/* @0x24a54c moveq r3, r1 */
/* @0x24a550 add r3, r3, r3, lsl #1 */
/* @0x24a554 add r3, r3, r3, lsr #31 */
/* @0x24a558 asr r3, r3, #1 */
/* @0x24a55c cmp r3, r2 */
/* @0x24a560 addlt r2, r2, r2, lsl #1 */
/* @0x24a564 addlt r2, r2, r2, lsr #31 */
/* @0x24a568 asrlt r3, r2, #1 */
/* @0x24a56c str r3, [sp, #0x4] */
/* @0x24a570 mov r0, r3 */
/* @0x24a574 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24a578 ldr r2, [sp, #0x24] */
/* @0x24a57c mov r1, r11 */
/* @0x24a580 str r0, [sp, #0x20] */
/* @0x24a584 bl 0xb65bc <memcpy@plt> */
/* @0x24a588 ldr r3, [sp, #0x4] */
/* @0x24a58c cmp r11, #0 */
/* @0x24a590 str r3, [sp, #0x24] */
/* @0x24a594 beq 0x24a5a0 <_Z18ObjectBaseToStringP12YYObjectBase+0x114> */
/* @0x24a598 mov r0, r11 */
/* @0x24a59c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a5a0 ldr r2, [sp, #0x28] */
/* @0x24a5a4 ldr r0, [sp, #0x20] */
/* @0x24a5a8 mov r1, r9 */
/* @0x24a5ac add r0, r0, r2 */
/* @0x24a5b0 bl 0xb65a4 <strcpy@plt> */
/* @0x24a5b4 ldr r3, [sp, #0x28] */
/* @0x24a5b8 add r4, r4, r3 */
/* @0x24a5bc str r4, [sp, #0x28] */
/* @0x24a5c0 ldr r3, [sp, #0x24] */
/* @0x24a5c4 mvn r2, r4 */
/* @0x24a5c8 add r2, r3, r2 */
/* @0x24a5cc cmp r2, #3 */
/* @0x24a5d0 bgt 0x24a630 <_Z18ObjectBaseToStringP12YYObjectBase+0x1a4> */
/* @0x24a5d4 cmp r3, #0 */
/* @0x24a5d8 add r4, r4, #4 */
/* @0x24a5dc addne r3, r3, r3, lsl #1 */
/* @0x24a5e0 ldr r11, [sp, #0x20] */
/* @0x24a5e4 moveq r9, #6 */
/* @0x24a5e8 addne r3, r3, r3, lsr #31 */
/* @0x24a5ec asrne r9, r3, #1 */
/* @0x24a5f0 cmp r4, r9 */
/* @0x24a5f4 addgt r4, r4, r4, lsl #1 */
/* @0x24a5f8 addgt r4, r4, r4, lsr #31 */
/* @0x24a5fc asrgt r9, r4, #1 */
/* @0x24a600 mov r0, r9 */
/* @0x24a604 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24a608 ldr r2, [sp, #0x24] */
/* @0x24a60c mov r1, r11 */
/* @0x24a610 str r0, [sp, #0x20] */
/* @0x24a614 bl 0xb65bc <memcpy@plt> */
/* @0x24a618 cmp r11, #0 */
/* @0x24a61c str r9, [sp, #0x24] */
/* @0x24a620 beq 0x24a62c <_Z18ObjectBaseToStringP12YYObjectBase+0x1a0> */
/* @0x24a624 mov r0, r11 */
/* @0x24a628 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a62c ldr r4, [sp, #0x28] */
/* @0x24a630 ldr r2, [sp, #0x8] */
/* @0x24a634 ldr r3, [sp, #0x20] */
/* @0x24a638 ldr r0, [r2] */
/* @0x24a63c str r0, [r3, r4] */
/* @0x24a640 mov r0, #256 */
/* @0x24a644 ldr r3, [sp, #0x28] */
/* @0x24a648 str r0, [sp, #0x14] */
/* @0x24a64c add r3, r3, #3 */
/* @0x24a650 str r3, [sp, #0x28] */
/* @0x24a654 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24a658 mov r2, #0 */
/* @0x24a65c add r1, sp, #24 */
/* @0x24a660 mov r3, r0 */
/* @0x24a664 add r0, sp, #104 */
/* @0x24a668 str r3, [sp, #0x18] */
/* @0x24a66c str r3, [r0, #-0x4c]! */
/* @0x24a670 strb r2, [r3] */
/* @0x24a674 add r2, sp, #20 */
/* @0x24a678 mov r3, r5 */
/* @0x24a67c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x24a680 ldr r1, [sp, #0x18] */
/* @0x24a684 ldr r4, [sp, #0x1c] */
/* @0x24a688 ldr r2, [sp, #0x28] */
/* @0x24a68c ldr r3, [sp, #0x24] */
/* @0x24a690 rsb r4, r1, r4 */
/* @0x24a694 add r0, r4, #1 */
/* @0x24a698 mvn r12, r2 */
/* @0x24a69c add r12, r3, r12 */
/* @0x24a6a0 cmp r0, r12 */
/* @0x24a6a4 ble 0x24a708 <_Z18ObjectBaseToStringP12YYObjectBase+0x27c> */
/* @0x24a6a8 cmp r3, #0 */
/* @0x24a6ac add r2, r0, r2 */
/* @0x24a6b0 ldr r11, [sp, #0x20] */
/* @0x24a6b4 moveq r3, r0 */
/* @0x24a6b8 add r3, r3, r3, lsl #1 */
/* @0x24a6bc add r3, r3, r3, lsr #31 */
/* @0x24a6c0 asr r9, r3, #1 */
/* @0x24a6c4 cmp r9, r2 */
/* @0x24a6c8 addlt r2, r2, r2, lsl #1 */
/* @0x24a6cc addlt r2, r2, r2, lsr #31 */
/* @0x24a6d0 asrlt r9, r2, #1 */
/* @0x24a6d4 mov r0, r9 */
/* @0x24a6d8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24a6dc ldr r2, [sp, #0x24] */
/* @0x24a6e0 mov r1, r11 */
/* @0x24a6e4 str r0, [sp, #0x20] */
/* @0x24a6e8 bl 0xb65bc <memcpy@plt> */
/* @0x24a6ec cmp r11, #0 */
/* @0x24a6f0 str r9, [sp, #0x24] */
/* @0x24a6f4 beq 0x24a700 <_Z18ObjectBaseToStringP12YYObjectBase+0x274> */
/* @0x24a6f8 mov r0, r11 */
/* @0x24a6fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a700 ldr r1, [sp, #0x18] */
/* @0x24a704 ldr r2, [sp, #0x28] */
/* @0x24a708 ldr r0, [sp, #0x20] */
/* @0x24a70c add r0, r0, r2 */
/* @0x24a710 bl 0xb65a4 <strcpy@plt> */
/* @0x24a714 ldr r3, [sp, #0x28] */
/* @0x24a718 ldr r0, [sp, #0x18] */
/* @0x24a71c add r4, r3, r4 */
/* @0x24a720 str r4, [sp, #0x28] */
/* @0x24a724 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a728 ldr r3, [sp, #0x28] */
/* @0x24a72c ldr r2, [sp, #0x24] */
/* @0x24a730 mvn r1, r3 */
/* @0x24a734 add r1, r2, r1 */
/* @0x24a738 cmp r1, #1 */
/* @0x24a73c bgt 0x24a79c <_Z18ObjectBaseToStringP12YYObjectBase+0x310> */
/* @0x24a740 cmp r2, #0 */
/* @0x24a744 add r3, r3, #2 */
/* @0x24a748 addne r2, r2, r2, lsl #1 */
/* @0x24a74c ldr r4, [sp, #0x20] */
/* @0x24a750 moveq r11, #3 */
/* @0x24a754 addne r2, r2, r2, lsr #31 */
/* @0x24a758 asrne r11, r2, #1 */
/* @0x24a75c cmp r3, r11 */
/* @0x24a760 addgt r3, r3, r3, lsl #1 */
/* @0x24a764 addgt r3, r3, r3, lsr #31 */
/* @0x24a768 asrgt r11, r3, #1 */
/* @0x24a76c mov r0, r11 */
/* @0x24a770 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24a774 ldr r2, [sp, #0x24] */
/* @0x24a778 mov r1, r4 */
/* @0x24a77c str r0, [sp, #0x20] */
/* @0x24a780 bl 0xb65bc <memcpy@plt> */
/* @0x24a784 cmp r4, #0 */
/* @0x24a788 str r11, [sp, #0x24] */
/* @0x24a78c beq 0x24a798 <_Z18ObjectBaseToStringP12YYObjectBase+0x30c> */
/* @0x24a790 mov r0, r4 */
/* @0x24a794 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a798 ldr r3, [sp, #0x28] */
/* @0x24a79c ldr r0, [sp, #0xc] */
/* @0x24a7a0 ldr r2, [sp, #0x20] */
/* @0x24a7a4 ldrh r1, [r0] */
/* @0x24a7a8 strh r1, [r2, r3] */
/* @0x24a7ac ldr r3, [sp, #0x28] */
/* @0x24a7b0 add r3, r3, #1 */
/* @0x24a7b4 str r3, [sp, #0x28] */
/* @0x24a7b8 mov r0, r6 */
/* @0x24a7bc mov r1, r7 */
/* @0x24a7c0 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x24a7c4 cmp r0, #0 */
/* @0x24a7c8 bne 0x24a4ec <_Z18ObjectBaseToStringP12YYObjectBase+0x60> */
/* @0x24a7cc ldr r3, [sp, #0x28] */
/* @0x24a7d0 cmp r3, #0 */
/* @0x24a7d4 mov r3, #0 */
/* @0x24a7d8 addeq r0, sp, #40 */
/* @0x24a7dc str r3, [sp, #0x28] */
/* @0x24a7e0 ldrne r0, [sp, #0x20] */
/* @0x24a7e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x24a7e8 mov r4, r0 */
/* @0x24a7ec ldr r0, [sp, #0x20] */
/* @0x24a7f0 cmp r0, #0 */
/* @0x24a7f4 beq 0x24a7fc <_Z18ObjectBaseToStringP12YYObjectBase+0x370> */
/* @0x24a7f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24a7fc mov r0, r4 */
/* @0x24a800 add sp, sp, #108 */
/* @0x24a804 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24a808 mulseq r0, r0, r9 */
/* @0x24a80c andeq r8, lr, r4, asr #15 */

/* ── FUNC 0x24a810 · EncodeObject(RValue*) · size=160 · insn=40 */
/* @0x24a810 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x24a814 sub sp, sp, #68 */
/* @0x24a818 ldr r6, [r0] */
/* @0x24a81c bl 0x27e89c <json_object_new_object> */
/* @0x24a820 add r7, sp, #36 */
/* @0x24a824 mov r2, #1 */
/* @0x24a828 add r9, sp, #4 */
/* @0x24a82c add r4, sp, #20 */
/* @0x24a830 mov r1, r6 */
/* @0x24a834 mov r8, r0 */
/* @0x24a838 mov r0, r7 */
/* @0x24a83c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x24a840 mov r3, #0 */
/* @0x24a844 mvn r2, #-16777216 */
/* @0x24a848 str r3, [sp, #0x4] */
/* @0x24a84c str r3, [sp, #0x8] */
/* @0x24a850 str r3, [sp, #0xc] */
/* @0x24a854 str r2, [sp, #0x10] */
/* @0x24a858 b 0x24a888 <_Z12EncodeObjectP6RValue+0x78> */
/* @0x24a85c ldr r3, [sp, #0x4] */
/* @0x24a860 ldr r2, [r3] */
/* @0x24a864 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x24a868 ldr r3, [sp, #0x4] */
/* @0x24a86c mov r0, r4 */
/* @0x24a870 ldr r5, [r3] */
/* @0x24a874 bl 0x13be2c <_Z11EncodeValueP6RValue> */
/* @0x24a878 mov r1, r5 */
/* @0x24a87c mov r2, r0 */
/* @0x24a880 mov r0, r8 */
/* @0x24a884 bl 0x27ea00 <json_object_object_add> */
/* @0x24a888 mov r1, r9 */
/* @0x24a88c mov r0, r7 */
/* @0x24a890 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x24a894 mov r1, r4 */
/* @0x24a898 cmp r0, #0 */
/* @0x24a89c mov r0, r6 */
/* @0x24a8a0 bne 0x24a85c <_Z12EncodeObjectP6RValue+0x4c> */
/* @0x24a8a4 mov r0, r8 */
/* @0x24a8a8 add sp, sp, #68 */
/* @0x24a8ac pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x24a8b0 · F_JSObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x24a8b0 push {r4, r5, r6, r7, r8, lr} */
/* @0x24a8b4 sub sp, sp, #24 */
/* @0x24a8b8 mov r4, r1 */
/* @0x24a8bc mov r6, r0 */
/* @0x24a8c0 ldr r5, [sp, #0x30] */
/* @0x24a8c4 mov r7, r3 */
/* @0x24a8c8 str r5, [sp] */
/* @0x24a8cc bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24a8d0 ldr r2, [r4, #0x48] */
/* @0x24a8d4 ldr r6, [r6] */
/* @0x24a8d8 cmp r2, #3 */
/* @0x24a8dc beq 0x24a8e8 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x24a8e0 add sp, sp, #24 */
/* @0x24a8e4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24a8e8 ldr r1, [r4, #0x4] */
/* @0x24a8ec cmp r1, #0 */
/* @0x24a8f0 beq 0x24a988 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x24a8f4 ldr r3, [r1, #0xc] */
/* @0x24a8f8 bic r3, r3, #-16777216 */
/* @0x24a8fc cmp r3, #6 */
/* @0x24a900 beq 0x24a974 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x24a904 mov r3, #0 */
/* @0x24a908 str r3, [r6, #0x18] */
/* @0x24a90c ldr r3, [r4, #0x64] */
/* @0x24a910 cmp r3, #0 */
/* @0x24a914 beq 0x24a8e0 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x24a918 add r8, sp, #8 */
/* @0x24a91c str r5, [sp] */
/* @0x24a920 mov r2, r4 */
/* @0x24a924 mov r3, r7 */
/* @0x24a928 mov r0, r6 */
/* @0x24a92c mov r1, r8 */
/* @0x24a930 mov lr, #0 */
/* @0x24a934 mvn r12, #-16777216 */
/* @0x24a938 mov r4, #0 */
/* @0x24a93c mov r5, #0 */
/* @0x24a940 str lr, [sp, #0x10] */
/* @0x24a944 strd r4, r5, [sp, #8] */
/* @0x24a948 str r12, [sp, #0x14] */
/* @0x24a94c bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_> */
/* @0x24a950 ldr r3, [sp, #0x14] */
/* @0x24a954 sub r3, r3, #1 */
/* @0x24a958 bic r3, r3, #-16777216 */
/* @0x24a95c bic r3, r3, #3 */
/* @0x24a960 cmp r3, #0 */
/* @0x24a964 bne 0x24a8e0 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x24a968 mov r0, r8 */
/* @0x24a96c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24a970 b 0x24a8e0 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x24a974 ldr r1, [r1] */
/* @0x24a978 mov r0, r6 */
/* @0x24a97c str r1, [r6, #0x18] */
/* @0x24a980 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24a984 b 0x24a90c <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x24a988 mov r0, r4 */
/* @0x24a98c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24a990 subs r1, r0, #0 */
/* @0x24a994 bne 0x24a8f4 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x24a998 b 0x24a904 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x54> */

/* ── FUNC 0x24a99c · DoReplace(YYStrBuilder&, CInstance*, bool, RValue*, RValue*, int, SMatches**, int, int) · size=3992 · insn=998 */
/* @0x24a99c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24a9a0 vpush {d8} */
/* @0x24a9a4 add r11, sp, #40 */
/* @0x24a9a8 ldr r7, [pc, #0xf74] */
/* @0x24a9ac sub sp, sp, #140 */
/* @0x24a9b0 str r3, [r11, #-0x7c] */
/* @0x24a9b4 mov r1, #0 */
/* @0x24a9b8 mov r8, r0 */
/* @0x24a9bc str r7, [r11, #-0x9c] */
/* @0x24a9c0 mov r4, r2 */
/* @0x24a9c4 ldr r7, [r11, #0x4] */
/* @0x24a9c8 str r7, [r11, #-0x54] */
/* @0x24a9cc ldr r7, [r11, #-0x9c] */
/* @0x24a9d0 ldr r0, [r11, #-0x54] */
/* @0x24a9d4 ldr r7, [pc, r7] */
/* @0x24a9d8 str r7, [r11, #-0x9c] */
/* @0x24a9dc ldr r3, [r7] */
/* @0x24a9e0 ldr r7, [r11, #0xc] */
/* @0x24a9e4 str r3, [r11, #-0x30] */
/* @0x24a9e8 str r7, [r11, #-0x88] */
/* @0x24a9ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x24a9f0 str r0, [r11, #-0x50] */
/* @0x24a9f4 bl 0xb6538 <strlen@plt> */
/* @0x24a9f8 cmp r4, #0 */
/* @0x24a9fc str r0, [r11, #-0x98] */
/* @0x24aa00 beq 0x24af24 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x588> */
/* @0x24aa04 ldr r7, [r11, #0x10] */
/* @0x24aa08 cmp r7, #0 */
/* @0x24aa0c ble 0x24af04 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x568> */
/* @0x24aa10 ldr r7, [pc, #0xf10] */
/* @0x24aa14 mov r4, #0 */
/* @0x24aa18 ldr lr, [r11, #0x8] */
/* @0x24aa1c str r7, [r11, #-0x78] */
/* @0x24aa20 ldr r7, [r11, #-0x88] */
/* @0x24aa24 sub r7, r7, #4 */
/* @0x24aa28 str r7, [r11, #-0xa4] */
/* @0x24aa2c sub r7, r11, #64 */
/* @0x24aa30 str r7, [r11, #-0x70] */
/* @0x24aa34 mov r7, #0 */
/* @0x24aa38 str r7, [r11, #-0x58] */
/* @0x24aa3c ldr r7, [r11, #-0x78] */
/* @0x24aa40 ldr r7, [pc, r7] */
/* @0x24aa44 str r7, [r11, #-0x78] */
/* @0x24aa48 sub r7, r11, #60 */
/* @0x24aa4c str r7, [r11, #-0x8c] */
/* @0x24aa50 sub r7, r11, #56 */
/* @0x24aa54 str r7, [r11, #-0x90] */
/* @0x24aa58 sub r7, r11, #52 */
/* @0x24aa5c str r7, [r11, #-0x94] */
/* @0x24aa60 sub r7, r11, #68 */
/* @0x24aa64 str r7, [r11, #-0x88] */
/* @0x24aa68 sub r7, r11, #72 */
/* @0x24aa6c str r7, [r11, #-0x84] */
/* @0x24aa70 sub r7, r11, #76 */
/* @0x24aa74 str r7, [r11, #-0x80] */
/* @0x24aa78 ldr r7, [r11, #-0x50] */
/* @0x24aa7c add r7, r7, lr */
/* @0x24aa80 str r7, [r11, #-0xa0] */
/* @0x24aa84 ldr r7, [r11, #-0xa4] */
/* @0x24aa88 str r7, [r11, #-0x5c] */
/* @0x24aa8c ldr r7, [r11, #-0x70] */
/* @0x24aa90 str r7, [r11, #-0x60] */
/* @0x24aa94 mov r7, #1 */
/* @0x24aa98 str r7, [r11, #-0x74] */
/* @0x24aa9c ldr r7, [r11, #-0x58] */
/* @0x24aaa0 add r7, r7, #1 */
/* @0x24aaa4 str r7, [r11, #-0x58] */
/* @0x24aaa8 ldr r7, [r11, #-0x5c] */
/* @0x24aaac ldr lr, [r11, #-0x58] */
/* @0x24aab0 ldr r5, [r7, #0x4]! */
/* @0x24aab4 str r7, [r11, #-0x5c] */
/* @0x24aab8 ldr r7, [r11, #0x10] */
/* @0x24aabc ldr r1, [r5, #0x4] */
/* @0x24aac0 vldr s16, [r1] */
/* @0x24aac4 cmp r7, lr */
/* @0x24aac8 ldr lr, [r5] */
/* @0x24aacc ldrgt r7, [r11, #-0x5c] */
/* @0x24aad0 ldrle r7, [r11, #-0x98] */
/* @0x24aad4 ldrgt r3, [r7, #0x4] */
/* @0x24aad8 strle r7, [r11, #-0x64] */
/* @0x24aadc ldr r7, [r1, #0x4] */
/* @0x24aae0 ldrgt r3, [r3, #0x4] */
/* @0x24aae4 str r7, [r11, #-0x68] */
/* @0x24aae8 ldrgt r3, [r3] */
/* @0x24aaec strgt r3, [r11, #-0x64] */
/* @0x24aaf0 lsl r3, lr, #4 */
/* @0x24aaf4 add r3, r3, #40 */
/* @0x24aaf8 cmp lr, #0 */
/* @0x24aafc sub sp, sp, r3 */
/* @0x24ab00 add r6, sp, #8 */
/* @0x24ab04 ble 0x24ab44 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x1a8> */
/* @0x24ab08 mov r9, #0 */
/* @0x24ab0c mov r7, r6 */
/* @0x24ab10 mov r10, r9 */
/* @0x24ab14 b 0x24ab1c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x180> */
/* @0x24ab18 ldr r1, [r5, #0x4] */
/* @0x24ab1c add r1, r1, r9 */
/* @0x24ab20 mov r0, r7 */
/* @0x24ab24 add r10, r10, #1 */
/* @0x24ab28 add r9, r9, #12 */
/* @0x24ab2c ldr r1, [r1, #0x8] */
/* @0x24ab30 add r7, r7, #16 */
/* @0x24ab34 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x24ab38 ldr lr, [r5] */
/* @0x24ab3c cmp lr, r10 */
/* @0x24ab40 bgt 0x24ab18 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x17c> */
/* @0x24ab44 ldr r7, [r11, #-0x54] */
/* @0x24ab48 vcvt.f64.s32 d7, s16 */
/* @0x24ab4c lsl lr, lr, #4 */
/* @0x24ab50 str r4, [r11, #-0x3c] */
/* @0x24ab54 add r12, lr, #16 */
/* @0x24ab58 add lr, r6, lr */
/* @0x24ab5c ldr r0, [r7] */
/* @0x24ab60 add r12, r6, r12 */
/* @0x24ab64 ldr r1, [r7, #0x4] */
/* @0x24ab68 ldr r2, [r7, #0x8] */
/* @0x24ab6c ldr r3, [r7, #0xc] */
/* @0x24ab70 ldr r7, [r11, #-0x70] */
/* @0x24ab74 vstr d7, [lr] */
/* @0x24ab78 str r4, [lr, #0xc] */
/* @0x24ab7c stm r12!, {r0, r1, r2, r3} */
/* @0x24ab80 str r4, [r7] */
/* @0x24ab84 sub r7, r11, #64 */
/* @0x24ab88 str r7, [r11, #-0x70] */
/* @0x24ab8c mov r1, r7 */
/* @0x24ab90 ldr r7, [r11, #-0x78] */
/* @0x24ab94 str r4, [r11, #-0x38] */
/* @0x24ab98 str r4, [r11, #-0x34] */
/* @0x24ab9c ldr r3, [r5] */
/* @0x24aba0 ldr r0, [r7] */
/* @0x24aba4 ldr r2, [r11, #-0x7c] */
/* @0x24aba8 add r3, r3, #2 */
/* @0x24abac str r6, [sp] */
/* @0x24abb0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x24abb4 ldr r1, [r5] */
/* @0x24abb8 cmp r1, #0 */
/* @0x24abbc movgt r7, #0 */
/* @0x24abc0 bgt 0x24abe4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x248> */
/* @0x24abc4 b 0x24ac0c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x270> */
/* @0x24abc8 add r7, r7, #1 */
/* @0x24abcc str r4, [r6, #0x8] */
/* @0x24abd0 cmp r1, r7 */
/* @0x24abd4 mov lr, #5 */
/* @0x24abd8 str lr, [r6, #0xc] */
/* @0x24abdc str r4, [r6], #16 */
/* @0x24abe0 ble 0x24ac0c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x270> */
/* @0x24abe4 ldr r3, [r6, #0xc] */
/* @0x24abe8 sub r3, r3, #1 */
/* @0x24abec bic r3, r3, #-16777216 */
/* @0x24abf0 bic r3, r3, #3 */
/* @0x24abf4 cmp r3, #0 */
/* @0x24abf8 bne 0x24abc8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x22c> */
/* @0x24abfc mov r0, r6 */
/* @0x24ac00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24ac04 ldr r1, [r5] */
/* @0x24ac08 b 0x24abc8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x22c> */
/* @0x24ac0c ldr r7, [r11, #-0x74] */
/* @0x24ac10 cmp r7, #0 */
/* @0x24ac14 beq 0x24acd0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x334> */
/* @0x24ac18 vmov r0, s16 */
/* @0x24ac1c ldr r7, [r11, #0x8] */
/* @0x24ac20 cmp r0, r7 */
/* @0x24ac24 ble 0x24acd0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x334> */
/* @0x24ac28 ldr r7, [r11, #-0x50] */
/* @0x24ac2c ldr r2, [r8, #0x8] */
/* @0x24ac30 add r10, r7, r0 */
/* @0x24ac34 ldr r7, [r11, #-0xa0] */
/* @0x24ac38 ldr r3, [r8, #0x4] */
/* @0x24ac3c mvn r1, r2 */
/* @0x24ac40 ldrb r5, [r7], #1 */
/* @0x24ac44 add r1, r3, r1 */
/* @0x24ac48 cmp r1, #1 */
/* @0x24ac4c bgt 0x24acac <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x310> */
/* @0x24ac50 cmp r3, #0 */
/* @0x24ac54 add r2, r2, #2 */
/* @0x24ac58 addne r3, r3, r3, lsl #1 */
/* @0x24ac5c ldr r9, [r8] */
/* @0x24ac60 moveq r6, #3 */
/* @0x24ac64 addne r3, r3, r3, lsr #31 */
/* @0x24ac68 asrne r6, r3, #1 */
/* @0x24ac6c cmp r2, r6 */
/* @0x24ac70 addgt r2, r2, r2, lsl #1 */
/* @0x24ac74 addgt r2, r2, r2, lsr #31 */
/* @0x24ac78 asrgt r6, r2, #1 */
/* @0x24ac7c mov r0, r6 */
/* @0x24ac80 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24ac84 ldr r2, [r8, #0x4] */
/* @0x24ac88 mov r1, r9 */
/* @0x24ac8c str r0, [r8] */
/* @0x24ac90 bl 0xb65bc <memcpy@plt> */
/* @0x24ac94 cmp r9, #0 */
/* @0x24ac98 str r6, [r8, #0x4] */
/* @0x24ac9c beq 0x24aca8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x30c> */
/* @0x24aca0 mov r0, r9 */
/* @0x24aca4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24aca8 ldr r2, [r8, #0x8] */
/* @0x24acac ldr r3, [r8] */
/* @0x24acb0 cmp r7, r10 */
/* @0x24acb4 add r1, r3, r2 */
/* @0x24acb8 strb r5, [r3, r2] */
/* @0x24acbc strb r4, [r1, #0x1] */
/* @0x24acc0 ldr r2, [r8, #0x8] */
/* @0x24acc4 add r2, r2, #1 */
/* @0x24acc8 str r2, [r8, #0x8] */
/* @0x24accc bne 0x24ac38 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x29c> */
/* @0x24acd0 mov r0, #256 */
/* @0x24acd4 str r0, [r11, #-0x4c] */
/* @0x24acd8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24acdc sub r1, r11, #72 */
/* @0x24ace0 sub r2, r11, #76 */
/* @0x24ace4 mov r3, r0 */
/* @0x24ace8 str r0, [r11, #-0x48] */
/* @0x24acec str r0, [r11, #-0x44] */
/* @0x24acf0 sub r0, r11, #68 */
/* @0x24acf4 strb r4, [r3] */
/* @0x24acf8 sub r3, r11, #64 */
/* @0x24acfc bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x24ad00 ldr r1, [r11, #-0x48] */
/* @0x24ad04 ldr r5, [r11, #-0x44] */
/* @0x24ad08 ldr r2, [r8, #0x8] */
/* @0x24ad0c ldr r3, [r8, #0x4] */
/* @0x24ad10 rsb r5, r1, r5 */
/* @0x24ad14 add r0, r5, #1 */
/* @0x24ad18 mvn r12, r2 */
/* @0x24ad1c add r12, r3, r12 */
/* @0x24ad20 cmp r0, r12 */
/* @0x24ad24 ble 0x24ad88 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x3ec> */
/* @0x24ad28 cmp r3, #0 */
/* @0x24ad2c add r2, r0, r2 */
/* @0x24ad30 ldr r6, [r8] */
/* @0x24ad34 moveq r3, r0 */
/* @0x24ad38 add r3, r3, r3, lsl #1 */
/* @0x24ad3c add r3, r3, r3, lsr #31 */
/* @0x24ad40 asr r10, r3, #1 */
/* @0x24ad44 cmp r10, r2 */
/* @0x24ad48 addlt r2, r2, r2, lsl #1 */
/* @0x24ad4c addlt r2, r2, r2, lsr #31 */
/* @0x24ad50 asrlt r10, r2, #1 */
/* @0x24ad54 mov r0, r10 */
/* @0x24ad58 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24ad5c ldr r2, [r8, #0x4] */
/* @0x24ad60 mov r1, r6 */
/* @0x24ad64 str r0, [r8] */
/* @0x24ad68 bl 0xb65bc <memcpy@plt> */
/* @0x24ad6c cmp r6, #0 */
/* @0x24ad70 str r10, [r8, #0x4] */
/* @0x24ad74 beq 0x24ad80 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x3e4> */
/* @0x24ad78 mov r0, r6 */
/* @0x24ad7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ad80 ldr r1, [r11, #-0x48] */
/* @0x24ad84 ldr r2, [r8, #0x8] */
/* @0x24ad88 ldr r0, [r8] */
/* @0x24ad8c add r0, r0, r2 */
/* @0x24ad90 bl 0xb65a4 <strcpy@plt> */
/* @0x24ad94 ldr r3, [r8, #0x8] */
/* @0x24ad98 ldr r0, [r11, #-0x48] */
/* @0x24ad9c add r5, r3, r5 */
/* @0x24ada0 str r5, [r8, #0x8] */
/* @0x24ada4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ada8 ldr r7, [r11, #-0x64] */
/* @0x24adac ldr r0, [r11, #-0x68] */
/* @0x24adb0 cmp r7, r0 */
/* @0x24adb4 ble 0x24ae68 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4cc> */
/* @0x24adb8 ldr r1, [r11, #-0x50] */
/* @0x24adbc ldr r3, [r11, #-0x68] */
/* @0x24adc0 ldr r0, [r11, #-0x64] */
/* @0x24adc4 ldr r2, [r8, #0x8] */
/* @0x24adc8 add r7, r1, r3 */
/* @0x24adcc add r10, r1, r0 */
/* @0x24add0 ldr r3, [r8, #0x4] */
/* @0x24add4 mvn r1, r2 */
/* @0x24add8 ldrb r5, [r7], #1 */
/* @0x24addc add r1, r3, r1 */
/* @0x24ade0 cmp r1, #1 */
/* @0x24ade4 bgt 0x24ae44 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4a8> */
/* @0x24ade8 cmp r3, #0 */
/* @0x24adec add r2, r2, #2 */
/* @0x24adf0 addne r3, r3, r3, lsl #1 */
/* @0x24adf4 ldr r9, [r8] */
/* @0x24adf8 moveq r6, #3 */
/* @0x24adfc addne r3, r3, r3, lsr #31 */
/* @0x24ae00 asrne r6, r3, #1 */
/* @0x24ae04 cmp r2, r6 */
/* @0x24ae08 addgt r2, r2, r2, lsl #1 */
/* @0x24ae0c addgt r2, r2, r2, lsr #31 */
/* @0x24ae10 asrgt r6, r2, #1 */
/* @0x24ae14 mov r0, r6 */
/* @0x24ae18 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24ae1c ldr r2, [r8, #0x4] */
/* @0x24ae20 mov r1, r9 */
/* @0x24ae24 str r0, [r8] */
/* @0x24ae28 bl 0xb65bc <memcpy@plt> */
/* @0x24ae2c cmp r9, #0 */
/* @0x24ae30 str r6, [r8, #0x4] */
/* @0x24ae34 beq 0x24ae40 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4a4> */
/* @0x24ae38 mov r0, r9 */
/* @0x24ae3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ae40 ldr r2, [r8, #0x8] */
/* @0x24ae44 ldr r3, [r8] */
/* @0x24ae48 cmp r7, r10 */
/* @0x24ae4c add r1, r3, r2 */
/* @0x24ae50 strb r5, [r3, r2] */
/* @0x24ae54 strb r4, [r1, #0x1] */
/* @0x24ae58 ldr r2, [r8, #0x8] */
/* @0x24ae5c add r2, r2, #1 */
/* @0x24ae60 str r2, [r8, #0x8] */
/* @0x24ae64 bne 0x24add0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x434> */
/* @0x24ae68 ldr r7, [r11, #-0x58] */
/* @0x24ae6c ldr r0, [r11, #0x10] */
/* @0x24ae70 cmp r7, r0 */
/* @0x24ae74 beq 0x24aeb0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x514> */
/* @0x24ae78 mov r7, #0 */
/* @0x24ae7c str r7, [r11, #-0x74] */
/* @0x24ae80 b 0x24aa9c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x100> */
/* @0x24ae84 ldr r3, [r11, #-0x84] */
/* @0x24ae88 cmp r3, #0 */
/* @0x24ae8c beq 0x24ae98 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4fc> */
/* @0x24ae90 ldr r0, [r11, #-0x84] */
/* @0x24ae94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ae98 ldr r7, [r11, #0x10] */
/* @0x24ae9c cmp r7, #0 */
/* @0x24aea0 ble 0x24af04 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x568> */
/* @0x24aea4 ldr r7, [r11, #-0x88] */
/* @0x24aea8 sub r7, r7, #4 */
/* @0x24aeac str r7, [r11, #-0xa4] */
/* @0x24aeb0 ldr r8, [r11, #-0xa4] */
/* @0x24aeb4 mov r7, #0 */
/* @0x24aeb8 ldr r9, [r11, #0x10] */
/* @0x24aebc ldr r6, [r8, #0x4]! */
/* @0x24aec0 ldr r3, [r6] */
/* @0x24aec4 cmp r3, #0 */
/* @0x24aec8 movgt r4, #0 */
/* @0x24aecc movgt r5, r4 */
/* @0x24aed0 ble 0x24aef8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x55c> */
/* @0x24aed4 ldr r3, [r6, #0x4] */
/* @0x24aed8 add r5, r5, #1 */
/* @0x24aedc add r3, r3, r4 */
/* @0x24aee0 add r4, r4, #12 */
/* @0x24aee4 ldr r0, [r3, #0x8] */
/* @0x24aee8 bl 0x25f6ac <pcre_free_substring> */
/* @0x24aeec ldr r3, [r6] */
/* @0x24aef0 cmp r3, r5 */
/* @0x24aef4 bgt 0x24aed4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x538> */
/* @0x24aef8 add r7, r7, #1 */
/* @0x24aefc cmp r9, r7 */
/* @0x24af00 bgt 0x24aebc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x520> */
/* @0x24af04 ldr r7, [r11, #-0x9c] */
/* @0x24af08 ldr r2, [r11, #-0x30] */
/* @0x24af0c ldr r3, [r7] */
/* @0x24af10 cmp r2, r3 */
/* @0x24af14 bne 0x24b920 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf84> */
/* @0x24af18 sub sp, r11, #40 */
/* @0x24af1c vpop {d8} */
/* @0x24af20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24af24 mov r3, #256 */
/* @0x24af28 str r4, [r11, #-0x40] */
/* @0x24af2c mov r0, r3 */
/* @0x24af30 str r3, [r11, #-0x4c] */
/* @0x24af34 str r4, [r11, #-0x3c] */
/* @0x24af38 str r4, [r11, #-0x38] */
/* @0x24af3c bl 0xcef4c <_Z7YYAlloci> */
/* @0x24af40 ldr r3, [r11, #-0x7c] */
/* @0x24af44 sub r1, r11, #72 */
/* @0x24af48 mov r2, r0 */
/* @0x24af4c str r0, [r11, #-0x48] */
/* @0x24af50 sub r0, r11, #44 */
/* @0x24af54 str r2, [r0, #-0x18]! */
/* @0x24af58 strb r4, [r2] */
/* @0x24af5c sub r2, r11, #76 */
/* @0x24af60 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x24af64 ldr r3, [r11, #-0x48] */
/* @0x24af68 ldr r2, [r11, #-0x44] */
/* @0x24af6c rsb r2, r3, r2 */
/* @0x24af70 str r2, [r11, #-0x78] */
/* @0x24af74 adds r2, r2, #1 */
/* @0x24af78 strmi r4, [r11, #-0x84] */
/* @0x24af7c movmi r1, r3 */
/* @0x24af80 bmi 0x24afa4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x608> */
/* @0x24af84 add r2, r2, r2, lsl #1 */
/* @0x24af88 asr r4, r2, #1 */
/* @0x24af8c mov r0, r4 */
/* @0x24af90 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24af94 ldr r1, [r11, #-0x48] */
/* @0x24af98 str r4, [r11, #-0x3c] */
/* @0x24af9c str r0, [r11, #-0x84] */
/* @0x24afa0 str r0, [r11, #-0x40] */
/* @0x24afa4 ldr r0, [r11, #-0x84] */
/* @0x24afa8 bl 0xb65a4 <strcpy@plt> */
/* @0x24afac ldr r3, [r11, #-0x78] */
/* @0x24afb0 ldr r0, [r11, #-0x48] */
/* @0x24afb4 str r3, [r11, #-0x38] */
/* @0x24afb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24afbc ldr r7, [r11, #0x10] */
/* @0x24afc0 cmp r7, #0 */
/* @0x24afc4 ble 0x24ae84 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4e8> */
/* @0x24afc8 ldr r7, [pc, #0x95c] */
/* @0x24afcc mov r3, #0 */
/* @0x24afd0 str r3, [r11, #-0x58] */
/* @0x24afd4 mov r9, #0 */
/* @0x24afd8 add r7, pc, r7 */
/* @0x24afdc str r7, [r11, #-0x7c] */
/* @0x24afe0 ldr r7, [r11, #-0x88] */
/* @0x24afe4 mov r2, #1 */
/* @0x24afe8 ldr r3, [r11, #-0x50] */
/* @0x24afec sub r7, r7, #4 */
/* @0x24aff0 str r7, [r11, #-0x64] */
/* @0x24aff4 ldr r7, [r11, #0x8] */
/* @0x24aff8 add r3, r3, r7 */
/* @0x24affc str r3, [r11, #-0x80] */
/* @0x24b000 str r7, [r11, #-0x74] */
/* @0x24b004 ldr r3, [r11, #-0x58] */
/* @0x24b008 add r3, r3, #1 */
/* @0x24b00c str r3, [r11, #-0x58] */
/* @0x24b010 ldr r3, [r11, #-0x64] */
/* @0x24b014 ldr r7, [r3, #0x4]! */
/* @0x24b018 str r3, [r11, #-0x64] */
/* @0x24b01c str r7, [r11, #-0x5c] */
/* @0x24b020 ldr r3, [r11, #-0x58] */
/* @0x24b024 ldr r7, [r11, #0x10] */
/* @0x24b028 cmp r7, r3 */
/* @0x24b02c ldrgt r7, [r11, #-0x64] */
/* @0x24b030 ldrle r7, [r11, #-0x98] */
/* @0x24b034 ldrgt r3, [r7, #0x4] */
/* @0x24b038 strle r7, [r11, #-0x68] */
/* @0x24b03c ldr r7, [r11, #-0x5c] */
/* @0x24b040 ldrgt r3, [r3, #0x4] */
/* @0x24b044 ldrgt r3, [r3] */
/* @0x24b048 strgt r3, [r11, #-0x68] */
/* @0x24b04c ldr r3, [r7, #0x4] */
/* @0x24b050 ldr r7, [r11, #-0x78] */
/* @0x24b054 cmp r7, #0 */
/* @0x24b058 ldr r7, [r3] */
/* @0x24b05c ldr r3, [r3, #0x4] */
/* @0x24b060 subeq r4, r11, #56 */
/* @0x24b064 ldrne r4, [r11, #-0x84] */
/* @0x24b068 cmp r2, #0 */
/* @0x24b06c str r7, [r11, #-0x60] */
/* @0x24b070 str r3, [r11, #-0x54] */
/* @0x24b074 beq 0x24b148 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x7ac> */
/* @0x24b078 ldr r3, [r11, #-0x60] */
/* @0x24b07c ldr r7, [r11, #-0x74] */
/* @0x24b080 cmp r3, r7 */
/* @0x24b084 ble 0x24b914 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf78> */
/* @0x24b088 ldr r0, [r11, #-0x50] */
/* @0x24b08c ldr r2, [r8, #0x8] */
/* @0x24b090 add r10, r0, r7 */
/* @0x24b094 add r3, r0, r3 */
/* @0x24b098 str r4, [r11, #-0x70] */
/* @0x24b09c mov r4, r10 */
/* @0x24b0a0 mov r10, r3 */
/* @0x24b0a4 ldr r12, [r8, #0x4] */
/* @0x24b0a8 mvn r1, r2 */
/* @0x24b0ac ldrb r6, [r4], #1 */
/* @0x24b0b0 add r1, r12, r1 */
/* @0x24b0b4 cmp r1, #1 */
/* @0x24b0b8 bgt 0x24b118 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x77c> */
/* @0x24b0bc cmp r12, #0 */
/* @0x24b0c0 add r2, r2, #2 */
/* @0x24b0c4 addne r12, r12, r12, lsl #1 */
/* @0x24b0c8 ldr r5, [r8] */
/* @0x24b0cc moveq r7, #3 */
/* @0x24b0d0 addne r12, r12, r12, lsr #31 */
/* @0x24b0d4 asrne r7, r12, #1 */
/* @0x24b0d8 cmp r2, r7 */
/* @0x24b0dc addgt r2, r2, r2, lsl #1 */
/* @0x24b0e0 addgt r2, r2, r2, lsr #31 */
/* @0x24b0e4 asrgt r7, r2, #1 */
/* @0x24b0e8 mov r0, r7 */
/* @0x24b0ec bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b0f0 ldr r2, [r8, #0x4] */
/* @0x24b0f4 mov r1, r5 */
/* @0x24b0f8 str r0, [r8] */
/* @0x24b0fc bl 0xb65bc <memcpy@plt> */
/* @0x24b100 cmp r5, #0 */
/* @0x24b104 str r7, [r8, #0x4] */
/* @0x24b108 beq 0x24b114 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x778> */
/* @0x24b10c mov r0, r5 */
/* @0x24b110 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b114 ldr r2, [r8, #0x8] */
/* @0x24b118 ldr r1, [r8] */
/* @0x24b11c cmp r4, r10 */
/* @0x24b120 add r0, r1, r2 */
/* @0x24b124 strb r6, [r1, r2] */
/* @0x24b128 strb r9, [r0, #0x1] */
/* @0x24b12c ldr r2, [r8, #0x8] */
/* @0x24b130 add r2, r2, #1 */
/* @0x24b134 str r2, [r8, #0x8] */
/* @0x24b138 bne 0x24b0a4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x708> */
/* @0x24b13c ldr r7, [r11, #-0x54] */
/* @0x24b140 ldr r4, [r11, #-0x70] */
/* @0x24b144 str r7, [r11, #-0x74] */
/* @0x24b148 ldrb r6, [r4] */
/* @0x24b14c cmp r6, #0 */
/* @0x24b150 beq 0x24b4f8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb5c> */
/* @0x24b154 ldr r3, [r11, #-0x50] */
/* @0x24b158 ldr r7, [r11, #-0x60] */
/* @0x24b15c add r3, r3, r7 */
/* @0x24b160 str r3, [r11, #-0x70] */
/* @0x24b164 b 0x24b20c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x870> */
/* @0x24b168 ldr r2, [r8, #0x8] */
/* @0x24b16c ldr r3, [r8, #0x4] */
/* @0x24b170 mvn r1, r2 */
/* @0x24b174 add r1, r3, r1 */
/* @0x24b178 cmp r1, #1 */
/* @0x24b17c bgt 0x24b1dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x840> */
/* @0x24b180 cmp r3, #0 */
/* @0x24b184 add r2, r2, #2 */
/* @0x24b188 addne r3, r3, r3, lsl #1 */
/* @0x24b18c ldr r5, [r8] */
/* @0x24b190 moveq r10, #3 */
/* @0x24b194 addne r3, r3, r3, lsr #31 */
/* @0x24b198 asrne r10, r3, #1 */
/* @0x24b19c cmp r2, r10 */
/* @0x24b1a0 addgt r2, r2, r2, lsl #1 */
/* @0x24b1a4 addgt r2, r2, r2, lsr #31 */
/* @0x24b1a8 asrgt r10, r2, #1 */
/* @0x24b1ac mov r0, r10 */
/* @0x24b1b0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b1b4 ldr r2, [r8, #0x4] */
/* @0x24b1b8 mov r1, r5 */
/* @0x24b1bc str r0, [r8] */
/* @0x24b1c0 bl 0xb65bc <memcpy@plt> */
/* @0x24b1c4 cmp r5, #0 */
/* @0x24b1c8 str r10, [r8, #0x4] */
/* @0x24b1cc beq 0x24b1d8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x83c> */
/* @0x24b1d0 mov r0, r5 */
/* @0x24b1d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b1d8 ldr r2, [r8, #0x8] */
/* @0x24b1dc ldr r3, [r8] */
/* @0x24b1e0 mov r5, r4 */
/* @0x24b1e4 add r1, r2, r3 */
/* @0x24b1e8 strb r6, [r2, r3] */
/* @0x24b1ec strb r9, [r1, #0x1] */
/* @0x24b1f0 ldr r3, [r8, #0x8] */
/* @0x24b1f4 add r3, r3, #1 */
/* @0x24b1f8 str r3, [r8, #0x8] */
/* @0x24b1fc ldrb r6, [r5, #0x1] */
/* @0x24b200 add r4, r5, #1 */
/* @0x24b204 cmp r6, #0 */
/* @0x24b208 beq 0x24b4f8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb5c> */
/* @0x24b20c cmp r6, #36 */
/* @0x24b210 bne 0x24b168 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x7cc> */
/* @0x24b214 ldrb r6, [r4, #0x1] */
/* @0x24b218 sub r3, r6, #36 */
/* @0x24b21c cmp r3, #60 */
/* @0x24b220 addls pc, pc, r3, lsl #2 */
/* @0x24b224 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b228 b 0x24b760 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xdc4> */
/* @0x24b22c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b230 b 0x24b5d0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xc34> */
/* @0x24b234 b 0x24b694 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf8> */
/* @0x24b238 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b23c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b240 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b244 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b248 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b24c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b250 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b254 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b258 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b25c b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b260 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b264 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b268 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b26c b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b270 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b274 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b278 b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b27c b 0x24b3dc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa40> */
/* @0x24b280 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b284 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b288 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b28c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b290 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b294 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b298 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b29c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2a0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2a4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2a8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2ac b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2b0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2b4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2b8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2bc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2c0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2c4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2c8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2cc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2d0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2d4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2d8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2dc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2e0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2e4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2e8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2ec b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2f0 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2f4 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2f8 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b2fc b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b300 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b304 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b308 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b30c b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b310 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b314 b 0x24b7f4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe58> */
/* @0x24b318 b 0x24b31c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x980> */
/* @0x24b31c ldr r7, [r11, #0x8] */
/* @0x24b320 ldr r3, [r11, #-0x60] */
/* @0x24b324 cmp r7, r3 */
/* @0x24b328 bge 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b32c ldr r2, [r8, #0x8] */
/* @0x24b330 ldr r10, [r11, #-0x80] */
/* @0x24b334 ldr r6, [r11, #-0x70] */
/* @0x24b338 str r4, [r11, #-0x6c] */
/* @0x24b33c ldr r3, [r8, #0x4] */
/* @0x24b340 mvn r1, r2 */
/* @0x24b344 ldrb r5, [r10], #1 */
/* @0x24b348 add r1, r3, r1 */
/* @0x24b34c cmp r1, #1 */
/* @0x24b350 bgt 0x24b3b0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa14> */
/* @0x24b354 cmp r3, #0 */
/* @0x24b358 add r2, r2, #2 */
/* @0x24b35c addne r3, r3, r3, lsl #1 */
/* @0x24b360 ldr r7, [r8] */
/* @0x24b364 moveq r4, #3 */
/* @0x24b368 addne r3, r3, r3, lsr #31 */
/* @0x24b36c asrne r4, r3, #1 */
/* @0x24b370 cmp r2, r4 */
/* @0x24b374 addgt r2, r2, r2, lsl #1 */
/* @0x24b378 addgt r2, r2, r2, lsr #31 */
/* @0x24b37c asrgt r4, r2, #1 */
/* @0x24b380 mov r0, r4 */
/* @0x24b384 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b388 ldr r2, [r8, #0x4] */
/* @0x24b38c mov r1, r7 */
/* @0x24b390 str r0, [r8] */
/* @0x24b394 bl 0xb65bc <memcpy@plt> */
/* @0x24b398 cmp r7, #0 */
/* @0x24b39c str r4, [r8, #0x4] */
/* @0x24b3a0 beq 0x24b3ac <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa10> */
/* @0x24b3a4 mov r0, r7 */
/* @0x24b3a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b3ac ldr r2, [r8, #0x8] */
/* @0x24b3b0 ldr r3, [r8] */
/* @0x24b3b4 cmp r10, r6 */
/* @0x24b3b8 add r1, r3, r2 */
/* @0x24b3bc strb r5, [r3, r2] */
/* @0x24b3c0 strb r9, [r1, #0x1] */
/* @0x24b3c4 ldr r2, [r8, #0x8] */
/* @0x24b3c8 add r2, r2, #1 */
/* @0x24b3cc str r2, [r8, #0x8] */
/* @0x24b3d0 bne 0x24b33c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x9a0> */
/* @0x24b3d4 ldr r4, [r11, #-0x6c] */
/* @0x24b3d8 b 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b3dc ldr r7, [r11, #-0x5c] */
/* @0x24b3e0 sub r6, r6, #48 */
/* @0x24b3e4 add r5, r4, #1 */
/* @0x24b3e8 ldr r3, [r7] */
/* @0x24b3ec cmp r3, #9 */
/* @0x24b3f0 ble 0x24b41c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa80> */
/* @0x24b3f4 ldr r2, [pc, #0x534] */
/* @0x24b3f8 ldrb r1, [r4, #0x3] */
/* @0x24b3fc ldr r2, [pc, r2] */
/* @0x24b400 ldr r2, [r2] */
/* @0x24b404 add r2, r2, r1 */
/* @0x24b408 ldrb r2, [r2, #0x1] */
/* @0x24b40c tst r2, #4 */
/* @0x24b410 beq 0x24b424 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xa88> */
/* @0x24b414 sub r6, r1, #48 */
/* @0x24b418 add r5, r4, #2 */
/* @0x24b41c cmp r6, r3 */
/* @0x24b420 bge 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b424 ldr r7, [r11, #-0x5c] */
/* @0x24b428 add r6, r6, r6, lsl #1 */
/* @0x24b42c ldr r3, [r7, #0x4] */
/* @0x24b430 add r3, r3, r6, lsl #2 */
/* @0x24b434 ldr r6, [r3, #0x8] */
/* @0x24b438 cmp r6, #0 */
/* @0x24b43c beq 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b440 mov r0, r6 */
/* @0x24b444 bl 0xb6538 <strlen@plt> */
/* @0x24b448 ldr r2, [r8, #0x8] */
/* @0x24b44c ldr r3, [r8, #0x4] */
/* @0x24b450 add r1, r0, #1 */
/* @0x24b454 mov r4, r0 */
/* @0x24b458 mvn r0, r2 */
/* @0x24b45c add r0, r3, r0 */
/* @0x24b460 cmp r1, r0 */
/* @0x24b464 ble 0x24b4cc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb30> */
/* @0x24b468 cmp r3, #0 */
/* @0x24b46c add r2, r1, r2 */
/* @0x24b470 ldr r7, [r8] */
/* @0x24b474 moveq r3, r1 */
/* @0x24b478 add r3, r3, r3, lsl #1 */
/* @0x24b47c add r3, r3, r3, lsr #31 */
/* @0x24b480 asr r3, r3, #1 */
/* @0x24b484 cmp r3, r2 */
/* @0x24b488 addlt r2, r2, r2, lsl #1 */
/* @0x24b48c addlt r2, r2, r2, lsr #31 */
/* @0x24b490 asrlt r3, r2, #1 */
/* @0x24b494 str r3, [r11, #-0xa8] */
/* @0x24b498 mov r0, r3 */
/* @0x24b49c bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b4a0 ldr r2, [r8, #0x4] */
/* @0x24b4a4 mov r1, r7 */
/* @0x24b4a8 str r0, [r8] */
/* @0x24b4ac bl 0xb65bc <memcpy@plt> */
/* @0x24b4b0 ldr r3, [r11, #-0xa8] */
/* @0x24b4b4 cmp r7, #0 */
/* @0x24b4b8 str r3, [r8, #0x4] */
/* @0x24b4bc beq 0x24b4c8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb2c> */
/* @0x24b4c0 mov r0, r7 */
/* @0x24b4c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b4c8 ldr r2, [r8, #0x8] */
/* @0x24b4cc ldr r0, [r8] */
/* @0x24b4d0 mov r1, r6 */
/* @0x24b4d4 add r0, r0, r2 */
/* @0x24b4d8 bl 0xb65a4 <strcpy@plt> */
/* @0x24b4dc ldr r3, [r8, #0x8] */
/* @0x24b4e0 add r3, r3, r4 */
/* @0x24b4e4 str r3, [r8, #0x8] */
/* @0x24b4e8 ldrb r6, [r5, #0x1] */
/* @0x24b4ec add r4, r5, #1 */
/* @0x24b4f0 cmp r6, #0 */
/* @0x24b4f4 bne 0x24b20c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x870> */
/* @0x24b4f8 ldr r3, [r11, #-0x68] */
/* @0x24b4fc ldr r7, [r11, #-0x54] */
/* @0x24b500 cmp r3, r7 */
/* @0x24b504 ble 0x24b5b8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xc1c> */
/* @0x24b508 ldr r7, [r11, #-0x50] */
/* @0x24b50c ldr r3, [r11, #-0x54] */
/* @0x24b510 ldr r2, [r8, #0x8] */
/* @0x24b514 add r10, r7, r3 */
/* @0x24b518 ldr r3, [r11, #-0x68] */
/* @0x24b51c add r5, r7, r3 */
/* @0x24b520 ldr r3, [r8, #0x4] */
/* @0x24b524 mvn r1, r2 */
/* @0x24b528 ldrb r4, [r10], #1 */
/* @0x24b52c add r1, r3, r1 */
/* @0x24b530 cmp r1, #1 */
/* @0x24b534 bgt 0x24b594 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xbf8> */
/* @0x24b538 cmp r3, #0 */
/* @0x24b53c add r2, r2, #2 */
/* @0x24b540 addne r3, r3, r3, lsl #1 */
/* @0x24b544 ldr r6, [r8] */
/* @0x24b548 moveq r7, #3 */
/* @0x24b54c addne r3, r3, r3, lsr #31 */
/* @0x24b550 asrne r7, r3, #1 */
/* @0x24b554 cmp r2, r7 */
/* @0x24b558 addgt r2, r2, r2, lsl #1 */
/* @0x24b55c addgt r2, r2, r2, lsr #31 */
/* @0x24b560 asrgt r7, r2, #1 */
/* @0x24b564 mov r0, r7 */
/* @0x24b568 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b56c ldr r2, [r8, #0x4] */
/* @0x24b570 mov r1, r6 */
/* @0x24b574 str r0, [r8] */
/* @0x24b578 bl 0xb65bc <memcpy@plt> */
/* @0x24b57c cmp r6, #0 */
/* @0x24b580 str r7, [r8, #0x4] */
/* @0x24b584 beq 0x24b590 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xbf4> */
/* @0x24b588 mov r0, r6 */
/* @0x24b58c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b590 ldr r2, [r8, #0x8] */
/* @0x24b594 ldr r3, [r8] */
/* @0x24b598 cmp r10, r5 */
/* @0x24b59c add r1, r3, r2 */
/* @0x24b5a0 strb r4, [r3, r2] */
/* @0x24b5a4 strb r9, [r1, #0x1] */
/* @0x24b5a8 ldr r2, [r8, #0x8] */
/* @0x24b5ac add r2, r2, #1 */
/* @0x24b5b0 str r2, [r8, #0x8] */
/* @0x24b5b4 bne 0x24b520 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xb84> */
/* @0x24b5b8 ldr r3, [r11, #-0x58] */
/* @0x24b5bc ldr r7, [r11, #0x10] */
/* @0x24b5c0 cmp r3, r7 */
/* @0x24b5c4 beq 0x24ae84 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x4e8> */
/* @0x24b5c8 mov r2, #0 */
/* @0x24b5cc b 0x24b004 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x668> */
/* @0x24b5d0 ldr r7, [r11, #-0x5c] */
/* @0x24b5d4 ldr r3, [r7, #0x4] */
/* @0x24b5d8 ldr r10, [r3, #0x8] */
/* @0x24b5dc cmp r10, #0 */
/* @0x24b5e0 beq 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b5e4 mov r0, r10 */
/* @0x24b5e8 bl 0xb6538 <strlen@plt> */
/* @0x24b5ec ldr r2, [r8, #0x4] */
/* @0x24b5f0 mov r5, r0 */
/* @0x24b5f4 ldr r0, [r8, #0x8] */
/* @0x24b5f8 add r1, r5, #1 */
/* @0x24b5fc mvn r12, r0 */
/* @0x24b600 add r12, r2, r12 */
/* @0x24b604 cmp r1, r12 */
/* @0x24b608 ble 0x24b670 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcd4> */
/* @0x24b60c cmp r2, #0 */
/* @0x24b610 ldr r6, [r8] */
/* @0x24b614 moveq r2, r1 */
/* @0x24b618 add r1, r1, r0 */
/* @0x24b61c add r2, r2, r2, lsl #1 */
/* @0x24b620 add r2, r2, r2, lsr #31 */
/* @0x24b624 asr r12, r2, #1 */
/* @0x24b628 cmp r12, r1 */
/* @0x24b62c addlt r1, r1, r1, lsl #1 */
/* @0x24b630 addlt r1, r1, r1, lsr #31 */
/* @0x24b634 asrlt r12, r1, #1 */
/* @0x24b638 str r12, [r11, #-0xa8] */
/* @0x24b63c mov r0, r12 */
/* @0x24b640 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b644 ldr r2, [r8, #0x4] */
/* @0x24b648 mov r1, r6 */
/* @0x24b64c str r0, [r8] */
/* @0x24b650 bl 0xb65bc <memcpy@plt> */
/* @0x24b654 ldr r12, [r11, #-0xa8] */
/* @0x24b658 cmp r6, #0 */
/* @0x24b65c str r12, [r8, #0x4] */
/* @0x24b660 beq 0x24b66c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcd0> */
/* @0x24b664 mov r0, r6 */
/* @0x24b668 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b66c ldr r0, [r8, #0x8] */
/* @0x24b670 ldr r2, [r8] */
/* @0x24b674 mov r1, r10 */
/* @0x24b678 add r0, r2, r0 */
/* @0x24b67c bl 0xb65a4 <strcpy@plt> */
/* @0x24b680 ldr r3, [r8, #0x8] */
/* @0x24b684 add r5, r3, r5 */
/* @0x24b688 str r5, [r8, #0x8] */
/* @0x24b68c add r5, r4, #1 */
/* @0x24b690 b 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b694 ldr r7, [r11, #-0x98] */
/* @0x24b698 ldr r3, [r11, #-0x54] */
/* @0x24b69c cmp r7, r3 */
/* @0x24b6a0 ble 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b6a4 ldr r10, [r11, #-0x54] */
/* @0x24b6a8 str r4, [r11, #-0x6c] */
/* @0x24b6ac ldr r2, [r8, #0x8] */
/* @0x24b6b0 mov r4, r10 */
/* @0x24b6b4 ldr r10, [r11, #-0x98] */
/* @0x24b6b8 ldr r12, [r8, #0x4] */
/* @0x24b6bc mvn r1, r2 */
/* @0x24b6c0 ldr r7, [r11, #-0x50] */
/* @0x24b6c4 add r1, r12, r1 */
/* @0x24b6c8 cmp r1, #1 */
/* @0x24b6cc ldrb r6, [r7, r4] */
/* @0x24b6d0 bgt 0x24b730 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xd94> */
/* @0x24b6d4 cmp r12, #0 */
/* @0x24b6d8 add r2, r2, #2 */
/* @0x24b6dc addne r12, r12, r12, lsl #1 */
/* @0x24b6e0 ldr r5, [r8] */
/* @0x24b6e4 moveq r7, #3 */
/* @0x24b6e8 addne r12, r12, r12, lsr #31 */
/* @0x24b6ec asrne r7, r12, #1 */
/* @0x24b6f0 cmp r2, r7 */
/* @0x24b6f4 addgt r2, r2, r2, lsl #1 */
/* @0x24b6f8 addgt r2, r2, r2, lsr #31 */
/* @0x24b6fc asrgt r7, r2, #1 */
/* @0x24b700 mov r0, r7 */
/* @0x24b704 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b708 ldr r2, [r8, #0x4] */
/* @0x24b70c mov r1, r5 */
/* @0x24b710 str r0, [r8] */
/* @0x24b714 bl 0xb65bc <memcpy@plt> */
/* @0x24b718 cmp r5, #0 */
/* @0x24b71c str r7, [r8, #0x4] */
/* @0x24b720 beq 0x24b72c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xd90> */
/* @0x24b724 mov r0, r5 */
/* @0x24b728 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b72c ldr r2, [r8, #0x8] */
/* @0x24b730 ldr r1, [r8] */
/* @0x24b734 add r4, r4, #1 */
/* @0x24b738 cmp r10, r4 */
/* @0x24b73c add r0, r1, r2 */
/* @0x24b740 strb r6, [r1, r2] */
/* @0x24b744 strb r9, [r0, #0x1] */
/* @0x24b748 ldr r2, [r8, #0x8] */
/* @0x24b74c add r2, r2, #1 */
/* @0x24b750 str r2, [r8, #0x8] */
/* @0x24b754 bne 0x24b6b8 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xd1c> */
/* @0x24b758 ldr r4, [r11, #-0x6c] */
/* @0x24b75c b 0x24b68c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xcf0> */
/* @0x24b760 ldmib r8, {r2, r3} */
/* @0x24b764 mvn r1, r3 */
/* @0x24b768 add r1, r2, r1 */
/* @0x24b76c cmp r1, #1 */
/* @0x24b770 bgt 0x24b7d0 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe34> */
/* @0x24b774 cmp r2, #0 */
/* @0x24b778 add r3, r3, #2 */
/* @0x24b77c addne r2, r2, r2, lsl #1 */
/* @0x24b780 ldr r5, [r8] */
/* @0x24b784 moveq r6, #3 */
/* @0x24b788 addne r2, r2, r2, lsr #31 */
/* @0x24b78c asrne r6, r2, #1 */
/* @0x24b790 cmp r3, r6 */
/* @0x24b794 addgt r3, r3, r3, lsl #1 */
/* @0x24b798 addgt r3, r3, r3, lsr #31 */
/* @0x24b79c asrgt r6, r3, #1 */
/* @0x24b7a0 mov r0, r6 */
/* @0x24b7a4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b7a8 ldr r2, [r8, #0x4] */
/* @0x24b7ac mov r1, r5 */
/* @0x24b7b0 str r0, [r8] */
/* @0x24b7b4 bl 0xb65bc <memcpy@plt> */
/* @0x24b7b8 cmp r5, #0 */
/* @0x24b7bc str r6, [r8, #0x4] */
/* @0x24b7c0 beq 0x24b7cc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xe30> */
/* @0x24b7c4 mov r0, r5 */
/* @0x24b7c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b7cc ldr r3, [r8, #0x8] */
/* @0x24b7d0 ldr r7, [r11, #-0x7c] */
/* @0x24b7d4 add r5, r4, #1 */
/* @0x24b7d8 ldr r2, [r8] */
/* @0x24b7dc ldrh r1, [r7] */
/* @0x24b7e0 strh r1, [r2, r3] */
/* @0x24b7e4 ldr r3, [r8, #0x8] */
/* @0x24b7e8 add r3, r3, #1 */
/* @0x24b7ec str r3, [r8, #0x8] */
/* @0x24b7f0 b 0x24b1fc <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x860> */
/* @0x24b7f4 ldr r2, [r8, #0x8] */
/* @0x24b7f8 ldr r3, [r8, #0x4] */
/* @0x24b7fc mvn r1, r2 */
/* @0x24b800 add r1, r3, r1 */
/* @0x24b804 cmp r1, #1 */
/* @0x24b808 bgt 0x24b870 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xed4> */
/* @0x24b80c cmp r3, #0 */
/* @0x24b810 add r2, r2, #2 */
/* @0x24b814 addne r3, r3, r3, lsl #1 */
/* @0x24b818 ldr r5, [r8] */
/* @0x24b81c moveq r3, #3 */
/* @0x24b820 addne r3, r3, r3, lsr #31 */
/* @0x24b824 asrne r3, r3, #1 */
/* @0x24b828 cmp r2, r3 */
/* @0x24b82c addgt r2, r2, r2, lsl #1 */
/* @0x24b830 addgt r2, r2, r2, lsr #31 */
/* @0x24b834 asrgt r3, r2, #1 */
/* @0x24b838 str r3, [r11, #-0xa8] */
/* @0x24b83c mov r0, r3 */
/* @0x24b840 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b844 ldr r2, [r8, #0x4] */
/* @0x24b848 mov r1, r5 */
/* @0x24b84c str r0, [r8] */
/* @0x24b850 bl 0xb65bc <memcpy@plt> */
/* @0x24b854 ldr r3, [r11, #-0xa8] */
/* @0x24b858 cmp r5, #0 */
/* @0x24b85c str r3, [r8, #0x4] */
/* @0x24b860 beq 0x24b86c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xed0> */
/* @0x24b864 mov r0, r5 */
/* @0x24b868 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b86c ldr r2, [r8, #0x8] */
/* @0x24b870 ldr r3, [r8] */
/* @0x24b874 mov r0, #36 */
/* @0x24b878 add r1, r3, r2 */
/* @0x24b87c strb r0, [r3, r2] */
/* @0x24b880 strb r9, [r1, #0x1] */
/* @0x24b884 ldr r1, [r8, #0x8] */
/* @0x24b888 ldr r2, [r8, #0x4] */
/* @0x24b88c add r3, r1, #1 */
/* @0x24b890 str r3, [r8, #0x8] */
/* @0x24b894 mvn r0, r3 */
/* @0x24b898 add r0, r2, r0 */
/* @0x24b89c cmp r0, #1 */
/* @0x24b8a0 bgt 0x24b908 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf6c> */
/* @0x24b8a4 cmp r2, #0 */
/* @0x24b8a8 add r1, r1, #3 */
/* @0x24b8ac addne r2, r2, r2, lsl #1 */
/* @0x24b8b0 ldr r5, [r8] */
/* @0x24b8b4 moveq r3, #3 */
/* @0x24b8b8 addne r2, r2, r2, lsr #31 */
/* @0x24b8bc asrne r3, r2, #1 */
/* @0x24b8c0 cmp r1, r3 */
/* @0x24b8c4 addgt r1, r1, r1, lsl #1 */
/* @0x24b8c8 addgt r1, r1, r1, lsr #31 */
/* @0x24b8cc asrgt r3, r1, #1 */
/* @0x24b8d0 str r3, [r11, #-0xa8] */
/* @0x24b8d4 mov r0, r3 */
/* @0x24b8d8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x24b8dc ldr r2, [r8, #0x4] */
/* @0x24b8e0 mov r1, r5 */
/* @0x24b8e4 str r0, [r8] */
/* @0x24b8e8 bl 0xb65bc <memcpy@plt> */
/* @0x24b8ec ldr r3, [r11, #-0xa8] */
/* @0x24b8f0 cmp r5, #0 */
/* @0x24b8f4 str r3, [r8, #0x4] */
/* @0x24b8f8 beq 0x24b904 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0xf68> */
/* @0x24b8fc mov r0, r5 */
/* @0x24b900 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24b904 ldr r3, [r8, #0x8] */
/* @0x24b908 ldr r2, [r8] */
/* @0x24b90c add r5, r4, #1 */
/* @0x24b910 b 0x24b1e4 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x848> */
/* @0x24b914 ldr r3, [r11, #-0x54] */
/* @0x24b918 str r3, [r11, #-0x74] */
/* @0x24b91c b 0x24b148 <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii+0x7ac> */
/* @0x24b920 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24b924 andseq r2, r10, r12, ror pc */
/* @0x24b928 andseq r3, r10, r8, ror #4 */
/* @0x24b92c andseq r10, r0, r4, lsl #29 */
/* @0x24b930 andseq r2, r10, r4, lsl #11 */

/* ── FUNC 0x24b934 · F_JS_Array_setLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=460 · insn=115 */
/* @0x24b934 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24b938 sub sp, sp, #12 */
/* @0x24b93c mov r4, r1 */
/* @0x24b940 mov r1, #0 */
/* @0x24b944 ldr r0, [sp, #0x30] */
/* @0x24b948 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x24b94c ldr r1, [pc, #0x1a0] */
/* @0x24b950 add r1, pc, r1 */
/* @0x24b954 mov r7, r0 */
/* @0x24b958 ldr r0, [r4, #0x40] */
/* @0x24b95c bl 0xb6574 <strcmp@plt> */
/* @0x24b960 cmp r0, #0 */
/* @0x24b964 bne 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x24b968 ldr r3, [r4, #0x4] */
/* @0x24b96c cmp r3, #0 */
/* @0x24b970 beq 0x24babc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x24b974 add r0, r3, #16 */
/* @0x24b978 ldr r3, [r0, #0xc] */
/* @0x24b97c cmp r3, #6 */
/* @0x24b980 beq 0x24b98c <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x24b984 add sp, sp, #12 */
/* @0x24b988 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24b98c ldr r10, [r0] */
/* @0x24b990 ldr r6, [r10, #0x2c] */
/* @0x24b994 subs r4, r7, r6 */
/* @0x24b998 sbc r5, r7, r7 */
/* @0x24b99c cmp r4, #0 */
/* @0x24b9a0 sbcs r0, r5, #0 */
/* @0x24b9a4 blt 0x24ba20 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x24b9a8 orrs r0, r4, r5 */
/* @0x24b9ac beq 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x24b9b0 ldr r2, [pc, #0x140] */
/* @0x24b9b4 mov r3, #0 */
/* @0x24b9b8 ldr r0, [r10, #0x4] */
/* @0x24b9bc lsl r1, r7, #4 */
/* @0x24b9c0 str r3, [sp] */
/* @0x24b9c4 add r2, pc, r2 */
/* @0x24b9c8 mov r3, #74 */
/* @0x24b9cc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x24b9d0 cmp r4, #1 */
/* @0x24b9d4 sbcs r3, r5, #0 */
/* @0x24b9d8 str r7, [r10, #0x2c] */
/* @0x24b9dc str r0, [r10, #0x4] */
/* @0x24b9e0 blt 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x24b9e4 cmp r0, #0 */
/* @0x24b9e8 beq 0x24bacc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x24b9ec add r0, r0, r6, lsl #4 */
/* @0x24b9f0 add r3, r0, #16 */
/* @0x24b9f4 mov r1, #5 */
/* @0x24b9f8 mov r2, #0 */
/* @0x24b9fc subs r4, r4, #1 */
/* @0x24ba00 str r1, [r3, #-0x4] */
/* @0x24ba04 sbc r5, r5, #0 */
/* @0x24ba08 str r2, [r3, #-0x10] */
/* @0x24ba0c orrs r0, r4, r5 */
/* @0x24ba10 add r3, r3, #16 */
/* @0x24ba14 bne 0x24b9fc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x24ba18 add sp, sp, #12 */
/* @0x24ba1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24ba20 ldr r6, [r10, #0x4] */
/* @0x24ba24 cmp r6, #0 */
/* @0x24ba28 beq 0x24badc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x24ba2c lsl r9, r7, #4 */
/* @0x24ba30 add r6, r6, r9 */
/* @0x24ba34 rsbs r4, r4, #0 */
/* @0x24ba38 rsc r5, r5, #0 */
/* @0x24ba3c mov r8, #0 */
/* @0x24ba40 mvn r11, #-16777216 */
/* @0x24ba44 b 0x24ba6c <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x24ba48 subs r4, r4, #1 */
/* @0x24ba4c str r8, [r6, #0x8] */
/* @0x24ba50 sbc r5, r5, #0 */
/* @0x24ba54 str r8, [r6] */
/* @0x24ba58 orrs r3, r4, r5 */
/* @0x24ba5c str r11, [r6, #0xc] */
/* @0x24ba60 mov r2, #0 */
/* @0x24ba64 add r6, r6, #16 */
/* @0x24ba68 beq 0x24ba90 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x24ba6c ldr r3, [r6, #0xc] */
/* @0x24ba70 sub r3, r3, #1 */
/* @0x24ba74 bic r3, r3, #-16777216 */
/* @0x24ba78 bic r3, r3, #3 */
/* @0x24ba7c cmp r3, #0 */
/* @0x24ba80 bne 0x24ba48 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x24ba84 mov r0, r6 */
/* @0x24ba88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24ba8c b 0x24ba48 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x24ba90 ldr r0, [r10, #0x4] */
/* @0x24ba94 mov r1, r9 */
/* @0x24ba98 str r7, [r10, #0x24] */
/* @0x24ba9c mov r3, #74 */
/* @0x24baa0 str r2, [sp] */
/* @0x24baa4 ldr r2, [pc, #0x50] */
/* @0x24baa8 add r2, pc, r2 */
/* @0x24baac bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x24bab0 str r7, [r10, #0x2c] */
/* @0x24bab4 str r0, [r10, #0x4] */
/* @0x24bab8 b 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x24babc mov r0, r4 */
/* @0x24bac0 mov r1, #1 */
/* @0x24bac4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24bac8 b 0x24b978 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x24bacc mov r0, r10 */
/* @0x24bad0 mov r1, r6 */
/* @0x24bad4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24bad8 b 0x24b9f0 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24badc mov r0, r10 */
/* @0x24bae0 mov r1, r7 */
/* @0x24bae4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24bae8 lsl r9, r7, #4 */
/* @0x24baec mov r6, r0 */
/* @0x24baf0 b 0x24ba34 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x24baf4 andeq r8, lr, r8, asr #31 */
/* @0x24baf8 andeq r5, lr, r12, ror #12 */
/* @0x24bafc andeq r5, lr, r8, lsl #11 */

/* ── FUNC 0x24bb00 · JS_Array_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*) · size=544 · insn=136 */
/* @0x24bb00 ldr r12, [pc, #0x20c] */
/* @0x24bb04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24bb08 ldr r12, [pc, r12] */
/* @0x24bb0c sub sp, sp, #132 */
/* @0x24bb10 mov r7, #0 */
/* @0x24bb14 mov r4, r3 */
/* @0x24bb18 mov r3, r7 */
/* @0x24bb1c str r12, [sp, #0x10] */
/* @0x24bb20 mov r5, r1 */
/* @0x24bb24 ldr r12, [r12] */
/* @0x24bb28 add r8, sp, #28 */
/* @0x24bb2c str r7, [sp] */
/* @0x24bb30 str r0, [sp, #0x14] */
/* @0x24bb34 str r12, [sp, #0x7c] */
/* @0x24bb38 ldr r6, [sp, #0xa8] */
/* @0x24bb3c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x24bb40 ldr r2, [pc, #0x1d0] */
/* @0x24bb44 mov r0, r5 */
/* @0x24bb48 mov r1, r8 */
/* @0x24bb4c mvn r3, #-16777216 */
/* @0x24bb50 add r2, pc, r2 */
/* @0x24bb54 str r3, [sp, #0x28] */
/* @0x24bb58 str r7, [sp, #0x1c] */
/* @0x24bb5c str r7, [sp, #0x20] */
/* @0x24bb60 str r7, [sp, #0x24] */
/* @0x24bb64 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24bb68 mov r0, r8 */
/* @0x24bb6c mov r1, r7 */
/* @0x24bb70 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x24bb74 cmp r4, r7 */
/* @0x24bb78 mov r9, r0 */
/* @0x24bb7c ble 0x24bba8 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x24bb80 mov r1, r7 */
/* @0x24bb84 mov r0, r6 */
/* @0x24bb88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x24bb8c cmp r0, #0 */
/* @0x24bb90 movge r2, r0 */
/* @0x24bb94 asrge r3, r2, #31 */
/* @0x24bb98 bge 0x24bbb0 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x24bb9c add r7, r0, r9 */
/* @0x24bba0 bic r7, r7, r7, asr #31 */
/* @0x24bba4 b 0x24bbc8 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x24bba8 mov r2, #0 */
/* @0x24bbac mov r3, #0 */
/* @0x24bbb0 mov r10, r9 */
/* @0x24bbb4 mov r11, #0 */
/* @0x24bbb8 cmp r10, r2 */
/* @0x24bbbc sbcs r1, r11, r3 */
/* @0x24bbc0 movlt r2, r9 */
/* @0x24bbc4 mov r7, r2 */
/* @0x24bbc8 cmp r4, #1 */
/* @0x24bbcc movle r0, r9 */
/* @0x24bbd0 ble 0x24bbe0 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x24bbd4 mov r0, r6 */
/* @0x24bbd8 mov r1, #1 */
/* @0x24bbdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x24bbe0 cmp r0, #0 */
/* @0x24bbe4 addlt r8, r0, r9 */
/* @0x24bbe8 biclt r8, r8, r8, asr #31 */
/* @0x24bbec blt 0x24bc0c <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x24bbf0 mov r2, r9 */
/* @0x24bbf4 asr r9, r0, #31 */
/* @0x24bbf8 mov r8, r0 */
/* @0x24bbfc mov r3, #0 */
/* @0x24bc00 cmp r2, r8 */
/* @0x24bc04 sbcs r12, r3, r9 */
/* @0x24bc08 movlt r8, r2 */
/* @0x24bc0c cmp r7, r8 */
/* @0x24bc10 bhs 0x24bcf4 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x24bc14 ldr r6, [pc, #0x100] */
/* @0x24bc18 add r12, sp, #92 */
/* @0x24bc1c add r4, sp, #60 */
/* @0x24bc20 str r12, [sp, #0xc] */
/* @0x24bc24 add r6, pc, r6 */
/* @0x24bc28 add r10, sp, #44 */
/* @0x24bc2c mov r11, r7 */
/* @0x24bc30 mov r9, #0 */
/* @0x24bc34 b 0x24bc44 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x24bc38 add r11, r11, #1 */
/* @0x24bc3c cmp r8, r11 */
/* @0x24bc40 bls 0x24bcf4 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x24bc44 mov r3, r11 */
/* @0x24bc48 mov r1, #32 */
/* @0x24bc4c mov r2, r6 */
/* @0x24bc50 mov r0, r4 */
/* @0x24bc54 bl 0xb65c8 <snprintf@plt> */
/* @0x24bc58 mov r0, r5 */
/* @0x24bc5c mov r1, r4 */
/* @0x24bc60 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x24bc64 rsb r3, r7, r11 */
/* @0x24bc68 cmp r0, #0 */
/* @0x24bc6c beq 0x24bc38 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x24bc70 mov r1, #32 */
/* @0x24bc74 mov r2, r6 */
/* @0x24bc78 add r0, sp, #92 */
/* @0x24bc7c bl 0xb65c8 <snprintf@plt> */
/* @0x24bc80 mov r0, r5 */
/* @0x24bc84 mov r1, r10 */
/* @0x24bc88 mov r2, r4 */
/* @0x24bc8c mvn lr, #-16777216 */
/* @0x24bc90 str r9, [sp, #0x2c] */
/* @0x24bc94 str lr, [sp, #0x38] */
/* @0x24bc98 str r9, [sp, #0x30] */
/* @0x24bc9c str r9, [sp, #0x34] */
/* @0x24bca0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24bca4 ldr r12, [sp, #0x14] */
/* @0x24bca8 mov r3, #0 */
/* @0x24bcac ldr lr, [sp, #0x34] */
/* @0x24bcb0 add r1, sp, #92 */
/* @0x24bcb4 mov r2, r10 */
/* @0x24bcb8 ldr r0, [r12] */
/* @0x24bcbc orr lr, lr, #7 */
/* @0x24bcc0 str lr, [sp, #0x34] */
/* @0x24bcc4 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x24bcc8 ldr r3, [sp, #0x38] */
/* @0x24bccc sub r3, r3, #1 */
/* @0x24bcd0 bic r3, r3, #-16777216 */
/* @0x24bcd4 bic r3, r3, #3 */
/* @0x24bcd8 cmp r3, #0 */
/* @0x24bcdc bne 0x24bc38 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x24bce0 mov r0, r10 */
/* @0x24bce4 add r11, r11, #1 */
/* @0x24bce8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24bcec cmp r8, r11 */
/* @0x24bcf0 bhi 0x24bc44 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x24bcf4 ldr r12, [sp, #0x10] */
/* @0x24bcf8 ldr r2, [sp, #0x7c] */
/* @0x24bcfc ldr r3, [r12] */
/* @0x24bd00 cmp r2, r3 */
/* @0x24bd04 bne 0x24bd10 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x24bd08 add sp, sp, #132 */
/* @0x24bd0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24bd10 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24bd14 andseq r1, r10, r8, asr #28 */
/* @0x24bd18 andeq r4, lr, r12, lsl sp */
/* @0x24bd1c andseq r10, r0, r12, lsr r2 */

/* ── FUNC 0x24bd20 · json_parse_to_object(json_object*, RValue&) · size=396 · insn=99 */
/* @0x24bd20 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24bd24 sub sp, sp, #76 */
/* @0x24bd28 mov r5, #0 */
/* @0x24bd2c mov r9, r1 */
/* @0x24bd30 str r0, [sp, #0x24] */
/* @0x24bd34 mov r2, r5 */
/* @0x24bd38 mov r0, r1 */
/* @0x24bd3c mov r3, r5 */
/* @0x24bd40 mov r1, r5 */
/* @0x24bd44 str r5, [sp] */
/* @0x24bd48 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x24bd4c ldr r0, [sp, #0x24] */
/* @0x24bd50 bl 0x27e8f4 <json_object_get_object> */
/* @0x24bd54 ldr r4, [r0, #0x20] */
/* @0x24bd58 cmp r4, r5 */
/* @0x24bd5c beq 0x24be98 <_Z20json_parse_to_objectP11json_objectR6RValue+0x178> */
/* @0x24bd60 add r8, sp, #40 */
/* @0x24bd64 add r2, sp, #44 */
/* @0x24bd68 add r3, sp, #48 */
/* @0x24bd6c mov r11, r5 */
/* @0x24bd70 str r2, [sp, #0x18] */
/* @0x24bd74 add r5, sp, #56 */
/* @0x24bd78 add r2, sp, #52 */
/* @0x24bd7c str r3, [sp, #0x1c] */
/* @0x24bd80 str r2, [sp, #0x20] */
/* @0x24bd84 add r3, sp, #60 */
/* @0x24bd88 add r2, sp, #64 */
/* @0x24bd8c str r3, [sp, #0xc] */
/* @0x24bd90 mov r7, r8 */
/* @0x24bd94 add r3, sp, #68 */
/* @0x24bd98 str r2, [sp, #0x10] */
/* @0x24bd9c str r3, [sp, #0x14] */
/* @0x24bda0 b 0x24be20 <_Z20json_parse_to_objectP11json_objectR6RValue+0x100> */
/* @0x24bda4 bl 0x27e828 <json_object_get_type> */
/* @0x24bda8 cmp r0, #5 */
/* @0x24bdac beq 0x24be70 <_Z20json_parse_to_objectP11json_objectR6RValue+0x150> */
/* @0x24bdb0 mov r0, r10 */
/* @0x24bdb4 mov r1, r5 */
/* @0x24bdb8 bl 0x24beac <_Z10json_parseP11json_objectR6RValue> */
/* @0x24bdbc ldr r1, [sp, #0x28] */
/* @0x24bdc0 mov r3, #7 */
/* @0x24bdc4 ldr r0, [r9] */
/* @0x24bdc8 mov r2, r5 */
/* @0x24bdcc ldr r1, [r1] */
/* @0x24bdd0 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x24bdd4 ldr r3, [sp, #0x34] */
/* @0x24bdd8 sub r3, r3, #1 */
/* @0x24bddc bic r3, r3, #-16777216 */
/* @0x24bde0 bic r3, r3, #3 */
/* @0x24bde4 cmp r3, #0 */
/* @0x24bde8 beq 0x24bea0 <_Z20json_parse_to_objectP11json_objectR6RValue+0x180> */
/* @0x24bdec ldr r3, [sp, #0x44] */
/* @0x24bdf0 mov r2, #5 */
/* @0x24bdf4 str r11, [sp, #0x30] */
/* @0x24bdf8 sub r3, r3, #1 */
/* @0x24bdfc str r2, [sp, #0x34] */
/* @0x24be00 bic r3, r3, #-16777216 */
/* @0x24be04 str r11, [sp, #0x28] */
/* @0x24be08 bic r3, r3, #3 */
/* @0x24be0c cmp r3, #0 */
/* @0x24be10 beq 0x24be84 <_Z20json_parse_to_objectP11json_objectR6RValue+0x164> */
/* @0x24be14 ldr r4, [r4, #0x8] */
/* @0x24be18 cmp r4, #0 */
/* @0x24be1c beq 0x24be98 <_Z20json_parse_to_objectP11json_objectR6RValue+0x178> */
/* @0x24be20 ldr r6, [r4] */
/* @0x24be24 mov r0, r7 */
/* @0x24be28 ldr r10, [r4, #0x4] */
/* @0x24be2c str r11, [r8] */
/* @0x24be30 mov r8, r7 */
/* @0x24be34 mov r1, r6 */
/* @0x24be38 str r11, [sp, #0x2c] */
/* @0x24be3c str r11, [sp, #0x30] */
/* @0x24be40 str r11, [sp, #0x34] */
/* @0x24be44 str r11, [r5] */
/* @0x24be48 str r11, [sp, #0x3c] */
/* @0x24be4c str r11, [sp, #0x40] */
/* @0x24be50 str r11, [sp, #0x44] */
/* @0x24be54 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x24be58 subs r0, r10, #0 */
/* @0x24be5c beq 0x24bdb0 <_Z20json_parse_to_objectP11json_objectR6RValue+0x90> */
/* @0x24be60 bl 0x27e828 <json_object_get_type> */
/* @0x24be64 cmp r0, #4 */
/* @0x24be68 mov r0, r10 */
/* @0x24be6c bne 0x24bda4 <_Z20json_parse_to_objectP11json_objectR6RValue+0x84> */
/* @0x24be70 mov r1, r6 */
/* @0x24be74 ldr r0, [sp, #0x24] */
/* @0x24be78 bl 0x27ea38 <json_object_object_get> */
/* @0x24be7c mov r10, r0 */
/* @0x24be80 b 0x24bdb0 <_Z20json_parse_to_objectP11json_objectR6RValue+0x90> */
/* @0x24be84 mov r0, r5 */
/* @0x24be88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24be8c ldr r4, [r4, #0x8] */
/* @0x24be90 cmp r4, #0 */
/* @0x24be94 bne 0x24be20 <_Z20json_parse_to_objectP11json_objectR6RValue+0x100> */
/* @0x24be98 add sp, sp, #76 */
/* @0x24be9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24bea0 mov r0, r7 */
/* @0x24bea4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24bea8 b 0x24bdec <_Z20json_parse_to_objectP11json_objectR6RValue+0xcc> */

/* ── FUNC 0x24beac · json_parse(json_object*, RValue&) · size=112 · insn=28 */
/* @0x24beac push {r3, r4, r5, lr} */
/* @0x24beb0 subs r4, r0, #0 */
/* @0x24beb4 mov r5, r1 */
/* @0x24beb8 beq 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60> */
/* @0x24bebc bl 0x27e828 <json_object_get_type> */
/* @0x24bec0 cmp r0, #6 */
/* @0x24bec4 addls pc, pc, r0, lsl #2 */
/* @0x24bec8 b 0x24bf08 <_Z10json_parseP11json_objectR6RValue+0x5c> */
/* @0x24becc b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60> */
/* @0x24bed0 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60> */
/* @0x24bed4 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60> */
/* @0x24bed8 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60> */
/* @0x24bedc b 0x24bef8 <_Z10json_parseP11json_objectR6RValue+0x4c> */
/* @0x24bee0 b 0x24bee8 <_Z10json_parseP11json_objectR6RValue+0x3c> */
/* @0x24bee4 b 0x24bf0c <_Z10json_parseP11json_objectR6RValue+0x60> */
/* @0x24bee8 mov r0, r4 */
/* @0x24beec mov r1, r5 */
/* @0x24bef0 pop {r3, r4, r5, lr} */
/* @0x24bef4 b 0x24bf1c <_Z18json_parse_jsarrayP11json_objectR6RValue> */
/* @0x24bef8 mov r0, r4 */
/* @0x24befc mov r1, r5 */
/* @0x24bf00 pop {r3, r4, r5, lr} */
/* @0x24bf04 b 0x24bd20 <_Z20json_parse_to_objectP11json_objectR6RValue> */
/* @0x24bf08 pop {r3, r4, r5, pc} */
/* @0x24bf0c mov r0, r4 */
/* @0x24bf10 mov r1, r5 */
/* @0x24bf14 pop {r3, r4, r5, lr} */
/* @0x24bf18 b 0x13c274 <_Z10json_valueP11json_objectP6RValue> */

/* ── FUNC 0x24bf1c · json_parse_jsarray(json_object*, RValue&) · size=156 · insn=39 */
/* @0x24bf1c push {r4, r5, r6, r7, r8, lr} */
/* @0x24bf20 sub sp, sp, #8 */
/* @0x24bf24 mov r4, r1 */
/* @0x24bf28 mov r7, r0 */
/* @0x24bf2c bl 0x27ede8 <json_object_array_length> */
/* @0x24bf30 mov r3, #0 */
/* @0x24bf34 mov r1, r3 */
/* @0x24bf38 str r3, [sp] */
/* @0x24bf3c mov r2, r3 */
/* @0x24bf40 mov r6, r0 */
/* @0x24bf44 mov r0, r4 */
/* @0x24bf48 mov r3, r6 */
/* @0x24bf4c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x24bf50 ldr r0, [r4] */
/* @0x24bf54 ldr r3, [r0, #0x4] */
/* @0x24bf58 cmp r3, #0 */
/* @0x24bf5c beq 0x24bfac <_Z18json_parse_jsarrayP11json_objectR6RValue+0x90> */
/* @0x24bf60 add r0, r3, #16 */
/* @0x24bf64 ldr r3, [r0] */
/* @0x24bf68 cmp r6, #0 */
/* @0x24bf6c ldr r4, [r3, #0x4] */
/* @0x24bf70 ble 0x24bfa4 <_Z18json_parse_jsarrayP11json_objectR6RValue+0x88> */
/* @0x24bf74 mov r5, #0 */
/* @0x24bf78 mov r8, #6 */
/* @0x24bf7c mov r1, r5 */
/* @0x24bf80 mov r0, r7 */
/* @0x24bf84 bl 0x27ee00 <json_object_array_get_idx> */
/* @0x24bf88 add r5, r5, #1 */
/* @0x24bf8c mov r1, r4 */
/* @0x24bf90 add r4, r4, #16 */
/* @0x24bf94 bl 0x24beac <_Z10json_parseP11json_objectR6RValue> */
/* @0x24bf98 cmp r5, r6 */
/* @0x24bf9c str r8, [r4, #-0x8] */
/* @0x24bfa0 bne 0x24bf7c <_Z18json_parse_jsarrayP11json_objectR6RValue+0x60> */
/* @0x24bfa4 add sp, sp, #8 */
/* @0x24bfa8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x24bfac mov r1, #1 */
/* @0x24bfb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24bfb4 b 0x24bf64 <_Z18json_parse_jsarrayP11json_objectR6RValue+0x48> */
