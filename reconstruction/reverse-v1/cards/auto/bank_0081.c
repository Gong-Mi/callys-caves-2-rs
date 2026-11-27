/* libyoyo.so 覆盖卡组 0081
 * 函数 0x147dc8..0x148e70，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x147dc8 · F_GPUGetZFunc(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x147dc8 cmp r3, #0 */
/* @0x147dcc mov r1, #0 */
/* @0x147dd0 push {r4, lr} */
/* @0x147dd4 mov r4, r0 */
/* @0x147dd8 str r1, [r0, #0xc] */
/* @0x147ddc str r1, [r0] */
/* @0x147de0 str r1, [r0, #0x4] */
/* @0x147de4 bne 0x147e14 <_Z13F_GPUGetZFuncR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x147de8 ldr r0, [pc, #0x34] */
/* @0x147dec mov r1, #9 */
/* @0x147df0 ldr r0, [pc, r0] */
/* @0x147df4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147df8 vmov s15, r0 */
/* @0x147dfc vcvt.f64.u32 d7, s15 */
/* @0x147e00 vmov r0, r1, d7 */
/* @0x147e04 vmov r2, s14 */
/* @0x147e08 mov r3, r1 */
/* @0x147e0c stm r4, {r2, r3} */
/* @0x147e10 pop {r4, pc} */
/* @0x147e14 ldr r0, [pc, #0xc] */
/* @0x147e18 pop {r4, lr} */
/* @0x147e1c add r0, pc, r0 */
/* @0x147e20 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147e24 eoreq r5, r10, r8, lsl #30 */
/* @0x147e28 andseq r10, pc, r12, lsl #2 */

/* ── FUNC 0x147e2c · F_GPUGetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x147e2c push {r3, r4, r5, lr} */
/* @0x147e30 subs r5, r3, #0 */
/* @0x147e34 mov r1, #0 */
/* @0x147e38 mov r4, r0 */
/* @0x147e3c str r1, [r0, #0xc] */
/* @0x147e40 str r1, [r0] */
/* @0x147e44 str r1, [r0, #0x4] */
/* @0x147e48 bne 0x147e80 <_Z20F_GPUGetZWriteEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x147e4c ldr r0, [pc, #0x3c] */
/* @0x147e50 mov r1, #4 */
/* @0x147e54 ldr r0, [pc, r0] */
/* @0x147e58 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147e5c cmp r0, #0 */
/* @0x147e60 moveq r3, r0 */
/* @0x147e64 movne r2, #0 */
/* @0x147e68 movne r3, r5 */
/* @0x147e6c movtne r2, #0x3ff0 */
/* @0x147e70 moveq r2, r3 */
/* @0x147e74 str r3, [r4] */
/* @0x147e78 str r2, [r4, #0x4] */
/* @0x147e7c pop {r3, r4, r5, pc} */
/* @0x147e80 ldr r0, [pc, #0xc] */
/* @0x147e84 pop {r3, r4, r5, lr} */
/* @0x147e88 add r0, pc, r0 */
/* @0x147e8c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147e90 eoreq r5, r10, r4, lsr #29 */
/* @0x147e94 ldrsbeq r10, [pc], -r0 */

/* ── FUNC 0x147e98 · F_GPUGetCullmode(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x147e98 cmp r3, #0 */
/* @0x147e9c mov r1, #0 */
/* @0x147ea0 push {r4, lr} */
/* @0x147ea4 mov r4, r0 */
/* @0x147ea8 str r1, [r0, #0xc] */
/* @0x147eac str r1, [r0] */
/* @0x147eb0 str r1, [r0, #0x4] */
/* @0x147eb4 bne 0x147ee4 <_Z16F_GPUGetCullmodeR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x147eb8 ldr r0, [pc, #0x34] */
/* @0x147ebc mov r1, #8 */
/* @0x147ec0 ldr r0, [pc, r0] */
/* @0x147ec4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147ec8 vmov s15, r0 */
/* @0x147ecc vcvt.f64.u32 d7, s15 */
/* @0x147ed0 vmov r0, r1, d7 */
/* @0x147ed4 vmov r2, s14 */
/* @0x147ed8 mov r3, r1 */
/* @0x147edc stm r4, {r2, r3} */
/* @0x147ee0 pop {r4, pc} */
/* @0x147ee4 ldr r0, [pc, #0xc] */
/* @0x147ee8 pop {r4, lr} */
/* @0x147eec add r0, pc, r0 */
/* @0x147ef0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147ef4 eoreq r5, r10, r8, lsr lr */
/* @0x147ef8 andseq r10, pc, r4, lsr #1 */

/* ── FUNC 0x147efc · F_GPUGetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x147efc cmp r3, #0 */
/* @0x147f00 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x147f04 mov r6, #0 */
/* @0x147f08 mov r1, r6 */
/* @0x147f0c mov r4, r0 */
/* @0x147f10 movt r6, #0xbff0 */
/* @0x147f14 str r1, [r0, #0xc] */
/* @0x147f18 stm r0, {r1, r6} */
/* @0x147f1c bne 0x147fc4 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x147f20 ldr r5, [pc, #0xf0] */
/* @0x147f24 mov r1, #6 */
/* @0x147f28 ldr r5, [pc, r5] */
/* @0x147f2c mov r0, r5 */
/* @0x147f30 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147f34 mov r1, #7 */
/* @0x147f38 mov r7, r0 */
/* @0x147f3c mov r0, r5 */
/* @0x147f40 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147f44 mov r1, #34 */
/* @0x147f48 mov r8, r0 */
/* @0x147f4c mov r0, r5 */
/* @0x147f50 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147f54 mov r1, #35 */
/* @0x147f58 mov r9, r0 */
/* @0x147f5c mov r0, r5 */
/* @0x147f60 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147f64 cmp r7, r9 */
/* @0x147f68 cmpeq r8, r0 */
/* @0x147f6c moveq r0, #0 */
/* @0x147f70 movne r0, #1 */
/* @0x147f74 bne 0x147fb0 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x147f78 cmp r7, #1 */
/* @0x147f7c beq 0x147fa8 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x147f80 cmp r7, #5 */
/* @0x147f84 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x147f88 cmp r8, #4 */
/* @0x147f8c beq 0x147ffc <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x147f90 cmp r8, #6 */
/* @0x147f94 beq 0x14800c <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x147f98 cmp r8, #2 */
/* @0x147f9c beq 0x147fe8 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x147fa0 stm r4, {r0, r6} */
/* @0x147fa4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x147fa8 cmp r8, #4 */
/* @0x147fac beq 0x147fd4 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x147fb0 mov r3, #0 */
/* @0x147fb4 mov r2, r3 */
/* @0x147fb8 movt r3, #0xbff0 */
/* @0x147fbc stm r4, {r2, r3} */
/* @0x147fc0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x147fc4 ldr r0, [pc, #0x50] */
/* @0x147fc8 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x147fcc add r0, pc, r0 */
/* @0x147fd0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147fd4 mov r3, #0 */
/* @0x147fd8 str r0, [r4] */
/* @0x147fdc movt r3, #0x4008 */
/* @0x147fe0 str r3, [r4, #0x4] */
/* @0x147fe4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x147fe8 mov r3, #0 */
/* @0x147fec str r0, [r4] */
/* @0x147ff0 movt r3, #0x3ff0 */
/* @0x147ff4 str r3, [r4, #0x4] */
/* @0x147ff8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x147ffc mov r3, #1073741824 */
/* @0x148000 str r0, [r4] */
/* @0x148004 str r3, [r4, #0x4] */
/* @0x148008 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x14800c str r0, [r4] */
/* @0x148010 str r0, [r4, #0x4] */
/* @0x148014 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x148018 .word 0x002a5dd0 */
/* @0x14801c ldrsheq r9, [pc], -r8 */

/* ── FUNC 0x148020 · F_GPUGetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x148020 cmp r3, #0 */
/* @0x148024 mov r3, #0 */
/* @0x148028 push {r4, r5, r6, lr} */
/* @0x14802c mov r1, r3 */
/* @0x148030 sub sp, sp, #8 */
/* @0x148034 movt r3, #0xbff0 */
/* @0x148038 mov r4, r0 */
/* @0x14803c str r1, [r0, #0xc] */
/* @0x148040 stm r0, {r1, r3} */
/* @0x148044 bne 0x148098 <_Z20F_GPUGetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x148048 ldr r5, [pc, #0x5c] */
/* @0x14804c mov r1, #6 */
/* @0x148050 ldr r5, [pc, r5] */
/* @0x148054 mov r0, r5 */
/* @0x148058 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x14805c mov r1, #7 */
/* @0x148060 mov r6, r0 */
/* @0x148064 mov r0, r5 */
/* @0x148068 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x14806c vmov s15, r6 */
/* @0x148070 mov r1, #2 */
/* @0x148074 vcvt.f64.u32 d7, s15 */
/* @0x148078 vmov r2, r3, d7 */
/* @0x14807c vmov s13, r0 */
/* @0x148080 mov r0, r4 */
/* @0x148084 vcvt.f64.u32 d7, s13 */
/* @0x148088 vstr d7, [sp] */
/* @0x14808c bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x148090 add sp, sp, #8 */
/* @0x148094 pop {r4, r5, r6, pc} */
/* @0x148098 ldr r0, [pc, #0x10] */
/* @0x14809c add r0, pc, r0 */
/* @0x1480a0 add sp, sp, #8 */
/* @0x1480a4 pop {r4, r5, r6, lr} */
/* @0x1480a8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1480ac eoreq r5, r10, r8, lsr #25 */
/* @0x1480b0 andseq r9, pc, r12, asr pc */

/* ── FUNC 0x1480b4 · F_GPUGetBlendModeExtSepAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x1480b4 cmp r3, #0 */
/* @0x1480b8 mov r3, #0 */
/* @0x1480bc push {r4, r5, r6, r7, r8, lr} */
/* @0x1480c0 mov r1, r3 */
/* @0x1480c4 sub sp, sp, #24 */
/* @0x1480c8 movt r3, #0xbff0 */
/* @0x1480cc mov r4, r0 */
/* @0x1480d0 str r1, [r0, #0xc] */
/* @0x1480d4 stm r0, {r1, r3} */
/* @0x1480d8 bne 0x148164 <_Z28F_GPUGetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x1480dc ldr r5, [pc, #0x94] */
/* @0x1480e0 mov r1, #6 */
/* @0x1480e4 ldr r5, [pc, r5] */
/* @0x1480e8 mov r0, r5 */
/* @0x1480ec bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1480f0 mov r1, #7 */
/* @0x1480f4 mov r6, r0 */
/* @0x1480f8 mov r0, r5 */
/* @0x1480fc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x148100 mov r1, #34 */
/* @0x148104 mov r8, r0 */
/* @0x148108 mov r0, r5 */
/* @0x14810c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x148110 mov r1, #35 */
/* @0x148114 mov r7, r0 */
/* @0x148118 mov r0, r5 */
/* @0x14811c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x148120 vmov s11, r8 */
/* @0x148124 mov r1, #4 */
/* @0x148128 vcvt.f64.u32 d6, s11 */
/* @0x14812c vmov s11, r7 */
/* @0x148130 vcvt.f64.u32 d7, s11 */
/* @0x148134 vstr d6, [sp] */
/* @0x148138 vstr d7, [sp, #8] */
/* @0x14813c vmov s15, r6 */
/* @0x148140 vcvt.f64.u32 d7, s15 */
/* @0x148144 vmov r2, r3, d7 */
/* @0x148148 vmov s11, r0 */
/* @0x14814c mov r0, r4 */
/* @0x148150 vcvt.f64.u32 d7, s11 */
/* @0x148154 vstr d7, [sp, #16] */
/* @0x148158 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x14815c add sp, sp, #24 */
/* @0x148160 pop {r4, r5, r6, r7, r8, pc} */
/* @0x148164 ldr r0, [pc, #0x10] */
/* @0x148168 add r0, pc, r0 */
/* @0x14816c add sp, sp, #24 */
/* @0x148170 pop {r4, r5, r6, r7, r8, lr} */
/* @0x148174 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148178 eoreq r5, r10, r4, lsl r12 */
/* @0x14817c andseq r9, pc, r8, asr #29 */

/* ── FUNC 0x148180 · F_GPUGetBlendModeSrc(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x148180 cmp r3, #0 */
/* @0x148184 mov r1, #0 */
/* @0x148188 push {r4, lr} */
/* @0x14818c mov r4, r0 */
/* @0x148190 str r1, [r0, #0xc] */
/* @0x148194 str r1, [r0] */
/* @0x148198 str r1, [r0, #0x4] */
/* @0x14819c bne 0x1481cc <_Z20F_GPUGetBlendModeSrcR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1481a0 ldr r0, [pc, #0x34] */
/* @0x1481a4 mov r1, #6 */
/* @0x1481a8 ldr r0, [pc, r0] */
/* @0x1481ac bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1481b0 vmov s15, r0 */
/* @0x1481b4 vcvt.f64.u32 d7, s15 */
/* @0x1481b8 vmov r0, r1, d7 */
/* @0x1481bc vmov r2, s14 */
/* @0x1481c0 mov r3, r1 */
/* @0x1481c4 stm r4, {r2, r3} */
/* @0x1481c8 pop {r4, pc} */
/* @0x1481cc ldr r0, [pc, #0xc] */
/* @0x1481d0 pop {r4, lr} */
/* @0x1481d4 add r0, pc, r0 */
/* @0x1481d8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1481dc eoreq r5, r10, r0, asr r11 */
/* @0x1481e0 mulseq pc, r12, lr */

/* ── FUNC 0x1481e4 · F_GPUGetBlendModeDest(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1481e4 cmp r3, #0 */
/* @0x1481e8 mov r1, #0 */
/* @0x1481ec push {r4, lr} */
/* @0x1481f0 mov r4, r0 */
/* @0x1481f4 str r1, [r0, #0xc] */
/* @0x1481f8 str r1, [r0] */
/* @0x1481fc str r1, [r0, #0x4] */
/* @0x148200 bne 0x148230 <_Z21F_GPUGetBlendModeDestR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x148204 ldr r0, [pc, #0x34] */
/* @0x148208 mov r1, #7 */
/* @0x14820c ldr r0, [pc, r0] */
/* @0x148210 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x148214 vmov s15, r0 */
/* @0x148218 vcvt.f64.u32 d7, s15 */
/* @0x14821c vmov r0, r1, d7 */
/* @0x148220 vmov r2, s14 */
/* @0x148224 mov r3, r1 */
/* @0x148228 stm r4, {r2, r3} */
/* @0x14822c pop {r4, pc} */
/* @0x148230 ldr r0, [pc, #0xc] */
/* @0x148234 pop {r4, lr} */
/* @0x148238 add r0, pc, r0 */
/* @0x14823c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148240 eoreq r5, r10, r12, ror #21 */
/* @0x148244 andseq r9, pc, r0, ror lr */

/* ── FUNC 0x148248 · F_GPUGetBlendModeSrcAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x148248 cmp r3, #0 */
/* @0x14824c mov r1, #0 */
/* @0x148250 push {r4, lr} */
/* @0x148254 mov r4, r0 */
/* @0x148258 str r1, [r0, #0xc] */
/* @0x14825c str r1, [r0] */
/* @0x148260 str r1, [r0, #0x4] */
/* @0x148264 bne 0x148294 <_Z25F_GPUGetBlendModeSrcAlphaR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x148268 ldr r0, [pc, #0x34] */
/* @0x14826c mov r1, #34 */
/* @0x148270 ldr r0, [pc, r0] */
/* @0x148274 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x148278 vmov s15, r0 */
/* @0x14827c vcvt.f64.u32 d7, s15 */
/* @0x148280 vmov r0, r1, d7 */
/* @0x148284 vmov r2, s14 */
/* @0x148288 mov r3, r1 */
/* @0x14828c stm r4, {r2, r3} */
/* @0x148290 pop {r4, pc} */
/* @0x148294 ldr r0, [pc, #0xc] */
/* @0x148298 pop {r4, lr} */
/* @0x14829c add r0, pc, r0 */
/* @0x1482a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1482a4 eoreq r5, r10, r8, lsl #21 */
/* @0x1482a8 andseq r9, pc, r4, asr #28 */

/* ── FUNC 0x1482ac · F_GPUGetBlendModeDestAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1482ac cmp r3, #0 */
/* @0x1482b0 mov r1, #0 */
/* @0x1482b4 push {r4, lr} */
/* @0x1482b8 mov r4, r0 */
/* @0x1482bc str r1, [r0, #0xc] */
/* @0x1482c0 str r1, [r0] */
/* @0x1482c4 str r1, [r0, #0x4] */
/* @0x1482c8 bne 0x1482f8 <_Z26F_GPUGetBlendModeDestAlphaR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1482cc ldr r0, [pc, #0x34] */
/* @0x1482d0 mov r1, #35 */
/* @0x1482d4 ldr r0, [pc, r0] */
/* @0x1482d8 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1482dc vmov s15, r0 */
/* @0x1482e0 vcvt.f64.u32 d7, s15 */
/* @0x1482e4 vmov r0, r1, d7 */
/* @0x1482e8 vmov r2, s14 */
/* @0x1482ec mov r3, r1 */
/* @0x1482f0 stm r4, {r2, r3} */
/* @0x1482f4 pop {r4, pc} */
/* @0x1482f8 ldr r0, [pc, #0xc] */
/* @0x1482fc pop {r4, lr} */
/* @0x148300 add r0, pc, r0 */
/* @0x148304 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148308 eoreq r5, r10, r4, lsr #20 */
/* @0x14830c andseq r9, pc, r12, lsl lr */

/* ── FUNC 0x148310 · F_GPUGetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=42 */
/* @0x148310 cmp r3, #0 */
/* @0x148314 mov r1, #0 */
/* @0x148318 push {r4, lr} */
/* @0x14831c mov r4, r0 */
/* @0x148320 sub sp, sp, #24 */
/* @0x148324 str r1, [r0, #0xc] */
/* @0x148328 str r1, [r0] */
/* @0x14832c str r1, [r0, #0x4] */
/* @0x148330 bne 0x14839c <_Z25F_GPUGetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x148334 ldr r0, [pc, #0x7c] */
/* @0x148338 mov r1, #24 */
/* @0x14833c ldr r0, [pc, r0] */
/* @0x148340 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x148344 vmov.f64 d7, #1.000000e+00 */
/* @0x148348 vldr d6, [pc, #96] */
/* @0x14834c mov r1, #4 */
/* @0x148350 tst r0, #1 */
/* @0x148354 mov r12, r0 */
/* @0x148358 mov r0, r4 */
/* @0x14835c vmovne r2, r3, d7 */
/* @0x148360 vmoveq r2, r3, d6 */
/* @0x148364 tst r12, #2 */
/* @0x148368 vmovne.f64 d5, d7 */
/* @0x14836c vmoveq.f64 d5, d6 */
/* @0x148370 tst r12, #4 */
/* @0x148374 vstr d5, [sp] */
/* @0x148378 vmovne.f64 d5, d7 */
/* @0x14837c vmoveq.f64 d5, d6 */
/* @0x148380 tst r12, #8 */
/* @0x148384 vstr d5, [sp, #8] */
/* @0x148388 vmoveq.f64 d7, d6 */
/* @0x14838c vstr d7, [sp, #16] */
/* @0x148390 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x148394 add sp, sp, #24 */
/* @0x148398 pop {r4, pc} */
/* @0x14839c ldr r0, [pc, #0x18] */
/* @0x1483a0 add r0, pc, r0 */
/* @0x1483a4 add sp, sp, #24 */
/* @0x1483a8 pop {r4, lr} */
/* @0x1483ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1483b8 .word 0x002a59bc */
/* @0x1483bc ldrheq r9, [pc], -r12 */

/* ── FUNC 0x1483c0 · F_GPUGetAlphaTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1483c0 push {r3, r4, r5, lr} */
/* @0x1483c4 subs r5, r3, #0 */
/* @0x1483c8 mov r1, #0 */
/* @0x1483cc mov r4, r0 */
/* @0x1483d0 str r1, [r0, #0xc] */
/* @0x1483d4 str r1, [r0] */
/* @0x1483d8 str r1, [r0, #0x4] */
/* @0x1483dc bne 0x148414 <_Z23F_GPUGetAlphaTestEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1483e0 ldr r0, [pc, #0x3c] */
/* @0x1483e4 mov r1, #5 */
/* @0x1483e8 ldr r0, [pc, r0] */
/* @0x1483ec bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1483f0 cmp r0, #0 */
/* @0x1483f4 moveq r3, r0 */
/* @0x1483f8 movne r2, #0 */
/* @0x1483fc movne r3, r5 */
/* @0x148400 movtne r2, #0x3ff0 */
/* @0x148404 moveq r2, r3 */
/* @0x148408 str r3, [r4] */
/* @0x14840c str r2, [r4, #0x4] */
/* @0x148410 pop {r3, r4, r5, pc} */
/* @0x148414 ldr r0, [pc, #0xc] */
/* @0x148418 pop {r3, r4, r5, lr} */
/* @0x14841c add r0, pc, r0 */
/* @0x148420 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148424 eoreq r5, r10, r0, lsl r9 */
/* @0x148428 andseq r9, pc, r12, ror sp */

/* ── FUNC 0x14842c · F_GPUGetAlphaTestRef(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x14842c cmp r3, #0 */
/* @0x148430 mov r1, #0 */
/* @0x148434 push {r4, lr} */
/* @0x148438 mov r4, r0 */
/* @0x14843c str r1, [r0, #0xc] */
/* @0x148440 str r1, [r0] */
/* @0x148444 str r1, [r0, #0x4] */
/* @0x148448 bne 0x148478 <_Z20F_GPUGetAlphaTestRefR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14844c ldr r0, [pc, #0x34] */
/* @0x148450 mov r1, #10 */
/* @0x148454 ldr r0, [pc, r0] */
/* @0x148458 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x14845c vmov s15, r0 */
/* @0x148460 vcvt.f64.u32 d7, s15 */
/* @0x148464 vmov r0, r1, d7 */
/* @0x148468 vmov r2, s14 */
/* @0x14846c mov r3, r1 */
/* @0x148470 stm r4, {r2, r3} */
/* @0x148474 pop {r4, pc} */
/* @0x148478 ldr r0, [pc, #0xc] */
/* @0x14847c pop {r4, lr} */
/* @0x148480 add r0, pc, r0 */
/* @0x148484 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148488 eoreq r5, r10, r4, lsr #17 */
/* @0x14848c andseq r9, pc, r4, asr sp */

/* ── FUNC 0x148490 · F_GPUGetAlphaTestFunc(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x148490 cmp r3, #0 */
/* @0x148494 mov r1, #0 */
/* @0x148498 push {r4, lr} */
/* @0x14849c mov r4, r0 */
/* @0x1484a0 str r1, [r0, #0xc] */
/* @0x1484a4 str r1, [r0] */
/* @0x1484a8 str r1, [r0, #0x4] */
/* @0x1484ac bne 0x1484dc <_Z21F_GPUGetAlphaTestFuncR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1484b0 ldr r0, [pc, #0x34] */
/* @0x1484b4 mov r1, #11 */
/* @0x1484b8 ldr r0, [pc, r0] */
/* @0x1484bc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1484c0 vmov s15, r0 */
/* @0x1484c4 vcvt.f64.u32 d7, s15 */
/* @0x1484c8 vmov r0, r1, d7 */
/* @0x1484cc vmov r2, s14 */
/* @0x1484d0 mov r3, r1 */
/* @0x1484d4 stm r4, {r2, r3} */
/* @0x1484d8 pop {r4, pc} */
/* @0x1484dc ldr r0, [pc, #0xc] */
/* @0x1484e0 pop {r4, lr} */
/* @0x1484e4 add r0, pc, r0 */
/* @0x1484e8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1484ec eoreq r5, r10, r0, asr #16 */
/* @0x1484f0 andseq r9, pc, r8, lsr #26 */

/* ── FUNC 0x1484f4 · F_GPUGetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1484f4 push {r3, r4, r5, lr} */
/* @0x1484f8 subs r5, r3, #0 */
/* @0x1484fc mov r1, #0 */
/* @0x148500 mov r4, r0 */
/* @0x148504 str r1, [r0, #0xc] */
/* @0x148508 str r1, [r0] */
/* @0x14850c str r1, [r0, #0x4] */
/* @0x148510 bne 0x148544 <_Z17F_GPUGetTexFilterR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x148514 ldr r0, [pc, #0x38] */
/* @0x148518 mov r1, r5 */
/* @0x14851c mov r2, r5 */
/* @0x148520 ldr r0, [pc, r0] */
/* @0x148524 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148528 str r5, [r4] */
/* @0x14852c cmp r0, #1 */
/* @0x148530 moveq r3, #0 */
/* @0x148534 movne r3, r5 */
/* @0x148538 movteq r3, #0x3ff0 */
/* @0x14853c str r3, [r4, #0x4] */
/* @0x148540 pop {r3, r4, r5, pc} */
/* @0x148544 ldr r0, [pc, #0xc] */
/* @0x148548 pop {r3, r4, r5, lr} */
/* @0x14854c add r0, pc, r0 */
/* @0x148550 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148554 .word 0x002a57d8 */
/* @0x148558 ldrsheq r9, [pc], -r8 */

/* ── FUNC 0x14855c · F_GPUGetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x14855c cmp r3, #1 */
/* @0x148560 push {r3, r4, r5, lr} */
/* @0x148564 mov r5, r0 */
/* @0x148568 mov r4, #0 */
/* @0x14856c ldr r0, [sp, #0x10] */
/* @0x148570 str r4, [r5, #0xc] */
/* @0x148574 mov r1, r4 */
/* @0x148578 str r4, [r5] */
/* @0x14857c str r4, [r5, #0x4] */
/* @0x148580 beq 0x148594 <_Z20F_GPUGetTexFilterExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148584 ldr r0, [pc, #0x44] */
/* @0x148588 pop {r3, r4, r5, lr} */
/* @0x14858c add r0, pc, r0 */
/* @0x148590 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148594 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148598 cmp r0, #7 */
/* @0x14859c pophi {r3, r4, r5, pc} */
/* @0x1485a0 ldr r3, [pc, #0x2c] */
/* @0x1485a4 mov r1, r0 */
/* @0x1485a8 mov r2, r4 */
/* @0x1485ac ldr r0, [pc, r3] */
/* @0x1485b0 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1485b4 str r4, [r5] */
/* @0x1485b8 cmp r0, #1 */
/* @0x1485bc moveq r3, #0 */
/* @0x1485c0 movne r3, r4 */
/* @0x1485c4 movteq r3, #0x3ff0 */
/* @0x1485c8 str r3, [r5, #0x4] */
/* @0x1485cc pop {r3, r4, r5, pc} */
/* @0x1485d0 andseq r9, pc, r12, ror #25 */
/* @0x1485d4 eoreq r5, r10, r12, asr #14 */

/* ── FUNC 0x1485d8 · F_GPUGetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1485d8 push {r3, r4, r5, lr} */
/* @0x1485dc subs r5, r3, #0 */
/* @0x1485e0 mov r1, #0 */
/* @0x1485e4 mov r4, r0 */
/* @0x1485e8 str r1, [r0, #0xc] */
/* @0x1485ec str r1, [r0] */
/* @0x1485f0 str r1, [r0, #0x4] */
/* @0x1485f4 bne 0x14862c <_Z17F_GPUGetTexRepeatR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1485f8 ldr r0, [pc, #0x3c] */
/* @0x1485fc mov r1, r5 */
/* @0x148600 mov r2, #2 */
/* @0x148604 ldr r0, [pc, r0] */
/* @0x148608 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x14860c cmp r0, #0 */
/* @0x148610 moveq r3, #0 */
/* @0x148614 moveq r5, r0 */
/* @0x148618 movteq r3, #0x3ff0 */
/* @0x14861c movne r3, r5 */
/* @0x148620 str r5, [r4] */
/* @0x148624 str r3, [r4, #0x4] */
/* @0x148628 pop {r3, r4, r5, pc} */
/* @0x14862c ldr r0, [pc, #0xc] */
/* @0x148630 pop {r3, r4, r5, lr} */
/* @0x148634 add r0, pc, r0 */
/* @0x148638 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14863c .word 0x002a56f4 */
/* @0x148640 mulseq pc, r4, r12 */

/* ── FUNC 0x148644 · F_GPUGetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x148644 cmp r3, #1 */
/* @0x148648 push {r3, r4, r5, lr} */
/* @0x14864c mov r5, r0 */
/* @0x148650 mov r4, #0 */
/* @0x148654 ldr r0, [sp, #0x10] */
/* @0x148658 str r4, [r5, #0xc] */
/* @0x14865c mov r1, r4 */
/* @0x148660 str r4, [r5] */
/* @0x148664 str r4, [r5, #0x4] */
/* @0x148668 beq 0x14867c <_Z20F_GPUGetTexRepeatExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14866c ldr r0, [pc, #0x48] */
/* @0x148670 pop {r3, r4, r5, lr} */
/* @0x148674 add r0, pc, r0 */
/* @0x148678 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14867c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148680 cmp r0, #7 */
/* @0x148684 pophi {r3, r4, r5, pc} */
/* @0x148688 ldr r3, [pc, #0x30] */
/* @0x14868c mov r1, r0 */
/* @0x148690 mov r2, #2 */
/* @0x148694 ldr r0, [pc, r3] */
/* @0x148698 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x14869c cmp r0, #0 */
/* @0x1486a0 moveq r3, #0 */
/* @0x1486a4 moveq r4, r0 */
/* @0x1486a8 movteq r3, #0x3ff0 */
/* @0x1486ac movne r3, r4 */
/* @0x1486b0 str r4, [r5] */
/* @0x1486b4 str r3, [r5, #0x4] */
/* @0x1486b8 pop {r3, r4, r5, pc} */
/* @0x1486bc andseq r9, pc, r8, lsl #25 */
/* @0x1486c0 eoreq r5, r10, r4, ror #12 */

/* ── FUNC 0x1486c4 · F_GPUGetTexMipFilter(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1486c4 subs r1, r3, #0 */
/* @0x1486c8 push {r4, lr} */
/* @0x1486cc mov r4, r0 */
/* @0x1486d0 mov r0, #0 */
/* @0x1486d4 mov r2, r0 */
/* @0x1486d8 movt r0, #0xbff0 */
/* @0x1486dc str r2, [r4, #0xc] */
/* @0x1486e0 str r0, [r4, #0x4] */
/* @0x1486e4 str r2, [r4] */
/* @0x1486e8 bne 0x148718 <_Z20F_GPUGetTexMipFilterR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1486ec ldr r0, [pc, #0x38] */
/* @0x1486f0 mov r2, #4 */
/* @0x1486f4 ldr r0, [pc, r0] */
/* @0x1486f8 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1486fc vmov s15, r0 */
/* @0x148700 vcvt.f64.u32 d7, s15 */
/* @0x148704 vmov r0, r1, d7 */
/* @0x148708 vmov r2, s14 */
/* @0x14870c mov r3, r1 */
/* @0x148710 stm r4, {r2, r3} */
/* @0x148714 pop {r4, pc} */
/* @0x148718 ldr r0, [pc, #0x10] */
/* @0x14871c mov r1, r2 */
/* @0x148720 pop {r4, lr} */
/* @0x148724 add r0, pc, r0 */
/* @0x148728 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14872c eoreq r5, r10, r4, lsl #12 */
/* @0x148730 andseq r9, pc, r8, lsr #24 */

/* ── FUNC 0x148734 · F_GPUGetTexMipFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x148734 cmp r3, #1 */
/* @0x148738 mov r3, #0 */
/* @0x14873c push {r4, lr} */
/* @0x148740 mov r1, r3 */
/* @0x148744 mov r4, r0 */
/* @0x148748 movt r3, #0xbff0 */
/* @0x14874c str r1, [r0, #0xc] */
/* @0x148750 stm r0, {r1, r3} */
/* @0x148754 ldr r0, [sp, #0x8] */
/* @0x148758 beq 0x14876c <_Z23F_GPUGetTexMipFilterExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14875c ldr r0, [pc, #0x44] */
/* @0x148760 pop {r4, lr} */
/* @0x148764 add r0, pc, r0 */
/* @0x148768 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14876c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148770 cmp r0, #7 */
/* @0x148774 pophi {r4, pc} */
/* @0x148778 ldr r3, [pc, #0x2c] */
/* @0x14877c mov r1, r0 */
/* @0x148780 mov r2, #4 */
/* @0x148784 ldr r0, [pc, r3] */
/* @0x148788 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x14878c vmov s15, r0 */
/* @0x148790 vcvt.f64.u32 d7, s15 */
/* @0x148794 vmov r0, r1, d7 */
/* @0x148798 vmov r2, s14 */
/* @0x14879c mov r3, r1 */
/* @0x1487a0 stm r4, {r2, r3} */
/* @0x1487a4 pop {r4, pc} */
/* @0x1487a8 andseq r9, pc, r0, lsr #24 */
/* @0x1487ac eoreq r5, r10, r4, ror r5 */

/* ── FUNC 0x1487b0 · F_GPUGetTexMipBias(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1487b0 subs r1, r3, #0 */
/* @0x1487b4 push {r4, lr} */
/* @0x1487b8 mov r4, r0 */
/* @0x1487bc mov r0, #0 */
/* @0x1487c0 mov r2, r0 */
/* @0x1487c4 movt r0, #0xbff0 */
/* @0x1487c8 str r2, [r4, #0xc] */
/* @0x1487cc str r0, [r4, #0x4] */
/* @0x1487d0 str r2, [r4] */
/* @0x1487d4 bne 0x148804 <_Z18F_GPUGetTexMipBiasR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1487d8 ldr r0, [pc, #0x38] */
/* @0x1487dc mov r2, #7 */
/* @0x1487e0 ldr r0, [pc, r0] */
/* @0x1487e4 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1487e8 vmov s15, r0 */
/* @0x1487ec vcvt.f64.f32 d7, s15 */
/* @0x1487f0 vmov r0, r1, d7 */
/* @0x1487f4 vmov r2, s14 */
/* @0x1487f8 mov r3, r1 */
/* @0x1487fc stm r4, {r2, r3} */
/* @0x148800 pop {r4, pc} */
/* @0x148804 ldr r0, [pc, #0x10] */
/* @0x148808 mov r1, r2 */
/* @0x14880c pop {r4, lr} */
/* @0x148810 add r0, pc, r0 */
/* @0x148814 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148818 eoreq r5, r10, r8, lsl r5 */
/* @0x14881c andseq r9, pc, r12, asr #23 */

/* ── FUNC 0x148820 · F_GPUGetTexMipBiasExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x148820 cmp r3, #1 */
/* @0x148824 mov r3, #0 */
/* @0x148828 push {r4, lr} */
/* @0x14882c mov r1, r3 */
/* @0x148830 mov r4, r0 */
/* @0x148834 movt r3, #0xbff0 */
/* @0x148838 str r1, [r0, #0xc] */
/* @0x14883c stm r0, {r1, r3} */
/* @0x148840 ldr r0, [sp, #0x8] */
/* @0x148844 beq 0x148858 <_Z21F_GPUGetTexMipBiasExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148848 ldr r0, [pc, #0x44] */
/* @0x14884c pop {r4, lr} */
/* @0x148850 add r0, pc, r0 */
/* @0x148854 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148858 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14885c cmp r0, #7 */
/* @0x148860 pophi {r4, pc} */
/* @0x148864 ldr r3, [pc, #0x2c] */
/* @0x148868 mov r1, r0 */
/* @0x14886c mov r2, #7 */
/* @0x148870 ldr r0, [pc, r3] */
/* @0x148874 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148878 vmov s15, r0 */
/* @0x14887c vcvt.f64.f32 d7, s15 */
/* @0x148880 vmov r0, r1, d7 */
/* @0x148884 vmov r2, s14 */
/* @0x148888 mov r3, r1 */
/* @0x14888c stm r4, {r2, r3} */
/* @0x148890 pop {r4, pc} */
/* @0x148894 andseq r9, pc, r4, asr #23 */
/* @0x148898 eoreq r5, r10, r8, lsl #9 */

/* ── FUNC 0x14889c · F_GPUGetTexMinMip(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x14889c subs r1, r3, #0 */
/* @0x1488a0 push {r4, lr} */
/* @0x1488a4 mov r4, r0 */
/* @0x1488a8 mov r0, #0 */
/* @0x1488ac mov r2, r0 */
/* @0x1488b0 movt r0, #0xbff0 */
/* @0x1488b4 str r2, [r4, #0xc] */
/* @0x1488b8 str r0, [r4, #0x4] */
/* @0x1488bc str r2, [r4] */
/* @0x1488c0 bne 0x1488f0 <_Z17F_GPUGetTexMinMipR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1488c4 ldr r0, [pc, #0x38] */
/* @0x1488c8 mov r2, #5 */
/* @0x1488cc ldr r0, [pc, r0] */
/* @0x1488d0 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1488d4 vmov s15, r0 */
/* @0x1488d8 vcvt.f64.f32 d7, s15 */
/* @0x1488dc vmov r0, r1, d7 */
/* @0x1488e0 vmov r2, s14 */
/* @0x1488e4 mov r3, r1 */
/* @0x1488e8 stm r4, {r2, r3} */
/* @0x1488ec pop {r4, pc} */
/* @0x1488f0 ldr r0, [pc, #0x10] */
/* @0x1488f4 mov r1, r2 */
/* @0x1488f8 pop {r4, lr} */
/* @0x1488fc add r0, pc, r0 */
/* @0x148900 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148904 eoreq r5, r10, r12, lsr #8 */
/* @0x148908 andseq r9, pc, r12, ror #22 */

/* ── FUNC 0x14890c · F_GPUGetTexMinMipExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x14890c cmp r3, #1 */
/* @0x148910 mov r3, #0 */
/* @0x148914 push {r4, lr} */
/* @0x148918 mov r1, r3 */
/* @0x14891c mov r4, r0 */
/* @0x148920 movt r3, #0xbff0 */
/* @0x148924 str r1, [r0, #0xc] */
/* @0x148928 stm r0, {r1, r3} */
/* @0x14892c ldr r0, [sp, #0x8] */
/* @0x148930 beq 0x148944 <_Z20F_GPUGetTexMinMipExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148934 ldr r0, [pc, #0x44] */
/* @0x148938 pop {r4, lr} */
/* @0x14893c add r0, pc, r0 */
/* @0x148940 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148944 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148948 cmp r0, #7 */
/* @0x14894c pophi {r4, pc} */
/* @0x148950 ldr r3, [pc, #0x2c] */
/* @0x148954 mov r1, r0 */
/* @0x148958 mov r2, #5 */
/* @0x14895c ldr r0, [pc, r3] */
/* @0x148960 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148964 vmov s15, r0 */
/* @0x148968 vcvt.f64.f32 d7, s15 */
/* @0x14896c vmov r0, r1, d7 */
/* @0x148970 vmov r2, s14 */
/* @0x148974 mov r3, r1 */
/* @0x148978 stm r4, {r2, r3} */
/* @0x14897c pop {r4, pc} */
/* @0x148980 andseq r9, pc, r0, ror #22 */
/* @0x148984 mlaeq r10, r12, r3, r5 */

/* ── FUNC 0x148988 · F_GPUGetTexMaxMip(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x148988 subs r1, r3, #0 */
/* @0x14898c push {r4, lr} */
/* @0x148990 mov r4, r0 */
/* @0x148994 mov r0, #0 */
/* @0x148998 mov r2, r0 */
/* @0x14899c movt r0, #0xbff0 */
/* @0x1489a0 str r2, [r4, #0xc] */
/* @0x1489a4 str r0, [r4, #0x4] */
/* @0x1489a8 str r2, [r4] */
/* @0x1489ac bne 0x1489dc <_Z17F_GPUGetTexMaxMipR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1489b0 ldr r0, [pc, #0x38] */
/* @0x1489b4 mov r2, #6 */
/* @0x1489b8 ldr r0, [pc, r0] */
/* @0x1489bc bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1489c0 vmov s15, r0 */
/* @0x1489c4 vcvt.f64.f32 d7, s15 */
/* @0x1489c8 vmov r0, r1, d7 */
/* @0x1489cc vmov r2, s14 */
/* @0x1489d0 mov r3, r1 */
/* @0x1489d4 stm r4, {r2, r3} */
/* @0x1489d8 pop {r4, pc} */
/* @0x1489dc ldr r0, [pc, #0x10] */
/* @0x1489e0 mov r1, r2 */
/* @0x1489e4 pop {r4, lr} */
/* @0x1489e8 add r0, pc, r0 */
/* @0x1489ec b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1489f0 eoreq r5, r10, r0, asr #6 */
/* @0x1489f4 andseq r9, pc, r8, lsl #22 */

/* ── FUNC 0x1489f8 · F_GPUGetTexMaxMipExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1489f8 cmp r3, #1 */
/* @0x1489fc mov r3, #0 */
/* @0x148a00 push {r4, lr} */
/* @0x148a04 mov r1, r3 */
/* @0x148a08 mov r4, r0 */
/* @0x148a0c movt r3, #0xbff0 */
/* @0x148a10 str r1, [r0, #0xc] */
/* @0x148a14 stm r0, {r1, r3} */
/* @0x148a18 ldr r0, [sp, #0x8] */
/* @0x148a1c beq 0x148a30 <_Z20F_GPUGetTexMaxMipExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148a20 ldr r0, [pc, #0x44] */
/* @0x148a24 pop {r4, lr} */
/* @0x148a28 add r0, pc, r0 */
/* @0x148a2c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148a30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148a34 cmp r0, #7 */
/* @0x148a38 pophi {r4, pc} */
/* @0x148a3c ldr r3, [pc, #0x2c] */
/* @0x148a40 mov r1, r0 */
/* @0x148a44 mov r2, #6 */
/* @0x148a48 ldr r0, [pc, r3] */
/* @0x148a4c bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148a50 vmov s15, r0 */
/* @0x148a54 vcvt.f64.f32 d7, s15 */
/* @0x148a58 vmov r0, r1, d7 */
/* @0x148a5c vmov r2, s14 */
/* @0x148a60 mov r3, r1 */
/* @0x148a64 stm r4, {r2, r3} */
/* @0x148a68 pop {r4, pc} */
/* @0x148a6c ldrsheq r9, [pc], -r12 */
/* @0x148a70 .word 0x002a52b0 */

/* ── FUNC 0x148a74 · F_GPUGetTexMaxAniso(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x148a74 subs r1, r3, #0 */
/* @0x148a78 push {r4, lr} */
/* @0x148a7c mov r4, r0 */
/* @0x148a80 mov r0, #0 */
/* @0x148a84 mov r2, r0 */
/* @0x148a88 movt r0, #0xbff0 */
/* @0x148a8c str r2, [r4, #0xc] */
/* @0x148a90 str r0, [r4, #0x4] */
/* @0x148a94 str r2, [r4] */
/* @0x148a98 bne 0x148ac8 <_Z19F_GPUGetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x148a9c ldr r0, [pc, #0x38] */
/* @0x148aa0 mov r2, #8 */
/* @0x148aa4 ldr r0, [pc, r0] */
/* @0x148aa8 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148aac vmov s15, r0 */
/* @0x148ab0 vcvt.f64.u32 d7, s15 */
/* @0x148ab4 vmov r0, r1, d7 */
/* @0x148ab8 vmov r2, s14 */
/* @0x148abc mov r3, r1 */
/* @0x148ac0 stm r4, {r2, r3} */
/* @0x148ac4 pop {r4, pc} */
/* @0x148ac8 ldr r0, [pc, #0x10] */
/* @0x148acc mov r1, r2 */
/* @0x148ad0 pop {r4, lr} */
/* @0x148ad4 add r0, pc, r0 */
/* @0x148ad8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148adc eoreq r5, r10, r4, asr r2 */
/* @0x148ae0 andseq r9, pc, r4, lsl #21 */

/* ── FUNC 0x148ae4 · F_GPUGetTexMaxAnisoExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x148ae4 cmp r3, #1 */
/* @0x148ae8 mov r3, #0 */
/* @0x148aec push {r4, lr} */
/* @0x148af0 mov r1, r3 */
/* @0x148af4 mov r4, r0 */
/* @0x148af8 movt r3, #0xbff0 */
/* @0x148afc str r1, [r0, #0xc] */
/* @0x148b00 stm r0, {r1, r3} */
/* @0x148b04 ldr r0, [sp, #0x8] */
/* @0x148b08 beq 0x148b1c <_Z22F_GPUGetTexMaxAnisoExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148b0c ldr r0, [pc, #0x44] */
/* @0x148b10 pop {r4, lr} */
/* @0x148b14 add r0, pc, r0 */
/* @0x148b18 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148b1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148b20 cmp r0, #7 */
/* @0x148b24 pophi {r4, pc} */
/* @0x148b28 ldr r3, [pc, #0x2c] */
/* @0x148b2c mov r1, r0 */
/* @0x148b30 mov r2, #8 */
/* @0x148b34 ldr r0, [pc, r3] */
/* @0x148b38 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148b3c vmov s15, r0 */
/* @0x148b40 vcvt.f64.u32 d7, s15 */
/* @0x148b44 vmov r0, r1, d7 */
/* @0x148b48 vmov r2, s14 */
/* @0x148b4c mov r3, r1 */
/* @0x148b50 stm r4, {r2, r3} */
/* @0x148b54 pop {r4, pc} */
/* @0x148b58 andseq r9, pc, r12, ror r10 */
/* @0x148b5c eoreq r5, r10, r4, asr #3 */

/* ── FUNC 0x148b60 · F_GPUGetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x148b60 subs r1, r3, #0 */
/* @0x148b64 push {r4, lr} */
/* @0x148b68 mov r4, r0 */
/* @0x148b6c mov r0, #0 */
/* @0x148b70 mov r2, r0 */
/* @0x148b74 movt r0, #0xbff0 */
/* @0x148b78 str r2, [r4, #0xc] */
/* @0x148b7c str r0, [r4, #0x4] */
/* @0x148b80 str r2, [r4] */
/* @0x148b84 bne 0x148bb4 <_Z20F_GPUGetTexMipEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x148b88 ldr r0, [pc, #0x38] */
/* @0x148b8c mov r2, #9 */
/* @0x148b90 ldr r0, [pc, r0] */
/* @0x148b94 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148b98 vmov s15, r0 */
/* @0x148b9c vcvt.f64.u32 d7, s15 */
/* @0x148ba0 vmov r0, r1, d7 */
/* @0x148ba4 vmov r2, s14 */
/* @0x148ba8 mov r3, r1 */
/* @0x148bac stm r4, {r2, r3} */
/* @0x148bb0 pop {r4, pc} */
/* @0x148bb4 ldr r0, [pc, #0x10] */
/* @0x148bb8 mov r1, r2 */
/* @0x148bbc pop {r4, lr} */
/* @0x148bc0 add r0, pc, r0 */
/* @0x148bc4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148bc8 eoreq r5, r10, r8, ror #2 */
/* @0x148bcc andseq r9, pc, r4, lsl #20 */

/* ── FUNC 0x148bd0 · F_GPUGetTexMipEnableExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x148bd0 cmp r3, #1 */
/* @0x148bd4 mov r3, #0 */
/* @0x148bd8 push {r4, lr} */
/* @0x148bdc mov r1, r3 */
/* @0x148be0 mov r4, r0 */
/* @0x148be4 movt r3, #0xbff0 */
/* @0x148be8 str r1, [r0, #0xc] */
/* @0x148bec stm r0, {r1, r3} */
/* @0x148bf0 ldr r0, [sp, #0x8] */
/* @0x148bf4 beq 0x148c08 <_Z23F_GPUGetTexMipEnableExtR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148bf8 ldr r0, [pc, #0x44] */
/* @0x148bfc pop {r4, lr} */
/* @0x148c00 add r0, pc, r0 */
/* @0x148c04 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148c08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x148c0c cmp r0, #7 */
/* @0x148c10 pophi {r4, pc} */
/* @0x148c14 ldr r3, [pc, #0x2c] */
/* @0x148c18 mov r1, r0 */
/* @0x148c1c mov r2, #9 */
/* @0x148c20 ldr r0, [pc, r3] */
/* @0x148c24 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x148c28 vmov s15, r0 */
/* @0x148c2c vcvt.f64.u32 d7, s15 */
/* @0x148c30 vmov r0, r1, d7 */
/* @0x148c34 vmov r2, s14 */
/* @0x148c38 mov r3, r1 */
/* @0x148c3c stm r4, {r2, r3} */
/* @0x148c40 pop {r4, pc} */
/* @0x148c44 ldrsheq r9, [pc], -r12 */
/* @0x148c48 .word 0x002a50d8 */

/* ── FUNC 0x148c4c · F_D3DBuildMatrix(RValue&, CInstance*, CInstance*, int, RValue*) · size=548 · insn=137 */
/* @0x148c4c push {r4, r5, lr} */
/* @0x148c50 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x148c54 cmp r3, #9 */
/* @0x148c58 sub sp, sp, #124 */
/* @0x148c5c mov r5, r0 */
/* @0x148c60 ldr r4, [sp, #0xb8] */
/* @0x148c64 beq 0x148c84 <_Z16F_D3DBuildMatrixR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x148c68 ldr r0, [pc, #0x1fc] */
/* @0x148c6c mov r1, #1 */
/* @0x148c70 add r0, pc, r0 */
/* @0x148c74 add sp, sp, #124 */
/* @0x148c78 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x148c7c pop {r4, r5, lr} */
/* @0x148c80 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148c84 mov r0, r4 */
/* @0x148c88 mov r1, #0 */
/* @0x148c8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148c90 mov r1, #1 */
/* @0x148c94 vldr s19, [pc, #460] */
/* @0x148c98 vmov s18, r0 */
/* @0x148c9c mov r0, r4 */
/* @0x148ca0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148ca4 mov r1, #2 */
/* @0x148ca8 vmov s17, r0 */
/* @0x148cac mov r0, r4 */
/* @0x148cb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148cb4 mov r1, #3 */
/* @0x148cb8 vmov s16, r0 */
/* @0x148cbc mov r0, r4 */
/* @0x148cc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148cc4 mov r1, #4 */
/* @0x148cc8 vmov s12, r0 */
/* @0x148ccc mov r0, r4 */
/* @0x148cd0 vnmul.f32 s20, s19, s12 */
/* @0x148cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148cd8 mov r1, #5 */
/* @0x148cdc vmov s13, r0 */
/* @0x148ce0 mov r0, r4 */
/* @0x148ce4 vnmul.f32 s21, s19, s13 */
/* @0x148ce8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148cec mov r1, #6 */
/* @0x148cf0 vmov s15, r0 */
/* @0x148cf4 mov r0, r4 */
/* @0x148cf8 vnmul.f32 s27, s19, s15 */
/* @0x148cfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148d00 mov r1, #7 */
/* @0x148d04 vmov s22, r0 */
/* @0x148d08 mov r0, r4 */
/* @0x148d0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148d10 mov r1, #8 */
/* @0x148d14 vmov s24, r0 */
/* @0x148d18 mov r0, r4 */
/* @0x148d1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x148d20 vmov s23, r0 */
/* @0x148d24 vmov r0, s20 */
/* @0x148d28 bl 0xb6580 <sinf@plt> */
/* @0x148d2c vmov s25, r0 */
/* @0x148d30 vmov r0, s20 */
/* @0x148d34 bl 0xb658c <cosf@plt> */
/* @0x148d38 vmov s20, r0 */
/* @0x148d3c vmov r0, s21 */
/* @0x148d40 bl 0xb6580 <sinf@plt> */
/* @0x148d44 vmov s26, r0 */
/* @0x148d48 vmov r0, s21 */
/* @0x148d4c bl 0xb658c <cosf@plt> */
/* @0x148d50 vmov s19, r0 */
/* @0x148d54 vmov r0, s27 */
/* @0x148d58 bl 0xb6580 <sinf@plt> */
/* @0x148d5c vmov s21, r0 */
/* @0x148d60 vmov r0, s27 */
/* @0x148d64 bl 0xb658c <cosf@plt> */
/* @0x148d68 vneg.f32 s14, s26 */
/* @0x148d6c mov r2, #0 */
/* @0x148d70 mov r3, #0 */
/* @0x148d74 mov r1, #16 */
/* @0x148d78 strd r2, r3, [sp, #16] */
/* @0x148d7c strd r2, r3, [sp, #48] */
/* @0x148d80 vmul.f32 s15, s25, s21 */
/* @0x148d84 strd r2, r3, [sp, #80] */
/* @0x148d88 mov r2, #0 */
/* @0x148d8c mov r3, #0 */
/* @0x148d90 movt r3, #0x3ff0 */
/* @0x148d94 strd r2, r3, [sp, #112] */
/* @0x148d98 vmul.f32 s0, s19, s15 */
/* @0x148d9c vmul.f32 s15, s15, s14 */
/* @0x148da0 vmov s4, r0 */
/* @0x148da4 mov r0, r5 */
/* @0x148da8 vnmul.f32 s12, s25, s4 */
/* @0x148dac vmul.f32 s10, s12, s14 */
/* @0x148db0 vmul.f32 s12, s19, s12 */
/* @0x148db4 vmla.f32 s12, s26, s21 */
/* @0x148db8 vmla.f32 s10, s19, s21 */
/* @0x148dbc vmla.f32 s15, s19, s4 */
/* @0x148dc0 vmla.f32 s0, s26, s4 */
/* @0x148dc4 vmul.f32 s14, s20, s14 */
/* @0x148dc8 vmul.f32 s12, s24, s12 */
/* @0x148dcc vmul.f32 s4, s20, s4 */
/* @0x148dd0 vnmul.f32 s2, s21, s20 */
/* @0x148dd4 vmul.f32 s6, s20, s19 */
/* @0x148dd8 vmul.f32 s10, s24, s10 */
/* @0x148ddc vmul.f32 s14, s23, s14 */
/* @0x148de0 vcvt.f64.f32 d6, s12 */
/* @0x148de4 vmul.f32 s0, s22, s0 */
/* @0x148de8 vstr d6, [sp, #64] */
/* @0x148dec vmul.f32 s8, s23, s25 */
/* @0x148df0 vmul.f32 s4, s24, s4 */
/* @0x148df4 vmul.f32 s2, s22, s2 */
/* @0x148df8 vmul.f32 s6, s23, s6 */
/* @0x148dfc vmul.f32 s22, s22, s15 */
/* @0x148e00 vcvt.f64.f32 d6, s17 */
/* @0x148e04 vcvt.f64.f32 d5, s10 */
/* @0x148e08 vstr d6, [sp, #96] */
/* @0x148e0c vcvt.f64.f32 d7, s14 */
/* @0x148e10 vstr d5, [sp] */
/* @0x148e14 vcvt.f64.f32 d0, s0 */
/* @0x148e18 vstr d7, [sp, #8] */
/* @0x148e1c vcvt.f64.f32 d1, s2 */
/* @0x148e20 vstr d0, [sp, #56] */
/* @0x148e24 vcvt.f64.f32 d2, s4 */
/* @0x148e28 vstr d1, [sp, #24] */
/* @0x148e2c vcvt.f64.f32 d3, s6 */
/* @0x148e30 vstr d2, [sp, #32] */
/* @0x148e34 vcvt.f64.f32 d4, s8 */
/* @0x148e38 vstr d3, [sp, #72] */
/* @0x148e3c vcvt.f64.f32 d5, s18 */
/* @0x148e40 vstr d4, [sp, #40] */
/* @0x148e44 vcvt.f64.f32 d7, s16 */
/* @0x148e48 vstr d5, [sp, #88] */
/* @0x148e4c vcvt.f64.f32 d6, s22 */
/* @0x148e50 vstr d7, [sp, #104] */
/* @0x148e54 vmov r2, r3, d6 */
/* @0x148e58 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x148e5c add sp, sp, #124 */
/* @0x148e60 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x148e64 pop {r4, r5, pc} */
/* @0x148e68 vstmialo lr, {s30, s31} */
/* @0x148e6c andseq r9, pc, r4, asr #19 */

/* ── FUNC 0x148e70 · F_D3DMatrixStackPush(RValue&, CInstance*, CInstance*, int, RValue*) · size=416 · insn=104 */
/* @0x148e70 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x148e74 sub sp, sp, #132 */
/* @0x148e78 ldr r6, [pc, #0x178] */
/* @0x148e7c ldr r2, [pc, #0x178] */
/* @0x148e80 add r6, pc, r6 */
/* @0x148e84 ldr r7, [r6, r2] */
/* @0x148e88 ldr r4, [r7] */
/* @0x148e8c cmp r4, #49 */
/* @0x148e90 bgt 0x148f24 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x148e94 cmp r3, #0 */
/* @0x148e98 add r2, r4, #1 */
/* @0x148e9c str r2, [r7] */
/* @0x148ea0 beq 0x148eec <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x148ea4 cmp r3, #1 */
/* @0x148ea8 beq 0x148f84 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x148eac ldr r1, [sp, #0xa0] */
/* @0x148eb0 ldr r3, [r1] */
/* @0x148eb4 cmp r3, #0 */
/* @0x148eb8 beq 0x148ed4 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x148ebc ldr r3, [r3, #0x4] */
/* @0x148ec0 cmp r3, #0 */
/* @0x148ec4 beq 0x148ed4 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x148ec8 ldr r2, [r3] */
/* @0x148ecc cmp r2, #16 */
/* @0x148ed0 beq 0x148f3c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x148ed4 ldr r0, [pc, #0x124] */
/* @0x148ed8 mov r1, #1 */
/* @0x148edc add r0, pc, r0 */
/* @0x148ee0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148ee4 add sp, sp, #132 */
/* @0x148ee8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x148eec ldr r3, [pc, #0x110] */
/* @0x148ef0 ldr r12, [r6, r3] */
/* @0x148ef4 add r4, r12, r4, lsl #6 */
/* @0x148ef8 add r12, r12, r2, lsl #6 */
/* @0x148efc ldm r4!, {r0, r1, r2, r3} */
/* @0x148f00 stm r12!, {r0, r1, r2, r3} */
/* @0x148f04 ldm r4!, {r0, r1, r2, r3} */
/* @0x148f08 stm r12!, {r0, r1, r2, r3} */
/* @0x148f0c ldm r4!, {r0, r1, r2, r3} */
/* @0x148f10 stm r12!, {r0, r1, r2, r3} */
/* @0x148f14 ldm r4, {r0, r1, r2, r3} */
/* @0x148f18 stm r12, {r0, r1, r2, r3} */
/* @0x148f1c add sp, sp, #132 */
/* @0x148f20 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x148f24 ldr r0, [pc, #0xdc] */
/* @0x148f28 mov r1, #1 */
/* @0x148f2c add r0, pc, r0 */
/* @0x148f30 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148f34 add sp, sp, #132 */
/* @0x148f38 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x148f3c ldr r4, [r3, #0x4] */
/* @0x148f40 add r9, sp, #64 */
/* @0x148f44 mov r5, sp */
/* @0x148f48 b 0x148f68 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x148f4c ldm r4, {r0, r1} */
/* @0x148f50 vmov d6, r0, r1 */
/* @0x148f54 add r4, r4, #16 */
/* @0x148f58 vcvt.f32.f64 s15, d6 */
/* @0x148f5c vstmia r5!, {s15} */
/* @0x148f60 cmp r5, r9 */
/* @0x148f64 beq 0x148fac <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x148f68 ldr r3, [r4, #0xc] */
/* @0x148f6c bic r3, r3, #-16777216 */
/* @0x148f70 cmp r3, #0 */
/* @0x148f74 beq 0x148f4c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x148f78 mov r0, r4 */
/* @0x148f7c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x148f80 b 0x148f50 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x148f84 ldr r1, [sp, #0xa0] */
/* @0x148f88 ldr r3, [r1, #0xc] */
/* @0x148f8c bic r3, r3, #-16777216 */
/* @0x148f90 cmp r3, #2 */
/* @0x148f94 beq 0x148eac <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x148f98 ldr r0, [pc, #0x6c] */
/* @0x148f9c mov r1, #0 */
/* @0x148fa0 add r0, pc, r0 */
/* @0x148fa4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x148fa8 b 0x148f1c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x148fac ldr r3, [pc, #0x50] */
/* @0x148fb0 mov r1, sp */
/* @0x148fb4 ldr r2, [r7] */
/* @0x148fb8 mov r0, r5 */
/* @0x148fbc ldr r4, [r6, r3] */
/* @0x148fc0 sub r2, r2, #1 */
/* @0x148fc4 add r2, r4, r2, lsl #6 */
/* @0x148fc8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x148fcc ldm r5!, {r0, r1, r2, r3} */
/* @0x148fd0 ldr r12, [r7] */
/* @0x148fd4 add r12, r4, r12, lsl #6 */
/* @0x148fd8 stm r12!, {r0, r1, r2, r3} */
/* @0x148fdc ldm r5!, {r0, r1, r2, r3} */
/* @0x148fe0 stm r12!, {r0, r1, r2, r3} */
/* @0x148fe4 ldm r5!, {r0, r1, r2, r3} */
/* @0x148fe8 stm r12!, {r0, r1, r2, r3} */
/* @0x148fec ldm r5, {r0, r1, r2, r3} */
/* @0x148ff0 stm r12, {r0, r1, r2, r3} */
/* @0x148ff4 b 0x148f1c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x148ff8 .word 0x002a8dd0 */
/* @0x148ffc .word 0xffffd9b4 */
/* @0x149000 mulseq pc, r12, r7 */
/* @0x149004 .word 0xffffd9b8 */
/* @0x149008 andseq r9, pc, r8, lsr #14 */
/* @0x14900c andseq r9, pc, r4, lsl #14 */
