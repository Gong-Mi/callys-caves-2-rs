/* libyoyo.so 覆盖卡组 0283
 * 函数 0x2d90a4..0x2dbb2c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2d90a4 · b2ParticleSystem::SolvePressure(b2TimeStep const&) · size=888 · insn=222 */
/* @0x2d90a4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2d90a8 vpush {d8, d9, d10} */
/* @0x2d90ac mov r4, r0 */
/* @0x2d90b0 ldr lr, [r0, #0x24] */
/* @0x2d90b4 mov r5, r1 */
/* @0x2d90b8 cmp lr, #0 */
/* @0x2d90bc ble 0x2d90d8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x34> */
/* @0x2d90c0 ldr r3, [r0, #0x48] */
/* @0x2d90c4 mov r1, #0 */
/* @0x2d90c8 add r2, r3, lr, lsl #2 */
/* @0x2d90cc str r1, [r3], #4 */
/* @0x2d90d0 cmp r3, r2 */
/* @0x2d90d4 bne 0x2d90cc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x28> */
/* @0x2d90d8 ldr r1, [r4, #0x80] */
/* @0x2d90dc cmp r1, #0 */
/* @0x2d90e0 ble 0x2d9120 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x7c> */
/* @0x2d90e4 ldr r3, [r4, #0x88] */
/* @0x2d90e8 add r1, r1, r1, lsl #1 */
/* @0x2d90ec ldr r0, [r4, #0x48] */
/* @0x2d90f0 add r3, r3, #8 */
/* @0x2d90f4 add r1, r3, r1, lsl #3 */
/* @0x2d90f8 ldr r2, [r3, #-0x8] */
/* @0x2d90fc mov r12, r3 */
/* @0x2d9100 vldr s15, [r12] */
/* @0x2d9104 add r3, r3, #24 */
/* @0x2d9108 cmp r3, r1 */
/* @0x2d910c add r2, r0, r2, lsl #2 */
/* @0x2d9110 vldr s14, [r2] */
/* @0x2d9114 vadd.f32 s15, s14, s15 */
/* @0x2d9118 vstr s15, [r2] */
/* @0x2d911c bne 0x2d90f8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x54> */
/* @0x2d9120 ldr r1, [r4, #0x74] */
/* @0x2d9124 cmp r1, #0 */
/* @0x2d9128 ble 0x2d9178 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0xd4> */
/* @0x2d912c ldr r3, [r4, #0x7c] */
/* @0x2d9130 add r1, r1, r1, lsl #1 */
/* @0x2d9134 ldr r12, [r4, #0x48] */
/* @0x2d9138 add r3, r3, #12 */
/* @0x2d913c add r1, r3, r1, lsl #3 */
/* @0x2d9140 ldr r0, [r3, #-0xc] */
/* @0x2d9144 vldr s15, [r3] */
/* @0x2d9148 ldr r2, [r3, #-0x8] */
/* @0x2d914c add r3, r3, #24 */
/* @0x2d9150 cmp r3, r1 */
/* @0x2d9154 add r0, r12, r0, lsl #2 */
/* @0x2d9158 vldr s14, [r0] */
/* @0x2d915c vadd.f32 s14, s14, s15 */
/* @0x2d9160 add r2, r12, r2, lsl #2 */
/* @0x2d9164 vstr s14, [r0] */
/* @0x2d9168 vldr s14, [r2] */
/* @0x2d916c vadd.f32 s15, s14, s15 */
/* @0x2d9170 vstr s15, [r2] */
/* @0x2d9174 bne 0x2d9140 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x9c> */
/* @0x2d9178 ldr r3, [r4, #0x4] */
/* @0x2d917c tst r3, #64 */
/* @0x2d9180 beq 0x2d91bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x118> */
/* @0x2d9184 cmp lr, #0 */
/* @0x2d9188 ble 0x2d91bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x118> */
/* @0x2d918c ldr r1, [r4, #0x30] */
/* @0x2d9190 lsl lr, lr, #2 */
/* @0x2d9194 mov r3, #0 */
/* @0x2d9198 mov r0, #0 */
/* @0x2d919c ldr r2, [r1, r3] */
/* @0x2d91a0 tst r2, #64 */
/* @0x2d91a4 ldrne r2, [r4, #0x48] */
/* @0x2d91a8 addne r2, r2, r3 */
/* @0x2d91ac add r3, r3, #4 */
/* @0x2d91b0 strne r0, [r2] */
/* @0x2d91b4 cmp r3, lr */
/* @0x2d91b8 bne 0x2d919c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0xf8> */
/* @0x2d91bc mov r0, r4 */
/* @0x2d91c0 mov r1, r5 */
/* @0x2d91c4 vldr s19, [r4, #172] */
/* @0x2d91c8 bl 0x2d8584 <_ZNK16b2ParticleSystem19GetCriticalPressureERK10b2TimeStep> */
/* @0x2d91cc ldr r2, [r4, #0x24] */
/* @0x2d91d0 cmp r2, #0 */
/* @0x2d91d4 vmov s15, r0 */
/* @0x2d91d8 vmul.f32 s19, s19, s15 */
/* @0x2d91dc ble 0x2d9240 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x19c> */
/* @0x2d91e0 ldr r3, [r4, #0x48] */
/* @0x2d91e4 add r2, r3, r2, lsl #2 */
/* @0x2d91e8 vmov.f32 s13, #5.000000e+00 */
/* @0x2d91ec vmov.f32 s12, #1.000000e+00 */
/* @0x2d91f0 b 0x2d9218 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x174> */
/* @0x2d91f4 vsub.f32 s15, s15, s12 */
/* @0x2d91f8 vldr s14, [pc, #536] */
/* @0x2d91fc vcmpe.f32 s15, s14 */
/* @0x2d9200 vmrs APSR_nzcv, fpscr */
/* @0x2d9204 bpl 0x2d922c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x188> */
/* @0x2d9208 vmul.f32 s14, s19, s14 */
/* @0x2d920c cmp r3, r2 */
/* @0x2d9210 vstr s14, [r3, #-4] */
/* @0x2d9214 beq 0x2d9240 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x19c> */
/* @0x2d9218 vldmia r3!, {s15} */
/* @0x2d921c vcmpe.f32 s15, s13 */
/* @0x2d9220 vmrs APSR_nzcv, fpscr */
/* @0x2d9224 bmi 0x2d91f4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x150> */
/* @0x2d9228 vmov.f32 s15, #4.000000e+00 */
/* @0x2d922c cmp r3, r2 */
/* @0x2d9230 vmov.f32 s14, s15 */
/* @0x2d9234 vmul.f32 s14, s19, s14 */
/* @0x2d9238 vstr s14, [r3, #-4] */
/* @0x2d923c bne 0x2d9218 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x174> */
/* @0x2d9240 vldr s15, [r4, #24] */
/* @0x2d9244 vldr s18, [r4, #12] */
/* @0x2d9248 vmul.f32 s18, s18, s15 */
/* @0x2d924c ldr r3, [r4, #0x80] */
/* @0x2d9250 vldr s15, [r5] */
/* @0x2d9254 cmp r3, #0 */
/* @0x2d9258 movgt r7, #0 */
/* @0x2d925c movgt r9, #0 */
/* @0x2d9260 movgt r8, r7 */
/* @0x2d9264 vdiv.f32 s18, s15, s18 */
/* @0x2d9268 ble 0x2d9368 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x2c4> */
/* @0x2d926c ldr r2, [r4, #0x88] */
/* @0x2d9270 mov r0, r4 */
/* @0x2d9274 ldr r12, [r4, #0x48] */
/* @0x2d9278 add r3, r2, r7 */
/* @0x2d927c vldr s14, [r3, #8] */
/* @0x2d9280 ldr r5, [r2, r7] */
/* @0x2d9284 vldr s13, [r3, #20] */
/* @0x2d9288 ldr r1, [r4, #0x38] */
/* @0x2d928c vldr s16, [r3, #12] */
/* @0x2d9290 vldr s17, [r3, #16] */
/* @0x2d9294 ldr r6, [r3, #0x4] */
/* @0x2d9298 add r2, r12, r5, lsl #2 */
/* @0x2d929c vldr s15, [r2] */
/* @0x2d92a0 ldr r2, [r4, #0x40] */
/* @0x2d92a4 lsl r5, r5, #3 */
/* @0x2d92a8 add r3, r1, r5 */
/* @0x2d92ac vldr s20, [r3] */
/* @0x2d92b0 add r5, r2, r5 */
/* @0x2d92b4 vldr s21, [r3, #4] */
/* @0x2d92b8 vmul.f32 s12, s18, s14 */
/* @0x2d92bc vmla.f32 s15, s19, s14 */
/* @0x2d92c0 vmul.f32 s14, s12, s13 */
/* @0x2d92c4 vmul.f32 s15, s14, s15 */
/* @0x2d92c8 vmul.f32 s16, s15, s16 */
/* @0x2d92cc vmul.f32 s17, s15, s17 */
/* @0x2d92d0 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv> */
/* @0x2d92d4 vldr s14, [r5] */
/* @0x2d92d8 vldr s15, [r5, #4] */
/* @0x2d92dc ldr r3, [r6] */
/* @0x2d92e0 cmp r3, #2 */
/* @0x2d92e4 vmov s13, r0 */
/* @0x2d92e8 vmls.f32 s14, s13, s16 */
/* @0x2d92ec vmls.f32 s15, s13, s17 */
/* @0x2d92f0 vstr s14, [r5] */
/* @0x2d92f4 vstr s15, [r5, #4] */
/* @0x2d92f8 bne 0x2d9354 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x2b0> */
/* @0x2d92fc vldr s15, [r6, #64] */
/* @0x2d9300 vsub.f32 s21, s21, s15 */
/* @0x2d9304 vldr s10, [r6, #60] */
/* @0x2d9308 vldr s14, [r6, #88] */
/* @0x2d930c vldr s12, [r6, #136] */
/* @0x2d9310 vldr s13, [r6, #80] */
/* @0x2d9314 vldr s15, [r6, #84] */
/* @0x2d9318 vldr s11, [r6, #144] */
/* @0x2d931c ldrh r3, [r6, #4] */
/* @0x2d9320 tst r3, #2 */
/* @0x2d9324 orr r3, r3, #2 */
/* @0x2d9328 streq r9, [r6, #0xa0] */
/* @0x2d932c strheq r3, [r6, #4] */
/* @0x2d9330 vmul.f32 s21, s16, s21 */
/* @0x2d9334 vsub.f32 s20, s20, s10 */
/* @0x2d9338 vnmls.f32 s21, s17, s20 */
/* @0x2d933c vmla.f32 s13, s16, s12 */
/* @0x2d9340 vmla.f32 s14, s21, s11 */
/* @0x2d9344 vstr s13, [r6, #80] */
/* @0x2d9348 vmla.f32 s15, s17, s12 */
/* @0x2d934c vstr s14, [r6, #88] */
/* @0x2d9350 vstr s15, [r6, #84] */
/* @0x2d9354 ldr r3, [r4, #0x80] */
/* @0x2d9358 add r8, r8, #1 */
/* @0x2d935c add r7, r7, #24 */
/* @0x2d9360 cmp r3, r8 */
/* @0x2d9364 bgt 0x2d926c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x1c8> */
/* @0x2d9368 ldr r6, [r4, #0x74] */
/* @0x2d936c cmp r6, #0 */
/* @0x2d9370 ble 0x2d9410 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x36c> */
/* @0x2d9374 ldr r3, [r4, #0x7c] */
/* @0x2d9378 add r6, r6, r6, lsl #1 */
/* @0x2d937c ldr r5, [r4, #0x48] */
/* @0x2d9380 ldr r12, [r4, #0x40] */
/* @0x2d9384 add r6, r3, r6, lsl #3 */
/* @0x2d9388 add r0, r3, #12 */
/* @0x2d938c ldr r1, [r0, #-0xc] */
/* @0x2d9390 mov r4, r0 */
/* @0x2d9394 ldr r2, [r0, #-0x8] */
/* @0x2d9398 vldr s10, [r4] */
/* @0x2d939c vmul.f32 s10, s18, s10 */
/* @0x2d93a0 vldr s14, [r3, #16] */
/* @0x2d93a4 add r4, r5, r1, lsl #2 */
/* @0x2d93a8 vldr s15, [r4] */
/* @0x2d93ac add r4, r5, r2, lsl #2 */
/* @0x2d93b0 vldr s9, [r4] */
/* @0x2d93b4 vldr s11, [r3, #20] */
/* @0x2d93b8 add r1, r12, r1, lsl #3 */
/* @0x2d93bc vldr s13, [r1] */
/* @0x2d93c0 vldr s12, [r1, #4] */
/* @0x2d93c4 add r2, r12, r2, lsl #3 */
/* @0x2d93c8 add r3, r3, #24 */
/* @0x2d93cc cmp r3, r6 */
/* @0x2d93d0 add r0, r0, #24 */
/* @0x2d93d4 vadd.f32 s15, s15, s9 */
/* @0x2d93d8 vmul.f32 s15, s10, s15 */
/* @0x2d93dc vmul.f32 s14, s15, s14 */
/* @0x2d93e0 vmul.f32 s15, s15, s11 */
/* @0x2d93e4 vsub.f32 s13, s13, s14 */
/* @0x2d93e8 vsub.f32 s12, s12, s15 */
/* @0x2d93ec vstr s13, [r1] */
/* @0x2d93f0 vldr s13, [r2] */
/* @0x2d93f4 vstr s12, [r1, #4] */
/* @0x2d93f8 vadd.f32 s14, s13, s14 */
/* @0x2d93fc vldr s13, [r2, #4] */
/* @0x2d9400 vadd.f32 s15, s13, s15 */
/* @0x2d9404 vstr s14, [r2] */
/* @0x2d9408 vstr s15, [r2, #4] */
/* @0x2d940c bne 0x2d938c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x2e8> */
/* @0x2d9410 vpop {d8, d9, d10} */
/* @0x2d9414 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d9418 andeq r0, r0, r0 */

/* ── FUNC 0x2d941c · anon_2d941c · size=1096 · insn=274 */
/* @0x2d941c ldrb r3, [r1, #0x2c] */
/* @0x2d9420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d9424 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d9428 cmp r3, #0 */
/* @0x2d942c sub sp, sp, #76 */
/* @0x2d9430 mov r9, r1 */
/* @0x2d9434 str r0, [sp, #0x20] */
/* @0x2d9438 bne 0x2d968c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5e8> */
/* @0x2d943c ldr r2, [r1, #0x8] */
/* @0x2d9440 vldr s15, [r2, #48] */
/* @0x2d9444 vmul.f32 s15, s15, s15 */
/* @0x2d9448 vldr s13, [r2, #44] */
/* @0x2d944c vldr s14, [r2, #132] */
/* @0x2d9450 vldr s12, [r2, #140] */
/* @0x2d9454 ldr r0, [r1, #0xc] */
/* @0x2d9458 vldr s23, [r2, #60] */
/* @0x2d945c str r2, [sp, #0x1c] */
/* @0x2d9460 vldr s24, [r2, #64] */
/* @0x2d9464 ldr r3, [r0] */
/* @0x2d9468 ldr r3, [r3, #0xc] */
/* @0x2d946c vmla.f32 s15, s13, s13 */
/* @0x2d9470 vmul.f32 s15, s14, s15 */
/* @0x2d9474 vadd.f32 s13, s15, s12 */
/* @0x2d9478 vcmpe.f32 s14, #0 */
/* @0x2d947c vsub.f32 s15, s13, s15 */
/* @0x2d9480 vmrs APSR_nzcv, fpscr */
/* @0x2d9484 vldrle s25, [pc, #968] */
/* @0x2d9488 vmovgt.f32 s25, #1.000000e+00 */
/* @0x2d948c vcmpe.f32 s15, #0 */
/* @0x2d9490 vdivgt.f32 s25, s25, s14 */
/* @0x2d9494 vmrs APSR_nzcv, fpscr */
/* @0x2d9498 vldrle s26, [pc, #948] */
/* @0x2d949c vmovgt.f32 s26, #1.000000e+00 */
/* @0x2d94a0 vdivgt.f32 s26, s26, s15 */
/* @0x2d94a4 blx r3 */
/* @0x2d94a8 cmp r0, #0 */
/* @0x2d94ac str r0, [sp, #0x18] */
/* @0x2d94b0 ble 0x2d968c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5e8> */
/* @0x2d94b4 ldr r3, [sp, #0x20] */
/* @0x2d94b8 mov r11, #0 */
/* @0x2d94bc add r6, sp, #56 */
/* @0x2d94c0 mov r10, r11 */
/* @0x2d94c4 add r2, sp, #52 */
/* @0x2d94c8 vldr s22, [pc, #904] */
/* @0x2d94cc ldr r8, [r3, #0x4] */
/* @0x2d94d0 mov r3, r9 */
/* @0x2d94d4 mov r9, r11 */
/* @0x2d94d8 mov r11, r3 */
/* @0x2d94dc str r2, [sp, #0x24] */
/* @0x2d94e0 vldr s21, [pc, #884] */
/* @0x2d94e4 vldr s20, [pc, #884] */
/* @0x2d94e8 ldr r3, [r11, #0x18] */
/* @0x2d94ec vldr s14, [r8, #24] */
/* @0x2d94f0 vldr s15, [r8, #28] */
/* @0x2d94f4 vmov.f32 s12, s21 */
/* @0x2d94f8 add r3, r3, r9 */
/* @0x2d94fc vldr s16, [r3] */
/* @0x2d9500 vldr s18, [r3, #4] */
/* @0x2d9504 vldr s17, [r3, #8] */
/* @0x2d9508 vldr s19, [r3, #12] */
/* @0x2d950c ldr r12, [r8, #0x68] */
/* @0x2d9510 vsub.f32 s16, s16, s14 */
/* @0x2d9514 ldr r4, [r8, #0x70] */
/* @0x2d9518 sbfx r0, r12, #0x0, #0x1d */
/* @0x2d951c add r12, r4, r12, lsl #3 */
/* @0x2d9520 vmul.f32 s13, s16, s15 */
/* @0x2d9524 vsub.f32 s18, s18, s14 */
/* @0x2d9528 vmla.f32 s12, s13, s22 */
/* @0x2d952c vmov.f32 s13, s20 */
/* @0x2d9530 vmla.f32 s13, s18, s15 */
/* @0x2d9534 vcvt.u32.f32 s12, s12 */
/* @0x2d9538 vcvt.u32.f32 s13, s13 */
/* @0x2d953c vmov r3, s12 */
/* @0x2d9540 vmov r5, s13 */
/* @0x2d9544 vadd.f32 s17, s14, s17 */
/* @0x2d9548 vadd.f32 s19, s14, s19 */
/* @0x2d954c add r5, r3, r5, lsl #20 */
/* @0x2d9550 cmp r0, #0 */
/* @0x2d9554 ble 0x2d9590 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4ec> */
/* @0x2d9558 asr r3, r0, #1 */
/* @0x2d955c add r1, r4, r3, lsl #3 */
/* @0x2d9560 ldr r2, [r1, #0x4] */
/* @0x2d9564 cmp r5, r2 */
/* @0x2d9568 bls 0x2d9580 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4dc> */
/* @0x2d956c b 0x2d969c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5f8> */
/* @0x2d9570 ldr r0, [r1, #0x4] */
/* @0x2d9574 cmp r5, r0 */
/* @0x2d9578 bhi 0x2d96a4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x600> */
/* @0x2d957c mov r3, r2 */
/* @0x2d9580 asr r2, r3, #1 */
/* @0x2d9584 cmp r3, #0 */
/* @0x2d9588 add r1, r4, r2, lsl #3 */
/* @0x2d958c bne 0x2d9570 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4cc> */
/* @0x2d9590 vmul.f32 s14, s17, s15 */
/* @0x2d9594 rsb r0, r4, r12 */
/* @0x2d9598 mov r5, r4 */
/* @0x2d959c asr r0, r0, #3 */
/* @0x2d95a0 vmov.f32 s10, s21 */
/* @0x2d95a4 vmov.f32 s13, s20 */
/* @0x2d95a8 vmla.f32 s10, s14, s22 */
/* @0x2d95ac vmla.f32 s13, s19, s15 */
/* @0x2d95b0 vcvt.u32.f32 s14, s10 */
/* @0x2d95b4 vcvt.u32.f32 s15, s13 */
/* @0x2d95b8 vmov r2, s14 */
/* @0x2d95bc vmov r12, s15 */
/* @0x2d95c0 add r12, r2, r12, lsl #20 */
/* @0x2d95c4 cmp r0, #0 */
/* @0x2d95c8 ble 0x2d9604 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x560> */
/* @0x2d95cc asr r3, r0, #1 */
/* @0x2d95d0 add r1, r4, r3, lsl #3 */
/* @0x2d95d4 ldr r2, [r1, #0x4] */
/* @0x2d95d8 cmp r12, r2 */
/* @0x2d95dc blo 0x2d95f4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x550> */
/* @0x2d95e0 b 0x2d96b4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x610> */
/* @0x2d95e4 ldr r0, [r1, #0x4] */
/* @0x2d95e8 cmp r12, r0 */
/* @0x2d95ec bhs 0x2d96bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x618> */
/* @0x2d95f0 mov r3, r2 */
/* @0x2d95f4 asr r2, r3, #1 */
/* @0x2d95f8 cmp r3, #0 */
/* @0x2d95fc add r1, r4, r2, lsl #3 */
/* @0x2d9600 bne 0x2d95e4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x540> */
/* @0x2d9604 cmp r4, r5 */
/* @0x2d9608 addne r2, sp, #64 */
/* @0x2d960c addne r5, r5, #8 */
/* @0x2d9610 vmovne.f32 s27, #1.000000e+00 */
/* @0x2d9614 strne r2, [sp, #0x14] */
/* @0x2d9618 bne 0x2d9624 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x580> */
/* @0x2d961c b 0x2d9678 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5d4> */
/* @0x2d9620 add r5, r5, #8 */
/* @0x2d9624 ldr r7, [r5, #-0x8] */
/* @0x2d9628 ldr r3, [r8, #0x38] */
/* @0x2d962c add r3, r3, r7, lsl #3 */
/* @0x2d9630 ldm r3, {r0, r1} */
/* @0x2d9634 stm r6, {r0, r1} */
/* @0x2d9638 vldr s15, [sp, #56] */
/* @0x2d963c vcmpe.f32 s16, s15 */
/* @0x2d9640 vmrs APSR_nzcv, fpscr */
/* @0x2d9644 bhi 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc> */
/* @0x2d9648 vcmpe.f32 s17, s15 */
/* @0x2d964c vmrs APSR_nzcv, fpscr */
/* @0x2d9650 blt 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc> */
/* @0x2d9654 vldr s15, [sp, #60] */
/* @0x2d9658 vcmpe.f32 s18, s15 */
/* @0x2d965c vmrs APSR_nzcv, fpscr */
/* @0x2d9660 bhi 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc> */
/* @0x2d9664 vcmpe.f32 s19, s15 */
/* @0x2d9668 vmrs APSR_nzcv, fpscr */
/* @0x2d966c bge 0x2d96cc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x628> */
/* @0x2d9670 cmp r5, r4 */
/* @0x2d9674 bne 0x2d9620 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x57c> */
/* @0x2d9678 ldr r3, [sp, #0x18] */
/* @0x2d967c add r10, r10, #1 */
/* @0x2d9680 add r9, r9, #28 */
/* @0x2d9684 cmp r10, r3 */
/* @0x2d9688 bne 0x2d94e8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x444> */
/* @0x2d968c mov r0, #1 */
/* @0x2d9690 add sp, sp, #76 */
/* @0x2d9694 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2d9698 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d969c mov r2, r3 */
/* @0x2d96a0 mov r3, r0 */
/* @0x2d96a4 rsb r3, r2, r3 */
/* @0x2d96a8 add r4, r1, #8 */
/* @0x2d96ac sub r0, r3, #1 */
/* @0x2d96b0 b 0x2d9550 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4ac> */
/* @0x2d96b4 mov r2, r3 */
/* @0x2d96b8 mov r3, r0 */
/* @0x2d96bc rsb r3, r2, r3 */
/* @0x2d96c0 add r4, r1, #8 */
/* @0x2d96c4 sub r0, r3, #1 */
/* @0x2d96c8 b 0x2d95c4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x520> */
/* @0x2d96cc ldr r0, [r11, #0xc] */
/* @0x2d96d0 mov r2, r6 */
/* @0x2d96d4 ldr r1, [r11, #0x8] */
/* @0x2d96d8 add lr, sp, #64 */
/* @0x2d96dc add r3, sp, #52 */
/* @0x2d96e0 ldr r12, [r0] */
/* @0x2d96e4 add r1, r1, #12 */
/* @0x2d96e8 str lr, [sp] */
/* @0x2d96ec str r10, [sp, #0x4] */
/* @0x2d96f0 ldr r12, [r12, #0x14] */
/* @0x2d96f4 blx r12 */
/* @0x2d96f8 ldr r2, [sp, #0x20] */
/* @0x2d96fc vldr s15, [sp, #52] */
/* @0x2d9700 ldr r8, [r2, #0x4] */
/* @0x2d9704 vldr s14, [r8, #24] */
/* @0x2d9708 vcmpe.f32 s14, s15 */
/* @0x2d970c vmrs APSR_nzcv, fpscr */
/* @0x2d9710 ble 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc> */
/* @0x2d9714 ldr r3, [r8, #0x30] */
/* @0x2d9718 ldr r3, [r3, r7, lsl #2] */
/* @0x2d971c tst r3, #4 */
/* @0x2d9720 beq 0x2d983c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x798> */
/* @0x2d9724 vldr s29, [pc, #296] */
/* @0x2d9728 vldr s28, [sp, #60] */
/* @0x2d972c vsub.f32 s28, s28, s24 */
/* @0x2d9730 vldr s14, [sp, #64] */
/* @0x2d9734 vldr s15, [sp, #56] */
/* @0x2d9738 ldr r3, [r8, #0x80] */
/* @0x2d973c vldr s13, [sp, #68] */
/* @0x2d9740 ldr r2, [r8, #0x84] */
/* @0x2d9744 cmp r3, r2 */
/* @0x2d9748 vmul.f32 s28, s28, s14 */
/* @0x2d974c vsub.f32 s15, s15, s23 */
/* @0x2d9750 vnmls.f32 s28, s15, s13 */
/* @0x2d9754 blt 0x2d97e0 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x73c> */
/* @0x2d9758 cmp r3, #0 */
/* @0x2d975c ldr r0, [r8, #0xd4] */
/* @0x2d9760 lslne r12, r3, #1 */
/* @0x2d9764 addne r3, r12, r3, lsl #2 */
/* @0x2d9768 moveq r1, #6144 */
/* @0x2d976c moveq r12, #256 */
/* @0x2d9770 lslne r1, r3, #3 */
/* @0x2d9774 ldr r3, [r8, #0x88] */
/* @0x2d9778 str r12, [sp, #0xc] */
/* @0x2d977c str r2, [sp, #0x10] */
/* @0x2d9780 str r3, [sp, #0x28] */
/* @0x2d9784 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d9788 ldr r2, [sp, #0x10] */
/* @0x2d978c ldr r1, [sp, #0x28] */
/* @0x2d9790 add r2, r2, r2, lsl #1 */
/* @0x2d9794 lsl r3, r2, #3 */
/* @0x2d9798 str r3, [sp, #0x10] */
/* @0x2d979c mov r2, r3 */
/* @0x2d97a0 str r0, [sp, #0x2c] */
/* @0x2d97a4 bl 0xb65bc <memcpy@plt> */
/* @0x2d97a8 ldr r3, [sp, #0x10] */
/* @0x2d97ac ldr r0, [r8, #0xd4] */
/* @0x2d97b0 ldr r1, [sp, #0x28] */
/* @0x2d97b4 mov r2, r3 */
/* @0x2d97b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d97bc ldr r3, [sp, #0x2c] */
/* @0x2d97c0 ldr r2, [sp, #0x20] */
/* @0x2d97c4 vldr s14, [sp, #64] */
/* @0x2d97c8 ldr r12, [sp, #0xc] */
/* @0x2d97cc vldr s13, [sp, #68] */
/* @0x2d97d0 str r3, [r8, #0x88] */
/* @0x2d97d4 ldr r8, [r2, #0x4] */
/* @0x2d97d8 ldr r3, [r8, #0x80] */
/* @0x2d97dc str r12, [r8, #0x84] */
/* @0x2d97e0 vmul.f32 s10, s28, s26 */
/* @0x2d97e4 vldr s11, [r8, #28] */
/* @0x2d97e8 vldr s12, [sp, #52] */
/* @0x2d97ec ldr r2, [r8, #0x88] */
/* @0x2d97f0 add r1, r3, r3, lsl #1 */
/* @0x2d97f4 add r0, r3, #1 */
/* @0x2d97f8 str r7, [r2, r1, lsl #3] */
/* @0x2d97fc add r3, r2, r1, lsl #3 */
/* @0x2d9800 ldr r2, [sp, #0x1c] */
/* @0x2d9804 str r2, [r3, #0x4] */
/* @0x2d9808 vadd.f32 s15, s25, s29 */
/* @0x2d980c vmla.f32 s15, s28, s10 */
/* @0x2d9810 vdiv.f32 s15, s27, s15 */
/* @0x2d9814 vmov.f32 s10, s27 */
/* @0x2d9818 vstr s15, [r3, #20] */
/* @0x2d981c vmls.f32 s10, s11, s12 */
/* @0x2d9820 vneg.f32 s14, s14 */
/* @0x2d9824 vstr s10, [r3, #8] */
/* @0x2d9828 vneg.f32 s15, s13 */
/* @0x2d982c vstr s14, [r3, #12] */
/* @0x2d9830 vstr s15, [r3, #16] */
/* @0x2d9834 str r0, [r8, #0x80] */
/* @0x2d9838 b 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc> */
/* @0x2d983c mov r0, r8 */
/* @0x2d9840 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv> */
/* @0x2d9844 ldr r3, [sp, #0x20] */
/* @0x2d9848 ldr r8, [r3, #0x4] */
/* @0x2d984c vmov s29, r0 */
/* @0x2d9850 b 0x2d9728 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x684> */
/* @0x2d9854 andeq r0, r0, r0 */
/* @0x2d9858 orrmi r0, r0, #0 */
/* @0x2d985c .word 0x49000000 */
/* @0x2d9860 strmi r0, [r0, #-0x0] */

/* ── FUNC 0x2d9864 · b2ParticleSystem::GetParticleFlagsBuffer() · size=8 · insn=2 */
/* @0x2d9864 ldr r0, [r0, #0x30] */
/* @0x2d9868 bx lr */

/* ── FUNC 0x2d986c · b2ParticleSystem::GetParticlePositionBuffer() · size=8 · insn=2 */
/* @0x2d986c ldr r0, [r0, #0x38] */
/* @0x2d9870 bx lr */

/* ── FUNC 0x2d9874 · b2ParticleSystem::GetParticleVelocityBuffer() · size=8 · insn=2 */
/* @0x2d9874 ldr r0, [r0, #0x40] */
/* @0x2d9878 bx lr */

/* ── FUNC 0x2d987c · b2ParticleSystem::GetParticleColorBuffer() · size=48 · insn=12 */
/* @0x2d987c push {r4, lr} */
/* @0x2d9880 mov r4, r0 */
/* @0x2d9884 ldr r0, [r0, #0x54] */
/* @0x2d9888 cmp r0, #0 */
/* @0x2d988c beq 0x2d9898 <_ZN16b2ParticleSystem22GetParticleColorBufferEv+0x1c> */
/* @0x2d9890 str r0, [r4, #0x54] */
/* @0x2d9894 pop {r4, pc} */
/* @0x2d9898 add r0, r4, #40 */
/* @0x2d989c add r1, r4, #212 */
/* @0x2d98a0 bl 0x2d4a30 <_ZN15b2QueryCallbackD0Ev+0xa0> */
/* @0x2d98a4 str r0, [r4, #0x54] */
/* @0x2d98a8 pop {r4, pc} */

/* ── FUNC 0x2d98ac · b2ParticleSystem::GetParticleUserDataBuffer() · size=72 · insn=18 */
/* @0x2d98ac push {r3, r4, r5, lr} */
/* @0x2d98b0 mov r5, r0 */
/* @0x2d98b4 ldr r4, [r0, #0x60] */
/* @0x2d98b8 cmp r4, #0 */
/* @0x2d98bc beq 0x2d98cc <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv+0x20> */
/* @0x2d98c0 str r4, [r5, #0x60] */
/* @0x2d98c4 mov r0, r4 */
/* @0x2d98c8 pop {r3, r4, r5, pc} */
/* @0x2d98cc ldr r1, [r0, #0x28] */
/* @0x2d98d0 ldr r0, [r0, #0xd4] */
/* @0x2d98d4 lsl r1, r1, #2 */
/* @0x2d98d8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d98dc ldr r2, [r5, #0x28] */
/* @0x2d98e0 mov r1, #0 */
/* @0x2d98e4 lsl r2, r2, #2 */
/* @0x2d98e8 mov r4, r0 */
/* @0x2d98ec bl 0xb65b0 <memset@plt> */
/* @0x2d98f0 b 0x2d98c0 <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv+0x14> */

/* ── FUNC 0x2d98f4 · b2ParticleSystem::GetParticleMaxCount() const · size=8 · insn=2 */
/* @0x2d98f4 ldr r0, [r0, #0x2c] */
/* @0x2d98f8 bx lr */

/* ── FUNC 0x2d98fc · b2ParticleSystem::SetParticleMaxCount(int) · size=8 · insn=2 */
/* @0x2d98fc str r1, [r0, #0x2c] */
/* @0x2d9900 bx lr */

/* ── FUNC 0x2d9904 · b2ParticleSystem::GetParticleFlagsBuffer() const · size=8 · insn=2 */
/* @0x2d9904 ldr r0, [r0, #0x30] */
/* @0x2d9908 bx lr */

/* ── FUNC 0x2d990c · b2ParticleSystem::GetParticlePositionBuffer() const · size=8 · insn=2 */
/* @0x2d990c ldr r0, [r0, #0x38] */
/* @0x2d9910 bx lr */

/* ── FUNC 0x2d9914 · b2ParticleSystem::GetParticleVelocityBuffer() const · size=8 · insn=2 */
/* @0x2d9914 ldr r0, [r0, #0x40] */
/* @0x2d9918 bx lr */

/* ── FUNC 0x2d991c · b2ParticleSystem::GetParticleColorBuffer() const · size=4 · insn=1 */
/* @0x2d991c b 0x2d987c <_ZN16b2ParticleSystem22GetParticleColorBufferEv> */

/* ── FUNC 0x2d9920 · b2ParticleSystem::GetParticleGroupBuffer() const · size=8 · insn=2 */
/* @0x2d9920 ldr r0, [r0, #0x5c] */
/* @0x2d9924 bx lr */

/* ── FUNC 0x2d9928 · b2ParticleSystem::GetParticleUserDataBuffer() const · size=4 · insn=1 */
/* @0x2d9928 b 0x2d98ac <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv> */

/* ── FUNC 0x2d992c · b2ParticleSystem::SetParticleFlagsBuffer(unsigned int*, int) · size=60 · insn=15 */
/* @0x2d992c ldr r3, [r0, #0x34] */
/* @0x2d9930 push {r4, r5, r6, lr} */
/* @0x2d9934 cmp r3, #0 */
/* @0x2d9938 mov r4, r0 */
/* @0x2d993c mov r6, r1 */
/* @0x2d9940 mov r5, r2 */
/* @0x2d9944 bne 0x2d995c <_ZN16b2ParticleSystem22SetParticleFlagsBufferEPji+0x30> */
/* @0x2d9948 ldr r2, [r0, #0x28] */
/* @0x2d994c ldr r1, [r4, #0x30] */
/* @0x2d9950 ldr r0, [r0, #0xd4] */
/* @0x2d9954 lsl r2, r2, #2 */
/* @0x2d9958 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d995c str r6, [r4, #0x30] */
/* @0x2d9960 str r5, [r4, #0x34] */
/* @0x2d9964 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2d9968 · b2ParticleSystem::SetParticlePositionBuffer(b2Vec2*, int) · size=60 · insn=15 */
/* @0x2d9968 ldr r3, [r0, #0x3c] */
/* @0x2d996c push {r4, r5, r6, lr} */
/* @0x2d9970 cmp r3, #0 */
/* @0x2d9974 mov r4, r0 */
/* @0x2d9978 mov r6, r1 */
/* @0x2d997c mov r5, r2 */
/* @0x2d9980 bne 0x2d9998 <_ZN16b2ParticleSystem25SetParticlePositionBufferEP6b2Vec2i+0x30> */
/* @0x2d9984 ldr r2, [r0, #0x28] */
/* @0x2d9988 ldr r1, [r4, #0x38] */
/* @0x2d998c ldr r0, [r0, #0xd4] */
/* @0x2d9990 lsl r2, r2, #3 */
/* @0x2d9994 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d9998 str r6, [r4, #0x38] */
/* @0x2d999c str r5, [r4, #0x3c] */
/* @0x2d99a0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2d99a4 · b2ParticleSystem::SetParticleVelocityBuffer(b2Vec2*, int) · size=60 · insn=15 */
/* @0x2d99a4 ldr r3, [r0, #0x44] */
/* @0x2d99a8 push {r4, r5, r6, lr} */
/* @0x2d99ac cmp r3, #0 */
/* @0x2d99b0 mov r4, r0 */
/* @0x2d99b4 mov r6, r1 */
/* @0x2d99b8 mov r5, r2 */
/* @0x2d99bc bne 0x2d99d4 <_ZN16b2ParticleSystem25SetParticleVelocityBufferEP6b2Vec2i+0x30> */
/* @0x2d99c0 ldr r2, [r0, #0x28] */
/* @0x2d99c4 ldr r1, [r4, #0x40] */
/* @0x2d99c8 ldr r0, [r0, #0xd4] */
/* @0x2d99cc lsl r2, r2, #3 */
/* @0x2d99d0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d99d4 str r6, [r4, #0x40] */
/* @0x2d99d8 str r5, [r4, #0x44] */
/* @0x2d99dc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2d99e0 · b2ParticleSystem::SetParticleColorBuffer(b2ParticleColor*, int) · size=60 · insn=15 */
/* @0x2d99e0 ldr r3, [r0, #0x58] */
/* @0x2d99e4 push {r4, r5, r6, lr} */
/* @0x2d99e8 cmp r3, #0 */
/* @0x2d99ec mov r4, r0 */
/* @0x2d99f0 mov r6, r1 */
/* @0x2d99f4 mov r5, r2 */
/* @0x2d99f8 bne 0x2d9a10 <_ZN16b2ParticleSystem22SetParticleColorBufferEP15b2ParticleColori+0x30> */
/* @0x2d99fc ldr r2, [r0, #0x28] */
/* @0x2d9a00 ldr r1, [r4, #0x54] */
/* @0x2d9a04 ldr r0, [r0, #0xd4] */
/* @0x2d9a08 lsl r2, r2, #2 */
/* @0x2d9a0c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d9a10 str r6, [r4, #0x54] */
/* @0x2d9a14 str r5, [r4, #0x58] */
/* @0x2d9a18 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2d9a1c · b2ParticleSystem::GetParticleGroupBuffer() · size=8 · insn=2 */
/* @0x2d9a1c ldr r0, [r0, #0x5c] */
/* @0x2d9a20 bx lr */

/* ── FUNC 0x2d9a24 · b2ParticleSystem::SetParticleUserDataBuffer(void**, int) · size=60 · insn=15 */
/* @0x2d9a24 ldr r3, [r0, #0x64] */
/* @0x2d9a28 push {r4, r5, r6, lr} */
/* @0x2d9a2c cmp r3, #0 */
/* @0x2d9a30 mov r4, r0 */
/* @0x2d9a34 mov r6, r1 */
/* @0x2d9a38 mov r5, r2 */
/* @0x2d9a3c bne 0x2d9a54 <_ZN16b2ParticleSystem25SetParticleUserDataBufferEPPvi+0x30> */
/* @0x2d9a40 ldr r2, [r0, #0x28] */
/* @0x2d9a44 ldr r1, [r4, #0x60] */
/* @0x2d9a48 ldr r0, [r0, #0xd4] */
/* @0x2d9a4c lsl r2, r2, #2 */
/* @0x2d9a50 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2d9a54 str r6, [r4, #0x60] */
/* @0x2d9a58 str r5, [r4, #0x64] */
/* @0x2d9a5c pop {r4, r5, r6, pc} */

/* ── FUNC 0x2d9a60 · b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const · size=492 · insn=123 */
/* @0x2d9a60 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2d9a64 mov r7, r0 */
/* @0x2d9a68 ldr r3, [r0, #0x68] */
/* @0x2d9a6c mov r8, r1 */
/* @0x2d9a70 mov r9, r2 */
/* @0x2d9a74 cmp r3, #0 */
/* @0x2d9a78 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d9a7c vldr s15, [r0, #28] */
/* @0x2d9a80 vldr s14, [r2] */
/* @0x2d9a84 vmul.f32 s10, s15, s14 */
/* @0x2d9a88 vldr s9, [r2, #4] */
/* @0x2d9a8c vldr s12, [pc, #428] */
/* @0x2d9a90 vldr s11, [pc, #428] */
/* @0x2d9a94 vldr s13, [pc, #428] */
/* @0x2d9a98 ldr r5, [r0, #0x70] */
/* @0x2d9a9c sbfx r1, r3, #0x0, #0x1d */
/* @0x2d9aa0 add r6, r5, r3, lsl #3 */
/* @0x2d9aa4 vmla.f32 s12, s15, s9 */
/* @0x2d9aa8 vmla.f32 s13, s10, s11 */
/* @0x2d9aac vcvt.u32.f32 s12, s12 */
/* @0x2d9ab0 vcvt.u32.f32 s13, s13 */
/* @0x2d9ab4 vmov r0, s12 */
/* @0x2d9ab8 vmov r3, s13 */
/* @0x2d9abc add r0, r3, r0, lsl #20 */
/* @0x2d9ac0 cmp r1, #0 */
/* @0x2d9ac4 ble 0x2d9b00 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0xa0> */
/* @0x2d9ac8 asr r3, r1, #1 */
/* @0x2d9acc add r2, r5, r3, lsl #3 */
/* @0x2d9ad0 ldr r12, [r2, #0x4] */
/* @0x2d9ad4 cmp r0, r12 */
/* @0x2d9ad8 bls 0x2d9af0 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x90> */
/* @0x2d9adc b 0x2d9bf4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x194> */
/* @0x2d9ae0 ldr r1, [r2, #0x4] */
/* @0x2d9ae4 cmp r0, r1 */
/* @0x2d9ae8 bhi 0x2d9bfc <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x19c> */
/* @0x2d9aec mov r3, r12 */
/* @0x2d9af0 asr r12, r3, #1 */
/* @0x2d9af4 cmp r3, #0 */
/* @0x2d9af8 add r2, r5, r12, lsl #3 */
/* @0x2d9afc bne 0x2d9ae0 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x80> */
/* @0x2d9b00 vldr s9, [r9, #8] */
/* @0x2d9b04 vmul.f32 s9, s15, s9 */
/* @0x2d9b08 vldr s10, [pc, #308] */
/* @0x2d9b0c vldr s12, [pc, #308] */
/* @0x2d9b10 vldr s11, [r9, #12] */
/* @0x2d9b14 vldr s13, [pc, #292] */
/* @0x2d9b18 rsb r2, r5, r6 */
/* @0x2d9b1c mov r4, r5 */
/* @0x2d9b20 asr r2, r2, #3 */
/* @0x2d9b24 vmla.f32 s12, s9, s10 */
/* @0x2d9b28 vmla.f32 s13, s15, s11 */
/* @0x2d9b2c vcvt.u32.f32 s12, s12 */
/* @0x2d9b30 vcvt.u32.f32 s13, s13 */
/* @0x2d9b34 vmov r3, s12 */
/* @0x2d9b38 vmov r1, s13 */
/* @0x2d9b3c add r1, r3, r1, lsl #20 */
/* @0x2d9b40 cmp r2, #0 */
/* @0x2d9b44 ble 0x2d9b80 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x120> */
/* @0x2d9b48 asr r3, r2, #1 */
/* @0x2d9b4c add r6, r5, r3, lsl #3 */
/* @0x2d9b50 ldr r0, [r6, #0x4] */
/* @0x2d9b54 cmp r1, r0 */
/* @0x2d9b58 blo 0x2d9b70 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x110> */
/* @0x2d9b5c b 0x2d9c0c <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x1ac> */
/* @0x2d9b60 ldr r2, [r6, #0x4] */
/* @0x2d9b64 cmp r1, r2 */
/* @0x2d9b68 bhs 0x2d9c14 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x1b4> */
/* @0x2d9b6c mov r3, r12 */
/* @0x2d9b70 asr r12, r3, #1 */
/* @0x2d9b74 cmp r3, #0 */
/* @0x2d9b78 add r6, r5, r12, lsl #3 */
/* @0x2d9b7c bne 0x2d9b60 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x100> */
/* @0x2d9b80 cmp r4, r5 */
/* @0x2d9b84 pophs {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d9b88 add r4, r4, #8 */
/* @0x2d9b8c b 0x2d9b94 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x134> */
/* @0x2d9b90 vldr s14, [r9] */
/* @0x2d9b94 ldr r1, [r4, #-0x8] */
/* @0x2d9b98 ldr r3, [r7, #0x38] */
/* @0x2d9b9c add r3, r3, r1, lsl #3 */
/* @0x2d9ba0 vldr s15, [r3] */
/* @0x2d9ba4 vcmpe.f32 s15, s14 */
/* @0x2d9ba8 vmrs APSR_nzcv, fpscr */
/* @0x2d9bac ble 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184> */
/* @0x2d9bb0 vldr s14, [r9, #8] */
/* @0x2d9bb4 vcmpe.f32 s15, s14 */
/* @0x2d9bb8 vmrs APSR_nzcv, fpscr */
/* @0x2d9bbc bpl 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184> */
/* @0x2d9bc0 vldr s15, [r3, #4] */
/* @0x2d9bc4 vldr s14, [r9, #4] */
/* @0x2d9bc8 vcmpe.f32 s14, s15 */
/* @0x2d9bcc vmrs APSR_nzcv, fpscr */
/* @0x2d9bd0 bpl 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184> */
/* @0x2d9bd4 vldr s14, [r9, #12] */
/* @0x2d9bd8 vcmpe.f32 s15, s14 */
/* @0x2d9bdc vmrs APSR_nzcv, fpscr */
/* @0x2d9be0 bmi 0x2d9c24 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x1c4> */
/* @0x2d9be4 cmp r4, r5 */
/* @0x2d9be8 add r4, r4, #8 */
/* @0x2d9bec blo 0x2d9b90 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x130> */
/* @0x2d9bf0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d9bf4 mov r12, r3 */
/* @0x2d9bf8 mov r3, r1 */
/* @0x2d9bfc rsb r3, r12, r3 */
/* @0x2d9c00 add r5, r2, #8 */
/* @0x2d9c04 sub r1, r3, #1 */
/* @0x2d9c08 b 0x2d9ac0 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x60> */
/* @0x2d9c0c mov r12, r3 */
/* @0x2d9c10 mov r3, r2 */
/* @0x2d9c14 rsb r3, r12, r3 */
/* @0x2d9c18 add r5, r6, #8 */
/* @0x2d9c1c sub r2, r3, #1 */
/* @0x2d9c20 b 0x2d9b40 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0xe0> */
/* @0x2d9c24 ldr r3, [r8] */
/* @0x2d9c28 mov r0, r8 */
/* @0x2d9c2c ldr r3, [r3, #0xc] */
/* @0x2d9c30 blx r3 */
/* @0x2d9c34 cmp r0, #0 */
/* @0x2d9c38 bne 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184> */
/* @0x2d9c3c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2d9c40 strmi r0, [r0, #-0x0] */
/* @0x2d9c44 orrmi r0, r0, #0 */
/* @0x2d9c48 .word 0x49000000 */

/* ── FUNC 0x2d9c4c · b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const · size=924 · insn=231 */
/* @0x2d9c4c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2d9c50 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2d9c54 mov r8, r1 */
/* @0x2d9c58 ldr r1, [r0, #0x68] */
/* @0x2d9c5c sub sp, sp, #32 */
/* @0x2d9c60 mov r7, r0 */
/* @0x2d9c64 mov r6, r2 */
/* @0x2d9c68 cmp r1, #0 */
/* @0x2d9c6c beq 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320> */
/* @0x2d9c70 vmov.f32 s13, #1.000000e+00 */
/* @0x2d9c74 vldr s17, [r2] */
/* @0x2d9c78 vldr s21, [r3] */
/* @0x2d9c7c vldr s15, [r0, #28] */
/* @0x2d9c80 vldr s18, [r2, #4] */
/* @0x2d9c84 vldr s22, [r3, #4] */
/* @0x2d9c88 vldr s11, [pc, #840] */
/* @0x2d9c8c vldr s14, [pc, #840] */
/* @0x2d9c90 vldr s12, [pc, #840] */
/* @0x2d9c94 ldr r5, [r0, #0x70] */
/* @0x2d9c98 sbfx r4, r1, #0x0, #0x1d */
/* @0x2d9c9c add r9, r5, r1, lsl #3 */
/* @0x2d9ca0 vcmpe.f32 s17, s21 */
/* @0x2d9ca4 vmov.f32 s9, s13 */
/* @0x2d9ca8 vmrs APSR_nzcv, fpscr */
/* @0x2d9cac vmovpl.f32 s10, s21 */
/* @0x2d9cb0 vmovmi.f32 s10, s17 */
/* @0x2d9cb4 vnmls.f32 s9, s15, s10 */
/* @0x2d9cb8 vcmpe.f32 s18, s22 */
/* @0x2d9cbc vmov.f32 s10, s9 */
/* @0x2d9cc0 vmrs APSR_nzcv, fpscr */
/* @0x2d9cc4 vmovpl.f32 s9, s22 */
/* @0x2d9cc8 vmovmi.f32 s9, s18 */
/* @0x2d9ccc vnmls.f32 s13, s15, s9 */
/* @0x2d9cd0 vmla.f32 s14, s10, s11 */
/* @0x2d9cd4 vadd.f32 s13, s13, s12 */
/* @0x2d9cd8 vcvt.u32.f32 s14, s14 */
/* @0x2d9cdc vcvt.u32.f32 s13, s13 */
/* @0x2d9ce0 vmov r3, s14 */
/* @0x2d9ce4 vmov r2, s13 */
/* @0x2d9ce8 add r0, r3, r2, lsl #20 */
/* @0x2d9cec cmp r4, #0 */
/* @0x2d9cf0 ble 0x2d9d2c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xe0> */
/* @0x2d9cf4 asr r3, r4, #1 */
/* @0x2d9cf8 add r2, r5, r3, lsl #3 */
/* @0x2d9cfc ldr r12, [r2, #0x4] */
/* @0x2d9d00 cmp r0, r12 */
/* @0x2d9d04 bls 0x2d9d1c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xd0> */
/* @0x2d9d08 b 0x2d9f90 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x344> */
/* @0x2d9d0c ldr r1, [r2, #0x4] */
/* @0x2d9d10 cmp r0, r1 */
/* @0x2d9d14 bhi 0x2d9f98 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x34c> */
/* @0x2d9d18 mov r3, r12 */
/* @0x2d9d1c asr r12, r3, #1 */
/* @0x2d9d20 cmp r3, #0 */
/* @0x2d9d24 add r2, r5, r12, lsl #3 */
/* @0x2d9d28 bne 0x2d9d0c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xc0> */
/* @0x2d9d2c vmov.f32 s13, #1.000000e+00 */
/* @0x2d9d30 vldr s11, [pc, #672] */
/* @0x2d9d34 vldr s14, [pc, #672] */
/* @0x2d9d38 vldr s12, [pc, #672] */
/* @0x2d9d3c rsb r1, r5, r9 */
/* @0x2d9d40 mov r4, r5 */
/* @0x2d9d44 asr r1, r1, #3 */
/* @0x2d9d48 vcmpe.f32 s17, s21 */
/* @0x2d9d4c vmov.f32 s9, s13 */
/* @0x2d9d50 vmrs APSR_nzcv, fpscr */
/* @0x2d9d54 vmovle.f32 s10, s21 */
/* @0x2d9d58 vmovgt.f32 s10, s17 */
/* @0x2d9d5c vmla.f32 s9, s15, s10 */
/* @0x2d9d60 vcmpe.f32 s18, s22 */
/* @0x2d9d64 vmov.f32 s10, s9 */
/* @0x2d9d68 vmrs APSR_nzcv, fpscr */
/* @0x2d9d6c vmovle.f32 s9, s22 */
/* @0x2d9d70 vmovgt.f32 s9, s18 */
/* @0x2d9d74 vmla.f32 s13, s15, s9 */
/* @0x2d9d78 vmla.f32 s14, s10, s11 */
/* @0x2d9d7c vadd.f32 s13, s13, s12 */
/* @0x2d9d80 vcvt.u32.f32 s14, s14 */
/* @0x2d9d84 vcvt.u32.f32 s13, s13 */
/* @0x2d9d88 vmov r3, s14 */
/* @0x2d9d8c vmov r2, s13 */
/* @0x2d9d90 add r0, r3, r2, lsl #20 */
/* @0x2d9d94 cmp r1, #0 */
/* @0x2d9d98 ble 0x2d9dd4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x188> */
/* @0x2d9d9c asr r3, r1, #1 */
/* @0x2d9da0 add r2, r5, r3, lsl #3 */
/* @0x2d9da4 ldr r12, [r2, #0x4] */
/* @0x2d9da8 cmp r0, r12 */
/* @0x2d9dac blo 0x2d9dc4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x178> */
/* @0x2d9db0 b 0x2d9f78 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x32c> */
/* @0x2d9db4 ldr r1, [r2, #0x4] */
/* @0x2d9db8 cmp r0, r1 */
/* @0x2d9dbc bhs 0x2d9f80 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x334> */
/* @0x2d9dc0 mov r3, r12 */
/* @0x2d9dc4 asr r12, r3, #1 */
/* @0x2d9dc8 cmp r3, #0 */
/* @0x2d9dcc add r2, r5, r12, lsl #3 */
/* @0x2d9dd0 bne 0x2d9db4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x168> */
/* @0x2d9dd4 vsub.f32 s22, s22, s18 */
/* @0x2d9dd8 cmp r5, r4 */
/* @0x2d9ddc vmul.f32 s20, s22, s22 */
/* @0x2d9de0 vsub.f32 s21, s21, s17 */
/* @0x2d9de4 vmla.f32 s20, s21, s21 */
/* @0x2d9de8 bls 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320> */
/* @0x2d9dec add r4, r4, #8 */
/* @0x2d9df0 add r10, sp, #24 */
/* @0x2d9df4 add r9, sp, #16 */
/* @0x2d9df8 vldr s24, [pc, #484] */
/* @0x2d9dfc vmov.f32 s23, #1.000000e+00 */
/* @0x2d9e00 vmov.f32 s25, s23 */
/* @0x2d9e04 b 0x2d9ec8 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x27c> */
/* @0x2d9e08 vmul.f32 s26, s19, s22 */
/* @0x2d9e0c vmul.f32 s16, s19, s21 */
/* @0x2d9e10 vadd.f32 s18, s18, s26 */
/* @0x2d9e14 vmul.f32 s14, s18, s18 */
/* @0x2d9e18 vstr s18, [sp, #20] */
/* @0x2d9e1c vadd.f32 s17, s17, s16 */
/* @0x2d9e20 vmla.f32 s14, s17, s17 */
/* @0x2d9e24 vstr s17, [sp, #16] */
/* @0x2d9e28 vsqrt.f32 s15, s14 */
/* @0x2d9e2c vcmp.f32 s15, s15 */
/* @0x2d9e30 vmrs APSR_nzcv, fpscr */
/* @0x2d9e34 bne 0x2d9fc0 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x374> */
/* @0x2d9e38 vcmpe.f32 s15, s24 */
/* @0x2d9e3c vmrs APSR_nzcv, fpscr */
/* @0x2d9e40 bmi 0x2d9e60 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x214> */
/* @0x2d9e44 vdiv.f32 s15, s25, s15 */
/* @0x2d9e48 vldr s14, [sp, #16] */
/* @0x2d9e4c vldr s13, [sp, #20] */
/* @0x2d9e50 vmul.f32 s14, s14, s15 */
/* @0x2d9e54 vmul.f32 s15, s13, s15 */
/* @0x2d9e58 vstr s14, [sp, #16] */
/* @0x2d9e5c vstr s15, [sp, #20] */
/* @0x2d9e60 vldr s15, [r6] */
/* @0x2d9e64 vldr s14, [r6, #4] */
/* @0x2d9e68 vadd.f32 s16, s16, s15 */
/* @0x2d9e6c ldr r12, [r8] */
/* @0x2d9e70 mov r0, r8 */
/* @0x2d9e74 mov r2, r10 */
/* @0x2d9e78 mov r3, r9 */
/* @0x2d9e7c ldr r12, [r12, #0xc] */
/* @0x2d9e80 vstr s19, [sp] */
/* @0x2d9e84 vadd.f32 s26, s26, s14 */
/* @0x2d9e88 vstr s16, [sp, #24] */
/* @0x2d9e8c vstr s26, [sp, #28] */
/* @0x2d9e90 blx r12 */
/* @0x2d9e94 vmov s15, r0 */
/* @0x2d9e98 vcmp.f32 s15, s23 */
/* @0x2d9e9c vmrs APSR_nzcv, fpscr */
/* @0x2d9ea0 vmovgt.f32 s15, s23 */
/* @0x2d9ea4 vcmpe.f32 s15, #0 */
/* @0x2d9ea8 vmrs APSR_nzcv, fpscr */
/* @0x2d9eac bls 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320> */
/* @0x2d9eb0 vmov.f32 s23, s15 */
/* @0x2d9eb4 cmp r4, r5 */
/* @0x2d9eb8 bhs 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320> */
/* @0x2d9ebc add r4, r4, #8 */
/* @0x2d9ec0 vldr s17, [r6] */
/* @0x2d9ec4 vldr s18, [r6, #4] */
/* @0x2d9ec8 ldr r1, [r4, #-0x8] */
/* @0x2d9ecc vldr s14, [r7, #32] */
/* @0x2d9ed0 ldr r0, [r7, #0x38] */
/* @0x2d9ed4 add r0, r0, r1, lsl #3 */
/* @0x2d9ed8 vldr s15, [r0, #4] */
/* @0x2d9edc vsub.f32 s18, s18, s15 */
/* @0x2d9ee0 vldr s13, [r0] */
/* @0x2d9ee4 vmul.f32 s15, s18, s18 */
/* @0x2d9ee8 vsub.f32 s17, s17, s13 */
/* @0x2d9eec vmla.f32 s15, s17, s17 */
/* @0x2d9ef0 vmul.f32 s16, s22, s18 */
/* @0x2d9ef4 vsub.f32 s15, s15, s14 */
/* @0x2d9ef8 vmla.f32 s16, s21, s17 */
/* @0x2d9efc vmul.f32 s15, s15, s20 */
/* @0x2d9f00 vnmls.f32 s15, s16, s16 */
/* @0x2d9f04 vcmpe.f32 s15, #0 */
/* @0x2d9f08 vmrs APSR_nzcv, fpscr */
/* @0x2d9f0c blt 0x2d9eb4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x268> */
/* @0x2d9f10 vsqrt.f32 s14, s15 */
/* @0x2d9f14 vcmp.f32 s14, s14 */
/* @0x2d9f18 vmrs APSR_nzcv, fpscr */
/* @0x2d9f1c bne 0x2d9fa8 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x35c> */
/* @0x2d9f20 vneg.f32 s19, s16 */
/* @0x2d9f24 vsub.f32 s19, s19, s14 */
/* @0x2d9f28 vdiv.f32 s19, s19, s20 */
/* @0x2d9f2c vcmpe.f32 s19, s23 */
/* @0x2d9f30 vmrs APSR_nzcv, fpscr */
/* @0x2d9f34 bgt 0x2d9eb4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x268> */
/* @0x2d9f38 vcmpe.f32 s19, #0 */
/* @0x2d9f3c vmrs APSR_nzcv, fpscr */
/* @0x2d9f40 bpl 0x2d9e08 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x1bc> */
/* @0x2d9f44 vsub.f32 s16, s14, s16 */
/* @0x2d9f48 vdiv.f32 s19, s16, s20 */
/* @0x2d9f4c vcmpe.f32 s19, #0 */
/* @0x2d9f50 vmrs APSR_nzcv, fpscr */
/* @0x2d9f54 bmi 0x2d9eb4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x268> */
/* @0x2d9f58 vcmpe.f32 s19, s23 */
/* @0x2d9f5c vmrs APSR_nzcv, fpscr */
/* @0x2d9f60 ble 0x2d9e08 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x1bc> */
/* @0x2d9f64 cmp r4, r5 */
/* @0x2d9f68 blo 0x2d9ebc <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x270> */
/* @0x2d9f6c add sp, sp, #32 */
/* @0x2d9f70 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2d9f74 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2d9f78 mov r12, r3 */
/* @0x2d9f7c mov r3, r1 */
/* @0x2d9f80 rsb r3, r12, r3 */
/* @0x2d9f84 add r5, r2, #8 */
/* @0x2d9f88 sub r1, r3, #1 */
/* @0x2d9f8c b 0x2d9d94 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x148> */
/* @0x2d9f90 mov r12, r3 */
/* @0x2d9f94 mov r3, r4 */
/* @0x2d9f98 rsb r3, r12, r3 */
/* @0x2d9f9c add r5, r2, #8 */
/* @0x2d9fa0 sub r4, r3, #1 */
/* @0x2d9fa4 b 0x2d9cec <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xa0> */
/* @0x2d9fa8 vmov r0, s15 */
/* @0x2d9fac str r1, [sp, #0xc] */
/* @0x2d9fb0 bl 0xb6700 <sqrtf@plt> */
/* @0x2d9fb4 ldr r1, [sp, #0xc] */
/* @0x2d9fb8 vmov s14, r0 */
/* @0x2d9fbc b 0x2d9f20 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x2d4> */
/* @0x2d9fc0 vmov r0, s14 */
/* @0x2d9fc4 str r1, [sp, #0xc] */
/* @0x2d9fc8 bl 0xb6700 <sqrtf@plt> */
/* @0x2d9fcc ldr r1, [sp, #0xc] */
/* @0x2d9fd0 vmov s15, r0 */
/* @0x2d9fd4 b 0x2d9e38 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x1ec> */
/* @0x2d9fd8 orrmi r0, r0, #0 */
/* @0x2d9fdc .word 0x49000000 */
/* @0x2d9fe0 strmi r0, [r0, #-0x0] */
/* @0x2d9fe4 strlo r0, [r0], #-0 */

/* ── FUNC 0x2d9fe8 · b2ParticleSystem::ComputeParticleCollisionEnergy() const · size=168 · insn=42 */
/* @0x2d9fe8 push {r3, lr} */
/* @0x2d9fec vpush {d8} */
/* @0x2d9ff0 ldr lr, [r0, #0x74] */
/* @0x2d9ff4 cmp lr, #0 */
/* @0x2d9ff8 ble 0x2da084 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv+0x9c> */
/* @0x2d9ffc ldr r3, [r0, #0x7c] */
/* @0x2da000 add lr, lr, lr, lsl #1 */
/* @0x2da004 ldr r12, [r0, #0x40] */
/* @0x2da008 vldr s16, [pc, #124] */
/* @0x2da00c add r3, r3, #16 */
/* @0x2da010 add lr, r3, lr, lsl #3 */
/* @0x2da014 ldr r1, [r3, #-0xc] */
/* @0x2da018 vldr s11, [r3, #4] */
/* @0x2da01c ldr r2, [r3, #-0x10] */
/* @0x2da020 vldr s14, [r3] */
/* @0x2da024 add r3, r3, #24 */
/* @0x2da028 add r1, r12, r1, lsl #3 */
/* @0x2da02c vldr s13, [r1, #4] */
/* @0x2da030 add r2, r12, r2, lsl #3 */
/* @0x2da034 vldr s15, [r2, #4] */
/* @0x2da038 vsub.f32 s15, s13, s15 */
/* @0x2da03c vldr s12, [r1] */
/* @0x2da040 vldr s13, [r2] */
/* @0x2da044 vmul.f32 s15, s15, s11 */
/* @0x2da048 vsub.f32 s13, s12, s13 */
/* @0x2da04c vmla.f32 s15, s13, s14 */
/* @0x2da050 vcmpe.f32 s15, #0 */
/* @0x2da054 vmrs APSR_nzcv, fpscr */
/* @0x2da058 vmlami.f32 s16, s15, s15 */
/* @0x2da05c cmp r3, lr */
/* @0x2da060 bne 0x2da014 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv+0x2c> */
/* @0x2da064 bl 0x2d85bc <_ZNK16b2ParticleSystem15GetParticleMassEv> */
/* @0x2da068 vmov.f32 s15, #5.000000e-01 */
/* @0x2da06c vmov s14, r0 */
/* @0x2da070 vmul.f32 s15, s14, s15 */
/* @0x2da074 vmul.f32 s15, s15, s16 */
/* @0x2da078 vpop {d8} */
/* @0x2da07c vmov r0, s15 */
/* @0x2da080 pop {r3, pc} */
/* @0x2da084 vldr s16, [pc] */
/* @0x2da088 b 0x2da064 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv+0x7c> */
/* @0x2da08c andeq r0, r0, r0 */

/* ── FUNC 0x2da090 · b2Vec2* b2ParticleSystem::ReallocateBuffer<b2Vec2>(b2ParticleSystem::ParticleBuffer<b2Vec2>*, int, int, bool) · size=120 · insn=30 */
/* @0x2da090 push {r3, r4, r5, r6, r7, lr} */
/* @0x2da094 mov r6, r0 */
/* @0x2da098 ldrb r12, [sp, #0x18] */
/* @0x2da09c ldr r4, [r1] */
/* @0x2da0a0 eor r12, r12, #1 */
/* @0x2da0a4 ldr r5, [r1, #0x4] */
/* @0x2da0a8 cmp r4, #0 */
/* @0x2da0ac orrne r12, r12, #1 */
/* @0x2da0b0 cmp r12, #0 */
/* @0x2da0b4 moveq r4, r12 */
/* @0x2da0b8 bne 0x2da0c4 <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib+0x34> */
/* @0x2da0bc mov r0, r4 */
/* @0x2da0c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2da0c4 cmp r5, #0 */
/* @0x2da0c8 bne 0x2da0bc <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib+0x2c> */
/* @0x2da0cc lsl r1, r3, #3 */
/* @0x2da0d0 ldr r0, [r0, #0xd4] */
/* @0x2da0d4 lsl r5, r2, #3 */
/* @0x2da0d8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da0dc mov r1, r4 */
/* @0x2da0e0 mov r2, r5 */
/* @0x2da0e4 mov r7, r0 */
/* @0x2da0e8 bl 0xb65bc <memcpy@plt> */
/* @0x2da0ec ldr r0, [r6, #0xd4] */
/* @0x2da0f0 mov r1, r4 */
/* @0x2da0f4 mov r2, r5 */
/* @0x2da0f8 mov r4, r7 */
/* @0x2da0fc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da100 mov r0, r4 */
/* @0x2da104 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2da108 · b2ParticleSystem::CreateParticle(b2ParticleDef const&) · size=1148 · insn=287 */
/* @0x2da108 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2da10c mov r4, r0 */
/* @0x2da110 ldr r5, [r0, #0x24] */
/* @0x2da114 sub sp, sp, #12 */
/* @0x2da118 ldr r2, [r0, #0x28] */
/* @0x2da11c mov r6, r1 */
/* @0x2da120 cmp r5, r2 */
/* @0x2da124 blt 0x2da3b8 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x2b0> */
/* @0x2da128 cmp r5, #0 */
/* @0x2da12c ldr r3, [r0, #0x2c] */
/* @0x2da130 lslne r5, r5, #1 */
/* @0x2da134 ldr r1, [r0, #0x34] */
/* @0x2da138 moveq r5, #256 */
/* @0x2da13c cmp r3, #0 */
/* @0x2da140 cmpne r5, r3 */
/* @0x2da144 ldr r7, [r0, #0x3c] */
/* @0x2da148 movgt r5, r3 */
/* @0x2da14c cmp r1, #0 */
/* @0x2da150 cmpne r1, r5 */
/* @0x2da154 ldr r12, [r0, #0x44] */
/* @0x2da158 movlt r5, r1 */
/* @0x2da15c cmp r7, #0 */
/* @0x2da160 cmpne r7, r5 */
/* @0x2da164 ldr r0, [r0, #0x58] */
/* @0x2da168 movge r7, r5 */
/* @0x2da16c cmp r12, #0 */
/* @0x2da170 cmpne r12, r7 */
/* @0x2da174 ldr r3, [r4, #0x64] */
/* @0x2da178 movge r12, r7 */
/* @0x2da17c cmp r0, #0 */
/* @0x2da180 cmpne r0, r12 */
/* @0x2da184 movge r0, r12 */
/* @0x2da188 cmp r3, #0 */
/* @0x2da18c cmpne r3, r0 */
/* @0x2da190 movge r7, r0 */
/* @0x2da194 movlt r7, r3 */
/* @0x2da198 cmp r2, r7 */
/* @0x2da19c blt 0x2da1ac <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0xa4> */
/* @0x2da1a0 mvn r0, #0 */
/* @0x2da1a4 add sp, sp, #12 */
/* @0x2da1a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2da1ac cmp r1, #0 */
/* @0x2da1b0 lsl r5, r7, #2 */
/* @0x2da1b4 ldr r8, [r4, #0x30] */
/* @0x2da1b8 beq 0x2da548 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x440> */
/* @0x2da1bc str r8, [r4, #0x30] */
/* @0x2da1c0 add r1, r4, #56 */
/* @0x2da1c4 mov r8, #0 */
/* @0x2da1c8 mov r3, r7 */
/* @0x2da1cc str r8, [sp] */
/* @0x2da1d0 mov r0, r4 */
/* @0x2da1d4 bl 0x2da090 <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib> */
/* @0x2da1d8 ldr r2, [r4, #0x28] */
/* @0x2da1dc mov r3, r7 */
/* @0x2da1e0 str r8, [sp] */
/* @0x2da1e4 add r1, r4, #64 */
/* @0x2da1e8 str r0, [r4, #0x38] */
/* @0x2da1ec mov r0, r4 */
/* @0x2da1f0 bl 0x2da090 <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib> */
/* @0x2da1f4 mov r1, r5 */
/* @0x2da1f8 ldr r8, [r4, #0x48] */
/* @0x2da1fc ldr r9, [r4, #0x28] */
/* @0x2da200 lsl r9, r9, #2 */
/* @0x2da204 str r0, [r4, #0x40] */
/* @0x2da208 ldr r0, [r4, #0xd4] */
/* @0x2da20c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da210 mov r1, r8 */
/* @0x2da214 mov r2, r9 */
/* @0x2da218 mov r10, r0 */
/* @0x2da21c bl 0xb65bc <memcpy@plt> */
/* @0x2da220 mov r2, r9 */
/* @0x2da224 mov r1, r8 */
/* @0x2da228 ldr r0, [r4, #0xd4] */
/* @0x2da22c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da230 ldr r8, [r4, #0x4c] */
/* @0x2da234 str r10, [r4, #0x48] */
/* @0x2da238 cmp r8, #0 */
/* @0x2da23c ldr r2, [r4, #0x28] */
/* @0x2da240 moveq r10, r8 */
/* @0x2da244 beq 0x2da27c <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x174> */
/* @0x2da248 lsl r1, r7, #3 */
/* @0x2da24c ldr r0, [r4, #0xd4] */
/* @0x2da250 lsl r9, r2, #3 */
/* @0x2da254 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da258 mov r1, r8 */
/* @0x2da25c mov r2, r9 */
/* @0x2da260 mov r10, r0 */
/* @0x2da264 bl 0xb65bc <memcpy@plt> */
/* @0x2da268 mov r2, r9 */
/* @0x2da26c mov r1, r8 */
/* @0x2da270 ldr r0, [r4, #0xd4] */
/* @0x2da274 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da278 ldr r2, [r4, #0x28] */
/* @0x2da27c ldr r8, [r4, #0x50] */
/* @0x2da280 str r10, [r4, #0x4c] */
/* @0x2da284 cmp r8, #0 */
/* @0x2da288 moveq r10, r8 */
/* @0x2da28c beq 0x2da2c4 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x1bc> */
/* @0x2da290 mov r1, r5 */
/* @0x2da294 ldr r0, [r4, #0xd4] */
/* @0x2da298 lsl r9, r2, #2 */
/* @0x2da29c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da2a0 mov r1, r8 */
/* @0x2da2a4 mov r2, r9 */
/* @0x2da2a8 mov r10, r0 */
/* @0x2da2ac bl 0xb65bc <memcpy@plt> */
/* @0x2da2b0 mov r2, r9 */
/* @0x2da2b4 mov r1, r8 */
/* @0x2da2b8 ldr r0, [r4, #0xd4] */
/* @0x2da2bc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da2c0 ldr r2, [r4, #0x28] */
/* @0x2da2c4 ldr r8, [r4, #0x54] */
/* @0x2da2c8 str r10, [r4, #0x50] */
/* @0x2da2cc cmp r8, #0 */
/* @0x2da2d0 ldr r3, [r4, #0x58] */
/* @0x2da2d4 beq 0x2da318 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x210> */
/* @0x2da2d8 cmp r3, #0 */
/* @0x2da2dc bne 0x2da318 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x210> */
/* @0x2da2e0 mov r1, r5 */
/* @0x2da2e4 ldr r0, [r4, #0xd4] */
/* @0x2da2e8 lsl r9, r2, #2 */
/* @0x2da2ec bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da2f0 mov r1, r8 */
/* @0x2da2f4 mov r2, r9 */
/* @0x2da2f8 mov r10, r0 */
/* @0x2da2fc bl 0xb65bc <memcpy@plt> */
/* @0x2da300 mov r2, r9 */
/* @0x2da304 mov r1, r8 */
/* @0x2da308 ldr r0, [r4, #0xd4] */
/* @0x2da30c mov r8, r10 */
/* @0x2da310 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da314 ldr r2, [r4, #0x28] */
/* @0x2da318 str r8, [r4, #0x54] */
/* @0x2da31c mov r1, r5 */
/* @0x2da320 ldr r0, [r4, #0xd4] */
/* @0x2da324 lsl r9, r2, #2 */
/* @0x2da328 ldr r10, [r4, #0x5c] */
/* @0x2da32c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da330 mov r2, r9 */
/* @0x2da334 mov r1, r10 */
/* @0x2da338 mov r11, r0 */
/* @0x2da33c bl 0xb65bc <memcpy@plt> */
/* @0x2da340 mov r2, r9 */
/* @0x2da344 mov r1, r10 */
/* @0x2da348 ldr r0, [r4, #0xd4] */
/* @0x2da34c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da350 ldr r8, [r4, #0x60] */
/* @0x2da354 str r11, [r4, #0x5c] */
/* @0x2da358 cmp r8, #0 */
/* @0x2da35c ldr r2, [r4, #0x28] */
/* @0x2da360 ldr r3, [r4, #0x64] */
/* @0x2da364 beq 0x2da3a4 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x29c> */
/* @0x2da368 cmp r3, #0 */
/* @0x2da36c bne 0x2da3a4 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x29c> */
/* @0x2da370 mov r1, r5 */
/* @0x2da374 ldr r0, [r4, #0xd4] */
/* @0x2da378 lsl r9, r2, #2 */
/* @0x2da37c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da380 mov r1, r8 */
/* @0x2da384 mov r2, r9 */
/* @0x2da388 mov r5, r0 */
/* @0x2da38c bl 0xb65bc <memcpy@plt> */
/* @0x2da390 mov r1, r8 */
/* @0x2da394 mov r2, r9 */
/* @0x2da398 ldr r0, [r4, #0xd4] */
/* @0x2da39c mov r8, r5 */
/* @0x2da3a0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da3a4 ldr r5, [r4, #0x24] */
/* @0x2da3a8 str r8, [r4, #0x60] */
/* @0x2da3ac cmp r5, r7 */
/* @0x2da3b0 str r7, [r4, #0x28] */
/* @0x2da3b4 bge 0x2da1a0 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x98> */
/* @0x2da3b8 mov r3, r6 */
/* @0x2da3bc ldr r2, [r4, #0x38] */
/* @0x2da3c0 ldr r9, [r3], #4 */
/* @0x2da3c4 lsl r12, r5, #3 */
/* @0x2da3c8 ldr r8, [r4, #0x30] */
/* @0x2da3cc add r2, r2, r12 */
/* @0x2da3d0 add r7, r6, #12 */
/* @0x2da3d4 ldr r10, [r4, #0x40] */
/* @0x2da3d8 ldm r3, {r0, r1} */
/* @0x2da3dc add r3, r5, #1 */
/* @0x2da3e0 str r3, [r4, #0x24] */
/* @0x2da3e4 add r3, r10, r12 */
/* @0x2da3e8 str r9, [r8, r5, lsl #2] */
/* @0x2da3ec mov r12, #0 */
/* @0x2da3f0 stm r2, {r0, r1} */
/* @0x2da3f4 lsl r8, r5, #2 */
/* @0x2da3f8 ldr r2, [r4, #0x5c] */
/* @0x2da3fc ldm r7, {r0, r1} */
/* @0x2da400 stm r3, {r0, r1} */
/* @0x2da404 str r12, [r2, r5, lsl #2] */
/* @0x2da408 ldr r3, [r4, #0x50] */
/* @0x2da40c cmp r3, r12 */
/* @0x2da410 addne r3, r3, r8 */
/* @0x2da414 movne r2, #0 */
/* @0x2da418 strne r2, [r3] */
/* @0x2da41c ldr r3, [r4, #0x54] */
/* @0x2da420 cmp r3, #0 */
/* @0x2da424 beq 0x2da4d0 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3c8> */
/* @0x2da428 str r3, [r4, #0x54] */
/* @0x2da42c ldr r0, [r6, #0x14] */
/* @0x2da430 str r0, [r3, r8] */
/* @0x2da434 ldr r7, [r4, #0x60] */
/* @0x2da438 cmp r7, #0 */
/* @0x2da43c beq 0x2da514 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x40c> */
/* @0x2da440 ldr r3, [r6, #0x18] */
/* @0x2da444 str r7, [r4, #0x60] */
/* @0x2da448 str r3, [r7, r8] */
/* @0x2da44c ldr r1, [r4, #0x68] */
/* @0x2da450 ldr r2, [r4, #0x6c] */
/* @0x2da454 cmp r1, r2 */
/* @0x2da458 bge 0x2da478 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x370> */
/* @0x2da45c ldr r3, [r4, #0x70] */
/* @0x2da460 add r2, r1, #1 */
/* @0x2da464 mov r0, r5 */
/* @0x2da468 str r2, [r4, #0x68] */
/* @0x2da46c str r5, [r3, r1, lsl #3] */
/* @0x2da470 add sp, sp, #12 */
/* @0x2da474 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2da478 cmp r1, #0 */
/* @0x2da47c ldr r0, [r4, #0xd4] */
/* @0x2da480 lslne r9, r1, #1 */
/* @0x2da484 lslne r1, r1, #4 */
/* @0x2da488 moveq r1, #2048 */
/* @0x2da48c moveq r9, #256 */
/* @0x2da490 ldr r7, [r4, #0x70] */
/* @0x2da494 lsl r6, r2, #3 */
/* @0x2da498 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da49c mov r2, r6 */
/* @0x2da4a0 mov r1, r7 */
/* @0x2da4a4 mov r8, r0 */
/* @0x2da4a8 bl 0xb65bc <memcpy@plt> */
/* @0x2da4ac mov r1, r7 */
/* @0x2da4b0 mov r2, r6 */
/* @0x2da4b4 ldr r0, [r4, #0xd4] */
/* @0x2da4b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da4bc ldr r1, [r4, #0x68] */
/* @0x2da4c0 mov r3, r8 */
/* @0x2da4c4 str r8, [r4, #0x70] */
/* @0x2da4c8 str r9, [r4, #0x6c] */
/* @0x2da4cc b 0x2da460 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x358> */
/* @0x2da4d0 ldrb r3, [r6, #0x14] */
/* @0x2da4d4 cmp r3, #0 */
/* @0x2da4d8 bne 0x2da500 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3f8> */
/* @0x2da4dc ldrb r3, [r6, #0x15] */
/* @0x2da4e0 cmp r3, #0 */
/* @0x2da4e4 bne 0x2da500 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3f8> */
/* @0x2da4e8 ldrb r3, [r6, #0x16] */
/* @0x2da4ec cmp r3, #0 */
/* @0x2da4f0 bne 0x2da500 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3f8> */
/* @0x2da4f4 ldrb r3, [r6, #0x17] */
/* @0x2da4f8 cmp r3, #0 */
/* @0x2da4fc beq 0x2da434 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x32c> */
/* @0x2da500 add r0, r4, #40 */
/* @0x2da504 add r1, r4, #212 */
/* @0x2da508 bl 0x2d4a30 <_ZN15b2QueryCallbackD0Ev+0xa0> */
/* @0x2da50c mov r3, r0 */
/* @0x2da510 b 0x2da428 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x320> */
/* @0x2da514 ldr r3, [r6, #0x18] */
/* @0x2da518 cmp r3, #0 */
/* @0x2da51c beq 0x2da44c <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x344> */
/* @0x2da520 ldr r1, [r4, #0x28] */
/* @0x2da524 ldr r0, [r4, #0xd4] */
/* @0x2da528 lsl r1, r1, #2 */
/* @0x2da52c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da530 ldr r2, [r4, #0x28] */
/* @0x2da534 mov r1, #0 */
/* @0x2da538 lsl r2, r2, #2 */
/* @0x2da53c mov r7, r0 */
/* @0x2da540 bl 0xb65b0 <memset@plt> */
/* @0x2da544 b 0x2da440 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x338> */
/* @0x2da548 mov r1, r5 */
/* @0x2da54c ldr r0, [r4, #0xd4] */
/* @0x2da550 lsl r9, r2, #2 */
/* @0x2da554 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da558 mov r1, r8 */
/* @0x2da55c mov r2, r9 */
/* @0x2da560 mov r10, r0 */
/* @0x2da564 bl 0xb65bc <memcpy@plt> */
/* @0x2da568 mov r2, r9 */
/* @0x2da56c mov r1, r8 */
/* @0x2da570 ldr r0, [r4, #0xd4] */
/* @0x2da574 mov r8, r10 */
/* @0x2da578 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da57c ldr r2, [r4, #0x28] */
/* @0x2da580 b 0x2da1bc <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0xb4> */

/* ── FUNC 0x2da584 · void std::sort<b2ParticleSystem::Proxy*>(b2ParticleSystem::Proxy*, b2ParticleSystem::Proxy*) · size=224 · insn=56 */
/* @0x2da584 cmp r0, r1 */
/* @0x2da588 push {r4, r5, r6, r7, r8, lr} */
/* @0x2da58c mov r6, r0 */
/* @0x2da590 mov r7, r1 */
/* @0x2da594 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2da598 rsb r4, r0, r1 */
/* @0x2da59c mov r2, #0 */
/* @0x2da5a0 asr r3, r4, #3 */
/* @0x2da5a4 cmp r3, #1 */
/* @0x2da5a8 beq 0x2da5c0 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x3c> */
/* @0x2da5ac asr r3, r3, #1 */
/* @0x2da5b0 add r2, r2, #1 */
/* @0x2da5b4 cmp r3, #1 */
/* @0x2da5b8 bne 0x2da5ac <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x28> */
/* @0x2da5bc lsl r2, r2, #1 */
/* @0x2da5c0 mov r0, r6 */
/* @0x2da5c4 mov r1, r7 */
/* @0x2da5c8 bl 0x2d4b88 <_ZN15b2QueryCallbackD0Ev+0x1f8> */
/* @0x2da5cc cmp r4, #135 */
/* @0x2da5d0 bgt 0x2da5e4 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x60> */
/* @0x2da5d4 mov r0, r6 */
/* @0x2da5d8 mov r1, r7 */
/* @0x2da5dc pop {r4, r5, r6, r7, r8, lr} */
/* @0x2da5e0 b 0x2d4d10 <_ZN15b2QueryCallbackD0Ev+0x380> */
/* @0x2da5e4 add r5, r6, #128 */
/* @0x2da5e8 mov r0, r6 */
/* @0x2da5ec mov r1, r5 */
/* @0x2da5f0 bl 0x2d4d10 <_ZN15b2QueryCallbackD0Ev+0x380> */
/* @0x2da5f4 cmp r7, r5 */
/* @0x2da5f8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2da5fc add r6, r6, #120 */
/* @0x2da600 ldr r4, [r5, #0x4] */
/* @0x2da604 mov r3, r6 */
/* @0x2da608 ldr r2, [r5, #-0x4] */
/* @0x2da60c ldr r8, [r6, #0x8] */
/* @0x2da610 cmp r4, r2 */
/* @0x2da614 bhs 0x2da65c <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0xd8> */
/* @0x2da618 mov r2, r5 */
/* @0x2da61c b 0x2da624 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0xa0> */
/* @0x2da620 mov r3, r12 */
/* @0x2da624 ldm r3, {r0, r1} */
/* @0x2da628 sub r12, r3, #8 */
/* @0x2da62c stm r2, {r0, r1} */
/* @0x2da630 mov r2, r3 */
/* @0x2da634 ldr r0, [r3, #-0x4] */
/* @0x2da638 cmp r4, r0 */
/* @0x2da63c blo 0x2da620 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x9c> */
/* @0x2da640 add r5, r5, #8 */
/* @0x2da644 str r8, [r3] */
/* @0x2da648 cmp r7, r5 */
/* @0x2da64c str r4, [r3, #0x4] */
/* @0x2da650 add r6, r6, #8 */
/* @0x2da654 bne 0x2da600 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0x7c> */
/* @0x2da658 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2da65c mov r3, r5 */
/* @0x2da660 b 0x2da640 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_+0xbc> */

/* ── FUNC 0x2da664 · b2ParticleSystem::UpdateContacts(bool) · size=1644 · insn=411 */
/* @0x2da664 ldr r3, [r0, #0x68] */
/* @0x2da668 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2da66c vpush {d8, d9, d10} */
/* @0x2da670 sub sp, sp, #28 */
/* @0x2da674 ldr r6, [r0, #0x70] */
/* @0x2da678 mov r4, r0 */
/* @0x2da67c str r1, [sp, #0x14] */
/* @0x2da680 add r11, r6, r3, lsl #3 */
/* @0x2da684 cmp r6, r11 */
/* @0x2da688 bhs 0x2daacc <_ZN16b2ParticleSystem14UpdateContactsEb+0x468> */
/* @0x2da68c add r9, r6, #8 */
/* @0x2da690 add r12, r6, #16 */
/* @0x2da694 rsb r1, r9, #7 */
/* @0x2da698 ldr r0, [r0, #0x38] */
/* @0x2da69c add r1, r11, r1 */
/* @0x2da6a0 mov r3, r9 */
/* @0x2da6a4 bic r1, r1, #7 */
/* @0x2da6a8 vldr s15, [r4, #28] */
/* @0x2da6ac add r1, r12, r1 */
/* @0x2da6b0 vldr s10, [pc, #656] */
/* @0x2da6b4 vldr s11, [pc, #656] */
/* @0x2da6b8 vldr s12, [pc, #656] */
/* @0x2da6bc ldr r2, [r3, #-0x8] */
/* @0x2da6c0 vmov.f32 s9, s11 */
/* @0x2da6c4 add r3, r3, #8 */
/* @0x2da6c8 add r2, r0, r2, lsl #3 */
/* @0x2da6cc vldr s13, [r2] */
/* @0x2da6d0 vmul.f32 s13, s15, s13 */
/* @0x2da6d4 vldr s14, [r2, #4] */
/* @0x2da6d8 vmla.f32 s9, s13, s10 */
/* @0x2da6dc vmov.f32 s13, s9 */
/* @0x2da6e0 vmov.f32 s9, s12 */
/* @0x2da6e4 vmla.f32 s9, s15, s14 */
/* @0x2da6e8 vcvt.u32.f32 s13, s13 */
/* @0x2da6ec vcvt.u32.f32 s14, s9 */
/* @0x2da6f0 vmov lr, s13 */
/* @0x2da6f4 vmov r2, s14 */
/* @0x2da6f8 add r2, lr, r2, lsl #20 */
/* @0x2da6fc str r2, [r3, #-0xc] */
/* @0x2da700 cmp r3, r1 */
/* @0x2da704 bne 0x2da6bc <_ZN16b2ParticleSystem14UpdateContactsEb+0x58> */
/* @0x2da708 vmov.f32 s21, #5.000000e-01 */
/* @0x2da70c mov r0, r6 */
/* @0x2da710 mov r1, r11 */
/* @0x2da714 mov r10, r9 */
/* @0x2da718 str r12, [sp, #0xc] */
/* @0x2da71c bl 0x2da584 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_> */
/* @0x2da720 mov r3, #0 */
/* @0x2da724 str r3, [r4, #0x74] */
/* @0x2da728 vmov.f32 s20, #1.500000e+00 */
/* @0x2da72c vmov.f32 s19, #1.000000e+00 */
/* @0x2da730 ldr r3, [sp, #0xc] */
/* @0x2da734 cmp r11, r10 */
/* @0x2da738 ldr r1, [r3, #-0xc] */
/* @0x2da73c add r9, r1, #256 */
/* @0x2da740 bls 0x2da8d4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x270> */
/* @0x2da744 ldr r3, [r3, #-0x4] */
/* @0x2da748 cmp r9, r3 */
/* @0x2da74c blo 0x2da8d4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x270> */
/* @0x2da750 ldr r5, [sp, #0xc] */
/* @0x2da754 str r6, [sp, #0x10] */
/* @0x2da758 b 0x2da7f8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x194> */
/* @0x2da75c ldr r2, [r4, #0x7c] */
/* @0x2da760 vmov r0, s16 */
/* @0x2da764 vldr s14, [r4, #28] */
/* @0x2da768 vmul.f32 s15, s16, s21 */
/* @0x2da76c vmov.f32 s12, s20 */
/* @0x2da770 vmov.f32 s13, s19 */
/* @0x2da774 asr r3, r0, #1 */
/* @0x2da778 add r0, r1, r1, lsl #1 */
/* @0x2da77c rsb r3, r3, #1593835520 */
/* @0x2da780 add r1, r1, #1 */
/* @0x2da784 add r3, r3, #3620864 */
/* @0x2da788 str r6, [r2, r0, lsl #3] */
/* @0x2da78c add r3, r3, #6592 */
/* @0x2da790 add r2, r2, r0, lsl #3 */
/* @0x2da794 add r3, r3, #31 */
/* @0x2da798 ldr r0, [r4, #0x30] */
/* @0x2da79c str r7, [r2, #0x4] */
/* @0x2da7a0 vmov s9, r3 */
/* @0x2da7a4 ldr r12, [r0, r7, lsl #2] */
/* @0x2da7a8 vmul.f32 s15, s15, s9 */
/* @0x2da7ac ldr r0, [r0, r6, lsl #2] */
/* @0x2da7b0 orr r0, r12, r0 */
/* @0x2da7b4 str r0, [r2, #0x8] */
/* @0x2da7b8 vmls.f32 s12, s9, s15 */
/* @0x2da7bc vmul.f32 s15, s9, s12 */
/* @0x2da7c0 vmul.f32 s16, s16, s15 */
/* @0x2da7c4 vmls.f32 s13, s16, s14 */
/* @0x2da7c8 vmul.f32 s18, s18, s15 */
/* @0x2da7cc vstr s13, [r2, #12] */
/* @0x2da7d0 vmul.f32 s17, s17, s15 */
/* @0x2da7d4 vstr s18, [r2, #16] */
/* @0x2da7d8 vstr s17, [r2, #20] */
/* @0x2da7dc str r1, [r4, #0x74] */
/* @0x2da7e0 cmp r11, r5 */
/* @0x2da7e4 add r5, r5, #8 */
/* @0x2da7e8 bls 0x2da8cc <_ZN16b2ParticleSystem14UpdateContactsEb+0x268> */
/* @0x2da7ec ldr r3, [r5, #-0x4] */
/* @0x2da7f0 cmp r3, r9 */
/* @0x2da7f4 bhi 0x2da8cc <_ZN16b2ParticleSystem14UpdateContactsEb+0x268> */
/* @0x2da7f8 ldr r6, [r10, #-0x8] */
/* @0x2da7fc vldr s15, [r4, #32] */
/* @0x2da800 ldr r7, [r5, #-0x8] */
/* @0x2da804 ldr r2, [r4, #0x38] */
/* @0x2da808 add r3, r2, r6, lsl #3 */
/* @0x2da80c add r2, r2, r7, lsl #3 */
/* @0x2da810 vldr s14, [r3, #4] */
/* @0x2da814 vldr s17, [r2, #4] */
/* @0x2da818 vsub.f32 s17, s17, s14 */
/* @0x2da81c vldr s18, [r2] */
/* @0x2da820 vldr s14, [r3] */
/* @0x2da824 vmul.f32 s16, s17, s17 */
/* @0x2da828 vsub.f32 s18, s18, s14 */
/* @0x2da82c vmla.f32 s16, s18, s18 */
/* @0x2da830 vcmpe.f32 s16, s15 */
/* @0x2da834 vmrs APSR_nzcv, fpscr */
/* @0x2da838 bpl 0x2da7e0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x17c> */
/* @0x2da83c ldr r3, [r4, #0x74] */
/* @0x2da840 ldr r12, [r4, #0x78] */
/* @0x2da844 cmp r3, r12 */
/* @0x2da848 mov r1, r3 */
/* @0x2da84c blt 0x2da75c <_ZN16b2ParticleSystem14UpdateContactsEb+0xf8> */
/* @0x2da850 lsl r8, r3, #1 */
/* @0x2da854 cmp r3, #0 */
/* @0x2da858 add r3, r8, r3, lsl #2 */
/* @0x2da85c mov r1, #6144 */
/* @0x2da860 ldr r0, [r4, #0xd4] */
/* @0x2da864 moveq r8, #256 */
/* @0x2da868 lslne r1, r3, #3 */
/* @0x2da86c ldr r3, [r4, #0x7c] */
/* @0x2da870 str r12, [sp, #0x4] */
/* @0x2da874 str r3, [sp, #0x8] */
/* @0x2da878 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2da87c ldr r12, [sp, #0x4] */
/* @0x2da880 ldr r1, [sp, #0x8] */
/* @0x2da884 add r12, r12, r12, lsl #1 */
/* @0x2da888 lsl r12, r12, #3 */
/* @0x2da88c str r12, [sp, #0x4] */
/* @0x2da890 mov r2, r12 */
/* @0x2da894 bl 0xb65bc <memcpy@plt> */
/* @0x2da898 ldr r12, [sp, #0x4] */
/* @0x2da89c ldr r1, [sp, #0x8] */
/* @0x2da8a0 mov r2, r12 */
/* @0x2da8a4 mov r3, r0 */
/* @0x2da8a8 ldr r0, [r4, #0xd4] */
/* @0x2da8ac str r3, [sp, #0x4] */
/* @0x2da8b0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2da8b4 ldr r3, [sp, #0x4] */
/* @0x2da8b8 ldr r1, [r4, #0x74] */
/* @0x2da8bc str r8, [r4, #0x78] */
/* @0x2da8c0 mov r2, r3 */
/* @0x2da8c4 str r3, [r4, #0x7c] */
/* @0x2da8c8 b 0x2da760 <_ZN16b2ParticleSystem14UpdateContactsEb+0xfc> */
/* @0x2da8cc ldr r6, [sp, #0x10] */
/* @0x2da8d0 ldr r1, [r10, #-0x4] */
/* @0x2da8d4 cmp r11, r6 */
/* @0x2da8d8 add r2, r1, #1044480 */
/* @0x2da8dc add r2, r2, #3840 */
/* @0x2da8e0 bls 0x2da90c <_ZN16b2ParticleSystem14UpdateContactsEb+0x2a8> */
/* @0x2da8e4 ldr r3, [r6, #0x4] */
/* @0x2da8e8 cmp r2, r3 */
/* @0x2da8ec bhi 0x2da900 <_ZN16b2ParticleSystem14UpdateContactsEb+0x29c> */
/* @0x2da8f0 b 0x2da928 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2c4> */
/* @0x2da8f4 ldr r3, [r6, #0x4] */
/* @0x2da8f8 cmp r3, r2 */
/* @0x2da8fc bhs 0x2da928 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2c4> */
/* @0x2da900 add r6, r6, #8 */
/* @0x2da904 cmp r11, r6 */
/* @0x2da908 bhi 0x2da8f4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x290> */
/* @0x2da90c ldr r3, [sp, #0xc] */
/* @0x2da910 cmp r11, r10 */
/* @0x2da914 add r3, r3, #8 */
/* @0x2da918 str r3, [sp, #0xc] */
/* @0x2da91c bls 0x2daae0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x47c> */
/* @0x2da920 add r10, r10, #8 */
/* @0x2da924 b 0x2da730 <_ZN16b2ParticleSystem14UpdateContactsEb+0xcc> */
/* @0x2da928 add r1, r1, #1048576 */
/* @0x2da92c add r1, r1, #256 */
/* @0x2da930 str r1, [sp, #0x8] */
/* @0x2da934 cmp r1, r3 */
/* @0x2da938 blo 0x2da90c <_ZN16b2ParticleSystem14UpdateContactsEb+0x2a8> */
/* @0x2da93c add r5, r6, #8 */
/* @0x2da940 str r6, [sp, #0x10] */
/* @0x2da944 b 0x2da9f4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x390> */
/* @0x2da948 orrmi r0, r0, #0 */
/* @0x2da94c .word 0x49000000 */
/* @0x2da950 strmi r0, [r0, #-0x0] */
/* @0x2da954 ldr r2, [r4, #0x7c] */
/* @0x2da958 vmov r0, s16 */
/* @0x2da95c vldr s14, [r4, #28] */
/* @0x2da960 vmul.f32 s15, s16, s21 */
/* @0x2da964 vmov.f32 s12, s20 */
/* @0x2da968 vmov.f32 s13, s19 */
/* @0x2da96c asr r3, r0, #1 */
/* @0x2da970 add r0, r1, r1, lsl #1 */
/* @0x2da974 rsb r3, r3, #1593835520 */
/* @0x2da978 add r1, r1, #1 */
/* @0x2da97c add r3, r3, #3620864 */
/* @0x2da980 str r6, [r2, r0, lsl #3] */
/* @0x2da984 add r3, r3, #6592 */
/* @0x2da988 add r2, r2, r0, lsl #3 */
/* @0x2da98c add r3, r3, #31 */
/* @0x2da990 ldr r0, [r4, #0x30] */
/* @0x2da994 str r7, [r2, #0x4] */
/* @0x2da998 vmov s9, r3 */
/* @0x2da99c ldr r12, [r0, r7, lsl #2] */
/* @0x2da9a0 vmul.f32 s15, s15, s9 */
/* @0x2da9a4 ldr r0, [r0, r6, lsl #2] */
/* @0x2da9a8 orr r0, r12, r0 */
/* @0x2da9ac str r0, [r2, #0x8] */
/* @0x2da9b0 vmls.f32 s12, s9, s15 */
/* @0x2da9b4 vmul.f32 s15, s9, s12 */
/* @0x2da9b8 vmul.f32 s16, s16, s15 */
/* @0x2da9bc vmls.f32 s13, s16, s14 */
/* @0x2da9c0 vmul.f32 s18, s18, s15 */
/* @0x2da9c4 vstr s13, [r2, #12] */
/* @0x2da9c8 vmul.f32 s17, s17, s15 */
/* @0x2da9cc vstr s18, [r2, #16] */
/* @0x2da9d0 vstr s17, [r2, #20] */
/* @0x2da9d4 str r1, [r4, #0x74] */
/* @0x2da9d8 cmp r11, r5 */
/* @0x2da9dc add r5, r5, #8 */
/* @0x2da9e0 bls 0x2daac4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x460> */
/* @0x2da9e4 ldr r3, [r5, #-0x4] */
/* @0x2da9e8 ldr r0, [sp, #0x8] */
/* @0x2da9ec cmp r3, r0 */
/* @0x2da9f0 bhi 0x2daac4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x460> */
/* @0x2da9f4 ldr r6, [r10, #-0x8] */
/* @0x2da9f8 vldr s15, [r4, #32] */
/* @0x2da9fc ldr r7, [r5, #-0x8] */
/* @0x2daa00 ldr r2, [r4, #0x38] */
/* @0x2daa04 add r3, r2, r6, lsl #3 */
/* @0x2daa08 add r2, r2, r7, lsl #3 */
/* @0x2daa0c vldr s14, [r3, #4] */
/* @0x2daa10 vldr s17, [r2, #4] */
/* @0x2daa14 vsub.f32 s17, s17, s14 */
/* @0x2daa18 vldr s18, [r2] */
/* @0x2daa1c vldr s14, [r3] */
/* @0x2daa20 vmul.f32 s16, s17, s17 */
/* @0x2daa24 vsub.f32 s18, s18, s14 */
/* @0x2daa28 vmla.f32 s16, s18, s18 */
/* @0x2daa2c vcmpe.f32 s16, s15 */
/* @0x2daa30 vmrs APSR_nzcv, fpscr */
/* @0x2daa34 bpl 0x2da9d8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x374> */
/* @0x2daa38 ldr r3, [r4, #0x74] */
/* @0x2daa3c ldr r12, [r4, #0x78] */
/* @0x2daa40 cmp r3, r12 */
/* @0x2daa44 mov r1, r3 */
/* @0x2daa48 blt 0x2da954 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2f0> */
/* @0x2daa4c lsl r8, r3, #1 */
/* @0x2daa50 cmp r3, #0 */
/* @0x2daa54 add r3, r8, r3, lsl #2 */
/* @0x2daa58 mov r1, #6144 */
/* @0x2daa5c ldr r0, [r4, #0xd4] */
/* @0x2daa60 moveq r8, #256 */
/* @0x2daa64 lslne r1, r3, #3 */
/* @0x2daa68 ldr r9, [r4, #0x7c] */
/* @0x2daa6c str r12, [sp, #0x4] */
/* @0x2daa70 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2daa74 ldr r12, [sp, #0x4] */
/* @0x2daa78 mov r1, r9 */
/* @0x2daa7c add r12, r12, r12, lsl #1 */
/* @0x2daa80 lsl r12, r12, #3 */
/* @0x2daa84 str r12, [sp, #0x4] */
/* @0x2daa88 mov r2, r12 */
/* @0x2daa8c bl 0xb65bc <memcpy@plt> */
/* @0x2daa90 ldr r12, [sp, #0x4] */
/* @0x2daa94 mov r1, r9 */
/* @0x2daa98 mov r2, r12 */
/* @0x2daa9c mov r3, r0 */
/* @0x2daaa0 ldr r0, [r4, #0xd4] */
/* @0x2daaa4 str r3, [sp, #0x4] */
/* @0x2daaa8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2daaac ldr r3, [sp, #0x4] */
/* @0x2daab0 ldr r1, [r4, #0x74] */
/* @0x2daab4 str r8, [r4, #0x78] */
/* @0x2daab8 mov r2, r3 */
/* @0x2daabc str r3, [r4, #0x7c] */
/* @0x2daac0 b 0x2da958 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2f4> */
/* @0x2daac4 ldr r6, [sp, #0x10] */
/* @0x2daac8 b 0x2da90c <_ZN16b2ParticleSystem14UpdateContactsEb+0x2a8> */
/* @0x2daacc mov r0, r6 */
/* @0x2daad0 mov r1, r11 */
/* @0x2daad4 bl 0x2da584 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_> */
/* @0x2daad8 mov r3, #0 */
/* @0x2daadc str r3, [r4, #0x74] */
/* @0x2daae0 ldr r3, [sp, #0x14] */
/* @0x2daae4 cmp r3, #0 */
/* @0x2daae8 bne 0x2daaf8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x494> */
/* @0x2daaec add sp, sp, #28 */
/* @0x2daaf0 vpop {d8, d9, d10} */
/* @0x2daaf4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2daaf8 ldr r9, [r4, #0x74] */
/* @0x2daafc ldr r8, [r4, #0x7c] */
/* @0x2dab00 add r9, r9, r9, lsl #1 */
/* @0x2dab04 sbfx r3, r9, #0x0, #0x1d */
/* @0x2dab08 add r9, r8, r9, lsl #3 */
/* @0x2dab0c add r11, r3, r3, lsl #2 */
/* @0x2dab10 add r11, r11, r11, lsl #4 */
/* @0x2dab14 add r11, r11, r11, lsl #8 */
/* @0x2dab18 add r11, r11, r11, lsl #16 */
/* @0x2dab1c add r11, r3, r11, lsl #1 */
/* @0x2dab20 asr r2, r11, #2 */
/* @0x2dab24 cmp r2, #0 */
/* @0x2dab28 ble 0x2dacb4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x650> */
/* @0x2dab2c ldr r3, [r8, #0x8] */
/* @0x2dab30 tst r3, #2 */
/* @0x2dab34 bne 0x2dacc0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x65c> */
/* @0x2dab38 ldr r3, [r8, #0x20] */
/* @0x2dab3c tst r3, #2 */
/* @0x2dab40 addne r12, r8, #24 */
/* @0x2dab44 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dab48 ldr r3, [r8, #0x38] */
/* @0x2dab4c tst r3, #2 */
/* @0x2dab50 addne r12, r8, #48 */
/* @0x2dab54 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dab58 ldr r3, [r8, #0x50] */
/* @0x2dab5c tst r3, #2 */
/* @0x2dab60 bne 0x2dacc8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x664> */
/* @0x2dab64 add r1, r8, #176 */
/* @0x2dab68 mov r0, r8 */
/* @0x2dab6c add r10, r8, #168 */
/* @0x2dab70 b 0x2daba8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x544> */
/* @0x2dab74 ldr r5, [r3, r5] */
/* @0x2dab78 tst r5, #2 */
/* @0x2dab7c bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dab80 ldr r5, [r3, r7] */
/* @0x2dab84 tst r5, #2 */
/* @0x2dab88 bne 0x2dac88 <_ZN16b2ParticleSystem14UpdateContactsEb+0x624> */
/* @0x2dab8c ldr r3, [r3, r6] */
/* @0x2dab90 tst r3, #2 */
/* @0x2dab94 bne 0x2dac80 <_ZN16b2ParticleSystem14UpdateContactsEb+0x61c> */
/* @0x2dab98 ldr r3, [r1], #96 */
/* @0x2dab9c tst r3, #2 */
/* @0x2daba0 bne 0x2dac78 <_ZN16b2ParticleSystem14UpdateContactsEb+0x614> */
/* @0x2daba4 mov r0, r12 */
/* @0x2daba8 subs r2, r2, #1 */
/* @0x2dabac rsb r3, r10, r1 */
/* @0x2dabb0 add r5, r8, #96 */
/* @0x2dabb4 add r7, r8, #120 */
/* @0x2dabb8 add r6, r8, #144 */
/* @0x2dabbc add r12, r0, #96 */
/* @0x2dabc0 bne 0x2dab74 <_ZN16b2ParticleSystem14UpdateContactsEb+0x510> */
/* @0x2dabc4 rsb r2, r12, r9 */
/* @0x2dabc8 asr r2, r2, #3 */
/* @0x2dabcc add r3, r2, r2, lsl #2 */
/* @0x2dabd0 add r3, r3, r3, lsl #4 */
/* @0x2dabd4 add r3, r3, r3, lsl #8 */
/* @0x2dabd8 add r3, r3, r3, lsl #16 */
/* @0x2dabdc add r3, r2, r3, lsl #1 */
/* @0x2dabe0 cmp r3, #2 */
/* @0x2dabe4 beq 0x2daca0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x63c> */
/* @0x2dabe8 cmp r3, #3 */
/* @0x2dabec beq 0x2dac90 <_ZN16b2ParticleSystem14UpdateContactsEb+0x62c> */
/* @0x2dabf0 cmp r3, #1 */
/* @0x2dabf4 bne 0x2dac68 <_ZN16b2ParticleSystem14UpdateContactsEb+0x604> */
/* @0x2dabf8 ldr r3, [r12, #0x8] */
/* @0x2dabfc tst r3, #2 */
/* @0x2dac00 beq 0x2dac68 <_ZN16b2ParticleSystem14UpdateContactsEb+0x604> */
/* @0x2dac04 cmp r9, r12 */
/* @0x2dac08 beq 0x2dac68 <_ZN16b2ParticleSystem14UpdateContactsEb+0x604> */
/* @0x2dac0c add r5, r12, #24 */
/* @0x2dac10 cmp r9, r5 */
/* @0x2dac14 beq 0x2dac4c <_ZN16b2ParticleSystem14UpdateContactsEb+0x5e8> */
/* @0x2dac18 ldr r3, [r5, #0x8] */
/* @0x2dac1c mov r7, r5 */
/* @0x2dac20 mov r6, r12 */
/* @0x2dac24 add r5, r5, #24 */
/* @0x2dac28 tst r3, #2 */
/* @0x2dac2c bne 0x2dac10 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5ac> */
/* @0x2dac30 ldm r7!, {r0, r1, r2, r3} */
/* @0x2dac34 cmp r9, r5 */
/* @0x2dac38 add r12, r12, #24 */
/* @0x2dac3c stm r6!, {r0, r1, r2, r3} */
/* @0x2dac40 ldm r7, {r0, r1} */
/* @0x2dac44 stm r6, {r0, r1} */
/* @0x2dac48 bne 0x2dac18 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5b4> */
/* @0x2dac4c rsb r3, r8, r12 */
/* @0x2dac50 asr r3, r3, #3 */
/* @0x2dac54 add r11, r3, r3, lsl #2 */
/* @0x2dac58 add r11, r11, r11, lsl #4 */
/* @0x2dac5c add r11, r11, r11, lsl #8 */
/* @0x2dac60 add r11, r11, r11, lsl #16 */
/* @0x2dac64 add r11, r3, r11, lsl #1 */
/* @0x2dac68 str r11, [r4, #0x74] */
/* @0x2dac6c add sp, sp, #28 */
/* @0x2dac70 vpop {d8, d9, d10} */
/* @0x2dac74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2dac78 add r12, r0, #168 */
/* @0x2dac7c b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dac80 add r12, r0, #144 */
/* @0x2dac84 b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dac88 add r12, r0, #120 */
/* @0x2dac8c b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dac90 ldr r3, [r12, #0x8] */
/* @0x2dac94 tst r3, #2 */
/* @0x2dac98 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dac9c add r12, r12, #24 */
/* @0x2daca0 ldr r3, [r12, #0x8] */
/* @0x2daca4 tst r3, #2 */
/* @0x2daca8 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dacac add r12, r12, #24 */
/* @0x2dacb0 b 0x2dabf8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x594> */
/* @0x2dacb4 mov r3, r11 */
/* @0x2dacb8 mov r12, r8 */
/* @0x2dacbc b 0x2dabe0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x57c> */
/* @0x2dacc0 mov r12, r8 */
/* @0x2dacc4 b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */
/* @0x2dacc8 add r12, r8, #72 */
/* @0x2daccc b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0> */

/* ── FUNC 0x2dacd0 · b2ParticleSystem::CreateParticleGroup(b2ParticleGroupDef const&) · size=1696 · insn=424 */
/* @0x2dacd0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2dacd4 vpush {d8, d9, d10, d11, d12} */
/* @0x2dacd8 sub sp, sp, #116 */
/* @0x2dacdc vldr s20, [pc, #868] */
/* @0x2dace0 mov r7, r1 */
/* @0x2dace4 mov r9, r0 */
/* @0x2dace8 bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv> */
/* @0x2dacec vmov.f32 s21, #1.000000e+00 */
/* @0x2dacf0 ldr r4, [r7, #0x28] */
/* @0x2dacf4 vstr s20, [sp, #36] */
/* @0x2dacf8 ldr r1, [r9, #0x24] */
/* @0x2dacfc vstr s20, [sp, #40] */
/* @0x2dad00 cmp r4, #0 */
/* @0x2dad04 vstr s20, [sp, #44] */
/* @0x2dad08 str r1, [sp, #0xc] */
/* @0x2dad0c vstr s21, [sp, #48] */
/* @0x2dad10 vmov s18, r0 */
/* @0x2dad14 beq 0x2db1d8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x508> */
/* @0x2dad18 ldr r3, [pc, #0x32c] */
/* @0x2dad1c add r5, sp, #88 */
/* @0x2dad20 ldr r6, [r7, #0x10] */
/* @0x2dad24 vldr s23, [r7, #8] */
/* @0x2dad28 ldr r3, [pc, r3] */
/* @0x2dad2c ldr lr, [r7] */
/* @0x2dad30 ldr r12, [r7, #0x20] */
/* @0x2dad34 vldr s22, [r7, #12] */
/* @0x2dad38 ldm r3, {r0, r1} */
/* @0x2dad3c add r3, sp, #96 */
/* @0x2dad40 ldr r2, [r7, #0x30] */
/* @0x2dad44 str lr, [sp, #0x54] */
/* @0x2dad48 stm r3, {r0, r1} */
/* @0x2dad4c stm r5, {r0, r1} */
/* @0x2dad50 mov r0, r6 */
/* @0x2dad54 str r12, [sp, #0x68] */
/* @0x2dad58 str r2, [sp, #0x6c] */
/* @0x2dad5c bl 0xb6580 <sinf@plt> */
/* @0x2dad60 vmov s20, r0 */
/* @0x2dad64 mov r0, r6 */
/* @0x2dad68 bl 0xb658c <cosf@plt> */
/* @0x2dad6c ldr r3, [r4] */
/* @0x2dad70 ldr r3, [r3, #0xc] */
/* @0x2dad74 vmov s21, r0 */
/* @0x2dad78 mov r0, r4 */
/* @0x2dad7c blx r3 */
/* @0x2dad80 subs r11, r0, #0 */
/* @0x2dad84 ble 0x2dae2c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x15c> */
/* @0x2dad88 add r8, sp, #36 */
/* @0x2dad8c add r10, sp, #68 */
/* @0x2dad90 mov r6, #0 */
/* @0x2dad94 add r1, sp, #52 */
/* @0x2dad98 str r1, [sp, #0x10] */
/* @0x2dad9c cmp r6, #0 */
/* @0x2dada0 mov r3, r6 */
/* @0x2dada4 mov r0, r4 */
/* @0x2dada8 mov r1, r10 */
/* @0x2dadac mov r2, r8 */
/* @0x2dadb0 ldr r12, [r4] */
/* @0x2dadb4 beq 0x2db360 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x690> */
/* @0x2dadb8 ldr r12, [r12, #0x1c] */
/* @0x2dadbc blx r12 */
/* @0x2dadc0 vldr s8, [sp, #52] */
/* @0x2dadc4 vldr s9, [sp, #68] */
/* @0x2dadc8 vcmpe.f32 s8, s9 */
/* @0x2dadcc vldr s10, [sp, #56] */
/* @0x2dadd0 vldr s11, [sp, #72] */
/* @0x2dadd4 vldr s12, [sp, #60] */
/* @0x2dadd8 vldr s13, [sp, #76] */
/* @0x2daddc vldr s14, [sp, #64] */
/* @0x2dade0 vldr s15, [sp, #80] */
/* @0x2dade4 vmrs APSR_nzcv, fpscr */
/* @0x2dade8 vcmpe.f32 s10, s11 */
/* @0x2dadec vmovmi.f32 s9, s8 */
/* @0x2dadf0 vmrs APSR_nzcv, fpscr */
/* @0x2dadf4 vstr s9, [sp, #52] */
/* @0x2dadf8 vcmpe.f32 s12, s13 */
/* @0x2dadfc vmovmi.f32 s11, s10 */
/* @0x2dae00 vmrs APSR_nzcv, fpscr */
/* @0x2dae04 vstr s11, [sp, #56] */
/* @0x2dae08 vcmpe.f32 s14, s15 */
/* @0x2dae0c vmovgt.f32 s13, s12 */
/* @0x2dae10 vmrs APSR_nzcv, fpscr */
/* @0x2dae14 vstr s13, [sp, #60] */
/* @0x2dae18 vmovgt.f32 s15, s14 */
/* @0x2dae1c vstr s15, [sp, #64] */
/* @0x2dae20 add r6, r6, #1 */
/* @0x2dae24 cmp r6, r11 */
/* @0x2dae28 bne 0x2dad9c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0xcc> */
/* @0x2dae2c vldr s15, [sp, #56] */
/* @0x2dae30 vdiv.f32 s15, s15, s18 */
/* @0x2dae34 vmov r0, s15 */
/* @0x2dae38 bl 0xb6910 <floorf@plt> */
/* @0x2dae3c vldr s24, [sp, #64] */
/* @0x2dae40 vmov s15, r0 */
/* @0x2dae44 vmul.f32 s19, s15, s18 */
/* @0x2dae48 vcmpe.f32 s19, s24 */
/* @0x2dae4c vmrs APSR_nzcv, fpscr */
/* @0x2dae50 bpl 0x2daf48 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x278> */
/* @0x2dae54 add r8, sp, #36 */
/* @0x2dae58 add r6, sp, #68 */
/* @0x2dae5c add r10, sp, #84 */
/* @0x2dae60 vldr s17, [sp, #60] */
/* @0x2dae64 vldr s15, [sp, #52] */
/* @0x2dae68 vdiv.f32 s15, s15, s18 */
/* @0x2dae6c vmov r0, s15 */
/* @0x2dae70 bl 0xb6910 <floorf@plt> */
/* @0x2dae74 vmov s15, r0 */
/* @0x2dae78 vmul.f32 s16, s15, s18 */
/* @0x2dae7c vcmpe.f32 s16, s17 */
/* @0x2dae80 vmrs APSR_nzcv, fpscr */
/* @0x2dae84 bmi 0x2daea0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x1d0> */
/* @0x2dae88 b 0x2daf38 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x268> */
/* @0x2dae8c vadd.f32 s16, s16, s18 */
/* @0x2dae90 vldr s17, [sp, #60] */
/* @0x2dae94 vcmpe.f32 s17, s16 */
/* @0x2dae98 vmrs APSR_nzcv, fpscr */
/* @0x2dae9c ble 0x2daf34 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x264> */
/* @0x2daea0 ldr r3, [r4] */
/* @0x2daea4 mov r0, r4 */
/* @0x2daea8 vstr s16, [sp, #68] */
/* @0x2daeac mov r1, r8 */
/* @0x2daeb0 vstr s19, [sp, #72] */
/* @0x2daeb4 mov r2, r6 */
/* @0x2daeb8 ldr r3, [r3, #0x10] */
/* @0x2daebc blx r3 */
/* @0x2daec0 cmp r0, #0 */
/* @0x2daec4 beq 0x2dae8c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x1bc> */
/* @0x2daec8 vldr s13, [sp, #72] */
/* @0x2daecc vmul.f32 s12, s13, s20 */
/* @0x2daed0 vldr s10, [sp, #68] */
/* @0x2daed4 vldr s8, [r7, #8] */
/* @0x2daed8 vldr s9, [r7, #12] */
/* @0x2daedc vldr s11, [r7, #28] */
/* @0x2daee0 vldr s14, [r7, #24] */
/* @0x2daee4 vldr s15, [r7, #20] */
/* @0x2daee8 vmul.f32 s13, s13, s21 */
/* @0x2daeec vnmls.f32 s12, s10, s21 */
/* @0x2daef0 vmla.f32 s13, s10, s20 */
/* @0x2daef4 vadd.f32 s12, s12, s23 */
/* @0x2daef8 vadd.f32 s13, s13, s22 */
/* @0x2daefc vstr s12, [sp, #68] */
/* @0x2daf00 vstr s13, [sp, #72] */
/* @0x2daf04 vsub.f32 s12, s12, s8 */
/* @0x2daf08 ldm r6, {r0, r1} */
/* @0x2daf0c stm r5, {r0, r1} */
/* @0x2daf10 mov r0, r9 */
/* @0x2daf14 mov r1, r10 */
/* @0x2daf18 vsub.f32 s13, s13, s9 */
/* @0x2daf1c vmla.f32 s14, s11, s12 */
/* @0x2daf20 vmls.f32 s15, s11, s13 */
/* @0x2daf24 vstr s14, [sp, #100] */
/* @0x2daf28 vstr s15, [sp, #96] */
/* @0x2daf2c bl 0x2da108 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef> */
/* @0x2daf30 b 0x2dae8c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x1bc> */
/* @0x2daf34 vldr s24, [sp, #64] */
/* @0x2daf38 vadd.f32 s19, s19, s18 */
/* @0x2daf3c vcmpe.f32 s24, s19 */
/* @0x2daf40 vmrs APSR_nzcv, fpscr */
/* @0x2daf44 bgt 0x2dae64 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x194> */
/* @0x2daf48 ldr r10, [r9, #0x24] */
/* @0x2daf4c ldr r0, [r9, #0xd4] */
/* @0x2daf50 mov r1, #84 */
/* @0x2daf54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2daf58 subs r11, r0, #0 */
/* @0x2daf5c beq 0x2daf64 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x294> */
/* @0x2daf60 bl 0x2d4560 <_ZN15b2ParticleGroupC2Ev> */
/* @0x2daf64 ldr lr, [r7, #0x24] */
/* @0x2daf68 mov r1, #0 */
/* @0x2daf6c ldr r4, [sp, #0xc] */
/* @0x2daf70 ldr r3, [r9, #0xa8] */
/* @0x2daf74 ldr r12, [r7, #0x4] */
/* @0x2daf78 ldr r0, [r7, #0x30] */
/* @0x2daf7c cmp r3, r1 */
/* @0x2daf80 ldrb r2, [r11, #0x4c] */
/* @0x2daf84 str lr, [r11, #0x10] */
/* @0x2daf88 ldrb lr, [r7, #0x2c] */
/* @0x2daf8c vstr s23, [r11, #60] */
/* @0x2daf90 str r4, [r11, #0x4] */
/* @0x2daf94 vstr s22, [r11, #64] */
/* @0x2daf98 ldr r4, [sp, #0xc] */
/* @0x2daf9c vstr s20, [r11, #68] */
/* @0x2dafa0 str r3, [r11, #0x18] */
/* @0x2dafa4 vstr s21, [r11, #72] */
/* @0x2dafa8 str r9, [r11] */
/* @0x2dafac bfi r2, lr, #0, #1 */
/* @0x2dafb0 str r10, [r11, #0x8] */
/* @0x2dafb4 str r12, [r11, #0xc] */
/* @0x2dafb8 strb r2, [r11, #0x4c] */
/* @0x2dafbc str r0, [r11, #0x50] */
/* @0x2dafc0 str r1, [r11, #0x14] */
/* @0x2dafc4 strne r11, [r3, #0x14] */
/* @0x2dafc8 cmp r4, r10 */
/* @0x2dafcc ldr r3, [r9, #0xa4] */
/* @0x2dafd0 str r11, [r9, #0xa8] */
/* @0x2dafd4 add r3, r3, #1 */
/* @0x2dafd8 str r3, [r9, #0xa4] */
/* @0x2dafdc bge 0x2db004 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x334> */
/* @0x2dafe0 ldr r4, [sp, #0xc] */
/* @0x2dafe4 lsl r2, r4, #2 */
/* @0x2dafe8 mov r3, r4 */
/* @0x2dafec add r3, r3, #1 */
/* @0x2daff0 ldr r1, [r9, #0x5c] */
/* @0x2daff4 cmp r3, r10 */
/* @0x2daff8 str r11, [r1, r2] */
/* @0x2daffc add r2, r2, #4 */
/* @0x2db000 bne 0x2dafec <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x31c> */
/* @0x2db004 mov r0, r9 */
/* @0x2db008 mov r1, #1 */
/* @0x2db00c bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2db010 ldr r3, [r7] */
/* @0x2db014 tst r3, #8 */
/* @0x2db018 beq 0x2db1a8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4d8> */
/* @0x2db01c ldr r0, [r9, #0x74] */
/* @0x2db020 cmp r0, #0 */
/* @0x2db024 ble 0x2db1a8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4d8> */
/* @0x2db028 mov r12, #0 */
/* @0x2db02c str r11, [sp, #0x1c] */
/* @0x2db030 mov r6, r12 */
/* @0x2db034 mov r5, r12 */
/* @0x2db038 ldr r11, [sp, #0xc] */
/* @0x2db03c mov r12, r7 */
/* @0x2db040 str r10, [sp, #0x10] */
/* @0x2db044 b 0x2db0cc <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3fc> */
/* @0x2db048 andeq r0, r0, r0 */
/* @0x2db04c ldrheq r6, [r1], -r0 */
/* @0x2db050 ldr r3, [r9, #0x94] */
/* @0x2db054 ldr r0, [r9, #0x38] */
/* @0x2db058 add r7, r2, r2, lsl #2 */
/* @0x2db05c ldr r10, [r10, #0x8] */
/* @0x2db060 add r1, r0, r4, lsl #3 */
/* @0x2db064 add r0, r0, r8, lsl #3 */
/* @0x2db068 vldr s14, [r1, #4] */
/* @0x2db06c vldr s15, [r0, #4] */
/* @0x2db070 vsub.f32 s14, s14, s15 */
/* @0x2db074 vldr s13, [r1] */
/* @0x2db078 vldr s15, [r0] */
/* @0x2db07c str r4, [r3, r7, lsl #2] */
/* @0x2db080 add r7, r3, r7, lsl #2 */
/* @0x2db084 ldr r3, [r12, #0x24] */
/* @0x2db088 stmib r7, {r8, r10} */
/* @0x2db08c str r3, [r7, #0xc] */
/* @0x2db090 vmul.f32 s14, s14, s14 */
/* @0x2db094 vsub.f32 s15, s13, s15 */
/* @0x2db098 vmla.f32 s14, s15, s15 */
/* @0x2db09c vsqrt.f32 s15, s14 */
/* @0x2db0a0 vcmp.f32 s15, s15 */
/* @0x2db0a4 vmrs APSR_nzcv, fpscr */
/* @0x2db0a8 bne 0x2db344 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x674> */
/* @0x2db0ac ldr r0, [r9, #0x74] */
/* @0x2db0b0 add r2, r2, #1 */
/* @0x2db0b4 vstr s15, [r7, #16] */
/* @0x2db0b8 str r2, [r9, #0x8c] */
/* @0x2db0bc add r6, r6, #1 */
/* @0x2db0c0 add r5, r5, #24 */
/* @0x2db0c4 cmp r0, r6 */
/* @0x2db0c8 ble 0x2db198 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4c8> */
/* @0x2db0cc ldr r3, [r9, #0x7c] */
/* @0x2db0d0 add r10, r3, r5 */
/* @0x2db0d4 ldr r8, [r3, r5] */
/* @0x2db0d8 ldr r4, [r10, #0x4] */
/* @0x2db0dc cmp r8, r4 */
/* @0x2db0e0 movle r3, r4 */
/* @0x2db0e4 movle r4, r8 */
/* @0x2db0e8 movle r8, r3 */
/* @0x2db0ec cmp r11, r4 */
/* @0x2db0f0 bgt 0x2db0bc <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3ec> */
/* @0x2db0f4 ldr r3, [sp, #0x10] */
/* @0x2db0f8 cmp r8, r3 */
/* @0x2db0fc bge 0x2db0bc <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3ec> */
/* @0x2db100 ldr r2, [r9, #0x8c] */
/* @0x2db104 ldr r3, [r9, #0x90] */
/* @0x2db108 cmp r2, r3 */
/* @0x2db10c blt 0x2db050 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x380> */
/* @0x2db110 cmp r2, #0 */
/* @0x2db114 ldr r0, [r9, #0xd4] */
/* @0x2db118 lslne r1, r2, #1 */
/* @0x2db11c strne r1, [sp, #0x18] */
/* @0x2db120 addne r2, r1, r2, lsl #3 */
/* @0x2db124 moveq r2, #256 */
/* @0x2db128 streq r2, [sp, #0x18] */
/* @0x2db12c moveq r1, #5120 */
/* @0x2db130 lslne r1, r2, #2 */
/* @0x2db134 ldr r2, [r9, #0x94] */
/* @0x2db138 str r12, [sp, #0x4] */
/* @0x2db13c str r3, [sp, #0x8] */
/* @0x2db140 str r2, [sp, #0x14] */
/* @0x2db144 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2db148 ldr r3, [sp, #0x8] */
/* @0x2db14c ldr r1, [sp, #0x14] */
/* @0x2db150 add r3, r3, r3, lsl #2 */
/* @0x2db154 lsl r3, r3, #2 */
/* @0x2db158 str r3, [sp, #0x8] */
/* @0x2db15c mov r2, r3 */
/* @0x2db160 mov r7, r0 */
/* @0x2db164 bl 0xb65bc <memcpy@plt> */
/* @0x2db168 ldr r3, [sp, #0x8] */
/* @0x2db16c ldr r1, [sp, #0x14] */
/* @0x2db170 ldr r0, [r9, #0xd4] */
/* @0x2db174 mov r2, r3 */
/* @0x2db178 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2db17c ldr r1, [sp, #0x18] */
/* @0x2db180 ldr r2, [r9, #0x8c] */
/* @0x2db184 mov r3, r7 */
/* @0x2db188 str r7, [r9, #0x94] */
/* @0x2db18c str r1, [r9, #0x90] */
/* @0x2db190 ldr r12, [sp, #0x4] */
/* @0x2db194 b 0x2db054 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x384> */
/* @0x2db198 ldr r11, [sp, #0x1c] */
/* @0x2db19c mov r7, r12 */
/* @0x2db1a0 ldr r10, [sp, #0x10] */
/* @0x2db1a4 ldr r3, [r12] */
/* @0x2db1a8 tst r3, #16 */
/* @0x2db1ac bne 0x2db1e8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x518> */
/* @0x2db1b0 ldr r3, [r7, #0x4] */
/* @0x2db1b4 tst r3, #1 */
/* @0x2db1b8 beq 0x2db1c8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4f8> */
/* @0x2db1bc mov r0, r9 */
/* @0x2db1c0 mov r1, r11 */
/* @0x2db1c4 bl 0x2d5920 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup> */
/* @0x2db1c8 mov r0, r11 */
/* @0x2db1cc add sp, sp, #116 */
/* @0x2db1d0 vpop {d8, d9, d10, d11, d12} */
/* @0x2db1d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2db1d8 ldr r10, [sp, #0xc] */
/* @0x2db1dc vmov.f32 s22, s20 */
/* @0x2db1e0 vmov.f32 s23, s20 */
/* @0x2db1e4 b 0x2daf4c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x27c> */
/* @0x2db1e8 add r4, sp, #84 */
/* @0x2db1ec ldr r1, [r9, #0xd4] */
/* @0x2db1f0 str r4, [sp, #0x10] */
/* @0x2db1f4 add r0, sp, #84 */
/* @0x2db1f8 ldr r4, [sp, #0xc] */
/* @0x2db1fc add r1, r1, #68 */
/* @0x2db200 rsb r2, r4, r10 */
/* @0x2db204 bl 0x2dbb2c <_ZN16b2VoronoiDiagramC2EP16b2StackAllocatori> */
/* @0x2db208 cmp r4, r10 */
/* @0x2db20c bge 0x2db240 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x570> */
/* @0x2db210 ldr r4, [sp, #0xc] */
/* @0x2db214 add r6, sp, #84 */
/* @0x2db218 lsl r5, r4, #3 */
/* @0x2db21c ldr r1, [r9, #0x38] */
/* @0x2db220 mov r2, r4 */
/* @0x2db224 mov r0, r6 */
/* @0x2db228 add r4, r4, #1 */
/* @0x2db22c add r1, r1, r5 */
/* @0x2db230 add r5, r5, #8 */
/* @0x2db234 bl 0x2dbb94 <_ZN16b2VoronoiDiagram12AddGeneratorERK6b2Vec2i> */
/* @0x2db238 cmp r4, r10 */
/* @0x2db23c bne 0x2db21c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x54c> */
/* @0x2db240 vmov.f32 s15, #5.000000e-01 */
/* @0x2db244 add r0, sp, #84 */
/* @0x2db248 vmul.f32 s15, s18, s15 */
/* @0x2db24c vmov r1, s15 */
/* @0x2db250 bl 0x2dbbc4 <_ZN16b2VoronoiDiagram8GenerateEf> */
/* @0x2db254 ldr r3, [sp, #0x64] */
/* @0x2db258 ldr r4, [sp, #0xc] */
/* @0x2db25c cmp r3, #1 */
/* @0x2db260 str r9, [sp, #0x44] */
/* @0x2db264 str r7, [sp, #0x48] */
/* @0x2db268 str r4, [sp, #0x4c] */
/* @0x2db26c ble 0x2db338 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x668> */
/* @0x2db270 ldr r1, [sp, #0x60] */
/* @0x2db274 add r8, sp, #68 */
/* @0x2db278 mov r10, #0 */
/* @0x2db27c str r7, [sp, #0xc] */
/* @0x2db280 cmp r1, #1 */
/* @0x2db284 ble 0x2db324 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x654> */
/* @0x2db288 mov r6, #0 */
/* @0x2db28c b 0x2db2b0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5e0> */
/* @0x2db290 cmp r4, r7 */
/* @0x2db294 cmpne r5, r7 */
/* @0x2db298 bne 0x2db308 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x638> */
/* @0x2db29c ldr r1, [sp, #0x60] */
/* @0x2db2a0 add r6, r6, #1 */
/* @0x2db2a4 sub r3, r1, #1 */
/* @0x2db2a8 cmp r6, r3 */
/* @0x2db2ac bge 0x2db320 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x650> */
/* @0x2db2b0 mla r2, r1, r10, r6 */
/* @0x2db2b4 ldr r3, [sp, #0x68] */
/* @0x2db2b8 add r0, r1, r2 */
/* @0x2db2bc add r12, r0, #1 */
/* @0x2db2c0 add lr, r3, r2, lsl #2 */
/* @0x2db2c4 ldr r4, [r3, r0, lsl #2] */
/* @0x2db2c8 ldr r2, [r3, r2, lsl #2] */
/* @0x2db2cc ldr r5, [lr, #0x4] */
/* @0x2db2d0 ldr r7, [r3, r12, lsl #2] */
/* @0x2db2d4 cmp r5, r4 */
/* @0x2db2d8 beq 0x2db2a0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5d0> */
/* @0x2db2dc cmp r2, r4 */
/* @0x2db2e0 cmpne r2, r5 */
/* @0x2db2e4 beq 0x2db290 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5c0> */
/* @0x2db2e8 ldr r1, [r2, #0x8] */
/* @0x2db2ec mov r0, r8 */
/* @0x2db2f0 ldr r2, [r5, #0x8] */
/* @0x2db2f4 ldr r3, [r4, #0x8] */
/* @0x2db2f8 bl 0x2d5308 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii> */
/* @0x2db2fc cmp r4, r7 */
/* @0x2db300 cmpne r5, r7 */
/* @0x2db304 beq 0x2db29c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5cc> */
/* @0x2db308 ldr r1, [r5, #0x8] */
/* @0x2db30c mov r0, r8 */
/* @0x2db310 ldr r2, [r7, #0x8] */
/* @0x2db314 ldr r3, [r4, #0x8] */
/* @0x2db318 bl 0x2d5308 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii> */
/* @0x2db31c b 0x2db29c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5cc> */
/* @0x2db320 ldr r3, [sp, #0x64] */
/* @0x2db324 add r10, r10, #1 */
/* @0x2db328 sub r2, r3, #1 */
/* @0x2db32c cmp r10, r2 */
/* @0x2db330 blt 0x2db280 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5b0> */
/* @0x2db334 ldr r7, [sp, #0xc] */
/* @0x2db338 add r0, sp, #84 */
/* @0x2db33c bl 0x2dbb68 <_ZN16b2VoronoiDiagramD2Ev> */
/* @0x2db340 b 0x2db1b0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4e0> */
/* @0x2db344 vmov r0, s14 */
/* @0x2db348 str r12, [sp, #0x4] */
/* @0x2db34c bl 0xb6700 <sqrtf@plt> */
/* @0x2db350 ldr r2, [r9, #0x8c] */
/* @0x2db354 ldr r12, [sp, #0x4] */
/* @0x2db358 vmov s15, r0 */
/* @0x2db35c b 0x2db0ac <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3dc> */
/* @0x2db360 add r1, sp, #52 */
/* @0x2db364 ldr r12, [r12, #0x1c] */
/* @0x2db368 blx r12 */
/* @0x2db36c b 0x2dae20 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x150> */

/* ── FUNC 0x2db370 · b2ParticleSystem::Solve(b2TimeStep const&) · size=816 · insn=204 */
/* @0x2db370 push {r3, r4, r5, r6, r7, lr} */
/* @0x2db374 vpush {d8, d9} */
/* @0x2db378 mov r5, r0 */
/* @0x2db37c ldr r0, [r0, #0x24] */
/* @0x2db380 mov r7, r1 */
/* @0x2db384 ldr r3, [r5] */
/* @0x2db388 cmp r0, #0 */
/* @0x2db38c add r3, r3, #1 */
/* @0x2db390 str r3, [r5] */
/* @0x2db394 beq 0x2db598 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x228> */
/* @0x2db398 mov r1, #0 */
/* @0x2db39c str r1, [r5, #0x4] */
/* @0x2db3a0 ble 0x2db3cc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x5c> */
/* @0x2db3a4 ldr r3, [r5, #0x30] */
/* @0x2db3a8 add r0, r3, r0, lsl #2 */
/* @0x2db3ac ldr r2, [r3], #4 */
/* @0x2db3b0 orr r2, r2, r1 */
/* @0x2db3b4 cmp r3, r0 */
/* @0x2db3b8 str r2, [r5, #0x4] */
/* @0x2db3bc mov r1, r2 */
/* @0x2db3c0 bne 0x2db3ac <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x3c> */
/* @0x2db3c4 tst r2, #2 */
/* @0x2db3c8 bne 0x2db5b0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x240> */
/* @0x2db3cc ldr r3, [r5, #0xa8] */
/* @0x2db3d0 mov r1, #0 */
/* @0x2db3d4 str r1, [r5, #0x8] */
/* @0x2db3d8 cmp r3, r1 */
/* @0x2db3dc beq 0x2db3fc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x8c> */
/* @0x2db3e0 ldr r2, [r3, #0xc] */
/* @0x2db3e4 ldr r3, [r3, #0x18] */
/* @0x2db3e8 orr r2, r1, r2 */
/* @0x2db3ec cmp r3, #0 */
/* @0x2db3f0 mov r1, r2 */
/* @0x2db3f4 bne 0x2db3e0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x70> */
/* @0x2db3f8 str r2, [r5, #0x8] */
/* @0x2db3fc vldr s15, [r5, #20] */
/* @0x2db400 vldr s18, [r7] */
/* @0x2db404 vmul.f32 s18, s18, s15 */
/* @0x2db408 ldr r3, [r5, #0xd4] */
/* @0x2db40c mov r0, r5 */
/* @0x2db410 mov r1, r7 */
/* @0x2db414 add r2, r3, #102400 */
/* @0x2db418 vldr s17, [r2, #568] */
/* @0x2db41c mov r3, r2 */
/* @0x2db420 vldr s15, [r3, #572] */
/* @0x2db424 vmul.f32 s17, s18, s17 */
/* @0x2db428 vmul.f32 s18, s18, s15 */
/* @0x2db42c bl 0x2d856c <_ZNK16b2ParticleSystem26GetCriticalVelocitySquaredERK10b2TimeStep> */
/* @0x2db430 ldr r3, [r5, #0x24] */
/* @0x2db434 cmp r3, #0 */
/* @0x2db438 movgt r6, #0 */
/* @0x2db43c vmov s16, r0 */
/* @0x2db440 bgt 0x2db55c <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1ec> */
/* @0x2db444 mov r0, r5 */
/* @0x2db448 mov r1, r7 */
/* @0x2db44c bl 0x2d5cc0 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep> */
/* @0x2db450 ldr r3, [r5, #0x8] */
/* @0x2db454 tst r3, #2 */
/* @0x2db458 bne 0x2db650 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2e0> */
/* @0x2db45c ldr r3, [r5, #0x4] */
/* @0x2db460 tst r3, #4 */
/* @0x2db464 bne 0x2db668 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2f8> */
/* @0x2db468 ldr r1, [r5, #0x24] */
/* @0x2db46c cmp r1, #0 */
/* @0x2db470 ble 0x2db4b8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x148> */
/* @0x2db474 ldr r2, [r5, #0x40] */
/* @0x2db478 vldr s13, [r7] */
/* @0x2db47c ldr r3, [r5, #0x38] */
/* @0x2db480 add r1, r2, r1, lsl #3 */
/* @0x2db484 vldr s11, [r2, #4] */
/* @0x2db488 vldr s14, [r3, #4] */
/* @0x2db48c vldr s15, [r3] */
/* @0x2db490 mov r0, r2 */
/* @0x2db494 vmla.f32 s14, s13, s11 */
/* @0x2db498 vldr s12, [r0] */
/* @0x2db49c add r2, r2, #8 */
/* @0x2db4a0 add r3, r3, #8 */
/* @0x2db4a4 cmp r2, r1 */
/* @0x2db4a8 vmla.f32 s15, s13, s12 */
/* @0x2db4ac vstr s14, [r3, #-4] */
/* @0x2db4b0 vstr s15, [r3, #-8] */
/* @0x2db4b4 bne 0x2db484 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x114> */
/* @0x2db4b8 mov r0, r5 */
/* @0x2db4bc bl 0x2d5b9c <_ZN16b2ParticleSystem18UpdateBodyContactsEv> */
/* @0x2db4c0 mov r0, r5 */
/* @0x2db4c4 mov r1, #0 */
/* @0x2db4c8 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2db4cc ldr r3, [r5, #0x4] */
/* @0x2db4d0 tst r3, #32 */
/* @0x2db4d4 bne 0x2db5bc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x24c> */
/* @0x2db4d8 tst r3, #64 */
/* @0x2db4dc bne 0x2db5d4 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x264> */
/* @0x2db4e0 tst r3, #128 */
/* @0x2db4e4 bne 0x2db5ec <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x27c> */
/* @0x2db4e8 tst r3, #16 */
/* @0x2db4ec bne 0x2db604 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x294> */
/* @0x2db4f0 tst r3, #8 */
/* @0x2db4f4 bne 0x2db61c <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2ac> */
/* @0x2db4f8 ldr r3, [r5, #0x8] */
/* @0x2db4fc tst r3, #1 */
/* @0x2db500 bne 0x2db634 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x2c4> */
/* @0x2db504 ldr r3, [r5, #0x4] */
/* @0x2db508 tst r3, #256 */
/* @0x2db50c bne 0x2db5a0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x230> */
/* @0x2db510 mov r0, r5 */
/* @0x2db514 mov r1, r7 */
/* @0x2db518 bl 0x2d90a4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep> */
/* @0x2db51c vpop {d8, d9} */
/* @0x2db520 mov r0, r5 */
/* @0x2db524 mov r1, r7 */
/* @0x2db528 pop {r3, r4, r5, r6, r7, lr} */
/* @0x2db52c b 0x2d8a44 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep> */
/* @0x2db530 vdiv.f32 s13, s16, s13 */
/* @0x2db534 vsqrt.f32 s12, s13 */
/* @0x2db538 vcmp.f32 s12, s12 */
/* @0x2db53c vmrs APSR_nzcv, fpscr */
/* @0x2db540 bne 0x2db684 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x314> */
/* @0x2db544 vmul.f32 s14, s14, s12 */
/* @0x2db548 vmul.f32 s15, s15, s12 */
/* @0x2db54c vstr s14, [r4] */
/* @0x2db550 vstr s15, [r4, #4] */
/* @0x2db554 cmp r3, r6 */
/* @0x2db558 ble 0x2db444 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0xd4> */
/* @0x2db55c ldr r4, [r5, #0x40] */
/* @0x2db560 add r4, r4, r6, lsl #3 */
/* @0x2db564 vldr s15, [r4, #4] */
/* @0x2db568 vadd.f32 s15, s18, s15 */
/* @0x2db56c vldr s14, [r4] */
/* @0x2db570 add r6, r6, #1 */
/* @0x2db574 vmul.f32 s13, s15, s15 */
/* @0x2db578 vstr s15, [r4, #4] */
/* @0x2db57c vadd.f32 s14, s17, s14 */
/* @0x2db580 vmla.f32 s13, s14, s14 */
/* @0x2db584 vstr s14, [r4] */
/* @0x2db588 vcmpe.f32 s16, s13 */
/* @0x2db58c vmrs APSR_nzcv, fpscr */
/* @0x2db590 bpl 0x2db554 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1e4> */
/* @0x2db594 b 0x2db530 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1c0> */
/* @0x2db598 vpop {d8, d9} */
/* @0x2db59c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2db5a0 mov r0, r5 */
/* @0x2db5a4 mov r1, r7 */
/* @0x2db5a8 bl 0x2d6440 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep> */
/* @0x2db5ac b 0x2db510 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1a0> */
/* @0x2db5b0 mov r0, r5 */
/* @0x2db5b4 bl 0x2d660c <_ZN16b2ParticleSystem11SolveZombieEv> */
/* @0x2db5b8 b 0x2db3cc <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x5c> */
/* @0x2db5bc mov r0, r5 */
/* @0x2db5c0 mov r1, r7 */
/* @0x2db5c4 bl 0x2d8c88 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep> */
/* @0x2db5c8 ldr r3, [r5, #0x4] */
/* @0x2db5cc tst r3, #64 */
/* @0x2db5d0 beq 0x2db4e0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x170> */
/* @0x2db5d4 mov r0, r5 */
/* @0x2db5d8 mov r1, r7 */
/* @0x2db5dc bl 0x2d8e98 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep> */
/* @0x2db5e0 ldr r3, [r5, #0x4] */
/* @0x2db5e4 tst r3, #128 */
/* @0x2db5e8 beq 0x2db4e8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x178> */
/* @0x2db5ec mov r0, r5 */
/* @0x2db5f0 mov r1, r7 */
/* @0x2db5f4 bl 0x2d82fc <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep> */
/* @0x2db5f8 ldr r3, [r5, #0x4] */
/* @0x2db5fc tst r3, #16 */
/* @0x2db600 beq 0x2db4f0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x180> */
/* @0x2db604 mov r0, r5 */
/* @0x2db608 mov r1, r7 */
/* @0x2db60c bl 0x2d5fc0 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep> */
/* @0x2db610 ldr r3, [r5, #0x4] */
/* @0x2db614 tst r3, #8 */
/* @0x2db618 beq 0x2db4f8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x188> */
/* @0x2db61c mov r0, r5 */
/* @0x2db620 mov r1, r7 */
/* @0x2db624 bl 0x2d620c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep> */
/* @0x2db628 ldr r3, [r5, #0x8] */
/* @0x2db62c tst r3, #1 */
/* @0x2db630 beq 0x2db504 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x194> */
/* @0x2db634 mov r0, r5 */
/* @0x2db638 mov r1, r7 */
/* @0x2db63c bl 0x2d6330 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep> */
/* @0x2db640 ldr r3, [r5, #0x4] */
/* @0x2db644 tst r3, #256 */
/* @0x2db648 beq 0x2db510 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1a0> */
/* @0x2db64c b 0x2db5a0 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x230> */
/* @0x2db650 mov r0, r5 */
/* @0x2db654 mov r1, r7 */
/* @0x2db658 bl 0x2d5e54 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep> */
/* @0x2db65c ldr r3, [r5, #0x4] */
/* @0x2db660 tst r3, #4 */
/* @0x2db664 beq 0x2db468 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0xf8> */
/* @0x2db668 mov r1, r7 */
/* @0x2db66c mov r0, r5 */
/* @0x2db670 bl 0x2d5e08 <_ZN16b2ParticleSystem9SolveWallERK10b2TimeStep> */
/* @0x2db674 ldr r1, [r5, #0x24] */
/* @0x2db678 cmp r1, #0 */
/* @0x2db67c bgt 0x2db474 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x104> */
/* @0x2db680 b 0x2db4b8 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x148> */
/* @0x2db684 vmov r0, s13 */
/* @0x2db688 bl 0xb6700 <sqrtf@plt> */
/* @0x2db68c ldr r3, [r5, #0x24] */
/* @0x2db690 vldr s14, [r4] */
/* @0x2db694 vldr s15, [r4, #4] */
/* @0x2db698 vmov s12, r0 */
/* @0x2db69c b 0x2db544 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep+0x1d4> */

/* ── FUNC 0x2db6a0 · b2ParticleSystem::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*) · size=1164 · insn=291 */
/* @0x2db6a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2db6a4 sub sp, sp, #68 */
/* @0x2db6a8 mov r9, r1 */
/* @0x2db6ac ldr r3, [r0, #0x24] */
/* @0x2db6b0 str r2, [sp, #0x8] */
/* @0x2db6b4 mov r11, r0 */
/* @0x2db6b8 ldr r12, [sp, #0x8] */
/* @0x2db6bc ldr r2, [r2, #0x8] */
/* @0x2db6c0 ldr r1, [r12, #0x4] */
/* @0x2db6c4 bl 0x2d7500 <_ZN16b2ParticleSystem12RotateBufferEiii> */
/* @0x2db6c8 ldr r12, [sp, #0x8] */
/* @0x2db6cc ldmib r9, {r1, r2} */
/* @0x2db6d0 mov r0, r11 */
/* @0x2db6d4 ldr r3, [r12, #0x4] */
/* @0x2db6d8 bl 0x2d7500 <_ZN16b2ParticleSystem12RotateBufferEiii> */
/* @0x2db6dc ldr r12, [sp, #0x8] */
/* @0x2db6e0 ldr r3, [r9, #0x4] */
/* @0x2db6e4 ldr r2, [r12, #0x8] */
/* @0x2db6e8 cmp r3, r2 */
/* @0x2db6ec bge 0x2dbaf8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x458> */
/* @0x2db6f0 ldr r1, [r11, #0x30] */
/* @0x2db6f4 mov r5, #0 */
/* @0x2db6f8 add r3, r1, r3, lsl #2 */
/* @0x2db6fc add r1, r1, r2, lsl #2 */
/* @0x2db700 ldr r2, [r3], #4 */
/* @0x2db704 cmp r3, r1 */
/* @0x2db708 orr r5, r5, r2 */
/* @0x2db70c bne 0x2db700 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x60> */
/* @0x2db710 mov r0, r11 */
/* @0x2db714 mov r1, #1 */
/* @0x2db718 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2db71c tst r5, #8 */
/* @0x2db720 beq 0x2db9c0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x320> */
/* @0x2db724 ldr r1, [r11, #0x74] */
/* @0x2db728 cmp r1, #0 */
/* @0x2db72c ble 0x2db9c0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x320> */
/* @0x2db730 ldr r12, [sp, #0x8] */
/* @0x2db734 mov r6, #0 */
/* @0x2db738 mov r8, r6 */
/* @0x2db73c ldr r2, [r12, #0x8] */
/* @0x2db740 mov r12, r5 */
/* @0x2db744 ldr r5, [sp, #0x8] */
/* @0x2db748 ldr r3, [r11, #0x7c] */
/* @0x2db74c add r10, r3, r6 */
/* @0x2db750 ldr r7, [r3, r6] */
/* @0x2db754 ldr r4, [r10, #0x4] */
/* @0x2db758 cmp r7, r4 */
/* @0x2db75c movle r3, r4 */
/* @0x2db760 movle r4, r7 */
/* @0x2db764 movle r7, r3 */
/* @0x2db768 ldr r3, [r9, #0x4] */
/* @0x2db76c cmp r3, r4 */
/* @0x2db770 bgt 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db774 ldr r3, [r9, #0x8] */
/* @0x2db778 cmp r3, r4 */
/* @0x2db77c ble 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db780 ldr r3, [r5, #0x4] */
/* @0x2db784 cmp r3, r7 */
/* @0x2db788 bgt 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db78c cmp r7, r2 */
/* @0x2db790 bge 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188> */
/* @0x2db794 ldr r0, [r11, #0x8c] */
/* @0x2db798 ldr r3, [r11, #0x90] */
/* @0x2db79c cmp r0, r3 */
/* @0x2db7a0 bge 0x2dba70 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3d0> */
/* @0x2db7a4 ldr r2, [r11, #0x94] */
/* @0x2db7a8 ldr r3, [r11, #0x38] */
/* @0x2db7ac vldr s12, [r9, #16] */
/* @0x2db7b0 vldr s13, [r5, #16] */
/* @0x2db7b4 vcmpe.f32 s12, s13 */
/* @0x2db7b8 add r1, r3, r4, lsl #3 */
/* @0x2db7bc add r3, r3, r7, lsl #3 */
/* @0x2db7c0 vldr s10, [r1, #4] */
/* @0x2db7c4 vldr s14, [r3, #4] */
/* @0x2db7c8 vldr s11, [r1] */
/* @0x2db7cc vldr s15, [r3] */
/* @0x2db7d0 vsub.f32 s14, s10, s14 */
/* @0x2db7d4 vmrs APSR_nzcv, fpscr */
/* @0x2db7d8 add r3, r0, r0, lsl #2 */
/* @0x2db7dc ldr r1, [r10, #0x8] */
/* @0x2db7e0 add r10, r2, r3, lsl #2 */
/* @0x2db7e4 str r4, [r2, r3, lsl #2] */
/* @0x2db7e8 str r1, [r10, #0x8] */
/* @0x2db7ec str r7, [r10, #0x4] */
/* @0x2db7f0 vmul.f32 s14, s14, s14 */
/* @0x2db7f4 vsub.f32 s15, s11, s15 */
/* @0x2db7f8 vmla.f32 s14, s15, s15 */
/* @0x2db7fc vsqrt.f32 s15, s14 */
/* @0x2db800 vcmp.f32 s15, s15 */
/* @0x2db804 vmovmi.f32 s13, s12 */
/* @0x2db808 vmrs APSR_nzcv, fpscr */
/* @0x2db80c vstr s13, [r10, #12] */
/* @0x2db810 bne 0x2dbb10 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x470> */
/* @0x2db814 ldr r1, [r11, #0x74] */
/* @0x2db818 add r0, r0, #1 */
/* @0x2db81c ldr r2, [r5, #0x8] */
/* @0x2db820 vstr s15, [r10, #16] */
/* @0x2db824 str r0, [r11, #0x8c] */
/* @0x2db828 add r8, r8, #1 */
/* @0x2db82c add r6, r6, #24 */
/* @0x2db830 cmp r1, r8 */
/* @0x2db834 bgt 0x2db748 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0xa8> */
/* @0x2db838 and r5, r12, #16 */
/* @0x2db83c cmp r5, #0 */
/* @0x2db840 beq 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334> */
/* @0x2db844 add r12, sp, #40 */
/* @0x2db848 ldr r1, [r11, #0xd4] */
/* @0x2db84c ldr r3, [r9, #0x4] */
/* @0x2db850 mov r0, r12 */
/* @0x2db854 add r1, r1, #68 */
/* @0x2db858 rsb r2, r3, r2 */
/* @0x2db85c str r12, [sp, #0xc] */
/* @0x2db860 bl 0x2dbb2c <_ZN16b2VoronoiDiagramC2EP16b2StackAllocatori> */
/* @0x2db864 ldr r12, [sp, #0x8] */
/* @0x2db868 ldr r4, [r9, #0x4] */
/* @0x2db86c ldr r2, [r12, #0x8] */
/* @0x2db870 cmp r4, r2 */
/* @0x2db874 bge 0x2db8d8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x238> */
/* @0x2db878 lsl r5, r4, #2 */
/* @0x2db87c lsl r6, r4, #3 */
/* @0x2db880 ldr r7, [sp, #0x8] */
/* @0x2db884 add r8, sp, #40 */
/* @0x2db888 b 0x2db89c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1fc> */
/* @0x2db88c add r4, r4, #1 */
/* @0x2db890 add r6, r6, #8 */
/* @0x2db894 cmp r2, r4 */
/* @0x2db898 ble 0x2db8d8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x238> */
/* @0x2db89c ldr r3, [r11, #0x30] */
/* @0x2db8a0 ldr r3, [r3, r5] */
/* @0x2db8a4 add r5, r5, #4 */
/* @0x2db8a8 tst r3, #2 */
/* @0x2db8ac bne 0x2db88c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1ec> */
/* @0x2db8b0 ldr r1, [r11, #0x38] */
/* @0x2db8b4 mov r2, r4 */
/* @0x2db8b8 mov r0, r8 */
/* @0x2db8bc add r4, r4, #1 */
/* @0x2db8c0 add r1, r1, r6 */
/* @0x2db8c4 add r6, r6, #8 */
/* @0x2db8c8 bl 0x2dbb94 <_ZN16b2VoronoiDiagram12AddGeneratorERK6b2Vec2i> */
/* @0x2db8cc ldr r2, [r7, #0x8] */
/* @0x2db8d0 cmp r2, r4 */
/* @0x2db8d4 bgt 0x2db89c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1fc> */
/* @0x2db8d8 mov r0, r11 */
/* @0x2db8dc bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv> */
/* @0x2db8e0 vmov.f32 s15, #5.000000e-01 */
/* @0x2db8e4 vmov s14, r0 */
/* @0x2db8e8 add r0, sp, #40 */
/* @0x2db8ec vmul.f32 s15, s14, s15 */
/* @0x2db8f0 vmov r1, s15 */
/* @0x2db8f4 bl 0x2dbbc4 <_ZN16b2VoronoiDiagram8GenerateEf> */
/* @0x2db8f8 ldr r3, [sp, #0x38] */
/* @0x2db8fc ldr r12, [sp, #0x8] */
/* @0x2db900 cmp r3, #1 */
/* @0x2db904 str r11, [sp, #0x1c] */
/* @0x2db908 str r9, [sp, #0x20] */
/* @0x2db90c str r12, [sp, #0x24] */
/* @0x2db910 ble 0x2dba5c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3bc> */
/* @0x2db914 ldr r1, [sp, #0x34] */
/* @0x2db918 add r10, sp, #28 */
/* @0x2db91c mov r8, #0 */
/* @0x2db920 cmp r1, #1 */
/* @0x2db924 ble 0x2dba4c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3ac> */
/* @0x2db928 mov r6, #0 */
/* @0x2db92c b 0x2db950 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x2b0> */
/* @0x2db930 cmp r4, r7 */
/* @0x2db934 cmpne r5, r7 */
/* @0x2db938 bne 0x2db9a8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x308> */
/* @0x2db93c ldr r1, [sp, #0x34] */
/* @0x2db940 add r6, r6, #1 */
/* @0x2db944 sub r3, r1, #1 */
/* @0x2db948 cmp r6, r3 */
/* @0x2db94c bge 0x2dba48 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3a8> */
/* @0x2db950 mla r2, r1, r8, r6 */
/* @0x2db954 ldr r3, [sp, #0x3c] */
/* @0x2db958 add r0, r1, r2 */
/* @0x2db95c add r12, r0, #1 */
/* @0x2db960 add lr, r3, r2, lsl #2 */
/* @0x2db964 ldr r4, [r3, r0, lsl #2] */
/* @0x2db968 ldr r2, [r3, r2, lsl #2] */
/* @0x2db96c ldr r5, [lr, #0x4] */
/* @0x2db970 ldr r7, [r3, r12, lsl #2] */
/* @0x2db974 cmp r5, r4 */
/* @0x2db978 beq 0x2db940 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x2a0> */
/* @0x2db97c cmp r2, r4 */
/* @0x2db980 cmpne r2, r5 */
/* @0x2db984 beq 0x2db930 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x290> */
/* @0x2db988 ldr r1, [r2, #0x8] */
/* @0x2db98c mov r0, r10 */
/* @0x2db990 ldr r2, [r5, #0x8] */
/* @0x2db994 ldr r3, [r4, #0x8] */
/* @0x2db998 bl 0x2d5580 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii> */
/* @0x2db99c cmp r4, r7 */
/* @0x2db9a0 cmpne r5, r7 */
/* @0x2db9a4 beq 0x2db93c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x29c> */
/* @0x2db9a8 ldr r1, [r5, #0x8] */
/* @0x2db9ac mov r0, r10 */
/* @0x2db9b0 ldr r2, [r7, #0x8] */
/* @0x2db9b4 ldr r3, [r4, #0x8] */
/* @0x2db9b8 bl 0x2d5580 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii> */
/* @0x2db9bc b 0x2db93c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x29c> */
/* @0x2db9c0 and r5, r5, #16 */
/* @0x2db9c4 ldr r12, [sp, #0x8] */
/* @0x2db9c8 cmp r5, #0 */
/* @0x2db9cc ldr r2, [r12, #0x8] */
/* @0x2db9d0 bne 0x2db844 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1a4> */
/* @0x2db9d4 ldr r12, [sp, #0x8] */
/* @0x2db9d8 ldr r3, [r12, #0x4] */
/* @0x2db9dc cmp r3, r2 */
/* @0x2db9e0 lsllt r1, r3, #2 */
/* @0x2db9e4 bge 0x2dba00 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x360> */
/* @0x2db9e8 add r3, r3, #1 */
/* @0x2db9ec ldr r0, [r11, #0x5c] */
/* @0x2db9f0 cmp r3, r2 */
/* @0x2db9f4 str r9, [r0, r1] */
/* @0x2db9f8 add r1, r1, #4 */
/* @0x2db9fc bne 0x2db9e8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x348> */
/* @0x2dba00 ldr r12, [sp, #0x8] */
/* @0x2dba04 mov r0, r11 */
/* @0x2dba08 ldr r4, [r12, #0xc] */
/* @0x2dba0c mov r1, r12 */
/* @0x2dba10 str r2, [r9, #0x8] */
/* @0x2dba14 ldr r3, [r12, #0x8] */
/* @0x2dba18 ldr r2, [r9, #0xc] */
/* @0x2dba1c orr r4, r4, r2 */
/* @0x2dba20 str r4, [r9, #0xc] */
/* @0x2dba24 str r3, [r12, #0x4] */
/* @0x2dba28 bl 0x2d5874 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup> */
/* @0x2dba2c tst r4, #1 */
/* @0x2dba30 beq 0x2dba40 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3a0> */
/* @0x2dba34 mov r0, r11 */
/* @0x2dba38 mov r1, r9 */
/* @0x2dba3c bl 0x2d5920 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup> */
/* @0x2dba40 add sp, sp, #68 */
/* @0x2dba44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2dba48 ldr r3, [sp, #0x38] */
/* @0x2dba4c add r8, r8, #1 */
/* @0x2dba50 sub r2, r3, #1 */
/* @0x2dba54 cmp r8, r2 */
/* @0x2dba58 blt 0x2db920 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x280> */
/* @0x2dba5c add r0, sp, #40 */
/* @0x2dba60 bl 0x2dbb68 <_ZN16b2VoronoiDiagramD2Ev> */
/* @0x2dba64 ldr r12, [sp, #0x8] */
/* @0x2dba68 ldr r2, [r12, #0x8] */
/* @0x2dba6c b 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334> */
/* @0x2dba70 cmp r0, #0 */
/* @0x2dba74 lslne r1, r0, #1 */
/* @0x2dba78 strne r1, [sp, #0x14] */
/* @0x2dba7c moveq r2, #256 */
/* @0x2dba80 addne r1, r1, r0, lsl #3 */
/* @0x2dba84 streq r2, [sp, #0x14] */
/* @0x2dba88 moveq r1, #5120 */
/* @0x2dba8c ldr r2, [r11, #0x94] */
/* @0x2dba90 lslne r1, r1, #2 */
/* @0x2dba94 ldr r0, [r11, #0xd4] */
/* @0x2dba98 str r12, [sp] */
/* @0x2dba9c str r2, [sp, #0xc] */
/* @0x2dbaa0 str r3, [sp, #0x4] */
/* @0x2dbaa4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2dbaa8 ldr r3, [sp, #0x4] */
/* @0x2dbaac ldr r1, [sp, #0xc] */
/* @0x2dbab0 add r3, r3, r3, lsl #2 */
/* @0x2dbab4 lsl r3, r3, #2 */
/* @0x2dbab8 str r3, [sp, #0x4] */
/* @0x2dbabc mov r2, r3 */
/* @0x2dbac0 str r0, [sp, #0x10] */
/* @0x2dbac4 bl 0xb65bc <memcpy@plt> */
/* @0x2dbac8 ldr r3, [sp, #0x4] */
/* @0x2dbacc ldr r0, [r11, #0xd4] */
/* @0x2dbad0 ldr r1, [sp, #0xc] */
/* @0x2dbad4 mov r2, r3 */
/* @0x2dbad8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2dbadc ldr r2, [sp, #0x10] */
/* @0x2dbae0 ldr r3, [sp, #0x14] */
/* @0x2dbae4 ldr r0, [r11, #0x8c] */
/* @0x2dbae8 str r2, [r11, #0x94] */
/* @0x2dbaec str r3, [r11, #0x90] */
/* @0x2dbaf0 ldr r12, [sp] */
/* @0x2dbaf4 b 0x2db7a8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x108> */
/* @0x2dbaf8 mov r0, r11 */
/* @0x2dbafc mov r1, #1 */
/* @0x2dbb00 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb> */
/* @0x2dbb04 ldr r12, [sp, #0x8] */
/* @0x2dbb08 ldr r2, [r12, #0x8] */
/* @0x2dbb0c b 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334> */
/* @0x2dbb10 vmov r0, s14 */
/* @0x2dbb14 str r12, [sp] */
/* @0x2dbb18 bl 0xb6700 <sqrtf@plt> */
/* @0x2dbb1c ldr r12, [sp] */
/* @0x2dbb20 vmov s15, r0 */
/* @0x2dbb24 ldr r0, [r11, #0x8c] */
/* @0x2dbb28 b 0x2db814 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x174> */

/* ── FUNC 0x2dbb2c · b2VoronoiDiagram::b2VoronoiDiagram(b2StackAllocator*, int) · size=60 · insn=15 */
/* @0x2dbb2c add r2, r2, r2, lsl #1 */
/* @0x2dbb30 push {r4, lr} */
/* @0x2dbb34 mov r4, r0 */
/* @0x2dbb38 str r1, [r4] */
/* @0x2dbb3c mov r0, r1 */
/* @0x2dbb40 lsl r1, r2, #2 */
/* @0x2dbb44 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2dbb48 mov r3, #0 */
/* @0x2dbb4c str r3, [r4, #0x8] */
/* @0x2dbb50 str r3, [r4, #0xc] */
/* @0x2dbb54 str r3, [r4, #0x10] */
/* @0x2dbb58 str r3, [r4, #0x14] */
/* @0x2dbb5c str r0, [r4, #0x4] */
/* @0x2dbb60 mov r0, r4 */
/* @0x2dbb64 pop {r4, pc} */
