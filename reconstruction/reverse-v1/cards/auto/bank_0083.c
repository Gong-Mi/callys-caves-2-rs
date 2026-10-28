/* libyoyo.so 覆盖卡组 0083
 * 函数 0x14bf60..0x14d3b4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x14bf60 · F_PhysicsApplyTorque(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x14bf60 push {r4, lr} */
/* @0x14bf64 ldr r4, [r1, #0x84] */
/* @0x14bf68 ldr r0, [sp, #0x8] */
/* @0x14bf6c cmp r4, #0 */
/* @0x14bf70 beq 0x14bf8c <_Z20F_PhysicsApplyTorqueR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x14bf74 mov r1, #0 */
/* @0x14bf78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14bf7c mov r1, r0 */
/* @0x14bf80 mov r0, r4 */
/* @0x14bf84 pop {r4, lr} */
/* @0x14bf88 b 0x237260 <_ZN14CPhysicsObject11ApplyTorqueEf> */
/* @0x14bf8c ldr r0, [pc, #0xc] */
/* @0x14bf90 mov r1, r4 */
/* @0x14bf94 pop {r4, lr} */
/* @0x14bf98 add r0, pc, r0 */
/* @0x14bf9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14bfa0 andseq r7, pc, r12, asr #28 */

/* ── FUNC 0x14bfa4 · F_PhysicsGetFriction(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x14bfa4 mov r2, #0 */
/* @0x14bfa8 push {r3, r4, r5, lr} */
/* @0x14bfac mov r3, r2 */
/* @0x14bfb0 movt r2, #0xbff0 */
/* @0x14bfb4 str r3, [r0] */
/* @0x14bfb8 str r2, [r0, #0x4] */
/* @0x14bfbc mov r4, r0 */
/* @0x14bfc0 ldr r5, [r1, #0x84] */
/* @0x14bfc4 str r3, [r0, #0xc] */
/* @0x14bfc8 cmp r5, r3 */
/* @0x14bfcc ldr r0, [sp, #0x10] */
/* @0x14bfd0 beq 0x14c004 <_Z20F_PhysicsGetFrictionR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14bfd4 mov r1, r3 */
/* @0x14bfd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14bfdc mov r1, r0 */
/* @0x14bfe0 mov r0, r5 */
/* @0x14bfe4 bl 0x2378d0 <_ZN14CPhysicsObject11GetFrictionEi> */
/* @0x14bfe8 vmov s15, r0 */
/* @0x14bfec vcvt.f64.f32 d7, s15 */
/* @0x14bff0 vmov r0, r1, d7 */
/* @0x14bff4 vmov r2, s14 */
/* @0x14bff8 mov r3, r1 */
/* @0x14bffc stm r4, {r2, r3} */
/* @0x14c000 pop {r3, r4, r5, pc} */
/* @0x14c004 ldr r0, [pc, #0xc] */
/* @0x14c008 mov r1, r5 */
/* @0x14c00c pop {r3, r4, r5, lr} */
/* @0x14c010 add r0, pc, r0 */
/* @0x14c014 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c018 ldrsbeq r7, [pc], -r4 */

/* ── FUNC 0x14c01c · F_PhysicsGetDensity(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x14c01c mov r2, #0 */
/* @0x14c020 push {r3, r4, r5, lr} */
/* @0x14c024 mov r3, r2 */
/* @0x14c028 movt r2, #0xbff0 */
/* @0x14c02c str r3, [r0] */
/* @0x14c030 str r2, [r0, #0x4] */
/* @0x14c034 mov r4, r0 */
/* @0x14c038 ldr r5, [r1, #0x84] */
/* @0x14c03c str r3, [r0, #0xc] */
/* @0x14c040 cmp r5, r3 */
/* @0x14c044 ldr r0, [sp, #0x10] */
/* @0x14c048 beq 0x14c07c <_Z19F_PhysicsGetDensityR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14c04c mov r1, r3 */
/* @0x14c050 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c054 mov r1, r0 */
/* @0x14c058 mov r0, r5 */
/* @0x14c05c bl 0x237924 <_ZN14CPhysicsObject10GetDensityEi> */
/* @0x14c060 vmov s15, r0 */
/* @0x14c064 vcvt.f64.f32 d7, s15 */
/* @0x14c068 vmov r0, r1, d7 */
/* @0x14c06c vmov r2, s14 */
/* @0x14c070 mov r3, r1 */
/* @0x14c074 stm r4, {r2, r3} */
/* @0x14c078 pop {r3, r4, r5, pc} */
/* @0x14c07c ldr r0, [pc, #0xc] */
/* @0x14c080 mov r1, r5 */
/* @0x14c084 pop {r3, r4, r5, lr} */
/* @0x14c088 add r0, pc, r0 */
/* @0x14c08c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c090 andseq r7, pc, r12, asr sp */

/* ── FUNC 0x14c094 · F_PhysicsGetRestitution(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x14c094 mov r2, #0 */
/* @0x14c098 push {r3, r4, r5, lr} */
/* @0x14c09c mov r3, r2 */
/* @0x14c0a0 movt r2, #0xbff0 */
/* @0x14c0a4 str r3, [r0] */
/* @0x14c0a8 str r2, [r0, #0x4] */
/* @0x14c0ac mov r4, r0 */
/* @0x14c0b0 ldr r5, [r1, #0x84] */
/* @0x14c0b4 str r3, [r0, #0xc] */
/* @0x14c0b8 cmp r5, r3 */
/* @0x14c0bc ldr r0, [sp, #0x10] */
/* @0x14c0c0 beq 0x14c0f4 <_Z23F_PhysicsGetRestitutionR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14c0c4 mov r1, r3 */
/* @0x14c0c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c0cc mov r1, r0 */
/* @0x14c0d0 mov r0, r5 */
/* @0x14c0d4 bl 0x237978 <_ZN14CPhysicsObject14GetRestitutionEi> */
/* @0x14c0d8 vmov s15, r0 */
/* @0x14c0dc vcvt.f64.f32 d7, s15 */
/* @0x14c0e0 vmov r0, r1, d7 */
/* @0x14c0e4 vmov r2, s14 */
/* @0x14c0e8 mov r3, r1 */
/* @0x14c0ec stm r4, {r2, r3} */
/* @0x14c0f0 pop {r3, r4, r5, pc} */
/* @0x14c0f4 ldr r0, [pc, #0xc] */
/* @0x14c0f8 mov r1, r5 */
/* @0x14c0fc pop {r3, r4, r5, lr} */
/* @0x14c100 add r0, pc, r0 */
/* @0x14c104 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c108 andseq r7, pc, r4, ror #25 */

/* ── FUNC 0x14c10c · F_PhysicsSetFriction(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x14c10c push {r4, r5, r6, lr} */
/* @0x14c110 mov r3, #0 */
/* @0x14c114 str r3, [r0] */
/* @0x14c118 str r3, [r0, #0x4] */
/* @0x14c11c ldr r4, [r1, #0x84] */
/* @0x14c120 ldr r5, [sp, #0x10] */
/* @0x14c124 cmp r4, r3 */
/* @0x14c128 str r3, [r0, #0xc] */
/* @0x14c12c beq 0x14c160 <_Z20F_PhysicsSetFrictionR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x14c130 mov r1, r3 */
/* @0x14c134 mov r0, r5 */
/* @0x14c138 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c13c mov r1, #1 */
/* @0x14c140 mov r6, r0 */
/* @0x14c144 mov r0, r5 */
/* @0x14c148 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c14c mov r1, r6 */
/* @0x14c150 mov r2, r0 */
/* @0x14c154 mov r0, r4 */
/* @0x14c158 pop {r4, r5, r6, lr} */
/* @0x14c15c b 0x2379cc <_ZN14CPhysicsObject11SetFrictionEif> */
/* @0x14c160 ldr r0, [pc, #0xc] */
/* @0x14c164 mov r1, r4 */
/* @0x14c168 pop {r4, r5, r6, lr} */
/* @0x14c16c add r0, pc, r0 */
/* @0x14c170 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c174 andseq r7, pc, r8, ror r12 */

/* ── FUNC 0x14c178 · F_PhysicsSetDensity(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x14c178 push {r4, r5, r6, lr} */
/* @0x14c17c mov r3, #0 */
/* @0x14c180 str r3, [r0] */
/* @0x14c184 str r3, [r0, #0x4] */
/* @0x14c188 ldr r4, [r1, #0x84] */
/* @0x14c18c ldr r5, [sp, #0x10] */
/* @0x14c190 cmp r4, r3 */
/* @0x14c194 str r3, [r0, #0xc] */
/* @0x14c198 beq 0x14c1cc <_Z19F_PhysicsSetDensityR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x14c19c mov r1, r3 */
/* @0x14c1a0 mov r0, r5 */
/* @0x14c1a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c1a8 mov r1, #1 */
/* @0x14c1ac mov r6, r0 */
/* @0x14c1b0 mov r0, r5 */
/* @0x14c1b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c1b8 mov r1, r6 */
/* @0x14c1bc mov r2, r0 */
/* @0x14c1c0 mov r0, r4 */
/* @0x14c1c4 pop {r4, r5, r6, lr} */
/* @0x14c1c8 b 0x237a18 <_ZN14CPhysicsObject10SetDensityEif> */
/* @0x14c1cc ldr r0, [pc, #0xc] */
/* @0x14c1d0 mov r1, r4 */
/* @0x14c1d4 pop {r4, r5, r6, lr} */
/* @0x14c1d8 add r0, pc, r0 */
/* @0x14c1dc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c1e0 andseq r7, pc, r12, lsl #24 */

/* ── FUNC 0x14c1e4 · F_PhysicsSetRestitution(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x14c1e4 push {r4, r5, r6, lr} */
/* @0x14c1e8 mov r3, #0 */
/* @0x14c1ec str r3, [r0] */
/* @0x14c1f0 str r3, [r0, #0x4] */
/* @0x14c1f4 ldr r4, [r1, #0x84] */
/* @0x14c1f8 ldr r5, [sp, #0x10] */
/* @0x14c1fc cmp r4, r3 */
/* @0x14c200 str r3, [r0, #0xc] */
/* @0x14c204 beq 0x14c238 <_Z23F_PhysicsSetRestitutionR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x14c208 mov r1, r3 */
/* @0x14c20c mov r0, r5 */
/* @0x14c210 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c214 mov r1, #1 */
/* @0x14c218 mov r6, r0 */
/* @0x14c21c mov r0, r5 */
/* @0x14c220 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c224 mov r1, r6 */
/* @0x14c228 mov r2, r0 */
/* @0x14c22c mov r0, r4 */
/* @0x14c230 pop {r4, r5, r6, lr} */
/* @0x14c234 b 0x237a68 <_ZN14CPhysicsObject14SetRestitutionEif> */
/* @0x14c238 ldr r0, [pc, #0xc] */
/* @0x14c23c mov r1, r4 */
/* @0x14c240 pop {r4, r5, r6, lr} */
/* @0x14c244 add r0, pc, r0 */
/* @0x14c248 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c24c andseq r7, pc, r0, lsr #23 */

/* ── FUNC 0x14c250 · F_PhysicsFixtureSetCircleShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x14c250 push {r4, r5, r6, lr} */
/* @0x14c254 mov r1, #0 */
/* @0x14c258 ldr r5, [sp, #0x10] */
/* @0x14c25c mov r0, r5 */
/* @0x14c260 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c264 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14c268 subs r6, r0, #0 */
/* @0x14c26c beq 0x14c2c4 <_Z30F_PhysicsFixtureSetCircleShapeR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x14c270 ldr r3, [pc, #0x60] */
/* @0x14c274 ldr r3, [pc, r3] */
/* @0x14c278 ldr r3, [r3] */
/* @0x14c27c ldr r4, [r3, #0xb4] */
/* @0x14c280 cmp r4, #0 */
/* @0x14c284 beq 0x14c2b0 <_Z30F_PhysicsFixtureSetCircleShapeR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14c288 mov r0, r5 */
/* @0x14c28c mov r1, #1 */
/* @0x14c290 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c294 vldr s15, [r4, #96] */
/* @0x14c298 vmov s14, r0 */
/* @0x14c29c mov r0, r6 */
/* @0x14c2a0 pop {r4, r5, r6, lr} */
/* @0x14c2a4 vmul.f32 s15, s14, s15 */
/* @0x14c2a8 vmov r1, s15 */
/* @0x14c2ac b 0x236788 <_ZN15CPhysicsFixture14SetCircleShapeEf> */
/* @0x14c2b0 ldr r0, [pc, #0x24] */
/* @0x14c2b4 mov r1, r4 */
/* @0x14c2b8 pop {r4, r5, r6, lr} */
/* @0x14c2bc add r0, pc, r0 */
/* @0x14c2c0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c2c4 ldr r0, [pc, #0x14] */
/* @0x14c2c8 mov r1, r6 */
/* @0x14c2cc pop {r4, r5, r6, lr} */
/* @0x14c2d0 add r0, pc, r0 */
/* @0x14c2d4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c2d8 .word 0x002a16b4 */
/* @0x14c2dc andseq r7, pc, r8, ror #22 */
/* @0x14c2e0 ldrsbeq r7, [pc], -r8 */

/* ── FUNC 0x14c2e4 · F_PhysicsFixtureSetBoxShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x14c2e4 push {r4, r5, r6, lr} */
/* @0x14c2e8 vpush {d8} */
/* @0x14c2ec mov r1, #0 */
/* @0x14c2f0 ldr r5, [sp, #0x18] */
/* @0x14c2f4 mov r0, r5 */
/* @0x14c2f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c2fc bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14c300 subs r6, r0, #0 */
/* @0x14c304 beq 0x14c380 <_Z27F_PhysicsFixtureSetBoxShapeR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x14c308 ldr r3, [pc, #0x88] */
/* @0x14c30c ldr r3, [pc, r3] */
/* @0x14c310 ldr r3, [r3] */
/* @0x14c314 ldr r4, [r3, #0xb4] */
/* @0x14c318 cmp r4, #0 */
/* @0x14c31c beq 0x14c368 <_Z27F_PhysicsFixtureSetBoxShapeR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x14c320 mov r0, r5 */
/* @0x14c324 mov r1, #1 */
/* @0x14c328 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c32c mov r1, #2 */
/* @0x14c330 vldr s16, [r4, #96] */
/* @0x14c334 vmov s14, r0 */
/* @0x14c338 mov r0, r5 */
/* @0x14c33c vmul.f32 s16, s14, s16 */
/* @0x14c340 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c344 vldr s15, [r4, #96] */
/* @0x14c348 vmov r1, s16 */
/* @0x14c34c vpop {d8} */
/* @0x14c350 vmov s14, r0 */
/* @0x14c354 mov r0, r6 */
/* @0x14c358 pop {r4, r5, r6, lr} */
/* @0x14c35c vmul.f32 s15, s14, s15 */
/* @0x14c360 vmov r2, s15 */
/* @0x14c364 b 0x2367d8 <_ZN15CPhysicsFixture11SetBoxShapeEff> */
/* @0x14c368 vpop {d8} */
/* @0x14c36c mov r1, r4 */
/* @0x14c370 ldr r0, [pc, #0x24] */
/* @0x14c374 add r0, pc, r0 */
/* @0x14c378 pop {r4, r5, r6, lr} */
/* @0x14c37c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c380 vpop {d8} */
/* @0x14c384 mov r1, r6 */
/* @0x14c388 ldr r0, [pc, #0x10] */
/* @0x14c38c add r0, pc, r0 */
/* @0x14c390 pop {r4, r5, r6, lr} */
/* @0x14c394 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c398 eoreq r1, r10, r12, lsl r6 */
/* @0x14c39c ldrheq r7, [pc], -r0 */
/* @0x14c3a0 andseq r7, pc, r12, lsl r10 */

/* ── FUNC 0x14c3a4 · F_PhysicsFixtureSetEdgeShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=248 · insn=62 */
/* @0x14c3a4 push {r4, r5, r6, lr} */
/* @0x14c3a8 vpush {d8, d9} */
/* @0x14c3ac mov r1, #0 */
/* @0x14c3b0 ldr r5, [sp, #0x20] */
/* @0x14c3b4 mov r0, r5 */
/* @0x14c3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c3bc bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14c3c0 subs r6, r0, #0 */
/* @0x14c3c4 beq 0x14c478 <_Z28F_PhysicsFixtureSetEdgeShapeR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x14c3c8 ldr r3, [pc, #0xc0] */
/* @0x14c3cc ldr r3, [pc, r3] */
/* @0x14c3d0 ldr r3, [r3] */
/* @0x14c3d4 ldr r4, [r3, #0xb4] */
/* @0x14c3d8 cmp r4, #0 */
/* @0x14c3dc beq 0x14c460 <_Z28F_PhysicsFixtureSetEdgeShapeR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x14c3e0 mov r0, r5 */
/* @0x14c3e4 mov r1, #1 */
/* @0x14c3e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c3ec mov r1, #2 */
/* @0x14c3f0 vldr s18, [r4, #96] */
/* @0x14c3f4 vmov s14, r0 */
/* @0x14c3f8 mov r0, r5 */
/* @0x14c3fc vmul.f32 s18, s14, s18 */
/* @0x14c400 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c404 mov r1, #3 */
/* @0x14c408 vldr s17, [r4, #96] */
/* @0x14c40c vmov s15, r0 */
/* @0x14c410 mov r0, r5 */
/* @0x14c414 vmul.f32 s17, s15, s17 */
/* @0x14c418 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c41c mov r1, #4 */
/* @0x14c420 vldr s16, [r4, #96] */
/* @0x14c424 vmov s14, r0 */
/* @0x14c428 mov r0, r5 */
/* @0x14c42c vmul.f32 s16, s14, s16 */
/* @0x14c430 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c434 vldr s15, [r4, #96] */
/* @0x14c438 vmov r1, s18 */
/* @0x14c43c vmov r2, s17 */
/* @0x14c440 vmov r3, s16 */
/* @0x14c444 vmov s14, r0 */
/* @0x14c448 mov r0, r6 */
/* @0x14c44c vmul.f32 s15, s14, s15 */
/* @0x14c450 vstr s15, [sp, #32] */
/* @0x14c454 vpop {d8, d9} */
/* @0x14c458 pop {r4, r5, r6, lr} */
/* @0x14c45c b 0x236848 <_ZN15CPhysicsFixture12SetEdgeShapeEffff> */
/* @0x14c460 vpop {d8, d9} */
/* @0x14c464 mov r1, r4 */
/* @0x14c468 ldr r0, [pc, #0x24] */
/* @0x14c46c add r0, pc, r0 */
/* @0x14c470 pop {r4, r5, r6, lr} */
/* @0x14c474 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c478 vpop {d8, d9} */
/* @0x14c47c mov r1, r6 */
/* @0x14c480 ldr r0, [pc, #0x10] */
/* @0x14c484 add r0, pc, r0 */
/* @0x14c488 pop {r4, r5, r6, lr} */
/* @0x14c48c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c490 eoreq r1, r10, r12, asr r5 */
/* @0x14c494 ldrheq r7, [pc], -r8 */
/* @0x14c498 andseq r7, pc, r4, lsr #18 */

/* ── FUNC 0x14c49c · F_PhysicsFixtureAddShapePoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x14c49c push {r4, r5, r6, lr} */
/* @0x14c4a0 vpush {d8} */
/* @0x14c4a4 mov r1, #0 */
/* @0x14c4a8 ldr r5, [sp, #0x18] */
/* @0x14c4ac mov r0, r5 */
/* @0x14c4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c4b4 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14c4b8 subs r6, r0, #0 */
/* @0x14c4bc beq 0x14c554 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14c4c0 ldr r3, [pc, #0xa4] */
/* @0x14c4c4 ldr r3, [pc, r3] */
/* @0x14c4c8 ldr r3, [r3] */
/* @0x14c4cc ldr r4, [r3, #0xb4] */
/* @0x14c4d0 cmp r4, #0 */
/* @0x14c4d4 beq 0x14c53c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c4d8 mov r1, #1 */
/* @0x14c4dc mov r0, r5 */
/* @0x14c4e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c4e4 mov r1, #2 */
/* @0x14c4e8 vldr s16, [r4, #96] */
/* @0x14c4ec vmov s14, r0 */
/* @0x14c4f0 mov r0, r5 */
/* @0x14c4f4 vmul.f32 s16, s14, s16 */
/* @0x14c4f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c4fc vldr s15, [r4, #96] */
/* @0x14c500 vmov r1, s16 */
/* @0x14c504 vmov s14, r0 */
/* @0x14c508 mov r0, r6 */
/* @0x14c50c vmul.f32 s15, s14, s15 */
/* @0x14c510 vmov r2, s15 */
/* @0x14c514 bl 0x236ac8 <_ZN15CPhysicsFixture13AddShapePointEff> */
/* @0x14c518 subs r1, r0, #0 */
/* @0x14c51c beq 0x14c528 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x14c520 vpop {d8} */
/* @0x14c524 pop {r4, r5, r6, pc} */
/* @0x14c528 vpop {d8} */
/* @0x14c52c ldr r0, [pc, #0x3c] */
/* @0x14c530 add r0, pc, r0 */
/* @0x14c534 pop {r4, r5, r6, lr} */
/* @0x14c538 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c53c vpop {d8} */
/* @0x14c540 mov r1, r4 */
/* @0x14c544 ldr r0, [pc, #0x28] */
/* @0x14c548 add r0, pc, r0 */
/* @0x14c54c pop {r4, r5, r6, lr} */
/* @0x14c550 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c554 vpop {d8} */
/* @0x14c558 mov r1, r6 */
/* @0x14c55c ldr r0, [pc, #0x14] */
/* @0x14c560 add r0, pc, r0 */
/* @0x14c564 pop {r4, r5, r6, lr} */
/* @0x14c568 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c56c eoreq r1, r10, r4, ror #8 */
/* @0x14c570 andseq r7, pc, r4, lsr r9 */
/* @0x14c574 ldrsbeq r7, [pc], -r12 */
/* @0x14c578 andseq r7, pc, r8, asr #16 */

/* ── FUNC 0x14c57c · anon_14c57c · size=292 · insn=73 */
/* @0x14c57c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x14c580 vpush {d8} */
/* @0x14c584 mov r6, r0 */
/* @0x14c588 sub sp, sp, #52 */
/* @0x14c58c mov r0, r1 */
/* @0x14c590 mov r9, r2 */
/* @0x14c594 vmov.f32 s16, s1 */
/* @0x14c598 vmov r8, s0 */
/* @0x14c59c bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj> */
/* @0x14c5a0 subs r7, r0, #0 */
/* @0x14c5a4 beq 0x14c67c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14c5a8 ldr r5, [pc, #0xe4] */
/* @0x14c5ac ldr r5, [pc, r5] */
/* @0x14c5b0 ldr r3, [r5] */
/* @0x14c5b4 cmp r3, #0 */
/* @0x14c5b8 beq 0x14c658 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x14c5bc ldr r3, [r3, #0xb4] */
/* @0x14c5c0 cmp r3, #0 */
/* @0x14c5c4 beq 0x14c658 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x14c5c8 add r4, sp, #12 */
/* @0x14c5cc mov r2, r6 */
/* @0x14c5d0 mov r3, r6 */
/* @0x14c5d4 mov r12, #0 */
/* @0x14c5d8 mov r1, r9 */
/* @0x14c5dc mov r0, r4 */
/* @0x14c5e0 str r12, [sp] */
/* @0x14c5e4 mvn r6, #0 */
/* @0x14c5e8 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x14c5ec b 0x14c634 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x14c5f0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x14c5f4 ldrb r12, [r0, #0x68] */
/* @0x14c5f8 cmp r12, #0 */
/* @0x14c5fc bne 0x14c62c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x14c600 ldrb r12, [r0, #0x69] */
/* @0x14c604 mov r1, r7 */
/* @0x14c608 mov r2, r0 */
/* @0x14c60c mov r3, r8 */
/* @0x14c610 cmp r12, #0 */
/* @0x14c614 bne 0x14c62c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x14c618 ldr r0, [r5] */
/* @0x14c61c ldr r0, [r0, #0xb4] */
/* @0x14c620 vstr s16, [sp] */
/* @0x14c624 bl 0x23894c <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff> */
/* @0x14c628 mov r6, r0 */
/* @0x14c62c mov r0, r4 */
/* @0x14c630 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x14c634 mov r0, r4 */
/* @0x14c638 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x14c63c cmp r0, #0 */
/* @0x14c640 mov r0, r4 */
/* @0x14c644 bne 0x14c5f0 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x14c648 mov r0, r6 */
/* @0x14c64c add sp, sp, #52 */
/* @0x14c650 vpop {d8} */
/* @0x14c654 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x14c658 ldr r0, [pc, #0x38] */
/* @0x14c65c mov r1, #0 */
/* @0x14c660 mvn r6, #0 */
/* @0x14c664 add r0, pc, r0 */
/* @0x14c668 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c66c mov r0, r6 */
/* @0x14c670 add sp, sp, #52 */
/* @0x14c674 vpop {d8} */
/* @0x14c678 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x14c67c ldr r0, [pc, #0x18] */
/* @0x14c680 mov r1, r7 */
/* @0x14c684 mvn r6, #0 */
/* @0x14c688 add r0, pc, r0 */
/* @0x14c68c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c690 b 0x14c648 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x14c694 eoreq r1, r10, r12, ror r3 */
/* @0x14c698 andseq r7, pc, r0, ror #16 */
/* @0x14c69c andseq r7, pc, r0, lsr #14 */

/* ── FUNC 0x14c6a0 · F_PhysicsBindFixture(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x14c6a0 push {r3, r4, r5, r6, r7, lr} */
/* @0x14c6a4 mov r3, #0 */
/* @0x14c6a8 ldr r5, [sp, #0x18] */
/* @0x14c6ac mov r4, r0 */
/* @0x14c6b0 str r3, [r0, #0xc] */
/* @0x14c6b4 mov r6, r1 */
/* @0x14c6b8 mov r1, r3 */
/* @0x14c6bc mov r0, r5 */
/* @0x14c6c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c6c4 mov r1, #1 */
/* @0x14c6c8 mov r7, r0 */
/* @0x14c6cc mov r0, r5 */
/* @0x14c6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c6d4 vldr s0, [pc, #44] */
/* @0x14c6d8 mov r1, r7 */
/* @0x14c6dc vmov.f32 s1, s0 */
/* @0x14c6e0 mov r2, r0 */
/* @0x14c6e4 mov r0, r6 */
/* @0x14c6e8 bl 0x14c57c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x14c6ec vmov s15, r0 */
/* @0x14c6f0 vcvt.f64.s32 d7, s15 */
/* @0x14c6f4 vmov r0, r1, d7 */
/* @0x14c6f8 vmov r2, s14 */
/* @0x14c6fc mov r3, r1 */
/* @0x14c700 stm r4, {r2, r3} */
/* @0x14c704 pop {r3, r4, r5, r6, r7, pc} */
/* @0x14c708 andeq r0, r0, r0 */

/* ── FUNC 0x14c70c · F_PhysicsBindFixtureExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x14c70c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x14c710 mov r3, #0 */
/* @0x14c714 ldr r4, [sp, #0x20] */
/* @0x14c718 mov r5, r0 */
/* @0x14c71c str r3, [r0, #0xc] */
/* @0x14c720 mov r8, r1 */
/* @0x14c724 mov r1, r3 */
/* @0x14c728 mov r0, r4 */
/* @0x14c72c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c730 mov r1, #1 */
/* @0x14c734 mov r7, r0 */
/* @0x14c738 mov r0, r4 */
/* @0x14c73c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14c740 mov r1, #2 */
/* @0x14c744 mov r6, r0 */
/* @0x14c748 mov r0, r4 */
/* @0x14c74c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c750 mov r1, #3 */
/* @0x14c754 mov r9, r0 */
/* @0x14c758 mov r0, r4 */
/* @0x14c75c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c760 mov r1, r7 */
/* @0x14c764 mov r2, r6 */
/* @0x14c768 vmov s0, r9 */
/* @0x14c76c vmov s1, r0 */
/* @0x14c770 mov r0, r8 */
/* @0x14c774 bl 0x14c57c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x14c778 vmov s15, r0 */
/* @0x14c77c vcvt.f64.s32 d7, s15 */
/* @0x14c780 vmov r0, r1, d7 */
/* @0x14c784 vmov r2, s14 */
/* @0x14c788 mov r3, r1 */
/* @0x14c78c stm r5, {r2, r3} */
/* @0x14c790 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x14c794 · F_PhysicsSetMass(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x14c794 push {r4, r5, r6, lr} */
/* @0x14c798 vpush {d8} */
/* @0x14c79c ldr r5, [r1, #0x84] */
/* @0x14c7a0 ldr r4, [sp, #0x18] */
/* @0x14c7a4 cmp r5, #0 */
/* @0x14c7a8 beq 0x14c84c <_Z16F_PhysicsSetMassR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14c7ac ldr r3, [pc, #0xb0] */
/* @0x14c7b0 ldr r3, [pc, r3] */
/* @0x14c7b4 ldr r3, [r3] */
/* @0x14c7b8 cmp r3, #0 */
/* @0x14c7bc beq 0x14c834 <_Z16F_PhysicsSetMassR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c7c0 ldr r3, [r3, #0xb4] */
/* @0x14c7c4 cmp r3, #0 */
/* @0x14c7c8 beq 0x14c834 <_Z16F_PhysicsSetMassR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c7cc mov r0, r4 */
/* @0x14c7d0 mov r1, #0 */
/* @0x14c7d4 vldr s16, [r3, #96] */
/* @0x14c7d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c7dc mov r1, #1 */
/* @0x14c7e0 mov r6, r0 */
/* @0x14c7e4 mov r0, r4 */
/* @0x14c7e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c7ec mov r1, #2 */
/* @0x14c7f0 vmov s15, r0 */
/* @0x14c7f4 mov r0, r4 */
/* @0x14c7f8 vmul.f32 s17, s16, s15 */
/* @0x14c7fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c800 mov r1, #3 */
/* @0x14c804 vmov s15, r0 */
/* @0x14c808 mov r0, r4 */
/* @0x14c80c vmul.f32 s16, s16, s15 */
/* @0x14c810 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c814 vmov r2, s17 */
/* @0x14c818 mov r1, r6 */
/* @0x14c81c vmov r3, s16 */
/* @0x14c820 str r0, [sp, #0x18] */
/* @0x14c824 mov r0, r5 */
/* @0x14c828 vpop {d8} */
/* @0x14c82c pop {r4, r5, r6, lr} */
/* @0x14c830 b 0x236dd0 <_ZN14CPhysicsObject7SetMassEffff> */
/* @0x14c834 vpop {d8} */
/* @0x14c838 mov r1, #0 */
/* @0x14c83c ldr r0, [pc, #0x24] */
/* @0x14c840 add r0, pc, r0 */
/* @0x14c844 pop {r4, r5, r6, lr} */
/* @0x14c848 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c84c vpop {d8} */
/* @0x14c850 mov r1, r5 */
/* @0x14c854 ldr r0, [pc, #0x10] */
/* @0x14c858 add r0, pc, r0 */
/* @0x14c85c pop {r4, r5, r6, lr} */
/* @0x14c860 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c864 eoreq r1, r10, r8, ror r1 */
/* @0x14c868 andseq r7, pc, r4, ror #11 */
/* @0x14c86c andseq r7, pc, r12, lsl #11 */

/* ── FUNC 0x14c870 · F_PhysicsApplyForce(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x14c870 push {r4, r5, r6, lr} */
/* @0x14c874 vpush {d8} */
/* @0x14c878 ldr r5, [r1, #0x84] */
/* @0x14c87c ldr r4, [sp, #0x18] */
/* @0x14c880 cmp r5, #0 */
/* @0x14c884 beq 0x14c928 <_Z19F_PhysicsApplyForceR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14c888 ldr r3, [pc, #0xb0] */
/* @0x14c88c ldr r3, [pc, r3] */
/* @0x14c890 ldr r3, [r3] */
/* @0x14c894 cmp r3, #0 */
/* @0x14c898 beq 0x14c910 <_Z19F_PhysicsApplyForceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c89c ldr r3, [r3, #0xb4] */
/* @0x14c8a0 cmp r3, #0 */
/* @0x14c8a4 beq 0x14c910 <_Z19F_PhysicsApplyForceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c8a8 mov r0, r4 */
/* @0x14c8ac mov r1, #0 */
/* @0x14c8b0 vldr s16, [r3, #96] */
/* @0x14c8b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c8b8 mov r1, #1 */
/* @0x14c8bc vmov s15, r0 */
/* @0x14c8c0 mov r0, r4 */
/* @0x14c8c4 vmul.f32 s17, s16, s15 */
/* @0x14c8c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c8cc mov r1, #2 */
/* @0x14c8d0 vmov s15, r0 */
/* @0x14c8d4 mov r0, r4 */
/* @0x14c8d8 vmul.f32 s16, s16, s15 */
/* @0x14c8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c8e0 mov r1, #3 */
/* @0x14c8e4 mov r6, r0 */
/* @0x14c8e8 mov r0, r4 */
/* @0x14c8ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c8f0 vmov r1, s17 */
/* @0x14c8f4 vmov r2, s16 */
/* @0x14c8f8 mov r3, r6 */
/* @0x14c8fc str r0, [sp, #0x18] */
/* @0x14c900 mov r0, r5 */
/* @0x14c904 vpop {d8} */
/* @0x14c908 pop {r4, r5, r6, lr} */
/* @0x14c90c b 0x237058 <_ZN14CPhysicsObject10ApplyForceEffff> */
/* @0x14c910 vpop {d8} */
/* @0x14c914 mov r1, #0 */
/* @0x14c918 ldr r0, [pc, #0x24] */
/* @0x14c91c add r0, pc, r0 */
/* @0x14c920 pop {r4, r5, r6, lr} */
/* @0x14c924 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c928 vpop {d8} */
/* @0x14c92c mov r1, r5 */
/* @0x14c930 ldr r0, [pc, #0x10] */
/* @0x14c934 add r0, pc, r0 */
/* @0x14c938 pop {r4, r5, r6, lr} */
/* @0x14c93c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14c940 mlaeq r10, r12, r0, r1 */
/* @0x14c944 andseq r7, pc, r8, lsl #10 */
/* @0x14c948 ldrheq r7, [pc], -r0 */

/* ── FUNC 0x14c94c · F_PhysicsApplyImpulse(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x14c94c push {r4, r5, r6, lr} */
/* @0x14c950 vpush {d8} */
/* @0x14c954 ldr r5, [r1, #0x84] */
/* @0x14c958 ldr r4, [sp, #0x18] */
/* @0x14c95c cmp r5, #0 */
/* @0x14c960 beq 0x14ca04 <_Z21F_PhysicsApplyImpulseR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14c964 ldr r3, [pc, #0xb0] */
/* @0x14c968 ldr r3, [pc, r3] */
/* @0x14c96c ldr r3, [r3] */
/* @0x14c970 cmp r3, #0 */
/* @0x14c974 beq 0x14c9ec <_Z21F_PhysicsApplyImpulseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c978 ldr r3, [r3, #0xb4] */
/* @0x14c97c cmp r3, #0 */
/* @0x14c980 beq 0x14c9ec <_Z21F_PhysicsApplyImpulseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14c984 mov r0, r4 */
/* @0x14c988 mov r1, #0 */
/* @0x14c98c vldr s16, [r3, #96] */
/* @0x14c990 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c994 mov r1, #1 */
/* @0x14c998 vmov s15, r0 */
/* @0x14c99c mov r0, r4 */
/* @0x14c9a0 vmul.f32 s17, s16, s15 */
/* @0x14c9a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c9a8 mov r1, #2 */
/* @0x14c9ac vmov s15, r0 */
/* @0x14c9b0 mov r0, r4 */
/* @0x14c9b4 vmul.f32 s16, s16, s15 */
/* @0x14c9b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c9bc mov r1, #3 */
/* @0x14c9c0 mov r6, r0 */
/* @0x14c9c4 mov r0, r4 */
/* @0x14c9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14c9cc vmov r1, s17 */
/* @0x14c9d0 vmov r2, s16 */
/* @0x14c9d4 mov r3, r6 */
/* @0x14c9d8 str r0, [sp, #0x18] */
/* @0x14c9dc mov r0, r5 */
/* @0x14c9e0 vpop {d8} */
/* @0x14c9e4 pop {r4, r5, r6, lr} */
/* @0x14c9e8 b 0x236fd0 <_ZN14CPhysicsObject12ApplyImpulseEffff> */
/* @0x14c9ec vpop {d8} */
/* @0x14c9f0 mov r1, #0 */
/* @0x14c9f4 ldr r0, [pc, #0x24] */
/* @0x14c9f8 add r0, pc, r0 */
/* @0x14c9fc pop {r4, r5, r6, lr} */
/* @0x14ca00 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ca04 vpop {d8} */
/* @0x14ca08 mov r1, r5 */
/* @0x14ca0c ldr r0, [pc, #0x10] */
/* @0x14ca10 add r0, pc, r0 */
/* @0x14ca14 pop {r4, r5, r6, lr} */
/* @0x14ca18 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ca1c eoreq r0, r10, r0, asr #31 */
/* @0x14ca20 andseq r7, pc, r12, lsr #8 */
/* @0x14ca24 ldrsbeq r7, [pc], -r4 */

/* ── FUNC 0x14ca28 · F_PhysicsApplyAngularImpulse(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14ca28 push {r4, lr} */
/* @0x14ca2c ldr r4, [r1, #0x84] */
/* @0x14ca30 ldr r0, [sp, #0x8] */
/* @0x14ca34 cmp r4, #0 */
/* @0x14ca38 beq 0x14ca88 <_Z28F_PhysicsApplyAngularImpulseR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x14ca3c ldr r3, [pc, #0x58] */
/* @0x14ca40 ldr r3, [pc, r3] */
/* @0x14ca44 ldr r3, [r3] */
/* @0x14ca48 cmp r3, #0 */
/* @0x14ca4c beq 0x14ca74 <_Z28F_PhysicsApplyAngularImpulseR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14ca50 ldr r3, [r3, #0xb4] */
/* @0x14ca54 cmp r3, #0 */
/* @0x14ca58 beq 0x14ca74 <_Z28F_PhysicsApplyAngularImpulseR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14ca5c mov r1, #0 */
/* @0x14ca60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ca64 mov r1, r0 */
/* @0x14ca68 mov r0, r4 */
/* @0x14ca6c pop {r4, lr} */
/* @0x14ca70 b 0x2372a4 <_ZN14CPhysicsObject19ApplyAngularImpulseEf> */
/* @0x14ca74 ldr r0, [pc, #0x24] */
/* @0x14ca78 mov r1, #0 */
/* @0x14ca7c pop {r4, lr} */
/* @0x14ca80 add r0, pc, r0 */
/* @0x14ca84 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ca88 ldr r0, [pc, #0x14] */
/* @0x14ca8c mov r1, r4 */
/* @0x14ca90 pop {r4, lr} */
/* @0x14ca94 add r0, pc, r0 */
/* @0x14ca98 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ca9c eoreq r0, r10, r8, ror #29 */
/* @0x14caa0 andseq r7, pc, r4, lsr #7 */
/* @0x14caa4 andseq r7, pc, r0, asr r3 */

/* ── FUNC 0x14caa8 · F_PhysicsApplyLocalForce(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x14caa8 push {r4, r5, r6, lr} */
/* @0x14caac vpush {d8} */
/* @0x14cab0 ldr r5, [r1, #0x84] */
/* @0x14cab4 ldr r4, [sp, #0x18] */
/* @0x14cab8 cmp r5, #0 */
/* @0x14cabc beq 0x14cb60 <_Z24F_PhysicsApplyLocalForceR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14cac0 ldr r3, [pc, #0xb0] */
/* @0x14cac4 ldr r3, [pc, r3] */
/* @0x14cac8 ldr r3, [r3] */
/* @0x14cacc cmp r3, #0 */
/* @0x14cad0 beq 0x14cb48 <_Z24F_PhysicsApplyLocalForceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14cad4 ldr r3, [r3, #0xb4] */
/* @0x14cad8 cmp r3, #0 */
/* @0x14cadc beq 0x14cb48 <_Z24F_PhysicsApplyLocalForceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14cae0 mov r0, r4 */
/* @0x14cae4 mov r1, #0 */
/* @0x14cae8 vldr s16, [r3, #96] */
/* @0x14caec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14caf0 mov r1, #1 */
/* @0x14caf4 vmov s15, r0 */
/* @0x14caf8 mov r0, r4 */
/* @0x14cafc vmul.f32 s17, s16, s15 */
/* @0x14cb00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cb04 mov r1, #2 */
/* @0x14cb08 vmov s15, r0 */
/* @0x14cb0c mov r0, r4 */
/* @0x14cb10 vmul.f32 s16, s16, s15 */
/* @0x14cb14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cb18 mov r1, #3 */
/* @0x14cb1c mov r6, r0 */
/* @0x14cb20 mov r0, r4 */
/* @0x14cb24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cb28 vmov r1, s17 */
/* @0x14cb2c vmov r2, s16 */
/* @0x14cb30 mov r3, r6 */
/* @0x14cb34 str r0, [sp, #0x18] */
/* @0x14cb38 mov r0, r5 */
/* @0x14cb3c vpop {d8} */
/* @0x14cb40 pop {r4, r5, r6, lr} */
/* @0x14cb44 b 0x2370d8 <_ZN14CPhysicsObject15ApplyLocalForceEffff> */
/* @0x14cb48 vpop {d8} */
/* @0x14cb4c mov r1, #0 */
/* @0x14cb50 ldr r0, [pc, #0x24] */
/* @0x14cb54 add r0, pc, r0 */
/* @0x14cb58 pop {r4, r5, r6, lr} */
/* @0x14cb5c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cb60 vpop {d8} */
/* @0x14cb64 mov r1, r5 */
/* @0x14cb68 ldr r0, [pc, #0x10] */
/* @0x14cb6c add r0, pc, r0 */
/* @0x14cb70 pop {r4, r5, r6, lr} */
/* @0x14cb74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cb78 eoreq r0, r10, r4, ror #28 */
/* @0x14cb7c ldrsbeq r7, [pc], -r0 */
/* @0x14cb80 andseq r7, pc, r8, ror r2 */

/* ── FUNC 0x14cb84 · F_PhysicsApplyLocalImpulse(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x14cb84 push {r4, r5, r6, lr} */
/* @0x14cb88 vpush {d8} */
/* @0x14cb8c ldr r5, [r1, #0x84] */
/* @0x14cb90 ldr r4, [sp, #0x18] */
/* @0x14cb94 cmp r5, #0 */
/* @0x14cb98 beq 0x14cc3c <_Z26F_PhysicsApplyLocalImpulseR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14cb9c ldr r3, [pc, #0xb0] */
/* @0x14cba0 ldr r3, [pc, r3] */
/* @0x14cba4 ldr r3, [r3] */
/* @0x14cba8 cmp r3, #0 */
/* @0x14cbac beq 0x14cc24 <_Z26F_PhysicsApplyLocalImpulseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14cbb0 ldr r3, [r3, #0xb4] */
/* @0x14cbb4 cmp r3, #0 */
/* @0x14cbb8 beq 0x14cc24 <_Z26F_PhysicsApplyLocalImpulseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x14cbbc mov r0, r4 */
/* @0x14cbc0 mov r1, #0 */
/* @0x14cbc4 vldr s16, [r3, #96] */
/* @0x14cbc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cbcc mov r1, #1 */
/* @0x14cbd0 vmov s15, r0 */
/* @0x14cbd4 mov r0, r4 */
/* @0x14cbd8 vmul.f32 s17, s16, s15 */
/* @0x14cbdc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cbe0 mov r1, #2 */
/* @0x14cbe4 vmov s15, r0 */
/* @0x14cbe8 mov r0, r4 */
/* @0x14cbec vmul.f32 s16, s16, s15 */
/* @0x14cbf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cbf4 mov r1, #3 */
/* @0x14cbf8 mov r6, r0 */
/* @0x14cbfc mov r0, r4 */
/* @0x14cc00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cc04 vmov r1, s17 */
/* @0x14cc08 vmov r2, s16 */
/* @0x14cc0c mov r3, r6 */
/* @0x14cc10 str r0, [sp, #0x18] */
/* @0x14cc14 mov r0, r5 */
/* @0x14cc18 vpop {d8} */
/* @0x14cc1c pop {r4, r5, r6, lr} */
/* @0x14cc20 b 0x237190 <_ZN14CPhysicsObject17ApplyLocalImpulseEffff> */
/* @0x14cc24 vpop {d8} */
/* @0x14cc28 mov r1, #0 */
/* @0x14cc2c ldr r0, [pc, #0x24] */
/* @0x14cc30 add r0, pc, r0 */
/* @0x14cc34 pop {r4, r5, r6, lr} */
/* @0x14cc38 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cc3c vpop {d8} */
/* @0x14cc40 mov r1, r5 */
/* @0x14cc44 ldr r0, [pc, #0x10] */
/* @0x14cc48 add r0, pc, r0 */
/* @0x14cc4c pop {r4, r5, r6, lr} */
/* @0x14cc50 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cc54 eoreq r0, r10, r8, lsl #27 */
/* @0x14cc58 ldrsheq r7, [pc], -r4 */
/* @0x14cc5c mulseq pc, r12, r1 */

/* ── FUNC 0x14cc60 · F_PhysicsTestOverlap(RValue&, CInstance*, CInstance*, int, RValue*) · size=440 · insn=110 */
/* @0x14cc60 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x14cc64 vpush {d8, d9} */
/* @0x14cc68 mov r7, r0 */
/* @0x14cc6c mov r8, r1 */
/* @0x14cc70 mov r0, #0 */
/* @0x14cc74 str r0, [r7] */
/* @0x14cc78 sub sp, sp, #48 */
/* @0x14cc7c str r0, [r7, #0x4] */
/* @0x14cc80 mov r10, r2 */
/* @0x14cc84 ldr r1, [r1, #0x84] */
/* @0x14cc88 ldr r6, [sp, #0x60] */
/* @0x14cc8c cmp r1, r0 */
/* @0x14cc90 str r0, [r7, #0xc] */
/* @0x14cc94 beq 0x14cdec <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x14cc98 mov r0, r6 */
/* @0x14cc9c mov r1, #3 */
/* @0x14cca0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14cca4 ldr r5, [pc, #0x160] */
/* @0x14cca8 ldr r5, [pc, r5] */
/* @0x14ccac ldr r3, [r5] */
/* @0x14ccb0 cmn r0, #1 */
/* @0x14ccb4 mov r9, r0 */
/* @0x14ccb8 ldreq r9, [r8, #0x78] */
/* @0x14ccbc cmp r3, #0 */
/* @0x14ccc0 beq 0x14cdd0 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x14ccc4 ldr r3, [r3, #0xb4] */
/* @0x14ccc8 cmp r3, #0 */
/* @0x14cccc beq 0x14cdd0 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x14ccd0 mov r0, r6 */
/* @0x14ccd4 mov r1, #0 */
/* @0x14ccd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ccdc ldr r3, [r5] */
/* @0x14cce0 mov r1, #1 */
/* @0x14cce4 vldr s16, [pc, #280] */
/* @0x14cce8 add r4, sp, #12 */
/* @0x14ccec ldr r3, [r3, #0xb4] */
/* @0x14ccf0 vldr s18, [r3, #96] */
/* @0x14ccf4 vmov s14, r0 */
/* @0x14ccf8 mov r0, r6 */
/* @0x14ccfc vmul.f32 s18, s14, s18 */
/* @0x14cd00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cd04 ldr r3, [r5] */
/* @0x14cd08 mov r1, #2 */
/* @0x14cd0c ldr r3, [r3, #0xb4] */
/* @0x14cd10 vldr s17, [r3, #96] */
/* @0x14cd14 vmov s15, r0 */
/* @0x14cd18 mov r0, r6 */
/* @0x14cd1c vmul.f32 s17, s15, s17 */
/* @0x14cd20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cd24 mov r12, #0 */
/* @0x14cd28 mov r1, r9 */
/* @0x14cd2c mov r3, r10 */
/* @0x14cd30 mov r2, r8 */
/* @0x14cd34 str r12, [sp] */
/* @0x14cd38 vldr s15, [pc, #200] */
/* @0x14cd3c vmov s14, r0 */
/* @0x14cd40 mov r0, r4 */
/* @0x14cd44 vmul.f32 s16, s14, s16 */
/* @0x14cd48 vdiv.f32 s16, s16, s15 */
/* @0x14cd4c bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x14cd50 b 0x14cd5c <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x14cd54 mov r0, r4 */
/* @0x14cd58 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x14cd5c mov r0, r4 */
/* @0x14cd60 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x14cd64 cmp r0, #0 */
/* @0x14cd68 mov r0, r4 */
/* @0x14cd6c beq 0x14cdc4 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x14cd70 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x14cd74 ldrb r3, [r0, #0x68] */
/* @0x14cd78 cmp r3, #0 */
/* @0x14cd7c bne 0x14cd54 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x14cd80 ldrb r6, [r0, #0x69] */
/* @0x14cd84 cmp r6, #0 */
/* @0x14cd88 bne 0x14cd54 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x14cd8c ldr r12, [r5] */
/* @0x14cd90 mov r2, r0 */
/* @0x14cd94 mov r1, r8 */
/* @0x14cd98 vmov r3, s18 */
/* @0x14cd9c ldr r0, [r12, #0xb4] */
/* @0x14cda0 vstr s17, [sp] */
/* @0x14cda4 vstr s16, [sp, #4] */
/* @0x14cda8 bl 0x239818 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff> */
/* @0x14cdac cmp r0, #0 */
/* @0x14cdb0 beq 0x14cd54 <_Z20F_PhysicsTestOverlapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x14cdb4 mov r3, #0 */
/* @0x14cdb8 str r6, [r7] */
/* @0x14cdbc movt r3, #0x3ff0 */
/* @0x14cdc0 str r3, [r7, #0x4] */
/* @0x14cdc4 add sp, sp, #48 */
/* @0x14cdc8 vpop {d8, d9} */
/* @0x14cdcc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x14cdd0 ldr r0, [pc, #0x38] */
/* @0x14cdd4 mov r1, #0 */
/* @0x14cdd8 add r0, pc, r0 */
/* @0x14cddc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cde0 add sp, sp, #48 */
/* @0x14cde4 vpop {d8, d9} */
/* @0x14cde8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x14cdec ldr r0, [pc, #0x20] */
/* @0x14cdf0 add r0, pc, r0 */
/* @0x14cdf4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cdf8 add sp, sp, #48 */
/* @0x14cdfc vpop {d8, d9} */
/* @0x14ce00 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x14ce04 ldrdmi r0, r1, [r9], #-251 */
/* @0x14ce08 teqmi r4, #0 */
/* @0x14ce0c eoreq r0, r10, r0, lsl #25 */
/* @0x14ce10 andseq r7, pc, r12, asr #32 */
/* @0x14ce14 ldrsheq r6, [pc], -r4 */

/* ── FUNC 0x14ce18 · F_PhysicsRemoveFixture(RValue&, CInstance*, CInstance*, int, RValue*) · size=288 · insn=72 */
/* @0x14ce18 ldr r12, [pc, #0x110] */
/* @0x14ce1c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x14ce20 ldr r12, [pc, r12] */
/* @0x14ce24 mov r6, #0 */
/* @0x14ce28 str r6, [r0] */
/* @0x14ce2c ldr r12, [r12] */
/* @0x14ce30 sub sp, sp, #48 */
/* @0x14ce34 mov r5, r0 */
/* @0x14ce38 mov r9, r1 */
/* @0x14ce3c cmp r12, r6 */
/* @0x14ce40 mov r0, r6 */
/* @0x14ce44 mov r8, r2 */
/* @0x14ce48 movt r0, #0xbff0 */
/* @0x14ce4c str r6, [r5, #0xc] */
/* @0x14ce50 str r0, [r5, #0x4] */
/* @0x14ce54 ldr r7, [sp, #0x50] */
/* @0x14ce58 beq 0x14cf18 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x14ce5c ldr r3, [r12, #0xb4] */
/* @0x14ce60 cmp r3, r6 */
/* @0x14ce64 beq 0x14cf18 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x14ce68 mov r1, r6 */
/* @0x14ce6c mov r0, r7 */
/* @0x14ce70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ce74 mov r1, #1 */
/* @0x14ce78 add r4, sp, #12 */
/* @0x14ce7c mov r10, r0 */
/* @0x14ce80 mov r0, r7 */
/* @0x14ce84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ce88 mov r1, r10 */
/* @0x14ce8c str r6, [sp] */
/* @0x14ce90 mov r2, r9 */
/* @0x14ce94 mov r3, r8 */
/* @0x14ce98 mov r7, r0 */
/* @0x14ce9c mov r0, r4 */
/* @0x14cea0 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x14cea4 b 0x14cf00 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x14cea8 mov r0, r4 */
/* @0x14ceac bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x14ceb0 ldrb r3, [r0, #0x68] */
/* @0x14ceb4 cmp r3, #0 */
/* @0x14ceb8 bne 0x14cef8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x14cebc ldrb r6, [r0, #0x69] */
/* @0x14cec0 cmp r6, #0 */
/* @0x14cec4 bne 0x14cef8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x14cec8 ldr r0, [r0, #0x84] */
/* @0x14cecc cmp r0, #0 */
/* @0x14ced0 beq 0x14cef8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x14ced4 mov r1, r7 */
/* @0x14ced8 bl 0x2377c4 <_ZN14CPhysicsObject13RemoveFixtureEi> */
/* @0x14cedc cmp r0, #0 */
/* @0x14cee0 moveq r6, r0 */
/* @0x14cee4 movne r3, #0 */
/* @0x14cee8 moveq r3, r6 */
/* @0x14ceec movtne r3, #0x3ff0 */
/* @0x14cef0 str r6, [r5] */
/* @0x14cef4 str r3, [r5, #0x4] */
/* @0x14cef8 mov r0, r4 */
/* @0x14cefc bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x14cf00 mov r0, r4 */
/* @0x14cf04 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x14cf08 cmp r0, #0 */
/* @0x14cf0c bne 0x14cea8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x14cf10 add sp, sp, #48 */
/* @0x14cf14 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x14cf18 ldr r0, [pc, #0x14] */
/* @0x14cf1c mov r1, #0 */
/* @0x14cf20 add r0, pc, r0 */
/* @0x14cf24 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cf28 add sp, sp, #48 */
/* @0x14cf2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x14cf30 eoreq r0, r10, r8, lsl #22 */
/* @0x14cf34 andseq r6, pc, r4, lsr #31 */

/* ── FUNC 0x14cf38 · F_PhysicsSetGravity(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x14cf38 ldr r3, [pc, #0x74] */
/* @0x14cf3c push {r4, r5, r6, lr} */
/* @0x14cf40 ldr r3, [pc, r3] */
/* @0x14cf44 ldr r5, [sp, #0x10] */
/* @0x14cf48 ldr r4, [r3] */
/* @0x14cf4c cmp r4, #0 */
/* @0x14cf50 beq 0x14cfa0 <_Z19F_PhysicsSetGravityR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x14cf54 ldr r1, [r4, #0xb4] */
/* @0x14cf58 cmp r1, #0 */
/* @0x14cf5c beq 0x14cf90 <_Z19F_PhysicsSetGravityR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x14cf60 mov r0, r5 */
/* @0x14cf64 mov r1, #0 */
/* @0x14cf68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cf6c mov r1, #1 */
/* @0x14cf70 mov r6, r0 */
/* @0x14cf74 mov r0, r5 */
/* @0x14cf78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14cf7c mov r1, r6 */
/* @0x14cf80 mov r2, r0 */
/* @0x14cf84 ldr r0, [r4, #0xb4] */
/* @0x14cf88 pop {r4, r5, r6, lr} */
/* @0x14cf8c b 0x238c14 <_ZN13CPhysicsWorld10SetGravityEff> */
/* @0x14cf90 ldr r0, [pc, #0x20] */
/* @0x14cf94 pop {r4, r5, r6, lr} */
/* @0x14cf98 add r0, pc, r0 */
/* @0x14cf9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cfa0 ldr r0, [pc, #0x14] */
/* @0x14cfa4 mov r1, r4 */
/* @0x14cfa8 pop {r4, r5, r6, lr} */
/* @0x14cfac add r0, pc, r0 */
/* @0x14cfb0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14cfb4 eoreq r0, r10, r8, ror #19 */
/* @0x14cfb8 andseq r6, pc, r12, lsl #29 */
/* @0x14cfbc andseq r6, pc, r0, ror #30 */

/* ── FUNC 0x14cfc0 · F_PhysicsSetUpdateSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x14cfc0 ldr r3, [pc, #0x58] */
/* @0x14cfc4 push {r4, lr} */
/* @0x14cfc8 ldr r3, [pc, r3] */
/* @0x14cfcc ldr r0, [sp, #0x8] */
/* @0x14cfd0 ldr r4, [r3] */
/* @0x14cfd4 cmp r4, #0 */
/* @0x14cfd8 beq 0x14d00c <_Z23F_PhysicsSetUpdateSpeedR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14cfdc ldr r1, [r4, #0xb4] */
/* @0x14cfe0 cmp r1, #0 */
/* @0x14cfe4 beq 0x14cffc <_Z23F_PhysicsSetUpdateSpeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x14cfe8 mov r1, #0 */
/* @0x14cfec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14cff0 ldr r3, [r4, #0xb4] */
/* @0x14cff4 str r0, [r3, #0x58] */
/* @0x14cff8 pop {r4, pc} */
/* @0x14cffc ldr r0, [pc, #0x20] */
/* @0x14d000 pop {r4, lr} */
/* @0x14d004 add r0, pc, r0 */
/* @0x14d008 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d00c ldr r0, [pc, #0x14] */
/* @0x14d010 mov r1, r4 */
/* @0x14d014 pop {r4, lr} */
/* @0x14d018 add r0, pc, r0 */
/* @0x14d01c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d020 eoreq r0, r10, r0, ror #18 */
/* @0x14d024 andseq r6, pc, r0, lsr #28 */
/* @0x14d028 ldrsheq r6, [pc], -r4 */

/* ── FUNC 0x14d02c · F_PhysicsSetUpdateIterations(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x14d02c ldr r3, [pc, #0x58] */
/* @0x14d030 push {r4, lr} */
/* @0x14d034 ldr r3, [pc, r3] */
/* @0x14d038 ldr r0, [sp, #0x8] */
/* @0x14d03c ldr r4, [r3] */
/* @0x14d040 cmp r4, #0 */
/* @0x14d044 beq 0x14d078 <_Z28F_PhysicsSetUpdateIterationsR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14d048 ldr r1, [r4, #0xb4] */
/* @0x14d04c cmp r1, #0 */
/* @0x14d050 beq 0x14d068 <_Z28F_PhysicsSetUpdateIterationsR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x14d054 mov r1, #0 */
/* @0x14d058 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d05c ldr r3, [r4, #0xb4] */
/* @0x14d060 str r0, [r3, #0x5c] */
/* @0x14d064 pop {r4, pc} */
/* @0x14d068 ldr r0, [pc, #0x20] */
/* @0x14d06c pop {r4, lr} */
/* @0x14d070 add r0, pc, r0 */
/* @0x14d074 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d078 ldr r0, [pc, #0x14] */
/* @0x14d07c mov r1, r4 */
/* @0x14d080 pop {r4, lr} */
/* @0x14d084 add r0, pc, r0 */
/* @0x14d088 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d08c .word 0x002a08f4 */
/* @0x14d090 ldrheq r6, [pc], -r4 */
/* @0x14d094 andseq r6, pc, r8, lsl #29 */

/* ── FUNC 0x14d098 · F_PhysicsDeleteJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x14d098 ldr r3, [pc, #0x44] */
/* @0x14d09c push {r4, lr} */
/* @0x14d0a0 ldr r3, [pc, r3] */
/* @0x14d0a4 ldr r0, [sp, #0x8] */
/* @0x14d0a8 ldr r3, [r3] */
/* @0x14d0ac ldr r4, [r3, #0xb4] */
/* @0x14d0b0 cmp r4, #0 */
/* @0x14d0b4 beq 0x14d0d0 <_Z20F_PhysicsDeleteJointR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x14d0b8 mov r1, #0 */
/* @0x14d0bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d0c0 mov r1, r0 */
/* @0x14d0c4 mov r0, r4 */
/* @0x14d0c8 pop {r4, lr} */
/* @0x14d0cc b 0x237f90 <_ZN13CPhysicsWorld11DeleteJointEi> */
/* @0x14d0d0 ldr r0, [pc, #0x10] */
/* @0x14d0d4 mov r1, r4 */
/* @0x14d0d8 pop {r4, lr} */
/* @0x14d0dc add r0, pc, r0 */
/* @0x14d0e0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d0e4 eoreq r0, r10, r8, lsl #17 */
/* @0x14d0e8 andseq r6, pc, r8, asr #26 */

/* ── FUNC 0x14d0ec · F_PhysicsDebugRender(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14d0ec ldr r3, [pc, #0x4c] */
/* @0x14d0f0 ldr r3, [pc, r3] */
/* @0x14d0f4 ldr r3, [r3] */
/* @0x14d0f8 cmp r3, #0 */
/* @0x14d0fc beq 0x14d12c <_Z20F_PhysicsDebugRenderR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14d100 ldr r3, [r3, #0xb4] */
/* @0x14d104 cmp r3, #0 */
/* @0x14d108 beq 0x14d12c <_Z20F_PhysicsDebugRenderR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14d10c ldr r0, [r1, #0x84] */
/* @0x14d110 cmp r0, #0 */
/* @0x14d114 beq 0x14d13c <_Z20F_PhysicsDebugRenderR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x14d118 vmov.f32 s14, #1.000000e+00 */
/* @0x14d11c vldr s15, [r3, #96] */
/* @0x14d120 vdiv.f32 s15, s14, s15 */
/* @0x14d124 vmov r1, s15 */
/* @0x14d128 b 0x2376dc <_ZN14CPhysicsObject11DebugRenderEf> */
/* @0x14d12c ldr r0, [pc, #0x10] */
/* @0x14d130 mov r1, #0 */
/* @0x14d134 add r0, pc, r0 */
/* @0x14d138 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d13c bx lr */
/* @0x14d140 eoreq r0, r10, r8, lsr r8 */
/* @0x14d144 ldrsheq r6, [pc], -r0 */

/* ── FUNC 0x14d148 · F_PhysicsDebugRenderAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x14d148 push {r4, lr} */
/* @0x14d14c ldr r4, [pc, #0x4c] */
/* @0x14d150 ldr r0, [sp, #0x8] */
/* @0x14d154 ldr r4, [pc, r4] */
/* @0x14d158 ldr r3, [r4] */
/* @0x14d15c cmp r3, #0 */
/* @0x14d160 beq 0x14d18c <_Z23F_PhysicsDebugRenderAllR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x14d164 ldr r3, [r3, #0xb4] */
/* @0x14d168 cmp r3, #0 */
/* @0x14d16c beq 0x14d18c <_Z23F_PhysicsDebugRenderAllR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x14d170 mov r1, #0 */
/* @0x14d174 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d178 ldr r3, [r4] */
/* @0x14d17c pop {r4, lr} */
/* @0x14d180 mov r1, r0 */
/* @0x14d184 ldr r0, [r3, #0xb4] */
/* @0x14d188 b 0x238438 <_ZN13CPhysicsWorld11DebugRenderEj> */
/* @0x14d18c ldr r0, [pc, #0x10] */
/* @0x14d190 mov r1, #0 */
/* @0x14d194 pop {r4, lr} */
/* @0x14d198 add r0, pc, r0 */
/* @0x14d19c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d1a0 .word 0x002a07d4 */
/* @0x14d1a4 andseq r6, pc, r12, lsl #25 */

/* ── FUNC 0x14d1a8 · F_PhysicsPause(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x14d1a8 push {r4, lr} */
/* @0x14d1ac ldr r4, [pc, #0x64] */
/* @0x14d1b0 ldr r0, [sp, #0x8] */
/* @0x14d1b4 ldr r4, [pc, r4] */
/* @0x14d1b8 ldr r3, [r4] */
/* @0x14d1bc cmp r3, #0 */
/* @0x14d1c0 beq 0x14d204 <_Z14F_PhysicsPauseR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x14d1c4 ldr r3, [r3, #0xb4] */
/* @0x14d1c8 cmp r3, #0 */
/* @0x14d1cc beq 0x14d204 <_Z14F_PhysicsPauseR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x14d1d0 mov r1, #0 */
/* @0x14d1d4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14d1d8 cmp r0, #0 */
/* @0x14d1dc beq 0x14d1f4 <_Z14F_PhysicsPauseR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14d1e0 ldr r3, [r4] */
/* @0x14d1e4 mov r2, #1 */
/* @0x14d1e8 ldr r3, [r3, #0xb4] */
/* @0x14d1ec strb r2, [r3, #0x64] */
/* @0x14d1f0 pop {r4, pc} */
/* @0x14d1f4 ldr r3, [r4] */
/* @0x14d1f8 ldr r3, [r3, #0xb4] */
/* @0x14d1fc strb r0, [r3, #0x64] */
/* @0x14d200 pop {r4, pc} */
/* @0x14d204 ldr r0, [pc, #0x10] */
/* @0x14d208 mov r1, #0 */
/* @0x14d20c pop {r4, lr} */
/* @0x14d210 add r0, pc, r0 */
/* @0x14d214 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d218 eoreq r0, r10, r4, ror r7 */
/* @0x14d21c andseq r6, pc, r0, lsr sp */

/* ── FUNC 0x14d220 · F_PhysicsCreateParticle(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x14d220 ldr r3, [pc, #0x128] */
/* @0x14d224 mov r1, #0 */
/* @0x14d228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d22c ldr r3, [pc, r3] */
/* @0x14d230 str r1, [r0] */
/* @0x14d234 sub sp, sp, #36 */
/* @0x14d238 ldr r3, [r3] */
/* @0x14d23c mov r2, r1 */
/* @0x14d240 mov r5, r0 */
/* @0x14d244 movt r2, #0xbff0 */
/* @0x14d248 cmp r3, r1 */
/* @0x14d24c str r1, [r0, #0xc] */
/* @0x14d250 str r2, [r0, #0x4] */
/* @0x14d254 ldr r4, [sp, #0x48] */
/* @0x14d258 beq 0x14d338 <_Z23F_PhysicsCreateParticleR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x14d25c ldr r6, [r3, #0xb4] */
/* @0x14d260 cmp r6, r1 */
/* @0x14d264 beq 0x14d338 <_Z23F_PhysicsCreateParticleR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x14d268 mov r0, r4 */
/* @0x14d26c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x14d270 mov r1, #1 */
/* @0x14d274 mov r9, r0 */
/* @0x14d278 mov r0, r4 */
/* @0x14d27c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d280 mov r1, #2 */
/* @0x14d284 mov r8, r0 */
/* @0x14d288 mov r0, r4 */
/* @0x14d28c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d290 mov r1, #3 */
/* @0x14d294 mov r7, r0 */
/* @0x14d298 mov r0, r4 */
/* @0x14d29c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d2a0 mov r1, #4 */
/* @0x14d2a4 mov r2, r0 */
/* @0x14d2a8 mov r0, r4 */
/* @0x14d2ac str r2, [sp, #0x18] */
/* @0x14d2b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d2b4 mov r1, #5 */
/* @0x14d2b8 mov r3, r0 */
/* @0x14d2bc mov r0, r4 */
/* @0x14d2c0 str r3, [sp, #0x1c] */
/* @0x14d2c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d2c8 mov r1, #6 */
/* @0x14d2cc mov r11, r0 */
/* @0x14d2d0 mov r0, r4 */
/* @0x14d2d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d2d8 mov r1, #7 */
/* @0x14d2dc mov r10, r0 */
/* @0x14d2e0 mov r0, r4 */
/* @0x14d2e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d2e8 ldr r2, [sp, #0x18] */
/* @0x14d2ec ldr r3, [sp, #0x1c] */
/* @0x14d2f0 mov r1, r9 */
/* @0x14d2f4 str r11, [sp, #0x8] */
/* @0x14d2f8 str r2, [sp] */
/* @0x14d2fc mov r2, r8 */
/* @0x14d300 str r3, [sp, #0x4] */
/* @0x14d304 mov r3, r7 */
/* @0x14d308 str r10, [sp, #0xc] */
/* @0x14d30c str r0, [sp, #0x10] */
/* @0x14d310 mov r0, r6 */
/* @0x14d314 bl 0x2398e4 <_ZN13CPhysicsWorld14CreateParticleEjffffjfi> */
/* @0x14d318 vmov s15, r0 */
/* @0x14d31c vcvt.f64.s32 d7, s15 */
/* @0x14d320 vmov r0, r1, d7 */
/* @0x14d324 vmov r2, s14 */
/* @0x14d328 mov r3, r1 */
/* @0x14d32c stm r5, {r2, r3} */
/* @0x14d330 add sp, sp, #36 */
/* @0x14d334 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14d338 ldr r0, [pc, #0x14] */
/* @0x14d33c mov r1, #0 */
/* @0x14d340 add r0, pc, r0 */
/* @0x14d344 add sp, sp, #36 */
/* @0x14d348 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14d34c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d350 .word 0x002a06fc */
/* @0x14d354 andseq r6, pc, r8, asr r12 */

/* ── FUNC 0x14d358 · F_PhysicsDestroyParticle(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14d358 ldr r3, [pc, #0x4c] */
/* @0x14d35c push {r4, lr} */
/* @0x14d360 ldr r3, [pc, r3] */
/* @0x14d364 ldr r0, [sp, #0x8] */
/* @0x14d368 ldr r3, [r3] */
/* @0x14d36c cmp r3, #0 */
/* @0x14d370 beq 0x14d398 <_Z24F_PhysicsDestroyParticleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14d374 ldr r4, [r3, #0xb4] */
/* @0x14d378 cmp r4, #0 */
/* @0x14d37c beq 0x14d398 <_Z24F_PhysicsDestroyParticleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14d380 mov r1, #0 */
/* @0x14d384 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14d388 mov r1, r0 */
/* @0x14d38c mov r0, r4 */
/* @0x14d390 pop {r4, lr} */
/* @0x14d394 b 0x23999c <_ZN13CPhysicsWorld14DeleteParticleEi> */
/* @0x14d398 ldr r0, [pc, #0x10] */
/* @0x14d39c mov r1, #0 */
/* @0x14d3a0 pop {r4, lr} */
/* @0x14d3a4 add r0, pc, r0 */
/* @0x14d3a8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d3ac eoreq r0, r10, r8, asr #11 */
/* @0x14d3b0 andseq r6, pc, r12, asr #24 */

/* ── FUNC 0x14d3b4 · F_PhysicsDestroyParticleRegionCircle(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x14d3b4 ldr r3, [pc, #0x78] */
/* @0x14d3b8 push {r4, r5, r6, r7, r8, lr} */
/* @0x14d3bc ldr r3, [pc, r3] */
/* @0x14d3c0 ldr r4, [sp, #0x18] */
/* @0x14d3c4 ldr r3, [r3] */
/* @0x14d3c8 cmp r3, #0 */
/* @0x14d3cc beq 0x14d420 <_Z36F_PhysicsDestroyParticleRegionCircleR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x14d3d0 ldr r5, [r3, #0xb4] */
/* @0x14d3d4 cmp r5, #0 */
/* @0x14d3d8 beq 0x14d420 <_Z36F_PhysicsDestroyParticleRegionCircleR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x14d3dc mov r0, r4 */
/* @0x14d3e0 mov r1, #0 */
/* @0x14d3e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d3e8 mov r1, #1 */
/* @0x14d3ec mov r7, r0 */
/* @0x14d3f0 mov r0, r4 */
/* @0x14d3f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d3f8 mov r1, #2 */
/* @0x14d3fc mov r6, r0 */
/* @0x14d400 mov r0, r4 */
/* @0x14d404 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14d408 mov r1, r7 */
/* @0x14d40c mov r2, r6 */
/* @0x14d410 mov r3, r0 */
/* @0x14d414 mov r0, r5 */
/* @0x14d418 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14d41c b 0x239f50 <_ZN13CPhysicsWorld26DeleteParticleCircleRegionEfff> */
/* @0x14d420 ldr r0, [pc, #0x10] */
/* @0x14d424 mov r1, #0 */
/* @0x14d428 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14d42c add r0, pc, r0 */
/* @0x14d430 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14d434 eoreq r0, r10, r12, ror #10 */
/* @0x14d438 andseq r6, pc, r12, lsl r12 */
