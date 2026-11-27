/* libyoyo.so 覆盖卡组 0169
 * 函数 0x1f4d10..0x1f6680，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f4d10 · FINALIZE_Variable_Main() · size=152 · insn=38 */
/* @0x1f4d10 push {r4, r5, r6, lr} */
/* @0x1f4d14 mov r4, #0 */
/* @0x1f4d18 ldr r5, [pc, #0x7c] */
/* @0x1f4d1c mov r6, r4 */
/* @0x1f4d20 ldr r5, [pc, r5] */
/* @0x1f4d24 ldr r0, [r5, r4] */
/* @0x1f4d28 cmp r0, #0 */
/* @0x1f4d2c beq 0x1f4d38 <_Z22FINALIZE_Variable_Mainv+0x28> */
/* @0x1f4d30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f4d34 str r6, [r5, r4] */
/* @0x1f4d38 add r4, r4, #16 */
/* @0x1f4d3c cmp r4, #8000 */
/* @0x1f4d40 bne 0x1f4d24 <_Z22FINALIZE_Variable_Mainv+0x14> */
/* @0x1f4d44 ldr r6, [pc, #0x54] */
/* @0x1f4d48 mov r0, r5 */
/* @0x1f4d4c mov r2, r4 */
/* @0x1f4d50 mov r1, #0 */
/* @0x1f4d54 bl 0xb65b0 <memset@plt> */
/* @0x1f4d58 ldr r6, [pc, r6] */
/* @0x1f4d5c ldr r3, [pc, #0x40] */
/* @0x1f4d60 mov r5, #0 */
/* @0x1f4d64 ldr r4, [r6, #0x4] */
/* @0x1f4d68 ldr r3, [pc, r3] */
/* @0x1f4d6c cmp r4, r5 */
/* @0x1f4d70 mov r0, r4 */
/* @0x1f4d74 str r5, [r3] */
/* @0x1f4d78 beq 0x1f4d90 <_Z22FINALIZE_Variable_Mainv+0x80> */
/* @0x1f4d7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f4d80 str r5, [r6, #0x4] */
/* @0x1f4d84 mov r3, #0 */
/* @0x1f4d88 str r3, [r6] */
/* @0x1f4d8c pop {r4, r5, r6, pc} */
/* @0x1f4d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f4d94 str r4, [r6, #0x4] */
/* @0x1f4d98 b 0x1f4d84 <_Z22FINALIZE_Variable_Mainv+0x74> */
/* @0x1f4d9c andseq r8, pc, r8, lsl pc */
/* @0x1f4da0 ldrsbeq r12, [pc], -r0 */
/* @0x1f4da4 andseq r8, pc, r12, asr #29 */

/* ── FUNC 0x1f4da8 · Variable_BuiltIn_Add(char const*, bool (*)(CInstance*, int, RValue*), bool (*)(CInstance*, int, RValue*), bool) · size=680 · insn=170 */
/* @0x1f4da8 ldr r3, [pc, #0x28c] */
/* @0x1f4dac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f4db0 ldr r3, [pc, r3] */
/* @0x1f4db4 sub sp, sp, #12 */
/* @0x1f4db8 mov r6, r0 */
/* @0x1f4dbc mov r5, r1 */
/* @0x1f4dc0 mov r9, r2 */
/* @0x1f4dc4 str r3, [sp, #0x4] */
/* @0x1f4dc8 ldr r3, [r3] */
/* @0x1f4dcc cmp r3, #500 */
/* @0x1f4dd0 beq 0x1f5024 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x27c> */
/* @0x1f4dd4 ldr r4, [pc, #0x264] */
/* @0x1f4dd8 ldr r4, [pc, r4] */
/* @0x1f4ddc ldr r0, [r4, r3, lsl #4] */
/* @0x1f4de0 cmp r0, #0 */
/* @0x1f4de4 moveq r10, r3 */
/* @0x1f4de8 beq 0x1f4e04 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x5c> */
/* @0x1f4dec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f4df0 ldr r3, [sp, #0x4] */
/* @0x1f4df4 ldr r2, [r3] */
/* @0x1f4df8 mov r3, #0 */
/* @0x1f4dfc mov r10, r2 */
/* @0x1f4e00 str r3, [r4, r2, lsl #4] */
/* @0x1f4e04 mov r0, r6 */
/* @0x1f4e08 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1f4e0c ldr r3, [pc, #0x230] */
/* @0x1f4e10 ldr r2, [sp, #0x4] */
/* @0x1f4e14 adds r1, r9, #0 */
/* @0x1f4e18 ldr r3, [pc, r3] */
/* @0x1f4e1c movne r1, #1 */
/* @0x1f4e20 ldr r8, [r3] */
/* @0x1f4e24 ldr r7, [r2] */
/* @0x1f4e28 ldr r12, [r8, #0xc] */
/* @0x1f4e2c ldr r2, [r8, #0x4] */
/* @0x1f4e30 add r3, r4, r7, lsl #4 */
/* @0x1f4e34 cmp r2, r12 */
/* @0x1f4e38 str r0, [r4, r10, lsl #4] */
/* @0x1f4e3c strb r1, [r3, #0xc] */
/* @0x1f4e40 stmib r3, {r5, r9} */
/* @0x1f4e44 bgt 0x1f4f34 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x18c> */
/* @0x1f4e48 add r2, r2, #1 */
/* @0x1f4e4c mov r0, r6 */
/* @0x1f4e50 str r2, [r8, #0x4] */
/* @0x1f4e54 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f4e58 ldr r4, [r8, #0x8] */
/* @0x1f4e5c ldr r10, [r8, #0x10] */
/* @0x1f4e60 bic r0, r0, #-2147483648 */
/* @0x1f4e64 and r3, r0, r4 */
/* @0x1f4e68 add r2, r3, r3, lsl #1 */
/* @0x1f4e6c add r2, r10, r2, lsl #2 */
/* @0x1f4e70 ldr r1, [r2, #0x8] */
/* @0x1f4e74 cmp r1, #0 */
/* @0x1f4e78 ldrne r11, [r8] */
/* @0x1f4e7c movne r5, #0 */
/* @0x1f4e80 bne 0x1f4ec8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x120> */
/* @0x1f4e84 b 0x1f4f14 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x16c> */
/* @0x1f4e88 ldr r9, [r2] */
/* @0x1f4e8c ldr r5, [r2, #0x4] */
/* @0x1f4e90 str r0, [r2, #0x8] */
/* @0x1f4e94 mov r0, r1 */
/* @0x1f4e98 str r6, [r2] */
/* @0x1f4e9c mov r6, r9 */
/* @0x1f4ea0 str r7, [r2, #0x4] */
/* @0x1f4ea4 mov r7, r5 */
/* @0x1f4ea8 add r3, r3, #1 */
/* @0x1f4eac add r5, r12, #1 */
/* @0x1f4eb0 and r3, r3, r4 */
/* @0x1f4eb4 add r2, r3, r3, lsl #1 */
/* @0x1f4eb8 add r2, r10, r2, lsl #2 */
/* @0x1f4ebc ldr r1, [r2, #0x8] */
/* @0x1f4ec0 cmp r1, #0 */
/* @0x1f4ec4 beq 0x1f4f14 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x16c> */
/* @0x1f4ec8 add r12, r3, r11 */
/* @0x1f4ecc and r9, r1, r4 */
/* @0x1f4ed0 rsb r12, r9, r12 */
/* @0x1f4ed4 and r12, r12, r4 */
/* @0x1f4ed8 cmp r12, r5 */
/* @0x1f4edc blt 0x1f4e88 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0xe0> */
/* @0x1f4ee0 movne r12, r5 */
/* @0x1f4ee4 bne 0x1f4ea8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x100> */
/* @0x1f4ee8 cmp r1, r0 */
/* @0x1f4eec bne 0x1f4ea8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x100> */
/* @0x1f4ef0 ldr r5, [r2] */
/* @0x1f4ef4 cmp r6, r5 */
/* @0x1f4ef8 bne 0x1f4ea8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x100> */
/* @0x1f4efc ldr r3, [r8, #0x4] */
/* @0x1f4f00 stm r2, {r6, r7} */
/* @0x1f4f04 sub r3, r3, #1 */
/* @0x1f4f08 str r1, [r2, #0x8] */
/* @0x1f4f0c str r3, [r8, #0x4] */
/* @0x1f4f10 b 0x1f4f1c <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x174> */
/* @0x1f4f14 stm r2, {r6, r7} */
/* @0x1f4f18 str r0, [r2, #0x8] */
/* @0x1f4f1c ldr r2, [sp, #0x4] */
/* @0x1f4f20 ldr r3, [r2] */
/* @0x1f4f24 add r3, r3, #1 */
/* @0x1f4f28 str r3, [r2] */
/* @0x1f4f2c add sp, sp, #12 */
/* @0x1f4f30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4f34 ldr r10, [r8] */
/* @0x1f4f38 mov r3, #1 */
/* @0x1f4f3c ldr r1, [pc, #0x104] */
/* @0x1f4f40 mov r2, #70 */
/* @0x1f4f44 ldr r9, [r8, #0x10] */
/* @0x1f4f48 lsl r0, r10, r3 */
/* @0x1f4f4c add r1, pc, r1 */
/* @0x1f4f50 add r4, r0, r10, lsl #2 */
/* @0x1f4f54 str r0, [r8] */
/* @0x1f4f58 sub r0, r0, #1 */
/* @0x1f4f5c str r0, [r8, #0x8] */
/* @0x1f4f60 lsl r4, r4, #2 */
/* @0x1f4f64 mov r0, r4 */
/* @0x1f4f68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f4f6c mov r2, r4 */
/* @0x1f4f70 mov r1, #0 */
/* @0x1f4f74 str r0, [r8, #0x10] */
/* @0x1f4f78 bl 0xb65b0 <memset@plt> */
/* @0x1f4f7c ldr r2, [r8] */
/* @0x1f4f80 vldr s15, [pc, #176] */
/* @0x1f4f84 mov r1, #0 */
/* @0x1f4f88 cmp r2, r1 */
/* @0x1f4f8c str r1, [r8, #0x4] */
/* @0x1f4f90 vmov s13, r2 */
/* @0x1f4f94 vcvt.f32.s32 s14, s13 */
/* @0x1f4f98 vmul.f32 s15, s14, s15 */
/* @0x1f4f9c vcvt.s32.f32 s15, s15 */
/* @0x1f4fa0 vstr s15, [r8, #12] */
/* @0x1f4fa4 ble 0x1f4fc4 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x21c> */
/* @0x1f4fa8 add r2, r2, r2, lsl #1 */
/* @0x1f4fac ldr r3, [r8, #0x10] */
/* @0x1f4fb0 add r2, r3, r2, lsl #2 */
/* @0x1f4fb4 str r1, [r3, #0x8] */
/* @0x1f4fb8 add r3, r3, #12 */
/* @0x1f4fbc cmp r3, r2 */
/* @0x1f4fc0 bne 0x1f4fb4 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x20c> */
/* @0x1f4fc4 cmp r10, #0 */
/* @0x1f4fc8 movgt r4, r9 */
/* @0x1f4fcc movgt r5, #0 */
/* @0x1f4fd0 ble 0x1f4ffc <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x254> */
/* @0x1f4fd4 ldr r3, [r4, #0x8] */
/* @0x1f4fd8 mov r0, r8 */
/* @0x1f4fdc add r5, r5, #1 */
/* @0x1f4fe0 cmp r3, #0 */
/* @0x1f4fe4 ble 0x1f4ff0 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x248> */
/* @0x1f4fe8 ldm r4, {r1, r2} */
/* @0x1f4fec bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1f4ff0 cmp r5, r10 */
/* @0x1f4ff4 add r4, r4, #12 */
/* @0x1f4ff8 bne 0x1f4fd4 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0x22c> */
/* @0x1f4ffc mov r0, r9 */
/* @0x1f5000 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f5004 vldr s13, [r8] */
/* @0x1f5008 vcvt.f32.s32 s14, s13 */
/* @0x1f500c vldr s15, [pc, #36] */
/* @0x1f5010 ldr r2, [r8, #0x4] */
/* @0x1f5014 vmul.f32 s15, s14, s15 */
/* @0x1f5018 vcvt.s32.f32 s15, s15 */
/* @0x1f501c vstr s15, [r8, #12] */
/* @0x1f5020 b 0x1f4e48 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b+0xa0> */
/* @0x1f5024 ldr r0, [pc, #0x20] */
/* @0x1f5028 add r0, pc, r0 */
/* @0x1f502c add sp, sp, #12 */
/* @0x1f5030 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f5034 b 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1f5038 svclo #0x19999a */
/* @0x1f503c andseq r8, pc, r4, lsl #29 */
/* @0x1f5040 andseq r8, pc, r0, ror #28 */
/* @0x1f5044 andseq r12, pc, r4, lsl r0 */
/* @0x1f5048 andseq r12, r3, r4, ror #1 */
/* @0x1f504c andseq sp, r5, r4, lsr #16 */

/* ── FUNC 0x1f5050 · CVariableList::const_iterator::operator++() · size=84 · insn=21 */
/* @0x1f5050 ldr r3, [r0] */
/* @0x1f5054 cmp r3, #0 */
/* @0x1f5058 ldrne r3, [r3] */
/* @0x1f505c strne r3, [r0] */
/* @0x1f5060 cmp r3, #0 */
/* @0x1f5064 bxne lr */
/* @0x1f5068 ldr r1, [r0, #0x8] */
/* @0x1f506c b 0x1f507c <_ZN13CVariableList14const_iteratorppEv+0x2c> */
/* @0x1f5070 cmp r1, r2 */
/* @0x1f5074 str r2, [r0, #0x4] */
/* @0x1f5078 bne 0x1f5090 <_ZN13CVariableList14const_iteratorppEv+0x40> */
/* @0x1f507c ldr r3, [r0, #0x4] */
/* @0x1f5080 cmp r3, r1 */
/* @0x1f5084 add r2, r3, #4 */
/* @0x1f5088 bne 0x1f5070 <_ZN13CVariableList14const_iteratorppEv+0x20> */
/* @0x1f508c bx lr */
/* @0x1f5090 ldr r3, [r3, #0x4] */
/* @0x1f5094 cmp r3, #0 */
/* @0x1f5098 str r3, [r0] */
/* @0x1f509c beq 0x1f5068 <_ZN13CVariableList14const_iteratorppEv+0x18> */
/* @0x1f50a0 bx lr */

/* ── FUNC 0x1f50a4 · RVariable::RVariable(int) · size=40 · insn=10 */
/* @0x1f50a4 mov r2, #0 */
/* @0x1f50a8 mov r12, #7 */
/* @0x1f50ac str r1, [r0, #0x8] */
/* @0x1f50b0 str r12, [r0, #0x14] */
/* @0x1f50b4 str r2, [r0] */
/* @0x1f50b8 str r2, [r0, #0x4] */
/* @0x1f50bc str r2, [r0, #0x18] */
/* @0x1f50c0 str r2, [r0, #0x1c] */
/* @0x1f50c4 str r2, [r0, #0x24] */
/* @0x1f50c8 bx lr */

/* ── FUNC 0x1f50a4 · RVariable::RVariable(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f50cc · CVariableList::Alloc(int) · size=108 · insn=27 */
/* @0x1f50cc push {r3, r4, r5, lr} */
/* @0x1f50d0 mov r5, r0 */
/* @0x1f50d4 ldr r3, [pc, #0x58] */
/* @0x1f50d8 ldr r3, [pc, r3] */
/* @0x1f50dc ldr r4, [r3] */
/* @0x1f50e0 cmp r4, #0 */
/* @0x1f50e4 beq 0x1f511c <_ZN13CVariableList5AllocEi+0x50> */
/* @0x1f50e8 ldr r0, [r4, #0x4] */
/* @0x1f50ec mov r2, #0 */
/* @0x1f50f0 mov r1, #7 */
/* @0x1f50f4 str r5, [r4, #0x8] */
/* @0x1f50f8 str r2, [r4, #0x18] */
/* @0x1f50fc str r0, [r3] */
/* @0x1f5100 str r2, [r4, #0x1c] */
/* @0x1f5104 str r2, [r4, #0x24] */
/* @0x1f5108 str r1, [r4, #0x14] */
/* @0x1f510c and r5, r5, #3 */
/* @0x1f5110 mov r0, r4 */
/* @0x1f5114 str r5, [r4, #0x28] */
/* @0x1f5118 pop {r3, r4, r5, pc} */
/* @0x1f511c mov r0, #44 */
/* @0x1f5120 bl 0x27c524 <_Znwj> */
/* @0x1f5124 mov r1, r5 */
/* @0x1f5128 mov r4, r0 */
/* @0x1f512c bl 0x1f50a4 <_ZN9RVariableC2Ei> */
/* @0x1f5130 b 0x1f510c <_ZN13CVariableList5AllocEi+0x40> */
/* @0x1f5134 andseq r11, pc, r12, asr sp */

/* ── FUNC 0x1f5138 · RVariable::RVariable(char const*) · size=64 · insn=16 */
/* @0x1f5138 push {r3, r4, r5, lr} */
/* @0x1f513c mov r4, r0 */
/* @0x1f5140 mov r3, #0 */
/* @0x1f5144 mov r5, r1 */
/* @0x1f5148 str r3, [r4] */
/* @0x1f514c add r0, r0, #8 */
/* @0x1f5150 str r3, [r4, #0x4] */
/* @0x1f5154 str r3, [r4, #0x18] */
/* @0x1f5158 str r3, [r4, #0x1c] */
/* @0x1f515c str r3, [r4, #0x24] */
/* @0x1f5160 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1f5164 mov r0, r5 */
/* @0x1f5168 bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x1f516c str r0, [r4, #0x28] */
/* @0x1f5170 mov r0, r4 */
/* @0x1f5174 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1f5138 · RVariable::RVariable(char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f5178 · CVariableList::Alloc(char const*) · size=112 · insn=28 */
/* @0x1f5178 push {r3, r4, r5, lr} */
/* @0x1f517c mov r5, r0 */
/* @0x1f5180 ldr r3, [pc, #0x5c] */
/* @0x1f5184 ldr r3, [pc, r3] */
/* @0x1f5188 ldr r4, [r3] */
/* @0x1f518c cmp r4, #0 */
/* @0x1f5190 beq 0x1f51c8 <_ZN13CVariableList5AllocEPKc+0x50> */
/* @0x1f5194 ldr r2, [r4, #0x4] */
/* @0x1f5198 str r2, [r3] */
/* @0x1f519c bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x1f51a0 mov r3, #0 */
/* @0x1f51a4 mov r1, r5 */
/* @0x1f51a8 str r3, [r4, #0x18] */
/* @0x1f51ac str r3, [r4, #0x1c] */
/* @0x1f51b0 str r3, [r4, #0x24] */
/* @0x1f51b4 str r0, [r4, #0x28] */
/* @0x1f51b8 add r0, r4, #8 */
/* @0x1f51bc bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1f51c0 mov r0, r4 */
/* @0x1f51c4 pop {r3, r4, r5, pc} */
/* @0x1f51c8 mov r0, #44 */
/* @0x1f51cc bl 0x27c524 <_Znwj> */
/* @0x1f51d0 mov r1, r5 */
/* @0x1f51d4 mov r4, r0 */
/* @0x1f51d8 bl 0x1f5138 <_ZN9RVariableC2EPKc> */
/* @0x1f51dc mov r0, r4 */
/* @0x1f51e0 pop {r3, r4, r5, pc} */
/* @0x1f51e4 ldrheq r11, [pc], -r0 */

/* ── FUNC 0x1f51e8 · CVariableList::Add(RVariable*) · size=48 · insn=12 */
/* @0x1f51e8 ldr r3, [r1, #0x28] */
/* @0x1f51ec ldr r12, [r0, #0x14] */
/* @0x1f51f0 and r3, r3, #3 */
/* @0x1f51f4 add r3, r0, r3, lsl #2 */
/* @0x1f51f8 ldr r2, [r3, #0x4] */
/* @0x1f51fc stm r1, {r2, r12} */
/* @0x1f5200 str r1, [r3, #0x4] */
/* @0x1f5204 ldr r3, [r0, #0x18] */
/* @0x1f5208 str r1, [r0, #0x14] */
/* @0x1f520c add r3, r3, #1 */
/* @0x1f5210 str r3, [r0, #0x18] */
/* @0x1f5214 bx lr */

/* ── FUNC 0x1f5218 · CVariableList::Find(char const*) · size=132 · insn=33 */
/* @0x1f5218 push {r4, r5, r6, lr} */
/* @0x1f521c mov r4, r0 */
/* @0x1f5220 mov r0, r1 */
/* @0x1f5224 mov r6, r1 */
/* @0x1f5228 bl 0x27dfa8 <_Z14CalcCRC_stringPKc> */
/* @0x1f522c and r3, r0, #3 */
/* @0x1f5230 mov r5, r0 */
/* @0x1f5234 add r4, r4, r3, lsl #2 */
/* @0x1f5238 ldr r4, [r4, #0x4] */
/* @0x1f523c cmp r4, #0 */
/* @0x1f5240 bne 0x1f5254 <_ZN13CVariableList4FindEPKc+0x3c> */
/* @0x1f5244 b 0x1f5294 <_ZN13CVariableList4FindEPKc+0x7c> */
/* @0x1f5248 ldr r4, [r4] */
/* @0x1f524c cmp r4, #0 */
/* @0x1f5250 beq 0x1f5294 <_ZN13CVariableList4FindEPKc+0x7c> */
/* @0x1f5254 ldr r3, [r4, #0x28] */
/* @0x1f5258 cmp r3, r5 */
/* @0x1f525c bne 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30> */
/* @0x1f5260 ldr r3, [r4, #0x14] */
/* @0x1f5264 cmp r3, #1 */
/* @0x1f5268 bne 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30> */
/* @0x1f526c ldr r3, [r4, #0x8] */
/* @0x1f5270 mov r1, r6 */
/* @0x1f5274 cmp r3, #0 */
/* @0x1f5278 beq 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30> */
/* @0x1f527c ldr r0, [r3] */
/* @0x1f5280 cmp r0, #0 */
/* @0x1f5284 beq 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30> */
/* @0x1f5288 bl 0xb6574 <strcmp@plt> */
/* @0x1f528c cmp r0, #0 */
/* @0x1f5290 bne 0x1f5248 <_ZN13CVariableList4FindEPKc+0x30> */
/* @0x1f5294 mov r0, r4 */
/* @0x1f5298 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1f529c · CVariableList::Find(RValue const*) · size=128 · insn=32 */
/* @0x1f529c push {r4, r5, r6, lr} */
/* @0x1f52a0 mov r4, r0 */
/* @0x1f52a4 mov r0, r1 */
/* @0x1f52a8 mov r6, r1 */
/* @0x1f52ac bl 0xcee94 <_Z11HASH_RValuePK6RValue> */
/* @0x1f52b0 and r3, r0, #3 */
/* @0x1f52b4 mov r5, r0 */
/* @0x1f52b8 add r4, r4, r3, lsl #2 */
/* @0x1f52bc ldr r4, [r4, #0x4] */
/* @0x1f52c0 cmp r4, #0 */
/* @0x1f52c4 bne 0x1f52d8 <_ZN13CVariableList4FindEPK6RValue+0x3c> */
/* @0x1f52c8 b 0x1f530c <_ZN13CVariableList4FindEPK6RValue+0x70> */
/* @0x1f52cc ldr r4, [r4] */
/* @0x1f52d0 cmp r4, #0 */
/* @0x1f52d4 beq 0x1f530c <_ZN13CVariableList4FindEPK6RValue+0x70> */
/* @0x1f52d8 ldr r3, [r4, #0x28] */
/* @0x1f52dc cmp r3, r5 */
/* @0x1f52e0 bne 0x1f52cc <_ZN13CVariableList4FindEPK6RValue+0x30> */
/* @0x1f52e4 ldr r3, [pc, #0x2c] */
/* @0x1f52e8 add r0, r4, #8 */
/* @0x1f52ec mov r1, r6 */
/* @0x1f52f0 ldr r3, [pc, r3] */
/* @0x1f52f4 ldrd r2, r3, [r3] */
/* @0x1f52f8 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x1f52fc cmp r0, #0 */
/* @0x1f5300 bne 0x1f52cc <_ZN13CVariableList4FindEPK6RValue+0x30> */
/* @0x1f5304 mov r0, r4 */
/* @0x1f5308 pop {r4, r5, r6, pc} */
/* @0x1f530c mov r4, #0 */
/* @0x1f5310 mov r0, r4 */
/* @0x1f5314 pop {r4, r5, r6, pc} */
/* @0x1f5318 andseq r8, pc, r8, lsr #20 */

/* ── FUNC 0x1f531c · CVariableList::Find(int) · size=68 · insn=17 */
/* @0x1f531c and r3, r1, #3 */
/* @0x1f5320 add r0, r0, r3, lsl #2 */
/* @0x1f5324 ldr r0, [r0, #0x4] */
/* @0x1f5328 cmp r0, #0 */
/* @0x1f532c bxeq lr */
/* @0x1f5330 ldr r3, [r0, #0x8] */
/* @0x1f5334 cmp r3, r1 */
/* @0x1f5338 bne 0x1f534c <_ZN13CVariableList4FindEi+0x30> */
/* @0x1f533c b 0x1f535c <_ZN13CVariableList4FindEi+0x40> */
/* @0x1f5340 ldr r3, [r0, #0x8] */
/* @0x1f5344 cmp r3, r1 */
/* @0x1f5348 bxeq lr */
/* @0x1f534c ldr r0, [r0] */
/* @0x1f5350 cmp r0, #0 */
/* @0x1f5354 bne 0x1f5340 <_ZN13CVariableList4FindEi+0x24> */
/* @0x1f5358 bx lr */
/* @0x1f535c bx lr */

/* ── FUNC 0x1f5360 · CVariableList::Exists(int) · size=60 · insn=15 */
/* @0x1f5360 and r3, r1, #3 */
/* @0x1f5364 add r0, r0, r3, lsl #2 */
/* @0x1f5368 ldr r0, [r0, #0x4] */
/* @0x1f536c cmp r0, #0 */
/* @0x1f5370 bne 0x1f5384 <_ZN13CVariableList6ExistsEi+0x24> */
/* @0x1f5374 bx lr */
/* @0x1f5378 ldr r0, [r0] */
/* @0x1f537c cmp r0, #0 */
/* @0x1f5380 beq 0x1f5398 <_ZN13CVariableList6ExistsEi+0x38> */
/* @0x1f5384 ldr r3, [r0, #0x8] */
/* @0x1f5388 cmp r3, r1 */
/* @0x1f538c bne 0x1f5378 <_ZN13CVariableList6ExistsEi+0x18> */
/* @0x1f5390 mov r0, #1 */
/* @0x1f5394 bx lr */
/* @0x1f5398 bx lr */

/* ── FUNC 0x1f539c · CVariableList::SetVar(int, int, RValue*) · size=140 · insn=35 */
/* @0x1f539c push {r3, r4, r5, r6, r7, lr} */
/* @0x1f53a0 and r4, r1, #3 */
/* @0x1f53a4 ldr r12, [pc, #0x78] */
/* @0x1f53a8 mov r7, r3 */
/* @0x1f53ac add r4, r0, r4, lsl #2 */
/* @0x1f53b0 mov r3, #0 */
/* @0x1f53b4 ldr r12, [pc, r12] */
/* @0x1f53b8 mov r5, r0 */
/* @0x1f53bc ldr r4, [r4, #0x4] */
/* @0x1f53c0 mov r6, r2 */
/* @0x1f53c4 strb r3, [r12] */
/* @0x1f53c8 cmp r4, r3 */
/* @0x1f53cc beq 0x1f53f8 <_ZN13CVariableList6SetVarEiiP6RValue+0x5c> */
/* @0x1f53d0 ldr r3, [r4, #0x8] */
/* @0x1f53d4 cmp r3, r1 */
/* @0x1f53d8 bne 0x1f53ec <_ZN13CVariableList6SetVarEiiP6RValue+0x50> */
/* @0x1f53dc b 0x1f5410 <_ZN13CVariableList6SetVarEiiP6RValue+0x74> */
/* @0x1f53e0 ldr r12, [r4, #0x8] */
/* @0x1f53e4 cmp r12, r1 */
/* @0x1f53e8 beq 0x1f5410 <_ZN13CVariableList6SetVarEiiP6RValue+0x74> */
/* @0x1f53ec ldr r4, [r4] */
/* @0x1f53f0 cmp r4, #0 */
/* @0x1f53f4 bne 0x1f53e0 <_ZN13CVariableList6SetVarEiiP6RValue+0x44> */
/* @0x1f53f8 mov r0, r1 */
/* @0x1f53fc bl 0x1f50cc <_ZN13CVariableList5AllocEi> */
/* @0x1f5400 mov r4, r0 */
/* @0x1f5404 mov r0, r5 */
/* @0x1f5408 mov r1, r4 */
/* @0x1f540c bl 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable> */
/* @0x1f5410 add r0, r4, #24 */
/* @0x1f5414 mov r1, r7 */
/* @0x1f5418 mov r2, r6 */
/* @0x1f541c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1f5420 b 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f5424 andseq r8, pc, r0, asr #15 */

/* ── FUNC 0x1f5428 · CVariableList::GetVar(int, int, RValue*) · size=204 · insn=51 */
/* @0x1f5428 and r12, r1, #3 */
/* @0x1f542c push {r4, r5, r6} */
/* @0x1f5430 add r0, r0, r12, lsl #2 */
/* @0x1f5434 ldr r4, [pc, #0xac] */
/* @0x1f5438 mov r6, #0 */
/* @0x1f543c ldr r5, [pc, #0xa8] */
/* @0x1f5440 ldr r12, [r0, #0x4] */
/* @0x1f5444 ldr r4, [pc, r4] */
/* @0x1f5448 ldr r5, [pc, r5] */
/* @0x1f544c cmp r12, r6 */
/* @0x1f5450 strb r6, [r4] */
/* @0x1f5454 strb r6, [r5] */
/* @0x1f5458 beq 0x1f5484 <_ZN13CVariableList6GetVarEiiP6RValue+0x5c> */
/* @0x1f545c ldr r0, [r12, #0x8] */
/* @0x1f5460 cmp r0, r1 */
/* @0x1f5464 bne 0x1f5478 <_ZN13CVariableList6GetVarEiiP6RValue+0x50> */
/* @0x1f5468 b 0x1f54c0 <_ZN13CVariableList6GetVarEiiP6RValue+0x98> */
/* @0x1f546c ldr r4, [r12, #0x8] */
/* @0x1f5470 cmp r4, r1 */
/* @0x1f5474 beq 0x1f54c0 <_ZN13CVariableList6GetVarEiiP6RValue+0x98> */
/* @0x1f5478 ldr r12, [r12] */
/* @0x1f547c cmp r12, #0 */
/* @0x1f5480 bne 0x1f546c <_ZN13CVariableList6GetVarEiiP6RValue+0x44> */
/* @0x1f5484 ldr r2, [pc, #0x64] */
/* @0x1f5488 ldr r2, [pc, r2] */
/* @0x1f548c ldrb r2, [r2] */
/* @0x1f5490 cmp r2, #0 */
/* @0x1f5494 beq 0x1f54d0 <_ZN13CVariableList6GetVarEiiP6RValue+0xa8> */
/* @0x1f5498 mov r2, #0 */
/* @0x1f549c movw r0, #0xcccd */
/* @0x1f54a0 movw r1, #0x8c29 */
/* @0x1f54a4 movt r0, #0xdccc */
/* @0x1f54a8 movt r1, #0x4167 */
/* @0x1f54ac str r2, [r3, #0xc] */
/* @0x1f54b0 stm r3, {r0, r1} */
/* @0x1f54b4 mov r0, r2 */
/* @0x1f54b8 pop {r4, r5, r6} */
/* @0x1f54bc bx lr */
/* @0x1f54c0 mov r0, r3 */
/* @0x1f54c4 add r1, r12, #24 */
/* @0x1f54c8 pop {r4, r5, r6} */
/* @0x1f54cc b 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1f54d0 mov r0, #1 */
/* @0x1f54d4 str r2, [r3, #0xc] */
/* @0x1f54d8 str r2, [r3] */
/* @0x1f54dc str r2, [r3, #0x4] */
/* @0x1f54e0 pop {r4, r5, r6} */
/* @0x1f54e4 bx lr */
/* @0x1f54e8 andseq r8, pc, r0, lsr r7 */
/* @0x1f54ec andseq r8, pc, r8, lsl r9 */
/* @0x1f54f0 andseq r11, pc, r8, asr #5 */

/* ── FUNC 0x1f54f4 · CVariableList::Init(int) · size=92 · insn=23 */
/* @0x1f54f4 and r3, r1, #3 */
/* @0x1f54f8 push {r4, lr} */
/* @0x1f54fc add r3, r0, r3, lsl #2 */
/* @0x1f5500 mov r4, r0 */
/* @0x1f5504 ldr r3, [r3, #0x4] */
/* @0x1f5508 cmp r3, #0 */
/* @0x1f550c beq 0x1f5538 <_ZN13CVariableList4InitEi+0x44> */
/* @0x1f5510 ldr r2, [r3, #0x28] */
/* @0x1f5514 cmp r2, r1 */
/* @0x1f5518 bne 0x1f552c <_ZN13CVariableList4InitEi+0x38> */
/* @0x1f551c pop {r4, pc} */
/* @0x1f5520 ldr r2, [r3, #0x28] */
/* @0x1f5524 cmp r2, r1 */
/* @0x1f5528 popeq {r4, pc} */
/* @0x1f552c ldr r3, [r3] */
/* @0x1f5530 cmp r3, #0 */
/* @0x1f5534 bne 0x1f5520 <_ZN13CVariableList4InitEi+0x2c> */
/* @0x1f5538 mov r0, r1 */
/* @0x1f553c bl 0x1f50cc <_ZN13CVariableList5AllocEi> */
/* @0x1f5540 mov r1, r0 */
/* @0x1f5544 mov r0, r4 */
/* @0x1f5548 pop {r4, lr} */
/* @0x1f554c b 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable> */

/* ── FUNC 0x1f5550 · CVariableList::Serialise(IBuffer*) · size=236 · insn=59 */
/* @0x1f5550 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f5554 mov r2, r1 */
/* @0x1f5558 ldr r4, [r0, #0x18] */
/* @0x1f555c mov r7, r1 */
/* @0x1f5560 ldr r3, [r2], #44 */
/* @0x1f5564 mov r8, r0 */
/* @0x1f5568 mov r1, #0 */
/* @0x1f556c mov r0, r7 */
/* @0x1f5570 vmov s15, r4 */
/* @0x1f5574 str r1, [r7, #0x38] */
/* @0x1f5578 mov r1, #6 */
/* @0x1f557c add r6, r8, #20 */
/* @0x1f5580 vcvt.f64.s32 d7, s15 */
/* @0x1f5584 vmov r4, r5, d7 */
/* @0x1f5588 vstr s14, [r7, #44] */
/* @0x1f558c str r5, [r7, #0x30] */
/* @0x1f5590 ldr r3, [r3, #0x8] */
/* @0x1f5594 blx r3 */
/* @0x1f5598 cmp r6, r8 */
/* @0x1f559c add r5, r8, #4 */
/* @0x1f55a0 beq 0x1f55ac <_ZN13CVariableList9SerialiseEP7IBuffer+0x5c> */
/* @0x1f55a4 cmp r6, r5 */
/* @0x1f55a8 bne 0x1f5624 <_ZN13CVariableList9SerialiseEP7IBuffer+0xd4> */
/* @0x1f55ac mov r5, r6 */
/* @0x1f55b0 mov r4, #0 */
/* @0x1f55b4 cmp r4, #0 */
/* @0x1f55b8 beq 0x1f5620 <_ZN13CVariableList9SerialiseEP7IBuffer+0xd0> */
/* @0x1f55bc ldr r3, [r4, #0xc] */
/* @0x1f55c0 mvn r1, #0 */
/* @0x1f55c4 ldr r2, [r4, #0x8] */
/* @0x1f55c8 mov r0, #0 */
/* @0x1f55cc vmov d7, r2, r3 */
/* @0x1f55d0 vcvt.s32.f64 s15, d7 */
/* @0x1f55d4 vmov r2, s15 */
/* @0x1f55d8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x1f55dc mov r1, r0 */
/* @0x1f55e0 mov r0, r7 */
/* @0x1f55e4 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1f55e8 add r0, r4, #24 */
/* @0x1f55ec mov r1, r7 */
/* @0x1f55f0 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer> */
/* @0x1f55f4 ldr r4, [r4] */
/* @0x1f55f8 cmp r4, #0 */
/* @0x1f55fc add r3, r5, #4 */
/* @0x1f5600 bne 0x1f55b4 <_ZN13CVariableList9SerialiseEP7IBuffer+0x64> */
/* @0x1f5604 cmp r6, r5 */
/* @0x1f5608 beq 0x1f5638 <_ZN13CVariableList9SerialiseEP7IBuffer+0xe8> */
/* @0x1f560c cmp r6, r3 */
/* @0x1f5610 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1f5614 ldr r4, [r5, #0x4] */
/* @0x1f5618 mov r5, r3 */
/* @0x1f561c b 0x1f55f8 <_ZN13CVariableList9SerialiseEP7IBuffer+0xa8> */
/* @0x1f5620 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f5624 ldr r4, [r8, #0x4] */
/* @0x1f5628 cmp r4, #0 */
/* @0x1f562c bne 0x1f55b4 <_ZN13CVariableList9SerialiseEP7IBuffer+0x64> */
/* @0x1f5630 mov r8, r5 */
/* @0x1f5634 b 0x1f5598 <_ZN13CVariableList9SerialiseEP7IBuffer+0x48> */
/* @0x1f5638 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1f563c · OutputValue(tagIConsole*, RValue*) · size=964 · insn=241 */
/* @0x1f563c ldr r3, [r1, #0xc] */
/* @0x1f5640 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f5644 cmp r3, #6 */
/* @0x1f5648 sub sp, sp, #12 */
/* @0x1f564c mov r7, r1 */
/* @0x1f5650 mov r6, r0 */
/* @0x1f5654 beq 0x1f58e0 <_Z11OutputValueP11tagIConsoleP6RValue+0x2a4> */
/* @0x1f5658 bgt 0x1f5690 <_Z11OutputValueP11tagIConsoleP6RValue+0x54> */
/* @0x1f565c cmp r3, #2 */
/* @0x1f5660 beq 0x1f57b4 <_Z11OutputValueP11tagIConsoleP6RValue+0x178> */
/* @0x1f5664 ble 0x1f56fc <_Z11OutputValueP11tagIConsoleP6RValue+0xc0> */
/* @0x1f5668 cmp r3, #3 */
/* @0x1f566c beq 0x1f5760 <_Z11OutputValueP11tagIConsoleP6RValue+0x124> */
/* @0x1f5670 cmp r3, #5 */
/* @0x1f5674 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140> */
/* @0x1f5678 ldr r3, [r0] */
/* @0x1f567c ldr r1, [pc, #0x330] */
/* @0x1f5680 ldr r3, [r3, #0xc] */
/* @0x1f5684 add r1, pc, r1 */
/* @0x1f5688 blx r3 */
/* @0x1f568c b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5690 cmp r3, #13 */
/* @0x1f5694 beq 0x1f5734 <_Z11OutputValueP11tagIConsoleP6RValue+0xf8> */
/* @0x1f5698 bgt 0x1f56d0 <_Z11OutputValueP11tagIConsoleP6RValue+0x94> */
/* @0x1f569c cmp r3, #7 */
/* @0x1f56a0 beq 0x1f5798 <_Z11OutputValueP11tagIConsoleP6RValue+0x15c> */
/* @0x1f56a4 cmp r3, #10 */
/* @0x1f56a8 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140> */
/* @0x1f56ac ldr r3, [r0] */
/* @0x1f56b0 ldr r1, [pc, #0x300] */
/* @0x1f56b4 ldr r2, [r7] */
/* @0x1f56b8 ldr r12, [r3, #0xc] */
/* @0x1f56bc add r1, pc, r1 */
/* @0x1f56c0 ldr r3, [r7, #0x4] */
/* @0x1f56c4 blx r12 */
/* @0x1f56c8 add sp, sp, #12 */
/* @0x1f56cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f56d0 cmp r3, #14 */
/* @0x1f56d4 beq 0x1f58fc <_Z11OutputValueP11tagIConsoleP6RValue+0x2c0> */
/* @0x1f56d8 mvn r2, #-16777216 */
/* @0x1f56dc cmp r3, r2 */
/* @0x1f56e0 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140> */
/* @0x1f56e4 ldr r3, [r0] */
/* @0x1f56e8 ldr r1, [pc, #0x2cc] */
/* @0x1f56ec ldr r3, [r3, #0xc] */
/* @0x1f56f0 add r1, pc, r1 */
/* @0x1f56f4 blx r3 */
/* @0x1f56f8 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f56fc cmp r3, #0 */
/* @0x1f5700 beq 0x1f5914 <_Z11OutputValueP11tagIConsoleP6RValue+0x2d8> */
/* @0x1f5704 cmp r3, #1 */
/* @0x1f5708 bne 0x1f577c <_Z11OutputValueP11tagIConsoleP6RValue+0x140> */
/* @0x1f570c ldr r3, [r1] */
/* @0x1f5710 ldr r2, [r0] */
/* @0x1f5714 cmp r3, #0 */
/* @0x1f5718 ldr r1, [pc, #0x2a0] */
/* @0x1f571c ldr r12, [r2, #0xc] */
/* @0x1f5720 add r1, pc, r1 */
/* @0x1f5724 ldrne r2, [r3] */
/* @0x1f5728 moveq r2, r3 */
/* @0x1f572c blx r12 */
/* @0x1f5730 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5734 ldm r1, {r2, r3} */
/* @0x1f5738 vmov d6, r2, r3 */
/* @0x1f573c ldr r3, [r0] */
/* @0x1f5740 vcmp.f64 d6, #0 */
/* @0x1f5744 vmrs APSR_nzcv, fpscr */
/* @0x1f5748 bne 0x1f5984 <_Z11OutputValueP11tagIConsoleP6RValue+0x348> */
/* @0x1f574c ldr r1, [pc, #0x270] */
/* @0x1f5750 ldr r3, [r3, #0xc] */
/* @0x1f5754 add r1, pc, r1 */
/* @0x1f5758 blx r3 */
/* @0x1f575c b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5760 ldr r3, [r0] */
/* @0x1f5764 ldr r2, [r1] */
/* @0x1f5768 ldr r1, [pc, #0x258] */
/* @0x1f576c ldr r3, [r3, #0xc] */
/* @0x1f5770 add r1, pc, r1 */
/* @0x1f5774 blx r3 */
/* @0x1f5778 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f577c ldr r3, [r6] */
/* @0x1f5780 mov r0, r6 */
/* @0x1f5784 ldr r1, [pc, #0x240] */
/* @0x1f5788 ldr r3, [r3, #0xc] */
/* @0x1f578c add r1, pc, r1 */
/* @0x1f5790 blx r3 */
/* @0x1f5794 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5798 ldr r3, [r0] */
/* @0x1f579c ldr r2, [r1] */
/* @0x1f57a0 ldr r1, [pc, #0x228] */
/* @0x1f57a4 ldr r3, [r3, #0xc] */
/* @0x1f57a8 add r1, pc, r1 */
/* @0x1f57ac blx r3 */
/* @0x1f57b0 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f57b4 ldr r10, [pc, #0x218] */
/* @0x1f57b8 ldr r3, [r0] */
/* @0x1f57bc add r10, pc, r10 */
/* @0x1f57c0 ldr r3, [r3, #0xc] */
/* @0x1f57c4 mov r1, r10 */
/* @0x1f57c8 blx r3 */
/* @0x1f57cc ldr r8, [r7] */
/* @0x1f57d0 cmp r8, #0 */
/* @0x1f57d4 beq 0x1f58c4 <_Z11OutputValueP11tagIConsoleP6RValue+0x288> */
/* @0x1f57d8 ldr r3, [r8, #0x10] */
/* @0x1f57dc cmp r3, #0 */
/* @0x1f57e0 ble 0x1f58c4 <_Z11OutputValueP11tagIConsoleP6RValue+0x288> */
/* @0x1f57e4 ldr r5, [pc, #0x1ec] */
/* @0x1f57e8 mov r7, #0 */
/* @0x1f57ec ldr r9, [pc, #0x1e8] */
/* @0x1f57f0 ldr r3, [pc, #0x1e8] */
/* @0x1f57f4 add r5, pc, r5 */
/* @0x1f57f8 add r9, pc, r9 */
/* @0x1f57fc add r3, pc, r3 */
/* @0x1f5800 str r3, [sp, #0x4] */
/* @0x1f5804 ldr r3, [r6] */
/* @0x1f5808 mov r0, r6 */
/* @0x1f580c ldr r4, [r8, #0x4] */
/* @0x1f5810 mov r1, r10 */
/* @0x1f5814 ldr r2, [r3, #0xc] */
/* @0x1f5818 add r11, r4, r7, lsl #3 */
/* @0x1f581c blx r2 */
/* @0x1f5820 ldr r2, [r4, r7, lsl #3] */
/* @0x1f5824 cmp r2, #0 */
/* @0x1f5828 ble 0x1f588c <_Z11OutputValueP11tagIConsoleP6RValue+0x250> */
/* @0x1f582c mov r4, #0 */
/* @0x1f5830 ldr r1, [r11, #0x4] */
/* @0x1f5834 mov r0, r6 */
/* @0x1f5838 add r1, r1, r4, lsl #4 */
/* @0x1f583c add r4, r4, #1 */
/* @0x1f5840 bl 0x1f563c <_Z11OutputValueP11tagIConsoleP6RValue> */
/* @0x1f5844 ldr r2, [r11] */
/* @0x1f5848 mov r0, r6 */
/* @0x1f584c mov r1, r5 */
/* @0x1f5850 cmp r2, #30 */
/* @0x1f5854 movlt r12, r2 */
/* @0x1f5858 movge r12, #30 */
/* @0x1f585c cmp r4, r12 */
/* @0x1f5860 bge 0x1f5874 <_Z11OutputValueP11tagIConsoleP6RValue+0x238> */
/* @0x1f5864 ldr r2, [r6] */
/* @0x1f5868 ldr r2, [r2, #0xc] */
/* @0x1f586c blx r2 */
/* @0x1f5870 b 0x1f5830 <_Z11OutputValueP11tagIConsoleP6RValue+0x1f4> */
/* @0x1f5874 cmp r2, #30 */
/* @0x1f5878 ble 0x1f588c <_Z11OutputValueP11tagIConsoleP6RValue+0x250> */
/* @0x1f587c ldr r3, [r6] */
/* @0x1f5880 ldr r1, [sp, #0x4] */
/* @0x1f5884 ldr r3, [r3, #0xc] */
/* @0x1f5888 blx r3 */
/* @0x1f588c ldr r3, [r6] */
/* @0x1f5890 mov r0, r6 */
/* @0x1f5894 mov r1, r9 */
/* @0x1f5898 add r7, r7, #1 */
/* @0x1f589c ldr r3, [r3, #0xc] */
/* @0x1f58a0 blx r3 */
/* @0x1f58a4 ldr r3, [r8, #0x10] */
/* @0x1f58a8 cmp r3, #30 */
/* @0x1f58ac movlt r2, r3 */
/* @0x1f58b0 movge r2, #30 */
/* @0x1f58b4 cmp r7, r2 */
/* @0x1f58b8 blt 0x1f5804 <_Z11OutputValueP11tagIConsoleP6RValue+0x1c8> */
/* @0x1f58bc cmp r3, #30 */
/* @0x1f58c0 bgt 0x1f5998 <_Z11OutputValueP11tagIConsoleP6RValue+0x35c> */
/* @0x1f58c4 ldr r3, [r6] */
/* @0x1f58c8 mov r0, r6 */
/* @0x1f58cc ldr r1, [pc, #0x110] */
/* @0x1f58d0 ldr r3, [r3, #0xc] */
/* @0x1f58d4 add r1, pc, r1 */
/* @0x1f58d8 blx r3 */
/* @0x1f58dc b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f58e0 ldr r3, [r0] */
/* @0x1f58e4 ldr r2, [r1] */
/* @0x1f58e8 ldr r1, [pc, #0xf8] */
/* @0x1f58ec ldr r3, [r3, #0xc] */
/* @0x1f58f0 add r1, pc, r1 */
/* @0x1f58f4 blx r3 */
/* @0x1f58f8 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f58fc ldr r3, [r0] */
/* @0x1f5900 ldr r1, [pc, #0xe4] */
/* @0x1f5904 ldr r3, [r3, #0xc] */
/* @0x1f5908 add r1, pc, r1 */
/* @0x1f590c blx r3 */
/* @0x1f5910 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5914 ldm r1, {r4, r5} */
/* @0x1f5918 mov r0, r4 */
/* @0x1f591c mov r1, r5 */
/* @0x1f5920 bl 0xb66e8 <lrint@plt> */
/* @0x1f5924 ldr r2, [r7] */
/* @0x1f5928 ldr r12, [r6] */
/* @0x1f592c vmov s12, r0 */
/* @0x1f5930 mov r0, r6 */
/* @0x1f5934 vcvt.f64.s32 d7, s12 */
/* @0x1f5938 vmov d6, r4, r5 */
/* @0x1f593c vcmp.f64 d6, d7 */
/* @0x1f5940 vmrs APSR_nzcv, fpscr */
/* @0x1f5944 bne 0x1f596c <_Z11OutputValueP11tagIConsoleP6RValue+0x330> */
/* @0x1f5948 ldr r3, [r7, #0x4] */
/* @0x1f594c ldr r1, [pc, #0x9c] */
/* @0x1f5950 ldr r12, [r12, #0xc] */
/* @0x1f5954 vmov d7, r2, r3 */
/* @0x1f5958 add r1, pc, r1 */
/* @0x1f595c vcvt.s32.f64 s15, d7 */
/* @0x1f5960 vmov r2, s15 */
/* @0x1f5964 blx r12 */
/* @0x1f5968 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f596c ldr r1, [pc, #0x80] */
/* @0x1f5970 ldr r3, [r7, #0x4] */
/* @0x1f5974 add r1, pc, r1 */
/* @0x1f5978 ldr r12, [r12, #0xc] */
/* @0x1f597c blx r12 */
/* @0x1f5980 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5984 ldr r1, [pc, #0x6c] */
/* @0x1f5988 ldr r3, [r3, #0xc] */
/* @0x1f598c add r1, pc, r1 */
/* @0x1f5990 blx r3 */
/* @0x1f5994 b 0x1f56c8 <_Z11OutputValueP11tagIConsoleP6RValue+0x8c> */
/* @0x1f5998 ldr r3, [r6] */
/* @0x1f599c mov r0, r6 */
/* @0x1f59a0 ldr r1, [pc, #0x54] */
/* @0x1f59a4 ldr r3, [r3, #0xc] */
/* @0x1f59a8 add r1, pc, r1 */
/* @0x1f59ac blx r3 */
/* @0x1f59b0 b 0x1f58c4 <_Z11OutputValueP11tagIConsoleP6RValue+0x288> */
/* @0x1f59b4 ldrsbeq r12, [r3], -r12 */
/* @0x1f59b8 ldrsbeq sp, [r5], -r4 */
/* @0x1f59bc andseq sp, r5, r4, lsr #3 */
/* @0x1f59c0 andseq sp, r5, r8, asr r1 */
/* @0x1f59c4 ldrsbeq pc, [r3], -r4 */
/* @0x1f59c8 mulseq r3, r8, sp */
/* @0x1f59cc andseq sp, r5, r4, lsr #2 */
/* @0x1f59d0 andseq r12, r3, r4, ror #26 */
/* @0x1f59d4 andseq r12, r3, r0, ror #26 */
/* @0x1f59d8 andseq sp, r5, r8, lsr #1 */
/* @0x1f59dc ldrheq sp, [r5], -r0 */
/* @0x1f59e0 andseq sp, r5, r4, lsr #1 */
/* @0x1f59e4 andseq r12, r3, r12, asr #24 */
/* @0x1f59e8 mulseq r5, r0, pc */
/* @0x1f59ec andseq r12, r3, r4, lsr #19 */
/* @0x1f59f0 ldrheq r12, [r3], -r4 */
/* @0x1f59f4 andseq r10, r4, r0, asr #20 */
/* @0x1f59f8 mulseq r3, r4, r0 */
/* @0x1f59fc ldrsheq r12, [r5], -r8 */

/* ── FUNC 0x1f5a00 · OutputVariable(tagIConsole*, RVariable*) · size=200 · insn=50 */
/* @0x1f5a00 ldr r3, [r1, #0x14] */
/* @0x1f5a04 push {r4, r5, r6, lr} */
/* @0x1f5a08 cmp r3, #1 */
/* @0x1f5a0c mov r5, r1 */
/* @0x1f5a10 mov r4, r0 */
/* @0x1f5a14 bne 0x1f5a64 <_Z14OutputVariableP11tagIConsoleP9RVariable+0x64> */
/* @0x1f5a18 ldr r3, [r1, #0x8] */
/* @0x1f5a1c cmp r3, #0 */
/* @0x1f5a20 beq 0x1f5a9c <_Z14OutputVariableP11tagIConsoleP9RVariable+0x9c> */
/* @0x1f5a24 ldr r12, [r0] */
/* @0x1f5a28 ldr r1, [pc, #0x84] */
/* @0x1f5a2c ldr r2, [r3] */
/* @0x1f5a30 add r1, pc, r1 */
/* @0x1f5a34 ldr r3, [r12, #0xc] */
/* @0x1f5a38 blx r3 */
/* @0x1f5a3c add r1, r5, #24 */
/* @0x1f5a40 mov r0, r4 */
/* @0x1f5a44 bl 0x1f563c <_Z11OutputValueP11tagIConsoleP6RValue> */
/* @0x1f5a48 ldr r3, [r4] */
/* @0x1f5a4c ldr r1, [pc, #0x64] */
/* @0x1f5a50 mov r0, r4 */
/* @0x1f5a54 add r1, pc, r1 */
/* @0x1f5a58 ldr r3, [r3, #0xc] */
/* @0x1f5a5c blx r3 */
/* @0x1f5a60 pop {r4, r5, r6, pc} */
/* @0x1f5a64 ldr r3, [r0] */
/* @0x1f5a68 mvn r1, #0 */
/* @0x1f5a6c ldr r0, [pc, #0x48] */
/* @0x1f5a70 ldr r2, [r5, #0x8] */
/* @0x1f5a74 add r0, pc, r0 */
/* @0x1f5a78 ldr r6, [r3, #0xc] */
/* @0x1f5a7c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x1f5a80 ldr r1, [pc, #0x38] */
/* @0x1f5a84 ldr r3, [r5, #0x8] */
/* @0x1f5a88 add r1, pc, r1 */
/* @0x1f5a8c mov r2, r0 */
/* @0x1f5a90 mov r0, r4 */
/* @0x1f5a94 blx r6 */
/* @0x1f5a98 b 0x1f5a3c <_Z14OutputVariableP11tagIConsoleP9RVariable+0x3c> */
/* @0x1f5a9c ldr r3, [r0] */
/* @0x1f5aa0 ldr r1, [pc, #0x1c] */
/* @0x1f5aa4 ldr r3, [r3, #0xc] */
/* @0x1f5aa8 add r1, pc, r1 */
/* @0x1f5aac blx r3 */
/* @0x1f5ab0 b 0x1f5a3c <_Z14OutputVariableP11tagIConsoleP9RVariable+0x3c> */
/* @0x1f5ab4 andseq r7, r5, r4, ror r2 */
/* @0x1f5ab8 andseq sp, r3, r4, asr #4 */
/* @0x1f5abc andseq r9, r3, r2, asr #1 */
/* @0x1f5ac0 andseq r12, r5, r8, lsr lr */
/* @0x1f5ac4 andseq r12, r5, r4, lsr #28 */

/* ── FUNC 0x1f5ac8 · CVariableList::Dump(tagIConsole&) · size=152 · insn=38 */
/* @0x1f5ac8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1f5acc adds r4, r0, #4 */
/* @0x1f5ad0 mov r7, r1 */
/* @0x1f5ad4 addne r4, r0, #20 */
/* @0x1f5ad8 beq 0x1f5b3c <_ZN13CVariableList4DumpER11tagIConsole+0x74> */
/* @0x1f5adc cmp r4, r0 */
/* @0x1f5ae0 add r6, r0, #4 */
/* @0x1f5ae4 beq 0x1f5af0 <_ZN13CVariableList4DumpER11tagIConsole+0x28> */
/* @0x1f5ae8 cmp r4, r6 */
/* @0x1f5aec bne 0x1f5b48 <_ZN13CVariableList4DumpER11tagIConsole+0x80> */
/* @0x1f5af0 mov r6, r4 */
/* @0x1f5af4 mov r5, #0 */
/* @0x1f5af8 cmp r5, #0 */
/* @0x1f5afc beq 0x1f5b38 <_ZN13CVariableList4DumpER11tagIConsole+0x70> */
/* @0x1f5b00 mov r1, r5 */
/* @0x1f5b04 mov r0, r7 */
/* @0x1f5b08 bl 0x1f5a00 <_Z14OutputVariableP11tagIConsoleP9RVariable> */
/* @0x1f5b0c ldr r5, [r5] */
/* @0x1f5b10 cmp r5, #0 */
/* @0x1f5b14 add r3, r6, #4 */
/* @0x1f5b18 bne 0x1f5af8 <_ZN13CVariableList4DumpER11tagIConsole+0x30> */
/* @0x1f5b1c cmp r4, r6 */
/* @0x1f5b20 beq 0x1f5b5c <_ZN13CVariableList4DumpER11tagIConsole+0x94> */
/* @0x1f5b24 cmp r3, r4 */
/* @0x1f5b28 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1f5b2c ldr r5, [r6, #0x4] */
/* @0x1f5b30 mov r6, r3 */
/* @0x1f5b34 b 0x1f5b10 <_ZN13CVariableList4DumpER11tagIConsole+0x48> */
/* @0x1f5b38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1f5b3c mov r6, r4 */
/* @0x1f5b40 mov r5, r4 */
/* @0x1f5b44 b 0x1f5af8 <_ZN13CVariableList4DumpER11tagIConsole+0x30> */
/* @0x1f5b48 ldr r5, [r0, #0x4] */
/* @0x1f5b4c cmp r5, #0 */
/* @0x1f5b50 bne 0x1f5af8 <_ZN13CVariableList4DumpER11tagIConsole+0x30> */
/* @0x1f5b54 mov r0, r6 */
/* @0x1f5b58 b 0x1f5adc <_ZN13CVariableList4DumpER11tagIConsole+0x14> */
/* @0x1f5b5c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1f5b60 · RVariable::RVariable(RValue const*) · size=616 · insn=154 */
/* @0x1f5b60 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f5b64 mov r4, r0 */
/* @0x1f5b68 mov r3, #0 */
/* @0x1f5b6c mov r0, r1 */
/* @0x1f5b70 str r3, [r4] */
/* @0x1f5b74 mov r5, r1 */
/* @0x1f5b78 str r3, [r4, #0x4] */
/* @0x1f5b7c add r7, r4, #8 */
/* @0x1f5b80 bl 0xcee94 <_Z11HASH_RValuePK6RValue> */
/* @0x1f5b84 ldr r2, [r4, #0x14] */
/* @0x1f5b88 bic r3, r2, #-16777216 */
/* @0x1f5b8c cmp r3, #1 */
/* @0x1f5b90 str r0, [r4, #0x28] */
/* @0x1f5b94 beq 0x1f5c58 <_ZN9RVariableC2EPK6RValue+0xf8> */
/* @0x1f5b98 cmp r3, #2 */
/* @0x1f5b9c bne 0x1f5bc4 <_ZN9RVariableC2EPK6RValue+0x64> */
/* @0x1f5ba0 sub r2, r2, #1 */
/* @0x1f5ba4 bic r2, r2, #-16777216 */
/* @0x1f5ba8 bic r2, r2, #3 */
/* @0x1f5bac cmp r2, #0 */
/* @0x1f5bb0 beq 0x1f5d2c <_ZN9RVariableC2EPK6RValue+0x1cc> */
/* @0x1f5bb4 mov r2, #0 */
/* @0x1f5bb8 mov r3, #5 */
/* @0x1f5bbc str r2, [r4, #0x10] */
/* @0x1f5bc0 str r3, [r4, #0x14] */
/* @0x1f5bc4 ldr r3, [r5, #0xc] */
/* @0x1f5bc8 mov r1, #0 */
/* @0x1f5bcc ldr r2, [r5, #0x8] */
/* @0x1f5bd0 str r1, [r4, #0x8] */
/* @0x1f5bd4 str r3, [r4, #0x14] */
/* @0x1f5bd8 ldr r3, [r5, #0xc] */
/* @0x1f5bdc str r2, [r4, #0x10] */
/* @0x1f5be0 bic r3, r3, #-16777216 */
/* @0x1f5be4 cmp r3, #14 */
/* @0x1f5be8 addls pc, pc, r3, lsl #2 */
/* @0x1f5bec b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5bf0 b 0x1f5c48 <_ZN9RVariableC2EPK6RValue+0xe8> */
/* @0x1f5bf4 b 0x1f5cb0 <_ZN9RVariableC2EPK6RValue+0x150> */
/* @0x1f5bf8 b 0x1f5cc8 <_ZN9RVariableC2EPK6RValue+0x168> */
/* @0x1f5bfc b 0x1f5c2c <_ZN9RVariableC2EPK6RValue+0xcc> */
/* @0x1f5c00 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c04 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c08 b 0x1f5c8c <_ZN9RVariableC2EPK6RValue+0x12c> */
/* @0x1f5c0c b 0x1f5c2c <_ZN9RVariableC2EPK6RValue+0xcc> */
/* @0x1f5c10 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c14 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c18 b 0x1f5c48 <_ZN9RVariableC2EPK6RValue+0xe8> */
/* @0x1f5c1c b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c20 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c24 b 0x1f5c48 <_ZN9RVariableC2EPK6RValue+0xe8> */
/* @0x1f5c28 b 0x1f5c2c <_ZN9RVariableC2EPK6RValue+0xcc> */
/* @0x1f5c2c ldr r3, [r5] */
/* @0x1f5c30 str r3, [r4, #0x8] */
/* @0x1f5c34 mov r3, #0 */
/* @0x1f5c38 mov r0, r4 */
/* @0x1f5c3c str r3, [r4, #0x18] */
/* @0x1f5c40 str r3, [r4, #0x24] */
/* @0x1f5c44 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f5c48 ldm r5, {r2, r3} */
/* @0x1f5c4c str r2, [r4, #0x8] */
/* @0x1f5c50 str r3, [r4, #0xc] */
/* @0x1f5c54 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5c58 ldr r6, [r4, #0x8] */
/* @0x1f5c5c cmp r6, #0 */
/* @0x1f5c60 beq 0x1f5c80 <_ZN9RVariableC2EPK6RValue+0x120> */
/* @0x1f5c64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f5c68 ldr r8, [r6, #0x4] */
/* @0x1f5c6c sub r8, r8, #1 */
/* @0x1f5c70 str r8, [r6, #0x4] */
/* @0x1f5c74 cmp r8, #0 */
/* @0x1f5c78 beq 0x1f5cf4 <_ZN9RVariableC2EPK6RValue+0x194> */
/* @0x1f5c7c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f5c80 mov r3, #0 */
/* @0x1f5c84 str r3, [r4, #0x8] */
/* @0x1f5c88 b 0x1f5bc4 <_ZN9RVariableC2EPK6RValue+0x64> */
/* @0x1f5c8c ldr r3, [r5] */
/* @0x1f5c90 str r3, [r4, #0x8] */
/* @0x1f5c94 ldr r3, [r5] */
/* @0x1f5c98 cmp r3, #0 */
/* @0x1f5c9c beq 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5ca0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f5ca4 ldr r1, [r5] */
/* @0x1f5ca8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f5cac b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5cb0 ldr r3, [r5] */
/* @0x1f5cb4 cmp r3, #0 */
/* @0x1f5cb8 ldrne r2, [r3, #0x4] */
/* @0x1f5cbc addne r2, r2, #1 */
/* @0x1f5cc0 strne r2, [r3, #0x4] */
/* @0x1f5cc4 b 0x1f5c30 <_ZN9RVariableC2EPK6RValue+0xd0> */
/* @0x1f5cc8 ldr r3, [r5] */
/* @0x1f5ccc cmp r3, #0 */
/* @0x1f5cd0 str r3, [r4, #0x8] */
/* @0x1f5cd4 beq 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5cd8 ldr r1, [r3, #0x8] */
/* @0x1f5cdc ldr r2, [r3] */
/* @0x1f5ce0 cmp r1, #0 */
/* @0x1f5ce4 streq r7, [r3, #0x8] */
/* @0x1f5ce8 add r2, r2, #1 */
/* @0x1f5cec str r2, [r3] */
/* @0x1f5cf0 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4> */
/* @0x1f5cf4 ldr r0, [r6] */
/* @0x1f5cf8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f5cfc str r8, [r6] */
/* @0x1f5d00 str r8, [r6, #0x8] */
/* @0x1f5d04 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f5d08 ldr r8, [r6, #0x4] */
/* @0x1f5d0c sub r8, r8, #1 */
/* @0x1f5d10 str r8, [r6, #0x4] */
/* @0x1f5d14 cmp r8, #0 */
/* @0x1f5d18 beq 0x1f5d38 <_ZN9RVariableC2EPK6RValue+0x1d8> */
/* @0x1f5d1c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f5d20 mov r0, r6 */
/* @0x1f5d24 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f5d28 b 0x1f5c7c <_ZN9RVariableC2EPK6RValue+0x11c> */
/* @0x1f5d2c mov r0, r7 */
/* @0x1f5d30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f5d34 b 0x1f5bb4 <_ZN9RVariableC2EPK6RValue+0x54> */
/* @0x1f5d38 ldr r0, [r6] */
/* @0x1f5d3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f5d40 str r8, [r6] */
/* @0x1f5d44 str r8, [r6, #0x8] */
/* @0x1f5d48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f5d4c ldr r8, [r6, #0x4] */
/* @0x1f5d50 sub r8, r8, #1 */
/* @0x1f5d54 str r8, [r6, #0x4] */
/* @0x1f5d58 cmp r8, #0 */
/* @0x1f5d5c beq 0x1f5d70 <_ZN9RVariableC2EPK6RValue+0x210> */
/* @0x1f5d60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f5d64 mov r0, r6 */
/* @0x1f5d68 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f5d6c b 0x1f5d1c <_ZN9RVariableC2EPK6RValue+0x1bc> */
/* @0x1f5d70 ldr r0, [r6] */
/* @0x1f5d74 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f5d78 str r8, [r6] */
/* @0x1f5d7c str r8, [r6, #0x8] */
/* @0x1f5d80 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f5d84 ldr r8, [r6, #0x4] */
/* @0x1f5d88 sub r8, r8, #1 */
/* @0x1f5d8c str r8, [r6, #0x4] */
/* @0x1f5d90 cmp r8, #0 */
/* @0x1f5d94 bne 0x1f5db8 <_ZN9RVariableC2EPK6RValue+0x258> */
/* @0x1f5d98 ldr r0, [r6] */
/* @0x1f5d9c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f5da0 mov r0, r6 */
/* @0x1f5da4 str r8, [r6] */
/* @0x1f5da8 str r8, [r6, #0x8] */
/* @0x1f5dac bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f5db0 mov r0, r6 */
/* @0x1f5db4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f5db8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f5dbc mov r0, r6 */
/* @0x1f5dc0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f5dc4 b 0x1f5d60 <_ZN9RVariableC2EPK6RValue+0x200> */

/* ── FUNC 0x1f5b60 · RVariable::RVariable(RValue const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f5dc8 · RVariable::RVariable(RValue const*, RValue const*) · size=1172 · insn=293 */
/* @0x1f5dc8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1f5dcc mov r4, r0 */
/* @0x1f5dd0 mov r3, #0 */
/* @0x1f5dd4 mov r0, r1 */
/* @0x1f5dd8 str r3, [r4] */
/* @0x1f5ddc mov r6, r2 */
/* @0x1f5de0 str r3, [r4, #0x4] */
/* @0x1f5de4 mov r5, r1 */
/* @0x1f5de8 bl 0xcee94 <_Z11HASH_RValuePK6RValue> */
/* @0x1f5dec ldr r2, [r4, #0x14] */
/* @0x1f5df0 add r8, r4, #8 */
/* @0x1f5df4 bic r3, r2, #-16777216 */
/* @0x1f5df8 cmp r3, #1 */
/* @0x1f5dfc str r0, [r4, #0x28] */
/* @0x1f5e00 beq 0x1f5f7c <_ZN9RVariableC2EPK6RValueS2_+0x1b4> */
/* @0x1f5e04 cmp r3, #2 */
/* @0x1f5e08 bne 0x1f5e30 <_ZN9RVariableC2EPK6RValueS2_+0x68> */
/* @0x1f5e0c sub r2, r2, #1 */
/* @0x1f5e10 bic r2, r2, #-16777216 */
/* @0x1f5e14 bic r2, r2, #3 */
/* @0x1f5e18 cmp r2, #0 */
/* @0x1f5e1c beq 0x1f6124 <_ZN9RVariableC2EPK6RValueS2_+0x35c> */
/* @0x1f5e20 mov r2, #0 */
/* @0x1f5e24 mov r3, #5 */
/* @0x1f5e28 str r2, [r4, #0x10] */
/* @0x1f5e2c str r3, [r4, #0x14] */
/* @0x1f5e30 ldr r3, [r5, #0xc] */
/* @0x1f5e34 mov r1, #0 */
/* @0x1f5e38 ldr r2, [r5, #0x8] */
/* @0x1f5e3c str r1, [r4, #0x8] */
/* @0x1f5e40 str r3, [r4, #0x14] */
/* @0x1f5e44 ldr r3, [r5, #0xc] */
/* @0x1f5e48 str r2, [r4, #0x10] */
/* @0x1f5e4c bic r3, r3, #-16777216 */
/* @0x1f5e50 cmp r3, #14 */
/* @0x1f5e54 addls pc, pc, r3, lsl #2 */
/* @0x1f5e58 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e5c b 0x1f5f58 <_ZN9RVariableC2EPK6RValueS2_+0x190> */
/* @0x1f5e60 b 0x1f6008 <_ZN9RVariableC2EPK6RValueS2_+0x240> */
/* @0x1f5e64 b 0x1f6020 <_ZN9RVariableC2EPK6RValueS2_+0x258> */
/* @0x1f5e68 b 0x1f5e98 <_ZN9RVariableC2EPK6RValueS2_+0xd0> */
/* @0x1f5e6c b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e70 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e74 b 0x1f5fe4 <_ZN9RVariableC2EPK6RValueS2_+0x21c> */
/* @0x1f5e78 b 0x1f5e98 <_ZN9RVariableC2EPK6RValueS2_+0xd0> */
/* @0x1f5e7c b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e80 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e84 b 0x1f5f58 <_ZN9RVariableC2EPK6RValueS2_+0x190> */
/* @0x1f5e88 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e8c b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5e90 b 0x1f5f58 <_ZN9RVariableC2EPK6RValueS2_+0x190> */
/* @0x1f5e94 b 0x1f5e98 <_ZN9RVariableC2EPK6RValueS2_+0xd0> */
/* @0x1f5e98 ldr r3, [r5] */
/* @0x1f5e9c str r3, [r4, #0x8] */
/* @0x1f5ea0 ldr r2, [r4, #0x24] */
/* @0x1f5ea4 add r7, r4, #24 */
/* @0x1f5ea8 bic r3, r2, #-16777216 */
/* @0x1f5eac cmp r3, #1 */
/* @0x1f5eb0 beq 0x1f5fb0 <_ZN9RVariableC2EPK6RValueS2_+0x1e8> */
/* @0x1f5eb4 cmp r3, #2 */
/* @0x1f5eb8 bne 0x1f5ee0 <_ZN9RVariableC2EPK6RValueS2_+0x118> */
/* @0x1f5ebc sub r2, r2, #1 */
/* @0x1f5ec0 bic r2, r2, #-16777216 */
/* @0x1f5ec4 bic r2, r2, #3 */
/* @0x1f5ec8 cmp r2, #0 */
/* @0x1f5ecc beq 0x1f6130 <_ZN9RVariableC2EPK6RValueS2_+0x368> */
/* @0x1f5ed0 mov r2, #0 */
/* @0x1f5ed4 mov r3, #5 */
/* @0x1f5ed8 str r2, [r4, #0x20] */
/* @0x1f5edc str r3, [r4, #0x24] */
/* @0x1f5ee0 ldr r3, [r6, #0xc] */
/* @0x1f5ee4 mov r1, #0 */
/* @0x1f5ee8 ldr r2, [r6, #0x8] */
/* @0x1f5eec str r1, [r4, #0x18] */
/* @0x1f5ef0 str r3, [r4, #0x24] */
/* @0x1f5ef4 ldr r3, [r6, #0xc] */
/* @0x1f5ef8 str r2, [r4, #0x20] */
/* @0x1f5efc bic r3, r3, #-16777216 */
/* @0x1f5f00 cmp r3, #14 */
/* @0x1f5f04 addls pc, pc, r3, lsl #2 */
/* @0x1f5f08 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f0c b 0x1f5f68 <_ZN9RVariableC2EPK6RValueS2_+0x1a0> */
/* @0x1f5f10 b 0x1f604c <_ZN9RVariableC2EPK6RValueS2_+0x284> */
/* @0x1f5f14 b 0x1f6088 <_ZN9RVariableC2EPK6RValueS2_+0x2c0> */
/* @0x1f5f18 b 0x1f5f48 <_ZN9RVariableC2EPK6RValueS2_+0x180> */
/* @0x1f5f1c b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f20 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f24 b 0x1f6064 <_ZN9RVariableC2EPK6RValueS2_+0x29c> */
/* @0x1f5f28 b 0x1f5f48 <_ZN9RVariableC2EPK6RValueS2_+0x180> */
/* @0x1f5f2c b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f30 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f34 b 0x1f5f68 <_ZN9RVariableC2EPK6RValueS2_+0x1a0> */
/* @0x1f5f38 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f3c b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f5f40 b 0x1f5f68 <_ZN9RVariableC2EPK6RValueS2_+0x1a0> */
/* @0x1f5f44 b 0x1f5f48 <_ZN9RVariableC2EPK6RValueS2_+0x180> */
/* @0x1f5f48 ldr r3, [r6] */
/* @0x1f5f4c str r3, [r4, #0x18] */
/* @0x1f5f50 mov r0, r4 */
/* @0x1f5f54 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1f5f58 ldm r5, {r2, r3} */
/* @0x1f5f5c str r2, [r4, #0x8] */
/* @0x1f5f60 str r3, [r4, #0xc] */
/* @0x1f5f64 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5f68 ldm r6, {r2, r3} */
/* @0x1f5f6c mov r0, r4 */
/* @0x1f5f70 str r2, [r4, #0x18] */
/* @0x1f5f74 str r3, [r4, #0x1c] */
/* @0x1f5f78 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1f5f7c ldr r7, [r4, #0x8] */
/* @0x1f5f80 cmp r7, #0 */
/* @0x1f5f84 beq 0x1f5fa4 <_ZN9RVariableC2EPK6RValueS2_+0x1dc> */
/* @0x1f5f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f5f8c ldr r9, [r7, #0x4] */
/* @0x1f5f90 sub r9, r9, #1 */
/* @0x1f5f94 str r9, [r7, #0x4] */
/* @0x1f5f98 cmp r9, #0 */
/* @0x1f5f9c beq 0x1f60b4 <_ZN9RVariableC2EPK6RValueS2_+0x2ec> */
/* @0x1f5fa0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f5fa4 mov r3, #0 */
/* @0x1f5fa8 str r3, [r4, #0x8] */
/* @0x1f5fac b 0x1f5e30 <_ZN9RVariableC2EPK6RValueS2_+0x68> */
/* @0x1f5fb0 ldr r5, [r4, #0x18] */
/* @0x1f5fb4 cmp r5, #0 */
/* @0x1f5fb8 beq 0x1f5fd8 <_ZN9RVariableC2EPK6RValueS2_+0x210> */
/* @0x1f5fbc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f5fc0 ldr r8, [r5, #0x4] */
/* @0x1f5fc4 sub r8, r8, #1 */
/* @0x1f5fc8 str r8, [r5, #0x4] */
/* @0x1f5fcc cmp r8, #0 */
/* @0x1f5fd0 beq 0x1f60ec <_ZN9RVariableC2EPK6RValueS2_+0x324> */
/* @0x1f5fd4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f5fd8 mov r3, #0 */
/* @0x1f5fdc str r3, [r4, #0x18] */
/* @0x1f5fe0 b 0x1f5ee0 <_ZN9RVariableC2EPK6RValueS2_+0x118> */
/* @0x1f5fe4 ldr r3, [r5] */
/* @0x1f5fe8 str r3, [r4, #0x8] */
/* @0x1f5fec ldr r3, [r5] */
/* @0x1f5ff0 cmp r3, #0 */
/* @0x1f5ff4 beq 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f5ff8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f5ffc ldr r1, [r5] */
/* @0x1f6000 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f6004 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f6008 ldr r3, [r5] */
/* @0x1f600c cmp r3, #0 */
/* @0x1f6010 ldrne r2, [r3, #0x4] */
/* @0x1f6014 addne r2, r2, #1 */
/* @0x1f6018 strne r2, [r3, #0x4] */
/* @0x1f601c b 0x1f5e9c <_ZN9RVariableC2EPK6RValueS2_+0xd4> */
/* @0x1f6020 ldr r3, [r5] */
/* @0x1f6024 cmp r3, #0 */
/* @0x1f6028 str r3, [r4, #0x8] */
/* @0x1f602c beq 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f6030 ldr r1, [r3, #0x8] */
/* @0x1f6034 ldr r2, [r3] */
/* @0x1f6038 cmp r1, #0 */
/* @0x1f603c streq r8, [r3, #0x8] */
/* @0x1f6040 add r2, r2, #1 */
/* @0x1f6044 str r2, [r3] */
/* @0x1f6048 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8> */
/* @0x1f604c ldr r3, [r6] */
/* @0x1f6050 cmp r3, #0 */
/* @0x1f6054 ldrne r2, [r3, #0x4] */
/* @0x1f6058 addne r2, r2, #1 */
/* @0x1f605c strne r2, [r3, #0x4] */
/* @0x1f6060 b 0x1f5f4c <_ZN9RVariableC2EPK6RValueS2_+0x184> */
/* @0x1f6064 ldr r3, [r6] */
/* @0x1f6068 str r3, [r4, #0x18] */
/* @0x1f606c ldr r3, [r6] */
/* @0x1f6070 cmp r3, #0 */
/* @0x1f6074 beq 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f6078 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1f607c ldr r1, [r6] */
/* @0x1f6080 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1f6084 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f6088 ldr r3, [r6] */
/* @0x1f608c cmp r3, #0 */
/* @0x1f6090 str r3, [r4, #0x18] */
/* @0x1f6094 beq 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f6098 ldr r1, [r3, #0x8] */
/* @0x1f609c ldr r2, [r3] */
/* @0x1f60a0 cmp r1, #0 */
/* @0x1f60a4 streq r7, [r3, #0x8] */
/* @0x1f60a8 add r2, r2, #1 */
/* @0x1f60ac str r2, [r3] */
/* @0x1f60b0 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188> */
/* @0x1f60b4 ldr r0, [r7] */
/* @0x1f60b8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f60bc str r9, [r7] */
/* @0x1f60c0 str r9, [r7, #0x8] */
/* @0x1f60c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f60c8 ldr r9, [r7, #0x4] */
/* @0x1f60cc sub r9, r9, #1 */
/* @0x1f60d0 str r9, [r7, #0x4] */
/* @0x1f60d4 cmp r9, #0 */
/* @0x1f60d8 beq 0x1f613c <_ZN9RVariableC2EPK6RValueS2_+0x374> */
/* @0x1f60dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f60e0 mov r0, r7 */
/* @0x1f60e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f60e8 b 0x1f5fa0 <_ZN9RVariableC2EPK6RValueS2_+0x1d8> */
/* @0x1f60ec ldr r0, [r5] */
/* @0x1f60f0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f60f4 str r8, [r5] */
/* @0x1f60f8 str r8, [r5, #0x8] */
/* @0x1f60fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6100 ldr r8, [r5, #0x4] */
/* @0x1f6104 sub r8, r8, #1 */
/* @0x1f6108 str r8, [r5, #0x4] */
/* @0x1f610c cmp r8, #0 */
/* @0x1f6110 beq 0x1f6174 <_ZN9RVariableC2EPK6RValueS2_+0x3ac> */
/* @0x1f6114 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6118 mov r0, r5 */
/* @0x1f611c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6120 b 0x1f5fd4 <_ZN9RVariableC2EPK6RValueS2_+0x20c> */
/* @0x1f6124 mov r0, r8 */
/* @0x1f6128 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f612c b 0x1f5e20 <_ZN9RVariableC2EPK6RValueS2_+0x58> */
/* @0x1f6130 mov r0, r7 */
/* @0x1f6134 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6138 b 0x1f5ed0 <_ZN9RVariableC2EPK6RValueS2_+0x108> */
/* @0x1f613c ldr r0, [r7] */
/* @0x1f6140 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6144 str r9, [r7] */
/* @0x1f6148 str r9, [r7, #0x8] */
/* @0x1f614c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6150 ldr r9, [r7, #0x4] */
/* @0x1f6154 sub r9, r9, #1 */
/* @0x1f6158 str r9, [r7, #0x4] */
/* @0x1f615c cmp r9, #0 */
/* @0x1f6160 beq 0x1f61ac <_ZN9RVariableC2EPK6RValueS2_+0x3e4> */
/* @0x1f6164 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6168 mov r0, r7 */
/* @0x1f616c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6170 b 0x1f60dc <_ZN9RVariableC2EPK6RValueS2_+0x314> */
/* @0x1f6174 ldr r0, [r5] */
/* @0x1f6178 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f617c str r8, [r5] */
/* @0x1f6180 str r8, [r5, #0x8] */
/* @0x1f6184 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6188 ldr r8, [r5, #0x4] */
/* @0x1f618c sub r8, r8, #1 */
/* @0x1f6190 str r8, [r5, #0x4] */
/* @0x1f6194 cmp r8, #0 */
/* @0x1f6198 beq 0x1f6204 <_ZN9RVariableC2EPK6RValueS2_+0x43c> */
/* @0x1f619c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f61a0 mov r0, r5 */
/* @0x1f61a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f61a8 b 0x1f6114 <_ZN9RVariableC2EPK6RValueS2_+0x34c> */
/* @0x1f61ac ldr r0, [r7] */
/* @0x1f61b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f61b4 str r9, [r7] */
/* @0x1f61b8 str r9, [r7, #0x8] */
/* @0x1f61bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f61c0 ldr r9, [r7, #0x4] */
/* @0x1f61c4 sub r9, r9, #1 */
/* @0x1f61c8 str r9, [r7, #0x4] */
/* @0x1f61cc cmp r9, #0 */
/* @0x1f61d0 bne 0x1f61f4 <_ZN9RVariableC2EPK6RValueS2_+0x42c> */
/* @0x1f61d4 ldr r0, [r7] */
/* @0x1f61d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f61dc mov r0, r7 */
/* @0x1f61e0 str r9, [r7] */
/* @0x1f61e4 str r9, [r7, #0x8] */
/* @0x1f61e8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f61ec mov r0, r7 */
/* @0x1f61f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f61f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f61f8 mov r0, r7 */
/* @0x1f61fc bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6200 b 0x1f6164 <_ZN9RVariableC2EPK6RValueS2_+0x39c> */
/* @0x1f6204 ldr r0, [r5] */
/* @0x1f6208 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f620c str r8, [r5] */
/* @0x1f6210 str r8, [r5, #0x8] */
/* @0x1f6214 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f6218 ldr r8, [r5, #0x4] */
/* @0x1f621c sub r8, r8, #1 */
/* @0x1f6220 str r8, [r5, #0x4] */
/* @0x1f6224 cmp r8, #0 */
/* @0x1f6228 bne 0x1f624c <_ZN9RVariableC2EPK6RValueS2_+0x484> */
/* @0x1f622c ldr r0, [r5] */
/* @0x1f6230 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6234 mov r0, r5 */
/* @0x1f6238 str r8, [r5] */
/* @0x1f623c str r8, [r5, #0x8] */
/* @0x1f6240 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f6244 mov r0, r5 */
/* @0x1f6248 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f624c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6250 mov r0, r5 */
/* @0x1f6254 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6258 b 0x1f619c <_ZN9RVariableC2EPK6RValueS2_+0x3d4> */

/* ── FUNC 0x1f5dc8 · RVariable::RVariable(RValue const*, RValue const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f625c · CVariableList::Remove(RVariable*) · size=248 · insn=62 */
/* @0x1f625c ldr r3, [r1, #0x28] */
/* @0x1f6260 push {r4, lr} */
/* @0x1f6264 and r3, r3, #3 */
/* @0x1f6268 mov r4, r1 */
/* @0x1f626c add r0, r0, r3, lsl #2 */
/* @0x1f6270 ldr r2, [r0, #0x4] */
/* @0x1f6274 cmp r1, r2 */
/* @0x1f6278 cmpne r2, #0 */
/* @0x1f627c bne 0x1f6288 <_ZN13CVariableList6RemoveEP9RVariable+0x2c> */
/* @0x1f6280 b 0x1f6344 <_ZN13CVariableList6RemoveEP9RVariable+0xe8> */
/* @0x1f6284 mov r2, r3 */
/* @0x1f6288 add r3, r2, #44 */
/* @0x1f628c cmp r4, r3 */
/* @0x1f6290 cmpne r3, #0 */
/* @0x1f6294 bne 0x1f6284 <_ZN13CVariableList6RemoveEP9RVariable+0x28> */
/* @0x1f6298 cmp r4, r3 */
/* @0x1f629c beq 0x1f6324 <_ZN13CVariableList6RemoveEP9RVariable+0xc8> */
/* @0x1f62a0 ldr r1, [r4, #0x14] */
/* @0x1f62a4 ldr r3, [pc, #0xa4] */
/* @0x1f62a8 sub r1, r1, #1 */
/* @0x1f62ac ldr r3, [pc, r3] */
/* @0x1f62b0 bic r1, r1, #-16777216 */
/* @0x1f62b4 bic r1, r1, #3 */
/* @0x1f62b8 ldr r2, [r3] */
/* @0x1f62bc cmp r1, #0 */
/* @0x1f62c0 str r4, [r3] */
/* @0x1f62c4 str r2, [r4, #0x4] */
/* @0x1f62c8 beq 0x1f6318 <_ZN13CVariableList6RemoveEP9RVariable+0xbc> */
/* @0x1f62cc ldr r1, [r4, #0x24] */
/* @0x1f62d0 mov r3, #0 */
/* @0x1f62d4 str r3, [r4, #0x10] */
/* @0x1f62d8 mov r2, #5 */
/* @0x1f62dc sub r1, r1, #1 */
/* @0x1f62e0 str r3, [r4, #0x8] */
/* @0x1f62e4 bic r3, r1, #-16777216 */
/* @0x1f62e8 str r2, [r4, #0x14] */
/* @0x1f62ec bic r3, r3, #3 */
/* @0x1f62f0 cmp r3, #0 */
/* @0x1f62f4 bne 0x1f6300 <_ZN13CVariableList6RemoveEP9RVariable+0xa4> */
/* @0x1f62f8 add r0, r4, #24 */
/* @0x1f62fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6300 mov r3, #0 */
/* @0x1f6304 mov r2, #5 */
/* @0x1f6308 str r3, [r4, #0x20] */
/* @0x1f630c str r3, [r4, #0x18] */
/* @0x1f6310 str r2, [r4, #0x24] */
/* @0x1f6314 pop {r4, pc} */
/* @0x1f6318 add r0, r4, #8 */
/* @0x1f631c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6320 b 0x1f62cc <_ZN13CVariableList6RemoveEP9RVariable+0x70> */
/* @0x1f6324 cmp r2, #0 */
/* @0x1f6328 ldrne r3, [r4] */
/* @0x1f632c strne r3, [r2] */
/* @0x1f6330 bne 0x1f62a0 <_ZN13CVariableList6RemoveEP9RVariable+0x44> */
/* @0x1f6334 mov r2, r4 */
/* @0x1f6338 ldr r3, [r2] */
/* @0x1f633c str r3, [r0, #0x4] */
/* @0x1f6340 b 0x1f62a0 <_ZN13CVariableList6RemoveEP9RVariable+0x44> */
/* @0x1f6344 cmp r1, r2 */
/* @0x1f6348 bne 0x1f62a0 <_ZN13CVariableList6RemoveEP9RVariable+0x44> */
/* @0x1f634c b 0x1f6338 <_ZN13CVariableList6RemoveEP9RVariable+0xdc> */
/* @0x1f6350 andseq r10, pc, r8, lsl #23 */

/* ── FUNC 0x1f6354 · CVariableList::Free(RVariable*) · size=584 · insn=146 */
/* @0x1f6354 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f6358 mov r5, r0 */
/* @0x1f635c ldr r3, [pc, #0x234] */
/* @0x1f6360 ldr r1, [r0, #0x14] */
/* @0x1f6364 ldr r3, [pc, r3] */
/* @0x1f6368 sub r1, r1, #1 */
/* @0x1f636c bic r1, r1, #-16777216 */
/* @0x1f6370 ldr r2, [r3] */
/* @0x1f6374 bic r1, r1, #3 */
/* @0x1f6378 str r0, [r3] */
/* @0x1f637c cmp r1, #0 */
/* @0x1f6380 str r2, [r0, #0x4] */
/* @0x1f6384 beq 0x1f6418 <_ZN13CVariableList4FreeEP9RVariable+0xc4> */
/* @0x1f6388 ldr r1, [r5, #0x24] */
/* @0x1f638c mov r2, #0 */
/* @0x1f6390 mov r0, #5 */
/* @0x1f6394 str r2, [r5, #0x10] */
/* @0x1f6398 sub r3, r1, #1 */
/* @0x1f639c str r2, [r5, #0x8] */
/* @0x1f63a0 bic r3, r3, #-16777216 */
/* @0x1f63a4 str r0, [r5, #0x14] */
/* @0x1f63a8 bics r4, r3, #3 */
/* @0x1f63ac beq 0x1f63c8 <_ZN13CVariableList4FreeEP9RVariable+0x74> */
/* @0x1f63b0 mov r3, #0 */
/* @0x1f63b4 mov r2, #5 */
/* @0x1f63b8 str r3, [r5, #0x20] */
/* @0x1f63bc str r3, [r5, #0x18] */
/* @0x1f63c0 str r2, [r5, #0x24] */
/* @0x1f63c4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f63c8 bic r1, r1, #-16777216 */
/* @0x1f63cc cmp r1, #2 */
/* @0x1f63d0 beq 0x1f644c <_ZN13CVariableList4FreeEP9RVariable+0xf8> */
/* @0x1f63d4 cmp r1, #3 */
/* @0x1f63d8 beq 0x1f6424 <_ZN13CVariableList4FreeEP9RVariable+0xd0> */
/* @0x1f63dc cmp r1, #1 */
/* @0x1f63e0 bne 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f63e4 ldr r4, [r5, #0x18] */
/* @0x1f63e8 cmp r4, #0 */
/* @0x1f63ec beq 0x1f640c <_ZN13CVariableList4FreeEP9RVariable+0xb8> */
/* @0x1f63f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f63f4 ldr r6, [r4, #0x4] */
/* @0x1f63f8 sub r6, r6, #1 */
/* @0x1f63fc str r6, [r4, #0x4] */
/* @0x1f6400 cmp r6, #0 */
/* @0x1f6404 beq 0x1f6488 <_ZN13CVariableList4FreeEP9RVariable+0x134> */
/* @0x1f6408 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f640c mov r3, #0 */
/* @0x1f6410 str r3, [r5, #0x18] */
/* @0x1f6414 b 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f6418 add r0, r0, #8 */
/* @0x1f641c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f6420 b 0x1f6388 <_ZN13CVariableList4FreeEP9RVariable+0x34> */
/* @0x1f6424 ldr r3, [r5, #0x20] */
/* @0x1f6428 tst r3, #8 */
/* @0x1f642c beq 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f6430 ldr r0, [r5, #0x18] */
/* @0x1f6434 cmp r0, #0 */
/* @0x1f6438 beq 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f643c ldr r3, [r0] */
/* @0x1f6440 ldr r3, [r3, #0x4] */
/* @0x1f6444 blx r3 */
/* @0x1f6448 b 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f644c ldr r8, [r5, #0x18] */
/* @0x1f6450 cmp r8, #0 */
/* @0x1f6454 beq 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f6458 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f645c ldr r3, [r8] */
/* @0x1f6460 ldr r1, [r8, #0x8] */
/* @0x1f6464 add r2, r5, #24 */
/* @0x1f6468 sub r3, r3, #1 */
/* @0x1f646c str r3, [r8] */
/* @0x1f6470 cmp r1, r2 */
/* @0x1f6474 streq r4, [r8, #0x8] */
/* @0x1f6478 cmp r3, #0 */
/* @0x1f647c ble 0x1f64c0 <_ZN13CVariableList4FreeEP9RVariable+0x16c> */
/* @0x1f6480 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f6484 b 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c> */
/* @0x1f6488 ldr r0, [r4] */
/* @0x1f648c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f6490 str r6, [r4] */
/* @0x1f6494 str r6, [r4, #0x8] */
/* @0x1f6498 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1f649c ldr r6, [r4, #0x4] */
/* @0x1f64a0 sub r6, r6, #1 */
/* @0x1f64a4 str r6, [r4, #0x4] */
/* @0x1f64a8 cmp r6, #0 */
/* @0x1f64ac beq 0x1f6574 <_ZN13CVariableList4FreeEP9RVariable+0x220> */
/* @0x1f64b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1f64b4 mov r0, r4 */
/* @0x1f64b8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f64bc b 0x1f6408 <_ZN13CVariableList4FreeEP9RVariable+0xb4> */
/* @0x1f64c0 ldr r3, [r8, #0x10] */
/* @0x1f64c4 cmp r3, #0 */
/* @0x1f64c8 movgt r7, #0 */
/* @0x1f64cc movgt r11, #5 */
/* @0x1f64d0 movgt r6, r7 */
/* @0x1f64d4 ble 0x1f654c <_ZN13CVariableList4FreeEP9RVariable+0x1f8> */
/* @0x1f64d8 ldr r3, [r8, #0x4] */
/* @0x1f64dc add r9, r3, r7, lsl #3 */
/* @0x1f64e0 ldr r10, [r3, r7, lsl #3] */
/* @0x1f64e4 ldr r4, [r9, #0x4] */
/* @0x1f64e8 add r10, r4, r10, lsl #4 */
/* @0x1f64ec cmp r4, r10 */
/* @0x1f64f0 blo 0x1f650c <_ZN13CVariableList4FreeEP9RVariable+0x1b8> */
/* @0x1f64f4 b 0x1f656c <_ZN13CVariableList4FreeEP9RVariable+0x218> */
/* @0x1f64f8 str r6, [r4, #0x8] */
/* @0x1f64fc str r11, [r4, #0xc] */
/* @0x1f6500 str r6, [r4], #16 */
/* @0x1f6504 cmp r10, r4 */
/* @0x1f6508 bls 0x1f6530 <_ZN13CVariableList4FreeEP9RVariable+0x1dc> */
/* @0x1f650c ldr r3, [r4, #0xc] */
/* @0x1f6510 sub r3, r3, #1 */
/* @0x1f6514 bic r3, r3, #-16777216 */
/* @0x1f6518 bic r3, r3, #3 */
/* @0x1f651c cmp r3, #0 */
/* @0x1f6520 bne 0x1f64f8 <_ZN13CVariableList4FreeEP9RVariable+0x1a4> */
/* @0x1f6524 mov r0, r4 */
/* @0x1f6528 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1f652c b 0x1f64f8 <_ZN13CVariableList4FreeEP9RVariable+0x1a4> */
/* @0x1f6530 ldr r0, [r9, #0x4] */
/* @0x1f6534 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1f6538 ldr r3, [r8, #0x10] */
/* @0x1f653c add r7, r7, #1 */
/* @0x1f6540 str r6, [r9, #0x4] */
/* @0x1f6544 cmp r7, r3 */
/* @0x1f6548 blt 0x1f64d8 <_ZN13CVariableList4FreeEP9RVariable+0x184> */
/* @0x1f654c ldr r0, [r8, #0x4] */
/* @0x1f6550 mov r4, #0 */
/* @0x1f6554 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1f6558 str r4, [r8, #0x4] */
/* @0x1f655c mov r0, r8 */
/* @0x1f6560 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1f6564 str r4, [r5, #0x18] */
/* @0x1f6568 b 0x1f6480 <_ZN13CVariableList4FreeEP9RVariable+0x12c> */
/* @0x1f656c mov r0, r4 */
/* @0x1f6570 b 0x1f6534 <_ZN13CVariableList4FreeEP9RVariable+0x1e0> */
/* @0x1f6574 ldr r0, [r4] */
/* @0x1f6578 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1f657c mov r0, r4 */
/* @0x1f6580 str r6, [r4] */
/* @0x1f6584 str r6, [r4, #0x8] */
/* @0x1f6588 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1f658c mov r0, r4 */
/* @0x1f6590 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6594 b 0x1f64b0 <_ZN13CVariableList4FreeEP9RVariable+0x15c> */
/* @0x1f6598 ldrsbeq r10, [pc], -r0 */

/* ── FUNC 0x1f659c · FreeRange(CVariableList&) · size=144 · insn=36 */
/* @0x1f659c push {r4, r5, r6, lr} */
/* @0x1f65a0 adds r4, r0, #4 */
/* @0x1f65a4 addne r4, r0, #20 */
/* @0x1f65a8 beq 0x1f6608 <_Z9FreeRangeR13CVariableList+0x6c> */
/* @0x1f65ac cmp r4, r0 */
/* @0x1f65b0 add r6, r0, #4 */
/* @0x1f65b4 beq 0x1f65c0 <_Z9FreeRangeR13CVariableList+0x24> */
/* @0x1f65b8 cmp r4, r6 */
/* @0x1f65bc bne 0x1f6614 <_Z9FreeRangeR13CVariableList+0x78> */
/* @0x1f65c0 mov r6, r4 */
/* @0x1f65c4 mov r5, #0 */
/* @0x1f65c8 cmp r5, #0 */
/* @0x1f65cc beq 0x1f6604 <_Z9FreeRangeR13CVariableList+0x68> */
/* @0x1f65d0 mov r0, r5 */
/* @0x1f65d4 bl 0x1f6354 <_ZN13CVariableList4FreeEP9RVariable> */
/* @0x1f65d8 ldr r5, [r5] */
/* @0x1f65dc cmp r5, #0 */
/* @0x1f65e0 add r3, r6, #4 */
/* @0x1f65e4 bne 0x1f65c8 <_Z9FreeRangeR13CVariableList+0x2c> */
/* @0x1f65e8 cmp r4, r6 */
/* @0x1f65ec beq 0x1f6628 <_Z9FreeRangeR13CVariableList+0x8c> */
/* @0x1f65f0 cmp r3, r4 */
/* @0x1f65f4 popeq {r4, r5, r6, pc} */
/* @0x1f65f8 ldr r5, [r6, #0x4] */
/* @0x1f65fc mov r6, r3 */
/* @0x1f6600 b 0x1f65dc <_Z9FreeRangeR13CVariableList+0x40> */
/* @0x1f6604 pop {r4, r5, r6, pc} */
/* @0x1f6608 mov r6, r4 */
/* @0x1f660c mov r5, r4 */
/* @0x1f6610 b 0x1f65c8 <_Z9FreeRangeR13CVariableList+0x2c> */
/* @0x1f6614 ldr r5, [r0, #0x4] */
/* @0x1f6618 cmp r5, #0 */
/* @0x1f661c bne 0x1f65c8 <_Z9FreeRangeR13CVariableList+0x2c> */
/* @0x1f6620 mov r0, r6 */
/* @0x1f6624 b 0x1f65ac <_Z9FreeRangeR13CVariableList+0x10> */
/* @0x1f6628 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1f662c · CVariableList::Clear() · size=44 · insn=11 */
/* @0x1f662c push {r4, lr} */
/* @0x1f6630 mov r4, r0 */
/* @0x1f6634 bl 0x1f659c <_Z9FreeRangeR13CVariableList> */
/* @0x1f6638 add r0, r4, #4 */
/* @0x1f663c mov r1, #0 */
/* @0x1f6640 mov r2, #16 */
/* @0x1f6644 bl 0xb65b0 <memset@plt> */
/* @0x1f6648 mov r3, #0 */
/* @0x1f664c str r3, [r4, #0x18] */
/* @0x1f6650 str r3, [r4, #0x14] */
/* @0x1f6654 pop {r4, pc} */

/* ── FUNC 0x1f6658 · CVariableList::~CVariableList() · size=40 · insn=10 */
/* @0x1f6658 ldr r3, [pc, #0x1c] */
/* @0x1f665c push {r4, lr} */
/* @0x1f6660 ldr r3, [pc, r3] */
/* @0x1f6664 mov r4, r0 */
/* @0x1f6668 add r3, r3, #8 */
/* @0x1f666c str r3, [r0] */
/* @0x1f6670 bl 0x1f662c <_ZN13CVariableList5ClearEv> */
/* @0x1f6674 mov r0, r4 */
/* @0x1f6678 pop {r4, pc} */
/* @0x1f667c ldrsbeq r10, [pc], -r8 */

/* ── FUNC 0x1f6658 · CVariableList::~CVariableList() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f6680 · CVariableList::~CVariableList() · size=28 · insn=7 */
/* @0x1f6680 push {r4, lr} */
/* @0x1f6684 mov r4, r0 */
/* @0x1f6688 bl 0x1f6658 <_ZN13CVariableListD2Ev> */
/* @0x1f668c mov r0, r4 */
/* @0x1f6690 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f6694 mov r0, r4 */
/* @0x1f6698 pop {r4, pc} */
