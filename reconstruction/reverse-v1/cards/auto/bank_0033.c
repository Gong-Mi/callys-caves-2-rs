/* libyoyo.so 覆盖卡组 0033
 * 函数 0x1085a0..0x109634，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1085a0 · F_DistanceToPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=60 */
/* @0x1085a0 push {r4, r5, r6, lr} */
/* @0x1085a4 vpush {d8, d9} */
/* @0x1085a8 mov r4, r1 */
/* @0x1085ac ldr r6, [sp, #0x20] */
/* @0x1085b0 mov r5, r0 */
/* @0x1085b4 mov r1, #0 */
/* @0x1085b8 mov r0, r6 */
/* @0x1085bc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1085c0 vmov d9, r0, r1 */
/* @0x1085c4 mov r0, r6 */
/* @0x1085c8 mov r1, #1 */
/* @0x1085cc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1085d0 ldrb r3, [r4, #0x64] */
/* @0x1085d4 cmp r3, #0 */
/* @0x1085d8 vmov d8, r0, r1 */
/* @0x1085dc bne 0x10866c <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x1085e0 vldr s14, [r4, #240] */
/* @0x1085e4 vcvt.f64.s32 d7, s14 */
/* @0x1085e8 vldr s11, [r4, #232] */
/* @0x1085ec vldr s10, [r4, #236] */
/* @0x1085f0 mov r3, #0 */
/* @0x1085f4 str r3, [r5, #0xc] */
/* @0x1085f8 vcvt.f64.s32 d6, s11 */
/* @0x1085fc vldr s11, [r4, #244] */
/* @0x108600 vcmpe.f64 d9, d7 */
/* @0x108604 vmrs APSR_nzcv, fpscr */
/* @0x108608 vcmpe.f64 d9, d6 */
/* @0x10860c vldrle d7, [pc, #124] */
/* @0x108610 vsubgt.f64 d7, d9, d7 */
/* @0x108614 vmrs APSR_nzcv, fpscr */
/* @0x108618 vsubmi.f64 d7, d9, d6 */
/* @0x10861c vcvt.f64.s32 d6, s11 */
/* @0x108620 vcvt.f64.s32 d5, s10 */
/* @0x108624 vcmpe.f64 d8, d6 */
/* @0x108628 vmrs APSR_nzcv, fpscr */
/* @0x10862c vcmpe.f64 d8, d5 */
/* @0x108630 vldrle d6, [pc, #88] */
/* @0x108634 vsubgt.f64 d6, d8, d6 */
/* @0x108638 vmrs APSR_nzcv, fpscr */
/* @0x10863c vsubmi.f64 d6, d8, d5 */
/* @0x108640 vmul.f64 d6, d6, d6 */
/* @0x108644 vmla.f64 d6, d7, d7 */
/* @0x108648 vsqrt.f64 d7, d6 */
/* @0x10864c vcmp.f64 d7, d7 */
/* @0x108650 vmrs APSR_nzcv, fpscr */
/* @0x108654 bne 0x10867c <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x108658 vmov r2, s14 */
/* @0x10865c vmov r3, s15 */
/* @0x108660 stm r5, {r2, r3} */
/* @0x108664 vpop {d8, d9} */
/* @0x108668 pop {r4, r5, r6, pc} */
/* @0x10866c mov r0, r4 */
/* @0x108670 mov r1, #1 */
/* @0x108674 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x108678 b 0x1085e0 <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x10867c vmov r0, r1, d6 */
/* @0x108680 bl 0xb66f4 <sqrt@plt> */
/* @0x108684 vmov d7, r0, r1 */
/* @0x108688 b 0x108658 <_Z17F_DistanceToPointR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x10868c nop */

/* ── FUNC 0x108698 · F_Point_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x108698 push {r3, r4, r5, lr} */
/* @0x10869c vpush {d8, d9, d10} */
/* @0x1086a0 mov r3, #0 */
/* @0x1086a4 ldr r4, [sp, #0x28] */
/* @0x1086a8 mov r1, r3 */
/* @0x1086ac str r3, [r0, #0xc] */
/* @0x1086b0 mov r5, r0 */
/* @0x1086b4 str r3, [r0] */
/* @0x1086b8 str r3, [r0, #0x4] */
/* @0x1086bc mov r0, r4 */
/* @0x1086c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1086c4 mov r1, #1 */
/* @0x1086c8 vmov s18, r0 */
/* @0x1086cc mov r0, r4 */
/* @0x1086d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1086d4 mov r1, #2 */
/* @0x1086d8 vmov s20, r0 */
/* @0x1086dc mov r0, r4 */
/* @0x1086e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1086e4 mov r1, #3 */
/* @0x1086e8 vmov s17, r0 */
/* @0x1086ec mov r0, r4 */
/* @0x1086f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1086f4 mov r1, #4 */
/* @0x1086f8 vmov s19, r0 */
/* @0x1086fc mov r0, r4 */
/* @0x108700 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108704 vsub.f32 s15, s18, s17 */
/* @0x108708 vsub.f32 s14, s20, s19 */
/* @0x10870c vmul.f32 s14, s14, s14 */
/* @0x108710 vmla.f32 s14, s15, s15 */
/* @0x108714 vmov s16, r0 */
/* @0x108718 vsqrt.f32 s15, s14 */
/* @0x10871c vcmp.f32 s15, s15 */
/* @0x108720 vmrs APSR_nzcv, fpscr */
/* @0x108724 bne 0x108748 <_Z17F_Point_In_CircleR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x108728 vcmpe.f32 s16, s15 */
/* @0x10872c vmrs APSR_nzcv, fpscr */
/* @0x108730 movge r3, #0 */
/* @0x108734 movge r2, r3 */
/* @0x108738 movtge r3, #0x3ff0 */
/* @0x10873c stmge r5, {r2, r3} */
/* @0x108740 vpop {d8, d9, d10} */
/* @0x108744 pop {r3, r4, r5, pc} */
/* @0x108748 vmov r0, s14 */
/* @0x10874c bl 0xb6700 <sqrtf@plt> */
/* @0x108750 vmov s15, r0 */
/* @0x108754 b 0x108728 <_Z17F_Point_In_CircleR6RValueP9CInstanceS2_iPS_+0x90> */

/* ── FUNC 0x108758 · F_InstanceFind(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x108758 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10875c sub sp, sp, #52 */
/* @0x108760 mov r10, r1 */
/* @0x108764 mov r8, r0 */
/* @0x108768 ldr r4, [sp, #0x58] */
/* @0x10876c mov r1, #0 */
/* @0x108770 mov r9, r2 */
/* @0x108774 add r5, sp, #12 */
/* @0x108778 mvn r6, #0 */
/* @0x10877c mov r0, r4 */
/* @0x108780 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108784 mov r1, #1 */
/* @0x108788 mov r11, r0 */
/* @0x10878c mov r0, r4 */
/* @0x108790 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108794 mov r12, #0 */
/* @0x108798 mov r1, r11 */
/* @0x10879c mov r2, r10 */
/* @0x1087a0 mov r3, r9 */
/* @0x1087a4 str r12, [sp] */
/* @0x1087a8 mov r7, r0 */
/* @0x1087ac mov r0, r5 */
/* @0x1087b0 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x1087b4 b 0x1087dc <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1087b8 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x1087bc ldrb r3, [r4, #0x68] */
/* @0x1087c0 cmp r3, #0 */
/* @0x1087c4 bne 0x1087d4 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1087c8 ldrb r3, [r4, #0x69] */
/* @0x1087cc cmp r3, #0 */
/* @0x1087d0 addeq r6, r6, #1 */
/* @0x1087d4 cmp r6, r7 */
/* @0x1087d8 beq 0x1087f0 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1087dc mov r0, r5 */
/* @0x1087e0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x1087e4 subs r4, r0, #0 */
/* @0x1087e8 mov r0, r5 */
/* @0x1087ec bne 0x1087b8 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x1087f0 ldr r3, [pc, #0x50] */
/* @0x1087f4 ldr r3, [pc, r3] */
/* @0x1087f8 ldrb r3, [r3] */
/* @0x1087fc cmp r3, #0 */
/* @0x108800 bne 0x108834 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x108804 cmp r4, #0 */
/* @0x108808 str r3, [r8, #0xc] */
/* @0x10880c ldrne r2, [r4, #0x78] */
/* @0x108810 moveq r3, #0 */
/* @0x108814 moveq r2, #0 */
/* @0x108818 movteq r3, #0xc010 */
/* @0x10881c vmovne s15, r2 */
/* @0x108820 vcvtne.f64.s32 d7, s15 */
/* @0x108824 vmovne r2, r3, d7 */
/* @0x108828 stm r8, {r2, r3} */
/* @0x10882c add sp, sp, #52 */
/* @0x108830 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x108834 mov r3, #6 */
/* @0x108838 str r4, [r8] */
/* @0x10883c str r3, [r8, #0xc] */
/* @0x108840 add sp, sp, #52 */
/* @0x108844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x108848 eoreq r5, lr, r4, asr #7 */

/* ── FUNC 0x10884c · F_PathStart(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x10884c push {r4, r5, r6, r7, r8, lr} */
/* @0x108850 sub sp, sp, #16 */
/* @0x108854 mov r5, r1 */
/* @0x108858 mov r1, #0 */
/* @0x10885c ldr r4, [sp, #0x28] */
/* @0x108860 mov r0, r4 */
/* @0x108864 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108868 mov r1, #1 */
/* @0x10886c mov r7, r0 */
/* @0x108870 mov r0, r4 */
/* @0x108874 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108878 mov r1, #3 */
/* @0x10887c mov r6, r0 */
/* @0x108880 mov r0, r4 */
/* @0x108884 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108888 mov r1, #2 */
/* @0x10888c mov r8, r0 */
/* @0x108890 mov r0, r4 */
/* @0x108894 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108898 eor r3, r8, #1 */
/* @0x10889c mov r12, #0 */
/* @0x1088a0 mov r1, r7 */
/* @0x1088a4 mov r2, r6 */
/* @0x1088a8 uxtb r3, r3 */
/* @0x1088ac str r12, [sp] */
/* @0x1088b0 str r3, [sp, #0x4] */
/* @0x1088b4 mov r3, #1065353216 */
/* @0x1088b8 str r0, [sp, #0x8] */
/* @0x1088bc mov r0, r5 */
/* @0x1088c0 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi> */
/* @0x1088c4 add sp, sp, #16 */
/* @0x1088c8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1088cc · F_PathEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1088cc str lr, [sp, #-0x4]! */
/* @0x1088d0 sub sp, sp, #20 */
/* @0x1088d4 mov r0, r1 */
/* @0x1088d8 mov r2, #0 */
/* @0x1088dc mov r3, #0 */
/* @0x1088e0 str r2, [sp] */
/* @0x1088e4 str r3, [sp, #0x4] */
/* @0x1088e8 mvn r1, #0 */
/* @0x1088ec str r3, [sp, #0x8] */
/* @0x1088f0 mov r3, #1065353216 */
/* @0x1088f4 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi> */
/* @0x1088f8 add sp, sp, #20 */
/* @0x1088fc ldr pc, [sp], #4 */

/* ── FUNC 0x108900 · F_MpLinearStep(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x108900 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108904 sub sp, sp, #8 */
/* @0x108908 mov r6, #0 */
/* @0x10890c mov r5, r0 */
/* @0x108910 ldr r4, [sp, #0x28] */
/* @0x108914 mov r7, r1 */
/* @0x108918 str r6, [r0, #0xc] */
/* @0x10891c mov r1, r6 */
/* @0x108920 mov r0, r4 */
/* @0x108924 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108928 mov r1, #1 */
/* @0x10892c mov r10, r0 */
/* @0x108930 mov r0, r4 */
/* @0x108934 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108938 mov r1, #2 */
/* @0x10893c mov r9, r0 */
/* @0x108940 mov r0, r4 */
/* @0x108944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108948 mov r1, #3 */
/* @0x10894c mov r8, r0 */
/* @0x108950 mov r0, r4 */
/* @0x108954 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108958 mov r3, r8 */
/* @0x10895c mvn r12, #2 */
/* @0x108960 mov r1, r10 */
/* @0x108964 mov r2, r9 */
/* @0x108968 str r12, [sp] */
/* @0x10896c str r0, [sp, #0x4] */
/* @0x108970 mov r0, r7 */
/* @0x108974 bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib> */
/* @0x108978 cmp r0, #0 */
/* @0x10897c moveq r6, r0 */
/* @0x108980 movne r3, r6 */
/* @0x108984 moveq r3, r6 */
/* @0x108988 movtne r3, #0x3ff0 */
/* @0x10898c str r6, [r5] */
/* @0x108990 str r3, [r5, #0x4] */
/* @0x108994 add sp, sp, #8 */
/* @0x108998 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x10899c · F_MpLinearStepObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x10899c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1089a0 sub sp, sp, #8 */
/* @0x1089a4 mov r6, #0 */
/* @0x1089a8 mov r5, r0 */
/* @0x1089ac ldr r4, [sp, #0x28] */
/* @0x1089b0 mov r7, r1 */
/* @0x1089b4 str r6, [r0, #0xc] */
/* @0x1089b8 mov r1, r6 */
/* @0x1089bc mov r0, r4 */
/* @0x1089c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1089c4 mov r1, #1 */
/* @0x1089c8 mov r10, r0 */
/* @0x1089cc mov r0, r4 */
/* @0x1089d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1089d4 mov r1, #2 */
/* @0x1089d8 mov r9, r0 */
/* @0x1089dc mov r0, r4 */
/* @0x1089e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1089e4 mov r1, #3 */
/* @0x1089e8 mov r8, r0 */
/* @0x1089ec mov r0, r4 */
/* @0x1089f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1089f4 mov r3, r8 */
/* @0x1089f8 mov r12, #1 */
/* @0x1089fc mov r1, r10 */
/* @0x108a00 mov r2, r9 */
/* @0x108a04 stm sp, {r0, r12} */
/* @0x108a08 mov r0, r7 */
/* @0x108a0c bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib> */
/* @0x108a10 cmp r0, #0 */
/* @0x108a14 moveq r6, r0 */
/* @0x108a18 movne r3, r6 */
/* @0x108a1c moveq r3, r6 */
/* @0x108a20 movtne r3, #0x3ff0 */
/* @0x108a24 str r6, [r5] */
/* @0x108a28 str r3, [r5, #0x4] */
/* @0x108a2c add sp, sp, #8 */
/* @0x108a30 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x108a34 · F_MpPotentialStep(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x108a34 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108a38 sub sp, sp, #8 */
/* @0x108a3c mov r6, #0 */
/* @0x108a40 mov r5, r0 */
/* @0x108a44 ldr r4, [sp, #0x28] */
/* @0x108a48 mov r7, r1 */
/* @0x108a4c str r6, [r0, #0xc] */
/* @0x108a50 mov r1, r6 */
/* @0x108a54 mov r0, r4 */
/* @0x108a58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108a5c mov r1, #1 */
/* @0x108a60 mov r10, r0 */
/* @0x108a64 mov r0, r4 */
/* @0x108a68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108a6c mov r1, #2 */
/* @0x108a70 mov r9, r0 */
/* @0x108a74 mov r0, r4 */
/* @0x108a78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108a7c mov r1, #3 */
/* @0x108a80 mov r8, r0 */
/* @0x108a84 mov r0, r4 */
/* @0x108a88 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108a8c mov r3, r8 */
/* @0x108a90 mvn r12, #2 */
/* @0x108a94 mov r1, r10 */
/* @0x108a98 mov r2, r9 */
/* @0x108a9c str r12, [sp] */
/* @0x108aa0 str r0, [sp, #0x4] */
/* @0x108aa4 mov r0, r7 */
/* @0x108aa8 bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib> */
/* @0x108aac cmp r0, #0 */
/* @0x108ab0 moveq r6, r0 */
/* @0x108ab4 movne r3, r6 */
/* @0x108ab8 moveq r3, r6 */
/* @0x108abc movtne r3, #0x3ff0 */
/* @0x108ac0 str r6, [r5] */
/* @0x108ac4 str r3, [r5, #0x4] */
/* @0x108ac8 add sp, sp, #8 */
/* @0x108acc pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x108ad0 · F_MpPotentialStepObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x108ad0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108ad4 sub sp, sp, #8 */
/* @0x108ad8 mov r6, #0 */
/* @0x108adc mov r5, r0 */
/* @0x108ae0 ldr r4, [sp, #0x28] */
/* @0x108ae4 mov r7, r1 */
/* @0x108ae8 str r6, [r0, #0xc] */
/* @0x108aec mov r1, r6 */
/* @0x108af0 mov r0, r4 */
/* @0x108af4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108af8 mov r1, #1 */
/* @0x108afc mov r10, r0 */
/* @0x108b00 mov r0, r4 */
/* @0x108b04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108b08 mov r1, #2 */
/* @0x108b0c mov r9, r0 */
/* @0x108b10 mov r0, r4 */
/* @0x108b14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108b18 mov r1, #3 */
/* @0x108b1c mov r8, r0 */
/* @0x108b20 mov r0, r4 */
/* @0x108b24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108b28 mov r3, r8 */
/* @0x108b2c mov r12, #1 */
/* @0x108b30 mov r1, r10 */
/* @0x108b34 mov r2, r9 */
/* @0x108b38 stm sp, {r0, r12} */
/* @0x108b3c mov r0, r7 */
/* @0x108b40 bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib> */
/* @0x108b44 cmp r0, #0 */
/* @0x108b48 moveq r6, r0 */
/* @0x108b4c movne r3, r6 */
/* @0x108b50 moveq r3, r6 */
/* @0x108b54 movtne r3, #0x3ff0 */
/* @0x108b58 str r6, [r5] */
/* @0x108b5c str r3, [r5, #0x4] */
/* @0x108b60 add sp, sp, #8 */
/* @0x108b64 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x108b68 · F_MpPotentialSettings(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x108b68 push {r4, r5, r6, r7, r8, lr} */
/* @0x108b6c mov r1, #0 */
/* @0x108b70 ldr r4, [sp, #0x18] */
/* @0x108b74 mov r0, r4 */
/* @0x108b78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108b7c mov r1, #1 */
/* @0x108b80 mov r7, r0 */
/* @0x108b84 mov r0, r4 */
/* @0x108b88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108b8c mov r1, #2 */
/* @0x108b90 mov r6, r0 */
/* @0x108b94 mov r0, r4 */
/* @0x108b98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108b9c mov r1, #3 */
/* @0x108ba0 mov r5, r0 */
/* @0x108ba4 mov r0, r4 */
/* @0x108ba8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108bac mov r1, r6 */
/* @0x108bb0 mov r2, r5 */
/* @0x108bb4 mov r3, r0 */
/* @0x108bb8 mov r0, r7 */
/* @0x108bbc pop {r4, r5, r6, r7, r8, lr} */
/* @0x108bc0 b 0x19cb18 <_Z25Motion_Potential_Settingsfffb> */

/* ── FUNC 0x108bc4 · F_MpGridCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x108bc4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108bc8 sub sp, sp, #8 */
/* @0x108bcc mov r5, r0 */
/* @0x108bd0 mov r1, #0 */
/* @0x108bd4 ldr r4, [sp, #0x28] */
/* @0x108bd8 str r1, [r0, #0xc] */
/* @0x108bdc mov r0, r4 */
/* @0x108be0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108be4 mov r1, #1 */
/* @0x108be8 mov r6, r0 */
/* @0x108bec mov r0, r4 */
/* @0x108bf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108bf4 mov r1, #2 */
/* @0x108bf8 mov r9, r0 */
/* @0x108bfc mov r0, r4 */
/* @0x108c00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108c04 mov r1, #3 */
/* @0x108c08 mov r8, r0 */
/* @0x108c0c mov r0, r4 */
/* @0x108c10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108c14 mov r1, #4 */
/* @0x108c18 mov r7, r0 */
/* @0x108c1c mov r0, r4 */
/* @0x108c20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108c24 mov r1, #5 */
/* @0x108c28 mov r10, r0 */
/* @0x108c2c mov r0, r4 */
/* @0x108c30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108c34 mov r1, r9 */
/* @0x108c38 mov r2, r8 */
/* @0x108c3c mov r3, r7 */
/* @0x108c40 str r10, [sp] */
/* @0x108c44 str r0, [sp, #0x4] */
/* @0x108c48 mov r0, r6 */
/* @0x108c4c bl 0x199fc0 <_Z18Motion_Grid_Createiiiiii> */
/* @0x108c50 vmov s15, r0 */
/* @0x108c54 vcvt.f64.s32 d7, s15 */
/* @0x108c58 vmov r0, r1, d7 */
/* @0x108c5c vmov r2, s14 */
/* @0x108c60 mov r3, r1 */
/* @0x108c64 stm r5, {r2, r3} */
/* @0x108c68 add sp, sp, #8 */
/* @0x108c6c pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x108c70 · F_MpGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x108c70 push {r3, lr} */
/* @0x108c74 mov r1, #0 */
/* @0x108c78 ldr r0, [sp, #0x8] */
/* @0x108c7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108c80 pop {r3, lr} */
/* @0x108c84 b 0x19a178 <_Z19Motion_Grid_Destroyi> */

/* ── FUNC 0x108c88 · F_MpGridClearAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x108c88 push {r3, lr} */
/* @0x108c8c mov r1, #0 */
/* @0x108c90 ldr r0, [sp, #0x8] */
/* @0x108c94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108c98 pop {r3, lr} */
/* @0x108c9c b 0x19a1d4 <_Z20Motion_Grid_ClearAlli> */

/* ── FUNC 0x108ca0 · F_MpGridClearCell(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x108ca0 push {r4, r5, r6, lr} */
/* @0x108ca4 mov r1, #0 */
/* @0x108ca8 ldr r4, [sp, #0x10] */
/* @0x108cac mov r0, r4 */
/* @0x108cb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108cb4 mov r1, #1 */
/* @0x108cb8 mov r6, r0 */
/* @0x108cbc mov r0, r4 */
/* @0x108cc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108cc4 mov r1, #2 */
/* @0x108cc8 mov r5, r0 */
/* @0x108ccc mov r0, r4 */
/* @0x108cd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108cd4 mov r1, r5 */
/* @0x108cd8 mov r2, r0 */
/* @0x108cdc mov r0, r6 */
/* @0x108ce0 pop {r4, r5, r6, lr} */
/* @0x108ce4 b 0x19a26c <_Z21Motion_Grid_ClearCelliii> */

/* ── FUNC 0x108ce8 · F_MpGridClearRectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x108ce8 push {r4, r5, r6, r7, r8, lr} */
/* @0x108cec mov r1, #0 */
/* @0x108cf0 ldr r4, [sp, #0x18] */
/* @0x108cf4 mov r0, r4 */
/* @0x108cf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108cfc mov r1, #1 */
/* @0x108d00 mov r5, r0 */
/* @0x108d04 mov r0, r4 */
/* @0x108d08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d0c mov r1, #2 */
/* @0x108d10 mov r8, r0 */
/* @0x108d14 mov r0, r4 */
/* @0x108d18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d1c mov r1, #3 */
/* @0x108d20 mov r7, r0 */
/* @0x108d24 mov r0, r4 */
/* @0x108d28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d2c mov r1, #4 */
/* @0x108d30 mov r6, r0 */
/* @0x108d34 mov r0, r4 */
/* @0x108d38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d3c mov r1, r8 */
/* @0x108d40 mov r2, r7 */
/* @0x108d44 mov r3, r6 */
/* @0x108d48 str r0, [sp, #0x18] */
/* @0x108d4c mov r0, r5 */
/* @0x108d50 pop {r4, r5, r6, r7, r8, lr} */
/* @0x108d54 b 0x19a2e0 <_Z26Motion_Grid_ClearRectangleiiiii> */

/* ── FUNC 0x108d58 · F_MpGridAddCell(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x108d58 push {r4, r5, r6, lr} */
/* @0x108d5c mov r1, #0 */
/* @0x108d60 ldr r4, [sp, #0x10] */
/* @0x108d64 mov r0, r4 */
/* @0x108d68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d6c mov r1, #1 */
/* @0x108d70 mov r6, r0 */
/* @0x108d74 mov r0, r4 */
/* @0x108d78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d7c mov r1, #2 */
/* @0x108d80 mov r5, r0 */
/* @0x108d84 mov r0, r4 */
/* @0x108d88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108d8c mov r1, r5 */
/* @0x108d90 mov r2, r0 */
/* @0x108d94 mov r0, r6 */
/* @0x108d98 pop {r4, r5, r6, lr} */
/* @0x108d9c b 0x19a404 <_Z19Motion_Grid_AddCelliii> */

/* ── FUNC 0x108da0 · F_MpGridGetCell(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x108da0 push {r3, r4, r5, r6, r7, lr} */
/* @0x108da4 mov r1, #0 */
/* @0x108da8 ldr r4, [sp, #0x18] */
/* @0x108dac mov r5, r0 */
/* @0x108db0 str r1, [r0, #0xc] */
/* @0x108db4 mov r0, r4 */
/* @0x108db8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108dbc mov r1, #1 */
/* @0x108dc0 mov r7, r0 */
/* @0x108dc4 mov r0, r4 */
/* @0x108dc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108dcc mov r1, #2 */
/* @0x108dd0 mov r6, r0 */
/* @0x108dd4 mov r0, r4 */
/* @0x108dd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108ddc mov r1, r6 */
/* @0x108de0 mov r2, r0 */
/* @0x108de4 mov r0, r7 */
/* @0x108de8 bl 0x19a478 <_Z19Motion_Grid_GetCelliii> */
/* @0x108dec vmov s15, r0 */
/* @0x108df0 vcvt.f64.s32 d7, s15 */
/* @0x108df4 vmov r0, r1, d7 */
/* @0x108df8 vmov r2, s14 */
/* @0x108dfc mov r3, r1 */
/* @0x108e00 stm r5, {r2, r3} */
/* @0x108e04 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x108e08 · F_MpGridAddRectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x108e08 push {r4, r5, r6, r7, r8, lr} */
/* @0x108e0c mov r1, #0 */
/* @0x108e10 ldr r4, [sp, #0x18] */
/* @0x108e14 mov r0, r4 */
/* @0x108e18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108e1c mov r1, #1 */
/* @0x108e20 mov r5, r0 */
/* @0x108e24 mov r0, r4 */
/* @0x108e28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108e2c mov r1, #2 */
/* @0x108e30 mov r8, r0 */
/* @0x108e34 mov r0, r4 */
/* @0x108e38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108e3c mov r1, #3 */
/* @0x108e40 mov r7, r0 */
/* @0x108e44 mov r0, r4 */
/* @0x108e48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108e4c mov r1, #4 */
/* @0x108e50 mov r6, r0 */
/* @0x108e54 mov r0, r4 */
/* @0x108e58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108e5c mov r1, r8 */
/* @0x108e60 mov r2, r7 */
/* @0x108e64 mov r3, r6 */
/* @0x108e68 str r0, [sp, #0x18] */
/* @0x108e6c mov r0, r5 */
/* @0x108e70 pop {r4, r5, r6, r7, r8, lr} */
/* @0x108e74 b 0x19a4f4 <_Z24Motion_Grid_AddRectangleiiiii> */

/* ── FUNC 0x108e78 · F_MpGridAddInstances(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x108e78 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108e7c sub sp, sp, #48 */
/* @0x108e80 mov r9, r1 */
/* @0x108e84 mov r1, #0 */
/* @0x108e88 ldr r5, [sp, #0x50] */
/* @0x108e8c mov r6, r2 */
/* @0x108e90 add r4, sp, #12 */
/* @0x108e94 mov r0, r5 */
/* @0x108e98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108e9c mov r1, #1 */
/* @0x108ea0 mov r7, r0 */
/* @0x108ea4 mov r0, r5 */
/* @0x108ea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108eac mov r1, #2 */
/* @0x108eb0 mov r10, r0 */
/* @0x108eb4 mov r0, r5 */
/* @0x108eb8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108ebc mov r12, #0 */
/* @0x108ec0 mov r1, r10 */
/* @0x108ec4 mov r2, r9 */
/* @0x108ec8 mov r3, r6 */
/* @0x108ecc str r12, [sp] */
/* @0x108ed0 mov r8, r0 */
/* @0x108ed4 mov r0, r4 */
/* @0x108ed8 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x108edc mov r0, r4 */
/* @0x108ee0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x108ee4 cmp r0, #0 */
/* @0x108ee8 mov r0, r4 */
/* @0x108eec beq 0x108f2c <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x108ef0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x108ef4 mov r5, r0 */
/* @0x108ef8 mov r0, r4 */
/* @0x108efc bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x108f00 ldrb r3, [r5, #0x68] */
/* @0x108f04 cmp r3, #0 */
/* @0x108f08 bne 0x108edc <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x108f0c ldrb r3, [r5, #0x69] */
/* @0x108f10 cmp r3, #0 */
/* @0x108f14 bne 0x108edc <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x108f18 mov r1, r5 */
/* @0x108f1c mov r0, r7 */
/* @0x108f20 mov r2, r8 */
/* @0x108f24 bl 0x19a618 <_Z23Motion_Grid_AddInstanceiP9CInstanceb> */
/* @0x108f28 b 0x108edc <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x108f2c add sp, sp, #48 */
/* @0x108f30 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x108f34 · F_MpGridDraw(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x108f34 push {r3, lr} */
/* @0x108f38 mov r1, #0 */
/* @0x108f3c ldr r0, [sp, #0x8] */
/* @0x108f40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108f44 pop {r3, lr} */
/* @0x108f48 b 0x19c1ac <_Z16Motion_Grid_Drawi> */

/* ── FUNC 0x108f4c · F_MpGrid_to_DSGrid(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x108f4c push {r3, r4, r5, lr} */
/* @0x108f50 mov r1, #0 */
/* @0x108f54 ldr r4, [sp, #0x10] */
/* @0x108f58 mov r0, r4 */
/* @0x108f5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108f60 mov r1, #1 */
/* @0x108f64 mov r5, r0 */
/* @0x108f68 mov r0, r4 */
/* @0x108f6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108f70 mov r1, r0 */
/* @0x108f74 mov r0, r5 */
/* @0x108f78 pop {r3, r4, r5, lr} */
/* @0x108f7c b 0x19c358 <_Z21Motion_Grid_to_dsGridii> */

/* ── FUNC 0x108f80 · F_CollisionPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x108f80 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x108f84 sub sp, sp, #8 */
/* @0x108f88 mov r5, r0 */
/* @0x108f8c mov r6, r1 */
/* @0x108f90 ldr r4, [sp, #0x28] */
/* @0x108f94 mov r1, #0 */
/* @0x108f98 mov r0, r4 */
/* @0x108f9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108fa0 mov r1, #1 */
/* @0x108fa4 mov r9, r0 */
/* @0x108fa8 mov r0, r4 */
/* @0x108fac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108fb0 mov r1, #2 */
/* @0x108fb4 mov r7, r0 */
/* @0x108fb8 mov r0, r4 */
/* @0x108fbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x108fc0 mov r1, #3 */
/* @0x108fc4 mov r8, r0 */
/* @0x108fc8 mov r0, r4 */
/* @0x108fcc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108fd0 mov r1, #4 */
/* @0x108fd4 mov r10, r0 */
/* @0x108fd8 mov r0, r4 */
/* @0x108fdc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108fe0 mov r2, r7 */
/* @0x108fe4 mov r3, r8 */
/* @0x108fe8 str r10, [sp] */
/* @0x108fec mov r1, r9 */
/* @0x108ff0 str r0, [sp, #0x4] */
/* @0x108ff4 mov r0, r6 */
/* @0x108ff8 bl 0x1c89a4 <_Z22Command_CollisionPointP9CInstanceffibb> */
/* @0x108ffc mov r3, #0 */
/* @0x109000 str r3, [r5, #0xc] */
/* @0x109004 cmp r0, #0 */
/* @0x109008 ldrne r2, [r0, #0x78] */
/* @0x10900c moveq r3, #0 */
/* @0x109010 moveq r2, #0 */
/* @0x109014 movteq r3, #0xc010 */
/* @0x109018 vmovne s15, r2 */
/* @0x10901c vcvtne.f64.s32 d7, s15 */
/* @0x109020 vmovne r2, r3, d7 */
/* @0x109024 stm r5, {r2, r3} */
/* @0x109028 add sp, sp, #8 */
/* @0x10902c pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x109030 · F_CollisionRectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x109030 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109034 sub sp, sp, #28 */
/* @0x109038 mov r5, r0 */
/* @0x10903c mov r6, r1 */
/* @0x109040 ldr r4, [sp, #0x40] */
/* @0x109044 mov r1, #0 */
/* @0x109048 mov r0, r4 */
/* @0x10904c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109050 mov r1, #1 */
/* @0x109054 mov r9, r0 */
/* @0x109058 mov r0, r4 */
/* @0x10905c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109060 mov r1, #2 */
/* @0x109064 mov r8, r0 */
/* @0x109068 mov r0, r4 */
/* @0x10906c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109070 mov r1, #3 */
/* @0x109074 mov r7, r0 */
/* @0x109078 mov r0, r4 */
/* @0x10907c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109080 mov r1, #4 */
/* @0x109084 mov r3, r0 */
/* @0x109088 mov r0, r4 */
/* @0x10908c str r3, [sp, #0x14] */
/* @0x109090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109094 mov r1, #5 */
/* @0x109098 mov r11, r0 */
/* @0x10909c mov r0, r4 */
/* @0x1090a0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1090a4 mov r1, #6 */
/* @0x1090a8 mov r10, r0 */
/* @0x1090ac mov r0, r4 */
/* @0x1090b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1090b4 ldr r3, [sp, #0x14] */
/* @0x1090b8 mov r2, r8 */
/* @0x1090bc str r11, [sp, #0x4] */
/* @0x1090c0 str r10, [sp, #0x8] */
/* @0x1090c4 mov r1, r9 */
/* @0x1090c8 str r3, [sp] */
/* @0x1090cc mov r3, r7 */
/* @0x1090d0 str r0, [sp, #0xc] */
/* @0x1090d4 mov r0, r6 */
/* @0x1090d8 bl 0x1ca350 <_Z26Command_CollisionRectangleP9CInstanceffffibb> */
/* @0x1090dc mov r3, #0 */
/* @0x1090e0 str r3, [r5, #0xc] */
/* @0x1090e4 cmp r0, #0 */
/* @0x1090e8 ldrne r2, [r0, #0x78] */
/* @0x1090ec moveq r3, #0 */
/* @0x1090f0 moveq r2, #0 */
/* @0x1090f4 movteq r3, #0xc010 */
/* @0x1090f8 vmovne s15, r2 */
/* @0x1090fc vcvtne.f64.s32 d7, s15 */
/* @0x109100 vmovne r2, r3, d7 */
/* @0x109104 stm r5, {r2, r3} */
/* @0x109108 add sp, sp, #28 */
/* @0x10910c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x109110 · F_CollisionEllipse(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x109110 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109114 sub sp, sp, #28 */
/* @0x109118 mov r5, r0 */
/* @0x10911c mov r6, r1 */
/* @0x109120 ldr r4, [sp, #0x40] */
/* @0x109124 mov r1, #0 */
/* @0x109128 mov r0, r4 */
/* @0x10912c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109130 mov r1, #1 */
/* @0x109134 mov r9, r0 */
/* @0x109138 mov r0, r4 */
/* @0x10913c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109140 mov r1, #2 */
/* @0x109144 mov r8, r0 */
/* @0x109148 mov r0, r4 */
/* @0x10914c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109150 mov r1, #3 */
/* @0x109154 mov r7, r0 */
/* @0x109158 mov r0, r4 */
/* @0x10915c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109160 mov r1, #4 */
/* @0x109164 mov r3, r0 */
/* @0x109168 mov r0, r4 */
/* @0x10916c str r3, [sp, #0x14] */
/* @0x109170 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109174 mov r1, #5 */
/* @0x109178 mov r11, r0 */
/* @0x10917c mov r0, r4 */
/* @0x109180 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109184 mov r1, #6 */
/* @0x109188 mov r10, r0 */
/* @0x10918c mov r0, r4 */
/* @0x109190 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109194 ldr r3, [sp, #0x14] */
/* @0x109198 mov r2, r8 */
/* @0x10919c str r11, [sp, #0x4] */
/* @0x1091a0 str r10, [sp, #0x8] */
/* @0x1091a4 mov r1, r9 */
/* @0x1091a8 str r3, [sp] */
/* @0x1091ac mov r3, r7 */
/* @0x1091b0 str r0, [sp, #0xc] */
/* @0x1091b4 mov r0, r6 */
/* @0x1091b8 bl 0x1c8bb4 <_Z24Command_CollisionEllipseP9CInstanceffffibb> */
/* @0x1091bc mov r3, #0 */
/* @0x1091c0 str r3, [r5, #0xc] */
/* @0x1091c4 cmp r0, #0 */
/* @0x1091c8 ldrne r2, [r0, #0x78] */
/* @0x1091cc moveq r3, #0 */
/* @0x1091d0 moveq r2, #0 */
/* @0x1091d4 movteq r3, #0xc010 */
/* @0x1091d8 vmovne s15, r2 */
/* @0x1091dc vcvtne.f64.s32 d7, s15 */
/* @0x1091e0 vmovne r2, r3, d7 */
/* @0x1091e4 stm r5, {r2, r3} */
/* @0x1091e8 add sp, sp, #28 */
/* @0x1091ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1091f0 · F_CollisionCircle(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x1091f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1091f4 vpush {d8, d9} */
/* @0x1091f8 sub sp, sp, #16 */
/* @0x1091fc mov r5, r0 */
/* @0x109200 mov r6, r1 */
/* @0x109204 ldr r4, [sp, #0x38] */
/* @0x109208 mov r1, #0 */
/* @0x10920c mov r0, r4 */
/* @0x109210 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109214 mov r1, #1 */
/* @0x109218 vmov s17, r0 */
/* @0x10921c mov r0, r4 */
/* @0x109220 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109224 mov r1, #2 */
/* @0x109228 vmov s18, r0 */
/* @0x10922c mov r0, r4 */
/* @0x109230 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109234 mov r1, #3 */
/* @0x109238 vmov s16, r0 */
/* @0x10923c mov r0, r4 */
/* @0x109240 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109244 mov r1, #4 */
/* @0x109248 mov r8, r0 */
/* @0x10924c mov r0, r4 */
/* @0x109250 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109254 mov r1, #5 */
/* @0x109258 mov r7, r0 */
/* @0x10925c mov r0, r4 */
/* @0x109260 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109264 vadd.f32 s15, s18, s16 */
/* @0x109268 str r8, [sp, #0x4] */
/* @0x10926c str r7, [sp, #0x8] */
/* @0x109270 vsub.f32 s14, s17, s16 */
/* @0x109274 vstr s15, [sp] */
/* @0x109278 vsub.f32 s18, s18, s16 */
/* @0x10927c vmov r1, s14 */
/* @0x109280 vadd.f32 s16, s17, s16 */
/* @0x109284 vmov r2, s18 */
/* @0x109288 str r0, [sp, #0xc] */
/* @0x10928c mov r0, r6 */
/* @0x109290 vmov r3, s16 */
/* @0x109294 bl 0x1c8bb4 <_Z24Command_CollisionEllipseP9CInstanceffffibb> */
/* @0x109298 mov r3, #0 */
/* @0x10929c str r3, [r5, #0xc] */
/* @0x1092a0 cmp r0, #0 */
/* @0x1092a4 ldrne r2, [r0, #0x78] */
/* @0x1092a8 moveq r3, #0 */
/* @0x1092ac moveq r2, #0 */
/* @0x1092b0 movteq r3, #0xc010 */
/* @0x1092b4 vmovne s15, r2 */
/* @0x1092b8 vcvtne.f64.s32 d7, s15 */
/* @0x1092bc vmovne r2, r3, d7 */
/* @0x1092c0 stm r5, {r2, r3} */
/* @0x1092c4 add sp, sp, #16 */
/* @0x1092c8 vpop {d8, d9} */
/* @0x1092cc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1092d0 · F_CollisionLine(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x1092d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1092d4 sub sp, sp, #28 */
/* @0x1092d8 mov r5, r0 */
/* @0x1092dc mov r6, r1 */
/* @0x1092e0 ldr r4, [sp, #0x40] */
/* @0x1092e4 mov r1, #0 */
/* @0x1092e8 mov r0, r4 */
/* @0x1092ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1092f0 mov r1, #1 */
/* @0x1092f4 mov r9, r0 */
/* @0x1092f8 mov r0, r4 */
/* @0x1092fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109300 mov r1, #2 */
/* @0x109304 mov r8, r0 */
/* @0x109308 mov r0, r4 */
/* @0x10930c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109310 mov r1, #3 */
/* @0x109314 mov r7, r0 */
/* @0x109318 mov r0, r4 */
/* @0x10931c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109320 mov r1, #4 */
/* @0x109324 mov r3, r0 */
/* @0x109328 mov r0, r4 */
/* @0x10932c str r3, [sp, #0x14] */
/* @0x109330 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109334 mov r1, #5 */
/* @0x109338 mov r11, r0 */
/* @0x10933c mov r0, r4 */
/* @0x109340 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109344 mov r1, #6 */
/* @0x109348 mov r10, r0 */
/* @0x10934c mov r0, r4 */
/* @0x109350 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109354 ldr r3, [sp, #0x14] */
/* @0x109358 mov r2, r8 */
/* @0x10935c str r11, [sp, #0x4] */
/* @0x109360 str r10, [sp, #0x8] */
/* @0x109364 mov r1, r9 */
/* @0x109368 str r3, [sp] */
/* @0x10936c mov r3, r7 */
/* @0x109370 str r0, [sp, #0xc] */
/* @0x109374 mov r0, r6 */
/* @0x109378 bl 0x1cb390 <_Z21Command_CollisionLineP9CInstanceffffibb> */
/* @0x10937c mov r3, #0 */
/* @0x109380 str r3, [r5, #0xc] */
/* @0x109384 cmp r0, #0 */
/* @0x109388 ldrne r2, [r0, #0x78] */
/* @0x10938c moveq r3, #0 */
/* @0x109390 moveq r2, #0 */
/* @0x109394 movteq r3, #0xc010 */
/* @0x109398 vmovne s15, r2 */
/* @0x10939c vcvtne.f64.s32 d7, s15 */
/* @0x1093a0 vmovne r2, r3, d7 */
/* @0x1093a4 stm r5, {r2, r3} */
/* @0x1093a8 add sp, sp, #28 */
/* @0x1093ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1093b0 · F_InstancePosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1093b0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1093b4 mov r1, #0 */
/* @0x1093b8 ldr r4, [sp, #0x18] */
/* @0x1093bc mov r5, r0 */
/* @0x1093c0 mov r0, r4 */
/* @0x1093c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1093c8 mov r1, #1 */
/* @0x1093cc mov r7, r0 */
/* @0x1093d0 mov r0, r4 */
/* @0x1093d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1093d8 mov r1, #2 */
/* @0x1093dc mov r6, r0 */
/* @0x1093e0 mov r0, r4 */
/* @0x1093e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1093e8 mov r1, r6 */
/* @0x1093ec mov r2, r0 */
/* @0x1093f0 mov r0, r7 */
/* @0x1093f4 bl 0x1c90cc <_Z24Command_InstancePositionffi> */
/* @0x1093f8 mov r3, #0 */
/* @0x1093fc str r3, [r5, #0xc] */
/* @0x109400 cmp r0, #0 */
/* @0x109404 ldrne r2, [r0, #0x78] */
/* @0x109408 moveq r3, #0 */
/* @0x10940c moveq r2, #0 */
/* @0x109410 movteq r3, #0xc010 */
/* @0x109414 vmovne s15, r2 */
/* @0x109418 vcvtne.f64.s32 d7, s15 */
/* @0x10941c vmovne r2, r3, d7 */
/* @0x109420 stm r5, {r2, r3} */
/* @0x109424 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x109428 · F_InstanceNearest(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x109428 push {r3, r4, r5, r6, r7, lr} */
/* @0x10942c mov r1, #0 */
/* @0x109430 ldr r4, [sp, #0x18] */
/* @0x109434 mov r5, r0 */
/* @0x109438 mov r0, r4 */
/* @0x10943c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109440 mov r1, #1 */
/* @0x109444 mov r7, r0 */
/* @0x109448 mov r0, r4 */
/* @0x10944c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109450 mov r1, #2 */
/* @0x109454 mov r6, r0 */
/* @0x109458 mov r0, r4 */
/* @0x10945c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109460 mov r1, r6 */
/* @0x109464 mov r2, r0 */
/* @0x109468 mov r0, r7 */
/* @0x10946c bl 0x1c9290 <_Z23Command_InstanceNearestffi> */
/* @0x109470 mov r3, #0 */
/* @0x109474 str r3, [r5, #0xc] */
/* @0x109478 cmp r0, #0 */
/* @0x10947c ldrne r2, [r0, #0x78] */
/* @0x109480 moveq r3, #0 */
/* @0x109484 moveq r2, #0 */
/* @0x109488 movteq r3, #0xc010 */
/* @0x10948c vmovne s15, r2 */
/* @0x109490 vcvtne.f64.s32 d7, s15 */
/* @0x109494 vmovne r2, r3, d7 */
/* @0x109498 stm r5, {r2, r3} */
/* @0x10949c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1094a0 · F_InstanceFurthest(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1094a0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1094a4 mov r1, #0 */
/* @0x1094a8 ldr r4, [sp, #0x18] */
/* @0x1094ac mov r5, r0 */
/* @0x1094b0 mov r0, r4 */
/* @0x1094b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1094b8 mov r1, #1 */
/* @0x1094bc mov r7, r0 */
/* @0x1094c0 mov r0, r4 */
/* @0x1094c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1094c8 mov r1, #2 */
/* @0x1094cc mov r6, r0 */
/* @0x1094d0 mov r0, r4 */
/* @0x1094d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1094d8 mov r1, r6 */
/* @0x1094dc mov r2, r0 */
/* @0x1094e0 mov r0, r7 */
/* @0x1094e4 bl 0x1c9414 <_Z24Command_InstanceFurthestffi> */
/* @0x1094e8 mov r3, #0 */
/* @0x1094ec str r3, [r5, #0xc] */
/* @0x1094f0 cmp r0, #0 */
/* @0x1094f4 ldrne r2, [r0, #0x78] */
/* @0x1094f8 moveq r3, #0 */
/* @0x1094fc moveq r2, #0 */
/* @0x109500 movteq r3, #0xc010 */
/* @0x109504 vmovne s15, r2 */
/* @0x109508 vcvtne.f64.s32 d7, s15 */
/* @0x10950c vmovne r2, r3, d7 */
/* @0x109510 stm r5, {r2, r3} */
/* @0x109514 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x109518 · F_InstancePlace(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x109518 push {r4, r5, r6, r7, r8, lr} */
/* @0x10951c mov r5, r0 */
/* @0x109520 ldr r4, [sp, #0x18] */
/* @0x109524 mov r8, r1 */
/* @0x109528 mov r1, #0 */
/* @0x10952c mov r0, r4 */
/* @0x109530 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109534 mov r1, #1 */
/* @0x109538 mov r7, r0 */
/* @0x10953c mov r0, r4 */
/* @0x109540 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109544 mov r1, #2 */
/* @0x109548 mov r6, r0 */
/* @0x10954c mov r0, r4 */
/* @0x109550 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109554 mov r2, r6 */
/* @0x109558 mov r1, r7 */
/* @0x10955c mov r3, r0 */
/* @0x109560 mov r0, r8 */
/* @0x109564 bl 0x1ca6d8 <_Z21Command_InstancePlaceP9CInstanceffi> */
/* @0x109568 mov r3, #0 */
/* @0x10956c str r3, [r5, #0xc] */
/* @0x109570 cmp r0, #0 */
/* @0x109574 ldrne r2, [r0, #0x78] */
/* @0x109578 moveq r3, #0 */
/* @0x10957c moveq r2, #0 */
/* @0x109580 movteq r3, #0xc010 */
/* @0x109584 vmovne s15, r2 */
/* @0x109588 vcvtne.f64.s32 d7, s15 */
/* @0x10958c vmovne r2, r3, d7 */
/* @0x109590 stm r5, {r2, r3} */
/* @0x109594 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x109598 · F_InstanceCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x109598 push {r3, r4, r5, r6, r7, lr} */
/* @0x10959c mov r1, #2 */
/* @0x1095a0 ldr r4, [sp, #0x18] */
/* @0x1095a4 mov r5, r0 */
/* @0x1095a8 mov r0, r4 */
/* @0x1095ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1095b0 mov r1, #0 */
/* @0x1095b4 mov r7, r0 */
/* @0x1095b8 mov r0, r4 */
/* @0x1095bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1095c0 mov r1, #1 */
/* @0x1095c4 mov r6, r0 */
/* @0x1095c8 mov r0, r4 */
/* @0x1095cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1095d0 mov r1, r6 */
/* @0x1095d4 mov r2, r0 */
/* @0x1095d8 mov r0, r7 */
/* @0x1095dc bl 0x1c983c <_Z14Command_Createiff> */
/* @0x1095e0 ldr r3, [pc, #0x48] */
/* @0x1095e4 ldr r3, [pc, r3] */
/* @0x1095e8 ldrb r3, [r3] */
/* @0x1095ec cmp r3, #0 */
/* @0x1095f0 bne 0x109620 <_Z16F_InstanceCreateR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1095f4 cmp r0, #0 */
/* @0x1095f8 str r3, [r5, #0xc] */
/* @0x1095fc ldrne r2, [r0, #0x78] */
/* @0x109600 moveq r3, #0 */
/* @0x109604 moveq r2, #0 */
/* @0x109608 movteq r3, #0xbff0 */
/* @0x10960c vmovne s15, r2 */
/* @0x109610 vcvtne.f64.s32 d7, s15 */
/* @0x109614 vmovne r2, r3, d7 */
/* @0x109618 stm r5, {r2, r3} */
/* @0x10961c pop {r3, r4, r5, r6, r7, pc} */
/* @0x109620 mov r3, #6 */
/* @0x109624 str r0, [r5] */
/* @0x109628 str r3, [r5, #0xc] */
/* @0x10962c pop {r3, r4, r5, r6, r7, pc} */
/* @0x109630 .word 0x002e45d4 */

/* ── FUNC 0x109634 · F_InstanceCreateDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x109634 push {r4, r5, r6, r7, r8, lr} */
/* @0x109638 mov r1, #3 */
/* @0x10963c ldr r4, [sp, #0x18] */
/* @0x109640 mov r5, r0 */
/* @0x109644 mov r0, r4 */
/* @0x109648 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10964c mov r1, #0 */
/* @0x109650 mov r8, r0 */
/* @0x109654 mov r0, r4 */
/* @0x109658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10965c mov r1, #1 */
/* @0x109660 mov r7, r0 */
/* @0x109664 mov r0, r4 */
/* @0x109668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10966c mov r1, #2 */
/* @0x109670 mov r6, r0 */
/* @0x109674 mov r0, r4 */
/* @0x109678 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10967c mov r1, r7 */
/* @0x109680 mov r2, r6 */
/* @0x109684 mov r3, r0 */
/* @0x109688 mov r0, r8 */
/* @0x10968c bl 0x1c98d4 <_Z20Command_Create_Depthiffi> */
/* @0x109690 ldr r3, [pc, #0x48] */
/* @0x109694 ldr r3, [pc, r3] */
/* @0x109698 ldrb r3, [r3] */
/* @0x10969c cmp r3, #0 */
/* @0x1096a0 bne 0x1096d0 <_Z21F_InstanceCreateDepthR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1096a4 cmp r0, #0 */
/* @0x1096a8 str r3, [r5, #0xc] */
/* @0x1096ac ldrne r2, [r0, #0x78] */
/* @0x1096b0 moveq r3, #0 */
/* @0x1096b4 moveq r2, #0 */
/* @0x1096b8 movteq r3, #0xbff0 */
/* @0x1096bc vmovne s15, r2 */
/* @0x1096c0 vcvtne.f64.s32 d7, s15 */
/* @0x1096c4 vmovne r2, r3, d7 */
/* @0x1096c8 stm r5, {r2, r3} */
/* @0x1096cc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1096d0 mov r3, #6 */
/* @0x1096d4 str r0, [r5] */
/* @0x1096d8 str r3, [r5, #0xc] */
/* @0x1096dc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1096e0 eoreq r4, lr, r4, lsr #10 */
