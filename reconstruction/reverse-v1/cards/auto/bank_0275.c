/* libyoyo.so 覆盖卡组 0275
 * 函数 0x2cd3c8..0x2ce6c4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2cd3c8 · b2FrictionJoint::GetReactionTorque(float) const · size=20 · insn=5 */
/* @0x2cd3c8 vmov s14, r1 */
/* @0x2cd3cc vldr s15, [r0, #92] */
/* @0x2cd3d0 vmul.f32 s14, s14, s15 */
/* @0x2cd3d4 vmov r0, s14 */
/* @0x2cd3d8 bx lr */

/* ── FUNC 0x2cd3dc · b2FrictionJoint::~b2FrictionJoint() · size=24 · insn=6 */
/* @0x2cd3dc ldr r3, [pc, #0xc] */
/* @0x2cd3e0 ldr r3, [pc, r3] */
/* @0x2cd3e4 add r3, r3, #8 */
/* @0x2cd3e8 str r3, [r0] */
/* @0x2cd3ec bx lr */
/* @0x2cd3f0 andseq r4, r2, r4, ror r7 */

/* ── FUNC 0x2cd3dc · b2FrictionJoint::~b2FrictionJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cd3f4 · b2FrictionJoint::Dump() · size=268 · insn=67 */
/* @0x2cd3f4 push {r4, r5, r6, lr} */
/* @0x2cd3f8 mov r4, r0 */
/* @0x2cd3fc ldr r2, [r4, #0x30] */
/* @0x2cd400 sub sp, sp, #8 */
/* @0x2cd404 ldr r3, [r4, #0x34] */
/* @0x2cd408 ldr r0, [pc, #0xcc] */
/* @0x2cd40c ldr r6, [r2, #0x8] */
/* @0x2cd410 add r0, pc, r0 */
/* @0x2cd414 ldr r5, [r3, #0x8] */
/* @0x2cd418 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd41c ldr r0, [pc, #0xbc] */
/* @0x2cd420 mov r1, r6 */
/* @0x2cd424 add r0, pc, r0 */
/* @0x2cd428 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd42c ldr r0, [pc, #0xb0] */
/* @0x2cd430 mov r1, r5 */
/* @0x2cd434 add r0, pc, r0 */
/* @0x2cd438 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd43c ldr r0, [pc, #0xa4] */
/* @0x2cd440 ldrb r1, [r4, #0x3d] */
/* @0x2cd444 add r0, pc, r0 */
/* @0x2cd448 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd44c vldr s13, [r4, #68] */
/* @0x2cd450 vldr s14, [r4, #72] */
/* @0x2cd454 vcvt.f64.f32 d5, s13 */
/* @0x2cd458 ldr r0, [pc, #0x8c] */
/* @0x2cd45c add r0, pc, r0 */
/* @0x2cd460 vcvt.f64.f32 d7, s14 */
/* @0x2cd464 vmov r2, r3, d5 */
/* @0x2cd468 vstr d7, [sp] */
/* @0x2cd46c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd470 vldr s13, [r4, #76] */
/* @0x2cd474 vldr s14, [r4, #80] */
/* @0x2cd478 vcvt.f64.f32 d5, s13 */
/* @0x2cd47c ldr r0, [pc, #0x6c] */
/* @0x2cd480 add r0, pc, r0 */
/* @0x2cd484 vcvt.f64.f32 d7, s14 */
/* @0x2cd488 vmov r2, r3, d5 */
/* @0x2cd48c vstr d7, [sp] */
/* @0x2cd490 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd494 vldr s15, [r4, #96] */
/* @0x2cd498 vcvt.f64.f32 d6, s15 */
/* @0x2cd49c ldr r0, [pc, #0x50] */
/* @0x2cd4a0 add r0, pc, r0 */
/* @0x2cd4a4 vmov r2, r3, d6 */
/* @0x2cd4a8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd4ac vldr s15, [r4, #100] */
/* @0x2cd4b0 vcvt.f64.f32 d5, s15 */
/* @0x2cd4b4 ldr r0, [pc, #0x3c] */
/* @0x2cd4b8 add r0, pc, r0 */
/* @0x2cd4bc vmov r2, r3, d5 */
/* @0x2cd4c0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd4c4 ldr r0, [pc, #0x30] */
/* @0x2cd4c8 ldr r1, [r4, #0x38] */
/* @0x2cd4cc add r0, pc, r0 */
/* @0x2cd4d0 add sp, sp, #8 */
/* @0x2cd4d4 pop {r4, r5, r6, lr} */
/* @0x2cd4d8 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cd4dc ldrdeq lr, pc, [r8], -r4 */
/* @0x2cd4e0 andeq lr, r8, r8, lsl #21 */
/* @0x2cd4e4 muleq r8, r4, r10 */
/* @0x2cd4e8 andeq lr, r8, r0, lsr #21 */
/* @0x2cd4ec andeq lr, r8, r12, lsr #21 */
/* @0x2cd4f0 strheq lr, [r8], -r4 */
/* @0x2cd4f4 andeq lr, r8, r0, ror #22 */
/* @0x2cd4f8 andeq lr, r8, r4, ror #22 */
/* @0x2cd4fc andeq lr, r8, r12, ror #21 */

/* ── FUNC 0x2cd500 · b2FrictionJoint::~b2FrictionJoint() · size=40 · insn=10 */
/* @0x2cd500 ldr r3, [pc, #0x1c] */
/* @0x2cd504 push {r4, lr} */
/* @0x2cd508 ldr r3, [pc, r3] */
/* @0x2cd50c mov r4, r0 */
/* @0x2cd510 add r3, r3, #8 */
/* @0x2cd514 str r3, [r0] */
/* @0x2cd518 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cd51c mov r0, r4 */
/* @0x2cd520 pop {r4, pc} */
/* @0x2cd524 andseq r4, r2, r12, asr #12 */

/* ── FUNC 0x2cd528 · b2FrictionJoint::SolveVelocityConstraints(b2SolverData const&) · size=532 · insn=133 */
/* @0x2cd528 push {r4, r5, lr} */
/* @0x2cd52c vldr s13, [r0, #92] */
/* @0x2cd530 mov r4, r0 */
/* @0x2cd534 vldr s5, [r0, #176] */
/* @0x2cd538 ldr r5, [r0, #0x68] */
/* @0x2cd53c vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cd540 ldr r12, [r0, #0x6c] */
/* @0x2cd544 vmov.f32 s2, s13 */
/* @0x2cd548 ldr r0, [r1, #0x1c] */
/* @0x2cd54c vldr s6, [r1] */
/* @0x2cd550 add r2, r5, r5, lsl #1 */
/* @0x2cd554 vldr s11, [r4, #100] */
/* @0x2cd558 add r3, r12, r12, lsl #1 */
/* @0x2cd55c vldr s24, [r4, #156] */
/* @0x2cd560 add r2, r0, r2, lsl #2 */
/* @0x2cd564 vldr s17, [r2, #8] */
/* @0x2cd568 add r3, r0, r3, lsl #2 */
/* @0x2cd56c vldr s16, [r3, #8] */
/* @0x2cd570 vsub.f32 s12, s16, s17 */
/* @0x2cd574 vldr s18, [r3, #4] */
/* @0x2cd578 vldr s20, [r3] */
/* @0x2cd57c vldr s22, [r2, #4] */
/* @0x2cd580 vldr s23, [r2] */
/* @0x2cd584 vldr s10, [r4, #120] */
/* @0x2cd588 vldr s25, [r4, #152] */
/* @0x2cd58c vldr s8, [r4, #124] */
/* @0x2cd590 vldr s9, [r4, #112] */
/* @0x2cd594 vldr s7, [r4, #116] */
/* @0x2cd598 vldr s15, [r4, #172] */
/* @0x2cd59c vldr s3, [r4, #164] */
/* @0x2cd5a0 vldr s14, [r4, #168] */
/* @0x2cd5a4 vldr s4, [r4, #160] */
/* @0x2cd5a8 vldr s26, [r4, #88] */
/* @0x2cd5ac vldr s27, [r4, #84] */
/* @0x2cd5b0 vldr s28, [r4, #96] */
/* @0x2cd5b4 sub sp, sp, #12 */
/* @0x2cd5b8 vldr s21, [r4, #144] */
/* @0x2cd5bc vldr s19, [r4, #148] */
/* @0x2cd5c0 vmls.f32 s2, s5, s12 */
/* @0x2cd5c4 vmul.f32 s11, s6, s11 */
/* @0x2cd5c8 vcmpe.f32 s11, s2 */
/* @0x2cd5cc vneg.f32 s5, s11 */
/* @0x2cd5d0 vmrs APSR_nzcv, fpscr */
/* @0x2cd5d4 vmovgt.f32 s11, s2 */
/* @0x2cd5d8 vcmpe.f32 s5, s11 */
/* @0x2cd5dc vmrs APSR_nzcv, fpscr */
/* @0x2cd5e0 vmovgt.f32 s11, s5 */
/* @0x2cd5e4 vstr s11, [r4, #92] */
/* @0x2cd5e8 vsub.f32 s11, s11, s13 */
/* @0x2cd5ec vmla.f32 s16, s24, s11 */
/* @0x2cd5f0 vmov.f32 s12, s18 */
/* @0x2cd5f4 vmla.f32 s12, s16, s10 */
/* @0x2cd5f8 vmov.f32 s13, s20 */
/* @0x2cd5fc vmls.f32 s17, s25, s11 */
/* @0x2cd600 vmls.f32 s13, s16, s8 */
/* @0x2cd604 vsub.f32 s12, s12, s22 */
/* @0x2cd608 vmls.f32 s12, s17, s9 */
/* @0x2cd60c vsub.f32 s13, s13, s23 */
/* @0x2cd610 vmla.f32 s13, s17, s7 */
/* @0x2cd614 vmul.f32 s15, s12, s15 */
/* @0x2cd618 vmul.f32 s14, s12, s14 */
/* @0x2cd61c vmla.f32 s15, s13, s3 */
/* @0x2cd620 vmla.f32 s14, s13, s4 */
/* @0x2cd624 vsub.f32 s15, s26, s15 */
/* @0x2cd628 vmul.f32 s13, s15, s15 */
/* @0x2cd62c vstr s15, [r4, #88] */
/* @0x2cd630 vsub.f32 s14, s27, s14 */
/* @0x2cd634 vmul.f32 s28, s6, s28 */
/* @0x2cd638 vstr s14, [r4, #84] */
/* @0x2cd63c vmla.f32 s13, s14, s14 */
/* @0x2cd640 vmul.f32 s12, s28, s28 */
/* @0x2cd644 vcmpe.f32 s12, s13 */
/* @0x2cd648 vmrs APSR_nzcv, fpscr */
/* @0x2cd64c bmi 0x2cd6a4 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x17c> */
/* @0x2cd650 vsub.f32 s14, s14, s27 */
/* @0x2cd654 vmul.f32 s12, s14, s7 */
/* @0x2cd658 vmul.f32 s13, s14, s8 */
/* @0x2cd65c vsub.f32 s15, s15, s26 */
/* @0x2cd660 vnmls.f32 s12, s15, s9 */
/* @0x2cd664 vnmls.f32 s13, s15, s10 */
/* @0x2cd668 vmls.f32 s17, s25, s12 */
/* @0x2cd66c vmla.f32 s16, s24, s13 */
/* @0x2cd670 vstr s17, [r2, #8] */
/* @0x2cd674 vmls.f32 s23, s21, s14 */
/* @0x2cd678 vmls.f32 s22, s21, s15 */
/* @0x2cd67c vstr s23, [r2] */
/* @0x2cd680 vmla.f32 s20, s19, s14 */
/* @0x2cd684 vstr s22, [r2, #4] */
/* @0x2cd688 vstr s16, [r3, #8] */
/* @0x2cd68c vmla.f32 s18, s19, s15 */
/* @0x2cd690 vstr s20, [r3] */
/* @0x2cd694 vstr s18, [r3, #4] */
/* @0x2cd698 add sp, sp, #12 */
/* @0x2cd69c vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cd6a0 pop {r4, r5, pc} */
/* @0x2cd6a4 vsqrt.f32 s12, s13 */
/* @0x2cd6a8 vcmp.f32 s12, s12 */
/* @0x2cd6ac vmrs APSR_nzcv, fpscr */
/* @0x2cd6b0 bne 0x2cd704 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x1dc> */
/* @0x2cd6b4 vldr s15, [pc, #124] */
/* @0x2cd6b8 vcmpe.f32 s12, s15 */
/* @0x2cd6bc add r5, r5, r5, lsl #1 */
/* @0x2cd6c0 add r12, r12, r12, lsl #1 */
/* @0x2cd6c4 add r2, r0, r5, lsl #2 */
/* @0x2cd6c8 add r3, r0, r12, lsl #2 */
/* @0x2cd6cc vmrs APSR_nzcv, fpscr */
/* @0x2cd6d0 vmovpl.f32 s13, #1.000000e+00 */
/* @0x2cd6d4 vldrpl s15, [r4, #88] */
/* @0x2cd6d8 vldrpl s14, [r4, #84] */
/* @0x2cd6dc vldrmi s14, [r4, #84] */
/* @0x2cd6e0 vldrmi s15, [r4, #88] */
/* @0x2cd6e4 vdivpl.f32 s12, s13, s12 */
/* @0x2cd6e8 vmulpl.f32 s15, s12, s15 */
/* @0x2cd6ec vmulpl.f32 s14, s12, s14 */
/* @0x2cd6f0 vmul.f32 s15, s28, s15 */
/* @0x2cd6f4 vmul.f32 s14, s28, s14 */
/* @0x2cd6f8 vstr s15, [r4, #88] */
/* @0x2cd6fc vstr s14, [r4, #84] */
/* @0x2cd700 b 0x2cd650 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x128> */
/* @0x2cd704 vmov r0, s13 */
/* @0x2cd708 str r1, [sp, #0x4] */
/* @0x2cd70c bl 0xb6700 <sqrtf@plt> */
/* @0x2cd710 ldr r1, [sp, #0x4] */
/* @0x2cd714 vldr s8, [r4, #124] */
/* @0x2cd718 ldr r5, [r4, #0x68] */
/* @0x2cd71c vldr s10, [r4, #120] */
/* @0x2cd720 ldr r12, [r4, #0x6c] */
/* @0x2cd724 vldr s7, [r4, #116] */
/* @0x2cd728 vldr s9, [r4, #112] */
/* @0x2cd72c vmov s12, r0 */
/* @0x2cd730 ldr r0, [r1, #0x1c] */
/* @0x2cd734 b 0x2cd6b4 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x18c> */
/* @0x2cd738 strlo r0, [r0], #-0 */

/* ── FUNC 0x2cd73c · b2FrictionJoint::InitVelocityConstraints(b2SolverData const&) · size=604 · insn=151 */
/* @0x2cd73c ldr r2, [r0, #0x30] */
/* @0x2cd740 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2cd744 vpush {d8, d9, d10, d11} */
/* @0x2cd748 mov r7, r1 */
/* @0x2cd74c vldr s19, [r2, #136] */
/* @0x2cd750 ldr r3, [r0, #0x34] */
/* @0x2cd754 add r1, r2, #44 */
/* @0x2cd758 ldr r6, [r2, #0x8] */
/* @0x2cd75c mov r4, r0 */
/* @0x2cd760 vldr s18, [r3, #136] */
/* @0x2cd764 ldr r8, [r7, #0x18] */
/* @0x2cd768 ldr r12, [r3, #0x8] */
/* @0x2cd76c add lr, r0, #136 */
/* @0x2cd770 add r10, r0, #128 */
/* @0x2cd774 ldm r1, {r0, r1} */
/* @0x2cd778 str r6, [r4, #0x68] */
/* @0x2cd77c add r6, r6, r6, lsl #1 */
/* @0x2cd780 vldr s16, [r2, #144] */
/* @0x2cd784 add r9, r3, #44 */
/* @0x2cd788 lsl r6, r6, #2 */
/* @0x2cd78c ldr r5, [r7, #0x1c] */
/* @0x2cd790 add r2, r8, r6 */
/* @0x2cd794 str r12, [r4, #0x6c] */
/* @0x2cd798 stm r10, {r0, r1} */
/* @0x2cd79c add r12, r12, r12, lsl #1 */
/* @0x2cd7a0 ldm r9, {r0, r1} */
/* @0x2cd7a4 vldr s17, [r3, #144] */
/* @0x2cd7a8 ldr r9, [r2, #0x8] */
/* @0x2cd7ac lsl r12, r12, #2 */
/* @0x2cd7b0 add r8, r8, r12 */
/* @0x2cd7b4 add r6, r5, r6 */
/* @0x2cd7b8 stm lr, {r0, r1} */
/* @0x2cd7bc vstr s19, [r4, #144] */
/* @0x2cd7c0 mov r0, r9 */
/* @0x2cd7c4 vstr s18, [r4, #148] */
/* @0x2cd7c8 vstr s16, [r4, #152] */
/* @0x2cd7cc vstr s17, [r4, #156] */
/* @0x2cd7d0 add r5, r5, r12 */
/* @0x2cd7d4 bl 0xb6580 <sinf@plt> */
/* @0x2cd7d8 ldr r8, [r8, #0x8] */
/* @0x2cd7dc vmov s22, r0 */
/* @0x2cd7e0 mov r0, r9 */
/* @0x2cd7e4 bl 0xb658c <cosf@plt> */
/* @0x2cd7e8 vmov s21, r0 */
/* @0x2cd7ec mov r0, r8 */
/* @0x2cd7f0 bl 0xb6580 <sinf@plt> */
/* @0x2cd7f4 vmov s20, r0 */
/* @0x2cd7f8 mov r0, r8 */
/* @0x2cd7fc bl 0xb658c <cosf@plt> */
/* @0x2cd800 vldr s11, [r4, #72] */
/* @0x2cd804 vldr s14, [r4, #132] */
/* @0x2cd808 vsub.f32 s14, s11, s14 */
/* @0x2cd80c vldr s15, [r4, #140] */
/* @0x2cd810 vldr s13, [r4, #80] */
/* @0x2cd814 vldr s12, [r4, #76] */
/* @0x2cd818 vldr s8, [r4, #68] */
/* @0x2cd81c vldr s10, [r4, #128] */
/* @0x2cd820 vldr s1, [r6] */
/* @0x2cd824 vldr s2, [r6, #4] */
/* @0x2cd828 vldr s3, [r6, #8] */
/* @0x2cd82c vldr s4, [r5] */
/* @0x2cd830 vldr s5, [r5, #4] */
/* @0x2cd834 vldr s6, [r5, #8] */
/* @0x2cd838 vsub.f32 s13, s13, s15 */
/* @0x2cd83c vldr s15, [r4, #136] */
/* @0x2cd840 vsub.f32 s15, s12, s15 */
/* @0x2cd844 vmul.f32 s12, s14, s21 */
/* @0x2cd848 vmov s9, r0 */
/* @0x2cd84c vmul.f32 s11, s13, s20 */
/* @0x2cd850 vsub.f32 s10, s8, s10 */
/* @0x2cd854 vmul.f32 s14, s14, s22 */
/* @0x2cd858 vmla.f32 s12, s10, s22 */
/* @0x2cd85c vnmls.f32 s11, s15, s9 */
/* @0x2cd860 vstr s12, [r4, #116] */
/* @0x2cd864 ldrb r3, [r7, #0x14] */
/* @0x2cd868 vmul.f32 s13, s13, s9 */
/* @0x2cd86c vstr s11, [r4, #120] */
/* @0x2cd870 vnmls.f32 s14, s10, s21 */
/* @0x2cd874 vmla.f32 s13, s15, s20 */
/* @0x2cd878 vstr s14, [r4, #112] */
/* @0x2cd87c vadd.f32 s8, s19, s18 */
/* @0x2cd880 vstr s13, [r4, #124] */
/* @0x2cd884 vmul.f32 s9, s16, s12 */
/* @0x2cd888 vmul.f32 s15, s17, s11 */
/* @0x2cd88c vmul.f32 s7, s16, s14 */
/* @0x2cd890 vmov.f32 s20, s8 */
/* @0x2cd894 vmla.f32 s20, s9, s12 */
/* @0x2cd898 vmul.f32 s10, s15, s13 */
/* @0x2cd89c vnmul.f32 s0, s16, s14 */
/* @0x2cd8a0 vmla.f32 s8, s7, s14 */
/* @0x2cd8a4 vnmls.f32 s10, s0, s12 */
/* @0x2cd8a8 vmul.f32 s7, s17, s13 */
/* @0x2cd8ac vmov.f32 s9, s20 */
/* @0x2cd8b0 vmla.f32 s8, s15, s11 */
/* @0x2cd8b4 vmla.f32 s9, s7, s13 */
/* @0x2cd8b8 vmul.f32 s15, s10, s10 */
/* @0x2cd8bc vnmls.f32 s15, s9, s8 */
/* @0x2cd8c0 vcmp.f32 s15, #0 */
/* @0x2cd8c4 vmrs APSR_nzcv, fpscr */
/* @0x2cd8c8 vmovne.f32 s7, #1.000000e+00 */
/* @0x2cd8cc vdivne.f32 s15, s7, s15 */
/* @0x2cd8d0 vadd.f32 s7, s16, s17 */
/* @0x2cd8d4 vnmul.f32 s10, s15, s10 */
/* @0x2cd8d8 vmul.f32 s8, s8, s15 */
/* @0x2cd8dc vstr s10, [r4, #164] */
/* @0x2cd8e0 vstr s10, [r4, #168] */
/* @0x2cd8e4 vmul.f32 s15, s9, s15 */
/* @0x2cd8e8 vstr s8, [r4, #160] */
/* @0x2cd8ec vcmpe.f32 s7, #0 */
/* @0x2cd8f0 vstr s15, [r4, #172] */
/* @0x2cd8f4 vmrs APSR_nzcv, fpscr */
/* @0x2cd8f8 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2cd8fc vdivgt.f32 s7, s15, s7 */
/* @0x2cd900 cmp r3, #0 */
/* @0x2cd904 vstr s7, [r4, #176] */
/* @0x2cd908 bne 0x2cd93c <_ZN15b2FrictionJoint23InitVelocityConstraintsERK12b2SolverData+0x200> */
/* @0x2cd90c mov r3, #0 */
/* @0x2cd910 str r3, [r4, #0x54] */
/* @0x2cd914 str r3, [r4, #0x58] */
/* @0x2cd918 str r3, [r4, #0x5c] */
/* @0x2cd91c vpop {d8, d9, d10, d11} */
/* @0x2cd920 vstr s1, [r6] */
/* @0x2cd924 vstr s2, [r6, #4] */
/* @0x2cd928 vstr s3, [r6, #8] */
/* @0x2cd92c vstr s4, [r5] */
/* @0x2cd930 vstr s5, [r5, #4] */
/* @0x2cd934 vstr s6, [r5, #8] */
/* @0x2cd938 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2cd93c vldr s9, [r7, #8] */
/* @0x2cd940 vldr s10, [r4, #84] */
/* @0x2cd944 vmul.f32 s10, s9, s10 */
/* @0x2cd948 vldr s15, [r4, #88] */
/* @0x2cd94c vldr s8, [r4, #92] */
/* @0x2cd950 vmul.f32 s15, s9, s15 */
/* @0x2cd954 vstr s10, [r4, #84] */
/* @0x2cd958 vmul.f32 s12, s12, s10 */
/* @0x2cd95c vstr s15, [r4, #88] */
/* @0x2cd960 vmul.f32 s13, s13, s10 */
/* @0x2cd964 vnmls.f32 s12, s14, s15 */
/* @0x2cd968 vnmls.f32 s13, s11, s15 */
/* @0x2cd96c vmul.f32 s14, s9, s8 */
/* @0x2cd970 vadd.f32 s12, s14, s12 */
/* @0x2cd974 vstr s14, [r4, #92] */
/* @0x2cd978 vadd.f32 s13, s14, s13 */
/* @0x2cd97c vmls.f32 s1, s19, s10 */
/* @0x2cd980 vmla.f32 s4, s18, s10 */
/* @0x2cd984 vmls.f32 s2, s19, s15 */
/* @0x2cd988 vmla.f32 s5, s18, s15 */
/* @0x2cd98c vmls.f32 s3, s16, s12 */
/* @0x2cd990 vmla.f32 s6, s17, s13 */
/* @0x2cd994 b 0x2cd91c <_ZN15b2FrictionJoint23InitVelocityConstraintsERK12b2SolverData+0x1e0> */

/* ── FUNC 0x2cd998 · b2FrictionJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&) · size=124 · insn=31 */
/* @0x2cd998 vldr s15, [r1, #16] */
/* @0x2cd99c vldr s14, [r3, #4] */
/* @0x2cd9a0 vsub.f32 s14, s14, s15 */
/* @0x2cd9a4 vldr s9, [r1, #20] */
/* @0x2cd9a8 vldr s8, [r1, #24] */
/* @0x2cd9ac vldr s6, [r3] */
/* @0x2cd9b0 vldr s10, [r1, #12] */
/* @0x2cd9b4 vldr s12, [r2, #20] */
/* @0x2cd9b8 vldr s11, [r2, #24] */
/* @0x2cd9bc vldr s15, [r2, #16] */
/* @0x2cd9c0 vldr s7, [r2, #12] */
/* @0x2cd9c4 str r1, [r0, #0x8] */
/* @0x2cd9c8 str r2, [r0, #0xc] */
/* @0x2cd9cc vmul.f32 s13, s14, s9 */
/* @0x2cd9d0 vmul.f32 s14, s14, s8 */
/* @0x2cd9d4 vsub.f32 s10, s6, s10 */
/* @0x2cd9d8 vmla.f32 s13, s10, s8 */
/* @0x2cd9dc vmls.f32 s14, s9, s10 */
/* @0x2cd9e0 vstr s13, [r0, #20] */
/* @0x2cd9e4 vstr s14, [r0, #24] */
/* @0x2cd9e8 vldr s14, [r3, #4] */
/* @0x2cd9ec vsub.f32 s15, s14, s15 */
/* @0x2cd9f0 vldr s13, [r3] */
/* @0x2cd9f4 vmul.f32 s14, s15, s12 */
/* @0x2cd9f8 vmul.f32 s15, s15, s11 */
/* @0x2cd9fc vsub.f32 s13, s13, s7 */
/* @0x2cda00 vmla.f32 s14, s13, s11 */
/* @0x2cda04 vmls.f32 s15, s12, s13 */
/* @0x2cda08 vstr s14, [r0, #28] */
/* @0x2cda0c vstr s15, [r0, #32] */
/* @0x2cda10 bx lr */

/* ── FUNC 0x2cda14 · b2FrictionJoint::b2FrictionJoint(b2FrictionJointDef const*) · size=108 · insn=27 */
/* @0x2cda14 push {r3, r4, r5, r6, r7, lr} */
/* @0x2cda18 mov r4, r0 */
/* @0x2cda1c mov r5, r1 */
/* @0x2cda20 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2cda24 add r3, r5, #20 */
/* @0x2cda28 ldr r2, [pc, #0x4c] */
/* @0x2cda2c add r6, r5, #28 */
/* @0x2cda30 ldr r7, [r5, #0x24] */
/* @0x2cda34 ldm r3, {r0, r1} */
/* @0x2cda38 ldr r2, [pc, r2] */
/* @0x2cda3c mov r3, r4 */
/* @0x2cda40 add r2, r2, #8 */
/* @0x2cda44 str r2, [r3], #68 */
/* @0x2cda48 add r12, r4, #76 */
/* @0x2cda4c stm r3, {r0, r1} */
/* @0x2cda50 mov r3, #0 */
/* @0x2cda54 ldm r6, {r0, r1} */
/* @0x2cda58 ldr r2, [r5, #0x28] */
/* @0x2cda5c stm r12, {r0, r1} */
/* @0x2cda60 mov r0, r4 */
/* @0x2cda64 str r7, [r4, #0x60] */
/* @0x2cda68 str r2, [r4, #0x64] */
/* @0x2cda6c str r3, [r4, #0x54] */
/* @0x2cda70 str r3, [r4, #0x58] */
/* @0x2cda74 str r3, [r4, #0x5c] */
/* @0x2cda78 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2cda7c andseq r4, r2, r4, lsr #2 */

/* ── FUNC 0x2cda14 · b2FrictionJoint::b2FrictionJoint(b2FrictionJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cda80 · b2FrictionJoint::SetMaxForce(float) · size=152 · insn=38 */
/* @0x2cda80 push {r4, lr} */
/* @0x2cda84 vpush {d8} */
/* @0x2cda88 vmov s16, r1 */
/* @0x2cda8c ldr r3, [pc, #0x7c] */
/* @0x2cda90 sub sp, sp, #16 */
/* @0x2cda94 vcmp.f32 s16, s16 */
/* @0x2cda98 mov r4, r0 */
/* @0x2cda9c ldr r3, [pc, r3] */
/* @0x2cdaa0 ldr r3, [r3] */
/* @0x2cdaa4 vmrs APSR_nzcv, fpscr */
/* @0x2cdaa8 bne 0x2cdad0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x50> */
/* @0x2cdaac mov r1, #0 */
/* @0x2cdab0 movw r2, #0x7f80 */
/* @0x2cdab4 strh r1, [sp] */
/* @0x2cdab8 strh r2, [sp, #2] */
/* @0x2cdabc vldr s15, [sp] */
/* @0x2cdac0 vneg.f32 s14, s15 */
/* @0x2cdac4 vcmpe.f32 s16, s14 */
/* @0x2cdac8 vmrs APSR_nzcv, fpscr */
/* @0x2cdacc bgt 0x2cdaf0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x70> */
/* @0x2cdad0 mov r0, #0 */
/* @0x2cdad4 ldr r1, [pc, #0x38] */
/* @0x2cdad8 add r1, pc, r1 */
/* @0x2cdadc blx r3 */
/* @0x2cdae0 vstr s16, [r4, #96] */
/* @0x2cdae4 add sp, sp, #16 */
/* @0x2cdae8 vpop {d8} */
/* @0x2cdaec pop {r4, pc} */
/* @0x2cdaf0 vcmpe.f32 s16, s15 */
/* @0x2cdaf4 vmrs APSR_nzcv, fpscr */
/* @0x2cdaf8 bpl 0x2cdad0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x50> */
/* @0x2cdafc vcmpe.f32 s16, #0 */
/* @0x2cdb00 vmrs APSR_nzcv, fpscr */
/* @0x2cdb04 movge r0, #1 */
/* @0x2cdb08 bge 0x2cdad4 <_ZN15b2FrictionJoint11SetMaxForceEf+0x54> */
/* @0x2cdb0c b 0x2cdad0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x50> */
/* @0x2cdb10 andseq r3, r2, r12, lsr #20 */
/* @0x2cdb14 .word 0x0008f8d0 */

/* ── FUNC 0x2cdb18 · b2FrictionJoint::GetMaxForce() const · size=8 · insn=2 */
/* @0x2cdb18 ldr r0, [r0, #0x60] */
/* @0x2cdb1c bx lr */

/* ── FUNC 0x2cdb20 · b2FrictionJoint::SetMaxTorque(float) · size=152 · insn=38 */
/* @0x2cdb20 push {r4, lr} */
/* @0x2cdb24 vpush {d8} */
/* @0x2cdb28 vmov s16, r1 */
/* @0x2cdb2c ldr r3, [pc, #0x7c] */
/* @0x2cdb30 sub sp, sp, #16 */
/* @0x2cdb34 vcmp.f32 s16, s16 */
/* @0x2cdb38 mov r4, r0 */
/* @0x2cdb3c ldr r3, [pc, r3] */
/* @0x2cdb40 ldr r3, [r3] */
/* @0x2cdb44 vmrs APSR_nzcv, fpscr */
/* @0x2cdb48 bne 0x2cdb70 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x50> */
/* @0x2cdb4c mov r1, #0 */
/* @0x2cdb50 movw r2, #0x7f80 */
/* @0x2cdb54 strh r1, [sp] */
/* @0x2cdb58 strh r2, [sp, #2] */
/* @0x2cdb5c vldr s15, [sp] */
/* @0x2cdb60 vneg.f32 s14, s15 */
/* @0x2cdb64 vcmpe.f32 s16, s14 */
/* @0x2cdb68 vmrs APSR_nzcv, fpscr */
/* @0x2cdb6c bgt 0x2cdb90 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x70> */
/* @0x2cdb70 mov r0, #0 */
/* @0x2cdb74 ldr r1, [pc, #0x38] */
/* @0x2cdb78 add r1, pc, r1 */
/* @0x2cdb7c blx r3 */
/* @0x2cdb80 vstr s16, [r4, #100] */
/* @0x2cdb84 add sp, sp, #16 */
/* @0x2cdb88 vpop {d8} */
/* @0x2cdb8c pop {r4, pc} */
/* @0x2cdb90 vcmpe.f32 s16, s15 */
/* @0x2cdb94 vmrs APSR_nzcv, fpscr */
/* @0x2cdb98 bpl 0x2cdb70 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x50> */
/* @0x2cdb9c vcmpe.f32 s16, #0 */
/* @0x2cdba0 vmrs APSR_nzcv, fpscr */
/* @0x2cdba4 movge r0, #1 */
/* @0x2cdba8 bge 0x2cdb74 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x54> */
/* @0x2cdbac b 0x2cdb70 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x50> */
/* @0x2cdbb0 andseq r3, r2, r12, lsl #19 */
/* @0x2cdbb4 strheq pc, [r8], -r8 */

/* ── FUNC 0x2cdbb8 · b2FrictionJoint::GetMaxTorque() const · size=8 · insn=2 */
/* @0x2cdbb8 ldr r0, [r0, #0x64] */
/* @0x2cdbbc bx lr */

/* ── FUNC 0x2cdbc0 · b2Joint::Create(b2JointDef const*, b2BlockAllocator*) · size=472 · insn=118 */
/* @0x2cdbc0 push {r3, r4, r5, lr} */
/* @0x2cdbc4 mov r4, r0 */
/* @0x2cdbc8 ldr r3, [r0] */
/* @0x2cdbcc sub r3, r3, #1 */
/* @0x2cdbd0 cmp r3, #10 */
/* @0x2cdbd4 addls pc, pc, r3, lsl #2 */
/* @0x2cdbd8 b 0x2cdd6c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x1ac> */
/* @0x2cdbdc b 0x2cdc2c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x6c> */
/* @0x2cdbe0 b 0x2cdc4c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x8c> */
/* @0x2cdbe4 b 0x2cdc6c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0xac> */
/* @0x2cdbe8 b 0x2cdc8c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0xcc> */
/* @0x2cdbec b 0x2cdcac <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0xec> */
/* @0x2cdbf0 b 0x2cdccc <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x10c> */
/* @0x2cdbf4 b 0x2cdcec <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x12c> */
/* @0x2cdbf8 b 0x2cdd0c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x14c> */
/* @0x2cdbfc b 0x2cdd2c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x16c> */
/* @0x2cdc00 b 0x2cdd4c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x18c> */
/* @0x2cdc04 b 0x2cdc08 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x48> */
/* @0x2cdc08 mov r0, r1 */
/* @0x2cdc0c mov r1, #192 */
/* @0x2cdc10 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdc14 subs r5, r0, #0 */
/* @0x2cdc18 beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc1c mov r1, r4 */
/* @0x2cdc20 bl 0x2ce6c4 <_ZN12b2MotorJointC2EPK15b2MotorJointDef> */
/* @0x2cdc24 mov r0, r5 */
/* @0x2cdc28 pop {r3, r4, r5, pc} */
/* @0x2cdc2c mov r0, r1 */
/* @0x2cdc30 mov r1, #228 */
/* @0x2cdc34 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdc38 subs r5, r0, #0 */
/* @0x2cdc3c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc40 mov r1, r4 */
/* @0x2cdc44 bl 0x2d2064 <_ZN15b2RevoluteJointC2EPK18b2RevoluteJointDef> */
/* @0x2cdc48 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc4c mov r0, r1 */
/* @0x2cdc50 mov r1, #256 */
/* @0x2cdc54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdc58 subs r5, r0, #0 */
/* @0x2cdc5c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc60 mov r1, r4 */
/* @0x2cdc64 bl 0x2d0028 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef> */
/* @0x2cdc68 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc6c mov r0, r1 */
/* @0x2cdc70 mov r1, #176 */
/* @0x2cdc74 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdc78 subs r5, r0, #0 */
/* @0x2cdc7c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc80 mov r1, r4 */
/* @0x2cdc84 bl 0x2cd2ac <_ZN15b2DistanceJointC2EPK18b2DistanceJointDef> */
/* @0x2cdc88 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdc8c mov r0, r1 */
/* @0x2cdc90 mov r1, #196 */
/* @0x2cdc94 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdc98 subs r5, r0, #0 */
/* @0x2cdc9c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdca0 mov r1, r4 */
/* @0x2cdca4 bl 0x2d1084 <_ZN13b2PulleyJointC2EPK16b2PulleyJointDef> */
/* @0x2cdca8 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdcac mov r0, r1 */
/* @0x2cdcb0 mov r1, #168 */
/* @0x2cdcb4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdcb8 subs r5, r0, #0 */
/* @0x2cdcbc beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdcc0 mov r1, r4 */
/* @0x2cdcc4 bl 0x2cedbc <_ZN12b2MouseJointC2EPK15b2MouseJointDef> */
/* @0x2cdcc8 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdccc mov r0, r1 */
/* @0x2cdcd0 mov r1, #276 */
/* @0x2cdcd4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdcd8 subs r5, r0, #0 */
/* @0x2cdcdc beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdce0 mov r1, r4 */
/* @0x2cdce4 bl 0x2e4588 <_ZN11b2GearJointC2EPK14b2GearJointDef> */
/* @0x2cdce8 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdcec mov r0, r1 */
/* @0x2cdcf0 mov r1, #224 */
/* @0x2cdcf4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdcf8 subs r5, r0, #0 */
/* @0x2cdcfc beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd00 mov r1, r4 */
/* @0x2cdd04 bl 0x2d4214 <_ZN12b2WheelJointC2EPK15b2WheelJointDef> */
/* @0x2cdd08 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd0c mov r0, r1 */
/* @0x2cdd10 mov r1, #208 */
/* @0x2cdd14 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdd18 subs r5, r0, #0 */
/* @0x2cdd1c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd20 mov r1, r4 */
/* @0x2cdd24 bl 0x2d3724 <_ZN11b2WeldJointC2EPK14b2WeldJointDef> */
/* @0x2cdd28 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd2c mov r0, r1 */
/* @0x2cdd30 mov r1, #180 */
/* @0x2cdd34 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdd38 subs r5, r0, #0 */
/* @0x2cdd3c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd40 mov r1, r4 */
/* @0x2cdd44 bl 0x2cda14 <_ZN15b2FrictionJointC2EPK18b2FrictionJointDef> */
/* @0x2cdd48 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd4c mov r0, r1 */
/* @0x2cdd50 mov r1, #168 */
/* @0x2cdd54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2cdd58 subs r5, r0, #0 */
/* @0x2cdd5c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd60 mov r1, r4 */
/* @0x2cdd64 bl 0x2d2b48 <_ZN11b2RopeJointC2EPK14b2RopeJointDef> */
/* @0x2cdd68 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd6c ldr r3, [pc, #0x1c] */
/* @0x2cdd70 mov r0, #0 */
/* @0x2cdd74 ldr r1, [pc, #0x18] */
/* @0x2cdd78 mov r5, r0 */
/* @0x2cdd7c ldr r3, [pc, r3] */
/* @0x2cdd80 add r1, pc, r1 */
/* @0x2cdd84 ldr r3, [r3] */
/* @0x2cdd88 blx r3 */
/* @0x2cdd8c b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64> */
/* @0x2cdd90 andseq r3, r2, r12, asr #14 */
/* @0x2cdd94 andeq pc, r8, r0, asr #14 */

/* ── FUNC 0x2cdd98 · b2Joint::Destroy(b2Joint*, b2BlockAllocator*) · size=328 · insn=82 */
/* @0x2cdd98 push {r3, r4, r5, lr} */
/* @0x2cdd9c mov r4, r0 */
/* @0x2cdda0 ldr r3, [r0] */
/* @0x2cdda4 mov r5, r1 */
/* @0x2cdda8 ldr r3, [r3, #0x18] */
/* @0x2cddac blx r3 */
/* @0x2cddb0 ldr r3, [r4, #0x4] */
/* @0x2cddb4 sub r3, r3, #1 */
/* @0x2cddb8 cmp r3, #10 */
/* @0x2cddbc addls pc, pc, r3, lsl #2 */
/* @0x2cddc0 b 0x2cdeb8 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x120> */
/* @0x2cddc4 b 0x2cde04 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x6c> */
/* @0x2cddc8 b 0x2cde18 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x80> */
/* @0x2cddcc b 0x2cde2c <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x94> */
/* @0x2cddd0 b 0x2cde40 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xa8> */
/* @0x2cddd4 b 0x2cddf0 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x58> */
/* @0x2cddd8 b 0x2cde68 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xd0> */
/* @0x2cdddc b 0x2cde7c <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xe4> */
/* @0x2cdde0 b 0x2cde90 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xf8> */
/* @0x2cdde4 b 0x2cdea4 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x10c> */
/* @0x2cdde8 b 0x2cddf0 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x58> */
/* @0x2cddec b 0x2cde54 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xbc> */
/* @0x2cddf0 mov r0, r5 */
/* @0x2cddf4 mov r1, r4 */
/* @0x2cddf8 mov r2, #168 */
/* @0x2cddfc pop {r3, r4, r5, lr} */
/* @0x2cde00 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde04 mov r0, r5 */
/* @0x2cde08 mov r1, r4 */
/* @0x2cde0c mov r2, #228 */
/* @0x2cde10 pop {r3, r4, r5, lr} */
/* @0x2cde14 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde18 mov r0, r5 */
/* @0x2cde1c mov r1, r4 */
/* @0x2cde20 mov r2, #256 */
/* @0x2cde24 pop {r3, r4, r5, lr} */
/* @0x2cde28 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde2c mov r0, r5 */
/* @0x2cde30 mov r1, r4 */
/* @0x2cde34 mov r2, #176 */
/* @0x2cde38 pop {r3, r4, r5, lr} */
/* @0x2cde3c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde40 mov r0, r5 */
/* @0x2cde44 mov r1, r4 */
/* @0x2cde48 mov r2, #196 */
/* @0x2cde4c pop {r3, r4, r5, lr} */
/* @0x2cde50 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde54 mov r0, r5 */
/* @0x2cde58 mov r1, r4 */
/* @0x2cde5c mov r2, #192 */
/* @0x2cde60 pop {r3, r4, r5, lr} */
/* @0x2cde64 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde68 mov r0, r5 */
/* @0x2cde6c mov r1, r4 */
/* @0x2cde70 mov r2, #276 */
/* @0x2cde74 pop {r3, r4, r5, lr} */
/* @0x2cde78 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde7c mov r0, r5 */
/* @0x2cde80 mov r1, r4 */
/* @0x2cde84 mov r2, #224 */
/* @0x2cde88 pop {r3, r4, r5, lr} */
/* @0x2cde8c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cde90 mov r0, r5 */
/* @0x2cde94 mov r1, r4 */
/* @0x2cde98 mov r2, #208 */
/* @0x2cde9c pop {r3, r4, r5, lr} */
/* @0x2cdea0 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cdea4 mov r0, r5 */
/* @0x2cdea8 mov r1, r4 */
/* @0x2cdeac mov r2, #180 */
/* @0x2cdeb0 pop {r3, r4, r5, lr} */
/* @0x2cdeb4 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2cdeb8 ldr r3, [pc, #0x18] */
/* @0x2cdebc mov r0, #0 */
/* @0x2cdec0 ldr r1, [pc, #0x14] */
/* @0x2cdec4 ldr r3, [pc, r3] */
/* @0x2cdec8 add r1, pc, r1 */
/* @0x2cdecc ldr r3, [r3] */
/* @0x2cded0 blx r3 */
/* @0x2cded4 pop {r3, r4, r5, pc} */
/* @0x2cded8 andseq r3, r2, r4, lsl #12 */
/* @0x2cdedc .word 0x0008f5f8 */

/* ── FUNC 0x2cdee0 · b2Joint::b2Joint(b2JointDef const*) · size=180 · insn=45 */
/* @0x2cdee0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2cdee4 mov r4, r0 */
/* @0x2cdee8 mov r5, r1 */
/* @0x2cdeec ldr r0, [r1, #0x8] */
/* @0x2cdef0 ldr r3, [pc, #0x90] */
/* @0x2cdef4 ldr r1, [r1, #0xc] */
/* @0x2cdef8 ldr r2, [pc, #0x8c] */
/* @0x2cdefc ldr r3, [pc, r3] */
/* @0x2cdf00 subs r0, r0, r1 */
/* @0x2cdf04 ldr r1, [pc, #0x84] */
/* @0x2cdf08 ldr r2, [pc, r2] */
/* @0x2cdf0c ldr r3, [r3] */
/* @0x2cdf10 add r2, r2, #8 */
/* @0x2cdf14 movne r0, #1 */
/* @0x2cdf18 str r2, [r4] */
/* @0x2cdf1c add r1, pc, r1 */
/* @0x2cdf20 blx r3 */
/* @0x2cdf24 ldr r7, [r5] */
/* @0x2cdf28 ldr r6, [r5, #0x8] */
/* @0x2cdf2c mov r3, #0 */
/* @0x2cdf30 ldr r12, [r5, #0xc] */
/* @0x2cdf34 mov r0, r4 */
/* @0x2cdf38 ldrb r1, [r5, #0x10] */
/* @0x2cdf3c ldr r2, [r5, #0x4] */
/* @0x2cdf40 str r7, [r4, #0x4] */
/* @0x2cdf44 str r6, [r4, #0x30] */
/* @0x2cdf48 str r12, [r4, #0x34] */
/* @0x2cdf4c strb r1, [r4, #0x3d] */
/* @0x2cdf50 str r2, [r4, #0x40] */
/* @0x2cdf54 str r3, [r4, #0x8] */
/* @0x2cdf58 str r3, [r4, #0xc] */
/* @0x2cdf5c str r3, [r4, #0x38] */
/* @0x2cdf60 strb r3, [r4, #0x3c] */
/* @0x2cdf64 str r3, [r4, #0x14] */
/* @0x2cdf68 str r3, [r4, #0x10] */
/* @0x2cdf6c str r3, [r4, #0x18] */
/* @0x2cdf70 str r3, [r4, #0x1c] */
/* @0x2cdf74 str r3, [r4, #0x24] */
/* @0x2cdf78 str r3, [r4, #0x20] */
/* @0x2cdf7c str r3, [r4, #0x28] */
/* @0x2cdf80 str r3, [r4, #0x2c] */
/* @0x2cdf84 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2cdf88 andseq r3, r2, r12, asr #11 */
/* @0x2cdf8c andseq r3, r2, r12, asr #24 */
/* @0x2cdf90 strheq pc, [r8], -r12 */

/* ── FUNC 0x2cdee0 · b2Joint::b2Joint(b2JointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cdf94 · b2Joint::IsActive() const · size=40 · insn=10 */
/* @0x2cdf94 ldr r3, [r0, #0x30] */
/* @0x2cdf98 ldrh r3, [r3, #4] */
/* @0x2cdf9c and r3, r3, #32 */
/* @0x2cdfa0 uxth r3, r3 */
/* @0x2cdfa4 cmp r3, #0 */
/* @0x2cdfa8 ldrne r3, [r0, #0x34] */
/* @0x2cdfac ldrhne r0, [r3, #4] */
/* @0x2cdfb0 ubfxne r0, r0, #0x5, #0x1 */
/* @0x2cdfb4 moveq r0, r3 */
/* @0x2cdfb8 bx lr */

/* ── FUNC 0x2cdfbc · b2MotorJoint::SolvePositionConstraints(b2SolverData const&) · size=8 · insn=2 */
/* @0x2cdfbc mov r0, #1 */
/* @0x2cdfc0 bx lr */

/* ── FUNC 0x2cdfc4 · b2MotorJoint::GetAnchorA() const · size=28 · insn=7 */
/* @0x2cdfc4 ldr r2, [r1, #0x30] */
/* @0x2cdfc8 mov r3, r0 */
/* @0x2cdfcc add r2, r2, #12 */
/* @0x2cdfd0 ldm r2, {r0, r1} */
/* @0x2cdfd4 stm r3, {r0, r1} */
/* @0x2cdfd8 mov r0, r3 */
/* @0x2cdfdc bx lr */

/* ── FUNC 0x2cdfe0 · b2MotorJoint::GetAnchorB() const · size=28 · insn=7 */
/* @0x2cdfe0 ldr r2, [r1, #0x34] */
/* @0x2cdfe4 mov r3, r0 */
/* @0x2cdfe8 add r2, r2, #12 */
/* @0x2cdfec ldm r2, {r0, r1} */
/* @0x2cdff0 stm r3, {r0, r1} */
/* @0x2cdff4 mov r0, r3 */
/* @0x2cdff8 bx lr */

/* ── FUNC 0x2cdffc · b2MotorJoint::GetReactionForce(float) const · size=32 · insn=8 */
/* @0x2cdffc vmov s15, r2 */
/* @0x2ce000 vldr s14, [r1, #84] */
/* @0x2ce004 vldr s13, [r1, #80] */
/* @0x2ce008 vmul.f32 s14, s15, s14 */
/* @0x2ce00c vmul.f32 s15, s15, s13 */
/* @0x2ce010 vstr s14, [r0, #4] */
/* @0x2ce014 vstr s15, [r0] */
/* @0x2ce018 bx lr */

/* ── FUNC 0x2ce01c · b2MotorJoint::GetReactionTorque(float) const · size=20 · insn=5 */
/* @0x2ce01c vmov s14, r1 */
/* @0x2ce020 vldr s15, [r0, #88] */
/* @0x2ce024 vmul.f32 s14, s14, s15 */
/* @0x2ce028 vmov r0, s14 */
/* @0x2ce02c bx lr */

/* ── FUNC 0x2ce030 · b2MotorJoint::~b2MotorJoint() · size=24 · insn=6 */
/* @0x2ce030 ldr r3, [pc, #0xc] */
/* @0x2ce034 ldr r3, [pc, r3] */
/* @0x2ce038 add r3, r3, #8 */
/* @0x2ce03c str r3, [r0] */
/* @0x2ce040 bx lr */
/* @0x2ce044 andseq r3, r2, r0, lsr #22 */

/* ── FUNC 0x2ce030 · b2MotorJoint::~b2MotorJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2ce048 · b2MotorJoint::Dump() · size=284 · insn=71 */
/* @0x2ce048 push {r4, r5, r6, lr} */
/* @0x2ce04c mov r4, r0 */
/* @0x2ce050 ldr r2, [r4, #0x30] */
/* @0x2ce054 sub sp, sp, #8 */
/* @0x2ce058 ldr r3, [r4, #0x34] */
/* @0x2ce05c ldr r0, [pc, #0xd8] */
/* @0x2ce060 ldr r6, [r2, #0x8] */
/* @0x2ce064 add r0, pc, r0 */
/* @0x2ce068 ldr r5, [r3, #0x8] */
/* @0x2ce06c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce070 ldr r0, [pc, #0xc8] */
/* @0x2ce074 mov r1, r6 */
/* @0x2ce078 add r0, pc, r0 */
/* @0x2ce07c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce080 ldr r0, [pc, #0xbc] */
/* @0x2ce084 mov r1, r5 */
/* @0x2ce088 add r0, pc, r0 */
/* @0x2ce08c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce090 ldr r0, [pc, #0xb0] */
/* @0x2ce094 ldrb r1, [r4, #0x3d] */
/* @0x2ce098 add r0, pc, r0 */
/* @0x2ce09c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce0a0 vldr s14, [r4, #72] */
/* @0x2ce0a4 vcvt.f64.f32 d7, s14 */
/* @0x2ce0a8 vldr s13, [r4, #68] */
/* @0x2ce0ac ldr r0, [pc, #0x98] */
/* @0x2ce0b0 add r0, pc, r0 */
/* @0x2ce0b4 vstr d7, [sp] */
/* @0x2ce0b8 vcvt.f64.f32 d7, s13 */
/* @0x2ce0bc vmov r2, r3, d7 */
/* @0x2ce0c0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce0c4 vldr s15, [r4, #76] */
/* @0x2ce0c8 vcvt.f64.f32 d6, s15 */
/* @0x2ce0cc ldr r0, [pc, #0x7c] */
/* @0x2ce0d0 add r0, pc, r0 */
/* @0x2ce0d4 vmov r2, r3, d6 */
/* @0x2ce0d8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce0dc vldr s15, [r4, #92] */
/* @0x2ce0e0 vcvt.f64.f32 d6, s15 */
/* @0x2ce0e4 ldr r0, [pc, #0x68] */
/* @0x2ce0e8 add r0, pc, r0 */
/* @0x2ce0ec vmov r2, r3, d6 */
/* @0x2ce0f0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce0f4 vldr s15, [r4, #96] */
/* @0x2ce0f8 vcvt.f64.f32 d6, s15 */
/* @0x2ce0fc ldr r0, [pc, #0x54] */
/* @0x2ce100 add r0, pc, r0 */
/* @0x2ce104 vmov r2, r3, d6 */
/* @0x2ce108 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce10c vldr s15, [r4, #100] */
/* @0x2ce110 vcvt.f64.f32 d6, s15 */
/* @0x2ce114 ldr r0, [pc, #0x40] */
/* @0x2ce118 add r0, pc, r0 */
/* @0x2ce11c vmov r2, r3, d6 */
/* @0x2ce120 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce124 ldr r0, [pc, #0x34] */
/* @0x2ce128 ldr r1, [r4, #0x38] */
/* @0x2ce12c add r0, pc, r0 */
/* @0x2ce130 add sp, sp, #8 */
/* @0x2ce134 pop {r4, r5, r6, lr} */
/* @0x2ce138 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2ce13c ldrdeq sp, lr, [r8], -r4 */
/* @0x2ce140 andeq sp, r8, r4, lsr lr */
/* @0x2ce144 andeq sp, r8, r0, asr #28 */
/* @0x2ce148 andeq sp, r8, r12, asr #28 */
/* @0x2ce14c andeq sp, r8, r0, lsr #31 */
/* @0x2ce150 andeq sp, r8, r12, lsr #31 */
/* @0x2ce154 andeq sp, r8, r8, lsl pc */
/* @0x2ce158 andeq sp, r8, r12, lsl pc */
/* @0x2ce15c andeq sp, r8, r4, lsl #31 */
/* @0x2ce160 andeq sp, r8, r12, lsl #29 */

/* ── FUNC 0x2ce164 · b2MotorJoint::~b2MotorJoint() · size=40 · insn=10 */
/* @0x2ce164 ldr r3, [pc, #0x1c] */
/* @0x2ce168 push {r4, lr} */
/* @0x2ce16c ldr r3, [pc, r3] */
/* @0x2ce170 mov r4, r0 */
/* @0x2ce174 add r3, r3, #8 */
/* @0x2ce178 str r3, [r0] */
/* @0x2ce17c bl 0x27d1d0 <_ZdlPv> */
/* @0x2ce180 mov r0, r4 */
/* @0x2ce184 pop {r4, pc} */
/* @0x2ce188 andseq r3, r2, r8, ror #19 */

/* ── FUNC 0x2ce18c · b2MotorJoint::SolveVelocityConstraints(b2SolverData const&) · size=568 · insn=142 */
/* @0x2ce18c push {r4, r5, lr} */
/* @0x2ce190 vldr s10, [r0, #100] */
/* @0x2ce194 mov r4, r0 */
/* @0x2ce198 vldr s15, [r1, #4] */
/* @0x2ce19c ldr r5, [r0, #0x68] */
/* @0x2ce1a0 vmul.f32 s10, s10, s15 */
/* @0x2ce1a4 ldr r12, [r0, #0x6c] */
/* @0x2ce1a8 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2ce1ac ldr r0, [r1, #0x1c] */
/* @0x2ce1b0 vldr s14, [r4, #152] */
/* @0x2ce1b4 add r2, r5, r5, lsl #1 */
/* @0x2ce1b8 vldr s13, [r4, #88] */
/* @0x2ce1bc add r3, r12, r12, lsl #1 */
/* @0x2ce1c0 vldr s15, [r4, #188] */
/* @0x2ce1c4 add r2, r0, r2, lsl #2 */
/* @0x2ce1c8 vldr s17, [r2, #8] */
/* @0x2ce1cc add r3, r0, r3, lsl #2 */
/* @0x2ce1d0 vldr s16, [r3, #8] */
/* @0x2ce1d4 vldr s4, [r1] */
/* @0x2ce1d8 vldr s9, [r4, #96] */
/* @0x2ce1dc vldr s28, [r4, #148] */
/* @0x2ce1e0 vldr s24, [r4, #168] */
/* @0x2ce1e4 vldr s18, [r3, #4] */
/* @0x2ce1e8 vldr s7, [r4, #120] */
/* @0x2ce1ec vldr s25, [r4, #164] */
/* @0x2ce1f0 vldr s20, [r3] */
/* @0x2ce1f4 vldr s5, [r4, #124] */
/* @0x2ce1f8 vldr s22, [r2, #4] */
/* @0x2ce1fc vsub.f32 s8, s16, s17 */
/* @0x2ce200 vldr s6, [r4, #112] */
/* @0x2ce204 vldr s23, [r2] */
/* @0x2ce208 vldr s12, [r4, #116] */
/* @0x2ce20c vldr s0, [r4, #144] */
/* @0x2ce210 vldr s11, [r4, #184] */
/* @0x2ce214 vldr s1, [r4, #180] */
/* @0x2ce218 vldr s2, [r4, #176] */
/* @0x2ce21c vldr s3, [r4, #172] */
/* @0x2ce220 vldr s26, [r4, #84] */
/* @0x2ce224 vldr s27, [r4, #80] */
/* @0x2ce228 vldr s21, [r4, #156] */
/* @0x2ce22c vldr s19, [r4, #160] */
/* @0x2ce230 sub sp, sp, #12 */
/* @0x2ce234 vmla.f32 s8, s10, s14 */
/* @0x2ce238 vmov.f32 s14, s13 */
/* @0x2ce23c vmls.f32 s14, s15, s8 */
/* @0x2ce240 vmul.f32 s9, s4, s9 */
/* @0x2ce244 vcmpe.f32 s9, s14 */
/* @0x2ce248 vneg.f32 s15, s9 */
/* @0x2ce24c vmrs APSR_nzcv, fpscr */
/* @0x2ce250 vmovgt.f32 s9, s14 */
/* @0x2ce254 vcmpe.f32 s15, s9 */
/* @0x2ce258 vmrs APSR_nzcv, fpscr */
/* @0x2ce25c vmovgt.f32 s9, s15 */
/* @0x2ce260 vstr s9, [r4, #88] */
/* @0x2ce264 vsub.f32 s9, s9, s13 */
/* @0x2ce268 vmla.f32 s16, s24, s9 */
/* @0x2ce26c vmov.f32 s14, s18 */
/* @0x2ce270 vmla.f32 s14, s16, s7 */
/* @0x2ce274 vmov.f32 s15, s20 */
/* @0x2ce278 vmls.f32 s17, s25, s9 */
/* @0x2ce27c vmls.f32 s15, s16, s5 */
/* @0x2ce280 vsub.f32 s14, s14, s22 */
/* @0x2ce284 vmls.f32 s14, s17, s6 */
/* @0x2ce288 vsub.f32 s15, s15, s23 */
/* @0x2ce28c vmla.f32 s15, s17, s12 */
/* @0x2ce290 vmla.f32 s14, s10, s28 */
/* @0x2ce294 vldr s28, [r4, #92] */
/* @0x2ce298 vmla.f32 s15, s10, s0 */
/* @0x2ce29c vmul.f32 s11, s14, s11 */
/* @0x2ce2a0 vmul.f32 s14, s14, s1 */
/* @0x2ce2a4 vmla.f32 s11, s15, s2 */
/* @0x2ce2a8 vmla.f32 s14, s15, s3 */
/* @0x2ce2ac vsub.f32 s15, s26, s11 */
/* @0x2ce2b0 vmul.f32 s13, s15, s15 */
/* @0x2ce2b4 vstr s15, [r4, #84] */
/* @0x2ce2b8 vsub.f32 s14, s27, s14 */
/* @0x2ce2bc vmul.f32 s28, s4, s28 */
/* @0x2ce2c0 vstr s14, [r4, #80] */
/* @0x2ce2c4 vmla.f32 s13, s14, s14 */
/* @0x2ce2c8 vmul.f32 s11, s28, s28 */
/* @0x2ce2cc vcmpe.f32 s11, s13 */
/* @0x2ce2d0 vmrs APSR_nzcv, fpscr */
/* @0x2ce2d4 bmi 0x2ce32c <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x1a0> */
/* @0x2ce2d8 vsub.f32 s14, s14, s27 */
/* @0x2ce2dc vmul.f32 s12, s14, s12 */
/* @0x2ce2e0 vmul.f32 s13, s14, s5 */
/* @0x2ce2e4 vsub.f32 s15, s15, s26 */
/* @0x2ce2e8 vnmls.f32 s12, s15, s6 */
/* @0x2ce2ec vnmls.f32 s13, s15, s7 */
/* @0x2ce2f0 vmls.f32 s17, s25, s12 */
/* @0x2ce2f4 vmla.f32 s16, s24, s13 */
/* @0x2ce2f8 vstr s17, [r2, #8] */
/* @0x2ce2fc vmls.f32 s23, s21, s14 */
/* @0x2ce300 vmls.f32 s22, s21, s15 */
/* @0x2ce304 vstr s23, [r2] */
/* @0x2ce308 vmla.f32 s20, s19, s14 */
/* @0x2ce30c vstr s22, [r2, #4] */
/* @0x2ce310 vstr s16, [r3, #8] */
/* @0x2ce314 vmla.f32 s18, s19, s15 */
/* @0x2ce318 vstr s20, [r3] */
/* @0x2ce31c vstr s18, [r3, #4] */
/* @0x2ce320 add sp, sp, #12 */
/* @0x2ce324 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2ce328 pop {r4, r5, pc} */
/* @0x2ce32c vsqrt.f32 s11, s13 */
/* @0x2ce330 vcmp.f32 s11, s11 */
/* @0x2ce334 vmrs APSR_nzcv, fpscr */
/* @0x2ce338 bne 0x2ce38c <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x200> */
/* @0x2ce33c vldr s15, [pc, #124] */
/* @0x2ce340 vcmpe.f32 s11, s15 */
/* @0x2ce344 add r5, r5, r5, lsl #1 */
/* @0x2ce348 add r12, r12, r12, lsl #1 */
/* @0x2ce34c add r2, r0, r5, lsl #2 */
/* @0x2ce350 add r3, r0, r12, lsl #2 */
/* @0x2ce354 vmrs APSR_nzcv, fpscr */
/* @0x2ce358 vmovpl.f32 s13, #1.000000e+00 */
/* @0x2ce35c vldrpl s15, [r4, #84] */
/* @0x2ce360 vldrpl s14, [r4, #80] */
/* @0x2ce364 vldrmi s14, [r4, #80] */
/* @0x2ce368 vldrmi s15, [r4, #84] */
/* @0x2ce36c vdivpl.f32 s11, s13, s11 */
/* @0x2ce370 vmulpl.f32 s15, s11, s15 */
/* @0x2ce374 vmulpl.f32 s14, s11, s14 */
/* @0x2ce378 vmul.f32 s15, s28, s15 */
/* @0x2ce37c vmul.f32 s14, s28, s14 */
/* @0x2ce380 vstr s15, [r4, #84] */
/* @0x2ce384 vstr s14, [r4, #80] */
/* @0x2ce388 b 0x2ce2d8 <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x14c> */
/* @0x2ce38c vmov r0, s13 */
/* @0x2ce390 str r1, [sp, #0x4] */
/* @0x2ce394 bl 0xb6700 <sqrtf@plt> */
/* @0x2ce398 ldr r1, [sp, #0x4] */
/* @0x2ce39c vldr s5, [r4, #124] */
/* @0x2ce3a0 ldr r5, [r4, #0x68] */
/* @0x2ce3a4 vldr s7, [r4, #120] */
/* @0x2ce3a8 ldr r12, [r4, #0x6c] */
/* @0x2ce3ac vldr s12, [r4, #116] */
/* @0x2ce3b0 vldr s6, [r4, #112] */
/* @0x2ce3b4 vmov s11, r0 */
/* @0x2ce3b8 ldr r0, [r1, #0x1c] */
/* @0x2ce3bc b 0x2ce33c <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x1b0> */
/* @0x2ce3c0 strlo r0, [r0], #-0 */

/* ── FUNC 0x2ce3c4 · b2MotorJoint::InitVelocityConstraints(b2SolverData const&) · size=684 · insn=171 */
/* @0x2ce3c4 ldr r2, [r0, #0x30] */
/* @0x2ce3c8 ldr r3, [r0, #0x34] */
/* @0x2ce3cc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2ce3d0 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2ce3d4 mov r7, r1 */
/* @0x2ce3d8 vldr s16, [r2, #144] */
/* @0x2ce3dc add r1, r2, #44 */
/* @0x2ce3e0 mov r4, r0 */
/* @0x2ce3e4 ldr r6, [r2, #0x8] */
/* @0x2ce3e8 add lr, r0, #136 */
/* @0x2ce3ec ldr r12, [r3, #0x8] */
/* @0x2ce3f0 add r10, r0, #128 */
/* @0x2ce3f4 ldm r1, {r0, r1} */
/* @0x2ce3f8 add r9, r3, #44 */
/* @0x2ce3fc ldr r8, [r7, #0x18] */
/* @0x2ce400 vldr s23, [r2, #136] */
/* @0x2ce404 vldr s22, [r3, #136] */
/* @0x2ce408 ldr r5, [r7, #0x1c] */
/* @0x2ce40c str r6, [r4, #0x68] */
/* @0x2ce410 add r6, r6, r6, lsl #1 */
/* @0x2ce414 str r12, [r4, #0x6c] */
/* @0x2ce418 add r12, r12, r12, lsl #1 */
/* @0x2ce41c stm r10, {r0, r1} */
/* @0x2ce420 lsl r6, r6, #2 */
/* @0x2ce424 ldm r9, {r0, r1} */
/* @0x2ce428 vldr s17, [r3, #144] */
/* @0x2ce42c add r2, r8, r6 */
/* @0x2ce430 lsl r12, r12, #2 */
/* @0x2ce434 vldr s20, [r2, #8] */
/* @0x2ce438 add r3, r8, r12 */
/* @0x2ce43c stm lr, {r0, r1} */
/* @0x2ce440 vstr s23, [r4, #156] */
/* @0x2ce444 vmov r0, s20 */
/* @0x2ce448 vstr s22, [r4, #160] */
/* @0x2ce44c vstr s16, [r4, #164] */
/* @0x2ce450 vstr s17, [r4, #168] */
/* @0x2ce454 vldr s21, [r3, #8] */
/* @0x2ce458 vldr s27, [r3] */
/* @0x2ce45c vldr s26, [r3, #4] */
/* @0x2ce460 vldr s25, [r2] */
/* @0x2ce464 vldr s24, [r2, #4] */
/* @0x2ce468 add r6, r5, r6 */
/* @0x2ce46c add r5, r5, r12 */
/* @0x2ce470 bl 0xb6580 <sinf@plt> */
/* @0x2ce474 vmov s18, r0 */
/* @0x2ce478 vmov r0, s20 */
/* @0x2ce47c bl 0xb658c <cosf@plt> */
/* @0x2ce480 vsub.f32 s20, s21, s20 */
/* @0x2ce484 vmov s19, r0 */
/* @0x2ce488 vmov r0, s21 */
/* @0x2ce48c bl 0xb6580 <sinf@plt> */
/* @0x2ce490 vmov s28, r0 */
/* @0x2ce494 vmov r0, s21 */
/* @0x2ce498 bl 0xb658c <cosf@plt> */
/* @0x2ce49c vldr s13, [r4, #132] */
/* @0x2ce4a0 vneg.f32 s13, s13 */
/* @0x2ce4a4 vldr s14, [r4, #128] */
/* @0x2ce4a8 vldr s1, [r6] */
/* @0x2ce4ac vldr s2, [r6, #4] */
/* @0x2ce4b0 vldr s3, [r6, #8] */
/* @0x2ce4b4 vldr s4, [r5] */
/* @0x2ce4b8 vldr s5, [r5, #4] */
/* @0x2ce4bc vldr s6, [r5, #8] */
/* @0x2ce4c0 vmul.f32 s15, s13, s18 */
/* @0x2ce4c4 vmul.f32 s13, s13, s19 */
/* @0x2ce4c8 vneg.f32 s14, s14 */
/* @0x2ce4cc vmov s10, r0 */
/* @0x2ce4d0 vnmls.f32 s15, s14, s19 */
/* @0x2ce4d4 vmla.f32 s13, s14, s18 */
/* @0x2ce4d8 vstr s15, [r4, #112] */
/* @0x2ce4dc vstr s13, [r4, #116] */
/* @0x2ce4e0 vldr s14, [r4, #140] */
/* @0x2ce4e4 vneg.f32 s14, s14 */
/* @0x2ce4e8 vldr s12, [r4, #136] */
/* @0x2ce4ec ldrb r3, [r7, #0x14] */
/* @0x2ce4f0 vmul.f32 s11, s14, s28 */
/* @0x2ce4f4 vneg.f32 s12, s12 */
/* @0x2ce4f8 vmul.f32 s14, s14, s10 */
/* @0x2ce4fc vnmls.f32 s11, s12, s10 */
/* @0x2ce500 vmla.f32 s14, s12, s28 */
/* @0x2ce504 vstr s11, [r4, #120] */
/* @0x2ce508 vadd.f32 s9, s23, s22 */
/* @0x2ce50c vstr s14, [r4, #124] */
/* @0x2ce510 vmul.f32 s8, s16, s15 */
/* @0x2ce514 vmul.f32 s7, s17, s11 */
/* @0x2ce518 vmul.f32 s0, s16, s13 */
/* @0x2ce51c vmov.f32 s28, s9 */
/* @0x2ce520 vmla.f32 s28, s8, s15 */
/* @0x2ce524 vmul.f32 s10, s7, s14 */
/* @0x2ce528 vnmul.f32 s12, s16, s15 */
/* @0x2ce52c vmla.f32 s9, s0, s13 */
/* @0x2ce530 vnmls.f32 s10, s12, s13 */
/* @0x2ce534 vmul.f32 s12, s17, s14 */
/* @0x2ce538 vmov.f32 s8, s28 */
/* @0x2ce53c vmla.f32 s9, s12, s14 */
/* @0x2ce540 vmla.f32 s8, s7, s11 */
/* @0x2ce544 vmul.f32 s12, s10, s10 */
/* @0x2ce548 vnmls.f32 s12, s9, s8 */
/* @0x2ce54c vcmp.f32 s12, #0 */
/* @0x2ce550 vmrs APSR_nzcv, fpscr */
/* @0x2ce554 vmovne.f32 s7, #1.000000e+00 */
/* @0x2ce558 vdivne.f32 s12, s7, s12 */
/* @0x2ce55c vadd.f32 s7, s16, s17 */
/* @0x2ce560 vnmul.f32 s10, s12, s10 */
/* @0x2ce564 vmul.f32 s8, s8, s12 */
/* @0x2ce568 vstr s10, [r4, #176] */
/* @0x2ce56c vstr s10, [r4, #180] */
/* @0x2ce570 vmul.f32 s12, s9, s12 */
/* @0x2ce574 vldr s9, [r4, #68] */
/* @0x2ce578 vstr s8, [r4, #172] */
/* @0x2ce57c vldr s8, [r4, #76] */
/* @0x2ce580 vcmpe.f32 s7, #0 */
/* @0x2ce584 vstr s12, [r4, #184] */
/* @0x2ce588 vmrs APSR_nzcv, fpscr */
/* @0x2ce58c vmovgt.f32 s12, #1.000000e+00 */
/* @0x2ce590 vdivgt.f32 s7, s12, s7 */
/* @0x2ce594 vldr s12, [r4, #72] */
/* @0x2ce598 cmp r3, #0 */
/* @0x2ce59c vmul.f32 s10, s12, s18 */
/* @0x2ce5a0 vstr s7, [r4, #188] */
/* @0x2ce5a4 vmul.f32 s12, s12, s19 */
/* @0x2ce5a8 vadd.f32 s27, s11, s27 */
/* @0x2ce5ac vadd.f32 s26, s14, s26 */
/* @0x2ce5b0 vnmls.f32 s10, s9, s19 */
/* @0x2ce5b4 vmla.f32 s12, s9, s18 */
/* @0x2ce5b8 vsub.f32 s25, s27, s25 */
/* @0x2ce5bc vsub.f32 s24, s26, s24 */
/* @0x2ce5c0 vsub.f32 s25, s25, s15 */
/* @0x2ce5c4 vsub.f32 s24, s24, s13 */
/* @0x2ce5c8 vsub.f32 s10, s25, s10 */
/* @0x2ce5cc vsub.f32 s12, s24, s12 */
/* @0x2ce5d0 vstr s10, [r4, #144] */
/* @0x2ce5d4 vsub.f32 s20, s20, s8 */
/* @0x2ce5d8 vstr s12, [r4, #148] */
/* @0x2ce5dc vstr s20, [r4, #152] */
/* @0x2ce5e0 bne 0x2ce614 <_ZN12b2MotorJoint23InitVelocityConstraintsERK12b2SolverData+0x250> */
/* @0x2ce5e4 mov r3, #0 */
/* @0x2ce5e8 str r3, [r4, #0x50] */
/* @0x2ce5ec str r3, [r4, #0x54] */
/* @0x2ce5f0 str r3, [r4, #0x58] */
/* @0x2ce5f4 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2ce5f8 vstr s1, [r6] */
/* @0x2ce5fc vstr s2, [r6, #4] */
/* @0x2ce600 vstr s3, [r6, #8] */
/* @0x2ce604 vstr s4, [r5] */
/* @0x2ce608 vstr s5, [r5, #4] */
/* @0x2ce60c vstr s6, [r5, #8] */
/* @0x2ce610 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2ce614 vldr s9, [r7, #8] */
/* @0x2ce618 vldr s10, [r4, #80] */
/* @0x2ce61c vmul.f32 s10, s9, s10 */
/* @0x2ce620 vldr s12, [r4, #84] */
/* @0x2ce624 vldr s8, [r4, #88] */
/* @0x2ce628 vmul.f32 s12, s9, s12 */
/* @0x2ce62c vstr s10, [r4, #80] */
/* @0x2ce630 vmul.f32 s13, s13, s10 */
/* @0x2ce634 vstr s12, [r4, #84] */
/* @0x2ce638 vmul.f32 s14, s14, s10 */
/* @0x2ce63c vnmls.f32 s13, s15, s12 */
/* @0x2ce640 vnmls.f32 s14, s11, s12 */
/* @0x2ce644 vmul.f32 s15, s9, s8 */
/* @0x2ce648 vadd.f32 s13, s15, s13 */
/* @0x2ce64c vstr s15, [r4, #88] */
/* @0x2ce650 vadd.f32 s14, s15, s14 */
/* @0x2ce654 vmls.f32 s1, s23, s10 */
/* @0x2ce658 vmla.f32 s4, s22, s10 */
/* @0x2ce65c vmls.f32 s2, s23, s12 */
/* @0x2ce660 vmla.f32 s5, s22, s12 */
/* @0x2ce664 vmls.f32 s3, s16, s13 */
/* @0x2ce668 vmla.f32 s6, s17, s14 */
/* @0x2ce66c b 0x2ce5f4 <_ZN12b2MotorJoint23InitVelocityConstraintsERK12b2SolverData+0x230> */

/* ── FUNC 0x2ce670 · b2MotorJointDef::Initialize(b2Body*, b2Body*) · size=84 · insn=21 */
/* @0x2ce670 vldr s14, [r2, #16] */
/* @0x2ce674 vldr s15, [r1, #16] */
/* @0x2ce678 vsub.f32 s15, s14, s15 */
/* @0x2ce67c vldr s12, [r1, #20] */
/* @0x2ce680 vldr s8, [r2, #12] */
/* @0x2ce684 vldr s13, [r1, #12] */
/* @0x2ce688 vldr s11, [r1, #24] */
/* @0x2ce68c vldr s9, [r2, #72] */
/* @0x2ce690 vldr s10, [r1, #72] */
/* @0x2ce694 str r1, [r0, #0x8] */
/* @0x2ce698 str r2, [r0, #0xc] */
/* @0x2ce69c vmul.f32 s14, s15, s12 */
/* @0x2ce6a0 vsub.f32 s13, s8, s13 */
/* @0x2ce6a4 vmul.f32 s15, s15, s11 */
/* @0x2ce6a8 vmla.f32 s14, s13, s11 */
/* @0x2ce6ac vmls.f32 s15, s12, s13 */
/* @0x2ce6b0 vstr s14, [r0, #20] */
/* @0x2ce6b4 vsub.f32 s14, s9, s10 */
/* @0x2ce6b8 vstr s15, [r0, #24] */
/* @0x2ce6bc vstr s14, [r0, #28] */
/* @0x2ce6c0 bx lr */

/* ── FUNC 0x2ce6c4 · b2MotorJoint::b2MotorJoint(b2MotorJointDef const*) · size=108 · insn=27 */
/* @0x2ce6c4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2ce6c8 mov r4, r0 */
/* @0x2ce6cc mov r5, r1 */
/* @0x2ce6d0 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2ce6d4 ldr r2, [pc, #0x50] */
/* @0x2ce6d8 add r1, r5, #20 */
/* @0x2ce6dc mov r3, r4 */
/* @0x2ce6e0 ldr r7, [r5, #0x1c] */
/* @0x2ce6e4 ldr r2, [pc, r2] */
/* @0x2ce6e8 ldm r1, {r0, r1} */
/* @0x2ce6ec ldr r6, [r5, #0x20] */
/* @0x2ce6f0 add r2, r2, #8 */
/* @0x2ce6f4 ldr r12, [r5, #0x24] */
/* @0x2ce6f8 str r2, [r3], #68 */
/* @0x2ce6fc ldr r2, [r5, #0x28] */
/* @0x2ce700 stm r3, {r0, r1} */
/* @0x2ce704 mov r3, #0 */
/* @0x2ce708 str r7, [r4, #0x4c] */
/* @0x2ce70c mov r0, r4 */
/* @0x2ce710 str r6, [r4, #0x5c] */
/* @0x2ce714 str r12, [r4, #0x60] */
/* @0x2ce718 str r2, [r4, #0x64] */
/* @0x2ce71c str r3, [r4, #0x50] */
/* @0x2ce720 str r3, [r4, #0x54] */
/* @0x2ce724 str r3, [r4, #0x58] */
/* @0x2ce728 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2ce72c andseq r3, r2, r12, ror r4 */
