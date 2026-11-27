/* libyoyo.so 覆盖卡组 0164
 * 函数 0x1e2bb0..0x1e5854，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1e2bb0 · F_VertexFormat_Begin(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1e2bb0 subs r1, r3, #0 */
/* @0x1e2bb4 mov r12, #0 */
/* @0x1e2bb8 mov r2, r12 */
/* @0x1e2bbc movt r12, #0xbff0 */
/* @0x1e2bc0 push {r3, r4, r5, lr} */
/* @0x1e2bc4 str r2, [r0, #0xc] */
/* @0x1e2bc8 stm r0, {r2, r12} */
/* @0x1e2bcc bne 0x1e2bf4 <_Z20F_VertexFormat_BeginR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1e2bd0 ldr r4, [pc, #0x68] */
/* @0x1e2bd4 ldr r4, [pc, r4] */
/* @0x1e2bd8 ldr r5, [r4] */
/* @0x1e2bdc cmp r5, #0 */
/* @0x1e2be0 beq 0x1e2c08 <_Z20F_VertexFormat_BeginR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1e2be4 ldr r0, [pc, #0x58] */
/* @0x1e2be8 pop {r3, r4, r5, lr} */
/* @0x1e2bec add r0, pc, r0 */
/* @0x1e2bf0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2bf4 ldr r0, [pc, #0x4c] */
/* @0x1e2bf8 mov r1, r2 */
/* @0x1e2bfc pop {r3, r4, r5, lr} */
/* @0x1e2c00 add r0, pc, r0 */
/* @0x1e2c04 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2c08 mov r0, #28 */
/* @0x1e2c0c bl 0x27c524 <_Znwj> */
/* @0x1e2c10 ldr r3, [pc, #0x34] */
/* @0x1e2c14 mov r2, #1 */
/* @0x1e2c18 ldr r3, [pc, r3] */
/* @0x1e2c1c str r5, [r0] */
/* @0x1e2c20 str r5, [r0, #0x4] */
/* @0x1e2c24 str r5, [r0, #0x8] */
/* @0x1e2c28 str r5, [r0, #0xc] */
/* @0x1e2c2c str r5, [r0, #0x10] */
/* @0x1e2c30 str r5, [r0, #0x18] */
/* @0x1e2c34 str r0, [r4] */
/* @0x1e2c38 str r2, [r3] */
/* @0x1e2c3c pop {r3, r4, r5, pc} */
/* @0x1e2c40 .word 0x0020e1bc */
/* @0x1e2c44 andseq pc, r6, r4, lsl #13 */
/* @0x1e2c48 andseq pc, r6, r0, asr #12 */
/* @0x1e2c4c eoreq lr, r0, r12, ror r1 */

/* ── FUNC 0x1e2c50 · Hash<VertexFormat>::~Hash() · size=128 · insn=32 */
/* @0x1e2c50 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e2c54 mov r6, r0 */
/* @0x1e2c58 ldm r0, {r0, r8} */
/* @0x1e2c5c cmp r8, #0 */
/* @0x1e2c60 lslge r7, r8, #3 */
/* @0x1e2c64 movge r9, #0 */
/* @0x1e2c68 blt 0x1e2cc4 <_ZN4HashI12VertexFormatED2Ev+0x74> */
/* @0x1e2c6c ldr r4, [r0, r7] */
/* @0x1e2c70 add r3, r0, r7 */
/* @0x1e2c74 str r9, [r0, r7] */
/* @0x1e2c78 cmp r4, #0 */
/* @0x1e2c7c str r9, [r3, #0x4] */
/* @0x1e2c80 beq 0x1e2cb4 <_ZN4HashI12VertexFormatED2Ev+0x64> */
/* @0x1e2c84 ldr r5, [r4, #0x4] */
/* @0x1e2c88 ldr r0, [r4, #0xc] */
/* @0x1e2c8c bl 0x27d1d0 <_ZdlPv> */
/* @0x1e2c90 mov r0, r4 */
/* @0x1e2c94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e2c98 ldr r3, [r6, #0x8] */
/* @0x1e2c9c cmp r5, #0 */
/* @0x1e2ca0 mov r4, r5 */
/* @0x1e2ca4 sub r3, r3, #1 */
/* @0x1e2ca8 str r3, [r6, #0x8] */
/* @0x1e2cac bne 0x1e2c84 <_ZN4HashI12VertexFormatED2Ev+0x34> */
/* @0x1e2cb0 ldr r0, [r6] */
/* @0x1e2cb4 sub r8, r8, #1 */
/* @0x1e2cb8 sub r7, r7, #8 */
/* @0x1e2cbc cmn r8, #1 */
/* @0x1e2cc0 bne 0x1e2c6c <_ZN4HashI12VertexFormatED2Ev+0x1c> */
/* @0x1e2cc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e2cc8 mov r0, r6 */
/* @0x1e2ccc pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1e2c50 · Hash<VertexFormat>::~Hash() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1e2cd0 · GetVertexFormat(int) · size=132 · insn=33 */
/* @0x1e2cd0 ldr r1, [pc, #0x74] */
/* @0x1e2cd4 ldr r1, [pc, r1] */
/* @0x1e2cd8 ldr r3, [r1] */
/* @0x1e2cdc cmp r3, #0 */
/* @0x1e2ce0 beq 0x1e2cf0 <_Z15GetVertexFormati+0x20> */
/* @0x1e2ce4 ldr r2, [r3] */
/* @0x1e2ce8 cmp r2, r0 */
/* @0x1e2cec beq 0x1e2d44 <_Z15GetVertexFormati+0x74> */
/* @0x1e2cf0 ldr r3, [pc, #0x58] */
/* @0x1e2cf4 ldr r3, [pc, r3] */
/* @0x1e2cf8 ldr r2, [r3, #0x4] */
/* @0x1e2cfc ldr r3, [r3] */
/* @0x1e2d00 and r2, r0, r2 */
/* @0x1e2d04 ldr r3, [r3, r2, lsl #3] */
/* @0x1e2d08 cmp r3, #0 */
/* @0x1e2d0c bne 0x1e2d20 <_Z15GetVertexFormati+0x50> */
/* @0x1e2d10 b 0x1e2d38 <_Z15GetVertexFormati+0x68> */
/* @0x1e2d14 ldr r3, [r3, #0x4] */
/* @0x1e2d18 cmp r3, #0 */
/* @0x1e2d1c beq 0x1e2d38 <_Z15GetVertexFormati+0x68> */
/* @0x1e2d20 ldr r2, [r3, #0x8] */
/* @0x1e2d24 cmp r0, r2 */
/* @0x1e2d28 bne 0x1e2d14 <_Z15GetVertexFormati+0x44> */
/* @0x1e2d2c ldr r0, [r3, #0xc] */
/* @0x1e2d30 str r0, [r1] */
/* @0x1e2d34 bx lr */
/* @0x1e2d38 mov r0, r3 */
/* @0x1e2d3c str r0, [r1] */
/* @0x1e2d40 bx lr */
/* @0x1e2d44 mov r0, r3 */
/* @0x1e2d48 bx lr */
/* @0x1e2d4c eoreq lr, r0, r4, asr #1 */
/* @0x1e2d50 eoreq lr, r0, r8, lsr #1 */

/* ── FUNC 0x1e2d54 · VertexFormatExists(int) · size=20 · insn=5 */
/* @0x1e2d54 push {r3, lr} */
/* @0x1e2d58 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0x1e2d5c adds r0, r0, #0 */
/* @0x1e2d60 movne r0, #1 */
/* @0x1e2d64 pop {r3, pc} */

/* ── FUNC 0x1e2d68 · AddVertexFormat(VertexFormat*) · size=180 · insn=45 */
/* @0x1e2d68 push {r4, r5, r6, r7, r8, lr} */
/* @0x1e2d6c subs r5, r0, #0 */
/* @0x1e2d70 beq 0x1e2e08 <_Z15AddVertexFormatP12VertexFormat+0xa0> */
/* @0x1e2d74 ldr r12, [pc, #0x94] */
/* @0x1e2d78 mov r3, #1 */
/* @0x1e2d7c ldr r4, [pc, #0x90] */
/* @0x1e2d80 movw r2, #0x132 */
/* @0x1e2d84 add r12, pc, r12 */
/* @0x1e2d88 ldr r1, [pc, #0x88] */
/* @0x1e2d8c ldr r4, [pc, r4] */
/* @0x1e2d90 mov r0, #16 */
/* @0x1e2d94 ldr lr, [r12] */
/* @0x1e2d98 add r1, pc, r1 */
/* @0x1e2d9c ldr r7, [r4] */
/* @0x1e2da0 orr r6, lr, #16777216 */
/* @0x1e2da4 ldr r8, [r4, #0x4] */
/* @0x1e2da8 str r6, [r5] */
/* @0x1e2dac add lr, lr, r3 */
/* @0x1e2db0 str lr, [r12] */
/* @0x1e2db4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e2db8 and r8, r6, r8 */
/* @0x1e2dbc ldr r1, [r7, r8, lsl #3] */
/* @0x1e2dc0 add r2, r7, r8, lsl #3 */
/* @0x1e2dc4 cmp r1, #0 */
/* @0x1e2dc8 ldrne r1, [r2, #0x4] */
/* @0x1e2dcc mov r3, r0 */
/* @0x1e2dd0 str r6, [r0, #0x8] */
/* @0x1e2dd4 str r5, [r0, #0xc] */
/* @0x1e2dd8 movne r0, #0 */
/* @0x1e2ddc strne r1, [r3] */
/* @0x1e2de0 strne r3, [r1, #0x4] */
/* @0x1e2de4 strne r3, [r2, #0x4] */
/* @0x1e2de8 strne r0, [r3, #0x4] */
/* @0x1e2dec ldr r3, [r4, #0x8] */
/* @0x1e2df0 streq r0, [r2, #0x4] */
/* @0x1e2df4 add r3, r3, #1 */
/* @0x1e2df8 streq r0, [r7, r8, lsl #3] */
/* @0x1e2dfc streq r1, [r0, #0x4] */
/* @0x1e2e00 streq r1, [r0] */
/* @0x1e2e04 str r3, [r4, #0x8] */
/* @0x1e2e08 mov r0, r5 */
/* @0x1e2e0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e2e10 eorseq r1, r6, r0, lsl #30 */
/* @0x1e2e14 eoreq lr, r0, r0, lsl r0 */
/* @0x1e2e18 andseq r8, r6, r12, lsl #12 */

/* ── FUNC 0x1e2e1c · F_VertexFormat_End(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1e2e1c push {r3, r4, r5, lr} */
/* @0x1e2e20 mov r5, r0 */
/* @0x1e2e24 ldr r4, [pc, #0x60] */
/* @0x1e2e28 ldr r4, [pc, r4] */
/* @0x1e2e2c ldr r0, [r4] */
/* @0x1e2e30 cmp r0, #0 */
/* @0x1e2e34 beq 0x1e2e78 <_Z18F_VertexFormat_EndR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1e2e38 bl 0x1e2d68 <_Z15AddVertexFormatP12VertexFormat> */
/* @0x1e2e3c str r0, [r4] */
/* @0x1e2e40 bl 0x18565c <_Z24CreateNativeVertexFormatP12VertexFormat> */
/* @0x1e2e44 ldr r3, [r4] */
/* @0x1e2e48 mov r1, #0 */
/* @0x1e2e4c ldr r0, [pc, #0x3c] */
/* @0x1e2e50 str r1, [r5, #0xc] */
/* @0x1e2e54 ldr r2, [r3] */
/* @0x1e2e58 ldr r0, [pc, r0] */
/* @0x1e2e5c vmov s15, r2 */
/* @0x1e2e60 vcvt.f64.s32 d7, s15 */
/* @0x1e2e64 vmov r2, r3, d7 */
/* @0x1e2e68 stm r5, {r2, r3} */
/* @0x1e2e6c str r1, [r0] */
/* @0x1e2e70 str r1, [r4] */
/* @0x1e2e74 pop {r3, r4, r5, pc} */
/* @0x1e2e78 mov r1, r0 */
/* @0x1e2e7c ldr r0, [pc, #0x10] */
/* @0x1e2e80 pop {r3, r4, r5, lr} */
/* @0x1e2e84 add r0, pc, r0 */
/* @0x1e2e88 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e2e8c eoreq sp, r0, r8, ror #30 */
/* @0x1e2e90 eoreq sp, r0, r12, lsr pc */
/* @0x1e2e94 andseq pc, r6, r12, lsr r4 */

/* ── FUNC 0x1e2e98 · DeleteVertexFormat(VertexFormat*) · size=192 · insn=48 */
/* @0x1e2e98 push {r3, r4, r5, lr} */
/* @0x1e2e9c subs r4, r0, #0 */
/* @0x1e2ea0 popeq {r3, r4, r5, pc} */
/* @0x1e2ea4 ldr r3, [pc, #0xa4] */
/* @0x1e2ea8 ldr r5, [pc, #0xa4] */
/* @0x1e2eac ldr r3, [pc, r3] */
/* @0x1e2eb0 ldr r0, [r4, #0x8] */
/* @0x1e2eb4 ldr r2, [r3] */
/* @0x1e2eb8 cmp r2, r4 */
/* @0x1e2ebc moveq r2, #0 */
/* @0x1e2ec0 streq r2, [r3] */
/* @0x1e2ec4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e2ec8 ldr r5, [pc, r5] */
/* @0x1e2ecc ldr r2, [r4] */
/* @0x1e2ed0 ldr r0, [r5, #0x4] */
/* @0x1e2ed4 ldr r1, [r5] */
/* @0x1e2ed8 and r0, r2, r0 */
/* @0x1e2edc ldr r4, [r1, r0, lsl #3] */
/* @0x1e2ee0 add r12, r1, r0, lsl #3 */
/* @0x1e2ee4 cmp r4, #0 */
/* @0x1e2ee8 bne 0x1e2efc <_Z18DeleteVertexFormatP12VertexFormat+0x64> */
/* @0x1e2eec pop {r3, r4, r5, pc} */
/* @0x1e2ef0 ldr r4, [r4, #0x4] */
/* @0x1e2ef4 cmp r4, #0 */
/* @0x1e2ef8 beq 0x1e2f4c <_Z18DeleteVertexFormatP12VertexFormat+0xb4> */
/* @0x1e2efc ldr r3, [r4, #0x8] */
/* @0x1e2f00 cmp r2, r3 */
/* @0x1e2f04 bne 0x1e2ef0 <_Z18DeleteVertexFormatP12VertexFormat+0x58> */
/* @0x1e2f08 ldr r3, [r4] */
/* @0x1e2f0c ldr r2, [r4, #0x4] */
/* @0x1e2f10 cmp r3, #0 */
/* @0x1e2f14 strne r2, [r3, #0x4] */
/* @0x1e2f18 ldrne r2, [r4, #0x4] */
/* @0x1e2f1c streq r2, [r1, r0, lsl #3] */
/* @0x1e2f20 cmp r2, #0 */
/* @0x1e2f24 ldr r0, [r4, #0xc] */
/* @0x1e2f28 streq r3, [r12, #0x4] */
/* @0x1e2f2c strne r3, [r2] */
/* @0x1e2f30 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e2f34 mov r0, r4 */
/* @0x1e2f38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e2f3c ldr r3, [r5, #0x8] */
/* @0x1e2f40 sub r3, r3, #1 */
/* @0x1e2f44 str r3, [r5, #0x8] */
/* @0x1e2f48 pop {r3, r4, r5, pc} */
/* @0x1e2f4c pop {r3, r4, r5, pc} */
/* @0x1e2f50 eoreq sp, r0, r12, ror #29 */
/* @0x1e2f54 .word 0x0020ded4 */

/* ── FUNC 0x1e2f58 · F_VertexFormat_Delete(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1e2f58 push {r4, lr} */
/* @0x1e2f5c ldr r4, [sp, #0x8] */
/* @0x1e2f60 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e2f64 mov r1, #0 */
/* @0x1e2f68 mov r0, r4 */
/* @0x1e2f6c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1e2f70 ldr r3, [pc, #0x58] */
/* @0x1e2f74 ldr r3, [pc, r3] */
/* @0x1e2f78 ldr r2, [r3, #0x4] */
/* @0x1e2f7c ldr r3, [r3] */
/* @0x1e2f80 and r2, r0, r2 */
/* @0x1e2f84 ldr r3, [r3, r2, lsl #3] */
/* @0x1e2f88 cmp r3, #0 */
/* @0x1e2f8c bne 0x1e2fa0 <_Z21F_VertexFormat_DeleteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1e2f90 pop {r4, pc} */
/* @0x1e2f94 ldr r3, [r3, #0x4] */
/* @0x1e2f98 cmp r3, #0 */
/* @0x1e2f9c beq 0x1e2fcc <_Z21F_VertexFormat_DeleteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1e2fa0 ldr r2, [r3, #0x8] */
/* @0x1e2fa4 cmp r0, r2 */
/* @0x1e2fa8 bne 0x1e2f94 <_Z21F_VertexFormat_DeleteR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1e2fac ldr r4, [r3, #0xc] */
/* @0x1e2fb0 cmp r4, #0 */
/* @0x1e2fb4 popeq {r4, pc} */
/* @0x1e2fb8 mov r0, r4 */
/* @0x1e2fbc bl 0x185640 <_Z16FreeVertexFormatP12VertexFormat> */
/* @0x1e2fc0 mov r0, r4 */
/* @0x1e2fc4 pop {r4, lr} */
/* @0x1e2fc8 b 0x1e2e98 <_Z18DeleteVertexFormatP12VertexFormat> */
/* @0x1e2fcc pop {r4, pc} */
/* @0x1e2fd0 eoreq sp, r0, r8, lsr #28 */

/* ── FUNC 0x1e2fd4 · VertexFormat_Set(VertexFormat*) · size=20 · insn=5 */
/* @0x1e2fd4 ldr r3, [pc, #0x8] */
/* @0x1e2fd8 ldr r3, [pc, r3] */
/* @0x1e2fdc str r0, [r3] */
/* @0x1e2fe0 bx lr */
/* @0x1e2fe4 eoreq sp, r0, r8, asr #27 */

/* ── FUNC 0x1e2fe8 · InitVertexFormats() · size=408 · insn=102 */
/* @0x1e2fe8 push {r4, r5, r6, lr} */
/* @0x1e2fec mov r2, #0 */
/* @0x1e2ff0 ldr r4, [pc, #0x134] */
/* @0x1e2ff4 mov r3, r2 */
/* @0x1e2ff8 ldr r1, [pc, #0x130] */
/* @0x1e2ffc add r4, pc, r4 */
/* @0x1e3000 ldr r0, [pc, #0x12c] */
/* @0x1e3004 ldr r1, [r4, r1] */
/* @0x1e3008 add r0, pc, r0 */
/* @0x1e300c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e3010 ldr r1, [pc, #0x120] */
/* @0x1e3014 ldr r0, [pc, #0x120] */
/* @0x1e3018 mov r2, #1 */
/* @0x1e301c mov r3, #0 */
/* @0x1e3020 ldr r1, [r4, r1] */
/* @0x1e3024 add r0, pc, r0 */
/* @0x1e3028 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e302c ldr r1, [pc, #0x10c] */
/* @0x1e3030 ldr r0, [pc, #0x10c] */
/* @0x1e3034 mov r2, #0 */
/* @0x1e3038 mov r3, r2 */
/* @0x1e303c ldr r1, [r4, r1] */
/* @0x1e3040 add r0, pc, r0 */
/* @0x1e3044 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e3048 ldr r1, [pc, #0xf8] */
/* @0x1e304c ldr r0, [pc, #0xf8] */
/* @0x1e3050 mov r2, #0 */
/* @0x1e3054 mov r3, r2 */
/* @0x1e3058 ldr r1, [r4, r1] */
/* @0x1e305c add r0, pc, r0 */
/* @0x1e3060 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e3064 ldr r1, [pc, #0xe4] */
/* @0x1e3068 ldr r0, [pc, #0xe4] */
/* @0x1e306c mov r2, #0 */
/* @0x1e3070 mov r3, r2 */
/* @0x1e3074 ldr r1, [r4, r1] */
/* @0x1e3078 add r0, pc, r0 */
/* @0x1e307c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e3080 ldr r1, [pc, #0xd0] */
/* @0x1e3084 ldr r0, [pc, #0xd0] */
/* @0x1e3088 mov r2, #0 */
/* @0x1e308c mov r3, r2 */
/* @0x1e3090 ldr r5, [r4, r1] */
/* @0x1e3094 add r0, pc, r0 */
/* @0x1e3098 mov r1, r5 */
/* @0x1e309c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e30a0 ldr r0, [pc, #0xb8] */
/* @0x1e30a4 mov r2, #0 */
/* @0x1e30a8 mov r1, r5 */
/* @0x1e30ac mov r3, r2 */
/* @0x1e30b0 add r0, pc, r0 */
/* @0x1e30b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e30b8 ldr r1, [pc, #0xa4] */
/* @0x1e30bc ldr r0, [pc, #0xa4] */
/* @0x1e30c0 mov r2, #0 */
/* @0x1e30c4 mov r3, r2 */
/* @0x1e30c8 ldr r1, [r4, r1] */
/* @0x1e30cc add r0, pc, r0 */
/* @0x1e30d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e30d4 ldr r1, [pc, #0x90] */
/* @0x1e30d8 ldr r0, [pc, #0x90] */
/* @0x1e30dc mov r2, #0 */
/* @0x1e30e0 mov r3, r2 */
/* @0x1e30e4 ldr r5, [r4, r1] */
/* @0x1e30e8 add r0, pc, r0 */
/* @0x1e30ec mov r1, r5 */
/* @0x1e30f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e30f4 ldr r0, [pc, #0x78] */
/* @0x1e30f8 mov r2, #0 */
/* @0x1e30fc mov r1, r5 */
/* @0x1e3100 mov r3, r2 */
/* @0x1e3104 add r0, pc, r0 */
/* @0x1e3108 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e310c ldr r1, [pc, #0x64] */
/* @0x1e3110 ldr r0, [pc, #0x64] */
/* @0x1e3114 mov r2, #2 */
/* @0x1e3118 mov r3, #0 */
/* @0x1e311c ldr r1, [r4, r1] */
/* @0x1e3120 add r0, pc, r0 */
/* @0x1e3124 pop {r4, r5, r6, lr} */
/* @0x1e3128 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1e312c eoreq lr, r0, r4, asr r12 */
/* @0x1e3130 .word 0xfffff154 */
/* @0x1e3134 ldrsheq pc, [r6], -r12 */
/* @0x1e3138 .word 0xfffff158 */
/* @0x1e313c ldrsheq pc, [r6], -r4 */
/* @0x1e3140 .word 0xfffff15c */
/* @0x1e3144 ldrsheq pc, [r6], -r0 */
/* @0x1e3148 .word 0xfffff160 */
/* @0x1e314c andseq pc, r6, r8, ror #5 */
/* @0x1e3150 .word 0xfffff164 */
/* @0x1e3154 andseq pc, r6, r8, ror #5 */
/* @0x1e3158 .word 0xfffff168 */
/* @0x1e315c andseq pc, r6, r12, ror #5 */
/* @0x1e3160 andseq pc, r6, r12, ror #5 */
/* @0x1e3164 .word 0xfffff16c */
/* @0x1e3168 andseq pc, r6, r8, ror #5 */
/* @0x1e316c .word 0xfffff170 */
/* @0x1e3170 andseq pc, r6, r8, ror #5 */
/* @0x1e3174 andseq pc, r6, r8, ror #5 */
/* @0x1e3178 .word 0xfffff174 */
/* @0x1e317c andseq pc, r6, r8, ror #5 */

/* ── FUNC 0x1e3180 · FINALIZE_VertexFormats() · size=296 · insn=74 */
/* @0x1e3180 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e3184 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1e3188 mov r3, #0 */
/* @0x1e318c ldr r6, [pc, #0x10c] */
/* @0x1e3190 ldr r6, [pc, r6] */
/* @0x1e3194 ldm r6, {r2, r8} */
/* @0x1e3198 b 0x1e31a4 <_Z22FINALIZE_VertexFormatsv+0x24> */
/* @0x1e319c cmp r8, r3 */
/* @0x1e31a0 blt 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c> */
/* @0x1e31a4 ldr r4, [r2, r3, lsl #3] */
/* @0x1e31a8 mov r5, r3 */
/* @0x1e31ac add r3, r3, #1 */
/* @0x1e31b0 cmp r4, #0 */
/* @0x1e31b4 beq 0x1e319c <_Z22FINALIZE_VertexFormatsv+0x1c> */
/* @0x1e31b8 ldr r0, [r4, #0xc] */
/* @0x1e31bc cmp r0, #0 */
/* @0x1e31c0 bne 0x1e31d4 <_Z22FINALIZE_VertexFormatsv+0x54> */
/* @0x1e31c4 b 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c> */
/* @0x1e31c8 ldr r0, [r4, #0xc] */
/* @0x1e31cc cmp r0, #0 */
/* @0x1e31d0 beq 0x1e3298 <_Z22FINALIZE_VertexFormatsv+0x118> */
/* @0x1e31d4 bl 0x185640 <_Z16FreeVertexFormatP12VertexFormat> */
/* @0x1e31d8 ldr r4, [r4, #0x4] */
/* @0x1e31dc cmp r4, #0 */
/* @0x1e31e0 bne 0x1e31c8 <_Z22FINALIZE_VertexFormatsv+0x48> */
/* @0x1e31e4 ldr r8, [r6, #0x4] */
/* @0x1e31e8 add r3, r5, #1 */
/* @0x1e31ec cmp r3, r8 */
/* @0x1e31f0 bgt 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c> */
/* @0x1e31f4 ldr r2, [r6] */
/* @0x1e31f8 add r2, r2, r5, lsl #3 */
/* @0x1e31fc ldr r4, [r2, #0x8] */
/* @0x1e3200 mov r5, r3 */
/* @0x1e3204 add r2, r2, #8 */
/* @0x1e3208 add r3, r3, #1 */
/* @0x1e320c cmp r4, #0 */
/* @0x1e3210 bne 0x1e31c8 <_Z22FINALIZE_VertexFormatsv+0x48> */
/* @0x1e3214 cmp r3, r8 */
/* @0x1e3218 ble 0x1e31fc <_Z22FINALIZE_VertexFormatsv+0x7c> */
/* @0x1e321c cmp r8, #0 */
/* @0x1e3220 lslge r7, r8, #3 */
/* @0x1e3224 movge r9, #0 */
/* @0x1e3228 blt 0x1e3284 <_Z22FINALIZE_VertexFormatsv+0x104> */
/* @0x1e322c ldr r3, [r6] */
/* @0x1e3230 add r2, r3, r7 */
/* @0x1e3234 ldr r4, [r3, r7] */
/* @0x1e3238 str r9, [r3, r7] */
/* @0x1e323c cmp r4, #0 */
/* @0x1e3240 str r9, [r2, #0x4] */
/* @0x1e3244 beq 0x1e3274 <_Z22FINALIZE_VertexFormatsv+0xf4> */
/* @0x1e3248 ldr r5, [r4, #0x4] */
/* @0x1e324c ldr r0, [r4, #0xc] */
/* @0x1e3250 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e3254 mov r0, r4 */
/* @0x1e3258 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e325c ldr r3, [r6, #0x8] */
/* @0x1e3260 cmp r5, #0 */
/* @0x1e3264 mov r4, r5 */
/* @0x1e3268 sub r3, r3, #1 */
/* @0x1e326c str r3, [r6, #0x8] */
/* @0x1e3270 bne 0x1e3248 <_Z22FINALIZE_VertexFormatsv+0xc8> */
/* @0x1e3274 sub r8, r8, #1 */
/* @0x1e3278 sub r7, r7, #8 */
/* @0x1e327c cmn r8, #1 */
/* @0x1e3280 bne 0x1e322c <_Z22FINALIZE_VertexFormatsv+0xac> */
/* @0x1e3284 ldr r3, [pc, #0x18] */
/* @0x1e3288 mov r2, #0 */
/* @0x1e328c ldr r3, [pc, r3] */
/* @0x1e3290 str r2, [r3] */
/* @0x1e3294 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e3298 ldr r8, [r6, #0x4] */
/* @0x1e329c b 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c> */
/* @0x1e32a0 eoreq sp, r0, r12, lsl #24 */
/* @0x1e32a4 eoreq sp, r0, r12, lsl #22 */

/* ── FUNC 0x1e32a8 · ClearVertexFormats() · size=64 · insn=16 */
/* @0x1e32a8 push {r3, lr} */
/* @0x1e32ac bl 0x1e3180 <_Z22FINALIZE_VertexFormatsv> */
/* @0x1e32b0 mov r2, #0 */
/* @0x1e32b4 ldr r0, [pc, #0x20] */
/* @0x1e32b8 ldr r1, [pc, #0x20] */
/* @0x1e32bc ldr r3, [pc, #0x20] */
/* @0x1e32c0 ldr r0, [pc, r0] */
/* @0x1e32c4 ldr r1, [pc, r1] */
/* @0x1e32c8 ldr r3, [pc, r3] */
/* @0x1e32cc str r2, [r0] */
/* @0x1e32d0 str r2, [r1] */
/* @0x1e32d4 str r2, [r3] */
/* @0x1e32d8 pop {r3, pc} */
/* @0x1e32dc eoreq sp, r0, r0, ror #21 */
/* @0x1e32e0 eoreq sp, r0, r12, asr #21 */
/* @0x1e32e4 eoreq sp, r0, r12, asr #21 */

/* ── FUNC 0x1e32e8 · CSprite::SetBoundingBox(tagYYRECT*) · size=56 · insn=14 */
/* @0x1e32e8 ldr r3, [r0, #0x4] */
/* @0x1e32ec str r4, [sp, #-0x4]! */
/* @0x1e32f0 cmp r3, #2 */
/* @0x1e32f4 bne 0x1e3318 <_ZN7CSprite14SetBoundingBoxEP9tagYYRECT+0x30> */
/* @0x1e32f8 ldr r4, [r1, #0xc] */
/* @0x1e32fc ldr r12, [r1] */
/* @0x1e3300 ldr r2, [r1, #0x8] */
/* @0x1e3304 ldr r3, [r1, #0x4] */
/* @0x1e3308 str r4, [r0, #0x14] */
/* @0x1e330c str r12, [r0, #0x8] */
/* @0x1e3310 str r2, [r0, #0x10] */
/* @0x1e3314 str r3, [r0, #0xc] */
/* @0x1e3318 ldr r4, [sp], #4 */
/* @0x1e331c bx lr */

/* ── FUNC 0x1e3320 · CSprite::ComputeBoundingBox() · size=680 · insn=170 */
/* @0x1e3320 ldr r2, [r0, #0x28] */
/* @0x1e3324 ldr r3, [r0, #0x24] */
/* @0x1e3328 push {r4, r5, r6, r7, r8, lr} */
/* @0x1e332c vpush {d8, d9, d10} */
/* @0x1e3330 mov r4, r0 */
/* @0x1e3334 mul r1, r2, r2 */
/* @0x1e3338 ldr r0, [r0, #0x20] */
/* @0x1e333c mul r12, r3, r3 */
/* @0x1e3340 rsb r2, r2, r0 */
/* @0x1e3344 mul r2, r2, r2 */
/* @0x1e3348 vmov s19, r1 */
/* @0x1e334c ldr r1, [r4, #0x1c] */
/* @0x1e3350 vmov s18, r12 */
/* @0x1e3354 vcvt.f32.s32 s19, s19 */
/* @0x1e3358 rsb r3, r3, r1 */
/* @0x1e335c mul r3, r3, r3 */
/* @0x1e3360 vcvt.f32.s32 s18, s18 */
/* @0x1e3364 vmov s13, r3 */
/* @0x1e3368 vadd.f32 s14, s18, s19 */
/* @0x1e336c vsqrt.f32 s15, s14 */
/* @0x1e3370 vcmp.f32 s15, s15 */
/* @0x1e3374 vcvt.f32.s32 s17, s13 */
/* @0x1e3378 vmrs APSR_nzcv, fpscr */
/* @0x1e337c vmov s13, r2 */
/* @0x1e3380 vcvt.f32.s32 s16, s13 */
/* @0x1e3384 bne 0x1e35a8 <_ZN7CSprite18ComputeBoundingBoxEv+0x288> */
/* @0x1e3388 vmov r0, s15 */
/* @0x1e338c bl 0xb6994 <ceilf@plt> */
/* @0x1e3390 vadd.f32 s19, s17, s19 */
/* @0x1e3394 vsqrt.f32 s15, s19 */
/* @0x1e3398 vmov s20, r0 */
/* @0x1e339c vcmp.f32 s15, s15 */
/* @0x1e33a0 vmrs APSR_nzcv, fpscr */
/* @0x1e33a4 bne 0x1e3588 <_ZN7CSprite18ComputeBoundingBoxEv+0x268> */
/* @0x1e33a8 vadd.f32 s18, s18, s16 */
/* @0x1e33ac vmov r0, s15 */
/* @0x1e33b0 bl 0xb6994 <ceilf@plt> */
/* @0x1e33b4 vsqrt.f32 s15, s18 */
/* @0x1e33b8 vmov s19, r0 */
/* @0x1e33bc vcmp.f32 s15, s15 */
/* @0x1e33c0 vmrs APSR_nzcv, fpscr */
/* @0x1e33c4 bne 0x1e35b8 <_ZN7CSprite18ComputeBoundingBoxEv+0x298> */
/* @0x1e33c8 vadd.f32 s16, s17, s16 */
/* @0x1e33cc vmov r0, s15 */
/* @0x1e33d0 bl 0xb6994 <ceilf@plt> */
/* @0x1e33d4 vsqrt.f32 s15, s16 */
/* @0x1e33d8 vmov s18, r0 */
/* @0x1e33dc vcmp.f32 s15, s15 */
/* @0x1e33e0 vmrs APSR_nzcv, fpscr */
/* @0x1e33e4 bne 0x1e3598 <_ZN7CSprite18ComputeBoundingBoxEv+0x278> */
/* @0x1e33e8 vmov r0, s15 */
/* @0x1e33ec bl 0xb6994 <ceilf@plt> */
/* @0x1e33f0 vcvt.s32.f32 s18, s18 */
/* @0x1e33f4 ldr r3, [r4, #0x4] */
/* @0x1e33f8 vcvt.s32.f32 s19, s19 */
/* @0x1e33fc vmov r2, s18 */
/* @0x1e3400 vmov r1, s19 */
/* @0x1e3404 vcvt.s32.f32 s20, s20 */
/* @0x1e3408 vmov s13, r0 */
/* @0x1e340c vcvt.s32.f32 s13, s13 */
/* @0x1e3410 cmp r2, r1 */
/* @0x1e3414 movlt r2, r1 */
/* @0x1e3418 vmov r1, s20 */
/* @0x1e341c vmov r0, s13 */
/* @0x1e3420 cmp r2, r0 */
/* @0x1e3424 movlt r2, r0 */
/* @0x1e3428 cmp r1, r2 */
/* @0x1e342c strge r1, [r4, #0x2c] */
/* @0x1e3430 strlt r2, [r4, #0x2c] */
/* @0x1e3434 cmp r3, #2 */
/* @0x1e3438 beq 0x1e352c <_ZN7CSprite18ComputeBoundingBoxEv+0x20c> */
/* @0x1e343c ldrb r2, [r4, #0x32] */
/* @0x1e3440 cmp r2, #0 */
/* @0x1e3444 bne 0x1e3534 <_ZN7CSprite18ComputeBoundingBoxEv+0x214> */
/* @0x1e3448 ldr r1, [r4, #0x1c] */
/* @0x1e344c mov r3, #0 */
/* @0x1e3450 ldr r2, [r4, #0x20] */
/* @0x1e3454 sub r1, r1, #1 */
/* @0x1e3458 str r3, [r4, #0x8] */
/* @0x1e345c sub r2, r2, #1 */
/* @0x1e3460 str r1, [r4, #0x10] */
/* @0x1e3464 str r3, [r4, #0xc] */
/* @0x1e3468 str r2, [r4, #0x14] */
/* @0x1e346c ldr r3, [r4, #0x18] */
/* @0x1e3470 ldr r2, [r4, #0x74] */
/* @0x1e3474 cmp r3, #0 */
/* @0x1e3478 streq r3, [r4, #0xc] */
/* @0x1e347c streq r3, [r4, #0x10] */
/* @0x1e3480 streq r3, [r4, #0x8] */
/* @0x1e3484 streq r3, [r4, #0x14] */
/* @0x1e3488 cmp r2, #1 */
/* @0x1e348c beq 0x1e3540 <_ZN7CSprite18ComputeBoundingBoxEv+0x220> */
/* @0x1e3490 cmp r3, #0 */
/* @0x1e3494 ldr r2, [r4, #0x1c] */
/* @0x1e3498 ldr r3, [r4, #0x20] */
/* @0x1e349c mov r5, #0 */
/* @0x1e34a0 sub r2, r2, #1 */
/* @0x1e34a4 str r5, [r4, #0x10] */
/* @0x1e34a8 sub r3, r3, #1 */
/* @0x1e34ac str r2, [r4, #0x8] */
/* @0x1e34b0 str r5, [r4, #0x14] */
/* @0x1e34b4 str r3, [r4, #0xc] */
/* @0x1e34b8 ble 0x1e352c <_ZN7CSprite18ComputeBoundingBoxEv+0x20c> */
/* @0x1e34bc ldr r3, [r4, #0x48] */
/* @0x1e34c0 ldr r0, [r3, r5, lsl #2] */
/* @0x1e34c4 add r5, r5, #1 */
/* @0x1e34c8 bl 0x167508 <_ZN9CBitmap3211BoundingBoxEv> */
/* @0x1e34cc ldr r8, [r4, #0x8] */
/* @0x1e34d0 ldr r6, [r4, #0x10] */
/* @0x1e34d4 ldr r12, [r4, #0xc] */
/* @0x1e34d8 ldr r2, [r4, #0x14] */
/* @0x1e34dc ldr r3, [r0, #0xc] */
/* @0x1e34e0 ldr r7, [r0] */
/* @0x1e34e4 ldr lr, [r0, #0x8] */
/* @0x1e34e8 ldr r1, [r0, #0x4] */
/* @0x1e34ec cmp r2, r3 */
/* @0x1e34f0 strge r2, [r4, #0x14] */
/* @0x1e34f4 strlt r3, [r4, #0x14] */
/* @0x1e34f8 cmp r8, r7 */
/* @0x1e34fc strle r8, [r4, #0x8] */
/* @0x1e3500 strgt r7, [r4, #0x8] */
/* @0x1e3504 cmp r6, lr */
/* @0x1e3508 strge r6, [r4, #0x10] */
/* @0x1e350c strlt lr, [r4, #0x10] */
/* @0x1e3510 cmp r12, r1 */
/* @0x1e3514 strle r12, [r4, #0xc] */
/* @0x1e3518 strgt r1, [r4, #0xc] */
/* @0x1e351c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e3520 ldr r3, [r4, #0x18] */
/* @0x1e3524 cmp r3, r5 */
/* @0x1e3528 bgt 0x1e34bc <_ZN7CSprite18ComputeBoundingBoxEv+0x19c> */
/* @0x1e352c vpop {d8, d9, d10} */
/* @0x1e3530 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e3534 cmp r3, #1 */
/* @0x1e3538 bne 0x1e346c <_ZN7CSprite18ComputeBoundingBoxEv+0x14c> */
/* @0x1e353c b 0x1e3448 <_ZN7CSprite18ComputeBoundingBoxEv+0x128> */
/* @0x1e3540 ldr r3, [r4, #0x84] */
/* @0x1e3544 cmp r3, #0 */
/* @0x1e3548 beq 0x1e352c <_ZN7CSprite18ComputeBoundingBoxEv+0x20c> */
/* @0x1e354c vldr s15, [r3, #8] */
/* @0x1e3550 vcvt.s32.f32 s15, s15 */
/* @0x1e3554 vldr s13, [r3, #12] */
/* @0x1e3558 vldr s14, [r3, #16] */
/* @0x1e355c vpop {d8, d9, d10} */
/* @0x1e3560 vmov r2, s15 */
/* @0x1e3564 vldr s15, [r3, #20] */
/* @0x1e3568 vcvt.s32.f32 s13, s13 */
/* @0x1e356c vcvt.s32.f32 s14, s14 */
/* @0x1e3570 vstr s13, [r4, #16] */
/* @0x1e3574 vcvt.s32.f32 s15, s15 */
/* @0x1e3578 vstr s14, [r4, #12] */
/* @0x1e357c str r2, [r4, #0x8] */
/* @0x1e3580 vstr s15, [r4, #20] */
/* @0x1e3584 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e3588 vmov r0, s19 */
/* @0x1e358c bl 0xb6700 <sqrtf@plt> */
/* @0x1e3590 vmov s15, r0 */
/* @0x1e3594 b 0x1e33a8 <_ZN7CSprite18ComputeBoundingBoxEv+0x88> */
/* @0x1e3598 vmov r0, s16 */
/* @0x1e359c bl 0xb6700 <sqrtf@plt> */
/* @0x1e35a0 vmov s15, r0 */
/* @0x1e35a4 b 0x1e33e8 <_ZN7CSprite18ComputeBoundingBoxEv+0xc8> */
/* @0x1e35a8 vmov r0, s14 */
/* @0x1e35ac bl 0xb6700 <sqrtf@plt> */
/* @0x1e35b0 vmov s15, r0 */
/* @0x1e35b4 b 0x1e3388 <_ZN7CSprite18ComputeBoundingBoxEv+0x68> */
/* @0x1e35b8 vmov r0, s18 */
/* @0x1e35bc bl 0xb6700 <sqrtf@plt> */
/* @0x1e35c0 vmov s15, r0 */
/* @0x1e35c4 b 0x1e33c8 <_ZN7CSprite18ComputeBoundingBoxEv+0xa8> */

/* ── FUNC 0x1e35c8 · CSprite::SetBoundingBoxMode(int) · size=28 · insn=7 */
/* @0x1e35c8 cmp r1, #2 */
/* @0x1e35cc bxhi lr */
/* @0x1e35d0 ldr r2, [r0, #0x4] */
/* @0x1e35d4 cmp r2, r1 */
/* @0x1e35d8 bxeq lr */
/* @0x1e35dc str r1, [r0, #0x4] */
/* @0x1e35e0 b 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv> */

/* ── FUNC 0x1e35e4 · CSprite::TMaskCreate(CMask*, CMask*, CBitmap32*, int, int, int) · size=944 · insn=236 */
/* @0x1e35e4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e35e8 mov r7, r0 */
/* @0x1e35ec ldr r4, [sp, #0x2c] */
/* @0x1e35f0 mov r8, r1 */
/* @0x1e35f4 mov r6, r2 */
/* @0x1e35f8 mov r9, r3 */
/* @0x1e35fc cmp r4, #0 */
/* @0x1e3600 ldr r5, [sp, #0x30] */
/* @0x1e3604 beq 0x1e368c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0xa8> */
/* @0x1e3608 ldr r12, [r0, #0x1c] */
/* @0x1e360c ldr r2, [r0, #0x20] */
/* @0x1e3610 mul r2, r2, r12 */
/* @0x1e3614 cmp r2, #0 */
/* @0x1e3618 ble 0x1e3634 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x50> */
/* @0x1e361c ldr r3, [r6, #0x4] */
/* @0x1e3620 mov r1, #0 */
/* @0x1e3624 add r2, r3, r2 */
/* @0x1e3628 strb r1, [r3], #1 */
/* @0x1e362c cmp r3, r2 */
/* @0x1e3630 bne 0x1e3628 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x44> */
/* @0x1e3634 cmp r4, #2 */
/* @0x1e3638 beq 0x1e388c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x2a8> */
/* @0x1e363c cmp r4, #3 */
/* @0x1e3640 beq 0x1e371c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x138> */
/* @0x1e3644 cmp r4, #1 */
/* @0x1e3648 beq 0x1e3824 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x240> */
/* @0x1e364c cmp r8, #0 */
/* @0x1e3650 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3654 ldr r1, [r6] */
/* @0x1e3658 cmp r1, #0 */
/* @0x1e365c pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3660 ldr r0, [r8, #0x4] */
/* @0x1e3664 mov r3, #0 */
/* @0x1e3668 mov r12, #1 */
/* @0x1e366c ldrb r2, [r0, r3] */
/* @0x1e3670 cmp r2, #0 */
/* @0x1e3674 ldrne r2, [r6, #0x4] */
/* @0x1e3678 strbne r12, [r2, r3] */
/* @0x1e367c add r3, r3, #1 */
/* @0x1e3680 cmp r3, r1 */
/* @0x1e3684 bne 0x1e366c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x88> */
/* @0x1e3688 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e368c mov r0, r3 */
/* @0x1e3690 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e3694 mov r0, r9 */
/* @0x1e3698 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e369c ldr r10, [r7, #0x20] */
/* @0x1e36a0 cmp r10, #0 */
/* @0x1e36a4 ldr r9, [r0, #0x4] */
/* @0x1e36a8 ble 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68> */
/* @0x1e36ac ldr r1, [r7, #0x1c] */
/* @0x1e36b0 sub r9, r9, #4 */
/* @0x1e36b4 mov r2, r4 */
/* @0x1e36b8 mov r7, r4 */
/* @0x1e36bc lsl r11, r1, #2 */
/* @0x1e36c0 cmp r1, #0 */
/* @0x1e36c4 ble 0x1e36fc <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x118> */
/* @0x1e36c8 ldr r3, [r6, #0x4] */
/* @0x1e36cc mov r0, r9 */
/* @0x1e36d0 add r4, r3, r1 */
/* @0x1e36d4 add r3, r3, r2 */
/* @0x1e36d8 add r4, r4, r2 */
/* @0x1e36dc ldr r12, [r0, #0x4]! */
/* @0x1e36e0 and r12, r12, #-16777216 */
/* @0x1e36e4 cmp r5, r12 */
/* @0x1e36e8 movhs r12, #0 */
/* @0x1e36ec movlo r12, #1 */
/* @0x1e36f0 strb r12, [r3], #1 */
/* @0x1e36f4 cmp r3, r4 */
/* @0x1e36f8 bne 0x1e36dc <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0xf8> */
/* @0x1e36fc add r7, r7, #1 */
/* @0x1e3700 add r9, r9, r11 */
/* @0x1e3704 cmp r7, r10 */
/* @0x1e3708 add r2, r2, r1 */
/* @0x1e370c bne 0x1e36c0 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0xdc> */
/* @0x1e3710 cmp r8, #0 */
/* @0x1e3714 bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70> */
/* @0x1e3718 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e371c ldr r9, [r7, #0x8] */
/* @0x1e3720 vmov.f32 s15, #5.000000e-01 */
/* @0x1e3724 ldr r10, [r7, #0x10] */
/* @0x1e3728 ldr r4, [r7, #0xc] */
/* @0x1e372c add r2, r9, r10 */
/* @0x1e3730 ldr r7, [r7, #0x14] */
/* @0x1e3734 vmov s13, r9 */
/* @0x1e3738 add r3, r4, r7 */
/* @0x1e373c add r2, r2, r2, lsr #31 */
/* @0x1e3740 cmp r4, r7 */
/* @0x1e3744 add r3, r3, r3, lsr #31 */
/* @0x1e3748 asr r2, r2, #1 */
/* @0x1e374c asr r3, r3, #1 */
/* @0x1e3750 vmov s8, r2 */
/* @0x1e3754 vcvt.f32.s32 s14, s13 */
/* @0x1e3758 vmov s13, r4 */
/* @0x1e375c vcvt.f32.s32 s12, s8 */
/* @0x1e3760 vmov s8, r3 */
/* @0x1e3764 vcvt.f32.s32 s10, s13 */
/* @0x1e3768 vcvt.f32.s32 s9, s8 */
/* @0x1e376c vsub.f32 s14, s12, s14 */
/* @0x1e3770 vsub.f32 s10, s9, s10 */
/* @0x1e3774 vadd.f32 s14, s14, s15 */
/* @0x1e3778 vadd.f32 s10, s10, s15 */
/* @0x1e377c bgt 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68> */
/* @0x1e3780 mul r5, r4, r12 */
/* @0x1e3784 add r7, r7, #1 */
/* @0x1e3788 add r0, r10, #1 */
/* @0x1e378c vmov.f32 s11, #1.000000e+00 */
/* @0x1e3790 cmp r9, r10 */
/* @0x1e3794 bgt 0x1e3808 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x224> */
/* @0x1e3798 vcmpe.f32 s14, #0 */
/* @0x1e379c vmrs APSR_nzcv, fpscr */
/* @0x1e37a0 ble 0x1e3808 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x224> */
/* @0x1e37a4 vcmpe.f32 s10, #0 */
/* @0x1e37a8 vmrs APSR_nzcv, fpscr */
/* @0x1e37ac ble 0x1e3808 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x224> */
/* @0x1e37b0 vmov s15, r4 */
/* @0x1e37b4 ldr r1, [r6, #0x4] */
/* @0x1e37b8 mov r3, r9 */
/* @0x1e37bc vcvt.f32.s32 s13, s15 */
/* @0x1e37c0 add r1, r1, r5 */
/* @0x1e37c4 vsub.f32 s13, s13, s9 */
/* @0x1e37c8 vdiv.f32 s13, s13, s10 */
/* @0x1e37cc vabs.f32 s13, s13 */
/* @0x1e37d0 vmov s8, r3 */
/* @0x1e37d4 vcvt.f32.s32 s15, s8 */
/* @0x1e37d8 vsub.f32 s15, s15, s12 */
/* @0x1e37dc vdiv.f32 s15, s15, s14 */
/* @0x1e37e0 vabs.f32 s15, s15 */
/* @0x1e37e4 vadd.f32 s15, s15, s13 */
/* @0x1e37e8 vcmpe.f32 s15, s11 */
/* @0x1e37ec vmrs APSR_nzcv, fpscr */
/* @0x1e37f0 movpl r2, #0 */
/* @0x1e37f4 movmi r2, #1 */
/* @0x1e37f8 strb r2, [r1, r3] */
/* @0x1e37fc add r3, r3, #1 */
/* @0x1e3800 cmp r3, r0 */
/* @0x1e3804 bne 0x1e37d0 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x1ec> */
/* @0x1e3808 add r4, r4, #1 */
/* @0x1e380c add r5, r5, r12 */
/* @0x1e3810 cmp r4, r7 */
/* @0x1e3814 bne 0x1e3790 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x1ac> */
/* @0x1e3818 cmp r8, #0 */
/* @0x1e381c bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70> */
/* @0x1e3820 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3824 ldr r5, [r7, #0xc] */
/* @0x1e3828 ldr r11, [r7, #0x14] */
/* @0x1e382c cmp r5, r11 */
/* @0x1e3830 bgt 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68> */
/* @0x1e3834 mul r9, r12, r5 */
/* @0x1e3838 ldr r10, [r7, #0x10] */
/* @0x1e383c ldr r7, [r7, #0x8] */
/* @0x1e3840 add r11, r11, #1 */
/* @0x1e3844 add r0, r10, #1 */
/* @0x1e3848 mov r2, r4 */
/* @0x1e384c cmp r7, r10 */
/* @0x1e3850 bgt 0x1e3870 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x28c> */
/* @0x1e3854 ldr r1, [r6, #0x4] */
/* @0x1e3858 mov r3, r7 */
/* @0x1e385c add r1, r1, r9 */
/* @0x1e3860 strb r2, [r1, r3] */
/* @0x1e3864 add r3, r3, #1 */
/* @0x1e3868 cmp r3, r0 */
/* @0x1e386c bne 0x1e3860 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x27c> */
/* @0x1e3870 add r5, r5, #1 */
/* @0x1e3874 add r9, r9, r12 */
/* @0x1e3878 cmp r5, r11 */
/* @0x1e387c bne 0x1e384c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x268> */
/* @0x1e3880 cmp r8, #0 */
/* @0x1e3884 bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70> */
/* @0x1e3888 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e388c ldr r9, [r7, #0x8] */
/* @0x1e3890 vmov.f32 s15, #5.000000e-01 */
/* @0x1e3894 ldr r10, [r7, #0x10] */
/* @0x1e3898 ldr r4, [r7, #0xc] */
/* @0x1e389c add r2, r9, r10 */
/* @0x1e38a0 ldr r7, [r7, #0x14] */
/* @0x1e38a4 vmov s13, r9 */
/* @0x1e38a8 add r3, r4, r7 */
/* @0x1e38ac add r2, r2, r2, lsr #31 */
/* @0x1e38b0 cmp r4, r7 */
/* @0x1e38b4 add r3, r3, r3, lsr #31 */
/* @0x1e38b8 asr r2, r2, #1 */
/* @0x1e38bc asr r3, r3, #1 */
/* @0x1e38c0 vmov s8, r2 */
/* @0x1e38c4 vcvt.f32.s32 s14, s13 */
/* @0x1e38c8 vmov s13, r4 */
/* @0x1e38cc vcvt.f32.s32 s12, s8 */
/* @0x1e38d0 vmov s8, r3 */
/* @0x1e38d4 vcvt.f32.s32 s10, s13 */
/* @0x1e38d8 vcvt.f32.s32 s9, s8 */
/* @0x1e38dc vsub.f32 s14, s12, s14 */
/* @0x1e38e0 vsub.f32 s10, s9, s10 */
/* @0x1e38e4 vadd.f32 s14, s14, s15 */
/* @0x1e38e8 vadd.f32 s10, s10, s15 */
/* @0x1e38ec bgt 0x1e364c <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x68> */
/* @0x1e38f0 mul r5, r4, r12 */
/* @0x1e38f4 add r7, r7, #1 */
/* @0x1e38f8 add r0, r10, #1 */
/* @0x1e38fc vmov.f32 s11, #1.000000e+00 */
/* @0x1e3900 cmp r9, r10 */
/* @0x1e3904 bgt 0x1e3978 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x394> */
/* @0x1e3908 vcmpe.f32 s14, #0 */
/* @0x1e390c vmrs APSR_nzcv, fpscr */
/* @0x1e3910 ble 0x1e3978 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x394> */
/* @0x1e3914 vcmpe.f32 s10, #0 */
/* @0x1e3918 vmrs APSR_nzcv, fpscr */
/* @0x1e391c ble 0x1e3978 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x394> */
/* @0x1e3920 vmov s15, r4 */
/* @0x1e3924 ldr r1, [r6, #0x4] */
/* @0x1e3928 mov r3, r9 */
/* @0x1e392c vcvt.f32.s32 s13, s15 */
/* @0x1e3930 add r1, r1, r5 */
/* @0x1e3934 vsub.f32 s13, s13, s9 */
/* @0x1e3938 vdiv.f32 s13, s13, s10 */
/* @0x1e393c vmul.f32 s13, s13, s13 */
/* @0x1e3940 vmov s8, r3 */
/* @0x1e3944 vcvt.f32.s32 s15, s8 */
/* @0x1e3948 vsub.f32 s15, s15, s12 */
/* @0x1e394c vdiv.f32 s15, s15, s14 */
/* @0x1e3950 vmov.f32 s8, s13 */
/* @0x1e3954 vmla.f32 s8, s15, s15 */
/* @0x1e3958 vcmpe.f32 s8, s11 */
/* @0x1e395c vmrs APSR_nzcv, fpscr */
/* @0x1e3960 movpl r2, #0 */
/* @0x1e3964 movmi r2, #1 */
/* @0x1e3968 strb r2, [r1, r3] */
/* @0x1e396c add r3, r3, #1 */
/* @0x1e3970 cmp r3, r0 */
/* @0x1e3974 bne 0x1e3940 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x35c> */
/* @0x1e3978 add r4, r4, #1 */
/* @0x1e397c add r5, r5, r12 */
/* @0x1e3980 cmp r4, r7 */
/* @0x1e3984 bne 0x1e3900 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x31c> */
/* @0x1e3988 cmp r8, #0 */
/* @0x1e398c bne 0x1e3654 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii+0x70> */
/* @0x1e3990 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1e3994 · CSprite::UnpackWADMask(int) · size=452 · insn=113 */
/* @0x1e3994 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e3998 sub sp, sp, #28 */
/* @0x1e399c ldrb r5, [r0, #0x31] */
/* @0x1e39a0 str r0, [sp, #0x4] */
/* @0x1e39a4 cmp r5, #0 */
/* @0x1e39a8 bne 0x1e3b40 <_ZN7CSprite13UnpackWADMaskEi+0x1ac> */
/* @0x1e39ac ldr r6, [r0, #0x64] */
/* @0x1e39b0 cmp r6, #0 */
/* @0x1e39b4 beq 0x1e3b40 <_ZN7CSprite13UnpackWADMaskEi+0x1ac> */
/* @0x1e39b8 ldr r4, [r0, #0x68] */
/* @0x1e39bc cmp r4, #0 */
/* @0x1e39c0 beq 0x1e3b40 <_ZN7CSprite13UnpackWADMaskEi+0x1ac> */
/* @0x1e39c4 ldr r8, [sp, #0x4] */
/* @0x1e39c8 lsl r1, r6, #3 */
/* @0x1e39cc ldr r12, [pc, #0x17c] */
/* @0x1e39d0 movw r3, #0x22d */
/* @0x1e39d4 ldr r7, [pc, #0x178] */
/* @0x1e39d8 add r0, r0, #64 */
/* @0x1e39dc ldr r2, [r8, #0x18] */
/* @0x1e39e0 ldr r12, [pc, r12] */
/* @0x1e39e4 add r7, pc, r7 */
/* @0x1e39e8 subs r2, r6, r2 */
/* @0x1e39ec ldr lr, [r12] */
/* @0x1e39f0 rsbs r6, r2, #0 */
/* @0x1e39f4 adcs r6, r6, r2 */
/* @0x1e39f8 mov r2, r7 */
/* @0x1e39fc strb r6, [r8, #0x35] */
/* @0x1e3a00 add lr, lr, #1 */
/* @0x1e3a04 str lr, [r12] */
/* @0x1e3a08 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3a0c ldr r3, [r8, #0x64] */
/* @0x1e3a10 cmp r3, #0 */
/* @0x1e3a14 str r3, [r8, #0x3c] */
/* @0x1e3a18 ble 0x1e3b34 <_ZN7CSprite13UnpackWADMaskEi+0x1a0> */
/* @0x1e3a1c ldr r8, [sp, #0x4] */
/* @0x1e3a20 str r5, [sp, #0x8] */
/* @0x1e3a24 str r7, [sp, #0x14] */
/* @0x1e3a28 ldr r3, [r8, #0x1c] */
/* @0x1e3a2c ldr r2, [r8, #0x20] */
/* @0x1e3a30 ldr r8, [r8, #0x40] */
/* @0x1e3a34 mul r2, r2, r3 */
/* @0x1e3a38 str r8, [sp, #0xc] */
/* @0x1e3a3c str r2, [sp, #0x10] */
/* @0x1e3a40 ldr r8, [sp, #0x8] */
/* @0x1e3a44 movw r3, #0x233 */
/* @0x1e3a48 ldr r2, [sp, #0xc] */
/* @0x1e3a4c ldr r1, [sp, #0x10] */
/* @0x1e3a50 lsl r11, r8, #3 */
/* @0x1e3a54 add r0, r2, r11 */
/* @0x1e3a58 ldr r2, [sp, #0x14] */
/* @0x1e3a5c add r0, r0, #4 */
/* @0x1e3a60 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3a64 ldr r8, [sp, #0x4] */
/* @0x1e3a68 ldr r6, [r8, #0x1c] */
/* @0x1e3a6c ldr r9, [r8, #0x20] */
/* @0x1e3a70 ldr r2, [r8, #0x40] */
/* @0x1e3a74 adds r10, r6, #7 */
/* @0x1e3a78 ldr r8, [sp, #0x8] */
/* @0x1e3a7c addmi r10, r6, #14 */
/* @0x1e3a80 mul r3, r9, r6 */
/* @0x1e3a84 cmp r9, #0 */
/* @0x1e3a88 str r2, [sp, #0xc] */
/* @0x1e3a8c asr r10, r10, #3 */
/* @0x1e3a90 add r11, r2, r11 */
/* @0x1e3a94 str r3, [sp, #0x10] */
/* @0x1e3a98 str r3, [r2, r8, lsl #3] */
/* @0x1e3a9c ble 0x1e3b48 <_ZN7CSprite13UnpackWADMaskEi+0x1b4> */
/* @0x1e3aa0 mov r5, #0 */
/* @0x1e3aa4 mov r7, r5 */
/* @0x1e3aa8 mov r8, r5 */
/* @0x1e3aac cmp r6, #0 */
/* @0x1e3ab0 ble 0x1e3afc <_ZN7CSprite13UnpackWADMaskEi+0x168> */
/* @0x1e3ab4 ldr r2, [r11, #0x4] */
/* @0x1e3ab8 mov r1, r8 */
/* @0x1e3abc mov r3, #128 */
/* @0x1e3ac0 add r12, r2, r6 */
/* @0x1e3ac4 add r2, r2, r5 */
/* @0x1e3ac8 add r12, r12, r5 */
/* @0x1e3acc b 0x1e3adc <_ZN7CSprite13UnpackWADMaskEi+0x148> */
/* @0x1e3ad0 cmp r3, #0 */
/* @0x1e3ad4 addeq r1, r1, #1 */
/* @0x1e3ad8 moveq r3, #128 */
/* @0x1e3adc ldrb r0, [r4, r1] */
/* @0x1e3ae0 tst r3, r0 */
/* @0x1e3ae4 lsr r3, r3, #1 */
/* @0x1e3ae8 moveq r0, #0 */
/* @0x1e3aec movne r0, #1 */
/* @0x1e3af0 strb r0, [r2], #1 */
/* @0x1e3af4 cmp r2, r12 */
/* @0x1e3af8 bne 0x1e3ad0 <_ZN7CSprite13UnpackWADMaskEi+0x13c> */
/* @0x1e3afc add r7, r7, #1 */
/* @0x1e3b00 add r8, r8, r10 */
/* @0x1e3b04 cmp r7, r9 */
/* @0x1e3b08 add r5, r5, r6 */
/* @0x1e3b0c bne 0x1e3aac <_ZN7CSprite13UnpackWADMaskEi+0x118> */
/* @0x1e3b10 mul r7, r10, r7 */
/* @0x1e3b14 ldr r8, [sp, #0x4] */
/* @0x1e3b18 add r4, r4, r7 */
/* @0x1e3b1c ldr r3, [r8, #0x64] */
/* @0x1e3b20 ldr r8, [sp, #0x8] */
/* @0x1e3b24 add r8, r8, #1 */
/* @0x1e3b28 str r8, [sp, #0x8] */
/* @0x1e3b2c cmp r8, r3 */
/* @0x1e3b30 blt 0x1e3a40 <_ZN7CSprite13UnpackWADMaskEi+0xac> */
/* @0x1e3b34 ldr r8, [sp, #0x4] */
/* @0x1e3b38 mov r3, #1 */
/* @0x1e3b3c strb r3, [r8, #0x31] */
/* @0x1e3b40 add sp, sp, #28 */
/* @0x1e3b44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3b48 mov r7, #0 */
/* @0x1e3b4c b 0x1e3b14 <_ZN7CSprite13UnpackWADMaskEi+0x180> */
/* @0x1e3b50 eoreq sp, r0, r12, ror #7 */
/* @0x1e3b54 andseq lr, r6, r0, asr #20 */

/* ── FUNC 0x1e3b58 · CSprite::FreeMask() · size=116 · insn=29 */
/* @0x1e3b58 push {r3, r4, r5, r6, r7, lr} */
/* @0x1e3b5c mov r6, r0 */
/* @0x1e3b60 ldrb r3, [r0, #0x31] */
/* @0x1e3b64 cmp r3, #0 */
/* @0x1e3b68 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1e3b6c ldr r3, [r0, #0x3c] */
/* @0x1e3b70 ldr r0, [r0, #0x40] */
/* @0x1e3b74 cmp r3, #0 */
/* @0x1e3b78 movgt r4, #0 */
/* @0x1e3b7c movgt r7, r4 */
/* @0x1e3b80 ble 0x1e3bb4 <_ZN7CSprite8FreeMaskEv+0x5c> */
/* @0x1e3b84 lsl r5, r4, #3 */
/* @0x1e3b88 add r3, r0, r5 */
/* @0x1e3b8c ldr r0, [r3, #0x4] */
/* @0x1e3b90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e3b94 ldr r0, [r6, #0x40] */
/* @0x1e3b98 ldr r2, [r6, #0x3c] */
/* @0x1e3b9c add r5, r0, r5 */
/* @0x1e3ba0 str r7, [r5, #0x4] */
/* @0x1e3ba4 str r7, [r0, r4, lsl #3] */
/* @0x1e3ba8 add r4, r4, #1 */
/* @0x1e3bac cmp r4, r2 */
/* @0x1e3bb0 blt 0x1e3b84 <_ZN7CSprite8FreeMaskEv+0x2c> */
/* @0x1e3bb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e3bb8 mov r3, #0 */
/* @0x1e3bbc str r3, [r6, #0x40] */
/* @0x1e3bc0 str r3, [r6, #0x3c] */
/* @0x1e3bc4 strb r3, [r6, #0x31] */
/* @0x1e3bc8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1e3bcc · CSprite::CreateMask() · size=412 · insn=103 */
/* @0x1e3bcc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e3bd0 mov r8, r0 */
/* @0x1e3bd4 ldrb r3, [r0, #0x31] */
/* @0x1e3bd8 cmp r3, #0 */
/* @0x1e3bdc bne 0x1e3d5c <_ZN7CSprite10CreateMaskEv+0x190> */
/* @0x1e3be0 ldrb r3, [r8, #0x30] */
/* @0x1e3be4 cmp r3, #0 */
/* @0x1e3be8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3bec ldrb r3, [r8, #0x32] */
/* @0x1e3bf0 cmp r3, #0 */
/* @0x1e3bf4 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3bf8 ldr r1, [r8, #0x18] */
/* @0x1e3bfc cmp r1, #0 */
/* @0x1e3c00 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3c04 ldr r3, [r8, #0x74] */
/* @0x1e3c08 cmp r3, #0 */
/* @0x1e3c0c popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3c10 ldr r3, [r8, #0x54] */
/* @0x1e3c14 cmp r3, #0 */
/* @0x1e3c18 beq 0x1e3c28 <_ZN7CSprite10CreateMaskEv+0x5c> */
/* @0x1e3c1c ldrb r3, [r8, #0x36] */
/* @0x1e3c20 cmp r3, #0 */
/* @0x1e3c24 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3c28 ldr r5, [pc, #0x134] */
/* @0x1e3c2c mov r3, #268 */
/* @0x1e3c30 lsl r1, r1, #3 */
/* @0x1e3c34 add r0, r8, #64 */
/* @0x1e3c38 add r5, pc, r5 */
/* @0x1e3c3c mov r2, r5 */
/* @0x1e3c40 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3c44 ldr r3, [r8, #0x18] */
/* @0x1e3c48 cmp r3, #0 */
/* @0x1e3c4c str r3, [r8, #0x3c] */
/* @0x1e3c50 ble 0x1e3d50 <_ZN7CSprite10CreateMaskEv+0x184> */
/* @0x1e3c54 ldr r1, [r8, #0x1c] */
/* @0x1e3c58 mov r4, #0 */
/* @0x1e3c5c ldr r0, [r8, #0x20] */
/* @0x1e3c60 ldr r3, [r8, #0x40] */
/* @0x1e3c64 mul r1, r0, r1 */
/* @0x1e3c68 add r0, r3, r4, lsl #3 */
/* @0x1e3c6c mov r2, r5 */
/* @0x1e3c70 add r0, r0, #4 */
/* @0x1e3c74 mov r3, #272 */
/* @0x1e3c78 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3c7c ldr r1, [r8, #0x1c] */
/* @0x1e3c80 ldr r0, [r8, #0x20] */
/* @0x1e3c84 ldr r3, [r8, #0x40] */
/* @0x1e3c88 ldr r12, [r8, #0x18] */
/* @0x1e3c8c mul r1, r0, r1 */
/* @0x1e3c90 str r1, [r3, r4, lsl #3] */
/* @0x1e3c94 add r4, r4, #1 */
/* @0x1e3c98 cmp r12, r4 */
/* @0x1e3c9c bgt 0x1e3c68 <_ZN7CSprite10CreateMaskEv+0x9c> */
/* @0x1e3ca0 cmp r12, #0 */
/* @0x1e3ca4 ble 0x1e3d50 <_ZN7CSprite10CreateMaskEv+0x184> */
/* @0x1e3ca8 mov r10, #0 */
/* @0x1e3cac ldr r3, [r8, #0x48] */
/* @0x1e3cb0 ldr r0, [r3, r10, lsl #2] */
/* @0x1e3cb4 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e3cb8 ldr r3, [r8, #0x48] */
/* @0x1e3cbc ldr r0, [r3, r10, lsl #2] */
/* @0x1e3cc0 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e3cc4 ldr r9, [r8, #0x20] */
/* @0x1e3cc8 cmp r9, #0 */
/* @0x1e3ccc ldr r7, [r0, #0x4] */
/* @0x1e3cd0 ble 0x1e3d40 <_ZN7CSprite10CreateMaskEv+0x174> */
/* @0x1e3cd4 ldr r6, [r8, #0x1c] */
/* @0x1e3cd8 mov r4, #0 */
/* @0x1e3cdc sub r7, r7, #4 */
/* @0x1e3ce0 lsl r11, r10, #3 */
/* @0x1e3ce4 mov r5, r4 */
/* @0x1e3ce8 lsl r0, r6, #2 */
/* @0x1e3cec cmp r6, #0 */
/* @0x1e3cf0 ble 0x1e3d2c <_ZN7CSprite10CreateMaskEv+0x160> */
/* @0x1e3cf4 ldr r3, [r8, #0x40] */
/* @0x1e3cf8 mov r2, r7 */
/* @0x1e3cfc add r3, r3, r11 */
/* @0x1e3d00 ldr r3, [r3, #0x4] */
/* @0x1e3d04 add r12, r3, r6 */
/* @0x1e3d08 add r3, r3, r4 */
/* @0x1e3d0c add r12, r12, r4 */
/* @0x1e3d10 ldr r1, [r2, #0x4]! */
/* @0x1e3d14 tst r1, #-16777216 */
/* @0x1e3d18 moveq r1, #0 */
/* @0x1e3d1c movne r1, #1 */
/* @0x1e3d20 strb r1, [r3], #1 */
/* @0x1e3d24 cmp r3, r12 */
/* @0x1e3d28 bne 0x1e3d10 <_ZN7CSprite10CreateMaskEv+0x144> */
/* @0x1e3d2c add r5, r5, #1 */
/* @0x1e3d30 add r7, r7, r0 */
/* @0x1e3d34 cmp r5, r9 */
/* @0x1e3d38 add r4, r4, r6 */
/* @0x1e3d3c bne 0x1e3cec <_ZN7CSprite10CreateMaskEv+0x120> */
/* @0x1e3d40 ldr r3, [r8, #0x18] */
/* @0x1e3d44 add r10, r10, #1 */
/* @0x1e3d48 cmp r10, r3 */
/* @0x1e3d4c blt 0x1e3cac <_ZN7CSprite10CreateMaskEv+0xe0> */
/* @0x1e3d50 mov r3, #1 */
/* @0x1e3d54 strb r3, [r8, #0x31] */
/* @0x1e3d58 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3d5c bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv> */
/* @0x1e3d60 b 0x1e3be0 <_ZN7CSprite10CreateMaskEv+0x14> */
/* @0x1e3d64 andseq lr, r6, r12, ror #15 */

/* ── FUNC 0x1e3d68 · CSprite::SetCollisionChecking(bool) · size=32 · insn=8 */
/* @0x1e3d68 ldrb r2, [r0, #0x30] */
/* @0x1e3d6c cmp r2, r1 */
/* @0x1e3d70 bxeq lr */
/* @0x1e3d74 ldr r2, [r0, #0x74] */
/* @0x1e3d78 strb r1, [r0, #0x30] */
/* @0x1e3d7c cmp r2, #0 */
/* @0x1e3d80 bxne lr */
/* @0x1e3d84 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */

/* ── FUNC 0x1e3d88 · CSprite::ComputeMask(bool, int, tagYYRECT const&, int, int) · size=1296 · insn=324 */
/* @0x1e3d88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e3d8c sub sp, sp, #52 */
/* @0x1e3d90 mov r11, r0 */
/* @0x1e3d94 mov r6, r3 */
/* @0x1e3d98 str r1, [sp, #0x28] */
/* @0x1e3d9c ldr r1, [r0, #0x74] */
/* @0x1e3da0 str r2, [sp, #0x24] */
/* @0x1e3da4 cmp r1, #0 */
/* @0x1e3da8 ldr r10, [sp, #0x5c] */
/* @0x1e3dac bne 0x1e3ecc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x144> */
/* @0x1e3db0 ldrb r3, [r0, #0x31] */
/* @0x1e3db4 cmp r3, #0 */
/* @0x1e3db8 bne 0x1e3ed4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x14c> */
/* @0x1e3dbc ldr r3, [r11, #0x54] */
/* @0x1e3dc0 cmp r3, #0 */
/* @0x1e3dc4 beq 0x1e3dd4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4c> */
/* @0x1e3dc8 ldrb r3, [r11, #0x36] */
/* @0x1e3dcc cmp r3, #0 */
/* @0x1e3dd0 beq 0x1e3ecc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x144> */
/* @0x1e3dd4 ldr r5, [pc, #0x4b8] */
/* @0x1e3dd8 mov r3, #400 */
/* @0x1e3ddc ldr r1, [r11, #0x18] */
/* @0x1e3de0 add r0, r11, #64 */
/* @0x1e3de4 add r5, pc, r5 */
/* @0x1e3de8 lsl r1, r1, #3 */
/* @0x1e3dec mov r2, r5 */
/* @0x1e3df0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3df4 ldr r3, [r11, #0x18] */
/* @0x1e3df8 cmp r3, #0 */
/* @0x1e3dfc str r3, [r11, #0x3c] */
/* @0x1e3e00 ble 0x1e3e54 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xcc> */
/* @0x1e3e04 ldr r1, [r11, #0x1c] */
/* @0x1e3e08 mov r4, #0 */
/* @0x1e3e0c ldr r3, [r11, #0x20] */
/* @0x1e3e10 ldr r2, [r11, #0x40] */
/* @0x1e3e14 mul r1, r1, r3 */
/* @0x1e3e18 mov r0, r2 */
/* @0x1e3e1c add r0, r0, r4, lsl #3 */
/* @0x1e3e20 mov r2, r5 */
/* @0x1e3e24 add r0, r0, #4 */
/* @0x1e3e28 mov r3, #404 */
/* @0x1e3e2c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e3e30 ldr r2, [r11, #0x1c] */
/* @0x1e3e34 ldr r1, [r11, #0x20] */
/* @0x1e3e38 ldr r0, [r11, #0x40] */
/* @0x1e3e3c ldr r3, [r11, #0x18] */
/* @0x1e3e40 mul r1, r1, r2 */
/* @0x1e3e44 str r1, [r0, r4, lsl #3] */
/* @0x1e3e48 add r4, r4, #1 */
/* @0x1e3e4c cmp r3, r4 */
/* @0x1e3e50 bgt 0x1e3e1c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x94> */
/* @0x1e3e54 ldr r4, [sp, #0x24] */
/* @0x1e3e58 cmp r4, #1 */
/* @0x1e3e5c beq 0x1e4258 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4d0> */
/* @0x1e3e60 cmp r4, #2 */
/* @0x1e3e64 beq 0x1e3edc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x154> */
/* @0x1e3e68 cmp r4, #0 */
/* @0x1e3e6c beq 0x1e3ff0 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x268> */
/* @0x1e3e70 ldr r4, [sp, #0x28] */
/* @0x1e3e74 cmp r4, #0 */
/* @0x1e3e78 beq 0x1e3f74 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x1ec> */
/* @0x1e3e7c cmp r3, #0 */
/* @0x1e3e80 ble 0x1e3ec4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x13c> */
/* @0x1e3e84 ldr r5, [sp, #0x24] */
/* @0x1e3e88 mov r4, #0 */
/* @0x1e3e8c ldr r6, [sp, #0x58] */
/* @0x1e3e90 ldr r3, [r11, #0x48] */
/* @0x1e3e94 mov r0, r11 */
/* @0x1e3e98 ldr r2, [r11, #0x40] */
/* @0x1e3e9c mov r1, #0 */
/* @0x1e3ea0 ldr r3, [r3, r4, lsl #2] */
/* @0x1e3ea4 add r2, r2, r4, lsl #3 */
/* @0x1e3ea8 str r5, [sp] */
/* @0x1e3eac add r4, r4, #1 */
/* @0x1e3eb0 stmib sp, {r6, r10} */
/* @0x1e3eb4 bl 0x1e35e4 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii> */
/* @0x1e3eb8 ldr r3, [r11, #0x18] */
/* @0x1e3ebc cmp r3, r4 */
/* @0x1e3ec0 bgt 0x1e3e90 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x108> */
/* @0x1e3ec4 mov r3, #1 */
/* @0x1e3ec8 strb r3, [r11, #0x31] */
/* @0x1e3ecc add sp, sp, #52 */
/* @0x1e3ed0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e3ed4 bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv> */
/* @0x1e3ed8 b 0x1e3dbc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x34> */
/* @0x1e3edc ldr r2, [r6] */
/* @0x1e3ee0 cmp r2, #0 */
/* @0x1e3ee4 movlt r1, #0 */
/* @0x1e3ee8 blt 0x1e3efc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x174> */
/* @0x1e3eec ldr r1, [r11, #0x1c] */
/* @0x1e3ef0 cmp r2, r1 */
/* @0x1e3ef4 subge r1, r1, #1 */
/* @0x1e3ef8 movlt r1, r2 */
/* @0x1e3efc ldr r2, [r6, #0x8] */
/* @0x1e3f00 str r1, [r11, #0x8] */
/* @0x1e3f04 cmp r2, #0 */
/* @0x1e3f08 movlt r1, #0 */
/* @0x1e3f0c blt 0x1e3f20 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x198> */
/* @0x1e3f10 ldr r1, [r11, #0x1c] */
/* @0x1e3f14 cmp r2, r1 */
/* @0x1e3f18 subge r1, r1, #1 */
/* @0x1e3f1c movlt r1, r2 */
/* @0x1e3f20 ldr r2, [r6, #0x4] */
/* @0x1e3f24 str r1, [r11, #0x10] */
/* @0x1e3f28 cmp r2, #0 */
/* @0x1e3f2c movlt r1, #0 */
/* @0x1e3f30 blt 0x1e3f44 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x1bc> */
/* @0x1e3f34 ldr r1, [r11, #0x20] */
/* @0x1e3f38 cmp r2, r1 */
/* @0x1e3f3c subge r1, r1, #1 */
/* @0x1e3f40 movlt r1, r2 */
/* @0x1e3f44 ldr r2, [r6, #0xc] */
/* @0x1e3f48 str r1, [r11, #0xc] */
/* @0x1e3f4c cmp r2, #0 */
/* @0x1e3f50 movlt r2, #0 */
/* @0x1e3f54 blt 0x1e3f64 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x1dc> */
/* @0x1e3f58 ldr r1, [r11, #0x20] */
/* @0x1e3f5c cmp r2, r1 */
/* @0x1e3f60 subge r2, r1, #1 */
/* @0x1e3f64 ldr r4, [sp, #0x28] */
/* @0x1e3f68 str r2, [r11, #0x14] */
/* @0x1e3f6c cmp r4, #0 */
/* @0x1e3f70 bne 0x1e3e7c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xf4> */
/* @0x1e3f74 ldr r3, [r11, #0x48] */
/* @0x1e3f78 mov r0, r11 */
/* @0x1e3f7c ldr r12, [sp, #0x24] */
/* @0x1e3f80 ldr r4, [sp, #0x58] */
/* @0x1e3f84 ldr r3, [r3] */
/* @0x1e3f88 ldr r2, [r11, #0x40] */
/* @0x1e3f8c ldr r1, [sp, #0x28] */
/* @0x1e3f90 str r12, [sp] */
/* @0x1e3f94 stmib sp, {r4, r10} */
/* @0x1e3f98 bl 0x1e35e4 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii> */
/* @0x1e3f9c ldr r3, [r11, #0x18] */
/* @0x1e3fa0 cmp r3, #1 */
/* @0x1e3fa4 ble 0x1e3ec4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x13c> */
/* @0x1e3fa8 ldr r5, [sp, #0x24] */
/* @0x1e3fac mov r4, #1 */
/* @0x1e3fb0 ldr r6, [sp, #0x58] */
/* @0x1e3fb4 ldr r3, [r11, #0x48] */
/* @0x1e3fb8 mov r0, r11 */
/* @0x1e3fbc ldr r1, [r11, #0x40] */
/* @0x1e3fc0 ldr r3, [r3, r4, lsl #2] */
/* @0x1e3fc4 add r2, r1, r4, lsl #3 */
/* @0x1e3fc8 stm sp, {r5, r6} */
/* @0x1e3fcc add r4, r4, #1 */
/* @0x1e3fd0 str r10, [sp, #0x8] */
/* @0x1e3fd4 bl 0x1e35e4 <_ZN7CSprite11TMaskCreateEP5CMaskS1_P9CBitmap32iii> */
/* @0x1e3fd8 ldr r3, [r11, #0x18] */
/* @0x1e3fdc cmp r3, r4 */
/* @0x1e3fe0 bgt 0x1e3fb4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x22c> */
/* @0x1e3fe4 mov r3, #1 */
/* @0x1e3fe8 strb r3, [r11, #0x31] */
/* @0x1e3fec b 0x1e3ecc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x144> */
/* @0x1e3ff0 cmp r3, #0 */
/* @0x1e3ff4 mvn r1, #-2147483648 */
/* @0x1e3ff8 mov r2, #-2147483648 */
/* @0x1e3ffc str r1, [r11, #0x8] */
/* @0x1e4000 str r1, [r11, #0xc] */
/* @0x1e4004 str r2, [r11, #0x10] */
/* @0x1e4008 str r2, [r11, #0x14] */
/* @0x1e400c ldrb r4, [r11, #0x36] */
/* @0x1e4010 ble 0x1e41cc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x444> */
/* @0x1e4014 ldr r12, [sp, #0x24] */
/* @0x1e4018 str r12, [sp, #0x20] */
/* @0x1e401c ldr r3, [r11, #0x48] */
/* @0x1e4020 ldr r12, [sp, #0x20] */
/* @0x1e4024 ldr r2, [sp, #0x20] */
/* @0x1e4028 ldr r5, [r3, r12, lsl #2] */
/* @0x1e402c lsl r2, r2, #2 */
/* @0x1e4030 str r2, [sp, #0x2c] */
/* @0x1e4034 mov r0, r5 */
/* @0x1e4038 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e403c mov r0, r5 */
/* @0x1e4040 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1e4044 ldr r2, [r11, #0x20] */
/* @0x1e4048 cmp r2, #0 */
/* @0x1e404c str r2, [sp, #0x18] */
/* @0x1e4050 ldr r5, [r0, #0x4] */
/* @0x1e4054 ble 0x1e4280 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4f8> */
/* @0x1e4058 ldr r0, [r11, #0x1c] */
/* @0x1e405c mov r7, #-2147483648 */
/* @0x1e4060 mvn r6, #-2147483648 */
/* @0x1e4064 sub r5, r5, #4 */
/* @0x1e4068 mov r9, r7 */
/* @0x1e406c mov r8, r6 */
/* @0x1e4070 mov r2, #0 */
/* @0x1e4074 lsl r3, r0, #2 */
/* @0x1e4078 str r3, [sp, #0x1c] */
/* @0x1e407c cmp r0, #0 */
/* @0x1e4080 ble 0x1e4124 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x39c> */
/* @0x1e4084 cmp r4, #0 */
/* @0x1e4088 beq 0x1e41e4 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x45c> */
/* @0x1e408c mov r12, r5 */
/* @0x1e4090 mov r3, #0 */
/* @0x1e4094 str r4, [sp, #0x14] */
/* @0x1e4098 b 0x1e40fc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x374> */
/* @0x1e409c ldr r4, [r11, #0x8] */
/* @0x1e40a0 cmp r4, r3 */
/* @0x1e40a4 ldr r4, [r11, #0x10] */
/* @0x1e40a8 strgt r3, [r11, #0x8] */
/* @0x1e40ac cmp r4, r3 */
/* @0x1e40b0 ldr r4, [r11, #0xc] */
/* @0x1e40b4 strlt r3, [r11, #0x10] */
/* @0x1e40b8 cmp r4, r2 */
/* @0x1e40bc ldr r4, [r11, #0x14] */
/* @0x1e40c0 strgt r2, [r11, #0xc] */
/* @0x1e40c4 cmp r4, r2 */
/* @0x1e40c8 bge 0x1e410c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x384> */
/* @0x1e40cc str r2, [r11, #0x14] */
/* @0x1e40d0 cmp r8, r3 */
/* @0x1e40d4 movge r8, r3 */
/* @0x1e40d8 cmp r9, r3 */
/* @0x1e40dc movlt r9, r3 */
/* @0x1e40e0 add r3, r3, #1 */
/* @0x1e40e4 cmp r6, r2 */
/* @0x1e40e8 movge r6, r2 */
/* @0x1e40ec cmp r7, r2 */
/* @0x1e40f0 movlt r7, r2 */
/* @0x1e40f4 cmp r3, r0 */
/* @0x1e40f8 beq 0x1e4120 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x398> */
/* @0x1e40fc ldr r1, [r12, #0x4]! */
/* @0x1e4100 and r1, r1, #-16777216 */
/* @0x1e4104 cmp r1, r10 */
/* @0x1e4108 bhi 0x1e409c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x314> */
/* @0x1e410c cmp r1, #0 */
/* @0x1e4110 bne 0x1e40d0 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x348> */
/* @0x1e4114 add r3, r3, #1 */
/* @0x1e4118 cmp r3, r0 */
/* @0x1e411c bne 0x1e40fc <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x374> */
/* @0x1e4120 ldr r4, [sp, #0x14] */
/* @0x1e4124 ldr r3, [sp, #0x18] */
/* @0x1e4128 add r2, r2, #1 */
/* @0x1e412c ldr r12, [sp, #0x1c] */
/* @0x1e4130 cmp r2, r3 */
/* @0x1e4134 add r5, r5, r12 */
/* @0x1e4138 bne 0x1e407c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x2f4> */
/* @0x1e413c cmp r4, #0 */
/* @0x1e4140 beq 0x1e41a8 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x420> */
/* @0x1e4144 ldr r3, [r11, #0x54] */
/* @0x1e4148 cmn r8, #-2147483647 */
/* @0x1e414c ldr r12, [sp, #0x2c] */
/* @0x1e4150 ldr r3, [r3, r12] */
/* @0x1e4154 beq 0x1e423c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4b4> */
/* @0x1e4158 uxth r1, r6 */
/* @0x1e415c uxth r12, r8 */
/* @0x1e4160 add r0, r9, #1 */
/* @0x1e4164 add r2, r7, #1 */
/* @0x1e4168 rsb r0, r12, r0 */
/* @0x1e416c rsb r2, r1, r2 */
/* @0x1e4170 ldrh r5, [r3] */
/* @0x1e4174 strh r6, [r3, #10] */
/* @0x1e4178 uxth r0, r0 */
/* @0x1e417c ldrh r6, [r3, #2] */
/* @0x1e4180 uxth r2, r2 */
/* @0x1e4184 add r12, r12, r5 */
/* @0x1e4188 strh r8, [r3, #8] */
/* @0x1e418c add r1, r1, r6 */
/* @0x1e4190 strh r0, [r3, #12] */
/* @0x1e4194 strh r0, [r3, #4] */
/* @0x1e4198 strh r2, [r3, #14] */
/* @0x1e419c strh r2, [r3, #6] */
/* @0x1e41a0 strh r12, [r3] */
/* @0x1e41a4 strh r1, [r3, #2] */
/* @0x1e41a8 ldr r2, [sp, #0x20] */
/* @0x1e41ac ldr r3, [r11, #0x18] */
/* @0x1e41b0 add r2, r2, #1 */
/* @0x1e41b4 str r2, [sp, #0x20] */
/* @0x1e41b8 cmp r3, r2 */
/* @0x1e41bc bgt 0x1e401c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x294> */
/* @0x1e41c0 ldr r2, [r11, #0x8] */
/* @0x1e41c4 cmn r2, #-2147483647 */
/* @0x1e41c8 bne 0x1e3e70 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xe8> */
/* @0x1e41cc mov r2, #0 */
/* @0x1e41d0 str r2, [r11, #0x8] */
/* @0x1e41d4 str r2, [r11, #0x10] */
/* @0x1e41d8 str r2, [r11, #0xc] */
/* @0x1e41dc str r2, [r11, #0x14] */
/* @0x1e41e0 b 0x1e3e70 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xe8> */
/* @0x1e41e4 mov r1, r5 */
/* @0x1e41e8 mov r3, r4 */
/* @0x1e41ec ldr r12, [r1, #0x4]! */
/* @0x1e41f0 and r12, r12, #-16777216 */
/* @0x1e41f4 cmp r10, r12 */
/* @0x1e41f8 bhs 0x1e422c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x4a4> */
/* @0x1e41fc ldr r12, [r11, #0x8] */
/* @0x1e4200 cmp r3, r12 */
/* @0x1e4204 ldr r12, [r11, #0x10] */
/* @0x1e4208 strlt r3, [r11, #0x8] */
/* @0x1e420c cmp r3, r12 */
/* @0x1e4210 ldr r12, [r11, #0xc] */
/* @0x1e4214 strgt r3, [r11, #0x10] */
/* @0x1e4218 cmp r12, r2 */
/* @0x1e421c ldr r12, [r11, #0x14] */
/* @0x1e4220 strgt r2, [r11, #0xc] */
/* @0x1e4224 cmp r12, r2 */
/* @0x1e4228 strlt r2, [r11, #0x14] */
/* @0x1e422c add r3, r3, #1 */
/* @0x1e4230 cmp r3, r0 */
/* @0x1e4234 bne 0x1e41ec <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x464> */
/* @0x1e4238 b 0x1e4124 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x39c> */
/* @0x1e423c mov r2, #0 */
/* @0x1e4240 mov r12, #1 */
/* @0x1e4244 strh r2, [r3, #8] */
/* @0x1e4248 strh r2, [r3, #10] */
/* @0x1e424c strh r12, [r3, #12] */
/* @0x1e4250 strh r12, [r3, #14] */
/* @0x1e4254 b 0x1e41a8 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x420> */
/* @0x1e4258 ldr r0, [r11, #0x1c] */
/* @0x1e425c mov r2, #0 */
/* @0x1e4260 ldr r1, [r11, #0x20] */
/* @0x1e4264 sub r0, r0, #1 */
/* @0x1e4268 str r2, [r11, #0x8] */
/* @0x1e426c sub r1, r1, #1 */
/* @0x1e4270 str r0, [r11, #0x10] */
/* @0x1e4274 str r2, [r11, #0xc] */
/* @0x1e4278 str r1, [r11, #0x14] */
/* @0x1e427c b 0x1e3e70 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0xe8> */
/* @0x1e4280 mov r7, #-2147483648 */
/* @0x1e4284 mvn r6, #-2147483648 */
/* @0x1e4288 mov r9, r7 */
/* @0x1e428c mov r8, r6 */
/* @0x1e4290 b 0x1e413c <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii+0x3b4> */
/* @0x1e4294 andseq lr, r6, r0, asr #12 */

/* ── FUNC 0x1e4298 · CSprite::PreciseCollision(int, tagYYRECT*, int, int, float, float, float, CSprite*, int, tagYYRECT*, int, int, float, float, float) · size=1944 · insn=486 */
/* @0x1e4298 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e429c vpush {d8, d9, d10, d11, d12} */
/* @0x1e42a0 mov r4, r0 */
/* @0x1e42a4 ldr r7, [pc, #0x778] */
/* @0x1e42a8 sub sp, sp, #44 */
/* @0x1e42ac ldr r0, [pc, #0x774] */
/* @0x1e42b0 mov r10, r1 */
/* @0x1e42b4 add r7, pc, r7 */
/* @0x1e42b8 str r3, [sp, #0xc] */
/* @0x1e42bc str r7, [sp, #0x1c] */
/* @0x1e42c0 mov r5, r2 */
/* @0x1e42c4 ldr r0, [r7, r0] */
/* @0x1e42c8 ldr r9, [sp, #0x78] */
/* @0x1e42cc ldr r6, [sp, #0x88] */
/* @0x1e42d0 ldrb r3, [r0] */
/* @0x1e42d4 str r0, [sp, #0x20] */
/* @0x1e42d8 cmp r3, #0 */
/* @0x1e42dc ldr r11, [sp, #0x98] */
/* @0x1e42e0 bne 0x1e4790 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4f8> */
/* @0x1e42e4 cmp r6, #0 */
/* @0x1e42e8 beq 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e42ec ldr r3, [r4, #0x18] */
/* @0x1e42f0 cmp r3, #0 */
/* @0x1e42f4 ble 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e42f8 ldr r3, [r6, #0x18] */
/* @0x1e42fc cmp r3, #0 */
/* @0x1e4300 ble 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e4304 mov r0, r4 */
/* @0x1e4308 mov r1, r10 */
/* @0x1e430c bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e4310 mov r0, r6 */
/* @0x1e4314 ldr r1, [sp, #0x8c] */
/* @0x1e4318 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e431c ldr r7, [r4, #0x3c] */
/* @0x1e4320 cmp r7, #0 */
/* @0x1e4324 ble 0x1e4338 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0xa0> */
/* @0x1e4328 mov r0, r10 */
/* @0x1e432c mov r1, r7 */
/* @0x1e4330 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4334 mov r10, r1 */
/* @0x1e4338 cmp r10, #0 */
/* @0x1e433c addlt r10, r10, r7 */
/* @0x1e4340 ldr r7, [r6, #0x3c] */
/* @0x1e4344 cmp r7, #0 */
/* @0x1e4348 ble 0x1e435c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0xc4> */
/* @0x1e434c ldr r0, [sp, #0x8c] */
/* @0x1e4350 mov r1, r7 */
/* @0x1e4354 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4358 str r1, [sp, #0x8c] */
/* @0x1e435c vmov.f32 s15, #1.000000e+00 */
/* @0x1e4360 vldr s5, [sp, #124] */
/* @0x1e4364 vldr s8, [sp, #156] */
/* @0x1e4368 ldr r12, [sp, #0x8c] */
/* @0x1e436c ldr r3, [r5] */
/* @0x1e4370 vldr s11, [sp, #128] */
/* @0x1e4374 cmp r12, #0 */
/* @0x1e4378 ldr r1, [r5, #0x8] */
/* @0x1e437c addlt r12, r12, r7 */
/* @0x1e4380 strlt r12, [sp, #0x8c] */
/* @0x1e4384 ldr r12, [sp, #0x90] */
/* @0x1e4388 vldr s13, [sp, #160] */
/* @0x1e438c ldr r2, [r5, #0x4] */
/* @0x1e4390 ldr r7, [r12] */
/* @0x1e4394 ldr r0, [r12, #0x8] */
/* @0x1e4398 vdiv.f32 s16, s15, s5 */
/* @0x1e439c cmp r7, r3 */
/* @0x1e43a0 movlt r7, r3 */
/* @0x1e43a4 ldr r8, [r12, #0x4] */
/* @0x1e43a8 cmp r0, r1 */
/* @0x1e43ac movge r0, r1 */
/* @0x1e43b0 ldr r3, [r5, #0xc] */
/* @0x1e43b4 ldr r5, [r12, #0xc] */
/* @0x1e43b8 cmp r8, r2 */
/* @0x1e43bc movlt r8, r2 */
/* @0x1e43c0 str r0, [sp, #0x18] */
/* @0x1e43c4 cmp r5, r3 */
/* @0x1e43c8 movge r5, r3 */
/* @0x1e43cc vdiv.f32 s20, s15, s8 */
/* @0x1e43d0 vcmp.f32 s16, s15 */
/* @0x1e43d4 vmrs APSR_nzcv, fpscr */
/* @0x1e43d8 vcmp.f32 s20, s15 */
/* @0x1e43dc movne r3, #0 */
/* @0x1e43e0 moveq r3, #1 */
/* @0x1e43e4 vmrs APSR_nzcv, fpscr */
/* @0x1e43e8 movne r3, #0 */
/* @0x1e43ec andeq r3, r3, #1 */
/* @0x1e43f0 cmp r3, #0 */
/* @0x1e43f4 vdiv.f32 s18, s15, s11 */
/* @0x1e43f8 vdiv.f32 s21, s15, s13 */
/* @0x1e43fc beq 0x1e45cc <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x334> */
/* @0x1e4400 vcmp.f32 s18, s15 */
/* @0x1e4404 vmrs APSR_nzcv, fpscr */
/* @0x1e4408 vcmp.f32 s21, s15 */
/* @0x1e440c movne r3, #0 */
/* @0x1e4410 moveq r3, #1 */
/* @0x1e4414 vmrs APSR_nzcv, fpscr */
/* @0x1e4418 movne r3, #0 */
/* @0x1e441c andeq r3, r3, #1 */
/* @0x1e4420 cmp r3, #0 */
/* @0x1e4424 beq 0x1e45cc <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x334> */
/* @0x1e4428 vldr s14, [sp, #132] */
/* @0x1e442c vcmp.f32 s14, #0 */
/* @0x1e4430 vldr s15, [sp, #164] */
/* @0x1e4434 vmrs APSR_nzcv, fpscr */
/* @0x1e4438 vcmp.f32 s15, #0 */
/* @0x1e443c movne r3, #0 */
/* @0x1e4440 moveq r3, #1 */
/* @0x1e4444 vmrs APSR_nzcv, fpscr */
/* @0x1e4448 movne r3, #0 */
/* @0x1e444c andeq r3, r3, #1 */
/* @0x1e4450 cmp r3, #0 */
/* @0x1e4454 str r3, [sp, #0x14] */
/* @0x1e4458 beq 0x1e47a8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x510> */
/* @0x1e445c cmp r0, r7 */
/* @0x1e4460 blt 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e4464 ldr r0, [sp, #0x8c] */
/* @0x1e4468 lsl r10, r10, #3 */
/* @0x1e446c rsb r9, r9, r8 */
/* @0x1e4470 str r10, [sp, #0x8] */
/* @0x1e4474 str r9, [sp, #0x10] */
/* @0x1e4478 lsl r0, r0, #3 */
/* @0x1e447c str r11, [sp, #0x4] */
/* @0x1e4480 str r0, [sp, #0x24] */
/* @0x1e4484 cmp r8, r5 */
/* @0x1e4488 bgt 0x1e4584 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2ec> */
/* @0x1e448c ldr r10, [sp, #0xc] */
/* @0x1e4490 mov r3, r8 */
/* @0x1e4494 ldr r2, [r4, #0x24] */
/* @0x1e4498 rsb r1, r10, r7 */
/* @0x1e449c ldr r12, [r4, #0x28] */
/* @0x1e44a0 ldr r9, [sp, #0x94] */
/* @0x1e44a4 add r1, r1, r2 */
/* @0x1e44a8 ldr r10, [sp, #0x10] */
/* @0x1e44ac rsb r0, r9, r7 */
/* @0x1e44b0 str r7, [sp] */
/* @0x1e44b4 add r2, r10, r12 */
/* @0x1e44b8 cmp r1, #0 */
/* @0x1e44bc blt 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44c0 ldr r12, [r4, #0x1c] */
/* @0x1e44c4 cmp r12, r1 */
/* @0x1e44c8 ble 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44cc cmp r2, #0 */
/* @0x1e44d0 blt 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44d4 ldr r9, [r4, #0x20] */
/* @0x1e44d8 cmp r2, r9 */
/* @0x1e44dc bge 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e44e0 ldrb r9, [r4, #0x31] */
/* @0x1e44e4 cmp r9, #0 */
/* @0x1e44e8 beq 0x1e450c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x274> */
/* @0x1e44ec ldr r9, [r4, #0x40] */
/* @0x1e44f0 ldr r7, [sp, #0x8] */
/* @0x1e44f4 add r9, r9, r7 */
/* @0x1e44f8 ldr r9, [r9, #0x4] */
/* @0x1e44fc mla r12, r12, r2, r9 */
/* @0x1e4500 ldrb r12, [r12, r1] */
/* @0x1e4504 cmp r12, #0 */
/* @0x1e4508 beq 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e450c ldr r12, [r6, #0x24] */
/* @0x1e4510 ldr r9, [r6, #0x28] */
/* @0x1e4514 adds r12, r0, r12 */
/* @0x1e4518 bmi 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e451c ldr r10, [r6, #0x1c] */
/* @0x1e4520 cmp r12, r10 */
/* @0x1e4524 bge 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e4528 ldr r7, [sp, #0x4] */
/* @0x1e452c rsb r11, r7, r3 */
/* @0x1e4530 adds r9, r9, r11 */
/* @0x1e4534 bmi 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e4538 ldr r11, [r6, #0x20] */
/* @0x1e453c cmp r9, r11 */
/* @0x1e4540 bge 0x1e4570 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2d8> */
/* @0x1e4544 ldrb r11, [r6, #0x31] */
/* @0x1e4548 cmp r11, #0 */
/* @0x1e454c beq 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4550 ldr r11, [r6, #0x40] */
/* @0x1e4554 ldr r7, [sp, #0x24] */
/* @0x1e4558 add r11, r11, r7 */
/* @0x1e455c ldr r11, [r11, #0x4] */
/* @0x1e4560 mla r9, r10, r9, r11 */
/* @0x1e4564 ldrb r12, [r9, r12] */
/* @0x1e4568 cmp r12, #0 */
/* @0x1e456c bne 0x1e4a14 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x77c> */
/* @0x1e4570 add r3, r3, #1 */
/* @0x1e4574 add r2, r2, #1 */
/* @0x1e4578 cmp r5, r3 */
/* @0x1e457c bge 0x1e44b8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x220> */
/* @0x1e4580 ldr r7, [sp] */
/* @0x1e4584 ldr r9, [sp, #0x18] */
/* @0x1e4588 add r7, r7, #1 */
/* @0x1e458c cmp r7, r9 */
/* @0x1e4590 ble 0x1e4484 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x1ec> */
/* @0x1e4594 mov r1, #0 */
/* @0x1e4598 str r1, [sp, #0x14] */
/* @0x1e459c ldr r7, [sp, #0x20] */
/* @0x1e45a0 ldrb r3, [r7] */
/* @0x1e45a4 cmp r3, #0 */
/* @0x1e45a8 beq 0x1e45bc <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x324> */
/* @0x1e45ac ldr r3, [pc, #0x478] */
/* @0x1e45b0 ldr r9, [sp, #0x1c] */
/* @0x1e45b4 ldr r0, [r9, r3] */
/* @0x1e45b8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1e45bc ldr r0, [sp, #0x14] */
/* @0x1e45c0 add sp, sp, #44 */
/* @0x1e45c4 vpop {d8, d9, d10, d11, d12} */
/* @0x1e45c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e45cc vldr s5, [sp, #132] */
/* @0x1e45d0 vcmp.f32 s5, #0 */
/* @0x1e45d4 vldr s8, [sp, #164] */
/* @0x1e45d8 vmrs APSR_nzcv, fpscr */
/* @0x1e45dc vcmp.f32 s8, #0 */
/* @0x1e45e0 movne r3, #0 */
/* @0x1e45e4 moveq r3, #1 */
/* @0x1e45e8 vmrs APSR_nzcv, fpscr */
/* @0x1e45ec movne r3, #0 */
/* @0x1e45f0 andeq r3, r3, #1 */
/* @0x1e45f4 cmp r3, #0 */
/* @0x1e45f8 str r3, [sp, #0x14] */
/* @0x1e45fc beq 0x1e47a8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x510> */
/* @0x1e4600 ldr r1, [sp, #0x18] */
/* @0x1e4604 cmp r1, r7 */
/* @0x1e4608 blt 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e460c ldr r2, [sp, #0x8c] */
/* @0x1e4610 lsl r12, r10, #3 */
/* @0x1e4614 str r11, [sp, #0x10] */
/* @0x1e4618 lsl r2, r2, #3 */
/* @0x1e461c str r2, [sp, #0x24] */
/* @0x1e4620 cmp r8, r5 */
/* @0x1e4624 bgt 0x1e477c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4e4> */
/* @0x1e4628 ldr r10, [sp, #0xc] */
/* @0x1e462c vldr s8, [r4, #36] */
/* @0x1e4630 vcvt.f32.s32 s15, s8 */
/* @0x1e4634 vldr s11, [r4, #40] */
/* @0x1e4638 rsb r3, r10, r7 */
/* @0x1e463c ldr r10, [sp, #0x94] */
/* @0x1e4640 vmov s5, r3 */
/* @0x1e4644 rsb r10, r10, r7 */
/* @0x1e4648 mov r3, r8 */
/* @0x1e464c vmov s12, r10 */
/* @0x1e4650 vcvt.f32.s32 s14, s5 */
/* @0x1e4654 vmla.f32 s15, s16, s14 */
/* @0x1e4658 vcvt.s32.f32 s15, s15 */
/* @0x1e465c vmov r2, s15 */
/* @0x1e4660 vcvt.f32.s32 s14, s11 */
/* @0x1e4664 cmp r2, #0 */
/* @0x1e4668 blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e466c ldr r1, [r4, #0x1c] */
/* @0x1e4670 cmp r1, r2 */
/* @0x1e4674 ble 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e4678 rsb r10, r9, r3 */
/* @0x1e467c vmov.f32 s5, s14 */
/* @0x1e4680 vmov s15, r10 */
/* @0x1e4684 vcvt.f32.s32 s15, s15 */
/* @0x1e4688 vmla.f32 s5, s15, s18 */
/* @0x1e468c vcvt.s32.f32 s15, s5 */
/* @0x1e4690 vmov r0, s15 */
/* @0x1e4694 cmp r0, #0 */
/* @0x1e4698 blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e469c ldr r10, [r4, #0x20] */
/* @0x1e46a0 cmp r0, r10 */
/* @0x1e46a4 bge 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e46a8 ldrb r10, [r4, #0x31] */
/* @0x1e46ac cmp r10, #0 */
/* @0x1e46b0 beq 0x1e46d0 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x438> */
/* @0x1e46b4 ldr r10, [r4, #0x40] */
/* @0x1e46b8 add r10, r10, r12 */
/* @0x1e46bc ldr r10, [r10, #0x4] */
/* @0x1e46c0 mla r1, r1, r0, r10 */
/* @0x1e46c4 ldrb r1, [r1, r2] */
/* @0x1e46c8 cmp r1, #0 */
/* @0x1e46cc beq 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e46d0 vcvt.f32.s32 s13, s12 */
/* @0x1e46d4 vldr s8, [r6, #36] */
/* @0x1e46d8 ldr r10, [r6, #0x28] */
/* @0x1e46dc vcvt.f32.s32 s15, s8 */
/* @0x1e46e0 vmla.f32 s15, s13, s20 */
/* @0x1e46e4 vcvt.s32.f32 s15, s15 */
/* @0x1e46e8 vmov r1, s15 */
/* @0x1e46ec cmp r1, #0 */
/* @0x1e46f0 blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e46f4 ldr r0, [r6, #0x1c] */
/* @0x1e46f8 cmp r1, r0 */
/* @0x1e46fc bge 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e4700 ldr r11, [sp, #0x10] */
/* @0x1e4704 vmov s5, r10 */
/* @0x1e4708 rsb r11, r11, r3 */
/* @0x1e470c vcvt.f32.s32 s13, s5 */
/* @0x1e4710 vmov s11, r11 */
/* @0x1e4714 vcvt.f32.s32 s11, s11 */
/* @0x1e4718 vmla.f32 s13, s11, s21 */
/* @0x1e471c vcvt.s32.f32 s13, s13 */
/* @0x1e4720 vmov r10, s13 */
/* @0x1e4724 vstr s13, [sp, #8] */
/* @0x1e4728 cmp r10, #0 */
/* @0x1e472c blt 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e4730 ldr r11, [r6, #0x20] */
/* @0x1e4734 cmp r10, r11 */
/* @0x1e4738 bge 0x1e4770 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4d8> */
/* @0x1e473c ldrb r11, [r6, #0x31] */
/* @0x1e4740 cmp r11, #0 */
/* @0x1e4744 beq 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4748 ldr r10, [sp, #0x24] */
/* @0x1e474c ldr r11, [r6, #0x40] */
/* @0x1e4750 add r11, r11, r10 */
/* @0x1e4754 vmov r10, s13 */
/* @0x1e4758 str r11, [sp, #0x4] */
/* @0x1e475c ldr r11, [r11, #0x4] */
/* @0x1e4760 mla r0, r0, r10, r11 */
/* @0x1e4764 ldrb r1, [r0, r1] */
/* @0x1e4768 cmp r1, #0 */
/* @0x1e476c bne 0x1e4a0c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x774> */
/* @0x1e4770 add r3, r3, #1 */
/* @0x1e4774 cmp r5, r3 */
/* @0x1e4778 bge 0x1e4664 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x3cc> */
/* @0x1e477c ldr r1, [sp, #0x18] */
/* @0x1e4780 add r7, r7, #1 */
/* @0x1e4784 cmp r7, r1 */
/* @0x1e4788 ble 0x1e4620 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x388> */
/* @0x1e478c b 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e4790 ldr r3, [pc, #0x294] */
/* @0x1e4794 mov r1, #6 */
/* @0x1e4798 mov r2, #3 */
/* @0x1e479c ldr r0, [r7, r3] */
/* @0x1e47a0 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1e47a4 b 0x1e42e4 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x4c> */
/* @0x1e47a8 vldr s13, [sp, #132] */
/* @0x1e47ac vldr s24, [pc, #616] */
/* @0x1e47b0 vnmul.f32 s15, s13, s24 */
/* @0x1e47b4 vldr s23, [pc, #612] */
/* @0x1e47b8 vdiv.f32 s15, s15, s23 */
/* @0x1e47bc vmov r0, s15 */
/* @0x1e47c0 bl 0xb6580 <sinf@plt> */
/* @0x1e47c4 vldr s14, [sp, #132] */
/* @0x1e47c8 vmul.f32 s15, s14, s24 */
/* @0x1e47cc vdiv.f32 s15, s15, s23 */
/* @0x1e47d0 vmov s17, r0 */
/* @0x1e47d4 vmov r0, s15 */
/* @0x1e47d8 bl 0xb658c <cosf@plt> */
/* @0x1e47dc vldr s5, [sp, #164] */
/* @0x1e47e0 vnmul.f32 s15, s5, s24 */
/* @0x1e47e4 vdiv.f32 s15, s15, s23 */
/* @0x1e47e8 vmov s19, r0 */
/* @0x1e47ec vmov r0, s15 */
/* @0x1e47f0 bl 0xb6580 <sinf@plt> */
/* @0x1e47f4 vldr s8, [sp, #164] */
/* @0x1e47f8 vmul.f32 s24, s8, s24 */
/* @0x1e47fc vdiv.f32 s24, s24, s23 */
/* @0x1e4800 vmov s22, r0 */
/* @0x1e4804 vmov r0, s24 */
/* @0x1e4808 bl 0xb658c <cosf@plt> */
/* @0x1e480c ldr r1, [sp, #0x18] */
/* @0x1e4810 cmp r1, r7 */
/* @0x1e4814 vmov s7, r0 */
/* @0x1e4818 blt 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e481c ldr r3, [sp, #0x8c] */
/* @0x1e4820 lsl r10, r10, #3 */
/* @0x1e4824 ldr r12, [sp, #0x94] */
/* @0x1e4828 lsl r0, r3, #3 */
/* @0x1e482c str r0, [sp, #0x10] */
/* @0x1e4830 cmp r8, r5 */
/* @0x1e4834 bgt 0x1e49e8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x750> */
/* @0x1e4838 ldr r2, [sp, #0xc] */
/* @0x1e483c vldr s8, [r4, #36] */
/* @0x1e4840 vldr s13, [r4, #40] */
/* @0x1e4844 vcvt.f32.s32 s12, s8 */
/* @0x1e4848 rsb r3, r2, r7 */
/* @0x1e484c rsb r0, r12, r7 */
/* @0x1e4850 str r1, [sp, #0x4] */
/* @0x1e4854 vmov s5, r3 */
/* @0x1e4858 mov r3, r8 */
/* @0x1e485c vmov s6, r0 */
/* @0x1e4860 vcvt.f32.s32 s9, s5 */
/* @0x1e4864 vmul.f32 s11, s19, s9 */
/* @0x1e4868 vmul.f32 s9, s17, s9 */
/* @0x1e486c vcvt.f32.s32 s10, s13 */
/* @0x1e4870 rsb r0, r9, r3 */
/* @0x1e4874 vmov s14, r0 */
/* @0x1e4878 vcvt.f32.s32 s14, s14 */
/* @0x1e487c vmov.f32 s15, s11 */
/* @0x1e4880 vmla.f32 s15, s14, s17 */
/* @0x1e4884 vmov.f32 s5, s12 */
/* @0x1e4888 vmla.f32 s5, s15, s16 */
/* @0x1e488c vcmpe.f32 s5, #0 */
/* @0x1e4890 vmov.f32 s15, s5 */
/* @0x1e4894 vmrs APSR_nzcv, fpscr */
/* @0x1e4898 bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e489c ldr r2, [r4, #0x1c] */
/* @0x1e48a0 vmov s8, r2 */
/* @0x1e48a4 vcvt.f32.s32 s13, s8 */
/* @0x1e48a8 vcmpe.f32 s5, s13 */
/* @0x1e48ac vmrs APSR_nzcv, fpscr */
/* @0x1e48b0 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e48b4 vmov.f32 s13, s9 */
/* @0x1e48b8 vnmls.f32 s13, s19, s14 */
/* @0x1e48bc vmov.f32 s5, s10 */
/* @0x1e48c0 vmla.f32 s5, s13, s18 */
/* @0x1e48c4 vcmpe.f32 s5, #0 */
/* @0x1e48c8 vmrs APSR_nzcv, fpscr */
/* @0x1e48cc bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e48d0 vldr s8, [r4, #32] */
/* @0x1e48d4 vcvt.f32.s32 s13, s8 */
/* @0x1e48d8 vcmpe.f32 s5, s13 */
/* @0x1e48dc vmrs APSR_nzcv, fpscr */
/* @0x1e48e0 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e48e4 ldrb r0, [r4, #0x31] */
/* @0x1e48e8 cmp r0, #0 */
/* @0x1e48ec beq 0x1e491c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x684> */
/* @0x1e48f0 vcvt.s32.f32 s14, s5 */
/* @0x1e48f4 ldr r0, [r4, #0x40] */
/* @0x1e48f8 add r0, r0, r10 */
/* @0x1e48fc ldr r0, [r0, #0x4] */
/* @0x1e4900 vmov r1, s14 */
/* @0x1e4904 vcvt.s32.f32 s15, s15 */
/* @0x1e4908 mla r2, r1, r2, r0 */
/* @0x1e490c vmov r0, s15 */
/* @0x1e4910 ldrb r2, [r2, r0] */
/* @0x1e4914 cmp r2, #0 */
/* @0x1e4918 beq 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e491c rsb r1, r11, r3 */
/* @0x1e4920 vcvt.f32.s32 s8, s6 */
/* @0x1e4924 vldr s5, [r6, #36] */
/* @0x1e4928 ldr r0, [r6, #0x28] */
/* @0x1e492c vmov s13, r1 */
/* @0x1e4930 vcvt.f32.s32 s13, s13 */
/* @0x1e4934 vmul.f32 s14, s13, s22 */
/* @0x1e4938 vmla.f32 s14, s8, s7 */
/* @0x1e493c vcvt.f32.s32 s15, s5 */
/* @0x1e4940 vmla.f32 s15, s14, s20 */
/* @0x1e4944 vcmpe.f32 s15, #0 */
/* @0x1e4948 vmrs APSR_nzcv, fpscr */
/* @0x1e494c bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e4950 ldr r2, [r6, #0x1c] */
/* @0x1e4954 vmov s5, r2 */
/* @0x1e4958 vcvt.f32.s32 s14, s5 */
/* @0x1e495c vcmpe.f32 s15, s14 */
/* @0x1e4960 vmrs APSR_nzcv, fpscr */
/* @0x1e4964 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e4968 vmul.f32 s8, s22, s8 */
/* @0x1e496c vnmls.f32 s8, s7, s13 */
/* @0x1e4970 vmov s13, r0 */
/* @0x1e4974 vcvt.f32.s32 s14, s13 */
/* @0x1e4978 vmla.f32 s14, s8, s21 */
/* @0x1e497c vcmpe.f32 s14, #0 */
/* @0x1e4980 vmrs APSR_nzcv, fpscr */
/* @0x1e4984 bmi 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e4988 vldr s5, [r6, #32] */
/* @0x1e498c vcvt.f32.s32 s13, s5 */
/* @0x1e4990 vcmpe.f32 s14, s13 */
/* @0x1e4994 vmrs APSR_nzcv, fpscr */
/* @0x1e4998 bge 0x1e49d8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x740> */
/* @0x1e499c ldrb r0, [r6, #0x31] */
/* @0x1e49a0 cmp r0, #0 */
/* @0x1e49a4 beq 0x1e4a00 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x768> */
/* @0x1e49a8 vcvt.s32.f32 s14, s14 */
/* @0x1e49ac ldr r1, [sp, #0x10] */
/* @0x1e49b0 ldr r0, [r6, #0x40] */
/* @0x1e49b4 add r0, r0, r1 */
/* @0x1e49b8 ldr r0, [r0, #0x4] */
/* @0x1e49bc vmov r1, s14 */
/* @0x1e49c0 vcvt.s32.f32 s15, s15 */
/* @0x1e49c4 mla r2, r1, r2, r0 */
/* @0x1e49c8 vmov r0, s15 */
/* @0x1e49cc ldrb r2, [r2, r0] */
/* @0x1e49d0 cmp r2, #0 */
/* @0x1e49d4 bne 0x1e49f8 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x760> */
/* @0x1e49d8 add r3, r3, #1 */
/* @0x1e49dc cmp r5, r3 */
/* @0x1e49e0 bge 0x1e4870 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x5d8> */
/* @0x1e49e4 ldr r1, [sp, #0x4] */
/* @0x1e49e8 add r7, r7, #1 */
/* @0x1e49ec cmp r7, r1 */
/* @0x1e49f0 ble 0x1e4830 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x598> */
/* @0x1e49f4 b 0x1e4594 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x2fc> */
/* @0x1e49f8 str r2, [sp, #0x14] */
/* @0x1e49fc b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a00 mov r2, #1 */
/* @0x1e4a04 str r2, [sp, #0x14] */
/* @0x1e4a08 b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a0c str r1, [sp, #0x14] */
/* @0x1e4a10 b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a14 str r12, [sp, #0x14] */
/* @0x1e4a18 b 0x1e459c <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x304> */
/* @0x1e4a1c ldrdmi r0, r1, [r9], #-251 */
/* @0x1e4a20 teqmi r4, #0 */
/* @0x1e4a24 mlaeq r0, r12, r9, sp */
/* @0x1e4a28 .word 0xffffbf18 */
/* @0x1e4a2c .word 0xffffbf1c */

/* ── FUNC 0x1e4a30 · CSprite::PreciseCollisionPoint(int, tagYYRECT*, int, int, float, float, float, int, int) · size=500 · insn=125 */
/* @0x1e4a30 push {r4, r5, r6, r7, r8, lr} */
/* @0x1e4a34 vpush {d8, d9} */
/* @0x1e4a38 mov r4, r0 */
/* @0x1e4a3c mov r6, r3 */
/* @0x1e4a40 mov r5, r1 */
/* @0x1e4a44 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e4a48 ldrb r2, [r4, #0x31] */
/* @0x1e4a4c cmp r2, #0 */
/* @0x1e4a50 moveq r0, #1 */
/* @0x1e4a54 beq 0x1e4b44 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x114> */
/* @0x1e4a58 ldr r3, [r4, #0x18] */
/* @0x1e4a5c cmp r3, #0 */
/* @0x1e4a60 ble 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c> */
/* @0x1e4a64 ldr r7, [r4, #0x3c] */
/* @0x1e4a68 mov r0, r5 */
/* @0x1e4a6c mov r1, r7 */
/* @0x1e4a70 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4a74 vldr s13, [sp, #52] */
/* @0x1e4a78 vabs.f32 s14, s13 */
/* @0x1e4a7c vldr s15, [pc, #404] */
/* @0x1e4a80 vcmpe.f32 s14, s15 */
/* @0x1e4a84 subs r8, r1, #0 */
/* @0x1e4a88 addlt r8, r8, r7 */
/* @0x1e4a8c vmrs APSR_nzcv, fpscr */
/* @0x1e4a90 bpl 0x1e4b58 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x128> */
/* @0x1e4a94 ldr r2, [sp, #0x38] */
/* @0x1e4a98 vldr s13, [sp, #44] */
/* @0x1e4a9c rsb r2, r6, r2 */
/* @0x1e4aa0 vmov s14, r2 */
/* @0x1e4aa4 vcvt.f32.s32 s14, s14 */
/* @0x1e4aa8 vdiv.f32 s14, s14, s13 */
/* @0x1e4aac vldr s13, [r4, #36] */
/* @0x1e4ab0 vcvt.f32.s32 s15, s13 */
/* @0x1e4ab4 vadd.f32 s15, s14, s15 */
/* @0x1e4ab8 vmov r0, s15 */
/* @0x1e4abc bl 0xb6910 <floorf@plt> */
/* @0x1e4ac0 ldr r3, [sp, #0x28] */
/* @0x1e4ac4 ldr r2, [sp, #0x3c] */
/* @0x1e4ac8 vldr s13, [sp, #48] */
/* @0x1e4acc rsb r2, r3, r2 */
/* @0x1e4ad0 vmov s14, r2 */
/* @0x1e4ad4 vcvt.f32.s32 s14, s14 */
/* @0x1e4ad8 vdiv.f32 s14, s14, s13 */
/* @0x1e4adc vldr s13, [r4, #40] */
/* @0x1e4ae0 vcvt.f32.s32 s15, s13 */
/* @0x1e4ae4 vmov s13, r0 */
/* @0x1e4ae8 vadd.f32 s15, s14, s15 */
/* @0x1e4aec vcvt.s32.f32 s13, s13 */
/* @0x1e4af0 vmov r0, s15 */
/* @0x1e4af4 vmov r5, s13 */
/* @0x1e4af8 bl 0xb6910 <floorf@plt> */
/* @0x1e4afc vmov s14, r0 */
/* @0x1e4b00 vcvt.s32.f32 s14, s14 */
/* @0x1e4b04 vmov r0, s14 */
/* @0x1e4b08 cmp r5, #0 */
/* @0x1e4b0c blt 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c> */
/* @0x1e4b10 ldr r3, [r4, #0x1c] */
/* @0x1e4b14 cmp r5, r3 */
/* @0x1e4b18 bge 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c> */
/* @0x1e4b1c cmp r0, #0 */
/* @0x1e4b20 blt 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c> */
/* @0x1e4b24 ldr r2, [r4, #0x20] */
/* @0x1e4b28 cmp r0, r2 */
/* @0x1e4b2c bge 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c> */
/* @0x1e4b30 ldr r2, [r4, #0x40] */
/* @0x1e4b34 add r8, r2, r8, lsl #3 */
/* @0x1e4b38 ldr r2, [r8, #0x4] */
/* @0x1e4b3c mla r0, r3, r0, r2 */
/* @0x1e4b40 ldrb r0, [r0, r5] */
/* @0x1e4b44 vpop {d8, d9} */
/* @0x1e4b48 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e4b4c vpop {d8, d9} */
/* @0x1e4b50 mov r0, #0 */
/* @0x1e4b54 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e4b58 vldr s13, [sp, #52] */
/* @0x1e4b5c vldr s17, [pc, #184] */
/* @0x1e4b60 vnmul.f32 s15, s13, s17 */
/* @0x1e4b64 vldr s16, [pc, #180] */
/* @0x1e4b68 vdiv.f32 s15, s15, s16 */
/* @0x1e4b6c vmov r0, s15 */
/* @0x1e4b70 bl 0xb6580 <sinf@plt> */
/* @0x1e4b74 vldr s14, [sp, #52] */
/* @0x1e4b78 vmul.f32 s17, s14, s17 */
/* @0x1e4b7c vdiv.f32 s17, s17, s16 */
/* @0x1e4b80 vmov s19, r0 */
/* @0x1e4b84 vmov r0, s17 */
/* @0x1e4b88 bl 0xb658c <cosf@plt> */
/* @0x1e4b8c ldr r3, [sp, #0x28] */
/* @0x1e4b90 ldr r2, [sp, #0x3c] */
/* @0x1e4b94 vldr s15, [sp, #44] */
/* @0x1e4b98 rsb r2, r3, r2 */
/* @0x1e4b9c vmov s16, r2 */
/* @0x1e4ba0 ldr r2, [sp, #0x38] */
/* @0x1e4ba4 vcvt.f32.s32 s16, s16 */
/* @0x1e4ba8 rsb r6, r6, r2 */
/* @0x1e4bac vmov s13, r6 */
/* @0x1e4bb0 vmul.f32 s14, s16, s19 */
/* @0x1e4bb4 vcvt.f32.s32 s18, s13 */
/* @0x1e4bb8 vldr s13, [r4, #36] */
/* @0x1e4bbc vmov s17, r0 */
/* @0x1e4bc0 vmla.f32 s14, s18, s17 */
/* @0x1e4bc4 vdiv.f32 s14, s14, s15 */
/* @0x1e4bc8 vcvt.f32.s32 s15, s13 */
/* @0x1e4bcc vadd.f32 s15, s14, s15 */
/* @0x1e4bd0 vmov r0, s15 */
/* @0x1e4bd4 bl 0xb6910 <floorf@plt> */
/* @0x1e4bd8 vmul.f32 s15, s19, s18 */
/* @0x1e4bdc vldr s14, [sp, #48] */
/* @0x1e4be0 vldr s13, [r4, #40] */
/* @0x1e4be4 vnmls.f32 s15, s17, s16 */
/* @0x1e4be8 vdiv.f32 s15, s15, s14 */
/* @0x1e4bec vcvt.f32.s32 s14, s13 */
/* @0x1e4bf0 vmov s13, r0 */
/* @0x1e4bf4 vadd.f32 s14, s15, s14 */
/* @0x1e4bf8 vcvt.s32.f32 s13, s13 */
/* @0x1e4bfc vmov r0, s14 */
/* @0x1e4c00 vmov r5, s13 */
/* @0x1e4c04 bl 0xb6910 <floorf@plt> */
/* @0x1e4c08 vmov s14, r0 */
/* @0x1e4c0c vcvt.s32.f32 s14, s14 */
/* @0x1e4c10 vmov r0, s14 */
/* @0x1e4c14 b 0x1e4b08 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0xd8> */
/* @0x1e4c18 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x1e4c1c ldrdmi r0, r1, [r9], #-251 */
/* @0x1e4c20 teqmi r4, #0 */

/* ── FUNC 0x1e4c24 · CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*) · size=744 · insn=186 */
/* @0x1e4c24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e4c28 vpush {d8, d9, d10, d11, d12} */
/* @0x1e4c2c sub sp, sp, #12 */
/* @0x1e4c30 vldr s23, [sp, #92] */
/* @0x1e4c34 mov r4, r0 */
/* @0x1e4c38 mov r8, r2 */
/* @0x1e4c3c str r3, [sp] */
/* @0x1e4c40 mov r7, r1 */
/* @0x1e4c44 ldr r6, [sp, #0x58] */
/* @0x1e4c48 vldr s24, [sp, #96] */
/* @0x1e4c4c vldr s16, [sp, #100] */
/* @0x1e4c50 ldr r5, [sp, #0x68] */
/* @0x1e4c54 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e4c58 ldrb r3, [r4, #0x31] */
/* @0x1e4c5c cmp r3, #0 */
/* @0x1e4c60 moveq r0, #1 */
/* @0x1e4c64 beq 0x1e4e3c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x218> */
/* @0x1e4c68 ldr r3, [r4, #0x18] */
/* @0x1e4c6c cmp r3, #0 */
/* @0x1e4c70 ble 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214> */
/* @0x1e4c74 ldr r11, [r4, #0x3c] */
/* @0x1e4c78 mov r0, r7 */
/* @0x1e4c7c mov r1, r11 */
/* @0x1e4c80 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4c84 vmov.f32 s15, #1.000000e+00 */
/* @0x1e4c88 ldr r3, [r8] */
/* @0x1e4c8c ldr r7, [r5] */
/* @0x1e4c90 ldr r2, [r8, #0x4] */
/* @0x1e4c94 vcmp.f32 s23, s15 */
/* @0x1e4c98 subs r9, r1, #0 */
/* @0x1e4c9c ldr r1, [r8, #0x8] */
/* @0x1e4ca0 addlt r9, r9, r11 */
/* @0x1e4ca4 ldr r11, [r5, #0x8] */
/* @0x1e4ca8 cmp r7, r3 */
/* @0x1e4cac movlt r7, r3 */
/* @0x1e4cb0 ldr r3, [r8, #0xc] */
/* @0x1e4cb4 ldr r8, [r5, #0x4] */
/* @0x1e4cb8 cmp r11, r1 */
/* @0x1e4cbc movge r11, r1 */
/* @0x1e4cc0 ldr r5, [r5, #0xc] */
/* @0x1e4cc4 cmp r8, r2 */
/* @0x1e4cc8 movlt r8, r2 */
/* @0x1e4ccc str r11, [sp, #0x4] */
/* @0x1e4cd0 cmp r5, r3 */
/* @0x1e4cd4 movge r5, r3 */
/* @0x1e4cd8 vmrs APSR_nzcv, fpscr */
/* @0x1e4cdc vcmp.f32 s24, s15 */
/* @0x1e4ce0 movne r3, #0 */
/* @0x1e4ce4 moveq r3, #1 */
/* @0x1e4ce8 vmrs APSR_nzcv, fpscr */
/* @0x1e4cec movne r3, #0 */
/* @0x1e4cf0 andeq r3, r3, #1 */
/* @0x1e4cf4 cmp r3, #0 */
/* @0x1e4cf8 beq 0x1e4d10 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0xec> */
/* @0x1e4cfc vabs.f32 s14, s16 */
/* @0x1e4d00 vldr s15, [pc, #504] */
/* @0x1e4d04 vcmpe.f32 s14, s15 */
/* @0x1e4d08 vmrs APSR_nzcv, fpscr */
/* @0x1e4d0c bmi 0x1e4e48 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x224> */
/* @0x1e4d10 vldr s19, [pc, #492] */
/* @0x1e4d14 vnmul.f32 s15, s16, s19 */
/* @0x1e4d18 vldr s18, [pc, #488] */
/* @0x1e4d1c vdiv.f32 s15, s15, s18 */
/* @0x1e4d20 vmul.f32 s16, s16, s19 */
/* @0x1e4d24 vmov r0, s15 */
/* @0x1e4d28 bl 0xb6580 <sinf@plt> */
/* @0x1e4d2c vdiv.f32 s16, s16, s18 */
/* @0x1e4d30 vmov s17, r0 */
/* @0x1e4d34 vmov r0, s16 */
/* @0x1e4d38 bl 0xb658c <cosf@plt> */
/* @0x1e4d3c ldr r3, [sp, #0x4] */
/* @0x1e4d40 cmp r3, r7 */
/* @0x1e4d44 vmov s18, r0 */
/* @0x1e4d48 blt 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214> */
/* @0x1e4d4c lsl r9, r9, #3 */
/* @0x1e4d50 cmp r5, r8 */
/* @0x1e4d54 blt 0x1e4e28 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x204> */
/* @0x1e4d58 ldr r3, [sp] */
/* @0x1e4d5c vldr s15, [r4, #36] */
/* @0x1e4d60 vcvt.f32.s32 s22, s15 */
/* @0x1e4d64 mov r11, r8 */
/* @0x1e4d68 rsb r2, r3, r7 */
/* @0x1e4d6c vmov s14, r2 */
/* @0x1e4d70 vcvt.f32.s32 s20, s14 */
/* @0x1e4d74 vldr s14, [r4, #40] */
/* @0x1e4d78 vmul.f32 s21, s18, s20 */
/* @0x1e4d7c vmul.f32 s20, s17, s20 */
/* @0x1e4d80 vcvt.f32.s32 s19, s14 */
/* @0x1e4d84 rsb r2, r6, r11 */
/* @0x1e4d88 add r11, r11, #1 */
/* @0x1e4d8c vmov s16, r2 */
/* @0x1e4d90 vcvt.f32.s32 s16, s16 */
/* @0x1e4d94 vmov.f32 s15, s21 */
/* @0x1e4d98 vmla.f32 s15, s16, s17 */
/* @0x1e4d9c vdiv.f32 s15, s15, s23 */
/* @0x1e4da0 vadd.f32 s15, s15, s22 */
/* @0x1e4da4 vmov r0, s15 */
/* @0x1e4da8 bl 0xb6910 <floorf@plt> */
/* @0x1e4dac vmov.f32 s15, s20 */
/* @0x1e4db0 vnmls.f32 s15, s18, s16 */
/* @0x1e4db4 vdiv.f32 s15, s15, s24 */
/* @0x1e4db8 vmov s14, r0 */
/* @0x1e4dbc vadd.f32 s15, s15, s19 */
/* @0x1e4dc0 vcvt.s32.f32 s14, s14 */
/* @0x1e4dc4 vmov r0, s15 */
/* @0x1e4dc8 vmov r10, s14 */
/* @0x1e4dcc bl 0xb6910 <floorf@plt> */
/* @0x1e4dd0 cmp r10, #0 */
/* @0x1e4dd4 vmov s15, r0 */
/* @0x1e4dd8 blt 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc> */
/* @0x1e4ddc ldr r2, [r4, #0x1c] */
/* @0x1e4de0 cmp r10, r2 */
/* @0x1e4de4 bge 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc> */
/* @0x1e4de8 vcvt.s32.f32 s15, s15 */
/* @0x1e4dec vmov r1, s15 */
/* @0x1e4df0 cmp r1, #0 */
/* @0x1e4df4 blt 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc> */
/* @0x1e4df8 ldr r0, [r4, #0x20] */
/* @0x1e4dfc cmp r1, r0 */
/* @0x1e4e00 bge 0x1e4e20 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x1fc> */
/* @0x1e4e04 ldr r0, [r4, #0x40] */
/* @0x1e4e08 add r0, r0, r9 */
/* @0x1e4e0c ldr r0, [r0, #0x4] */
/* @0x1e4e10 mla r2, r2, r1, r0 */
/* @0x1e4e14 ldrb r0, [r2, r10] */
/* @0x1e4e18 cmp r0, #0 */
/* @0x1e4e1c bne 0x1e4e3c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x218> */
/* @0x1e4e20 cmp r5, r11 */
/* @0x1e4e24 bge 0x1e4d84 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x160> */
/* @0x1e4e28 ldr r2, [sp, #0x4] */
/* @0x1e4e2c add r7, r7, #1 */
/* @0x1e4e30 cmp r7, r2 */
/* @0x1e4e34 ble 0x1e4d50 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x12c> */
/* @0x1e4e38 mov r0, #0 */
/* @0x1e4e3c add sp, sp, #12 */
/* @0x1e4e40 vpop {d8, d9, d10, d11, d12} */
/* @0x1e4e44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e4e48 cmp r11, r7 */
/* @0x1e4e4c blt 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214> */
/* @0x1e4e50 lsl r9, r9, #3 */
/* @0x1e4e54 rsb r6, r6, r8 */
/* @0x1e4e58 cmp r5, r8 */
/* @0x1e4e5c blt 0x1e4e98 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x274> */
/* @0x1e4e60 ldr r2, [sp] */
/* @0x1e4e64 ldr r3, [r4, #0x24] */
/* @0x1e4e68 rsb r1, r2, r7 */
/* @0x1e4e6c ldr r2, [r4, #0x28] */
/* @0x1e4e70 adds r1, r1, r3 */
/* @0x1e4e74 bmi 0x1e4e98 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x274> */
/* @0x1e4e78 ldr r12, [r4, #0x1c] */
/* @0x1e4e7c add r2, r6, r2 */
/* @0x1e4e80 mov r3, r8 */
/* @0x1e4e84 cmp r12, r1 */
/* @0x1e4e88 bgt 0x1e4eac <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x288> */
/* @0x1e4e8c add r3, r3, #1 */
/* @0x1e4e90 cmp r5, r3 */
/* @0x1e4e94 bge 0x1e4e8c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x268> */
/* @0x1e4e98 ldr r2, [sp, #0x4] */
/* @0x1e4e9c add r7, r7, #1 */
/* @0x1e4ea0 cmp r7, r2 */
/* @0x1e4ea4 ble 0x1e4e58 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x234> */
/* @0x1e4ea8 b 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214> */
/* @0x1e4eac cmp r2, #0 */
/* @0x1e4eb0 add r3, r3, #1 */
/* @0x1e4eb4 blt 0x1e4ee0 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x2bc> */
/* @0x1e4eb8 ldr r0, [r4, #0x20] */
/* @0x1e4ebc cmp r2, r0 */
/* @0x1e4ec0 bge 0x1e4ee0 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x2bc> */
/* @0x1e4ec4 ldr r0, [r4, #0x40] */
/* @0x1e4ec8 add r0, r0, r9 */
/* @0x1e4ecc ldr r0, [r0, #0x4] */
/* @0x1e4ed0 mla r0, r12, r2, r0 */
/* @0x1e4ed4 ldrb r0, [r0, r1] */
/* @0x1e4ed8 cmp r0, #0 */
/* @0x1e4edc bne 0x1e4e3c <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x218> */
/* @0x1e4ee0 cmp r5, r3 */
/* @0x1e4ee4 add r2, r2, #1 */
/* @0x1e4ee8 bge 0x1e4eac <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x288> */
/* @0x1e4eec ldr r2, [sp, #0x4] */
/* @0x1e4ef0 add r7, r7, #1 */
/* @0x1e4ef4 cmp r7, r2 */
/* @0x1e4ef8 ble 0x1e4e58 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x234> */
/* @0x1e4efc b 0x1e4e38 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_+0x214> */
/* @0x1e4f00 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x1e4f04 ldrdmi r0, r1, [r9], #-251 */
/* @0x1e4f08 teqmi r4, #0 */

/* ── FUNC 0x1e4f0c · CSprite::PreciseCollisionEllipse(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*) · size=944 · insn=236 */
/* @0x1e4f0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e4f10 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1e4f14 sub sp, sp, #12 */
/* @0x1e4f18 vldr s23, [sp, #108] */
/* @0x1e4f1c mov r4, r0 */
/* @0x1e4f20 mov r8, r3 */
/* @0x1e4f24 mov r10, r2 */
/* @0x1e4f28 mov r6, r1 */
/* @0x1e4f2c ldr r5, [sp, #0x68] */
/* @0x1e4f30 vldr s24, [sp, #112] */
/* @0x1e4f34 ldr r9, [sp, #0x78] */
/* @0x1e4f38 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e4f3c ldrb r3, [r4, #0x31] */
/* @0x1e4f40 cmp r3, #0 */
/* @0x1e4f44 moveq r0, #1 */
/* @0x1e4f48 beq 0x1e5190 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x284> */
/* @0x1e4f4c ldr r3, [r4, #0x18] */
/* @0x1e4f50 cmp r3, #0 */
/* @0x1e4f54 ble 0x1e5288 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x37c> */
/* @0x1e4f58 ldr r7, [r4, #0x3c] */
/* @0x1e4f5c mov r0, r6 */
/* @0x1e4f60 mov r1, r7 */
/* @0x1e4f64 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e4f68 vmov.f32 s13, #1.000000e+00 */
/* @0x1e4f6c ldr r0, [r9] */
/* @0x1e4f70 ldr r12, [r9, #0x8] */
/* @0x1e4f74 ldr r3, [r10, #0x8] */
/* @0x1e4f78 ldr r2, [r9, #0xc] */
/* @0x1e4f7c ldr r6, [r10] */
/* @0x1e4f80 vcmp.f32 s23, s13 */
/* @0x1e4f84 subs r11, r1, #0 */
/* @0x1e4f88 ldr r1, [r10, #0xc] */
/* @0x1e4f8c addlt r11, r11, r7 */
/* @0x1e4f90 cmp r3, r12 */
/* @0x1e4f94 movge r3, r12 */
/* @0x1e4f98 ldr r7, [r10, #0x4] */
/* @0x1e4f9c add r10, r0, r12 */
/* @0x1e4fa0 str r3, [sp] */
/* @0x1e4fa4 cmp r6, r0 */
/* @0x1e4fa8 movlt r6, r0 */
/* @0x1e4fac ldr r3, [r9, #0x4] */
/* @0x1e4fb0 rsb r0, r0, r12 */
/* @0x1e4fb4 cmp r2, r1 */
/* @0x1e4fb8 movlt r9, r2 */
/* @0x1e4fbc movge r9, r1 */
/* @0x1e4fc0 add r10, r10, r10, lsr #31 */
/* @0x1e4fc4 add r1, r3, r2 */
/* @0x1e4fc8 cmp r7, r3 */
/* @0x1e4fcc movlt r7, r3 */
/* @0x1e4fd0 rsb r3, r3, r2 */
/* @0x1e4fd4 vmrs APSR_nzcv, fpscr */
/* @0x1e4fd8 add r0, r0, r0, lsr #31 */
/* @0x1e4fdc asr r10, r10, #1 */
/* @0x1e4fe0 add r1, r1, r1, lsr #31 */
/* @0x1e4fe4 add r3, r3, r3, lsr #31 */
/* @0x1e4fe8 vcmp.f32 s24, s13 */
/* @0x1e4fec asr r0, r0, #1 */
/* @0x1e4ff0 vmov s12, r10 */
/* @0x1e4ff4 asr r1, r1, #1 */
/* @0x1e4ff8 asr r3, r3, #1 */
/* @0x1e4ffc movne r2, #0 */
/* @0x1e5000 moveq r2, #1 */
/* @0x1e5004 vmov s14, r0 */
/* @0x1e5008 vmrs APSR_nzcv, fpscr */
/* @0x1e500c vcvt.f32.s32 s25, s12 */
/* @0x1e5010 movne r2, #0 */
/* @0x1e5014 andeq r2, r2, #1 */
/* @0x1e5018 vmov s15, r1 */
/* @0x1e501c vmov s12, r3 */
/* @0x1e5020 cmp r2, #0 */
/* @0x1e5024 vcvt.f32.s32 s26, s14 */
/* @0x1e5028 vcvt.f32.s32 s16, s15 */
/* @0x1e502c vcvt.f32.s32 s17, s12 */
/* @0x1e5030 bne 0x1e519c <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x290> */
/* @0x1e5034 vldr s13, [sp, #116] */
/* @0x1e5038 vldr s19, [pc, #624] */
/* @0x1e503c vldr s18, [pc, #624] */
/* @0x1e5040 vnmul.f32 s15, s13, s19 */
/* @0x1e5044 vdiv.f32 s15, s15, s18 */
/* @0x1e5048 vmov r0, s15 */
/* @0x1e504c bl 0xb6580 <sinf@plt> */
/* @0x1e5050 vldr s14, [sp, #116] */
/* @0x1e5054 vmul.f32 s19, s14, s19 */
/* @0x1e5058 vdiv.f32 s19, s19, s18 */
/* @0x1e505c vmov s20, r0 */
/* @0x1e5060 vmov r0, s19 */
/* @0x1e5064 bl 0xb658c <cosf@plt> */
/* @0x1e5068 ldr r3, [sp] */
/* @0x1e506c cmp r3, r6 */
/* @0x1e5070 vmov s21, r0 */
/* @0x1e5074 blt 0x1e5288 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x37c> */
/* @0x1e5078 vmov.f32 s19, #1.000000e+00 */
/* @0x1e507c lsl r11, r11, #3 */
/* @0x1e5080 str r11, [sp, #0x4] */
/* @0x1e5084 cmp r9, r7 */
/* @0x1e5088 blt 0x1e5298 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x38c> */
/* @0x1e508c vmov s12, r6 */
/* @0x1e5090 rsb r3, r8, r6 */
/* @0x1e5094 mov r10, r7 */
/* @0x1e5098 vmov s22, r3 */
/* @0x1e509c vcvt.f32.s32 s18, s12 */
/* @0x1e50a0 vsub.f32 s18, s18, s25 */
/* @0x1e50a4 vdiv.f32 s18, s18, s26 */
/* @0x1e50a8 vmul.f32 s18, s18, s18 */
/* @0x1e50ac b 0x1e50bc <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1b0> */
/* @0x1e50b0 add r10, r10, #1 */
/* @0x1e50b4 cmp r9, r10 */
/* @0x1e50b8 blt 0x1e5298 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x38c> */
/* @0x1e50bc vmov s12, r10 */
/* @0x1e50c0 vmov.f32 s13, s18 */
/* @0x1e50c4 vcvt.f32.s32 s15, s12 */
/* @0x1e50c8 vsub.f32 s15, s15, s16 */
/* @0x1e50cc vdiv.f32 s15, s15, s17 */
/* @0x1e50d0 vmla.f32 s13, s15, s15 */
/* @0x1e50d4 vcmpe.f32 s13, s19 */
/* @0x1e50d8 vmrs APSR_nzcv, fpscr */
/* @0x1e50dc bgt 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4> */
/* @0x1e50e0 rsb r3, r5, r10 */
/* @0x1e50e4 vcvt.f32.s32 s28, s22 */
/* @0x1e50e8 vldr s12, [r4, #36] */
/* @0x1e50ec vmov s27, r3 */
/* @0x1e50f0 vcvt.f32.s32 s27, s27 */
/* @0x1e50f4 vmul.f32 s14, s27, s20 */
/* @0x1e50f8 vmla.f32 s14, s28, s21 */
/* @0x1e50fc vdiv.f32 s14, s14, s23 */
/* @0x1e5100 vcvt.f32.s32 s15, s12 */
/* @0x1e5104 vadd.f32 s15, s14, s15 */
/* @0x1e5108 vmov r0, s15 */
/* @0x1e510c bl 0xb6910 <floorf@plt> */
/* @0x1e5110 vmul.f32 s15, s20, s28 */
/* @0x1e5114 vldr s13, [r4, #40] */
/* @0x1e5118 vnmls.f32 s15, s21, s27 */
/* @0x1e511c vmov s12, r0 */
/* @0x1e5120 vdiv.f32 s15, s15, s24 */
/* @0x1e5124 vcvt.f32.s32 s14, s13 */
/* @0x1e5128 vadd.f32 s14, s15, s14 */
/* @0x1e512c vcvt.s32.f32 s12, s12 */
/* @0x1e5130 vmov r0, s14 */
/* @0x1e5134 vmov r11, s12 */
/* @0x1e5138 bl 0xb6910 <floorf@plt> */
/* @0x1e513c cmp r11, #0 */
/* @0x1e5140 vmov s15, r0 */
/* @0x1e5144 blt 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4> */
/* @0x1e5148 ldr r2, [r4, #0x1c] */
/* @0x1e514c cmp r11, r2 */
/* @0x1e5150 bge 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4> */
/* @0x1e5154 vcvt.s32.f32 s15, s15 */
/* @0x1e5158 vmov r1, s15 */
/* @0x1e515c cmp r1, #0 */
/* @0x1e5160 blt 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4> */
/* @0x1e5164 ldr r0, [r4, #0x20] */
/* @0x1e5168 cmp r1, r0 */
/* @0x1e516c bge 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4> */
/* @0x1e5170 ldr r0, [r4, #0x40] */
/* @0x1e5174 ldr r3, [sp, #0x4] */
/* @0x1e5178 add r0, r0, r3 */
/* @0x1e517c ldr r0, [r0, #0x4] */
/* @0x1e5180 mla r2, r2, r1, r0 */
/* @0x1e5184 ldrb r0, [r2, r11] */
/* @0x1e5188 cmp r0, #0 */
/* @0x1e518c beq 0x1e50b0 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x1a4> */
/* @0x1e5190 add sp, sp, #12 */
/* @0x1e5194 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1e5198 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e519c vldr s12, [sp, #116] */
/* @0x1e51a0 vabs.f32 s14, s12 */
/* @0x1e51a4 vldr s15, [pc, #268] */
/* @0x1e51a8 vcmpe.f32 s14, s15 */
/* @0x1e51ac vmrs APSR_nzcv, fpscr */
/* @0x1e51b0 bpl 0x1e5034 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x128> */
/* @0x1e51b4 ldr r3, [sp] */
/* @0x1e51b8 cmp r3, r6 */
/* @0x1e51bc blt 0x1e5288 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x37c> */
/* @0x1e51c0 lsl r11, r11, #3 */
/* @0x1e51c4 cmp r9, r7 */
/* @0x1e51c8 blt 0x1e5278 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x36c> */
/* @0x1e51cc vmov s12, r6 */
/* @0x1e51d0 mov r3, r7 */
/* @0x1e51d4 rsb r2, r8, r6 */
/* @0x1e51d8 vcvt.f32.s32 s14, s12 */
/* @0x1e51dc vsub.f32 s14, s14, s25 */
/* @0x1e51e0 vdiv.f32 s14, s14, s26 */
/* @0x1e51e4 vmul.f32 s14, s14, s14 */
/* @0x1e51e8 b 0x1e51f8 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2ec> */
/* @0x1e51ec add r3, r3, #1 */
/* @0x1e51f0 cmp r9, r3 */
/* @0x1e51f4 blt 0x1e5278 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x36c> */
/* @0x1e51f8 vmov s12, r3 */
/* @0x1e51fc vcvt.f32.s32 s15, s12 */
/* @0x1e5200 vsub.f32 s15, s15, s16 */
/* @0x1e5204 vdiv.f32 s15, s15, s17 */
/* @0x1e5208 vmov.f32 s12, s14 */
/* @0x1e520c vmla.f32 s12, s15, s15 */
/* @0x1e5210 vcmpe.f32 s12, s13 */
/* @0x1e5214 vmrs APSR_nzcv, fpscr */
/* @0x1e5218 bgt 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0> */
/* @0x1e521c ldr r1, [r4, #0x24] */
/* @0x1e5220 ldr r0, [r4, #0x28] */
/* @0x1e5224 adds r1, r2, r1 */
/* @0x1e5228 bmi 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0> */
/* @0x1e522c ldr r12, [r4, #0x1c] */
/* @0x1e5230 rsb r10, r5, r3 */
/* @0x1e5234 cmp r1, r12 */
/* @0x1e5238 bge 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0> */
/* @0x1e523c adds r0, r0, r10 */
/* @0x1e5240 bmi 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0> */
/* @0x1e5244 ldr r10, [r4, #0x20] */
/* @0x1e5248 cmp r0, r10 */
/* @0x1e524c bge 0x1e51ec <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2e0> */
/* @0x1e5250 ldr r10, [r4, #0x40] */
/* @0x1e5254 add r10, r10, r11 */
/* @0x1e5258 ldr r10, [r10, #0x4] */
/* @0x1e525c mla r0, r12, r0, r10 */
/* @0x1e5260 ldrb r0, [r0, r1] */
/* @0x1e5264 cmp r0, #0 */
/* @0x1e5268 bne 0x1e5190 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x284> */
/* @0x1e526c add r3, r3, #1 */
/* @0x1e5270 cmp r9, r3 */
/* @0x1e5274 bge 0x1e51f8 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2ec> */
/* @0x1e5278 ldr r3, [sp] */
/* @0x1e527c add r6, r6, #1 */
/* @0x1e5280 cmp r6, r3 */
/* @0x1e5284 ble 0x1e51c4 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x2b8> */
/* @0x1e5288 mov r0, #0 */
/* @0x1e528c add sp, sp, #12 */
/* @0x1e5290 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1e5294 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e5298 ldr r3, [sp] */
/* @0x1e529c add r6, r6, #1 */
/* @0x1e52a0 cmp r6, r3 */
/* @0x1e52a4 ble 0x1e5084 <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x178> */
/* @0x1e52a8 mov r0, #0 */
/* @0x1e52ac b 0x1e528c <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_+0x380> */
/* @0x1e52b0 ldrdmi r0, r1, [r9], #-251 */
/* @0x1e52b4 teqmi r4, #0 */
/* @0x1e52b8 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */

/* ── FUNC 0x1e52bc · CSprite::PreciseCollisionLine(int, tagYYRECT*, int, int, float, float, float, int, int, int, int) · size=1084 · insn=271 */
/* @0x1e52bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e52c0 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x1e52c4 sub sp, sp, #52 */
/* @0x1e52c8 vldr s20, [sp, #140] */
/* @0x1e52cc mov r4, r0 */
/* @0x1e52d0 mov r7, r3 */
/* @0x1e52d4 mov r10, r1 */
/* @0x1e52d8 mov r11, r2 */
/* @0x1e52dc ldr r8, [sp, #0x88] */
/* @0x1e52e0 vldr s21, [sp, #144] */
/* @0x1e52e4 ldr r6, [sp, #0x98] */
/* @0x1e52e8 ldr r5, [sp, #0x9c] */
/* @0x1e52ec bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi> */
/* @0x1e52f0 ldrb r3, [r4, #0x31] */
/* @0x1e52f4 cmp r3, #0 */
/* @0x1e52f8 moveq r10, #1 */
/* @0x1e52fc beq 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4> */
/* @0x1e5300 ldr r3, [r4, #0x18] */
/* @0x1e5304 cmp r3, #0 */
/* @0x1e5308 ble 0x1e56d4 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x418> */
/* @0x1e530c ldr r9, [r4, #0x3c] */
/* @0x1e5310 mov r0, r10 */
/* @0x1e5314 mov r1, r9 */
/* @0x1e5318 bl 0x318dec <__aeabi_idivmod> */
/* @0x1e531c ldr r2, [sp, #0xa0] */
/* @0x1e5320 ldr r3, [sp, #0xa4] */
/* @0x1e5324 cmp r1, #0 */
/* @0x1e5328 addlt r1, r1, r9 */
/* @0x1e532c cmp r5, r3 */
/* @0x1e5330 cmpne r6, r2 */
/* @0x1e5334 movne r10, #0 */
/* @0x1e5338 moveq r10, #1 */
/* @0x1e533c bne 0x1e53a0 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xe4> */
/* @0x1e5340 cmp r5, r3 */
/* @0x1e5344 str r6, [sp, #0x20] */
/* @0x1e5348 bge 0x1e56c0 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x404> */
/* @0x1e534c str r5, [sp, #0x24] */
/* @0x1e5350 ldr r2, [sp, #0xa0] */
/* @0x1e5354 ldr r5, [sp, #0xa4] */
/* @0x1e5358 str r2, [sp, #0x28] */
/* @0x1e535c vldr s14, [sp, #148] */
/* @0x1e5360 add r12, sp, #32 */
/* @0x1e5364 str r8, [sp] */
/* @0x1e5368 vstr s20, [sp, #4] */
/* @0x1e536c vstr s21, [sp, #8] */
/* @0x1e5370 vstr s14, [sp, #12] */
/* @0x1e5374 mov r0, r4 */
/* @0x1e5378 mov r2, r11 */
/* @0x1e537c mov r3, r7 */
/* @0x1e5380 str r12, [sp, #0x10] */
/* @0x1e5384 str r5, [sp, #0x2c] */
/* @0x1e5388 bl 0x1e4c24 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_> */
/* @0x1e538c mov r10, r0 */
/* @0x1e5390 mov r0, r10 */
/* @0x1e5394 add sp, sp, #52 */
/* @0x1e5398 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1e539c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e53a0 vldr s14, [sp, #148] */
/* @0x1e53a4 vldr s18, [pc, #836] */
/* @0x1e53a8 vnmul.f32 s15, s14, s18 */
/* @0x1e53ac vldr s17, [pc, #832] */
/* @0x1e53b0 str r1, [sp, #0x1c] */
/* @0x1e53b4 vdiv.f32 s15, s15, s17 */
/* @0x1e53b8 vmov r0, s15 */
/* @0x1e53bc bl 0xb6580 <sinf@plt> */
/* @0x1e53c0 vldr s15, [sp, #148] */
/* @0x1e53c4 vmul.f32 s18, s15, s18 */
/* @0x1e53c8 vdiv.f32 s18, s18, s17 */
/* @0x1e53cc vmov s16, r0 */
/* @0x1e53d0 vmov r0, s18 */
/* @0x1e53d4 bl 0xb658c <cosf@plt> */
/* @0x1e53d8 ldr r2, [sp, #0xa0] */
/* @0x1e53dc ldr r3, [sp, #0xa4] */
/* @0x1e53e0 ldr r1, [sp, #0x1c] */
/* @0x1e53e4 vmov s17, r0 */
/* @0x1e53e8 rsb r0, r6, r2 */
/* @0x1e53ec rsb r2, r5, r3 */
/* @0x1e53f0 eor r12, r0, r0, asr #31 */
/* @0x1e53f4 sub r12, r12, r0, asr #31 */
/* @0x1e53f8 eor r3, r2, r2, asr #31 */
/* @0x1e53fc sub r3, r3, r2, asr #31 */
/* @0x1e5400 cmp r12, r3 */
/* @0x1e5404 blt 0x1e5564 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x2a8> */
/* @0x1e5408 ldr r12, [sp, #0xa0] */
/* @0x1e540c cmp r6, r12 */
/* @0x1e5410 ble 0x1e5434 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x178> */
/* @0x1e5414 ldr r12, [sp, #0xa4] */
/* @0x1e5418 mov r3, r6 */
/* @0x1e541c rsb r2, r12, r5 */
/* @0x1e5420 ldr r12, [sp, #0xa0] */
/* @0x1e5424 ldr r5, [sp, #0xa4] */
/* @0x1e5428 rsb r0, r12, r6 */
/* @0x1e542c str r3, [sp, #0xa0] */
/* @0x1e5430 mov r6, r12 */
/* @0x1e5434 vmov s14, r2 */
/* @0x1e5438 ldr r3, [r11] */
/* @0x1e543c ldr r9, [r11, #0x8] */
/* @0x1e5440 vcvt.f32.s32 s22, s14 */
/* @0x1e5444 cmp r6, r3 */
/* @0x1e5448 movge r11, r6 */
/* @0x1e544c movlt r11, r3 */
/* @0x1e5450 vmov s14, r0 */
/* @0x1e5454 ldr r3, [sp, #0xa0] */
/* @0x1e5458 cmp r9, r3 */
/* @0x1e545c movge r9, r3 */
/* @0x1e5460 cmp r9, r11 */
/* @0x1e5464 vcvt.f32.s32 s15, s14 */
/* @0x1e5468 vdiv.f32 s22, s22, s15 */
/* @0x1e546c blt 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4> */
/* @0x1e5470 vldr s15, [r4, #36] */
/* @0x1e5474 vldr s14, [r4, #40] */
/* @0x1e5478 lsl r1, r1, #3 */
/* @0x1e547c vcvt.f32.s32 s26, s15 */
/* @0x1e5480 vmov s15, r5 */
/* @0x1e5484 vcvt.f32.s32 s25, s14 */
/* @0x1e5488 vmov s14, r8 */
/* @0x1e548c mov r8, r1 */
/* @0x1e5490 vcvt.f32.s32 s24, s15 */
/* @0x1e5494 vcvt.f32.s32 s23, s14 */
/* @0x1e5498 rsb r0, r6, r11 */
/* @0x1e549c rsb r3, r7, r11 */
/* @0x1e54a0 add r11, r11, #1 */
/* @0x1e54a4 vmov s15, r0 */
/* @0x1e54a8 vcvt.f32.s32 s15, s15 */
/* @0x1e54ac vmov.f32 s18, s24 */
/* @0x1e54b0 vmla.f32 s18, s15, s22 */
/* @0x1e54b4 vmov s15, r3 */
/* @0x1e54b8 vsub.f32 s18, s18, s23 */
/* @0x1e54bc vmul.f32 s14, s18, s16 */
/* @0x1e54c0 vcvt.f32.s32 s19, s15 */
/* @0x1e54c4 vmla.f32 s14, s19, s17 */
/* @0x1e54c8 vdiv.f32 s14, s14, s20 */
/* @0x1e54cc vadd.f32 s14, s14, s26 */
/* @0x1e54d0 vmov r0, s14 */
/* @0x1e54d4 bl 0xb6910 <floorf@plt> */
/* @0x1e54d8 vmul.f32 s15, s16, s19 */
/* @0x1e54dc vnmls.f32 s15, s17, s18 */
/* @0x1e54e0 vmov s14, r0 */
/* @0x1e54e4 vdiv.f32 s15, s15, s21 */
/* @0x1e54e8 vadd.f32 s15, s15, s25 */
/* @0x1e54ec vcvt.s32.f32 s14, s14 */
/* @0x1e54f0 vmov r0, s15 */
/* @0x1e54f4 vmov r5, s14 */
/* @0x1e54f8 bl 0xb6910 <floorf@plt> */
/* @0x1e54fc cmp r5, #0 */
/* @0x1e5500 vmov s15, r0 */
/* @0x1e5504 blt 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290> */
/* @0x1e5508 ldr r3, [r4, #0x1c] */
/* @0x1e550c cmp r5, r3 */
/* @0x1e5510 bge 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290> */
/* @0x1e5514 vcvt.s32.f32 s15, s15 */
/* @0x1e5518 vmov r2, s15 */
/* @0x1e551c cmp r2, #0 */
/* @0x1e5520 blt 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290> */
/* @0x1e5524 ldr r1, [r4, #0x20] */
/* @0x1e5528 cmp r2, r1 */
/* @0x1e552c bge 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290> */
/* @0x1e5530 ldr r1, [r4, #0x40] */
/* @0x1e5534 add r1, r1, r8 */
/* @0x1e5538 ldr r1, [r1, #0x4] */
/* @0x1e553c mla r3, r3, r2, r1 */
/* @0x1e5540 ldrb r2, [r3, r5] */
/* @0x1e5544 cmp r2, #0 */
/* @0x1e5548 bne 0x1e56e8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x42c> */
/* @0x1e554c cmp r9, r11 */
/* @0x1e5550 bge 0x1e5498 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x1dc> */
/* @0x1e5554 mov r0, r10 */
/* @0x1e5558 add sp, sp, #52 */
/* @0x1e555c vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1e5560 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e5564 ldr r3, [sp, #0xa4] */
/* @0x1e5568 cmp r5, r3 */
/* @0x1e556c ble 0x1e5590 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x2d4> */
/* @0x1e5570 ldr r12, [sp, #0xa0] */
/* @0x1e5574 mov r3, r5 */
/* @0x1e5578 rsb r0, r12, r6 */
/* @0x1e557c ldr r12, [sp, #0xa4] */
/* @0x1e5580 ldr r6, [sp, #0xa0] */
/* @0x1e5584 rsb r2, r12, r5 */
/* @0x1e5588 str r3, [sp, #0xa4] */
/* @0x1e558c mov r5, r12 */
/* @0x1e5590 vmov s14, r0 */
/* @0x1e5594 ldr r3, [r11, #0x4] */
/* @0x1e5598 ldr r0, [r11, #0xc] */
/* @0x1e559c vcvt.f32.s32 s22, s14 */
/* @0x1e55a0 ldr r9, [sp, #0xa4] */
/* @0x1e55a4 vmov s14, r2 */
/* @0x1e55a8 cmp r5, r3 */
/* @0x1e55ac movge r11, r5 */
/* @0x1e55b0 movlt r11, r3 */
/* @0x1e55b4 cmp r9, r0 */
/* @0x1e55b8 movge r9, r0 */
/* @0x1e55bc cmp r9, r11 */
/* @0x1e55c0 vcvt.f32.s32 s15, s14 */
/* @0x1e55c4 vdiv.f32 s22, s22, s15 */
/* @0x1e55c8 blt 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4> */
/* @0x1e55cc vldr s15, [r4, #36] */
/* @0x1e55d0 vldr s14, [r4, #40] */
/* @0x1e55d4 lsl r1, r1, #3 */
/* @0x1e55d8 vcvt.f32.s32 s26, s15 */
/* @0x1e55dc vmov s15, r6 */
/* @0x1e55e0 vcvt.f32.s32 s25, s14 */
/* @0x1e55e4 vmov s14, r7 */
/* @0x1e55e8 mov r7, r1 */
/* @0x1e55ec vcvt.f32.s32 s24, s15 */
/* @0x1e55f0 vcvt.f32.s32 s23, s14 */
/* @0x1e55f4 rsb r3, r5, r11 */
/* @0x1e55f8 rsb r0, r8, r11 */
/* @0x1e55fc add r11, r11, #1 */
/* @0x1e5600 vmov s14, r3 */
/* @0x1e5604 vmov s18, r0 */
/* @0x1e5608 vcvt.f32.s32 s15, s14 */
/* @0x1e560c vmov.f32 s19, s24 */
/* @0x1e5610 vmla.f32 s19, s15, s22 */
/* @0x1e5614 vcvt.f32.s32 s18, s18 */
/* @0x1e5618 vmul.f32 s14, s18, s16 */
/* @0x1e561c vsub.f32 s19, s19, s23 */
/* @0x1e5620 vmla.f32 s14, s19, s17 */
/* @0x1e5624 vdiv.f32 s14, s14, s20 */
/* @0x1e5628 vadd.f32 s14, s14, s26 */
/* @0x1e562c vmov r0, s14 */
/* @0x1e5630 bl 0xb6910 <floorf@plt> */
/* @0x1e5634 vmul.f32 s15, s16, s19 */
/* @0x1e5638 vnmls.f32 s15, s17, s18 */
/* @0x1e563c vmov s14, r0 */
/* @0x1e5640 vdiv.f32 s15, s15, s21 */
/* @0x1e5644 vadd.f32 s15, s15, s25 */
/* @0x1e5648 vcvt.s32.f32 s14, s14 */
/* @0x1e564c vmov r0, s15 */
/* @0x1e5650 vmov r6, s14 */
/* @0x1e5654 bl 0xb6910 <floorf@plt> */
/* @0x1e5658 cmp r6, #0 */
/* @0x1e565c vmov s15, r0 */
/* @0x1e5660 blt 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec> */
/* @0x1e5664 ldr r3, [r4, #0x1c] */
/* @0x1e5668 cmp r6, r3 */
/* @0x1e566c bge 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec> */
/* @0x1e5670 vcvt.s32.f32 s15, s15 */
/* @0x1e5674 vmov r2, s15 */
/* @0x1e5678 cmp r2, #0 */
/* @0x1e567c blt 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec> */
/* @0x1e5680 ldr r1, [r4, #0x20] */
/* @0x1e5684 cmp r2, r1 */
/* @0x1e5688 bge 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec> */
/* @0x1e568c ldr r1, [r4, #0x40] */
/* @0x1e5690 add r1, r1, r7 */
/* @0x1e5694 ldr r1, [r1, #0x4] */
/* @0x1e5698 mla r3, r3, r2, r1 */
/* @0x1e569c ldrb r2, [r3, r6] */
/* @0x1e56a0 cmp r2, #0 */
/* @0x1e56a4 bne 0x1e56e8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x42c> */
/* @0x1e56a8 cmp r11, r9 */
/* @0x1e56ac ble 0x1e55f4 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x338> */
/* @0x1e56b0 mov r0, r10 */
/* @0x1e56b4 add sp, sp, #52 */
/* @0x1e56b8 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1e56bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e56c0 cmp r5, r3 */
/* @0x1e56c4 movlt r5, r3 */
/* @0x1e56c8 str r3, [sp, #0x24] */
/* @0x1e56cc str r2, [sp, #0x28] */
/* @0x1e56d0 b 0x1e535c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xa0> */
/* @0x1e56d4 mov r10, #0 */
/* @0x1e56d8 mov r0, r10 */
/* @0x1e56dc add sp, sp, #52 */
/* @0x1e56e0 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1e56e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e56e8 mov r10, r2 */
/* @0x1e56ec b 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4> */
/* @0x1e56f0 ldrdmi r0, r1, [r9], #-251 */
/* @0x1e56f4 teqmi r4, #0 */

/* ── FUNC 0x1e56f8 · CSprite::ComputeCollisionMask() · size=4 · insn=1 */
/* @0x1e56f8 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */

/* ── FUNC 0x1e56fc · CSprite::FreeTexture() · size=76 · insn=19 */
/* @0x1e56fc ldr r2, [r0, #0x4c] */
/* @0x1e5700 push {r4, r5, r6, lr} */
/* @0x1e5704 cmp r2, #0 */
/* @0x1e5708 mov r5, r0 */
/* @0x1e570c pople {r4, r5, r6, pc} */
/* @0x1e5710 ldr r3, [r0, #0x50] */
/* @0x1e5714 mov r4, #0 */
/* @0x1e5718 mvn r6, #0 */
/* @0x1e571c ldr r0, [r3, r4, lsl #2] */
/* @0x1e5720 cmp r0, #0 */
/* @0x1e5724 blt 0x1e5738 <_ZN7CSprite11FreeTextureEv+0x3c> */
/* @0x1e5728 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x1e572c ldr r3, [r5, #0x50] */
/* @0x1e5730 str r6, [r3, r4, lsl #2] */
/* @0x1e5734 ldr r2, [r5, #0x4c] */
/* @0x1e5738 add r4, r4, #1 */
/* @0x1e573c cmp r2, r4 */
/* @0x1e5740 bgt 0x1e571c <_ZN7CSprite11FreeTextureEv+0x20> */
/* @0x1e5744 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1e5748 · CSprite::InitTexture() · size=172 · insn=43 */
/* @0x1e5748 push {r4, r5, r6, lr} */
/* @0x1e574c mov r5, r0 */
/* @0x1e5750 bl 0x1e56fc <_ZN7CSprite11FreeTextureEv> */
/* @0x1e5754 ldr r3, [r5, #0x54] */
/* @0x1e5758 cmp r3, #0 */
/* @0x1e575c beq 0x1e576c <_ZN7CSprite11InitTextureEv+0x24> */
/* @0x1e5760 ldrb r3, [r5, #0x36] */
/* @0x1e5764 cmp r3, #0 */
/* @0x1e5768 popeq {r4, r5, r6, pc} */
/* @0x1e576c ldr r1, [r5, #0x18] */
/* @0x1e5770 movw r3, #0x705 */
/* @0x1e5774 ldr r2, [pc, #0x74] */
/* @0x1e5778 add r0, r5, #80 */
/* @0x1e577c add r2, pc, r2 */
/* @0x1e5780 lsl r1, r1, #2 */
/* @0x1e5784 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e5788 ldr r3, [r5, #0x18] */
/* @0x1e578c cmp r3, #0 */
/* @0x1e5790 str r3, [r5, #0x4c] */
/* @0x1e5794 pople {r4, r5, r6, pc} */
/* @0x1e5798 mov r4, #0 */
/* @0x1e579c b 0x1e57b0 <_ZN7CSprite11InitTextureEv+0x68> */
/* @0x1e57a0 ldr r3, [r5, #0x18] */
/* @0x1e57a4 add r4, r4, #1 */
/* @0x1e57a8 cmp r4, r3 */
/* @0x1e57ac bge 0x1e57ec <_ZN7CSprite11InitTextureEv+0xa4> */
/* @0x1e57b0 ldr r3, [r5, #0x48] */
/* @0x1e57b4 ldr r6, [r5, #0x50] */
/* @0x1e57b8 ldr r0, [r3, r4, lsl #2] */
/* @0x1e57bc bl 0x173e70 <_Z24GR_Texture_Create_DirectP9CBitmap32> */
/* @0x1e57c0 ldrb r3, [r5, #0x34] */
/* @0x1e57c4 cmp r3, #0 */
/* @0x1e57c8 str r0, [r6, r4, lsl #2] */
/* @0x1e57cc beq 0x1e57a0 <_ZN7CSprite11InitTextureEv+0x58> */
/* @0x1e57d0 ldr r3, [r5, #0x50] */
/* @0x1e57d4 ldr r0, [r3, r4, lsl #2] */
/* @0x1e57d8 add r4, r4, #1 */
/* @0x1e57dc bl 0x174288 <_Z18GR_Texture_Preloadi> */
/* @0x1e57e0 ldr r3, [r5, #0x18] */
/* @0x1e57e4 cmp r4, r3 */
/* @0x1e57e8 blt 0x1e57b0 <_ZN7CSprite11InitTextureEv+0x68> */
/* @0x1e57ec pop {r4, r5, r6, pc} */
/* @0x1e57f0 andseq r12, r6, r8, lsr #25 */

/* ── FUNC 0x1e57f4 · CSprite::GetTexture(int) · size=96 · insn=24 */
/* @0x1e57f4 push {r3, r4, r5, lr} */
/* @0x1e57f8 mov r4, r0 */
/* @0x1e57fc ldr r3, [r0, #0x74] */
/* @0x1e5800 cmp r3, #1 */
/* @0x1e5804 beq 0x1e584c <_ZN7CSprite10GetTextureEi+0x58> */
/* @0x1e5808 ldr r5, [r0, #0x18] */
/* @0x1e580c cmp r5, #0 */
/* @0x1e5810 ble 0x1e584c <_ZN7CSprite10GetTextureEi+0x58> */
/* @0x1e5814 mov r0, r1 */
/* @0x1e5818 mov r1, r5 */
/* @0x1e581c bl 0x318dec <__aeabi_idivmod> */
/* @0x1e5820 ldr r3, [r4, #0x54] */
/* @0x1e5824 cmp r1, #0 */
/* @0x1e5828 addlt r1, r1, r5 */
/* @0x1e582c cmp r3, #0 */
/* @0x1e5830 beq 0x1e5840 <_ZN7CSprite10GetTextureEi+0x4c> */
/* @0x1e5834 ldrb r2, [r4, #0x36] */
/* @0x1e5838 cmp r2, #0 */
/* @0x1e583c beq 0x1e5844 <_ZN7CSprite10GetTextureEi+0x50> */
/* @0x1e5840 ldr r3, [r4, #0x50] */
/* @0x1e5844 ldr r0, [r3, r1, lsl #2] */
/* @0x1e5848 pop {r3, r4, r5, pc} */
/* @0x1e584c mvn r0, #0 */
/* @0x1e5850 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1e5854 · CSprite::InitLocalTPE() · size=308 · insn=77 */
/* @0x1e5854 push {r4, r5, r6, r7, r8, lr} */
/* @0x1e5858 mov r5, r0 */
/* @0x1e585c ldr r0, [r0, #0x54] */
/* @0x1e5860 cmp r0, #0 */
/* @0x1e5864 beq 0x1e58ac <_ZN7CSprite12InitLocalTPEEv+0x58> */
/* @0x1e5868 ldrb r3, [r5, #0x36] */
/* @0x1e586c cmp r3, #0 */
/* @0x1e5870 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1e5874 ldr r3, [r5, #0x38] */
/* @0x1e5878 cmp r3, #0 */
/* @0x1e587c ble 0x1e58a0 <_ZN7CSprite12InitLocalTPEEv+0x4c> */
/* @0x1e5880 mov r4, #0 */
/* @0x1e5884 ldr r0, [r0, r4, lsl #2] */
/* @0x1e5888 add r4, r4, #1 */
/* @0x1e588c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e5890 ldr r3, [r5, #0x38] */
/* @0x1e5894 ldr r0, [r5, #0x54] */
/* @0x1e5898 cmp r3, r4 */
/* @0x1e589c bgt 0x1e5884 <_ZN7CSprite12InitLocalTPEEv+0x30> */
/* @0x1e58a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e58a4 mov r3, #0 */
/* @0x1e58a8 str r3, [r5, #0x54] */
/* @0x1e58ac ldr r8, [pc, #0xd0] */
/* @0x1e58b0 movw r2, #0x76a */
/* @0x1e58b4 ldr r0, [r5, #0x44] */
/* @0x1e58b8 mov r3, #1 */
/* @0x1e58bc add r8, pc, r8 */
/* @0x1e58c0 lsl r0, r0, #2 */
/* @0x1e58c4 mov r1, r8 */
/* @0x1e58c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e58cc ldr r2, [r5, #0x44] */
/* @0x1e58d0 cmp r2, #0 */
/* @0x1e58d4 str r0, [r5, #0x54] */
/* @0x1e58d8 ble 0x1e5974 <_ZN7CSprite12InitLocalTPEEv+0x120> */
/* @0x1e58dc mov r6, #0 */
/* @0x1e58e0 mov r4, r0 */
/* @0x1e58e4 mov r7, r6 */
/* @0x1e58e8 b 0x1e58f0 <_ZN7CSprite12InitLocalTPEEv+0x9c> */
/* @0x1e58ec ldr r4, [r5, #0x54] */
/* @0x1e58f0 mov r1, r8 */
/* @0x1e58f4 movw r2, #0x76d */
/* @0x1e58f8 mov r3, #1 */
/* @0x1e58fc mov r0, #22 */
/* @0x1e5900 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e5904 str r0, [r4, r6, lsl #2] */
/* @0x1e5908 ldr r2, [r5, #0x54] */
/* @0x1e590c ldr r3, [r5, #0x48] */
/* @0x1e5910 ldr r4, [r2, r6, lsl #2] */
/* @0x1e5914 ldr r0, [r3, r6, lsl #2] */
/* @0x1e5918 strh r7, [r4] */
/* @0x1e591c strh r7, [r4, #2] */
/* @0x1e5920 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x1e5924 ldr r3, [r5, #0x48] */
/* @0x1e5928 strh r0, [r4, #4] */
/* @0x1e592c ldr r0, [r3, r6, lsl #2] */
/* @0x1e5930 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x1e5934 ldr r1, [r5, #0x50] */
/* @0x1e5938 ldr r2, [r5, #0x44] */
/* @0x1e593c ldrh r3, [r4, #4] */
/* @0x1e5940 ldr r1, [r1, r6, lsl #2] */
/* @0x1e5944 add r6, r6, #1 */
/* @0x1e5948 cmp r6, r2 */
/* @0x1e594c strh r7, [r4, #8] */
/* @0x1e5950 strh r7, [r4, #10] */
/* @0x1e5954 strh r1, [r4, #20] */
/* @0x1e5958 strh r3, [r4, #12] */
/* @0x1e595c strh r3, [r4, #16] */
/* @0x1e5960 uxth r0, r0 */
/* @0x1e5964 strh r0, [r4, #6] */
/* @0x1e5968 strh r0, [r4, #14] */
/* @0x1e596c strh r0, [r4, #18] */
/* @0x1e5970 blt 0x1e58ec <_ZN7CSprite12InitLocalTPEEv+0x98> */
/* @0x1e5974 mov r3, #1 */
/* @0x1e5978 str r2, [r5, #0x38] */
/* @0x1e597c strb r3, [r5, #0x36] */
/* @0x1e5980 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e5984 andseq r12, r6, r8, ror #22 */
