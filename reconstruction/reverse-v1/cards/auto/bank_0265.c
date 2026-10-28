/* libyoyo.so 覆盖卡组 0265
 * 函数 0x2c3234..0x2c4e74，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2c3234 · GifFreeSavedImages(GifFileType*) · size=148 · insn=37 */
/* @0x2c3234 push {r4, r5, r6, lr} */
/* @0x2c3238 subs r5, r0, #0 */
/* @0x2c323c popeq {r4, r5, r6, pc} */
/* @0x2c3240 ldr r4, [r5, #0x34] */
/* @0x2c3244 cmp r4, #0 */
/* @0x2c3248 popeq {r4, r5, r6, pc} */
/* @0x2c324c ldr r3, [r5, #0x18] */
/* @0x2c3250 add r3, r3, r3, lsl #3 */
/* @0x2c3254 add r3, r4, r3, lsl #2 */
/* @0x2c3258 cmp r4, r3 */
/* @0x2c325c bhs 0x2c32c0 <_Z18GifFreeSavedImagesP11GifFileType+0x8c> */
/* @0x2c3260 mov r6, #0 */
/* @0x2c3264 ldr r0, [r4, #0x14] */
/* @0x2c3268 cmp r0, #0 */
/* @0x2c326c beq 0x2c3278 <_Z18GifFreeSavedImagesP11GifFileType+0x44> */
/* @0x2c3270 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject> */
/* @0x2c3274 str r6, [r4, #0x14] */
/* @0x2c3278 ldr r0, [r4, #0x18] */
/* @0x2c327c cmp r0, #0 */
/* @0x2c3280 beq 0x2c3288 <_Z18GifFreeSavedImagesP11GifFileType+0x54> */
/* @0x2c3284 bl 0xb655c <free@plt> */
/* @0x2c3288 add r0, r4, #28 */
/* @0x2c328c add r1, r4, #32 */
/* @0x2c3290 bl 0x2c2ff8 <_Z17GifFreeExtensionsPiPP14ExtensionBlock> */
/* @0x2c3294 ldr r3, [r5, #0x18] */
/* @0x2c3298 ldr r0, [r5, #0x34] */
/* @0x2c329c add r4, r4, #36 */
/* @0x2c32a0 add r3, r3, r3, lsl #3 */
/* @0x2c32a4 add r3, r0, r3, lsl #2 */
/* @0x2c32a8 cmp r4, r3 */
/* @0x2c32ac blo 0x2c3264 <_Z18GifFreeSavedImagesP11GifFileType+0x30> */
/* @0x2c32b0 bl 0xb655c <free@plt> */
/* @0x2c32b4 mov r3, #0 */
/* @0x2c32b8 str r3, [r5, #0x34] */
/* @0x2c32bc pop {r4, r5, r6, pc} */
/* @0x2c32c0 mov r0, r4 */
/* @0x2c32c4 b 0x2c32b0 <_Z18GifFreeSavedImagesP11GifFileType+0x7c> */

/* ── FUNC 0x2c32c8 · b2WorldManifold::Initialize(b2Manifold const*, b2Transform const&, float, b2Transform const&, float) · size=924 · insn=231 */
/* @0x2c32c8 push {r4, lr} */
/* @0x2c32cc vpush {d8, d9, d10} */
/* @0x2c32d0 mov r4, r0 */
/* @0x2c32d4 vldr s17, [sp, #36] */
/* @0x2c32d8 ldr r0, [r1, #0x3c] */
/* @0x2c32dc vmov s16, r3 */
/* @0x2c32e0 ldr r12, [sp, #0x20] */
/* @0x2c32e4 cmp r0, #0 */
/* @0x2c32e8 beq 0x2c3308 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x40> */
/* @0x2c32ec ldr r3, [r1, #0x38] */
/* @0x2c32f0 cmp r3, #1 */
/* @0x2c32f4 beq 0x2c3310 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x48> */
/* @0x2c32f8 cmp r3, #2 */
/* @0x2c32fc beq 0x2c34dc <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x214> */
/* @0x2c3300 cmp r3, #0 */
/* @0x2c3304 beq 0x2c3410 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x148> */
/* @0x2c3308 vpop {d8, d9, d10} */
/* @0x2c330c pop {r4, pc} */
/* @0x2c3310 vldr s14, [r2, #12] */
/* @0x2c3314 vldr s15, [r2, #8] */
/* @0x2c3318 vldr s12, [r1, #44] */
/* @0x2c331c vmul.f32 s11, s14, s12 */
/* @0x2c3320 vldr s13, [r1, #40] */
/* @0x2c3324 vldr s6, [r2] */
/* @0x2c3328 vldr s9, [r2, #4] */
/* @0x2c332c cmp r0, #0 */
/* @0x2c3330 vmul.f32 s12, s15, s12 */
/* @0x2c3334 vmla.f32 s11, s13, s15 */
/* @0x2c3338 vnmls.f32 s12, s14, s13 */
/* @0x2c333c vstr s11, [r4, #4] */
/* @0x2c3340 vstr s12, [r4] */
/* @0x2c3344 vldr s5, [r1, #52] */
/* @0x2c3348 vmul.f32 s13, s15, s5 */
/* @0x2c334c vldr s10, [r1, #48] */
/* @0x2c3350 vmul.f32 s5, s14, s5 */
/* @0x2c3354 vnmls.f32 s13, s14, s10 */
/* @0x2c3358 vmla.f32 s5, s15, s10 */
/* @0x2c335c vadd.f32 s6, s13, s6 */
/* @0x2c3360 vadd.f32 s5, s5, s9 */
/* @0x2c3364 ble 0x2c3308 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x40> */
/* @0x2c3368 add r3, r4, #8 */
/* @0x2c336c mov r2, #0 */
/* @0x2c3370 vldr s8, [r12, #12] */
/* @0x2c3374 vldr s9, [r12, #8] */
/* @0x2c3378 vldr s3, [r12] */
/* @0x2c337c vldr s4, [r12, #4] */
/* @0x2c3380 vmov.f32 s10, #5.000000e-01 */
/* @0x2c3384 b 0x2c3390 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0xc8> */
/* @0x2c3388 vldr s12, [r4] */
/* @0x2c338c vldr s11, [r4, #4] */
/* @0x2c3390 vldr s14, [r1, #4] */
/* @0x2c3394 vmul.f32 s15, s14, s8 */
/* @0x2c3398 vldr s13, [r1] */
/* @0x2c339c add r2, r2, #1 */
/* @0x2c33a0 cmp r2, r0 */
/* @0x2c33a4 add r1, r1, #20 */
/* @0x2c33a8 add r3, r3, #8 */
/* @0x2c33ac vmla.f32 s15, s13, s9 */
/* @0x2c33b0 vmul.f32 s14, s14, s9 */
/* @0x2c33b4 vnmls.f32 s14, s13, s8 */
/* @0x2c33b8 vadd.f32 s15, s15, s4 */
/* @0x2c33bc vsub.f32 s13, s15, s5 */
/* @0x2c33c0 vadd.f32 s14, s14, s3 */
/* @0x2c33c4 vmul.f32 s13, s13, s11 */
/* @0x2c33c8 vsub.f32 s7, s14, s6 */
/* @0x2c33cc vmla.f32 s13, s7, s12 */
/* @0x2c33d0 vsub.f32 s13, s16, s13 */
/* @0x2c33d4 vmov.f32 s7, s14 */
/* @0x2c33d8 vmla.f32 s14, s13, s12 */
/* @0x2c33dc vmls.f32 s7, s17, s12 */
/* @0x2c33e0 vmov.f32 s12, s15 */
/* @0x2c33e4 vmls.f32 s15, s17, s11 */
/* @0x2c33e8 vmla.f32 s12, s13, s11 */
/* @0x2c33ec vadd.f32 s14, s14, s7 */
/* @0x2c33f0 vadd.f32 s15, s12, s15 */
/* @0x2c33f4 vmul.f32 s14, s14, s10 */
/* @0x2c33f8 vmul.f32 s15, s15, s10 */
/* @0x2c33fc vstr s14, [r3, #-8] */
/* @0x2c3400 vstr s15, [r3, #-4] */
/* @0x2c3404 bne 0x2c3388 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0xc0> */
/* @0x2c3408 vpop {d8, d9, d10} */
/* @0x2c340c pop {r4, pc} */
/* @0x2c3410 vldr s8, [r2, #12] */
/* @0x2c3414 vldr s10, [r12, #12] */
/* @0x2c3418 vldr s4, [pc, #568] */
/* @0x2c341c vstr s4, [r4, #4] */
/* @0x2c3420 vldr s13, [r1, #52] */
/* @0x2c3424 vldr s7, [r1, #4] */
/* @0x2c3428 vmul.f32 s12, s8, s13 */
/* @0x2c342c vldr s6, [r2, #8] */
/* @0x2c3430 vldr s14, [r12, #8] */
/* @0x2c3434 vldr s19, [r2, #4] */
/* @0x2c3438 vldr s18, [r12, #4] */
/* @0x2c343c vldr s3, [pc, #536] */
/* @0x2c3440 vmul.f32 s15, s10, s7 */
/* @0x2c3444 vmov.f32 s5, #1.000000e+00 */
/* @0x2c3448 vmul.f32 s13, s6, s13 */
/* @0x2c344c vstr s5, [r4] */
/* @0x2c3450 vldr s9, [r1, #48] */
/* @0x2c3454 vldr s11, [r1] */
/* @0x2c3458 vldr s21, [r2] */
/* @0x2c345c vldr s20, [r12] */
/* @0x2c3460 vmla.f32 s15, s11, s14 */
/* @0x2c3464 vmla.f32 s12, s9, s6 */
/* @0x2c3468 vmul.f32 s14, s14, s7 */
/* @0x2c346c vnmls.f32 s13, s8, s9 */
/* @0x2c3470 vnmls.f32 s14, s10, s11 */
/* @0x2c3474 vadd.f32 s19, s12, s19 */
/* @0x2c3478 vadd.f32 s18, s15, s18 */
/* @0x2c347c vsub.f32 s15, s19, s18 */
/* @0x2c3480 vadd.f32 s21, s13, s21 */
/* @0x2c3484 vadd.f32 s20, s14, s20 */
/* @0x2c3488 vmul.f32 s15, s15, s15 */
/* @0x2c348c vsub.f32 s14, s21, s20 */
/* @0x2c3490 vmla.f32 s15, s14, s14 */
/* @0x2c3494 vcmpe.f32 s15, s3 */
/* @0x2c3498 vmrs APSR_nzcv, fpscr */
/* @0x2c349c vmovle.f32 s15, s4 */
/* @0x2c34a0 vmovle.f32 s14, s5 */
/* @0x2c34a4 bgt 0x2c35e8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x320> */
/* @0x2c34a8 vmla.f32 s21, s16, s14 */
/* @0x2c34ac vmls.f32 s20, s17, s14 */
/* @0x2c34b0 vmla.f32 s19, s16, s15 */
/* @0x2c34b4 vmls.f32 s18, s17, s15 */
/* @0x2c34b8 vadd.f32 s20, s21, s20 */
/* @0x2c34bc vmov.f32 s11, #5.000000e-01 */
/* @0x2c34c0 vadd.f32 s18, s19, s18 */
/* @0x2c34c4 vmul.f32 s20, s20, s11 */
/* @0x2c34c8 vmul.f32 s11, s18, s11 */
/* @0x2c34cc vstr s20, [r4, #8] */
/* @0x2c34d0 vpop {d8, d9, d10} */
/* @0x2c34d4 vstr s11, [r4, #12] */
/* @0x2c34d8 pop {r4, pc} */
/* @0x2c34dc vldr s14, [r12, #12] */
/* @0x2c34e0 vldr s15, [r12, #8] */
/* @0x2c34e4 vldr s12, [r1, #44] */
/* @0x2c34e8 vmul.f32 s11, s14, s12 */
/* @0x2c34ec vldr s13, [r1, #40] */
/* @0x2c34f0 vldr s6, [r12] */
/* @0x2c34f4 vldr s9, [r12, #4] */
/* @0x2c34f8 cmp r0, #0 */
/* @0x2c34fc vmul.f32 s12, s15, s12 */
/* @0x2c3500 vmla.f32 s11, s13, s15 */
/* @0x2c3504 vnmls.f32 s12, s14, s13 */
/* @0x2c3508 vstr s11, [r4, #4] */
/* @0x2c350c vstr s12, [r4] */
/* @0x2c3510 vldr s5, [r1, #52] */
/* @0x2c3514 vmul.f32 s13, s15, s5 */
/* @0x2c3518 vldr s10, [r1, #48] */
/* @0x2c351c vmul.f32 s5, s14, s5 */
/* @0x2c3520 vnmls.f32 s13, s14, s10 */
/* @0x2c3524 vmla.f32 s5, s15, s10 */
/* @0x2c3528 vadd.f32 s6, s13, s6 */
/* @0x2c352c vadd.f32 s5, s5, s9 */
/* @0x2c3530 ble 0x2c35d0 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x308> */
/* @0x2c3534 add r3, r4, #8 */
/* @0x2c3538 mov r12, #0 */
/* @0x2c353c vldr s8, [r2, #12] */
/* @0x2c3540 vldr s9, [r2, #8] */
/* @0x2c3544 vldr s3, [r2] */
/* @0x2c3548 vldr s4, [r2, #4] */
/* @0x2c354c vmov.f32 s10, #5.000000e-01 */
/* @0x2c3550 vldr s14, [r1, #4] */
/* @0x2c3554 vldr s13, [r1] */
/* @0x2c3558 add r12, r12, #1 */
/* @0x2c355c add r1, r1, #20 */
/* @0x2c3560 cmp r12, r0 */
/* @0x2c3564 add r3, r3, #8 */
/* @0x2c3568 vmul.f32 s15, s14, s8 */
/* @0x2c356c vmul.f32 s14, s14, s9 */
/* @0x2c3570 vmla.f32 s15, s13, s9 */
/* @0x2c3574 vnmls.f32 s14, s13, s8 */
/* @0x2c3578 vadd.f32 s15, s15, s4 */
/* @0x2c357c vsub.f32 s13, s15, s5 */
/* @0x2c3580 vadd.f32 s14, s14, s3 */
/* @0x2c3584 vmul.f32 s13, s13, s11 */
/* @0x2c3588 vsub.f32 s7, s14, s6 */
/* @0x2c358c vmla.f32 s13, s7, s12 */
/* @0x2c3590 vsub.f32 s13, s17, s13 */
/* @0x2c3594 vmov.f32 s7, s14 */
/* @0x2c3598 vmla.f32 s14, s13, s12 */
/* @0x2c359c vmls.f32 s7, s16, s12 */
/* @0x2c35a0 vmov.f32 s12, s15 */
/* @0x2c35a4 vmls.f32 s15, s16, s11 */
/* @0x2c35a8 vmla.f32 s12, s13, s11 */
/* @0x2c35ac vadd.f32 s14, s14, s7 */
/* @0x2c35b0 vadd.f32 s15, s12, s15 */
/* @0x2c35b4 vmul.f32 s14, s14, s10 */
/* @0x2c35b8 vmul.f32 s15, s15, s10 */
/* @0x2c35bc vstr s14, [r3, #-8] */
/* @0x2c35c0 vstr s15, [r3, #-4] */
/* @0x2c35c4 vldr s12, [r4] */
/* @0x2c35c8 vldr s11, [r4, #4] */
/* @0x2c35cc bne 0x2c3550 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x288> */
/* @0x2c35d0 vpop {d8, d9, d10} */
/* @0x2c35d4 vneg.f32 s12, s12 */
/* @0x2c35d8 vneg.f32 s11, s11 */
/* @0x2c35dc vstr s12, [r4] */
/* @0x2c35e0 vstr s11, [r4, #4] */
/* @0x2c35e4 pop {r4, pc} */
/* @0x2c35e8 vsub.f32 s14, s18, s19 */
/* @0x2c35ec vmul.f32 s15, s14, s14 */
/* @0x2c35f0 vstr s14, [r4, #4] */
/* @0x2c35f4 vsub.f32 s14, s20, s21 */
/* @0x2c35f8 vmla.f32 s15, s14, s14 */
/* @0x2c35fc vstr s14, [r4] */
/* @0x2c3600 vsqrt.f32 s13, s15 */
/* @0x2c3604 vcmp.f32 s13, s13 */
/* @0x2c3608 vmrs APSR_nzcv, fpscr */
/* @0x2c360c bne 0x2c3648 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x380> */
/* @0x2c3610 vldr s15, [pc, #72] */
/* @0x2c3614 vcmpe.f32 s13, s15 */
/* @0x2c3618 vmrs APSR_nzcv, fpscr */
/* @0x2c361c vmovpl.f32 s12, #1.000000e+00 */
/* @0x2c3620 vldrpl s14, [r4] */
/* @0x2c3624 vldrpl s15, [r4, #4] */
/* @0x2c3628 vldrmi s14, [r4] */
/* @0x2c362c vldrmi s15, [r4, #4] */
/* @0x2c3630 vdivpl.f32 s13, s12, s13 */
/* @0x2c3634 vmulpl.f32 s14, s13, s14 */
/* @0x2c3638 vmulpl.f32 s15, s13, s15 */
/* @0x2c363c vstrpl s14, [r4] */
/* @0x2c3640 vstrpl s15, [r4, #4] */
/* @0x2c3644 b 0x2c34a8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x1e0> */
/* @0x2c3648 vmov r0, s15 */
/* @0x2c364c bl 0xb6700 <sqrtf@plt> */
/* @0x2c3650 vmov s13, r0 */
/* @0x2c3654 b 0x2c3610 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x348> */
/* @0x2c3658 andeq r0, r0, r0 */
/* @0x2c365c .word 0x28800000 */
/* @0x2c3660 strlo r0, [r0], #-0 */

/* ── FUNC 0x2c3664 · b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*) · size=304 · insn=76 */
/* @0x2c3664 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2c3668 mov r12, #0 */
/* @0x2c366c ldr r7, [r2, #0x3c] */
/* @0x2c3670 ldr r8, [r3, #0x3c] */
/* @0x2c3674 cmp r7, r12 */
/* @0x2c3678 str r12, [r0] */
/* @0x2c367c str r12, [r1] */
/* @0x2c3680 str r12, [r0, #0x4] */
/* @0x2c3684 str r12, [r1, #0x4] */
/* @0x2c3688 ble 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78> */
/* @0x2c368c cmp r8, #0 */
/* @0x2c3690 mov r6, r0 */
/* @0x2c3694 mov r4, r2 */
/* @0x2c3698 mov r9, #3 */
/* @0x2c369c mov r10, #2 */
/* @0x2c36a0 ble 0x2c374c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe8> */
/* @0x2c36a4 ldr r5, [r4, #0x10] */
/* @0x2c36a8 add r12, r12, #1 */
/* @0x2c36ac str r9, [r6], #4 */
/* @0x2c36b0 add r4, r4, #20 */
/* @0x2c36b4 ldr r0, [r3, #0x10] */
/* @0x2c36b8 cmp r0, r5 */
/* @0x2c36bc beq 0x2c373c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd8> */
/* @0x2c36c0 cmp r8, #1 */
/* @0x2c36c4 beq 0x2c36d4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x70> */
/* @0x2c36c8 ldr r0, [r3, #0x24] */
/* @0x2c36cc cmp r0, r5 */
/* @0x2c36d0 beq 0x2c373c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd8> */
/* @0x2c36d4 cmp r12, r7 */
/* @0x2c36d8 bne 0x2c36a4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x40> */
/* @0x2c36dc cmp r8, #0 */
/* @0x2c36e0 ble 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0> */
/* @0x2c36e4 cmp r7, #0 */
/* @0x2c36e8 mov r0, r3 */
/* @0x2c36ec mov r5, #1 */
/* @0x2c36f0 mov r3, #0 */
/* @0x2c36f4 mov r6, #2 */
/* @0x2c36f8 ble 0x2c3770 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x10c> */
/* @0x2c36fc ldr r12, [r0, #0x10] */
/* @0x2c3700 add r3, r3, #1 */
/* @0x2c3704 str r5, [r1], #4 */
/* @0x2c3708 add r0, r0, #20 */
/* @0x2c370c ldr r4, [r2, #0x10] */
/* @0x2c3710 cmp r12, r4 */
/* @0x2c3714 beq 0x2c3744 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe0> */
/* @0x2c3718 cmp r7, #1 */
/* @0x2c371c beq 0x2c372c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xc8> */
/* @0x2c3720 ldr r4, [r2, #0x24] */
/* @0x2c3724 cmp r12, r4 */
/* @0x2c3728 beq 0x2c3744 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe0> */
/* @0x2c372c cmp r3, r8 */
/* @0x2c3730 bne 0x2c36fc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x98> */
/* @0x2c3734 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2c3738 bx lr */
/* @0x2c373c str r10, [r6, #-0x4] */
/* @0x2c3740 b 0x2c36d4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x70> */
/* @0x2c3744 str r6, [r1, #-0x4] */
/* @0x2c3748 b 0x2c372c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xc8> */
/* @0x2c374c add r12, r12, #1 */
/* @0x2c3750 str r9, [r6], #4 */
/* @0x2c3754 cmp r12, r7 */
/* @0x2c3758 beq 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78> */
/* @0x2c375c add r12, r12, #1 */
/* @0x2c3760 str r9, [r6], #4 */
/* @0x2c3764 cmp r12, r7 */
/* @0x2c3768 bne 0x2c374c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe8> */
/* @0x2c376c b 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78> */
/* @0x2c3770 add r3, r3, #1 */
/* @0x2c3774 str r5, [r1], #4 */
/* @0x2c3778 cmp r3, r8 */
/* @0x2c377c beq 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0> */
/* @0x2c3780 add r3, r3, #1 */
/* @0x2c3784 str r5, [r1], #4 */
/* @0x2c3788 cmp r3, r8 */
/* @0x2c378c bne 0x2c3770 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x10c> */
/* @0x2c3790 b 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0> */

/* ── FUNC 0x2c3794 · b2AABB::RayCast(b2RayCastOutput*, b2RayCastInput const&) const · size=560 · insn=140 */
/* @0x2c3794 vldr s15, [r2] */
/* @0x2c3798 vldr s14, [r2, #8] */
/* @0x2c379c vsub.f32 s14, s14, s15 */
/* @0x2c37a0 vldr s13, [r2, #12] */
/* @0x2c37a4 vldr s15, [r2, #4] */
/* @0x2c37a8 str r4, [sp, #-0x4]! */
/* @0x2c37ac sub sp, sp, #36 */
/* @0x2c37b0 mov r3, r0 */
/* @0x2c37b4 mov r4, r1 */
/* @0x2c37b8 ldm r2, {r0, r1} */
/* @0x2c37bc stm sp, {r0, r1} */
/* @0x2c37c0 vsub.f32 s15, s13, s15 */
/* @0x2c37c4 vstr s14, [sp, #8] */
/* @0x2c37c8 vldr s13, [pc, #488] */
/* @0x2c37cc vcmpe.f32 s14, #0 */
/* @0x2c37d0 vstr s15, [sp, #12] */
/* @0x2c37d4 vmrs APSR_nzcv, fpscr */
/* @0x2c37d8 vcmpe.f32 s15, #0 */
/* @0x2c37dc vnegle.f32 s14, s14 */
/* @0x2c37e0 vmrs APSR_nzcv, fpscr */
/* @0x2c37e4 vcmpe.f32 s14, s13 */
/* @0x2c37e8 vnegle.f32 s15, s15 */
/* @0x2c37ec vmrs APSR_nzcv, fpscr */
/* @0x2c37f0 vstr s15, [sp, #20] */
/* @0x2c37f4 bmi 0x2c3878 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xe4> */
/* @0x2c37f8 vmov.f32 s11, #1.000000e+00 */
/* @0x2c37fc vldr s13, [sp, #8] */
/* @0x2c3800 vldr s12, [sp] */
/* @0x2c3804 vldr s14, [r3] */
/* @0x2c3808 vldr s15, [r3, #8] */
/* @0x2c380c vdiv.f32 s13, s11, s13 */
/* @0x2c3810 vsub.f32 s14, s14, s12 */
/* @0x2c3814 vsub.f32 s15, s15, s12 */
/* @0x2c3818 vmul.f32 s14, s14, s13 */
/* @0x2c381c vmul.f32 s15, s15, s13 */
/* @0x2c3820 vcmpe.f32 s14, s15 */
/* @0x2c3824 vmrs APSR_nzcv, fpscr */
/* @0x2c3828 ble 0x2c391c <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x188> */
/* @0x2c382c vldr s13, [pc, #392] */
/* @0x2c3830 vcmpe.f32 s15, s13 */
/* @0x2c3834 vmrs APSR_nzcv, fpscr */
/* @0x2c3838 ble 0x2c393c <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x1a8> */
/* @0x2c383c mov r1, #0 */
/* @0x2c3840 vstr s11, [sp, #24] */
/* @0x2c3844 str r1, [sp, #0x1c] */
/* @0x2c3848 vldr s13, [pc, #368] */
/* @0x2c384c vcmp.f32 s14, s13 */
/* @0x2c3850 vmrs APSR_nzcv, fpscr */
/* @0x2c3854 vmovgt.f32 s14, s13 */
/* @0x2c3858 vcmpe.f32 s15, s14 */
/* @0x2c385c vmrs APSR_nzcv, fpscr */
/* @0x2c3860 ble 0x2c38a4 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x110> */
/* @0x2c3864 mov r3, #0 */
/* @0x2c3868 mov r0, r3 */
/* @0x2c386c add sp, sp, #36 */
/* @0x2c3870 ldr r4, [sp], #4 */
/* @0x2c3874 bx lr */
/* @0x2c3878 vldr s15, [sp] */
/* @0x2c387c vldr s14, [r3] */
/* @0x2c3880 vcmpe.f32 s15, s14 */
/* @0x2c3884 vmrs APSR_nzcv, fpscr */
/* @0x2c3888 bmi 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c388c vldr s14, [r3, #8] */
/* @0x2c3890 vcmpe.f32 s15, s14 */
/* @0x2c3894 vmrs APSR_nzcv, fpscr */
/* @0x2c3898 bgt 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c389c vldr s14, [pc, #284] */
/* @0x2c38a0 vldr s15, [pc, #276] */
/* @0x2c38a4 vldr s12, [sp, #20] */
/* @0x2c38a8 vldr s13, [pc, #264] */
/* @0x2c38ac vcmpe.f32 s12, s13 */
/* @0x2c38b0 vmrs APSR_nzcv, fpscr */
/* @0x2c38b4 bpl 0x2c3944 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x1b0> */
/* @0x2c38b8 vldr s14, [sp, #4] */
/* @0x2c38bc vldr s13, [r3, #4] */
/* @0x2c38c0 vcmpe.f32 s14, s13 */
/* @0x2c38c4 vmrs APSR_nzcv, fpscr */
/* @0x2c38c8 bmi 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c38cc vldr s13, [r3, #12] */
/* @0x2c38d0 vcmpe.f32 s14, s13 */
/* @0x2c38d4 vmrs APSR_nzcv, fpscr */
/* @0x2c38d8 bgt 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c38dc vcmpe.f32 s15, #0 */
/* @0x2c38e0 vmrs APSR_nzcv, fpscr */
/* @0x2c38e4 bmi 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c38e8 vldr s14, [r2, #16] */
/* @0x2c38ec vcmpe.f32 s15, s14 */
/* @0x2c38f0 vmrs APSR_nzcv, fpscr */
/* @0x2c38f4 bgt 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c38f8 add r3, sp, #32 */
/* @0x2c38fc vstr s15, [r4, #8] */
/* @0x2c3900 ldmdb r3, {r0, r1} */
/* @0x2c3904 mov r3, #1 */
/* @0x2c3908 stm r4, {r0, r1} */
/* @0x2c390c mov r0, r3 */
/* @0x2c3910 add sp, sp, #36 */
/* @0x2c3914 ldr r4, [sp], #4 */
/* @0x2c3918 bx lr */
/* @0x2c391c vmov.f32 s13, s15 */
/* @0x2c3920 vmov.f32 s15, s14 */
/* @0x2c3924 vmov.f32 s14, s13 */
/* @0x2c3928 vldr s13, [pc, #140] */
/* @0x2c392c vcmpe.f32 s15, s13 */
/* @0x2c3930 vmov.f32 s11, #-1.000000e+00 */
/* @0x2c3934 vmrs APSR_nzcv, fpscr */
/* @0x2c3938 bgt 0x2c383c <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xa8> */
/* @0x2c393c vmov.f32 s15, s13 */
/* @0x2c3940 b 0x2c3848 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xb4> */
/* @0x2c3944 vmov.f32 s9, #1.000000e+00 */
/* @0x2c3948 vldr s11, [sp, #12] */
/* @0x2c394c vldr s10, [sp, #4] */
/* @0x2c3950 vldr s13, [r3, #4] */
/* @0x2c3954 vldr s12, [r3, #12] */
/* @0x2c3958 vdiv.f32 s11, s9, s11 */
/* @0x2c395c vsub.f32 s13, s13, s10 */
/* @0x2c3960 vsub.f32 s12, s12, s10 */
/* @0x2c3964 vmul.f32 s13, s13, s11 */
/* @0x2c3968 vmul.f32 s12, s12, s11 */
/* @0x2c396c vcmpe.f32 s13, s12 */
/* @0x2c3970 vmrs APSR_nzcv, fpscr */
/* @0x2c3974 vmovle.f32 s11, s12 */
/* @0x2c3978 vmovle.f32 s12, s13 */
/* @0x2c397c vmovle.f32 s13, s11 */
/* @0x2c3980 vcmpe.f32 s12, s15 */
/* @0x2c3984 vmovle.f32 s9, #-1.000000e+00 */
/* @0x2c3988 vmrs APSR_nzcv, fpscr */
/* @0x2c398c movgt r3, #0 */
/* @0x2c3990 vstrgt s9, [sp, #28] */
/* @0x2c3994 strgt r3, [sp, #0x18] */
/* @0x2c3998 vcmp.f32 s13, s14 */
/* @0x2c399c vmovgt.f32 s15, s12 */
/* @0x2c39a0 vmrs APSR_nzcv, fpscr */
/* @0x2c39a4 vmovgt.f32 s13, s14 */
/* @0x2c39a8 vcmpe.f32 s15, s13 */
/* @0x2c39ac vmrs APSR_nzcv, fpscr */
/* @0x2c39b0 ble 0x2c38dc <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x148> */
/* @0x2c39b4 b 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0> */
/* @0x2c39b8 strlo r0, [r0], #-0 */
/* @0x2c39bc .word 0xff7fffff */
/* @0x2c39c0 svcvc #0x7fffff */

/* ── FUNC 0x2c39c4 · b2ClipSegmentToLine(b2ClipVertex*, b2ClipVertex const*, b2Vec2 const&, float, int) · size=248 · insn=62 */
/* @0x2c39c4 vldr s15, [r2, #4] */
/* @0x2c39c8 vldr s14, [r1, #4] */
/* @0x2c39cc vmul.f32 s14, s15, s14 */
/* @0x2c39d0 vldr s10, [r1, #16] */
/* @0x2c39d4 vldr s12, [r2] */
/* @0x2c39d8 vldr s9, [r1] */
/* @0x2c39dc vldr s11, [r1, #12] */
/* @0x2c39e0 vmov s13, r3 */
/* @0x2c39e4 push {r4, r5} */
/* @0x2c39e8 mov r12, r1 */
/* @0x2c39ec mov r4, r0 */
/* @0x2c39f0 vmul.f32 s15, s15, s10 */
/* @0x2c39f4 vmla.f32 s14, s12, s9 */
/* @0x2c39f8 vmla.f32 s15, s12, s11 */
/* @0x2c39fc vsub.f32 s14, s14, s13 */
/* @0x2c3a00 vsub.f32 s15, s15, s13 */
/* @0x2c3a04 vcmpe.f32 s14, #0 */
/* @0x2c3a08 vmrs APSR_nzcv, fpscr */
/* @0x2c3a0c ldmls r1, {r0, r1, r2} */
/* @0x2c3a10 vcmpe.f32 s15, #0 */
/* @0x2c3a14 movls r3, #1 */
/* @0x2c3a18 movhi r3, #0 */
/* @0x2c3a1c stmls r4, {r0, r1, r2} */
/* @0x2c3a20 vmrs APSR_nzcv, fpscr */
/* @0x2c3a24 bls 0x2c3aa0 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi+0xdc> */
/* @0x2c3a28 vmul.f32 s13, s14, s15 */
/* @0x2c3a2c vcmpe.f32 s13, #0 */
/* @0x2c3a30 vmrs APSR_nzcv, fpscr */
/* @0x2c3a34 bpl 0x2c3a94 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi+0xd0> */
/* @0x2c3a38 vsub.f32 s15, s14, s15 */
/* @0x2c3a3c vldr s12, [r12, #4] */
/* @0x2c3a40 vldr s13, [r12] */
/* @0x2c3a44 vldr s11, [r12, #16] */
/* @0x2c3a48 vldr s10, [r12, #12] */
/* @0x2c3a4c add r0, r3, r3, lsl #1 */
/* @0x2c3a50 ldr r2, [sp, #0x8] */
/* @0x2c3a54 add r3, r3, #1 */
/* @0x2c3a58 add r0, r4, r0, lsl #2 */
/* @0x2c3a5c mov r5, #0 */
/* @0x2c3a60 mov r1, #1 */
/* @0x2c3a64 strb r2, [r0, #0x8] */
/* @0x2c3a68 vdiv.f32 s14, s14, s15 */
/* @0x2c3a6c vsub.f32 s11, s11, s12 */
/* @0x2c3a70 vsub.f32 s15, s10, s13 */
/* @0x2c3a74 vmla.f32 s12, s14, s11 */
/* @0x2c3a78 vmla.f32 s13, s14, s15 */
/* @0x2c3a7c vstr s12, [r0, #4] */
/* @0x2c3a80 vstr s13, [r0] */
/* @0x2c3a84 ldrb r2, [r12, #0x9] */
/* @0x2c3a88 strb r5, [r0, #0xa] */
/* @0x2c3a8c strb r1, [r0, #0xb] */
/* @0x2c3a90 strb r2, [r0, #0x9] */
/* @0x2c3a94 mov r0, r3 */
/* @0x2c3a98 pop {r4, r5} */
/* @0x2c3a9c bx lr */
/* @0x2c3aa0 add r2, r12, #12 */
/* @0x2c3aa4 add r5, r3, r3, lsl #1 */
/* @0x2c3aa8 add r3, r3, #1 */
/* @0x2c3aac ldm r2, {r0, r1, r2} */
/* @0x2c3ab0 add r5, r4, r5, lsl #2 */
/* @0x2c3ab4 stm r5, {r0, r1, r2} */
/* @0x2c3ab8 b 0x2c3a28 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi+0x64> */

/* ── FUNC 0x2c3abc · b2TestOverlap(b2Shape const*, int, b2Shape const*, int, b2Transform const&, b2Transform const&) · size=184 · insn=46 */
/* @0x2c3abc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c3ac0 sub sp, sp, #132 */
/* @0x2c3ac4 add r7, sp, #36 */
/* @0x2c3ac8 mov r12, r1 */
/* @0x2c3acc ldr r6, [sp, #0xa0] */
/* @0x2c3ad0 mov r9, r3 */
/* @0x2c3ad4 mov r1, r0 */
/* @0x2c3ad8 mov r8, r2 */
/* @0x2c3adc mov r0, r7 */
/* @0x2c3ae0 mov r2, r12 */
/* @0x2c3ae4 mov r4, #0 */
/* @0x2c3ae8 mov r12, #0 */
/* @0x2c3aec ldr r5, [sp, #0xa4] */
/* @0x2c3af0 str r12, [sp, #0x3c] */
/* @0x2c3af4 str r12, [sp, #0x58] */
/* @0x2c3af8 str r4, [sp, #0x34] */
/* @0x2c3afc str r4, [sp, #0x38] */
/* @0x2c3b00 str r4, [sp, #0x50] */
/* @0x2c3b04 str r4, [sp, #0x54] */
/* @0x2c3b08 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei> */
/* @0x2c3b0c mov r1, r8 */
/* @0x2c3b10 mov r2, r9 */
/* @0x2c3b14 add r0, sp, #64 */
/* @0x2c3b18 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei> */
/* @0x2c3b1c ldm r6, {r0, r1, r2, r3} */
/* @0x2c3b20 mov r12, #1 */
/* @0x2c3b24 strb r12, [sp, #0x7c] */
/* @0x2c3b28 add r12, sp, #92 */
/* @0x2c3b2c strh r4, [sp, #4] */
/* @0x2c3b30 stm r12, {r0, r1, r2, r3} */
/* @0x2c3b34 add r12, sp, #108 */
/* @0x2c3b38 ldm r5, {r0, r1, r2, r3} */
/* @0x2c3b3c stm r12, {r0, r1, r2, r3} */
/* @0x2c3b40 add r0, sp, #12 */
/* @0x2c3b44 mov r2, r7 */
/* @0x2c3b48 mov r1, sp */
/* @0x2c3b4c bl 0x2c3fa0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput> */
/* @0x2c3b50 vldr s14, [sp, #28] */
/* @0x2c3b54 vldr s15, [pc, #20] */
/* @0x2c3b58 vcmpe.f32 s14, s15 */
/* @0x2c3b5c vmrs APSR_nzcv, fpscr */
/* @0x2c3b60 movpl r0, #0 */
/* @0x2c3b64 movmi r0, #1 */
/* @0x2c3b68 add sp, sp, #132 */
/* @0x2c3b6c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c3b70 strlo r0, [r0, #0x0]! */

/* ── FUNC 0x2c3b74 · b2DistanceProxy::Set(b2Shape const*, int) · size=220 · insn=55 */
/* @0x2c3b74 mov r12, r1 */
/* @0x2c3b78 ldr r1, [r1, #0x4] */
/* @0x2c3b7c str r4, [sp, #-0x4]! */
/* @0x2c3b80 mov r3, r0 */
/* @0x2c3b84 cmp r1, #3 */
/* @0x2c3b88 addls pc, pc, r1, lsl #2 */
/* @0x2c3b8c b 0x2c3bb8 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x44> */
/* @0x2c3b90 b 0x2c3c30 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0xbc> */
/* @0x2c3b94 b 0x2c3ba0 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x2c> */
/* @0x2c3b98 b 0x2c3c10 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x9c> */
/* @0x2c3b9c b 0x2c3bc0 <_ZN15b2DistanceProxy3SetEPK7b2Shapei+0x4c> */
/* @0x2c3ba0 ldr r1, [r12, #0x8] */
/* @0x2c3ba4 add r2, r12, #12 */
/* @0x2c3ba8 str r2, [r0, #0x10] */
/* @0x2c3bac mov r2, #2 */
/* @0x2c3bb0 str r2, [r0, #0x14] */
/* @0x2c3bb4 str r1, [r0, #0x18] */
/* @0x2c3bb8 ldr r4, [sp], #4 */
/* @0x2c3bbc bx lr */
/* @0x2c3bc0 ldr r4, [r12, #0xc] */
/* @0x2c3bc4 add r0, r2, #1 */
/* @0x2c3bc8 ldr r1, [r12, #0x10] */
/* @0x2c3bcc add r2, r4, r2, lsl #3 */
/* @0x2c3bd0 cmp r0, r1 */
/* @0x2c3bd4 ldm r2, {r0, r1} */
/* @0x2c3bd8 addge r2, r3, #8 */
/* @0x2c3bdc stm r3, {r0, r1} */
/* @0x2c3be0 addlt r1, r2, #8 */
/* @0x2c3be4 ldmge r4, {r0, r1} */
/* @0x2c3be8 addlt r2, r3, #8 */
/* @0x2c3bec ldmlt r1, {r0, r1} */
/* @0x2c3bf0 ldr r4, [sp], #4 */
/* @0x2c3bf4 stm r2, {r0, r1} */
/* @0x2c3bf8 ldr r2, [r12, #0x8] */
/* @0x2c3bfc str r3, [r3, #0x10] */
/* @0x2c3c00 str r2, [r3, #0x18] */
/* @0x2c3c04 mov r2, #2 */
/* @0x2c3c08 str r2, [r3, #0x14] */
/* @0x2c3c0c bx lr */
/* @0x2c3c10 ldr r2, [r12, #0x94] */
/* @0x2c3c14 add r1, r12, #20 */
/* @0x2c3c18 ldr r0, [r12, #0x8] */
/* @0x2c3c1c ldr r4, [sp], #4 */
/* @0x2c3c20 str r1, [r3, #0x10] */
/* @0x2c3c24 str r0, [r3, #0x18] */
/* @0x2c3c28 str r2, [r3, #0x14] */
/* @0x2c3c2c bx lr */
/* @0x2c3c30 ldr r1, [r12, #0x8] */
/* @0x2c3c34 add r2, r12, #12 */
/* @0x2c3c38 ldr r4, [sp], #4 */
/* @0x2c3c3c str r2, [r0, #0x10] */
/* @0x2c3c40 mov r2, #1 */
/* @0x2c3c44 str r1, [r0, #0x18] */
/* @0x2c3c48 str r2, [r0, #0x14] */
/* @0x2c3c4c bx lr */

/* ── FUNC 0x2c3c50 · b2Simplex::Solve2() · size=196 · insn=49 */
/* @0x2c3c50 vldr s15, [r0, #20] */
/* @0x2c3c54 vldr s10, [r0, #56] */
/* @0x2c3c58 vsub.f32 s14, s10, s15 */
/* @0x2c3c5c vldr s13, [r0, #16] */
/* @0x2c3c60 vldr s11, [r0, #52] */
/* @0x2c3c64 str r4, [sp, #-0x4]! */
/* @0x2c3c68 vmul.f32 s15, s15, s14 */
/* @0x2c3c6c vsub.f32 s12, s11, s13 */
/* @0x2c3c70 vmla.f32 s15, s13, s12 */
/* @0x2c3c74 vneg.f32 s13, s15 */
/* @0x2c3c78 vcmpe.f32 s13, #0 */
/* @0x2c3c7c vmrs APSR_nzcv, fpscr */
/* @0x2c3c80 bls 0x2c3cfc <_ZN9b2Simplex6Solve2Ev+0xac> */
/* @0x2c3c84 vmul.f32 s14, s10, s14 */
/* @0x2c3c88 vmla.f32 s14, s11, s12 */
/* @0x2c3c8c vcmpe.f32 s14, #0 */
/* @0x2c3c90 vmrs APSR_nzcv, fpscr */
/* @0x2c3c94 bls 0x2c3cc4 <_ZN9b2Simplex6Solve2Ev+0x74> */
/* @0x2c3c98 vsub.f32 s15, s14, s15 */
/* @0x2c3c9c mov r3, #2 */
/* @0x2c3ca0 ldr r4, [sp], #4 */
/* @0x2c3ca4 str r3, [r0, #0x6c] */
/* @0x2c3ca8 vmov.f32 s12, #1.000000e+00 */
/* @0x2c3cac vdiv.f32 s15, s12, s15 */
/* @0x2c3cb0 vmul.f32 s14, s15, s14 */
/* @0x2c3cb4 vmul.f32 s15, s13, s15 */
/* @0x2c3cb8 vstr s14, [r0, #24] */
/* @0x2c3cbc vstr s15, [r0, #60] */
/* @0x2c3cc0 bx lr */
/* @0x2c3cc4 add r4, r0, #36 */
/* @0x2c3cc8 mov r2, #1065353216 */
/* @0x2c3ccc mov r12, r0 */
/* @0x2c3cd0 str r2, [r0, #0x3c] */
/* @0x2c3cd4 mov r3, #1 */
/* @0x2c3cd8 str r3, [r0, #0x6c] */
/* @0x2c3cdc ldm r4!, {r0, r1, r2, r3} */
/* @0x2c3ce0 stm r12!, {r0, r1, r2, r3} */
/* @0x2c3ce4 ldm r4!, {r0, r1, r2, r3} */
/* @0x2c3ce8 ldr r4, [r4] */
/* @0x2c3cec stm r12!, {r0, r1, r2, r3} */
/* @0x2c3cf0 str r4, [r12] */
/* @0x2c3cf4 ldr r4, [sp], #4 */
/* @0x2c3cf8 bx lr */
/* @0x2c3cfc mov r2, #1065353216 */
/* @0x2c3d00 mov r3, #1 */
/* @0x2c3d04 str r2, [r0, #0x18] */
/* @0x2c3d08 str r3, [r0, #0x6c] */
/* @0x2c3d0c ldr r4, [sp], #4 */
/* @0x2c3d10 bx lr */

/* ── FUNC 0x2c3d14 · b2Simplex::Solve3() · size=652 · insn=163 */
/* @0x2c3d14 vldr s14, [r0, #20] */
/* @0x2c3d18 vldr s12, [r0, #56] */
/* @0x2c3d1c vsub.f32 s1, s12, s14 */
/* @0x2c3d20 vldr s15, [r0, #16] */
/* @0x2c3d24 vldr s10, [r0, #88] */
/* @0x2c3d28 vldr s11, [r0, #92] */
/* @0x2c3d2c vldr s13, [r0, #52] */
/* @0x2c3d30 push {r4, r5} */
/* @0x2c3d34 mov r12, r0 */
/* @0x2c3d38 vsub.f32 s6, s10, s15 */
/* @0x2c3d3c vsub.f32 s2, s11, s14 */
/* @0x2c3d40 vmul.f32 s8, s14, s1 */
/* @0x2c3d44 vsub.f32 s3, s13, s15 */
/* @0x2c3d48 vmul.f32 s7, s14, s2 */
/* @0x2c3d4c vmul.f32 s9, s1, s6 */
/* @0x2c3d50 vmul.f32 s4, s11, s15 */
/* @0x2c3d54 vmul.f32 s5, s13, s14 */
/* @0x2c3d58 vmla.f32 s8, s15, s3 */
/* @0x2c3d5c vnmls.f32 s9, s3, s2 */
/* @0x2c3d60 vnmls.f32 s4, s10, s14 */
/* @0x2c3d64 vnmls.f32 s5, s12, s15 */
/* @0x2c3d68 vmla.f32 s7, s15, s6 */
/* @0x2c3d6c vmul.f32 s14, s11, s2 */
/* @0x2c3d70 vmul.f32 s15, s12, s1 */
/* @0x2c3d74 vneg.f32 s2, s8 */
/* @0x2c3d78 vcmpe.f32 s2, #0 */
/* @0x2c3d7c vmla.f32 s14, s10, s6 */
/* @0x2c3d80 vmrs APSR_nzcv, fpscr */
/* @0x2c3d84 vmla.f32 s15, s13, s3 */
/* @0x2c3d88 vmul.f32 s4, s9, s4 */
/* @0x2c3d8c vmul.f32 s5, s9, s5 */
/* @0x2c3d90 vneg.f32 s6, s7 */
/* @0x2c3d94 bls 0x2c3e7c <_ZN9b2Simplex6Solve3Ev+0x168> */
/* @0x2c3d98 vcmpe.f32 s15, #0 */
/* @0x2c3d9c vmrs APSR_nzcv, fpscr */
/* @0x2c3da0 ble 0x2c3dbc <_ZN9b2Simplex6Solve3Ev+0xa8> */
/* @0x2c3da4 vcmpe.f32 s2, #0 */
/* @0x2c3da8 vmrs APSR_nzcv, fpscr */
/* @0x2c3dac ble 0x2c3dbc <_ZN9b2Simplex6Solve3Ev+0xa8> */
/* @0x2c3db0 vcmpe.f32 s5, #0 */
/* @0x2c3db4 vmrs APSR_nzcv, fpscr */
/* @0x2c3db8 bls 0x2c3ef4 <_ZN9b2Simplex6Solve3Ev+0x1e0> */
/* @0x2c3dbc vcmpe.f32 s14, #0 */
/* @0x2c3dc0 vmrs APSR_nzcv, fpscr */
/* @0x2c3dc4 ble 0x2c3de0 <_ZN9b2Simplex6Solve3Ev+0xcc> */
/* @0x2c3dc8 vcmpe.f32 s6, #0 */
/* @0x2c3dcc vmrs APSR_nzcv, fpscr */
/* @0x2c3dd0 ble 0x2c3de0 <_ZN9b2Simplex6Solve3Ev+0xcc> */
/* @0x2c3dd4 vcmpe.f32 s4, #0 */
/* @0x2c3dd8 vmrs APSR_nzcv, fpscr */
/* @0x2c3ddc bls 0x2c3f20 <_ZN9b2Simplex6Solve3Ev+0x20c> */
/* @0x2c3de0 vsub.f32 s6, s11, s12 */
/* @0x2c3de4 vmul.f32 s8, s12, s6 */
/* @0x2c3de8 vsub.f32 s7, s10, s13 */
/* @0x2c3dec vmla.f32 s8, s13, s7 */
/* @0x2c3df0 vcmpe.f32 s15, #0 */
/* @0x2c3df4 vneg.f32 s3, s8 */
/* @0x2c3df8 vmrs APSR_nzcv, fpscr */
/* @0x2c3dfc bls 0x2c3e9c <_ZN9b2Simplex6Solve3Ev+0x188> */
/* @0x2c3e00 vmul.f32 s15, s11, s6 */
/* @0x2c3e04 vcmpe.f32 s14, #0 */
/* @0x2c3e08 vmla.f32 s15, s10, s7 */
/* @0x2c3e0c vmrs APSR_nzcv, fpscr */
/* @0x2c3e10 bls 0x2c3ec8 <_ZN9b2Simplex6Solve3Ev+0x1b4> */
/* @0x2c3e14 vmul.f32 s12, s10, s12 */
/* @0x2c3e18 vnmls.f32 s12, s11, s13 */
/* @0x2c3e1c vcmpe.f32 s15, #0 */
/* @0x2c3e20 vmul.f32 s12, s9, s12 */
/* @0x2c3e24 vmrs APSR_nzcv, fpscr */
/* @0x2c3e28 ble 0x2c3e44 <_ZN9b2Simplex6Solve3Ev+0x130> */
/* @0x2c3e2c vcmpe.f32 s3, #0 */
/* @0x2c3e30 vmrs APSR_nzcv, fpscr */
/* @0x2c3e34 ble 0x2c3e44 <_ZN9b2Simplex6Solve3Ev+0x130> */
/* @0x2c3e38 vcmpe.f32 s12, #0 */
/* @0x2c3e3c vmrs APSR_nzcv, fpscr */
/* @0x2c3e40 bls 0x2c3f6c <_ZN9b2Simplex6Solve3Ev+0x258> */
/* @0x2c3e44 vadd.f32 s15, s12, s4 */
/* @0x2c3e48 mov r3, #3 */
/* @0x2c3e4c str r3, [r12, #0x6c] */
/* @0x2c3e50 vadd.f32 s15, s15, s5 */
/* @0x2c3e54 vmov.f32 s14, #1.000000e+00 */
/* @0x2c3e58 vdiv.f32 s15, s14, s15 */
/* @0x2c3e5c vmul.f32 s12, s12, s15 */
/* @0x2c3e60 vmul.f32 s4, s4, s15 */
/* @0x2c3e64 vstr s12, [r12, #24] */
/* @0x2c3e68 vmul.f32 s5, s5, s15 */
/* @0x2c3e6c vstr s4, [r12, #60] */
/* @0x2c3e70 vstr s5, [r12, #96] */
/* @0x2c3e74 pop {r4, r5} */
/* @0x2c3e78 bx lr */
/* @0x2c3e7c vcmpe.f32 s6, #0 */
/* @0x2c3e80 vmrs APSR_nzcv, fpscr */
/* @0x2c3e84 bhi 0x2c3d98 <_ZN9b2Simplex6Solve3Ev+0x84> */
/* @0x2c3e88 mov r2, #1065353216 */
/* @0x2c3e8c mov r3, #1 */
/* @0x2c3e90 str r2, [r0, #0x18] */
/* @0x2c3e94 str r3, [r0, #0x6c] */
/* @0x2c3e98 b 0x2c3e74 <_ZN9b2Simplex6Solve3Ev+0x160> */
/* @0x2c3e9c vcmpe.f32 s3, #0 */
/* @0x2c3ea0 vmrs APSR_nzcv, fpscr */
/* @0x2c3ea4 bhi 0x2c3e00 <_ZN9b2Simplex6Solve3Ev+0xec> */
/* @0x2c3ea8 add r5, r12, #36 */
/* @0x2c3eac mov r2, #1065353216 */
/* @0x2c3eb0 mov r3, #1 */
/* @0x2c3eb4 str r2, [r12, #0x3c] */
/* @0x2c3eb8 str r3, [r12, #0x6c] */
/* @0x2c3ebc mov r4, r12 */
/* @0x2c3ec0 ldm r5!, {r0, r1, r2, r3} */
/* @0x2c3ec4 b 0x2c3f50 <_ZN9b2Simplex6Solve3Ev+0x23c> */
/* @0x2c3ec8 vcmpe.f32 s15, #0 */
/* @0x2c3ecc vmrs APSR_nzcv, fpscr */
/* @0x2c3ed0 bhi 0x2c3e14 <_ZN9b2Simplex6Solve3Ev+0x100> */
/* @0x2c3ed4 add r5, r12, #72 */
/* @0x2c3ed8 mov r2, #1065353216 */
/* @0x2c3edc mov r3, #1 */
/* @0x2c3ee0 str r2, [r12, #0x60] */
/* @0x2c3ee4 str r3, [r12, #0x6c] */
/* @0x2c3ee8 mov r4, r12 */
/* @0x2c3eec ldm r5!, {r0, r1, r2, r3} */
/* @0x2c3ef0 b 0x2c3f50 <_ZN9b2Simplex6Solve3Ev+0x23c> */
/* @0x2c3ef4 vsub.f32 s8, s15, s8 */
/* @0x2c3ef8 mov r3, #2 */
/* @0x2c3efc pop {r4, r5} */
/* @0x2c3f00 str r3, [r12, #0x6c] */
/* @0x2c3f04 vmov.f32 s14, #1.000000e+00 */
/* @0x2c3f08 vdiv.f32 s8, s14, s8 */
/* @0x2c3f0c vmul.f32 s15, s8, s15 */
/* @0x2c3f10 vmul.f32 s8, s2, s8 */
/* @0x2c3f14 vstr s15, [r12, #24] */
/* @0x2c3f18 vstr s8, [r12, #60] */
/* @0x2c3f1c bx lr */
/* @0x2c3f20 vsub.f32 s7, s14, s7 */
/* @0x2c3f24 add r5, r12, #72 */
/* @0x2c3f28 add r4, r12, #36 */
/* @0x2c3f2c mov r3, #2 */
/* @0x2c3f30 str r3, [r12, #0x6c] */
/* @0x2c3f34 vmov.f32 s15, #1.000000e+00 */
/* @0x2c3f38 vdiv.f32 s7, s15, s7 */
/* @0x2c3f3c vmul.f32 s6, s6, s7 */
/* @0x2c3f40 vmul.f32 s14, s7, s14 */
/* @0x2c3f44 vstr s6, [r12, #96] */
/* @0x2c3f48 ldm r5!, {r0, r1, r2, r3} */
/* @0x2c3f4c vstr s14, [r12, #24] */
/* @0x2c3f50 stm r4!, {r0, r1, r2, r3} */
/* @0x2c3f54 ldm r5!, {r0, r1, r2, r3} */
/* @0x2c3f58 ldr r12, [r5] */
/* @0x2c3f5c stm r4!, {r0, r1, r2, r3} */
/* @0x2c3f60 str r12, [r4] */
/* @0x2c3f64 pop {r4, r5} */
/* @0x2c3f68 bx lr */
/* @0x2c3f6c vsub.f32 s8, s15, s8 */
/* @0x2c3f70 add r5, r12, #72 */
/* @0x2c3f74 mov r3, #2 */
/* @0x2c3f78 mov r4, r12 */
/* @0x2c3f7c str r3, [r12, #0x6c] */
/* @0x2c3f80 vmov.f32 s14, #1.000000e+00 */
/* @0x2c3f84 vdiv.f32 s8, s14, s8 */
/* @0x2c3f88 vmul.f32 s3, s3, s8 */
/* @0x2c3f8c vmul.f32 s15, s8, s15 */
/* @0x2c3f90 vstr s3, [r12, #96] */
/* @0x2c3f94 ldm r5!, {r0, r1, r2, r3} */
/* @0x2c3f98 vstr s15, [r12, #60] */
/* @0x2c3f9c b 0x2c3f50 <_ZN9b2Simplex6Solve3Ev+0x23c> */

/* ── FUNC 0x2c3fa0 · b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*) · size=2248 · insn=562 */
/* @0x2c3fa0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c3fa4 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2c3fa8 mov r5, r1 */
/* @0x2c3fac vldr s21, [r2, #56] */
/* @0x2c3fb0 ldr r7, [pc, #0x5e4] */
/* @0x2c3fb4 mov r4, r2 */
/* @0x2c3fb8 ldr r1, [pc, #0x5e0] */
/* @0x2c3fbc vldr s20, [r2, #60] */
/* @0x2c3fc0 add r7, pc, r7 */
/* @0x2c3fc4 ldrh r3, [r5, #4] */
/* @0x2c3fc8 sub sp, sp, #140 */
/* @0x2c3fcc mov r8, r0 */
/* @0x2c3fd0 ldr r2, [r7, r1] */
/* @0x2c3fd4 cmp r3, #0 */
/* @0x2c3fd8 str r3, [sp, #0x84] */
/* @0x2c3fdc vldr s19, [r4, #64] */
/* @0x2c3fe0 vldr s17, [r4, #68] */
/* @0x2c3fe4 vldr s23, [r4, #72] */
/* @0x2c3fe8 ldr r3, [r2] */
/* @0x2c3fec vldr s22, [r4, #76] */
/* @0x2c3ff0 vldr s18, [r4, #80] */
/* @0x2c3ff4 vldr s16, [r4, #84] */
/* @0x2c3ff8 add r3, r3, #1 */
/* @0x2c3ffc str r3, [r2] */
/* @0x2c4000 beq 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178> */
/* @0x2c4004 ldr r10, [r4, #0x10] */
/* @0x2c4008 sub r2, r5, #1 */
/* @0x2c400c ldr r6, [r4, #0x2c] */
/* @0x2c4010 add r3, sp, #56 */
/* @0x2c4014 mov r1, #0 */
/* @0x2c4018 mov r11, #0 */
/* @0x2c401c add r2, r2, #1 */
/* @0x2c4020 ldrb r12, [r2, #0x6] */
/* @0x2c4024 ldrb r0, [r2, #0x9] */
/* @0x2c4028 add r1, r1, #1 */
/* @0x2c402c add r3, r3, #36 */
/* @0x2c4030 str r12, [r3, #-0x28] */
/* @0x2c4034 add r12, r10, r12, lsl #3 */
/* @0x2c4038 str r0, [r3, #-0x24] */
/* @0x2c403c add r0, r6, r0, lsl #3 */
/* @0x2c4040 vldr s13, [r12, #4] */
/* @0x2c4044 vldr s15, [r0, #4] */
/* @0x2c4048 vmul.f32 s12, s13, s19 */
/* @0x2c404c vldr s10, [r12] */
/* @0x2c4050 vldr s11, [r0] */
/* @0x2c4054 str r11, [r3, #-0x2c] */
/* @0x2c4058 vmul.f32 s14, s15, s18 */
/* @0x2c405c vmul.f32 s13, s13, s17 */
/* @0x2c4060 vmul.f32 s15, s15, s16 */
/* @0x2c4064 vnmls.f32 s12, s10, s17 */
/* @0x2c4068 vmla.f32 s13, s10, s19 */
/* @0x2c406c vnmls.f32 s14, s11, s16 */
/* @0x2c4070 vmla.f32 s15, s11, s18 */
/* @0x2c4074 vadd.f32 s12, s21, s12 */
/* @0x2c4078 vadd.f32 s13, s20, s13 */
/* @0x2c407c vstr s12, [r3, #-68] */
/* @0x2c4080 vadd.f32 s14, s14, s23 */
/* @0x2c4084 vstr s13, [r3, #-64] */
/* @0x2c4088 vadd.f32 s15, s15, s22 */
/* @0x2c408c vstr s14, [r3, #-60] */
/* @0x2c4090 vstr s15, [r3, #-56] */
/* @0x2c4094 vsub.f32 s14, s14, s12 */
/* @0x2c4098 vsub.f32 s15, s15, s13 */
/* @0x2c409c vstr s14, [r3, #-52] */
/* @0x2c40a0 vstr s15, [r3, #-48] */
/* @0x2c40a4 ldr r9, [sp, #0x84] */
/* @0x2c40a8 cmp r1, r9 */
/* @0x2c40ac blt 0x2c401c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x7c> */
/* @0x2c40b0 cmp r9, #1 */
/* @0x2c40b4 ble 0x2c46a4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x704> */
/* @0x2c40b8 cmp r9, #3 */
/* @0x2c40bc vldr s24, [r5] */
/* @0x2c40c0 beq 0x2c4768 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x7c8> */
/* @0x2c40c4 vldr s12, [sp, #44] */
/* @0x2c40c8 vldr s14, [sp, #80] */
/* @0x2c40cc vsub.f32 s14, s12, s14 */
/* @0x2c40d0 vldr s13, [sp, #40] */
/* @0x2c40d4 vldr s15, [sp, #76] */
/* @0x2c40d8 vmul.f32 s14, s14, s14 */
/* @0x2c40dc vsub.f32 s15, s13, s15 */
/* @0x2c40e0 vmla.f32 s14, s15, s15 */
/* @0x2c40e4 vsqrt.f32 s15, s14 */
/* @0x2c40e8 vcmp.f32 s15, s15 */
/* @0x2c40ec vmrs APSR_nzcv, fpscr */
/* @0x2c40f0 bne 0x2c4858 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x8b8> */
/* @0x2c40f4 vmov.f32 s14, #5.000000e-01 */
/* @0x2c40f8 vmul.f32 s14, s24, s14 */
/* @0x2c40fc vcmpe.f32 s14, s15 */
/* @0x2c4100 vmrs APSR_nzcv, fpscr */
/* @0x2c4104 bgt 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178> */
/* @0x2c4108 vadd.f32 s24, s24, s24 */
/* @0x2c410c vcmpe.f32 s24, s15 */
/* @0x2c4110 vmrs APSR_nzcv, fpscr */
/* @0x2c4114 bpl 0x2c4690 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x6f0> */
/* @0x2c4118 ldr r3, [r4, #0x2c] */
/* @0x2c411c vldr s15, [r3, #4] */
/* @0x2c4120 ldr r2, [r4, #0x10] */
/* @0x2c4124 vmul.f32 s14, s15, s18 */
/* @0x2c4128 vldr s13, [r2, #4] */
/* @0x2c412c vldr s11, [r3] */
/* @0x2c4130 vldr s10, [r2] */
/* @0x2c4134 mov r3, #1 */
/* @0x2c4138 mov r9, r3 */
/* @0x2c413c str r3, [sp, #0x84] */
/* @0x2c4140 mov r3, #0 */
/* @0x2c4144 str r3, [sp, #0x34] */
/* @0x2c4148 str r3, [sp, #0x38] */
/* @0x2c414c mov r3, #1065353216 */
/* @0x2c4150 str r3, [sp, #0x30] */
/* @0x2c4154 vmul.f32 s12, s13, s19 */
/* @0x2c4158 vmul.f32 s15, s15, s16 */
/* @0x2c415c vmul.f32 s13, s13, s17 */
/* @0x2c4160 vnmls.f32 s12, s10, s17 */
/* @0x2c4164 vmla.f32 s13, s10, s19 */
/* @0x2c4168 vnmls.f32 s14, s11, s16 */
/* @0x2c416c vmla.f32 s15, s11, s18 */
/* @0x2c4170 vadd.f32 s12, s21, s12 */
/* @0x2c4174 vadd.f32 s13, s20, s13 */
/* @0x2c4178 vstr s12, [sp, #24] */
/* @0x2c417c vadd.f32 s14, s14, s23 */
/* @0x2c4180 vstr s13, [sp, #28] */
/* @0x2c4184 vadd.f32 s15, s15, s22 */
/* @0x2c4188 vstr s14, [sp, #32] */
/* @0x2c418c vstr s15, [sp, #36] */
/* @0x2c4190 vsub.f32 s14, s14, s12 */
/* @0x2c4194 vsub.f32 s15, s15, s13 */
/* @0x2c4198 vstr s14, [sp, #40] */
/* @0x2c419c vstr s15, [sp, #44] */
/* @0x2c41a0 vneg.f32 s26, s19 */
/* @0x2c41a4 mov r6, #0 */
/* @0x2c41a8 vldr s24, [pc, #996] */
/* @0x2c41ac vneg.f32 s25, s18 */
/* @0x2c41b0 cmp r9, #0 */
/* @0x2c41b4 ble 0x2c41ec <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x24c> */
/* @0x2c41b8 add r2, sp, #24 */
/* @0x2c41bc lsl r11, r9, #2 */
/* @0x2c41c0 add r1, sp, #12 */
/* @0x2c41c4 mov r10, sp */
/* @0x2c41c8 mov r3, #0 */
/* @0x2c41cc ldr r12, [r2, #0x1c] */
/* @0x2c41d0 add r2, r2, #36 */
/* @0x2c41d4 ldr r0, [r2, #-0x4] */
/* @0x2c41d8 str r12, [r10, r3] */
/* @0x2c41dc str r0, [r1, r3] */
/* @0x2c41e0 add r3, r3, #4 */
/* @0x2c41e4 cmp r3, r11 */
/* @0x2c41e8 bne 0x2c41cc <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x22c> */
/* @0x2c41ec cmp r9, #2 */
/* @0x2c41f0 beq 0x2c45c8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x628> */
/* @0x2c41f4 cmp r9, #3 */
/* @0x2c41f8 bne 0x2c45b4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x614> */
/* @0x2c41fc add r0, sp, #24 */
/* @0x2c4200 bl 0x2c3d14 <_ZN9b2Simplex6Solve3Ev> */
/* @0x2c4204 ldr r1, [sp, #0x84] */
/* @0x2c4208 cmp r1, #3 */
/* @0x2c420c beq 0x2c45c0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x620> */
/* @0x2c4210 cmp r1, #1 */
/* @0x2c4214 beq 0x2c45ec <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x64c> */
/* @0x2c4218 cmp r1, #2 */
/* @0x2c421c bne 0x2c45d8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x638> */
/* @0x2c4220 vldr s14, [sp, #44] */
/* @0x2c4224 vldr s9, [sp, #80] */
/* @0x2c4228 vsub.f32 s9, s9, s14 */
/* @0x2c422c vldr s13, [sp, #40] */
/* @0x2c4230 vldr s12, [sp, #76] */
/* @0x2c4234 vnmul.f32 s15, s13, s9 */
/* @0x2c4238 vsub.f32 s12, s12, s13 */
/* @0x2c423c vnmla.f32 s15, s14, s12 */
/* @0x2c4240 vcmpe.f32 s15, #0 */
/* @0x2c4244 vmrs APSR_nzcv, fpscr */
/* @0x2c4248 vneggt.f32 s9, s9 */
/* @0x2c424c vnegle.f32 s12, s12 */
/* @0x2c4250 vmul.f32 s15, s12, s12 */
/* @0x2c4254 vmla.f32 s15, s9, s9 */
/* @0x2c4258 vcmpe.f32 s15, s24 */
/* @0x2c425c vmrs APSR_nzcv, fpscr */
/* @0x2c4260 bmi 0x2c45c0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x620> */
/* @0x2c4264 vneg.f32 s11, s12 */
/* @0x2c4268 ldr r10, [r4, #0x10] */
/* @0x2c426c vldr s13, [r10, #4] */
/* @0x2c4270 ldr r0, [r4, #0x14] */
/* @0x2c4274 add r1, r1, r1, lsl #3 */
/* @0x2c4278 add r3, sp, #24 */
/* @0x2c427c cmp r0, #1 */
/* @0x2c4280 vldr s14, [r10] */
/* @0x2c4284 vmul.f32 s10, s11, s17 */
/* @0x2c4288 add r1, r3, r1, lsl #2 */
/* @0x2c428c vneg.f32 s15, s9 */
/* @0x2c4290 vmul.f32 s11, s11, s19 */
/* @0x2c4294 vmla.f32 s10, s15, s26 */
/* @0x2c4298 vmla.f32 s11, s15, s17 */
/* @0x2c429c vmul.f32 s13, s10, s13 */
/* @0x2c42a0 vmla.f32 s13, s11, s14 */
/* @0x2c42a4 ble 0x2c460c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x66c> */
/* @0x2c42a8 add r3, r10, #8 */
/* @0x2c42ac mov r2, #0 */
/* @0x2c42b0 mov r12, #1 */
/* @0x2c42b4 vldr s15, [r3, #4] */
/* @0x2c42b8 vldr s14, [r3] */
/* @0x2c42bc add r3, r3, #8 */
/* @0x2c42c0 vmul.f32 s15, s10, s15 */
/* @0x2c42c4 vmla.f32 s15, s11, s14 */
/* @0x2c42c8 vcmpe.f32 s13, s15 */
/* @0x2c42cc vmrs APSR_nzcv, fpscr */
/* @0x2c42d0 movmi r2, r12 */
/* @0x2c42d4 add r12, r12, #1 */
/* @0x2c42d8 vmovmi.f32 s13, s15 */
/* @0x2c42dc cmp r12, r0 */
/* @0x2c42e0 bne 0x2c42b4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x314> */
/* @0x2c42e4 lsl r3, r2, #3 */
/* @0x2c42e8 add r10, r10, r3 */
/* @0x2c42ec vldr s15, [r10, #4] */
/* @0x2c42f0 vmul.f32 s14, s15, s19 */
/* @0x2c42f4 vldr s13, [r10] */
/* @0x2c42f8 ldr r11, [r4, #0x2c] */
/* @0x2c42fc ldr r10, [r4, #0x30] */
/* @0x2c4300 str r2, [r1, #0x1c] */
/* @0x2c4304 cmp r10, #1 */
/* @0x2c4308 vmul.f32 s15, s15, s17 */
/* @0x2c430c vmul.f32 s11, s12, s16 */
/* @0x2c4310 vmla.f32 s15, s13, s19 */
/* @0x2c4314 vnmls.f32 s14, s13, s17 */
/* @0x2c4318 vmla.f32 s11, s9, s25 */
/* @0x2c431c vmul.f32 s12, s12, s18 */
/* @0x2c4320 vadd.f32 s10, s15, s20 */
/* @0x2c4324 vadd.f32 s8, s14, s21 */
/* @0x2c4328 vstr s10, [r1, #4] */
/* @0x2c432c vmla.f32 s12, s9, s16 */
/* @0x2c4330 vstr s8, [r1] */
/* @0x2c4334 vldr s13, [r11, #4] */
/* @0x2c4338 vldr s15, [r11] */
/* @0x2c433c vmul.f32 s13, s11, s13 */
/* @0x2c4340 vmla.f32 s13, s12, s15 */
/* @0x2c4344 ble 0x2c4600 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x660> */
/* @0x2c4348 add r3, r11, #8 */
/* @0x2c434c mov r0, #0 */
/* @0x2c4350 mov r12, #1 */
/* @0x2c4354 vldr s15, [r3, #4] */
/* @0x2c4358 vldr s14, [r3] */
/* @0x2c435c add r3, r3, #8 */
/* @0x2c4360 vmul.f32 s15, s11, s15 */
/* @0x2c4364 vmla.f32 s15, s12, s14 */
/* @0x2c4368 vcmpe.f32 s13, s15 */
/* @0x2c436c vmrs APSR_nzcv, fpscr */
/* @0x2c4370 movmi r0, r12 */
/* @0x2c4374 add r12, r12, #1 */
/* @0x2c4378 vmovmi.f32 s13, s15 */
/* @0x2c437c cmp r12, r10 */
/* @0x2c4380 bne 0x2c4354 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x3b4> */
/* @0x2c4384 lsl r3, r0, #3 */
/* @0x2c4388 add r11, r11, r3 */
/* @0x2c438c vldr s15, [r11, #4] */
/* @0x2c4390 vmul.f32 s14, s15, s18 */
/* @0x2c4394 vldr s13, [r11] */
/* @0x2c4398 ldr r3, [pc, #0x204] */
/* @0x2c439c cmp r9, #0 */
/* @0x2c43a0 str r0, [r1, #0x20] */
/* @0x2c43a4 add r6, r6, #1 */
/* @0x2c43a8 vmul.f32 s15, s15, s16 */
/* @0x2c43ac vnmls.f32 s14, s13, s16 */
/* @0x2c43b0 vmla.f32 s15, s13, s18 */
/* @0x2c43b4 vadd.f32 s14, s14, s23 */
/* @0x2c43b8 vadd.f32 s15, s15, s22 */
/* @0x2c43bc vstr s14, [r1, #8] */
/* @0x2c43c0 vstr s15, [r1, #12] */
/* @0x2c43c4 vsub.f32 s14, s14, s8 */
/* @0x2c43c8 vsub.f32 s15, s15, s10 */
/* @0x2c43cc vstr s14, [r1, #16] */
/* @0x2c43d0 vstr s15, [r1, #20] */
/* @0x2c43d4 ldr r3, [r7, r3] */
/* @0x2c43d8 ldr r1, [r3] */
/* @0x2c43dc add r1, r1, #1 */
/* @0x2c43e0 str r1, [r3] */
/* @0x2c43e4 ble 0x2c457c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5dc> */
/* @0x2c43e8 mov r3, #0 */
/* @0x2c43ec mov r10, sp */
/* @0x2c43f0 mov r12, r3 */
/* @0x2c43f4 b 0x2c4404 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x464> */
/* @0x2c43f8 cmp r12, r9 */
/* @0x2c43fc add r3, r3, #4 */
/* @0x2c4400 beq 0x2c457c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5dc> */
/* @0x2c4404 ldr r1, [r10, r3] */
/* @0x2c4408 add r12, r12, #1 */
/* @0x2c440c cmp r1, r2 */
/* @0x2c4410 bne 0x2c43f8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x458> */
/* @0x2c4414 add r1, sp, #12 */
/* @0x2c4418 ldr r1, [r1, r3] */
/* @0x2c441c cmp r1, r0 */
/* @0x2c4420 bne 0x2c43f8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x458> */
/* @0x2c4424 ldr r9, [sp, #0x84] */
/* @0x2c4428 ldr r3, [pc, #0x178] */
/* @0x2c442c ldr r3, [r7, r3] */
/* @0x2c4430 ldr r2, [r3] */
/* @0x2c4434 cmp r6, r2 */
/* @0x2c4438 strge r6, [r3] */
/* @0x2c443c strlt r2, [r3] */
/* @0x2c4440 cmp r9, #2 */
/* @0x2c4444 beq 0x2c470c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x76c> */
/* @0x2c4448 cmp r9, #3 */
/* @0x2c444c beq 0x2c46b0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x710> */
/* @0x2c4450 cmp r9, #1 */
/* @0x2c4454 addeq r2, sp, #24 */
/* @0x2c4458 addeq r3, r8, #8 */
/* @0x2c445c ldmeq r2, {r0, r1} */
/* @0x2c4460 addeq r2, sp, #32 */
/* @0x2c4464 stmeq r8, {r0, r1} */
/* @0x2c4468 ldmeq r2, {r0, r1} */
/* @0x2c446c stmeq r3, {r0, r1} */
/* @0x2c4470 vldr s13, [r8] */
/* @0x2c4474 vldr s15, [r8, #8] */
/* @0x2c4478 vldr s12, [r8, #4] */
/* @0x2c447c vldr s14, [r8, #12] */
/* @0x2c4480 vsub.f32 s14, s12, s14 */
/* @0x2c4484 vmul.f32 s14, s14, s14 */
/* @0x2c4488 vsub.f32 s15, s13, s15 */
/* @0x2c448c vmla.f32 s14, s15, s15 */
/* @0x2c4490 vsqrt.f32 s15, s14 */
/* @0x2c4494 vcmp.f32 s15, s15 */
/* @0x2c4498 vmrs APSR_nzcv, fpscr */
/* @0x2c449c bne 0x2c4848 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x8a8> */
/* @0x2c44a0 ldr r9, [sp, #0x84] */
/* @0x2c44a4 vstr s15, [r8, #16] */
/* @0x2c44a8 str r6, [r8, #0x14] */
/* @0x2c44ac cmp r9, #2 */
/* @0x2c44b0 beq 0x2c4658 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x6b8> */
/* @0x2c44b4 cmp r9, #3 */
/* @0x2c44b8 beq 0x2c4618 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x678> */
/* @0x2c44bc mov r0, r9 */
/* @0x2c44c0 vldr s15, [pc, #208] */
/* @0x2c44c4 cmp r9, #0 */
/* @0x2c44c8 vstr s15, [r5] */
/* @0x2c44cc strh r9, [r5, #4] */
/* @0x2c44d0 ble 0x2c44fc <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x55c> */
/* @0x2c44d4 add r3, sp, #24 */
/* @0x2c44d8 add r0, r5, r0 */
/* @0x2c44dc ldr r1, [r3, #0x1c] */
/* @0x2c44e0 add r5, r5, #1 */
/* @0x2c44e4 ldr r2, [r3, #0x20] */
/* @0x2c44e8 add r3, r3, #36 */
/* @0x2c44ec strb r1, [r5, #0x5] */
/* @0x2c44f0 cmp r5, r0 */
/* @0x2c44f4 strb r2, [r5, #0x8] */
/* @0x2c44f8 bne 0x2c44dc <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x53c> */
/* @0x2c44fc ldrb r3, [r4, #0x58] */
/* @0x2c4500 cmp r3, #0 */
/* @0x2c4504 beq 0x2c4570 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5d0> */
/* @0x2c4508 vldr s17, [r4, #24] */
/* @0x2c450c vldr s16, [r4, #52] */
/* @0x2c4510 vadd.f32 s14, s17, s16 */
/* @0x2c4514 vldr s15, [r8, #16] */
/* @0x2c4518 vcmpe.f32 s15, s14 */
/* @0x2c451c vmrs APSR_nzcv, fpscr */
/* @0x2c4520 ble 0x2c4534 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x594> */
/* @0x2c4524 vldr s13, [pc, #132] */
/* @0x2c4528 vcmpe.f32 s15, s13 */
/* @0x2c452c vmrs APSR_nzcv, fpscr */
/* @0x2c4530 bgt 0x2c479c <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x7fc> */
/* @0x2c4534 vldr s11, [r8] */
/* @0x2c4538 vldr s14, [r8, #8] */
/* @0x2c453c vmov.f32 s15, #5.000000e-01 */
/* @0x2c4540 vldr s12, [r8, #4] */
/* @0x2c4544 vldr s13, [r8, #12] */
/* @0x2c4548 mov r3, #0 */
/* @0x2c454c str r3, [r8, #0x10] */
/* @0x2c4550 vadd.f32 s14, s11, s14 */
/* @0x2c4554 vadd.f32 s13, s12, s13 */
/* @0x2c4558 vmul.f32 s14, s14, s15 */
/* @0x2c455c vmul.f32 s15, s13, s15 */
/* @0x2c4560 vstr s14, [r8] */
/* @0x2c4564 vstr s14, [r8, #8] */
/* @0x2c4568 vstr s15, [r8, #4] */
/* @0x2c456c vstr s15, [r8, #12] */
/* @0x2c4570 add sp, sp, #140 */
/* @0x2c4574 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2c4578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c457c ldr r9, [sp, #0x84] */
/* @0x2c4580 cmp r6, #20 */
/* @0x2c4584 add r9, r9, #1 */
/* @0x2c4588 str r9, [sp, #0x84] */
/* @0x2c458c bne 0x2c41b0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x210> */
/* @0x2c4590 b 0x2c4428 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x488> */
/* @0x2c4594 .word 0x28800000 */
/* @0x2c4598 andeq r0, r0, r0 */
/* @0x2c459c mulseq r2, r0, r12 */
/* @0x2c45a0 .word 0xfffffe78 */
/* @0x2c45a4 .word 0xfffffe7c */
/* @0x2c45a8 .word 0xfffffe80 */
/* @0x2c45ac .word 0xfffff888 */
/* @0x2c45b0 strlo r0, [r0], #-0 */
/* @0x2c45b4 mov r1, r9 */
/* @0x2c45b8 cmp r1, #3 */
/* @0x2c45bc bne 0x2c4210 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x270> */
/* @0x2c45c0 mov r9, r1 */
/* @0x2c45c4 b 0x2c4428 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x488> */
/* @0x2c45c8 add r0, sp, #24 */
/* @0x2c45cc bl 0x2c3c50 <_ZN9b2Simplex6Solve2Ev> */
/* @0x2c45d0 ldr r1, [sp, #0x84] */
/* @0x2c45d4 b 0x2c4208 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x268> */
/* @0x2c45d8 ldr r3, [pc, #-0x34] */
/* @0x2c45dc ldr r3, [r7, r3] */
/* @0x2c45e0 vldr s9, [r3] */
/* @0x2c45e4 vldr s12, [r3, #4] */
/* @0x2c45e8 b 0x2c4250 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x2b0> */
/* @0x2c45ec vldr s9, [sp, #40] */
/* @0x2c45f0 vldr s12, [sp, #44] */
/* @0x2c45f4 vneg.f32 s9, s9 */
/* @0x2c45f8 vneg.f32 s12, s12 */
/* @0x2c45fc b 0x2c4250 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x2b0> */
/* @0x2c4600 mov r3, #0 */
/* @0x2c4604 mov r0, r3 */
/* @0x2c4608 b 0x2c4388 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x3e8> */
/* @0x2c460c mov r3, #0 */
/* @0x2c4610 mov r2, r3 */
/* @0x2c4614 b 0x2c42e8 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x348> */
/* @0x2c4618 vldr s13, [sp, #40] */
/* @0x2c461c vldr s14, [sp, #44] */
/* @0x2c4620 vldr s15, [sp, #112] */
/* @0x2c4624 vldr s10, [sp, #80] */
/* @0x2c4628 vsub.f32 s15, s15, s13 */
/* @0x2c462c vldr s11, [sp, #76] */
/* @0x2c4630 vldr s12, [sp, #116] */
/* @0x2c4634 mov r0, r9 */
/* @0x2c4638 strh r9, [r5, #4] */
/* @0x2c463c vsub.f32 s10, s10, s14 */
/* @0x2c4640 vmul.f32 s15, s10, s15 */
/* @0x2c4644 vsub.f32 s13, s11, s13 */
/* @0x2c4648 vsub.f32 s14, s12, s14 */
/* @0x2c464c vnmls.f32 s15, s13, s14 */
/* @0x2c4650 vstr s15, [r5] */
/* @0x2c4654 b 0x2c44d4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x534> */
/* @0x2c4658 vldr s12, [sp, #44] */
/* @0x2c465c vldr s14, [sp, #80] */
/* @0x2c4660 vsub.f32 s14, s12, s14 */
/* @0x2c4664 vldr s13, [sp, #40] */
/* @0x2c4668 vldr s15, [sp, #76] */
/* @0x2c466c vmul.f32 s14, s14, s14 */
/* @0x2c4670 vsub.f32 s15, s13, s15 */
/* @0x2c4674 vmla.f32 s14, s15, s15 */
/* @0x2c4678 vsqrt.f32 s15, s14 */
/* @0x2c467c vcmp.f32 s15, s15 */
/* @0x2c4680 vmrs APSR_nzcv, fpscr */
/* @0x2c4684 bne 0x2c4834 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x894> */
/* @0x2c4688 mov r0, r9 */
/* @0x2c468c b 0x2c44c4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x524> */
/* @0x2c4690 vldr s14, [pc, #-232] */
/* @0x2c4694 vcmpe.f32 s15, s14 */
/* @0x2c4698 vmrs APSR_nzcv, fpscr */
/* @0x2c469c bmi 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178> */
/* @0x2c46a0 ldr r9, [sp, #0x84] */
/* @0x2c46a4 cmp r9, #0 */
/* @0x2c46a8 bne 0x2c41a0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x200> */
/* @0x2c46ac b 0x2c4118 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x178> */
/* @0x2c46b0 vldr s12, [sp, #84] */
/* @0x2c46b4 vldr s13, [sp, #60] */
/* @0x2c46b8 vldr s7, [sp, #64] */
/* @0x2c46bc vmul.f32 s13, s12, s13 */
/* @0x2c46c0 vldr s14, [sp, #48] */
/* @0x2c46c4 vldr s8, [sp, #24] */
/* @0x2c46c8 vldr s9, [sp, #28] */
/* @0x2c46cc vldr s15, [sp, #120] */
/* @0x2c46d0 vldr s10, [sp, #96] */
/* @0x2c46d4 vldr s11, [sp, #100] */
/* @0x2c46d8 add r3, r8, #8 */
/* @0x2c46dc vmul.f32 s12, s12, s7 */
/* @0x2c46e0 vmla.f32 s13, s14, s8 */
/* @0x2c46e4 vmla.f32 s12, s14, s9 */
/* @0x2c46e8 vmla.f32 s13, s15, s10 */
/* @0x2c46ec vmla.f32 s12, s15, s11 */
/* @0x2c46f0 vstr s13, [r8] */
/* @0x2c46f4 vstr s12, [r8, #4] */
/* @0x2c46f8 ldm r8, {r0, r1} */
/* @0x2c46fc stm r3, {r0, r1} */
/* @0x2c4700 vldr s15, [r8, #8] */
/* @0x2c4704 vldr s14, [r8, #12] */
/* @0x2c4708 b 0x2c4480 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x4e0> */
/* @0x2c470c vldr s14, [sp, #84] */
/* @0x2c4710 vldr s13, [sp, #60] */
/* @0x2c4714 vldr s12, [sp, #64] */
/* @0x2c4718 vmul.f32 s13, s14, s13 */
/* @0x2c471c vldr s15, [sp, #68] */
/* @0x2c4720 vldr s6, [sp, #72] */
/* @0x2c4724 vldr s11, [sp, #48] */
/* @0x2c4728 vldr s7, [sp, #24] */
/* @0x2c472c vldr s8, [sp, #28] */
/* @0x2c4730 vldr s9, [sp, #32] */
/* @0x2c4734 vldr s10, [sp, #36] */
/* @0x2c4738 vmul.f32 s12, s14, s12 */
/* @0x2c473c vmul.f32 s15, s14, s15 */
/* @0x2c4740 vmul.f32 s14, s14, s6 */
/* @0x2c4744 vmla.f32 s13, s11, s7 */
/* @0x2c4748 vmla.f32 s12, s11, s8 */
/* @0x2c474c vstr s13, [r8] */
/* @0x2c4750 vmla.f32 s15, s11, s9 */
/* @0x2c4754 vstr s12, [r8, #4] */
/* @0x2c4758 vmla.f32 s14, s11, s10 */
/* @0x2c475c vstr s15, [r8, #8] */
/* @0x2c4760 vstr s14, [r8, #12] */
/* @0x2c4764 b 0x2c4480 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x4e0> */
/* @0x2c4768 vldr s13, [sp, #40] */
/* @0x2c476c vldr s14, [sp, #44] */
/* @0x2c4770 vldr s15, [sp, #112] */
/* @0x2c4774 vldr s10, [sp, #80] */
/* @0x2c4778 vsub.f32 s15, s15, s13 */
/* @0x2c477c vldr s11, [sp, #76] */
/* @0x2c4780 vldr s12, [sp, #116] */
/* @0x2c4784 vsub.f32 s10, s10, s14 */
/* @0x2c4788 vmul.f32 s15, s10, s15 */
/* @0x2c478c vsub.f32 s13, s11, s13 */
/* @0x2c4790 vsub.f32 s14, s12, s14 */
/* @0x2c4794 vnmls.f32 s15, s13, s14 */
/* @0x2c4798 b 0x2c40f4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x154> */
/* @0x2c479c vldr s13, [r8, #4] */
/* @0x2c47a0 vldr s18, [r8, #12] */
/* @0x2c47a4 vsub.f32 s18, s18, s13 */
/* @0x2c47a8 vldr s19, [r8, #8] */
/* @0x2c47ac vldr s13, [r8] */
/* @0x2c47b0 vmul.f32 s12, s18, s18 */
/* @0x2c47b4 vsub.f32 s19, s19, s13 */
/* @0x2c47b8 vmla.f32 s12, s19, s19 */
/* @0x2c47bc vsqrt.f32 s13, s12 */
/* @0x2c47c0 vsub.f32 s15, s15, s14 */
/* @0x2c47c4 vcmp.f32 s13, s13 */
/* @0x2c47c8 vstr s15, [r8, #16] */
/* @0x2c47cc vmrs APSR_nzcv, fpscr */
/* @0x2c47d0 bne 0x2c4824 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x884> */
/* @0x2c47d4 vldr s15, [pc, #-556] */
/* @0x2c47d8 vcmpe.f32 s13, s15 */
/* @0x2c47dc vldr s12, [r8] */
/* @0x2c47e0 vldr s14, [r8, #8] */
/* @0x2c47e4 vmrs APSR_nzcv, fpscr */
/* @0x2c47e8 vmovpl.f32 s15, #1.000000e+00 */
/* @0x2c47ec vdivpl.f32 s13, s15, s13 */
/* @0x2c47f0 vldr s15, [r8, #12] */
/* @0x2c47f4 vmulpl.f32 s19, s19, s13 */
/* @0x2c47f8 vmulpl.f32 s18, s18, s13 */
/* @0x2c47fc vldr s13, [r8, #4] */
/* @0x2c4800 vmla.f32 s12, s17, s19 */
/* @0x2c4804 vmla.f32 s13, s17, s18 */
/* @0x2c4808 vstr s12, [r8] */
/* @0x2c480c vmls.f32 s14, s16, s19 */
/* @0x2c4810 vstr s13, [r8, #4] */
/* @0x2c4814 vmls.f32 s15, s16, s18 */
/* @0x2c4818 vstr s14, [r8, #8] */
/* @0x2c481c vstr s15, [r8, #12] */
/* @0x2c4820 b 0x2c4570 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x5d0> */
/* @0x2c4824 vmov r0, s12 */
/* @0x2c4828 bl 0xb6700 <sqrtf@plt> */
/* @0x2c482c vmov s13, r0 */
/* @0x2c4830 b 0x2c47d4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x834> */
/* @0x2c4834 vmov r0, s14 */
/* @0x2c4838 bl 0xb6700 <sqrtf@plt> */
/* @0x2c483c ldr r9, [sp, #0x84] */
/* @0x2c4840 vmov s15, r0 */
/* @0x2c4844 b 0x2c4688 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x6e8> */
/* @0x2c4848 vmov r0, s14 */
/* @0x2c484c bl 0xb6700 <sqrtf@plt> */
/* @0x2c4850 vmov s15, r0 */
/* @0x2c4854 b 0x2c44a0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x500> */
/* @0x2c4858 vmov r0, s14 */
/* @0x2c485c bl 0xb6700 <sqrtf@plt> */
/* @0x2c4860 vmov s15, r0 */
/* @0x2c4864 b 0x2c40f4 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput+0x154> */

/* ── FUNC 0x2c4868 · b2ChainShape::GetChildCount() const · size=12 · insn=3 */
/* @0x2c4868 ldr r0, [r0, #0x10] */
/* @0x2c486c sub r0, r0, #1 */
/* @0x2c4870 bx lr */

/* ── FUNC 0x2c4874 · b2ChainShape::TestPoint(b2Transform const&, b2Vec2 const&) const · size=8 · insn=2 */
/* @0x2c4874 mov r0, #0 */
/* @0x2c4878 bx lr */

/* ── FUNC 0x2c487c · b2ChainShape::ComputeAABB(b2AABB*, b2Transform const&, int) const · size=196 · insn=49 */
/* @0x2c487c str r4, [sp, #-0x4]! */
/* @0x2c4880 vldr s11, [r2, #8] */
/* @0x2c4884 add r12, r3, #1 */
/* @0x2c4888 vldr s10, [r2, #12] */
/* @0x2c488c ldr r4, [r0, #0x10] */
/* @0x2c4890 vldr s13, [r2] */
/* @0x2c4894 vldr s8, [r2, #4] */
/* @0x2c4898 cmp r4, r12 */
/* @0x2c489c lslne r4, r12, #3 */
/* @0x2c48a0 ldr r12, [r0, #0xc] */
/* @0x2c48a4 moveq r4, #0 */
/* @0x2c48a8 add r3, r12, r3, lsl #3 */
/* @0x2c48ac add r0, r12, r4 */
/* @0x2c48b0 vldr s14, [r3, #4] */
/* @0x2c48b4 vldr s15, [r0, #4] */
/* @0x2c48b8 vmul.f32 s12, s11, s14 */
/* @0x2c48bc vldr s6, [r3] */
/* @0x2c48c0 vldr s7, [r0] */
/* @0x2c48c4 ldr r4, [sp], #4 */
/* @0x2c48c8 vmul.f32 s9, s11, s15 */
/* @0x2c48cc vmul.f32 s14, s10, s14 */
/* @0x2c48d0 vmul.f32 s15, s10, s15 */
/* @0x2c48d4 vnmls.f32 s12, s10, s6 */
/* @0x2c48d8 vnmls.f32 s9, s10, s7 */
/* @0x2c48dc vmla.f32 s14, s6, s11 */
/* @0x2c48e0 vmla.f32 s15, s11, s7 */
/* @0x2c48e4 vadd.f32 s12, s12, s13 */
/* @0x2c48e8 vadd.f32 s13, s13, s9 */
/* @0x2c48ec vadd.f32 s14, s14, s8 */
/* @0x2c48f0 vadd.f32 s15, s8, s15 */
/* @0x2c48f4 vcmpe.f32 s12, s13 */
/* @0x2c48f8 vmrs APSR_nzcv, fpscr */
/* @0x2c48fc vcmpe.f32 s14, s15 */
/* @0x2c4900 vmovpl.f32 s11, s13 */
/* @0x2c4904 vmovmi.f32 s11, s12 */
/* @0x2c4908 vmrs APSR_nzcv, fpscr */
/* @0x2c490c vstr s11, [r1] */
/* @0x2c4910 vcmpe.f32 s12, s13 */
/* @0x2c4914 vmovpl.f32 s11, s15 */
/* @0x2c4918 vmovmi.f32 s11, s14 */
/* @0x2c491c vmrs APSR_nzcv, fpscr */
/* @0x2c4920 vstr s11, [r1, #4] */
/* @0x2c4924 vcmpe.f32 s14, s15 */
/* @0x2c4928 vmovgt.f32 s13, s12 */
/* @0x2c492c vmrs APSR_nzcv, fpscr */
/* @0x2c4930 vstr s13, [r1, #8] */
/* @0x2c4934 vmovgt.f32 s15, s14 */
/* @0x2c4938 vstr s15, [r1, #12] */
/* @0x2c493c bx lr */

/* ── FUNC 0x2c4940 · b2ChainShape::ComputeMass(b2MassData*, float) const · size=24 · insn=6 */
/* @0x2c4940 mov r3, #0 */
/* @0x2c4944 str r3, [r1] */
/* @0x2c4948 str r3, [r1, #0x4] */
/* @0x2c494c str r3, [r1, #0x8] */
/* @0x2c4950 str r3, [r1, #0xc] */
/* @0x2c4954 bx lr */

/* ── FUNC 0x2c4958 · b2ChainShape::~b2ChainShape() · size=76 · insn=19 */
/* @0x2c4958 ldr r3, [pc, #0x3c] */
/* @0x2c495c push {r4, lr} */
/* @0x2c4960 ldr r3, [pc, r3] */
/* @0x2c4964 mov r4, r0 */
/* @0x2c4968 add r3, r3, #8 */
/* @0x2c496c ldr r0, [r0, #0xc] */
/* @0x2c4970 str r3, [r4] */
/* @0x2c4974 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c4978 ldr r3, [pc, #0x20] */
/* @0x2c497c mov r2, #0 */
/* @0x2c4980 mov r0, r4 */
/* @0x2c4984 ldr r3, [pc, r3] */
/* @0x2c4988 str r2, [r4, #0xc] */
/* @0x2c498c add r3, r3, #8 */
/* @0x2c4990 str r2, [r4, #0x10] */
/* @0x2c4994 str r3, [r4] */
/* @0x2c4998 pop {r4, pc} */
/* @0x2c499c andseq r12, r2, r8, asr r11 */
/* @0x2c49a0 andseq r12, r2, r12, lsl r11 */

/* ── FUNC 0x2c4958 · b2ChainShape::~b2ChainShape() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c49a4 · b2ChainShape::~b2ChainShape() · size=28 · insn=7 */
/* @0x2c49a4 push {r4, lr} */
/* @0x2c49a8 mov r4, r0 */
/* @0x2c49ac bl 0x2c4958 <_ZN12b2ChainShapeD2Ev> */
/* @0x2c49b0 mov r0, r4 */
/* @0x2c49b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2c49b8 mov r0, r4 */
/* @0x2c49bc pop {r4, pc} */

/* ── FUNC 0x2c49c0 · b2ChainShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const · size=168 · insn=42 */
/* @0x2c49c0 push {r4, r5, r6, lr} */
/* @0x2c49c4 sub sp, sp, #56 */
/* @0x2c49c8 ldr lr, [r0, #0x10] */
/* @0x2c49cc mov r5, r1 */
/* @0x2c49d0 ldr r4, [sp, #0x48] */
/* @0x2c49d4 movw r6, #0xd70a */
/* @0x2c49d8 ldr r12, [pc, #0x84] */
/* @0x2c49dc movt r6, #0x3c23 */
/* @0x2c49e0 add r1, r4, #1 */
/* @0x2c49e4 str r6, [sp, #0x10] */
/* @0x2c49e8 cmp lr, r1 */
/* @0x2c49ec mov lr, #1 */
/* @0x2c49f0 str lr, [sp, #0xc] */
/* @0x2c49f4 mov lr, #0 */
/* @0x2c49f8 strb lr, [sp, #0x34] */
/* @0x2c49fc ldr r12, [pc, r12] */
/* @0x2c4a00 strb lr, [sp, #0x35] */
/* @0x2c4a04 lslne lr, r1, #3 */
/* @0x2c4a08 ldr r1, [r0, #0xc] */
/* @0x2c4a0c add r12, r12, #8 */
/* @0x2c4a10 str r12, [sp, #0x8] */
/* @0x2c4a14 mov r12, #0 */
/* @0x2c4a18 add r4, r1, r4, lsl #3 */
/* @0x2c4a1c str r12, [sp, #0x24] */
/* @0x2c4a20 str r12, [sp, #0x28] */
/* @0x2c4a24 add lr, r1, lr */
/* @0x2c4a28 str r12, [sp, #0x2c] */
/* @0x2c4a2c mov r6, #0 */
/* @0x2c4a30 str r12, [sp, #0x30] */
/* @0x2c4a34 add r12, sp, #20 */
/* @0x2c4a38 ldm r4, {r0, r1} */
/* @0x2c4a3c stm r12, {r0, r1} */
/* @0x2c4a40 add r12, sp, #28 */
/* @0x2c4a44 ldm lr, {r0, r1} */
/* @0x2c4a48 str r6, [sp] */
/* @0x2c4a4c stm r12, {r0, r1} */
/* @0x2c4a50 mov r1, r5 */
/* @0x2c4a54 add r0, sp, #8 */
/* @0x2c4a58 bl 0x2c534c <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi> */
/* @0x2c4a5c add sp, sp, #56 */
/* @0x2c4a60 pop {r4, r5, r6, pc} */
/* @0x2c4a64 ldrheq r12, [r2], -r8 */

/* ── FUNC 0x2c4a68 · b2ChainShape::CreateLoop(b2Vec2 const*, int) · size=120 · insn=30 */
/* @0x2c4a68 add r2, r2, #1 */
/* @0x2c4a6c push {r4, r5, r6, r7, r8, lr} */
/* @0x2c4a70 mov r4, r0 */
/* @0x2c4a74 str r2, [r0, #0x10] */
/* @0x2c4a78 lsl r0, r2, #3 */
/* @0x2c4a7c mov r6, r1 */
/* @0x2c4a80 sub r5, r0, #8 */
/* @0x2c4a84 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c4a88 mov r1, r6 */
/* @0x2c4a8c mov r2, r5 */
/* @0x2c4a90 add r7, r4, #20 */
/* @0x2c4a94 str r0, [r4, #0xc] */
/* @0x2c4a98 bl 0xb65bc <memcpy@plt> */
/* @0x2c4a9c ldr r3, [r4, #0xc] */
/* @0x2c4aa0 ldr r8, [r4, #0x10] */
/* @0x2c4aa4 add r12, r4, #28 */
/* @0x2c4aa8 add r5, r3, r5 */
/* @0x2c4aac add r6, r3, #8 */
/* @0x2c4ab0 sub r8, r8, #-536870910 */
/* @0x2c4ab4 ldm r3, {r0, r1} */
/* @0x2c4ab8 mov r2, #1 */
/* @0x2c4abc add r3, r3, r8, lsl #3 */
/* @0x2c4ac0 stm r5, {r0, r1} */
/* @0x2c4ac4 ldm r3, {r0, r1} */
/* @0x2c4ac8 stm r7, {r0, r1} */
/* @0x2c4acc ldm r6, {r0, r1} */
/* @0x2c4ad0 stm r12, {r0, r1} */
/* @0x2c4ad4 strb r2, [r4, #0x24] */
/* @0x2c4ad8 strb r2, [r4, #0x25] */
/* @0x2c4adc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2c4ae0 · b2ChainShape::CreateChain(b2Vec2 const*, int) · size=60 · insn=15 */
/* @0x2c4ae0 push {r3, r4, r5, lr} */
/* @0x2c4ae4 mov r4, r0 */
/* @0x2c4ae8 str r2, [r4, #0x10] */
/* @0x2c4aec lsl r0, r2, #3 */
/* @0x2c4af0 mov r5, r1 */
/* @0x2c4af4 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c4af8 ldr r2, [r4, #0x10] */
/* @0x2c4afc mov r1, r5 */
/* @0x2c4b00 lsl r2, r2, #3 */
/* @0x2c4b04 str r0, [r4, #0xc] */
/* @0x2c4b08 bl 0xb65bc <memcpy@plt> */
/* @0x2c4b0c mov r3, #0 */
/* @0x2c4b10 strb r3, [r4, #0x24] */
/* @0x2c4b14 strb r3, [r4, #0x25] */
/* @0x2c4b18 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2c4b1c · b2ChainShape::Clone(b2BlockAllocator*) const · size=160 · insn=40 */
/* @0x2c4b1c push {r4, r5, r6, lr} */
/* @0x2c4b20 mov r5, r0 */
/* @0x2c4b24 mov r0, r1 */
/* @0x2c4b28 mov r1, #40 */
/* @0x2c4b2c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2c4b30 subs r4, r0, #0 */
/* @0x2c4b34 beq 0x2c4b70 <_ZNK12b2ChainShape5CloneEP16b2BlockAllocator+0x54> */
/* @0x2c4b38 ldr r3, [pc, #0x78] */
/* @0x2c4b3c mov r2, #3 */
/* @0x2c4b40 movw r1, #0xd70a */
/* @0x2c4b44 str r2, [r4, #0x4] */
/* @0x2c4b48 ldr r3, [pc, r3] */
/* @0x2c4b4c movt r1, #0x3c23 */
/* @0x2c4b50 add r2, r3, #8 */
/* @0x2c4b54 str r1, [r4, #0x8] */
/* @0x2c4b58 mov r3, #0 */
/* @0x2c4b5c str r2, [r4] */
/* @0x2c4b60 str r3, [r4, #0xc] */
/* @0x2c4b64 str r3, [r4, #0x10] */
/* @0x2c4b68 strb r3, [r4, #0x24] */
/* @0x2c4b6c strb r3, [r4, #0x25] */
/* @0x2c4b70 mov r0, r4 */
/* @0x2c4b74 ldr r1, [r5, #0xc] */
/* @0x2c4b78 ldr r2, [r5, #0x10] */
/* @0x2c4b7c bl 0x2c4ae0 <_ZN12b2ChainShape11CreateChainEPK6b2Vec2i> */
/* @0x2c4b80 add r3, r5, #20 */
/* @0x2c4b84 add r2, r5, #28 */
/* @0x2c4b88 add r12, r4, #20 */
/* @0x2c4b8c ldm r3, {r0, r1} */
/* @0x2c4b90 add r3, r4, #28 */
/* @0x2c4b94 ldrb r6, [r5, #0x24] */
/* @0x2c4b98 ldrb r5, [r5, #0x25] */
/* @0x2c4b9c stm r12, {r0, r1} */
/* @0x2c4ba0 ldm r2, {r0, r1} */
/* @0x2c4ba4 stm r3, {r0, r1} */
/* @0x2c4ba8 mov r0, r4 */
/* @0x2c4bac strb r6, [r4, #0x24] */
/* @0x2c4bb0 strb r5, [r4, #0x25] */
/* @0x2c4bb4 pop {r4, r5, r6, pc} */
/* @0x2c4bb8 andseq r12, r2, r0, ror r9 */

/* ── FUNC 0x2c4bbc · b2ChainShape::SetPrevVertex(b2Vec2 const&) · size=28 · insn=7 */
/* @0x2c4bbc mov r3, r0 */
/* @0x2c4bc0 ldm r1, {r0, r1} */
/* @0x2c4bc4 add r2, r3, #20 */
/* @0x2c4bc8 mov r12, #1 */
/* @0x2c4bcc stm r2, {r0, r1} */
/* @0x2c4bd0 strb r12, [r3, #0x24] */
/* @0x2c4bd4 bx lr */

/* ── FUNC 0x2c4bd8 · b2ChainShape::SetNextVertex(b2Vec2 const&) · size=28 · insn=7 */
/* @0x2c4bd8 mov r3, r0 */
/* @0x2c4bdc ldm r1, {r0, r1} */
/* @0x2c4be0 add r2, r3, #28 */
/* @0x2c4be4 mov r12, #1 */
/* @0x2c4be8 stm r2, {r0, r1} */
/* @0x2c4bec strb r12, [r3, #0x25] */
/* @0x2c4bf0 bx lr */

/* ── FUNC 0x2c4bf4 · b2ChainShape::GetChildEdge(b2EdgeShape*, int) const · size=176 · insn=44 */
/* @0x2c4bf4 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2c4bf8 mov r3, r1 */
/* @0x2c4bfc ldr r10, [r0, #0xc] */
/* @0x2c4c00 lsl r9, r2, #3 */
/* @0x2c4c04 add r7, r1, #12 */
/* @0x2c4c08 ldr r1, [r0, #0x8] */
/* @0x2c4c0c add r4, r10, r9 */
/* @0x2c4c10 mov r12, r0 */
/* @0x2c4c14 add r6, r4, #8 */
/* @0x2c4c18 mov r8, #1 */
/* @0x2c4c1c str r1, [r3, #0x8] */
/* @0x2c4c20 add r5, r3, #20 */
/* @0x2c4c24 ldm r4, {r0, r1} */
/* @0x2c4c28 cmp r2, #0 */
/* @0x2c4c2c str r8, [r3, #0x4] */
/* @0x2c4c30 addle r4, r3, #28 */
/* @0x2c4c34 stm r7, {r0, r1} */
/* @0x2c4c38 ldm r6, {r0, r1} */
/* @0x2c4c3c stm r5, {r0, r1} */
/* @0x2c4c40 addle r1, r12, #20 */
/* @0x2c4c44 ldmdbgt r4, {r0, r1} */
/* @0x2c4c48 addgt r4, r3, #28 */
/* @0x2c4c4c ldmle r1, {r0, r1} */
/* @0x2c4c50 ldrble r5, [r12, #0x24] */
/* @0x2c4c54 stmgt r4, {r0, r1} */
/* @0x2c4c58 stmle r4, {r0, r1} */
/* @0x2c4c5c ldr r1, [r12, #0x10] */
/* @0x2c4c60 strbgt r8, [r3, #0x2c] */
/* @0x2c4c64 sub r1, r1, #2 */
/* @0x2c4c68 strble r5, [r3, #0x2c] */
/* @0x2c4c6c cmp r2, r1 */
/* @0x2c4c70 addlt r9, r10, r9 */
/* @0x2c4c74 addge r1, r12, #28 */
/* @0x2c4c78 addlt r9, r9, #16 */
/* @0x2c4c7c ldrbge r12, [r12, #0x25] */
/* @0x2c4c80 ldmge r1, {r0, r1} */
/* @0x2c4c84 addlt r2, r3, #36 */
/* @0x2c4c88 ldmlt r9, {r0, r1} */
/* @0x2c4c8c addge r2, r3, #36 */
/* @0x2c4c90 movlt r12, #1 */
/* @0x2c4c94 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2c4c98 stm r2, {r0, r1} */
/* @0x2c4c9c strb r12, [r3, #0x2d] */
/* @0x2c4ca0 bx lr */

/* ── FUNC 0x2c4ca4 · b2ChainShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const · size=148 · insn=37 */
/* @0x2c4ca4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c4ca8 sub sp, sp, #60 */
/* @0x2c4cac add r5, sp, #8 */
/* @0x2c4cb0 ldr r12, [pc, #0x7c] */
/* @0x2c4cb4 ldr r6, [sp, #0x58] */
/* @0x2c4cb8 mov r8, r1 */
/* @0x2c4cbc mov r7, r2 */
/* @0x2c4cc0 mov r9, r3 */
/* @0x2c4cc4 mov r1, r5 */
/* @0x2c4cc8 ldr r2, [sp, #0x5c] */
/* @0x2c4ccc ldr r12, [pc, r12] */
/* @0x2c4cd0 mov r4, #0 */
/* @0x2c4cd4 add r12, r12, #8 */
/* @0x2c4cd8 mov r3, #1 */
/* @0x2c4cdc str r12, [sp, #0x8] */
/* @0x2c4ce0 mov r12, #0 */
/* @0x2c4ce4 str r3, [sp, #0xc] */
/* @0x2c4ce8 movw r3, #0xd70a */
/* @0x2c4cec str r12, [sp, #0x24] */
/* @0x2c4cf0 movt r3, #0x3c23 */
/* @0x2c4cf4 str r12, [sp, #0x28] */
/* @0x2c4cf8 str r3, [sp, #0x10] */
/* @0x2c4cfc str r12, [sp, #0x2c] */
/* @0x2c4d00 str r12, [sp, #0x30] */
/* @0x2c4d04 strb r4, [sp, #0x34] */
/* @0x2c4d08 strb r4, [sp, #0x35] */
/* @0x2c4d0c bl 0x2c4bf4 <_ZNK12b2ChainShape12GetChildEdgeEP11b2EdgeShapei> */
/* @0x2c4d10 str r6, [sp] */
/* @0x2c4d14 mov r0, r5 */
/* @0x2c4d18 str r4, [sp, #0x4] */
/* @0x2c4d1c mov r1, r8 */
/* @0x2c4d20 mov r2, r7 */
/* @0x2c4d24 mov r3, r9 */
/* @0x2c4d28 bl 0x2c54fc <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i> */
/* @0x2c4d2c add sp, sp, #60 */
/* @0x2c4d30 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c4d34 andseq r12, r2, r8, ror #15 */

/* ── FUNC 0x2c4d38 · b2CircleShape::GetChildCount() const · size=8 · insn=2 */
/* @0x2c4d38 mov r0, #1 */
/* @0x2c4d3c bx lr */

/* ── FUNC 0x2c4d40 · b2CircleShape::TestPoint(b2Transform const&, b2Vec2 const&) const · size=100 · insn=25 */
/* @0x2c4d40 vldr s8, [r0, #16] */
/* @0x2c4d44 vldr s10, [r1, #12] */
/* @0x2c4d48 vmul.f32 s13, s10, s8 */
/* @0x2c4d4c vldr s11, [r0, #12] */
/* @0x2c4d50 vldr s9, [r1, #8] */
/* @0x2c4d54 vldr s5, [r1, #4] */
/* @0x2c4d58 vldr s15, [r2, #4] */
/* @0x2c4d5c vldr s6, [r1] */
/* @0x2c4d60 vldr s7, [r2] */
/* @0x2c4d64 vldr s12, [r0, #8] */
/* @0x2c4d68 vmul.f32 s14, s9, s8 */
/* @0x2c4d6c vmla.f32 s13, s11, s9 */
/* @0x2c4d70 vnmls.f32 s14, s10, s11 */
/* @0x2c4d74 vadd.f32 s13, s13, s5 */
/* @0x2c4d78 vsub.f32 s15, s15, s13 */
/* @0x2c4d7c vadd.f32 s14, s14, s6 */
/* @0x2c4d80 vmul.f32 s15, s15, s15 */
/* @0x2c4d84 vsub.f32 s14, s7, s14 */
/* @0x2c4d88 vmla.f32 s15, s14, s14 */
/* @0x2c4d8c vmul.f32 s12, s12, s12 */
/* @0x2c4d90 vcmpe.f32 s12, s15 */
/* @0x2c4d94 vmrs APSR_nzcv, fpscr */
/* @0x2c4d98 movlt r0, #0 */
/* @0x2c4d9c movge r0, #1 */
/* @0x2c4da0 bx lr */

/* ── FUNC 0x2c4da4 · b2CircleShape::ComputeAABB(b2AABB*, b2Transform const&, int) const · size=88 · insn=22 */
/* @0x2c4da4 vldr s11, [r2, #12] */
/* @0x2c4da8 vldr s9, [r0, #16] */
/* @0x2c4dac vldr s10, [r2, #8] */
/* @0x2c4db0 vmul.f32 s13, s11, s9 */
/* @0x2c4db4 vldr s12, [r0, #12] */
/* @0x2c4db8 vldr s8, [r2] */
/* @0x2c4dbc vldr s7, [r2, #4] */
/* @0x2c4dc0 vldr s15, [r0, #8] */
/* @0x2c4dc4 vmul.f32 s14, s10, s9 */
/* @0x2c4dc8 vmla.f32 s13, s12, s10 */
/* @0x2c4dcc vnmls.f32 s14, s11, s12 */
/* @0x2c4dd0 vadd.f32 s13, s13, s7 */
/* @0x2c4dd4 vadd.f32 s14, s14, s8 */
/* @0x2c4dd8 vsub.f32 s11, s13, s15 */
/* @0x2c4ddc vsub.f32 s12, s14, s15 */
/* @0x2c4de0 vstr s11, [r1, #4] */
/* @0x2c4de4 vadd.f32 s14, s15, s14 */
/* @0x2c4de8 vstr s12, [r1] */
/* @0x2c4dec vadd.f32 s13, s15, s13 */
/* @0x2c4df0 vstr s14, [r1, #8] */
/* @0x2c4df4 vstr s13, [r1, #12] */
/* @0x2c4df8 bx lr */

/* ── FUNC 0x2c4dfc · b2CircleShape::ComputeMass(b2MassData*, float) const · size=96 · insn=24 */
/* @0x2c4dfc vmov s15, r2 */
/* @0x2c4e00 vldr s13, [pc, #80] */
/* @0x2c4e04 vldr s14, [r0, #8] */
/* @0x2c4e08 mov r3, r0 */
/* @0x2c4e0c vmul.f32 s13, s15, s13 */
/* @0x2c4e10 add r0, r0, #12 */
/* @0x2c4e14 mov r2, r1 */
/* @0x2c4e18 mov r12, r1 */
/* @0x2c4e1c ldm r0, {r0, r1} */
/* @0x2c4e20 vmul.f32 s13, s13, s14 */
/* @0x2c4e24 vmul.f32 s13, s14, s13 */
/* @0x2c4e28 vstmia r2!, {s13} */
/* @0x2c4e2c stm r2, {r0, r1} */
/* @0x2c4e30 vldr s15, [r3, #16] */
/* @0x2c4e34 vmul.f32 s15, s15, s15 */
/* @0x2c4e38 vldr s12, [r3, #12] */
/* @0x2c4e3c vmov.f32 s11, #5.000000e-01 */
/* @0x2c4e40 vmla.f32 s15, s12, s12 */
/* @0x2c4e44 vmul.f32 s12, s14, s11 */
/* @0x2c4e48 vmla.f32 s15, s14, s12 */
/* @0x2c4e4c vmul.f32 s15, s13, s15 */
/* @0x2c4e50 vstr s15, [r12, #12] */
/* @0x2c4e54 bx lr */
/* @0x2c4e58 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x2c4e5c · b2CircleShape::~b2CircleShape() · size=24 · insn=6 */
/* @0x2c4e5c ldr r3, [pc, #0xc] */
/* @0x2c4e60 ldr r3, [pc, r3] */
/* @0x2c4e64 add r3, r3, #8 */
/* @0x2c4e68 str r3, [r0] */
/* @0x2c4e6c bx lr */
/* @0x2c4e70 andseq r12, r2, r0, asr #12 */

/* ── FUNC 0x2c4e5c · b2CircleShape::~b2CircleShape() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c4e74 · b2CircleShape::~b2CircleShape() · size=40 · insn=10 */
/* @0x2c4e74 ldr r3, [pc, #0x1c] */
/* @0x2c4e78 push {r4, lr} */
/* @0x2c4e7c ldr r3, [pc, r3] */
/* @0x2c4e80 mov r4, r0 */
/* @0x2c4e84 add r3, r3, #8 */
/* @0x2c4e88 str r3, [r0] */
/* @0x2c4e8c bl 0x27d1d0 <_ZdlPv> */
/* @0x2c4e90 mov r0, r4 */
/* @0x2c4e94 pop {r4, pc} */
/* @0x2c4e98 andseq r12, r2, r4, lsr #12 */
