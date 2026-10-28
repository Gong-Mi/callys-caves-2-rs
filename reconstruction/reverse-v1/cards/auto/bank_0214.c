/* libyoyo.so 覆盖卡组 0214
 * 函数 0x23a194..0x23be54，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x23a194 · CPhysicsWorld::SetParticleCategoryFlags(int, unsigned int) · size=124 · insn=31 */
/* @0x23a194 push {r4, r5, r6, r7, r8, lr} */
/* @0x23a198 mov r7, r0 */
/* @0x23a19c ldr r0, [r0, #0x10] */
/* @0x23a1a0 movw r3, #0x9298 */
/* @0x23a1a4 movt r3, #0x1 */
/* @0x23a1a8 mov r5, r1 */
/* @0x23a1ac mov r4, r2 */
/* @0x23a1b0 ldr r8, [r0, r3] */
/* @0x23a1b4 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv> */
/* @0x23a1b8 mov r6, r0 */
/* @0x23a1bc ldr r0, [r7, #0x10] */
/* @0x23a1c0 bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv> */
/* @0x23a1c4 cmp r8, #0 */
/* @0x23a1c8 pople {r4, r5, r6, r7, r8, pc} */
/* @0x23a1cc cmp r5, #0 */
/* @0x23a1d0 beq 0x23a1f8 <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij+0x64> */
/* @0x23a1d4 lsl r1, r8, #2 */
/* @0x23a1d8 mov r3, #0 */
/* @0x23a1dc ldr r12, [r0, r3] */
/* @0x23a1e0 cmp r12, r5 */
/* @0x23a1e4 streq r4, [r6, r3] */
/* @0x23a1e8 add r3, r3, #4 */
/* @0x23a1ec cmp r3, r1 */
/* @0x23a1f0 bne 0x23a1dc <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij+0x48> */
/* @0x23a1f4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x23a1f8 add r3, r6, r8, lsl #2 */
/* @0x23a1fc mov r0, r6 */
/* @0x23a200 str r4, [r0], #4 */
/* @0x23a204 cmp r0, r3 */
/* @0x23a208 bne 0x23a200 <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij+0x6c> */
/* @0x23a20c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x23a210 · CPhysicsWorld::SetParticleGroupFlags(int, unsigned int) · size=32 · insn=8 */
/* @0x23a210 push {r4, lr} */
/* @0x23a214 mov r4, r2 */
/* @0x23a218 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a21c cmp r0, #0 */
/* @0x23a220 popeq {r4, pc} */
/* @0x23a224 mov r1, r4 */
/* @0x23a228 pop {r4, lr} */
/* @0x23a22c b 0x2d460c <_ZN15b2ParticleGroup13SetGroupFlagsEi> */

/* ── FUNC 0x23a230 · CPhysicsWorld::GetParticleGroupFlags(int) · size=24 · insn=6 */
/* @0x23a230 push {r3, lr} */
/* @0x23a234 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a238 cmp r0, #0 */
/* @0x23a23c popeq {r3, pc} */
/* @0x23a240 pop {r3, lr} */
/* @0x23a244 b 0x2d4604 <_ZNK15b2ParticleGroup13GetGroupFlagsEv> */

/* ── FUNC 0x23a248 · CPhysicsWorld::GetParticleData(IBuffer*, unsigned int, int, int) · size=820 · insn=205 */
/* @0x23a248 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23a24c vpush {d8} */
/* @0x23a250 mov r11, r0 */
/* @0x23a254 ldr r0, [r0, #0x10] */
/* @0x23a258 movw r12, #0x9298 */
/* @0x23a25c movt r12, #0x1 */
/* @0x23a260 mov r4, r1 */
/* @0x23a264 sub sp, sp, #44 */
/* @0x23a268 ldr r1, [r0, r12] */
/* @0x23a26c ldr r7, [sp, #0x58] */
/* @0x23a270 cmp r3, r1 */
/* @0x23a274 movlt r5, #0 */
/* @0x23a278 movge r5, #1 */
/* @0x23a27c orrs r5, r5, r3, lsr #31 */
/* @0x23a280 bne 0x23a294 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x4c> */
/* @0x23a284 cmp r3, r7 */
/* @0x23a288 bgt 0x23a294 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x4c> */
/* @0x23a28c cmp r7, r1 */
/* @0x23a290 ble 0x23a2a0 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x58> */
/* @0x23a294 add sp, sp, #44 */
/* @0x23a298 vpop {d8} */
/* @0x23a29c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23a2a0 str r2, [sp, #0x4] */
/* @0x23a2a4 vmov.f32 s16, #1.000000e+00 */
/* @0x23a2a8 str r3, [sp] */
/* @0x23a2ac bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv> */
/* @0x23a2b0 mov r10, r0 */
/* @0x23a2b4 ldr r0, [r11, #0x10] */
/* @0x23a2b8 bl 0x2cb574 <_ZN7b2World25GetParticlePositionBufferEv> */
/* @0x23a2bc mov r8, r0 */
/* @0x23a2c0 ldr r0, [r11, #0x10] */
/* @0x23a2c4 bl 0x2cb580 <_ZN7b2World25GetParticleVelocityBufferEv> */
/* @0x23a2c8 mov r9, r0 */
/* @0x23a2cc ldr r0, [r11, #0x10] */
/* @0x23a2d0 bl 0x2cb58c <_ZN7b2World22GetParticleColorBufferEv> */
/* @0x23a2d4 mov r6, r0 */
/* @0x23a2d8 ldr r0, [r11, #0x10] */
/* @0x23a2dc bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv> */
/* @0x23a2e0 ldr r3, [sp] */
/* @0x23a2e4 ldr r1, [r4, #0x1c] */
/* @0x23a2e8 vldr s15, [r11, #96] */
/* @0x23a2ec cmp r3, r7 */
/* @0x23a2f0 vdiv.f32 s16, s16, s15 */
/* @0x23a2f4 ldr r2, [sp, #0x4] */
/* @0x23a2f8 str r1, [sp, #0x24] */
/* @0x23a2fc bge 0x23a558 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x310> */
/* @0x23a300 lsl r1, r3, #2 */
/* @0x23a304 lsl r12, r3, #3 */
/* @0x23a308 add r10, r10, r1 */
/* @0x23a30c rsb r7, r3, r7 */
/* @0x23a310 str r10, [sp, #0x20] */
/* @0x23a314 and r3, r2, #1 */
/* @0x23a318 add r0, r0, r1 */
/* @0x23a31c str r3, [sp, #0xc] */
/* @0x23a320 add r6, r6, r1 */
/* @0x23a324 and r3, r2, #2 */
/* @0x23a328 str r0, [sp, #0x1c] */
/* @0x23a32c add r9, r9, r12 */
/* @0x23a330 str r3, [sp, #0x10] */
/* @0x23a334 add r8, r8, r12 */
/* @0x23a338 and r3, r2, #4 */
/* @0x23a33c add r11, r4, #44 */
/* @0x23a340 str r3, [sp, #0x14] */
/* @0x23a344 mov r10, r5 */
/* @0x23a348 and r3, r2, #8 */
/* @0x23a34c and r2, r2, #16 */
/* @0x23a350 str r3, [sp, #0x8] */
/* @0x23a354 str r2, [sp, #0x18] */
/* @0x23a358 b 0x23a3a4 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x15c> */
/* @0x23a35c ldr r3, [sp, #0x10] */
/* @0x23a360 cmp r3, #0 */
/* @0x23a364 bne 0x23a3f0 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x1a8> */
/* @0x23a368 ldr r3, [sp, #0x14] */
/* @0x23a36c cmp r3, #0 */
/* @0x23a370 bne 0x23a45c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x214> */
/* @0x23a374 ldr r3, [sp, #0x8] */
/* @0x23a378 cmp r3, #0 */
/* @0x23a37c bne 0x23a4c8 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x280> */
/* @0x23a380 ldr r3, [sp, #0x18] */
/* @0x23a384 cmp r3, #0 */
/* @0x23a388 bne 0x23a520 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x2d8> */
/* @0x23a38c add r5, r5, #1 */
/* @0x23a390 add r6, r6, #4 */
/* @0x23a394 cmp r5, r7 */
/* @0x23a398 add r9, r9, #8 */
/* @0x23a39c add r8, r8, #8 */
/* @0x23a3a0 beq 0x23a558 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x310> */
/* @0x23a3a4 ldr r3, [sp, #0xc] */
/* @0x23a3a8 cmp r3, #0 */
/* @0x23a3ac beq 0x23a35c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x114> */
/* @0x23a3b0 ldr r1, [sp, #0x20] */
/* @0x23a3b4 mov r0, r4 */
/* @0x23a3b8 ldr lr, [r4] */
/* @0x23a3bc mov r2, r11 */
/* @0x23a3c0 ldr r1, [r1, r5, lsl #2] */
/* @0x23a3c4 str r10, [r4, #0x38] */
/* @0x23a3c8 vmov s14, r1 */
/* @0x23a3cc mov r1, #5 */
/* @0x23a3d0 vcvt.f64.u32 d7, s14 */
/* @0x23a3d4 vstr s14, [r4, #44] */
/* @0x23a3d8 vstr s15, [r4, #48] */
/* @0x23a3dc ldr r3, [lr, #0x8] */
/* @0x23a3e0 blx r3 */
/* @0x23a3e4 ldr r3, [sp, #0x10] */
/* @0x23a3e8 cmp r3, #0 */
/* @0x23a3ec beq 0x23a368 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x120> */
/* @0x23a3f0 vldr s14, [r8] */
/* @0x23a3f4 vmul.f32 s14, s16, s14 */
/* @0x23a3f8 ldr lr, [r4] */
/* @0x23a3fc mov r1, #8 */
/* @0x23a400 mov r2, r11 */
/* @0x23a404 mov r0, r4 */
/* @0x23a408 str r10, [r4, #0x38] */
/* @0x23a40c vcvt.f64.f32 d7, s14 */
/* @0x23a410 vstr s14, [r4, #44] */
/* @0x23a414 vstr s15, [r4, #48] */
/* @0x23a418 ldr r3, [lr, #0x8] */
/* @0x23a41c blx r3 */
/* @0x23a420 vldr s14, [r8, #4] */
/* @0x23a424 vmul.f32 s14, s16, s14 */
/* @0x23a428 ldr lr, [r4] */
/* @0x23a42c str r10, [r4, #0x38] */
/* @0x23a430 mov r0, r4 */
/* @0x23a434 mov r1, #8 */
/* @0x23a438 mov r2, r11 */
/* @0x23a43c vcvt.f64.f32 d7, s14 */
/* @0x23a440 vstr s14, [r4, #44] */
/* @0x23a444 vstr s15, [r4, #48] */
/* @0x23a448 ldr r3, [lr, #0x8] */
/* @0x23a44c blx r3 */
/* @0x23a450 ldr r3, [sp, #0x14] */
/* @0x23a454 cmp r3, #0 */
/* @0x23a458 beq 0x23a374 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x12c> */
/* @0x23a45c vldr s14, [r9] */
/* @0x23a460 vmul.f32 s14, s16, s14 */
/* @0x23a464 ldr lr, [r4] */
/* @0x23a468 mov r1, #8 */
/* @0x23a46c mov r2, r11 */
/* @0x23a470 mov r0, r4 */
/* @0x23a474 str r10, [r4, #0x38] */
/* @0x23a478 vcvt.f64.f32 d7, s14 */
/* @0x23a47c vstr s14, [r4, #44] */
/* @0x23a480 vstr s15, [r4, #48] */
/* @0x23a484 ldr r3, [lr, #0x8] */
/* @0x23a488 blx r3 */
/* @0x23a48c vldr s14, [r9, #4] */
/* @0x23a490 vmul.f32 s14, s16, s14 */
/* @0x23a494 ldr lr, [r4] */
/* @0x23a498 str r10, [r4, #0x38] */
/* @0x23a49c mov r0, r4 */
/* @0x23a4a0 mov r1, #8 */
/* @0x23a4a4 mov r2, r11 */
/* @0x23a4a8 vcvt.f64.f32 d7, s14 */
/* @0x23a4ac vstr s14, [r4, #44] */
/* @0x23a4b0 vstr s15, [r4, #48] */
/* @0x23a4b4 ldr r3, [lr, #0x8] */
/* @0x23a4b8 blx r3 */
/* @0x23a4bc ldr r3, [sp, #0x8] */
/* @0x23a4c0 cmp r3, #0 */
/* @0x23a4c4 beq 0x23a380 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x138> */
/* @0x23a4c8 ldrb r12, [r6] */
/* @0x23a4cc mov r0, r4 */
/* @0x23a4d0 ldrb lr, [r6, #0x3] */
/* @0x23a4d4 mov r1, #5 */
/* @0x23a4d8 ldrb r2, [r6, #0x2] */
/* @0x23a4dc ldrb r3, [r6, #0x1] */
/* @0x23a4e0 lsl r12, r12, #16 */
/* @0x23a4e4 orr r12, r12, lr, lsl #24 */
/* @0x23a4e8 ldr lr, [r4] */
/* @0x23a4ec orr r12, r12, r2 */
/* @0x23a4f0 str r10, [r4, #0x38] */
/* @0x23a4f4 orr r12, r12, r3, lsl #8 */
/* @0x23a4f8 mov r2, r11 */
/* @0x23a4fc vmov s13, r12 */
/* @0x23a500 vcvt.f64.u32 d7, s13 */
/* @0x23a504 vstr s14, [r4, #44] */
/* @0x23a508 vstr s15, [r4, #48] */
/* @0x23a50c ldr r3, [lr, #0x8] */
/* @0x23a510 blx r3 */
/* @0x23a514 ldr r3, [sp, #0x18] */
/* @0x23a518 cmp r3, #0 */
/* @0x23a51c beq 0x23a38c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x144> */
/* @0x23a520 ldr r1, [sp, #0x1c] */
/* @0x23a524 mov r0, r4 */
/* @0x23a528 ldr lr, [r4] */
/* @0x23a52c mov r2, r11 */
/* @0x23a530 ldr r1, [r1, r5, lsl #2] */
/* @0x23a534 str r10, [r4, #0x38] */
/* @0x23a538 vmov s14, r1 */
/* @0x23a53c mov r1, #6 */
/* @0x23a540 vcvt.f64.s32 d7, s14 */
/* @0x23a544 vstr s14, [r4, #44] */
/* @0x23a548 vstr s15, [r4, #48] */
/* @0x23a54c ldr r3, [lr, #0x8] */
/* @0x23a550 blx r3 */
/* @0x23a554 b 0x23a38c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x144> */
/* @0x23a558 ldr r3, [r4] */
/* @0x23a55c mov r0, r4 */
/* @0x23a560 ldr r2, [sp, #0x24] */
/* @0x23a564 mov r1, #0 */
/* @0x23a568 ldr r3, [r3, #0x10] */
/* @0x23a56c blx r3 */
/* @0x23a570 add sp, sp, #44 */
/* @0x23a574 vpop {d8} */
/* @0x23a578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x23a57c · CPhysicsWorld::GetParticleData(IBuffer*, unsigned int) · size=44 · insn=11 */
/* @0x23a57c str lr, [sp, #-0x4]! */
/* @0x23a580 movw r12, #0x9298 */
/* @0x23a584 ldr lr, [r0, #0x10] */
/* @0x23a588 movt r12, #0x1 */
/* @0x23a58c sub sp, sp, #12 */
/* @0x23a590 mov r3, #0 */
/* @0x23a594 ldr r12, [lr, r12] */
/* @0x23a598 str r12, [sp] */
/* @0x23a59c bl 0x23a248 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii> */
/* @0x23a5a0 add sp, sp, #12 */
/* @0x23a5a4 ldr pc, [sp], #4 */

/* ── FUNC 0x23a5a8 · CPhysicsWorld::GetParticleDataParticle(int, IBuffer*, unsigned int) · size=44 · insn=11 */
/* @0x23a5a8 str lr, [sp, #-0x4]! */
/* @0x23a5ac sub sp, sp, #12 */
/* @0x23a5b0 mov r12, r1 */
/* @0x23a5b4 mov r1, r2 */
/* @0x23a5b8 add lr, r12, #1 */
/* @0x23a5bc mov r2, r3 */
/* @0x23a5c0 str lr, [sp] */
/* @0x23a5c4 mov r3, r12 */
/* @0x23a5c8 bl 0x23a248 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii> */
/* @0x23a5cc add sp, sp, #12 */
/* @0x23a5d0 ldr pc, [sp], #4 */

/* ── FUNC 0x23a5d4 · CPhysicsWorld::GetParticleGroupCount(int) · size=28 · insn=7 */
/* @0x23a5d4 push {r3, lr} */
/* @0x23a5d8 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a5dc cmp r0, #0 */
/* @0x23a5e0 ldrne r2, [r0, #0x8] */
/* @0x23a5e4 ldrne r3, [r0, #0x4] */
/* @0x23a5e8 rsbne r0, r3, r2 */
/* @0x23a5ec pop {r3, pc} */

/* ── FUNC 0x23a5f0 · CPhysicsWorld::GetParticleDataGroup(int, IBuffer*, unsigned int) · size=88 · insn=22 */
/* @0x23a5f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x23a5f4 sub sp, sp, #8 */
/* @0x23a5f8 mov r6, r2 */
/* @0x23a5fc mov r5, r3 */
/* @0x23a600 mov r7, r0 */
/* @0x23a604 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a608 subs r4, r0, #0 */
/* @0x23a60c beq 0x23a640 <_ZN13CPhysicsWorld20GetParticleDataGroupEiP7IBufferj+0x50> */
/* @0x23a610 bl 0x2d45fc <_ZNK15b2ParticleGroup14GetBufferIndexEv> */
/* @0x23a614 ldr r8, [r4, #0x8] */
/* @0x23a618 ldr lr, [r4, #0x4] */
/* @0x23a61c mov r1, r6 */
/* @0x23a620 mov r2, r5 */
/* @0x23a624 rsb lr, lr, r8 */
/* @0x23a628 mov r12, r0 */
/* @0x23a62c mov r0, r7 */
/* @0x23a630 mov r3, r12 */
/* @0x23a634 add r12, r12, lr */
/* @0x23a638 str r12, [sp] */
/* @0x23a63c bl 0x23a248 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii> */
/* @0x23a640 add sp, sp, #8 */
/* @0x23a644 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x23a648 · CPhysicsWorld::GetParticleGroupMass(int) · size=32 · insn=8 */
/* @0x23a648 push {r3, lr} */
/* @0x23a64c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a650 cmp r0, #0 */
/* @0x23a654 beq 0x23a660 <_ZN13CPhysicsWorld20GetParticleGroupMassEi+0x18> */
/* @0x23a658 pop {r3, lr} */
/* @0x23a65c b 0x2d4814 <_ZNK15b2ParticleGroup7GetMassEv> */
/* @0x23a660 mov r0, #0 */
/* @0x23a664 pop {r3, pc} */

/* ── FUNC 0x23a668 · CPhysicsWorld::GetParticleGroupInertia(int) · size=32 · insn=8 */
/* @0x23a668 push {r3, lr} */
/* @0x23a66c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a670 cmp r0, #0 */
/* @0x23a674 beq 0x23a680 <_ZN13CPhysicsWorld23GetParticleGroupInertiaEi+0x18> */
/* @0x23a678 pop {r3, lr} */
/* @0x23a67c b 0x2d4828 <_ZNK15b2ParticleGroup10GetInertiaEv> */
/* @0x23a680 mov r0, #0 */
/* @0x23a684 pop {r3, pc} */

/* ── FUNC 0x23a688 · CPhysicsWorld::GetParticleGroupCentreX(int) · size=76 · insn=19 */
/* @0x23a688 push {r4, lr} */
/* @0x23a68c sub sp, sp, #8 */
/* @0x23a690 mov r4, r0 */
/* @0x23a694 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a698 subs r1, r0, #0 */
/* @0x23a69c beq 0x23a6c0 <_ZN13CPhysicsWorld23GetParticleGroupCentreXEi+0x38> */
/* @0x23a6a0 mov r0, sp */
/* @0x23a6a4 bl 0x2d483c <_ZNK15b2ParticleGroup9GetCenterEv> */
/* @0x23a6a8 vldr s14, [sp] */
/* @0x23a6ac vldr s15, [r4, #96] */
/* @0x23a6b0 vdiv.f32 s15, s14, s15 */
/* @0x23a6b4 vmov r0, s15 */
/* @0x23a6b8 add sp, sp, #8 */
/* @0x23a6bc pop {r4, pc} */
/* @0x23a6c0 vldr s15, [pc, #8] */
/* @0x23a6c4 vmov r0, s15 */
/* @0x23a6c8 add sp, sp, #8 */
/* @0x23a6cc pop {r4, pc} */
/* @0x23a6d0 andeq r0, r0, r0 */

/* ── FUNC 0x23a6d4 · CPhysicsWorld::GetParticleGroupCentreY(int) · size=76 · insn=19 */
/* @0x23a6d4 push {r4, lr} */
/* @0x23a6d8 sub sp, sp, #8 */
/* @0x23a6dc mov r4, r0 */
/* @0x23a6e0 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a6e4 subs r1, r0, #0 */
/* @0x23a6e8 beq 0x23a70c <_ZN13CPhysicsWorld23GetParticleGroupCentreYEi+0x38> */
/* @0x23a6ec mov r0, sp */
/* @0x23a6f0 bl 0x2d483c <_ZNK15b2ParticleGroup9GetCenterEv> */
/* @0x23a6f4 vldr s14, [sp, #4] */
/* @0x23a6f8 vldr s15, [r4, #96] */
/* @0x23a6fc vdiv.f32 s15, s14, s15 */
/* @0x23a700 vmov r0, s15 */
/* @0x23a704 add sp, sp, #8 */
/* @0x23a708 pop {r4, pc} */
/* @0x23a70c vldr s15, [pc, #8] */
/* @0x23a710 vmov r0, s15 */
/* @0x23a714 add sp, sp, #8 */
/* @0x23a718 pop {r4, pc} */
/* @0x23a71c andeq r0, r0, r0 */

/* ── FUNC 0x23a720 · CPhysicsWorld::GetParticleGroupVelocityX(int) · size=76 · insn=19 */
/* @0x23a720 push {r4, lr} */
/* @0x23a724 sub sp, sp, #8 */
/* @0x23a728 mov r4, r0 */
/* @0x23a72c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a730 subs r1, r0, #0 */
/* @0x23a734 beq 0x23a758 <_ZN13CPhysicsWorld25GetParticleGroupVelocityXEi+0x38> */
/* @0x23a738 mov r0, sp */
/* @0x23a73c bl 0x2d4864 <_ZNK15b2ParticleGroup17GetLinearVelocityEv> */
/* @0x23a740 vldr s14, [sp] */
/* @0x23a744 vldr s15, [r4, #96] */
/* @0x23a748 vdiv.f32 s15, s14, s15 */
/* @0x23a74c vmov r0, s15 */
/* @0x23a750 add sp, sp, #8 */
/* @0x23a754 pop {r4, pc} */
/* @0x23a758 vldr s15, [pc, #8] */
/* @0x23a75c vmov r0, s15 */
/* @0x23a760 add sp, sp, #8 */
/* @0x23a764 pop {r4, pc} */
/* @0x23a768 andeq r0, r0, r0 */

/* ── FUNC 0x23a76c · CPhysicsWorld::GetParticleGroupVelocityY(int) · size=76 · insn=19 */
/* @0x23a76c push {r4, lr} */
/* @0x23a770 sub sp, sp, #8 */
/* @0x23a774 mov r4, r0 */
/* @0x23a778 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a77c subs r1, r0, #0 */
/* @0x23a780 beq 0x23a7a4 <_ZN13CPhysicsWorld25GetParticleGroupVelocityYEi+0x38> */
/* @0x23a784 mov r0, sp */
/* @0x23a788 bl 0x2d4864 <_ZNK15b2ParticleGroup17GetLinearVelocityEv> */
/* @0x23a78c vldr s14, [sp, #4] */
/* @0x23a790 vldr s15, [r4, #96] */
/* @0x23a794 vdiv.f32 s15, s14, s15 */
/* @0x23a798 vmov r0, s15 */
/* @0x23a79c add sp, sp, #8 */
/* @0x23a7a0 pop {r4, pc} */
/* @0x23a7a4 vldr s15, [pc, #8] */
/* @0x23a7a8 vmov r0, s15 */
/* @0x23a7ac add sp, sp, #8 */
/* @0x23a7b0 pop {r4, pc} */
/* @0x23a7b4 andeq r0, r0, r0 */

/* ── FUNC 0x23a7b8 · CPhysicsWorld::GetParticleGroupOmega(int) · size=72 · insn=18 */
/* @0x23a7b8 push {r3, lr} */
/* @0x23a7bc bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a7c0 cmp r0, #0 */
/* @0x23a7c4 beq 0x23a7e8 <_ZN13CPhysicsWorld21GetParticleGroupOmegaEi+0x30> */
/* @0x23a7c8 bl 0x2d488c <_ZNK15b2ParticleGroup18GetAngularVelocityEv> */
/* @0x23a7cc vldr s15, [pc, #32] */
/* @0x23a7d0 vldr s14, [pc, #32] */
/* @0x23a7d4 vmov s13, r0 */
/* @0x23a7d8 vmul.f32 s15, s13, s15 */
/* @0x23a7dc vdiv.f32 s15, s15, s14 */
/* @0x23a7e0 vmov r0, s15 */
/* @0x23a7e4 pop {r3, pc} */
/* @0x23a7e8 vldr s15, [pc, #12] */
/* @0x23a7ec vmov r0, s15 */
/* @0x23a7f0 pop {r3, pc} */
/* @0x23a7f4 teqmi r4, #0 */
/* @0x23a7f8 ldrdmi r0, r1, [r9], #-251 */
/* @0x23a7fc andeq r0, r0, r0 */

/* ── FUNC 0x23a800 · CPhysicsWorld::GetParticleGroupX(int) · size=60 · insn=15 */
/* @0x23a800 push {r4, lr} */
/* @0x23a804 mov r4, r0 */
/* @0x23a808 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a80c cmp r0, #0 */
/* @0x23a810 beq 0x23a82c <_ZN13CPhysicsWorld17GetParticleGroupXEi+0x2c> */
/* @0x23a814 bl 0x2d461c <_ZNK15b2ParticleGroup11GetPositionEv> */
/* @0x23a818 vldr s15, [r4, #96] */
/* @0x23a81c vldr s14, [r0] */
/* @0x23a820 vdiv.f32 s15, s14, s15 */
/* @0x23a824 vmov r0, s15 */
/* @0x23a828 pop {r4, pc} */
/* @0x23a82c vldr s15, [pc, #4] */
/* @0x23a830 vmov r0, s15 */
/* @0x23a834 pop {r4, pc} */
/* @0x23a838 andeq r0, r0, r0 */

/* ── FUNC 0x23a83c · CPhysicsWorld::GetParticleGroupY(int) · size=60 · insn=15 */
/* @0x23a83c push {r4, lr} */
/* @0x23a840 mov r4, r0 */
/* @0x23a844 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a848 cmp r0, #0 */
/* @0x23a84c beq 0x23a868 <_ZN13CPhysicsWorld17GetParticleGroupYEi+0x2c> */
/* @0x23a850 bl 0x2d461c <_ZNK15b2ParticleGroup11GetPositionEv> */
/* @0x23a854 vldr s15, [r4, #96] */
/* @0x23a858 vldr s14, [r0, #4] */
/* @0x23a85c vdiv.f32 s15, s14, s15 */
/* @0x23a860 vmov r0, s15 */
/* @0x23a864 pop {r4, pc} */
/* @0x23a868 vldr s15, [pc, #4] */
/* @0x23a86c vmov r0, s15 */
/* @0x23a870 pop {r4, pc} */
/* @0x23a874 andeq r0, r0, r0 */

/* ── FUNC 0x23a878 · CPhysicsWorld::GetParticleGroupAngle(int) · size=72 · insn=18 */
/* @0x23a878 push {r3, lr} */
/* @0x23a87c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x23a880 cmp r0, #0 */
/* @0x23a884 beq 0x23a8a8 <_ZN13CPhysicsWorld21GetParticleGroupAngleEi+0x30> */
/* @0x23a888 bl 0x2d4624 <_ZNK15b2ParticleGroup8GetAngleEv> */
/* @0x23a88c vldr s15, [pc, #32] */
/* @0x23a890 vldr s14, [pc, #32] */
/* @0x23a894 vmov s13, r0 */
/* @0x23a898 vmul.f32 s15, s13, s15 */
/* @0x23a89c vdiv.f32 s15, s15, s14 */
/* @0x23a8a0 vmov r0, s15 */
/* @0x23a8a4 pop {r3, pc} */
/* @0x23a8a8 vldr s15, [pc, #12] */
/* @0x23a8ac vmov r0, s15 */
/* @0x23a8b0 pop {r3, pc} */
/* @0x23a8b4 teqmi r4, #0 */
/* @0x23a8b8 ldrdmi r0, r1, [r9], #-251 */
/* @0x23a8bc andeq r0, r0, r0 */

/* ── FUNC 0x23a8c0 · CPhysicsWorld::DrawParticles(unsigned int, int, CSprite*, int) · size=1076 · insn=269 */
/* @0x23a8c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23a8c4 vpush {d8, d9, d10} */
/* @0x23a8c8 sub sp, sp, #44 */
/* @0x23a8cc ldr r5, [r3, #0x18] */
/* @0x23a8d0 mov r6, r0 */
/* @0x23a8d4 str r1, [sp, #0xc] */
/* @0x23a8d8 mov r4, r3 */
/* @0x23a8dc ldr r0, [sp, #0x68] */
/* @0x23a8e0 mov r8, r2 */
/* @0x23a8e4 mov r1, r5 */
/* @0x23a8e8 bl 0x318dec <__aeabi_idivmod> */
/* @0x23a8ec ldr r3, [r4, #0x54] */
/* @0x23a8f0 cmp r1, #0 */
/* @0x23a8f4 addlt r1, r1, r5 */
/* @0x23a8f8 cmp r3, #0 */
/* @0x23a8fc beq 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54> */
/* @0x23a900 ldr r5, [r3, r1, lsl #2] */
/* @0x23a904 ldrsh r0, [r5, #20] */
/* @0x23a908 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x23a90c cmp r0, #0 */
/* @0x23a910 bne 0x23a920 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x60> */
/* @0x23a914 add sp, sp, #44 */
/* @0x23a918 vpop {d8, d9, d10} */
/* @0x23a91c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23a920 ldr r3, [pc, #0x3c8] */
/* @0x23a924 ldrsh r2, [r5, #20] */
/* @0x23a928 ldr r3, [pc, r3] */
/* @0x23a92c ldr r0, [r6, #0x10] */
/* @0x23a930 ldr r3, [r3, #0x4] */
/* @0x23a934 ldr r3, [r3, r2, lsl #2] */
/* @0x23a938 str r3, [sp, #0x4] */
/* @0x23a93c bl 0x2cb574 <_ZN7b2World25GetParticlePositionBufferEv> */
/* @0x23a940 str r0, [sp, #0x20] */
/* @0x23a944 ldr r0, [r6, #0x10] */
/* @0x23a948 bl 0x2cb58c <_ZN7b2World22GetParticleColorBufferEv> */
/* @0x23a94c str r0, [sp, #0x24] */
/* @0x23a950 ldr r0, [r6, #0x10] */
/* @0x23a954 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv> */
/* @0x23a958 str r0, [sp, #0x18] */
/* @0x23a95c ldr r0, [r6, #0x10] */
/* @0x23a960 bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv> */
/* @0x23a964 ldr r2, [r6, #0x10] */
/* @0x23a968 movw r3, #0x9298 */
/* @0x23a96c movt r3, #0x1 */
/* @0x23a970 vldr s15, [r6, #96] */
/* @0x23a974 ldr r11, [r2, r3] */
/* @0x23a978 cmp r11, #0 */
/* @0x23a97c str r0, [sp, #0x1c] */
/* @0x23a980 ble 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54> */
/* @0x23a984 cmp r8, #0 */
/* @0x23a988 beq 0x23acb4 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3f4> */
/* @0x23a98c mov r3, #0 */
/* @0x23a990 lsl r0, r11, #2 */
/* @0x23a994 mov r1, r3 */
/* @0x23a998 ldr r12, [sp, #0x18] */
/* @0x23a99c ldr r7, [sp, #0x1c] */
/* @0x23a9a0 ldr r6, [sp, #0xc] */
/* @0x23a9a4 b 0x23a9c0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x100> */
/* @0x23a9a8 ldr r2, [r7, r3] */
/* @0x23a9ac cmp r2, r8 */
/* @0x23a9b0 addeq r1, r1, #1 */
/* @0x23a9b4 add r3, r3, #4 */
/* @0x23a9b8 cmp r3, r0 */
/* @0x23a9bc beq 0x23a9e0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x120> */
/* @0x23a9c0 ldr r2, [r12, r3] */
/* @0x23a9c4 cmp r2, #0 */
/* @0x23a9c8 beq 0x23a9a8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0xe8> */
/* @0x23a9cc tst r2, r6 */
/* @0x23a9d0 bne 0x23a9a8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0xe8> */
/* @0x23a9d4 add r3, r3, #4 */
/* @0x23a9d8 cmp r3, r0 */
/* @0x23a9dc bne 0x23a9c0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x100> */
/* @0x23a9e0 cmp r1, #0 */
/* @0x23a9e4 beq 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54> */
/* @0x23a9e8 ldr r3, [r4, #0x24] */
/* @0x23a9ec vmov.f32 s16, #1.000000e+00 */
/* @0x23a9f0 ldrsh r12, [r5, #8] */
/* @0x23a9f4 add r1, r1, r1, lsl #1 */
/* @0x23a9f8 ldr r2, [r4, #0x28] */
/* @0x23a9fc vldr s17, [pc, #744] */
/* @0x23aa00 rsb r12, r3, r12 */
/* @0x23aa04 ldrh r3, [r5, #12] */
/* @0x23aa08 ldrsh r0, [r5, #10] */
/* @0x23aa0c lsl r1, r1, #1 */
/* @0x23aa10 cmp r3, #0 */
/* @0x23aa14 vmov s14, r12 */
/* @0x23aa18 sxthne r3, r3 */
/* @0x23aa1c rsb r2, r2, r0 */
/* @0x23aa20 moveq r3, #1 */
/* @0x23aa24 strheq r3, [r5, #12] */
/* @0x23aa28 vmovne s21, r3 */
/* @0x23aa2c ldrh r3, [r5, #14] */
/* @0x23aa30 str r1, [sp, #0x14] */
/* @0x23aa34 mov r4, #0 */
/* @0x23aa38 vcvtne.f32.s32 s21, s21 */
/* @0x23aa3c vmoveq.f32 s21, #1.000000e+00 */
/* @0x23aa40 cmp r3, #0 */
/* @0x23aa44 sxthne r3, r3 */
/* @0x23aa48 moveq r3, #1 */
/* @0x23aa4c strheq r3, [r5, #14] */
/* @0x23aa50 vmovne s20, r3 */
/* @0x23aa54 vcvt.f32.s32 s19, s14 */
/* @0x23aa58 vmov s14, r2 */
/* @0x23aa5c vcvtne.f32.s32 s20, s20 */
/* @0x23aa60 vmoveq.f32 s20, #1.000000e+00 */
/* @0x23aa64 vcvt.f32.s32 s18, s14 */
/* @0x23aa68 vdiv.f32 s16, s16, s15 */
/* @0x23aa6c bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x23aa70 ldr r9, [sp, #0x14] */
/* @0x23aa74 cmp r0, r9 */
/* @0x23aa78 vadd.f32 s21, s19, s21 */
/* @0x23aa7c vadd.f32 s20, s18, s20 */
/* @0x23aa80 blt 0x23aca8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3e8> */
/* @0x23aa84 ldr r10, [sp, #0x14] */
/* @0x23aa88 str r10, [sp, #0x8] */
/* @0x23aa8c ldr r9, [sp, #0x4] */
/* @0x23aa90 mov r0, #4 */
/* @0x23aa94 mov r2, #24 */
/* @0x23aa98 ldr r3, [sp, #0x8] */
/* @0x23aa9c ldr r1, [r9] */
/* @0x23aaa0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x23aaa4 cmp r11, r4 */
/* @0x23aaa8 ble 0x23ac8c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3cc> */
/* @0x23aaac ldr r10, [sp, #0x18] */
/* @0x23aab0 lsl r7, r4, #2 */
/* @0x23aab4 ldr r1, [sp, #0x1c] */
/* @0x23aab8 mov r3, #0 */
/* @0x23aabc add r6, r10, r7 */
/* @0x23aac0 ldr r9, [sp, #0x24] */
/* @0x23aac4 ldr r10, [sp, #0x20] */
/* @0x23aac8 add r1, r1, r7 */
/* @0x23aacc mov r12, r3 */
/* @0x23aad0 str r1, [sp, #0x10] */
/* @0x23aad4 add r7, r9, r7 */
/* @0x23aad8 add r2, r10, r4, lsl #3 */
/* @0x23aadc b 0x23ab04 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x244> */
/* @0x23aae0 ldr r10, [sp, #0x10] */
/* @0x23aae4 ldr r1, [r10, r3] */
/* @0x23aae8 cmp r1, r8 */
/* @0x23aaec beq 0x23ab24 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x264> */
/* @0x23aaf0 add r4, r4, #1 */
/* @0x23aaf4 add r3, r3, #4 */
/* @0x23aaf8 cmp r4, r11 */
/* @0x23aafc add r2, r2, #8 */
/* @0x23ab00 beq 0x23ac8c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3cc> */
/* @0x23ab04 ldr r1, [r6, r3] */
/* @0x23ab08 cmp r1, #0 */
/* @0x23ab0c beq 0x23ab1c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x25c> */
/* @0x23ab10 ldr r9, [sp, #0xc] */
/* @0x23ab14 tst r1, r9 */
/* @0x23ab18 beq 0x23aaf0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x230> */
/* @0x23ab1c cmp r8, #0 */
/* @0x23ab20 bne 0x23aae0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x220> */
/* @0x23ab24 add r1, r7, r3 */
/* @0x23ab28 ldrb r9, [r7, r3] */
/* @0x23ab2c ldrb r10, [r1, #0x3] */
/* @0x23ab30 vmov s15, r10 */
/* @0x23ab34 ldrb r10, [r1, #0x1] */
/* @0x23ab38 ldrb r1, [r1, #0x2] */
/* @0x23ab3c vcvt.f32.s32 s15, s15 */
/* @0x23ab40 orr r9, r9, r10, lsl #8 */
/* @0x23ab44 orr r1, r9, r1, lsl #16 */
/* @0x23ab48 vdiv.f32 s15, s15, s17 */
/* @0x23ab4c vmul.f32 s15, s15, s17 */
/* @0x23ab50 vcvt.s32.f32 s15, s15 */
/* @0x23ab54 vmov r9, s15 */
/* @0x23ab58 cmp r9, #255 */
/* @0x23ab5c movgt r9, #-16777216 */
/* @0x23ab60 bgt 0x23ab70 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x2b0> */
/* @0x23ab64 cmp r9, #0 */
/* @0x23ab68 lslge r9, r9, #24 */
/* @0x23ab6c movlt r9, #0 */
/* @0x23ab70 ldrsh r10, [r5] */
/* @0x23ab74 orr r1, r9, r1 */
/* @0x23ab78 add r9, r12, #11 */
/* @0x23ab7c vldr s11, [r2] */
/* @0x23ab80 vldr s13, [r2, #4] */
/* @0x23ab84 vmul.f32 s11, s16, s11 */
/* @0x23ab88 vmov s14, r10 */
/* @0x23ab8c ldr r10, [sp, #0x4] */
/* @0x23ab90 vldr s9, [r10, #8] */
/* @0x23ab94 ldr r10, [sp, #0x8] */
/* @0x23ab98 str r1, [r0, #0x84] */
/* @0x23ab9c add r12, r12, #6 */
/* @0x23aba0 cmp r10, r9 */
/* @0x23aba4 str r1, [r0, #0x6c] */
/* @0x23aba8 str r1, [r0, #0x54] */
/* @0x23abac add r0, r0, #144 */
/* @0x23abb0 str r1, [r0, #-0x54] */
/* @0x23abb4 str r1, [r0, #-0x6c] */
/* @0x23abb8 str r1, [r0, #-0x84] */
/* @0x23abbc vmov r1, s14 */
/* @0x23abc0 ldr r9, [sp, #0x4] */
/* @0x23abc4 vcvt.f32.s32 s15, s14 */
/* @0x23abc8 vmul.f32 s15, s15, s9 */
/* @0x23abcc vstr s15, [r0, #-32] */
/* @0x23abd0 vstr s15, [r0, #-128] */
/* @0x23abd4 vstr s15, [r0, #-8] */
/* @0x23abd8 ldrsh r10, [r5, #2] */
/* @0x23abdc vldr s10, [r9, #12] */
/* @0x23abe0 vmul.f32 s13, s16, s13 */
/* @0x23abe4 vmov s15, r10 */
/* @0x23abe8 vcvt.f32.s32 s12, s15 */
/* @0x23abec vmul.f32 s12, s12, s10 */
/* @0x23abf0 vstr s12, [r0, #-100] */
/* @0x23abf4 vstr s12, [r0, #-124] */
/* @0x23abf8 vstr s12, [r0, #-4] */
/* @0x23abfc ldrsh r9, [r5, #4] */
/* @0x23ac00 vadd.f32 s12, s11, s19 */
/* @0x23ac04 add r1, r1, r9 */
/* @0x23ac08 vmov s14, r1 */
/* @0x23ac0c vcvt.f32.s32 s14, s14 */
/* @0x23ac10 vstr s12, [r0, #-144] */
/* @0x23ac14 vstr s12, [r0, #-24] */
/* @0x23ac18 vstr s12, [r0, #-48] */
/* @0x23ac1c vmul.f32 s14, s9, s14 */
/* @0x23ac20 vadd.f32 s12, s13, s18 */
/* @0x23ac24 vstr s14, [r0, #-80] */
/* @0x23ac28 vstr s14, [r0, #-56] */
/* @0x23ac2c vadd.f32 s11, s11, s21 */
/* @0x23ac30 vstr s12, [r0, #-116] */
/* @0x23ac34 vstr s12, [r0, #-140] */
/* @0x23ac38 vstr s12, [r0, #-20] */
/* @0x23ac3c vadd.f32 s13, s13, s20 */
/* @0x23ac40 vstr s11, [r0, #-96] */
/* @0x23ac44 vstr s11, [r0, #-72] */
/* @0x23ac48 vstr s11, [r0, #-120] */
/* @0x23ac4c vstr s13, [r0, #-44] */
/* @0x23ac50 vstr s14, [r0, #-104] */
/* @0x23ac54 ldrsh r1, [r5, #6] */
/* @0x23ac58 vstr s13, [r0, #-92] */
/* @0x23ac5c vstr s13, [r0, #-68] */
/* @0x23ac60 add r1, r10, r1 */
/* @0x23ac64 vmov s15, r1 */
/* @0x23ac68 vcvt.f32.s32 s15, s15 */
/* @0x23ac6c vmul.f32 s15, s10, s15 */
/* @0x23ac70 vstr s15, [r0, #-28] */
/* @0x23ac74 vstr s15, [r0, #-76] */
/* @0x23ac78 vstr s15, [r0, #-52] */
/* @0x23ac7c bgt 0x23aaf0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x230> */
/* @0x23ac80 ldr r9, [sp, #0x14] */
/* @0x23ac84 rsb r9, r12, r9 */
/* @0x23ac88 str r9, [sp, #0x14] */
/* @0x23ac8c ldr r10, [sp, #0x14] */
/* @0x23ac90 cmp r10, #0 */
/* @0x23ac94 ble 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54> */
/* @0x23ac98 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x23ac9c ldr r9, [sp, #0x14] */
/* @0x23aca0 cmp r0, r9 */
/* @0x23aca4 bge 0x23aa84 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x1c4> */
/* @0x23aca8 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x23acac str r0, [sp, #0x8] */
/* @0x23acb0 b 0x23aa8c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x1cc> */
/* @0x23acb4 ldr r9, [sp, #0x18] */
/* @0x23acb8 mov r1, r8 */
/* @0x23acbc ldr r12, [sp, #0xc] */
/* @0x23acc0 add r0, r9, r11, lsl #2 */
/* @0x23acc4 mov r3, r9 */
/* @0x23acc8 ldr r2, [r3], #4 */
/* @0x23accc cmp r2, #0 */
/* @0x23acd0 beq 0x23acdc <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x41c> */
/* @0x23acd4 tst r2, r12 */
/* @0x23acd8 beq 0x23ace0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x420> */
/* @0x23acdc add r1, r1, #1 */
/* @0x23ace0 cmp r3, r0 */
/* @0x23ace4 bne 0x23acc8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x408> */
/* @0x23ace8 b 0x23a9e0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x120> */
/* @0x23acec cmnmi pc, #0 */
/* @0x23acf0 ldrsheq r2, [r11], -r4 */

/* ── FUNC 0x23acf4 · CPhysicsWorld::DrawParticlesExt(unsigned int, int, CSprite*, int, float, float, float, unsigned int, float) · size=1324 · insn=331 */
/* @0x23acf4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23acf8 vpush {d8, d9, d10} */
/* @0x23acfc sub sp, sp, #20 */
/* @0x23ad00 ldr r4, [r3, #0x18] */
/* @0x23ad04 mov r5, r0 */
/* @0x23ad08 mov r9, r1 */
/* @0x23ad0c ldr r0, [sp, #0x50] */
/* @0x23ad10 mov r10, r3 */
/* @0x23ad14 mov r6, r2 */
/* @0x23ad18 mov r1, r4 */
/* @0x23ad1c bl 0x318dec <__aeabi_idivmod> */
/* @0x23ad20 ldr r3, [r10, #0x54] */
/* @0x23ad24 cmp r1, #0 */
/* @0x23ad28 addlt r1, r1, r4 */
/* @0x23ad2c cmp r3, #0 */
/* @0x23ad30 beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54> */
/* @0x23ad34 ldr r4, [r3, r1, lsl #2] */
/* @0x23ad38 ldrsh r0, [r4, #20] */
/* @0x23ad3c bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x23ad40 cmp r0, #0 */
/* @0x23ad44 bne 0x23ad54 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x60> */
/* @0x23ad48 add sp, sp, #20 */
/* @0x23ad4c vpop {d8, d9, d10} */
/* @0x23ad50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23ad54 ldr r3, [pc, #0x374] */
/* @0x23ad58 ldrsh r2, [r4, #20] */
/* @0x23ad5c ldr r3, [pc, r3] */
/* @0x23ad60 ldr r0, [r5, #0x10] */
/* @0x23ad64 ldr r3, [r3, #0x4] */
/* @0x23ad68 ldr r11, [r3, r2, lsl #2] */
/* @0x23ad6c bl 0x2cb574 <_ZN7b2World25GetParticlePositionBufferEv> */
/* @0x23ad70 str r0, [sp, #0xc] */
/* @0x23ad74 ldr r0, [r5, #0x10] */
/* @0x23ad78 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv> */
/* @0x23ad7c mov r7, r0 */
/* @0x23ad80 ldr r0, [r5, #0x10] */
/* @0x23ad84 bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv> */
/* @0x23ad88 ldr r2, [r5, #0x10] */
/* @0x23ad8c movw r3, #0x9298 */
/* @0x23ad90 movt r3, #0x1 */
/* @0x23ad94 vldr s15, [r5, #96] */
/* @0x23ad98 ldr r8, [r2, r3] */
/* @0x23ad9c cmp r8, #0 */
/* @0x23ada0 mov r12, r0 */
/* @0x23ada4 ble 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54> */
/* @0x23ada8 cmp r6, #0 */
/* @0x23adac lsl r8, r8, #2 */
/* @0x23adb0 beq 0x23b040 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x34c> */
/* @0x23adb4 mov r3, #0 */
/* @0x23adb8 mov r2, r3 */
/* @0x23adbc b 0x23add8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xe4> */
/* @0x23adc0 ldr r1, [r12, r3] */
/* @0x23adc4 cmp r1, r6 */
/* @0x23adc8 addeq r2, r2, #1 */
/* @0x23adcc add r3, r3, #4 */
/* @0x23add0 cmp r3, r8 */
/* @0x23add4 beq 0x23adf8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x104> */
/* @0x23add8 ldr r1, [r7, r3] */
/* @0x23addc cmp r1, #0 */
/* @0x23ade0 beq 0x23adc0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xcc> */
/* @0x23ade4 tst r1, r9 */
/* @0x23ade8 bne 0x23adc0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xcc> */
/* @0x23adec add r3, r3, #4 */
/* @0x23adf0 cmp r3, r8 */
/* @0x23adf4 bne 0x23add8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xe4> */
/* @0x23adf8 cmp r2, #0 */
/* @0x23adfc beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54> */
/* @0x23ae00 vldr s14, [pc, #704] */
/* @0x23ae04 vldr s11, [sp, #100] */
/* @0x23ae08 vmul.f32 s14, s11, s14 */
/* @0x23ae0c vcvt.s32.f32 s14, s14 */
/* @0x23ae10 vmov r5, s14 */
/* @0x23ae14 cmp r5, #255 */
/* @0x23ae18 movgt r5, #-16777216 */
/* @0x23ae1c bgt 0x23ae2c <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x138> */
/* @0x23ae20 cmp r5, #0 */
/* @0x23ae24 lslge r5, r5, #24 */
/* @0x23ae28 movlt r5, #0 */
/* @0x23ae2c ldrsh r3, [r4, #12] */
/* @0x23ae30 vmov.f32 s16, #1.000000e+00 */
/* @0x23ae34 ldr r0, [sp, #0x60] */
/* @0x23ae38 cmp r3, #0 */
/* @0x23ae3c bic r1, r0, #-16777216 */
/* @0x23ae40 mov r0, #4 */
/* @0x23ae44 moveq r3, #1 */
/* @0x23ae48 strheq r3, [r4, #12] */
/* @0x23ae4c ldrsh r3, [r4, #14] */
/* @0x23ae50 orr r5, r5, r1 */
/* @0x23ae54 ldr r1, [r11] */
/* @0x23ae58 cmp r3, #0 */
/* @0x23ae5c moveq r3, #1 */
/* @0x23ae60 strheq r3, [r4, #14] */
/* @0x23ae64 add r3, r2, r2, lsl #1 */
/* @0x23ae68 mov r2, #24 */
/* @0x23ae6c vdiv.f32 s16, s16, s15 */
/* @0x23ae70 str r12, [sp] */
/* @0x23ae74 lsl r3, r3, #1 */
/* @0x23ae78 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x23ae7c ldrsh r1, [r4, #10] */
/* @0x23ae80 ldrsh r2, [r4, #8] */
/* @0x23ae84 vldr s11, [sp, #84] */
/* @0x23ae88 vldr s12, [sp, #88] */
/* @0x23ae8c vldr s13, [pc, #568] */
/* @0x23ae90 ldr r12, [sp] */
/* @0x23ae94 mov r3, r0 */
/* @0x23ae98 ldr r0, [r10, #0x28] */
/* @0x23ae9c ldr r10, [r10, #0x24] */
/* @0x23aea0 rsb r0, r1, r0 */
/* @0x23aea4 ldrsh r1, [r4, #12] */
/* @0x23aea8 rsb r10, r2, r10 */
/* @0x23aeac ldrsh r2, [r4, #14] */
/* @0x23aeb0 vmov s17, r0 */
/* @0x23aeb4 vmov s18, r10 */
/* @0x23aeb8 vcvt.f32.s32 s17, s17 */
/* @0x23aebc vmov s14, r1 */
/* @0x23aec0 vmov s15, r2 */
/* @0x23aec4 vcvt.f32.s32 s18, s18 */
/* @0x23aec8 vnmul.f32 s17, s12, s17 */
/* @0x23aecc vnmul.f32 s18, s11, s18 */
/* @0x23aed0 vldr s11, [sp, #92] */
/* @0x23aed4 vabs.f32 s12, s11 */
/* @0x23aed8 vcvt.f32.s32 s14, s14 */
/* @0x23aedc vcvt.f32.s32 s15, s15 */
/* @0x23aee0 vcmpe.f32 s12, s13 */
/* @0x23aee4 vldr s12, [sp, #84] */
/* @0x23aee8 vldr s13, [sp, #88] */
/* @0x23aeec vmov.f32 s20, s18 */
/* @0x23aef0 vmrs APSR_nzcv, fpscr */
/* @0x23aef4 vmov.f32 s19, s17 */
/* @0x23aef8 vmla.f32 s20, s14, s12 */
/* @0x23aefc vmla.f32 s19, s15, s13 */
/* @0x23af00 bpl 0x23b070 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x37c> */
/* @0x23af04 ldr r1, [sp, #0xc] */
/* @0x23af08 mov r2, #0 */
/* @0x23af0c str r9, [sp, #0x8] */
/* @0x23af10 b 0x23af30 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x23c> */
/* @0x23af14 ldr r0, [r12, r2] */
/* @0x23af18 cmp r0, r6 */
/* @0x23af1c beq 0x23af50 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x25c> */
/* @0x23af20 add r2, r2, #4 */
/* @0x23af24 add r1, r1, #8 */
/* @0x23af28 cmp r2, r8 */
/* @0x23af2c beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54> */
/* @0x23af30 ldr r0, [r7, r2] */
/* @0x23af34 cmp r0, #0 */
/* @0x23af38 beq 0x23af48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x254> */
/* @0x23af3c ldr r9, [sp, #0x8] */
/* @0x23af40 tst r0, r9 */
/* @0x23af44 beq 0x23af20 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x22c> */
/* @0x23af48 cmp r6, #0 */
/* @0x23af4c bne 0x23af14 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x220> */
/* @0x23af50 ldrsh r9, [r4] */
/* @0x23af54 vldr s8, [r11, #8] */
/* @0x23af58 vldr s10, [r1] */
/* @0x23af5c vldr s12, [r1, #4] */
/* @0x23af60 vmul.f32 s10, s16, s10 */
/* @0x23af64 str r5, [r3, #0x84] */
/* @0x23af68 vmov s11, r9 */
/* @0x23af6c str r5, [r3, #0x6c] */
/* @0x23af70 str r5, [r3, #0x54] */
/* @0x23af74 add r3, r3, #144 */
/* @0x23af78 str r5, [r3, #-0x54] */
/* @0x23af7c str r5, [r3, #-0x6c] */
/* @0x23af80 str r5, [r3, #-0x84] */
/* @0x23af84 vcvt.f32.s32 s15, s11 */
/* @0x23af88 vmul.f32 s15, s15, s8 */
/* @0x23af8c vstr s15, [r3, #-32] */
/* @0x23af90 vstr s15, [r3, #-128] */
/* @0x23af94 vstr s15, [r3, #-8] */
/* @0x23af98 ldrsh r0, [r4, #2] */
/* @0x23af9c vldr s9, [r11, #12] */
/* @0x23afa0 vmul.f32 s12, s16, s12 */
/* @0x23afa4 vmov s14, r0 */
/* @0x23afa8 vcvt.f32.s32 s13, s14 */
/* @0x23afac vmul.f32 s13, s13, s9 */
/* @0x23afb0 vstr s13, [r3, #-100] */
/* @0x23afb4 vstr s13, [r3, #-124] */
/* @0x23afb8 vstr s13, [r3, #-4] */
/* @0x23afbc ldrsh r10, [r4, #4] */
/* @0x23afc0 vadd.f32 s11, s10, s18 */
/* @0x23afc4 add r10, r9, r10 */
/* @0x23afc8 vmov s14, r10 */
/* @0x23afcc vcvt.f32.s32 s14, s14 */
/* @0x23afd0 vstr s11, [r3, #-144] */
/* @0x23afd4 vstr s11, [r3, #-24] */
/* @0x23afd8 vstr s11, [r3, #-48] */
/* @0x23afdc vmul.f32 s14, s8, s14 */
/* @0x23afe0 vadd.f32 s11, s12, s17 */
/* @0x23afe4 vstr s14, [r3, #-80] */
/* @0x23afe8 vstr s14, [r3, #-56] */
/* @0x23afec vadd.f32 s10, s10, s20 */
/* @0x23aff0 vstr s11, [r3, #-116] */
/* @0x23aff4 vstr s11, [r3, #-140] */
/* @0x23aff8 vstr s11, [r3, #-20] */
/* @0x23affc vadd.f32 s12, s12, s19 */
/* @0x23b000 vstr s10, [r3, #-96] */
/* @0x23b004 vstr s10, [r3, #-72] */
/* @0x23b008 vstr s10, [r3, #-120] */
/* @0x23b00c vstr s12, [r3, #-44] */
/* @0x23b010 vstr s12, [r3, #-92] */
/* @0x23b014 vstr s12, [r3, #-68] */
/* @0x23b018 vstr s14, [r3, #-104] */
/* @0x23b01c ldrsh r10, [r4, #6] */
/* @0x23b020 add r10, r0, r10 */
/* @0x23b024 vmov s15, r10 */
/* @0x23b028 vcvt.f32.s32 s15, s15 */
/* @0x23b02c vmul.f32 s15, s9, s15 */
/* @0x23b030 vstr s15, [r3, #-28] */
/* @0x23b034 vstr s15, [r3, #-76] */
/* @0x23b038 vstr s15, [r3, #-52] */
/* @0x23b03c b 0x23af20 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x22c> */
/* @0x23b040 add r0, r7, r8 */
/* @0x23b044 mov r3, r7 */
/* @0x23b048 mov r2, r6 */
/* @0x23b04c ldr r1, [r3], #4 */
/* @0x23b050 cmp r1, #0 */
/* @0x23b054 beq 0x23b060 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x36c> */
/* @0x23b058 tst r1, r9 */
/* @0x23b05c beq 0x23b064 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x370> */
/* @0x23b060 add r2, r2, #1 */
/* @0x23b064 cmp r3, r0 */
/* @0x23b068 bne 0x23b04c <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x358> */
/* @0x23b06c b 0x23adf8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x104> */
/* @0x23b070 ldr r0, [sp, #0x5c] */
/* @0x23b074 str r3, [sp, #0x4] */
/* @0x23b078 str r12, [sp] */
/* @0x23b07c bl 0xb6580 <sinf@plt> */
/* @0x23b080 vmov s21, r0 */
/* @0x23b084 ldr r0, [sp, #0x5c] */
/* @0x23b088 bl 0xb658c <cosf@plt> */
/* @0x23b08c ldr r1, [sp, #0xc] */
/* @0x23b090 vmul.f32 s2, s18, s21 */
/* @0x23b094 mov r2, #0 */
/* @0x23b098 ldr r3, [sp, #0x4] */
/* @0x23b09c ldr r12, [sp] */
/* @0x23b0a0 str r9, [sp, #0x8] */
/* @0x23b0a4 vmul.f32 s3, s20, s21 */
/* @0x23b0a8 vmul.f32 s4, s17, s21 */
/* @0x23b0ac vmov s15, r0 */
/* @0x23b0b0 vmul.f32 s5, s19, s21 */
/* @0x23b0b4 vmul.f32 s18, s18, s15 */
/* @0x23b0b8 vmul.f32 s20, s20, s15 */
/* @0x23b0bc vmul.f32 s17, s17, s15 */
/* @0x23b0c0 vmul.f32 s19, s19, s15 */
/* @0x23b0c4 b 0x23b0f0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3fc> */
/* @0x23b0c8 cmnmi pc, #0 */
/* @0x23b0cc blo 0xfe2ffa90 <b2_toiTime+0xfffffffffdba65ec> */
/* @0x23b0d0 andseq r2, r11, r0, asr #23 */
/* @0x23b0d4 ldr r0, [r12, r2] */
/* @0x23b0d8 cmp r0, r6 */
/* @0x23b0dc beq 0x23b110 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x41c> */
/* @0x23b0e0 add r2, r2, #4 */
/* @0x23b0e4 add r1, r1, #8 */
/* @0x23b0e8 cmp r2, r8 */
/* @0x23b0ec beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54> */
/* @0x23b0f0 ldr r0, [r7, r2] */
/* @0x23b0f4 cmp r0, #0 */
/* @0x23b0f8 beq 0x23b108 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x414> */
/* @0x23b0fc ldr r9, [sp, #0x8] */
/* @0x23b100 tst r0, r9 */
/* @0x23b104 beq 0x23b0e0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3ec> */
/* @0x23b108 cmp r6, #0 */
/* @0x23b10c bne 0x23b0d4 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3e0> */
/* @0x23b110 ldrsh r9, [r4] */
/* @0x23b114 vldr s11, [r11, #8] */
/* @0x23b118 vldr s7, [r1] */
/* @0x23b11c vldr s10, [r1, #4] */
/* @0x23b120 vmul.f32 s7, s16, s7 */
/* @0x23b124 str r5, [r3, #0x84] */
/* @0x23b128 vmov s12, r9 */
/* @0x23b12c str r5, [r3, #0x6c] */
/* @0x23b130 str r5, [r3, #0x54] */
/* @0x23b134 add r3, r3, #144 */
/* @0x23b138 str r5, [r3, #-0x54] */
/* @0x23b13c str r5, [r3, #-0x6c] */
/* @0x23b140 str r5, [r3, #-0x84] */
/* @0x23b144 vcvt.f32.s32 s15, s12 */
/* @0x23b148 vmul.f32 s15, s15, s11 */
/* @0x23b14c vstr s15, [r3, #-32] */
/* @0x23b150 vstr s15, [r3, #-128] */
/* @0x23b154 vstr s15, [r3, #-8] */
/* @0x23b158 ldrsh r0, [r4, #2] */
/* @0x23b15c vldr s12, [r11, #12] */
/* @0x23b160 vmul.f32 s10, s16, s10 */
/* @0x23b164 vmov s14, r0 */
/* @0x23b168 vcvt.f32.s32 s13, s14 */
/* @0x23b16c vmul.f32 s13, s13, s12 */
/* @0x23b170 vadd.f32 s6, s7, s18 */
/* @0x23b174 vstr s13, [r3, #-100] */
/* @0x23b178 vstr s13, [r3, #-124] */
/* @0x23b17c vstr s13, [r3, #-4] */
/* @0x23b180 ldrsh r10, [r4, #4] */
/* @0x23b184 add r10, r9, r10 */
/* @0x23b188 vmov s14, r10 */
/* @0x23b18c vadd.f32 s7, s7, s20 */
/* @0x23b190 vadd.f32 s9, s6, s4 */
/* @0x23b194 vsub.f32 s8, s10, s2 */
/* @0x23b198 vstr s9, [r3, #-144] */
/* @0x23b19c vstr s9, [r3, #-24] */
/* @0x23b1a0 vadd.f32 s15, s7, s4 */
/* @0x23b1a4 vsub.f32 s10, s10, s3 */
/* @0x23b1a8 vstr s15, [r3, #-120] */
/* @0x23b1ac vcvt.f32.s32 s14, s14 */
/* @0x23b1b0 vmul.f32 s14, s11, s14 */
/* @0x23b1b4 vadd.f32 s9, s8, s17 */
/* @0x23b1b8 vstr s14, [r3, #-80] */
/* @0x23b1bc vstr s14, [r3, #-56] */
/* @0x23b1c0 vadd.f32 s15, s10, s17 */
/* @0x23b1c4 vstr s9, [r3, #-140] */
/* @0x23b1c8 vstr s9, [r3, #-20] */
/* @0x23b1cc vadd.f32 s7, s5, s7 */
/* @0x23b1d0 vstr s15, [r3, #-116] */
/* @0x23b1d4 vadd.f32 s10, s19, s10 */
/* @0x23b1d8 vstr s7, [r3, #-96] */
/* @0x23b1dc vstr s7, [r3, #-72] */
/* @0x23b1e0 vadd.f32 s6, s5, s6 */
/* @0x23b1e4 vstr s10, [r3, #-92] */
/* @0x23b1e8 vstr s10, [r3, #-68] */
/* @0x23b1ec vadd.f32 s8, s19, s8 */
/* @0x23b1f0 vstr s6, [r3, #-48] */
/* @0x23b1f4 vstr s8, [r3, #-44] */
/* @0x23b1f8 vstr s14, [r3, #-104] */
/* @0x23b1fc ldrsh r10, [r4, #6] */
/* @0x23b200 add r10, r0, r10 */
/* @0x23b204 vmov s15, r10 */
/* @0x23b208 vcvt.f32.s32 s15, s15 */
/* @0x23b20c vmul.f32 s15, s12, s15 */
/* @0x23b210 vstr s15, [r3, #-28] */
/* @0x23b214 vstr s15, [r3, #-76] */
/* @0x23b218 vstr s15, [r3, #-52] */
/* @0x23b21c b 0x23b0e0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3ec> */

/* ── FUNC 0x23b220 · Hash<CPhysicsJoint>::~Hash() · size=136 · insn=34 */
/* @0x23b220 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x23b224 mov r6, r0 */
/* @0x23b228 ldm r0, {r0, r8} */
/* @0x23b22c cmp r8, #0 */
/* @0x23b230 lslge r7, r8, #3 */
/* @0x23b234 movge r9, #0 */
/* @0x23b238 blt 0x23b29c <_ZN4HashI13CPhysicsJointED2Ev+0x7c> */
/* @0x23b23c ldr r4, [r0, r7] */
/* @0x23b240 add r3, r0, r7 */
/* @0x23b244 str r9, [r0, r7] */
/* @0x23b248 cmp r4, #0 */
/* @0x23b24c str r9, [r3, #0x4] */
/* @0x23b250 beq 0x23b28c <_ZN4HashI13CPhysicsJointED2Ev+0x6c> */
/* @0x23b254 ldr r0, [r4, #0xc] */
/* @0x23b258 ldr r5, [r4, #0x4] */
/* @0x23b25c cmp r0, #0 */
/* @0x23b260 beq 0x23b268 <_ZN4HashI13CPhysicsJointED2Ev+0x48> */
/* @0x23b264 bl 0x27d1d0 <_ZdlPv> */
/* @0x23b268 mov r0, r4 */
/* @0x23b26c mov r4, r5 */
/* @0x23b270 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23b274 ldr r3, [r6, #0x8] */
/* @0x23b278 cmp r5, #0 */
/* @0x23b27c sub r3, r3, #1 */
/* @0x23b280 str r3, [r6, #0x8] */
/* @0x23b284 bne 0x23b254 <_ZN4HashI13CPhysicsJointED2Ev+0x34> */
/* @0x23b288 ldr r0, [r6] */
/* @0x23b28c sub r8, r8, #1 */
/* @0x23b290 sub r7, r7, #8 */
/* @0x23b294 cmn r8, #1 */
/* @0x23b298 bne 0x23b23c <_ZN4HashI13CPhysicsJointED2Ev+0x1c> */
/* @0x23b29c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23b2a0 mov r0, r6 */
/* @0x23b2a4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x23b220 · Hash<CPhysicsJoint>::~Hash() · alias of the symbol above · insn=0 */

/* ── FUNC 0x23b2a8 · CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&) · size=204 · insn=51 */
/* @0x23b2a8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x23b2ac mov r7, r0 */
/* @0x23b2b0 ldr r0, [r0, #0x10] */
/* @0x23b2b4 bl 0x2c90f8 <_ZN7b2World11CreateJointEPK10b2JointDef> */
/* @0x23b2b8 ldr r3, [pc, #0xa8] */
/* @0x23b2bc ldr r4, [pc, #0xa8] */
/* @0x23b2c0 ldr r3, [pc, r3] */
/* @0x23b2c4 ldr r6, [r3] */
/* @0x23b2c8 add r6, r6, #1 */
/* @0x23b2cc str r6, [r3] */
/* @0x23b2d0 mov r9, r0 */
/* @0x23b2d4 mov r0, #28 */
/* @0x23b2d8 bl 0x27c524 <_Znwj> */
/* @0x23b2dc ldr r4, [pc, r4] */
/* @0x23b2e0 ldr r1, [pc, #0x88] */
/* @0x23b2e4 movw r2, #0x132 */
/* @0x23b2e8 ldr r8, [r4, #0x4] */
/* @0x23b2ec mov r3, #1 */
/* @0x23b2f0 add r1, pc, r1 */
/* @0x23b2f4 and r8, r6, r8 */
/* @0x23b2f8 mov r5, r0 */
/* @0x23b2fc str r7, [r0] */
/* @0x23b300 str r6, [r0, #0x8] */
/* @0x23b304 mov r0, #16 */
/* @0x23b308 str r9, [r5, #0x4] */
/* @0x23b30c ldr r7, [r4] */
/* @0x23b310 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x23b314 add r2, r7, r8, lsl #3 */
/* @0x23b318 ldr r1, [r7, r8, lsl #3] */
/* @0x23b31c cmp r1, #0 */
/* @0x23b320 ldrne r1, [r2, #0x4] */
/* @0x23b324 mov r3, r0 */
/* @0x23b328 str r6, [r0, #0x8] */
/* @0x23b32c str r5, [r0, #0xc] */
/* @0x23b330 movne r0, #0 */
/* @0x23b334 strne r1, [r3] */
/* @0x23b338 strne r3, [r1, #0x4] */
/* @0x23b33c strne r3, [r2, #0x4] */
/* @0x23b340 strne r0, [r3, #0x4] */
/* @0x23b344 ldr r3, [r4, #0x8] */
/* @0x23b348 streq r0, [r2, #0x4] */
/* @0x23b34c add r3, r3, #1 */
/* @0x23b350 streq r0, [r7, r8, lsl #3] */
/* @0x23b354 streq r1, [r0, #0x4] */
/* @0x23b358 streq r1, [r0] */
/* @0x23b35c mov r0, r5 */
/* @0x23b360 str r3, [r4, #0x8] */
/* @0x23b364 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23b368 andseq r6, r11, r0, lsr #4 */
/* @0x23b36c andseq r6, r11, r8, lsl #4 */
/* @0x23b370 ldrheq r1, [r1], -r12 */

/* ── FUNC 0x23b374 · CPhysicsJointFactory::FindJoint(unsigned int) · size=80 · insn=20 */
/* @0x23b374 ldr r3, [pc, #0x44] */
/* @0x23b378 ldr r3, [pc, r3] */
/* @0x23b37c ldr r2, [r3, #0x4] */
/* @0x23b380 ldr r3, [r3] */
/* @0x23b384 and r2, r0, r2 */
/* @0x23b388 ldr r3, [r3, r2, lsl #3] */
/* @0x23b38c cmp r3, #0 */
/* @0x23b390 bne 0x23b3a4 <_ZN20CPhysicsJointFactory9FindJointEj+0x30> */
/* @0x23b394 b 0x23b3b8 <_ZN20CPhysicsJointFactory9FindJointEj+0x44> */
/* @0x23b398 ldr r3, [r3, #0x4] */
/* @0x23b39c cmp r3, #0 */
/* @0x23b3a0 beq 0x23b3b8 <_ZN20CPhysicsJointFactory9FindJointEj+0x44> */
/* @0x23b3a4 ldr r2, [r3, #0x8] */
/* @0x23b3a8 cmp r0, r2 */
/* @0x23b3ac bne 0x23b398 <_ZN20CPhysicsJointFactory9FindJointEj+0x24> */
/* @0x23b3b0 ldr r0, [r3, #0xc] */
/* @0x23b3b4 bx lr */
/* @0x23b3b8 mov r0, r3 */
/* @0x23b3bc bx lr */
/* @0x23b3c0 andseq r6, r11, r12, ror #2 */

/* ── FUNC 0x23b3c4 · CPhysicsJointFactory::DestroyJoint(CPhysicsWorld*, unsigned int) · size=184 · insn=46 */
/* @0x23b3c4 push {r4, r5, r6, lr} */
/* @0x23b3c8 mov r6, r0 */
/* @0x23b3cc mov r0, r1 */
/* @0x23b3d0 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj> */
/* @0x23b3d4 subs r5, r0, #0 */
/* @0x23b3d8 beq 0x23b470 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0xac> */
/* @0x23b3dc ldr r4, [pc, #0x94] */
/* @0x23b3e0 ldr r1, [r5, #0x8] */
/* @0x23b3e4 ldr r4, [pc, r4] */
/* @0x23b3e8 ldm r4, {r12, lr} */
/* @0x23b3ec and lr, r1, lr */
/* @0x23b3f0 ldr r3, [r12, lr, lsl #3] */
/* @0x23b3f4 add r0, r12, lr, lsl #3 */
/* @0x23b3f8 cmp r3, #0 */
/* @0x23b3fc bne 0x23b410 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x4c> */
/* @0x23b400 b 0x23b454 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x90> */
/* @0x23b404 ldr r3, [r3, #0x4] */
/* @0x23b408 cmp r3, #0 */
/* @0x23b40c beq 0x23b454 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x90> */
/* @0x23b410 ldr r2, [r3, #0x8] */
/* @0x23b414 cmp r1, r2 */
/* @0x23b418 bne 0x23b404 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj+0x40> */
/* @0x23b41c ldr r2, [r3] */
/* @0x23b420 ldr r1, [r3, #0x4] */
/* @0x23b424 cmp r2, #0 */
/* @0x23b428 strne r1, [r2, #0x4] */
/* @0x23b42c ldrne r1, [r3, #0x4] */
/* @0x23b430 streq r1, [r12, lr, lsl #3] */
/* @0x23b434 cmp r1, #0 */
/* @0x23b438 streq r2, [r0, #0x4] */
/* @0x23b43c strne r2, [r1] */
/* @0x23b440 mov r0, r3 */
/* @0x23b444 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23b448 ldr r3, [r4, #0x8] */
/* @0x23b44c sub r3, r3, #1 */
/* @0x23b450 str r3, [r4, #0x8] */
/* @0x23b454 ldr r0, [r6, #0x10] */
/* @0x23b458 ldr r1, [r5, #0x4] */
/* @0x23b45c bl 0x2c923c <_ZN7b2World12DestroyJointEP7b2Joint> */
/* @0x23b460 mov r0, r5 */
/* @0x23b464 bl 0x27d1d0 <_ZdlPv> */
/* @0x23b468 mov r0, #1 */
/* @0x23b46c pop {r4, r5, r6, pc} */
/* @0x23b470 mov r0, r5 */
/* @0x23b474 pop {r4, r5, r6, pc} */
/* @0x23b478 andseq r6, r11, r0, lsl #2 */

/* ── FUNC 0x23b47c · CPhysicsJointFactory::FindJoint(b2Joint*) · size=184 · insn=46 */
/* @0x23b47c ldr r3, [pc, #0xac] */
/* @0x23b480 mov r2, #0 */
/* @0x23b484 push {r4, r5} */
/* @0x23b488 ldr r3, [pc, r3] */
/* @0x23b48c ldr r5, [r3] */
/* @0x23b490 ldr r4, [r3, #0x4] */
/* @0x23b494 b 0x23b4a0 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x24> */
/* @0x23b498 cmp r4, r2 */
/* @0x23b49c blt 0x23b528 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0xac> */
/* @0x23b4a0 mov r12, r2 */
/* @0x23b4a4 add r2, r2, #1 */
/* @0x23b4a8 ldr r3, [r5, r12, lsl #3] */
/* @0x23b4ac cmp r3, #0 */
/* @0x23b4b0 beq 0x23b498 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x1c> */
/* @0x23b4b4 cmp r3, #0 */
/* @0x23b4b8 beq 0x23b518 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x9c> */
/* @0x23b4bc ldr r2, [r3, #0xc] */
/* @0x23b4c0 cmp r2, #0 */
/* @0x23b4c4 beq 0x23b51c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0xa0> */
/* @0x23b4c8 ldr r1, [r2, #0x4] */
/* @0x23b4cc cmp r1, r0 */
/* @0x23b4d0 beq 0x23b51c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0xa0> */
/* @0x23b4d4 ldr r3, [r3, #0x4] */
/* @0x23b4d8 cmp r3, #0 */
/* @0x23b4dc bne 0x23b4b4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x38> */
/* @0x23b4e0 add r2, r12, #1 */
/* @0x23b4e4 cmp r4, r2 */
/* @0x23b4e8 blt 0x23b518 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x9c> */
/* @0x23b4ec add r1, r5, r12, lsl #3 */
/* @0x23b4f0 b 0x23b4fc <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x80> */
/* @0x23b4f4 cmp r4, r2 */
/* @0x23b4f8 blt 0x23b518 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x9c> */
/* @0x23b4fc ldr r3, [r1, #0x8] */
/* @0x23b500 mov r12, r2 */
/* @0x23b504 add r1, r1, #8 */
/* @0x23b508 add r2, r2, #1 */
/* @0x23b50c cmp r3, #0 */
/* @0x23b510 beq 0x23b4f4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x78> */
/* @0x23b514 b 0x23b4b4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x38> */
/* @0x23b518 mov r2, #0 */
/* @0x23b51c mov r0, r2 */
/* @0x23b520 pop {r4, r5} */
/* @0x23b524 bx lr */
/* @0x23b528 mvn r12, #0 */
/* @0x23b52c b 0x23b4b4 <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint+0x38> */
/* @0x23b530 andseq r6, r11, r12, asr r0 */

/* ── FUNC 0x23b534 · CPhysicsJoint::EnableMotor(bool) · size=220 · insn=55 */
/* @0x23b534 ldr r0, [r0, #0x4] */
/* @0x23b538 cmp r0, #0 */
/* @0x23b53c bxeq lr */
/* @0x23b540 ldr r3, [r0, #0x4] */
/* @0x23b544 cmp r3, #2 */
/* @0x23b548 beq 0x23b5d4 <_ZN13CPhysicsJoint11EnableMotorEb+0xa0> */
/* @0x23b54c cmp r3, #7 */
/* @0x23b550 beq 0x23b598 <_ZN13CPhysicsJoint11EnableMotorEb+0x64> */
/* @0x23b554 cmp r3, #1 */
/* @0x23b558 bxne lr */
/* @0x23b55c ldr r3, [r0, #0x30] */
/* @0x23b560 ldrh r2, [r3, #4] */
/* @0x23b564 tst r2, #2 */
/* @0x23b568 orreq r2, r2, #2 */
/* @0x23b56c strheq r2, [r3, #4] */
/* @0x23b570 moveq r12, #0 */
/* @0x23b574 streq r12, [r3, #0xa0] */
/* @0x23b578 ldr r3, [r0, #0x34] */
/* @0x23b57c ldrh r2, [r3, #4] */
/* @0x23b580 tst r2, #2 */
/* @0x23b584 orreq r2, r2, #2 */
/* @0x23b588 strheq r2, [r3, #4] */
/* @0x23b58c moveq r12, #0 */
/* @0x23b590 streq r12, [r3, #0xa0] */
/* @0x23b594 b 0x2d214c <_ZN15b2RevoluteJoint11EnableMotorEb> */
/* @0x23b598 ldr r3, [r0, #0x30] */
/* @0x23b59c ldrh r2, [r3, #4] */
/* @0x23b5a0 tst r2, #2 */
/* @0x23b5a4 orreq r2, r2, #2 */
/* @0x23b5a8 strheq r2, [r3, #4] */
/* @0x23b5ac moveq r12, #0 */
/* @0x23b5b0 streq r12, [r3, #0xa0] */
/* @0x23b5b4 ldr r3, [r0, #0x34] */
/* @0x23b5b8 ldrh r2, [r3, #4] */
/* @0x23b5bc tst r2, #2 */
/* @0x23b5c0 orreq r2, r2, #2 */
/* @0x23b5c4 strheq r2, [r3, #4] */
/* @0x23b5c8 moveq r12, #0 */
/* @0x23b5cc streq r12, [r3, #0xa0] */
/* @0x23b5d0 b 0x2d43a4 <_ZN12b2WheelJoint11EnableMotorEb> */
/* @0x23b5d4 ldr r3, [r0, #0x30] */
/* @0x23b5d8 ldrh r2, [r3, #4] */
/* @0x23b5dc tst r2, #2 */
/* @0x23b5e0 orreq r2, r2, #2 */
/* @0x23b5e4 strheq r2, [r3, #4] */
/* @0x23b5e8 moveq r12, #0 */
/* @0x23b5ec streq r12, [r3, #0xa0] */
/* @0x23b5f0 ldr r3, [r0, #0x34] */
/* @0x23b5f4 ldrh r2, [r3, #4] */
/* @0x23b5f8 tst r2, #2 */
/* @0x23b5fc orreq r2, r2, #2 */
/* @0x23b600 strheq r2, [r3, #4] */
/* @0x23b604 moveq r12, #0 */
/* @0x23b608 streq r12, [r3, #0xa0] */
/* @0x23b60c b 0x2d043c <_ZN16b2PrismaticJoint11EnableMotorEb> */

/* ── FUNC 0x23b610 · CPhysicsJoint::GetValue(int) · size=1284 · insn=321 */
/* @0x23b610 push {r4, lr} */
/* @0x23b614 sub sp, sp, #8 */
/* @0x23b618 ldr r4, [pc, #0x488] */
/* @0x23b61c add r4, pc, r4 */
/* @0x23b620 cmp r1, #24 */
/* @0x23b624 addls pc, pc, r1, lsl #2 */
/* @0x23b628 b 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b62c b 0x23ba7c <_ZN13CPhysicsJoint8GetValueEi+0x46c> */
/* @0x23b630 b 0x23ba68 <_ZN13CPhysicsJoint8GetValueEi+0x458> */
/* @0x23b634 b 0x23b98c <_ZN13CPhysicsJoint8GetValueEi+0x37c> */
/* @0x23b638 b 0x23b950 <_ZN13CPhysicsJoint8GetValueEi+0x340> */
/* @0x23b63c b 0x23b9ec <_ZN13CPhysicsJoint8GetValueEi+0x3dc> */
/* @0x23b640 b 0x23b9ac <_ZN13CPhysicsJoint8GetValueEi+0x39c> */
/* @0x23b644 b 0x23ba2c <_ZN13CPhysicsJoint8GetValueEi+0x41c> */
/* @0x23b648 b 0x23b928 <_ZN13CPhysicsJoint8GetValueEi+0x318> */
/* @0x23b64c b 0x23b690 <_ZN13CPhysicsJoint8GetValueEi+0x80> */
/* @0x23b650 b 0x23b8c4 <_ZN13CPhysicsJoint8GetValueEi+0x2b4> */
/* @0x23b654 b 0x23b904 <_ZN13CPhysicsJoint8GetValueEi+0x2f4> */
/* @0x23b658 b 0x23b8a4 <_ZN13CPhysicsJoint8GetValueEi+0x294> */
/* @0x23b65c b 0x23b880 <_ZN13CPhysicsJoint8GetValueEi+0x270> */
/* @0x23b660 b 0x23b848 <_ZN13CPhysicsJoint8GetValueEi+0x238> */
/* @0x23b664 b 0x23b830 <_ZN13CPhysicsJoint8GetValueEi+0x220> */
/* @0x23b668 b 0x23b810 <_ZN13CPhysicsJoint8GetValueEi+0x200> */
/* @0x23b66c b 0x23b7dc <_ZN13CPhysicsJoint8GetValueEi+0x1cc> */
/* @0x23b670 b 0x23b7b4 <_ZN13CPhysicsJoint8GetValueEi+0x1a4> */
/* @0x23b674 b 0x23b78c <_ZN13CPhysicsJoint8GetValueEi+0x17c> */
/* @0x23b678 b 0x23b774 <_ZN13CPhysicsJoint8GetValueEi+0x164> */
/* @0x23b67c b 0x23b748 <_ZN13CPhysicsJoint8GetValueEi+0x138> */
/* @0x23b680 b 0x23b728 <_ZN13CPhysicsJoint8GetValueEi+0x118> */
/* @0x23b684 b 0x23b6f4 <_ZN13CPhysicsJoint8GetValueEi+0xe4> */
/* @0x23b688 b 0x23b6d8 <_ZN13CPhysicsJoint8GetValueEi+0xc8> */
/* @0x23b68c b 0x23b6bc <_ZN13CPhysicsJoint8GetValueEi+0xac> */
/* @0x23b690 ldr r0, [r0, #0x4] */
/* @0x23b694 ldr r3, [r0, #0x4] */
/* @0x23b698 cmp r3, #1 */
/* @0x23b69c beq 0x23bacc <_ZN13CPhysicsJoint8GetValueEi+0x4bc> */
/* @0x23b6a0 cmp r3, #8 */
/* @0x23b6a4 vldreq s15, [r0, #96] */
/* @0x23b6a8 beq 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b6ac vldr s15, [pc, #1000] */
/* @0x23b6b0 vmov r0, s15 */
/* @0x23b6b4 add sp, sp, #8 */
/* @0x23b6b8 pop {r4, pc} */
/* @0x23b6bc ldr r0, [r0, #0x4] */
/* @0x23b6c0 ldr r3, [r0, #0x4] */
/* @0x23b6c4 cmp r3, #9 */
/* @0x23b6c8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b6cc add sp, sp, #8 */
/* @0x23b6d0 pop {r4, lr} */
/* @0x23b6d4 b 0x2cdb18 <_ZNK15b2FrictionJoint11GetMaxForceEv> */
/* @0x23b6d8 ldr r0, [r0, #0x4] */
/* @0x23b6dc ldr r3, [r0, #0x4] */
/* @0x23b6e0 cmp r3, #9 */
/* @0x23b6e4 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b6e8 add sp, sp, #8 */
/* @0x23b6ec pop {r4, lr} */
/* @0x23b6f0 b 0x2cdbb8 <_ZNK15b2FrictionJoint12GetMaxTorqueEv> */
/* @0x23b6f4 ldr r0, [r0, #0x4] */
/* @0x23b6f8 ldr r3, [r0, #0x4] */
/* @0x23b6fc cmp r3, #10 */
/* @0x23b700 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b704 bl 0x2d2bb4 <_ZNK11b2RopeJoint12GetMaxLengthEv> */
/* @0x23b708 ldr r3, [pc, #0x39c] */
/* @0x23b70c vmov s13, r0 */
/* @0x23b710 ldr r3, [r4, r3] */
/* @0x23b714 ldr r3, [r3] */
/* @0x23b718 ldr r3, [r3, #0xb4] */
/* @0x23b71c vldr s15, [r3, #96] */
/* @0x23b720 vdiv.f32 s15, s13, s15 */
/* @0x23b724 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b728 ldr r0, [r0, #0x4] */
/* @0x23b72c ldr r3, [r0, #0x4] */
/* @0x23b730 cmp r3, #1 */
/* @0x23b734 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b738 bl 0x2d2220 <_ZNK15b2RevoluteJoint14IsLimitEnabledEv> */
/* @0x23b73c vmov s14, r0 */
/* @0x23b740 vcvt.f32.u32 s15, s14 */
/* @0x23b744 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b748 ldr r0, [r0, #0x4] */
/* @0x23b74c ldr r3, [r0, #0x4] */
/* @0x23b750 cmp r3, #1 */
/* @0x23b754 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b758 bl 0x2d2284 <_ZNK15b2RevoluteJoint13GetUpperLimitEv> */
/* @0x23b75c vmov s13, r0 */
/* @0x23b760 vldr s14, [pc, #824] */
/* @0x23b764 vldr s15, [pc, #824] */
/* @0x23b768 vmul.f32 s14, s13, s14 */
/* @0x23b76c vdiv.f32 s15, s14, s15 */
/* @0x23b770 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b774 ldr r0, [r0, #0x4] */
/* @0x23b778 ldr r3, [r0, #0x4] */
/* @0x23b77c cmp r3, #1 */
/* @0x23b780 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b784 bl 0x2d227c <_ZNK15b2RevoluteJoint13GetLowerLimitEv> */
/* @0x23b788 b 0x23b75c <_ZN13CPhysicsJoint8GetValueEi+0x14c> */
/* @0x23b78c ldr r2, [r0, #0x4] */
/* @0x23b790 ldr r3, [r2, #0x4] */
/* @0x23b794 cmp r3, #3 */
/* @0x23b798 beq 0x23b7ac <_ZN13CPhysicsJoint8GetValueEi+0x19c> */
/* @0x23b79c cmp r3, #7 */
/* @0x23b7a0 beq 0x23b7ac <_ZN13CPhysicsJoint8GetValueEi+0x19c> */
/* @0x23b7a4 cmp r3, #8 */
/* @0x23b7a8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b7ac vldr s15, [r2, #68] */
/* @0x23b7b0 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b7b4 ldr r2, [r0, #0x4] */
/* @0x23b7b8 ldr r3, [r2, #0x4] */
/* @0x23b7bc cmp r3, #3 */
/* @0x23b7c0 beq 0x23b7d4 <_ZN13CPhysicsJoint8GetValueEi+0x1c4> */
/* @0x23b7c4 cmp r3, #7 */
/* @0x23b7c8 beq 0x23b7d4 <_ZN13CPhysicsJoint8GetValueEi+0x1c4> */
/* @0x23b7cc cmp r3, #8 */
/* @0x23b7d0 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b7d4 vldr s15, [r2, #72] */
/* @0x23b7d8 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b7dc ldr r0, [r0, #0x4] */
/* @0x23b7e0 ldr r3, [r0, #0x4] */
/* @0x23b7e4 cmp r3, #4 */
/* @0x23b7e8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b7ec bl 0x2d118c <_ZNK13b2PulleyJoint10GetLengthBEv> */
/* @0x23b7f0 ldr r3, [pc, #0x2b4] */
/* @0x23b7f4 vmov s14, r0 */
/* @0x23b7f8 ldr r3, [r4, r3] */
/* @0x23b7fc ldr r3, [r3] */
/* @0x23b800 ldr r3, [r3, #0xb4] */
/* @0x23b804 vldr s15, [r3, #96] */
/* @0x23b808 vdiv.f32 s15, s14, s15 */
/* @0x23b80c b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b810 ldr r0, [r0, #0x4] */
/* @0x23b814 ldr r3, [r0, #0x4] */
/* @0x23b818 cmp r3, #3 */
/* @0x23b81c beq 0x23bab0 <_ZN13CPhysicsJoint8GetValueEi+0x4a0> */
/* @0x23b820 cmp r3, #4 */
/* @0x23b824 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b828 bl 0x2d1184 <_ZNK13b2PulleyJoint10GetLengthAEv> */
/* @0x23b82c b 0x23b708 <_ZN13CPhysicsJoint8GetValueEi+0xf8> */
/* @0x23b830 ldr r3, [r0, #0x4] */
/* @0x23b834 ldr r2, [r3, #0x4] */
/* @0x23b838 cmp r2, #2 */
/* @0x23b83c vldreq s15, [r3, #128] */
/* @0x23b840 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b844 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b848 ldr r3, [r0, #0x4] */
/* @0x23b84c ldr r2, [r3, #0x4] */
/* @0x23b850 cmp r2, #2 */
/* @0x23b854 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b858 vmov.f32 s14, #1.000000e+00 */
/* @0x23b85c ldr r2, [r0] */
/* @0x23b860 vldr s15, [r2, #88] */
/* @0x23b864 mov r0, r3 */
/* @0x23b868 vcvt.f32.s32 s15, s15 */
/* @0x23b86c vdiv.f32 s14, s14, s15 */
/* @0x23b870 vmov r1, s14 */
/* @0x23b874 add sp, sp, #8 */
/* @0x23b878 pop {r4, lr} */
/* @0x23b87c b 0x2d04fc <_ZNK16b2PrismaticJoint13GetMotorForceEf> */
/* @0x23b880 ldr r0, [r0, #0x4] */
/* @0x23b884 ldr r3, [r0, #0x4] */
/* @0x23b888 cmp r3, #2 */
/* @0x23b88c beq 0x23bae0 <_ZN13CPhysicsJoint8GetValueEi+0x4d0> */
/* @0x23b890 cmp r3, #7 */
/* @0x23b894 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b898 add sp, sp, #8 */
/* @0x23b89c pop {r4, lr} */
/* @0x23b8a0 b 0x2d4380 <_ZNK12b2WheelJoint13GetJointSpeedEv> */
/* @0x23b8a4 ldr r0, [r0, #0x4] */
/* @0x23b8a8 ldr r3, [r0, #0x4] */
/* @0x23b8ac cmp r3, #2 */
/* @0x23b8b0 beq 0x23bad8 <_ZN13CPhysicsJoint8GetValueEi+0x4c8> */
/* @0x23b8b4 cmp r3, #7 */
/* @0x23b8b8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b8bc bl 0x2d42e0 <_ZNK12b2WheelJoint19GetJointTranslationEv> */
/* @0x23b8c0 b 0x23b7f0 <_ZN13CPhysicsJoint8GetValueEi+0x1e0> */
/* @0x23b8c4 ldr r2, [r0, #0x4] */
/* @0x23b8c8 ldr r3, [r2, #0x4] */
/* @0x23b8cc cmp r3, #1 */
/* @0x23b8d0 beq 0x23baec <_ZN13CPhysicsJoint8GetValueEi+0x4dc> */
/* @0x23b8d4 cmp r3, #7 */
/* @0x23b8d8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b8dc vmov.f32 s14, #1.000000e+00 */
/* @0x23b8e0 ldr r3, [r0] */
/* @0x23b8e4 vldr s15, [r3, #88] */
/* @0x23b8e8 mov r0, r2 */
/* @0x23b8ec vcvt.f32.s32 s15, s15 */
/* @0x23b8f0 vdiv.f32 s14, s14, s15 */
/* @0x23b8f4 vmov r1, s14 */
/* @0x23b8f8 add sp, sp, #8 */
/* @0x23b8fc pop {r4, lr} */
/* @0x23b900 b 0x2d4464 <_ZNK12b2WheelJoint14GetMotorTorqueEf> */
/* @0x23b904 ldr r2, [r0, #0x4] */
/* @0x23b908 ldr r3, [r2, #0x4] */
/* @0x23b90c cmp r3, #1 */
/* @0x23b910 vldreq s15, [r2, #104] */
/* @0x23b914 beq 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b918 cmp r3, #7 */
/* @0x23b91c vldreq s15, [r2, #120] */
/* @0x23b920 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b924 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b928 ldr r2, [r0, #0x4] */
/* @0x23b92c ldr r3, [r2, #0x4] */
/* @0x23b930 cmp r3, #2 */
/* @0x23b934 beq 0x23bac4 <_ZN13CPhysicsJoint8GetValueEi+0x4b4> */
/* @0x23b938 cmp r3, #7 */
/* @0x23b93c beq 0x23babc <_ZN13CPhysicsJoint8GetValueEi+0x4ac> */
/* @0x23b940 cmp r3, #1 */
/* @0x23b944 vldreq s15, [r2, #108] */
/* @0x23b948 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c> */
/* @0x23b94c b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b950 ldr r1, [r0, #0x4] */
/* @0x23b954 mov r0, sp */
/* @0x23b958 ldr r3, [r1] */
/* @0x23b95c ldr r3, [r3, #0x4] */
/* @0x23b960 blx r3 */
/* @0x23b964 ldr r3, [pc, #0x140] */
/* @0x23b968 vldr s14, [sp, #4] */
/* @0x23b96c ldr r3, [r4, r3] */
/* @0x23b970 ldr r3, [r3] */
/* @0x23b974 ldr r3, [r3, #0xb4] */
/* @0x23b978 vldr s15, [r3, #96] */
/* @0x23b97c vdiv.f32 s15, s14, s15 */
/* @0x23b980 vmov r0, s15 */
/* @0x23b984 add sp, sp, #8 */
/* @0x23b988 pop {r4, pc} */
/* @0x23b98c ldr r1, [r0, #0x4] */
/* @0x23b990 mov r0, sp */
/* @0x23b994 ldr r3, [r1] */
/* @0x23b998 ldr r3, [r3, #0x4] */
/* @0x23b99c blx r3 */
/* @0x23b9a0 ldr r3, [pc, #0x104] */
/* @0x23b9a4 vldr s14, [sp] */
/* @0x23b9a8 b 0x23b96c <_ZN13CPhysicsJoint8GetValueEi+0x35c> */
/* @0x23b9ac ldr r3, [pc, #0xf8] */
/* @0x23b9b0 vmov.f32 s14, #1.000000e+00 */
/* @0x23b9b4 ldr r1, [r0, #0x4] */
/* @0x23b9b8 mov r0, sp */
/* @0x23b9bc ldr r2, [r4, r3] */
/* @0x23b9c0 ldr r3, [r1] */
/* @0x23b9c4 ldr r2, [r2] */
/* @0x23b9c8 ldr r3, [r3, #0x8] */
/* @0x23b9cc ldr r2, [r2, #0xb4] */
/* @0x23b9d0 vldr s15, [r2, #88] */
/* @0x23b9d4 vcvt.f32.s32 s15, s15 */
/* @0x23b9d8 vdiv.f32 s14, s14, s15 */
/* @0x23b9dc vmov r2, s14 */
/* @0x23b9e0 blx r3 */
/* @0x23b9e4 vldr s15, [sp, #4] */
/* @0x23b9e8 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23b9ec ldr r3, [pc, #0xb8] */
/* @0x23b9f0 vmov.f32 s14, #1.000000e+00 */
/* @0x23b9f4 ldr r1, [r0, #0x4] */
/* @0x23b9f8 mov r0, sp */
/* @0x23b9fc ldr r2, [r4, r3] */
/* @0x23ba00 ldr r3, [r1] */
/* @0x23ba04 ldr r2, [r2] */
/* @0x23ba08 ldr r3, [r3, #0x8] */
/* @0x23ba0c ldr r2, [r2, #0xb4] */
/* @0x23ba10 vldr s15, [r2, #88] */
/* @0x23ba14 vcvt.f32.s32 s15, s15 */
/* @0x23ba18 vdiv.f32 s14, s14, s15 */
/* @0x23ba1c vmov r2, s14 */
/* @0x23ba20 blx r3 */
/* @0x23ba24 vldr s15, [sp] */
/* @0x23ba28 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23ba2c ldr r3, [pc, #0x78] */
/* @0x23ba30 vmov.f32 s14, #1.000000e+00 */
/* @0x23ba34 ldr r0, [r0, #0x4] */
/* @0x23ba38 ldr r2, [r4, r3] */
/* @0x23ba3c ldr r3, [r0] */
/* @0x23ba40 ldr r2, [r2] */
/* @0x23ba44 ldr r3, [r3, #0xc] */
/* @0x23ba48 ldr r2, [r2, #0xb4] */
/* @0x23ba4c vldr s15, [r2, #88] */
/* @0x23ba50 vcvt.f32.s32 s15, s15 */
/* @0x23ba54 vdiv.f32 s14, s14, s15 */
/* @0x23ba58 vmov r1, s14 */
/* @0x23ba5c blx r3 */
/* @0x23ba60 vmov s15, r0 */
/* @0x23ba64 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23ba68 ldr r1, [r0, #0x4] */
/* @0x23ba6c mov r0, sp */
/* @0x23ba70 ldr r3, [r1] */
/* @0x23ba74 ldr r3, [r3] */
/* @0x23ba78 b 0x23b960 <_ZN13CPhysicsJoint8GetValueEi+0x350> */
/* @0x23ba7c ldr r1, [r0, #0x4] */
/* @0x23ba80 mov r0, sp */
/* @0x23ba84 ldr r3, [r1] */
/* @0x23ba88 ldr r3, [r3] */
/* @0x23ba8c blx r3 */
/* @0x23ba90 ldr r3, [pc, #0x14] */
/* @0x23ba94 vldr s14, [sp] */
/* @0x23ba98 b 0x23b96c <_ZN13CPhysicsJoint8GetValueEi+0x35c> */
/* @0x23ba9c andeq r0, r0, r0 */
/* @0x23baa0 teqmi r4, #0 */
/* @0x23baa4 ldrdmi r0, r1, [r9], #-251 */
/* @0x23baa8 andseq r6, r11, r4, lsr r6 */
/* @0x23baac .word 0xffffbcd8 */
/* @0x23bab0 ldr r3, [pc, #-0xc] */
/* @0x23bab4 vldr s14, [r0, #104] */
/* @0x23bab8 b 0x23b96c <_ZN13CPhysicsJoint8GetValueEi+0x35c> */
/* @0x23babc vldr s15, [r2, #124] */
/* @0x23bac0 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23bac4 vldr s15, [r2, #132] */
/* @0x23bac8 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0> */
/* @0x23bacc add sp, sp, #8 */
/* @0x23bad0 pop {r4, lr} */
/* @0x23bad4 b 0x2d2104 <_ZNK15b2RevoluteJoint13GetJointAngleEv> */
/* @0x23bad8 bl 0x2d016c <_ZNK16b2PrismaticJoint19GetJointTranslationEv> */
/* @0x23badc b 0x23b708 <_ZN13CPhysicsJoint8GetValueEi+0xf8> */
/* @0x23bae0 add sp, sp, #8 */
/* @0x23bae4 pop {r4, lr} */
/* @0x23bae8 b 0x2d020c <_ZNK16b2PrismaticJoint13GetJointSpeedEv> */
/* @0x23baec vmov.f32 s14, #1.000000e+00 */
/* @0x23baf0 ldr r3, [r0] */
/* @0x23baf4 vldr s15, [r3, #88] */
/* @0x23baf8 mov r0, r2 */
/* @0x23bafc vcvt.f32.s32 s15, s15 */
/* @0x23bb00 vdiv.f32 s14, s14, s15 */
/* @0x23bb04 vmov r1, s14 */
/* @0x23bb08 add sp, sp, #8 */
/* @0x23bb0c pop {r4, lr} */
/* @0x23bb10 b 0x2d218c <_ZNK15b2RevoluteJoint14GetMotorTorqueEf> */

/* ── FUNC 0x23bb14 · CPhysicsJoint::SetValue(int, float) · size=824 · insn=206 */
/* @0x23bb14 sub r1, r1, #7 */
/* @0x23bb18 push {r4, lr} */
/* @0x23bb1c sub sp, sp, #8 */
/* @0x23bb20 cmp r1, #17 */
/* @0x23bb24 addls pc, pc, r1, lsl #2 */
/* @0x23bb28 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb2c b 0x23bbc0 <_ZN13CPhysicsJoint8SetValueEif+0xac> */
/* @0x23bb30 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb34 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb38 b 0x23bc28 <_ZN13CPhysicsJoint8SetValueEif+0x114> */
/* @0x23bb3c b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb40 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb44 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb48 b 0x23bc50 <_ZN13CPhysicsJoint8SetValueEif+0x13c> */
/* @0x23bb4c b 0x23bc70 <_ZN13CPhysicsJoint8SetValueEif+0x15c> */
/* @0x23bb50 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb54 b 0x23bc84 <_ZN13CPhysicsJoint8SetValueEif+0x170> */
/* @0x23bb58 b 0x23bb74 <_ZN13CPhysicsJoint8SetValueEif+0x60> */
/* @0x23bb5c b 0x23bcac <_ZN13CPhysicsJoint8SetValueEif+0x198> */
/* @0x23bb60 b 0x23bcf0 <_ZN13CPhysicsJoint8SetValueEif+0x1dc> */
/* @0x23bb64 b 0x23bd3c <_ZN13CPhysicsJoint8SetValueEif+0x228> */
/* @0x23bb68 b 0x23bd70 <_ZN13CPhysicsJoint8SetValueEif+0x25c> */
/* @0x23bb6c b 0x23bd84 <_ZN13CPhysicsJoint8SetValueEif+0x270> */
/* @0x23bb70 b 0x23bba0 <_ZN13CPhysicsJoint8SetValueEif+0x8c> */
/* @0x23bb74 ldr r1, [r0, #0x4] */
/* @0x23bb78 ldr r3, [r1, #0x4] */
/* @0x23bb7c cmp r3, #3 */
/* @0x23bb80 beq 0x23bb94 <_ZN13CPhysicsJoint8SetValueEif+0x80> */
/* @0x23bb84 cmp r3, #7 */
/* @0x23bb88 beq 0x23bb94 <_ZN13CPhysicsJoint8SetValueEif+0x80> */
/* @0x23bb8c cmp r3, #8 */
/* @0x23bb90 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bb94 str r2, [r1, #0x44] */
/* @0x23bb98 add sp, sp, #8 */
/* @0x23bb9c pop {r4, pc} */
/* @0x23bba0 ldr r0, [r0, #0x4] */
/* @0x23bba4 ldr r3, [r0, #0x4] */
/* @0x23bba8 cmp r3, #9 */
/* @0x23bbac bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bbb0 mov r1, r2 */
/* @0x23bbb4 add sp, sp, #8 */
/* @0x23bbb8 pop {r4, lr} */
/* @0x23bbbc b 0x2cda80 <_ZN15b2FrictionJoint11SetMaxForceEf> */
/* @0x23bbc0 ldr r0, [r0, #0x4] */
/* @0x23bbc4 ldr r3, [r0, #0x4] */
/* @0x23bbc8 cmp r3, #2 */
/* @0x23bbcc beq 0x23bdec <_ZN13CPhysicsJoint8SetValueEif+0x2d8> */
/* @0x23bbd0 cmp r3, #7 */
/* @0x23bbd4 beq 0x23bda4 <_ZN13CPhysicsJoint8SetValueEif+0x290> */
/* @0x23bbd8 cmp r3, #1 */
/* @0x23bbdc bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bbe0 ldr r3, [r0, #0x30] */
/* @0x23bbe4 ldrh r1, [r3, #4] */
/* @0x23bbe8 tst r1, #2 */
/* @0x23bbec orreq r1, r1, #2 */
/* @0x23bbf0 strheq r1, [r3, #4] */
/* @0x23bbf4 moveq r12, #0 */
/* @0x23bbf8 streq r12, [r3, #0xa0] */
/* @0x23bbfc ldr r3, [r0, #0x34] */
/* @0x23bc00 ldrh r1, [r3, #4] */
/* @0x23bc04 tst r1, #2 */
/* @0x23bc08 orreq r1, r1, #2 */
/* @0x23bc0c strheq r1, [r3, #4] */
/* @0x23bc10 moveq r12, #0 */
/* @0x23bc14 mov r1, r2 */
/* @0x23bc18 streq r12, [r3, #0xa0] */
/* @0x23bc1c add sp, sp, #8 */
/* @0x23bc20 pop {r4, lr} */
/* @0x23bc24 b 0x2d21a0 <_ZN15b2RevoluteJoint13SetMotorSpeedEf> */
/* @0x23bc28 ldr r0, [r0, #0x4] */
/* @0x23bc2c ldr r3, [r0, #0x4] */
/* @0x23bc30 cmp r3, #1 */
/* @0x23bc34 beq 0x23be34 <_ZN13CPhysicsJoint8SetValueEif+0x320> */
/* @0x23bc38 cmp r3, #7 */
/* @0x23bc3c bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bc40 mov r1, r2 */
/* @0x23bc44 add sp, sp, #8 */
/* @0x23bc48 pop {r4, lr} */
/* @0x23bc4c b 0x2d4424 <_ZN12b2WheelJoint17SetMaxMotorTorqueEf> */
/* @0x23bc50 ldr r0, [r0, #0x4] */
/* @0x23bc54 ldr r3, [r0, #0x4] */
/* @0x23bc58 cmp r3, #2 */
/* @0x23bc5c bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bc60 mov r1, r2 */
/* @0x23bc64 add sp, sp, #8 */
/* @0x23bc68 pop {r4, lr} */
/* @0x23bc6c b 0x2d04bc <_ZN16b2PrismaticJoint16SetMaxMotorForceEf> */
/* @0x23bc70 ldr r3, [r0, #0x4] */
/* @0x23bc74 ldr r1, [r3, #0x4] */
/* @0x23bc78 cmp r1, #3 */
/* @0x23bc7c streq r2, [r3, #0x68] */
/* @0x23bc80 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bc84 ldr r1, [r0, #0x4] */
/* @0x23bc88 ldr r3, [r1, #0x4] */
/* @0x23bc8c cmp r3, #3 */
/* @0x23bc90 beq 0x23bca4 <_ZN13CPhysicsJoint8SetValueEif+0x190> */
/* @0x23bc94 cmp r3, #7 */
/* @0x23bc98 beq 0x23bca4 <_ZN13CPhysicsJoint8SetValueEif+0x190> */
/* @0x23bc9c cmp r3, #8 */
/* @0x23bca0 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bca4 str r2, [r1, #0x48] */
/* @0x23bca8 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bcac ldr r4, [r0, #0x4] */
/* @0x23bcb0 ldr r3, [r4, #0x4] */
/* @0x23bcb4 cmp r3, #1 */
/* @0x23bcb8 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bcbc mov r0, r4 */
/* @0x23bcc0 str r2, [sp, #0x4] */
/* @0x23bcc4 bl 0x2d2284 <_ZNK15b2RevoluteJoint13GetUpperLimitEv> */
/* @0x23bcc8 ldr r2, [sp, #0x4] */
/* @0x23bccc vldr s14, [pc, #368] */
/* @0x23bcd0 vmov s15, r2 */
/* @0x23bcd4 vmul.f32 s14, s15, s14 */
/* @0x23bcd8 vldr s15, [pc, #360] */
/* @0x23bcdc vdiv.f32 s15, s14, s15 */
/* @0x23bce0 mov r2, r0 */
/* @0x23bce4 mov r0, r4 */
/* @0x23bce8 vmov r1, s15 */
/* @0x23bcec b 0x23bd30 <_ZN13CPhysicsJoint8SetValueEif+0x21c> */
/* @0x23bcf0 ldr r4, [r0, #0x4] */
/* @0x23bcf4 ldr r3, [r4, #0x4] */
/* @0x23bcf8 cmp r3, #1 */
/* @0x23bcfc bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bd00 mov r0, r4 */
/* @0x23bd04 str r2, [sp, #0x4] */
/* @0x23bd08 bl 0x2d227c <_ZNK15b2RevoluteJoint13GetLowerLimitEv> */
/* @0x23bd0c ldr r2, [sp, #0x4] */
/* @0x23bd10 vldr s14, [pc, #300] */
/* @0x23bd14 vmov s15, r2 */
/* @0x23bd18 vmul.f32 s14, s15, s14 */
/* @0x23bd1c vldr s15, [pc, #292] */
/* @0x23bd20 vdiv.f32 s15, s14, s15 */
/* @0x23bd24 mov r1, r0 */
/* @0x23bd28 mov r0, r4 */
/* @0x23bd2c vmov r2, s15 */
/* @0x23bd30 add sp, sp, #8 */
/* @0x23bd34 pop {r4, lr} */
/* @0x23bd38 b 0x2d228c <_ZN15b2RevoluteJoint9SetLimitsEff> */
/* @0x23bd3c ldr r0, [r0, #0x4] */
/* @0x23bd40 ldr r3, [r0, #0x4] */
/* @0x23bd44 cmp r3, #1 */
/* @0x23bd48 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bd4c vmov.f32 s15, #5.000000e-01 */
/* @0x23bd50 vmov s14, r2 */
/* @0x23bd54 vcmpe.f32 s14, s15 */
/* @0x23bd58 vmrs APSR_nzcv, fpscr */
/* @0x23bd5c movle r1, #0 */
/* @0x23bd60 movgt r1, #1 */
/* @0x23bd64 add sp, sp, #8 */
/* @0x23bd68 pop {r4, lr} */
/* @0x23bd6c b 0x2d2228 <_ZN15b2RevoluteJoint11EnableLimitEb> */
/* @0x23bd70 ldr r3, [r0, #0x4] */
/* @0x23bd74 ldr r1, [r3, #0x4] */
/* @0x23bd78 cmp r1, #10 */
/* @0x23bd7c streq r2, [r3, #0x54] */
/* @0x23bd80 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bd84 ldr r0, [r0, #0x4] */
/* @0x23bd88 ldr r3, [r0, #0x4] */
/* @0x23bd8c cmp r3, #9 */
/* @0x23bd90 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84> */
/* @0x23bd94 mov r1, r2 */
/* @0x23bd98 add sp, sp, #8 */
/* @0x23bd9c pop {r4, lr} */
/* @0x23bda0 b 0x2cdb20 <_ZN15b2FrictionJoint12SetMaxTorqueEf> */
/* @0x23bda4 ldr r3, [r0, #0x30] */
/* @0x23bda8 ldrh r1, [r3, #4] */
/* @0x23bdac tst r1, #2 */
/* @0x23bdb0 orreq r1, r1, #2 */
/* @0x23bdb4 strheq r1, [r3, #4] */
/* @0x23bdb8 moveq r12, #0 */
/* @0x23bdbc streq r12, [r3, #0xa0] */
/* @0x23bdc0 ldr r3, [r0, #0x34] */
/* @0x23bdc4 ldrh r1, [r3, #4] */
/* @0x23bdc8 tst r1, #2 */
/* @0x23bdcc orreq r1, r1, #2 */
/* @0x23bdd0 strheq r1, [r3, #4] */
/* @0x23bdd4 moveq r12, #0 */
/* @0x23bdd8 mov r1, r2 */
/* @0x23bddc streq r12, [r3, #0xa0] */
/* @0x23bde0 add sp, sp, #8 */
/* @0x23bde4 pop {r4, lr} */
/* @0x23bde8 b 0x2d43e4 <_ZN12b2WheelJoint13SetMotorSpeedEf> */
/* @0x23bdec ldr r3, [r0, #0x30] */
/* @0x23bdf0 ldrh r1, [r3, #4] */
/* @0x23bdf4 tst r1, #2 */
/* @0x23bdf8 orreq r1, r1, #2 */
/* @0x23bdfc strheq r1, [r3, #4] */
/* @0x23be00 moveq r12, #0 */
/* @0x23be04 streq r12, [r3, #0xa0] */
/* @0x23be08 ldr r3, [r0, #0x34] */
/* @0x23be0c ldrh r1, [r3, #4] */
/* @0x23be10 tst r1, #2 */
/* @0x23be14 orreq r1, r1, #2 */
/* @0x23be18 strheq r1, [r3, #4] */
/* @0x23be1c moveq r12, #0 */
/* @0x23be20 mov r1, r2 */
/* @0x23be24 streq r12, [r3, #0xa0] */
/* @0x23be28 add sp, sp, #8 */
/* @0x23be2c pop {r4, lr} */
/* @0x23be30 b 0x2d047c <_ZN16b2PrismaticJoint13SetMotorSpeedEf> */
/* @0x23be34 mov r1, r2 */
/* @0x23be38 add sp, sp, #8 */
/* @0x23be3c pop {r4, lr} */
/* @0x23be40 b 0x2d21e0 <_ZN15b2RevoluteJoint17SetMaxMotorTorqueEf> */
/* @0x23be44 ldrdmi r0, r1, [r9], #-251 */
/* @0x23be48 teqmi r4, #0 */

/* ── FUNC 0x23be4c · CRunnerContactListener::EndContact(b2Contact*) · size=4 · insn=1 */
/* @0x23be4c bx lr */

/* ── FUNC 0x23be50 · CRunnerContactListener::PreSolve(b2Contact*, b2Manifold const*) · size=4 · insn=1 */
/* @0x23be50 bx lr */

/* ── FUNC 0x23be54 · CRunnerContactListener::~CRunnerContactListener() · size=24 · insn=6 */
/* @0x23be54 ldr r3, [pc, #0xc] */
/* @0x23be58 ldr r3, [pc, r3] */
/* @0x23be5c add r3, r3, #8 */
/* @0x23be60 str r3, [r0] */
/* @0x23be64 bx lr */
/* @0x23be68 andseq r5, r11, r8, ror #12 */
