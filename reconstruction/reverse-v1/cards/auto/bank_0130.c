/* libyoyo.so 覆盖卡组 0130
 * 函数 0x192aa0..0x194a90，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x192aa0 · CInstance::Compute_Speed2() · size=264 · insn=66 */
/* @0x192aa0 push {r4, lr} */
/* @0x192aa4 vldr s15, [pc, #240] */
/* @0x192aa8 vpush {d8, d9} */
/* @0x192aac vldr s18, [r0, #204] */
/* @0x192ab0 vmul.f32 s18, s18, s15 */
/* @0x192ab4 vldr s15, [pc, #228] */
/* @0x192ab8 vldr s17, [r0, #208] */
/* @0x192abc mov r4, r0 */
/* @0x192ac0 vdiv.f32 s18, s18, s15 */
/* @0x192ac4 vmov r0, s18 */
/* @0x192ac8 bl 0xb658c <cosf@plt> */
/* @0x192acc vmov s12, r0 */
/* @0x192ad0 vmov r0, s18 */
/* @0x192ad4 vmul.f32 s16, s17, s12 */
/* @0x192ad8 vstr s16, [r4, #224] */
/* @0x192adc bl 0xb6580 <sinf@plt> */
/* @0x192ae0 vcvt.f64.f32 d7, s16 */
/* @0x192ae4 vmov s13, r0 */
/* @0x192ae8 vmov r0, r1, d7 */
/* @0x192aec vnmul.f32 s17, s17, s13 */
/* @0x192af0 vstr s17, [r4, #228] */
/* @0x192af4 bl 0xb66e8 <lrint@plt> */
/* @0x192af8 vldr s15, [pc, #164] */
/* @0x192afc vmov s12, r0 */
/* @0x192b00 vcvt.f32.s32 s14, s12 */
/* @0x192b04 vsub.f32 s16, s16, s14 */
/* @0x192b08 vabs.f32 s16, s16 */
/* @0x192b0c vcmpe.f32 s16, s15 */
/* @0x192b10 vmrs APSR_nzcv, fpscr */
/* @0x192b14 bmi 0x192b7c <_ZN9CInstance14Compute_Speed2Ev+0xdc> */
/* @0x192b18 vldr s16, [r4, #228] */
/* @0x192b1c vcvt.f64.f32 d7, s16 */
/* @0x192b20 vmov r0, r1, d7 */
/* @0x192b24 bl 0xb66e8 <lrint@plt> */
/* @0x192b28 vldr s15, [pc, #116] */
/* @0x192b2c vmov s12, r0 */
/* @0x192b30 vcvt.f32.s32 s14, s12 */
/* @0x192b34 vsub.f32 s16, s16, s14 */
/* @0x192b38 vabs.f32 s16, s16 */
/* @0x192b3c vcmpe.f32 s16, s15 */
/* @0x192b40 vmrs APSR_nzcv, fpscr */
/* @0x192b44 bpl 0x192b64 <_ZN9CInstance14Compute_Speed2Ev+0xc4> */
/* @0x192b48 vldr s15, [r4, #228] */
/* @0x192b4c vcvt.f64.f32 d6, s15 */
/* @0x192b50 vmov r0, r1, d6 */
/* @0x192b54 bl 0xb66e8 <lrint@plt> */
/* @0x192b58 vmov s13, r0 */
/* @0x192b5c vcvt.f32.s32 s15, s13 */
/* @0x192b60 vstr s15, [r4, #228] */
/* @0x192b64 vpop {d8, d9} */
/* @0x192b68 mov r3, #1 */
/* @0x192b6c mov r0, r4 */
/* @0x192b70 strb r3, [r4, #0x64] */
/* @0x192b74 pop {r4, lr} */
/* @0x192b78 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x192b7c vldr s15, [r4, #224] */
/* @0x192b80 vcvt.f64.f32 d6, s15 */
/* @0x192b84 vmov r0, r1, d6 */
/* @0x192b88 bl 0xb66e8 <lrint@plt> */
/* @0x192b8c vmov s13, r0 */
/* @0x192b90 vcvt.f32.s32 s15, s13 */
/* @0x192b94 vstr s15, [r4, #224] */
/* @0x192b98 b 0x192b18 <_ZN9CInstance14Compute_Speed2Ev+0x78> */
/* @0x192b9c ldrdmi r0, r1, [r9], #-251 */
/* @0x192ba0 teqmi r4, #0 */
/* @0x192ba4 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */

/* ── FUNC 0x192ba8 · CInstance::Set_MaskIndex(int) · size=28 · insn=7 */
/* @0x192ba8 ldr r2, [r0, #0xac] */
/* @0x192bac cmp r2, r1 */
/* @0x192bb0 bxeq lr */
/* @0x192bb4 mov r2, #1 */
/* @0x192bb8 str r1, [r0, #0xac] */
/* @0x192bbc strb r2, [r0, #0x64] */
/* @0x192bc0 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */

/* ── FUNC 0x192bc4 · CInstance::RelinkObjectTypes() · size=272 · insn=68 */
/* @0x192bc4 push {r4, lr} */
/* @0x192bc8 mov r4, r0 */
/* @0x192bcc ldr r0, [r0, #0x168] */
/* @0x192bd0 cmp r0, #0 */
/* @0x192bd4 beq 0x192be0 <_ZN9CInstance17RelinkObjectTypesEv+0x1c> */
/* @0x192bd8 mov r1, r4 */
/* @0x192bdc bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */
/* @0x192be0 mov r3, #0 */
/* @0x192be4 ldr r0, [r4, #0x80] */
/* @0x192be8 str r3, [r4, #0x168] */
/* @0x192bec mov r1, r4 */
/* @0x192bf0 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */
/* @0x192bf4 ldrb r3, [r4, #0x69] */
/* @0x192bf8 cmp r3, #0 */
/* @0x192bfc popne {r4, pc} */
/* @0x192c00 ldr r2, [pc, #0xc8] */
/* @0x192c04 ldr r3, [r4, #0x17c] */
/* @0x192c08 ldr r1, [r4, #0x178] */
/* @0x192c0c ldr r2, [pc, r2] */
/* @0x192c10 cmp r3, #0 */
/* @0x192c14 ldr r2, [r2] */
/* @0x192c18 strne r1, [r3, #0x178] */
/* @0x192c1c ldrne r1, [r4, #0x178] */
/* @0x192c20 ldrne r3, [r4, #0x17c] */
/* @0x192c24 streq r1, [r2, #0x80] */
/* @0x192c28 cmp r1, #0 */
/* @0x192c2c streq r3, [r2, #0x84] */
/* @0x192c30 strne r3, [r1, #0x17c] */
/* @0x192c34 mov r1, #0 */
/* @0x192c38 ldrne r3, [r2, #0x84] */
/* @0x192c3c str r1, [r4, #0x178] */
/* @0x192c40 cmp r3, #0 */
/* @0x192c44 str r1, [r4, #0x17c] */
/* @0x192c48 vldrne s14, [r4, #384] */
/* @0x192c4c beq 0x192cbc <_ZN9CInstance17RelinkObjectTypesEv+0xf8> */
/* @0x192c50 vldr s15, [r3, #388] */
/* @0x192c54 vcmpe.f32 s14, s15 */
/* @0x192c58 vmrs APSR_nzcv, fpscr */
/* @0x192c5c bge 0x192c88 <_ZN9CInstance17RelinkObjectTypesEv+0xc4> */
/* @0x192c60 ldr r3, [r3, #0x17c] */
/* @0x192c64 cmp r3, #0 */
/* @0x192c68 bne 0x192c50 <_ZN9CInstance17RelinkObjectTypesEv+0x8c> */
/* @0x192c6c ldr r1, [r2, #0x80] */
/* @0x192c70 vstr s14, [r4, #388] */
/* @0x192c74 str r4, [r1, #0x17c] */
/* @0x192c78 str r1, [r4, #0x178] */
/* @0x192c7c str r4, [r2, #0x80] */
/* @0x192c80 str r3, [r4, #0x17c] */
/* @0x192c84 pop {r4, pc} */
/* @0x192c88 ldr r1, [r3, #0x178] */
/* @0x192c8c cmp r1, #0 */
/* @0x192c90 streq r3, [r4, #0x17c] */
/* @0x192c94 strne r1, [r4, #0x178] */
/* @0x192c98 ldrne r2, [r3, #0x178] */
/* @0x192c9c streq r4, [r3, #0x178] */
/* @0x192ca0 strne r3, [r4, #0x17c] */
/* @0x192ca4 streq r4, [r2, #0x84] */
/* @0x192ca8 strne r4, [r2, #0x17c] */
/* @0x192cac streq r1, [r4, #0x178] */
/* @0x192cb0 strne r4, [r3, #0x178] */
/* @0x192cb4 vstr s14, [r4, #388] */
/* @0x192cb8 pop {r4, pc} */
/* @0x192cbc ldr r3, [r4, #0x180] */
/* @0x192cc0 str r4, [r2, #0x84] */
/* @0x192cc4 str r4, [r2, #0x80] */
/* @0x192cc8 str r3, [r4, #0x184] */
/* @0x192ccc pop {r4, pc} */
/* @0x192cd0 eoreq r10, r5, r12, lsl sp */

/* ── FUNC 0x192cd4 · CInstance::CreatePhysicsBody(CRoom*) · size=720 · insn=180 */
/* @0x192cd4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x192cd8 vpush {d8} */
/* @0x192cdc sub sp, sp, #528 */
/* @0x192ce0 ldr r4, [pc, #0x2b0] */
/* @0x192ce4 mov r5, r0 */
/* @0x192ce8 ldr r3, [r0, #0x80] */
/* @0x192cec mov r8, r1 */
/* @0x192cf0 ldr r4, [pc, r4] */
/* @0x192cf4 cmp r3, #0 */
/* @0x192cf8 ldr r2, [r4] */
/* @0x192cfc str r2, [sp, #0x20c] */
/* @0x192d00 beq 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c> */
/* @0x192d04 ldrb r3, [r3, #0x1c] */
/* @0x192d08 cmp r3, #0 */
/* @0x192d0c bne 0x192d2c <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x58> */
/* @0x192d10 ldr r2, [sp, #0x20c] */
/* @0x192d14 ldr r3, [r4] */
/* @0x192d18 cmp r2, r3 */
/* @0x192d1c bne 0x192f8c <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x2b8> */
/* @0x192d20 add sp, sp, #528 */
/* @0x192d24 vpop {d8} */
/* @0x192d28 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x192d2c ldr r0, [r0, #0x8c] */
/* @0x192d30 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x192d34 cmp r0, #0 */
/* @0x192d38 beq 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c> */
/* @0x192d3c ldr r3, [r8, #0xb4] */
/* @0x192d40 cmp r3, #0 */
/* @0x192d44 beq 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c> */
/* @0x192d48 ldr r6, [r5, #0x80] */
/* @0x192d4c vldr s16, [r3, #96] */
/* @0x192d50 bl 0x2364d4 <_ZN22CPhysicsFixtureFactory13CreateFixtureEv> */
/* @0x192d54 ldr r9, [r6, #0x20] */
/* @0x192d58 cmp r9, #0 */
/* @0x192d5c mov r7, r0 */
/* @0x192d60 beq 0x192e74 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1a0> */
/* @0x192d64 blt 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120> */
/* @0x192d68 cmp r9, #2 */
/* @0x192d6c bgt 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120> */
/* @0x192d70 bl 0x2368f8 <_ZN15CPhysicsFixture15SetPolygonShapeEv> */
/* @0x192d74 vldr s15, [r5, #152] */
/* @0x192d78 vldr s14, [r5, #156] */
/* @0x192d7c vmul.f32 s13, s15, s14 */
/* @0x192d80 vcmpe.f32 s13, #0 */
/* @0x192d84 vmrs APSR_nzcv, fpscr */
/* @0x192d88 bmi 0x192f00 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x22c> */
/* @0x192d8c ldr r3, [r6, #0x40] */
/* @0x192d90 cmp r3, #0 */
/* @0x192d94 movgt r10, #4 */
/* @0x192d98 movgt r9, #0 */
/* @0x192d9c bgt 0x192dac <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0xd8> */
/* @0x192da0 b 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120> */
/* @0x192da4 vldr s15, [r5, #152] */
/* @0x192da8 vldr s14, [r5, #156] */
/* @0x192dac ldr r3, [r6, #0x44] */
/* @0x192db0 mov r0, r7 */
/* @0x192db4 add r2, r3, r9, lsl #3 */
/* @0x192db8 add r3, r3, r10 */
/* @0x192dbc vldr s12, [r2] */
/* @0x192dc0 vldr s13, [r3] */
/* @0x192dc4 vmul.f32 s12, s16, s12 */
/* @0x192dc8 add r9, r9, #1 */
/* @0x192dcc add r10, r10, #8 */
/* @0x192dd0 vmul.f32 s13, s16, s13 */
/* @0x192dd4 vmul.f32 s12, s12, s15 */
/* @0x192dd8 vmul.f32 s13, s13, s14 */
/* @0x192ddc vmov r1, s12 */
/* @0x192de0 vmov r2, s13 */
/* @0x192de4 bl 0x236ac8 <_ZN15CPhysicsFixture13AddShapePointEff> */
/* @0x192de8 ldr r3, [r6, #0x40] */
/* @0x192dec cmp r3, r9 */
/* @0x192df0 bgt 0x192da4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0xd0> */
/* @0x192df4 vldr s16, [pc, #404] */
/* @0x192df8 vmov.f32 s17, s16 */
/* @0x192dfc ldr r2, [r6, #0x34] */
/* @0x192e00 ldrb r0, [r6, #0x1d] */
/* @0x192e04 ldr r3, [r7, #0x20] */
/* @0x192e08 str r2, [r7, #0x4] */
/* @0x192e0c ldr r12, [r6, #0x30] */
/* @0x192e10 ldr r1, [r6, #0x24] */
/* @0x192e14 ldrb r2, [r6, #0x3c] */
/* @0x192e18 str r12, [r7] */
/* @0x192e1c strb r0, [r3, #0x14] */
/* @0x192e20 ldr r0, [r6, #0x28] */
/* @0x192e24 strh r1, [r3, #32] */
/* @0x192e28 ldr r1, [r6, #0x38] */
/* @0x192e2c str r0, [r3, #0x10] */
/* @0x192e30 ldr r0, [r6, #0x2c] */
/* @0x192e34 str r1, [r3, #0x8] */
/* @0x192e38 mov r1, r7 */
/* @0x192e3c str r0, [r3, #0xc] */
/* @0x192e40 strb r2, [r7, #0x8] */
/* @0x192e44 mov r2, r5 */
/* @0x192e48 ldrb r3, [r6, #0x3d] */
/* @0x192e4c cmp r3, #0 */
/* @0x192e50 movne r3, #1 */
/* @0x192e54 strbne r3, [r7, #0x18] */
/* @0x192e58 vmov r3, s17 */
/* @0x192e5c ldr r0, [r8, #0xb4] */
/* @0x192e60 vstr s16, [sp] */
/* @0x192e64 bl 0x23894c <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff> */
/* @0x192e68 ldr r0, [r7, #0x1c] */
/* @0x192e6c bl 0x236648 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj> */
/* @0x192e70 b 0x192d10 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x3c> */
/* @0x192e74 ldr r3, [r6, #0x40] */
/* @0x192e78 cmp r3, #1 */
/* @0x192e7c ble 0x192f60 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x28c> */
/* @0x192e80 vldr s15, [r5, #152] */
/* @0x192e84 vldr s13, [r5, #156] */
/* @0x192e88 vsub.f32 s13, s15, s13 */
/* @0x192e8c vldr s14, [pc, #256] */
/* @0x192e90 vabs.f32 s13, s13 */
/* @0x192e94 vcmpe.f32 s13, s14 */
/* @0x192e98 vmrs APSR_nzcv, fpscr */
/* @0x192e9c bpl 0x192ed0 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1fc> */
/* @0x192ea0 ldr r3, [r6, #0x44] */
/* @0x192ea4 vldr s13, [r3, #8] */
/* @0x192ea8 vmul.f32 s16, s16, s13 */
/* @0x192eac mov r0, r7 */
/* @0x192eb0 vldr s17, [r3] */
/* @0x192eb4 vldr s14, [r3, #4] */
/* @0x192eb8 vmul.f32 s16, s16, s15 */
/* @0x192ebc vmov r1, s16 */
/* @0x192ec0 vnmul.f32 s17, s17, s15 */
/* @0x192ec4 vnmul.f32 s16, s14, s15 */
/* @0x192ec8 bl 0x236788 <_ZN15CPhysicsFixture14SetCircleShapeEf> */
/* @0x192ecc b 0x192dfc <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x128> */
/* @0x192ed0 ldr r3, [r5, #0x80] */
/* @0x192ed4 add r9, sp, #12 */
/* @0x192ed8 ldr r1, [pc, #0xbc] */
/* @0x192edc mov r0, r9 */
/* @0x192ee0 add r1, pc, r1 */
/* @0x192ee4 ldr r2, [r3, #0x14] */
/* @0x192ee8 bl 0xb6550 <sprintf@plt> */
/* @0x192eec mov r0, r9 */
/* @0x192ef0 mov r1, #0 */
/* @0x192ef4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x192ef8 vmov.f32 s15, #1.000000e+00 */
/* @0x192efc b 0x192ea0 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1cc> */
/* @0x192f00 ldr r9, [r6, #0x40] */
/* @0x192f04 subs r9, r9, #1 */
/* @0x192f08 bmi 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120> */
/* @0x192f0c lsl r10, r9, #3 */
/* @0x192f10 b 0x192f1c <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x248> */
/* @0x192f14 vldr s15, [r5, #152] */
/* @0x192f18 vldr s14, [r5, #156] */
/* @0x192f1c ldr r3, [r6, #0x44] */
/* @0x192f20 sub r9, r9, #1 */
/* @0x192f24 mov r0, r7 */
/* @0x192f28 add r3, r3, r10 */
/* @0x192f2c vldr s12, [r3] */
/* @0x192f30 vldr s13, [r3, #4] */
/* @0x192f34 vmul.f32 s12, s16, s12 */
/* @0x192f38 sub r10, r10, #8 */
/* @0x192f3c vmul.f32 s13, s16, s13 */
/* @0x192f40 vmul.f32 s12, s12, s15 */
/* @0x192f44 vmul.f32 s13, s13, s14 */
/* @0x192f48 vmov r1, s12 */
/* @0x192f4c vmov r2, s13 */
/* @0x192f50 bl 0x236ac8 <_ZN15CPhysicsFixture13AddShapePointEff> */
/* @0x192f54 cmn r9, #1 */
/* @0x192f58 bne 0x192f14 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x240> */
/* @0x192f5c b 0x192df4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x120> */
/* @0x192f60 ldr r3, [r5, #0x80] */
/* @0x192f64 add r10, sp, #12 */
/* @0x192f68 ldr r1, [pc, #0x30] */
/* @0x192f6c mov r0, r10 */
/* @0x192f70 add r1, pc, r1 */
/* @0x192f74 ldr r2, [r3, #0x14] */
/* @0x192f78 bl 0xb6550 <sprintf@plt> */
/* @0x192f7c mov r0, r10 */
/* @0x192f80 mov r1, r9 */
/* @0x192f84 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x192f88 b 0x192e80 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom+0x1ac> */
/* @0x192f8c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x192f90 andeq r0, r0, r0 */
/* @0x192f94 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x192f98 eoreq r10, r5, r0, ror #24 */
/* @0x192f9c andseq r9, r11, r12, lsr #14 */
/* @0x192fa0 andseq r9, r11, r0, lsl #13 */

/* ── FUNC 0x192fa4 · CInstance::RebuildPhysicsBody(CRoom*) · size=72 · insn=18 */
/* @0x192fa4 push {r3, r4, r5, lr} */
/* @0x192fa8 mov r5, r1 */
/* @0x192fac ldr r1, [r0, #0x84] */
/* @0x192fb0 mov r4, r0 */
/* @0x192fb4 cmp r1, #0 */
/* @0x192fb8 beq 0x192fcc <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom+0x28> */
/* @0x192fbc ldr r0, [r5, #0xb4] */
/* @0x192fc0 bl 0x238c08 <_ZN13CPhysicsWorld11DestroyBodyEP14CPhysicsObject> */
/* @0x192fc4 mov r3, #0 */
/* @0x192fc8 str r3, [r4, #0x84] */
/* @0x192fcc ldr r3, [r4, #0x80] */
/* @0x192fd0 ldrb r3, [r3, #0x1c] */
/* @0x192fd4 cmp r3, #0 */
/* @0x192fd8 popeq {r3, r4, r5, pc} */
/* @0x192fdc mov r0, r4 */
/* @0x192fe0 mov r1, r5 */
/* @0x192fe4 pop {r3, r4, r5, lr} */
/* @0x192fe8 b 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */

/* ── FUNC 0x192fec · CInstance::SetImageScaleX(float) · size=40 · insn=10 */
/* @0x192fec vmov s15, r1 */
/* @0x192ff0 vldr s14, [r0, #152] */
/* @0x192ff4 mov r3, r0 */
/* @0x192ff8 vcmp.f32 s14, s15 */
/* @0x192ffc vmrs APSR_nzcv, fpscr */
/* @0x193000 bxeq lr */
/* @0x193004 str r1, [r3, #0x98] */
/* @0x193008 mov r2, #1 */
/* @0x19300c strb r2, [r0, #0x64] */
/* @0x193010 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */

/* ── FUNC 0x193014 · CInstance::SetImageScaleY(float) · size=40 · insn=10 */
/* @0x193014 vmov s15, r1 */
/* @0x193018 vldr s14, [r0, #156] */
/* @0x19301c mov r3, r0 */
/* @0x193020 vcmp.f32 s14, s15 */
/* @0x193024 vmrs APSR_nzcv, fpscr */
/* @0x193028 bxeq lr */
/* @0x19302c str r1, [r3, #0x9c] */
/* @0x193030 mov r2, #1 */
/* @0x193034 strb r2, [r0, #0x64] */
/* @0x193038 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */

/* ── FUNC 0x19303c · CInstance::SetImageAngle(float) · size=40 · insn=10 */
/* @0x19303c vmov s15, r1 */
/* @0x193040 vldr s14, [r0, #160] */
/* @0x193044 mov r3, r0 */
/* @0x193048 vcmp.f32 s14, s15 */
/* @0x19304c vmrs APSR_nzcv, fpscr */
/* @0x193050 bxeq lr */
/* @0x193054 str r1, [r3, #0xa0] */
/* @0x193058 mov r2, #1 */
/* @0x19305c strb r2, [r0, #0x64] */
/* @0x193060 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */

/* ── FUNC 0x193064 · CInstance::SetDirection(float) · size=112 · insn=28 */
/* @0x193064 vmov s15, r1 */
/* @0x193068 push {r4, lr} */
/* @0x19306c vcmpe.f32 s15, #0 */
/* @0x193070 mov r4, r0 */
/* @0x193074 vmrs APSR_nzcv, fpscr */
/* @0x193078 bpl 0x193090 <_ZN9CInstance12SetDirectionEf+0x2c> */
/* @0x19307c vldr s14, [pc, #76] */
/* @0x193080 vadd.f32 s15, s15, s14 */
/* @0x193084 vcmpe.f32 s15, #0 */
/* @0x193088 vmrs APSR_nzcv, fpscr */
/* @0x19308c bmi 0x193080 <_ZN9CInstance12SetDirectionEf+0x1c> */
/* @0x193090 vldr s14, [pc, #56] */
/* @0x193094 vcmpe.f32 s15, s14 */
/* @0x193098 vmrs APSR_nzcv, fpscr */
/* @0x19309c ble 0x1930b0 <_ZN9CInstance12SetDirectionEf+0x4c> */
/* @0x1930a0 vsub.f32 s15, s15, s14 */
/* @0x1930a4 vcmpe.f32 s15, s14 */
/* @0x1930a8 vmrs APSR_nzcv, fpscr */
/* @0x1930ac bgt 0x1930a0 <_ZN9CInstance12SetDirectionEf+0x3c> */
/* @0x1930b0 vmov r0, s15 */
/* @0x1930b4 mov r1, #0 */
/* @0x1930b8 movt r1, #0x43b4 */
/* @0x1930bc bl 0xb6790 <fmodf@plt> */
/* @0x1930c0 str r0, [r4, #0xcc] */
/* @0x1930c4 mov r0, r4 */
/* @0x1930c8 pop {r4, lr} */
/* @0x1930cc b 0x192aa0 <_ZN9CInstance14Compute_Speed2Ev> */
/* @0x1930d0 .word 0x43b40000 */

/* ── FUNC 0x1930d4 · CInstance::SetSpeed(float) · size=32 · insn=8 */
/* @0x1930d4 vmov s15, r1 */
/* @0x1930d8 vldr s14, [r0, #208] */
/* @0x1930dc mov r3, r0 */
/* @0x1930e0 vcmp.f32 s14, s15 */
/* @0x1930e4 vmrs APSR_nzcv, fpscr */
/* @0x1930e8 bxeq lr */
/* @0x1930ec str r1, [r3, #0xd0] */
/* @0x1930f0 b 0x192aa0 <_ZN9CInstance14Compute_Speed2Ev> */

/* ── FUNC 0x1930f4 · CInstance::SetHspeed(float) · size=32 · insn=8 */
/* @0x1930f4 vmov s15, r1 */
/* @0x1930f8 vldr s14, [r0, #224] */
/* @0x1930fc mov r3, r0 */
/* @0x193100 vcmp.f32 s14, s15 */
/* @0x193104 vmrs APSR_nzcv, fpscr */
/* @0x193108 bxeq lr */
/* @0x19310c str r1, [r3, #0xe0] */
/* @0x193110 b 0x1928d8 <_ZN9CInstance14Compute_Speed1Ev> */

/* ── FUNC 0x193114 · CInstance::SetVspeed(float) · size=32 · insn=8 */
/* @0x193114 vmov s15, r1 */
/* @0x193118 vldr s14, [r0, #228] */
/* @0x19311c mov r3, r0 */
/* @0x193120 vcmp.f32 s14, s15 */
/* @0x193124 vmrs APSR_nzcv, fpscr */
/* @0x193128 bxeq lr */
/* @0x19312c str r1, [r3, #0xe4] */
/* @0x193130 b 0x1928d8 <_ZN9CInstance14Compute_Speed1Ev> */

/* ── FUNC 0x193134 · CInstance::GetTimer(int) · size=20 · insn=5 */
/* @0x193134 cmp r1, #11 */
/* @0x193138 addls r1, r1, #62 */
/* @0x19313c ldrls r0, [r0, r1, lsl #2] */
/* @0x193140 mvnhi r0, #0 */
/* @0x193144 bx lr */

/* ── FUNC 0x193148 · CInstance::SetTimer(int, int) · size=16 · insn=4 */
/* @0x193148 cmp r1, #11 */
/* @0x19314c addls r1, r1, #62 */
/* @0x193150 strls r2, [r0, r1, lsl #2] */
/* @0x193154 bx lr */

/* ── FUNC 0x193158 · CInstance::SkeletonAnimation() · size=104 · insn=26 */
/* @0x193158 push {r4, r5, r6, lr} */
/* @0x19315c mov r4, r0 */
/* @0x193160 ldr r0, [r0, #0x8c] */
/* @0x193164 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x193168 cmp r0, #0 */
/* @0x19316c bne 0x193178 <_ZN9CInstance17SkeletonAnimationEv+0x20> */
/* @0x193170 ldr r0, [r4, #0x88] */
/* @0x193174 pop {r4, r5, r6, pc} */
/* @0x193178 ldr r0, [r4, #0x8c] */
/* @0x19317c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x193180 ldr r3, [r0, #0x74] */
/* @0x193184 mov r5, r0 */
/* @0x193188 ldr r0, [r4, #0x88] */
/* @0x19318c cmp r3, #2 */
/* @0x193190 beq 0x193198 <_ZN9CInstance17SkeletonAnimationEv+0x40> */
/* @0x193194 pop {r4, r5, r6, pc} */
/* @0x193198 cmp r0, #0 */
/* @0x19319c popne {r4, r5, r6, pc} */
/* @0x1931a0 mov r0, #52 */
/* @0x1931a4 bl 0x27c524 <_Znwj> */
/* @0x1931a8 ldr r1, [r5, #0x58] */
/* @0x1931ac mov r6, r0 */
/* @0x1931b0 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite> */
/* @0x1931b4 mov r0, r6 */
/* @0x1931b8 str r6, [r4, #0x88] */
/* @0x1931bc pop {r4, r5, r6, pc} */

/* ── FUNC 0x1931c0 · CInstance::SetSpriteIndex(int) · size=140 · insn=35 */
/* @0x1931c0 push {r4, r5, r6, lr} */
/* @0x1931c4 mov r4, r0 */
/* @0x1931c8 str r1, [r4, #0x8c] */
/* @0x1931cc mov r0, r1 */
/* @0x1931d0 mov r5, r1 */
/* @0x1931d4 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1931d8 cmp r0, #0 */
/* @0x1931dc moveq r5, r0 */
/* @0x1931e0 bne 0x193210 <_ZN9CInstance14SetSpriteIndexEi+0x50> */
/* @0x1931e4 vldr s15, [r4, #144] */
/* @0x1931e8 vcvt.s32.f32 s15, s15 */
/* @0x1931ec mov r0, r4 */
/* @0x1931f0 vmov r3, s15 */
/* @0x1931f4 cmp r5, r3 */
/* @0x1931f8 movle r3, #0 */
/* @0x1931fc strle r3, [r4, #0x90] */
/* @0x193200 mov r3, #1 */
/* @0x193204 strb r3, [r4, #0x64] */
/* @0x193208 pop {r4, r5, r6, lr} */
/* @0x19320c b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x193210 mov r0, r5 */
/* @0x193214 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x193218 ldr r6, [r4, #0x88] */
/* @0x19321c cmp r6, #0 */
/* @0x193220 ldr r5, [r0, #0x18] */
/* @0x193224 beq 0x193240 <_ZN9CInstance14SetSpriteIndexEi+0x80> */
/* @0x193228 mov r0, r6 */
/* @0x19322c bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */
/* @0x193230 mov r0, r6 */
/* @0x193234 bl 0x27d1d0 <_ZdlPv> */
/* @0x193238 mov r3, #0 */
/* @0x19323c str r3, [r4, #0x88] */
/* @0x193240 mov r0, r4 */
/* @0x193244 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x193248 b 0x1931e4 <_ZN9CInstance14SetSpriteIndexEi+0x24> */

/* ── FUNC 0x19324c · CInstance::SetObjectIndex(int, bool) · size=284 · insn=71 */
/* @0x19324c push {r4, r5, r6, lr} */
/* @0x193250 mov r5, r0 */
/* @0x193254 ldr r0, [r0, #0x80] */
/* @0x193258 mov r4, r1 */
/* @0x19325c mov r6, r2 */
/* @0x193260 str r1, [r5, #0x7c] */
/* @0x193264 cmp r0, #0 */
/* @0x193268 moveq r3, r1 */
/* @0x19326c beq 0x193284 <_ZN9CInstance14SetObjectIndexEib+0x38> */
/* @0x193270 mov r1, r5 */
/* @0x193274 bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */
/* @0x193278 ldr r3, [r5, #0x7c] */
/* @0x19327c mov r2, #0 */
/* @0x193280 str r2, [r5, #0x80] */
/* @0x193284 cmn r3, #1 */
/* @0x193288 moveq r3, #0 */
/* @0x19328c streq r3, [r5, #0x7c] */
/* @0x193290 ldr r3, [pc, #0xcc] */
/* @0x193294 ldr r3, [pc, r3] */
/* @0x193298 ldr r3, [r3] */
/* @0x19329c ldr r1, [r3, #0x4] */
/* @0x1932a0 ldr r3, [r3] */
/* @0x1932a4 and r1, r4, r1 */
/* @0x1932a8 ldr r3, [r3, r1, lsl #3] */
/* @0x1932ac cmp r3, #0 */
/* @0x1932b0 beq 0x1932dc <_ZN9CInstance14SetObjectIndexEib+0x90> */
/* @0x1932b4 ldr r2, [r3, #0x8] */
/* @0x1932b8 cmp r4, r2 */
/* @0x1932bc bne 0x1932d0 <_ZN9CInstance14SetObjectIndexEib+0x84> */
/* @0x1932c0 b 0x1932e8 <_ZN9CInstance14SetObjectIndexEib+0x9c> */
/* @0x1932c4 ldr r12, [r3, #0x8] */
/* @0x1932c8 cmp r4, r12 */
/* @0x1932cc beq 0x1932e8 <_ZN9CInstance14SetObjectIndexEib+0x9c> */
/* @0x1932d0 ldr r3, [r3, #0x4] */
/* @0x1932d4 cmp r3, #0 */
/* @0x1932d8 bne 0x1932c4 <_ZN9CInstance14SetObjectIndexEib+0x78> */
/* @0x1932dc mov r3, #0 */
/* @0x1932e0 str r3, [r5, #0x80] */
/* @0x1932e4 pop {r4, r5, r6, pc} */
/* @0x1932e8 ldr r3, [r3, #0xc] */
/* @0x1932ec cmp r3, #0 */
/* @0x1932f0 str r3, [r5, #0x80] */
/* @0x1932f4 popeq {r4, r5, r6, pc} */
/* @0x1932f8 cmp r6, #0 */
/* @0x1932fc bne 0x193350 <_ZN9CInstance14SetObjectIndexEib+0x104> */
/* @0x193300 vldr s14, [r3, #8] */
/* @0x193304 vcvt.f32.s32 s15, s14 */
/* @0x193308 ldr r12, [r3, #0x10] */
/* @0x19330c mov r0, r5 */
/* @0x193310 ldr r2, [r3] */
/* @0x193314 ldr r1, [r3, #0x4] */
/* @0x193318 ubfx r3, r2, #0x1, #0x1 */
/* @0x19331c str r12, [r5, #0xac] */
/* @0x193320 strb r3, [r5, #0x65] */
/* @0x193324 and r12, r2, #1 */
/* @0x193328 ubfx r2, r2, #0x2, #0x1 */
/* @0x19332c strb r12, [r5, #0x66] */
/* @0x193330 strb r2, [r5, #0x67] */
/* @0x193334 vstr s15, [r5, #384] */
/* @0x193338 bl 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi> */
/* @0x19333c mov r3, #1 */
/* @0x193340 mov r0, r5 */
/* @0x193344 strb r3, [r5, #0x64] */
/* @0x193348 pop {r4, r5, r6, lr} */
/* @0x19334c b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x193350 mov r0, r3 */
/* @0x193354 mov r1, r5 */
/* @0x193358 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */
/* @0x19335c ldr r3, [r5, #0x80] */
/* @0x193360 b 0x193300 <_ZN9CInstance14SetObjectIndexEib+0xb4> */
/* @0x193364 eoreq r10, r5, r8, lsr #19 */

/* ── FUNC 0x193368 · CInstance::ChangeObjectIndex(int) · size=532 · insn=133 */
/* @0x193368 push {r4, r5, r6, r7, lr} */
/* @0x19336c mov r4, r0 */
/* @0x193370 ldr r6, [pc, #0x1e4] */
/* @0x193374 sub sp, sp, #12 */
/* @0x193378 ldr r3, [pc, #0x1e0] */
/* @0x19337c mov r5, r1 */
/* @0x193380 add r6, pc, r6 */
/* @0x193384 ldr r7, [r6, r3] */
/* @0x193388 ldm r7, {r0, r3, r12} */
/* @0x19338c cmp r12, r3 */
/* @0x193390 beq 0x1934f8 <_ZN9CInstance17ChangeObjectIndexEi+0x190> */
/* @0x193394 str r4, [r0, r12, lsl #2] */
/* @0x193398 add r12, r12, #1 */
/* @0x19339c ldr r3, [r4, #0x168] */
/* @0x1933a0 str r12, [r7, #0x8] */
/* @0x1933a4 cmp r3, #0 */
/* @0x1933a8 str r5, [r4, #0x7c] */
/* @0x1933ac ldreq r3, [r4, #0x80] */
/* @0x1933b0 streq r3, [r4, #0x168] */
/* @0x1933b4 ldr r3, [pc, #0x1a8] */
/* @0x1933b8 ldr r3, [r6, r3] */
/* @0x1933bc ldr r3, [r3] */
/* @0x1933c0 ldr r2, [r3, #0x4] */
/* @0x1933c4 ldr r3, [r3] */
/* @0x1933c8 and r2, r5, r2 */
/* @0x1933cc ldr r3, [r3, r2, lsl #3] */
/* @0x1933d0 cmp r3, #0 */
/* @0x1933d4 bne 0x1933e8 <_ZN9CInstance17ChangeObjectIndexEi+0x80> */
/* @0x1933d8 b 0x193488 <_ZN9CInstance17ChangeObjectIndexEi+0x120> */
/* @0x1933dc ldr r3, [r3, #0x4] */
/* @0x1933e0 cmp r3, #0 */
/* @0x1933e4 beq 0x193488 <_ZN9CInstance17ChangeObjectIndexEi+0x120> */
/* @0x1933e8 ldr r2, [r3, #0x8] */
/* @0x1933ec cmp r5, r2 */
/* @0x1933f0 bne 0x1933dc <_ZN9CInstance17ChangeObjectIndexEi+0x74> */
/* @0x1933f4 ldr r3, [r3, #0xc] */
/* @0x1933f8 cmp r3, #0 */
/* @0x1933fc str r3, [r4, #0x80] */
/* @0x193400 beq 0x193490 <_ZN9CInstance17ChangeObjectIndexEi+0x128> */
/* @0x193404 ldr r1, [r3, #0x10] */
/* @0x193408 mov r0, r4 */
/* @0x19340c ldr r2, [pc, #0x154] */
/* @0x193410 str r1, [r4, #0xac] */
/* @0x193414 ldr r5, [r6, r2] */
/* @0x193418 ldr r1, [r3, #0x4] */
/* @0x19341c ldrb r2, [r5] */
/* @0x193420 cmp r2, #0 */
/* @0x193424 vldreq s14, [r3, #8] */
/* @0x193428 ldr r2, [r3] */
/* @0x19342c vcvteq.f32.s32 s15, s14 */
/* @0x193430 ubfx r3, r2, #0x1, #0x1 */
/* @0x193434 and r12, r2, #1 */
/* @0x193438 strb r3, [r4, #0x65] */
/* @0x19343c ubfx r2, r2, #0x2, #0x1 */
/* @0x193440 strb r12, [r4, #0x66] */
/* @0x193444 strb r2, [r4, #0x67] */
/* @0x193448 vstreq s15, [r4, #384] */
/* @0x19344c bl 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi> */
/* @0x193450 ldrb r3, [r5] */
/* @0x193454 cmp r3, #0 */
/* @0x193458 beq 0x193498 <_ZN9CInstance17ChangeObjectIndexEi+0x130> */
/* @0x19345c ldr r3, [pc, #0x108] */
/* @0x193460 mov r0, r4 */
/* @0x193464 ldr r3, [r6, r3] */
/* @0x193468 ldr r1, [r3] */
/* @0x19346c bl 0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> */
/* @0x193470 mov r3, #1 */
/* @0x193474 mov r0, r4 */
/* @0x193478 strb r3, [r4, #0x64] */
/* @0x19347c add sp, sp, #12 */
/* @0x193480 pop {r4, r5, r6, r7, lr} */
/* @0x193484 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x193488 mov r3, #0 */
/* @0x19348c str r3, [r4, #0x80] */
/* @0x193490 add sp, sp, #12 */
/* @0x193494 pop {r4, r5, r6, r7, pc} */
/* @0x193498 ldr r2, [pc, #0xd0] */
/* @0x19349c ldr r5, [r6, r2] */
/* @0x1934a0 ldmib r5, {r2, r12} */
/* @0x1934a4 cmp r12, r2 */
/* @0x1934a8 beq 0x193528 <_ZN9CInstance17ChangeObjectIndexEi+0x1c0> */
/* @0x1934ac ldr lr, [r5] */
/* @0x1934b0 cmp r12, #0 */
/* @0x1934b4 ble 0x1934e8 <_ZN9CInstance17ChangeObjectIndexEi+0x180> */
/* @0x1934b8 ldr r3, [lr] */
/* @0x1934bc cmp r4, r3 */
/* @0x1934c0 beq 0x19345c <_ZN9CInstance17ChangeObjectIndexEi+0xf4> */
/* @0x1934c4 mov r2, lr */
/* @0x1934c8 mov r3, #0 */
/* @0x1934cc b 0x1934dc <_ZN9CInstance17ChangeObjectIndexEi+0x174> */
/* @0x1934d0 ldr r1, [r2, #0x4]! */
/* @0x1934d4 cmp r4, r1 */
/* @0x1934d8 beq 0x19345c <_ZN9CInstance17ChangeObjectIndexEi+0xf4> */
/* @0x1934dc add r3, r3, #1 */
/* @0x1934e0 cmp r3, r12 */
/* @0x1934e4 bne 0x1934d0 <_ZN9CInstance17ChangeObjectIndexEi+0x168> */
/* @0x1934e8 str r4, [lr, r12, lsl #2] */
/* @0x1934ec add r12, r12, #1 */
/* @0x1934f0 str r12, [r5, #0x8] */
/* @0x1934f4 b 0x19345c <_ZN9CInstance17ChangeObjectIndexEi+0xf4> */
/* @0x1934f8 ldr r2, [pc, #0x74] */
/* @0x1934fc mov r3, #0 */
/* @0x193500 lsl r1, r12, #3 */
/* @0x193504 str r3, [sp] */
/* @0x193508 lsl r12, r12, #1 */
/* @0x19350c add r2, pc, r2 */
/* @0x193510 str r12, [r7, #0x4] */
/* @0x193514 mov r3, #74 */
/* @0x193518 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x19351c ldr r12, [r7, #0x8] */
/* @0x193520 str r0, [r7] */
/* @0x193524 b 0x193394 <_ZN9CInstance17ChangeObjectIndexEi+0x2c> */
/* @0x193528 ldr r2, [pc, #0x48] */
/* @0x19352c lsl r1, r12, #3 */
/* @0x193530 ldr r0, [r5] */
/* @0x193534 lsl r12, r12, #1 */
/* @0x193538 str r3, [sp] */
/* @0x19353c add r2, pc, r2 */
/* @0x193540 str r12, [r5, #0x4] */
/* @0x193544 mov r3, #74 */
/* @0x193548 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x19354c ldr r12, [r5, #0x8] */
/* @0x193550 mov lr, r0 */
/* @0x193554 str r0, [r5] */
/* @0x193558 b 0x1934b0 <_ZN9CInstance17ChangeObjectIndexEi+0x148> */
/* @0x19355c .word 0x0025e8d0 */
/* @0x193560 .word 0xffffbff0 */
/* @0x193564 .word 0xffffbfec */
/* @0x193568 .word 0xffffbcd4 */
/* @0x19356c .word 0xffffbcd8 */
/* @0x193570 .word 0xffffc454 */
/* @0x193574 andseq sp, r9, r4, lsr #22 */
/* @0x193578 ldrsheq sp, [r9], -r4 */

/* ── FUNC 0x19357c · CInstance::GetImageNumber() · size=72 · insn=18 */
/* @0x19357c push {r4, lr} */
/* @0x193580 mov r4, r0 */
/* @0x193584 ldr r0, [r0, #0x8c] */
/* @0x193588 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x19358c cmp r0, #0 */
/* @0x193590 popeq {r4, pc} */
/* @0x193594 ldr r0, [r4, #0x8c] */
/* @0x193598 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x19359c ldr r3, [r0, #0x74] */
/* @0x1935a0 cmp r3, #2 */
/* @0x1935a4 beq 0x1935b0 <_ZN9CInstance14GetImageNumberEv+0x34> */
/* @0x1935a8 ldr r0, [r0, #0x18] */
/* @0x1935ac pop {r4, pc} */
/* @0x1935b0 mov r0, r4 */
/* @0x1935b4 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1935b8 mov r1, #0 */
/* @0x1935bc pop {r4, lr} */
/* @0x1935c0 b 0xbe220 <_ZN17CSkeletonInstance10FrameCountEi> */

/* ── FUNC 0x1935c4 · CInstance::SetPathPosition(float) · size=56 · insn=14 */
/* @0x1935c4 vmov s15, r1 */
/* @0x1935c8 vcmpe.f32 s15, #0 */
/* @0x1935cc vmrs APSR_nzcv, fpscr */
/* @0x1935d0 bmi 0x1935ec <_ZN9CInstance15SetPathPositionEf+0x28> */
/* @0x1935d4 vmov.f32 s14, #1.000000e+00 */
/* @0x1935d8 vcmp.f32 s15, s14 */
/* @0x1935dc vmrs APSR_nzcv, fpscr */
/* @0x1935e0 vmovgt.f32 s15, s14 */
/* @0x1935e4 vstr s15, [r0, #300] */
/* @0x1935e8 bx lr */
/* @0x1935ec vldr s15, [pc, #4] */
/* @0x1935f0 vstr s15, [r0, #300] */
/* @0x1935f4 bx lr */
/* @0x1935f8 andeq r0, r0, r0 */

/* ── FUNC 0x1935fc · CInstance::SetPathPositionPrevious(float) · size=56 · insn=14 */
/* @0x1935fc vmov s15, r1 */
/* @0x193600 vcmpe.f32 s15, #0 */
/* @0x193604 vmrs APSR_nzcv, fpscr */
/* @0x193608 bmi 0x193624 <_ZN9CInstance23SetPathPositionPreviousEf+0x28> */
/* @0x19360c vmov.f32 s14, #1.000000e+00 */
/* @0x193610 vcmp.f32 s15, s14 */
/* @0x193614 vmrs APSR_nzcv, fpscr */
/* @0x193618 vmovgt.f32 s15, s14 */
/* @0x19361c vstr s15, [r0, #304] */
/* @0x193620 bx lr */
/* @0x193624 vldr s15, [pc, #4] */
/* @0x193628 vstr s15, [r0, #304] */
/* @0x19362c bx lr */
/* @0x193630 andeq r0, r0, r0 */

/* ── FUNC 0x193634 · CInstance::SetPathSpeed(float) · size=8 · insn=2 */
/* @0x193634 str r1, [r0, #0x134] */
/* @0x193638 bx lr */

/* ── FUNC 0x19363c · CInstance::Dump(tagIConsole&) · size=2112 · insn=528 */
/* @0x19363c ldr r3, [r1] */
/* @0x193640 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x193644 mov r10, r1 */
/* @0x193648 mov r6, r0 */
/* @0x19364c mov r0, r1 */
/* @0x193650 ldr r1, [pc, #0x754] */
/* @0x193654 mov r5, r6 */
/* @0x193658 ldr r2, [r6, #0x78] */
/* @0x19365c mov r4, #0 */
/* @0x193660 add r1, pc, r1 */
/* @0x193664 ldr r3, [r3, #0xc] */
/* @0x193668 blx r3 */
/* @0x19366c ldr r8, [r6, #0x8c] */
/* @0x193670 ldr r3, [r10] */
/* @0x193674 ldr r7, [pc, #0x734] */
/* @0x193678 mov r0, r8 */
/* @0x19367c ldr r9, [r3, #0xc] */
/* @0x193680 bl 0x1eeee0 <_Z11Sprite_Namei> */
/* @0x193684 ldr r1, [pc, #0x728] */
/* @0x193688 mov r2, r8 */
/* @0x19368c add r7, pc, r7 */
/* @0x193690 add r1, pc, r1 */
/* @0x193694 mov r3, r0 */
/* @0x193698 mov r0, r10 */
/* @0x19369c blx r9 */
/* @0x1936a0 vldr s15, [r6, #144] */
/* @0x1936a4 vcvt.f64.f32 d6, s15 */
/* @0x1936a8 ldr r12, [r10] */
/* @0x1936ac ldr r1, [pc, #0x704] */
/* @0x1936b0 mov r0, r10 */
/* @0x1936b4 add r1, pc, r1 */
/* @0x1936b8 ldr r12, [r12, #0xc] */
/* @0x1936bc vmov r2, r3, d6 */
/* @0x1936c0 blx r12 */
/* @0x1936c4 vldr s15, [r6, #148] */
/* @0x1936c8 vcvt.f64.f32 d6, s15 */
/* @0x1936cc ldr r3, [r10] */
/* @0x1936d0 ldr r1, [pc, #0x6e4] */
/* @0x1936d4 mov r0, r10 */
/* @0x1936d8 ldr r12, [r3, #0xc] */
/* @0x1936dc add r1, pc, r1 */
/* @0x1936e0 vmov r2, r3, d6 */
/* @0x1936e4 blx r12 */
/* @0x1936e8 vldr s15, [r6, #152] */
/* @0x1936ec vcvt.f64.f32 d6, s15 */
/* @0x1936f0 ldr r3, [r10] */
/* @0x1936f4 ldr r1, [pc, #0x6c4] */
/* @0x1936f8 mov r0, r10 */
/* @0x1936fc ldr r12, [r3, #0xc] */
/* @0x193700 add r1, pc, r1 */
/* @0x193704 vmov r2, r3, d6 */
/* @0x193708 blx r12 */
/* @0x19370c vldr s15, [r6, #156] */
/* @0x193710 vcvt.f64.f32 d6, s15 */
/* @0x193714 ldr r3, [r10] */
/* @0x193718 ldr r1, [pc, #0x6a4] */
/* @0x19371c mov r0, r10 */
/* @0x193720 ldr r12, [r3, #0xc] */
/* @0x193724 add r1, pc, r1 */
/* @0x193728 vmov r2, r3, d6 */
/* @0x19372c blx r12 */
/* @0x193730 vldr s15, [r6, #160] */
/* @0x193734 vcvt.f64.f32 d6, s15 */
/* @0x193738 ldr r3, [r10] */
/* @0x19373c ldr r1, [pc, #0x684] */
/* @0x193740 mov r0, r10 */
/* @0x193744 ldr r12, [r3, #0xc] */
/* @0x193748 add r1, pc, r1 */
/* @0x19374c vmov r2, r3, d6 */
/* @0x193750 blx r12 */
/* @0x193754 vldr s15, [r6, #164] */
/* @0x193758 vcvt.f64.f32 d6, s15 */
/* @0x19375c ldr r3, [r10] */
/* @0x193760 ldr r1, [pc, #0x664] */
/* @0x193764 mov r0, r10 */
/* @0x193768 ldr r12, [r3, #0xc] */
/* @0x19376c add r1, pc, r1 */
/* @0x193770 vmov r2, r3, d6 */
/* @0x193774 blx r12 */
/* @0x193778 ldr r3, [r10] */
/* @0x19377c ldr r1, [pc, #0x64c] */
/* @0x193780 mov r0, r10 */
/* @0x193784 ldr r2, [r6, #0xa8] */
/* @0x193788 add r1, pc, r1 */
/* @0x19378c ldr r3, [r3, #0xc] */
/* @0x193790 blx r3 */
/* @0x193794 ldr r3, [r10] */
/* @0x193798 ldr r1, [pc, #0x634] */
/* @0x19379c mov r0, r10 */
/* @0x1937a0 ldr r2, [r6, #0xac] */
/* @0x1937a4 add r1, pc, r1 */
/* @0x1937a8 ldr r3, [r3, #0xc] */
/* @0x1937ac blx r3 */
/* @0x1937b0 vldr s15, [r6, #384] */
/* @0x1937b4 vcvt.f64.f32 d6, s15 */
/* @0x1937b8 ldr r12, [r10] */
/* @0x1937bc ldr r1, [pc, #0x614] */
/* @0x1937c0 mov r0, r10 */
/* @0x1937c4 ldr r12, [r12, #0xc] */
/* @0x1937c8 add r1, pc, r1 */
/* @0x1937cc vmov r2, r3, d6 */
/* @0x1937d0 blx r12 */
/* @0x1937d4 ldr r3, [r10] */
/* @0x1937d8 ldr r1, [pc, #0x5fc] */
/* @0x1937dc mov r0, r10 */
/* @0x1937e0 ldrb r2, [r6, #0xb0] */
/* @0x1937e4 add r1, pc, r1 */
/* @0x1937e8 ldr r3, [r3, #0xc] */
/* @0x1937ec blx r3 */
/* @0x1937f0 vldr s15, [r6, #180] */
/* @0x1937f4 vcvt.f64.f32 d6, s15 */
/* @0x1937f8 ldr r12, [r10] */
/* @0x1937fc ldr r1, [pc, #0x5dc] */
/* @0x193800 mov r0, r10 */
/* @0x193804 add r1, pc, r1 */
/* @0x193808 ldr r12, [r12, #0xc] */
/* @0x19380c vmov r2, r3, d6 */
/* @0x193810 blx r12 */
/* @0x193814 vldr s15, [r6, #184] */
/* @0x193818 vcvt.f64.f32 d6, s15 */
/* @0x19381c ldr r3, [r10] */
/* @0x193820 ldr r1, [pc, #0x5bc] */
/* @0x193824 mov r0, r10 */
/* @0x193828 ldr r12, [r3, #0xc] */
/* @0x19382c add r1, pc, r1 */
/* @0x193830 vmov r2, r3, d6 */
/* @0x193834 blx r12 */
/* @0x193838 vldr s15, [r6, #188] */
/* @0x19383c vcvt.f64.f32 d6, s15 */
/* @0x193840 ldr r3, [r10] */
/* @0x193844 ldr r1, [pc, #0x59c] */
/* @0x193848 mov r0, r10 */
/* @0x19384c ldr r12, [r3, #0xc] */
/* @0x193850 add r1, pc, r1 */
/* @0x193854 vmov r2, r3, d6 */
/* @0x193858 blx r12 */
/* @0x19385c vldr s15, [r6, #192] */
/* @0x193860 vcvt.f64.f32 d6, s15 */
/* @0x193864 ldr r3, [r10] */
/* @0x193868 ldr r1, [pc, #0x57c] */
/* @0x19386c mov r0, r10 */
/* @0x193870 ldr r12, [r3, #0xc] */
/* @0x193874 add r1, pc, r1 */
/* @0x193878 vmov r2, r3, d6 */
/* @0x19387c blx r12 */
/* @0x193880 vldr s15, [r6, #196] */
/* @0x193884 vcvt.f64.f32 d6, s15 */
/* @0x193888 ldr r3, [r10] */
/* @0x19388c ldr r1, [pc, #0x55c] */
/* @0x193890 mov r0, r10 */
/* @0x193894 ldr r12, [r3, #0xc] */
/* @0x193898 add r1, pc, r1 */
/* @0x19389c vmov r2, r3, d6 */
/* @0x1938a0 blx r12 */
/* @0x1938a4 vldr s15, [r6, #200] */
/* @0x1938a8 vcvt.f64.f32 d6, s15 */
/* @0x1938ac ldr r3, [r10] */
/* @0x1938b0 ldr r1, [pc, #0x53c] */
/* @0x1938b4 mov r0, r10 */
/* @0x1938b8 ldr r12, [r3, #0xc] */
/* @0x1938bc add r1, pc, r1 */
/* @0x1938c0 vmov r2, r3, d6 */
/* @0x1938c4 blx r12 */
/* @0x1938c8 vldr s15, [r6, #204] */
/* @0x1938cc vcvt.f64.f32 d6, s15 */
/* @0x1938d0 ldr r3, [r10] */
/* @0x1938d4 ldr r1, [pc, #0x51c] */
/* @0x1938d8 mov r0, r10 */
/* @0x1938dc ldr r12, [r3, #0xc] */
/* @0x1938e0 add r1, pc, r1 */
/* @0x1938e4 vmov r2, r3, d6 */
/* @0x1938e8 blx r12 */
/* @0x1938ec vldr s15, [r6, #208] */
/* @0x1938f0 vcvt.f64.f32 d6, s15 */
/* @0x1938f4 ldr r3, [r10] */
/* @0x1938f8 ldr r1, [pc, #0x4fc] */
/* @0x1938fc mov r0, r10 */
/* @0x193900 ldr r12, [r3, #0xc] */
/* @0x193904 add r1, pc, r1 */
/* @0x193908 vmov r2, r3, d6 */
/* @0x19390c blx r12 */
/* @0x193910 vldr s15, [r6, #212] */
/* @0x193914 vcvt.f64.f32 d6, s15 */
/* @0x193918 ldr r3, [r10] */
/* @0x19391c ldr r1, [pc, #0x4dc] */
/* @0x193920 mov r0, r10 */
/* @0x193924 ldr r12, [r3, #0xc] */
/* @0x193928 add r1, pc, r1 */
/* @0x19392c vmov r2, r3, d6 */
/* @0x193930 blx r12 */
/* @0x193934 vldr s15, [r6, #216] */
/* @0x193938 vcvt.f64.f32 d6, s15 */
/* @0x19393c ldr r3, [r10] */
/* @0x193940 ldr r1, [pc, #0x4bc] */
/* @0x193944 mov r0, r10 */
/* @0x193948 ldr r12, [r3, #0xc] */
/* @0x19394c add r1, pc, r1 */
/* @0x193950 vmov r2, r3, d6 */
/* @0x193954 blx r12 */
/* @0x193958 vldr s15, [r6, #220] */
/* @0x19395c vcvt.f64.f32 d6, s15 */
/* @0x193960 ldr r3, [r10] */
/* @0x193964 ldr r1, [pc, #0x49c] */
/* @0x193968 mov r0, r10 */
/* @0x19396c ldr r12, [r3, #0xc] */
/* @0x193970 add r1, pc, r1 */
/* @0x193974 vmov r2, r3, d6 */
/* @0x193978 blx r12 */
/* @0x19397c vldr s15, [r6, #224] */
/* @0x193980 vcvt.f64.f32 d6, s15 */
/* @0x193984 ldr r3, [r10] */
/* @0x193988 ldr r1, [pc, #0x47c] */
/* @0x19398c mov r0, r10 */
/* @0x193990 ldr r12, [r3, #0xc] */
/* @0x193994 add r1, pc, r1 */
/* @0x193998 vmov r2, r3, d6 */
/* @0x19399c blx r12 */
/* @0x1939a0 vldr s15, [r6, #228] */
/* @0x1939a4 vcvt.f64.f32 d6, s15 */
/* @0x1939a8 ldr r3, [r10] */
/* @0x1939ac ldr r1, [pc, #0x45c] */
/* @0x1939b0 mov r0, r10 */
/* @0x1939b4 ldr r12, [r3, #0xc] */
/* @0x1939b8 add r1, pc, r1 */
/* @0x1939bc vmov r2, r3, d6 */
/* @0x1939c0 blx r12 */
/* @0x1939c4 ldr r3, [r10] */
/* @0x1939c8 ldr r1, [pc, #0x444] */
/* @0x1939cc mov r0, r10 */
/* @0x1939d0 ldr r2, [r6, #0xe8] */
/* @0x1939d4 add r1, pc, r1 */
/* @0x1939d8 ldr r3, [r3, #0xc] */
/* @0x1939dc blx r3 */
/* @0x1939e0 ldr r3, [r10] */
/* @0x1939e4 ldr r1, [pc, #0x42c] */
/* @0x1939e8 mov r0, r10 */
/* @0x1939ec ldr r2, [r6, #0xf0] */
/* @0x1939f0 add r1, pc, r1 */
/* @0x1939f4 ldr r3, [r3, #0xc] */
/* @0x1939f8 blx r3 */
/* @0x1939fc ldr r3, [r10] */
/* @0x193a00 ldr r1, [pc, #0x414] */
/* @0x193a04 mov r0, r10 */
/* @0x193a08 ldr r2, [r6, #0xec] */
/* @0x193a0c add r1, pc, r1 */
/* @0x193a10 ldr r3, [r3, #0xc] */
/* @0x193a14 blx r3 */
/* @0x193a18 ldr r3, [r10] */
/* @0x193a1c ldr r1, [pc, #0x3fc] */
/* @0x193a20 mov r0, r10 */
/* @0x193a24 ldr r2, [r6, #0xf4] */
/* @0x193a28 add r1, pc, r1 */
/* @0x193a2c ldr r3, [r3, #0xc] */
/* @0x193a30 blx r3 */
/* @0x193a34 ldr r3, [r10] */
/* @0x193a38 ldr r1, [pc, #0x3e4] */
/* @0x193a3c mov r0, r10 */
/* @0x193a40 ldrb r2, [r6, #0x65] */
/* @0x193a44 add r1, pc, r1 */
/* @0x193a48 ldr r3, [r3, #0xc] */
/* @0x193a4c blx r3 */
/* @0x193a50 ldr r3, [r10] */
/* @0x193a54 ldr r1, [pc, #0x3cc] */
/* @0x193a58 mov r0, r10 */
/* @0x193a5c ldrb r2, [r6, #0x66] */
/* @0x193a60 add r1, pc, r1 */
/* @0x193a64 ldr r3, [r3, #0xc] */
/* @0x193a68 blx r3 */
/* @0x193a6c ldr r3, [r10] */
/* @0x193a70 ldr r1, [pc, #0x3b4] */
/* @0x193a74 mov r0, r10 */
/* @0x193a78 ldrb r2, [r6, #0x67] */
/* @0x193a7c add r1, pc, r1 */
/* @0x193a80 ldr r3, [r3, #0xc] */
/* @0x193a84 blx r3 */
/* @0x193a88 ldr r8, [r6, #0x7c] */
/* @0x193a8c ldr r3, [r10] */
/* @0x193a90 mov r0, r8 */
/* @0x193a94 ldr r9, [r3, #0xc] */
/* @0x193a98 bl 0x19ed54 <_Z11Object_Namei> */
/* @0x193a9c ldr r1, [pc, #0x38c] */
/* @0x193aa0 mov r2, r8 */
/* @0x193aa4 add r1, pc, r1 */
/* @0x193aa8 mov r3, r0 */
/* @0x193aac mov r0, r10 */
/* @0x193ab0 blx r9 */
/* @0x193ab4 ldr r12, [r10] */
/* @0x193ab8 mov r2, r4 */
/* @0x193abc ldr r3, [r5, #0xf8] */
/* @0x193ac0 mov r0, r10 */
/* @0x193ac4 mov r1, r7 */
/* @0x193ac8 add r4, r4, #1 */
/* @0x193acc ldr r12, [r12, #0xc] */
/* @0x193ad0 add r5, r5, #4 */
/* @0x193ad4 blx r12 */
/* @0x193ad8 cmp r4, #12 */
/* @0x193adc bne 0x193ab4 <_ZN9CInstance4DumpER11tagIConsole+0x478> */
/* @0x193ae0 ldr r3, [r10] */
/* @0x193ae4 mov r0, r10 */
/* @0x193ae8 ldr r1, [pc, #0x344] */
/* @0x193aec ldrb r2, [r6, #0x68] */
/* @0x193af0 add r1, pc, r1 */
/* @0x193af4 ldr r3, [r3, #0xc] */
/* @0x193af8 blx r3 */
/* @0x193afc ldr r3, [r10] */
/* @0x193b00 ldr r1, [pc, #0x330] */
/* @0x193b04 mov r0, r10 */
/* @0x193b08 ldrb r2, [r6, #0x69] */
/* @0x193b0c add r1, pc, r1 */
/* @0x193b10 ldr r3, [r3, #0xc] */
/* @0x193b14 blx r3 */
/* @0x193b18 ldr r3, [r10] */
/* @0x193b1c ldr r1, [pc, #0x318] */
/* @0x193b20 mov r0, r10 */
/* @0x193b24 ldr r2, [r6, #0x128] */
/* @0x193b28 add r1, pc, r1 */
/* @0x193b2c ldr r3, [r3, #0xc] */
/* @0x193b30 blx r3 */
/* @0x193b34 vldr s15, [r6, #300] */
/* @0x193b38 vcvt.f64.f32 d6, s15 */
/* @0x193b3c ldr r12, [r10] */
/* @0x193b40 ldr r1, [pc, #0x2f8] */
/* @0x193b44 mov r0, r10 */
/* @0x193b48 add r1, pc, r1 */
/* @0x193b4c ldr r12, [r12, #0xc] */
/* @0x193b50 vmov r2, r3, d6 */
/* @0x193b54 blx r12 */
/* @0x193b58 vldr s15, [r6, #304] */
/* @0x193b5c vcvt.f64.f32 d6, s15 */
/* @0x193b60 ldr r3, [r10] */
/* @0x193b64 ldr r1, [pc, #0x2d8] */
/* @0x193b68 mov r0, r10 */
/* @0x193b6c ldr r12, [r3, #0xc] */
/* @0x193b70 add r1, pc, r1 */
/* @0x193b74 vmov r2, r3, d6 */
/* @0x193b78 blx r12 */
/* @0x193b7c vldr s15, [r6, #308] */
/* @0x193b80 vcvt.f64.f32 d6, s15 */
/* @0x193b84 ldr r3, [r10] */
/* @0x193b88 ldr r1, [pc, #0x2b8] */
/* @0x193b8c mov r0, r10 */
/* @0x193b90 ldr r12, [r3, #0xc] */
/* @0x193b94 add r1, pc, r1 */
/* @0x193b98 vmov r2, r3, d6 */
/* @0x193b9c blx r12 */
/* @0x193ba0 vldr s15, [r6, #312] */
/* @0x193ba4 vcvt.f64.f32 d6, s15 */
/* @0x193ba8 ldr r3, [r10] */
/* @0x193bac ldr r1, [pc, #0x298] */
/* @0x193bb0 mov r0, r10 */
/* @0x193bb4 ldr r12, [r3, #0xc] */
/* @0x193bb8 add r1, pc, r1 */
/* @0x193bbc vmov r2, r3, d6 */
/* @0x193bc0 blx r12 */
/* @0x193bc4 vldr s15, [r6, #316] */
/* @0x193bc8 vcvt.f64.f32 d6, s15 */
/* @0x193bcc ldr r3, [r10] */
/* @0x193bd0 ldr r1, [pc, #0x278] */
/* @0x193bd4 mov r0, r10 */
/* @0x193bd8 ldr r12, [r3, #0xc] */
/* @0x193bdc add r1, pc, r1 */
/* @0x193be0 vmov r2, r3, d6 */
/* @0x193be4 blx r12 */
/* @0x193be8 ldr r3, [r10] */
/* @0x193bec ldr r1, [pc, #0x260] */
/* @0x193bf0 mov r0, r10 */
/* @0x193bf4 ldr r2, [r6, #0x140] */
/* @0x193bf8 add r1, pc, r1 */
/* @0x193bfc ldr r3, [r3, #0xc] */
/* @0x193c00 blx r3 */
/* @0x193c04 vldr s15, [r6, #324] */
/* @0x193c08 vcvt.f64.f32 d6, s15 */
/* @0x193c0c ldr r12, [r10] */
/* @0x193c10 ldr r1, [pc, #0x240] */
/* @0x193c14 mov r0, r10 */
/* @0x193c18 add r1, pc, r1 */
/* @0x193c1c ldr r12, [r12, #0xc] */
/* @0x193c20 vmov r2, r3, d6 */
/* @0x193c24 blx r12 */
/* @0x193c28 vldr s15, [r6, #328] */
/* @0x193c2c vcvt.f64.f32 d6, s15 */
/* @0x193c30 ldr r3, [r10] */
/* @0x193c34 ldr r1, [pc, #0x220] */
/* @0x193c38 mov r0, r10 */
/* @0x193c3c ldr r12, [r3, #0xc] */
/* @0x193c40 add r1, pc, r1 */
/* @0x193c44 vmov r2, r3, d6 */
/* @0x193c48 blx r12 */
/* @0x193c4c ldr r3, [r10] */
/* @0x193c50 ldr r1, [pc, #0x208] */
/* @0x193c54 mov r0, r10 */
/* @0x193c58 ldr r2, [r6, #0x14c] */
/* @0x193c5c add r1, pc, r1 */
/* @0x193c60 ldr r3, [r3, #0xc] */
/* @0x193c64 blx r3 */
/* @0x193c68 vldr s15, [r6, #340] */
/* @0x193c6c vcvt.f64.f32 d6, s15 */
/* @0x193c70 ldr r12, [r10] */
/* @0x193c74 ldr r1, [pc, #0x1e8] */
/* @0x193c78 mov r0, r10 */
/* @0x193c7c add r1, pc, r1 */
/* @0x193c80 ldr r12, [r12, #0xc] */
/* @0x193c84 vmov r2, r3, d6 */
/* @0x193c88 blx r12 */
/* @0x193c8c vldr s15, [r6, #344] */
/* @0x193c90 vcvt.f64.f32 d6, s15 */
/* @0x193c94 ldr r3, [r10] */
/* @0x193c98 ldr r1, [pc, #0x1c8] */
/* @0x193c9c mov r0, r10 */
/* @0x193ca0 ldr r12, [r3, #0xc] */
/* @0x193ca4 add r1, pc, r1 */
/* @0x193ca8 vmov r2, r3, d6 */
/* @0x193cac blx r12 */
/* @0x193cb0 ldr r3, [r10] */
/* @0x193cb4 ldr r1, [pc, #0x1b0] */
/* @0x193cb8 mov r0, r10 */
/* @0x193cbc ldrb r2, [r6, #0x15c] */
/* @0x193cc0 add r1, pc, r1 */
/* @0x193cc4 ldr r3, [r3, #0xc] */
/* @0x193cc8 blx r3 */
/* @0x193ccc ldr r3, [r10] */
/* @0x193cd0 ldr r1, [pc, #0x198] */
/* @0x193cd4 mov r0, r10 */
/* @0x193cd8 ldrb r2, [r6, #0x15d] */
/* @0x193cdc ldr r3, [r3, #0xc] */
/* @0x193ce0 add r1, pc, r1 */
/* @0x193ce4 blx r3 */
/* @0x193ce8 ldr r3, [r6, #0x60] */
/* @0x193cec cmp r3, #0 */
/* @0x193cf0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x193cf4 ldr r9, [pc, #0x178] */
/* @0x193cf8 mov r4, #0 */
/* @0x193cfc ldr r8, [pc, #0x174] */
/* @0x193d00 mvn r7, #-16777216 */
/* @0x193d04 ldr r1, [r3] */
/* @0x193d08 add r9, pc, r9 */
/* @0x193d0c ldr r0, [r3, #0x10] */
/* @0x193d10 add r8, pc, r8 */
/* @0x193d14 add r3, r4, r4, lsl #1 */
/* @0x193d18 add r3, r0, r3, lsl #2 */
/* @0x193d1c add r4, r4, #1 */
/* @0x193d20 mov r5, r3 */
/* @0x193d24 cmp r4, r1 */
/* @0x193d28 add r3, r3, #12 */
/* @0x193d2c popgt {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x193d30 ldr r2, [r5, #0x8] */
/* @0x193d34 cmp r2, #0 */
/* @0x193d38 ble 0x193d1c <_ZN9CInstance4DumpER11tagIConsole+0x6e0> */
/* @0x193d3c ldm r5, {r2, r3} */
/* @0x193d40 ldr r3, [r3, #0xc] */
/* @0x193d44 bic r3, r3, #-16777216 */
/* @0x193d48 cmp r3, r7 */
/* @0x193d4c beq 0x193d14 <_ZN9CInstance4DumpER11tagIConsole+0x6d8> */
/* @0x193d50 add r2, r2, #99328 */
/* @0x193d54 mvn r1, #0 */
/* @0x193d58 add r2, r2, #672 */
/* @0x193d5c mov r0, #0 */
/* @0x193d60 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x193d64 ldr r3, [r10] */
/* @0x193d68 mov r1, r9 */
/* @0x193d6c ldr r3, [r3, #0xc] */
/* @0x193d70 mov r2, r0 */
/* @0x193d74 mov r0, r10 */
/* @0x193d78 blx r3 */
/* @0x193d7c mov r0, r10 */
/* @0x193d80 ldr r1, [r5, #0x4] */
/* @0x193d84 bl 0x1f563c <_Z11OutputValueP11tagIConsoleP6RValue> */
/* @0x193d88 ldr r3, [r10] */
/* @0x193d8c mov r0, r10 */
/* @0x193d90 mov r1, r8 */
/* @0x193d94 ldr r3, [r3, #0xc] */
/* @0x193d98 blx r3 */
/* @0x193d9c ldr r3, [r6, #0x60] */
/* @0x193da0 ldr r1, [r3] */
/* @0x193da4 ldr r0, [r3, #0x10] */
/* @0x193da8 b 0x193d14 <_ZN9CInstance4DumpER11tagIConsole+0x6d8> */
/* @0x193dac andseq r9, r11, r4 */
/* @0x193db0 ldrsheq r9, [r11], -r12 */
/* @0x193db4 ldrsheq r8, [r11], -r4 */
/* @0x193db8 ldrsheq r8, [r11], -r4 */
/* @0x193dbc andseq r8, r11, r12, ror #31 */
/* @0x193dc0 andseq r8, r11, r8, ror #31 */
/* @0x193dc4 andseq r8, r11, r4, ror #31 */
/* @0x193dc8 andseq r8, r11, r0, ror #31 */
/* @0x193dcc ldrsbeq r8, [r11], -r12 */
/* @0x193dd0 andseq r8, r11, r0, ror #31 */
/* @0x193dd4 andseq r8, r11, r4, ror #31 */
/* @0x193dd8 andseq r8, r11, r0, ror #31 */
/* @0x193ddc andseq r8, r11, r4, ror #31 */
/* @0x193de0 andseq r8, r11, r4, ror #31 */
/* @0x193de4 ldrsbeq r8, [r11], -r12 */
/* @0x193de8 ldrsbeq r8, [r11], -r8 */
/* @0x193dec ldrsbeq r8, [r11], -r4 */
/* @0x193df0 ldrsbeq r8, [r11], -r0 */
/* @0x193df4 andseq r8, r11, r12, asr #31 */
/* @0x193df8 andseq r8, r11, r8, asr #31 */
/* @0x193dfc andseq r8, r11, r4, asr #31 */
/* @0x193e00 andseq r8, r11, r0, asr #31 */
/* @0x193e04 ldrheq r8, [r11], -r12 */
/* @0x193e08 ldrheq r8, [r11], -r8 */
/* @0x193e0c ldrheq r8, [r11], -r4 */
/* @0x193e10 ldrheq r8, [r11], -r0 */
/* @0x193e14 ldrheq r8, [r11], -r4 */
/* @0x193e18 ldrheq r8, [r11], -r8 */
/* @0x193e1c ldrheq r8, [r11], -r12 */
/* @0x193e20 andseq r8, r11, r0, asr #31 */
/* @0x193e24 andseq r8, r11, r4, asr #31 */
/* @0x193e28 andseq r8, r11, r8, asr #31 */
/* @0x193e2c andseq r8, r11, r12, asr #31 */
/* @0x193e30 andseq r8, r11, r4, asr #31 */
/* @0x193e34 ldrheq r8, [r11], -r4 */
/* @0x193e38 ldrheq r8, [r11], -r8 */
/* @0x193e3c ldrheq r8, [r11], -r12 */
/* @0x193e40 ldrheq r8, [r11], -r12 */
/* @0x193e44 ldrheq r8, [r11], -r4 */
/* @0x193e48 ldrheq r8, [r11], -r0 */
/* @0x193e4c andseq r8, r11, r12, lsr #31 */
/* @0x193e50 andseq r8, r11, r8, lsr #31 */
/* @0x193e54 andseq r8, r11, r12, lsr #31 */
/* @0x193e58 andseq r8, r11, r12, lsr #31 */
/* @0x193e5c andseq r8, r11, r4, lsr #31 */
/* @0x193e60 andseq r8, r11, r8, lsr #31 */
/* @0x193e64 andseq r8, r11, r8, lsr #31 */
/* @0x193e68 andseq r8, r11, r0, lsr #31 */
/* @0x193e6c andseq r8, r11, r4, lsr #31 */
/* @0x193e70 andseq r8, r11, r4, lsr #31 */
/* @0x193e74 mulseq r11, r12, pc */
/* @0x193e78 andseq lr, r9, r8, lsl #31 */

/* ── FUNC 0x193e7c · CInstance::SetPosition(float, float) · size=68 · insn=17 */
/* @0x193e7c vmov s15, r1 */
/* @0x193e80 vldr s13, [r0, #180] */
/* @0x193e84 mov r3, r0 */
/* @0x193e88 vmov s14, r2 */
/* @0x193e8c vcmp.f32 s13, s15 */
/* @0x193e90 vmrs APSR_nzcv, fpscr */
/* @0x193e94 bne 0x193ea8 <_ZN9CInstance11SetPositionEff+0x2c> */
/* @0x193e98 vldr s13, [r0, #184] */
/* @0x193e9c vcmp.f32 s13, s14 */
/* @0x193ea0 vmrs APSR_nzcv, fpscr */
/* @0x193ea4 bxeq lr */
/* @0x193ea8 mov r2, #1 */
/* @0x193eac vstr s15, [r3, #180] */
/* @0x193eb0 vstr s14, [r3, #184] */
/* @0x193eb4 mov r0, r3 */
/* @0x193eb8 strb r2, [r3, #0x64] */
/* @0x193ebc b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */

/* ── FUNC 0x193ec0 · CInstance::AddTo_Speed(float, float) · size=108 · insn=27 */
/* @0x193ec0 vmov s14, r1 */
/* @0x193ec4 vldr s15, [pc, #88] */
/* @0x193ec8 push {r4, lr} */
/* @0x193ecc vpush {d8} */
/* @0x193ed0 vldr s17, [pc, #80] */
/* @0x193ed4 vmul.f32 s17, s14, s17 */
/* @0x193ed8 mov r4, r0 */
/* @0x193edc vmov s16, r2 */
/* @0x193ee0 vdiv.f32 s17, s17, s15 */
/* @0x193ee4 vmov r0, s17 */
/* @0x193ee8 bl 0xb658c <cosf@plt> */
/* @0x193eec vldr s15, [r4, #224] */
/* @0x193ef0 vmov s14, r0 */
/* @0x193ef4 vmov r0, s17 */
/* @0x193ef8 vmla.f32 s15, s14, s16 */
/* @0x193efc vstr s15, [r4, #224] */
/* @0x193f00 bl 0xb6580 <sinf@plt> */
/* @0x193f04 vldr s15, [r4, #228] */
/* @0x193f08 vmov s14, r0 */
/* @0x193f0c mov r0, r4 */
/* @0x193f10 vmls.f32 s15, s14, s16 */
/* @0x193f14 vpop {d8} */
/* @0x193f18 vstr s15, [r4, #228] */
/* @0x193f1c pop {r4, lr} */
/* @0x193f20 b 0x1928d8 <_ZN9CInstance14Compute_Speed1Ev> */
/* @0x193f24 teqmi r4, #0 */
/* @0x193f28 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x193f2c · CInstance::Adapt_Speed() · size=180 · insn=45 */
/* @0x193f2c vldr s15, [r0, #212] */
/* @0x193f30 vcmp.f32 s15, #0 */
/* @0x193f34 push {r4, lr} */
/* @0x193f38 mov r4, r0 */
/* @0x193f3c vmrs APSR_nzcv, fpscr */
/* @0x193f40 beq 0x193f7c <_ZN9CInstance11Adapt_SpeedEv+0x50> */
/* @0x193f44 vldr s14, [r0, #208] */
/* @0x193f48 vcmpe.f32 s14, #0 */
/* @0x193f4c vmrs APSR_nzcv, fpscr */
/* @0x193f50 vsubgt.f32 s15, s14, s15 */
/* @0x193f54 ble 0x193fa0 <_ZN9CInstance11Adapt_SpeedEv+0x74> */
/* @0x193f58 vcmpe.f32 s15, #0 */
/* @0x193f5c vmrs APSR_nzcv, fpscr */
/* @0x193f60 bmi 0x193fc0 <_ZN9CInstance11Adapt_SpeedEv+0x94> */
/* @0x193f64 vcmpe.f32 s14, #0 */
/* @0x193f68 vmrs APSR_nzcv, fpscr */
/* @0x193f6c bmi 0x193fb4 <_ZN9CInstance11Adapt_SpeedEv+0x88> */
/* @0x193f70 vcmp.f32 s14, #0 */
/* @0x193f74 vmrs APSR_nzcv, fpscr */
/* @0x193f78 bne 0x193fd0 <_ZN9CInstance11Adapt_SpeedEv+0xa4> */
/* @0x193f7c vldr s15, [r4, #220] */
/* @0x193f80 vcmp.f32 s15, #0 */
/* @0x193f84 vmrs APSR_nzcv, fpscr */
/* @0x193f88 popeq {r4, pc} */
/* @0x193f8c mov r0, r4 */
/* @0x193f90 ldr r1, [r4, #0xd8] */
/* @0x193f94 vmov r2, s15 */
/* @0x193f98 pop {r4, lr} */
/* @0x193f9c b 0x193ec0 <_ZN9CInstance11AddTo_SpeedEff> */
/* @0x193fa0 vadd.f32 s15, s15, s14 */
/* @0x193fa4 bgt 0x193f58 <_ZN9CInstance11Adapt_SpeedEv+0x2c> */
/* @0x193fa8 vcmpe.f32 s14, #0 */
/* @0x193fac vmrs APSR_nzcv, fpscr */
/* @0x193fb0 bpl 0x193f70 <_ZN9CInstance11Adapt_SpeedEv+0x44> */
/* @0x193fb4 vcmpe.f32 s15, #0 */
/* @0x193fb8 vmrs APSR_nzcv, fpscr */
/* @0x193fbc ble 0x193fd0 <_ZN9CInstance11Adapt_SpeedEv+0xa4> */
/* @0x193fc0 mov r0, r4 */
/* @0x193fc4 mov r1, #0 */
/* @0x193fc8 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x193fcc b 0x193f7c <_ZN9CInstance11Adapt_SpeedEv+0x50> */
/* @0x193fd0 mov r0, r4 */
/* @0x193fd4 vmov r1, s15 */
/* @0x193fd8 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x193fdc b 0x193f7c <_ZN9CInstance11Adapt_SpeedEv+0x50> */

/* ── FUNC 0x193fe0 · CInstance::Assign_Path(int, float, float, float, bool, int) · size=316 · insn=79 */
/* @0x193fe0 cmp r1, #0 */
/* @0x193fe4 push {r4, r5, r6, lr} */
/* @0x193fe8 vpush {d8} */
/* @0x193fec mov r4, r0 */
/* @0x193ff0 str r1, [r0, #0x128] */
/* @0x193ff4 vmov s16, r2 */
/* @0x193ff8 vmov s17, r3 */
/* @0x193ffc ldrb r5, [sp, #0x1c] */
/* @0x194000 blt 0x1940c4 <_ZN9CInstance11Assign_PathEifffbi+0xe4> */
/* @0x194004 mov r0, r1 */
/* @0x194008 bl 0x1a815c <_Z9Path_Datai> */
/* @0x19400c subs r6, r0, #0 */
/* @0x194010 beq 0x1940cc <_ZN9CInstance11Assign_PathEifffbi+0xec> */
/* @0x194014 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x194018 mov r3, #0 */
/* @0x19401c vmov s15, r0 */
/* @0x194020 vcmpe.f32 s15, #0 */
/* @0x194024 vmrs APSR_nzcv, fpscr */
/* @0x194028 bls 0x1940cc <_ZN9CInstance11Assign_PathEifffbi+0xec> */
/* @0x19402c vcmpe.f32 s16, #0 */
/* @0x194030 vstr s16, [r4, #308] */
/* @0x194034 vmrs APSR_nzcv, fpscr */
/* @0x194038 strge r3, [r4, #0x12c] */
/* @0x19403c blt 0x1940f4 <_ZN9CInstance11Assign_PathEifffbi+0x114> */
/* @0x194040 vcmpe.f32 s17, #0 */
/* @0x194044 str r3, [r4, #0x130] */
/* @0x194048 vstr s17, [r4, #312] */
/* @0x19404c vmrs APSR_nzcv, fpscr */
/* @0x194050 bmi 0x1940cc <_ZN9CInstance11Assign_PathEifffbi+0xec> */
/* @0x194054 ldr r2, [sp, #0x20] */
/* @0x194058 cmp r5, #0 */
/* @0x19405c vldr s15, [sp, #24] */
/* @0x194060 vstr s15, [r4, #316] */
/* @0x194064 str r2, [r4, #0x140] */
/* @0x194068 bne 0x1940dc <_ZN9CInstance11Assign_PathEifffbi+0xfc> */
/* @0x19406c vcmpe.f32 s16, #0 */
/* @0x194070 mov r0, r6 */
/* @0x194074 vmrs APSR_nzcv, fpscr */
/* @0x194078 blt 0x194104 <_ZN9CInstance11Assign_PathEifffbi+0x124> */
/* @0x19407c mov r1, #0 */
/* @0x194080 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x194084 mov r1, #0 */
/* @0x194088 mov r5, r0 */
/* @0x19408c mov r0, r6 */
/* @0x194090 bl 0x1a75c0 <_ZN5CPath9YPositionEf> */
/* @0x194094 mov r1, r5 */
/* @0x194098 mov r2, r0 */
/* @0x19409c mov r0, r4 */
/* @0x1940a0 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1940a4 mov r1, #0 */
/* @0x1940a8 mov r0, r6 */
/* @0x1940ac bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x1940b0 mov r1, #0 */
/* @0x1940b4 str r0, [r4, #0x144] */
/* @0x1940b8 mov r0, r6 */
/* @0x1940bc bl 0x1a75c0 <_ZN5CPath9YPositionEf> */
/* @0x1940c0 str r0, [r4, #0x148] */
/* @0x1940c4 vpop {d8} */
/* @0x1940c8 pop {r4, r5, r6, pc} */
/* @0x1940cc vpop {d8} */
/* @0x1940d0 mvn r3, #0 */
/* @0x1940d4 str r3, [r4, #0x128] */
/* @0x1940d8 pop {r4, r5, r6, pc} */
/* @0x1940dc vpop {d8} */
/* @0x1940e0 ldr r2, [r4, #0xb4] */
/* @0x1940e4 ldr r3, [r4, #0xb8] */
/* @0x1940e8 str r2, [r4, #0x144] */
/* @0x1940ec str r3, [r4, #0x148] */
/* @0x1940f0 pop {r4, r5, r6, pc} */
/* @0x1940f4 mov r2, #1065353216 */
/* @0x1940f8 str r2, [r4, #0x12c] */
/* @0x1940fc mov r3, r2 */
/* @0x194100 b 0x194040 <_ZN9CInstance11Assign_PathEifffbi+0x60> */
/* @0x194104 mov r1, #1065353216 */
/* @0x194108 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x19410c mov r1, #1065353216 */
/* @0x194110 mov r5, r0 */
/* @0x194114 mov r0, r6 */
/* @0x194118 b 0x194090 <_ZN9CInstance11Assign_PathEifffbi+0xb0> */

/* ── FUNC 0x19411c · CInstance::Adapt_Path() · size=916 · insn=229 */
/* @0x19411c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x194120 vpush {d8, d9, d10, d11} */
/* @0x194124 mov r4, r0 */
/* @0x194128 ldr r0, [r0, #0x128] */
/* @0x19412c sub sp, sp, #28 */
/* @0x194130 cmp r0, #0 */
/* @0x194134 blt 0x194210 <_ZN9CInstance10Adapt_PathEv+0xf4> */
/* @0x194138 bl 0x1a815c <_Z9Path_Datai> */
/* @0x19413c subs r6, r0, #0 */
/* @0x194140 beq 0x194210 <_ZN9CInstance10Adapt_PathEv+0xf4> */
/* @0x194144 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x194148 vmov s14, r0 */
/* @0x19414c vcmpe.f32 s14, #0 */
/* @0x194150 vmrs APSR_nzcv, fpscr */
/* @0x194154 bls 0x194210 <_ZN9CInstance10Adapt_PathEv+0xf4> */
/* @0x194158 vldr s17, [r4, #316] */
/* @0x19415c vldr s15, [pc, #828] */
/* @0x194160 vmul.f32 s17, s17, s15 */
/* @0x194164 add r8, sp, #16 */
/* @0x194168 add r9, sp, #20 */
/* @0x19416c ldr r1, [r4, #0x12c] */
/* @0x194170 mov r2, r8 */
/* @0x194174 mov r0, r6 */
/* @0x194178 mov r3, r9 */
/* @0x19417c add r7, sp, #12 */
/* @0x194180 str r7, [sp] */
/* @0x194184 vldr s15, [pc, #792] */
/* @0x194188 vdiv.f32 s17, s17, s15 */
/* @0x19418c bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x194190 vldr s13, [r4, #312] */
/* @0x194194 vldr s15, [pc, #780] */
/* @0x194198 vldr s14, [sp, #12] */
/* @0x19419c mov r0, r6 */
/* @0x1941a0 vldr s16, [r4, #308] */
/* @0x1941a4 vldr s18, [r4, #300] */
/* @0x1941a8 vmul.f32 s15, s13, s15 */
/* @0x1941ac vdiv.f32 s15, s14, s15 */
/* @0x1941b0 vmul.f32 s16, s15, s16 */
/* @0x1941b4 vstr s15, [sp, #12] */
/* @0x1941b8 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv> */
/* @0x1941bc vmov.f32 s14, #1.000000e+00 */
/* @0x1941c0 vmov s15, r0 */
/* @0x1941c4 vdiv.f32 s16, s16, s15 */
/* @0x1941c8 vadd.f32 s16, s18, s16 */
/* @0x1941cc vcmpe.f32 s16, s14 */
/* @0x1941d0 vstr s16, [r4, #300] */
/* @0x1941d4 vmrs APSR_nzcv, fpscr */
/* @0x1941d8 blt 0x194224 <_ZN9CInstance10Adapt_PathEv+0x108> */
/* @0x1941dc vldr s15, [r4, #308] */
/* @0x1941e0 vcmp.f32 s15, #0 */
/* @0x1941e4 ldr r3, [r4, #0x140] */
/* @0x1941e8 vmrs APSR_nzcv, fpscr */
/* @0x1941ec moveq r5, #0 */
/* @0x1941f0 movne r5, #1 */
/* @0x1941f4 cmp r3, #3 */
/* @0x1941f8 addls pc, pc, r3, lsl #2 */
/* @0x1941fc b 0x194258 <_ZN9CInstance10Adapt_PathEv+0x13c> */
/* @0x194200 b 0x19423c <_ZN9CInstance10Adapt_PathEv+0x120> */
/* @0x194204 b 0x194384 <_ZN9CInstance10Adapt_PathEv+0x268> */
/* @0x194208 b 0x1943a0 <_ZN9CInstance10Adapt_PathEv+0x284> */
/* @0x19420c b 0x19434c <_ZN9CInstance10Adapt_PathEv+0x230> */
/* @0x194210 mov r5, #0 */
/* @0x194214 mov r0, r5 */
/* @0x194218 add sp, sp, #28 */
/* @0x19421c vpop {d8, d9, d10, d11} */
/* @0x194220 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x194224 vcmpe.f32 s16, #0 */
/* @0x194228 vmrs APSR_nzcv, fpscr */
/* @0x19422c bls 0x1941dc <_ZN9CInstance10Adapt_PathEv+0xc0> */
/* @0x194230 vmov r0, s17 */
/* @0x194234 mov r5, #0 */
/* @0x194238 b 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x19423c vcmpe.f32 s15, #0 */
/* @0x194240 vldr s15, [pc, #612] */
/* @0x194244 vmrs APSR_nzcv, fpscr */
/* @0x194248 bmi 0x194460 <_ZN9CInstance10Adapt_PathEv+0x344> */
/* @0x19424c cmp r5, #0 */
/* @0x194250 vmoveq r0, s17 */
/* @0x194254 beq 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x194258 vmov r0, s17 */
/* @0x19425c mvn r3, #0 */
/* @0x194260 vmov.f32 s16, #1.000000e+00 */
/* @0x194264 str r3, [r4, #0x128] */
/* @0x194268 vstr s16, [r4, #300] */
/* @0x19426c bl 0xb658c <cosf@plt> */
/* @0x194270 vmov s18, r0 */
/* @0x194274 vmov r0, s17 */
/* @0x194278 bl 0xb6580 <sinf@plt> */
/* @0x19427c vmov s19, r0 */
/* @0x194280 mov r2, r8 */
/* @0x194284 mov r3, r9 */
/* @0x194288 mov r0, r6 */
/* @0x19428c vmov r1, s16 */
/* @0x194290 str r7, [sp] */
/* @0x194294 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_> */
/* @0x194298 mov r0, r6 */
/* @0x19429c mov r1, #0 */
/* @0x1942a0 vldr s16, [sp, #16] */
/* @0x1942a4 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x1942a8 mov r1, #0 */
/* @0x1942ac vldr s20, [sp, #20] */
/* @0x1942b0 vmov s15, r0 */
/* @0x1942b4 mov r0, r6 */
/* @0x1942b8 vsub.f32 s16, s16, s15 */
/* @0x1942bc vstr s16, [sp, #16] */
/* @0x1942c0 bl 0x1a75c0 <_ZN5CPath9YPositionEf> */
/* @0x1942c4 vldr s11, [sp, #16] */
/* @0x1942c8 vmul.f32 s15, s11, s19 */
/* @0x1942cc vldr s12, [r4, #312] */
/* @0x1942d0 vldr s17, [r4, #324] */
/* @0x1942d4 vldr s16, [r4, #328] */
/* @0x1942d8 vldr s10, [r4, #180] */
/* @0x1942dc vmov s14, r0 */
/* @0x1942e0 mov r0, r4 */
/* @0x1942e4 vsub.f32 s13, s20, s14 */
/* @0x1942e8 vmul.f32 s14, s13, s19 */
/* @0x1942ec vstr s13, [sp, #20] */
/* @0x1942f0 vmla.f32 s14, s11, s18 */
/* @0x1942f4 vnmls.f32 s15, s13, s18 */
/* @0x1942f8 vmla.f32 s17, s12, s14 */
/* @0x1942fc vmla.f32 s16, s12, s15 */
/* @0x194300 vsub.f32 s10, s17, s10 */
/* @0x194304 vmov r1, s10 */
/* @0x194308 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x19430c vldr s15, [r4, #184] */
/* @0x194310 vsub.f32 s15, s16, s15 */
/* @0x194314 mov r0, r4 */
/* @0x194318 vmov r1, s15 */
/* @0x19431c bl 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x194320 mov r0, r4 */
/* @0x194324 mov r1, #0 */
/* @0x194328 bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x19432c mov r0, r4 */
/* @0x194330 vmov r1, s17 */
/* @0x194334 vmov r2, s16 */
/* @0x194338 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x19433c mov r0, r5 */
/* @0x194340 add sp, sp, #28 */
/* @0x194344 vpop {d8, d9, d10, d11} */
/* @0x194348 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x19434c vcmpe.f32 s16, #0 */
/* @0x194350 vmrs APSR_nzcv, fpscr */
/* @0x194354 vmovpl.f32 s14, #2.000000e+00 */
/* @0x194358 vmovmi r0, s17 */
/* @0x19435c vmovpl r0, s17 */
/* @0x194360 vsubpl.f32 s16, s14, s16 */
/* @0x194364 vabspl.f32 s15, s15 */
/* @0x194368 vstrpl s16, [r4, #300] */
/* @0x19436c vnegmi.f32 s16, s16 */
/* @0x194370 vabsmi.f32 s15, s15 */
/* @0x194374 vstrmi s16, [r4, #300] */
/* @0x194378 vnegpl.f32 s15, s15 */
/* @0x19437c vstr s15, [r4, #308] */
/* @0x194380 b 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x194384 vmov.f32 s15, #1.000000e+00 */
/* @0x194388 vmov r0, s17 */
/* @0x19438c vcmpe.f32 s16, #0 */
/* @0x194390 vmrs APSR_nzcv, fpscr */
/* @0x194394 vaddmi.f32 s16, s16, s15 */
/* @0x194398 vsubpl.f32 s16, s16, s15 */
/* @0x19439c b 0x194268 <_ZN9CInstance10Adapt_PathEv+0x14c> */
/* @0x1943a0 mov r1, #1065353216 */
/* @0x1943a4 mov r0, r6 */
/* @0x1943a8 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x1943ac mov r1, #0 */
/* @0x1943b0 vmov s16, r0 */
/* @0x1943b4 mov r0, r6 */
/* @0x1943b8 bl 0x1a7598 <_ZN5CPath9XPositionEf> */
/* @0x1943bc mov r1, #1065353216 */
/* @0x1943c0 vmov s15, r0 */
/* @0x1943c4 mov r0, r6 */
/* @0x1943c8 vsub.f32 s16, s16, s15 */
/* @0x1943cc vstr s16, [sp, #16] */
/* @0x1943d0 bl 0x1a75c0 <_ZN5CPath9YPositionEf> */
/* @0x1943d4 mov r1, #0 */
/* @0x1943d8 vmov s20, r0 */
/* @0x1943dc mov r0, r6 */
/* @0x1943e0 bl 0x1a75c0 <_ZN5CPath9YPositionEf> */
/* @0x1943e4 vldr s21, [r4, #312] */
/* @0x1943e8 vmov s14, r0 */
/* @0x1943ec vmov r0, s17 */
/* @0x1943f0 vsub.f32 s20, s20, s14 */
/* @0x1943f4 vstr s20, [sp, #20] */
/* @0x1943f8 bl 0xb658c <cosf@plt> */
/* @0x1943fc vldr s22, [sp, #16] */
/* @0x194400 vmov s18, r0 */
/* @0x194404 vmov r0, s17 */
/* @0x194408 bl 0xb6580 <sinf@plt> */
/* @0x19440c vldr s13, [r4, #300] */
/* @0x194410 vcmpe.f32 s13, #0 */
/* @0x194414 vmrs APSR_nzcv, fpscr */
/* @0x194418 vmov s19, r0 */
/* @0x19441c vmul.f32 s14, s20, s19 */
/* @0x194420 vmul.f32 s15, s22, s19 */
/* @0x194424 vmla.f32 s14, s18, s22 */
/* @0x194428 vnmls.f32 s15, s20, s18 */
/* @0x19442c vmul.f32 s14, s21, s14 */
/* @0x194430 vmul.f32 s15, s21, s15 */
/* @0x194434 bmi 0x194478 <_ZN9CInstance10Adapt_PathEv+0x35c> */
/* @0x194438 vldr s11, [r4, #324] */
/* @0x19443c vldr s12, [r4, #328] */
/* @0x194440 vmov.f32 s16, #1.000000e+00 */
/* @0x194444 vadd.f32 s14, s11, s14 */
/* @0x194448 vsub.f32 s16, s13, s16 */
/* @0x19444c vstr s14, [r4, #324] */
/* @0x194450 vadd.f32 s15, s12, s15 */
/* @0x194454 vstr s16, [r4, #300] */
/* @0x194458 vstr s15, [r4, #328] */
/* @0x19445c b 0x194280 <_ZN9CInstance10Adapt_PathEv+0x164> */
/* @0x194460 mvn r3, #0 */
/* @0x194464 vstr s15, [r4, #300] */
/* @0x194468 vmov r0, s17 */
/* @0x19446c str r3, [r4, #0x128] */
/* @0x194470 vmov.f32 s16, s15 */
/* @0x194474 b 0x19426c <_ZN9CInstance10Adapt_PathEv+0x150> */
/* @0x194478 vmov.f32 s16, #1.000000e+00 */
/* @0x19447c vldr s11, [r4, #324] */
/* @0x194480 vldr s12, [r4, #328] */
/* @0x194484 vsub.f32 s14, s11, s14 */
/* @0x194488 vadd.f32 s16, s13, s16 */
/* @0x19448c vstr s14, [r4, #324] */
/* @0x194490 vsub.f32 s15, s12, s15 */
/* @0x194494 vstr s16, [r4, #300] */
/* @0x194498 vstr s15, [r4, #328] */
/* @0x19449c b 0x194280 <_ZN9CInstance10Adapt_PathEv+0x164> */
/* @0x1944a0 ldrdmi r0, r1, [r9], #-251 */
/* @0x1944a4 teqmi r4, #0 */
/* @0x1944a8 sbcmi r0, r8, #0 */
/* @0x1944ac andeq r0, r0, r0 */

/* ── FUNC 0x1944b0 · CInstance::Collision_Point(float, float, bool) · size=580 · insn=145 */
/* @0x1944b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1944b4 vpush {d8, d9} */
/* @0x1944b8 sub sp, sp, #28 */
/* @0x1944bc mov r4, r0 */
/* @0x1944c0 vmov s17, r2 */
/* @0x1944c4 mov r8, r3 */
/* @0x1944c8 vmov s16, r1 */
/* @0x1944cc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x1944d0 subs r7, r0, #0 */
/* @0x1944d4 ldrbeq r2, [r4, #0x64] */
/* @0x1944d8 beq 0x194544 <_ZN9CInstance15Collision_PointEffb+0x94> */
/* @0x1944dc vldr s15, [r4, #144] */
/* @0x1944e0 vcvt.s32.f32 s15, s15 */
/* @0x1944e4 ldr r5, [pc, #0x204] */
/* @0x1944e8 ldr r1, [r4, #0xa0] */
/* @0x1944ec ldr r9, [r4, #0xb8] */
/* @0x1944f0 ldr r5, [pc, r5] */
/* @0x1944f4 ldr lr, [r4, #0x98] */
/* @0x1944f8 ldr r12, [r4, #0x9c] */
/* @0x1944fc ldr r3, [r4, #0xb4] */
/* @0x194500 ldr r6, [r5] */
/* @0x194504 vmov r2, s15 */
/* @0x194508 str r4, [r5] */
/* @0x19450c str r1, [sp, #0xc] */
/* @0x194510 add r1, r4, #232 */
/* @0x194514 str r9, [sp] */
/* @0x194518 str lr, [sp, #0x4] */
/* @0x19451c str r12, [sp, #0x8] */
/* @0x194520 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> */
/* @0x194524 str r6, [r5] */
/* @0x194528 cmp r0, #0 */
/* @0x19452c ldrbeq r2, [r4, #0x64] */
/* @0x194530 movne r3, #0 */
/* @0x194534 movne r2, r3 */
/* @0x194538 movne r1, #1 */
/* @0x19453c strbne r3, [r4, #0x64] */
/* @0x194540 strbne r1, [r4, #0xb0] */
/* @0x194544 cmp r2, #0 */
/* @0x194548 bne 0x19464c <_ZN9CInstance15Collision_PointEffb+0x19c> */
/* @0x19454c ldr r2, [r4, #0xf0] */
/* @0x194550 add r2, r2, #1 */
/* @0x194554 vmov s12, r2 */
/* @0x194558 vcvt.f32.s32 s15, s12 */
/* @0x19455c vcmpe.f32 s15, s16 */
/* @0x194560 vmrs APSR_nzcv, fpscr */
/* @0x194564 bls 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x194568 vldr s13, [r4, #232] */
/* @0x19456c vcvt.f32.s32 s15, s13 */
/* @0x194570 vcmpe.f32 s16, s15 */
/* @0x194574 vmrs APSR_nzcv, fpscr */
/* @0x194578 bmi 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x19457c ldr r3, [r4, #0xf4] */
/* @0x194580 add r3, r3, #1 */
/* @0x194584 vmov s14, r3 */
/* @0x194588 vcvt.f32.s32 s15, s14 */
/* @0x19458c vcmpe.f32 s15, s17 */
/* @0x194590 vmrs APSR_nzcv, fpscr */
/* @0x194594 bls 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x194598 vldr s12, [r4, #236] */
/* @0x19459c vcvt.f32.s32 s15, s12 */
/* @0x1945a0 vcmpe.f32 s17, s15 */
/* @0x1945a4 vmrs APSR_nzcv, fpscr */
/* @0x1945a8 bmi 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x1945ac ldrb r3, [r4, #0x68] */
/* @0x1945b0 cmp r3, #0 */
/* @0x1945b4 bne 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x1945b8 ldr r0, [r4, #0xac] */
/* @0x1945bc cmp r0, #0 */
/* @0x1945c0 ldrlt r0, [r4, #0x8c] */
/* @0x1945c4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1945c8 cmp r0, #0 */
/* @0x1945cc mov r5, r0 */
/* @0x1945d0 beq 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x1945d4 ldr r3, [r0, #0x18] */
/* @0x1945d8 cmp r3, #0 */
/* @0x1945dc beq 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c> */
/* @0x1945e0 cmp r8, #0 */
/* @0x1945e4 beq 0x19465c <_ZN9CInstance15Collision_PointEffb+0x1ac> */
/* @0x1945e8 ldrb r3, [r5, #0x30] */
/* @0x1945ec cmp r3, #0 */
/* @0x1945f0 beq 0x19465c <_ZN9CInstance15Collision_PointEffb+0x1ac> */
/* @0x1945f4 cmp r7, #0 */
/* @0x1945f8 beq 0x194664 <_ZN9CInstance15Collision_PointEffb+0x1b4> */
/* @0x1945fc vstr s16, [sp, #12] */
/* @0x194600 vstr s17, [sp, #16] */
/* @0x194604 vldr s15, [r4, #144] */
/* @0x194608 vcvt.s32.f32 s15, s15 */
/* @0x19460c ldr r12, [r4, #0x98] */
/* @0x194610 mov r0, r7 */
/* @0x194614 ldr r2, [r4, #0xb4] */
/* @0x194618 ldr r3, [r4, #0xb8] */
/* @0x19461c str r12, [sp] */
/* @0x194620 ldr lr, [r4, #0x9c] */
/* @0x194624 ldr r12, [r4, #0xa0] */
/* @0x194628 vmov r1, s15 */
/* @0x19462c str lr, [sp, #0x4] */
/* @0x194630 str r12, [sp, #0x8] */
/* @0x194634 bl 0xbf374 <_ZN17CSkeletonInstance14PointCollisionEifffffff> */
/* @0x194638 b 0x194640 <_ZN9CInstance15Collision_PointEffb+0x190> */
/* @0x19463c mov r0, #0 */
/* @0x194640 add sp, sp, #28 */
/* @0x194644 vpop {d8, d9} */
/* @0x194648 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19464c mov r0, r4 */
/* @0x194650 mov r1, #1 */
/* @0x194654 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x194658 b 0x19454c <_ZN9CInstance15Collision_PointEffb+0x9c> */
/* @0x19465c mov r0, #1 */
/* @0x194660 b 0x194640 <_ZN9CInstance15Collision_PointEffb+0x190> */
/* @0x194664 vldr s15, [r4, #180] */
/* @0x194668 vcvt.f64.f32 d6, s15 */
/* @0x19466c vldr s15, [r4, #144] */
/* @0x194670 vcvt.s32.f32 s15, s15 */
/* @0x194674 vmov r0, r1, d6 */
/* @0x194678 vmov r9, s15 */
/* @0x19467c bl 0xb66e8 <lrint@plt> */
/* @0x194680 vldr s15, [r4, #184] */
/* @0x194684 vcvt.f64.f32 d6, s15 */
/* @0x194688 mov r6, r0 */
/* @0x19468c vmov r0, r1, d6 */
/* @0x194690 bl 0xb66e8 <lrint@plt> */
/* @0x194694 vldr s18, [r4, #152] */
/* @0x194698 vcvt.f64.f32 d7, s16 */
/* @0x19469c ldr r11, [r4, #0x9c] */
/* @0x1946a0 ldr r10, [r4, #0xa0] */
/* @0x1946a4 mov r8, r0 */
/* @0x1946a8 vmov r0, r1, d7 */
/* @0x1946ac bl 0xb66e8 <lrint@plt> */
/* @0x1946b0 vcvt.f64.f32 d6, s17 */
/* @0x1946b4 mov r7, r0 */
/* @0x1946b8 vmov r0, r1, d6 */
/* @0x1946bc bl 0xb66e8 <lrint@plt> */
/* @0x1946c0 str r8, [sp] */
/* @0x1946c4 mov r1, r9 */
/* @0x1946c8 vstr s18, [sp, #4] */
/* @0x1946cc str r11, [sp, #0x8] */
/* @0x1946d0 mov r3, r6 */
/* @0x1946d4 str r10, [sp, #0xc] */
/* @0x1946d8 add r2, r4, #232 */
/* @0x1946dc str r7, [sp, #0x10] */
/* @0x1946e0 str r0, [sp, #0x14] */
/* @0x1946e4 mov r0, r5 */
/* @0x1946e8 bl 0x1e4a30 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii> */
/* @0x1946ec b 0x194640 <_ZN9CInstance15Collision_PointEffb+0x190> */
/* @0x1946f0 eoreq r9, r5, r4, asr #8 */

/* ── FUNC 0x1946f4 · CInstance::Collision_Rectangle(float, float, float, float, bool) · size=756 · insn=189 */
/* @0x1946f4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1946f8 vpush {d8, d9} */
/* @0x1946fc sub sp, sp, #52 */
/* @0x194700 vldr s18, [sp, #96] */
/* @0x194704 mov r4, r0 */
/* @0x194708 vmov s16, r3 */
/* @0x19470c vmov s17, r1 */
/* @0x194710 ldrb r7, [sp, #0x64] */
/* @0x194714 vmov s19, r2 */
/* @0x194718 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x19471c subs r8, r0, #0 */
/* @0x194720 ldrbeq r3, [r4, #0x64] */
/* @0x194724 beq 0x194790 <_ZN9CInstance19Collision_RectangleEffffb+0x9c> */
/* @0x194728 vldr s15, [r4, #144] */
/* @0x19472c vcvt.s32.f32 s15, s15 */
/* @0x194730 ldr r5, [pc, #0x2ac] */
/* @0x194734 ldr r1, [r4, #0xa0] */
/* @0x194738 ldr r9, [r4, #0xb8] */
/* @0x19473c ldr r5, [pc, r5] */
/* @0x194740 ldr lr, [r4, #0x98] */
/* @0x194744 ldr r12, [r4, #0x9c] */
/* @0x194748 ldr r3, [r4, #0xb4] */
/* @0x19474c ldr r6, [r5] */
/* @0x194750 vmov r2, s15 */
/* @0x194754 str r4, [r5] */
/* @0x194758 str r1, [sp, #0xc] */
/* @0x19475c add r1, r4, #232 */
/* @0x194760 str r9, [sp] */
/* @0x194764 str lr, [sp, #0x4] */
/* @0x194768 str r12, [sp, #0x8] */
/* @0x19476c bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> */
/* @0x194770 str r6, [r5] */
/* @0x194774 cmp r0, #0 */
/* @0x194778 ldrbeq r3, [r4, #0x64] */
/* @0x19477c movne r2, #0 */
/* @0x194780 movne r3, r2 */
/* @0x194784 movne r1, #1 */
/* @0x194788 strbne r2, [r4, #0x64] */
/* @0x19478c strbne r1, [r4, #0xb0] */
/* @0x194790 cmp r3, #0 */
/* @0x194794 bne 0x194960 <_ZN9CInstance19Collision_RectangleEffffb+0x26c> */
/* @0x194798 ldr r3, [r4, #0xf0] */
/* @0x19479c vcmpe.f32 s17, s16 */
/* @0x1947a0 add r3, r3, #1 */
/* @0x1947a4 vmov s12, r3 */
/* @0x1947a8 vmrs APSR_nzcv, fpscr */
/* @0x1947ac vmovpl.f32 s14, s16 */
/* @0x1947b0 vmovmi.f32 s14, s17 */
/* @0x1947b4 vcvt.f32.s32 s15, s12 */
/* @0x1947b8 vcmpe.f32 s14, s15 */
/* @0x1947bc vmrs APSR_nzcv, fpscr */
/* @0x1947c0 bge 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x1947c4 vcmpe.f32 s17, s16 */
/* @0x1947c8 vldr s13, [r4, #232] */
/* @0x1947cc vcvt.f32.s32 s15, s13 */
/* @0x1947d0 vmrs APSR_nzcv, fpscr */
/* @0x1947d4 vmovle.f32 s14, s16 */
/* @0x1947d8 vmovgt.f32 s14, s17 */
/* @0x1947dc vcmpe.f32 s14, s15 */
/* @0x1947e0 vmrs APSR_nzcv, fpscr */
/* @0x1947e4 bmi 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x1947e8 ldr r3, [r4, #0xf4] */
/* @0x1947ec vcmpe.f32 s19, s18 */
/* @0x1947f0 add r3, r3, #1 */
/* @0x1947f4 vmov s14, r3 */
/* @0x1947f8 vmrs APSR_nzcv, fpscr */
/* @0x1947fc vcvt.f32.s32 s15, s14 */
/* @0x194800 vmovpl.f32 s14, s18 */
/* @0x194804 vmovmi.f32 s14, s19 */
/* @0x194808 vcmpe.f32 s14, s15 */
/* @0x19480c vmrs APSR_nzcv, fpscr */
/* @0x194810 bge 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x194814 vcmpe.f32 s19, s18 */
/* @0x194818 vldr s12, [r4, #236] */
/* @0x19481c vcvt.f32.s32 s15, s12 */
/* @0x194820 vmrs APSR_nzcv, fpscr */
/* @0x194824 vmovle.f32 s14, s18 */
/* @0x194828 vmovgt.f32 s14, s19 */
/* @0x19482c vcmpe.f32 s14, s15 */
/* @0x194830 vmrs APSR_nzcv, fpscr */
/* @0x194834 bmi 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x194838 ldrb r3, [r4, #0x68] */
/* @0x19483c cmp r3, #0 */
/* @0x194840 bne 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x194844 cmp r7, #0 */
/* @0x194848 beq 0x194970 <_ZN9CInstance19Collision_RectangleEffffb+0x27c> */
/* @0x19484c ldrb r3, [r4, #0xb0] */
/* @0x194850 cmp r3, #0 */
/* @0x194854 beq 0x194970 <_ZN9CInstance19Collision_RectangleEffffb+0x27c> */
/* @0x194858 ldr r0, [r4, #0xac] */
/* @0x19485c cmp r0, #0 */
/* @0x194860 ldrlt r0, [r4, #0x8c] */
/* @0x194864 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x194868 cmp r0, #0 */
/* @0x19486c mov r5, r0 */
/* @0x194870 beq 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x194874 ldr r3, [r0, #0x18] */
/* @0x194878 cmp r3, #0 */
/* @0x19487c beq 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c> */
/* @0x194880 vcmpe.f32 s17, s16 */
/* @0x194884 vmrs APSR_nzcv, fpscr */
/* @0x194888 vmovpl.f32 s15, s16 */
/* @0x19488c vmovmi.f32 s15, s17 */
/* @0x194890 vcvt.f64.f32 d6, s15 */
/* @0x194894 vmov r0, r1, d6 */
/* @0x194898 bl 0xb66e8 <lrint@plt> */
/* @0x19489c vcmpe.f32 s19, s18 */
/* @0x1948a0 vmrs APSR_nzcv, fpscr */
/* @0x1948a4 vmovpl.f32 s15, s18 */
/* @0x1948a8 vmovmi.f32 s15, s19 */
/* @0x1948ac vcvt.f64.f32 d6, s15 */
/* @0x1948b0 str r0, [sp, #0x20] */
/* @0x1948b4 vmov r0, r1, d6 */
/* @0x1948b8 bl 0xb66e8 <lrint@plt> */
/* @0x1948bc vcmpe.f32 s17, s16 */
/* @0x1948c0 vmrs APSR_nzcv, fpscr */
/* @0x1948c4 vmovle.f32 s15, s16 */
/* @0x1948c8 vmovgt.f32 s15, s17 */
/* @0x1948cc vcvt.f64.f32 d6, s15 */
/* @0x1948d0 str r0, [sp, #0x24] */
/* @0x1948d4 vmov r0, r1, d6 */
/* @0x1948d8 bl 0xb66e8 <lrint@plt> */
/* @0x1948dc vcmpe.f32 s19, s18 */
/* @0x1948e0 vmrs APSR_nzcv, fpscr */
/* @0x1948e4 vmovle.f32 s15, s18 */
/* @0x1948e8 vmovgt.f32 s15, s19 */
/* @0x1948ec vcvt.f64.f32 d6, s15 */
/* @0x1948f0 str r0, [sp, #0x28] */
/* @0x1948f4 vmov r0, r1, d6 */
/* @0x1948f8 bl 0xb66e8 <lrint@plt> */
/* @0x1948fc cmp r8, #0 */
/* @0x194900 str r0, [sp, #0x2c] */
/* @0x194904 beq 0x194978 <_ZN9CInstance19Collision_RectangleEffffb+0x284> */
/* @0x194908 vstr s17, [sp, #12] */
/* @0x19490c vstr s19, [sp, #16] */
/* @0x194910 vstr s16, [sp, #20] */
/* @0x194914 vstr s18, [sp, #24] */
/* @0x194918 vldr s15, [r4, #144] */
/* @0x19491c vcvt.s32.f32 s15, s15 */
/* @0x194920 ldr r12, [r4, #0x98] */
/* @0x194924 mov r0, r8 */
/* @0x194928 ldr r2, [r4, #0xb4] */
/* @0x19492c ldr r3, [r4, #0xb8] */
/* @0x194930 str r12, [sp] */
/* @0x194934 ldr lr, [r4, #0x9c] */
/* @0x194938 ldr r12, [r4, #0xa0] */
/* @0x19493c vmov r1, s15 */
/* @0x194940 str lr, [sp, #0x4] */
/* @0x194944 str r12, [sp, #0x8] */
/* @0x194948 bl 0xbf434 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff> */
/* @0x19494c b 0x194954 <_ZN9CInstance19Collision_RectangleEffffb+0x260> */
/* @0x194950 mov r0, #0 */
/* @0x194954 add sp, sp, #52 */
/* @0x194958 vpop {d8, d9} */
/* @0x19495c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x194960 mov r0, r4 */
/* @0x194964 mov r1, #1 */
/* @0x194968 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x19496c b 0x194798 <_ZN9CInstance19Collision_RectangleEffffb+0xa4> */
/* @0x194970 mov r0, #1 */
/* @0x194974 b 0x194954 <_ZN9CInstance19Collision_RectangleEffffb+0x260> */
/* @0x194978 vldr s15, [r4, #180] */
/* @0x19497c vcvt.f64.f32 d6, s15 */
/* @0x194980 vldr s15, [r4, #144] */
/* @0x194984 vcvt.s32.f32 s15, s15 */
/* @0x194988 vmov r0, r1, d6 */
/* @0x19498c vmov r7, s15 */
/* @0x194990 bl 0xb66e8 <lrint@plt> */
/* @0x194994 vldr s15, [r4, #184] */
/* @0x194998 vcvt.f64.f32 d6, s15 */
/* @0x19499c mov r6, r0 */
/* @0x1949a0 vmov r0, r1, d6 */
/* @0x1949a4 bl 0xb66e8 <lrint@plt> */
/* @0x1949a8 ldr r12, [r4, #0x98] */
/* @0x1949ac ldr r2, [r4, #0x9c] */
/* @0x1949b0 mov r1, r7 */
/* @0x1949b4 mov r3, r6 */
/* @0x1949b8 str r12, [sp, #0x4] */
/* @0x1949bc str r2, [sp, #0x8] */
/* @0x1949c0 add r2, r4, #232 */
/* @0x1949c4 ldr r12, [r4, #0xa0] */
/* @0x1949c8 str r12, [sp, #0xc] */
/* @0x1949cc add r12, sp, #32 */
/* @0x1949d0 str r12, [sp, #0x10] */
/* @0x1949d4 str r0, [sp] */
/* @0x1949d8 mov r0, r5 */
/* @0x1949dc bl 0x1e4c24 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_> */
/* @0x1949e0 b 0x194954 <_ZN9CInstance19Collision_RectangleEffffb+0x260> */
/* @0x1949e4 .word 0x002591f8 */

/* ── FUNC 0x1949e8 · InEll(tagYYRECT*, int, int) · size=168 · insn=42 */
/* @0x1949e8 ldr r3, [r0, #0x4] */
/* @0x1949ec vmov s13, r2 */
/* @0x1949f0 ldr r12, [r0, #0xc] */
/* @0x1949f4 vmov s15, r1 */
/* @0x1949f8 str r4, [sp, #-0x4]! */
/* @0x1949fc add r4, r12, r3 */
/* @0x194a00 vcvt.f64.s32 d0, s13 */
/* @0x194a04 rsb r12, r3, r12 */
/* @0x194a08 add r4, r4, r4, lsr #31 */
/* @0x194a0c ldr r2, [r0, #0x8] */
/* @0x194a10 add r12, r12, r12, lsr #31 */
/* @0x194a14 ldr r3, [r0] */
/* @0x194a18 asr r4, r4, #1 */
/* @0x194a1c asr r12, r12, #1 */
/* @0x194a20 add r0, r2, r3 */
/* @0x194a24 vmov s13, r4 */
/* @0x194a28 rsb r3, r3, r2 */
/* @0x194a2c add r0, r0, r0, lsr #31 */
/* @0x194a30 ldr r4, [sp], #4 */
/* @0x194a34 vcvt.f64.s32 d1, s13 */
/* @0x194a38 add r3, r3, r3, lsr #31 */
/* @0x194a3c asr r0, r0, #1 */
/* @0x194a40 asr r3, r3, #1 */
/* @0x194a44 vmov s13, r0 */
/* @0x194a48 vsub.f64 d1, d0, d1 */
/* @0x194a4c vcvt.f64.s32 d3, s15 */
/* @0x194a50 vmov s15, r12 */
/* @0x194a54 vcvt.f64.s32 d2, s15 */
/* @0x194a58 vcvt.f64.s32 d4, s13 */
/* @0x194a5c vmov s13, r3 */
/* @0x194a60 vdiv.f64 d7, d1, d2 */
/* @0x194a64 vsub.f64 d4, d3, d4 */
/* @0x194a68 vcvt.f64.s32 d5, s13 */
/* @0x194a6c vdiv.f64 d6, d4, d5 */
/* @0x194a70 vmul.f64 d7, d7, d7 */
/* @0x194a74 vmla.f64 d7, d6, d6 */
/* @0x194a78 vmov.f64 d6, #1.000000e+00 */
/* @0x194a7c vcmpe.f64 d7, d6 */
/* @0x194a80 vmrs APSR_nzcv, fpscr */
/* @0x194a84 movhi r0, #0 */
/* @0x194a88 movls r0, #1 */
/* @0x194a8c bx lr */

/* ── FUNC 0x194a90 · CInstance::Collision_Ellipse(float, float, float, float, bool) · size=1176 · insn=294 */
/* @0x194a90 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x194a94 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x194a98 sub sp, sp, #60 */
/* @0x194a9c vldr s27, [sp, #136] */
/* @0x194aa0 mov r4, r0 */
/* @0x194aa4 vmov s25, r3 */
/* @0x194aa8 vmov s24, r1 */
/* @0x194aac ldrb r7, [sp, #0x8c] */
/* @0x194ab0 vmov s26, r2 */
/* @0x194ab4 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv> */
/* @0x194ab8 subs r8, r0, #0 */
/* @0x194abc ldrbeq r3, [r4, #0x64] */
/* @0x194ac0 beq 0x194b2c <_ZN9CInstance17Collision_EllipseEffffb+0x9c> */
/* @0x194ac4 vldr s15, [r4, #144] */
/* @0x194ac8 vcvt.s32.f32 s15, s15 */
/* @0x194acc ldr r5, [pc, #0x450] */
/* @0x194ad0 ldr r1, [r4, #0xa0] */
/* @0x194ad4 ldr r9, [r4, #0xb8] */
/* @0x194ad8 ldr r5, [pc, r5] */
/* @0x194adc ldr lr, [r4, #0x98] */
/* @0x194ae0 ldr r12, [r4, #0x9c] */
/* @0x194ae4 ldr r3, [r4, #0xb4] */
/* @0x194ae8 ldr r6, [r5] */
/* @0x194aec vmov r2, s15 */
/* @0x194af0 str r4, [r5] */
/* @0x194af4 str r1, [sp, #0xc] */
/* @0x194af8 add r1, r4, #232 */
/* @0x194afc str r9, [sp] */
/* @0x194b00 str lr, [sp, #0x4] */
/* @0x194b04 str r12, [sp, #0x8] */
/* @0x194b08 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff> */
/* @0x194b0c str r6, [r5] */
/* @0x194b10 cmp r0, #0 */
/* @0x194b14 ldrbeq r3, [r4, #0x64] */
/* @0x194b18 movne r2, #0 */
/* @0x194b1c movne r3, r2 */
/* @0x194b20 movne r1, #1 */
/* @0x194b24 strbne r2, [r4, #0x64] */
/* @0x194b28 strbne r1, [r4, #0xb0] */
/* @0x194b2c cmp r3, #0 */
/* @0x194b30 bne 0x194e58 <_ZN9CInstance17Collision_EllipseEffffb+0x3c8> */
/* @0x194b34 ldr r3, [r4, #0xf0] */
/* @0x194b38 vcmpe.f32 s24, s25 */
/* @0x194b3c add r3, r3, #1 */
/* @0x194b40 vmov s12, r3 */
/* @0x194b44 vmrs APSR_nzcv, fpscr */
/* @0x194b48 vmovpl.f32 s14, s25 */
/* @0x194b4c vmovmi.f32 s14, s24 */
/* @0x194b50 vcvt.f32.s32 s15, s12 */
/* @0x194b54 vcmpe.f32 s14, s15 */
/* @0x194b58 vmrs APSR_nzcv, fpscr */
/* @0x194b5c bge 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194b60 vcmpe.f32 s24, s25 */
/* @0x194b64 vldr s13, [r4, #232] */
/* @0x194b68 vcvt.f32.s32 s15, s13 */
/* @0x194b6c vmrs APSR_nzcv, fpscr */
/* @0x194b70 vmovle.f32 s14, s25 */
/* @0x194b74 vmovgt.f32 s14, s24 */
/* @0x194b78 vcmpe.f32 s14, s15 */
/* @0x194b7c vmrs APSR_nzcv, fpscr */
/* @0x194b80 bmi 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194b84 ldr r3, [r4, #0xf4] */
/* @0x194b88 vcmpe.f32 s26, s27 */
/* @0x194b8c add r3, r3, #1 */
/* @0x194b90 vmov s14, r3 */
/* @0x194b94 vmrs APSR_nzcv, fpscr */
/* @0x194b98 vcvt.f32.s32 s15, s14 */
/* @0x194b9c vmovpl.f32 s14, s27 */
/* @0x194ba0 vmovmi.f32 s14, s26 */
/* @0x194ba4 vcmpe.f32 s14, s15 */
/* @0x194ba8 vmrs APSR_nzcv, fpscr */
/* @0x194bac bge 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194bb0 vcmpe.f32 s26, s27 */
/* @0x194bb4 vldr s12, [r4, #236] */
/* @0x194bb8 vcvt.f32.s32 s15, s12 */
/* @0x194bbc vmrs APSR_nzcv, fpscr */
/* @0x194bc0 vmovle.f32 s14, s27 */
/* @0x194bc4 vmovgt.f32 s14, s26 */
/* @0x194bc8 vcmpe.f32 s14, s15 */
/* @0x194bcc vmrs APSR_nzcv, fpscr */
/* @0x194bd0 bmi 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194bd4 ldrb r3, [r4, #0x68] */
/* @0x194bd8 cmp r3, #0 */
/* @0x194bdc bne 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194be0 vcvt.f64.f32 d9, s24 */
/* @0x194be4 vmov r0, r1, d9 */
/* @0x194be8 bl 0xb66e8 <lrint@plt> */
/* @0x194bec vcvt.f64.f32 d8, s25 */
/* @0x194bf0 mov r5, r0 */
/* @0x194bf4 vmov r0, r1, d8 */
/* @0x194bf8 bl 0xb66e8 <lrint@plt> */
/* @0x194bfc cmp r5, r0 */
/* @0x194c00 beq 0x194e68 <_ZN9CInstance17Collision_EllipseEffffb+0x3d8> */
/* @0x194c04 vcvt.f64.f32 d11, s26 */
/* @0x194c08 vmov r0, r1, d11 */
/* @0x194c0c bl 0xb66e8 <lrint@plt> */
/* @0x194c10 vcvt.f64.f32 d10, s27 */
/* @0x194c14 mov r5, r0 */
/* @0x194c18 vmov r0, r1, d10 */
/* @0x194c1c bl 0xb66e8 <lrint@plt> */
/* @0x194c20 cmp r5, r0 */
/* @0x194c24 beq 0x194e68 <_ZN9CInstance17Collision_EllipseEffffb+0x3d8> */
/* @0x194c28 vcmpe.f32 s24, s25 */
/* @0x194c2c vmrs APSR_nzcv, fpscr */
/* @0x194c30 vmovpl r0, r1, d8 */
/* @0x194c34 vmovmi r0, r1, d9 */
/* @0x194c38 bl 0xb66e8 <lrint@plt> */
/* @0x194c3c vcmpe.f32 s26, s27 */
/* @0x194c40 vmrs APSR_nzcv, fpscr */
/* @0x194c44 str r0, [sp, #0x18] */
/* @0x194c48 vmovpl r0, r1, d10 */
/* @0x194c4c vmovmi r0, r1, d11 */
/* @0x194c50 bl 0xb66e8 <lrint@plt> */
/* @0x194c54 vcmpe.f32 s24, s25 */
/* @0x194c58 vmrs APSR_nzcv, fpscr */
/* @0x194c5c str r0, [sp, #0x1c] */
/* @0x194c60 vmovle r0, r1, d8 */
/* @0x194c64 vmovgt r0, r1, d9 */
/* @0x194c68 bl 0xb66e8 <lrint@plt> */
/* @0x194c6c vcmpe.f32 s26, s27 */
/* @0x194c70 vmrs APSR_nzcv, fpscr */
/* @0x194c74 str r0, [sp, #0x20] */
/* @0x194c78 vmovle r0, r1, d10 */
/* @0x194c7c vmovgt r0, r1, d11 */
/* @0x194c80 bl 0xb66e8 <lrint@plt> */
/* @0x194c84 ldr r1, [r4, #0xe8] */
/* @0x194c88 vadd.f32 s14, s24, s25 */
/* @0x194c8c vmov s12, r1 */
/* @0x194c90 vmov.f32 s15, #5.000000e-01 */
/* @0x194c94 vmul.f32 s15, s14, s15 */
/* @0x194c98 str r0, [sp, #0x24] */
/* @0x194c9c vcvt.f32.s32 s14, s12 */
/* @0x194ca0 vcmpe.f32 s14, s15 */
/* @0x194ca4 vmrs APSR_nzcv, fpscr */
/* @0x194ca8 bhi 0x194cc0 <_ZN9CInstance17Collision_EllipseEffffb+0x230> */
/* @0x194cac vldr s13, [r4, #240] */
/* @0x194cb0 vcvt.f32.s32 s14, s13 */
/* @0x194cb4 vcmpe.f32 s15, s14 */
/* @0x194cb8 vmrs APSR_nzcv, fpscr */
/* @0x194cbc bls 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194cc0 vadd.f32 s14, s26, s27 */
/* @0x194cc4 ldr r2, [r4, #0xec] */
/* @0x194cc8 vmov s12, r2 */
/* @0x194ccc vmov.f32 s15, #5.000000e-01 */
/* @0x194cd0 vmul.f32 s15, s14, s15 */
/* @0x194cd4 vcvt.f32.s32 s14, s12 */
/* @0x194cd8 vcmpe.f32 s14, s15 */
/* @0x194cdc vmrs APSR_nzcv, fpscr */
/* @0x194ce0 bhi 0x194cf8 <_ZN9CInstance17Collision_EllipseEffffb+0x268> */
/* @0x194ce4 vldr s13, [r4, #244] */
/* @0x194ce8 vcvt.f32.s32 s14, s13 */
/* @0x194cec vcmpe.f32 s15, s14 */
/* @0x194cf0 vmrs APSR_nzcv, fpscr */
/* @0x194cf4 bls 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194cf8 add r5, sp, #24 */
/* @0x194cfc mov r0, r5 */
/* @0x194d00 bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194d04 cmp r0, #0 */
/* @0x194d08 beq 0x194e00 <_ZN9CInstance17Collision_EllipseEffffb+0x370> */
/* @0x194d0c cmp r7, #0 */
/* @0x194d10 beq 0x194e88 <_ZN9CInstance17Collision_EllipseEffffb+0x3f8> */
/* @0x194d14 ldrb r3, [r4, #0xb0] */
/* @0x194d18 cmp r3, #0 */
/* @0x194d1c beq 0x194e88 <_ZN9CInstance17Collision_EllipseEffffb+0x3f8> */
/* @0x194d20 vcmpe.f32 s24, s25 */
/* @0x194d24 vmrs APSR_nzcv, fpscr */
/* @0x194d28 vmovpl r0, r1, d8 */
/* @0x194d2c vmovmi r0, r1, d9 */
/* @0x194d30 bl 0xb66e8 <lrint@plt> */
/* @0x194d34 vcmpe.f32 s26, s27 */
/* @0x194d38 vmrs APSR_nzcv, fpscr */
/* @0x194d3c str r0, [sp, #0x28] */
/* @0x194d40 vmovpl r0, r1, d10 */
/* @0x194d44 vmovmi r0, r1, d11 */
/* @0x194d48 bl 0xb66e8 <lrint@plt> */
/* @0x194d4c vcmp.f32 s24, s25 */
/* @0x194d50 vmrs APSR_nzcv, fpscr */
/* @0x194d54 str r0, [sp, #0x2c] */
/* @0x194d58 vmovgt r0, r1, d9 */
/* @0x194d5c vmovle r0, r1, d8 */
/* @0x194d60 bl 0xb66e8 <lrint@plt> */
/* @0x194d64 vcmp.f32 s26, s27 */
/* @0x194d68 vmrs APSR_nzcv, fpscr */
/* @0x194d6c str r0, [sp, #0x30] */
/* @0x194d70 vmovgt r0, r1, d11 */
/* @0x194d74 vmovle r0, r1, d10 */
/* @0x194d78 bl 0xb66e8 <lrint@plt> */
/* @0x194d7c cmp r8, #0 */
/* @0x194d80 str r0, [sp, #0x34] */
/* @0x194d84 beq 0x194e90 <_ZN9CInstance17Collision_EllipseEffffb+0x400> */
/* @0x194d88 vldr s15, [r4, #180] */
/* @0x194d8c vcvt.f64.f32 d6, s15 */
/* @0x194d90 vldr s15, [r4, #144] */
/* @0x194d94 vcvt.s32.f32 s15, s15 */
/* @0x194d98 vmov r0, r1, d6 */
/* @0x194d9c vmov r6, s15 */
/* @0x194da0 bl 0xb66e8 <lrint@plt> */
/* @0x194da4 vldr s15, [r4, #184] */
/* @0x194da8 vcvt.f64.f32 d6, s15 */
/* @0x194dac mov r5, r0 */
/* @0x194db0 vmov r0, r1, d6 */
/* @0x194db4 bl 0xb66e8 <lrint@plt> */
/* @0x194db8 ldr r2, [r4, #0x98] */
/* @0x194dbc vmov s13, r5 */
/* @0x194dc0 ldr r3, [r4, #0x9c] */
/* @0x194dc4 mov r1, r6 */
/* @0x194dc8 vcvt.f32.s32 s13, s13 */
/* @0x194dcc str r2, [sp] */
/* @0x194dd0 str r3, [sp, #0x4] */
/* @0x194dd4 ldr r3, [r4, #0xa0] */
/* @0x194dd8 str r3, [sp, #0x8] */
/* @0x194ddc add r3, sp, #40 */
/* @0x194de0 str r3, [sp, #0xc] */
/* @0x194de4 vmov r2, s13 */
/* @0x194de8 vmov s14, r0 */
/* @0x194dec mov r0, r8 */
/* @0x194df0 vcvt.f32.s32 s15, s14 */
/* @0x194df4 vmov r3, s15 */
/* @0x194df8 bl 0xbf524 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT> */
/* @0x194dfc b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194e00 mov r0, r5 */
/* @0x194e04 ldr r1, [r4, #0xe8] */
/* @0x194e08 ldr r2, [r4, #0xf4] */
/* @0x194e0c bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194e10 cmp r0, #0 */
/* @0x194e14 bne 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194e18 mov r0, r5 */
/* @0x194e1c ldr r1, [r4, #0xf0] */
/* @0x194e20 ldr r2, [r4, #0xec] */
/* @0x194e24 bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194e28 cmp r0, #0 */
/* @0x194e2c bne 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194e30 mov r0, r5 */
/* @0x194e34 ldr r1, [r4, #0xf0] */
/* @0x194e38 ldr r2, [r4, #0xf4] */
/* @0x194e3c bl 0x1949e8 <_Z5InEllP9tagYYRECTii> */
/* @0x194e40 cmp r0, #0 */
/* @0x194e44 bne 0x194d0c <_ZN9CInstance17Collision_EllipseEffffb+0x27c> */
/* @0x194e48 mov r0, #0 */
/* @0x194e4c add sp, sp, #60 */
/* @0x194e50 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x194e54 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x194e58 mov r0, r4 */
/* @0x194e5c mov r1, #1 */
/* @0x194e60 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x194e64 b 0x194b34 <_ZN9CInstance17Collision_EllipseEffffb+0xa4> */
/* @0x194e68 vstr s27, [sp] */
/* @0x194e6c str r7, [sp, #0x4] */
/* @0x194e70 mov r0, r4 */
/* @0x194e74 vmov r1, s24 */
/* @0x194e78 vmov r2, s26 */
/* @0x194e7c vmov r3, s25 */
/* @0x194e80 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x194e84 b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194e88 mov r0, #1 */
/* @0x194e8c b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194e90 ldr r0, [r4, #0xac] */
/* @0x194e94 cmp r0, #0 */
/* @0x194e98 ldrlt r0, [r4, #0x8c] */
/* @0x194e9c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x194ea0 cmp r0, #0 */
/* @0x194ea4 mov r5, r0 */
/* @0x194ea8 beq 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194eac ldr r3, [r0, #0x18] */
/* @0x194eb0 cmp r3, #0 */
/* @0x194eb4 beq 0x194e48 <_ZN9CInstance17Collision_EllipseEffffb+0x3b8> */
/* @0x194eb8 vldr s15, [r4, #180] */
/* @0x194ebc vcvt.f64.f32 d6, s15 */
/* @0x194ec0 vldr s15, [r4, #144] */
/* @0x194ec4 vcvt.s32.f32 s15, s15 */
/* @0x194ec8 vmov r0, r1, d6 */
/* @0x194ecc vmov r7, s15 */
/* @0x194ed0 bl 0xb66e8 <lrint@plt> */
/* @0x194ed4 vldr s15, [r4, #184] */
/* @0x194ed8 vcvt.f64.f32 d6, s15 */
/* @0x194edc mov r6, r0 */
/* @0x194ee0 vmov r0, r1, d6 */
/* @0x194ee4 bl 0xb66e8 <lrint@plt> */
/* @0x194ee8 ldr r12, [r4, #0x98] */
/* @0x194eec ldr r2, [r4, #0x9c] */
/* @0x194ef0 mov r1, r7 */
/* @0x194ef4 mov r3, r6 */
/* @0x194ef8 str r12, [sp, #0x4] */
/* @0x194efc str r2, [sp, #0x8] */
/* @0x194f00 add r2, r4, #232 */
/* @0x194f04 ldr r12, [r4, #0xa0] */
/* @0x194f08 str r12, [sp, #0xc] */
/* @0x194f0c add r12, sp, #40 */
/* @0x194f10 str r12, [sp, #0x10] */
/* @0x194f14 str r0, [sp] */
/* @0x194f18 mov r0, r5 */
/* @0x194f1c bl 0x1e4f0c <_ZN7CSprite23PreciseCollisionEllipseEiP9tagYYRECTiifffS1_> */
/* @0x194f20 b 0x194e4c <_ZN9CInstance17Collision_EllipseEffffb+0x3bc> */
/* @0x194f24 eoreq r8, r5, r12, asr lr */
