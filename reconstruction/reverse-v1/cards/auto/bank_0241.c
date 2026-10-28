/* libyoyo.so 覆盖卡组 0241
 * 函数 0x28ee80..0x28fe70，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x28ee80 · spSlot_setToSetupPose · size=108 · insn=27 */
/* @0x28ee80 ldr r3, [r0] */
/* @0x28ee84 push {r4, lr} */
/* @0x28ee88 mov r4, r0 */
/* @0x28ee8c ldr r1, [r3, #0x10] */
/* @0x28ee90 ldr r2, [r3, #0x14] */
/* @0x28ee94 str r1, [r0, #0x8] */
/* @0x28ee98 ldr r1, [r3, #0x18] */
/* @0x28ee9c str r2, [r0, #0xc] */
/* @0x28eea0 ldr r2, [r3, #0xc] */
/* @0x28eea4 str r1, [r0, #0x10] */
/* @0x28eea8 ldr r1, [r3, #0x1c] */
/* @0x28eeac cmp r2, #0 */
/* @0x28eeb0 str r1, [r0, #0x14] */
/* @0x28eeb4 beq 0x28eee0 <spSlot_setToSetupPose+0x60> */
/* @0x28eeb8 ldr r0, [r0, #0x4] */
/* @0x28eebc ldr r1, [r3] */
/* @0x28eec0 ldr r0, [r0, #0x4] */
/* @0x28eec4 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex> */
/* @0x28eec8 mov r3, #0 */
/* @0x28eecc str r3, [r4, #0x18] */
/* @0x28eed0 mov r1, r0 */
/* @0x28eed4 mov r0, r4 */
/* @0x28eed8 pop {r4, lr} */
/* @0x28eedc b 0x28ee1c <spSlot_setAttachment> */
/* @0x28eee0 mov r1, r2 */
/* @0x28eee4 pop {r4, lr} */
/* @0x28eee8 b 0x28ee1c <spSlot_setAttachment> */

/* ── FUNC 0x28eeec · spSlot_create · size=64 · insn=16 */
/* @0x28eeec ldr r2, [pc, #0x34] */
/* @0x28eef0 mov r3, #41 */
/* @0x28eef4 push {r4, r5, r6, lr} */
/* @0x28eef8 add r2, pc, r2 */
/* @0x28eefc mov r6, r0 */
/* @0x28ef00 mov r5, r1 */
/* @0x28ef04 mov r0, #1 */
/* @0x28ef08 mov r1, #44 */
/* @0x28ef0c bl 0x285c4c <_calloc> */
/* @0x28ef10 mov r4, r0 */
/* @0x28ef14 str r6, [r0] */
/* @0x28ef18 str r5, [r0, #0x4] */
/* @0x28ef1c bl 0x28ee80 <spSlot_setToSetupPose> */
/* @0x28ef20 mov r0, r4 */
/* @0x28ef24 pop {r4, r5, r6, pc} */
/* @0x28ef28 andeq r9, r12, r4, asr #1 */

/* ── FUNC 0x28ef2c · spSlotData_create · size=124 · insn=31 */
/* @0x28ef2c push {r4, r5, r6, r7, r8, lr} */
/* @0x28ef30 mov r5, r1 */
/* @0x28ef34 ldr r6, [pc, #0x68] */
/* @0x28ef38 mov r1, #36 */
/* @0x28ef3c mov r3, r1 */
/* @0x28ef40 mov r8, r0 */
/* @0x28ef44 add r6, pc, r6 */
/* @0x28ef48 mov r7, r2 */
/* @0x28ef4c mov r0, #1 */
/* @0x28ef50 mov r2, r6 */
/* @0x28ef54 bl 0x285c4c <_calloc> */
/* @0x28ef58 mov r4, r0 */
/* @0x28ef5c str r8, [r0] */
/* @0x28ef60 mov r0, r5 */
/* @0x28ef64 bl 0xb6538 <strlen@plt> */
/* @0x28ef68 mov r1, r6 */
/* @0x28ef6c mov r2, #38 */
/* @0x28ef70 add r0, r0, #1 */
/* @0x28ef74 bl 0x285c10 <_malloc> */
/* @0x28ef78 mov r1, r5 */
/* @0x28ef7c str r0, [r4, #0x4] */
/* @0x28ef80 bl 0xb65a4 <strcpy@plt> */
/* @0x28ef84 mov r3, #1065353216 */
/* @0x28ef88 str r7, [r4, #0x8] */
/* @0x28ef8c mov r0, r4 */
/* @0x28ef90 str r3, [r4, #0x10] */
/* @0x28ef94 str r3, [r4, #0x14] */
/* @0x28ef98 str r3, [r4, #0x18] */
/* @0x28ef9c str r3, [r4, #0x1c] */
/* @0x28efa0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28efa4 andeq r9, r12, r12, lsr #1 */

/* ── FUNC 0x28efa8 · spSlotData_dispose · size=36 · insn=9 */
/* @0x28efa8 push {r4, lr} */
/* @0x28efac mov r4, r0 */
/* @0x28efb0 ldr r0, [r0, #0x4] */
/* @0x28efb4 bl 0x285c80 <_free> */
/* @0x28efb8 ldr r0, [r4, #0xc] */
/* @0x28efbc bl 0x285c80 <_free> */
/* @0x28efc0 mov r0, r4 */
/* @0x28efc4 pop {r4, lr} */
/* @0x28efc8 b 0x285c80 <_free> */

/* ── FUNC 0x28efcc · spSlotData_setAttachmentName · size=80 · insn=20 */
/* @0x28efcc push {r3, r4, r5, lr} */
/* @0x28efd0 mov r5, r0 */
/* @0x28efd4 ldr r0, [r0, #0xc] */
/* @0x28efd8 mov r4, r1 */
/* @0x28efdc bl 0x285c80 <_free> */
/* @0x28efe0 cmp r4, #0 */
/* @0x28efe4 streq r4, [r5, #0xc] */
/* @0x28efe8 popeq {r3, r4, r5, pc} */
/* @0x28efec mov r0, r4 */
/* @0x28eff0 bl 0xb6538 <strlen@plt> */
/* @0x28eff4 ldr r1, [pc, #0x1c] */
/* @0x28eff8 mov r2, #56 */
/* @0x28effc add r1, pc, r1 */
/* @0x28f000 add r0, r0, #1 */
/* @0x28f004 bl 0x285c10 <_malloc> */
/* @0x28f008 mov r1, r4 */
/* @0x28f00c str r0, [r5, #0xc] */
/* @0x28f010 pop {r3, r4, r5, lr} */
/* @0x28f014 b 0xb65a4 <strcpy@plt> */
/* @0x28f018 strdeq r8, r9, [r12], -r4 */

/* ── FUNC 0x28f01c · spTransformConstraint_create · size=216 · insn=54 */
/* @0x28f01c push {r3, r4, r5, r6, r7, lr} */
/* @0x28f020 mov r4, r0 */
/* @0x28f024 ldr r6, [pc, #0xc4] */
/* @0x28f028 mov r3, #38 */
/* @0x28f02c mov r7, r1 */
/* @0x28f030 mov r0, #1 */
/* @0x28f034 add r6, pc, r6 */
/* @0x28f038 mov r1, #32 */
/* @0x28f03c mov r2, r6 */
/* @0x28f040 bl 0x285c4c <_calloc> */
/* @0x28f044 ldr r2, [r4, #0x10] */
/* @0x28f048 ldr r3, [r4, #0x14] */
/* @0x28f04c mov r1, r6 */
/* @0x28f050 mov r5, r0 */
/* @0x28f054 ldr r0, [r4, #0x4] */
/* @0x28f058 str r2, [r5, #0x10] */
/* @0x28f05c str r3, [r5, #0x14] */
/* @0x28f060 ldr r2, [r4, #0x18] */
/* @0x28f064 ldr r3, [r4, #0x1c] */
/* @0x28f068 str r4, [r5] */
/* @0x28f06c str r2, [r5, #0x18] */
/* @0x28f070 mov r2, #45 */
/* @0x28f074 str r3, [r5, #0x1c] */
/* @0x28f078 str r0, [r5, #0x4] */
/* @0x28f07c lsl r0, r0, #2 */
/* @0x28f080 bl 0x285c10 <_malloc> */
/* @0x28f084 ldr r3, [r5, #0x4] */
/* @0x28f088 cmp r3, #0 */
/* @0x28f08c str r0, [r5, #0x8] */
/* @0x28f090 ble 0x28f0d0 <spTransformConstraint_create+0xb4> */
/* @0x28f094 mov r6, r0 */
/* @0x28f098 mov r4, #0 */
/* @0x28f09c b 0x28f0a4 <spTransformConstraint_create+0x88> */
/* @0x28f0a0 ldr r6, [r5, #0x8] */
/* @0x28f0a4 ldr r3, [r5] */
/* @0x28f0a8 mov r0, r7 */
/* @0x28f0ac ldr r3, [r3, #0x8] */
/* @0x28f0b0 ldr r3, [r3, r4, lsl #2] */
/* @0x28f0b4 ldr r1, [r3, #0x4] */
/* @0x28f0b8 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0x28f0bc ldr r3, [r5, #0x4] */
/* @0x28f0c0 str r0, [r6, r4, lsl #2] */
/* @0x28f0c4 add r4, r4, #1 */
/* @0x28f0c8 cmp r3, r4 */
/* @0x28f0cc bgt 0x28f0a0 <spTransformConstraint_create+0x84> */
/* @0x28f0d0 ldr r3, [r5] */
/* @0x28f0d4 mov r0, r7 */
/* @0x28f0d8 ldr r3, [r3, #0xc] */
/* @0x28f0dc ldr r1, [r3, #0x4] */
/* @0x28f0e0 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0x28f0e4 str r0, [r5, #0xc] */
/* @0x28f0e8 mov r0, r5 */
/* @0x28f0ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x28f0f0 strdeq r8, r9, [r12], -r4 */

/* ── FUNC 0x28f0f4 · spTransformConstraint_dispose · size=28 · insn=7 */
/* @0x28f0f4 push {r4, lr} */
/* @0x28f0f8 mov r4, r0 */
/* @0x28f0fc ldr r0, [r0, #0x8] */
/* @0x28f100 bl 0x285c80 <_free> */
/* @0x28f104 mov r0, r4 */
/* @0x28f108 pop {r4, lr} */
/* @0x28f10c b 0x285c80 <_free> */

/* ── FUNC 0x28f110 · spTransformConstraint_apply · size=1184 · insn=296 */
/* @0x28f110 ldr r3, [r0, #0x4] */
/* @0x28f114 push {r4, r5, r6, r7, lr} */
/* @0x28f118 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x28f11c cmp r3, #0 */
/* @0x28f120 vldr s26, [r0, #16] */
/* @0x28f124 ldr r7, [r0, #0xc] */
/* @0x28f128 sub sp, sp, #20 */
/* @0x28f12c mov r5, r0 */
/* @0x28f130 vldr s21, [r0, #20] */
/* @0x28f134 vldr s28, [r0, #24] */
/* @0x28f138 vldr s19, [r7, #52] */
/* @0x28f13c vldr s24, [r7, #56] */
/* @0x28f140 vldr s20, [r7, #64] */
/* @0x28f144 vldr s25, [r7, #68] */
/* @0x28f148 vldr s27, [r0, #28] */
/* @0x28f14c ble 0x28f554 <spTransformConstraint_apply+0x444> */
/* @0x28f150 mov r6, #0 */
/* @0x28f154 vldr s29, [pc, #1008] */
/* @0x28f158 b 0x28f47c <spTransformConstraint_apply+0x36c> */
/* @0x28f15c movt r3, #0x40c9 */
/* @0x28f160 vmov s8, r3 */
/* @0x28f164 vsub.f32 s16, s16, s8 */
/* @0x28f168 vmul.f32 s16, s16, s26 */
/* @0x28f16c vcvt.f64.f32 d8, s16 */
/* @0x28f170 vmov r0, r1, d8 */
/* @0x28f174 bl 0xb67e4 <cos@plt> */
/* @0x28f178 vmov d5, r0, r1 */
/* @0x28f17c vmov r0, r1, d8 */
/* @0x28f180 vcvt.f32.f64 s18, d5 */
/* @0x28f184 bl 0xb67d8 <sin@plt> */
/* @0x28f188 vmul.f32 s13, s18, s23 */
/* @0x28f18c vmul.f32 s14, s18, s31 */
/* @0x28f190 vmov d4, r0, r1 */
/* @0x28f194 vcvt.f32.f64 s15, d4 */
/* @0x28f198 vmul.f32 s23, s15, s23 */
/* @0x28f19c vmul.f32 s31, s15, s31 */
/* @0x28f1a0 vmla.f32 s13, s15, s22 */
/* @0x28f1a4 vnmls.f32 s23, s18, s22 */
/* @0x28f1a8 vstr s13, [r4, #64] */
/* @0x28f1ac vnmls.f32 s31, s18, s30 */
/* @0x28f1b0 vstr s23, [r4, #52] */
/* @0x28f1b4 vmla.f32 s14, s15, s30 */
/* @0x28f1b8 vstr s31, [r4, #56] */
/* @0x28f1bc vstr s14, [r4, #68] */
/* @0x28f1c0 vcmpe.f32 s21, #0 */
/* @0x28f1c4 vmrs APSR_nzcv, fpscr */
/* @0x28f1c8 ble 0x28f214 <spTransformConstraint_apply+0x104> */
/* @0x28f1cc ldr r3, [r5] */
/* @0x28f1d0 add r12, sp, #12 */
/* @0x28f1d4 mov r0, r7 */
/* @0x28f1d8 ldr r1, [r3, #0x24] */
/* @0x28f1dc ldr r2, [r3, #0x28] */
/* @0x28f1e0 add r3, sp, #8 */
/* @0x28f1e4 str r12, [sp] */
/* @0x28f1e8 bl 0x2859fc <spBone_localToWorld> */
/* @0x28f1ec vldr s14, [r4, #60] */
/* @0x28f1f0 vldr s15, [r4, #72] */
/* @0x28f1f4 vldr s12, [sp, #8] */
/* @0x28f1f8 vldr s13, [sp, #12] */
/* @0x28f1fc vsub.f32 s12, s12, s14 */
/* @0x28f200 vsub.f32 s13, s13, s15 */
/* @0x28f204 vmla.f32 s14, s12, s21 */
/* @0x28f208 vmla.f32 s15, s13, s21 */
/* @0x28f20c vstr s14, [r4, #60] */
/* @0x28f210 vstr s15, [r4, #72] */
/* @0x28f214 vcmpe.f32 s28, #0 */
/* @0x28f218 vmrs APSR_nzcv, fpscr */
/* @0x28f21c ble 0x28f348 <spTransformConstraint_apply+0x238> */
/* @0x28f220 vldr s12, [r4, #64] */
/* @0x28f224 vmul.f32 s12, s12, s12 */
/* @0x28f228 vldr s15, [r4, #52] */
/* @0x28f22c vmla.f32 s12, s15, s15 */
/* @0x28f230 vcvt.f64.f32 d6, s12 */
/* @0x28f234 vsqrt.f64 d7, d6 */
/* @0x28f238 vcmp.f64 d7, d7 */
/* @0x28f23c vmrs APSR_nzcv, fpscr */
/* @0x28f240 bne 0x28f560 <spTransformConstraint_apply+0x450> */
/* @0x28f244 vmul.f32 s10, s20, s20 */
/* @0x28f248 vmla.f32 s10, s19, s19 */
/* @0x28f24c vcvt.f64.f32 d5, s10 */
/* @0x28f250 vsqrt.f64 d6, d5 */
/* @0x28f254 vcmp.f64 d6, d6 */
/* @0x28f258 vcvt.f32.f64 s16, d7 */
/* @0x28f25c vmrs APSR_nzcv, fpscr */
/* @0x28f260 bne 0x28f5a0 <spTransformConstraint_apply+0x490> */
/* @0x28f264 movw r3, #0xc5ac */
/* @0x28f268 movt r3, #0x3727 */
/* @0x28f26c vldr s11, [r4, #52] */
/* @0x28f270 vldr s10, [r4, #64] */
/* @0x28f274 vmov s8, r3 */
/* @0x28f278 vcmpe.f32 s16, s8 */
/* @0x28f27c vmrs APSR_nzcv, fpscr */
/* @0x28f280 vcvtgt.f32.f64 s12, d6 */
/* @0x28f284 ldrgt r3, [r5] */
/* @0x28f288 vldrgt s15, [r3, #44] */
/* @0x28f28c vldrle s16, [pc, #700] */
/* @0x28f290 vsubgt.f32 s12, s12, s16 */
/* @0x28f294 vaddgt.f32 s12, s12, s15 */
/* @0x28f298 vldr s15, [r4, #56] */
/* @0x28f29c vmovgt.f32 s14, s16 */
/* @0x28f2a0 vmlagt.f32 s14, s12, s28 */
/* @0x28f2a4 vldr s12, [r4, #68] */
/* @0x28f2a8 vmul.f32 s12, s12, s12 */
/* @0x28f2ac vmla.f32 s12, s15, s15 */
/* @0x28f2b0 vcvt.f64.f32 d6, s12 */
/* @0x28f2b4 vdivgt.f32 s16, s14, s16 */
/* @0x28f2b8 vsqrt.f64 d7, d6 */
/* @0x28f2bc vmul.f32 s11, s11, s16 */
/* @0x28f2c0 vmul.f32 s16, s10, s16 */
/* @0x28f2c4 vstr s11, [r4, #52] */
/* @0x28f2c8 vcmp.f64 d7, d7 */
/* @0x28f2cc vstr s16, [r4, #64] */
/* @0x28f2d0 vmrs APSR_nzcv, fpscr */
/* @0x28f2d4 bne 0x28f590 <spTransformConstraint_apply+0x480> */
/* @0x28f2d8 vmul.f32 s10, s25, s25 */
/* @0x28f2dc vmla.f32 s10, s24, s24 */
/* @0x28f2e0 vcvt.f64.f32 d5, s10 */
/* @0x28f2e4 vsqrt.f64 d6, d5 */
/* @0x28f2e8 vcmp.f64 d6, d6 */
/* @0x28f2ec vcvt.f32.f64 s16, d7 */
/* @0x28f2f0 vmrs APSR_nzcv, fpscr */
/* @0x28f2f4 bne 0x28f580 <spTransformConstraint_apply+0x470> */
/* @0x28f2f8 movw r3, #0xc5ac */
/* @0x28f2fc movt r3, #0x3727 */
/* @0x28f300 vmov s8, r3 */
/* @0x28f304 vcmpe.f32 s16, s8 */
/* @0x28f308 vmrs APSR_nzcv, fpscr */
/* @0x28f30c vcvtgt.f32.f64 s12, d6 */
/* @0x28f310 ldrgt r3, [r5] */
/* @0x28f314 vldrgt s15, [r3, #48] */
/* @0x28f318 vldrle s16, [pc, #560] */
/* @0x28f31c vsubgt.f32 s12, s12, s16 */
/* @0x28f320 vaddgt.f32 s12, s12, s15 */
/* @0x28f324 vldr s15, [r4, #56] */
/* @0x28f328 vmovgt.f32 s14, s16 */
/* @0x28f32c vmlagt.f32 s14, s12, s28 */
/* @0x28f330 vdivgt.f32 s16, s14, s16 */
/* @0x28f334 vldr s14, [r4, #68] */
/* @0x28f338 vmul.f32 s15, s15, s16 */
/* @0x28f33c vmul.f32 s16, s14, s16 */
/* @0x28f340 vstr s15, [r4, #56] */
/* @0x28f344 vstr s16, [r4, #68] */
/* @0x28f348 vcmpe.f32 s27, #0 */
/* @0x28f34c vmrs APSR_nzcv, fpscr */
/* @0x28f350 ble 0x28f46c <spTransformConstraint_apply+0x35c> */
/* @0x28f354 vldr s17, [r4, #56] */
/* @0x28f358 vldr s18, [r4, #68] */
/* @0x28f35c vcvt.f64.f32 d5, s17 */
/* @0x28f360 vcvt.f64.f32 d6, s18 */
/* @0x28f364 vmov r2, r3, d5 */
/* @0x28f368 vmov r0, r1, d6 */
/* @0x28f36c bl 0xb6c70 <atan2@plt> */
/* @0x28f370 vcvt.f64.f32 d5, s25 */
/* @0x28f374 vcvt.f64.f32 d7, s24 */
/* @0x28f378 vmov r2, r3, d7 */
/* @0x28f37c vmov d4, r0, r1 */
/* @0x28f380 vmov r0, r1, d5 */
/* @0x28f384 vcvt.f32.f64 s16, d4 */
/* @0x28f388 bl 0xb6c70 <atan2@plt> */
/* @0x28f38c vcvt.f64.f32 d6, s19 */
/* @0x28f390 vcvt.f64.f32 d7, s20 */
/* @0x28f394 vmov r2, r3, d6 */
/* @0x28f398 vmov d11, r0, r1 */
/* @0x28f39c vmov r0, r1, d7 */
/* @0x28f3a0 bl 0xb6c70 <atan2@plt> */
/* @0x28f3a4 vldr s14, [r4, #64] */
/* @0x28f3a8 vldr s15, [r4, #52] */
/* @0x28f3ac vcvt.f64.f32 d4, s14 */
/* @0x28f3b0 vcvt.f64.f32 d5, s15 */
/* @0x28f3b4 vmov r2, r3, d5 */
/* @0x28f3b8 vmov d15, r0, r1 */
/* @0x28f3bc vmov r0, r1, d4 */
/* @0x28f3c0 bl 0xb6c70 <atan2@plt> */
/* @0x28f3c4 vmul.f32 s18, s18, s18 */
/* @0x28f3c8 vmla.f32 s18, s17, s17 */
/* @0x28f3cc vmov d4, r0, r1 */
/* @0x28f3d0 vcvt.f64.f32 d6, s18 */
/* @0x28f3d4 vsqrt.f64 d7, d6 */
/* @0x28f3d8 vcvt.f32.f64 s22, d11 */
/* @0x28f3dc vcvt.f32.f64 s30, d15 */
/* @0x28f3e0 vcvt.f32.f64 s11, d4 */
/* @0x28f3e4 vsub.f32 s22, s22, s30 */
/* @0x28f3e8 vsub.f32 s11, s16, s11 */
/* @0x28f3ec vcmp.f64 d7, d7 */
/* @0x28f3f0 vsub.f32 s22, s22, s11 */
/* @0x28f3f4 vmrs APSR_nzcv, fpscr */
/* @0x28f3f8 bne 0x28f570 <spTransformConstraint_apply+0x460> */
/* @0x28f3fc movw r3, #0xfdb */
/* @0x28f400 movt r3, #0x4049 */
/* @0x28f404 vmov s8, r3 */
/* @0x28f408 movw r3, #0xfdb */
/* @0x28f40c vcmpe.f32 s22, s8 */
/* @0x28f410 vcvt.f32.f64 s18, d7 */
/* @0x28f414 vmrs APSR_nzcv, fpscr */
/* @0x28f418 ble 0x28f528 <spTransformConstraint_apply+0x418> */
/* @0x28f41c movt r3, #0x40c9 */
/* @0x28f420 vmov s8, r3 */
/* @0x28f424 vsub.f32 s22, s22, s8 */
/* @0x28f428 ldr r3, [r5] */
/* @0x28f42c vldr s15, [r3, #52] */
/* @0x28f430 vmla.f32 s22, s15, s29 */
/* @0x28f434 vmla.f32 s16, s22, s27 */
/* @0x28f438 vcvt.f64.f32 d8, s16 */
/* @0x28f43c vmov r0, r1, d8 */
/* @0x28f440 bl 0xb67e4 <cos@plt> */
/* @0x28f444 vmov d5, r0, r1 */
/* @0x28f448 vcvt.f32.f64 s15, d5 */
/* @0x28f44c vmov r0, r1, d8 */
/* @0x28f450 vmul.f32 s15, s15, s18 */
/* @0x28f454 vstr s15, [r4, #56] */
/* @0x28f458 bl 0xb67d8 <sin@plt> */
/* @0x28f45c vmov d6, r0, r1 */
/* @0x28f460 vcvt.f32.f64 s15, d6 */
/* @0x28f464 vmul.f32 s18, s15, s18 */
/* @0x28f468 vstr s18, [r4, #68] */
/* @0x28f46c ldr r3, [r5, #0x4] */
/* @0x28f470 add r6, r6, #1 */
/* @0x28f474 cmp r3, r6 */
/* @0x28f478 ble 0x28f554 <spTransformConstraint_apply+0x444> */
/* @0x28f47c vcmpe.f32 s26, #0 */
/* @0x28f480 ldr r3, [r5, #0x8] */
/* @0x28f484 ldr r4, [r3, r6, lsl #2] */
/* @0x28f488 vmrs APSR_nzcv, fpscr */
/* @0x28f48c ble 0x28f1c0 <spTransformConstraint_apply+0xb0> */
/* @0x28f490 vcvt.f64.f32 d4, s20 */
/* @0x28f494 vldr s22, [r4, #52] */
/* @0x28f498 vldr s23, [r4, #64] */
/* @0x28f49c vldr s30, [r4, #56] */
/* @0x28f4a0 vldr s31, [r4, #68] */
/* @0x28f4a4 vcvt.f64.f32 d5, s19 */
/* @0x28f4a8 vmov r0, r1, d4 */
/* @0x28f4ac vmov r2, r3, d5 */
/* @0x28f4b0 bl 0xb6c70 <atan2@plt> */
/* @0x28f4b4 vcvt.f64.f32 d7, s23 */
/* @0x28f4b8 vcvt.f64.f32 d6, s22 */
/* @0x28f4bc vmov r2, r3, d6 */
/* @0x28f4c0 vmov d8, r0, r1 */
/* @0x28f4c4 vmov r0, r1, d7 */
/* @0x28f4c8 bl 0xb6c70 <atan2@plt> */
/* @0x28f4cc ldr r3, [r5] */
/* @0x28f4d0 vcvt.f32.f64 s16, d8 */
/* @0x28f4d4 vldr s15, [r3, #32] */
/* @0x28f4d8 movw r3, #0xfdb */
/* @0x28f4dc movt r3, #0x4049 */
/* @0x28f4e0 vmov d4, r0, r1 */
/* @0x28f4e4 vcvt.f32.f64 s14, d4 */
/* @0x28f4e8 vmov s8, r3 */
/* @0x28f4ec movw r3, #0xfdb */
/* @0x28f4f0 vsub.f32 s16, s16, s14 */
/* @0x28f4f4 vmla.f32 s16, s15, s29 */
/* @0x28f4f8 vcmpe.f32 s16, s8 */
/* @0x28f4fc vmrs APSR_nzcv, fpscr */
/* @0x28f500 bgt 0x28f15c <spTransformConstraint_apply+0x4c> */
/* @0x28f504 movt r3, #0xc049 */
/* @0x28f508 vmov s8, r3 */
/* @0x28f50c vcmpe.f32 s16, s8 */
/* @0x28f510 vmrs APSR_nzcv, fpscr */
/* @0x28f514 movwmi r3, #0xfdb */
/* @0x28f518 movtmi r3, #0x40c9 */
/* @0x28f51c vmovmi s8, r3 */
/* @0x28f520 vaddmi.f32 s16, s16, s8 */
/* @0x28f524 b 0x28f168 <spTransformConstraint_apply+0x58> */
/* @0x28f528 movt r3, #0xc049 */
/* @0x28f52c vmov s8, r3 */
/* @0x28f530 vcmpe.f32 s22, s8 */
/* @0x28f534 vmrs APSR_nzcv, fpscr */
/* @0x28f538 movwmi r3, #0xfdb */
/* @0x28f53c movtmi r3, #0x40c9 */
/* @0x28f540 vmovmi s8, r3 */
/* @0x28f544 vaddmi.f32 s22, s22, s8 */
/* @0x28f548 b 0x28f428 <spTransformConstraint_apply+0x318> */
/* @0x28f54c vstmialo lr, {s30, s31} */
/* @0x28f550 andeq r0, r0, r0 */
/* @0x28f554 add sp, sp, #20 */
/* @0x28f558 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x28f55c pop {r4, r5, r6, r7, pc} */
/* @0x28f560 vmov r0, r1, d6 */
/* @0x28f564 bl 0xb66f4 <sqrt@plt> */
/* @0x28f568 vmov d7, r0, r1 */
/* @0x28f56c b 0x28f244 <spTransformConstraint_apply+0x134> */
/* @0x28f570 vmov r0, r1, d6 */
/* @0x28f574 bl 0xb66f4 <sqrt@plt> */
/* @0x28f578 vmov d7, r0, r1 */
/* @0x28f57c b 0x28f3fc <spTransformConstraint_apply+0x2ec> */
/* @0x28f580 vmov r0, r1, d5 */
/* @0x28f584 bl 0xb66f4 <sqrt@plt> */
/* @0x28f588 vmov d6, r0, r1 */
/* @0x28f58c b 0x28f2f8 <spTransformConstraint_apply+0x1e8> */
/* @0x28f590 vmov r0, r1, d6 */
/* @0x28f594 bl 0xb66f4 <sqrt@plt> */
/* @0x28f598 vmov d7, r0, r1 */
/* @0x28f59c b 0x28f2d8 <spTransformConstraint_apply+0x1c8> */
/* @0x28f5a0 vmov r0, r1, d5 */
/* @0x28f5a4 bl 0xb66f4 <sqrt@plt> */
/* @0x28f5a8 vmov d6, r0, r1 */
/* @0x28f5ac b 0x28f264 <spTransformConstraint_apply+0x154> */

/* ── FUNC 0x28f5b0 · spTransformConstraintData_create · size=88 · insn=22 */
/* @0x28f5b0 push {r4, r5, r6, lr} */
/* @0x28f5b4 mov r3, #36 */
/* @0x28f5b8 ldr r6, [pc, #0x44] */
/* @0x28f5bc mov r5, r0 */
/* @0x28f5c0 mov r1, #56 */
/* @0x28f5c4 mov r0, #1 */
/* @0x28f5c8 add r6, pc, r6 */
/* @0x28f5cc mov r2, r6 */
/* @0x28f5d0 bl 0x285c4c <_calloc> */
/* @0x28f5d4 mov r4, r0 */
/* @0x28f5d8 mov r0, r5 */
/* @0x28f5dc bl 0xb6538 <strlen@plt> */
/* @0x28f5e0 mov r1, r6 */
/* @0x28f5e4 mov r2, #37 */
/* @0x28f5e8 add r0, r0, #1 */
/* @0x28f5ec bl 0x285c10 <_malloc> */
/* @0x28f5f0 mov r1, r5 */
/* @0x28f5f4 str r0, [r4] */
/* @0x28f5f8 bl 0xb65a4 <strcpy@plt> */
/* @0x28f5fc mov r0, r4 */
/* @0x28f600 pop {r4, r5, r6, pc} */
/* @0x28f604 andeq r8, r12, r4, lsr #21 */

/* ── FUNC 0x28f608 · spTransformConstraintData_dispose · size=36 · insn=9 */
/* @0x28f608 push {r4, lr} */
/* @0x28f60c mov r4, r0 */
/* @0x28f610 ldr r0, [r0] */
/* @0x28f614 bl 0x285c80 <_free> */
/* @0x28f618 ldr r0, [r4, #0x8] */
/* @0x28f61c bl 0x285c80 <_free> */
/* @0x28f620 mov r0, r4 */
/* @0x28f624 pop {r4, lr} */
/* @0x28f628 b 0x285c80 <_free> */

/* ── FUNC 0x28f62c · _spVertexAttachment_deinit · size=32 · insn=8 */
/* @0x28f62c push {r4, lr} */
/* @0x28f630 mov r4, r0 */
/* @0x28f634 bl 0x284c84 <_spAttachment_deinit> */
/* @0x28f638 ldr r0, [r4, #0x14] */
/* @0x28f63c bl 0x285c80 <_free> */
/* @0x28f640 ldr r0, [r4, #0x1c] */
/* @0x28f644 pop {r4, lr} */
/* @0x28f648 b 0x285c80 <_free> */

/* ── FUNC 0x28f64c · spVertexAttachment_computeWorldVertices1 · size=956 · insn=239 */
/* @0x28f64c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x28f650 sub sp, sp, #24 */
/* @0x28f654 ldr r6, [r0, #0x14] */
/* @0x28f658 ldr r4, [r3, #0x4] */
/* @0x28f65c ldr r0, [r0, #0x1c] */
/* @0x28f660 cmp r6, #0 */
/* @0x28f664 ldr r9, [r3, #0x20] */
/* @0x28f668 ldr r3, [r3, #0x24] */
/* @0x28f66c ldr r10, [sp, #0x3c] */
/* @0x28f670 ldr r12, [r4, #0x4] */
/* @0x28f674 vldr s3, [r12, #88] */
/* @0x28f678 str r0, [sp, #0x8] */
/* @0x28f67c add r2, r2, r10 */
/* @0x28f680 vldr s2, [r12, #92] */
/* @0x28f684 str r3, [sp, #0xc] */
/* @0x28f688 ldr r8, [sp, #0x38] */
/* @0x28f68c beq 0x28f95c <spVertexAttachment_computeWorldVertices1+0x310> */
/* @0x28f690 cmp r1, #0 */
/* @0x28f694 movle r7, #0 */
/* @0x28f698 movle r5, r7 */
/* @0x28f69c movle r4, r7 */
/* @0x28f6a0 ble 0x28f6d0 <spVertexAttachment_computeWorldVertices1+0x84> */
/* @0x28f6a4 mov r3, #0 */
/* @0x28f6a8 mov r5, r3 */
/* @0x28f6ac mov r4, r3 */
/* @0x28f6b0 ldr r0, [r6, r4, lsl #2] */
/* @0x28f6b4 add r3, r3, #2 */
/* @0x28f6b8 cmp r1, r3 */
/* @0x28f6bc add r7, r0, #1 */
/* @0x28f6c0 add r5, r5, r0 */
/* @0x28f6c4 add r4, r4, r7 */
/* @0x28f6c8 bgt 0x28f6b0 <spVertexAttachment_computeWorldVertices1+0x64> */
/* @0x28f6cc add r7, r5, r5, lsl #1 */
/* @0x28f6d0 cmp r9, #0 */
/* @0x28f6d4 ldr r12, [r12, #0x8] */
/* @0x28f6d8 bne 0x28f7e4 <spVertexAttachment_computeWorldVertices1+0x198> */
/* @0x28f6dc cmp r10, r2 */
/* @0x28f6e0 bge 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c> */
/* @0x28f6e4 mvn r3, r10 */
/* @0x28f6e8 add r3, r3, r2 */
/* @0x28f6ec bic r3, r3, #1 */
/* @0x28f6f0 add r2, r10, #1 */
/* @0x28f6f4 add r10, r3, r10 */
/* @0x28f6f8 add r3, r8, #12 */
/* @0x28f6fc add r8, r8, r2, lsl #2 */
/* @0x28f700 sub r2, r6, #4 */
/* @0x28f704 add r11, r3, r10, lsl #2 */
/* @0x28f708 str r2, [sp, #0x4] */
/* @0x28f70c ldr r5, [r6, r4, lsl #2] */
/* @0x28f710 add r9, r4, #1 */
/* @0x28f714 mov r10, r4 */
/* @0x28f718 add r1, r6, r4, lsl #2 */
/* @0x28f71c add r5, r5, r9 */
/* @0x28f720 cmp r9, r5 */
/* @0x28f724 bge 0x28f94c <spVertexAttachment_computeWorldVertices1+0x300> */
/* @0x28f728 ldr r3, [sp, #0x4] */
/* @0x28f72c add r2, r7, #2 */
/* @0x28f730 vmov.f32 s10, s2 */
/* @0x28f734 str r4, [sp, #0xc] */
/* @0x28f738 add r0, r3, r5, lsl #2 */
/* @0x28f73c ldr r3, [sp, #0x8] */
/* @0x28f740 add r2, r3, r2, lsl #2 */
/* @0x28f744 vmov.f32 s9, s3 */
/* @0x28f748 ldr r3, [r1, #0x4]! */
/* @0x28f74c vldr s11, [r2, #-4] */
/* @0x28f750 vldr s12, [r2, #-8] */
/* @0x28f754 mov r4, r2 */
/* @0x28f758 cmp r1, r0 */
/* @0x28f75c vldr s13, [r4] */
/* @0x28f760 ldr r3, [r12, r3, lsl #2] */
/* @0x28f764 vldr s14, [r3, #56] */
/* @0x28f768 vldr s15, [r3, #68] */
/* @0x28f76c vmul.f32 s14, s11, s14 */
/* @0x28f770 vldr s5, [r3, #52] */
/* @0x28f774 vldr s6, [r3, #64] */
/* @0x28f778 vldr s7, [r3, #60] */
/* @0x28f77c vldr s8, [r3, #72] */
/* @0x28f780 add r2, r2, #12 */
/* @0x28f784 vmul.f32 s15, s11, s15 */
/* @0x28f788 vmla.f32 s14, s12, s5 */
/* @0x28f78c vmla.f32 s15, s12, s6 */
/* @0x28f790 vadd.f32 s14, s14, s7 */
/* @0x28f794 vadd.f32 s15, s15, s8 */
/* @0x28f798 vmla.f32 s9, s14, s13 */
/* @0x28f79c vmla.f32 s10, s15, s13 */
/* @0x28f7a0 bne 0x28f748 <spVertexAttachment_computeWorldVertices1+0xfc> */
/* @0x28f7a4 ldr r4, [sp, #0xc] */
/* @0x28f7a8 rsb r10, r10, r5 */
/* @0x28f7ac sub r7, r7, #3 */
/* @0x28f7b0 rsb r4, r4, r9 */
/* @0x28f7b4 add r10, r10, r10, lsl #1 */
/* @0x28f7b8 sub r4, r4, #1 */
/* @0x28f7bc add r7, r7, r10 */
/* @0x28f7c0 add r4, r5, r4 */
/* @0x28f7c4 vmov r0, s10 */
/* @0x28f7c8 vstr s9, [r8, #-4] */
/* @0x28f7cc str r0, [r8], #8 */
/* @0x28f7d0 cmp r8, r11 */
/* @0x28f7d4 bne 0x28f70c <spVertexAttachment_computeWorldVertices1+0xc0> */
/* @0x28f7d8 add sp, sp, #24 */
/* @0x28f7dc pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x28f7e0 bx lr */
/* @0x28f7e4 cmp r10, r2 */
/* @0x28f7e8 lsl r5, r5, #1 */
/* @0x28f7ec str r5, [sp, #0x4] */
/* @0x28f7f0 bge 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c> */
/* @0x28f7f4 mvn r3, r10 */
/* @0x28f7f8 add r9, r10, #1 */
/* @0x28f7fc add r3, r3, r2 */
/* @0x28f800 sub r1, r6, #4 */
/* @0x28f804 bic r3, r3, #1 */
/* @0x28f808 add r9, r8, r9, lsl #2 */
/* @0x28f80c add r10, r3, r10 */
/* @0x28f810 add r3, r8, #12 */
/* @0x28f814 str r1, [sp, #0x14] */
/* @0x28f818 add r10, r3, r10, lsl #2 */
/* @0x28f81c str r10, [sp, #0x10] */
/* @0x28f820 ldr r8, [r6, r4, lsl #2] */
/* @0x28f824 add r10, r4, #1 */
/* @0x28f828 mov r11, r4 */
/* @0x28f82c add r1, r6, r4, lsl #2 */
/* @0x28f830 add r8, r8, r10 */
/* @0x28f834 cmp r10, r8 */
/* @0x28f838 bge 0x28f93c <spVertexAttachment_computeWorldVertices1+0x2f0> */
/* @0x28f83c ldr r2, [sp, #0x4] */
/* @0x28f840 vmov.f32 s10, s2 */
/* @0x28f844 ldr r3, [sp, #0x14] */
/* @0x28f848 add r0, r2, #1 */
/* @0x28f84c add r2, r7, #2 */
/* @0x28f850 add r5, r3, r8, lsl #2 */
/* @0x28f854 ldr r3, [sp, #0xc] */
/* @0x28f858 vmov.f32 s9, s3 */
/* @0x28f85c str r4, [sp] */
/* @0x28f860 add r0, r3, r0, lsl #2 */
/* @0x28f864 ldr r3, [sp, #0x8] */
/* @0x28f868 add r2, r3, r2, lsl #2 */
/* @0x28f86c mov r4, r0 */
/* @0x28f870 vldr s4, [r2, #-4] */
/* @0x28f874 vldr s11, [r4] */
/* @0x28f878 vadd.f32 s11, s4, s11 */
/* @0x28f87c ldr r3, [r1, #0x4]! */
/* @0x28f880 vldr s15, [r0, #-4] */
/* @0x28f884 vldr s12, [r2, #-8] */
/* @0x28f888 mov r4, r2 */
/* @0x28f88c cmp r1, r5 */
/* @0x28f890 vldr s13, [r4] */
/* @0x28f894 ldr r3, [r12, r3, lsl #2] */
/* @0x28f898 vldr s14, [r3, #56] */
/* @0x28f89c vldr s5, [r3, #52] */
/* @0x28f8a0 vldr s6, [r3, #64] */
/* @0x28f8a4 vldr s7, [r3, #60] */
/* @0x28f8a8 vldr s8, [r3, #72] */
/* @0x28f8ac add r0, r0, #8 */
/* @0x28f8b0 add r2, r2, #12 */
/* @0x28f8b4 vadd.f32 s12, s12, s15 */
/* @0x28f8b8 vldr s15, [r3, #68] */
/* @0x28f8bc vmul.f32 s14, s11, s14 */
/* @0x28f8c0 vmul.f32 s15, s11, s15 */
/* @0x28f8c4 vmla.f32 s14, s12, s5 */
/* @0x28f8c8 vmla.f32 s15, s12, s6 */
/* @0x28f8cc vadd.f32 s14, s14, s7 */
/* @0x28f8d0 vadd.f32 s15, s15, s8 */
/* @0x28f8d4 vmla.f32 s9, s14, s13 */
/* @0x28f8d8 vmla.f32 s10, s15, s13 */
/* @0x28f8dc bne 0x28f86c <spVertexAttachment_computeWorldVertices1+0x220> */
/* @0x28f8e0 ldr r4, [sp] */
/* @0x28f8e4 movw r3, #0xfffe */
/* @0x28f8e8 movt r3, #0x7fff */
/* @0x28f8ec ldr r0, [sp, #0x4] */
/* @0x28f8f0 rsb r3, r11, r3 */
/* @0x28f8f4 rsb r11, r11, r8 */
/* @0x28f8f8 rsb r4, r4, r10 */
/* @0x28f8fc sub r7, r7, #3 */
/* @0x28f900 sub r4, r4, #1 */
/* @0x28f904 add r11, r11, r11, lsl #1 */
/* @0x28f908 add r3, r8, r3 */
/* @0x28f90c add r4, r8, r4 */
/* @0x28f910 add r7, r7, r11 */
/* @0x28f914 add r2, r0, #2 */
/* @0x28f918 add r3, r2, r3, lsl #1 */
/* @0x28f91c str r3, [sp, #0x4] */
/* @0x28f920 vmov r1, s10 */
/* @0x28f924 vstr s9, [r9, #-4] */
/* @0x28f928 ldr r2, [sp, #0x10] */
/* @0x28f92c str r1, [r9], #8 */
/* @0x28f930 cmp r9, r2 */
/* @0x28f934 bne 0x28f820 <spVertexAttachment_computeWorldVertices1+0x1d4> */
/* @0x28f938 b 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c> */
/* @0x28f93c vmov.f32 s10, s2 */
/* @0x28f940 mov r4, r10 */
/* @0x28f944 vmov.f32 s9, s3 */
/* @0x28f948 b 0x28f920 <spVertexAttachment_computeWorldVertices1+0x2d4> */
/* @0x28f94c vmov.f32 s10, s2 */
/* @0x28f950 mov r4, r9 */
/* @0x28f954 vmov.f32 s9, s3 */
/* @0x28f958 b 0x28f7c4 <spVertexAttachment_computeWorldVertices1+0x178> */
/* @0x28f95c ldr r3, [sp, #0x8] */
/* @0x28f960 cmp r9, #0 */
/* @0x28f964 ldr r0, [sp, #0xc] */
/* @0x28f968 vldr s14, [r4, #60] */
/* @0x28f96c vldr s15, [r4, #72] */
/* @0x28f970 vadd.f32 s3, s3, s14 */
/* @0x28f974 movle r0, r3 */
/* @0x28f978 cmp r10, r2 */
/* @0x28f97c str r0, [sp, #0xc] */
/* @0x28f980 vadd.f32 s2, s2, s15 */
/* @0x28f984 bge 0x28f7d8 <spVertexAttachment_computeWorldVertices1+0x18c> */
/* @0x28f988 mvn r3, r10 */
/* @0x28f98c add r2, r3, r2 */
/* @0x28f990 bic r2, r2, #1 */
/* @0x28f994 add r3, r1, #1 */
/* @0x28f998 add r2, r2, r1 */
/* @0x28f99c add r10, r10, #1 */
/* @0x28f9a0 add r3, r0, r3, lsl #2 */
/* @0x28f9a4 add r2, r0, r2, lsl #2 */
/* @0x28f9a8 add r8, r8, r10, lsl #2 */
/* @0x28f9ac add r2, r2, #12 */
/* @0x28f9b0 vldr s14, [r4, #56] */
/* @0x28f9b4 mov r0, r3 */
/* @0x28f9b8 vldr s15, [r0] */
/* @0x28f9bc vmul.f32 s14, s15, s14 */
/* @0x28f9c0 vldr s13, [r3, #-4] */
/* @0x28f9c4 vldr s12, [r4, #52] */
/* @0x28f9c8 add r3, r3, #8 */
/* @0x28f9cc cmp r3, r2 */
/* @0x28f9d0 vmla.f32 s14, s13, s12 */
/* @0x28f9d4 vadd.f32 s14, s14, s3 */
/* @0x28f9d8 vstr s14, [r8, #-4] */
/* @0x28f9dc vldr s14, [r4, #68] */
/* @0x28f9e0 vmul.f32 s15, s15, s14 */
/* @0x28f9e4 vldr s14, [r4, #64] */
/* @0x28f9e8 vmla.f32 s15, s13, s14 */
/* @0x28f9ec vadd.f32 s15, s15, s2 */
/* @0x28f9f0 vmov r1, s15 */
/* @0x28f9f4 str r1, [r8], #8 */
/* @0x28f9f8 bne 0x28f9b0 <spVertexAttachment_computeWorldVertices1+0x364> */
/* @0x28f9fc add sp, sp, #24 */
/* @0x28fa00 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x28fa04 bx lr */

/* ── FUNC 0x28fa08 · spVertexAttachment_computeWorldVertices · size=48 · insn=12 */
/* @0x28fa08 str lr, [sp, #-0x4]! */
/* @0x28fa0c sub sp, sp, #12 */
/* @0x28fa10 ldr lr, [r0, #0x20] */
/* @0x28fa14 mov r12, #0 */
/* @0x28fa18 mov r3, r1 */
/* @0x28fa1c str r2, [sp] */
/* @0x28fa20 mov r1, r12 */
/* @0x28fa24 str r12, [sp, #0x4] */
/* @0x28fa28 mov r2, lr */
/* @0x28fa2c bl 0x28f64c <spVertexAttachment_computeWorldVertices1> */
/* @0x28fa30 add sp, sp, #12 */
/* @0x28fa34 ldr pc, [sp], #4 */

/* ── FUNC 0x28fa38 · textureReadFn(png_struct_def*, unsigned char*, unsigned int) · size=32 · insn=8 */
/* @0x28fa38 push {r3, r4, r5, lr} */
/* @0x28fa3c mov r5, r1 */
/* @0x28fa40 mov r4, r2 */
/* @0x28fa44 blx 0x2a5f20 <png_get_io_ptr> */
/* @0x28fa48 mov r1, r5 */
/* @0x28fa4c mov r2, r4 */
/* @0x28fa50 pop {r3, r4, r5, lr} */
/* @0x28fa54 b 0x31ba7c <__udivdi3+0x3e4> */

/* ── FUNC 0x28fa58 · PB_OurInfo(HTTP_REQ_CONTEXT*, void*, int*) · size=156 · insn=39 */
/* @0x28fa58 ldr r12, [pc, #0x80] */
/* @0x28fa5c mov r0, #0 */
/* @0x28fa60 push {r4, lr} */
/* @0x28fa64 ldr r12, [pc, r12] */
/* @0x28fa68 sub sp, sp, #40 */
/* @0x28fa6c ldr lr, [pc, #0x70] */
/* @0x28fa70 ldr r3, [pc, #0x70] */
/* @0x28fa74 mov r1, #0 */
/* @0x28fa78 mov r4, #0 */
/* @0x28fa7c strd r0, r1, [sp, #8] */
/* @0x28fa80 str r4, [sp] */
/* @0x28fa84 add lr, pc, lr */
/* @0x28fa88 str lr, [sp, #0x4] */
/* @0x28fa8c ldr r3, [pc, r3] */
/* @0x28fa90 ldr lr, [r12] */
/* @0x28fa94 mov r4, r2 */
/* @0x28fa98 ldr r12, [pc, #0x4c] */
/* @0x28fa9c mov r2, #0 */
/* @0x28faa0 strd r0, r1, [sp, #24] */
/* @0x28faa4 mov r0, #3 */
/* @0x28faa8 str lr, [sp, #0x10] */
/* @0x28faac add r12, pc, r12 */
/* @0x28fab0 str r12, [sp, #0x14] */
/* @0x28fab4 ldr r12, [r3] */
/* @0x28fab8 mov r3, #20480 */
/* @0x28fabc ldr r1, [pc, #0x2c] */
/* @0x28fac0 movt r3, #0x408f */
/* @0x28fac4 add r1, pc, r1 */
/* @0x28fac8 str r12, [sp, #0x20] */
/* @0x28facc bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x28fad0 str r0, [r4] */
/* @0x28fad4 mov r0, #70 */
/* @0x28fad8 add sp, sp, #40 */
/* @0x28fadc pop {r4, pc} */
/* @0x28fae0 andseq r1, r6, r8, lsr #29 */
/* @0x28fae4 andeq r0, r10, r4, lsl #27 */
/* @0x28fae8 andseq r1, r6, r4, lsl #29 */
/* @0x28faec andeq r8, r12, r8, lsl #12 */
/* @0x28faf0 andeq r0, r10, r12, ror pc */

/* ── FUNC 0x28faf4 · PB_PurchaseInfo(HTTP_REQ_CONTEXT*, void*, int*) · size=148 · insn=37 */
/* @0x28faf4 push {r4, r5, r6, r7, lr} */
/* @0x28faf8 mov r6, r1 */
/* @0x28fafc vldr s13, [r6] */
/* @0x28fb00 vcvt.f64.s32 d7, s13 */
/* @0x28fb04 sub sp, sp, #44 */
/* @0x28fb08 ldr r1, [pc, #0x6c] */
/* @0x28fb0c mov r7, r2 */
/* @0x28fb10 ldr r0, [r6, #0x4] */
/* @0x28fb14 mov r3, #0 */
/* @0x28fb18 add r1, pc, r1 */
/* @0x28fb1c ldr r2, [pc, #0x5c] */
/* @0x28fb20 str r1, [sp, #0x4] */
/* @0x28fb24 mov r4, #0 */
/* @0x28fb28 ldr r1, [pc, #0x54] */
/* @0x28fb2c add r2, pc, r2 */
/* @0x28fb30 str r0, [sp, #0x10] */
/* @0x28fb34 mov r5, #0 */
/* @0x28fb38 str r2, [sp, #0x14] */
/* @0x28fb3c add r1, pc, r1 */
/* @0x28fb40 str r3, [sp] */
/* @0x28fb44 mov r2, #0 */
/* @0x28fb48 str r3, [sp, #0x20] */
/* @0x28fb4c vstr d7, [sp, #24] */
/* @0x28fb50 strd r4, r5, [sp, #8] */
/* @0x28fb54 mov r0, #3 */
/* @0x28fb58 mov r3, #43008 */
/* @0x28fb5c movt r3, #0x408f */
/* @0x28fb60 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x28fb64 str r0, [r7] */
/* @0x28fb68 mov r0, r6 */
/* @0x28fb6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x28fb70 mov r0, #70 */
/* @0x28fb74 add sp, sp, #44 */
/* @0x28fb78 pop {r4, r5, r6, r7, pc} */
/* @0x28fb7c andeq r8, r12, r8, lsr #11 */
/* @0x28fb80 andeq r8, r12, r0, lsr #11 */
/* @0x28fb84 andeq r0, r10, r4, lsl #30 */

/* ── FUNC 0x28fb88 · PB_AchievementPicLoaded(HTTP_REQ_CONTEXT*, void*, int*) · size=236 · insn=59 */
/* @0x28fb88 ldr r3, [pc, #0xcc] */
/* @0x28fb8c push {r4, r5, r6, r7, lr} */
/* @0x28fb90 ldr r3, [pc, r3] */
/* @0x28fb94 mov r6, r1 */
/* @0x28fb98 ldr r1, [pc, #0xc0] */
/* @0x28fb9c ldr r4, [r3] */
/* @0x28fba0 sub sp, sp, #44 */
/* @0x28fba4 add r1, pc, r1 */
/* @0x28fba8 mov r7, r2 */
/* @0x28fbac mov r5, #0 */
/* @0x28fbb0 ldr r3, [r4] */
/* @0x28fbb4 mov r0, r4 */
/* @0x28fbb8 ldr r3, [r3, #0xc] */
/* @0x28fbbc blx r3 */
/* @0x28fbc0 ldr r1, [r4] */
/* @0x28fbc4 mov r0, r4 */
/* @0x28fbc8 ldr r2, [r6, #0x4] */
/* @0x28fbcc ldr r3, [r6] */
/* @0x28fbd0 mov r4, #0 */
/* @0x28fbd4 ldr r12, [r1, #0xc] */
/* @0x28fbd8 ldr r1, [pc, #0x84] */
/* @0x28fbdc add r1, pc, r1 */
/* @0x28fbe0 blx r12 */
/* @0x28fbe4 vldr s13, [r6, #4] */
/* @0x28fbe8 vcvt.f64.s32 d7, s13 */
/* @0x28fbec ldr r1, [pc, #0x74] */
/* @0x28fbf0 ldr r0, [r6] */
/* @0x28fbf4 mov r3, #0 */
/* @0x28fbf8 add r1, pc, r1 */
/* @0x28fbfc ldr r2, [pc, #0x68] */
/* @0x28fc00 str r1, [sp, #0x4] */
/* @0x28fc04 ldr r1, [pc, #0x64] */
/* @0x28fc08 add r2, pc, r2 */
/* @0x28fc0c str r0, [sp, #0x20] */
/* @0x28fc10 mov r0, #3 */
/* @0x28fc14 add r1, pc, r1 */
/* @0x28fc18 str r2, [sp, #0x14] */
/* @0x28fc1c vstr d7, [sp, #8] */
/* @0x28fc20 mov r2, #0 */
/* @0x28fc24 str r3, [sp] */
/* @0x28fc28 str r3, [sp, #0x10] */
/* @0x28fc2c mov r3, #28672 */
/* @0x28fc30 strd r4, r5, [sp, #24] */
/* @0x28fc34 movt r3, #0x408f */
/* @0x28fc38 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x28fc3c str r0, [r7] */
/* @0x28fc40 ldr r0, [r6] */
/* @0x28fc44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x28fc48 mov r0, r6 */
/* @0x28fc4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x28fc50 mov r0, #70 */
/* @0x28fc54 add sp, sp, #44 */
/* @0x28fc58 pop {r4, r5, r6, r7, pc} */
/* @0x28fc5c ldrheq sp, [r5], -r0 */
/* @0x28fc60 andeq r8, r12, r4, lsr r5 */
/* @0x28fc64 andeq r8, r12, r0, lsr #10 */
/* @0x28fc68 andeq r8, r12, r0, lsr r5 */
/* @0x28fc6c andeq r8, r12, r12, lsr #9 */
/* @0x28fc70 andeq r0, r10, r12, lsr #28 */

/* ── FUNC 0x28fc74 · _JNIEnv::CallObjectMethod(_jobject*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0x28fc74 push {r2, r3} */
/* @0x28fc78 str lr, [sp, #-0x4]! */
/* @0x28fc7c sub sp, sp, #12 */
/* @0x28fc80 ldr lr, [r0] */
/* @0x28fc84 add r12, sp, #20 */
/* @0x28fc88 ldr r2, [sp, #0x10] */
/* @0x28fc8c mov r3, r12 */
/* @0x28fc90 str r12, [sp, #0x4] */
/* @0x28fc94 ldr r12, [lr, #0x8c] */
/* @0x28fc98 blx r12 */
/* @0x28fc9c add sp, sp, #12 */
/* @0x28fca0 ldr lr, [sp], #4 */
/* @0x28fca4 add sp, sp, #8 */
/* @0x28fca8 bx lr */

/* ── FUNC 0x28fcac · _JNIEnv::CallBooleanMethod(_jobject*, _jmethodID*, ...) · size=56 · insn=14 */
/* @0x28fcac push {r2, r3} */
/* @0x28fcb0 str lr, [sp, #-0x4]! */
/* @0x28fcb4 sub sp, sp, #12 */
/* @0x28fcb8 ldr lr, [r0] */
/* @0x28fcbc add r12, sp, #20 */
/* @0x28fcc0 ldr r2, [sp, #0x10] */
/* @0x28fcc4 mov r3, r12 */
/* @0x28fcc8 str r12, [sp, #0x4] */
/* @0x28fccc ldr r12, [lr, #0x98] */
/* @0x28fcd0 blx r12 */
/* @0x28fcd4 add sp, sp, #12 */
/* @0x28fcd8 ldr lr, [sp], #4 */
/* @0x28fcdc add sp, sp, #8 */
/* @0x28fce0 bx lr */

/* ── FUNC 0x28fce4 · ImportGLLibrary() · size=104 · insn=26 */
/* @0x28fce4 push {r4, lr} */
/* @0x28fce8 ldr r4, [pc, #0x58] */
/* @0x28fcec ldr r4, [pc, r4] */
/* @0x28fcf0 ldr r0, [r4] */
/* @0x28fcf4 cmp r0, #1 */
/* @0x28fcf8 movne r0, #0 */
/* @0x28fcfc bl 0xba710 <_Z12GLFuncImportb> */
/* @0x28fd00 cmp r0, #2 */
/* @0x28fd04 moveq r3, #1 */
/* @0x28fd08 streq r3, [r4] */
/* @0x28fd0c popeq {r4, pc} */
/* @0x28fd10 ldr r3, [r4] */
/* @0x28fd14 cmp r3, #1 */
/* @0x28fd18 beq 0x28fd28 <_Z15ImportGLLibraryv+0x44> */
/* @0x28fd1c mov r3, #0 */
/* @0x28fd20 str r3, [r4] */
/* @0x28fd24 pop {r4, pc} */
/* @0x28fd28 cmp r0, #3 */
/* @0x28fd2c bne 0x28fd1c <_Z15ImportGLLibraryv+0x38> */
/* @0x28fd30 bl 0xbd6a4 <_Z19GLFuncImportDestroyv> */
/* @0x28fd34 mov r3, #0 */
/* @0x28fd38 mov r0, r3 */
/* @0x28fd3c str r3, [r4] */
/* @0x28fd40 pop {r4, lr} */
/* @0x28fd44 b 0xba710 <_Z12GLFuncImportb> */
/* @0x28fd48 andseq r0, r6, r12, lsl r7 */

/* ── FUNC 0x28fd4c · sysGetFilePrePend · size=8 · insn=2 */
/* @0x28fd4c mov r0, #0 */
/* @0x28fd50 bx lr */

/* ── FUNC 0x28fd54 · sysGetSavePrePend · size=8 · insn=2 */
/* @0x28fd54 mov r0, #0 */
/* @0x28fd58 bx lr */

/* ── FUNC 0x28fd5c · GetFilePrePend() · size=16 · insn=4 */
/* @0x28fd5c ldr r0, [pc, #0x4] */
/* @0x28fd60 add r0, pc, r0 */
/* @0x28fd64 bx lr */
/* @0x28fd68 andeq r2, r12, r8, lsl sp */

/* ── FUNC 0x28fd6c · GetSavePrePend() · size=212 · insn=53 */
/* @0x28fd6c ldr r3, [pc, #0xb8] */
/* @0x28fd70 ldr r2, [pc, #0xb8] */
/* @0x28fd74 add r3, pc, r3 */
/* @0x28fd78 push {r4, r5, r6, r7, r8, lr} */
/* @0x28fd7c ldr r5, [r3, r2] */
/* @0x28fd80 ldr r4, [r5] */
/* @0x28fd84 cmp r4, #0 */
/* @0x28fd88 beq 0x28fe1c <_Z14GetSavePrePendv+0xb0> */
/* @0x28fd8c ldrb r2, [r4] */
/* @0x28fd90 cmp r2, #0 */
/* @0x28fd94 beq 0x28fe1c <_Z14GetSavePrePendv+0xb0> */
/* @0x28fd98 ldr r2, [pc, #0x94] */
/* @0x28fd9c ldr r7, [r3, r2] */
/* @0x28fda0 ldr r6, [r7] */
/* @0x28fda4 mov r0, r6 */
/* @0x28fda8 bl 0xb6538 <strlen@plt> */
/* @0x28fdac mov r1, r6 */
/* @0x28fdb0 mov r8, r0 */
/* @0x28fdb4 mov r0, r4 */
/* @0x28fdb8 mov r2, r8 */
/* @0x28fdbc bl 0xb65e0 <strncmp@plt> */
/* @0x28fdc0 cmp r0, #0 */
/* @0x28fdc4 mov r0, r4 */
/* @0x28fdc8 bne 0x28fdd0 <_Z14GetSavePrePendv+0x64> */
/* @0x28fdcc pop {r4, r5, r6, r7, r8, pc} */
/* @0x28fdd0 bl 0xb6538 <strlen@plt> */
/* @0x28fdd4 ldr r1, [pc, #0x5c] */
/* @0x28fdd8 movw r2, #0x167 */
/* @0x28fddc mov r3, #1 */
/* @0x28fde0 add r1, pc, r1 */
/* @0x28fde4 add r0, r0, r8 */
/* @0x28fde8 add r0, r0, #3 */
/* @0x28fdec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x28fdf0 ldr r1, [pc, #0x44] */
/* @0x28fdf4 ldr r2, [r7] */
/* @0x28fdf8 add r1, pc, r1 */
/* @0x28fdfc ldr r3, [r5] */
/* @0x28fe00 mov r4, r0 */
/* @0x28fe04 bl 0xb6550 <sprintf@plt> */
/* @0x28fe08 ldr r0, [r5] */
/* @0x28fe0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x28fe10 str r4, [r5] */
/* @0x28fe14 mov r0, r4 */
/* @0x28fe18 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28fe1c ldr r2, [pc, #0x10] */
/* @0x28fe20 ldr r3, [r3, r2] */
/* @0x28fe24 ldr r0, [r3] */
/* @0x28fe28 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28fe2c ldrsbeq r1, [r6], -r12 */
/* @0x28fe30 .word 0xfffffcc4 */
/* @0x28fe34 .word 0xfffffcc8 */
/* @0x28fe38 andeq r8, r12, r4, asr r3 */
/* @0x28fe3c andeq r8, r12, r12, ror #6 */

/* ── FUNC 0x28fe40 · DrawLogo(int) · size=4 · insn=1 */
/* @0x28fe40 bx lr */

/* ── FUNC 0x28fe44 · ShouldDisplaySplash() · size=8 · insn=2 */
/* @0x28fe44 mov r0, #0 */
/* @0x28fe48 bx lr */

/* ── FUNC 0x28fe4c · Terminate() · size=4 · insn=1 */
/* @0x28fe4c bx lr */

/* ── FUNC 0x28fe50 · GetExeName · size=20 · insn=5 */
/* @0x28fe50 ldr r3, [pc, #0x8] */
/* @0x28fe54 ldr r3, [pc, r3] */
/* @0x28fe58 ldr r0, [r3] */
/* @0x28fe5c bx lr */
/* @0x28fe60 andseq r1, r6, r8, asr #21 */

/* ── FUNC 0x28fe64 · ProcessMessages() · size=4 · insn=1 */
/* @0x28fe64 bx lr */

/* ── FUNC 0x28fe68 · FINALIZE_PlatformSpecific() · size=4 · insn=1 */
/* @0x28fe68 bx lr */

/* ── FUNC 0x28fe6c · INITIALIZE_PlatformSpecific() · size=4 · insn=1 */
/* @0x28fe6c bx lr */

/* ── FUNC 0x28fe70 · loadTexture(zip*, char const*, int*, int*) · size=1028 · insn=257 */
/* @0x28fe70 push {r4, r5, r6, r7, lr} */
/* @0x28fe74 sub sp, sp, #92 */
/* @0x28fe78 ldr r5, [pc, #0x3bc] */
/* @0x28fe7c mov r4, r1 */
/* @0x28fe80 ldr r12, [pc, #0x3b8] */
/* @0x28fe84 add r5, pc, r5 */
/* @0x28fe88 str r2, [sp, #0x20] */
/* @0x28fe8c str r5, [sp, #0x18] */
/* @0x28fe90 mov r2, #0 */
/* @0x28fe94 str r3, [sp, #0x24] */
/* @0x28fe98 ldr r3, [r5, r12] */
/* @0x28fe9c ldr r3, [r3] */
/* @0x28fea0 str r3, [sp, #0x54] */
/* @0x28fea4 blx 0x2a44b8 <zip_fopen> */
/* @0x28fea8 subs r12, r0, #0 */
/* @0x28feac str r12, [sp, #0x1c] */
/* @0x28feb0 beq 0x29020c <_Z11loadTextureP3zipPKcPiS3_+0x39c> */
/* @0x28feb4 add r4, sp, #76 */
/* @0x28feb8 mov r2, #8 */
/* @0x28febc mov r1, r4 */
/* @0x28fec0 blx 0x2a476c <zip_fread> */
/* @0x28fec4 mov r1, #0 */
/* @0x28fec8 mov r0, r4 */
/* @0x28fecc mov r2, #8 */
/* @0x28fed0 blx 0x2a5a4c <png_sig_cmp> */
/* @0x28fed4 subs r1, r0, #0 */
/* @0x28fed8 bne 0x2901c8 <_Z11loadTextureP3zipPKcPiS3_+0x358> */
/* @0x28fedc ldr r0, [pc, #0x360] */
/* @0x28fee0 mov r2, r1 */
/* @0x28fee4 mov r3, r1 */
/* @0x28fee8 add r0, pc, r0 */
/* @0x28feec blx 0x2a6fdc <png_create_read_struct> */
/* @0x28fef0 cmp r0, #0 */
/* @0x28fef4 str r0, [sp, #0x2c] */
/* @0x28fef8 beq 0x290180 <_Z11loadTextureP3zipPKcPiS3_+0x310> */
/* @0x28fefc blx 0x2a5b64 <png_create_info_struct> */
/* @0x28ff00 cmp r0, #0 */
/* @0x28ff04 str r0, [sp, #0x30] */
/* @0x28ff08 beq 0x2901f8 <_Z11loadTextureP3zipPKcPiS3_+0x388> */
/* @0x28ff0c ldr r0, [sp, #0x2c] */
/* @0x28ff10 blx 0x2a5b64 <png_create_info_struct> */
/* @0x28ff14 cmp r0, #0 */
/* @0x28ff18 str r0, [sp, #0x34] */
/* @0x28ff1c beq 0x290170 <_Z11loadTextureP3zipPKcPiS3_+0x300> */
/* @0x28ff20 ldr r3, [pc, #0x320] */
/* @0x28ff24 mov r2, #256 */
/* @0x28ff28 ldr lr, [sp, #0x18] */
/* @0x28ff2c ldr r0, [sp, #0x2c] */
/* @0x28ff30 ldr r1, [lr, r3] */
/* @0x28ff34 blx 0x2a653c <png_set_longjmp_fn> */
/* @0x28ff38 bl 0xb6904 <setjmp@plt> */
/* @0x28ff3c subs r4, r0, #0 */
/* @0x28ff40 bne 0x2901b4 <_Z11loadTextureP3zipPKcPiS3_+0x344> */
/* @0x28ff44 ldr r3, [pc, #0x300] */
/* @0x28ff48 ldr r5, [sp, #0x18] */
/* @0x28ff4c ldr r1, [sp, #0x1c] */
/* @0x28ff50 ldr r0, [sp, #0x2c] */
/* @0x28ff54 ldr r2, [r5, r3] */
/* @0x28ff58 blx 0x2a804c <png_set_read_fn> */
/* @0x28ff5c ldr r0, [sp, #0x2c] */
/* @0x28ff60 mov r1, #8 */
/* @0x28ff64 blx 0x2a5a24 <png_set_sig_bytes> */
/* @0x28ff68 ldr r0, [sp, #0x2c] */
/* @0x28ff6c ldr r1, [sp, #0x30] */
/* @0x28ff70 blx 0x2a6ff0 <png_read_info> */
/* @0x28ff74 ldr r1, [sp, #0x30] */
/* @0x28ff78 add r3, sp, #56 */
/* @0x28ff7c add r2, sp, #64 */
/* @0x28ff80 str r3, [sp] */
/* @0x28ff84 add r3, sp, #60 */
/* @0x28ff88 ldr r0, [sp, #0x2c] */
/* @0x28ff8c str r3, [sp, #0x4] */
/* @0x28ff90 add r3, sp, #68 */
/* @0x28ff94 str r4, [sp, #0x8] */
/* @0x28ff98 str r4, [sp, #0xc] */
/* @0x28ff9c str r4, [sp, #0x10] */
/* @0x28ffa0 blx 0x2a693e <png_get_IHDR> */
/* @0x28ffa4 ldr r2, [sp, #0x40] */
/* @0x28ffa8 ldr r3, [sp, #0x44] */
/* @0x28ffac ldr r12, [sp, #0x20] */
/* @0x28ffb0 ldr lr, [sp, #0x24] */
/* @0x28ffb4 ldr r0, [sp, #0x2c] */
/* @0x28ffb8 str r2, [r12] */
/* @0x28ffbc ldr r1, [sp, #0x30] */
/* @0x28ffc0 str r3, [lr] */
/* @0x28ffc4 blx 0x2a7448 <png_read_update_info> */
/* @0x28ffc8 ldr r1, [sp, #0x30] */
/* @0x28ffcc ldr r0, [sp, #0x2c] */
/* @0x28ffd0 blx 0x2a6574 <png_get_rowbytes> */
/* @0x28ffd4 mov r5, r0 */
/* @0x28ffd8 ldr r0, [sp, #0x44] */
/* @0x28ffdc mul r0, r0, r5 */
/* @0x28ffe0 bl 0x27d14c <_Znaj> */
/* @0x28ffe4 subs r6, r0, #0 */
/* @0x28ffe8 beq 0x2901b4 <_Z11loadTextureP3zipPKcPiS3_+0x344> */
/* @0x28ffec ldr r0, [sp, #0x44] */
/* @0x28fff0 cmp r0, #532676608 */
/* @0x28fff4 lslls r0, r0, #2 */
/* @0x28fff8 mvnhi r0, #0 */
/* @0x28fffc bl 0x27d14c <_Znaj> */
/* @0x290000 subs r4, r0, #0 */
/* @0x290004 beq 0x2901b4 <_Z11loadTextureP3zipPKcPiS3_+0x344> */
/* @0x290008 ldr lr, [sp, #0x44] */
/* @0x29000c cmp lr, #0 */
/* @0x290010 movne r12, #0 */
/* @0x290014 movne r1, r5 */
/* @0x290018 movne r3, r12 */
/* @0x29001c movne r2, r6 */
/* @0x290020 beq 0x29003c <_Z11loadTextureP3zipPKcPiS3_+0x1cc> */
/* @0x290024 add r3, r3, #1 */
/* @0x290028 str r2, [r4, r12, lsl #2] */
/* @0x29002c cmp r3, lr */
/* @0x290030 add r2, r2, r1 */
/* @0x290034 mov r12, r3 */
/* @0x290038 bne 0x290024 <_Z11loadTextureP3zipPKcPiS3_+0x1b4> */
/* @0x29003c ldr r0, [sp, #0x2c] */
/* @0x290040 mov r1, r4 */
/* @0x290044 blx 0x2a7840 <png_read_image> */
/* @0x290048 ldr r2, [sp, #0x18] */
/* @0x29004c ldr r3, [pc, #0x1fc] */
/* @0x290050 mov r0, #1 */
/* @0x290054 add r1, sp, #72 */
/* @0x290058 ldr r3, [r2, r3] */
/* @0x29005c ldr r3, [r3] */
/* @0x290060 blx r3 */
/* @0x290064 ldr r12, [sp, #0x18] */
/* @0x290068 ldr r3, [pc, #0x1e4] */
/* @0x29006c movw r0, #0xde1 */
/* @0x290070 ldr r1, [sp, #0x48] */
/* @0x290074 ldr r3, [r12, r3] */
/* @0x290078 ldr r3, [r3] */
/* @0x29007c blx r3 */
/* @0x290080 ldr r0, [sp, #0x18] */
/* @0x290084 ldr r3, [pc, #0x1cc] */
/* @0x290088 ldr lr, [sp, #0x3c] */
/* @0x29008c ldr r7, [sp, #0x38] */
/* @0x290090 ldr r1, [r0, r3] */
/* @0x290094 ldr r2, [sp, #0x40] */
/* @0x290098 ldr r3, [sp, #0x44] */
/* @0x29009c ldr r0, [r1] */
/* @0x2900a0 ldr r1, [pc, #0x1b4] */
/* @0x2900a4 ldr r12, [r0] */
/* @0x2900a8 add r1, pc, r1 */
/* @0x2900ac stm sp, {r5, r7, lr} */
/* @0x2900b0 ldr r12, [r12, #0xc] */
/* @0x2900b4 blx r12 */
/* @0x2900b8 ldr r5, [sp, #0x18] */
/* @0x2900bc ldr r1, [pc, #0x19c] */
/* @0x2900c0 movw r12, #0x1908 */
/* @0x2900c4 ldr r2, [sp, #0x44] */
/* @0x2900c8 mov r0, #0 */
/* @0x2900cc ldr r3, [sp, #0x40] */
/* @0x2900d0 ldr lr, [r5, r1] */
/* @0x2900d4 mov r1, r0 */
/* @0x2900d8 str r2, [sp] */
/* @0x2900dc mov r2, r12 */
/* @0x2900e0 str r6, [sp, #0x10] */
/* @0x2900e4 ldr r5, [lr] */
/* @0x2900e8 movw lr, #0x1401 */
/* @0x2900ec str r0, [sp, #0x4] */
/* @0x2900f0 movw r0, #0xde1 */
/* @0x2900f4 str lr, [sp, #0xc] */
/* @0x2900f8 str r12, [sp, #0x8] */
/* @0x2900fc blx r5 */
/* @0x290100 ldr r12, [sp, #0x18] */
/* @0x290104 ldr r3, [pc, #0x158] */
/* @0x290108 movw r0, #0xde1 */
/* @0x29010c movw r1, #0x2801 */
/* @0x290110 mov r2, #9728 */
/* @0x290114 ldr r3, [r12, r3] */
/* @0x290118 ldr r3, [r3] */
/* @0x29011c blx r3 */
/* @0x290120 add r1, sp, #48 */
/* @0x290124 add r2, sp, #52 */
/* @0x290128 add r0, sp, #44 */
/* @0x29012c blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x290130 mov r0, r6 */
/* @0x290134 bl 0x27d1d4 <_ZdaPv> */
/* @0x290138 mov r0, r4 */
/* @0x29013c bl 0x27d1d4 <_ZdaPv> */
/* @0x290140 ldr r0, [sp, #0x1c] */
/* @0x290144 blx 0x2a4388 <zip_fclose> */
/* @0x290148 ldr r0, [sp, #0x48] */
/* @0x29014c ldr r3, [pc, #0xec] */
/* @0x290150 ldr r1, [sp, #0x18] */
/* @0x290154 ldr r2, [sp, #0x54] */
/* @0x290158 ldr r3, [r1, r3] */
/* @0x29015c ldr r3, [r3] */
/* @0x290160 cmp r2, r3 */
/* @0x290164 bne 0x290238 <_Z11loadTextureP3zipPKcPiS3_+0x3c8> */
/* @0x290168 add sp, sp, #92 */
/* @0x29016c pop {r4, r5, r6, r7, pc} */
/* @0x290170 mov r2, r0 */
/* @0x290174 add r1, sp, #48 */
/* @0x290178 add r0, sp, #44 */
/* @0x29017c blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x290180 ldr r3, [pc, #0xd0] */
/* @0x290184 ldr lr, [sp, #0x18] */
/* @0x290188 ldr r3, [lr, r3] */
/* @0x29018c ldr r0, [r3] */
/* @0x290190 ldr r3, [r0] */
/* @0x290194 ldr r1, [pc, #0xcc] */
/* @0x290198 ldr r3, [r3, #0xc] */
/* @0x29019c add r1, pc, r1 */
/* @0x2901a0 blx r3 */
/* @0x2901a4 ldr r0, [sp, #0x1c] */
/* @0x2901a8 blx 0x2a4388 <zip_fclose> */
/* @0x2901ac mvn r0, #0 */
/* @0x2901b0 b 0x29014c <_Z11loadTextureP3zipPKcPiS3_+0x2dc> */
/* @0x2901b4 add r0, sp, #44 */
/* @0x2901b8 add r1, sp, #48 */
/* @0x2901bc add r2, sp, #52 */
/* @0x2901c0 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x2901c4 b 0x290180 <_Z11loadTextureP3zipPKcPiS3_+0x310> */
/* @0x2901c8 ldr r0, [sp, #0x18] */
/* @0x2901cc ldr r3, [pc, #0x84] */
/* @0x2901d0 ldr r1, [pc, #0x94] */
/* @0x2901d4 ldr r3, [r0, r3] */
/* @0x2901d8 add r1, pc, r1 */
/* @0x2901dc ldr r4, [r3] */
/* @0x2901e0 ldr r3, [r4] */
/* @0x2901e4 mov r0, r4 */
/* @0x2901e8 ldr r3, [r3, #0xc] */
/* @0x2901ec blx r3 */
/* @0x2901f0 mov r0, r4 */
/* @0x2901f4 b 0x290190 <_Z11loadTextureP3zipPKcPiS3_+0x320> */
/* @0x2901f8 mov r1, r0 */
/* @0x2901fc add r0, sp, #44 */
/* @0x290200 mov r2, r1 */
/* @0x290204 blx 0x2a7e2c <png_destroy_read_struct> */
/* @0x290208 b 0x290180 <_Z11loadTextureP3zipPKcPiS3_+0x310> */
/* @0x29020c ldr r3, [pc, #0x44] */
/* @0x290210 mov r2, r4 */
/* @0x290214 ldr r1, [pc, #0x54] */
/* @0x290218 ldr r3, [r5, r3] */
/* @0x29021c add r1, pc, r1 */
/* @0x290220 ldr r0, [r3] */
/* @0x290224 ldr r3, [r0] */
/* @0x290228 ldr r3, [r3, #0xc] */
/* @0x29022c blx r3 */
/* @0x290230 mvn r0, #0 */
/* @0x290234 b 0x29014c <_Z11loadTextureP3zipPKcPiS3_+0x2dc> */
/* @0x290238 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x29023c andseq r1, r6, r12, asr #27 */
/* @0x290240 .word 0xffffbd00 */
/* @0x290244 andeq r10, r11, r4, asr r7 */
/* @0x290248 .word 0xffffe4ac */
/* @0x29024c .word 0xfffffcd0 */
/* @0x290250 .word 0xffffbb28 */
/* @0x290254 .word 0xffffbb20 */
/* @0x290258 .word 0xffffbac4 */
/* @0x29025c ldrdeq r11, r12, [r11], -r4 */
/* @0x290260 .word 0xffffbb2c */
/* @0x290264 .word 0xffffbb44 */
/* @0x290268 strdeq r7, r8, [r12], -r0 */
/* @0x29026c strdeq r11, r12, [r11], -r4 */
/* @0x290270 andeq r7, r12, r0, asr pc */
