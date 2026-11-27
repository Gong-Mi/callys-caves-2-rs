/* libyoyo.so 覆盖卡组 0123
 * 函数 0x188b90..0x18b348，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x188b90 · Shader_Set_Uniform_B(int, int, double, double, double, double) · size=276 · insn=69 */
/* @0x188b90 ldr r12, [pc, #0x104] */
/* @0x188b94 push {r4, lr} */
/* @0x188b98 vpush {d8} */
/* @0x188b9c ldr r12, [pc, r12] */
/* @0x188ba0 vmov d8, r2, r3 */
/* @0x188ba4 sub sp, sp, #24 */
/* @0x188ba8 ldr r3, [r12] */
/* @0x188bac mov r4, r0 */
/* @0x188bb0 cmp r3, #1 */
/* @0x188bb4 beq 0x188bc8 <_Z20Shader_Set_Uniform_Biidddd+0x38> */
/* @0x188bb8 mov r0, #0 */
/* @0x188bbc add sp, sp, #24 */
/* @0x188bc0 vpop {d8} */
/* @0x188bc4 pop {r4, pc} */
/* @0x188bc8 cmp r0, #0 */
/* @0x188bcc blt 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28> */
/* @0x188bd0 ldr r3, [pc, #0xc8] */
/* @0x188bd4 ldr r3, [pc, r3] */
/* @0x188bd8 ldr r3, [r3] */
/* @0x188bdc cmp r3, #0 */
/* @0x188be0 beq 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28> */
/* @0x188be4 ldr r0, [r3, #0x64] */
/* @0x188be8 str r1, [sp, #0x4] */
/* @0x188bec bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188bf0 ldr r1, [sp, #0x4] */
/* @0x188bf4 cmp r0, #0 */
/* @0x188bf8 beq 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28> */
/* @0x188bfc ldr r3, [r0, #0x7c] */
/* @0x188c00 cmp r4, r3 */
/* @0x188c04 bge 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28> */
/* @0x188c08 ldr r3, [r0, #0x78] */
/* @0x188c0c rsb r4, r4, r4, lsl #3 */
/* @0x188c10 adds r4, r3, r4, lsl #2 */
/* @0x188c14 beq 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28> */
/* @0x188c18 vcvt.s32.f64 s16, d8 */
/* @0x188c1c ldr r2, [r4, #0xc] */
/* @0x188c20 mov r3, #0 */
/* @0x188c24 str r3, [sp, #0x14] */
/* @0x188c28 cmp r1, r2 */
/* @0x188c2c movge r1, r2 */
/* @0x188c30 str r3, [sp, #0x10] */
/* @0x188c34 cmp r1, #1 */
/* @0x188c38 strle r3, [sp, #0xc] */
/* @0x188c3c vstr s16, [sp, #8] */
/* @0x188c40 ble 0x188c7c <_Z20Shader_Set_Uniform_Biidddd+0xec> */
/* @0x188c44 vldr d7, [sp, #40] */
/* @0x188c48 vcvt.s32.f64 s15, d7 */
/* @0x188c4c cmp r1, #2 */
/* @0x188c50 vstr s15, [sp, #12] */
/* @0x188c54 beq 0x188c7c <_Z20Shader_Set_Uniform_Biidddd+0xec> */
/* @0x188c58 vldr d7, [sp, #48] */
/* @0x188c5c vcvt.s32.f64 s15, d7 */
/* @0x188c60 cmp r1, #3 */
/* @0x188c64 vmov r3, s15 */
/* @0x188c68 vstr s15, [sp, #16] */
/* @0x188c6c vldrne d7, [sp, #56] */
/* @0x188c70 vcvtne.s32.f64 s15, d7 */
/* @0x188c74 vmovne r3, s15 */
/* @0x188c78 strne r3, [sp, #0x14] */
/* @0x188c7c ldr r0, [r4, #0x4] */
/* @0x188c80 mov r2, #1 */
/* @0x188c84 add r3, sp, #8 */
/* @0x188c88 bl 0x188200 <_Z20Shader_Set_Uniform_IiiiPi> */
/* @0x188c8c mov r0, #1 */
/* @0x188c90 add sp, sp, #24 */
/* @0x188c94 vpop {d8} */
/* @0x188c98 pop {r4, pc} */
/* @0x188c9c eoreq r7, r6, r12, ror #16 */
/* @0x188ca0 eoreq r7, r6, r4, lsr #17 */

/* ── FUNC 0x188ca4 · GraphicsRecorder::~GraphicsRecorder() · size=68 · insn=17 */
/* @0x188ca4 push {r4, lr} */
/* @0x188ca8 mov r4, r0 */
/* @0x188cac bl 0x1857d8 <_ZN16GraphicsRecorder15DeleteHWBuffersEv> */
/* @0x188cb0 ldr r0, [r4, #0x14] */
/* @0x188cb4 cmp r0, #0 */
/* @0x188cb8 beq 0x188cc0 <_ZN16GraphicsRecorderD2Ev+0x1c> */
/* @0x188cbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x188cc0 ldr r0, [r4, #0x24] */
/* @0x188cc4 cmp r0, #0 */
/* @0x188cc8 beq 0x188cd0 <_ZN16GraphicsRecorderD2Ev+0x2c> */
/* @0x188ccc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x188cd0 ldr r0, [r4, #0x34] */
/* @0x188cd4 cmp r0, #0 */
/* @0x188cd8 beq 0x188ce0 <_ZN16GraphicsRecorderD2Ev+0x3c> */
/* @0x188cdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x188ce0 mov r0, r4 */
/* @0x188ce4 pop {r4, pc} */

/* ── FUNC 0x188ca4 · GraphicsRecorder::~GraphicsRecorder() · alias of the symbol above · insn=0 */

/* ── FUNC 0x188ce8 · GraphicsRecorder::Reset() · size=4 · insn=1 */
/* @0x188ce8 bx lr */

/* ── FUNC 0x188cec · GraphicsRecorder::ReAllocVerts(SVertexNormal_Float*, int&, int&, int) · size=316 · insn=79 */
/* @0x188cec push {r3, r4, r5, r6, r7, lr} */
/* @0x188cf0 mov r7, r1 */
/* @0x188cf4 ldr r4, [sp, #0x18] */
/* @0x188cf8 mov r6, r2 */
/* @0x188cfc mov r5, r3 */
/* @0x188d00 cmp r4, #0 */
/* @0x188d04 beq 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8> */
/* @0x188d08 cmn r4, #1 */
/* @0x188d0c ldr r3, [r3] */
/* @0x188d10 beq 0x188dbc <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xd0> */
/* @0x188d14 ldr r12, [r2] */
/* @0x188d18 add r3, r4, r3 */
/* @0x188d1c cmp r12, r3 */
/* @0x188d20 strge r3, [r5] */
/* @0x188d24 bge 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8> */
/* @0x188d28 cmp r12, #0 */
/* @0x188d2c bne 0x188d48 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x5c> */
/* @0x188d30 str r4, [r2] */
/* @0x188d34 mov r12, r4 */
/* @0x188d38 ldr r3, [r5] */
/* @0x188d3c add r3, r4, r3 */
/* @0x188d40 cmp r4, r3 */
/* @0x188d44 bge 0x188d60 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x74> */
/* @0x188d48 lsl r12, r12, #1 */
/* @0x188d4c str r12, [r6] */
/* @0x188d50 ldr r3, [r5] */
/* @0x188d54 add r3, r4, r3 */
/* @0x188d58 cmp r12, r3 */
/* @0x188d5c blt 0x188d48 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x5c> */
/* @0x188d60 add r0, r12, r12, lsl #3 */
/* @0x188d64 ldr r1, [pc, #0xb4] */
/* @0x188d68 mov r2, #91 */
/* @0x188d6c mov r3, #0 */
/* @0x188d70 add r1, pc, r1 */
/* @0x188d74 lsl r0, r0, #2 */
/* @0x188d78 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x188d7c cmp r7, #0 */
/* @0x188d80 mov r6, r0 */
/* @0x188d84 beq 0x188da4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xb8> */
/* @0x188d88 ldr r3, [r5] */
/* @0x188d8c mov r1, r7 */
/* @0x188d90 add r2, r3, r3, lsl #3 */
/* @0x188d94 lsl r2, r2, #2 */
/* @0x188d98 bl 0xb65bc <memcpy@plt> */
/* @0x188d9c mov r0, r7 */
/* @0x188da0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x188da4 ldr r3, [r5] */
/* @0x188da8 mov r7, r6 */
/* @0x188dac add r4, r3, r4 */
/* @0x188db0 str r4, [r5] */
/* @0x188db4 mov r0, r7 */
/* @0x188db8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x188dbc ldr r2, [r2] */
/* @0x188dc0 cmp r2, r3 */
/* @0x188dc4 beq 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8> */
/* @0x188dc8 add r0, r3, r3, lsl #3 */
/* @0x188dcc ldr r1, [pc, #0x50] */
/* @0x188dd0 mov r3, #0 */
/* @0x188dd4 mov r2, #71 */
/* @0x188dd8 add r1, pc, r1 */
/* @0x188ddc lsl r0, r0, #2 */
/* @0x188de0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x188de4 ldr r3, [r5] */
/* @0x188de8 cmp r3, #0 */
/* @0x188dec mov r4, r0 */
/* @0x188df0 ble 0x188e10 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x124> */
/* @0x188df4 add r2, r3, r3, lsl #3 */
/* @0x188df8 mov r1, r7 */
/* @0x188dfc lsl r2, r2, #2 */
/* @0x188e00 bl 0xb65bc <memcpy@plt> */
/* @0x188e04 mov r0, r7 */
/* @0x188e08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x188e0c ldr r3, [r5] */
/* @0x188e10 mov r7, r4 */
/* @0x188e14 str r3, [r6] */
/* @0x188e18 mov r0, r7 */
/* @0x188e1c pop {r3, r4, r5, r6, r7, pc} */
/* @0x188e20 andseq r3, r12, r12, ror #5 */
/* @0x188e24 andseq r3, r12, r4, lsl #5 */

/* ── FUNC 0x188e28 · GraphicsRecorder::AddPrims(ePrimType, int, void*) · size=760 · insn=190 */
/* @0x188e28 sub r1, r1, #2 */
/* @0x188e2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x188e30 mov r4, r0 */
/* @0x188e34 sub sp, sp, #28 */
/* @0x188e38 mov r5, r2 */
/* @0x188e3c mov r9, r3 */
/* @0x188e40 cmp r1, #4 */
/* @0x188e44 addls pc, pc, r1, lsl #2 */
/* @0x188e48 b 0x1890f8 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x2d0> */
/* @0x188e4c b 0x188f28 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x100> */
/* @0x188e50 b 0x189094 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x26c> */
/* @0x188e54 b 0x188f64 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x13c> */
/* @0x188e58 b 0x188f8c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x164> */
/* @0x188e5c b 0x188e60 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x38> */
/* @0x188e60 sub r3, r2, #2 */
/* @0x188e64 ldr r6, [r0, #0x1c] */
/* @0x188e68 ldr r1, [r0, #0x14] */
/* @0x188e6c add r2, r4, #32 */
/* @0x188e70 add r3, r3, r3, lsl #1 */
/* @0x188e74 str r3, [sp] */
/* @0x188e78 add r3, r4, #28 */
/* @0x188e7c add r6, r6, r6, lsl #3 */
/* @0x188e80 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x188e84 cmp r5, #2 */
/* @0x188e88 str r0, [r4, #0x14] */
/* @0x188e8c add r10, r0, r6, lsl #2 */
/* @0x188e90 ble 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8> */
/* @0x188e94 add r5, r5, r5, lsl #3 */
/* @0x188e98 mov r11, r9 */
/* @0x188e9c str r9, [sp, #0x14] */
/* @0x188ea0 add r5, r9, r5, lsl #2 */
/* @0x188ea4 sub r5, r5, #72 */
/* @0x188ea8 str r5, [sp, #0x10] */
/* @0x188eac ldr r8, [sp, #0x14] */
/* @0x188eb0 mov r7, r10 */
/* @0x188eb4 add r6, r11, #36 */
/* @0x188eb8 ldr r9, [sp, #0x10] */
/* @0x188ebc add r4, r11, #72 */
/* @0x188ec0 add r5, r10, #36 */
/* @0x188ec4 ldm r8!, {r0, r1, r2, r3} */
/* @0x188ec8 mov r11, r6 */
/* @0x188ecc cmp r6, r9 */
/* @0x188ed0 add r12, r10, #72 */
/* @0x188ed4 add r10, r10, #108 */
/* @0x188ed8 stm r7!, {r0, r1, r2, r3} */
/* @0x188edc ldm r8!, {r0, r1, r2, r3} */
/* @0x188ee0 stm r7!, {r0, r1, r2, r3} */
/* @0x188ee4 ldr r3, [r8] */
/* @0x188ee8 str r3, [r7] */
/* @0x188eec ldm r6!, {r0, r1, r2, r3} */
/* @0x188ef0 stm r5!, {r0, r1, r2, r3} */
/* @0x188ef4 ldm r6!, {r0, r1, r2, r3} */
/* @0x188ef8 stm r5!, {r0, r1, r2, r3} */
/* @0x188efc ldr r3, [r6] */
/* @0x188f00 str r3, [r5] */
/* @0x188f04 ldm r4!, {r0, r1, r2, r3} */
/* @0x188f08 stm r12!, {r0, r1, r2, r3} */
/* @0x188f0c ldm r4!, {r0, r1, r2, r3} */
/* @0x188f10 stm r12!, {r0, r1, r2, r3} */
/* @0x188f14 ldr r3, [r4] */
/* @0x188f18 str r3, [r12] */
/* @0x188f1c bne 0x188eac <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x84> */
/* @0x188f20 add sp, sp, #28 */
/* @0x188f24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x188f28 ldr r6, [r4, #0x2c] */
/* @0x188f2c add r2, r4, #48 */
/* @0x188f30 ldr r1, [r0, #0x24] */
/* @0x188f34 add r3, r4, #44 */
/* @0x188f38 str r5, [sp] */
/* @0x188f3c bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x188f40 add r6, r6, r6, lsl #3 */
/* @0x188f44 add r2, r5, r5, lsl #3 */
/* @0x188f48 str r0, [r4, #0x24] */
/* @0x188f4c mov r1, r9 */
/* @0x188f50 lsl r2, r2, #2 */
/* @0x188f54 add r0, r0, r6, lsl #2 */
/* @0x188f58 add sp, sp, #28 */
/* @0x188f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x188f60 b 0xb65bc <memcpy@plt> */
/* @0x188f64 ldr r6, [r4, #0x1c] */
/* @0x188f68 add r2, r4, #32 */
/* @0x188f6c ldr r1, [r0, #0x14] */
/* @0x188f70 add r3, r4, #28 */
/* @0x188f74 str r5, [sp] */
/* @0x188f78 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x188f7c add r6, r6, r6, lsl #3 */
/* @0x188f80 add r2, r5, r5, lsl #3 */
/* @0x188f84 str r0, [r4, #0x14] */
/* @0x188f88 b 0x188f4c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x124> */
/* @0x188f8c sub r5, r2, #2 */
/* @0x188f90 str r5, [sp, #0x14] */
/* @0x188f94 ldr r12, [sp, #0x14] */
/* @0x188f98 add r2, r4, #32 */
/* @0x188f9c ldr r5, [r0, #0x1c] */
/* @0x188fa0 ldr r1, [r0, #0x14] */
/* @0x188fa4 add r3, r12, r12, lsl #1 */
/* @0x188fa8 str r3, [sp] */
/* @0x188fac add r3, r4, #28 */
/* @0x188fb0 add r5, r5, r5, lsl #3 */
/* @0x188fb4 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x188fb8 ldr r12, [sp, #0x14] */
/* @0x188fbc cmp r12, #0 */
/* @0x188fc0 str r0, [r4, #0x14] */
/* @0x188fc4 add r10, r0, r5, lsl #2 */
/* @0x188fc8 ble 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8> */
/* @0x188fcc mov r12, #0 */
/* @0x188fd0 mov r3, r9 */
/* @0x188fd4 str r12, [sp, #0x10] */
/* @0x188fd8 mov r9, r12 */
/* @0x188fdc b 0x18904c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x224> */
/* @0x188fe0 ldm r8!, {r0, r1, r2, r3} */
/* @0x188fe4 stm r7!, {r0, r1, r2, r3} */
/* @0x188fe8 ldm r8!, {r0, r1, r2, r3} */
/* @0x188fec stm r7!, {r0, r1, r2, r3} */
/* @0x188ff0 ldr r3, [r8] */
/* @0x188ff4 str r3, [r7] */
/* @0x188ff8 ldm r6!, {r0, r1, r2, r3} */
/* @0x188ffc stm r5!, {r0, r1, r2, r3} */
/* @0x189000 ldm r6!, {r0, r1, r2, r3} */
/* @0x189004 stm r5!, {r0, r1, r2, r3} */
/* @0x189008 ldr r3, [r6] */
/* @0x18900c str r3, [r5] */
/* @0x189010 ldm r4!, {r0, r1, r2, r3} */
/* @0x189014 stm r12!, {r0, r1, r2, r3} */
/* @0x189018 ldm r4!, {r0, r1, r2, r3} */
/* @0x18901c stm r12!, {r0, r1, r2, r3} */
/* @0x189020 ldr r3, [r4] */
/* @0x189024 str r3, [r12] */
/* @0x189028 ldr r12, [sp, #0x10] */
/* @0x18902c add r9, r9, #1 */
/* @0x189030 add r10, r10, #108 */
/* @0x189034 mov r3, r11 */
/* @0x189038 eor r12, r12, #1 */
/* @0x18903c str r12, [sp, #0x10] */
/* @0x189040 ldr r12, [sp, #0x14] */
/* @0x189044 cmp r9, r12 */
/* @0x189048 beq 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8> */
/* @0x18904c ldr r2, [sp, #0x10] */
/* @0x189050 add r11, r3, #36 */
/* @0x189054 add r8, r3, #72 */
/* @0x189058 mov r7, r10 */
/* @0x18905c cmp r2, #0 */
/* @0x189060 add r5, r10, #36 */
/* @0x189064 mov r4, r3 */
/* @0x189068 add r12, r10, #72 */
/* @0x18906c mov r6, r11 */
/* @0x189070 bne 0x188fe0 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x1b8> */
/* @0x189074 mov r1, r3 */
/* @0x189078 mov r0, r10 */
/* @0x18907c mov r2, #108 */
/* @0x189080 str r3, [sp, #0xc] */
/* @0x189084 bl 0xb65bc <memcpy@plt> */
/* @0x189088 ldr r3, [sp, #0xc] */
/* @0x18908c add r11, r3, #36 */
/* @0x189090 b 0x189028 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x200> */
/* @0x189094 sub r5, r2, #1 */
/* @0x189098 ldr r6, [r0, #0x2c] */
/* @0x18909c ldr r1, [r0, #0x24] */
/* @0x1890a0 add r2, r4, #48 */
/* @0x1890a4 lsl r3, r5, #1 */
/* @0x1890a8 str r3, [sp] */
/* @0x1890ac add r3, r4, #44 */
/* @0x1890b0 add r6, r6, r6, lsl #3 */
/* @0x1890b4 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x1890b8 cmp r5, #0 */
/* @0x1890bc str r0, [r4, #0x24] */
/* @0x1890c0 add r3, r0, r6, lsl #2 */
/* @0x1890c4 ble 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8> */
/* @0x1890c8 mov r4, #0 */
/* @0x1890cc mov r0, r3 */
/* @0x1890d0 mov r1, r9 */
/* @0x1890d4 mov r2, #72 */
/* @0x1890d8 add r4, r4, #1 */
/* @0x1890dc bl 0xb65bc <memcpy@plt> */
/* @0x1890e0 cmp r4, r5 */
/* @0x1890e4 add r9, r9, #36 */
/* @0x1890e8 add r3, r0, #72 */
/* @0x1890ec bne 0x1890cc <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x2a4> */
/* @0x1890f0 add sp, sp, #28 */
/* @0x1890f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1890f8 ldr r6, [r4, #0x3c] */
/* @0x1890fc add r2, r4, #64 */
/* @0x189100 ldr r1, [r0, #0x34] */
/* @0x189104 add r3, r4, #60 */
/* @0x189108 str r5, [sp] */
/* @0x18910c bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x189110 add r6, r6, r6, lsl #3 */
/* @0x189114 add r2, r5, r5, lsl #3 */
/* @0x189118 str r0, [r4, #0x34] */
/* @0x18911c b 0x188f4c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x124> */

/* ── FUNC 0x189120 · GraphicsRecorder::ChangeColour(unsigned int) · size=180 · insn=45 */
/* @0x189120 push {r3, r4, r5, lr} */
/* @0x189124 mov r4, r0 */
/* @0x189128 ldr r3, [r0, #0x8] */
/* @0x18912c ands r12, r3, #1 */
/* @0x189130 popne {r3, r4, r5, pc} */
/* @0x189134 ldr r0, [r0, #0x1c] */
/* @0x189138 bic r5, r1, #1 */
/* @0x18913c ldr r2, [r4, #0x14] */
/* @0x189140 cmp r0, #0 */
/* @0x189144 ble 0x189164 <_ZN16GraphicsRecorder12ChangeColourEj+0x44> */
/* @0x189148 ldr lr, [r2, #0x18] */
/* @0x18914c add r12, r12, #1 */
/* @0x189150 add r2, r2, #36 */
/* @0x189154 cmp r3, lr */
/* @0x189158 streq r5, [r2, #-0xc] */
/* @0x18915c cmp r12, r0 */
/* @0x189160 bne 0x189148 <_ZN16GraphicsRecorder12ChangeColourEj+0x28> */
/* @0x189164 ldr r1, [r4, #0x2c] */
/* @0x189168 ldr r2, [r4, #0x24] */
/* @0x18916c cmp r1, #0 */
/* @0x189170 movgt r12, #0 */
/* @0x189174 ble 0x189194 <_ZN16GraphicsRecorder12ChangeColourEj+0x74> */
/* @0x189178 ldr lr, [r2, #0x18] */
/* @0x18917c add r12, r12, #1 */
/* @0x189180 add r2, r2, #36 */
/* @0x189184 cmp r3, lr */
/* @0x189188 streq r5, [r2, #-0xc] */
/* @0x18918c cmp r12, r1 */
/* @0x189190 bne 0x189178 <_ZN16GraphicsRecorder12ChangeColourEj+0x58> */
/* @0x189194 ldr r1, [r4, #0x3c] */
/* @0x189198 ldr r2, [r4, #0x34] */
/* @0x18919c cmp r1, #0 */
/* @0x1891a0 movgt r12, #0 */
/* @0x1891a4 ble 0x1891c4 <_ZN16GraphicsRecorder12ChangeColourEj+0xa4> */
/* @0x1891a8 ldr lr, [r2, #0x18] */
/* @0x1891ac add r12, r12, #1 */
/* @0x1891b0 add r2, r2, #36 */
/* @0x1891b4 cmp r3, lr */
/* @0x1891b8 streq r5, [r2, #-0xc] */
/* @0x1891bc cmp r12, r1 */
/* @0x1891c0 bne 0x1891a8 <_ZN16GraphicsRecorder12ChangeColourEj+0x88> */
/* @0x1891c4 mov r0, r4 */
/* @0x1891c8 bl 0x1857d8 <_ZN16GraphicsRecorder15DeleteHWBuffersEv> */
/* @0x1891cc str r5, [r4, #0x8] */
/* @0x1891d0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x1891d4 · anon_1891d4 · size=100 · insn=26 */
/* @0x1891d4 push {r4, r5, r6, lr} */
/* @0x1891d8 mov r6, r1 */
/* @0x1891dc mov r5, r2 */
/* @0x1891e0 blx 0x2a5f20 <png_get_io_ptr> */
/* @0x1891e4 mov r2, r5 */
/* @0x1891e8 mov r4, r0 */
/* @0x1891ec mov r0, r6 */
/* @0x1891f0 ldr r1, [r4, #0x4] */
/* @0x1891f4 bl 0xb65bc <memcpy@plt> */
/* @0x1891f8 ldr r3, [r4, #0x4] */
/* @0x1891fc add r5, r3, r5 */
/* @0x189200 str r5, [r4, #0x4] */
/* @0x189204 pop {r4, r5, r6, pc} */
/* @0x189208 push {r4, r5, r6, lr} */
/* @0x18920c mov r6, r1 */
/* @0x189210 mov r5, r2 */
/* @0x189214 blx 0x2a5f20 <png_get_io_ptr> */
/* @0x189218 mov r2, r5 */
/* @0x18921c mov r4, r0 */
/* @0x189220 mov r0, r6 */
/* @0x189224 ldr r1, [r4, #0x4] */
/* @0x189228 bl 0xb65bc <memcpy@plt> */
/* @0x18922c ldr r3, [r4, #0x4] */
/* @0x189230 add r5, r3, r5 */
/* @0x189234 str r5, [r4, #0x4] */
/* @0x189238 pop {r4, r5, r6, pc} */

/* ── FUNC 0x18923c · HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*) · size=480 · insn=120 */
/* @0x18923c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x189240 sub sp, sp, #52 */
/* @0x189244 mov r4, r2 */
/* @0x189248 mov r11, r3 */
/* @0x18924c ldr r12, [sp, #0x58] */
/* @0x189250 str r0, [sp, #0x1c] */
/* @0x189254 str r1, [sp, #0x2c] */
/* @0x189258 lsl r0, r12, #16 */
/* @0x18925c bl 0x318d10 <__divsi3> */
/* @0x189260 ldr r2, [sp, #0x2c] */
/* @0x189264 cmp r2, #0 */
/* @0x189268 str r0, [sp, #0x24] */
/* @0x18926c ble 0x1893f4 <_Z15HalfTextureRGBAiiPjiiS_+0x1b8> */
/* @0x189270 lsl r0, r11, #16 */
/* @0x189274 ldr r1, [sp, #0x1c] */
/* @0x189278 bl 0x318d10 <__divsi3> */
/* @0x18927c ldr r2, [sp, #0x2c] */
/* @0x189280 ldr r3, [sp, #0x1c] */
/* @0x189284 str r4, [sp, #0x14] */
/* @0x189288 mul r3, r3, r2 */
/* @0x18928c ldr r2, [sp, #0x1c] */
/* @0x189290 lsl r2, r2, #2 */
/* @0x189294 str r2, [sp, #0x20] */
/* @0x189298 str r3, [sp, #0x28] */
/* @0x18929c mov r3, #0 */
/* @0x1892a0 str r3, [sp, #0x10] */
/* @0x1892a4 str r3, [sp, #0x18] */
/* @0x1892a8 str r3, [sp, #0xc] */
/* @0x1892ac str r0, [sp, #0x8] */
/* @0x1892b0 ldr r3, [sp, #0xc] */
/* @0x1892b4 ldr r2, [sp, #0x1c] */
/* @0x1892b8 asr r12, r3, #16 */
/* @0x1892bc cmp r2, #0 */
/* @0x1892c0 ldr r3, [sp, #0x5c] */
/* @0x1892c4 mul r12, r11, r12 */
/* @0x1892c8 add r12, r3, r12, lsl #2 */
/* @0x1892cc ble 0x1893c8 <_Z15HalfTextureRGBAiiPjiiS_+0x18c> */
/* @0x1892d0 ldr r3, [sp, #0x14] */
/* @0x1892d4 mov r4, #0 */
/* @0x1892d8 ldr r2, [sp, #0x20] */
/* @0x1892dc mov r5, r3 */
/* @0x1892e0 add r2, r2, r3 */
/* @0x1892e4 str r2, [sp, #0x4] */
/* @0x1892e8 asr r3, r4, #16 */
/* @0x1892ec ldr r2, [sp, #0x8] */
/* @0x1892f0 add r1, r12, r3, lsl #2 */
/* @0x1892f4 add r4, r4, r2 */
/* @0x1892f8 add r2, r3, r11 */
/* @0x1892fc ldr r1, [r1, #0x4] */
/* @0x189300 add r8, r2, #1 */
/* @0x189304 ldr r0, [r12, r2, lsl #2] */
/* @0x189308 ldr r2, [r12, r3, lsl #2] */
/* @0x18930c and r7, r1, #65280 */
/* @0x189310 ldr r3, [r12, r8, lsl #2] */
/* @0x189314 and r6, r0, #65280 */
/* @0x189318 and r8, r0, #16711680 */
/* @0x18931c add r6, r7, r6 */
/* @0x189320 and r10, r1, #16711680 */
/* @0x189324 and r7, r2, #65280 */
/* @0x189328 add r10, r10, r8 */
/* @0x18932c add r6, r6, r7 */
/* @0x189330 and r8, r2, #16711680 */
/* @0x189334 and r7, r3, #65280 */
/* @0x189338 add r10, r10, r8 */
/* @0x18933c add r6, r6, r7 */
/* @0x189340 lsr r8, r1, #8 */
/* @0x189344 lsr r7, r0, #8 */
/* @0x189348 and r8, r8, #16711680 */
/* @0x18934c and r7, r7, #16711680 */
/* @0x189350 and r9, r3, #16711680 */
/* @0x189354 add r7, r8, r7 */
/* @0x189358 lsr r8, r2, #8 */
/* @0x18935c add r9, r10, r9 */
/* @0x189360 uxtb r0, r0 */
/* @0x189364 lsr r10, r3, #8 */
/* @0x189368 and r8, r8, #16711680 */
/* @0x18936c uxtab r0, r0, r1 */
/* @0x189370 and r10, r10, #16711680 */
/* @0x189374 add r8, r7, r8 */
/* @0x189378 lsr r6, r6, #2 */
/* @0x18937c lsr r9, r9, #2 */
/* @0x189380 uxtab r0, r0, r2 */
/* @0x189384 add r10, r8, r10 */
/* @0x189388 and r6, r6, #65280 */
/* @0x18938c and r9, r9, #16711680 */
/* @0x189390 uxtab r3, r0, r3 */
/* @0x189394 orr r9, r6, r9 */
/* @0x189398 lsl r10, r10, #6 */
/* @0x18939c orr r3, r9, r3, lsr #2 */
/* @0x1893a0 and r10, r10, #-16777216 */
/* @0x1893a4 orr r3, r3, r10 */
/* @0x1893a8 str r3, [r5], #4 */
/* @0x1893ac ldr r3, [sp, #0x4] */
/* @0x1893b0 cmp r3, r5 */
/* @0x1893b4 bne 0x1892e8 <_Z15HalfTextureRGBAiiPjiiS_+0xac> */
/* @0x1893b8 ldr r2, [sp, #0x10] */
/* @0x1893bc ldr r3, [sp, #0x1c] */
/* @0x1893c0 add r2, r2, r3 */
/* @0x1893c4 str r2, [sp, #0x10] */
/* @0x1893c8 ldr r2, [sp, #0x28] */
/* @0x1893cc ldr r3, [sp, #0x10] */
/* @0x1893d0 cmp r2, r3 */
/* @0x1893d4 ldr r2, [sp, #0xc] */
/* @0x1893d8 ldr r3, [sp, #0x24] */
/* @0x1893dc add r2, r2, r3 */
/* @0x1893e0 str r2, [sp, #0xc] */
/* @0x1893e4 ldr r2, [sp, #0x18] */
/* @0x1893e8 add r2, r2, #1 */
/* @0x1893ec str r2, [sp, #0x18] */
/* @0x1893f0 bge 0x1893fc <_Z15HalfTextureRGBAiiPjiiS_+0x1c0> */
/* @0x1893f4 add sp, sp, #52 */
/* @0x1893f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1893fc ldr r3, [sp, #0x2c] */
/* @0x189400 cmp r3, r2 */
/* @0x189404 ldr r2, [sp, #0x14] */
/* @0x189408 ldr r3, [sp, #0x20] */
/* @0x18940c add r2, r2, r3 */
/* @0x189410 str r2, [sp, #0x14] */
/* @0x189414 bgt 0x1892b0 <_Z15HalfTextureRGBAiiPjiiS_+0x74> */
/* @0x189418 b 0x1893f4 <_Z15HalfTextureRGBAiiPjiiS_+0x1b8> */

/* ── FUNC 0x18941c · HalfTextureRGB(int, int, unsigned char*, int, int, unsigned char*) · size=464 · insn=116 */
/* @0x18941c ldr r12, [pc, #0x1c0] */
/* @0x189420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x189424 ldr r12, [pc, r12] */
/* @0x189428 sub sp, sp, #60 */
/* @0x18942c mov r4, r2 */
/* @0x189430 mov r5, r3 */
/* @0x189434 mov r3, r1 */
/* @0x189438 str r0, [sp, #0x18] */
/* @0x18943c add r8, r5, r5, lsl #1 */
/* @0x189440 ldr r0, [r12] */
/* @0x189444 ldr r6, [sp, #0x60] */
/* @0x189448 ldr r2, [sp, #0x18] */
/* @0x18944c ldr r12, [r0] */
/* @0x189450 ldr r9, [sp, #0x64] */
/* @0x189454 str r1, [sp, #0x30] */
/* @0x189458 add r7, r2, r2, lsl #1 */
/* @0x18945c ldr r1, [pc, #0x184] */
/* @0x189460 stm sp, {r4, r5, r6} */
/* @0x189464 add r1, pc, r1 */
/* @0x189468 str r9, [sp, #0xc] */
/* @0x18946c str r7, [sp, #0x34] */
/* @0x189470 ldr r12, [r12, #0xc] */
/* @0x189474 blx r12 */
/* @0x189478 lsl r0, r6, #16 */
/* @0x18947c ldr r1, [sp, #0x30] */
/* @0x189480 bl 0x318d10 <__divsi3> */
/* @0x189484 ldr r12, [sp, #0x30] */
/* @0x189488 cmp r12, #0 */
/* @0x18948c str r0, [sp, #0x28] */
/* @0x189490 ble 0x1895bc <_Z14HalfTextureRGBiiPhiiS_+0x1a0> */
/* @0x189494 ldr r1, [sp, #0x18] */
/* @0x189498 lsl r0, r5, #16 */
/* @0x18949c bl 0x318d10 <__divsi3> */
/* @0x1894a0 ldr r1, [sp, #0x30] */
/* @0x1894a4 ldr r7, [sp, #0x18] */
/* @0x1894a8 mov r2, #0 */
/* @0x1894ac mov r11, r2 */
/* @0x1894b0 str r4, [sp, #0x14] */
/* @0x1894b4 str r2, [sp, #0x24] */
/* @0x1894b8 mul r1, r1, r7 */
/* @0x1894bc str r2, [sp, #0x20] */
/* @0x1894c0 str r1, [sp, #0x2c] */
/* @0x1894c4 str r0, [sp, #0x1c] */
/* @0x1894c8 ldr r12, [sp, #0x20] */
/* @0x1894cc ldr r9, [sp, #0x18] */
/* @0x1894d0 ldr r7, [sp, #0x64] */
/* @0x1894d4 asr r3, r12, #16 */
/* @0x1894d8 cmp r9, #0 */
/* @0x1894dc mla r3, r8, r3, r7 */
/* @0x1894e0 ble 0x189594 <_Z14HalfTextureRGBiiPhiiS_+0x178> */
/* @0x1894e4 ldr r12, [sp, #0x14] */
/* @0x1894e8 mov r0, #0 */
/* @0x1894ec mov r6, r0 */
/* @0x1894f0 asr r2, r6, #16 */
/* @0x1894f4 ldr r9, [sp, #0x1c] */
/* @0x1894f8 add r11, r11, #1 */
/* @0x1894fc add r12, r12, #3 */
/* @0x189500 add r2, r2, r2, lsl #1 */
/* @0x189504 add r6, r6, r9 */
/* @0x189508 add r1, r2, #3 */
/* @0x18950c add r5, r2, r8 */
/* @0x189510 ldrb r10, [r3, r2] */
/* @0x189514 add r4, r1, r8 */
/* @0x189518 ldrb r7, [r3, r1] */
/* @0x18951c ldrb r9, [r3, r5] */
/* @0x189520 add r10, r10, r7 */
/* @0x189524 ldrb r7, [r3, r4] */
/* @0x189528 add r9, r10, r9 */
/* @0x18952c add r9, r9, r7 */
/* @0x189530 ldr r7, [sp, #0x14] */
/* @0x189534 asr r9, r9, #2 */
/* @0x189538 strb r9, [r7, r0] */
/* @0x18953c add r0, r0, #3 */
/* @0x189540 ldr r9, [sp, #0x18] */
/* @0x189544 ldrb r7, [r3, r1] */
/* @0x189548 ldrb r10, [r3, r2] */
/* @0x18954c cmp r9, r0 */
/* @0x189550 ldrb r9, [r3, r5] */
/* @0x189554 add r10, r10, r7 */
/* @0x189558 ldrb r7, [r3, r4] */
/* @0x18955c add r9, r10, r9 */
/* @0x189560 add r9, r9, r7 */
/* @0x189564 asr r9, r9, #2 */
/* @0x189568 strb r9, [r12, #-0x2] */
/* @0x18956c ldrb r7, [r3, r2] */
/* @0x189570 ldrb r1, [r3, r1] */
/* @0x189574 ldrb r5, [r3, r5] */
/* @0x189578 ldrb r4, [r3, r4] */
/* @0x18957c add r2, r7, r1 */
/* @0x189580 add r2, r2, r5 */
/* @0x189584 add r2, r2, r4 */
/* @0x189588 asr r2, r2, #2 */
/* @0x18958c strb r2, [r12, #-0x1] */
/* @0x189590 bgt 0x1894f0 <_Z14HalfTextureRGBiiPhiiS_+0xd4> */
/* @0x189594 ldr r12, [sp, #0x2c] */
/* @0x189598 ldr r1, [sp, #0x20] */
/* @0x18959c ldr r3, [sp, #0x24] */
/* @0x1895a0 cmp r12, r11 */
/* @0x1895a4 ldr r2, [sp, #0x28] */
/* @0x1895a8 add r3, r3, #1 */
/* @0x1895ac str r3, [sp, #0x24] */
/* @0x1895b0 add r1, r1, r2 */
/* @0x1895b4 str r1, [sp, #0x20] */
/* @0x1895b8 bge 0x1895c4 <_Z14HalfTextureRGBiiPhiiS_+0x1a8> */
/* @0x1895bc add sp, sp, #60 */
/* @0x1895c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1895c4 ldr r7, [sp, #0x30] */
/* @0x1895c8 ldr r9, [sp, #0x14] */
/* @0x1895cc ldr r12, [sp, #0x34] */
/* @0x1895d0 cmp r7, r3 */
/* @0x1895d4 add r9, r9, r12 */
/* @0x1895d8 str r9, [sp, #0x14] */
/* @0x1895dc bgt 0x1894c8 <_Z14HalfTextureRGBiiPhiiS_+0xac> */
/* @0x1895e0 b 0x1895bc <_Z14HalfTextureRGBiiPhiiS_+0x1a0> */
/* @0x1895e4 .word 0x002642f0 */
/* @0x1895e8 andseq r2, r12, r12, lsr r12 */

/* ── FUNC 0x1895ec · loadTexture(Texture*) · size=892 · insn=223 */
/* @0x1895ec push {r4, r5, r6, lr} */
/* @0x1895f0 sub sp, sp, #72 */
/* @0x1895f4 str r0, [sp, #0x18] */
/* @0x1895f8 bl 0x182598 <_Z23_InvalidateTextureStatev> */
/* @0x1895fc ldr r1, [sp, #0x18] */
/* @0x189600 mov r2, #8 */
/* @0x189604 ldr r3, [pc, #0x340] */
/* @0x189608 ldr r0, [r1, #0x2c] */
/* @0x18960c mov r1, #0 */
/* @0x189610 add r3, pc, r3 */
/* @0x189614 str r3, [sp, #0x1c] */
/* @0x189618 blx 0x2a5a4c <png_sig_cmp> */
/* @0x18961c subs r1, r0, #0 */
/* @0x189620 bne 0x189908 <_Z11loadTextureP7Texture+0x31c> */
/* @0x189624 ldr r0, [pc, #0x324] */
/* @0x189628 mov r2, r1 */
/* @0x18962c mov r3, r1 */
/* @0x189630 add r0, pc, r0 */
/* @0x189634 blx 0x2a6fdc <png_create_read_struct> */
/* @0x189638 cmp r0, #0 */
/* @0x18963c str r0, [sp, #0x24] */
/* @0x189640 beq 0x1898c4 <_Z11loadTextureP7Texture+0x2d8> */
/* @0x189644 blx 0x2a5b64 <png_create_info_struct> */
/* @0x189648 cmp r0, #0 */
/* @0x18964c str r0, [sp, #0x28] */
/* @0x189650 beq 0x189938 <_Z11loadTextureP7Texture+0x34c> */
/* @0x189654 ldr r0, [sp, #0x24] */
/* @0x189658 blx 0x2a5b64 <png_create_info_struct> */
/* @0x18965c cmp r0, #0 */
/* @0x189660 str r0, [sp, #0x2c] */
/* @0x189664 beq 0x1898b4 <_Z11loadTextureP7Texture+0x2c8> */
/* @0x189668 ldr r3, [pc, #0x2e4] */
/* @0x18966c mov r2, #256 */
/* @0x189670 ldr r12, [sp, #0x1c] */
/* @0x189674 ldr r0, [sp, #0x24] */
/* @0x189678 ldr r1, [r12, r3] */
/* @0x18967c blx 0x2a653c <png_set_longjmp_fn> */
/* @0x189680 bl 0xb6904 <setjmp@plt> */
/* @0x189684 subs r4, r0, #0 */
/* @0x189688 bne 0x1898f4 <_Z11loadTextureP7Texture+0x308> */
/* @0x18968c ldr r1, [sp, #0x18] */
/* @0x189690 ldr r12, [sp, #0x18] */
/* @0x189694 ldr r2, [pc, #0x2bc] */
/* @0x189698 ldr r3, [r1, #0x2c] */
/* @0x18969c add r1, sp, #64 */
/* @0x1896a0 add r2, pc, r2 */
/* @0x1896a4 ldr r0, [sp, #0x24] */
/* @0x1896a8 add r3, r3, #8 */
/* @0x1896ac str r12, [sp, #0x40] */
/* @0x1896b0 str r3, [sp, #0x44] */
/* @0x1896b4 blx 0x2a804c <png_set_read_fn> */
/* @0x1896b8 ldr r0, [sp, #0x24] */
/* @0x1896bc mov r1, #8 */
/* @0x1896c0 blx 0x2a5a24 <png_set_sig_bytes> */
/* @0x1896c4 ldr r0, [sp, #0x24] */
/* @0x1896c8 ldr r1, [sp, #0x28] */
/* @0x1896cc blx 0x2a6ff0 <png_read_info> */
/* @0x1896d0 ldr r1, [sp, #0x28] */
/* @0x1896d4 ldr r0, [sp, #0x24] */
/* @0x1896d8 blx 0x2a65a6 <png_get_bit_depth> */
/* @0x1896dc ldr r1, [sp, #0x28] */
/* @0x1896e0 str r0, [sp, #0x30] */
/* @0x1896e4 ldr r0, [sp, #0x24] */
/* @0x1896e8 blx 0x2a65b2 <png_get_color_type> */
/* @0x1896ec cmp r0, #3 */
/* @0x1896f0 str r0, [sp, #0x34] */
/* @0x1896f4 movne r3, r0 */
/* @0x1896f8 beq 0x189870 <_Z11loadTextureP7Texture+0x284> */
/* @0x1896fc bics r1, r3, #2 */
/* @0x189700 beq 0x189848 <_Z11loadTextureP7Texture+0x25c> */
/* @0x189704 eor r4, r4, #1 */
/* @0x189708 cmp r3, #3 */
/* @0x18970c movne r4, #0 */
/* @0x189710 andeq r4, r4, #1 */
/* @0x189714 cmp r4, #0 */
/* @0x189718 bne 0x189848 <_Z11loadTextureP7Texture+0x25c> */
/* @0x18971c bics r2, r3, #4 */
/* @0x189720 beq 0x189864 <_Z11loadTextureP7Texture+0x278> */
/* @0x189724 ldr r1, [sp, #0x28] */
/* @0x189728 add r3, sp, #48 */
/* @0x18972c add r2, sp, #52 */
/* @0x189730 str r3, [sp] */
/* @0x189734 ldr r0, [sp, #0x24] */
/* @0x189738 mov r3, #0 */
/* @0x18973c stmib sp, {r2, r3} */
/* @0x189740 add r2, sp, #56 */
/* @0x189744 str r3, [sp, #0xc] */
/* @0x189748 str r3, [sp, #0x10] */
/* @0x18974c add r3, sp, #60 */
/* @0x189750 blx 0x2a693e <png_get_IHDR> */
/* @0x189754 add r1, sp, #52 */
/* @0x189758 ldr r12, [sp, #0x18] */
/* @0x18975c ldm r1, {r1, r2, r3} */
/* @0x189760 cmp r1, #3 */
/* @0x189764 stmib r12, {r2, r3} */
/* @0x189768 beq 0x1898a8 <_Z11loadTextureP7Texture+0x2bc> */
/* @0x18976c ldr r0, [sp, #0x24] */
/* @0x189770 ldr r1, [sp, #0x28] */
/* @0x189774 blx 0x2a7448 <png_read_update_info> */
/* @0x189778 ldr r1, [sp, #0x28] */
/* @0x18977c ldr r0, [sp, #0x24] */
/* @0x189780 blx 0x2a6574 <png_get_rowbytes> */
/* @0x189784 mov r4, r0 */
/* @0x189788 ldr r0, [sp, #0x3c] */
/* @0x18978c mul r0, r0, r4 */
/* @0x189790 bl 0x27d14c <_Znaj> */
/* @0x189794 subs r6, r0, #0 */
/* @0x189798 beq 0x1898f4 <_Z11loadTextureP7Texture+0x308> */
/* @0x18979c ldr r0, [sp, #0x3c] */
/* @0x1897a0 cmp r0, #532676608 */
/* @0x1897a4 lslls r0, r0, #2 */
/* @0x1897a8 mvnhi r0, #0 */
/* @0x1897ac bl 0x27d14c <_Znaj> */
/* @0x1897b0 subs r5, r0, #0 */
/* @0x1897b4 beq 0x1898f4 <_Z11loadTextureP7Texture+0x308> */
/* @0x1897b8 ldr r12, [sp, #0x3c] */
/* @0x1897bc cmp r12, #0 */
/* @0x1897c0 addne r12, r5, r12, lsl #2 */
/* @0x1897c4 movne r2, r6 */
/* @0x1897c8 movne r3, r5 */
/* @0x1897cc beq 0x1897e0 <_Z11loadTextureP7Texture+0x1f4> */
/* @0x1897d0 str r2, [r3], #4 */
/* @0x1897d4 cmp r3, r12 */
/* @0x1897d8 add r2, r2, r4 */
/* @0x1897dc bne 0x1897d0 <_Z11loadTextureP7Texture+0x1e4> */
/* @0x1897e0 ldr r0, [sp, #0x24] */
/* @0x1897e4 mov r1, r5 */
/* @0x1897e8 blx 0x2a7840 <png_read_image> */
/* @0x1897ec ldr r12, [sp, #0x30] */
/* @0x1897f0 ldr r3, [sp, #0x3c] */
/* @0x1897f4 mov r1, #6 */
/* @0x1897f8 ldr r2, [sp, #0x38] */
/* @0x1897fc str r12, [sp, #0x4] */
/* @0x189800 ldr r0, [sp, #0x18] */
/* @0x189804 str r4, [sp] */
/* @0x189808 str r6, [sp, #0x8] */
/* @0x18980c bl 0x181cdc <_Z15_PNG_setTextureP7TextureiiiiiPh> */
/* @0x189810 add r1, sp, #40 */
/* @0x189814 add r2, sp, #44 */
/* @0x189818 add r0, sp, #36 */
/* @0x18981c blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189820 mov r0, r6 */
/* @0x189824 bl 0x27d1d4 <_ZdaPv> */
/* @0x189828 mov r0, r5 */
/* @0x18982c bl 0x27d1d4 <_ZdaPv> */
/* @0x189830 ldr r1, [sp, #0x18] */
/* @0x189834 mov r3, #6 */
/* @0x189838 ldr r0, [r1, #0x14] */
/* @0x18983c str r3, [r1] */
/* @0x189840 add sp, sp, #72 */
/* @0x189844 pop {r4, r5, r6, pc} */
/* @0x189848 mov r2, #1 */
/* @0x18984c ldr r0, [sp, #0x24] */
/* @0x189850 mov r1, #255 */
/* @0x189854 blx 0x2af812 <png_set_add_alpha> */
/* @0x189858 ldr r3, [sp, #0x34] */
/* @0x18985c bics r2, r3, #4 */
/* @0x189860 bne 0x189724 <_Z11loadTextureP7Texture+0x138> */
/* @0x189864 ldr r0, [sp, #0x24] */
/* @0x189868 blx 0x2a880a <png_set_gray_to_rgb> */
/* @0x18986c b 0x189724 <_Z11loadTextureP7Texture+0x138> */
/* @0x189870 mov r2, r4 */
/* @0x189874 str r4, [sp] */
/* @0x189878 ldr r0, [sp, #0x24] */
/* @0x18987c add r3, sp, #60 */
/* @0x189880 ldr r1, [sp, #0x28] */
/* @0x189884 blx 0x2a6b56 <png_get_tRNS> */
/* @0x189888 cmp r0, #0 */
/* @0x18988c moveq r4, r0 */
/* @0x189890 beq 0x1898a0 <_Z11loadTextureP7Texture+0x2b4> */
/* @0x189894 ldr r4, [sp, #0x3c] */
/* @0x189898 adds r4, r4, #0 */
/* @0x18989c movne r4, #1 */
/* @0x1898a0 ldr r3, [sp, #0x34] */
/* @0x1898a4 b 0x1896fc <_Z11loadTextureP7Texture+0x110> */
/* @0x1898a8 ldr r0, [sp, #0x24] */
/* @0x1898ac blx 0x2a87b0 <png_set_palette_to_rgb> */
/* @0x1898b0 b 0x18976c <_Z11loadTextureP7Texture+0x180> */
/* @0x1898b4 mov r2, r0 */
/* @0x1898b8 add r1, sp, #40 */
/* @0x1898bc add r0, sp, #36 */
/* @0x1898c0 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x1898c4 ldr r3, [pc, #0x90] */
/* @0x1898c8 ldr r2, [sp, #0x1c] */
/* @0x1898cc ldr r3, [r2, r3] */
/* @0x1898d0 ldr r0, [r3] */
/* @0x1898d4 ldr r3, [r0] */
/* @0x1898d8 ldr r1, [pc, #0x80] */
/* @0x1898dc ldr r3, [r3, #0xc] */
/* @0x1898e0 add r1, pc, r1 */
/* @0x1898e4 blx r3 */
/* @0x1898e8 mvn r0, #0 */
/* @0x1898ec add sp, sp, #72 */
/* @0x1898f0 pop {r4, r5, r6, pc} */
/* @0x1898f4 add r0, sp, #36 */
/* @0x1898f8 add r1, sp, #40 */
/* @0x1898fc add r2, sp, #44 */
/* @0x189900 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189904 b 0x1898c4 <_Z11loadTextureP7Texture+0x2d8> */
/* @0x189908 ldr r12, [sp, #0x1c] */
/* @0x18990c ldr r3, [pc, #0x48] */
/* @0x189910 ldr r1, [pc, #0x4c] */
/* @0x189914 ldr r3, [r12, r3] */
/* @0x189918 add r1, pc, r1 */
/* @0x18991c ldr r4, [r3] */
/* @0x189920 ldr r3, [r4] */
/* @0x189924 mov r0, r4 */
/* @0x189928 ldr r3, [r3, #0xc] */
/* @0x18992c blx r3 */
/* @0x189930 mov r0, r4 */
/* @0x189934 b 0x1898d4 <_Z11loadTextureP7Texture+0x2e8> */
/* @0x189938 mov r1, r0 */
/* @0x18993c add r0, sp, #36 */
/* @0x189940 mov r2, r1 */
/* @0x189944 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189948 b 0x1898c4 <_Z11loadTextureP7Texture+0x2d8> */
/* @0x18994c eoreq r8, r6, r0, asr #12 */
/* @0x189950 andseq r1, r12, r12 */
/* @0x189954 .word 0xffffe4ac */
/* @0x189958 .word 0xfffffb2c */
/* @0x18995c .word 0xffffbac4 */
/* @0x189960 ldrsheq r2, [r12], -r8 */
/* @0x189964 ldrheq r2, [r12], -r4 */

/* ── FUNC 0x189968 · getTextureInfo(Texture*) · size=468 · insn=117 */
/* @0x189968 push {r4, lr} */
/* @0x18996c sub sp, sp, #72 */
/* @0x189970 mov r1, #0 */
/* @0x189974 mov r2, #8 */
/* @0x189978 str r0, [sp, #0x1c] */
/* @0x18997c ldr r0, [r0, #0x2c] */
/* @0x189980 blx 0x2a5a4c <png_sig_cmp> */
/* @0x189984 ldr r1, [pc, #0x194] */
/* @0x189988 add r1, pc, r1 */
/* @0x18998c str r1, [sp, #0x18] */
/* @0x189990 subs r1, r0, #0 */
/* @0x189994 bne 0x189a24 <_Z14getTextureInfoP7Texture+0xbc> */
/* @0x189998 ldr r0, [pc, #0x184] */
/* @0x18999c mov r2, r1 */
/* @0x1899a0 mov r3, r1 */
/* @0x1899a4 add r0, pc, r0 */
/* @0x1899a8 blx 0x2a6fdc <png_create_read_struct> */
/* @0x1899ac cmp r0, #0 */
/* @0x1899b0 str r0, [sp, #0x24] */
/* @0x1899b4 beq 0x189a10 <_Z14getTextureInfoP7Texture+0xa8> */
/* @0x1899b8 blx 0x2a5b64 <png_create_info_struct> */
/* @0x1899bc cmp r0, #0 */
/* @0x1899c0 str r0, [sp, #0x28] */
/* @0x1899c4 beq 0x189af8 <_Z14getTextureInfoP7Texture+0x190> */
/* @0x1899c8 ldr r0, [sp, #0x24] */
/* @0x1899cc blx 0x2a5b64 <png_create_info_struct> */
/* @0x1899d0 cmp r0, #0 */
/* @0x1899d4 str r0, [sp, #0x2c] */
/* @0x1899d8 beq 0x189b0c <_Z14getTextureInfoP7Texture+0x1a4> */
/* @0x1899dc ldr r3, [pc, #0x144] */
/* @0x1899e0 mov r2, #256 */
/* @0x1899e4 ldr r12, [sp, #0x18] */
/* @0x1899e8 ldr r0, [sp, #0x24] */
/* @0x1899ec ldr r1, [r12, r3] */
/* @0x1899f0 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x1899f4 bl 0xb6904 <setjmp@plt> */
/* @0x1899f8 subs r4, r0, #0 */
/* @0x1899fc beq 0x189a6c <_Z14getTextureInfoP7Texture+0x104> */
/* @0x189a00 add r0, sp, #36 */
/* @0x189a04 add r1, sp, #40 */
/* @0x189a08 add r2, sp, #44 */
/* @0x189a0c blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189a10 ldr r3, [pc, #0x114] */
/* @0x189a14 ldr r1, [sp, #0x18] */
/* @0x189a18 ldr r3, [r1, r3] */
/* @0x189a1c ldr r0, [r3] */
/* @0x189a20 b 0x189a50 <_Z14getTextureInfoP7Texture+0xe8> */
/* @0x189a24 ldr r2, [sp, #0x18] */
/* @0x189a28 ldr r3, [pc, #0xfc] */
/* @0x189a2c ldr r1, [pc, #0xfc] */
/* @0x189a30 ldr r3, [r2, r3] */
/* @0x189a34 add r1, pc, r1 */
/* @0x189a38 ldr r4, [r3] */
/* @0x189a3c ldr r3, [r4] */
/* @0x189a40 mov r0, r4 */
/* @0x189a44 ldr r3, [r3, #0xc] */
/* @0x189a48 blx r3 */
/* @0x189a4c mov r0, r4 */
/* @0x189a50 ldr r3, [r0] */
/* @0x189a54 ldr r1, [pc, #0xd8] */
/* @0x189a58 ldr r3, [r3, #0xc] */
/* @0x189a5c add r1, pc, r1 */
/* @0x189a60 blx r3 */
/* @0x189a64 add sp, sp, #72 */
/* @0x189a68 pop {r4, pc} */
/* @0x189a6c ldr r0, [sp, #0x1c] */
/* @0x189a70 add r1, sp, #64 */
/* @0x189a74 ldr r12, [sp, #0x1c] */
/* @0x189a78 ldr r2, [pc, #0xb8] */
/* @0x189a7c ldr r3, [r0, #0x2c] */
/* @0x189a80 add r2, pc, r2 */
/* @0x189a84 ldr r0, [sp, #0x24] */
/* @0x189a88 add r3, r3, #8 */
/* @0x189a8c str r12, [sp, #0x40] */
/* @0x189a90 str r3, [sp, #0x44] */
/* @0x189a94 blx 0x2a804c <png_set_read_fn> */
/* @0x189a98 ldr r0, [sp, #0x24] */
/* @0x189a9c mov r1, #8 */
/* @0x189aa0 blx 0x2a5a24 <png_set_sig_bytes> */
/* @0x189aa4 ldr r0, [sp, #0x24] */
/* @0x189aa8 ldr r1, [sp, #0x28] */
/* @0x189aac blx 0x2a6ff0 <png_read_info> */
/* @0x189ab0 ldr r1, [sp, #0x28] */
/* @0x189ab4 add r3, sp, #48 */
/* @0x189ab8 add r2, sp, #56 */
/* @0x189abc str r3, [sp] */
/* @0x189ac0 add r3, sp, #52 */
/* @0x189ac4 ldr r0, [sp, #0x24] */
/* @0x189ac8 str r3, [sp, #0x4] */
/* @0x189acc add r3, sp, #60 */
/* @0x189ad0 str r4, [sp, #0x8] */
/* @0x189ad4 str r4, [sp, #0xc] */
/* @0x189ad8 str r4, [sp, #0x10] */
/* @0x189adc blx 0x2a693e <png_get_IHDR> */
/* @0x189ae0 ldr r2, [sp, #0x38] */
/* @0x189ae4 ldr r3, [sp, #0x3c] */
/* @0x189ae8 mov r1, #6 */
/* @0x189aec ldr r0, [sp, #0x1c] */
/* @0x189af0 stm r0, {r1, r2, r3} */
/* @0x189af4 b 0x189a64 <_Z14getTextureInfoP7Texture+0xfc> */
/* @0x189af8 mov r1, r0 */
/* @0x189afc add r0, sp, #36 */
/* @0x189b00 mov r2, r1 */
/* @0x189b04 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189b08 b 0x189a10 <_Z14getTextureInfoP7Texture+0xa8> */
/* @0x189b0c mov r2, r0 */
/* @0x189b10 add r1, sp, #40 */
/* @0x189b14 add r0, sp, #36 */
/* @0x189b18 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189b1c b 0x189a10 <_Z14getTextureInfoP7Texture+0xa8> */
/* @0x189b20 eoreq r8, r6, r8, asr #5 */
/* @0x189b24 mulseq r12, r8, r12 */
/* @0x189b28 .word 0xffffe4ac */
/* @0x189b2c .word 0xffffbac4 */
/* @0x189b30 mulseq r12, r8, r6 */
/* @0x189b34 mulseq r12, r0, r6 */
/* @0x189b38 .word 0xfffff74c */

/* ── FUNC 0x189b3c · FreePNG(yyPNGFile*) · size=60 · insn=15 */
/* @0x189b3c push {r4, lr} */
/* @0x189b40 mov r4, r0 */
/* @0x189b44 add r0, r0, #20 */
/* @0x189b48 add r1, r4, #24 */
/* @0x189b4c add r2, r4, #28 */
/* @0x189b50 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189b54 ldr r0, [r4, #0x20] */
/* @0x189b58 cmp r0, #0 */
/* @0x189b5c beq 0x189b64 <_Z7FreePNGP9yyPNGFile+0x28> */
/* @0x189b60 bl 0x27d1d4 <_ZdaPv> */
/* @0x189b64 ldr r0, [r4, #0x24] */
/* @0x189b68 cmp r0, #0 */
/* @0x189b6c popeq {r4, pc} */
/* @0x189b70 pop {r4, lr} */
/* @0x189b74 b 0x27d1d4 <_ZdaPv> */

/* ── FUNC 0x189b78 · ReadPNGHeader(yyPNGFile*) · size=776 · insn=194 */
/* @0x189b78 push {r4, lr} */
/* @0x189b7c sub sp, sp, #56 */
/* @0x189b80 mov r1, #0 */
/* @0x189b84 mov r2, #8 */
/* @0x189b88 str r0, [sp, #0x18] */
/* @0x189b8c ldr r0, [r0, #0x4] */
/* @0x189b90 blx 0x2a5a4c <png_sig_cmp> */
/* @0x189b94 ldr r1, [pc, #0x2c8] */
/* @0x189b98 add r1, pc, r1 */
/* @0x189b9c str r1, [sp, #0x1c] */
/* @0x189ba0 subs r1, r0, #0 */
/* @0x189ba4 bne 0x189d34 <_Z13ReadPNGHeaderP9yyPNGFile+0x1bc> */
/* @0x189ba8 ldr r0, [pc, #0x2b8] */
/* @0x189bac mov r2, r1 */
/* @0x189bb0 mov r3, r1 */
/* @0x189bb4 add r0, pc, r0 */
/* @0x189bb8 blx 0x2a6fdc <png_create_read_struct> */
/* @0x189bbc ldr r2, [sp, #0x18] */
/* @0x189bc0 cmp r0, #0 */
/* @0x189bc4 str r0, [r2, #0x14] */
/* @0x189bc8 beq 0x189d9c <_Z13ReadPNGHeaderP9yyPNGFile+0x224> */
/* @0x189bcc blx 0x2a5b64 <png_create_info_struct> */
/* @0x189bd0 ldr r3, [sp, #0x18] */
/* @0x189bd4 cmp r0, #0 */
/* @0x189bd8 str r0, [r3, #0x18] */
/* @0x189bdc beq 0x189df4 <_Z13ReadPNGHeaderP9yyPNGFile+0x27c> */
/* @0x189be0 ldr r12, [sp, #0x18] */
/* @0x189be4 ldr r0, [r12, #0x14] */
/* @0x189be8 blx 0x2a5b64 <png_create_info_struct> */
/* @0x189bec ldr r1, [sp, #0x18] */
/* @0x189bf0 cmp r0, #0 */
/* @0x189bf4 str r0, [r1, #0x1c] */
/* @0x189bf8 beq 0x189d8c <_Z13ReadPNGHeaderP9yyPNGFile+0x214> */
/* @0x189bfc ldr r12, [sp, #0x18] */
/* @0x189c00 mov r2, #256 */
/* @0x189c04 ldr r3, [pc, #0x260] */
/* @0x189c08 ldr r0, [r12, #0x14] */
/* @0x189c0c ldr r12, [sp, #0x1c] */
/* @0x189c10 ldr r1, [r12, r3] */
/* @0x189c14 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x189c18 bl 0xb6904 <setjmp@plt> */
/* @0x189c1c subs r4, r0, #0 */
/* @0x189c20 bne 0x189db0 <_Z13ReadPNGHeaderP9yyPNGFile+0x238> */
/* @0x189c24 ldr r12, [sp, #0x18] */
/* @0x189c28 add r1, sp, #48 */
/* @0x189c2c ldr r2, [pc, #0x23c] */
/* @0x189c30 ldr r3, [r12, #0x4] */
/* @0x189c34 add r2, pc, r2 */
/* @0x189c38 ldr r0, [r12, #0x14] */
/* @0x189c3c add r3, r3, #8 */
/* @0x189c40 str r12, [sp, #0x30] */
/* @0x189c44 str r3, [sp, #0x34] */
/* @0x189c48 blx 0x2a804c <png_set_read_fn> */
/* @0x189c4c ldr r1, [sp, #0x18] */
/* @0x189c50 ldr r0, [r1, #0x14] */
/* @0x189c54 mov r1, #8 */
/* @0x189c58 blx 0x2a5a24 <png_set_sig_bytes> */
/* @0x189c5c ldr r2, [sp, #0x18] */
/* @0x189c60 ldr r0, [r2, #0x14] */
/* @0x189c64 ldr r1, [r2, #0x18] */
/* @0x189c68 blx 0x2a6ff0 <png_read_info> */
/* @0x189c6c ldr r3, [sp, #0x18] */
/* @0x189c70 ldr r1, [r3, #0x18] */
/* @0x189c74 ldr r0, [r3, #0x14] */
/* @0x189c78 blx 0x2a65a6 <png_get_bit_depth> */
/* @0x189c7c ldr r12, [sp, #0x18] */
/* @0x189c80 ldr r1, [r12, #0x18] */
/* @0x189c84 str r0, [sp, #0x20] */
/* @0x189c88 ldr r0, [r12, #0x14] */
/* @0x189c8c blx 0x2a65b2 <png_get_color_type> */
/* @0x189c90 cmp r0, #3 */
/* @0x189c94 str r0, [sp, #0x24] */
/* @0x189c98 movne r3, r0 */
/* @0x189c9c beq 0x189e28 <_Z13ReadPNGHeaderP9yyPNGFile+0x2b0> */
/* @0x189ca0 bics r2, r3, #4 */
/* @0x189ca4 beq 0x189e08 <_Z13ReadPNGHeaderP9yyPNGFile+0x290> */
/* @0x189ca8 bics r12, r3, #2 */
/* @0x189cac beq 0x189ddc <_Z13ReadPNGHeaderP9yyPNGFile+0x264> */
/* @0x189cb0 eor r4, r4, #1 */
/* @0x189cb4 cmp r3, #3 */
/* @0x189cb8 movne r3, #0 */
/* @0x189cbc andeq r3, r4, #1 */
/* @0x189cc0 cmp r3, #0 */
/* @0x189cc4 bne 0x189ddc <_Z13ReadPNGHeaderP9yyPNGFile+0x264> */
/* @0x189cc8 ldr r2, [sp, #0x18] */
/* @0x189ccc add r3, sp, #32 */
/* @0x189cd0 ldr r1, [r2, #0x18] */
/* @0x189cd4 ldr r0, [r2, #0x14] */
/* @0x189cd8 add r2, sp, #36 */
/* @0x189cdc str r3, [sp] */
/* @0x189ce0 mov r3, #0 */
/* @0x189ce4 stmib sp, {r2, r3} */
/* @0x189ce8 add r2, sp, #40 */
/* @0x189cec str r3, [sp, #0xc] */
/* @0x189cf0 str r3, [sp, #0x10] */
/* @0x189cf4 add r3, sp, #44 */
/* @0x189cf8 blx 0x2a693e <png_get_IHDR> */
/* @0x189cfc add r1, sp, #36 */
/* @0x189d00 ldr r12, [sp, #0x18] */
/* @0x189d04 ldm r1, {r1, r2, r3} */
/* @0x189d08 cmp r1, #3 */
/* @0x189d0c str r2, [r12, #0xc] */
/* @0x189d10 str r3, [r12, #0x10] */
/* @0x189d14 beq 0x189e1c <_Z13ReadPNGHeaderP9yyPNGFile+0x2a4> */
/* @0x189d18 ldr r1, [sp, #0x18] */
/* @0x189d1c ldr r0, [r1, #0x14] */
/* @0x189d20 ldr r1, [r1, #0x18] */
/* @0x189d24 blx 0x2a7448 <png_read_update_info> */
/* @0x189d28 mov r0, #1 */
/* @0x189d2c add sp, sp, #56 */
/* @0x189d30 pop {r4, pc} */
/* @0x189d34 ldr r12, [sp, #0x1c] */
/* @0x189d38 ldr r3, [pc, #0x134] */
/* @0x189d3c ldr r1, [pc, #0x134] */
/* @0x189d40 ldr r3, [r12, r3] */
/* @0x189d44 add r1, pc, r1 */
/* @0x189d48 ldr r4, [r3] */
/* @0x189d4c ldr r3, [r4] */
/* @0x189d50 mov r0, r4 */
/* @0x189d54 ldr r3, [r3, #0xc] */
/* @0x189d58 blx r3 */
/* @0x189d5c mov r0, r4 */
/* @0x189d60 ldr r3, [r0] */
/* @0x189d64 mov r2, #1 */
/* @0x189d68 ldr r12, [sp, #0x18] */
/* @0x189d6c ldr r1, [pc, #0x108] */
/* @0x189d70 ldr r3, [r3, #0xc] */
/* @0x189d74 add r1, pc, r1 */
/* @0x189d78 strb r2, [r12] */
/* @0x189d7c blx r3 */
/* @0x189d80 mov r0, #0 */
/* @0x189d84 add sp, sp, #56 */
/* @0x189d88 pop {r4, pc} */
/* @0x189d8c mov r2, r0 */
/* @0x189d90 add r0, r1, #20 */
/* @0x189d94 add r1, r1, #24 */
/* @0x189d98 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189d9c ldr r3, [pc, #0xd0] */
/* @0x189da0 ldr r2, [sp, #0x1c] */
/* @0x189da4 ldr r3, [r2, r3] */
/* @0x189da8 ldr r0, [r3] */
/* @0x189dac b 0x189d60 <_Z13ReadPNGHeaderP9yyPNGFile+0x1e8> */
/* @0x189db0 ldr r1, [sp, #0x18] */
/* @0x189db4 ldr r3, [sp, #0x18] */
/* @0x189db8 add r0, r1, #20 */
/* @0x189dbc add r1, r1, #24 */
/* @0x189dc0 add r2, r3, #28 */
/* @0x189dc4 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189dc8 ldr r3, [pc, #0xa4] */
/* @0x189dcc ldr r2, [sp, #0x1c] */
/* @0x189dd0 ldr r3, [r2, r3] */
/* @0x189dd4 ldr r0, [r3] */
/* @0x189dd8 b 0x189d60 <_Z13ReadPNGHeaderP9yyPNGFile+0x1e8> */
/* @0x189ddc ldr r1, [sp, #0x18] */
/* @0x189de0 mov r2, #1 */
/* @0x189de4 ldr r0, [r1, #0x14] */
/* @0x189de8 mov r1, #255 */
/* @0x189dec blx 0x2af812 <png_set_add_alpha> */
/* @0x189df0 b 0x189cc8 <_Z13ReadPNGHeaderP9yyPNGFile+0x150> */
/* @0x189df4 mov r1, r0 */
/* @0x189df8 add r0, r3, #20 */
/* @0x189dfc mov r2, r1 */
/* @0x189e00 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x189e04 b 0x189d9c <_Z13ReadPNGHeaderP9yyPNGFile+0x224> */
/* @0x189e08 ldr r3, [sp, #0x18] */
/* @0x189e0c ldr r0, [r3, #0x14] */
/* @0x189e10 blx 0x2a880a <png_set_gray_to_rgb> */
/* @0x189e14 ldr r3, [sp, #0x24] */
/* @0x189e18 b 0x189ca8 <_Z13ReadPNGHeaderP9yyPNGFile+0x130> */
/* @0x189e1c ldr r0, [r12, #0x14] */
/* @0x189e20 blx 0x2a87b0 <png_set_palette_to_rgb> */
/* @0x189e24 b 0x189d18 <_Z13ReadPNGHeaderP9yyPNGFile+0x1a0> */
/* @0x189e28 ldr r1, [sp, #0x18] */
/* @0x189e2c mov r2, r4 */
/* @0x189e30 add r3, sp, #44 */
/* @0x189e34 ldr r0, [r1, #0x14] */
/* @0x189e38 ldr r1, [r1, #0x18] */
/* @0x189e3c str r4, [sp] */
/* @0x189e40 blx 0x2a6b56 <png_get_tRNS> */
/* @0x189e44 cmp r0, #0 */
/* @0x189e48 moveq r4, r0 */
/* @0x189e4c beq 0x189e5c <_Z13ReadPNGHeaderP9yyPNGFile+0x2e4> */
/* @0x189e50 ldr r4, [sp, #0x2c] */
/* @0x189e54 adds r4, r4, #0 */
/* @0x189e58 movne r4, #1 */
/* @0x189e5c ldr r3, [sp, #0x24] */
/* @0x189e60 b 0x189ca0 <_Z13ReadPNGHeaderP9yyPNGFile+0x128> */
/* @0x189e64 strhteq r8, [r6], -r8 */
/* @0x189e68 andseq r0, r12, r8, lsl #21 */
/* @0x189e6c .word 0xffffe4ac */
/* @0x189e70 .word 0xfffff5cc */
/* @0x189e74 .word 0xffffbac4 */
/* @0x189e78 andseq r2, r12, r8, lsl #7 */
/* @0x189e7c andseq r2, r12, r0, lsr #7 */

/* ── FUNC 0x189e80 · ReadPNG(yyPNGFile*) · size=972 · insn=243 */
/* @0x189e80 push {r4, lr} */
/* @0x189e84 sub sp, sp, #56 */
/* @0x189e88 mov r1, #0 */
/* @0x189e8c mov r2, #8 */
/* @0x189e90 str r0, [sp, #0x18] */
/* @0x189e94 ldr r0, [r0, #0x4] */
/* @0x189e98 blx 0x2a5a4c <png_sig_cmp> */
/* @0x189e9c ldr r1, [pc, #0x38c] */
/* @0x189ea0 add r1, pc, r1 */
/* @0x189ea4 str r1, [sp, #0x1c] */
/* @0x189ea8 subs r1, r0, #0 */
/* @0x189eac bne 0x18a0dc <_Z7ReadPNGP9yyPNGFile+0x25c> */
/* @0x189eb0 ldr r0, [pc, #0x37c] */
/* @0x189eb4 mov r2, r1 */
/* @0x189eb8 mov r3, r1 */
/* @0x189ebc add r0, pc, r0 */
/* @0x189ec0 blx 0x2a6fdc <png_create_read_struct> */
/* @0x189ec4 ldr r2, [sp, #0x18] */
/* @0x189ec8 cmp r0, #0 */
/* @0x189ecc str r0, [r2, #0x14] */
/* @0x189ed0 beq 0x18a144 <_Z7ReadPNGP9yyPNGFile+0x2c4> */
/* @0x189ed4 blx 0x2a5b64 <png_create_info_struct> */
/* @0x189ed8 ldr r3, [sp, #0x18] */
/* @0x189edc cmp r0, #0 */
/* @0x189ee0 str r0, [r3, #0x18] */
/* @0x189ee4 beq 0x18a1b8 <_Z7ReadPNGP9yyPNGFile+0x338> */
/* @0x189ee8 ldr r12, [sp, #0x18] */
/* @0x189eec ldr r0, [r12, #0x14] */
/* @0x189ef0 blx 0x2a5b64 <png_create_info_struct> */
/* @0x189ef4 ldr r1, [sp, #0x18] */
/* @0x189ef8 cmp r0, #0 */
/* @0x189efc str r0, [r1, #0x1c] */
/* @0x189f00 beq 0x18a134 <_Z7ReadPNGP9yyPNGFile+0x2b4> */
/* @0x189f04 ldr r12, [sp, #0x18] */
/* @0x189f08 mov r2, #256 */
/* @0x189f0c ldr r3, [pc, #0x324] */
/* @0x189f10 ldr r0, [r12, #0x14] */
/* @0x189f14 ldr r12, [sp, #0x1c] */
/* @0x189f18 ldr r1, [r12, r3] */
/* @0x189f1c blx 0x2a653c <png_set_longjmp_fn> */
/* @0x189f20 bl 0xb6904 <setjmp@plt> */
/* @0x189f24 subs r4, r0, #0 */
/* @0x189f28 bne 0x18a174 <_Z7ReadPNGP9yyPNGFile+0x2f4> */
/* @0x189f2c ldr r12, [sp, #0x18] */
/* @0x189f30 add r1, sp, #48 */
/* @0x189f34 ldr r2, [pc, #0x300] */
/* @0x189f38 ldr r3, [r12, #0x4] */
/* @0x189f3c add r2, pc, r2 */
/* @0x189f40 ldr r0, [r12, #0x14] */
/* @0x189f44 add r3, r3, #8 */
/* @0x189f48 str r12, [sp, #0x30] */
/* @0x189f4c str r3, [sp, #0x34] */
/* @0x189f50 blx 0x2a804c <png_set_read_fn> */
/* @0x189f54 ldr r1, [sp, #0x18] */
/* @0x189f58 ldr r0, [r1, #0x14] */
/* @0x189f5c mov r1, #8 */
/* @0x189f60 blx 0x2a5a24 <png_set_sig_bytes> */
/* @0x189f64 ldr r2, [sp, #0x18] */
/* @0x189f68 ldr r0, [r2, #0x14] */
/* @0x189f6c ldr r1, [r2, #0x18] */
/* @0x189f70 blx 0x2a6ff0 <png_read_info> */
/* @0x189f74 ldr r3, [sp, #0x18] */
/* @0x189f78 ldr r1, [r3, #0x18] */
/* @0x189f7c ldr r0, [r3, #0x14] */
/* @0x189f80 blx 0x2a65a6 <png_get_bit_depth> */
/* @0x189f84 ldr r12, [sp, #0x18] */
/* @0x189f88 ldr r1, [r12, #0x18] */
/* @0x189f8c str r0, [sp, #0x24] */
/* @0x189f90 ldr r0, [r12, #0x14] */
/* @0x189f94 blx 0x2a65b2 <png_get_color_type> */
/* @0x189f98 cmp r0, #3 */
/* @0x189f9c str r0, [sp, #0x28] */
/* @0x189fa0 movne r3, r0 */
/* @0x189fa4 beq 0x18a1e0 <_Z7ReadPNGP9yyPNGFile+0x360> */
/* @0x189fa8 bics r2, r3, #4 */
/* @0x189fac beq 0x18a1cc <_Z7ReadPNGP9yyPNGFile+0x34c> */
/* @0x189fb0 bics r12, r3, #2 */
/* @0x189fb4 beq 0x18a1a0 <_Z7ReadPNGP9yyPNGFile+0x320> */
/* @0x189fb8 eor r4, r4, #1 */
/* @0x189fbc cmp r3, #3 */
/* @0x189fc0 movne r3, #0 */
/* @0x189fc4 andeq r3, r4, #1 */
/* @0x189fc8 cmp r3, #0 */
/* @0x189fcc bne 0x18a1a0 <_Z7ReadPNGP9yyPNGFile+0x320> */
/* @0x189fd0 ldr r2, [sp, #0x18] */
/* @0x189fd4 add r3, sp, #36 */
/* @0x189fd8 ldr r1, [r2, #0x18] */
/* @0x189fdc ldr r0, [r2, #0x14] */
/* @0x189fe0 add r2, sp, #40 */
/* @0x189fe4 str r3, [sp] */
/* @0x189fe8 mov r3, #0 */
/* @0x189fec stmib sp, {r2, r3} */
/* @0x189ff0 add r2, sp, #32 */
/* @0x189ff4 str r3, [sp, #0xc] */
/* @0x189ff8 str r3, [sp, #0x10] */
/* @0x189ffc add r3, sp, #44 */
/* @0x18a000 blx 0x2a693e <png_get_IHDR> */
/* @0x18a004 ldr r1, [sp, #0x28] */
/* @0x18a008 ldr r12, [sp, #0x18] */
/* @0x18a00c ldr r2, [sp, #0x20] */
/* @0x18a010 cmp r1, #3 */
/* @0x18a014 ldr r3, [sp, #0x2c] */
/* @0x18a018 str r2, [r12, #0xc] */
/* @0x18a01c str r3, [r12, #0x10] */
/* @0x18a020 beq 0x18a21c <_Z7ReadPNGP9yyPNGFile+0x39c> */
/* @0x18a024 ldr r1, [sp, #0x18] */
/* @0x18a028 ldr r0, [r1, #0x14] */
/* @0x18a02c ldr r1, [r1, #0x18] */
/* @0x18a030 blx 0x2a7448 <png_read_update_info> */
/* @0x18a034 ldr r2, [sp, #0x18] */
/* @0x18a038 ldr r0, [r2, #0x14] */
/* @0x18a03c ldr r1, [r2, #0x18] */
/* @0x18a040 blx 0x2a6574 <png_get_rowbytes> */
/* @0x18a044 ldr r12, [sp, #0x18] */
/* @0x18a048 ldr r3, [r12, #0x20] */
/* @0x18a04c cmp r3, #0 */
/* @0x18a050 mov r4, r0 */
/* @0x18a054 beq 0x18a158 <_Z7ReadPNGP9yyPNGFile+0x2d8> */
/* @0x18a058 ldr r0, [sp, #0x2c] */
/* @0x18a05c cmp r0, #532676608 */
/* @0x18a060 lslls r0, r0, #2 */
/* @0x18a064 mvnhi r0, #0 */
/* @0x18a068 bl 0x27d14c <_Znaj> */
/* @0x18a06c ldr r2, [sp, #0x18] */
/* @0x18a070 cmp r0, #0 */
/* @0x18a074 str r0, [r2, #0x24] */
/* @0x18a078 beq 0x18a174 <_Z7ReadPNGP9yyPNGFile+0x2f4> */
/* @0x18a07c ldr lr, [sp, #0x2c] */
/* @0x18a080 cmp lr, #0 */
/* @0x18a084 beq 0x18a228 <_Z7ReadPNGP9yyPNGFile+0x3a8> */
/* @0x18a088 mov r2, #0 */
/* @0x18a08c mov r1, r0 */
/* @0x18a090 mov r3, r2 */
/* @0x18a094 b 0x18a09c <_Z7ReadPNGP9yyPNGFile+0x21c> */
/* @0x18a098 ldr r1, [r0, #0x24] */
/* @0x18a09c ldr r0, [sp, #0x18] */
/* @0x18a0a0 ldr r12, [r0, #0x20] */
/* @0x18a0a4 add r12, r12, r2 */
/* @0x18a0a8 str r12, [r1, r3, lsl #2] */
/* @0x18a0ac add r3, r3, #1 */
/* @0x18a0b0 add r2, r2, r4 */
/* @0x18a0b4 cmp r3, lr */
/* @0x18a0b8 bne 0x18a098 <_Z7ReadPNGP9yyPNGFile+0x218> */
/* @0x18a0bc ldr r2, [sp, #0x18] */
/* @0x18a0c0 ldr r1, [r2, #0x24] */
/* @0x18a0c4 ldr r3, [sp, #0x18] */
/* @0x18a0c8 ldr r0, [r3, #0x14] */
/* @0x18a0cc blx 0x2a7840 <png_read_image> */
/* @0x18a0d0 mov r0, #1 */
/* @0x18a0d4 add sp, sp, #56 */
/* @0x18a0d8 pop {r4, pc} */
/* @0x18a0dc ldr r0, [sp, #0x1c] */
/* @0x18a0e0 ldr r3, [pc, #0x158] */
/* @0x18a0e4 ldr r1, [pc, #0x158] */
/* @0x18a0e8 ldr r3, [r0, r3] */
/* @0x18a0ec add r1, pc, r1 */
/* @0x18a0f0 ldr r4, [r3] */
/* @0x18a0f4 ldr r3, [r4] */
/* @0x18a0f8 mov r0, r4 */
/* @0x18a0fc ldr r3, [r3, #0xc] */
/* @0x18a100 blx r3 */
/* @0x18a104 mov r0, r4 */
/* @0x18a108 ldr r3, [r0] */
/* @0x18a10c mov r2, #1 */
/* @0x18a110 ldr r12, [sp, #0x18] */
/* @0x18a114 ldr r1, [pc, #0x12c] */
/* @0x18a118 ldr r3, [r3, #0xc] */
/* @0x18a11c add r1, pc, r1 */
/* @0x18a120 strb r2, [r12] */
/* @0x18a124 blx r3 */
/* @0x18a128 mov r0, #0 */
/* @0x18a12c add sp, sp, #56 */
/* @0x18a130 pop {r4, pc} */
/* @0x18a134 mov r2, r0 */
/* @0x18a138 add r0, r1, #20 */
/* @0x18a13c add r1, r1, #24 */
/* @0x18a140 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x18a144 ldr r3, [pc, #0xf4] */
/* @0x18a148 ldr r12, [sp, #0x1c] */
/* @0x18a14c ldr r3, [r12, r3] */
/* @0x18a150 ldr r0, [r3] */
/* @0x18a154 b 0x18a108 <_Z7ReadPNGP9yyPNGFile+0x288> */
/* @0x18a158 ldr r0, [sp, #0x2c] */
/* @0x18a15c mul r0, r0, r4 */
/* @0x18a160 bl 0x27d14c <_Znaj> */
/* @0x18a164 ldr r1, [sp, #0x18] */
/* @0x18a168 cmp r0, #0 */
/* @0x18a16c str r0, [r1, #0x20] */
/* @0x18a170 bne 0x18a058 <_Z7ReadPNGP9yyPNGFile+0x1d8> */
/* @0x18a174 ldr r1, [sp, #0x18] */
/* @0x18a178 ldr r3, [sp, #0x18] */
/* @0x18a17c add r0, r1, #20 */
/* @0x18a180 add r1, r1, #24 */
/* @0x18a184 add r2, r3, #28 */
/* @0x18a188 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x18a18c ldr r3, [pc, #0xac] */
/* @0x18a190 ldr r12, [sp, #0x1c] */
/* @0x18a194 ldr r3, [r12, r3] */
/* @0x18a198 ldr r0, [r3] */
/* @0x18a19c b 0x18a108 <_Z7ReadPNGP9yyPNGFile+0x288> */
/* @0x18a1a0 ldr r1, [sp, #0x18] */
/* @0x18a1a4 mov r2, #1 */
/* @0x18a1a8 ldr r0, [r1, #0x14] */
/* @0x18a1ac mov r1, #255 */
/* @0x18a1b0 blx 0x2af812 <png_set_add_alpha> */
/* @0x18a1b4 b 0x189fd0 <_Z7ReadPNGP9yyPNGFile+0x150> */
/* @0x18a1b8 mov r1, r0 */
/* @0x18a1bc add r0, r3, #20 */
/* @0x18a1c0 mov r2, r1 */
/* @0x18a1c4 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x18a1c8 b 0x18a144 <_Z7ReadPNGP9yyPNGFile+0x2c4> */
/* @0x18a1cc ldr r3, [sp, #0x18] */
/* @0x18a1d0 ldr r0, [r3, #0x14] */
/* @0x18a1d4 blx 0x2a880a <png_set_gray_to_rgb> */
/* @0x18a1d8 ldr r3, [sp, #0x28] */
/* @0x18a1dc b 0x189fb0 <_Z7ReadPNGP9yyPNGFile+0x130> */
/* @0x18a1e0 ldr r1, [sp, #0x18] */
/* @0x18a1e4 mov r2, r4 */
/* @0x18a1e8 add r3, sp, #44 */
/* @0x18a1ec ldr r0, [r1, #0x14] */
/* @0x18a1f0 ldr r1, [r1, #0x18] */
/* @0x18a1f4 str r4, [sp] */
/* @0x18a1f8 blx 0x2a6b56 <png_get_tRNS> */
/* @0x18a1fc cmp r0, #0 */
/* @0x18a200 moveq r4, r0 */
/* @0x18a204 beq 0x18a214 <_Z7ReadPNGP9yyPNGFile+0x394> */
/* @0x18a208 ldr r4, [sp, #0x2c] */
/* @0x18a20c adds r4, r4, #0 */
/* @0x18a210 movne r4, #1 */
/* @0x18a214 ldr r3, [sp, #0x28] */
/* @0x18a218 b 0x189fa8 <_Z7ReadPNGP9yyPNGFile+0x128> */
/* @0x18a21c ldr r0, [r12, #0x14] */
/* @0x18a220 blx 0x2a87b0 <png_set_palette_to_rgb> */
/* @0x18a224 b 0x18a024 <_Z7ReadPNGP9yyPNGFile+0x1a4> */
/* @0x18a228 mov r1, r0 */
/* @0x18a22c b 0x18a0c4 <_Z7ReadPNGP9yyPNGFile+0x244> */
/* @0x18a230 .word 0x00267db0 */
/* @0x18a234 andseq r0, r12, r0, lsl #15 */
/* @0x18a238 .word 0xffffe4ac */
/* @0x18a23c .word 0xfffff2c4 */
/* @0x18a240 .word 0xffffbac4 */
/* @0x18a244 andseq r1, r12, r0, ror #31 */
/* @0x18a248 ldrsheq r1, [r12], -r8 */

/* ── FUNC 0x18a24c · ReadPNGFile(void*, int, int*, int*, bool) · size=356 · insn=89 */
/* @0x18a24c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18a250 sub sp, sp, #20 */
/* @0x18a254 ldr r5, [pc, #0x14c] */
/* @0x18a258 mov r9, r0 */
/* @0x18a25c ldr r12, [pc, #0x148] */
/* @0x18a260 mov r7, r2 */
/* @0x18a264 ldrb lr, [sp, #0x30] */
/* @0x18a268 ldr r5, [pc, r5] */
/* @0x18a26c ldr r12, [pc, r12] */
/* @0x18a270 mov r8, r3 */
/* @0x18a274 cmp lr, #0 */
/* @0x18a278 ldr r6, [r5] */
/* @0x18a27c ldr r4, [r12] */
/* @0x18a280 moveq r4, #1 */
/* @0x18a284 cmp r6, #0 */
/* @0x18a288 beq 0x18a2c0 <_Z11ReadPNGFilePviPiS0_b+0x74> */
/* @0x18a28c ldr r3, [r6, #0xc] */
/* @0x18a290 mov r0, r3 */
/* @0x18a294 mov r1, r4 */
/* @0x18a298 bl 0x318d10 <__divsi3> */
/* @0x18a29c mov r1, r4 */
/* @0x18a2a0 str r0, [r7] */
/* @0x18a2a4 ldr r0, [r6, #0x10] */
/* @0x18a2a8 bl 0x318d10 <__divsi3> */
/* @0x18a2ac ldr r3, [r6, #0x20] */
/* @0x18a2b0 str r0, [r8] */
/* @0x18a2b4 mov r0, r3 */
/* @0x18a2b8 add sp, sp, #20 */
/* @0x18a2bc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18a2c0 mov r0, #40 */
/* @0x18a2c4 str r1, [sp, #0xc] */
/* @0x18a2c8 bl 0x27c524 <_Znwj> */
/* @0x18a2cc ldr r1, [sp, #0xc] */
/* @0x18a2d0 strb r6, [r0] */
/* @0x18a2d4 str r6, [r0, #0x20] */
/* @0x18a2d8 str r6, [r0, #0x24] */
/* @0x18a2dc str r9, [r0, #0x4] */
/* @0x18a2e0 str r1, [r0, #0x8] */
/* @0x18a2e4 str r0, [r5] */
/* @0x18a2e8 bl 0x189e80 <_Z7ReadPNGP9yyPNGFile> */
/* @0x18a2ec subs r6, r0, #0 */
/* @0x18a2f0 beq 0x18a380 <_Z11ReadPNGFilePviPiS0_b+0x134> */
/* @0x18a2f4 cmp r4, #1 */
/* @0x18a2f8 ble 0x18a3a0 <_Z11ReadPNGFilePviPiS0_b+0x154> */
/* @0x18a2fc ldr r1, [r5] */
/* @0x18a300 ldr r3, [r1, #0xc] */
/* @0x18a304 cmp r3, #1 */
/* @0x18a308 ble 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c> */
/* @0x18a30c ldr r0, [r1, #0x10] */
/* @0x18a310 cmp r0, #1 */
/* @0x18a314 movgt r6, r4 */
/* @0x18a318 bgt 0x18a330 <_Z11ReadPNGFilePviPiS0_b+0xe4> */
/* @0x18a31c b 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c> */
/* @0x18a320 cmp r3, #1 */
/* @0x18a324 ble 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c> */
/* @0x18a328 cmp r0, #1 */
/* @0x18a32c ble 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c> */
/* @0x18a330 ldr r2, [r1, #0x20] */
/* @0x18a334 asr r1, r0, #1 */
/* @0x18a338 str r0, [sp] */
/* @0x18a33c asr r0, r3, #1 */
/* @0x18a340 asr r6, r6, #1 */
/* @0x18a344 str r2, [sp, #0x4] */
/* @0x18a348 bl 0x18923c <_Z15HalfTextureRGBAiiPjiiS_> */
/* @0x18a34c ldr r1, [r5] */
/* @0x18a350 cmp r6, #1 */
/* @0x18a354 ldr r12, [r1, #0xc] */
/* @0x18a358 ldr r0, [r1, #0x10] */
/* @0x18a35c add r12, r12, r12, lsr #31 */
/* @0x18a360 add r0, r0, r0, lsr #31 */
/* @0x18a364 asr r3, r12, #1 */
/* @0x18a368 str r3, [r1, #0xc] */
/* @0x18a36c asr r0, r0, #1 */
/* @0x18a370 str r0, [r1, #0x10] */
/* @0x18a374 bgt 0x18a320 <_Z11ReadPNGFilePviPiS0_b+0xd4> */
/* @0x18a378 mov r6, r1 */
/* @0x18a37c b 0x18a290 <_Z11ReadPNGFilePviPiS0_b+0x44> */
/* @0x18a380 ldr r0, [r5] */
/* @0x18a384 bl 0x27d1d0 <_ZdlPv> */
/* @0x18a388 str r6, [r5] */
/* @0x18a38c mvn r2, #0 */
/* @0x18a390 mov r3, r6 */
/* @0x18a394 str r2, [r7] */
/* @0x18a398 str r2, [r8] */
/* @0x18a39c b 0x18a2b4 <_Z11ReadPNGFilePviPiS0_b+0x68> */
/* @0x18a3a0 ldr r6, [r5] */
/* @0x18a3a4 b 0x18a28c <_Z11ReadPNGFilePviPiS0_b+0x40> */
/* @0x18a3a8 eoreq r6, r6, r8, asr r3 */
/* @0x18a3ac eoreq r4, r6, r8, ror #6 */

/* ── FUNC 0x18a3b0 · ReadPNGFilePreallocated(void*, int, int*, int*, void*, bool) · size=360 · insn=90 */
/* @0x18a3b0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18a3b4 sub sp, sp, #20 */
/* @0x18a3b8 ldr r5, [pc, #0x150] */
/* @0x18a3bc mov r9, r0 */
/* @0x18a3c0 ldr r12, [pc, #0x14c] */
/* @0x18a3c4 mov r7, r2 */
/* @0x18a3c8 ldrb lr, [sp, #0x34] */
/* @0x18a3cc ldr r5, [pc, r5] */
/* @0x18a3d0 ldr r12, [pc, r12] */
/* @0x18a3d4 mov r8, r3 */
/* @0x18a3d8 cmp lr, #0 */
/* @0x18a3dc ldr r6, [r5] */
/* @0x18a3e0 ldr r4, [r12] */
/* @0x18a3e4 moveq r4, #1 */
/* @0x18a3e8 cmp r6, #0 */
/* @0x18a3ec beq 0x18a424 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x74> */
/* @0x18a3f0 ldr r3, [r6, #0xc] */
/* @0x18a3f4 mov r0, r3 */
/* @0x18a3f8 mov r1, r4 */
/* @0x18a3fc bl 0x318d10 <__divsi3> */
/* @0x18a400 mov r1, r4 */
/* @0x18a404 str r0, [r7] */
/* @0x18a408 ldr r0, [r6, #0x10] */
/* @0x18a40c bl 0x318d10 <__divsi3> */
/* @0x18a410 ldr r3, [r6, #0x20] */
/* @0x18a414 str r0, [r8] */
/* @0x18a418 mov r0, r3 */
/* @0x18a41c add sp, sp, #20 */
/* @0x18a420 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18a424 mov r0, #40 */
/* @0x18a428 str r1, [sp, #0xc] */
/* @0x18a42c bl 0x27c524 <_Znwj> */
/* @0x18a430 ldr r1, [sp, #0xc] */
/* @0x18a434 ldr r2, [sp, #0x30] */
/* @0x18a438 strb r6, [r0] */
/* @0x18a43c str r6, [r0, #0x24] */
/* @0x18a440 str r9, [r0, #0x4] */
/* @0x18a444 str r1, [r0, #0x8] */
/* @0x18a448 str r2, [r0, #0x20] */
/* @0x18a44c str r0, [r5] */
/* @0x18a450 bl 0x189e80 <_Z7ReadPNGP9yyPNGFile> */
/* @0x18a454 subs r6, r0, #0 */
/* @0x18a458 beq 0x18a4e8 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x138> */
/* @0x18a45c cmp r4, #1 */
/* @0x18a460 ble 0x18a508 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x158> */
/* @0x18a464 ldr r1, [r5] */
/* @0x18a468 ldr r3, [r1, #0xc] */
/* @0x18a46c cmp r3, #1 */
/* @0x18a470 ble 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130> */
/* @0x18a474 ldr r0, [r1, #0x10] */
/* @0x18a478 cmp r0, #1 */
/* @0x18a47c movgt r6, r4 */
/* @0x18a480 bgt 0x18a498 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0xe8> */
/* @0x18a484 b 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130> */
/* @0x18a488 cmp r3, #1 */
/* @0x18a48c ble 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130> */
/* @0x18a490 cmp r0, #1 */
/* @0x18a494 ble 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130> */
/* @0x18a498 ldr r2, [r1, #0x20] */
/* @0x18a49c asr r1, r0, #1 */
/* @0x18a4a0 str r0, [sp] */
/* @0x18a4a4 asr r0, r3, #1 */
/* @0x18a4a8 asr r6, r6, #1 */
/* @0x18a4ac str r2, [sp, #0x4] */
/* @0x18a4b0 bl 0x18923c <_Z15HalfTextureRGBAiiPjiiS_> */
/* @0x18a4b4 ldr r1, [r5] */
/* @0x18a4b8 cmp r6, #1 */
/* @0x18a4bc ldr r12, [r1, #0xc] */
/* @0x18a4c0 ldr r0, [r1, #0x10] */
/* @0x18a4c4 add r12, r12, r12, lsr #31 */
/* @0x18a4c8 add r0, r0, r0, lsr #31 */
/* @0x18a4cc asr r3, r12, #1 */
/* @0x18a4d0 str r3, [r1, #0xc] */
/* @0x18a4d4 asr r0, r0, #1 */
/* @0x18a4d8 str r0, [r1, #0x10] */
/* @0x18a4dc bgt 0x18a488 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0xd8> */
/* @0x18a4e0 mov r6, r1 */
/* @0x18a4e4 b 0x18a3f4 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x44> */
/* @0x18a4e8 ldr r0, [r5] */
/* @0x18a4ec bl 0x27d1d0 <_ZdlPv> */
/* @0x18a4f0 str r6, [r5] */
/* @0x18a4f4 mvn r2, #0 */
/* @0x18a4f8 mov r3, r6 */
/* @0x18a4fc str r2, [r7] */
/* @0x18a500 str r2, [r8] */
/* @0x18a504 b 0x18a418 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x68> */
/* @0x18a508 ldr r6, [r5] */
/* @0x18a50c b 0x18a3f0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x40> */
/* @0x18a510 .word 0x002661f4 */
/* @0x18a514 eoreq r4, r6, r4, lsl #4 */

/* ── FUNC 0x18a518 · FreePNGFile() · size=52 · insn=13 */
/* @0x18a518 push {r4, lr} */
/* @0x18a51c ldr r4, [pc, #0x24] */
/* @0x18a520 ldr r4, [pc, r4] */
/* @0x18a524 ldr r0, [r4] */
/* @0x18a528 cmp r0, #0 */
/* @0x18a52c popeq {r4, pc} */
/* @0x18a530 bl 0x189b3c <_Z7FreePNGP9yyPNGFile> */
/* @0x18a534 ldr r0, [r4] */
/* @0x18a538 bl 0x27d1d0 <_ZdlPv> */
/* @0x18a53c mov r3, #0 */
/* @0x18a540 str r3, [r4] */
/* @0x18a544 pop {r4, pc} */
/* @0x18a548 eoreq r6, r6, r0, lsr #1 */

/* ── FUNC 0x18a54c · ReadPNGFileHeader(void*, int, int*, int*, bool) · size=208 · insn=52 */
/* @0x18a54c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18a550 sub sp, sp, #12 */
/* @0x18a554 ldr r5, [pc, #0xb8] */
/* @0x18a558 mov r7, r0 */
/* @0x18a55c ldr r12, [pc, #0xb4] */
/* @0x18a560 mov r9, r2 */
/* @0x18a564 ldrb lr, [sp, #0x28] */
/* @0x18a568 ldr r5, [pc, r5] */
/* @0x18a56c ldr r12, [pc, r12] */
/* @0x18a570 mov r8, r3 */
/* @0x18a574 cmp lr, #0 */
/* @0x18a578 ldr r6, [r5] */
/* @0x18a57c ldr r4, [r12] */
/* @0x18a580 moveq r4, #1 */
/* @0x18a584 cmp r6, #0 */
/* @0x18a588 beq 0x18a5c0 <_Z17ReadPNGFileHeaderPviPiS0_b+0x74> */
/* @0x18a58c ldr r0, [r6, #0xc] */
/* @0x18a590 mov r1, r4 */
/* @0x18a594 bl 0x318d10 <__divsi3> */
/* @0x18a598 mov r1, r4 */
/* @0x18a59c mov r7, #1 */
/* @0x18a5a0 str r0, [r9] */
/* @0x18a5a4 ldr r0, [r6, #0x10] */
/* @0x18a5a8 bl 0x318d10 <__divsi3> */
/* @0x18a5ac str r0, [r8] */
/* @0x18a5b0 bl 0x18a518 <_Z11FreePNGFilev> */
/* @0x18a5b4 mov r0, r7 */
/* @0x18a5b8 add sp, sp, #12 */
/* @0x18a5bc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18a5c0 mov r0, #40 */
/* @0x18a5c4 str r1, [sp, #0x4] */
/* @0x18a5c8 bl 0x27c524 <_Znwj> */
/* @0x18a5cc ldr r1, [sp, #0x4] */
/* @0x18a5d0 strb r6, [r0] */
/* @0x18a5d4 str r7, [r0, #0x4] */
/* @0x18a5d8 str r6, [r0, #0x20] */
/* @0x18a5dc str r6, [r0, #0x24] */
/* @0x18a5e0 str r1, [r0, #0x8] */
/* @0x18a5e4 str r0, [r5] */
/* @0x18a5e8 bl 0x189b78 <_Z13ReadPNGHeaderP9yyPNGFile> */
/* @0x18a5ec subs r7, r0, #0 */
/* @0x18a5f0 ldrne r6, [r5] */
/* @0x18a5f4 bne 0x18a58c <_Z17ReadPNGFileHeaderPviPiS0_b+0x40> */
/* @0x18a5f8 ldr r0, [r5] */
/* @0x18a5fc bl 0x27d1d0 <_ZdlPv> */
/* @0x18a600 str r7, [r5] */
/* @0x18a604 mvn r3, #0 */
/* @0x18a608 str r3, [r9] */
/* @0x18a60c str r3, [r8] */
/* @0x18a610 b 0x18a5b4 <_Z17ReadPNGFileHeaderPviPiS0_b+0x68> */
/* @0x18a614 eoreq r6, r6, r8, asr r0 */
/* @0x18a618 eoreq r4, r6, r8, rrx */

/* ── FUNC 0x18a61c · anon_18a61c · size=68 · insn=18 */
/* @0x18a61c bx lr */
/* @0x18a620 mov r0, #1 */
/* @0x18a624 bx lr */
/* @0x18a628 ldr r2, [r0, #0x18] */
/* @0x18a62c cmp r1, #0 */
/* @0x18a630 ldr r3, [r2, #0x4] */
/* @0x18a634 bgt 0x18a640 <_Z17ReadPNGFileHeaderPviPiS0_b+0xf4> */
/* @0x18a638 b 0x18a648 <_Z17ReadPNGFileHeaderPviPiS0_b+0xfc> */
/* @0x18a63c rsb r1, r3, r1 */
/* @0x18a640 cmp r1, r3 */
/* @0x18a644 bgt 0x18a63c <_Z17ReadPNGFileHeaderPviPiS0_b+0xf0> */
/* @0x18a648 ldr r0, [r2] */
/* @0x18a64c rsb r3, r1, r3 */
/* @0x18a650 str r3, [r2, #0x4] */
/* @0x18a654 add r1, r0, r1 */
/* @0x18a658 str r1, [r2] */
/* @0x18a65c bx lr */
/* @0x18a660 bx lr */

/* ── FUNC 0x18a664 · ReadGifData(GifFileType*, unsigned char*, int) · size=44 · insn=11 */
/* @0x18a664 push {r3, r4, r5, lr} */
/* @0x18a668 mov r4, r0 */
/* @0x18a66c mov r0, r1 */
/* @0x18a670 ldr r1, [r4, #0x44] */
/* @0x18a674 mov r5, r2 */
/* @0x18a678 bl 0xb65bc <memcpy@plt> */
/* @0x18a67c ldr r3, [r4, #0x44] */
/* @0x18a680 mov r0, r5 */
/* @0x18a684 add r5, r3, r5 */
/* @0x18a688 str r5, [r4, #0x44] */
/* @0x18a68c pop {r3, r4, r5, pc} */

/* ── FUNC 0x18a690 · jpeg_memory_src(jpeg_decompress_struct*, unsigned char const*, unsigned int) · size=152 · insn=38 */
/* @0x18a690 ldr r3, [r0, #0x18] */
/* @0x18a694 push {r4, r5, r6, lr} */
/* @0x18a698 cmp r3, #0 */
/* @0x18a69c mov r4, r0 */
/* @0x18a6a0 mov r6, r1 */
/* @0x18a6a4 mov r5, r2 */
/* @0x18a6a8 beq 0x18a6f4 <_Z15jpeg_memory_srcP22jpeg_decompress_structPKhj+0x64> */
/* @0x18a6ac ldr r4, [pc, #0x60] */
/* @0x18a6b0 ldr r12, [pc, #0x60] */
/* @0x18a6b4 ldr r1, [pc, #0x60] */
/* @0x18a6b8 add r4, pc, r4 */
/* @0x18a6bc ldr r2, [pc, #0x5c] */
/* @0x18a6c0 add r12, pc, r12 */
/* @0x18a6c4 ldr r0, [pc, #0x58] */
/* @0x18a6c8 add r1, pc, r1 */
/* @0x18a6cc add r2, pc, r2 */
/* @0x18a6d0 str r6, [r3] */
/* @0x18a6d4 ldr r0, [pc, r0] */
/* @0x18a6d8 str r5, [r3, #0x4] */
/* @0x18a6dc str r4, [r3, #0x8] */
/* @0x18a6e0 str r0, [r3, #0x14] */
/* @0x18a6e4 str r12, [r3, #0xc] */
/* @0x18a6e8 str r1, [r3, #0x10] */
/* @0x18a6ec str r2, [r3, #0x18] */
/* @0x18a6f0 pop {r4, r5, r6, pc} */
/* @0x18a6f4 ldr r12, [r0, #0x4] */
/* @0x18a6f8 mov r1, r3 */
/* @0x18a6fc mov r2, #32 */
/* @0x18a700 ldr r3, [r12] */
/* @0x18a704 blx r3 */
/* @0x18a708 mov r3, r0 */
/* @0x18a70c str r0, [r4, #0x18] */
/* @0x18a710 b 0x18a6ac <_Z15jpeg_memory_srcP22jpeg_decompress_structPKhj+0x1c> */
/* @0x18a714 .word 0xffffff5c */
/* @0x18a718 .word 0xffffff58 */
/* @0x18a71c .word 0xffffff58 */
/* @0x18a720 .word 0xffffff8c */
/* @0x18a724 .word 0x00265ef0 */

/* ── FUNC 0x18a728 · ReadJPEGFile(void*, int, int*, int*, bool) · size=496 · insn=124 */
/* @0x18a728 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18a72c mov r7, r3 */
/* @0x18a730 ldr r6, [pc, #0x1d8] */
/* @0x18a734 sub sp, sp, #580 */
/* @0x18a738 mov r9, r0 */
/* @0x18a73c add r0, sp, #4 */
/* @0x18a740 ldr r6, [pc, r6] */
/* @0x18a744 mov r5, r1 */
/* @0x18a748 mov r8, r2 */
/* @0x18a74c add r4, sp, #576 */
/* @0x18a750 ldr r3, [r6] */
/* @0x18a754 str r3, [sp, #0x23c] */
/* @0x18a758 bl 0x2b8fc0 <jpeg_std_error> */
/* @0x18a75c mov r1, #62 */
/* @0x18a760 mov r2, #432 */
/* @0x18a764 str r0, [r4, #-0x1b8]! */
/* @0x18a768 mov r0, r4 */
/* @0x18a76c bl 0x2b2dfc <jpeg_CreateDecompress> */
/* @0x18a770 mov r0, r4 */
/* @0x18a774 mov r1, r9 */
/* @0x18a778 mov r2, r5 */
/* @0x18a77c bl 0x18a690 <_Z15jpeg_memory_srcP22jpeg_decompress_structPKhj> */
/* @0x18a780 mov r0, r4 */
/* @0x18a784 mov r1, #0 */
/* @0x18a788 bl 0x2b31b8 <jpeg_read_header> */
/* @0x18a78c cmp r0, #2 */
/* @0x18a790 beq 0x18a780 <_Z12ReadJPEGFilePviPiS0_b+0x58> */
/* @0x18a794 cmp r0, #0 */
/* @0x18a798 beq 0x18a8f4 <_Z12ReadJPEGFilePviPiS0_b+0x1cc> */
/* @0x18a79c mov r0, r4 */
/* @0x18a7a0 ldr r5, [pc, #0x16c] */
/* @0x18a7a4 bl 0x2b34a8 <jpeg_start_decompress> */
/* @0x18a7a8 ldr r0, [sp, #0xe4] */
/* @0x18a7ac ldr lr, [sp, #0xac] */
/* @0x18a7b0 add r5, pc, r5 */
/* @0x18a7b4 ldr r12, [sp, #0xe8] */
/* @0x18a7b8 mov r2, #111 */
/* @0x18a7bc str r0, [r8] */
/* @0x18a7c0 mov r1, r5 */
/* @0x18a7c4 mov r3, #1 */
/* @0x18a7c8 str r12, [r7] */
/* @0x18a7cc mul r0, lr, r0 */
/* @0x18a7d0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18a7d4 ldr r12, [sp, #0xe4] */
/* @0x18a7d8 ldr lr, [sp, #0xe8] */
/* @0x18a7dc mov r1, r5 */
/* @0x18a7e0 mov r2, #114 */
/* @0x18a7e4 mov r3, #1 */
/* @0x18a7e8 mul r12, lr, r12 */
/* @0x18a7ec str r0, [sp] */
/* @0x18a7f0 lsl r0, r12, #2 */
/* @0x18a7f4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18a7f8 mov r7, r0 */
/* @0x18a7fc mov r8, r0 */
/* @0x18a800 ldr r2, [sp, #0x100] */
/* @0x18a804 mov r0, r4 */
/* @0x18a808 ldr r3, [sp, #0xa8] */
/* @0x18a80c cmp r2, r3 */
/* @0x18a810 bhs 0x18a8dc <_Z12ReadJPEGFilePviPiS0_b+0x1b4> */
/* @0x18a814 mov r1, sp */
/* @0x18a818 mov r2, #1 */
/* @0x18a81c bl 0x2b35c0 <jpeg_read_scanlines> */
/* @0x18a820 ldr r1, [sp, #0xa4] */
/* @0x18a824 ldr r2, [sp] */
/* @0x18a828 cmp r1, #0 */
/* @0x18a82c beq 0x18a800 <_Z12ReadJPEGFilePviPiS0_b+0xd8> */
/* @0x18a830 add r3, r8, #4 */
/* @0x18a834 mov lr, #0 */
/* @0x18a838 b 0x18a878 <_Z12ReadJPEGFilePviPiS0_b+0x150> */
/* @0x18a83c cmp r12, #4 */
/* @0x18a840 beq 0x18a8ac <_Z12ReadJPEGFilePviPiS0_b+0x184> */
/* @0x18a844 cmp r12, #1 */
/* @0x18a848 bne 0x18a864 <_Z12ReadJPEGFilePviPiS0_b+0x13c> */
/* @0x18a84c ldrb r1, [r2], #1 */
/* @0x18a850 orr r0, r1, #-16777216 */
/* @0x18a854 orr r0, r0, r1, lsl #16 */
/* @0x18a858 orr r1, r0, r1, lsl #8 */
/* @0x18a85c str r1, [r3, #-0x4] */
/* @0x18a860 ldr r1, [sp, #0xa4] */
/* @0x18a864 add lr, lr, #1 */
/* @0x18a868 mov r8, r3 */
/* @0x18a86c cmp r1, lr */
/* @0x18a870 add r3, r3, #4 */
/* @0x18a874 bls 0x18a800 <_Z12ReadJPEGFilePviPiS0_b+0xd8> */
/* @0x18a878 ldr r12, [sp, #0xac] */
/* @0x18a87c cmp r12, #3 */
/* @0x18a880 bne 0x18a83c <_Z12ReadJPEGFilePviPiS0_b+0x114> */
/* @0x18a884 ldrb r1, [r2] */
/* @0x18a888 add r2, r2, #3 */
/* @0x18a88c ldrb r12, [r2, #-0x1] */
/* @0x18a890 ldrb r0, [r2, #-0x2] */
/* @0x18a894 orr r1, r1, #-16777216 */
/* @0x18a898 orr r1, r1, r12, lsl #16 */
/* @0x18a89c orr r1, r1, r0, lsl #8 */
/* @0x18a8a0 str r1, [r3, #-0x4] */
/* @0x18a8a4 ldr r1, [sp, #0xa4] */
/* @0x18a8a8 b 0x18a864 <_Z12ReadJPEGFilePviPiS0_b+0x13c> */
/* @0x18a8ac ldrb r1, [r2, #0x2] */
/* @0x18a8b0 add r2, r2, #4 */
/* @0x18a8b4 ldrb r8, [r2, #-0x1] */
/* @0x18a8b8 ldrb r12, [r2, #-0x4] */
/* @0x18a8bc ldrb r0, [r2, #-0x3] */
/* @0x18a8c0 lsl r1, r1, #16 */
/* @0x18a8c4 orr r1, r1, r8, lsl #24 */
/* @0x18a8c8 orr r1, r1, r12 */
/* @0x18a8cc orr r1, r1, r0, lsl #8 */
/* @0x18a8d0 str r1, [r3, #-0x4] */
/* @0x18a8d4 ldr r1, [sp, #0xa4] */
/* @0x18a8d8 b 0x18a864 <_Z12ReadJPEGFilePviPiS0_b+0x13c> */
/* @0x18a8dc bl 0x2b32c0 <jpeg_finish_decompress> */
/* @0x18a8e0 mov r0, r4 */
/* @0x18a8e4 bl 0x2b2f00 <jpeg_destroy_decompress> */
/* @0x18a8e8 ldr r0, [sp] */
/* @0x18a8ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18a8f0 mov r0, r7 */
/* @0x18a8f4 ldr r2, [sp, #0x23c] */
/* @0x18a8f8 ldr r3, [r6] */
/* @0x18a8fc cmp r2, r3 */
/* @0x18a900 bne 0x18a90c <_Z12ReadJPEGFilePviPiS0_b+0x1e4> */
/* @0x18a904 add sp, sp, #580 */
/* @0x18a908 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18a90c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18a910 eoreq r3, r6, r0, lsl r2 */
/* @0x18a914 andseq r1, r12, r4, lsl #19 */

/* ── FUNC 0x18a918 · ReadGIFFile(void*, int, int*, int*, bool) · size=340 · insn=85 */
/* @0x18a918 ldr r1, [pc, #0x144] */
/* @0x18a91c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18a920 sub sp, sp, #12 */
/* @0x18a924 mov r9, r2 */
/* @0x18a928 ldr r1, [pc, r1] */
/* @0x18a92c add r2, sp, #4 */
/* @0x18a930 mov r6, r3 */
/* @0x18a934 bl 0x2c1c50 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi> */
/* @0x18a938 subs r5, r0, #0 */
/* @0x18a93c beq 0x18aa50 <_Z11ReadGIFFilePviPiS0_b+0x138> */
/* @0x18a940 bl 0x2c2918 <_Z9DGifSlurpP11GifFileType> */
/* @0x18a944 cmp r0, #1 */
/* @0x18a948 bne 0x18aa50 <_Z11ReadGIFFilePviPiS0_b+0x138> */
/* @0x18a94c ldr r8, [r5, #0x34] */
/* @0x18a950 ldr r12, [r8, #0x1c] */
/* @0x18a954 cmp r12, #0 */
/* @0x18a958 ble 0x18aa5c <_Z11ReadGIFFilePviPiS0_b+0x144> */
/* @0x18a95c add r12, r12, r12, lsl #1 */
/* @0x18a960 ldr r1, [r8, #0x20] */
/* @0x18a964 mvn r4, #0 */
/* @0x18a968 add r12, r1, r12, lsl #2 */
/* @0x18a96c b 0x18a97c <_Z11ReadGIFFilePviPiS0_b+0x64> */
/* @0x18a970 add r1, r1, #12 */
/* @0x18a974 cmp r1, r12 */
/* @0x18a978 beq 0x18a9b0 <_Z11ReadGIFFilePviPiS0_b+0x98> */
/* @0x18a97c ldr r0, [r1, #0x8] */
/* @0x18a980 cmp r0, #249 */
/* @0x18a984 bne 0x18a970 <_Z11ReadGIFFilePviPiS0_b+0x58> */
/* @0x18a988 ldr r3, [r1] */
/* @0x18a98c cmp r3, #4 */
/* @0x18a990 bne 0x18a970 <_Z11ReadGIFFilePviPiS0_b+0x58> */
/* @0x18a994 ldr r3, [r1, #0x4] */
/* @0x18a998 add r1, r1, #12 */
/* @0x18a99c ldrb r2, [r3] */
/* @0x18a9a0 tst r2, #1 */
/* @0x18a9a4 ldrbne r4, [r3, #0x3] */
/* @0x18a9a8 cmp r1, r12 */
/* @0x18a9ac bne 0x18a97c <_Z11ReadGIFFilePviPiS0_b+0x64> */
/* @0x18a9b0 ldr r7, [r5] */
/* @0x18a9b4 mov r2, #200 */
/* @0x18a9b8 ldr r1, [pc, #0xa8] */
/* @0x18a9bc mov r3, #1 */
/* @0x18a9c0 str r7, [r9] */
/* @0x18a9c4 add r1, pc, r1 */
/* @0x18a9c8 ldr r0, [r5, #0x4] */
/* @0x18a9cc mul r7, r0, r7 */
/* @0x18a9d0 str r0, [r6] */
/* @0x18a9d4 lsl r0, r7, #2 */
/* @0x18a9d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18a9dc cmp r7, #0 */
/* @0x18a9e0 ldr r2, [r8, #0x18] */
/* @0x18a9e4 addgt r7, r2, r7 */
/* @0x18a9e8 mov r6, r0 */
/* @0x18a9ec ldr r0, [r5, #0x14] */
/* @0x18a9f0 movgt r3, r6 */
/* @0x18a9f4 ble 0x18aa3c <_Z11ReadGIFFilePviPiS0_b+0x124> */
/* @0x18a9f8 ldrb r12, [r2] */
/* @0x18a9fc add r3, r3, #4 */
/* @0x18aa00 ldr lr, [r0, #0xc] */
/* @0x18aa04 add r12, r12, r12, lsl #1 */
/* @0x18aa08 add r1, lr, r12 */
/* @0x18aa0c ldrb r12, [lr, r12] */
/* @0x18aa10 strb r12, [r3, #-0x4] */
/* @0x18aa14 ldrb r12, [r1, #0x1] */
/* @0x18aa18 strb r12, [r3, #-0x3] */
/* @0x18aa1c ldrb r1, [r1, #0x2] */
/* @0x18aa20 strb r1, [r3, #-0x2] */
/* @0x18aa24 ldrb r1, [r2], #1 */
/* @0x18aa28 subs r1, r1, r4 */
/* @0x18aa2c mvnne r1, #0 */
/* @0x18aa30 cmp r2, r7 */
/* @0x18aa34 strb r1, [r3, #-0x1] */
/* @0x18aa38 bne 0x18a9f8 <_Z11ReadGIFFilePviPiS0_b+0xe0> */
/* @0x18aa3c mov r0, r5 */
/* @0x18aa40 bl 0x2c24e4 <_Z13DGifCloseFileP11GifFileType> */
/* @0x18aa44 mov r0, r6 */
/* @0x18aa48 add sp, sp, #12 */
/* @0x18aa4c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18aa50 mov r0, #0 */
/* @0x18aa54 add sp, sp, #12 */
/* @0x18aa58 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18aa5c mvn r4, #0 */
/* @0x18aa60 b 0x18a9b0 <_Z11ReadGIFFilePviPiS0_b+0x98> */
/* @0x18aa64 eoreq r5, r6, r0, lsr #25 */
/* @0x18aa68 andseq r1, r12, r0, ror r7 */

/* ── FUNC 0x18aa6c · CIAPPurchase::SetFromPurchase(CIAPPurchase const&) · size=212 · insn=53 */
/* @0x18aa6c push {r4, r5, r6, lr} */
/* @0x18aa70 mov r4, r0 */
/* @0x18aa74 ldr r0, [r0, #0x4] */
/* @0x18aa78 mov r5, r1 */
/* @0x18aa7c ldr r6, [r1, #0x4] */
/* @0x18aa80 cmp r0, #0 */
/* @0x18aa84 beq 0x18aa8c <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x20> */
/* @0x18aa88 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18aa8c mov r0, r6 */
/* @0x18aa90 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18aa94 ldr r3, [r4] */
/* @0x18aa98 cmp r3, #0 */
/* @0x18aa9c str r0, [r4, #0x4] */
/* @0x18aaa0 ldr r6, [r5] */
/* @0x18aaa4 beq 0x18aab0 <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x44> */
/* @0x18aaa8 mov r0, r3 */
/* @0x18aaac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18aab0 mov r0, r6 */
/* @0x18aab4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18aab8 ldr r3, [r4, #0x8] */
/* @0x18aabc cmp r3, #0 */
/* @0x18aac0 str r0, [r4] */
/* @0x18aac4 ldr r6, [r5, #0x8] */
/* @0x18aac8 beq 0x18aad4 <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x68> */
/* @0x18aacc mov r0, r3 */
/* @0x18aad0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18aad4 mov r0, r6 */
/* @0x18aad8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18aadc ldr r3, [r4, #0xc] */
/* @0x18aae0 cmp r3, #0 */
/* @0x18aae4 str r0, [r4, #0x8] */
/* @0x18aae8 ldr r6, [r5, #0xc] */
/* @0x18aaec beq 0x18aaf8 <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0x8c> */
/* @0x18aaf0 mov r0, r3 */
/* @0x18aaf4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18aaf8 mov r0, r6 */
/* @0x18aafc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18ab00 ldr r3, [r4, #0x10] */
/* @0x18ab04 cmp r3, #0 */
/* @0x18ab08 str r0, [r4, #0xc] */
/* @0x18ab0c ldr r6, [r5, #0x10] */
/* @0x18ab10 beq 0x18ab1c <_ZN12CIAPPurchase15SetFromPurchaseERKS_+0xb0> */
/* @0x18ab14 mov r0, r3 */
/* @0x18ab18 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18ab1c mov r0, r6 */
/* @0x18ab20 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18ab24 add r1, r5, #20 */
/* @0x18ab28 ldm r1, {r1, r2, r3} */
/* @0x18ab2c str r1, [r4, #0x14] */
/* @0x18ab30 str r2, [r4, #0x18] */
/* @0x18ab34 str r3, [r4, #0x1c] */
/* @0x18ab38 str r0, [r4, #0x10] */
/* @0x18ab3c pop {r4, r5, r6, pc} */

/* ── FUNC 0x18ab40 · CIAPPurchase::SetFromJSON(json_object*) · size=760 · insn=190 */
/* @0x18ab40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18ab44 mov r7, r0 */
/* @0x18ab48 sub sp, sp, #20 */
/* @0x18ab4c mov r0, r1 */
/* @0x18ab50 bl 0x27e8f4 <json_object_get_object> */
/* @0x18ab54 mvn r3, #0 */
/* @0x18ab58 str r3, [sp, #0x8] */
/* @0x18ab5c ldr r4, [r0, #0x20] */
/* @0x18ab60 cmp r4, #0 */
/* @0x18ab64 beq 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18ab68 ldr r8, [pc, #0x2a4] */
/* @0x18ab6c ldr r9, [pc, #0x2a4] */
/* @0x18ab70 ldr r10, [pc, #0x2a4] */
/* @0x18ab74 add r8, pc, r8 */
/* @0x18ab78 ldr r11, [pc, #0x2a0] */
/* @0x18ab7c add r9, pc, r9 */
/* @0x18ab80 ldr r3, [pc, #0x29c] */
/* @0x18ab84 add r10, pc, r10 */
/* @0x18ab88 add r11, pc, r11 */
/* @0x18ab8c add r3, pc, r3 */
/* @0x18ab90 str r3, [sp, #0x4] */
/* @0x18ab94 ldr r3, [pc, #0x28c] */
/* @0x18ab98 add r3, pc, r3 */
/* @0x18ab9c str r3, [sp, #0xc] */
/* @0x18aba0 ldm r4, {r5, r6} */
/* @0x18aba4 cmp r6, #0 */
/* @0x18aba8 beq 0x18ac6c <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x12c> */
/* @0x18abac mov r0, r5 */
/* @0x18abb0 mov r1, r8 */
/* @0x18abb4 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18abb8 cmp r0, #0 */
/* @0x18abbc beq 0x18ac84 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x144> */
/* @0x18abc0 mov r0, r5 */
/* @0x18abc4 mov r1, r9 */
/* @0x18abc8 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18abcc cmp r0, #0 */
/* @0x18abd0 beq 0x18acbc <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x17c> */
/* @0x18abd4 mov r0, r5 */
/* @0x18abd8 mov r1, r10 */
/* @0x18abdc bl 0xb66d0 <strcasecmp@plt> */
/* @0x18abe0 cmp r0, #0 */
/* @0x18abe4 beq 0x18acf4 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x1b4> */
/* @0x18abe8 mov r0, r5 */
/* @0x18abec mov r1, r11 */
/* @0x18abf0 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18abf4 cmp r0, #0 */
/* @0x18abf8 beq 0x18ad10 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x1d0> */
/* @0x18abfc mov r0, r5 */
/* @0x18ac00 ldr r1, [sp, #0x4] */
/* @0x18ac04 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18ac08 cmp r0, #0 */
/* @0x18ac0c beq 0x18ad34 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x1f4> */
/* @0x18ac10 mov r0, r5 */
/* @0x18ac14 ldr r1, [sp, #0xc] */
/* @0x18ac18 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18ac1c cmp r0, #0 */
/* @0x18ac20 beq 0x18ad6c <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x22c> */
/* @0x18ac24 ldr r1, [pc, #0x200] */
/* @0x18ac28 mov r0, r5 */
/* @0x18ac2c add r1, pc, r1 */
/* @0x18ac30 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18ac34 cmp r0, #0 */
/* @0x18ac38 beq 0x18ad88 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x248> */
/* @0x18ac3c ldr r1, [pc, #0x1ec] */
/* @0x18ac40 mov r0, r5 */
/* @0x18ac44 add r1, pc, r1 */
/* @0x18ac48 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18ac4c cmp r0, #0 */
/* @0x18ac50 beq 0x18adc0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x280> */
/* @0x18ac54 ldr r1, [pc, #0x1d8] */
/* @0x18ac58 mov r0, r5 */
/* @0x18ac5c add r1, pc, r1 */
/* @0x18ac60 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18ac64 cmp r0, #0 */
/* @0x18ac68 beq 0x18adf8 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x2b8> */
/* @0x18ac6c ldr r4, [r4, #0x8] */
/* @0x18ac70 cmp r4, #0 */
/* @0x18ac74 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18ac78 ldr r0, [sp, #0x8] */
/* @0x18ac7c add sp, sp, #20 */
/* @0x18ac80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18ac84 mov r0, r6 */
/* @0x18ac88 bl 0x27ed58 <json_object_get_string> */
/* @0x18ac8c mov r5, r0 */
/* @0x18ac90 ldr r0, [r7] */
/* @0x18ac94 cmp r0, #0 */
/* @0x18ac98 beq 0x18aca0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x160> */
/* @0x18ac9c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18aca0 mov r0, r5 */
/* @0x18aca4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18aca8 str r0, [r7] */
/* @0x18acac ldr r4, [r4, #0x8] */
/* @0x18acb0 cmp r4, #0 */
/* @0x18acb4 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18acb8 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18acbc mov r0, r6 */
/* @0x18acc0 bl 0x27ed58 <json_object_get_string> */
/* @0x18acc4 mov r5, r0 */
/* @0x18acc8 ldr r0, [r7, #0x4] */
/* @0x18accc cmp r0, #0 */
/* @0x18acd0 beq 0x18acd8 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x198> */
/* @0x18acd4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18acd8 mov r0, r5 */
/* @0x18acdc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18ace0 str r0, [r7, #0x4] */
/* @0x18ace4 ldr r4, [r4, #0x8] */
/* @0x18ace8 cmp r4, #0 */
/* @0x18acec bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18acf0 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18acf4 mov r0, r6 */
/* @0x18acf8 bl 0x27eb28 <json_object_get_int> */
/* @0x18acfc ldr r4, [r4, #0x8] */
/* @0x18ad00 cmp r4, #0 */
/* @0x18ad04 str r0, [r7, #0x1c] */
/* @0x18ad08 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18ad0c b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18ad10 mov r0, r6 */
/* @0x18ad14 bl 0x27ebf0 <json_object_get_double> */
/* @0x18ad18 ldr r4, [r4, #0x8] */
/* @0x18ad1c cmp r4, #0 */
/* @0x18ad20 vmov d7, r0, r1 */
/* @0x18ad24 vcvt.s32.f64 s15, d7 */
/* @0x18ad28 vstr s15, [r7, #24] */
/* @0x18ad2c bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18ad30 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18ad34 mov r0, r6 */
/* @0x18ad38 bl 0x27ed58 <json_object_get_string> */
/* @0x18ad3c mov r5, r0 */
/* @0x18ad40 ldr r0, [r7, #0xc] */
/* @0x18ad44 cmp r0, #0 */
/* @0x18ad48 beq 0x18ad50 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x210> */
/* @0x18ad4c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18ad50 mov r0, r5 */
/* @0x18ad54 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18ad58 str r0, [r7, #0xc] */
/* @0x18ad5c ldr r4, [r4, #0x8] */
/* @0x18ad60 cmp r4, #0 */
/* @0x18ad64 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18ad68 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18ad6c mov r0, r6 */
/* @0x18ad70 bl 0x27eb28 <json_object_get_int> */
/* @0x18ad74 ldr r4, [r4, #0x8] */
/* @0x18ad78 cmp r4, #0 */
/* @0x18ad7c str r0, [r7, #0x14] */
/* @0x18ad80 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18ad84 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18ad88 mov r0, r6 */
/* @0x18ad8c bl 0x27ed58 <json_object_get_string> */
/* @0x18ad90 mov r5, r0 */
/* @0x18ad94 ldr r0, [r7, #0x10] */
/* @0x18ad98 cmp r0, #0 */
/* @0x18ad9c beq 0x18ada4 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x264> */
/* @0x18ada0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18ada4 mov r0, r5 */
/* @0x18ada8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18adac str r0, [r7, #0x10] */
/* @0x18adb0 ldr r4, [r4, #0x8] */
/* @0x18adb4 cmp r4, #0 */
/* @0x18adb8 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18adbc b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18adc0 mov r0, r6 */
/* @0x18adc4 bl 0x27ed58 <json_object_get_string> */
/* @0x18adc8 mov r5, r0 */
/* @0x18adcc ldr r0, [r7, #0x8] */
/* @0x18add0 cmp r0, #0 */
/* @0x18add4 beq 0x18addc <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x29c> */
/* @0x18add8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18addc mov r0, r5 */
/* @0x18ade0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18ade4 str r0, [r7, #0x8] */
/* @0x18ade8 ldr r4, [r4, #0x8] */
/* @0x18adec cmp r4, #0 */
/* @0x18adf0 bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18adf4 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18adf8 mov r0, r6 */
/* @0x18adfc bl 0x27eb28 <json_object_get_int> */
/* @0x18ae00 ldr r4, [r4, #0x8] */
/* @0x18ae04 cmp r4, #0 */
/* @0x18ae08 str r0, [sp, #0x8] */
/* @0x18ae0c bne 0x18aba0 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x60> */
/* @0x18ae10 b 0x18ac78 <_ZN12CIAPPurchase11SetFromJSONEP11json_object+0x138> */
/* @0x18ae14 ldrsheq r1, [r12], -r12 */
/* @0x18ae18 ldrheq r11, [r11], -r4 */
/* @0x18ae1c ldrsheq r1, [r12], -r4 */
/* @0x18ae20 andseq r1, r12, r0, lsl #12 */
/* @0x18ae24 andseq r1, r12, r12, lsl #12 */
/* @0x18ae28 andseq r11, r11, r8, ror r6 */
/* @0x18ae2c andseq r1, r12, r12, ror r5 */
/* @0x18ae30 andseq r1, r12, r8, ror r5 */
/* @0x18ae34 ldrsbeq r11, [r11], -r12 */

/* ── FUNC 0x18ae38 · CIAPPurchase::PopulateMap(int) · size=532 · insn=133 */
/* @0x18ae38 vmov s13, r1 */
/* @0x18ae3c mov r3, #1 */
/* @0x18ae40 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18ae44 vcvt.f64.s32 d7, s13 */
/* @0x18ae48 sub sp, sp, #76 */
/* @0x18ae4c mov r4, #0 */
/* @0x18ae50 add r5, sp, #8 */
/* @0x18ae54 mov r7, r0 */
/* @0x18ae58 add r6, sp, #24 */
/* @0x18ae5c mov r2, r4 */
/* @0x18ae60 mov r1, r4 */
/* @0x18ae64 mov r0, r5 */
/* @0x18ae68 str r6, [sp] */
/* @0x18ae6c add r8, sp, #40 */
/* @0x18ae70 str r4, [sp, #0x24] */
/* @0x18ae74 add r9, sp, #56 */
/* @0x18ae78 vstr d7, [sp, #24] */
/* @0x18ae7c bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x18ae80 ldr r1, [pc, #0x1a4] */
/* @0x18ae84 mov r0, r8 */
/* @0x18ae88 add r1, pc, r1 */
/* @0x18ae8c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x18ae90 ldr r1, [r7, #0x4] */
/* @0x18ae94 mov r0, r9 */
/* @0x18ae98 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x18ae9c mov r2, r4 */
/* @0x18aea0 mov r3, #3 */
/* @0x18aea4 mov r0, r5 */
/* @0x18aea8 mov r1, r4 */
/* @0x18aeac str r6, [sp] */
/* @0x18aeb0 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18aeb4 ldr r1, [pc, #0x174] */
/* @0x18aeb8 mov r0, r8 */
/* @0x18aebc add r1, pc, r1 */
/* @0x18aec0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18aec4 mov r0, r9 */
/* @0x18aec8 ldr r1, [r7] */
/* @0x18aecc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18aed0 mov r2, r4 */
/* @0x18aed4 mov r3, #3 */
/* @0x18aed8 mov r0, r5 */
/* @0x18aedc mov r1, r4 */
/* @0x18aee0 str r6, [sp] */
/* @0x18aee4 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18aee8 ldr r1, [pc, #0x144] */
/* @0x18aeec mov r0, r8 */
/* @0x18aef0 add r1, pc, r1 */
/* @0x18aef4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18aef8 mov r0, r9 */
/* @0x18aefc ldr r1, [r7, #0x8] */
/* @0x18af00 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18af04 mov r2, r4 */
/* @0x18af08 mov r3, #3 */
/* @0x18af0c mov r0, r5 */
/* @0x18af10 mov r1, r4 */
/* @0x18af14 str r6, [sp] */
/* @0x18af18 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18af1c ldr r1, [pc, #0x114] */
/* @0x18af20 mov r0, r8 */
/* @0x18af24 add r1, pc, r1 */
/* @0x18af28 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18af2c mov r0, r9 */
/* @0x18af30 ldr r1, [r7, #0x10] */
/* @0x18af34 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18af38 mov r2, r4 */
/* @0x18af3c mov r3, #3 */
/* @0x18af40 mov r0, r5 */
/* @0x18af44 mov r1, r4 */
/* @0x18af48 str r6, [sp] */
/* @0x18af4c bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18af50 ldr r1, [pc, #0xe4] */
/* @0x18af54 mov r0, r8 */
/* @0x18af58 add r1, pc, r1 */
/* @0x18af5c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18af60 mov r0, r9 */
/* @0x18af64 ldr r1, [r7, #0xc] */
/* @0x18af68 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18af6c mov r2, r4 */
/* @0x18af70 mov r0, r5 */
/* @0x18af74 mov r1, r4 */
/* @0x18af78 mov r3, #3 */
/* @0x18af7c str r6, [sp] */
/* @0x18af80 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18af84 ldr r1, [pc, #0xb4] */
/* @0x18af88 mov r0, r8 */
/* @0x18af8c add r1, pc, r1 */
/* @0x18af90 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18af94 vldr s14, [r7, #28] */
/* @0x18af98 vcvt.f64.s32 d7, s14 */
/* @0x18af9c mov r2, r4 */
/* @0x18afa0 mov r0, r5 */
/* @0x18afa4 mov r1, r4 */
/* @0x18afa8 mov r3, #3 */
/* @0x18afac str r6, [sp] */
/* @0x18afb0 str r4, [sp, #0x44] */
/* @0x18afb4 vstr d7, [sp, #56] */
/* @0x18afb8 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18afbc ldr r1, [pc, #0x80] */
/* @0x18afc0 mov r0, r8 */
/* @0x18afc4 add r1, pc, r1 */
/* @0x18afc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18afcc vldr s14, [r7, #24] */
/* @0x18afd0 vcvt.f64.s32 d7, s14 */
/* @0x18afd4 mov r2, r4 */
/* @0x18afd8 mov r0, r5 */
/* @0x18afdc mov r1, r4 */
/* @0x18afe0 mov r3, #3 */
/* @0x18afe4 str r6, [sp] */
/* @0x18afe8 vstr d7, [sp, #56] */
/* @0x18afec bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18aff0 ldr r1, [pc, #0x50] */
/* @0x18aff4 mov r0, r8 */
/* @0x18aff8 add r1, pc, r1 */
/* @0x18affc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b000 vldr s14, [r7, #20] */
/* @0x18b004 vcvt.f64.s32 d7, s14 */
/* @0x18b008 mov r1, r4 */
/* @0x18b00c str r6, [sp] */
/* @0x18b010 mov r0, r5 */
/* @0x18b014 mov r2, r4 */
/* @0x18b018 mov r3, #3 */
/* @0x18b01c vstr d7, [sp, #56] */
/* @0x18b020 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b024 add sp, sp, #76 */
/* @0x18b028 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18b02c andseq r11, r11, r8, lsr #5 */
/* @0x18b030 andseq r1, r12, r8, lsl #6 */
/* @0x18b034 andseq r1, r12, r12, asr #5 */
/* @0x18b038 andseq r11, r11, r4, lsr #4 */
/* @0x18b03c andseq r11, r11, r4, asr #5 */
/* @0x18b040 andseq r5, r10, r4, asr #21 */
/* @0x18b044 andseq r1, r12, r8, lsl #4 */
/* @0x18b048 andseq r11, r11, r8, lsl r2 */

/* ── FUNC 0x18b04c · CIAPProduct::SetFromProduct(CIAPProduct const&) · size=192 · insn=48 */
/* @0x18b04c push {r4, r5, r6, lr} */
/* @0x18b050 mov r4, r0 */
/* @0x18b054 ldr r0, [r0] */
/* @0x18b058 mov r5, r1 */
/* @0x18b05c ldr r6, [r1] */
/* @0x18b060 cmp r0, #0 */
/* @0x18b064 beq 0x18b06c <_ZN11CIAPProduct14SetFromProductERKS_+0x20> */
/* @0x18b068 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b06c mov r0, r6 */
/* @0x18b070 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b074 ldr r3, [r4, #0x4] */
/* @0x18b078 cmp r3, #0 */
/* @0x18b07c str r0, [r4] */
/* @0x18b080 ldr r6, [r5, #0x4] */
/* @0x18b084 beq 0x18b090 <_ZN11CIAPProduct14SetFromProductERKS_+0x44> */
/* @0x18b088 mov r0, r3 */
/* @0x18b08c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b090 mov r0, r6 */
/* @0x18b094 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b098 ldr r3, [r4, #0x8] */
/* @0x18b09c cmp r3, #0 */
/* @0x18b0a0 str r0, [r4, #0x4] */
/* @0x18b0a4 ldr r6, [r5, #0x8] */
/* @0x18b0a8 beq 0x18b0b4 <_ZN11CIAPProduct14SetFromProductERKS_+0x68> */
/* @0x18b0ac mov r0, r3 */
/* @0x18b0b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b0b4 mov r0, r6 */
/* @0x18b0b8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b0bc ldr r3, [r4, #0xc] */
/* @0x18b0c0 cmp r3, #0 */
/* @0x18b0c4 str r0, [r4, #0x8] */
/* @0x18b0c8 ldr r6, [r5, #0xc] */
/* @0x18b0cc beq 0x18b0d8 <_ZN11CIAPProduct14SetFromProductERKS_+0x8c> */
/* @0x18b0d0 mov r0, r3 */
/* @0x18b0d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b0d8 mov r0, r6 */
/* @0x18b0dc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b0e0 ldr r3, [r4, #0x10] */
/* @0x18b0e4 cmp r3, #0 */
/* @0x18b0e8 str r0, [r4, #0xc] */
/* @0x18b0ec ldr r5, [r5, #0x10] */
/* @0x18b0f0 beq 0x18b0fc <_ZN11CIAPProduct14SetFromProductERKS_+0xb0> */
/* @0x18b0f4 mov r0, r3 */
/* @0x18b0f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b0fc mov r0, r5 */
/* @0x18b100 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b104 str r0, [r4, #0x10] */
/* @0x18b108 pop {r4, r5, r6, pc} */

/* ── FUNC 0x18b10c · CIAPProduct::GetProductType(CIAPProduct const&) · size=92 · insn=23 */
/* @0x18b10c push {r4, lr} */
/* @0x18b110 ldr r4, [r0, #0x10] */
/* @0x18b114 cmp r4, #0 */
/* @0x18b118 beq 0x18b158 <_ZN11CIAPProduct14GetProductTypeERKS_+0x4c> */
/* @0x18b11c ldr r1, [pc, #0x3c] */
/* @0x18b120 mov r0, r4 */
/* @0x18b124 add r1, pc, r1 */
/* @0x18b128 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b12c cmp r0, #0 */
/* @0x18b130 bne 0x18b13c <_ZN11CIAPProduct14GetProductTypeERKS_+0x30> */
/* @0x18b134 mov r0, #2 */
/* @0x18b138 pop {r4, pc} */
/* @0x18b13c ldr r1, [pc, #0x20] */
/* @0x18b140 mov r0, r4 */
/* @0x18b144 add r1, pc, r1 */
/* @0x18b148 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b14c adds r0, r0, #0 */
/* @0x18b150 movne r0, #1 */
/* @0x18b154 pop {r4, pc} */
/* @0x18b158 mov r0, #1 */
/* @0x18b15c pop {r4, pc} */
/* @0x18b160 ldrheq r1, [r12], -r0 */
/* @0x18b164 andseq r1, r12, r0, lsr #1 */

/* ── FUNC 0x18b168 · CIAPProduct::SetFromJSON(json_object*) · size=476 · insn=119 */
/* @0x18b168 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18b16c mov r6, r0 */
/* @0x18b170 sub sp, sp, #12 */
/* @0x18b174 mov r0, r1 */
/* @0x18b178 bl 0x27e8f4 <json_object_get_object> */
/* @0x18b17c ldr r4, [r0, #0x20] */
/* @0x18b180 cmp r4, #0 */
/* @0x18b184 beq 0x18b278 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x110> */
/* @0x18b188 ldr r7, [pc, #0x1a0] */
/* @0x18b18c ldr r8, [pc, #0x1a0] */
/* @0x18b190 ldr r9, [pc, #0x1a0] */
/* @0x18b194 add r7, pc, r7 */
/* @0x18b198 ldr r10, [pc, #0x19c] */
/* @0x18b19c add r8, pc, r8 */
/* @0x18b1a0 ldr r3, [pc, #0x198] */
/* @0x18b1a4 add r9, pc, r9 */
/* @0x18b1a8 add r10, pc, r10 */
/* @0x18b1ac add r3, pc, r3 */
/* @0x18b1b0 str r3, [sp, #0x4] */
/* @0x18b1b4 b 0x18b1c4 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x5c> */
/* @0x18b1b8 ldr r4, [r4, #0x8] */
/* @0x18b1bc cmp r4, #0 */
/* @0x18b1c0 beq 0x18b278 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x110> */
/* @0x18b1c4 ldm r4, {r5, r11} */
/* @0x18b1c8 cmp r11, #0 */
/* @0x18b1cc beq 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b1d0 mov r0, r11 */
/* @0x18b1d4 bl 0x27e828 <json_object_get_type> */
/* @0x18b1d8 cmp r0, #6 */
/* @0x18b1dc bne 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b1e0 mov r0, r5 */
/* @0x18b1e4 mov r1, r7 */
/* @0x18b1e8 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b1ec cmp r0, #0 */
/* @0x18b1f0 beq 0x18b280 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x118> */
/* @0x18b1f4 mov r0, r5 */
/* @0x18b1f8 mov r1, r8 */
/* @0x18b1fc bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b200 cmp r0, #0 */
/* @0x18b204 beq 0x18b2ac <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x144> */
/* @0x18b208 mov r0, r5 */
/* @0x18b20c mov r1, r9 */
/* @0x18b210 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b214 cmp r0, #0 */
/* @0x18b218 beq 0x18b2d8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x170> */
/* @0x18b21c mov r0, r5 */
/* @0x18b220 mov r1, r10 */
/* @0x18b224 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b228 cmp r0, #0 */
/* @0x18b22c beq 0x18b304 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x19c> */
/* @0x18b230 mov r0, r5 */
/* @0x18b234 ldr r1, [sp, #0x4] */
/* @0x18b238 bl 0xb66d0 <strcasecmp@plt> */
/* @0x18b23c cmp r0, #0 */
/* @0x18b240 bne 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b244 mov r0, r11 */
/* @0x18b248 bl 0x27ed58 <json_object_get_string> */
/* @0x18b24c mov r5, r0 */
/* @0x18b250 ldr r0, [r6, #0x10] */
/* @0x18b254 cmp r0, #0 */
/* @0x18b258 beq 0x18b260 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0xf8> */
/* @0x18b25c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b260 mov r0, r5 */
/* @0x18b264 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b268 str r0, [r6, #0x10] */
/* @0x18b26c ldr r4, [r4, #0x8] */
/* @0x18b270 cmp r4, #0 */
/* @0x18b274 bne 0x18b1c4 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x5c> */
/* @0x18b278 add sp, sp, #12 */
/* @0x18b27c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18b280 mov r0, r11 */
/* @0x18b284 bl 0x27ed58 <json_object_get_string> */
/* @0x18b288 mov r5, r0 */
/* @0x18b28c ldr r0, [r6] */
/* @0x18b290 cmp r0, #0 */
/* @0x18b294 beq 0x18b29c <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x134> */
/* @0x18b298 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b29c mov r0, r5 */
/* @0x18b2a0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b2a4 str r0, [r6] */
/* @0x18b2a8 b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b2ac mov r0, r11 */
/* @0x18b2b0 bl 0x27ed58 <json_object_get_string> */
/* @0x18b2b4 mov r5, r0 */
/* @0x18b2b8 ldr r0, [r6, #0x4] */
/* @0x18b2bc cmp r0, #0 */
/* @0x18b2c0 beq 0x18b2c8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x160> */
/* @0x18b2c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b2c8 mov r0, r5 */
/* @0x18b2cc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b2d0 str r0, [r6, #0x4] */
/* @0x18b2d4 b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b2d8 mov r0, r11 */
/* @0x18b2dc bl 0x27ed58 <json_object_get_string> */
/* @0x18b2e0 mov r5, r0 */
/* @0x18b2e4 ldr r0, [r6, #0xc] */
/* @0x18b2e8 cmp r0, #0 */
/* @0x18b2ec beq 0x18b2f4 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x18c> */
/* @0x18b2f0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b2f4 mov r0, r5 */
/* @0x18b2f8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b2fc str r0, [r6, #0xc] */
/* @0x18b300 b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b304 mov r0, r11 */
/* @0x18b308 bl 0x27ed58 <json_object_get_string> */
/* @0x18b30c mov r5, r0 */
/* @0x18b310 ldr r0, [r6, #0x8] */
/* @0x18b314 cmp r0, #0 */
/* @0x18b318 beq 0x18b320 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x1b8> */
/* @0x18b31c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x18b320 mov r0, r5 */
/* @0x18b324 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18b328 str r0, [r6, #0x8] */
/* @0x18b32c b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50> */
/* @0x18b330 mulseq r11, r12, r0 */
/* @0x18b334 andseq lr, r11, r0, lsr r6 */
/* @0x18b338 andseq r1, r12, r12, asr #32 */
/* @0x18b33c andseq r11, r11, r4, lsl r4 */
/* @0x18b340 andseq r10, r11, r12, ror pc */

/* ── FUNC 0x18b344 · anon_18b344 · size=0 · insn=1 */
/* @0x18b344 andeq r0, r0, r0 */

/* ── FUNC 0x18b348 · CIAPProduct::PopulateMap(int) · size=496 · insn=122 */
/* @0x18b348 vmov s13, r1 */
/* @0x18b34c mov r3, #1 */
/* @0x18b350 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18b354 vcvt.f64.s32 d7, s13 */
/* @0x18b358 sub sp, sp, #76 */
/* @0x18b35c mov r7, #0 */
/* @0x18b360 add r5, sp, #8 */
/* @0x18b364 mov r2, r7 */
/* @0x18b368 mov r4, r0 */
/* @0x18b36c mov r1, r7 */
/* @0x18b370 mov r0, r5 */
/* @0x18b374 add r6, sp, #24 */
/* @0x18b378 str r6, [sp] */
/* @0x18b37c add r8, sp, #40 */
/* @0x18b380 str r7, [sp, #0x24] */
/* @0x18b384 add r9, sp, #56 */
/* @0x18b388 vstr d7, [sp, #24] */
/* @0x18b38c bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x18b390 ldr r1, [pc, #0x188] */
/* @0x18b394 mov r0, r8 */
/* @0x18b398 add r1, pc, r1 */
/* @0x18b39c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x18b3a0 ldr r1, [r4] */
/* @0x18b3a4 mov r0, r9 */
/* @0x18b3a8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x18b3ac mov r3, #3 */
/* @0x18b3b0 str r6, [sp] */
/* @0x18b3b4 mov r0, r5 */
/* @0x18b3b8 mov r1, r7 */
/* @0x18b3bc mov r2, r7 */
/* @0x18b3c0 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b3c4 ldr r3, [r4, #0x4] */
/* @0x18b3c8 cmp r3, r7 */
/* @0x18b3cc beq 0x18b404 <_ZN11CIAPProduct11PopulateMapEi+0xbc> */
/* @0x18b3d0 ldr r1, [pc, #0x14c] */
/* @0x18b3d4 mov r0, r8 */
/* @0x18b3d8 add r1, pc, r1 */
/* @0x18b3dc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b3e0 mov r0, r9 */
/* @0x18b3e4 ldr r1, [r4, #0x4] */
/* @0x18b3e8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b3ec mov r1, r7 */
/* @0x18b3f0 str r6, [sp] */
/* @0x18b3f4 mov r2, r7 */
/* @0x18b3f8 mov r0, r5 */
/* @0x18b3fc mov r3, #3 */
/* @0x18b400 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b404 ldr r3, [r4, #0x8] */
/* @0x18b408 cmp r3, #0 */
/* @0x18b40c beq 0x18b444 <_ZN11CIAPProduct11PopulateMapEi+0xfc> */
/* @0x18b410 ldr r1, [pc, #0x110] */
/* @0x18b414 mov r0, r8 */
/* @0x18b418 add r1, pc, r1 */
/* @0x18b41c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b420 mov r0, r9 */
/* @0x18b424 ldr r1, [r4, #0x8] */
/* @0x18b428 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b42c mov r1, #0 */
/* @0x18b430 str r6, [sp] */
/* @0x18b434 mov r2, r1 */
/* @0x18b438 mov r0, r5 */
/* @0x18b43c mov r3, #3 */
/* @0x18b440 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b444 ldr r3, [r4, #0xc] */
/* @0x18b448 cmp r3, #0 */
/* @0x18b44c beq 0x18b484 <_ZN11CIAPProduct11PopulateMapEi+0x13c> */
/* @0x18b450 ldr r1, [pc, #0xd4] */
/* @0x18b454 mov r0, r8 */
/* @0x18b458 add r1, pc, r1 */
/* @0x18b45c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b460 mov r0, r9 */
/* @0x18b464 ldr r1, [r4, #0xc] */
/* @0x18b468 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b46c mov r1, #0 */
/* @0x18b470 str r6, [sp] */
/* @0x18b474 mov r2, r1 */
/* @0x18b478 mov r0, r5 */
/* @0x18b47c mov r3, #3 */
/* @0x18b480 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b484 ldr r3, [r4, #0x10] */
/* @0x18b488 cmp r3, #0 */
/* @0x18b48c beq 0x18b4c4 <_ZN11CIAPProduct11PopulateMapEi+0x17c> */
/* @0x18b490 ldr r1, [pc, #0x98] */
/* @0x18b494 mov r0, r8 */
/* @0x18b498 add r1, pc, r1 */
/* @0x18b49c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b4a0 mov r0, r9 */
/* @0x18b4a4 ldr r1, [r4, #0x10] */
/* @0x18b4a8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b4ac mov r1, #0 */
/* @0x18b4b0 str r6, [sp] */
/* @0x18b4b4 mov r2, r1 */
/* @0x18b4b8 mov r0, r5 */
/* @0x18b4bc mov r3, #3 */
/* @0x18b4c0 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b4c4 ldr r1, [pc, #0x68] */
/* @0x18b4c8 mov r0, r8 */
/* @0x18b4cc add r1, pc, r1 */
/* @0x18b4d0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18b4d4 vmov.f64 d7, #1.000000e+00 */
/* @0x18b4d8 ldrb r3, [r4, #0x14] */
/* @0x18b4dc mov r12, #0 */
/* @0x18b4e0 str r6, [sp] */
/* @0x18b4e4 mov r1, r12 */
/* @0x18b4e8 cmp r3, r12 */
/* @0x18b4ec mov r0, r5 */
/* @0x18b4f0 mov r2, r12 */
/* @0x18b4f4 mov r3, #3 */
/* @0x18b4f8 vldr d6, [pc, #24] */
/* @0x18b4fc str r12, [sp, #0x44] */
/* @0x18b500 vmoveq.f64 d7, d6 */
/* @0x18b504 vstr d7, [sp, #56] */
/* @0x18b508 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x18b50c add sp, sp, #76 */
/* @0x18b510 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18b514 nop */
/* @0x18b520 andseq r5, r10, r8, lsr #13 */
/* @0x18b524 ldrsheq lr, [r11], -r4 */
/* @0x18b528 andseq r11, r11, r4, lsr #3 */
/* @0x18b52c mulseq r12, r8, sp */
/* @0x18b530 mulseq r11, r0, r12 */
/* @0x18b534 andseq r0, r12, r12, lsr #26 */
