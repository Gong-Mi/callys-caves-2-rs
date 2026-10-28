/* libyoyo.so 覆盖卡组 0109
 * 函数 0x16d378..0x16ee64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x16d378 · CCamera::IsViewDirty() · size=8 · insn=2 */
/* @0x16d378 ldrb r0, [r0, #0x1b9] */
/* @0x16d37c bx lr */

/* ── FUNC 0x16d380 · CCamera::IsOrthoProj() · size=24 · insn=6 */
/* @0x16d380 vldr s15, [r0, #48] */
/* @0x16d384 vcmp.f32 s15, #0 */
/* @0x16d388 vmrs APSR_nzcv, fpscr */
/* @0x16d38c movne r0, #0 */
/* @0x16d390 moveq r0, #1 */
/* @0x16d394 bx lr */

/* ── FUNC 0x16d398 · CCamera::Is2D() · size=8 · insn=2 */
/* @0x16d398 ldrb r0, [r0, #0x1b8] */
/* @0x16d39c bx lr */

/* ── FUNC 0x16d3a0 · CCamera::GetCamPos() · size=28 · insn=7 */
/* @0x16d3a0 ldr r2, [r1, #0x138] */
/* @0x16d3a4 ldr r12, [r1, #0x134] */
/* @0x16d3a8 str r2, [r0, #0x4] */
/* @0x16d3ac ldr r2, [r1, #0x13c] */
/* @0x16d3b0 str r12, [r0] */
/* @0x16d3b4 str r2, [r0, #0x8] */
/* @0x16d3b8 bx lr */

/* ── FUNC 0x16d3bc · CCamera::ApplyMatrices() · size=1032 · insn=258 */
/* @0x16d3bc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x16d3c0 vpush {d8, d9} */
/* @0x16d3c4 sub sp, sp, #140 */
/* @0x16d3c8 mov r5, r0 */
/* @0x16d3cc bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv> */
/* @0x16d3d0 ldr r4, [pc, #0x3cc] */
/* @0x16d3d4 add r4, pc, r4 */
/* @0x16d3d8 cmp r0, #0 */
/* @0x16d3dc bne 0x16d520 <_ZN7CCamera13ApplyMatricesEv+0x164> */
/* @0x16d3e0 ldr r0, [pc, #0x3c0] */
/* @0x16d3e4 mov r3, #0 */
/* @0x16d3e8 ldr r1, [pc, #0x3bc] */
/* @0x16d3ec ldr r2, [pc, #0x3bc] */
/* @0x16d3f0 ldr r0, [r4, r0] */
/* @0x16d3f4 str r3, [r0] */
/* @0x16d3f8 ldr r1, [r4, r1] */
/* @0x16d3fc str r3, [r1] */
/* @0x16d400 ldr r3, [r4, r2] */
/* @0x16d404 ldr r3, [r3] */
/* @0x16d408 cmp r3, #0 */
/* @0x16d40c beq 0x16d754 <_ZN7CCamera13ApplyMatricesEv+0x398> */
/* @0x16d410 vldr s14, [r3, #16] */
/* @0x16d414 vldr s15, [r3, #20] */
/* @0x16d418 vcvt.f32.s32 s14, s14 */
/* @0x16d41c ldr r3, [pc, #0x390] */
/* @0x16d420 ldr r3, [r4, r3] */
/* @0x16d424 vcvt.f32.s32 s15, s15 */
/* @0x16d428 vstr s14, [r3] */
/* @0x16d42c ldr r3, [pc, #0x384] */
/* @0x16d430 mov r1, #0 */
/* @0x16d434 ldr r12, [pc, #0x380] */
/* @0x16d438 mov r0, r1 */
/* @0x16d43c vmov r2, s14 */
/* @0x16d440 ldr r3, [r4, r3] */
/* @0x16d444 vstr s15, [r3] */
/* @0x16d448 ldr r12, [r4, r12] */
/* @0x16d44c vmov r3, s15 */
/* @0x16d450 str r1, [sp] */
/* @0x16d454 str r1, [r12] */
/* @0x16d458 bl 0x1692e4 <_Z14SetViewExtentsfffff> */
/* @0x16d45c ldr r3, [pc, #0x35c] */
/* @0x16d460 ldr r3, [r4, r3] */
/* @0x16d464 ldr r3, [r3] */
/* @0x16d468 cmn r3, #1 */
/* @0x16d46c beq 0x16d4f0 <_ZN7CCamera13ApplyMatricesEv+0x134> */
/* @0x16d470 add r4, sp, #8 */
/* @0x16d474 add r1, r5, #4 */
/* @0x16d478 add r2, sp, #72 */
/* @0x16d47c mov r3, #0 */
/* @0x16d480 mov r0, r4 */
/* @0x16d484 mov r12, #1065353216 */
/* @0x16d488 mov lr, #0 */
/* @0x16d48c str r3, [sp, #0x80] */
/* @0x16d490 movt lr, #0xbf80 */
/* @0x16d494 str r3, [sp, #0x7c] */
/* @0x16d498 str r3, [sp, #0x78] */
/* @0x16d49c str r3, [sp, #0x74] */
/* @0x16d4a0 str r3, [sp, #0x6c] */
/* @0x16d4a4 str r3, [sp, #0x68] */
/* @0x16d4a8 str r3, [sp, #0x64] */
/* @0x16d4ac str r12, [sp, #0x84] */
/* @0x16d4b0 str r12, [sp, #0x70] */
/* @0x16d4b4 str r12, [sp, #0x48] */
/* @0x16d4b8 str r3, [sp, #0x60] */
/* @0x16d4bc str r3, [sp, #0x58] */
/* @0x16d4c0 str r3, [sp, #0x54] */
/* @0x16d4c4 str r3, [sp, #0x50] */
/* @0x16d4c8 str r3, [sp, #0x4c] */
/* @0x16d4cc str lr, [sp, #0x5c] */
/* @0x16d4d0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x16d4d4 add r1, r5, #68 */
/* @0x16d4d8 mov r2, r4 */
/* @0x16d4dc mov r0, #0 */
/* @0x16d4e0 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_> */
/* @0x16d4e4 add sp, sp, #140 */
/* @0x16d4e8 vpop {d8, d9} */
/* @0x16d4ec pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x16d4f0 add lr, r5, #4 */
/* @0x16d4f4 add r4, sp, #8 */
/* @0x16d4f8 ldm lr!, {r0, r1, r2, r3} */
/* @0x16d4fc mov r12, r4 */
/* @0x16d500 stm r12!, {r0, r1, r2, r3} */
/* @0x16d504 ldm lr!, {r0, r1, r2, r3} */
/* @0x16d508 stm r12!, {r0, r1, r2, r3} */
/* @0x16d50c ldm lr!, {r0, r1, r2, r3} */
/* @0x16d510 stm r12!, {r0, r1, r2, r3} */
/* @0x16d514 ldm lr, {r0, r1, r2, r3} */
/* @0x16d518 stm r12, {r0, r1, r2, r3} */
/* @0x16d51c b 0x16d4d4 <_ZN7CCamera13ApplyMatricesEv+0x118> */
/* @0x16d520 add r0, sp, #72 */
/* @0x16d524 mov r1, r5 */
/* @0x16d528 bl 0x16d3a0 <_ZN7CCamera9GetCamPosEv> */
/* @0x16d52c vldr s15, [pc, #612] */
/* @0x16d530 vldr s6, [r5, #344] */
/* @0x16d534 vmul.f32 s1, s6, s15 */
/* @0x16d538 vldr s9, [r5, #360] */
/* @0x16d53c vldr s2, [r5, #328] */
/* @0x16d540 vldr s5, [r5, #340] */
/* @0x16d544 vldr s8, [r5, #356] */
/* @0x16d548 vldr s3, [r5, #324] */
/* @0x16d54c vldr s12, [r5, #376] */
/* @0x16d550 vldr s7, [r5, #348] */
/* @0x16d554 vldr s10, [r5, #364] */
/* @0x16d558 vldr s11, [r5, #372] */
/* @0x16d55c vldr s4, [r5, #332] */
/* @0x16d560 vldr s13, [r5, #380] */
/* @0x16d564 vmul.f32 s9, s9, s15 */
/* @0x16d568 vadd.f32 s18, s2, s1 */
/* @0x16d56c vsub.f32 s14, s1, s2 */
/* @0x16d570 vmul.f32 s1, s5, s15 */
/* @0x16d574 vmul.f32 s8, s8, s15 */
/* @0x16d578 vadd.f32 s18, s9, s18 */
/* @0x16d57c vadd.f32 s14, s14, s9 */
/* @0x16d580 vadd.f32 s17, s3, s1 */
/* @0x16d584 vsub.f32 s0, s1, s3 */
/* @0x16d588 vadd.f32 s18, s12, s18 */
/* @0x16d58c vadd.f32 s14, s14, s12 */
/* @0x16d590 vmul.f32 s16, s7, s15 */
/* @0x16d594 vadd.f32 s17, s8, s17 */
/* @0x16d598 vadd.f32 s0, s0, s8 */
/* @0x16d59c vsub.f32 s14, s18, s14 */
/* @0x16d5a0 vmul.f32 s10, s10, s15 */
/* @0x16d5a4 vadd.f32 s17, s11, s17 */
/* @0x16d5a8 vadd.f32 s0, s0, s11 */
/* @0x16d5ac vadd.f32 s1, s4, s16 */
/* @0x16d5b0 vsub.f32 s16, s16, s4 */
/* @0x16d5b4 vmul.f32 s14, s14, s14 */
/* @0x16d5b8 vsub.f32 s0, s17, s0 */
/* @0x16d5bc vadd.f32 s1, s10, s1 */
/* @0x16d5c0 vadd.f32 s16, s16, s10 */
/* @0x16d5c4 vmla.f32 s14, s0, s0 */
/* @0x16d5c8 vadd.f32 s1, s13, s1 */
/* @0x16d5cc vadd.f32 s16, s16, s13 */
/* @0x16d5d0 vmul.f32 s2, s2, s15 */
/* @0x16d5d4 vmul.f32 s3, s3, s15 */
/* @0x16d5d8 vmul.f32 s4, s4, s15 */
/* @0x16d5dc vsub.f32 s1, s1, s16 */
/* @0x16d5e0 vadd.f32 s17, s5, s3 */
/* @0x16d5e4 vadd.f32 s18, s6, s2 */
/* @0x16d5e8 vadd.f32 s19, s7, s4 */
/* @0x16d5ec vsub.f32 s3, s3, s5 */
/* @0x16d5f0 vsub.f32 s2, s2, s6 */
/* @0x16d5f4 vsub.f32 s4, s4, s7 */
/* @0x16d5f8 vmla.f32 s14, s1, s1 */
/* @0x16d5fc vadd.f32 s17, s8, s17 */
/* @0x16d600 vadd.f32 s18, s9, s18 */
/* @0x16d604 vadd.f32 s19, s10, s19 */
/* @0x16d608 vadd.f32 s8, s8, s3 */
/* @0x16d60c vadd.f32 s9, s9, s2 */
/* @0x16d610 vadd.f32 s10, s10, s4 */
/* @0x16d614 vadd.f32 s17, s11, s17 */
/* @0x16d618 vadd.f32 s18, s12, s18 */
/* @0x16d61c vadd.f32 s19, s13, s19 */
/* @0x16d620 vadd.f32 s11, s11, s8 */
/* @0x16d624 vadd.f32 s12, s12, s9 */
/* @0x16d628 vadd.f32 s13, s13, s10 */
/* @0x16d62c vcmpe.f32 s14, s15 */
/* @0x16d630 vsub.f32 s17, s17, s11 */
/* @0x16d634 vmrs APSR_nzcv, fpscr */
/* @0x16d638 vsub.f32 s18, s18, s12 */
/* @0x16d63c vsub.f32 s19, s19, s13 */
/* @0x16d640 ble 0x16d654 <_ZN7CCamera13ApplyMatricesEv+0x298> */
/* @0x16d644 vsqrt.f32 s15, s14 */
/* @0x16d648 vcmp.f32 s15, s15 */
/* @0x16d64c vmrs APSR_nzcv, fpscr */
/* @0x16d650 bne 0x16d76c <_ZN7CCamera13ApplyMatricesEv+0x3b0> */
/* @0x16d654 vmul.f32 s16, s18, s18 */
/* @0x16d658 ldr r3, [pc, #0x154] */
/* @0x16d65c ldr r6, [r4, r3] */
/* @0x16d660 vstr s15, [r6] */
/* @0x16d664 vmla.f32 s16, s17, s17 */
/* @0x16d668 vmla.f32 s16, s19, s19 */
/* @0x16d66c vcmpe.f32 s16, #0 */
/* @0x16d670 vsqrt.f32 s19, s16 */
/* @0x16d674 vmrs APSR_nzcv, fpscr */
/* @0x16d678 ble 0x16d748 <_ZN7CCamera13ApplyMatricesEv+0x38c> */
/* @0x16d67c vmov r0, s19 */
/* @0x16d680 vcmp.f32 s19, s19 */
/* @0x16d684 vmrs APSR_nzcv, fpscr */
/* @0x16d688 bne 0x16d78c <_ZN7CCamera13ApplyMatricesEv+0x3d0> */
/* @0x16d68c vmov.f32 s11, #5.000000e-01 */
/* @0x16d690 vldr s15, [r6] */
/* @0x16d694 vmov s12, r0 */
/* @0x16d698 vmul.f32 s11, s12, s11 */
/* @0x16d69c ldr r1, [pc, #0x114] */
/* @0x16d6a0 vldr s13, [sp, #72] */
/* @0x16d6a4 vldr s10, [sp, #76] */
/* @0x16d6a8 ldr r2, [pc, #0xf8] */
/* @0x16d6ac ldr r3, [pc, #0xf8] */
/* @0x16d6b0 ldr r7, [r4, r1] */
/* @0x16d6b4 vstr s12, [r7] */
/* @0x16d6b8 ldr r9, [r4, r2] */
/* @0x16d6bc vmov.f32 s12, #5.000000e-01 */
/* @0x16d6c0 vmls.f32 s13, s15, s12 */
/* @0x16d6c4 vsub.f32 s11, s10, s11 */
/* @0x16d6c8 vstr s13, [r9] */
/* @0x16d6cc ldr r8, [r4, r3] */
/* @0x16d6d0 vcmp.f32 s19, s19 */
/* @0x16d6d4 vstr s11, [r8] */
/* @0x16d6d8 vmov.f32 s14, s19 */
/* @0x16d6dc vmrs APSR_nzcv, fpscr */
/* @0x16d6e0 bne 0x16d77c <_ZN7CCamera13ApplyMatricesEv+0x3c0> */
/* @0x16d6e4 vmov.f32 s16, #1.000000e+00 */
/* @0x16d6e8 vdiv.f32 s16, s16, s14 */
/* @0x16d6ec vmul.f32 s18, s18, s16 */
/* @0x16d6f0 vmov r0, s18 */
/* @0x16d6f4 bl 0xb6760 <acosf@plt> */
/* @0x16d6f8 vmul.f32 s17, s17, s16 */
/* @0x16d6fc vldr s14, [pc, #152] */
/* @0x16d700 ldr r12, [pc, #0xb4] */
/* @0x16d704 ldr r1, [r8] */
/* @0x16d708 ldr r2, [r6] */
/* @0x16d70c ldr r12, [r4, r12] */
/* @0x16d710 ldr r3, [r7] */
/* @0x16d714 vcmpe.f32 s17, #0 */
/* @0x16d718 vmrs APSR_nzcv, fpscr */
/* @0x16d71c vldrmi s15, [pc, #124] */
/* @0x16d720 vmov s13, r0 */
/* @0x16d724 ldr r0, [r9] */
/* @0x16d728 vsubmi.f32 s13, s15, s13 */
/* @0x16d72c vldr s15, [pc, #108] */
/* @0x16d730 vdiv.f32 s15, s13, s15 */
/* @0x16d734 vmul.f32 s15, s15, s14 */
/* @0x16d738 vstr s15, [sp] */
/* @0x16d73c vstr s15, [r12] */
/* @0x16d740 bl 0x1692e4 <_Z14SetViewExtentsfffff> */
/* @0x16d744 b 0x16d45c <_ZN7CCamera13ApplyMatricesEv+0xa0> */
/* @0x16d748 vldr s11, [pc, #72] */
/* @0x16d74c vmov.f32 s12, s11 */
/* @0x16d750 b 0x16d69c <_ZN7CCamera13ApplyMatricesEv+0x2e0> */
/* @0x16d754 vmov.f32 s15, #1.000000e+00 */
/* @0x16d758 ldr r3, [pc, #0x54] */
/* @0x16d75c ldr r3, [r4, r3] */
/* @0x16d760 vmov.f32 s14, s15 */
/* @0x16d764 vstr s15, [r3] */
/* @0x16d768 b 0x16d42c <_ZN7CCamera13ApplyMatricesEv+0x70> */
/* @0x16d76c vmov r0, s14 */
/* @0x16d770 bl 0xb6700 <sqrtf@plt> */
/* @0x16d774 vmov s15, r0 */
/* @0x16d778 b 0x16d654 <_ZN7CCamera13ApplyMatricesEv+0x298> */
/* @0x16d77c vmov r0, s16 */
/* @0x16d780 bl 0xb6700 <sqrtf@plt> */
/* @0x16d784 vmov s14, r0 */
/* @0x16d788 b 0x16d6e4 <_ZN7CCamera13ApplyMatricesEv+0x328> */
/* @0x16d78c vmov r0, s16 */
/* @0x16d790 bl 0xb6700 <sqrtf@plt> */
/* @0x16d794 b 0x16d68c <_ZN7CCamera13ApplyMatricesEv+0x2d0> */
/* @0x16d798 andeq r0, r0, r0 */
/* @0x16d79c .word 0x43b40000 */
/* @0x16d7a0 ldrdmi r0, r1, [r9], #251 */
/* @0x16d7a4 eoreq r4, r8, r12, ror r8 */
/* @0x16d7a8 .word 0xffffe504 */
/* @0x16d7ac .word 0xffffe508 */
/* @0x16d7b0 .word 0xffffbcd8 */
/* @0x16d7b4 .word 0xffffe50c */
/* @0x16d7b8 .word 0xffffe510 */
/* @0x16d7bc .word 0xffffe514 */
/* @0x16d7c0 .word 0xffffe48c */

/* ── FUNC 0x16d7c4 · CCamera::GetCamDir() · size=128 · insn=32 */
/* @0x16d7c4 vldr s12, [r1, #92] */
/* @0x16d7c8 vmul.f32 s15, s12, s12 */
/* @0x16d7cc vldr s13, [r1, #76] */
/* @0x16d7d0 vldr s14, [r1, #108] */
/* @0x16d7d4 push {r4, lr} */
/* @0x16d7d8 vstr s14, [r0, #8] */
/* @0x16d7dc mov r4, r0 */
/* @0x16d7e0 vstr s12, [r0, #4] */
/* @0x16d7e4 vstr s13, [r0] */
/* @0x16d7e8 vmla.f32 s15, s13, s13 */
/* @0x16d7ec vmla.f32 s15, s14, s14 */
/* @0x16d7f0 vsqrt.f32 s14, s15 */
/* @0x16d7f4 vcmp.f32 s14, s14 */
/* @0x16d7f8 vmrs APSR_nzcv, fpscr */
/* @0x16d7fc bne 0x16d834 <_ZN7CCamera9GetCamDirEv+0x70> */
/* @0x16d800 vmov.f32 s11, #1.000000e+00 */
/* @0x16d804 vldr s12, [r4] */
/* @0x16d808 vldr s15, [r4, #4] */
/* @0x16d80c vldr s13, [r4, #8] */
/* @0x16d810 mov r0, r4 */
/* @0x16d814 vdiv.f32 s14, s11, s14 */
/* @0x16d818 vmul.f32 s12, s12, s14 */
/* @0x16d81c vmul.f32 s15, s15, s14 */
/* @0x16d820 vstr s12, [r4] */
/* @0x16d824 vmul.f32 s14, s13, s14 */
/* @0x16d828 vstr s15, [r4, #4] */
/* @0x16d82c vstr s14, [r4, #8] */
/* @0x16d830 pop {r4, pc} */
/* @0x16d834 vmov r0, s15 */
/* @0x16d838 bl 0xb6700 <sqrtf@plt> */
/* @0x16d83c vmov s14, r0 */
/* @0x16d840 b 0x16d800 <_ZN7CCamera9GetCamDirEv+0x3c> */

/* ── FUNC 0x16d844 · CCamera::GetCamUp() · size=128 · insn=32 */
/* @0x16d844 vldr s12, [r1, #88] */
/* @0x16d848 vmul.f32 s15, s12, s12 */
/* @0x16d84c vldr s13, [r1, #72] */
/* @0x16d850 vldr s14, [r1, #104] */
/* @0x16d854 push {r4, lr} */
/* @0x16d858 vstr s14, [r0, #8] */
/* @0x16d85c mov r4, r0 */
/* @0x16d860 vstr s12, [r0, #4] */
/* @0x16d864 vstr s13, [r0] */
/* @0x16d868 vmla.f32 s15, s13, s13 */
/* @0x16d86c vmla.f32 s15, s14, s14 */
/* @0x16d870 vsqrt.f32 s14, s15 */
/* @0x16d874 vcmp.f32 s14, s14 */
/* @0x16d878 vmrs APSR_nzcv, fpscr */
/* @0x16d87c bne 0x16d8b4 <_ZN7CCamera8GetCamUpEv+0x70> */
/* @0x16d880 vmov.f32 s11, #1.000000e+00 */
/* @0x16d884 vldr s12, [r4] */
/* @0x16d888 vldr s15, [r4, #4] */
/* @0x16d88c vldr s13, [r4, #8] */
/* @0x16d890 mov r0, r4 */
/* @0x16d894 vdiv.f32 s14, s11, s14 */
/* @0x16d898 vmul.f32 s12, s12, s14 */
/* @0x16d89c vmul.f32 s15, s15, s14 */
/* @0x16d8a0 vstr s12, [r4] */
/* @0x16d8a4 vmul.f32 s14, s13, s14 */
/* @0x16d8a8 vstr s15, [r4, #4] */
/* @0x16d8ac vstr s14, [r4, #8] */
/* @0x16d8b0 pop {r4, pc} */
/* @0x16d8b4 vmov r0, s15 */
/* @0x16d8b8 bl 0xb6700 <sqrtf@plt> */
/* @0x16d8bc vmov s14, r0 */
/* @0x16d8c0 b 0x16d880 <_ZN7CCamera8GetCamUpEv+0x3c> */

/* ── FUNC 0x16d8c4 · CCamera::GetCamRight() · size=120 · insn=30 */
/* @0x16d8c4 vldr s15, [r1, #100] */
/* @0x16d8c8 vmul.f32 s14, s15, s15 */
/* @0x16d8cc push {r4, lr} */
/* @0x16d8d0 vstr s15, [r0] */
/* @0x16d8d4 vstr s15, [r0, #4] */
/* @0x16d8d8 vstr s15, [r0, #8] */
/* @0x16d8dc mov r4, r0 */
/* @0x16d8e0 vadd.f32 s15, s14, s14 */
/* @0x16d8e4 vadd.f32 s14, s14, s15 */
/* @0x16d8e8 vsqrt.f32 s15, s14 */
/* @0x16d8ec vcmp.f32 s15, s15 */
/* @0x16d8f0 vmrs APSR_nzcv, fpscr */
/* @0x16d8f4 bne 0x16d92c <_ZN7CCamera11GetCamRightEv+0x68> */
/* @0x16d8f8 vmov.f32 s11, #1.000000e+00 */
/* @0x16d8fc vldr s12, [r4] */
/* @0x16d900 vldr s14, [r4, #4] */
/* @0x16d904 vldr s13, [r4, #8] */
/* @0x16d908 mov r0, r4 */
/* @0x16d90c vdiv.f32 s15, s11, s15 */
/* @0x16d910 vmul.f32 s12, s12, s15 */
/* @0x16d914 vmul.f32 s14, s14, s15 */
/* @0x16d918 vstr s12, [r4] */
/* @0x16d91c vmul.f32 s15, s13, s15 */
/* @0x16d920 vstr s14, [r4, #4] */
/* @0x16d924 vstr s15, [r4, #8] */
/* @0x16d928 pop {r4, pc} */
/* @0x16d92c vmov r0, s14 */
/* @0x16d930 bl 0xb6700 <sqrtf@plt> */
/* @0x16d934 vmov s15, r0 */
/* @0x16d938 b 0x16d8f8 <_ZN7CCamera11GetCamRightEv+0x34> */

/* ── FUNC 0x16d93c · CCamera::Update2D() · size=168 · insn=42 */
/* @0x16d93c push {r4, lr} */
/* @0x16d940 mov r4, r0 */
/* @0x16d944 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv> */
/* @0x16d948 cmp r0, #0 */
/* @0x16d94c beq 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d950 vldr s15, [r4, #20] */
/* @0x16d954 vcmp.f32 s15, #0 */
/* @0x16d958 vmrs APSR_nzcv, fpscr */
/* @0x16d95c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d960 vldr s15, [r4, #36] */
/* @0x16d964 vcmp.f32 s15, #0 */
/* @0x16d968 vmrs APSR_nzcv, fpscr */
/* @0x16d96c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d970 vldr s15, [r4, #8] */
/* @0x16d974 vcmp.f32 s15, #0 */
/* @0x16d978 vmrs APSR_nzcv, fpscr */
/* @0x16d97c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d980 vldr s15, [r4, #40] */
/* @0x16d984 vcmp.f32 s15, #0 */
/* @0x16d988 vmrs APSR_nzcv, fpscr */
/* @0x16d98c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d990 vldr s15, [r4, #12] */
/* @0x16d994 vcmp.f32 s15, #0 */
/* @0x16d998 vmrs APSR_nzcv, fpscr */
/* @0x16d99c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d9a0 vldr s15, [r4, #28] */
/* @0x16d9a4 vcmp.f32 s15, #0 */
/* @0x16d9a8 vmrs APSR_nzcv, fpscr */
/* @0x16d9ac bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d9b0 vldr s15, [r4, #76] */
/* @0x16d9b4 vcmp.f32 s15, #0 */
/* @0x16d9b8 vmrs APSR_nzcv, fpscr */
/* @0x16d9bc bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c> */
/* @0x16d9c0 vldr s15, [r4, #92] */
/* @0x16d9c4 vcmp.f32 s15, #0 */
/* @0x16d9c8 vmrs APSR_nzcv, fpscr */
/* @0x16d9cc moveq r3, #1 */
/* @0x16d9d0 strbeq r3, [r4, #0x1b8] */
/* @0x16d9d4 popeq {r4, pc} */
/* @0x16d9d8 mov r3, #0 */
/* @0x16d9dc strb r3, [r4, #0x1b8] */
/* @0x16d9e0 pop {r4, pc} */

/* ── FUNC 0x16d9e4 · CCamera::SetProjMat(yyMatrix&) · size=176 · insn=44 */
/* @0x16d9e4 push {r4, r5, r6, r7, r8, lr} */
/* @0x16d9e8 mov r6, r1 */
/* @0x16d9ec mov r7, r0 */
/* @0x16d9f0 add r5, r7, #4 */
/* @0x16d9f4 ldm r6!, {r0, r1, r2, r3} */
/* @0x16d9f8 mov r4, r5 */
/* @0x16d9fc add r12, r7, #196 */
/* @0x16da00 add r8, r7, #132 */
/* @0x16da04 stm r5!, {r0, r1, r2, r3} */
/* @0x16da08 ldm r6!, {r0, r1, r2, r3} */
/* @0x16da0c stm r5!, {r0, r1, r2, r3} */
/* @0x16da10 ldm r6!, {r0, r1, r2, r3} */
/* @0x16da14 stm r5!, {r0, r1, r2, r3} */
/* @0x16da18 ldm r6, {r0, r1, r2, r3} */
/* @0x16da1c stm r5, {r0, r1, r2, r3} */
/* @0x16da20 ldm r4!, {r0, r1, r2, r3} */
/* @0x16da24 stm r12!, {r0, r1, r2, r3} */
/* @0x16da28 ldm r4!, {r0, r1, r2, r3} */
/* @0x16da2c stm r12!, {r0, r1, r2, r3} */
/* @0x16da30 ldm r4!, {r0, r1, r2, r3} */
/* @0x16da34 stm r12!, {r0, r1, r2, r3} */
/* @0x16da38 ldm r4, {r0, r1, r2, r3} */
/* @0x16da3c stm r12, {r0, r1, r2, r3} */
/* @0x16da40 add r0, r7, #196 */
/* @0x16da44 bl 0x16c65c <_ZN8yyMatrix6InvertEv> */
/* @0x16da48 mov r0, r8 */
/* @0x16da4c add r1, r7, #68 */
/* @0x16da50 add r2, r7, #4 */
/* @0x16da54 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x16da58 mov lr, r8 */
/* @0x16da5c ldm lr!, {r0, r1, r2, r3} */
/* @0x16da60 add r12, r7, #324 */
/* @0x16da64 stm r12!, {r0, r1, r2, r3} */
/* @0x16da68 ldm lr!, {r0, r1, r2, r3} */
/* @0x16da6c stm r12!, {r0, r1, r2, r3} */
/* @0x16da70 ldm lr!, {r0, r1, r2, r3} */
/* @0x16da74 stm r12!, {r0, r1, r2, r3} */
/* @0x16da78 ldm lr, {r0, r1, r2, r3} */
/* @0x16da7c stm r12, {r0, r1, r2, r3} */
/* @0x16da80 add r0, r7, #324 */
/* @0x16da84 bl 0x16c65c <_ZN8yyMatrix6InvertEv> */
/* @0x16da88 mov r0, r7 */
/* @0x16da8c pop {r4, r5, r6, r7, r8, lr} */
/* @0x16da90 b 0x16d93c <_ZN7CCamera8Update2DEv> */

/* ── FUNC 0x16da94 · CCamera::SetViewMat(yyMatrix&) · size=176 · insn=44 */
/* @0x16da94 push {r4, r5, r6, r7, r8, lr} */
/* @0x16da98 mov r6, r1 */
/* @0x16da9c mov r7, r0 */
/* @0x16daa0 add r5, r7, #68 */
/* @0x16daa4 ldm r6!, {r0, r1, r2, r3} */
/* @0x16daa8 mov r4, r5 */
/* @0x16daac add r12, r7, #260 */
/* @0x16dab0 add r8, r7, #132 */
/* @0x16dab4 stm r5!, {r0, r1, r2, r3} */
/* @0x16dab8 ldm r6!, {r0, r1, r2, r3} */
/* @0x16dabc stm r5!, {r0, r1, r2, r3} */
/* @0x16dac0 ldm r6!, {r0, r1, r2, r3} */
/* @0x16dac4 stm r5!, {r0, r1, r2, r3} */
/* @0x16dac8 ldm r6, {r0, r1, r2, r3} */
/* @0x16dacc stm r5, {r0, r1, r2, r3} */
/* @0x16dad0 ldm r4!, {r0, r1, r2, r3} */
/* @0x16dad4 stm r12!, {r0, r1, r2, r3} */
/* @0x16dad8 ldm r4!, {r0, r1, r2, r3} */
/* @0x16dadc stm r12!, {r0, r1, r2, r3} */
/* @0x16dae0 ldm r4!, {r0, r1, r2, r3} */
/* @0x16dae4 stm r12!, {r0, r1, r2, r3} */
/* @0x16dae8 ldm r4, {r0, r1, r2, r3} */
/* @0x16daec stm r12, {r0, r1, r2, r3} */
/* @0x16daf0 add r0, r7, #260 */
/* @0x16daf4 bl 0x16c65c <_ZN8yyMatrix6InvertEv> */
/* @0x16daf8 mov r0, r8 */
/* @0x16dafc add r1, r7, #68 */
/* @0x16db00 add r2, r7, #4 */
/* @0x16db04 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x16db08 mov lr, r8 */
/* @0x16db0c ldm lr!, {r0, r1, r2, r3} */
/* @0x16db10 add r12, r7, #324 */
/* @0x16db14 stm r12!, {r0, r1, r2, r3} */
/* @0x16db18 ldm lr!, {r0, r1, r2, r3} */
/* @0x16db1c stm r12!, {r0, r1, r2, r3} */
/* @0x16db20 ldm lr!, {r0, r1, r2, r3} */
/* @0x16db24 stm r12!, {r0, r1, r2, r3} */
/* @0x16db28 ldm lr, {r0, r1, r2, r3} */
/* @0x16db2c stm r12, {r0, r1, r2, r3} */
/* @0x16db30 add r0, r7, #324 */
/* @0x16db34 bl 0x16c65c <_ZN8yyMatrix6InvertEv> */
/* @0x16db38 mov r0, r7 */
/* @0x16db3c pop {r4, r5, r6, r7, r8, lr} */
/* @0x16db40 b 0x16d93c <_ZN7CCamera8Update2DEv> */

/* ── FUNC 0x16db44 · CCamera::Build2DView(float, float) · size=200 · insn=50 */
/* @0x16db44 push {r4, r5, r6, lr} */
/* @0x16db48 vpush {d8} */
/* @0x16db4c vldr s17, [r0, #420] */
/* @0x16db50 vldr s16, [pc, #176] */
/* @0x16db54 vnmul.f32 s15, s17, s16 */
/* @0x16db58 sub sp, sp, #176 */
/* @0x16db5c mov r4, r0 */
/* @0x16db60 mov r5, #0 */
/* @0x16db64 str r1, [sp, #0xc] */
/* @0x16db68 mov r3, #0 */
/* @0x16db6c str r1, [sp, #0x18] */
/* @0x16db70 movt r3, #0xc67a */
/* @0x16db74 str r2, [sp, #0x10] */
/* @0x16db78 str r2, [sp, #0x1c] */
/* @0x16db7c str r3, [sp, #0x14] */
/* @0x16db80 str r5, [sp, #0x20] */
/* @0x16db84 vmov r0, s15 */
/* @0x16db88 bl 0xb6580 <sinf@plt> */
/* @0x16db8c vmul.f32 s16, s17, s16 */
/* @0x16db90 mov r6, r0 */
/* @0x16db94 vmov r0, s16 */
/* @0x16db98 bl 0xb658c <cosf@plt> */
/* @0x16db9c str r6, [sp, #0x24] */
/* @0x16dba0 add r6, sp, #48 */
/* @0x16dba4 str r5, [sp, #0x2c] */
/* @0x16dba8 add r5, sp, #112 */
/* @0x16dbac add r1, sp, #12 */
/* @0x16dbb0 add r2, sp, #24 */
/* @0x16dbb4 add r3, sp, #36 */
/* @0x16dbb8 str r0, [sp, #0x28] */
/* @0x16dbbc mov r0, r6 */
/* @0x16dbc0 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x16dbc4 ldr r2, [r4, #0x190] */
/* @0x16dbc8 ldr r1, [r4, #0x18c] */
/* @0x16dbcc mov r3, #1065353216 */
/* @0x16dbd0 mov r0, r5 */
/* @0x16dbd4 mov r12, #0 */
/* @0x16dbd8 movt r12, #0x46fa */
/* @0x16dbdc str r12, [sp] */
/* @0x16dbe0 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x16dbe4 mov r0, r4 */
/* @0x16dbe8 mov r1, r6 */
/* @0x16dbec bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix> */
/* @0x16dbf0 mov r0, r4 */
/* @0x16dbf4 mov r1, r5 */
/* @0x16dbf8 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix> */
/* @0x16dbfc add sp, sp, #176 */
/* @0x16dc00 vpop {d8} */
/* @0x16dc04 pop {r4, r5, r6, pc} */
/* @0x16dc08 vstmialo lr, {s30, s31} */

/* ── FUNC 0x16dc0c · CCamera::Build3DView(float, float) · size=216 · insn=54 */
/* @0x16dc0c push {r4, r5, r6, lr} */
/* @0x16dc10 vpush {d8} */
/* @0x16dc14 vldr s17, [r0, #420] */
/* @0x16dc18 vldr s16, [pc, #192] */
/* @0x16dc1c vnmul.f32 s14, s17, s16 */
/* @0x16dc20 vldr s15, [r0, #396] */
/* @0x16dc24 sub sp, sp, #176 */
/* @0x16dc28 mov r4, r0 */
/* @0x16dc2c mov r5, #0 */
/* @0x16dc30 str r1, [sp, #0xc] */
/* @0x16dc34 str r1, [sp, #0x18] */
/* @0x16dc38 str r2, [sp, #0x10] */
/* @0x16dc3c str r2, [sp, #0x1c] */
/* @0x16dc40 str r5, [sp, #0x20] */
/* @0x16dc44 vneg.f32 s15, s15 */
/* @0x16dc48 vmov r0, s14 */
/* @0x16dc4c vstr s15, [sp, #20] */
/* @0x16dc50 bl 0xb6580 <sinf@plt> */
/* @0x16dc54 vmul.f32 s16, s17, s16 */
/* @0x16dc58 mov r6, r0 */
/* @0x16dc5c vmov r0, s16 */
/* @0x16dc60 bl 0xb658c <cosf@plt> */
/* @0x16dc64 str r6, [sp, #0x24] */
/* @0x16dc68 add r6, sp, #48 */
/* @0x16dc6c add r1, sp, #12 */
/* @0x16dc70 add r2, sp, #24 */
/* @0x16dc74 add r3, sp, #36 */
/* @0x16dc78 str r5, [sp, #0x2c] */
/* @0x16dc7c add r5, sp, #112 */
/* @0x16dc80 str r0, [sp, #0x28] */
/* @0x16dc84 mov r0, r6 */
/* @0x16dc88 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x16dc8c vldr s14, [r4, #400] */
/* @0x16dc90 vneg.f32 s14, s14 */
/* @0x16dc94 vldr s15, [r4, #396] */
/* @0x16dc98 mov r1, #1065353216 */
/* @0x16dc9c mov r0, r5 */
/* @0x16dca0 mov r3, #0 */
/* @0x16dca4 movt r3, #0x46fa */
/* @0x16dca8 str r3, [sp] */
/* @0x16dcac mov r3, r1 */
/* @0x16dcb0 vdiv.f32 s15, s14, s15 */
/* @0x16dcb4 vmov r2, s15 */
/* @0x16dcb8 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff> */
/* @0x16dcbc mov r0, r4 */
/* @0x16dcc0 mov r1, r6 */
/* @0x16dcc4 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix> */
/* @0x16dcc8 mov r0, r4 */
/* @0x16dccc mov r1, r5 */
/* @0x16dcd0 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix> */
/* @0x16dcd4 add sp, sp, #176 */
/* @0x16dcd8 vpop {d8} */
/* @0x16dcdc pop {r4, r5, r6, pc} */
/* @0x16dce0 vstmialo lr, {s30, s31} */

/* ── FUNC 0x16dce4 · CCameraManager::CCameraManager() · size=80 · insn=20 */
/* @0x16dce4 ldr r1, [pc, #0x44] */
/* @0x16dce8 mov r2, #1072 */
/* @0x16dcec push {r3, r4, r5, lr} */
/* @0x16dcf0 mov r4, r0 */
/* @0x16dcf4 mov r5, #0 */
/* @0x16dcf8 mov r3, #1 */
/* @0x16dcfc str r5, [r4] */
/* @0x16dd00 add r1, pc, r1 */
/* @0x16dd04 str r5, [r4, #0x4] */
/* @0x16dd08 mov r0, #4 */
/* @0x16dd0c str r5, [r4, #0x8] */
/* @0x16dd10 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16dd14 mov r3, #1 */
/* @0x16dd18 str r5, [r4, #0x14] */
/* @0x16dd1c str r5, [r4, #0x18] */
/* @0x16dd20 str r3, [r4, #0x10] */
/* @0x16dd24 str r0, [r4, #0xc] */
/* @0x16dd28 mov r0, r4 */
/* @0x16dd2c pop {r3, r4, r5, pc} */
/* @0x16dd30 andseq r12, sp, r8, asr r11 */

/* ── FUNC 0x16dce4 · CCameraManager::CCameraManager() · alias of the symbol above · insn=0 */

/* ── FUNC 0x16dd34 · CCameraManager::Clean() · size=92 · insn=23 */
/* @0x16dd34 push {r3, r4, r5, lr} */
/* @0x16dd38 mov r5, r0 */
/* @0x16dd3c ldr r3, [r0, #0x14] */
/* @0x16dd40 cmp r3, #0 */
/* @0x16dd44 movgt r4, #0 */
/* @0x16dd48 ble 0x16dd74 <_ZN14CCameraManager5CleanEv+0x40> */
/* @0x16dd4c ldr r3, [r5, #0xc] */
/* @0x16dd50 ldr r0, [r3, r4, lsl #2] */
/* @0x16dd54 bl 0x16d120 <_ZN7CCameraD2Ev> */
/* @0x16dd58 ldr r3, [r5, #0xc] */
/* @0x16dd5c ldr r0, [r3, r4, lsl #2] */
/* @0x16dd60 add r4, r4, #1 */
/* @0x16dd64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x16dd68 ldr r3, [r5, #0x14] */
/* @0x16dd6c cmp r3, r4 */
/* @0x16dd70 bgt 0x16dd4c <_ZN14CCameraManager5CleanEv+0x18> */
/* @0x16dd74 mov r3, #0 */
/* @0x16dd78 str r3, [r5] */
/* @0x16dd7c str r3, [r5, #0x4] */
/* @0x16dd80 str r3, [r5, #0x8] */
/* @0x16dd84 str r3, [r5, #0x14] */
/* @0x16dd88 str r3, [r5, #0x18] */
/* @0x16dd8c pop {r3, r4, r5, pc} */

/* ── FUNC 0x16dd90 · CCameraManager::~CCameraManager() · size=28 · insn=7 */
/* @0x16dd90 push {r4, lr} */
/* @0x16dd94 mov r4, r0 */
/* @0x16dd98 bl 0x16dd34 <_ZN14CCameraManager5CleanEv> */
/* @0x16dd9c ldr r0, [r4, #0xc] */
/* @0x16dda0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x16dda4 mov r0, r4 */
/* @0x16dda8 pop {r4, pc} */

/* ── FUNC 0x16dd90 · CCameraManager::~CCameraManager() · alias of the symbol above · insn=0 */

/* ── FUNC 0x16ddac · CCameraManager::SetupGMLFunctions() · size=1712 · insn=428 */
/* @0x16ddac push {r4, lr} */
/* @0x16ddb0 mov r2, #0 */
/* @0x16ddb4 ldr r4, [pc, #0x524] */
/* @0x16ddb8 mov r3, #1 */
/* @0x16ddbc ldr r1, [pc, #0x520] */
/* @0x16ddc0 add r4, pc, r4 */
/* @0x16ddc4 ldr r0, [pc, #0x51c] */
/* @0x16ddc8 ldr r1, [r4, r1] */
/* @0x16ddcc add r0, pc, r0 */
/* @0x16ddd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16ddd4 ldr r1, [pc, #0x510] */
/* @0x16ddd8 ldr r0, [pc, #0x510] */
/* @0x16dddc mov r2, #4 */
/* @0x16dde0 mov r3, #1 */
/* @0x16dde4 ldr r1, [r4, r1] */
/* @0x16dde8 add r0, pc, r0 */
/* @0x16ddec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16ddf0 ldr r1, [pc, #0x4fc] */
/* @0x16ddf4 ldr r0, [pc, #0x4fc] */
/* @0x16ddf8 mov r2, #1 */
/* @0x16ddfc mov r3, r2 */
/* @0x16de00 ldr r1, [r4, r1] */
/* @0x16de04 add r0, pc, r0 */
/* @0x16de08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16de0c ldr r1, [pc, #0x4e8] */
/* @0x16de10 ldr r0, [pc, #0x4e8] */
/* @0x16de14 mov r2, #1 */
/* @0x16de18 mov r3, r2 */
/* @0x16de1c ldr r1, [r4, r1] */
/* @0x16de20 add r0, pc, r0 */
/* @0x16de24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16de28 ldr r1, [pc, #0x4d4] */
/* @0x16de2c ldr r0, [pc, #0x4d4] */
/* @0x16de30 mov r2, #0 */
/* @0x16de34 mov r3, #1 */
/* @0x16de38 ldr r1, [r4, r1] */
/* @0x16de3c add r0, pc, r0 */
/* @0x16de40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16de44 ldr r1, [pc, #0x4c0] */
/* @0x16de48 ldr r0, [pc, #0x4c0] */
/* @0x16de4c mov r2, #0 */
/* @0x16de50 mov r3, #1 */
/* @0x16de54 ldr r1, [r4, r1] */
/* @0x16de58 add r0, pc, r0 */
/* @0x16de5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16de60 ldr r1, [pc, #0x4ac] */
/* @0x16de64 ldr r0, [pc, #0x4ac] */
/* @0x16de68 mov r2, #1 */
/* @0x16de6c mov r3, r2 */
/* @0x16de70 ldr r1, [r4, r1] */
/* @0x16de74 add r0, pc, r0 */
/* @0x16de78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16de7c ldr r1, [pc, #0x498] */
/* @0x16de80 ldr r0, [pc, #0x498] */
/* @0x16de84 mov r2, #2 */
/* @0x16de88 mov r3, #1 */
/* @0x16de8c ldr r1, [r4, r1] */
/* @0x16de90 add r0, pc, r0 */
/* @0x16de94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16de98 ldr r1, [pc, #0x484] */
/* @0x16de9c ldr r0, [pc, #0x484] */
/* @0x16dea0 mov r2, #2 */
/* @0x16dea4 mov r3, #1 */
/* @0x16dea8 ldr r1, [r4, r1] */
/* @0x16deac add r0, pc, r0 */
/* @0x16deb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16deb4 ldr r1, [pc, #0x470] */
/* @0x16deb8 ldr r0, [pc, #0x470] */
/* @0x16debc mov r2, #2 */
/* @0x16dec0 mov r3, #1 */
/* @0x16dec4 ldr r1, [r4, r1] */
/* @0x16dec8 add r0, pc, r0 */
/* @0x16decc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16ded0 ldr r1, [pc, #0x45c] */
/* @0x16ded4 ldr r0, [pc, #0x45c] */
/* @0x16ded8 mov r2, #2 */
/* @0x16dedc mov r3, #1 */
/* @0x16dee0 ldr r1, [r4, r1] */
/* @0x16dee4 add r0, pc, r0 */
/* @0x16dee8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16deec ldr r1, [pc, #0x448] */
/* @0x16def0 ldr r0, [pc, #0x448] */
/* @0x16def4 mov r2, #2 */
/* @0x16def8 mov r3, #1 */
/* @0x16defc ldr r1, [r4, r1] */
/* @0x16df00 add r0, pc, r0 */
/* @0x16df04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16df08 ldr r1, [pc, #0x434] */
/* @0x16df0c ldr r0, [pc, #0x434] */
/* @0x16df10 mov r2, #3 */
/* @0x16df14 mov r3, #1 */
/* @0x16df18 ldr r1, [r4, r1] */
/* @0x16df1c add r0, pc, r0 */
/* @0x16df20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16df24 ldr r1, [pc, #0x420] */
/* @0x16df28 ldr r0, [pc, #0x420] */
/* @0x16df2c mov r2, #3 */
/* @0x16df30 mov r3, #1 */
/* @0x16df34 ldr r1, [r4, r1] */
/* @0x16df38 add r0, pc, r0 */
/* @0x16df3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16df40 ldr r1, [pc, #0x40c] */
/* @0x16df44 ldr r0, [pc, #0x40c] */
/* @0x16df48 mov r2, #3 */
/* @0x16df4c mov r3, #1 */
/* @0x16df50 ldr r1, [r4, r1] */
/* @0x16df54 add r0, pc, r0 */
/* @0x16df58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16df5c ldr r1, [pc, #0x3f8] */
/* @0x16df60 ldr r0, [pc, #0x3f8] */
/* @0x16df64 mov r2, #3 */
/* @0x16df68 mov r3, #1 */
/* @0x16df6c ldr r1, [r4, r1] */
/* @0x16df70 add r0, pc, r0 */
/* @0x16df74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16df78 ldr r1, [pc, #0x3e4] */
/* @0x16df7c ldr r0, [pc, #0x3e4] */
/* @0x16df80 mov r2, #2 */
/* @0x16df84 mov r3, #1 */
/* @0x16df88 ldr r1, [r4, r1] */
/* @0x16df8c add r0, pc, r0 */
/* @0x16df90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16df94 ldr r1, [pc, #0x3d0] */
/* @0x16df98 ldr r0, [pc, #0x3d0] */
/* @0x16df9c mov r2, #2 */
/* @0x16dfa0 mov r3, #1 */
/* @0x16dfa4 ldr r1, [r4, r1] */
/* @0x16dfa8 add r0, pc, r0 */
/* @0x16dfac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16dfb0 ldr r1, [pc, #0x3bc] */
/* @0x16dfb4 ldr r0, [pc, #0x3bc] */
/* @0x16dfb8 mov r2, #1 */
/* @0x16dfbc mov r3, r2 */
/* @0x16dfc0 ldr r1, [r4, r1] */
/* @0x16dfc4 add r0, pc, r0 */
/* @0x16dfc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16dfcc ldr r1, [pc, #0x3a8] */
/* @0x16dfd0 ldr r0, [pc, #0x3a8] */
/* @0x16dfd4 mov r2, #1 */
/* @0x16dfd8 mov r3, r2 */
/* @0x16dfdc ldr r1, [r4, r1] */
/* @0x16dfe0 add r0, pc, r0 */
/* @0x16dfe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16dfe8 ldr r1, [pc, #0x394] */
/* @0x16dfec ldr r0, [pc, #0x394] */
/* @0x16dff0 mov r2, #1 */
/* @0x16dff4 mov r3, r2 */
/* @0x16dff8 ldr r1, [r4, r1] */
/* @0x16dffc add r0, pc, r0 */
/* @0x16e000 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e004 ldr r1, [pc, #0x380] */
/* @0x16e008 ldr r0, [pc, #0x380] */
/* @0x16e00c mov r2, #1 */
/* @0x16e010 mov r3, r2 */
/* @0x16e014 ldr r1, [r4, r1] */
/* @0x16e018 add r0, pc, r0 */
/* @0x16e01c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e020 ldr r1, [pc, #0x36c] */
/* @0x16e024 ldr r0, [pc, #0x36c] */
/* @0x16e028 mov r2, #1 */
/* @0x16e02c mov r3, r2 */
/* @0x16e030 ldr r1, [r4, r1] */
/* @0x16e034 add r0, pc, r0 */
/* @0x16e038 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e03c ldr r1, [pc, #0x358] */
/* @0x16e040 ldr r0, [pc, #0x358] */
/* @0x16e044 mov r2, #1 */
/* @0x16e048 mov r3, r2 */
/* @0x16e04c ldr r1, [r4, r1] */
/* @0x16e050 add r0, pc, r0 */
/* @0x16e054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e058 ldr r1, [pc, #0x344] */
/* @0x16e05c ldr r0, [pc, #0x344] */
/* @0x16e060 mov r2, #1 */
/* @0x16e064 mov r3, r2 */
/* @0x16e068 ldr r1, [r4, r1] */
/* @0x16e06c add r0, pc, r0 */
/* @0x16e070 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e074 ldr r1, [pc, #0x330] */
/* @0x16e078 ldr r0, [pc, #0x330] */
/* @0x16e07c mov r2, #1 */
/* @0x16e080 mov r3, r2 */
/* @0x16e084 ldr r1, [r4, r1] */
/* @0x16e088 add r0, pc, r0 */
/* @0x16e08c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e090 ldr r1, [pc, #0x31c] */
/* @0x16e094 ldr r0, [pc, #0x31c] */
/* @0x16e098 mov r2, #1 */
/* @0x16e09c mov r3, r2 */
/* @0x16e0a0 ldr r1, [r4, r1] */
/* @0x16e0a4 add r0, pc, r0 */
/* @0x16e0a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e0ac ldr r1, [pc, #0x308] */
/* @0x16e0b0 ldr r0, [pc, #0x308] */
/* @0x16e0b4 mov r2, #1 */
/* @0x16e0b8 mov r3, r2 */
/* @0x16e0bc ldr r1, [r4, r1] */
/* @0x16e0c0 add r0, pc, r0 */
/* @0x16e0c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e0c8 ldr r1, [pc, #0x2f4] */
/* @0x16e0cc ldr r0, [pc, #0x2f4] */
/* @0x16e0d0 mov r2, #1 */
/* @0x16e0d4 mov r3, r2 */
/* @0x16e0d8 ldr r1, [r4, r1] */
/* @0x16e0dc add r0, pc, r0 */
/* @0x16e0e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e0e4 ldr r1, [pc, #0x2e0] */
/* @0x16e0e8 ldr r0, [pc, #0x2e0] */
/* @0x16e0ec mov r2, #1 */
/* @0x16e0f0 mov r3, r2 */
/* @0x16e0f4 ldr r1, [r4, r1] */
/* @0x16e0f8 add r0, pc, r0 */
/* @0x16e0fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e100 ldr r1, [pc, #0x2cc] */
/* @0x16e104 ldr r0, [pc, #0x2cc] */
/* @0x16e108 mov r2, #1 */
/* @0x16e10c mov r3, r2 */
/* @0x16e110 ldr r1, [r4, r1] */
/* @0x16e114 add r0, pc, r0 */
/* @0x16e118 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e11c ldr r1, [pc, #0x2b8] */
/* @0x16e120 ldr r0, [pc, #0x2b8] */
/* @0x16e124 mov r2, #1 */
/* @0x16e128 mov r3, r2 */
/* @0x16e12c ldr r1, [r4, r1] */
/* @0x16e130 add r0, pc, r0 */
/* @0x16e134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e138 ldr r1, [pc, #0x2a4] */
/* @0x16e13c ldr r0, [pc, #0x2a4] */
/* @0x16e140 mov r2, #1 */
/* @0x16e144 mov r3, r2 */
/* @0x16e148 ldr r1, [r4, r1] */
/* @0x16e14c add r0, pc, r0 */
/* @0x16e150 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e154 ldr r1, [pc, #0x290] */
/* @0x16e158 ldr r0, [pc, #0x290] */
/* @0x16e15c mov r2, #1 */
/* @0x16e160 mov r3, r2 */
/* @0x16e164 ldr r1, [r4, r1] */
/* @0x16e168 add r0, pc, r0 */
/* @0x16e16c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e170 ldr r1, [pc, #0x27c] */
/* @0x16e174 ldr r0, [pc, #0x27c] */
/* @0x16e178 mov r2, #1 */
/* @0x16e17c mov r3, r2 */
/* @0x16e180 ldr r1, [r4, r1] */
/* @0x16e184 add r0, pc, r0 */
/* @0x16e188 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e18c ldr r1, [pc, #0x268] */
/* @0x16e190 ldr r0, [pc, #0x268] */
/* @0x16e194 mov r2, #1 */
/* @0x16e198 mov r3, r2 */
/* @0x16e19c ldr r1, [r4, r1] */
/* @0x16e1a0 add r0, pc, r0 */
/* @0x16e1a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e1a8 ldr r1, [pc, #0x254] */
/* @0x16e1ac ldr r0, [pc, #0x254] */
/* @0x16e1b0 mov r2, #1 */
/* @0x16e1b4 mov r3, r2 */
/* @0x16e1b8 ldr r1, [r4, r1] */
/* @0x16e1bc add r0, pc, r0 */
/* @0x16e1c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e1c4 ldr r1, [pc, #0x240] */
/* @0x16e1c8 ldr r0, [pc, #0x240] */
/* @0x16e1cc mov r2, #1 */
/* @0x16e1d0 mov r3, r2 */
/* @0x16e1d4 ldr r1, [r4, r1] */
/* @0x16e1d8 add r0, pc, r0 */
/* @0x16e1dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e1e0 ldr r1, [pc, #0x22c] */
/* @0x16e1e4 ldr r0, [pc, #0x22c] */
/* @0x16e1e8 mov r2, #1 */
/* @0x16e1ec mov r3, r2 */
/* @0x16e1f0 ldr r1, [r4, r1] */
/* @0x16e1f4 add r0, pc, r0 */
/* @0x16e1f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e1fc ldr r1, [pc, #0x218] */
/* @0x16e200 ldr r0, [pc, #0x218] */
/* @0x16e204 mov r2, #1 */
/* @0x16e208 mov r3, r2 */
/* @0x16e20c ldr r1, [r4, r1] */
/* @0x16e210 add r0, pc, r0 */
/* @0x16e214 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e218 ldr r1, [pc, #0x204] */
/* @0x16e21c ldr r0, [pc, #0x204] */
/* @0x16e220 mov r2, #2 */
/* @0x16e224 mov r3, #1 */
/* @0x16e228 ldr r1, [r4, r1] */
/* @0x16e22c add r0, pc, r0 */
/* @0x16e230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e234 ldr r1, [pc, #0x1f0] */
/* @0x16e238 ldr r0, [pc, #0x1f0] */
/* @0x16e23c mov r2, #2 */
/* @0x16e240 mov r3, #1 */
/* @0x16e244 ldr r1, [r4, r1] */
/* @0x16e248 add r0, pc, r0 */
/* @0x16e24c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e250 ldr r1, [pc, #0x1dc] */
/* @0x16e254 ldr r0, [pc, #0x1dc] */
/* @0x16e258 mov r2, #2 */
/* @0x16e25c mov r3, #1 */
/* @0x16e260 ldr r1, [r4, r1] */
/* @0x16e264 add r0, pc, r0 */
/* @0x16e268 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e26c ldr r1, [pc, #0x1c8] */
/* @0x16e270 ldr r0, [pc, #0x1c8] */
/* @0x16e274 mov r2, #2 */
/* @0x16e278 mov r3, #1 */
/* @0x16e27c ldr r1, [r4, r1] */
/* @0x16e280 add r0, pc, r0 */
/* @0x16e284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e288 ldr r1, [pc, #0x1b4] */
/* @0x16e28c ldr r0, [pc, #0x1b4] */
/* @0x16e290 mov r2, #2 */
/* @0x16e294 mov r3, #1 */
/* @0x16e298 ldr r1, [r4, r1] */
/* @0x16e29c add r0, pc, r0 */
/* @0x16e2a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e2a4 ldr r1, [pc, #0x1a0] */
/* @0x16e2a8 ldr r0, [pc, #0x1a0] */
/* @0x16e2ac mov r2, #2 */
/* @0x16e2b0 mov r3, #1 */
/* @0x16e2b4 ldr r1, [r4, r1] */
/* @0x16e2b8 add r0, pc, r0 */
/* @0x16e2bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e2c0 ldr r1, [pc, #0x18c] */
/* @0x16e2c4 ldr r0, [pc, #0x18c] */
/* @0x16e2c8 mov r2, #2 */
/* @0x16e2cc mov r3, #1 */
/* @0x16e2d0 ldr r1, [r4, r1] */
/* @0x16e2d4 add r0, pc, r0 */
/* @0x16e2d8 pop {r4, lr} */
/* @0x16e2dc b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x16e2e0 mlaeq r8, r0, lr, r3 */
/* @0x16e2e4 .word 0xffffe550 */
/* @0x16e2e8 andseq r12, sp, r4, lsr #22 */
/* @0x16e2ec .word 0xffffe554 */
/* @0x16e2f0 andseq r12, sp, r8, lsl r11 */
/* @0x16e2f4 .word 0xffffe558 */
/* @0x16e2f8 andseq r12, sp, r0, lsl r11 */
/* @0x16e2fc .word 0xffffe55c */
/* @0x16e300 andseq r12, sp, r4, lsl #22 */
/* @0x16e304 .word 0xffffe560 */
/* @0x16e308 ldrsheq r12, [sp], -r8 */
/* @0x16e30c .word 0xffffe564 */
/* @0x16e310 ldrsheq r12, [sp], -r0 */
/* @0x16e314 .word 0xffffe568 */
/* @0x16e318 andseq r12, sp, r8, ror #21 */
/* @0x16e31c .word 0xffffe56c */
/* @0x16e320 andseq r12, sp, r0, ror #21 */
/* @0x16e324 .word 0xffffe570 */
/* @0x16e328 ldrsbeq r12, [sp], -r8 */
/* @0x16e32c .word 0xffffe574 */
/* @0x16e330 ldrsbeq r12, [sp], -r0 */
/* @0x16e334 .word 0xffffe578 */
/* @0x16e338 ldrsbeq r12, [sp], -r0 */
/* @0x16e33c .word 0xffffe57c */
/* @0x16e340 andseq r12, sp, r12, asr #21 */
/* @0x16e344 .word 0xffffe580 */
/* @0x16e348 andseq r12, sp, r8, asr #21 */
/* @0x16e34c .word 0xffffe584 */
/* @0x16e350 andseq r12, sp, r0, asr #21 */
/* @0x16e354 .word 0xffffe588 */
/* @0x16e358 ldrheq r12, [sp], -r12 */
/* @0x16e35c .word 0xffffe58c */
/* @0x16e360 ldrheq r12, [sp], -r8 */
/* @0x16e364 .word 0xffffe590 */
/* @0x16e368 ldrheq r12, [sp], -r4 */
/* @0x16e36c .word 0xffffe594 */
/* @0x16e370 ldrheq r12, [sp], -r0 */
/* @0x16e374 .word 0xffffe598 */
/* @0x16e378 andseq r12, sp, r12, lsr #21 */
/* @0x16e37c .word 0xffffe59c */
/* @0x16e380 andseq r12, sp, r4, lsr #21 */
/* @0x16e384 .word 0xffffe5a0 */
/* @0x16e388 mulseq sp, r12, r10 */
/* @0x16e38c .word 0xffffe5a4 */
/* @0x16e390 mulseq sp, r12, r10 */
/* @0x16e394 .word 0xffffe5a8 */
/* @0x16e398 mulseq sp, r8, r10 */
/* @0x16e39c .word 0xffffe5ac */
/* @0x16e3a0 mulseq sp, r4, r10 */
/* @0x16e3a4 .word 0xffffe5b0 */
/* @0x16e3a8 andseq r12, sp, r12, lsl #21 */
/* @0x16e3ac .word 0xffffe5b4 */
/* @0x16e3b0 andseq r12, sp, r4, lsl #21 */
/* @0x16e3b4 .word 0xffffe5b8 */
/* @0x16e3b8 andseq r12, sp, r0, lsl #21 */
/* @0x16e3bc .word 0xffffe5bc */
/* @0x16e3c0 andseq r12, sp, r12, ror r10 */
/* @0x16e3c4 .word 0xffffe5c0 */
/* @0x16e3c8 andseq r12, sp, r8, ror r10 */
/* @0x16e3cc .word 0xffffe5c4 */
/* @0x16e3d0 andseq r12, sp, r4, ror r10 */
/* @0x16e3d4 .word 0xffffe5c8 */
/* @0x16e3d8 andseq r12, sp, r4, ror r10 */
/* @0x16e3dc .word 0xffffe5cc */
/* @0x16e3e0 andseq r12, sp, r4, ror r10 */
/* @0x16e3e4 .word 0xffffe5d0 */
/* @0x16e3e8 andseq r12, sp, r0, ror r10 */
/* @0x16e3ec .word 0xffffe5d4 */
/* @0x16e3f0 andseq r12, sp, r12, ror #20 */
/* @0x16e3f4 .word 0xffffe5d8 */
/* @0x16e3f8 andseq r12, sp, r0, ror #20 */
/* @0x16e3fc .word 0xffffe5dc */
/* @0x16e400 andseq r12, sp, r8, asr r10 */
/* @0x16e404 .word 0xffffe5e0 */
/* @0x16e408 andseq r12, sp, r12, asr #20 */
/* @0x16e40c .word 0xffffe5e4 */
/* @0x16e410 andseq r12, sp, r0, asr #20 */
/* @0x16e414 .word 0xffffe5e8 */
/* @0x16e418 andseq r12, sp, r4, lsr r10 */
/* @0x16e41c .word 0xffffe5ec */
/* @0x16e420 andseq r12, sp, r8, lsr #20 */
/* @0x16e424 .word 0xffffe5f0 */
/* @0x16e428 andseq r12, sp, r0, lsr #20 */
/* @0x16e42c .word 0xffffe5f4 */
/* @0x16e430 andseq r12, sp, r4, lsl r10 */
/* @0x16e434 .word 0xffffe5f8 */
/* @0x16e438 andseq r12, sp, r12, lsl #20 */
/* @0x16e43c .word 0xffffe5fc */
/* @0x16e440 andseq r12, sp, r0, lsl #20 */
/* @0x16e444 .word 0xffffe600 */
/* @0x16e448 ldrsheq r12, [sp], -r4 */
/* @0x16e44c .word 0xffffe604 */
/* @0x16e450 andseq r12, sp, r8, ror #19 */
/* @0x16e454 .word 0xffffe608 */
/* @0x16e458 ldrsbeq r12, [sp], -r12 */

/* ── FUNC 0x16e45c · SerializeMatrix(yyMatrix*, IBuffer*) · size=84 · insn=21 */
/* @0x16e45c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16e460 add r10, r1, #44 */
/* @0x16e464 mov r6, r1 */
/* @0x16e468 mov r8, r0 */
/* @0x16e46c mov r7, #16 */
/* @0x16e470 mov r9, #0 */
/* @0x16e474 vldmia r8!, {s15} */
/* @0x16e478 vcvt.f64.f32 d6, s15 */
/* @0x16e47c ldr r3, [r6] */
/* @0x16e480 mov r0, r6 */
/* @0x16e484 str r9, [r6, #0x38] */
/* @0x16e488 mov r1, #8 */
/* @0x16e48c mov r2, r10 */
/* @0x16e490 vmov r4, r5, d6 */
/* @0x16e494 vstr s12, [r6, #44] */
/* @0x16e498 str r5, [r6, #0x30] */
/* @0x16e49c ldr r3, [r3, #0x8] */
/* @0x16e4a0 blx r3 */
/* @0x16e4a4 subs r7, r7, #1 */
/* @0x16e4a8 bne 0x16e474 <_Z15SerializeMatrixP8yyMatrixP7IBuffer+0x18> */
/* @0x16e4ac pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x16e4b0 · DeSerializeMatrix(yyMatrix*, IBuffer*) · size=72 · insn=18 */
/* @0x16e4b0 push {r3, r4, r5, r6, r7, lr} */
/* @0x16e4b4 add r6, r1, #44 */
/* @0x16e4b8 mov r5, r1 */
/* @0x16e4bc mov r7, r0 */
/* @0x16e4c0 mov r4, #16 */
/* @0x16e4c4 ldr r3, [r5] */
/* @0x16e4c8 mov r1, #8 */
/* @0x16e4cc mov r2, r6 */
/* @0x16e4d0 mov r0, r5 */
/* @0x16e4d4 ldr r3, [r3, #0xc] */
/* @0x16e4d8 blx r3 */
/* @0x16e4dc mov r0, r6 */
/* @0x16e4e0 mov r1, #0 */
/* @0x16e4e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16e4e8 subs r4, r4, #1 */
/* @0x16e4ec str r0, [r7], #4 */
/* @0x16e4f0 bne 0x16e4c4 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer+0x14> */
/* @0x16e4f4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x16e4f8 · CCamera::Serialize(IBuffer*) · size=892 · insn=223 */
/* @0x16e4f8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x16e4fc mov r6, r1 */
/* @0x16e500 mov r7, r0 */
/* @0x16e504 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16e508 ldr r3, [r6] */
/* @0x16e50c add r9, r6, #44 */
/* @0x16e510 mov r8, #0 */
/* @0x16e514 mov r1, #6 */
/* @0x16e518 mov r2, r9 */
/* @0x16e51c str r8, [r6, #0x38] */
/* @0x16e520 vmov s13, r0 */
/* @0x16e524 mov r0, r6 */
/* @0x16e528 vcvt.f64.s32 d6, s13 */
/* @0x16e52c vmov r4, r5, d6 */
/* @0x16e530 vstr s12, [r6, #44] */
/* @0x16e534 str r5, [r6, #0x30] */
/* @0x16e538 ldr r3, [r3, #0x8] */
/* @0x16e53c blx r3 */
/* @0x16e540 add r0, r7, #4 */
/* @0x16e544 mov r1, r6 */
/* @0x16e548 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e54c add r0, r7, #68 */
/* @0x16e550 mov r1, r6 */
/* @0x16e554 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e558 add r0, r7, #132 */
/* @0x16e55c mov r1, r6 */
/* @0x16e560 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e564 add r0, r7, #196 */
/* @0x16e568 mov r1, r6 */
/* @0x16e56c bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e570 add r0, r7, #260 */
/* @0x16e574 mov r1, r6 */
/* @0x16e578 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e57c add r0, r7, #324 */
/* @0x16e580 mov r1, r6 */
/* @0x16e584 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e588 vldr s15, [r7, #388] */
/* @0x16e58c vcvt.f64.f32 d6, s15 */
/* @0x16e590 ldr r3, [r6] */
/* @0x16e594 mov r2, r9 */
/* @0x16e598 str r8, [r6, #0x38] */
/* @0x16e59c mov r0, r6 */
/* @0x16e5a0 mov r1, #8 */
/* @0x16e5a4 vmov r4, r5, d6 */
/* @0x16e5a8 vstr s12, [r6, #44] */
/* @0x16e5ac str r5, [r6, #0x30] */
/* @0x16e5b0 ldr r3, [r3, #0x8] */
/* @0x16e5b4 blx r3 */
/* @0x16e5b8 vldr s15, [r7, #392] */
/* @0x16e5bc vcvt.f64.f32 d6, s15 */
/* @0x16e5c0 ldr r3, [r6] */
/* @0x16e5c4 mov r2, r9 */
/* @0x16e5c8 str r8, [r6, #0x38] */
/* @0x16e5cc mov r0, r6 */
/* @0x16e5d0 mov r1, #8 */
/* @0x16e5d4 vmov r4, r5, d6 */
/* @0x16e5d8 vstr s12, [r6, #44] */
/* @0x16e5dc str r5, [r6, #0x30] */
/* @0x16e5e0 ldr r3, [r3, #0x8] */
/* @0x16e5e4 blx r3 */
/* @0x16e5e8 vldr s15, [r7, #396] */
/* @0x16e5ec vcvt.f64.f32 d6, s15 */
/* @0x16e5f0 ldr r3, [r6] */
/* @0x16e5f4 mov r2, r9 */
/* @0x16e5f8 str r8, [r6, #0x38] */
/* @0x16e5fc mov r0, r6 */
/* @0x16e600 mov r1, #8 */
/* @0x16e604 vmov r4, r5, d6 */
/* @0x16e608 vstr s12, [r6, #44] */
/* @0x16e60c str r5, [r6, #0x30] */
/* @0x16e610 ldr r3, [r3, #0x8] */
/* @0x16e614 blx r3 */
/* @0x16e618 vldr s15, [r7, #400] */
/* @0x16e61c vcvt.f64.f32 d6, s15 */
/* @0x16e620 ldr r3, [r6] */
/* @0x16e624 mov r2, r9 */
/* @0x16e628 str r8, [r6, #0x38] */
/* @0x16e62c mov r0, r6 */
/* @0x16e630 mov r1, #8 */
/* @0x16e634 vmov r4, r5, d6 */
/* @0x16e638 vstr s12, [r6, #44] */
/* @0x16e63c str r5, [r6, #0x30] */
/* @0x16e640 ldr r3, [r3, #0x8] */
/* @0x16e644 blx r3 */
/* @0x16e648 vldr s15, [r7, #404] */
/* @0x16e64c vcvt.f64.f32 d6, s15 */
/* @0x16e650 ldr r3, [r6] */
/* @0x16e654 mov r2, r9 */
/* @0x16e658 str r8, [r6, #0x38] */
/* @0x16e65c mov r0, r6 */
/* @0x16e660 mov r1, #8 */
/* @0x16e664 vmov r4, r5, d6 */
/* @0x16e668 vstr s12, [r6, #44] */
/* @0x16e66c str r5, [r6, #0x30] */
/* @0x16e670 ldr r3, [r3, #0x8] */
/* @0x16e674 blx r3 */
/* @0x16e678 vldr s15, [r7, #408] */
/* @0x16e67c vcvt.f64.f32 d6, s15 */
/* @0x16e680 ldr r3, [r6] */
/* @0x16e684 mov r2, r9 */
/* @0x16e688 str r8, [r6, #0x38] */
/* @0x16e68c mov r0, r6 */
/* @0x16e690 mov r1, #8 */
/* @0x16e694 vmov r4, r5, d6 */
/* @0x16e698 vstr s12, [r6, #44] */
/* @0x16e69c str r5, [r6, #0x30] */
/* @0x16e6a0 ldr r3, [r3, #0x8] */
/* @0x16e6a4 blx r3 */
/* @0x16e6a8 vldr s15, [r7, #412] */
/* @0x16e6ac vcvt.f64.f32 d6, s15 */
/* @0x16e6b0 ldr r3, [r6] */
/* @0x16e6b4 mov r2, r9 */
/* @0x16e6b8 str r8, [r6, #0x38] */
/* @0x16e6bc mov r0, r6 */
/* @0x16e6c0 mov r1, #8 */
/* @0x16e6c4 vmov r4, r5, d6 */
/* @0x16e6c8 vstr s12, [r6, #44] */
/* @0x16e6cc str r5, [r6, #0x30] */
/* @0x16e6d0 ldr r3, [r3, #0x8] */
/* @0x16e6d4 blx r3 */
/* @0x16e6d8 vldr s15, [r7, #416] */
/* @0x16e6dc vcvt.f64.f32 d6, s15 */
/* @0x16e6e0 ldr r3, [r6] */
/* @0x16e6e4 mov r2, r9 */
/* @0x16e6e8 str r8, [r6, #0x38] */
/* @0x16e6ec mov r0, r6 */
/* @0x16e6f0 mov r1, #8 */
/* @0x16e6f4 vmov r4, r5, d6 */
/* @0x16e6f8 vstr s12, [r6, #44] */
/* @0x16e6fc str r5, [r6, #0x30] */
/* @0x16e700 ldr r3, [r3, #0x8] */
/* @0x16e704 blx r3 */
/* @0x16e708 vldr s15, [r7, #420] */
/* @0x16e70c vcvt.f64.f32 d6, s15 */
/* @0x16e710 ldr r3, [r6] */
/* @0x16e714 mov r2, r9 */
/* @0x16e718 str r8, [r6, #0x38] */
/* @0x16e71c mov r0, r6 */
/* @0x16e720 mov r1, #8 */
/* @0x16e724 vmov r4, r5, d6 */
/* @0x16e728 vstr s12, [r6, #44] */
/* @0x16e72c str r5, [r6, #0x30] */
/* @0x16e730 ldr r3, [r3, #0x8] */
/* @0x16e734 blx r3 */
/* @0x16e738 ldr r4, [r7, #0x1a8] */
/* @0x16e73c ldr r3, [r6] */
/* @0x16e740 mov r2, r9 */
/* @0x16e744 str r8, [r6, #0x38] */
/* @0x16e748 mov r0, r6 */
/* @0x16e74c vmov s15, r4 */
/* @0x16e750 mov r1, #6 */
/* @0x16e754 vcvt.f64.s32 d7, s15 */
/* @0x16e758 vmov r4, r5, d7 */
/* @0x16e75c vstr s14, [r6, #44] */
/* @0x16e760 str r5, [r6, #0x30] */
/* @0x16e764 ldr r3, [r3, #0x8] */
/* @0x16e768 blx r3 */
/* @0x16e76c ldr r4, [r7, #0x1ac] */
/* @0x16e770 ldr r3, [r6] */
/* @0x16e774 mov r2, r9 */
/* @0x16e778 str r8, [r6, #0x38] */
/* @0x16e77c mov r0, r6 */
/* @0x16e780 vmov s13, r4 */
/* @0x16e784 mov r1, #6 */
/* @0x16e788 vcvt.f64.s32 d6, s13 */
/* @0x16e78c vmov r4, r5, d6 */
/* @0x16e790 vstr s12, [r6, #44] */
/* @0x16e794 str r5, [r6, #0x30] */
/* @0x16e798 ldr r3, [r3, #0x8] */
/* @0x16e79c blx r3 */
/* @0x16e7a0 ldr r4, [r7, #0x1b0] */
/* @0x16e7a4 ldr r3, [r6] */
/* @0x16e7a8 mov r2, r9 */
/* @0x16e7ac str r8, [r6, #0x38] */
/* @0x16e7b0 mov r0, r6 */
/* @0x16e7b4 vmov s15, r4 */
/* @0x16e7b8 mov r1, #6 */
/* @0x16e7bc vcvt.f64.s32 d7, s15 */
/* @0x16e7c0 vmov r4, r5, d7 */
/* @0x16e7c4 vstr s14, [r6, #44] */
/* @0x16e7c8 str r5, [r6, #0x30] */
/* @0x16e7cc ldr r3, [r3, #0x8] */
/* @0x16e7d0 blx r3 */
/* @0x16e7d4 ldr r4, [r7, #0x1b4] */
/* @0x16e7d8 ldr r3, [r6] */
/* @0x16e7dc mov r2, r9 */
/* @0x16e7e0 str r8, [r6, #0x38] */
/* @0x16e7e4 mov r0, r6 */
/* @0x16e7e8 vmov s13, r4 */
/* @0x16e7ec mov r1, #6 */
/* @0x16e7f0 vcvt.f64.s32 d6, s13 */
/* @0x16e7f4 vmov r4, r5, d6 */
/* @0x16e7f8 vstr s12, [r6, #44] */
/* @0x16e7fc str r5, [r6, #0x30] */
/* @0x16e800 ldr r3, [r3, #0x8] */
/* @0x16e804 blx r3 */
/* @0x16e808 ldrb r4, [r7, #0x1b8] */
/* @0x16e80c ldr r3, [r6] */
/* @0x16e810 mov r2, r9 */
/* @0x16e814 str r8, [r6, #0x38] */
/* @0x16e818 mov r0, r6 */
/* @0x16e81c vmov s15, r4 */
/* @0x16e820 mov r1, #6 */
/* @0x16e824 vcvt.f64.u32 d7, s15 */
/* @0x16e828 vmov r4, r5, d7 */
/* @0x16e82c vstr s14, [r6, #44] */
/* @0x16e830 str r5, [r6, #0x30] */
/* @0x16e834 ldr r3, [r3, #0x8] */
/* @0x16e838 blx r3 */
/* @0x16e83c ldrb r4, [r7, #0x1b9] */
/* @0x16e840 ldr r3, [r6] */
/* @0x16e844 mov r2, r9 */
/* @0x16e848 str r8, [r6, #0x38] */
/* @0x16e84c mov r0, r6 */
/* @0x16e850 vmov s13, r4 */
/* @0x16e854 mov r1, #6 */
/* @0x16e858 vcvt.f64.u32 d6, s13 */
/* @0x16e85c vmov r4, r5, d6 */
/* @0x16e860 vstr s12, [r6, #44] */
/* @0x16e864 str r5, [r6, #0x30] */
/* @0x16e868 ldr r3, [r3, #0x8] */
/* @0x16e86c blx r3 */
/* @0x16e870 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x16e874 · CCameraManager::Serialize(IBuffer*) · size=232 · insn=58 */
/* @0x16e874 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x16e878 add r8, r1, #44 */
/* @0x16e87c ldr r4, [r0, #0x14] */
/* @0x16e880 mov r6, r1 */
/* @0x16e884 ldr r3, [r1] */
/* @0x16e888 mov r7, r0 */
/* @0x16e88c mov r9, #0 */
/* @0x16e890 mov r0, r1 */
/* @0x16e894 vmov s15, r4 */
/* @0x16e898 str r9, [r1, #0x38] */
/* @0x16e89c mov r2, r8 */
/* @0x16e8a0 mov r1, #6 */
/* @0x16e8a4 vcvt.f64.s32 d7, s15 */
/* @0x16e8a8 vmov r4, r5, d7 */
/* @0x16e8ac vstr s14, [r6, #44] */
/* @0x16e8b0 str r5, [r6, #0x30] */
/* @0x16e8b4 ldr r3, [r3, #0x8] */
/* @0x16e8b8 blx r3 */
/* @0x16e8bc ldr r3, [r7, #0x14] */
/* @0x16e8c0 cmp r3, r9 */
/* @0x16e8c4 pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x16e8c8 mov r10, r9 */
/* @0x16e8cc mov r4, r9 */
/* @0x16e8d0 movt r10, #0x3ff0 */
/* @0x16e8d4 b 0x16e908 <_ZN14CCameraManager9SerializeEP7IBuffer+0x94> */
/* @0x16e8d8 str r9, [r6, #0x2c] */
/* @0x16e8dc add r4, r4, #1 */
/* @0x16e8e0 str r10, [r6, #0x30] */
/* @0x16e8e4 str r9, [r6, #0x38] */
/* @0x16e8e8 ldr r3, [r3, #0x8] */
/* @0x16e8ec blx r3 */
/* @0x16e8f0 mov r0, r5 */
/* @0x16e8f4 mov r1, r6 */
/* @0x16e8f8 bl 0x16e4f8 <_ZN7CCamera9SerializeEP7IBuffer> */
/* @0x16e8fc ldr r3, [r7, #0x14] */
/* @0x16e900 cmp r3, r4 */
/* @0x16e904 ble 0x16e958 <_ZN14CCameraManager9SerializeEP7IBuffer+0xe4> */
/* @0x16e908 ldr r3, [r7, #0xc] */
/* @0x16e90c mov r0, r6 */
/* @0x16e910 mov r2, r8 */
/* @0x16e914 mov r1, #6 */
/* @0x16e918 ldr r5, [r3, r4, lsl #2] */
/* @0x16e91c ldr r3, [r6] */
/* @0x16e920 cmp r5, #0 */
/* @0x16e924 bne 0x16e8d8 <_ZN14CCameraManager9SerializeEP7IBuffer+0x64> */
/* @0x16e928 str r5, [r6, #0x2c] */
/* @0x16e92c mov r0, r6 */
/* @0x16e930 str r5, [r6, #0x30] */
/* @0x16e934 mov r1, #6 */
/* @0x16e938 ldr r3, [r3, #0x8] */
/* @0x16e93c mov r2, r8 */
/* @0x16e940 str r5, [r6, #0x38] */
/* @0x16e944 add r4, r4, #1 */
/* @0x16e948 blx r3 */
/* @0x16e94c ldr r3, [r7, #0x14] */
/* @0x16e950 cmp r3, r4 */
/* @0x16e954 bgt 0x16e908 <_ZN14CCameraManager9SerializeEP7IBuffer+0x94> */
/* @0x16e958 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x16e95c · CCamera::DeSerialize(IBuffer*) · size=736 · insn=184 */
/* @0x16e95c ldr r3, [r1] */
/* @0x16e960 push {r4, r5, r6, lr} */
/* @0x16e964 add r5, r1, #44 */
/* @0x16e968 mov r4, r1 */
/* @0x16e96c mov r6, r0 */
/* @0x16e970 mov r2, r5 */
/* @0x16e974 ldr r3, [r3, #0xc] */
/* @0x16e978 mov r0, r1 */
/* @0x16e97c mov r1, #6 */
/* @0x16e980 blx r3 */
/* @0x16e984 mov r1, #0 */
/* @0x16e988 mov r0, r5 */
/* @0x16e98c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16e990 mov r3, r6 */
/* @0x16e994 mov r1, r4 */
/* @0x16e998 str r0, [r3], #4 */
/* @0x16e99c mov r0, r3 */
/* @0x16e9a0 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e9a4 add r0, r6, #68 */
/* @0x16e9a8 mov r1, r4 */
/* @0x16e9ac bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e9b0 add r0, r6, #132 */
/* @0x16e9b4 mov r1, r4 */
/* @0x16e9b8 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e9bc add r0, r6, #196 */
/* @0x16e9c0 mov r1, r4 */
/* @0x16e9c4 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e9c8 add r0, r6, #260 */
/* @0x16e9cc mov r1, r4 */
/* @0x16e9d0 bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e9d4 add r0, r6, #324 */
/* @0x16e9d8 mov r1, r4 */
/* @0x16e9dc bl 0x16e4b0 <_Z17DeSerializeMatrixP8yyMatrixP7IBuffer> */
/* @0x16e9e0 ldr r3, [r4] */
/* @0x16e9e4 mov r2, r5 */
/* @0x16e9e8 mov r1, #8 */
/* @0x16e9ec mov r0, r4 */
/* @0x16e9f0 ldr r3, [r3, #0xc] */
/* @0x16e9f4 blx r3 */
/* @0x16e9f8 mov r1, #0 */
/* @0x16e9fc mov r0, r5 */
/* @0x16ea00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16ea04 ldr r3, [r4] */
/* @0x16ea08 mov r2, r5 */
/* @0x16ea0c mov r1, #8 */
/* @0x16ea10 ldr r3, [r3, #0xc] */
/* @0x16ea14 str r0, [r6, #0x184] */
/* @0x16ea18 mov r0, r4 */
/* @0x16ea1c blx r3 */
/* @0x16ea20 mov r1, #0 */
/* @0x16ea24 mov r0, r5 */
/* @0x16ea28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16ea2c ldr r3, [r4] */
/* @0x16ea30 mov r2, r5 */
/* @0x16ea34 mov r1, #8 */
/* @0x16ea38 ldr r3, [r3, #0xc] */
/* @0x16ea3c str r0, [r6, #0x188] */
/* @0x16ea40 mov r0, r4 */
/* @0x16ea44 blx r3 */
/* @0x16ea48 mov r1, #0 */
/* @0x16ea4c mov r0, r5 */
/* @0x16ea50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16ea54 ldr r3, [r4] */
/* @0x16ea58 mov r2, r5 */
/* @0x16ea5c mov r1, #8 */
/* @0x16ea60 ldr r3, [r3, #0xc] */
/* @0x16ea64 str r0, [r6, #0x18c] */
/* @0x16ea68 mov r0, r4 */
/* @0x16ea6c blx r3 */
/* @0x16ea70 mov r1, #0 */
/* @0x16ea74 mov r0, r5 */
/* @0x16ea78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16ea7c ldr r3, [r4] */
/* @0x16ea80 mov r2, r5 */
/* @0x16ea84 mov r1, #8 */
/* @0x16ea88 ldr r3, [r3, #0xc] */
/* @0x16ea8c str r0, [r6, #0x190] */
/* @0x16ea90 mov r0, r4 */
/* @0x16ea94 blx r3 */
/* @0x16ea98 mov r1, #0 */
/* @0x16ea9c mov r0, r5 */
/* @0x16eaa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eaa4 ldr r3, [r4] */
/* @0x16eaa8 mov r2, r5 */
/* @0x16eaac mov r1, #8 */
/* @0x16eab0 ldr r3, [r3, #0xc] */
/* @0x16eab4 str r0, [r6, #0x194] */
/* @0x16eab8 mov r0, r4 */
/* @0x16eabc blx r3 */
/* @0x16eac0 mov r1, #0 */
/* @0x16eac4 mov r0, r5 */
/* @0x16eac8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eacc ldr r3, [r4] */
/* @0x16ead0 mov r2, r5 */
/* @0x16ead4 mov r1, #8 */
/* @0x16ead8 ldr r3, [r3, #0xc] */
/* @0x16eadc str r0, [r6, #0x198] */
/* @0x16eae0 mov r0, r4 */
/* @0x16eae4 blx r3 */
/* @0x16eae8 mov r1, #0 */
/* @0x16eaec mov r0, r5 */
/* @0x16eaf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eaf4 ldr r3, [r4] */
/* @0x16eaf8 mov r2, r5 */
/* @0x16eafc mov r1, #8 */
/* @0x16eb00 ldr r3, [r3, #0xc] */
/* @0x16eb04 str r0, [r6, #0x19c] */
/* @0x16eb08 mov r0, r4 */
/* @0x16eb0c blx r3 */
/* @0x16eb10 mov r1, #0 */
/* @0x16eb14 mov r0, r5 */
/* @0x16eb18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eb1c ldr r3, [r4] */
/* @0x16eb20 mov r2, r5 */
/* @0x16eb24 mov r1, #8 */
/* @0x16eb28 ldr r3, [r3, #0xc] */
/* @0x16eb2c str r0, [r6, #0x1a0] */
/* @0x16eb30 mov r0, r4 */
/* @0x16eb34 blx r3 */
/* @0x16eb38 mov r1, #0 */
/* @0x16eb3c mov r0, r5 */
/* @0x16eb40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eb44 ldr r3, [r4] */
/* @0x16eb48 mov r2, r5 */
/* @0x16eb4c mov r1, #6 */
/* @0x16eb50 ldr r3, [r3, #0xc] */
/* @0x16eb54 str r0, [r6, #0x1a4] */
/* @0x16eb58 mov r0, r4 */
/* @0x16eb5c blx r3 */
/* @0x16eb60 mov r1, #0 */
/* @0x16eb64 mov r0, r5 */
/* @0x16eb68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16eb6c ldr r3, [r4] */
/* @0x16eb70 mov r2, r5 */
/* @0x16eb74 mov r1, #6 */
/* @0x16eb78 ldr r3, [r3, #0xc] */
/* @0x16eb7c str r0, [r6, #0x1a8] */
/* @0x16eb80 mov r0, r4 */
/* @0x16eb84 blx r3 */
/* @0x16eb88 mov r1, #0 */
/* @0x16eb8c mov r0, r5 */
/* @0x16eb90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16eb94 ldr r3, [r4] */
/* @0x16eb98 mov r2, r5 */
/* @0x16eb9c mov r1, #6 */
/* @0x16eba0 ldr r3, [r3, #0xc] */
/* @0x16eba4 str r0, [r6, #0x1ac] */
/* @0x16eba8 mov r0, r4 */
/* @0x16ebac blx r3 */
/* @0x16ebb0 mov r1, #0 */
/* @0x16ebb4 mov r0, r5 */
/* @0x16ebb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16ebbc ldr r3, [r4] */
/* @0x16ebc0 mov r2, r5 */
/* @0x16ebc4 mov r1, #6 */
/* @0x16ebc8 ldr r3, [r3, #0xc] */
/* @0x16ebcc str r0, [r6, #0x1b0] */
/* @0x16ebd0 mov r0, r4 */
/* @0x16ebd4 blx r3 */
/* @0x16ebd8 mov r1, #0 */
/* @0x16ebdc mov r0, r5 */
/* @0x16ebe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16ebe4 ldr r3, [r4] */
/* @0x16ebe8 mov r2, r5 */
/* @0x16ebec mov r1, #6 */
/* @0x16ebf0 ldr r3, [r3, #0xc] */
/* @0x16ebf4 str r0, [r6, #0x1b4] */
/* @0x16ebf8 mov r0, r4 */
/* @0x16ebfc blx r3 */
/* @0x16ec00 mov r1, #0 */
/* @0x16ec04 mov r0, r5 */
/* @0x16ec08 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x16ec0c ldr r3, [r4] */
/* @0x16ec10 mov r2, r5 */
/* @0x16ec14 mov r1, #6 */
/* @0x16ec18 ldr r3, [r3, #0xc] */
/* @0x16ec1c strb r0, [r6, #0x1b8] */
/* @0x16ec20 mov r0, r4 */
/* @0x16ec24 blx r3 */
/* @0x16ec28 mov r0, r5 */
/* @0x16ec2c mov r1, #0 */
/* @0x16ec30 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x16ec34 strb r0, [r6, #0x1b9] */
/* @0x16ec38 pop {r4, r5, r6, pc} */

/* ── FUNC 0x16ec3c · CCameraManager::GetActiveCamera() · size=8 · insn=2 */
/* @0x16ec3c ldr r0, [r0, #0x4] */
/* @0x16ec40 bx lr */

/* ── FUNC 0x16ec44 · F_CameraGetActive(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x16ec44 ldr r1, [pc, #0x4c] */
/* @0x16ec48 mov r2, #0 */
/* @0x16ec4c push {r4, lr} */
/* @0x16ec50 mov r4, r0 */
/* @0x16ec54 mov r3, r2 */
/* @0x16ec58 movt r2, #0xbff0 */
/* @0x16ec5c str r3, [r0, #0xc] */
/* @0x16ec60 str r2, [r0, #0x4] */
/* @0x16ec64 ldr r0, [pc, r1] */
/* @0x16ec68 str r3, [r4] */
/* @0x16ec6c bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x16ec70 cmp r0, #0 */
/* @0x16ec74 popeq {r4, pc} */
/* @0x16ec78 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16ec7c vmov s15, r0 */
/* @0x16ec80 vcvt.f64.s32 d7, s15 */
/* @0x16ec84 vmov r0, r1, d7 */
/* @0x16ec88 vmov r2, s14 */
/* @0x16ec8c mov r3, r1 */
/* @0x16ec90 stm r4, {r2, r3} */
/* @0x16ec94 pop {r4, pc} */
/* @0x16ec98 eoreq pc, r7, r0, lsl r0 */

/* ── FUNC 0x16ec9c · CCameraManager::StartRoom() · size=84 · insn=21 */
/* @0x16ec9c push {r4, r5, r6, lr} */
/* @0x16eca0 mov r5, r0 */
/* @0x16eca4 ldr r4, [r0, #0x8] */
/* @0x16eca8 sub sp, sp, #8 */
/* @0x16ecac cmp r4, #0 */
/* @0x16ecb0 beq 0x16ecbc <_ZN14CCameraManager9StartRoomEv+0x20> */
/* @0x16ecb4 add sp, sp, #8 */
/* @0x16ecb8 pop {r4, r5, r6, pc} */
/* @0x16ecbc mov r0, #432 */
/* @0x16ecc0 bl 0x27c524 <_Znwj> */
/* @0x16ecc4 mov r1, #0 */
/* @0x16ecc8 mov r3, r4 */
/* @0x16eccc str r4, [sp, #0x4] */
/* @0x16ecd0 mvn r2, #0 */
/* @0x16ecd4 str r2, [sp] */
/* @0x16ecd8 mov r2, r1 */
/* @0x16ecdc mov r6, r0 */
/* @0x16ece0 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x16ece4 str r6, [r5, #0x8] */
/* @0x16ece8 add sp, sp, #8 */
/* @0x16ecec pop {r4, r5, r6, pc} */

/* ── FUNC 0x16ecf0 · CCameraManager::EndRoom() · size=44 · insn=11 */
/* @0x16ecf0 push {r4, lr} */
/* @0x16ecf4 mov r4, r0 */
/* @0x16ecf8 ldr r0, [r0, #0x8] */
/* @0x16ecfc cmp r0, #0 */
/* @0x16ed00 popeq {r4, pc} */
/* @0x16ed04 ldr r2, [r0] */
/* @0x16ed08 ldr r3, [r2, #0x4] */
/* @0x16ed0c blx r3 */
/* @0x16ed10 mov r3, #0 */
/* @0x16ed14 str r3, [r4, #0x8] */
/* @0x16ed18 pop {r4, pc} */

/* ── FUNC 0x16ed1c · CCameraManager::AddCameraToList(CCamera*, int) · size=152 · insn=38 */
/* @0x16ed1c push {r4, r5, lr} */
/* @0x16ed20 subs r5, r1, #0 */
/* @0x16ed24 sub sp, sp, #12 */
/* @0x16ed28 mov r4, r0 */
/* @0x16ed2c beq 0x16ed70 <_ZN14CCameraManager15AddCameraToListEP7CCamerai+0x54> */
/* @0x16ed30 cmn r2, #1 */
/* @0x16ed34 ldreq r1, [r0] */
/* @0x16ed38 movne r1, r2 */
/* @0x16ed3c moveq r0, r5 */
/* @0x16ed40 movne r0, r5 */
/* @0x16ed44 addeq r3, r1, #1 */
/* @0x16ed48 streq r3, [r4] */
/* @0x16ed4c bl 0x16d124 <_ZN7CCamera5SetIDEi> */
/* @0x16ed50 ldr r3, [r4, #0x14] */
/* @0x16ed54 ldr r2, [r4, #0x10] */
/* @0x16ed58 cmp r3, r2 */
/* @0x16ed5c beq 0x16ed78 <_ZN14CCameraManager15AddCameraToListEP7CCamerai+0x5c> */
/* @0x16ed60 ldr r2, [r4, #0xc] */
/* @0x16ed64 add r1, r3, #1 */
/* @0x16ed68 str r1, [r4, #0x14] */
/* @0x16ed6c str r5, [r2, r3, lsl #2] */
/* @0x16ed70 add sp, sp, #12 */
/* @0x16ed74 pop {r4, r5, pc} */
/* @0x16ed78 lsl r2, r3, #1 */
/* @0x16ed7c str r2, [r4, #0x10] */
/* @0x16ed80 ldr r2, [pc, #0x28] */
/* @0x16ed84 lsl r1, r3, #3 */
/* @0x16ed88 ldr r0, [r4, #0xc] */
/* @0x16ed8c mov r3, #0 */
/* @0x16ed90 add r2, pc, r2 */
/* @0x16ed94 str r3, [sp] */
/* @0x16ed98 mov r3, #74 */
/* @0x16ed9c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x16eda0 ldr r3, [r4, #0x14] */
/* @0x16eda4 mov r2, r0 */
/* @0x16eda8 str r0, [r4, #0xc] */
/* @0x16edac b 0x16ed64 <_ZN14CCameraManager15AddCameraToListEP7CCamerai+0x48> */
/* @0x16edb0 andseq r2, r12, r0, lsr #5 */

/* ── FUNC 0x16edb4 · CCameraManager::CreateCamera() · size=72 · insn=18 */
/* @0x16edb4 ldr r1, [pc, #0x3c] */
/* @0x16edb8 movw r2, #0x803 */
/* @0x16edbc push {r3, r4, r5, lr} */
/* @0x16edc0 add r1, pc, r1 */
/* @0x16edc4 mov r5, r0 */
/* @0x16edc8 mov r3, #1 */
/* @0x16edcc mov r0, #444 */
/* @0x16edd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x16edd4 subs r4, r0, #0 */
/* @0x16edd8 beq 0x16ede0 <_ZN14CCameraManager12CreateCameraEv+0x2c> */
/* @0x16eddc bl 0x16cfc0 <_ZN7CCameraC2Ev> */
/* @0x16ede0 mov r0, r5 */
/* @0x16ede4 mov r1, r4 */
/* @0x16ede8 mvn r2, #0 */
/* @0x16edec bl 0x16ed1c <_ZN14CCameraManager15AddCameraToListEP7CCamerai> */
/* @0x16edf0 mov r0, r4 */
/* @0x16edf4 pop {r3, r4, r5, pc} */
/* @0x16edf8 mulseq sp, r8, r10 */

/* ── FUNC 0x16edfc · F_CameraCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x16edfc cmp r3, #0 */
/* @0x16ee00 mov r3, #0 */
/* @0x16ee04 push {r4, lr} */
/* @0x16ee08 mov r1, r3 */
/* @0x16ee0c mov r4, r0 */
/* @0x16ee10 movt r3, #0xbff0 */
/* @0x16ee14 str r1, [r0, #0xc] */
/* @0x16ee18 stm r0, {r1, r3} */
/* @0x16ee1c bne 0x16ee4c <_Z14F_CameraCreateR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x16ee20 ldr r0, [pc, #0x34] */
/* @0x16ee24 ldr r0, [pc, r0] */
/* @0x16ee28 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv> */
/* @0x16ee2c bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16ee30 vmov s15, r0 */
/* @0x16ee34 vcvt.f64.s32 d7, s15 */
/* @0x16ee38 vmov r0, r1, d7 */
/* @0x16ee3c vmov r2, s14 */
/* @0x16ee40 mov r3, r1 */
/* @0x16ee44 stm r4, {r2, r3} */
/* @0x16ee48 pop {r4, pc} */
/* @0x16ee4c ldr r0, [pc, #0xc] */
/* @0x16ee50 pop {r4, lr} */
/* @0x16ee54 add r0, pc, r0 */
/* @0x16ee58 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16ee5c eoreq lr, r7, r0, asr lr */
/* @0x16ee60 andseq r11, sp, r0, ror lr */

/* ── FUNC 0x16ee64 · F_CameraCreateView(RValue&, CInstance*, CInstance*, int, RValue*) · size=676 · insn=169 */
/* @0x16ee64 cmp r3, #3 */
/* @0x16ee68 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16ee6c vpush {d8, d9} */
/* @0x16ee70 mov r8, r3 */
/* @0x16ee74 mov r3, #0 */
/* @0x16ee78 mov r5, r0 */
/* @0x16ee7c mov r6, r3 */
/* @0x16ee80 ldr r7, [sp, #0x38] */
/* @0x16ee84 movt r3, #0xbff0 */
/* @0x16ee88 str r6, [r0, #0xc] */
/* @0x16ee8c str r3, [r0, #0x4] */
/* @0x16ee90 str r6, [r0] */
/* @0x16ee94 ble 0x16f000 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x16ee98 ldr r0, [pc, #0x260] */
/* @0x16ee9c ldr r0, [pc, r0] */
/* @0x16eea0 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv> */
/* @0x16eea4 mov r4, r0 */
/* @0x16eea8 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x16eeac cmp r4, #0 */
/* @0x16eeb0 vmov s15, r0 */
/* @0x16eeb4 vcvt.f64.s32 d7, s15 */
/* @0x16eeb8 vmov r0, r1, d7 */
/* @0x16eebc vmov r2, s14 */
/* @0x16eec0 mov r3, r1 */
/* @0x16eec4 stm r5, {r2, r3} */
/* @0x16eec8 beq 0x16f018 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x16eecc mov r1, r6 */
/* @0x16eed0 mov r0, r7 */
/* @0x16eed4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eed8 mov r1, r0 */
/* @0x16eedc mov r0, r4 */
/* @0x16eee0 bl 0x16d29c <_ZN7CCamera8SetViewXEf> */
/* @0x16eee4 mov r1, #1 */
/* @0x16eee8 mov r0, r7 */
/* @0x16eeec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16eef0 mov r1, r0 */
/* @0x16eef4 mov r0, r4 */
/* @0x16eef8 bl 0x16d2ac <_ZN7CCamera8SetViewYEf> */
/* @0x16eefc mov r1, #2 */
/* @0x16ef00 mov r0, r7 */
/* @0x16ef04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16ef08 mov r1, r0 */
/* @0x16ef0c mov r0, r4 */
/* @0x16ef10 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf> */
/* @0x16ef14 mov r1, #3 */
/* @0x16ef18 mov r0, r7 */
/* @0x16ef1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16ef20 mov r1, r0 */
/* @0x16ef24 mov r0, r4 */
/* @0x16ef28 bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf> */
/* @0x16ef2c cmp r8, #4 */
/* @0x16ef30 moveq r6, #0 */
/* @0x16ef34 bne 0x16f06c <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x16ef38 mvn r9, #0 */
/* @0x16ef3c mov r10, #0 */
/* @0x16ef40 movt r10, #0xbf80 */
/* @0x16ef44 mov r11, #0 */
/* @0x16ef48 movt r11, #0xbf80 */
/* @0x16ef4c mov r5, #0 */
/* @0x16ef50 mov r7, r5 */
/* @0x16ef54 mov r1, r6 */
/* @0x16ef58 mov r0, r4 */
/* @0x16ef5c bl 0x16d31c <_ZN7CCamera12SetViewAngleEf> */
/* @0x16ef60 mov r0, r4 */
/* @0x16ef64 mov r1, r9 */
/* @0x16ef68 vmov.f32 s17, #5.000000e-01 */
/* @0x16ef6c bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi> */
/* @0x16ef70 mov r0, r4 */
/* @0x16ef74 mov r1, r10 */
/* @0x16ef78 bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf> */
/* @0x16ef7c mov r0, r4 */
/* @0x16ef80 mov r1, r11 */
/* @0x16ef84 bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf> */
/* @0x16ef88 mov r0, r4 */
/* @0x16ef8c mov r1, r5 */
/* @0x16ef90 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf> */
/* @0x16ef94 mov r0, r4 */
/* @0x16ef98 mov r1, r7 */
/* @0x16ef9c bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf> */
/* @0x16efa0 mov r0, r4 */
/* @0x16efa4 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv> */
/* @0x16efa8 cmp r0, #0 */
/* @0x16efac mov r0, r4 */
/* @0x16efb0 bne 0x16f020 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x16efb4 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv> */
/* @0x16efb8 vmov s16, r0 */
/* @0x16efbc mov r0, r4 */
/* @0x16efc0 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv> */
/* @0x16efc4 vmov s14, r0 */
/* @0x16efc8 mov r0, r4 */
/* @0x16efcc vmla.f32 s16, s14, s17 */
/* @0x16efd0 bl 0x16d2b4 <_ZN7CCamera8GetViewYEv> */
/* @0x16efd4 vmov s18, r0 */
/* @0x16efd8 mov r0, r4 */
/* @0x16efdc bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv> */
/* @0x16efe0 vmov r1, s16 */
/* @0x16efe4 vmov s15, r0 */
/* @0x16efe8 mov r0, r4 */
/* @0x16efec vmla.f32 s18, s15, s17 */
/* @0x16eff0 vmov r2, s18 */
/* @0x16eff4 vpop {d8, d9} */
/* @0x16eff8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16effc b 0x16dc0c <_ZN7CCamera11Build3DViewEff> */
/* @0x16f000 vpop {d8, d9} */
/* @0x16f004 mov r1, r6 */
/* @0x16f008 ldr r0, [pc, #0xf4] */
/* @0x16f00c add r0, pc, r0 */
/* @0x16f010 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16f014 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x16f018 vpop {d8, d9} */
/* @0x16f01c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x16f020 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv> */
/* @0x16f024 vmov s16, r0 */
/* @0x16f028 mov r0, r4 */
/* @0x16f02c bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv> */
/* @0x16f030 vmov s14, r0 */
/* @0x16f034 mov r0, r4 */
/* @0x16f038 vmla.f32 s16, s14, s17 */
/* @0x16f03c bl 0x16d2b4 <_ZN7CCamera8GetViewYEv> */
/* @0x16f040 vmov s18, r0 */
/* @0x16f044 mov r0, r4 */
/* @0x16f048 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv> */
/* @0x16f04c vmov r1, s16 */
/* @0x16f050 vmov s15, r0 */
/* @0x16f054 mov r0, r4 */
/* @0x16f058 vmla.f32 s18, s15, s17 */
/* @0x16f05c vmov r2, s18 */
/* @0x16f060 vpop {d8, d9} */
/* @0x16f064 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x16f068 b 0x16db44 <_ZN7CCamera11Build2DViewEff> */
/* @0x16f06c mov r0, r7 */
/* @0x16f070 mov r1, #4 */
/* @0x16f074 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f078 cmp r8, #5 */
/* @0x16f07c mov r6, r0 */
/* @0x16f080 beq 0x16ef38 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x16f084 mov r0, r7 */
/* @0x16f088 mov r1, #5 */
/* @0x16f08c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x16f090 cmp r8, #6 */
/* @0x16f094 mov r9, r0 */
/* @0x16f098 beq 0x16ef3c <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x16f09c mov r0, r7 */
/* @0x16f0a0 mov r1, #6 */
/* @0x16f0a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f0a8 cmp r8, #7 */
/* @0x16f0ac mov r10, r0 */
/* @0x16f0b0 beq 0x16ef44 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x16f0b4 mov r0, r7 */
/* @0x16f0b8 mov r1, #7 */
/* @0x16f0bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f0c0 cmp r8, #8 */
/* @0x16f0c4 mov r11, r0 */
/* @0x16f0c8 beq 0x16ef4c <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x16f0cc mov r0, r7 */
/* @0x16f0d0 mov r1, #8 */
/* @0x16f0d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f0d8 cmp r8, #9 */
/* @0x16f0dc mov r5, r0 */
/* @0x16f0e0 beq 0x16f0f8 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x16f0e4 mov r0, r7 */
/* @0x16f0e8 mov r1, #9 */
/* @0x16f0ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x16f0f0 mov r7, r0 */
/* @0x16f0f4 b 0x16ef54 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x16f0f8 mov r7, #0 */
/* @0x16f0fc b 0x16ef54 <_Z18F_CameraCreateViewR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x16f100 .word 0x0027edd8 */
/* @0x16f104 andseq r11, sp, r8, ror #25 */
