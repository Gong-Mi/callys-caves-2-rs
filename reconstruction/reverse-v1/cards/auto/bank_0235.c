/* libyoyo.so 覆盖卡组 0235
 * 函数 0x282fb8..0x283b58，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x282fb8 · spTransformConstraintTimeline_create · size=24 · insn=6 */
/* @0x282fb8 ldr r3, [pc, #0xc] */
/* @0x282fbc mov r1, #10 */
/* @0x282fc0 mov r2, #5 */
/* @0x282fc4 ldr r3, [pc, r3] */
/* @0x282fc8 b 0x282a10 <_spBaseTimeline_create> */
/* @0x282fcc andseq lr, r6, r8, lsl r9 */

/* ── FUNC 0x282fd0 · spTransformConstraintTimeline_setFrame · size=64 · insn=16 */
/* @0x282fd0 add r1, r1, r1, lsl #2 */
/* @0x282fd4 ldr r0, [r0, #0x10] */
/* @0x282fd8 add r12, r1, #1 */
/* @0x282fdc push {r4, r5} */
/* @0x282fe0 add r1, r0, r1, lsl #2 */
/* @0x282fe4 ldr r5, [sp, #0x8] */
/* @0x282fe8 add r0, r0, r12, lsl #2 */
/* @0x282fec ldr r4, [sp, #0xc] */
/* @0x282ff0 ldr r12, [sp, #0x10] */
/* @0x282ff4 str r2, [r1] */
/* @0x282ff8 str r5, [r0, #0x4] */
/* @0x282ffc str r4, [r0, #0x8] */
/* @0x283000 str r3, [r0] */
/* @0x283004 str r12, [r0, #0xc] */
/* @0x283008 pop {r4, r5} */
/* @0x28300c bx lr */

/* ── FUNC 0x283010 · spPathConstraintPositionTimeline_create · size=24 · insn=6 */
/* @0x283010 ldr r3, [pc, #0xc] */
/* @0x283014 mov r1, #11 */
/* @0x283018 mov r2, #2 */
/* @0x28301c ldr r3, [pc, r3] */
/* @0x283020 b 0x282a10 <_spBaseTimeline_create> */
/* @0x283024 andseq lr, r6, r4, asr #17 */

/* ── FUNC 0x283028 · spPathConstraintPositionTimeline_setFrame · size=20 · insn=5 */
/* @0x283028 ldr r0, [r0, #0x10] */
/* @0x28302c add r12, r0, r1, lsl #3 */
/* @0x283030 str r2, [r12] */
/* @0x283034 str r3, [r12, #0x4] */
/* @0x283038 bx lr */

/* ── FUNC 0x28303c · spPathConstraintSpacingTimeline_create · size=24 · insn=6 */
/* @0x28303c ldr r3, [pc, #0xc] */
/* @0x283040 mov r1, #12 */
/* @0x283044 mov r2, #2 */
/* @0x283048 ldr r3, [pc, r3] */
/* @0x28304c b 0x282a10 <_spBaseTimeline_create> */
/* @0x283050 mulseq r6, r12, r8 */

/* ── FUNC 0x283054 · spPathConstraintSpacingTimeline_setFrame · size=20 · insn=5 */
/* @0x283054 ldr r0, [r0, #0x10] */
/* @0x283058 add r12, r0, r1, lsl #3 */
/* @0x28305c str r2, [r12] */
/* @0x283060 str r3, [r12, #0x4] */
/* @0x283064 bx lr */

/* ── FUNC 0x283068 · spPathConstraintMixTimeline_create · size=24 · insn=6 */
/* @0x283068 ldr r3, [pc, #0xc] */
/* @0x28306c mov r1, #13 */
/* @0x283070 mov r2, #3 */
/* @0x283074 ldr r3, [pc, r3] */
/* @0x283078 b 0x282a10 <_spBaseTimeline_create> */
/* @0x28307c andseq lr, r6, r4, ror r8 */

/* ── FUNC 0x283080 · spPathConstraintMixTimeline_setFrame · size=48 · insn=12 */
/* @0x283080 add r1, r1, r1, lsl #1 */
/* @0x283084 ldr r0, [r0, #0x10] */
/* @0x283088 str r4, [sp, #-0x4]! */
/* @0x28308c add r12, r1, #1 */
/* @0x283090 ldr r4, [sp, #0x4] */
/* @0x283094 add r1, r0, r1, lsl #2 */
/* @0x283098 add r0, r0, r12, lsl #2 */
/* @0x28309c str r2, [r1] */
/* @0x2830a0 str r4, [r0, #0x4] */
/* @0x2830a4 str r3, [r0] */
/* @0x2830a8 ldr r4, [sp], #4 */
/* @0x2830ac bx lr */

/* ── FUNC 0x2830b0 · _spTrackEntry_create · size=68 · insn=17 */
/* @0x2830b0 ldr r2, [pc, #0x38] */
/* @0x2830b4 mov r1, #60 */
/* @0x2830b8 push {r4, lr} */
/* @0x2830bc add r2, pc, r2 */
/* @0x2830c0 mov r4, r0 */
/* @0x2830c4 mov r3, #37 */
/* @0x2830c8 mov r0, #1 */
/* @0x2830cc bl 0x285c4c <_calloc> */
/* @0x2830d0 mov r2, #1065353216 */
/* @0x2830d4 mov r1, #0 */
/* @0x2830d8 movt r1, #0xbf80 */
/* @0x2830dc str r4, [r0] */
/* @0x2830e0 str r1, [r0, #0x1c] */
/* @0x2830e4 str r2, [r0, #0x24] */
/* @0x2830e8 str r2, [r0, #0x34] */
/* @0x2830ec pop {r4, pc} */
/* @0x2830f0 andeq r4, sp, r12, asr #7 */

/* ── FUNC 0x2830f4 · _spAnimationState_createTrackEntry · size=4 · insn=1 */
/* @0x2830f4 b 0x2830b0 <_spTrackEntry_create> */

/* ── FUNC 0x2830f8 · _spTrackEntry_dispose · size=44 · insn=11 */
/* @0x2830f8 push {r4, lr} */
/* @0x2830fc mov r4, r0 */
/* @0x283100 ldr r0, [r0, #0x8] */
/* @0x283104 cmp r0, #0 */
/* @0x283108 beq 0x283118 <_spTrackEntry_dispose+0x20> */
/* @0x28310c ldr r3, [r4] */
/* @0x283110 ldr r3, [r3, #0x20] */
/* @0x283114 blx r3 */
/* @0x283118 mov r0, r4 */
/* @0x28311c pop {r4, lr} */
/* @0x283120 b 0x285c80 <_free> */

/* ── FUNC 0x283124 · _spAnimationState_disposeTrackEntry · size=4 · insn=1 */
/* @0x283124 b 0x2830f8 <_spTrackEntry_dispose> */

/* ── FUNC 0x283128 · spAnimationState_create · size=116 · insn=29 */
/* @0x283128 push {r4, r5, r6, lr} */
/* @0x28312c mov r3, #61 */
/* @0x283130 ldr r5, [pc, #0x58] */
/* @0x283134 mov r6, r0 */
/* @0x283138 mov r1, #36 */
/* @0x28313c mov r0, #1 */
/* @0x283140 add r5, pc, r5 */
/* @0x283144 mov r2, r5 */
/* @0x283148 bl 0x285c4c <_calloc> */
/* @0x28314c mov r1, r5 */
/* @0x283150 mov r2, #63 */
/* @0x283154 mov r4, r0 */
/* @0x283158 mov r0, #256 */
/* @0x28315c bl 0x285c10 <_malloc> */
/* @0x283160 ldr r2, [pc, #0x2c] */
/* @0x283164 ldr r3, [pc, #0x2c] */
/* @0x283168 mov r1, #1065353216 */
/* @0x28316c ldr r2, [pc, r2] */
/* @0x283170 str r6, [r4] */
/* @0x283174 ldr r3, [pc, r3] */
/* @0x283178 str r2, [r4, #0x1c] */
/* @0x28317c str r3, [r4, #0x20] */
/* @0x283180 str r1, [r4, #0x4] */
/* @0x283184 str r0, [r4, #0x18] */
/* @0x283188 mov r0, r4 */
/* @0x28318c pop {r4, r5, r6, pc} */
/* @0x283190 andeq r4, sp, r8, asr #6 */
/* @0x283194 andseq lr, r6, r0, lsl #15 */
/* @0x283198 andseq lr, r6, r12, ror r7 */

/* ── FUNC 0x28319c · _spAnimationState_disposeAllEntries · size=48 · insn=12 */
/* @0x28319c cmp r1, #0 */
/* @0x2831a0 push {r3, r4, r5, lr} */
/* @0x2831a4 mov r5, r0 */
/* @0x2831a8 popeq {r3, r4, r5, pc} */
/* @0x2831ac ldr r4, [r1, #0x4] */
/* @0x2831b0 mov r0, r1 */
/* @0x2831b4 ldr r3, [r5, #0x20] */
/* @0x2831b8 blx r3 */
/* @0x2831bc cmp r4, #0 */
/* @0x2831c0 mov r1, r4 */
/* @0x2831c4 bne 0x2831ac <_spAnimationState_disposeAllEntries+0x10> */
/* @0x2831c8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2831cc · spAnimationState_dispose · size=84 · insn=21 */
/* @0x2831cc push {r3, r4, r5, lr} */
/* @0x2831d0 mov r5, r0 */
/* @0x2831d4 ldr r0, [r0, #0x18] */
/* @0x2831d8 bl 0x285c80 <_free> */
/* @0x2831dc ldr r3, [r5, #0xc] */
/* @0x2831e0 cmp r3, #0 */
/* @0x2831e4 movgt r4, #0 */
/* @0x2831e8 ble 0x28320c <spAnimationState_dispose+0x40> */
/* @0x2831ec ldr r3, [r5, #0x10] */
/* @0x2831f0 mov r0, r5 */
/* @0x2831f4 ldr r1, [r3, r4, lsl #2] */
/* @0x2831f8 add r4, r4, #1 */
/* @0x2831fc bl 0x28319c <_spAnimationState_disposeAllEntries> */
/* @0x283200 ldr r3, [r5, #0xc] */
/* @0x283204 cmp r3, r4 */
/* @0x283208 bgt 0x2831ec <spAnimationState_dispose+0x20> */
/* @0x28320c ldr r0, [r5, #0x10] */
/* @0x283210 bl 0x285c80 <_free> */
/* @0x283214 mov r0, r5 */
/* @0x283218 pop {r3, r4, r5, lr} */
/* @0x28321c b 0x285c80 <_free> */

/* ── FUNC 0x283220 · spAnimationState_apply · size=824 · insn=206 */
/* @0x283220 ldr r3, [r0, #0xc] */
/* @0x283224 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x283228 vpush {d8, d9} */
/* @0x28322c cmp r3, #0 */
/* @0x283230 sub sp, sp, #36 */
/* @0x283234 mov r4, r0 */
/* @0x283238 mov r10, r1 */
/* @0x28323c ble 0x283450 <spAnimationState_apply+0x230> */
/* @0x283240 vmov.f32 s19, #1.000000e+00 */
/* @0x283244 mov r7, #0 */
/* @0x283248 mov r8, r7 */
/* @0x28324c add r12, sp, #28 */
/* @0x283250 str r12, [sp, #0x14] */
/* @0x283254 ldr r2, [r4, #0x10] */
/* @0x283258 lsl r9, r7, #2 */
/* @0x28325c ldr r6, [r2, r7, lsl #2] */
/* @0x283260 cmp r6, #0 */
/* @0x283264 beq 0x283444 <spAnimationState_apply+0x224> */
/* @0x283268 ldr r12, [r6, #0x10] */
/* @0x28326c vldr s18, [r6, #24] */
/* @0x283270 str r8, [sp, #0x1c] */
/* @0x283274 cmp r12, #0 */
/* @0x283278 bne 0x28328c <spAnimationState_apply+0x6c> */
/* @0x28327c vldr s15, [r6, #32] */
/* @0x283280 vcmp.f32 s18, s15 */
/* @0x283284 vmrs APSR_nzcv, fpscr */
/* @0x283288 vmovgt.f32 s18, s15 */
/* @0x28328c ldr r3, [r6, #0x8] */
/* @0x283290 cmp r3, #0 */
/* @0x283294 beq 0x2834a0 <spAnimationState_apply+0x280> */
/* @0x283298 vldr s15, [r6, #48] */
/* @0x28329c vldr s16, [r6, #44] */
/* @0x2832a0 vdiv.f32 s16, s16, s15 */
/* @0x2832a4 ldr r12, [r3, #0x10] */
/* @0x2832a8 vldr s14, [r6, #52] */
/* @0x2832ac vldr s15, [r3, #24] */
/* @0x2832b0 cmp r12, #0 */
/* @0x2832b4 vmul.f32 s16, s16, s14 */
/* @0x2832b8 bne 0x2832cc <spAnimationState_apply+0xac> */
/* @0x2832bc vldr s14, [r3, #32] */
/* @0x2832c0 vcmp.f32 s15, s14 */
/* @0x2832c4 vmrs APSR_nzcv, fpscr */
/* @0x2832c8 vmovgt.f32 s15, s14 */
/* @0x2832cc ldr r0, [r3, #0xc] */
/* @0x2832d0 mov r1, r10 */
/* @0x2832d4 vmov r2, s15 */
/* @0x2832d8 str r12, [sp] */
/* @0x2832dc str r8, [sp, #0x4] */
/* @0x2832e0 str r8, [sp, #0x8] */
/* @0x2832e4 vmov r3, s15 */
/* @0x2832e8 bl 0x281500 <spAnimation_apply> */
/* @0x2832ec vcmpe.f32 s16, s19 */
/* @0x2832f0 vmrs APSR_nzcv, fpscr */
/* @0x2832f4 blt 0x28330c <spAnimationState_apply+0xec> */
/* @0x2832f8 vmov.f32 s16, #1.000000e+00 */
/* @0x2832fc ldr r3, [r4, #0x20] */
/* @0x283300 ldr r0, [r6, #0x8] */
/* @0x283304 blx r3 */
/* @0x283308 str r8, [r6, #0x8] */
/* @0x28330c ldr r12, [r6, #0x10] */
/* @0x283310 mov r1, r10 */
/* @0x283314 ldr r3, [r4, #0x18] */
/* @0x283318 ldr r0, [r6, #0xc] */
/* @0x28331c ldr r2, [r6, #0x1c] */
/* @0x283320 vstr s16, [sp, #12] */
/* @0x283324 str r12, [sp] */
/* @0x283328 add r12, sp, #28 */
/* @0x28332c stmib sp, {r3, r12} */
/* @0x283330 vmov r3, s18 */
/* @0x283334 bl 0x2815ec <spAnimation_mix> */
/* @0x283338 ldr r3, [sp, #0x1c] */
/* @0x28333c cmp r3, #0 */
/* @0x283340 movgt r5, #0 */
/* @0x283344 ble 0x2833c8 <spAnimationState_apply+0x1a8> */
/* @0x283348 ldr r12, [r6, #0x28] */
/* @0x28334c mov r0, r4 */
/* @0x283350 ldr r3, [r4, #0x18] */
/* @0x283354 mov r1, r7 */
/* @0x283358 cmp r12, #0 */
/* @0x28335c mov r2, #3 */
/* @0x283360 ldr r11, [r3, r5, lsl #2] */
/* @0x283364 beq 0x283384 <spAnimationState_apply+0x164> */
/* @0x283368 mov r3, r11 */
/* @0x28336c str r8, [sp] */
/* @0x283370 blx r12 */
/* @0x283374 ldr r3, [r4, #0x10] */
/* @0x283378 ldr r3, [r3, r9] */
/* @0x28337c cmp r3, r6 */
/* @0x283380 bne 0x283440 <spAnimationState_apply+0x220> */
/* @0x283384 ldr r12, [r4, #0x8] */
/* @0x283388 mov r0, r4 */
/* @0x28338c mov r1, r7 */
/* @0x283390 mov r2, #3 */
/* @0x283394 cmp r12, #0 */
/* @0x283398 mov r3, r11 */
/* @0x28339c beq 0x2833b8 <spAnimationState_apply+0x198> */
/* @0x2833a0 str r8, [sp] */
/* @0x2833a4 blx r12 */
/* @0x2833a8 ldr r3, [r4, #0x10] */
/* @0x2833ac ldr r3, [r3, r9] */
/* @0x2833b0 cmp r3, r6 */
/* @0x2833b4 bne 0x283440 <spAnimationState_apply+0x220> */
/* @0x2833b8 ldr r3, [sp, #0x1c] */
/* @0x2833bc add r5, r5, #1 */
/* @0x2833c0 cmp r3, r5 */
/* @0x2833c4 bgt 0x283348 <spAnimationState_apply+0x128> */
/* @0x2833c8 ldr r3, [r6, #0x10] */
/* @0x2833cc cmp r3, #0 */
/* @0x2833d0 bne 0x2834dc <spAnimationState_apply+0x2bc> */
/* @0x2833d4 vldr s15, [r6, #32] */
/* @0x2833d8 vldr s14, [r6, #28] */
/* @0x2833dc vcmpe.f32 s14, s15 */
/* @0x2833e0 vmrs APSR_nzcv, fpscr */
/* @0x2833e4 bpl 0x2833f8 <spAnimationState_apply+0x1d8> */
/* @0x2833e8 vcmpe.f32 s18, s15 */
/* @0x2833ec vmrs APSR_nzcv, fpscr */
/* @0x2833f0 movlt r3, #0 */
/* @0x2833f4 movge r3, #1 */
/* @0x2833f8 cmp r3, #0 */
/* @0x2833fc beq 0x283490 <spAnimationState_apply+0x270> */
/* @0x283400 vldr s15, [r6, #32] */
/* @0x283404 vdiv.f32 s18, s18, s15 */
/* @0x283408 ldr r12, [r6, #0x28] */
/* @0x28340c cmp r12, #0 */
/* @0x283410 vcvt.s32.f32 s18, s18 */
/* @0x283414 beq 0x28345c <spAnimationState_apply+0x23c> */
/* @0x283418 mov r3, #0 */
/* @0x28341c vstr s18, [sp] */
/* @0x283420 mov r0, r4 */
/* @0x283424 mov r1, r7 */
/* @0x283428 mov r2, #2 */
/* @0x28342c blx r12 */
/* @0x283430 ldr r3, [r4, #0x10] */
/* @0x283434 ldr r3, [r3, r9] */
/* @0x283438 cmp r3, r6 */
/* @0x28343c beq 0x28345c <spAnimationState_apply+0x23c> */
/* @0x283440 ldr r3, [r4, #0xc] */
/* @0x283444 add r7, r7, #1 */
/* @0x283448 cmp r3, r7 */
/* @0x28344c bgt 0x283254 <spAnimationState_apply+0x34> */
/* @0x283450 add sp, sp, #36 */
/* @0x283454 vpop {d8, d9} */
/* @0x283458 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28345c ldr r12, [r4, #0x8] */
/* @0x283460 cmp r12, #0 */
/* @0x283464 beq 0x283490 <spAnimationState_apply+0x270> */
/* @0x283468 mov r3, #0 */
/* @0x28346c vstr s18, [sp] */
/* @0x283470 mov r0, r4 */
/* @0x283474 mov r1, r7 */
/* @0x283478 mov r2, #2 */
/* @0x28347c blx r12 */
/* @0x283480 ldr r3, [r4, #0x10] */
/* @0x283484 ldr r3, [r3, r9] */
/* @0x283488 cmp r3, r6 */
/* @0x28348c bne 0x283440 <spAnimationState_apply+0x220> */
/* @0x283490 ldr r2, [r6, #0x18] */
/* @0x283494 ldr r3, [r4, #0xc] */
/* @0x283498 str r2, [r6, #0x1c] */
/* @0x28349c b 0x283444 <spAnimationState_apply+0x224> */
/* @0x2834a0 vldr s15, [r6, #52] */
/* @0x2834a4 vcmp.f32 s15, s19 */
/* @0x2834a8 ldr r0, [r6, #0xc] */
/* @0x2834ac ldr r2, [r6, #0x1c] */
/* @0x2834b0 ldr r3, [r4, #0x18] */
/* @0x2834b4 vmrs APSR_nzcv, fpscr */
/* @0x2834b8 bne 0x283534 <spAnimationState_apply+0x314> */
/* @0x2834bc str r3, [sp, #0x4] */
/* @0x2834c0 mov r1, r10 */
/* @0x2834c4 add r3, sp, #28 */
/* @0x2834c8 str r12, [sp] */
/* @0x2834cc str r3, [sp, #0x8] */
/* @0x2834d0 vmov r3, s18 */
/* @0x2834d4 bl 0x281500 <spAnimation_apply> */
/* @0x2834d8 b 0x283338 <spAnimationState_apply+0x118> */
/* @0x2834dc vldr s14, [r6, #28] */
/* @0x2834e0 vcvt.f64.f32 d6, s14 */
/* @0x2834e4 vldr s15, [r6, #32] */
/* @0x2834e8 vmov r0, r1, d6 */
/* @0x2834ec vcvt.f64.f32 d6, s15 */
/* @0x2834f0 vmov r2, r3, d6 */
/* @0x2834f4 bl 0xb66ac <fmod@plt> */
/* @0x2834f8 vldr s15, [r6, #32] */
/* @0x2834fc vcvt.f64.f32 d6, s18 */
/* @0x283500 vmov d8, r0, r1 */
/* @0x283504 vmov r0, r1, d6 */
/* @0x283508 vcvt.f64.f32 d6, s15 */
/* @0x28350c vmov r2, r3, d6 */
/* @0x283510 bl 0xb66ac <fmod@plt> */
/* @0x283514 vcvt.f32.f64 s16, d8 */
/* @0x283518 vmov d6, r0, r1 */
/* @0x28351c vcvt.f32.f64 s15, d6 */
/* @0x283520 vcmpe.f32 s16, s15 */
/* @0x283524 vmrs APSR_nzcv, fpscr */
/* @0x283528 movle r3, #0 */
/* @0x28352c movgt r3, #1 */
/* @0x283530 b 0x2833f8 <spAnimationState_apply+0x1d8> */
/* @0x283534 str r12, [sp] */
/* @0x283538 vstr s15, [sp, #12] */
/* @0x28353c str r3, [sp, #0x4] */
/* @0x283540 add r12, sp, #28 */
/* @0x283544 mov r1, r10 */
/* @0x283548 str r12, [sp, #0x8] */
/* @0x28354c vmov r3, s18 */
/* @0x283550 bl 0x2815ec <spAnimation_mix> */
/* @0x283554 b 0x283338 <spAnimationState_apply+0x118> */

/* ── FUNC 0x283558 · spAnimationState_clearTrack · size=148 · insn=37 */
/* @0x283558 ldr r3, [r0, #0xc] */
/* @0x28355c push {r4, r5, r6, lr} */
/* @0x283560 cmp r3, r1 */
/* @0x283564 sub sp, sp, #8 */
/* @0x283568 mov r4, r0 */
/* @0x28356c mov r5, r1 */
/* @0x283570 ble 0x2835e4 <spAnimationState_clearTrack+0x8c> */
/* @0x283574 ldr r3, [r0, #0x10] */
/* @0x283578 ldr r6, [r3, r1, lsl #2] */
/* @0x28357c cmp r6, #0 */
/* @0x283580 beq 0x2835e4 <spAnimationState_clearTrack+0x8c> */
/* @0x283584 ldr r12, [r6, #0x28] */
/* @0x283588 cmp r12, #0 */
/* @0x28358c beq 0x2835a0 <spAnimationState_clearTrack+0x48> */
/* @0x283590 mov r3, #0 */
/* @0x283594 mov r2, #1 */
/* @0x283598 str r3, [sp] */
/* @0x28359c blx r12 */
/* @0x2835a0 ldr r12, [r4, #0x8] */
/* @0x2835a4 cmp r12, #0 */
/* @0x2835a8 beq 0x2835c4 <spAnimationState_clearTrack+0x6c> */
/* @0x2835ac mov r3, #0 */
/* @0x2835b0 mov r0, r4 */
/* @0x2835b4 str r3, [sp] */
/* @0x2835b8 mov r1, r5 */
/* @0x2835bc mov r2, #1 */
/* @0x2835c0 blx r12 */
/* @0x2835c4 ldr r3, [r4, #0x10] */
/* @0x2835c8 mov r2, #0 */
/* @0x2835cc mov r1, r6 */
/* @0x2835d0 mov r0, r4 */
/* @0x2835d4 str r2, [r3, r5, lsl #2] */
/* @0x2835d8 add sp, sp, #8 */
/* @0x2835dc pop {r4, r5, r6, lr} */
/* @0x2835e0 b 0x28319c <_spAnimationState_disposeAllEntries> */
/* @0x2835e4 add sp, sp, #8 */
/* @0x2835e8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2835ec · spAnimationState_clearTracks · size=64 · insn=16 */
/* @0x2835ec push {r3, r4, r5, lr} */
/* @0x2835f0 mov r5, r0 */
/* @0x2835f4 ldr r3, [r0, #0xc] */
/* @0x2835f8 cmp r3, #0 */
/* @0x2835fc movgt r4, #0 */
/* @0x283600 ble 0x283620 <spAnimationState_clearTracks+0x34> */
/* @0x283604 mov r1, r4 */
/* @0x283608 mov r0, r5 */
/* @0x28360c bl 0x283558 <spAnimationState_clearTrack> */
/* @0x283610 ldr r3, [r5, #0xc] */
/* @0x283614 add r4, r4, #1 */
/* @0x283618 cmp r3, r4 */
/* @0x28361c bgt 0x283604 <spAnimationState_clearTracks+0x18> */
/* @0x283620 mov r3, #0 */
/* @0x283624 str r3, [r5, #0xc] */
/* @0x283628 pop {r3, r4, r5, pc} */

/* ── FUNC 0x28362c · _spAnimationState_expandToIndex · size=108 · insn=27 */
/* @0x28362c ldr r3, [r0, #0xc] */
/* @0x283630 push {r4, r5, r6, lr} */
/* @0x283634 cmp r3, r1 */
/* @0x283638 mov r4, r0 */
/* @0x28363c ble 0x28364c <_spAnimationState_expandToIndex+0x20> */
/* @0x283640 ldr r3, [r0, #0x10] */
/* @0x283644 ldr r0, [r3, r1, lsl #2] */
/* @0x283648 pop {r4, r5, r6, pc} */
/* @0x28364c add r5, r1, #1 */
/* @0x283650 ldr r2, [pc, #0x3c] */
/* @0x283654 mov r3, #221 */
/* @0x283658 mov r1, #4 */
/* @0x28365c add r2, pc, r2 */
/* @0x283660 mov r0, r5 */
/* @0x283664 bl 0x285c4c <_calloc> */
/* @0x283668 ldr r2, [r4, #0xc] */
/* @0x28366c ldr r1, [r4, #0x10] */
/* @0x283670 lsl r2, r2, #2 */
/* @0x283674 mov r6, r0 */
/* @0x283678 bl 0xb65bc <memcpy@plt> */
/* @0x28367c ldr r0, [r4, #0x10] */
/* @0x283680 bl 0x285c80 <_free> */
/* @0x283684 mov r0, #0 */
/* @0x283688 str r6, [r4, #0x10] */
/* @0x28368c str r5, [r4, #0xc] */
/* @0x283690 pop {r4, r5, r6, pc} */
/* @0x283694 andeq r3, sp, r12, lsr #28 */

/* ── FUNC 0x283698 · _spAnimationState_setCurrent · size=356 · insn=89 */
/* @0x283698 push {r4, r5, r6, r7, r8, lr} */
/* @0x28369c sub sp, sp, #8 */
/* @0x2836a0 mov r5, r2 */
/* @0x2836a4 mov r4, r0 */
/* @0x2836a8 mov r7, r1 */
/* @0x2836ac bl 0x28362c <_spAnimationState_expandToIndex> */
/* @0x2836b0 subs r6, r0, #0 */
/* @0x2836b4 beq 0x28376c <_spAnimationState_setCurrent+0xd4> */
/* @0x2836b8 ldr r12, [r6, #0x28] */
/* @0x2836bc mov r3, #0 */
/* @0x2836c0 ldr r8, [r6, #0x8] */
/* @0x2836c4 cmp r12, r3 */
/* @0x2836c8 str r3, [r6, #0x8] */
/* @0x2836cc beq 0x2836e4 <_spAnimationState_setCurrent+0x4c> */
/* @0x2836d0 str r3, [sp] */
/* @0x2836d4 mov r0, r4 */
/* @0x2836d8 mov r1, r7 */
/* @0x2836dc mov r2, #1 */
/* @0x2836e0 blx r12 */
/* @0x2836e4 ldr r12, [r4, #0x8] */
/* @0x2836e8 cmp r12, #0 */
/* @0x2836ec beq 0x283708 <_spAnimationState_setCurrent+0x70> */
/* @0x2836f0 mov r3, #0 */
/* @0x2836f4 mov r0, r4 */
/* @0x2836f8 str r3, [sp] */
/* @0x2836fc mov r1, r7 */
/* @0x283700 mov r2, #1 */
/* @0x283704 blx r12 */
/* @0x283708 ldr r0, [r4] */
/* @0x28370c ldr r1, [r6, #0xc] */
/* @0x283710 ldr r2, [r5, #0xc] */
/* @0x283714 bl 0x283ca8 <spAnimationStateData_getMix> */
/* @0x283718 mov r3, #0 */
/* @0x28371c vmov s15, r0 */
/* @0x283720 str r0, [r5, #0x30] */
/* @0x283724 vcmpe.f32 s15, #0 */
/* @0x283728 vmrs APSR_nzcv, fpscr */
/* @0x28372c ble 0x2837ec <_spAnimationState_setCurrent+0x154> */
/* @0x283730 cmp r8, #0 */
/* @0x283734 str r3, [r5, #0x2c] */
/* @0x283738 beq 0x2837b0 <_spAnimationState_setCurrent+0x118> */
/* @0x28373c vldr s15, [r6, #48] */
/* @0x283740 vldr s14, [r6, #44] */
/* @0x283744 vdiv.f32 s14, s14, s15 */
/* @0x283748 vmov.f32 s15, #5.000000e-01 */
/* @0x28374c vcmpe.f32 s14, s15 */
/* @0x283750 vmrs APSR_nzcv, fpscr */
/* @0x283754 strmi r8, [r5, #0x8] */
/* @0x283758 movmi r8, r6 */
/* @0x28375c bpl 0x2837b0 <_spAnimationState_setCurrent+0x118> */
/* @0x283760 mov r0, r8 */
/* @0x283764 ldr r3, [r4, #0x20] */
/* @0x283768 blx r3 */
/* @0x28376c ldr r3, [r4, #0x10] */
/* @0x283770 str r5, [r3, r7, lsl #2] */
/* @0x283774 ldr r12, [r5, #0x28] */
/* @0x283778 cmp r12, #0 */
/* @0x28377c beq 0x2837c0 <_spAnimationState_setCurrent+0x128> */
/* @0x283780 mov r3, #0 */
/* @0x283784 mov r0, r4 */
/* @0x283788 mov r2, r3 */
/* @0x28378c str r3, [sp] */
/* @0x283790 mov r1, r7 */
/* @0x283794 blx r12 */
/* @0x283798 ldr r3, [r4, #0x10] */
/* @0x28379c ldr r3, [r3, r7, lsl #2] */
/* @0x2837a0 cmp r3, r5 */
/* @0x2837a4 beq 0x2837c0 <_spAnimationState_setCurrent+0x128> */
/* @0x2837a8 add sp, sp, #8 */
/* @0x2837ac pop {r4, r5, r6, r7, r8, pc} */
/* @0x2837b0 str r6, [r5, #0x8] */
/* @0x2837b4 cmp r8, #0 */
/* @0x2837b8 bne 0x283760 <_spAnimationState_setCurrent+0xc8> */
/* @0x2837bc b 0x28376c <_spAnimationState_setCurrent+0xd4> */
/* @0x2837c0 ldr r12, [r4, #0x8] */
/* @0x2837c4 cmp r12, #0 */
/* @0x2837c8 beq 0x2837a8 <_spAnimationState_setCurrent+0x110> */
/* @0x2837cc mov r3, #0 */
/* @0x2837d0 mov r0, r4 */
/* @0x2837d4 mov r2, r3 */
/* @0x2837d8 mov r1, r7 */
/* @0x2837dc str r3, [sp] */
/* @0x2837e0 blx r12 */
/* @0x2837e4 add sp, sp, #8 */
/* @0x2837e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2837ec mov r0, r6 */
/* @0x2837f0 ldr r3, [r4, #0x20] */
/* @0x2837f4 blx r3 */
/* @0x2837f8 b 0x2837b4 <_spAnimationState_setCurrent+0x11c> */

/* ── FUNC 0x2837fc · spAnimationState_update · size=260 · insn=65 */
/* @0x2837fc push {r4, r5, r6, lr} */
/* @0x283800 vpush {d8} */
/* @0x283804 vmov s15, r1 */
/* @0x283808 vldr s16, [r0, #4] */
/* @0x28380c ldr r6, [r0, #0xc] */
/* @0x283810 mov r5, r0 */
/* @0x283814 vmul.f32 s16, s15, s16 */
/* @0x283818 cmp r6, #0 */
/* @0x28381c ble 0x2838f8 <spAnimationState_update+0xfc> */
/* @0x283820 mov r4, #0 */
/* @0x283824 b 0x283858 <spAnimationState_update+0x5c> */
/* @0x283828 vldr s14, [r3, #28] */
/* @0x28382c vldr s15, [r12, #20] */
/* @0x283830 vsub.f32 s15, s14, s15 */
/* @0x283834 vcmpe.f32 s15, #0 */
/* @0x283838 vstr s15, [r12, #24] */
/* @0x28383c vmrs APSR_nzcv, fpscr */
/* @0x283840 blt 0x28384c <spAnimationState_update+0x50> */
/* @0x283844 bl 0x283698 <_spAnimationState_setCurrent> */
/* @0x283848 ldr r6, [r5, #0xc] */
/* @0x28384c add r4, r4, #1 */
/* @0x283850 cmp r6, r4 */
/* @0x283854 ble 0x2838f8 <spAnimationState_update+0xfc> */
/* @0x283858 ldr r3, [r5, #0x10] */
/* @0x28385c ldr r3, [r3, r4, lsl #2] */
/* @0x283860 cmp r3, #0 */
/* @0x283864 beq 0x28384c <spAnimationState_update+0x50> */
/* @0x283868 vldr s15, [r3, #24] */
/* @0x28386c vldr s14, [r3, #36] */
/* @0x283870 vmla.f32 s15, s16, s14 */
/* @0x283874 ldr r2, [r3, #0x8] */
/* @0x283878 mov r0, r5 */
/* @0x28387c mov r1, r4 */
/* @0x283880 cmp r2, #0 */
/* @0x283884 vstr s15, [r3, #24] */
/* @0x283888 beq 0x2838ac <spAnimationState_update+0xb0> */
/* @0x28388c vldr s15, [r2, #36] */
/* @0x283890 vmul.f32 s15, s16, s15 */
/* @0x283894 vldr s14, [r2, #24] */
/* @0x283898 vldr s13, [r3, #44] */
/* @0x28389c vadd.f32 s14, s14, s15 */
/* @0x2838a0 vadd.f32 s15, s13, s15 */
/* @0x2838a4 vstr s14, [r2, #24] */
/* @0x2838a8 vstr s15, [r3, #44] */
/* @0x2838ac ldr r12, [r3, #0x4] */
/* @0x2838b0 cmp r12, #0 */
/* @0x2838b4 mov r2, r12 */
/* @0x2838b8 bne 0x283828 <spAnimationState_update+0x2c> */
/* @0x2838bc ldr r2, [r3, #0x10] */
/* @0x2838c0 cmp r2, #0 */
/* @0x2838c4 bne 0x28384c <spAnimationState_update+0x50> */
/* @0x2838c8 vldr s14, [r3, #28] */
/* @0x2838cc vldr s15, [r3, #32] */
/* @0x2838d0 vcmpe.f32 s14, s15 */
/* @0x2838d4 vmrs APSR_nzcv, fpscr */
/* @0x2838d8 blt 0x28384c <spAnimationState_update+0x50> */
/* @0x2838dc mov r1, r4 */
/* @0x2838e0 mov r0, r5 */
/* @0x2838e4 bl 0x283558 <spAnimationState_clearTrack> */
/* @0x2838e8 ldr r6, [r5, #0xc] */
/* @0x2838ec add r4, r4, #1 */
/* @0x2838f0 cmp r6, r4 */
/* @0x2838f4 bgt 0x283858 <spAnimationState_update+0x5c> */
/* @0x2838f8 vpop {d8} */
/* @0x2838fc pop {r4, r5, r6, pc} */

/* ── FUNC 0x283900 · spAnimationState_setAnimation · size=100 · insn=25 */
/* @0x283900 push {r4, r5, r6, r7, r8, lr} */
/* @0x283904 mov r6, r2 */
/* @0x283908 mov r8, r3 */
/* @0x28390c mov r5, r0 */
/* @0x283910 mov r7, r1 */
/* @0x283914 bl 0x28362c <_spAnimationState_expandToIndex> */
/* @0x283918 cmp r0, #0 */
/* @0x28391c beq 0x28392c <spAnimationState_setAnimation+0x2c> */
/* @0x283920 ldr r1, [r0, #0x4] */
/* @0x283924 mov r0, r5 */
/* @0x283928 bl 0x28319c <_spAnimationState_disposeAllEntries> */
/* @0x28392c ldr r3, [r5, #0x1c] */
/* @0x283930 mov r0, r5 */
/* @0x283934 blx r3 */
/* @0x283938 ldr r3, [r6, #0x4] */
/* @0x28393c mov r1, r7 */
/* @0x283940 mov r4, r0 */
/* @0x283944 str r6, [r0, #0xc] */
/* @0x283948 str r8, [r0, #0x10] */
/* @0x28394c mov r2, r4 */
/* @0x283950 str r3, [r0, #0x20] */
/* @0x283954 mov r0, r5 */
/* @0x283958 bl 0x283698 <_spAnimationState_setCurrent> */
/* @0x28395c mov r0, r4 */
/* @0x283960 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x283964 · spAnimationState_setAnimationByName · size=56 · insn=14 */
/* @0x283964 push {r4, r5, r6, lr} */
/* @0x283968 mov r4, r0 */
/* @0x28396c ldr r0, [r0] */
/* @0x283970 mov r5, r1 */
/* @0x283974 mov r1, r2 */
/* @0x283978 mov r6, r3 */
/* @0x28397c ldr r0, [r0] */
/* @0x283980 bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0x283984 mov r1, r5 */
/* @0x283988 mov r3, r6 */
/* @0x28398c mov r2, r0 */
/* @0x283990 mov r0, r4 */
/* @0x283994 pop {r4, r5, r6, lr} */
/* @0x283998 b 0x283900 <spAnimationState_setAnimation> */

/* ── FUNC 0x28399c · spAnimationState_addAnimation · size=208 · insn=52 */
/* @0x28399c push {r4, r5, r6, r7, r8, lr} */
/* @0x2839a0 vpush {d8} */
/* @0x2839a4 mov r7, r1 */
/* @0x2839a8 vldr s16, [sp, #32] */
/* @0x2839ac ldr r1, [r0, #0x1c] */
/* @0x2839b0 mov r6, r2 */
/* @0x2839b4 mov r8, r3 */
/* @0x2839b8 mov r5, r0 */
/* @0x2839bc blx r1 */
/* @0x2839c0 ldr r3, [r6, #0x4] */
/* @0x2839c4 mov r1, r7 */
/* @0x2839c8 str r8, [r0, #0x10] */
/* @0x2839cc mov r4, r0 */
/* @0x2839d0 str r6, [r0, #0xc] */
/* @0x2839d4 str r3, [r0, #0x20] */
/* @0x2839d8 mov r0, r5 */
/* @0x2839dc bl 0x28362c <_spAnimationState_expandToIndex> */
/* @0x2839e0 subs r12, r0, #0 */
/* @0x2839e4 bne 0x2839f0 <spAnimationState_addAnimation+0x54> */
/* @0x2839e8 b 0x283a54 <spAnimationState_addAnimation+0xb8> */
/* @0x2839ec mov r12, r3 */
/* @0x2839f0 ldr r3, [r12, #0x4] */
/* @0x2839f4 cmp r3, #0 */
/* @0x2839f8 bne 0x2839ec <spAnimationState_addAnimation+0x50> */
/* @0x2839fc str r4, [r12, #0x4] */
/* @0x283a00 vcmpe.f32 s16, #0 */
/* @0x283a04 vmrs APSR_nzcv, fpscr */
/* @0x283a08 bls 0x283a1c <spAnimationState_addAnimation+0x80> */
/* @0x283a0c vstr s16, [r4, #20] */
/* @0x283a10 vpop {d8} */
/* @0x283a14 mov r0, r4 */
/* @0x283a18 pop {r4, r5, r6, r7, r8, pc} */
/* @0x283a1c cmp r12, #0 */
/* @0x283a20 beq 0x283a60 <spAnimationState_addAnimation+0xc4> */
/* @0x283a24 ldr r0, [r5] */
/* @0x283a28 mov r2, r6 */
/* @0x283a2c ldr r1, [r12, #0xc] */
/* @0x283a30 vldr s17, [r12, #32] */
/* @0x283a34 bl 0x283ca8 <spAnimationStateData_getMix> */
/* @0x283a38 vmov s15, r0 */
/* @0x283a3c mov r0, r4 */
/* @0x283a40 vsub.f32 s17, s17, s15 */
/* @0x283a44 vadd.f32 s16, s16, s17 */
/* @0x283a48 vstr s16, [r4, #20] */
/* @0x283a4c vpop {d8} */
/* @0x283a50 pop {r4, r5, r6, r7, r8, pc} */
/* @0x283a54 ldr r3, [r5, #0x10] */
/* @0x283a58 str r4, [r3, r7, lsl #2] */
/* @0x283a5c b 0x283a00 <spAnimationState_addAnimation+0x64> */
/* @0x283a60 vldr s16, [pc] */
/* @0x283a64 b 0x283a0c <spAnimationState_addAnimation+0x70> */
/* @0x283a68 andeq r0, r0, r0 */

/* ── FUNC 0x283a6c · spAnimationState_addAnimationByName · size=64 · insn=16 */
/* @0x283a6c push {r4, r5, r6, r7, r8, lr} */
/* @0x283a70 mov r4, r0 */
/* @0x283a74 ldr r0, [r0] */
/* @0x283a78 mov r5, r1 */
/* @0x283a7c mov r1, r2 */
/* @0x283a80 ldr r7, [sp, #0x18] */
/* @0x283a84 mov r6, r3 */
/* @0x283a88 ldr r0, [r0] */
/* @0x283a8c bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0x283a90 str r7, [sp, #0x18] */
/* @0x283a94 mov r1, r5 */
/* @0x283a98 mov r3, r6 */
/* @0x283a9c mov r2, r0 */
/* @0x283aa0 mov r0, r4 */
/* @0x283aa4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x283aa8 b 0x28399c <spAnimationState_addAnimation> */

/* ── FUNC 0x283aac · spAnimationState_getCurrent · size=24 · insn=6 */
/* @0x283aac ldr r3, [r0, #0xc] */
/* @0x283ab0 cmp r3, r1 */
/* @0x283ab4 ldrgt r3, [r0, #0x10] */
/* @0x283ab8 ldrgt r0, [r3, r1, lsl #2] */
/* @0x283abc movle r0, #0 */
/* @0x283ac0 bx lr */

/* ── FUNC 0x283ac4 · _ToEntry_create · size=52 · insn=13 */
/* @0x283ac4 ldr r2, [pc, #0x28] */
/* @0x283ac8 push {r3, r4, r5, lr} */
/* @0x283acc add r2, pc, r2 */
/* @0x283ad0 mov r5, r0 */
/* @0x283ad4 mov r4, r1 */
/* @0x283ad8 mov r3, #43 */
/* @0x283adc mov r1, #12 */
/* @0x283ae0 mov r0, #1 */
/* @0x283ae4 bl 0x285c4c <_calloc> */
/* @0x283ae8 str r5, [r0] */
/* @0x283aec str r4, [r0, #0x4] */
/* @0x283af0 pop {r3, r4, r5, pc} */
/* @0x283af4 strdeq r3, r4, [sp], -r8 */

/* ── FUNC 0x283af8 · _ToEntry_dispose · size=4 · insn=1 */
/* @0x283af8 b 0x285c80 <_free> */

/* ── FUNC 0x283afc · _FromEntry_create · size=44 · insn=11 */
/* @0x283afc ldr r2, [pc, #0x20] */
/* @0x283b00 mov r1, #12 */
/* @0x283b04 push {r4, lr} */
/* @0x283b08 add r2, pc, r2 */
/* @0x283b0c mov r4, r0 */
/* @0x283b10 mov r3, #63 */
/* @0x283b14 mov r0, #1 */
/* @0x283b18 bl 0x285c4c <_calloc> */
/* @0x283b1c str r4, [r0] */
/* @0x283b20 pop {r4, pc} */
/* @0x283b24 strheq r3, [sp], -r12 */

/* ── FUNC 0x283b28 · _FromEntry_dispose · size=4 · insn=1 */
/* @0x283b28 b 0x285c80 <_free> */

/* ── FUNC 0x283b2c · spAnimationStateData_create · size=44 · insn=11 */
/* @0x283b2c ldr r2, [pc, #0x20] */
/* @0x283b30 mov r1, #12 */
/* @0x283b34 push {r4, lr} */
/* @0x283b38 add r2, pc, r2 */
/* @0x283b3c mov r4, r0 */
/* @0x283b40 mov r3, #75 */
/* @0x283b44 mov r0, #1 */
/* @0x283b48 bl 0x285c4c <_calloc> */
/* @0x283b4c str r4, [r0] */
/* @0x283b50 pop {r4, pc} */
/* @0x283b54 andeq r3, sp, r12, lsl #19 */

/* ── FUNC 0x283b58 · spAnimationStateData_dispose · size=88 · insn=22 */
/* @0x283b58 push {r4, r5, r6, lr} */
/* @0x283b5c mov r6, r0 */
/* @0x283b60 ldr r5, [r0, #0x8] */
/* @0x283b64 cmp r5, #0 */
/* @0x283b68 beq 0x283ba4 <spAnimationStateData_dispose+0x4c> */
/* @0x283b6c ldr r0, [r5, #0x4] */
/* @0x283b70 cmp r0, #0 */
/* @0x283b74 beq 0x283b8c <spAnimationStateData_dispose+0x34> */
/* @0x283b78 ldr r4, [r0, #0x8] */
/* @0x283b7c bl 0x283af8 <_ToEntry_dispose> */
/* @0x283b80 cmp r4, #0 */
/* @0x283b84 mov r0, r4 */
/* @0x283b88 bne 0x283b78 <spAnimationStateData_dispose+0x20> */
/* @0x283b8c ldr r4, [r5, #0x8] */
/* @0x283b90 mov r0, r5 */
/* @0x283b94 bl 0x283b28 <_FromEntry_dispose> */
/* @0x283b98 cmp r4, #0 */
/* @0x283b9c movne r5, r4 */
/* @0x283ba0 bne 0x283b6c <spAnimationStateData_dispose+0x14> */
/* @0x283ba4 mov r0, r6 */
/* @0x283ba8 pop {r4, r5, r6, lr} */
/* @0x283bac b 0x285c80 <_free> */
