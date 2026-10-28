/* libyoyo.so 覆盖卡组 0280
 * 函数 0x2d2fd4..0x2d4560，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2d2fd4 · b2WeldJoint::~b2WeldJoint() · size=40 · insn=10 */
/* @0x2d2fd4 ldr r3, [pc, #0x1c] */
/* @0x2d2fd8 push {r4, lr} */
/* @0x2d2fdc ldr r3, [pc, r3] */
/* @0x2d2fe0 mov r4, r0 */
/* @0x2d2fe4 add r3, r3, #8 */
/* @0x2d2fe8 str r3, [r0] */
/* @0x2d2fec bl 0x27d1d0 <_ZdlPv> */
/* @0x2d2ff0 mov r0, r4 */
/* @0x2d2ff4 pop {r4, pc} */
/* @0x2d2ff8 andseq lr, r1, r8, ror r11 */

/* ── FUNC 0x2d2ffc · b2WeldJoint::SolvePositionConstraints(b2SolverData const&) · size=844 · insn=211 */
/* @0x2d2ffc ldr r2, [r0, #0x74] */
/* @0x2d3000 ldr r3, [r0, #0x78] */
/* @0x2d3004 push {r4, r5, lr} */
/* @0x2d3008 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d300c mov r5, r1 */
/* @0x2d3010 add r2, r2, r2, lsl #1 */
/* @0x2d3014 ldr r1, [r1, #0x18] */
/* @0x2d3018 add r3, r3, r3, lsl #1 */
/* @0x2d301c sub sp, sp, #84 */
/* @0x2d3020 mov r4, r0 */
/* @0x2d3024 add r2, r1, r2, lsl #2 */
/* @0x2d3028 vldr s23, [r2, #8] */
/* @0x2d302c vmov r0, s23 */
/* @0x2d3030 vldr s31, [r2] */
/* @0x2d3034 vldr s29, [r2, #4] */
/* @0x2d3038 add r3, r1, r3, lsl #2 */
/* @0x2d303c vldr s12, [r3, #4] */
/* @0x2d3040 vldr s30, [r3] */
/* @0x2d3044 vldr s22, [r3, #8] */
/* @0x2d3048 vstr s12, [sp, #4] */
/* @0x2d304c bl 0xb6580 <sinf@plt> */
/* @0x2d3050 vmov s27, r0 */
/* @0x2d3054 vmov r0, s23 */
/* @0x2d3058 bl 0xb658c <cosf@plt> */
/* @0x2d305c vmov s28, r0 */
/* @0x2d3060 vmov r0, s22 */
/* @0x2d3064 bl 0xb6580 <sinf@plt> */
/* @0x2d3068 vmov s26, r0 */
/* @0x2d306c vmov r0, s22 */
/* @0x2d3070 bl 0xb658c <cosf@plt> */
/* @0x2d3074 vldr s14, [r4, #144] */
/* @0x2d3078 vldr s21, [r4, #84] */
/* @0x2d307c vsub.f32 s21, s21, s14 */
/* @0x2d3080 vldr s10, [r4, #152] */
/* @0x2d3084 vldr s16, [r4, #92] */
/* @0x2d3088 vldr s11, [r4, #80] */
/* @0x2d308c vldr s13, [r4, #140] */
/* @0x2d3090 vldr s12, [r4, #88] */
/* @0x2d3094 vldr s14, [r4, #148] */
/* @0x2d3098 vldr s25, [r4, #156] */
/* @0x2d309c vldr s24, [r4, #160] */
/* @0x2d30a0 vldr s20, [r4, #164] */
/* @0x2d30a4 vldr s19, [r4, #168] */
/* @0x2d30a8 vsub.f32 s16, s16, s10 */
/* @0x2d30ac vmul.f32 s17, s21, s27 */
/* @0x2d30b0 vmov s15, r0 */
/* @0x2d30b4 vmul.f32 s21, s21, s28 */
/* @0x2d30b8 vsub.f32 s13, s11, s13 */
/* @0x2d30bc vmul.f32 s18, s16, s15 */
/* @0x2d30c0 vmul.f32 s16, s16, s26 */
/* @0x2d30c4 vsub.f32 s14, s12, s14 */
/* @0x2d30c8 vmla.f32 s21, s13, s27 */
/* @0x2d30cc vnmls.f32 s17, s13, s28 */
/* @0x2d30d0 vnmls.f32 s16, s14, s15 */
/* @0x2d30d4 vmla.f32 s18, s14, s26 */
/* @0x2d30d8 vadd.f32 s12, s25, s24 */
/* @0x2d30dc vmul.f32 s14, s21, s21 */
/* @0x2d30e0 vmul.f32 s15, s17, s17 */
/* @0x2d30e4 vmov.f32 s11, s12 */
/* @0x2d30e8 vmul.f32 s13, s16, s18 */
/* @0x2d30ec vmla.f32 s11, s14, s20 */
/* @0x2d30f0 vmul.f32 s14, s19, s18 */
/* @0x2d30f4 vmla.f32 s12, s15, s20 */
/* @0x2d30f8 vneg.f32 s10, s21 */
/* @0x2d30fc vmul.f32 s7, s18, s18 */
/* @0x2d3100 vmul.f32 s8, s16, s16 */
/* @0x2d3104 vmul.f32 s9, s10, s17 */
/* @0x2d3108 vmul.f32 s13, s13, s19 */
/* @0x2d310c vmul.f32 s15, s19, s16 */
/* @0x2d3110 vnmls.f32 s14, s20, s10 */
/* @0x2d3114 vmla.f32 s15, s20, s17 */
/* @0x2d3118 vstr s14, [sp, #68] */
/* @0x2d311c vstr s14, [sp, #52] */
/* @0x2d3120 vnmls.f32 s13, s9, s20 */
/* @0x2d3124 vstr s15, [sp, #72] */
/* @0x2d3128 vstr s15, [sp, #64] */
/* @0x2d312c vmla.f32 s11, s7, s19 */
/* @0x2d3130 vstr s13, [sp, #56] */
/* @0x2d3134 vstr s13, [sp, #48] */
/* @0x2d3138 vmla.f32 s12, s8, s19 */
/* @0x2d313c vstr s11, [sp, #44] */
/* @0x2d3140 vadd.f32 s14, s20, s19 */
/* @0x2d3144 vstr s12, [sp, #60] */
/* @0x2d3148 vstr s14, [sp, #76] */
/* @0x2d314c vldr s15, [r4, #68] */
/* @0x2d3150 vcmpe.f32 s15, #0 */
/* @0x2d3154 vmrs APSR_nzcv, fpscr */
/* @0x2d3158 ble 0x2d3250 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x254> */
/* @0x2d315c vldr s13, [sp, #4] */
/* @0x2d3160 vadd.f32 s15, s18, s13 */
/* @0x2d3164 vsub.f32 s15, s15, s29 */
/* @0x2d3168 vadd.f32 s14, s16, s30 */
/* @0x2d316c vsub.f32 s15, s15, s21 */
/* @0x2d3170 vsub.f32 s14, s14, s31 */
/* @0x2d3174 vstr s15, [sp, #24] */
/* @0x2d3178 vmul.f32 s15, s15, s15 */
/* @0x2d317c vsub.f32 s14, s14, s17 */
/* @0x2d3180 vmla.f32 s15, s14, s14 */
/* @0x2d3184 vstr s14, [sp, #20] */
/* @0x2d3188 vsqrt.f32 s26, s15 */
/* @0x2d318c vcmp.f32 s26, s26 */
/* @0x2d3190 vmrs APSR_nzcv, fpscr */
/* @0x2d3194 bne 0x2d331c <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x320> */
/* @0x2d3198 add r0, sp, #32 */
/* @0x2d319c add r1, sp, #44 */
/* @0x2d31a0 add r2, sp, #20 */
/* @0x2d31a4 vldr s27, [pc, #400] */
/* @0x2d31a8 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2> */
/* @0x2d31ac vldr s14, [sp, #32] */
/* @0x2d31b0 vneg.f32 s14, s14 */
/* @0x2d31b4 vldr s15, [sp, #36] */
/* @0x2d31b8 vmul.f32 s21, s21, s14 */
/* @0x2d31bc vmul.f32 s18, s18, s14 */
/* @0x2d31c0 vneg.f32 s15, s15 */
/* @0x2d31c4 vnmls.f32 s21, s17, s15 */
/* @0x2d31c8 vnmls.f32 s18, s16, s15 */
/* @0x2d31cc vmls.f32 s31, s25, s14 */
/* @0x2d31d0 vmla.f32 s30, s24, s14 */
/* @0x2d31d4 vldr s14, [sp, #4] */
/* @0x2d31d8 vmls.f32 s23, s20, s21 */
/* @0x2d31dc vmla.f32 s22, s19, s18 */
/* @0x2d31e0 vmls.f32 s29, s25, s15 */
/* @0x2d31e4 vmla.f32 s14, s24, s15 */
/* @0x2d31e8 ldr r2, [r4, #0x74] */
/* @0x2d31ec vldr s15, [pc, #332] */
/* @0x2d31f0 ldr r3, [r4, #0x78] */
/* @0x2d31f4 ldr r1, [r5, #0x18] */
/* @0x2d31f8 add r2, r2, r2, lsl #1 */
/* @0x2d31fc add r3, r3, r3, lsl #1 */
/* @0x2d3200 add r2, r1, r2, lsl #2 */
/* @0x2d3204 vstr s31, [r2] */
/* @0x2d3208 vstr s29, [r2, #4] */
/* @0x2d320c vstr s23, [r2, #8] */
/* @0x2d3210 add r3, r1, r3, lsl #2 */
/* @0x2d3214 vstr s30, [r3] */
/* @0x2d3218 vstr s14, [r3, #4] */
/* @0x2d321c vstr s22, [r3, #8] */
/* @0x2d3220 vcmpe.f32 s26, s15 */
/* @0x2d3224 vmrs APSR_nzcv, fpscr */
/* @0x2d3228 movhi r0, #0 */
/* @0x2d322c bhi 0x2d3244 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x248> */
/* @0x2d3230 vldr s15, [pc, #268] */
/* @0x2d3234 vcmpe.f32 s27, s15 */
/* @0x2d3238 vmrs APSR_nzcv, fpscr */
/* @0x2d323c movhi r0, #0 */
/* @0x2d3240 movls r0, #1 */
/* @0x2d3244 add sp, sp, #84 */
/* @0x2d3248 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d324c pop {r4, r5, pc} */
/* @0x2d3250 vldr s14, [sp, #4] */
/* @0x2d3254 vadd.f32 s15, s18, s14 */
/* @0x2d3258 vldr s14, [r4, #96] */
/* @0x2d325c vsub.f32 s15, s15, s29 */
/* @0x2d3260 vadd.f32 s28, s16, s30 */
/* @0x2d3264 vsub.f32 s15, s15, s21 */
/* @0x2d3268 vsub.f32 s28, s28, s31 */
/* @0x2d326c vstr s15, [sp, #12] */
/* @0x2d3270 vmul.f32 s15, s15, s15 */
/* @0x2d3274 vsub.f32 s28, s28, s17 */
/* @0x2d3278 vmla.f32 s15, s28, s28 */
/* @0x2d327c vsqrt.f32 s26, s15 */
/* @0x2d3280 vsub.f32 s13, s22, s23 */
/* @0x2d3284 vsub.f32 s14, s13, s14 */
/* @0x2d3288 vcmp.f32 s26, s26 */
/* @0x2d328c vstr s14, [sp, #8] */
/* @0x2d3290 vmrs APSR_nzcv, fpscr */
/* @0x2d3294 bne 0x2d332c <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x330> */
/* @0x2d3298 vldr s13, [sp, #8] */
/* @0x2d329c vcmpe.f32 s13, #0 */
/* @0x2d32a0 add r0, sp, #32 */
/* @0x2d32a4 add r1, sp, #44 */
/* @0x2d32a8 add r2, sp, #20 */
/* @0x2d32ac vldr s14, [sp, #12] */
/* @0x2d32b0 vldr s15, [sp, #8] */
/* @0x2d32b4 vstr s14, [sp, #24] */
/* @0x2d32b8 vmrs APSR_nzcv, fpscr */
/* @0x2d32bc vstr s15, [sp, #28] */
/* @0x2d32c0 vnegle.f32 s27, s13 */
/* @0x2d32c4 vldrgt s27, [sp, #8] */
/* @0x2d32c8 vstr s28, [sp, #20] */
/* @0x2d32cc bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3> */
/* @0x2d32d0 vldr s14, [sp, #32] */
/* @0x2d32d4 vldr s15, [sp, #36] */
/* @0x2d32d8 vldr s13, [sp, #40] */
/* @0x2d32dc vneg.f32 s14, s14 */
/* @0x2d32e0 vmul.f32 s21, s21, s14 */
/* @0x2d32e4 vmul.f32 s18, s18, s14 */
/* @0x2d32e8 vneg.f32 s15, s15 */
/* @0x2d32ec vnmls.f32 s21, s17, s15 */
/* @0x2d32f0 vnmls.f32 s18, s16, s15 */
/* @0x2d32f4 vsub.f32 s21, s21, s13 */
/* @0x2d32f8 vsub.f32 s18, s18, s13 */
/* @0x2d32fc vmls.f32 s31, s25, s14 */
/* @0x2d3300 vmla.f32 s30, s24, s14 */
/* @0x2d3304 vldr s14, [sp, #4] */
/* @0x2d3308 vmls.f32 s29, s25, s15 */
/* @0x2d330c vmla.f32 s14, s24, s15 */
/* @0x2d3310 vmls.f32 s23, s21, s20 */
/* @0x2d3314 vmla.f32 s22, s18, s19 */
/* @0x2d3318 b 0x2d31e8 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x1ec> */
/* @0x2d331c vmov r0, s15 */
/* @0x2d3320 bl 0xb6700 <sqrtf@plt> */
/* @0x2d3324 vmov s26, r0 */
/* @0x2d3328 b 0x2d3198 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x19c> */
/* @0x2d332c vmov r0, s15 */
/* @0x2d3330 bl 0xb6700 <sqrtf@plt> */
/* @0x2d3334 vmov s26, r0 */
/* @0x2d3338 b 0x2d3298 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x29c> */
/* @0x2d333c andeq r0, r0, r0 */
/* @0x2d3340 bllo 0xfebc8f70 <b2_toiTime+0xfffffffffe46facc> */
/* @0x2d3344 vstrlo s30, [lr, #-216] */

/* ── FUNC 0x2d3348 · b2WeldJoint::InitVelocityConstraints(b2SolverData const&) · size=848 · insn=212 */
/* @0x2d3348 ldr r2, [r0, #0x30] */
/* @0x2d334c ldr r3, [r0, #0x34] */
/* @0x2d3350 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2d3354 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d3358 mov r5, r1 */
/* @0x2d335c vldr s17, [r2, #144] */
/* @0x2d3360 add r1, r2, #44 */
/* @0x2d3364 mov r4, r0 */
/* @0x2d3368 ldr r12, [r3, #0x8] */
/* @0x2d336c add r10, r0, #140 */
/* @0x2d3370 ldr lr, [r2, #0x8] */
/* @0x2d3374 add r7, r0, #148 */
/* @0x2d3378 ldm r1, {r0, r1} */
/* @0x2d337c add r9, r3, #44 */
/* @0x2d3380 vldr s18, [r3, #136] */
/* @0x2d3384 ldr r8, [r5, #0x18] */
/* @0x2d3388 vldr s19, [r2, #136] */
/* @0x2d338c ldr r6, [r5, #0x1c] */
/* @0x2d3390 str lr, [r4, #0x74] */
/* @0x2d3394 add lr, lr, lr, lsl #1 */
/* @0x2d3398 str r12, [r4, #0x78] */
/* @0x2d339c add r12, r12, r12, lsl #1 */
/* @0x2d33a0 stm r10, {r0, r1} */
/* @0x2d33a4 lsl lr, lr, #2 */
/* @0x2d33a8 ldm r9, {r0, r1} */
/* @0x2d33ac vldr s16, [r3, #144] */
/* @0x2d33b0 sub sp, sp, #40 */
/* @0x2d33b4 add r2, r8, lr */
/* @0x2d33b8 lsl r12, r12, #2 */
/* @0x2d33bc vldr s20, [r2, #8] */
/* @0x2d33c0 stm r7, {r0, r1} */
/* @0x2d33c4 vstr s19, [r4, #156] */
/* @0x2d33c8 vmov r0, s20 */
/* @0x2d33cc vstr s18, [r4, #160] */
/* @0x2d33d0 vstr s17, [r4, #164] */
/* @0x2d33d4 vstr s16, [r4, #168] */
/* @0x2d33d8 add lr, r6, lr */
/* @0x2d33dc add r8, r8, r12 */
/* @0x2d33e0 vldr s30, [lr] */
/* @0x2d33e4 add r12, r6, r12 */
/* @0x2d33e8 vldr s29, [lr, #4] */
/* @0x2d33ec vldr s28, [lr, #8] */
/* @0x2d33f0 vldr s27, [r12] */
/* @0x2d33f4 vldr s26, [r12, #4] */
/* @0x2d33f8 vldr s25, [r12, #8] */
/* @0x2d33fc bl 0xb6580 <sinf@plt> */
/* @0x2d3400 vldr s21, [r8, #8] */
/* @0x2d3404 vldr s31, [pc, #644] */
/* @0x2d3408 vmov s24, r0 */
/* @0x2d340c vmov r0, s20 */
/* @0x2d3410 bl 0xb658c <cosf@plt> */
/* @0x2d3414 vmov s23, r0 */
/* @0x2d3418 vmov r0, s21 */
/* @0x2d341c bl 0xb6580 <sinf@plt> */
/* @0x2d3420 vmov s22, r0 */
/* @0x2d3424 vmov r0, s21 */
/* @0x2d3428 bl 0xb658c <cosf@plt> */
/* @0x2d342c vldr s14, [r4, #84] */
/* @0x2d3430 vldr s15, [r4, #144] */
/* @0x2d3434 vsub.f32 s15, s14, s15 */
/* @0x2d3438 vldr s12, [r4, #92] */
/* @0x2d343c vldr s14, [r4, #152] */
/* @0x2d3440 vldr s13, [r4, #140] */
/* @0x2d3444 vldr s9, [r4, #80] */
/* @0x2d3448 vldr s8, [r4, #88] */
/* @0x2d344c vldr s10, [r4, #148] */
/* @0x2d3450 add r1, r4, #172 */
/* @0x2d3454 vsub.f32 s14, s12, s14 */
/* @0x2d3458 vmul.f32 s12, s15, s23 */
/* @0x2d345c vmov s11, r0 */
/* @0x2d3460 add r0, sp, #4 */
/* @0x2d3464 vsub.f32 s9, s9, s13 */
/* @0x2d3468 vmul.f32 s15, s15, s24 */
/* @0x2d346c vmla.f32 s12, s9, s24 */
/* @0x2d3470 vmul.f32 s13, s14, s11 */
/* @0x2d3474 vstr s12, [r4, #128] */
/* @0x2d3478 vmul.f32 s14, s14, s22 */
/* @0x2d347c vsub.f32 s10, s8, s10 */
/* @0x2d3480 vldr s8, [r4, #68] */
/* @0x2d3484 vnmls.f32 s15, s9, s23 */
/* @0x2d3488 vmla.f32 s13, s10, s22 */
/* @0x2d348c vstr s15, [r4, #124] */
/* @0x2d3490 vnmls.f32 s14, s10, s11 */
/* @0x2d3494 vstr s13, [r4, #136] */
/* @0x2d3498 vadd.f32 s10, s19, s18 */
/* @0x2d349c vstr s14, [r4, #132] */
/* @0x2d34a0 vmul.f32 s9, s12, s12 */
/* @0x2d34a4 vmov.f32 s6, s10 */
/* @0x2d34a8 vmul.f32 s7, s15, s15 */
/* @0x2d34ac vmla.f32 s6, s17, s9 */
/* @0x2d34b0 vmul.f32 s11, s14, s13 */
/* @0x2d34b4 vmla.f32 s10, s17, s7 */
/* @0x2d34b8 vneg.f32 s12, s12 */
/* @0x2d34bc vmov.f32 s9, s6 */
/* @0x2d34c0 vmul.f32 s5, s13, s13 */
/* @0x2d34c4 vmul.f32 s6, s14, s14 */
/* @0x2d34c8 vmul.f32 s7, s12, s15 */
/* @0x2d34cc vmul.f32 s11, s16, s11 */
/* @0x2d34d0 vmul.f32 s13, s16, s13 */
/* @0x2d34d4 vmul.f32 s14, s16, s14 */
/* @0x2d34d8 vnmls.f32 s11, s17, s7 */
/* @0x2d34dc vnmls.f32 s13, s17, s12 */
/* @0x2d34e0 vstr s11, [sp, #16] */
/* @0x2d34e4 vstr s11, [sp, #8] */
/* @0x2d34e8 vmla.f32 s14, s17, s15 */
/* @0x2d34ec vstr s13, [sp, #28] */
/* @0x2d34f0 vstr s13, [sp, #12] */
/* @0x2d34f4 vmla.f32 s9, s16, s5 */
/* @0x2d34f8 vstr s14, [sp, #32] */
/* @0x2d34fc vstr s14, [sp, #24] */
/* @0x2d3500 vmla.f32 s10, s16, s6 */
/* @0x2d3504 vstr s9, [sp, #4] */
/* @0x2d3508 vadd.f32 s22, s17, s16 */
/* @0x2d350c vstr s10, [sp, #20] */
/* @0x2d3510 vcmpe.f32 s8, s31 */
/* @0x2d3514 vstr s22, [sp, #36] */
/* @0x2d3518 vmrs APSR_nzcv, fpscr */
/* @0x2d351c ble 0x2d3680 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x338> */
/* @0x2d3520 bl 0x2c6940 <_ZNK7b2Mat3312GetInverse22EPS_> */
/* @0x2d3524 vcmpe.f32 s22, s31 */
/* @0x2d3528 vldr s15, [pc, #356] */
/* @0x2d352c vldr s13, [r4, #68] */
/* @0x2d3530 vldr s14, [r5] */
/* @0x2d3534 vldr s11, [r4, #96] */
/* @0x2d3538 vmrs APSR_nzcv, fpscr */
/* @0x2d353c vmovgt.f32 s12, #1.000000e+00 */
/* @0x2d3540 vmul.f32 s13, s13, s15 */
/* @0x2d3544 vldr s15, [r4, #72] */
/* @0x2d3548 vmovle.f32 s12, s31 */
/* @0x2d354c vsub.f32 s20, s21, s20 */
/* @0x2d3550 vdivgt.f32 s12, s12, s22 */
/* @0x2d3554 vaddgt.f32 s31, s12, s12 */
/* @0x2d3558 vmul.f32 s12, s12, s13 */
/* @0x2d355c vmul.f32 s31, s31, s15 */
/* @0x2d3560 vmul.f32 s12, s12, s13 */
/* @0x2d3564 vmul.f32 s15, s31, s13 */
/* @0x2d3568 vmla.f32 s15, s14, s12 */
/* @0x2d356c vmul.f32 s15, s15, s14 */
/* @0x2d3570 vcmp.f32 s15, #0 */
/* @0x2d3574 vmrs APSR_nzcv, fpscr */
/* @0x2d3578 vmovne.f32 s13, #1.000000e+00 */
/* @0x2d357c vldreq s15, [pc, #268] */
/* @0x2d3580 vdivne.f32 s15, s13, s15 */
/* @0x2d3584 vsub.f32 s20, s20, s11 */
/* @0x2d3588 vstr s15, [r4, #100] */
/* @0x2d358c vmul.f32 s14, s20, s14 */
/* @0x2d3590 vmul.f32 s12, s14, s12 */
/* @0x2d3594 vadd.f32 s22, s15, s22 */
/* @0x2d3598 vmul.f32 s15, s15, s12 */
/* @0x2d359c vcmp.f32 s22, #0 */
/* @0x2d35a0 vstr s15, [r4, #76] */
/* @0x2d35a4 vmrs APSR_nzcv, fpscr */
/* @0x2d35a8 vmovne.f32 s15, #1.000000e+00 */
/* @0x2d35ac vldreq s22, [pc, #220] */
/* @0x2d35b0 vdivne.f32 s22, s15, s22 */
/* @0x2d35b4 vstr s22, [r4, #204] */
/* @0x2d35b8 ldrb r3, [r5, #0x14] */
/* @0x2d35bc cmp r3, #0 */
/* @0x2d35c0 bne 0x2d3614 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x2cc> */
/* @0x2d35c4 mov r3, #0 */
/* @0x2d35c8 str r3, [r4, #0x68] */
/* @0x2d35cc str r3, [r4, #0x6c] */
/* @0x2d35d0 str r3, [r4, #0x70] */
/* @0x2d35d4 ldr r2, [r4, #0x74] */
/* @0x2d35d8 ldr r3, [r4, #0x78] */
/* @0x2d35dc ldr r1, [r5, #0x1c] */
/* @0x2d35e0 add r2, r2, r2, lsl #1 */
/* @0x2d35e4 add r3, r3, r3, lsl #1 */
/* @0x2d35e8 add r2, r1, r2, lsl #2 */
/* @0x2d35ec vstr s30, [r2] */
/* @0x2d35f0 vstr s29, [r2, #4] */
/* @0x2d35f4 vstr s28, [r2, #8] */
/* @0x2d35f8 add r3, r1, r3, lsl #2 */
/* @0x2d35fc vstr s27, [r3] */
/* @0x2d3600 vstr s26, [r3, #4] */
/* @0x2d3604 vstr s25, [r3, #8] */
/* @0x2d3608 add sp, sp, #40 */
/* @0x2d360c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d3610 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2d3614 vldr s12, [r5, #8] */
/* @0x2d3618 vldr s14, [r4, #104] */
/* @0x2d361c vmul.f32 s14, s12, s14 */
/* @0x2d3620 vldr s15, [r4, #108] */
/* @0x2d3624 vldr s11, [r4, #128] */
/* @0x2d3628 vldr s13, [r4, #136] */
/* @0x2d362c vldr s8, [r4, #124] */
/* @0x2d3630 vldr s9, [r4, #132] */
/* @0x2d3634 vldr s10, [r4, #112] */
/* @0x2d3638 vmul.f32 s15, s12, s15 */
/* @0x2d363c vstr s14, [r4, #104] */
/* @0x2d3640 vmul.f32 s11, s14, s11 */
/* @0x2d3644 vstr s15, [r4, #108] */
/* @0x2d3648 vmul.f32 s13, s14, s13 */
/* @0x2d364c vnmls.f32 s11, s15, s8 */
/* @0x2d3650 vnmls.f32 s13, s15, s9 */
/* @0x2d3654 vmul.f32 s12, s12, s10 */
/* @0x2d3658 vadd.f32 s11, s12, s11 */
/* @0x2d365c vstr s12, [r4, #112] */
/* @0x2d3660 vadd.f32 s13, s12, s13 */
/* @0x2d3664 vmls.f32 s30, s19, s14 */
/* @0x2d3668 vmla.f32 s27, s18, s14 */
/* @0x2d366c vmls.f32 s29, s19, s15 */
/* @0x2d3670 vmla.f32 s26, s18, s15 */
/* @0x2d3674 vmls.f32 s28, s17, s11 */
/* @0x2d3678 vmla.f32 s25, s16, s13 */
/* @0x2d367c b 0x2d35d4 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x28c> */
/* @0x2d3680 bl 0x2c69a8 <_ZNK7b2Mat3315GetSymInverse33EPS_> */
/* @0x2d3684 vstr s31, [r4, #100] */
/* @0x2d3688 vstr s31, [r4, #76] */
/* @0x2d368c b 0x2d35b8 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x270> */
/* @0x2d3690 andeq r0, r0, r0 */
/* @0x2d3694 ldrdmi r0, r1, [r9], #251 */

/* ── FUNC 0x2d3698 · b2WeldJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&) · size=140 · insn=35 */
/* @0x2d3698 vldr s15, [r1, #16] */
/* @0x2d369c vldr s14, [r3, #4] */
/* @0x2d36a0 vsub.f32 s14, s14, s15 */
/* @0x2d36a4 vldr s9, [r1, #20] */
/* @0x2d36a8 vldr s8, [r1, #24] */
/* @0x2d36ac vldr s4, [r3] */
/* @0x2d36b0 vldr s10, [r1, #12] */
/* @0x2d36b4 vldr s12, [r2, #20] */
/* @0x2d36b8 vldr s11, [r2, #24] */
/* @0x2d36bc vldr s15, [r2, #16] */
/* @0x2d36c0 vldr s5, [r2, #12] */
/* @0x2d36c4 vldr s6, [r2, #72] */
/* @0x2d36c8 vldr s7, [r1, #72] */
/* @0x2d36cc str r1, [r0, #0x8] */
/* @0x2d36d0 str r2, [r0, #0xc] */
/* @0x2d36d4 vmul.f32 s13, s14, s9 */
/* @0x2d36d8 vmul.f32 s14, s14, s8 */
/* @0x2d36dc vsub.f32 s10, s4, s10 */
/* @0x2d36e0 vmla.f32 s13, s10, s8 */
/* @0x2d36e4 vmls.f32 s14, s9, s10 */
/* @0x2d36e8 vstr s13, [r0, #20] */
/* @0x2d36ec vstr s14, [r0, #24] */
/* @0x2d36f0 vldr s14, [r3, #4] */
/* @0x2d36f4 vsub.f32 s15, s14, s15 */
/* @0x2d36f8 vldr s13, [r3] */
/* @0x2d36fc vmul.f32 s14, s15, s12 */
/* @0x2d3700 vsub.f32 s13, s13, s5 */
/* @0x2d3704 vmul.f32 s15, s15, s11 */
/* @0x2d3708 vmla.f32 s14, s13, s11 */
/* @0x2d370c vmls.f32 s15, s12, s13 */
/* @0x2d3710 vstr s14, [r0, #28] */
/* @0x2d3714 vsub.f32 s14, s6, s7 */
/* @0x2d3718 vstr s15, [r0, #32] */
/* @0x2d371c vstr s14, [r0, #36] */
/* @0x2d3720 bx lr */

/* ── FUNC 0x2d3724 · b2WeldJoint::b2WeldJoint(b2WeldJointDef const*) · size=116 · insn=29 */
/* @0x2d3724 push {r3, r4, r5, r6, r7, lr} */
/* @0x2d3728 mov r4, r0 */
/* @0x2d372c mov r5, r1 */
/* @0x2d3730 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2d3734 add r3, r5, #20 */
/* @0x2d3738 ldr r2, [pc, #0x54] */
/* @0x2d373c add r6, r5, #28 */
/* @0x2d3740 ldr r7, [r5, #0x24] */
/* @0x2d3744 ldm r3, {r0, r1} */
/* @0x2d3748 ldr r2, [pc, r2] */
/* @0x2d374c mov r3, r4 */
/* @0x2d3750 add r2, r2, #8 */
/* @0x2d3754 str r2, [r3], #80 */
/* @0x2d3758 add r12, r4, #88 */
/* @0x2d375c stm r3, {r0, r1} */
/* @0x2d3760 mov r3, #0 */
/* @0x2d3764 ldm r6, {r0, r1} */
/* @0x2d3768 ldr r2, [r5, #0x2c] */
/* @0x2d376c ldr r6, [r5, #0x28] */
/* @0x2d3770 stm r12, {r0, r1} */
/* @0x2d3774 mov r0, r4 */
/* @0x2d3778 str r7, [r4, #0x60] */
/* @0x2d377c str r6, [r4, #0x44] */
/* @0x2d3780 str r2, [r4, #0x48] */
/* @0x2d3784 str r3, [r4, #0x68] */
/* @0x2d3788 str r3, [r4, #0x6c] */
/* @0x2d378c str r3, [r4, #0x70] */
/* @0x2d3790 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2d3794 andseq lr, r1, r0, lsr r4 */

/* ── FUNC 0x2d3724 · b2WeldJoint::b2WeldJoint(b2WeldJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d3798 · b2WheelJoint::SolveVelocityConstraints(b2SolverData const&) · size=404 · insn=101 */
/* @0x2d3798 ldr r2, [r0, #0x84] */
/* @0x2d379c vldr s15, [r0, #176] */
/* @0x2d37a0 ldr r3, [r0, #0x88] */
/* @0x2d37a4 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d37a8 ldr r12, [r1, #0x1c] */
/* @0x2d37ac vldr s19, [r0, #172] */
/* @0x2d37b0 add r2, r2, r2, lsl #1 */
/* @0x2d37b4 vldr s20, [r0, #192] */
/* @0x2d37b8 add r3, r3, r3, lsl #1 */
/* @0x2d37bc vldr s24, [r0, #188] */
/* @0x2d37c0 add r2, r12, r2, lsl #2 */
/* @0x2d37c4 vldr s2, [r2, #4] */
/* @0x2d37c8 add r3, r12, r3, lsl #2 */
/* @0x2d37cc vldr s6, [r3, #4] */
/* @0x2d37d0 vsub.f32 s14, s6, s2 */
/* @0x2d37d4 vldr s1, [r2] */
/* @0x2d37d8 vldr s5, [r3] */
/* @0x2d37dc vldr s7, [r3, #8] */
/* @0x2d37e0 vldr s3, [r2, #8] */
/* @0x2d37e4 vldr s29, [r0, #216] */
/* @0x2d37e8 vldr s8, [r0, #116] */
/* @0x2d37ec vldr s28, [r0, #220] */
/* @0x2d37f0 vldr s27, [r0, #212] */
/* @0x2d37f4 vldr s10, [r0, #164] */
/* @0x2d37f8 vldr s11, [r0, #168] */
/* @0x2d37fc vldr s26, [r0, #124] */
/* @0x2d3800 vldr s18, [r0, #112] */
/* @0x2d3804 vldr s25, [r0, #208] */
/* @0x2d3808 vldr s12, [r0, #156] */
/* @0x2d380c vldr s13, [r0, #160] */
/* @0x2d3810 vldr s23, [r1] */
/* @0x2d3814 vldr s9, [r0, #120] */
/* @0x2d3818 vldr s17, [r0, #184] */
/* @0x2d381c vldr s4, [r0, #180] */
/* @0x2d3820 vmul.f32 s14, s14, s15 */
/* @0x2d3824 vldr s0, [r0, #200] */
/* @0x2d3828 vldr s16, [r0, #196] */
/* @0x2d382c vldr s22, [r0, #204] */
/* @0x2d3830 vldr s21, [r0, #108] */
/* @0x2d3834 vsub.f32 s30, s5, s1 */
/* @0x2d3838 vmla.f32 s14, s30, s19 */
/* @0x2d383c vmla.f32 s14, s20, s7 */
/* @0x2d3840 vmls.f32 s14, s24, s3 */
/* @0x2d3844 vadd.f32 s14, s14, s29 */
/* @0x2d3848 vmla.f32 s14, s8, s28 */
/* @0x2d384c vnmul.f32 s14, s27, s14 */
/* @0x2d3850 vmul.f32 s24, s24, s14 */
/* @0x2d3854 vmul.f32 s20, s20, s14 */
/* @0x2d3858 vmls.f32 s3, s10, s24 */
/* @0x2d385c vmla.f32 s7, s11, s20 */
/* @0x2d3860 vsub.f32 s20, s7, s3 */
/* @0x2d3864 vsub.f32 s20, s20, s26 */
/* @0x2d3868 vmul.f32 s15, s14, s15 */
/* @0x2d386c vmov.f32 s24, s18 */
/* @0x2d3870 vmls.f32 s24, s25, s20 */
/* @0x2d3874 vmul.f32 s19, s14, s19 */
/* @0x2d3878 vmls.f32 s2, s12, s15 */
/* @0x2d387c vmla.f32 s6, s13, s15 */
/* @0x2d3880 vmul.f32 s9, s23, s9 */
/* @0x2d3884 vmls.f32 s1, s12, s19 */
/* @0x2d3888 vmla.f32 s5, s13, s19 */
/* @0x2d388c vcmpe.f32 s9, s24 */
/* @0x2d3890 vneg.f32 s19, s9 */
/* @0x2d3894 vmrs APSR_nzcv, fpscr */
/* @0x2d3898 vsub.f32 s15, s6, s2 */
/* @0x2d389c vmovgt.f32 s9, s24 */
/* @0x2d38a0 vcmpe.f32 s19, s9 */
/* @0x2d38a4 vmrs APSR_nzcv, fpscr */
/* @0x2d38a8 vmovgt.f32 s9, s19 */
/* @0x2d38ac vstr s9, [r0, #112] */
/* @0x2d38b0 vmul.f32 s15, s15, s17 */
/* @0x2d38b4 vsub.f32 s19, s5, s1 */
/* @0x2d38b8 vsub.f32 s9, s9, s18 */
/* @0x2d38bc vmla.f32 s15, s19, s4 */
/* @0x2d38c0 vmla.f32 s7, s11, s9 */
/* @0x2d38c4 vmls.f32 s3, s10, s9 */
/* @0x2d38c8 vmla.f32 s15, s0, s7 */
/* @0x2d38cc vmls.f32 s15, s16, s3 */
/* @0x2d38d0 vnmul.f32 s15, s22, s15 */
/* @0x2d38d4 vmul.f32 s9, s15, s17 */
/* @0x2d38d8 vmul.f32 s4, s15, s4 */
/* @0x2d38dc vmul.f32 s16, s16, s15 */
/* @0x2d38e0 vmul.f32 s0, s0, s15 */
/* @0x2d38e4 vmls.f32 s3, s10, s16 */
/* @0x2d38e8 vmls.f32 s1, s12, s4 */
/* @0x2d38ec vmls.f32 s2, s12, s9 */
/* @0x2d38f0 vmla.f32 s5, s13, s4 */
/* @0x2d38f4 vmla.f32 s6, s13, s9 */
/* @0x2d38f8 vmla.f32 s7, s11, s0 */
/* @0x2d38fc vadd.f32 s15, s21, s15 */
/* @0x2d3900 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d3904 vadd.f32 s14, s8, s14 */
/* @0x2d3908 vstr s15, [r0, #108] */
/* @0x2d390c vstr s14, [r0, #116] */
/* @0x2d3910 vstr s1, [r2] */
/* @0x2d3914 vstr s2, [r2, #4] */
/* @0x2d3918 vstr s3, [r2, #8] */
/* @0x2d391c vstr s5, [r3] */
/* @0x2d3920 vstr s6, [r3, #4] */
/* @0x2d3924 vstr s7, [r3, #8] */
/* @0x2d3928 bx lr */

/* ── FUNC 0x2d392c · b2WheelJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2d392c ldr r3, [r1, #0x30] */
/* @0x2d3930 vldr s15, [r1, #80] */
/* @0x2d3934 vldr s12, [r3, #24] */
/* @0x2d3938 vldr s11, [r3, #20] */
/* @0x2d393c vmul.f32 s14, s12, s15 */
/* @0x2d3940 vldr s13, [r1, #76] */
/* @0x2d3944 vldr s9, [r3, #16] */
/* @0x2d3948 vldr s10, [r3, #12] */
/* @0x2d394c vmul.f32 s15, s11, s15 */
/* @0x2d3950 vmla.f32 s14, s13, s11 */
/* @0x2d3954 vnmls.f32 s15, s12, s13 */
/* @0x2d3958 vadd.f32 s14, s14, s9 */
/* @0x2d395c vadd.f32 s15, s15, s10 */
/* @0x2d3960 vstr s14, [r0, #4] */
/* @0x2d3964 vstr s15, [r0] */
/* @0x2d3968 bx lr */

/* ── FUNC 0x2d396c · b2WheelJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2d396c ldr r3, [r1, #0x34] */
/* @0x2d3970 vldr s15, [r1, #88] */
/* @0x2d3974 vldr s12, [r3, #24] */
/* @0x2d3978 vldr s11, [r3, #20] */
/* @0x2d397c vmul.f32 s14, s12, s15 */
/* @0x2d3980 vldr s13, [r1, #84] */
/* @0x2d3984 vldr s9, [r3, #16] */
/* @0x2d3988 vldr s10, [r3, #12] */
/* @0x2d398c vmul.f32 s15, s11, s15 */
/* @0x2d3990 vmla.f32 s14, s13, s11 */
/* @0x2d3994 vnmls.f32 s15, s12, s13 */
/* @0x2d3998 vadd.f32 s14, s14, s9 */
/* @0x2d399c vadd.f32 s15, s15, s10 */
/* @0x2d39a0 vstr s14, [r0, #4] */
/* @0x2d39a4 vstr s15, [r0] */
/* @0x2d39a8 bx lr */

/* ── FUNC 0x2d39ac · b2WheelJoint::GetReactionForce(float) const · size=64 · insn=16 */
/* @0x2d39ac vldr s15, [r1, #116] */
/* @0x2d39b0 vldr s14, [r1, #176] */
/* @0x2d39b4 vldr s9, [r1, #172] */
/* @0x2d39b8 vmul.f32 s14, s15, s14 */
/* @0x2d39bc vldr s12, [r1, #108] */
/* @0x2d39c0 vldr s10, [r1, #184] */
/* @0x2d39c4 vldr s11, [r1, #180] */
/* @0x2d39c8 vmov s13, r2 */
/* @0x2d39cc vmul.f32 s15, s15, s9 */
/* @0x2d39d0 vmla.f32 s14, s12, s10 */
/* @0x2d39d4 vmla.f32 s15, s12, s11 */
/* @0x2d39d8 vmul.f32 s14, s13, s14 */
/* @0x2d39dc vmul.f32 s15, s13, s15 */
/* @0x2d39e0 vstr s14, [r0, #4] */
/* @0x2d39e4 vstr s15, [r0] */
/* @0x2d39e8 bx lr */

/* ── FUNC 0x2d39ec · b2WheelJoint::GetReactionTorque(float) const · size=20 · insn=5 */
/* @0x2d39ec vmov s14, r1 */
/* @0x2d39f0 vldr s15, [r0, #112] */
/* @0x2d39f4 vmul.f32 s14, s14, s15 */
/* @0x2d39f8 vmov r0, s14 */
/* @0x2d39fc bx lr */

/* ── FUNC 0x2d3a00 · b2WheelJoint::~b2WheelJoint() · size=24 · insn=6 */
/* @0x2d3a00 ldr r3, [pc, #0xc] */
/* @0x2d3a04 ldr r3, [pc, r3] */
/* @0x2d3a08 add r3, r3, #8 */
/* @0x2d3a0c str r3, [r0] */
/* @0x2d3a10 bx lr */
/* @0x2d3a14 andseq lr, r1, r0, asr r1 */

/* ── FUNC 0x2d3a00 · b2WheelJoint::~b2WheelJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d3a18 · b2WheelJoint::Dump() · size=384 · insn=96 */
/* @0x2d3a18 push {r4, r5, r6, lr} */
/* @0x2d3a1c mov r4, r0 */
/* @0x2d3a20 ldr r2, [r4, #0x30] */
/* @0x2d3a24 sub sp, sp, #8 */
/* @0x2d3a28 ldr r3, [r4, #0x34] */
/* @0x2d3a2c ldr r0, [pc, #0x130] */
/* @0x2d3a30 ldr r6, [r2, #0x8] */
/* @0x2d3a34 add r0, pc, r0 */
/* @0x2d3a38 ldr r5, [r3, #0x8] */
/* @0x2d3a3c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3a40 ldr r0, [pc, #0x120] */
/* @0x2d3a44 mov r1, r6 */
/* @0x2d3a48 add r0, pc, r0 */
/* @0x2d3a4c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3a50 ldr r0, [pc, #0x114] */
/* @0x2d3a54 mov r1, r5 */
/* @0x2d3a58 add r0, pc, r0 */
/* @0x2d3a5c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3a60 ldr r0, [pc, #0x108] */
/* @0x2d3a64 ldrb r1, [r4, #0x3d] */
/* @0x2d3a68 add r0, pc, r0 */
/* @0x2d3a6c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3a70 vldr s13, [r4, #76] */
/* @0x2d3a74 vldr s14, [r4, #80] */
/* @0x2d3a78 vcvt.f64.f32 d5, s13 */
/* @0x2d3a7c ldr r0, [pc, #0xf0] */
/* @0x2d3a80 add r0, pc, r0 */
/* @0x2d3a84 vcvt.f64.f32 d7, s14 */
/* @0x2d3a88 vmov r2, r3, d5 */
/* @0x2d3a8c vstr d7, [sp] */
/* @0x2d3a90 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3a94 vldr s13, [r4, #84] */
/* @0x2d3a98 vldr s14, [r4, #88] */
/* @0x2d3a9c vcvt.f64.f32 d5, s13 */
/* @0x2d3aa0 ldr r0, [pc, #0xd0] */
/* @0x2d3aa4 add r0, pc, r0 */
/* @0x2d3aa8 vcvt.f64.f32 d7, s14 */
/* @0x2d3aac vmov r2, r3, d5 */
/* @0x2d3ab0 vstr d7, [sp] */
/* @0x2d3ab4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3ab8 vldr s13, [r4, #92] */
/* @0x2d3abc vldr s14, [r4, #96] */
/* @0x2d3ac0 vcvt.f64.f32 d5, s13 */
/* @0x2d3ac4 ldr r0, [pc, #0xb0] */
/* @0x2d3ac8 add r0, pc, r0 */
/* @0x2d3acc vcvt.f64.f32 d7, s14 */
/* @0x2d3ad0 vmov r2, r3, d5 */
/* @0x2d3ad4 vstr d7, [sp] */
/* @0x2d3ad8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3adc ldr r0, [pc, #0x9c] */
/* @0x2d3ae0 ldrb r1, [r4, #0x80] */
/* @0x2d3ae4 add r0, pc, r0 */
/* @0x2d3ae8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3aec vldr s15, [r4, #124] */
/* @0x2d3af0 vcvt.f64.f32 d6, s15 */
/* @0x2d3af4 ldr r0, [pc, #0x88] */
/* @0x2d3af8 add r0, pc, r0 */
/* @0x2d3afc vmov r2, r3, d6 */
/* @0x2d3b00 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3b04 vldr s15, [r4, #120] */
/* @0x2d3b08 vcvt.f64.f32 d5, s15 */
/* @0x2d3b0c ldr r0, [pc, #0x74] */
/* @0x2d3b10 add r0, pc, r0 */
/* @0x2d3b14 vmov r2, r3, d5 */
/* @0x2d3b18 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3b1c vldr s15, [r4, #68] */
/* @0x2d3b20 vcvt.f64.f32 d6, s15 */
/* @0x2d3b24 ldr r0, [pc, #0x60] */
/* @0x2d3b28 add r0, pc, r0 */
/* @0x2d3b2c vmov r2, r3, d6 */
/* @0x2d3b30 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3b34 vldr s15, [r4, #72] */
/* @0x2d3b38 vcvt.f64.f32 d5, s15 */
/* @0x2d3b3c ldr r0, [pc, #0x4c] */
/* @0x2d3b40 add r0, pc, r0 */
/* @0x2d3b44 vmov r2, r3, d5 */
/* @0x2d3b48 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3b4c ldr r0, [pc, #0x40] */
/* @0x2d3b50 ldr r1, [r4, #0x38] */
/* @0x2d3b54 add r0, pc, r0 */
/* @0x2d3b58 add sp, sp, #8 */
/* @0x2d3b5c pop {r4, r5, r6, lr} */
/* @0x2d3b60 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d3b64 andeq r8, r8, r12, asr r9 */
/* @0x2d3b68 andeq r8, r8, r4, ror #8 */
/* @0x2d3b6c andeq r8, r8, r0, ror r4 */
/* @0x2d3b70 andeq r8, r8, r12, ror r4 */
/* @0x2d3b74 andeq r8, r8, r8, lsl #9 */
/* @0x2d3b78 muleq r8, r0, r4 */
/* @0x2d3b7c andeq r8, r8, r12, lsr r6 */
/* @0x2d3b80 ldrdeq r8, r9, [r8], -r0 */
/* @0x2d3b84 ldrdeq r8, r9, [r8], -r12 */
/* @0x2d3b88 andeq r8, r8, r4, lsl r8 */
/* @0x2d3b8c andeq r8, r8, r0, asr r4 */
/* @0x2d3b90 andeq r8, r8, r8, asr r4 */
/* @0x2d3b94 andeq r8, r8, r4, ror #8 */

/* ── FUNC 0x2d3b98 · b2WheelJoint::~b2WheelJoint() · size=40 · insn=10 */
/* @0x2d3b98 ldr r3, [pc, #0x1c] */
/* @0x2d3b9c push {r4, lr} */
/* @0x2d3ba0 ldr r3, [pc, r3] */
/* @0x2d3ba4 mov r4, r0 */
/* @0x2d3ba8 add r3, r3, #8 */
/* @0x2d3bac str r3, [r0] */
/* @0x2d3bb0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d3bb4 mov r0, r4 */
/* @0x2d3bb8 pop {r4, pc} */
/* @0x2d3bbc ldrheq sp, [r1], -r4 */

/* ── FUNC 0x2d3bc0 · b2WheelJoint::SolvePositionConstraints(b2SolverData const&) · size=448 · insn=112 */
/* @0x2d3bc0 push {r4, r5, r6, lr} */
/* @0x2d3bc4 vpush {d8, d9, d10, d11, d12} */
/* @0x2d3bc8 mov r4, r0 */
/* @0x2d3bcc ldr r6, [r0, #0x84] */
/* @0x2d3bd0 ldr r5, [r0, #0x88] */
/* @0x2d3bd4 ldr r3, [r1, #0x18] */
/* @0x2d3bd8 add r6, r6, r6, lsl #1 */
/* @0x2d3bdc add r5, r5, r5, lsl #1 */
/* @0x2d3be0 add r6, r3, r6, lsl #2 */
/* @0x2d3be4 vldr s19, [r6, #8] */
/* @0x2d3be8 vmov r0, s19 */
/* @0x2d3bec add r5, r3, r5, lsl #2 */
/* @0x2d3bf0 bl 0xb6580 <sinf@plt> */
/* @0x2d3bf4 vldr s18, [r5, #8] */
/* @0x2d3bf8 vldr s20, [r6, #4] */
/* @0x2d3bfc vmov s16, r0 */
/* @0x2d3c00 vmov r0, s19 */
/* @0x2d3c04 bl 0xb658c <cosf@plt> */
/* @0x2d3c08 vmov s17, r0 */
/* @0x2d3c0c vmov r0, s18 */
/* @0x2d3c10 bl 0xb6580 <sinf@plt> */
/* @0x2d3c14 vmov s21, r0 */
/* @0x2d3c18 vmov r0, s18 */
/* @0x2d3c1c bl 0xb658c <cosf@plt> */
/* @0x2d3c20 vldr s15, [r4, #152] */
/* @0x2d3c24 vldr s11, [r4, #88] */
/* @0x2d3c28 vsub.f32 s11, s11, s15 */
/* @0x2d3c2c vldr s12, [r4, #148] */
/* @0x2d3c30 vldr s25, [r4, #84] */
/* @0x2d3c34 vldr s8, [r4, #80] */
/* @0x2d3c38 vldr s10, [r4, #144] */
/* @0x2d3c3c vldr s14, [r4, #196] */
/* @0x2d3c40 vldr s2, [r4, #164] */
/* @0x2d3c44 vldr s6, [r4, #156] */
/* @0x2d3c48 vldr s7, [r4, #160] */
/* @0x2d3c4c vldr s13, [r4, #140] */
/* @0x2d3c50 vldr s0, [r4, #76] */
/* @0x2d3c54 vldr s15, [r4, #104] */
/* @0x2d3c58 vldr s4, [r5, #4] */
/* @0x2d3c5c vldr s23, [r4, #100] */
/* @0x2d3c60 vldr s3, [r5] */
/* @0x2d3c64 vldr s1, [r6] */
/* @0x2d3c68 vldr s22, [r4, #200] */
/* @0x2d3c6c vldr s5, [r4, #168] */
/* @0x2d3c70 vsub.f32 s25, s25, s12 */
/* @0x2d3c74 vsub.f32 s10, s8, s10 */
/* @0x2d3c78 vsub.f32 s0, s0, s13 */
/* @0x2d3c7c vmov s24, r0 */
/* @0x2d3c80 vmul.f32 s9, s11, s24 */
/* @0x2d3c84 vmul.f32 s11, s11, s21 */
/* @0x2d3c88 vmla.f32 s9, s25, s21 */
/* @0x2d3c8c vmul.f32 s21, s2, s14 */
/* @0x2d3c90 vmul.f32 s8, s10, s17 */
/* @0x2d3c94 vadd.f32 s13, s6, s7 */
/* @0x2d3c98 vmla.f32 s13, s14, s21 */
/* @0x2d3c9c vmul.f32 s14, s15, s16 */
/* @0x2d3ca0 vmul.f32 s15, s15, s17 */
/* @0x2d3ca4 vmla.f32 s8, s0, s16 */
/* @0x2d3ca8 vmul.f32 s10, s10, s16 */
/* @0x2d3cac vsub.f32 s12, s4, s20 */
/* @0x2d3cb0 vnmls.f32 s11, s25, s24 */
/* @0x2d3cb4 vmla.f32 s15, s23, s16 */
/* @0x2d3cb8 vadd.f32 s12, s9, s12 */
/* @0x2d3cbc vnmls.f32 s10, s0, s17 */
/* @0x2d3cc0 vsub.f32 s0, s3, s1 */
/* @0x2d3cc4 vsub.f32 s12, s12, s8 */
/* @0x2d3cc8 vnmls.f32 s14, s23, s17 */
/* @0x2d3ccc vadd.f32 s0, s11, s0 */
/* @0x2d3cd0 vmul.f32 s21, s5, s22 */
/* @0x2d3cd4 vadd.f32 s8, s8, s12 */
/* @0x2d3cd8 vmul.f32 s12, s12, s15 */
/* @0x2d3cdc vsub.f32 s0, s0, s10 */
/* @0x2d3ce0 vmla.f32 s13, s22, s21 */
/* @0x2d3ce4 vmla.f32 s12, s0, s14 */
/* @0x2d3ce8 vmul.f32 s9, s9, s14 */
/* @0x2d3cec vcmp.f32 s13, #0 */
/* @0x2d3cf0 vnmls.f32 s9, s11, s15 */
/* @0x2d3cf4 vmrs APSR_nzcv, fpscr */
/* @0x2d3cf8 vldreq s13, [pc, #120] */
/* @0x2d3cfc vnegne.f32 s11, s12 */
/* @0x2d3d00 vdivne.f32 s13, s11, s13 */
/* @0x2d3d04 vmul.f32 s8, s14, s8 */
/* @0x2d3d08 vadd.f32 s10, s10, s0 */
/* @0x2d3d0c vnmls.f32 s8, s15, s10 */
/* @0x2d3d10 vmul.f32 s14, s13, s14 */
/* @0x2d3d14 vmul.f32 s15, s13, s15 */
/* @0x2d3d18 vmul.f32 s8, s13, s8 */
/* @0x2d3d1c vmul.f32 s13, s13, s9 */
/* @0x2d3d20 vmls.f32 s20, s6, s15 */
/* @0x2d3d24 vmls.f32 s19, s2, s8 */
/* @0x2d3d28 vstr s20, [r6, #4] */
/* @0x2d3d2c vmla.f32 s4, s7, s15 */
/* @0x2d3d30 vstr s19, [r6, #8] */
/* @0x2d3d34 vldr s15, [pc, #64] */
/* @0x2d3d38 vmla.f32 s18, s5, s13 */
/* @0x2d3d3c vmls.f32 s1, s6, s14 */
/* @0x2d3d40 vmla.f32 s3, s7, s14 */
/* @0x2d3d44 vstr s1, [r6] */
/* @0x2d3d48 vcmpe.f32 s12, #0 */
/* @0x2d3d4c vstr s3, [r5] */
/* @0x2d3d50 vstr s4, [r5, #4] */
/* @0x2d3d54 vstr s18, [r5, #8] */
/* @0x2d3d58 vpop {d8, d9, d10, d11, d12} */
/* @0x2d3d5c vmrs APSR_nzcv, fpscr */
/* @0x2d3d60 vnegle.f32 s12, s12 */
/* @0x2d3d64 vcmpe.f32 s12, s15 */
/* @0x2d3d68 vmrs APSR_nzcv, fpscr */
/* @0x2d3d6c movhi r0, #0 */
/* @0x2d3d70 movls r0, #1 */
/* @0x2d3d74 pop {r4, r5, r6, pc} */
/* @0x2d3d78 andeq r0, r0, r0 */
/* @0x2d3d7c bllo 0xfebc99ac <b2_toiTime+0xfffffffffe470508> */

/* ── FUNC 0x2d3d80 · b2WheelJoint::InitVelocityConstraints(b2SolverData const&) · size=1008 · insn=252 */
/* @0x2d3d80 ldr r2, [r0, #0x30] */
/* @0x2d3d84 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2d3d88 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d3d8c mov r6, r1 */
/* @0x2d3d90 vldr s21, [r2, #136] */
/* @0x2d3d94 ldr r3, [r0, #0x34] */
/* @0x2d3d98 add r1, r2, #44 */
/* @0x2d3d9c ldr lr, [r2, #0x8] */
/* @0x2d3da0 mov r4, r0 */
/* @0x2d3da4 vldr s20, [r3, #136] */
/* @0x2d3da8 ldr r8, [r6, #0x18] */
/* @0x2d3dac ldr r12, [r3, #0x8] */
/* @0x2d3db0 add r10, r0, #140 */
/* @0x2d3db4 add r9, r0, #148 */
/* @0x2d3db8 ldm r1, {r0, r1} */
/* @0x2d3dbc str lr, [r4, #0x84] */
/* @0x2d3dc0 add lr, lr, lr, lsl #1 */
/* @0x2d3dc4 add r7, r3, #44 */
/* @0x2d3dc8 vldr s19, [r2, #144] */
/* @0x2d3dcc lsl lr, lr, #2 */
/* @0x2d3dd0 ldr r5, [r6, #0x1c] */
/* @0x2d3dd4 str r12, [r4, #0x88] */
/* @0x2d3dd8 add r12, r12, r12, lsl #1 */
/* @0x2d3ddc stm r10, {r0, r1} */
/* @0x2d3de0 vldr s18, [r3, #144] */
/* @0x2d3de4 ldm r7, {r0, r1} */
/* @0x2d3de8 add r7, r8, lr */
/* @0x2d3dec lsl r12, r12, #2 */
/* @0x2d3df0 add lr, r5, lr */
/* @0x2d3df4 ldr r10, [r7, #0x8] */
/* @0x2d3df8 vldr s27, [lr] */
/* @0x2d3dfc stm r9, {r0, r1} */
/* @0x2d3e00 vstr s20, [r4, #160] */
/* @0x2d3e04 vstr s21, [r4, #156] */
/* @0x2d3e08 vstr s19, [r4, #164] */
/* @0x2d3e0c mov r0, r10 */
/* @0x2d3e10 vstr s18, [r4, #168] */
/* @0x2d3e14 vldr s26, [lr, #4] */
/* @0x2d3e18 vldr s25, [lr, #8] */
/* @0x2d3e1c add r8, r8, r12 */
/* @0x2d3e20 add r12, r5, r12 */
/* @0x2d3e24 vldr s24, [r12] */
/* @0x2d3e28 vldr s23, [r12, #4] */
/* @0x2d3e2c vldr s22, [r12, #8] */
/* @0x2d3e30 bl 0xb6580 <sinf@plt> */
/* @0x2d3e34 ldr r9, [r8, #0x8] */
/* @0x2d3e38 vadd.f32 s20, s21, s20 */
/* @0x2d3e3c vmov s16, r0 */
/* @0x2d3e40 mov r0, r10 */
/* @0x2d3e44 bl 0xb658c <cosf@plt> */
/* @0x2d3e48 vmov s17, r0 */
/* @0x2d3e4c mov r0, r9 */
/* @0x2d3e50 bl 0xb6580 <sinf@plt> */
/* @0x2d3e54 vmov s28, r0 */
/* @0x2d3e58 mov r0, r9 */
/* @0x2d3e5c bl 0xb658c <cosf@plt> */
/* @0x2d3e60 vldr s14, [r4, #152] */
/* @0x2d3e64 vldr s12, [r4, #88] */
/* @0x2d3e68 vsub.f32 s12, s12, s14 */
/* @0x2d3e6c vldr s1, [r4, #84] */
/* @0x2d3e70 vldr s7, [r4, #148] */
/* @0x2d3e74 vldr s14, [r4, #144] */
/* @0x2d3e78 vldr s10, [r4, #80] */
/* @0x2d3e7c vldr s2, [r4, #76] */
/* @0x2d3e80 vldr s8, [r4, #140] */
/* @0x2d3e84 vldr s3, [r8, #4] */
/* @0x2d3e88 vldr s13, [r4, #104] */
/* @0x2d3e8c vldr s4, [r7, #4] */
/* @0x2d3e90 vldr s6, [r8] */
/* @0x2d3e94 vldr s9, [r4, #100] */
/* @0x2d3e98 vldr s5, [r7] */
/* @0x2d3e9c mov r3, #0 */
/* @0x2d3ea0 vsub.f32 s7, s1, s7 */
/* @0x2d3ea4 vsub.f32 s10, s10, s14 */
/* @0x2d3ea8 vmul.f32 s14, s10, s17 */
/* @0x2d3eac vmov s15, r0 */
/* @0x2d3eb0 vmul.f32 s11, s12, s15 */
/* @0x2d3eb4 vmul.f32 s12, s12, s28 */
/* @0x2d3eb8 vmla.f32 s11, s7, s28 */
/* @0x2d3ebc vsub.f32 s8, s2, s8 */
/* @0x2d3ec0 vnmls.f32 s12, s7, s15 */
/* @0x2d3ec4 vmla.f32 s14, s8, s16 */
/* @0x2d3ec8 vmul.f32 s10, s10, s16 */
/* @0x2d3ecc vadd.f32 s7, s11, s3 */
/* @0x2d3ed0 vmul.f32 s15, s13, s16 */
/* @0x2d3ed4 vsub.f32 s7, s7, s4 */
/* @0x2d3ed8 vnmls.f32 s10, s8, s17 */
/* @0x2d3edc vadd.f32 s6, s12, s6 */
/* @0x2d3ee0 vnmls.f32 s15, s9, s17 */
/* @0x2d3ee4 vmul.f32 s13, s13, s17 */
/* @0x2d3ee8 vstr s15, [r4, #180] */
/* @0x2d3eec str r3, [r4, #0xd4] */
/* @0x2d3ef0 str r3, [r4, #0xd8] */
/* @0x2d3ef4 str r3, [r4, #0xdc] */
/* @0x2d3ef8 vsub.f32 s7, s7, s14 */
/* @0x2d3efc vsub.f32 s6, s6, s5 */
/* @0x2d3f00 vadd.f32 s8, s14, s7 */
/* @0x2d3f04 vmla.f32 s13, s9, s16 */
/* @0x2d3f08 vsub.f32 s9, s6, s10 */
/* @0x2d3f0c vstr s13, [r4, #184] */
/* @0x2d3f10 vmul.f32 s14, s15, s8 */
/* @0x2d3f14 vadd.f32 s10, s10, s9 */
/* @0x2d3f18 vnmls.f32 s14, s13, s10 */
/* @0x2d3f1c vmul.f32 s15, s11, s15 */
/* @0x2d3f20 vstr s14, [r4, #196] */
/* @0x2d3f24 vnmls.f32 s15, s12, s13 */
/* @0x2d3f28 vmul.f32 s13, s19, s14 */
/* @0x2d3f2c vstr s15, [r4, #200] */
/* @0x2d3f30 vmov.f32 s6, s20 */
/* @0x2d3f34 vmla.f32 s6, s13, s14 */
/* @0x2d3f38 vmul.f32 s13, s18, s15 */
/* @0x2d3f3c vmov.f32 s14, s6 */
/* @0x2d3f40 vldr s6, [r4, #68] */
/* @0x2d3f44 vmla.f32 s14, s13, s15 */
/* @0x2d3f48 vcmpe.f32 s14, #0 */
/* @0x2d3f4c vmrs APSR_nzcv, fpscr */
/* @0x2d3f50 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2d3f54 vdivgt.f32 s14, s15, s14 */
/* @0x2d3f58 vcmpe.f32 s6, #0 */
/* @0x2d3f5c vstr s14, [r4, #204] */
/* @0x2d3f60 vmrs APSR_nzcv, fpscr */
/* @0x2d3f64 strle r3, [r4, #0x74] */
/* @0x2d3f68 ble 0x2d4040 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x2c0> */
/* @0x2d3f6c vldr s13, [r4, #96] */
/* @0x2d3f70 vmul.f32 s15, s13, s16 */
/* @0x2d3f74 vldr s14, [r4, #92] */
/* @0x2d3f78 vmul.f32 s13, s13, s17 */
/* @0x2d3f7c vnmls.f32 s15, s14, s17 */
/* @0x2d3f80 vmla.f32 s13, s14, s16 */
/* @0x2d3f84 vstr s15, [r4, #172] */
/* @0x2d3f88 vmul.f32 s14, s8, s15 */
/* @0x2d3f8c vstr s13, [r4, #176] */
/* @0x2d3f90 vnmls.f32 s14, s10, s13 */
/* @0x2d3f94 vmul.f32 s11, s11, s15 */
/* @0x2d3f98 vstr s14, [r4, #188] */
/* @0x2d3f9c vnmls.f32 s11, s12, s13 */
/* @0x2d3fa0 vmul.f32 s12, s19, s14 */
/* @0x2d3fa4 vstr s11, [r4, #192] */
/* @0x2d3fa8 vmla.f32 s20, s12, s14 */
/* @0x2d3fac vmul.f32 s14, s18, s11 */
/* @0x2d3fb0 vmla.f32 s20, s14, s11 */
/* @0x2d3fb4 vcmpe.f32 s20, #0 */
/* @0x2d3fb8 vmrs APSR_nzcv, fpscr */
/* @0x2d3fbc ble 0x2d4040 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x2c0> */
/* @0x2d3fc0 vmov.f32 s11, #1.000000e+00 */
/* @0x2d3fc4 vldr s8, [pc, #416] */
/* @0x2d3fc8 vldr s12, [r6] */
/* @0x2d3fcc vldr s10, [r4, #72] */
/* @0x2d3fd0 vdiv.f32 s14, s11, s20 */
/* @0x2d3fd4 vmul.f32 s6, s6, s8 */
/* @0x2d3fd8 vstr s14, [r4, #212] */
/* @0x2d3fdc vadd.f32 s8, s14, s14 */
/* @0x2d3fe0 vmul.f32 s14, s14, s6 */
/* @0x2d3fe4 vmul.f32 s10, s8, s10 */
/* @0x2d3fe8 vmul.f32 s14, s14, s6 */
/* @0x2d3fec vmul.f32 s6, s10, s6 */
/* @0x2d3ff0 vmla.f32 s6, s12, s14 */
/* @0x2d3ff4 vmul.f32 s6, s6, s12 */
/* @0x2d3ff8 vcmpe.f32 s6, #0 */
/* @0x2d3ffc vmrs APSR_nzcv, fpscr */
/* @0x2d4000 vdivgt.f32 s11, s11, s6 */
/* @0x2d4004 vstrle s6, [r4, #220] */
/* @0x2d4008 vmul.f32 s13, s7, s13 */
/* @0x2d400c vstrgt s11, [r4, #220] */
/* @0x2d4010 vmovgt.f32 s6, s11 */
/* @0x2d4014 vadd.f32 s20, s20, s6 */
/* @0x2d4018 vmla.f32 s13, s9, s15 */
/* @0x2d401c vcmpe.f32 s20, #0 */
/* @0x2d4020 vmrs APSR_nzcv, fpscr */
/* @0x2d4024 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2d4028 vdivgt.f32 s20, s15, s20 */
/* @0x2d402c vmul.f32 s13, s12, s13 */
/* @0x2d4030 vstr s20, [r4, #212] */
/* @0x2d4034 vmul.f32 s14, s13, s14 */
/* @0x2d4038 vmul.f32 s6, s14, s6 */
/* @0x2d403c vstr s6, [r4, #216] */
/* @0x2d4040 ldrb r3, [r4, #0x80] */
/* @0x2d4044 cmp r3, #0 */
/* @0x2d4048 beq 0x2d40b8 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x338> */
/* @0x2d404c vadd.f32 s18, s19, s18 */
/* @0x2d4050 ldrb r3, [r6, #0x14] */
/* @0x2d4054 vcmpe.f32 s18, #0 */
/* @0x2d4058 vmrs APSR_nzcv, fpscr */
/* @0x2d405c vmovgt.f32 s19, #1.000000e+00 */
/* @0x2d4060 vdivgt.f32 s18, s19, s18 */
/* @0x2d4064 cmp r3, #0 */
/* @0x2d4068 vstr s18, [r4, #208] */
/* @0x2d406c bne 0x2d40d0 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x350> */
/* @0x2d4070 mov r3, #0 */
/* @0x2d4074 str r3, [r4, #0x6c] */
/* @0x2d4078 str r3, [r4, #0x74] */
/* @0x2d407c str r3, [r4, #0x70] */
/* @0x2d4080 ldr r3, [r4, #0x84] */
/* @0x2d4084 ldr r2, [r4, #0x88] */
/* @0x2d4088 add r3, r3, r3, lsl #1 */
/* @0x2d408c add r2, r2, r2, lsl #1 */
/* @0x2d4090 add r3, r5, r3, lsl #2 */
/* @0x2d4094 vstr s27, [r3] */
/* @0x2d4098 vstr s26, [r3, #4] */
/* @0x2d409c vstr s25, [r3, #8] */
/* @0x2d40a0 add r5, r5, r2, lsl #2 */
/* @0x2d40a4 vstr s24, [r5] */
/* @0x2d40a8 vstr s23, [r5, #4] */
/* @0x2d40ac vstr s22, [r5, #8] */
/* @0x2d40b0 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d40b4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2d40b8 mov r3, #0 */
/* @0x2d40bc str r3, [r4, #0xd0] */
/* @0x2d40c0 str r3, [r4, #0x70] */
/* @0x2d40c4 ldrb r3, [r6, #0x14] */
/* @0x2d40c8 cmp r3, #0 */
/* @0x2d40cc beq 0x2d4070 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x2f0> */
/* @0x2d40d0 vldr s11, [r6, #8] */
/* @0x2d40d4 vldr s14, [r4, #116] */
/* @0x2d40d8 vmul.f32 s14, s11, s14 */
/* @0x2d40dc vldr s15, [r4, #108] */
/* @0x2d40e0 vldr s10, [r4, #188] */
/* @0x2d40e4 vldr s12, [r4, #192] */
/* @0x2d40e8 vldr s13, [r4, #172] */
/* @0x2d40ec vldr s0, [r4, #176] */
/* @0x2d40f0 vldr s1, [r4, #196] */
/* @0x2d40f4 vldr s2, [r4, #200] */
/* @0x2d40f8 vldr s3, [r4, #112] */
/* @0x2d40fc vldr s4, [r4, #180] */
/* @0x2d4100 vldr s5, [r4, #184] */
/* @0x2d4104 vldr s8, [r4, #156] */
/* @0x2d4108 vldr s9, [r4, #160] */
/* @0x2d410c vldr s6, [r4, #164] */
/* @0x2d4110 vldr s7, [r4, #168] */
/* @0x2d4114 vmul.f32 s15, s11, s15 */
/* @0x2d4118 vstr s14, [r4, #116] */
/* @0x2d411c vmul.f32 s10, s14, s10 */
/* @0x2d4120 vstr s15, [r4, #108] */
/* @0x2d4124 vmul.f32 s12, s14, s12 */
/* @0x2d4128 vmul.f32 s13, s14, s13 */
/* @0x2d412c vmul.f32 s14, s14, s0 */
/* @0x2d4130 vmla.f32 s10, s15, s1 */
/* @0x2d4134 vmla.f32 s12, s15, s2 */
/* @0x2d4138 vmul.f32 s11, s11, s3 */
/* @0x2d413c vmla.f32 s13, s15, s4 */
/* @0x2d4140 vstr s11, [r4, #112] */
/* @0x2d4144 vmla.f32 s14, s15, s5 */
/* @0x2d4148 vadd.f32 s10, s11, s10 */
/* @0x2d414c vadd.f32 s12, s11, s12 */
/* @0x2d4150 vmls.f32 s25, s10, s6 */
/* @0x2d4154 vmla.f32 s22, s12, s7 */
/* @0x2d4158 vmls.f32 s27, s8, s13 */
/* @0x2d415c vmls.f32 s26, s8, s14 */
/* @0x2d4160 vmla.f32 s24, s9, s13 */
/* @0x2d4164 vmla.f32 s23, s9, s14 */
/* @0x2d4168 b 0x2d4080 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x300> */
/* @0x2d416c ldrdmi r0, r1, [r9], #251 */

/* ── FUNC 0x2d4170 · b2WheelJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&) · size=164 · insn=41 */
/* @0x2d4170 vldr s15, [r1, #16] */
/* @0x2d4174 vldr s12, [r3, #4] */
/* @0x2d4178 vsub.f32 s12, s12, s15 */
/* @0x2d417c vldr s13, [r1, #20] */
/* @0x2d4180 vldr s15, [r1, #24] */
/* @0x2d4184 vldr s10, [r1, #12] */
/* @0x2d4188 vldr s7, [r3] */
/* @0x2d418c vldr s9, [r2, #20] */
/* @0x2d4190 vldr s8, [r2, #24] */
/* @0x2d4194 vldr s14, [r2, #16] */
/* @0x2d4198 vldr s6, [r2, #12] */
/* @0x2d419c ldr r12, [sp] */
/* @0x2d41a0 str r1, [r0, #0x8] */
/* @0x2d41a4 str r2, [r0, #0xc] */
/* @0x2d41a8 vmul.f32 s11, s12, s13 */
/* @0x2d41ac vmul.f32 s12, s12, s15 */
/* @0x2d41b0 vsub.f32 s7, s7, s10 */
/* @0x2d41b4 vneg.f32 s10, s13 */
/* @0x2d41b8 vmla.f32 s11, s7, s15 */
/* @0x2d41bc vmla.f32 s12, s7, s10 */
/* @0x2d41c0 vstr s11, [r0, #20] */
/* @0x2d41c4 vstr s12, [r0, #24] */
/* @0x2d41c8 vldr s12, [r3, #4] */
/* @0x2d41cc vsub.f32 s14, s12, s14 */
/* @0x2d41d0 vldr s11, [r3] */
/* @0x2d41d4 vmul.f32 s12, s14, s9 */
/* @0x2d41d8 vmul.f32 s14, s14, s8 */
/* @0x2d41dc vsub.f32 s11, s11, s6 */
/* @0x2d41e0 vmla.f32 s12, s11, s8 */
/* @0x2d41e4 vmls.f32 s14, s9, s11 */
/* @0x2d41e8 vstr s12, [r0, #28] */
/* @0x2d41ec vstr s14, [r0, #32] */
/* @0x2d41f0 vldr s14, [r12, #4] */
/* @0x2d41f4 vmul.f32 s13, s13, s14 */
/* @0x2d41f8 vldr s12, [r12] */
/* @0x2d41fc vmul.f32 s14, s15, s14 */
/* @0x2d4200 vmla.f32 s13, s15, s12 */
/* @0x2d4204 vmla.f32 s14, s10, s12 */
/* @0x2d4208 vstr s13, [r0, #36] */
/* @0x2d420c vstr s14, [r0, #40] */
/* @0x2d4210 bx lr */

/* ── FUNC 0x2d4214 · b2WheelJoint::b2WheelJoint(b2WheelJointDef const*) · size=204 · insn=51 */
/* @0x2d4214 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2d4218 mov r4, r0 */
/* @0x2d421c mov r5, r1 */
/* @0x2d4220 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2d4224 add r3, r5, #20 */
/* @0x2d4228 ldr r2, [pc, #0xac] */
/* @0x2d422c add r6, r5, #28 */
/* @0x2d4230 add r12, r4, #84 */
/* @0x2d4234 ldm r3, {r0, r1} */
/* @0x2d4238 ldr r2, [pc, r2] */
/* @0x2d423c mov r3, r4 */
/* @0x2d4240 add r2, r2, #8 */
/* @0x2d4244 str r2, [r3], #76 */
/* @0x2d4248 add r2, r4, #92 */
/* @0x2d424c stm r3, {r0, r1} */
/* @0x2d4250 add r3, r5, #36 */
/* @0x2d4254 ldm r6, {r0, r1} */
/* @0x2d4258 ldr r9, [r5, #0x30] */
/* @0x2d425c ldrb r6, [r5, #0x2c] */
/* @0x2d4260 ldr r8, [r5, #0x34] */
/* @0x2d4264 ldr r7, [r5, #0x38] */
/* @0x2d4268 stm r12, {r0, r1} */
/* @0x2d426c ldm r3, {r0, r1} */
/* @0x2d4270 mov r3, #0 */
/* @0x2d4274 ldr r12, [r5, #0x3c] */
/* @0x2d4278 stm r2, {r0, r1} */
/* @0x2d427c vldr s15, [r4, #96] */
/* @0x2d4280 vneg.f32 s15, s15 */
/* @0x2d4284 ldr r2, [r4, #0x5c] */
/* @0x2d4288 str r9, [r4, #0x78] */
/* @0x2d428c mov r0, r4 */
/* @0x2d4290 str r8, [r4, #0x7c] */
/* @0x2d4294 str r2, [r4, #0x68] */
/* @0x2d4298 strb r6, [r4, #0x80] */
/* @0x2d429c vstr s15, [r4, #100] */
/* @0x2d42a0 str r7, [r4, #0x44] */
/* @0x2d42a4 str r3, [r4, #0xcc] */
/* @0x2d42a8 str r3, [r4, #0x6c] */
/* @0x2d42ac str r3, [r4, #0xd0] */
/* @0x2d42b0 str r3, [r4, #0x70] */
/* @0x2d42b4 str r3, [r4, #0xd4] */
/* @0x2d42b8 str r3, [r4, #0x74] */
/* @0x2d42bc str r12, [r4, #0x48] */
/* @0x2d42c0 str r3, [r4, #0xd8] */
/* @0x2d42c4 str r3, [r4, #0xdc] */
/* @0x2d42c8 str r3, [r4, #0xac] */
/* @0x2d42cc str r3, [r4, #0xb0] */
/* @0x2d42d0 str r3, [r4, #0xb4] */
/* @0x2d42d4 str r3, [r4, #0xb8] */
/* @0x2d42d8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d42dc andseq sp, r1, r4, asr #18 */

/* ── FUNC 0x2d4214 · b2WheelJoint::b2WheelJoint(b2WheelJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d42e0 · b2WheelJoint::GetJointTranslation() const · size=160 · insn=40 */
/* @0x2d42e0 ldr r3, [r0, #0x30] */
/* @0x2d42e4 vldr s11, [r0, #80] */
/* @0x2d42e8 ldr r2, [r0, #0x34] */
/* @0x2d42ec vldr s15, [r3, #24] */
/* @0x2d42f0 vldr s10, [r0, #88] */
/* @0x2d42f4 vmul.f32 s8, s15, s11 */
/* @0x2d42f8 vldr s5, [r2, #24] */
/* @0x2d42fc vldr s14, [r3, #20] */
/* @0x2d4300 vldr s4, [r0, #76] */
/* @0x2d4304 vldr s6, [r0, #84] */
/* @0x2d4308 vldr s3, [r2, #20] */
/* @0x2d430c vldr s13, [r0, #96] */
/* @0x2d4310 vldr s7, [r0, #92] */
/* @0x2d4314 vpush {d8} */
/* @0x2d4318 vldr s0, [r2, #16] */
/* @0x2d431c vldr s16, [r3, #16] */
/* @0x2d4320 vldr s1, [r2, #12] */
/* @0x2d4324 vldr s2, [r3, #12] */
/* @0x2d4328 vmul.f32 s9, s5, s10 */
/* @0x2d432c vmul.f32 s11, s14, s11 */
/* @0x2d4330 vmla.f32 s8, s4, s14 */
/* @0x2d4334 vmul.f32 s10, s3, s10 */
/* @0x2d4338 vmla.f32 s9, s6, s3 */
/* @0x2d433c vmul.f32 s12, s15, s13 */
/* @0x2d4340 vnmls.f32 s11, s15, s4 */
/* @0x2d4344 vnmls.f32 s10, s5, s6 */
/* @0x2d4348 vmul.f32 s13, s14, s13 */
/* @0x2d434c vmla.f32 s12, s14, s7 */
/* @0x2d4350 vadd.f32 s8, s8, s16 */
/* @0x2d4354 vpop {d8} */
/* @0x2d4358 vadd.f32 s9, s9, s0 */
/* @0x2d435c vsub.f32 s9, s9, s8 */
/* @0x2d4360 vnmls.f32 s13, s15, s7 */
/* @0x2d4364 vadd.f32 s10, s10, s1 */
/* @0x2d4368 vadd.f32 s11, s11, s2 */
/* @0x2d436c vmul.f32 s12, s9, s12 */
/* @0x2d4370 vsub.f32 s11, s10, s11 */
/* @0x2d4374 vmla.f32 s12, s11, s13 */
/* @0x2d4378 vmov r0, s12 */
/* @0x2d437c bx lr */

/* ── FUNC 0x2d4380 · b2WheelJoint::GetJointSpeed() const · size=28 · insn=7 */
/* @0x2d4380 ldr r3, [r0, #0x34] */
/* @0x2d4384 vldr s14, [r3, #88] */
/* @0x2d4388 ldr r3, [r0, #0x30] */
/* @0x2d438c vldr s15, [r3, #88] */
/* @0x2d4390 vsub.f32 s15, s14, s15 */
/* @0x2d4394 vmov r0, s15 */
/* @0x2d4398 bx lr */

/* ── FUNC 0x2d439c · b2WheelJoint::IsMotorEnabled() const · size=8 · insn=2 */
/* @0x2d439c ldrb r0, [r0, #0x80] */
/* @0x2d43a0 bx lr */

/* ── FUNC 0x2d43a4 · b2WheelJoint::EnableMotor(bool) · size=64 · insn=16 */
/* @0x2d43a4 ldr r3, [r0, #0x30] */
/* @0x2d43a8 ldrh r2, [r3, #4] */
/* @0x2d43ac tst r2, #2 */
/* @0x2d43b0 orreq r2, r2, #2 */
/* @0x2d43b4 strheq r2, [r3, #4] */
/* @0x2d43b8 moveq r12, #0 */
/* @0x2d43bc streq r12, [r3, #0xa0] */
/* @0x2d43c0 ldr r3, [r0, #0x34] */
/* @0x2d43c4 ldrh r2, [r3, #4] */
/* @0x2d43c8 tst r2, #2 */
/* @0x2d43cc orreq r2, r2, #2 */
/* @0x2d43d0 strheq r2, [r3, #4] */
/* @0x2d43d4 moveq r12, #0 */
/* @0x2d43d8 streq r12, [r3, #0xa0] */
/* @0x2d43dc strb r1, [r0, #0x80] */
/* @0x2d43e0 bx lr */

/* ── FUNC 0x2d43e4 · b2WheelJoint::SetMotorSpeed(float) · size=64 · insn=16 */
/* @0x2d43e4 ldr r3, [r0, #0x30] */
/* @0x2d43e8 ldrh r2, [r3, #4] */
/* @0x2d43ec tst r2, #2 */
/* @0x2d43f0 orreq r2, r2, #2 */
/* @0x2d43f4 strheq r2, [r3, #4] */
/* @0x2d43f8 moveq r12, #0 */
/* @0x2d43fc streq r12, [r3, #0xa0] */
/* @0x2d4400 ldr r3, [r0, #0x34] */
/* @0x2d4404 ldrh r2, [r3, #4] */
/* @0x2d4408 tst r2, #2 */
/* @0x2d440c orreq r2, r2, #2 */
/* @0x2d4410 strheq r2, [r3, #4] */
/* @0x2d4414 moveq r12, #0 */
/* @0x2d4418 streq r12, [r3, #0xa0] */
/* @0x2d441c str r1, [r0, #0x7c] */
/* @0x2d4420 bx lr */

/* ── FUNC 0x2d4424 · b2WheelJoint::SetMaxMotorTorque(float) · size=64 · insn=16 */
/* @0x2d4424 ldr r3, [r0, #0x30] */
/* @0x2d4428 ldrh r2, [r3, #4] */
/* @0x2d442c tst r2, #2 */
/* @0x2d4430 orreq r2, r2, #2 */
/* @0x2d4434 strheq r2, [r3, #4] */
/* @0x2d4438 moveq r12, #0 */
/* @0x2d443c streq r12, [r3, #0xa0] */
/* @0x2d4440 ldr r3, [r0, #0x34] */
/* @0x2d4444 ldrh r2, [r3, #4] */
/* @0x2d4448 tst r2, #2 */
/* @0x2d444c orreq r2, r2, #2 */
/* @0x2d4450 strheq r2, [r3, #4] */
/* @0x2d4454 moveq r12, #0 */
/* @0x2d4458 streq r12, [r3, #0xa0] */
/* @0x2d445c str r1, [r0, #0x78] */
/* @0x2d4460 bx lr */

/* ── FUNC 0x2d4464 · b2WheelJoint::GetMotorTorque(float) const · size=20 · insn=5 */
/* @0x2d4464 vmov s14, r1 */
/* @0x2d4468 vldr s15, [r0, #112] */
/* @0x2d446c vmul.f32 s14, s14, s15 */
/* @0x2d4470 vmov r0, s14 */
/* @0x2d4474 bx lr */

/* ── FUNC 0x2d4478 · b2ParticleColor::b2ParticleColor(b2Color const&) · size=80 · insn=20 */
/* @0x2d4478 vldr s14, [r1] */
/* @0x2d447c vldr s15, [pc, #64] */
/* @0x2d4480 vmul.f32 s14, s14, s15 */
/* @0x2d4484 mvn r2, #0 */
/* @0x2d4488 vcvt.s32.f32 s14, s14 */
/* @0x2d448c vmov r12, s14 */
/* @0x2d4490 strb r12, [r0] */
/* @0x2d4494 vldr s14, [r1, #4] */
/* @0x2d4498 vmul.f32 s14, s14, s15 */
/* @0x2d449c vcvt.s32.f32 s14, s14 */
/* @0x2d44a0 vmov r12, s14 */
/* @0x2d44a4 strb r12, [r0, #0x1] */
/* @0x2d44a8 vldr s14, [r1, #8] */
/* @0x2d44ac vmul.f32 s15, s14, s15 */
/* @0x2d44b0 strb r2, [r0, #0x3] */
/* @0x2d44b4 vcvt.s32.f32 s15, s15 */
/* @0x2d44b8 vmov r2, s15 */
/* @0x2d44bc strb r2, [r0, #0x2] */
/* @0x2d44c0 bx lr */
/* @0x2d44c4 cmnmi pc, #0 */

/* ── FUNC 0x2d4478 · b2ParticleColor::b2ParticleColor(b2Color const&) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d44c8 · b2ParticleColor::GetColor() const · size=72 · insn=18 */
/* @0x2d44c8 ldrb r2, [r1, #0x1] */
/* @0x2d44cc vldr s15, [pc, #56] */
/* @0x2d44d0 vmov s12, r2 */
/* @0x2d44d4 ldrb r2, [r1] */
/* @0x2d44d8 ldrb r1, [r1, #0x2] */
/* @0x2d44dc vcvt.f32.s32 s12, s12 */
/* @0x2d44e0 vmov s14, r2 */
/* @0x2d44e4 vmov s13, r1 */
/* @0x2d44e8 vcvt.f32.s32 s14, s14 */
/* @0x2d44ec vcvt.f32.s32 s13, s13 */
/* @0x2d44f0 vmul.f32 s12, s12, s15 */
/* @0x2d44f4 vmul.f32 s14, s14, s15 */
/* @0x2d44f8 vstr s12, [r0, #4] */
/* @0x2d44fc vmul.f32 s15, s13, s15 */
/* @0x2d4500 vstr s14, [r0] */
/* @0x2d4504 vstr s15, [r0, #8] */
/* @0x2d4508 bx lr */
/* @0x2d450c bllo 0xfe2f4718 <b2_toiTime+0xfffffffffdb9b274> */

/* ── FUNC 0x2d4510 · b2ParticleColor::Set(b2Color const&) · size=80 · insn=20 */
/* @0x2d4510 vldr s14, [r1] */
/* @0x2d4514 vldr s15, [pc, #64] */
/* @0x2d4518 vmul.f32 s14, s14, s15 */
/* @0x2d451c mvn r3, #0 */
/* @0x2d4520 vcvt.s32.f32 s14, s14 */
/* @0x2d4524 vmov r2, s14 */
/* @0x2d4528 strb r2, [r0] */
/* @0x2d452c vldr s14, [r1, #4] */
/* @0x2d4530 vmul.f32 s14, s14, s15 */
/* @0x2d4534 vcvt.s32.f32 s14, s14 */
/* @0x2d4538 vmov r2, s14 */
/* @0x2d453c strb r2, [r0, #0x1] */
/* @0x2d4540 vldr s14, [r1, #8] */
/* @0x2d4544 vmul.f32 s15, s14, s15 */
/* @0x2d4548 strb r3, [r0, #0x3] */
/* @0x2d454c vcvt.s32.f32 s15, s15 */
/* @0x2d4550 vmov r3, s15 */
/* @0x2d4554 strb r3, [r0, #0x2] */
/* @0x2d4558 bx lr */
/* @0x2d455c cmnmi pc, #0 */

/* ── FUNC 0x2d4560 · b2ParticleGroup::b2ParticleGroup() · size=152 · insn=38 */
/* @0x2d4560 ldr r12, [pc, #0x8c] */
/* @0x2d4564 mov r3, r0 */
/* @0x2d4568 push {r4, r5, r6, r7, r8} */
/* @0x2d456c ldr r12, [pc, r12] */
/* @0x2d4570 ldrb r5, [r0, #0x4c] */
/* @0x2d4574 add r7, r0, #40 */
/* @0x2d4578 ldm r12, {r0, r1} */
/* @0x2d457c mvn r6, #0 */
/* @0x2d4580 orr r5, r5, #1 */
/* @0x2d4584 str r6, [r3, #0x1c] */
/* @0x2d4588 add r6, r3, #48 */
/* @0x2d458c and r5, r5, #253 */
/* @0x2d4590 mov r2, #0 */
/* @0x2d4594 mov r4, #0 */
/* @0x2d4598 mov r8, #1065353216 */
/* @0x2d459c str r4, [r3, #0x20] */
/* @0x2d45a0 str r4, [r3, #0x24] */
/* @0x2d45a4 bfi r5, r2, #2, #1 */
/* @0x2d45a8 str r8, [r3, #0x10] */
/* @0x2d45ac str r2, [r3] */
/* @0x2d45b0 str r2, [r3, #0x4] */
/* @0x2d45b4 str r2, [r3, #0x8] */
/* @0x2d45b8 str r2, [r3, #0xc] */
/* @0x2d45bc str r2, [r3, #0x14] */
/* @0x2d45c0 str r2, [r3, #0x18] */
/* @0x2d45c4 stm r7, {r0, r1} */
/* @0x2d45c8 stm r6, {r0, r1} */
/* @0x2d45cc mov r0, r3 */
/* @0x2d45d0 str r4, [r3, #0x38] */
/* @0x2d45d4 strb r5, [r3, #0x4c] */
/* @0x2d45d8 str r4, [r3, #0x3c] */
/* @0x2d45dc str r4, [r3, #0x40] */
/* @0x2d45e0 str r4, [r3, #0x44] */
/* @0x2d45e4 str r8, [r3, #0x48] */
/* @0x2d45e8 str r2, [r3, #0x50] */
/* @0x2d45ec pop {r4, r5, r6, r7, r8} */
/* @0x2d45f0 bx lr */
/* @0x2d45f4 andseq r12, r1, r12, ror #30 */
