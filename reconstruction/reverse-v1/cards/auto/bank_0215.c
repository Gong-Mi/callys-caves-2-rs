/* libyoyo.so 覆盖卡组 0215
 * 函数 0x23be6c..0x23c748，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x23be6c · CRunnerContactListener::~CRunnerContactListener() · size=40 · insn=10 */
/* @0x23be6c ldr r3, [pc, #0x1c] */
/* @0x23be70 push {r4, lr} */
/* @0x23be74 ldr r3, [pc, r3] */
/* @0x23be78 mov r4, r0 */
/* @0x23be7c add r3, r3, #8 */
/* @0x23be80 str r3, [r0] */
/* @0x23be84 bl 0x27d1d0 <_ZdlPv> */
/* @0x23be88 mov r0, r4 */
/* @0x23be8c pop {r4, pc} */
/* @0x23be90 andseq r5, r11, r12, asr #12 */

/* ── FUNC 0x23be94 · CRunnerContactListener::PostSolve(b2Contact*, b2ContactImpulse const*) · size=8 · insn=2 */
/* @0x23be94 ldr r0, [r0, #0x4] */
/* @0x23be98 b 0x238204 <_ZN13CPhysicsWorld21RegisterContactResultEP9b2Contact> */

/* ── FUNC 0x23be9c · CRunnerContactListener::BeginContact(b2Contact*) · size=40 · insn=10 */
/* @0x23be9c ldr r3, [r1, #0x30] */
/* @0x23bea0 ldrb r3, [r3, #0x2c] */
/* @0x23bea4 cmp r3, #0 */
/* @0x23bea8 bne 0x23bebc <_ZN22CRunnerContactListener12BeginContactEP9b2Contact+0x20> */
/* @0x23beac ldr r3, [r1, #0x34] */
/* @0x23beb0 ldrb r3, [r3, #0x2c] */
/* @0x23beb4 cmp r3, #0 */
/* @0x23beb8 bxeq lr */
/* @0x23bebc ldr r0, [r0, #0x4] */
/* @0x23bec0 b 0x238204 <_ZN13CPhysicsWorld21RegisterContactResultEP9b2Contact> */

/* ── FUNC 0x23bec4 · ContactsStack::Push(b2Contact*) · size=612 · insn=153 */
/* @0x23bec4 ldr r3, [r1, #0x30] */
/* @0x23bec8 ldr r12, [r1, #0x34] */
/* @0x23becc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x23bed0 sub sp, sp, #752 */
/* @0x23bed4 ldr r2, [r3, #0x8] */
/* @0x23bed8 add r9, sp, #12 */
/* @0x23bedc ldr r3, [r3, #0xc] */
/* @0x23bee0 add r8, r1, #64 */
/* @0x23bee4 ldr lr, [r12, #0x8] */
/* @0x23bee8 mov r6, r1 */
/* @0x23beec mov r7, r0 */
/* @0x23bef0 mov r1, r8 */
/* @0x23bef4 ldr r3, [r3, #0x8] */
/* @0x23bef8 add lr, lr, #12 */
/* @0x23befc str lr, [sp] */
/* @0x23bf00 mov r0, r9 */
/* @0x23bf04 ldr r12, [r12, #0xc] */
/* @0x23bf08 add r2, r2, #12 */
/* @0x23bf0c ldr r12, [r12, #0x8] */
/* @0x23bf10 str r12, [sp, #0x4] */
/* @0x23bf14 bl 0x2c32c8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f> */
/* @0x23bf18 ldr r4, [r7, #0x4] */
/* @0x23bf1c ldr r5, [r6, #0x30] */
/* @0x23bf20 cmp r4, #0 */
/* @0x23bf24 ldrle r6, [r6, #0x34] */
/* @0x23bf28 ble 0x23bfc0 <_ZN13ContactsStack4PushEP9b2Contact+0xfc> */
/* @0x23bf2c mov r3, #0 */
/* @0x23bf30 ldr r6, [r6, #0x34] */
/* @0x23bf34 ldr r12, [r7] */
/* @0x23bf38 b 0x23bf50 <_ZN13ContactsStack4PushEP9b2Contact+0x8c> */
/* @0x23bf3c cmp r2, r6 */
/* @0x23bf40 beq 0x23bfa8 <_ZN13ContactsStack4PushEP9b2Contact+0xe4> */
/* @0x23bf44 cmp r3, r4 */
/* @0x23bf48 add r12, r12, #716 */
/* @0x23bf4c beq 0x23bfc0 <_ZN13ContactsStack4PushEP9b2Contact+0xfc> */
/* @0x23bf50 cmp r12, #0 */
/* @0x23bf54 add r3, r3, #1 */
/* @0x23bf58 beq 0x23bf44 <_ZN13ContactsStack4PushEP9b2Contact+0x80> */
/* @0x23bf5c ldr r2, [r12, #0x4] */
/* @0x23bf60 cmp r2, r5 */
/* @0x23bf64 bne 0x23bf3c <_ZN13ContactsStack4PushEP9b2Contact+0x78> */
/* @0x23bf68 ldr r1, [r12, #0x8] */
/* @0x23bf6c cmp r1, r6 */
/* @0x23bf70 bne 0x23bf3c <_ZN13ContactsStack4PushEP9b2Contact+0x78> */
/* @0x23bf74 ldr r3, [r12] */
/* @0x23bf78 cmp r3, #7 */
/* @0x23bf7c ble 0x23c054 <_ZN13ContactsStack4PushEP9b2Contact+0x190> */
/* @0x23bf80 ldr r3, [pc, #0x194] */
/* @0x23bf84 ldr r1, [pc, #0x194] */
/* @0x23bf88 ldr r3, [pc, r3] */
/* @0x23bf8c add r1, pc, r1 */
/* @0x23bf90 ldr r0, [r3] */
/* @0x23bf94 ldr r3, [r0] */
/* @0x23bf98 ldr r3, [r3, #0xc] */
/* @0x23bf9c blx r3 */
/* @0x23bfa0 add sp, sp, #752 */
/* @0x23bfa4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x23bfa8 ldr r2, [r12, #0x8] */
/* @0x23bfac cmp r2, r5 */
/* @0x23bfb0 beq 0x23bf74 <_ZN13ContactsStack4PushEP9b2Contact+0xb0> */
/* @0x23bfb4 cmp r3, r4 */
/* @0x23bfb8 add r12, r12, #716 */
/* @0x23bfbc bne 0x23bf50 <_ZN13ContactsStack4PushEP9b2Contact+0x8c> */
/* @0x23bfc0 add lr, sp, #48 */
/* @0x23bfc4 add r10, r8, #64 */
/* @0x23bfc8 mov r3, #0 */
/* @0x23bfcc str r5, [sp, #0x28] */
/* @0x23bfd0 str r6, [sp, #0x2c] */
/* @0x23bfd4 str r3, [sp, #0x24] */
/* @0x23bfd8 ldr r0, [r8] */
/* @0x23bfdc add r8, r8, #16 */
/* @0x23bfe0 ldr r1, [r8, #-0xc] */
/* @0x23bfe4 mov r12, lr */
/* @0x23bfe8 ldr r2, [r8, #-0x8] */
/* @0x23bfec add lr, lr, #16 */
/* @0x23bff0 ldr r3, [r8, #-0x4] */
/* @0x23bff4 cmp r8, r10 */
/* @0x23bff8 stm r12!, {r0, r1, r2, r3} */
/* @0x23bffc bne 0x23bfd8 <_ZN13ContactsStack4PushEP9b2Contact+0x114> */
/* @0x23c000 ldm r9!, {r0, r1, r2, r3} */
/* @0x23c004 add r12, sp, #560 */
/* @0x23c008 ldr r5, [r7, #0x8] */
/* @0x23c00c ldr lr, [sp, #0x24] */
/* @0x23c010 cmp r4, r5 */
/* @0x23c014 stm r12!, {r0, r1, r2, r3} */
/* @0x23c018 add lr, lr, #1 */
/* @0x23c01c ldm r9, {r0, r1} */
/* @0x23c020 str lr, [sp, #0x24] */
/* @0x23c024 stm r12, {r0, r1} */
/* @0x23c028 beq 0x23c0cc <_ZN13ContactsStack4PushEP9b2Contact+0x208> */
/* @0x23c02c ldr r0, [r7] */
/* @0x23c030 mov r2, #716 */
/* @0x23c034 add r1, sp, #36 */
/* @0x23c038 mla r0, r2, r4, r0 */
/* @0x23c03c bl 0xb65bc <memcpy@plt> */
/* @0x23c040 ldr r3, [r7, #0x4] */
/* @0x23c044 add r3, r3, #1 */
/* @0x23c048 str r3, [r7, #0x4] */
/* @0x23c04c add sp, sp, #752 */
/* @0x23c050 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x23c054 add r3, r12, r3, lsl #6 */
/* @0x23c058 add r2, r8, #64 */
/* @0x23c05c add r3, r3, #12 */
/* @0x23c060 ldr r5, [r8] */
/* @0x23c064 add r8, r8, #16 */
/* @0x23c068 ldr r4, [r8, #-0xc] */
/* @0x23c06c add r3, r3, #16 */
/* @0x23c070 ldr r0, [r8, #-0x8] */
/* @0x23c074 ldr r1, [r8, #-0x4] */
/* @0x23c078 cmp r8, r2 */
/* @0x23c07c str r5, [r3, #-0x10] */
/* @0x23c080 str r4, [r3, #-0xc] */
/* @0x23c084 str r0, [r3, #-0x8] */
/* @0x23c088 str r1, [r3, #-0x4] */
/* @0x23c08c bne 0x23c060 <_ZN13ContactsStack4PushEP9b2Contact+0x19c> */
/* @0x23c090 ldr r4, [r12] */
/* @0x23c094 ldm r9!, {r0, r1, r2, r3} */
/* @0x23c098 add r4, r4, r4, lsl #1 */
/* @0x23c09c add r5, r12, r4, lsl #3 */
/* @0x23c0a0 str r0, [r5, #0x20c] */
/* @0x23c0a4 str r1, [r5, #0x210] */
/* @0x23c0a8 str r2, [r5, #0x214] */
/* @0x23c0ac str r3, [r5, #0x218] */
/* @0x23c0b0 ldm r9!, {r0, r1} */
/* @0x23c0b4 str r0, [r5, #0x21c] */
/* @0x23c0b8 str r1, [r5, #0x220] */
/* @0x23c0bc ldr r3, [r12] */
/* @0x23c0c0 add r3, r3, #1 */
/* @0x23c0c4 str r3, [r12] */
/* @0x23c0c8 b 0x23bfa0 <_ZN13ContactsStack4PushEP9b2Contact+0xdc> */
/* @0x23c0cc add r5, r4, #10 */
/* @0x23c0d0 ldr r1, [pc, #0x4c] */
/* @0x23c0d4 mov r4, #716 */
/* @0x23c0d8 mov r3, #1 */
/* @0x23c0dc add r1, pc, r1 */
/* @0x23c0e0 mov r2, #40 */
/* @0x23c0e4 mul r0, r4, r5 */
/* @0x23c0e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x23c0ec ldr r2, [r7, #0x8] */
/* @0x23c0f0 ldr r1, [r7] */
/* @0x23c0f4 mul r2, r4, r2 */
/* @0x23c0f8 mov r6, r0 */
/* @0x23c0fc bl 0xb65bc <memcpy@plt> */
/* @0x23c100 ldr r0, [r7] */
/* @0x23c104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23c108 ldr r4, [r7, #0x4] */
/* @0x23c10c mov r0, r6 */
/* @0x23c110 str r5, [r7, #0x8] */
/* @0x23c114 str r6, [r7] */
/* @0x23c118 b 0x23c030 <_ZN13ContactsStack4PushEP9b2Contact+0x16c> */
/* @0x23c11c andseq r1, r11, r12, lsl #15 */
/* @0x23c120 mulseq r1, r12, r3 */
/* @0x23c124 andseq r9, r1, r8, lsr #2 */

/* ── FUNC 0x23c128 · ContactsStack::Pop() · size=32 · insn=8 */
/* @0x23c128 ldm r0, {r2, r3} */
/* @0x23c12c cmp r3, #0 */
/* @0x23c130 subgt r3, r3, #1 */
/* @0x23c134 strgt r3, [r0, #0x4] */
/* @0x23c138 movgt r1, #716 */
/* @0x23c13c mlagt r0, r1, r3, r2 */
/* @0x23c140 movle r0, #0 */
/* @0x23c144 bx lr */

/* ── FUNC 0x23c148 · b2Draw::~b2Draw() · size=24 · insn=6 */
/* @0x23c148 ldr r3, [pc, #0xc] */
/* @0x23c14c ldr r3, [pc, r3] */
/* @0x23c150 add r3, r3, #8 */
/* @0x23c154 str r3, [r0] */
/* @0x23c158 bx lr */
/* @0x23c15c andseq r5, r11, r0, lsr #7 */

/* ── FUNC 0x23c148 · b2Draw::~b2Draw() · alias of the symbol above · insn=0 */

/* ── FUNC 0x23c160 · CPhysicsDebugRender::~CPhysicsDebugRender() · size=24 · insn=6 */
/* @0x23c160 ldr r3, [pc, #0xc] */
/* @0x23c164 ldr r3, [pc, r3] */
/* @0x23c168 add r3, r3, #8 */
/* @0x23c16c str r3, [r0] */
/* @0x23c170 bx lr */
/* @0x23c174 andseq r5, r11, r8, lsl #7 */

/* ── FUNC 0x23c160 · CPhysicsDebugRender::~CPhysicsDebugRender() · alias of the symbol above · insn=0 */

/* ── FUNC 0x23c178 · b2Draw::~b2Draw() · size=40 · insn=10 */
/* @0x23c178 ldr r3, [pc, #0x1c] */
/* @0x23c17c push {r4, lr} */
/* @0x23c180 ldr r3, [pc, r3] */
/* @0x23c184 mov r4, r0 */
/* @0x23c188 add r3, r3, #8 */
/* @0x23c18c str r3, [r0] */
/* @0x23c190 bl 0x27d1d0 <_ZdlPv> */
/* @0x23c194 mov r0, r4 */
/* @0x23c198 pop {r4, pc} */
/* @0x23c19c andseq r5, r11, r12, ror #6 */

/* ── FUNC 0x23c1a0 · CPhysicsDebugRender::~CPhysicsDebugRender() · size=40 · insn=10 */
/* @0x23c1a0 ldr r3, [pc, #0x1c] */
/* @0x23c1a4 push {r4, lr} */
/* @0x23c1a8 ldr r3, [pc, r3] */
/* @0x23c1ac mov r4, r0 */
/* @0x23c1b0 add r3, r3, #8 */
/* @0x23c1b4 str r3, [r0] */
/* @0x23c1b8 bl 0x27d1d0 <_ZdlPv> */
/* @0x23c1bc mov r0, r4 */
/* @0x23c1c0 pop {r4, pc} */
/* @0x23c1c4 andseq r5, r11, r4, asr #6 */

/* ── FUNC 0x23c1c8 · CPhysicsDebugRender::DrawTransform(b2Transform const&) · size=172 · insn=43 */
/* @0x23c1c8 push {r4, lr} */
/* @0x23c1cc vpush {d8, d9, d10, d11} */
/* @0x23c1d0 vmov.f32 s16, #1.000000e+00 */
/* @0x23c1d4 vldr s19, [r1] */
/* @0x23c1d8 ldr r3, [r0, #0x8] */
/* @0x23c1dc vldr s13, [r3, #96] */
/* @0x23c1e0 vldr s18, [r1, #4] */
/* @0x23c1e4 vldr s17, [pc, #132] */
/* @0x23c1e8 vldr s14, [r1, #12] */
/* @0x23c1ec vldr s15, [r1, #8] */
/* @0x23c1f0 mov r0, #255 */
/* @0x23c1f4 mov r4, r1 */
/* @0x23c1f8 vdiv.f32 s16, s16, s13 */
/* @0x23c1fc vmov.f32 s23, s19 */
/* @0x23c200 vmov.f32 s22, s18 */
/* @0x23c204 vmla.f32 s23, s14, s17 */
/* @0x23c208 vmla.f32 s22, s15, s17 */
/* @0x23c20c bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c210 vmul.f32 s21, s16, s19 */
/* @0x23c214 vmul.f32 s20, s16, s18 */
/* @0x23c218 vmov r0, s21 */
/* @0x23c21c vmul.f32 s23, s16, s23 */
/* @0x23c220 vmov r1, s20 */
/* @0x23c224 vmul.f32 s22, s16, s22 */
/* @0x23c228 vmov r2, s23 */
/* @0x23c22c vmov r3, s22 */
/* @0x23c230 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x23c234 vldr s14, [r4, #8] */
/* @0x23c238 vldr s15, [r4, #12] */
/* @0x23c23c vmls.f32 s19, s14, s17 */
/* @0x23c240 mov r0, #16711680 */
/* @0x23c244 vmla.f32 s18, s15, s17 */
/* @0x23c248 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c24c vmov r0, s21 */
/* @0x23c250 vmov r1, s20 */
/* @0x23c254 vmul.f32 s19, s16, s19 */
/* @0x23c258 vmul.f32 s18, s16, s18 */
/* @0x23c25c vmov r2, s19 */
/* @0x23c260 vmov r3, s18 */
/* @0x23c264 vpop {d8, d9, d10, d11} */
/* @0x23c268 pop {r4, lr} */
/* @0x23c26c b 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x23c270 cdplo p12, #0xc, c12, c12, c13, #0x6 */

/* ── FUNC 0x23c274 · CPhysicsDebugRender::DrawParticles(b2Vec2 const*, float, b2ParticleColor const*, int) · size=196 · insn=49 */
/* @0x23c274 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x23c278 vpush {d8, d9} */
/* @0x23c27c sub sp, sp, #12 */
/* @0x23c280 mov r9, r0 */
/* @0x23c284 vmov s17, r2 */
/* @0x23c288 ldr r7, [sp, #0x38] */
/* @0x23c28c cmp r7, #0 */
/* @0x23c290 ble 0x23c32c <_ZN19CPhysicsDebugRender13DrawParticlesEPK6b2Vec2fPK15b2ParticleColori+0xb8> */
/* @0x23c294 vmov.f32 s18, #1.000000e+00 */
/* @0x23c298 mov r4, r3 */
/* @0x23c29c mov r5, r1 */
/* @0x23c2a0 mov r6, #0 */
/* @0x23c2a4 mov r8, #1 */
/* @0x23c2a8 ldr r3, [r9, #0x8] */
/* @0x23c2ac vldr s16, [r3, #96] */
/* @0x23c2b0 ldrb r3, [r4, #0x2] */
/* @0x23c2b4 add r6, r6, #1 */
/* @0x23c2b8 ldrb r0, [r4, #0x3] */
/* @0x23c2bc add r5, r5, #8 */
/* @0x23c2c0 ldrb r1, [r4] */
/* @0x23c2c4 add r4, r4, #4 */
/* @0x23c2c8 ldrb r2, [r4, #-0x3] */
/* @0x23c2cc lsl r3, r3, #16 */
/* @0x23c2d0 orr r3, r3, r0, lsl #24 */
/* @0x23c2d4 vdiv.f32 s16, s18, s16 */
/* @0x23c2d8 orr r0, r3, r1 */
/* @0x23c2dc orr r0, r0, r2, lsl #8 */
/* @0x23c2e0 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c2e4 vldr s14, [r5, #-8] */
/* @0x23c2e8 vldr s15, [r5, #-4] */
/* @0x23c2ec str r8, [sp] */
/* @0x23c2f0 vsub.f32 s12, s14, s17 */
/* @0x23c2f4 vsub.f32 s13, s15, s17 */
/* @0x23c2f8 vadd.f32 s14, s14, s17 */
/* @0x23c2fc vadd.f32 s15, s17, s15 */
/* @0x23c300 vmul.f32 s12, s12, s16 */
/* @0x23c304 vmul.f32 s13, s13, s16 */
/* @0x23c308 vmov r0, s12 */
/* @0x23c30c vmul.f32 s14, s14, s16 */
/* @0x23c310 vmov r1, s13 */
/* @0x23c314 vmul.f32 s15, s15, s16 */
/* @0x23c318 vmov r2, s14 */
/* @0x23c31c vmov r3, s15 */
/* @0x23c320 bl 0x16b278 <_Z15GR_Draw_Ellipseffffb> */
/* @0x23c324 cmp r6, r7 */
/* @0x23c328 bne 0x23c2a8 <_ZN19CPhysicsDebugRender13DrawParticlesEPK6b2Vec2fPK15b2ParticleColori+0x34> */
/* @0x23c32c add sp, sp, #12 */
/* @0x23c330 vpop {d8, d9} */
/* @0x23c334 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x23c338 · CPhysicsDebugRender::TranslateColour(b2Color const&) · size=72 · insn=18 */
/* @0x23c338 vldr s15, [pc, #60] */
/* @0x23c33c vldr s13, [r1] */
/* @0x23c340 vldr s14, [r1, #4] */
/* @0x23c344 vmul.f32 s13, s13, s15 */
/* @0x23c348 vldr s12, [r1, #8] */
/* @0x23c34c vmul.f32 s14, s14, s15 */
/* @0x23c350 vmul.f32 s15, s12, s15 */
/* @0x23c354 vcvt.s32.f32 s13, s13 */
/* @0x23c358 vcvt.s32.f32 s14, s14 */
/* @0x23c35c vmov r0, s13 */
/* @0x23c360 vcvt.s32.f32 s15, s15 */
/* @0x23c364 vmov r1, s14 */
/* @0x23c368 vmov r2, s15 */
/* @0x23c36c uxtb r0, r0 */
/* @0x23c370 uxtb r1, r1 */
/* @0x23c374 uxtb r2, r2 */
/* @0x23c378 b 0x169d80 <_Z20GR_Draw_Create_Coloriii> */
/* @0x23c37c orrmi r0, r0, #0 */

/* ── FUNC 0x23c380 · CPhysicsDebugRender::DrawPolygon(b2Vec2 const*, int, b2Color const&) · size=156 · insn=39 */
/* @0x23c380 push {r3, r4, r5, r6, r7, lr} */
/* @0x23c384 vpush {d8} */
/* @0x23c388 vmov.f32 s16, #1.000000e+00 */
/* @0x23c38c mov r7, r1 */
/* @0x23c390 mov r1, r3 */
/* @0x23c394 mov r6, r2 */
/* @0x23c398 mov r4, r0 */
/* @0x23c39c bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color> */
/* @0x23c3a0 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c3a4 cmp r6, #0 */
/* @0x23c3a8 ldr r3, [r4, #0x8] */
/* @0x23c3ac vldr s15, [r3, #96] */
/* @0x23c3b0 vdiv.f32 s16, s16, s15 */
/* @0x23c3b4 ble 0x23c414 <_ZN19CPhysicsDebugRender11DrawPolygonEPK6b2Vec2iRK7b2Color+0x94> */
/* @0x23c3b8 mov r5, r7 */
/* @0x23c3bc mov r4, #0 */
/* @0x23c3c0 add r4, r4, #1 */
/* @0x23c3c4 mov r1, r6 */
/* @0x23c3c8 add r5, r5, #8 */
/* @0x23c3cc mov r0, r4 */
/* @0x23c3d0 bl 0x318dec <__aeabi_idivmod> */
/* @0x23c3d4 vldr s14, [r5, #-8] */
/* @0x23c3d8 vldr s15, [r5, #-4] */
/* @0x23c3dc vmul.f32 s14, s16, s14 */
/* @0x23c3e0 add r1, r7, r1, lsl #3 */
/* @0x23c3e4 vldr s13, [r1] */
/* @0x23c3e8 vmov r0, s14 */
/* @0x23c3ec vldr s14, [r1, #4] */
/* @0x23c3f0 vmul.f32 s13, s16, s13 */
/* @0x23c3f4 vmul.f32 s14, s16, s14 */
/* @0x23c3f8 vmov r2, s13 */
/* @0x23c3fc vmul.f32 s15, s16, s15 */
/* @0x23c400 vmov r3, s14 */
/* @0x23c404 vmov r1, s15 */
/* @0x23c408 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x23c40c cmp r4, r6 */
/* @0x23c410 bne 0x23c3c0 <_ZN19CPhysicsDebugRender11DrawPolygonEPK6b2Vec2iRK7b2Color+0x40> */
/* @0x23c414 vpop {d8} */
/* @0x23c418 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x23c41c · CPhysicsDebugRender::DrawSolidPolygon(b2Vec2 const*, int, b2Color const&) · size=180 · insn=45 */
/* @0x23c41c push {r4, r5, r6, r7, r8, lr} */
/* @0x23c420 vpush {d8} */
/* @0x23c424 vmov.f32 s16, #1.000000e+00 */
/* @0x23c428 sub sp, sp, #16 */
/* @0x23c42c mov r6, r1 */
/* @0x23c430 mov r1, r3 */
/* @0x23c434 mov r7, r2 */
/* @0x23c438 mov r4, r0 */
/* @0x23c43c bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color> */
/* @0x23c440 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c444 cmp r7, #2 */
/* @0x23c448 ldr r3, [r4, #0x8] */
/* @0x23c44c vldr s15, [r3, #96] */
/* @0x23c450 vdiv.f32 s16, s16, s15 */
/* @0x23c454 ble 0x23c4c4 <_ZN19CPhysicsDebugRender16DrawSolidPolygonEPK6b2Vec2iRK7b2Color+0xa8> */
/* @0x23c458 add r4, r6, #16 */
/* @0x23c45c mov r5, #2 */
/* @0x23c460 mov r8, #0 */
/* @0x23c464 vldr s11, [r4] */
/* @0x23c468 vldr s12, [r4, #-8] */
/* @0x23c46c vldr s13, [r4, #-4] */
/* @0x23c470 vldr s14, [r6] */
/* @0x23c474 vldr s15, [r6, #4] */
/* @0x23c478 add r5, r5, #1 */
/* @0x23c47c add r4, r4, #8 */
/* @0x23c480 vmul.f32 s11, s16, s11 */
/* @0x23c484 vmul.f32 s12, s16, s12 */
/* @0x23c488 vstr s11, [sp] */
/* @0x23c48c vldr s11, [r4, #-4] */
/* @0x23c490 str r8, [sp, #0x8] */
/* @0x23c494 vmul.f32 s11, s16, s11 */
/* @0x23c498 vmov r2, s12 */
/* @0x23c49c vmul.f32 s13, s16, s13 */
/* @0x23c4a0 vstr s11, [sp, #4] */
/* @0x23c4a4 vmul.f32 s14, s16, s14 */
/* @0x23c4a8 vmov r3, s13 */
/* @0x23c4ac vmul.f32 s15, s16, s15 */
/* @0x23c4b0 vmov r0, s14 */
/* @0x23c4b4 vmov r1, s15 */
/* @0x23c4b8 bl 0x16a6f0 <_Z16GR_Draw_Triangleffffffb> */
/* @0x23c4bc cmp r5, r7 */
/* @0x23c4c0 bne 0x23c464 <_ZN19CPhysicsDebugRender16DrawSolidPolygonEPK6b2Vec2iRK7b2Color+0x48> */
/* @0x23c4c4 add sp, sp, #16 */
/* @0x23c4c8 vpop {d8} */
/* @0x23c4cc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x23c4d0 · CPhysicsDebugRender::DrawCircle(b2Vec2 const&, float, b2Color const&) · size=132 · insn=33 */
/* @0x23c4d0 push {r4, r5, lr} */
/* @0x23c4d4 vpush {d8} */
/* @0x23c4d8 mov r4, r1 */
/* @0x23c4dc sub sp, sp, #12 */
/* @0x23c4e0 mov r1, r3 */
/* @0x23c4e4 vmov s16, r2 */
/* @0x23c4e8 mov r5, r0 */
/* @0x23c4ec bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color> */
/* @0x23c4f0 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c4f4 vmov.f32 s12, #1.000000e+00 */
/* @0x23c4f8 ldr r3, [r5, #0x8] */
/* @0x23c4fc vldr s15, [r3, #96] */
/* @0x23c500 vldr s13, [r4] */
/* @0x23c504 vldr s14, [r4, #4] */
/* @0x23c508 mov r3, #1 */
/* @0x23c50c str r3, [sp] */
/* @0x23c510 vdiv.f32 s15, s12, s15 */
/* @0x23c514 vsub.f32 s11, s13, s16 */
/* @0x23c518 vsub.f32 s12, s14, s16 */
/* @0x23c51c vadd.f32 s13, s13, s16 */
/* @0x23c520 vadd.f32 s16, s16, s14 */
/* @0x23c524 vmul.f32 s11, s11, s15 */
/* @0x23c528 vmul.f32 s12, s12, s15 */
/* @0x23c52c vmov r0, s11 */
/* @0x23c530 vmul.f32 s13, s13, s15 */
/* @0x23c534 vmov r1, s12 */
/* @0x23c538 vmul.f32 s16, s16, s15 */
/* @0x23c53c vmov r2, s13 */
/* @0x23c540 vmov r3, s16 */
/* @0x23c544 bl 0x16b278 <_Z15GR_Draw_Ellipseffffb> */
/* @0x23c548 add sp, sp, #12 */
/* @0x23c54c vpop {d8} */
/* @0x23c550 pop {r4, r5, pc} */

/* ── FUNC 0x23c554 · CPhysicsDebugRender::DrawSolidCircle(b2Vec2 const&, float, b2Vec2 const&, b2Color const&) · size=124 · insn=31 */
/* @0x23c554 push {r4, r5, r6, lr} */
/* @0x23c558 vpush {d8} */
/* @0x23c55c mov r4, r1 */
/* @0x23c560 ldr r1, [sp, #0x18] */
/* @0x23c564 vmov s16, r2 */
/* @0x23c568 mov r5, r0 */
/* @0x23c56c bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color> */
/* @0x23c570 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c574 vmov.f32 s12, #1.000000e+00 */
/* @0x23c578 ldr r3, [r5, #0x8] */
/* @0x23c57c vldr s15, [r3, #96] */
/* @0x23c580 vldr s13, [r4] */
/* @0x23c584 vldr s14, [r4, #4] */
/* @0x23c588 mov r3, #0 */
/* @0x23c58c str r3, [sp, #0x18] */
/* @0x23c590 vdiv.f32 s15, s12, s15 */
/* @0x23c594 vsub.f32 s11, s13, s16 */
/* @0x23c598 vsub.f32 s12, s14, s16 */
/* @0x23c59c vadd.f32 s13, s13, s16 */
/* @0x23c5a0 vadd.f32 s16, s16, s14 */
/* @0x23c5a4 vmul.f32 s16, s16, s15 */
/* @0x23c5a8 vmul.f32 s11, s11, s15 */
/* @0x23c5ac vmov r3, s16 */
/* @0x23c5b0 vpop {d8} */
/* @0x23c5b4 pop {r4, r5, r6, lr} */
/* @0x23c5b8 vmul.f32 s12, s12, s15 */
/* @0x23c5bc vmov r0, s11 */
/* @0x23c5c0 vmul.f32 s13, s13, s15 */
/* @0x23c5c4 vmov r1, s12 */
/* @0x23c5c8 vmov r2, s13 */
/* @0x23c5cc b 0x16b278 <_Z15GR_Draw_Ellipseffffb> */

/* ── FUNC 0x23c5d0 · CPhysicsDebugRender::DrawSegment(b2Vec2 const&, b2Vec2 const&, b2Color const&) · size=100 · insn=25 */
/* @0x23c5d0 push {r4, r5, r6, lr} */
/* @0x23c5d4 mov r4, r1 */
/* @0x23c5d8 mov r1, r3 */
/* @0x23c5dc mov r5, r2 */
/* @0x23c5e0 mov r6, r0 */
/* @0x23c5e4 bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color> */
/* @0x23c5e8 bl 0x169d98 <_Z21YYGML_draw_set_colourj> */
/* @0x23c5ec vmov.f32 s10, #1.000000e+00 */
/* @0x23c5f0 ldr r3, [r6, #0x8] */
/* @0x23c5f4 vldr s15, [r3, #96] */
/* @0x23c5f8 vldr s11, [r4] */
/* @0x23c5fc vldr s12, [r4, #4] */
/* @0x23c600 vldr s13, [r5] */
/* @0x23c604 vldr s14, [r5, #4] */
/* @0x23c608 pop {r4, r5, r6, lr} */
/* @0x23c60c vdiv.f32 s15, s10, s15 */
/* @0x23c610 vmul.f32 s11, s15, s11 */
/* @0x23c614 vmul.f32 s12, s15, s12 */
/* @0x23c618 vmov r0, s11 */
/* @0x23c61c vmul.f32 s13, s15, s13 */
/* @0x23c620 vmov r1, s12 */
/* @0x23c624 vmul.f32 s14, s15, s14 */
/* @0x23c628 vmov r2, s13 */
/* @0x23c62c vmov r3, s14 */
/* @0x23c630 b 0x16a21c <_Z12GR_Draw_Lineffff> */

/* ── FUNC 0x23c634 · COwnedObject::~COwnedObject() · size=24 · insn=6 */
/* @0x23c634 ldr r3, [pc, #0xc] */
/* @0x23c638 ldr r3, [pc, r3] */
/* @0x23c63c add r3, r3, #8 */
/* @0x23c640 str r3, [r0] */
/* @0x23c644 bx lr */
/* @0x23c648 ldrheq r4, [r11], -r8 */

/* ── FUNC 0x23c634 · COwnedObject::~COwnedObject() · alias of the symbol above · insn=0 */

/* ── FUNC 0x23c64c · F_JSThis(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x23c64c mov r3, #6 */
/* @0x23c650 str r1, [r0] */
/* @0x23c654 str r3, [r0, #0xc] */
/* @0x23c658 bx lr */

/* ── FUNC 0x23c65c · F_JSNull(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x23c65c mov r3, #0 */
/* @0x23c660 mov r2, #12 */
/* @0x23c664 str r3, [r0] */
/* @0x23c668 str r2, [r0, #0xc] */
/* @0x23c66c str r3, [r0, #0x4] */
/* @0x23c670 bx lr */

/* ── FUNC 0x23c674 · F_JSOther(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x23c674 mov r3, #6 */
/* @0x23c678 str r2, [r0] */
/* @0x23c67c str r3, [r0, #0xc] */
/* @0x23c680 bx lr */

/* ── FUNC 0x23c684 · F_JSGlobalScope(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x23c684 ldr r3, [pc, #0x14] */
/* @0x23c688 mov r2, #6 */
/* @0x23c68c str r2, [r0, #0xc] */
/* @0x23c690 ldr r3, [pc, r3] */
/* @0x23c694 ldr r3, [r3] */
/* @0x23c698 str r3, [r0] */
/* @0x23c69c bx lr */
/* @0x23c6a0 andseq r1, r11, r8, lsl r6 */

/* ── FUNC 0x23c6a4 · F_JSFinishCatch(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x23c6a4 ldr r2, [pc, #0x18] */
/* @0x23c6a8 mov r1, #0 */
/* @0x23c6ac ldr r3, [pc, #0x14] */
/* @0x23c6b0 ldr r2, [pc, r2] */
/* @0x23c6b4 ldr r3, [pc, r3] */
/* @0x23c6b8 strb r1, [r2] */
/* @0x23c6bc str r1, [r3] */
/* @0x23c6c0 bx lr */
/* @0x23c6c4 andseq r4, r11, r4, asr #28 */
/* @0x23c6c8 andseq r1, r11, r8, ror r6 */

/* ── FUNC 0x23c6cc · F_JS_Function_constructor(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x23c6cc bx lr */

/* ── FUNC 0x23c6d0 · JS_Function_prototype_Call(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x23c6d0 mov r3, #5 */
/* @0x23c6d4 str r3, [r0, #0xc] */
/* @0x23c6d8 bx lr */

/* ── FUNC 0x23c6dc · F_JS_Object_prototype_valueOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x23c6dc mov r3, #6 */
/* @0x23c6e0 str r1, [r0] */
/* @0x23c6e4 str r3, [r0, #0xc] */
/* @0x23c6e8 bx lr */

/* ── FUNC 0x23c6ec · COwnedObject::~COwnedObject() · size=40 · insn=10 */
/* @0x23c6ec ldr r3, [pc, #0x1c] */
/* @0x23c6f0 push {r4, lr} */
/* @0x23c6f4 ldr r3, [pc, r3] */
/* @0x23c6f8 mov r4, r0 */
/* @0x23c6fc add r3, r3, #8 */
/* @0x23c700 str r3, [r0] */
/* @0x23c704 bl 0x27d1d0 <_ZdlPv> */
/* @0x23c708 mov r0, r4 */
/* @0x23c70c pop {r4, pc} */
/* @0x23c710 ldrsheq r4, [r11], -r12 */

/* ── FUNC 0x23c714 · F_JSTryUnHook(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x23c714 ldr r3, [pc, #0x28] */
/* @0x23c718 ldr r3, [pc, r3] */
/* @0x23c71c ldr r3, [r3] */
/* @0x23c720 ldr r3, [r3, #0x28] */
/* @0x23c724 cmp r3, #0 */
/* @0x23c728 bxeq lr */
/* @0x23c72c ldr r0, [r3, #0x28] */
/* @0x23c730 cmp r0, #0 */
/* @0x23c734 bxeq lr */
/* @0x23c738 ldr r2, [r0] */
/* @0x23c73c str r2, [r3, #0x28] */
/* @0x23c740 b 0x27d1d0 <_ZdlPv> */
/* @0x23c744 mulseq r11, r0, r4 */

/* ── FUNC 0x23c748 · C_UTF16String::~C_UTF16String() · size=72 · insn=18 */
/* @0x23c748 push {r4, lr} */
/* @0x23c74c mov r4, r0 */
/* @0x23c750 ldr r0, [r0, #0x4] */
/* @0x23c754 ldr r3, [pc, #0x2c] */
/* @0x23c758 cmp r0, #0 */
/* @0x23c75c ldr r3, [pc, r3] */
/* @0x23c760 add r3, r3, #8 */
/* @0x23c764 str r3, [r4] */
/* @0x23c768 beq 0x23c770 <_ZN13C_UTF16StringD2Ev+0x28> */
/* @0x23c76c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23c770 ldr r3, [pc, #0x14] */
/* @0x23c774 mov r0, r4 */
/* @0x23c778 ldr r3, [pc, r3] */
/* @0x23c77c add r3, r3, #8 */
/* @0x23c780 str r3, [r4] */
/* @0x23c784 pop {r4, pc} */
/* @0x23c788 mulseq r11, r12, sp */
/* @0x23c78c andseq r4, r11, r8, ror sp */
