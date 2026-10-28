/* libyoyo.so 覆盖卡组 0277
 * 函数 0x2cf0f8..0x2d071c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2cf0f8 · b2PrismaticJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2cf0f8 ldr r3, [r1, #0x34] */
/* @0x2cf0fc vldr s15, [r1, #80] */
/* @0x2cf100 vldr s12, [r3, #24] */
/* @0x2cf104 vldr s11, [r3, #20] */
/* @0x2cf108 vmul.f32 s14, s12, s15 */
/* @0x2cf10c vldr s13, [r1, #76] */
/* @0x2cf110 vldr s9, [r3, #16] */
/* @0x2cf114 vldr s10, [r3, #12] */
/* @0x2cf118 vmul.f32 s15, s11, s15 */
/* @0x2cf11c vmla.f32 s14, s13, s11 */
/* @0x2cf120 vnmls.f32 s15, s12, s13 */
/* @0x2cf124 vadd.f32 s14, s14, s9 */
/* @0x2cf128 vadd.f32 s15, s15, s10 */
/* @0x2cf12c vstr s14, [r0, #4] */
/* @0x2cf130 vstr s15, [r0] */
/* @0x2cf134 bx lr */

/* ── FUNC 0x2cf138 · b2PrismaticJoint::GetReactionForce(float) const · size=72 · insn=18 */
/* @0x2cf138 vldr s14, [r1, #116] */
/* @0x2cf13c vldr s15, [r1, #112] */
/* @0x2cf140 vadd.f32 s15, s14, s15 */
/* @0x2cf144 vldr s9, [r1, #184] */
/* @0x2cf148 vldr s14, [r1, #188] */
/* @0x2cf14c vldr s12, [r1, #104] */
/* @0x2cf150 vldr s10, [r1, #196] */
/* @0x2cf154 vldr s11, [r1, #192] */
/* @0x2cf158 vmov s13, r2 */
/* @0x2cf15c vmul.f32 s14, s15, s14 */
/* @0x2cf160 vmul.f32 s15, s15, s9 */
/* @0x2cf164 vmla.f32 s14, s12, s10 */
/* @0x2cf168 vmla.f32 s15, s12, s11 */
/* @0x2cf16c vmul.f32 s14, s13, s14 */
/* @0x2cf170 vmul.f32 s15, s13, s15 */
/* @0x2cf174 vstr s14, [r0, #4] */
/* @0x2cf178 vstr s15, [r0] */
/* @0x2cf17c bx lr */

/* ── FUNC 0x2cf180 · b2PrismaticJoint::GetReactionTorque(float) const · size=20 · insn=5 */
/* @0x2cf180 vmov s14, r1 */
/* @0x2cf184 vldr s15, [r0, #108] */
/* @0x2cf188 vmul.f32 s14, s14, s15 */
/* @0x2cf18c vmov r0, s14 */
/* @0x2cf190 bx lr */

/* ── FUNC 0x2cf194 · b2PrismaticJoint::~b2PrismaticJoint() · size=24 · insn=6 */
/* @0x2cf194 ldr r3, [pc, #0xc] */
/* @0x2cf198 ldr r3, [pc, r3] */
/* @0x2cf19c add r3, r3, #8 */
/* @0x2cf1a0 str r3, [r0] */
/* @0x2cf1a4 bx lr */
/* @0x2cf1a8 ldrheq r2, [r2], -r12 */

/* ── FUNC 0x2cf194 · b2PrismaticJoint::~b2PrismaticJoint() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2cf1ac · b2PrismaticJoint::Dump() · size=432 · insn=108 */
/* @0x2cf1ac push {r4, r5, r6, lr} */
/* @0x2cf1b0 mov r4, r0 */
/* @0x2cf1b4 ldr r2, [r4, #0x30] */
/* @0x2cf1b8 sub sp, sp, #8 */
/* @0x2cf1bc ldr r3, [r4, #0x34] */
/* @0x2cf1c0 ldr r0, [pc, #0x158] */
/* @0x2cf1c4 ldr r6, [r2, #0x8] */
/* @0x2cf1c8 add r0, pc, r0 */
/* @0x2cf1cc ldr r5, [r3, #0x8] */
/* @0x2cf1d0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf1d4 ldr r0, [pc, #0x148] */
/* @0x2cf1d8 mov r1, r6 */
/* @0x2cf1dc add r0, pc, r0 */
/* @0x2cf1e0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf1e4 ldr r0, [pc, #0x13c] */
/* @0x2cf1e8 mov r1, r5 */
/* @0x2cf1ec add r0, pc, r0 */
/* @0x2cf1f0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf1f4 ldr r0, [pc, #0x130] */
/* @0x2cf1f8 ldrb r1, [r4, #0x3d] */
/* @0x2cf1fc add r0, pc, r0 */
/* @0x2cf200 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf204 vldr s13, [r4, #68] */
/* @0x2cf208 vldr s14, [r4, #72] */
/* @0x2cf20c vcvt.f64.f32 d5, s13 */
/* @0x2cf210 ldr r0, [pc, #0x118] */
/* @0x2cf214 add r0, pc, r0 */
/* @0x2cf218 vcvt.f64.f32 d7, s14 */
/* @0x2cf21c vmov r2, r3, d5 */
/* @0x2cf220 vstr d7, [sp] */
/* @0x2cf224 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf228 vldr s13, [r4, #76] */
/* @0x2cf22c vldr s14, [r4, #80] */
/* @0x2cf230 vcvt.f64.f32 d5, s13 */
/* @0x2cf234 ldr r0, [pc, #0xf8] */
/* @0x2cf238 add r0, pc, r0 */
/* @0x2cf23c vcvt.f64.f32 d7, s14 */
/* @0x2cf240 vmov r2, r3, d5 */
/* @0x2cf244 vstr d7, [sp] */
/* @0x2cf248 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf24c vldr s13, [r4, #84] */
/* @0x2cf250 vldr s14, [r4, #88] */
/* @0x2cf254 vcvt.f64.f32 d5, s13 */
/* @0x2cf258 ldr r0, [pc, #0xd8] */
/* @0x2cf25c add r0, pc, r0 */
/* @0x2cf260 vcvt.f64.f32 d7, s14 */
/* @0x2cf264 vmov r2, r3, d5 */
/* @0x2cf268 vstr d7, [sp] */
/* @0x2cf26c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf270 vldr s15, [r4, #100] */
/* @0x2cf274 vcvt.f64.f32 d6, s15 */
/* @0x2cf278 ldr r0, [pc, #0xbc] */
/* @0x2cf27c add r0, pc, r0 */
/* @0x2cf280 vmov r2, r3, d6 */
/* @0x2cf284 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf288 ldr r0, [pc, #0xb0] */
/* @0x2cf28c ldrb r1, [r4, #0x88] */
/* @0x2cf290 add r0, pc, r0 */
/* @0x2cf294 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf298 vldr s15, [r4, #120] */
/* @0x2cf29c vcvt.f64.f32 d5, s15 */
/* @0x2cf2a0 ldr r0, [pc, #0x9c] */
/* @0x2cf2a4 add r0, pc, r0 */
/* @0x2cf2a8 vmov r2, r3, d5 */
/* @0x2cf2ac bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf2b0 vldr s15, [r4, #124] */
/* @0x2cf2b4 vcvt.f64.f32 d6, s15 */
/* @0x2cf2b8 ldr r0, [pc, #0x88] */
/* @0x2cf2bc add r0, pc, r0 */
/* @0x2cf2c0 vmov r2, r3, d6 */
/* @0x2cf2c4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf2c8 ldr r0, [pc, #0x7c] */
/* @0x2cf2cc ldrb r1, [r4, #0x89] */
/* @0x2cf2d0 add r0, pc, r0 */
/* @0x2cf2d4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf2d8 vldr s15, [r4, #132] */
/* @0x2cf2dc vcvt.f64.f32 d5, s15 */
/* @0x2cf2e0 ldr r0, [pc, #0x68] */
/* @0x2cf2e4 add r0, pc, r0 */
/* @0x2cf2e8 vmov r2, r3, d5 */
/* @0x2cf2ec bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf2f0 vldr s15, [r4, #128] */
/* @0x2cf2f4 vcvt.f64.f32 d6, s15 */
/* @0x2cf2f8 ldr r0, [pc, #0x54] */
/* @0x2cf2fc add r0, pc, r0 */
/* @0x2cf300 vmov r2, r3, d6 */
/* @0x2cf304 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf308 ldr r0, [pc, #0x48] */
/* @0x2cf30c ldr r1, [r4, #0x38] */
/* @0x2cf310 add r0, pc, r0 */
/* @0x2cf314 add sp, sp, #8 */
/* @0x2cf318 pop {r4, r5, r6, lr} */
/* @0x2cf31c b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cf320 andeq r12, r8, r0, lsr #30 */
/* @0x2cf324 ldrdeq r12, sp, [r8], -r0 */
/* @0x2cf328 ldrdeq r12, sp, [r8], -r12 */
/* @0x2cf32c andeq r12, r8, r8, ror #25 */
/* @0x2cf330 strdeq r12, sp, [r8], -r4 */
/* @0x2cf334 strdeq r12, sp, [r8], -r12 */
/* @0x2cf338 andeq r12, r8, r8, lsr #29 */
/* @0x2cf33c strheq r12, [r8], -r0 */
/* @0x2cf340 strheq r12, [r8], -r12 */
/* @0x2cf344 andeq r12, r8, r8, asr #29 */
/* @0x2cf348 ldrdeq r12, sp, [r8], -r4 */
/* @0x2cf34c andeq r12, r8, r4, ror #29 */
/* @0x2cf350 strdeq r12, sp, [r8], -r0 */
/* @0x2cf354 strdeq r12, sp, [r8], -r4 */
/* @0x2cf358 andeq r12, r8, r8, lsr #25 */

/* ── FUNC 0x2cf35c · b2PrismaticJoint::~b2PrismaticJoint() · size=40 · insn=10 */
/* @0x2cf35c ldr r3, [pc, #0x1c] */
/* @0x2cf360 push {r4, lr} */
/* @0x2cf364 ldr r3, [pc, r3] */
/* @0x2cf368 mov r4, r0 */
/* @0x2cf36c add r3, r3, #8 */
/* @0x2cf370 str r3, [r0] */
/* @0x2cf374 bl 0x27d1d0 <_ZdlPv> */
/* @0x2cf378 mov r0, r4 */
/* @0x2cf37c pop {r4, pc} */
/* @0x2cf380 ldrsheq r2, [r2], -r0 */

/* ── FUNC 0x2cf384 · b2PrismaticJoint::SolveVelocityConstraints(b2SolverData const&) · size=912 · insn=228 */
/* @0x2cf384 ldr r2, [r0, #0x90] */
/* @0x2cf388 ldr r3, [r0, #0x94] */
/* @0x2cf38c push {r4, r5, r6, r7, lr} */
/* @0x2cf390 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2cf394 mov r4, r0 */
/* @0x2cf398 vldr s23, [r0, #168] */
/* @0x2cf39c vldr s22, [r0, #172] */
/* @0x2cf3a0 ldrb r0, [r0, #0x89] */
/* @0x2cf3a4 mov r5, r1 */
/* @0x2cf3a8 add r2, r2, r2, lsl #1 */
/* @0x2cf3ac ldr r1, [r1, #0x1c] */
/* @0x2cf3b0 add r3, r3, r3, lsl #1 */
/* @0x2cf3b4 cmp r0, #0 */
/* @0x2cf3b8 sub sp, sp, #36 */
/* @0x2cf3bc add r2, r1, r2, lsl #2 */
/* @0x2cf3c0 add r3, r1, r3, lsl #2 */
/* @0x2cf3c4 vldr s25, [r4, #176] */
/* @0x2cf3c8 vldr s24, [r4, #180] */
/* @0x2cf3cc vldr s21, [r2] */
/* @0x2cf3d0 vldr s19, [r2, #4] */
/* @0x2cf3d4 vldr s17, [r2, #8] */
/* @0x2cf3d8 vldr s20, [r3] */
/* @0x2cf3dc vldr s18, [r3, #4] */
/* @0x2cf3e0 vldr s16, [r3, #8] */
/* @0x2cf3e4 beq 0x2cf48c <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x108> */
/* @0x2cf3e8 ldr r3, [r4, #0x8c] */
/* @0x2cf3ec cmp r3, #3 */
/* @0x2cf3f0 beq 0x2cf48c <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x108> */
/* @0x2cf3f4 vsub.f32 s15, s18, s19 */
/* @0x2cf3f8 vldr s10, [r4, #188] */
/* @0x2cf3fc vldr s13, [r4, #184] */
/* @0x2cf400 vldr s12, [r4, #212] */
/* @0x2cf404 vldr s11, [r4, #208] */
/* @0x2cf408 vldr s6, [r4, #132] */
/* @0x2cf40c vldr s9, [r4, #116] */
/* @0x2cf410 vldr s8, [r4, #252] */
/* @0x2cf414 vldr s7, [r5] */
/* @0x2cf418 vldr s14, [r4, #128] */
/* @0x2cf41c vmul.f32 s15, s15, s10 */
/* @0x2cf420 vsub.f32 s5, s20, s21 */
/* @0x2cf424 vmla.f32 s15, s5, s13 */
/* @0x2cf428 vmla.f32 s15, s12, s16 */
/* @0x2cf42c vmls.f32 s15, s11, s17 */
/* @0x2cf430 vsub.f32 s15, s6, s15 */
/* @0x2cf434 vmov.f32 s6, s9 */
/* @0x2cf438 vmla.f32 s6, s15, s8 */
/* @0x2cf43c vmul.f32 s14, s7, s14 */
/* @0x2cf440 vcmpe.f32 s14, s6 */
/* @0x2cf444 vneg.f32 s15, s14 */
/* @0x2cf448 vmrs APSR_nzcv, fpscr */
/* @0x2cf44c vmovgt.f32 s14, s6 */
/* @0x2cf450 vcmpe.f32 s15, s14 */
/* @0x2cf454 vmrs APSR_nzcv, fpscr */
/* @0x2cf458 vmovle.f32 s15, s14 */
/* @0x2cf45c vstr s15, [r4, #116] */
/* @0x2cf460 vsub.f32 s15, s15, s9 */
/* @0x2cf464 vmul.f32 s13, s15, s13 */
/* @0x2cf468 vmul.f32 s14, s15, s10 */
/* @0x2cf46c vmul.f32 s11, s11, s15 */
/* @0x2cf470 vmul.f32 s15, s12, s15 */
/* @0x2cf474 vmls.f32 s21, s23, s13 */
/* @0x2cf478 vmla.f32 s20, s22, s13 */
/* @0x2cf47c vmls.f32 s19, s23, s14 */
/* @0x2cf480 vmla.f32 s18, s22, s14 */
/* @0x2cf484 vmls.f32 s17, s25, s11 */
/* @0x2cf488 vmla.f32 s16, s24, s15 */
/* @0x2cf48c vldr s15, [r4, #196] */
/* @0x2cf490 vldr s10, [r4, #192] */
/* @0x2cf494 vldr s11, [r4, #204] */
/* @0x2cf498 ldrb r3, [r4, #0x88] */
/* @0x2cf49c vldr s12, [r4, #200] */
/* @0x2cf4a0 cmp r3, #0 */
/* @0x2cf4a4 vsub.f32 s13, s18, s19 */
/* @0x2cf4a8 vmul.f32 s15, s13, s15 */
/* @0x2cf4ac vsub.f32 s14, s20, s21 */
/* @0x2cf4b0 vmla.f32 s15, s14, s10 */
/* @0x2cf4b4 vmla.f32 s15, s16, s11 */
/* @0x2cf4b8 vsub.f32 s11, s16, s17 */
/* @0x2cf4bc vmls.f32 s15, s17, s12 */
/* @0x2cf4c0 beq 0x2cf4d0 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x14c> */
/* @0x2cf4c4 ldr r3, [r4, #0x8c] */
/* @0x2cf4c8 cmp r3, #0 */
/* @0x2cf4cc bne 0x2cf590 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x20c> */
/* @0x2cf4d0 mov r0, sp */
/* @0x2cf4d4 add r1, r4, #216 */
/* @0x2cf4d8 add r2, sp, #20 */
/* @0x2cf4dc vneg.f32 s15, s15 */
/* @0x2cf4e0 vneg.f32 s11, s11 */
/* @0x2cf4e4 vstr s15, [sp, #20] */
/* @0x2cf4e8 vstr s11, [sp, #24] */
/* @0x2cf4ec bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2> */
/* @0x2cf4f0 vldr s14, [sp, #4] */
/* @0x2cf4f4 vmov.f32 s7, s14 */
/* @0x2cf4f8 vldr s15, [sp] */
/* @0x2cf4fc vldr s8, [r4, #200] */
/* @0x2cf500 vldr s9, [r4, #204] */
/* @0x2cf504 vldr s12, [r4, #192] */
/* @0x2cf508 vldr s13, [r4, #196] */
/* @0x2cf50c vldr s10, [r4, #108] */
/* @0x2cf510 vmov.f32 s6, s14 */
/* @0x2cf514 vldr s11, [r4, #104] */
/* @0x2cf518 vmla.f32 s7, s15, s8 */
/* @0x2cf51c vmla.f32 s6, s15, s9 */
/* @0x2cf520 vmul.f32 s12, s15, s12 */
/* @0x2cf524 vmul.f32 s13, s15, s13 */
/* @0x2cf528 vmls.f32 s17, s25, s7 */
/* @0x2cf52c vmla.f32 s16, s24, s6 */
/* @0x2cf530 vmls.f32 s21, s23, s12 */
/* @0x2cf534 vmla.f32 s20, s22, s12 */
/* @0x2cf538 vmls.f32 s19, s23, s13 */
/* @0x2cf53c vmla.f32 s18, s22, s13 */
/* @0x2cf540 vadd.f32 s14, s10, s14 */
/* @0x2cf544 vadd.f32 s15, s11, s15 */
/* @0x2cf548 vstr s14, [r4, #108] */
/* @0x2cf54c vstr s15, [r4, #104] */
/* @0x2cf550 ldr r2, [r4, #0x90] */
/* @0x2cf554 ldr r3, [r4, #0x94] */
/* @0x2cf558 ldr r1, [r5, #0x1c] */
/* @0x2cf55c add r2, r2, r2, lsl #1 */
/* @0x2cf560 add r3, r3, r3, lsl #1 */
/* @0x2cf564 add r2, r1, r2, lsl #2 */
/* @0x2cf568 vstr s21, [r2] */
/* @0x2cf56c vstr s19, [r2, #4] */
/* @0x2cf570 vstr s17, [r2, #8] */
/* @0x2cf574 add r3, r1, r3, lsl #2 */
/* @0x2cf578 vstr s20, [r3] */
/* @0x2cf57c vstr s18, [r3, #4] */
/* @0x2cf580 vstr s16, [r3, #8] */
/* @0x2cf584 add sp, sp, #36 */
/* @0x2cf588 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2cf58c pop {r4, r5, r6, r7, pc} */
/* @0x2cf590 vldr s8, [r4, #188] */
/* @0x2cf594 vmul.f32 s13, s13, s8 */
/* @0x2cf598 vldr s9, [r4, #184] */
/* @0x2cf59c vldr s10, [r4, #212] */
/* @0x2cf5a0 vldr s12, [r4, #208] */
/* @0x2cf5a4 add r6, r4, #216 */
/* @0x2cf5a8 add r7, sp, #20 */
/* @0x2cf5ac add r0, sp, #8 */
/* @0x2cf5b0 mov r1, r6 */
/* @0x2cf5b4 vldr s27, [r4, #104] */
/* @0x2cf5b8 mov r2, r7 */
/* @0x2cf5bc vldr s26, [r4, #108] */
/* @0x2cf5c0 vldr s28, [r4, #112] */
/* @0x2cf5c4 vmla.f32 s13, s14, s9 */
/* @0x2cf5c8 vmla.f32 s13, s16, s10 */
/* @0x2cf5cc vmls.f32 s13, s17, s12 */
/* @0x2cf5d0 vneg.f32 s29, s15 */
/* @0x2cf5d4 vneg.f32 s30, s11 */
/* @0x2cf5d8 vstr s29, [sp, #20] */
/* @0x2cf5dc vneg.f32 s13, s13 */
/* @0x2cf5e0 vstr s30, [sp, #24] */
/* @0x2cf5e4 vstr s13, [sp, #28] */
/* @0x2cf5e8 bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3> */
/* @0x2cf5ec vldr s10, [r4, #104] */
/* @0x2cf5f0 vldr s11, [r4, #108] */
/* @0x2cf5f4 vldr s15, [r4, #112] */
/* @0x2cf5f8 vldr s12, [sp, #8] */
/* @0x2cf5fc vldr s14, [sp, #12] */
/* @0x2cf600 vldr s13, [sp, #16] */
/* @0x2cf604 vadd.f32 s12, s10, s12 */
/* @0x2cf608 ldr r3, [r4, #0x8c] */
/* @0x2cf60c cmp r3, #1 */
/* @0x2cf610 vadd.f32 s14, s11, s14 */
/* @0x2cf614 vstr s12, [r4, #104] */
/* @0x2cf618 vadd.f32 s15, s13, s15 */
/* @0x2cf61c vstr s14, [r4, #108] */
/* @0x2cf620 vstr s15, [r4, #112] */
/* @0x2cf624 beq 0x2cf6f8 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x374> */
/* @0x2cf628 cmp r3, #2 */
/* @0x2cf62c bne 0x2cf644 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x2c0> */
/* @0x2cf630 vcmpe.f32 s15, #0 */
/* @0x2cf634 vldr s14, [pc, #212] */
/* @0x2cf638 vmrs APSR_nzcv, fpscr */
/* @0x2cf63c vmovpl.f32 s15, s14 */
/* @0x2cf640 vstr s15, [r4, #112] */
/* @0x2cf644 vldr s13, [r4, #244] */
/* @0x2cf648 vldr s14, [r4, #240] */
/* @0x2cf64c vsub.f32 s15, s15, s28 */
/* @0x2cf650 mov r0, r7 */
/* @0x2cf654 mov r1, r6 */
/* @0x2cf658 mov r2, sp */
/* @0x2cf65c vmls.f32 s30, s15, s13 */
/* @0x2cf660 vmls.f32 s29, s15, s14 */
/* @0x2cf664 vstr s30, [sp, #4] */
/* @0x2cf668 vstr s29, [sp] */
/* @0x2cf66c bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2> */
/* @0x2cf670 vldr s13, [sp, #24] */
/* @0x2cf674 vadd.f32 s13, s26, s13 */
/* @0x2cf678 vldr s12, [sp, #20] */
/* @0x2cf67c vldr s15, [r4, #112] */
/* @0x2cf680 vldr s6, [r4, #200] */
/* @0x2cf684 vldr s7, [r4, #204] */
/* @0x2cf688 vldr s14, [r4, #184] */
/* @0x2cf68c vldr s8, [r4, #192] */
/* @0x2cf690 vldr s9, [r4, #196] */
/* @0x2cf694 vldr s10, [r4, #208] */
/* @0x2cf698 vldr s11, [r4, #212] */
/* @0x2cf69c vadd.f32 s12, s27, s12 */
/* @0x2cf6a0 vstr s13, [r4, #108] */
/* @0x2cf6a4 vsub.f32 s26, s13, s26 */
/* @0x2cf6a8 vstr s12, [r4, #104] */
/* @0x2cf6ac vsub.f32 s27, s12, s27 */
/* @0x2cf6b0 vmov.f32 s13, s26 */
/* @0x2cf6b4 vsub.f32 s28, s15, s28 */
/* @0x2cf6b8 vldr s15, [r4, #188] */
/* @0x2cf6bc vmla.f32 s13, s27, s6 */
/* @0x2cf6c0 vmla.f32 s26, s27, s7 */
/* @0x2cf6c4 vmul.f32 s14, s28, s14 */
/* @0x2cf6c8 vmul.f32 s15, s28, s15 */
/* @0x2cf6cc vmla.f32 s14, s27, s8 */
/* @0x2cf6d0 vmla.f32 s15, s27, s9 */
/* @0x2cf6d4 vmla.f32 s13, s28, s10 */
/* @0x2cf6d8 vmla.f32 s26, s28, s11 */
/* @0x2cf6dc vmls.f32 s21, s23, s14 */
/* @0x2cf6e0 vmla.f32 s20, s22, s14 */
/* @0x2cf6e4 vmls.f32 s19, s23, s15 */
/* @0x2cf6e8 vmla.f32 s18, s22, s15 */
/* @0x2cf6ec vmls.f32 s17, s25, s13 */
/* @0x2cf6f0 vmla.f32 s16, s24, s26 */
/* @0x2cf6f4 b 0x2cf550 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x1cc> */
/* @0x2cf6f8 vcmpe.f32 s15, #0 */
/* @0x2cf6fc vldr s14, [pc, #12] */
/* @0x2cf700 vmrs APSR_nzcv, fpscr */
/* @0x2cf704 vmovle.f32 s15, s14 */
/* @0x2cf708 vstr s15, [r4, #112] */
/* @0x2cf70c b 0x2cf644 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x2c0> */
/* @0x2cf710 andeq r0, r0, r0 */

/* ── FUNC 0x2cf714 · b2PrismaticJoint::SolvePositionConstraints(b2SolverData const&) · size=1164 · insn=291 */
/* @0x2cf714 push {r4, r5, r6, r7, lr} */
/* @0x2cf718 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2cf71c mov r4, r0 */
/* @0x2cf720 ldr r5, [r0, #0x90] */
/* @0x2cf724 sub sp, sp, #84 */
/* @0x2cf728 ldr r6, [r0, #0x94] */
/* @0x2cf72c mov r7, r1 */
/* @0x2cf730 ldr r3, [r1, #0x18] */
/* @0x2cf734 add r5, r5, r5, lsl #1 */
/* @0x2cf738 add r6, r6, r6, lsl #1 */
/* @0x2cf73c add r5, r3, r5, lsl #2 */
/* @0x2cf740 vldr s25, [r5, #8] */
/* @0x2cf744 vmov r0, s25 */
/* @0x2cf748 add r6, r3, r6, lsl #2 */
/* @0x2cf74c bl 0xb6580 <sinf@plt> */
/* @0x2cf750 vldr s8, [r6, #4] */
/* @0x2cf754 vstr s8, [sp, #8] */
/* @0x2cf758 vldr s26, [r6, #8] */
/* @0x2cf75c vmov s23, r0 */
/* @0x2cf760 vmov r0, s25 */
/* @0x2cf764 bl 0xb658c <cosf@plt> */
/* @0x2cf768 vmov s24, r0 */
/* @0x2cf76c vmov r0, s26 */
/* @0x2cf770 bl 0xb6580 <sinf@plt> */
/* @0x2cf774 vmov s16, r0 */
/* @0x2cf778 vmov r0, s26 */
/* @0x2cf77c bl 0xb658c <cosf@plt> */
/* @0x2cf780 vldr s14, [r4, #80] */
/* @0x2cf784 vldr s15, [r4, #164] */
/* @0x2cf788 vsub.f32 s15, s14, s15 */
/* @0x2cf78c vldr s5, [r4, #76] */
/* @0x2cf790 vldr s8, [r4, #160] */
/* @0x2cf794 vldr s6, [r4, #72] */
/* @0x2cf798 vldr s14, [r4, #156] */
/* @0x2cf79c vldr s7, [r4, #68] */
/* @0x2cf7a0 vldr s13, [r4, #152] */
/* @0x2cf7a4 vldr s17, [r4, #96] */
/* @0x2cf7a8 vldr s10, [r4, #92] */
/* @0x2cf7ac vldr s11, [r5, #4] */
/* @0x2cf7b0 vstr s11, [sp] */
/* @0x2cf7b4 vldr s20, [r4, #88] */
/* @0x2cf7b8 vldr s31, [r6] */
/* @0x2cf7bc vldr s11, [r5] */
/* @0x2cf7c0 vstr s11, [sp, #4] */
/* @0x2cf7c4 vldr s11, [r4, #84] */
/* @0x2cf7c8 vldr s9, [r4, #100] */
/* @0x2cf7cc vldr s29, [r4, #168] */
/* @0x2cf7d0 vldr s30, [r4, #172] */
/* @0x2cf7d4 vsub.f32 s8, s5, s8 */
/* @0x2cf7d8 vldr s27, [r4, #176] */
/* @0x2cf7dc vldr s28, [r4, #180] */
/* @0x2cf7e0 vsub.f32 s14, s6, s14 */
/* @0x2cf7e4 vmul.f32 s21, s14, s24 */
/* @0x2cf7e8 vmov s12, r0 */
/* @0x2cf7ec vmul.f32 s22, s15, s12 */
/* @0x2cf7f0 vmul.f32 s15, s15, s16 */
/* @0x2cf7f4 vmla.f32 s22, s8, s16 */
/* @0x2cf7f8 vsub.f32 s13, s7, s13 */
/* @0x2cf7fc vnmls.f32 s15, s8, s12 */
/* @0x2cf800 vldr s8, [sp, #8] */
/* @0x2cf804 vmul.f32 s18, s17, s24 */
/* @0x2cf808 vmla.f32 s21, s13, s23 */
/* @0x2cf80c vmul.f32 s14, s14, s23 */
/* @0x2cf810 vadd.f32 s12, s22, s8 */
/* @0x2cf814 vldr s8, [sp] */
/* @0x2cf818 vmla.f32 s18, s10, s23 */
/* @0x2cf81c vmul.f32 s17, s17, s23 */
/* @0x2cf820 vsub.f32 s12, s12, s8 */
/* @0x2cf824 vnmls.f32 s14, s13, s24 */
/* @0x2cf828 vmul.f32 s19, s20, s23 */
/* @0x2cf82c vadd.f32 s13, s15, s31 */
/* @0x2cf830 vsub.f32 s12, s12, s21 */
/* @0x2cf834 vnmls.f32 s17, s10, s24 */
/* @0x2cf838 vldr s10, [sp, #4] */
/* @0x2cf83c vsub.f32 s13, s13, s10 */
/* @0x2cf840 vnmls.f32 s19, s11, s24 */
/* @0x2cf844 vmul.f32 s20, s20, s24 */
/* @0x2cf848 vmul.f32 s16, s12, s18 */
/* @0x2cf84c vsub.f32 s13, s13, s14 */
/* @0x2cf850 vmla.f32 s20, s11, s23 */
/* @0x2cf854 vmla.f32 s16, s13, s17 */
/* @0x2cf858 vmul.f32 s24, s22, s19 */
/* @0x2cf85c vmul.f32 s22, s22, s17 */
/* @0x2cf860 vsub.f32 s11, s26, s25 */
/* @0x2cf864 vadd.f32 s21, s21, s12 */
/* @0x2cf868 vnmls.f32 s24, s15, s20 */
/* @0x2cf86c vnmls.f32 s22, s15, s18 */
/* @0x2cf870 vsub.f32 s15, s11, s9 */
/* @0x2cf874 vcmpe.f32 s16, #0 */
/* @0x2cf878 vmul.f32 s23, s19, s21 */
/* @0x2cf87c vmrs APSR_nzcv, fpscr */
/* @0x2cf880 vmul.f32 s21, s21, s17 */
/* @0x2cf884 vadd.f32 s14, s14, s13 */
/* @0x2cf888 vnegle.f32 s16, s16 */
/* @0x2cf88c vcmpe.f32 s15, #0 */
/* @0x2cf890 vneggt.f32 s9, s16 */
/* @0x2cf894 vmovle.f32 s9, s16 */
/* @0x2cf898 vmrs APSR_nzcv, fpscr */
/* @0x2cf89c vstrgt s15, [sp, #12] */
/* @0x2cf8a0 ldrb r3, [r4, #0x88] */
/* @0x2cf8a4 vnegle.f32 s15, s15 */
/* @0x2cf8a8 vneggt.f32 s8, s15 */
/* @0x2cf8ac vstrle s15, [sp, #12] */
/* @0x2cf8b0 vmovle.f32 s8, s15 */
/* @0x2cf8b4 cmp r3, #0 */
/* @0x2cf8b8 vnmls.f32 s23, s20, s14 */
/* @0x2cf8bc vnmls.f32 s21, s14, s18 */
/* @0x2cf8c0 beq 0x2cf9d8 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x2c4> */
/* @0x2cf8c4 vldr s11, [r4, #124] */
/* @0x2cf8c8 vldr s15, [r4, #120] */
/* @0x2cf8cc vsub.f32 s14, s11, s15 */
/* @0x2cf8d0 vmul.f32 s12, s12, s20 */
/* @0x2cf8d4 vcmpe.f32 s14, #0 */
/* @0x2cf8d8 vmrs APSR_nzcv, fpscr */
/* @0x2cf8dc vnegle.f32 s14, s14 */
/* @0x2cf8e0 vmla.f32 s12, s13, s19 */
/* @0x2cf8e4 vldr s13, [pc, #664] */
/* @0x2cf8e8 vcmpe.f32 s14, s13 */
/* @0x2cf8ec vmrs APSR_nzcv, fpscr */
/* @0x2cf8f0 bpl 0x2cfacc <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3b8> */
/* @0x2cf8f4 vldr s14, [pc, #652] */
/* @0x2cf8f8 vcmpe.f32 s12, s14 */
/* @0x2cf8fc vmrs APSR_nzcv, fpscr */
/* @0x2cf900 bmi 0x2cfb08 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3f4> */
/* @0x2cf904 vldr s14, [pc, #640] */
/* @0x2cf908 vcmpe.f32 s12, #0 */
/* @0x2cf90c vmrs APSR_nzcv, fpscr */
/* @0x2cf910 vnegle.f32 s12, s12 */
/* @0x2cf914 vcmpe.f32 s16, s12 */
/* @0x2cf918 vmrs APSR_nzcv, fpscr */
/* @0x2cf91c vmovle.f32 s16, s12 */
/* @0x2cf920 vstr s9, [sp, #32] */
/* @0x2cf924 vstr s14, [sp, #40] */
/* @0x2cf928 add r0, sp, #20 */
/* @0x2cf92c add r1, sp, #44 */
/* @0x2cf930 vmul.f32 s9, s27, s23 */
/* @0x2cf934 add r2, sp, #32 */
/* @0x2cf938 vstr s8, [sp, #36] */
/* @0x2cf93c vadd.f32 s15, s29, s30 */
/* @0x2cf940 vmul.f32 s12, s27, s21 */
/* @0x2cf944 vmov.f32 s11, s15 */
/* @0x2cf948 vmla.f32 s15, s9, s23 */
/* @0x2cf94c vmul.f32 s13, s28, s22 */
/* @0x2cf950 vmla.f32 s11, s12, s21 */
/* @0x2cf954 vmul.f32 s10, s28, s24 */
/* @0x2cf958 vmul.f32 s14, s13, s24 */
/* @0x2cf95c vmla.f32 s15, s10, s24 */
/* @0x2cf960 vmla.f32 s14, s12, s23 */
/* @0x2cf964 vstr s15, [sp, #76] */
/* @0x2cf968 vmla.f32 s11, s13, s22 */
/* @0x2cf96c vstr s14, [sp, #52] */
/* @0x2cf970 vstr s14, [sp, #68] */
/* @0x2cf974 vadd.f32 s15, s27, s28 */
/* @0x2cf978 vstr s11, [sp, #44] */
/* @0x2cf97c vadd.f32 s14, s9, s10 */
/* @0x2cf980 vadd.f32 s13, s12, s13 */
/* @0x2cf984 vstr s14, [sp, #64] */
/* @0x2cf988 vstr s14, [sp, #72] */
/* @0x2cf98c vmov.f32 s11, #1.000000e+00 */
/* @0x2cf990 vstr s13, [sp, #48] */
/* @0x2cf994 vstr s13, [sp, #56] */
/* @0x2cf998 vcmp.f32 s15, #0 */
/* @0x2cf99c vmrs APSR_nzcv, fpscr */
/* @0x2cf9a0 vmoveq.f32 s15, s11 */
/* @0x2cf9a4 vstr s15, [sp, #60] */
/* @0x2cf9a8 bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3> */
/* @0x2cf9ac ldr r5, [r4, #0x90] */
/* @0x2cf9b0 vldr s14, [sp, #20] */
/* @0x2cf9b4 ldr r6, [r4, #0x94] */
/* @0x2cf9b8 vldr s13, [sp, #24] */
/* @0x2cf9bc ldr r3, [r7, #0x18] */
/* @0x2cf9c0 vldr s15, [sp, #28] */
/* @0x2cf9c4 add r5, r5, r5, lsl #1 */
/* @0x2cf9c8 add r6, r6, r6, lsl #1 */
/* @0x2cf9cc add r5, r3, r5, lsl #2 */
/* @0x2cf9d0 add r6, r3, r6, lsl #2 */
/* @0x2cf9d4 b 0x2cfa34 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x320> */
/* @0x2cf9d8 vmul.f32 s13, s27, s21 */
/* @0x2cf9dc vadd.f32 s12, s29, s30 */
/* @0x2cf9e0 vmla.f32 s12, s13, s21 */
/* @0x2cf9e4 vmul.f32 s15, s28, s22 */
/* @0x2cf9e8 vadd.f32 s13, s13, s15 */
/* @0x2cf9ec vmla.f32 s12, s15, s22 */
/* @0x2cf9f0 vadd.f32 s10, s27, s28 */
/* @0x2cf9f4 vmov.f32 s15, #1.000000e+00 */
/* @0x2cf9f8 vmul.f32 s11, s13, s13 */
/* @0x2cf9fc vcmp.f32 s10, #0 */
/* @0x2cfa00 vmrs APSR_nzcv, fpscr */
/* @0x2cfa04 vmoveq.f32 s10, s15 */
/* @0x2cfa08 vnmls.f32 s11, s10, s12 */
/* @0x2cfa0c vcmp.f32 s11, #0 */
/* @0x2cfa10 vmrs APSR_nzcv, fpscr */
/* @0x2cfa14 vdivne.f32 s11, s15, s11 */
/* @0x2cfa18 vldr s15, [pc, #368] */
/* @0x2cfa1c vmul.f32 s14, s13, s8 */
/* @0x2cfa20 vmul.f32 s13, s13, s9 */
/* @0x2cfa24 vnmls.f32 s14, s10, s9 */
/* @0x2cfa28 vnmls.f32 s13, s12, s8 */
/* @0x2cfa2c vmul.f32 s14, s14, s11 */
/* @0x2cfa30 vmul.f32 s13, s11, s13 */
/* @0x2cfa34 vldr s11, [pc, #344] */
/* @0x2cfa38 vmul.f32 s20, s15, s20 */
/* @0x2cfa3c vmov.f32 s12, s13 */
/* @0x2cfa40 vmla.f32 s20, s14, s18 */
/* @0x2cfa44 vmla.f32 s12, s14, s21 */
/* @0x2cfa48 vmla.f32 s13, s14, s22 */
/* @0x2cfa4c vmul.f32 s19, s15, s19 */
/* @0x2cfa50 vmla.f32 s12, s15, s23 */
/* @0x2cfa54 vmla.f32 s19, s14, s17 */
/* @0x2cfa58 vldr s14, [sp, #4] */
/* @0x2cfa5c vmla.f32 s13, s15, s24 */
/* @0x2cfa60 vldr s15, [sp] */
/* @0x2cfa64 vmls.f32 s15, s29, s20 */
/* @0x2cfa68 vmls.f32 s25, s27, s12 */
/* @0x2cfa6c vstr s15, [r5, #4] */
/* @0x2cfa70 vldr s15, [sp, #8] */
/* @0x2cfa74 vmls.f32 s14, s29, s19 */
/* @0x2cfa78 vstr s25, [r5, #8] */
/* @0x2cfa7c vmla.f32 s31, s30, s19 */
/* @0x2cfa80 vstr s14, [r5] */
/* @0x2cfa84 vmla.f32 s15, s30, s20 */
/* @0x2cfa88 vstr s31, [r6] */
/* @0x2cfa8c vmla.f32 s26, s28, s13 */
/* @0x2cfa90 vstr s15, [r6, #4] */
/* @0x2cfa94 vcmpe.f32 s16, s11 */
/* @0x2cfa98 vstr s26, [r6, #8] */
/* @0x2cfa9c vmrs APSR_nzcv, fpscr */
/* @0x2cfaa0 movhi r0, #0 */
/* @0x2cfaa4 bhi 0x2cfac0 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3ac> */
/* @0x2cfaa8 vldr s15, [pc, #232] */
/* @0x2cfaac vldr s11, [sp, #12] */
/* @0x2cfab0 vcmpe.f32 s11, s15 */
/* @0x2cfab4 vmrs APSR_nzcv, fpscr */
/* @0x2cfab8 movhi r0, #0 */
/* @0x2cfabc movls r0, #1 */
/* @0x2cfac0 add sp, sp, #84 */
/* @0x2cfac4 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x2cfac8 pop {r4, r5, r6, r7, pc} */
/* @0x2cfacc vcmpe.f32 s15, s12 */
/* @0x2cfad0 vmrs APSR_nzcv, fpscr */
/* @0x2cfad4 blt 0x2cfb1c <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x408> */
/* @0x2cfad8 vsub.f32 s13, s12, s15 */
/* @0x2cfadc vldr s14, [pc, #176] */
/* @0x2cfae0 vadd.f32 s14, s13, s14 */
/* @0x2cfae4 vcmpe.f32 s14, #0 */
/* @0x2cfae8 vmrs APSR_nzcv, fpscr */
/* @0x2cfaec bmi 0x2cfb6c <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x458> */
/* @0x2cfaf0 vldr s14, [pc, #164] */
/* @0x2cfaf4 vsub.f32 s12, s15, s12 */
/* @0x2cfaf8 vcmpe.f32 s12, s16 */
/* @0x2cfafc vmrs APSR_nzcv, fpscr */
/* @0x2cfb00 vmovpl.f32 s16, s12 */
/* @0x2cfb04 b 0x2cf920 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x20c> */
/* @0x2cfb08 vldr s15, [pc, #124] */
/* @0x2cfb0c vcmpe.f32 s12, s15 */
/* @0x2cfb10 vmrs APSR_nzcv, fpscr */
/* @0x2cfb14 vnegpl.f32 s14, s12 */
/* @0x2cfb18 b 0x2cf908 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x1f4> */
/* @0x2cfb1c vcmpe.f32 s11, s12 */
/* @0x2cfb20 vmrs APSR_nzcv, fpscr */
/* @0x2cfb24 bhi 0x2cf9d8 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x2c4> */
/* @0x2cfb28 vsub.f32 s12, s12, s11 */
/* @0x2cfb2c vldr s14, [pc, #96] */
/* @0x2cfb30 vldr s15, [pc, #80] */
/* @0x2cfb34 vsub.f32 s14, s12, s14 */
/* @0x2cfb38 vcmpe.f32 s14, s15 */
/* @0x2cfb3c vmrs APSR_nzcv, fpscr */
/* @0x2cfb40 bpl 0x2cfb58 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x444> */
/* @0x2cfb44 vcmpe.f32 s14, #0 */
/* @0x2cfb48 vmrs APSR_nzcv, fpscr */
/* @0x2cfb4c vnegpl.f32 s14, s14 */
/* @0x2cfb50 vldrmi s14, [pc, #68] */
/* @0x2cfb54 b 0x2cfb5c <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x448> */
/* @0x2cfb58 vldr s14, [pc, #44] */
/* @0x2cfb5c vcmpe.f32 s12, s16 */
/* @0x2cfb60 vmrs APSR_nzcv, fpscr */
/* @0x2cfb64 vmovpl.f32 s16, s12 */
/* @0x2cfb68 b 0x2cf920 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x20c> */
/* @0x2cfb6c vldr s13, [pc, #24] */
/* @0x2cfb70 vcmpe.f32 s14, s13 */
/* @0x2cfb74 vmrs APSR_nzcv, fpscr */
/* @0x2cfb78 vnegpl.f32 s14, s14 */
/* @0x2cfb7c vldrmi s14, [pc, #4] */
/* @0x2cfb80 b 0x2cfaf4 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3e0> */
/* @0x2cfb84 stclo p7, c13, [r3], #-40 */
/* @0x2cfb88 cdplo p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2cfb8c cdplt p12, #0x4, c12, c12, c13, #0x6 */
/* @0x2cfb90 andeq r0, r0, r0 */
/* @0x2cfb94 bllo 0xfebc57c4 <b2_toiTime+0xfffffffffe46c320> */
/* @0x2cfb98 vstrlo s30, [lr, #-216] */
/* @0x2cfb9c andhi r0, r0, r0 */

/* ── FUNC 0x2cfba0 · b2PrismaticJoint::InitVelocityConstraints(b2SolverData const&) · size=980 · insn=245 */
/* @0x2cfba0 ldr r2, [r0, #0x30] */
/* @0x2cfba4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2cfba8 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cfbac mov r7, r1 */
/* @0x2cfbb0 vldr s21, [r2, #136] */
/* @0x2cfbb4 ldr r3, [r0, #0x34] */
/* @0x2cfbb8 add r1, r2, #44 */
/* @0x2cfbbc ldr r6, [r2, #0x8] */
/* @0x2cfbc0 mov r4, r0 */
/* @0x2cfbc4 vldr s20, [r3, #136] */
/* @0x2cfbc8 ldr r9, [r7, #0x18] */
/* @0x2cfbcc ldr r12, [r3, #0x8] */
/* @0x2cfbd0 add lr, r0, #160 */
/* @0x2cfbd4 add r10, r0, #152 */
/* @0x2cfbd8 ldm r1, {r0, r1} */
/* @0x2cfbdc str r6, [r4, #0x90] */
/* @0x2cfbe0 add r6, r6, r6, lsl #1 */
/* @0x2cfbe4 add r8, r3, #44 */
/* @0x2cfbe8 vldr s19, [r2, #144] */
/* @0x2cfbec lsl r6, r6, #2 */
/* @0x2cfbf0 ldr r5, [r7, #0x1c] */
/* @0x2cfbf4 str r12, [r4, #0x94] */
/* @0x2cfbf8 add r12, r12, r12, lsl #1 */
/* @0x2cfbfc stm r10, {r0, r1} */
/* @0x2cfc00 vldr s18, [r3, #144] */
/* @0x2cfc04 ldm r8, {r0, r1} */
/* @0x2cfc08 add r8, r9, r6 */
/* @0x2cfc0c lsl r12, r12, #2 */
/* @0x2cfc10 add r6, r5, r6 */
/* @0x2cfc14 ldr r11, [r8, #0x8] */
/* @0x2cfc18 add r9, r9, r12 */
/* @0x2cfc1c stm lr, {r0, r1} */
/* @0x2cfc20 vstr s21, [r4, #168] */
/* @0x2cfc24 vstr s20, [r4, #172] */
/* @0x2cfc28 vstr s19, [r4, #176] */
/* @0x2cfc2c mov r0, r11 */
/* @0x2cfc30 vstr s18, [r4, #180] */
/* @0x2cfc34 add r5, r5, r12 */
/* @0x2cfc38 bl 0xb6580 <sinf@plt> */
/* @0x2cfc3c ldr r10, [r9, #0x8] */
/* @0x2cfc40 vadd.f32 s28, s21, s20 */
/* @0x2cfc44 vmov s16, r0 */
/* @0x2cfc48 mov r0, r11 */
/* @0x2cfc4c bl 0xb658c <cosf@plt> */
/* @0x2cfc50 vmov s17, r0 */
/* @0x2cfc54 mov r0, r10 */
/* @0x2cfc58 bl 0xb6580 <sinf@plt> */
/* @0x2cfc5c vmov s22, r0 */
/* @0x2cfc60 mov r0, r10 */
/* @0x2cfc64 bl 0xb658c <cosf@plt> */
/* @0x2cfc68 vldr s15, [r4, #164] */
/* @0x2cfc6c vldr s7, [r4, #80] */
/* @0x2cfc70 vsub.f32 s7, s7, s15 */
/* @0x2cfc74 vldr s27, [r4, #72] */
/* @0x2cfc78 vldr s15, [r4, #156] */
/* @0x2cfc7c vldr s8, [r4, #76] */
/* @0x2cfc80 vldr s10, [r4, #160] */
/* @0x2cfc84 vldr s26, [r4, #68] */
/* @0x2cfc88 vldr s11, [r4, #152] */
/* @0x2cfc8c vldr s4, [r9, #4] */
/* @0x2cfc90 vldr s5, [r8, #4] */
/* @0x2cfc94 vldr s13, [r4, #88] */
/* @0x2cfc98 vldr s6, [r8] */
/* @0x2cfc9c vldr s25, [r9] */
/* @0x2cfca0 vldr s14, [r4, #84] */
/* @0x2cfca4 vldr s24, [r6] */
/* @0x2cfca8 vldr s23, [r6, #4] */
/* @0x2cfcac vldr s0, [r6, #8] */
/* @0x2cfcb0 vldr s1, [r5] */
/* @0x2cfcb4 vldr s2, [r5, #4] */
/* @0x2cfcb8 vldr s3, [r5, #8] */
/* @0x2cfcbc vsub.f32 s15, s27, s15 */
/* @0x2cfcc0 vsub.f32 s10, s8, s10 */
/* @0x2cfcc4 vmul.f32 s8, s15, s17 */
/* @0x2cfcc8 vmov s12, r0 */
/* @0x2cfccc vmul.f32 s9, s7, s12 */
/* @0x2cfcd0 vsub.f32 s11, s26, s11 */
/* @0x2cfcd4 vmla.f32 s9, s10, s22 */
/* @0x2cfcd8 vmul.f32 s7, s7, s22 */
/* @0x2cfcdc vmla.f32 s8, s11, s16 */
/* @0x2cfce0 vmul.f32 s15, s15, s16 */
/* @0x2cfce4 vsub.f32 s22, s4, s5 */
/* @0x2cfce8 vnmls.f32 s7, s10, s12 */
/* @0x2cfcec vmul.f32 s12, s13, s16 */
/* @0x2cfcf0 vadd.f32 s22, s9, s22 */
/* @0x2cfcf4 vnmls.f32 s15, s11, s17 */
/* @0x2cfcf8 vsub.f32 s25, s25, s6 */
/* @0x2cfcfc vnmls.f32 s12, s14, s17 */
/* @0x2cfd00 vmul.f32 s13, s13, s17 */
/* @0x2cfd04 vstr s12, [r4, #184] */
/* @0x2cfd08 vldr s4, [r4, #92] */
/* @0x2cfd0c ldrb r3, [r4, #0x88] */
/* @0x2cfd10 vsub.f32 s22, s22, s8 */
/* @0x2cfd14 vadd.f32 s25, s7, s25 */
/* @0x2cfd18 vadd.f32 s8, s8, s22 */
/* @0x2cfd1c vmla.f32 s13, s14, s16 */
/* @0x2cfd20 vsub.f32 s25, s25, s15 */
/* @0x2cfd24 vstr s13, [r4, #188] */
/* @0x2cfd28 vmul.f32 s14, s12, s8 */
/* @0x2cfd2c vadd.f32 s5, s15, s25 */
/* @0x2cfd30 vnmls.f32 s14, s13, s5 */
/* @0x2cfd34 vmul.f32 s15, s9, s12 */
/* @0x2cfd38 vstr s14, [r4, #208] */
/* @0x2cfd3c vnmls.f32 s15, s7, s13 */
/* @0x2cfd40 vmul.f32 s27, s19, s14 */
/* @0x2cfd44 vstr s15, [r4, #212] */
/* @0x2cfd48 vmov.f32 s6, s28 */
/* @0x2cfd4c vmla.f32 s6, s27, s14 */
/* @0x2cfd50 vmul.f32 s26, s18, s15 */
/* @0x2cfd54 vmla.f32 s6, s26, s15 */
/* @0x2cfd58 vcmpe.f32 s6, #0 */
/* @0x2cfd5c vstr s6, [r4, #248] */
/* @0x2cfd60 vmrs APSR_nzcv, fpscr */
/* @0x2cfd64 vmovgt.f32 s11, #1.000000e+00 */
/* @0x2cfd68 vstrle s6, [r4, #252] */
/* @0x2cfd6c vdivgt.f32 s11, s11, s6 */
/* @0x2cfd70 vstrgt s11, [r4, #252] */
/* @0x2cfd74 vldr s11, [r4, #96] */
/* @0x2cfd78 vmul.f32 s10, s11, s16 */
/* @0x2cfd7c vmul.f32 s11, s11, s17 */
/* @0x2cfd80 vnmls.f32 s10, s4, s17 */
/* @0x2cfd84 vmla.f32 s11, s4, s16 */
/* @0x2cfd88 vstr s10, [r4, #192] */
/* @0x2cfd8c vmul.f32 s8, s8, s10 */
/* @0x2cfd90 vstr s11, [r4, #196] */
/* @0x2cfd94 vnmls.f32 s8, s5, s11 */
/* @0x2cfd98 vmul.f32 s9, s9, s10 */
/* @0x2cfd9c vstr s8, [r4, #200] */
/* @0x2cfda0 vnmls.f32 s9, s7, s11 */
/* @0x2cfda4 vmul.f32 s4, s19, s8 */
/* @0x2cfda8 vstr s9, [r4, #204] */
/* @0x2cfdac vmov.f32 s7, s28 */
/* @0x2cfdb0 vmla.f32 s7, s4, s8 */
/* @0x2cfdb4 vmul.f32 s5, s18, s9 */
/* @0x2cfdb8 vmul.f32 s6, s5, s15 */
/* @0x2cfdbc vmla.f32 s7, s5, s9 */
/* @0x2cfdc0 vmla.f32 s6, s4, s14 */
/* @0x2cfdc4 vstr s7, [r4, #216] */
/* @0x2cfdc8 vadd.f32 s7, s19, s18 */
/* @0x2cfdcc vstr s6, [r4, #224] */
/* @0x2cfdd0 vstr s6, [r4, #240] */
/* @0x2cfdd4 vmov.f32 s16, #1.000000e+00 */
/* @0x2cfdd8 vadd.f32 s6, s27, s26 */
/* @0x2cfddc vadd.f32 s5, s4, s5 */
/* @0x2cfde0 vstr s6, [r4, #236] */
/* @0x2cfde4 vstr s6, [r4, #244] */
/* @0x2cfde8 vcmp.f32 s7, #0 */
/* @0x2cfdec vstr s5, [r4, #220] */
/* @0x2cfdf0 vstr s5, [r4, #228] */
/* @0x2cfdf4 vmrs APSR_nzcv, fpscr */
/* @0x2cfdf8 vmoveq.f32 s7, s16 */
/* @0x2cfdfc cmp r3, #0 */
/* @0x2cfe00 vstr s7, [r4, #232] */
/* @0x2cfe04 beq 0x2cfe88 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2e8> */
/* @0x2cfe08 vldr s5, [r4, #124] */
/* @0x2cfe0c vldr s6, [r4, #120] */
/* @0x2cfe10 vsub.f32 s7, s5, s6 */
/* @0x2cfe14 vldr s4, [pc, #340] */
/* @0x2cfe18 vcmpe.f32 s7, #0 */
/* @0x2cfe1c vmrs APSR_nzcv, fpscr */
/* @0x2cfe20 vnegle.f32 s7, s7 */
/* @0x2cfe24 vcmpe.f32 s7, s4 */
/* @0x2cfe28 vmrs APSR_nzcv, fpscr */
/* @0x2cfe2c movmi r3, #3 */
/* @0x2cfe30 strmi r3, [r4, #0x8c] */
/* @0x2cfe34 bpl 0x2cfe9c <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2fc> */
/* @0x2cfe38 ldrb r3, [r4, #0x89] */
/* @0x2cfe3c cmp r3, #0 */
/* @0x2cfe40 moveq r3, #0 */
/* @0x2cfe44 streq r3, [r4, #0x74] */
/* @0x2cfe48 ldrb r3, [r7, #0x14] */
/* @0x2cfe4c cmp r3, #0 */
/* @0x2cfe50 bne 0x2cfecc <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x32c> */
/* @0x2cfe54 mov r3, #0 */
/* @0x2cfe58 str r3, [r4, #0x68] */
/* @0x2cfe5c str r3, [r4, #0x6c] */
/* @0x2cfe60 str r3, [r4, #0x70] */
/* @0x2cfe64 str r3, [r4, #0x74] */
/* @0x2cfe68 vstr s24, [r6] */
/* @0x2cfe6c vstr s23, [r6, #4] */
/* @0x2cfe70 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2cfe74 vstr s0, [r6, #8] */
/* @0x2cfe78 vstr s1, [r5] */
/* @0x2cfe7c vstr s2, [r5, #4] */
/* @0x2cfe80 vstr s3, [r5, #8] */
/* @0x2cfe84 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cfe88 mov r3, #0 */
/* @0x2cfe8c mov r2, #0 */
/* @0x2cfe90 str r3, [r4, #0x8c] */
/* @0x2cfe94 str r2, [r4, #0x70] */
/* @0x2cfe98 b 0x2cfe38 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x298> */
/* @0x2cfe9c vmul.f32 s22, s22, s13 */
/* @0x2cfea0 vmla.f32 s22, s25, s12 */
/* @0x2cfea4 vcmpe.f32 s6, s22 */
/* @0x2cfea8 vmrs APSR_nzcv, fpscr */
/* @0x2cfeac blt 0x2cff48 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x3a8> */
/* @0x2cfeb0 ldr r3, [r4, #0x8c] */
/* @0x2cfeb4 cmp r3, #1 */
/* @0x2cfeb8 movne r3, #1 */
/* @0x2cfebc movne r2, #0 */
/* @0x2cfec0 strne r3, [r4, #0x8c] */
/* @0x2cfec4 strne r2, [r4, #0x70] */
/* @0x2cfec8 b 0x2cfe38 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x298> */
/* @0x2cfecc vldr s5, [r7, #8] */
/* @0x2cfed0 vldr s4, [r4, #112] */
/* @0x2cfed4 vldr s6, [r4, #116] */
/* @0x2cfed8 vmul.f32 s4, s5, s4 */
/* @0x2cfedc vldr s7, [r4, #104] */
/* @0x2cfee0 vldr s16, [r4, #108] */
/* @0x2cfee4 vmul.f32 s7, s5, s7 */
/* @0x2cfee8 vstr s4, [r4, #112] */
/* @0x2cfeec vmul.f32 s6, s5, s6 */
/* @0x2cfef0 vstr s7, [r4, #104] */
/* @0x2cfef4 vmul.f32 s5, s5, s16 */
/* @0x2cfef8 vstr s6, [r4, #116] */
/* @0x2cfefc vadd.f32 s6, s6, s4 */
/* @0x2cff00 vstr s5, [r4, #108] */
/* @0x2cff04 vmov.f32 s4, s5 */
/* @0x2cff08 vmla.f32 s4, s8, s7 */
/* @0x2cff0c vmla.f32 s5, s9, s7 */
/* @0x2cff10 vmul.f32 s12, s6, s12 */
/* @0x2cff14 vmul.f32 s13, s6, s13 */
/* @0x2cff18 vmov.f32 s8, s4 */
/* @0x2cff1c vmla.f32 s12, s10, s7 */
/* @0x2cff20 vmla.f32 s13, s11, s7 */
/* @0x2cff24 vmla.f32 s8, s6, s14 */
/* @0x2cff28 vmla.f32 s5, s6, s15 */
/* @0x2cff2c vmls.f32 s24, s21, s12 */
/* @0x2cff30 vmla.f32 s1, s20, s12 */
/* @0x2cff34 vmls.f32 s23, s21, s13 */
/* @0x2cff38 vmla.f32 s2, s20, s13 */
/* @0x2cff3c vmls.f32 s0, s19, s8 */
/* @0x2cff40 vmla.f32 s3, s18, s5 */
/* @0x2cff44 b 0x2cfe68 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2c8> */
/* @0x2cff48 vcmpe.f32 s5, s22 */
/* @0x2cff4c vmrs APSR_nzcv, fpscr */
/* @0x2cff50 bhi 0x2cfe88 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x2e8> */
/* @0x2cff54 ldr r3, [r4, #0x8c] */
/* @0x2cff58 cmp r3, #2 */
/* @0x2cff5c movne r3, #2 */
/* @0x2cff60 movne r2, #0 */
/* @0x2cff64 strne r3, [r4, #0x8c] */
/* @0x2cff68 strne r2, [r4, #0x70] */
/* @0x2cff6c b 0x2cfe38 <_ZN16b2PrismaticJoint23InitVelocityConstraintsERK12b2SolverData+0x298> */
/* @0x2cff70 stclo p7, c13, [r3], #-40 */

/* ── FUNC 0x2cff74 · b2PrismaticJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&) · size=180 · insn=45 */
/* @0x2cff74 vldr s15, [r1, #16] */
/* @0x2cff78 vldr s12, [r3, #4] */
/* @0x2cff7c vsub.f32 s12, s12, s15 */
/* @0x2cff80 vldr s13, [r1, #20] */
/* @0x2cff84 vldr s15, [r1, #24] */
/* @0x2cff88 vldr s10, [r1, #12] */
/* @0x2cff8c vldr s7, [r3] */
/* @0x2cff90 vldr s9, [r2, #20] */
/* @0x2cff94 vldr s8, [r2, #24] */
/* @0x2cff98 vldr s14, [r2, #16] */
/* @0x2cff9c vldr s4, [r2, #12] */
/* @0x2cffa0 vldr s5, [r2, #72] */
/* @0x2cffa4 vldr s6, [r1, #72] */
/* @0x2cffa8 ldr r12, [sp] */
/* @0x2cffac str r1, [r0, #0x8] */
/* @0x2cffb0 str r2, [r0, #0xc] */
/* @0x2cffb4 vmul.f32 s11, s12, s13 */
/* @0x2cffb8 vmul.f32 s12, s12, s15 */
/* @0x2cffbc vsub.f32 s7, s7, s10 */
/* @0x2cffc0 vneg.f32 s10, s13 */
/* @0x2cffc4 vmla.f32 s11, s7, s15 */
/* @0x2cffc8 vmla.f32 s12, s7, s10 */
/* @0x2cffcc vstr s11, [r0, #20] */
/* @0x2cffd0 vstr s12, [r0, #24] */
/* @0x2cffd4 vldr s12, [r3, #4] */
/* @0x2cffd8 vsub.f32 s14, s12, s14 */
/* @0x2cffdc vldr s11, [r3] */
/* @0x2cffe0 vmul.f32 s12, s14, s9 */
/* @0x2cffe4 vmul.f32 s14, s14, s8 */
/* @0x2cffe8 vsub.f32 s11, s11, s4 */
/* @0x2cffec vmla.f32 s12, s11, s8 */
/* @0x2cfff0 vmls.f32 s14, s9, s11 */
/* @0x2cfff4 vstr s12, [r0, #28] */
/* @0x2cfff8 vstr s14, [r0, #32] */
/* @0x2cfffc vldr s14, [r12, #4] */
/* @0x2d0000 vmul.f32 s13, s13, s14 */
/* @0x2d0004 vldr s12, [r12] */
/* @0x2d0008 vmul.f32 s14, s15, s14 */
/* @0x2d000c vmla.f32 s13, s15, s12 */
/* @0x2d0010 vmla.f32 s14, s10, s12 */
/* @0x2d0014 vstr s13, [r0, #36] */
/* @0x2d0018 vsub.f32 s15, s5, s6 */
/* @0x2d001c vstr s14, [r0, #40] */
/* @0x2d0020 vstr s15, [r0, #44] */
/* @0x2d0024 bx lr */

/* ── FUNC 0x2d0028 · b2PrismaticJoint::b2PrismaticJoint(b2PrismaticJointDef const*) · size=324 · insn=81 */
/* @0x2d0028 push {r4, r5, r6, lr} */
/* @0x2d002c mov r4, r0 */
/* @0x2d0030 mov r5, r1 */
/* @0x2d0034 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef> */
/* @0x2d0038 add r3, r5, #20 */
/* @0x2d003c ldr r2, [pc, #0x124] */
/* @0x2d0040 add r6, r5, #28 */
/* @0x2d0044 add r12, r4, #76 */
/* @0x2d0048 ldm r3, {r0, r1} */
/* @0x2d004c ldr r2, [pc, r2] */
/* @0x2d0050 mov r3, r4 */
/* @0x2d0054 add r2, r2, #8 */
/* @0x2d0058 str r2, [r3], #68 */
/* @0x2d005c add r2, r5, #36 */
/* @0x2d0060 stm r3, {r0, r1} */
/* @0x2d0064 add r3, r4, #84 */
/* @0x2d0068 ldm r6, {r0, r1} */
/* @0x2d006c stm r12, {r0, r1} */
/* @0x2d0070 ldm r2, {r0, r1} */
/* @0x2d0074 stm r3, {r0, r1} */
/* @0x2d0078 vldr s14, [r4, #88] */
/* @0x2d007c vmul.f32 s14, s14, s14 */
/* @0x2d0080 vldr s15, [r4, #84] */
/* @0x2d0084 vmla.f32 s14, s15, s15 */
/* @0x2d0088 vsqrt.f32 s15, s14 */
/* @0x2d008c vcmp.f32 s15, s15 */
/* @0x2d0090 vmrs APSR_nzcv, fpscr */
/* @0x2d0094 bne 0x2d0154 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0x12c> */
/* @0x2d0098 vldr s14, [pc, #196] */
/* @0x2d009c vcmpe.f32 s15, s14 */
/* @0x2d00a0 vmrs APSR_nzcv, fpscr */
/* @0x2d00a4 bmi 0x2d0148 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0x120> */
/* @0x2d00a8 vmov.f32 s12, #1.000000e+00 */
/* @0x2d00ac vldr s13, [r4, #88] */
/* @0x2d00b0 vldr s14, [r4, #84] */
/* @0x2d00b4 vdiv.f32 s15, s12, s15 */
/* @0x2d00b8 vmul.f32 s13, s15, s13 */
/* @0x2d00bc vmul.f32 s14, s15, s14 */
/* @0x2d00c0 vstr s13, [r4, #88] */
/* @0x2d00c4 vmov.f32 s15, s13 */
/* @0x2d00c8 vstr s14, [r4, #84] */
/* @0x2d00cc ldr r0, [r5, #0x2c] */
/* @0x2d00d0 ldrb r1, [r5, #0x30] */
/* @0x2d00d4 ldrb r2, [r5, #0x3c] */
/* @0x2d00d8 vneg.f32 s15, s15 */
/* @0x2d00dc ldr r3, [r5, #0x34] */
/* @0x2d00e0 vstr s14, [r4, #96] */
/* @0x2d00e4 str r0, [r4, #0x64] */
/* @0x2d00e8 ldr r0, [r5, #0x38] */
/* @0x2d00ec str r3, [r4, #0x78] */
/* @0x2d00f0 vstr s15, [r4, #92] */
/* @0x2d00f4 ldr r3, [r5, #0x40] */
/* @0x2d00f8 str r0, [r4, #0x7c] */
/* @0x2d00fc ldr r0, [r5, #0x44] */
/* @0x2d0100 str r3, [r4, #0x80] */
/* @0x2d0104 mov r3, #0 */
/* @0x2d0108 strb r1, [r4, #0x88] */
/* @0x2d010c str r0, [r4, #0x84] */
/* @0x2d0110 mov r0, r4 */
/* @0x2d0114 str r3, [r4, #0x68] */
/* @0x2d0118 str r3, [r4, #0x6c] */
/* @0x2d011c str r3, [r4, #0x70] */
/* @0x2d0120 str r3, [r4, #0xfc] */
/* @0x2d0124 str r3, [r4, #0x74] */
/* @0x2d0128 str r3, [r4, #0xb8] */
/* @0x2d012c str r3, [r4, #0xbc] */
/* @0x2d0130 str r3, [r4, #0xc0] */
/* @0x2d0134 str r3, [r4, #0xc4] */
/* @0x2d0138 mov r3, #0 */
/* @0x2d013c strb r2, [r4, #0x89] */
/* @0x2d0140 str r3, [r4, #0x8c] */
/* @0x2d0144 pop {r4, r5, r6, pc} */
/* @0x2d0148 vldr s15, [r4, #88] */
/* @0x2d014c vldr s14, [r4, #84] */
/* @0x2d0150 b 0x2d00cc <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0xa4> */
/* @0x2d0154 vmov r0, s14 */
/* @0x2d0158 bl 0xb6700 <sqrtf@plt> */
/* @0x2d015c vmov s15, r0 */
/* @0x2d0160 b 0x2d0098 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0x70> */
/* @0x2d0164 strlo r0, [r0], #-0 */
/* @0x2d0168 andseq r1, r2, r12, lsl r11 */

/* ── FUNC 0x2d0028 · b2PrismaticJoint::b2PrismaticJoint(b2PrismaticJointDef const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2d016c · b2PrismaticJoint::GetJointTranslation() const · size=160 · insn=40 */
/* @0x2d016c ldr r3, [r0, #0x30] */
/* @0x2d0170 vldr s11, [r0, #72] */
/* @0x2d0174 ldr r2, [r0, #0x34] */
/* @0x2d0178 vldr s15, [r3, #24] */
/* @0x2d017c vldr s10, [r0, #80] */
/* @0x2d0180 vmul.f32 s8, s15, s11 */
/* @0x2d0184 vldr s5, [r2, #24] */
/* @0x2d0188 vldr s14, [r3, #20] */
/* @0x2d018c vldr s4, [r0, #68] */
/* @0x2d0190 vldr s6, [r0, #76] */
/* @0x2d0194 vldr s3, [r2, #20] */
/* @0x2d0198 vldr s13, [r0, #88] */
/* @0x2d019c vldr s7, [r0, #84] */
/* @0x2d01a0 vpush {d8} */
/* @0x2d01a4 vldr s0, [r2, #16] */
/* @0x2d01a8 vldr s16, [r3, #16] */
/* @0x2d01ac vldr s1, [r2, #12] */
/* @0x2d01b0 vldr s2, [r3, #12] */
/* @0x2d01b4 vmul.f32 s9, s5, s10 */
/* @0x2d01b8 vmul.f32 s11, s14, s11 */
/* @0x2d01bc vmla.f32 s8, s4, s14 */
/* @0x2d01c0 vmul.f32 s10, s3, s10 */
/* @0x2d01c4 vmla.f32 s9, s6, s3 */
/* @0x2d01c8 vmul.f32 s12, s15, s13 */
/* @0x2d01cc vnmls.f32 s11, s15, s4 */
/* @0x2d01d0 vnmls.f32 s10, s5, s6 */
/* @0x2d01d4 vmul.f32 s13, s14, s13 */
/* @0x2d01d8 vmla.f32 s12, s14, s7 */
/* @0x2d01dc vadd.f32 s8, s8, s16 */
/* @0x2d01e0 vpop {d8} */
/* @0x2d01e4 vadd.f32 s9, s9, s0 */
/* @0x2d01e8 vsub.f32 s9, s9, s8 */
/* @0x2d01ec vnmls.f32 s13, s15, s7 */
/* @0x2d01f0 vadd.f32 s10, s10, s1 */
/* @0x2d01f4 vadd.f32 s11, s11, s2 */
/* @0x2d01f8 vmul.f32 s12, s9, s12 */
/* @0x2d01fc vsub.f32 s11, s10, s11 */
/* @0x2d0200 vmla.f32 s12, s11, s13 */
/* @0x2d0204 vmov r0, s12 */
/* @0x2d0208 bx lr */

/* ── FUNC 0x2d020c · b2PrismaticJoint::GetJointSpeed() const · size=264 · insn=66 */
/* @0x2d020c ldr r2, [r0, #0x34] */
/* @0x2d0210 vldr s10, [r0, #80] */
/* @0x2d0214 vldr s15, [r2, #48] */
/* @0x2d0218 vsub.f32 s10, s10, s15 */
/* @0x2d021c vldr s15, [r2, #20] */
/* @0x2d0220 vpush {d8, d9, d10, d11} */
/* @0x2d0224 vldr s1, [r2, #44] */
/* @0x2d0228 vldr s23, [r0, #76] */
/* @0x2d022c vldr s0, [r2, #24] */
/* @0x2d0230 ldr r3, [r0, #0x30] */
/* @0x2d0234 vldr s11, [r0, #72] */
/* @0x2d0238 vldr s13, [r3, #48] */
/* @0x2d023c vldr s9, [r3, #20] */
/* @0x2d0240 vldr s8, [r3, #24] */
/* @0x2d0244 vldr s22, [r0, #68] */
/* @0x2d0248 vldr s3, [r2, #88] */
/* @0x2d024c vldr s5, [r2, #84] */
/* @0x2d0250 vldr s2, [r3, #44] */
/* @0x2d0254 vldr s14, [r0, #88] */
/* @0x2d0258 vldr s6, [r2, #80] */
/* @0x2d025c vldr s4, [r0, #84] */
/* @0x2d0260 vldr s21, [r3, #84] */
/* @0x2d0264 vmul.f32 s12, s10, s15 */
/* @0x2d0268 vldr s7, [r3, #88] */
/* @0x2d026c vldr s20, [r2, #64] */
/* @0x2d0270 vldr s19, [r3, #64] */
/* @0x2d0274 vldr s18, [r3, #80] */
/* @0x2d0278 vldr s17, [r2, #60] */
/* @0x2d027c vldr s16, [r3, #60] */
/* @0x2d0280 vsub.f32 s1, s23, s1 */
/* @0x2d0284 vmul.f32 s10, s10, s0 */
/* @0x2d0288 vnmls.f32 s12, s1, s0 */
/* @0x2d028c vsub.f32 s11, s11, s13 */
/* @0x2d0290 vmla.f32 s10, s1, s15 */
/* @0x2d0294 vmul.f32 s13, s11, s9 */
/* @0x2d0298 vmul.f32 s11, s11, s8 */
/* @0x2d029c vmla.f32 s5, s3, s12 */
/* @0x2d02a0 vsub.f32 s2, s22, s2 */
/* @0x2d02a4 vmul.f32 s15, s9, s14 */
/* @0x2d02a8 vnmls.f32 s13, s2, s8 */
/* @0x2d02ac vmla.f32 s11, s2, s9 */
/* @0x2d02b0 vmls.f32 s6, s3, s10 */
/* @0x2d02b4 vnmls.f32 s15, s8, s4 */
/* @0x2d02b8 vmul.f32 s14, s8, s14 */
/* @0x2d02bc vsub.f32 s8, s5, s21 */
/* @0x2d02c0 vmla.f32 s14, s9, s4 */
/* @0x2d02c4 vmls.f32 s8, s7, s13 */
/* @0x2d02c8 vadd.f32 s5, s11, s19 */
/* @0x2d02cc vadd.f32 s10, s10, s20 */
/* @0x2d02d0 vsub.f32 s9, s6, s18 */
/* @0x2d02d4 vneg.f32 s6, s7 */
/* @0x2d02d8 vmul.f32 s7, s7, s15 */
/* @0x2d02dc vsub.f32 s10, s10, s5 */
/* @0x2d02e0 vmls.f32 s9, s11, s6 */
/* @0x2d02e4 vadd.f32 s12, s12, s17 */
/* @0x2d02e8 vadd.f32 s13, s13, s16 */
/* @0x2d02ec vpop {d8, d9, d10, d11} */
/* @0x2d02f0 vmul.f32 s11, s14, s8 */
/* @0x2d02f4 vmul.f32 s10, s10, s7 */
/* @0x2d02f8 vmul.f32 s14, s14, s6 */
/* @0x2d02fc vsub.f32 s13, s12, s13 */
/* @0x2d0300 vmla.f32 s11, s15, s9 */
/* @0x2d0304 vmla.f32 s10, s13, s14 */
/* @0x2d0308 vadd.f32 s11, s10, s11 */
/* @0x2d030c vmov r0, s11 */
/* @0x2d0310 bx lr */

/* ── FUNC 0x2d0314 · b2PrismaticJoint::IsLimitEnabled() const · size=8 · insn=2 */
/* @0x2d0314 ldrb r0, [r0, #0x88] */
/* @0x2d0318 bx lr */

/* ── FUNC 0x2d031c · b2PrismaticJoint::EnableLimit(bool) · size=84 · insn=21 */
/* @0x2d031c ldrb r3, [r0, #0x88] */
/* @0x2d0320 cmp r3, r1 */
/* @0x2d0324 bxeq lr */
/* @0x2d0328 ldr r3, [r0, #0x30] */
/* @0x2d032c ldrh r2, [r3, #4] */
/* @0x2d0330 tst r2, #2 */
/* @0x2d0334 orreq r2, r2, #2 */
/* @0x2d0338 strheq r2, [r3, #4] */
/* @0x2d033c moveq r12, #0 */
/* @0x2d0340 streq r12, [r3, #0xa0] */
/* @0x2d0344 ldr r3, [r0, #0x34] */
/* @0x2d0348 ldrh r2, [r3, #4] */
/* @0x2d034c tst r2, #2 */
/* @0x2d0350 orreq r2, r2, #2 */
/* @0x2d0354 strheq r2, [r3, #4] */
/* @0x2d0358 moveq r12, #0 */
/* @0x2d035c streq r12, [r3, #0xa0] */
/* @0x2d0360 mov r3, #0 */
/* @0x2d0364 strb r1, [r0, #0x88] */
/* @0x2d0368 str r3, [r0, #0x70] */
/* @0x2d036c bx lr */

/* ── FUNC 0x2d0370 · b2PrismaticJoint::GetLowerLimit() const · size=8 · insn=2 */
/* @0x2d0370 ldr r0, [r0, #0x78] */
/* @0x2d0374 bx lr */

/* ── FUNC 0x2d0378 · b2PrismaticJoint::GetUpperLimit() const · size=8 · insn=2 */
/* @0x2d0378 ldr r0, [r0, #0x7c] */
/* @0x2d037c bx lr */

/* ── FUNC 0x2d0380 · b2PrismaticJoint::SetLimits(float, float) · size=180 · insn=45 */
/* @0x2d0380 push {r4, lr} */
/* @0x2d0384 vpush {d8} */
/* @0x2d0388 vmov s16, r1 */
/* @0x2d038c vmov s17, r2 */
/* @0x2d0390 ldr r3, [pc, #0x94] */
/* @0x2d0394 ldr r1, [pc, #0x94] */
/* @0x2d0398 mov r4, r0 */
/* @0x2d039c vcmpe.f32 s16, s17 */
/* @0x2d03a0 ldr r3, [pc, r3] */
/* @0x2d03a4 add r1, pc, r1 */
/* @0x2d03a8 ldr r3, [r3] */
/* @0x2d03ac vmrs APSR_nzcv, fpscr */
/* @0x2d03b0 movhi r0, #0 */
/* @0x2d03b4 movls r0, #1 */
/* @0x2d03b8 blx r3 */
/* @0x2d03bc vldr s15, [r4, #120] */
/* @0x2d03c0 vcmp.f32 s15, s16 */
/* @0x2d03c4 vmrs APSR_nzcv, fpscr */
/* @0x2d03c8 bne 0x2d03dc <_ZN16b2PrismaticJoint9SetLimitsEff+0x5c> */
/* @0x2d03cc vldr s15, [r4, #124] */
/* @0x2d03d0 vcmp.f32 s15, s17 */
/* @0x2d03d4 vmrs APSR_nzcv, fpscr */
/* @0x2d03d8 beq 0x2d0424 <_ZN16b2PrismaticJoint9SetLimitsEff+0xa4> */
/* @0x2d03dc ldr r3, [r4, #0x30] */
/* @0x2d03e0 ldrh r2, [r3, #4] */
/* @0x2d03e4 tst r2, #2 */
/* @0x2d03e8 orreq r2, r2, #2 */
/* @0x2d03ec strheq r2, [r3, #4] */
/* @0x2d03f0 moveq r1, #0 */
/* @0x2d03f4 streq r1, [r3, #0xa0] */
/* @0x2d03f8 ldr r3, [r4, #0x34] */
/* @0x2d03fc ldrh r2, [r3, #4] */
/* @0x2d0400 tst r2, #2 */
/* @0x2d0404 orreq r2, r2, #2 */
/* @0x2d0408 strheq r2, [r3, #4] */
/* @0x2d040c moveq r1, #0 */
/* @0x2d0410 streq r1, [r3, #0xa0] */
/* @0x2d0414 mov r3, #0 */
/* @0x2d0418 vstr s16, [r4, #120] */
/* @0x2d041c vstr s17, [r4, #124] */
/* @0x2d0420 str r3, [r4, #0x70] */
/* @0x2d0424 vpop {d8} */
/* @0x2d0428 pop {r4, pc} */
/* @0x2d042c andseq r1, r2, r8, lsr #2 */
/* @0x2d0430 andeq sp, r8, r0, lsl #9 */

/* ── FUNC 0x2d0434 · b2PrismaticJoint::IsMotorEnabled() const · size=8 · insn=2 */
/* @0x2d0434 ldrb r0, [r0, #0x89] */
/* @0x2d0438 bx lr */

/* ── FUNC 0x2d043c · b2PrismaticJoint::EnableMotor(bool) · size=64 · insn=16 */
/* @0x2d043c ldr r3, [r0, #0x30] */
/* @0x2d0440 ldrh r2, [r3, #4] */
/* @0x2d0444 tst r2, #2 */
/* @0x2d0448 orreq r2, r2, #2 */
/* @0x2d044c strheq r2, [r3, #4] */
/* @0x2d0450 moveq r12, #0 */
/* @0x2d0454 streq r12, [r3, #0xa0] */
/* @0x2d0458 ldr r3, [r0, #0x34] */
/* @0x2d045c ldrh r2, [r3, #4] */
/* @0x2d0460 tst r2, #2 */
/* @0x2d0464 orreq r2, r2, #2 */
/* @0x2d0468 strheq r2, [r3, #4] */
/* @0x2d046c moveq r12, #0 */
/* @0x2d0470 streq r12, [r3, #0xa0] */
/* @0x2d0474 strb r1, [r0, #0x89] */
/* @0x2d0478 bx lr */

/* ── FUNC 0x2d047c · b2PrismaticJoint::SetMotorSpeed(float) · size=64 · insn=16 */
/* @0x2d047c ldr r3, [r0, #0x30] */
/* @0x2d0480 ldrh r2, [r3, #4] */
/* @0x2d0484 tst r2, #2 */
/* @0x2d0488 orreq r2, r2, #2 */
/* @0x2d048c strheq r2, [r3, #4] */
/* @0x2d0490 moveq r12, #0 */
/* @0x2d0494 streq r12, [r3, #0xa0] */
/* @0x2d0498 ldr r3, [r0, #0x34] */
/* @0x2d049c ldrh r2, [r3, #4] */
/* @0x2d04a0 tst r2, #2 */
/* @0x2d04a4 orreq r2, r2, #2 */
/* @0x2d04a8 strheq r2, [r3, #4] */
/* @0x2d04ac moveq r12, #0 */
/* @0x2d04b0 streq r12, [r3, #0xa0] */
/* @0x2d04b4 str r1, [r0, #0x84] */
/* @0x2d04b8 bx lr */

/* ── FUNC 0x2d04bc · b2PrismaticJoint::SetMaxMotorForce(float) · size=64 · insn=16 */
/* @0x2d04bc ldr r3, [r0, #0x30] */
/* @0x2d04c0 ldrh r2, [r3, #4] */
/* @0x2d04c4 tst r2, #2 */
/* @0x2d04c8 orreq r2, r2, #2 */
/* @0x2d04cc strheq r2, [r3, #4] */
/* @0x2d04d0 moveq r12, #0 */
/* @0x2d04d4 streq r12, [r3, #0xa0] */
/* @0x2d04d8 ldr r3, [r0, #0x34] */
/* @0x2d04dc ldrh r2, [r3, #4] */
/* @0x2d04e0 tst r2, #2 */
/* @0x2d04e4 orreq r2, r2, #2 */
/* @0x2d04e8 strheq r2, [r3, #4] */
/* @0x2d04ec moveq r12, #0 */
/* @0x2d04f0 streq r12, [r3, #0xa0] */
/* @0x2d04f4 str r1, [r0, #0x80] */
/* @0x2d04f8 bx lr */

/* ── FUNC 0x2d04fc · b2PrismaticJoint::GetMotorForce(float) const · size=20 · insn=5 */
/* @0x2d04fc vmov s14, r1 */
/* @0x2d0500 vldr s15, [r0, #116] */
/* @0x2d0504 vmul.f32 s14, s14, s15 */
/* @0x2d0508 vmov r0, s14 */
/* @0x2d050c bx lr */

/* ── FUNC 0x2d0510 · b2PulleyJoint::SolveVelocityConstraints(b2SolverData const&) · size=276 · insn=69 */
/* @0x2d0510 ldr r2, [r0, #0x78] */
/* @0x2d0514 vpush {d8, d9, d10, d11, d12} */
/* @0x2d0518 ldr r3, [r0, #0x7c] */
/* @0x2d051c vldr s16, [r0, #152] */
/* @0x2d0520 ldr r1, [r1, #0x1c] */
/* @0x2d0524 vldr s0, [r0, #144] */
/* @0x2d0528 add r2, r2, r2, lsl #1 */
/* @0x2d052c vldr s11, [r0, #148] */
/* @0x2d0530 add r3, r3, r3, lsl #1 */
/* @0x2d0534 vldr s13, [r0, #156] */
/* @0x2d0538 add r2, r1, r2, lsl #2 */
/* @0x2d053c vldr s5, [r2, #4] */
/* @0x2d0540 add r3, r1, r3, lsl #2 */
/* @0x2d0544 vmov.f32 s15, s5 */
/* @0x2d0548 vldr s9, [r3, #4] */
/* @0x2d054c vldr s12, [r2, #8] */
/* @0x2d0550 vldr s14, [r3, #8] */
/* @0x2d0554 vldr s2, [r2] */
/* @0x2d0558 vldr s7, [r3] */
/* @0x2d055c vldr s18, [r0, #140] */
/* @0x2d0560 vmov.f32 s10, s9 */
/* @0x2d0564 vldr s4, [r0, #132] */
/* @0x2d0568 vldr s1, [r0, #128] */
/* @0x2d056c vldr s6, [r0, #136] */
/* @0x2d0570 vldr s17, [r0, #112] */
/* @0x2d0574 vldr s22, [r0, #192] */
/* @0x2d0578 vldr s21, [r0, #184] */
/* @0x2d057c vldr s3, [r0, #176] */
/* @0x2d0580 vmla.f32 s10, s14, s16 */
/* @0x2d0584 vldr s8, [r0, #180] */
/* @0x2d0588 vldr s20, [r0, #188] */
/* @0x2d058c vldr s19, [r0, #116] */
/* @0x2d0590 vmla.f32 s15, s12, s0 */
/* @0x2d0594 vmov.f32 s24, s2 */
/* @0x2d0598 vmov.f32 s23, s7 */
/* @0x2d059c vmls.f32 s24, s12, s11 */
/* @0x2d05a0 vmls.f32 s23, s14, s13 */
/* @0x2d05a4 vmul.f32 s15, s15, s4 */
/* @0x2d05a8 vmul.f32 s10, s10, s18 */
/* @0x2d05ac vmla.f32 s15, s24, s1 */
/* @0x2d05b0 vmla.f32 s10, s23, s6 */
/* @0x2d05b4 vnmla.f32 s15, s17, s10 */
/* @0x2d05b8 vnmul.f32 s15, s22, s15 */
/* @0x2d05bc vnmul.f32 s10, s17, s15 */
/* @0x2d05c0 vneg.f32 s17, s15 */
/* @0x2d05c4 vmul.f32 s6, s10, s6 */
/* @0x2d05c8 vmul.f32 s1, s17, s1 */
/* @0x2d05cc vmul.f32 s10, s10, s18 */
/* @0x2d05d0 vmul.f32 s4, s17, s4 */
/* @0x2d05d4 vmul.f32 s13, s13, s6 */
/* @0x2d05d8 vmul.f32 s11, s11, s1 */
/* @0x2d05dc vnmls.f32 s13, s16, s10 */
/* @0x2d05e0 vnmls.f32 s11, s0, s4 */
/* @0x2d05e4 vmla.f32 s14, s13, s20 */
/* @0x2d05e8 vmla.f32 s12, s11, s21 */
/* @0x2d05ec vmla.f32 s2, s3, s1 */
/* @0x2d05f0 vmla.f32 s5, s3, s4 */
/* @0x2d05f4 vmla.f32 s7, s8, s6 */
/* @0x2d05f8 vmla.f32 s9, s8, s10 */
/* @0x2d05fc vadd.f32 s15, s19, s15 */
/* @0x2d0600 vpop {d8, d9, d10, d11, d12} */
/* @0x2d0604 vstr s15, [r0, #116] */
/* @0x2d0608 vstr s12, [r2, #8] */
/* @0x2d060c vstr s2, [r2] */
/* @0x2d0610 vstr s5, [r2, #4] */
/* @0x2d0614 vstr s14, [r3, #8] */
/* @0x2d0618 vstr s7, [r3] */
/* @0x2d061c vstr s9, [r3, #4] */
/* @0x2d0620 bx lr */

/* ── FUNC 0x2d0624 · b2PulleyJoint::GetAnchorA() const · size=64 · insn=16 */
/* @0x2d0624 ldr r3, [r1, #0x30] */
/* @0x2d0628 vldr s15, [r1, #96] */
/* @0x2d062c vldr s12, [r3, #24] */
/* @0x2d0630 vldr s11, [r3, #20] */
/* @0x2d0634 vmul.f32 s14, s12, s15 */
/* @0x2d0638 vldr s13, [r1, #92] */
/* @0x2d063c vldr s9, [r3, #16] */
/* @0x2d0640 vldr s10, [r3, #12] */
/* @0x2d0644 vmul.f32 s15, s11, s15 */
/* @0x2d0648 vmla.f32 s14, s13, s11 */
/* @0x2d064c vnmls.f32 s15, s12, s13 */
/* @0x2d0650 vadd.f32 s14, s14, s9 */
/* @0x2d0654 vadd.f32 s15, s15, s10 */
/* @0x2d0658 vstr s14, [r0, #4] */
/* @0x2d065c vstr s15, [r0] */
/* @0x2d0660 bx lr */

/* ── FUNC 0x2d0664 · b2PulleyJoint::GetAnchorB() const · size=64 · insn=16 */
/* @0x2d0664 ldr r3, [r1, #0x34] */
/* @0x2d0668 vldr s15, [r1, #104] */
/* @0x2d066c vldr s12, [r3, #24] */
/* @0x2d0670 vldr s11, [r3, #20] */
/* @0x2d0674 vmul.f32 s14, s12, s15 */
/* @0x2d0678 vldr s13, [r1, #100] */
/* @0x2d067c vldr s9, [r3, #16] */
/* @0x2d0680 vldr s10, [r3, #12] */
/* @0x2d0684 vmul.f32 s15, s11, s15 */
/* @0x2d0688 vmla.f32 s14, s13, s11 */
/* @0x2d068c vnmls.f32 s15, s12, s13 */
/* @0x2d0690 vadd.f32 s14, s14, s9 */
/* @0x2d0694 vadd.f32 s15, s15, s10 */
/* @0x2d0698 vstr s14, [r0, #4] */
/* @0x2d069c vstr s15, [r0] */
/* @0x2d06a0 bx lr */

/* ── FUNC 0x2d06a4 · b2PulleyJoint::GetReactionForce(float) const · size=44 · insn=11 */
/* @0x2d06a4 vldr s14, [r1, #116] */
/* @0x2d06a8 vldr s13, [r1, #140] */
/* @0x2d06ac vldr s12, [r1, #136] */
/* @0x2d06b0 vmul.f32 s13, s14, s13 */
/* @0x2d06b4 vmov s15, r2 */
/* @0x2d06b8 vmul.f32 s14, s14, s12 */
/* @0x2d06bc vmul.f32 s13, s15, s13 */
/* @0x2d06c0 vmul.f32 s15, s15, s14 */
/* @0x2d06c4 vstr s13, [r0, #4] */
/* @0x2d06c8 vstr s15, [r0] */
/* @0x2d06cc bx lr */

/* ── FUNC 0x2d06d0 · b2PulleyJoint::GetReactionTorque(float) const · size=8 · insn=2 */
/* @0x2d06d0 mov r0, #0 */
/* @0x2d06d4 bx lr */

/* ── FUNC 0x2d06d8 · b2PulleyJoint::ShiftOrigin(b2Vec2 const&) · size=68 · insn=17 */
/* @0x2d06d8 vldr s15, [r1] */
/* @0x2d06dc vldr s12, [r1, #4] */
/* @0x2d06e0 vldr s14, [r0, #68] */
/* @0x2d06e4 vldr s11, [r0, #72] */
/* @0x2d06e8 vsub.f32 s15, s14, s15 */
/* @0x2d06ec vldr s13, [r0, #80] */
/* @0x2d06f0 vldr s14, [r0, #76] */
/* @0x2d06f4 vsub.f32 s12, s11, s12 */
/* @0x2d06f8 vstr s15, [r0, #68] */
/* @0x2d06fc vldr s15, [r1] */
/* @0x2d0700 vstr s12, [r0, #72] */
/* @0x2d0704 vsub.f32 s14, s14, s15 */
/* @0x2d0708 vldr s15, [r1, #4] */
/* @0x2d070c vsub.f32 s15, s13, s15 */
/* @0x2d0710 vstr s14, [r0, #76] */
/* @0x2d0714 vstr s15, [r0, #80] */
/* @0x2d0718 bx lr */

/* ── FUNC 0x2d071c · b2PulleyJoint::~b2PulleyJoint() · size=24 · insn=6 */
/* @0x2d071c ldr r3, [pc, #0xc] */
/* @0x2d0720 ldr r3, [pc, r3] */
/* @0x2d0724 add r3, r3, #8 */
/* @0x2d0728 str r3, [r0] */
/* @0x2d072c bx lr */
/* @0x2d0730 andseq r1, r2, r4, lsr r4 */
