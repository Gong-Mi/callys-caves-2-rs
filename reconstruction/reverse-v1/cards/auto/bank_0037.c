/* libyoyo.so 覆盖卡组 0037
 * 函数 0x10e0e8..0x10ec24，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x10e0e8 · F_DotProduct_3D(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x10e0e8 push {r3, r4, r5, lr} */
/* @0x10e0ec vpush {d8, d9, d10, d11, d12} */
/* @0x10e0f0 mov r5, r0 */
/* @0x10e0f4 ldr r4, [sp, #0x38] */
/* @0x10e0f8 mov r1, #0 */
/* @0x10e0fc str r1, [r0, #0xc] */
/* @0x10e100 mov r0, r4 */
/* @0x10e104 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e108 vmov d10, r0, r1 */
/* @0x10e10c mov r0, r4 */
/* @0x10e110 mov r1, #1 */
/* @0x10e114 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e118 vmov d12, r0, r1 */
/* @0x10e11c mov r0, r4 */
/* @0x10e120 mov r1, #2 */
/* @0x10e124 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e128 vmov d8, r0, r1 */
/* @0x10e12c mov r0, r4 */
/* @0x10e130 mov r1, #3 */
/* @0x10e134 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e138 vmov d9, r0, r1 */
/* @0x10e13c mov r0, r4 */
/* @0x10e140 mov r1, #4 */
/* @0x10e144 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e148 vmov d11, r0, r1 */
/* @0x10e14c mov r0, r4 */
/* @0x10e150 mov r1, #5 */
/* @0x10e154 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e158 vmul.f64 d7, d12, d11 */
/* @0x10e15c vmla.f64 d7, d10, d9 */
/* @0x10e160 vmov d6, r0, r1 */
/* @0x10e164 vmla.f64 d7, d8, d6 */
/* @0x10e168 vmov r2, s14 */
/* @0x10e16c vmov r3, s15 */
/* @0x10e170 stm r5, {r2, r3} */
/* @0x10e174 vpop {d8, d9, d10, d11, d12} */
/* @0x10e178 pop {r3, r4, r5, pc} */

/* ── FUNC 0x10e17c · anon_10e17c · size=4 · insn=1 */
/* @0x10e17c andeq r0, r0, r0 */

/* ── FUNC 0x10e180 · F_MathSetEpsilon(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x10e180 push {r4, r5, lr} */
/* @0x10e184 sub sp, sp, #20 */
/* @0x10e188 mov r1, #0 */
/* @0x10e18c ldr r0, [sp, #0x20] */
/* @0x10e190 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e194 vmov d7, r0, r1 */
/* @0x10e198 vcmpe.f64 d7, #0 */
/* @0x10e19c vmrs APSR_nzcv, fpscr */
/* @0x10e1a0 blt 0x10e1b4 <_Z16F_MathSetEpsilonR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x10e1a4 vmov.f64 d6, #1.000000e+00 */
/* @0x10e1a8 vcmpe.f64 d7, d6 */
/* @0x10e1ac vmrs APSR_nzcv, fpscr */
/* @0x10e1b0 bmi 0x10e1bc <_Z16F_MathSetEpsilonR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x10e1b4 add sp, sp, #20 */
/* @0x10e1b8 pop {r4, r5, pc} */
/* @0x10e1bc ldr r2, [pc, #0x54] */
/* @0x10e1c0 vcmp.f64 d7, #0 */
/* @0x10e1c4 vldr d6, [pc, #68] */
/* @0x10e1c8 ldr r3, [pc, #0x4c] */
/* @0x10e1cc ldr r2, [pc, r2] */
/* @0x10e1d0 ldr r3, [pc, r3] */
/* @0x10e1d4 ldr r2, [r2] */
/* @0x10e1d8 vmrs APSR_nzcv, fpscr */
/* @0x10e1dc vmoveq.f64 d7, d6 */
/* @0x10e1e0 vstr d7, [r3] */
/* @0x10e1e4 cmp r2, #0 */
/* @0x10e1e8 beq 0x10e1b4 <_Z16F_MathSetEpsilonR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x10e1ec vmov r4, r5, d7 */
/* @0x10e1f0 add r1, sp, #16 */
/* @0x10e1f4 mov r0, #1 */
/* @0x10e1f8 strd r4, r5, [r1, #-16]! */
/* @0x10e1fc mov r1, sp */
/* @0x10e200 blx r2 */
/* @0x10e204 add sp, sp, #20 */
/* @0x10e208 pop {r4, r5, pc} */
/* @0x10e20c nop */
/* @0x10e210 .word 0xe1796495 */
/* @0x10e214 stclo p13, c15, [r5, #508]! */
/* @0x10e218 eoreq r0, lr, r12, ror r0 */
/* @0x10e21c eoreq pc, sp, r8, asr #22 */

/* ── FUNC 0x10e220 · F_RandomSetSeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x10e220 push {r3, lr} */
/* @0x10e224 mov r3, #0 */
/* @0x10e228 ldr r12, [sp, #0x8] */
/* @0x10e22c mov r1, r3 */
/* @0x10e230 str r3, [r0, #0xc] */
/* @0x10e234 str r3, [r0] */
/* @0x10e238 str r3, [r0, #0x4] */
/* @0x10e23c mov r0, r12 */
/* @0x10e240 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x10e244 pop {r3, lr} */
/* @0x10e248 b 0xc4438 <_Z10InitRandomj> */

/* ── FUNC 0x10e24c · F_RandomUseOldVersion(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x10e24c push {r3, lr} */
/* @0x10e250 mov r3, #0 */
/* @0x10e254 ldr r12, [sp, #0x8] */
/* @0x10e258 mov r1, r3 */
/* @0x10e25c str r3, [r0, #0xc] */
/* @0x10e260 str r3, [r0] */
/* @0x10e264 str r3, [r0, #0x4] */
/* @0x10e268 mov r0, r12 */
/* @0x10e26c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10e270 pop {r3, lr} */
/* @0x10e274 cmp r0, #0 */
/* @0x10e278 movle r0, #0 */
/* @0x10e27c movgt r0, #1 */
/* @0x10e280 b 0xc44ac <_Z15ChangeToOldPolyb> */

/* ── FUNC 0x10e284 · F_Randomize(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x10e284 push {r4, lr} */
/* @0x10e288 mov r3, #0 */
/* @0x10e28c str r3, [r0, #0xc] */
/* @0x10e290 mov r4, r0 */
/* @0x10e294 bl 0x215148 <Timing_Time> */
/* @0x10e298 ldr r3, [pc, #0x34] */
/* @0x10e29c ldr r3, [pc, r3] */
/* @0x10e2a0 ldrd r2, r3, [r3] */
/* @0x10e2a4 adds r2, r2, r0 */
/* @0x10e2a8 adc r3, r3, r1 */
/* @0x10e2ac add r0, r3, r2 */
/* @0x10e2b0 eor r0, r0, r2, ror #16 */
/* @0x10e2b4 bl 0xc4438 <_Z10InitRandomj> */
/* @0x10e2b8 vmov s15, r0 */
/* @0x10e2bc vcvt.f64.u32 d7, s15 */
/* @0x10e2c0 vmov r0, r1, d7 */
/* @0x10e2c4 vmov r2, s14 */
/* @0x10e2c8 mov r3, r1 */
/* @0x10e2cc stm r4, {r2, r3} */
/* @0x10e2d0 pop {r4, pc} */
/* @0x10e2d4 .word 0x002dffb0 */

/* ── FUNC 0x10e2d8 · F_Round(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x10e2d8 push {r4, lr} */
/* @0x10e2dc mov r3, #0 */
/* @0x10e2e0 mov r1, r3 */
/* @0x10e2e4 str r3, [r0, #0xc] */
/* @0x10e2e8 mov r4, r0 */
/* @0x10e2ec ldr r0, [sp, #0x8] */
/* @0x10e2f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e2f4 bl 0xb66e8 <lrint@plt> */
/* @0x10e2f8 vmov s15, r0 */
/* @0x10e2fc vcvt.f64.s32 d7, s15 */
/* @0x10e300 vmov r0, r1, d7 */
/* @0x10e304 vmov r2, s14 */
/* @0x10e308 mov r3, r1 */
/* @0x10e30c stm r4, {r2, r3} */
/* @0x10e310 pop {r4, pc} */

/* ── FUNC 0x10e314 · F_Floor(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x10e314 push {r4, lr} */
/* @0x10e318 mov r3, #0 */
/* @0x10e31c mov r4, r0 */
/* @0x10e320 str r3, [r0, #0xc] */
/* @0x10e324 mov r1, r3 */
/* @0x10e328 ldr r0, [sp, #0x8] */
/* @0x10e32c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e330 bl 0xb6598 <floor@plt> */
/* @0x10e334 stm r4, {r0, r1} */
/* @0x10e338 pop {r4, pc} */

/* ── FUNC 0x10e33c · F_Ceil(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x10e33c push {r4, lr} */
/* @0x10e340 mov r3, #0 */
/* @0x10e344 mov r4, r0 */
/* @0x10e348 str r3, [r0, #0xc] */
/* @0x10e34c mov r1, r3 */
/* @0x10e350 ldr r0, [sp, #0x8] */
/* @0x10e354 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e358 bl 0xb670c <ceil@plt> */
/* @0x10e35c stm r4, {r0, r1} */
/* @0x10e360 pop {r4, pc} */

/* ── FUNC 0x10e364 · F_Frac(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x10e364 push {r4, r5, r6, r7, lr} */
/* @0x10e368 sub sp, sp, #12 */
/* @0x10e36c mov r3, #0 */
/* @0x10e370 add r7, sp, #8 */
/* @0x10e374 str r3, [r0, #0xc] */
/* @0x10e378 mov r6, r0 */
/* @0x10e37c mov r1, r3 */
/* @0x10e380 ldr r0, [sp, #0x20] */
/* @0x10e384 mov r4, #0 */
/* @0x10e388 mov r5, #0 */
/* @0x10e38c strd r4, r5, [r7, #-8]! */
/* @0x10e390 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e394 mov r2, sp */
/* @0x10e398 bl 0xb6718 <modf@plt> */
/* @0x10e39c stm r6, {r0, r1} */
/* @0x10e3a0 add sp, sp, #12 */
/* @0x10e3a4 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x10e3a8 · F_Exp(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x10e3a8 push {r4, lr} */
/* @0x10e3ac mov r3, #0 */
/* @0x10e3b0 mov r4, r0 */
/* @0x10e3b4 str r3, [r0, #0xc] */
/* @0x10e3b8 mov r1, r3 */
/* @0x10e3bc ldr r0, [sp, #0x8] */
/* @0x10e3c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e3c4 bl 0xb6724 <exp@plt> */
/* @0x10e3c8 stm r4, {r0, r1} */
/* @0x10e3cc pop {r4, pc} */

/* ── FUNC 0x10e3d0 · F_Ln(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x10e3d0 push {r4, lr} */
/* @0x10e3d4 mov r3, #0 */
/* @0x10e3d8 mov r4, r0 */
/* @0x10e3dc str r3, [r0, #0xc] */
/* @0x10e3e0 mov r1, r3 */
/* @0x10e3e4 ldr r0, [sp, #0x8] */
/* @0x10e3e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e3ec bl 0xb6730 <log@plt> */
/* @0x10e3f0 stm r4, {r0, r1} */
/* @0x10e3f4 pop {r4, pc} */

/* ── FUNC 0x10e3f8 · F_Log2(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x10e3f8 push {r4, lr} */
/* @0x10e3fc mov r3, #0 */
/* @0x10e400 mov r1, r3 */
/* @0x10e404 str r3, [r0, #0xc] */
/* @0x10e408 mov r4, r0 */
/* @0x10e40c ldr r0, [sp, #0x8] */
/* @0x10e410 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e414 bl 0xb6730 <log@plt> */
/* @0x10e418 vldr d7, [pc, #24] */
/* @0x10e41c vmov d6, r0, r1 */
/* @0x10e420 vdiv.f64 d6, d6, d7 */
/* @0x10e424 vmov r0, r1, d6 */
/* @0x10e428 vmov r2, s12 */
/* @0x10e42c mov r3, r1 */
/* @0x10e430 stm r4, {r2, r3} */
/* @0x10e434 pop {r4, pc} */
/* @0x10e438 cdp2 p9, #0xf, c3, c10, c15, #0x7 */
/* @0x10e43c svclo #0xe62e42 */

/* ── FUNC 0x10e440 · F_Logn(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x10e440 push {r4, r5, r6, lr} */
/* @0x10e444 vpush {d8} */
/* @0x10e448 mov r4, r0 */
/* @0x10e44c ldr r5, [sp, #0x18] */
/* @0x10e450 mov r6, #0 */
/* @0x10e454 mov r1, #1 */
/* @0x10e458 str r6, [r0, #0xc] */
/* @0x10e45c mov r0, r5 */
/* @0x10e460 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e464 bl 0xb6730 <log@plt> */
/* @0x10e468 vmov d8, r0, r1 */
/* @0x10e46c mov r0, r5 */
/* @0x10e470 mov r1, r6 */
/* @0x10e474 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e478 bl 0xb6730 <log@plt> */
/* @0x10e47c vmov d7, r0, r1 */
/* @0x10e480 vdiv.f64 d7, d8, d7 */
/* @0x10e484 vmov r0, r1, d7 */
/* @0x10e488 vmov r2, s14 */
/* @0x10e48c mov r3, r1 */
/* @0x10e490 stm r4, {r2, r3} */
/* @0x10e494 vpop {d8} */
/* @0x10e498 pop {r4, r5, r6, pc} */

/* ── FUNC 0x10e49c · F_Log10(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x10e49c push {r4, lr} */
/* @0x10e4a0 mov r3, #0 */
/* @0x10e4a4 mov r4, r0 */
/* @0x10e4a8 str r3, [r0, #0xc] */
/* @0x10e4ac mov r1, r3 */
/* @0x10e4b0 ldr r0, [sp, #0x8] */
/* @0x10e4b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10e4b8 bl 0xb673c <log10@plt> */
/* @0x10e4bc stm r4, {r0, r1} */
/* @0x10e4c0 pop {r4, pc} */

/* ── FUNC 0x10e4c4 · F_Sin(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10e4c4 mov r3, #0 */
/* @0x10e4c8 push {r4, lr} */
/* @0x10e4cc mov r1, r3 */
/* @0x10e4d0 str r3, [r0, #0xc] */
/* @0x10e4d4 mov r4, r0 */
/* @0x10e4d8 ldr r0, [sp, #0x8] */
/* @0x10e4dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e4e0 bl 0xb6580 <sinf@plt> */
/* @0x10e4e4 vldr s14, [pc, #36] */
/* @0x10e4e8 vmov s15, r0 */
/* @0x10e4ec vabs.f32 s13, s15 */
/* @0x10e4f0 vcmpe.f32 s13, s14 */
/* @0x10e4f4 vmrs APSR_nzcv, fpscr */
/* @0x10e4f8 vcvtpl.f64.f32 d6, s15 */
/* @0x10e4fc movmi r2, #0 */
/* @0x10e500 movmi r3, #0 */
/* @0x10e504 vmovpl r2, r3, d6 */
/* @0x10e508 stm r4, {r2, r3} */
/* @0x10e50c pop {r4, pc} */
/* @0x10e510 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e514 · F_DSin(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x10e514 mov r3, #0 */
/* @0x10e518 push {r4, lr} */
/* @0x10e51c mov r1, r3 */
/* @0x10e520 str r3, [r0, #0xc] */
/* @0x10e524 mov r4, r0 */
/* @0x10e528 ldr r0, [sp, #0x8] */
/* @0x10e52c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e530 vldr s14, [pc, #64] */
/* @0x10e534 vldr s15, [pc, #64] */
/* @0x10e538 vmov s12, r0 */
/* @0x10e53c vmul.f32 s14, s12, s14 */
/* @0x10e540 vdiv.f32 s15, s14, s15 */
/* @0x10e544 vmov r0, s15 */
/* @0x10e548 bl 0xb6580 <sinf@plt> */
/* @0x10e54c vldr s14, [pc, #44] */
/* @0x10e550 vmov s15, r0 */
/* @0x10e554 vabs.f32 s13, s15 */
/* @0x10e558 vcmpe.f32 s13, s14 */
/* @0x10e55c vmrs APSR_nzcv, fpscr */
/* @0x10e560 vcvtpl.f64.f32 d6, s15 */
/* @0x10e564 movmi r2, #0 */
/* @0x10e568 movmi r3, #0 */
/* @0x10e56c vmovpl r2, r3, d6 */
/* @0x10e570 stm r4, {r2, r3} */
/* @0x10e574 pop {r4, pc} */
/* @0x10e578 ldrdmi r0, r1, [r9], #-251 */
/* @0x10e57c teqmi r4, #0 */
/* @0x10e580 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e584 · F_Cos(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10e584 mov r3, #0 */
/* @0x10e588 push {r4, lr} */
/* @0x10e58c mov r1, r3 */
/* @0x10e590 str r3, [r0, #0xc] */
/* @0x10e594 mov r4, r0 */
/* @0x10e598 ldr r0, [sp, #0x8] */
/* @0x10e59c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e5a0 bl 0xb658c <cosf@plt> */
/* @0x10e5a4 vldr s14, [pc, #36] */
/* @0x10e5a8 vmov s15, r0 */
/* @0x10e5ac vabs.f32 s13, s15 */
/* @0x10e5b0 vcmpe.f32 s13, s14 */
/* @0x10e5b4 vmrs APSR_nzcv, fpscr */
/* @0x10e5b8 vcvtpl.f64.f32 d6, s15 */
/* @0x10e5bc movmi r2, #0 */
/* @0x10e5c0 movmi r3, #0 */
/* @0x10e5c4 vmovpl r2, r3, d6 */
/* @0x10e5c8 stm r4, {r2, r3} */
/* @0x10e5cc pop {r4, pc} */
/* @0x10e5d0 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e5d4 · F_DCos(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x10e5d4 mov r3, #0 */
/* @0x10e5d8 push {r4, lr} */
/* @0x10e5dc mov r1, r3 */
/* @0x10e5e0 str r3, [r0, #0xc] */
/* @0x10e5e4 mov r4, r0 */
/* @0x10e5e8 ldr r0, [sp, #0x8] */
/* @0x10e5ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e5f0 vldr s14, [pc, #64] */
/* @0x10e5f4 vldr s15, [pc, #64] */
/* @0x10e5f8 vmov s12, r0 */
/* @0x10e5fc vmul.f32 s14, s12, s14 */
/* @0x10e600 vdiv.f32 s15, s14, s15 */
/* @0x10e604 vmov r0, s15 */
/* @0x10e608 bl 0xb658c <cosf@plt> */
/* @0x10e60c vldr s14, [pc, #44] */
/* @0x10e610 vmov s15, r0 */
/* @0x10e614 vabs.f32 s13, s15 */
/* @0x10e618 vcmpe.f32 s13, s14 */
/* @0x10e61c vmrs APSR_nzcv, fpscr */
/* @0x10e620 vcvtpl.f64.f32 d6, s15 */
/* @0x10e624 movmi r2, #0 */
/* @0x10e628 movmi r3, #0 */
/* @0x10e62c vmovpl r2, r3, d6 */
/* @0x10e630 stm r4, {r2, r3} */
/* @0x10e634 pop {r4, pc} */
/* @0x10e638 ldrdmi r0, r1, [r9], #-251 */
/* @0x10e63c teqmi r4, #0 */
/* @0x10e640 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e644 · F_Tan(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10e644 mov r3, #0 */
/* @0x10e648 push {r4, lr} */
/* @0x10e64c mov r1, r3 */
/* @0x10e650 str r3, [r0, #0xc] */
/* @0x10e654 mov r4, r0 */
/* @0x10e658 ldr r0, [sp, #0x8] */
/* @0x10e65c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e660 bl 0xb6748 <tanf@plt> */
/* @0x10e664 vldr s14, [pc, #36] */
/* @0x10e668 vmov s15, r0 */
/* @0x10e66c vabs.f32 s13, s15 */
/* @0x10e670 vcmpe.f32 s13, s14 */
/* @0x10e674 vmrs APSR_nzcv, fpscr */
/* @0x10e678 vcvtpl.f64.f32 d6, s15 */
/* @0x10e67c movmi r2, #0 */
/* @0x10e680 movmi r3, #0 */
/* @0x10e684 vmovpl r2, r3, d6 */
/* @0x10e688 stm r4, {r2, r3} */
/* @0x10e68c pop {r4, pc} */
/* @0x10e690 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e694 · F_DTan(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x10e694 mov r3, #0 */
/* @0x10e698 push {r4, lr} */
/* @0x10e69c mov r1, r3 */
/* @0x10e6a0 str r3, [r0, #0xc] */
/* @0x10e6a4 mov r4, r0 */
/* @0x10e6a8 ldr r0, [sp, #0x8] */
/* @0x10e6ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e6b0 vldr s14, [pc, #64] */
/* @0x10e6b4 vldr s15, [pc, #64] */
/* @0x10e6b8 vmov s12, r0 */
/* @0x10e6bc vmul.f32 s14, s12, s14 */
/* @0x10e6c0 vdiv.f32 s15, s14, s15 */
/* @0x10e6c4 vmov r0, s15 */
/* @0x10e6c8 bl 0xb6748 <tanf@plt> */
/* @0x10e6cc vldr s14, [pc, #44] */
/* @0x10e6d0 vmov s15, r0 */
/* @0x10e6d4 vabs.f32 s13, s15 */
/* @0x10e6d8 vcmpe.f32 s13, s14 */
/* @0x10e6dc vmrs APSR_nzcv, fpscr */
/* @0x10e6e0 vcvtpl.f64.f32 d6, s15 */
/* @0x10e6e4 movmi r2, #0 */
/* @0x10e6e8 movmi r3, #0 */
/* @0x10e6ec vmovpl r2, r3, d6 */
/* @0x10e6f0 stm r4, {r2, r3} */
/* @0x10e6f4 pop {r4, pc} */
/* @0x10e6f8 ldrdmi r0, r1, [r9], #-251 */
/* @0x10e6fc teqmi r4, #0 */
/* @0x10e700 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e704 · F_ArcSin(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x10e704 push {r4, lr} */
/* @0x10e708 mov r1, #0 */
/* @0x10e70c ldr r3, [sp, #0x8] */
/* @0x10e710 mov r4, r0 */
/* @0x10e714 str r1, [r0, #0xc] */
/* @0x10e718 mov r0, r3 */
/* @0x10e71c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e720 vmov.f32 s14, #-1.000000e+00 */
/* @0x10e724 vmov s15, r0 */
/* @0x10e728 vcmpe.f32 s15, s14 */
/* @0x10e72c vmrs APSR_nzcv, fpscr */
/* @0x10e730 blt 0x10e744 <_Z8F_ArcSinR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x10e734 vmov.f32 s14, #1.000000e+00 */
/* @0x10e738 vcmpe.f32 s15, s14 */
/* @0x10e73c vmrs APSR_nzcv, fpscr */
/* @0x10e740 bls 0x10e758 <_Z8F_ArcSinR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10e744 ldr r0, [pc, #0x40] */
/* @0x10e748 mov r1, #0 */
/* @0x10e74c pop {r4, lr} */
/* @0x10e750 add r0, pc, r0 */
/* @0x10e754 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10e758 bl 0xb6754 <asinf@plt> */
/* @0x10e75c vldr s14, [pc, #36] */
/* @0x10e760 vmov s15, r0 */
/* @0x10e764 vabs.f32 s13, s15 */
/* @0x10e768 vcmpe.f32 s13, s14 */
/* @0x10e76c vmrs APSR_nzcv, fpscr */
/* @0x10e770 vcvtpl.f64.f32 d6, s15 */
/* @0x10e774 movmi r2, #0 */
/* @0x10e778 movmi r3, #0 */
/* @0x10e77c vmovpl r2, r3, d6 */
/* @0x10e780 stm r4, {r2, r3} */
/* @0x10e784 pop {r4, pc} */
/* @0x10e788 strlo r12, [r7, -r12, lsr #11]! */
/* @0x10e78c .word 0x0022a6bc */

/* ── FUNC 0x10e790 · F_DArcSin(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x10e790 push {r4, lr} */
/* @0x10e794 mov r1, #0 */
/* @0x10e798 ldr r3, [sp, #0x8] */
/* @0x10e79c mov r4, r0 */
/* @0x10e7a0 str r1, [r0, #0xc] */
/* @0x10e7a4 mov r0, r3 */
/* @0x10e7a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e7ac vmov.f32 s14, #-1.000000e+00 */
/* @0x10e7b0 vmov s15, r0 */
/* @0x10e7b4 vcmpe.f32 s15, s14 */
/* @0x10e7b8 vmrs APSR_nzcv, fpscr */
/* @0x10e7bc blt 0x10e7d0 <_Z9F_DArcSinR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x10e7c0 vmov.f32 s14, #1.000000e+00 */
/* @0x10e7c4 vcmpe.f32 s15, s14 */
/* @0x10e7c8 vmrs APSR_nzcv, fpscr */
/* @0x10e7cc bls 0x10e7e4 <_Z9F_DArcSinR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x10e7d0 ldr r0, [pc, #0x58] */
/* @0x10e7d4 mov r1, #0 */
/* @0x10e7d8 pop {r4, lr} */
/* @0x10e7dc add r0, pc, r0 */
/* @0x10e7e0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10e7e4 bl 0xb6754 <asinf@plt> */
/* @0x10e7e8 vldr s15, [pc, #52] */
/* @0x10e7ec vldr s13, [pc, #52] */
/* @0x10e7f0 vldr s14, [pc, #52] */
/* @0x10e7f4 vmov s12, r0 */
/* @0x10e7f8 vmul.f32 s15, s12, s15 */
/* @0x10e7fc vdiv.f32 s15, s15, s13 */
/* @0x10e800 vabs.f32 s13, s15 */
/* @0x10e804 vcmpe.f32 s13, s14 */
/* @0x10e808 vmrs APSR_nzcv, fpscr */
/* @0x10e80c vcvtpl.f64.f32 d6, s15 */
/* @0x10e810 movmi r2, #0 */
/* @0x10e814 movmi r3, #0 */
/* @0x10e818 vmovpl r2, r3, d6 */
/* @0x10e81c stm r4, {r2, r3} */
/* @0x10e820 pop {r4, pc} */
/* @0x10e824 teqmi r4, #0 */
/* @0x10e828 ldrdmi r0, r1, [r9], #-251 */
/* @0x10e82c strlo r12, [r7, -r12, lsr #11]! */
/* @0x10e830 eoreq r10, r2, r0, lsr r6 */

/* ── FUNC 0x10e834 · F_ArcCos(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x10e834 push {r4, lr} */
/* @0x10e838 mov r3, #0 */
/* @0x10e83c ldr r2, [sp, #0x8] */
/* @0x10e840 mov r4, r0 */
/* @0x10e844 str r3, [r0, #0xc] */
/* @0x10e848 mov r1, r3 */
/* @0x10e84c str r3, [r0] */
/* @0x10e850 str r3, [r0, #0x4] */
/* @0x10e854 mov r0, r2 */
/* @0x10e858 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e85c vmov.f32 s14, #-1.000000e+00 */
/* @0x10e860 vmov s15, r0 */
/* @0x10e864 vcmpe.f32 s15, s14 */
/* @0x10e868 vmrs APSR_nzcv, fpscr */
/* @0x10e86c blt 0x10e880 <_Z8F_ArcCosR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x10e870 vmov.f32 s14, #1.000000e+00 */
/* @0x10e874 vcmpe.f32 s15, s14 */
/* @0x10e878 vmrs APSR_nzcv, fpscr */
/* @0x10e87c bls 0x10e894 <_Z8F_ArcCosR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x10e880 ldr r0, [pc, #0x40] */
/* @0x10e884 mov r1, #0 */
/* @0x10e888 pop {r4, lr} */
/* @0x10e88c add r0, pc, r0 */
/* @0x10e890 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10e894 bl 0xb6760 <acosf@plt> */
/* @0x10e898 vldr s14, [pc, #36] */
/* @0x10e89c vmov s15, r0 */
/* @0x10e8a0 vabs.f32 s13, s15 */
/* @0x10e8a4 vcmpe.f32 s13, s14 */
/* @0x10e8a8 vmrs APSR_nzcv, fpscr */
/* @0x10e8ac vcvtpl.f64.f32 d6, s15 */
/* @0x10e8b0 movmi r2, #0 */
/* @0x10e8b4 movmi r3, #0 */
/* @0x10e8b8 vmovpl r2, r3, d6 */
/* @0x10e8bc stm r4, {r2, r3} */
/* @0x10e8c0 pop {r4, pc} */
/* @0x10e8c4 strlo r12, [r7, -r12, lsr #11]! */
/* @0x10e8c8 mlaeq r2, r12, r5, r10 */

/* ── FUNC 0x10e8cc · F_DArcCos(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x10e8cc push {r4, lr} */
/* @0x10e8d0 mov r3, #0 */
/* @0x10e8d4 ldr r2, [sp, #0x8] */
/* @0x10e8d8 mov r4, r0 */
/* @0x10e8dc str r3, [r0, #0xc] */
/* @0x10e8e0 mov r1, r3 */
/* @0x10e8e4 str r3, [r0] */
/* @0x10e8e8 str r3, [r0, #0x4] */
/* @0x10e8ec mov r0, r2 */
/* @0x10e8f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e8f4 vmov.f32 s14, #-1.000000e+00 */
/* @0x10e8f8 vmov s15, r0 */
/* @0x10e8fc vcmpe.f32 s15, s14 */
/* @0x10e900 vmrs APSR_nzcv, fpscr */
/* @0x10e904 blt 0x10e918 <_Z9F_DArcCosR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x10e908 vmov.f32 s14, #1.000000e+00 */
/* @0x10e90c vcmpe.f32 s15, s14 */
/* @0x10e910 vmrs APSR_nzcv, fpscr */
/* @0x10e914 bls 0x10e92c <_Z9F_DArcCosR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x10e918 ldr r0, [pc, #0x58] */
/* @0x10e91c mov r1, #0 */
/* @0x10e920 pop {r4, lr} */
/* @0x10e924 add r0, pc, r0 */
/* @0x10e928 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10e92c bl 0xb6760 <acosf@plt> */
/* @0x10e930 vldr s15, [pc, #52] */
/* @0x10e934 vldr s13, [pc, #52] */
/* @0x10e938 vldr s14, [pc, #52] */
/* @0x10e93c vmov s12, r0 */
/* @0x10e940 vmul.f32 s15, s12, s15 */
/* @0x10e944 vdiv.f32 s15, s15, s13 */
/* @0x10e948 vabs.f32 s13, s15 */
/* @0x10e94c vcmpe.f32 s13, s14 */
/* @0x10e950 vmrs APSR_nzcv, fpscr */
/* @0x10e954 vcvtpl.f64.f32 d6, s15 */
/* @0x10e958 movmi r2, #0 */
/* @0x10e95c movmi r3, #0 */
/* @0x10e960 vmovpl r2, r3, d6 */
/* @0x10e964 stm r4, {r2, r3} */
/* @0x10e968 pop {r4, pc} */
/* @0x10e96c teqmi r4, #0 */
/* @0x10e970 ldrdmi r0, r1, [r9], #-251 */
/* @0x10e974 strlo r12, [r7, -r12, lsr #11]! */
/* @0x10e978 eoreq r10, r2, r4, lsl #10 */

/* ── FUNC 0x10e97c · F_ArcTan(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10e97c mov r3, #0 */
/* @0x10e980 push {r4, lr} */
/* @0x10e984 mov r1, r3 */
/* @0x10e988 str r3, [r0, #0xc] */
/* @0x10e98c mov r4, r0 */
/* @0x10e990 ldr r0, [sp, #0x8] */
/* @0x10e994 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e998 bl 0xb676c <atanf@plt> */
/* @0x10e99c vldr s14, [pc, #36] */
/* @0x10e9a0 vmov s15, r0 */
/* @0x10e9a4 vabs.f32 s13, s15 */
/* @0x10e9a8 vcmpe.f32 s13, s14 */
/* @0x10e9ac vmrs APSR_nzcv, fpscr */
/* @0x10e9b0 vcvtpl.f64.f32 d6, s15 */
/* @0x10e9b4 movmi r2, #0 */
/* @0x10e9b8 movmi r3, #0 */
/* @0x10e9bc vmovpl r2, r3, d6 */
/* @0x10e9c0 stm r4, {r2, r3} */
/* @0x10e9c4 pop {r4, pc} */
/* @0x10e9c8 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10e9cc · F_DArcTan(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x10e9cc mov r3, #0 */
/* @0x10e9d0 push {r4, lr} */
/* @0x10e9d4 mov r1, r3 */
/* @0x10e9d8 str r3, [r0, #0xc] */
/* @0x10e9dc mov r4, r0 */
/* @0x10e9e0 ldr r0, [sp, #0x8] */
/* @0x10e9e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10e9e8 bl 0xb676c <atanf@plt> */
/* @0x10e9ec vldr s15, [pc, #52] */
/* @0x10e9f0 vldr s13, [pc, #52] */
/* @0x10e9f4 vldr s14, [pc, #52] */
/* @0x10e9f8 vmov s12, r0 */
/* @0x10e9fc vmul.f32 s15, s12, s15 */
/* @0x10ea00 vdiv.f32 s15, s15, s13 */
/* @0x10ea04 vabs.f32 s13, s15 */
/* @0x10ea08 vcmpe.f32 s13, s14 */
/* @0x10ea0c vmrs APSR_nzcv, fpscr */
/* @0x10ea10 vcvtpl.f64.f32 d6, s15 */
/* @0x10ea14 movmi r2, #0 */
/* @0x10ea18 movmi r3, #0 */
/* @0x10ea1c vmovpl r2, r3, d6 */
/* @0x10ea20 stm r4, {r2, r3} */
/* @0x10ea24 pop {r4, pc} */
/* @0x10ea28 teqmi r4, #0 */
/* @0x10ea2c ldrdmi r0, r1, [r9], #-251 */
/* @0x10ea30 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10ea34 · F_ArcTan2(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x10ea34 push {r4, r5, r6, lr} */
/* @0x10ea38 mov r1, #0 */
/* @0x10ea3c ldr r5, [sp, #0x10] */
/* @0x10ea40 mov r4, r0 */
/* @0x10ea44 str r1, [r0, #0xc] */
/* @0x10ea48 mov r0, r5 */
/* @0x10ea4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10ea50 mov r1, #1 */
/* @0x10ea54 mov r6, r0 */
/* @0x10ea58 mov r0, r5 */
/* @0x10ea5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10ea60 mov r1, r0 */
/* @0x10ea64 mov r0, r6 */
/* @0x10ea68 bl 0xb6778 <atan2f@plt> */
/* @0x10ea6c vldr s14, [pc, #36] */
/* @0x10ea70 vmov s15, r0 */
/* @0x10ea74 vabs.f32 s13, s15 */
/* @0x10ea78 vcmpe.f32 s13, s14 */
/* @0x10ea7c vmrs APSR_nzcv, fpscr */
/* @0x10ea80 vcvtpl.f64.f32 d6, s15 */
/* @0x10ea84 movmi r2, #0 */
/* @0x10ea88 movmi r3, #0 */
/* @0x10ea8c vmovpl r2, r3, d6 */
/* @0x10ea90 stm r4, {r2, r3} */
/* @0x10ea94 pop {r4, r5, r6, pc} */
/* @0x10ea98 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10ea9c · F_DArcTan2(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x10ea9c push {r4, r5, r6, lr} */
/* @0x10eaa0 mov r1, #0 */
/* @0x10eaa4 ldr r5, [sp, #0x10] */
/* @0x10eaa8 mov r4, r0 */
/* @0x10eaac str r1, [r0, #0xc] */
/* @0x10eab0 mov r0, r5 */
/* @0x10eab4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10eab8 mov r1, #1 */
/* @0x10eabc mov r6, r0 */
/* @0x10eac0 mov r0, r5 */
/* @0x10eac4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10eac8 mov r1, r0 */
/* @0x10eacc mov r0, r6 */
/* @0x10ead0 bl 0xb6778 <atan2f@plt> */
/* @0x10ead4 vldr s15, [pc, #52] */
/* @0x10ead8 vldr s13, [pc, #52] */
/* @0x10eadc vldr s14, [pc, #52] */
/* @0x10eae0 vmov s12, r0 */
/* @0x10eae4 vmul.f32 s15, s12, s15 */
/* @0x10eae8 vdiv.f32 s15, s15, s13 */
/* @0x10eaec vabs.f32 s13, s15 */
/* @0x10eaf0 vcmpe.f32 s13, s14 */
/* @0x10eaf4 vmrs APSR_nzcv, fpscr */
/* @0x10eaf8 vcvtpl.f64.f32 d6, s15 */
/* @0x10eafc movmi r2, #0 */
/* @0x10eb00 movmi r3, #0 */
/* @0x10eb04 vmovpl r2, r3, d6 */
/* @0x10eb08 stm r4, {r2, r3} */
/* @0x10eb0c pop {r4, r5, r6, pc} */
/* @0x10eb10 teqmi r4, #0 */
/* @0x10eb14 ldrdmi r0, r1, [r9], #-251 */
/* @0x10eb18 strlo r12, [r7, -r12, lsr #11]! */

/* ── FUNC 0x10eb1c · F_Power(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x10eb1c push {r3, r4, r5, r6, r7, lr} */
/* @0x10eb20 mov r1, #0 */
/* @0x10eb24 ldr r7, [sp, #0x18] */
/* @0x10eb28 mov r6, r0 */
/* @0x10eb2c str r1, [r0, #0xc] */
/* @0x10eb30 mov r0, r7 */
/* @0x10eb34 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10eb38 mov r4, r0 */
/* @0x10eb3c mov r5, r1 */
/* @0x10eb40 mov r0, r7 */
/* @0x10eb44 mov r1, #1 */
/* @0x10eb48 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10eb4c mov r2, r0 */
/* @0x10eb50 mov r3, r1 */
/* @0x10eb54 mov r0, r4 */
/* @0x10eb58 mov r1, r5 */
/* @0x10eb5c bl 0xb6784 <pow@plt> */
/* @0x10eb60 stm r6, {r0, r1} */
/* @0x10eb64 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x10eb68 · F_Median(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x10eb68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10eb6c add r11, sp, #32 */
/* @0x10eb70 ldr r9, [pc, #0xa4] */
/* @0x10eb74 sub sp, sp, #12 */
/* @0x10eb78 subs r6, r3, #0 */
/* @0x10eb7c ldr r9, [pc, r9] */
/* @0x10eb80 mov r4, #0 */
/* @0x10eb84 mov r8, r0 */
/* @0x10eb88 str r4, [r0, #0xc] */
/* @0x10eb8c ldr r3, [r9] */
/* @0x10eb90 str r4, [r0, #0x4] */
/* @0x10eb94 ldr r7, [r11, #0x4] */
/* @0x10eb98 str r4, [r0] */
/* @0x10eb9c str r3, [r11, #-0x28] */
/* @0x10eba0 ble 0x10ec00 <_Z8F_MedianR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x10eba4 lsl r3, r6, #3 */
/* @0x10eba8 add r3, r3, #8 */
/* @0x10ebac sub sp, sp, r3 */
/* @0x10ebb0 mov r10, sp */
/* @0x10ebb4 mov r5, sp */
/* @0x10ebb8 mov r1, r4 */
/* @0x10ebbc mov r0, r7 */
/* @0x10ebc0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10ebc4 add r4, r4, #1 */
/* @0x10ebc8 cmp r4, r6 */
/* @0x10ebcc strd r0, r1, [r5], #8 */
/* @0x10ebd0 bne 0x10ebb8 <_Z8F_MedianR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x10ebd4 ldr r3, [pc, #0x44] */
/* @0x10ebd8 mov r1, r4 */
/* @0x10ebdc asr r4, r4, #1 */
/* @0x10ebe0 mov r2, #8 */
/* @0x10ebe4 ldr r3, [pc, r3] */
/* @0x10ebe8 mov r0, r10 */
/* @0x10ebec bl 0xb66dc <qsort@plt> */
/* @0x10ebf0 add r3, r10, r4, lsl #3 */
/* @0x10ebf4 ldr r2, [r10, r4, lsl #3] */
/* @0x10ebf8 ldr r3, [r3, #0x4] */
/* @0x10ebfc stm r8, {r2, r3} */
/* @0x10ec00 ldr r2, [r11, #-0x28] */
/* @0x10ec04 ldr r3, [r9] */
/* @0x10ec08 cmp r2, r3 */
/* @0x10ec0c bne 0x10ec18 <_Z8F_MedianR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10ec10 sub sp, r11, #32 */
/* @0x10ec14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10ec18 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x10ec1c .word 0x002dedd4 */
/* @0x10ec20 eoreq pc, sp, r12, ror #12 */

/* ── FUNC 0x10ec24 · F_Real(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x10ec24 push {r4, lr} */
/* @0x10ec28 mov r2, #0 */
/* @0x10ec2c ldr r3, [sp, #0x8] */
/* @0x10ec30 mov r4, r0 */
/* @0x10ec34 str r2, [r0, #0xc] */
/* @0x10ec38 ldr r2, [r3, #0xc] */
/* @0x10ec3c bic r2, r2, #-16777216 */
/* @0x10ec40 cmp r2, #0 */
/* @0x10ec44 bne 0x10ec54 <_Z6F_RealR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x10ec48 ldm r3, {r0, r1} */
/* @0x10ec4c stm r4, {r0, r1} */
/* @0x10ec50 pop {r4, pc} */
/* @0x10ec54 mov r0, r3 */
/* @0x10ec58 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x10ec5c stm r4, {r0, r1} */
/* @0x10ec60 pop {r4, pc} */
