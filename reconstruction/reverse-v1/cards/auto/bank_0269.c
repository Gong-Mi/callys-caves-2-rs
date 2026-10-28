/* libyoyo.so 覆盖卡组 0269
 * 函数 0x2c8ffc..0x2cb48c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2c8ffc · b2World::SetDestructionListener(b2DestructionListener*) · size=16 · insn=4 */
/* @0x2c8ffc movw r3, #0x9244 */
/* @0x2c9000 movt r3, #0x1 */
/* @0x2c9004 str r1, [r0, r3] */
/* @0x2c9008 bx lr */

/* ── FUNC 0x2c900c · b2World::SetContactFilter(b2ContactFilter*) · size=16 · insn=4 */
/* @0x2c900c movw r3, #0x921c */
/* @0x2c9010 movt r3, #0x1 */
/* @0x2c9014 str r1, [r0, r3] */
/* @0x2c9018 bx lr */

/* ── FUNC 0x2c901c · b2World::SetContactListener(b2ContactListener*) · size=16 · insn=4 */
/* @0x2c901c movw r3, #0x9220 */
/* @0x2c9020 movt r3, #0x1 */
/* @0x2c9024 str r1, [r0, r3] */
/* @0x2c9028 bx lr */

/* ── FUNC 0x2c902c · b2World::SetDebugDraw(b2Draw*) · size=16 · insn=4 */
/* @0x2c902c movw r3, #0x9248 */
/* @0x2c9030 movt r3, #0x1 */
/* @0x2c9034 str r1, [r0, r3] */
/* @0x2c9038 bx lr */

/* ── FUNC 0x2c903c · b2World::CreateBody(b2BodyDef const*) · size=188 · insn=47 */
/* @0x2c903c push {r4, r5, r6, lr} */
/* @0x2c9040 movw r5, #0x91d4 */
/* @0x2c9044 movt r5, #0x1 */
/* @0x2c9048 ldr r3, [pc, #0xa0] */
/* @0x2c904c mov r4, r0 */
/* @0x2c9050 mov r6, r1 */
/* @0x2c9054 ldr r0, [r0, r5] */
/* @0x2c9058 ldr r3, [pc, r3] */
/* @0x2c905c ldr r1, [pc, #0x90] */
/* @0x2c9060 eor r0, r0, #2 */
/* @0x2c9064 ldr r3, [r3] */
/* @0x2c9068 add r1, pc, r1 */
/* @0x2c906c ubfx r0, r0, #0x1, #0x1 */
/* @0x2c9070 blx r3 */
/* @0x2c9074 ldr r3, [r4, r5] */
/* @0x2c9078 tst r3, #2 */
/* @0x2c907c bne 0x2c90e8 <_ZN7b2World10CreateBodyEPK9b2BodyDef+0xac> */
/* @0x2c9080 mov r0, r4 */
/* @0x2c9084 mov r1, #168 */
/* @0x2c9088 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2c908c subs r5, r0, #0 */
/* @0x2c9090 beq 0x2c90a0 <_ZN7b2World10CreateBodyEPK9b2BodyDef+0x64> */
/* @0x2c9094 mov r1, r6 */
/* @0x2c9098 mov r2, r4 */
/* @0x2c909c bl 0x2c6a80 <_ZN6b2BodyC2EPK9b2BodyDefP7b2World> */
/* @0x2c90a0 movw r3, #0x9228 */
/* @0x2c90a4 movt r3, #0x1 */
/* @0x2c90a8 mov r2, #0 */
/* @0x2c90ac str r2, [r5, #0x6c] */
/* @0x2c90b0 ldr r3, [r4, r3] */
/* @0x2c90b4 mov r0, r5 */
/* @0x2c90b8 cmp r3, r2 */
/* @0x2c90bc movw r2, #0x9228 */
/* @0x2c90c0 str r3, [r5, #0x70] */
/* @0x2c90c4 movt r2, #0x1 */
/* @0x2c90c8 strne r5, [r3, #0x6c] */
/* @0x2c90cc movw r3, #0x9230 */
/* @0x2c90d0 movt r3, #0x1 */
/* @0x2c90d4 ldr r1, [r4, r3] */
/* @0x2c90d8 str r5, [r4, r2] */
/* @0x2c90dc add r2, r1, #1 */
/* @0x2c90e0 str r2, [r4, r3] */
/* @0x2c90e4 pop {r4, r5, r6, pc} */
/* @0x2c90e8 mov r0, #0 */
/* @0x2c90ec pop {r4, r5, r6, pc} */
/* @0x2c90f0 andseq r8, r2, r0, ror r4 */
/* @0x2c90f4 andeq r4, r9, r12, ror #4 */

/* ── FUNC 0x2c90f8 · b2World::CreateJoint(b2JointDef const*) · size=324 · insn=81 */
/* @0x2c90f8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2c90fc movw r6, #0x91d4 */
/* @0x2c9100 movt r6, #0x1 */
/* @0x2c9104 ldr r3, [pc, #0x128] */
/* @0x2c9108 mov r4, r0 */
/* @0x2c910c mov r5, r1 */
/* @0x2c9110 ldr r0, [r0, r6] */
/* @0x2c9114 ldr r3, [pc, r3] */
/* @0x2c9118 ldr r1, [pc, #0x118] */
/* @0x2c911c eor r0, r0, #2 */
/* @0x2c9120 ldr r3, [r3] */
/* @0x2c9124 add r1, pc, r1 */
/* @0x2c9128 ubfx r0, r0, #0x1, #0x1 */
/* @0x2c912c blx r3 */
/* @0x2c9130 ldr r3, [r4, r6] */
/* @0x2c9134 ands r6, r3, #2 */
/* @0x2c9138 bne 0x2c922c <_ZN7b2World11CreateJointEPK10b2JointDef+0x134> */
/* @0x2c913c mov r1, r4 */
/* @0x2c9140 mov r0, r5 */
/* @0x2c9144 bl 0x2cdbc0 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator> */
/* @0x2c9148 movw r1, #0x922c */
/* @0x2c914c movt r1, #0x1 */
/* @0x2c9150 mov r7, #0 */
/* @0x2c9154 ldr r3, [r4, r1] */
/* @0x2c9158 cmp r3, #0 */
/* @0x2c915c ldr r1, [r0, #0x30] */
/* @0x2c9160 mov r2, r0 */
/* @0x2c9164 str r6, [r0, #0x8] */
/* @0x2c9168 movw r6, #0x922c */
/* @0x2c916c str r3, [r0, #0xc] */
/* @0x2c9170 movt r6, #0x1 */
/* @0x2c9174 strne r0, [r3, #0x8] */
/* @0x2c9178 movw r0, #0x9234 */
/* @0x2c917c movt r0, #0x1 */
/* @0x2c9180 ldr r12, [r1, #0x7c] */
/* @0x2c9184 ldr r3, [r2, #0x34] */
/* @0x2c9188 ldr r8, [r4, r0] */
/* @0x2c918c cmp r12, r7 */
/* @0x2c9190 str r2, [r4, r6] */
/* @0x2c9194 add r6, r8, #1 */
/* @0x2c9198 str r6, [r4, r0] */
/* @0x2c919c str r12, [r2, #0x1c] */
/* @0x2c91a0 add r0, r2, #16 */
/* @0x2c91a4 str r3, [r2, #0x10] */
/* @0x2c91a8 str r2, [r2, #0x14] */
/* @0x2c91ac str r7, [r2, #0x18] */
/* @0x2c91b0 strne r0, [r12, #0x8] */
/* @0x2c91b4 mov r12, #0 */
/* @0x2c91b8 str r0, [r1, #0x7c] */
/* @0x2c91bc ldr r0, [r3, #0x7c] */
/* @0x2c91c0 str r1, [r2, #0x20] */
/* @0x2c91c4 add r1, r2, #32 */
/* @0x2c91c8 cmp r0, r12 */
/* @0x2c91cc str r12, [r2, #0x28] */
/* @0x2c91d0 str r0, [r2, #0x2c] */
/* @0x2c91d4 str r2, [r2, #0x24] */
/* @0x2c91d8 strne r1, [r0, #0x8] */
/* @0x2c91dc ldrb r0, [r5, #0x10] */
/* @0x2c91e0 ldr r12, [r5, #0x8] */
/* @0x2c91e4 cmp r0, #0 */
/* @0x2c91e8 str r1, [r3, #0x7c] */
/* @0x2c91ec ldr r3, [r5, #0xc] */
/* @0x2c91f0 bne 0x2c9224 <_ZN7b2World11CreateJointEPK10b2JointDef+0x12c> */
/* @0x2c91f4 ldr r3, [r3, #0x80] */
/* @0x2c91f8 cmp r3, #0 */
/* @0x2c91fc beq 0x2c9224 <_ZN7b2World11CreateJointEPK10b2JointDef+0x12c> */
/* @0x2c9200 ldr r1, [r3] */
/* @0x2c9204 cmp r1, r12 */
/* @0x2c9208 ldreq r1, [r3, #0x4] */
/* @0x2c920c ldr r3, [r3, #0xc] */
/* @0x2c9210 ldreq r0, [r1, #0x4] */
/* @0x2c9214 orreq r0, r0, #8 */
/* @0x2c9218 streq r0, [r1, #0x4] */
/* @0x2c921c cmp r3, #0 */
/* @0x2c9220 bne 0x2c9200 <_ZN7b2World11CreateJointEPK10b2JointDef+0x108> */
/* @0x2c9224 mov r0, r2 */
/* @0x2c9228 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c922c mov r0, #0 */
/* @0x2c9230 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c9234 ldrheq r8, [r2], -r4 */
/* @0x2c9238 strheq r4, [r9], -r0 */

/* ── FUNC 0x2c923c · b2World::DestroyJoint(b2Joint*) · size=424 · insn=106 */
/* @0x2c923c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c9240 movw r5, #0x91d4 */
/* @0x2c9244 movt r5, #0x1 */
/* @0x2c9248 ldr r7, [pc, #0x188] */
/* @0x2c924c mov r6, r0 */
/* @0x2c9250 mov r4, r1 */
/* @0x2c9254 ldr r0, [r0, r5] */
/* @0x2c9258 ldr r7, [pc, r7] */
/* @0x2c925c ldr r1, [pc, #0x178] */
/* @0x2c9260 eor r0, r0, #2 */
/* @0x2c9264 ldr r3, [r7] */
/* @0x2c9268 add r1, pc, r1 */
/* @0x2c926c ubfx r0, r0, #0x1, #0x1 */
/* @0x2c9270 blx r3 */
/* @0x2c9274 ldr r3, [r6, r5] */
/* @0x2c9278 tst r3, #2 */
/* @0x2c927c popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c9280 ldr r3, [r4, #0x8] */
/* @0x2c9284 movw r8, #0x9234 */
/* @0x2c9288 ldrb r10, [r4, #0x3d] */
/* @0x2c928c movt r8, #0x1 */
/* @0x2c9290 cmp r3, #0 */
/* @0x2c9294 ldr r5, [r4, #0x30] */
/* @0x2c9298 ldr r9, [r4, #0x34] */
/* @0x2c929c mov r0, r4 */
/* @0x2c92a0 ldrne r2, [r4, #0xc] */
/* @0x2c92a4 strne r2, [r3, #0xc] */
/* @0x2c92a8 ldr r2, [r4, #0xc] */
/* @0x2c92ac cmp r2, #0 */
/* @0x2c92b0 strne r3, [r2, #0x8] */
/* @0x2c92b4 movw r3, #0x922c */
/* @0x2c92b8 movt r3, #0x1 */
/* @0x2c92bc ldr r1, [r6, r3] */
/* @0x2c92c0 cmp r1, r4 */
/* @0x2c92c4 streq r2, [r6, r3] */
/* @0x2c92c8 ldrh r3, [r5, #4] */
/* @0x2c92cc ldr r1, [r5, #0x7c] */
/* @0x2c92d0 tst r3, #2 */
/* @0x2c92d4 orreq r3, r3, #2 */
/* @0x2c92d8 strheq r3, [r5, #4] */
/* @0x2c92dc ldrh r3, [r9, #4] */
/* @0x2c92e0 moveq r2, #0 */
/* @0x2c92e4 streq r2, [r5, #0xa0] */
/* @0x2c92e8 tst r3, #2 */
/* @0x2c92ec orreq r3, r3, #2 */
/* @0x2c92f0 strheq r3, [r9, #4] */
/* @0x2c92f4 ldr r3, [r4, #0x18] */
/* @0x2c92f8 moveq r2, #0 */
/* @0x2c92fc streq r2, [r9, #0xa0] */
/* @0x2c9300 cmp r3, #0 */
/* @0x2c9304 ldrne r2, [r4, #0x1c] */
/* @0x2c9308 strne r2, [r3, #0xc] */
/* @0x2c930c ldr r2, [r4, #0x1c] */
/* @0x2c9310 cmp r2, #0 */
/* @0x2c9314 strne r3, [r2, #0x8] */
/* @0x2c9318 add r3, r4, #16 */
/* @0x2c931c cmp r1, r3 */
/* @0x2c9320 ldr r3, [r4, #0x28] */
/* @0x2c9324 streq r2, [r5, #0x7c] */
/* @0x2c9328 mov r2, #0 */
/* @0x2c932c cmp r3, r2 */
/* @0x2c9330 str r2, [r4, #0x18] */
/* @0x2c9334 str r2, [r4, #0x1c] */
/* @0x2c9338 ldrne r2, [r4, #0x2c] */
/* @0x2c933c ldr r1, [r9, #0x7c] */
/* @0x2c9340 strne r2, [r3, #0xc] */
/* @0x2c9344 ldr r2, [r4, #0x2c] */
/* @0x2c9348 cmp r2, #0 */
/* @0x2c934c strne r3, [r2, #0x8] */
/* @0x2c9350 add r3, r4, #32 */
/* @0x2c9354 cmp r1, r3 */
/* @0x2c9358 mov r1, r6 */
/* @0x2c935c streq r2, [r9, #0x7c] */
/* @0x2c9360 mov r3, #0 */
/* @0x2c9364 str r3, [r4, #0x28] */
/* @0x2c9368 str r3, [r4, #0x2c] */
/* @0x2c936c bl 0x2cdd98 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator> */
/* @0x2c9370 ldr r0, [r6, r8] */
/* @0x2c9374 ldr r1, [pc, #0x64] */
/* @0x2c9378 cmp r0, #0 */
/* @0x2c937c ldr r3, [r7] */
/* @0x2c9380 add r1, pc, r1 */
/* @0x2c9384 movle r0, #0 */
/* @0x2c9388 movgt r0, #1 */
/* @0x2c938c blx r3 */
/* @0x2c9390 ldr r3, [r6, r8] */
/* @0x2c9394 cmp r10, #0 */
/* @0x2c9398 sub r3, r3, #1 */
/* @0x2c939c str r3, [r6, r8] */
/* @0x2c93a0 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c93a4 ldr r3, [r9, #0x80] */
/* @0x2c93a8 cmp r3, #0 */
/* @0x2c93ac popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c93b0 ldr r2, [r3] */
/* @0x2c93b4 cmp r2, r5 */
/* @0x2c93b8 ldreq r2, [r3, #0x4] */
/* @0x2c93bc ldr r3, [r3, #0xc] */
/* @0x2c93c0 ldreq r1, [r2, #0x4] */
/* @0x2c93c4 orreq r1, r1, #8 */
/* @0x2c93c8 streq r1, [r2, #0x4] */
/* @0x2c93cc cmp r3, #0 */
/* @0x2c93d0 bne 0x2c93b0 <_ZN7b2World12DestroyJointEP7b2Joint+0x174> */
/* @0x2c93d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c93d8 andseq r8, r2, r0, ror r2 */
/* @0x2c93dc andeq r4, r9, r12, rrx */
/* @0x2c93e0 andeq r3, r9, r4, lsr #31 */

/* ── FUNC 0x2c93e4 · b2World::DestroyBody(b2Body*) · size=508 · insn=127 */
/* @0x2c93e4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c93e8 movw r3, #0x9230 */
/* @0x2c93ec movt r3, #0x1 */
/* @0x2c93f0 mov r4, r0 */
/* @0x2c93f4 ldr r5, [pc, #0x1d8] */
/* @0x2c93f8 mov r6, r1 */
/* @0x2c93fc ldr r0, [r0, r3] */
/* @0x2c9400 movw r7, #0x91d4 */
/* @0x2c9404 ldr r5, [pc, r5] */
/* @0x2c9408 ldr r1, [pc, #0x1c8] */
/* @0x2c940c cmp r0, #0 */
/* @0x2c9410 movt r7, #0x1 */
/* @0x2c9414 ldr r3, [r5] */
/* @0x2c9418 add r1, pc, r1 */
/* @0x2c941c movle r0, #0 */
/* @0x2c9420 movgt r0, #1 */
/* @0x2c9424 blx r3 */
/* @0x2c9428 ldr r0, [r4, r7] */
/* @0x2c942c ldr r1, [pc, #0x1a8] */
/* @0x2c9430 eor r0, r0, #2 */
/* @0x2c9434 ldr r3, [r5] */
/* @0x2c9438 add r1, pc, r1 */
/* @0x2c943c ubfx r0, r0, #0x1, #0x1 */
/* @0x2c9440 blx r3 */
/* @0x2c9444 ldr r3, [r4, r7] */
/* @0x2c9448 tst r3, #2 */
/* @0x2c944c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c9450 ldr r7, [r6, #0x7c] */
/* @0x2c9454 cmp r7, #0 */
/* @0x2c9458 movwne r8, #0x9244 */
/* @0x2c945c movtne r8, #0x1 */
/* @0x2c9460 beq 0x2c94a4 <_ZN7b2World11DestroyBodyEP6b2Body+0xc0> */
/* @0x2c9464 ldr r3, [r4, r8] */
/* @0x2c9468 ldr r5, [r7, #0xc] */
/* @0x2c946c cmp r3, #0 */
/* @0x2c9470 mov r0, r3 */
/* @0x2c9474 beq 0x2c9488 <_ZN7b2World11DestroyBodyEP6b2Body+0xa4> */
/* @0x2c9478 ldr r3, [r3] */
/* @0x2c947c ldr r1, [r7, #0x4] */
/* @0x2c9480 ldr r3, [r3, #0x8] */
/* @0x2c9484 blx r3 */
/* @0x2c9488 ldr r1, [r7, #0x4] */
/* @0x2c948c mov r0, r4 */
/* @0x2c9490 bl 0x2c923c <_ZN7b2World12DestroyJointEP7b2Joint> */
/* @0x2c9494 cmp r5, #0 */
/* @0x2c9498 mov r7, r5 */
/* @0x2c949c str r5, [r6, #0x7c] */
/* @0x2c94a0 bne 0x2c9464 <_ZN7b2World11DestroyBodyEP6b2Body+0x80> */
/* @0x2c94a4 ldr r3, [r6, #0x80] */
/* @0x2c94a8 mov r2, #0 */
/* @0x2c94ac str r2, [r6, #0x7c] */
/* @0x2c94b0 cmp r3, r2 */
/* @0x2c94b4 addne r7, r4, #102400 */
/* @0x2c94b8 addne r7, r7, #472 */
/* @0x2c94bc beq 0x2c94dc <_ZN7b2World11DestroyBodyEP6b2Body+0xf8> */
/* @0x2c94c0 ldr r5, [r3, #0xc] */
/* @0x2c94c4 mov r0, r7 */
/* @0x2c94c8 ldr r1, [r3, #0x4] */
/* @0x2c94cc bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact> */
/* @0x2c94d0 cmp r5, #0 */
/* @0x2c94d4 mov r3, r5 */
/* @0x2c94d8 bne 0x2c94c0 <_ZN7b2World11DestroyBodyEP6b2Body+0xdc> */
/* @0x2c94dc ldr r5, [r6, #0x74] */
/* @0x2c94e0 mov r3, #0 */
/* @0x2c94e4 str r3, [r6, #0x80] */
/* @0x2c94e8 cmp r5, r3 */
/* @0x2c94ec addne r9, r4, #102400 */
/* @0x2c94f0 movwne r8, #0x9244 */
/* @0x2c94f4 addne r9, r9, #472 */
/* @0x2c94f8 movtne r8, #0x1 */
/* @0x2c94fc beq 0x2c9568 <_ZN7b2World11DestroyBodyEP6b2Body+0x184> */
/* @0x2c9500 ldr r3, [r4, r8] */
/* @0x2c9504 mov r1, r5 */
/* @0x2c9508 ldr r7, [r5, #0x4] */
/* @0x2c950c cmp r3, #0 */
/* @0x2c9510 mov r0, r3 */
/* @0x2c9514 beq 0x2c9524 <_ZN7b2World11DestroyBodyEP6b2Body+0x140> */
/* @0x2c9518 ldr r3, [r3] */
/* @0x2c951c ldr r3, [r3, #0xc] */
/* @0x2c9520 blx r3 */
/* @0x2c9524 mov r0, r5 */
/* @0x2c9528 mov r1, r9 */
/* @0x2c952c bl 0x2c8770 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase> */
/* @0x2c9530 mov r0, r5 */
/* @0x2c9534 mov r1, r4 */
/* @0x2c9538 bl 0x2c85f0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator> */
/* @0x2c953c mov r1, r5 */
/* @0x2c9540 mov r0, r4 */
/* @0x2c9544 mov r2, #52 */
/* @0x2c9548 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c954c ldr r3, [r6, #0x78] */
/* @0x2c9550 cmp r7, #0 */
/* @0x2c9554 mov r5, r7 */
/* @0x2c9558 sub r3, r3, #1 */
/* @0x2c955c str r7, [r6, #0x74] */
/* @0x2c9560 str r3, [r6, #0x78] */
/* @0x2c9564 bne 0x2c9500 <_ZN7b2World11DestroyBodyEP6b2Body+0x11c> */
/* @0x2c9568 ldr r3, [r6, #0x6c] */
/* @0x2c956c mov r2, #0 */
/* @0x2c9570 str r2, [r6, #0x74] */
/* @0x2c9574 cmp r3, r2 */
/* @0x2c9578 str r2, [r6, #0x78] */
/* @0x2c957c ldrne r2, [r6, #0x70] */
/* @0x2c9580 strne r2, [r3, #0x70] */
/* @0x2c9584 ldr r2, [r6, #0x70] */
/* @0x2c9588 mov r0, r6 */
/* @0x2c958c cmp r2, #0 */
/* @0x2c9590 strne r3, [r2, #0x6c] */
/* @0x2c9594 movw r3, #0x9228 */
/* @0x2c9598 movt r3, #0x1 */
/* @0x2c959c ldr r1, [r4, r3] */
/* @0x2c95a0 cmp r1, r6 */
/* @0x2c95a4 streq r2, [r4, r3] */
/* @0x2c95a8 movw r3, #0x9230 */
/* @0x2c95ac movt r3, #0x1 */
/* @0x2c95b0 ldr r2, [r4, r3] */
/* @0x2c95b4 sub r2, r2, #1 */
/* @0x2c95b8 str r2, [r4, r3] */
/* @0x2c95bc bl 0x2c6bfc <_ZN6b2BodyD2Ev> */
/* @0x2c95c0 mov r0, r4 */
/* @0x2c95c4 mov r1, r6 */
/* @0x2c95c8 mov r2, #168 */
/* @0x2c95cc pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c95d0 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c95d4 andseq r8, r2, r4, asr #1 */
/* @0x2c95d8 andeq r3, r9, r0, asr pc */
/* @0x2c95dc muleq r9, r12, lr */

/* ── FUNC 0x2c95e0 · b2World::SetAllowSleeping(bool) · size=92 · insn=23 */
/* @0x2c95e0 movw r3, #0x9240 */
/* @0x2c95e4 movt r3, #0x1 */
/* @0x2c95e8 ldrb r2, [r0, r3] */
/* @0x2c95ec cmp r2, r1 */
/* @0x2c95f0 bxeq lr */
/* @0x2c95f4 cmp r1, #0 */
/* @0x2c95f8 strb r1, [r0, r3] */
/* @0x2c95fc bxne lr */
/* @0x2c9600 movw r3, #0x9228 */
/* @0x2c9604 movt r3, #0x1 */
/* @0x2c9608 ldr r3, [r0, r3] */
/* @0x2c960c cmp r3, #0 */
/* @0x2c9610 bxeq lr */
/* @0x2c9614 mov r1, #0 */
/* @0x2c9618 ldrh r2, [r3, #4] */
/* @0x2c961c tst r2, #2 */
/* @0x2c9620 orr r2, r2, #2 */
/* @0x2c9624 streq r1, [r3, #0xa0] */
/* @0x2c9628 strheq r2, [r3, #4] */
/* @0x2c962c ldr r3, [r3, #0x70] */
/* @0x2c9630 cmp r3, #0 */
/* @0x2c9634 bne 0x2c9618 <_ZN7b2World16SetAllowSleepingEb+0x38> */
/* @0x2c9638 bx lr */

/* ── FUNC 0x2c963c · b2World::Solve(b2TimeStep const&) · size=1144 · insn=286 */
/* @0x2c963c movw r3, #0x9228 */
/* @0x2c9640 movt r3, #0x1 */
/* @0x2c9644 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c9648 vpush {d8} */
/* @0x2c964c sub sp, sp, #140 */
/* @0x2c9650 ldr r12, [r0, r3] */
/* @0x2c9654 mov r7, r0 */
/* @0x2c9658 str r1, [sp, #0x28] */
/* @0x2c965c cmp r12, #0 */
/* @0x2c9660 beq 0x2c9680 <_ZN7b2World5SolveERK10b2TimeStep+0x44> */
/* @0x2c9664 add r3, r12, #12 */
/* @0x2c9668 add lr, r12, #28 */
/* @0x2c966c ldr r12, [r12, #0x70] */
/* @0x2c9670 ldm r3, {r0, r1, r2, r3} */
/* @0x2c9674 cmp r12, #0 */
/* @0x2c9678 stm lr, {r0, r1, r2, r3} */
/* @0x2c967c bne 0x2c9664 <_ZN7b2World5SolveERK10b2TimeStep+0x28> */
/* @0x2c9680 add r11, r7, #102400 */
/* @0x2c9684 movw r0, #0x9220 */
/* @0x2c9688 str r11, [sp, #0xc] */
/* @0x2c968c movt r0, #0x1 */
/* @0x2c9690 add r10, sp, #84 */
/* @0x2c9694 str r10, [sp, #0x14] */
/* @0x2c9698 ldr r10, [sp, #0xc] */
/* @0x2c969c mov r8, r11 */
/* @0x2c96a0 ldr r0, [r7, r0] */
/* @0x2c96a4 movw r1, #0x9230 */
/* @0x2c96a8 add r10, r10, #616 */
/* @0x2c96ac movw r2, #0x9218 */
/* @0x2c96b0 movt r1, #0x1 */
/* @0x2c96b4 movt r2, #0x1 */
/* @0x2c96b8 movw r3, #0x9234 */
/* @0x2c96bc add r11, r11, #608 */
/* @0x2c96c0 movt r3, #0x1 */
/* @0x2c96c4 add r8, r8, #612 */
/* @0x2c96c8 ldr r1, [r7, r1] */
/* @0x2c96cc mov r12, #0 */
/* @0x2c96d0 ldr r3, [r7, r3] */
/* @0x2c96d4 ldr r2, [r7, r2] */
/* @0x2c96d8 str r12, [r11] */
/* @0x2c96dc str r0, [sp, #0x4] */
/* @0x2c96e0 add r0, sp, #84 */
/* @0x2c96e4 str r12, [r8] */
/* @0x2c96e8 str r12, [r10] */
/* @0x2c96ec add r12, r7, #68 */
/* @0x2c96f0 str r12, [sp] */
/* @0x2c96f4 str r10, [sp, #0xc] */
/* @0x2c96f8 str r12, [sp, #0x18] */
/* @0x2c96fc bl 0x2e1130 <_ZN8b2IslandC2EiiiP16b2StackAllocatorP17b2ContactListener> */
/* @0x2c9700 movw r3, #0x9228 */
/* @0x2c9704 movt r3, #0x1 */
/* @0x2c9708 ldr r3, [r7, r3] */
/* @0x2c970c cmp r3, #0 */
/* @0x2c9710 beq 0x2c972c <_ZN7b2World5SolveERK10b2TimeStep+0xf0> */
/* @0x2c9714 ldrh r2, [r3, #4] */
/* @0x2c9718 bic r2, r2, #1 */
/* @0x2c971c strh r2, [r3, #4] */
/* @0x2c9720 ldr r3, [r3, #0x70] */
/* @0x2c9724 cmp r3, #0 */
/* @0x2c9728 bne 0x2c9714 <_ZN7b2World5SolveERK10b2TimeStep+0xd8> */
/* @0x2c972c movw r3, #0x9214 */
/* @0x2c9730 movt r3, #0x1 */
/* @0x2c9734 ldr r3, [r7, r3] */
/* @0x2c9738 cmp r3, #0 */
/* @0x2c973c beq 0x2c9758 <_ZN7b2World5SolveERK10b2TimeStep+0x11c> */
/* @0x2c9740 ldr r2, [r3, #0x4] */
/* @0x2c9744 bic r2, r2, #1 */
/* @0x2c9748 str r2, [r3, #0x4] */
/* @0x2c974c ldr r3, [r3, #0xc] */
/* @0x2c9750 cmp r3, #0 */
/* @0x2c9754 bne 0x2c9740 <_ZN7b2World5SolveERK10b2TimeStep+0x104> */
/* @0x2c9758 movw r3, #0x922c */
/* @0x2c975c movt r3, #0x1 */
/* @0x2c9760 ldr r3, [r7, r3] */
/* @0x2c9764 cmp r3, #0 */
/* @0x2c9768 movne r2, #0 */
/* @0x2c976c beq 0x2c9780 <_ZN7b2World5SolveERK10b2TimeStep+0x144> */
/* @0x2c9770 strb r2, [r3, #0x3c] */
/* @0x2c9774 ldr r3, [r3, #0xc] */
/* @0x2c9778 cmp r3, #0 */
/* @0x2c977c bne 0x2c9770 <_ZN7b2World5SolveERK10b2TimeStep+0x134> */
/* @0x2c9780 movw r3, #0x9230 */
/* @0x2c9784 movt r3, #0x1 */
/* @0x2c9788 ldr r0, [sp, #0x18] */
/* @0x2c978c ldr r1, [r7, r3] */
/* @0x2c9790 lsl r1, r1, #2 */
/* @0x2c9794 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi> */
/* @0x2c9798 movw r3, #0x9228 */
/* @0x2c979c movt r3, #0x1 */
/* @0x2c97a0 ldr r4, [r7, r3] */
/* @0x2c97a4 cmp r4, #0 */
/* @0x2c97a8 addeq r10, sp, #52 */
/* @0x2c97ac addeq r12, r7, #102400 */
/* @0x2c97b0 streq r10, [sp, #0x10] */
/* @0x2c97b4 mov r6, r0 */
/* @0x2c97b8 streq r12, [sp, #0x24] */
/* @0x2c97bc beq 0x2c9928 <_ZN7b2World5SolveERK10b2TimeStep+0x2ec> */
/* @0x2c97c0 add r10, r7, #102400 */
/* @0x2c97c4 movw r12, #0x9240 */
/* @0x2c97c8 str r10, [sp, #0x24] */
/* @0x2c97cc movt r12, #0x1 */
/* @0x2c97d0 add r10, r10, #568 */
/* @0x2c97d4 str r12, [sp, #0x1c] */
/* @0x2c97d8 str r10, [sp, #0x2c] */
/* @0x2c97dc add r12, sp, #52 */
/* @0x2c97e0 vldr s16, [pc, #712] */
/* @0x2c97e4 str r12, [sp, #0x10] */
/* @0x2c97e8 str r7, [sp, #0x20] */
/* @0x2c97ec ldrh r3, [r4, #4] */
/* @0x2c97f0 ands r2, r3, #1 */
/* @0x2c97f4 bne 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc> */
/* @0x2c97f8 and r1, r3, #34 */
/* @0x2c97fc cmp r1, #34 */
/* @0x2c9800 bne 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc> */
/* @0x2c9804 ldr r1, [r4] */
/* @0x2c9808 cmp r1, #0 */
/* @0x2c980c beq 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc> */
/* @0x2c9810 str r2, [sp, #0x70] */
/* @0x2c9814 mov r7, r2 */
/* @0x2c9818 str r2, [sp, #0x78] */
/* @0x2c981c orr r3, r3, #1 */
/* @0x2c9820 str r2, [sp, #0x74] */
/* @0x2c9824 mov r5, r2 */
/* @0x2c9828 str r4, [r6] */
/* @0x2c982c mov r0, r2 */
/* @0x2c9830 strh r3, [r4, #4] */
/* @0x2c9834 mov r2, #1 */
/* @0x2c9838 b 0x2c9840 <_ZN7b2World5SolveERK10b2TimeStep+0x204> */
/* @0x2c983c mov r0, r1 */
/* @0x2c9840 sub r2, r2, #1 */
/* @0x2c9844 ldr lr, [sp, #0x5c] */
/* @0x2c9848 add r1, r0, #1 */
/* @0x2c984c ldr r3, [r6, r2, lsl #2] */
/* @0x2c9850 ldrh r12, [r3, #4] */
/* @0x2c9854 str r0, [r3, #0x8] */
/* @0x2c9858 str r3, [lr, r0, lsl #2] */
/* @0x2c985c tst r12, #2 */
/* @0x2c9860 ldr r0, [r3] */
/* @0x2c9864 orreq r12, r12, #2 */
/* @0x2c9868 vstreq s16, [r3, #160] */
/* @0x2c986c strheq r12, [r3, #4] */
/* @0x2c9870 cmp r0, #0 */
/* @0x2c9874 bne 0x2c99bc <_ZN7b2World5SolveERK10b2TimeStep+0x380> */
/* @0x2c9878 cmp r2, #0 */
/* @0x2c987c bne 0x2c983c <_ZN7b2World5SolveERK10b2TimeStep+0x200> */
/* @0x2c9880 ldr r10, [sp, #0x1c] */
/* @0x2c9884 add r0, sp, #84 */
/* @0x2c9888 ldr lr, [sp, #0x20] */
/* @0x2c988c ldr r3, [sp, #0x2c] */
/* @0x2c9890 str r1, [sp, #0x70] */
/* @0x2c9894 ldrb r12, [lr, r10] */
/* @0x2c9898 ldr r1, [sp, #0x10] */
/* @0x2c989c ldr r2, [sp, #0x28] */
/* @0x2c98a0 str r12, [sp] */
/* @0x2c98a4 str r7, [sp, #0x78] */
/* @0x2c98a8 str r5, [sp, #0x74] */
/* @0x2c98ac bl 0x2e15e8 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b> */
/* @0x2c98b0 vldr s12, [r11] */
/* @0x2c98b4 vldr s11, [r8] */
/* @0x2c98b8 vldr s13, [sp, #64] */
/* @0x2c98bc ldr r10, [sp, #0xc] */
/* @0x2c98c0 vadd.f32 s12, s12, s13 */
/* @0x2c98c4 vldr s14, [sp, #68] */
/* @0x2c98c8 vldr s13, [r10] */
/* @0x2c98cc vldr s15, [sp, #72] */
/* @0x2c98d0 ldr r0, [sp, #0x70] */
/* @0x2c98d4 cmp r0, #0 */
/* @0x2c98d8 ldrgt r3, [sp, #0x5c] */
/* @0x2c98dc vadd.f32 s14, s11, s14 */
/* @0x2c98e0 vstr s12, [r11] */
/* @0x2c98e4 vadd.f32 s15, s13, s15 */
/* @0x2c98e8 vstr s14, [r8] */
/* @0x2c98ec addgt r0, r3, r0, lsl #2 */
/* @0x2c98f0 vstr s15, [r10] */
/* @0x2c98f4 ble 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc> */
/* @0x2c98f8 ldr r2, [r3], #4 */
/* @0x2c98fc ldr r1, [r2] */
/* @0x2c9900 cmp r1, #0 */
/* @0x2c9904 ldrheq r1, [r2, #4] */
/* @0x2c9908 biceq r1, r1, #1 */
/* @0x2c990c strheq r1, [r2, #4] */
/* @0x2c9910 cmp r3, r0 */
/* @0x2c9914 bne 0x2c98f8 <_ZN7b2World5SolveERK10b2TimeStep+0x2bc> */
/* @0x2c9918 ldr r4, [r4, #0x70] */
/* @0x2c991c cmp r4, #0 */
/* @0x2c9920 bne 0x2c97ec <_ZN7b2World5SolveERK10b2TimeStep+0x1b0> */
/* @0x2c9924 ldr r7, [sp, #0x20] */
/* @0x2c9928 ldr r0, [sp, #0x18] */
/* @0x2c992c mov r1, r6 */
/* @0x2c9930 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv> */
/* @0x2c9934 ldr r0, [sp, #0x10] */
/* @0x2c9938 bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2c993c movw r3, #0x9228 */
/* @0x2c9940 movt r3, #0x1 */
/* @0x2c9944 ldr r4, [r7, r3] */
/* @0x2c9948 cmp r4, #0 */
/* @0x2c994c bne 0x2c9960 <_ZN7b2World5SolveERK10b2TimeStep+0x324> */
/* @0x2c9950 b 0x2c998c <_ZN7b2World5SolveERK10b2TimeStep+0x350> */
/* @0x2c9954 ldr r4, [r4, #0x70] */
/* @0x2c9958 cmp r4, #0 */
/* @0x2c995c beq 0x2c998c <_ZN7b2World5SolveERK10b2TimeStep+0x350> */
/* @0x2c9960 ldrh r3, [r4, #4] */
/* @0x2c9964 tst r3, #1 */
/* @0x2c9968 beq 0x2c9954 <_ZN7b2World5SolveERK10b2TimeStep+0x318> */
/* @0x2c996c ldr r3, [r4] */
/* @0x2c9970 cmp r3, #0 */
/* @0x2c9974 beq 0x2c9954 <_ZN7b2World5SolveERK10b2TimeStep+0x318> */
/* @0x2c9978 mov r0, r4 */
/* @0x2c997c bl 0x2c72cc <_ZN6b2Body19SynchronizeFixturesEv> */
/* @0x2c9980 ldr r4, [r4, #0x70] */
/* @0x2c9984 cmp r4, #0 */
/* @0x2c9988 bne 0x2c9960 <_ZN7b2World5SolveERK10b2TimeStep+0x324> */
/* @0x2c998c ldr r12, [sp, #0x24] */
/* @0x2c9990 add r7, r7, #102400 */
/* @0x2c9994 add r0, r12, #472 */
/* @0x2c9998 bl 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv> */
/* @0x2c999c ldr r0, [sp, #0x10] */
/* @0x2c99a0 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2c99a4 str r0, [r7, #0x26c] */
/* @0x2c99a8 add r0, sp, #84 */
/* @0x2c99ac bl 0x2e11d8 <_ZN8b2IslandD2Ev> */
/* @0x2c99b0 add sp, sp, #140 */
/* @0x2c99b4 vpop {d8} */
/* @0x2c99b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c99bc ldr r0, [r3, #0x80] */
/* @0x2c99c0 cmp r0, #0 */
/* @0x2c99c4 beq 0x2c9a40 <_ZN7b2World5SolveERK10b2TimeStep+0x404> */
/* @0x2c99c8 ldr lr, [r0, #0x4] */
/* @0x2c99cc ldr r12, [lr, #0x4] */
/* @0x2c99d0 tst r12, #1 */
/* @0x2c99d4 and r9, r12, #6 */
/* @0x2c99d8 bne 0x2c9a34 <_ZN7b2World5SolveERK10b2TimeStep+0x3f8> */
/* @0x2c99dc cmp r9, #6 */
/* @0x2c99e0 bne 0x2c9a34 <_ZN7b2World5SolveERK10b2TimeStep+0x3f8> */
/* @0x2c99e4 ldr r10, [lr, #0x34] */
/* @0x2c99e8 ldr r9, [lr, #0x30] */
/* @0x2c99ec ldrb r10, [r10, #0x2c] */
/* @0x2c99f0 ldrb r9, [r9, #0x2c] */
/* @0x2c99f4 orrs r9, r10, r9 */
/* @0x2c99f8 bne 0x2c9a34 <_ZN7b2World5SolveERK10b2TimeStep+0x3f8> */
/* @0x2c99fc ldr r9, [sp, #0x60] */
/* @0x2c9a00 orr r12, r12, #1 */
/* @0x2c9a04 add r10, r7, #1 */
/* @0x2c9a08 str lr, [r9, r7, lsl #2] */
/* @0x2c9a0c mov r7, r10 */
/* @0x2c9a10 ldr r9, [r0] */
/* @0x2c9a14 str r12, [lr, #0x4] */
/* @0x2c9a18 ldrh r12, [r9, #4] */
/* @0x2c9a1c tst r12, #1 */
/* @0x2c9a20 streq r9, [r6, r2, lsl #2] */
/* @0x2c9a24 addeq r2, r2, #1 */
/* @0x2c9a28 orr r12, r12, #1 */
/* @0x2c9a2c movne r7, r10 */
/* @0x2c9a30 strheq r12, [r9, #4] */
/* @0x2c9a34 ldr r0, [r0, #0xc] */
/* @0x2c9a38 cmp r0, #0 */
/* @0x2c9a3c bne 0x2c99c8 <_ZN7b2World5SolveERK10b2TimeStep+0x38c> */
/* @0x2c9a40 ldr r3, [r3, #0x7c] */
/* @0x2c9a44 cmp r3, #0 */
/* @0x2c9a48 beq 0x2c9878 <_ZN7b2World5SolveERK10b2TimeStep+0x23c> */
/* @0x2c9a4c ldr r0, [r3, #0x4] */
/* @0x2c9a50 ldrb r12, [r0, #0x3c] */
/* @0x2c9a54 cmp r12, #0 */
/* @0x2c9a58 bne 0x2c9aa0 <_ZN7b2World5SolveERK10b2TimeStep+0x464> */
/* @0x2c9a5c ldr lr, [r3] */
/* @0x2c9a60 add r9, r5, #1 */
/* @0x2c9a64 ldrh r12, [lr, #4] */
/* @0x2c9a68 tst r12, #32 */
/* @0x2c9a6c beq 0x2c9aa0 <_ZN7b2World5SolveERK10b2TimeStep+0x464> */
/* @0x2c9a70 ldr r10, [sp, #0x64] */
/* @0x2c9a74 tst r12, #1 */
/* @0x2c9a78 orr r12, r12, #1 */
/* @0x2c9a7c str r0, [r10, r5, lsl #2] */
/* @0x2c9a80 mov r10, #1 */
/* @0x2c9a84 ldr r0, [r3, #0x4] */
/* @0x2c9a88 mov r5, r9 */
/* @0x2c9a8c movne r5, r9 */
/* @0x2c9a90 strb r10, [r0, #0x3c] */
/* @0x2c9a94 streq lr, [r6, r2, lsl #2] */
/* @0x2c9a98 addeq r2, r2, #1 */
/* @0x2c9a9c strheq r12, [lr, #4] */
/* @0x2c9aa0 ldr r3, [r3, #0xc] */
/* @0x2c9aa4 cmp r3, #0 */
/* @0x2c9aa8 bne 0x2c9a4c <_ZN7b2World5SolveERK10b2TimeStep+0x410> */
/* @0x2c9aac b 0x2c9878 <_ZN7b2World5SolveERK10b2TimeStep+0x23c> */
/* @0x2c9ab0 andeq r0, r0, r0 */

/* ── FUNC 0x2c9ab4 · b2World::SolveTOI(b2TimeStep const&) · size=2980 · insn=745 */
/* @0x2c9ab4 movw r3, #0x9220 */
/* @0x2c9ab8 movt r3, #0x1 */
/* @0x2c9abc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c9ac0 vpush {d8, d9, d10} */
/* @0x2c9ac4 sub sp, sp, #316 */
/* @0x2c9ac8 ldr r3, [r0, r3] */
/* @0x2c9acc add r2, sp, #128 */
/* @0x2c9ad0 str r0, [sp, #0x10] */
/* @0x2c9ad4 str r2, [sp, #0x24] */
/* @0x2c9ad8 add r2, r0, #68 */
/* @0x2c9adc str r1, [sp, #0x20] */
/* @0x2c9ae0 add r0, sp, #128 */
/* @0x2c9ae4 str r2, [sp] */
/* @0x2c9ae8 mov r1, #64 */
/* @0x2c9aec str r3, [sp, #0x4] */
/* @0x2c9af0 mov r2, #32 */
/* @0x2c9af4 mov r3, #0 */
/* @0x2c9af8 bl 0x2e1130 <_ZN8b2IslandC2EiiiP16b2StackAllocatorP17b2ContactListener> */
/* @0x2c9afc ldr lr, [sp, #0x10] */
/* @0x2c9b00 movw r3, #0x9253 */
/* @0x2c9b04 movt r3, #0x1 */
/* @0x2c9b08 ldrb r3, [lr, r3] */
/* @0x2c9b0c cmp r3, #0 */
/* @0x2c9b10 bne 0x2ca4f0 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa3c> */
/* @0x2c9b14 movw r3, #0x9214 */
/* @0x2c9b18 movt r3, #0x1 */
/* @0x2c9b1c ldr r4, [lr, r3] */
/* @0x2c9b20 ldr lr, [sp, #0x10] */
/* @0x2c9b24 cmp r4, #0 */
/* @0x2c9b28 movw r1, #0x9220 */
/* @0x2c9b2c movw r2, #0x9252 */
/* @0x2c9b30 add r3, lr, #102400 */
/* @0x2c9b34 movt r1, #0x1 */
/* @0x2c9b38 add r3, r3, #472 */
/* @0x2c9b3c movt r2, #0x1 */
/* @0x2c9b40 str r3, [sp, #0x2c] */
/* @0x2c9b44 vldr s19, [pc, #448] */
/* @0x2c9b48 str r1, [sp, #0x1c] */
/* @0x2c9b4c vldr s20, [pc, #444] */
/* @0x2c9b50 str r2, [sp, #0x28] */
/* @0x2c9b54 beq 0x2ca288 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7d4> */
/* @0x2c9b58 mov r8, #0 */
/* @0x2c9b5c vmov.f32 s16, #1.000000e+00 */
/* @0x2c9b60 add r10, sp, #180 */
/* @0x2c9b64 add r11, sp, #208 */
/* @0x2c9b68 mov r9, r8 */
/* @0x2c9b6c b 0x2c9b90 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xdc> */
/* @0x2c9b70 vldr s15, [r4, #132] */
/* @0x2c9b74 vcmpe.f32 s15, s16 */
/* @0x2c9b78 vmrs APSR_nzcv, fpscr */
/* @0x2c9b7c vmovmi.f32 s16, s15 */
/* @0x2c9b80 movmi r8, r4 */
/* @0x2c9b84 ldr r4, [r4, #0xc] */
/* @0x2c9b88 cmp r4, #0 */
/* @0x2c9b8c beq 0x2c9d14 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x260> */
/* @0x2c9b90 ldr r3, [r4, #0x4] */
/* @0x2c9b94 tst r3, #4 */
/* @0x2c9b98 beq 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0> */
/* @0x2c9b9c ldr r2, [r4, #0x80] */
/* @0x2c9ba0 cmp r2, #8 */
/* @0x2c9ba4 bgt 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0> */
/* @0x2c9ba8 tst r3, #32 */
/* @0x2c9bac bne 0x2c9b70 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xbc> */
/* @0x2c9bb0 ldr r3, [r4, #0x30] */
/* @0x2c9bb4 ldr r5, [r4, #0x34] */
/* @0x2c9bb8 ldrb r2, [r3, #0x2c] */
/* @0x2c9bbc cmp r2, #0 */
/* @0x2c9bc0 bne 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0> */
/* @0x2c9bc4 ldrb r2, [r5, #0x2c] */
/* @0x2c9bc8 cmp r2, #0 */
/* @0x2c9bcc bne 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0> */
/* @0x2c9bd0 ldr r6, [r3, #0x8] */
/* @0x2c9bd4 ldr r7, [r5, #0x8] */
/* @0x2c9bd8 ldrh r1, [r6, #4] */
/* @0x2c9bdc ldr r12, [r6] */
/* @0x2c9be0 and r0, r1, #2 */
/* @0x2c9be4 ldr lr, [r7] */
/* @0x2c9be8 uxth r0, r0 */
/* @0x2c9bec cmp r0, #0 */
/* @0x2c9bf0 beq 0x2c9bfc <_ZN7b2World8SolveTOIERK10b2TimeStep+0x148> */
/* @0x2c9bf4 adds r0, r12, #0 */
/* @0x2c9bf8 movne r0, #1 */
/* @0x2c9bfc ldrh r2, [r7, #4] */
/* @0x2c9c00 tst r2, #2 */
/* @0x2c9c04 beq 0x2ca390 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8dc> */
/* @0x2c9c08 cmp lr, #0 */
/* @0x2c9c0c beq 0x2ca390 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8dc> */
/* @0x2c9c10 tst r1, #8 */
/* @0x2c9c14 movne r12, #1 */
/* @0x2c9c18 bne 0x2c9c24 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x170> */
/* @0x2c9c1c subs r12, r12, #2 */
/* @0x2c9c20 movne r12, #1 */
/* @0x2c9c24 tst r2, #8 */
/* @0x2c9c28 bne 0x2c9c34 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x180> */
/* @0x2c9c2c cmp lr, #2 */
/* @0x2c9c30 beq 0x2ca5dc <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb28> */
/* @0x2c9c34 vldr s17, [r6, #76] */
/* @0x2c9c38 vldr s15, [r7, #76] */
/* @0x2c9c3c vcmpe.f32 s17, s15 */
/* @0x2c9c40 vmrs APSR_nzcv, fpscr */
/* @0x2c9c44 bmi 0x2ca570 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xabc> */
/* @0x2c9c48 bgt 0x2ca604 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb50> */
/* @0x2c9c4c ldr r12, [r4, #0x3c] */
/* @0x2c9c50 mov r0, r10 */
/* @0x2c9c54 ldr r2, [r4, #0x38] */
/* @0x2c9c58 vstr s19, [sp, #204] */
/* @0x2c9c5c str r9, [sp, #0xc4] */
/* @0x2c9c60 vstr s19, [sp, #232] */
/* @0x2c9c64 str r9, [sp, #0xc8] */
/* @0x2c9c68 add r6, r6, #44 */
/* @0x2c9c6c str r9, [sp, #0xe0] */
/* @0x2c9c70 vmov.f32 s18, #1.000000e+00 */
/* @0x2c9c74 str r9, [sp, #0xe4] */
/* @0x2c9c78 ldr r1, [r3, #0xc] */
/* @0x2c9c7c str r12, [sp, #0x8] */
/* @0x2c9c80 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei> */
/* @0x2c9c84 ldr r12, [sp, #0x8] */
/* @0x2c9c88 mov r0, r11 */
/* @0x2c9c8c ldr r1, [r5, #0xc] */
/* @0x2c9c90 add r5, sp, #236 */
/* @0x2c9c94 mov r2, r12 */
/* @0x2c9c98 bl 0x2c3b74 <_ZN15b2DistanceProxy3SetEPK7b2Shapei> */
/* @0x2c9c9c ldm r6!, {r0, r1, r2, r3} */
/* @0x2c9ca0 add lr, r7, #44 */
/* @0x2c9ca4 add r12, sp, #272 */
/* @0x2c9ca8 stm r5!, {r0, r1, r2, r3} */
/* @0x2c9cac ldm r6!, {r0, r1, r2, r3} */
/* @0x2c9cb0 stm r5!, {r0, r1, r2, r3} */
/* @0x2c9cb4 ldr r3, [r6] */
/* @0x2c9cb8 str r3, [r5] */
/* @0x2c9cbc ldm lr!, {r0, r1, r2, r3} */
/* @0x2c9cc0 stm r12!, {r0, r1, r2, r3} */
/* @0x2c9cc4 ldm lr!, {r0, r1, r2, r3} */
/* @0x2c9cc8 stm r12!, {r0, r1, r2, r3} */
/* @0x2c9ccc add r0, sp, #92 */
/* @0x2c9cd0 ldr r3, [lr] */
/* @0x2c9cd4 mov r1, r10 */
/* @0x2c9cd8 vstr s18, [sp, #308] */
/* @0x2c9cdc str r3, [r12] */
/* @0x2c9ce0 bl 0x2e0930 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput> */
/* @0x2c9ce4 ldr r3, [sp, #0x5c] */
/* @0x2c9ce8 vldr s15, [sp, #96] */
/* @0x2c9cec cmp r3, #3 */
/* @0x2c9cf0 vmovne.f32 s15, s18 */
/* @0x2c9cf4 beq 0x2ca5e8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb34> */
/* @0x2c9cf8 ldr r3, [r4, #0x4] */
/* @0x2c9cfc vstr s15, [r4, #132] */
/* @0x2c9d00 orr r3, r3, #32 */
/* @0x2c9d04 str r3, [r4, #0x4] */
/* @0x2c9d08 b 0x2c9b74 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xc0> */
/* @0x2c9d0c andeq r0, r0, r0 */
/* @0x2c9d10 svclo #0x7fffec */
/* @0x2c9d14 cmp r8, #0 */
/* @0x2c9d18 beq 0x2ca288 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7d4> */
/* @0x2c9d1c vcmpe.f32 s16, s20 */
/* @0x2c9d20 vmrs APSR_nzcv, fpscr */
/* @0x2c9d24 bgt 0x2ca288 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7d4> */
/* @0x2c9d28 ldr r2, [r8, #0x30] */
/* @0x2c9d2c add r10, sp, #56 */
/* @0x2c9d30 ldr r3, [r8, #0x34] */
/* @0x2c9d34 add r11, sp, #92 */
/* @0x2c9d38 mov r6, r10 */
/* @0x2c9d3c vmov.f32 s21, #1.000000e+00 */
/* @0x2c9d40 ldr r4, [r2, #0x8] */
/* @0x2c9d44 mov r12, r11 */
/* @0x2c9d48 ldr r5, [r3, #0x8] */
/* @0x2c9d4c add r2, r4, #44 */
/* @0x2c9d50 str r2, [sp, #0x18] */
/* @0x2c9d54 add r9, r5, #44 */
/* @0x2c9d58 add lr, r4, #52 */
/* @0x2c9d5c mov r7, r2 */
/* @0x2c9d60 str lr, [sp, #0x14] */
/* @0x2c9d64 ldm r7!, {r0, r1, r2, r3} */
/* @0x2c9d68 add lr, r4, #60 */
/* @0x2c9d6c str lr, [sp, #0xc] */
/* @0x2c9d70 mov lr, r9 */
/* @0x2c9d74 stm r6!, {r0, r1, r2, r3} */
/* @0x2c9d78 ldm r7!, {r0, r1, r2, r3} */
/* @0x2c9d7c stm r6!, {r0, r1, r2, r3} */
/* @0x2c9d80 ldm lr!, {r0, r1, r2, r3} */
/* @0x2c9d84 ldr r7, [r7] */
/* @0x2c9d88 stm r12!, {r0, r1, r2, r3} */
/* @0x2c9d8c ldm lr!, {r0, r1, r2, r3} */
/* @0x2c9d90 str r7, [r6] */
/* @0x2c9d94 stm r12!, {r0, r1, r2, r3} */
/* @0x2c9d98 ldr r3, [lr] */
/* @0x2c9d9c ldr lr, [sp, #0x14] */
/* @0x2c9da0 str r3, [r12] */
/* @0x2c9da4 vldr s12, [r4, #76] */
/* @0x2c9da8 vsub.f32 s14, s16, s12 */
/* @0x2c9dac vldr s13, [r4, #52] */
/* @0x2c9db0 vldr s15, [r4, #56] */
/* @0x2c9db4 vldr s10, [r4, #60] */
/* @0x2c9db8 vldr s11, [r4, #64] */
/* @0x2c9dbc vldr s9, [r4, #72] */
/* @0x2c9dc0 vldr s17, [r4, #68] */
/* @0x2c9dc4 vstr s16, [r4, #76] */
/* @0x2c9dc8 vsub.f32 s12, s21, s12 */
/* @0x2c9dcc vdiv.f32 s14, s14, s12 */
/* @0x2c9dd0 vsub.f32 s10, s10, s13 */
/* @0x2c9dd4 vsub.f32 s11, s11, s15 */
/* @0x2c9dd8 vsub.f32 s12, s9, s17 */
/* @0x2c9ddc vmla.f32 s13, s14, s10 */
/* @0x2c9de0 vmla.f32 s15, s14, s11 */
/* @0x2c9de4 vstr s13, [r4, #52] */
/* @0x2c9de8 vmla.f32 s17, s14, s12 */
/* @0x2c9dec vstr s15, [r4, #56] */
/* @0x2c9df0 ldm lr, {r0, r1} */
/* @0x2c9df4 ldr lr, [sp, #0xc] */
/* @0x2c9df8 vstr s17, [r4, #68] */
/* @0x2c9dfc stm lr, {r0, r1} */
/* @0x2c9e00 vstr s17, [r4, #72] */
/* @0x2c9e04 vmov r0, s17 */
/* @0x2c9e08 bl 0xb6580 <sinf@plt> */
/* @0x2c9e0c vmov s18, r0 */
/* @0x2c9e10 vstr s18, [r4, #20] */
/* @0x2c9e14 vmov r0, s17 */
/* @0x2c9e18 bl 0xb658c <cosf@plt> */
/* @0x2c9e1c vldr s14, [r4, #48] */
/* @0x2c9e20 vmul.f32 s13, s14, s18 */
/* @0x2c9e24 vldr s15, [r4, #44] */
/* @0x2c9e28 vldr s10, [r4, #60] */
/* @0x2c9e2c vldr s11, [r4, #64] */
/* @0x2c9e30 add r2, r5, #52 */
/* @0x2c9e34 add r3, r5, #60 */
/* @0x2c9e38 vmov s12, r0 */
/* @0x2c9e3c str r0, [r4, #0x18] */
/* @0x2c9e40 vmul.f32 s14, s14, s12 */
/* @0x2c9e44 vnmls.f32 s13, s15, s12 */
/* @0x2c9e48 vmla.f32 s14, s15, s18 */
/* @0x2c9e4c vsub.f32 s13, s10, s13 */
/* @0x2c9e50 vsub.f32 s14, s11, s14 */
/* @0x2c9e54 vstr s13, [r4, #12] */
/* @0x2c9e58 vstr s14, [r4, #16] */
/* @0x2c9e5c vldr s12, [r5, #76] */
/* @0x2c9e60 vsub.f32 s21, s21, s12 */
/* @0x2c9e64 vldr s13, [r5, #52] */
/* @0x2c9e68 vldr s14, [r5, #56] */
/* @0x2c9e6c vldr s10, [r5, #60] */
/* @0x2c9e70 vldr s11, [r5, #64] */
/* @0x2c9e74 vldr s9, [r5, #72] */
/* @0x2c9e78 vldr s17, [r5, #68] */
/* @0x2c9e7c vstr s16, [r5, #76] */
/* @0x2c9e80 vsub.f32 s15, s16, s12 */
/* @0x2c9e84 vdiv.f32 s15, s15, s21 */
/* @0x2c9e88 vsub.f32 s10, s10, s13 */
/* @0x2c9e8c vsub.f32 s11, s11, s14 */
/* @0x2c9e90 vsub.f32 s12, s9, s17 */
/* @0x2c9e94 vmla.f32 s13, s15, s10 */
/* @0x2c9e98 vmla.f32 s14, s15, s11 */
/* @0x2c9e9c vstr s13, [r5, #52] */
/* @0x2c9ea0 vmla.f32 s17, s15, s12 */
/* @0x2c9ea4 vstr s14, [r5, #56] */
/* @0x2c9ea8 ldm r2, {r0, r1} */
/* @0x2c9eac vstr s17, [r5, #68] */
/* @0x2c9eb0 stm r3, {r0, r1} */
/* @0x2c9eb4 vstr s17, [r5, #72] */
/* @0x2c9eb8 vmov r0, s17 */
/* @0x2c9ebc bl 0xb6580 <sinf@plt> */
/* @0x2c9ec0 vmov s18, r0 */
/* @0x2c9ec4 vstr s18, [r5, #20] */
/* @0x2c9ec8 vmov r0, s17 */
/* @0x2c9ecc bl 0xb658c <cosf@plt> */
/* @0x2c9ed0 vldr s15, [r5, #48] */
/* @0x2c9ed4 vmul.f32 s14, s15, s18 */
/* @0x2c9ed8 vldr s12, [r5, #44] */
/* @0x2c9edc vldr s10, [r5, #60] */
/* @0x2c9ee0 vldr s11, [r5, #64] */
/* @0x2c9ee4 ldr r3, [sp, #0x10] */
/* @0x2c9ee8 ldr r2, [sp, #0x1c] */
/* @0x2c9eec vmov s13, r0 */
/* @0x2c9ef0 str r0, [r5, #0x18] */
/* @0x2c9ef4 mov r0, r8 */
/* @0x2c9ef8 vmul.f32 s15, s15, s13 */
/* @0x2c9efc vnmls.f32 s14, s12, s13 */
/* @0x2c9f00 vmla.f32 s15, s12, s18 */
/* @0x2c9f04 vsub.f32 s14, s10, s14 */
/* @0x2c9f08 vsub.f32 s15, s11, s15 */
/* @0x2c9f0c vstr s14, [r5, #12] */
/* @0x2c9f10 vstr s15, [r5, #16] */
/* @0x2c9f14 ldr r1, [r3, r2] */
/* @0x2c9f18 bl 0x2cc1ec <_ZN9b2Contact6UpdateEP17b2ContactListener> */
/* @0x2c9f1c ldr r12, [r8, #0x4] */
/* @0x2c9f20 ldr r2, [r8, #0x80] */
/* @0x2c9f24 and r1, r12, #6 */
/* @0x2c9f28 bic r3, r12, #32 */
/* @0x2c9f2c cmp r1, #6 */
/* @0x2c9f30 add r2, r2, #1 */
/* @0x2c9f34 str r3, [r8, #0x4] */
/* @0x2c9f38 str r2, [r8, #0x80] */
/* @0x2c9f3c bne 0x2ca2a0 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7ec> */
/* @0x2c9f40 ldrh r2, [r4, #4] */
/* @0x2c9f44 tst r2, #2 */
/* @0x2c9f48 orreq r2, r2, #2 */
/* @0x2c9f4c vstreq s19, [r4, #160] */
/* @0x2c9f50 strheq r2, [r4, #4] */
/* @0x2c9f54 ldrh r2, [r5, #4] */
/* @0x2c9f58 mov r10, #0 */
/* @0x2c9f5c ldr r1, [sp, #0x88] */
/* @0x2c9f60 mov r0, #2 */
/* @0x2c9f64 tst r2, #2 */
/* @0x2c9f68 vstreq s19, [r5, #160] */
/* @0x2c9f6c orreq r2, r2, #2 */
/* @0x2c9f70 strheq r2, [r5, #4] */
/* @0x2c9f74 str r10, [sp, #0xa0] */
/* @0x2c9f78 mov r2, #1 */
/* @0x2c9f7c str r10, [r4, #0x8] */
/* @0x2c9f80 orr r3, r3, r2 */
/* @0x2c9f84 str r4, [r1] */
/* @0x2c9f88 mov r11, r4 */
/* @0x2c9f8c ldr r1, [sp, #0x88] */
/* @0x2c9f90 add lr, sp, #180 */
/* @0x2c9f94 str r2, [r5, #0x8] */
/* @0x2c9f98 vmov.f32 s17, #1.000000e+00 */
/* @0x2c9f9c str r4, [sp, #0x30] */
/* @0x2c9fa0 mov r9, r4 */
/* @0x2c9fa4 str r5, [r1, #0x4] */
/* @0x2c9fa8 ldr r1, [sp, #0x8c] */
/* @0x2c9fac str r2, [sp, #0xa4] */
/* @0x2c9fb0 ldrh r2, [r4, #4] */
/* @0x2c9fb4 str r0, [sp, #0x9c] */
/* @0x2c9fb8 orr r2, r2, #1 */
/* @0x2c9fbc str r8, [r1] */
/* @0x2c9fc0 strh r2, [r4, #4] */
/* @0x2c9fc4 ldrh r2, [r5, #4] */
/* @0x2c9fc8 str lr, [sp, #0xc] */
/* @0x2c9fcc orr r2, r2, #1 */
/* @0x2c9fd0 strh r2, [r5, #4] */
/* @0x2c9fd4 str r3, [r8, #0x4] */
/* @0x2c9fd8 ldr r3, [r11] */
/* @0x2c9fdc str r5, [sp, #0x34] */
/* @0x2c9fe0 cmp r3, #2 */
/* @0x2c9fe4 beq 0x2ca008 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x554> */
/* @0x2c9fe8 add r10, r10, #4 */
/* @0x2c9fec cmp r10, #8 */
/* @0x2c9ff0 beq 0x2ca184 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6d0> */
/* @0x2c9ff4 add r3, sp, #48 */
/* @0x2c9ff8 ldr r11, [r10, r3] */
/* @0x2c9ffc ldr r3, [r11] */
/* @0x2ca000 cmp r3, #2 */
/* @0x2ca004 bne 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534> */
/* @0x2ca008 ldr r4, [r11, #0x80] */
/* @0x2ca00c cmp r4, #0 */
/* @0x2ca010 beq 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534> */
/* @0x2ca014 ldr r2, [sp, #0x9c] */
/* @0x2ca018 ldr r3, [sp, #0xa8] */
/* @0x2ca01c cmp r2, r3 */
/* @0x2ca020 beq 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534> */
/* @0x2ca024 ldr r2, [sp, #0xa4] */
/* @0x2ca028 ldr r3, [sp, #0xac] */
/* @0x2ca02c cmp r2, r3 */
/* @0x2ca030 strne r5, [sp, #0x14] */
/* @0x2ca034 movne r5, r11 */
/* @0x2ca038 bne 0x2ca130 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x67c> */
/* @0x2ca03c b 0x2c9fe8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x534> */
/* @0x2ca040 ldr r2, [r6, #0x34] */
/* @0x2ca044 ldr r3, [r6, #0x30] */
/* @0x2ca048 ldrb r2, [r2, #0x2c] */
/* @0x2ca04c ldrb r3, [r3, #0x2c] */
/* @0x2ca050 orrs r3, r2, r3 */
/* @0x2ca054 bne 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650> */
/* @0x2ca058 add r8, r7, #44 */
/* @0x2ca05c add r12, sp, #180 */
/* @0x2ca060 ldrh r11, [r7, #4] */
/* @0x2ca064 mov lr, r8 */
/* @0x2ca068 ldm lr!, {r0, r1, r2, r3} */
/* @0x2ca06c tst r11, #1 */
/* @0x2ca070 stm r12!, {r0, r1, r2, r3} */
/* @0x2ca074 ldm lr!, {r0, r1, r2, r3} */
/* @0x2ca078 stm r12!, {r0, r1, r2, r3} */
/* @0x2ca07c ldr r3, [lr] */
/* @0x2ca080 str r3, [r12] */
/* @0x2ca084 beq 0x2ca410 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x95c> */
/* @0x2ca088 ldr r3, [sp, #0x10] */
/* @0x2ca08c mov r0, r6 */
/* @0x2ca090 ldr r2, [sp, #0x1c] */
/* @0x2ca094 ldr r1, [r3, r2] */
/* @0x2ca098 bl 0x2cc1ec <_ZN9b2Contact6UpdateEP17b2ContactListener> */
/* @0x2ca09c ldr r3, [r6, #0x4] */
/* @0x2ca0a0 tst r3, #4 */
/* @0x2ca0a4 beq 0x2ca39c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8e8> */
/* @0x2ca0a8 tst r3, #2 */
/* @0x2ca0ac beq 0x2ca39c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x8e8> */
/* @0x2ca0b0 ldrh r1, [r7, #4] */
/* @0x2ca0b4 orr r3, r3, #1 */
/* @0x2ca0b8 ldr r2, [sp, #0xa4] */
/* @0x2ca0bc ldr r0, [sp, #0x8c] */
/* @0x2ca0c0 tst r1, #1 */
/* @0x2ca0c4 str r3, [r6, #0x4] */
/* @0x2ca0c8 add r3, r2, #1 */
/* @0x2ca0cc str r3, [sp, #0xa4] */
/* @0x2ca0d0 str r6, [r0, r2, lsl #2] */
/* @0x2ca0d4 bne 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650> */
/* @0x2ca0d8 ldr r3, [r7] */
/* @0x2ca0dc orr r2, r1, #1 */
/* @0x2ca0e0 strh r2, [r7, #4] */
/* @0x2ca0e4 cmp r3, #0 */
/* @0x2ca0e8 bne 0x2ca5c8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb14> */
/* @0x2ca0ec ldr r3, [sp, #0x9c] */
/* @0x2ca0f0 ldr r1, [sp, #0x88] */
/* @0x2ca0f4 add r2, r3, #1 */
/* @0x2ca0f8 str r3, [r7, #0x8] */
/* @0x2ca0fc str r7, [r1, r3, lsl #2] */
/* @0x2ca100 str r2, [sp, #0x9c] */
/* @0x2ca104 ldr r4, [r4, #0xc] */
/* @0x2ca108 cmp r4, #0 */
/* @0x2ca10c beq 0x2ca174 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c0> */
/* @0x2ca110 ldr r2, [sp, #0x9c] */
/* @0x2ca114 ldr r3, [sp, #0xa8] */
/* @0x2ca118 cmp r2, r3 */
/* @0x2ca11c beq 0x2ca174 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c0> */
/* @0x2ca120 ldr r2, [sp, #0xa4] */
/* @0x2ca124 ldr r3, [sp, #0xac] */
/* @0x2ca128 cmp r2, r3 */
/* @0x2ca12c beq 0x2ca174 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c0> */
/* @0x2ca130 ldr r6, [r4, #0x4] */
/* @0x2ca134 ldr r3, [r6, #0x4] */
/* @0x2ca138 tst r3, #1 */
/* @0x2ca13c bne 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650> */
/* @0x2ca140 ldr r7, [r4] */
/* @0x2ca144 ldr r3, [r7] */
/* @0x2ca148 cmp r3, #2 */
/* @0x2ca14c bne 0x2ca040 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x58c> */
/* @0x2ca150 ldrh r3, [r5, #4] */
/* @0x2ca154 tst r3, #8 */
/* @0x2ca158 bne 0x2ca040 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x58c> */
/* @0x2ca15c ldrh r3, [r7, #4] */
/* @0x2ca160 tst r3, #8 */
/* @0x2ca164 bne 0x2ca040 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x58c> */
/* @0x2ca168 ldr r4, [r4, #0xc] */
/* @0x2ca16c cmp r4, #0 */
/* @0x2ca170 bne 0x2ca110 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x65c> */
/* @0x2ca174 add r10, r10, #4 */
/* @0x2ca178 ldr r5, [sp, #0x14] */
/* @0x2ca17c cmp r10, #8 */
/* @0x2ca180 bne 0x2c9ff4 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x540> */
/* @0x2ca184 vmov.f32 s15, #1.000000e+00 */
/* @0x2ca188 ldr lr, [sp, #0x20] */
/* @0x2ca18c vldr s14, [lr] */
/* @0x2ca190 mov r2, #20 */
/* @0x2ca194 str r2, [sp, #0xc4] */
/* @0x2ca198 add r1, sp, #180 */
/* @0x2ca19c ldr r3, [lr, #0xc] */
/* @0x2ca1a0 add r0, sp, #128 */
/* @0x2ca1a4 mov r6, #0 */
/* @0x2ca1a8 str r3, [sp, #0xc0] */
/* @0x2ca1ac ldr r3, [r5, #0x8] */
/* @0x2ca1b0 ldr r2, [r9, #0x8] */
/* @0x2ca1b4 strb r6, [sp, #0xc8] */
/* @0x2ca1b8 vsub.f32 s16, s15, s16 */
/* @0x2ca1bc vstr s15, [sp, #188] */
/* @0x2ca1c0 vmul.f32 s16, s16, s14 */
/* @0x2ca1c4 vdiv.f32 s15, s15, s16 */
/* @0x2ca1c8 vstr s16, [sp, #180] */
/* @0x2ca1cc vstr s15, [sp, #184] */
/* @0x2ca1d0 bl 0x2e12c4 <_ZN8b2Island8SolveTOIERK10b2TimeStepii> */
/* @0x2ca1d4 ldr r1, [sp, #0x9c] */
/* @0x2ca1d8 cmp r1, r6 */
/* @0x2ca1dc movgt r5, r6 */
/* @0x2ca1e0 bgt 0x2ca1f4 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x740> */
/* @0x2ca1e4 b 0x2ca254 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7a0> */
/* @0x2ca1e8 add r5, r5, #1 */
/* @0x2ca1ec cmp r1, r5 */
/* @0x2ca1f0 ble 0x2ca254 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7a0> */
/* @0x2ca1f4 ldr r3, [sp, #0x88] */
/* @0x2ca1f8 ldr r4, [r3, r5, lsl #2] */
/* @0x2ca1fc ldr r2, [r4] */
/* @0x2ca200 ldrh r3, [r4, #4] */
/* @0x2ca204 cmp r2, #2 */
/* @0x2ca208 bic r3, r3, #1 */
/* @0x2ca20c strh r3, [r4, #4] */
/* @0x2ca210 bne 0x2ca1e8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x734> */
/* @0x2ca214 mov r0, r4 */
/* @0x2ca218 bl 0x2c72cc <_ZN6b2Body19SynchronizeFixturesEv> */
/* @0x2ca21c ldr r3, [r4, #0x80] */
/* @0x2ca220 cmp r3, #0 */
/* @0x2ca224 beq 0x2ca244 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x790> */
/* @0x2ca228 ldr r2, [r3, #0x4] */
/* @0x2ca22c ldr r3, [r3, #0xc] */
/* @0x2ca230 ldr r1, [r2, #0x4] */
/* @0x2ca234 cmp r3, #0 */
/* @0x2ca238 bic r1, r1, #33 */
/* @0x2ca23c str r1, [r2, #0x4] */
/* @0x2ca240 bne 0x2ca228 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x774> */
/* @0x2ca244 ldr r1, [sp, #0x9c] */
/* @0x2ca248 add r5, r5, #1 */
/* @0x2ca24c cmp r1, r5 */
/* @0x2ca250 bgt 0x2ca1f4 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x740> */
/* @0x2ca254 ldr r0, [sp, #0x2c] */
/* @0x2ca258 bl 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv> */
/* @0x2ca25c ldr r2, [sp, #0x10] */
/* @0x2ca260 ldr r1, [sp, #0x28] */
/* @0x2ca264 ldrb r3, [r2, r1] */
/* @0x2ca268 cmp r3, #0 */
/* @0x2ca26c bne 0x2ca4c8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa14> */
/* @0x2ca270 ldr lr, [sp, #0x10] */
/* @0x2ca274 movw r3, #0x9214 */
/* @0x2ca278 movt r3, #0x1 */
/* @0x2ca27c ldr r4, [lr, r3] */
/* @0x2ca280 cmp r4, #0 */
/* @0x2ca284 bne 0x2c9b58 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa4> */
/* @0x2ca288 ldr r1, [sp, #0x10] */
/* @0x2ca28c movw r3, #0x9253 */
/* @0x2ca290 movt r3, #0x1 */
/* @0x2ca294 mov r2, #1 */
/* @0x2ca298 strb r2, [r1, r3] */
/* @0x2ca29c b 0x2ca4dc <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa28> */
/* @0x2ca2a0 ldm r10!, {r0, r1, r2, r3} */
/* @0x2ca2a4 bic r12, r12, #36 */
/* @0x2ca2a8 ldr lr, [sp, #0x18] */
/* @0x2ca2ac mov r6, r9 */
/* @0x2ca2b0 str r12, [r8, #0x4] */
/* @0x2ca2b4 mov r12, r11 */
/* @0x2ca2b8 stm lr!, {r0, r1, r2, r3} */
/* @0x2ca2bc ldm r10!, {r0, r1, r2, r3} */
/* @0x2ca2c0 ldr r7, [r10] */
/* @0x2ca2c4 stm lr!, {r0, r1, r2, r3} */
/* @0x2ca2c8 str r7, [lr] */
/* @0x2ca2cc ldm r12!, {r0, r1, r2, r3} */
/* @0x2ca2d0 stm r6!, {r0, r1, r2, r3} */
/* @0x2ca2d4 ldm r12!, {r0, r1, r2, r3} */
/* @0x2ca2d8 stm r6!, {r0, r1, r2, r3} */
/* @0x2ca2dc ldr r3, [r12] */
/* @0x2ca2e0 ldr r7, [r4, #0x48] */
/* @0x2ca2e4 str r3, [r6] */
/* @0x2ca2e8 mov r0, r7 */
/* @0x2ca2ec bl 0xb6580 <sinf@plt> */
/* @0x2ca2f0 vmov s16, r0 */
/* @0x2ca2f4 mov r0, r7 */
/* @0x2ca2f8 vstr s16, [r4, #20] */
/* @0x2ca2fc bl 0xb658c <cosf@plt> */
/* @0x2ca300 vldr s15, [r4, #48] */
/* @0x2ca304 vmul.f32 s14, s15, s16 */
/* @0x2ca308 vldr s12, [r4, #44] */
/* @0x2ca30c vldr s11, [r4, #64] */
/* @0x2ca310 vldr s10, [r4, #60] */
/* @0x2ca314 vmov s13, r0 */
/* @0x2ca318 str r0, [r4, #0x18] */
/* @0x2ca31c vmul.f32 s15, s15, s13 */
/* @0x2ca320 vnmls.f32 s14, s12, s13 */
/* @0x2ca324 vmla.f32 s15, s12, s16 */
/* @0x2ca328 vsub.f32 s14, s10, s14 */
/* @0x2ca32c vsub.f32 s15, s11, s15 */
/* @0x2ca330 vstr s14, [r4, #12] */
/* @0x2ca334 vstr s15, [r4, #16] */
/* @0x2ca338 ldr r4, [r5, #0x48] */
/* @0x2ca33c mov r0, r4 */
/* @0x2ca340 bl 0xb6580 <sinf@plt> */
/* @0x2ca344 vmov s16, r0 */
/* @0x2ca348 mov r0, r4 */
/* @0x2ca34c vstr s16, [r5, #20] */
/* @0x2ca350 bl 0xb658c <cosf@plt> */
/* @0x2ca354 vldr s15, [r5, #48] */
/* @0x2ca358 vmul.f32 s14, s15, s16 */
/* @0x2ca35c vldr s12, [r5, #44] */
/* @0x2ca360 vldr s11, [r5, #64] */
/* @0x2ca364 vldr s10, [r5, #60] */
/* @0x2ca368 vmov s13, r0 */
/* @0x2ca36c str r0, [r5, #0x18] */
/* @0x2ca370 vmul.f32 s15, s15, s13 */
/* @0x2ca374 vnmls.f32 s14, s12, s13 */
/* @0x2ca378 vmla.f32 s15, s12, s16 */
/* @0x2ca37c vsub.f32 s14, s10, s14 */
/* @0x2ca380 vsub.f32 s15, s11, s15 */
/* @0x2ca384 vstr s14, [r5, #12] */
/* @0x2ca388 vstr s15, [r5, #16] */
/* @0x2ca38c b 0x2ca270 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x7bc> */
/* @0x2ca390 cmp r0, #0 */
/* @0x2ca394 beq 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0> */
/* @0x2ca398 b 0x2c9c10 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x15c> */
/* @0x2ca39c add r12, sp, #180 */
/* @0x2ca3a0 ldm r12!, {r0, r1, r2, r3} */
/* @0x2ca3a4 stm r8!, {r0, r1, r2, r3} */
/* @0x2ca3a8 ldm r12!, {r0, r1, r2, r3} */
/* @0x2ca3ac stm r8!, {r0, r1, r2, r3} */
/* @0x2ca3b0 ldr r3, [r12] */
/* @0x2ca3b4 ldr r6, [r7, #0x48] */
/* @0x2ca3b8 str r3, [r8] */
/* @0x2ca3bc mov r0, r6 */
/* @0x2ca3c0 bl 0xb6580 <sinf@plt> */
/* @0x2ca3c4 vmov s18, r0 */
/* @0x2ca3c8 mov r0, r6 */
/* @0x2ca3cc vstr s18, [r7, #20] */
/* @0x2ca3d0 bl 0xb658c <cosf@plt> */
/* @0x2ca3d4 vldr s15, [r7, #48] */
/* @0x2ca3d8 vmul.f32 s14, s15, s18 */
/* @0x2ca3dc vldr s12, [r7, #44] */
/* @0x2ca3e0 vldr s11, [r7, #64] */
/* @0x2ca3e4 vldr s10, [r7, #60] */
/* @0x2ca3e8 vmov s13, r0 */
/* @0x2ca3ec str r0, [r7, #0x18] */
/* @0x2ca3f0 vmul.f32 s15, s15, s13 */
/* @0x2ca3f4 vnmls.f32 s14, s12, s13 */
/* @0x2ca3f8 vmla.f32 s15, s12, s18 */
/* @0x2ca3fc vsub.f32 s14, s10, s14 */
/* @0x2ca400 vsub.f32 s15, s11, s15 */
/* @0x2ca404 vstr s14, [r7, #12] */
/* @0x2ca408 vstr s15, [r7, #16] */
/* @0x2ca40c b 0x2ca104 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x650> */
/* @0x2ca410 vldr s12, [r7, #76] */
/* @0x2ca414 vsub.f32 s15, s16, s12 */
/* @0x2ca418 vldr s13, [r7, #52] */
/* @0x2ca41c vldr s14, [r7, #56] */
/* @0x2ca420 vldr s10, [r7, #60] */
/* @0x2ca424 vldr s11, [r7, #64] */
/* @0x2ca428 vldr s9, [r7, #72] */
/* @0x2ca42c vldr s18, [r7, #68] */
/* @0x2ca430 add r2, r7, #52 */
/* @0x2ca434 add r3, r7, #60 */
/* @0x2ca438 vstr s16, [r7, #76] */
/* @0x2ca43c vsub.f32 s12, s17, s12 */
/* @0x2ca440 vdiv.f32 s15, s15, s12 */
/* @0x2ca444 vsub.f32 s10, s10, s13 */
/* @0x2ca448 vsub.f32 s11, s11, s14 */
/* @0x2ca44c vsub.f32 s12, s9, s18 */
/* @0x2ca450 vmla.f32 s13, s15, s10 */
/* @0x2ca454 vmla.f32 s14, s15, s11 */
/* @0x2ca458 vstr s13, [r7, #52] */
/* @0x2ca45c vmla.f32 s18, s15, s12 */
/* @0x2ca460 vstr s14, [r7, #56] */
/* @0x2ca464 ldm r2, {r0, r1} */
/* @0x2ca468 vstr s18, [r7, #68] */
/* @0x2ca46c stm r3, {r0, r1} */
/* @0x2ca470 vstr s18, [r7, #72] */
/* @0x2ca474 vmov r0, s18 */
/* @0x2ca478 bl 0xb6580 <sinf@plt> */
/* @0x2ca47c vmov s21, r0 */
/* @0x2ca480 vstr s21, [r7, #20] */
/* @0x2ca484 vmov r0, s18 */
/* @0x2ca488 bl 0xb658c <cosf@plt> */
/* @0x2ca48c vldr s15, [r7, #48] */
/* @0x2ca490 vmul.f32 s14, s15, s21 */
/* @0x2ca494 vldr s12, [r7, #44] */
/* @0x2ca498 vldr s11, [r7, #64] */
/* @0x2ca49c vldr s10, [r7, #60] */
/* @0x2ca4a0 vmov s13, r0 */
/* @0x2ca4a4 str r0, [r7, #0x18] */
/* @0x2ca4a8 vmul.f32 s15, s15, s13 */
/* @0x2ca4ac vnmls.f32 s14, s12, s13 */
/* @0x2ca4b0 vmla.f32 s15, s12, s21 */
/* @0x2ca4b4 vsub.f32 s14, s10, s14 */
/* @0x2ca4b8 vsub.f32 s15, s11, s15 */
/* @0x2ca4bc vstr s14, [r7, #12] */
/* @0x2ca4c0 vstr s15, [r7, #16] */
/* @0x2ca4c4 b 0x2ca088 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x5d4> */
/* @0x2ca4c8 ldr lr, [sp, #0x10] */
/* @0x2ca4cc movw r3, #0x9253 */
/* @0x2ca4d0 movt r3, #0x1 */
/* @0x2ca4d4 mov r2, #0 */
/* @0x2ca4d8 strb r2, [lr, r3] */
/* @0x2ca4dc add r0, sp, #128 */
/* @0x2ca4e0 bl 0x2e11d8 <_ZN8b2IslandD2Ev> */
/* @0x2ca4e4 add sp, sp, #316 */
/* @0x2ca4e8 vpop {d8, d9, d10} */
/* @0x2ca4ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ca4f0 ldr r1, [sp, #0x10] */
/* @0x2ca4f4 movw r3, #0x9228 */
/* @0x2ca4f8 movt r3, #0x1 */
/* @0x2ca4fc ldr r3, [r1, r3] */
/* @0x2ca500 cmp r3, #0 */
/* @0x2ca504 movne r1, #0 */
/* @0x2ca508 beq 0x2ca528 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa74> */
/* @0x2ca50c ldrh r2, [r3, #4] */
/* @0x2ca510 str r1, [r3, #0x4c] */
/* @0x2ca514 bic r2, r2, #1 */
/* @0x2ca518 strh r2, [r3, #4] */
/* @0x2ca51c ldr r3, [r3, #0x70] */
/* @0x2ca520 cmp r3, #0 */
/* @0x2ca524 bne 0x2ca50c <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa58> */
/* @0x2ca528 ldr r2, [sp, #0x10] */
/* @0x2ca52c movw r3, #0x9214 */
/* @0x2ca530 movt r3, #0x1 */
/* @0x2ca534 ldr r4, [r2, r3] */
/* @0x2ca538 cmp r4, #0 */
/* @0x2ca53c movne r0, #1065353216 */
/* @0x2ca540 movne r3, r4 */
/* @0x2ca544 movne r1, #0 */
/* @0x2ca548 beq 0x2c9b20 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c> */
/* @0x2ca54c ldr r2, [r3, #0x4] */
/* @0x2ca550 str r0, [r3, #0x84] */
/* @0x2ca554 str r1, [r3, #0x80] */
/* @0x2ca558 bic r2, r2, #33 */
/* @0x2ca55c str r2, [r3, #0x4] */
/* @0x2ca560 ldr r3, [r3, #0xc] */
/* @0x2ca564 cmp r3, #0 */
/* @0x2ca568 bne 0x2ca54c <_ZN7b2World8SolveTOIERK10b2TimeStep+0xa98> */
/* @0x2ca56c b 0x2c9b20 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x6c> */
/* @0x2ca570 vmov.f32 s8, #1.000000e+00 */
/* @0x2ca574 vstr s15, [r6, #76] */
/* @0x2ca578 vldr s12, [r6, #52] */
/* @0x2ca57c vldr s13, [r6, #56] */
/* @0x2ca580 vldr s14, [r6, #68] */
/* @0x2ca584 vldr s9, [r6, #60] */
/* @0x2ca588 vldr s10, [r6, #64] */
/* @0x2ca58c vldr s11, [r6, #72] */
/* @0x2ca590 vsub.f32 s8, s8, s17 */
/* @0x2ca594 vsub.f32 s7, s15, s17 */
/* @0x2ca598 vmov.f32 s17, s15 */
/* @0x2ca59c vdiv.f32 s15, s7, s8 */
/* @0x2ca5a0 vsub.f32 s9, s9, s12 */
/* @0x2ca5a4 vsub.f32 s10, s10, s13 */
/* @0x2ca5a8 vsub.f32 s11, s11, s14 */
/* @0x2ca5ac vmla.f32 s12, s15, s9 */
/* @0x2ca5b0 vmla.f32 s13, s15, s10 */
/* @0x2ca5b4 vstr s12, [r6, #52] */
/* @0x2ca5b8 vmla.f32 s14, s15, s11 */
/* @0x2ca5bc vstr s13, [r6, #56] */
/* @0x2ca5c0 vstr s14, [r6, #68] */
/* @0x2ca5c4 b 0x2c9c4c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x198> */
/* @0x2ca5c8 tst r1, #2 */
/* @0x2ca5cc vstreq s19, [r7, #160] */
/* @0x2ca5d0 orreq r1, r1, #3 */
/* @0x2ca5d4 strheq r1, [r7, #4] */
/* @0x2ca5d8 b 0x2ca0ec <_ZN7b2World8SolveTOIERK10b2TimeStep+0x638> */
/* @0x2ca5dc cmp r12, #0 */
/* @0x2ca5e0 beq 0x2c9b84 <_ZN7b2World8SolveTOIERK10b2TimeStep+0xd0> */
/* @0x2ca5e4 b 0x2c9c34 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x180> */
/* @0x2ca5e8 vsub.f32 s14, s18, s17 */
/* @0x2ca5ec vmla.f32 s17, s14, s15 */
/* @0x2ca5f0 vmov.f32 s15, s17 */
/* @0x2ca5f4 vcmpe.f32 s17, s18 */
/* @0x2ca5f8 vmrs APSR_nzcv, fpscr */
/* @0x2ca5fc vmovpl.f32 s15, s18 */
/* @0x2ca600 b 0x2c9cf8 <_ZN7b2World8SolveTOIERK10b2TimeStep+0x244> */
/* @0x2ca604 vmov.f32 s8, #1.000000e+00 */
/* @0x2ca608 vldr s12, [r7, #52] */
/* @0x2ca60c vldr s13, [r7, #56] */
/* @0x2ca610 vldr s14, [r7, #68] */
/* @0x2ca614 vldr s9, [r7, #60] */
/* @0x2ca618 vldr s10, [r7, #64] */
/* @0x2ca61c vldr s11, [r7, #72] */
/* @0x2ca620 vstr s17, [r7, #76] */
/* @0x2ca624 vsub.f32 s8, s8, s15 */
/* @0x2ca628 vsub.f32 s15, s17, s15 */
/* @0x2ca62c vdiv.f32 s15, s15, s8 */
/* @0x2ca630 vsub.f32 s9, s9, s12 */
/* @0x2ca634 vsub.f32 s10, s10, s13 */
/* @0x2ca638 vsub.f32 s11, s11, s14 */
/* @0x2ca63c vmla.f32 s12, s15, s9 */
/* @0x2ca640 vmla.f32 s13, s15, s10 */
/* @0x2ca644 vstr s12, [r7, #52] */
/* @0x2ca648 vmla.f32 s14, s15, s11 */
/* @0x2ca64c vstr s13, [r7, #56] */
/* @0x2ca650 vstr s14, [r7, #68] */
/* @0x2ca654 b 0x2c9c4c <_ZN7b2World8SolveTOIERK10b2TimeStep+0x198> */

/* ── FUNC 0x2ca658 · b2World::ClearForces() · size=52 · insn=13 */
/* @0x2ca658 movw r3, #0x9228 */
/* @0x2ca65c movt r3, #0x1 */
/* @0x2ca660 ldr r3, [r0, r3] */
/* @0x2ca664 cmp r3, #0 */
/* @0x2ca668 bxeq lr */
/* @0x2ca66c mov r2, #0 */
/* @0x2ca670 str r2, [r3, #0x5c] */
/* @0x2ca674 str r2, [r3, #0x60] */
/* @0x2ca678 str r2, [r3, #0x64] */
/* @0x2ca67c ldr r3, [r3, #0x70] */
/* @0x2ca680 cmp r3, #0 */
/* @0x2ca684 bne 0x2ca670 <_ZN7b2World11ClearForcesEv+0x18> */
/* @0x2ca688 bx lr */

/* ── FUNC 0x2ca68c · b2World::Step(float, int, int) · size=472 · insn=118 */
/* @0x2ca68c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2ca690 vpush {d8} */
/* @0x2ca694 sub sp, sp, #40 */
/* @0x2ca698 movw r5, #0x91d4 */
/* @0x2ca69c movt r5, #0x1 */
/* @0x2ca6a0 mov r4, r0 */
/* @0x2ca6a4 mov r0, sp */
/* @0x2ca6a8 mov r6, r3 */
/* @0x2ca6ac mov r10, r2 */
/* @0x2ca6b0 vmov s16, r1 */
/* @0x2ca6b4 bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2ca6b8 ldr r3, [r4, r5] */
/* @0x2ca6bc add r8, r4, #102400 */
/* @0x2ca6c0 add r9, r8, #472 */
/* @0x2ca6c4 tst r3, #1 */
/* @0x2ca6c8 bne 0x2ca850 <_ZN7b2World4StepEfii+0x1c4> */
/* @0x2ca6cc vcmpe.f32 s16, #0 */
/* @0x2ca6d0 add r5, r4, #102400 */
/* @0x2ca6d4 vstr s16, [sp, #16] */
/* @0x2ca6d8 add r5, r5, #588 */
/* @0x2ca6dc movw r1, #0x91d4 */
/* @0x2ca6e0 movt r1, #0x1 */
/* @0x2ca6e4 orr r3, r3, #2 */
/* @0x2ca6e8 str r6, [sp, #0x20] */
/* @0x2ca6ec vmrs APSR_nzcv, fpscr */
/* @0x2ca6f0 vmovgt.f32 s15, #1.000000e+00 */
/* @0x2ca6f4 str r3, [r4, r1] */
/* @0x2ca6f8 movw r3, #0x9250 */
/* @0x2ca6fc movt r3, #0x1 */
/* @0x2ca700 add r6, sp, #8 */
/* @0x2ca704 mov r2, #0 */
/* @0x2ca708 str r10, [sp, #0x1c] */
/* @0x2ca70c ldrb r3, [r4, r3] */
/* @0x2ca710 mov r0, r6 */
/* @0x2ca714 strle r2, [sp, #0x14] */
/* @0x2ca718 strb r3, [sp, #0x24] */
/* @0x2ca71c vdivgt.f32 s15, s15, s16 */
/* @0x2ca720 vstrgt s15, [sp, #20] */
/* @0x2ca724 vldr s15, [r5] */
/* @0x2ca728 vmul.f32 s16, s15, s16 */
/* @0x2ca72c vstr s16, [sp, #24] */
/* @0x2ca730 bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2ca734 mov r0, r9 */
/* @0x2ca738 bl 0x2c7970 <_ZN16b2ContactManager7CollideEv> */
/* @0x2ca73c mov r0, r6 */
/* @0x2ca740 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2ca744 movw r2, #0x9253 */
/* @0x2ca748 movt r2, #0x1 */
/* @0x2ca74c add r3, r4, #102400 */
/* @0x2ca750 vldr s15, [sp, #16] */
/* @0x2ca754 ldrb r2, [r4, r2] */
/* @0x2ca758 cmp r2, #0 */
/* @0x2ca75c str r0, [r3, #0x258] */
/* @0x2ca760 beq 0x2ca7a8 <_ZN7b2World4StepEfii+0x11c> */
/* @0x2ca764 vcmpe.f32 s15, #0 */
/* @0x2ca768 vmrs APSR_nzcv, fpscr */
/* @0x2ca76c ble 0x2ca7a8 <_ZN7b2World4StepEfii+0x11c> */
/* @0x2ca770 mov r0, r6 */
/* @0x2ca774 bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2ca778 add r0, r8, #628 */
/* @0x2ca77c add r8, sp, #16 */
/* @0x2ca780 mov r1, r8 */
/* @0x2ca784 bl 0x2db370 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep> */
/* @0x2ca788 mov r0, r4 */
/* @0x2ca78c mov r1, r8 */
/* @0x2ca790 bl 0x2c963c <_ZN7b2World5SolveERK10b2TimeStep> */
/* @0x2ca794 mov r0, r6 */
/* @0x2ca798 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2ca79c add r3, r4, #102400 */
/* @0x2ca7a0 vldr s15, [sp, #16] */
/* @0x2ca7a4 str r0, [r3, #0x25c] */
/* @0x2ca7a8 movw r3, #0x9251 */
/* @0x2ca7ac movt r3, #0x1 */
/* @0x2ca7b0 ldrb r3, [r4, r3] */
/* @0x2ca7b4 cmp r3, #0 */
/* @0x2ca7b8 beq 0x2ca7f0 <_ZN7b2World4StepEfii+0x164> */
/* @0x2ca7bc vcmpe.f32 s15, #0 */
/* @0x2ca7c0 vmrs APSR_nzcv, fpscr */
/* @0x2ca7c4 ble 0x2ca7f0 <_ZN7b2World4StepEfii+0x164> */
/* @0x2ca7c8 mov r0, r6 */
/* @0x2ca7cc bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2ca7d0 mov r0, r4 */
/* @0x2ca7d4 add r1, sp, #16 */
/* @0x2ca7d8 bl 0x2c9ab4 <_ZN7b2World8SolveTOIERK10b2TimeStep> */
/* @0x2ca7dc mov r0, r6 */
/* @0x2ca7e0 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2ca7e4 add r3, r4, #102400 */
/* @0x2ca7e8 vldr s15, [sp, #16] */
/* @0x2ca7ec str r0, [r3, #0x270] */
/* @0x2ca7f0 vcmpe.f32 s15, #0 */
/* @0x2ca7f4 vmrs APSR_nzcv, fpscr */
/* @0x2ca7f8 ldrgt r3, [sp, #0x14] */
/* @0x2ca7fc strgt r3, [r5] */
/* @0x2ca800 movw r5, #0x91d4 */
/* @0x2ca804 movt r5, #0x1 */
/* @0x2ca808 ldr r3, [r4, r5] */
/* @0x2ca80c tst r3, #4 */
/* @0x2ca810 moveq r2, r3 */
/* @0x2ca814 beq 0x2ca824 <_ZN7b2World4StepEfii+0x198> */
/* @0x2ca818 mov r0, r4 */
/* @0x2ca81c bl 0x2ca658 <_ZN7b2World11ClearForcesEv> */
/* @0x2ca820 ldr r2, [r4, r5] */
/* @0x2ca824 movw r3, #0x91d4 */
/* @0x2ca828 movt r3, #0x1 */
/* @0x2ca82c bic r2, r2, #2 */
/* @0x2ca830 mov r0, sp */
/* @0x2ca834 str r2, [r4, r3] */
/* @0x2ca838 add r4, r4, #102400 */
/* @0x2ca83c bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2ca840 str r0, [r4, #0x254] */
/* @0x2ca844 add sp, sp, #40 */
/* @0x2ca848 vpop {d8} */
/* @0x2ca84c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2ca850 mov r0, r9 */
/* @0x2ca854 bl 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv> */
/* @0x2ca858 ldr r3, [r4, r5] */
/* @0x2ca85c bic r3, r3, #1 */
/* @0x2ca860 b 0x2ca6cc <_ZN7b2World4StepEfii+0x40> */

/* ── FUNC 0x2ca864 · b2World::DrawShape(b2Fixture*, b2Transform const&, b2Color const&) · size=728 · insn=182 */
/* @0x2ca864 ldr r12, [r1, #0xc] */
/* @0x2ca868 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ca86c mov r9, r3 */
/* @0x2ca870 ldr r3, [r12, #0x4] */
/* @0x2ca874 sub sp, sp, #92 */
/* @0x2ca878 mov r10, r0 */
/* @0x2ca87c mov r4, r2 */
/* @0x2ca880 cmp r3, #3 */
/* @0x2ca884 addls pc, pc, r3, lsl #2 */
/* @0x2ca888 b 0x2ca920 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0xbc> */
/* @0x2ca88c b 0x2caab8 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x254> */
/* @0x2ca890 b 0x2ca89c <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x38> */
/* @0x2ca894 b 0x2caa28 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x1c4> */
/* @0x2ca898 b 0x2ca928 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0xc4> */
/* @0x2ca89c vldr s11, [r12, #16] */
/* @0x2ca8a0 vldr s15, [r2, #12] */
/* @0x2ca8a4 vmul.f32 s10, s15, s11 */
/* @0x2ca8a8 vldr s13, [r12, #12] */
/* @0x2ca8ac vldr s14, [r2, #8] */
/* @0x2ca8b0 vldr s8, [r2, #4] */
/* @0x2ca8b4 movw r0, #0x9248 */
/* @0x2ca8b8 movt r0, #0x1 */
/* @0x2ca8bc vldr s9, [r2] */
/* @0x2ca8c0 mov r3, r9 */
/* @0x2ca8c4 ldr r0, [r10, r0] */
/* @0x2ca8c8 add r1, sp, #16 */
/* @0x2ca8cc add r2, sp, #24 */
/* @0x2ca8d0 ldr lr, [r0] */
/* @0x2ca8d4 ldr r4, [lr, #0x1c] */
/* @0x2ca8d8 vmla.f32 s10, s13, s14 */
/* @0x2ca8dc vmul.f32 s11, s14, s11 */
/* @0x2ca8e0 vnmls.f32 s11, s15, s13 */
/* @0x2ca8e4 vadd.f32 s10, s10, s8 */
/* @0x2ca8e8 vstr s10, [sp, #20] */
/* @0x2ca8ec vldr s13, [r12, #24] */
/* @0x2ca8f0 vmul.f32 s12, s15, s13 */
/* @0x2ca8f4 vmul.f32 s13, s14, s13 */
/* @0x2ca8f8 vadd.f32 s11, s11, s9 */
/* @0x2ca8fc vstr s11, [sp, #16] */
/* @0x2ca900 vldr s11, [r12, #20] */
/* @0x2ca904 vmla.f32 s12, s14, s11 */
/* @0x2ca908 vnmls.f32 s13, s15, s11 */
/* @0x2ca90c vadd.f32 s12, s8, s12 */
/* @0x2ca910 vadd.f32 s13, s9, s13 */
/* @0x2ca914 vstr s12, [sp, #28] */
/* @0x2ca918 vstr s13, [sp, #24] */
/* @0x2ca91c blx r4 */
/* @0x2ca920 add sp, sp, #92 */
/* @0x2ca924 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ca928 ldr r6, [r12, #0xc] */
/* @0x2ca92c vldr s11, [r2, #8] */
/* @0x2ca930 vldr s13, [r6, #4] */
/* @0x2ca934 vldr s12, [r2, #12] */
/* @0x2ca938 vmul.f32 s8, s11, s13 */
/* @0x2ca93c vldr s7, [r6] */
/* @0x2ca940 vldr s10, [r2] */
/* @0x2ca944 vldr s9, [r2, #4] */
/* @0x2ca948 ldr r12, [r12, #0x10] */
/* @0x2ca94c cmp r12, #1 */
/* @0x2ca950 str r12, [sp, #0xc] */
/* @0x2ca954 vmul.f32 s13, s12, s13 */
/* @0x2ca958 vnmls.f32 s8, s12, s7 */
/* @0x2ca95c vmla.f32 s13, s7, s11 */
/* @0x2ca960 vadd.f32 s8, s8, s10 */
/* @0x2ca964 vadd.f32 s13, s13, s9 */
/* @0x2ca968 vstr s8, [sp, #16] */
/* @0x2ca96c vstr s13, [sp, #20] */
/* @0x2ca970 ble 0x2ca920 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0xbc> */
/* @0x2ca974 movw r11, #0x9248 */
/* @0x2ca978 add r6, r6, #8 */
/* @0x2ca97c movt r11, #0x1 */
/* @0x2ca980 add r5, sp, #16 */
/* @0x2ca984 add r7, sp, #24 */
/* @0x2ca988 mov r8, #1 */
/* @0x2ca98c b 0x2ca9a0 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x13c> */
/* @0x2ca990 vldr s12, [r4, #12] */
/* @0x2ca994 vldr s11, [r4, #8] */
/* @0x2ca998 vldr s10, [r4] */
/* @0x2ca99c vldr s9, [r4, #4] */
/* @0x2ca9a0 vldr s15, [r6, #4] */
/* @0x2ca9a4 vmul.f32 s14, s15, s11 */
/* @0x2ca9a8 vldr s13, [r6] */
/* @0x2ca9ac ldr r0, [r10, r11] */
/* @0x2ca9b0 mov r1, r5 */
/* @0x2ca9b4 mov r2, r7 */
/* @0x2ca9b8 mov r3, r9 */
/* @0x2ca9bc add r8, r8, #1 */
/* @0x2ca9c0 ldr r12, [r0] */
/* @0x2ca9c4 add r6, r6, #8 */
/* @0x2ca9c8 ldr r12, [r12, #0x1c] */
/* @0x2ca9cc vmul.f32 s15, s15, s12 */
/* @0x2ca9d0 vnmls.f32 s14, s13, s12 */
/* @0x2ca9d4 vmla.f32 s15, s13, s11 */
/* @0x2ca9d8 vadd.f32 s14, s14, s10 */
/* @0x2ca9dc vadd.f32 s15, s15, s9 */
/* @0x2ca9e0 vstr s14, [sp, #24] */
/* @0x2ca9e4 vstr s15, [sp, #28] */
/* @0x2ca9e8 blx r12 */
/* @0x2ca9ec ldr r0, [r10, r11] */
/* @0x2ca9f0 mov r1, r5 */
/* @0x2ca9f4 mov r3, r9 */
/* @0x2ca9f8 movw r2, #0xcccd */
/* @0x2ca9fc movt r2, #0x3d4c */
/* @0x2caa00 ldr r12, [r0] */
/* @0x2caa04 ldr r12, [r12, #0x10] */
/* @0x2caa08 blx r12 */
/* @0x2caa0c ldr r3, [sp, #0xc] */
/* @0x2caa10 ldm r7, {r0, r1} */
/* @0x2caa14 cmp r8, r3 */
/* @0x2caa18 stm r5, {r0, r1} */
/* @0x2caa1c bne 0x2ca990 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x12c> */
/* @0x2caa20 add sp, sp, #92 */
/* @0x2caa24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2caa28 ldr r2, [r12, #0x94] */
/* @0x2caa2c add r7, sp, #24 */
/* @0x2caa30 cmp r2, #0 */
/* @0x2caa34 ble 0x2caa90 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x22c> */
/* @0x2caa38 add r1, r12, #20 */
/* @0x2caa3c mov r0, #0 */
/* @0x2caa40 mov r3, r7 */
/* @0x2caa44 vldr s11, [r4, #12] */
/* @0x2caa48 vldr s12, [r4, #8] */
/* @0x2caa4c vldr s9, [r4] */
/* @0x2caa50 vldr s10, [r4, #4] */
/* @0x2caa54 vldr s15, [r1, #4] */
/* @0x2caa58 vmul.f32 s14, s15, s12 */
/* @0x2caa5c vldr s13, [r1] */
/* @0x2caa60 add r0, r0, #1 */
/* @0x2caa64 cmp r0, r2 */
/* @0x2caa68 add r1, r1, #8 */
/* @0x2caa6c add r3, r3, #8 */
/* @0x2caa70 vmul.f32 s15, s15, s11 */
/* @0x2caa74 vnmls.f32 s14, s13, s11 */
/* @0x2caa78 vmla.f32 s15, s13, s12 */
/* @0x2caa7c vadd.f32 s14, s14, s9 */
/* @0x2caa80 vadd.f32 s15, s15, s10 */
/* @0x2caa84 vstr s14, [r3, #-8] */
/* @0x2caa88 vstr s15, [r3, #-4] */
/* @0x2caa8c bne 0x2caa54 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x1f0> */
/* @0x2caa90 movw r3, #0x9248 */
/* @0x2caa94 movt r3, #0x1 */
/* @0x2caa98 mov r1, r7 */
/* @0x2caa9c ldr r0, [r10, r3] */
/* @0x2caaa0 mov r3, r9 */
/* @0x2caaa4 ldr r12, [r0] */
/* @0x2caaa8 ldr r12, [r12, #0xc] */
/* @0x2caaac blx r12 */
/* @0x2caab0 add sp, sp, #92 */
/* @0x2caab4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2caab8 vldr s13, [r12, #16] */
/* @0x2caabc vldr s14, [r2, #12] */
/* @0x2caac0 vldr s15, [r2, #8] */
/* @0x2caac4 vmul.f32 s12, s14, s13 */
/* @0x2caac8 vldr s10, [r12, #12] */
/* @0x2caacc vldr s11, [pc, #100] */
/* @0x2caad0 vldr s8, [r2, #4] */
/* @0x2caad4 vldr s9, [r2] */
/* @0x2caad8 movw r2, #0x9248 */
/* @0x2caadc movt r2, #0x1 */
/* @0x2caae0 add r1, sp, #16 */
/* @0x2caae4 add r3, sp, #24 */
/* @0x2caae8 ldr r0, [r0, r2] */
/* @0x2caaec ldr lr, [r0] */
/* @0x2caaf0 vmul.f32 s13, s15, s13 */
/* @0x2caaf4 vmla.f32 s12, s10, s15 */
/* @0x2caaf8 vnmls.f32 s13, s14, s10 */
/* @0x2caafc vmov.f32 s10, s14 */
/* @0x2cab00 vmls.f32 s10, s15, s11 */
/* @0x2cab04 vmla.f32 s15, s14, s11 */
/* @0x2cab08 vadd.f32 s12, s12, s8 */
/* @0x2cab0c vadd.f32 s13, s13, s9 */
/* @0x2cab10 vstr s12, [sp, #20] */
/* @0x2cab14 vstr s13, [sp, #16] */
/* @0x2cab18 ldr r2, [r12, #0x8] */
/* @0x2cab1c str r9, [sp] */
/* @0x2cab20 ldr r12, [lr, #0x14] */
/* @0x2cab24 vstr s10, [sp, #24] */
/* @0x2cab28 vstr s15, [sp, #28] */
/* @0x2cab2c blx r12 */
/* @0x2cab30 add sp, sp, #92 */
/* @0x2cab34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cab38 andeq r0, r0, r0 */

/* ── FUNC 0x2cab3c · b2World::DrawJoint(b2Joint*) · size=440 · insn=110 */
/* @0x2cab3c ldr r2, [r1, #0x30] */
/* @0x2cab40 ldr r3, [r1, #0x34] */
/* @0x2cab44 add r2, r2, #12 */
/* @0x2cab48 ldr r12, [r1] */
/* @0x2cab4c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2cab50 mov r4, r1 */
/* @0x2cab54 sub sp, sp, #64 */
/* @0x2cab58 mov r9, r0 */
/* @0x2cab5c ldm r2, {r0, r1} */
/* @0x2cab60 add r3, r3, #12 */
/* @0x2cab64 add r6, sp, #4 */
/* @0x2cab68 ldr r2, [r12] */
/* @0x2cab6c add r5, sp, #12 */
/* @0x2cab70 add r8, sp, #20 */
/* @0x2cab74 stm r6, {r0, r1} */
/* @0x2cab78 add r7, sp, #28 */
/* @0x2cab7c ldm r3, {r0, r1} */
/* @0x2cab80 stm r5, {r0, r1} */
/* @0x2cab84 mov r1, r4 */
/* @0x2cab88 mov r0, r8 */
/* @0x2cab8c blx r2 */
/* @0x2cab90 ldr r3, [r4] */
/* @0x2cab94 mov r1, r4 */
/* @0x2cab98 mov r0, r7 */
/* @0x2cab9c ldr r3, [r3, #0x4] */
/* @0x2caba0 blx r3 */
/* @0x2caba4 ldr r3, [r4, #0x4] */
/* @0x2caba8 mov r1, #1056964608 */
/* @0x2cabac movw r2, #0xcccd */
/* @0x2cabb0 cmp r3, #4 */
/* @0x2cabb4 movt r2, #0x3f4c */
/* @0x2cabb8 str r1, [sp, #0x34] */
/* @0x2cabbc str r2, [sp, #0x38] */
/* @0x2cabc0 str r2, [sp, #0x3c] */
/* @0x2cabc4 beq 0x2cac6c <_ZN7b2World9DrawJointEP7b2Joint+0x130> */
/* @0x2cabc8 cmp r3, #5 */
/* @0x2cabcc beq 0x2cac38 <_ZN7b2World9DrawJointEP7b2Joint+0xfc> */
/* @0x2cabd0 cmp r3, #3 */
/* @0x2cabd4 beq 0x2cac40 <_ZN7b2World9DrawJointEP7b2Joint+0x104> */
/* @0x2cabd8 movw r4, #0x9248 */
/* @0x2cabdc movt r4, #0x1 */
/* @0x2cabe0 mov r1, r6 */
/* @0x2cabe4 add r6, sp, #52 */
/* @0x2cabe8 ldr r0, [r9, r4] */
/* @0x2cabec mov r2, r8 */
/* @0x2cabf0 mov r3, r6 */
/* @0x2cabf4 ldr r12, [r0] */
/* @0x2cabf8 ldr r12, [r12, #0x1c] */
/* @0x2cabfc blx r12 */
/* @0x2cac00 ldr r0, [r9, r4] */
/* @0x2cac04 mov r1, r8 */
/* @0x2cac08 mov r3, r6 */
/* @0x2cac0c mov r2, r7 */
/* @0x2cac10 ldr r12, [r0] */
/* @0x2cac14 ldr r12, [r12, #0x1c] */
/* @0x2cac18 blx r12 */
/* @0x2cac1c ldr r0, [r9, r4] */
/* @0x2cac20 mov r3, r6 */
/* @0x2cac24 mov r1, r5 */
/* @0x2cac28 mov r2, r7 */
/* @0x2cac2c ldr r12, [r0] */
/* @0x2cac30 ldr r12, [r12, #0x1c] */
/* @0x2cac34 blx r12 */
/* @0x2cac38 add sp, sp, #64 */
/* @0x2cac3c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2cac40 movw r3, #0x9248 */
/* @0x2cac44 movt r3, #0x1 */
/* @0x2cac48 mov r1, r8 */
/* @0x2cac4c mov r2, r7 */
/* @0x2cac50 ldr r0, [r9, r3] */
/* @0x2cac54 add r3, sp, #52 */
/* @0x2cac58 ldr r12, [r0] */
/* @0x2cac5c ldr r12, [r12, #0x1c] */
/* @0x2cac60 blx r12 */
/* @0x2cac64 add sp, sp, #64 */
/* @0x2cac68 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2cac6c add r10, sp, #36 */
/* @0x2cac70 add r6, sp, #44 */
/* @0x2cac74 mov r1, r4 */
/* @0x2cac78 movw r5, #0x9248 */
/* @0x2cac7c mov r0, r10 */
/* @0x2cac80 movt r5, #0x1 */
/* @0x2cac84 bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv> */
/* @0x2cac88 mov r1, r4 */
/* @0x2cac8c mov r0, r6 */
/* @0x2cac90 add r4, sp, #52 */
/* @0x2cac94 bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv> */
/* @0x2cac98 ldr r0, [r9, r5] */
/* @0x2cac9c mov r2, r8 */
/* @0x2caca0 mov r1, r10 */
/* @0x2caca4 mov r3, r4 */
/* @0x2caca8 ldr r12, [r0] */
/* @0x2cacac ldr r12, [r12, #0x1c] */
/* @0x2cacb0 blx r12 */
/* @0x2cacb4 ldr r0, [r9, r5] */
/* @0x2cacb8 mov r2, r7 */
/* @0x2cacbc mov r1, r6 */
/* @0x2cacc0 mov r3, r4 */
/* @0x2cacc4 ldr r12, [r0] */
/* @0x2cacc8 ldr r12, [r12, #0x1c] */
/* @0x2caccc blx r12 */
/* @0x2cacd0 ldr r0, [r9, r5] */
/* @0x2cacd4 mov r1, r10 */
/* @0x2cacd8 mov r2, r6 */
/* @0x2cacdc mov r3, r4 */
/* @0x2cace0 ldr r12, [r0] */
/* @0x2cace4 ldr r12, [r12, #0x1c] */
/* @0x2cace8 blx r12 */
/* @0x2cacec add sp, sp, #64 */
/* @0x2cacf0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2cacf4 · b2World::DrawParticleSystem(b2ParticleSystem const&) · size=168 · insn=42 */
/* @0x2cacf4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2cacf8 mov r4, r1 */
/* @0x2cacfc ldr r5, [r1, #0x24] */
/* @0x2cad00 sub sp, sp, #8 */
/* @0x2cad04 mov r6, r0 */
/* @0x2cad08 cmp r5, #0 */
/* @0x2cad0c bne 0x2cad18 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem+0x24> */
/* @0x2cad10 add sp, sp, #8 */
/* @0x2cad14 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2cad18 mov r0, r1 */
/* @0x2cad1c bl 0x2d82d4 <_ZNK16b2ParticleSystem17GetParticleRadiusEv> */
/* @0x2cad20 mov r7, r0 */
/* @0x2cad24 mov r0, r4 */
/* @0x2cad28 bl 0x2d990c <_ZNK16b2ParticleSystem25GetParticlePositionBufferEv> */
/* @0x2cad2c ldr r3, [r4, #0x54] */
/* @0x2cad30 cmp r3, #0 */
/* @0x2cad34 mov r8, r0 */
/* @0x2cad38 beq 0x2cad74 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem+0x80> */
/* @0x2cad3c mov r0, r4 */
/* @0x2cad40 bl 0x2d991c <_ZNK16b2ParticleSystem22GetParticleColorBufferEv> */
/* @0x2cad44 movw r12, #0x9248 */
/* @0x2cad48 movt r12, #0x1 */
/* @0x2cad4c mov r1, r8 */
/* @0x2cad50 mov r2, r7 */
/* @0x2cad54 mov r3, r0 */
/* @0x2cad58 ldr r0, [r6, r12] */
/* @0x2cad5c ldr lr, [r0] */
/* @0x2cad60 str r5, [sp] */
/* @0x2cad64 ldr r12, [lr, #0x18] */
/* @0x2cad68 blx r12 */
/* @0x2cad6c add sp, sp, #8 */
/* @0x2cad70 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2cad74 movw r0, #0x9248 */
/* @0x2cad78 movt r0, #0x1 */
/* @0x2cad7c mov r1, r8 */
/* @0x2cad80 mov r2, r7 */
/* @0x2cad84 ldr r0, [r6, r0] */
/* @0x2cad88 ldr r12, [r0] */
/* @0x2cad8c str r5, [sp] */
/* @0x2cad90 ldr r12, [r12, #0x18] */
/* @0x2cad94 blx r12 */
/* @0x2cad98 b 0x2cad10 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem+0x1c> */

/* ── FUNC 0x2cad9c · b2World::DrawDebugData() · size=872 · insn=218 */
/* @0x2cad9c movw r3, #0x9248 */
/* @0x2cada0 movt r3, #0x1 */
/* @0x2cada4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2cada8 vpush {d8} */
/* @0x2cadac mov r7, r0 */
/* @0x2cadb0 ldr r0, [r0, r3] */
/* @0x2cadb4 sub sp, sp, #60 */
/* @0x2cadb8 cmp r0, #0 */
/* @0x2cadbc beq 0x2cb0b8 <_ZN7b2World13DrawDebugDataEv+0x31c> */
/* @0x2cadc0 bl 0x2c67e0 <_ZNK6b2Draw8GetFlagsEv> */
/* @0x2cadc4 tst r0, #1 */
/* @0x2cadc8 str r0, [sp, #0x4] */
/* @0x2cadcc beq 0x2caecc <_ZN7b2World13DrawDebugDataEv+0x130> */
/* @0x2cadd0 movw r3, #0x9228 */
/* @0x2cadd4 movt r3, #0x1 */
/* @0x2cadd8 ldr r5, [r7, r3] */
/* @0x2caddc cmp r5, #0 */
/* @0x2cade0 beq 0x2caebc <_ZN7b2World13DrawDebugDataEv+0x120> */
/* @0x2cade4 movw r11, #0x6666 */
/* @0x2cade8 movw r10, #0x999a */
/* @0x2cadec add r8, sp, #24 */
/* @0x2cadf0 movt r11, #0x3f66 */
/* @0x2cadf4 movt r10, #0x3f19 */
/* @0x2cadf8 mov r9, #1056964608 */
/* @0x2cadfc vldr s16, [pc, #760] */
/* @0x2cae00 vldr s17, [pc, #760] */
/* @0x2cae04 ldr r4, [r5, #0x74] */
/* @0x2cae08 add r6, r5, #12 */
/* @0x2cae0c cmp r4, #0 */
/* @0x2cae10 bne 0x2cae78 <_ZN7b2World13DrawDebugDataEv+0xdc> */
/* @0x2cae14 b 0x2caeb0 <_ZN7b2World13DrawDebugDataEv+0x114> */
/* @0x2cae18 ldr lr, [r5] */
/* @0x2cae1c cmp lr, #0 */
/* @0x2cae20 beq 0x2cb0c4 <_ZN7b2World13DrawDebugDataEv+0x328> */
/* @0x2cae24 cmp lr, #1 */
/* @0x2cae28 mov r1, r4 */
/* @0x2cae2c mov r0, r7 */
/* @0x2cae30 mov r2, r6 */
/* @0x2cae34 mov r3, r8 */
/* @0x2cae38 beq 0x2cb0e8 <_ZN7b2World13DrawDebugDataEv+0x34c> */
/* @0x2cae3c tst r12, #2 */
/* @0x2cae40 streq r10, [sp, #0x18] */
/* @0x2cae44 streq r10, [sp, #0x1c] */
/* @0x2cae48 vstrne s16, [sp, #28] */
/* @0x2cae4c moveq r0, r7 */
/* @0x2cae50 moveq r1, r4 */
/* @0x2cae54 moveq r2, r6 */
/* @0x2cae58 moveq r3, r8 */
/* @0x2cae5c streq r10, [sp, #0x20] */
/* @0x2cae60 vstrne s16, [sp, #32] */
/* @0x2cae64 strne r11, [sp, #0x18] */
/* @0x2cae68 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color> */
/* @0x2cae6c ldr r4, [r4, #0x4] */
/* @0x2cae70 cmp r4, #0 */
/* @0x2cae74 beq 0x2caeb0 <_ZN7b2World13DrawDebugDataEv+0x114> */
/* @0x2cae78 ldrh r12, [r5, #4] */
/* @0x2cae7c tst r12, #32 */
/* @0x2cae80 bne 0x2cae18 <_ZN7b2World13DrawDebugDataEv+0x7c> */
/* @0x2cae84 mov r1, r4 */
/* @0x2cae88 mov r0, r7 */
/* @0x2cae8c mov r2, r6 */
/* @0x2cae90 mov r3, r8 */
/* @0x2cae94 str r9, [sp, #0x18] */
/* @0x2cae98 vstr s17, [sp, #32] */
/* @0x2cae9c str r9, [sp, #0x1c] */
/* @0x2caea0 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color> */
/* @0x2caea4 ldr r4, [r4, #0x4] */
/* @0x2caea8 cmp r4, #0 */
/* @0x2caeac bne 0x2cae78 <_ZN7b2World13DrawDebugDataEv+0xdc> */
/* @0x2caeb0 ldr r5, [r5, #0x70] */
/* @0x2caeb4 cmp r5, #0 */
/* @0x2caeb8 bne 0x2cae04 <_ZN7b2World13DrawDebugDataEv+0x68> */
/* @0x2caebc add r1, r7, #102400 */
/* @0x2caec0 mov r0, r7 */
/* @0x2caec4 add r1, r1, #628 */
/* @0x2caec8 bl 0x2cacf4 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem> */
/* @0x2caecc ldr r2, [sp, #0x4] */
/* @0x2caed0 tst r2, #2 */
/* @0x2caed4 beq 0x2caf04 <_ZN7b2World13DrawDebugDataEv+0x168> */
/* @0x2caed8 movw r3, #0x922c */
/* @0x2caedc movt r3, #0x1 */
/* @0x2caee0 ldr r4, [r7, r3] */
/* @0x2caee4 cmp r4, #0 */
/* @0x2caee8 beq 0x2caf04 <_ZN7b2World13DrawDebugDataEv+0x168> */
/* @0x2caeec mov r1, r4 */
/* @0x2caef0 mov r0, r7 */
/* @0x2caef4 bl 0x2cab3c <_ZN7b2World9DrawJointEP7b2Joint> */
/* @0x2caef8 ldr r4, [r4, #0xc] */
/* @0x2caefc cmp r4, #0 */
/* @0x2caf00 bne 0x2caeec <_ZN7b2World13DrawDebugDataEv+0x150> */
/* @0x2caf04 ldr r3, [sp, #0x4] */
/* @0x2caf08 tst r3, #8 */
/* @0x2caf0c beq 0x2caf30 <_ZN7b2World13DrawDebugDataEv+0x194> */
/* @0x2caf10 movw r3, #0x9214 */
/* @0x2caf14 movt r3, #0x1 */
/* @0x2caf18 ldr r3, [r7, r3] */
/* @0x2caf1c cmp r3, #0 */
/* @0x2caf20 beq 0x2caf30 <_ZN7b2World13DrawDebugDataEv+0x194> */
/* @0x2caf24 ldr r3, [r3, #0xc] */
/* @0x2caf28 cmp r3, #0 */
/* @0x2caf2c bne 0x2caf24 <_ZN7b2World13DrawDebugDataEv+0x188> */
/* @0x2caf30 ldr r2, [sp, #0x4] */
/* @0x2caf34 tst r2, #4 */
/* @0x2caf38 beq 0x2cb050 <_ZN7b2World13DrawDebugDataEv+0x2b4> */
/* @0x2caf3c movw r3, #0x9228 */
/* @0x2caf40 movt r3, #0x1 */
/* @0x2caf44 movw r2, #0x6666 */
/* @0x2caf48 movw r1, #0x999a */
/* @0x2caf4c ldr r3, [r7, r3] */
/* @0x2caf50 movt r2, #0x3f66 */
/* @0x2caf54 movt r1, #0x3e99 */
/* @0x2caf58 str r2, [sp, #0xc] */
/* @0x2caf5c cmp r3, #0 */
/* @0x2caf60 str r2, [sp, #0x14] */
/* @0x2caf64 str r3, [sp] */
/* @0x2caf68 str r1, [sp, #0x10] */
/* @0x2caf6c beq 0x2cb050 <_ZN7b2World13DrawDebugDataEv+0x2b4> */
/* @0x2caf70 movw r11, #0x91dc */
/* @0x2caf74 movw r8, #0x9248 */
/* @0x2caf78 movt r11, #0x1 */
/* @0x2caf7c movt r8, #0x1 */
/* @0x2caf80 add r10, sp, #24 */
/* @0x2caf84 add r9, sp, #12 */
/* @0x2caf88 ldr r2, [sp] */
/* @0x2caf8c ldrh r3, [r2, #4] */
/* @0x2caf90 tst r3, #32 */
/* @0x2caf94 beq 0x2cb03c <_ZN7b2World13DrawDebugDataEv+0x2a0> */
/* @0x2caf98 ldr r6, [r2, #0x74] */
/* @0x2caf9c cmp r6, #0 */
/* @0x2cafa0 beq 0x2cb03c <_ZN7b2World13DrawDebugDataEv+0x2a0> */
/* @0x2cafa4 ldr r3, [r6, #0x1c] */
/* @0x2cafa8 cmp r3, #0 */
/* @0x2cafac ble 0x2cb030 <_ZN7b2World13DrawDebugDataEv+0x294> */
/* @0x2cafb0 mov r4, #0 */
/* @0x2cafb4 mov r5, r4 */
/* @0x2cafb8 ldr r3, [r6, #0x18] */
/* @0x2cafbc mov r1, r10 */
/* @0x2cafc0 ldr lr, [r7, r11] */
/* @0x2cafc4 mov r2, #4 */
/* @0x2cafc8 add r3, r3, r4 */
/* @0x2cafcc ldr r0, [r7, r8] */
/* @0x2cafd0 add r5, r5, #1 */
/* @0x2cafd4 add r4, r4, #28 */
/* @0x2cafd8 ldr r3, [r3, #0x18] */
/* @0x2cafdc ldr r12, [r0] */
/* @0x2cafe0 add r3, r3, r3, lsl #3 */
/* @0x2cafe4 ldr r12, [r12, #0x8] */
/* @0x2cafe8 add r3, lr, r3, lsl #2 */
/* @0x2cafec vldr s15, [r3] */
/* @0x2caff0 vldr s13, [r3, #4] */
/* @0x2caff4 vldr s14, [r3, #8] */
/* @0x2caff8 ldr lr, [r3, #0xc] */
/* @0x2caffc mov r3, r9 */
/* @0x2cb000 vstr s15, [sp, #24] */
/* @0x2cb004 vstr s13, [sp, #28] */
/* @0x2cb008 vstr s14, [sp, #32] */
/* @0x2cb00c vstr s13, [sp, #36] */
/* @0x2cb010 vstr s14, [sp, #40] */
/* @0x2cb014 str lr, [sp, #0x2c] */
/* @0x2cb018 vstr s15, [sp, #48] */
/* @0x2cb01c str lr, [sp, #0x34] */
/* @0x2cb020 blx r12 */
/* @0x2cb024 ldr r3, [r6, #0x1c] */
/* @0x2cb028 cmp r3, r5 */
/* @0x2cb02c bgt 0x2cafb8 <_ZN7b2World13DrawDebugDataEv+0x21c> */
/* @0x2cb030 ldr r6, [r6, #0x4] */
/* @0x2cb034 cmp r6, #0 */
/* @0x2cb038 bne 0x2cafa4 <_ZN7b2World13DrawDebugDataEv+0x208> */
/* @0x2cb03c ldr r3, [sp] */
/* @0x2cb040 ldr r3, [r3, #0x70] */
/* @0x2cb044 cmp r3, #0 */
/* @0x2cb048 str r3, [sp] */
/* @0x2cb04c bne 0x2caf88 <_ZN7b2World13DrawDebugDataEv+0x1ec> */
/* @0x2cb050 ldr r2, [sp, #0x4] */
/* @0x2cb054 tst r2, #16 */
/* @0x2cb058 beq 0x2cb0b8 <_ZN7b2World13DrawDebugDataEv+0x31c> */
/* @0x2cb05c movw r3, #0x9228 */
/* @0x2cb060 movt r3, #0x1 */
/* @0x2cb064 ldr r5, [r7, r3] */
/* @0x2cb068 cmp r5, #0 */
/* @0x2cb06c beq 0x2cb0b8 <_ZN7b2World13DrawDebugDataEv+0x31c> */
/* @0x2cb070 movw r8, #0x9248 */
/* @0x2cb074 add r4, sp, #24 */
/* @0x2cb078 movt r8, #0x1 */
/* @0x2cb07c add r3, r5, #12 */
/* @0x2cb080 ldr r12, [r7, r8] */
/* @0x2cb084 add lr, r5, #60 */
/* @0x2cb088 ldm r3, {r0, r1, r2, r3} */
/* @0x2cb08c ldr r6, [r12] */
/* @0x2cb090 stm r4, {r0, r1, r2, r3} */
/* @0x2cb094 ldm lr, {r0, r1} */
/* @0x2cb098 ldr r3, [r6, #0x20] */
/* @0x2cb09c stm r4, {r0, r1} */
/* @0x2cb0a0 mov r0, r12 */
/* @0x2cb0a4 mov r1, r4 */
/* @0x2cb0a8 blx r3 */
/* @0x2cb0ac ldr r5, [r5, #0x70] */
/* @0x2cb0b0 cmp r5, #0 */
/* @0x2cb0b4 bne 0x2cb07c <_ZN7b2World13DrawDebugDataEv+0x2e0> */
/* @0x2cb0b8 add sp, sp, #60 */
/* @0x2cb0bc vpop {d8} */
/* @0x2cb0c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2cb0c4 mov r0, r7 */
/* @0x2cb0c8 mov r1, r4 */
/* @0x2cb0cc mov r2, r6 */
/* @0x2cb0d0 mov r3, r8 */
/* @0x2cb0d4 str r9, [sp, #0x18] */
/* @0x2cb0d8 str r11, [sp, #0x1c] */
/* @0x2cb0dc str r9, [sp, #0x20] */
/* @0x2cb0e0 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color> */
/* @0x2cb0e4 b 0x2cae6c <_ZN7b2World13DrawDebugDataEv+0xd0> */
/* @0x2cb0e8 str r9, [sp, #0x18] */
/* @0x2cb0ec str r9, [sp, #0x1c] */
/* @0x2cb0f0 str r11, [sp, #0x20] */
/* @0x2cb0f4 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color> */
/* @0x2cb0f8 b 0x2cae6c <_ZN7b2World13DrawDebugDataEv+0xd0> */
/* @0x2cb0fc svclo #0x333333 */
/* @0x2cb100 mrclo p9, #0x4, r9, c9, c10, #0x4 */

/* ── FUNC 0x2cb104 · b2World::GetProxyCount() const · size=16 · insn=4 */
/* @0x2cb104 movw r3, #0x91f4 */
/* @0x2cb108 movt r3, #0x1 */
/* @0x2cb10c ldr r0, [r0, r3] */
/* @0x2cb110 bx lr */

/* ── FUNC 0x2cb114 · b2World::GetTreeHeight() const · size=12 · insn=3 */
/* @0x2cb114 add r0, r0, #102400 */
/* @0x2cb118 add r0, r0, #472 */
/* @0x2cb11c b 0x2df778 <_ZNK13b2DynamicTree9GetHeightEv> */

/* ── FUNC 0x2cb120 · b2World::GetTreeBalance() const · size=12 · insn=3 */
/* @0x2cb120 add r0, r0, #102400 */
/* @0x2cb124 add r0, r0, #472 */
/* @0x2cb128 b 0x2df980 <_ZNK13b2DynamicTree13GetMaxBalanceEv> */

/* ── FUNC 0x2cb12c · b2World::GetTreeQuality() const · size=12 · insn=3 */
/* @0x2cb12c add r0, r0, #102400 */
/* @0x2cb130 add r0, r0, #472 */
/* @0x2cb134 b 0x2df798 <_ZNK13b2DynamicTree12GetAreaRatioEv> */

/* ── FUNC 0x2cb138 · b2World::ShiftOrigin(b2Vec2 const&) · size=232 · insn=58 */
/* @0x2cb138 movw r3, #0x91d4 */
/* @0x2cb13c movt r3, #0x1 */
/* @0x2cb140 push {r4, r5, r6, lr} */
/* @0x2cb144 mov r6, r0 */
/* @0x2cb148 ldr r3, [r0, r3] */
/* @0x2cb14c mov r4, r1 */
/* @0x2cb150 tst r3, #2 */
/* @0x2cb154 popne {r4, r5, r6, pc} */
/* @0x2cb158 movw r3, #0x9228 */
/* @0x2cb15c movt r3, #0x1 */
/* @0x2cb160 ldr r3, [r0, r3] */
/* @0x2cb164 cmp r3, #0 */
/* @0x2cb168 beq 0x2cb1d8 <_ZN7b2World11ShiftOriginERK6b2Vec2+0xa0> */
/* @0x2cb16c vldr s15, [r4] */
/* @0x2cb170 vldr s10, [r4, #4] */
/* @0x2cb174 vldr s14, [r3, #12] */
/* @0x2cb178 vldr s9, [r3, #16] */
/* @0x2cb17c vsub.f32 s15, s14, s15 */
/* @0x2cb180 vldr s12, [r3, #52] */
/* @0x2cb184 vldr s11, [r3, #56] */
/* @0x2cb188 vldr s14, [r3, #60] */
/* @0x2cb18c vldr s13, [r3, #64] */
/* @0x2cb190 vsub.f32 s10, s9, s10 */
/* @0x2cb194 vstr s15, [r3, #12] */
/* @0x2cb198 vldr s15, [r4] */
/* @0x2cb19c vstr s10, [r3, #16] */
/* @0x2cb1a0 vsub.f32 s15, s12, s15 */
/* @0x2cb1a4 vldr s12, [r4, #4] */
/* @0x2cb1a8 vsub.f32 s12, s11, s12 */
/* @0x2cb1ac vstr s15, [r3, #52] */
/* @0x2cb1b0 vldr s15, [r4] */
/* @0x2cb1b4 vstr s12, [r3, #56] */
/* @0x2cb1b8 vsub.f32 s14, s14, s15 */
/* @0x2cb1bc vldr s15, [r4, #4] */
/* @0x2cb1c0 vsub.f32 s15, s13, s15 */
/* @0x2cb1c4 vstr s14, [r3, #60] */
/* @0x2cb1c8 vstr s15, [r3, #64] */
/* @0x2cb1cc ldr r3, [r3, #0x70] */
/* @0x2cb1d0 cmp r3, #0 */
/* @0x2cb1d4 bne 0x2cb16c <_ZN7b2World11ShiftOriginERK6b2Vec2+0x34> */
/* @0x2cb1d8 movw r3, #0x922c */
/* @0x2cb1dc movt r3, #0x1 */
/* @0x2cb1e0 ldr r5, [r6, r3] */
/* @0x2cb1e4 cmp r5, #0 */
/* @0x2cb1e8 beq 0x2cb20c <_ZN7b2World11ShiftOriginERK6b2Vec2+0xd4> */
/* @0x2cb1ec ldr r3, [r5] */
/* @0x2cb1f0 mov r0, r5 */
/* @0x2cb1f4 mov r1, r4 */
/* @0x2cb1f8 ldr r3, [r3, #0x14] */
/* @0x2cb1fc blx r3 */
/* @0x2cb200 ldr r5, [r5, #0xc] */
/* @0x2cb204 cmp r5, #0 */
/* @0x2cb208 bne 0x2cb1ec <_ZN7b2World11ShiftOriginERK6b2Vec2+0xb4> */
/* @0x2cb20c add r0, r6, #102400 */
/* @0x2cb210 mov r1, r4 */
/* @0x2cb214 add r0, r0, #472 */
/* @0x2cb218 pop {r4, r5, r6, lr} */
/* @0x2cb21c b 0x2dfc84 <_ZN13b2DynamicTree11ShiftOriginERK6b2Vec2> */

/* ── FUNC 0x2cb220 · b2World::Dump() · size=524 · insn=131 */
/* @0x2cb220 movw r3, #0x91d4 */
/* @0x2cb224 movt r3, #0x1 */
/* @0x2cb228 push {r4, r5, r6, r7, lr} */
/* @0x2cb22c mov r6, r0 */
/* @0x2cb230 ldr r5, [r0, r3] */
/* @0x2cb234 sub sp, sp, #12 */
/* @0x2cb238 ands r5, r5, #2 */
/* @0x2cb23c beq 0x2cb248 <_ZN7b2World4DumpEv+0x28> */
/* @0x2cb240 add sp, sp, #12 */
/* @0x2cb244 pop {r4, r5, r6, r7, pc} */
/* @0x2cb248 add r2, r0, #102400 */
/* @0x2cb24c vldr s14, [r2, #572] */
/* @0x2cb250 vcvt.f64.f32 d7, s14 */
/* @0x2cb254 ldr r0, [pc, #0x1a0] */
/* @0x2cb258 mov r3, r2 */
/* @0x2cb25c vldr s13, [r3, #568] */
/* @0x2cb260 add r0, pc, r0 */
/* @0x2cb264 vstr d7, [sp] */
/* @0x2cb268 vcvt.f64.f32 d7, s13 */
/* @0x2cb26c vmov r2, r3, d7 */
/* @0x2cb270 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb274 ldr r0, [pc, #0x184] */
/* @0x2cb278 add r0, pc, r0 */
/* @0x2cb27c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb280 movw r3, #0x9230 */
/* @0x2cb284 ldr r0, [pc, #0x178] */
/* @0x2cb288 movt r3, #0x1 */
/* @0x2cb28c add r0, pc, r0 */
/* @0x2cb290 ldr r1, [r6, r3] */
/* @0x2cb294 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb298 movw r3, #0x9234 */
/* @0x2cb29c ldr r0, [pc, #0x164] */
/* @0x2cb2a0 movt r3, #0x1 */
/* @0x2cb2a4 add r0, pc, r0 */
/* @0x2cb2a8 ldr r1, [r6, r3] */
/* @0x2cb2ac bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb2b0 movw r3, #0x9228 */
/* @0x2cb2b4 movt r3, #0x1 */
/* @0x2cb2b8 ldr r4, [r6, r3] */
/* @0x2cb2bc cmp r4, #0 */
/* @0x2cb2c0 beq 0x2cb2e0 <_ZN7b2World4DumpEv+0xc0> */
/* @0x2cb2c4 str r5, [r4, #0x8] */
/* @0x2cb2c8 mov r0, r4 */
/* @0x2cb2cc bl 0x2c75b4 <_ZN6b2Body4DumpEv> */
/* @0x2cb2d0 ldr r4, [r4, #0x70] */
/* @0x2cb2d4 add r5, r5, #1 */
/* @0x2cb2d8 cmp r4, #0 */
/* @0x2cb2dc bne 0x2cb2c4 <_ZN7b2World4DumpEv+0xa4> */
/* @0x2cb2e0 movw r3, #0x922c */
/* @0x2cb2e4 movt r3, #0x1 */
/* @0x2cb2e8 ldr r4, [r6, r3] */
/* @0x2cb2ec cmp r4, #0 */
/* @0x2cb2f0 movne r3, r4 */
/* @0x2cb2f4 movne r2, #0 */
/* @0x2cb2f8 beq 0x2cb3c4 <_ZN7b2World4DumpEv+0x1a4> */
/* @0x2cb2fc str r2, [r3, #0x38] */
/* @0x2cb300 add r2, r2, #1 */
/* @0x2cb304 ldr r3, [r3, #0xc] */
/* @0x2cb308 cmp r3, #0 */
/* @0x2cb30c bne 0x2cb2fc <_ZN7b2World4DumpEv+0xdc> */
/* @0x2cb310 ldr r5, [pc, #0xf4] */
/* @0x2cb314 ldr r7, [pc, #0xf4] */
/* @0x2cb318 add r5, pc, r5 */
/* @0x2cb31c add r7, pc, r7 */
/* @0x2cb320 ldr r3, [r4, #0x4] */
/* @0x2cb324 mov r0, r5 */
/* @0x2cb328 cmp r3, #6 */
/* @0x2cb32c beq 0x2cb34c <_ZN7b2World4DumpEv+0x12c> */
/* @0x2cb330 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb334 ldr r3, [r4] */
/* @0x2cb338 mov r0, r4 */
/* @0x2cb33c ldr r3, [r3, #0x10] */
/* @0x2cb340 blx r3 */
/* @0x2cb344 mov r0, r7 */
/* @0x2cb348 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb34c ldr r4, [r4, #0xc] */
/* @0x2cb350 cmp r4, #0 */
/* @0x2cb354 bne 0x2cb320 <_ZN7b2World4DumpEv+0x100> */
/* @0x2cb358 movw r3, #0x922c */
/* @0x2cb35c movt r3, #0x1 */
/* @0x2cb360 ldr r5, [pc, #0xac] */
/* @0x2cb364 ldr r4, [r6, r3] */
/* @0x2cb368 ldr r6, [pc, #0xa8] */
/* @0x2cb36c add r5, pc, r5 */
/* @0x2cb370 cmp r4, #0 */
/* @0x2cb374 add r6, pc, r6 */
/* @0x2cb378 bne 0x2cb38c <_ZN7b2World4DumpEv+0x16c> */
/* @0x2cb37c b 0x2cb3c4 <_ZN7b2World4DumpEv+0x1a4> */
/* @0x2cb380 ldr r4, [r4, #0xc] */
/* @0x2cb384 cmp r4, #0 */
/* @0x2cb388 beq 0x2cb3c4 <_ZN7b2World4DumpEv+0x1a4> */
/* @0x2cb38c ldr r3, [r4, #0x4] */
/* @0x2cb390 cmp r3, #6 */
/* @0x2cb394 bne 0x2cb380 <_ZN7b2World4DumpEv+0x160> */
/* @0x2cb398 mov r0, r6 */
/* @0x2cb39c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb3a0 ldr r3, [r4] */
/* @0x2cb3a4 mov r0, r4 */
/* @0x2cb3a8 ldr r3, [r3, #0x10] */
/* @0x2cb3ac blx r3 */
/* @0x2cb3b0 mov r0, r5 */
/* @0x2cb3b4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb3b8 ldr r4, [r4, #0xc] */
/* @0x2cb3bc cmp r4, #0 */
/* @0x2cb3c0 bne 0x2cb38c <_ZN7b2World4DumpEv+0x16c> */
/* @0x2cb3c4 ldr r0, [pc, #0x50] */
/* @0x2cb3c8 add r0, pc, r0 */
/* @0x2cb3cc bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb3d0 ldr r0, [pc, #0x48] */
/* @0x2cb3d4 add r0, pc, r0 */
/* @0x2cb3d8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb3dc ldr r0, [pc, #0x40] */
/* @0x2cb3e0 add r0, pc, r0 */
/* @0x2cb3e4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb3e8 ldr r0, [pc, #0x38] */
/* @0x2cb3ec add r0, pc, r0 */
/* @0x2cb3f0 add sp, sp, #12 */
/* @0x2cb3f4 pop {r4, r5, r6, r7, lr} */
/* @0x2cb3f8 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2cb3fc andeq r0, r9, r0, lsl #22 */
/* @0x2cb400 andeq r0, r9, r8, lsl #22 */
/* @0x2cb404 andeq r0, r9, r0, lsl r11 */
/* @0x2cb408 andeq r0, r9, r4, lsr r11 */
/* @0x2cb40c andeq r0, r9, r8, lsr r4 */
/* @0x2cb410 andeq r0, r9, r8, lsl r6 */
/* @0x2cb414 andeq r0, r9, r8, asr #11 */
/* @0x2cb418 ldrdeq r0, r1, [r9], -r12 */
/* @0x2cb41c andeq r0, r9, r0, asr r10 */
/* @0x2cb420 andeq r0, r9, r8, asr r10 */
/* @0x2cb424 andeq r0, r9, r0, ror #20 */
/* @0x2cb428 andeq r0, r9, r4, ror #20 */

/* ── FUNC 0x2cb42c · b2World::GetParticleMaxCount() const · size=12 · insn=3 */
/* @0x2cb42c add r0, r0, #102400 */
/* @0x2cb430 add r0, r0, #628 */
/* @0x2cb434 b 0x2d98f4 <_ZNK16b2ParticleSystem19GetParticleMaxCountEv> */

/* ── FUNC 0x2cb438 · b2World::SetParticleMaxCount(int) · size=12 · insn=3 */
/* @0x2cb438 add r0, r0, #102400 */
/* @0x2cb43c add r0, r0, #628 */
/* @0x2cb440 b 0x2d98fc <_ZN16b2ParticleSystem19SetParticleMaxCountEi> */

/* ── FUNC 0x2cb444 · b2World::SetParticleDensity(float) · size=12 · insn=3 */
/* @0x2cb444 add r0, r0, #102400 */
/* @0x2cb448 add r0, r0, #628 */
/* @0x2cb44c b 0x2d8294 <_ZN16b2ParticleSystem18SetParticleDensityEf> */

/* ── FUNC 0x2cb450 · b2World::GetParticleDensity() const · size=12 · insn=3 */
/* @0x2cb450 add r0, r0, #102400 */
/* @0x2cb454 add r0, r0, #628 */
/* @0x2cb458 b 0x2d82ac <_ZNK16b2ParticleSystem18GetParticleDensityEv> */

/* ── FUNC 0x2cb45c · b2World::SetParticleGravityScale(float) · size=12 · insn=3 */
/* @0x2cb45c add r0, r0, #102400 */
/* @0x2cb460 add r0, r0, #628 */
/* @0x2cb464 b 0x2d82b4 <_ZN16b2ParticleSystem23SetParticleGravityScaleEf> */

/* ── FUNC 0x2cb468 · b2World::GetParticleGravityScale() const · size=12 · insn=3 */
/* @0x2cb468 add r0, r0, #102400 */
/* @0x2cb46c add r0, r0, #628 */
/* @0x2cb470 b 0x2d82bc <_ZNK16b2ParticleSystem23GetParticleGravityScaleEv> */

/* ── FUNC 0x2cb474 · b2World::SetParticleDamping(float) · size=12 · insn=3 */
/* @0x2cb474 add r0, r0, #102400 */
/* @0x2cb478 add r0, r0, #628 */
/* @0x2cb47c b 0x2d82c4 <_ZN16b2ParticleSystem18SetParticleDampingEf> */

/* ── FUNC 0x2cb480 · b2World::GetParticleDamping() const · size=12 · insn=3 */
/* @0x2cb480 add r0, r0, #102400 */
/* @0x2cb484 add r0, r0, #628 */
/* @0x2cb488 b 0x2d82cc <_ZNK16b2ParticleSystem18GetParticleDampingEv> */

/* ── FUNC 0x2cb48c · b2World::SetParticleRadius(float) · size=12 · insn=3 */
/* @0x2cb48c add r0, r0, #102400 */
/* @0x2cb490 add r0, r0, #628 */
/* @0x2cb494 b 0x2d8270 <_ZN16b2ParticleSystem17SetParticleRadiusEf> */
