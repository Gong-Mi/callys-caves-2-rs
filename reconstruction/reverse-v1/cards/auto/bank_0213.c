/* libyoyo.so 覆盖卡组 0213
 * 函数 0x238ce4..0x23a194，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x238ce4 · CPhysicsWorld::GetCurrentContactPosition(CInstance*, int, float&, float&) · size=184 · insn=46 */
/* @0x238ce4 push {r3, r4, r5, r6, r7, lr} */
/* @0x238ce8 mov r7, r3 */
/* @0x238cec mov r6, r2 */
/* @0x238cf0 mov r4, r0 */
/* @0x238cf4 bl 0x238cb0 <_ZN13CPhysicsWorld21GetValidCollisionDataEP9CInstance> */
/* @0x238cf8 subs r3, r0, #0 */
/* @0x238cfc beq 0x238d4c <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x68> */
/* @0x238d00 ldr r2, [r3] */
/* @0x238d04 vldr s15, [r4, #96] */
/* @0x238d08 cmp r2, #0 */
/* @0x238d0c ble 0x238d4c <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x68> */
/* @0x238d10 ldr r5, [r3, #0x48] */
/* @0x238d14 cmp r6, r5 */
/* @0x238d18 movgt r12, r3 */
/* @0x238d1c movgt r1, #0 */
/* @0x238d20 bgt 0x238d40 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x5c> */
/* @0x238d24 b 0x238d54 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x70> */
/* @0x238d28 ldr r4, [r12, #0x88] */
/* @0x238d2c add r12, r12, #64 */
/* @0x238d30 add r4, r5, r4 */
/* @0x238d34 cmp r4, r6 */
/* @0x238d38 bge 0x238d5c <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x78> */
/* @0x238d3c mov r5, r4 */
/* @0x238d40 add r1, r1, #1 */
/* @0x238d44 cmp r1, r2 */
/* @0x238d48 bne 0x238d28 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x44> */
/* @0x238d4c mov r0, #0 */
/* @0x238d50 pop {r3, r4, r5, r6, r7, pc} */
/* @0x238d54 mov r1, #0 */
/* @0x238d58 mov r5, r1 */
/* @0x238d5c vmov.f32 s13, #1.000000e+00 */
/* @0x238d60 add r1, r1, r1, lsl #1 */
/* @0x238d64 rsb r5, r5, r6 */
/* @0x238d68 mov r0, #1 */
/* @0x238d6c add r3, r3, r1, lsl #3 */
/* @0x238d70 add r3, r3, #524 */
/* @0x238d74 add r5, r3, r5, lsl #3 */
/* @0x238d78 vldr s14, [r5, #8] */
/* @0x238d7c ldr r3, [sp, #0x18] */
/* @0x238d80 vdiv.f32 s15, s13, s15 */
/* @0x238d84 vmul.f32 s14, s14, s15 */
/* @0x238d88 vstr s14, [r7] */
/* @0x238d8c vldr s14, [r5, #12] */
/* @0x238d90 vmul.f32 s15, s14, s15 */
/* @0x238d94 vstr s15, [r3] */
/* @0x238d98 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x238d9c · CPhysicsWorld::GetCurrentContactNormal(CInstance*, int, float&, float&) · size=140 · insn=35 */
/* @0x238d9c push {r4, r5, r6, r7, r8, lr} */
/* @0x238da0 mov r7, r2 */
/* @0x238da4 mov r8, r3 */
/* @0x238da8 bl 0x238cb0 <_ZN13CPhysicsWorld21GetValidCollisionDataEP9CInstance> */
/* @0x238dac subs r2, r0, #0 */
/* @0x238db0 beq 0x238df8 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x5c> */
/* @0x238db4 ldr r6, [r2] */
/* @0x238db8 cmp r6, #0 */
/* @0x238dbc ble 0x238df8 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x5c> */
/* @0x238dc0 ldr r12, [r2, #0x48] */
/* @0x238dc4 cmp r7, r12 */
/* @0x238dc8 movgt r4, r2 */
/* @0x238dcc movgt r1, #0 */
/* @0x238dd0 bgt 0x238dec <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x50> */
/* @0x238dd4 b 0x238e00 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x64> */
/* @0x238dd8 ldr r5, [r4, #0x88] */
/* @0x238ddc add r4, r4, #64 */
/* @0x238de0 add r12, r12, r5 */
/* @0x238de4 cmp r12, r7 */
/* @0x238de8 bge 0x238e04 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x68> */
/* @0x238dec add r1, r1, #1 */
/* @0x238df0 cmp r1, r6 */
/* @0x238df4 bne 0x238dd8 <_ZN13CPhysicsWorld23GetCurrentContactNormalEP9CInstanceiRfS2_+0x3c> */
/* @0x238df8 mov r0, #0 */
/* @0x238dfc pop {r4, r5, r6, r7, r8, pc} */
/* @0x238e00 mov r1, #0 */
/* @0x238e04 add r1, r1, r1, lsl #1 */
/* @0x238e08 mov r0, #1 */
/* @0x238e0c add r2, r2, r1, lsl #3 */
/* @0x238e10 ldr r3, [r2, #0x20c] */
/* @0x238e14 str r3, [r8] */
/* @0x238e18 ldr r3, [r2, #0x210] */
/* @0x238e1c ldr r2, [sp, #0x18] */
/* @0x238e20 str r3, [r2] */
/* @0x238e24 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x238e28 · CPhysicsWorld::GetCurrentContactPointCount(CInstance*) · size=72 · insn=18 */
/* @0x238e28 push {r3, lr} */
/* @0x238e2c bl 0x238cb0 <_ZN13CPhysicsWorld21GetValidCollisionDataEP9CInstance> */
/* @0x238e30 cmp r0, #0 */
/* @0x238e34 popeq {r3, pc} */
/* @0x238e38 ldr r1, [r0] */
/* @0x238e3c cmp r1, #0 */
/* @0x238e40 ble 0x238e68 <_ZN13CPhysicsWorld27GetCurrentContactPointCountEP9CInstance+0x40> */
/* @0x238e44 mov r3, r0 */
/* @0x238e48 add r1, r0, r1, lsl #6 */
/* @0x238e4c mov r0, #0 */
/* @0x238e50 ldr r2, [r3, #0x48] */
/* @0x238e54 add r3, r3, #64 */
/* @0x238e58 cmp r3, r1 */
/* @0x238e5c add r0, r0, r2 */
/* @0x238e60 bne 0x238e50 <_ZN13CPhysicsWorld27GetCurrentContactPointCountEP9CInstance+0x28> */
/* @0x238e64 pop {r3, pc} */
/* @0x238e68 mov r0, #0 */
/* @0x238e6c pop {r3, pc} */

/* ── FUNC 0x238e70 · CPhysicsWorld::CreateDistanceJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool) · size=240 · insn=60 */
/* @0x238e70 vmov s11, r3 */
/* @0x238e74 ldr r1, [r1] */
/* @0x238e78 push {r4, r5, r6, r7, lr} */
/* @0x238e7c mov r4, r0 */
/* @0x238e80 vldr s15, [r4, #96] */
/* @0x238e84 sub sp, sp, #76 */
/* @0x238e88 vmul.f32 s11, s15, s11 */
/* @0x238e8c vldr s13, [sp, #104] */
/* @0x238e90 vldr s12, [sp, #96] */
/* @0x238e94 vldr s14, [sp, #100] */
/* @0x238e98 ldrh r3, [r1, #4] */
/* @0x238e9c ldr r2, [r2] */
/* @0x238ea0 add r5, sp, #24 */
/* @0x238ea4 tst r3, #2 */
/* @0x238ea8 ldrb r6, [sp, #0x6c] */
/* @0x238eac orreq r3, r3, #2 */
/* @0x238eb0 strheq r3, [r1, #4] */
/* @0x238eb4 ldrh r3, [r2, #4] */
/* @0x238eb8 moveq r0, #0 */
/* @0x238ebc streq r0, [r1, #0xa0] */
/* @0x238ec0 mov lr, #0 */
/* @0x238ec4 tst r3, #2 */
/* @0x238ec8 mov r12, #0 */
/* @0x238ecc orreq r3, r3, #2 */
/* @0x238ed0 strheq r3, [r2, #4] */
/* @0x238ed4 moveq r0, #0 */
/* @0x238ed8 add r3, sp, #16 */
/* @0x238edc streq r0, [r2, #0xa0] */
/* @0x238ee0 mov r0, r5 */
/* @0x238ee4 vmul.f32 s12, s15, s12 */
/* @0x238ee8 str r3, [sp] */
/* @0x238eec add r3, sp, #8 */
/* @0x238ef0 str lr, [sp, #0x1c] */
/* @0x238ef4 str lr, [sp, #0x20] */
/* @0x238ef8 vstr s11, [sp, #8] */
/* @0x238efc str lr, [sp, #0x24] */
/* @0x238f00 mov r7, #3 */
/* @0x238f04 strb lr, [sp, #0x28] */
/* @0x238f08 str r12, [sp, #0x2c] */
/* @0x238f0c str r12, [sp, #0x30] */
/* @0x238f10 str r12, [sp, #0x34] */
/* @0x238f14 str r12, [sp, #0x38] */
/* @0x238f18 str r12, [sp, #0x40] */
/* @0x238f1c str r12, [sp, #0x44] */
/* @0x238f20 mov r12, #1065353216 */
/* @0x238f24 str r7, [sp, #0x18] */
/* @0x238f28 vmul.f32 s14, s15, s14 */
/* @0x238f2c vstr s12, [sp, #12] */
/* @0x238f30 str r12, [sp, #0x3c] */
/* @0x238f34 vmul.f32 s15, s15, s13 */
/* @0x238f38 vstr s14, [sp, #16] */
/* @0x238f3c vstr s15, [sp, #20] */
/* @0x238f40 bl 0x2cd1e0 <_ZN18b2DistanceJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_> */
/* @0x238f44 mov r1, r5 */
/* @0x238f48 mov r0, r4 */
/* @0x238f4c strb r6, [sp, #0x28] */
/* @0x238f50 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x238f54 ldr r0, [r0, #0x8] */
/* @0x238f58 add sp, sp, #76 */
/* @0x238f5c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x238f60 · CPhysicsWorld::CreateRopeJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, bool) · size=240 · insn=60 */
/* @0x238f60 str lr, [sp, #-0x4]! */
/* @0x238f64 vldr s15, [r0, #96] */
/* @0x238f68 sub sp, sp, #44 */
/* @0x238f6c vldr s14, [sp, #48] */
/* @0x238f70 ldr r12, [r1] */
/* @0x238f74 vldr s3, [sp, #56] */
/* @0x238f78 ldr r2, [r2] */
/* @0x238f7c vldr s11, [r12, #16] */
/* @0x238f80 vldr s12, [r2, #16] */
/* @0x238f84 vnmls.f32 s11, s15, s14 */
/* @0x238f88 vmov s9, r3 */
/* @0x238f8c vldr s13, [r12, #12] */
/* @0x238f90 vldr s14, [r2, #12] */
/* @0x238f94 vldr s10, [sp, #52] */
/* @0x238f98 vldr s6, [r12, #20] */
/* @0x238f9c vldr s5, [r12, #24] */
/* @0x238fa0 vldr s8, [r2, #20] */
/* @0x238fa4 vldr s7, [r2, #24] */
/* @0x238fa8 vldr s4, [sp, #60] */
/* @0x238fac ldrh r3, [r12, #4] */
/* @0x238fb0 ldrb lr, [sp, #0x40] */
/* @0x238fb4 tst r3, #2 */
/* @0x238fb8 orreq r3, r3, #2 */
/* @0x238fbc strheq r3, [r12, #4] */
/* @0x238fc0 ldrh r3, [r2, #4] */
/* @0x238fc4 moveq r1, #0 */
/* @0x238fc8 streq r1, [r12, #0xa0] */
/* @0x238fcc tst r3, #2 */
/* @0x238fd0 orreq r3, r3, #2 */
/* @0x238fd4 strheq r3, [r2, #4] */
/* @0x238fd8 moveq r1, #0 */
/* @0x238fdc streq r1, [r2, #0xa0] */
/* @0x238fe0 mov r1, sp */
/* @0x238fe4 str r12, [sp, #0x8] */
/* @0x238fe8 mov r3, #10 */
/* @0x238fec mov r12, #0 */
/* @0x238ff0 strb lr, [sp, #0x10] */
/* @0x238ff4 str r2, [sp, #0xc] */
/* @0x238ff8 stm sp, {r3, r12} */
/* @0x238ffc vnmls.f32 s12, s15, s3 */
/* @0x239000 vnmls.f32 s13, s15, s9 */
/* @0x239004 vnmls.f32 s14, s15, s10 */
/* @0x239008 vmul.f32 s9, s11, s6 */
/* @0x23900c vmul.f32 s10, s12, s8 */
/* @0x239010 vmul.f32 s11, s11, s5 */
/* @0x239014 vmul.f32 s12, s12, s7 */
/* @0x239018 vmla.f32 s9, s13, s5 */
/* @0x23901c vmls.f32 s11, s6, s13 */
/* @0x239020 vstr s9, [sp, #20] */
/* @0x239024 vmla.f32 s10, s14, s7 */
/* @0x239028 vstr s11, [sp, #24] */
/* @0x23902c vmls.f32 s12, s8, s14 */
/* @0x239030 vstr s10, [sp, #28] */
/* @0x239034 vmul.f32 s15, s15, s4 */
/* @0x239038 vstr s12, [sp, #32] */
/* @0x23903c vstr s15, [sp, #36] */
/* @0x239040 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x239044 ldr r0, [r0, #0x8] */
/* @0x239048 add sp, sp, #44 */
/* @0x23904c ldr pc, [sp], #4 */

/* ── FUNC 0x239050 · CPhysicsWorld::CreateRevoluteJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool, float, float, bool, bool) · size=276 · insn=69 */
/* @0x239050 vmov s14, r3 */
/* @0x239054 ldr r1, [r1] */
/* @0x239058 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23905c vpush {d8} */
/* @0x239060 mov r4, r0 */
/* @0x239064 vldr s15, [r4, #96] */
/* @0x239068 sub sp, sp, #76 */
/* @0x23906c vmul.f32 s14, s15, s14 */
/* @0x239070 vldr s13, [sp, #120] */
/* @0x239074 ldrh r3, [r1, #4] */
/* @0x239078 ldr r2, [r2] */
/* @0x23907c add r5, sp, #8 */
/* @0x239080 tst r3, #2 */
/* @0x239084 ldr r11, [sp, #0x80] */
/* @0x239088 orreq r3, r3, #2 */
/* @0x23908c strheq r3, [r1, #4] */
/* @0x239090 ldrh r3, [r2, #4] */
/* @0x239094 moveq r0, #0 */
/* @0x239098 streq r0, [r1, #0xa0] */
/* @0x23909c mov r12, #0 */
/* @0x2390a0 tst r3, #2 */
/* @0x2390a4 ldrb r8, [sp, #0x84] */
/* @0x2390a8 ldr r10, [sp, #0x88] */
/* @0x2390ac orreq r3, r3, #2 */
/* @0x2390b0 ldr r9, [sp, #0x8c] */
/* @0x2390b4 moveq r0, #0 */
/* @0x2390b8 ldrb r7, [sp, #0x90] */
/* @0x2390bc vldr s16, [sp, #124] */
/* @0x2390c0 ldrb r6, [sp, #0x94] */
/* @0x2390c4 vmul.f32 s15, s15, s13 */
/* @0x2390c8 strheq r3, [r2, #4] */
/* @0x2390cc streq r0, [r2, #0xa0] */
/* @0x2390d0 mov r3, sp */
/* @0x2390d4 mov r0, r5 */
/* @0x2390d8 vstr s14, [sp] */
/* @0x2390dc str r12, [sp, #0xc] */
/* @0x2390e0 str r12, [sp, #0x10] */
/* @0x2390e4 str r12, [sp, #0x14] */
/* @0x2390e8 strb r12, [sp, #0x18] */
/* @0x2390ec strb r12, [sp, #0x30] */
/* @0x2390f0 strb r12, [sp, #0x3c] */
/* @0x2390f4 mov r12, #1 */
/* @0x2390f8 str r12, [sp, #0x8] */
/* @0x2390fc mov r12, #0 */
/* @0x239100 str r12, [sp, #0x1c] */
/* @0x239104 str r12, [sp, #0x20] */
/* @0x239108 str r12, [sp, #0x24] */
/* @0x23910c str r12, [sp, #0x28] */
/* @0x239110 str r12, [sp, #0x2c] */
/* @0x239114 str r12, [sp, #0x34] */
/* @0x239118 str r12, [sp, #0x38] */
/* @0x23911c vstr s15, [sp, #4] */
/* @0x239120 str r12, [sp, #0x44] */
/* @0x239124 str r12, [sp, #0x40] */
/* @0x239128 bl 0x2d1fd8 <_ZN18b2RevoluteJointDef10InitializeEP6b2BodyS1_RK6b2Vec2> */
/* @0x23912c mov r1, r5 */
/* @0x239130 mov r0, r4 */
/* @0x239134 vstr s16, [sp, #52] */
/* @0x239138 str r11, [sp, #0x38] */
/* @0x23913c strb r8, [sp, #0x30] */
/* @0x239140 str r10, [sp, #0x44] */
/* @0x239144 str r9, [sp, #0x40] */
/* @0x239148 strb r7, [sp, #0x3c] */
/* @0x23914c strb r6, [sp, #0x18] */
/* @0x239150 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x239154 ldr r0, [r0, #0x8] */
/* @0x239158 add sp, sp, #76 */
/* @0x23915c vpop {d8} */
/* @0x239160 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x239164 · CPhysicsWorld::CreatePrismaticJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, float, bool, float, float, bool, bool) · size=324 · insn=81 */
/* @0x239164 vmov s15, r3 */
/* @0x239168 ldr r1, [r1] */
/* @0x23916c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x239170 vpush {d8} */
/* @0x239174 mov r4, r0 */
/* @0x239178 vldr s14, [r4, #96] */
/* @0x23917c sub sp, sp, #100 */
/* @0x239180 vmul.f32 s15, s14, s15 */
/* @0x239184 vldr s13, [sp, #144] */
/* @0x239188 ldrh r3, [r1, #4] */
/* @0x23918c ldr r2, [r2] */
/* @0x239190 add r5, sp, #24 */
/* @0x239194 tst r3, #2 */
/* @0x239198 ldr lr, [sp, #0x94] */
/* @0x23919c orreq r3, r3, #2 */
/* @0x2391a0 strheq r3, [r1, #4] */
/* @0x2391a4 ldrh r3, [r2, #4] */
/* @0x2391a8 moveq r0, #0 */
/* @0x2391ac ldr r12, [sp, #0x98] */
/* @0x2391b0 vldr s17, [sp, #156] */
/* @0x2391b4 streq r0, [r1, #0xa0] */
/* @0x2391b8 tst r3, #2 */
/* @0x2391bc orreq r3, r3, #2 */
/* @0x2391c0 strheq r3, [r2, #4] */
/* @0x2391c4 moveq r0, #0 */
/* @0x2391c8 add r3, sp, #16 */
/* @0x2391cc streq r0, [r2, #0xa0] */
/* @0x2391d0 mov r0, r5 */
/* @0x2391d4 str r3, [sp] */
/* @0x2391d8 add r3, sp, #8 */
/* @0x2391dc vmul.f32 s14, s14, s13 */
/* @0x2391e0 vstr s15, [sp, #8] */
/* @0x2391e4 vldr s16, [sp, #160] */
/* @0x2391e8 ldrb r8, [sp, #0xa4] */
/* @0x2391ec ldr r11, [sp, #0xa8] */
/* @0x2391f0 mov r9, #2 */
/* @0x2391f4 ldr r10, [sp, #0xac] */
/* @0x2391f8 ldrb r7, [sp, #0xb0] */
/* @0x2391fc ldrb r6, [sp, #0xb4] */
/* @0x239200 str lr, [sp, #0x10] */
/* @0x239204 mov lr, #0 */
/* @0x239208 str r12, [sp, #0x14] */
/* @0x23920c mov r12, #0 */
/* @0x239210 str lr, [sp, #0x1c] */
/* @0x239214 str lr, [sp, #0x20] */
/* @0x239218 str lr, [sp, #0x24] */
/* @0x23921c strb lr, [sp, #0x28] */
/* @0x239220 strb lr, [sp, #0x48] */
/* @0x239224 strb lr, [sp, #0x54] */
/* @0x239228 str r12, [sp, #0x2c] */
/* @0x23922c str r9, [sp, #0x18] */
/* @0x239230 str r12, [sp, #0x30] */
/* @0x239234 vstr s14, [sp, #12] */
/* @0x239238 str r12, [sp, #0x34] */
/* @0x23923c str r12, [sp, #0x38] */
/* @0x239240 str r12, [sp, #0x40] */
/* @0x239244 str r12, [sp, #0x44] */
/* @0x239248 str r12, [sp, #0x4c] */
/* @0x23924c str r12, [sp, #0x50] */
/* @0x239250 str r12, [sp, #0x58] */
/* @0x239254 str r12, [sp, #0x5c] */
/* @0x239258 mov r12, #1065353216 */
/* @0x23925c str r12, [sp, #0x3c] */
/* @0x239260 bl 0x2cff74 <_ZN19b2PrismaticJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_> */
/* @0x239264 vldr s15, [r4, #96] */
/* @0x239268 vmul.f32 s17, s15, s17 */
/* @0x23926c mov r0, r4 */
/* @0x239270 mov r1, r5 */
/* @0x239274 strb r8, [sp, #0x48] */
/* @0x239278 str r11, [sp, #0x58] */
/* @0x23927c str r10, [sp, #0x5c] */
/* @0x239280 strb r7, [sp, #0x54] */
/* @0x239284 strb r6, [sp, #0x28] */
/* @0x239288 vmul.f32 s15, s15, s16 */
/* @0x23928c vstr s17, [sp, #76] */
/* @0x239290 vstr s15, [sp, #80] */
/* @0x239294 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x239298 ldr r0, [r0, #0x8] */
/* @0x23929c add sp, sp, #100 */
/* @0x2392a0 vpop {d8} */
/* @0x2392a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2392a8 · CPhysicsWorld::CreatePulleyJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, float, float, float, float, bool) · size=412 · insn=103 */
/* @0x2392a8 push {r4, r5, r6, r7, lr} */
/* @0x2392ac vpush {d8, d9} */
/* @0x2392b0 sub sp, sp, #116 */
/* @0x2392b4 vldr s12, [sp, #168] */
/* @0x2392b8 ldr r1, [r1] */
/* @0x2392bc vldr s14, [sp, #176] */
/* @0x2392c0 ldr r2, [r2] */
/* @0x2392c4 vldr s5, [r1, #24] */
/* @0x2392c8 vldr s7, [r1, #20] */
/* @0x2392cc vldr s10, [r2, #20] */
/* @0x2392d0 vldr s8, [r2, #24] */
/* @0x2392d4 vmul.f32 s11, s12, s5 */
/* @0x2392d8 vldr s6, [sp, #164] */
/* @0x2392dc vldr s9, [sp, #172] */
/* @0x2392e0 vmov s18, r3 */
/* @0x2392e4 mov r4, r0 */
/* @0x2392e8 vldr s15, [r4, #96] */
/* @0x2392ec ldrh r3, [r1, #4] */
/* @0x2392f0 vldr s2, [r1, #12] */
/* @0x2392f4 vldr s1, [r1, #16] */
/* @0x2392f8 tst r3, #2 */
/* @0x2392fc vldr s4, [r2, #12] */
/* @0x239300 orreq r3, r3, #2 */
/* @0x239304 strheq r3, [r1, #4] */
/* @0x239308 ldrh r3, [r2, #4] */
/* @0x23930c moveq r0, #0 */
/* @0x239310 streq r0, [r1, #0xa0] */
/* @0x239314 vldr s3, [r2, #16] */
/* @0x239318 tst r3, #2 */
/* @0x23931c vldr s0, [sp, #160] */
/* @0x239320 orreq r3, r3, #2 */
/* @0x239324 mov r12, #0 */
/* @0x239328 strheq r3, [r2, #4] */
/* @0x23932c moveq r0, #0 */
/* @0x239330 vmul.f32 s13, s14, s8 */
/* @0x239334 streq r0, [r2, #0xa0] */
/* @0x239338 mov r3, #0 */
/* @0x23933c vldr s17, [sp, #152] */
/* @0x239340 vldr s16, [sp, #156] */
/* @0x239344 ldr r7, [sp, #0xb4] */
/* @0x239348 ldrb r6, [sp, #0xb8] */
/* @0x23934c mov r0, #4 */
/* @0x239350 str r12, [sp, #0x34] */
/* @0x239354 add r5, sp, #48 */
/* @0x239358 str r12, [sp, #0x38] */
/* @0x23935c mov lr, #0 */
/* @0x239360 str r12, [sp, #0x3c] */
/* @0x239364 mov r12, #1 */
/* @0x239368 str r0, [sp, #0x30] */
/* @0x23936c mov r0, r5 */
/* @0x239370 str r3, [sp, #0x58] */
/* @0x239374 movt lr, #0xbf80 */
/* @0x239378 str r3, [sp, #0x60] */
/* @0x23937c str r3, [sp, #0x64] */
/* @0x239380 str r3, [sp, #0x68] */
/* @0x239384 add r3, sp, #16 */
/* @0x239388 vmul.f32 s12, s12, s7 */
/* @0x23938c strb r12, [sp, #0x40] */
/* @0x239390 str r7, [sp, #0xc] */
/* @0x239394 mov r12, #1065353216 */
/* @0x239398 str r12, [sp, #0x48] */
/* @0x23939c str r12, [sp, #0x4c] */
/* @0x2393a0 str r12, [sp, #0x50] */
/* @0x2393a4 str r12, [sp, #0x5c] */
/* @0x2393a8 str r12, [sp, #0x6c] */
/* @0x2393ac add r12, sp, #24 */
/* @0x2393b0 str r12, [sp] */
/* @0x2393b4 add r12, sp, #32 */
/* @0x2393b8 str r12, [sp, #0x4] */
/* @0x2393bc add r12, sp, #40 */
/* @0x2393c0 str r12, [sp, #0x8] */
/* @0x2393c4 str lr, [sp, #0x44] */
/* @0x2393c8 str lr, [sp, #0x54] */
/* @0x2393cc vmul.f32 s14, s14, s10 */
/* @0x2393d0 vnmls.f32 s12, s6, s5 */
/* @0x2393d4 vnmls.f32 s14, s9, s8 */
/* @0x2393d8 vmla.f32 s11, s6, s7 */
/* @0x2393dc vmla.f32 s13, s9, s10 */
/* @0x2393e0 vmul.f32 s10, s15, s18 */
/* @0x2393e4 vmul.f32 s9, s15, s17 */
/* @0x2393e8 vstr s10, [sp, #16] */
/* @0x2393ec vmul.f32 s10, s15, s16 */
/* @0x2393f0 vstr s9, [sp, #20] */
/* @0x2393f4 vmul.f32 s15, s15, s0 */
/* @0x2393f8 vstr s10, [sp, #24] */
/* @0x2393fc vadd.f32 s11, s11, s1 */
/* @0x239400 vstr s15, [sp, #28] */
/* @0x239404 vadd.f32 s12, s12, s2 */
/* @0x239408 vstr s11, [sp, #36] */
/* @0x23940c vadd.f32 s13, s13, s3 */
/* @0x239410 vstr s12, [sp, #32] */
/* @0x239414 vadd.f32 s14, s14, s4 */
/* @0x239418 vstr s13, [sp, #44] */
/* @0x23941c vstr s14, [sp, #40] */
/* @0x239420 bl 0x2d0f08 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f> */
/* @0x239424 mov r1, r5 */
/* @0x239428 mov r0, r4 */
/* @0x23942c strb r6, [sp, #0x40] */
/* @0x239430 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x239434 ldr r0, [r0, #0x8] */
/* @0x239438 add sp, sp, #116 */
/* @0x23943c vpop {d8, d9} */
/* @0x239440 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x239444 · CPhysicsWorld::CreateWheelJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool, float, float, float, float, bool) · size=300 · insn=75 */
/* @0x239444 vmov s14, r3 */
/* @0x239448 ldr r1, [r1] */
/* @0x23944c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x239450 mov r4, r0 */
/* @0x239454 vldr s15, [r4, #96] */
/* @0x239458 sub sp, sp, #92 */
/* @0x23945c vmul.f32 s14, s15, s14 */
/* @0x239460 vldr s13, [sp, #128] */
/* @0x239464 ldrh r3, [r1, #4] */
/* @0x239468 ldr r2, [r2] */
/* @0x23946c add r5, sp, #24 */
/* @0x239470 tst r3, #2 */
/* @0x239474 ldr lr, [sp, #0x84] */
/* @0x239478 orreq r3, r3, #2 */
/* @0x23947c strheq r3, [r1, #4] */
/* @0x239480 ldrh r3, [r2, #4] */
/* @0x239484 moveq r0, #0 */
/* @0x239488 ldr r12, [sp, #0x88] */
/* @0x23948c streq r0, [r1, #0xa0] */
/* @0x239490 tst r3, #2 */
/* @0x239494 ldrb r7, [sp, #0x8c] */
/* @0x239498 orreq r3, r3, #2 */
/* @0x23949c ldr r11, [sp, #0x90] */
/* @0x2394a0 moveq r0, #0 */
/* @0x2394a4 ldr r10, [sp, #0x94] */
/* @0x2394a8 ldr r9, [sp, #0x98] */
/* @0x2394ac vmul.f32 s15, s15, s13 */
/* @0x2394b0 ldr r8, [sp, #0x9c] */
/* @0x2394b4 ldrb r6, [sp, #0xa0] */
/* @0x2394b8 vstr s14, [sp, #8] */
/* @0x2394bc strheq r3, [r2, #4] */
/* @0x2394c0 add r3, sp, #16 */
/* @0x2394c4 streq r0, [r2, #0xa0] */
/* @0x2394c8 mov r0, r5 */
/* @0x2394cc str r3, [sp] */
/* @0x2394d0 add r3, sp, #8 */
/* @0x2394d4 str lr, [sp, #0x10] */
/* @0x2394d8 mov lr, #1065353216 */
/* @0x2394dc str r12, [sp, #0x14] */
/* @0x2394e0 mov r12, #0 */
/* @0x2394e4 str r12, [sp, #0x1c] */
/* @0x2394e8 str r12, [sp, #0x20] */
/* @0x2394ec str r12, [sp, #0x24] */
/* @0x2394f0 strb r12, [sp, #0x28] */
/* @0x2394f4 strb r12, [sp, #0x44] */
/* @0x2394f8 mov r12, #7 */
/* @0x2394fc str r12, [sp, #0x18] */
/* @0x239500 mov r12, #0 */
/* @0x239504 str r12, [sp, #0x2c] */
/* @0x239508 str r12, [sp, #0x30] */
/* @0x23950c str r12, [sp, #0x34] */
/* @0x239510 str r12, [sp, #0x38] */
/* @0x239514 str r12, [sp, #0x40] */
/* @0x239518 vstr s15, [sp, #12] */
/* @0x23951c str r12, [sp, #0x48] */
/* @0x239520 str r12, [sp, #0x4c] */
/* @0x239524 movw r12, #0x3333 */
/* @0x239528 str lr, [sp, #0x3c] */
/* @0x23952c movt r12, #0x3f33 */
/* @0x239530 str r12, [sp, #0x54] */
/* @0x239534 mov r12, #1073741824 */
/* @0x239538 str r12, [sp, #0x50] */
/* @0x23953c bl 0x2d4170 <_ZN15b2WheelJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_> */
/* @0x239540 mov r1, r5 */
/* @0x239544 mov r0, r4 */
/* @0x239548 strb r7, [sp, #0x44] */
/* @0x23954c str r11, [sp, #0x48] */
/* @0x239550 str r10, [sp, #0x4c] */
/* @0x239554 str r9, [sp, #0x50] */
/* @0x239558 str r8, [sp, #0x54] */
/* @0x23955c strb r6, [sp, #0x28] */
/* @0x239560 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x239564 ldr r0, [r0, #0x8] */
/* @0x239568 add sp, sp, #92 */
/* @0x23956c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x239570 · CPhysicsWorld::CreateWeldJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, bool) · size=260 · insn=65 */
/* @0x239570 vmov s14, r3 */
/* @0x239574 ldr r1, [r1] */
/* @0x239578 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x23957c vpush {d8} */
/* @0x239580 mov r4, r0 */
/* @0x239584 vldr s15, [r4, #96] */
/* @0x239588 sub sp, sp, #60 */
/* @0x23958c vmul.f32 s14, s15, s14 */
/* @0x239590 vldr s13, [sp, #96] */
/* @0x239594 ldrh r3, [r1, #4] */
/* @0x239598 ldr r2, [r2] */
/* @0x23959c add r5, sp, #8 */
/* @0x2395a0 tst r3, #2 */
/* @0x2395a4 mov r12, #0 */
/* @0x2395a8 orreq r3, r3, #2 */
/* @0x2395ac strheq r3, [r1, #4] */
/* @0x2395b0 ldrh r3, [r2, #4] */
/* @0x2395b4 moveq r0, #0 */
/* @0x2395b8 streq r0, [r1, #0xa0] */
/* @0x2395bc mov lr, #0 */
/* @0x2395c0 tst r3, #2 */
/* @0x2395c4 vldr s16, [sp, #100] */
/* @0x2395c8 orreq r3, r3, #2 */
/* @0x2395cc strheq r3, [r2, #4] */
/* @0x2395d0 moveq r0, #0 */
/* @0x2395d4 mov r3, sp */
/* @0x2395d8 streq r0, [r2, #0xa0] */
/* @0x2395dc mov r0, r5 */
/* @0x2395e0 ldr r9, [sp, #0x68] */
/* @0x2395e4 mov r7, #8 */
/* @0x2395e8 vmul.f32 s15, s15, s13 */
/* @0x2395ec ldr r8, [sp, #0x6c] */
/* @0x2395f0 ldrb r6, [sp, #0x70] */
/* @0x2395f4 vstr s14, [sp] */
/* @0x2395f8 str lr, [sp, #0xc] */
/* @0x2395fc str lr, [sp, #0x10] */
/* @0x239600 str lr, [sp, #0x14] */
/* @0x239604 strb lr, [sp, #0x18] */
/* @0x239608 str r12, [sp, #0x1c] */
/* @0x23960c str r12, [sp, #0x20] */
/* @0x239610 str r12, [sp, #0x24] */
/* @0x239614 str r12, [sp, #0x28] */
/* @0x239618 str r12, [sp, #0x2c] */
/* @0x23961c str r12, [sp, #0x30] */
/* @0x239620 str r12, [sp, #0x34] */
/* @0x239624 vstr s15, [sp, #4] */
/* @0x239628 str r7, [sp, #0x8] */
/* @0x23962c bl 0x2d3698 <_ZN14b2WeldJointDef10InitializeEP6b2BodyS1_RK6b2Vec2> */
/* @0x239630 vldr s15, [pc, #52] */
/* @0x239634 vnmul.f32 s16, s16, s15 */
/* @0x239638 vldr s15, [pc, #48] */
/* @0x23963c mov r1, r5 */
/* @0x239640 mov r0, r4 */
/* @0x239644 str r9, [sp, #0x30] */
/* @0x239648 str r8, [sp, #0x34] */
/* @0x23964c strb r6, [sp, #0x18] */
/* @0x239650 vdiv.f32 s16, s16, s15 */
/* @0x239654 vstr s16, [sp, #44] */
/* @0x239658 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x23965c ldr r0, [r0, #0x8] */
/* @0x239660 add sp, sp, #60 */
/* @0x239664 vpop {d8} */
/* @0x239668 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x23966c teqmi r4, #0 */
/* @0x239670 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x239674 · CPhysicsWorld::CreateFrictionJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool) · size=216 · insn=54 */
/* @0x239674 vmov s14, r3 */
/* @0x239678 ldr r1, [r1] */
/* @0x23967c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x239680 mov r4, r0 */
/* @0x239684 vldr s15, [r4, #96] */
/* @0x239688 sub sp, sp, #60 */
/* @0x23968c vmul.f32 s14, s15, s14 */
/* @0x239690 vldr s13, [sp, #88] */
/* @0x239694 ldrh r3, [r1, #4] */
/* @0x239698 ldr r2, [r2] */
/* @0x23969c add r5, sp, #12 */
/* @0x2396a0 tst r3, #2 */
/* @0x2396a4 ldr r9, [sp, #0x5c] */
/* @0x2396a8 orreq r3, r3, #2 */
/* @0x2396ac strheq r3, [r1, #4] */
/* @0x2396b0 ldrh r3, [r2, #4] */
/* @0x2396b4 moveq r0, #0 */
/* @0x2396b8 streq r0, [r1, #0xa0] */
/* @0x2396bc mov r12, #0 */
/* @0x2396c0 tst r3, #2 */
/* @0x2396c4 ldr r8, [sp, #0x60] */
/* @0x2396c8 ldrb r6, [sp, #0x64] */
/* @0x2396cc orreq r3, r3, #2 */
/* @0x2396d0 moveq r0, #0 */
/* @0x2396d4 strheq r3, [r2, #4] */
/* @0x2396d8 streq r0, [r2, #0xa0] */
/* @0x2396dc add r3, sp, #4 */
/* @0x2396e0 mov r0, r5 */
/* @0x2396e4 mov lr, #0 */
/* @0x2396e8 vmul.f32 s15, s15, s13 */
/* @0x2396ec str lr, [sp, #0x10] */
/* @0x2396f0 str lr, [sp, #0x14] */
/* @0x2396f4 vstr s14, [sp, #4] */
/* @0x2396f8 str lr, [sp, #0x18] */
/* @0x2396fc mov r7, #9 */
/* @0x239700 strb lr, [sp, #0x1c] */
/* @0x239704 str r12, [sp, #0x20] */
/* @0x239708 str r12, [sp, #0x24] */
/* @0x23970c str r12, [sp, #0x28] */
/* @0x239710 str r12, [sp, #0x2c] */
/* @0x239714 str r12, [sp, #0x30] */
/* @0x239718 str r12, [sp, #0x34] */
/* @0x23971c str r7, [sp, #0xc] */
/* @0x239720 vstr s15, [sp, #8] */
/* @0x239724 bl 0x2cd998 <_ZN18b2FrictionJointDef10InitializeEP6b2BodyS1_RK6b2Vec2> */
/* @0x239728 mov r1, r5 */
/* @0x23972c mov r0, r4 */
/* @0x239730 str r9, [sp, #0x30] */
/* @0x239734 str r8, [sp, #0x34] */
/* @0x239738 strb r6, [sp, #0x1c] */
/* @0x23973c bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x239740 ldr r0, [r0, #0x8] */
/* @0x239744 add sp, sp, #60 */
/* @0x239748 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x23974c · CPhysicsWorld::CreateGearJoint(CPhysicsObject*, CPhysicsObject*, CPhysicsJoint*, CPhysicsJoint*, float) · size=204 · insn=51 */
/* @0x23974c push {r4, lr} */
/* @0x239750 sub sp, sp, #32 */
/* @0x239754 ldr r4, [r3, #0x4] */
/* @0x239758 ldr r3, [r4, #0x4] */
/* @0x23975c sub r3, r3, #1 */
/* @0x239760 cmp r3, #1 */
/* @0x239764 bls 0x239790 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0x44> */
/* @0x239768 ldr r12, [sp, #0x28] */
/* @0x23976c ldr r3, [r12, #0x4] */
/* @0x239770 ldr r12, [r3, #0x4] */
/* @0x239774 sub r12, r12, #1 */
/* @0x239778 cmp r12, #1 */
/* @0x23977c movls lr, r3 */
/* @0x239780 bls 0x239798 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0x4c> */
/* @0x239784 mvn r0, #0 */
/* @0x239788 add sp, sp, #32 */
/* @0x23978c pop {r4, pc} */
/* @0x239790 ldr r3, [sp, #0x28] */
/* @0x239794 ldr lr, [r3, #0x4] */
/* @0x239798 ldr r12, [r1] */
/* @0x23979c ldrh r3, [r12, #4] */
/* @0x2397a0 tst r3, #2 */
/* @0x2397a4 beq 0x239804 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0xb8> */
/* @0x2397a8 ldr r3, [r2] */
/* @0x2397ac vldr s15, [sp, #44] */
/* @0x2397b0 ldrh r2, [r3, #4] */
/* @0x2397b4 tst r2, #2 */
/* @0x2397b8 orreq r2, r2, #2 */
/* @0x2397bc strheq r2, [r3, #4] */
/* @0x2397c0 moveq r1, #0 */
/* @0x2397c4 streq r1, [r3, #0xa0] */
/* @0x2397c8 mov r1, sp */
/* @0x2397cc mov r2, #0 */
/* @0x2397d0 str r3, [sp, #0xc] */
/* @0x2397d4 vstr s15, [sp, #28] */
/* @0x2397d8 mov r3, #6 */
/* @0x2397dc str r12, [sp, #0x8] */
/* @0x2397e0 str r4, [sp, #0x14] */
/* @0x2397e4 str lr, [sp, #0x18] */
/* @0x2397e8 str r2, [sp, #0x4] */
/* @0x2397ec strb r2, [sp, #0x10] */
/* @0x2397f0 str r3, [sp] */
/* @0x2397f4 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef> */
/* @0x2397f8 ldr r0, [r0, #0x8] */
/* @0x2397fc add sp, sp, #32 */
/* @0x239800 pop {r4, pc} */
/* @0x239804 orr r3, r3, #2 */
/* @0x239808 mov r1, #0 */
/* @0x23980c strh r3, [r12, #4] */
/* @0x239810 str r1, [r12, #0xa0] */
/* @0x239814 b 0x2397a8 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0x5c> */

/* ── FUNC 0x239818 · CPhysicsWorld::TestOverlap(CInstance*, CInstance*, float, float, float) · size=204 · insn=51 */
/* @0x239818 push {r4, r5, r6, r7, r8, lr} */
/* @0x23981c sub sp, sp, #24 */
/* @0x239820 mov r5, r1 */
/* @0x239824 mov r6, r2 */
/* @0x239828 ldr r4, [sp, #0x34] */
/* @0x23982c ldr r1, [sp, #0x30] */
/* @0x239830 str r3, [sp, #0x8] */
/* @0x239834 mov r0, r4 */
/* @0x239838 str r1, [sp, #0xc] */
/* @0x23983c bl 0xb6580 <sinf@plt> */
/* @0x239840 str r0, [sp, #0x10] */
/* @0x239844 mov r0, r4 */
/* @0x239848 bl 0xb658c <cosf@plt> */
/* @0x23984c ldr r3, [r5, #0x84] */
/* @0x239850 cmp r3, #0 */
/* @0x239854 str r0, [sp, #0x14] */
/* @0x239858 beq 0x2398d8 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xc0> */
/* @0x23985c ldr r2, [r6, #0x84] */
/* @0x239860 cmp r2, #0 */
/* @0x239864 beq 0x2398d8 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xc0> */
/* @0x239868 ldr r3, [r3] */
/* @0x23986c ldr r8, [r2] */
/* @0x239870 ldr r5, [r3, #0x74] */
/* @0x239874 cmp r5, #0 */
/* @0x239878 beq 0x2398d8 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xc0> */
/* @0x23987c add r7, r8, #12 */
/* @0x239880 add r6, sp, #8 */
/* @0x239884 ldr r4, [r8, #0x74] */
/* @0x239888 cmp r4, #0 */
/* @0x23988c bne 0x2398a0 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0x88> */
/* @0x239890 b 0x2398cc <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xb4> */
/* @0x239894 ldr r4, [r4, #0x4] */
/* @0x239898 cmp r4, #0 */
/* @0x23989c beq 0x2398cc <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xb4> */
/* @0x2398a0 mov r1, #0 */
/* @0x2398a4 ldr r0, [r5, #0xc] */
/* @0x2398a8 ldr r2, [r4, #0xc] */
/* @0x2398ac mov r3, r1 */
/* @0x2398b0 stm sp, {r6, r7} */
/* @0x2398b4 bl 0x2c3abc <_Z13b2TestOverlapPK7b2ShapeiS1_iRK11b2TransformS4_> */
/* @0x2398b8 cmp r0, #0 */
/* @0x2398bc beq 0x239894 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0x7c> */
/* @0x2398c0 mov r0, #1 */
/* @0x2398c4 add sp, sp, #24 */
/* @0x2398c8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2398cc ldr r5, [r5, #0x4] */
/* @0x2398d0 cmp r5, #0 */
/* @0x2398d4 bne 0x239884 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0x6c> */
/* @0x2398d8 mov r0, #0 */
/* @0x2398dc add sp, sp, #24 */
/* @0x2398e0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2398e4 · CPhysicsWorld::CreateParticle(unsigned int, float, float, float, float, unsigned int, float, int) · size=184 · insn=46 */
/* @0x2398e4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2398e8 vldr s14, [pc, #164] */
/* @0x2398ec sub sp, sp, #32 */
/* @0x2398f0 vldr s11, [sp, #68] */
/* @0x2398f4 vmul.f32 s14, s11, s14 */
/* @0x2398f8 vldr s15, [r0, #96] */
/* @0x2398fc vmov s9, r2 */
/* @0x239900 vldr s13, [sp, #56] */
/* @0x239904 vldr s12, [sp, #60] */
/* @0x239908 ldr r12, [pc, #0x88] */
/* @0x23990c ldr lr, [sp, #0x40] */
/* @0x239910 mov r4, r0 */
/* @0x239914 ldr r12, [pc, r12] */
/* @0x239918 mov r5, r1 */
/* @0x23991c ldr r6, [sp, #0x48] */
/* @0x239920 ubfx r8, lr, #0x8, #0x8 */
/* @0x239924 ldm r12, {r0, r1} */
/* @0x239928 add r12, sp, #16 */
/* @0x23992c str r5, [sp, #0x4] */
/* @0x239930 add r5, sp, #8 */
/* @0x239934 strb lr, [sp, #0x18] */
/* @0x239938 ubfx r7, lr, #0x10, #0x8 */
/* @0x23993c stm r5, {r0, r1} */
/* @0x239940 strb r8, [sp, #0x19] */
/* @0x239944 stm r12, {r0, r1} */
/* @0x239948 add r1, sp, #4 */
/* @0x23994c vcvt.s32.f32 s14, s14 */
/* @0x239950 ldr r0, [r4, #0x10] */
/* @0x239954 strb r7, [sp, #0x1a] */
/* @0x239958 str r6, [sp, #0x1c] */
/* @0x23995c vmul.f32 s10, s15, s9 */
/* @0x239960 vmov s9, r3 */
/* @0x239964 vmov r3, s14 */
/* @0x239968 vmul.f32 s11, s15, s9 */
/* @0x23996c vstr s10, [sp, #8] */
/* @0x239970 strb r3, [sp, #0x1b] */
/* @0x239974 vmul.f32 s13, s15, s13 */
/* @0x239978 vstr s11, [sp, #12] */
/* @0x23997c vmul.f32 s15, s15, s12 */
/* @0x239980 vstr s13, [sp, #16] */
/* @0x239984 vstr s15, [sp, #20] */
/* @0x239988 bl 0x2cb4a4 <_ZN7b2World14CreateParticleERK13b2ParticleDef> */
/* @0x23998c add sp, sp, #32 */
/* @0x239990 pop {r4, r5, r6, r7, r8, pc} */
/* @0x239994 cmnmi pc, #0 */
/* @0x239998 andseq r7, r11, r4, asr #23 */

/* ── FUNC 0x23999c · CPhysicsWorld::DeleteParticle(int) · size=12 · insn=3 */
/* @0x23999c ldr r0, [r0, #0x10] */
/* @0x2399a0 mov r2, #0 */
/* @0x2399a4 b 0x2cb4cc <_ZN7b2World15DestroyParticleEib> */

/* ── FUNC 0x2399a8 · CPhysicsWorld::BeginParticleGroup(unsigned int, unsigned int, float, float, float, float, float, float, unsigned int, float, float, int) · size=196 · insn=49 */
/* @0x2399a8 push {r4, r5} */
/* @0x2399ac vldr s13, [pc, #172] */
/* @0x2399b0 vldr s7, [sp, #12] */
/* @0x2399b4 vldr s6, [sp, #24] */
/* @0x2399b8 vnmul.f32 s7, s7, s13 */
/* @0x2399bc vldr s14, [pc, #160] */
/* @0x2399c0 vldr s8, [sp, #32] */
/* @0x2399c4 vldr s12, [pc, #156] */
/* @0x2399c8 vldr s15, [r0, #96] */
/* @0x2399cc vldr s9, [sp, #8] */
/* @0x2399d0 vldr s10, [sp, #16] */
/* @0x2399d4 vldr s11, [sp, #20] */
/* @0x2399d8 ldr r12, [sp, #0x1c] */
/* @0x2399dc mov r5, #1 */
/* @0x2399e0 ldr r4, [sp, #0x28] */
/* @0x2399e4 str r2, [r0, #0x18] */
/* @0x2399e8 ubfx r2, r12, #0x10, #0x8 */
/* @0x2399ec strb r2, [r0, #0x36] */
/* @0x2399f0 ldr r2, [sp, #0x24] */
/* @0x2399f4 str r1, [r0, #0x14] */
/* @0x2399f8 ubfx r1, r12, #0x8, #0x8 */
/* @0x2399fc strb r5, [r0, #0x40] */
/* @0x239a00 str r4, [r0, #0x44] */
/* @0x239a04 vmul.f32 s13, s6, s13 */
/* @0x239a08 strb r12, [r0, #0x34] */
/* @0x239a0c strb r1, [r0, #0x35] */
/* @0x239a10 str r2, [r0, #0x38] */
/* @0x239a14 pop {r4, r5} */
/* @0x239a18 vdiv.f32 s7, s7, s14 */
/* @0x239a1c vdiv.f32 s14, s13, s14 */
/* @0x239a20 vstr s7, [r0, #36] */
/* @0x239a24 vmov s13, r3 */
/* @0x239a28 vmul.f32 s12, s8, s12 */
/* @0x239a2c vstr s14, [r0, #48] */
/* @0x239a30 vcvt.s32.f32 s12, s12 */
/* @0x239a34 vmul.f32 s14, s15, s13 */
/* @0x239a38 vmov r3, s12 */
/* @0x239a3c vmul.f32 s13, s15, s9 */
/* @0x239a40 vstr s14, [r0, #28] */
/* @0x239a44 strb r3, [r0, #0x37] */
/* @0x239a48 vmul.f32 s14, s15, s10 */
/* @0x239a4c vstr s13, [r0, #32] */
/* @0x239a50 vmul.f32 s15, s15, s11 */
/* @0x239a54 vstr s14, [r0, #40] */
/* @0x239a58 vstr s15, [r0, #44] */
/* @0x239a5c bx lr */
/* @0x239a60 ldrdmi r0, r1, [r9], #-251 */
/* @0x239a64 teqmi r4, #0 */
/* @0x239a68 cmnmi pc, #0 */

/* ── FUNC 0x239a6c · CPhysicsWorld::ParticleGroupCircle(float) · size=120 · insn=30 */
/* @0x239a6c push {r4, lr} */
/* @0x239a70 vpush {d8} */
/* @0x239a74 mov r4, r0 */
/* @0x239a78 ldr r0, [r0, #0x3c] */
/* @0x239a7c vmov s16, r1 */
/* @0x239a80 cmp r0, #0 */
/* @0x239a84 beq 0x239a94 <_ZN13CPhysicsWorld19ParticleGroupCircleEf+0x28> */
/* @0x239a88 ldr r3, [r0] */
/* @0x239a8c ldr r3, [r3, #0x4] */
/* @0x239a90 blx r3 */
/* @0x239a94 mov r0, #20 */
/* @0x239a98 bl 0x27c524 <_Znwj> */
/* @0x239a9c vldr s15, [r4, #96] */
/* @0x239aa0 vmul.f32 s16, s16, s15 */
/* @0x239aa4 ldr r2, [pc, #0x34] */
/* @0x239aa8 mov r1, #0 */
/* @0x239aac ldr r2, [pc, r2] */
/* @0x239ab0 add r2, r2, #8 */
/* @0x239ab4 vabs.f32 s16, s16 */
/* @0x239ab8 mov r3, r0 */
/* @0x239abc vstr s16, [r3, #8] */
/* @0x239ac0 vpop {d8} */
/* @0x239ac4 mov r0, #0 */
/* @0x239ac8 str r1, [r3, #0xc] */
/* @0x239acc str r0, [r3, #0x4] */
/* @0x239ad0 str r1, [r3, #0x10] */
/* @0x239ad4 str r2, [r3] */
/* @0x239ad8 str r3, [r4, #0x3c] */
/* @0x239adc pop {r4, pc} */
/* @0x239ae0 andseq r7, r11, r0, lsl #20 */

/* ── FUNC 0x239ae4 · CPhysicsWorld::ParticleGroupBox(float, float) · size=180 · insn=45 */
/* @0x239ae4 push {r3, r4, r5, lr} */
/* @0x239ae8 vpush {d8} */
/* @0x239aec vmov.f32 s15, #1.000000e+00 */
/* @0x239af0 vmov s17, r1 */
/* @0x239af4 mov r5, r0 */
/* @0x239af8 vmov s16, r2 */
/* @0x239afc ldr r0, [r0, #0x3c] */
/* @0x239b00 vcmp.f32 s17, #0 */
/* @0x239b04 vmrs APSR_nzcv, fpscr */
/* @0x239b08 vcmp.f32 s16, #0 */
/* @0x239b0c vmoveq.f32 s17, s15 */
/* @0x239b10 vmrs APSR_nzcv, fpscr */
/* @0x239b14 vmoveq.f32 s16, s15 */
/* @0x239b18 cmp r0, #0 */
/* @0x239b1c beq 0x239b2c <_ZN13CPhysicsWorld16ParticleGroupBoxEff+0x48> */
/* @0x239b20 ldr r3, [r0] */
/* @0x239b24 ldr r3, [r3, #0x4] */
/* @0x239b28 blx r3 */
/* @0x239b2c mov r0, #152 */
/* @0x239b30 bl 0x27c524 <_Znwj> */
/* @0x239b34 vldr s15, [r5, #96] */
/* @0x239b38 vmul.f32 s17, s15, s17 */
/* @0x239b3c ldr r3, [pc, #0x50] */
/* @0x239b40 mov r2, #2 */
/* @0x239b44 movw r1, #0xd70a */
/* @0x239b48 ldr r3, [pc, r3] */
/* @0x239b4c movt r1, #0x3c23 */
/* @0x239b50 add r3, r3, #8 */
/* @0x239b54 vmul.f32 s16, s16, s15 */
/* @0x239b58 str r2, [r0, #0x4] */
/* @0x239b5c mov r2, #0 */
/* @0x239b60 str r1, [r0, #0x8] */
/* @0x239b64 mov r4, r0 */
/* @0x239b68 str r3, [r0] */
/* @0x239b6c mov r3, #0 */
/* @0x239b70 str r2, [r0, #0x94] */
/* @0x239b74 vmov r1, s17 */
/* @0x239b78 vmov r2, s16 */
/* @0x239b7c str r3, [r0, #0xc] */
/* @0x239b80 str r3, [r0, #0x10] */
/* @0x239b84 bl 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff> */
/* @0x239b88 vpop {d8} */
/* @0x239b8c str r4, [r5, #0x3c] */
/* @0x239b90 pop {r3, r4, r5, pc} */
/* @0x239b94 andseq r7, r11, r8, ror #18 */

/* ── FUNC 0x239b98 · CPhysicsWorld::ParticleGroupPoly() · size=112 · insn=28 */
/* @0x239b98 push {r4, lr} */
/* @0x239b9c mov r4, r0 */
/* @0x239ba0 ldr r0, [r0, #0x3c] */
/* @0x239ba4 cmp r0, #0 */
/* @0x239ba8 beq 0x239bb8 <_ZN13CPhysicsWorld17ParticleGroupPolyEv+0x20> */
/* @0x239bac ldr r2, [r0] */
/* @0x239bb0 ldr r3, [r2, #0x4] */
/* @0x239bb4 blx r3 */
/* @0x239bb8 mov r0, #152 */
/* @0x239bbc bl 0x27c524 <_Znwj> */
/* @0x239bc0 ldr r2, [pc, #0x3c] */
/* @0x239bc4 mov r1, #2 */
/* @0x239bc8 ldr r2, [pc, r2] */
/* @0x239bcc add r2, r2, #8 */
/* @0x239bd0 mov r3, r0 */
/* @0x239bd4 movw r0, #0xd70a */
/* @0x239bd8 str r1, [r3, #0x4] */
/* @0x239bdc movt r0, #0x3c23 */
/* @0x239be0 str r2, [r3] */
/* @0x239be4 mov r1, #0 */
/* @0x239be8 mov r2, #0 */
/* @0x239bec str r0, [r3, #0x8] */
/* @0x239bf0 str r1, [r3, #0x94] */
/* @0x239bf4 str r2, [r3, #0xc] */
/* @0x239bf8 str r2, [r3, #0x10] */
/* @0x239bfc str r3, [r4, #0x3c] */
/* @0x239c00 pop {r4, pc} */
/* @0x239c04 andseq r7, r11, r8, ror #17 */

/* ── FUNC 0x239c08 · CPhysicsWorld::ParticleGroupAddPoint(float, float) · size=84 · insn=21 */
/* @0x239c08 ldr r3, [r0, #0x3c] */
/* @0x239c0c vmov s14, r1 */
/* @0x239c10 vmov s15, r2 */
/* @0x239c14 cmp r3, #0 */
/* @0x239c18 bxeq lr */
/* @0x239c1c ldr r2, [r3, #0x4] */
/* @0x239c20 cmp r2, #2 */
/* @0x239c24 bxne lr */
/* @0x239c28 ldr r2, [r3, #0x94] */
/* @0x239c2c cmp r2, #7 */
/* @0x239c30 bxgt lr */
/* @0x239c34 vldr s13, [r0, #96] */
/* @0x239c38 vmul.f32 s14, s13, s14 */
/* @0x239c3c add r1, r2, #2 */
/* @0x239c40 add r2, r2, #1 */
/* @0x239c44 str r2, [r3, #0x94] */
/* @0x239c48 add r3, r3, r1, lsl #3 */
/* @0x239c4c vmul.f32 s15, s13, s15 */
/* @0x239c50 vstr s14, [r3, #4] */
/* @0x239c54 vstr s15, [r3, #8] */
/* @0x239c58 bx lr */

/* ── FUNC 0x239c5c · CPhysicsWorld::GetFreeParticleGroupSlot() · size=212 · insn=53 */
/* @0x239c5c push {r4, r5, r6, lr} */
/* @0x239c60 mov r5, r0 */
/* @0x239c64 ldr r4, [r0, #0x4c] */
/* @0x239c68 sub sp, sp, #8 */
/* @0x239c6c ldr r0, [r0, #0x48] */
/* @0x239c70 cmp r4, #0 */
/* @0x239c74 ble 0x239ca8 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0x4c> */
/* @0x239c78 ldr r3, [r0] */
/* @0x239c7c cmp r3, #0 */
/* @0x239c80 beq 0x239d20 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xc4> */
/* @0x239c84 mov r2, r0 */
/* @0x239c88 mov r3, #0 */
/* @0x239c8c b 0x239c9c <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0x40> */
/* @0x239c90 ldr r1, [r2, #0x4]! */
/* @0x239c94 cmp r1, #0 */
/* @0x239c98 beq 0x239d20 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xc4> */
/* @0x239c9c add r3, r3, #1 */
/* @0x239ca0 cmp r3, r4 */
/* @0x239ca4 bne 0x239c90 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0x34> */
/* @0x239ca8 add r1, r4, #1 */
/* @0x239cac ldr r2, [pc, #0x78] */
/* @0x239cb0 mov r6, #0 */
/* @0x239cb4 mov r3, #1344 */
/* @0x239cb8 add r1, r1, r1, lsl #1 */
/* @0x239cbc str r6, [sp] */
/* @0x239cc0 add r2, pc, r2 */
/* @0x239cc4 add r1, r1, r1, lsr #31 */
/* @0x239cc8 asr r1, r1, #1 */
/* @0x239ccc str r1, [r5, #0x4c] */
/* @0x239cd0 lsl r1, r1, #2 */
/* @0x239cd4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x239cd8 ldr r12, [r5, #0x4c] */
/* @0x239cdc cmp r4, r12 */
/* @0x239ce0 str r0, [r5, #0x48] */
/* @0x239ce4 bge 0x239d14 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xb8> */
/* @0x239ce8 mov r3, r0 */
/* @0x239cec lsl r1, r4, #2 */
/* @0x239cf0 mov r0, r6 */
/* @0x239cf4 mov r2, r4 */
/* @0x239cf8 b 0x239d00 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xa4> */
/* @0x239cfc ldr r3, [r5, #0x48] */
/* @0x239d00 add r2, r2, #1 */
/* @0x239d04 str r0, [r3, r1] */
/* @0x239d08 cmp r2, r12 */
/* @0x239d0c add r1, r1, #4 */
/* @0x239d10 bne 0x239cfc <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xa0> */
/* @0x239d14 mov r0, r4 */
/* @0x239d18 add sp, sp, #8 */
/* @0x239d1c pop {r4, r5, r6, pc} */
/* @0x239d20 mov r0, r3 */
/* @0x239d24 add sp, sp, #8 */
/* @0x239d28 pop {r4, r5, r6, pc} */
/* @0x239d2c andseq r11, r1, r8, lsr #12 */

/* ── FUNC 0x239d30 · CPhysicsWorld::EndParticleGroup() · size=144 · insn=36 */
/* @0x239d30 push {r4, r5, r6, lr} */
/* @0x239d34 mov r4, r0 */
/* @0x239d38 ldr r0, [r0, #0x3c] */
/* @0x239d3c sub sp, sp, #64 */
/* @0x239d40 cmp r0, #0 */
/* @0x239d44 beq 0x239d54 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x24> */
/* @0x239d48 ldr r3, [r0, #0x4] */
/* @0x239d4c cmp r3, #2 */
/* @0x239d50 beq 0x239d7c <_ZN13CPhysicsWorld16EndParticleGroupEv+0x4c> */
/* @0x239d54 add r1, r4, #20 */
/* @0x239d58 ldr r0, [r4, #0x10] */
/* @0x239d5c bl 0x2cb500 <_ZN7b2World19CreateParticleGroupERK18b2ParticleGroupDef> */
/* @0x239d60 mov r5, r0 */
/* @0x239d64 mov r0, r4 */
/* @0x239d68 bl 0x239c5c <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv> */
/* @0x239d6c ldr r3, [r4, #0x48] */
/* @0x239d70 str r5, [r3, r0, lsl #2] */
/* @0x239d74 add sp, sp, #64 */
/* @0x239d78 pop {r4, r5, r6, pc} */
/* @0x239d7c ldr r2, [r0, #0x94] */
/* @0x239d80 cmp r2, #0 */
/* @0x239d84 addgt r12, r0, #20 */
/* @0x239d88 addgt r6, sp, r2, lsl #3 */
/* @0x239d8c movgt r3, sp */
/* @0x239d90 ble 0x239db4 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x84> */
/* @0x239d94 ldr r5, [r12] */
/* @0x239d98 add r3, r3, #8 */
/* @0x239d9c ldr lr, [r12, #0x4] */
/* @0x239da0 add r12, r12, #8 */
/* @0x239da4 str r5, [r3, #-0x8] */
/* @0x239da8 str lr, [r3, #-0x4] */
/* @0x239dac cmp r3, r6 */
/* @0x239db0 bne 0x239d94 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x64> */
/* @0x239db4 mov r1, sp */
/* @0x239db8 bl 0x2c6028 <_ZN14b2PolygonShape3SetEPK6b2Vec2i> */
/* @0x239dbc b 0x239d54 <_ZN13CPhysicsWorld16EndParticleGroupEv+0x24> */

/* ── FUNC 0x239dc0 · CPhysicsWorld::GetParticleGroup(int) · size=40 · insn=10 */
/* @0x239dc0 cmp r1, #0 */
/* @0x239dc4 blt 0x239de0 <_ZN13CPhysicsWorld16GetParticleGroupEi+0x20> */
/* @0x239dc8 ldr r3, [r0, #0x4c] */
/* @0x239dcc cmp r1, r3 */
/* @0x239dd0 bge 0x239de0 <_ZN13CPhysicsWorld16GetParticleGroupEi+0x20> */
/* @0x239dd4 ldr r3, [r0, #0x48] */
/* @0x239dd8 ldr r0, [r3, r1, lsl #2] */
/* @0x239ddc bx lr */
/* @0x239de0 mov r0, #0 */
/* @0x239de4 bx lr */

/* ── FUNC 0x239de8 · CPhysicsWorld::JoinParticleGroups(int, int) · size=76 · insn=19 */
/* @0x239de8 push {r4, r5, r6, lr} */
/* @0x239dec mov r5, r2 */
/* @0x239df0 mov r4, r0 */
/* @0x239df4 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x239df8 mov r1, r5 */
/* @0x239dfc mov r6, r0 */
/* @0x239e00 mov r0, r4 */
/* @0x239e04 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x239e08 cmp r0, #0 */
/* @0x239e0c cmpne r6, #0 */
/* @0x239e10 popeq {r4, r5, r6, pc} */
/* @0x239e14 mov r2, r0 */
/* @0x239e18 mov r1, r6 */
/* @0x239e1c ldr r0, [r4, #0x10] */
/* @0x239e20 bl 0x2cb528 <_ZN7b2World18JoinParticleGroupsEP15b2ParticleGroupS1_> */
/* @0x239e24 ldr r3, [r4, #0x48] */
/* @0x239e28 mov r2, #0 */
/* @0x239e2c str r2, [r3, r5, lsl #2] */
/* @0x239e30 pop {r4, r5, r6, pc} */

/* ── FUNC 0x239e34 · CPhysicsWorld::DeleteParticleGroup(int) · size=52 · insn=13 */
/* @0x239e34 push {r3, r4, r5, lr} */
/* @0x239e38 mov r5, r1 */
/* @0x239e3c mov r4, r0 */
/* @0x239e40 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi> */
/* @0x239e44 subs r1, r0, #0 */
/* @0x239e48 popeq {r3, r4, r5, pc} */
/* @0x239e4c mov r2, #0 */
/* @0x239e50 ldr r0, [r4, #0x10] */
/* @0x239e54 bl 0x2cb548 <_ZN7b2World23DestroyParticlesInGroupEP15b2ParticleGroupb> */
/* @0x239e58 ldr r3, [r4, #0x48] */
/* @0x239e5c mov r2, #0 */
/* @0x239e60 str r2, [r3, r5, lsl #2] */
/* @0x239e64 pop {r3, r4, r5, pc} */

/* ── FUNC 0x239e68 · CPhysicsWorld::~CPhysicsWorld() · size=232 · insn=58 */
/* @0x239e68 push {r3, r4, r5, lr} */
/* @0x239e6c mov r5, r0 */
/* @0x239e70 ldr r0, [r0, #0x10] */
/* @0x239e74 movw r3, #0xfeee */
/* @0x239e78 movt r3, #0xfeee */
/* @0x239e7c cmp r0, r3 */
/* @0x239e80 beq 0x239f10 <_ZN13CPhysicsWorldD2Ev+0xa8> */
/* @0x239e84 ldr r3, [r5, #0x4c] */
/* @0x239e88 cmp r3, #0 */
/* @0x239e8c ble 0x239eb4 <_ZN13CPhysicsWorldD2Ev+0x4c> */
/* @0x239e90 mov r4, #0 */
/* @0x239e94 mov r1, r4 */
/* @0x239e98 mov r0, r5 */
/* @0x239e9c bl 0x239e34 <_ZN13CPhysicsWorld19DeleteParticleGroupEi> */
/* @0x239ea0 ldr r3, [r5, #0x4c] */
/* @0x239ea4 add r4, r4, #1 */
/* @0x239ea8 cmp r3, r4 */
/* @0x239eac bgt 0x239e94 <_ZN13CPhysicsWorldD2Ev+0x2c> */
/* @0x239eb0 ldr r0, [r5, #0x10] */
/* @0x239eb4 mov r1, #0 */
/* @0x239eb8 bl 0x2c901c <_ZN7b2World18SetContactListenerEP17b2ContactListener> */
/* @0x239ebc ldr r0, [r5, #0x54] */
/* @0x239ec0 cmp r0, #0 */
/* @0x239ec4 beq 0x239ed4 <_ZN13CPhysicsWorldD2Ev+0x6c> */
/* @0x239ec8 ldr r3, [r0] */
/* @0x239ecc ldr r3, [r3, #0x4] */
/* @0x239ed0 blx r3 */
/* @0x239ed4 ldr r3, [pc, #0x70] */
/* @0x239ed8 ldr r3, [pc, r3] */
/* @0x239edc ldr r3, [r3] */
/* @0x239ee0 cmp r3, #0 */
/* @0x239ee4 beq 0x239ef4 <_ZN13CPhysicsWorldD2Ev+0x8c> */
/* @0x239ee8 ldr r3, [r3, #0xb4] */
/* @0x239eec cmp r5, r3 */
/* @0x239ef0 beq 0x239f38 <_ZN13CPhysicsWorldD2Ev+0xd0> */
/* @0x239ef4 ldr r4, [r5, #0x10] */
/* @0x239ef8 cmp r4, #0 */
/* @0x239efc beq 0x239f10 <_ZN13CPhysicsWorldD2Ev+0xa8> */
/* @0x239f00 mov r0, r4 */
/* @0x239f04 bl 0x2c8f74 <_ZN7b2WorldD2Ev> */
/* @0x239f08 mov r0, r4 */
/* @0x239f0c bl 0x27d1d0 <_ZdlPv> */
/* @0x239f10 ldr r0, [r5, #0x50] */
/* @0x239f14 cmp r0, #0 */
/* @0x239f18 beq 0x239f28 <_ZN13CPhysicsWorldD2Ev+0xc0> */
/* @0x239f1c ldr r3, [r0] */
/* @0x239f20 ldr r3, [r3, #0x4] */
/* @0x239f24 blx r3 */
/* @0x239f28 ldr r0, [r5] */
/* @0x239f2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x239f30 mov r0, r5 */
/* @0x239f34 pop {r3, r4, r5, pc} */
/* @0x239f38 mov r0, r5 */
/* @0x239f3c bl 0x237e94 <_ZN13CPhysicsWorld13DestroyBodiesEv> */
/* @0x239f40 mov r0, r5 */
/* @0x239f44 bl 0x237f48 <_ZN13CPhysicsWorld13DestroyJointsEv> */
/* @0x239f48 b 0x239ef4 <_ZN13CPhysicsWorldD2Ev+0x8c> */
/* @0x239f4c andseq r3, r11, r0, asr r10 */

/* ── FUNC 0x239e68 · CPhysicsWorld::~CPhysicsWorld() · alias of the symbol above · insn=0 */

/* ── FUNC 0x239f50 · CPhysicsWorld::DeleteParticleCircleRegion(float, float, float) · size=128 · insn=32 */
/* @0x239f50 vmov s12, r3 */
/* @0x239f54 vldr s15, [r0, #96] */
/* @0x239f58 str lr, [sp, #-0x4]! */
/* @0x239f5c vmul.f32 s13, s15, s12 */
/* @0x239f60 sub sp, sp, #44 */
/* @0x239f64 vmov s12, r1 */
/* @0x239f68 ldr r12, [pc, #0x5c] */
/* @0x239f6c mov lr, #0 */
/* @0x239f70 mov r3, lr */
/* @0x239f74 add r1, sp, #20 */
/* @0x239f78 ldr r12, [pc, r12] */
/* @0x239f7c ldr r0, [r0, #0x10] */
/* @0x239f80 add r12, r12, #8 */
/* @0x239f84 str lr, [sp, #0x18] */
/* @0x239f88 str r12, [sp, #0x14] */
/* @0x239f8c mov r12, #0 */
/* @0x239f90 str r12, [sp, #0x20] */
/* @0x239f94 str r12, [sp, #0x24] */
/* @0x239f98 str r12, [sp, #0xc] */
/* @0x239f9c mov r12, #1065353216 */
/* @0x239fa0 str r12, [sp, #0x10] */
/* @0x239fa4 vstr s13, [sp, #28] */
/* @0x239fa8 vmov s13, r2 */
/* @0x239fac vmul.f32 s14, s15, s12 */
/* @0x239fb0 add r2, sp, #4 */
/* @0x239fb4 vmul.f32 s15, s15, s13 */
/* @0x239fb8 vstr s14, [sp, #4] */
/* @0x239fbc vstr s15, [sp, #8] */
/* @0x239fc0 bl 0x2cb4d8 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb> */
/* @0x239fc4 add sp, sp, #44 */
/* @0x239fc8 ldr pc, [sp], #4 */
/* @0x239fcc andseq r7, r11, r4, lsr r5 */

/* ── FUNC 0x239fd0 · CPhysicsWorld::DeleteParticleBoxRegion(float, float, float, float) · size=188 · insn=47 */
/* @0x239fd0 vmov s13, r3 */
/* @0x239fd4 vldr s14, [r0, #96] */
/* @0x239fd8 push {r4, r5, r6, r7, lr} */
/* @0x239fdc vpush {d8} */
/* @0x239fe0 vmul.f32 s13, s14, s13 */
/* @0x239fe4 sub sp, sp, #172 */
/* @0x239fe8 vldr s15, [sp, #200] */
/* @0x239fec add r6, sp, #16 */
/* @0x239ff0 ldr r12, [pc, #0x90] */
/* @0x239ff4 vmov s16, r2 */
/* @0x239ff8 mov r4, r0 */
/* @0x239ffc vmov s17, r1 */
/* @0x23a000 mov r0, r6 */
/* @0x23a004 ldr r12, [pc, r12] */
/* @0x23a008 movw r2, #0xd70a */
/* @0x23a00c movt r2, #0x3c23 */
/* @0x23a010 str r2, [sp, #0x18] */
/* @0x23a014 mov r5, #0 */
/* @0x23a018 add r12, r12, #8 */
/* @0x23a01c mov r3, #2 */
/* @0x23a020 str r12, [sp, #0x10] */
/* @0x23a024 str r3, [sp, #0x14] */
/* @0x23a028 mov r7, #0 */
/* @0x23a02c str r5, [sp, #0x1c] */
/* @0x23a030 str r7, [sp, #0xa4] */
/* @0x23a034 vmul.f32 s15, s14, s15 */
/* @0x23a038 str r5, [sp, #0x20] */
/* @0x23a03c vmov r1, s13 */
/* @0x23a040 vmov r2, s15 */
/* @0x23a044 bl 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff> */
/* @0x23a048 vldr s15, [r4, #96] */
/* @0x23a04c vmul.f32 s17, s15, s17 */
/* @0x23a050 mov r1, r6 */
/* @0x23a054 mov r3, r7 */
/* @0x23a058 ldr r0, [r4, #0x10] */
/* @0x23a05c mov r2, sp */
/* @0x23a060 mov r12, #1065353216 */
/* @0x23a064 str r5, [sp, #0x8] */
/* @0x23a068 str r12, [sp, #0xc] */
/* @0x23a06c vmul.f32 s15, s15, s16 */
/* @0x23a070 vstr s17, [sp] */
/* @0x23a074 vstr s15, [sp, #4] */
/* @0x23a078 bl 0x2cb4d8 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb> */
/* @0x23a07c add sp, sp, #172 */
/* @0x23a080 vpop {d8} */
/* @0x23a084 pop {r4, r5, r6, r7, pc} */
/* @0x23a088 andseq r7, r11, r12, lsr #9 */

/* ── FUNC 0x23a08c · CPhysicsWorld::DeleteParticlePolyRegion(float*, int) · size=212 · insn=53 */
/* @0x23a08c cmp r2, #8 */
/* @0x23a090 movge r2, #8 */
/* @0x23a094 mov r12, r1 */
/* @0x23a098 cmp r2, #0 */
/* @0x23a09c push {r4, r5, r6, r7, lr} */
/* @0x23a0a0 sub sp, sp, #236 */
/* @0x23a0a4 mov r6, r0 */
/* @0x23a0a8 add r1, sp, #16 */
/* @0x23a0ac ble 0x23a0e8 <_ZN13CPhysicsWorld24DeleteParticlePolyRegionEPfi+0x5c> */
/* @0x23a0b0 add r12, r12, #4 */
/* @0x23a0b4 add lr, r1, r2, lsl #3 */
/* @0x23a0b8 mov r3, r1 */
/* @0x23a0bc vldr s15, [r0, #96] */
/* @0x23a0c0 vldr s13, [r12] */
/* @0x23a0c4 vldr s14, [r12, #-4] */
/* @0x23a0c8 vmul.f32 s13, s15, s13 */
/* @0x23a0cc add r3, r3, #8 */
/* @0x23a0d0 add r12, r12, #8 */
/* @0x23a0d4 vmul.f32 s14, s14, s15 */
/* @0x23a0d8 vstr s13, [r3, #-4] */
/* @0x23a0dc vstr s14, [r3, #-8] */
/* @0x23a0e0 cmp r3, lr */
/* @0x23a0e4 bne 0x23a0c0 <_ZN13CPhysicsWorld24DeleteParticlePolyRegionEPfi+0x34> */
/* @0x23a0e8 add r7, sp, #80 */
/* @0x23a0ec ldr r3, [pc, #0x68] */
/* @0x23a0f0 mov r5, #0 */
/* @0x23a0f4 mov r4, #0 */
/* @0x23a0f8 mov r0, r7 */
/* @0x23a0fc ldr r3, [pc, r3] */
/* @0x23a100 mov r12, #2 */
/* @0x23a104 add r3, r3, #8 */
/* @0x23a108 str r12, [sp, #0x54] */
/* @0x23a10c str r3, [sp, #0x50] */
/* @0x23a110 movw r3, #0xd70a */
/* @0x23a114 str r5, [sp, #0xe4] */
/* @0x23a118 movt r3, #0x3c23 */
/* @0x23a11c str r4, [sp, #0x5c] */
/* @0x23a120 str r3, [sp, #0x58] */
/* @0x23a124 str r4, [sp, #0x60] */
/* @0x23a128 bl 0x2c6028 <_ZN14b2PolygonShape3SetEPK6b2Vec2i> */
/* @0x23a12c mov r1, r7 */
/* @0x23a130 mov r3, r5 */
/* @0x23a134 ldr r0, [r6, #0x10] */
/* @0x23a138 mov r2, sp */
/* @0x23a13c mov r12, #1065353216 */
/* @0x23a140 str r4, [sp] */
/* @0x23a144 str r4, [sp, #0x4] */
/* @0x23a148 str r4, [sp, #0x8] */
/* @0x23a14c str r12, [sp, #0xc] */
/* @0x23a150 bl 0x2cb4d8 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb> */
/* @0x23a154 add sp, sp, #236 */
/* @0x23a158 pop {r4, r5, r6, r7, pc} */
/* @0x23a15c ldrheq r7, [r11], -r4 */

/* ── FUNC 0x23a160 · CPhysicsWorld::SetParticleFlags(int, unsigned int) · size=52 · insn=13 */
/* @0x23a160 push {r3, r4, r5, lr} */
/* @0x23a164 subs r4, r1, #0 */
/* @0x23a168 mov r5, r2 */
/* @0x23a16c poplt {r3, r4, r5, pc} */
/* @0x23a170 ldr r0, [r0, #0x10] */
/* @0x23a174 movw r3, #0x9298 */
/* @0x23a178 movt r3, #0x1 */
/* @0x23a17c ldr r3, [r0, r3] */
/* @0x23a180 cmp r4, r3 */
/* @0x23a184 popge {r3, r4, r5, pc} */
/* @0x23a188 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv> */
/* @0x23a18c str r5, [r0, r4, lsl #2] */
/* @0x23a190 pop {r3, r4, r5, pc} */

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
