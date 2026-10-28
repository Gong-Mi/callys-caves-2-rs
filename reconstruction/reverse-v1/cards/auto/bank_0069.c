/* libyoyo.so 覆盖卡组 0069
 * 函数 0x137acc..0x1392d4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x137acc · F_FileExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x137acc push {r3, r4, r5, r6, r7, lr} */
/* @0x137ad0 mov r1, #0 */
/* @0x137ad4 mov r4, r0 */
/* @0x137ad8 ldr r0, [sp, #0x18] */
/* @0x137adc mov r5, r1 */
/* @0x137ae0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x137ae4 str r5, [r4, #0xc] */
/* @0x137ae8 mov r6, r0 */
/* @0x137aec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x137af0 subs r7, r0, #0 */
/* @0x137af4 movne r3, #0 */
/* @0x137af8 movtne r3, #0x3ff0 */
/* @0x137afc bne 0x137b20 <_Z12F_FileExistsR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x137b00 mov r0, r6 */
/* @0x137b04 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x137b08 cmp r0, #0 */
/* @0x137b0c moveq r5, r0 */
/* @0x137b10 movne r3, #0 */
/* @0x137b14 movtne r3, #0x3ff0 */
/* @0x137b18 moveq r3, r5 */
/* @0x137b1c movne r5, r7 */
/* @0x137b20 str r5, [r4] */
/* @0x137b24 str r3, [r4, #0x4] */
/* @0x137b28 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x137b2c · F_FileTextOpenRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=476 · insn=119 */
/* @0x137b2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x137b30 mov r3, #0 */
/* @0x137b34 ldr r6, [pc, #0x1a8] */
/* @0x137b38 mov r5, r0 */
/* @0x137b3c ldr r12, [pc, #0x1a4] */
/* @0x137b40 sub sp, sp, #1040 */
/* @0x137b44 add r6, pc, r6 */
/* @0x137b48 sub sp, sp, #4 */
/* @0x137b4c mov r2, r3 */
/* @0x137b50 movt r2, #0xbff0 */
/* @0x137b54 ldr r7, [r6, r12] */
/* @0x137b58 mov r1, r3 */
/* @0x137b5c str r2, [r5, #0x4] */
/* @0x137b60 mov r4, #1 */
/* @0x137b64 str r3, [r5, #0xc] */
/* @0x137b68 ldr r2, [r7] */
/* @0x137b6c ldr r0, [sp, #0x438] */
/* @0x137b70 str r3, [r5] */
/* @0x137b74 str r2, [sp, #0x40c] */
/* @0x137b78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x137b7c ldr r3, [pc, #0x168] */
/* @0x137b80 ldr r3, [r6, r3] */
/* @0x137b84 str r3, [sp, #0x4] */
/* @0x137b88 mov r9, r0 */
/* @0x137b8c b 0x137b9c <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x137b90 add r4, r4, #1 */
/* @0x137b94 cmp r4, #32 */
/* @0x137b98 beq 0x137ca0 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x137b9c ldr r2, [r3, #0x4]! */
/* @0x137ba0 cmp r2, #0 */
/* @0x137ba4 bne 0x137b90 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x137ba8 ldr r1, [pc, #0x140] */
/* @0x137bac lsl r11, r4, #1 */
/* @0x137bb0 add r3, r11, r4 */
/* @0x137bb4 ldr r10, [r6, r1] */
/* @0x137bb8 lsl r8, r3, #2 */
/* @0x137bbc ldr r0, [r10, r8] */
/* @0x137bc0 cmp r0, #0 */
/* @0x137bc4 beq 0x137bd8 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x137bc8 str r2, [sp] */
/* @0x137bcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x137bd0 ldr r2, [sp] */
/* @0x137bd4 str r2, [r10, r8] */
/* @0x137bd8 mov r0, r9 */
/* @0x137bdc bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x137be0 cmp r0, #0 */
/* @0x137be4 beq 0x137c68 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x137be8 mov r2, r9 */
/* @0x137bec add r9, sp, #12 */
/* @0x137bf0 mov r1, #1024 */
/* @0x137bf4 mov r0, r9 */
/* @0x137bf8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x137bfc mov r0, r9 */
/* @0x137c00 add r11, r11, r4 */
/* @0x137c04 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x137c08 ldr r1, [pc, #0xe4] */
/* @0x137c0c lsl r11, r11, #2 */
/* @0x137c10 add r1, pc, r1 */
/* @0x137c14 add r8, r10, r11 */
/* @0x137c18 str r0, [r10, r11] */
/* @0x137c1c mov r9, r0 */
/* @0x137c20 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x137c24 cmp r0, #0 */
/* @0x137c28 str r0, [r8, #0x8] */
/* @0x137c2c beq 0x137ccc <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x137c30 vmov s15, r4 */
/* @0x137c34 ldr r0, [sp, #0x4] */
/* @0x137c38 mov r1, #1 */
/* @0x137c3c vcvt.f64.s32 d7, s15 */
/* @0x137c40 str r1, [r0, r4, lsl #2] */
/* @0x137c44 vmov r2, r3, d7 */
/* @0x137c48 stm r5, {r2, r3} */
/* @0x137c4c ldr r2, [sp, #0x40c] */
/* @0x137c50 ldr r3, [r7] */
/* @0x137c54 cmp r2, r3 */
/* @0x137c58 bne 0x137ce0 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x137c5c add sp, sp, #1040 */
/* @0x137c60 add sp, sp, #4 */
/* @0x137c64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x137c68 mov r0, r9 */
/* @0x137c6c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x137c70 cmp r0, #0 */
/* @0x137c74 bne 0x137cb4 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x137c78 ldr r1, [pc, #0x78] */
/* @0x137c7c mov r2, r9 */
/* @0x137c80 ldr r3, [pc, #0x74] */
/* @0x137c84 add r1, pc, r1 */
/* @0x137c88 ldr r3, [r6, r3] */
/* @0x137c8c ldr r0, [r3] */
/* @0x137c90 ldr r3, [r0] */
/* @0x137c94 ldr r3, [r3, #0xc] */
/* @0x137c98 blx r3 */
/* @0x137c9c b 0x137c4c <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x137ca0 ldr r0, [pc, #0x58] */
/* @0x137ca4 mov r1, #0 */
/* @0x137ca8 add r0, pc, r0 */
/* @0x137cac bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x137cb0 b 0x137c4c <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x137cb4 mov r2, r9 */
/* @0x137cb8 add r9, sp, #12 */
/* @0x137cbc mov r1, #1024 */
/* @0x137cc0 mov r0, r9 */
/* @0x137cc4 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x137cc8 b 0x137bfc <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x137ccc ldr r1, [pc, #0x30] */
/* @0x137cd0 mov r2, r9 */
/* @0x137cd4 ldr r3, [pc, #0x20] */
/* @0x137cd8 add r1, pc, r1 */
/* @0x137cdc b 0x137c88 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x137ce0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x137ce4 eoreq r10, r11, r12, lsl #2 */
/* @0x137ce8 .word 0xffffbd00 */
/* @0x137cec .word 0xffffd620 */
/* @0x137cf0 .word 0xffffd624 */
/* @0x137cf4 eoreq r8, r0, r12, ror #7 */
/* @0x137cf8 eoreq r8, r0, r0, asr r3 */
/* @0x137cfc .word 0xffffbac4 */
/* @0x137d00 eoreq r8, r0, r8, asr r3 */
/* @0x137d04 .word 0x002082fc */

/* ── FUNC 0x137d08 · F_FileTextEof(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x137d08 push {r3, r4, r5, lr} */
/* @0x137d0c mov r1, #0 */
/* @0x137d10 mov r4, r0 */
/* @0x137d14 ldr r0, [sp, #0x10] */
/* @0x137d18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x137d1c sub r3, r0, #1 */
/* @0x137d20 cmp r3, #30 */
/* @0x137d24 bhi 0x137d3c <_Z13F_FileTextEofR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x137d28 ldr r3, [pc, #0x60] */
/* @0x137d2c ldr r3, [pc, r3] */
/* @0x137d30 ldr r3, [r3, r0, lsl #2] */
/* @0x137d34 cmp r3, #1 */
/* @0x137d38 beq 0x137d50 <_Z13F_FileTextEofR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x137d3c ldr r0, [pc, #0x50] */
/* @0x137d40 mov r1, #0 */
/* @0x137d44 pop {r3, r4, r5, lr} */
/* @0x137d48 add r0, pc, r0 */
/* @0x137d4c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x137d50 ldr r3, [pc, #0x40] */
/* @0x137d54 add r0, r0, r0, lsl #1 */
/* @0x137d58 mov r5, #0 */
/* @0x137d5c str r5, [r4, #0xc] */
/* @0x137d60 ldr r3, [pc, r3] */
/* @0x137d64 add r3, r3, r0, lsl #2 */
/* @0x137d68 ldr r0, [r3, #0x8] */
/* @0x137d6c bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x137d70 cmp r0, #0 */
/* @0x137d74 moveq r5, r0 */
/* @0x137d78 movne r3, r5 */
/* @0x137d7c moveq r3, r5 */
/* @0x137d80 movtne r3, #0x3ff0 */
/* @0x137d84 str r5, [r4] */
/* @0x137d88 str r3, [r4, #0x4] */
/* @0x137d8c pop {r3, r4, r5, pc} */
/* @0x137d90 eoreq r7, r11, r4, asr #10 */
/* @0x137d94 eoreq r8, r0, r8, ror #5 */
/* @0x137d98 eoreq r7, r11, r4, lsl r5 */

/* ── FUNC 0x137d9c · F_FileTextEoln(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x137d9c push {r3, r4, r5, lr} */
/* @0x137da0 mov r1, #0 */
/* @0x137da4 mov r4, r0 */
/* @0x137da8 ldr r0, [sp, #0x10] */
/* @0x137dac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x137db0 sub r3, r0, #1 */
/* @0x137db4 cmp r3, #30 */
/* @0x137db8 bhi 0x137dd0 <_Z14F_FileTextEolnR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x137dbc ldr r3, [pc, #0x60] */
/* @0x137dc0 ldr r3, [pc, r3] */
/* @0x137dc4 ldr r3, [r3, r0, lsl #2] */
/* @0x137dc8 cmp r3, #1 */
/* @0x137dcc beq 0x137de4 <_Z14F_FileTextEolnR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x137dd0 ldr r0, [pc, #0x50] */
/* @0x137dd4 mov r1, #0 */
/* @0x137dd8 pop {r3, r4, r5, lr} */
/* @0x137ddc add r0, pc, r0 */
/* @0x137de0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x137de4 ldr r3, [pc, #0x40] */
/* @0x137de8 add r0, r0, r0, lsl #1 */
/* @0x137dec mov r5, #0 */
/* @0x137df0 str r5, [r4, #0xc] */
/* @0x137df4 ldr r3, [pc, r3] */
/* @0x137df8 add r3, r3, r0, lsl #2 */
/* @0x137dfc ldr r0, [r3, #0x8] */
/* @0x137e00 bl 0x18de98 <_ZN8LoadSave7yyfeolnEP7_YYFILE> */
/* @0x137e04 cmp r0, #0 */
/* @0x137e08 moveq r5, r0 */
/* @0x137e0c movne r3, r5 */
/* @0x137e10 moveq r3, r5 */
/* @0x137e14 movtne r3, #0x3ff0 */
/* @0x137e18 str r5, [r4] */
/* @0x137e1c str r3, [r4, #0x4] */
/* @0x137e20 pop {r3, r4, r5, pc} */
/* @0x137e24 .word 0x002b74b0 */
/* @0x137e28 eoreq r8, r0, r4, asr r2 */
/* @0x137e2c eoreq r7, r11, r0, lsl #9 */

/* ── FUNC 0x137e30 · F_FileTextReadString(RValue&, CInstance*, CInstance*, int, RValue*) · size=456 · insn=114 */
/* @0x137e30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x137e34 sub sp, sp, #20 */
/* @0x137e38 mov r9, r0 */
/* @0x137e3c mov r1, #0 */
/* @0x137e40 ldr r0, [sp, #0x38] */
/* @0x137e44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x137e48 sub r3, r0, #1 */
/* @0x137e4c mov r5, r0 */
/* @0x137e50 cmp r3, #30 */
/* @0x137e54 bhi 0x137e6c <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x137e58 ldr r3, [pc, #0x180] */
/* @0x137e5c ldr r3, [pc, r3] */
/* @0x137e60 ldr r3, [r3, r0, lsl #2] */
/* @0x137e64 cmp r3, #1 */
/* @0x137e68 beq 0x137e84 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x137e6c ldr r0, [pc, #0x170] */
/* @0x137e70 mov r1, #0 */
/* @0x137e74 add r0, pc, r0 */
/* @0x137e78 add sp, sp, #20 */
/* @0x137e7c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x137e80 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x137e84 ldr r1, [pc, #0x15c] */
/* @0x137e88 mov r0, #1024 */
/* @0x137e8c movw r2, #0x409 */
/* @0x137e90 mov r3, #0 */
/* @0x137e94 add r1, pc, r1 */
/* @0x137e98 lsl r12, r5, #1 */
/* @0x137e9c str r12, [sp, #0xc] */
/* @0x137ea0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x137ea4 ldr r12, [sp, #0xc] */
/* @0x137ea8 mov r4, #0 */
/* @0x137eac ldr r10, [pc, #0x138] */
/* @0x137eb0 mov r7, #1024 */
/* @0x137eb4 add r6, r12, r5 */
/* @0x137eb8 ldr r12, [pc, #0x130] */
/* @0x137ebc ldr r10, [pc, r10] */
/* @0x137ec0 add r6, r10, r6, lsl #2 */
/* @0x137ec4 add r12, pc, r12 */
/* @0x137ec8 str r12, [sp, #0x8] */
/* @0x137ecc mov r8, r0 */
/* @0x137ed0 ldr r0, [r6, #0x8] */
/* @0x137ed4 bl 0x18df2c <_ZN8LoadSave5fgetcEP7_YYFILE> */
/* @0x137ed8 cmp r0, #10 */
/* @0x137edc cmpne r0, #13 */
/* @0x137ee0 mov r11, r0 */
/* @0x137ee4 bne 0x137f30 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x137ee8 mov r3, #12 */
/* @0x137eec mla r3, r3, r5, r10 */
/* @0x137ef0 ldr r0, [r3, #0x8] */
/* @0x137ef4 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x137ef8 cmp r11, #13 */
/* @0x137efc cmpne r11, #10 */
/* @0x137f00 beq 0x137f60 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x137f04 cmp r7, r4 */
/* @0x137f08 ble 0x137fb4 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x137f0c mov r0, r9 */
/* @0x137f10 mov r3, #0 */
/* @0x137f14 mov r1, r8 */
/* @0x137f18 strb r3, [r8, r4] */
/* @0x137f1c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x137f20 mov r0, r8 */
/* @0x137f24 add sp, sp, #20 */
/* @0x137f28 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x137f2c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x137f30 cmp r4, r7 */
/* @0x137f34 add r4, r4, #1 */
/* @0x137f38 bge 0x137f88 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x137f3c add r3, r8, r4 */
/* @0x137f40 strb r11, [r3, #-0x1] */
/* @0x137f44 ldr r0, [r6, #0x8] */
/* @0x137f48 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x137f4c cmp r0, #0 */
/* @0x137f50 beq 0x137ed0 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x137f54 cmp r11, #13 */
/* @0x137f58 cmpne r11, #10 */
/* @0x137f5c bne 0x137f04 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x137f60 ldr r12, [sp, #0xc] */
/* @0x137f64 add r5, r12, r5 */
/* @0x137f68 add r10, r10, r5, lsl #2 */
/* @0x137f6c ldr r0, [r10, #0x8] */
/* @0x137f70 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0x137f74 mov r2, #0 */
/* @0x137f78 sub r1, r0, #1 */
/* @0x137f7c ldr r0, [r10, #0x8] */
/* @0x137f80 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x137f84 b 0x137f04 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x137f88 add r3, r7, r7, lsr #31 */
/* @0x137f8c mov r2, #0 */
/* @0x137f90 mov r0, r8 */
/* @0x137f94 str r2, [sp] */
/* @0x137f98 add r7, r7, r3, asr #1 */
/* @0x137f9c ldr r2, [sp, #0x8] */
/* @0x137fa0 movw r3, #0x412 */
/* @0x137fa4 mov r1, r7 */
/* @0x137fa8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x137fac mov r8, r0 */
/* @0x137fb0 b 0x137f3c <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x137fb4 add r1, r7, r7, lsr #31 */
/* @0x137fb8 ldr r2, [pc, #0x34] */
/* @0x137fbc mov r0, r8 */
/* @0x137fc0 mov r3, #0 */
/* @0x137fc4 add r2, pc, r2 */
/* @0x137fc8 str r3, [sp] */
/* @0x137fcc add r1, r7, r1, asr #1 */
/* @0x137fd0 movw r3, #0x421 */
/* @0x137fd4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x137fd8 mov r8, r0 */
/* @0x137fdc b 0x137f0c <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x137fe0 eoreq r7, r11, r4, lsl r4 */
/* @0x137fe4 .word 0x002081bc */
/* @0x137fe8 .word 0x002081bc */
/* @0x137fec .word 0x002b73b8 */
/* @0x137ff0 eoreq r8, r0, r12, lsl #3 */
/* @0x137ff4 eoreq r8, r0, r12, lsl #1 */

/* ── FUNC 0x137ff8 · F_FileTextReadReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x137ff8 push {r4, lr} */
/* @0x137ffc mov r1, #0 */
/* @0x138000 mov r4, r0 */
/* @0x138004 ldr r0, [sp, #0x8] */
/* @0x138008 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13800c sub r3, r0, #1 */
/* @0x138010 cmp r3, #30 */
/* @0x138014 bhi 0x13802c <_Z18F_FileTextReadRealR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x138018 ldr r3, [pc, #0x48] */
/* @0x13801c ldr r3, [pc, r3] */
/* @0x138020 ldr r3, [r3, r0, lsl #2] */
/* @0x138024 cmp r3, #1 */
/* @0x138028 beq 0x138040 <_Z18F_FileTextReadRealR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x13802c ldr r0, [pc, #0x38] */
/* @0x138030 mov r1, #0 */
/* @0x138034 pop {r4, lr} */
/* @0x138038 add r0, pc, r0 */
/* @0x13803c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x138040 ldr r3, [pc, #0x28] */
/* @0x138044 add r0, r0, r0, lsl #1 */
/* @0x138048 mov r2, #0 */
/* @0x13804c mov r1, r4 */
/* @0x138050 ldr r3, [pc, r3] */
/* @0x138054 str r2, [r4, #0xc] */
/* @0x138058 add r3, r3, r0, lsl #2 */
/* @0x13805c pop {r4, lr} */
/* @0x138060 ldr r0, [r3, #0x8] */
/* @0x138064 b 0x18df88 <_ZN8LoadSave9freadrealEP7_YYFILEPd> */
/* @0x138068 eoreq r7, r11, r4, asr r2 */
/* @0x13806c .word 0x00207ff8 */
/* @0x138070 eoreq r7, r11, r4, lsr #4 */

/* ── FUNC 0x138074 · F_FileTextReadLn(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x138074 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x138078 sub sp, sp, #20 */
/* @0x13807c mov r9, r0 */
/* @0x138080 mov r1, #0 */
/* @0x138084 ldr r0, [sp, #0x38] */
/* @0x138088 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13808c sub r3, r0, #1 */
/* @0x138090 mov r4, r0 */
/* @0x138094 cmp r3, #30 */
/* @0x138098 bhi 0x1380b0 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x13809c ldr r3, [pc, #0x108] */
/* @0x1380a0 ldr r3, [pc, r3] */
/* @0x1380a4 ldr r3, [r3, r0, lsl #2] */
/* @0x1380a8 cmp r3, #1 */
/* @0x1380ac beq 0x1380c8 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1380b0 ldr r0, [pc, #0xf8] */
/* @0x1380b4 mov r1, #0 */
/* @0x1380b8 add r0, pc, r0 */
/* @0x1380bc add sp, sp, #20 */
/* @0x1380c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1380c4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1380c8 ldr r1, [pc, #0xe4] */
/* @0x1380cc movw r2, #0x441 */
/* @0x1380d0 mov r0, #1024 */
/* @0x1380d4 add r7, r4, r4, lsl #1 */
/* @0x1380d8 add r1, pc, r1 */
/* @0x1380dc mov r4, #0 */
/* @0x1380e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1380e4 mov r1, #0 */
/* @0x1380e8 mov r2, #1024 */
/* @0x1380ec mov r8, #1024 */
/* @0x1380f0 mov r5, r0 */
/* @0x1380f4 bl 0xb65b0 <memset@plt> */
/* @0x1380f8 ldr r3, [pc, #0xb8] */
/* @0x1380fc ldr r3, [pc, r3] */
/* @0x138100 add r7, r3, r7, lsl #2 */
/* @0x138104 ldr r3, [pc, #0xb0] */
/* @0x138108 ldr r0, [r7, #0x8] */
/* @0x13810c add r3, pc, r3 */
/* @0x138110 str r3, [sp, #0xc] */
/* @0x138114 bl 0x18df2c <_ZN8LoadSave5fgetcEP7_YYFILE> */
/* @0x138118 mov r6, r0 */
/* @0x13811c add r4, r4, #1 */
/* @0x138120 add r3, r5, r4 */
/* @0x138124 strb r6, [r3, #-0x1] */
/* @0x138128 ldr r0, [r7, #0x8] */
/* @0x13812c bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x138130 subs r11, r0, #0 */
/* @0x138134 bne 0x138190 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x138138 cmp r6, #10 */
/* @0x13813c beq 0x138190 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x138140 ldr r0, [r7, #0x8] */
/* @0x138144 bl 0x18df2c <_ZN8LoadSave5fgetcEP7_YYFILE> */
/* @0x138148 sub r3, r8, #1 */
/* @0x13814c cmp r3, r4 */
/* @0x138150 mov r6, r0 */
/* @0x138154 bgt 0x13811c <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x138158 add r10, r8, #1024 */
/* @0x13815c ldr r2, [sp, #0xc] */
/* @0x138160 str r11, [sp] */
/* @0x138164 mov r0, r5 */
/* @0x138168 mov r1, r10 */
/* @0x13816c movw r3, #0x44a */
/* @0x138170 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x138174 mov r1, r11 */
/* @0x138178 mov r2, #1024 */
/* @0x13817c mov r5, r0 */
/* @0x138180 add r0, r0, r8 */
/* @0x138184 mov r8, r10 */
/* @0x138188 bl 0xb65b0 <memset@plt> */
/* @0x13818c b 0x13811c <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x138190 mov r0, r9 */
/* @0x138194 mov r1, r5 */
/* @0x138198 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13819c mov r0, r5 */
/* @0x1381a0 add sp, sp, #20 */
/* @0x1381a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1381a8 b 0xcef90 <_Z6YYFreePKv> */
/* @0x1381ac .word 0x002b71d0 */
/* @0x1381b0 eoreq r7, r0, r8, ror pc */
/* @0x1381b4 eoreq r7, r0, r8, ror pc */
/* @0x1381b8 eoreq r7, r11, r8, ror r1 */
/* @0x1381bc eoreq r7, r0, r4, asr #30 */

/* ── FUNC 0x1381c0 · F_FileTextWriteString(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1381c0 push {r3, r4, r5, lr} */
/* @0x1381c4 mov r1, #0 */
/* @0x1381c8 ldr r5, [sp, #0x10] */
/* @0x1381cc mov r0, r5 */
/* @0x1381d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1381d4 mov r1, #1 */
/* @0x1381d8 mov r4, r0 */
/* @0x1381dc mov r0, r5 */
/* @0x1381e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1381e4 sub r3, r4, #1 */
/* @0x1381e8 cmp r3, #30 */
/* @0x1381ec bhi 0x138204 <_Z21F_FileTextWriteStringR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1381f0 ldr r3, [pc, #0x48] */
/* @0x1381f4 ldr r3, [pc, r3] */
/* @0x1381f8 ldr r3, [r3, r4, lsl #2] */
/* @0x1381fc cmp r3, #2 */
/* @0x138200 beq 0x138218 <_Z21F_FileTextWriteStringR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x138204 ldr r0, [pc, #0x38] */
/* @0x138208 mov r1, #0 */
/* @0x13820c pop {r3, r4, r5, lr} */
/* @0x138210 add r0, pc, r0 */
/* @0x138214 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x138218 cmp r0, #0 */
/* @0x13821c popeq {r3, r4, r5, pc} */
/* @0x138220 ldr r3, [pc, #0x20] */
/* @0x138224 add r4, r4, r4, lsl #1 */
/* @0x138228 mov r1, r0 */
/* @0x13822c ldr r3, [pc, r3] */
/* @0x138230 add r3, r3, r4, lsl #2 */
/* @0x138234 ldr r0, [r3, #0x8] */
/* @0x138238 pop {r3, r4, r5, lr} */
/* @0x13823c b 0x18e114 <_ZN8LoadSave5fputsEP7_YYFILEPKc> */
/* @0x138240 eoreq r7, r11, r12, ror r0 */
/* @0x138244 eoreq r7, r0, r12, ror lr */
/* @0x138248 eoreq r7, r11, r8, asr #32 */

/* ── FUNC 0x13824c · F_FileTextWriteLn(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x13824c push {r3, lr} */
/* @0x138250 mov r1, #0 */
/* @0x138254 ldr r0, [sp, #0x8] */
/* @0x138258 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13825c sub r3, r0, #1 */
/* @0x138260 cmp r3, #30 */
/* @0x138264 bhi 0x13827c <_Z17F_FileTextWriteLnR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x138268 ldr r3, [pc, #0x44] */
/* @0x13826c ldr r3, [pc, r3] */
/* @0x138270 ldr r3, [r3, r0, lsl #2] */
/* @0x138274 cmp r3, #2 */
/* @0x138278 beq 0x138290 <_Z17F_FileTextWriteLnR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x13827c ldr r0, [pc, #0x34] */
/* @0x138280 mov r1, #0 */
/* @0x138284 pop {r3, lr} */
/* @0x138288 add r0, pc, r0 */
/* @0x13828c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x138290 ldr r3, [pc, #0x24] */
/* @0x138294 add r0, r0, r0, lsl #1 */
/* @0x138298 ldr r1, [pc, #0x20] */
/* @0x13829c ldr r3, [pc, r3] */
/* @0x1382a0 add r3, r3, r0, lsl #2 */
/* @0x1382a4 add r1, pc, r1 */
/* @0x1382a8 ldr r0, [r3, #0x8] */
/* @0x1382ac pop {r3, lr} */
/* @0x1382b0 b 0x18e114 <_ZN8LoadSave5fputsEP7_YYFILEPKc> */
/* @0x1382b4 eoreq r7, r11, r4 */
/* @0x1382b8 eoreq r7, r0, r4, lsl #28 */
/* @0x1382bc .word 0x002b6fd8 */
/* @0x1382c0 ldrsheq r10, [pc], -r4 */

/* ── FUNC 0x1382c4 · F_FileTextWriteReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x1382c4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1382c8 sub sp, sp, #1024 */
/* @0x1382cc ldr r6, [pc, #0xd0] */
/* @0x1382d0 sub sp, sp, #8 */
/* @0x1382d4 mov r1, #0 */
/* @0x1382d8 ldr r6, [pc, r6] */
/* @0x1382dc ldr r4, [sp, #0x420] */
/* @0x1382e0 ldr r3, [r6] */
/* @0x1382e4 mov r0, r4 */
/* @0x1382e8 str r3, [sp, #0x404] */
/* @0x1382ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1382f0 mov r1, #1 */
/* @0x1382f4 mov r7, r0 */
/* @0x1382f8 mov r0, r4 */
/* @0x1382fc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x138300 sub r3, r7, #1 */
/* @0x138304 cmp r3, #30 */
/* @0x138308 mov r4, r0 */
/* @0x13830c mov r5, r1 */
/* @0x138310 bhi 0x138328 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x138314 ldr r3, [pc, #0x8c] */
/* @0x138318 ldr r3, [pc, r3] */
/* @0x13831c ldr r3, [r3, r7, lsl #2] */
/* @0x138320 cmp r3, #2 */
/* @0x138324 beq 0x138354 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x138328 ldr r0, [pc, #0x7c] */
/* @0x13832c mov r1, #0 */
/* @0x138330 add r0, pc, r0 */
/* @0x138334 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x138338 ldr r2, [sp, #0x404] */
/* @0x13833c ldr r3, [r6] */
/* @0x138340 cmp r2, r3 */
/* @0x138344 bne 0x1383a0 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x138348 add sp, sp, #1024 */
/* @0x13834c add sp, sp, #8 */
/* @0x138350 pop {r4, r5, r6, r7, r8, pc} */
/* @0x138354 add r8, sp, #4 */
/* @0x138358 mov r1, #0 */
/* @0x13835c mov r2, #1024 */
/* @0x138360 add r7, r7, r7, lsl #1 */
/* @0x138364 mov r0, r8 */
/* @0x138368 bl 0xb65b0 <memset@plt> */
/* @0x13836c ldr r1, [pc, #0x3c] */
/* @0x138370 mov r3, r5 */
/* @0x138374 mov r0, r8 */
/* @0x138378 mov r2, r4 */
/* @0x13837c add r1, pc, r1 */
/* @0x138380 bl 0xb6550 <sprintf@plt> */
/* @0x138384 ldr r3, [pc, #0x28] */
/* @0x138388 mov r1, r8 */
/* @0x13838c ldr r3, [pc, r3] */
/* @0x138390 add r3, r3, r7, lsl #2 */
/* @0x138394 ldr r0, [r3, #0x8] */
/* @0x138398 bl 0x18e114 <_ZN8LoadSave5fputsEP7_YYFILEPKc> */
/* @0x13839c b 0x138338 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1383a0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1383a4 eoreq r5, r11, r8, ror r6 */
/* @0x1383a8 eoreq r6, r11, r8, asr pc */
/* @0x1383ac eoreq r7, r0, r12, asr sp */
/* @0x1383b0 eoreq r7, r0, r0, lsr sp */
/* @0x1383b4 eoreq r6, r11, r8, ror #29 */

/* ── FUNC 0x1383b8 · F_FileOpenRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x1383b8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1383bc mov r1, #0 */
/* @0x1383c0 ldr r0, [sp, #0x18] */
/* @0x1383c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1383c8 ldr r4, [pc, #0x94] */
/* @0x1383cc ldr r3, [pc, #0x94] */
/* @0x1383d0 add r4, pc, r4 */
/* @0x1383d4 ldr r5, [r4, r3] */
/* @0x1383d8 ldr r3, [r5] */
/* @0x1383dc cmp r3, #0 */
/* @0x1383e0 mov r7, r0 */
/* @0x1383e4 bne 0x13843c <_Z14F_FileOpenReadR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1383e8 mov r0, r7 */
/* @0x1383ec mov r6, #0 */
/* @0x1383f0 str r6, [r5] */
/* @0x1383f4 bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x1383f8 cmp r0, r6 */
/* @0x1383fc popeq {r4, r5, r6, r7, r8, pc} */
/* @0x138400 ldr r3, [pc, #0x64] */
/* @0x138404 ldr r4, [r4, r3] */
/* @0x138408 ldr r0, [r4] */
/* @0x13840c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138410 mov r0, r7 */
/* @0x138414 str r6, [r4] */
/* @0x138418 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x13841c ldr r1, [pc, #0x4c] */
/* @0x138420 add r1, pc, r1 */
/* @0x138424 str r0, [r4] */
/* @0x138428 bl 0xb6844 <fopen@plt> */
/* @0x13842c mov r3, #1 */
/* @0x138430 str r3, [r5] */
/* @0x138434 str r0, [r4, #0x8] */
/* @0x138438 pop {r4, r5, r6, r7, r8, pc} */
/* @0x13843c ldr r3, [pc, #0x28] */
/* @0x138440 mov r8, #0 */
/* @0x138444 ldr r6, [r4, r3] */
/* @0x138448 ldr r0, [r6] */
/* @0x13844c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138450 ldr r0, [r6, #0x8] */
/* @0x138454 str r8, [r6] */
/* @0x138458 bl 0xb6850 <fclose@plt> */
/* @0x13845c str r8, [r6, #0x8] */
/* @0x138460 b 0x1383e8 <_Z14F_FileOpenReadR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x138464 eoreq r9, r11, r0, lsl #17 */
/* @0x138468 .word 0xffffd620 */
/* @0x13846c .word 0xffffd624 */
/* @0x138470 .word 0x00207bdc */

/* ── FUNC 0x138474 · F_FileDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x138474 push {r4, r5, r6, lr} */
/* @0x138478 sub sp, sp, #2048 */
/* @0x13847c ldr r4, [pc, #0x80] */
/* @0x138480 sub sp, sp, #8 */
/* @0x138484 mov r1, #0 */
/* @0x138488 mov r5, r0 */
/* @0x13848c ldr r4, [pc, r4] */
/* @0x138490 ldr r0, [sp, #0x818] */
/* @0x138494 ldr r3, [r4] */
/* @0x138498 str r3, [sp, #0x804] */
/* @0x13849c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1384a0 mov r6, r0 */
/* @0x1384a4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1384a8 cmp r0, #0 */
/* @0x1384ac beq 0x1384e4 <_Z12F_FileDeleteR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1384b0 mov r2, r6 */
/* @0x1384b4 add r6, sp, #4 */
/* @0x1384b8 mov r1, #2048 */
/* @0x1384bc mov r0, r6 */
/* @0x1384c0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1384c4 mov r0, r6 */
/* @0x1384c8 bl 0x18ffb0 <_ZN8LoadSave14RemoveSaveFileEPKc> */
/* @0x1384cc vmov s15, r0 */
/* @0x1384d0 vcvt.f64.s32 d7, s15 */
/* @0x1384d4 vmov r0, r1, d7 */
/* @0x1384d8 vmov r2, s14 */
/* @0x1384dc mov r3, r1 */
/* @0x1384e0 stm r5, {r2, r3} */
/* @0x1384e4 ldr r2, [sp, #0x804] */
/* @0x1384e8 ldr r3, [r4] */
/* @0x1384ec cmp r2, r3 */
/* @0x1384f0 bne 0x138500 <_Z12F_FileDeleteR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1384f4 add sp, sp, #2048 */
/* @0x1384f8 add sp, sp, #8 */
/* @0x1384fc pop {r4, r5, r6, pc} */
/* @0x138500 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x138504 eoreq r5, r11, r4, asr #9 */

/* ── FUNC 0x138508 · F_FileRename(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x138508 push {r4, r5, r6, r7, r8, lr} */
/* @0x13850c sub sp, sp, #4096 */
/* @0x138510 sub sp, sp, #8 */
/* @0x138514 ldr r4, [pc, #0xbc] */
/* @0x138518 add r2, sp, #8192 */
/* @0x13851c mov r1, #0 */
/* @0x138520 ldr r4, [pc, r4] */
/* @0x138524 mov r7, r0 */
/* @0x138528 ldr r5, [r2, #-0xfe0] */
/* @0x13852c ldr r3, [r4] */
/* @0x138530 mov r0, r5 */
/* @0x138534 str r3, [r2, #-0xffc] */
/* @0x138538 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13853c mov r1, #1 */
/* @0x138540 mov r6, r0 */
/* @0x138544 mov r0, r5 */
/* @0x138548 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13854c mov r5, r0 */
/* @0x138550 mov r0, r6 */
/* @0x138554 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x138558 cmp r0, #0 */
/* @0x13855c beq 0x1385b4 <_Z12F_FileRenameR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x138560 mov r2, r6 */
/* @0x138564 add r6, sp, #2048 */
/* @0x138568 add r8, sp, #4 */
/* @0x13856c add r6, r6, #8 */
/* @0x138570 sub r6, r6, #4 */
/* @0x138574 mov r1, #2048 */
/* @0x138578 mov r0, r8 */
/* @0x13857c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x138580 mov r2, r5 */
/* @0x138584 mov r1, #2048 */
/* @0x138588 mov r0, r6 */
/* @0x13858c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x138590 mov r0, r8 */
/* @0x138594 mov r1, r6 */
/* @0x138598 bl 0xb685c <rename@plt> */
/* @0x13859c cmp r0, #0 */
/* @0x1385a0 movne r0, #0 */
/* @0x1385a4 moveq r3, #0 */
/* @0x1385a8 movne r3, r0 */
/* @0x1385ac movteq r3, #0x3ff0 */
/* @0x1385b0 stm r7, {r0, r3} */
/* @0x1385b4 add r3, sp, #8192 */
/* @0x1385b8 ldr r2, [r3, #-0xffc] */
/* @0x1385bc ldr r3, [r4] */
/* @0x1385c0 cmp r2, r3 */
/* @0x1385c4 bne 0x1385d4 <_Z12F_FileRenameR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x1385c8 add sp, sp, #4096 */
/* @0x1385cc add sp, sp, #8 */
/* @0x1385d0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1385d4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1385d8 eoreq r5, r11, r0, lsr r4 */

/* ── FUNC 0x1385dc · F_DirectoryExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x1385dc push {r4, r5, r6, r7, lr} */
/* @0x1385e0 sub sp, sp, #1024 */
/* @0x1385e4 ldr r4, [pc, #0xb0] */
/* @0x1385e8 sub sp, sp, #12 */
/* @0x1385ec mov r5, r0 */
/* @0x1385f0 mov r1, #0 */
/* @0x1385f4 ldr r4, [pc, r4] */
/* @0x1385f8 ldr r0, [sp, #0x420] */
/* @0x1385fc add r6, sp, #4 */
/* @0x138600 ldr r3, [r4] */
/* @0x138604 str r3, [sp, #0x404] */
/* @0x138608 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13860c mov r3, #0 */
/* @0x138610 mov r1, #1024 */
/* @0x138614 str r3, [r5, #0xc] */
/* @0x138618 mov r2, r0 */
/* @0x13861c mov r7, r0 */
/* @0x138620 mov r0, r6 */
/* @0x138624 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x138628 mov r0, r6 */
/* @0x13862c bl 0x214f24 <_Z15DirectoryExistsPKc> */
/* @0x138630 cmp r0, #0 */
/* @0x138634 beq 0x138670 <_Z17F_DirectoryExistsR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x138638 mov r3, #0 */
/* @0x13863c movt r3, #0x3ff0 */
/* @0x138640 mov r2, #0 */
/* @0x138644 mov r1, r2 */
/* @0x138648 ldr r2, [sp, #0x404] */
/* @0x13864c str r1, [r5] */
/* @0x138650 mov r1, r3 */
/* @0x138654 ldr r3, [r4] */
/* @0x138658 str r1, [r5, #0x4] */
/* @0x13865c cmp r2, r3 */
/* @0x138660 bne 0x138698 <_Z17F_DirectoryExistsR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x138664 add sp, sp, #1024 */
/* @0x138668 add sp, sp, #12 */
/* @0x13866c pop {r4, r5, r6, r7, pc} */
/* @0x138670 mov r2, r7 */
/* @0x138674 mov r0, r6 */
/* @0x138678 mov r1, #1024 */
/* @0x13867c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x138680 mov r0, r6 */
/* @0x138684 bl 0x214f24 <_Z15DirectoryExistsPKc> */
/* @0x138688 vmov s15, r0 */
/* @0x13868c vcvt.f64.s32 d7, s15 */
/* @0x138690 vmov r2, r3, d7 */
/* @0x138694 b 0x138644 <_Z17F_DirectoryExistsR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x138698 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13869c eoreq r5, r11, r12, asr r3 */

/* ── FUNC 0x1386a0 · F_DirectoryDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1386a0 push {r4, r5, lr} */
/* @0x1386a4 sub sp, sp, #1024 */
/* @0x1386a8 ldr r4, [pc, #0x58] */
/* @0x1386ac sub sp, sp, #12 */
/* @0x1386b0 mov r1, #0 */
/* @0x1386b4 ldr r4, [pc, r4] */
/* @0x1386b8 ldr r0, [sp, #0x418] */
/* @0x1386bc ldr r3, [r4] */
/* @0x1386c0 str r3, [sp, #0x404] */
/* @0x1386c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1386c8 subs r2, r0, #0 */
/* @0x1386cc beq 0x1386e8 <_Z17F_DirectoryDeleteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1386d0 add r5, sp, #4 */
/* @0x1386d4 mov r1, #1024 */
/* @0x1386d8 mov r0, r5 */
/* @0x1386dc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1386e0 mov r0, r5 */
/* @0x1386e4 bl 0x214e18 <_Z10DestroyDirPKc> */
/* @0x1386e8 ldr r2, [sp, #0x404] */
/* @0x1386ec ldr r3, [r4] */
/* @0x1386f0 cmp r2, r3 */
/* @0x1386f4 bne 0x138704 <_Z17F_DirectoryDeleteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x1386f8 add sp, sp, #1024 */
/* @0x1386fc add sp, sp, #12 */
/* @0x138700 pop {r4, r5, pc} */
/* @0x138704 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x138708 mlaeq r11, r12, r2, r5 */

/* ── FUNC 0x13870c · F_FileAttributes(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x13870c push {r4, r5, r6, r7, lr} */
/* @0x138710 sub sp, sp, #1024 */
/* @0x138714 ldr r5, [pc, #0xc8] */
/* @0x138718 sub sp, sp, #12 */
/* @0x13871c mov r4, r0 */
/* @0x138720 mov r1, #0 */
/* @0x138724 ldr r5, [pc, r5] */
/* @0x138728 ldr r0, [sp, #0x420] */
/* @0x13872c ldr r3, [r5] */
/* @0x138730 str r3, [sp, #0x404] */
/* @0x138734 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138738 mov r3, #0 */
/* @0x13873c str r3, [r4, #0xc] */
/* @0x138740 str r3, [r4] */
/* @0x138744 str r3, [r4, #0x4] */
/* @0x138748 mov r6, r0 */
/* @0x13874c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x138750 subs r7, r0, #0 */
/* @0x138754 bne 0x1387c0 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x138758 mov r0, r6 */
/* @0x13875c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x138760 cmp r0, #0 */
/* @0x138764 bne 0x138784 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x138768 ldr r2, [sp, #0x404] */
/* @0x13876c ldr r3, [r5] */
/* @0x138770 cmp r2, r3 */
/* @0x138774 bne 0x1387e0 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x138778 add sp, sp, #1024 */
/* @0x13877c add sp, sp, #12 */
/* @0x138780 pop {r4, r5, r6, r7, pc} */
/* @0x138784 mov r2, r6 */
/* @0x138788 add r6, sp, #4 */
/* @0x13878c mov r1, #1024 */
/* @0x138790 mov r0, r6 */
/* @0x138794 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x138798 mov r0, r6 */
/* @0x13879c mov r1, r7 */
/* @0x1387a0 bl 0x160ad8 <_Z19YYGetFileAttributesPKcb> */
/* @0x1387a4 vmov s15, r0 */
/* @0x1387a8 vcvt.f64.s32 d7, s15 */
/* @0x1387ac vmov r0, r1, d7 */
/* @0x1387b0 vmov r2, s14 */
/* @0x1387b4 mov r3, r1 */
/* @0x1387b8 stm r4, {r2, r3} */
/* @0x1387bc b 0x138768 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1387c0 mov r2, r6 */
/* @0x1387c4 add r6, sp, #4 */
/* @0x1387c8 mov r1, #1024 */
/* @0x1387cc mov r0, r6 */
/* @0x1387d0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1387d4 mov r0, r6 */
/* @0x1387d8 mov r1, #1 */
/* @0x1387dc b 0x1387a0 <_Z16F_FileAttributesR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1387e0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1387e4 eoreq r5, r11, r12, lsr #4 */

/* ── FUNC 0x1387e8 · F_FilenameName(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1387e8 push {r3, r4, r5, lr} */
/* @0x1387ec mov r1, #0 */
/* @0x1387f0 mov r4, r0 */
/* @0x1387f4 ldr r0, [sp, #0x10] */
/* @0x1387f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1387fc mov r3, #0 */
/* @0x138800 mov r2, #1 */
/* @0x138804 str r3, [r4] */
/* @0x138808 str r2, [r4, #0xc] */
/* @0x13880c cmp r0, r3 */
/* @0x138810 popeq {r3, r4, r5, pc} */
/* @0x138814 bl 0x214fe0 <_Z15ExtractFileNamePKc> */
/* @0x138818 mov r5, r0 */
/* @0x13881c mov r0, r4 */
/* @0x138820 mov r1, r5 */
/* @0x138824 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x138828 mov r0, r5 */
/* @0x13882c pop {r3, r4, r5, lr} */
/* @0x138830 b 0xcef90 <_Z6YYFreePKv> */

/* ── FUNC 0x138834 · F_FilenameDrive(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x138834 push {r3, r4, r5, lr} */
/* @0x138838 mov r1, #0 */
/* @0x13883c mov r4, r0 */
/* @0x138840 ldr r0, [sp, #0x10] */
/* @0x138844 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138848 mov r3, #0 */
/* @0x13884c mov r2, #1 */
/* @0x138850 str r3, [r4] */
/* @0x138854 str r2, [r4, #0xc] */
/* @0x138858 cmp r0, r3 */
/* @0x13885c popeq {r3, r4, r5, pc} */
/* @0x138860 bl 0x214fdc <_Z16ExtractFileDrivePKc> */
/* @0x138864 mov r5, r0 */
/* @0x138868 mov r0, r4 */
/* @0x13886c mov r1, r5 */
/* @0x138870 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x138874 mov r0, r5 */
/* @0x138878 pop {r3, r4, r5, lr} */
/* @0x13887c b 0xcef90 <_Z6YYFreePKv> */

/* ── FUNC 0x138880 · F_FilenameExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x138880 push {r3, r4, r5, lr} */
/* @0x138884 mov r1, #0 */
/* @0x138888 mov r4, r0 */
/* @0x13888c ldr r0, [sp, #0x10] */
/* @0x138890 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138894 mov r3, #0 */
/* @0x138898 mov r2, #1 */
/* @0x13889c str r3, [r4] */
/* @0x1388a0 str r2, [r4, #0xc] */
/* @0x1388a4 cmp r0, r3 */
/* @0x1388a8 popeq {r3, r4, r5, pc} */
/* @0x1388ac bl 0x215008 <_Z14ExtractFileExtPKc> */
/* @0x1388b0 mov r5, r0 */
/* @0x1388b4 mov r0, r4 */
/* @0x1388b8 mov r1, r5 */
/* @0x1388bc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1388c0 mov r0, r5 */
/* @0x1388c4 pop {r3, r4, r5, lr} */
/* @0x1388c8 b 0xcef90 <_Z6YYFreePKv> */

/* ── FUNC 0x1388cc · F_FilenameChangeExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=280 · insn=70 */
/* @0x1388cc push {r4, r5, r6, r7, r8, lr} */
/* @0x1388d0 mov r1, #0 */
/* @0x1388d4 ldr r6, [sp, #0x18] */
/* @0x1388d8 mov r5, #1 */
/* @0x1388dc str r1, [r0] */
/* @0x1388e0 str r5, [r0, #0xc] */
/* @0x1388e4 mov r0, r6 */
/* @0x1388e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1388ec mov r1, r5 */
/* @0x1388f0 mov r4, r0 */
/* @0x1388f4 mov r0, r6 */
/* @0x1388f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1388fc cmp r4, #0 */
/* @0x138900 mov r6, r0 */
/* @0x138904 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x138908 mov r0, r4 */
/* @0x13890c mov r1, #46 */
/* @0x138910 bl 0xb6868 <strrchr@plt> */
/* @0x138914 subs r7, r0, #0 */
/* @0x138918 beq 0x138964 <_Z19F_FilenameChangeExtR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x13891c mov r0, r6 */
/* @0x138920 rsb r7, r4, r7 */
/* @0x138924 bl 0xb6538 <strlen@plt> */
/* @0x138928 ldr r1, [pc, #0xa4] */
/* @0x13892c add r12, r7, #2 */
/* @0x138930 mov r3, r5 */
/* @0x138934 add r1, pc, r1 */
/* @0x138938 movw r2, #0x6a5 */
/* @0x13893c add r0, r12, r0 */
/* @0x138940 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x138944 mov r1, r4 */
/* @0x138948 mov r2, r7 */
/* @0x13894c mov r5, r0 */
/* @0x138950 bl 0xb6568 <strncpy@plt> */
/* @0x138954 mov r0, r5 */
/* @0x138958 mov r1, r6 */
/* @0x13895c pop {r4, r5, r6, r7, r8, lr} */
/* @0x138960 b 0xb6628 <strcat@plt> */
/* @0x138964 mov r0, r4 */
/* @0x138968 bl 0xb6538 <strlen@plt> */
/* @0x13896c mov r7, r0 */
/* @0x138970 mov r0, r6 */
/* @0x138974 bl 0xb6538 <strlen@plt> */
/* @0x138978 mov r3, r5 */
/* @0x13897c ldr r1, [pc, #0x54] */
/* @0x138980 movw r2, #0x6ab */
/* @0x138984 add r1, pc, r1 */
/* @0x138988 add r0, r7, r0 */
/* @0x13898c add r5, r0, #2 */
/* @0x138990 mov r0, r5 */
/* @0x138994 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x138998 ldrb r3, [r6] */
/* @0x13899c mov r1, r5 */
/* @0x1389a0 str r6, [sp, #0x18] */
/* @0x1389a4 cmp r3, #46 */
/* @0x1389a8 cmpne r3, #0 */
/* @0x1389ac mov r3, r4 */
/* @0x1389b0 beq 0x1389c4 <_Z19F_FilenameChangeExtR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1389b4 ldr r2, [pc, #0x20] */
/* @0x1389b8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1389bc add r2, pc, r2 */
/* @0x1389c0 b 0xb65c8 <snprintf@plt> */
/* @0x1389c4 ldr r2, [pc, #0x14] */
/* @0x1389c8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1389cc add r2, pc, r2 */
/* @0x1389d0 b 0xb65c8 <snprintf@plt> */
/* @0x1389d4 eoreq r7, r0, r12, lsl r7 */
/* @0x1389d8 eoreq r7, r0, r12, asr #13 */
/* @0x1389dc .word 0x002076f4 */
/* @0x1389e0 andseq r12, pc, r8, lsl #4 */

/* ── FUNC 0x1389e4 · F_ExecuteProgram(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x1389e4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1389e8 mov r1, #0 */
/* @0x1389ec ldr r5, [sp, #0x18] */
/* @0x1389f0 mov r4, r0 */
/* @0x1389f4 mov r0, r5 */
/* @0x1389f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1389fc mov r1, #1 */
/* @0x138a00 mov r6, r0 */
/* @0x138a04 mov r0, r5 */
/* @0x138a08 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138a0c mov r1, #2 */
/* @0x138a10 mov r8, r0 */
/* @0x138a14 mov r0, r5 */
/* @0x138a18 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x138a1c mov r12, #0 */
/* @0x138a20 str r12, [r4, #0xc] */
/* @0x138a24 str r12, [r4] */
/* @0x138a28 str r12, [r4, #0x4] */
/* @0x138a2c mov r7, r0 */
/* @0x138a30 bl 0x214e1c <_Z13GetCurrentDirv> */
/* @0x138a34 mov r1, r8 */
/* @0x138a38 mov r3, r7 */
/* @0x138a3c mov r5, r0 */
/* @0x138a40 mov r0, r6 */
/* @0x138a44 mov r2, r5 */
/* @0x138a48 bl 0x214de4 <_Z12File_ExecutePKcS0_S0_b> */
/* @0x138a4c cmp r0, #0 */
/* @0x138a50 bne 0x138a88 <_Z16F_ExecuteProgramR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x138a54 ldr r3, [pc, #0x38] */
/* @0x138a58 mov r2, #0 */
/* @0x138a5c str r0, [r4] */
/* @0x138a60 movt r2, #0xbff0 */
/* @0x138a64 ldr r3, [pc, r3] */
/* @0x138a68 str r2, [r4, #0x4] */
/* @0x138a6c ldr r1, [pc, #0x24] */
/* @0x138a70 mov r2, r6 */
/* @0x138a74 ldr r0, [r3] */
/* @0x138a78 add r1, pc, r1 */
/* @0x138a7c ldr r3, [r0] */
/* @0x138a80 ldr r3, [r3, #0xc] */
/* @0x138a84 blx r3 */
/* @0x138a88 mov r0, r5 */
/* @0x138a8c pop {r4, r5, r6, r7, r8, lr} */
/* @0x138a90 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138a94 .word 0x002b4cb0 */
/* @0x138a98 eoreq r7, r0, r0, asr #12 */

/* ── FUNC 0x138a9c · F_ExecuteShell(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x138a9c push {r3, r4, r5, r6, r7, lr} */
/* @0x138aa0 mov r1, #0 */
/* @0x138aa4 ldr r6, [sp, #0x18] */
/* @0x138aa8 mov r4, r0 */
/* @0x138aac mov r0, r6 */
/* @0x138ab0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138ab4 mov r1, #1 */
/* @0x138ab8 mov r5, r0 */
/* @0x138abc mov r0, r6 */
/* @0x138ac0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138ac4 cmp r5, #0 */
/* @0x138ac8 mov r3, #0 */
/* @0x138acc str r3, [r4, #0xc] */
/* @0x138ad0 str r3, [r4] */
/* @0x138ad4 str r3, [r4, #0x4] */
/* @0x138ad8 mov r7, r0 */
/* @0x138adc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x138ae0 bl 0x214e1c <_Z13GetCurrentDirv> */
/* @0x138ae4 mov r1, r7 */
/* @0x138ae8 mov r6, r0 */
/* @0x138aec mov r0, r5 */
/* @0x138af0 mov r2, r6 */
/* @0x138af4 bl 0x214ddc <_Z17File_ShellExecutePKcS0_S0_> */
/* @0x138af8 cmp r0, #0 */
/* @0x138afc beq 0x138b0c <_Z14F_ExecuteShellR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x138b00 mov r0, r6 */
/* @0x138b04 pop {r3, r4, r5, r6, r7, lr} */
/* @0x138b08 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138b0c ldr r3, [pc, #0x38] */
/* @0x138b10 mov r2, #0 */
/* @0x138b14 str r0, [r4] */
/* @0x138b18 movt r2, #0xbff0 */
/* @0x138b1c ldr r3, [pc, r3] */
/* @0x138b20 str r2, [r4, #0x4] */
/* @0x138b24 ldr r1, [pc, #0x24] */
/* @0x138b28 mov r2, r5 */
/* @0x138b2c ldr r0, [r3] */
/* @0x138b30 add r1, pc, r1 */
/* @0x138b34 ldr r3, [r0] */
/* @0x138b38 ldr r3, [r3, #0xc] */
/* @0x138b3c blx r3 */
/* @0x138b40 mov r0, r6 */
/* @0x138b44 pop {r3, r4, r5, r6, r7, lr} */
/* @0x138b48 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138b4c .word 0x002b4bf8 */
/* @0x138b50 eoreq r7, r0, r8, lsl #11 */

/* ── FUNC 0x138b54 · F_EnvironmentGetVariable(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x138b54 push {r3, r4, r5, lr} */
/* @0x138b58 mov r1, #0 */
/* @0x138b5c ldr r3, [sp, #0x10] */
/* @0x138b60 mov r2, #1 */
/* @0x138b64 str r1, [r0] */
/* @0x138b68 mov r4, r0 */
/* @0x138b6c str r2, [r0, #0xc] */
/* @0x138b70 mov r0, r3 */
/* @0x138b74 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138b78 cmp r0, #0 */
/* @0x138b7c popeq {r3, r4, r5, pc} */
/* @0x138b80 bl 0x215284 <_Z22EnvironmentGetVariablePc> */
/* @0x138b84 mov r5, r0 */
/* @0x138b88 mov r0, r4 */
/* @0x138b8c mov r1, r5 */
/* @0x138b90 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x138b94 mov r0, r5 */
/* @0x138b98 pop {r3, r4, r5, lr} */
/* @0x138b9c b 0xcef90 <_Z6YYFreePKv> */

/* ── FUNC 0x138ba0 · HttpRequestCallback(HTTP_REQ_CONTEXT*, void*, int*) · size=324 · insn=79 */
/* @0x138ba0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x138ba4 mov r4, r0 */
/* @0x138ba8 ldr r1, [pc, #0x118] */
/* @0x138bac sub sp, sp, #92 */
/* @0x138bb0 ldr r0, [r0, #0x3c] */
/* @0x138bb4 mov r3, #1 */
/* @0x138bb8 mov r6, r2 */
/* @0x138bbc add r1, pc, r1 */
/* @0x138bc0 add r0, r0, r3 */
/* @0x138bc4 movw r2, #0x8e2 */
/* @0x138bc8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x138bcc ldr r1, [r4, #0x34] */
/* @0x138bd0 ldr r2, [r4, #0x3c] */
/* @0x138bd4 ldr r8, [pc, #0xf0] */
/* @0x138bd8 ldr r7, [pc, #0xf0] */
/* @0x138bdc add r8, pc, r8 */
/* @0x138be0 add r7, pc, r7 */
/* @0x138be4 mov r5, r0 */
/* @0x138be8 bl 0xb65bc <memcpy@plt> */
/* @0x138bec vmov.f64 d5, #-1.000000e+00 */
/* @0x138bf0 ldr r2, [r4, #0x3c] */
/* @0x138bf4 mov r3, #0 */
/* @0x138bf8 vldr d7, [pc, #192] */
/* @0x138bfc ldr lr, [pc, #0xd0] */
/* @0x138c00 mov r0, #6 */
/* @0x138c04 strb r3, [r5, r2] */
/* @0x138c08 vldr s8, [r4, #40] */
/* @0x138c0c vstr d7, [sp, #8] */
/* @0x138c10 vldr s12, [r4, #44] */
/* @0x138c14 vstr d7, [sp, #24] */
/* @0x138c18 ldr r1, [r4, #0x3c] */
/* @0x138c1c ldr r2, [r4, #0x24] */
/* @0x138c20 add lr, pc, lr */
/* @0x138c24 cmp r1, r3 */
/* @0x138c28 ldr r9, [r4, #0x20] */
/* @0x138c2c ldr r1, [pc, #0xa4] */
/* @0x138c30 ldr r12, [pc, #0xa4] */
/* @0x138c34 vmovle.f64 d7, d5 */
/* @0x138c38 vstr d7, [sp, #72] */
/* @0x138c3c vmov s15, r2 */
/* @0x138c40 add r1, pc, r1 */
/* @0x138c44 str r1, [sp, #0x44] */
/* @0x138c48 add r12, pc, r12 */
/* @0x138c4c ldr r1, [pc, #0x8c] */
/* @0x138c50 vcvt.f64.s32 d4, s8 */
/* @0x138c54 str r3, [sp] */
/* @0x138c58 str r3, [sp, #0x30] */
/* @0x138c5c add r1, pc, r1 */
/* @0x138c60 str r3, [sp, #0x40] */
/* @0x138c64 str r3, [sp, #0x50] */
/* @0x138c68 str lr, [sp, #0x24] */
/* @0x138c6c str r12, [sp, #0x34] */
/* @0x138c70 str r5, [sp, #0x20] */
/* @0x138c74 vcvt.f64.s32 d6, s12 */
/* @0x138c78 vstr d4, [sp, #40] */
/* @0x138c7c str r9, [sp, #0x10] */
/* @0x138c80 str r8, [sp, #0x4] */
/* @0x138c84 str r7, [sp, #0x14] */
/* @0x138c88 vcvt.f64.s32 d7, s15 */
/* @0x138c8c vstr d6, [sp, #56] */
/* @0x138c90 vmov r2, r3, d7 */
/* @0x138c94 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x138c98 str r0, [r6] */
/* @0x138c9c mov r0, r5 */
/* @0x138ca0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138ca4 ldr r0, [r4, #0x1c] */
/* @0x138ca8 cmp r0, #0 */
/* @0x138cac beq 0x138cb4 <_Z19HttpRequestCallbackP16HTTP_REQ_CONTEXTPvPi+0x114> */
/* @0x138cb0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138cb4 mov r0, #62 */
/* @0x138cb8 add sp, sp, #92 */
/* @0x138cbc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x138cc8 mlaeq r0, r4, r4, r7 */
/* @0x138ccc .word 0x002074f0 */
/* @0x138cd0 andseq lr, pc, r8, ror r3 */
/* @0x138cd4 andseq r7, pc, r4, lsr #28 */
/* @0x138cd8 andseq r7, pc, r0, lsl lr */
/* @0x138cdc eoreq r7, r0, r8, lsl #9 */
/* @0x138ce0 andseq r7, pc, r4, ror #27 */

/* ── FUNC 0x138ce4 · anon_138ce4 · size=0 · insn=1 */
/* @0x138ce4 nop */

/* ── FUNC 0x138ce8 · HttpBufferRequestCallback(HTTP_REQ_CONTEXT*, void*, int*) · size=392 · insn=96 */
/* @0x138ce8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x138cec sub sp, sp, #120 */
/* @0x138cf0 ldr r6, [r0, #0x1c] */
/* @0x138cf4 mvn r3, #0 */
/* @0x138cf8 str r3, [sp] */
/* @0x138cfc mov r4, #0 */
/* @0x138d00 mov r5, r0 */
/* @0x138d04 ldr r1, [r0, #0x34] */
/* @0x138d08 ldr lr, [r6, #0x1c] */
/* @0x138d0c mov r12, #1 */
/* @0x138d10 mov r7, r2 */
/* @0x138d14 mov r3, r4 */
/* @0x138d18 ldr r2, [r5, #0x3c] */
/* @0x138d1c mov r0, r6 */
/* @0x138d20 str lr, [sp, #0x4] */
/* @0x138d24 str r12, [sp, #0x8] */
/* @0x138d28 str r4, [sp, #0xc] */
/* @0x138d2c str r4, [sp, #0x10] */
/* @0x138d30 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0x138d34 ldr r3, [r6] */
/* @0x138d38 mov r1, r4 */
/* @0x138d3c ldr r8, [pc, #0x10c] */
/* @0x138d40 ldr r3, [r3, #0x10] */
/* @0x138d44 add r8, pc, r8 */
/* @0x138d48 mov r2, r0 */
/* @0x138d4c mov r0, r6 */
/* @0x138d50 blx r3 */
/* @0x138d54 ldr r3, [r5, #0x3c] */
/* @0x138d58 vmov.f64 d5, #-1.000000e+00 */
/* @0x138d5c vldr s6, [r6, #28] */
/* @0x138d60 ldr r10, [r5, #0x2c] */
/* @0x138d64 cmp r3, r4 */
/* @0x138d68 vmov s9, r3 */
/* @0x138d6c ldr r2, [r5, #0x24] */
/* @0x138d70 vldr s8, [r5, #40] */
/* @0x138d74 vldr d7, [pc, #204] */
/* @0x138d78 vstr d7, [sp, #8] */
/* @0x138d7c ldr r9, [r5, #0x20] */
/* @0x138d80 ldr r1, [pc, #0xcc] */
/* @0x138d84 mov r0, #8 */
/* @0x138d88 ldr r6, [pc, #0xc8] */
/* @0x138d8c add r1, pc, r1 */
/* @0x138d90 ldr r5, [pc, #0xc4] */
/* @0x138d94 str r1, [sp, #0x54] */
/* @0x138d98 add r6, pc, r6 */
/* @0x138d9c ldr lr, [pc, #0xbc] */
/* @0x138da0 add r5, pc, r5 */
/* @0x138da4 vcvt.f64.s32 d3, s6 */
/* @0x138da8 ldr r12, [pc, #0xb4] */
/* @0x138dac ldr r3, [pc, #0xb4] */
/* @0x138db0 add lr, pc, lr */
/* @0x138db4 ldr r1, [pc, #0xb0] */
/* @0x138db8 add r12, pc, r12 */
/* @0x138dbc str r4, [sp] */
/* @0x138dc0 add r3, pc, r3 */
/* @0x138dc4 str r4, [sp, #0x20] */
/* @0x138dc8 add r1, pc, r1 */
/* @0x138dcc str r3, [sp, #0x64] */
/* @0x138dd0 str r4, [sp, #0x30] */
/* @0x138dd4 vcvt.f64.s32 d6, s9 */
/* @0x138dd8 vstr d3, [sp, #24] */
/* @0x138ddc vmov s7, r10 */
/* @0x138de0 str r4, [sp, #0x40] */
/* @0x138de4 str r4, [sp, #0x50] */
/* @0x138de8 str r4, [sp, #0x60] */
/* @0x138dec str r4, [sp, #0x70] */
/* @0x138df0 str r9, [sp, #0x10] */
/* @0x138df4 str r8, [sp, #0x4] */
/* @0x138df8 vmovle.f64 d7, d5 */
/* @0x138dfc vstr d7, [sp, #104] */
/* @0x138e00 vmov s15, r2 */
/* @0x138e04 vstr d6, [sp, #72] */
/* @0x138e08 vstr d6, [sp, #88] */
/* @0x138e0c str r6, [sp, #0x14] */
/* @0x138e10 str r5, [sp, #0x24] */
/* @0x138e14 vcvt.f64.s32 d4, s8 */
/* @0x138e18 str lr, [sp, #0x34] */
/* @0x138e1c str r12, [sp, #0x44] */
/* @0x138e20 vcvt.f64.s32 d6, s7 */
/* @0x138e24 vstr d4, [sp, #40] */
/* @0x138e28 vcvt.f64.s32 d7, s15 */
/* @0x138e2c vstr d6, [sp, #56] */
/* @0x138e30 vmov r2, r3, d7 */
/* @0x138e34 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x138e38 str r0, [r7] */
/* @0x138e3c mov r0, #62 */
/* @0x138e40 add sp, sp, #120 */
/* @0x138e44 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x138e50 eoreq r7, r0, r8, lsl #7 */
/* @0x138e54 eoreq r7, r0, r8, ror #6 */
/* @0x138e58 andseq lr, pc, r0, asr #3 */
/* @0x138e5c andseq r7, pc, r4, lsr #25 */
/* @0x138e60 eoreq r7, r0, r0, lsr #6 */
/* @0x138e64 eoreq r7, r0, r12, lsr #6 */
/* @0x138e68 mulseq pc, r0, r12 */
/* @0x138e6c andseq r7, pc, r8, ror r12 */

/* ── FUNC 0x138e70 · HttpGetFileCallback(HTTP_REQ_CONTEXT*, void*, int*) · size=272 · insn=66 */
/* @0x138e70 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x138e74 mov r4, r0 */
/* @0x138e78 sub sp, sp, #92 */
/* @0x138e7c mov r5, r2 */
/* @0x138e80 ldr r1, [r4, #0x34] */
/* @0x138e84 ldr r2, [r4, #0x3c] */
/* @0x138e88 ldr r0, [r0, #0x1c] */
/* @0x138e8c bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0x138e90 vldr s10, [r4, #44] */
/* @0x138e94 vcvt.f64.s32 d5, s10 */
/* @0x138e98 vldr s8, [r4, #40] */
/* @0x138e9c vldr d7, [pc, #188] */
/* @0x138ea0 vstr d7, [sp, #8] */
/* @0x138ea4 ldr r2, [r4, #0x24] */
/* @0x138ea8 vstr d7, [sp, #24] */
/* @0x138eac ldr r9, [r4, #0x20] */
/* @0x138eb0 mov r3, #0 */
/* @0x138eb4 ldr r8, [r4, #0x1c] */
/* @0x138eb8 ldr r1, [pc, #0xa8] */
/* @0x138ebc ldr r7, [pc, #0xa8] */
/* @0x138ec0 vmov.f64 d6, #-1.000000e+00 */
/* @0x138ec4 vstr d5, [sp, #56] */
/* @0x138ec8 vmov s11, r2 */
/* @0x138ecc add r1, pc, r1 */
/* @0x138ed0 ldr r6, [pc, #0x98] */
/* @0x138ed4 add r7, pc, r7 */
/* @0x138ed8 str r1, [sp, #0x44] */
/* @0x138edc ldr lr, [pc, #0x90] */
/* @0x138ee0 add r6, pc, r6 */
/* @0x138ee4 ldr r12, [pc, #0x8c] */
/* @0x138ee8 ldr r1, [pc, #0x8c] */
/* @0x138eec add lr, pc, lr */
/* @0x138ef0 add r12, pc, r12 */
/* @0x138ef4 str lr, [sp, #0x24] */
/* @0x138ef8 str r12, [sp, #0x34] */
/* @0x138efc add r1, pc, r1 */
/* @0x138f00 str r3, [sp] */
/* @0x138f04 vcvt.f64.s32 d4, s8 */
/* @0x138f08 str r3, [sp, #0x30] */
/* @0x138f0c str r3, [sp, #0x40] */
/* @0x138f10 str r3, [sp, #0x50] */
/* @0x138f14 str r9, [sp, #0x10] */
/* @0x138f18 str r8, [sp, #0x20] */
/* @0x138f1c str r7, [sp, #0x4] */
/* @0x138f20 str r6, [sp, #0x14] */
/* @0x138f24 vcvt.f64.s32 d5, s11 */
/* @0x138f28 vstr d4, [sp, #40] */
/* @0x138f2c cmp r0, #0 */
/* @0x138f30 vmov r2, r3, d5 */
/* @0x138f34 mov r0, #6 */
/* @0x138f38 vmoveq.f64 d7, d6 */
/* @0x138f3c vstr d7, [sp, #72] */
/* @0x138f40 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x138f44 str r0, [r5] */
/* @0x138f48 ldr r0, [r4, #0x1c] */
/* @0x138f4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x138f50 mov r0, #62 */
/* @0x138f54 add sp, sp, #92 */
/* @0x138f58 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x138f5c nop */
/* @0x138f68 andseq r7, pc, r4, lsl #23 */
/* @0x138f6c .word 0x002071f8 */
/* @0x138f70 andseq lr, pc, r8, ror r0 */
/* @0x138f74 andseq r7, pc, r8, asr r11 */
/* @0x138f78 eoreq r7, r0, r0, ror #3 */
/* @0x138f7c andseq r7, pc, r4, asr #22 */

/* ── FUNC 0x138f80 · F_HttpPostString(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x138f80 push {r4, r5, r6, r7, lr} */
/* @0x138f84 sub sp, sp, #12 */
/* @0x138f88 ldr r3, [pc, #0xd0] */
/* @0x138f8c mov r4, r0 */
/* @0x138f90 ldr r6, [sp, #0x20] */
/* @0x138f94 mov r1, #0 */
/* @0x138f98 ldr r3, [pc, r3] */
/* @0x138f9c mov r7, #1 */
/* @0x138fa0 mov r0, r6 */
/* @0x138fa4 strb r7, [r3] */
/* @0x138fa8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138fac mov r1, r7 */
/* @0x138fb0 mov r5, r0 */
/* @0x138fb4 mov r0, r6 */
/* @0x138fb8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x138fbc cmp r5, #0 */
/* @0x138fc0 mov r2, #0 */
/* @0x138fc4 mov r3, r2 */
/* @0x138fc8 movt r2, #0xbff0 */
/* @0x138fcc str r3, [r4, #0xc] */
/* @0x138fd0 str r2, [r4, #0x4] */
/* @0x138fd4 str r3, [r4] */
/* @0x138fd8 mov r6, r0 */
/* @0x138fdc beq 0x139058 <_Z16F_HttpPostStringR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x138fe0 ldr r0, [pc, #0x7c] */
/* @0x138fe4 mov r1, r5 */
/* @0x138fe8 mov r2, #7 */
/* @0x138fec add r0, pc, r0 */
/* @0x138ff0 bl 0xb65e0 <strncmp@plt> */
/* @0x138ff4 cmp r0, #0 */
/* @0x138ff8 beq 0x139018 <_Z16F_HttpPostStringR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x138ffc ldr r0, [pc, #0x64] */
/* @0x139000 mov r1, r5 */
/* @0x139004 mov r2, #8 */
/* @0x139008 add r0, pc, r0 */
/* @0x13900c bl 0xb65e0 <strncmp@plt> */
/* @0x139010 cmp r0, #0 */
/* @0x139014 bne 0x139058 <_Z16F_HttpPostStringR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x139018 ldr r3, [pc, #0x4c] */
/* @0x13901c mov r0, r6 */
/* @0x139020 ldr r3, [pc, r3] */
/* @0x139024 ldr r6, [r3] */
/* @0x139028 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x13902c ldr r2, [pc, #0x3c] */
/* @0x139030 mov r3, #0 */
/* @0x139034 str r3, [sp] */
/* @0x139038 ldr r2, [pc, r2] */
/* @0x13903c mov r1, r0 */
/* @0x139040 mov r0, r5 */
/* @0x139044 bl 0x18fd00 <_ZN8LoadSave9HTTP_PostEPKcS1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0x139048 vmov s15, r6 */
/* @0x13904c vcvt.f64.s32 d7, s15 */
/* @0x139050 vmov r2, r3, d7 */
/* @0x139054 stm r4, {r2, r3} */
/* @0x139058 add sp, sp, #12 */
/* @0x13905c pop {r4, r5, r6, r7, pc} */
/* @0x139060 .word 0x002b49bc */
/* @0x139064 ldrsheq r7, [pc], -r4 */
/* @0x139068 andseq r7, pc, r0, ror #21 */
/* @0x13906c eoreq r6, r11, r8, asr r2 */
/* @0x139070 eoreq r6, r11, r4, asr #4 */

/* ── FUNC 0x139074 · F_HttpGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x139074 ldr r3, [pc, #0xbc] */
/* @0x139078 mov r1, #0 */
/* @0x13907c push {r4, r5, lr} */
/* @0x139080 sub sp, sp, #12 */
/* @0x139084 ldr r3, [pc, r3] */
/* @0x139088 mov r4, r0 */
/* @0x13908c ldr r0, [sp, #0x18] */
/* @0x139090 mov r2, #1 */
/* @0x139094 strb r2, [r3] */
/* @0x139098 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13909c mov r2, #0 */
/* @0x1390a0 mov r3, r2 */
/* @0x1390a4 movt r2, #0xbff0 */
/* @0x1390a8 str r3, [r4, #0xc] */
/* @0x1390ac str r2, [r4, #0x4] */
/* @0x1390b0 str r3, [r4] */
/* @0x1390b4 subs r5, r0, #0 */
/* @0x1390b8 beq 0x139130 <_Z9F_HttpGetR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1390bc ldr r0, [pc, #0x78] */
/* @0x1390c0 mov r1, r5 */
/* @0x1390c4 mov r2, #7 */
/* @0x1390c8 add r0, pc, r0 */
/* @0x1390cc bl 0xb65e0 <strncmp@plt> */
/* @0x1390d0 cmp r0, #0 */
/* @0x1390d4 beq 0x1390f4 <_Z9F_HttpGetR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1390d8 ldr r0, [pc, #0x60] */
/* @0x1390dc mov r1, r5 */
/* @0x1390e0 mov r2, #8 */
/* @0x1390e4 add r0, pc, r0 */
/* @0x1390e8 bl 0xb65e0 <strncmp@plt> */
/* @0x1390ec cmp r0, #0 */
/* @0x1390f0 bne 0x139130 <_Z9F_HttpGetR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1390f4 ldr r12, [pc, #0x48] */
/* @0x1390f8 mov r0, r5 */
/* @0x1390fc ldr r2, [pc, #0x44] */
/* @0x139100 mov lr, #0 */
/* @0x139104 ldr r12, [pc, r12] */
/* @0x139108 mov r3, lr */
/* @0x13910c ldr r2, [pc, r2] */
/* @0x139110 mvn r1, #0 */
/* @0x139114 ldr r5, [r12] */
/* @0x139118 str lr, [sp] */
/* @0x13911c bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0x139120 vmov s15, r5 */
/* @0x139124 vcvt.f64.s32 d7, s15 */
/* @0x139128 vmov r2, r3, d7 */
/* @0x13912c stm r4, {r2, r3} */
/* @0x139130 add sp, sp, #12 */
/* @0x139134 pop {r4, r5, pc} */
/* @0x139138 .word 0x002b48d0 */
/* @0x13913c andseq r7, pc, r8, lsl r10 */
/* @0x139140 andseq r7, pc, r4, lsl #20 */
/* @0x139144 eoreq r6, r11, r4, ror r1 */
/* @0x139148 eoreq r6, r11, r0, ror r1 */

/* ── FUNC 0x13914c · F_ZipUnzip(RValue&, CInstance*, CInstance*, int, RValue*) · size=304 · insn=76 */
/* @0x13914c push {r4, r5, r6, r7, r8, lr} */
/* @0x139150 sub sp, sp, #2064 */
/* @0x139154 ldr r5, [pc, #0x118] */
/* @0x139158 mov r4, r0 */
/* @0x13915c ldr r7, [sp, #0x828] */
/* @0x139160 mov r1, #0 */
/* @0x139164 ldr r5, [pc, r5] */
/* @0x139168 ldr r3, [r5] */
/* @0x13916c mov r0, r7 */
/* @0x139170 str r3, [sp, #0x80c] */
/* @0x139174 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x139178 mov r1, #1 */
/* @0x13917c mov r6, r0 */
/* @0x139180 mov r0, r7 */
/* @0x139184 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x139188 mov r3, #0 */
/* @0x13918c str r3, [r4, #0xc] */
/* @0x139190 str r3, [r4] */
/* @0x139194 str r3, [r4, #0x4] */
/* @0x139198 mov r8, r0 */
/* @0x13919c mov r0, r6 */
/* @0x1391a0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1391a4 cmp r0, #0 */
/* @0x1391a8 bne 0x139258 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x1391ac mov r0, r6 */
/* @0x1391b0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1391b4 cmp r0, #0 */
/* @0x1391b8 bne 0x139240 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1391bc ldr r3, [pc, #0xb4] */
/* @0x1391c0 add r7, sp, #12 */
/* @0x1391c4 movw r12, #0x6261 */
/* @0x1391c8 mov r2, r6 */
/* @0x1391cc ldr r3, [pc, r3] */
/* @0x1391d0 movt r12, #0x2b */
/* @0x1391d4 mov r0, r7 */
/* @0x1391d8 mov r1, #1024 */
/* @0x1391dc str r12, [r3] */
/* @0x1391e0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1391e4 add r6, sp, #1040 */
/* @0x1391e8 mov r2, r8 */
/* @0x1391ec sub r6, r6, #4 */
/* @0x1391f0 mov r1, #1024 */
/* @0x1391f4 mov r0, r6 */
/* @0x1391f8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1391fc mov r3, #0 */
/* @0x139200 mov r2, r3 */
/* @0x139204 mov r1, r6 */
/* @0x139208 str r3, [sp] */
/* @0x13920c mov r0, r7 */
/* @0x139210 bl 0x1ca040 <_Z13Command_UnzipPKcS0_iiPc> */
/* @0x139214 ldr r1, [sp, #0x80c] */
/* @0x139218 vmov s15, r0 */
/* @0x13921c vcvt.f64.s32 d7, s15 */
/* @0x139220 vmov r2, r3, d7 */
/* @0x139224 vstr s14, [r4] */
/* @0x139228 ldr r2, [r5] */
/* @0x13922c cmp r1, r2 */
/* @0x139230 str r3, [r4, #0x4] */
/* @0x139234 bne 0x139270 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x139238 add sp, sp, #2064 */
/* @0x13923c pop {r4, r5, r6, r7, r8, pc} */
/* @0x139240 add r7, sp, #12 */
/* @0x139244 mov r2, r6 */
/* @0x139248 mov r1, #1024 */
/* @0x13924c mov r0, r7 */
/* @0x139250 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x139254 b 0x1391e4 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x139258 add r7, sp, #12 */
/* @0x13925c mov r2, r6 */
/* @0x139260 mov r1, #1024 */
/* @0x139264 mov r0, r7 */
/* @0x139268 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13926c b 0x1391e4 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x139270 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x139274 eoreq r4, r11, r12, ror #15 */
/* @0x139278 strhteq r6, [r11], -r4 */

/* ── FUNC 0x13927c · F_FileFindNext(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x13927c ldr r3, [pc, #0x48] */
/* @0x139280 mov r1, #0 */
/* @0x139284 str r1, [r0] */
/* @0x139288 mov r1, #1 */
/* @0x13928c ldr r3, [pc, r3] */
/* @0x139290 str r1, [r0, #0xc] */
/* @0x139294 ldrb r3, [r3] */
/* @0x139298 cmp r3, #0 */
/* @0x13929c bxeq lr */
/* @0x1392a0 ldr r3, [pc, #0x28] */
/* @0x1392a4 ldr r3, [pc, r3] */
/* @0x1392a8 ldr r2, [r3] */
/* @0x1392ac ldr r1, [r3, #0x4] */
/* @0x1392b0 add r2, r2, #1 */
/* @0x1392b4 str r2, [r3] */
/* @0x1392b8 cmp r2, r1 */
/* @0x1392bc bxge lr */
/* @0x1392c0 ldr r3, [r3, #0x8] */
/* @0x1392c4 ldr r1, [r3, r2, lsl #2] */
/* @0x1392c8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1392cc .word 0x002b5ff8 */
/* @0x1392d0 eoreq r5, r11, r4, ror #31 */

/* ── FUNC 0x1392d4 · F_FileBinClose(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1392d4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1392d8 mov r1, #0 */
/* @0x1392dc ldr r0, [sp, #0x20] */
/* @0x1392e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1392e4 sub r3, r0, #1 */
/* @0x1392e8 mov r4, r0 */
/* @0x1392ec cmp r3, #30 */
/* @0x1392f0 bhi 0x139340 <_Z14F_FileBinCloseR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1392f4 ldr r5, [pc, #0x58] */
/* @0x1392f8 ldr r5, [pc, r5] */
/* @0x1392fc ldrb r3, [r5, r0] */
/* @0x139300 cmp r3, #0 */
/* @0x139304 beq 0x139340 <_Z14F_FileBinCloseR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x139308 add r8, r0, r0, lsl #1 */
/* @0x13930c ldr r6, [pc, #0x44] */
/* @0x139310 mov r7, #0 */
/* @0x139314 ldr r6, [pc, r6] */
/* @0x139318 lsl r8, r8, #2 */
/* @0x13931c add r9, r8, r6 */
/* @0x139320 ldr r0, [r9, #0x8] */
/* @0x139324 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x139328 str r7, [r9, #0x8] */
/* @0x13932c ldr r0, [r6, r8] */
/* @0x139330 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x139334 str r7, [r8, r6] */
/* @0x139338 strb r7, [r5, r4] */
/* @0x13933c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x139340 ldr r0, [pc, #0x14] */
/* @0x139344 mov r1, #0 */
/* @0x139348 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x13934c add r0, pc, r0 */
/* @0x139350 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139354 mlaeq r11, r4, pc, r5 */
/* @0x139358 eoreq r5, r11, r12, ror pc */
/* @0x13935c .word 0x00206db8 */
