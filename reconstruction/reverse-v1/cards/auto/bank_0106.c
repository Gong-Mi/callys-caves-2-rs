/* libyoyo.so 覆盖卡组 0106
 * 函数 0x169f1c..0x16c0d8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x169f1c · GR_Draw_Get_Alpha() · size=40 · insn=10 */
/* @0x169f1c ldr r3, [pc, #0x1c] */
/* @0x169f20 vldr s15, [pc, #20] */
/* @0x169f24 ldr r3, [pc, r3] */
/* @0x169f28 vldr s14, [r3] */
/* @0x169f2c vcvt.f32.u32 s14, s14 */
/* @0x169f30 vdiv.f32 s15, s14, s15 */
/* @0x169f34 vmov r0, s15 */
/* @0x169f38 bx lr */
/* @0x169f3c cmnmi pc, #0 */
/* @0x169f40 .word 0x00283ddc */

/* ── FUNC 0x169f44 · GR_Draw_Get_D3DColor() · size=20 · insn=5 */
/* @0x169f44 ldr r3, [pc, #0x8] */
/* @0x169f48 ldr r3, [pc, r3] */
/* @0x169f4c ldr r0, [r3] */
/* @0x169f50 bx lr */
/* @0x169f54 .word 0x00283db4 */

/* ── FUNC 0x169f58 · GR_Draw_Clear(unsigned int) · size=332 · insn=83 */
/* @0x169f58 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x169f5c mov r5, r0 */
/* @0x169f60 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x169f64 ldr r4, [pc, #0x120] */
/* @0x169f68 ldr r3, [pc, #0x120] */
/* @0x169f6c add r4, pc, r4 */
/* @0x169f70 ldr r3, [r4, r3] */
/* @0x169f74 ldr r0, [r3] */
/* @0x169f78 cmn r0, #1 */
/* @0x169f7c beq 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x169f80 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x169f84 subs r7, r0, #0 */
/* @0x169f88 beq 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x169f8c ldr r3, [pc, #0x100] */
/* @0x169f90 ldr r6, [r4, r3] */
/* @0x169f94 ldr r3, [r6] */
/* @0x169f98 cmp r3, #0 */
/* @0x169f9c bne 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x169fa0 ldr r3, [pc, #0xf0] */
/* @0x169fa4 ldr r8, [r4, r3] */
/* @0x169fa8 ldr r3, [r8] */
/* @0x169fac cmp r3, #0 */
/* @0x169fb0 bne 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x169fb4 ldr r3, [pc, #0xe0] */
/* @0x169fb8 ldr r2, [r7, #0x8] */
/* @0x169fbc ldr r9, [r4, r3] */
/* @0x169fc0 ldr r3, [r9] */
/* @0x169fc4 cmp r2, r3 */
/* @0x169fc8 beq 0x169fe4 <_Z13GR_Draw_Clearj+0x8c> */
/* @0x169fcc mov r0, r5 */
/* @0x169fd0 mov r1, #1065353216 */
/* @0x169fd4 mov r2, #0 */
/* @0x169fd8 mov r3, #7 */
/* @0x169fdc pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x169fe0 b 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x169fe4 ldr r3, [pc, #0xb4] */
/* @0x169fe8 ldr r2, [r7, #0xc] */
/* @0x169fec ldr r4, [r4, r3] */
/* @0x169ff0 ldr r3, [r4] */
/* @0x169ff4 cmp r2, r3 */
/* @0x169ff8 bne 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x169ffc ldr r0, [r7, #0x4] */
/* @0x16a000 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x16a004 cmp r0, #0 */
/* @0x16a008 beq 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x16a00c ldr r2, [r0, #0x4] */
/* @0x16a010 ldr r1, [r7, #0x8] */
/* @0x16a014 ldr r3, [r0, #0x8] */
/* @0x16a018 cmp r2, r1 */
/* @0x16a01c ldr r0, [r7, #0xc] */
/* @0x16a020 bne 0x16a02c <_Z13GR_Draw_Clearj+0xd4> */
/* @0x16a024 cmp r3, r0 */
/* @0x16a028 beq 0x169fcc <_Z13GR_Draw_Clearj+0x74> */
/* @0x16a02c add r12, r0, #1 */
/* @0x16a030 ldr r10, [r6] */
/* @0x16a034 mov r0, #0 */
/* @0x16a038 ldr r7, [r8] */
/* @0x16a03c ldr r6, [r9] */
/* @0x16a040 add r1, r1, #1 */
/* @0x16a044 ldr r4, [r4] */
/* @0x16a048 cmp r2, r1 */
/* @0x16a04c movge r2, r1 */
/* @0x16a050 cmp r3, r12 */
/* @0x16a054 movge r3, r12 */
/* @0x16a058 mov r1, r0 */
/* @0x16a05c bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x16a060 mov r0, r5 */
/* @0x16a064 mov r1, #1065353216 */
/* @0x16a068 mov r2, #0 */
/* @0x16a06c mov r3, #7 */
/* @0x16a070 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x16a074 mov r0, r10 */
/* @0x16a078 mov r1, r7 */
/* @0x16a07c mov r2, r6 */
/* @0x16a080 mov r3, r4 */
/* @0x16a084 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16a088 b 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x16a08c eoreq r7, r8, r4, ror #25 */
/* @0x16a090 .word 0xffffe51c */
/* @0x16a094 .word 0xffffe4ec */
/* @0x16a098 .word 0xffffe4f0 */
/* @0x16a09c .word 0xffffe4f4 */
/* @0x16a0a0 .word 0xffffe4f8 */

/* ── FUNC 0x16a0a4 · GR_Draw_Clear_Alpha(unsigned int, float) · size=28 · insn=7 */
/* @0x16a0a4 push {r4, lr} */
/* @0x16a0a8 mov r4, r0 */
/* @0x16a0ac mov r0, r1 */
/* @0x16a0b0 bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x16a0b4 orr r0, r4, r0, lsl #24 */
/* @0x16a0b8 pop {r4, lr} */
/* @0x16a0bc b 0x169f58 <_Z13GR_Draw_Clearj> */

/* ── FUNC 0x16a0c0 · YYGML_draw_point(float, float) · size=168 · insn=42 */
/* @0x16a0c0 push {r4, lr} */
/* @0x16a0c4 vpush {d8} */
/* @0x16a0c8 vmov s17, r1 */
/* @0x16a0cc ldr r4, [pc, #0x7c] */
/* @0x16a0d0 vmov s16, r0 */
/* @0x16a0d4 ldr r12, [pc, #0x78] */
/* @0x16a0d8 mov r0, #1 */
/* @0x16a0dc add r4, pc, r4 */
/* @0x16a0e0 mov r3, r0 */
/* @0x16a0e4 mov r2, #16 */
/* @0x16a0e8 ldr r1, [r4, r12] */
/* @0x16a0ec ldr r1, [r1] */
/* @0x16a0f0 ldr r1, [r1] */
/* @0x16a0f4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a0f8 ldr r1, [pc, #0x58] */
/* @0x16a0fc ldr r3, [pc, #0x58] */
/* @0x16a100 vldr s15, [pc, #68] */
/* @0x16a104 ldr r2, [pc, #0x54] */
/* @0x16a108 ldr r1, [r4, r1] */
/* @0x16a10c vldr s14, [r1] */
/* @0x16a110 ldr r3, [r4, r3] */
/* @0x16a114 vmla.f32 s17, s14, s15 */
/* @0x16a118 vldr s14, [r3] */
/* @0x16a11c ldr r3, [pc, #0x40] */
/* @0x16a120 vmla.f32 s16, s14, s15 */
/* @0x16a124 vstr s17, [r0, #4] */
/* @0x16a128 vstr s16, [r0] */
/* @0x16a12c ldr r2, [r4, r2] */
/* @0x16a130 vpop {d8} */
/* @0x16a134 ldr r2, [r2] */
/* @0x16a138 str r2, [r0, #0x8] */
/* @0x16a13c ldr r3, [r4, r3] */
/* @0x16a140 ldr r3, [r3] */
/* @0x16a144 str r3, [r0, #0xc] */
/* @0x16a148 pop {r4, pc} */
/* @0x16a14c stclo p7, c13, [r3], #-40 */
/* @0x16a150 eoreq r7, r8, r4, ror r11 */
/* @0x16a154 .word 0xffffe4e0 */
/* @0x16a158 .word 0xffffe520 */
/* @0x16a15c .word 0xffffe524 */
/* @0x16a160 .word 0xffffbcd0 */
/* @0x16a164 .word 0xffffc0ac */

/* ── FUNC 0x16a168 · YYGML_draw_point_ext(float, float, unsigned int) · size=180 · insn=45 */
/* @0x16a168 push {r3, r4, r5, lr} */
/* @0x16a16c vpush {d8} */
/* @0x16a170 vmov s17, r1 */
/* @0x16a174 ldr r4, [pc, #0x88] */
/* @0x16a178 vmov s16, r0 */
/* @0x16a17c ldr r12, [pc, #0x84] */
/* @0x16a180 mov r0, #1 */
/* @0x16a184 add r4, pc, r4 */
/* @0x16a188 mov r5, r2 */
/* @0x16a18c mov r3, r0 */
/* @0x16a190 mov r2, #16 */
/* @0x16a194 ldr r1, [r4, r12] */
/* @0x16a198 bic r5, r5, #-16777216 */
/* @0x16a19c ldr r1, [r1] */
/* @0x16a1a0 ldr r1, [r1] */
/* @0x16a1a4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a1a8 ldr r1, [pc, #0x5c] */
/* @0x16a1ac ldr r3, [pc, #0x5c] */
/* @0x16a1b0 vldr s15, [pc, #72] */
/* @0x16a1b4 ldr r2, [pc, #0x58] */
/* @0x16a1b8 ldr r1, [r4, r1] */
/* @0x16a1bc vldr s14, [r1] */
/* @0x16a1c0 ldr r3, [r4, r3] */
/* @0x16a1c4 vmla.f32 s17, s14, s15 */
/* @0x16a1c8 vldr s14, [r3] */
/* @0x16a1cc ldr r3, [pc, #0x44] */
/* @0x16a1d0 vmla.f32 s16, s14, s15 */
/* @0x16a1d4 vstr s17, [r0, #4] */
/* @0x16a1d8 vstr s16, [r0] */
/* @0x16a1dc ldr r2, [r4, r2] */
/* @0x16a1e0 vpop {d8} */
/* @0x16a1e4 ldr r2, [r2] */
/* @0x16a1e8 str r2, [r0, #0x8] */
/* @0x16a1ec ldr r3, [r4, r3] */
/* @0x16a1f0 ldr r3, [r3] */
/* @0x16a1f4 orr r5, r5, r3, lsl #24 */
/* @0x16a1f8 str r5, [r0, #0xc] */
/* @0x16a1fc pop {r3, r4, r5, pc} */
/* @0x16a200 stclo p7, c13, [r3], #-40 */
/* @0x16a204 eoreq r7, r8, r12, asr #21 */
/* @0x16a208 .word 0xffffe4e0 */
/* @0x16a20c .word 0xffffe520 */
/* @0x16a210 .word 0xffffe524 */
/* @0x16a214 .word 0xffffbcd0 */
/* @0x16a218 .word 0xffffc0b0 */

/* ── FUNC 0x16a21c · GR_Draw_Line(float, float, float, float) · size=208 · insn=52 */
/* @0x16a21c push {r4, lr} */
/* @0x16a220 vpush {d8, d9} */
/* @0x16a224 vmov s18, r1 */
/* @0x16a228 ldr r4, [pc, #0xa4] */
/* @0x16a22c vmov s19, r0 */
/* @0x16a230 ldr r12, [pc, #0xa0] */
/* @0x16a234 mov r0, #2 */
/* @0x16a238 add r4, pc, r4 */
/* @0x16a23c vmov s16, r3 */
/* @0x16a240 vmov s17, r2 */
/* @0x16a244 mov r3, r0 */
/* @0x16a248 ldr r1, [r4, r12] */
/* @0x16a24c mov r2, #16 */
/* @0x16a250 ldr r1, [r1] */
/* @0x16a254 ldr r1, [r1] */
/* @0x16a258 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a25c ldr r1, [pc, #0x78] */
/* @0x16a260 ldr r2, [pc, #0x78] */
/* @0x16a264 vldr s13, [pc, #100] */
/* @0x16a268 ldr r3, [pc, #0x74] */
/* @0x16a26c ldr r1, [r4, r1] */
/* @0x16a270 vldr s14, [r1] */
/* @0x16a274 ldr r2, [r4, r2] */
/* @0x16a278 vmul.f32 s14, s14, s13 */
/* @0x16a27c vldr s15, [r2] */
/* @0x16a280 ldr r2, [pc, #0x60] */
/* @0x16a284 vmul.f32 s15, s15, s13 */
/* @0x16a288 vadd.f32 s19, s14, s19 */
/* @0x16a28c vadd.f32 s18, s15, s18 */
/* @0x16a290 vstr s19, [r0] */
/* @0x16a294 vstr s18, [r0, #4] */
/* @0x16a298 ldr r3, [r4, r3] */
/* @0x16a29c vadd.f32 s14, s14, s17 */
/* @0x16a2a0 ldr r3, [r3] */
/* @0x16a2a4 str r3, [r0, #0x8] */
/* @0x16a2a8 ldr r2, [r4, r2] */
/* @0x16a2ac str r3, [r0, #0x18] */
/* @0x16a2b0 ldr r3, [r2] */
/* @0x16a2b4 vadd.f32 s15, s15, s16 */
/* @0x16a2b8 vstr s14, [r0, #16] */
/* @0x16a2bc vpop {d8, d9} */
/* @0x16a2c0 str r3, [r0, #0xc] */
/* @0x16a2c4 str r3, [r0, #0x1c] */
/* @0x16a2c8 vstr s15, [r0, #20] */
/* @0x16a2cc pop {r4, pc} */
/* @0x16a2d0 stclo p7, c13, [r3], #-40 */
/* @0x16a2d4 eoreq r7, r8, r8, lsl r10 */
/* @0x16a2d8 .word 0xffffe4e0 */
/* @0x16a2dc .word 0xffffe524 */
/* @0x16a2e0 .word 0xffffe520 */
/* @0x16a2e4 .word 0xffffbcd0 */
/* @0x16a2e8 .word 0xffffc0ac */

/* ── FUNC 0x16a2ec · GR_Draw_Line_Width(float, float, float, float, float) · size=368 · insn=92 */
/* @0x16a2ec push {r4, lr} */
/* @0x16a2f0 vpush {d8, d9, d10} */
/* @0x16a2f4 vmov s18, r1 */
/* @0x16a2f8 vmov s17, r3 */
/* @0x16a2fc ldr r4, [pc, #0x140] */
/* @0x16a300 vmov s20, r0 */
/* @0x16a304 vsub.f32 s15, s17, s18 */
/* @0x16a308 add r4, pc, r4 */
/* @0x16a30c vmov s19, r2 */
/* @0x16a310 vmul.f32 s15, s15, s15 */
/* @0x16a314 vsub.f32 s14, s19, s20 */
/* @0x16a318 vmla.f32 s15, s14, s14 */
/* @0x16a31c vsqrt.f32 s16, s15 */
/* @0x16a320 vcmp.f32 s16, s16 */
/* @0x16a324 vmrs APSR_nzcv, fpscr */
/* @0x16a328 bne 0x16a430 <_Z18GR_Draw_Line_Widthfffff+0x144> */
/* @0x16a32c vcmp.f32 s16, #0 */
/* @0x16a330 vmrs APSR_nzcv, fpscr */
/* @0x16a334 beq 0x16a428 <_Z18GR_Draw_Line_Widthfffff+0x13c> */
/* @0x16a338 ldr r1, [pc, #0x108] */
/* @0x16a33c mov r2, #16 */
/* @0x16a340 mov r3, #4 */
/* @0x16a344 mov r0, #6 */
/* @0x16a348 ldr r1, [r4, r1] */
/* @0x16a34c ldr r1, [r1] */
/* @0x16a350 ldr r1, [r1] */
/* @0x16a354 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a358 ldr r1, [pc, #0xec] */
/* @0x16a35c ldr r2, [pc, #0xec] */
/* @0x16a360 vldr s13, [pc, #216] */
/* @0x16a364 vmov.f32 s14, #5.000000e-01 */
/* @0x16a368 ldr r3, [pc, #0xe4] */
/* @0x16a36c ldr r1, [r4, r1] */
/* @0x16a370 vldr s15, [r1] */
/* @0x16a374 ldr r2, [r4, r2] */
/* @0x16a378 vldr s12, [r2] */
/* @0x16a37c ldr r2, [pc, #0xd4] */
/* @0x16a380 vmul.f32 s15, s15, s13 */
/* @0x16a384 vmul.f32 s13, s12, s13 */
/* @0x16a388 vadd.f32 s20, s15, s20 */
/* @0x16a38c vadd.f32 s19, s19, s15 */
/* @0x16a390 vldr s15, [sp, #32] */
/* @0x16a394 vadd.f32 s18, s13, s18 */
/* @0x16a398 vadd.f32 s17, s17, s13 */
/* @0x16a39c vmul.f32 s14, s15, s14 */
/* @0x16a3a0 vsub.f32 s13, s19, s20 */
/* @0x16a3a4 vsub.f32 s15, s17, s18 */
/* @0x16a3a8 vmul.f32 s15, s14, s15 */
/* @0x16a3ac vmul.f32 s14, s14, s13 */
/* @0x16a3b0 vdiv.f32 s15, s15, s16 */
/* @0x16a3b4 vdiv.f32 s16, s14, s16 */
/* @0x16a3b8 vadd.f32 s14, s18, s16 */
/* @0x16a3bc vsub.f32 s13, s20, s15 */
/* @0x16a3c0 vstr s14, [r0, #4] */
/* @0x16a3c4 vsub.f32 s14, s19, s15 */
/* @0x16a3c8 vstr s13, [r0] */
/* @0x16a3cc ldr r3, [r4, r3] */
/* @0x16a3d0 ldr r3, [r3] */
/* @0x16a3d4 str r3, [r0, #0x8] */
/* @0x16a3d8 ldr r2, [r4, r2] */
/* @0x16a3dc str r3, [r0, #0x18] */
/* @0x16a3e0 vsub.f32 s18, s18, s16 */
/* @0x16a3e4 vstr s14, [r0, #16] */
/* @0x16a3e8 str r3, [r0, #0x28] */
/* @0x16a3ec str r3, [r0, #0x38] */
/* @0x16a3f0 ldr r3, [r2] */
/* @0x16a3f4 str r3, [r0, #0xc] */
/* @0x16a3f8 str r3, [r0, #0x1c] */
/* @0x16a3fc str r3, [r0, #0x2c] */
/* @0x16a400 str r3, [r0, #0x3c] */
/* @0x16a404 vadd.f32 s14, s17, s16 */
/* @0x16a408 vstr s18, [r0, #52] */
/* @0x16a40c vadd.f32 s20, s20, s15 */
/* @0x16a410 vstr s14, [r0, #20] */
/* @0x16a414 vadd.f32 s19, s19, s15 */
/* @0x16a418 vstr s20, [r0, #48] */
/* @0x16a41c vsub.f32 s16, s17, s16 */
/* @0x16a420 vstr s19, [r0, #32] */
/* @0x16a424 vstr s16, [r0, #36] */
/* @0x16a428 vpop {d8, d9, d10} */
/* @0x16a42c pop {r4, pc} */
/* @0x16a430 vmov r0, s15 */
/* @0x16a434 bl 0xb6700 <sqrtf@plt> */
/* @0x16a438 vmov s16, r0 */
/* @0x16a43c b 0x16a32c <_Z18GR_Draw_Line_Widthfffff+0x40> */
/* @0x16a440 stclo p7, c13, [r3], #-40 */
/* @0x16a444 eoreq r7, r8, r8, asr #18 */
/* @0x16a448 .word 0xffffe4e0 */
/* @0x16a44c .word 0xffffe524 */
/* @0x16a450 .word 0xffffe520 */
/* @0x16a454 .word 0xffffbcd0 */
/* @0x16a458 .word 0xffffc0ac */

/* ── FUNC 0x16a45c · GR_Draw_Line_Ext(float, float, float, float, unsigned int, unsigned int) · size=244 · insn=61 */
/* @0x16a45c push {r3, r4, r5, r6, r7, lr} */
/* @0x16a460 vpush {d8, d9} */
/* @0x16a464 vmov s18, r1 */
/* @0x16a468 ldr r5, [pc, #0xc8] */
/* @0x16a46c vmov s19, r0 */
/* @0x16a470 ldr r12, [pc, #0xc4] */
/* @0x16a474 mov r0, #2 */
/* @0x16a478 add r5, pc, r5 */
/* @0x16a47c vmov s16, r3 */
/* @0x16a480 vmov s17, r2 */
/* @0x16a484 mov r3, r0 */
/* @0x16a488 ldr r1, [r5, r12] */
/* @0x16a48c mov r2, #16 */
/* @0x16a490 ldr r6, [sp, #0x28] */
/* @0x16a494 ldr r7, [sp, #0x2c] */
/* @0x16a498 ldr r1, [r1] */
/* @0x16a49c ldr r1, [r1] */
/* @0x16a4a0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a4a4 ldr r1, [pc, #0x94] */
/* @0x16a4a8 ldr r3, [pc, #0x94] */
/* @0x16a4ac vldr s13, [pc, #128] */
/* @0x16a4b0 ldr r2, [pc, #0x90] */
/* @0x16a4b4 ldr r1, [r5, r1] */
/* @0x16a4b8 vldr s14, [r1] */
/* @0x16a4bc ldr r3, [r5, r3] */
/* @0x16a4c0 vmul.f32 s14, s14, s13 */
/* @0x16a4c4 vldr s15, [r3] */
/* @0x16a4c8 ldr r3, [pc, #0x7c] */
/* @0x16a4cc vmul.f32 s15, s15, s13 */
/* @0x16a4d0 vadd.f32 s19, s14, s19 */
/* @0x16a4d4 mov r4, r0 */
/* @0x16a4d8 mov r0, r6 */
/* @0x16a4dc vadd.f32 s18, s15, s18 */
/* @0x16a4e0 vstr s19, [r4] */
/* @0x16a4e4 vstr s18, [r4, #4] */
/* @0x16a4e8 ldr r6, [r5, r2] */
/* @0x16a4ec vadd.f32 s17, s14, s17 */
/* @0x16a4f0 ldr r2, [r6] */
/* @0x16a4f4 str r2, [r4, #0x8] */
/* @0x16a4f8 ldr r5, [r5, r3] */
/* @0x16a4fc ldr r1, [r5] */
/* @0x16a500 vadd.f32 s16, s15, s16 */
/* @0x16a504 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a508 ldr r3, [r6] */
/* @0x16a50c vstr s17, [r4, #16] */
/* @0x16a510 ldr r1, [r5] */
/* @0x16a514 str r3, [r4, #0x18] */
/* @0x16a518 vstr s16, [r4, #20] */
/* @0x16a51c str r0, [r4, #0xc] */
/* @0x16a520 mov r0, r7 */
/* @0x16a524 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a528 vpop {d8, d9} */
/* @0x16a52c str r0, [r4, #0x1c] */
/* @0x16a530 pop {r3, r4, r5, r6, r7, pc} */
/* @0x16a534 stclo p7, c13, [r3], #-40 */
/* @0x16a538 .word 0x002877d8 */
/* @0x16a53c .word 0xffffe4e0 */
/* @0x16a540 .word 0xffffe524 */
/* @0x16a544 .word 0xffffe520 */
/* @0x16a548 .word 0xffffbcd0 */
/* @0x16a54c .word 0xffffc0b0 */

/* ── FUNC 0x16a550 · GR_Draw_Line_Width_Ext(float, float, float, float, float, unsigned int, unsigned int) · size=416 · insn=104 */
/* @0x16a550 push {r4, r5, r6, r7, r8, lr} */
/* @0x16a554 vpush {d8, d9, d10, d11, d12} */
/* @0x16a558 vmov s18, r1 */
/* @0x16a55c vldr s23, [sp, #64] */
/* @0x16a560 ldr r5, [pc, #0x170] */
/* @0x16a564 vmov s19, r0 */
/* @0x16a568 ldr r1, [pc, #0x16c] */
/* @0x16a56c vmov s24, r2 */
/* @0x16a570 add r5, pc, r5 */
/* @0x16a574 vmov s17, r3 */
/* @0x16a578 mov r2, #16 */
/* @0x16a57c mov r3, #4 */
/* @0x16a580 ldr r1, [r5, r1] */
/* @0x16a584 mov r0, #6 */
/* @0x16a588 ldr r7, [sp, #0x44] */
/* @0x16a58c ldr r8, [sp, #0x48] */
/* @0x16a590 ldr r1, [r1] */
/* @0x16a594 ldr r1, [r1] */
/* @0x16a598 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a59c ldr r2, [pc, #0x13c] */
/* @0x16a5a0 vldr s14, [pc, #300] */
/* @0x16a5a4 ldr r3, [pc, #0x138] */
/* @0x16a5a8 ldr r2, [r5, r2] */
/* @0x16a5ac vldr s20, [r2] */
/* @0x16a5b0 vmul.f32 s20, s20, s14 */
/* @0x16a5b4 ldr r3, [r5, r3] */
/* @0x16a5b8 vldr s21, [r3] */
/* @0x16a5bc vadd.f32 s18, s20, s18 */
/* @0x16a5c0 vmul.f32 s21, s21, s14 */
/* @0x16a5c4 mov r4, r0 */
/* @0x16a5c8 vadd.f32 s20, s20, s17 */
/* @0x16a5cc vsub.f32 s22, s20, s18 */
/* @0x16a5d0 vadd.f32 s19, s21, s19 */
/* @0x16a5d4 vadd.f32 s21, s21, s24 */
/* @0x16a5d8 vmul.f32 s14, s22, s22 */
/* @0x16a5dc vsub.f32 s16, s21, s19 */
/* @0x16a5e0 vmla.f32 s14, s16, s16 */
/* @0x16a5e4 vsqrt.f32 s15, s14 */
/* @0x16a5e8 vcmp.f32 s15, s15 */
/* @0x16a5ec vmrs APSR_nzcv, fpscr */
/* @0x16a5f0 bne 0x16a6c4 <_Z22GR_Draw_Line_Width_Extfffffjj+0x174> */
/* @0x16a5f4 vmov.f32 s17, #5.000000e-01 */
/* @0x16a5f8 ldr r2, [pc, #0xe8] */
/* @0x16a5fc ldr r3, [pc, #0xe8] */
/* @0x16a600 mov r0, r7 */
/* @0x16a604 vmul.f32 s17, s23, s17 */
/* @0x16a608 vmul.f32 s16, s16, s17 */
/* @0x16a60c vmul.f32 s17, s22, s17 */
/* @0x16a610 vdiv.f32 s16, s16, s15 */
/* @0x16a614 vdiv.f32 s17, s17, s15 */
/* @0x16a618 vadd.f32 s14, s18, s16 */
/* @0x16a61c vsub.f32 s15, s19, s17 */
/* @0x16a620 vstr s14, [r4, #4] */
/* @0x16a624 vstr s15, [r4] */
/* @0x16a628 ldr r6, [r5, r2] */
/* @0x16a62c ldr r2, [r6] */
/* @0x16a630 str r2, [r4, #0x8] */
/* @0x16a634 ldr r5, [r5, r3] */
/* @0x16a638 ldr r1, [r5] */
/* @0x16a63c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a640 vsub.f32 s14, s21, s17 */
/* @0x16a644 ldr r3, [r6] */
/* @0x16a648 ldr r1, [r5] */
/* @0x16a64c str r3, [r4, #0x18] */
/* @0x16a650 vadd.f32 s15, s20, s16 */
/* @0x16a654 vstr s14, [r4, #16] */
/* @0x16a658 vstr s15, [r4, #20] */
/* @0x16a65c str r0, [r4, #0xc] */
/* @0x16a660 mov r0, r8 */
/* @0x16a664 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a668 vadd.f32 s21, s21, s17 */
/* @0x16a66c ldr r3, [r6] */
/* @0x16a670 ldr r1, [r5] */
/* @0x16a674 str r3, [r4, #0x28] */
/* @0x16a678 vsub.f32 s20, s20, s16 */
/* @0x16a67c vstr s21, [r4, #32] */
/* @0x16a680 vstr s20, [r4, #36] */
/* @0x16a684 str r0, [r4, #0x1c] */
/* @0x16a688 mov r0, r8 */
/* @0x16a68c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a690 vadd.f32 s17, s19, s17 */
/* @0x16a694 ldr r3, [r6] */
/* @0x16a698 ldr r1, [r5] */
/* @0x16a69c str r3, [r4, #0x38] */
/* @0x16a6a0 vsub.f32 s16, s18, s16 */
/* @0x16a6a4 vstr s17, [r4, #48] */
/* @0x16a6a8 vstr s16, [r4, #52] */
/* @0x16a6ac str r0, [r4, #0x2c] */
/* @0x16a6b0 mov r0, r7 */
/* @0x16a6b4 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a6b8 vpop {d8, d9, d10, d11, d12} */
/* @0x16a6bc str r0, [r4, #0x3c] */
/* @0x16a6c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16a6c4 vmov r0, s14 */
/* @0x16a6c8 bl 0xb6700 <sqrtf@plt> */
/* @0x16a6cc vmov s15, r0 */
/* @0x16a6d0 b 0x16a5f4 <_Z22GR_Draw_Line_Width_Extfffffjj+0xa4> */
/* @0x16a6d4 stclo p7, c13, [r3], #-40 */
/* @0x16a6d8 eoreq r7, r8, r0, ror #13 */
/* @0x16a6dc .word 0xffffe4e0 */
/* @0x16a6e0 .word 0xffffe520 */
/* @0x16a6e4 .word 0xffffe524 */
/* @0x16a6e8 .word 0xffffbcd0 */
/* @0x16a6ec .word 0xffffc0b0 */

/* ── FUNC 0x16a6f0 · GR_Draw_Triangle(float, float, float, float, float, float, bool) · size=364 · insn=91 */
/* @0x16a6f0 push {r3, r4, r5, lr} */
/* @0x16a6f4 vldr s13, [pc, #324] */
/* @0x16a6f8 vpush {d8, d9, d10} */
/* @0x16a6fc ldr r4, [pc, #0x140] */
/* @0x16a700 vldr s19, [sp, #40] */
/* @0x16a704 ldr r5, [pc, #0x13c] */
/* @0x16a708 vldr s18, [sp, #44] */
/* @0x16a70c add r4, pc, r4 */
/* @0x16a710 ldr lr, [pc, #0x134] */
/* @0x16a714 ldr r12, [pc, #0x134] */
/* @0x16a718 ldr r5, [r4, r5] */
/* @0x16a71c vldr s14, [r5] */
/* @0x16a720 vmul.f32 s14, s14, s13 */
/* @0x16a724 ldr lr, [r4, lr] */
/* @0x16a728 vldr s15, [lr] */
/* @0x16a72c ldrb lr, [sp, #0x30] */
/* @0x16a730 ldr r12, [r4, r12] */
/* @0x16a734 cmp lr, #0 */
/* @0x16a738 ldr r5, [r12] */
/* @0x16a73c vmul.f32 s15, s15, s13 */
/* @0x16a740 vmov s13, r0 */
/* @0x16a744 vadd.f32 s16, s14, s13 */
/* @0x16a748 vmov s13, r2 */
/* @0x16a74c vadd.f32 s19, s14, s19 */
/* @0x16a750 vadd.f32 s21, s14, s13 */
/* @0x16a754 vmov s14, r1 */
/* @0x16a758 ldr r1, [pc, #0xf4] */
/* @0x16a75c vmov s13, r3 */
/* @0x16a760 vadd.f32 s17, s15, s14 */
/* @0x16a764 vadd.f32 s20, s15, s13 */
/* @0x16a768 vadd.f32 s18, s15, s18 */
/* @0x16a76c bne 0x16a7d0 <_Z16GR_Draw_Triangleffffffb+0xe0> */
/* @0x16a770 ldr r1, [r4, r1] */
/* @0x16a774 mov r3, #3 */
/* @0x16a778 mov r0, #4 */
/* @0x16a77c mov r2, #24 */
/* @0x16a780 ldr r1, [r1] */
/* @0x16a784 ldr r1, [r1] */
/* @0x16a788 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a78c ldr r3, [pc, #0xc4] */
/* @0x16a790 ldr r3, [r4, r3] */
/* @0x16a794 ldr r3, [r3] */
/* @0x16a798 vstr s17, [r0, #4] */
/* @0x16a79c vstr s16, [r0] */
/* @0x16a7a0 vstr s21, [r0, #24] */
/* @0x16a7a4 vstr s20, [r0, #28] */
/* @0x16a7a8 vstr s19, [r0, #48] */
/* @0x16a7ac vstr s18, [r0, #52] */
/* @0x16a7b0 vpop {d8, d9, d10} */
/* @0x16a7b4 str r5, [r0, #0xc] */
/* @0x16a7b8 str r3, [r0, #0x8] */
/* @0x16a7bc str r3, [r0, #0x20] */
/* @0x16a7c0 str r3, [r0, #0x38] */
/* @0x16a7c4 str r5, [r0, #0x24] */
/* @0x16a7c8 str r5, [r0, #0x3c] */
/* @0x16a7cc pop {r3, r4, r5, pc} */
/* @0x16a7d0 ldr r1, [r4, r1] */
/* @0x16a7d4 mov r3, #4 */
/* @0x16a7d8 mov r0, #3 */
/* @0x16a7dc mov r2, #24 */
/* @0x16a7e0 ldr r1, [r1] */
/* @0x16a7e4 ldr r1, [r1] */
/* @0x16a7e8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a7ec ldr r3, [pc, #0x64] */
/* @0x16a7f0 ldr r3, [r4, r3] */
/* @0x16a7f4 ldr r3, [r3] */
/* @0x16a7f8 vstr s21, [r0, #24] */
/* @0x16a7fc vstr s16, [r0] */
/* @0x16a800 vstr s16, [r0, #72] */
/* @0x16a804 vstr s17, [r0, #4] */
/* @0x16a808 vstr s17, [r0, #76] */
/* @0x16a80c vstr s20, [r0, #28] */
/* @0x16a810 vstr s19, [r0, #48] */
/* @0x16a814 vstr s18, [r0, #52] */
/* @0x16a818 vpop {d8, d9, d10} */
/* @0x16a81c str r5, [r0, #0xc] */
/* @0x16a820 str r3, [r0, #0x8] */
/* @0x16a824 str r3, [r0, #0x50] */
/* @0x16a828 str r3, [r0, #0x20] */
/* @0x16a82c str r3, [r0, #0x38] */
/* @0x16a830 str r5, [r0, #0x54] */
/* @0x16a834 str r5, [r0, #0x24] */
/* @0x16a838 str r5, [r0, #0x3c] */
/* @0x16a83c pop {r3, r4, r5, pc} */
/* @0x16a840 stclo p7, c13, [r3], #-40 */
/* @0x16a844 eoreq r7, r8, r4, asr #10 */
/* @0x16a848 .word 0xffffe524 */
/* @0x16a84c .word 0xffffe520 */
/* @0x16a850 .word 0xffffc0ac */
/* @0x16a854 .word 0xffffe4e0 */
/* @0x16a858 .word 0xffffbcd0 */

/* ── FUNC 0x16a85c · GR_Draw_Triangle_Ext(float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, bool) · size=448 · insn=112 */
/* @0x16a85c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x16a860 vldr s13, [pc, #408] */
/* @0x16a864 vpush {d8, d9, d10} */
/* @0x16a868 ldr r5, [pc, #0x194] */
/* @0x16a86c vldr s19, [sp, #56] */
/* @0x16a870 ldr r4, [pc, #0x190] */
/* @0x16a874 vldr s18, [sp, #60] */
/* @0x16a878 add r5, pc, r5 */
/* @0x16a87c ldr lr, [pc, #0x188] */
/* @0x16a880 ldrb r12, [sp, #0x4c] */
/* @0x16a884 ldr r4, [r5, r4] */
/* @0x16a888 vldr s14, [r4] */
/* @0x16a88c vmul.f32 s14, s14, s13 */
/* @0x16a890 ldr lr, [r5, lr] */
/* @0x16a894 vldr s15, [lr] */
/* @0x16a898 cmp r12, #0 */
/* @0x16a89c ldr r8, [sp, #0x40] */
/* @0x16a8a0 ldr r7, [sp, #0x44] */
/* @0x16a8a4 ldr r6, [sp, #0x48] */
/* @0x16a8a8 vmul.f32 s15, s15, s13 */
/* @0x16a8ac vmov s13, r0 */
/* @0x16a8b0 vadd.f32 s17, s14, s13 */
/* @0x16a8b4 vmov s13, r2 */
/* @0x16a8b8 vadd.f32 s19, s14, s19 */
/* @0x16a8bc vadd.f32 s21, s14, s13 */
/* @0x16a8c0 vmov s14, r1 */
/* @0x16a8c4 ldr r1, [pc, #0x144] */
/* @0x16a8c8 vmov s13, r3 */
/* @0x16a8cc vadd.f32 s16, s15, s14 */
/* @0x16a8d0 vadd.f32 s20, s15, s13 */
/* @0x16a8d4 vadd.f32 s18, s15, s18 */
/* @0x16a8d8 bne 0x16a96c <_Z20GR_Draw_Triangle_Extffffffjjjb+0x110> */
/* @0x16a8dc ldr r1, [r5, r1] */
/* @0x16a8e0 mov r2, #24 */
/* @0x16a8e4 mov r3, #3 */
/* @0x16a8e8 mov r0, #4 */
/* @0x16a8ec ldr r1, [r1] */
/* @0x16a8f0 ldr r1, [r1] */
/* @0x16a8f4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a8f8 ldr r3, [pc, #0x114] */
/* @0x16a8fc ldr r2, [pc, #0x114] */
/* @0x16a900 vstr s17, [r0] */
/* @0x16a904 vstr s16, [r0, #4] */
/* @0x16a908 ldr r3, [r5, r3] */
/* @0x16a90c mov r4, r0 */
/* @0x16a910 mov r0, r8 */
/* @0x16a914 ldr r3, [r3] */
/* @0x16a918 str r3, [r4, #0x8] */
/* @0x16a91c str r3, [r4, #0x20] */
/* @0x16a920 str r3, [r4, #0x38] */
/* @0x16a924 ldr r5, [r5, r2] */
/* @0x16a928 ldr r1, [r5] */
/* @0x16a92c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a930 ldr r1, [r5] */
/* @0x16a934 vstr s21, [r4, #24] */
/* @0x16a938 vstr s20, [r4, #28] */
/* @0x16a93c str r0, [r4, #0xc] */
/* @0x16a940 mov r0, r7 */
/* @0x16a944 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a948 ldr r1, [r5] */
/* @0x16a94c vstr s19, [r4, #48] */
/* @0x16a950 vstr s18, [r4, #52] */
/* @0x16a954 str r0, [r4, #0x24] */
/* @0x16a958 mov r0, r6 */
/* @0x16a95c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a960 vpop {d8, d9, d10} */
/* @0x16a964 str r0, [r4, #0x3c] */
/* @0x16a968 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x16a96c ldr r1, [r5, r1] */
/* @0x16a970 mov r2, #24 */
/* @0x16a974 mov r3, #4 */
/* @0x16a978 mov r0, #3 */
/* @0x16a97c ldr r1, [r1] */
/* @0x16a980 ldr r1, [r1] */
/* @0x16a984 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16a988 ldr r3, [pc, #0x84] */
/* @0x16a98c ldr r2, [pc, #0x84] */
/* @0x16a990 vstr s17, [r0] */
/* @0x16a994 vstr s17, [r0, #72] */
/* @0x16a998 vstr s16, [r0, #4] */
/* @0x16a99c vstr s16, [r0, #76] */
/* @0x16a9a0 ldr r9, [r5, r3] */
/* @0x16a9a4 mov r4, r0 */
/* @0x16a9a8 ldr r3, [r9] */
/* @0x16a9ac str r3, [r0, #0x8] */
/* @0x16a9b0 str r3, [r0, #0x50] */
/* @0x16a9b4 mov r0, r8 */
/* @0x16a9b8 ldr r5, [r5, r2] */
/* @0x16a9bc ldr r1, [r5] */
/* @0x16a9c0 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a9c4 ldr r1, [r5] */
/* @0x16a9c8 vstr s21, [r4, #24] */
/* @0x16a9cc vstr s20, [r4, #28] */
/* @0x16a9d0 mov r3, r0 */
/* @0x16a9d4 str r3, [r4, #0x54] */
/* @0x16a9d8 ldr r3, [r9] */
/* @0x16a9dc str r0, [r4, #0xc] */
/* @0x16a9e0 mov r0, r7 */
/* @0x16a9e4 str r3, [r4, #0x20] */
/* @0x16a9e8 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16a9ec ldr r3, [r9] */
/* @0x16a9f0 ldr r1, [r5] */
/* @0x16a9f4 vstr s19, [r4, #48] */
/* @0x16a9f8 str r3, [r4, #0x38] */
/* @0x16a9fc b 0x16a950 <_Z20GR_Draw_Triangle_Extffffffjjjb+0xf4> */
/* @0x16aa00 stclo p7, c13, [r3], #-40 */
/* @0x16aa04 .word 0x002873d8 */
/* @0x16aa08 .word 0xffffe524 */
/* @0x16aa0c .word 0xffffe520 */
/* @0x16aa10 .word 0xffffe4e0 */
/* @0x16aa14 .word 0xffffbcd0 */
/* @0x16aa18 .word 0xffffc0b0 */

/* ── FUNC 0x16aa1c · YYGML_draw_rectangle(float, float, float, float, bool) · size=580 · insn=145 */
/* @0x16aa1c push {r4, r5, r6, lr} */
/* @0x16aa20 vpush {d8, d9} */
/* @0x16aa24 vmov s19, r2 */
/* @0x16aa28 vmov s16, r0 */
/* @0x16aa2c ldr r5, [pc, #0x214] */
/* @0x16aa30 vmov s17, r1 */
/* @0x16aa34 ldrb r2, [sp, #0x20] */
/* @0x16aa38 vcmpe.f32 s19, s16 */
/* @0x16aa3c add r5, pc, r5 */
/* @0x16aa40 vmov s18, r3 */
/* @0x16aa44 ldr r3, [pc, #0x200] */
/* @0x16aa48 ldr r1, [pc, #0x200] */
/* @0x16aa4c vmrs APSR_nzcv, fpscr */
/* @0x16aa50 vcmpe.f32 s18, s17 */
/* @0x16aa54 ldr r3, [r5, r3] */
/* @0x16aa58 vmovmi.f32 s15, s16 */
/* @0x16aa5c ldr r4, [r3] */
/* @0x16aa60 vmovmi.f32 s16, s19 */
/* @0x16aa64 vmovmi.f32 s19, s15 */
/* @0x16aa68 vmrs APSR_nzcv, fpscr */
/* @0x16aa6c vmovmi.f32 s15, s17 */
/* @0x16aa70 vmovmi.f32 s17, s18 */
/* @0x16aa74 vmovmi.f32 s18, s15 */
/* @0x16aa78 cmp r2, #0 */
/* @0x16aa7c bne 0x16ab30 <_Z20YYGML_draw_rectangleffffb+0x114> */
/* @0x16aa80 ldr r1, [r5, r1] */
/* @0x16aa84 mov r2, #24 */
/* @0x16aa88 mov r3, #6 */
/* @0x16aa8c mov r0, #4 */
/* @0x16aa90 ldr r1, [r1] */
/* @0x16aa94 ldr r1, [r1] */
/* @0x16aa98 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16aa9c ldr r1, [pc, #0x1b0] */
/* @0x16aaa0 ldr r2, [pc, #0x1b0] */
/* @0x16aaa4 ldr r3, [pc, #0x1b0] */
/* @0x16aaa8 ldr r1, [r5, r1] */
/* @0x16aaac vldr s15, [r1] */
/* @0x16aab0 ldr r2, [r5, r2] */
/* @0x16aab4 vadd.f32 s19, s19, s15 */
/* @0x16aab8 vldr s15, [r2] */
/* @0x16aabc ldr r3, [r5, r3] */
/* @0x16aac0 ldr r3, [r3] */
/* @0x16aac4 vadd.f32 s18, s18, s15 */
/* @0x16aac8 vstr s17, [r0, #4] */
/* @0x16aacc vstr s17, [r0, #28] */
/* @0x16aad0 vstr s16, [r0, #96] */
/* @0x16aad4 vstr s19, [r0, #24] */
/* @0x16aad8 vstr s19, [r0, #48] */
/* @0x16aadc vstr s19, [r0, #72] */
/* @0x16aae0 vstr s16, [r0, #120] */
/* @0x16aae4 vstr s17, [r0, #124] */
/* @0x16aae8 vstr s16, [r0] */
/* @0x16aaec vstr s18, [r0, #52] */
/* @0x16aaf0 vstr s18, [r0, #76] */
/* @0x16aaf4 vstr s18, [r0, #100] */
/* @0x16aaf8 vpop {d8, d9} */
/* @0x16aafc str r4, [r0, #0xc] */
/* @0x16ab00 str r4, [r0, #0x6c] */
/* @0x16ab04 str r3, [r0, #0x20] */
/* @0x16ab08 str r3, [r0, #0x38] */
/* @0x16ab0c str r3, [r0, #0x50] */
/* @0x16ab10 str r3, [r0, #0x8] */
/* @0x16ab14 str r3, [r0, #0x68] */
/* @0x16ab18 str r3, [r0, #0x80] */
/* @0x16ab1c str r4, [r0, #0x24] */
/* @0x16ab20 str r4, [r0, #0x3c] */
/* @0x16ab24 str r4, [r0, #0x54] */
/* @0x16ab28 str r4, [r0, #0x84] */
/* @0x16ab2c pop {r4, r5, r6, pc} */
/* @0x16ab30 ldr r6, [r5, r1] */
/* @0x16ab34 mov r2, #24 */
/* @0x16ab38 mov r3, #5 */
/* @0x16ab3c mov r0, #3 */
/* @0x16ab40 ldr r1, [r6] */
/* @0x16ab44 ldr r1, [r1] */
/* @0x16ab48 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16ab4c ldr lr, [pc, #0x100] */
/* @0x16ab50 ldr r1, [pc, #0x100] */
/* @0x16ab54 vldr s15, [pc, #232] */
/* @0x16ab58 ldr r3, [r6] */
/* @0x16ab5c mov r2, #24 */
/* @0x16ab60 ldr lr, [r5, lr] */
/* @0x16ab64 vldr s14, [lr] */
/* @0x16ab68 ldr r1, [r5, r1] */
/* @0x16ab6c vmul.f32 s14, s14, s15 */
/* @0x16ab70 vldr s13, [r1] */
/* @0x16ab74 ldr lr, [pc, #0xe0] */
/* @0x16ab78 ldr r1, [r3] */
/* @0x16ab7c mov r3, #4 */
/* @0x16ab80 ldr r5, [r5, lr] */
/* @0x16ab84 ldr lr, [r5] */
/* @0x16ab88 vmul.f32 s15, s13, s15 */
/* @0x16ab8c vadd.f32 s16, s14, s16 */
/* @0x16ab90 mov r12, r0 */
/* @0x16ab94 mov r0, #1 */
/* @0x16ab98 str r4, [r12, #0xc] */
/* @0x16ab9c str lr, [r12, #0x20] */
/* @0x16aba0 str r4, [r12, #0x6c] */
/* @0x16aba4 str lr, [r12, #0x38] */
/* @0x16aba8 str r4, [r12, #0x24] */
/* @0x16abac vadd.f32 s17, s15, s17 */
/* @0x16abb0 vstr s16, [r12, #96] */
/* @0x16abb4 vstr s16, [r12, #72] */
/* @0x16abb8 vstr s16, [r12] */
/* @0x16abbc str lr, [r12, #0x50] */
/* @0x16abc0 str r4, [r12, #0x3c] */
/* @0x16abc4 str lr, [r12, #0x8] */
/* @0x16abc8 str r4, [r12, #0x54] */
/* @0x16abcc str lr, [r12, #0x68] */
/* @0x16abd0 vadd.f32 s19, s19, s14 */
/* @0x16abd4 vstr s17, [r12, #4] */
/* @0x16abd8 vstr s17, [r12, #100] */
/* @0x16abdc vstr s17, [r12, #28] */
/* @0x16abe0 vadd.f32 s18, s18, s15 */
/* @0x16abe4 vstr s19, [r12, #24] */
/* @0x16abe8 vstr s19, [r12, #48] */
/* @0x16abec vstr s18, [r12, #52] */
/* @0x16abf0 vstr s18, [r12, #76] */
/* @0x16abf4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16abf8 ldr r3, [r5] */
/* @0x16abfc vstr s17, [r0, #4] */
/* @0x16ac00 vstr s16, [r0] */
/* @0x16ac04 vstr s19, [r0, #24] */
/* @0x16ac08 vstr s17, [r0, #28] */
/* @0x16ac0c vstr s19, [r0, #48] */
/* @0x16ac10 vstr s18, [r0, #52] */
/* @0x16ac14 vstr s16, [r0, #72] */
/* @0x16ac18 vstr s18, [r0, #76] */
/* @0x16ac1c vpop {d8, d9} */
/* @0x16ac20 str r3, [r0, #0x20] */
/* @0x16ac24 str r3, [r0, #0x38] */
/* @0x16ac28 str r3, [r0, #0x50] */
/* @0x16ac2c str r3, [r0, #0x8] */
/* @0x16ac30 str r4, [r0, #0xc] */
/* @0x16ac34 str r4, [r0, #0x24] */
/* @0x16ac38 str r4, [r0, #0x3c] */
/* @0x16ac3c str r4, [r0, #0x54] */
/* @0x16ac40 pop {r4, r5, r6, pc} */
/* @0x16ac44 stclo p7, c13, [r3], #-40 */
/* @0x16ac48 eoreq r7, r8, r4, lsl r2 */
/* @0x16ac4c .word 0xffffc0ac */
/* @0x16ac50 .word 0xffffe4e0 */
/* @0x16ac54 .word 0xffffe524 */
/* @0x16ac58 .word 0xffffe520 */
/* @0x16ac5c .word 0xffffbcd0 */

/* ── FUNC 0x16ac60 · GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool) · size=516 · insn=129 */
/* @0x16ac60 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x16ac64 vpush {d8, d9} */
/* @0x16ac68 vmov s14, r2 */
/* @0x16ac6c ldrb r12, [sp, #0x40] */
/* @0x16ac70 vmov s18, r0 */
/* @0x16ac74 ldr r5, [pc, #0x1d0] */
/* @0x16ac78 vmov s19, r1 */
/* @0x16ac7c cmp r12, #0 */
/* @0x16ac80 vmov s15, r3 */
/* @0x16ac84 add r5, pc, r5 */
/* @0x16ac88 ldr r9, [sp, #0x30] */
/* @0x16ac8c ldr r8, [sp, #0x34] */
/* @0x16ac90 ldr r7, [sp, #0x38] */
/* @0x16ac94 ldr r6, [sp, #0x3c] */
/* @0x16ac98 beq 0x16ae00 <_Z21GR_Draw_Rectangle_Extffffjjjjb+0x1a0> */
/* @0x16ac9c ldr r12, [pc, #0x1ac] */
/* @0x16aca0 vldr s13, [pc, #416] */
/* @0x16aca4 ldr r1, [pc, #0x1a8] */
/* @0x16aca8 mov r0, #3 */
/* @0x16acac ldr r3, [pc, #0x1a4] */
/* @0x16acb0 mov r2, #24 */
/* @0x16acb4 ldr r12, [r5, r12] */
/* @0x16acb8 vldr s17, [r12] */
/* @0x16acbc ldr r1, [r5, r1] */
/* @0x16acc0 vmul.f32 s17, s17, s13 */
/* @0x16acc4 vldr s16, [r1] */
/* @0x16acc8 ldr r1, [r5, r3] */
/* @0x16accc mov r3, #5 */
/* @0x16acd0 ldr r1, [r1] */
/* @0x16acd4 ldr r1, [r1] */
/* @0x16acd8 vmul.f32 s16, s16, s13 */
/* @0x16acdc vadd.f32 s18, s18, s17 */
/* @0x16ace0 vadd.f32 s19, s19, s16 */
/* @0x16ace4 vadd.f32 s17, s17, s14 */
/* @0x16ace8 vadd.f32 s16, s16, s15 */
/* @0x16acec bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16acf0 mov r4, r0 */
/* @0x16acf4 vcmpe.f32 s18, s17 */
/* @0x16acf8 bic r8, r8, #-16777216 */
/* @0x16acfc bic r7, r7, #-16777216 */
/* @0x16ad00 bic r6, r6, #-16777216 */
/* @0x16ad04 vmrs APSR_nzcv, fpscr */
/* @0x16ad08 vmovgt.f32 s15, s18 */
/* @0x16ad0c vmovgt.f32 s18, s17 */
/* @0x16ad10 vmovgt.f32 s17, s15 */
/* @0x16ad14 vcmpe.f32 s19, s16 */
/* @0x16ad18 vcvt.f64.f32 d6, s17 */
/* @0x16ad1c vmrs APSR_nzcv, fpscr */
/* @0x16ad20 vmovgt.f32 s15, s19 */
/* @0x16ad24 vmov r0, r1, d6 */
/* @0x16ad28 vmovgt.f32 s19, s16 */
/* @0x16ad2c vmovgt.f32 s16, s15 */
/* @0x16ad30 bl 0xb6598 <floor@plt> */
/* @0x16ad34 vmov d6, r0, r1 */
/* @0x16ad38 vcvt.s32.f64 s15, d6 */
/* @0x16ad3c vcvt.f32.s32 s15, s15 */
/* @0x16ad40 vcmp.f32 s15, s17 */
/* @0x16ad44 vmrs APSR_nzcv, fpscr */
/* @0x16ad48 vldreq s15, [pc, #248] */
/* @0x16ad4c vaddeq.f32 s17, s17, s15 */
/* @0x16ad50 vcvt.f64.f32 d7, s16 */
/* @0x16ad54 vmov r0, r1, d7 */
/* @0x16ad58 bl 0xb6598 <floor@plt> */
/* @0x16ad5c ldr r3, [pc, #0xf8] */
/* @0x16ad60 vstr s18, [r4] */
/* @0x16ad64 vstr s18, [r4, #96] */
/* @0x16ad68 vstr s19, [r4, #4] */
/* @0x16ad6c vstr s19, [r4, #100] */
/* @0x16ad70 ldr r3, [r5, r3] */
/* @0x16ad74 ldr r2, [pc, #0xe4] */
/* @0x16ad78 ldr r3, [r3] */
/* @0x16ad7c str r3, [r4, #0x8] */
/* @0x16ad80 str r3, [r4, #0x68] */
/* @0x16ad84 vmov d6, r0, r1 */
/* @0x16ad88 ldr r1, [r5, r2] */
/* @0x16ad8c vstr s17, [r4, #24] */
/* @0x16ad90 vstr s19, [r4, #28] */
/* @0x16ad94 vcvt.s32.f64 s15, d6 */
/* @0x16ad98 vstr s17, [r4, #48] */
/* @0x16ad9c vstr s18, [r4, #72] */
/* @0x16ada0 ldr r1, [r1] */
/* @0x16ada4 bic r2, r9, #-16777216 */
/* @0x16ada8 str r3, [r4, #0x20] */
/* @0x16adac str r3, [r4, #0x38] */
/* @0x16adb0 str r3, [r4, #0x50] */
/* @0x16adb4 lsl r3, r1, #24 */
/* @0x16adb8 orr r2, r2, r3 */
/* @0x16adbc orr r8, r8, r3 */
/* @0x16adc0 orr r7, r7, r3 */
/* @0x16adc4 str r2, [r4, #0xc] */
/* @0x16adc8 vcvt.f32.s32 s15, s15 */
/* @0x16adcc orr r3, r6, r3 */
/* @0x16add0 str r2, [r4, #0x6c] */
/* @0x16add4 str r8, [r4, #0x24] */
/* @0x16add8 str r7, [r4, #0x3c] */
/* @0x16addc str r3, [r4, #0x54] */
/* @0x16ade0 vcmp.f32 s15, s16 */
/* @0x16ade4 vmrs APSR_nzcv, fpscr */
/* @0x16ade8 vldreq s15, [pc, #88] */
/* @0x16adec vaddeq.f32 s16, s16, s15 */
/* @0x16adf0 vstr s16, [r4, #52] */
/* @0x16adf4 vstr s16, [r4, #76] */
/* @0x16adf8 vpop {d8, d9} */
/* @0x16adfc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x16ae00 ldr r1, [pc, #0x50] */
/* @0x16ae04 mov r0, #6 */
/* @0x16ae08 ldr lr, [pc, #0x40] */
/* @0x16ae0c mov r2, #24 */
/* @0x16ae10 ldr r12, [pc, #0x3c] */
/* @0x16ae14 mov r3, #5 */
/* @0x16ae18 ldr r1, [r5, r1] */
/* @0x16ae1c ldr lr, [r5, lr] */
/* @0x16ae20 vldr s17, [lr] */
/* @0x16ae24 ldr r12, [r5, r12] */
/* @0x16ae28 vadd.f32 s17, s14, s17 */
/* @0x16ae2c ldr r1, [r1] */
/* @0x16ae30 vldr s16, [r12] */
/* @0x16ae34 ldr r1, [r1] */
/* @0x16ae38 vadd.f32 s16, s15, s16 */
/* @0x16ae3c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16ae40 mov r4, r0 */
/* @0x16ae44 b 0x16acf4 <_Z21GR_Draw_Rectangle_Extffffjjjjb+0x94> */
/* @0x16ae48 stclo p7, c13, [r3], #-40 */
/* @0x16ae4c eoreq r6, r8, r12, asr #31 */
/* @0x16ae50 .word 0xffffe524 */
/* @0x16ae54 .word 0xffffe520 */
/* @0x16ae58 .word 0xffffe4e0 */
/* @0x16ae5c .word 0xffffbcd0 */
/* @0x16ae60 .word 0xffffc0b0 */

/* ── FUNC 0x16ae64 · GR_Draw_Circle_Precision(int) · size=216 · insn=54 */
/* @0x16ae64 cmp r0, #64 */
/* @0x16ae68 push {r4, r5, r6, r7, r8, lr} */
/* @0x16ae6c vpush {d8, d9} */
/* @0x16ae70 bgt 0x16af10 <_Z24GR_Draw_Circle_Precisioni+0xac> */
/* @0x16ae74 cmp r0, #4 */
/* @0x16ae78 movlt r0, #4 */
/* @0x16ae7c vldr s16, [pc, #160] */
/* @0x16ae80 bic r8, r0, #3 */
/* @0x16ae84 vmov s15, r8 */
/* @0x16ae88 vcvt.f32.s32 s17, s15 */
/* @0x16ae8c vdiv.f32 s16, s16, s17 */
/* @0x16ae90 vmov r0, s16 */
/* @0x16ae94 bl 0xb658c <cosf@plt> */
/* @0x16ae98 mov r7, r0 */
/* @0x16ae9c vmov r0, s16 */
/* @0x16aea0 bl 0xb6580 <sinf@plt> */
/* @0x16aea4 ldr r3, [pc, #0x84] */
/* @0x16aea8 mov r4, #0 */
/* @0x16aeac ldr r6, [pc, #0x80] */
/* @0x16aeb0 vldr s18, [pc, #112] */
/* @0x16aeb4 ldr r5, [pc, #0x7c] */
/* @0x16aeb8 ldr r3, [pc, r3] */
/* @0x16aebc ldr r6, [pc, r6] */
/* @0x16aec0 ldr r5, [pc, r5] */
/* @0x16aec4 str r8, [r3] */
/* @0x16aec8 b 0x16aef0 <_Z24GR_Draw_Circle_Precisioni+0x8c> */
/* @0x16aecc vmov s15, r3 */
/* @0x16aed0 vcvt.f32.s32 s16, s15 */
/* @0x16aed4 vmul.f32 s16, s16, s18 */
/* @0x16aed8 vdiv.f32 s16, s16, s17 */
/* @0x16aedc vmov r0, s16 */
/* @0x16aee0 bl 0xb658c <cosf@plt> */
/* @0x16aee4 mov r7, r0 */
/* @0x16aee8 vmov r0, s16 */
/* @0x16aeec bl 0xb6580 <sinf@plt> */
/* @0x16aef0 add r4, r4, #1 */
/* @0x16aef4 str r7, [r6], #4 */
/* @0x16aef8 cmp r8, r4 */
/* @0x16aefc str r0, [r5], #4 */
/* @0x16af00 lsl r3, r4, #1 */
/* @0x16af04 bge 0x16aecc <_Z24GR_Draw_Circle_Precisioni+0x68> */
/* @0x16af08 vpop {d8, d9} */
/* @0x16af0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x16af10 mov r7, #1065353216 */
/* @0x16af14 mov r8, #64 */
/* @0x16af18 mov r0, #0 */
/* @0x16af1c vldr s17, [pc, #8] */
/* @0x16af20 b 0x16aea4 <_Z24GR_Draw_Circle_Precisioni+0x40> */
/* @0x16af24 andeq r0, r0, r0 */
/* @0x16af28 ldrdmi r0, r1, [r9], #-251 */
/* @0x16af2c addmi r0, r0, #0 */
/* @0x16af30 eoreq r5, r8, r0, asr #5 */
/* @0x16af34 eoreq r5, r8, r0, asr #5 */
/* @0x16af38 eoreq r5, r8, r0, asr #5 */

/* ── FUNC 0x16af3c · _Draw_Ellipse(float, float, float, float, unsigned int, unsigned int, bool) · size=604 · insn=151 */
/* @0x16af3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16af40 vpush {d8, d9} */
/* @0x16af44 vmov s14, r3 */
/* @0x16af48 vmov s16, r0 */
/* @0x16af4c sub sp, sp, #20 */
/* @0x16af50 vmov s13, r2 */
/* @0x16af54 ldr r9, [pc, #0x224] */
/* @0x16af58 vmov s17, r1 */
/* @0x16af5c ldrb r10, [sp, #0x50] */
/* @0x16af60 vmov.f32 s15, #5.000000e-01 */
/* @0x16af64 add r9, pc, r9 */
/* @0x16af68 cmp r10, #0 */
/* @0x16af6c ldr r4, [sp, #0x4c] */
/* @0x16af70 ldr r3, [pc, #0x20c] */
/* @0x16af74 vsub.f32 s18, s16, s13 */
/* @0x16af78 vsub.f32 s19, s17, s14 */
/* @0x16af7c vmul.f32 s18, s18, s15 */
/* @0x16af80 vmul.f32 s19, s19, s15 */
/* @0x16af84 vadd.f32 s16, s16, s13 */
/* @0x16af88 vadd.f32 s17, s17, s14 */
/* @0x16af8c vabs.f32 s18, s18 */
/* @0x16af90 vmul.f32 s16, s16, s15 */
/* @0x16af94 vabs.f32 s19, s19 */
/* @0x16af98 vmul.f32 s17, s17, s15 */
/* @0x16af9c beq 0x16b044 <_Z13_Draw_Ellipseffffjjb+0x108> */
/* @0x16afa0 ldr r1, [pc, #0x1e0] */
/* @0x16afa4 mov r0, #3 */
/* @0x16afa8 ldr r3, [r9, r3] */
/* @0x16afac mov r2, #16 */
/* @0x16afb0 ldr r5, [r9, r1] */
/* @0x16afb4 ldr r1, [r3] */
/* @0x16afb8 ldr r3, [r5] */
/* @0x16afbc ldr r1, [r1] */
/* @0x16afc0 add r3, r3, #1 */
/* @0x16afc4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16afc8 ldr r12, [r5] */
/* @0x16afcc cmp r12, #0 */
/* @0x16afd0 blt 0x16b038 <_Z13_Draw_Ellipseffffjjb+0xfc> */
/* @0x16afd4 ldr r5, [pc, #0x1b0] */
/* @0x16afd8 add r3, r0, #8 */
/* @0x16afdc ldr r1, [pc, #0x1ac] */
/* @0x16afe0 ldr r2, [pc, #0x1ac] */
/* @0x16afe4 ldr r5, [r9, r5] */
/* @0x16afe8 ldr r1, [r9, r1] */
/* @0x16afec ldr r0, [r9, r2] */
/* @0x16aff0 ldr r5, [r5] */
/* @0x16aff4 add r2, r1, #4 */
/* @0x16aff8 add r12, r2, r12, lsl #2 */
/* @0x16affc vmov.f32 s13, s16 */
/* @0x16b000 vldr s15, [r1] */
/* @0x16b004 cmp r2, r12 */
/* @0x16b008 mov r1, r2 */
/* @0x16b00c add r3, r3, #16 */
/* @0x16b010 add r2, r2, #4 */
/* @0x16b014 vmla.f32 s13, s15, s18 */
/* @0x16b018 vmov.f32 s14, s17 */
/* @0x16b01c vstr s13, [r3, #-24] */
/* @0x16b020 vldmia r0!, {s15} */
/* @0x16b024 str r5, [r3, #-0x10] */
/* @0x16b028 str r4, [r3, #-0xc] */
/* @0x16b02c vmla.f32 s14, s15, s19 */
/* @0x16b030 vstr s14, [r3, #-20] */
/* @0x16b034 bne 0x16affc <_Z13_Draw_Ellipseffffjjb+0xc0> */
/* @0x16b038 add sp, sp, #20 */
/* @0x16b03c vpop {d8, d9} */
/* @0x16b040 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x16b044 ldr r1, [pc, #0x13c] */
/* @0x16b048 mov r0, #4 */
/* @0x16b04c ldr r3, [r9, r3] */
/* @0x16b050 mov r2, #16 */
/* @0x16b054 ldr r5, [r9, r1] */
/* @0x16b058 ldr r1, [r3] */
/* @0x16b05c ldr r3, [r5] */
/* @0x16b060 ldr r1, [r1] */
/* @0x16b064 add r3, r3, r3, lsl #1 */
/* @0x16b068 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16b06c ldr r3, [r5] */
/* @0x16b070 cmp r3, #0 */
/* @0x16b074 ble 0x16b038 <_Z13_Draw_Ellipseffffjjb+0xfc> */
/* @0x16b078 ldr r12, [pc, #0x110] */
/* @0x16b07c add r1, r3, r3, lsl #1 */
/* @0x16b080 ldr r3, [pc, #0x10c] */
/* @0x16b084 add r11, r0, #16 */
/* @0x16b088 add r1, r0, r1, lsl #4 */
/* @0x16b08c ldr r2, [pc, #0xf8] */
/* @0x16b090 ldr r12, [r9, r12] */
/* @0x16b094 add r1, r1, #48 */
/* @0x16b098 str r1, [sp, #0x4] */
/* @0x16b09c add r8, r0, #32 */
/* @0x16b0a0 add r7, r0, #36 */
/* @0x16b0a4 add r6, r0, #40 */
/* @0x16b0a8 str r12, [sp, #0x8] */
/* @0x16b0ac add r5, r0, #44 */
/* @0x16b0b0 ldr r3, [r9, r3] */
/* @0x16b0b4 mov r1, r10 */
/* @0x16b0b8 mov r12, r11 */
/* @0x16b0bc str r3, [sp, #0xc] */
/* @0x16b0c0 add r3, r0, #48 */
/* @0x16b0c4 ldr r2, [r9, r2] */
/* @0x16b0c8 vldr s15, [r2] */
/* @0x16b0cc str r0, [sp] */
/* @0x16b0d0 vmov.f32 s13, s16 */
/* @0x16b0d4 ldr r0, [sp, #0x48] */
/* @0x16b0d8 ldr r2, [sp, #0x8] */
/* @0x16b0dc vstr s16, [r3, #-48] */
/* @0x16b0e0 vstr s17, [r3, #-44] */
/* @0x16b0e4 vstr s15, [r3, #-40] */
/* @0x16b0e8 str r0, [r3, #-0x24] */
/* @0x16b0ec add r10, r2, r1 */
/* @0x16b0f0 vldr s14, [r10] */
/* @0x16b0f4 vmla.f32 s13, s18, s14 */
/* @0x16b0f8 ldr r0, [sp] */
/* @0x16b0fc add r3, r3, #48 */
/* @0x16b100 rsb r2, r0, r12 */
/* @0x16b104 ldr r0, [sp, #0xc] */
/* @0x16b108 add r2, r2, r11 */
/* @0x16b10c add r12, r12, #48 */
/* @0x16b110 add r9, r0, r1 */
/* @0x16b114 ldr r0, [sp, #0x4] */
/* @0x16b118 add r1, r1, #4 */
/* @0x16b11c cmp r3, r0 */
/* @0x16b120 vstr s13, [r2, #-16] */
/* @0x16b124 vmov.f32 s13, s17 */
/* @0x16b128 vldr s14, [r9] */
/* @0x16b12c vstr s15, [r2, #-8] */
/* @0x16b130 str r4, [r2, #-0x4] */
/* @0x16b134 vmla.f32 s13, s19, s14 */
/* @0x16b138 vstr s13, [r2, #-12] */
/* @0x16b13c vmov.f32 s13, s16 */
/* @0x16b140 vldr s14, [r10, #4] */
/* @0x16b144 vmov r2, s15 */
/* @0x16b148 vmla.f32 s13, s18, s14 */
/* @0x16b14c vmov r0, s13 */
/* @0x16b150 vmov.f32 s13, s17 */
/* @0x16b154 str r0, [r8], #48 */
/* @0x16b158 vldr s14, [r9, #4] */
/* @0x16b15c vmla.f32 s13, s19, s14 */
/* @0x16b160 vmov r0, s13 */
/* @0x16b164 str r0, [r7], #48 */
/* @0x16b168 str r2, [r6], #48 */
/* @0x16b16c str r4, [r5], #48 */
/* @0x16b170 bne 0x16b0d0 <_Z13_Draw_Ellipseffffjjb+0x194> */
/* @0x16b174 add sp, sp, #20 */
/* @0x16b178 vpop {d8, d9} */
/* @0x16b17c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x16b180 eoreq r6, r8, r12, ror #25 */
/* @0x16b184 .word 0xffffe4e0 */
/* @0x16b188 .word 0xffffe528 */
/* @0x16b18c .word 0xffffbcd0 */
/* @0x16b190 .word 0xffffe52c */
/* @0x16b194 .word 0xffffe530 */

/* ── FUNC 0x16b198 · GR_Draw_Circle(float, float, float, bool) · size=92 · insn=23 */
/* @0x16b198 vmov s15, r2 */
/* @0x16b19c ldr r12, [pc, #0x4c] */
/* @0x16b1a0 vmov s13, r0 */
/* @0x16b1a4 vmov s14, r1 */
/* @0x16b1a8 ldr r12, [pc, r12] */
/* @0x16b1ac vsub.f32 s12, s13, s15 */
/* @0x16b1b0 ldr r2, [r12] */
/* @0x16b1b4 str lr, [sp, #-0x4]! */
/* @0x16b1b8 sub sp, sp, #20 */
/* @0x16b1bc str r3, [sp, #0x8] */
/* @0x16b1c0 str r2, [sp] */
/* @0x16b1c4 str r2, [sp, #0x4] */
/* @0x16b1c8 vadd.f32 s13, s13, s15 */
/* @0x16b1cc vmov r0, s12 */
/* @0x16b1d0 vsub.f32 s12, s14, s15 */
/* @0x16b1d4 vmov r2, s13 */
/* @0x16b1d8 vadd.f32 s15, s14, s15 */
/* @0x16b1dc vmov r1, s12 */
/* @0x16b1e0 vmov r3, s15 */
/* @0x16b1e4 bl 0x16af3c <_Z13_Draw_Ellipseffffjjb> */
/* @0x16b1e8 add sp, sp, #20 */
/* @0x16b1ec ldr pc, [sp], #4 */
/* @0x16b1f0 eoreq r2, r8, r4, asr r11 */

/* ── FUNC 0x16b1f4 · GR_Draw_Circle_Ext(float, float, float, unsigned int, unsigned int, bool) · size=132 · insn=33 */
/* @0x16b1f4 push {r4, r5, r6, r7, lr} */
/* @0x16b1f8 vpush {d8, d9} */
/* @0x16b1fc vmov s15, r2 */
/* @0x16b200 ldr r4, [pc, #0x6c] */
/* @0x16b204 sub sp, sp, #20 */
/* @0x16b208 vmov s13, r1 */
/* @0x16b20c ldr r4, [pc, r4] */
/* @0x16b210 vmov s14, r0 */
/* @0x16b214 mov r0, r3 */
/* @0x16b218 vsub.f32 s19, s13, s15 */
/* @0x16b21c ldr r1, [r4] */
/* @0x16b220 ldr r5, [sp, #0x38] */
/* @0x16b224 ldrb r6, [sp, #0x3c] */
/* @0x16b228 vadd.f32 s18, s13, s15 */
/* @0x16b22c vsub.f32 s16, s14, s15 */
/* @0x16b230 vadd.f32 s17, s14, s15 */
/* @0x16b234 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16b238 ldr r1, [r4] */
/* @0x16b23c mov r7, r0 */
/* @0x16b240 mov r0, r5 */
/* @0x16b244 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16b248 str r7, [sp] */
/* @0x16b24c str r6, [sp, #0x8] */
/* @0x16b250 vmov r1, s19 */
/* @0x16b254 vmov r3, s18 */
/* @0x16b258 vmov r2, s17 */
/* @0x16b25c str r0, [sp, #0x4] */
/* @0x16b260 vmov r0, s16 */
/* @0x16b264 bl 0x16af3c <_Z13_Draw_Ellipseffffjjb> */
/* @0x16b268 add sp, sp, #20 */
/* @0x16b26c vpop {d8, d9} */
/* @0x16b270 pop {r4, r5, r6, r7, pc} */
/* @0x16b274 .word 0x00282af4 */

/* ── FUNC 0x16b278 · GR_Draw_Ellipse(float, float, float, float, bool) · size=52 · insn=13 */
/* @0x16b278 ldr r12, [pc, #0x28] */
/* @0x16b27c str lr, [sp, #-0x4]! */
/* @0x16b280 ldr r12, [pc, r12] */
/* @0x16b284 sub sp, sp, #20 */
/* @0x16b288 ldr r12, [r12] */
/* @0x16b28c ldrb lr, [sp, #0x18] */
/* @0x16b290 str r12, [sp] */
/* @0x16b294 str lr, [sp, #0x8] */
/* @0x16b298 str r12, [sp, #0x4] */
/* @0x16b29c bl 0x16af3c <_Z13_Draw_Ellipseffffjjb> */
/* @0x16b2a0 add sp, sp, #20 */
/* @0x16b2a4 ldr pc, [sp], #4 */
/* @0x16b2a8 eoreq r2, r8, r12, ror r10 */

/* ── FUNC 0x16b2ac · GR_Draw_Ellipse_Ext(float, float, float, float, unsigned int, unsigned int, bool) · size=112 · insn=28 */
/* @0x16b2ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16b2b0 sub sp, sp, #4 */
/* @0x16b2b4 ldr r4, [pc, #0x5c] */
/* @0x16b2b8 mov r5, r0 */
/* @0x16b2bc mov r6, r1 */
/* @0x16b2c0 ldr r0, [sp, #0x28] */
/* @0x16b2c4 ldr r4, [pc, r4] */
/* @0x16b2c8 mov r9, r2 */
/* @0x16b2cc mov r8, r3 */
/* @0x16b2d0 ldr r7, [sp, #0x2c] */
/* @0x16b2d4 ldr r1, [r4] */
/* @0x16b2d8 ldrb r10, [sp, #0x30] */
/* @0x16b2dc bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16b2e0 ldr r1, [r4] */
/* @0x16b2e4 mov r11, r0 */
/* @0x16b2e8 mov r0, r7 */
/* @0x16b2ec bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16b2f0 str r11, [sp, #0x28] */
/* @0x16b2f4 str r10, [sp, #0x30] */
/* @0x16b2f8 mov r1, r6 */
/* @0x16b2fc mov r2, r9 */
/* @0x16b300 mov r3, r8 */
/* @0x16b304 str r0, [sp, #0x2c] */
/* @0x16b308 mov r0, r5 */
/* @0x16b30c add sp, sp, #4 */
/* @0x16b310 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16b314 b 0x16af3c <_Z13_Draw_Ellipseffffjjb> */
/* @0x16b318 eoreq r2, r8, r12, lsr r10 */

/* ── FUNC 0x16b31c · _Draw_RoundRect(float, float, float, float, float, float, unsigned int, unsigned int, bool) · size=1120 · insn=280 */
/* @0x16b31c vmov s9, r0 */
/* @0x16b320 vmov s10, r2 */
/* @0x16b324 vmov s12, r3 */
/* @0x16b328 ldr r3, [pc, #0x434] */
/* @0x16b32c vsub.f32 s13, s10, s9 */
/* @0x16b330 vmov s11, r1 */
/* @0x16b334 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16b338 vpush {d8, d9, d10} */
/* @0x16b33c sub sp, sp, #20 */
/* @0x16b340 vldr s16, [sp, #80] */
/* @0x16b344 vldr s17, [sp, #84] */
/* @0x16b348 ldr r5, [pc, #0x418] */
/* @0x16b34c ldrb r8, [sp, #0x60] */
/* @0x16b350 add r5, pc, r5 */
/* @0x16b354 ldr r6, [sp, #0x58] */
/* @0x16b358 ldr r4, [sp, #0x5c] */
/* @0x16b35c str r8, [sp, #0x8] */
/* @0x16b360 vsub.f32 s14, s12, s11 */
/* @0x16b364 vabs.f32 s13, s13 */
/* @0x16b368 vabs.f32 s14, s14 */
/* @0x16b36c vcmp.f32 s13, s16 */
/* @0x16b370 vmov.f32 s15, #5.000000e-01 */
/* @0x16b374 vmrs APSR_nzcv, fpscr */
/* @0x16b378 vcmp.f32 s14, s17 */
/* @0x16b37c vmovmi.f32 s16, s13 */
/* @0x16b380 vmrs APSR_nzcv, fpscr */
/* @0x16b384 vmovmi.f32 s17, s14 */
/* @0x16b388 cmp r8, #0 */
/* @0x16b38c vmul.f32 s19, s16, s15 */
/* @0x16b390 vmul.f32 s18, s17, s15 */
/* @0x16b394 vadd.f32 s10, s9, s10 */
/* @0x16b398 vadd.f32 s12, s11, s12 */
/* @0x16b39c vmul.f32 s21, s10, s15 */
/* @0x16b3a0 vnmls.f32 s19, s13, s15 */
/* @0x16b3a4 vmul.f32 s20, s12, s15 */
/* @0x16b3a8 vnmls.f32 s18, s14, s15 */
/* @0x16b3ac beq 0x16b728 <_Z15_Draw_RoundRectffffffjjb+0x40c> */
/* @0x16b3b0 ldr r1, [pc, #0x3b4] */
/* @0x16b3b4 mov r0, #3 */
/* @0x16b3b8 ldr r3, [r5, r3] */
/* @0x16b3bc mov r2, #24 */
/* @0x16b3c0 ldr r7, [r5, r1] */
/* @0x16b3c4 ldr r1, [r3] */
/* @0x16b3c8 ldr r3, [r7] */
/* @0x16b3cc ldr r1, [r1] */
/* @0x16b3d0 add r3, r3, #6 */
/* @0x16b3d4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16b3d8 ldr r12, [r7] */
/* @0x16b3dc mov r10, #0 */
/* @0x16b3e0 ldr r3, [pc, #0x388] */
/* @0x16b3e4 vstr s21, [r0] */
/* @0x16b3e8 cmp r12, #0 */
/* @0x16b3ec add r7, r12, #3 */
/* @0x16b3f0 vstr s20, [r0, #4] */
/* @0x16b3f4 add r1, r0, #24 */
/* @0x16b3f8 movge r7, r12 */
/* @0x16b3fc ldr r3, [r5, r3] */
/* @0x16b400 asrs r7, r7, #2 */
/* @0x16b404 vldr s15, [r3] */
/* @0x16b408 str r10, [r0, #0x14] */
/* @0x16b40c vstr s15, [r0, #8] */
/* @0x16b410 str r6, [r0, #0xc] */
/* @0x16b414 str r10, [r0, #0x10] */
/* @0x16b418 bmi 0x16b754 <_Z15_Draw_RoundRectffffffjjb+0x438> */
/* @0x16b41c vadd.f32 s11, s21, s19 */
/* @0x16b420 lsl r11, r7, #1 */
/* @0x16b424 add r9, r11, r7 */
/* @0x16b428 ldr r6, [pc, #0x344] */
/* @0x16b42c ldr r2, [pc, #0x344] */
/* @0x16b430 add r3, r0, #48 */
/* @0x16b434 lsl r9, r9, #3 */
/* @0x16b438 str r11, [sp, #0x4] */
/* @0x16b43c add r8, r9, #72 */
/* @0x16b440 ldr r6, [r5, r6] */
/* @0x16b444 ldr r2, [r5, r2] */
/* @0x16b448 add r8, r0, r8 */
/* @0x16b44c vadd.f32 s12, s20, s18 */
/* @0x16b450 vmov.f32 s14, #5.000000e-01 */
/* @0x16b454 vldmia r6!, {s13} */
/* @0x16b458 add r3, r3, #24 */
/* @0x16b45c vmul.f32 s13, s13, s16 */
/* @0x16b460 vmov.f32 s10, s11 */
/* @0x16b464 vmla.f32 s10, s13, s14 */
/* @0x16b468 vstr s10, [r3, #-48] */
/* @0x16b46c vldmia r2!, {s13} */
/* @0x16b470 vmul.f32 s13, s13, s17 */
/* @0x16b474 vstr s15, [r3, #-40] */
/* @0x16b478 str r4, [r3, #-0x24] */
/* @0x16b47c str r10, [r3, #-0x1c] */
/* @0x16b480 str r10, [r3, #-0x20] */
/* @0x16b484 vmov.f32 s10, s12 */
/* @0x16b488 vmla.f32 s10, s13, s14 */
/* @0x16b48c vstr s10, [r3, #-44] */
/* @0x16b490 cmp r3, r8 */
/* @0x16b494 bne 0x16b454 <_Z15_Draw_RoundRectffffffjjb+0x138> */
/* @0x16b498 add r2, r9, #24 */
/* @0x16b49c add r2, r1, r2 */
/* @0x16b4a0 add r6, r12, r12, lsr #31 */
/* @0x16b4a4 asr r6, r6, #1 */
/* @0x16b4a8 cmp r6, r7 */
/* @0x16b4ac blt 0x16b560 <_Z15_Draw_RoundRectffffffjjb+0x244> */
/* @0x16b4b0 ldr r3, [pc, #0x2bc] */
/* @0x16b4b4 vadd.f32 s11, s20, s18 */
/* @0x16b4b8 ldr r11, [pc, #0x2b8] */
/* @0x16b4bc add r9, r6, r6, lsl #1 */
/* @0x16b4c0 ldr r8, [sp, #0x4] */
/* @0x16b4c4 ldr r3, [r5, r3] */
/* @0x16b4c8 lsl r9, r9, #3 */
/* @0x16b4cc add r10, r8, r7 */
/* @0x16b4d0 add r9, r9, #48 */
/* @0x16b4d4 lsl r8, r7, #2 */
/* @0x16b4d8 str r3, [sp, #0xc] */
/* @0x16b4dc sub r10, r9, r10, lsl #3 */
/* @0x16b4e0 ldr r11, [r5, r11] */
/* @0x16b4e4 add r3, r2, #24 */
/* @0x16b4e8 add r10, r2, r10 */
/* @0x16b4ec vsub.f32 s12, s21, s19 */
/* @0x16b4f0 str r11, [sp] */
/* @0x16b4f4 ldr r11, [sp, #0xc] */
/* @0x16b4f8 add r9, r8, r11 */
/* @0x16b4fc ldr r11, [sp] */
/* @0x16b500 add r8, r8, r11 */
/* @0x16b504 mov r11, #0 */
/* @0x16b508 vmov.f32 s14, #5.000000e-01 */
/* @0x16b50c vldmia r9!, {s13} */
/* @0x16b510 add r3, r3, #24 */
/* @0x16b514 vmul.f32 s13, s13, s16 */
/* @0x16b518 vmov.f32 s10, s12 */
/* @0x16b51c vmla.f32 s10, s13, s14 */
/* @0x16b520 vstr s10, [r3, #-48] */
/* @0x16b524 vldmia r8!, {s13} */
/* @0x16b528 vmul.f32 s13, s13, s17 */
/* @0x16b52c vstr s15, [r3, #-40] */
/* @0x16b530 str r4, [r3, #-0x24] */
/* @0x16b534 str r11, [r3, #-0x1c] */
/* @0x16b538 str r11, [r3, #-0x20] */
/* @0x16b53c vmov.f32 s10, s11 */
/* @0x16b540 vmla.f32 s10, s13, s14 */
/* @0x16b544 vstr s10, [r3, #-44] */
/* @0x16b548 cmp r3, r10 */
/* @0x16b54c bne 0x16b50c <_Z15_Draw_RoundRectffffffjjb+0x1f0> */
/* @0x16b550 add r3, r6, #1 */
/* @0x16b554 rsb r3, r7, r3 */
/* @0x16b558 add r3, r3, r3, lsl #1 */
/* @0x16b55c add r2, r2, r3, lsl #3 */
/* @0x16b560 ldr r3, [sp, #0x4] */
/* @0x16b564 add r7, r3, r7 */
/* @0x16b568 cmp r7, r6 */
/* @0x16b56c blt 0x16b60c <_Z15_Draw_RoundRectffffffjjb+0x2f0> */
/* @0x16b570 vsub.f32 s11, s21, s19 */
/* @0x16b574 add r10, r6, r6, lsl #1 */
/* @0x16b578 ldr r3, [pc, #0x1f8] */
/* @0x16b57c add r9, r7, r7, lsl #1 */
/* @0x16b580 ldr r8, [pc, #0x1ec] */
/* @0x16b584 lsl r10, r10, #3 */
/* @0x16b588 rsb r9, r10, r9, lsl #3 */
/* @0x16b58c lsl r10, r6, #2 */
/* @0x16b590 ldr r11, [r5, r3] */
/* @0x16b594 add r9, r9, #48 */
/* @0x16b598 ldr r8, [r5, r8] */
/* @0x16b59c add r9, r2, r9 */
/* @0x16b5a0 add r3, r2, #24 */
/* @0x16b5a4 add r8, r10, r8 */
/* @0x16b5a8 add r10, r10, r11 */
/* @0x16b5ac mov r11, #0 */
/* @0x16b5b0 vsub.f32 s12, s20, s18 */
/* @0x16b5b4 vmov.f32 s14, #5.000000e-01 */
/* @0x16b5b8 vldmia r8!, {s13} */
/* @0x16b5bc add r3, r3, #24 */
/* @0x16b5c0 vmul.f32 s13, s13, s16 */
/* @0x16b5c4 vmov.f32 s10, s11 */
/* @0x16b5c8 vmla.f32 s10, s13, s14 */
/* @0x16b5cc vstr s10, [r3, #-48] */
/* @0x16b5d0 vldmia r10!, {s13} */
/* @0x16b5d4 vmul.f32 s13, s13, s17 */
/* @0x16b5d8 vstr s15, [r3, #-40] */
/* @0x16b5dc str r4, [r3, #-0x24] */
/* @0x16b5e0 str r11, [r3, #-0x1c] */
/* @0x16b5e4 str r11, [r3, #-0x20] */
/* @0x16b5e8 vmov.f32 s10, s12 */
/* @0x16b5ec vmla.f32 s10, s13, s14 */
/* @0x16b5f0 vstr s10, [r3, #-44] */
/* @0x16b5f4 cmp r3, r9 */
/* @0x16b5f8 bne 0x16b5b8 <_Z15_Draw_RoundRectffffffjjb+0x29c> */
/* @0x16b5fc rsb r3, r6, r7 */
/* @0x16b600 add r3, r3, #1 */
/* @0x16b604 add r3, r3, r3, lsl #1 */
/* @0x16b608 add r2, r2, r3, lsl #3 */
/* @0x16b60c cmp r7, r12 */
/* @0x16b610 bgt 0x16b6b0 <_Z15_Draw_RoundRectffffffjjb+0x394> */
/* @0x16b614 vadd.f32 s19, s21, s19 */
/* @0x16b618 add r8, r12, r12, lsl #1 */
/* @0x16b61c ldr r6, [pc, #0x150] */
/* @0x16b620 add r9, r7, r7, lsl #1 */
/* @0x16b624 ldr r10, [pc, #0x14c] */
/* @0x16b628 lsl r8, r8, #3 */
/* @0x16b62c add r8, r8, #48 */
/* @0x16b630 lsl r3, r7, #2 */
/* @0x16b634 ldr r6, [r5, r6] */
/* @0x16b638 ldr r5, [r5, r10] */
/* @0x16b63c sub r8, r8, r9, lsl #3 */
/* @0x16b640 add r6, r3, r6 */
/* @0x16b644 add r8, r2, r8 */
/* @0x16b648 add r5, r3, r5 */
/* @0x16b64c add r3, r2, #24 */
/* @0x16b650 mov r9, #0 */
/* @0x16b654 vsub.f32 s18, s20, s18 */
/* @0x16b658 vmov.f32 s14, #5.000000e-01 */
/* @0x16b65c vldmia r6!, {s13} */
/* @0x16b660 add r3, r3, #24 */
/* @0x16b664 vmul.f32 s13, s13, s16 */
/* @0x16b668 vmov.f32 s12, s19 */
/* @0x16b66c vmla.f32 s12, s13, s14 */
/* @0x16b670 vstr s12, [r3, #-48] */
/* @0x16b674 vldmia r5!, {s13} */
/* @0x16b678 vmul.f32 s13, s13, s17 */
/* @0x16b67c vstr s15, [r3, #-40] */
/* @0x16b680 str r4, [r3, #-0x24] */
/* @0x16b684 str r9, [r3, #-0x1c] */
/* @0x16b688 str r9, [r3, #-0x20] */
/* @0x16b68c vmov.f32 s10, s18 */
/* @0x16b690 vmla.f32 s10, s13, s14 */
/* @0x16b694 vstr s10, [r3, #-44] */
/* @0x16b698 cmp r3, r8 */
/* @0x16b69c bne 0x16b65c <_Z15_Draw_RoundRectffffffjjb+0x340> */
/* @0x16b6a0 add r12, r12, #1 */
/* @0x16b6a4 rsb r7, r7, r12 */
/* @0x16b6a8 add r7, r7, r7, lsl #1 */
/* @0x16b6ac add r2, r2, r7, lsl #3 */
/* @0x16b6b0 ldr r12, [r1] */
/* @0x16b6b4 ldr r3, [r1, #0x4] */
/* @0x16b6b8 ldr r5, [r1, #0x8] */
/* @0x16b6bc ldr r4, [r1, #0xc] */
/* @0x16b6c0 ldr r8, [sp, #0x8] */
/* @0x16b6c4 str r12, [r2] */
/* @0x16b6c8 str r3, [r2, #0x4] */
/* @0x16b6cc cmp r8, #0 */
/* @0x16b6d0 str r5, [r2, #0x8] */
/* @0x16b6d4 str r4, [r2, #0xc] */
/* @0x16b6d8 ldr r12, [r1, #0x10] */
/* @0x16b6dc ldr r3, [r1, #0x14] */
/* @0x16b6e0 str r12, [r2, #0x10] */
/* @0x16b6e4 str r3, [r2, #0x14] */
/* @0x16b6e8 beq 0x16b71c <_Z15_Draw_RoundRectffffffjjb+0x400> */
/* @0x16b6ec ldr r2, [r1] */
/* @0x16b6f0 ldr r3, [r1, #0x4] */
/* @0x16b6f4 ldr r4, [r1, #0x8] */
/* @0x16b6f8 ldr r12, [r1, #0xc] */
/* @0x16b6fc str r2, [r0] */
/* @0x16b700 str r3, [r0, #0x4] */
/* @0x16b704 str r4, [r0, #0x8] */
/* @0x16b708 str r12, [r0, #0xc] */
/* @0x16b70c ldr r2, [r1, #0x10] */
/* @0x16b710 ldr r3, [r1, #0x14] */
/* @0x16b714 str r2, [r0, #0x10] */
/* @0x16b718 str r3, [r0, #0x14] */
/* @0x16b71c add sp, sp, #20 */
/* @0x16b720 vpop {d8, d9, d10} */
/* @0x16b724 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x16b728 ldr r1, [pc, #0x3c] */
/* @0x16b72c mov r0, #6 */
/* @0x16b730 ldr r3, [r5, r3] */
/* @0x16b734 mov r2, #24 */
/* @0x16b738 ldr r7, [r5, r1] */
/* @0x16b73c ldr r1, [r3] */
/* @0x16b740 ldr r3, [r7] */
/* @0x16b744 ldr r1, [r1] */
/* @0x16b748 add r3, r3, r0 */
/* @0x16b74c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16b750 b 0x16b3d8 <_Z15_Draw_RoundRectffffffjjb+0xbc> */
/* @0x16b754 lsl r2, r7, #1 */
/* @0x16b758 str r2, [sp, #0x4] */
/* @0x16b75c mov r2, r1 */
/* @0x16b760 b 0x16b4a0 <_Z15_Draw_RoundRectffffffjjb+0x184> */
/* @0x16b764 .word 0xffffe4e0 */
/* @0x16b768 eoreq r6, r8, r0, lsl #18 */
/* @0x16b76c .word 0xffffe528 */
/* @0x16b770 .word 0xffffbcd0 */
/* @0x16b774 .word 0xffffe52c */
/* @0x16b778 .word 0xffffe530 */

/* ── FUNC 0x16b77c · GR_Draw_RoundRect(float, float, float, float, float, float, bool) · size=232 · insn=58 */
/* @0x16b77c push {r4, r5, r6, lr} */
/* @0x16b780 vpush {d8, d9} */
/* @0x16b784 vmov s17, r2 */
/* @0x16b788 vmov s19, r0 */
/* @0x16b78c sub sp, sp, #24 */
/* @0x16b790 vmov s16, r3 */
/* @0x16b794 vcmpe.f32 s17, s19 */
/* @0x16b798 ldr r6, [sp, #0x38] */
/* @0x16b79c vmov s18, r1 */
/* @0x16b7a0 ldr r5, [sp, #0x3c] */
/* @0x16b7a4 ldrb r4, [sp, #0x40] */
/* @0x16b7a8 vmrs APSR_nzcv, fpscr */
/* @0x16b7ac vmovmi.f32 s15, s19 */
/* @0x16b7b0 vmovmi.f32 s19, s17 */
/* @0x16b7b4 vmovmi.f32 s17, s15 */
/* @0x16b7b8 vcmpe.f32 s16, s18 */
/* @0x16b7bc vcvt.f64.f32 d6, s17 */
/* @0x16b7c0 vmrs APSR_nzcv, fpscr */
/* @0x16b7c4 vmovmi.f32 s15, s18 */
/* @0x16b7c8 vmov r0, r1, d6 */
/* @0x16b7cc vmovmi.f32 s18, s16 */
/* @0x16b7d0 vmovmi.f32 s16, s15 */
/* @0x16b7d4 bl 0xb6598 <floor@plt> */
/* @0x16b7d8 vmov d6, r0, r1 */
/* @0x16b7dc vcvt.s32.f64 s15, d6 */
/* @0x16b7e0 vcvt.f32.s32 s15, s15 */
/* @0x16b7e4 vcmp.f32 s15, s17 */
/* @0x16b7e8 vmrs APSR_nzcv, fpscr */
/* @0x16b7ec vldreq s15, [pc, #104] */
/* @0x16b7f0 vaddeq.f32 s17, s17, s15 */
/* @0x16b7f4 vcvt.f64.f32 d7, s16 */
/* @0x16b7f8 vmov r0, r1, d7 */
/* @0x16b7fc bl 0xb6598 <floor@plt> */
/* @0x16b800 ldr r3, [pc, #0x58] */
/* @0x16b804 vmov r2, s17 */
/* @0x16b808 ldr r3, [pc, r3] */
/* @0x16b80c ldr r12, [r3] */
/* @0x16b810 str r6, [sp] */
/* @0x16b814 str r5, [sp, #0x4] */
/* @0x16b818 str r4, [sp, #0x10] */
/* @0x16b81c str r12, [sp, #0x8] */
/* @0x16b820 str r12, [sp, #0xc] */
/* @0x16b824 vmov d6, r0, r1 */
/* @0x16b828 vcvt.s32.f64 s15, d6 */
/* @0x16b82c vmov r0, s19 */
/* @0x16b830 vmov r1, s18 */
/* @0x16b834 vcvt.f32.s32 s15, s15 */
/* @0x16b838 vcmp.f32 s15, s16 */
/* @0x16b83c vmrs APSR_nzcv, fpscr */
/* @0x16b840 vldreq s15, [pc, #20] */
/* @0x16b844 vaddeq.f32 s16, s16, s15 */
/* @0x16b848 vmov r3, s16 */
/* @0x16b84c bl 0x16b31c <_Z15_Draw_RoundRectffffffjjb> */
/* @0x16b850 add sp, sp, #24 */
/* @0x16b854 vpop {d8, d9} */
/* @0x16b858 pop {r4, r5, r6, pc} */
/* @0x16b85c stclo p7, c13, [r3], #-40 */
/* @0x16b860 .word 0x002824f4 */

/* ── FUNC 0x16b864 · GR_Draw_RoundRect_Ext(float, float, float, float, float, float, unsigned int, unsigned int, bool) · size=256 · insn=64 */
/* @0x16b864 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16b868 vpush {d8, d9} */
/* @0x16b86c vmov s17, r2 */
/* @0x16b870 vmov s18, r0 */
/* @0x16b874 ldr r4, [pc, #0xe4] */
/* @0x16b878 vmov s16, r3 */
/* @0x16b87c ldr r7, [sp, #0x38] */
/* @0x16b880 vcmpe.f32 s17, s18 */
/* @0x16b884 ldr r9, [sp, #0x30] */
/* @0x16b888 vmov s19, r1 */
/* @0x16b88c ldr r8, [sp, #0x34] */
/* @0x16b890 ldr r6, [sp, #0x3c] */
/* @0x16b894 ldrb r5, [sp, #0x40] */
/* @0x16b898 vmrs APSR_nzcv, fpscr */
/* @0x16b89c vmovmi.f32 s15, s18 */
/* @0x16b8a0 vmovmi.f32 s18, s17 */
/* @0x16b8a4 vmovmi.f32 s17, s15 */
/* @0x16b8a8 vcmpe.f32 s16, s19 */
/* @0x16b8ac vcvt.f64.f32 d6, s17 */
/* @0x16b8b0 vmrs APSR_nzcv, fpscr */
/* @0x16b8b4 vmovmi.f32 s15, s19 */
/* @0x16b8b8 vmov r0, r1, d6 */
/* @0x16b8bc vmovmi.f32 s19, s16 */
/* @0x16b8c0 vmovmi.f32 s16, s15 */
/* @0x16b8c4 bl 0xb6598 <floor@plt> */
/* @0x16b8c8 vmov d6, r0, r1 */
/* @0x16b8cc vcvt.s32.f64 s15, d6 */
/* @0x16b8d0 vcvt.f32.s32 s15, s15 */
/* @0x16b8d4 vcmp.f32 s15, s17 */
/* @0x16b8d8 vmrs APSR_nzcv, fpscr */
/* @0x16b8dc vldreq s15, [pc, #120] */
/* @0x16b8e0 vaddeq.f32 s17, s17, s15 */
/* @0x16b8e4 vcvt.f64.f32 d7, s16 */
/* @0x16b8e8 vmov r0, r1, d7 */
/* @0x16b8ec bl 0xb6598 <floor@plt> */
/* @0x16b8f0 ldr r4, [pc, r4] */
/* @0x16b8f4 vmov d6, r0, r1 */
/* @0x16b8f8 ldr r1, [r4] */
/* @0x16b8fc mov r0, r7 */
/* @0x16b900 vcvt.s32.f64 s15, d6 */
/* @0x16b904 vcvt.f32.s32 s15, s15 */
/* @0x16b908 vcmp.f32 s15, s16 */
/* @0x16b90c vmrs APSR_nzcv, fpscr */
/* @0x16b910 vldreq s15, [pc, #68] */
/* @0x16b914 vaddeq.f32 s16, s16, s15 */
/* @0x16b918 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16b91c ldr r1, [r4] */
/* @0x16b920 mov r7, r0 */
/* @0x16b924 mov r0, r6 */
/* @0x16b928 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16b92c str r7, [sp, #0x38] */
/* @0x16b930 str r9, [sp, #0x30] */
/* @0x16b934 str r8, [sp, #0x34] */
/* @0x16b938 str r5, [sp, #0x40] */
/* @0x16b93c vmov r1, s19 */
/* @0x16b940 vmov r2, s17 */
/* @0x16b944 vmov r3, s16 */
/* @0x16b948 str r0, [sp, #0x3c] */
/* @0x16b94c vmov r0, s18 */
/* @0x16b950 vpop {d8, d9} */
/* @0x16b954 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16b958 b 0x16b31c <_Z15_Draw_RoundRectffffffjjb> */
/* @0x16b95c stclo p7, c13, [r3], #-40 */
/* @0x16b960 eoreq r2, r8, r0, lsl r4 */

/* ── FUNC 0x16b964 · GR_Draw_Primitive_Begin(int, int) · size=244 · insn=61 */
/* @0x16b964 push {r3, r4, r5, r6, r7, lr} */
/* @0x16b968 mov r5, r1 */
/* @0x16b96c ldr r4, [pc, #0xc0] */
/* @0x16b970 mov r3, #0 */
/* @0x16b974 ldr r2, [pc, #0xbc] */
/* @0x16b978 add r4, pc, r4 */
/* @0x16b97c ldr r12, [pc, #0xb8] */
/* @0x16b980 ldr r1, [pc, #0xb8] */
/* @0x16b984 ldr lr, [r4, r2] */
/* @0x16b988 ldr r2, [pc, #0xb4] */
/* @0x16b98c str r3, [lr] */
/* @0x16b990 ldr r12, [r4, r12] */
/* @0x16b994 str r0, [r12] */
/* @0x16b998 mov r0, r5 */
/* @0x16b99c ldr r6, [r4, r1] */
/* @0x16b9a0 str r5, [r6] */
/* @0x16b9a4 ldr r7, [r4, r2] */
/* @0x16b9a8 str r3, [r7] */
/* @0x16b9ac bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x16b9b0 cmp r0, #0 */
/* @0x16b9b4 strne r5, [r6] */
/* @0x16b9b8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x16b9bc add r2, r5, #1 */
/* @0x16b9c0 movw r3, #0x4001 */
/* @0x16b9c4 cmp r2, r3 */
/* @0x16b9c8 bhi 0x16b9e8 <_Z23GR_Draw_Primitive_Beginii+0x84> */
/* @0x16b9cc cmn r5, #1 */
/* @0x16b9d0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x16b9d4 ldr r0, [pc, #0x6c] */
/* @0x16b9d8 mov r1, #1 */
/* @0x16b9dc pop {r3, r4, r5, r6, r7, lr} */
/* @0x16b9e0 add r0, pc, r0 */
/* @0x16b9e4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x16b9e8 ldrsh r3, [r5, #20] */
/* @0x16b9ec ldr r2, [pc, #0x58] */
/* @0x16b9f0 str r5, [r7] */
/* @0x16b9f4 str r3, [r6] */
/* @0x16b9f8 ldr r0, [r4, r2] */
/* @0x16b9fc ldr r1, [pc, #0x4c] */
/* @0x16ba00 ldr r2, [pc, #0x4c] */
/* @0x16ba04 ldr r0, [r0, #0x4] */
/* @0x16ba08 ldr r1, [r4, r1] */
/* @0x16ba0c ldr r3, [r0, r3, lsl #2] */
/* @0x16ba10 ldr r3, [r3] */
/* @0x16ba14 vldr s14, [r3, #4] */
/* @0x16ba18 vldr s15, [r3, #8] */
/* @0x16ba1c vcvt.f32.s32 s14, s14 */
/* @0x16ba20 vcvt.f32.s32 s15, s15 */
/* @0x16ba24 vstr s14, [r1] */
/* @0x16ba28 ldr r3, [r4, r2] */
/* @0x16ba2c vstr s15, [r3] */
/* @0x16ba30 pop {r3, r4, r5, r6, r7, pc} */
/* @0x16ba34 .word 0x002862d8 */
/* @0x16ba38 .word 0xffffe534 */
/* @0x16ba3c .word 0xffffe538 */
/* @0x16ba40 .word 0xffffe53c */
/* @0x16ba44 .word 0xffffe540 */
/* @0x16ba48 andseq lr, sp, r12, asr lr */
/* @0x16ba4c .word 0xffffbccc */
/* @0x16ba50 .word 0xffffe544 */
/* @0x16ba54 .word 0xffffe548 */

/* ── FUNC 0x16ba58 · GR_Draw_Vertex(float, float) · size=136 · insn=34 */
/* @0x16ba58 ldr r3, [pc, #0x6c] */
/* @0x16ba5c ldr r2, [pc, #0x6c] */
/* @0x16ba60 add r3, pc, r3 */
/* @0x16ba64 push {r4, r5, r6, r7, r8} */
/* @0x16ba68 ldr r4, [r3, r2] */
/* @0x16ba6c ldr r12, [r4] */
/* @0x16ba70 cmp r12, #1000 */
/* @0x16ba74 bgt 0x16bac4 <_Z14GR_Draw_Vertexff+0x6c> */
/* @0x16ba78 ldr r2, [pc, #0x54] */
/* @0x16ba7c add r8, r12, r12, lsl #1 */
/* @0x16ba80 ldr r7, [pc, #0x50] */
/* @0x16ba84 mov r5, #0 */
/* @0x16ba88 ldr r6, [pc, #0x4c] */
/* @0x16ba8c add r12, r12, #1 */
/* @0x16ba90 ldr r2, [r3, r2] */
/* @0x16ba94 add r2, r2, r8, lsl #3 */
/* @0x16ba98 str r0, [r2] */
/* @0x16ba9c str r1, [r2, #0x4] */
/* @0x16baa0 ldr r1, [r3, r7] */
/* @0x16baa4 ldr r1, [r1] */
/* @0x16baa8 str r1, [r2, #0x8] */
/* @0x16baac ldr r3, [r3, r6] */
/* @0x16bab0 str r5, [r2, #0x14] */
/* @0x16bab4 str r12, [r4] */
/* @0x16bab8 ldr r3, [r3] */
/* @0x16babc str r5, [r2, #0x10] */
/* @0x16bac0 str r3, [r2, #0xc] */
/* @0x16bac4 pop {r4, r5, r6, r7, r8} */
/* @0x16bac8 bx lr */
/* @0x16bacc .word 0x002861f0 */
/* @0x16bad0 .word 0xffffe534 */
/* @0x16bad4 .word 0xffffe54c */
/* @0x16bad8 .word 0xffffbcd0 */
/* @0x16badc .word 0xffffc0ac */

/* ── FUNC 0x16bae0 · GR_Draw_Vertex_Color(float, float, unsigned int, float) · size=144 · insn=36 */
/* @0x16bae0 push {r4, r5, r6, r7, r8, lr} */
/* @0x16bae4 mov r7, r0 */
/* @0x16bae8 ldr r4, [pc, #0x74] */
/* @0x16baec mov r6, r1 */
/* @0x16baf0 mov r8, r2 */
/* @0x16baf4 ldr r4, [pc, r4] */
/* @0x16baf8 ldr r12, [r4] */
/* @0x16bafc cmp r12, #1000 */
/* @0x16bb00 popgt {r4, r5, r6, r7, r8, pc} */
/* @0x16bb04 mov r0, r3 */
/* @0x16bb08 bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x16bb0c ldr r5, [r4] */
/* @0x16bb10 ldr r2, [pc, #0x50] */
/* @0x16bb14 ldr r3, [pc, #0x50] */
/* @0x16bb18 ldr r2, [pc, r2] */
/* @0x16bb1c add r5, r5, r5, lsl #1 */
/* @0x16bb20 ldr r3, [pc, r3] */
/* @0x16bb24 ldr r2, [r2] */
/* @0x16bb28 add r5, r3, r5, lsl #3 */
/* @0x16bb2c str r7, [r5] */
/* @0x16bb30 str r2, [r5, #0x8] */
/* @0x16bb34 str r6, [r5, #0x4] */
/* @0x16bb38 mov r1, r0 */
/* @0x16bb3c mov r0, r8 */
/* @0x16bb40 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16bb44 ldr r2, [r4] */
/* @0x16bb48 mov r3, #0 */
/* @0x16bb4c str r3, [r5, #0x10] */
/* @0x16bb50 str r3, [r5, #0x14] */
/* @0x16bb54 add r3, r2, #1 */
/* @0x16bb58 str r3, [r4] */
/* @0x16bb5c str r0, [r5, #0xc] */
/* @0x16bb60 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16bb64 mlaeq r8, r0, r6, r4 */
/* @0x16bb68 eoreq r1, r8, r8, lsl #28 */
/* @0x16bb6c eoreq r4, r8, r12, ror r6 */

/* ── FUNC 0x16bb70 · GR_Draw_Vertex_Texture(float, float, float, float) · size=276 · insn=69 */
/* @0x16bb70 ldr r12, [pc, #0xec] */
/* @0x16bb74 vmov s13, r3 */
/* @0x16bb78 push {r4, r5, r6, r7, r8} */
/* @0x16bb7c add r12, pc, r12 */
/* @0x16bb80 ldr r4, [pc, #0xe0] */
/* @0x16bb84 vmov s12, r2 */
/* @0x16bb88 ldr r4, [r12, r4] */
/* @0x16bb8c ldr r3, [r4] */
/* @0x16bb90 cmp r3, #1000 */
/* @0x16bb94 ble 0x16bba0 <_Z22GR_Draw_Vertex_Textureffff+0x30> */
/* @0x16bb98 pop {r4, r5, r6, r7, r8} */
/* @0x16bb9c bx lr */
/* @0x16bba0 ldr r5, [pc, #0xc4] */
/* @0x16bba4 add r2, r3, r3, lsl #1 */
/* @0x16bba8 ldr r7, [pc, #0xc0] */
/* @0x16bbac ldr r6, [pc, #0xc0] */
/* @0x16bbb0 ldr r8, [r12, r5] */
/* @0x16bbb4 ldr r5, [pc, #0xbc] */
/* @0x16bbb8 add r2, r8, r2, lsl #3 */
/* @0x16bbbc str r0, [r2] */
/* @0x16bbc0 str r1, [r2, #0x4] */
/* @0x16bbc4 ldr r1, [r12, r7] */
/* @0x16bbc8 ldr r1, [r1] */
/* @0x16bbcc str r1, [r2, #0x8] */
/* @0x16bbd0 ldr r1, [r12, r6] */
/* @0x16bbd4 ldr r1, [r1] */
/* @0x16bbd8 str r1, [r2, #0xc] */
/* @0x16bbdc ldr r1, [r12, r5] */
/* @0x16bbe0 ldr r1, [r1] */
/* @0x16bbe4 cmp r1, #0 */
/* @0x16bbe8 vstreq s12, [r2, #16] */
/* @0x16bbec vstreq s13, [r2, #20] */
/* @0x16bbf0 beq 0x16bc54 <_Z22GR_Draw_Vertex_Textureffff+0xe4> */
/* @0x16bbf4 ldrsh r0, [r1] */
/* @0x16bbf8 ldrsh r5, [r1, #12] */
/* @0x16bbfc vmov s14, r0 */
/* @0x16bc00 ldr r0, [pc, #0x74] */
/* @0x16bc04 vmov s10, r5 */
/* @0x16bc08 ldrsh r5, [r1, #2] */
/* @0x16bc0c vcvt.f32.s32 s14, s14 */
/* @0x16bc10 vmov s15, r5 */
/* @0x16bc14 ldrsh r5, [r1, #14] */
/* @0x16bc18 ldr r1, [r12, r0] */
/* @0x16bc1c vldr s11, [r1] */
/* @0x16bc20 ldr r1, [pc, #0x58] */
/* @0x16bc24 vcvt.f32.s32 s10, s10 */
/* @0x16bc28 vmla.f32 s14, s12, s10 */
/* @0x16bc2c vdiv.f32 s14, s14, s11 */
/* @0x16bc30 vmov s11, r5 */
/* @0x16bc34 vcvt.f32.s32 s15, s15 */
/* @0x16bc38 vstr s14, [r2, #16] */
/* @0x16bc3c ldr r1, [r12, r1] */
/* @0x16bc40 vldr s14, [r1] */
/* @0x16bc44 vcvt.f32.s32 s12, s11 */
/* @0x16bc48 vmla.f32 s15, s13, s12 */
/* @0x16bc4c vdiv.f32 s15, s15, s14 */
/* @0x16bc50 vstr s15, [r2, #20] */
/* @0x16bc54 add r3, r3, #1 */
/* @0x16bc58 str r3, [r4] */
/* @0x16bc5c pop {r4, r5, r6, r7, r8} */
/* @0x16bc60 bx lr */
/* @0x16bc64 .word 0x002860d4 */
/* @0x16bc68 .word 0xffffe534 */
/* @0x16bc6c .word 0xffffe54c */
/* @0x16bc70 .word 0xffffbcd0 */
/* @0x16bc74 .word 0xffffc0ac */
/* @0x16bc78 .word 0xffffe540 */
/* @0x16bc7c .word 0xffffe544 */
/* @0x16bc80 .word 0xffffe548 */

/* ── FUNC 0x16bc84 · GR_Draw_Vertex_Texture_Color(float, float, float, float, unsigned int, float) · size=300 · insn=75 */
/* @0x16bc84 push {r4, r5, r6, r7, r8, lr} */
/* @0x16bc88 vpush {d8} */
/* @0x16bc8c vmov s16, r3 */
/* @0x16bc90 ldr r4, [pc, #0xfc] */
/* @0x16bc94 mov r8, r0 */
/* @0x16bc98 ldr r12, [pc, #0xf8] */
/* @0x16bc9c mov r7, r1 */
/* @0x16bca0 add r4, pc, r4 */
/* @0x16bca4 vmov s17, r2 */
/* @0x16bca8 ldr r5, [r4, r12] */
/* @0x16bcac ldr r3, [r5] */
/* @0x16bcb0 cmp r3, #1000 */
/* @0x16bcb4 ble 0x16bcc0 <_Z28GR_Draw_Vertex_Texture_Colorffffjf+0x3c> */
/* @0x16bcb8 vpop {d8} */
/* @0x16bcbc pop {r4, r5, r6, r7, r8, pc} */
/* @0x16bcc0 ldr r0, [sp, #0x24] */
/* @0x16bcc4 bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x16bcc8 ldr r6, [r5] */
/* @0x16bccc ldr r2, [pc, #0xc8] */
/* @0x16bcd0 ldr r3, [pc, #0xc8] */
/* @0x16bcd4 add r6, r6, r6, lsl #1 */
/* @0x16bcd8 ldr r2, [r4, r2] */
/* @0x16bcdc add r6, r2, r6, lsl #3 */
/* @0x16bce0 str r8, [r6] */
/* @0x16bce4 str r7, [r6, #0x4] */
/* @0x16bce8 ldr r3, [r4, r3] */
/* @0x16bcec ldr r3, [r3] */
/* @0x16bcf0 str r3, [r6, #0x8] */
/* @0x16bcf4 mov r1, r0 */
/* @0x16bcf8 ldr r0, [sp, #0x20] */
/* @0x16bcfc bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x16bd00 ldr r3, [pc, #0x9c] */
/* @0x16bd04 str r0, [r6, #0xc] */
/* @0x16bd08 ldr r3, [r4, r3] */
/* @0x16bd0c ldr r3, [r3] */
/* @0x16bd10 cmp r3, #0 */
/* @0x16bd14 vstreq s17, [r6, #16] */
/* @0x16bd18 vstreq s16, [r6, #20] */
/* @0x16bd1c beq 0x16bd80 <_Z28GR_Draw_Vertex_Texture_Colorffffjf+0xfc> */
/* @0x16bd20 ldrsh r1, [r3] */
/* @0x16bd24 ldrsh r2, [r3, #12] */
/* @0x16bd28 vmov s14, r1 */
/* @0x16bd2c ldrsh r1, [r3, #2] */
/* @0x16bd30 vmov s11, r2 */
/* @0x16bd34 ldrsh r3, [r3, #14] */
/* @0x16bd38 vcvt.f32.s32 s14, s14 */
/* @0x16bd3c ldr r2, [pc, #0x64] */
/* @0x16bd40 vmov s15, r1 */
/* @0x16bd44 vmov s13, r3 */
/* @0x16bd48 ldr r3, [r4, r2] */
/* @0x16bd4c vldr s12, [r3] */
/* @0x16bd50 ldr r3, [pc, #0x54] */
/* @0x16bd54 vcvt.f32.s32 s11, s11 */
/* @0x16bd58 vmla.f32 s14, s17, s11 */
/* @0x16bd5c vdiv.f32 s14, s14, s12 */
/* @0x16bd60 vcvt.f32.s32 s15, s15 */
/* @0x16bd64 vstr s14, [r6, #16] */
/* @0x16bd68 ldr r3, [r4, r3] */
/* @0x16bd6c vldr s14, [r3] */
/* @0x16bd70 vcvt.f32.s32 s13, s13 */
/* @0x16bd74 vmla.f32 s15, s16, s13 */
/* @0x16bd78 vdiv.f32 s15, s15, s14 */
/* @0x16bd7c vstr s15, [r6, #20] */
/* @0x16bd80 vpop {d8} */
/* @0x16bd84 ldr r3, [r5] */
/* @0x16bd88 add r3, r3, #1 */
/* @0x16bd8c str r3, [r5] */
/* @0x16bd90 pop {r4, r5, r6, r7, r8, pc} */
/* @0x16bd94 .word 0x00285fb0 */
/* @0x16bd98 .word 0xffffe534 */
/* @0x16bd9c .word 0xffffe54c */
/* @0x16bda0 .word 0xffffbcd0 */
/* @0x16bda4 .word 0xffffe540 */
/* @0x16bda8 .word 0xffffe544 */
/* @0x16bdac .word 0xffffe548 */

/* ── FUNC 0x16bdb0 · GR_Draw_Primitive_End() · size=308 · insn=77 */
/* @0x16bdb0 push {r4, r5, r6, r7, r8, lr} */
/* @0x16bdb4 ldr r4, [pc, #0x110] */
/* @0x16bdb8 ldr r3, [pc, #0x110] */
/* @0x16bdbc add r4, pc, r4 */
/* @0x16bdc0 ldr r5, [r4, r3] */
/* @0x16bdc4 ldr r3, [r5] */
/* @0x16bdc8 sub r2, r3, #1 */
/* @0x16bdcc cmp r2, #5 */
/* @0x16bdd0 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x16bdd4 sub r3, r3, #2 */
/* @0x16bdd8 cmp r3, #4 */
/* @0x16bddc addls pc, pc, r3, lsl #2 */
/* @0x16bde0 b 0x16be70 <_Z21GR_Draw_Primitive_Endv+0xc0> */
/* @0x16bde4 b 0x16be80 <_Z21GR_Draw_Primitive_Endv+0xd0> */
/* @0x16bde8 b 0x16be98 <_Z21GR_Draw_Primitive_Endv+0xe8> */
/* @0x16bdec b 0x16beac <_Z21GR_Draw_Primitive_Endv+0xfc> */
/* @0x16bdf0 b 0x16bdf8 <_Z21GR_Draw_Primitive_Endv+0x48> */
/* @0x16bdf4 b 0x16bdf8 <_Z21GR_Draw_Primitive_Endv+0x48> */
/* @0x16bdf8 ldr r3, [pc, #0xd4] */
/* @0x16bdfc ldr r6, [r4, r3] */
/* @0x16be00 ldr r8, [r6] */
/* @0x16be04 sub r8, r8, #2 */
/* @0x16be08 ldr r3, [pc, #0xc8] */
/* @0x16be0c ldr r7, [r4, r3] */
/* @0x16be10 ldr r0, [r7] */
/* @0x16be14 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x16be18 cmp r0, #0 */
/* @0x16be1c moveq r1, r0 */
/* @0x16be20 beq 0x16be3c <_Z21GR_Draw_Primitive_Endv+0x8c> */
/* @0x16be24 ldr r3, [pc, #0xb0] */
/* @0x16be28 ldr r2, [r7] */
/* @0x16be2c ldr r3, [r4, r3] */
/* @0x16be30 ldr r3, [r3, #0x4] */
/* @0x16be34 ldr r3, [r3, r2, lsl #2] */
/* @0x16be38 ldr r1, [r3] */
/* @0x16be3c cmp r8, #0 */
/* @0x16be40 pople {r4, r5, r6, r7, r8, pc} */
/* @0x16be44 ldr r3, [r6] */
/* @0x16be48 mov r2, #24 */
/* @0x16be4c ldr r0, [r5] */
/* @0x16be50 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x16be54 ldr r2, [r6] */
/* @0x16be58 ldr r3, [pc, #0x80] */
/* @0x16be5c add r2, r2, r2, lsl #1 */
/* @0x16be60 ldr r1, [r4, r3] */
/* @0x16be64 lsl r2, r2, #3 */
/* @0x16be68 pop {r4, r5, r6, r7, r8, lr} */
/* @0x16be6c b 0xb65bc <memcpy@plt> */
/* @0x16be70 ldr r3, [pc, #0x5c] */
/* @0x16be74 ldr r6, [r4, r3] */
/* @0x16be78 ldr r8, [r6] */
/* @0x16be7c b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58> */
/* @0x16be80 ldr r3, [pc, #0x4c] */
/* @0x16be84 ldr r6, [r4, r3] */
/* @0x16be88 ldr r8, [r6] */
/* @0x16be8c add r8, r8, r8, lsr #31 */
/* @0x16be90 asr r8, r8, #1 */
/* @0x16be94 b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58> */
/* @0x16be98 ldr r3, [pc, #0x34] */
/* @0x16be9c ldr r6, [r4, r3] */
/* @0x16bea0 ldr r8, [r6] */
/* @0x16bea4 sub r8, r8, #1 */
/* @0x16bea8 b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58> */
/* @0x16beac ldr r3, [pc, #0x20] */
/* @0x16beb0 movw r8, #0x5556 */
/* @0x16beb4 movt r8, #0x5555 */
/* @0x16beb8 ldr r6, [r4, r3] */
/* @0x16bebc ldr r3, [r6] */
/* @0x16bec0 smull r2, r8, r8, r3 */
/* @0x16bec4 sub r8, r8, r3, asr #31 */
/* @0x16bec8 b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58> */
/* @0x16becc mlaeq r8, r4, lr, r5 */
/* @0x16bed0 .word 0xffffe538 */
/* @0x16bed4 .word 0xffffe534 */
/* @0x16bed8 .word 0xffffe53c */
/* @0x16bedc .word 0xffffbccc */
/* @0x16bee0 .word 0xffffe54c */

/* ── FUNC 0x16bee4 · GR_Draw_Arrow(float, float, float, float, float) · size=224 · insn=56 */
/* @0x16bee4 str lr, [sp, #-0x4]! */
/* @0x16bee8 vpush {d8, d9, d10, d11} */
/* @0x16beec vmov s21, r1 */
/* @0x16bef0 vmov s17, r3 */
/* @0x16bef4 sub sp, sp, #20 */
/* @0x16bef8 vmov s22, r0 */
/* @0x16befc vldr s16, [sp, #56] */
/* @0x16bf00 vsub.f32 s19, s17, s21 */
/* @0x16bf04 vmov s18, r2 */
/* @0x16bf08 vmul.f32 s14, s19, s19 */
/* @0x16bf0c vsub.f32 s20, s18, s22 */
/* @0x16bf10 vmla.f32 s14, s20, s20 */
/* @0x16bf14 vsqrt.f32 s15, s14 */
/* @0x16bf18 vcmp.f32 s15, s15 */
/* @0x16bf1c vmrs APSR_nzcv, fpscr */
/* @0x16bf20 bne 0x16bfb4 <_Z13GR_Draw_Arrowfffff+0xd0> */
/* @0x16bf24 vcmp.f32 s15, #0 */
/* @0x16bf28 vmrs APSR_nzcv, fpscr */
/* @0x16bf2c beq 0x16bfa8 <_Z13GR_Draw_Arrowfffff+0xc4> */
/* @0x16bf30 vcmp.f32 s15, s16 */
/* @0x16bf34 vmov r2, s18 */
/* @0x16bf38 vmov r0, s22 */
/* @0x16bf3c vmov r1, s21 */
/* @0x16bf40 vmrs APSR_nzcv, fpscr */
/* @0x16bf44 vmovmi.f32 s16, s15 */
/* @0x16bf48 vmov r3, s17 */
/* @0x16bf4c vmul.f32 s20, s16, s20 */
/* @0x16bf50 vmul.f32 s16, s16, s19 */
/* @0x16bf54 vdiv.f32 s20, s20, s15 */
/* @0x16bf58 vdiv.f32 s16, s16, s15 */
/* @0x16bf5c bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x16bf60 vmov r2, s18 */
/* @0x16bf64 mov r3, #0 */
/* @0x16bf68 str r3, [sp, #0x8] */
/* @0x16bf6c vmov r3, s17 */
/* @0x16bf70 vmov.f32 s14, #3.000000e+00 */
/* @0x16bf74 vdiv.f32 s15, s16, s14 */
/* @0x16bf78 vdiv.f32 s14, s20, s14 */
/* @0x16bf7c vsub.f32 s18, s18, s20 */
/* @0x16bf80 vsub.f32 s16, s17, s16 */
/* @0x16bf84 vadd.f32 s12, s18, s15 */
/* @0x16bf88 vsub.f32 s13, s16, s14 */
/* @0x16bf8c vstr s12, [sp] */
/* @0x16bf90 vsub.f32 s15, s18, s15 */
/* @0x16bf94 vstr s13, [sp, #4] */
/* @0x16bf98 vadd.f32 s14, s16, s14 */
/* @0x16bf9c vmov r0, s15 */
/* @0x16bfa0 vmov r1, s14 */
/* @0x16bfa4 bl 0x16a6f0 <_Z16GR_Draw_Triangleffffffb> */
/* @0x16bfa8 add sp, sp, #20 */
/* @0x16bfac vpop {d8, d9, d10, d11} */
/* @0x16bfb0 ldr pc, [sp], #4 */
/* @0x16bfb4 vmov r0, s14 */
/* @0x16bfb8 bl 0xb6700 <sqrtf@plt> */
/* @0x16bfbc vmov s15, r0 */
/* @0x16bfc0 b 0x16bf24 <_Z13GR_Draw_Arrowfffff+0x40> */

/* ── FUNC 0x16bfc4 · GR_Draw_Button(float, float, float, float, bool) · size=276 · insn=69 */
/* @0x16bfc4 push {r4, lr} */
/* @0x16bfc8 vpush {d8, d9} */
/* @0x16bfcc sub sp, sp, #24 */
/* @0x16bfd0 vmov s19, r0 */
/* @0x16bfd4 ldrb r4, [sp, #0x30] */
/* @0x16bfd8 vmov s18, r1 */
/* @0x16bfdc str r0, [sp] */
/* @0x16bfe0 vmov s17, r2 */
/* @0x16bfe4 cmp r4, #0 */
/* @0x16bfe8 vmov s16, r3 */
/* @0x16bfec str r3, [sp, #0x4] */
/* @0x16bff0 bne 0x16c080 <_Z14GR_Draw_Buttonffffb+0xbc> */
/* @0x16bff4 mov r3, r1 */
/* @0x16bff8 str r4, [sp, #0x14] */
/* @0x16bffc movw r12, #0x8080 */
/* @0x16c000 movt r12, #0x80 */
/* @0x16c004 str r12, [sp, #0x8] */
/* @0x16c008 str r12, [sp, #0xc] */
/* @0x16c00c str r12, [sp, #0x10] */
/* @0x16c010 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb> */
/* @0x16c014 mvn r3, #-16777216 */
/* @0x16c018 vstr s17, [sp] */
/* @0x16c01c str r3, [sp, #0x8] */
/* @0x16c020 str r3, [sp, #0xc] */
/* @0x16c024 vstr s16, [sp, #4] */
/* @0x16c028 str r3, [sp, #0x10] */
/* @0x16c02c str r4, [sp, #0x14] */
/* @0x16c030 vmov r0, s19 */
/* @0x16c034 vmov r1, s16 */
/* @0x16c038 vmov r2, s17 */
/* @0x16c03c vmov r3, s18 */
/* @0x16c040 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb> */
/* @0x16c044 vmov.f32 s15, #2.000000e+00 */
/* @0x16c048 mov r3, #0 */
/* @0x16c04c str r3, [sp, #0x30] */
/* @0x16c050 vadd.f32 s19, s19, s15 */
/* @0x16c054 vadd.f32 s18, s18, s15 */
/* @0x16c058 vmov r0, s19 */
/* @0x16c05c vsub.f32 s17, s17, s15 */
/* @0x16c060 vmov r1, s18 */
/* @0x16c064 vsub.f32 s15, s16, s15 */
/* @0x16c068 vmov r2, s17 */
/* @0x16c06c vmov r3, s15 */
/* @0x16c070 add sp, sp, #24 */
/* @0x16c074 vpop {d8, d9} */
/* @0x16c078 pop {r4, lr} */
/* @0x16c07c b 0x16aa1c <_Z20YYGML_draw_rectangleffffb> */
/* @0x16c080 mvn r3, #-16777216 */
/* @0x16c084 mov r4, #0 */
/* @0x16c088 str r3, [sp, #0x8] */
/* @0x16c08c str r3, [sp, #0xc] */
/* @0x16c090 str r3, [sp, #0x10] */
/* @0x16c094 mov r3, r1 */
/* @0x16c098 str r4, [sp, #0x14] */
/* @0x16c09c bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb> */
/* @0x16c0a0 str r4, [sp, #0x14] */
/* @0x16c0a4 vstr s17, [sp] */
/* @0x16c0a8 vstr s16, [sp, #4] */
/* @0x16c0ac movw r3, #0x8080 */
/* @0x16c0b0 vmov r0, s19 */
/* @0x16c0b4 movt r3, #0x80 */
/* @0x16c0b8 vmov r1, s16 */
/* @0x16c0bc str r3, [sp, #0x8] */
/* @0x16c0c0 str r3, [sp, #0xc] */
/* @0x16c0c4 str r3, [sp, #0x10] */
/* @0x16c0c8 vmov r2, s17 */
/* @0x16c0cc vmov r3, s18 */
/* @0x16c0d0 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb> */
/* @0x16c0d4 b 0x16c044 <_Z14GR_Draw_Buttonffffb+0x80> */

/* ── FUNC 0x16c0d8 · GR_Draw_Healthbar(float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, int, bool, bool) · size=488 · insn=122 */
/* @0x16c0d8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x16c0dc vpush {d8, d9, d10} */
/* @0x16c0e0 sub sp, sp, #28 */
/* @0x16c0e4 vldr s16, [sp, #80] */
/* @0x16c0e8 vmov s18, r0 */
/* @0x16c0ec ldrb r12, [sp, #0x68] */
/* @0x16c0f0 vmov s20, r1 */
/* @0x16c0f4 vmov s17, r2 */
/* @0x16c0f8 ldr r7, [sp, #0x58] */
/* @0x16c0fc cmp r12, #0 */
/* @0x16c100 vmov s19, r3 */
/* @0x16c104 ldr r12, [sp, #0x54] */
/* @0x16c108 ldr r6, [sp, #0x5c] */
/* @0x16c10c ldr r8, [sp, #0x60] */
/* @0x16c110 ldr r4, [sp, #0x64] */
/* @0x16c114 ldrb r5, [sp, #0x6c] */
/* @0x16c118 bne 0x16c228 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x150> */
/* @0x16c11c vcmpe.f32 s16, #0 */
/* @0x16c120 vmrs APSR_nzcv, fpscr */
/* @0x16c124 bmi 0x16c16c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x94> */
/* @0x16c128 vldr s15, [pc, #392] */
/* @0x16c12c vcmpe.f32 s16, s15 */
/* @0x16c130 vmrs APSR_nzcv, fpscr */
/* @0x16c134 vmovgt.f32 s14, #1.000000e+00 */
/* @0x16c138 vmovgt.f32 s16, s15 */
/* @0x16c13c ble 0x16c15c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x84> */
/* @0x16c140 cmp r4, #3 */
/* @0x16c144 addls pc, pc, r4, lsl #2 */
/* @0x16c148 b 0x16c178 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xa0> */
/* @0x16c14c b 0x16c178 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xa0> */
/* @0x16c150 b 0x16c2a4 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x1cc> */
/* @0x16c154 b 0x16c27c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x1a4> */
/* @0x16c158 b 0x16c290 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x1b8> */
/* @0x16c15c vcmp.f32 s16, #0 */
/* @0x16c160 vmrs APSR_nzcv, fpscr */
/* @0x16c164 vdivne.f32 s14, s16, s15 */
/* @0x16c168 bne 0x16c140 <_Z17GR_Draw_Healthbarfffffjjjjibb+0x68> */
/* @0x16c16c add sp, sp, #28 */
/* @0x16c170 vpop {d8, d9, d10} */
/* @0x16c174 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x16c178 vsub.f32 s17, s17, s18 */
/* @0x16c17c vmov.f32 s15, s18 */
/* @0x16c180 vmla.f32 s15, s14, s17 */
/* @0x16c184 vmov.f32 s17, s15 */
/* @0x16c188 vldr s15, [pc, #300] */
/* @0x16c18c mov r4, #0 */
/* @0x16c190 vcmpe.f32 s16, s15 */
/* @0x16c194 vmrs APSR_nzcv, fpscr */
/* @0x16c198 vsubgt.f32 s16, s16, s15 */
/* @0x16c19c movgt r1, r8 */
/* @0x16c1a0 movle r1, r6 */
/* @0x16c1a4 movgt r0, r6 */
/* @0x16c1a8 movle r0, r7 */
/* @0x16c1ac vdivgt.f32 s16, s16, s15 */
/* @0x16c1b0 vdivle.f32 s15, s16, s15 */
/* @0x16c1b4 vmovgt r2, s16 */
/* @0x16c1b8 vmovle r2, s15 */
/* @0x16c1bc bl 0x16caa8 <_Z14GR_Color_Mergejjf> */
/* @0x16c1c0 str r4, [sp, #0x10] */
/* @0x16c1c4 vmov r1, s20 */
/* @0x16c1c8 vmov r2, s17 */
/* @0x16c1cc vmov r3, s19 */
/* @0x16c1d0 str r0, [sp] */
/* @0x16c1d4 str r0, [sp, #0x4] */
/* @0x16c1d8 str r0, [sp, #0x8] */
/* @0x16c1dc str r0, [sp, #0xc] */
/* @0x16c1e0 vmov r0, s18 */
/* @0x16c1e4 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x16c1e8 cmp r5, r4 */
/* @0x16c1ec beq 0x16c16c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x94> */
/* @0x16c1f0 mov r3, #1 */
/* @0x16c1f4 vmov r0, s18 */
/* @0x16c1f8 str r3, [sp, #0x60] */
/* @0x16c1fc vmov r1, s20 */
/* @0x16c200 vmov r2, s17 */
/* @0x16c204 vmov r3, s19 */
/* @0x16c208 str r4, [sp, #0x50] */
/* @0x16c20c str r4, [sp, #0x54] */
/* @0x16c210 str r4, [sp, #0x58] */
/* @0x16c214 str r4, [sp, #0x5c] */
/* @0x16c218 add sp, sp, #28 */
/* @0x16c21c vpop {d8, d9, d10} */
/* @0x16c220 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x16c224 b 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x16c228 mov r9, #0 */
/* @0x16c22c str r12, [sp] */
/* @0x16c230 str r12, [sp, #0x4] */
/* @0x16c234 str r12, [sp, #0x8] */
/* @0x16c238 str r12, [sp, #0xc] */
/* @0x16c23c str r9, [sp, #0x10] */
/* @0x16c240 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x16c244 cmp r5, r9 */
/* @0x16c248 beq 0x16c11c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x44> */
/* @0x16c24c mov r3, #1 */
/* @0x16c250 str r9, [sp] */
/* @0x16c254 str r3, [sp, #0x10] */
/* @0x16c258 str r9, [sp, #0x4] */
/* @0x16c25c str r9, [sp, #0x8] */
/* @0x16c260 str r9, [sp, #0xc] */
/* @0x16c264 vmov r0, s18 */
/* @0x16c268 vmov r1, s20 */
/* @0x16c26c vmov r2, s17 */
/* @0x16c270 vmov r3, s19 */
/* @0x16c274 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x16c278 b 0x16c11c <_Z17GR_Draw_Healthbarfffffjjjjibb+0x44> */
/* @0x16c27c vsub.f32 s19, s19, s20 */
/* @0x16c280 vmov.f32 s15, s20 */
/* @0x16c284 vmla.f32 s15, s14, s19 */
/* @0x16c288 vmov.f32 s19, s15 */
/* @0x16c28c b 0x16c188 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xb0> */
/* @0x16c290 vsub.f32 s20, s19, s20 */
/* @0x16c294 vmov.f32 s15, s19 */
/* @0x16c298 vmls.f32 s15, s14, s20 */
/* @0x16c29c vmov.f32 s20, s15 */
/* @0x16c2a0 b 0x16c188 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xb0> */
/* @0x16c2a4 vsub.f32 s18, s17, s18 */
/* @0x16c2a8 vmov.f32 s15, s17 */
/* @0x16c2ac vmls.f32 s15, s14, s18 */
/* @0x16c2b0 vmov.f32 s18, s15 */
/* @0x16c2b4 b 0x16c188 <_Z17GR_Draw_Healthbarfffffjjjjibb+0xb0> */
/* @0x16c2b8 sbcmi r0, r8, #0 */
/* @0x16c2bc submi r0, r8, #0 */
