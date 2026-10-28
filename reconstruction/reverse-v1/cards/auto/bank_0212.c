/* libyoyo.so 覆盖卡组 0212
 * 函数 0x237ad4..0x238c14，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x237ad4 · b2ContactListener::PreSolve(b2Contact*, b2Manifold const*) · size=4 · insn=1 */
/* @0x237ad4 bx lr */

/* ── FUNC 0x237ad8 · b2ContactListener::PostSolve(b2Contact*, b2ContactImpulse const*) · size=4 · insn=1 */
/* @0x237ad8 bx lr */

/* ── FUNC 0x237adc · b2ContactListener::~b2ContactListener() · size=40 · insn=10 */
/* @0x237adc ldr r3, [pc, #0x1c] */
/* @0x237ae0 push {r4, lr} */
/* @0x237ae4 ldr r3, [pc, r3] */
/* @0x237ae8 mov r4, r0 */
/* @0x237aec add r3, r3, #8 */
/* @0x237af0 str r3, [r0] */
/* @0x237af4 bl 0x27d1d0 <_ZdlPv> */
/* @0x237af8 mov r0, r4 */
/* @0x237afc pop {r4, pc} */
/* @0x237b00 ldrsbeq r9, [r11], -r12 */

/* ── FUNC 0x237b04 · anon_237b04 · size=116 · insn=29 */
/* @0x237b04 push {r4, r5, lr} */
/* @0x237b08 sub sp, sp, #1024 */
/* @0x237b0c ldr r4, [pc, #0x58] */
/* @0x237b10 sub sp, sp, #12 */
/* @0x237b14 add r5, sp, #4 */
/* @0x237b18 ldr r3, [pc, #0x50] */
/* @0x237b1c ldr r4, [pc, r4] */
/* @0x237b20 ldr r1, [pc, #0x4c] */
/* @0x237b24 mov r2, r0 */
/* @0x237b28 ldr r3, [pc, r3] */
/* @0x237b2c ldr r12, [r4] */
/* @0x237b30 add r1, pc, r1 */
/* @0x237b34 mov r0, r5 */
/* @0x237b38 str r12, [sp, #0x404] */
/* @0x237b3c bl 0xb6550 <sprintf@plt> */
/* @0x237b40 mov r0, r5 */
/* @0x237b44 mov r1, #0 */
/* @0x237b48 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x237b4c ldr r2, [sp, #0x404] */
/* @0x237b50 ldr r3, [r4] */
/* @0x237b54 cmp r2, r3 */
/* @0x237b58 bne 0x237b68 <_ZN17b2ContactListenerD0Ev+0x8c> */
/* @0x237b5c add sp, sp, #1024 */
/* @0x237b60 add sp, sp, #12 */
/* @0x237b64 pop {r4, r5, pc} */
/* @0x237b68 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x237b6c andseq r5, r11, r4, lsr lr */
/* @0x237b70 mulseq r11, r12, r9 */
/* @0x237b74 andseq sp, r1, r12, asr #13 */

/* ── FUNC 0x237b78 · yoyo_b2relassert(bool, wchar_t const*) · size=16 · insn=4 */
/* @0x237b78 cmp r0, #0 */
/* @0x237b7c bxne lr */
/* @0x237b80 mov r0, r1 */
/* @0x237b84 b 0x237b04 <_ZN17b2ContactListenerD0Ev+0x28> */

/* ── FUNC 0x237b88 · CPhysicsWorld::SetDebugMode() · size=52 · insn=13 */
/* @0x237b88 ldr r2, [pc, #0x20] */
/* @0x237b8c mov r0, #0 */
/* @0x237b90 ldr r3, [pc, #0x1c] */
/* @0x237b94 ldr r2, [pc, r2] */
/* @0x237b98 ldr r1, [pc, #0x18] */
/* @0x237b9c ldr r3, [pc, r3] */
/* @0x237ba0 ldr r1, [pc, r1] */
/* @0x237ba4 str r1, [r2] */
/* @0x237ba8 strb r0, [r3] */
/* @0x237bac bx lr */
/* @0x237bb0 andseq r9, r11, r4, lsr r9 */
/* @0x237bb4 andseq r9, r11, r8, lsr #18 */
/* @0x237bb8 andseq r9, r11, r12, lsr #18 */

/* ── FUNC 0x237bbc · CPhysicsWorld::SetTraceMsg(char*) · size=60 · insn=15 */
/* @0x237bbc ldr r3, [pc, #0x28] */
/* @0x237bc0 ldr r2, [pc, #0x28] */
/* @0x237bc4 ldr r3, [pc, r3] */
/* @0x237bc8 ldr r2, [pc, r2] */
/* @0x237bcc ldr r3, [r3] */
/* @0x237bd0 cmp r3, r2 */
/* @0x237bd4 bxne lr */
/* @0x237bd8 ldr r3, [pc, #0x14] */
/* @0x237bdc mov r1, r0 */
/* @0x237be0 movw r2, #0x1ff */
/* @0x237be4 ldr r0, [pc, r3] */
/* @0x237be8 b 0xb6568 <strncpy@plt> */
/* @0x237bec andseq r9, r11, r4, lsl #18 */
/* @0x237bf0 andseq r9, r11, r4, lsl #18 */
/* @0x237bf4 andseq r9, r11, r0, ror #17 */

/* ── FUNC 0x237bf8 · CPhysicsWorld::Init() · size=168 · insn=42 */
/* @0x237bf8 push {r3, r4, r5, lr} */
/* @0x237bfc mov r4, r0 */
/* @0x237c00 mov r3, #0 */
/* @0x237c04 mov r0, #8 */
/* @0x237c08 strb r3, [r4, #0x64] */
/* @0x237c0c str r3, [r4, #0xc] */
/* @0x237c10 str r3, [r4, #0x48] */
/* @0x237c14 str r3, [r4, #0x4c] */
/* @0x237c18 bl 0x27c524 <_Znwj> */
/* @0x237c1c ldr r2, [pc, #0x74] */
/* @0x237c20 ldr r2, [pc, r2] */
/* @0x237c24 add r2, r2, #8 */
/* @0x237c28 mov r3, r0 */
/* @0x237c2c str r4, [r0, #0x4] */
/* @0x237c30 mov r1, r0 */
/* @0x237c34 ldr r0, [r4, #0x10] */
/* @0x237c38 str r2, [r3] */
/* @0x237c3c str r3, [r4, #0x54] */
/* @0x237c40 bl 0x2c901c <_ZN7b2World18SetContactListenerEP17b2ContactListener> */
/* @0x237c44 mov r2, r4 */
/* @0x237c48 mov r3, #32 */
/* @0x237c4c mvn r1, #0 */
/* @0x237c50 subs r3, r3, #1 */
/* @0x237c54 str r1, [r2, #0x68] */
/* @0x237c58 add r2, r2, #12 */
/* @0x237c5c bne 0x237c50 <_ZN13CPhysicsWorld4InitEv+0x58> */
/* @0x237c60 mov r0, #12 */
/* @0x237c64 bl 0x27c524 <_Znwj> */
/* @0x237c68 mov r5, r0 */
/* @0x237c6c bl 0x2c67b8 <_ZN6b2DrawC2Ev> */
/* @0x237c70 ldr r3, [pc, #0x24] */
/* @0x237c74 mov r1, r5 */
/* @0x237c78 str r4, [r5, #0x8] */
/* @0x237c7c ldr r3, [pc, r3] */
/* @0x237c80 ldr r0, [r4, #0x10] */
/* @0x237c84 add r3, r3, #8 */
/* @0x237c88 str r3, [r5] */
/* @0x237c8c str r5, [r4, #0x50] */
/* @0x237c90 pop {r3, r4, r5, lr} */
/* @0x237c94 b 0x2c902c <_ZN7b2World12SetDebugDrawEP6b2Draw> */
/* @0x237c98 ldrheq r9, [r11], -r0 */
/* @0x237c9c andseq r9, r11, r8, asr r8 */

/* ── FUNC 0x237ca0 · CPhysicsWorld::CPhysicsWorld(float, int) · size=240 · insn=60 */
/* @0x237ca0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x237ca4 mov r9, r1 */
/* @0x237ca8 ldr r1, [pc, #0xd4] */
/* @0x237cac mov r4, r0 */
/* @0x237cb0 sub sp, sp, #12 */
/* @0x237cb4 mov r5, #0 */
/* @0x237cb8 mov r8, r2 */
/* @0x237cbc mov r6, #10 */
/* @0x237cc0 add r1, pc, r1 */
/* @0x237cc4 stmib r0, {r5, r6} */
/* @0x237cc8 mov r2, #55 */
/* @0x237ccc mov r3, #1 */
/* @0x237cd0 movw r0, #0x1bf8 */
/* @0x237cd4 add r10, r4, #28 */
/* @0x237cd8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x237cdc ldr r3, [pc, #0xa4] */
/* @0x237ce0 vmov.f32 s15, #1.000000e+00 */
/* @0x237ce4 ldr r12, [pc, #0xa0] */
/* @0x237ce8 ldr r3, [pc, r3] */
/* @0x237cec mov r1, #0 */
/* @0x237cf0 movt r1, #0x4120 */
/* @0x237cf4 str r1, [sp, #0x4] */
/* @0x237cf8 add r2, r4, #40 */
/* @0x237cfc ldr r12, [pc, r12] */
/* @0x237d00 mov lr, #0 */
/* @0x237d04 str r5, [r4, #0x14] */
/* @0x237d08 str r5, [r4, #0x18] */
/* @0x237d0c mov r7, #1 */
/* @0x237d10 lsl r11, r7, #16 */
/* @0x237d14 str lr, [sp] */
/* @0x237d18 str r0, [r4] */
/* @0x237d1c ldm r3, {r0, r1} */
/* @0x237d20 stm r10, {r0, r1} */
/* @0x237d24 str lr, [r4, #0x24] */
/* @0x237d28 stm r2, {r0, r1} */
/* @0x237d2c vstr s15, [r4, #56] */
/* @0x237d30 ldr r0, [r12] */
/* @0x237d34 str lr, [r4, #0x30] */
/* @0x237d38 str r5, [r4, #0x3c] */
/* @0x237d3c str r0, [r4, #0x34] */
/* @0x237d40 orr r0, r11, #37632 */
/* @0x237d44 str r5, [r4, #0x44] */
/* @0x237d48 orr r0, r0, #84 */
/* @0x237d4c str r9, [r4, #0x60] */
/* @0x237d50 str r6, [r4, #0x5c] */
/* @0x237d54 str r8, [r4, #0x58] */
/* @0x237d58 strb r7, [r4, #0x40] */
/* @0x237d5c bl 0x27c524 <_Znwj> */
/* @0x237d60 mov r1, sp */
/* @0x237d64 mov r5, r0 */
/* @0x237d68 bl 0x2c8e10 <_ZN7b2WorldC2ERK6b2Vec2> */
/* @0x237d6c mov r0, r4 */
/* @0x237d70 str r5, [r4, #0x10] */
/* @0x237d74 bl 0x237bf8 <_ZN13CPhysicsWorld4InitEv> */
/* @0x237d78 mov r0, r4 */
/* @0x237d7c add sp, sp, #12 */
/* @0x237d80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x237d84 andseq sp, r1, r4, asr #10 */
/* @0x237d88 ldrsheq r9, [r11], -r0 */
/* @0x237d8c andseq r9, r11, r0, ror #15 */

/* ── FUNC 0x237ca0 · CPhysicsWorld::CPhysicsWorld(float, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x237d90 · CPhysicsWorld::CPhysicsWorld(CPhysicsWorld*) · size=260 · insn=65 */
/* @0x237d90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x237d94 mov r6, r1 */
/* @0x237d98 ldr r1, [pc, #0xe8] */
/* @0x237d9c mov r4, r0 */
/* @0x237da0 sub sp, sp, #12 */
/* @0x237da4 mov r5, #0 */
/* @0x237da8 mov r3, #10 */
/* @0x237dac mov r2, #55 */
/* @0x237db0 str r3, [r0, #0x8] */
/* @0x237db4 add r1, pc, r1 */
/* @0x237db8 str r5, [r4, #0x4] */
/* @0x237dbc mov r3, #1 */
/* @0x237dc0 movw r0, #0x1bf8 */
/* @0x237dc4 add r8, r4, #28 */
/* @0x237dc8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x237dcc ldr r3, [pc, #0xb8] */
/* @0x237dd0 ldr r12, [pc, #0xb8] */
/* @0x237dd4 add r7, r4, #40 */
/* @0x237dd8 ldr r3, [pc, r3] */
/* @0x237ddc str r5, [r4, #0x14] */
/* @0x237de0 ldr r12, [pc, r12] */
/* @0x237de4 str r5, [r4, #0x18] */
/* @0x237de8 mov r10, #0 */
/* @0x237dec mov r2, #1 */
/* @0x237df0 movw lr, #0x9238 */
/* @0x237df4 bfi lr, r2, #16, #16 */
/* @0x237df8 lsl r9, r2, #16 */
/* @0x237dfc mov r11, #1065353216 */
/* @0x237e00 str r0, [r4] */
/* @0x237e04 ldm r3, {r0, r1} */
/* @0x237e08 stm r8, {r0, r1} */
/* @0x237e0c str r10, [r4, #0x24] */
/* @0x237e10 stm r7, {r0, r1} */
/* @0x237e14 ldr r0, [r12] */
/* @0x237e18 str r10, [r4, #0x30] */
/* @0x237e1c str r11, [r4, #0x38] */
/* @0x237e20 str r0, [r4, #0x34] */
/* @0x237e24 ldr r3, [r6, #0x10] */
/* @0x237e28 ldr r1, [r6, #0x60] */
/* @0x237e2c add lr, r3, lr */
/* @0x237e30 ldr r12, [r6, #0x5c] */
/* @0x237e34 ldr r3, [r6, #0x58] */
/* @0x237e38 str r1, [r4, #0x60] */
/* @0x237e3c ldm lr, {r0, r1} */
/* @0x237e40 strb r2, [r4, #0x40] */
/* @0x237e44 str r12, [r4, #0x5c] */
/* @0x237e48 stm sp, {r0, r1} */
/* @0x237e4c orr r0, r9, #37632 */
/* @0x237e50 str r3, [r4, #0x58] */
/* @0x237e54 orr r0, r0, #84 */
/* @0x237e58 str r5, [r4, #0x3c] */
/* @0x237e5c str r5, [r4, #0x44] */
/* @0x237e60 bl 0x27c524 <_Znwj> */
/* @0x237e64 mov r1, sp */
/* @0x237e68 mov r6, r0 */
/* @0x237e6c bl 0x2c8e10 <_ZN7b2WorldC2ERK6b2Vec2> */
/* @0x237e70 mov r0, r4 */
/* @0x237e74 str r6, [r4, #0x10] */
/* @0x237e78 bl 0x237bf8 <_ZN13CPhysicsWorld4InitEv> */
/* @0x237e7c mov r0, r4 */
/* @0x237e80 add sp, sp, #12 */
/* @0x237e84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x237e88 andseq sp, r1, r0, asr r4 */
/* @0x237e8c andseq r9, r11, r0, lsl #14 */
/* @0x237e90 ldrsheq r9, [r11], -r12 */

/* ── FUNC 0x237d90 · CPhysicsWorld::CPhysicsWorld(CPhysicsWorld*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x237e94 · CPhysicsWorld::DestroyBodies() · size=180 · insn=45 */
/* @0x237e94 ldr r3, [pc, #0xa8] */
/* @0x237e98 movw r2, #0xfeee */
/* @0x237e9c push {r4, r5, r6, r7, r8, lr} */
/* @0x237ea0 ldr r3, [pc, r3] */
/* @0x237ea4 movt r2, #0xfeee */
/* @0x237ea8 mov r7, r0 */
/* @0x237eac ldr r3, [r3] */
/* @0x237eb0 ldr r4, [r3, #0x80] */
/* @0x237eb4 cmp r4, r2 */
/* @0x237eb8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x237ebc cmp r4, #0 */
/* @0x237ec0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x237ec4 movw r6, #0x9228 */
/* @0x237ec8 movt r6, #0x1 */
/* @0x237ecc mov r8, #0 */
/* @0x237ed0 ldr r5, [r4, #0x84] */
/* @0x237ed4 cmp r5, #0 */
/* @0x237ed8 beq 0x237f10 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x7c> */
/* @0x237edc ldr r3, [r7, #0x10] */
/* @0x237ee0 ldr r3, [r3, r6] */
/* @0x237ee4 cmp r3, #0 */
/* @0x237ee8 beq 0x237f10 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x7c> */
/* @0x237eec ldr r2, [r5] */
/* @0x237ef0 cmp r3, r2 */
/* @0x237ef4 bne 0x237f04 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x70> */
/* @0x237ef8 b 0x237f20 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x8c> */
/* @0x237efc cmp r3, r2 */
/* @0x237f00 beq 0x237f20 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x8c> */
/* @0x237f04 ldr r3, [r3, #0x70] */
/* @0x237f08 cmp r3, #0 */
/* @0x237f0c bne 0x237efc <_ZN13CPhysicsWorld13DestroyBodiesEv+0x68> */
/* @0x237f10 ldr r4, [r4, #0x178] */
/* @0x237f14 cmp r4, #0 */
/* @0x237f18 bne 0x237ed0 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x3c> */
/* @0x237f1c pop {r4, r5, r6, r7, r8, pc} */
/* @0x237f20 mov r0, r5 */
/* @0x237f24 bl 0x236c60 <_ZN14CPhysicsObjectD2Ev> */
/* @0x237f28 mov r0, r5 */
/* @0x237f2c bl 0x27d1d0 <_ZdlPv> */
/* @0x237f30 str r8, [r4, #0x84] */
/* @0x237f34 ldr r4, [r4, #0x178] */
/* @0x237f38 cmp r4, #0 */
/* @0x237f3c bne 0x237ed0 <_ZN13CPhysicsWorld13DestroyBodiesEv+0x3c> */
/* @0x237f40 b 0x237f1c <_ZN13CPhysicsWorld13DestroyBodiesEv+0x88> */
/* @0x237f44 andseq r5, r11, r8, lsl #21 */

/* ── FUNC 0x237f48 · CPhysicsWorld::DestroyJoints() · size=72 · insn=18 */
/* @0x237f48 ldr r2, [r0, #0x10] */
/* @0x237f4c push {r3, r4, r5, lr} */
/* @0x237f50 movw r3, #0x922c */
/* @0x237f54 movt r3, #0x1 */
/* @0x237f58 mov r5, r0 */
/* @0x237f5c ldr r3, [r2, r3] */
/* @0x237f60 cmp r3, #0 */
/* @0x237f64 popeq {r3, r4, r5, pc} */
/* @0x237f68 mov r0, r3 */
/* @0x237f6c ldr r4, [r3, #0xc] */
/* @0x237f70 bl 0x23b47c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint> */
/* @0x237f74 ldr r1, [r0, #0x8] */
/* @0x237f78 mov r0, r5 */
/* @0x237f7c bl 0x23b3c4 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj> */
/* @0x237f80 cmp r4, #0 */
/* @0x237f84 mov r3, r4 */
/* @0x237f88 bne 0x237f68 <_ZN13CPhysicsWorld13DestroyJointsEv+0x20> */
/* @0x237f8c pop {r3, r4, r5, pc} */

/* ── FUNC 0x237f90 · CPhysicsWorld::DeleteJoint(int) · size=4 · insn=1 */
/* @0x237f90 b 0x23b3c4 <_ZN20CPhysicsJointFactory12DestroyJointEP13CPhysicsWorldj> */

/* ── FUNC 0x237f94 · CPhysicsWorld::UpdatePaths() · size=220 · insn=55 */
/* @0x237f94 push {r3, r4, r5, r6, r7, lr} */
/* @0x237f98 mov r7, r0 */
/* @0x237f9c ldr r3, [pc, #0xc8] */
/* @0x237fa0 ldr r3, [pc, r3] */
/* @0x237fa4 ldr r3, [r3] */
/* @0x237fa8 ldr r4, [r3, #0x80] */
/* @0x237fac cmp r4, #0 */
/* @0x237fb0 bne 0x237ff8 <_ZN13CPhysicsWorld11UpdatePathsEv+0x64> */
/* @0x237fb4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x237fb8 mov r0, r4 */
/* @0x237fbc bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x237fc0 cmp r0, #0 */
/* @0x237fc4 bne 0x238054 <_ZN13CPhysicsWorld11UpdatePathsEv+0xc0> */
/* @0x237fc8 vldr s15, [r7, #96] */
/* @0x237fcc vldr s13, [r4, #180] */
/* @0x237fd0 vldr s14, [r4, #184] */
/* @0x237fd4 vmul.f32 s13, s15, s13 */
/* @0x237fd8 mov r0, r6 */
/* @0x237fdc vmul.f32 s14, s15, s14 */
/* @0x237fe0 vmov r1, s13 */
/* @0x237fe4 vmov r2, s14 */
/* @0x237fe8 bl 0x236e00 <_ZN14CPhysicsObject11SetPositionEff> */
/* @0x237fec cmp r5, #0 */
/* @0x237ff0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x237ff4 mov r4, r5 */
/* @0x237ff8 ldr r3, [r4, #0x128] */
/* @0x237ffc ldr r5, [r4, #0x178] */
/* @0x238000 cmp r3, #0 */
/* @0x238004 blt 0x237fec <_ZN13CPhysicsWorld11UpdatePathsEv+0x58> */
/* @0x238008 ldr r6, [r4, #0x84] */
/* @0x23800c cmp r6, #0 */
/* @0x238010 beq 0x238024 <_ZN13CPhysicsWorld11UpdatePathsEv+0x90> */
/* @0x238014 ldr r3, [r6] */
/* @0x238018 ldr r3, [r3] */
/* @0x23801c cmp r3, #2 */
/* @0x238020 bne 0x237fb8 <_ZN13CPhysicsWorld11UpdatePathsEv+0x24> */
/* @0x238024 mov r0, r4 */
/* @0x238028 bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x23802c cmp r0, #0 */
/* @0x238030 beq 0x237fec <_ZN13CPhysicsWorld11UpdatePathsEv+0x58> */
/* @0x238034 mov r0, r4 */
/* @0x238038 mov r2, #7 */
/* @0x23803c mov r1, r4 */
/* @0x238040 mov r3, #8 */
/* @0x238044 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x238048 cmp r5, #0 */
/* @0x23804c bne 0x237ff4 <_ZN13CPhysicsWorld11UpdatePathsEv+0x60> */
/* @0x238050 pop {r3, r4, r5, r6, r7, pc} */
/* @0x238054 mov r0, r4 */
/* @0x238058 mov r1, r4 */
/* @0x23805c mov r2, #7 */
/* @0x238060 mov r3, #8 */
/* @0x238064 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x238068 b 0x237fc8 <_ZN13CPhysicsWorld11UpdatePathsEv+0x34> */
/* @0x23806c andseq r5, r11, r8, lsl #19 */

/* ── FUNC 0x238070 · CPhysicsWorld::StorePreviousPositions() · size=68 · insn=17 */
/* @0x238070 ldr r2, [r0, #0x10] */
/* @0x238074 movw r3, #0x9228 */
/* @0x238078 movt r3, #0x1 */
/* @0x23807c ldr r3, [r2, r3] */
/* @0x238080 cmp r3, #0 */
/* @0x238084 bxeq lr */
/* @0x238088 ldr r2, [r3, #0xa4] */
/* @0x23808c cmp r2, #0 */
/* @0x238090 ldrne r0, [r3, #0xc] */
/* @0x238094 ldrne r1, [r3, #0x10] */
/* @0x238098 ldrne r2, [r2, #0x84] */
/* @0x23809c strne r0, [r2, #0xc] */
/* @0x2380a0 strne r1, [r2, #0x10] */
/* @0x2380a4 ldr r3, [r3, #0x70] */
/* @0x2380a8 cmp r3, #0 */
/* @0x2380ac bne 0x238088 <_ZN13CPhysicsWorld22StorePreviousPositionsEv+0x18> */
/* @0x2380b0 bx lr */

/* ── FUNC 0x2380b4 · CPhysicsWorld::ApplyVisualOffset(float, b2Vec2 const&, b2Vec2&) · size=120 · insn=30 */
/* @0x2380b4 push {r3, r4, r5, lr} */
/* @0x2380b8 vpush {d8, d9} */
/* @0x2380bc vldr s16, [r2] */
/* @0x2380c0 vcmp.f32 s16, #0 */
/* @0x2380c4 mov r4, r3 */
/* @0x2380c8 mov r5, r1 */
/* @0x2380cc vldr s17, [r2, #4] */
/* @0x2380d0 vmrs APSR_nzcv, fpscr */
/* @0x2380d4 bne 0x2380f4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_+0x40> */
/* @0x2380d8 vcmp.f32 s17, #0 */
/* @0x2380dc vmrs APSR_nzcv, fpscr */
/* @0x2380e0 vstreq s16, [r3] */
/* @0x2380e4 vstreq s17, [r3, #4] */
/* @0x2380e8 bne 0x2380f4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_+0x40> */
/* @0x2380ec vpop {d8, d9} */
/* @0x2380f0 pop {r3, r4, r5, pc} */
/* @0x2380f4 mov r0, r5 */
/* @0x2380f8 bl 0xb658c <cosf@plt> */
/* @0x2380fc vmov s18, r0 */
/* @0x238100 mov r0, r5 */
/* @0x238104 bl 0xb6580 <sinf@plt> */
/* @0x238108 vmov s15, r0 */
/* @0x23810c vmul.f32 s14, s15, s17 */
/* @0x238110 vmul.f32 s15, s16, s15 */
/* @0x238114 vnmls.f32 s14, s16, s18 */
/* @0x238118 vmla.f32 s15, s18, s17 */
/* @0x23811c vstr s14, [r4] */
/* @0x238120 vpop {d8, d9} */
/* @0x238124 vstr s15, [r4, #4] */
/* @0x238128 pop {r3, r4, r5, pc} */

/* ── FUNC 0x23812c · CPhysicsWorld::TransferPhysicalPositions() · size=216 · insn=54 */
/* @0x23812c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x238130 vpush {d8, d9} */
/* @0x238134 vmov.f32 s16, #1.000000e+00 */
/* @0x238138 vldr s15, [r0, #96] */
/* @0x23813c ldr r2, [r0, #0x10] */
/* @0x238140 movw r3, #0x9228 */
/* @0x238144 movt r3, #0x1 */
/* @0x238148 sub sp, sp, #20 */
/* @0x23814c mov r8, r0 */
/* @0x238150 ldr r4, [r2, r3] */
/* @0x238154 cmp r4, #0 */
/* @0x238158 vdiv.f32 s16, s16, s15 */
/* @0x23815c beq 0x2381f0 <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv+0xc4> */
/* @0x238160 add r6, sp, #8 */
/* @0x238164 mov r9, #1 */
/* @0x238168 vldr s18, [pc, #140] */
/* @0x23816c vldr s17, [pc, #140] */
/* @0x238170 ldr r5, [r4, #0xa4] */
/* @0x238174 mov r2, r6 */
/* @0x238178 mov r3, sp */
/* @0x23817c cmp r5, #0 */
/* @0x238180 beq 0x2381e4 <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv+0xb8> */
/* @0x238184 ldr r12, [r5, #0x84] */
/* @0x238188 ldr lr, [r4, #0x48] */
/* @0x23818c ldmib r12, {r0, r1} */
/* @0x238190 stm r6, {r0, r1} */
/* @0x238194 mov r1, lr */
/* @0x238198 mov r0, r8 */
/* @0x23819c bl 0x2380b4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_> */
/* @0x2381a0 vldr s13, [r4, #12] */
/* @0x2381a4 vldr s14, [sp] */
/* @0x2381a8 vldr s15, [sp, #4] */
/* @0x2381ac mov r0, r5 */
/* @0x2381b0 vmla.f32 s14, s16, s13 */
/* @0x2381b4 vstr s14, [r5, #180] */
/* @0x2381b8 vldr s14, [r4, #16] */
/* @0x2381bc vmla.f32 s15, s16, s14 */
/* @0x2381c0 vstr s15, [r5, #184] */
/* @0x2381c4 vldr s15, [r4, #72] */
/* @0x2381c8 vnmul.f32 s15, s15, s18 */
/* @0x2381cc vdiv.f32 s15, s15, s17 */
/* @0x2381d0 vmov r1, s15 */
/* @0x2381d4 bl 0x19303c <_ZN9CInstance13SetImageAngleEf> */
/* @0x2381d8 strb r9, [r5, #0x64] */
/* @0x2381dc mov r0, r5 */
/* @0x2381e0 bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x2381e4 ldr r4, [r4, #0x70] */
/* @0x2381e8 cmp r4, #0 */
/* @0x2381ec bne 0x238170 <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv+0x44> */
/* @0x2381f0 add sp, sp, #20 */
/* @0x2381f4 vpop {d8, d9} */
/* @0x2381f8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2381fc teqmi r4, #0 */
/* @0x238200 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x238204 · CPhysicsWorld::RegisterContactResult(b2Contact*) · size=4 · insn=1 */
/* @0x238204 b 0x23bec4 <_ZN13ContactsStack4PushEP9b2Contact> */

/* ── FUNC 0x238208 · CPhysicsWorld::DispatchContactEvents() · size=168 · insn=42 */
/* @0x238208 push {r3, r4, r5, r6, r7, lr} */
/* @0x23820c mov r4, r0 */
/* @0x238210 bl 0x23c128 <_ZN13ContactsStack3PopEv> */
/* @0x238214 cmp r0, #0 */
/* @0x238218 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x23821c mov r6, #0 */
/* @0x238220 b 0x238238 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x30> */
/* @0x238224 str r6, [r4, #0xc] */
/* @0x238228 mov r0, r4 */
/* @0x23822c bl 0x23c128 <_ZN13ContactsStack3PopEv> */
/* @0x238230 cmp r0, #0 */
/* @0x238234 beq 0x2382ac <_ZN13CPhysicsWorld21DispatchContactEventsEv+0xa4> */
/* @0x238238 ldr r2, [r0, #0x4] */
/* @0x23823c cmp r2, #0 */
/* @0x238240 beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20> */
/* @0x238244 ldr r1, [r0, #0x8] */
/* @0x238248 cmp r1, #0 */
/* @0x23824c beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20> */
/* @0x238250 ldr r2, [r2, #0x8] */
/* @0x238254 cmp r2, #0 */
/* @0x238258 beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20> */
/* @0x23825c ldr r12, [r1, #0x8] */
/* @0x238260 cmp r12, #0 */
/* @0x238264 beq 0x238228 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x20> */
/* @0x238268 ldr r7, [r2, #0xa4] */
/* @0x23826c ldr r5, [r12, #0xa4] */
/* @0x238270 str r0, [r4, #0xc] */
/* @0x238274 cmp r5, #0 */
/* @0x238278 cmpne r7, #0 */
/* @0x23827c beq 0x238224 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x1c> */
/* @0x238280 mov r0, r7 */
/* @0x238284 mov r1, r5 */
/* @0x238288 ldr r3, [r5, #0x7c] */
/* @0x23828c mov r2, #4 */
/* @0x238290 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x238294 mov r0, r5 */
/* @0x238298 mov r1, r7 */
/* @0x23829c ldr r3, [r7, #0x7c] */
/* @0x2382a0 mov r2, #4 */
/* @0x2382a4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x2382a8 b 0x238224 <_ZN13CPhysicsWorld21DispatchContactEventsEv+0x1c> */
/* @0x2382ac pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2382b0 · CPhysicsWorld::Update(int, bool) · size=304 · insn=76 */
/* @0x2382b0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2382b4 vpush {d8, d9} */
/* @0x2382b8 mov r4, r0 */
/* @0x2382bc ldr r5, [pc, #0x110] */
/* @0x2382c0 mov r7, r1 */
/* @0x2382c4 ldr r3, [pc, #0x10c] */
/* @0x2382c8 mov r8, r2 */
/* @0x2382cc add r5, pc, r5 */
/* @0x2382d0 ldr r6, [r5, r3] */
/* @0x2382d4 ldrb r3, [r6] */
/* @0x2382d8 cmp r3, #0 */
/* @0x2382dc bne 0x238378 <_ZN13CPhysicsWorld6UpdateEib+0xc8> */
/* @0x2382e0 cmp r7, #0 */
/* @0x2382e4 ble 0x2382fc <_ZN13CPhysicsWorld6UpdateEib+0x4c> */
/* @0x2382e8 cmp r8, #0 */
/* @0x2382ec bne 0x2383c8 <_ZN13CPhysicsWorld6UpdateEib+0x118> */
/* @0x2382f0 ldrb r3, [r4, #0x64] */
/* @0x2382f4 cmp r3, #0 */
/* @0x2382f8 beq 0x238310 <_ZN13CPhysicsWorld6UpdateEib+0x60> */
/* @0x2382fc ldrb r3, [r6] */
/* @0x238300 cmp r3, #0 */
/* @0x238304 bne 0x238364 <_ZN13CPhysicsWorld6UpdateEib+0xb4> */
/* @0x238308 vpop {d8, d9} */
/* @0x23830c pop {r4, r5, r6, r7, r8, pc} */
/* @0x238310 mov r0, r4 */
/* @0x238314 vmov.f32 s17, #1.000000e+00 */
/* @0x238318 bl 0x238070 <_ZN13CPhysicsWorld22StorePreviousPositionsEv> */
/* @0x23831c vmov s15, r7 */
/* @0x238320 vcvt.f32.s32 s16, s15 */
/* @0x238324 vldr s15, [r4, #88] */
/* @0x238328 vcvt.f32.s32 s18, s15 */
/* @0x23832c vdiv.f32 s16, s18, s16 */
/* @0x238330 vcmpe.f32 s16, #0 */
/* @0x238334 vdiv.f32 s18, s17, s18 */
/* @0x238338 vmrs APSR_nzcv, fpscr */
/* @0x23833c bgt 0x238390 <_ZN13CPhysicsWorld6UpdateEib+0xe0> */
/* @0x238340 ldr r0, [r4, #0x10] */
/* @0x238344 bl 0x2ca658 <_ZN7b2World11ClearForcesEv> */
/* @0x238348 mov r0, r4 */
/* @0x23834c bl 0x23812c <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv> */
/* @0x238350 mov r0, r4 */
/* @0x238354 bl 0x238208 <_ZN13CPhysicsWorld21DispatchContactEventsEv> */
/* @0x238358 ldrb r3, [r6] */
/* @0x23835c cmp r3, #0 */
/* @0x238360 beq 0x238308 <_ZN13CPhysicsWorld6UpdateEib+0x58> */
/* @0x238364 vpop {d8, d9} */
/* @0x238368 ldr r3, [pc, #0x6c] */
/* @0x23836c ldr r0, [r5, r3] */
/* @0x238370 pop {r4, r5, r6, r7, r8, lr} */
/* @0x238374 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x238378 ldr r3, [pc, #0x5c] */
/* @0x23837c mov r1, #6 */
/* @0x238380 mov r2, r1 */
/* @0x238384 ldr r0, [r5, r3] */
/* @0x238388 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x23838c b 0x2382e0 <_ZN13CPhysicsWorld6UpdateEib+0x30> */
/* @0x238390 vcmpe.f32 s16, s17 */
/* @0x238394 ldr r2, [r4, #0x5c] */
/* @0x238398 ldr r0, [r4, #0x10] */
/* @0x23839c mov r3, r2 */
/* @0x2383a0 vmrs APSR_nzcv, fpscr */
/* @0x2383a4 vmov.f32 s15, s18 */
/* @0x2383a8 vmulle.f32 s15, s18, s16 */
/* @0x2383ac vmov r1, s15 */
/* @0x2383b0 bl 0x2ca68c <_ZN7b2World4StepEfii> */
/* @0x2383b4 vsub.f32 s16, s16, s17 */
/* @0x2383b8 vcmpe.f32 s16, #0 */
/* @0x2383bc vmrs APSR_nzcv, fpscr */
/* @0x2383c0 bgt 0x238390 <_ZN13CPhysicsWorld6UpdateEib+0xe0> */
/* @0x2383c4 b 0x238340 <_ZN13CPhysicsWorld6UpdateEib+0x90> */
/* @0x2383c8 mov r0, r4 */
/* @0x2383cc bl 0x237f94 <_ZN13CPhysicsWorld11UpdatePathsEv> */
/* @0x2383d0 b 0x2382f0 <_ZN13CPhysicsWorld6UpdateEib+0x40> */
/* @0x2383d4 andseq r9, r11, r4, lsl #19 */
/* @0x2383d8 .word 0xffffbf18 */
/* @0x2383dc .word 0xffffbf1c */

/* ── FUNC 0x2383e0 · CPhysicsWorld::InvalidateFixture(b2Fixture*) · size=88 · insn=22 */
/* @0x2383e0 ldr r3, [r0, #0x4] */
/* @0x2383e4 push {r4, r5} */
/* @0x2383e8 cmp r3, #0 */
/* @0x2383ec ble 0x238430 <_ZN13CPhysicsWorld17InvalidateFixtureEP9b2Fixture+0x50> */
/* @0x2383f0 mov r2, #0 */
/* @0x2383f4 mov r12, r2 */
/* @0x2383f8 mov r5, r2 */
/* @0x2383fc ldr r3, [r0] */
/* @0x238400 add r12, r12, #1 */
/* @0x238404 add r3, r3, r2 */
/* @0x238408 add r2, r2, #716 */
/* @0x23840c ldr r4, [r3, #0x4] */
/* @0x238410 cmp r4, r1 */
/* @0x238414 ldr r4, [r3, #0x8] */
/* @0x238418 streq r5, [r3, #0x4] */
/* @0x23841c cmp r4, r1 */
/* @0x238420 streq r5, [r3, #0x8] */
/* @0x238424 ldr r3, [r0, #0x4] */
/* @0x238428 cmp r12, r3 */
/* @0x23842c blt 0x2383fc <_ZN13CPhysicsWorld17InvalidateFixtureEP9b2Fixture+0x1c> */
/* @0x238430 pop {r4, r5} */
/* @0x238434 bx lr */

/* ── FUNC 0x238438 · CPhysicsWorld::DebugRender(unsigned int) · size=80 · insn=20 */
/* @0x238438 and r3, r1, #1 */
/* @0x23843c tst r1, #2 */
/* @0x238440 orrne r3, r3, #2 */
/* @0x238444 tst r1, #4 */
/* @0x238448 orrne r3, r3, #16 */
/* @0x23844c tst r1, #8 */
/* @0x238450 orrne r3, r3, #4 */
/* @0x238454 tst r1, #64 */
/* @0x238458 orrne r3, r3, #8 */
/* @0x23845c push {r4, lr} */
/* @0x238460 mov r1, r3 */
/* @0x238464 mov r4, r0 */
/* @0x238468 ldr r0, [r0, #0x50] */
/* @0x23846c bl 0x2c67d8 <_ZN6b2Draw8SetFlagsEj> */
/* @0x238470 ldr r0, [r4, #0x10] */
/* @0x238474 bl 0x2cad9c <_ZN7b2World13DrawDebugDataEv> */
/* @0x238478 ldr r0, [r4, #0x50] */
/* @0x23847c mov r1, #0 */
/* @0x238480 pop {r4, lr} */
/* @0x238484 b 0x2c67d8 <_ZN6b2Draw8SetFlagsEj> */

/* ── FUNC 0x238488 · CPhysicsWorld::GetCollisionCategory(int) · size=52 · insn=13 */
/* @0x238488 mov r3, #0 */
/* @0x23848c b 0x23849c <_ZN13CPhysicsWorld20GetCollisionCategoryEi+0x14> */
/* @0x238490 add r3, r3, #1 */
/* @0x238494 cmp r3, #32 */
/* @0x238498 beq 0x2384b4 <_ZN13CPhysicsWorld20GetCollisionCategoryEi+0x2c> */
/* @0x23849c ldr r2, [r0, #0x68] */
/* @0x2384a0 add r0, r0, #12 */
/* @0x2384a4 cmp r2, r1 */
/* @0x2384a8 bne 0x238490 <_ZN13CPhysicsWorld20GetCollisionCategoryEi+0x8> */
/* @0x2384ac mov r0, r3 */
/* @0x2384b0 bx lr */
/* @0x2384b4 mvn r0, #0 */
/* @0x2384b8 bx lr */

/* ── FUNC 0x2384bc · CPhysicsWorld::AssignCollisionCategory(int) · size=220 · insn=55 */
/* @0x2384bc push {r4, r5, r6, lr} */
/* @0x2384c0 sub sp, sp, #1024 */
/* @0x2384c4 ldr r4, [pc, #0xc4] */
/* @0x2384c8 sub sp, sp, #8 */
/* @0x2384cc mov r5, r0 */
/* @0x2384d0 mov r6, r1 */
/* @0x2384d4 ldr r4, [pc, r4] */
/* @0x2384d8 ldr r3, [r4] */
/* @0x2384dc str r3, [sp, #0x404] */
/* @0x2384e0 bl 0x238488 <_ZN13CPhysicsWorld20GetCollisionCategoryEi> */
/* @0x2384e4 cmn r0, #1 */
/* @0x2384e8 beq 0x238508 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x4c> */
/* @0x2384ec ldr r2, [sp, #0x404] */
/* @0x2384f0 ldr r3, [r4] */
/* @0x2384f4 cmp r2, r3 */
/* @0x2384f8 bne 0x23858c <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0xd0> */
/* @0x2384fc add sp, sp, #1024 */
/* @0x238500 add sp, sp, #8 */
/* @0x238504 pop {r4, r5, r6, pc} */
/* @0x238508 mov r2, r5 */
/* @0x23850c mov r3, #0 */
/* @0x238510 b 0x238524 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x68> */
/* @0x238514 add r3, r3, #1 */
/* @0x238518 add r2, r2, #12 */
/* @0x23851c cmp r3, #32 */
/* @0x238520 beq 0x238558 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x9c> */
/* @0x238524 ldr r12, [r2, #0x68] */
/* @0x238528 cmn r12, #1 */
/* @0x23852c bne 0x238514 <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x58> */
/* @0x238530 add r1, r3, r3, lsl #1 */
/* @0x238534 mov r2, #1 */
/* @0x238538 lsl r2, r2, r3 */
/* @0x23853c mov r0, r3 */
/* @0x238540 add r5, r5, r1, lsl #2 */
/* @0x238544 mov r3, #0 */
/* @0x238548 str r6, [r5, #0x68] */
/* @0x23854c str r2, [r5, #0x6c] */
/* @0x238550 str r3, [r5, #0x70] */
/* @0x238554 b 0x2384ec <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x30> */
/* @0x238558 mov r0, r6 */
/* @0x23855c add r5, sp, #4 */
/* @0x238560 bl 0x19ed54 <_Z11Object_Namei> */
/* @0x238564 ldr r1, [pc, #0x28] */
/* @0x238568 add r1, pc, r1 */
/* @0x23856c mov r2, r0 */
/* @0x238570 mov r0, r5 */
/* @0x238574 bl 0xb6550 <sprintf@plt> */
/* @0x238578 mov r0, r5 */
/* @0x23857c mov r1, #0 */
/* @0x238580 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x238584 mvn r0, #0 */
/* @0x238588 b 0x2384ec <_ZN13CPhysicsWorld23AssignCollisionCategoryEi+0x30> */
/* @0x23858c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x238590 andseq r5, r11, r12, ror r4 */
/* @0x238594 ldrsbeq r12, [r1], -r12 */

/* ── FUNC 0x238598 · CPhysicsWorld::FindBaseObjectForCollisions(int, int) · size=384 · insn=96 */
/* @0x238598 ldr r3, [pc, #0x16c] */
/* @0x23859c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2385a0 sub sp, sp, #12 */
/* @0x2385a4 mov r11, r1 */
/* @0x2385a8 str r3, [sp, #0x4] */
/* @0x2385ac ldr r0, [sp, #0x4] */
/* @0x2385b0 ldr r3, [pc, #0x158] */
/* @0x2385b4 ldr r0, [pc, r0] */
/* @0x2385b8 str r0, [sp, #0x4] */
/* @0x2385bc ldr r3, [pc, r3] */
/* @0x2385c0 ldr r1, [r0] */
/* @0x2385c4 ldr r10, [r3] */
/* @0x2385c8 ldr r0, [r1, #0x4] */
/* @0x2385cc ldr r3, [r1] */
/* @0x2385d0 and r1, r11, r0 */
/* @0x2385d4 ldr r3, [r3, r1, lsl #3] */
/* @0x2385d8 cmp r3, #0 */
/* @0x2385dc bne 0x2385f0 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x58> */
/* @0x2385e0 b 0x238704 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x16c> */
/* @0x2385e4 ldr r3, [r3, #0x4] */
/* @0x2385e8 cmp r3, #0 */
/* @0x2385ec beq 0x238704 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x16c> */
/* @0x2385f0 ldr r1, [r3, #0x8] */
/* @0x2385f4 cmp r11, r1 */
/* @0x2385f8 bne 0x2385e4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x4c> */
/* @0x2385fc ldr r8, [r3, #0xc] */
/* @0x238600 ldr r0, [r8, #0xc] */
/* @0x238604 cmp r0, #0 */
/* @0x238608 bge 0x238618 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x80> */
/* @0x23860c mov r0, r11 */
/* @0x238610 add sp, sp, #12 */
/* @0x238614 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x238618 str r2, [sp] */
/* @0x23861c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x238620 ldr r2, [sp] */
/* @0x238624 cmp r0, #0 */
/* @0x238628 beq 0x23860c <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x74> */
/* @0x23862c ldr r3, [sp, #0x4] */
/* @0x238630 ldr r1, [r8, #0xc] */
/* @0x238634 ldr r0, [r3] */
/* @0x238638 ldm r0, {r3, r12} */
/* @0x23863c and r0, r1, r12 */
/* @0x238640 ldr r3, [r3, r0, lsl #3] */
/* @0x238644 cmp r3, #0 */
/* @0x238648 beq 0x2386f4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x15c> */
/* @0x23864c ldr r0, [r3, #0x8] */
/* @0x238650 cmp r1, r0 */
/* @0x238654 beq 0x238670 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0xd8> */
/* @0x238658 ldr r3, [r3, #0x4] */
/* @0x23865c cmp r3, #0 */
/* @0x238660 beq 0x2386f4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x15c> */
/* @0x238664 ldr r12, [r3, #0x8] */
/* @0x238668 cmp r1, r12 */
/* @0x23866c bne 0x238658 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0xc0> */
/* @0x238670 ldr r8, [r3, #0xc] */
/* @0x238674 ldr r1, [pc, #0x98] */
/* @0x238678 cmp r10, #0 */
/* @0x23867c ldr r7, [r8, #0x18] */
/* @0x238680 ldr r1, [pc, r1] */
/* @0x238684 ldr r12, [r1, #0x4] */
/* @0x238688 ble 0x2386fc <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x164> */
/* @0x23868c mov r4, #0 */
/* @0x238690 add r12, r12, #20 */
/* @0x238694 mov r9, r4 */
/* @0x238698 b 0x2386ac <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x114> */
/* @0x23869c cmp r7, r5 */
/* @0x2386a0 beq 0x2386e4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x14c> */
/* @0x2386a4 cmp r4, r10 */
/* @0x2386a8 beq 0x2386d4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x13c> */
/* @0x2386ac ldr r6, [r12, #-0x14] */
/* @0x2386b0 add r4, r4, #1 */
/* @0x2386b4 ldr r5, [r12, #-0x10] */
/* @0x2386b8 add r12, r12, #20 */
/* @0x2386bc cmp r7, r6 */
/* @0x2386c0 bne 0x23869c <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x104> */
/* @0x2386c4 cmn r5, #1 */
/* @0x2386c8 addne r9, r9, #1 */
/* @0x2386cc cmp r4, r10 */
/* @0x2386d0 bne 0x2386ac <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x114> */
/* @0x2386d4 cmp r9, r2 */
/* @0x2386d8 bne 0x23860c <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x74> */
/* @0x2386dc mov r11, r7 */
/* @0x2386e0 b 0x238600 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x68> */
/* @0x2386e4 mov r5, r6 */
/* @0x2386e8 cmn r5, #1 */
/* @0x2386ec addne r9, r9, #1 */
/* @0x2386f0 b 0x2386cc <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x134> */
/* @0x2386f4 mov r8, r3 */
/* @0x2386f8 b 0x238674 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0xdc> */
/* @0x2386fc mov r9, #0 */
/* @0x238700 b 0x2386d4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x13c> */
/* @0x238704 mov r8, r3 */
/* @0x238708 b 0x238600 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x68> */
/* @0x23870c andseq r5, r11, r8, lsl #13 */
/* @0x238710 andseq r8, r11, r0, lsr #2 */
/* @0x238714 andseq r8, r11, r0, rrx */

/* ── FUNC 0x238718 · CPhysicsWorld::BuildCollisionBits(int) · size=396 · insn=99 */
/* @0x238718 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23871c add r11, sp, #32 */
/* @0x238720 ldr r3, [pc, #0x170] */
/* @0x238724 sub sp, sp, #20 */
/* @0x238728 ldr r5, [pc, #0x16c] */
/* @0x23872c ldr r3, [pc, r3] */
/* @0x238730 mov r8, r0 */
/* @0x238734 ldr r5, [pc, r5] */
/* @0x238738 str r5, [r11, #-0x30] */
/* @0x23873c ldr r2, [r3] */
/* @0x238740 ldr r12, [r5] */
/* @0x238744 cmp r2, #0 */
/* @0x238748 lsl r0, r2, #2 */
/* @0x23874c add r3, r0, #14 */
/* @0x238750 str r12, [r11, #-0x28] */
/* @0x238754 bic r3, r3, #7 */
/* @0x238758 sub sp, sp, r3 */
/* @0x23875c mov r10, sp */
/* @0x238760 ble 0x23888c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x174> */
/* @0x238764 ldr r3, [pc, #0x134] */
/* @0x238768 add r0, r0, r2 */
/* @0x23876c mov r2, #0 */
/* @0x238770 ldr r3, [pc, r3] */
/* @0x238774 lsl r4, r0, #2 */
/* @0x238778 mov r7, r2 */
/* @0x23877c ldr r12, [r3, #0x4] */
/* @0x238780 b 0x238798 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x80> */
/* @0x238784 cmp r3, r1 */
/* @0x238788 beq 0x238878 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x160> */
/* @0x23878c add r2, r2, #20 */
/* @0x238790 cmp r2, r4 */
/* @0x238794 beq 0x2387c4 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xac> */
/* @0x238798 mov r3, r12 */
/* @0x23879c ldr r0, [r3, r2]! */
/* @0x2387a0 cmp r0, r1 */
/* @0x2387a4 ldr r3, [r3, #0x4] */
/* @0x2387a8 bne 0x238784 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x6c> */
/* @0x2387ac cmn r3, #1 */
/* @0x2387b0 strne r3, [r10, r7, lsl #2] */
/* @0x2387b4 addne r7, r7, #1 */
/* @0x2387b8 add r2, r2, #20 */
/* @0x2387bc cmp r2, r4 */
/* @0x2387c0 bne 0x238798 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x80> */
/* @0x2387c4 cmp r7, #0 */
/* @0x2387c8 beq 0x23888c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x174> */
/* @0x2387cc mov r2, r7 */
/* @0x2387d0 mov r0, r8 */
/* @0x2387d4 bl 0x238598 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii> */
/* @0x2387d8 mov r1, r0 */
/* @0x2387dc mov r0, r8 */
/* @0x2387e0 bl 0x2384bc <_ZN13CPhysicsWorld23AssignCollisionCategoryEi> */
/* @0x2387e4 cmn r0, #1 */
/* @0x2387e8 beq 0x23888c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x174> */
/* @0x2387ec add r4, r0, r0, lsl #1 */
/* @0x2387f0 sub r10, r10, #4 */
/* @0x2387f4 add r12, r8, #384 */
/* @0x2387f8 mov r2, #0 */
/* @0x2387fc add r4, r8, r4, lsl #2 */
/* @0x238800 ldr r1, [r10, #0x4]! */
/* @0x238804 mov r3, r8 */
/* @0x238808 b 0x238818 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x100> */
/* @0x23880c add r3, r3, #12 */
/* @0x238810 cmp r3, r12 */
/* @0x238814 beq 0x238850 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x138> */
/* @0x238818 ldr r5, [r3, #0x68] */
/* @0x23881c cmp r5, r1 */
/* @0x238820 bne 0x23880c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xf4> */
/* @0x238824 ldr r6, [r3, #0x6c] */
/* @0x238828 add r3, r3, #12 */
/* @0x23882c ldr r9, [r4, #0x70] */
/* @0x238830 orr r5, r6, r9 */
/* @0x238834 ldr r6, [r4, #0x6c] */
/* @0x238838 str r5, [r4, #0x70] */
/* @0x23883c ldr r5, [r3, #0x64] */
/* @0x238840 orr r5, r5, r6 */
/* @0x238844 str r5, [r3, #0x64] */
/* @0x238848 cmp r3, r12 */
/* @0x23884c bne 0x238818 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x100> */
/* @0x238850 add r2, r2, #1 */
/* @0x238854 cmp r2, r7 */
/* @0x238858 blt 0x238800 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xe8> */
/* @0x23885c ldr r9, [r11, #-0x30] */
/* @0x238860 ldr r2, [r11, #-0x28] */
/* @0x238864 ldr r3, [r9] */
/* @0x238868 cmp r2, r3 */
/* @0x23886c bne 0x238894 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x17c> */
/* @0x238870 sub sp, r11, #32 */
/* @0x238874 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x238878 mov r3, r0 */
/* @0x23887c cmn r3, #1 */
/* @0x238880 strne r3, [r10, r7, lsl #2] */
/* @0x238884 addne r7, r7, #1 */
/* @0x238888 b 0x2387b8 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xa0> */
/* @0x23888c mvn r0, #0 */
/* @0x238890 b 0x23885c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x144> */
/* @0x238894 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x238898 ldrheq r7, [r11], -r0 */
/* @0x23889c andseq r5, r11, r12, lsl r2 */
/* @0x2388a0 andseq r7, r11, r0, ror pc */

/* ── FUNC 0x2388a4 · CPhysicsWorld::UpdateInstantiatedShapesCollisionBits() · size=168 · insn=42 */
/* @0x2388a4 ldr r2, [r0, #0x10] */
/* @0x2388a8 movw r3, #0x9228 */
/* @0x2388ac movt r3, #0x1 */
/* @0x2388b0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2388b4 mov r7, r0 */
/* @0x2388b8 ldr r5, [r2, r3] */
/* @0x2388bc sub sp, sp, #16 */
/* @0x2388c0 cmp r5, #0 */
/* @0x2388c4 beq 0x238944 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0xa0> */
/* @0x2388c8 add r6, sp, #4 */
/* @0x2388cc mov r8, #0 */
/* @0x2388d0 ldr r3, [r5, #0xa4] */
/* @0x2388d4 cmp r3, #0 */
/* @0x2388d8 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94> */
/* @0x2388dc ldr r3, [r3, #0x84] */
/* @0x2388e0 cmp r3, #0 */
/* @0x2388e4 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94> */
/* @0x2388e8 ldr r3, [r3, #0x14] */
/* @0x2388ec cmn r3, #1 */
/* @0x2388f0 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94> */
/* @0x2388f4 add r3, r3, r3, lsl #1 */
/* @0x2388f8 ldr r4, [r5, #0x74] */
/* @0x2388fc strh r8, [sp, #12] */
/* @0x238900 add r3, r7, r3, lsl #2 */
/* @0x238904 cmp r4, #0 */
/* @0x238908 ldr r2, [r3, #0x6c] */
/* @0x23890c ldr r3, [r3, #0x70] */
/* @0x238910 stmib sp, {r2, r3} */
/* @0x238914 beq 0x238938 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x94> */
/* @0x238918 ldrh r3, [r4, #40] */
/* @0x23891c mov r0, r4 */
/* @0x238920 mov r1, r6 */
/* @0x238924 strh r3, [sp, #12] */
/* @0x238928 bl 0x2c899c <_ZN9b2Fixture13SetFilterDataERK8b2Filter> */
/* @0x23892c ldr r4, [r4, #0x4] */
/* @0x238930 cmp r4, #0 */
/* @0x238934 bne 0x238918 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x74> */
/* @0x238938 ldr r5, [r5, #0x70] */
/* @0x23893c cmp r5, #0 */
/* @0x238940 bne 0x2388d0 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv+0x2c> */
/* @0x238944 add sp, sp, #16 */
/* @0x238948 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x23894c · CPhysicsWorld::CreateBody(CPhysicsFixture*, CInstance*, float, float) · size=700 · insn=175 */
/* @0x23894c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x238950 mov r10, r3 */
/* @0x238954 ldr r5, [pc, #0x2a0] */
/* @0x238958 sub sp, sp, #1104 */
/* @0x23895c sub sp, sp, #4 */
/* @0x238960 mov r11, r1 */
/* @0x238964 ldr r5, [pc, r5] */
/* @0x238968 mov r7, r0 */
/* @0x23896c mov r0, r1 */
/* @0x238970 mov r1, r2 */
/* @0x238974 ldr r3, [r5] */
/* @0x238978 mov r4, r2 */
/* @0x23897c str r3, [sp, #0x44c] */
/* @0x238980 bl 0x236b84 <_ZN15CPhysicsFixture8FinaliseEP9CInstance> */
/* @0x238984 ldr r6, [r11, #0x20] */
/* @0x238988 ldr r3, [r6] */
/* @0x23898c cmp r3, #0 */
/* @0x238990 beq 0x238bc0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0x274> */
/* @0x238994 mov r0, r7 */
/* @0x238998 ldr r1, [r4, #0x7c] */
/* @0x23899c bl 0x238718 <_ZN13CPhysicsWorld18BuildCollisionBitsEi> */
/* @0x2389a0 cmn r0, #1 */
/* @0x2389a4 mov r8, r0 */
/* @0x2389a8 addne r3, r0, r0, lsl #1 */
/* @0x2389ac moveq r3, #0 */
/* @0x2389b0 streq r3, [r6, #0x18] */
/* @0x2389b4 addne r3, r7, r3, lsl #2 */
/* @0x2389b8 ldrne r2, [r3, #0x6c] */
/* @0x2389bc ldrne r3, [r3, #0x70] */
/* @0x2389c0 strne r2, [r6, #0x18] */
/* @0x2389c4 str r3, [r6, #0x1c] */
/* @0x2389c8 ldr r3, [r4, #0x84] */
/* @0x2389cc cmp r3, #0 */
/* @0x2389d0 beq 0x238a10 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0xc4> */
/* @0x2389d4 ldr r0, [r3] */
/* @0x2389d8 mov r1, r6 */
/* @0x2389dc bl 0x2c6dfc <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef> */
/* @0x2389e0 mov r1, r0 */
/* @0x2389e4 ldr r0, [r4, #0x84] */
/* @0x2389e8 bl 0x237708 <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture> */
/* @0x2389ec mov r4, r0 */
/* @0x2389f0 ldr r2, [sp, #0x44c] */
/* @0x2389f4 mov r0, r4 */
/* @0x2389f8 ldr r3, [r5] */
/* @0x2389fc cmp r2, r3 */
/* @0x238a00 bne 0x238bf0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0x2a4> */
/* @0x238a04 add sp, sp, #1104 */
/* @0x238a08 add sp, sp, #4 */
/* @0x238a0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x238a10 ldr r2, [r11, #0x20] */
/* @0x238a14 vldr s14, [r4, #160] */
/* @0x238a18 vldr s15, [r2, #16] */
/* @0x238a1c vcmpe.f32 s15, #0 */
/* @0x238a20 vldr s15, [pc, #460] */
/* @0x238a24 add r12, sp, #28 */
/* @0x238a28 str r12, [sp, #0x4] */
/* @0x238a2c add r12, sp, #32 */
/* @0x238a30 ldr lr, [r11, #0x4] */
/* @0x238a34 mov r1, #1065353216 */
/* @0x238a38 vnmul.f32 s15, s14, s15 */
/* @0x238a3c vldr s14, [pc, #436] */
/* @0x238a40 vmrs APSR_nzcv, fpscr */
/* @0x238a44 ldr r0, [r11] */
/* @0x238a48 strb r3, [sp, #0x3e] */
/* @0x238a4c mov r2, #1 */
/* @0x238a50 strb r3, [sp, #0x3f] */
/* @0x238a54 mov r3, #0 */
/* @0x238a58 str r1, [sp, #0x48] */
/* @0x238a5c str r3, [r12] */
/* @0x238a60 str r3, [sp, #0x1c] */
/* @0x238a64 str r3, [sp, #0x28] */
/* @0x238a68 str r3, [sp, #0x2c] */
/* @0x238a6c str r3, [sp, #0x30] */
/* @0x238a70 movgt r3, #2 */
/* @0x238a74 ldrble r3, [r11, #0x18] */
/* @0x238a78 ldrb r1, [r11, #0x8] */
/* @0x238a7c add r11, sp, #2048 */
/* @0x238a80 vdiv.f32 s15, s15, s14 */
/* @0x238a84 strb r2, [sp, #0x3c] */
/* @0x238a88 strb r2, [sp, #0x40] */
/* @0x238a8c add r2, sp, #16 */
/* @0x238a90 str lr, [sp, #0x38] */
/* @0x238a94 ldr lr, [r11, #-0x388] */
/* @0x238a98 mov r9, r2 */
/* @0x238a9c str r10, [r9], #-8 */
/* @0x238aa0 mov r11, #0 */
/* @0x238aa4 str r3, [sp, #0x18] */
/* @0x238aa8 mov r3, r9 */
/* @0x238aac strb r1, [sp, #0x3d] */
/* @0x238ab0 str r0, [sp, #0x34] */
/* @0x238ab4 mov r0, r7 */
/* @0x238ab8 str lr, [sp, #0x14] */
/* @0x238abc str r4, [sp, #0x44] */
/* @0x238ac0 str r12, [sp] */
/* @0x238ac4 vmov r1, s15 */
/* @0x238ac8 vstr s15, [sp, #36] */
/* @0x238acc bl 0x2380b4 <_ZN13CPhysicsWorld17ApplyVisualOffsetEfRK6b2Vec2RS0_> */
/* @0x238ad0 vldr s15, [sp, #12] */
/* @0x238ad4 vldr s14, [r4, #184] */
/* @0x238ad8 vsub.f32 s14, s14, s15 */
/* @0x238adc vldr s15, [r7, #96] */
/* @0x238ae0 vldr s12, [r4, #180] */
/* @0x238ae4 vldr s13, [r9] */
/* @0x238ae8 ldr r12, [sp] */
/* @0x238aec ldr r0, [r7, #0x10] */
/* @0x238af0 mov r1, r12 */
/* @0x238af4 vmul.f32 s14, s15, s14 */
/* @0x238af8 vsub.f32 s13, s12, s13 */
/* @0x238afc vmov r2, s14 */
/* @0x238b00 vmul.f32 s15, s13, s15 */
/* @0x238b04 str r2, [r1], #-8 */
/* @0x238b08 vstr s15, [sp, #28] */
/* @0x238b0c bl 0x2c903c <_ZN7b2World10CreateBodyEPK9b2BodyDef> */
/* @0x238b10 mov r1, r6 */
/* @0x238b14 str r0, [sp] */
/* @0x238b18 bl 0x2c6dfc <_ZN6b2Body13CreateFixtureEPK12b2FixtureDef> */
/* @0x238b1c mov r9, r0 */
/* @0x238b20 mov r0, #32 */
/* @0x238b24 bl 0x27c524 <_Znwj> */
/* @0x238b28 ldr r3, [sp] */
/* @0x238b2c add r12, sp, #2048 */
/* @0x238b30 ldr r2, [r3, #0xc] */
/* @0x238b34 str r3, [r0] */
/* @0x238b38 mov r6, r0 */
/* @0x238b3c ldr r3, [r3, #0x10] */
/* @0x238b40 str r8, [r0, #0x14] */
/* @0x238b44 str r11, [r0, #0x18] */
/* @0x238b48 str r3, [r0, #0x10] */
/* @0x238b4c ldr r3, [r12, #-0x388] */
/* @0x238b50 str r2, [r0, #0xc] */
/* @0x238b54 str r10, [r0, #0x4] */
/* @0x238b58 mov r0, #12 */
/* @0x238b5c str r3, [r6, #0x8] */
/* @0x238b60 bl 0x27c524 <_Znwj> */
/* @0x238b64 ldr r1, [pc, #0x94] */
/* @0x238b68 mov r3, #15 */
/* @0x238b6c mov r2, #187 */
/* @0x238b70 add r1, pc, r1 */
/* @0x238b74 mov r8, r0 */
/* @0x238b78 str r11, [r0, #0x8] */
/* @0x238b7c str r3, [r8, #0x4] */
/* @0x238b80 mov r0, #128 */
/* @0x238b84 mov r3, #1 */
/* @0x238b88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x238b8c mov r1, r11 */
/* @0x238b90 mov r2, #128 */
/* @0x238b94 str r0, [r8] */
/* @0x238b98 bl 0xb65b0 <memset@plt> */
/* @0x238b9c str r8, [r6, #0x1c] */
/* @0x238ba0 mov r0, r6 */
/* @0x238ba4 str r6, [r4, #0x84] */
/* @0x238ba8 mov r1, r9 */
/* @0x238bac bl 0x237708 <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture> */
/* @0x238bb0 mov r4, r0 */
/* @0x238bb4 mov r0, r7 */
/* @0x238bb8 bl 0x2388a4 <_ZN13CPhysicsWorld37UpdateInstantiatedShapesCollisionBitsEv> */
/* @0x238bbc b 0x2389f0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0xa4> */
/* @0x238bc0 ldr r3, [r4, #0x80] */
/* @0x238bc4 add r6, sp, #76 */
/* @0x238bc8 ldr r1, [pc, #0x34] */
/* @0x238bcc mvn r4, #0 */
/* @0x238bd0 mov r0, r6 */
/* @0x238bd4 add r1, pc, r1 */
/* @0x238bd8 ldr r2, [r3, #0x14] */
/* @0x238bdc bl 0xb6550 <sprintf@plt> */
/* @0x238be0 mov r0, r6 */
/* @0x238be4 mov r1, #1 */
/* @0x238be8 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x238bec b 0x2389f0 <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff+0xa4> */
/* @0x238bf0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x238bf4 ldrdmi r0, r1, [r9], #-251 */
/* @0x238bf8 teqmi r4, #0 */
/* @0x238bfc andseq r4, r11, r12, ror #31 */
/* @0x238c00 andseq r4, r1, r12, lsr r1 */
/* @0x238c04 andseq r12, r1, r12, ror #13 */

/* ── FUNC 0x238c08 · CPhysicsWorld::DestroyBody(CPhysicsObject*) · size=12 · insn=3 */
/* @0x238c08 ldr r0, [r0, #0x10] */
/* @0x238c0c ldr r1, [r1] */
/* @0x238c10 b 0x2c93e4 <_ZN7b2World11DestroyBodyEP6b2Body> */

/* ── FUNC 0x238c14 · CPhysicsWorld::SetGravity(float, float) · size=156 · insn=39 */
/* @0x238c14 vmov s14, r1 */
/* @0x238c18 ldr r3, [r0, #0x10] */
/* @0x238c1c vmov s15, r2 */
/* @0x238c20 vcmp.f32 s14, #0 */
/* @0x238c24 add r2, r3, #102400 */
/* @0x238c28 mov r3, r2 */
/* @0x238c2c str r1, [r2, #0x238] */
/* @0x238c30 vstr s15, [r3, #572] */
/* @0x238c34 vmrs APSR_nzcv, fpscr */
/* @0x238c38 vcmp.f32 s15, #0 */
/* @0x238c3c moveq r3, #0 */
/* @0x238c40 movne r3, #1 */
/* @0x238c44 vmrs APSR_nzcv, fpscr */
/* @0x238c48 orrne r3, r3, #1 */
/* @0x238c4c cmp r3, #0 */
/* @0x238c50 bxeq lr */
/* @0x238c54 ldr r2, [r0, #0x10] */
/* @0x238c58 movw r3, #0x9228 */
/* @0x238c5c movt r3, #0x1 */
/* @0x238c60 ldr r3, [r2, r3] */
/* @0x238c64 cmp r3, #0 */
/* @0x238c68 bxeq lr */
/* @0x238c6c mov r1, #0 */
/* @0x238c70 b 0x238c80 <_ZN13CPhysicsWorld10SetGravityEff+0x6c> */
/* @0x238c74 ldr r3, [r3, #0x70] */
/* @0x238c78 cmp r3, #0 */
/* @0x238c7c beq 0x238cac <_ZN13CPhysicsWorld10SetGravityEff+0x98> */
/* @0x238c80 ldr r2, [r3] */
/* @0x238c84 cmp r2, #2 */
/* @0x238c88 bne 0x238c74 <_ZN13CPhysicsWorld10SetGravityEff+0x60> */
/* @0x238c8c ldrh r2, [r3, #4] */
/* @0x238c90 tst r2, #2 */
/* @0x238c94 orr r2, r2, #2 */
/* @0x238c98 streq r1, [r3, #0xa0] */
/* @0x238c9c strheq r2, [r3, #4] */
/* @0x238ca0 ldr r3, [r3, #0x70] */
/* @0x238ca4 cmp r3, #0 */
/* @0x238ca8 bne 0x238c80 <_ZN13CPhysicsWorld10SetGravityEff+0x6c> */
/* @0x238cac bx lr */
