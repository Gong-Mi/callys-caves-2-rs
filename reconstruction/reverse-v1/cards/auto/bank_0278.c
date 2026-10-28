/* libyoyo.so 覆盖卡组 0278
 * 函数 0x2d071c..0x2d2144，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2d071c · b2PulleyJoint::~b2PulleyJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d0734 · b2PulleyJoint::Dump() · size=376 · insn=94 */
/* @0x2d0734 push {r4, r5, r6, lr} */
/* @0x2d0738 mov r4, r0 */
/* @0x2d073c ldr r2, [r4, #0x30] */
/* @0x2d0740 sub sp, sp, #8 */
/* @0x2d0744 ldr r3, [r4, #0x34] */
/* @0x2d0748 ldr r0, [pc, #0x12c] */
/* @0x2d074c ldr r6, [r2, #0x8] */
/* @0x2d0750 add r0, pc, r0 */
/* @0x2d0754 ldr r5, [r3, #0x8] */
/* @0x2d0758 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d075c ldr r0, [pc, #0x11c] */
/* @0x2d0760 mov r1, r6 */
/* @0x2d0764 add r0, pc, r0 */
/* @0x2d0768 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d076c ldr r0, [pc, #0x110] */
/* @0x2d0770 mov r1, r5 */
/* @0x2d0774 add r0, pc, r0 */
/* @0x2d0778 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d077c ldr r0, [pc, #0x104] */
/* @0x2d0780 ldrb r1, [r4, #0x3d] */
/* @0x2d0784 add r0, pc, r0 */
/* @0x2d0788 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d078c vldr s13, [r4, #68] */
/* @0x2d0790 vldr s14, [r4, #72] */
/* @0x2d0794 vcvt.f64.f32 d5, s13 */
/* @0x2d0798 ldr r0, [pc, #0xec] */
/* @0x2d079c add r0, pc, r0 */
/* @0x2d07a0 vcvt.f64.f32 d7, s14 */
/* @0x2d07a4 vmov r2, r3, d5 */
/* @0x2d07a8 vstr d7, [sp] */
/* @0x2d07ac bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d07b0 vldr s13, [r4, #76] */
/* @0x2d07b4 vldr s14, [r4, #80] */
/* @0x2d07b8 vcvt.f64.f32 d5, s13 */
/* @0x2d07bc ldr r0, [pc, #0xcc] */
/* @0x2d07c0 add r0, pc, r0 */
/* @0x2d07c4 vcvt.f64.f32 d7, s14 */
/* @0x2d07c8 vmov r2, r3, d5 */
/* @0x2d07cc vstr d7, [sp] */
/* @0x2d07d0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d07d4 vldr s13, [r4, #92] */
/* @0x2d07d8 vldr s14, [r4, #96] */
/* @0x2d07dc vcvt.f64.f32 d5, s13 */
/* @0x2d07e0 ldr r0, [pc, #0xac] */
/* @0x2d07e4 add r0, pc, r0 */
/* @0x2d07e8 vcvt.f64.f32 d7, s14 */
/* @0x2d07ec vmov r2, r3, d5 */
/* @0x2d07f0 vstr d7, [sp] */
/* @0x2d07f4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d07f8 vldr s13, [r4, #100] */
/* @0x2d07fc vldr s14, [r4, #104] */
/* @0x2d0800 vcvt.f64.f32 d5, s13 */
/* @0x2d0804 ldr r0, [pc, #0x8c] */
/* @0x2d0808 add r0, pc, r0 */
/* @0x2d080c vcvt.f64.f32 d7, s14 */
/* @0x2d0810 vmov r2, r3, d5 */
/* @0x2d0814 vstr d7, [sp] */
/* @0x2d0818 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d081c vldr s15, [r4, #84] */
/* @0x2d0820 vcvt.f64.f32 d6, s15 */
/* @0x2d0824 ldr r0, [pc, #0x70] */
/* @0x2d0828 add r0, pc, r0 */
/* @0x2d082c vmov r2, r3, d6 */
/* @0x2d0830 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d0834 vldr s15, [r4, #88] */
/* @0x2d0838 vcvt.f64.f32 d5, s15 */
/* @0x2d083c ldr r0, [pc, #0x5c] */
/* @0x2d0840 add r0, pc, r0 */
/* @0x2d0844 vmov r2, r3, d5 */
/* @0x2d0848 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d084c vldr s15, [r4, #112] */
/* @0x2d0850 vcvt.f64.f32 d6, s15 */
/* @0x2d0854 ldr r0, [pc, #0x48] */
/* @0x2d0858 add r0, pc, r0 */
/* @0x2d085c vmov r2, r3, d6 */
/* @0x2d0860 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d0864 ldr r0, [pc, #0x3c] */
/* @0x2d0868 ldr r1, [r4, #0x38] */
/* @0x2d086c add r0, pc, r0 */
/* @0x2d0870 add sp, sp, #8 */
/* @0x2d0874 pop {r4, r5, r6, lr} */
/* @0x2d0878 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d087c andeq r11, r8, r0, asr #21 */
/* @0x2d0880 andeq r11, r8, r8, asr #14 */
/* @0x2d0884 andeq r11, r8, r4, asr r7 */
/* @0x2d0888 andeq r11, r8, r0, ror #14 */
/* @0x2d088c andeq r11, r8, r12, lsl #21 */
/* @0x2d0890 muleq r8, r4, r10 */
/* @0x2d0894 andeq r11, r8, r4, lsr #14 */
/* @0x2d0898 andeq r11, r8, r12, lsr #14 */
/* @0x2d089c andeq r11, r8, r8, asr r10 */
/* @0x2d08a0 andeq r11, r8, r12, asr r10 */
/* @0x2d08a4 andeq r11, r8, r0, ror #20 */
/* @0x2d08a8 andeq r11, r8, r12, asr #14 */

/* ── FUNC 0x2d08ac · b2PulleyJoint::~b2PulleyJoint() · size=40 · insn=10 */
/* @0x2d08ac ldr r3, [pc, #0x1c] */
/* @0x2d08b0 push {r4, lr} */
/* @0x2d08b4 ldr r3, [pc, r3] */
/* @0x2d08b8 mov r4, r0 */
/* @0x2d08bc add r3, r3, #8 */
/* @0x2d08c0 str r3, [r0] */
/* @0x2d08c4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d08c8 mov r0, r4 */
/* @0x2d08cc pop {r4, pc} */
/* @0x2d08d0 andseq r1, r2, r0, lsr #5 */

/* ── FUNC 0x2d08d4 · b2PulleyJoint::SolvePositionConstraints(b2SolverData const&) · size=676 · insn=169 */
/* @0x2d08d4 ldr r2, [r0, #0x78] */
/* @0x2d08d8 push {r3, r4, r5, lr} */
/* @0x2d08dc vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d08e0 mov r5, r1 */
/* @0x2d08e4 ldr r3, [r0, #0x7c] */
/* @0x2d08e8 add r2, r2, r2, lsl #1 */
/* @0x2d08ec ldr r1, [r1, #0x18] */
/* @0x2d08f0 mov r4, r0 */
/* @0x2d08f4 add r3, r3, r3, lsl #1 */
/* @0x2d08f8 add r2, r1, r2, lsl #2 */
/* @0x2d08fc vldr s22, [r2, #8] */
/* @0x2d0900 vmov r0, s22 */
/* @0x2d0904 add r3, r1, r3, lsl #2 */
/* @0x2d0908 vldr s26, [r2] */
/* @0x2d090c vldr s21, [r3, #8] */
/* @0x2d0910 vldr s25, [r2, #4] */
/* @0x2d0914 vldr s24, [r3] */
/* @0x2d0918 vldr s23, [r3, #4] */
/* @0x2d091c bl 0xb6580 <sinf@plt> */
/* @0x2d0920 vmov s20, r0 */
/* @0x2d0924 vmov r0, s22 */
/* @0x2d0928 bl 0xb658c <cosf@plt> */
/* @0x2d092c vmov s16, r0 */
/* @0x2d0930 vmov r0, s21 */
/* @0x2d0934 bl 0xb6580 <sinf@plt> */
/* @0x2d0938 vmov s31, r0 */
/* @0x2d093c vmov r0, s21 */
/* @0x2d0940 bl 0xb658c <cosf@plt> */
/* @0x2d0944 vldr s15, [r4, #164] */
/* @0x2d0948 vldr s17, [r4, #96] */
/* @0x2d094c vsub.f32 s17, s17, s15 */
/* @0x2d0950 vldr s6, [r4, #92] */
/* @0x2d0954 vldr s15, [r4, #160] */
/* @0x2d0958 vldr s7, [r4, #72] */
/* @0x2d095c vldr s8, [r4, #68] */
/* @0x2d0960 vldr s19, [r4, #104] */
/* @0x2d0964 vldr s9, [r4, #172] */
/* @0x2d0968 vldr s10, [r4, #100] */
/* @0x2d096c vldr s14, [r4, #168] */
/* @0x2d0970 vldr s11, [r4, #76] */
/* @0x2d0974 vldr s12, [r4, #80] */
/* @0x2d0978 vmul.f32 s18, s17, s16 */
/* @0x2d097c vsub.f32 s15, s6, s15 */
/* @0x2d0980 vmov s13, r0 */
/* @0x2d0984 vmla.f32 s18, s15, s20 */
/* @0x2d0988 vmul.f32 s17, s17, s20 */
/* @0x2d098c vnmls.f32 s17, s15, s16 */
/* @0x2d0990 vadd.f32 s29, s18, s25 */
/* @0x2d0994 vsub.f32 s29, s29, s7 */
/* @0x2d0998 vadd.f32 s30, s17, s26 */
/* @0x2d099c vmul.f32 s15, s29, s29 */
/* @0x2d09a0 vsub.f32 s30, s30, s8 */
/* @0x2d09a4 vmla.f32 s15, s30, s30 */
/* @0x2d09a8 vsub.f32 s19, s19, s9 */
/* @0x2d09ac vmul.f32 s16, s19, s31 */
/* @0x2d09b0 vmul.f32 s19, s19, s13 */
/* @0x2d09b4 vsub.f32 s14, s10, s14 */
/* @0x2d09b8 vsqrt.f32 s20, s15 */
/* @0x2d09bc vnmls.f32 s16, s14, s13 */
/* @0x2d09c0 vmla.f32 s19, s14, s31 */
/* @0x2d09c4 vadd.f32 s28, s16, s24 */
/* @0x2d09c8 vadd.f32 s27, s19, s23 */
/* @0x2d09cc vcmp.f32 s20, s20 */
/* @0x2d09d0 vsub.f32 s28, s28, s11 */
/* @0x2d09d4 vmrs APSR_nzcv, fpscr */
/* @0x2d09d8 vsub.f32 s27, s27, s12 */
/* @0x2d09dc bne 0x2d0b4c <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x278> */
/* @0x2d09e0 vmul.f32 s15, s27, s27 */
/* @0x2d09e4 vmla.f32 s15, s28, s28 */
/* @0x2d09e8 vsqrt.f32 s13, s15 */
/* @0x2d09ec vcmp.f32 s13, s13 */
/* @0x2d09f0 vmrs APSR_nzcv, fpscr */
/* @0x2d09f4 bne 0x2d0b5c <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x288> */
/* @0x2d09f8 vldr s15, [pc, #364] */
/* @0x2d09fc vcmpe.f32 s20, s15 */
/* @0x2d0a00 vldr s6, [r4, #184] */
/* @0x2d0a04 vldr s7, [r4, #188] */
/* @0x2d0a08 vldr s8, [r4, #176] */
/* @0x2d0a0c vldr s9, [r4, #180] */
/* @0x2d0a10 ldr r2, [r4, #0x78] */
/* @0x2d0a14 vmrs APSR_nzcv, fpscr */
/* @0x2d0a18 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2d0a1c vldrle s29, [pc, #332] */
/* @0x2d0a20 ldr r3, [r4, #0x7c] */
/* @0x2d0a24 ldr r1, [r5, #0x18] */
/* @0x2d0a28 add r2, r2, r2, lsl #1 */
/* @0x2d0a2c add r3, r3, r3, lsl #1 */
/* @0x2d0a30 add r2, r1, r2, lsl #2 */
/* @0x2d0a34 add r3, r1, r3, lsl #2 */
/* @0x2d0a38 vdivgt.f32 s15, s15, s20 */
/* @0x2d0a3c vmulgt.f32 s30, s15, s30 */
/* @0x2d0a40 vmulgt.f32 s29, s15, s29 */
/* @0x2d0a44 vldr s15, [pc, #288] */
/* @0x2d0a48 vcmpe.f32 s13, s15 */
/* @0x2d0a4c vmovle.f32 s30, s29 */
/* @0x2d0a50 vmrs APSR_nzcv, fpscr */
/* @0x2d0a54 vldrle s27, [pc, #276] */
/* @0x2d0a58 vmovgt.f32 s12, #1.000000e+00 */
/* @0x2d0a5c vdivgt.f32 s12, s12, s13 */
/* @0x2d0a60 vmulgt.f32 s28, s12, s28 */
/* @0x2d0a64 vmovle.f32 s28, s27 */
/* @0x2d0a68 vmul.f32 s10, s30, s18 */
/* @0x2d0a6c vmulgt.f32 s27, s12, s27 */
/* @0x2d0a70 vldr s12, [r4, #112] */
/* @0x2d0a74 vmul.f32 s11, s28, s19 */
/* @0x2d0a78 vnmls.f32 s10, s29, s17 */
/* @0x2d0a7c vnmls.f32 s11, s27, s16 */
/* @0x2d0a80 vmul.f32 s15, s6, s10 */
/* @0x2d0a84 vmul.f32 s14, s7, s11 */
/* @0x2d0a88 vmov.f32 s5, s8 */
/* @0x2d0a8c vmla.f32 s5, s15, s10 */
/* @0x2d0a90 vmov.f32 s10, s9 */
/* @0x2d0a94 vmla.f32 s10, s14, s11 */
/* @0x2d0a98 vmul.f32 s11, s12, s12 */
/* @0x2d0a9c vmov.f32 s15, s5 */
/* @0x2d0aa0 vmla.f32 s15, s11, s10 */
/* @0x2d0aa4 vcmpe.f32 s15, #0 */
/* @0x2d0aa8 vmov.f32 s14, s10 */
/* @0x2d0aac vmrs APSR_nzcv, fpscr */
/* @0x2d0ab0 vmovgt.f32 s14, #1.000000e+00 */
/* @0x2d0ab4 vdivgt.f32 s15, s14, s15 */
/* @0x2d0ab8 vldr s14, [r4, #108] */
/* @0x2d0abc vsub.f32 s14, s14, s20 */
/* @0x2d0ac0 vmls.f32 s14, s12, s13 */
/* @0x2d0ac4 vnmul.f32 s15, s15, s14 */
/* @0x2d0ac8 vnmul.f32 s12, s12, s15 */
/* @0x2d0acc vneg.f32 s15, s15 */
/* @0x2d0ad0 vmul.f32 s28, s12, s28 */
/* @0x2d0ad4 vmul.f32 s30, s15, s30 */
/* @0x2d0ad8 vmul.f32 s29, s15, s29 */
/* @0x2d0adc vmul.f32 s27, s12, s27 */
/* @0x2d0ae0 vmul.f32 s19, s19, s28 */
/* @0x2d0ae4 vmul.f32 s18, s18, s30 */
/* @0x2d0ae8 vnmls.f32 s19, s16, s27 */
/* @0x2d0aec vnmls.f32 s18, s17, s29 */
/* @0x2d0af0 vmla.f32 s26, s8, s30 */
/* @0x2d0af4 vmla.f32 s22, s6, s18 */
/* @0x2d0af8 vstr s26, [r2] */
/* @0x2d0afc vmla.f32 s25, s8, s29 */
/* @0x2d0b00 vstr s22, [r2, #8] */
/* @0x2d0b04 vmla.f32 s21, s7, s19 */
/* @0x2d0b08 vstr s25, [r2, #4] */
/* @0x2d0b0c vmla.f32 s24, s9, s28 */
/* @0x2d0b10 vstr s21, [r3, #8] */
/* @0x2d0b14 vmla.f32 s23, s9, s27 */
/* @0x2d0b18 vstr s24, [r3] */
/* @0x2d0b1c vcmpe.f32 s14, #0 */
/* @0x2d0b20 vstr s23, [r3, #4] */
/* @0x2d0b24 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d0b28 vmrs APSR_nzcv, fpscr */
/* @0x2d0b2c vnegle.f32 s13, s14 */
/* @0x2d0b30 vmovgt.f32 s13, s14 */
/* @0x2d0b34 vldr s14, [pc, #56] */
/* @0x2d0b38 vcmpe.f32 s13, s14 */
/* @0x2d0b3c vmrs APSR_nzcv, fpscr */
/* @0x2d0b40 movpl r0, #0 */
/* @0x2d0b44 movmi r0, #1 */
/* @0x2d0b48 pop {r3, r4, r5, pc} */
/* @0x2d0b4c vmov r0, s15 */
/* @0x2d0b50 bl 0xb6700 <sqrtf@plt> */
/* @0x2d0b54 vmov s20, r0 */
/* @0x2d0b58 b 0x2d09e0 <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x10c> */
/* @0x2d0b5c vmov r0, s15 */
/* @0x2d0b60 bl 0xb6700 <sqrtf@plt> */
/* @0x2d0b64 vmov s13, r0 */
/* @0x2d0b68 b 0x2d09f8 <_ZN13b2PulleyJoint24SolvePositionConstraintsERK12b2SolverData+0x124> */
/* @0x2d0b6c stcllo p12, c12, [r12, #-816] */
/* @0x2d0b70 andeq r0, r0, r0 */
/* @0x2d0b74 bllo 0xfebc67a4 <b2_toiTime+0xfffffffffe46d300> */

/* ── FUNC 0x2d0b78 · b2PulleyJoint::InitVelocityConstraints(b2SolverData const&) · size=912 · insn=228 */
/* @0x2d0b78 ldr r2, [r0, #0x30] */
/* @0x2d0b7c vldr s15, [r2, #136] */
/* @0x2d0b80 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d0b84 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d0b88 mov r5, r1 */
/* @0x2d0b8c ldr r3, [r0, #0x34] */
/* @0x2d0b90 add r1, r2, #44 */
/* @0x2d0b94 ldr lr, [r2, #0x8] */
/* @0x2d0b98 mov r4, r0 */
/* @0x2d0b9c ldr r7, [r5, #0x18] */
/* @0x2d0ba0 add r10, r0, #160 */
/* @0x2d0ba4 ldr r12, [r3, #0x8] */
/* @0x2d0ba8 add r6, r0, #168 */
/* @0x2d0bac ldr r11, [r2, #0x90] */
/* @0x2d0bb0 add r9, r3, #44 */
/* @0x2d0bb4 ldm r1, {r0, r1} */
/* @0x2d0bb8 str lr, [r4, #0x78] */
/* @0x2d0bbc add lr, lr, lr, lsl #1 */
/* @0x2d0bc0 ldr r8, [r5, #0x1c] */
/* @0x2d0bc4 lsl lr, lr, #2 */
/* @0x2d0bc8 str r12, [r4, #0x7c] */
/* @0x2d0bcc add r12, r12, r12, lsl #1 */
/* @0x2d0bd0 add r2, r7, lr */
/* @0x2d0bd4 stm r10, {r0, r1} */
/* @0x2d0bd8 add lr, r8, lr */
/* @0x2d0bdc lsl r12, r12, #2 */
/* @0x2d0be0 ldm r9, {r0, r1} */
/* @0x2d0be4 ldr r10, [r3, #0x88] */
/* @0x2d0be8 vldr s27, [r2] */
/* @0x2d0bec ldr r9, [r3, #0x90] */
/* @0x2d0bf0 add r3, r7, r12 */
/* @0x2d0bf4 ldr r7, [r2, #0x8] */
/* @0x2d0bf8 add r12, r8, r12 */
/* @0x2d0bfc stm r6, {r0, r1} */
/* @0x2d0c00 vstr s15, [r4, #176] */
/* @0x2d0c04 str r11, [r4, #0xb8] */
/* @0x2d0c08 vldr s25, [r3] */
/* @0x2d0c0c str r10, [r4, #0xb4] */
/* @0x2d0c10 mov r0, r7 */
/* @0x2d0c14 str r9, [r4, #0xbc] */
/* @0x2d0c18 vldr s28, [r2, #4] */
/* @0x2d0c1c ldr r6, [r3, #0x8] */
/* @0x2d0c20 vldr s24, [r3, #4] */
/* @0x2d0c24 vldr s22, [lr] */
/* @0x2d0c28 vldr s21, [lr, #4] */
/* @0x2d0c2c vldr s20, [lr, #8] */
/* @0x2d0c30 vldr s19, [r12] */
/* @0x2d0c34 vldr s18, [r12, #4] */
/* @0x2d0c38 vldr s17, [r12, #8] */
/* @0x2d0c3c bl 0xb6580 <sinf@plt> */
/* @0x2d0c40 vmov s26, r0 */
/* @0x2d0c44 mov r0, r7 */
/* @0x2d0c48 bl 0xb658c <cosf@plt> */
/* @0x2d0c4c vmov s16, r0 */
/* @0x2d0c50 mov r0, r6 */
/* @0x2d0c54 bl 0xb6580 <sinf@plt> */
/* @0x2d0c58 vmov s23, r0 */
/* @0x2d0c5c mov r0, r6 */
/* @0x2d0c60 bl 0xb658c <cosf@plt> */
/* @0x2d0c64 vldr s15, [r4, #164] */
/* @0x2d0c68 vldr s13, [r4, #96] */
/* @0x2d0c6c vsub.f32 s13, s13, s15 */
/* @0x2d0c70 vldr s14, [r4, #92] */
/* @0x2d0c74 vldr s15, [r4, #160] */
/* @0x2d0c78 vmul.f32 s12, s13, s16 */
/* @0x2d0c7c vsub.f32 s15, s14, s15 */
/* @0x2d0c80 vmov s11, r0 */
/* @0x2d0c84 vmul.f32 s13, s13, s26 */
/* @0x2d0c88 vmla.f32 s12, s15, s26 */
/* @0x2d0c8c vnmls.f32 s13, s15, s16 */
/* @0x2d0c90 vadd.f32 s28, s28, s12 */
/* @0x2d0c94 vstr s13, [r4, #144] */
/* @0x2d0c98 vldr s5, [r4, #72] */
/* @0x2d0c9c vstr s12, [r4, #148] */
/* @0x2d0ca0 vldr s6, [r4, #68] */
/* @0x2d0ca4 vldr s14, [r4, #104] */
/* @0x2d0ca8 vldr s15, [r4, #172] */
/* @0x2d0cac vldr s7, [r4, #100] */
/* @0x2d0cb0 vldr s8, [r4, #168] */
/* @0x2d0cb4 vldr s9, [r4, #76] */
/* @0x2d0cb8 vldr s10, [r4, #80] */
/* @0x2d0cbc vsub.f32 s12, s28, s5 */
/* @0x2d0cc0 vadd.f32 s13, s27, s13 */
/* @0x2d0cc4 vstr s12, [r4, #132] */
/* @0x2d0cc8 vmul.f32 s12, s12, s12 */
/* @0x2d0ccc vsub.f32 s13, s13, s6 */
/* @0x2d0cd0 vsub.f32 s15, s14, s15 */
/* @0x2d0cd4 vstr s13, [r4, #128] */
/* @0x2d0cd8 vmla.f32 s12, s13, s13 */
/* @0x2d0cdc vmul.f32 s14, s15, s23 */
/* @0x2d0ce0 vmul.f32 s15, s15, s11 */
/* @0x2d0ce4 vsub.f32 s13, s7, s8 */
/* @0x2d0ce8 vsqrt.f32 s16, s12 */
/* @0x2d0cec vnmls.f32 s14, s13, s11 */
/* @0x2d0cf0 vmla.f32 s15, s13, s23 */
/* @0x2d0cf4 vstr s14, [r4, #152] */
/* @0x2d0cf8 vstr s15, [r4, #156] */
/* @0x2d0cfc vadd.f32 s14, s14, s25 */
/* @0x2d0d00 vadd.f32 s15, s15, s24 */
/* @0x2d0d04 vsub.f32 s14, s14, s9 */
/* @0x2d0d08 vsub.f32 s15, s15, s10 */
/* @0x2d0d0c vstr s14, [r4, #136] */
/* @0x2d0d10 vcmp.f32 s16, s16 */
/* @0x2d0d14 vstr s15, [r4, #140] */
/* @0x2d0d18 vmrs APSR_nzcv, fpscr */
/* @0x2d0d1c bne 0x2d0ef0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x378> */
/* @0x2d0d20 vldr s14, [r4, #140] */
/* @0x2d0d24 vmul.f32 s14, s14, s14 */
/* @0x2d0d28 vldr s15, [r4, #136] */
/* @0x2d0d2c vmla.f32 s14, s15, s15 */
/* @0x2d0d30 vsqrt.f32 s15, s14 */
/* @0x2d0d34 vcmp.f32 s15, s15 */
/* @0x2d0d38 vmrs APSR_nzcv, fpscr */
/* @0x2d0d3c bne 0x2d0ee0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x368> */
/* @0x2d0d40 vldr s14, [pc, #440] */
/* @0x2d0d44 vcmpe.f32 s16, s14 */
/* @0x2d0d48 vmrs APSR_nzcv, fpscr */
/* @0x2d0d4c ble 0x2d0ed0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x358> */
/* @0x2d0d50 vmov.f32 s12, #1.000000e+00 */
/* @0x2d0d54 vldr s14, [r4, #128] */
/* @0x2d0d58 vldr s13, [r4, #132] */
/* @0x2d0d5c vdiv.f32 s16, s12, s16 */
/* @0x2d0d60 vmul.f32 s14, s14, s16 */
/* @0x2d0d64 vmul.f32 s16, s13, s16 */
/* @0x2d0d68 vstr s14, [r4, #128] */
/* @0x2d0d6c vstr s16, [r4, #132] */
/* @0x2d0d70 vldr s14, [pc, #392] */
/* @0x2d0d74 vcmpe.f32 s15, s14 */
/* @0x2d0d78 vmrs APSR_nzcv, fpscr */
/* @0x2d0d7c ble 0x2d0eb8 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x340> */
/* @0x2d0d80 vmov.f32 s14, #1.000000e+00 */
/* @0x2d0d84 vldr s12, [r4, #136] */
/* @0x2d0d88 vldr s3, [r4, #140] */
/* @0x2d0d8c vdiv.f32 s15, s14, s15 */
/* @0x2d0d90 vmul.f32 s12, s15, s12 */
/* @0x2d0d94 vmul.f32 s3, s15, s3 */
/* @0x2d0d98 vstr s12, [r4, #136] */
/* @0x2d0d9c vstr s3, [r4, #140] */
/* @0x2d0da0 vldr s4, [r4, #148] */
/* @0x2d0da4 vldr s1, [r4, #128] */
/* @0x2d0da8 vmul.f32 s15, s4, s1 */
/* @0x2d0dac vldr s2, [r4, #156] */
/* @0x2d0db0 vldr s7, [r4, #144] */
/* @0x2d0db4 vldr s5, [r4, #132] */
/* @0x2d0db8 vldr s6, [r4, #152] */
/* @0x2d0dbc vldr s9, [r4, #184] */
/* @0x2d0dc0 vldr s8, [r4, #188] */
/* @0x2d0dc4 vldr s11, [r4, #176] */
/* @0x2d0dc8 vldr s10, [r4, #180] */
/* @0x2d0dcc vldr s13, [r4, #112] */
/* @0x2d0dd0 ldrb r3, [r5, #0x14] */
/* @0x2d0dd4 vmul.f32 s14, s2, s12 */
/* @0x2d0dd8 vnmls.f32 s15, s7, s5 */
/* @0x2d0ddc vnmls.f32 s14, s6, s3 */
/* @0x2d0de0 vmul.f32 s16, s9, s15 */
/* @0x2d0de4 vmul.f32 s0, s8, s14 */
/* @0x2d0de8 vmov.f32 s23, s11 */
/* @0x2d0dec vmla.f32 s23, s16, s15 */
/* @0x2d0df0 vmov.f32 s16, s10 */
/* @0x2d0df4 vmla.f32 s16, s0, s14 */
/* @0x2d0df8 vmul.f32 s0, s13, s13 */
/* @0x2d0dfc vmov.f32 s15, s23 */
/* @0x2d0e00 vmla.f32 s15, s0, s16 */
/* @0x2d0e04 vcmpe.f32 s15, #0 */
/* @0x2d0e08 vmov.f32 s14, s16 */
/* @0x2d0e0c vmrs APSR_nzcv, fpscr */
/* @0x2d0e10 vmovgt.f32 s14, #1.000000e+00 */
/* @0x2d0e14 vdivgt.f32 s15, s14, s15 */
/* @0x2d0e18 cmp r3, #0 */
/* @0x2d0e1c moveq r3, #0 */
/* @0x2d0e20 streq r3, [r4, #0x74] */
/* @0x2d0e24 vstr s15, [r4, #192] */
/* @0x2d0e28 beq 0x2d0e7c <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x304> */
/* @0x2d0e2c vldr s14, [r4, #116] */
/* @0x2d0e30 vldr s15, [r5, #8] */
/* @0x2d0e34 vmul.f32 s15, s14, s15 */
/* @0x2d0e38 vnmul.f32 s13, s13, s15 */
/* @0x2d0e3c vstr s15, [r4, #116] */
/* @0x2d0e40 vneg.f32 s15, s15 */
/* @0x2d0e44 vmul.f32 s12, s13, s12 */
/* @0x2d0e48 vmul.f32 s1, s15, s1 */
/* @0x2d0e4c vmul.f32 s3, s13, s3 */
/* @0x2d0e50 vmul.f32 s5, s15, s5 */
/* @0x2d0e54 vmul.f32 s2, s2, s12 */
/* @0x2d0e58 vmul.f32 s4, s4, s1 */
/* @0x2d0e5c vnmls.f32 s2, s6, s3 */
/* @0x2d0e60 vnmls.f32 s4, s7, s5 */
/* @0x2d0e64 vmla.f32 s17, s8, s2 */
/* @0x2d0e68 vmla.f32 s19, s10, s12 */
/* @0x2d0e6c vmla.f32 s18, s10, s3 */
/* @0x2d0e70 vmla.f32 s20, s9, s4 */
/* @0x2d0e74 vmla.f32 s22, s11, s1 */
/* @0x2d0e78 vmla.f32 s21, s11, s5 */
/* @0x2d0e7c ldr r2, [r4, #0x78] */
/* @0x2d0e80 ldr r3, [r4, #0x7c] */
/* @0x2d0e84 ldr r1, [r5, #0x1c] */
/* @0x2d0e88 add r2, r2, r2, lsl #1 */
/* @0x2d0e8c add r3, r3, r3, lsl #1 */
/* @0x2d0e90 add r2, r1, r2, lsl #2 */
/* @0x2d0e94 vstr s22, [r2] */
/* @0x2d0e98 vstr s21, [r2, #4] */
/* @0x2d0e9c vstr s20, [r2, #8] */
/* @0x2d0ea0 add r3, r1, r3, lsl #2 */
/* @0x2d0ea4 vstr s19, [r3] */
/* @0x2d0ea8 vstr s18, [r3, #4] */
/* @0x2d0eac vstr s17, [r3, #8] */
/* @0x2d0eb0 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d0eb4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d0eb8 vldr s15, [pc, #68] */
/* @0x2d0ebc vmov.f32 s12, s15 */
/* @0x2d0ec0 vstr s15, [r4, #136] */
/* @0x2d0ec4 vstr s15, [r4, #140] */
/* @0x2d0ec8 vmov.f32 s3, s15 */
/* @0x2d0ecc b 0x2d0da0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x228> */
/* @0x2d0ed0 mov r3, #0 */
/* @0x2d0ed4 str r3, [r4, #0x80] */
/* @0x2d0ed8 str r3, [r4, #0x84] */
/* @0x2d0edc b 0x2d0d70 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8> */
/* @0x2d0ee0 vmov r0, s14 */
/* @0x2d0ee4 bl 0xb6700 <sqrtf@plt> */
/* @0x2d0ee8 vmov s15, r0 */
/* @0x2d0eec b 0x2d0d40 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x1c8> */
/* @0x2d0ef0 vmov r0, s12 */
/* @0x2d0ef4 bl 0xb6700 <sqrtf@plt> */
/* @0x2d0ef8 vmov s16, r0 */
/* @0x2d0efc b 0x2d0d20 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x1a8> */
/* @0x2d0f00 stcllo p12, c12, [r12, #-816] */
/* @0x2d0f04 andeq r0, r0, r0 */

/* ── FUNC 0x2d0f08 · b2PulleyJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&, b2Vec2 const&, b2Vec2 const&, float) · size=380 · insn=95 */
/* @0x2d0f08 push {r3, r4, r5, r6, r7, lr} */
/* @0x2d0f0c vpush {d8} */
/* @0x2d0f10 mov r4, r0 */
/* @0x2d0f14 vldr s12, [r2, #20] */
/* @0x2d0f18 mov r12, r1 */
/* @0x2d0f1c ldr r5, [sp, #0x20] */
/* @0x2d0f20 ldm r3, {r0, r1} */
/* @0x2d0f24 add lr, r4, #20 */
/* @0x2d0f28 str r12, [r4, #0x8] */
/* @0x2d0f2c add r7, r4, #28 */
/* @0x2d0f30 str r2, [r4, #0xc] */
/* @0x2d0f34 vldr s15, [r12, #16] */
/* @0x2d0f38 stm lr, {r0, r1} */
/* @0x2d0f3c vldr s9, [r12, #20] */
/* @0x2d0f40 ldm r5, {r0, r1} */
/* @0x2d0f44 vldr s8, [r12, #24] */
/* @0x2d0f48 vldr s10, [r12, #12] */
/* @0x2d0f4c ldr lr, [sp, #0x24] */
/* @0x2d0f50 vldr s11, [r2, #24] */
/* @0x2d0f54 vldr s7, [r2, #12] */
/* @0x2d0f58 stm r7, {r0, r1} */
/* @0x2d0f5c vldr s14, [lr, #4] */
/* @0x2d0f60 vsub.f32 s14, s14, s15 */
/* @0x2d0f64 vldr s6, [lr] */
/* @0x2d0f68 vldr s15, [r2, #16] */
/* @0x2d0f6c ldr r6, [sp, #0x28] */
/* @0x2d0f70 vldr s16, [sp, #44] */
/* @0x2d0f74 vmul.f32 s13, s14, s9 */
/* @0x2d0f78 vmul.f32 s14, s14, s8 */
/* @0x2d0f7c vsub.f32 s10, s6, s10 */
/* @0x2d0f80 vmla.f32 s13, s10, s8 */
/* @0x2d0f84 vmls.f32 s14, s9, s10 */
/* @0x2d0f88 vstr s13, [r4, #36] */
/* @0x2d0f8c vstr s14, [r4, #40] */
/* @0x2d0f90 vldr s14, [r6, #4] */
/* @0x2d0f94 vsub.f32 s15, s14, s15 */
/* @0x2d0f98 vldr s13, [r6] */
/* @0x2d0f9c vmul.f32 s14, s15, s12 */
/* @0x2d0fa0 vmul.f32 s15, s15, s11 */
/* @0x2d0fa4 vsub.f32 s13, s13, s7 */
/* @0x2d0fa8 vmla.f32 s14, s13, s11 */
/* @0x2d0fac vmls.f32 s15, s12, s13 */
/* @0x2d0fb0 vstr s14, [r4, #44] */
/* @0x2d0fb4 vstr s15, [r4, #48] */
/* @0x2d0fb8 vldr s15, [r3, #4] */
/* @0x2d0fbc vldr s14, [lr, #4] */
/* @0x2d0fc0 vsub.f32 s14, s14, s15 */
/* @0x2d0fc4 vldr s13, [lr] */
/* @0x2d0fc8 vldr s15, [r3] */
/* @0x2d0fcc vmul.f32 s14, s14, s14 */
/* @0x2d0fd0 vsub.f32 s15, s13, s15 */
/* @0x2d0fd4 vmla.f32 s14, s15, s15 */
/* @0x2d0fd8 vsqrt.f32 s15, s14 */
/* @0x2d0fdc vcmp.f32 s15, s15 */
/* @0x2d0fe0 vmrs APSR_nzcv, fpscr */
/* @0x2d0fe4 bne 0x2d1058 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0x150> */
/* @0x2d0fe8 vldr s13, [r6, #4] */
/* @0x2d0fec vldr s14, [r5, #4] */
/* @0x2d0ff0 vsub.f32 s14, s13, s14 */
/* @0x2d0ff4 vldr s12, [r6] */
/* @0x2d0ff8 vldr s13, [r5] */
/* @0x2d0ffc vstr s15, [r4, #52] */
/* @0x2d1000 vmul.f32 s14, s14, s14 */
/* @0x2d1004 vsub.f32 s15, s12, s13 */
/* @0x2d1008 vmla.f32 s14, s15, s15 */
/* @0x2d100c vsqrt.f32 s15, s14 */
/* @0x2d1010 vcmp.f32 s15, s15 */
/* @0x2d1014 vmrs APSR_nzcv, fpscr */
/* @0x2d1018 bne 0x2d1068 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0x160> */
/* @0x2d101c vldr s14, [pc, #84] */
/* @0x2d1020 ldr r3, [pc, #0x54] */
/* @0x2d1024 vcmpe.f32 s16, s14 */
/* @0x2d1028 ldr r1, [pc, #0x50] */
/* @0x2d102c ldr r3, [pc, r3] */
/* @0x2d1030 vstr s16, [r4, #60] */
/* @0x2d1034 vstr s15, [r4, #56] */
/* @0x2d1038 add r1, pc, r1 */
/* @0x2d103c ldr r3, [r3] */
/* @0x2d1040 vmrs APSR_nzcv, fpscr */
/* @0x2d1044 movle r0, #0 */
/* @0x2d1048 movgt r0, #1 */
/* @0x2d104c blx r3 */
/* @0x2d1050 vpop {d8} */
/* @0x2d1054 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2d1058 vmov r0, s14 */
/* @0x2d105c bl 0xb6700 <sqrtf@plt> */
/* @0x2d1060 vmov s15, r0 */
/* @0x2d1064 b 0x2d0fe8 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0xe0> */
/* @0x2d1068 vmov r0, s14 */
/* @0x2d106c bl 0xb6700 <sqrtf@plt> */
/* @0x2d1070 vmov s15, r0 */
/* @0x2d1074 b 0x2d101c <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0x114> */
/* @0x2d1078 strlo r0, [r0], #-0 */
/* @0x2d107c mulseq r2, r12, r4 */
/* @0x2d1080 andeq r12, r8, r8, lsr #16 */

/* ── FUNC 0x2d1084 · b2PulleyJoint::b2PulleyJoint(b2PulleyJointDef const*) · size=208 · insn=52 */
/* @0x2d1084 push {r3, r4, r5, r6, r7, lr} */
/* @0x2d1088 mov r5, r1 */
/* @0x2d108c mov r4, r0 */
/* @0x2d1090 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2d1094 add r3, r5, #20 */
/* @0x2d1098 ldr r2, [pc, #0xa8] */
/* @0x2d109c add r12, r5, #28 */
/* @0x2d10a0 add r7, r4, #76 */
/* @0x2d10a4 ldm r3, {r0, r1} */
/* @0x2d10a8 ldr r2, [pc, r2] */
/* @0x2d10ac mov r3, r4 */
/* @0x2d10b0 add r2, r2, #8 */
/* @0x2d10b4 str r2, [r3], #68 */
/* @0x2d10b8 add r6, r5, #36 */
/* @0x2d10bc stm r3, {r0, r1} */
/* @0x2d10c0 vldr s15, [r5, #60] */
/* @0x2d10c4 ldm r12, {r0, r1} */
/* @0x2d10c8 add lr, r4, #92 */
/* @0x2d10cc add r12, r5, #44 */
/* @0x2d10d0 vcmp.f32 s15, #0 */
/* @0x2d10d4 add r2, r4, #100 */
/* @0x2d10d8 ldr r3, [pc, #0x6c] */
/* @0x2d10dc stm r7, {r0, r1} */
/* @0x2d10e0 ldm r6, {r0, r1} */
/* @0x2d10e4 ldr r3, [pc, r3] */
/* @0x2d10e8 ldr r7, [r5, #0x34] */
/* @0x2d10ec vmrs APSR_nzcv, fpscr */
/* @0x2d10f0 ldr r6, [r5, #0x38] */
/* @0x2d10f4 stm lr, {r0, r1} */
/* @0x2d10f8 ldm r12, {r0, r1} */
/* @0x2d10fc ldr r3, [r3] */
/* @0x2d1100 stm r2, {r0, r1} */
/* @0x2d1104 moveq r0, #0 */
/* @0x2d1108 movne r0, #1 */
/* @0x2d110c ldr r1, [pc, #0x3c] */
/* @0x2d1110 str r7, [r4, #0x54] */
/* @0x2d1114 str r6, [r4, #0x58] */
/* @0x2d1118 add r1, pc, r1 */
/* @0x2d111c blx r3 */
/* @0x2d1120 vldr s14, [r5, #60] */
/* @0x2d1124 vldr s13, [r5, #56] */
/* @0x2d1128 vldr s15, [r5, #52] */
/* @0x2d112c vmla.f32 s15, s14, s13 */
/* @0x2d1130 mov r3, #0 */
/* @0x2d1134 vstr s14, [r4, #112] */
/* @0x2d1138 mov r0, r4 */
/* @0x2d113c str r3, [r4, #0x74] */
/* @0x2d1140 vstr s15, [r4, #108] */
/* @0x2d1144 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2d1148 andseq r0, r2, r4, asr #21 */
/* @0x2d114c andseq r0, r2, r4, ror #7 */
/* @0x2d1150 muleq r8, r4, r7 */

/* ── FUNC 0x2d1084 · b2PulleyJoint::b2PulleyJoint(b2PulleyJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d1154 · b2PulleyJoint::GetGroundAnchorA() const · size=24 · insn=6 */
/* @0x2d1154 add r1, r1, #68 */
/* @0x2d1158 mov r3, r0 */
/* @0x2d115c ldm r1, {r0, r1} */
/* @0x2d1160 stm r3, {r0, r1} */
/* @0x2d1164 mov r0, r3 */
/* @0x2d1168 bx lr */

/* ── FUNC 0x2d116c · b2PulleyJoint::GetGroundAnchorB() const · size=24 · insn=6 */
/* @0x2d116c add r1, r1, #76 */
/* @0x2d1170 mov r3, r0 */
/* @0x2d1174 ldm r1, {r0, r1} */
/* @0x2d1178 stm r3, {r0, r1} */
/* @0x2d117c mov r0, r3 */
/* @0x2d1180 bx lr */

/* ── FUNC 0x2d1184 · b2PulleyJoint::GetLengthA() const · size=8 · insn=2 */
/* @0x2d1184 ldr r0, [r0, #0x54] */
/* @0x2d1188 bx lr */

/* ── FUNC 0x2d118c · b2PulleyJoint::GetLengthB() const · size=8 · insn=2 */
/* @0x2d118c ldr r0, [r0, #0x58] */
/* @0x2d1190 bx lr */

/* ── FUNC 0x2d1194 · b2PulleyJoint::GetRatio() const · size=8 · insn=2 */
/* @0x2d1194 ldr r0, [r0, #0x70] */
/* @0x2d1198 bx lr */

/* ── FUNC 0x2d119c · b2PulleyJoint::GetCurrentLengthA() const · size=120 · insn=30 */
/* @0x2d119c vldr s9, [r0, #96] */
/* @0x2d11a0 push {r3, lr} */
/* @0x2d11a4 vldr s12, [r0, #92] */
/* @0x2d11a8 vldr s6, [r0, #72] */
/* @0x2d11ac ldr r3, [r0, #0x30] */
/* @0x2d11b0 vldr s11, [r3, #24] */
/* @0x2d11b4 vmul.f32 s13, s11, s9 */
/* @0x2d11b8 vldr s10, [r3, #20] */
/* @0x2d11bc vldr s14, [r3, #16] */
/* @0x2d11c0 vldr s7, [r3, #12] */
/* @0x2d11c4 vldr s8, [r0, #68] */
/* @0x2d11c8 vmul.f32 s15, s10, s9 */
/* @0x2d11cc vmla.f32 s13, s12, s10 */
/* @0x2d11d0 vnmls.f32 s15, s11, s12 */
/* @0x2d11d4 vadd.f32 s14, s13, s14 */
/* @0x2d11d8 vsub.f32 s14, s14, s6 */
/* @0x2d11dc vadd.f32 s15, s15, s7 */
/* @0x2d11e0 vmul.f32 s14, s14, s14 */
/* @0x2d11e4 vsub.f32 s15, s15, s8 */
/* @0x2d11e8 vmla.f32 s14, s15, s15 */
/* @0x2d11ec vsqrt.f32 s15, s14 */
/* @0x2d11f0 vcmp.f32 s15, s15 */
/* @0x2d11f4 vmrs APSR_nzcv, fpscr */
/* @0x2d11f8 bne 0x2d1204 <_ZNK13b2PulleyJoint17GetCurrentLengthAEv+0x68> */
/* @0x2d11fc vmov r0, s15 */
/* @0x2d1200 pop {r3, pc} */
/* @0x2d1204 vmov r0, s14 */
/* @0x2d1208 bl 0xb6700 <sqrtf@plt> */
/* @0x2d120c vmov s15, r0 */
/* @0x2d1210 b 0x2d11fc <_ZNK13b2PulleyJoint17GetCurrentLengthAEv+0x60> */

/* ── FUNC 0x2d1214 · b2PulleyJoint::GetCurrentLengthB() const · size=120 · insn=30 */
/* @0x2d1214 vldr s9, [r0, #104] */
/* @0x2d1218 push {r3, lr} */
/* @0x2d121c vldr s12, [r0, #100] */
/* @0x2d1220 vldr s6, [r0, #80] */
/* @0x2d1224 ldr r3, [r0, #0x34] */
/* @0x2d1228 vldr s11, [r3, #24] */
/* @0x2d122c vmul.f32 s13, s11, s9 */
/* @0x2d1230 vldr s10, [r3, #20] */
/* @0x2d1234 vldr s14, [r3, #16] */
/* @0x2d1238 vldr s7, [r3, #12] */
/* @0x2d123c vldr s8, [r0, #76] */
/* @0x2d1240 vmul.f32 s15, s10, s9 */
/* @0x2d1244 vmla.f32 s13, s12, s10 */
/* @0x2d1248 vnmls.f32 s15, s11, s12 */
/* @0x2d124c vadd.f32 s14, s13, s14 */
/* @0x2d1250 vsub.f32 s14, s14, s6 */
/* @0x2d1254 vadd.f32 s15, s15, s7 */
/* @0x2d1258 vmul.f32 s14, s14, s14 */
/* @0x2d125c vsub.f32 s15, s15, s8 */
/* @0x2d1260 vmla.f32 s14, s15, s15 */
/* @0x2d1264 vsqrt.f32 s15, s14 */
/* @0x2d1268 vcmp.f32 s15, s15 */
/* @0x2d126c vmrs APSR_nzcv, fpscr */
/* @0x2d1270 bne 0x2d127c <_ZNK13b2PulleyJoint17GetCurrentLengthBEv+0x68> */
/* @0x2d1274 vmov r0, s15 */
/* @0x2d1278 pop {r3, pc} */
/* @0x2d127c vmov r0, s14 */
/* @0x2d1280 bl 0xb6700 <sqrtf@plt> */
/* @0x2d1284 vmov s15, r0 */
/* @0x2d1288 b 0x2d1274 <_ZNK13b2PulleyJoint17GetCurrentLengthBEv+0x60> */

/* ── FUNC 0x2d128c · b2RevoluteJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2d128c ldr r3, [r1, #0x30] */
/* @0x2d1290 vldr s15, [r1, #72] */
/* @0x2d1294 vldr s12, [r3, #24] */
/* @0x2d1298 vldr s11, [r3, #20] */
/* @0x2d129c vmul.f32 s14, s12, s15 */
/* @0x2d12a0 vldr s13, [r1, #68] */
/* @0x2d12a4 vldr s9, [r3, #16] */
/* @0x2d12a8 vldr s10, [r3, #12] */
/* @0x2d12ac vmul.f32 s15, s11, s15 */
/* @0x2d12b0 vmla.f32 s14, s13, s11 */
/* @0x2d12b4 vnmls.f32 s15, s12, s13 */
/* @0x2d12b8 vadd.f32 s14, s14, s9 */
/* @0x2d12bc vadd.f32 s15, s15, s10 */
/* @0x2d12c0 vstr s14, [r0, #4] */
/* @0x2d12c4 vstr s15, [r0] */
/* @0x2d12c8 bx lr */

/* ── FUNC 0x2d12cc · b2RevoluteJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2d12cc ldr r3, [r1, #0x34] */
/* @0x2d12d0 vldr s15, [r1, #80] */
/* @0x2d12d4 vldr s12, [r3, #24] */
/* @0x2d12d8 vldr s11, [r3, #20] */
/* @0x2d12dc vmul.f32 s14, s12, s15 */
/* @0x2d12e0 vldr s13, [r1, #76] */
/* @0x2d12e4 vldr s9, [r3, #16] */
/* @0x2d12e8 vldr s10, [r3, #12] */
/* @0x2d12ec vmul.f32 s15, s11, s15 */
/* @0x2d12f0 vmla.f32 s14, s13, s11 */
/* @0x2d12f4 vnmls.f32 s15, s12, s13 */
/* @0x2d12f8 vadd.f32 s14, s14, s9 */
/* @0x2d12fc vadd.f32 s15, s15, s10 */
/* @0x2d1300 vstr s14, [r0, #4] */
/* @0x2d1304 vstr s15, [r0] */
/* @0x2d1308 bx lr */

/* ── FUNC 0x2d130c · b2RevoluteJoint::GetReactionForce(float) const · size=32 · insn=8 */
/* @0x2d130c vmov s15, r2 */
/* @0x2d1310 vldr s14, [r1, #88] */
/* @0x2d1314 vldr s13, [r1, #84] */
/* @0x2d1318 vmul.f32 s14, s15, s14 */
/* @0x2d131c vmul.f32 s15, s13, s15 */
/* @0x2d1320 vstr s14, [r0, #4] */
/* @0x2d1324 vstr s15, [r0] */
/* @0x2d1328 bx lr */

/* ── FUNC 0x2d132c · b2RevoluteJoint::GetReactionTorque(float) const · size=20 · insn=5 */
/* @0x2d132c vmov s14, r1 */
/* @0x2d1330 vldr s15, [r0, #92] */
/* @0x2d1334 vmul.f32 s14, s14, s15 */
/* @0x2d1338 vmov r0, s14 */
/* @0x2d133c bx lr */

/* ── FUNC 0x2d1340 · b2RevoluteJoint::~b2RevoluteJoint() · size=24 · insn=6 */
/* @0x2d1340 ldr r3, [pc, #0xc] */
/* @0x2d1344 ldr r3, [pc, r3] */
/* @0x2d1348 add r3, r3, #8 */
/* @0x2d134c str r3, [r0] */
/* @0x2d1350 bx lr */
/* @0x2d1354 andseq r0, r2, r0, lsl r8 */

/* ── FUNC 0x2d1340 · b2RevoluteJoint::~b2RevoluteJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d1358 · b2RevoluteJoint::Dump() · size=392 · insn=98 */
/* @0x2d1358 push {r4, r5, r6, lr} */
/* @0x2d135c mov r4, r0 */
/* @0x2d1360 ldr r2, [r4, #0x30] */
/* @0x2d1364 sub sp, sp, #8 */
/* @0x2d1368 ldr r3, [r4, #0x34] */
/* @0x2d136c ldr r0, [pc, #0x134] */
/* @0x2d1370 ldr r6, [r2, #0x8] */
/* @0x2d1374 add r0, pc, r0 */
/* @0x2d1378 ldr r5, [r3, #0x8] */
/* @0x2d137c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1380 ldr r0, [pc, #0x124] */
/* @0x2d1384 mov r1, r6 */
/* @0x2d1388 add r0, pc, r0 */
/* @0x2d138c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1390 ldr r0, [pc, #0x118] */
/* @0x2d1394 mov r1, r5 */
/* @0x2d1398 add r0, pc, r0 */
/* @0x2d139c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d13a0 ldr r0, [pc, #0x10c] */
/* @0x2d13a4 ldrb r1, [r4, #0x3d] */
/* @0x2d13a8 add r0, pc, r0 */
/* @0x2d13ac bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d13b0 vldr s13, [r4, #68] */
/* @0x2d13b4 vldr s14, [r4, #72] */
/* @0x2d13b8 vcvt.f64.f32 d5, s13 */
/* @0x2d13bc ldr r0, [pc, #0xf4] */
/* @0x2d13c0 add r0, pc, r0 */
/* @0x2d13c4 vcvt.f64.f32 d7, s14 */
/* @0x2d13c8 vmov r2, r3, d5 */
/* @0x2d13cc vstr d7, [sp] */
/* @0x2d13d0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d13d4 vldr s13, [r4, #76] */
/* @0x2d13d8 vldr s14, [r4, #80] */
/* @0x2d13dc vcvt.f64.f32 d5, s13 */
/* @0x2d13e0 ldr r0, [pc, #0xd4] */
/* @0x2d13e4 add r0, pc, r0 */
/* @0x2d13e8 vcvt.f64.f32 d7, s14 */
/* @0x2d13ec vmov r2, r3, d5 */
/* @0x2d13f0 vstr d7, [sp] */
/* @0x2d13f4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d13f8 vldr s15, [r4, #116] */
/* @0x2d13fc vcvt.f64.f32 d6, s15 */
/* @0x2d1400 ldr r0, [pc, #0xb8] */
/* @0x2d1404 add r0, pc, r0 */
/* @0x2d1408 vmov r2, r3, d6 */
/* @0x2d140c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1410 ldr r0, [pc, #0xac] */
/* @0x2d1414 ldrb r1, [r4, #0x70] */
/* @0x2d1418 add r0, pc, r0 */
/* @0x2d141c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1420 vldr s15, [r4, #120] */
/* @0x2d1424 vcvt.f64.f32 d5, s15 */
/* @0x2d1428 ldr r0, [pc, #0x98] */
/* @0x2d142c add r0, pc, r0 */
/* @0x2d1430 vmov r2, r3, d5 */
/* @0x2d1434 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1438 vldr s15, [r4, #124] */
/* @0x2d143c vcvt.f64.f32 d6, s15 */
/* @0x2d1440 ldr r0, [pc, #0x84] */
/* @0x2d1444 add r0, pc, r0 */
/* @0x2d1448 vmov r2, r3, d6 */
/* @0x2d144c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1450 ldr r0, [pc, #0x78] */
/* @0x2d1454 ldrb r1, [r4, #0x64] */
/* @0x2d1458 add r0, pc, r0 */
/* @0x2d145c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1460 vldr s15, [r4, #108] */
/* @0x2d1464 vcvt.f64.f32 d5, s15 */
/* @0x2d1468 ldr r0, [pc, #0x64] */
/* @0x2d146c add r0, pc, r0 */
/* @0x2d1470 vmov r2, r3, d5 */
/* @0x2d1474 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1478 vldr s15, [r4, #104] */
/* @0x2d147c vcvt.f64.f32 d6, s15 */
/* @0x2d1480 ldr r0, [pc, #0x50] */
/* @0x2d1484 add r0, pc, r0 */
/* @0x2d1488 vmov r2, r3, d6 */
/* @0x2d148c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d1490 ldr r0, [pc, #0x44] */
/* @0x2d1494 ldr r1, [r4, #0x38] */
/* @0x2d1498 add r0, pc, r0 */
/* @0x2d149c add sp, sp, #8 */
/* @0x2d14a0 pop {r4, r5, r6, lr} */
/* @0x2d14a4 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2d14a8 andeq r10, r8, r12, asr pc */
/* @0x2d14ac andeq r10, r8, r4, lsr #22 */
/* @0x2d14b0 andeq r10, r8, r0, lsr r11 */
/* @0x2d14b4 andeq r10, r8, r12, lsr r11 */
/* @0x2d14b8 andeq r10, r8, r8, asr #22 */
/* @0x2d14bc andeq r10, r8, r0, asr r11 */
/* @0x2d14c0 andeq r10, r8, r8, lsr #26 */
/* @0x2d14c4 andeq r10, r8, r4, lsr sp */
/* @0x2d14c8 andeq r10, r8, r0, asr #29 */
/* @0x2d14cc andeq r10, r8, r4, asr #29 */
/* @0x2d14d0 andeq r10, r8, r12, asr sp */
/* @0x2d14d4 andeq r10, r8, r8, ror #26 */
/* @0x2d14d8 andeq r10, r8, r0, lsr #29 */
/* @0x2d14dc andeq r10, r8, r0, lsr #22 */

/* ── FUNC 0x2d14e0 · b2RevoluteJoint::~b2RevoluteJoint() · size=40 · insn=10 */
/* @0x2d14e0 ldr r3, [pc, #0x1c] */
/* @0x2d14e4 push {r4, lr} */
/* @0x2d14e8 ldr r3, [pc, r3] */
/* @0x2d14ec mov r4, r0 */
/* @0x2d14f0 add r3, r3, #8 */
/* @0x2d14f4 str r3, [r0] */
/* @0x2d14f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d14fc mov r0, r4 */
/* @0x2d1500 pop {r4, pc} */
/* @0x2d1504 andseq r0, r2, r12, ror #12 */

/* ── FUNC 0x2d1508 · b2RevoluteJoint::SolveVelocityConstraints(b2SolverData const&) · size=964 · insn=241 */
/* @0x2d1508 push {r4, r5, r6, r7, r8, lr} */
/* @0x2d150c vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2d1510 vldr s19, [r0, #176] */
/* @0x2d1514 vldr s18, [r0, #180] */
/* @0x2d1518 vadd.f32 s15, s19, s18 */
/* @0x2d151c ldr r2, [r0, #0x80] */
/* @0x2d1520 ldr r3, [r0, #0x84] */
/* @0x2d1524 mov r4, r0 */
/* @0x2d1528 mov r5, r1 */
/* @0x2d152c vldr s22, [r0, #168] */
/* @0x2d1530 ldr r1, [r1, #0x1c] */
/* @0x2d1534 add r2, r2, r2, lsl #1 */
/* @0x2d1538 ldrb r0, [r0, #0x64] */
/* @0x2d153c add r3, r3, r3, lsl #1 */
/* @0x2d1540 add r2, r1, r2, lsl #2 */
/* @0x2d1544 vldr s25, [r2] */
/* @0x2d1548 vldr s23, [r2, #4] */
/* @0x2d154c vldr s17, [r2, #8] */
/* @0x2d1550 add r3, r1, r3, lsl #2 */
/* @0x2d1554 sub sp, sp, #32 */
/* @0x2d1558 vldr s21, [r4, #172] */
/* @0x2d155c vldr s24, [r3] */
/* @0x2d1560 vldr s20, [r3, #4] */
/* @0x2d1564 vldr s16, [r3, #8] */
/* @0x2d1568 vcmp.f32 s15, #0 */
/* @0x2d156c vmrs APSR_nzcv, fpscr */
/* @0x2d1570 movne r2, #0 */
/* @0x2d1574 moveq r2, #1 */
/* @0x2d1578 cmp r0, #0 */
/* @0x2d157c beq 0x2d1594 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x8c> */
/* @0x2d1580 ldr r3, [r4, #0xe0] */
/* @0x2d1584 cmp r3, #3 */
/* @0x2d1588 beq 0x2d1594 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x8c> */
/* @0x2d158c cmp r2, #0 */
/* @0x2d1590 beq 0x2d176c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x264> */
/* @0x2d1594 ldrb r3, [r4, #0x70] */
/* @0x2d1598 cmp r3, #0 */
/* @0x2d159c beq 0x2d15ac <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0xa4> */
/* @0x2d15a0 ldr r3, [r4, #0xe0] */
/* @0x2d15a4 cmp r3, #0 */
/* @0x2d15a8 bne 0x2d1694 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x18c> */
/* @0x2d15ac vmov.f32 s11, s20 */
/* @0x2d15b0 vldr s14, [r4, #144] */
/* @0x2d15b4 vldr s15, [r4, #148] */
/* @0x2d15b8 vldr s12, [r4, #136] */
/* @0x2d15bc vldr s13, [r4, #140] */
/* @0x2d15c0 add r0, sp, #8 */
/* @0x2d15c4 add r1, r4, #184 */
/* @0x2d15c8 add r2, sp, #20 */
/* @0x2d15cc vmov.f32 s10, s24 */
/* @0x2d15d0 vmla.f32 s11, s16, s14 */
/* @0x2d15d4 vmls.f32 s10, s16, s15 */
/* @0x2d15d8 vsub.f32 s14, s11, s23 */
/* @0x2d15dc vsub.f32 s15, s10, s25 */
/* @0x2d15e0 vmls.f32 s14, s17, s12 */
/* @0x2d15e4 vmla.f32 s15, s17, s13 */
/* @0x2d15e8 vneg.f32 s14, s14 */
/* @0x2d15ec vneg.f32 s15, s15 */
/* @0x2d15f0 vstr s14, [sp, #24] */
/* @0x2d15f4 vstr s15, [sp, #20] */
/* @0x2d15f8 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2> */
/* @0x2d15fc vldr s14, [sp, #8] */
/* @0x2d1600 vldr s12, [r4, #140] */
/* @0x2d1604 vldr s13, [r4, #148] */
/* @0x2d1608 vmul.f32 s12, s14, s12 */
/* @0x2d160c vldr s15, [sp, #12] */
/* @0x2d1610 vldr s8, [r4, #136] */
/* @0x2d1614 vldr s9, [r4, #144] */
/* @0x2d1618 vldr s10, [r4, #84] */
/* @0x2d161c vldr s11, [r4, #88] */
/* @0x2d1620 vmul.f32 s13, s14, s13 */
/* @0x2d1624 vnmls.f32 s12, s15, s8 */
/* @0x2d1628 vnmls.f32 s13, s15, s9 */
/* @0x2d162c vmls.f32 s17, s19, s12 */
/* @0x2d1630 vmla.f32 s16, s18, s13 */
/* @0x2d1634 vmls.f32 s25, s22, s14 */
/* @0x2d1638 vmla.f32 s24, s21, s14 */
/* @0x2d163c vmls.f32 s23, s22, s15 */
/* @0x2d1640 vmla.f32 s20, s21, s15 */
/* @0x2d1644 vadd.f32 s14, s10, s14 */
/* @0x2d1648 vadd.f32 s15, s11, s15 */
/* @0x2d164c vstr s14, [r4, #84] */
/* @0x2d1650 vstr s15, [r4, #88] */
/* @0x2d1654 ldr r2, [r4, #0x80] */
/* @0x2d1658 ldr r3, [r4, #0x84] */
/* @0x2d165c ldr r1, [r5, #0x1c] */
/* @0x2d1660 add r2, r2, r2, lsl #1 */
/* @0x2d1664 add r3, r3, r3, lsl #1 */
/* @0x2d1668 add r2, r1, r2, lsl #2 */
/* @0x2d166c vstr s25, [r2] */
/* @0x2d1670 vstr s23, [r2, #4] */
/* @0x2d1674 vstr s17, [r2, #8] */
/* @0x2d1678 add r3, r1, r3, lsl #2 */
/* @0x2d167c vstr s24, [r3] */
/* @0x2d1680 vstr s20, [r3, #4] */
/* @0x2d1684 vstr s16, [r3, #8] */
/* @0x2d1688 add sp, sp, #32 */
/* @0x2d168c vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2d1690 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2d1694 cmp r2, #0 */
/* @0x2d1698 bne 0x2d15ac <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0xa4> */
/* @0x2d169c vmov.f32 s26, s24 */
/* @0x2d16a0 vldr s12, [r4, #148] */
/* @0x2d16a4 vldr s13, [r4, #144] */
/* @0x2d16a8 vldr s14, [r4, #140] */
/* @0x2d16ac vldr s15, [r4, #136] */
/* @0x2d16b0 add r6, r4, #184 */
/* @0x2d16b4 add r7, sp, #20 */
/* @0x2d16b8 add r2, sp, #8 */
/* @0x2d16bc vmov.f32 s27, s20 */
/* @0x2d16c0 mov r1, r6 */
/* @0x2d16c4 mov r0, r7 */
/* @0x2d16c8 vmls.f32 s26, s16, s12 */
/* @0x2d16cc vmla.f32 s27, s16, s13 */
/* @0x2d16d0 vsub.f32 s26, s26, s25 */
/* @0x2d16d4 vsub.f32 s27, s27, s23 */
/* @0x2d16d8 vmla.f32 s26, s17, s14 */
/* @0x2d16dc vmls.f32 s27, s17, s15 */
/* @0x2d16e0 vstr s26, [sp, #8] */
/* @0x2d16e4 vsub.f32 s15, s16, s17 */
/* @0x2d16e8 vstr s27, [sp, #12] */
/* @0x2d16ec vstr s15, [sp, #16] */
/* @0x2d16f0 bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3> */
/* @0x2d16f4 ldr r3, [r4, #0xe0] */
/* @0x2d16f8 vldr s10, [sp, #20] */
/* @0x2d16fc vldr s12, [sp, #24] */
/* @0x2d1700 vldr s13, [sp, #28] */
/* @0x2d1704 cmp r3, #3 */
/* @0x2d1708 vneg.f32 s14, s10 */
/* @0x2d170c vneg.f32 s15, s12 */
/* @0x2d1710 vneg.f32 s11, s13 */
/* @0x2d1714 beq 0x2d1834 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x32c> */
/* @0x2d1718 cmp r3, #1 */
/* @0x2d171c beq 0x2d187c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x374> */
/* @0x2d1720 cmp r3, #2 */
/* @0x2d1724 beq 0x2d17c4 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x2bc> */
/* @0x2d1728 vldr s12, [r4, #140] */
/* @0x2d172c vldr s13, [r4, #148] */
/* @0x2d1730 vmul.f32 s12, s14, s12 */
/* @0x2d1734 vldr s9, [r4, #136] */
/* @0x2d1738 vldr s10, [r4, #144] */
/* @0x2d173c vmul.f32 s13, s14, s13 */
/* @0x2d1740 vnmls.f32 s12, s15, s9 */
/* @0x2d1744 vnmls.f32 s13, s15, s10 */
/* @0x2d1748 vadd.f32 s12, s12, s11 */
/* @0x2d174c vadd.f32 s13, s13, s11 */
/* @0x2d1750 vmls.f32 s25, s22, s14 */
/* @0x2d1754 vmls.f32 s23, s22, s15 */
/* @0x2d1758 vmla.f32 s24, s21, s14 */
/* @0x2d175c vmla.f32 s20, s21, s15 */
/* @0x2d1760 vmls.f32 s17, s12, s19 */
/* @0x2d1764 vmla.f32 s16, s13, s18 */
/* @0x2d1768 b 0x2d1654 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x14c> */
/* @0x2d176c vsub.f32 s10, s16, s17 */
/* @0x2d1770 vldr s12, [r4, #108] */
/* @0x2d1774 vldr s14, [r4, #96] */
/* @0x2d1778 vldr s11, [r4, #220] */
/* @0x2d177c vldr s13, [r5] */
/* @0x2d1780 vldr s15, [r4, #104] */
/* @0x2d1784 vsub.f32 s12, s10, s12 */
/* @0x2d1788 vmov.f32 s10, s14 */
/* @0x2d178c vmls.f32 s10, s11, s12 */
/* @0x2d1790 vmul.f32 s15, s13, s15 */
/* @0x2d1794 vcmpe.f32 s15, s10 */
/* @0x2d1798 vneg.f32 s13, s15 */
/* @0x2d179c vmrs APSR_nzcv, fpscr */
/* @0x2d17a0 vmovgt.f32 s15, s10 */
/* @0x2d17a4 vcmpe.f32 s13, s15 */
/* @0x2d17a8 vmrs APSR_nzcv, fpscr */
/* @0x2d17ac vmovgt.f32 s15, s13 */
/* @0x2d17b0 vstr s15, [r4, #96] */
/* @0x2d17b4 vsub.f32 s15, s15, s14 */
/* @0x2d17b8 vmls.f32 s17, s19, s15 */
/* @0x2d17bc vmla.f32 s16, s18, s15 */
/* @0x2d17c0 b 0x2d1594 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x8c> */
/* @0x2d17c4 vldr s9, [r4, #92] */
/* @0x2d17c8 vsub.f32 s13, s9, s13 */
/* @0x2d17cc mov r8, #0 */
/* @0x2d17d0 vcmpe.f32 s13, #0 */
/* @0x2d17d4 vmrs APSR_nzcv, fpscr */
/* @0x2d17d8 ble 0x2d185c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x354> */
/* @0x2d17dc vldr s14, [r4, #212] */
/* @0x2d17e0 vldr s15, [r4, #208] */
/* @0x2d17e4 vnmls.f32 s27, s9, s14 */
/* @0x2d17e8 mov r0, r7 */
/* @0x2d17ec mov r1, r6 */
/* @0x2d17f0 mov r2, sp */
/* @0x2d17f4 vnmls.f32 s26, s9, s15 */
/* @0x2d17f8 vstr s27, [sp, #4] */
/* @0x2d17fc vstr s26, [sp] */
/* @0x2d1800 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2> */
/* @0x2d1804 vldr s14, [sp, #20] */
/* @0x2d1808 vldr s12, [r4, #84] */
/* @0x2d180c vldr s15, [sp, #24] */
/* @0x2d1810 vldr s13, [r4, #88] */
/* @0x2d1814 vadd.f32 s12, s12, s14 */
/* @0x2d1818 vldr s11, [r4, #92] */
/* @0x2d181c str r8, [r4, #0x5c] */
/* @0x2d1820 vadd.f32 s13, s13, s15 */
/* @0x2d1824 vstr s12, [r4, #84] */
/* @0x2d1828 vstr s13, [r4, #88] */
/* @0x2d182c vneg.f32 s11, s11 */
/* @0x2d1830 b 0x2d1728 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x220> */
/* @0x2d1834 vldr s7, [r4, #84] */
/* @0x2d1838 vldr s8, [r4, #88] */
/* @0x2d183c vldr s9, [r4, #92] */
/* @0x2d1840 vsub.f32 s10, s7, s10 */
/* @0x2d1844 vsub.f32 s12, s8, s12 */
/* @0x2d1848 vstr s10, [r4, #84] */
/* @0x2d184c vsub.f32 s13, s9, s13 */
/* @0x2d1850 vstr s12, [r4, #88] */
/* @0x2d1854 vstr s13, [r4, #92] */
/* @0x2d1858 b 0x2d1728 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x220> */
/* @0x2d185c vldr s8, [r4, #84] */
/* @0x2d1860 vldr s9, [r4, #88] */
/* @0x2d1864 vsub.f32 s10, s8, s10 */
/* @0x2d1868 vstr s13, [r4, #92] */
/* @0x2d186c vsub.f32 s12, s9, s12 */
/* @0x2d1870 vstr s10, [r4, #84] */
/* @0x2d1874 vstr s12, [r4, #88] */
/* @0x2d1878 b 0x2d1728 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x220> */
/* @0x2d187c vldr s9, [r4, #92] */
/* @0x2d1880 vsub.f32 s13, s9, s13 */
/* @0x2d1884 mov r8, #0 */
/* @0x2d1888 vcmpe.f32 s13, #0 */
/* @0x2d188c vmrs APSR_nzcv, fpscr */
/* @0x2d1890 bpl 0x2d185c <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x354> */
/* @0x2d1894 vldr s14, [r4, #212] */
/* @0x2d1898 vldr s15, [r4, #208] */
/* @0x2d189c vnmls.f32 s27, s9, s14 */
/* @0x2d18a0 mov r1, r6 */
/* @0x2d18a4 mov r2, r7 */
/* @0x2d18a8 mov r0, sp */
/* @0x2d18ac vnmls.f32 s26, s9, s15 */
/* @0x2d18b0 vstr s27, [sp, #24] */
/* @0x2d18b4 vstr s26, [sp, #20] */
/* @0x2d18b8 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2> */
/* @0x2d18bc vldr s14, [sp] */
/* @0x2d18c0 vldr s12, [r4, #84] */
/* @0x2d18c4 vldr s15, [sp, #4] */
/* @0x2d18c8 b 0x2d1810 <_ZN15b2RevoluteJoint24SolveVelocityConstraintsERK12b2SolverData+0x308> */

/* ── FUNC 0x2d18cc · b2RevoluteJoint::InitVelocityConstraints(b2SolverData const&) · size=944 · insn=236 */
/* @0x2d18cc ldr r2, [r0, #0x30] */
/* @0x2d18d0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2d18d4 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d18d8 mov r6, r1 */
/* @0x2d18dc vldr s18, [r2, #136] */
/* @0x2d18e0 ldr r3, [r0, #0x34] */
/* @0x2d18e4 add r1, r2, #44 */
/* @0x2d18e8 ldr lr, [r2, #0x8] */
/* @0x2d18ec mov r4, r0 */
/* @0x2d18f0 vldr s19, [r3, #136] */
/* @0x2d18f4 ldr r9, [r6, #0x18] */
/* @0x2d18f8 ldr r12, [r3, #0x8] */
/* @0x2d18fc add r8, r0, #160 */
/* @0x2d1900 add r10, r0, #152 */
/* @0x2d1904 ldm r1, {r0, r1} */
/* @0x2d1908 str lr, [r4, #0x80] */
/* @0x2d190c add lr, lr, lr, lsl #1 */
/* @0x2d1910 vldr s16, [r2, #144] */
/* @0x2d1914 add r7, r3, #44 */
/* @0x2d1918 lsl lr, lr, #2 */
/* @0x2d191c ldr r5, [r6, #0x1c] */
/* @0x2d1920 add r2, r9, lr */
/* @0x2d1924 str r12, [r4, #0x84] */
/* @0x2d1928 stm r10, {r0, r1} */
/* @0x2d192c add r12, r12, r12, lsl #1 */
/* @0x2d1930 ldm r7, {r0, r1} */
/* @0x2d1934 vldr s17, [r3, #144] */
/* @0x2d1938 ldr r7, [r2, #0x8] */
/* @0x2d193c lsl r12, r12, #2 */
/* @0x2d1940 add lr, r5, lr */
/* @0x2d1944 add r9, r9, r12 */
/* @0x2d1948 stm r8, {r0, r1} */
/* @0x2d194c vstr s18, [r4, #168] */
/* @0x2d1950 mov r0, r7 */
/* @0x2d1954 vstr s19, [r4, #172] */
/* @0x2d1958 vstr s16, [r4, #176] */
/* @0x2d195c vstr s17, [r4, #180] */
/* @0x2d1960 add r12, r5, r12 */
/* @0x2d1964 vldr s28, [lr] */
/* @0x2d1968 vldr s27, [lr, #4] */
/* @0x2d196c vldr s23, [lr, #8] */
/* @0x2d1970 vldr s26, [r12] */
/* @0x2d1974 vldr s25, [r12, #4] */
/* @0x2d1978 vldr s24, [r12, #8] */
/* @0x2d197c bl 0xb6580 <sinf@plt> */
/* @0x2d1980 ldr r8, [r9, #0x8] */
/* @0x2d1984 vmov s22, r0 */
/* @0x2d1988 mov r0, r7 */
/* @0x2d198c bl 0xb658c <cosf@plt> */
/* @0x2d1990 vmov s21, r0 */
/* @0x2d1994 mov r0, r8 */
/* @0x2d1998 bl 0xb6580 <sinf@plt> */
/* @0x2d199c vmov s20, r0 */
/* @0x2d19a0 mov r0, r8 */
/* @0x2d19a4 bl 0xb658c <cosf@plt> */
/* @0x2d19a8 vldr s14, [r4, #72] */
/* @0x2d19ac vldr s15, [r4, #156] */
/* @0x2d19b0 vsub.f32 s15, s14, s15 */
/* @0x2d19b4 vldr s12, [r4, #80] */
/* @0x2d19b8 vldr s14, [r4, #164] */
/* @0x2d19bc vldr s13, [r4, #152] */
/* @0x2d19c0 vldr s9, [r4, #68] */
/* @0x2d19c4 vldr s8, [r4, #76] */
/* @0x2d19c8 vldr s10, [r4, #160] */
/* @0x2d19cc vsub.f32 s14, s12, s14 */
/* @0x2d19d0 vmul.f32 s12, s15, s21 */
/* @0x2d19d4 vmov s11, r0 */
/* @0x2d19d8 vsub.f32 s9, s9, s13 */
/* @0x2d19dc vmla.f32 s12, s9, s22 */
/* @0x2d19e0 vmul.f32 s13, s14, s11 */
/* @0x2d19e4 vstr s12, [r4, #140] */
/* @0x2d19e8 ldrb r2, [r4, #0x64] */
/* @0x2d19ec vmul.f32 s14, s14, s20 */
/* @0x2d19f0 vsub.f32 s10, s8, s10 */
/* @0x2d19f4 vmul.f32 s15, s15, s22 */
/* @0x2d19f8 vmla.f32 s13, s10, s20 */
/* @0x2d19fc vnmls.f32 s14, s10, s11 */
/* @0x2d1a00 vstr s13, [r4, #148] */
/* @0x2d1a04 vadd.f32 s10, s18, s19 */
/* @0x2d1a08 vstr s14, [r4, #144] */
/* @0x2d1a0c vnmls.f32 s15, s9, s21 */
/* @0x2d1a10 vmul.f32 s9, s12, s12 */
/* @0x2d1a14 vstr s15, [r4, #136] */
/* @0x2d1a18 vmov.f32 s7, s10 */
/* @0x2d1a1c vmla.f32 s7, s16, s9 */
/* @0x2d1a20 vmul.f32 s11, s14, s13 */
/* @0x2d1a24 vmov.f32 s9, s7 */
/* @0x2d1a28 vmul.f32 s7, s14, s14 */
/* @0x2d1a2c vmul.f32 s14, s17, s14 */
/* @0x2d1a30 vmul.f32 s8, s15, s15 */
/* @0x2d1a34 vneg.f32 s12, s12 */
/* @0x2d1a38 vmla.f32 s14, s16, s15 */
/* @0x2d1a3c vmla.f32 s10, s16, s8 */
/* @0x2d1a40 vstr s14, [r4, #212] */
/* @0x2d1a44 vstr s14, [r4, #204] */
/* @0x2d1a48 vmul.f32 s8, s12, s15 */
/* @0x2d1a4c vadd.f32 s15, s16, s17 */
/* @0x2d1a50 vcmp.f32 s15, #0 */
/* @0x2d1a54 vstr s15, [r4, #216] */
/* @0x2d1a58 vmrs APSR_nzcv, fpscr */
/* @0x2d1a5c vcmpe.f32 s15, #0 */
/* @0x2d1a60 movne r3, #0 */
/* @0x2d1a64 moveq r3, #1 */
/* @0x2d1a68 vmrs APSR_nzcv, fpscr */
/* @0x2d1a6c vmovgt.f32 s14, #1.000000e+00 */
/* @0x2d1a70 vdivgt.f32 s15, s14, s15 */
/* @0x2d1a74 cmp r2, #0 */
/* @0x2d1a78 vmul.f32 s6, s13, s13 */
/* @0x2d1a7c vstr s15, [r4, #220] */
/* @0x2d1a80 vmul.f32 s11, s17, s11 */
/* @0x2d1a84 vmul.f32 s13, s17, s13 */
/* @0x2d1a88 vnmls.f32 s11, s16, s8 */
/* @0x2d1a8c vnmls.f32 s13, s16, s12 */
/* @0x2d1a90 vstr s11, [r4, #196] */
/* @0x2d1a94 vstr s11, [r4, #188] */
/* @0x2d1a98 vmla.f32 s9, s17, s6 */
/* @0x2d1a9c vstr s13, [r4, #208] */
/* @0x2d1aa0 vstr s13, [r4, #192] */
/* @0x2d1aa4 vmla.f32 s10, s17, s7 */
/* @0x2d1aa8 vstr s9, [r4, #184] */
/* @0x2d1aac vstr s10, [r4, #200] */
/* @0x2d1ab0 beq 0x2d1b24 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x258> */
/* @0x2d1ab4 cmp r3, #0 */
/* @0x2d1ab8 beq 0x2d1c54 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x388> */
/* @0x2d1abc mov r3, #0 */
/* @0x2d1ac0 str r3, [r4, #0x60] */
/* @0x2d1ac4 mov r3, #0 */
/* @0x2d1ac8 str r3, [r4, #0xe0] */
/* @0x2d1acc ldrb r3, [r6, #0x14] */
/* @0x2d1ad0 cmp r3, #0 */
/* @0x2d1ad4 bne 0x2d1bac <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x2e0> */
/* @0x2d1ad8 mov r3, #0 */
/* @0x2d1adc str r3, [r4, #0x54] */
/* @0x2d1ae0 str r3, [r4, #0x58] */
/* @0x2d1ae4 str r3, [r4, #0x5c] */
/* @0x2d1ae8 str r3, [r4, #0x60] */
/* @0x2d1aec ldr r3, [r4, #0x80] */
/* @0x2d1af0 ldr r2, [r4, #0x84] */
/* @0x2d1af4 add r3, r3, r3, lsl #1 */
/* @0x2d1af8 add r2, r2, r2, lsl #1 */
/* @0x2d1afc add r3, r5, r3, lsl #2 */
/* @0x2d1b00 vstr s28, [r3] */
/* @0x2d1b04 vstr s27, [r3, #4] */
/* @0x2d1b08 vstr s23, [r3, #8] */
/* @0x2d1b0c add r5, r5, r2, lsl #2 */
/* @0x2d1b10 vstr s26, [r5] */
/* @0x2d1b14 vstr s25, [r5, #4] */
/* @0x2d1b18 vstr s24, [r5, #8] */
/* @0x2d1b1c vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d1b20 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2d1b24 ldrb r2, [r4, #0x70] */
/* @0x2d1b28 mov r1, #0 */
/* @0x2d1b2c str r1, [r4, #0x60] */
/* @0x2d1b30 cmp r2, #0 */
/* @0x2d1b34 beq 0x2d1ac4 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8> */
/* @0x2d1b38 cmp r3, #0 */
/* @0x2d1b3c bne 0x2d1ac4 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8> */
/* @0x2d1b40 vldr s13, [r4, #124] */
/* @0x2d1b44 vldr s14, [r4, #120] */
/* @0x2d1b48 vsub.f32 s15, s13, s14 */
/* @0x2d1b4c vldr s12, [pc, #292] */
/* @0x2d1b50 vldr s11, [r4, #116] */
/* @0x2d1b54 vcmpe.f32 s15, #0 */
/* @0x2d1b58 vmrs APSR_nzcv, fpscr */
/* @0x2d1b5c vnegle.f32 s15, s15 */
/* @0x2d1b60 vcmpe.f32 s15, s12 */
/* @0x2d1b64 vmrs APSR_nzcv, fpscr */
/* @0x2d1b68 movmi r3, #3 */
/* @0x2d1b6c strmi r3, [r4, #0xe0] */
/* @0x2d1b70 bmi 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200> */
/* @0x2d1b74 vmov s10, r8 */
/* @0x2d1b78 vmov s12, r7 */
/* @0x2d1b7c vsub.f32 s15, s10, s12 */
/* @0x2d1b80 vsub.f32 s11, s15, s11 */
/* @0x2d1b84 vcmpe.f32 s11, s14 */
/* @0x2d1b88 vmrs APSR_nzcv, fpscr */
/* @0x2d1b8c bhi 0x2d1c2c <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x360> */
/* @0x2d1b90 ldr r3, [r4, #0xe0] */
/* @0x2d1b94 cmp r3, #1 */
/* @0x2d1b98 movne r3, #0 */
/* @0x2d1b9c strne r3, [r4, #0x5c] */
/* @0x2d1ba0 mov r3, #1 */
/* @0x2d1ba4 str r3, [r4, #0xe0] */
/* @0x2d1ba8 b 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200> */
/* @0x2d1bac vldr s13, [r6, #8] */
/* @0x2d1bb0 vldr s14, [r4, #84] */
/* @0x2d1bb4 vmul.f32 s14, s13, s14 */
/* @0x2d1bb8 vldr s15, [r4, #88] */
/* @0x2d1bbc vldr s10, [r4, #140] */
/* @0x2d1bc0 vldr s12, [r4, #148] */
/* @0x2d1bc4 vldr s7, [r4, #136] */
/* @0x2d1bc8 vldr s8, [r4, #144] */
/* @0x2d1bcc vldr s11, [r4, #96] */
/* @0x2d1bd0 vldr s9, [r4, #92] */
/* @0x2d1bd4 vmul.f32 s15, s13, s15 */
/* @0x2d1bd8 vstr s14, [r4, #84] */
/* @0x2d1bdc vmul.f32 s10, s14, s10 */
/* @0x2d1be0 vstr s15, [r4, #88] */
/* @0x2d1be4 vmul.f32 s12, s14, s12 */
/* @0x2d1be8 vnmls.f32 s10, s15, s7 */
/* @0x2d1bec vnmls.f32 s12, s15, s8 */
/* @0x2d1bf0 vmul.f32 s11, s13, s11 */
/* @0x2d1bf4 vmul.f32 s13, s13, s9 */
/* @0x2d1bf8 vstr s11, [r4, #96] */
/* @0x2d1bfc vadd.f32 s10, s11, s10 */
/* @0x2d1c00 vstr s13, [r4, #92] */
/* @0x2d1c04 vadd.f32 s12, s11, s12 */
/* @0x2d1c08 vadd.f32 s10, s10, s13 */
/* @0x2d1c0c vadd.f32 s13, s12, s13 */
/* @0x2d1c10 vmls.f32 s28, s18, s14 */
/* @0x2d1c14 vmla.f32 s26, s19, s14 */
/* @0x2d1c18 vmls.f32 s27, s18, s15 */
/* @0x2d1c1c vmla.f32 s25, s19, s15 */
/* @0x2d1c20 vmls.f32 s23, s16, s10 */
/* @0x2d1c24 vmla.f32 s24, s17, s13 */
/* @0x2d1c28 b 0x2d1aec <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x220> */
/* @0x2d1c2c vcmpe.f32 s11, s13 */
/* @0x2d1c30 vmrs APSR_nzcv, fpscr */
/* @0x2d1c34 blt 0x2d1c64 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x398> */
/* @0x2d1c38 ldr r3, [r4, #0xe0] */
/* @0x2d1c3c cmp r3, #2 */
/* @0x2d1c40 movne r3, #0 */
/* @0x2d1c44 strne r3, [r4, #0x5c] */
/* @0x2d1c48 mov r3, #2 */
/* @0x2d1c4c str r3, [r4, #0xe0] */
/* @0x2d1c50 b 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200> */
/* @0x2d1c54 ldrb r3, [r4, #0x70] */
/* @0x2d1c58 cmp r3, #0 */
/* @0x2d1c5c bne 0x2d1b40 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x274> */
/* @0x2d1c60 b 0x2d1ac4 <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8> */
/* @0x2d1c64 mov r3, #0 */
/* @0x2d1c68 mov r2, #0 */
/* @0x2d1c6c str r3, [r4, #0xe0] */
/* @0x2d1c70 str r2, [r4, #0x5c] */
/* @0x2d1c74 b 0x2d1acc <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x200> */
/* @0x2d1c78 vstrlo s30, [lr, #216] */

/* ── FUNC 0x2d1c7c · b2RevoluteJoint::SolvePositionConstraints(b2SolverData const&) · size=860 · insn=215 */
/* @0x2d1c7c push {r4, r5, r6, r7, r8, lr} */
/* @0x2d1c80 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d1c84 mov r8, r1 */
/* @0x2d1c88 vldr s20, [r0, #176] */
/* @0x2d1c8c ldr r6, [r0, #0x80] */
/* @0x2d1c90 mov r4, r0 */
/* @0x2d1c94 ldr r7, [r0, #0x84] */
/* @0x2d1c98 vldr s23, [r0, #180] */
/* @0x2d1c9c ldrb r1, [r0, #0x70] */
/* @0x2d1ca0 ldr r5, [r8, #0x18] */
/* @0x2d1ca4 add r2, r6, r6, lsl #1 */
/* @0x2d1ca8 add r3, r7, r7, lsl #1 */
/* @0x2d1cac cmp r1, #0 */
/* @0x2d1cb0 add r2, r5, r2, lsl #2 */
/* @0x2d1cb4 vldr s29, [r2] */
/* @0x2d1cb8 add r3, r5, r3, lsl #2 */
/* @0x2d1cbc vldr s28, [r2, #4] */
/* @0x2d1cc0 vldr s24, [r2, #8] */
/* @0x2d1cc4 vldr s27, [r3] */
/* @0x2d1cc8 vldr s26, [r3, #4] */
/* @0x2d1ccc vldr s25, [r3, #8] */
/* @0x2d1cd0 beq 0x2d1ce0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x64> */
/* @0x2d1cd4 ldr r3, [r0, #0xe0] */
/* @0x2d1cd8 cmp r3, #0 */
/* @0x2d1cdc bne 0x2d1e84 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x208> */
/* @0x2d1ce0 vldr s30, [pc, #732] */
/* @0x2d1ce4 vmov r0, s24 */
/* @0x2d1ce8 bl 0xb6580 <sinf@plt> */
/* @0x2d1cec vmov s21, r0 */
/* @0x2d1cf0 vmov r0, s24 */
/* @0x2d1cf4 bl 0xb658c <cosf@plt> */
/* @0x2d1cf8 vmov s22, r0 */
/* @0x2d1cfc vmov r0, s25 */
/* @0x2d1d00 bl 0xb6580 <sinf@plt> */
/* @0x2d1d04 vmov s18, r0 */
/* @0x2d1d08 vmov r0, s25 */
/* @0x2d1d0c bl 0xb658c <cosf@plt> */
/* @0x2d1d10 vldr s15, [r4, #164] */
/* @0x2d1d14 vldr s19, [r4, #80] */
/* @0x2d1d18 vsub.f32 s19, s19, s15 */
/* @0x2d1d1c vldr s10, [r4, #76] */
/* @0x2d1d20 vldr s13, [r4, #160] */
/* @0x2d1d24 vldr s16, [r4, #72] */
/* @0x2d1d28 vldr s11, [r4, #156] */
/* @0x2d1d2c vldr s12, [r4, #68] */
/* @0x2d1d30 vldr s15, [r4, #152] */
/* @0x2d1d34 vsub.f32 s13, s10, s13 */
/* @0x2d1d38 vsub.f32 s16, s16, s11 */
/* @0x2d1d3c vsub.f32 s15, s12, s15 */
/* @0x2d1d40 vmov s14, r0 */
/* @0x2d1d44 vmul.f32 s17, s19, s14 */
/* @0x2d1d48 vmul.f32 s19, s19, s18 */
/* @0x2d1d4c vmla.f32 s17, s13, s18 */
/* @0x2d1d50 vmul.f32 s18, s16, s22 */
/* @0x2d1d54 vnmls.f32 s19, s13, s14 */
/* @0x2d1d58 vmla.f32 s18, s15, s21 */
/* @0x2d1d5c vmul.f32 s16, s16, s21 */
/* @0x2d1d60 vadd.f32 s21, s26, s17 */
/* @0x2d1d64 vsub.f32 s21, s21, s28 */
/* @0x2d1d68 vnmls.f32 s16, s15, s22 */
/* @0x2d1d6c vadd.f32 s22, s27, s19 */
/* @0x2d1d70 vsub.f32 s21, s21, s18 */
/* @0x2d1d74 vsub.f32 s22, s22, s29 */
/* @0x2d1d78 vmul.f32 s15, s21, s21 */
/* @0x2d1d7c vsub.f32 s22, s22, s16 */
/* @0x2d1d80 vmla.f32 s15, s22, s22 */
/* @0x2d1d84 vsqrt.f32 s10, s15 */
/* @0x2d1d88 vcmp.f32 s10, s10 */
/* @0x2d1d8c vmrs APSR_nzcv, fpscr */
/* @0x2d1d90 bne 0x2d1f88 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x30c> */
/* @0x2d1d94 vldr s8, [r4, #168] */
/* @0x2d1d98 vldr s9, [r4, #172] */
/* @0x2d1d9c vadd.f32 s12, s8, s9 */
/* @0x2d1da0 add r6, r6, r6, lsl #1 */
/* @0x2d1da4 add r7, r7, r7, lsl #1 */
/* @0x2d1da8 add r6, r5, r6, lsl #2 */
/* @0x2d1dac add r5, r5, r7, lsl #2 */
/* @0x2d1db0 vmul.f32 s11, s20, s16 */
/* @0x2d1db4 vmul.f32 s15, s23, s19 */
/* @0x2d1db8 vmul.f32 s7, s20, s18 */
/* @0x2d1dbc vmov.f32 s6, s12 */
/* @0x2d1dc0 vmla.f32 s6, s11, s16 */
/* @0x2d1dc4 vmul.f32 s14, s15, s17 */
/* @0x2d1dc8 vnmul.f32 s13, s20, s16 */
/* @0x2d1dcc vmla.f32 s12, s7, s18 */
/* @0x2d1dd0 vldr s7, [pc, #496] */
/* @0x2d1dd4 vnmls.f32 s14, s13, s18 */
/* @0x2d1dd8 vmul.f32 s13, s23, s17 */
/* @0x2d1ddc vmov.f32 s11, s6 */
/* @0x2d1de0 vmla.f32 s12, s13, s17 */
/* @0x2d1de4 vmla.f32 s11, s15, s19 */
/* @0x2d1de8 vmul.f32 s15, s14, s14 */
/* @0x2d1dec vnmls.f32 s15, s12, s11 */
/* @0x2d1df0 vcmp.f32 s15, #0 */
/* @0x2d1df4 vmrs APSR_nzcv, fpscr */
/* @0x2d1df8 vmovne.f32 s13, #1.000000e+00 */
/* @0x2d1dfc vdivne.f32 s15, s13, s15 */
/* @0x2d1e00 vmul.f32 s13, s14, s21 */
/* @0x2d1e04 vmul.f32 s14, s14, s22 */
/* @0x2d1e08 vnmls.f32 s13, s11, s22 */
/* @0x2d1e0c vnmls.f32 s14, s12, s21 */
/* @0x2d1e10 vnmul.f32 s13, s15, s13 */
/* @0x2d1e14 vnmul.f32 s15, s14, s15 */
/* @0x2d1e18 vmul.f32 s18, s18, s13 */
/* @0x2d1e1c vmul.f32 s17, s17, s13 */
/* @0x2d1e20 vnmls.f32 s18, s16, s15 */
/* @0x2d1e24 vnmls.f32 s17, s19, s15 */
/* @0x2d1e28 vmls.f32 s29, s8, s13 */
/* @0x2d1e2c vmls.f32 s24, s20, s18 */
/* @0x2d1e30 vstr s29, [r6] */
/* @0x2d1e34 vmla.f32 s25, s23, s17 */
/* @0x2d1e38 vstr s24, [r6, #8] */
/* @0x2d1e3c vmls.f32 s28, s8, s15 */
/* @0x2d1e40 vmla.f32 s27, s9, s13 */
/* @0x2d1e44 vstr s28, [r6, #4] */
/* @0x2d1e48 vstr s25, [r5, #8] */
/* @0x2d1e4c vmla.f32 s26, s9, s15 */
/* @0x2d1e50 vstr s27, [r5] */
/* @0x2d1e54 vcmpe.f32 s10, s7 */
/* @0x2d1e58 vstr s26, [r5, #4] */
/* @0x2d1e5c vmrs APSR_nzcv, fpscr */
/* @0x2d1e60 movhi r0, #0 */
/* @0x2d1e64 bhi 0x2d1e7c <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x200> */
/* @0x2d1e68 vldr s15, [pc, #348] */
/* @0x2d1e6c vcmpe.f32 s30, s15 */
/* @0x2d1e70 vmrs APSR_nzcv, fpscr */
/* @0x2d1e74 movhi r0, #0 */
/* @0x2d1e78 movls r0, #1 */
/* @0x2d1e7c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2d1e80 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2d1e84 vadd.f32 s15, s20, s23 */
/* @0x2d1e88 vcmp.f32 s15, #0 */
/* @0x2d1e8c vmrs APSR_nzcv, fpscr */
/* @0x2d1e90 beq 0x2d1ce0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x64> */
/* @0x2d1e94 vsub.f32 s30, s25, s24 */
/* @0x2d1e98 cmp r3, #3 */
/* @0x2d1e9c vldr s15, [r0, #116] */
/* @0x2d1ea0 vsub.f32 s30, s30, s15 */
/* @0x2d1ea4 beq 0x2d1f08 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x28c> */
/* @0x2d1ea8 cmp r3, #1 */
/* @0x2d1eac beq 0x2d1f40 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x2c4> */
/* @0x2d1eb0 cmp r3, #2 */
/* @0x2d1eb4 beq 0x2d1ecc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x250> */
/* @0x2d1eb8 vldr s15, [pc, #260] */
/* @0x2d1ebc vmov.f32 s30, s15 */
/* @0x2d1ec0 vmls.f32 s24, s15, s20 */
/* @0x2d1ec4 vmla.f32 s25, s15, s23 */
/* @0x2d1ec8 b 0x2d1ce4 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x68> */
/* @0x2d1ecc vldr s15, [r0, #124] */
/* @0x2d1ed0 vsub.f32 s30, s30, s15 */
/* @0x2d1ed4 vldr s14, [pc, #240] */
/* @0x2d1ed8 vldr s15, [pc, #240] */
/* @0x2d1edc vsub.f32 s14, s30, s14 */
/* @0x2d1ee0 vcmpe.f32 s14, s15 */
/* @0x2d1ee4 vmrs APSR_nzcv, fpscr */
/* @0x2d1ee8 bpl 0x2d1efc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x280> */
/* @0x2d1eec vcmpe.f32 s14, #0 */
/* @0x2d1ef0 vmrs APSR_nzcv, fpscr */
/* @0x2d1ef4 bpl 0x2d1f70 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x2f4> */
/* @0x2d1ef8 vldr s15, [pc, #196] */
/* @0x2d1efc vldr s13, [r4, #220] */
/* @0x2d1f00 vnmul.f32 s15, s13, s15 */
/* @0x2d1f04 b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244> */
/* @0x2d1f08 vldr s15, [r0, #120] */
/* @0x2d1f0c vsub.f32 s30, s30, s15 */
/* @0x2d1f10 vldr s14, [pc, #184] */
/* @0x2d1f14 vcmpe.f32 s30, s14 */
/* @0x2d1f18 vmrs APSR_nzcv, fpscr */
/* @0x2d1f1c bpl 0x2d1f78 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x2fc> */
/* @0x2d1f20 vldr s15, [pc, #172] */
/* @0x2d1f24 vcmpe.f32 s30, s15 */
/* @0x2d1f28 vmrs APSR_nzcv, fpscr */
/* @0x2d1f2c bpl 0x2d1fac <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x330> */
/* @0x2d1f30 vmov.f32 s30, s14 */
/* @0x2d1f34 vldr s14, [r0, #220] */
/* @0x2d1f38 vnmul.f32 s15, s14, s15 */
/* @0x2d1f3c b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244> */
/* @0x2d1f40 vldr s15, [r0, #120] */
/* @0x2d1f44 vsub.f32 s30, s30, s15 */
/* @0x2d1f48 vldr s14, [pc, #124] */
/* @0x2d1f4c vadd.f32 s14, s30, s14 */
/* @0x2d1f50 vcmpe.f32 s14, #0 */
/* @0x2d1f54 vneg.f32 s30, s30 */
/* @0x2d1f58 vmrs APSR_nzcv, fpscr */
/* @0x2d1f5c bpl 0x2d1ef8 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x27c> */
/* @0x2d1f60 vldr s15, [pc, #108] */
/* @0x2d1f64 vcmpe.f32 s14, s15 */
/* @0x2d1f68 vmrs APSR_nzcv, fpscr */
/* @0x2d1f6c bmi 0x2d1efc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x280> */
/* @0x2d1f70 vmov.f32 s15, s14 */
/* @0x2d1f74 b 0x2d1efc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x280> */
/* @0x2d1f78 vldr s15, [r0, #220] */
/* @0x2d1f7c vmov.f32 s30, s14 */
/* @0x2d1f80 vnmul.f32 s15, s15, s14 */
/* @0x2d1f84 b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244> */
/* @0x2d1f88 vmov r0, s15 */
/* @0x2d1f8c bl 0xb6700 <sqrtf@plt> */
/* @0x2d1f90 ldr r5, [r8, #0x18] */
/* @0x2d1f94 vldr s20, [r4, #176] */
/* @0x2d1f98 ldr r6, [r4, #0x80] */
/* @0x2d1f9c vldr s23, [r4, #180] */
/* @0x2d1fa0 ldr r7, [r4, #0x84] */
/* @0x2d1fa4 vmov s10, r0 */
/* @0x2d1fa8 b 0x2d1d94 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x118> */
/* @0x2d1fac vcmpe.f32 s30, #0 */
/* @0x2d1fb0 vldr s15, [r0, #220] */
/* @0x2d1fb4 vmrs APSR_nzcv, fpscr */
/* @0x2d1fb8 vnmul.f32 s15, s15, s30 */
/* @0x2d1fbc vnegle.f32 s30, s30 */
/* @0x2d1fc0 b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244> */
/* @0x2d1fc4 andeq r0, r0, r0 */
/* @0x2d1fc8 bllo 0xfebc7bf8 <b2_toiTime+0xfffffffffe46e754> */
/* @0x2d1fcc vstrlo s30, [lr, #-216] */
/* @0x2d1fd0 .word 0x3e0efa36 */
/* @0x2d1fd4 .word 0xbe0efa36 */

/* ── FUNC 0x2d1fd8 · b2RevoluteJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&) · size=140 · insn=35 */
/* @0x2d1fd8 vldr s15, [r1, #16] */
/* @0x2d1fdc vldr s14, [r3, #4] */
/* @0x2d1fe0 vsub.f32 s14, s14, s15 */
/* @0x2d1fe4 vldr s9, [r1, #20] */
/* @0x2d1fe8 vldr s8, [r1, #24] */
/* @0x2d1fec vldr s4, [r3] */
/* @0x2d1ff0 vldr s10, [r1, #12] */
/* @0x2d1ff4 vldr s12, [r2, #20] */
/* @0x2d1ff8 vldr s11, [r2, #24] */
/* @0x2d1ffc vldr s15, [r2, #16] */
/* @0x2d2000 vldr s5, [r2, #12] */
/* @0x2d2004 vldr s6, [r2, #72] */
/* @0x2d2008 vldr s7, [r1, #72] */
/* @0x2d200c str r1, [r0, #0x8] */
/* @0x2d2010 str r2, [r0, #0xc] */
/* @0x2d2014 vmul.f32 s13, s14, s9 */
/* @0x2d2018 vmul.f32 s14, s14, s8 */
/* @0x2d201c vsub.f32 s10, s4, s10 */
/* @0x2d2020 vmla.f32 s13, s10, s8 */
/* @0x2d2024 vmls.f32 s14, s9, s10 */
/* @0x2d2028 vstr s13, [r0, #20] */
/* @0x2d202c vstr s14, [r0, #24] */
/* @0x2d2030 vldr s14, [r3, #4] */
/* @0x2d2034 vsub.f32 s15, s14, s15 */
/* @0x2d2038 vldr s13, [r3] */
/* @0x2d203c vmul.f32 s14, s15, s12 */
/* @0x2d2040 vsub.f32 s13, s13, s5 */
/* @0x2d2044 vmul.f32 s15, s15, s11 */
/* @0x2d2048 vmla.f32 s14, s13, s11 */
/* @0x2d204c vmls.f32 s15, s12, s13 */
/* @0x2d2050 vstr s14, [r0, #28] */
/* @0x2d2054 vsub.f32 s14, s6, s7 */
/* @0x2d2058 vstr s15, [r0, #32] */
/* @0x2d205c vstr s14, [r0, #36] */
/* @0x2d2060 bx lr */

/* ── FUNC 0x2d2064 · b2RevoluteJoint::b2RevoluteJoint(b2RevoluteJointDef const*) · size=160 · insn=40 */
/* @0x2d2064 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d2068 mov r4, r0 */
/* @0x2d206c mov r5, r1 */
/* @0x2d2070 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2d2074 add r3, r5, #20 */
/* @0x2d2078 ldr r2, [pc, #0x80] */
/* @0x2d207c add r12, r5, #28 */
/* @0x2d2080 ldrb r7, [r5, #0x28] */
/* @0x2d2084 ldm r3, {r0, r1} */
/* @0x2d2088 ldr r2, [pc, r2] */
/* @0x2d208c mov r3, r4 */
/* @0x2d2090 ldrb r6, [r5, #0x34] */
/* @0x2d2094 ldr r11, [r5, #0x24] */
/* @0x2d2098 add r2, r2, #8 */
/* @0x2d209c ldr r10, [r5, #0x2c] */
/* @0x2d20a0 str r2, [r3], #68 */
/* @0x2d20a4 add r2, r4, #76 */
/* @0x2d20a8 stm r3, {r0, r1} */
/* @0x2d20ac mov r3, #0 */
/* @0x2d20b0 ldm r12, {r0, r1} */
/* @0x2d20b4 mov r12, #0 */
/* @0x2d20b8 ldr r9, [r5, #0x30] */
/* @0x2d20bc ldr r8, [r5, #0x3c] */
/* @0x2d20c0 ldr r5, [r5, #0x38] */
/* @0x2d20c4 stm r2, {r0, r1} */
/* @0x2d20c8 mov r0, r4 */
/* @0x2d20cc str r11, [r4, #0x74] */
/* @0x2d20d0 str r10, [r4, #0x78] */
/* @0x2d20d4 str r9, [r4, #0x7c] */
/* @0x2d20d8 str r8, [r4, #0x68] */
/* @0x2d20dc str r5, [r4, #0x6c] */
/* @0x2d20e0 strb r7, [r4, #0x70] */
/* @0x2d20e4 strb r6, [r4, #0x64] */
/* @0x2d20e8 str r3, [r4, #0x54] */
/* @0x2d20ec str r12, [r4, #0xe0] */
/* @0x2d20f0 str r3, [r4, #0x58] */
/* @0x2d20f4 str r3, [r4, #0x5c] */
/* @0x2d20f8 str r3, [r4, #0x60] */
/* @0x2d20fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d2100 andseq pc, r1, r8, ror #21 */

/* ── FUNC 0x2d2064 · b2RevoluteJoint::b2RevoluteJoint(b2RevoluteJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d2104 · b2RevoluteJoint::GetJointAngle() const · size=36 · insn=9 */
/* @0x2d2104 ldr r3, [r0, #0x34] */
/* @0x2d2108 vldr s13, [r3, #72] */
/* @0x2d210c ldr r3, [r0, #0x30] */
/* @0x2d2110 vldr s14, [r3, #72] */
/* @0x2d2114 vsub.f32 s14, s13, s14 */
/* @0x2d2118 vldr s15, [r0, #116] */
/* @0x2d211c vsub.f32 s15, s14, s15 */
/* @0x2d2120 vmov r0, s15 */
/* @0x2d2124 bx lr */

/* ── FUNC 0x2d2128 · b2RevoluteJoint::GetJointSpeed() const · size=28 · insn=7 */
/* @0x2d2128 ldr r3, [r0, #0x34] */
/* @0x2d212c vldr s14, [r3, #88] */
/* @0x2d2130 ldr r3, [r0, #0x30] */
/* @0x2d2134 vldr s15, [r3, #88] */
/* @0x2d2138 vsub.f32 s15, s14, s15 */
/* @0x2d213c vmov r0, s15 */
/* @0x2d2140 bx lr */

/* ── FUNC 0x2d2144 · b2RevoluteJoint::IsMotorEnabled() const · size=8 · insn=2 */
/* @0x2d2144 ldrb r0, [r0, #0x64] */
/* @0x2d2148 bx lr */
