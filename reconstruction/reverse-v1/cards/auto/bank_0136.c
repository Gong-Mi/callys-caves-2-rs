/* libyoyo.so 覆盖卡组 0136
 * 函数 0x1a33b4..0x1a4660，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a33b4 · ParticleType_Direction(int, float, float, float, float) · size=76 · insn=19 */
/* @0x1a33b4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a33b8 mov r7, r1 */
/* @0x1a33bc mov r6, r2 */
/* @0x1a33c0 mov r4, r0 */
/* @0x1a33c4 mov r5, r3 */
/* @0x1a33c8 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a33cc cmp r0, #0 */
/* @0x1a33d0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a33d4 ldr r12, [pc, #0x20] */
/* @0x1a33d8 vldr s15, [sp, #24] */
/* @0x1a33dc ldr r12, [pc, r12] */
/* @0x1a33e0 ldr r3, [r12, #0x4] */
/* @0x1a33e4 ldr r0, [r3, r4, lsl #2] */
/* @0x1a33e8 vstr s15, [r0, #88] */
/* @0x1a33ec str r7, [r0, #0x4c] */
/* @0x1a33f0 str r6, [r0, #0x50] */
/* @0x1a33f4 str r5, [r0, #0x54] */
/* @0x1a33f8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a33fc .word 0x0024d3d0 */

/* ── FUNC 0x1a3400 · ParticleType_Orientation(int, float, float, float, float, bool) · size=84 · insn=21 */
/* @0x1a3400 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a3404 mov r8, r1 */
/* @0x1a3408 mov r7, r2 */
/* @0x1a340c mov r5, r0 */
/* @0x1a3410 mov r6, r3 */
/* @0x1a3414 ldrb r4, [sp, #0x1c] */
/* @0x1a3418 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a341c cmp r0, #0 */
/* @0x1a3420 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a3424 ldr r12, [pc, #0x24] */
/* @0x1a3428 vldr s15, [sp, #24] */
/* @0x1a342c ldr r12, [pc, r12] */
/* @0x1a3430 ldr r3, [r12, #0x4] */
/* @0x1a3434 ldr r0, [r3, r5, lsl #2] */
/* @0x1a3438 vstr s15, [r0, #112] */
/* @0x1a343c str r8, [r0, #0x64] */
/* @0x1a3440 str r7, [r0, #0x68] */
/* @0x1a3444 str r6, [r0, #0x6c] */
/* @0x1a3448 strb r4, [r0, #0x74] */
/* @0x1a344c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3450 eoreq sp, r4, r0, lsl #7 */

/* ── FUNC 0x1a3454 · ParticleType_Gravity(int, float, float) · size=60 · insn=15 */
/* @0x1a3454 push {r4, r5, r6, lr} */
/* @0x1a3458 mov r6, r1 */
/* @0x1a345c mov r4, r0 */
/* @0x1a3460 mov r5, r2 */
/* @0x1a3464 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3468 cmp r0, #0 */
/* @0x1a346c popeq {r4, r5, r6, pc} */
/* @0x1a3470 ldr r3, [pc, #0x14] */
/* @0x1a3474 ldr r3, [pc, r3] */
/* @0x1a3478 ldr r3, [r3, #0x4] */
/* @0x1a347c ldr r3, [r3, r4, lsl #2] */
/* @0x1a3480 str r6, [r3, #0x5c] */
/* @0x1a3484 str r5, [r3, #0x60] */
/* @0x1a3488 pop {r4, r5, r6, pc} */
/* @0x1a348c eoreq sp, r4, r8, lsr r3 */

/* ── FUNC 0x1a3490 · ParticleType_Color_RGB(int, int, int, int, int, int, int) · size=100 · insn=25 */
/* @0x1a3490 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a3494 mov r7, r1 */
/* @0x1a3498 mov r6, r2 */
/* @0x1a349c mov r5, r3 */
/* @0x1a34a0 mov r4, r0 */
/* @0x1a34a4 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a34a8 cmp r0, #0 */
/* @0x1a34ac popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a34b0 ldr r12, [pc, #0x38] */
/* @0x1a34b4 mov r3, #3 */
/* @0x1a34b8 ldr r12, [pc, r12] */
/* @0x1a34bc ldr r2, [r12, #0x4] */
/* @0x1a34c0 ldr r0, [r2, r4, lsl #2] */
/* @0x1a34c4 ldr r2, [sp, #0x18] */
/* @0x1a34c8 str r7, [r0, #0x7c] */
/* @0x1a34cc str r2, [r0, #0x88] */
/* @0x1a34d0 ldr r2, [sp, #0x1c] */
/* @0x1a34d4 str r6, [r0, #0x80] */
/* @0x1a34d8 str r5, [r0, #0x84] */
/* @0x1a34dc str r2, [r0, #0x8c] */
/* @0x1a34e0 ldr r2, [sp, #0x20] */
/* @0x1a34e4 str r3, [r0, #0x78] */
/* @0x1a34e8 str r2, [r0, #0x90] */
/* @0x1a34ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a34f0 .word 0x0024d2f4 */

/* ── FUNC 0x1a34f4 · ParticleType_Color_Mix(int, unsigned int, unsigned int) · size=68 · insn=17 */
/* @0x1a34f4 push {r4, r5, r6, lr} */
/* @0x1a34f8 mov r6, r1 */
/* @0x1a34fc mov r5, r2 */
/* @0x1a3500 mov r4, r0 */
/* @0x1a3504 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3508 cmp r0, #0 */
/* @0x1a350c popeq {r4, r5, r6, pc} */
/* @0x1a3510 ldr r3, [pc, #0x1c] */
/* @0x1a3514 mov r2, #5 */
/* @0x1a3518 ldr r3, [pc, r3] */
/* @0x1a351c ldr r3, [r3, #0x4] */
/* @0x1a3520 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3524 str r6, [r3, #0x7c] */
/* @0x1a3528 str r5, [r3, #0x80] */
/* @0x1a352c str r2, [r3, #0x78] */
/* @0x1a3530 pop {r4, r5, r6, pc} */
/* @0x1a3534 mlaeq r4, r4, r2, sp */

/* ── FUNC 0x1a3538 · ParticleType_Color_HSV(int, int, int, int, int, int, int) · size=100 · insn=25 */
/* @0x1a3538 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a353c mov r7, r1 */
/* @0x1a3540 mov r6, r2 */
/* @0x1a3544 mov r5, r3 */
/* @0x1a3548 mov r4, r0 */
/* @0x1a354c bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3550 cmp r0, #0 */
/* @0x1a3554 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a3558 ldr r12, [pc, #0x38] */
/* @0x1a355c mov r3, #4 */
/* @0x1a3560 ldr r12, [pc, r12] */
/* @0x1a3564 ldr r2, [r12, #0x4] */
/* @0x1a3568 ldr r0, [r2, r4, lsl #2] */
/* @0x1a356c ldr r2, [sp, #0x18] */
/* @0x1a3570 str r7, [r0, #0x7c] */
/* @0x1a3574 str r2, [r0, #0x88] */
/* @0x1a3578 ldr r2, [sp, #0x1c] */
/* @0x1a357c str r6, [r0, #0x80] */
/* @0x1a3580 str r5, [r0, #0x84] */
/* @0x1a3584 str r2, [r0, #0x8c] */
/* @0x1a3588 ldr r2, [sp, #0x20] */
/* @0x1a358c str r3, [r0, #0x78] */
/* @0x1a3590 str r2, [r0, #0x90] */
/* @0x1a3594 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a3598 eoreq sp, r4, r12, asr #4 */

/* ── FUNC 0x1a359c · ParticleType_Color1(int, unsigned int) · size=60 · insn=15 */
/* @0x1a359c push {r3, r4, r5, lr} */
/* @0x1a35a0 mov r5, r1 */
/* @0x1a35a4 mov r4, r0 */
/* @0x1a35a8 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a35ac cmp r0, #0 */
/* @0x1a35b0 popeq {r3, r4, r5, pc} */
/* @0x1a35b4 ldr r3, [pc, #0x18] */
/* @0x1a35b8 mov r2, #0 */
/* @0x1a35bc ldr r3, [pc, r3] */
/* @0x1a35c0 ldr r3, [r3, #0x4] */
/* @0x1a35c4 ldr r3, [r3, r4, lsl #2] */
/* @0x1a35c8 str r5, [r3, #0x7c] */
/* @0x1a35cc str r2, [r3, #0x78] */
/* @0x1a35d0 pop {r3, r4, r5, pc} */
/* @0x1a35d4 .word 0x0024d1f0 */

/* ── FUNC 0x1a35d8 · ParticleType_Color2(int, unsigned int, unsigned int) · size=68 · insn=17 */
/* @0x1a35d8 push {r4, r5, r6, lr} */
/* @0x1a35dc mov r6, r1 */
/* @0x1a35e0 mov r5, r2 */
/* @0x1a35e4 mov r4, r0 */
/* @0x1a35e8 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a35ec cmp r0, #0 */
/* @0x1a35f0 popeq {r4, r5, r6, pc} */
/* @0x1a35f4 ldr r3, [pc, #0x1c] */
/* @0x1a35f8 mov r2, #1 */
/* @0x1a35fc ldr r3, [pc, r3] */
/* @0x1a3600 ldr r3, [r3, #0x4] */
/* @0x1a3604 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3608 str r6, [r3, #0x7c] */
/* @0x1a360c str r5, [r3, #0x80] */
/* @0x1a3610 str r2, [r3, #0x78] */
/* @0x1a3614 pop {r4, r5, r6, pc} */
/* @0x1a3618 .word 0x0024d1b0 */

/* ── FUNC 0x1a361c · ParticleType_Color3(int, unsigned int, unsigned int, unsigned int) · size=76 · insn=19 */
/* @0x1a361c push {r3, r4, r5, r6, r7, lr} */
/* @0x1a3620 mov r7, r1 */
/* @0x1a3624 mov r6, r2 */
/* @0x1a3628 mov r5, r3 */
/* @0x1a362c mov r4, r0 */
/* @0x1a3630 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3634 cmp r0, #0 */
/* @0x1a3638 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a363c ldr r12, [pc, #0x20] */
/* @0x1a3640 mov r3, #2 */
/* @0x1a3644 ldr r12, [pc, r12] */
/* @0x1a3648 ldr r2, [r12, #0x4] */
/* @0x1a364c ldr r0, [r2, r4, lsl #2] */
/* @0x1a3650 str r7, [r0, #0x7c] */
/* @0x1a3654 str r6, [r0, #0x80] */
/* @0x1a3658 str r5, [r0, #0x84] */
/* @0x1a365c str r3, [r0, #0x78] */
/* @0x1a3660 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a3664 eoreq sp, r4, r8, ror #2 */

/* ── FUNC 0x1a3668 · ParticleType_Alpha1(int, float) · size=60 · insn=15 */
/* @0x1a3668 push {r3, r4, r5, lr} */
/* @0x1a366c mov r4, r1 */
/* @0x1a3670 mov r5, r0 */
/* @0x1a3674 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3678 cmp r0, #0 */
/* @0x1a367c popeq {r3, r4, r5, pc} */
/* @0x1a3680 ldr r3, [pc, #0x18] */
/* @0x1a3684 ldr r3, [pc, r3] */
/* @0x1a3688 ldr r3, [r3, #0x4] */
/* @0x1a368c ldr r3, [r3, r5, lsl #2] */
/* @0x1a3690 str r4, [r3, #0x94] */
/* @0x1a3694 str r4, [r3, #0x98] */
/* @0x1a3698 str r4, [r3, #0x9c] */
/* @0x1a369c pop {r3, r4, r5, pc} */
/* @0x1a36a0 eoreq sp, r4, r8, lsr #2 */

/* ── FUNC 0x1a36a4 · ParticleType_Alpha2(int, float, float) · size=84 · insn=21 */
/* @0x1a36a4 push {r4, lr} */
/* @0x1a36a8 vpush {d8} */
/* @0x1a36ac mov r4, r0 */
/* @0x1a36b0 vmov s17, r1 */
/* @0x1a36b4 vmov s16, r2 */
/* @0x1a36b8 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a36bc cmp r0, #0 */
/* @0x1a36c0 beq 0x1a36ec <_Z19ParticleType_Alpha2iff+0x48> */
/* @0x1a36c4 vadd.f32 s14, s17, s16 */
/* @0x1a36c8 ldr r3, [pc, #0x24] */
/* @0x1a36cc ldr r3, [pc, r3] */
/* @0x1a36d0 ldr r3, [r3, #0x4] */
/* @0x1a36d4 ldr r3, [r3, r4, lsl #2] */
/* @0x1a36d8 vstr s17, [r3, #148] */
/* @0x1a36dc vstr s16, [r3, #156] */
/* @0x1a36e0 vmov.f32 s15, #5.000000e-01 */
/* @0x1a36e4 vmul.f32 s15, s14, s15 */
/* @0x1a36e8 vstr s15, [r3, #152] */
/* @0x1a36ec vpop {d8} */
/* @0x1a36f0 pop {r4, pc} */
/* @0x1a36f4 eoreq sp, r4, r0, ror #1 */

/* ── FUNC 0x1a36f8 · ParticleType_Alpha3(int, float, float, float) · size=68 · insn=17 */
/* @0x1a36f8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a36fc mov r7, r1 */
/* @0x1a3700 mov r4, r0 */
/* @0x1a3704 mov r6, r2 */
/* @0x1a3708 mov r5, r3 */
/* @0x1a370c bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3710 cmp r0, #0 */
/* @0x1a3714 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a3718 ldr r12, [pc, #0x18] */
/* @0x1a371c ldr r12, [pc, r12] */
/* @0x1a3720 ldr r3, [r12, #0x4] */
/* @0x1a3724 ldr r0, [r3, r4, lsl #2] */
/* @0x1a3728 str r7, [r0, #0x94] */
/* @0x1a372c str r6, [r0, #0x98] */
/* @0x1a3730 str r5, [r0, #0x9c] */
/* @0x1a3734 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a3738 mlaeq r4, r0, r0, sp */

/* ── FUNC 0x1a373c · ParticleType_Blend(int, bool) · size=52 · insn=13 */
/* @0x1a373c push {r3, r4, r5, lr} */
/* @0x1a3740 mov r5, r1 */
/* @0x1a3744 mov r4, r0 */
/* @0x1a3748 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a374c cmp r0, #0 */
/* @0x1a3750 popeq {r3, r4, r5, pc} */
/* @0x1a3754 ldr r3, [pc, #0x10] */
/* @0x1a3758 ldr r3, [pc, r3] */
/* @0x1a375c ldr r3, [r3, #0x4] */
/* @0x1a3760 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3764 strb r5, [r3, #0xa0] */
/* @0x1a3768 pop {r3, r4, r5, pc} */
/* @0x1a376c eoreq sp, r4, r4, asr r0 */

/* ── FUNC 0x1a3770 · ParticleSystem_Exists(int) · size=72 · insn=18 */
/* @0x1a3770 cmp r0, #0 */
/* @0x1a3774 blt 0x1a37a8 <_Z21ParticleSystem_Existsi+0x38> */
/* @0x1a3778 ldr r3, [pc, #0x30] */
/* @0x1a377c ldr r3, [pc, r3] */
/* @0x1a3780 ldr r3, [r3] */
/* @0x1a3784 cmp r0, r3 */
/* @0x1a3788 bge 0x1a37a8 <_Z21ParticleSystem_Existsi+0x38> */
/* @0x1a378c ldr r3, [pc, #0x20] */
/* @0x1a3790 ldr r3, [pc, r3] */
/* @0x1a3794 ldr r3, [r3, #0x4] */
/* @0x1a3798 ldr r0, [r3, r0, lsl #2] */
/* @0x1a379c adds r0, r0, #0 */
/* @0x1a37a0 movne r0, #1 */
/* @0x1a37a4 bx lr */
/* @0x1a37a8 mov r0, #0 */
/* @0x1a37ac bx lr */
/* @0x1a37b0 eoreq sp, r4, r8, lsr r0 */
/* @0x1a37b4 eoreq sp, r4, r8, lsr #32 */

/* ── FUNC 0x1a37b8 · ParticleSystem_Emitter_DestroyAll(int) · size=156 · insn=39 */
/* @0x1a37b8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a37bc mov r8, r0 */
/* @0x1a37c0 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a37c4 cmp r0, #0 */
/* @0x1a37c8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a37cc ldr r5, [pc, #0x7c] */
/* @0x1a37d0 lsl r6, r8, #2 */
/* @0x1a37d4 ldr r5, [pc, r5] */
/* @0x1a37d8 ldr r3, [r5, #0x4] */
/* @0x1a37dc ldr r3, [r3, r8, lsl #2] */
/* @0x1a37e0 ldr r2, [r3, #0xc] */
/* @0x1a37e4 cmp r2, #0 */
/* @0x1a37e8 ble 0x1a3828 <_Z33ParticleSystem_Emitter_DestroyAlli+0x70> */
/* @0x1a37ec mov r4, #0 */
/* @0x1a37f0 mov r7, r4 */
/* @0x1a37f4 ldr r3, [r3, #0x10] */
/* @0x1a37f8 ldr r0, [r3, r4, lsl #2] */
/* @0x1a37fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a3800 ldr r3, [r5, #0x4] */
/* @0x1a3804 ldr r3, [r3, r6] */
/* @0x1a3808 ldr r3, [r3, #0x10] */
/* @0x1a380c str r7, [r3, r4, lsl #2] */
/* @0x1a3810 add r4, r4, #1 */
/* @0x1a3814 ldr r3, [r5, #0x4] */
/* @0x1a3818 ldr r3, [r3, r6] */
/* @0x1a381c ldr r2, [r3, #0xc] */
/* @0x1a3820 cmp r2, r4 */
/* @0x1a3824 bgt 0x1a37f4 <_Z33ParticleSystem_Emitter_DestroyAlli+0x3c> */
/* @0x1a3828 ldr r0, [r3, #0x10] */
/* @0x1a382c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a3830 ldr r2, [r5, #0x4] */
/* @0x1a3834 mov r3, #0 */
/* @0x1a3838 ldr r1, [r2, r8, lsl #2] */
/* @0x1a383c str r3, [r1, #0x10] */
/* @0x1a3840 ldr r2, [r2, r8, lsl #2] */
/* @0x1a3844 str r3, [r2, #0xc] */
/* @0x1a3848 str r3, [r2, #0x14] */
/* @0x1a384c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3850 eoreq r12, r4, r4, ror #31 */

/* ── FUNC 0x1a3854 · ParticleSystem_Emitter_Exists(int, int) · size=88 · insn=22 */
/* @0x1a3854 push {r3, r4, r5, lr} */
/* @0x1a3858 mov r4, r1 */
/* @0x1a385c mov r5, r0 */
/* @0x1a3860 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a3864 cmp r0, #0 */
/* @0x1a3868 popeq {r3, r4, r5, pc} */
/* @0x1a386c cmp r4, #0 */
/* @0x1a3870 blt 0x1a38a0 <_Z29ParticleSystem_Emitter_Existsii+0x4c> */
/* @0x1a3874 ldr r3, [pc, #0x2c] */
/* @0x1a3878 ldr r3, [pc, r3] */
/* @0x1a387c ldr r3, [r3, #0x4] */
/* @0x1a3880 ldr r3, [r3, r5, lsl #2] */
/* @0x1a3884 ldr r2, [r3, #0x14] */
/* @0x1a3888 cmp r4, r2 */
/* @0x1a388c bge 0x1a38a0 <_Z29ParticleSystem_Emitter_Existsii+0x4c> */
/* @0x1a3890 ldr r3, [r3, #0x10] */
/* @0x1a3894 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3898 ldrb r0, [r3] */
/* @0x1a389c pop {r3, r4, r5, pc} */
/* @0x1a38a0 mov r0, #0 */
/* @0x1a38a4 pop {r3, r4, r5, pc} */
/* @0x1a38a8 eoreq r12, r4, r0, asr #30 */

/* ── FUNC 0x1a38ac · ParticleSystem_Emitter_Destroy(int, int) · size=64 · insn=16 */
/* @0x1a38ac push {r3, r4, r5, lr} */
/* @0x1a38b0 mov r5, r0 */
/* @0x1a38b4 mov r4, r1 */
/* @0x1a38b8 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii> */
/* @0x1a38bc cmp r0, #0 */
/* @0x1a38c0 popeq {r3, r4, r5, pc} */
/* @0x1a38c4 ldr r3, [pc, #0x1c] */
/* @0x1a38c8 mov r2, #0 */
/* @0x1a38cc ldr r3, [pc, r3] */
/* @0x1a38d0 ldr r3, [r3, #0x4] */
/* @0x1a38d4 ldr r3, [r3, r5, lsl #2] */
/* @0x1a38d8 ldr r3, [r3, #0x10] */
/* @0x1a38dc ldr r3, [r3, r4, lsl #2] */
/* @0x1a38e0 strb r2, [r3] */
/* @0x1a38e4 pop {r3, r4, r5, pc} */
/* @0x1a38e8 eoreq r12, r4, r12, ror #29 */

/* ── FUNC 0x1a38ec · ParticleSystem_Emitter_Clear(int, int) · size=96 · insn=24 */
/* @0x1a38ec push {r3, r4, r5, lr} */
/* @0x1a38f0 mov r5, r0 */
/* @0x1a38f4 mov r4, r1 */
/* @0x1a38f8 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii> */
/* @0x1a38fc cmp r0, #0 */
/* @0x1a3900 popeq {r3, r4, r5, pc} */
/* @0x1a3904 ldr r3, [pc, #0x3c] */
/* @0x1a3908 mov r2, #0 */
/* @0x1a390c mov r12, #0 */
/* @0x1a3910 ldr r3, [pc, r3] */
/* @0x1a3914 ldr r3, [r3, #0x4] */
/* @0x1a3918 ldr r3, [r3, r5, lsl #2] */
/* @0x1a391c ldr r3, [r3, #0x10] */
/* @0x1a3920 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3924 str r12, [r3, #0x8] */
/* @0x1a3928 str r12, [r3, #0xc] */
/* @0x1a392c str r12, [r3, #0x10] */
/* @0x1a3930 str r12, [r3, #0x14] */
/* @0x1a3934 str r2, [r3, #0x4] */
/* @0x1a3938 str r2, [r3, #0x20] */
/* @0x1a393c str r2, [r3, #0x1c] */
/* @0x1a3940 str r2, [r3, #0x18] */
/* @0x1a3944 pop {r3, r4, r5, pc} */
/* @0x1a3948 eoreq r12, r4, r8, lsr #29 */

/* ── FUNC 0x1a394c · ParticleSystem_Emitter_Region(int, int, float, float, float, float, int, int) · size=104 · insn=26 */
/* @0x1a394c push {r3, r4, r5, r6, r7, lr} */
/* @0x1a3950 mov r7, r2 */
/* @0x1a3954 mov r6, r3 */
/* @0x1a3958 mov r5, r0 */
/* @0x1a395c mov r4, r1 */
/* @0x1a3960 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii> */
/* @0x1a3964 cmp r0, #0 */
/* @0x1a3968 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a396c ldr r12, [pc, #0x3c] */
/* @0x1a3970 vldr s15, [sp, #24] */
/* @0x1a3974 ldr r12, [pc, r12] */
/* @0x1a3978 ldr r3, [r12, #0x4] */
/* @0x1a397c ldr r3, [r3, r5, lsl #2] */
/* @0x1a3980 ldr r3, [r3, #0x10] */
/* @0x1a3984 ldr r1, [r3, r4, lsl #2] */
/* @0x1a3988 vstr s15, [r1, #16] */
/* @0x1a398c ldr r3, [sp, #0x20] */
/* @0x1a3990 vldr s15, [sp, #28] */
/* @0x1a3994 vstr s15, [r1, #20] */
/* @0x1a3998 str r7, [r1, #0x8] */
/* @0x1a399c str r3, [r1, #0x1c] */
/* @0x1a39a0 ldr r3, [sp, #0x24] */
/* @0x1a39a4 str r6, [r1, #0xc] */
/* @0x1a39a8 str r3, [r1, #0x18] */
/* @0x1a39ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a39b0 eoreq r12, r4, r4, asr #28 */

/* ── FUNC 0x1a39b4 · ParticleSystem_Emitter_Create(int) · size=288 · insn=72 */
/* @0x1a39b4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a39b8 mov r6, r0 */
/* @0x1a39bc bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a39c0 cmp r0, #0 */
/* @0x1a39c4 beq 0x1a3ac4 <_Z29ParticleSystem_Emitter_Createi+0x110> */
/* @0x1a39c8 ldr r3, [pc, #0xfc] */
/* @0x1a39cc ldr r3, [pc, r3] */
/* @0x1a39d0 ldr r3, [r3, #0x4] */
/* @0x1a39d4 ldr r7, [r3, r6, lsl #2] */
/* @0x1a39d8 ldr r1, [r7, #0x14] */
/* @0x1a39dc cmp r1, #0 */
/* @0x1a39e0 ble 0x1a3ab0 <_Z29ParticleSystem_Emitter_Createi+0xfc> */
/* @0x1a39e4 ldr r3, [r7, #0x10] */
/* @0x1a39e8 ldr r2, [r3] */
/* @0x1a39ec ldrb r5, [r2] */
/* @0x1a39f0 cmp r5, #0 */
/* @0x1a39f4 beq 0x1a3aa8 <_Z29ParticleSystem_Emitter_Createi+0xf4> */
/* @0x1a39f8 mov r4, #0 */
/* @0x1a39fc b 0x1a3a10 <_Z29ParticleSystem_Emitter_Createi+0x5c> */
/* @0x1a3a00 ldr r2, [r3, #0x4]! */
/* @0x1a3a04 ldrb r2, [r2] */
/* @0x1a3a08 cmp r2, #0 */
/* @0x1a3a0c beq 0x1a3a44 <_Z29ParticleSystem_Emitter_Createi+0x90> */
/* @0x1a3a10 add r4, r4, #1 */
/* @0x1a3a14 cmp r4, r1 */
/* @0x1a3a18 lsl r5, r4, #2 */
/* @0x1a3a1c bne 0x1a3a00 <_Z29ParticleSystem_Emitter_Createi+0x4c> */
/* @0x1a3a20 add r8, r4, #1 */
/* @0x1a3a24 ldr r2, [pc, #0xa4] */
/* @0x1a3a28 add r0, r7, #16 */
/* @0x1a3a2c mov r3, #1072 */
/* @0x1a3a30 add r2, pc, r2 */
/* @0x1a3a34 lsl r1, r8, #2 */
/* @0x1a3a38 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a3a3c str r8, [r7, #0xc] */
/* @0x1a3a40 str r8, [r7, #0x14] */
/* @0x1a3a44 mov r0, #36 */
/* @0x1a3a48 bl 0x27c524 <_Znwj> */
/* @0x1a3a4c mov r2, #0 */
/* @0x1a3a50 mov r1, #0 */
/* @0x1a3a54 mov r3, r0 */
/* @0x1a3a58 ldr r0, [r7, #0x10] */
/* @0x1a3a5c strb r2, [r3] */
/* @0x1a3a60 str r2, [r3, #0x4] */
/* @0x1a3a64 str r1, [r3, #0x8] */
/* @0x1a3a68 str r2, [r3, #0x18] */
/* @0x1a3a6c str r1, [r3, #0xc] */
/* @0x1a3a70 str r2, [r3, #0x1c] */
/* @0x1a3a74 str r1, [r3, #0x10] */
/* @0x1a3a78 str r2, [r3, #0x20] */
/* @0x1a3a7c mov r2, #1 */
/* @0x1a3a80 str r1, [r3, #0x14] */
/* @0x1a3a84 mov r1, r4 */
/* @0x1a3a88 str r3, [r0, r5] */
/* @0x1a3a8c mov r0, r6 */
/* @0x1a3a90 ldr r3, [r7, #0x10] */
/* @0x1a3a94 ldr r3, [r3, r5] */
/* @0x1a3a98 strb r2, [r3] */
/* @0x1a3a9c bl 0x1a38ec <_Z28ParticleSystem_Emitter_Clearii> */
/* @0x1a3aa0 mov r0, r4 */
/* @0x1a3aa4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3aa8 mov r4, r5 */
/* @0x1a3aac b 0x1a3a44 <_Z29ParticleSystem_Emitter_Createi+0x90> */
/* @0x1a3ab0 movne r5, #0 */
/* @0x1a3ab4 bne 0x1a3aa8 <_Z29ParticleSystem_Emitter_Createi+0xf4> */
/* @0x1a3ab8 mov r5, r1 */
/* @0x1a3abc mov r4, r1 */
/* @0x1a3ac0 b 0x1a3a20 <_Z29ParticleSystem_Emitter_Createi+0x6c> */
/* @0x1a3ac4 mvn r0, #0 */
/* @0x1a3ac8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3acc eoreq r12, r4, r12, ror #27 */
/* @0x1a3ad0 andseq r9, r10, r0, asr r5 */

/* ── FUNC 0x1a3ad4 · ParticleSystem_Emitter_Stream(int, int, int, int) · size=164 · insn=41 */
/* @0x1a3ad4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a3ad8 mov r4, r1 */
/* @0x1a3adc mov r7, r3 */
/* @0x1a3ae0 mov r6, r2 */
/* @0x1a3ae4 mov r5, r0 */
/* @0x1a3ae8 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a3aec ldr r12, [pc, #0x70] */
/* @0x1a3af0 ldr r1, [pc, #0x70] */
/* @0x1a3af4 add r12, pc, r12 */
/* @0x1a3af8 ldr r3, [pc, #0x6c] */
/* @0x1a3afc add r1, pc, r1 */
/* @0x1a3b00 cmp r0, #0 */
/* @0x1a3b04 beq 0x1a3b4c <_Z29ParticleSystem_Emitter_Streamiiii+0x78> */
/* @0x1a3b08 ldr r3, [pc, #0x60] */
/* @0x1a3b0c cmp r4, #0 */
/* @0x1a3b10 ldr r1, [r12, r3] */
/* @0x1a3b14 ldr r1, [r1, #0x4] */
/* @0x1a3b18 ldr r1, [r1, r5, lsl #2] */
/* @0x1a3b1c blt 0x1a3b40 <_Z29ParticleSystem_Emitter_Streamiiii+0x6c> */
/* @0x1a3b20 ldr r3, [r1, #0xc] */
/* @0x1a3b24 cmp r4, r3 */
/* @0x1a3b28 bge 0x1a3b40 <_Z29ParticleSystem_Emitter_Streamiiii+0x6c> */
/* @0x1a3b2c ldr r3, [r1, #0x10] */
/* @0x1a3b30 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3b34 str r7, [r3, #0x4] */
/* @0x1a3b38 str r6, [r3, #0x20] */
/* @0x1a3b3c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a3b40 ldr r1, [pc, #0x2c] */
/* @0x1a3b44 ldr r3, [pc, #0x20] */
/* @0x1a3b48 add r1, pc, r1 */
/* @0x1a3b4c ldr r3, [r12, r3] */
/* @0x1a3b50 ldr r0, [r3] */
/* @0x1a3b54 ldr r3, [r0] */
/* @0x1a3b58 ldr r3, [r3, #0xc] */
/* @0x1a3b5c blx r3 */
/* @0x1a3b60 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a3b64 eoreq lr, r4, r12, asr r1 */
/* @0x1a3b68 andseq r9, r10, r0, asr #9 */
/* @0x1a3b6c .word 0xffffbac4 */
/* @0x1a3b70 .word 0xffffeb68 */
/* @0x1a3b74 andseq r9, r10, r12, lsr #9 */

/* ── FUNC 0x1a3b78 · ParticleSystem_Particles_Create(int, float, float, int, int) · size=376 · insn=94 */
/* @0x1a3b78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a3b7c sub sp, sp, #12 */
/* @0x1a3b80 mov r8, r1 */
/* @0x1a3b84 mov r6, r3 */
/* @0x1a3b88 mov r9, r2 */
/* @0x1a3b8c mov r5, r0 */
/* @0x1a3b90 ldr r7, [sp, #0x30] */
/* @0x1a3b94 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a3b98 ldr r4, [pc, #0x134] */
/* @0x1a3b9c add r4, pc, r4 */
/* @0x1a3ba0 cmp r0, #0 */
/* @0x1a3ba4 beq 0x1a3c9c <_Z31ParticleSystem_Particles_Createiffii+0x124> */
/* @0x1a3ba8 mov r0, r6 */
/* @0x1a3bac bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3bb0 cmp r0, #0 */
/* @0x1a3bb4 beq 0x1a3cc4 <_Z31ParticleSystem_Particles_Createiffii+0x14c> */
/* @0x1a3bb8 ldr r3, [pc, #0x118] */
/* @0x1a3bbc cmp r7, #0 */
/* @0x1a3bc0 ldr r3, [r4, r3] */
/* @0x1a3bc4 ldr r3, [r3, #0x4] */
/* @0x1a3bc8 ldr r4, [r3, r5, lsl #2] */
/* @0x1a3bcc ble 0x1a3cbc <_Z31ParticleSystem_Particles_Createiffii+0x144> */
/* @0x1a3bd0 ldr r3, [pc, #0x104] */
/* @0x1a3bd4 mov r5, #1 */
/* @0x1a3bd8 ldr r10, [pc, #0x100] */
/* @0x1a3bdc add r3, pc, r3 */
/* @0x1a3be0 str r3, [sp, #0x4] */
/* @0x1a3be4 add r10, pc, r10 */
/* @0x1a3be8 add r3, r4, #4 */
/* @0x1a3bec str r3, [sp] */
/* @0x1a3bf0 b 0x1a3c64 <_Z31ParticleSystem_Particles_Createiffii+0xec> */
/* @0x1a3bf4 ldr r2, [r4, #0x4] */
/* @0x1a3bf8 add r1, r3, #1073741824 */
/* @0x1a3bfc add r3, r3, #1 */
/* @0x1a3c00 str r3, [r4, #0x8] */
/* @0x1a3c04 add r11, r2, r1, lsl #2 */
/* @0x1a3c08 ldr r0, [r2, r1, lsl #2] */
/* @0x1a3c0c cmp r0, #0 */
/* @0x1a3c10 beq 0x1a3c24 <_Z31ParticleSystem_Particles_Createiffii+0xac> */
/* @0x1a3c14 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a3c18 ldmib r4, {r3, r12} */
/* @0x1a3c1c sub r12, r12, #-1073741823 */
/* @0x1a3c20 add r11, r3, r12, lsl #2 */
/* @0x1a3c24 mov r1, r10 */
/* @0x1a3c28 movw r2, #0x586 */
/* @0x1a3c2c mov r3, #1 */
/* @0x1a3c30 mov r0, #64 */
/* @0x1a3c34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a3c38 ldr lr, [r4, #0x8] */
/* @0x1a3c3c mov r1, r9 */
/* @0x1a3c40 mov r2, r6 */
/* @0x1a3c44 sub lr, lr, #-1073741823 */
/* @0x1a3c48 str r0, [r11] */
/* @0x1a3c4c mov r0, r8 */
/* @0x1a3c50 ldr r3, [r4, #0x4] */
/* @0x1a3c54 ldr r3, [r3, lr, lsl #2] */
/* @0x1a3c58 bl 0x1a2e5c <_Z14CreateParticleffiR9RParticle> */
/* @0x1a3c5c cmp r7, r5 */
/* @0x1a3c60 blt 0x1a3cbc <_Z31ParticleSystem_Particles_Createiffii+0x144> */
/* @0x1a3c64 ldr r3, [r4, #0x8] */
/* @0x1a3c68 add r5, r5, #1 */
/* @0x1a3c6c ldr r2, [r4] */
/* @0x1a3c70 cmp r2, r3 */
/* @0x1a3c74 bgt 0x1a3bf4 <_Z31ParticleSystem_Particles_Createiffii+0x7c> */
/* @0x1a3c78 add r1, r3, #100 */
/* @0x1a3c7c ldm sp, {r0, r2} */
/* @0x1a3c80 movw r3, #0x57e */
/* @0x1a3c84 lsl r1, r1, #2 */
/* @0x1a3c88 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a3c8c ldr r3, [r4, #0x8] */
/* @0x1a3c90 add r2, r3, #100 */
/* @0x1a3c94 str r2, [r4] */
/* @0x1a3c98 b 0x1a3bf4 <_Z31ParticleSystem_Particles_Createiffii+0x7c> */
/* @0x1a3c9c ldr r1, [pc, #0x40] */
/* @0x1a3ca0 ldr r3, [pc, #0x40] */
/* @0x1a3ca4 add r1, pc, r1 */
/* @0x1a3ca8 ldr r3, [r4, r3] */
/* @0x1a3cac ldr r0, [r3] */
/* @0x1a3cb0 ldr r3, [r0] */
/* @0x1a3cb4 ldr r3, [r3, #0xc] */
/* @0x1a3cb8 blx r3 */
/* @0x1a3cbc add sp, sp, #12 */
/* @0x1a3cc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a3cc4 ldr r1, [pc, #0x20] */
/* @0x1a3cc8 ldr r3, [pc, #0x18] */
/* @0x1a3ccc add r1, pc, r1 */
/* @0x1a3cd0 b 0x1a3ca8 <_Z31ParticleSystem_Particles_Createiffii+0x130> */
/* @0x1a3cd4 strhteq lr, [r4], -r4 */
/* @0x1a3cd8 .word 0xffffeb68 */
/* @0x1a3cdc andseq r9, r10, r4, lsr #7 */
/* @0x1a3ce0 mulseq r10, r12, r3 */
/* @0x1a3ce4 andseq r9, r10, r8, lsl #7 */
/* @0x1a3ce8 .word 0xffffbac4 */
/* @0x1a3cec mulseq r10, r12, r3 */

/* ── FUNC 0x1a3cf0 · ParticleSystem_Emitter_Burst(int, int, int, int) · size=600 · insn=150 */
/* @0x1a3cf0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a3cf4 vpush {d8, d9, d10} */
/* @0x1a3cf8 sub sp, sp, #8 */
/* @0x1a3cfc mov r8, r2 */
/* @0x1a3d00 mov r6, r3 */
/* @0x1a3d04 mov r7, r0 */
/* @0x1a3d08 mov r5, r1 */
/* @0x1a3d0c bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii> */
/* @0x1a3d10 cmp r0, #0 */
/* @0x1a3d14 beq 0x1a3df8 <_Z28ParticleSystem_Emitter_Burstiiii+0x108> */
/* @0x1a3d18 ldr r3, [pc, #0x220] */
/* @0x1a3d1c cmp r6, #0 */
/* @0x1a3d20 ldr r3, [pc, r3] */
/* @0x1a3d24 ldr r3, [r3, #0x4] */
/* @0x1a3d28 ldr r4, [r3, r7, lsl #2] */
/* @0x1a3d2c blt 0x1a3f28 <_Z28ParticleSystem_Emitter_Burstiiii+0x238> */
/* @0x1a3d30 ldr r1, [r4, #0x8] */
/* @0x1a3d34 ldr r3, [r4] */
/* @0x1a3d38 add r1, r6, r1 */
/* @0x1a3d3c cmp r3, r1 */
/* @0x1a3d40 ble 0x1a3f00 <_Z28ParticleSystem_Emitter_Burstiiii+0x210> */
/* @0x1a3d44 ldr r3, [r4, #0x10] */
/* @0x1a3d48 cmp r6, #0 */
/* @0x1a3d4c ldr r4, [r3, r5, lsl #2] */
/* @0x1a3d50 beq 0x1a3df8 <_Z28ParticleSystem_Emitter_Burstiiii+0x108> */
/* @0x1a3d54 vmov.f64 d8, #5.000000e-01 */
/* @0x1a3d58 mov r5, #0 */
/* @0x1a3d5c vmov.f32 s20, #5.000000e-01 */
/* @0x1a3d60 mov r1, #1065353216 */
/* @0x1a3d64 ldr r2, [r4, #0x18] */
/* @0x1a3d68 mov r0, #0 */
/* @0x1a3d6c bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a3d70 mov r1, #1065353216 */
/* @0x1a3d74 ldr r2, [r4, #0x18] */
/* @0x1a3d78 vmov s18, r0 */
/* @0x1a3d7c mov r0, #0 */
/* @0x1a3d80 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a3d84 ldr r1, [r4, #0x18] */
/* @0x1a3d88 cmp r1, #2 */
/* @0x1a3d8c vmov s19, r0 */
/* @0x1a3d90 beq 0x1a3e5c <_Z28ParticleSystem_Emitter_Burstiiii+0x16c> */
/* @0x1a3d94 ldr r1, [r4, #0x1c] */
/* @0x1a3d98 cmp r1, #1 */
/* @0x1a3d9c beq 0x1a3e04 <_Z28ParticleSystem_Emitter_Burstiiii+0x114> */
/* @0x1a3da0 cmp r1, #2 */
/* @0x1a3da4 beq 0x1a3e34 <_Z28ParticleSystem_Emitter_Burstiiii+0x144> */
/* @0x1a3da8 cmp r1, #3 */
/* @0x1a3dac beq 0x1a3e68 <_Z28ParticleSystem_Emitter_Burstiiii+0x178> */
/* @0x1a3db0 vldr s14, [r4, #8] */
/* @0x1a3db4 vldr s15, [r4, #16] */
/* @0x1a3db8 vldr s12, [r4, #12] */
/* @0x1a3dbc vldr s13, [r4, #20] */
/* @0x1a3dc0 vsub.f32 s12, s12, s14 */
/* @0x1a3dc4 mov r3, #1 */
/* @0x1a3dc8 mov r0, r7 */
/* @0x1a3dcc str r3, [sp] */
/* @0x1a3dd0 add r5, r5, #1 */
/* @0x1a3dd4 mov r3, r8 */
/* @0x1a3dd8 vsub.f32 s13, s13, s15 */
/* @0x1a3ddc vmla.f32 s14, s12, s18 */
/* @0x1a3de0 vmla.f32 s15, s13, s19 */
/* @0x1a3de4 vmov r1, s14 */
/* @0x1a3de8 vmov r2, s15 */
/* @0x1a3dec bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii> */
/* @0x1a3df0 cmp r5, r6 */
/* @0x1a3df4 bne 0x1a3d60 <_Z28ParticleSystem_Emitter_Burstiiii+0x70> */
/* @0x1a3df8 add sp, sp, #8 */
/* @0x1a3dfc vpop {d8, d9, d10} */
/* @0x1a3e00 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3e04 vsub.f32 s15, s19, s20 */
/* @0x1a3e08 vmul.f32 s15, s15, s15 */
/* @0x1a3e0c vsub.f32 s14, s18, s20 */
/* @0x1a3e10 vmla.f32 s15, s14, s14 */
/* @0x1a3e14 vmov.f32 s14, #2.500000e-01 */
/* @0x1a3e18 vcmpe.f32 s15, s14 */
/* @0x1a3e1c vmrs APSR_nzcv, fpscr */
/* @0x1a3e20 movhi r12, #0 */
/* @0x1a3e24 movls r12, #1 */
/* @0x1a3e28 cmp r12, #0 */
/* @0x1a3e2c beq 0x1a3d60 <_Z28ParticleSystem_Emitter_Burstiiii+0x70> */
/* @0x1a3e30 b 0x1a3da8 <_Z28ParticleSystem_Emitter_Burstiiii+0xb8> */
/* @0x1a3e34 vsub.f32 s14, s18, s20 */
/* @0x1a3e38 vsub.f32 s15, s19, s20 */
/* @0x1a3e3c vabs.f32 s14, s14 */
/* @0x1a3e40 vabs.f32 s15, s15 */
/* @0x1a3e44 vadd.f32 s15, s14, s15 */
/* @0x1a3e48 vcmpe.f32 s15, s20 */
/* @0x1a3e4c vmrs APSR_nzcv, fpscr */
/* @0x1a3e50 movhi r12, #0 */
/* @0x1a3e54 movls r12, #1 */
/* @0x1a3e58 b 0x1a3e28 <_Z28ParticleSystem_Emitter_Burstiiii+0x138> */
/* @0x1a3e5c ldr r1, [r4, #0x1c] */
/* @0x1a3e60 cmp r1, #3 */
/* @0x1a3e64 bne 0x1a3ebc <_Z28ParticleSystem_Emitter_Burstiiii+0x1cc> */
/* @0x1a3e68 vldr s14, [r4, #8] */
/* @0x1a3e6c vldr s15, [r4, #16] */
/* @0x1a3e70 vldr s12, [r4, #12] */
/* @0x1a3e74 vldr s13, [r4, #20] */
/* @0x1a3e78 vsub.f32 s12, s12, s14 */
/* @0x1a3e7c mov r3, #1 */
/* @0x1a3e80 mov r0, r7 */
/* @0x1a3e84 str r3, [sp] */
/* @0x1a3e88 add r5, r5, #1 */
/* @0x1a3e8c mov r3, r8 */
/* @0x1a3e90 vsub.f32 s13, s13, s15 */
/* @0x1a3e94 vmla.f32 s14, s12, s18 */
/* @0x1a3e98 vmla.f32 s15, s13, s18 */
/* @0x1a3e9c vmov r1, s14 */
/* @0x1a3ea0 vmov r2, s15 */
/* @0x1a3ea4 bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii> */
/* @0x1a3ea8 cmp r5, r6 */
/* @0x1a3eac bne 0x1a3d60 <_Z28ParticleSystem_Emitter_Burstiiii+0x70> */
/* @0x1a3eb0 add sp, sp, #8 */
/* @0x1a3eb4 vpop {d8, d9, d10} */
/* @0x1a3eb8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3ebc mov r0, #0 */
/* @0x1a3ec0 mov r1, #0 */
/* @0x1a3ec4 movt r1, #0x3ff0 */
/* @0x1a3ec8 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a3ecc mov r2, #0 */
/* @0x1a3ed0 vmov d7, r0, r1 */
/* @0x1a3ed4 mov r0, #0 */
/* @0x1a3ed8 mov r1, #1065353216 */
/* @0x1a3edc vcmpe.f64 d7, d8 */
/* @0x1a3ee0 vmrs APSR_nzcv, fpscr */
/* @0x1a3ee4 bpl 0x1a3ef4 <_Z28ParticleSystem_Emitter_Burstiiii+0x204> */
/* @0x1a3ee8 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a3eec vmov s18, r0 */
/* @0x1a3ef0 b 0x1a3d94 <_Z28ParticleSystem_Emitter_Burstiiii+0xa4> */
/* @0x1a3ef4 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a3ef8 vmov s19, r0 */
/* @0x1a3efc b 0x1a3d94 <_Z28ParticleSystem_Emitter_Burstiiii+0xa4> */
/* @0x1a3f00 ldr r2, [pc, #0x3c] */
/* @0x1a3f04 movw r3, #0x4fb */
/* @0x1a3f08 lsl r1, r1, #2 */
/* @0x1a3f0c add r0, r4, #4 */
/* @0x1a3f10 add r2, pc, r2 */
/* @0x1a3f14 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a3f18 ldr r3, [r4, #0x8] */
/* @0x1a3f1c add r3, r3, r6 */
/* @0x1a3f20 str r3, [r4] */
/* @0x1a3f24 b 0x1a3d44 <_Z28ParticleSystem_Emitter_Burstiiii+0x54> */
/* @0x1a3f28 rsb r0, r6, #0 */
/* @0x1a3f2c bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a3f30 cmp r0, #0 */
/* @0x1a3f34 bne 0x1a3df8 <_Z28ParticleSystem_Emitter_Burstiiii+0x108> */
/* @0x1a3f38 mov r6, #1 */
/* @0x1a3f3c b 0x1a3d30 <_Z28ParticleSystem_Emitter_Burstiiii+0x40> */
/* @0x1a3f40 mlaeq r4, r8, r10, r12 */
/* @0x1a3f44 andseq r9, r10, r0, ror r0 */

/* ── FUNC 0x1a3f48 · ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int) · size=396 · insn=99 */
/* @0x1a3f48 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a3f4c sub sp, sp, #12 */
/* @0x1a3f50 mov r8, r1 */
/* @0x1a3f54 mov r6, r3 */
/* @0x1a3f58 mov r9, r2 */
/* @0x1a3f5c mov r5, r0 */
/* @0x1a3f60 ldr r7, [sp, #0x34] */
/* @0x1a3f64 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a3f68 ldr r4, [pc, #0x148] */
/* @0x1a3f6c add r4, pc, r4 */
/* @0x1a3f70 cmp r0, #0 */
/* @0x1a3f74 beq 0x1a4080 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x138> */
/* @0x1a3f78 mov r0, r6 */
/* @0x1a3f7c bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3f80 cmp r0, #0 */
/* @0x1a3f84 beq 0x1a40a8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x160> */
/* @0x1a3f88 ldr r3, [pc, #0x12c] */
/* @0x1a3f8c cmp r7, #0 */
/* @0x1a3f90 ldr r3, [r4, r3] */
/* @0x1a3f94 ldr r3, [r3, #0x4] */
/* @0x1a3f98 ldr r4, [r3, r5, lsl #2] */
/* @0x1a3f9c ble 0x1a40a0 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x158> */
/* @0x1a3fa0 ldr r2, [pc, #0x118] */
/* @0x1a3fa4 add r1, r4, #4 */
/* @0x1a3fa8 ldr r11, [pc, #0x114] */
/* @0x1a3fac mov r5, #1 */
/* @0x1a3fb0 add r2, pc, r2 */
/* @0x1a3fb4 ldr r3, [r4, #0x8] */
/* @0x1a3fb8 str r1, [sp] */
/* @0x1a3fbc add r11, pc, r11 */
/* @0x1a3fc0 str r2, [sp, #0x4] */
/* @0x1a3fc4 b 0x1a404c <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x104> */
/* @0x1a3fc8 ldr r2, [r4, #0x4] */
/* @0x1a3fcc add r1, r3, #1073741824 */
/* @0x1a3fd0 add r3, r3, #1 */
/* @0x1a3fd4 str r3, [r4, #0x8] */
/* @0x1a3fd8 add r10, r2, r1, lsl #2 */
/* @0x1a3fdc ldr r0, [r2, r1, lsl #2] */
/* @0x1a3fe0 cmp r0, #0 */
/* @0x1a3fe4 beq 0x1a3ff8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0xb0> */
/* @0x1a3fe8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a3fec ldmib r4, {r3, r12} */
/* @0x1a3ff0 sub r12, r12, #-1073741823 */
/* @0x1a3ff4 add r10, r3, r12, lsl #2 */
/* @0x1a3ff8 mov r1, r11 */
/* @0x1a3ffc movw r2, #0x5b2 */
/* @0x1a4000 mov r3, #1 */
/* @0x1a4004 mov r0, #64 */
/* @0x1a4008 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a400c ldr lr, [r4, #0x8] */
/* @0x1a4010 mov r1, r9 */
/* @0x1a4014 mov r2, r6 */
/* @0x1a4018 sub lr, lr, #-1073741823 */
/* @0x1a401c str r0, [r10] */
/* @0x1a4020 mov r0, r8 */
/* @0x1a4024 ldr r3, [r4, #0x4] */
/* @0x1a4028 ldr r3, [r3, lr, lsl #2] */
/* @0x1a402c bl 0x1a2e5c <_Z14CreateParticleffiR9RParticle> */
/* @0x1a4030 ldmib r4, {r2, r3} */
/* @0x1a4034 cmp r7, r5 */
/* @0x1a4038 sub r1, r3, #-1073741823 */
/* @0x1a403c ldr r2, [r2, r1, lsl #2] */
/* @0x1a4040 ldr r1, [sp, #0x30] */
/* @0x1a4044 str r1, [r2, #0x2c] */
/* @0x1a4048 blt 0x1a40a0 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x158> */
/* @0x1a404c ldr r2, [r4] */
/* @0x1a4050 add r5, r5, #1 */
/* @0x1a4054 cmp r2, r3 */
/* @0x1a4058 bgt 0x1a3fc8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x80> */
/* @0x1a405c add r1, r3, #100 */
/* @0x1a4060 ldm sp, {r0, r2} */
/* @0x1a4064 movw r3, #0x5aa */
/* @0x1a4068 lsl r1, r1, #2 */
/* @0x1a406c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a4070 ldr r3, [r4, #0x8] */
/* @0x1a4074 add r2, r3, #100 */
/* @0x1a4078 str r2, [r4] */
/* @0x1a407c b 0x1a3fc8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x80> */
/* @0x1a4080 ldr r1, [pc, #0x40] */
/* @0x1a4084 ldr r3, [pc, #0x40] */
/* @0x1a4088 add r1, pc, r1 */
/* @0x1a408c ldr r3, [r4, r3] */
/* @0x1a4090 ldr r0, [r3] */
/* @0x1a4094 ldr r3, [r0] */
/* @0x1a4098 ldr r3, [r3, #0xc] */
/* @0x1a409c blx r3 */
/* @0x1a40a0 add sp, sp, #12 */
/* @0x1a40a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a40a8 ldr r1, [pc, #0x20] */
/* @0x1a40ac ldr r3, [pc, #0x18] */
/* @0x1a40b0 add r1, pc, r1 */
/* @0x1a40b4 b 0x1a408c <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x144> */
/* @0x1a40b8 eoreq sp, r4, r4, ror #25 */
/* @0x1a40bc .word 0xffffeb68 */
/* @0x1a40c0 ldrsbeq r8, [r10], -r0 */
/* @0x1a40c4 andseq r8, r10, r4, asr #31 */
/* @0x1a40c8 andseq r8, r10, r4, lsr #31 */
/* @0x1a40cc .word 0xffffbac4 */
/* @0x1a40d0 ldrheq r8, [r10], -r8 */

/* ── FUNC 0x1a40d4 · ParticleSystem_Particles_Clear(int) · size=124 · insn=31 */
/* @0x1a40d4 push {r4, r5, r6, lr} */
/* @0x1a40d8 mov r4, r0 */
/* @0x1a40dc bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a40e0 cmp r0, #0 */
/* @0x1a40e4 popeq {r4, r5, r6, pc} */
/* @0x1a40e8 ldr r3, [pc, #0x5c] */
/* @0x1a40ec ldr r3, [pc, r3] */
/* @0x1a40f0 ldr r3, [r3, #0x4] */
/* @0x1a40f4 ldr r5, [r3, r4, lsl #2] */
/* @0x1a40f8 ldr r3, [r5] */
/* @0x1a40fc cmp r3, #0 */
/* @0x1a4100 movgt r4, #0 */
/* @0x1a4104 movgt r6, r4 */
/* @0x1a4108 ble 0x1a4130 <_Z30ParticleSystem_Particles_Cleari+0x5c> */
/* @0x1a410c ldr r3, [r5, #0x4] */
/* @0x1a4110 ldr r0, [r3, r4, lsl #2] */
/* @0x1a4114 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a4118 ldr r2, [r5, #0x4] */
/* @0x1a411c ldr r3, [r5] */
/* @0x1a4120 str r6, [r2, r4, lsl #2] */
/* @0x1a4124 add r4, r4, #1 */
/* @0x1a4128 cmp r3, r4 */
/* @0x1a412c bgt 0x1a410c <_Z30ParticleSystem_Particles_Cleari+0x38> */
/* @0x1a4130 ldr r0, [r5, #0x4] */
/* @0x1a4134 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a4138 mov r3, #0 */
/* @0x1a413c str r3, [r5, #0x4] */
/* @0x1a4140 str r3, [r5] */
/* @0x1a4144 str r3, [r5, #0x8] */
/* @0x1a4148 pop {r4, r5, r6, pc} */
/* @0x1a414c eoreq r12, r4, r12, asr #13 */

/* ── FUNC 0x1a4150 · ParticleSystem_Particles_Count(int) · size=48 · insn=12 */
/* @0x1a4150 push {r4, lr} */
/* @0x1a4154 mov r4, r0 */
/* @0x1a4158 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a415c cmp r0, #0 */
/* @0x1a4160 popeq {r4, pc} */
/* @0x1a4164 ldr r3, [pc, #0x10] */
/* @0x1a4168 ldr r3, [pc, r3] */
/* @0x1a416c ldr r3, [r3, #0x4] */
/* @0x1a4170 ldr r3, [r3, r4, lsl #2] */
/* @0x1a4174 ldr r0, [r3, #0x8] */
/* @0x1a4178 pop {r4, pc} */
/* @0x1a417c eoreq r12, r4, r0, asr r6 */

/* ── FUNC 0x1a4180 · ParticleSystem_Clear(int) · size=348 · insn=87 */
/* @0x1a4180 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a4184 mov r7, r0 */
/* @0x1a4188 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a418c cmp r0, #0 */
/* @0x1a4190 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a4194 ldr r5, [pc, #0x134] */
/* @0x1a4198 lsl r6, r7, #2 */
/* @0x1a419c ldr r5, [pc, r5] */
/* @0x1a41a0 ldr r3, [r5, #0x4] */
/* @0x1a41a4 ldr r3, [r3, r7, lsl #2] */
/* @0x1a41a8 ldr r2, [r3] */
/* @0x1a41ac cmp r2, #0 */
/* @0x1a41b0 ble 0x1a41f0 <_Z20ParticleSystem_Cleari+0x70> */
/* @0x1a41b4 mov r4, #0 */
/* @0x1a41b8 mov r8, r4 */
/* @0x1a41bc ldr r3, [r3, #0x4] */
/* @0x1a41c0 ldr r0, [r3, r4, lsl #2] */
/* @0x1a41c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a41c8 ldr r3, [r5, #0x4] */
/* @0x1a41cc ldr r3, [r3, r6] */
/* @0x1a41d0 ldr r3, [r3, #0x4] */
/* @0x1a41d4 str r8, [r3, r4, lsl #2] */
/* @0x1a41d8 add r4, r4, #1 */
/* @0x1a41dc ldr r3, [r5, #0x4] */
/* @0x1a41e0 ldr r3, [r3, r6] */
/* @0x1a41e4 ldr r2, [r3] */
/* @0x1a41e8 cmp r4, r2 */
/* @0x1a41ec blt 0x1a41bc <_Z20ParticleSystem_Cleari+0x3c> */
/* @0x1a41f0 ldr r0, [r3, #0x4] */
/* @0x1a41f4 mov r4, #0 */
/* @0x1a41f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a41fc ldr r3, [r5, #0x4] */
/* @0x1a4200 ldr r2, [r3, r7, lsl #2] */
/* @0x1a4204 str r4, [r2, #0x4] */
/* @0x1a4208 ldr r3, [r3, r7, lsl #2] */
/* @0x1a420c ldr r2, [r3, #0xc] */
/* @0x1a4210 str r4, [r3] */
/* @0x1a4214 cmp r2, r4 */
/* @0x1a4218 str r4, [r3, #0x8] */
/* @0x1a421c ble 0x1a4244 <_Z20ParticleSystem_Cleari+0xc4> */
/* @0x1a4220 ldr r3, [r3, #0x10] */
/* @0x1a4224 ldr r0, [r3, r4, lsl #2] */
/* @0x1a4228 add r4, r4, #1 */
/* @0x1a422c bl 0x27d1d0 <_ZdlPv> */
/* @0x1a4230 ldr r3, [r5, #0x4] */
/* @0x1a4234 ldr r3, [r3, r6] */
/* @0x1a4238 ldr r2, [r3, #0xc] */
/* @0x1a423c cmp r4, r2 */
/* @0x1a4240 blt 0x1a4220 <_Z20ParticleSystem_Cleari+0xa0> */
/* @0x1a4244 ldr r0, [r3, #0x10] */
/* @0x1a4248 mov r4, #0 */
/* @0x1a424c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a4250 ldr r1, [r5, #0x4] */
/* @0x1a4254 ldr r3, [pc, #0x78] */
/* @0x1a4258 mov r2, #1 */
/* @0x1a425c mov r0, #0 */
/* @0x1a4260 ldr r12, [r1, r7, lsl #2] */
/* @0x1a4264 ldr r3, [pc, r3] */
/* @0x1a4268 ldrb r3, [r3] */
/* @0x1a426c str r4, [r12, #0x10] */
/* @0x1a4270 ldr r1, [r1, r7, lsl #2] */
/* @0x1a4274 cmp r3, r4 */
/* @0x1a4278 str r0, [r1, #0x1c] */
/* @0x1a427c str r0, [r1, #0x20] */
/* @0x1a4280 str r0, [r1, #0x24] */
/* @0x1a4284 str r4, [r1, #0xc] */
/* @0x1a4288 str r4, [r1, #0x14] */
/* @0x1a428c strb r2, [r1, #0x18] */
/* @0x1a4290 strb r2, [r1, #0x28] */
/* @0x1a4294 strb r2, [r1, #0x29] */
/* @0x1a4298 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a429c ldr r0, [pc, #0x34] */
/* @0x1a42a0 mov r3, r4 */
/* @0x1a42a4 ldr r1, [r1, #0x2c] */
/* @0x1a42a8 ldr r0, [pc, r0] */
/* @0x1a42ac ldr r0, [r0] */
/* @0x1a42b0 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1a42b4 ldr r3, [r5, #0x4] */
/* @0x1a42b8 mvn r2, #0 */
/* @0x1a42bc ldr r3, [r3, r7, lsl #2] */
/* @0x1a42c0 strb r4, [r3, #0x34] */
/* @0x1a42c4 str r2, [r3, #0x2c] */
/* @0x1a42c8 str r2, [r3, #0x30] */
/* @0x1a42cc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a42d0 eoreq r12, r4, r12, lsl r6 */
/* @0x1a42d4 eoreq r9, r4, r0, asr #13 */
/* @0x1a42d8 eoreq r9, r4, r0, lsl #13 */

/* ── FUNC 0x1a42dc · ParticleSystem_Create(int, bool) · size=624 · insn=156 */
/* @0x1a42dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a42e0 mov r10, r0 */
/* @0x1a42e4 ldr r5, [pc, #0x244] */
/* @0x1a42e8 sub sp, sp, #20 */
/* @0x1a42ec ldr r3, [pc, #0x240] */
/* @0x1a42f0 mov r11, r1 */
/* @0x1a42f4 add r5, pc, r5 */
/* @0x1a42f8 ldr r8, [r5, r3] */
/* @0x1a42fc ldrb r9, [r8] */
/* @0x1a4300 cmp r9, #0 */
/* @0x1a4304 beq 0x1a4364 <_Z21ParticleSystem_Createib+0x88> */
/* @0x1a4308 cmn r0, #1 */
/* @0x1a430c beq 0x1a4494 <_Z21ParticleSystem_Createib+0x1b8> */
/* @0x1a4310 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1a4314 subs r4, r0, #0 */
/* @0x1a4318 beq 0x1a44f4 <_Z21ParticleSystem_Createib+0x218> */
/* @0x1a431c mov r1, r10 */
/* @0x1a4320 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1a4324 subs r6, r0, #0 */
/* @0x1a4328 beq 0x1a44f4 <_Z21ParticleSystem_Createib+0x218> */
/* @0x1a432c bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv> */
/* @0x1a4330 ldr r3, [pc, #0x200] */
/* @0x1a4334 ldr r3, [r5, r3] */
/* @0x1a4338 mov r9, r0 */
/* @0x1a433c ldr r0, [r3] */
/* @0x1a4340 cmp r4, r0 */
/* @0x1a4344 beq 0x1a44c4 <_Z21ParticleSystem_Createib+0x1e8> */
/* @0x1a4348 mov r3, #1 */
/* @0x1a434c mov r1, #0 */
/* @0x1a4350 str r3, [sp] */
/* @0x1a4354 mov r2, r9 */
/* @0x1a4358 bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb> */
/* @0x1a435c cmp r9, #0 */
/* @0x1a4360 beq 0x1a44f4 <_Z21ParticleSystem_Createib+0x218> */
/* @0x1a4364 ldr r3, [pc, #0x1d0] */
/* @0x1a4368 ldr r12, [r5, r3] */
/* @0x1a436c ldr r3, [pc, #0x1cc] */
/* @0x1a4370 ldr r1, [r12] */
/* @0x1a4374 cmp r1, #0 */
/* @0x1a4378 ble 0x1a4500 <_Z21ParticleSystem_Createib+0x224> */
/* @0x1a437c ldr r7, [r5, r3] */
/* @0x1a4380 ldr r5, [r7, #0x4] */
/* @0x1a4384 ldr r6, [r5] */
/* @0x1a4388 cmp r6, #0 */
/* @0x1a438c beq 0x1a4518 <_Z21ParticleSystem_Createib+0x23c> */
/* @0x1a4390 add r3, r5, #4 */
/* @0x1a4394 mov r4, #0 */
/* @0x1a4398 b 0x1a43a8 <_Z21ParticleSystem_Createib+0xcc> */
/* @0x1a439c ldr r2, [r5] */
/* @0x1a43a0 cmp r2, #0 */
/* @0x1a43a4 beq 0x1a43f8 <_Z21ParticleSystem_Createib+0x11c> */
/* @0x1a43a8 add r4, r4, #1 */
/* @0x1a43ac mov r5, r3 */
/* @0x1a43b0 cmp r4, r1 */
/* @0x1a43b4 add r3, r3, #4 */
/* @0x1a43b8 lsl r6, r4, #2 */
/* @0x1a43bc bne 0x1a439c <_Z21ParticleSystem_Createib+0xc0> */
/* @0x1a43c0 add lr, r4, #1 */
/* @0x1a43c4 ldr r2, [pc, #0x178] */
/* @0x1a43c8 movw r3, #0x637 */
/* @0x1a43cc add r0, r7, #4 */
/* @0x1a43d0 add r2, pc, r2 */
/* @0x1a43d4 lsl r1, lr, #2 */
/* @0x1a43d8 str lr, [r12] */
/* @0x1a43dc str r12, [sp, #0xc] */
/* @0x1a43e0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a43e4 ldr r12, [sp, #0xc] */
/* @0x1a43e8 ldr r5, [r7, #0x4] */
/* @0x1a43ec ldr r3, [r12] */
/* @0x1a43f0 add r5, r5, r6 */
/* @0x1a43f4 str r3, [r7] */
/* @0x1a43f8 ldr r1, [pc, #0x148] */
/* @0x1a43fc movw r2, #0x63c */
/* @0x1a4400 mov r3, #1 */
/* @0x1a4404 mov r0, #56 */
/* @0x1a4408 add r1, pc, r1 */
/* @0x1a440c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a4410 ldrb r3, [r8] */
/* @0x1a4414 cmp r3, #0 */
/* @0x1a4418 mvnne r2, #0 */
/* @0x1a441c str r0, [r5] */
/* @0x1a4420 mov r0, r4 */
/* @0x1a4424 ldrne r3, [r7, #0x4] */
/* @0x1a4428 ldrne r3, [r3, r6] */
/* @0x1a442c strne r2, [r3, #0x2c] */
/* @0x1a4430 strne r2, [r3, #0x30] */
/* @0x1a4434 bl 0x1a4180 <_Z20ParticleSystem_Cleari> */
/* @0x1a4438 ldrb r3, [r8] */
/* @0x1a443c cmp r3, #0 */
/* @0x1a4440 beq 0x1a4488 <_Z21ParticleSystem_Createib+0x1ac> */
/* @0x1a4444 ldr r3, [r7, #0x4] */
/* @0x1a4448 cmn r10, #1 */
/* @0x1a444c ldr r2, [r9, #0x4] */
/* @0x1a4450 eor r11, r11, #1 */
/* @0x1a4454 str r4, [r9, #0x1c] */
/* @0x1a4458 ldr r3, [r3, r6] */
/* @0x1a445c str r2, [r3, #0x2c] */
/* @0x1a4460 strb r11, [r3, #0x34] */
/* @0x1a4464 beq 0x1a4488 <_Z21ParticleSystem_Createib+0x1ac> */
/* @0x1a4468 ldr r2, [r9, #0x10] */
/* @0x1a446c vldr s15, [r2, #4] */
/* @0x1a4470 vcvt.f32.s32 s15, s15 */
/* @0x1a4474 mov r0, r4 */
/* @0x1a4478 str r10, [r3, #0x30] */
/* @0x1a447c vstr s15, [r3, #28] */
/* @0x1a4480 add sp, sp, #20 */
/* @0x1a4484 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a4488 mov r0, r4 */
/* @0x1a448c add sp, sp, #20 */
/* @0x1a4490 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a4494 bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv> */
/* @0x1a4498 ldr r12, [pc, #0x98] */
/* @0x1a449c mov r1, #0 */
/* @0x1a44a0 ldr r12, [r5, r12] */
/* @0x1a44a4 mov r9, r0 */
/* @0x1a44a8 mov r0, #1 */
/* @0x1a44ac mov r3, r0 */
/* @0x1a44b0 str r0, [sp] */
/* @0x1a44b4 mov r2, r9 */
/* @0x1a44b8 ldr r0, [r12] */
/* @0x1a44bc bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb> */
/* @0x1a44c0 b 0x1a435c <_Z21ParticleSystem_Createib+0x80> */
/* @0x1a44c4 mov r1, r6 */
/* @0x1a44c8 mov r0, r4 */
/* @0x1a44cc mov r2, r9 */
/* @0x1a44d0 mov r3, #1 */
/* @0x1a44d4 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1a44d8 cmn r0, #1 */
/* @0x1a44dc bne 0x1a435c <_Z21ParticleSystem_Createib+0x80> */
/* @0x1a44e0 mov r0, r4 */
/* @0x1a44e4 ldr r1, [r9, #0x4] */
/* @0x1a44e8 mov r2, #1 */
/* @0x1a44ec mov r3, #0 */
/* @0x1a44f0 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1a44f4 mvn r0, #0 */
/* @0x1a44f8 add sp, sp, #20 */
/* @0x1a44fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a4500 beq 0x1a4520 <_Z21ParticleSystem_Createib+0x244> */
/* @0x1a4504 ldr r7, [r5, r3] */
/* @0x1a4508 mov r6, #0 */
/* @0x1a450c mov r4, r6 */
/* @0x1a4510 ldr r5, [r7, #0x4] */
/* @0x1a4514 b 0x1a43f8 <_Z21ParticleSystem_Createib+0x11c> */
/* @0x1a4518 mov r4, r6 */
/* @0x1a451c b 0x1a43f8 <_Z21ParticleSystem_Createib+0x11c> */
/* @0x1a4520 mov r6, r1 */
/* @0x1a4524 mov r4, r1 */
/* @0x1a4528 ldr r7, [r5, r3] */
/* @0x1a452c b 0x1a43c0 <_Z21ParticleSystem_Createib+0xe4> */
/* @0x1a4530 eoreq sp, r4, r12, asr r9 */
/* @0x1a4534 .word 0xffffbcd4 */
/* @0x1a4538 .word 0xffffbcd8 */
/* @0x1a453c .word 0xffffeb64 */
/* @0x1a4540 .word 0xffffeb68 */
/* @0x1a4544 ldrheq r8, [r10], -r0 */
/* @0x1a4548 andseq r8, r10, r8, ror r11 */

/* ── FUNC 0x1a454c · ParticleSystem_Destroy(int) · size=68 · insn=17 */
/* @0x1a454c push {r3, r4, r5, lr} */
/* @0x1a4550 mov r4, r0 */
/* @0x1a4554 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a4558 cmp r0, #0 */
/* @0x1a455c popeq {r3, r4, r5, pc} */
/* @0x1a4560 ldr r5, [pc, #0x24] */
/* @0x1a4564 mov r0, r4 */
/* @0x1a4568 bl 0x1a4180 <_Z20ParticleSystem_Cleari> */
/* @0x1a456c ldr r5, [pc, r5] */
/* @0x1a4570 ldr r3, [r5, #0x4] */
/* @0x1a4574 ldr r0, [r3, r4, lsl #2] */
/* @0x1a4578 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a457c ldr r3, [r5, #0x4] */
/* @0x1a4580 mov r2, #0 */
/* @0x1a4584 str r2, [r3, r4, lsl #2] */
/* @0x1a4588 pop {r3, r4, r5, pc} */
/* @0x1a458c eoreq r12, r4, r12, asr #4 */

/* ── FUNC 0x1a4590 · ParticleSystem_DestroyAll() · size=152 · insn=38 */
/* @0x1a4590 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a4594 ldr r6, [pc, #0x84] */
/* @0x1a4598 ldr r6, [pc, r6] */
/* @0x1a459c ldr r3, [r6] */
/* @0x1a45a0 cmp r3, #0 */
/* @0x1a45a4 movgt r4, #0 */
/* @0x1a45a8 ble 0x1a45c4 <_Z25ParticleSystem_DestroyAllv+0x34> */
/* @0x1a45ac mov r0, r4 */
/* @0x1a45b0 add r4, r4, #1 */
/* @0x1a45b4 bl 0x1a454c <_Z22ParticleSystem_Destroyi> */
/* @0x1a45b8 ldr r3, [r6] */
/* @0x1a45bc cmp r3, r4 */
/* @0x1a45c0 bgt 0x1a45ac <_Z25ParticleSystem_DestroyAllv+0x1c> */
/* @0x1a45c4 ldr r5, [pc, #0x58] */
/* @0x1a45c8 ldr r5, [pc, r5] */
/* @0x1a45cc ldr r3, [r5] */
/* @0x1a45d0 cmp r3, #0 */
/* @0x1a45d4 movgt r4, #0 */
/* @0x1a45d8 movgt r7, r4 */
/* @0x1a45dc ble 0x1a4604 <_Z25ParticleSystem_DestroyAllv+0x74> */
/* @0x1a45e0 ldr r3, [r5, #0x4] */
/* @0x1a45e4 ldr r0, [r3, r4, lsl #2] */
/* @0x1a45e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a45ec ldr r2, [r5, #0x4] */
/* @0x1a45f0 ldr r3, [r5] */
/* @0x1a45f4 str r7, [r2, r4, lsl #2] */
/* @0x1a45f8 add r4, r4, #1 */
/* @0x1a45fc cmp r3, r4 */
/* @0x1a4600 bgt 0x1a45e0 <_Z25ParticleSystem_DestroyAllv+0x50> */
/* @0x1a4604 ldr r0, [r5, #0x4] */
/* @0x1a4608 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a460c mov r3, #0 */
/* @0x1a4610 str r3, [r5, #0x4] */
/* @0x1a4614 str r3, [r5] */
/* @0x1a4618 str r3, [r6] */
/* @0x1a461c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a4620 eoreq r12, r4, r12, lsl r2 */
/* @0x1a4624 .word 0x0024c1f0 */

/* ── FUNC 0x1a4628 · ParticleSystem_GetLayer(int) · size=56 · insn=14 */
/* @0x1a4628 push {r4, lr} */
/* @0x1a462c mov r4, r0 */
/* @0x1a4630 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a4634 cmp r0, #0 */
/* @0x1a4638 beq 0x1a4654 <_Z23ParticleSystem_GetLayeri+0x2c> */
/* @0x1a463c ldr r3, [pc, #0x18] */
/* @0x1a4640 ldr r3, [pc, r3] */
/* @0x1a4644 ldr r3, [r3, #0x4] */
/* @0x1a4648 ldr r3, [r3, r4, lsl #2] */
/* @0x1a464c ldr r0, [r3, #0x30] */
/* @0x1a4650 pop {r4, pc} */
/* @0x1a4654 mvn r0, #0 */
/* @0x1a4658 pop {r4, pc} */
/* @0x1a465c eoreq r12, r4, r8, ror r1 */

/* ── FUNC 0x1a4660 · ParticleSystem_Layer(int, int) · size=320 · insn=80 */
/* @0x1a4660 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a4664 sub sp, sp, #12 */
/* @0x1a4668 mov r5, r1 */
/* @0x1a466c mov r4, r0 */
/* @0x1a4670 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a4674 cmp r0, #0 */
/* @0x1a4678 beq 0x1a4690 <_Z20ParticleSystem_Layerii+0x30> */
/* @0x1a467c ldr r3, [pc, #0x110] */
/* @0x1a4680 ldr r3, [pc, r3] */
/* @0x1a4684 ldrb r3, [r3] */
/* @0x1a4688 cmp r3, #0 */
/* @0x1a468c bne 0x1a4698 <_Z20ParticleSystem_Layerii+0x38> */
/* @0x1a4690 add sp, sp, #12 */
/* @0x1a4694 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a4698 ldr r6, [pc, #0xf8] */
/* @0x1a469c mov r2, #1 */
/* @0x1a46a0 ldr r7, [pc, #0xf4] */
/* @0x1a46a4 mov r3, #0 */
/* @0x1a46a8 ldr r6, [pc, r6] */
/* @0x1a46ac ldr r7, [pc, r7] */
/* @0x1a46b0 ldr r1, [r6, #0x4] */
/* @0x1a46b4 ldr r0, [r7] */
/* @0x1a46b8 ldr r1, [r1, r4, lsl #2] */
/* @0x1a46bc ldr r1, [r1, #0x2c] */
/* @0x1a46c0 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1a46c4 bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv> */
/* @0x1a46c8 ldr r3, [r6, #0x4] */
/* @0x1a46cc ldr r3, [r3, r4, lsl #2] */
/* @0x1a46d0 str r4, [r0, #0x1c] */
/* @0x1a46d4 mov r8, r0 */
/* @0x1a46d8 str r5, [r3, #0x30] */
/* @0x1a46dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1a46e0 subs r9, r0, #0 */
/* @0x1a46e4 beq 0x1a4690 <_Z20ParticleSystem_Layerii+0x30> */
/* @0x1a46e8 mov r1, r5 */
/* @0x1a46ec bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1a46f0 cmp r0, #0 */
/* @0x1a46f4 beq 0x1a4704 <_Z20ParticleSystem_Layerii+0xa4> */
/* @0x1a46f8 ldr r3, [r7] */
/* @0x1a46fc cmp r9, r3 */
/* @0x1a4700 beq 0x1a4744 <_Z20ParticleSystem_Layerii+0xe4> */
/* @0x1a4704 ldr r3, [r6, #0x4] */
/* @0x1a4708 ldr r4, [r3, r4, lsl #2] */
/* @0x1a470c ldr r3, [r4, #0x2c] */
/* @0x1a4710 cmn r3, #1 */
/* @0x1a4714 bne 0x1a4690 <_Z20ParticleSystem_Layerii+0x30> */
/* @0x1a4718 vldr s15, [r4, #28] */
/* @0x1a471c vcvt.s32.f32 s15, s15 */
/* @0x1a4720 mov r1, #1 */
/* @0x1a4724 ldr r0, [r7] */
/* @0x1a4728 mov r3, r1 */
/* @0x1a472c str r1, [sp] */
/* @0x1a4730 mov r2, r8 */
/* @0x1a4734 vmov r1, s15 */
/* @0x1a4738 bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb> */
/* @0x1a473c str r0, [r4, #0x2c] */
/* @0x1a4740 b 0x1a4690 <_Z20ParticleSystem_Layerii+0x30> */
/* @0x1a4744 ldr r12, [r6, #0x4] */
/* @0x1a4748 mov r1, r0 */
/* @0x1a474c mov r3, #1 */
/* @0x1a4750 mov r0, r9 */
/* @0x1a4754 mov r2, r8 */
/* @0x1a4758 ldr r5, [r12, r4, lsl #2] */
/* @0x1a475c bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1a4760 ldr r3, [r6, #0x4] */
/* @0x1a4764 ldr r3, [r3, r4, lsl #2] */
/* @0x1a4768 str r0, [r5, #0x2c] */
/* @0x1a476c ldr r3, [r3, #0x2c] */
/* @0x1a4770 cmn r3, #1 */
/* @0x1a4774 bne 0x1a4690 <_Z20ParticleSystem_Layerii+0x30> */
/* @0x1a4778 ldr r1, [r8, #0x4] */
/* @0x1a477c mov r0, r9 */
/* @0x1a4780 mov r2, #1 */
/* @0x1a4784 mov r3, #0 */
/* @0x1a4788 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1a478c mov r8, #0 */
/* @0x1a4790 b 0x1a4704 <_Z20ParticleSystem_Layerii+0xa4> */
/* @0x1a4794 eoreq r9, r4, r4, lsr #5 */
/* @0x1a4798 eoreq r12, r4, r0, lsl r1 */
/* @0x1a479c eoreq r9, r4, r12, ror r2 */
