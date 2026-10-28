/* libyoyo.so 覆盖卡组 0237
 * 函数 0x285410..0x2866f0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x285410 · spBone_getWorldRotationX · size=60 · insn=15 */
/* @0x285410 vldr s14, [r0, #64] */
/* @0x285414 vcvt.f64.f32 d6, s14 */
/* @0x285418 vldr s15, [r0, #52] */
/* @0x28541c push {r3, lr} */
/* @0x285420 vmov r0, r1, d6 */
/* @0x285424 vcvt.f64.f32 d6, s15 */
/* @0x285428 vmov r2, r3, d6 */
/* @0x28542c bl 0xb6c70 <atan2@plt> */
/* @0x285430 vldr s15, [pc, #16] */
/* @0x285434 vmov d6, r0, r1 */
/* @0x285438 vcvt.f32.f64 s14, d6 */
/* @0x28543c vmul.f32 s15, s14, s15 */
/* @0x285440 vmov r0, s15 */
/* @0x285444 pop {r3, pc} */
/* @0x285448 rsbmi r2, r5, #224, #28 */

/* ── FUNC 0x28544c · spBone_getWorldRotationY · size=60 · insn=15 */
/* @0x28544c vldr s14, [r0, #68] */
/* @0x285450 vcvt.f64.f32 d6, s14 */
/* @0x285454 vldr s15, [r0, #56] */
/* @0x285458 push {r3, lr} */
/* @0x28545c vmov r0, r1, d6 */
/* @0x285460 vcvt.f64.f32 d6, s15 */
/* @0x285464 vmov r2, r3, d6 */
/* @0x285468 bl 0xb6c70 <atan2@plt> */
/* @0x28546c vldr s15, [pc, #16] */
/* @0x285470 vmov d6, r0, r1 */
/* @0x285474 vcvt.f32.f64 s14, d6 */
/* @0x285478 vmul.f32 s15, s14, s15 */
/* @0x28547c vmov r0, s15 */
/* @0x285480 pop {r3, pc} */
/* @0x285484 rsbmi r2, r5, #224, #28 */

/* ── FUNC 0x285488 · spBone_getWorldScaleX · size=80 · insn=20 */
/* @0x285488 vldr s12, [r0, #56] */
/* @0x28548c vmul.f32 s12, s12, s12 */
/* @0x285490 vldr s15, [r0, #52] */
/* @0x285494 push {r4, lr} */
/* @0x285498 mov r4, r0 */
/* @0x28549c vmla.f32 s12, s15, s15 */
/* @0x2854a0 vcvt.f64.f32 d6, s12 */
/* @0x2854a4 vsqrt.f64 d7, d6 */
/* @0x2854a8 vcmp.f64 d7, d7 */
/* @0x2854ac vmrs APSR_nzcv, fpscr */
/* @0x2854b0 bne 0x2854c8 <spBone_getWorldScaleX+0x40> */
/* @0x2854b4 vcvt.f32.f64 s14, d7 */
/* @0x2854b8 vldr s15, [r4, #76] */
/* @0x2854bc vmul.f32 s15, s14, s15 */
/* @0x2854c0 vmov r0, s15 */
/* @0x2854c4 pop {r4, pc} */
/* @0x2854c8 vmov r0, r1, d6 */
/* @0x2854cc bl 0xb66f4 <sqrt@plt> */
/* @0x2854d0 vmov d7, r0, r1 */
/* @0x2854d4 b 0x2854b4 <spBone_getWorldScaleX+0x2c> */

/* ── FUNC 0x2854d8 · spBone_getWorldScaleY · size=80 · insn=20 */
/* @0x2854d8 vldr s12, [r0, #68] */
/* @0x2854dc vmul.f32 s12, s12, s12 */
/* @0x2854e0 vldr s15, [r0, #64] */
/* @0x2854e4 push {r4, lr} */
/* @0x2854e8 mov r4, r0 */
/* @0x2854ec vmla.f32 s12, s15, s15 */
/* @0x2854f0 vcvt.f64.f32 d6, s12 */
/* @0x2854f4 vsqrt.f64 d7, d6 */
/* @0x2854f8 vcmp.f64 d7, d7 */
/* @0x2854fc vmrs APSR_nzcv, fpscr */
/* @0x285500 bne 0x285518 <spBone_getWorldScaleY+0x40> */
/* @0x285504 vcvt.f32.f64 s14, d7 */
/* @0x285508 vldr s15, [r4, #80] */
/* @0x28550c vmul.f32 s15, s14, s15 */
/* @0x285510 vmov r0, s15 */
/* @0x285514 pop {r4, pc} */
/* @0x285518 vmov r0, r1, d6 */
/* @0x28551c bl 0xb66f4 <sqrt@plt> */
/* @0x285520 vmov d7, r0, r1 */
/* @0x285524 b 0x285504 <spBone_getWorldScaleY+0x2c> */

/* ── FUNC 0x285528 · spBone_worldToLocalRotationX · size=108 · insn=27 */
/* @0x285528 push {r3, lr} */
/* @0x28552c ldr r3, [r0, #0x8] */
/* @0x285530 cmp r3, #0 */
/* @0x285534 vldreq s15, [r0, #28] */
/* @0x285538 beq 0x285588 <spBone_worldToLocalRotationX+0x60> */
/* @0x28553c vldr s13, [r0, #52] */
/* @0x285540 vldr s14, [r3, #64] */
/* @0x285544 vmul.f32 s14, s13, s14 */
/* @0x285548 vldr s12, [r0, #64] */
/* @0x28554c vldr s15, [r3, #56] */
/* @0x285550 vldr s10, [r3, #52] */
/* @0x285554 vldr s11, [r3, #68] */
/* @0x285558 vmul.f32 s15, s12, s15 */
/* @0x28555c vnmls.f32 s14, s12, s10 */
/* @0x285560 vnmls.f32 s15, s13, s11 */
/* @0x285564 vcvt.f64.f32 d6, s14 */
/* @0x285568 vmov r0, r1, d6 */
/* @0x28556c vcvt.f64.f32 d6, s15 */
/* @0x285570 vmov r2, r3, d6 */
/* @0x285574 bl 0xb6c70 <atan2@plt> */
/* @0x285578 vldr s15, [pc, #16] */
/* @0x28557c vmov d6, r0, r1 */
/* @0x285580 vcvt.f32.f64 s14, d6 */
/* @0x285584 vmul.f32 s15, s14, s15 */
/* @0x285588 vmov r0, s15 */
/* @0x28558c pop {r3, pc} */
/* @0x285590 rsbmi r2, r5, #224, #28 */

/* ── FUNC 0x285594 · spBone_worldToLocalRotationY · size=108 · insn=27 */
/* @0x285594 push {r3, lr} */
/* @0x285598 ldr r3, [r0, #0x8] */
/* @0x28559c cmp r3, #0 */
/* @0x2855a0 vldreq s15, [r0, #28] */
/* @0x2855a4 beq 0x2855f4 <spBone_worldToLocalRotationY+0x60> */
/* @0x2855a8 vldr s13, [r0, #56] */
/* @0x2855ac vldr s14, [r3, #64] */
/* @0x2855b0 vmul.f32 s14, s13, s14 */
/* @0x2855b4 vldr s12, [r0, #68] */
/* @0x2855b8 vldr s15, [r3, #56] */
/* @0x2855bc vldr s10, [r3, #52] */
/* @0x2855c0 vldr s11, [r3, #68] */
/* @0x2855c4 vmul.f32 s15, s12, s15 */
/* @0x2855c8 vnmls.f32 s14, s12, s10 */
/* @0x2855cc vnmls.f32 s15, s13, s11 */
/* @0x2855d0 vcvt.f64.f32 d6, s14 */
/* @0x2855d4 vmov r0, r1, d6 */
/* @0x2855d8 vcvt.f64.f32 d6, s15 */
/* @0x2855dc vmov r2, r3, d6 */
/* @0x2855e0 bl 0xb6c70 <atan2@plt> */
/* @0x2855e4 vldr s15, [pc, #16] */
/* @0x2855e8 vmov d6, r0, r1 */
/* @0x2855ec vcvt.f32.f64 s14, d6 */
/* @0x2855f0 vmul.f32 s15, s14, s15 */
/* @0x2855f4 vmov r0, s15 */
/* @0x2855f8 pop {r3, pc} */
/* @0x2855fc rsbmi r2, r5, #224, #28 */

/* ── FUNC 0x285600 · spBone_rotateWorld · size=136 · insn=34 */
/* @0x285600 vmov s10, r1 */
/* @0x285604 push {r4, lr} */
/* @0x285608 vpush {d8, d9, d10, d11} */
/* @0x28560c vldr s16, [pc, #112] */
/* @0x285610 vmul.f32 s16, s10, s16 */
/* @0x285614 vldr s22, [r0, #64] */
/* @0x285618 vldr s21, [r0, #68] */
/* @0x28561c vldr s20, [r0, #52] */
/* @0x285620 vldr s19, [r0, #56] */
/* @0x285624 mov r4, r0 */
/* @0x285628 vcvt.f64.f32 d8, s16 */
/* @0x28562c vmov r0, r1, d8 */
/* @0x285630 bl 0xb67e4 <cos@plt> */
/* @0x285634 vmov d7, r0, r1 */
/* @0x285638 vmov r0, r1, d8 */
/* @0x28563c vcvt.f32.f64 s18, d7 */
/* @0x285640 bl 0xb67d8 <sin@plt> */
/* @0x285644 vmul.f32 s12, s18, s22 */
/* @0x285648 vmul.f32 s14, s18, s21 */
/* @0x28564c vmov d5, r0, r1 */
/* @0x285650 vcvt.f32.f64 s15, d5 */
/* @0x285654 vmul.f32 s11, s15, s22 */
/* @0x285658 vmul.f32 s13, s15, s21 */
/* @0x28565c vnmls.f32 s11, s18, s20 */
/* @0x285660 vmla.f32 s12, s15, s20 */
/* @0x285664 vstr s11, [r4, #52] */
/* @0x285668 vnmls.f32 s13, s18, s19 */
/* @0x28566c vstr s12, [r4, #64] */
/* @0x285670 vmla.f32 s14, s15, s19 */
/* @0x285674 vstr s13, [r4, #56] */
/* @0x285678 vpop {d8, d9, d10, d11} */
/* @0x28567c vstr s14, [r4, #68] */
/* @0x285680 pop {r4, pc} */
/* @0x285684 vstmialo lr, {s30, s31} */

/* ── FUNC 0x285688 · spBone_updateLocalTransform · size=780 · insn=195 */
/* @0x285688 ldr r3, [r0, #0x8] */
/* @0x28568c push {r4, lr} */
/* @0x285690 vpush {d8, d9, d10} */
/* @0x285694 cmp r3, #0 */
/* @0x285698 mov r4, r0 */
/* @0x28569c beq 0x285850 <spBone_updateLocalTransform+0x1c8> */
/* @0x2856a0 vldr s9, [r3, #56] */
/* @0x2856a4 vldr s10, [r3, #64] */
/* @0x2856a8 vmul.f32 s15, s9, s10 */
/* @0x2856ac vldr s7, [r3, #52] */
/* @0x2856b0 vldr s8, [r3, #68] */
/* @0x2856b4 vldr s14, [r0, #52] */
/* @0x2856b8 vldr s17, [r0, #64] */
/* @0x2856bc vldr s1, [r3, #72] */
/* @0x2856c0 vldr s2, [r3, #60] */
/* @0x2856c4 vldr s20, [r0, #72] */
/* @0x2856c8 vldr s0, [r0, #60] */
/* @0x2856cc vldr s6, [r0, #68] */
/* @0x2856d0 vldr s3, [r0, #56] */
/* @0x2856d4 mov r3, #0 */
/* @0x2856d8 str r3, [r0, #0x28] */
/* @0x2856dc vnmls.f32 s15, s7, s8 */
/* @0x2856e0 vmov.f32 s11, #1.000000e+00 */
/* @0x2856e4 vdiv.f32 s11, s11, s15 */
/* @0x2856e8 vmul.f32 s19, s11, s10 */
/* @0x2856ec vmul.f32 s18, s11, s9 */
/* @0x2856f0 vmul.f32 s5, s11, s7 */
/* @0x2856f4 vmul.f32 s16, s19, s14 */
/* @0x2856f8 vmul.f32 s4, s11, s8 */
/* @0x2856fc vnmls.f32 s16, s5, s17 */
/* @0x285700 vmul.f32 s17, s17, s18 */
/* @0x285704 vnmls.f32 s17, s14, s4 */
/* @0x285708 vmul.f32 s12, s16, s16 */
/* @0x28570c vmla.f32 s12, s17, s17 */
/* @0x285710 vcvt.f64.f32 d6, s12 */
/* @0x285714 vsqrt.f64 d7, d6 */
/* @0x285718 vsub.f32 s1, s20, s1 */
/* @0x28571c vsub.f32 s2, s0, s2 */
/* @0x285720 vmul.f32 s9, s1, s9 */
/* @0x285724 vmul.f32 s10, s2, s10 */
/* @0x285728 vmul.f32 s9, s9, s11 */
/* @0x28572c vmul.f32 s7, s1, s7 */
/* @0x285730 vmul.f32 s8, s2, s8 */
/* @0x285734 vmul.f32 s10, s10, s11 */
/* @0x285738 vnmls.f32 s9, s8, s11 */
/* @0x28573c vnmls.f32 s10, s7, s11 */
/* @0x285740 vstr s9, [r0, #20] */
/* @0x285744 vmul.f32 s18, s6, s18 */
/* @0x285748 vstr s10, [r0, #24] */
/* @0x28574c vmul.f32 s19, s19, s3 */
/* @0x285750 vcmp.f64 d7, d7 */
/* @0x285754 vnmls.f32 s18, s3, s4 */
/* @0x285758 vmrs APSR_nzcv, fpscr */
/* @0x28575c vnmls.f32 s19, s5, s6 */
/* @0x285760 bne 0x285940 <spBone_updateLocalTransform+0x2b8> */
/* @0x285764 vcvt.f32.f64 s14, d7 */
/* @0x285768 vldr s15, [pc, #536] */
/* @0x28576c vcmpe.f32 s14, s15 */
/* @0x285770 vstr s14, [r4, #32] */
/* @0x285774 vmrs APSR_nzcv, fpscr */
/* @0x285778 bgt 0x2857e8 <spBone_updateLocalTransform+0x160> */
/* @0x28577c vmul.f32 s12, s19, s19 */
/* @0x285780 mov r3, #0 */
/* @0x285784 str r3, [r4, #0x20] */
/* @0x285788 vmla.f32 s12, s18, s18 */
/* @0x28578c vcvt.f64.f32 d6, s12 */
/* @0x285790 vsqrt.f64 d7, d6 */
/* @0x285794 vcmp.f64 d7, d7 */
/* @0x285798 vmrs APSR_nzcv, fpscr */
/* @0x28579c bne 0x285950 <spBone_updateLocalTransform+0x2c8> */
/* @0x2857a0 vcvt.f32.f64 s14, d7 */
/* @0x2857a4 mov r3, #0 */
/* @0x2857a8 str r3, [r4, #0x2c] */
/* @0x2857ac vstr s14, [r4, #36] */
/* @0x2857b0 vcvt.f64.f32 d4, s18 */
/* @0x2857b4 vcvt.f64.f32 d7, s19 */
/* @0x2857b8 vmov r2, r3, d4 */
/* @0x2857bc vmov r0, r1, d7 */
/* @0x2857c0 bl 0xb6c70 <atan2@plt> */
/* @0x2857c4 vldr s14, [pc, #448] */
/* @0x2857c8 vldr s15, [pc, #448] */
/* @0x2857cc vmov d5, r0, r1 */
/* @0x2857d0 vcvt.f32.f64 s13, d5 */
/* @0x2857d4 vmls.f32 s15, s13, s14 */
/* @0x2857d8 vstr s15, [r4, #28] */
/* @0x2857dc vpop {d8, d9, d10} */
/* @0x2857e0 vstr s15, [r4, #48] */
/* @0x2857e4 pop {r4, pc} */
/* @0x2857e8 vmul.f32 s13, s18, s16 */
/* @0x2857ec vldr s20, [pc, #408] */
/* @0x2857f0 vnmls.f32 s13, s17, s19 */
/* @0x2857f4 vmul.f32 s19, s16, s19 */
/* @0x2857f8 vdiv.f32 s14, s13, s14 */
/* @0x2857fc vmla.f32 s19, s17, s18 */
/* @0x285800 vstr s14, [r4, #36] */
/* @0x285804 vcvt.f64.f32 d5, s13 */
/* @0x285808 vcvt.f64.f32 d6, s19 */
/* @0x28580c vmov r2, r3, d5 */
/* @0x285810 vmov r0, r1, d6 */
/* @0x285814 bl 0xb6c70 <atan2@plt> */
/* @0x285818 vcvt.f64.f32 d7, s17 */
/* @0x28581c vmov r2, r3, d7 */
/* @0x285820 vcvt.f64.f32 d5, s16 */
/* @0x285824 vmov d4, r0, r1 */
/* @0x285828 vcvt.f32.f64 s15, d4 */
/* @0x28582c vmov r0, r1, d5 */
/* @0x285830 vmul.f32 s15, s15, s20 */
/* @0x285834 vstr s15, [r4, #44] */
/* @0x285838 bl 0xb6c70 <atan2@plt> */
/* @0x28583c vmov d6, r0, r1 */
/* @0x285840 vcvt.f32.f64 s15, d6 */
/* @0x285844 vmul.f32 s15, s15, s20 */
/* @0x285848 vstr s15, [r4, #28] */
/* @0x28584c b 0x2857dc <spBone_updateLocalTransform+0x154> */
/* @0x285850 vldr s14, [r0, #64] */
/* @0x285854 vldr s16, [r0, #56] */
/* @0x285858 vmul.f32 s16, s14, s16 */
/* @0x28585c vldr s15, [r0, #52] */
/* @0x285860 ldr r2, [r0, #0x3c] */
/* @0x285864 vldr s13, [r0, #68] */
/* @0x285868 ldr r3, [r0, #0x48] */
/* @0x28586c str r2, [r0, #0x14] */
/* @0x285870 str r3, [r0, #0x18] */
/* @0x285874 vcvt.f64.f32 d5, s15 */
/* @0x285878 vcvt.f64.f32 d4, s14 */
/* @0x28587c vmov r2, r3, d5 */
/* @0x285880 vmov r0, r1, d4 */
/* @0x285884 vnmls.f32 s16, s15, s13 */
/* @0x285888 bl 0xb6c70 <atan2@plt> */
/* @0x28588c vldr s14, [r4, #64] */
/* @0x285890 vldr s15, [r4, #52] */
/* @0x285894 vldr s11, [pc, #240] */
/* @0x285898 vmul.f32 s14, s14, s14 */
/* @0x28589c vmov d4, r0, r1 */
/* @0x2858a0 vmla.f32 s14, s15, s15 */
/* @0x2858a4 vcvt.f64.f32 d7, s14 */
/* @0x2858a8 vsqrt.f64 d6, d7 */
/* @0x2858ac vcvt.f32.f64 s10, d4 */
/* @0x2858b0 vmul.f32 s11, s10, s11 */
/* @0x2858b4 vcmp.f64 d6, d6 */
/* @0x2858b8 vstr s11, [r4, #28] */
/* @0x2858bc vmrs APSR_nzcv, fpscr */
/* @0x2858c0 bne 0x285978 <spBone_updateLocalTransform+0x2f0> */
/* @0x2858c4 vldr s8, [r4, #68] */
/* @0x2858c8 vmul.f32 s10, s8, s8 */
/* @0x2858cc vldr s9, [r4, #56] */
/* @0x2858d0 vmla.f32 s10, s9, s9 */
/* @0x2858d4 vcvt.f64.f32 d5, s10 */
/* @0x2858d8 vsqrt.f64 d7, d5 */
/* @0x2858dc vcvt.f32.f64 s12, d6 */
/* @0x2858e0 vcmp.f64 d7, d7 */
/* @0x2858e4 vstr s12, [r4, #32] */
/* @0x2858e8 vmrs APSR_nzcv, fpscr */
/* @0x2858ec bne 0x285960 <spBone_updateLocalTransform+0x2d8> */
/* @0x2858f0 vldr s13, [r4, #64] */
/* @0x2858f4 vmul.f32 s8, s13, s8 */
/* @0x2858f8 vldr s13, [r4, #52] */
/* @0x2858fc mov r3, #0 */
/* @0x285900 str r3, [r4, #0x28] */
/* @0x285904 vmla.f32 s8, s13, s9 */
/* @0x285908 vcvt.f32.f64 s14, d7 */
/* @0x28590c vcvt.f64.f32 d5, s8 */
/* @0x285910 vstr s14, [r4, #36] */
/* @0x285914 vcvt.f64.f32 d6, s16 */
/* @0x285918 vmov r0, r1, d5 */
/* @0x28591c vmov r2, r3, d6 */
/* @0x285920 bl 0xb6c70 <atan2@plt> */
/* @0x285924 vldr s15, [pc, #96] */
/* @0x285928 vpop {d8, d9, d10} */
/* @0x28592c vmov d4, r0, r1 */
/* @0x285930 vcvt.f32.f64 s14, d4 */
/* @0x285934 vmul.f32 s15, s14, s15 */
/* @0x285938 vstr s15, [r4, #44] */
/* @0x28593c pop {r4, pc} */
/* @0x285940 vmov r0, r1, d6 */
/* @0x285944 bl 0xb66f4 <sqrt@plt> */
/* @0x285948 vmov d7, r0, r1 */
/* @0x28594c b 0x285764 <spBone_updateLocalTransform+0xdc> */
/* @0x285950 vmov r0, r1, d6 */
/* @0x285954 bl 0xb66f4 <sqrt@plt> */
/* @0x285958 vmov d7, r0, r1 */
/* @0x28595c b 0x2857a0 <spBone_updateLocalTransform+0x118> */
/* @0x285960 vmov r0, r1, d5 */
/* @0x285964 bl 0xb66f4 <sqrt@plt> */
/* @0x285968 vldr s8, [r4, #68] */
/* @0x28596c vldr s9, [r4, #56] */
/* @0x285970 vmov d7, r0, r1 */
/* @0x285974 b 0x2858f0 <spBone_updateLocalTransform+0x268> */
/* @0x285978 vmov r0, r1, d7 */
/* @0x28597c bl 0xb66f4 <sqrt@plt> */
/* @0x285980 vmov d6, r0, r1 */
/* @0x285984 b 0x2858c4 <spBone_updateLocalTransform+0x23c> */
/* @0x285988 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x28598c rsbmi r2, r5, #224, #28 */
/* @0x285990 adcsmi r0, r4, #0 */

/* ── FUNC 0x285994 · spBone_worldToLocal · size=104 · insn=26 */
/* @0x285994 vldr s13, [r0, #56] */
/* @0x285998 vldr s14, [r0, #64] */
/* @0x28599c vmul.f32 s15, s13, s14 */
/* @0x2859a0 vldr s10, [r0, #52] */
/* @0x2859a4 vldr s12, [r0, #68] */
/* @0x2859a8 vldr s9, [r0, #72] */
/* @0x2859ac vldr s11, [r0, #60] */
/* @0x2859b0 ldr r0, [sp] */
/* @0x2859b4 vnmls.f32 s15, s10, s12 */
/* @0x2859b8 vmov.f32 s8, #1.000000e+00 */
/* @0x2859bc vdiv.f32 s15, s8, s15 */
/* @0x2859c0 vmov s8, r2 */
/* @0x2859c4 vsub.f32 s9, s8, s9 */
/* @0x2859c8 vmov s8, r1 */
/* @0x2859cc vsub.f32 s11, s8, s11 */
/* @0x2859d0 vmul.f32 s13, s9, s13 */
/* @0x2859d4 vmul.f32 s14, s11, s14 */
/* @0x2859d8 vmul.f32 s13, s13, s15 */
/* @0x2859dc vmul.f32 s10, s9, s10 */
/* @0x2859e0 vmul.f32 s12, s11, s12 */
/* @0x2859e4 vmul.f32 s14, s14, s15 */
/* @0x2859e8 vnmls.f32 s13, s12, s15 */
/* @0x2859ec vnmls.f32 s14, s10, s15 */
/* @0x2859f0 vstr s13, [r3] */
/* @0x2859f4 vstr s14, [r0] */
/* @0x2859f8 bx lr */

/* ── FUNC 0x2859fc · spBone_localToWorld · size=72 · insn=18 */
/* @0x2859fc vmov s15, r2 */
/* @0x285a00 vldr s14, [r0, #56] */
/* @0x285a04 vmov s13, r1 */
/* @0x285a08 vldr s11, [r0, #52] */
/* @0x285a0c vmul.f32 s14, s15, s14 */
/* @0x285a10 vldr s12, [r0, #60] */
/* @0x285a14 ldr r2, [sp] */
/* @0x285a18 vmla.f32 s14, s13, s11 */
/* @0x285a1c vadd.f32 s14, s14, s12 */
/* @0x285a20 vstr s14, [r3] */
/* @0x285a24 vldr s14, [r0, #68] */
/* @0x285a28 vmul.f32 s15, s15, s14 */
/* @0x285a2c vldr s12, [r0, #64] */
/* @0x285a30 vldr s14, [r0, #72] */
/* @0x285a34 vmla.f32 s15, s13, s12 */
/* @0x285a38 vadd.f32 s15, s15, s14 */
/* @0x285a3c vstr s15, [r2] */
/* @0x285a40 bx lr */

/* ── FUNC 0x285a44 · spBoneData_create · size=128 · insn=32 */
/* @0x285a44 push {r4, r5, r6, r7, r8, lr} */
/* @0x285a48 mov r3, #36 */
/* @0x285a4c ldr r6, [pc, #0x6c] */
/* @0x285a50 mov r5, r1 */
/* @0x285a54 mov r8, r0 */
/* @0x285a58 mov r7, r2 */
/* @0x285a5c add r6, pc, r6 */
/* @0x285a60 mov r1, #52 */
/* @0x285a64 mov r0, #1 */
/* @0x285a68 mov r2, r6 */
/* @0x285a6c bl 0x285c4c <_calloc> */
/* @0x285a70 mov r4, r0 */
/* @0x285a74 str r8, [r0] */
/* @0x285a78 mov r0, r5 */
/* @0x285a7c bl 0xb6538 <strlen@plt> */
/* @0x285a80 mov r1, r6 */
/* @0x285a84 mov r2, #38 */
/* @0x285a88 add r0, r0, #1 */
/* @0x285a8c bl 0x285c10 <_malloc> */
/* @0x285a90 mov r1, r5 */
/* @0x285a94 str r0, [r4, #0x4] */
/* @0x285a98 bl 0xb65a4 <strcpy@plt> */
/* @0x285a9c mov r1, #1065353216 */
/* @0x285aa0 mov r3, #1 */
/* @0x285aa4 str r7, [r4, #0x8] */
/* @0x285aa8 mov r0, r4 */
/* @0x285aac str r3, [r4, #0x2c] */
/* @0x285ab0 str r3, [r4, #0x30] */
/* @0x285ab4 str r1, [r4, #0x1c] */
/* @0x285ab8 str r1, [r4, #0x20] */
/* @0x285abc pop {r4, r5, r6, r7, r8, pc} */
/* @0x285ac0 andeq r1, sp, r0, asr #25 */

/* ── FUNC 0x285ac4 · spBoneData_dispose · size=28 · insn=7 */
/* @0x285ac4 push {r4, lr} */
/* @0x285ac8 mov r4, r0 */
/* @0x285acc ldr r0, [r0, #0x4] */
/* @0x285ad0 bl 0x285c80 <_free> */
/* @0x285ad4 mov r0, r4 */
/* @0x285ad8 pop {r4, lr} */
/* @0x285adc b 0x285c80 <_free> */

/* ── FUNC 0x285ae0 · _spBoundingBoxAttachment_dispose · size=24 · insn=6 */
/* @0x285ae0 push {r4, lr} */
/* @0x285ae4 mov r4, r0 */
/* @0x285ae8 bl 0x28f62c <_spVertexAttachment_deinit> */
/* @0x285aec mov r0, r4 */
/* @0x285af0 pop {r4, lr} */
/* @0x285af4 b 0x285c80 <_free> */

/* ── FUNC 0x285af8 · spBoundingBoxAttachment_create · size=72 · insn=18 */
/* @0x285af8 ldr r2, [pc, #0x38] */
/* @0x285afc mov r1, #36 */
/* @0x285b00 push {r3, r4, r5, lr} */
/* @0x285b04 add r2, pc, r2 */
/* @0x285b08 mov r5, r0 */
/* @0x285b0c mov r3, #44 */
/* @0x285b10 mov r0, #1 */
/* @0x285b14 bl 0x285c4c <_calloc> */
/* @0x285b18 ldr r3, [pc, #0x1c] */
/* @0x285b1c mov r1, r5 */
/* @0x285b20 mov r2, #1 */
/* @0x285b24 ldr r3, [pc, r3] */
/* @0x285b28 mov r4, r0 */
/* @0x285b2c bl 0x284c18 <_spAttachment_init> */
/* @0x285b30 mov r0, r4 */
/* @0x285b34 pop {r3, r4, r5, pc} */
/* @0x285b38 andeq r1, sp, r0, asr r12 */
/* @0x285b3c ldrsbeq r11, [r6], -r8 */

/* ── FUNC 0x285b40 · spBoundingBoxAttachment_computeWorldVertices · size=4 · insn=1 */
/* @0x285b40 b 0x28fa08 <spVertexAttachment_computeWorldVertices> */

/* ── FUNC 0x285b44 · spEvent_create · size=52 · insn=13 */
/* @0x285b44 ldr r2, [pc, #0x28] */
/* @0x285b48 push {r3, r4, r5, lr} */
/* @0x285b4c add r2, pc, r2 */
/* @0x285b50 mov r4, r0 */
/* @0x285b54 mov r5, r1 */
/* @0x285b58 mov r3, #36 */
/* @0x285b5c mov r1, #20 */
/* @0x285b60 mov r0, #1 */
/* @0x285b64 bl 0x285c4c <_calloc> */
/* @0x285b68 str r5, [r0] */
/* @0x285b6c str r4, [r0, #0x4] */
/* @0x285b70 pop {r3, r4, r5, pc} */
/* @0x285b74 andeq r1, sp, r12, asr #24 */

/* ── FUNC 0x285b78 · spEvent_dispose · size=28 · insn=7 */
/* @0x285b78 push {r4, lr} */
/* @0x285b7c mov r4, r0 */
/* @0x285b80 ldr r0, [r0, #0x10] */
/* @0x285b84 bl 0x285c80 <_free> */
/* @0x285b88 mov r0, r4 */
/* @0x285b8c pop {r4, lr} */
/* @0x285b90 b 0x285c80 <_free> */

/* ── FUNC 0x285b94 · spEventData_create · size=88 · insn=22 */
/* @0x285b94 push {r4, r5, r6, lr} */
/* @0x285b98 mov r3, #36 */
/* @0x285b9c ldr r6, [pc, #0x44] */
/* @0x285ba0 mov r5, r0 */
/* @0x285ba4 mov r1, #16 */
/* @0x285ba8 mov r0, #1 */
/* @0x285bac add r6, pc, r6 */
/* @0x285bb0 mov r2, r6 */
/* @0x285bb4 bl 0x285c4c <_calloc> */
/* @0x285bb8 mov r4, r0 */
/* @0x285bbc mov r0, r5 */
/* @0x285bc0 bl 0xb6538 <strlen@plt> */
/* @0x285bc4 mov r1, r6 */
/* @0x285bc8 mov r2, #37 */
/* @0x285bcc add r0, r0, #1 */
/* @0x285bd0 bl 0x285c10 <_malloc> */
/* @0x285bd4 mov r1, r5 */
/* @0x285bd8 str r0, [r4] */
/* @0x285bdc bl 0xb65a4 <strcpy@plt> */
/* @0x285be0 mov r0, r4 */
/* @0x285be4 pop {r4, r5, r6, pc} */
/* @0x285be8 andeq r1, sp, r0, lsr #24 */

/* ── FUNC 0x285bec · spEventData_dispose · size=36 · insn=9 */
/* @0x285bec push {r4, lr} */
/* @0x285bf0 mov r4, r0 */
/* @0x285bf4 ldr r0, [r0, #0xc] */
/* @0x285bf8 bl 0x285c80 <_free> */
/* @0x285bfc ldr r0, [r4] */
/* @0x285c00 bl 0x285c80 <_free> */
/* @0x285c04 mov r0, r4 */
/* @0x285c08 pop {r4, lr} */
/* @0x285c0c b 0x285c80 <_free> */

/* ── FUNC 0x285c10 · _malloc · size=60 · insn=15 */
/* @0x285c10 push {r3, lr} */
/* @0x285c14 ldr r3, [pc, #0x28] */
/* @0x285c18 add r3, pc, r3 */
/* @0x285c1c ldr r3, [r3] */
/* @0x285c20 cmp r3, #0 */
/* @0x285c24 beq 0x285c30 <_malloc+0x20> */
/* @0x285c28 blx r3 */
/* @0x285c2c pop {r3, pc} */
/* @0x285c30 ldr r3, [pc, #0x10] */
/* @0x285c34 add r3, pc, r3 */
/* @0x285c38 ldr r3, [r3] */
/* @0x285c3c blx r3 */
/* @0x285c40 pop {r3, pc} */
/* @0x285c44 subeq r0, sp, r4, lsr #31 */
/* @0x285c48 andseq r1, r7, r4, asr r11 */

/* ── FUNC 0x285c4c · _calloc · size=52 · insn=13 */
/* @0x285c4c push {r3, r4, r5, lr} */
/* @0x285c50 mul r4, r1, r0 */
/* @0x285c54 mov r1, r2 */
/* @0x285c58 mov r2, r3 */
/* @0x285c5c mov r0, r4 */
/* @0x285c60 bl 0x285c10 <_malloc> */
/* @0x285c64 subs r5, r0, #0 */
/* @0x285c68 beq 0x285c78 <_calloc+0x2c> */
/* @0x285c6c mov r2, r4 */
/* @0x285c70 mov r1, #0 */
/* @0x285c74 bl 0xb65b0 <memset@plt> */
/* @0x285c78 mov r0, r5 */
/* @0x285c7c pop {r3, r4, r5, pc} */

/* ── FUNC 0x285c80 · _free · size=28 · insn=7 */
/* @0x285c80 push {r3, lr} */
/* @0x285c84 ldr r3, [pc, #0xc] */
/* @0x285c88 add r3, pc, r3 */
/* @0x285c8c ldr r3, [r3, #0x4] */
/* @0x285c90 blx r3 */
/* @0x285c94 pop {r3, pc} */
/* @0x285c98 andseq r1, r7, r0, lsl #22 */

/* ── FUNC 0x285c9c · _setDebugMalloc · size=20 · insn=5 */
/* @0x285c9c ldr r3, [pc, #0x8] */
/* @0x285ca0 add r3, pc, r3 */
/* @0x285ca4 str r0, [r3] */
/* @0x285ca8 bx lr */
/* @0x285cac subeq r0, sp, r12, lsl pc */

/* ── FUNC 0x285cb0 · _setMalloc · size=20 · insn=5 */
/* @0x285cb0 ldr r3, [pc, #0x8] */
/* @0x285cb4 add r3, pc, r3 */
/* @0x285cb8 str r0, [r3] */
/* @0x285cbc bx lr */
/* @0x285cc0 ldrsbeq r1, [r7], -r4 */

/* ── FUNC 0x285cc4 · _setFree · size=20 · insn=5 */
/* @0x285cc4 ldr r3, [pc, #0x8] */
/* @0x285cc8 add r3, pc, r3 */
/* @0x285ccc str r0, [r3, #0x4] */
/* @0x285cd0 bx lr */
/* @0x285cd4 andseq r1, r7, r0, asr #21 */

/* ── FUNC 0x285cd8 · _readFile · size=140 · insn=35 */
/* @0x285cd8 push {r4, r5, r6, lr} */
/* @0x285cdc mov r5, r1 */
/* @0x285ce0 ldr r1, [pc, #0x74] */
/* @0x285ce4 add r1, pc, r1 */
/* @0x285ce8 bl 0xb6844 <fopen@plt> */
/* @0x285cec subs r4, r0, #0 */
/* @0x285cf0 beq 0x285d54 <_readFile+0x7c> */
/* @0x285cf4 mov r1, #0 */
/* @0x285cf8 mov r2, #2 */
/* @0x285cfc bl 0xb68d4 <fseek@plt> */
/* @0x285d00 mov r0, r4 */
/* @0x285d04 bl 0xb68e0 <ftell@plt> */
/* @0x285d08 mov r1, #0 */
/* @0x285d0c mov r2, r1 */
/* @0x285d10 str r0, [r5] */
/* @0x285d14 mov r0, r4 */
/* @0x285d18 bl 0xb68d4 <fseek@plt> */
/* @0x285d1c ldr r1, [pc, #0x3c] */
/* @0x285d20 ldr r0, [r5] */
/* @0x285d24 mov r2, #74 */
/* @0x285d28 add r1, pc, r1 */
/* @0x285d2c bl 0x285c10 <_malloc> */
/* @0x285d30 ldr r2, [r5] */
/* @0x285d34 mov r1, #1 */
/* @0x285d38 mov r3, r4 */
/* @0x285d3c mov r6, r0 */
/* @0x285d40 bl 0xb68c8 <fread@plt> */
/* @0x285d44 mov r0, r4 */
/* @0x285d48 bl 0xb6850 <fclose@plt> */
/* @0x285d4c mov r0, r6 */
/* @0x285d50 pop {r4, r5, r6, pc} */
/* @0x285d54 mov r0, r4 */
/* @0x285d58 pop {r4, r5, r6, pc} */
/* @0x285d5c andeq r1, r11, r4, lsl pc */
/* @0x285d60 ldrdeq r1, r2, [sp], -r12 */

/* ── FUNC 0x285d64 · spIkConstraint_create · size=200 · insn=50 */
/* @0x285d64 push {r3, r4, r5, r6, r7, lr} */
/* @0x285d68 mov r4, r0 */
/* @0x285d6c ldr r6, [pc, #0xb4] */
/* @0x285d70 mov r3, #40 */
/* @0x285d74 mov r7, r1 */
/* @0x285d78 mov r0, #1 */
/* @0x285d7c add r6, pc, r6 */
/* @0x285d80 mov r1, #28 */
/* @0x285d84 mov r2, r6 */
/* @0x285d88 bl 0x285c4c <_calloc> */
/* @0x285d8c ldr r3, [r4, #0x10] */
/* @0x285d90 ldr r2, [r4, #0x14] */
/* @0x285d94 mov r1, r6 */
/* @0x285d98 mov r5, r0 */
/* @0x285d9c ldr r0, [r4, #0x4] */
/* @0x285da0 str r2, [r5, #0x14] */
/* @0x285da4 mov r2, #46 */
/* @0x285da8 str r3, [r5, #0x10] */
/* @0x285dac str r0, [r5, #0x4] */
/* @0x285db0 lsl r0, r0, #2 */
/* @0x285db4 str r4, [r5] */
/* @0x285db8 bl 0x285c10 <_malloc> */
/* @0x285dbc ldr r3, [r5, #0x4] */
/* @0x285dc0 cmp r3, #0 */
/* @0x285dc4 str r0, [r5, #0x8] */
/* @0x285dc8 ble 0x285e08 <spIkConstraint_create+0xa4> */
/* @0x285dcc mov r6, r0 */
/* @0x285dd0 mov r4, #0 */
/* @0x285dd4 b 0x285ddc <spIkConstraint_create+0x78> */
/* @0x285dd8 ldr r6, [r5, #0x8] */
/* @0x285ddc ldr r3, [r5] */
/* @0x285de0 mov r0, r7 */
/* @0x285de4 ldr r3, [r3, #0x8] */
/* @0x285de8 ldr r3, [r3, r4, lsl #2] */
/* @0x285dec ldr r1, [r3, #0x4] */
/* @0x285df0 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0x285df4 ldr r3, [r5, #0x4] */
/* @0x285df8 str r0, [r6, r4, lsl #2] */
/* @0x285dfc add r4, r4, #1 */
/* @0x285e00 cmp r3, r4 */
/* @0x285e04 bgt 0x285dd8 <spIkConstraint_create+0x74> */
/* @0x285e08 ldr r3, [r5] */
/* @0x285e0c mov r0, r7 */
/* @0x285e10 ldr r3, [r3, #0xc] */
/* @0x285e14 ldr r1, [r3, #0x4] */
/* @0x285e18 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0x285e1c str r0, [r5, #0xc] */
/* @0x285e20 mov r0, r5 */
/* @0x285e24 pop {r3, r4, r5, r6, r7, pc} */
/* @0x285e28 andeq r1, sp, r0, asr #21 */

/* ── FUNC 0x285e2c · spIkConstraint_dispose · size=28 · insn=7 */
/* @0x285e2c push {r4, lr} */
/* @0x285e30 mov r4, r0 */
/* @0x285e34 ldr r0, [r0, #0x8] */
/* @0x285e38 bl 0x285c80 <_free> */
/* @0x285e3c mov r0, r4 */
/* @0x285e40 pop {r4, lr} */
/* @0x285e44 b 0x285c80 <_free> */

/* ── FUNC 0x285e48 · spIkConstraint_apply1 · size=308 · insn=77 */
/* @0x285e48 push {r4, lr} */
/* @0x285e4c vpush {d8} */
/* @0x285e50 mov r4, r0 */
/* @0x285e54 vldr s15, [r4, #24] */
/* @0x285e58 ldr r0, [r0, #0x8] */
/* @0x285e5c vldr s12, [r0, #56] */
/* @0x285e60 vldr s13, [r0, #64] */
/* @0x285e64 vmul.f32 s11, s12, s13 */
/* @0x285e68 vldr s9, [r0, #52] */
/* @0x285e6c vldr s7, [r0, #68] */
/* @0x285e70 vmov s5, r2 */
/* @0x285e74 vldr s10, [r0, #72] */
/* @0x285e78 vldr s8, [r0, #60] */
/* @0x285e7c vldr s14, [r4, #20] */
/* @0x285e80 sub sp, sp, #16 */
/* @0x285e84 vmov s16, r3 */
/* @0x285e88 vnmls.f32 s11, s9, s7 */
/* @0x285e8c vmov.f32 s6, #1.000000e+00 */
/* @0x285e90 vsub.f32 s10, s5, s10 */
/* @0x285e94 vmov s5, r1 */
/* @0x285e98 vsub.f32 s8, s5, s8 */
/* @0x285e9c vdiv.f32 s11, s6, s11 */
/* @0x285ea0 vmul.f32 s12, s12, s10 */
/* @0x285ea4 vmul.f32 s13, s13, s8 */
/* @0x285ea8 vnmls.f32 s12, s7, s8 */
/* @0x285eac vnmls.f32 s13, s9, s10 */
/* @0x285eb0 vnmls.f32 s14, s12, s11 */
/* @0x285eb4 vnmls.f32 s15, s13, s11 */
/* @0x285eb8 vcvt.f64.f32 d4, s14 */
/* @0x285ebc vcvt.f64.f32 d6, s15 */
/* @0x285ec0 vmov r2, r3, d4 */
/* @0x285ec4 vmov r0, r1, d6 */
/* @0x285ec8 bl 0xb6c70 <atan2@plt> */
/* @0x285ecc vldr s13, [r4, #40] */
/* @0x285ed0 vldr s15, [pc, #148] */
/* @0x285ed4 vldr s14, [r4, #28] */
/* @0x285ed8 vldr s12, [r4, #32] */
/* @0x285edc vcmpe.f32 s12, #0 */
/* @0x285ee0 vmrs APSR_nzcv, fpscr */
/* @0x285ee4 vmov d4, r0, r1 */
/* @0x285ee8 vcvt.f32.f64 s11, d4 */
/* @0x285eec vmov.f32 s9, s13 */
/* @0x285ef0 vnmls.f32 s9, s11, s15 */
/* @0x285ef4 vldrmi s11, [pc, #116] */
/* @0x285ef8 vsub.f32 s15, s9, s14 */
/* @0x285efc vaddmi.f32 s15, s15, s11 */
/* @0x285f00 vldr s11, [pc, #104] */
/* @0x285f04 vcmpe.f32 s15, s11 */
/* @0x285f08 vmrs APSR_nzcv, fpscr */
/* @0x285f0c bgt 0x285f60 <spIkConstraint_apply1+0x118> */
/* @0x285f10 vldr s11, [pc, #92] */
/* @0x285f14 vcmpe.f32 s15, s11 */
/* @0x285f18 vmrs APSR_nzcv, fpscr */
/* @0x285f1c vldrmi s11, [pc, #84] */
/* @0x285f20 vaddmi.f32 s15, s15, s11 */
/* @0x285f24 vstr s12, [sp] */
/* @0x285f28 vstr s13, [sp, #8] */
/* @0x285f2c ldr r3, [r4, #0x24] */
/* @0x285f30 mov r0, r4 */
/* @0x285f34 ldr r1, [r4, #0x14] */
/* @0x285f38 ldr r2, [r4, #0x18] */
/* @0x285f3c str r3, [sp, #0x4] */
/* @0x285f40 ldr r3, [r4, #0x2c] */
/* @0x285f44 vmla.f32 s14, s15, s16 */
/* @0x285f48 str r3, [sp, #0xc] */
/* @0x285f4c vmov r3, s14 */
/* @0x285f50 bl 0x284f18 <spBone_updateWorldTransformWith> */
/* @0x285f54 add sp, sp, #16 */
/* @0x285f58 vpop {d8} */
/* @0x285f5c pop {r4, pc} */
/* @0x285f60 vldr s11, [pc, #16] */
/* @0x285f64 vsub.f32 s15, s15, s11 */
/* @0x285f68 b 0x285f24 <spIkConstraint_apply1+0xdc> */
/* @0x285f6c rsbmi r2, r5, #224, #28 */
/* @0x285f70 teqmi r4, #0 */
/* @0x285f74 teqgt r4, #0 */
/* @0x285f78 .word 0x43b40000 */

/* ── FUNC 0x285f7c · spIkConstraint_apply2 · size=1792 · insn=448 */
/* @0x285f7c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x285f80 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x285f84 sub sp, sp, #32 */
/* @0x285f88 vldr s20, [sp, #132] */
/* @0x285f8c vcmp.f32 s20, #0 */
/* @0x285f90 mov r5, r1 */
/* @0x285f94 vldr s19, [r1, #20] */
/* @0x285f98 vldr s24, [r1, #32] */
/* @0x285f9c mov r4, r0 */
/* @0x285fa0 vldr s22, [r0, #20] */
/* @0x285fa4 vldr s21, [r0, #24] */
/* @0x285fa8 vldr s16, [r0, #32] */
/* @0x285fac vldr s17, [r0, #36] */
/* @0x285fb0 ldr r1, [r0, #0x8] */
/* @0x285fb4 vmov s2, r2 */
/* @0x285fb8 ldr r8, [sp, #0x80] */
/* @0x285fbc vmov s3, r3 */
/* @0x285fc0 vmrs APSR_nzcv, fpscr */
/* @0x285fc4 beq 0x286574 <spIkConstraint_apply2+0x5f8> */
/* @0x285fc8 vcmpe.f32 s16, #0 */
/* @0x285fcc vmrs APSR_nzcv, fpscr */
/* @0x285fd0 vcmpe.f32 s17, #0 */
/* @0x285fd4 mvnmi r7, #0 */
/* @0x285fd8 movmi r10, #180 */
/* @0x285fdc movpl r7, #1 */
/* @0x285fe0 movpl r10, #0 */
/* @0x285fe4 vnegmi.f32 s16, s16 */
/* @0x285fe8 vmrs APSR_nzcv, fpscr */
/* @0x285fec rsbmi r7, r7, #0 */
/* @0x285ff0 vnegmi.f32 s17, s17 */
/* @0x285ff4 vsub.f32 s13, s16, s17 */
/* @0x285ff8 vcmpe.f32 s24, #0 */
/* @0x285ffc vmrs APSR_nzcv, fpscr */
/* @0x286000 vcmpe.f32 s13, #0 */
/* @0x286004 movmi r9, #180 */
/* @0x286008 movpl r9, #0 */
/* @0x28600c vnegmi.f32 s24, s24 */
/* @0x286010 vmrs APSR_nzcv, fpscr */
/* @0x286014 bmi 0x28655c <spIkConstraint_apply2+0x5e0> */
/* @0x286018 vldr s15, [pc, #768] */
/* @0x28601c vcmpe.f32 s13, s15 */
/* @0x286020 vmrs APSR_nzcv, fpscr */
/* @0x286024 movhi r6, #0 */
/* @0x286028 movls r6, #1 */
/* @0x28602c cmp r6, #0 */
/* @0x286030 beq 0x2862d0 <spIkConstraint_apply2+0x354> */
/* @0x286034 vldr s23, [r5, #24] */
/* @0x286038 vldr s4, [r4, #56] */
/* @0x28603c vldr s13, [r4, #68] */
/* @0x286040 vmul.f32 s4, s23, s4 */
/* @0x286044 vldr s11, [r4, #52] */
/* @0x286048 vldr s12, [r4, #64] */
/* @0x28604c vldr s14, [r4, #60] */
/* @0x286050 vldr s15, [r4, #72] */
/* @0x286054 vmul.f32 s13, s23, s13 */
/* @0x286058 vmla.f32 s4, s19, s11 */
/* @0x28605c vmla.f32 s13, s19, s12 */
/* @0x286060 vadd.f32 s4, s4, s14 */
/* @0x286064 vadd.f32 s13, s13, s15 */
/* @0x286068 vldr s10, [r1, #56] */
/* @0x28606c vldr s9, [r1, #64] */
/* @0x286070 vldr s7, [r1, #52] */
/* @0x286074 vldr s8, [r1, #68] */
/* @0x286078 vldr s6, [r1, #60] */
/* @0x28607c vldr s5, [r1, #72] */
/* @0x286080 vmul.f32 s12, s10, s9 */
/* @0x286084 vnmls.f32 s12, s7, s8 */
/* @0x286088 vmov.f32 s11, #1.000000e+00 */
/* @0x28608c vsub.f32 s4, s4, s6 */
/* @0x286090 vdiv.f32 s11, s11, s12 */
/* @0x286094 vmul.f32 s12, s9, s4 */
/* @0x286098 vsub.f32 s13, s13, s5 */
/* @0x28609c vnmls.f32 s12, s7, s13 */
/* @0x2860a0 vmul.f32 s13, s10, s13 */
/* @0x2860a4 vnmls.f32 s13, s8, s4 */
/* @0x2860a8 vmov.f32 s14, s21 */
/* @0x2860ac vnmls.f32 s14, s12, s11 */
/* @0x2860b0 vmov.f32 s15, s22 */
/* @0x2860b4 vnmls.f32 s15, s13, s11 */
/* @0x2860b8 vmul.f32 s12, s14, s14 */
/* @0x2860bc vmla.f32 s12, s15, s15 */
/* @0x2860c0 vcvt.f64.f32 d6, s12 */
/* @0x2860c4 vsqrt.f64 d7, d6 */
/* @0x2860c8 vsub.f32 s6, s2, s6 */
/* @0x2860cc vsub.f32 s5, s3, s5 */
/* @0x2860d0 vmul.f32 s9, s9, s6 */
/* @0x2860d4 vmul.f32 s10, s10, s5 */
/* @0x2860d8 vnmls.f32 s9, s7, s5 */
/* @0x2860dc vnmls.f32 s10, s8, s6 */
/* @0x2860e0 vcmp.f64 d7, d7 */
/* @0x2860e4 vmov.f32 s28, s21 */
/* @0x2860e8 vmrs APSR_nzcv, fpscr */
/* @0x2860ec vmov.f32 s25, s22 */
/* @0x2860f0 vnmls.f32 s28, s9, s11 */
/* @0x2860f4 vnmls.f32 s25, s10, s11 */
/* @0x2860f8 bne 0x28664c <spIkConstraint_apply2+0x6d0> */
/* @0x2860fc cmp r6, #0 */
/* @0x286100 ldr r3, [r5] */
/* @0x286104 vldr s29, [r3, #12] */
/* @0x286108 vcvt.f32.f64 s18, d7 */
/* @0x28610c vmul.f32 s29, s24, s29 */
/* @0x286110 beq 0x286344 <spIkConstraint_apply2+0x3c8> */
/* @0x286114 vmul.f32 s15, s28, s28 */
/* @0x286118 vmla.f32 s15, s25, s25 */
/* @0x28611c vmls.f32 s15, s18, s18 */
/* @0x286120 vmul.f32 s16, s29, s16 */
/* @0x286124 vadd.f32 s17, s18, s18 */
/* @0x286128 vmls.f32 s15, s16, s16 */
/* @0x28612c vmul.f32 s17, s17, s16 */
/* @0x286130 vdiv.f32 s17, s15, s17 */
/* @0x286134 vmov.f32 s15, #-1.000000e+00 */
/* @0x286138 vcmpe.f32 s17, s15 */
/* @0x28613c vmrs APSR_nzcv, fpscr */
/* @0x286140 bmi 0x286588 <spIkConstraint_apply2+0x60c> */
/* @0x286144 vmov.f32 s13, #1.000000e+00 */
/* @0x286148 vcmpe.f32 s17, s13 */
/* @0x28614c vmrs APSR_nzcv, fpscr */
/* @0x286150 vmovgt.f64 d7, #1.000000e+00 */
/* @0x286154 vmovgt.f32 s17, s13 */
/* @0x286158 ble 0x286594 <spIkConstraint_apply2+0x618> */
/* @0x28615c vmov r0, r1, d7 */
/* @0x286160 bl 0xb6c4c <acos@plt> */
/* @0x286164 vmov s10, r8 */
/* @0x286168 vmla.f32 s18, s16, s17 */
/* @0x28616c vcvt.f32.s32 s26, s10 */
/* @0x286170 vmov d6, r0, r1 */
/* @0x286174 vcvt.f32.f64 s17, d6 */
/* @0x286178 vmul.f32 s26, s17, s26 */
/* @0x28617c vcvt.f64.f32 d7, s26 */
/* @0x286180 vmov r0, r1, d7 */
/* @0x286184 bl 0xb67d8 <sin@plt> */
/* @0x286188 vmov d5, r0, r1 */
/* @0x28618c vcvt.f32.f64 s29, d5 */
/* @0x286190 vmul.f32 s16, s29, s16 */
/* @0x286194 vmul.f32 s13, s25, s16 */
/* @0x286198 vmul.f32 s29, s28, s16 */
/* @0x28619c vnmls.f32 s13, s28, s18 */
/* @0x2861a0 vmla.f32 s29, s25, s18 */
/* @0x2861a4 vcvt.f64.f32 d7, s13 */
/* @0x2861a8 vcvt.f64.f32 d5, s29 */
/* @0x2861ac vmov r0, r1, d7 */
/* @0x2861b0 vmov r2, r3, d5 */
/* @0x2861b4 bl 0xb6c70 <atan2@plt> */
/* @0x2861b8 vmov d6, r0, r1 */
/* @0x2861bc vcvt.f32.f64 s18, d6 */
/* @0x2861c0 vcvt.f64.f32 d7, s23 */
/* @0x2861c4 vcvt.f64.f32 d5, s19 */
/* @0x2861c8 vmov r0, r1, d7 */
/* @0x2861cc vmov r2, r3, d5 */
/* @0x2861d0 bl 0xb6c70 <atan2@plt> */
/* @0x2861d4 vldr s12, [pc, #328] */
/* @0x2861d8 vmov s11, r7 */
/* @0x2861dc vldr s13, [r4, #28] */
/* @0x2861e0 vmov s10, r10 */
/* @0x2861e4 vldr s15, [pc, #316] */
/* @0x2861e8 vcvt.f32.s32 s16, s11 */
/* @0x2861ec vcvt.f32.s32 s14, s10 */
/* @0x2861f0 vmov d5, r0, r1 */
/* @0x2861f4 vcvt.f32.f64 s17, d5 */
/* @0x2861f8 vmul.f32 s17, s17, s16 */
/* @0x2861fc vsub.f32 s18, s18, s17 */
/* @0x286200 vmla.f32 s14, s18, s12 */
/* @0x286204 vsub.f32 s14, s14, s13 */
/* @0x286208 vcmpe.f32 s14, s15 */
/* @0x28620c vmrs APSR_nzcv, fpscr */
/* @0x286210 ble 0x286308 <spIkConstraint_apply2+0x38c> */
/* @0x286214 vldr s15, [pc, #272] */
/* @0x286218 vsub.f32 s14, s14, s15 */
/* @0x28621c ldr r2, [r4, #0x20] */
/* @0x286220 mov r0, r4 */
/* @0x286224 ldr r3, [r4, #0x24] */
/* @0x286228 vmov r1, s22 */
/* @0x28622c str r2, [sp] */
/* @0x286230 str r3, [sp, #0x4] */
/* @0x286234 mov r3, #0 */
/* @0x286238 vmov r2, s21 */
/* @0x28623c str r3, [sp, #0x8] */
/* @0x286240 str r3, [sp, #0xc] */
/* @0x286244 vmla.f32 s13, s14, s20 */
/* @0x286248 vmov r3, s13 */
/* @0x28624c bl 0x284f18 <spBone_updateWorldTransformWith> */
/* @0x286250 vadd.f32 s26, s26, s17 */
/* @0x286254 vldr s13, [r5, #40] */
/* @0x286258 vldr s15, [pc, #196] */
/* @0x28625c vmov s10, r9 */
/* @0x286260 vldr s14, [r5, #28] */
/* @0x286264 vldr s12, [pc, #188] */
/* @0x286268 vmov.f32 s11, s13 */
/* @0x28626c vnmls.f32 s11, s26, s15 */
/* @0x286270 vcvt.f32.s32 s15, s10 */
/* @0x286274 vmla.f32 s15, s16, s11 */
/* @0x286278 vsub.f32 s15, s15, s14 */
/* @0x28627c vcmpe.f32 s15, s12 */
/* @0x286280 vmrs APSR_nzcv, fpscr */
/* @0x286284 ble 0x2862f0 <spIkConstraint_apply2+0x374> */
/* @0x286288 vldr s12, [pc, #156] */
/* @0x28628c vsub.f32 s15, s15, s12 */
/* @0x286290 vstr s13, [sp, #8] */
/* @0x286294 ldr r2, [r5, #0x20] */
/* @0x286298 ldr r3, [r5, #0x24] */
/* @0x28629c mov r0, r5 */
/* @0x2862a0 vmov r1, s19 */
/* @0x2862a4 str r2, [sp] */
/* @0x2862a8 str r3, [sp, #0x4] */
/* @0x2862ac ldr r3, [r5, #0x2c] */
/* @0x2862b0 vmov r2, s23 */
/* @0x2862b4 vmla.f32 s14, s15, s20 */
/* @0x2862b8 str r3, [sp, #0xc] */
/* @0x2862bc vmov r3, s14 */
/* @0x2862c0 bl 0x284f18 <spBone_updateWorldTransformWith> */
/* @0x2862c4 add sp, sp, #32 */
/* @0x2862c8 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2862cc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2862d0 vldr s14, [r4, #52] */
/* @0x2862d4 vldr s4, [r4, #60] */
/* @0x2862d8 vldr s15, [r4, #64] */
/* @0x2862dc vldr s13, [r4, #72] */
/* @0x2862e0 vmla.f32 s4, s19, s14 */
/* @0x2862e4 vldr s23, [pc, #80] */
/* @0x2862e8 vmla.f32 s13, s19, s15 */
/* @0x2862ec b 0x286068 <spIkConstraint_apply2+0xec> */
/* @0x2862f0 vldr s12, [pc, #56] */
/* @0x2862f4 vcmpe.f32 s15, s12 */
/* @0x2862f8 vmrs APSR_nzcv, fpscr */
/* @0x2862fc vldrmi s12, [pc, #40] */
/* @0x286300 vaddmi.f32 s15, s15, s12 */
/* @0x286304 b 0x286290 <spIkConstraint_apply2+0x314> */
/* @0x286308 vldr s15, [pc, #32] */
/* @0x28630c vcmpe.f32 s14, s15 */
/* @0x286310 vmrs APSR_nzcv, fpscr */
/* @0x286314 vldrmi s15, [pc, #16] */
/* @0x286318 vaddmi.f32 s14, s14, s15 */
/* @0x28631c b 0x28621c <spIkConstraint_apply2+0x2a0> */
/* @0x286320 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x286324 rsbmi r2, r5, #224, #28 */
/* @0x286328 teqmi r4, #0 */
/* @0x28632c .word 0x43b40000 */
/* @0x286330 teqgt r4, #0 */
/* @0x286334 svcvc #0x7fffff */
/* @0x286338 ldrdmi r0, r1, [r9], #-251 */
/* @0x28633c andeq r0, r0, r0 */
/* @0x286340 ldmlt r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x286344 vmul.f32 s27, s28, s28 */
/* @0x286348 vmul.f32 s24, s16, s29 */
/* @0x28634c vmla.f32 s27, s25, s25 */
/* @0x286350 vmul.f32 s30, s24, s24 */
/* @0x286354 vmul.f32 s29, s17, s29 */
/* @0x286358 vcvt.f64.f32 d7, s28 */
/* @0x28635c vcvt.f64.f32 d5, s25 */
/* @0x286360 vmov r0, r1, d7 */
/* @0x286364 vmov r2, r3, d5 */
/* @0x286368 bl 0xb6c70 <atan2@plt> */
/* @0x28636c vmul.f32 s26, s29, s29 */
/* @0x286370 vmul.f32 s15, s18, s18 */
/* @0x286374 vmul.f32 s25, s30, s27 */
/* @0x286378 vmla.f32 s25, s26, s15 */
/* @0x28637c vmov d7, r0, r1 */
/* @0x286380 vsub.f32 s11, s26, s30 */
/* @0x286384 vmov.f32 s12, #4.000000e+00 */
/* @0x286388 vstr s11, [sp, #20] */
/* @0x28638c vmov.f32 s31, #-2.000000e+00 */
/* @0x286390 vmls.f32 s25, s30, s26 */
/* @0x286394 vmul.f32 s12, s11, s12 */
/* @0x286398 vmul.f32 s31, s26, s31 */
/* @0x28639c vmul.f32 s12, s12, s25 */
/* @0x2863a0 vmul.f32 s31, s31, s18 */
/* @0x2863a4 vnmls.f32 s12, s31, s31 */
/* @0x2863a8 vadd.f32 s28, s18, s24 */
/* @0x2863ac vmul.f32 s10, s28, s28 */
/* @0x2863b0 vcvt.f32.f64 s15, d7 */
/* @0x2863b4 vstr s10, [sp, #24] */
/* @0x2863b8 vcmpe.f32 s12, #0 */
/* @0x2863bc vstr s15, [sp, #28] */
/* @0x2863c0 vmrs APSR_nzcv, fpscr */
/* @0x2863c4 blt 0x286440 <spIkConstraint_apply2+0x4c4> */
/* @0x2863c8 vcvt.f64.f32 d6, s12 */
/* @0x2863cc vsqrt.f64 d7, d6 */
/* @0x2863d0 vcmp.f64 d7, d7 */
/* @0x2863d4 vmrs APSR_nzcv, fpscr */
/* @0x2863d8 bne 0x28665c <spIkConstraint_apply2+0x6e0> */
/* @0x2863dc vcvt.f32.f64 s14, d7 */
/* @0x2863e0 vldr s11, [sp, #20] */
/* @0x2863e4 vcmpe.f32 s31, #0 */
/* @0x2863e8 vmrs APSR_nzcv, fpscr */
/* @0x2863ec vnegmi.f32 s14, s14 */
/* @0x2863f0 vmov.f32 s15, #5.000000e-01 */
/* @0x2863f4 vadd.f32 s31, s31, s14 */
/* @0x2863f8 vnmul.f32 s31, s31, s15 */
/* @0x2863fc vdiv.f32 s15, s31, s11 */
/* @0x286400 vdiv.f32 s25, s25, s31 */
/* @0x286404 vcmpe.f32 s15, #0 */
/* @0x286408 vmrs APSR_nzcv, fpscr */
/* @0x28640c vcmpe.f32 s25, #0 */
/* @0x286410 vnegmi.f32 s13, s15 */
/* @0x286414 vmovpl.f32 s13, s15 */
/* @0x286418 vmrs APSR_nzcv, fpscr */
/* @0x28641c vnegmi.f32 s14, s25 */
/* @0x286420 vmovpl.f32 s14, s25 */
/* @0x286424 vcmp.f32 s13, s14 */
/* @0x286428 vmrs APSR_nzcv, fpscr */
/* @0x28642c vmovmi.f32 s25, s15 */
/* @0x286430 vmul.f32 s12, s25, s25 */
/* @0x286434 vcmpe.f32 s27, s12 */
/* @0x286438 vmrs APSR_nzcv, fpscr */
/* @0x28643c bge 0x2865d4 <spIkConstraint_apply2+0x658> */
/* @0x286440 vsub.f32 s25, s18, s24 */
/* @0x286444 vldr s13, [sp, #24] */
/* @0x286448 vldr s15, [pc, #-284] */
/* @0x28644c vmul.f32 s31, s25, s25 */
/* @0x286450 vcmpe.f32 s13, #0 */
/* @0x286454 vmrs APSR_nzcv, fpscr */
/* @0x286458 vcmpe.f32 s31, s15 */
/* @0x28645c vldrle s28, [pc, #-296] */
/* @0x286460 vstrle s28, [sp, #24] */
/* @0x286464 vmrs APSR_nzcv, fpscr */
/* @0x286468 vmovpl.f32 s31, s15 */
/* @0x28646c vldrpl s25, [pc, #-312] */
/* @0x286470 vldrmi s14, [pc, #-320] */
/* @0x286474 vstrpl s25, [sp, #20] */
/* @0x286478 vstrmi s14, [sp, #20] */
/* @0x28647c vnmul.f32 s15, s24, s18 */
/* @0x286480 vsub.f32 s26, s30, s26 */
/* @0x286484 vdiv.f32 s26, s15, s26 */
/* @0x286488 vcvt.f64.f32 d5, s26 */
/* @0x28648c vmov r0, r1, d5 */
/* @0x286490 bl 0xb6c4c <acos@plt> */
/* @0x286494 vmov d6, r0, r1 */
/* @0x286498 vcvt.f32.f64 s26, d6 */
/* @0x28649c vcvt.f64.f32 d8, s26 */
/* @0x2864a0 vmov r0, r1, d8 */
/* @0x2864a4 bl 0xb67e4 <cos@plt> */
/* @0x2864a8 vmov d5, r0, r1 */
/* @0x2864ac vcvt.f32.f64 s15, d5 */
/* @0x2864b0 vmov r0, r1, d8 */
/* @0x2864b4 vmla.f32 s18, s15, s24 */
/* @0x2864b8 bl 0xb67d8 <sin@plt> */
/* @0x2864bc vldr s14, [sp, #24] */
/* @0x2864c0 vmov d6, r0, r1 */
/* @0x2864c4 vcvt.f32.f64 s15, d6 */
/* @0x2864c8 vmul.f32 s29, s15, s29 */
/* @0x2864cc vmul.f32 s15, s29, s29 */
/* @0x2864d0 vmla.f32 s15, s18, s18 */
/* @0x2864d4 vcmpe.f32 s31, s15 */
/* @0x2864d8 vmrs APSR_nzcv, fpscr */
/* @0x2864dc vcmpe.f32 s14, s15 */
/* @0x2864e0 vstrgt s26, [sp, #20] */
/* @0x2864e4 vldrle s13, [pc, #-432] */
/* @0x2864e8 vmovgt.f32 s31, s15 */
/* @0x2864ec vmovgt.f32 s13, s29 */
/* @0x2864f0 vmovgt.f32 s25, s18 */
/* @0x2864f4 vmrs APSR_nzcv, fpscr */
/* @0x2864f8 vldrpl s29, [pc, #-452] */
/* @0x2864fc vmovpl.f32 s15, s14 */
/* @0x286500 vmov.f32 s14, #5.000000e-01 */
/* @0x286504 vadd.f32 s15, s31, s15 */
/* @0x286508 vmul.f32 s15, s15, s14 */
/* @0x28650c vcmpe.f32 s27, s15 */
/* @0x286510 vmovpl.f32 s18, s28 */
/* @0x286514 vmovpl.f32 s26, s29 */
/* @0x286518 vmrs APSR_nzcv, fpscr */
/* @0x28651c bhi 0x28659c <spIkConstraint_apply2+0x620> */
/* @0x286520 vmov s15, r8 */
/* @0x286524 vcvt.f64.f32 d5, s25 */
/* @0x286528 vcvt.f32.s32 s26, s15 */
/* @0x28652c vmov r2, r3, d5 */
/* @0x286530 vmul.f32 s13, s26, s13 */
/* @0x286534 vcvt.f64.f32 d7, s13 */
/* @0x286538 vmov r0, r1, d7 */
/* @0x28653c bl 0xb6c70 <atan2@plt> */
/* @0x286540 vldr s15, [sp, #20] */
/* @0x286544 vmul.f32 s26, s15, s26 */
/* @0x286548 vmov d5, r0, r1 */
/* @0x28654c vcvt.f32.f64 s18, d5 */
/* @0x286550 vldr s11, [sp, #28] */
/* @0x286554 vsub.f32 s18, s11, s18 */
/* @0x286558 b 0x2861c0 <spIkConstraint_apply2+0x244> */
/* @0x28655c vldr s15, [pc, #-548] */
/* @0x286560 vcmpe.f32 s13, s15 */
/* @0x286564 vmrs APSR_nzcv, fpscr */
/* @0x286568 movlt r6, #0 */
/* @0x28656c movge r6, #1 */
/* @0x286570 b 0x28602c <spIkConstraint_apply2+0xb0> */
/* @0x286574 mov r0, r5 */
/* @0x286578 add sp, sp, #32 */
/* @0x28657c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x286580 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x286584 b 0x285348 <spBone_updateWorldTransform> */
/* @0x286588 vmov.f32 s17, s15 */
/* @0x28658c vmov.f64 d7, #-1.000000e+00 */
/* @0x286590 b 0x28615c <spIkConstraint_apply2+0x1e0> */
/* @0x286594 vcvt.f64.f32 d7, s17 */
/* @0x286598 b 0x28615c <spIkConstraint_apply2+0x1e0> */
/* @0x28659c vmov s12, r8 */
/* @0x2865a0 vcvt.f64.f32 d7, s18 */
/* @0x2865a4 vcvt.f32.s32 s17, s12 */
/* @0x2865a8 vmov r2, r3, d7 */
/* @0x2865ac vmul.f32 s29, s17, s29 */
/* @0x2865b0 vcvt.f64.f32 d5, s29 */
/* @0x2865b4 vmov r0, r1, d5 */
/* @0x2865b8 bl 0xb6c70 <atan2@plt> */
/* @0x2865bc vmul.f32 s26, s26, s17 */
/* @0x2865c0 vmov d6, r0, r1 */
/* @0x2865c4 vcvt.f32.f64 s18, d6 */
/* @0x2865c8 vldr s13, [sp, #28] */
/* @0x2865cc vsub.f32 s18, s13, s18 */
/* @0x2865d0 b 0x2861c0 <spIkConstraint_apply2+0x244> */
/* @0x2865d4 vsub.f32 s12, s27, s12 */
/* @0x2865d8 vcvt.f64.f32 d6, s12 */
/* @0x2865dc vsqrt.f64 d7, d6 */
/* @0x2865e0 vcmp.f64 d7, d7 */
/* @0x2865e4 vmrs APSR_nzcv, fpscr */
/* @0x2865e8 bne 0x28666c <spIkConstraint_apply2+0x6f0> */
/* @0x2865ec vmov s12, r8 */
/* @0x2865f0 vcvt.f32.f64 s14, d7 */
/* @0x2865f4 vcvt.f32.s32 s15, s12 */
/* @0x2865f8 vmul.f32 s24, s14, s15 */
/* @0x2865fc vcvt.f64.f32 d7, s25 */
/* @0x286600 vcvt.f64.f32 d5, s24 */
/* @0x286604 vmov r2, r3, d7 */
/* @0x286608 vmov r0, r1, d5 */
/* @0x28660c bl 0xb6c70 <atan2@plt> */
/* @0x286610 vsub.f32 s25, s25, s18 */
/* @0x286614 vdiv.f32 s17, s24, s17 */
/* @0x286618 vmov d6, r0, r1 */
/* @0x28661c vdiv.f32 s16, s25, s16 */
/* @0x286620 vcvt.f64.f32 d5, s17 */
/* @0x286624 vcvt.f64.f32 d7, s16 */
/* @0x286628 vmov r0, r1, d5 */
/* @0x28662c vldr s11, [sp, #28] */
/* @0x286630 vcvt.f32.f64 s18, d6 */
/* @0x286634 vmov r2, r3, d7 */
/* @0x286638 vsub.f32 s18, s11, s18 */
/* @0x28663c bl 0xb6c70 <atan2@plt> */
/* @0x286640 vmov d6, r0, r1 */
/* @0x286644 vcvt.f32.f64 s26, d6 */
/* @0x286648 b 0x2861c0 <spIkConstraint_apply2+0x244> */
/* @0x28664c vmov r0, r1, d6 */
/* @0x286650 bl 0xb66f4 <sqrt@plt> */
/* @0x286654 vmov d7, r0, r1 */
/* @0x286658 b 0x2860fc <spIkConstraint_apply2+0x180> */
/* @0x28665c vmov r0, r1, d6 */
/* @0x286660 bl 0xb66f4 <sqrt@plt> */
/* @0x286664 vmov d7, r0, r1 */
/* @0x286668 b 0x2863dc <spIkConstraint_apply2+0x460> */
/* @0x28666c vmov r0, r1, d6 */
/* @0x286670 bl 0xb66f4 <sqrt@plt> */
/* @0x286674 vmov d7, r0, r1 */
/* @0x286678 b 0x2865ec <spIkConstraint_apply2+0x670> */

/* ── FUNC 0x28667c · spIkConstraint_apply · size=116 · insn=29 */
/* @0x28667c ldr r3, [r0, #0x4] */
/* @0x286680 str lr, [sp, #-0x4]! */
/* @0x286684 cmp r3, #1 */
/* @0x286688 sub sp, sp, #12 */
/* @0x28668c beq 0x2866cc <spIkConstraint_apply+0x50> */
/* @0x286690 cmp r3, #2 */
/* @0x286694 bne 0x2866c4 <spIkConstraint_apply+0x48> */
/* @0x286698 ldr r3, [r0, #0xc] */
/* @0x28669c ldr r1, [r0, #0x8] */
/* @0x2866a0 ldr lr, [r0, #0x14] */
/* @0x2866a4 ldr r12, [r0, #0x10] */
/* @0x2866a8 ldr r2, [r3, #0x3c] */
/* @0x2866ac ldr r0, [r1] */
/* @0x2866b0 ldr r3, [r3, #0x48] */
/* @0x2866b4 ldr r1, [r1, #0x4] */
/* @0x2866b8 str lr, [sp, #0x4] */
/* @0x2866bc str r12, [sp] */
/* @0x2866c0 bl 0x285f7c <spIkConstraint_apply2> */
/* @0x2866c4 add sp, sp, #12 */
/* @0x2866c8 ldr pc, [sp], #4 */
/* @0x2866cc ldr r2, [r0, #0xc] */
/* @0x2866d0 ldr r12, [r0, #0x8] */
/* @0x2866d4 ldr r3, [r0, #0x14] */
/* @0x2866d8 ldr r1, [r2, #0x3c] */
/* @0x2866dc ldr r0, [r12] */
/* @0x2866e0 ldr r2, [r2, #0x48] */
/* @0x2866e4 add sp, sp, #12 */
/* @0x2866e8 ldr lr, [sp], #4 */
/* @0x2866ec b 0x285e48 <spIkConstraint_apply1> */

/* ── FUNC 0x2866f0 · spIkConstraintData_create · size=104 · insn=26 */
/* @0x2866f0 push {r4, r5, r6, lr} */
/* @0x2866f4 mov r3, #36 */
/* @0x2866f8 ldr r6, [pc, #0x54] */
/* @0x2866fc mov r5, r0 */
/* @0x286700 mov r1, #24 */
/* @0x286704 mov r0, #1 */
/* @0x286708 add r6, pc, r6 */
/* @0x28670c mov r2, r6 */
/* @0x286710 bl 0x285c4c <_calloc> */
/* @0x286714 mov r4, r0 */
/* @0x286718 mov r0, r5 */
/* @0x28671c bl 0xb6538 <strlen@plt> */
/* @0x286720 mov r1, r6 */
/* @0x286724 mov r2, #37 */
/* @0x286728 add r0, r0, #1 */
/* @0x28672c bl 0x285c10 <_malloc> */
/* @0x286730 mov r1, r5 */
/* @0x286734 str r0, [r4] */
/* @0x286738 bl 0xb65a4 <strcpy@plt> */
/* @0x28673c mov r2, #1065353216 */
/* @0x286740 mov r3, #1 */
/* @0x286744 mov r0, r4 */
/* @0x286748 str r3, [r4, #0x10] */
/* @0x28674c str r2, [r4, #0x14] */
/* @0x286750 pop {r4, r5, r6, pc} */
/* @0x286754 andeq r1, sp, r0, ror r1 */
