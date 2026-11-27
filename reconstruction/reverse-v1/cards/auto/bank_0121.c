/* libyoyo.so 覆盖卡组 0121
 * 函数 0x183d88..0x186544，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x183d88 · SetLightingUniforms(GLSLShader*, int) · size=732 · insn=183 */
/* @0x183d88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x183d8c sub sp, sp, #540 */
/* @0x183d90 ldr r8, [pc, #0x2ac] */
/* @0x183d94 mov r5, r1 */
/* @0x183d98 ldr r4, [pc, #0x2a8] */
/* @0x183d9c add r9, sp, #280 */
/* @0x183da0 add r8, pc, r8 */
/* @0x183da4 ldr r2, [pc, #0x2a0] */
/* @0x183da8 ldr r12, [pc, #0x2a0] */
/* @0x183dac add r7, sp, #24 */
/* @0x183db0 str r9, [sp, #0xc] */
/* @0x183db4 mov r3, #0 */
/* @0x183db8 str r0, [sp, #0x10] */
/* @0x183dbc mov r11, #1 */
/* @0x183dc0 ldr r4, [r8, r4] */
/* @0x183dc4 ldr r1, [pc, #0x288] */
/* @0x183dc8 ldr r6, [r8, r2] */
/* @0x183dcc mov r2, r3 */
/* @0x183dd0 ldr r12, [r8, r12] */
/* @0x183dd4 ldr r1, [r8, r1] */
/* @0x183dd8 ldr r10, [r4] */
/* @0x183ddc add r12, r12, #12 */
/* @0x183de0 str r5, [sp, #0x14] */
/* @0x183de4 add r4, r6, #8 */
/* @0x183de8 str r3, [sp, #0x4] */
/* @0x183dec mov r5, r7 */
/* @0x183df0 b 0x183e14 <_Z19SetLightingUniformsP10GLSLShaderi+0x8c> */
/* @0x183df4 cmp r9, #1 */
/* @0x183df8 beq 0x184020 <_Z19SetLightingUniformsP10GLSLShaderi+0x298> */
/* @0x183dfc add r3, r3, #1 */
/* @0x183e00 add r4, r4, #16 */
/* @0x183e04 cmp r3, #8 */
/* @0x183e08 add r1, r1, #4 */
/* @0x183e0c add r12, r12, #16 */
/* @0x183e10 beq 0x183e90 <_Z19SetLightingUniformsP10GLSLShaderi+0x108> */
/* @0x183e14 ands r0, r10, r11, lsl r3 */
/* @0x183e18 ldr r6, [pc, #0x238] */
/* @0x183e1c beq 0x183dfc <_Z19SetLightingUniformsP10GLSLShaderi+0x74> */
/* @0x183e20 ldr r6, [r8, r6] */
/* @0x183e24 add r9, sp, #280 */
/* @0x183e28 str r6, [sp, #0x8] */
/* @0x183e2c lsl r6, r2, #4 */
/* @0x183e30 ldr r0, [sp, #0x8] */
/* @0x183e34 add r7, r5, r6 */
/* @0x183e38 add r6, r9, r6 */
/* @0x183e3c ldr r9, [r0, r3, lsl #2] */
/* @0x183e40 cmp r9, #0 */
/* @0x183e44 addeq r2, r2, #1 */
/* @0x183e48 bne 0x183df4 <_Z19SetLightingUniformsP10GLSLShaderi+0x6c> */
/* @0x183e4c ldr r9, [r4, #-0x8] */
/* @0x183e50 str r9, [r7] */
/* @0x183e54 ldr r9, [r4, #-0x4] */
/* @0x183e58 str r9, [r7, #0x4] */
/* @0x183e5c ldr r9, [r4] */
/* @0x183e60 str r9, [r7, #0x8] */
/* @0x183e64 ldr r9, [r1] */
/* @0x183e68 str r9, [r7, #0xc] */
/* @0x183e6c ldr r9, [r12, #-0xc] */
/* @0x183e70 ldr r7, [r12, #-0x8] */
/* @0x183e74 str r9, [r6] */
/* @0x183e78 str r7, [r6, #0x4] */
/* @0x183e7c ldr r9, [r12, #-0x4] */
/* @0x183e80 ldr r7, [r12] */
/* @0x183e84 str r9, [r6, #0x8] */
/* @0x183e88 str r7, [r6, #0xc] */
/* @0x183e8c b 0x183dfc <_Z19SetLightingUniformsP10GLSLShaderi+0x74> */
/* @0x183e90 ldr r5, [sp, #0x14] */
/* @0x183e94 ldr r0, [sp, #0x4] */
/* @0x183e98 cmp r5, r2 */
/* @0x183e9c ble 0x183ef0 <_Z19SetLightingUniformsP10GLSLShaderi+0x168> */
/* @0x183ea0 lsl r3, r2, #4 */
/* @0x183ea4 add r12, sp, #280 */
/* @0x183ea8 add r1, sp, #24 */
/* @0x183eac mov r4, #1065353216 */
/* @0x183eb0 add r1, r1, r3 */
/* @0x183eb4 add r3, r12, r3 */
/* @0x183eb8 mov r12, #0 */
/* @0x183ebc add r2, r2, #1 */
/* @0x183ec0 str r12, [r1] */
/* @0x183ec4 cmp r2, r5 */
/* @0x183ec8 str r4, [r1, #0x4] */
/* @0x183ecc str r12, [r1, #0x8] */
/* @0x183ed0 add r3, r3, #16 */
/* @0x183ed4 str r4, [r1, #0xc] */
/* @0x183ed8 add r1, r1, #16 */
/* @0x183edc str r12, [r3, #-0x10] */
/* @0x183ee0 str r12, [r3, #-0xc] */
/* @0x183ee4 str r12, [r3, #-0x8] */
/* @0x183ee8 str r12, [r3, #-0x4] */
/* @0x183eec bne 0x183ebc <_Z19SetLightingUniformsP10GLSLShaderi+0x134> */
/* @0x183ef0 cmp r5, r0 */
/* @0x183ef4 ble 0x183f4c <_Z19SetLightingUniformsP10GLSLShaderi+0x1c4> */
/* @0x183ef8 lsl r3, r0, #4 */
/* @0x183efc add r1, sp, #280 */
/* @0x183f00 add r3, r3, #128 */
/* @0x183f04 add r2, sp, #24 */
/* @0x183f08 add r2, r2, r3 */
/* @0x183f0c mov r12, #1065353216 */
/* @0x183f10 add r3, r1, r3 */
/* @0x183f14 mov r1, #0 */
/* @0x183f18 add r0, r0, #1 */
/* @0x183f1c str r1, [r2] */
/* @0x183f20 cmp r0, r5 */
/* @0x183f24 str r12, [r2, #0x4] */
/* @0x183f28 str r1, [r2, #0x8] */
/* @0x183f2c add r3, r3, #16 */
/* @0x183f30 str r12, [r2, #0xc] */
/* @0x183f34 add r2, r2, #16 */
/* @0x183f38 str r1, [r3, #-0x10] */
/* @0x183f3c str r1, [r3, #-0xc] */
/* @0x183f40 str r1, [r3, #-0x8] */
/* @0x183f44 str r1, [r3, #-0x4] */
/* @0x183f48 bne 0x183f18 <_Z19SetLightingUniformsP10GLSLShaderi+0x190> */
/* @0x183f4c ldr r12, [sp, #0x10] */
/* @0x183f50 ldr r0, [r12, #0x64] */
/* @0x183f54 cmn r0, #1 */
/* @0x183f58 beq 0x183f78 <_Z19SetLightingUniformsP10GLSLShaderi+0x1f0> */
/* @0x183f5c ldr r3, [pc, #0xf8] */
/* @0x183f60 mov r1, #1 */
/* @0x183f64 ldr r2, [pc, #0xf4] */
/* @0x183f68 ldr r3, [r8, r3] */
/* @0x183f6c ldr r2, [r8, r2] */
/* @0x183f70 ldr r3, [r3] */
/* @0x183f74 blx r3 */
/* @0x183f78 ldr r3, [sp, #0x10] */
/* @0x183f7c ldr r0, [r3, #0x68] */
/* @0x183f80 cmn r0, #1 */
/* @0x183f84 beq 0x183fa0 <_Z19SetLightingUniformsP10GLSLShaderi+0x218> */
/* @0x183f88 ldr r3, [pc, #0xcc] */
/* @0x183f8c mov r1, r5 */
/* @0x183f90 add r2, sp, #24 */
/* @0x183f94 ldr r3, [r8, r3] */
/* @0x183f98 ldr r3, [r3] */
/* @0x183f9c blx r3 */
/* @0x183fa0 ldr r7, [sp, #0x10] */
/* @0x183fa4 ldr r0, [r7, #0x6c] */
/* @0x183fa8 cmn r0, #1 */
/* @0x183fac beq 0x183fc8 <_Z19SetLightingUniformsP10GLSLShaderi+0x240> */
/* @0x183fb0 ldr r3, [pc, #0xa4] */
/* @0x183fb4 mov r1, r5 */
/* @0x183fb8 add r2, sp, #280 */
/* @0x183fbc ldr r3, [r8, r3] */
/* @0x183fc0 ldr r3, [r3] */
/* @0x183fc4 blx r3 */
/* @0x183fc8 ldr r9, [sp, #0x10] */
/* @0x183fcc ldr r0, [r9, #0x70] */
/* @0x183fd0 cmn r0, #1 */
/* @0x183fd4 beq 0x183ff0 <_Z19SetLightingUniformsP10GLSLShaderi+0x268> */
/* @0x183fd8 ldr r3, [pc, #0x7c] */
/* @0x183fdc mov r1, r5 */
/* @0x183fe0 add r2, sp, #152 */
/* @0x183fe4 ldr r3, [r8, r3] */
/* @0x183fe8 ldr r3, [r3] */
/* @0x183fec blx r3 */
/* @0x183ff0 ldr r12, [sp, #0x10] */
/* @0x183ff4 ldr r0, [r12, #0x74] */
/* @0x183ff8 cmn r0, #1 */
/* @0x183ffc beq 0x184018 <_Z19SetLightingUniformsP10GLSLShaderi+0x290> */
/* @0x184000 ldr r3, [pc, #0x54] */
/* @0x184004 mov r1, r5 */
/* @0x184008 add r2, sp, #408 */
/* @0x18400c ldr r3, [r8, r3] */
/* @0x184010 ldr r3, [r3] */
/* @0x184014 blx r3 */
/* @0x184018 add sp, sp, #540 */
/* @0x18401c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x184020 ldr r7, [sp, #0x4] */
/* @0x184024 add r9, sp, #280 */
/* @0x184028 lsl r6, r7, #4 */
/* @0x18402c add r7, r7, #1 */
/* @0x184030 add r6, r6, #128 */
/* @0x184034 str r7, [sp, #0x4] */
/* @0x184038 add r7, r5, r6 */
/* @0x18403c add r6, r9, r6 */
/* @0x184040 b 0x183e4c <_Z19SetLightingUniformsP10GLSLShaderi+0xc4> */
/* @0x184044 .word 0x0026deb0 */
/* @0x184048 .word 0xffffe85c */
/* @0x18404c .word 0xffffe854 */
/* @0x184050 .word 0xffffe850 */
/* @0x184054 .word 0xffffe84c */
/* @0x184058 .word 0xffffe858 */
/* @0x18405c .word 0xffffbbd0 */
/* @0x184060 .word 0xffffe844 */

/* ── FUNC 0x184064 · SetFogUniforms(GLSLShader*) · size=296 · insn=74 */
/* @0x184064 push {r4, r5, r6, lr} */
/* @0x184068 mov r5, r0 */
/* @0x18406c ldr r0, [r0, #0x48] */
/* @0x184070 ldr r4, [pc, #0xf4] */
/* @0x184074 cmn r0, #1 */
/* @0x184078 add r4, pc, r4 */
/* @0x18407c beq 0x18409c <_Z14SetFogUniformsP10GLSLShader+0x38> */
/* @0x184080 ldr r3, [pc, #0xe8] */
/* @0x184084 ldr r2, [pc, #0xe8] */
/* @0x184088 ldr r3, [r4, r3] */
/* @0x18408c ldr r2, [r4, r2] */
/* @0x184090 ldr r3, [r3] */
/* @0x184094 ldrb r1, [r2] */
/* @0x184098 blx r3 */
/* @0x18409c ldr r0, [r5, #0x54] */
/* @0x1840a0 cmn r0, #1 */
/* @0x1840a4 beq 0x1840c4 <_Z14SetFogUniformsP10GLSLShader+0x60> */
/* @0x1840a8 ldr r3, [pc, #0xc0] */
/* @0x1840ac ldr r2, [pc, #0xc0] */
/* @0x1840b0 ldr r3, [r4, r3] */
/* @0x1840b4 ldr r2, [r4, r2] */
/* @0x1840b8 ldr r3, [r3] */
/* @0x1840bc ldrb r1, [r2] */
/* @0x1840c0 blx r3 */
/* @0x1840c4 ldr r0, [r5, #0x4c] */
/* @0x1840c8 cmn r0, #1 */
/* @0x1840cc beq 0x184160 <_Z14SetFogUniformsP10GLSLShader+0xfc> */
/* @0x1840d0 ldr r3, [pc, #0xa0] */
/* @0x1840d4 ldr r2, [pc, #0xa0] */
/* @0x1840d8 ldr r3, [r4, r3] */
/* @0x1840dc ldr r6, [r4, r2] */
/* @0x1840e0 ldr r3, [r3] */
/* @0x1840e4 ldr r1, [r6] */
/* @0x1840e8 blx r3 */
/* @0x1840ec ldr r3, [pc, #0x8c] */
/* @0x1840f0 vldr s15, [r6] */
/* @0x1840f4 ldr r0, [r5, #0x50] */
/* @0x1840f8 ldr r3, [r4, r3] */
/* @0x1840fc vldr s14, [r3] */
/* @0x184100 vsub.f32 s15, s14, s15 */
/* @0x184104 vcmpe.f32 s15, #0 */
/* @0x184108 vmrs APSR_nzcv, fpscr */
/* @0x18410c vmovgt.f32 s14, #1.000000e+00 */
/* @0x184110 vmovle.f32 s15, #1.000000e+00 */
/* @0x184114 vdivgt.f32 s15, s14, s15 */
/* @0x184118 cmn r0, #1 */
/* @0x18411c beq 0x184134 <_Z14SetFogUniformsP10GLSLShader+0xd0> */
/* @0x184120 ldr r3, [pc, #0x50] */
/* @0x184124 vmov r1, s15 */
/* @0x184128 ldr r3, [r4, r3] */
/* @0x18412c ldr r3, [r3] */
/* @0x184130 blx r3 */
/* @0x184134 ldr r0, [r5, #0x58] */
/* @0x184138 cmn r0, #1 */
/* @0x18413c popeq {r4, r5, r6, pc} */
/* @0x184140 ldr r3, [pc, #0x3c] */
/* @0x184144 mov r1, #1 */
/* @0x184148 ldr r2, [pc, #0x38] */
/* @0x18414c ldr r3, [r4, r3] */
/* @0x184150 ldr r2, [r4, r2] */
/* @0x184154 ldr r3, [r3] */
/* @0x184158 blx r3 */
/* @0x18415c pop {r4, r5, r6, pc} */
/* @0x184160 ldr r3, [pc, #0x14] */
/* @0x184164 ldr r6, [r4, r3] */
/* @0x184168 b 0x1840ec <_Z14SetFogUniformsP10GLSLShader+0x88> */
/* @0x18416c .word 0x0026dbd8 */
/* @0x184170 .word 0xffffbb84 */
/* @0x184174 .word 0xffffe884 */
/* @0x184178 .word 0xffffbbfc */
/* @0x18417c .word 0xffffe878 */
/* @0x184180 .word 0xffffe874 */
/* @0x184184 .word 0xffffbbd0 */
/* @0x184188 .word 0xffffe87c */

/* ── FUNC 0x18418c · anon_18418c · size=0 · insn=1 */
/* @0x18418c andeq r0, r0, r0 */

/* ── FUNC 0x184190 · SetAlphaTestUniforms(GLSLShader*) · size=156 · insn=39 */
/* @0x184190 push {r3, r4, r5, lr} */
/* @0x184194 mov r5, r0 */
/* @0x184198 ldr r0, [r0, #0x5c] */
/* @0x18419c ldr r4, [pc, #0x74] */
/* @0x1841a0 cmn r0, #1 */
/* @0x1841a4 add r4, pc, r4 */
/* @0x1841a8 beq 0x1841c8 <_Z20SetAlphaTestUniformsP10GLSLShader+0x38> */
/* @0x1841ac ldr r3, [pc, #0x68] */
/* @0x1841b0 ldr r2, [pc, #0x68] */
/* @0x1841b4 ldr r3, [r4, r3] */
/* @0x1841b8 ldr r2, [r4, r2] */
/* @0x1841bc ldr r3, [r3] */
/* @0x1841c0 ldrb r1, [r2] */
/* @0x1841c4 blx r3 */
/* @0x1841c8 ldr r0, [r5, #0x60] */
/* @0x1841cc cmn r0, #1 */
/* @0x1841d0 popeq {r3, r4, r5, pc} */
/* @0x1841d4 ldr r2, [pc, #0x48] */
/* @0x1841d8 vldr d6, [pc, #48] */
/* @0x1841dc ldr r3, [pc, #0x44] */
/* @0x1841e0 ldr r2, [r4, r2] */
/* @0x1841e4 vldr s14, [r2] */
/* @0x1841e8 vcvt.f32.s32 s14, s14 */
/* @0x1841ec ldr r3, [r4, r3] */
/* @0x1841f0 ldr r3, [r3] */
/* @0x1841f4 vcvt.f64.f32 d7, s14 */
/* @0x1841f8 vmul.f64 d7, d7, d6 */
/* @0x1841fc vcvt.f32.f64 s13, d7 */
/* @0x184200 vmov r1, s13 */
/* @0x184204 blx r3 */
/* @0x184208 pop {r3, r4, r5, pc} */
/* @0x18420c nop */
/* @0x184210 andsne r1, r0, r0, lsl r0 */
/* @0x184214 svclo #0x701010 */
/* @0x184218 eoreq sp, r6, r12, lsr #21 */
/* @0x18421c .word 0xffffbb84 */
/* @0x184220 .word 0xffffe89c */
/* @0x184224 .word 0xffffe888 */
/* @0x184228 .word 0xffffbbfc */

/* ── FUNC 0x18422c · anon_18422c · size=0 · insn=1 */
/* @0x18422c nop */

/* ── FUNC 0x184230 · SetTransformUniforms(GLSLShader*) · size=60 · insn=15 */
/* @0x184230 ldr r0, [r0, #0x3c] */
/* @0x184234 push {r3, lr} */
/* @0x184238 cmn r0, #1 */
/* @0x18423c popeq {r3, pc} */
/* @0x184240 ldr r12, [pc, #0x1c] */
/* @0x184244 mov r1, #5 */
/* @0x184248 ldr r3, [pc, #0x18] */
/* @0x18424c mov r2, #0 */
/* @0x184250 ldr r12, [pc, r12] */
/* @0x184254 ldr r3, [pc, r3] */
/* @0x184258 ldr r12, [r12] */
/* @0x18425c blx r12 */
/* @0x184260 pop {r3, pc} */
/* @0x184264 eoreq r9, r6, r12, ror #11 */
/* @0x184268 eoreq r12, r6, r0, lsr #4 */

/* ── FUNC 0x18426c · StartShaderBlock(int) · size=1420 · insn=355 */
/* @0x18426c ldr r2, [pc, #0x530] */
/* @0x184270 mov r3, r0 */
/* @0x184274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x184278 add r2, pc, r2 */
/* @0x18427c ldr r9, [pc, #0x524] */
/* @0x184280 ands r5, r0, #16777216 */
/* @0x184284 mov r4, #0 */
/* @0x184288 sub sp, sp, #28 */
/* @0x18428c add r9, pc, r9 */
/* @0x184290 str r4, [r2] */
/* @0x184294 beq 0x1842d8 <_Z16StartShaderBlocki+0x6c> */
/* @0x184298 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0x18429c ldr r1, [r0, #0x4] */
/* @0x1842a0 str r0, [sp, #0x4] */
/* @0x1842a4 cmp r1, #0 */
/* @0x1842a8 ble 0x1844fc <_Z16StartShaderBlocki+0x290> */
/* @0x1842ac ldr r3, [r0, #0x8] */
/* @0x1842b0 add r1, r3, r1, lsl #4 */
/* @0x1842b4 ldr r2, [r3, #0x8] */
/* @0x1842b8 sub r2, r2, #1 */
/* @0x1842bc cmp r2, #3 */
/* @0x1842c0 addls pc, pc, r2, lsl #2 */
/* @0x1842c4 b 0x1844f0 <_Z16StartShaderBlocki+0x284> */
/* @0x1842c8 b 0x184514 <_Z16StartShaderBlocki+0x2a8> */
/* @0x1842cc b 0x18450c <_Z16StartShaderBlocki+0x2a0> */
/* @0x1842d0 b 0x184504 <_Z16StartShaderBlocki+0x298> */
/* @0x1842d4 b 0x1844ec <_Z16StartShaderBlocki+0x280> */
/* @0x1842d8 cmp r0, #16 */
/* @0x1842dc beq 0x184590 <_Z16StartShaderBlocki+0x324> */
/* @0x1842e0 cmp r3, #24 */
/* @0x1842e4 str r5, [sp, #0x4] */
/* @0x1842e8 moveq r4, #7 */
/* @0x1842ec movne r4, #15 */
/* @0x1842f0 ldr r3, [pc, #0x4b4] */
/* @0x1842f4 ldr r3, [r9, r3] */
/* @0x1842f8 ldr r0, [r3] */
/* @0x1842fc cmn r0, #1 */
/* @0x184300 beq 0x18451c <_Z16StartShaderBlocki+0x2b0> */
/* @0x184304 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x184308 subs r7, r0, #0 */
/* @0x18430c beq 0x18451c <_Z16StartShaderBlocki+0x2b0> */
/* @0x184310 ldr r2, [pc, #0x498] */
/* @0x184314 mov r10, #0 */
/* @0x184318 ldr r3, [pc, #0x494] */
/* @0x18431c mov r11, r10 */
/* @0x184320 ldr r8, [r9, r2] */
/* @0x184324 ldr r6, [r9, r3] */
/* @0x184328 ldrb r3, [r8] */
/* @0x18432c cmp r3, #0 */
/* @0x184330 bne 0x18455c <_Z16StartShaderBlocki+0x2f0> */
/* @0x184334 ldrb r3, [r6] */
/* @0x184338 cmp r3, #0 */
/* @0x18433c bne 0x184570 <_Z16StartShaderBlocki+0x304> */
/* @0x184340 cmp r11, #0 */
/* @0x184344 bne 0x184580 <_Z16StartShaderBlocki+0x314> */
/* @0x184348 cmp r5, #0 */
/* @0x18434c beq 0x184468 <_Z16StartShaderBlocki+0x1fc> */
/* @0x184350 ldr r11, [r7, #0x30] */
/* @0x184354 cmp r11, #0 */
/* @0x184358 ble 0x184468 <_Z16StartShaderBlocki+0x1fc> */
/* @0x18435c ldr r4, [r7, #0x34] */
/* @0x184360 ldr r2, [sp, #0x4] */
/* @0x184364 cmp r4, #0 */
/* @0x184368 beq 0x18465c <_Z16StartShaderBlocki+0x3f0> */
/* @0x18436c ldr r3, [sp, #0x4] */
/* @0x184370 mov r6, #0 */
/* @0x184374 ldr r2, [r2, #0xc] */
/* @0x184378 ldr r10, [r7, #0x2c] */
/* @0x18437c ldr r3, [r3, #0x8] */
/* @0x184380 str r2, [sp, #0x8] */
/* @0x184384 ldr r2, [pc, #0x42c] */
/* @0x184388 str r3, [sp, #0xc] */
/* @0x18438c add r2, pc, r2 */
/* @0x184390 str r9, [sp, #0x14] */
/* @0x184394 str r2, [sp, #0x10] */
/* @0x184398 ldr r0, [r10, r6, lsl #2] */
/* @0x18439c lsl r9, r6, #2 */
/* @0x1843a0 cmn r0, #1 */
/* @0x1843a4 beq 0x184440 <_Z16StartShaderBlocki+0x1d4> */
/* @0x1843a8 ldr r3, [sp, #0x4] */
/* @0x1843ac ldr r2, [r7, #0x38] */
/* @0x1843b0 ldr r4, [r3, #0x4] */
/* @0x1843b4 ldr r3, [r7, #0x34] */
/* @0x1843b8 cmp r4, #0 */
/* @0x1843bc ldr r8, [r2, r6, lsl #2] */
/* @0x1843c0 ldr r5, [r3, r6, lsl #2] */
/* @0x1843c4 ble 0x184440 <_Z16StartShaderBlocki+0x1d4> */
/* @0x1843c8 ldr r3, [sp, #0xc] */
/* @0x1843cc mov r2, #0 */
/* @0x1843d0 ldr r1, [sp, #0x8] */
/* @0x1843d4 b 0x1843e4 <_Z16StartShaderBlocki+0x178> */
/* @0x1843d8 cmp r2, r4 */
/* @0x1843dc add r1, r1, #16 */
/* @0x1843e0 beq 0x184440 <_Z16StartShaderBlocki+0x1d4> */
/* @0x1843e4 ldr r12, [r3, #0x8] */
/* @0x1843e8 add r2, r2, #1 */
/* @0x1843ec add r3, r3, #16 */
/* @0x1843f0 cmp r12, r5 */
/* @0x1843f4 bne 0x1843d8 <_Z16StartShaderBlocki+0x16c> */
/* @0x1843f8 ldr r12, [r1, #0xc] */
/* @0x1843fc cmp r12, r8 */
/* @0x184400 bne 0x1843d8 <_Z16StartShaderBlocki+0x16c> */
/* @0x184404 ldr r2, [sp, #0x14] */
/* @0x184408 ldr r3, [pc, #0x3ac] */
/* @0x18440c ldr r3, [r2, r3] */
/* @0x184410 ldr r3, [r3] */
/* @0x184414 blx r3 */
/* @0x184418 ldr r2, [sp, #0x10] */
/* @0x18441c ldr r10, [r7, #0x2c] */
/* @0x184420 ldr r0, [sp, #0x10] */
/* @0x184424 ldr r3, [r2] */
/* @0x184428 ldr r11, [r7, #0x30] */
/* @0x18442c ldr r2, [r10, r9] */
/* @0x184430 add r1, r3, #1 */
/* @0x184434 add r3, r0, r3, lsl #2 */
/* @0x184438 str r1, [r0] */
/* @0x18443c str r2, [r3, #0x4] */
/* @0x184440 add r6, r6, #1 */
/* @0x184444 cmp r11, r6 */
/* @0x184448 bgt 0x184398 <_Z16StartShaderBlocki+0x12c> */
/* @0x18444c ldr r3, [pc, #0x36c] */
/* @0x184450 mov r0, r7 */
/* @0x184454 mov r2, #1 */
/* @0x184458 add r3, pc, r3 */
/* @0x18445c strb r2, [r3, #0x44] */
/* @0x184460 add sp, sp, #28 */
/* @0x184464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x184468 ldr r0, [r7, #0x1c] */
/* @0x18446c cmn r0, #1 */
/* @0x184470 beq 0x18447c <_Z16StartShaderBlocki+0x210> */
/* @0x184474 tst r4, #1 */
/* @0x184478 bne 0x18461c <_Z16StartShaderBlocki+0x3b0> */
/* @0x18447c ldr r0, [r7, #0x20] */
/* @0x184480 cmn r0, #1 */
/* @0x184484 beq 0x184490 <_Z16StartShaderBlocki+0x224> */
/* @0x184488 tst r4, #8 */
/* @0x18448c bne 0x18459c <_Z16StartShaderBlocki+0x330> */
/* @0x184490 ldr r0, [r7, #0x28] */
/* @0x184494 cmn r0, #1 */
/* @0x184498 beq 0x1844a4 <_Z16StartShaderBlocki+0x238> */
/* @0x18449c tst r4, #2 */
/* @0x1844a0 bne 0x1845dc <_Z16StartShaderBlocki+0x370> */
/* @0x1844a4 ldr r0, [r7, #0x24] */
/* @0x1844a8 cmn r0, #1 */
/* @0x1844ac beq 0x18444c <_Z16StartShaderBlocki+0x1e0> */
/* @0x1844b0 tst r4, #4 */
/* @0x1844b4 beq 0x18444c <_Z16StartShaderBlocki+0x1e0> */
/* @0x1844b8 ldr r3, [pc, #0x2fc] */
/* @0x1844bc ldr r3, [r9, r3] */
/* @0x1844c0 ldr r3, [r3] */
/* @0x1844c4 blx r3 */
/* @0x1844c8 ldr r3, [pc, #0x2f4] */
/* @0x1844cc ldr r1, [r7, #0x24] */
/* @0x1844d0 add r3, pc, r3 */
/* @0x1844d4 ldr r2, [r3] */
/* @0x1844d8 add r0, r2, #1 */
/* @0x1844dc str r0, [r3] */
/* @0x1844e0 add r3, r3, r2, lsl #2 */
/* @0x1844e4 str r1, [r3, #0x4] */
/* @0x1844e8 b 0x18444c <_Z16StartShaderBlocki+0x1e0> */
/* @0x1844ec orr r4, r4, #4 */
/* @0x1844f0 add r3, r3, #16 */
/* @0x1844f4 cmp r3, r1 */
/* @0x1844f8 bne 0x1842b4 <_Z16StartShaderBlocki+0x48> */
/* @0x1844fc mov r5, #1 */
/* @0x184500 b 0x1842f0 <_Z16StartShaderBlocki+0x84> */
/* @0x184504 orr r4, r4, #8 */
/* @0x184508 b 0x1844f0 <_Z16StartShaderBlocki+0x284> */
/* @0x18450c orr r4, r4, #2 */
/* @0x184510 b 0x1844f0 <_Z16StartShaderBlocki+0x284> */
/* @0x184514 orr r4, r4, #1 */
/* @0x184518 b 0x1844f0 <_Z16StartShaderBlocki+0x284> */
/* @0x18451c ldr r2, [pc, #0x290] */
/* @0x184520 ldr r3, [pc, #0x288] */
/* @0x184524 ldr r6, [r9, r2] */
/* @0x184528 ldr r8, [r9, r3] */
/* @0x18452c ldrb r3, [r6] */
/* @0x184530 ldrb r2, [r8] */
/* @0x184534 cmp r3, #0 */
/* @0x184538 orrne r2, r2, #2 */
/* @0x18453c cmp r4, #3 */
/* @0x184540 beq 0x184760 <_Z16StartShaderBlocki+0x4f4> */
/* @0x184544 cmp r4, #7 */
/* @0x184548 beq 0x1846c4 <_Z16StartShaderBlocki+0x458> */
/* @0x18454c cmp r4, #15 */
/* @0x184550 beq 0x184708 <_Z16StartShaderBlocki+0x49c> */
/* @0x184554 mov r0, #0 */
/* @0x184558 b 0x184460 <_Z16StartShaderBlocki+0x1f4> */
/* @0x18455c mov r0, r7 */
/* @0x184560 bl 0x184064 <_Z14SetFogUniformsP10GLSLShader> */
/* @0x184564 ldrb r3, [r6] */
/* @0x184568 cmp r3, #0 */
/* @0x18456c beq 0x184340 <_Z16StartShaderBlocki+0xd4> */
/* @0x184570 mov r0, r7 */
/* @0x184574 bl 0x184190 <_Z20SetAlphaTestUniformsP10GLSLShader> */
/* @0x184578 cmp r11, #0 */
/* @0x18457c beq 0x184348 <_Z16StartShaderBlocki+0xdc> */
/* @0x184580 mov r1, r10 */
/* @0x184584 mov r0, r7 */
/* @0x184588 bl 0x183d88 <_Z19SetLightingUniformsP10GLSLShaderi> */
/* @0x18458c b 0x184348 <_Z16StartShaderBlocki+0xdc> */
/* @0x184590 mov r4, #3 */
/* @0x184594 str r5, [sp, #0x4] */
/* @0x184598 b 0x1842f0 <_Z16StartShaderBlocki+0x84> */
/* @0x18459c ldr r3, [pc, #0x218] */
/* @0x1845a0 ldr r3, [r9, r3] */
/* @0x1845a4 ldr r3, [r3] */
/* @0x1845a8 blx r3 */
/* @0x1845ac ldr r3, [pc, #0x214] */
/* @0x1845b0 ldr r1, [r7, #0x20] */
/* @0x1845b4 add r3, pc, r3 */
/* @0x1845b8 ldr r2, [r3] */
/* @0x1845bc add r0, r2, #1 */
/* @0x1845c0 str r0, [r3] */
/* @0x1845c4 ldr r0, [r7, #0x28] */
/* @0x1845c8 add r3, r3, r2, lsl #2 */
/* @0x1845cc cmn r0, #1 */
/* @0x1845d0 str r1, [r3, #0x4] */
/* @0x1845d4 bne 0x18449c <_Z16StartShaderBlocki+0x230> */
/* @0x1845d8 b 0x1844a4 <_Z16StartShaderBlocki+0x238> */
/* @0x1845dc ldr r3, [pc, #0x1d8] */
/* @0x1845e0 ldr r3, [r9, r3] */
/* @0x1845e4 ldr r3, [r3] */
/* @0x1845e8 blx r3 */
/* @0x1845ec ldr r3, [pc, #0x1d8] */
/* @0x1845f0 ldr r1, [r7, #0x28] */
/* @0x1845f4 add r3, pc, r3 */
/* @0x1845f8 ldr r2, [r3] */
/* @0x1845fc add r0, r2, #1 */
/* @0x184600 str r0, [r3] */
/* @0x184604 ldr r0, [r7, #0x24] */
/* @0x184608 add r3, r3, r2, lsl #2 */
/* @0x18460c cmn r0, #1 */
/* @0x184610 str r1, [r3, #0x4] */
/* @0x184614 bne 0x1844b0 <_Z16StartShaderBlocki+0x244> */
/* @0x184618 b 0x18444c <_Z16StartShaderBlocki+0x1e0> */
/* @0x18461c ldr r3, [pc, #0x198] */
/* @0x184620 ldr r3, [r9, r3] */
/* @0x184624 ldr r3, [r3] */
/* @0x184628 blx r3 */
/* @0x18462c ldr r3, [pc, #0x19c] */
/* @0x184630 ldr r1, [r7, #0x1c] */
/* @0x184634 add r3, pc, r3 */
/* @0x184638 ldr r2, [r3] */
/* @0x18463c add r0, r2, #1 */
/* @0x184640 str r0, [r3] */
/* @0x184644 ldr r0, [r7, #0x20] */
/* @0x184648 add r3, r3, r2, lsl #2 */
/* @0x18464c cmn r0, #1 */
/* @0x184650 str r1, [r3, #0x4] */
/* @0x184654 bne 0x184488 <_Z16StartShaderBlocki+0x21c> */
/* @0x184658 b 0x184490 <_Z16StartShaderBlocki+0x224> */
/* @0x18465c ldr r6, [r2, #0x4] */
/* @0x184660 cmp r6, r11 */
/* @0x184664 movge r6, r11 */
/* @0x184668 cmp r6, #0 */
/* @0x18466c ble 0x18444c <_Z16StartShaderBlocki+0x1e0> */
/* @0x184670 ldr r5, [pc, #0x15c] */
/* @0x184674 ldr r10, [r7, #0x2c] */
/* @0x184678 add r5, pc, r5 */
/* @0x18467c ldr r0, [r10, r4, lsl #2] */
/* @0x184680 ldr r3, [pc, #0x134] */
/* @0x184684 cmn r0, #1 */
/* @0x184688 beq 0x1846b4 <_Z16StartShaderBlocki+0x448> */
/* @0x18468c ldr r3, [r9, r3] */
/* @0x184690 ldr r3, [r3] */
/* @0x184694 blx r3 */
/* @0x184698 ldr r10, [r7, #0x2c] */
/* @0x18469c ldr r3, [r5] */
/* @0x1846a0 ldr r2, [r10, r4, lsl #2] */
/* @0x1846a4 add r1, r3, #1 */
/* @0x1846a8 add r3, r5, r3, lsl #2 */
/* @0x1846ac str r1, [r5] */
/* @0x1846b0 str r2, [r3, #0x4] */
/* @0x1846b4 add r4, r4, #1 */
/* @0x1846b8 cmp r4, r6 */
/* @0x1846bc bne 0x18467c <_Z16StartShaderBlocki+0x410> */
/* @0x1846c0 b 0x18444c <_Z16StartShaderBlocki+0x1e0> */
/* @0x1846c4 ldr r3, [pc, #0x10c] */
/* @0x1846c8 mov r10, #0 */
/* @0x1846cc mov r11, r10 */
/* @0x1846d0 add r3, pc, r3 */
/* @0x1846d4 ldr r0, [r3, r2, lsl #2] */
/* @0x1846d8 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x1846dc mov r7, r0 */
/* @0x1846e0 cmp r7, #0 */
/* @0x1846e4 beq 0x184554 <_Z16StartShaderBlocki+0x2e8> */
/* @0x1846e8 ldr r3, [pc, #0xec] */
/* @0x1846ec ldr r0, [r7, #0x8] */
/* @0x1846f0 ldr r3, [r9, r3] */
/* @0x1846f4 ldr r3, [r3] */
/* @0x1846f8 blx r3 */
/* @0x1846fc mov r0, r7 */
/* @0x184700 bl 0x184230 <_Z20SetTransformUniformsP10GLSLShader> */
/* @0x184704 b 0x184328 <_Z16StartShaderBlocki+0xbc> */
/* @0x184708 ldr r3, [pc, #0xd0] */
/* @0x18470c ldr r3, [r9, r3] */
/* @0x184710 ldrb r10, [r3] */
/* @0x184714 cmp r10, #0 */
/* @0x184718 beq 0x184784 <_Z16StartShaderBlocki+0x518> */
/* @0x18471c ldr r1, [pc, #0xc0] */
/* @0x184720 mov r11, #1 */
/* @0x184724 ldr r3, [pc, #0xbc] */
/* @0x184728 ldr r0, [pc, #0xbc] */
/* @0x18472c ldr r1, [r9, r1] */
/* @0x184730 add r3, pc, r3 */
/* @0x184734 add r0, pc, r0 */
/* @0x184738 ldr r1, [r1] */
/* @0x18473c add r12, r3, r1, lsl #2 */
/* @0x184740 ldr r10, [r3, r1, lsl #2] */
/* @0x184744 ldr r3, [r12, #0x24] */
/* @0x184748 orr r2, r2, r3, lsl #2 */
/* @0x18474c add r3, r0, r2, lsl #2 */
/* @0x184750 ldr r0, [r3, #0x20] */
/* @0x184754 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x184758 mov r7, r0 */
/* @0x18475c b 0x1846e0 <_Z16StartShaderBlocki+0x474> */
/* @0x184760 ldr r3, [pc, #0x88] */
/* @0x184764 mov r10, #0 */
/* @0x184768 mov r11, r10 */
/* @0x18476c add r3, pc, r3 */
/* @0x184770 add r2, r3, r2, lsl #2 */
/* @0x184774 ldr r0, [r2, #0x60] */
/* @0x184778 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x18477c mov r7, r0 */
/* @0x184780 b 0x1846e0 <_Z16StartShaderBlocki+0x474> */
/* @0x184784 ldr r3, [pc, #0x68] */
/* @0x184788 mov r11, r10 */
/* @0x18478c add r3, pc, r3 */
/* @0x184790 add r2, r3, r2, lsl #2 */
/* @0x184794 ldr r0, [r2, #0x10] */
/* @0x184798 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x18479c mov r7, r0 */
/* @0x1847a0 b 0x1846e0 <_Z16StartShaderBlocki+0x474> */
/* @0x1847a4 ldrsbteq lr, [r1], -r8 */
/* @0x1847a8 eoreq sp, r6, r4, asr #19 */
/* @0x1847ac .word 0xffffe940 */
/* @0x1847b0 .word 0xffffe884 */
/* @0x1847b4 .word 0xffffe89c */
/* @0x1847b8 eorseq lr, r1, r4, asr #23 */
/* @0x1847bc .word 0xffffbb88 */
/* @0x1847c0 ldrshteq lr, [r1], -r8 */
/* @0x1847c4 eorseq lr, r1, r0, lsl #21 */
/* @0x1847c8 mlaseq r1, r12, r9, lr */
/* @0x1847cc eorseq lr, r1, r12, asr r9 */
/* @0x1847d0 eorseq lr, r1, r12, lsl r9 */
/* @0x1847d4 ldrsbteq lr, [r1], -r8 */
/* @0x1847d8 .word 0x0026e1d8 */
/* @0x1847dc .word 0xffffbb80 */
/* @0x1847e0 .word 0xffffe880 */
/* @0x1847e4 .word 0xffffe86c */
/* @0x1847e8 andseq r9, sp, r12, lsr #9 */
/* @0x1847ec eoreq lr, r6, r4, ror r1 */
/* @0x1847f0 eoreq lr, r6, r12, lsr r1 */
/* @0x1847f4 eoreq lr, r6, r12, lsl r1 */

/* ── FUNC 0x1847f8 · EndShaderBlock() · size=80 · insn=20 */
/* @0x1847f8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1847fc ldr r5, [pc, #0x3c] */
/* @0x184800 add r5, pc, r5 */
/* @0x184804 ldr r3, [r5] */
/* @0x184808 cmp r3, #0 */
/* @0x18480c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x184810 ldr r6, [pc, #0x2c] */
/* @0x184814 mov r7, r5 */
/* @0x184818 mov r4, #0 */
/* @0x18481c ldr r6, [pc, r6] */
/* @0x184820 ldr r3, [r6] */
/* @0x184824 add r4, r4, #1 */
/* @0x184828 ldr r0, [r5, #0x4]! */
/* @0x18482c blx r3 */
/* @0x184830 ldr r3, [r7] */
/* @0x184834 cmp r4, r3 */
/* @0x184838 blo 0x184820 <_Z14EndShaderBlockv+0x28> */
/* @0x18483c pop {r3, r4, r5, r6, r7, pc} */
/* @0x184840 eorseq lr, r1, r0, asr r7 */
/* @0x184844 eoreq r8, r6, r0, asr #31 */

/* ── FUNC 0x184848 · Graphics::AddVertexBuffer(int, int, bool) · size=8 · insn=2 */
/* @0x184848 mov r0, #0 */
/* @0x18484c bx lr */

/* ── FUNC 0x184850 · Graphics::VBLinkLast(VertexBuffer*) · size=4 · insn=1 */
/* @0x184850 bx lr */

/* ── FUNC 0x184854 · Graphics::VBUnLast(VertexBuffer*) · size=4 · insn=1 */
/* @0x184854 bx lr */

/* ── FUNC 0x184858 · Graphics::FVFSize(int) · size=8 · insn=2 */
/* @0x184858 mov r0, #0 */
/* @0x18485c bx lr */

/* ── FUNC 0x184860 · Graphics::FindVBSpace(int, int) · size=8 · insn=2 */
/* @0x184860 mov r0, #0 */
/* @0x184864 bx lr */

/* ── FUNC 0x184868 · _DrawArray(ePrimType, int, void*, int, void*) · size=2336 · insn=584 */
/* @0x184868 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18486c sub sp, sp, #36 */
/* @0x184870 ldr r4, [pc, #0x8dc] */
/* @0x184874 sub r0, r0, #1 */
/* @0x184878 ldr r7, [sp, #0x48] */
/* @0x18487c mov r8, r2 */
/* @0x184880 add r4, pc, r4 */
/* @0x184884 str r1, [sp, #0x10] */
/* @0x184888 mov r9, r3 */
/* @0x18488c str r7, [sp, #0x14] */
/* @0x184890 cmp r0, #5 */
/* @0x184894 addls pc, pc, r0, lsl #2 */
/* @0x184898 b 0x184d04 <_Z10_DrawArray9ePrimTypeiPviS0_+0x49c> */
/* @0x18489c b 0x184adc <_Z10_DrawArray9ePrimTypeiPviS0_+0x274> */
/* @0x1848a0 b 0x184ae8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x280> */
/* @0x1848a4 b 0x1848b4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x4c> */
/* @0x1848a8 b 0x184aa0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x238> */
/* @0x1848ac b 0x184ac4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x25c> */
/* @0x1848b0 b 0x184ad0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x268> */
/* @0x1848b4 mov r7, #3 */
/* @0x1848b8 str r7, [sp, #0x18] */
/* @0x1848bc ldr r2, [pc, #0x894] */
/* @0x1848c0 ldr r3, [pc, #0x894] */
/* @0x1848c4 ldr r1, [pc, #0x894] */
/* @0x1848c8 ldr r2, [r4, r2] */
/* @0x1848cc ldr r3, [r4, r3] */
/* @0x1848d0 ldr r1, [r4, r1] */
/* @0x1848d4 ldrb r6, [r2] */
/* @0x1848d8 ldrb r3, [r3] */
/* @0x1848dc cmp r6, #0 */
/* @0x1848e0 ldr r5, [r1] */
/* @0x1848e4 str r1, [sp, #0xc] */
/* @0x1848e8 movne r6, #3 */
/* @0x1848ec moveq r6, #2 */
/* @0x1848f0 cmp r3, #0 */
/* @0x1848f4 movne r6, #3 */
/* @0x1848f8 cmp r5, #0 */
/* @0x1848fc bne 0x184a14 <_Z10_DrawArray9ePrimTypeiPviS0_+0x1ac> */
/* @0x184900 tst r9, #16777216 */
/* @0x184904 beq 0x184af4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x28c> */
/* @0x184908 mov r0, r9 */
/* @0x18490c bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0x184910 ldr r3, [pc, #0x84c] */
/* @0x184914 ldr r6, [r4, r3] */
/* @0x184918 ldr r3, [r6] */
/* @0x18491c mov r7, r0 */
/* @0x184920 movw r0, #0x8074 */
/* @0x184924 ldr r10, [r7, #0xc] */
/* @0x184928 blx r3 */
/* @0x18492c ldr r3, [r6] */
/* @0x184930 movw r0, #0x8076 */
/* @0x184934 blx r3 */
/* @0x184938 ldr r3, [r6] */
/* @0x18493c movw r0, #0x8078 */
/* @0x184940 blx r3 */
/* @0x184944 ldr r3, [r6] */
/* @0x184948 movw r0, #0x8075 */
/* @0x18494c blx r3 */
/* @0x184950 ldr r12, [r7, #0x4] */
/* @0x184954 cmp r12, #0 */
/* @0x184958 ble 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188> */
/* @0x18495c mov r6, r5 */
/* @0x184960 str r9, [sp, #0x1c] */
/* @0x184964 ldr r9, [r7, #0x8] */
/* @0x184968 add r11, r9, r5 */
/* @0x18496c ldr r3, [r11, #0x8] */
/* @0x184970 sub r3, r3, #1 */
/* @0x184974 cmp r3, #3 */
/* @0x184978 addls pc, pc, r3, lsl #2 */
/* @0x18497c b 0x1849dc <_Z10_DrawArray9ePrimTypeiPviS0_+0x174> */
/* @0x184980 b 0x184a80 <_Z10_DrawArray9ePrimTypeiPviS0_+0x218> */
/* @0x184984 b 0x184a24 <_Z10_DrawArray9ePrimTypeiPviS0_+0x1bc> */
/* @0x184988 b 0x184a44 <_Z10_DrawArray9ePrimTypeiPviS0_+0x1dc> */
/* @0x18498c b 0x184990 <_Z10_DrawArray9ePrimTypeiPviS0_+0x128> */
/* @0x184990 ldr r1, [sp, #0x14] */
/* @0x184994 movw r0, #0x8078 */
/* @0x184998 ldr r3, [pc, #0x7c8] */
/* @0x18499c cmp r1, #0 */
/* @0x1849a0 beq 0x1849dc <_Z10_DrawArray9ePrimTypeiPviS0_+0x174> */
/* @0x1849a4 ldr r3, [r4, r3] */
/* @0x1849a8 ldr r3, [r3] */
/* @0x1849ac blx r3 */
/* @0x1849b0 ldr r0, [pc, #0x7b4] */
/* @0x1849b4 ldr r3, [r11] */
/* @0x1849b8 ldr r12, [r4, r0] */
/* @0x1849bc add r2, r10, r5 */
/* @0x1849c0 ldr r1, [r10, r5] */
/* @0x1849c4 add r3, r8, r3 */
/* @0x1849c8 ldr r0, [r2, #0x4] */
/* @0x1849cc ldr r12, [r12] */
/* @0x1849d0 ldr r2, [r7, #0x14] */
/* @0x1849d4 blx r12 */
/* @0x1849d8 ldr r12, [r7, #0x4] */
/* @0x1849dc add r6, r6, #1 */
/* @0x1849e0 add r5, r5, #16 */
/* @0x1849e4 cmp r12, r6 */
/* @0x1849e8 bgt 0x184964 <_Z10_DrawArray9ePrimTypeiPviS0_+0xfc> */
/* @0x1849ec ldr r9, [sp, #0x1c] */
/* @0x1849f0 ldr r3, [pc, #0x778] */
/* @0x1849f4 mov r1, #0 */
/* @0x1849f8 ldr r0, [sp, #0x18] */
/* @0x1849fc ldr r2, [sp, #0x10] */
/* @0x184a00 ldr r3, [r4, r3] */
/* @0x184a04 ldr r3, [r3] */
/* @0x184a08 blx r3 */
/* @0x184a0c ldr r7, [sp, #0xc] */
/* @0x184a10 ldr r5, [r7] */
/* @0x184a14 cmp r5, #1 */
/* @0x184a18 beq 0x184bc8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x360> */
/* @0x184a1c add sp, sp, #36 */
/* @0x184a20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x184a24 ldr r3, [pc, #0x73c] */
/* @0x184a28 movw r0, #0x8076 */
/* @0x184a2c ldr r3, [r4, r3] */
/* @0x184a30 ldr r3, [r3] */
/* @0x184a34 blx r3 */
/* @0x184a38 ldr r0, [pc, #0x734] */
/* @0x184a3c ldr r3, [r9, r5] */
/* @0x184a40 b 0x1849b8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x150> */
/* @0x184a44 ldr r3, [pc, #0x71c] */
/* @0x184a48 movw r0, #0x8075 */
/* @0x184a4c ldr r3, [r4, r3] */
/* @0x184a50 ldr r3, [r3] */
/* @0x184a54 blx r3 */
/* @0x184a58 ldr r3, [pc, #0x718] */
/* @0x184a5c ldr r2, [r9, r5] */
/* @0x184a60 ldr r0, [r10, r5] */
/* @0x184a64 ldr r3, [r4, r3] */
/* @0x184a68 add r2, r8, r2 */
/* @0x184a6c ldr r1, [r7, #0x14] */
/* @0x184a70 ldr r3, [r3] */
/* @0x184a74 blx r3 */
/* @0x184a78 ldr r12, [r7, #0x4] */
/* @0x184a7c b 0x1849dc <_Z10_DrawArray9ePrimTypeiPviS0_+0x174> */
/* @0x184a80 ldr r3, [pc, #0x6e0] */
/* @0x184a84 movw r0, #0x8074 */
/* @0x184a88 ldr r3, [r4, r3] */
/* @0x184a8c ldr r3, [r3] */
/* @0x184a90 blx r3 */
/* @0x184a94 ldr r0, [pc, #0x6e0] */
/* @0x184a98 ldr r3, [r9, r5] */
/* @0x184a9c b 0x1849b8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x150> */
/* @0x184aa0 ldr r3, [pc, #0x6d8] */
/* @0x184aa4 mov r7, #4 */
/* @0x184aa8 str r7, [sp, #0x18] */
/* @0x184aac ldr r3, [r4, r3] */
/* @0x184ab0 ldr r7, [sp, #0x10] */
/* @0x184ab4 ldr r2, [r3] */
/* @0x184ab8 add r2, r2, r7 */
/* @0x184abc str r2, [r3] */
/* @0x184ac0 b 0x1848bc <_Z10_DrawArray9ePrimTypeiPviS0_+0x54> */
/* @0x184ac4 ldr r3, [pc, #0x6b4] */
/* @0x184ac8 mov r7, #5 */
/* @0x184acc b 0x184aa8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x240> */
/* @0x184ad0 ldr r3, [pc, #0x6a8] */
/* @0x184ad4 mov r7, #6 */
/* @0x184ad8 b 0x184aa8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x240> */
/* @0x184adc ldr r3, [pc, #0x69c] */
/* @0x184ae0 mov r7, #0 */
/* @0x184ae4 b 0x184aa8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x240> */
/* @0x184ae8 mov r7, #1 */
/* @0x184aec str r7, [sp, #0x18] */
/* @0x184af0 b 0x1848bc <_Z10_DrawArray9ePrimTypeiPviS0_+0x54> */
/* @0x184af4 cmp r9, #16 */
/* @0x184af8 beq 0x184f10 <_Z10_DrawArray9ePrimTypeiPviS0_+0x6a8> */
/* @0x184afc cmp r9, #24 */
/* @0x184b00 ldr r3, [pc, #0x660] */
/* @0x184b04 beq 0x184df4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x58c> */
/* @0x184b08 ldr r5, [r4, r3] */
/* @0x184b0c movw r0, #0x8074 */
/* @0x184b10 ldr r3, [r5] */
/* @0x184b14 blx r3 */
/* @0x184b18 ldr r12, [pc, #0x65c] */
/* @0x184b1c movw r1, #0x1406 */
/* @0x184b20 mov r2, #36 */
/* @0x184b24 mov r0, r6 */
/* @0x184b28 mov r3, r8 */
/* @0x184b2c ldr r12, [r4, r12] */
/* @0x184b30 ldr r12, [r12] */
/* @0x184b34 blx r12 */
/* @0x184b38 ldr r3, [r5] */
/* @0x184b3c movw r0, #0x8076 */
/* @0x184b40 blx r3 */
/* @0x184b44 ldr r12, [pc, #0x628] */
/* @0x184b48 mov r0, #4 */
/* @0x184b4c movw r1, #0x1401 */
/* @0x184b50 mov r2, #36 */
/* @0x184b54 add r3, r8, #24 */
/* @0x184b58 ldr r12, [r4, r12] */
/* @0x184b5c ldr r12, [r12] */
/* @0x184b60 blx r12 */
/* @0x184b64 ldr r7, [sp, #0x14] */
/* @0x184b68 cmp r7, #0 */
/* @0x184b6c beq 0x184ffc <_Z10_DrawArray9ePrimTypeiPviS0_+0x794> */
/* @0x184b70 ldr r3, [r5] */
/* @0x184b74 movw r0, #0x8078 */
/* @0x184b78 blx r3 */
/* @0x184b7c ldr r12, [pc, #0x5e8] */
/* @0x184b80 mov r0, #2 */
/* @0x184b84 movw r1, #0x1406 */
/* @0x184b88 mov r2, #36 */
/* @0x184b8c add r3, r8, #28 */
/* @0x184b90 ldr r12, [r4, r12] */
/* @0x184b94 ldr r12, [r12] */
/* @0x184b98 blx r12 */
/* @0x184b9c ldr r3, [r5] */
/* @0x184ba0 movw r0, #0x8075 */
/* @0x184ba4 blx r3 */
/* @0x184ba8 ldr r3, [pc, #0x5c8] */
/* @0x184bac movw r0, #0x1406 */
/* @0x184bb0 mov r1, #36 */
/* @0x184bb4 add r2, r8, #12 */
/* @0x184bb8 ldr r3, [r4, r3] */
/* @0x184bbc ldr r3, [r3] */
/* @0x184bc0 blx r3 */
/* @0x184bc4 b 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188> */
/* @0x184bc8 mov r0, r9 */
/* @0x184bcc bl 0x18426c <_Z16StartShaderBlocki> */
/* @0x184bd0 subs r5, r0, #0 */
/* @0x184bd4 beq 0x184a1c <_Z10_DrawArray9ePrimTypeiPviS0_+0x1b4> */
/* @0x184bd8 ands r3, r9, #16777216 */
/* @0x184bdc beq 0x184d10 <_Z10_DrawArray9ePrimTypeiPviS0_+0x4a8> */
/* @0x184be0 mov r0, r9 */
/* @0x184be4 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0x184be8 ldr r10, [r5, #0x30] */
/* @0x184bec cmp r10, #0 */
/* @0x184bf0 mov r11, r0 */
/* @0x184bf4 ldr r7, [r0, #0xc] */
/* @0x184bf8 ble 0x18508c <_Z10_DrawArray9ePrimTypeiPviS0_+0x824> */
/* @0x184bfc ldr r6, [r5, #0x34] */
/* @0x184c00 cmp r6, #0 */
/* @0x184c04 beq 0x184ea0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x638> */
/* @0x184c08 ldr r1, [r11, #0x8] */
/* @0x184c0c mov r6, #0 */
/* @0x184c10 str r4, [sp, #0x14] */
/* @0x184c14 mov r4, r7 */
/* @0x184c18 str r8, [sp, #0x1c] */
/* @0x184c1c str r1, [sp, #0xc] */
/* @0x184c20 ldr r3, [r5, #0x2c] */
/* @0x184c24 ldr r0, [r3, r6, lsl #2] */
/* @0x184c28 cmn r0, #1 */
/* @0x184c2c beq 0x184ccc <_Z10_DrawArray9ePrimTypeiPviS0_+0x464> */
/* @0x184c30 ldr lr, [r11, #0x4] */
/* @0x184c34 ldr r2, [r5, #0x34] */
/* @0x184c38 ldr r3, [r5, #0x38] */
/* @0x184c3c cmp lr, #0 */
/* @0x184c40 ldr r8, [r2, r6, lsl #2] */
/* @0x184c44 ldr r9, [r3, r6, lsl #2] */
/* @0x184c48 ble 0x184ccc <_Z10_DrawArray9ePrimTypeiPviS0_+0x464> */
/* @0x184c4c ldr r2, [sp, #0xc] */
/* @0x184c50 mov r12, r4 */
/* @0x184c54 mov r3, #0 */
/* @0x184c58 b 0x184c68 <_Z10_DrawArray9ePrimTypeiPviS0_+0x400> */
/* @0x184c5c cmp r3, lr */
/* @0x184c60 add r12, r12, #16 */
/* @0x184c64 beq 0x184ccc <_Z10_DrawArray9ePrimTypeiPviS0_+0x464> */
/* @0x184c68 ldr r1, [r2, #0x8] */
/* @0x184c6c lsl r7, r3, #4 */
/* @0x184c70 add r2, r2, #16 */
/* @0x184c74 add r3, r3, #1 */
/* @0x184c78 cmp r1, r8 */
/* @0x184c7c bne 0x184c5c <_Z10_DrawArray9ePrimTypeiPviS0_+0x3f4> */
/* @0x184c80 ldr r1, [r12, #0xc] */
/* @0x184c84 cmp r1, r9 */
/* @0x184c88 bne 0x184c5c <_Z10_DrawArray9ePrimTypeiPviS0_+0x3f4> */
/* @0x184c8c ldr lr, [r11, #0x14] */
/* @0x184c90 ldr r2, [sp, #0x14] */
/* @0x184c94 ldr r3, [pc, #0x4e8] */
/* @0x184c98 ldr r1, [r12, #0x4] */
/* @0x184c9c ldr r8, [r2, r3] */
/* @0x184ca0 ldr r2, [r12] */
/* @0x184ca4 ldrb r3, [r12, #0x8] */
/* @0x184ca8 str lr, [sp] */
/* @0x184cac ldr lr, [r11, #0x8] */
/* @0x184cb0 ldr r12, [r8] */
/* @0x184cb4 ldr lr, [lr, r7] */
/* @0x184cb8 ldr r7, [sp, #0x1c] */
/* @0x184cbc add lr, r7, lr */
/* @0x184cc0 str lr, [sp, #0x4] */
/* @0x184cc4 blx r12 */
/* @0x184cc8 ldr r10, [r5, #0x30] */
/* @0x184ccc add r6, r6, #1 */
/* @0x184cd0 cmp r10, r6 */
/* @0x184cd4 bgt 0x184c20 <_Z10_DrawArray9ePrimTypeiPviS0_+0x3b8> */
/* @0x184cd8 ldr r4, [sp, #0x14] */
/* @0x184cdc ldr r3, [pc, #0x48c] */
/* @0x184ce0 mov r1, #0 */
/* @0x184ce4 ldr r0, [sp, #0x18] */
/* @0x184ce8 ldr r2, [sp, #0x10] */
/* @0x184cec ldr r3, [r4, r3] */
/* @0x184cf0 ldr r3, [r3] */
/* @0x184cf4 blx r3 */
/* @0x184cf8 add sp, sp, #36 */
/* @0x184cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x184d00 b 0x1847f8 <_Z14EndShaderBlockv> */
/* @0x184d04 mov r7, #4 */
/* @0x184d08 str r7, [sp, #0x18] */
/* @0x184d0c b 0x1848bc <_Z10_DrawArray9ePrimTypeiPviS0_+0x54> */
/* @0x184d10 cmp r9, #16 */
/* @0x184d14 beq 0x184f94 <_Z10_DrawArray9ePrimTypeiPviS0_+0x72c> */
/* @0x184d18 cmp r9, #24 */
/* @0x184d1c ldr r0, [r5, #0x1c] */
/* @0x184d20 beq 0x185014 <_Z10_DrawArray9ePrimTypeiPviS0_+0x7ac> */
/* @0x184d24 cmn r0, #1 */
/* @0x184d28 beq 0x184d50 <_Z10_DrawArray9ePrimTypeiPviS0_+0x4e8> */
/* @0x184d2c ldr r12, [pc, #0x450] */
/* @0x184d30 mov lr, #36 */
/* @0x184d34 mov r1, #3 */
/* @0x184d38 movw r2, #0x1406 */
/* @0x184d3c ldr r12, [r4, r12] */
/* @0x184d40 str r8, [sp, #0x4] */
/* @0x184d44 str lr, [sp] */
/* @0x184d48 ldr r12, [r12] */
/* @0x184d4c blx r12 */
/* @0x184d50 ldr r0, [r5, #0x20] */
/* @0x184d54 cmn r0, #1 */
/* @0x184d58 beq 0x184d84 <_Z10_DrawArray9ePrimTypeiPviS0_+0x51c> */
/* @0x184d5c ldr r3, [pc, #0x420] */
/* @0x184d60 mov r6, #36 */
/* @0x184d64 add lr, r8, #12 */
/* @0x184d68 mov r1, #3 */
/* @0x184d6c movw r2, #0x1406 */
/* @0x184d70 ldr r12, [r4, r3] */
/* @0x184d74 mov r3, #0 */
/* @0x184d78 stm sp, {r6, lr} */
/* @0x184d7c ldr r12, [r12] */
/* @0x184d80 blx r12 */
/* @0x184d84 ldr r0, [r5, #0x28] */
/* @0x184d88 cmn r0, #1 */
/* @0x184d8c beq 0x184db8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x550> */
/* @0x184d90 ldr r3, [pc, #0x3ec] */
/* @0x184d94 mov r6, #36 */
/* @0x184d98 add lr, r8, #24 */
/* @0x184d9c mov r1, #4 */
/* @0x184da0 movw r2, #0x1401 */
/* @0x184da4 ldr r12, [r4, r3] */
/* @0x184da8 mov r3, #1 */
/* @0x184dac stm sp, {r6, lr} */
/* @0x184db0 ldr r12, [r12] */
/* @0x184db4 blx r12 */
/* @0x184db8 ldr r0, [r5, #0x24] */
/* @0x184dbc cmn r0, #1 */
/* @0x184dc0 beq 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x184dc4 ldr r3, [pc, #0x3b8] */
/* @0x184dc8 add r8, r8, #28 */
/* @0x184dcc mov lr, #36 */
/* @0x184dd0 ldr r12, [r4, r3] */
/* @0x184dd4 mov r1, #2 */
/* @0x184dd8 str r8, [sp, #0x4] */
/* @0x184ddc movw r2, #0x1406 */
/* @0x184de0 str lr, [sp] */
/* @0x184de4 mov r3, #0 */
/* @0x184de8 ldr r12, [r12] */
/* @0x184dec blx r12 */
/* @0x184df0 b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x184df4 ldr r5, [r4, r3] */
/* @0x184df8 movw r0, #0x8076 */
/* @0x184dfc ldr r3, [r5] */
/* @0x184e00 blx r3 */
/* @0x184e04 ldr r12, [pc, #0x368] */
/* @0x184e08 movw r1, #0x1401 */
/* @0x184e0c mov r2, r9 */
/* @0x184e10 mov r0, #4 */
/* @0x184e14 add r3, r8, #12 */
/* @0x184e18 ldr r12, [r4, r12] */
/* @0x184e1c ldr r12, [r12] */
/* @0x184e20 blx r12 */
/* @0x184e24 ldr r3, [r5] */
/* @0x184e28 movw r0, #0x8074 */
/* @0x184e2c blx r3 */
/* @0x184e30 ldr r12, [pc, #0x344] */
/* @0x184e34 mov r0, r6 */
/* @0x184e38 movw r1, #0x1406 */
/* @0x184e3c mov r2, r9 */
/* @0x184e40 mov r3, r8 */
/* @0x184e44 ldr r12, [r4, r12] */
/* @0x184e48 ldr r12, [r12] */
/* @0x184e4c blx r12 */
/* @0x184e50 ldr r7, [sp, #0x14] */
/* @0x184e54 cmp r7, #0 */
/* @0x184e58 beq 0x185138 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8d0> */
/* @0x184e5c ldr r3, [r5] */
/* @0x184e60 movw r0, #0x8078 */
/* @0x184e64 blx r3 */
/* @0x184e68 ldr r12, [pc, #0x2fc] */
/* @0x184e6c add r3, r8, #16 */
/* @0x184e70 mov r0, #2 */
/* @0x184e74 movw r1, #0x1406 */
/* @0x184e78 mov r2, r9 */
/* @0x184e7c ldr r12, [r4, r12] */
/* @0x184e80 ldr r12, [r12] */
/* @0x184e84 blx r12 */
/* @0x184e88 ldr r3, [pc, #0x2d4] */
/* @0x184e8c ldr r5, [r4, r3] */
/* @0x184e90 ldr r3, [r5] */
/* @0x184e94 movw r0, #0x8075 */
/* @0x184e98 blx r3 */
/* @0x184e9c b 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188> */
/* @0x184ea0 ldr r3, [r11, #0x4] */
/* @0x184ea4 cmp r3, r10 */
/* @0x184ea8 movlt r9, r3 */
/* @0x184eac movge r9, r10 */
/* @0x184eb0 cmp r9, #0 */
/* @0x184eb4 ble 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x184eb8 ldr r3, [r5, #0x2c] */
/* @0x184ebc ldr r2, [pc, #0x2c0] */
/* @0x184ec0 ldr r12, [r11, #0x8] */
/* @0x184ec4 ldr r0, [r3, r6, lsl #2] */
/* @0x184ec8 cmn r0, #1 */
/* @0x184ecc beq 0x184efc <_Z10_DrawArray9ePrimTypeiPviS0_+0x694> */
/* @0x184ed0 ldr lr, [r11, #0x14] */
/* @0x184ed4 ldr r10, [r4, r2] */
/* @0x184ed8 ldr r1, [r7, #0x4] */
/* @0x184edc ldr r2, [r7] */
/* @0x184ee0 ldrb r3, [r7, #0x8] */
/* @0x184ee4 str lr, [sp] */
/* @0x184ee8 ldr lr, [r12, r6, lsl #4] */
/* @0x184eec ldr r12, [r10] */
/* @0x184ef0 add lr, r8, lr */
/* @0x184ef4 str lr, [sp, #0x4] */
/* @0x184ef8 blx r12 */
/* @0x184efc add r6, r6, #1 */
/* @0x184f00 add r7, r7, #16 */
/* @0x184f04 cmp r6, r9 */
/* @0x184f08 bne 0x184eb8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x650> */
/* @0x184f0c b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x184f10 ldr r3, [pc, #0x250] */
/* @0x184f14 movw r0, #0x8074 */
/* @0x184f18 ldr r5, [r4, r3] */
/* @0x184f1c ldr r3, [r5] */
/* @0x184f20 blx r3 */
/* @0x184f24 ldr r12, [pc, #0x250] */
/* @0x184f28 movw r1, #0x1406 */
/* @0x184f2c mov r2, r9 */
/* @0x184f30 mov r0, r6 */
/* @0x184f34 mov r3, r8 */
/* @0x184f38 ldr r12, [r4, r12] */
/* @0x184f3c ldr r12, [r12] */
/* @0x184f40 blx r12 */
/* @0x184f44 ldr r3, [r5] */
/* @0x184f48 movw r0, #0x8076 */
/* @0x184f4c blx r3 */
/* @0x184f50 ldr r12, [pc, #0x21c] */
/* @0x184f54 mov r0, #4 */
/* @0x184f58 add r3, r8, #12 */
/* @0x184f5c movw r1, #0x1401 */
/* @0x184f60 mov r2, r9 */
/* @0x184f64 ldr r12, [r4, r12] */
/* @0x184f68 ldr r12, [r12] */
/* @0x184f6c blx r12 */
/* @0x184f70 ldr r7, [sp, #0x14] */
/* @0x184f74 ldr r3, [pc, #0x1e8] */
/* @0x184f78 movw r0, #0x8078 */
/* @0x184f7c cmp r7, #0 */
/* @0x184f80 beq 0x185144 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8dc> */
/* @0x184f84 ldr r5, [r4, r3] */
/* @0x184f88 ldr r3, [r5] */
/* @0x184f8c blx r3 */
/* @0x184f90 b 0x184e90 <_Z10_DrawArray9ePrimTypeiPviS0_+0x628> */
/* @0x184f94 ldr r0, [r5, #0x1c] */
/* @0x184f98 cmn r0, #1 */
/* @0x184f9c beq 0x184fc0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x758> */
/* @0x184fa0 ldr r12, [pc, #0x1dc] */
/* @0x184fa4 mov r1, #3 */
/* @0x184fa8 movw r2, #0x1406 */
/* @0x184fac ldr r12, [r4, r12] */
/* @0x184fb0 str r9, [sp] */
/* @0x184fb4 str r8, [sp, #0x4] */
/* @0x184fb8 ldr r12, [r12] */
/* @0x184fbc blx r12 */
/* @0x184fc0 ldr r0, [r5, #0x28] */
/* @0x184fc4 cmn r0, #1 */
/* @0x184fc8 beq 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x184fcc ldr r3, [pc, #0x1b0] */
/* @0x184fd0 add r8, r8, #12 */
/* @0x184fd4 mov lr, #16 */
/* @0x184fd8 mov r1, #4 */
/* @0x184fdc movw r2, #0x1401 */
/* @0x184fe0 ldr r12, [r4, r3] */
/* @0x184fe4 mov r3, #1 */
/* @0x184fe8 str r8, [sp, #0x4] */
/* @0x184fec str lr, [sp] */
/* @0x184ff0 ldr r12, [r12] */
/* @0x184ff4 blx r12 */
/* @0x184ff8 b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x184ffc ldr r3, [pc, #0x160] */
/* @0x185000 movw r0, #0x8078 */
/* @0x185004 ldr r3, [r4, r3] */
/* @0x185008 ldr r3, [r3] */
/* @0x18500c blx r3 */
/* @0x185010 b 0x184b9c <_Z10_DrawArray9ePrimTypeiPviS0_+0x334> */
/* @0x185014 cmn r0, #1 */
/* @0x185018 beq 0x18503c <_Z10_DrawArray9ePrimTypeiPviS0_+0x7d4> */
/* @0x18501c ldr r12, [pc, #0x160] */
/* @0x185020 mov r1, #3 */
/* @0x185024 movw r2, #0x1406 */
/* @0x185028 ldr r12, [r4, r12] */
/* @0x18502c str r9, [sp] */
/* @0x185030 str r8, [sp, #0x4] */
/* @0x185034 ldr r12, [r12] */
/* @0x185038 blx r12 */
/* @0x18503c ldr r0, [r5, #0x28] */
/* @0x185040 cmn r0, #1 */
/* @0x185044 beq 0x185070 <_Z10_DrawArray9ePrimTypeiPviS0_+0x808> */
/* @0x185048 ldr r3, [pc, #0x134] */
/* @0x18504c mov r6, #24 */
/* @0x185050 add lr, r8, #12 */
/* @0x185054 mov r1, #4 */
/* @0x185058 movw r2, #0x1401 */
/* @0x18505c ldr r12, [r4, r3] */
/* @0x185060 mov r3, #1 */
/* @0x185064 stm sp, {r6, lr} */
/* @0x185068 ldr r12, [r12] */
/* @0x18506c blx r12 */
/* @0x185070 ldr r0, [r5, #0x24] */
/* @0x185074 cmn r0, #1 */
/* @0x185078 beq 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x18507c ldr r3, [pc, #0x100] */
/* @0x185080 add r8, r8, #16 */
/* @0x185084 mov lr, #24 */
/* @0x185088 b 0x184dd0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x568> */
/* @0x18508c ldr r2, [r0, #0x4] */
/* @0x185090 cmp r2, #0 */
/* @0x185094 ble 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x185098 mov r6, #0 */
/* @0x18509c ldr lr, [r11, #0x8] */
/* @0x1850a0 lsl r12, r6, #4 */
/* @0x1850a4 add r3, lr, r12 */
/* @0x1850a8 ldr r3, [r3, #0x8] */
/* @0x1850ac sub r3, r3, #1 */
/* @0x1850b0 cmp r3, #3 */
/* @0x1850b4 addls pc, pc, r3, lsl #2 */
/* @0x1850b8 b 0x18510c <_Z10_DrawArray9ePrimTypeiPviS0_+0x8a4> */
/* @0x1850bc b 0x185120 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8b8> */
/* @0x1850c0 b 0x185130 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8c8> */
/* @0x1850c4 b 0x185128 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8c0> */
/* @0x1850c8 b 0x1850cc <_Z10_DrawArray9ePrimTypeiPviS0_+0x864> */
/* @0x1850cc ldr r0, [r5, #0x24] */
/* @0x1850d0 cmn r0, #1 */
/* @0x1850d4 ldr r3, [pc, #0xa8] */
/* @0x1850d8 beq 0x18510c <_Z10_DrawArray9ePrimTypeiPviS0_+0x8a4> */
/* @0x1850dc ldr r10, [r11, #0x14] */
/* @0x1850e0 ldr r9, [r4, r3] */
/* @0x1850e4 ldr r2, [r7] */
/* @0x1850e8 ldr r1, [r7, #0x4] */
/* @0x1850ec ldrb r3, [r7, #0x8] */
/* @0x1850f0 str r10, [sp] */
/* @0x1850f4 ldr lr, [lr, r12] */
/* @0x1850f8 ldr r12, [r9] */
/* @0x1850fc add lr, r8, lr */
/* @0x185100 str lr, [sp, #0x4] */
/* @0x185104 blx r12 */
/* @0x185108 ldr r2, [r11, #0x4] */
/* @0x18510c add r6, r6, #1 */
/* @0x185110 add r7, r7, #16 */
/* @0x185114 cmp r2, r6 */
/* @0x185118 bgt 0x18509c <_Z10_DrawArray9ePrimTypeiPviS0_+0x834> */
/* @0x18511c b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474> */
/* @0x185120 ldr r0, [r5, #0x1c] */
/* @0x185124 b 0x1850d0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x868> */
/* @0x185128 ldr r0, [r5, #0x20] */
/* @0x18512c b 0x1850d0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x868> */
/* @0x185130 ldr r0, [r5, #0x28] */
/* @0x185134 b 0x1850d0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x868> */
/* @0x185138 ldr r3, [pc, #0x24] */
/* @0x18513c movw r0, #0x8078 */
/* @0x185140 b 0x184f84 <_Z10_DrawArray9ePrimTypeiPviS0_+0x71c> */
/* @0x185144 ldr r3, [r4, r3] */
/* @0x185148 ldr r3, [r3] */
/* @0x18514c blx r3 */
/* @0x185150 b 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188> */
/* @0x185154 .word 0x0026d3d0 */
/* @0x185158 .word 0xffffc0b4 */
/* @0x18515c .word 0xffffbcd4 */
/* @0x185160 .word 0xffffe7b8 */
/* @0x185164 .word 0xffffbc2c */
/* @0x185168 .word 0xffffbc30 */
/* @0x18516c .word 0xffffbca8 */
/* @0x185170 .word 0xffffbad4 */
/* @0x185174 .word 0xffffbc28 */
/* @0x185178 .word 0xffffbc50 */
/* @0x18517c .word 0xffffbc6c */
/* @0x185180 .word 0xffffe944 */
/* @0x185184 .word 0xffffbb90 */

/* ── FUNC 0x185188 · Graphics::DrawArrayEx(ePrimType, int, void*, int) · size=48 · insn=12 */
/* @0x185188 cmp r1, #0 */
/* @0x18518c str lr, [sp, #-0x4]! */
/* @0x185190 sub sp, sp, #12 */
/* @0x185194 beq 0x1851ac <_ZN8Graphics11DrawArrayExE9ePrimTypeiPvi+0x24> */
/* @0x185198 ldr r12, [pc, #0x14] */
/* @0x18519c ldr r12, [pc, r12] */
/* @0x1851a0 ldr r12, [r12] */
/* @0x1851a4 str r12, [sp] */
/* @0x1851a8 bl 0x184868 <_Z10_DrawArray9ePrimTypeiPviS0_> */
/* @0x1851ac add sp, sp, #12 */
/* @0x1851b0 ldr pc, [sp], #4 */
/* @0x1851b4 eoreq r11, r6, r12, lsr #7 */

/* ── FUNC 0x1851b8 · Graphics::ResetVBuffers() · size=96 · insn=24 */
/* @0x1851b8 ldr r3, [pc, #0x44] */
/* @0x1851bc mov r2, #0 */
/* @0x1851c0 ldr r1, [pc, #0x40] */
/* @0x1851c4 add r3, pc, r3 */
/* @0x1851c8 ldr r12, [pc, #0x3c] */
/* @0x1851cc push {r4, r5} */
/* @0x1851d0 mvn r4, #0 */
/* @0x1851d4 ldr r5, [r3, r1] */
/* @0x1851d8 ldr r0, [pc, #0x30] */
/* @0x1851dc ldr r1, [pc, #0x30] */
/* @0x1851e0 str r2, [r5] */
/* @0x1851e4 ldr r12, [r3, r12] */
/* @0x1851e8 str r4, [r12] */
/* @0x1851ec ldr r0, [r3, r0] */
/* @0x1851f0 pop {r4, r5} */
/* @0x1851f4 str r2, [r0] */
/* @0x1851f8 ldr r3, [r3, r1] */
/* @0x1851fc str r2, [r3] */
/* @0x185200 bx lr */
/* @0x185204 eoreq r12, r6, r12, lsl #21 */
/* @0x185208 .word 0xffffe944 */
/* @0x18520c .word 0xffffe948 */
/* @0x185210 .word 0xffffe94c */
/* @0x185214 .word 0xffffe950 */

/* ── FUNC 0x185218 · JoinToPreviousStrip() · size=212 · insn=53 */
/* @0x185218 ldr r3, [pc, #0xb8] */
/* @0x18521c ldr r2, [pc, #0xb8] */
/* @0x185220 add r3, pc, r3 */
/* @0x185224 push {r4, r5, r6, r7, r8, lr} */
/* @0x185228 ldr r2, [r3, r2] */
/* @0x18522c ldr r2, [r2] */
/* @0x185230 cmp r2, #5 */
/* @0x185234 popne {r4, r5, r6, r7, r8, pc} */
/* @0x185238 ldr r2, [pc, #0xa0] */
/* @0x18523c ldr r2, [r3, r2] */
/* @0x185240 ldr r12, [r2] */
/* @0x185244 cmp r12, #0 */
/* @0x185248 pople {r4, r5, r6, r7, r8, pc} */
/* @0x18524c ldr r2, [pc, #0x90] */
/* @0x185250 tst r12, #1 */
/* @0x185254 ldr r1, [pc, #0x8c] */
/* @0x185258 ldr r2, [r3, r2] */
/* @0x18525c ldr r5, [r3, r1] */
/* @0x185260 ldr r4, [r2] */
/* @0x185264 mul r0, r4, r12 */
/* @0x185268 mov r2, r4 */
/* @0x18526c rsb r6, r4, r0 */
/* @0x185270 add r0, r5, r0 */
/* @0x185274 bne 0x18529c <_Z19JoinToPreviousStripv+0x84> */
/* @0x185278 add r1, r5, r6 */
/* @0x18527c bl 0xb65bc <memcpy@plt> */
/* @0x185280 add r0, r6, r4, lsl #1 */
/* @0x185284 add r1, r0, r4 */
/* @0x185288 mov r2, r4 */
/* @0x18528c add r0, r5, r0 */
/* @0x185290 add r1, r5, r1 */
/* @0x185294 pop {r4, r5, r6, r7, r8, lr} */
/* @0x185298 b 0xb65bc <memcpy@plt> */
/* @0x18529c add r8, r6, r4, lsl #2 */
/* @0x1852a0 add r1, r5, r6 */
/* @0x1852a4 add r7, r8, r5 */
/* @0x1852a8 bl 0xb65bc <memcpy@plt> */
/* @0x1852ac add r0, r6, r4, lsl #1 */
/* @0x1852b0 mov r2, r4 */
/* @0x1852b4 mov r1, r7 */
/* @0x1852b8 add r0, r5, r0 */
/* @0x1852bc bl 0xb65bc <memcpy@plt> */
/* @0x1852c0 rsb r0, r4, r8 */
/* @0x1852c4 mov r1, r7 */
/* @0x1852c8 add r0, r5, r0 */
/* @0x1852cc mov r2, r4 */
/* @0x1852d0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1852d4 b 0xb65bc <memcpy@plt> */
/* @0x1852d8 eoreq r12, r6, r0, lsr r10 */
/* @0x1852dc .word 0xffffe948 */
/* @0x1852e0 .word 0xffffe950 */
/* @0x1852e4 .word 0xffffe954 */
/* @0x1852e8 .word 0xffffe958 */

/* ── FUNC 0x1852ec · Graphics::Flush() · size=300 · insn=75 */
/* @0x1852ec push {r4, r5, r6, lr} */
/* @0x1852f0 ldr r4, [pc, #0xf0] */
/* @0x1852f4 ldr r3, [pc, #0xf0] */
/* @0x1852f8 add r4, pc, r4 */
/* @0x1852fc ldr r5, [r4, r3] */
/* @0x185300 ldr r3, [r5] */
/* @0x185304 cmp r3, #0 */
/* @0x185308 blt 0x1853c4 <_ZN8Graphics5FlushEv+0xd8> */
/* @0x18530c ldr r2, [pc, #0xdc] */
/* @0x185310 ldr r3, [pc, #0xdc] */
/* @0x185314 ldr r6, [r4, r2] */
/* @0x185318 ldr r3, [r4, r3] */
/* @0x18531c ldr r2, [r6] */
/* @0x185320 ldr r1, [r3] */
/* @0x185324 cmp r1, r2 */
/* @0x185328 strlt r2, [r3] */
/* @0x18532c bl 0x185218 <_Z19JoinToPreviousStripv> */
/* @0x185330 ldr r2, [pc, #0xc0] */
/* @0x185334 ldr r3, [pc, #0xc0] */
/* @0x185338 ldr r2, [r4, r2] */
/* @0x18533c ldr r3, [r4, r3] */
/* @0x185340 ldr r0, [r2] */
/* @0x185344 ldr r1, [r3] */
/* @0x185348 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x18534c ldr r3, [pc, #0xac] */
/* @0x185350 ldr r2, [pc, #0xac] */
/* @0x185354 ldr r0, [r5] */
/* @0x185358 ldr r3, [r4, r3] */
/* @0x18535c ldr r2, [r4, r2] */
/* @0x185360 ldr r1, [r6] */
/* @0x185364 ldr r3, [r3] */
/* @0x185368 bl 0x185188 <_ZN8Graphics11DrawArrayExE9ePrimTypeiPvi> */
/* @0x18536c ldr r2, [pc, #0x94] */
/* @0x185370 mov r3, #0 */
/* @0x185374 mvn r1, #0 */
/* @0x185378 str r3, [r6] */
/* @0x18537c str r1, [r5] */
/* @0x185380 ldr r1, [pc, #0x84] */
/* @0x185384 ldr r0, [r4, r2] */
/* @0x185388 ldr r2, [pc, #0x80] */
/* @0x18538c str r3, [r0] */
/* @0x185390 ldr r3, [r4, r1] */
/* @0x185394 ldr r1, [r3] */
/* @0x185398 add r1, r1, #1 */
/* @0x18539c str r1, [r3] */
/* @0x1853a0 ldr r0, [r4, r2] */
/* @0x1853a4 bl 0x168134 <_ZN18RenderStateManager5FlushEv> */
/* @0x1853a8 ldr r3, [pc, #0x64] */
/* @0x1853ac ldr r3, [r4, r3] */
/* @0x1853b0 ldr r3, [r3] */
/* @0x1853b4 cmp r3, #1 */
/* @0x1853b8 popne {r4, r5, r6, pc} */
/* @0x1853bc pop {r4, r5, r6, lr} */
/* @0x1853c0 b 0x18805c <_Z13Shader_Commitv> */
/* @0x1853c4 ldr r3, [pc, #0x44] */
/* @0x1853c8 ldr r0, [r4, r3] */
/* @0x1853cc bl 0x168134 <_ZN18RenderStateManager5FlushEv> */
/* @0x1853d0 ldr r3, [pc, #0x3c] */
/* @0x1853d4 ldr r3, [r4, r3] */
/* @0x1853d8 ldr r3, [r3] */
/* @0x1853dc cmp r3, #1 */
/* @0x1853e0 popne {r4, r5, r6, pc} */
/* @0x1853e4 b 0x1853bc <_ZN8Graphics5FlushEv+0xd0> */
/* @0x1853e8 eoreq r12, r6, r8, asr r9 */
/* @0x1853ec .word 0xffffe948 */
/* @0x1853f0 .word 0xffffe94c */
/* @0x1853f4 .word 0xffffe95c */
/* @0x1853f8 .word 0xffffe4d4 */
/* @0x1853fc .word 0xffffe8f8 */
/* @0x185400 .word 0xffffe960 */
/* @0x185404 .word 0xffffe958 */
/* @0x185408 .word 0xffffe950 */
/* @0x18540c .word 0xffffe744 */
/* @0x185410 .word 0xffffc0a8 */
/* @0x185414 .word 0xffffe7b8 */

/* ── FUNC 0x185418 · Graphics::AllocVerts(ePrimType, void*, int, int) · size=488 · insn=122 */
/* @0x185418 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18541c mov r11, r0 */
/* @0x185420 ldr r6, [pc, #0x1a8] */
/* @0x185424 mov r9, r3 */
/* @0x185428 ldr r0, [pc, #0x1a4] */
/* @0x18542c sub sp, sp, #12 */
/* @0x185430 add r6, pc, r6 */
/* @0x185434 mov r10, r2 */
/* @0x185438 ldr r7, [r6, r0] */
/* @0x18543c ldr r3, [r7] */
/* @0x185440 cmp r11, r3 */
/* @0x185444 ldr r3, [pc, #0x18c] */
/* @0x185448 beq 0x1854e4 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0xcc> */
/* @0x18544c ldr r2, [pc, #0x188] */
/* @0x185450 ldr r0, [pc, #0x188] */
/* @0x185454 ldr r5, [r6, r3] */
/* @0x185458 ldr r4, [r6, r2] */
/* @0x18545c ldr r8, [r6, r0] */
/* @0x185460 str r1, [sp, #0x4] */
/* @0x185464 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x185468 ldr r1, [sp, #0x4] */
/* @0x18546c tst r10, #16777216 */
/* @0x185470 str r11, [r7] */
/* @0x185474 str r10, [r4] */
/* @0x185478 str r1, [r5] */
/* @0x18547c bne 0x185508 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0xf0> */
/* @0x185480 ldr r3, [pc, #0x15c] */
/* @0x185484 ldr r4, [r6, r3] */
/* @0x185488 str r10, [r4] */
/* @0x18548c bl 0x185218 <_Z19JoinToPreviousStripv> */
/* @0x185490 ldr r3, [r7] */
/* @0x185494 cmp r3, #5 */
/* @0x185498 ldr r3, [r8] */
/* @0x18549c beq 0x1854c0 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0xa8> */
/* @0x1854a0 ldr r2, [pc, #0x140] */
/* @0x1854a4 add r9, r9, r3 */
/* @0x1854a8 ldr r0, [r4] */
/* @0x1854ac ldr r2, [r6, r2] */
/* @0x1854b0 str r9, [r8] */
/* @0x1854b4 mla r0, r0, r3, r2 */
/* @0x1854b8 add sp, sp, #12 */
/* @0x1854bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1854c0 cmp r3, #0 */
/* @0x1854c4 ble 0x1854a0 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x88> */
/* @0x1854c8 ldr r2, [pc, #0x11c] */
/* @0x1854cc tst r3, #1 */
/* @0x1854d0 ldr r2, [r6, r2] */
/* @0x1854d4 str r3, [r2] */
/* @0x1854d8 addne r3, r3, #3 */
/* @0x1854dc addeq r3, r3, #2 */
/* @0x1854e0 b 0x1854a0 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x88> */
/* @0x1854e4 ldr r5, [r6, r3] */
/* @0x1854e8 ldr r2, [r5] */
/* @0x1854ec cmp r1, r2 */
/* @0x1854f0 ldr r2, [pc, #0xe4] */
/* @0x1854f4 beq 0x185548 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x130> */
/* @0x1854f8 ldr r0, [pc, #0xe0] */
/* @0x1854fc ldr r4, [r6, r2] */
/* @0x185500 ldr r8, [r6, r0] */
/* @0x185504 b 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48> */
/* @0x185508 mov r0, r10 */
/* @0x18550c bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0x185510 cmp r0, #0 */
/* @0x185514 ldrne r10, [r0, #0x14] */
/* @0x185518 bne 0x185480 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x68> */
/* @0x18551c ldr r3, [pc, #0xcc] */
/* @0x185520 mov r2, r10 */
/* @0x185524 ldr r1, [pc, #0xc8] */
/* @0x185528 mov r10, #1 */
/* @0x18552c ldr r3, [r6, r3] */
/* @0x185530 add r1, pc, r1 */
/* @0x185534 ldr r0, [r3] */
/* @0x185538 ldr r3, [r0] */
/* @0x18553c ldr r3, [r3, #0xc] */
/* @0x185540 blx r3 */
/* @0x185544 b 0x185480 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x68> */
/* @0x185548 ldr r4, [r6, r2] */
/* @0x18554c ldr r0, [r4] */
/* @0x185550 cmp r10, r0 */
/* @0x185554 beq 0x185564 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x14c> */
/* @0x185558 ldr r0, [pc, #0x80] */
/* @0x18555c ldr r8, [r6, r0] */
/* @0x185560 b 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48> */
/* @0x185564 cmp r11, #6 */
/* @0x185568 beq 0x185558 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x140> */
/* @0x18556c cmp r11, #3 */
/* @0x185570 beq 0x185558 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x140> */
/* @0x185574 ldr r12, [pc, #0x64] */
/* @0x185578 movw r0, #0x3ffd */
/* @0x18557c ldr r8, [r6, r12] */
/* @0x185580 ldr r12, [r8] */
/* @0x185584 add r12, r9, r12 */
/* @0x185588 cmp r12, r0 */
/* @0x18558c bgt 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48> */
/* @0x185590 ldr r0, [pc, #0x60] */
/* @0x185594 ldr r0, [r6, r0] */
/* @0x185598 ldrd r2, r3, [r0] */
/* @0x18559c orrs r12, r2, r3 */
/* @0x1855a0 bne 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48> */
/* @0x1855a4 ldrd r2, r3, [r0, #8] */
/* @0x1855a8 orrs r0, r2, r3 */
/* @0x1855ac bne 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48> */
/* @0x1855b0 ldr r0, [pc, #0x44] */
/* @0x1855b4 ldr r0, [r6, r0] */
/* @0x1855b8 ldrb r0, [r0] */
/* @0x1855bc cmp r0, #0 */
/* @0x1855c0 bne 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48> */
/* @0x1855c4 ldr r3, [pc, #0x18] */
/* @0x1855c8 ldr r4, [r6, r3] */
/* @0x1855cc b 0x18548c <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x74> */
/* @0x1855d0 eoreq r12, r6, r0, lsr #16 */
/* @0x1855d4 .word 0xffffe948 */
/* @0x1855d8 .word 0xffffe8f8 */
/* @0x1855dc .word 0xffffe960 */
/* @0x1855e0 .word 0xffffe94c */
/* @0x1855e4 .word 0xffffe954 */
/* @0x1855e8 .word 0xffffe958 */
/* @0x1855ec .word 0xffffe950 */
/* @0x1855f0 .word 0xffffbac4 */
/* @0x1855f4 andseq r6, r12, r12, asr #12 */
/* @0x1855f8 .word 0xffffc0a8 */
/* @0x1855fc .word 0xffffe964 */

/* ── FUNC 0x185600 · Graphics::FreeVerts(int) · size=28 · insn=7 */
/* @0x185600 ldr r3, [pc, #0x10] */
/* @0x185604 ldr r3, [pc, r3] */
/* @0x185608 ldr r2, [r3] */
/* @0x18560c rsb r0, r0, r2 */
/* @0x185610 str r0, [r3] */
/* @0x185614 bx lr */
/* @0x185618 mlaeq r6, r8, pc, r10 */

/* ── FUNC 0x18561c · Graphics::GetMaxDynamicVertexCount() · size=8 · insn=2 */
/* @0x18561c mov r0, #16384 */
/* @0x185620 bx lr */

/* ── FUNC 0x185624 · Graphics::GetMaxDynamicVertexSpace() · size=20 · insn=5 */
/* @0x185624 push {r3, lr} */
/* @0x185628 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x18562c add r0, r0, r0, lsl #3 */
/* @0x185630 lsl r0, r0, #2 */
/* @0x185634 pop {r3, pc} */

/* ── FUNC 0x185638 · Graphics::IsSupportedNativePrimtype(ePrimType) · size=8 · insn=2 */
/* @0x185638 mov r0, #1 */
/* @0x18563c bx lr */

/* ── FUNC 0x185640 · FreeVertexFormat(VertexFormat*) · size=28 · insn=7 */
/* @0x185640 push {r4, lr} */
/* @0x185644 mov r4, r0 */
/* @0x185648 ldr r0, [r0, #0xc] */
/* @0x18564c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x185650 mov r3, #0 */
/* @0x185654 str r3, [r4, #0xc] */
/* @0x185658 pop {r4, pc} */

/* ── FUNC 0x18565c · CreateNativeVertexFormat(VertexFormat*) · size=212 · insn=53 */
/* @0x18565c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x185660 subs r6, r0, #0 */
/* @0x185664 sub sp, sp, #68 */
/* @0x185668 beq 0x185720 <_Z24CreateNativeVertexFormatP12VertexFormat+0xc4> */
/* @0x18566c mov r1, #0 */
/* @0x185670 mov r2, #60 */
/* @0x185674 add r0, sp, #4 */
/* @0x185678 bl 0xb65b0 <memset@plt> */
/* @0x18567c ldr r0, [r6, #0x4] */
/* @0x185680 ldr r1, [pc, #0xa0] */
/* @0x185684 mov r2, #70 */
/* @0x185688 mov r3, #1 */
/* @0x18568c add r1, pc, r1 */
/* @0x185690 lsl r0, r0, #4 */
/* @0x185694 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x185698 ldr r8, [r6, #0x4] */
/* @0x18569c cmp r8, #0 */
/* @0x1856a0 ble 0x18571c <_Z24CreateNativeVertexFormatP12VertexFormat+0xc0> */
/* @0x1856a4 ldr r2, [r6, #0x8] */
/* @0x1856a8 mov r3, r0 */
/* @0x1856ac ldr r7, [pc, #0x78] */
/* @0x1856b0 add r8, r2, r8, lsl #4 */
/* @0x1856b4 add r7, pc, r7 */
/* @0x1856b8 ldr r1, [r2, #0x4] */
/* @0x1856bc movw r12, #0x1406 */
/* @0x1856c0 mov r5, #4 */
/* @0x1856c4 mov r4, #0 */
/* @0x1856c8 sub r1, r1, #1 */
/* @0x1856cc add r2, r2, #16 */
/* @0x1856d0 cmp r1, #5 */
/* @0x1856d4 add r9, r7, r1 */
/* @0x1856d8 add r1, r7, r1, lsl #2 */
/* @0x1856dc add r3, r3, #16 */
/* @0x1856e0 ldrbls r4, [r9, #0x78] */
/* @0x1856e4 ldrls r12, [r1, #0x48] */
/* @0x1856e8 ldrls r5, [r1, #0x60] */
/* @0x1856ec add r1, sp, #64 */
/* @0x1856f0 str r12, [r3, #-0x10] */
/* @0x1856f4 ldr r12, [r2, #-0x8] */
/* @0x1856f8 cmp r2, r8 */
/* @0x1856fc strb r4, [r3, #-0x8] */
/* @0x185700 str r5, [r3, #-0xc] */
/* @0x185704 add r12, r1, r12, lsl #2 */
/* @0x185708 ldr r1, [r12, #-0x3c] */
/* @0x18570c add r4, r1, #1 */
/* @0x185710 str r4, [r12, #-0x3c] */
/* @0x185714 str r1, [r3, #-0x4] */
/* @0x185718 bne 0x1856b8 <_Z24CreateNativeVertexFormatP12VertexFormat+0x5c> */
/* @0x18571c str r0, [r6, #0xc] */
/* @0x185720 add sp, sp, #68 */
/* @0x185724 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x185728 andseq r11, r10, r4, lsr #19 */
/* @0x18572c andseq r8, sp, r8, lsr #10 */

/* ── FUNC 0x185730 · Graphics::DrawArrayFromVB(ePrimType, int, int, int, void*, VertexBuffer*) · size=164 · insn=41 */
/* @0x185730 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x185734 sub sp, sp, #12 */
/* @0x185738 mov r8, r0 */
/* @0x18573c mov r6, r1 */
/* @0x185740 ldr r4, [sp, #0x2c] */
/* @0x185744 mov r9, r3 */
/* @0x185748 ldr r7, [sp, #0x28] */
/* @0x18574c cmp r4, #0 */
/* @0x185750 beq 0x1857c4 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer+0x94> */
/* @0x185754 cmp r1, #0 */
/* @0x185758 ble 0x1857c4 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer+0x94> */
/* @0x18575c ldr r3, [r4, #0xc] */
/* @0x185760 cmp r3, #0 */
/* @0x185764 beq 0x1857c4 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer+0x94> */
/* @0x185768 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x18576c ldr r2, [pc, #0x58] */
/* @0x185770 mov r1, r7 */
/* @0x185774 ldr r5, [pc, #0x54] */
/* @0x185778 ldr r2, [pc, r2] */
/* @0x18577c ldr r0, [r2] */
/* @0x185780 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x185784 ldr r3, [r4, #0xc] */
/* @0x185788 ldr r5, [pc, r5] */
/* @0x18578c movw r0, #0x8892 */
/* @0x185790 ldr r1, [r3] */
/* @0x185794 ldr r3, [r5] */
/* @0x185798 blx r3 */
/* @0x18579c mov r0, r8 */
/* @0x1857a0 mov r1, r6 */
/* @0x1857a4 mov r3, r9 */
/* @0x1857a8 str r7, [sp] */
/* @0x1857ac mov r2, #0 */
/* @0x1857b0 bl 0x184868 <_Z10_DrawArray9ePrimTypeiPviS0_> */
/* @0x1857b4 ldr r3, [r5] */
/* @0x1857b8 movw r0, #0x8892 */
/* @0x1857bc mov r1, #0 */
/* @0x1857c0 blx r3 */
/* @0x1857c4 add sp, sp, #12 */
/* @0x1857c8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1857cc eoreq r10, r6, r12, lsr #19 */
/* @0x1857d0 eoreq r8, r6, r4 */

/* ── FUNC 0x1857d4 · FreeAllVertexData() · size=4 · insn=1 */
/* @0x1857d4 bx lr */

/* ── FUNC 0x1857d8 · GraphicsRecorder::DeleteHWBuffers() · size=132 · insn=33 */
/* @0x1857d8 ldr r3, [pc, #0x74] */
/* @0x1857dc push {r4, r5, r6, r7, r8, lr} */
/* @0x1857e0 ldr r3, [pc, r3] */
/* @0x1857e4 mov r8, r0 */
/* @0x1857e8 ldrb r3, [r3] */
/* @0x1857ec cmp r3, #0 */
/* @0x1857f0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1857f4 ldr r5, [r0, #0x18] */
/* @0x1857f8 cmp r5, #0 */
/* @0x1857fc popeq {r4, r5, r6, r7, r8, pc} */
/* @0x185800 ldr r7, [r5, #0x4] */
/* @0x185804 cmp r7, #0 */
/* @0x185808 ble 0x185838 <_ZN16GraphicsRecorder15DeleteHWBuffersEv+0x60> */
/* @0x18580c ldr r6, [pc, #0x44] */
/* @0x185810 mov r4, #0 */
/* @0x185814 ldr r6, [pc, r6] */
/* @0x185818 ldr r1, [r5] */
/* @0x18581c mov r0, #1 */
/* @0x185820 ldr r3, [r6] */
/* @0x185824 add r1, r1, r4, lsl #3 */
/* @0x185828 add r4, r4, r0 */
/* @0x18582c blx r3 */
/* @0x185830 cmp r4, r7 */
/* @0x185834 bne 0x185818 <_ZN16GraphicsRecorder15DeleteHWBuffersEv+0x40> */
/* @0x185838 ldr r0, [r5] */
/* @0x18583c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x185840 ldr r0, [r8, #0x18] */
/* @0x185844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x185848 mov r3, #0 */
/* @0x18584c str r3, [r8, #0x18] */
/* @0x185850 pop {r4, r5, r6, r7, r8, pc} */
/* @0x185854 eoreq r10, r6, r0, asr r12 */
/* @0x185858 eoreq r7, r6, r0, ror pc */

/* ── FUNC 0x18585c · CreateVertexBuffer(void*, int) · size=456 · insn=114 */
/* @0x18585c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x185860 sub sp, sp, #36 */
/* @0x185864 mov r2, #70 */
/* @0x185868 mov r3, #1 */
/* @0x18586c str r1, [sp, #0x4] */
/* @0x185870 ldr r1, [pc, #0x190] */
/* @0x185874 str r0, [sp, #0x10] */
/* @0x185878 mov r0, #12 */
/* @0x18587c add r1, pc, r1 */
/* @0x185880 ldr r5, [pc, #0x184] */
/* @0x185884 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x185888 ldr r9, [sp, #0x4] */
/* @0x18588c movw r3, #0xe035 */
/* @0x185890 movt r3, #0x8637 */
/* @0x185894 ldr r12, [sp, #0x4] */
/* @0x185898 add r5, pc, r5 */
/* @0x18589c asr r1, r9, #31 */
/* @0x1858a0 ldr r2, [pc, #0x168] */
/* @0x1858a4 smull r9, r8, r3, r9 */
/* @0x1858a8 movw r3, #0xa11e */
/* @0x1858ac movt r3, #0x7 */
/* @0x1858b0 add r8, r8, r12 */
/* @0x1858b4 rsb r1, r1, r8, asr #18 */
/* @0x1858b8 mls r3, r3, r1, r12 */
/* @0x1858bc cmp r3, #0 */
/* @0x1858c0 mov r3, #1 */
/* @0x1858c4 str r0, [sp, #0x8] */
/* @0x1858c8 ldr r2, [r5, r2] */
/* @0x1858cc str r1, [sp] */
/* @0x1858d0 addgt r1, r1, #1 */
/* @0x1858d4 ldr r12, [sp, #0x8] */
/* @0x1858d8 strgt r1, [sp] */
/* @0x1858dc ldr r2, [r2] */
/* @0x1858e0 ldr r9, [sp] */
/* @0x1858e4 ldr r1, [pc, #0x128] */
/* @0x1858e8 str r2, [r0, #0x8] */
/* @0x1858ec mov r2, #70 */
/* @0x1858f0 str r9, [r12, #0x4] */
/* @0x1858f4 lsl r0, r9, #3 */
/* @0x1858f8 add r1, pc, r1 */
/* @0x1858fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x185900 cmp r9, #0 */
/* @0x185904 ldr r9, [sp, #0x8] */
/* @0x185908 str r0, [r9] */
/* @0x18590c ble 0x1859fc <_Z18CreateVertexBufferPvi+0x1a0> */
/* @0x185910 ldr r1, [pc, #0x100] */
/* @0x185914 movw r12, #0xa11d */
/* @0x185918 ldr r2, [pc, #0xfc] */
/* @0x18591c movt r12, #0x7 */
/* @0x185920 ldr r3, [pc, #0xf8] */
/* @0x185924 add r9, sp, #28 */
/* @0x185928 str r12, [sp, #0xc] */
/* @0x18592c mov r6, r0 */
/* @0x185930 str r9, [sp, #0x14] */
/* @0x185934 ldr r4, [sp, #0x4] */
/* @0x185938 ldr r11, [r5, r1] */
/* @0x18593c ldr r7, [r5, r2] */
/* @0x185940 ldr r10, [r5, r3] */
/* @0x185944 mov r5, #0 */
/* @0x185948 b 0x185954 <_Z18CreateVertexBufferPvi+0xf8> */
/* @0x18594c ldr r9, [sp, #0x8] */
/* @0x185950 ldr r6, [r9] */
/* @0x185954 ldr r3, [r11] */
/* @0x185958 mov r0, #1 */
/* @0x18595c add r1, sp, #28 */
/* @0x185960 movw r9, #0x5ee2 */
/* @0x185964 blx r3 */
/* @0x185968 ldr r3, [r7] */
/* @0x18596c movw r0, #0x8892 */
/* @0x185970 ldr r1, [sp, #0x1c] */
/* @0x185974 blx r3 */
/* @0x185978 ldr r12, [sp, #0xc] */
/* @0x18597c movt r9, #0xfff8 */
/* @0x185980 mov r8, r4 */
/* @0x185984 cmp r4, r12 */
/* @0x185988 ldr r12, [sp, #0x4] */
/* @0x18598c add r9, r4, r9 */
/* @0x185990 add r1, r4, r4, lsl #3 */
/* @0x185994 rsb r4, r4, r12 */
/* @0x185998 movle r9, #0 */
/* @0x18599c lsl r1, r1, #2 */
/* @0x1859a0 ldr r12, [r10] */
/* @0x1859a4 add lr, r4, r4, lsl #3 */
/* @0x1859a8 mov r4, r9 */
/* @0x1859ac ldr r9, [sp, #0x10] */
/* @0x1859b0 movwgt r1, #0xa838 */
/* @0x1859b4 movw r0, #0x8892 */
/* @0x1859b8 movtgt r1, #0x112 */
/* @0x1859bc movw r3, #0x88e4 */
/* @0x1859c0 add r2, r9, lr, lsl #2 */
/* @0x1859c4 movwgt r8, #0xa11e */
/* @0x1859c8 movtgt r8, #0x7 */
/* @0x1859cc blx r12 */
/* @0x1859d0 ldr r3, [r7] */
/* @0x1859d4 movw r0, #0x8892 */
/* @0x1859d8 mov r1, #0 */
/* @0x1859dc blx r3 */
/* @0x1859e0 ldr r12, [sp] */
/* @0x1859e4 add r6, r6, r5, lsl #3 */
/* @0x1859e8 ldr r3, [sp, #0x1c] */
/* @0x1859ec add r5, r5, #1 */
/* @0x1859f0 cmp r5, r12 */
/* @0x1859f4 stm r6, {r3, r8} */
/* @0x1859f8 bne 0x18594c <_Z18CreateVertexBufferPvi+0xf0> */
/* @0x1859fc ldr r0, [sp, #0x8] */
/* @0x185a00 add sp, sp, #36 */
/* @0x185a04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x185a08 ldrheq r11, [r10], -r4 */
/* @0x185a0c .word 0x0026c3b8 */
/* @0x185a10 .word 0xffffe90c */
/* @0x185a14 andseq r11, r10, r8, lsr r7 */
/* @0x185a18 .word 0xffffbb38 */
/* @0x185a1c .word 0xffffbb3c */
/* @0x185a20 .word 0xffffbb40 */

/* ── FUNC 0x185a24 · GraphicsRecorder::Draw(float, float, float) · size=2424 · insn=606 */
/* @0x185a24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x185a28 sub sp, sp, #228 */
/* @0x185a2c add r5, sp, #32 */
/* @0x185a30 mov r7, r1 */
/* @0x185a34 str r5, [sp, #0x10] */
/* @0x185a38 mov r4, r0 */
/* @0x185a3c mov r1, r5 */
/* @0x185a40 add r5, sp, #160 */
/* @0x185a44 mov r0, #2 */
/* @0x185a48 mov r8, r3 */
/* @0x185a4c mov r6, r2 */
/* @0x185a50 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x185a54 add r2, sp, #32 */
/* @0x185a58 mov r0, r5 */
/* @0x185a5c add r1, sp, #96 */
/* @0x185a60 mov r12, #0 */
/* @0x185a64 mov lr, #1065353216 */
/* @0x185a68 str r12, [sp, #0x8c] */
/* @0x185a6c str r12, [sp, #0x84] */
/* @0x185a70 str r12, [sp, #0x80] */
/* @0x185a74 str r12, [sp, #0x7c] */
/* @0x185a78 str r12, [sp, #0x78] */
/* @0x185a7c str lr, [sp, #0x9c] */
/* @0x185a80 str lr, [sp, #0x88] */
/* @0x185a84 str lr, [sp, #0x74] */
/* @0x185a88 str lr, [sp, #0x60] */
/* @0x185a8c str r12, [sp, #0x70] */
/* @0x185a90 str r12, [sp, #0x6c] */
/* @0x185a94 str r12, [sp, #0x68] */
/* @0x185a98 str r12, [sp, #0x64] */
/* @0x185a9c str r7, [sp, #0x90] */
/* @0x185aa0 str r6, [sp, #0x94] */
/* @0x185aa4 str r8, [sp, #0x98] */
/* @0x185aa8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x185aac mov r1, r5 */
/* @0x185ab0 mov r0, #2 */
/* @0x185ab4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x185ab8 ldr r5, [pc, #0x8a4] */
/* @0x185abc bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x185ac0 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x185ac4 add r5, pc, r5 */
/* @0x185ac8 str r0, [sp, #0x14] */
/* @0x185acc mov r0, #1 */
/* @0x185ad0 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x185ad4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x185ad8 ldr r1, [r4, #0x14] */
/* @0x185adc cmp r1, #0 */
/* @0x185ae0 beq 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130> */
/* @0x185ae4 ldr r3, [pc, #0x87c] */
/* @0x185ae8 ldr r3, [r5, r3] */
/* @0x185aec ldrb r3, [r3] */
/* @0x185af0 cmp r3, #0 */
/* @0x185af4 beq 0x185c5c <_ZN16GraphicsRecorder4DrawEfff+0x238> */
/* @0x185af8 ldr r3, [r4, #0x18] */
/* @0x185afc cmp r3, #0 */
/* @0x185b00 beq 0x1862d4 <_ZN16GraphicsRecorder4DrawEfff+0x8b0> */
/* @0x185b04 ldr r1, [pc, #0x860] */
/* @0x185b08 ldr r2, [r3, #0x8] */
/* @0x185b0c ldr r3, [r5, r1] */
/* @0x185b10 ldr r3, [r3] */
/* @0x185b14 cmp r2, r3 */
/* @0x185b18 beq 0x185b30 <_ZN16GraphicsRecorder4DrawEfff+0x10c> */
/* @0x185b1c mov r0, r4 */
/* @0x185b20 bl 0x1857d8 <_ZN16GraphicsRecorder15DeleteHWBuffersEv> */
/* @0x185b24 ldr r3, [r4, #0x18] */
/* @0x185b28 cmp r3, #0 */
/* @0x185b2c beq 0x1862d0 <_ZN16GraphicsRecorder4DrawEfff+0x8ac> */
/* @0x185b30 ldr r3, [pc, #0x838] */
/* @0x185b34 ldr r3, [r5, r3] */
/* @0x185b38 str r3, [sp, #0x8] */
/* @0x185b3c ldr r3, [r3] */
/* @0x185b40 cmp r3, #1 */
/* @0x185b44 movne r6, r3 */
/* @0x185b48 beq 0x185fd4 <_ZN16GraphicsRecorder4DrawEfff+0x5b0> */
/* @0x185b4c cmp r6, #0 */
/* @0x185b50 beq 0x185e28 <_ZN16GraphicsRecorder4DrawEfff+0x404> */
/* @0x185b54 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x185b58 ldr r3, [r4, #0x24] */
/* @0x185b5c cmp r3, #0 */
/* @0x185b60 mov r7, r0 */
/* @0x185b64 beq 0x185bd4 <_ZN16GraphicsRecorder4DrawEfff+0x1b0> */
/* @0x185b68 ldr r5, [r4, #0x2c] */
/* @0x185b6c cmp r5, #0 */
/* @0x185b70 ble 0x185bd4 <_ZN16GraphicsRecorder4DrawEfff+0x1b0> */
/* @0x185b74 cmp r5, r7 */
/* @0x185b78 movlt r3, r5 */
/* @0x185b7c movge r3, r7 */
/* @0x185b80 ldr r1, [r4, #0x10] */
/* @0x185b84 mov r2, #36 */
/* @0x185b88 mov r0, #2 */
/* @0x185b8c lsr r12, r3, #31 */
/* @0x185b90 add r6, r3, r12 */
/* @0x185b94 and r6, r6, #1 */
/* @0x185b98 rsb r6, r12, r6 */
/* @0x185b9c rsb r6, r6, r3 */
/* @0x185ba0 mov r3, r6 */
/* @0x185ba4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x185ba8 ldr r3, [r4, #0x2c] */
/* @0x185bac ldr r1, [r4, #0x24] */
/* @0x185bb0 add r2, r6, r6, lsl #3 */
/* @0x185bb4 rsb r3, r5, r3 */
/* @0x185bb8 rsb r5, r6, r5 */
/* @0x185bbc lsl r2, r2, #2 */
/* @0x185bc0 add r3, r3, r3, lsl #3 */
/* @0x185bc4 add r1, r1, r3, lsl #2 */
/* @0x185bc8 bl 0xb65bc <memcpy@plt> */
/* @0x185bcc cmp r5, #0 */
/* @0x185bd0 bgt 0x185b74 <_ZN16GraphicsRecorder4DrawEfff+0x150> */
/* @0x185bd4 ldr r3, [r4, #0x34] */
/* @0x185bd8 cmp r3, #0 */
/* @0x185bdc beq 0x185c38 <_ZN16GraphicsRecorder4DrawEfff+0x214> */
/* @0x185be0 ldr r5, [r4, #0x3c] */
/* @0x185be4 cmp r5, #0 */
/* @0x185be8 ble 0x185c38 <_ZN16GraphicsRecorder4DrawEfff+0x214> */
/* @0x185bec cmp r5, r7 */
/* @0x185bf0 movlt r6, r5 */
/* @0x185bf4 movge r6, r7 */
/* @0x185bf8 ldr r1, [r4, #0x10] */
/* @0x185bfc mov r2, #36 */
/* @0x185c00 mov r0, #1 */
/* @0x185c04 mov r3, r6 */
/* @0x185c08 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x185c0c ldr r3, [r4, #0x3c] */
/* @0x185c10 ldr r1, [r4, #0x34] */
/* @0x185c14 add r2, r6, r6, lsl #3 */
/* @0x185c18 rsb r3, r5, r3 */
/* @0x185c1c rsb r5, r6, r5 */
/* @0x185c20 lsl r2, r2, #2 */
/* @0x185c24 add r3, r3, r3, lsl #3 */
/* @0x185c28 add r1, r1, r3, lsl #2 */
/* @0x185c2c bl 0xb65bc <memcpy@plt> */
/* @0x185c30 cmp r5, #0 */
/* @0x185c34 bgt 0x185bec <_ZN16GraphicsRecorder4DrawEfff+0x1c8> */
/* @0x185c38 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x185c3c ldr r0, [sp, #0x14] */
/* @0x185c40 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x185c44 add r1, sp, #32 */
/* @0x185c48 mov r0, #2 */
/* @0x185c4c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x185c50 bl 0x168d7c <_Z16DirtyRoomExtentsv> */
/* @0x185c54 add sp, sp, #228 */
/* @0x185c58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x185c5c ldr r3, [pc, #0x70c] */
/* @0x185c60 ldr r3, [r5, r3] */
/* @0x185c64 str r3, [sp, #0x8] */
/* @0x185c68 ldr r3, [r3] */
/* @0x185c6c cmp r3, #1 */
/* @0x185c70 movne r6, r3 */
/* @0x185c74 beq 0x186150 <_ZN16GraphicsRecorder4DrawEfff+0x72c> */
/* @0x185c78 cmp r6, #0 */
/* @0x185c7c bne 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130> */
/* @0x185c80 ldr r3, [pc, #0x6ec] */
/* @0x185c84 movw r0, #0x8074 */
/* @0x185c88 ldr r7, [r5, r3] */
/* @0x185c8c ldr r3, [r7] */
/* @0x185c90 blx r3 */
/* @0x185c94 ldr r3, [r7] */
/* @0x185c98 movw r0, #0x8075 */
/* @0x185c9c blx r3 */
/* @0x185ca0 ldr r3, [r7] */
/* @0x185ca4 movw r0, #0x8076 */
/* @0x185ca8 blx r3 */
/* @0x185cac ldr r1, [r4, #0x10] */
/* @0x185cb0 ldr r3, [pc, #0x6c0] */
/* @0x185cb4 cmp r1, #0 */
/* @0x185cb8 beq 0x18632c <_ZN16GraphicsRecorder4DrawEfff+0x908> */
/* @0x185cbc ldr r3, [r5, r3] */
/* @0x185cc0 ldr r0, [r3] */
/* @0x185cc4 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x185cc8 ldr r3, [r7] */
/* @0x185ccc movw r0, #0x8078 */
/* @0x185cd0 blx r3 */
/* @0x185cd4 ldr r3, [pc, #0x6a0] */
/* @0x185cd8 ldr r3, [r5, r3] */
/* @0x185cdc str r3, [sp, #0x1c] */
/* @0x185ce0 ldr r6, [r4, #0x1c] */
/* @0x185ce4 cmp r6, #0 */
/* @0x185ce8 ble 0x185df0 <_ZN16GraphicsRecorder4DrawEfff+0x3cc> */
/* @0x185cec ldr r0, [pc, #0x68c] */
/* @0x185cf0 movw lr, #0x5556 */
/* @0x185cf4 ldr r12, [pc, #0x688] */
/* @0x185cf8 movt lr, #0x5555 */
/* @0x185cfc ldr r1, [pc, #0x684] */
/* @0x185d00 mov r3, r6 */
/* @0x185d04 str lr, [sp, #0xc] */
/* @0x185d08 ldr r2, [pc, #0x67c] */
/* @0x185d0c ldr r0, [r5, r0] */
/* @0x185d10 ldr r11, [r5, r12] */
/* @0x185d14 mov r8, r0 */
/* @0x185d18 str r0, [sp, #0x8] */
/* @0x185d1c ldr r10, [r5, r1] */
/* @0x185d20 ldr r9, [r5, r2] */
/* @0x185d24 str r5, [sp, #0x18] */
/* @0x185d28 b 0x185d30 <_ZN16GraphicsRecorder4DrawEfff+0x30c> */
/* @0x185d2c ldr r3, [r4, #0x1c] */
/* @0x185d30 ldr r5, [sp, #0xc] */
/* @0x185d34 movw r12, #0xffff */
/* @0x185d38 cmp r12, r6 */
/* @0x185d3c movge r12, r6 */
/* @0x185d40 rsb r3, r6, r3 */
/* @0x185d44 ldr r2, [r4, #0x14] */
/* @0x185d48 mov r0, #3 */
/* @0x185d4c smull r5, r7, r5, r12 */
/* @0x185d50 add r3, r3, r3, lsl #3 */
/* @0x185d54 movw r1, #0x1406 */
/* @0x185d58 add r5, r2, r3, lsl #2 */
/* @0x185d5c mov r2, #36 */
/* @0x185d60 mov r3, r5 */
/* @0x185d64 sub r7, r7, r12, asr #31 */
/* @0x185d68 ldr r12, [r8] */
/* @0x185d6c blx r12 */
/* @0x185d70 add r2, r5, #12 */
/* @0x185d74 ldr r3, [r10] */
/* @0x185d78 movw r0, #0x1406 */
/* @0x185d7c mov r1, #36 */
/* @0x185d80 add r7, r7, r7, lsl #1 */
/* @0x185d84 blx r3 */
/* @0x185d88 add r3, r5, #24 */
/* @0x185d8c ldr r12, [r9] */
/* @0x185d90 mov r0, #4 */
/* @0x185d94 movw r1, #0x1401 */
/* @0x185d98 mov r2, #36 */
/* @0x185d9c blx r12 */
/* @0x185da0 ldr r12, [r4, #0x10] */
/* @0x185da4 ldr lr, [pc, #0x5e4] */
/* @0x185da8 add r3, r5, #28 */
/* @0x185dac cmp r12, #0 */
/* @0x185db0 mov r0, #2 */
/* @0x185db4 movw r1, #0x1406 */
/* @0x185db8 mov r2, #36 */
/* @0x185dbc rsb r6, r7, r6 */
/* @0x185dc0 beq 0x185dd4 <_ZN16GraphicsRecorder4DrawEfff+0x3b0> */
/* @0x185dc4 ldr r5, [sp, #0x18] */
/* @0x185dc8 ldr r12, [r5, lr] */
/* @0x185dcc ldr r12, [r12] */
/* @0x185dd0 blx r12 */
/* @0x185dd4 mov r2, r7 */
/* @0x185dd8 ldr r3, [r11] */
/* @0x185ddc mov r0, #4 */
/* @0x185de0 mov r1, #0 */
/* @0x185de4 blx r3 */
/* @0x185de8 cmp r6, #0 */
/* @0x185dec bgt 0x185d2c <_ZN16GraphicsRecorder4DrawEfff+0x308> */
/* @0x185df0 ldr r5, [sp, #0x1c] */
/* @0x185df4 movw r0, #0x8074 */
/* @0x185df8 ldr r3, [r5] */
/* @0x185dfc blx r3 */
/* @0x185e00 ldr r3, [r5] */
/* @0x185e04 movw r0, #0x8075 */
/* @0x185e08 blx r3 */
/* @0x185e0c ldr r3, [r5] */
/* @0x185e10 movw r0, #0x8076 */
/* @0x185e14 blx r3 */
/* @0x185e18 ldr r3, [r5] */
/* @0x185e1c movw r0, #0x8078 */
/* @0x185e20 blx r3 */
/* @0x185e24 b 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130> */
/* @0x185e28 ldr r3, [pc, #0x544] */
/* @0x185e2c movw r0, #0x8074 */
/* @0x185e30 ldr r7, [r5, r3] */
/* @0x185e34 ldr r3, [r7] */
/* @0x185e38 blx r3 */
/* @0x185e3c ldr r3, [r7] */
/* @0x185e40 movw r0, #0x8075 */
/* @0x185e44 blx r3 */
/* @0x185e48 ldr r3, [r7] */
/* @0x185e4c movw r0, #0x8076 */
/* @0x185e50 blx r3 */
/* @0x185e54 ldr r1, [r4, #0x10] */
/* @0x185e58 ldr r3, [pc, #0x518] */
/* @0x185e5c cmp r1, #0 */
/* @0x185e60 beq 0x186300 <_ZN16GraphicsRecorder4DrawEfff+0x8dc> */
/* @0x185e64 ldr r3, [r5, r3] */
/* @0x185e68 ldr r0, [r3] */
/* @0x185e6c bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x185e70 ldr r3, [r7] */
/* @0x185e74 movw r0, #0x8078 */
/* @0x185e78 blx r3 */
/* @0x185e7c ldr r3, [pc, #0x4f8] */
/* @0x185e80 ldr r3, [r5, r3] */
/* @0x185e84 str r3, [sp, #0x1c] */
/* @0x185e88 ldr r7, [r4, #0x18] */
/* @0x185e8c cmp r7, #0 */
/* @0x185e90 beq 0x1862c4 <_ZN16GraphicsRecorder4DrawEfff+0x8a0> */
/* @0x185e94 ldr r12, [r7, #0x4] */
/* @0x185e98 cmp r12, #0 */
/* @0x185e9c str r12, [sp, #0xc] */
/* @0x185ea0 ble 0x1862c4 <_ZN16GraphicsRecorder4DrawEfff+0x8a0> */
/* @0x185ea4 ldr r1, [pc, #0x4d4] */
/* @0x185ea8 mov r6, #0 */
/* @0x185eac ldr r12, [pc, #0x4e0] */
/* @0x185eb0 ldr r0, [pc, #0x4cc] */
/* @0x185eb4 ldr r1, [r5, r1] */
/* @0x185eb8 ldr r2, [pc, #0x4c8] */
/* @0x185ebc ldr r3, [pc, #0x4c8] */
/* @0x185ec0 ldr r8, [r5, r12] */
/* @0x185ec4 ldr r11, [r5, r0] */
/* @0x185ec8 str r1, [sp, #0x8] */
/* @0x185ecc ldr r10, [r5, r2] */
/* @0x185ed0 ldr r9, [r5, r3] */
/* @0x185ed4 str r5, [sp, #0x18] */
/* @0x185ed8 ldr r3, [r7] */
/* @0x185edc movw r0, #0x8892 */
/* @0x185ee0 ldr r2, [r8] */
/* @0x185ee4 add r5, r3, r6, lsl #3 */
/* @0x185ee8 ldr r1, [r3, r6, lsl #3] */
/* @0x185eec add r6, r6, #1 */
/* @0x185ef0 blx r2 */
/* @0x185ef4 ldr lr, [sp, #0x8] */
/* @0x185ef8 mov r0, #3 */
/* @0x185efc movw r1, #0x1406 */
/* @0x185f00 mov r2, #36 */
/* @0x185f04 mov r3, #0 */
/* @0x185f08 ldr r12, [lr] */
/* @0x185f0c blx r12 */
/* @0x185f10 ldr r3, [r10] */
/* @0x185f14 movw r0, #0x1406 */
/* @0x185f18 mov r1, #36 */
/* @0x185f1c mov r2, #12 */
/* @0x185f20 blx r3 */
/* @0x185f24 ldr r12, [r9] */
/* @0x185f28 mov r0, #4 */
/* @0x185f2c movw r1, #0x1401 */
/* @0x185f30 mov r2, #36 */
/* @0x185f34 mov r3, #24 */
/* @0x185f38 blx r12 */
/* @0x185f3c ldr r12, [r4, #0x10] */
/* @0x185f40 ldr lr, [pc, #0x448] */
/* @0x185f44 mov r0, #2 */
/* @0x185f48 cmp r12, #0 */
/* @0x185f4c movw r1, #0x1406 */
/* @0x185f50 mov r2, #36 */
/* @0x185f54 mov r3, #28 */
/* @0x185f58 beq 0x185f6c <_ZN16GraphicsRecorder4DrawEfff+0x548> */
/* @0x185f5c ldr r12, [sp, #0x18] */
/* @0x185f60 ldr lr, [r12, lr] */
/* @0x185f64 ldr r12, [lr] */
/* @0x185f68 blx r12 */
/* @0x185f6c ldr r2, [r5, #0x4] */
/* @0x185f70 mov r0, #4 */
/* @0x185f74 ldr r3, [r11] */
/* @0x185f78 mov r1, #0 */
/* @0x185f7c blx r3 */
/* @0x185f80 ldr r5, [sp, #0xc] */
/* @0x185f84 cmp r6, r5 */
/* @0x185f88 bne 0x185ed8 <_ZN16GraphicsRecorder4DrawEfff+0x4b4> */
/* @0x185f8c ldr r5, [sp, #0x1c] */
/* @0x185f90 movw r0, #0x8074 */
/* @0x185f94 ldr r3, [r5] */
/* @0x185f98 blx r3 */
/* @0x185f9c ldr r3, [r5] */
/* @0x185fa0 movw r0, #0x8075 */
/* @0x185fa4 blx r3 */
/* @0x185fa8 ldr r3, [r5] */
/* @0x185fac movw r0, #0x8076 */
/* @0x185fb0 blx r3 */
/* @0x185fb4 ldr r3, [r5] */
/* @0x185fb8 movw r0, #0x8078 */
/* @0x185fbc blx r3 */
/* @0x185fc0 ldr r3, [r8] */
/* @0x185fc4 movw r0, #0x8892 */
/* @0x185fc8 mov r1, #0 */
/* @0x185fcc blx r3 */
/* @0x185fd0 b 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130> */
/* @0x185fd4 mov r0, #36 */
/* @0x185fd8 bl 0x18426c <_Z16StartShaderBlocki> */
/* @0x185fdc ldr r3, [pc, #0x394] */
/* @0x185fe0 ldr r1, [r4, #0x10] */
/* @0x185fe4 ldr r3, [r5, r3] */
/* @0x185fe8 mov r7, r0 */
/* @0x185fec ldr r0, [r3] */
/* @0x185ff0 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x185ff4 ldr r9, [r4, #0x18] */
/* @0x185ff8 cmp r9, #0 */
/* @0x185ffc beq 0x186358 <_ZN16GraphicsRecorder4DrawEfff+0x934> */
/* @0x186000 ldr r12, [r9, #0x4] */
/* @0x186004 cmp r12, #0 */
/* @0x186008 str r12, [sp, #0xc] */
/* @0x18600c ble 0x186358 <_ZN16GraphicsRecorder4DrawEfff+0x934> */
/* @0x186010 ldr r2, [pc, #0x37c] */
/* @0x186014 mov r6, #0 */
/* @0x186018 ldr r3, [pc, #0x364] */
/* @0x18601c mov r10, #36 */
/* @0x186020 ldr r8, [r5, r2] */
/* @0x186024 ldr r11, [r5, r3] */
/* @0x186028 str r4, [sp, #0x1c] */
/* @0x18602c ldr r3, [r9] */
/* @0x186030 movw r0, #0x8892 */
/* @0x186034 ldr r2, [r8] */
/* @0x186038 add r4, r3, r6, lsl #3 */
/* @0x18603c ldr r1, [r3, r6, lsl #3] */
/* @0x186040 add r6, r6, #1 */
/* @0x186044 blx r2 */
/* @0x186048 ldr r0, [r7, #0x1c] */
/* @0x18604c ldr r12, [pc, #0x344] */
/* @0x186050 mov r1, #3 */
/* @0x186054 cmn r0, #1 */
/* @0x186058 movw r2, #0x1406 */
/* @0x18605c mov r3, #0 */
/* @0x186060 beq 0x186078 <_ZN16GraphicsRecorder4DrawEfff+0x654> */
/* @0x186064 ldr r12, [r5, r12] */
/* @0x186068 str r10, [sp] */
/* @0x18606c str r3, [sp, #0x4] */
/* @0x186070 ldr r12, [r12] */
/* @0x186074 blx r12 */
/* @0x186078 ldr r0, [r7, #0x20] */
/* @0x18607c mov r1, #3 */
/* @0x186080 ldr r12, [pc, #0x310] */
/* @0x186084 movw r2, #0x1406 */
/* @0x186088 cmn r0, #1 */
/* @0x18608c mov r3, #0 */
/* @0x186090 beq 0x1860ac <_ZN16GraphicsRecorder4DrawEfff+0x688> */
/* @0x186094 ldr r12, [r5, r12] */
/* @0x186098 mov lr, #12 */
/* @0x18609c str r10, [sp] */
/* @0x1860a0 str lr, [sp, #0x4] */
/* @0x1860a4 ldr r12, [r12] */
/* @0x1860a8 blx r12 */
/* @0x1860ac ldr r0, [r7, #0x28] */
/* @0x1860b0 mov r1, #4 */
/* @0x1860b4 ldr lr, [pc, #0x2dc] */
/* @0x1860b8 movw r2, #0x1401 */
/* @0x1860bc cmn r0, #1 */
/* @0x1860c0 mov r3, #1 */
/* @0x1860c4 mov r12, #24 */
/* @0x1860c8 beq 0x1860dc <_ZN16GraphicsRecorder4DrawEfff+0x6b8> */
/* @0x1860cc ldr lr, [r5, lr] */
/* @0x1860d0 stm sp, {r10, r12} */
/* @0x1860d4 ldr r12, [lr] */
/* @0x1860d8 blx r12 */
/* @0x1860dc ldr r0, [r7, #0x24] */
/* @0x1860e0 mov r12, #28 */
/* @0x1860e4 ldr lr, [pc, #0x2ac] */
/* @0x1860e8 mov r1, #2 */
/* @0x1860ec cmn r0, #1 */
/* @0x1860f0 movw r2, #0x1406 */
/* @0x1860f4 mov r3, #0 */
/* @0x1860f8 beq 0x18610c <_ZN16GraphicsRecorder4DrawEfff+0x6e8> */
/* @0x1860fc ldr lr, [r5, lr] */
/* @0x186100 stm sp, {r10, r12} */
/* @0x186104 ldr r12, [lr] */
/* @0x186108 blx r12 */
/* @0x18610c ldr r2, [r4, #0x4] */
/* @0x186110 mov r0, #4 */
/* @0x186114 ldr r3, [r11] */
/* @0x186118 mov r1, #0 */
/* @0x18611c blx r3 */
/* @0x186120 ldr r12, [sp, #0xc] */
/* @0x186124 cmp r6, r12 */
/* @0x186128 bne 0x18602c <_ZN16GraphicsRecorder4DrawEfff+0x608> */
/* @0x18612c ldr r4, [sp, #0x1c] */
/* @0x186130 bl 0x1847f8 <_Z14EndShaderBlockv> */
/* @0x186134 ldr r3, [r8] */
/* @0x186138 movw r0, #0x8892 */
/* @0x18613c mov r1, #0 */
/* @0x186140 blx r3 */
/* @0x186144 ldr r12, [sp, #0x8] */
/* @0x186148 ldr r6, [r12] */
/* @0x18614c b 0x185b4c <_ZN16GraphicsRecorder4DrawEfff+0x128> */
/* @0x186150 mov r0, #36 */
/* @0x186154 bl 0x18426c <_Z16StartShaderBlocki> */
/* @0x186158 subs r8, r0, #0 */
/* @0x18615c beq 0x185c3c <_ZN16GraphicsRecorder4DrawEfff+0x218> */
/* @0x186160 ldr r3, [pc, #0x210] */
/* @0x186164 ldr r1, [r4, #0x10] */
/* @0x186168 ldr r3, [r5, r3] */
/* @0x18616c ldr r0, [r3] */
/* @0x186170 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x186174 ldr r6, [r4, #0x1c] */
/* @0x186178 cmp r6, #0 */
/* @0x18617c ble 0x1862b4 <_ZN16GraphicsRecorder4DrawEfff+0x890> */
/* @0x186180 ldr r3, [pc, #0x1fc] */
/* @0x186184 movw r12, #0x5556 */
/* @0x186188 mov r7, r6 */
/* @0x18618c movt r12, #0x5555 */
/* @0x186190 mov r10, #36 */
/* @0x186194 str r12, [sp, #0xc] */
/* @0x186198 ldr r11, [r5, r3] */
/* @0x18619c b 0x1861a4 <_ZN16GraphicsRecorder4DrawEfff+0x780> */
/* @0x1861a0 ldr r7, [r4, #0x1c] */
/* @0x1861a4 ldr r0, [sp, #0xc] */
/* @0x1861a8 movw r12, #0xffff */
/* @0x1861ac cmp r12, r6 */
/* @0x1861b0 movge r12, r6 */
/* @0x1861b4 rsb r7, r6, r7 */
/* @0x1861b8 ldr lr, [pc, #0x1d8] */
/* @0x1861bc mov r3, #0 */
/* @0x1861c0 smull r0, r9, r0, r12 */
/* @0x1861c4 add r7, r7, r7, lsl #3 */
/* @0x1861c8 ldr r0, [r4, #0x14] */
/* @0x1861cc mov r1, #3 */
/* @0x1861d0 movw r2, #0x1406 */
/* @0x1861d4 add r7, r0, r7, lsl #2 */
/* @0x1861d8 ldr r0, [r8, #0x1c] */
/* @0x1861dc sub r9, r9, r12, asr #31 */
/* @0x1861e0 cmn r0, #1 */
/* @0x1861e4 add r9, r9, r9, lsl #1 */
/* @0x1861e8 beq 0x186200 <_ZN16GraphicsRecorder4DrawEfff+0x7dc> */
/* @0x1861ec ldr r12, [r5, lr] */
/* @0x1861f0 str r10, [sp] */
/* @0x1861f4 str r7, [sp, #0x4] */
/* @0x1861f8 ldr r12, [r12] */
/* @0x1861fc blx r12 */
/* @0x186200 ldr r0, [r8, #0x20] */
/* @0x186204 mov r3, #0 */
/* @0x186208 ldr lr, [pc, #0x188] */
/* @0x18620c mov r1, #3 */
/* @0x186210 cmn r0, #1 */
/* @0x186214 movw r2, #0x1406 */
/* @0x186218 add r12, r7, #12 */
/* @0x18621c rsb r6, r9, r6 */
/* @0x186220 beq 0x186234 <_ZN16GraphicsRecorder4DrawEfff+0x810> */
/* @0x186224 ldr lr, [r5, lr] */
/* @0x186228 stm sp, {r10, r12} */
/* @0x18622c ldr r12, [lr] */
/* @0x186230 blx r12 */
/* @0x186234 ldr r0, [r8, #0x28] */
/* @0x186238 mov r3, #1 */
/* @0x18623c ldr lr, [pc, #0x154] */
/* @0x186240 add r12, r7, #24 */
/* @0x186244 cmn r0, #1 */
/* @0x186248 mov r1, #4 */
/* @0x18624c movw r2, #0x1401 */
/* @0x186250 beq 0x186264 <_ZN16GraphicsRecorder4DrawEfff+0x840> */
/* @0x186254 ldr lr, [r5, lr] */
/* @0x186258 stm sp, {r10, r12} */
/* @0x18625c ldr r12, [lr] */
/* @0x186260 blx r12 */
/* @0x186264 ldr r0, [r8, #0x24] */
/* @0x186268 add r7, r7, #28 */
/* @0x18626c ldr r12, [pc, #0x124] */
/* @0x186270 mov r3, #0 */
/* @0x186274 cmn r0, #1 */
/* @0x186278 mov r1, #2 */
/* @0x18627c movw r2, #0x1406 */
/* @0x186280 beq 0x186298 <_ZN16GraphicsRecorder4DrawEfff+0x874> */
/* @0x186284 ldr r12, [r5, r12] */
/* @0x186288 str r10, [sp] */
/* @0x18628c str r7, [sp, #0x4] */
/* @0x186290 ldr r12, [r12] */
/* @0x186294 blx r12 */
/* @0x186298 ldr r3, [r11] */
/* @0x18629c mov r0, #4 */
/* @0x1862a0 mov r2, r9 */
/* @0x1862a4 mov r1, #0 */
/* @0x1862a8 blx r3 */
/* @0x1862ac cmp r6, #0 */
/* @0x1862b0 bgt 0x1861a0 <_ZN16GraphicsRecorder4DrawEfff+0x77c> */
/* @0x1862b4 bl 0x1847f8 <_Z14EndShaderBlockv> */
/* @0x1862b8 ldr r12, [sp, #0x8] */
/* @0x1862bc ldr r6, [r12] */
/* @0x1862c0 b 0x185c78 <_ZN16GraphicsRecorder4DrawEfff+0x254> */
/* @0x1862c4 ldr r3, [pc, #0xc8] */
/* @0x1862c8 ldr r8, [r5, r3] */
/* @0x1862cc b 0x185f8c <_ZN16GraphicsRecorder4DrawEfff+0x568> */
/* @0x1862d0 ldr r1, [r4, #0x14] */
/* @0x1862d4 mvn r3, #0 */
/* @0x1862d8 add r2, r4, #32 */
/* @0x1862dc str r3, [sp] */
/* @0x1862e0 mov r0, r4 */
/* @0x1862e4 add r3, r4, #28 */
/* @0x1862e8 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i> */
/* @0x1862ec ldr r1, [r4, #0x1c] */
/* @0x1862f0 str r0, [r4, #0x14] */
/* @0x1862f4 bl 0x18585c <_Z18CreateVertexBufferPvi> */
/* @0x1862f8 str r0, [r4, #0x18] */
/* @0x1862fc b 0x185b30 <_ZN16GraphicsRecorder4DrawEfff+0x10c> */
/* @0x186300 ldr r3, [r5, r3] */
/* @0x186304 mov r1, r6 */
/* @0x186308 ldr r0, [r3] */
/* @0x18630c bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x186310 ldr r3, [pc, #0x64] */
/* @0x186314 movw r0, #0x8078 */
/* @0x186318 ldr r3, [r5, r3] */
/* @0x18631c str r3, [sp, #0x1c] */
/* @0x186320 ldr r3, [r3] */
/* @0x186324 blx r3 */
/* @0x186328 b 0x185e88 <_ZN16GraphicsRecorder4DrawEfff+0x464> */
/* @0x18632c ldr r3, [r5, r3] */
/* @0x186330 mov r1, r6 */
/* @0x186334 ldr r0, [r3] */
/* @0x186338 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x18633c ldr r3, [pc, #0x38] */
/* @0x186340 movw r0, #0x8078 */
/* @0x186344 ldr r3, [r5, r3] */
/* @0x186348 str r3, [sp, #0x1c] */
/* @0x18634c ldr r3, [r3] */
/* @0x186350 blx r3 */
/* @0x186354 b 0x185ce0 <_ZN16GraphicsRecorder4DrawEfff+0x2bc> */
/* @0x186358 ldr r3, [pc, #0x34] */
/* @0x18635c ldr r8, [r5, r3] */
/* @0x186360 b 0x186130 <_ZN16GraphicsRecorder4DrawEfff+0x70c> */
/* @0x186364 eoreq r12, r6, r12, lsl #3 */
/* @0x186368 .word 0xffffe7e0 */
/* @0x18636c .word 0xffffe90c */
/* @0x186370 .word 0xffffe7b8 */
/* @0x186374 .word 0xffffbc30 */
/* @0x186378 .word 0xffffe4d4 */
/* @0x18637c .word 0xffffbc2c */
/* @0x186380 .word 0xffffbc6c */
/* @0x186384 .word 0xffffbad4 */
/* @0x186388 .word 0xffffbc50 */
/* @0x18638c .word 0xffffbc28 */
/* @0x186390 .word 0xffffbca8 */
/* @0x186394 .word 0xffffbb3c */
/* @0x186398 .word 0xffffbb90 */

/* ── FUNC 0x18639c · DeleteShaderManagerResources() · size=424 · insn=106 */
/* @0x18639c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1863a0 ldr r9, [pc, #0x18c] */
/* @0x1863a4 ldr r3, [pc, #0x18c] */
/* @0x1863a8 add r9, pc, r9 */
/* @0x1863ac ldr r7, [r9, r3] */
/* @0x1863b0 ldr r3, [r7] */
/* @0x1863b4 ldr r0, [r7, #0x4] */
/* @0x1863b8 cmp r3, #0 */
/* @0x1863bc movgt r6, #0 */
/* @0x1863c0 movgt r8, r6 */
/* @0x1863c4 ble 0x186520 <_Z28DeleteShaderManagerResourcesv+0x184> */
/* @0x1863c8 ldr r4, [r0, r6, lsl #2] */
/* @0x1863cc cmp r4, #0 */
/* @0x1863d0 beq 0x186510 <_Z28DeleteShaderManagerResourcesv+0x174> */
/* @0x1863d4 ldr r0, [r4, #0x8] */
/* @0x1863d8 cmn r0, #1 */
/* @0x1863dc beq 0x1863f0 <_Z28DeleteShaderManagerResourcesv+0x54> */
/* @0x1863e0 ldr r3, [pc, #0x154] */
/* @0x1863e4 ldr r3, [r9, r3] */
/* @0x1863e8 ldr r3, [r3] */
/* @0x1863ec blx r3 */
/* @0x1863f0 ldr r0, [r4] */
/* @0x1863f4 cmn r0, #1 */
/* @0x1863f8 beq 0x18640c <_Z28DeleteShaderManagerResourcesv+0x70> */
/* @0x1863fc ldr r3, [pc, #0x13c] */
/* @0x186400 ldr r3, [r9, r3] */
/* @0x186404 ldr r3, [r3] */
/* @0x186408 blx r3 */
/* @0x18640c ldr r0, [r4, #0x4] */
/* @0x186410 cmn r0, #1 */
/* @0x186414 beq 0x186428 <_Z28DeleteShaderManagerResourcesv+0x8c> */
/* @0x186418 ldr r3, [pc, #0x120] */
/* @0x18641c ldr r3, [r9, r3] */
/* @0x186420 ldr r3, [r3] */
/* @0x186424 blx r3 */
/* @0x186428 ldr r0, [r4, #0xc] */
/* @0x18642c cmp r0, #0 */
/* @0x186430 beq 0x186438 <_Z28DeleteShaderManagerResourcesv+0x9c> */
/* @0x186434 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x186438 ldr r0, [r4, #0x10] */
/* @0x18643c cmp r0, #0 */
/* @0x186440 beq 0x186448 <_Z28DeleteShaderManagerResourcesv+0xac> */
/* @0x186444 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x186448 ldr r0, [r4, #0x14] */
/* @0x18644c cmp r0, #0 */
/* @0x186450 beq 0x186488 <_Z28DeleteShaderManagerResourcesv+0xec> */
/* @0x186454 ldr r5, [r0, #-0x4] */
/* @0x186458 add r5, r5, r5, lsl #1 */
/* @0x18645c add r5, r0, r5, lsl #2 */
/* @0x186460 cmp r0, r5 */
/* @0x186464 beq 0x18647c <_Z28DeleteShaderManagerResourcesv+0xe0> */
/* @0x186468 ldr r0, [r5, #-0xc]! */
/* @0x18646c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x186470 ldr r0, [r4, #0x14] */
/* @0x186474 cmp r0, r5 */
/* @0x186478 bne 0x186468 <_Z28DeleteShaderManagerResourcesv+0xcc> */
/* @0x18647c sub r0, r0, #8 */
/* @0x186480 bl 0x27d1d4 <_ZdaPv> */
/* @0x186484 str r8, [r4, #0x14] */
/* @0x186488 ldr r0, [r4, #0x2c] */
/* @0x18648c cmp r0, #0 */
/* @0x186490 beq 0x18649c <_Z28DeleteShaderManagerResourcesv+0x100> */
/* @0x186494 bl 0x27d1d4 <_ZdaPv> */
/* @0x186498 str r8, [r4, #0x2c] */
/* @0x18649c ldr r0, [r4, #0x34] */
/* @0x1864a0 cmp r0, #0 */
/* @0x1864a4 beq 0x1864b0 <_Z28DeleteShaderManagerResourcesv+0x114> */
/* @0x1864a8 bl 0x27d1d4 <_ZdaPv> */
/* @0x1864ac str r8, [r4, #0x34] */
/* @0x1864b0 ldr r0, [r4, #0x38] */
/* @0x1864b4 cmp r0, #0 */
/* @0x1864b8 beq 0x1864c4 <_Z28DeleteShaderManagerResourcesv+0x128> */
/* @0x1864bc bl 0x27d1d4 <_ZdaPv> */
/* @0x1864c0 str r8, [r4, #0x38] */
/* @0x1864c4 ldr r0, [r4, #0x78] */
/* @0x1864c8 cmp r0, #0 */
/* @0x1864cc beq 0x186504 <_Z28DeleteShaderManagerResourcesv+0x168> */
/* @0x1864d0 ldr r5, [r0, #-0x4] */
/* @0x1864d4 rsb r5, r5, r5, lsl #3 */
/* @0x1864d8 add r5, r0, r5, lsl #2 */
/* @0x1864dc cmp r0, r5 */
/* @0x1864e0 beq 0x1864f8 <_Z28DeleteShaderManagerResourcesv+0x15c> */
/* @0x1864e4 ldr r0, [r5, #-0x1c]! */
/* @0x1864e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1864ec ldr r0, [r4, #0x78] */
/* @0x1864f0 cmp r0, r5 */
/* @0x1864f4 bne 0x1864e4 <_Z28DeleteShaderManagerResourcesv+0x148> */
/* @0x1864f8 sub r0, r0, #8 */
/* @0x1864fc bl 0x27d1d4 <_ZdaPv> */
/* @0x186500 str r8, [r4, #0x78] */
/* @0x186504 mov r0, r4 */
/* @0x186508 bl 0x27d1d0 <_ZdlPv> */
/* @0x18650c ldr r0, [r7, #0x4] */
/* @0x186510 ldr r3, [r7] */
/* @0x186514 add r6, r6, #1 */
/* @0x186518 cmp r3, r6 */
/* @0x18651c bgt 0x1863c8 <_Z28DeleteShaderManagerResourcesv+0x2c> */
/* @0x186520 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x186524 mov r3, #0 */
/* @0x186528 str r3, [r7, #0x4] */
/* @0x18652c str r3, [r7] */
/* @0x186530 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x186534 eoreq r11, r6, r8, lsr #17 */
/* @0x186538 .word 0xffffe968 */
/* @0x18653c .word 0xffffbb78 */
/* @0x186540 .word 0xffffbb7c */

/* ── FUNC 0x186544 · SetupErrorString(char**, char*) · size=120 · insn=30 */
/* @0x186544 cmp r1, #0 */
/* @0x186548 cmpne r0, #0 */
/* @0x18654c push {r3, r4, r5, lr} */
/* @0x186550 mov r5, r0 */
/* @0x186554 mov r4, r1 */
/* @0x186558 popeq {r3, r4, r5, pc} */
/* @0x18655c ldr r3, [pc, #0x4c] */
/* @0x186560 mov r2, r1 */
/* @0x186564 ldr r1, [pc, #0x48] */
/* @0x186568 ldr r3, [pc, r3] */
/* @0x18656c add r1, pc, r1 */
/* @0x186570 ldr r0, [r3] */
/* @0x186574 ldr r3, [r0] */
/* @0x186578 ldr r3, [r3, #0xc] */
/* @0x18657c blx r3 */
/* @0x186580 mov r0, r4 */
/* @0x186584 bl 0xb6538 <strlen@plt> */
/* @0x186588 ldr r1, [pc, #0x28] */
/* @0x18658c mov r3, #1 */
/* @0x186590 mov r2, #70 */
/* @0x186594 add r1, pc, r1 */
/* @0x186598 add r0, r0, r3 */
/* @0x18659c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1865a0 mov r1, r4 */
/* @0x1865a4 str r0, [r5] */
/* @0x1865a8 pop {r3, r4, r5, lr} */
/* @0x1865ac b 0xb65a4 <strcpy@plt> */
/* @0x1865b0 eoreq r7, r6, r12, lsr #3 */
/* @0x1865b4 andseq r5, r12, r12, ror r6 */
/* @0x1865b8 mulseq r10, r12, r10 */
