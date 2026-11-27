/* libyoyo.so 覆盖卡组 0234
 * 函数 0x281a2c..0x282f8c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x281a2c · _spRotateTimeline_apply · size=492 · insn=123 */
/* @0x281a2c push {r3, r4, r5, r6, r7, lr} */
/* @0x281a30 vpush {d8} */
/* @0x281a34 vmov s16, r3 */
/* @0x281a38 ldr r5, [r0, #0x10] */
/* @0x281a3c vldr s15, [r5] */
/* @0x281a40 vcmpe.f32 s15, s16 */
/* @0x281a44 mov r4, r0 */
/* @0x281a48 vmrs APSR_nzcv, fpscr */
/* @0x281a4c bgt 0x281ae4 <_spRotateTimeline_apply+0xb8> */
/* @0x281a50 ldr r2, [r0, #0xc] */
/* @0x281a54 ldr r1, [r1, #0x8] */
/* @0x281a58 sub r3, r2, #2 */
/* @0x281a5c ldr r0, [r0, #0x14] */
/* @0x281a60 add r3, r5, r3, lsl #2 */
/* @0x281a64 vldr s15, [r3] */
/* @0x281a68 vcmpe.f32 s16, s15 */
/* @0x281a6c ldr r6, [r1, r0, lsl #2] */
/* @0x281a70 vmrs APSR_nzcv, fpscr */
/* @0x281a74 blt 0x281aec <_spRotateTimeline_apply+0xc0> */
/* @0x281a78 ldr r2, [r6] */
/* @0x281a7c vldr s15, [r3, #4] */
/* @0x281a80 vldr s14, [r2, #24] */
/* @0x281a84 vadd.f32 s15, s14, s15 */
/* @0x281a88 vldr s12, [r6, #28] */
/* @0x281a8c vldr s13, [pc, #376] */
/* @0x281a90 vsub.f32 s15, s15, s12 */
/* @0x281a94 vcmpe.f32 s15, s13 */
/* @0x281a98 vmrs APSR_nzcv, fpscr */
/* @0x281a9c ble 0x281ab4 <_spRotateTimeline_apply+0x88> */
/* @0x281aa0 vldr s14, [pc, #360] */
/* @0x281aa4 vsub.f32 s15, s15, s14 */
/* @0x281aa8 vcmpe.f32 s15, s13 */
/* @0x281aac vmrs APSR_nzcv, fpscr */
/* @0x281ab0 bgt 0x281aa4 <_spRotateTimeline_apply+0x78> */
/* @0x281ab4 vldr s13, [pc, #344] */
/* @0x281ab8 vcmpe.f32 s15, s13 */
/* @0x281abc vmrs APSR_nzcv, fpscr */
/* @0x281ac0 bpl 0x281ad8 <_spRotateTimeline_apply+0xac> */
/* @0x281ac4 vldr s14, [pc, #324] */
/* @0x281ac8 vadd.f32 s15, s15, s14 */
/* @0x281acc vcmpe.f32 s15, s13 */
/* @0x281ad0 vmrs APSR_nzcv, fpscr */
/* @0x281ad4 bmi 0x281ac8 <_spRotateTimeline_apply+0x9c> */
/* @0x281ad8 vldr s14, [sp, #40] */
/* @0x281adc vmla.f32 s12, s15, s14 */
/* @0x281ae0 vstr s12, [r6, #28] */
/* @0x281ae4 vpop {d8} */
/* @0x281ae8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x281aec mov r1, r2 */
/* @0x281af0 vmov.f32 s0, s16 */
/* @0x281af4 mov r0, r5 */
/* @0x281af8 mov r2, #2 */
/* @0x281afc bl 0x280ed0 <printbuf_free+0x20> */
/* @0x281b00 vmov.f32 s14, #1.000000e+00 */
/* @0x281b04 sub r7, r0, #1 */
/* @0x281b08 asr r1, r0, #1 */
/* @0x281b0c sub r1, r1, #1 */
/* @0x281b10 mov r0, r4 */
/* @0x281b14 lsl r7, r7, #2 */
/* @0x281b18 add r5, r5, r7 */
/* @0x281b1c vldr s15, [r5, #4] */
/* @0x281b20 vldr s13, [r5, #-4] */
/* @0x281b24 vsub.f32 s16, s16, s15 */
/* @0x281b28 vldr s17, [r5] */
/* @0x281b2c vsub.f32 s15, s13, s15 */
/* @0x281b30 vdiv.f32 s15, s16, s15 */
/* @0x281b34 vsub.f32 s14, s14, s15 */
/* @0x281b38 vmov r2, s14 */
/* @0x281b3c bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x281b40 ldr r3, [r4, #0x10] */
/* @0x281b44 vldr s12, [pc, #192] */
/* @0x281b48 add r7, r3, r7 */
/* @0x281b4c vldr s14, [r7, #8] */
/* @0x281b50 vsub.f32 s14, s14, s17 */
/* @0x281b54 vcmpe.f32 s14, s12 */
/* @0x281b58 vmrs APSR_nzcv, fpscr */
/* @0x281b5c vmov s15, r0 */
/* @0x281b60 ble 0x281b78 <_spRotateTimeline_apply+0x14c> */
/* @0x281b64 vldr s13, [pc, #164] */
/* @0x281b68 vsub.f32 s14, s14, s13 */
/* @0x281b6c vcmpe.f32 s14, s12 */
/* @0x281b70 vmrs APSR_nzcv, fpscr */
/* @0x281b74 bgt 0x281b68 <_spRotateTimeline_apply+0x13c> */
/* @0x281b78 vldr s12, [pc, #148] */
/* @0x281b7c vcmpe.f32 s14, s12 */
/* @0x281b80 vmrs APSR_nzcv, fpscr */
/* @0x281b84 bpl 0x281b9c <_spRotateTimeline_apply+0x170> */
/* @0x281b88 vldr s13, [pc, #128] */
/* @0x281b8c vadd.f32 s14, s14, s13 */
/* @0x281b90 vcmpe.f32 s14, s12 */
/* @0x281b94 vmrs APSR_nzcv, fpscr */
/* @0x281b98 bmi 0x281b8c <_spRotateTimeline_apply+0x160> */
/* @0x281b9c vmla.f32 s17, s14, s15 */
/* @0x281ba0 ldr r3, [r6] */
/* @0x281ba4 vldr s14, [r3, #24] */
/* @0x281ba8 vldr s12, [r6, #28] */
/* @0x281bac vldr s13, [pc, #88] */
/* @0x281bb0 vadd.f32 s15, s17, s14 */
/* @0x281bb4 vsub.f32 s15, s15, s12 */
/* @0x281bb8 vcmpe.f32 s15, s13 */
/* @0x281bbc vmrs APSR_nzcv, fpscr */
/* @0x281bc0 ble 0x281bd8 <_spRotateTimeline_apply+0x1ac> */
/* @0x281bc4 vldr s14, [pc, #68] */
/* @0x281bc8 vsub.f32 s15, s15, s14 */
/* @0x281bcc vcmpe.f32 s15, s13 */
/* @0x281bd0 vmrs APSR_nzcv, fpscr */
/* @0x281bd4 bgt 0x281bc8 <_spRotateTimeline_apply+0x19c> */
/* @0x281bd8 vldr s13, [pc, #52] */
/* @0x281bdc vcmpe.f32 s15, s13 */
/* @0x281be0 vmrs APSR_nzcv, fpscr */
/* @0x281be4 bpl 0x281ad8 <_spRotateTimeline_apply+0xac> */
/* @0x281be8 vldr s14, [pc, #32] */
/* @0x281bec vadd.f32 s15, s15, s14 */
/* @0x281bf0 vcmpe.f32 s15, s13 */
/* @0x281bf4 vmrs APSR_nzcv, fpscr */
/* @0x281bf8 bmi 0x281bec <_spRotateTimeline_apply+0x1c0> */
/* @0x281bfc vldr s14, [sp, #40] */
/* @0x281c00 vmla.f32 s12, s15, s14 */
/* @0x281c04 vstr s12, [r6, #28] */
/* @0x281c08 b 0x281ae4 <_spRotateTimeline_apply+0xb8> */
/* @0x281c0c teqmi r4, #0 */
/* @0x281c10 .word 0x43b40000 */
/* @0x281c14 teqgt r4, #0 */

/* ── FUNC 0x281c18 · _spTranslateTimeline_apply · size=348 · insn=87 */
/* @0x281c18 push {r3, r4, r5, r6, r7, lr} */
/* @0x281c1c vpush {d8, d9} */
/* @0x281c20 vmov s16, r3 */
/* @0x281c24 vldr s17, [sp, #48] */
/* @0x281c28 ldr r6, [r0, #0x10] */
/* @0x281c2c vldr s15, [r6] */
/* @0x281c30 vcmpe.f32 s15, s16 */
/* @0x281c34 mov r4, r0 */
/* @0x281c38 vmrs APSR_nzcv, fpscr */
/* @0x281c3c bgt 0x281ca4 <_spTranslateTimeline_apply+0x8c> */
/* @0x281c40 ldr r2, [r0, #0xc] */
/* @0x281c44 ldr r1, [r1, #0x8] */
/* @0x281c48 sub r3, r2, #3 */
/* @0x281c4c ldr r0, [r0, #0x14] */
/* @0x281c50 add r3, r6, r3, lsl #2 */
/* @0x281c54 vldr s15, [r3] */
/* @0x281c58 vcmpe.f32 s16, s15 */
/* @0x281c5c ldr r5, [r1, r0, lsl #2] */
/* @0x281c60 vmrs APSR_nzcv, fpscr */
/* @0x281c64 blt 0x281cac <_spTranslateTimeline_apply+0x94> */
/* @0x281c68 vldr s15, [r3, #4] */
/* @0x281c6c ldr r2, [r5] */
/* @0x281c70 vldr s12, [r2, #16] */
/* @0x281c74 vadd.f32 s12, s12, s15 */
/* @0x281c78 vldr s14, [r5, #20] */
/* @0x281c7c vldr s13, [r2, #20] */
/* @0x281c80 vldr s15, [r5, #24] */
/* @0x281c84 vsub.f32 s12, s12, s14 */
/* @0x281c88 vmla.f32 s14, s12, s17 */
/* @0x281c8c vstr s14, [r5, #20] */
/* @0x281c90 vldr s14, [r3, #8] */
/* @0x281c94 vadd.f32 s14, s13, s14 */
/* @0x281c98 vsub.f32 s14, s14, s15 */
/* @0x281c9c vmla.f32 s15, s14, s17 */
/* @0x281ca0 vstr s15, [r5, #24] */
/* @0x281ca4 vpop {d8, d9} */
/* @0x281ca8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x281cac mov r1, r2 */
/* @0x281cb0 vmov.f32 s0, s16 */
/* @0x281cb4 mov r0, r6 */
/* @0x281cb8 mov r2, #3 */
/* @0x281cbc bl 0x280ed0 <printbuf_free+0x20> */
/* @0x281cc0 movw r2, #0x5556 */
/* @0x281cc4 movt r2, #0x5555 */
/* @0x281cc8 vmov.f32 s14, #1.000000e+00 */
/* @0x281ccc sub r7, r0, #2 */
/* @0x281cd0 mov r3, r0 */
/* @0x281cd4 smull r1, r2, r2, r3 */
/* @0x281cd8 lsl r7, r7, #2 */
/* @0x281cdc add r6, r6, r7 */
/* @0x281ce0 vldr s15, [r6, #8] */
/* @0x281ce4 vldr s13, [r6, #-4] */
/* @0x281ce8 vsub.f32 s16, s16, s15 */
/* @0x281cec mov r0, r4 */
/* @0x281cf0 vldr s19, [r6] */
/* @0x281cf4 vldr s18, [r6, #4] */
/* @0x281cf8 sub r1, r2, r3, asr #31 */
/* @0x281cfc sub r1, r1, #1 */
/* @0x281d00 vsub.f32 s15, s13, s15 */
/* @0x281d04 vdiv.f32 s15, s16, s15 */
/* @0x281d08 vsub.f32 s14, s14, s15 */
/* @0x281d0c vmov r2, s14 */
/* @0x281d10 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x281d14 ldr r2, [r4, #0x10] */
/* @0x281d18 ldr r3, [r5] */
/* @0x281d1c vldr s14, [r3, #16] */
/* @0x281d20 add r7, r2, r7 */
/* @0x281d24 vadd.f32 s14, s19, s14 */
/* @0x281d28 vldr s10, [r7, #12] */
/* @0x281d2c vldr s11, [r5, #20] */
/* @0x281d30 vldr s15, [r3, #20] */
/* @0x281d34 vldr s13, [r5, #24] */
/* @0x281d38 vsub.f32 s19, s10, s19 */
/* @0x281d3c vadd.f32 s15, s18, s15 */
/* @0x281d40 vmov s12, r0 */
/* @0x281d44 vmla.f32 s14, s19, s12 */
/* @0x281d48 vsub.f32 s14, s14, s11 */
/* @0x281d4c vmla.f32 s11, s14, s17 */
/* @0x281d50 vstr s11, [r5, #20] */
/* @0x281d54 vldr s14, [r7, #16] */
/* @0x281d58 vsub.f32 s18, s14, s18 */
/* @0x281d5c vmla.f32 s15, s18, s12 */
/* @0x281d60 vsub.f32 s15, s15, s13 */
/* @0x281d64 vmla.f32 s13, s15, s17 */
/* @0x281d68 vpop {d8, d9} */
/* @0x281d6c vstr s13, [r5, #24] */
/* @0x281d70 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x281d74 · _spScaleTimeline_apply · size=348 · insn=87 */
/* @0x281d74 push {r3, r4, r5, r6, r7, lr} */
/* @0x281d78 vpush {d8, d9} */
/* @0x281d7c vmov s16, r3 */
/* @0x281d80 vldr s17, [sp, #48] */
/* @0x281d84 ldr r6, [r0, #0x10] */
/* @0x281d88 vldr s15, [r6] */
/* @0x281d8c vcmpe.f32 s15, s16 */
/* @0x281d90 mov r4, r0 */
/* @0x281d94 vmrs APSR_nzcv, fpscr */
/* @0x281d98 bgt 0x281e00 <_spScaleTimeline_apply+0x8c> */
/* @0x281d9c ldr r2, [r0, #0xc] */
/* @0x281da0 ldr r1, [r1, #0x8] */
/* @0x281da4 sub r3, r2, #3 */
/* @0x281da8 ldr r0, [r0, #0x14] */
/* @0x281dac add r3, r6, r3, lsl #2 */
/* @0x281db0 vldr s15, [r3] */
/* @0x281db4 vcmpe.f32 s16, s15 */
/* @0x281db8 ldr r5, [r1, r0, lsl #2] */
/* @0x281dbc vmrs APSR_nzcv, fpscr */
/* @0x281dc0 blt 0x281e08 <_spScaleTimeline_apply+0x94> */
/* @0x281dc4 vldr s14, [r5, #32] */
/* @0x281dc8 vmov.f32 s12, s14 */
/* @0x281dcc vldr s15, [r3, #4] */
/* @0x281dd0 ldr r2, [r5] */
/* @0x281dd4 vldr s13, [r2, #28] */
/* @0x281dd8 vnmls.f32 s12, s13, s15 */
/* @0x281ddc vldr s15, [r5, #36] */
/* @0x281de0 vldr s13, [r2, #32] */
/* @0x281de4 vmla.f32 s14, s12, s17 */
/* @0x281de8 vmov.f32 s10, s15 */
/* @0x281dec vstr s14, [r5, #32] */
/* @0x281df0 vldr s14, [r3, #8] */
/* @0x281df4 vnmls.f32 s10, s13, s14 */
/* @0x281df8 vmla.f32 s15, s10, s17 */
/* @0x281dfc vstr s15, [r5, #36] */
/* @0x281e00 vpop {d8, d9} */
/* @0x281e04 pop {r3, r4, r5, r6, r7, pc} */
/* @0x281e08 mov r1, r2 */
/* @0x281e0c vmov.f32 s0, s16 */
/* @0x281e10 mov r0, r6 */
/* @0x281e14 mov r2, #3 */
/* @0x281e18 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x281e1c movw r2, #0x5556 */
/* @0x281e20 movt r2, #0x5555 */
/* @0x281e24 vmov.f32 s14, #1.000000e+00 */
/* @0x281e28 sub r7, r0, #2 */
/* @0x281e2c mov r3, r0 */
/* @0x281e30 smull r1, r2, r2, r3 */
/* @0x281e34 lsl r7, r7, #2 */
/* @0x281e38 add r6, r6, r7 */
/* @0x281e3c vldr s15, [r6, #8] */
/* @0x281e40 vldr s13, [r6, #-4] */
/* @0x281e44 vsub.f32 s16, s16, s15 */
/* @0x281e48 mov r0, r4 */
/* @0x281e4c vldr s19, [r6] */
/* @0x281e50 vldr s18, [r6, #4] */
/* @0x281e54 sub r1, r2, r3, asr #31 */
/* @0x281e58 sub r1, r1, #1 */
/* @0x281e5c vsub.f32 s15, s13, s15 */
/* @0x281e60 vdiv.f32 s15, s16, s15 */
/* @0x281e64 vsub.f32 s14, s14, s15 */
/* @0x281e68 vmov r2, s14 */
/* @0x281e6c bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x281e70 ldr r2, [r4, #0x10] */
/* @0x281e74 vldr s13, [r5, #32] */
/* @0x281e78 ldr r3, [r5] */
/* @0x281e7c add r7, r2, r7 */
/* @0x281e80 vldr s10, [r7, #12] */
/* @0x281e84 vsub.f32 s10, s10, s19 */
/* @0x281e88 vldr s11, [r3, #28] */
/* @0x281e8c vldr s12, [r3, #32] */
/* @0x281e90 vldr s15, [r5, #36] */
/* @0x281e94 vmov s14, r0 */
/* @0x281e98 vmla.f32 s19, s10, s14 */
/* @0x281e9c vmov.f32 s10, s13 */
/* @0x281ea0 vnmls.f32 s10, s19, s11 */
/* @0x281ea4 vmla.f32 s13, s10, s17 */
/* @0x281ea8 vstr s13, [r5, #32] */
/* @0x281eac vldr s13, [r7, #16] */
/* @0x281eb0 vsub.f32 s13, s13, s18 */
/* @0x281eb4 vmla.f32 s18, s13, s14 */
/* @0x281eb8 vmov.f32 s14, s15 */
/* @0x281ebc vnmls.f32 s14, s18, s12 */
/* @0x281ec0 vmla.f32 s15, s14, s17 */
/* @0x281ec4 vpop {d8, d9} */
/* @0x281ec8 vstr s15, [r5, #36] */
/* @0x281ecc pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x281ed0 · _spShearTimeline_apply · size=348 · insn=87 */
/* @0x281ed0 push {r3, r4, r5, r6, r7, lr} */
/* @0x281ed4 vpush {d8, d9} */
/* @0x281ed8 vmov s16, r3 */
/* @0x281edc vldr s17, [sp, #48] */
/* @0x281ee0 ldr r6, [r0, #0x10] */
/* @0x281ee4 vldr s15, [r6] */
/* @0x281ee8 vcmpe.f32 s15, s16 */
/* @0x281eec mov r4, r0 */
/* @0x281ef0 vmrs APSR_nzcv, fpscr */
/* @0x281ef4 bgt 0x281f5c <_spShearTimeline_apply+0x8c> */
/* @0x281ef8 ldr r2, [r0, #0xc] */
/* @0x281efc ldr r1, [r1, #0x8] */
/* @0x281f00 sub r3, r2, #3 */
/* @0x281f04 ldr r0, [r0, #0x14] */
/* @0x281f08 add r3, r6, r3, lsl #2 */
/* @0x281f0c vldr s15, [r3] */
/* @0x281f10 vcmpe.f32 s16, s15 */
/* @0x281f14 ldr r5, [r1, r0, lsl #2] */
/* @0x281f18 vmrs APSR_nzcv, fpscr */
/* @0x281f1c blt 0x281f64 <_spShearTimeline_apply+0x94> */
/* @0x281f20 vldr s15, [r3, #4] */
/* @0x281f24 ldr r2, [r5] */
/* @0x281f28 vldr s12, [r2, #36] */
/* @0x281f2c vadd.f32 s12, s12, s15 */
/* @0x281f30 vldr s14, [r5, #40] */
/* @0x281f34 vldr s13, [r2, #40] */
/* @0x281f38 vldr s15, [r5, #44] */
/* @0x281f3c vsub.f32 s12, s12, s14 */
/* @0x281f40 vmla.f32 s14, s12, s17 */
/* @0x281f44 vstr s14, [r5, #40] */
/* @0x281f48 vldr s14, [r3, #8] */
/* @0x281f4c vadd.f32 s14, s13, s14 */
/* @0x281f50 vsub.f32 s14, s14, s15 */
/* @0x281f54 vmla.f32 s15, s14, s17 */
/* @0x281f58 vstr s15, [r5, #44] */
/* @0x281f5c vpop {d8, d9} */
/* @0x281f60 pop {r3, r4, r5, r6, r7, pc} */
/* @0x281f64 mov r1, r2 */
/* @0x281f68 vmov.f32 s0, s16 */
/* @0x281f6c mov r0, r6 */
/* @0x281f70 mov r2, #3 */
/* @0x281f74 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x281f78 movw r2, #0x5556 */
/* @0x281f7c movt r2, #0x5555 */
/* @0x281f80 vmov.f32 s14, #1.000000e+00 */
/* @0x281f84 sub r7, r0, #2 */
/* @0x281f88 mov r3, r0 */
/* @0x281f8c smull r1, r2, r2, r3 */
/* @0x281f90 lsl r7, r7, #2 */
/* @0x281f94 add r6, r6, r7 */
/* @0x281f98 vldr s15, [r6, #8] */
/* @0x281f9c vldr s13, [r6, #-4] */
/* @0x281fa0 vsub.f32 s16, s16, s15 */
/* @0x281fa4 mov r0, r4 */
/* @0x281fa8 vldr s19, [r6] */
/* @0x281fac vldr s18, [r6, #4] */
/* @0x281fb0 sub r1, r2, r3, asr #31 */
/* @0x281fb4 sub r1, r1, #1 */
/* @0x281fb8 vsub.f32 s15, s13, s15 */
/* @0x281fbc vdiv.f32 s15, s16, s15 */
/* @0x281fc0 vsub.f32 s14, s14, s15 */
/* @0x281fc4 vmov r2, s14 */
/* @0x281fc8 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x281fcc ldr r2, [r4, #0x10] */
/* @0x281fd0 ldr r3, [r5] */
/* @0x281fd4 vldr s14, [r3, #36] */
/* @0x281fd8 add r7, r2, r7 */
/* @0x281fdc vadd.f32 s14, s19, s14 */
/* @0x281fe0 vldr s10, [r7, #12] */
/* @0x281fe4 vldr s11, [r5, #40] */
/* @0x281fe8 vldr s15, [r3, #40] */
/* @0x281fec vldr s13, [r5, #44] */
/* @0x281ff0 vsub.f32 s19, s10, s19 */
/* @0x281ff4 vadd.f32 s15, s18, s15 */
/* @0x281ff8 vmov s12, r0 */
/* @0x281ffc vmla.f32 s14, s19, s12 */
/* @0x282000 vsub.f32 s14, s14, s11 */
/* @0x282004 vmla.f32 s11, s14, s17 */
/* @0x282008 vstr s11, [r5, #40] */
/* @0x28200c vldr s14, [r7, #16] */
/* @0x282010 vsub.f32 s18, s14, s18 */
/* @0x282014 vmla.f32 s15, s18, s12 */
/* @0x282018 vsub.f32 s15, s15, s13 */
/* @0x28201c vmla.f32 s13, s15, s17 */
/* @0x282020 vpop {d8, d9} */
/* @0x282024 vstr s13, [r5, #44] */
/* @0x282028 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x28202c · _spColorTimeline_apply · size=412 · insn=103 */
/* @0x28202c push {r3, r4, r5, r6, r7, lr} */
/* @0x282030 vpush {d8, d9, d10} */
/* @0x282034 vmov s16, r3 */
/* @0x282038 vldr s17, [sp, #56] */
/* @0x28203c ldr r5, [r0, #0x10] */
/* @0x282040 vldr s15, [r5] */
/* @0x282044 vcmpe.f32 s15, s16 */
/* @0x282048 mov r4, r0 */
/* @0x28204c mov r6, r1 */
/* @0x282050 vmrs APSR_nzcv, fpscr */
/* @0x282054 bgt 0x2820bc <_spColorTimeline_apply+0x90> */
/* @0x282058 ldr r1, [r0, #0xc] */
/* @0x28205c sub r3, r1, #-1073741819 */
/* @0x282060 lsl r3, r3, #2 */
/* @0x282064 add r2, r5, r3 */
/* @0x282068 vldr s15, [r2] */
/* @0x28206c vcmpe.f32 s16, s15 */
/* @0x282070 vmrs APSR_nzcv, fpscr */
/* @0x282074 blt 0x2820c4 <_spColorTimeline_apply+0x98> */
/* @0x282078 add r3, r3, #4 */
/* @0x28207c add r5, r5, r3 */
/* @0x282080 vldr s11, [r5] */
/* @0x282084 vldr s12, [r5, #4] */
/* @0x282088 vldr s13, [r5, #8] */
/* @0x28208c vldr s14, [r5, #12] */
/* @0x282090 vmov.f32 s15, #1.000000e+00 */
/* @0x282094 ldr r2, [r4, #0x14] */
/* @0x282098 ldr r3, [r6, #0x14] */
/* @0x28209c ldr r3, [r3, r2, lsl #2] */
/* @0x2820a0 vcmpe.f32 s17, s15 */
/* @0x2820a4 vmrs APSR_nzcv, fpscr */
/* @0x2820a8 bmi 0x282180 <_spColorTimeline_apply+0x154> */
/* @0x2820ac vstr s11, [r3, #8] */
/* @0x2820b0 vstr s12, [r3, #12] */
/* @0x2820b4 vstr s13, [r3, #16] */
/* @0x2820b8 vstr s14, [r3, #20] */
/* @0x2820bc vpop {d8, d9, d10} */
/* @0x2820c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2820c4 vmov.f32 s0, s16 */
/* @0x2820c8 mov r0, r5 */
/* @0x2820cc mov r2, #5 */
/* @0x2820d0 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x2820d4 movw r2, #0x6667 */
/* @0x2820d8 movt r2, #0x6666 */
/* @0x2820dc vmov.f32 s14, #1.000000e+00 */
/* @0x2820e0 sub r7, r0, #4 */
/* @0x2820e4 mvn r1, r0 */
/* @0x2820e8 smull r3, r2, r2, r0 */
/* @0x2820ec lsl r7, r7, #2 */
/* @0x2820f0 add r5, r5, r7 */
/* @0x2820f4 vldr s15, [r5, #16] */
/* @0x2820f8 vldr s13, [r5, #-4] */
/* @0x2820fc vsub.f32 s16, s16, s15 */
/* @0x282100 lsr r1, r1, #31 */
/* @0x282104 mov r0, r4 */
/* @0x282108 vldr s21, [r5] */
/* @0x28210c vldr s20, [r5, #4] */
/* @0x282110 rsb r1, r1, r2, asr #1 */
/* @0x282114 vldr s19, [r5, #8] */
/* @0x282118 vldr s18, [r5, #12] */
/* @0x28211c vsub.f32 s15, s13, s15 */
/* @0x282120 vdiv.f32 s15, s16, s15 */
/* @0x282124 vsub.f32 s14, s14, s15 */
/* @0x282128 vmov r2, s14 */
/* @0x28212c bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x282130 ldr r3, [r4, #0x10] */
/* @0x282134 add r3, r3, r7 */
/* @0x282138 vldr s11, [r3, #20] */
/* @0x28213c vldr s12, [r3, #24] */
/* @0x282140 vsub.f32 s11, s11, s21 */
/* @0x282144 vldr s13, [r3, #28] */
/* @0x282148 vldr s14, [r3, #32] */
/* @0x28214c vsub.f32 s12, s12, s20 */
/* @0x282150 vsub.f32 s13, s13, s19 */
/* @0x282154 vmov s15, r0 */
/* @0x282158 vsub.f32 s14, s14, s18 */
/* @0x28215c vmla.f32 s21, s11, s15 */
/* @0x282160 vmla.f32 s20, s12, s15 */
/* @0x282164 vmla.f32 s19, s13, s15 */
/* @0x282168 vmla.f32 s18, s14, s15 */
/* @0x28216c vmov.f32 s11, s21 */
/* @0x282170 vmov.f32 s12, s20 */
/* @0x282174 vmov.f32 s13, s19 */
/* @0x282178 vmov.f32 s14, s18 */
/* @0x28217c b 0x282090 <_spColorTimeline_apply+0x64> */
/* @0x282180 vldr s8, [r3, #8] */
/* @0x282184 vldr s9, [r3, #12] */
/* @0x282188 vldr s10, [r3, #16] */
/* @0x28218c vldr s15, [r3, #20] */
/* @0x282190 vsub.f32 s11, s11, s8 */
/* @0x282194 vsub.f32 s12, s12, s9 */
/* @0x282198 vsub.f32 s13, s13, s10 */
/* @0x28219c vsub.f32 s14, s14, s15 */
/* @0x2821a0 vmla.f32 s8, s11, s17 */
/* @0x2821a4 vmla.f32 s9, s12, s17 */
/* @0x2821a8 vstr s8, [r3, #8] */
/* @0x2821ac vmla.f32 s10, s13, s17 */
/* @0x2821b0 vstr s9, [r3, #12] */
/* @0x2821b4 vmla.f32 s15, s14, s17 */
/* @0x2821b8 vstr s10, [r3, #16] */
/* @0x2821bc vpop {d8, d9, d10} */
/* @0x2821c0 vstr s15, [r3, #20] */
/* @0x2821c4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2821c8 · _spDeformTimeline_apply · size=612 · insn=153 */
/* @0x2821c8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2821cc vpush {d8, d9} */
/* @0x2821d0 mov r4, r0 */
/* @0x2821d4 vldr s16, [sp, #48] */
/* @0x2821d8 ldr r1, [r1, #0x14] */
/* @0x2821dc vmov s17, r3 */
/* @0x2821e0 ldr r0, [r0, #0x1c] */
/* @0x2821e4 ldr r2, [r4, #0x20] */
/* @0x2821e8 ldr r5, [r1, r0, lsl #2] */
/* @0x2821ec ldr r3, [r5, #0x18] */
/* @0x2821f0 cmp r3, r2 */
/* @0x2821f4 beq 0x28222c <_spDeformTimeline_apply+0x64> */
/* @0x2821f8 cmp r3, #0 */
/* @0x2821fc beq 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x282200 ldr r1, [r3, #0x4] */
/* @0x282204 cmp r1, #2 */
/* @0x282208 bne 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x28220c ldr r1, [r3, #0x80] */
/* @0x282210 cmp r1, #0 */
/* @0x282214 beq 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x282218 ldr r3, [r3, #0x7c] */
/* @0x28221c cmp r2, r3 */
/* @0x282220 beq 0x28222c <_spDeformTimeline_apply+0x64> */
/* @0x282224 vpop {d8, d9} */
/* @0x282228 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28222c ldr r2, [r4, #0x10] */
/* @0x282230 vldr s15, [r2] */
/* @0x282234 vcmpe.f32 s15, s17 */
/* @0x282238 vmrs APSR_nzcv, fpscr */
/* @0x28223c bgt 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x282240 ldr r6, [r4, #0x14] */
/* @0x282244 ldr r3, [r5, #0x20] */
/* @0x282248 cmp r6, r3 */
/* @0x28224c ble 0x2822f4 <_spDeformTimeline_apply+0x12c> */
/* @0x282250 ldr r3, [r5, #0x1c] */
/* @0x282254 cmp r6, r3 */
/* @0x282258 vmovle.f32 s16, #1.000000e+00 */
/* @0x28225c bgt 0x2822c8 <_spDeformTimeline_apply+0x100> */
/* @0x282260 ldr r3, [r4, #0xc] */
/* @0x282264 str r6, [r5, #0x20] */
/* @0x282268 sub r1, r3, #-1073741823 */
/* @0x28226c add r0, r2, r1, lsl #2 */
/* @0x282270 vldr s15, [r0] */
/* @0x282274 vcmpe.f32 s17, s15 */
/* @0x282278 vmrs APSR_nzcv, fpscr */
/* @0x28227c blt 0x282304 <_spDeformTimeline_apply+0x13c> */
/* @0x282280 vmov.f32 s15, #1.000000e+00 */
/* @0x282284 ldr r3, [r4, #0x18] */
/* @0x282288 ldr r1, [r3, r1, lsl #2] */
/* @0x28228c vcmpe.f32 s16, s15 */
/* @0x282290 vmrs APSR_nzcv, fpscr */
/* @0x282294 bpl 0x2823d8 <_spDeformTimeline_apply+0x210> */
/* @0x282298 cmp r6, #0 */
/* @0x28229c ble 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x2822a0 ldr r3, [r5, #0x24] */
/* @0x2822a4 add r6, r1, r6, lsl #2 */
/* @0x2822a8 vldmia r1!, {s14} */
/* @0x2822ac vldr s15, [r3] */
/* @0x2822b0 vsub.f32 s14, s14, s15 */
/* @0x2822b4 cmp r1, r6 */
/* @0x2822b8 vmla.f32 s15, s14, s16 */
/* @0x2822bc vstmia r3!, {s15} */
/* @0x2822c0 bne 0x2822a8 <_spDeformTimeline_apply+0xe0> */
/* @0x2822c4 b 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x2822c8 ldr r0, [r5, #0x24] */
/* @0x2822cc bl 0x285c80 <_free> */
/* @0x2822d0 ldr r1, [pc, #0x150] */
/* @0x2822d4 movw r2, #0x2d6 */
/* @0x2822d8 lsl r0, r6, #2 */
/* @0x2822dc add r1, pc, r1 */
/* @0x2822e0 bl 0x285c10 <_malloc> */
/* @0x2822e4 ldr r3, [r5, #0x20] */
/* @0x2822e8 ldr r2, [r4, #0x10] */
/* @0x2822ec str r6, [r5, #0x1c] */
/* @0x2822f0 str r0, [r5, #0x24] */
/* @0x2822f4 vmov.f32 s15, #1.000000e+00 */
/* @0x2822f8 cmp r6, r3 */
/* @0x2822fc vmovne.f32 s16, s15 */
/* @0x282300 b 0x282260 <_spDeformTimeline_apply+0x98> */
/* @0x282304 subs r3, r3, #2 */
/* @0x282308 bne 0x282394 <_spDeformTimeline_apply+0x1cc> */
/* @0x28230c mov r8, r3 */
/* @0x282310 mov r7, #4 */
/* @0x282314 mov r1, r3 */
/* @0x282318 add r3, r2, r7 */
/* @0x28231c add r2, r2, r8 */
/* @0x282320 vldr s15, [r3] */
/* @0x282324 vldr s14, [r2] */
/* @0x282328 vsub.f32 s17, s17, s15 */
/* @0x28232c mov r0, r4 */
/* @0x282330 vsub.f32 s15, s14, s15 */
/* @0x282334 vdiv.f32 s15, s17, s15 */
/* @0x282338 vmov.f32 s18, #1.000000e+00 */
/* @0x28233c vsub.f32 s15, s18, s15 */
/* @0x282340 vmov r2, s15 */
/* @0x282344 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x282348 vcmpe.f32 s16, s18 */
/* @0x28234c ldr r2, [r4, #0x18] */
/* @0x282350 vmrs APSR_nzcv, fpscr */
/* @0x282354 ldr r3, [r2, r8] */
/* @0x282358 ldr r2, [r2, r7] */
/* @0x28235c vmov s13, r0 */
/* @0x282360 bmi 0x2823ec <_spDeformTimeline_apply+0x224> */
/* @0x282364 cmp r6, #0 */
/* @0x282368 addgt r6, r3, r6, lsl #2 */
/* @0x28236c ldrgt r1, [r5, #0x24] */
/* @0x282370 ble 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x282374 vldmia r3!, {s15} */
/* @0x282378 vldmia r2!, {s14} */
/* @0x28237c vsub.f32 s14, s14, s15 */
/* @0x282380 cmp r3, r6 */
/* @0x282384 vmla.f32 s15, s14, s13 */
/* @0x282388 vstmia r1!, {s15} */
/* @0x28238c bne 0x282374 <_spDeformTimeline_apply+0x1ac> */
/* @0x282390 b 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x282394 asr r0, r3, #1 */
/* @0x282398 mov r1, #0 */
/* @0x28239c add r12, r0, #1 */
/* @0x2823a0 add lr, r2, r12, lsl #2 */
/* @0x2823a4 vldr s15, [lr] */
/* @0x2823a8 vcmpe.f32 s17, s15 */
/* @0x2823ac vmrs APSR_nzcv, fpscr */
/* @0x2823b0 movge r1, r12 */
/* @0x2823b4 movlt r3, r0 */
/* @0x2823b8 add r0, r1, r3 */
/* @0x2823bc cmp r1, r3 */
/* @0x2823c0 asr r0, r0, #1 */
/* @0x2823c4 bne 0x28239c <_spDeformTimeline_apply+0x1d4> */
/* @0x2823c8 add r7, r1, #1 */
/* @0x2823cc lsl r7, r7, #2 */
/* @0x2823d0 sub r8, r7, #4 */
/* @0x2823d4 b 0x282318 <_spDeformTimeline_apply+0x150> */
/* @0x2823d8 vpop {d8, d9} */
/* @0x2823dc lsl r2, r6, #2 */
/* @0x2823e0 ldr r0, [r5, #0x24] */
/* @0x2823e4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2823e8 b 0xb65bc <memcpy@plt> */
/* @0x2823ec cmp r6, #0 */
/* @0x2823f0 ble 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x2823f4 ldr r1, [r5, #0x24] */
/* @0x2823f8 add r6, r3, r6, lsl #2 */
/* @0x2823fc vldmia r3!, {s14} */
/* @0x282400 vldmia r2!, {s12} */
/* @0x282404 vsub.f32 s12, s12, s14 */
/* @0x282408 vldr s15, [r1] */
/* @0x28240c cmp r3, r6 */
/* @0x282410 vmla.f32 s14, s12, s13 */
/* @0x282414 vsub.f32 s14, s14, s15 */
/* @0x282418 vmla.f32 s15, s14, s16 */
/* @0x28241c vstmia r1!, {s15} */
/* @0x282420 bne 0x2823fc <_spDeformTimeline_apply+0x234> */
/* @0x282424 b 0x282224 <_spDeformTimeline_apply+0x5c> */
/* @0x282428 andeq r5, sp, r4, ror r1 */

/* ── FUNC 0x28242c · _spIkConstraintTimeline_apply · size=284 · insn=71 */
/* @0x28242c push {r3, r4, r5, r6, r7, lr} */
/* @0x282430 vpush {d8} */
/* @0x282434 vmov s16, r3 */
/* @0x282438 ldr r5, [r0, #0x10] */
/* @0x28243c vldr s15, [r5] */
/* @0x282440 vcmpe.f32 s15, s16 */
/* @0x282444 mov r4, r0 */
/* @0x282448 vmrs APSR_nzcv, fpscr */
/* @0x28244c bgt 0x28249c <_spIkConstraintTimeline_apply+0x70> */
/* @0x282450 ldr r2, [r0, #0xc] */
/* @0x282454 ldr r1, [r1, #0x20] */
/* @0x282458 sub r3, r2, #3 */
/* @0x28245c ldr r0, [r0, #0x14] */
/* @0x282460 add r3, r5, r3, lsl #2 */
/* @0x282464 vldr s15, [r3] */
/* @0x282468 vcmpe.f32 s16, s15 */
/* @0x28246c ldr r6, [r1, r0, lsl #2] */
/* @0x282470 vmrs APSR_nzcv, fpscr */
/* @0x282474 blt 0x2824a4 <_spIkConstraintTimeline_apply+0x78> */
/* @0x282478 vldr s15, [r6, #20] */
/* @0x28247c vldr s14, [r3, #4] */
/* @0x282480 vsub.f32 s14, s14, s15 */
/* @0x282484 vldr s13, [sp, #40] */
/* @0x282488 vmla.f32 s15, s14, s13 */
/* @0x28248c vstr s15, [r6, #20] */
/* @0x282490 vldr s15, [r3, #8] */
/* @0x282494 vcvt.s32.f32 s15, s15 */
/* @0x282498 vstr s15, [r6, #16] */
/* @0x28249c vpop {d8} */
/* @0x2824a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2824a4 mov r1, r2 */
/* @0x2824a8 vmov.f32 s0, s16 */
/* @0x2824ac mov r0, r5 */
/* @0x2824b0 mov r2, #3 */
/* @0x2824b4 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x2824b8 movw r2, #0x5556 */
/* @0x2824bc movt r2, #0x5555 */
/* @0x2824c0 vmov.f32 s14, #1.000000e+00 */
/* @0x2824c4 sub r7, r0, #2 */
/* @0x2824c8 mov r3, r0 */
/* @0x2824cc smull r1, r2, r2, r3 */
/* @0x2824d0 lsl r7, r7, #2 */
/* @0x2824d4 add r5, r5, r7 */
/* @0x2824d8 vldr s15, [r5, #8] */
/* @0x2824dc vldr s13, [r5, #-4] */
/* @0x2824e0 vsub.f32 s16, s16, s15 */
/* @0x2824e4 mov r0, r4 */
/* @0x2824e8 vldr s17, [r5] */
/* @0x2824ec sub r1, r2, r3, asr #31 */
/* @0x2824f0 sub r1, r1, #1 */
/* @0x2824f4 vsub.f32 s15, s13, s15 */
/* @0x2824f8 vdiv.f32 s15, s16, s15 */
/* @0x2824fc vsub.f32 s14, s14, s15 */
/* @0x282500 vmov r2, s14 */
/* @0x282504 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x282508 ldr r3, [r4, #0x10] */
/* @0x28250c vldr s15, [r6, #20] */
/* @0x282510 add r7, r3, r7 */
/* @0x282514 vldr s14, [r7, #12] */
/* @0x282518 vsub.f32 s14, s14, s17 */
/* @0x28251c vmov s13, r0 */
/* @0x282520 vmla.f32 s17, s14, s13 */
/* @0x282524 vldr s14, [sp, #40] */
/* @0x282528 vsub.f32 s17, s17, s15 */
/* @0x28252c vmla.f32 s15, s17, s14 */
/* @0x282530 vpop {d8} */
/* @0x282534 vstr s15, [r6, #20] */
/* @0x282538 vldr s15, [r7, #4] */
/* @0x28253c vcvt.s32.f32 s15, s15 */
/* @0x282540 vstr s15, [r6, #16] */
/* @0x282544 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x282548 · _spTransformConstraintTimeline_apply · size=420 · insn=105 */
/* @0x282548 push {r3, r4, r5, r6, r7, lr} */
/* @0x28254c vpush {d8} */
/* @0x282550 vmov s17, r3 */
/* @0x282554 vldr s16, [sp, #40] */
/* @0x282558 ldr r6, [r0, #0x10] */
/* @0x28255c vldr s15, [r6] */
/* @0x282560 vcmpe.f32 s15, s17 */
/* @0x282564 mov r5, r0 */
/* @0x282568 vmrs APSR_nzcv, fpscr */
/* @0x28256c bgt 0x2825e8 <_spTransformConstraintTimeline_apply+0xa0> */
/* @0x282570 ldr r2, [r0, #0xc] */
/* @0x282574 ldr r1, [r1, #0x2c] */
/* @0x282578 sub r3, r2, #5 */
/* @0x28257c ldr r0, [r0, #0x14] */
/* @0x282580 add r3, r6, r3, lsl #2 */
/* @0x282584 vldr s15, [r3] */
/* @0x282588 vcmpe.f32 s17, s15 */
/* @0x28258c ldr r4, [r1, r0, lsl #2] */
/* @0x282590 vmrs APSR_nzcv, fpscr */
/* @0x282594 blt 0x2825f0 <_spTransformConstraintTimeline_apply+0xa8> */
/* @0x282598 vldr s11, [r3, #4] */
/* @0x28259c vldr s12, [r4, #16] */
/* @0x2825a0 vsub.f32 s11, s11, s12 */
/* @0x2825a4 vldr s13, [r4, #20] */
/* @0x2825a8 vldr s14, [r4, #24] */
/* @0x2825ac vldr s15, [r4, #28] */
/* @0x2825b0 vmla.f32 s12, s11, s16 */
/* @0x2825b4 vstr s12, [r4, #16] */
/* @0x2825b8 vldr s12, [r3, #8] */
/* @0x2825bc vsub.f32 s12, s12, s13 */
/* @0x2825c0 vmla.f32 s13, s12, s16 */
/* @0x2825c4 vstr s13, [r4, #20] */
/* @0x2825c8 vldr s13, [r3, #12] */
/* @0x2825cc vsub.f32 s13, s13, s14 */
/* @0x2825d0 vmla.f32 s14, s13, s16 */
/* @0x2825d4 vstr s14, [r4, #24] */
/* @0x2825d8 vldr s14, [r3, #16] */
/* @0x2825dc vsub.f32 s14, s14, s15 */
/* @0x2825e0 vmla.f32 s15, s14, s16 */
/* @0x2825e4 vstr s15, [r4, #28] */
/* @0x2825e8 vpop {d8} */
/* @0x2825ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x2825f0 mov r1, r2 */
/* @0x2825f4 vmov.f32 s0, s17 */
/* @0x2825f8 mov r0, r6 */
/* @0x2825fc mov r2, #5 */
/* @0x282600 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x282604 vmov.f32 s14, #1.000000e+00 */
/* @0x282608 lsl r3, r0, #2 */
/* @0x28260c mov r2, r0 */
/* @0x282610 sub r7, r3, #20 */
/* @0x282614 add r3, r6, r3 */
/* @0x282618 add r6, r6, r7 */
/* @0x28261c vldr s15, [r3] */
/* @0x282620 vldr s13, [r6] */
/* @0x282624 vsub.f32 s13, s13, s15 */
/* @0x282628 movw r3, #0x6667 */
/* @0x28262c movt r3, #0x6666 */
/* @0x282630 mvn r1, r0 */
/* @0x282634 mov r0, r5 */
/* @0x282638 smull r12, r2, r3, r2 */
/* @0x28263c lsr r1, r1, #31 */
/* @0x282640 vsub.f32 s15, s17, s15 */
/* @0x282644 rsb r1, r1, r2, asr #1 */
/* @0x282648 vdiv.f32 s15, s15, s13 */
/* @0x28264c vsub.f32 s14, s14, s15 */
/* @0x282650 vmov r2, s14 */
/* @0x282654 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x282658 ldr r3, [r5, #0x10] */
/* @0x28265c vldr s8, [r4, #16] */
/* @0x282660 vldr s10, [r4, #20] */
/* @0x282664 add r3, r3, r7 */
/* @0x282668 vldr s7, [r3, #4] */
/* @0x28266c vldr s6, [r3, #24] */
/* @0x282670 vsub.f32 s6, s6, s7 */
/* @0x282674 vldr s9, [r3, #8] */
/* @0x282678 vldr s11, [r3, #12] */
/* @0x28267c vldr s13, [r3, #16] */
/* @0x282680 vldr s12, [r4, #24] */
/* @0x282684 vldr s14, [r4, #28] */
/* @0x282688 vmov s15, r0 */
/* @0x28268c vmla.f32 s7, s6, s15 */
/* @0x282690 vsub.f32 s7, s7, s8 */
/* @0x282694 vmla.f32 s8, s7, s16 */
/* @0x282698 vstr s8, [r4, #16] */
/* @0x28269c vldr s8, [r3, #28] */
/* @0x2826a0 vsub.f32 s8, s8, s9 */
/* @0x2826a4 vmla.f32 s9, s8, s15 */
/* @0x2826a8 vsub.f32 s9, s9, s10 */
/* @0x2826ac vmla.f32 s10, s9, s16 */
/* @0x2826b0 vstr s10, [r4, #20] */
/* @0x2826b4 vldr s10, [r3, #32] */
/* @0x2826b8 vsub.f32 s10, s10, s11 */
/* @0x2826bc vmla.f32 s11, s10, s15 */
/* @0x2826c0 vsub.f32 s11, s11, s12 */
/* @0x2826c4 vmla.f32 s12, s11, s16 */
/* @0x2826c8 vstr s12, [r4, #24] */
/* @0x2826cc vldr s12, [r3, #36] */
/* @0x2826d0 vsub.f32 s12, s12, s13 */
/* @0x2826d4 vmla.f32 s13, s12, s15 */
/* @0x2826d8 vsub.f32 s13, s13, s14 */
/* @0x2826dc vmla.f32 s14, s13, s16 */
/* @0x2826e0 vpop {d8} */
/* @0x2826e4 vstr s14, [r4, #28] */
/* @0x2826e8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2826ec · _spPathConstraintPositionTimeline_apply · size=248 · insn=62 */
/* @0x2826ec push {r3, r4, r5, r6, r7, lr} */
/* @0x2826f0 vpush {d8} */
/* @0x2826f4 vmov s16, r3 */
/* @0x2826f8 ldr r5, [r0, #0x10] */
/* @0x2826fc vldr s15, [r5] */
/* @0x282700 vcmpe.f32 s15, s16 */
/* @0x282704 mov r4, r0 */
/* @0x282708 vmrs APSR_nzcv, fpscr */
/* @0x28270c bgt 0x282750 <_spPathConstraintPositionTimeline_apply+0x64> */
/* @0x282710 ldr r2, [r0, #0xc] */
/* @0x282714 ldr r1, [r1, #0x34] */
/* @0x282718 sub r3, r2, #2 */
/* @0x28271c ldr r0, [r0, #0x14] */
/* @0x282720 add r3, r5, r3, lsl #2 */
/* @0x282724 vldr s15, [r3] */
/* @0x282728 vcmpe.f32 s16, s15 */
/* @0x28272c ldr r6, [r1, r0, lsl #2] */
/* @0x282730 vmrs APSR_nzcv, fpscr */
/* @0x282734 blt 0x282758 <_spPathConstraintPositionTimeline_apply+0x6c> */
/* @0x282738 vldr s15, [r6, #16] */
/* @0x28273c vldr s14, [r3, #4] */
/* @0x282740 vsub.f32 s14, s14, s15 */
/* @0x282744 vldr s13, [sp, #40] */
/* @0x282748 vmla.f32 s15, s14, s13 */
/* @0x28274c vstr s15, [r6, #16] */
/* @0x282750 vpop {d8} */
/* @0x282754 pop {r3, r4, r5, r6, r7, pc} */
/* @0x282758 mov r1, r2 */
/* @0x28275c vmov.f32 s0, s16 */
/* @0x282760 mov r0, r5 */
/* @0x282764 mov r2, #2 */
/* @0x282768 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x28276c vmov.f32 s14, #1.000000e+00 */
/* @0x282770 sub r7, r0, #1 */
/* @0x282774 add r1, r0, r0, lsr #31 */
/* @0x282778 mov r0, r4 */
/* @0x28277c lsl r7, r7, #2 */
/* @0x282780 asr r1, r1, #1 */
/* @0x282784 add r5, r5, r7 */
/* @0x282788 vldr s15, [r5, #4] */
/* @0x28278c vldr s13, [r5, #-4] */
/* @0x282790 vsub.f32 s16, s16, s15 */
/* @0x282794 sub r1, r1, #1 */
/* @0x282798 vldr s17, [r5] */
/* @0x28279c vsub.f32 s15, s13, s15 */
/* @0x2827a0 vdiv.f32 s15, s16, s15 */
/* @0x2827a4 vsub.f32 s14, s14, s15 */
/* @0x2827a8 vmov r2, s14 */
/* @0x2827ac bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x2827b0 ldr r3, [r4, #0x10] */
/* @0x2827b4 vldr s15, [r6, #16] */
/* @0x2827b8 add r7, r3, r7 */
/* @0x2827bc vldr s14, [r7, #8] */
/* @0x2827c0 vsub.f32 s14, s14, s17 */
/* @0x2827c4 vmov s13, r0 */
/* @0x2827c8 vmla.f32 s17, s14, s13 */
/* @0x2827cc vldr s14, [sp, #40] */
/* @0x2827d0 vsub.f32 s17, s17, s15 */
/* @0x2827d4 vmla.f32 s15, s17, s14 */
/* @0x2827d8 vpop {d8} */
/* @0x2827dc vstr s15, [r6, #16] */
/* @0x2827e0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2827e4 · _spPathConstraintSpacingTimeline_apply · size=248 · insn=62 */
/* @0x2827e4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2827e8 vpush {d8} */
/* @0x2827ec vmov s16, r3 */
/* @0x2827f0 ldr r5, [r0, #0x10] */
/* @0x2827f4 vldr s15, [r5] */
/* @0x2827f8 vcmpe.f32 s15, s16 */
/* @0x2827fc mov r4, r0 */
/* @0x282800 vmrs APSR_nzcv, fpscr */
/* @0x282804 bgt 0x282848 <_spPathConstraintSpacingTimeline_apply+0x64> */
/* @0x282808 ldr r2, [r0, #0xc] */
/* @0x28280c ldr r1, [r1, #0x34] */
/* @0x282810 sub r3, r2, #2 */
/* @0x282814 ldr r0, [r0, #0x14] */
/* @0x282818 add r3, r5, r3, lsl #2 */
/* @0x28281c vldr s15, [r3] */
/* @0x282820 vcmpe.f32 s16, s15 */
/* @0x282824 ldr r6, [r1, r0, lsl #2] */
/* @0x282828 vmrs APSR_nzcv, fpscr */
/* @0x28282c blt 0x282850 <_spPathConstraintSpacingTimeline_apply+0x6c> */
/* @0x282830 vldr s15, [r6, #20] */
/* @0x282834 vldr s14, [r3, #4] */
/* @0x282838 vsub.f32 s14, s14, s15 */
/* @0x28283c vldr s13, [sp, #40] */
/* @0x282840 vmla.f32 s15, s14, s13 */
/* @0x282844 vstr s15, [r6, #20] */
/* @0x282848 vpop {d8} */
/* @0x28284c pop {r3, r4, r5, r6, r7, pc} */
/* @0x282850 mov r1, r2 */
/* @0x282854 vmov.f32 s0, s16 */
/* @0x282858 mov r0, r5 */
/* @0x28285c mov r2, #2 */
/* @0x282860 bl 0x280ed0 <printbuf_free+0x20> */
/* @0x282864 vmov.f32 s14, #1.000000e+00 */
/* @0x282868 sub r7, r0, #1 */
/* @0x28286c add r1, r0, r0, lsr #31 */
/* @0x282870 mov r0, r4 */
/* @0x282874 lsl r7, r7, #2 */
/* @0x282878 asr r1, r1, #1 */
/* @0x28287c add r5, r5, r7 */
/* @0x282880 vldr s15, [r5, #4] */
/* @0x282884 vldr s13, [r5, #-4] */
/* @0x282888 vsub.f32 s16, s16, s15 */
/* @0x28288c sub r1, r1, #1 */
/* @0x282890 vldr s17, [r5] */
/* @0x282894 vsub.f32 s15, s13, s15 */
/* @0x282898 vdiv.f32 s15, s16, s15 */
/* @0x28289c vsub.f32 s14, s14, s15 */
/* @0x2828a0 vmov r2, s14 */
/* @0x2828a4 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x2828a8 ldr r3, [r4, #0x10] */
/* @0x2828ac vldr s15, [r6, #20] */
/* @0x2828b0 add r7, r3, r7 */
/* @0x2828b4 vldr s14, [r7, #8] */
/* @0x2828b8 vsub.f32 s14, s14, s17 */
/* @0x2828bc vmov s13, r0 */
/* @0x2828c0 vmla.f32 s17, s14, s13 */
/* @0x2828c4 vldr s14, [sp, #40] */
/* @0x2828c8 vsub.f32 s17, s17, s15 */
/* @0x2828cc vmla.f32 s15, s17, s14 */
/* @0x2828d0 vpop {d8} */
/* @0x2828d4 vstr s15, [r6, #20] */
/* @0x2828d8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2828dc · _spPathConstraintMixTimeline_apply · size=308 · insn=77 */
/* @0x2828dc push {r3, r4, r5, r6, r7, lr} */
/* @0x2828e0 vpush {d8, d9} */
/* @0x2828e4 vmov s16, r3 */
/* @0x2828e8 vldr s17, [sp, #48] */
/* @0x2828ec ldr r5, [r0, #0x10] */
/* @0x2828f0 vldr s15, [r5] */
/* @0x2828f4 vcmpe.f32 s15, s16 */
/* @0x2828f8 mov r4, r0 */
/* @0x2828fc vmrs APSR_nzcv, fpscr */
/* @0x282900 bgt 0x282954 <_spPathConstraintMixTimeline_apply+0x78> */
/* @0x282904 ldr r2, [r0, #0xc] */
/* @0x282908 ldr r1, [r1, #0x34] */
/* @0x28290c sub r3, r2, #3 */
/* @0x282910 ldr r0, [r0, #0x14] */
/* @0x282914 add r3, r5, r3, lsl #2 */
/* @0x282918 vldr s15, [r3] */
/* @0x28291c vcmpe.f32 s16, s15 */
/* @0x282920 ldr r6, [r1, r0, lsl #2] */
/* @0x282924 vmrs APSR_nzcv, fpscr */
/* @0x282928 blt 0x28295c <_spPathConstraintMixTimeline_apply+0x80> */
/* @0x28292c vldr s14, [r6, #24] */
/* @0x282930 vldr s13, [r3, #4] */
/* @0x282934 vsub.f32 s13, s13, s14 */
/* @0x282938 vldr s15, [r6, #28] */
/* @0x28293c vmla.f32 s14, s13, s17 */
/* @0x282940 vstr s14, [r6, #24] */
/* @0x282944 vldr s14, [r3, #8] */
/* @0x282948 vsub.f32 s14, s14, s15 */
/* @0x28294c vmla.f32 s15, s14, s17 */
/* @0x282950 vstr s15, [r6, #28] */
/* @0x282954 vpop {d8, d9} */
/* @0x282958 pop {r3, r4, r5, r6, r7, pc} */
/* @0x28295c mov r1, r2 */
/* @0x282960 vmov.f32 s0, s16 */
/* @0x282964 mov r0, r5 */
/* @0x282968 mov r2, #3 */
/* @0x28296c bl 0x280ed0 <printbuf_free+0x20> */
/* @0x282970 movw r2, #0x5556 */
/* @0x282974 movt r2, #0x5555 */
/* @0x282978 vmov.f32 s14, #1.000000e+00 */
/* @0x28297c sub r7, r0, #2 */
/* @0x282980 mov r3, r0 */
/* @0x282984 smull r1, r2, r2, r3 */
/* @0x282988 lsl r7, r7, #2 */
/* @0x28298c add r5, r5, r7 */
/* @0x282990 vldr s15, [r5, #8] */
/* @0x282994 vldr s13, [r5, #-4] */
/* @0x282998 vsub.f32 s16, s16, s15 */
/* @0x28299c mov r0, r4 */
/* @0x2829a0 vldr s19, [r5] */
/* @0x2829a4 vldr s18, [r5, #4] */
/* @0x2829a8 sub r1, r2, r3, asr #31 */
/* @0x2829ac sub r1, r1, #1 */
/* @0x2829b0 vsub.f32 s15, s13, s15 */
/* @0x2829b4 vdiv.f32 s15, s16, s15 */
/* @0x2829b8 vsub.f32 s14, s14, s15 */
/* @0x2829bc vmov r2, s14 */
/* @0x2829c0 bl 0x2818e0 <spCurveTimeline_getCurvePercent> */
/* @0x2829c4 ldr r3, [r4, #0x10] */
/* @0x2829c8 vldr s13, [r6, #24] */
/* @0x2829cc vldr s15, [r6, #28] */
/* @0x2829d0 add r7, r3, r7 */
/* @0x2829d4 vldr s12, [r7, #12] */
/* @0x2829d8 vsub.f32 s12, s12, s19 */
/* @0x2829dc vmov s14, r0 */
/* @0x2829e0 vmla.f32 s19, s12, s14 */
/* @0x2829e4 vsub.f32 s19, s19, s13 */
/* @0x2829e8 vmla.f32 s13, s19, s17 */
/* @0x2829ec vstr s13, [r6, #24] */
/* @0x2829f0 vldr s13, [r7, #16] */
/* @0x2829f4 vsub.f32 s13, s13, s18 */
/* @0x2829f8 vmla.f32 s18, s13, s14 */
/* @0x2829fc vsub.f32 s18, s18, s15 */
/* @0x282a00 vmla.f32 s15, s18, s17 */
/* @0x282a04 vpop {d8, d9} */
/* @0x282a08 vstr s15, [r6, #28] */
/* @0x282a0c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x282a10 · _spBaseTimeline_create · size=128 · insn=32 */
/* @0x282a10 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x282a14 mov r5, r0 */
/* @0x282a18 ldr r6, [pc, #0x68] */
/* @0x282a1c sub sp, sp, #12 */
/* @0x282a20 mov r9, r1 */
/* @0x282a24 mov r7, r2 */
/* @0x282a28 add r6, pc, r6 */
/* @0x282a2c mov r8, r3 */
/* @0x282a30 mov r1, #24 */
/* @0x282a34 mov r3, #233 */
/* @0x282a38 mov r2, r6 */
/* @0x282a3c mov r0, #1 */
/* @0x282a40 bl 0x285c4c <_calloc> */
/* @0x282a44 ldr r3, [pc, #0x40] */
/* @0x282a48 mov r1, r9 */
/* @0x282a4c mov r2, r5 */
/* @0x282a50 str r8, [sp] */
/* @0x282a54 ldr r3, [pc, r3] */
/* @0x282a58 mov r4, r0 */
/* @0x282a5c bl 0x2816d8 <_spCurveTimeline_init> */
/* @0x282a60 mul r0, r7, r5 */
/* @0x282a64 mov r2, r6 */
/* @0x282a68 mov r1, #4 */
/* @0x282a6c mov r3, #237 */
/* @0x282a70 str r0, [r4, #0xc] */
/* @0x282a74 bl 0x285c4c <_calloc> */
/* @0x282a78 str r0, [r4, #0x10] */
/* @0x282a7c mov r0, r4 */
/* @0x282a80 add sp, sp, #12 */
/* @0x282a84 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x282a88 andeq r4, sp, r8, lsr #20 */
/* @0x282a8c andseq lr, r6, r12, asr #28 */

/* ── FUNC 0x282a90 · spRotateTimeline_create · size=24 · insn=6 */
/* @0x282a90 ldr r3, [pc, #0xc] */
/* @0x282a94 mov r1, #1 */
/* @0x282a98 mov r2, #2 */
/* @0x282a9c ldr r3, [pc, r3] */
/* @0x282aa0 b 0x282a10 <_spBaseTimeline_create> */
/* @0x282aa4 andseq lr, r6, r8, lsl #28 */

/* ── FUNC 0x282aa8 · spRotateTimeline_setFrame · size=20 · insn=5 */
/* @0x282aa8 ldr r0, [r0, #0x10] */
/* @0x282aac add r1, r0, r1, lsl #3 */
/* @0x282ab0 str r2, [r1] */
/* @0x282ab4 str r3, [r1, #0x4] */
/* @0x282ab8 bx lr */

/* ── FUNC 0x282abc · spTranslateTimeline_create · size=24 · insn=6 */
/* @0x282abc ldr r3, [pc, #0xc] */
/* @0x282ac0 mov r1, #2 */
/* @0x282ac4 mov r2, #3 */
/* @0x282ac8 ldr r3, [pc, r3] */
/* @0x282acc b 0x282a10 <_spBaseTimeline_create> */
/* @0x282ad0 andseq lr, r6, r0, ror #27 */

/* ── FUNC 0x282ad4 · spTranslateTimeline_setFrame · size=48 · insn=12 */
/* @0x282ad4 add r1, r1, r1, lsl #1 */
/* @0x282ad8 ldr r0, [r0, #0x10] */
/* @0x282adc str r4, [sp, #-0x4]! */
/* @0x282ae0 add r12, r1, #1 */
/* @0x282ae4 ldr r4, [sp, #0x4] */
/* @0x282ae8 add r1, r0, r1, lsl #2 */
/* @0x282aec add r0, r0, r12, lsl #2 */
/* @0x282af0 str r2, [r1] */
/* @0x282af4 str r4, [r0, #0x4] */
/* @0x282af8 str r3, [r0] */
/* @0x282afc ldr r4, [sp], #4 */
/* @0x282b00 bx lr */

/* ── FUNC 0x282b04 · spScaleTimeline_create · size=24 · insn=6 */
/* @0x282b04 ldr r3, [pc, #0xc] */
/* @0x282b08 mov r1, #0 */
/* @0x282b0c mov r2, #3 */
/* @0x282b10 ldr r3, [pc, r3] */
/* @0x282b14 b 0x282a10 <_spBaseTimeline_create> */
/* @0x282b18 mulseq r6, r12, sp */

/* ── FUNC 0x282b1c · spScaleTimeline_setFrame · size=4 · insn=1 */
/* @0x282b1c b 0x282ad4 <spTranslateTimeline_setFrame> */

/* ── FUNC 0x282b20 · spShearTimeline_create · size=24 · insn=6 */
/* @0x282b20 ldr r3, [pc, #0xc] */
/* @0x282b24 mov r1, #3 */
/* @0x282b28 mov r2, r1 */
/* @0x282b2c ldr r3, [pc, r3] */
/* @0x282b30 b 0x282a10 <_spBaseTimeline_create> */
/* @0x282b34 andseq lr, r6, r4, lsl #27 */

/* ── FUNC 0x282b38 · spShearTimeline_setFrame · size=4 · insn=1 */
/* @0x282b38 b 0x282ad4 <spTranslateTimeline_setFrame> */

/* ── FUNC 0x282b3c · spColorTimeline_create · size=24 · insn=6 */
/* @0x282b3c ldr r3, [pc, #0xc] */
/* @0x282b40 mov r1, #4 */
/* @0x282b44 mov r2, #5 */
/* @0x282b48 ldr r3, [pc, r3] */
/* @0x282b4c b 0x282a10 <_spBaseTimeline_create> */
/* @0x282b50 andseq lr, r6, r12, ror #26 */

/* ── FUNC 0x282b54 · spColorTimeline_setFrame · size=64 · insn=16 */
/* @0x282b54 add r1, r1, r1, lsl #2 */
/* @0x282b58 ldr r0, [r0, #0x10] */
/* @0x282b5c add r12, r1, #1 */
/* @0x282b60 push {r4, r5} */
/* @0x282b64 add r1, r0, r1, lsl #2 */
/* @0x282b68 ldr r5, [sp, #0x8] */
/* @0x282b6c add r0, r0, r12, lsl #2 */
/* @0x282b70 ldr r4, [sp, #0xc] */
/* @0x282b74 ldr r12, [sp, #0x10] */
/* @0x282b78 str r2, [r1] */
/* @0x282b7c str r5, [r0, #0x4] */
/* @0x282b80 str r4, [r0, #0x8] */
/* @0x282b84 str r3, [r0] */
/* @0x282b88 str r12, [r0, #0xc] */
/* @0x282b8c pop {r4, r5} */
/* @0x282b90 bx lr */

/* ── FUNC 0x282b94 · spAttachmentTimeline_create · size=136 · insn=34 */
/* @0x282b94 push {r4, r5, r6, lr} */
/* @0x282b98 mov r1, #24 */
/* @0x282b9c ldr r6, [pc, #0x6c] */
/* @0x282ba0 mov r5, r0 */
/* @0x282ba4 mov r3, #544 */
/* @0x282ba8 mov r0, #1 */
/* @0x282bac add r6, pc, r6 */
/* @0x282bb0 mov r2, r6 */
/* @0x282bb4 bl 0x285c4c <_calloc> */
/* @0x282bb8 ldr r2, [pc, #0x54] */
/* @0x282bbc ldr r3, [pc, #0x54] */
/* @0x282bc0 mov r1, #5 */
/* @0x282bc4 ldr r2, [pc, r2] */
/* @0x282bc8 ldr r3, [pc, r3] */
/* @0x282bcc mov r4, r0 */
/* @0x282bd0 bl 0x281328 <_spTimeline_init> */
/* @0x282bd4 mov r2, r6 */
/* @0x282bd8 str r5, [r4, #0x8] */
/* @0x282bdc mov r0, r5 */
/* @0x282be0 mov r1, #4 */
/* @0x282be4 mov r3, #548 */
/* @0x282be8 bl 0x285c4c <_calloc> */
/* @0x282bec mov r2, r6 */
/* @0x282bf0 mov r1, #4 */
/* @0x282bf4 movw r3, #0x225 */
/* @0x282bf8 str r0, [r4, #0xc] */
/* @0x282bfc mov r0, r5 */
/* @0x282c00 bl 0x285c4c <_calloc> */
/* @0x282c04 str r0, [r4, #0x14] */
/* @0x282c08 mov r0, r4 */
/* @0x282c0c pop {r4, r5, r6, pc} */
/* @0x282c10 andeq r4, sp, r4, lsr #17 */
/* @0x282c14 ldrsheq lr, [r6], -r4 */
/* @0x282c18 ldrsheq lr, [r6], -r4 */

/* ── FUNC 0x282c1c · spAttachmentTimeline_setFrame · size=112 · insn=28 */
/* @0x282c1c push {r4, r5, r6, lr} */
/* @0x282c20 mov r4, r1 */
/* @0x282c24 ldr r1, [r0, #0xc] */
/* @0x282c28 mov r5, r0 */
/* @0x282c2c ldr r0, [r0, #0x14] */
/* @0x282c30 mov r6, r3 */
/* @0x282c34 add r3, r1, r4, lsl #2 */
/* @0x282c38 ldr r0, [r0, r4, lsl #2] */
/* @0x282c3c str r2, [r3] */
/* @0x282c40 bl 0x285c80 <_free> */
/* @0x282c44 cmp r6, #0 */
/* @0x282c48 beq 0x282c7c <spAttachmentTimeline_setFrame+0x60> */
/* @0x282c4c mov r0, r6 */
/* @0x282c50 ldr r5, [r5, #0x14] */
/* @0x282c54 bl 0xb6538 <strlen@plt> */
/* @0x282c58 ldr r1, [pc, #0x28] */
/* @0x282c5c movw r2, #0x22f */
/* @0x282c60 add r1, pc, r1 */
/* @0x282c64 add r0, r0, #1 */
/* @0x282c68 bl 0x285c10 <_malloc> */
/* @0x282c6c mov r1, r6 */
/* @0x282c70 str r0, [r5, r4, lsl #2] */
/* @0x282c74 pop {r4, r5, r6, lr} */
/* @0x282c78 b 0xb65a4 <strcpy@plt> */
/* @0x282c7c ldr r3, [r5, #0x14] */
/* @0x282c80 str r6, [r3, r4, lsl #2] */
/* @0x282c84 pop {r4, r5, r6, pc} */
/* @0x282c88 strdeq r4, r5, [sp], -r0 */

/* ── FUNC 0x282c8c · spEventTimeline_create · size=136 · insn=34 */
/* @0x282c8c push {r4, r5, r6, lr} */
/* @0x282c90 mov r1, #20 */
/* @0x282c94 ldr r6, [pc, #0x6c] */
/* @0x282c98 mov r5, r0 */
/* @0x282c9c movw r3, #0x263 */
/* @0x282ca0 mov r0, #1 */
/* @0x282ca4 add r6, pc, r6 */
/* @0x282ca8 mov r2, r6 */
/* @0x282cac bl 0x285c4c <_calloc> */
/* @0x282cb0 ldr r2, [pc, #0x54] */
/* @0x282cb4 ldr r3, [pc, #0x54] */
/* @0x282cb8 mov r1, #6 */
/* @0x282cbc ldr r2, [pc, r2] */
/* @0x282cc0 ldr r3, [pc, r3] */
/* @0x282cc4 mov r4, r0 */
/* @0x282cc8 bl 0x281328 <_spTimeline_init> */
/* @0x282ccc mov r2, r6 */
/* @0x282cd0 str r5, [r4, #0x8] */
/* @0x282cd4 mov r0, r5 */
/* @0x282cd8 mov r1, #4 */
/* @0x282cdc movw r3, #0x267 */
/* @0x282ce0 bl 0x285c4c <_calloc> */
/* @0x282ce4 mov r2, r6 */
/* @0x282ce8 mov r1, #4 */
/* @0x282cec mov r3, #616 */
/* @0x282cf0 str r0, [r4, #0xc] */
/* @0x282cf4 mov r0, r5 */
/* @0x282cf8 bl 0x285c4c <_calloc> */
/* @0x282cfc str r0, [r4, #0x10] */
/* @0x282d00 mov r0, r4 */
/* @0x282d04 pop {r4, r5, r6, pc} */
/* @0x282d08 andeq r4, sp, r12, lsr #15 */
/* @0x282d0c andseq lr, r6, r4, lsl #24 */
/* @0x282d10 andseq lr, r6, r4, lsl #24 */

/* ── FUNC 0x282d14 · spEventTimeline_setFrame · size=56 · insn=14 */
/* @0x282d14 ldr r3, [r0, #0xc] */
/* @0x282d18 push {r4, r5, r6, lr} */
/* @0x282d1c mov r5, r1 */
/* @0x282d20 mov r6, r2 */
/* @0x282d24 ldr r1, [r0, #0x10] */
/* @0x282d28 ldr r2, [r2, #0x4] */
/* @0x282d2c add r3, r3, r5, lsl #2 */
/* @0x282d30 mov r4, r0 */
/* @0x282d34 ldr r0, [r1, r5, lsl #2] */
/* @0x282d38 str r2, [r3] */
/* @0x282d3c bl 0x285c80 <_free> */
/* @0x282d40 ldr r3, [r4, #0x10] */
/* @0x282d44 str r6, [r3, r5, lsl #2] */
/* @0x282d48 pop {r4, r5, r6, pc} */

/* ── FUNC 0x282d4c · spDrawOrderTimeline_create · size=144 · insn=36 */
/* @0x282d4c push {r3, r4, r5, r6, r7, lr} */
/* @0x282d50 mov r5, r0 */
/* @0x282d54 ldr r6, [pc, #0x74] */
/* @0x282d58 mov r7, r1 */
/* @0x282d5c mov r3, #672 */
/* @0x282d60 mov r1, #24 */
/* @0x282d64 add r6, pc, r6 */
/* @0x282d68 mov r0, #1 */
/* @0x282d6c mov r2, r6 */
/* @0x282d70 bl 0x285c4c <_calloc> */
/* @0x282d74 ldr r2, [pc, #0x58] */
/* @0x282d78 ldr r3, [pc, #0x58] */
/* @0x282d7c mov r1, #7 */
/* @0x282d80 ldr r2, [pc, r2] */
/* @0x282d84 ldr r3, [pc, r3] */
/* @0x282d88 mov r4, r0 */
/* @0x282d8c bl 0x281328 <_spTimeline_init> */
/* @0x282d90 mov r2, r6 */
/* @0x282d94 str r5, [r4, #0x8] */
/* @0x282d98 mov r0, r5 */
/* @0x282d9c mov r1, #4 */
/* @0x282da0 mov r3, #676 */
/* @0x282da4 bl 0x285c4c <_calloc> */
/* @0x282da8 mov r2, r6 */
/* @0x282dac mov r1, #4 */
/* @0x282db0 movw r3, #0x2a5 */
/* @0x282db4 str r0, [r4, #0xc] */
/* @0x282db8 mov r0, r5 */
/* @0x282dbc bl 0x285c4c <_calloc> */
/* @0x282dc0 str r7, [r4, #0x14] */
/* @0x282dc4 str r0, [r4, #0x10] */
/* @0x282dc8 mov r0, r4 */
/* @0x282dcc pop {r3, r4, r5, r6, r7, pc} */
/* @0x282dd0 andeq r4, sp, r12, ror #13 */
/* @0x282dd4 andseq lr, r6, r8, asr #22 */
/* @0x282dd8 andseq lr, r6, r8, asr #22 */

/* ── FUNC 0x282ddc · spDrawOrderTimeline_setFrame · size=124 · insn=31 */
/* @0x282ddc push {r3, r4, r5, r6, r7, lr} */
/* @0x282de0 mov r5, r1 */
/* @0x282de4 ldr r1, [r0, #0xc] */
/* @0x282de8 mov r4, r0 */
/* @0x282dec ldr r0, [r0, #0x10] */
/* @0x282df0 mov r6, r3 */
/* @0x282df4 add r3, r1, r5, lsl #2 */
/* @0x282df8 ldr r0, [r0, r5, lsl #2] */
/* @0x282dfc str r2, [r3] */
/* @0x282e00 bl 0x285c80 <_free> */
/* @0x282e04 cmp r6, #0 */
/* @0x282e08 beq 0x282e48 <spDrawOrderTimeline_setFrame+0x6c> */
/* @0x282e0c ldr r0, [r4, #0x14] */
/* @0x282e10 movw r2, #0x2b2 */
/* @0x282e14 ldr r1, [pc, #0x38] */
/* @0x282e18 ldr r7, [r4, #0x10] */
/* @0x282e1c add r1, pc, r1 */
/* @0x282e20 lsl r0, r0, #2 */
/* @0x282e24 bl 0x285c10 <_malloc> */
/* @0x282e28 ldr r2, [r4, #0x14] */
/* @0x282e2c mov r1, r6 */
/* @0x282e30 lsl r2, r2, #2 */
/* @0x282e34 str r0, [r7, r5, lsl #2] */
/* @0x282e38 ldr r3, [r4, #0x10] */
/* @0x282e3c ldr r0, [r3, r5, lsl #2] */
/* @0x282e40 pop {r3, r4, r5, r6, r7, lr} */
/* @0x282e44 b 0xb65bc <memcpy@plt> */
/* @0x282e48 ldr r3, [r4, #0x10] */
/* @0x282e4c str r6, [r3, r5, lsl #2] */
/* @0x282e50 pop {r3, r4, r5, r6, r7, pc} */
/* @0x282e54 andeq r4, sp, r4, lsr r6 */

/* ── FUNC 0x282e58 · spDeformTimeline_create · size=160 · insn=40 */
/* @0x282e58 push {r4, r5, r6, r7, lr} */
/* @0x282e5c movw r3, #0x30f */
/* @0x282e60 ldr r6, [pc, #0x84] */
/* @0x282e64 sub sp, sp, #12 */
/* @0x282e68 mov r5, r0 */
/* @0x282e6c mov r7, r1 */
/* @0x282e70 add r6, pc, r6 */
/* @0x282e74 mov r1, #36 */
/* @0x282e78 mov r0, #1 */
/* @0x282e7c mov r2, r6 */
/* @0x282e80 bl 0x285c4c <_calloc> */
/* @0x282e84 ldr r3, [pc, #0x64] */
/* @0x282e88 ldr r12, [pc, #0x64] */
/* @0x282e8c mov r2, r5 */
/* @0x282e90 mov r1, #8 */
/* @0x282e94 ldr r3, [pc, r3] */
/* @0x282e98 ldr r12, [pc, r12] */
/* @0x282e9c str r12, [sp] */
/* @0x282ea0 mov r4, r0 */
/* @0x282ea4 bl 0x2816d8 <_spCurveTimeline_init> */
/* @0x282ea8 mov r2, r6 */
/* @0x282eac str r5, [r4, #0xc] */
/* @0x282eb0 mov r0, r5 */
/* @0x282eb4 mov r1, #4 */
/* @0x282eb8 movw r3, #0x312 */
/* @0x282ebc bl 0x285c4c <_calloc> */
/* @0x282ec0 mov r2, r6 */
/* @0x282ec4 mov r1, #4 */
/* @0x282ec8 movw r3, #0x313 */
/* @0x282ecc str r0, [r4, #0x10] */
/* @0x282ed0 mov r0, r5 */
/* @0x282ed4 bl 0x285c4c <_calloc> */
/* @0x282ed8 str r7, [r4, #0x14] */
/* @0x282edc str r0, [r4, #0x18] */
/* @0x282ee0 mov r0, r4 */
/* @0x282ee4 add sp, sp, #12 */
/* @0x282ee8 pop {r4, r5, r6, r7, pc} */
/* @0x282eec andeq r4, sp, r0, ror #11 */
/* @0x282ef0 andseq lr, r6, r12, lsr r10 */
/* @0x282ef4 andseq lr, r6, r12, lsr r10 */

/* ── FUNC 0x282ef8 · spDeformTimeline_setFrame · size=124 · insn=31 */
/* @0x282ef8 push {r3, r4, r5, r6, r7, lr} */
/* @0x282efc mov r5, r1 */
/* @0x282f00 ldr r1, [r0, #0x10] */
/* @0x282f04 mov r4, r0 */
/* @0x282f08 ldr r0, [r0, #0x18] */
/* @0x282f0c mov r6, r3 */
/* @0x282f10 add r3, r1, r5, lsl #2 */
/* @0x282f14 ldr r0, [r0, r5, lsl #2] */
/* @0x282f18 str r2, [r3] */
/* @0x282f1c bl 0x285c80 <_free> */
/* @0x282f20 cmp r6, #0 */
/* @0x282f24 beq 0x282f64 <spDeformTimeline_setFrame+0x6c> */
/* @0x282f28 ldr r0, [r4, #0x14] */
/* @0x282f2c movw r2, #0x31f */
/* @0x282f30 ldr r1, [pc, #0x38] */
/* @0x282f34 ldr r7, [r4, #0x18] */
/* @0x282f38 add r1, pc, r1 */
/* @0x282f3c lsl r0, r0, #2 */
/* @0x282f40 bl 0x285c10 <_malloc> */
/* @0x282f44 ldr r2, [r4, #0x14] */
/* @0x282f48 mov r1, r6 */
/* @0x282f4c lsl r2, r2, #2 */
/* @0x282f50 str r0, [r7, r5, lsl #2] */
/* @0x282f54 ldr r3, [r4, #0x18] */
/* @0x282f58 ldr r0, [r3, r5, lsl #2] */
/* @0x282f5c pop {r3, r4, r5, r6, r7, lr} */
/* @0x282f60 b 0xb65bc <memcpy@plt> */
/* @0x282f64 ldr r3, [r4, #0x18] */
/* @0x282f68 str r6, [r3, r5, lsl #2] */
/* @0x282f6c pop {r3, r4, r5, r6, r7, pc} */
/* @0x282f70 andeq r4, sp, r8, lsl r5 */

/* ── FUNC 0x282f74 · spIkConstraintTimeline_create · size=24 · insn=6 */
/* @0x282f74 ldr r3, [pc, #0xc] */
/* @0x282f78 mov r1, #9 */
/* @0x282f7c mov r2, #3 */
/* @0x282f80 ldr r3, [pc, r3] */
/* @0x282f84 b 0x282a10 <_spBaseTimeline_create> */
/* @0x282f88 andseq lr, r6, r8, asr r9 */

/* ── FUNC 0x282f8c · spIkConstraintTimeline_setFrame · size=44 · insn=11 */
/* @0x282f8c vldr s14, [sp] */
/* @0x282f90 vcvt.f32.s32 s15, s14 */
/* @0x282f94 add r1, r1, r1, lsl #1 */
/* @0x282f98 ldr r12, [r0, #0x10] */
/* @0x282f9c add r0, r1, #1 */
/* @0x282fa0 add r1, r12, r1, lsl #2 */
/* @0x282fa4 add r0, r12, r0, lsl #2 */
/* @0x282fa8 str r2, [r1] */
/* @0x282fac str r3, [r0] */
/* @0x282fb0 vstr s15, [r0, #4] */
/* @0x282fb4 bx lr */
