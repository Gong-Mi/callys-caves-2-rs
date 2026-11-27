/* libyoyo.so 覆盖卡组 0211
 * 函数 0x2369dc..0x237ad4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2369dc · CPhysicsFixture::CheckPolygonIntegrity() · size=236 · insn=59 */
/* @0x2369dc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2369e0 vpush {d8} */
/* @0x2369e4 mov r8, r0 */
/* @0x2369e8 ldr r5, [r0, #0xc] */
/* @0x2369ec cmp r5, #2 */
/* @0x2369f0 ble 0x236ab0 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0xd4> */
/* @0x2369f4 ldr r10, [r0, #0x14] */
/* @0x2369f8 mov r4, #0 */
/* @0x2369fc vldr s16, [pc, #188] */
/* @0x236a00 mov r7, r10 */
/* @0x236a04 add r9, r4, #1 */
/* @0x236a08 mov r1, r5 */
/* @0x236a0c mov r0, r9 */
/* @0x236a10 bl 0x318dec <__aeabi_idivmod> */
/* @0x236a14 vldr s12, [r7] */
/* @0x236a18 vldr s13, [r7, #4] */
/* @0x236a1c mov r2, r10 */
/* @0x236a20 add r3, r10, r1, lsl #3 */
/* @0x236a24 vldr s10, [r3] */
/* @0x236a28 vldr s11, [r3, #4] */
/* @0x236a2c vsub.f32 s10, s10, s12 */
/* @0x236a30 mov r3, #0 */
/* @0x236a34 vsub.f32 s11, s11, s13 */
/* @0x236a38 cmp r4, r3 */
/* @0x236a3c cmpne r3, r1 */
/* @0x236a40 add r3, r3, #1 */
/* @0x236a44 movne r6, #0 */
/* @0x236a48 moveq r6, #1 */
/* @0x236a4c beq 0x236a74 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0x98> */
/* @0x236a50 vldr s15, [r2] */
/* @0x236a54 vldr s14, [r2, #4] */
/* @0x236a58 vsub.f32 s15, s15, s12 */
/* @0x236a5c vmul.f32 s15, s11, s15 */
/* @0x236a60 vsub.f32 s14, s14, s13 */
/* @0x236a64 vnmls.f32 s15, s10, s14 */
/* @0x236a68 vcmpe.f32 s15, s16 */
/* @0x236a6c vmrs APSR_nzcv, fpscr */
/* @0x236a70 bls 0x236a94 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0xb8> */
/* @0x236a74 cmp r3, r5 */
/* @0x236a78 add r2, r2, #8 */
/* @0x236a7c bne 0x236a38 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0x5c> */
/* @0x236a80 cmp r9, r5 */
/* @0x236a84 add r7, r7, #8 */
/* @0x236a88 beq 0x236ab0 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0xd4> */
/* @0x236a8c mov r4, r9 */
/* @0x236a90 b 0x236a04 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0x28> */
/* @0x236a94 ldr r0, [pc, #0x28] */
/* @0x236a98 ldr r1, [r8, #0x1c] */
/* @0x236a9c add r0, pc, r0 */
/* @0x236aa0 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x236aa4 vpop {d8} */
/* @0x236aa8 mov r0, r6 */
/* @0x236aac pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x236ab0 vpop {d8} */
/* @0x236ab4 mov r6, #1 */
/* @0x236ab8 mov r0, r6 */
/* @0x236abc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x236ac0 strlt r12, [r7, -r12, lsr #11]! */
/* @0x236ac4 ldrsbeq lr, [r1], -r12 */

/* ── FUNC 0x236ac8 · CPhysicsFixture::AddShapePoint(float, float) · size=188 · insn=47 */
/* @0x236ac8 ldr r3, [r0, #0x20] */
/* @0x236acc push {r4, r5, lr} */
/* @0x236ad0 mov r4, r0 */
/* @0x236ad4 ldr r3, [r3] */
/* @0x236ad8 sub sp, sp, #12 */
/* @0x236adc mov r5, r1 */
/* @0x236ae0 ldr r3, [r3, #0x4] */
/* @0x236ae4 cmp r3, #2 */
/* @0x236ae8 beq 0x236b34 <_ZN15CPhysicsFixture13AddShapePointEff+0x6c> */
/* @0x236aec cmp r3, #3 */
/* @0x236af0 beq 0x236b00 <_ZN15CPhysicsFixture13AddShapePointEff+0x38> */
/* @0x236af4 mov r0, #0 */
/* @0x236af8 add sp, sp, #12 */
/* @0x236afc pop {r4, r5, pc} */
/* @0x236b00 ldr r3, [r0, #0xc] */
/* @0x236b04 ldr r1, [r0, #0x10] */
/* @0x236b08 cmp r3, r1 */
/* @0x236b0c bge 0x236b64 <_ZN15CPhysicsFixture13AddShapePointEff+0x9c> */
/* @0x236b10 ldr r1, [r4, #0x14] */
/* @0x236b14 add r12, r3, #1 */
/* @0x236b18 mov r0, #1 */
/* @0x236b1c str r12, [r4, #0xc] */
/* @0x236b20 add r3, r1, r3, lsl #3 */
/* @0x236b24 str r5, [r3] */
/* @0x236b28 str r2, [r3, #0x4] */
/* @0x236b2c add sp, sp, #12 */
/* @0x236b30 pop {r4, r5, pc} */
/* @0x236b34 ldr r3, [r0, #0xc] */
/* @0x236b38 cmp r3, #7 */
/* @0x236b3c bgt 0x236af4 <_ZN15CPhysicsFixture13AddShapePointEff+0x2c> */
/* @0x236b40 ldr r1, [r0, #0x14] */
/* @0x236b44 add r12, r3, #1 */
/* @0x236b48 str r12, [r0, #0xc] */
/* @0x236b4c add r3, r1, r3, lsl #3 */
/* @0x236b50 str r5, [r3] */
/* @0x236b54 str r2, [r3, #0x4] */
/* @0x236b58 add sp, sp, #12 */
/* @0x236b5c pop {r4, r5, lr} */
/* @0x236b60 b 0x2369dc <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv> */
/* @0x236b64 add r3, r3, r3, lsl #1 */
/* @0x236b68 str r2, [sp, #0x4] */
/* @0x236b6c add r1, r3, r3, lsr #31 */
/* @0x236b70 asr r1, r1, #1 */
/* @0x236b74 bl 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi> */
/* @0x236b78 ldr r3, [r4, #0xc] */
/* @0x236b7c ldr r2, [sp, #0x4] */
/* @0x236b80 b 0x236b10 <_ZN15CPhysicsFixture13AddShapePointEff+0x48> */

/* ── FUNC 0x236b84 · CPhysicsFixture::Finalise(CInstance*) · size=220 · insn=55 */
/* @0x236b84 push {r4, r5, lr} */
/* @0x236b88 sub sp, sp, #1024 */
/* @0x236b8c ldr r4, [pc, #0xc4] */
/* @0x236b90 sub sp, sp, #12 */
/* @0x236b94 ldr r12, [r0, #0x14] */
/* @0x236b98 mov r3, r0 */
/* @0x236b9c ldr r4, [pc, r4] */
/* @0x236ba0 cmp r12, #0 */
/* @0x236ba4 ldr r2, [r4] */
/* @0x236ba8 str r2, [sp, #0x404] */
/* @0x236bac beq 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48> */
/* @0x236bb0 ldr r2, [r0, #0x20] */
/* @0x236bb4 ldr r0, [r2] */
/* @0x236bb8 ldr r2, [r0, #0x4] */
/* @0x236bbc cmp r2, #2 */
/* @0x236bc0 beq 0x236c04 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x80> */
/* @0x236bc4 cmp r2, #3 */
/* @0x236bc8 beq 0x236be8 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x64> */
/* @0x236bcc ldr r2, [sp, #0x404] */
/* @0x236bd0 ldr r3, [r4] */
/* @0x236bd4 cmp r2, r3 */
/* @0x236bd8 bne 0x236c54 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0xd0> */
/* @0x236bdc add sp, sp, #1024 */
/* @0x236be0 add sp, sp, #12 */
/* @0x236be4 pop {r4, r5, pc} */
/* @0x236be8 ldrb r2, [r3, #0x19] */
/* @0x236bec mov r1, r12 */
/* @0x236bf0 cmp r2, #0 */
/* @0x236bf4 ldr r2, [r3, #0xc] */
/* @0x236bf8 bne 0x236c4c <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0xc8> */
/* @0x236bfc bl 0x2c4ae0 <_ZN12b2ChainShape11CreateChainEPK6b2Vec2i> */
/* @0x236c00 b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48> */
/* @0x236c04 ldr r2, [r3, #0xc] */
/* @0x236c08 cmp r2, #2 */
/* @0x236c0c bgt 0x236c40 <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0xbc> */
/* @0x236c10 ldr r3, [r1, #0x80] */
/* @0x236c14 add r5, sp, #4 */
/* @0x236c18 ldr r2, [pc, #0x3c] */
/* @0x236c1c mov r1, #1024 */
/* @0x236c20 mov r0, r5 */
/* @0x236c24 add r2, pc, r2 */
/* @0x236c28 ldr r3, [r3, #0x14] */
/* @0x236c2c bl 0xb65c8 <snprintf@plt> */
/* @0x236c30 mov r0, r5 */
/* @0x236c34 mov r1, #1 */
/* @0x236c38 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x236c3c b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48> */
/* @0x236c40 mov r1, r12 */
/* @0x236c44 bl 0x2c6028 <_ZN14b2PolygonShape3SetEPK6b2Vec2i> */
/* @0x236c48 b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48> */
/* @0x236c4c bl 0x2c4a68 <_ZN12b2ChainShape10CreateLoopEPK6b2Vec2i> */
/* @0x236c50 b 0x236bcc <_ZN15CPhysicsFixture8FinaliseEP9CInstance+0x48> */
/* @0x236c54 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x236c58 ldrheq r6, [r11], -r4 */
/* @0x236c5c andseq lr, r1, r4, lsr #11 */

/* ── FUNC 0x236c60 · CPhysicsObject::~CPhysicsObject() · size=368 · insn=92 */
/* @0x236c60 ldr r3, [pc, #0x164] */
/* @0x236c64 movw r2, #0xfeee */
/* @0x236c68 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x236c6c ldr r3, [pc, r3] */
/* @0x236c70 movt r2, #0xfeee */
/* @0x236c74 mov r7, r0 */
/* @0x236c78 ldr r3, [r3] */
/* @0x236c7c ldr r5, [r3, #0xb4] */
/* @0x236c80 cmp r5, r2 */
/* @0x236c84 cmpne r5, #0 */
/* @0x236c88 beq 0x236cd0 <_ZN14CPhysicsObjectD2Ev+0x70> */
/* @0x236c8c ldr r3, [r0] */
/* @0x236c90 ldr r4, [r3, #0x7c] */
/* @0x236c94 cmp r4, #0 */
/* @0x236c98 beq 0x236cc4 <_ZN14CPhysicsObjectD2Ev+0x64> */
/* @0x236c9c ldr r0, [r4, #0x4] */
/* @0x236ca0 ldr r4, [r4, #0xc] */
/* @0x236ca4 bl 0x23b47c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint> */
/* @0x236ca8 subs r3, r0, #0 */
/* @0x236cac mov r0, r5 */
/* @0x236cb0 beq 0x236c94 <_ZN14CPhysicsObjectD2Ev+0x34> */
/* @0x236cb4 ldr r1, [r3, #0x8] */
/* @0x236cb8 bl 0x237f90 <_ZN13CPhysicsWorld11DeleteJointEi> */
/* @0x236cbc cmp r4, #0 */
/* @0x236cc0 bne 0x236c9c <_ZN14CPhysicsObjectD2Ev+0x3c> */
/* @0x236cc4 mov r0, r5 */
/* @0x236cc8 mov r1, r7 */
/* @0x236ccc bl 0x238c08 <_ZN13CPhysicsWorld11DestroyBodyEP14CPhysicsObject> */
/* @0x236cd0 ldr r4, [r7, #0x1c] */
/* @0x236cd4 ldr r8, [r4, #0x4] */
/* @0x236cd8 cmp r8, #0 */
/* @0x236cdc blt 0x236dc4 <_ZN14CPhysicsObjectD2Ev+0x164> */
/* @0x236ce0 lsl r6, r8, #3 */
/* @0x236ce4 mov r9, #0 */
/* @0x236ce8 ldr r3, [r4] */
/* @0x236cec add r2, r3, r6 */
/* @0x236cf0 ldr r0, [r3, r6] */
/* @0x236cf4 str r9, [r3, r6] */
/* @0x236cf8 cmp r0, #0 */
/* @0x236cfc str r9, [r2, #0x4] */
/* @0x236d00 beq 0x236d24 <_ZN14CPhysicsObjectD2Ev+0xc4> */
/* @0x236d04 ldr r5, [r0, #0x4] */
/* @0x236d08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236d0c ldr r3, [r4, #0x8] */
/* @0x236d10 cmp r5, #0 */
/* @0x236d14 sub r3, r3, #1 */
/* @0x236d18 mov r0, r5 */
/* @0x236d1c str r3, [r4, #0x8] */
/* @0x236d20 bne 0x236d04 <_ZN14CPhysicsObjectD2Ev+0xa4> */
/* @0x236d24 sub r8, r8, #1 */
/* @0x236d28 sub r6, r6, #8 */
/* @0x236d2c cmn r8, #1 */
/* @0x236d30 bne 0x236ce8 <_ZN14CPhysicsObjectD2Ev+0x88> */
/* @0x236d34 ldr r4, [r7, #0x1c] */
/* @0x236d38 cmp r4, #0 */
/* @0x236d3c beq 0x236dbc <_ZN14CPhysicsObjectD2Ev+0x15c> */
/* @0x236d40 ldr r9, [r4, #0x4] */
/* @0x236d44 cmp r9, #0 */
/* @0x236d48 blt 0x236dc4 <_ZN14CPhysicsObjectD2Ev+0x164> */
/* @0x236d4c ldr r0, [r4] */
/* @0x236d50 lsl r8, r9, #3 */
/* @0x236d54 mov r10, #0 */
/* @0x236d58 ldr r5, [r0, r8] */
/* @0x236d5c add r3, r0, r8 */
/* @0x236d60 str r10, [r0, r8] */
/* @0x236d64 cmp r5, #0 */
/* @0x236d68 str r10, [r3, #0x4] */
/* @0x236d6c beq 0x236da0 <_ZN14CPhysicsObjectD2Ev+0x140> */
/* @0x236d70 ldr r6, [r5, #0x4] */
/* @0x236d74 ldr r0, [r5, #0xc] */
/* @0x236d78 bl 0x27d1d0 <_ZdlPv> */
/* @0x236d7c mov r0, r5 */
/* @0x236d80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236d84 ldr r3, [r4, #0x8] */
/* @0x236d88 cmp r6, #0 */
/* @0x236d8c mov r5, r6 */
/* @0x236d90 sub r3, r3, #1 */
/* @0x236d94 str r3, [r4, #0x8] */
/* @0x236d98 bne 0x236d70 <_ZN14CPhysicsObjectD2Ev+0x110> */
/* @0x236d9c ldr r0, [r4] */
/* @0x236da0 sub r9, r9, #1 */
/* @0x236da4 sub r8, r8, #8 */
/* @0x236da8 cmn r9, #1 */
/* @0x236dac bne 0x236d58 <_ZN14CPhysicsObjectD2Ev+0xf8> */
/* @0x236db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x236db4 mov r0, r4 */
/* @0x236db8 bl 0x27d1d0 <_ZdlPv> */
/* @0x236dbc mov r0, r7 */
/* @0x236dc0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x236dc4 ldr r0, [r4] */
/* @0x236dc8 b 0x236db0 <_ZN14CPhysicsObjectD2Ev+0x150> */
/* @0x236dcc ldrheq r6, [r11], -r12 */

/* ── FUNC 0x236c60 · CPhysicsObject::~CPhysicsObject() · alias of the symbol above · insn=0 */

/* ── FUNC 0x236dd0 · CPhysicsObject::SetMass(float, float, float, float) · size=48 · insn=12 */
/* @0x236dd0 str lr, [sp, #-0x4]! */
/* @0x236dd4 sub sp, sp, #20 */
/* @0x236dd8 ldr r0, [r0] */
/* @0x236ddc ldr r12, [sp, #0x18] */
/* @0x236de0 str r1, [sp] */
/* @0x236de4 mov r1, sp */
/* @0x236de8 str r2, [sp, #0x4] */
/* @0x236dec str r3, [sp, #0x8] */
/* @0x236df0 str r12, [sp, #0xc] */
/* @0x236df4 bl 0x2c7030 <_ZN6b2Body11SetMassDataEPK10b2MassData> */
/* @0x236df8 add sp, sp, #20 */
/* @0x236dfc ldr pc, [sp], #4 */

/* ── FUNC 0x236e00 · CPhysicsObject::SetPosition(float, float) · size=72 · insn=18 */
/* @0x236e00 push {r4, lr} */
/* @0x236e04 mov r4, r0 */
/* @0x236e08 ldr r0, [r0] */
/* @0x236e0c sub sp, sp, #8 */
/* @0x236e10 str r1, [sp] */
/* @0x236e14 mov r1, sp */
/* @0x236e18 str r2, [sp, #0x4] */
/* @0x236e1c ldr r2, [r0, #0x48] */
/* @0x236e20 bl 0x2c71c4 <_ZN6b2Body12SetTransformERK6b2Vec2f> */
/* @0x236e24 ldr r3, [r4] */
/* @0x236e28 ldrh r2, [r3, #4] */
/* @0x236e2c tst r2, #2 */
/* @0x236e30 orreq r2, r2, #2 */
/* @0x236e34 strheq r2, [r3, #4] */
/* @0x236e38 moveq r1, #0 */
/* @0x236e3c streq r1, [r3, #0xa0] */
/* @0x236e40 add sp, sp, #8 */
/* @0x236e44 pop {r4, pc} */

/* ── FUNC 0x236e48 · CPhysicsObject::SetRotation(float) · size=84 · insn=21 */
/* @0x236e48 vmov s15, r1 */
/* @0x236e4c vldr s14, [pc, #64] */
/* @0x236e50 push {r4, lr} */
/* @0x236e54 vmul.f32 s14, s15, s14 */
/* @0x236e58 vldr s15, [pc, #56] */
/* @0x236e5c mov r4, r0 */
/* @0x236e60 ldr r0, [r0] */
/* @0x236e64 add r1, r0, #12 */
/* @0x236e68 vdiv.f32 s15, s14, s15 */
/* @0x236e6c vmov r2, s15 */
/* @0x236e70 bl 0x2c71c4 <_ZN6b2Body12SetTransformERK6b2Vec2f> */
/* @0x236e74 ldr r3, [r4] */
/* @0x236e78 ldrh r2, [r3, #4] */
/* @0x236e7c tst r2, #2 */
/* @0x236e80 orreq r2, r2, #2 */
/* @0x236e84 strheq r2, [r3, #4] */
/* @0x236e88 moveq r1, #0 */
/* @0x236e8c streq r1, [r3, #0xa0] */
/* @0x236e90 pop {r4, pc} */
/* @0x236e94 ldrdmi r0, r1, [r9], #-251 */
/* @0x236e98 teqmi r4, #0 */

/* ── FUNC 0x236e9c · CPhysicsObject::SetLinearVelocity(float, float) · size=168 · insn=42 */
/* @0x236e9c push {r4, lr} */
/* @0x236ea0 vpush {d8} */
/* @0x236ea4 vmov s17, r2 */
/* @0x236ea8 vmov s16, r1 */
/* @0x236eac mov r4, r0 */
/* @0x236eb0 vmul.f32 s15, s17, s17 */
/* @0x236eb4 ldr r0, [r0] */
/* @0x236eb8 ldr r2, [r0] */
/* @0x236ebc vmla.f32 s15, s16, s16 */
/* @0x236ec0 vcmpe.f32 s15, #0 */
/* @0x236ec4 vmrs APSR_nzcv, fpscr */
/* @0x236ec8 ble 0x236f2c <_ZN14CPhysicsObject17SetLinearVelocityEff+0x90> */
/* @0x236ecc cmp r2, #0 */
/* @0x236ed0 bne 0x236eec <_ZN14CPhysicsObject17SetLinearVelocityEff+0x50> */
/* @0x236ed4 mov r1, #1 */
/* @0x236ed8 bl 0x2c7378 <_ZN6b2Body7SetTypeE10b2BodyType> */
/* @0x236edc ldr r0, [r4] */
/* @0x236ee0 ldr r2, [r0] */
/* @0x236ee4 cmp r2, #0 */
/* @0x236ee8 beq 0x236f0c <_ZN14CPhysicsObject17SetLinearVelocityEff+0x70> */
/* @0x236eec ldrh r2, [r0, #4] */
/* @0x236ef0 tst r2, #2 */
/* @0x236ef4 orreq r2, r2, #2 */
/* @0x236ef8 strheq r2, [r0, #4] */
/* @0x236efc moveq r1, #0 */
/* @0x236f00 streq r1, [r0, #0xa0] */
/* @0x236f04 vstr s16, [r0, #80] */
/* @0x236f08 vstr s17, [r0, #84] */
/* @0x236f0c ldrh r2, [r0, #4] */
/* @0x236f10 tst r2, #2 */
/* @0x236f14 orreq r2, r2, #2 */
/* @0x236f18 moveq r1, #0 */
/* @0x236f1c strheq r2, [r0, #4] */
/* @0x236f20 streq r1, [r0, #0xa0] */
/* @0x236f24 vpop {d8} */
/* @0x236f28 pop {r4, pc} */
/* @0x236f2c cmp r2, #0 */
/* @0x236f30 beq 0x236f0c <_ZN14CPhysicsObject17SetLinearVelocityEff+0x70> */
/* @0x236f34 vcmpe.f32 s15, #0 */
/* @0x236f38 vmrs APSR_nzcv, fpscr */
/* @0x236f3c bgt 0x236eec <_ZN14CPhysicsObject17SetLinearVelocityEff+0x50> */
/* @0x236f40 b 0x236f04 <_ZN14CPhysicsObject17SetLinearVelocityEff+0x68> */

/* ── FUNC 0x236f44 · CPhysicsObject::SetAngularVelocity(float) · size=140 · insn=35 */
/* @0x236f44 ldr r3, [r0] */
/* @0x236f48 vmov s15, r1 */
/* @0x236f4c ldr r2, [r3] */
/* @0x236f50 cmp r2, #0 */
/* @0x236f54 beq 0x236fb8 <_ZN14CPhysicsObject18SetAngularVelocityEf+0x74> */
/* @0x236f58 vldr s14, [pc, #104] */
/* @0x236f5c vmul.f32 s15, s15, s14 */
/* @0x236f60 vldr s14, [pc, #100] */
/* @0x236f64 ldrh r1, [r3, #4] */
/* @0x236f68 mov r0, #0 */
/* @0x236f6c and r2, r1, #2 */
/* @0x236f70 uxth r2, r2 */
/* @0x236f74 vdiv.f32 s15, s15, s14 */
/* @0x236f78 vmul.f32 s14, s15, s15 */
/* @0x236f7c vcmpe.f32 s14, #0 */
/* @0x236f80 vmrs APSR_nzcv, fpscr */
/* @0x236f84 ble 0x236f9c <_ZN14CPhysicsObject18SetAngularVelocityEf+0x58> */
/* @0x236f88 cmp r2, #0 */
/* @0x236f8c streq r0, [r3, #0xa0] */
/* @0x236f90 orreq r1, r1, #2 */
/* @0x236f94 strheq r1, [r3, #4] */
/* @0x236f98 moveq r2, #2 */
/* @0x236f9c vstr s15, [r3, #88] */
/* @0x236fa0 cmp r2, #0 */
/* @0x236fa4 orreq r1, r1, #2 */
/* @0x236fa8 strheq r1, [r3, #4] */
/* @0x236fac moveq r2, #0 */
/* @0x236fb0 streq r2, [r3, #0xa0] */
/* @0x236fb4 bx lr */
/* @0x236fb8 ldrh r1, [r3, #4] */
/* @0x236fbc and r2, r1, #2 */
/* @0x236fc0 uxth r2, r2 */
/* @0x236fc4 b 0x236fa0 <_ZN14CPhysicsObject18SetAngularVelocityEf+0x5c> */
/* @0x236fc8 ldrdmi r0, r1, [r9], #-251 */
/* @0x236fcc teqmi r4, #0 */

/* ── FUNC 0x236fd0 · CPhysicsObject::ApplyImpulse(float, float, float, float) · size=136 · insn=34 */
/* @0x236fd0 ldr r0, [r0] */
/* @0x236fd4 vmov s15, r3 */
/* @0x236fd8 vmov s14, r1 */
/* @0x236fdc vmov s13, r2 */
/* @0x236fe0 ldr r3, [r0] */
/* @0x236fe4 cmp r3, #2 */
/* @0x236fe8 bxne lr */
/* @0x236fec ldrh r3, [r0, #4] */
/* @0x236ff0 tst r3, #2 */
/* @0x236ff4 beq 0x237044 <_ZN14CPhysicsObject12ApplyImpulseEffff+0x74> */
/* @0x236ff8 vldr s12, [r0, #64] */
/* @0x236ffc vsub.f32 s13, s13, s12 */
/* @0x237000 vldr s7, [r0, #60] */
/* @0x237004 vldr s11, [r0, #88] */
/* @0x237008 vldr s9, [r0, #136] */
/* @0x23700c vldr s10, [r0, #80] */
/* @0x237010 vldr s12, [r0, #84] */
/* @0x237014 vldr s8, [r0, #144] */
/* @0x237018 vmul.f32 s13, s15, s13 */
/* @0x23701c vsub.f32 s14, s14, s7 */
/* @0x237020 vldr s7, [sp] */
/* @0x237024 vnmls.f32 s13, s7, s14 */
/* @0x237028 vmla.f32 s10, s15, s9 */
/* @0x23702c vmla.f32 s11, s13, s8 */
/* @0x237030 vstr s10, [r0, #80] */
/* @0x237034 vmla.f32 s12, s7, s9 */
/* @0x237038 vstr s11, [r0, #88] */
/* @0x23703c vstr s12, [r0, #84] */
/* @0x237040 bx lr */
/* @0x237044 orr r3, r3, #2 */
/* @0x237048 mov r2, #0 */
/* @0x23704c strh r3, [r0, #4] */
/* @0x237050 str r2, [r0, #0xa0] */
/* @0x237054 b 0x236ff8 <_ZN14CPhysicsObject12ApplyImpulseEffff+0x28> */

/* ── FUNC 0x237058 · CPhysicsObject::ApplyForce(float, float, float, float) · size=128 · insn=32 */
/* @0x237058 ldr r0, [r0] */
/* @0x23705c vmov s15, r3 */
/* @0x237060 vmov s14, r1 */
/* @0x237064 vmov s13, r2 */
/* @0x237068 ldr r3, [r0] */
/* @0x23706c cmp r3, #2 */
/* @0x237070 bxne lr */
/* @0x237074 ldrh r3, [r0, #4] */
/* @0x237078 tst r3, #2 */
/* @0x23707c beq 0x2370c4 <_ZN14CPhysicsObject10ApplyForceEffff+0x6c> */
/* @0x237080 vldr s12, [r0, #64] */
/* @0x237084 vsub.f32 s13, s13, s12 */
/* @0x237088 vldr s9, [r0, #60] */
/* @0x23708c vldr s10, [r0, #92] */
/* @0x237090 vldr s11, [r0, #100] */
/* @0x237094 vldr s12, [r0, #96] */
/* @0x237098 vmul.f32 s13, s15, s13 */
/* @0x23709c vsub.f32 s14, s14, s9 */
/* @0x2370a0 vldr s9, [sp] */
/* @0x2370a4 vnmls.f32 s13, s9, s14 */
/* @0x2370a8 vadd.f32 s15, s10, s15 */
/* @0x2370ac vadd.f32 s13, s11, s13 */
/* @0x2370b0 vstr s15, [r0, #92] */
/* @0x2370b4 vadd.f32 s15, s12, s9 */
/* @0x2370b8 vstr s13, [r0, #100] */
/* @0x2370bc vstr s15, [r0, #96] */
/* @0x2370c0 bx lr */
/* @0x2370c4 orr r3, r3, #2 */
/* @0x2370c8 mov r2, #0 */
/* @0x2370cc strh r3, [r0, #4] */
/* @0x2370d0 str r2, [r0, #0xa0] */
/* @0x2370d4 b 0x237080 <_ZN14CPhysicsObject10ApplyForceEffff+0x28> */

/* ── FUNC 0x2370d8 · CPhysicsObject::ApplyLocalForce(float, float, float, float) · size=184 · insn=46 */
/* @0x2370d8 ldr r0, [r0] */
/* @0x2370dc vmov s13, r1 */
/* @0x2370e0 vldr s15, [r0, #24] */
/* @0x2370e4 vldr s14, [r0, #20] */
/* @0x2370e8 vldr s9, [r0, #12] */
/* @0x2370ec vldr s8, [r0, #16] */
/* @0x2370f0 ldr r1, [r0] */
/* @0x2370f4 vmov s12, r2 */
/* @0x2370f8 vmov s11, r3 */
/* @0x2370fc cmp r1, #2 */
/* @0x237100 bxne lr */
/* @0x237104 ldrh r3, [r0, #4] */
/* @0x237108 tst r3, #2 */
/* @0x23710c beq 0x23717c <_ZN14CPhysicsObject15ApplyLocalForceEffff+0xa4> */
/* @0x237110 vmul.f32 s7, s12, s15 */
/* @0x237114 vldr s1, [sp] */
/* @0x237118 vldr s2, [r0, #64] */
/* @0x23711c vldr s3, [r0, #60] */
/* @0x237120 vldr s5, [r0, #100] */
/* @0x237124 vldr s4, [r0, #92] */
/* @0x237128 vldr s6, [r0, #96] */
/* @0x23712c vmla.f32 s7, s13, s14 */
/* @0x237130 vmul.f32 s12, s12, s14 */
/* @0x237134 vmul.f32 s10, s1, s14 */
/* @0x237138 vnmls.f32 s12, s13, s15 */
/* @0x23713c vnmls.f32 s10, s11, s15 */
/* @0x237140 vmul.f32 s15, s1, s15 */
/* @0x237144 vadd.f32 s8, s7, s8 */
/* @0x237148 vsub.f32 s8, s8, s2 */
/* @0x23714c vmla.f32 s15, s11, s14 */
/* @0x237150 vadd.f32 s12, s12, s9 */
/* @0x237154 vmul.f32 s8, s10, s8 */
/* @0x237158 vsub.f32 s12, s12, s3 */
/* @0x23715c vnmls.f32 s8, s15, s12 */
/* @0x237160 vadd.f32 s10, s4, s10 */
/* @0x237164 vadd.f32 s8, s5, s8 */
/* @0x237168 vstr s10, [r0, #92] */
/* @0x23716c vadd.f32 s15, s6, s15 */
/* @0x237170 vstr s8, [r0, #100] */
/* @0x237174 vstr s15, [r0, #96] */
/* @0x237178 bx lr */
/* @0x23717c orr r3, r3, #2 */
/* @0x237180 mov r2, #0 */
/* @0x237184 strh r3, [r0, #4] */
/* @0x237188 str r2, [r0, #0xa0] */
/* @0x23718c b 0x237110 <_ZN14CPhysicsObject15ApplyLocalForceEffff+0x38> */

/* ── FUNC 0x237190 · CPhysicsObject::ApplyLocalImpulse(float, float, float, float) · size=208 · insn=52 */
/* @0x237190 ldr r0, [r0] */
/* @0x237194 vmov s13, r1 */
/* @0x237198 vpush {d8} */
/* @0x23719c vldr s15, [r0, #24] */
/* @0x2371a0 vldr s14, [r0, #20] */
/* @0x2371a4 vldr s9, [r0, #12] */
/* @0x2371a8 ldr r1, [r0] */
/* @0x2371ac vldr s8, [r0, #16] */
/* @0x2371b0 vmov s12, r2 */
/* @0x2371b4 cmp r1, #2 */
/* @0x2371b8 vmov s11, r3 */
/* @0x2371bc beq 0x2371c8 <_ZN14CPhysicsObject17ApplyLocalImpulseEffff+0x38> */
/* @0x2371c0 vpop {d8} */
/* @0x2371c4 bx lr */
/* @0x2371c8 ldrh r3, [r0, #4] */
/* @0x2371cc tst r3, #2 */
/* @0x2371d0 beq 0x23724c <_ZN14CPhysicsObject17ApplyLocalImpulseEffff+0xbc> */
/* @0x2371d4 vmul.f32 s4, s12, s15 */
/* @0x2371d8 vldr s16, [sp, #8] */
/* @0x2371dc vldr s0, [r0, #64] */
/* @0x2371e0 vldr s1, [r0, #60] */
/* @0x2371e4 vldr s6, [r0, #88] */
/* @0x2371e8 vldr s3, [r0, #136] */
/* @0x2371ec vldr s5, [r0, #80] */
/* @0x2371f0 vldr s7, [r0, #84] */
/* @0x2371f4 vldr s2, [r0, #144] */
/* @0x2371f8 vmla.f32 s4, s13, s14 */
/* @0x2371fc vmul.f32 s12, s12, s14 */
/* @0x237200 vmul.f32 s10, s16, s14 */
/* @0x237204 vnmls.f32 s12, s13, s15 */
/* @0x237208 vnmls.f32 s10, s11, s15 */
/* @0x23720c vmul.f32 s15, s16, s15 */
/* @0x237210 vpop {d8} */
/* @0x237214 vadd.f32 s8, s4, s8 */
/* @0x237218 vsub.f32 s8, s8, s0 */
/* @0x23721c vmla.f32 s15, s11, s14 */
/* @0x237220 vadd.f32 s12, s12, s9 */
/* @0x237224 vmul.f32 s8, s10, s8 */
/* @0x237228 vsub.f32 s12, s12, s1 */
/* @0x23722c vnmls.f32 s8, s15, s12 */
/* @0x237230 vmla.f32 s5, s10, s3 */
/* @0x237234 vmla.f32 s6, s8, s2 */
/* @0x237238 vstr s5, [r0, #80] */
/* @0x23723c vmla.f32 s7, s15, s3 */
/* @0x237240 vstr s6, [r0, #88] */
/* @0x237244 vstr s7, [r0, #84] */
/* @0x237248 bx lr */
/* @0x23724c orr r3, r3, #2 */
/* @0x237250 mov r2, #0 */
/* @0x237254 strh r3, [r0, #4] */
/* @0x237258 str r2, [r0, #0xa0] */
/* @0x23725c b 0x2371d4 <_ZN14CPhysicsObject17ApplyLocalImpulseEffff+0x44> */

/* ── FUNC 0x237260 · CPhysicsObject::ApplyTorque(float) · size=68 · insn=17 */
/* @0x237260 ldr r3, [r0] */
/* @0x237264 vmov s15, r1 */
/* @0x237268 ldr r2, [r3] */
/* @0x23726c cmp r2, #2 */
/* @0x237270 bxne lr */
/* @0x237274 ldrh r2, [r3, #4] */
/* @0x237278 tst r2, #2 */
/* @0x23727c beq 0x237290 <_ZN14CPhysicsObject11ApplyTorqueEf+0x30> */
/* @0x237280 vldr s14, [r3, #100] */
/* @0x237284 vadd.f32 s15, s14, s15 */
/* @0x237288 vstr s15, [r3, #100] */
/* @0x23728c bx lr */
/* @0x237290 orr r2, r2, #2 */
/* @0x237294 mov r1, #0 */
/* @0x237298 strh r2, [r3, #4] */
/* @0x23729c str r1, [r3, #0xa0] */
/* @0x2372a0 b 0x237280 <_ZN14CPhysicsObject11ApplyTorqueEf+0x20> */

/* ── FUNC 0x2372a4 · CPhysicsObject::ApplyAngularImpulse(float) · size=72 · insn=18 */
/* @0x2372a4 ldr r3, [r0] */
/* @0x2372a8 vmov s15, r1 */
/* @0x2372ac ldr r2, [r3] */
/* @0x2372b0 cmp r2, #2 */
/* @0x2372b4 bxne lr */
/* @0x2372b8 ldrh r2, [r3, #4] */
/* @0x2372bc tst r2, #2 */
/* @0x2372c0 beq 0x2372d8 <_ZN14CPhysicsObject19ApplyAngularImpulseEf+0x34> */
/* @0x2372c4 vldr s14, [r3, #88] */
/* @0x2372c8 vldr s13, [r3, #144] */
/* @0x2372cc vmla.f32 s14, s15, s13 */
/* @0x2372d0 vstr s14, [r3, #88] */
/* @0x2372d4 bx lr */
/* @0x2372d8 orr r2, r2, #2 */
/* @0x2372dc mov r1, #0 */
/* @0x2372e0 strh r2, [r3, #4] */
/* @0x2372e4 str r1, [r3, #0xa0] */
/* @0x2372e8 b 0x2372c4 <_ZN14CPhysicsObject19ApplyAngularImpulseEf+0x20> */

/* ── FUNC 0x2372ec · CPhysicsObject::DebugRenderShapes(float) · size=380 · insn=95 */
/* @0x2372ec ldr r3, [r0] */
/* @0x2372f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2372f4 vpush {d8, d9} */
/* @0x2372f8 mov r9, r0 */
/* @0x2372fc ldr r7, [r3, #0x74] */
/* @0x237300 sub sp, sp, #12 */
/* @0x237304 vmov s16, r1 */
/* @0x237308 cmp r7, #0 */
/* @0x23730c beq 0x237404 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x118> */
/* @0x237310 mov r10, #1 */
/* @0x237314 ldr r6, [r7, #0xc] */
/* @0x237318 ldr r3, [r6, #0x4] */
/* @0x23731c cmp r3, #0 */
/* @0x237320 beq 0x237410 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x124> */
/* @0x237324 cmp r3, #2 */
/* @0x237328 bne 0x2373f8 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x10c> */
/* @0x23732c ldr r11, [r9] */
/* @0x237330 add r8, r6, #20 */
/* @0x237334 ldr r4, [r11, #0x48] */
/* @0x237338 mov r0, r4 */
/* @0x23733c bl 0xb6580 <sinf@plt> */
/* @0x237340 vmov s17, r0 */
/* @0x237344 mov r0, r4 */
/* @0x237348 bl 0xb658c <cosf@plt> */
/* @0x23734c ldr r1, [r6, #0x94] */
/* @0x237350 cmp r1, #0 */
/* @0x237354 vmov s18, r0 */
/* @0x237358 ble 0x2373f8 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x10c> */
/* @0x23735c mov r5, r8 */
/* @0x237360 mov r4, #0 */
/* @0x237364 b 0x23736c <_ZN14CPhysicsObject17DebugRenderShapesEf+0x80> */
/* @0x237368 ldr r11, [r9] */
/* @0x23736c add r4, r4, #1 */
/* @0x237370 add r5, r5, #8 */
/* @0x237374 mov r0, r4 */
/* @0x237378 bl 0x318dec <__aeabi_idivmod> */
/* @0x23737c vldr s15, [r5, #-4] */
/* @0x237380 vmul.f32 s13, s15, s17 */
/* @0x237384 vldr s9, [r5, #-8] */
/* @0x237388 vldr s10, [r11, #12] */
/* @0x23738c vldr s11, [r11, #16] */
/* @0x237390 vmul.f32 s15, s18, s15 */
/* @0x237394 vnmls.f32 s13, s9, s18 */
/* @0x237398 add r1, r8, r1, lsl #3 */
/* @0x23739c vldr s14, [r1, #4] */
/* @0x2373a0 vldr s8, [r1] */
/* @0x2373a4 vmul.f32 s12, s14, s17 */
/* @0x2373a8 vmul.f32 s14, s18, s14 */
/* @0x2373ac vnmls.f32 s12, s8, s18 */
/* @0x2373b0 vmla.f32 s14, s17, s8 */
/* @0x2373b4 vmla.f32 s15, s17, s9 */
/* @0x2373b8 vadd.f32 s12, s10, s12 */
/* @0x2373bc vadd.f32 s13, s10, s13 */
/* @0x2373c0 vadd.f32 s14, s11, s14 */
/* @0x2373c4 vadd.f32 s15, s11, s15 */
/* @0x2373c8 vmul.f32 s12, s12, s16 */
/* @0x2373cc vmul.f32 s14, s14, s16 */
/* @0x2373d0 vmov r2, s12 */
/* @0x2373d4 vmul.f32 s13, s13, s16 */
/* @0x2373d8 vmov r3, s14 */
/* @0x2373dc vmul.f32 s15, s15, s16 */
/* @0x2373e0 vmov r0, s13 */
/* @0x2373e4 vmov r1, s15 */
/* @0x2373e8 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x2373ec ldr r1, [r6, #0x94] */
/* @0x2373f0 cmp r1, r4 */
/* @0x2373f4 bgt 0x237368 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x7c> */
/* @0x2373f8 ldr r7, [r7, #0x4] */
/* @0x2373fc cmp r7, #0 */
/* @0x237400 bne 0x237314 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x28> */
/* @0x237404 add sp, sp, #12 */
/* @0x237408 vpop {d8, d9} */
/* @0x23740c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x237410 vldr s15, [r6, #8] */
/* @0x237414 ldr r3, [r9] */
/* @0x237418 vldr s13, [r3, #12] */
/* @0x23741c vldr s14, [r3, #16] */
/* @0x237420 vsub.f32 s11, s13, s15 */
/* @0x237424 str r10, [sp] */
/* @0x237428 vsub.f32 s12, s14, s15 */
/* @0x23742c vadd.f32 s13, s13, s15 */
/* @0x237430 vadd.f32 s15, s15, s14 */
/* @0x237434 vmul.f32 s11, s11, s16 */
/* @0x237438 vmul.f32 s13, s13, s16 */
/* @0x23743c vmov r0, s11 */
/* @0x237440 vmul.f32 s12, s12, s16 */
/* @0x237444 vmov r2, s13 */
/* @0x237448 vmul.f32 s15, s15, s16 */
/* @0x23744c vmov r1, s12 */
/* @0x237450 vmov r3, s15 */
/* @0x237454 bl 0x16b278 <_Z15GR_Draw_Ellipseffffb> */
/* @0x237458 ldr r7, [r7, #0x4] */
/* @0x23745c cmp r7, #0 */
/* @0x237460 bne 0x237314 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x28> */
/* @0x237464 b 0x237404 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x118> */

/* ── FUNC 0x237468 · CPhysicsObject::DebugRenderJoints(float) · size=628 · insn=157 */
/* @0x237468 ldr r3, [r0] */
/* @0x23746c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x237470 vpush {d8, d9, d10} */
/* @0x237474 mov r6, r0 */
/* @0x237478 ldr r10, [r3, #0x7c] */
/* @0x23747c sub sp, sp, #68 */
/* @0x237480 vmov s16, r1 */
/* @0x237484 cmp r10, #0 */
/* @0x237488 beq 0x2375a4 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x13c> */
/* @0x23748c add r9, sp, #32 */
/* @0x237490 add r8, sp, #40 */
/* @0x237494 add r7, sp, #48 */
/* @0x237498 add r5, sp, #56 */
/* @0x23749c add r11, sp, #16 */
/* @0x2374a0 add r3, sp, #24 */
/* @0x2374a4 str r3, [sp, #0x4] */
/* @0x2374a8 ldr r4, [r10, #0x4] */
/* @0x2374ac ldr r3, [r4, #0x4] */
/* @0x2374b0 sub r3, r3, #1 */
/* @0x2374b4 cmp r3, #3 */
/* @0x2374b8 addls pc, pc, r3, lsl #2 */
/* @0x2374bc b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130> */
/* @0x2374c0 b 0x237600 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x198> */
/* @0x2374c4 b 0x2375b0 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x148> */
/* @0x2374c8 b 0x237664 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x1fc> */
/* @0x2374cc b 0x2374d0 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x68> */
/* @0x2374d0 ldr r3, [r6] */
/* @0x2374d4 mov r0, r11 */
/* @0x2374d8 ldr r2, [r4, #0x30] */
/* @0x2374dc mov r1, r4 */
/* @0x2374e0 cmp r2, r3 */
/* @0x2374e4 ldr r3, [r4] */
/* @0x2374e8 beq 0x2376c4 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x25c> */
/* @0x2374ec ldr r3, [r3, #0x4] */
/* @0x2374f0 blx r3 */
/* @0x2374f4 add r0, sp, #24 */
/* @0x2374f8 mov r1, r4 */
/* @0x2374fc bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv> */
/* @0x237500 vldr s12, [sp, #16] */
/* @0x237504 vldr s13, [sp, #20] */
/* @0x237508 vmul.f32 s12, s16, s12 */
/* @0x23750c vldr s14, [sp, #24] */
/* @0x237510 vldr s15, [sp, #28] */
/* @0x237514 vmul.f32 s13, s16, s13 */
/* @0x237518 vmov r0, s12 */
/* @0x23751c vmul.f32 s15, s16, s15 */
/* @0x237520 vmov r1, s13 */
/* @0x237524 vmul.f32 s14, s16, s14 */
/* @0x237528 vmov r3, s15 */
/* @0x23752c vmov r2, s14 */
/* @0x237530 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x237534 mov r0, r9 */
/* @0x237538 mov r1, r4 */
/* @0x23753c bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv> */
/* @0x237540 mov r0, r8 */
/* @0x237544 mov r1, r4 */
/* @0x237548 vldr s19, [sp, #32] */
/* @0x23754c bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv> */
/* @0x237550 mov r0, r7 */
/* @0x237554 mov r1, r4 */
/* @0x237558 vldr s18, [sp, #44] */
/* @0x23755c bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv> */
/* @0x237560 mov r1, r4 */
/* @0x237564 mov r0, r5 */
/* @0x237568 vldr s17, [sp, #48] */
/* @0x23756c vmul.f32 s19, s16, s19 */
/* @0x237570 bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv> */
/* @0x237574 vldr s15, [sp, #60] */
/* @0x237578 vmul.f32 s18, s16, s18 */
/* @0x23757c vmov r0, s19 */
/* @0x237580 vmul.f32 s17, s16, s17 */
/* @0x237584 vmov r1, s18 */
/* @0x237588 vmul.f32 s15, s16, s15 */
/* @0x23758c vmov r2, s17 */
/* @0x237590 vmov r3, s15 */
/* @0x237594 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x237598 ldr r10, [r10, #0xc] */
/* @0x23759c cmp r10, #0 */
/* @0x2375a0 bne 0x2374a8 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x40> */
/* @0x2375a4 add sp, sp, #68 */
/* @0x2375a8 vpop {d8, d9, d10} */
/* @0x2375ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2375b0 ldr r3, [r4] */
/* @0x2375b4 mov r1, r4 */
/* @0x2375b8 mov r0, r5 */
/* @0x2375bc ldr r3, [r3] */
/* @0x2375c0 blx r3 */
/* @0x2375c4 ldr r3, [r6] */
/* @0x2375c8 vldr s14, [sp, #56] */
/* @0x2375cc vldr s15, [sp, #60] */
/* @0x2375d0 vldr s12, [r3, #12] */
/* @0x2375d4 vldr s13, [r3, #16] */
/* @0x2375d8 vmul.f32 s12, s16, s12 */
/* @0x2375dc vmul.f32 s13, s16, s13 */
/* @0x2375e0 vmov r2, s12 */
/* @0x2375e4 vmul.f32 s14, s16, s14 */
/* @0x2375e8 vmov r3, s13 */
/* @0x2375ec vmul.f32 s15, s16, s15 */
/* @0x2375f0 vmov r0, s14 */
/* @0x2375f4 vmov r1, s15 */
/* @0x2375f8 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x2375fc b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130> */
/* @0x237600 ldr r3, [r4] */
/* @0x237604 mov r1, r4 */
/* @0x237608 add r0, sp, #8 */
/* @0x23760c ldr r3, [r3] */
/* @0x237610 blx r3 */
/* @0x237614 vldr s18, [sp, #8] */
/* @0x237618 vldr s19, [sp, #12] */
/* @0x23761c vmul.f32 s18, s16, s18 */
/* @0x237620 vmul.f32 s19, s16, s19 */
/* @0x237624 vmov.f32 s15, #2.000000e+00 */
/* @0x237628 vsub.f32 s20, s18, s15 */
/* @0x23762c vsub.f32 s17, s19, s15 */
/* @0x237630 vmov r0, s20 */
/* @0x237634 vadd.f32 s18, s18, s15 */
/* @0x237638 vmov r1, s17 */
/* @0x23763c vadd.f32 s19, s19, s15 */
/* @0x237640 vmov r2, s18 */
/* @0x237644 vmov r3, s19 */
/* @0x237648 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x23764c vmov r0, s20 */
/* @0x237650 vmov r1, s19 */
/* @0x237654 vmov r2, s18 */
/* @0x237658 vmov r3, s17 */
/* @0x23765c bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x237660 b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130> */
/* @0x237664 ldr r3, [r4] */
/* @0x237668 mov r0, r7 */
/* @0x23766c mov r1, r4 */
/* @0x237670 ldr r3, [r3] */
/* @0x237674 blx r3 */
/* @0x237678 ldr r3, [r4] */
/* @0x23767c mov r1, r4 */
/* @0x237680 mov r0, r5 */
/* @0x237684 ldr r3, [r3, #0x4] */
/* @0x237688 blx r3 */
/* @0x23768c vldr s12, [sp, #48] */
/* @0x237690 vldr s13, [sp, #52] */
/* @0x237694 vldr s14, [sp, #56] */
/* @0x237698 vldr s15, [sp, #60] */
/* @0x23769c vmul.f32 s12, s16, s12 */
/* @0x2376a0 vmul.f32 s13, s16, s13 */
/* @0x2376a4 vmov r0, s12 */
/* @0x2376a8 vmul.f32 s14, s16, s14 */
/* @0x2376ac vmov r1, s13 */
/* @0x2376b0 vmul.f32 s15, s16, s15 */
/* @0x2376b4 vmov r2, s14 */
/* @0x2376b8 vmov r3, s15 */
/* @0x2376bc bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0x2376c0 b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130> */
/* @0x2376c4 ldr r3, [r3] */
/* @0x2376c8 blx r3 */
/* @0x2376cc add r0, sp, #24 */
/* @0x2376d0 mov r1, r4 */
/* @0x2376d4 bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv> */
/* @0x2376d8 b 0x237500 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x98> */

/* ── FUNC 0x2376dc · CPhysicsObject::DebugRender(float) · size=44 · insn=11 */
/* @0x2376dc push {r3, r4, r5, lr} */
/* @0x2376e0 mov r4, r0 */
/* @0x2376e4 ldr r3, [r0] */
/* @0x2376e8 mov r5, r1 */
/* @0x2376ec cmp r3, #0 */
/* @0x2376f0 popeq {r3, r4, r5, pc} */
/* @0x2376f4 bl 0x2372ec <_ZN14CPhysicsObject17DebugRenderShapesEf> */
/* @0x2376f8 mov r0, r4 */
/* @0x2376fc mov r1, r5 */
/* @0x237700 pop {r3, r4, r5, lr} */
/* @0x237704 b 0x237468 <_ZN14CPhysicsObject17DebugRenderJointsEf> */

/* ── FUNC 0x237708 · CPhysicsObject::GetFixtureIndex(b2Fixture*) · size=188 · insn=47 */
/* @0x237708 ldr r2, [r0] */
/* @0x23770c push {r4, r5, r6, r7, r8, lr} */
/* @0x237710 ldr r4, [r2, #0x74] */
/* @0x237714 ldr r5, [r0, #0x18] */
/* @0x237718 cmp r4, r1 */
/* @0x23771c cmpne r4, #0 */
/* @0x237720 add r2, r5, #1 */
/* @0x237724 str r2, [r0, #0x18] */
/* @0x237728 beq 0x23773c <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture+0x34> */
/* @0x23772c ldr r4, [r4, #0x4] */
/* @0x237730 cmp r1, r4 */
/* @0x237734 cmpne r4, #0 */
/* @0x237738 bne 0x23772c <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture+0x24> */
/* @0x23773c cmp r4, r1 */
/* @0x237740 beq 0x23774c <_ZN14CPhysicsObject15GetFixtureIndexEP9b2Fixture+0x44> */
/* @0x237744 mov r0, r5 */
/* @0x237748 pop {r4, r5, r6, r7, r8, pc} */
/* @0x23774c ldr r6, [r0, #0x1c] */
/* @0x237750 movw r2, #0x132 */
/* @0x237754 ldr r1, [pc, #0x64] */
/* @0x237758 mov r3, #1 */
/* @0x23775c mov r0, #16 */
/* @0x237760 add r1, pc, r1 */
/* @0x237764 ldm r6, {r7, r8} */
/* @0x237768 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x23776c and r8, r5, r8 */
/* @0x237770 ldr r2, [r7, r8, lsl #3] */
/* @0x237774 add r3, r7, r8, lsl #3 */
/* @0x237778 cmp r2, #0 */
/* @0x23777c ldrne r2, [r3, #0x4] */
/* @0x237780 movne r1, #0 */
/* @0x237784 str r5, [r0, #0x8] */
/* @0x237788 str r4, [r0, #0xc] */
/* @0x23778c strne r2, [r0] */
/* @0x237790 streq r0, [r3, #0x4] */
/* @0x237794 strne r0, [r2, #0x4] */
/* @0x237798 strne r0, [r3, #0x4] */
/* @0x23779c ldr r3, [r6, #0x8] */
/* @0x2377a0 streq r0, [r7, r8, lsl #3] */
/* @0x2377a4 strne r1, [r0, #0x4] */
/* @0x2377a8 add r3, r3, #1 */
/* @0x2377ac streq r2, [r0, #0x4] */
/* @0x2377b0 streq r2, [r0] */
/* @0x2377b4 mov r0, r5 */
/* @0x2377b8 str r3, [r6, #0x8] */
/* @0x2377bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x2377c0 andseq r5, r1, r12, asr #10 */

/* ── FUNC 0x2377c4 · CPhysicsObject::RemoveFixture(int) · size=268 · insn=67 */
/* @0x2377c4 ldr r3, [r0, #0x1c] */
/* @0x2377c8 push {r4, r5, r6, lr} */
/* @0x2377cc mov r5, r0 */
/* @0x2377d0 ldr r2, [r3, #0x4] */
/* @0x2377d4 mov r4, r1 */
/* @0x2377d8 ldr r3, [r3] */
/* @0x2377dc and r2, r1, r2 */
/* @0x2377e0 ldr r3, [r3, r2, lsl #3] */
/* @0x2377e4 cmp r3, #0 */
/* @0x2377e8 bne 0x2377fc <_ZN14CPhysicsObject13RemoveFixtureEi+0x38> */
/* @0x2377ec b 0x2378b4 <_ZN14CPhysicsObject13RemoveFixtureEi+0xf0> */
/* @0x2377f0 ldr r3, [r3, #0x4] */
/* @0x2377f4 cmp r3, #0 */
/* @0x2377f8 beq 0x2378b4 <_ZN14CPhysicsObject13RemoveFixtureEi+0xf0> */
/* @0x2377fc ldr r2, [r3, #0x8] */
/* @0x237800 cmp r4, r2 */
/* @0x237804 bne 0x2377f0 <_ZN14CPhysicsObject13RemoveFixtureEi+0x2c> */
/* @0x237808 ldr r6, [r3, #0xc] */
/* @0x23780c cmp r6, #0 */
/* @0x237810 beq 0x2378c4 <_ZN14CPhysicsObject13RemoveFixtureEi+0x100> */
/* @0x237814 ldr r3, [pc, #0xb0] */
/* @0x237818 mov r1, r6 */
/* @0x23781c ldr r3, [pc, r3] */
/* @0x237820 ldr r3, [r3] */
/* @0x237824 ldr r0, [r3, #0xb4] */
/* @0x237828 bl 0x2383e0 <_ZN13CPhysicsWorld17InvalidateFixtureEP9b2Fixture> */
/* @0x23782c mov r1, r6 */
/* @0x237830 ldr r0, [r5] */
/* @0x237834 bl 0x2c6f24 <_ZN6b2Body14DestroyFixtureEP9b2Fixture> */
/* @0x237838 ldr r5, [r5, #0x1c] */
/* @0x23783c ldr r1, [r5, #0x4] */
/* @0x237840 ldr r2, [r5] */
/* @0x237844 and r1, r4, r1 */
/* @0x237848 ldr r0, [r2, r1, lsl #3] */
/* @0x23784c add r6, r2, r1, lsl #3 */
/* @0x237850 cmp r0, #0 */
/* @0x237854 bne 0x237868 <_ZN14CPhysicsObject13RemoveFixtureEi+0xa4> */
/* @0x237858 b 0x2378bc <_ZN14CPhysicsObject13RemoveFixtureEi+0xf8> */
/* @0x23785c ldr r0, [r0, #0x4] */
/* @0x237860 cmp r0, #0 */
/* @0x237864 beq 0x2378bc <_ZN14CPhysicsObject13RemoveFixtureEi+0xf8> */
/* @0x237868 ldr r3, [r0, #0x8] */
/* @0x23786c cmp r4, r3 */
/* @0x237870 bne 0x23785c <_ZN14CPhysicsObject13RemoveFixtureEi+0x98> */
/* @0x237874 ldr r3, [r0] */
/* @0x237878 cmp r3, #0 */
/* @0x23787c ldrne r2, [r0, #0x4] */
/* @0x237880 ldreq r12, [r0, #0x4] */
/* @0x237884 strne r2, [r3, #0x4] */
/* @0x237888 ldrne r12, [r0, #0x4] */
/* @0x23788c streq r12, [r2, r1, lsl #3] */
/* @0x237890 cmp r12, #0 */
/* @0x237894 streq r3, [r6, #0x4] */
/* @0x237898 strne r3, [r12] */
/* @0x23789c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2378a0 ldr r3, [r5, #0x8] */
/* @0x2378a4 mov r0, #1 */
/* @0x2378a8 sub r3, r3, #1 */
/* @0x2378ac str r3, [r5, #0x8] */
/* @0x2378b0 pop {r4, r5, r6, pc} */
/* @0x2378b4 mov r0, r3 */
/* @0x2378b8 pop {r4, r5, r6, pc} */
/* @0x2378bc mov r0, #1 */
/* @0x2378c0 pop {r4, r5, r6, pc} */
/* @0x2378c4 mov r0, r6 */
/* @0x2378c8 pop {r4, r5, r6, pc} */
/* @0x2378cc andseq r6, r11, r12, lsl #2 */

/* ── FUNC 0x2378d0 · CPhysicsObject::GetFriction(int) · size=84 · insn=21 */
/* @0x2378d0 ldr r3, [r0, #0x1c] */
/* @0x2378d4 ldr r2, [r3, #0x4] */
/* @0x2378d8 ldr r3, [r3] */
/* @0x2378dc and r2, r1, r2 */
/* @0x2378e0 ldr r3, [r3, r2, lsl #3] */
/* @0x2378e4 cmp r3, #0 */
/* @0x2378e8 bne 0x2378fc <_ZN14CPhysicsObject11GetFrictionEi+0x2c> */
/* @0x2378ec b 0x23791c <_ZN14CPhysicsObject11GetFrictionEi+0x4c> */
/* @0x2378f0 ldr r3, [r3, #0x4] */
/* @0x2378f4 cmp r3, #0 */
/* @0x2378f8 beq 0x23791c <_ZN14CPhysicsObject11GetFrictionEi+0x4c> */
/* @0x2378fc ldr r2, [r3, #0x8] */
/* @0x237900 cmp r1, r2 */
/* @0x237904 bne 0x2378f0 <_ZN14CPhysicsObject11GetFrictionEi+0x20> */
/* @0x237908 ldr r3, [r3, #0xc] */
/* @0x23790c cmp r3, #0 */
/* @0x237910 beq 0x23791c <_ZN14CPhysicsObject11GetFrictionEi+0x4c> */
/* @0x237914 ldr r0, [r3, #0x10] */
/* @0x237918 bx lr */
/* @0x23791c mov r0, #0 */
/* @0x237920 bx lr */

/* ── FUNC 0x237924 · CPhysicsObject::GetDensity(int) · size=84 · insn=21 */
/* @0x237924 ldr r3, [r0, #0x1c] */
/* @0x237928 ldr r2, [r3, #0x4] */
/* @0x23792c ldr r3, [r3] */
/* @0x237930 and r2, r1, r2 */
/* @0x237934 ldr r3, [r3, r2, lsl #3] */
/* @0x237938 cmp r3, #0 */
/* @0x23793c bne 0x237950 <_ZN14CPhysicsObject10GetDensityEi+0x2c> */
/* @0x237940 b 0x237970 <_ZN14CPhysicsObject10GetDensityEi+0x4c> */
/* @0x237944 ldr r3, [r3, #0x4] */
/* @0x237948 cmp r3, #0 */
/* @0x23794c beq 0x237970 <_ZN14CPhysicsObject10GetDensityEi+0x4c> */
/* @0x237950 ldr r2, [r3, #0x8] */
/* @0x237954 cmp r1, r2 */
/* @0x237958 bne 0x237944 <_ZN14CPhysicsObject10GetDensityEi+0x20> */
/* @0x23795c ldr r3, [r3, #0xc] */
/* @0x237960 cmp r3, #0 */
/* @0x237964 beq 0x237970 <_ZN14CPhysicsObject10GetDensityEi+0x4c> */
/* @0x237968 ldr r0, [r3] */
/* @0x23796c bx lr */
/* @0x237970 mov r0, #0 */
/* @0x237974 bx lr */

/* ── FUNC 0x237978 · CPhysicsObject::GetRestitution(int) · size=84 · insn=21 */
/* @0x237978 ldr r3, [r0, #0x1c] */
/* @0x23797c ldr r2, [r3, #0x4] */
/* @0x237980 ldr r3, [r3] */
/* @0x237984 and r2, r1, r2 */
/* @0x237988 ldr r3, [r3, r2, lsl #3] */
/* @0x23798c cmp r3, #0 */
/* @0x237990 bne 0x2379a4 <_ZN14CPhysicsObject14GetRestitutionEi+0x2c> */
/* @0x237994 b 0x2379c4 <_ZN14CPhysicsObject14GetRestitutionEi+0x4c> */
/* @0x237998 ldr r3, [r3, #0x4] */
/* @0x23799c cmp r3, #0 */
/* @0x2379a0 beq 0x2379c4 <_ZN14CPhysicsObject14GetRestitutionEi+0x4c> */
/* @0x2379a4 ldr r2, [r3, #0x8] */
/* @0x2379a8 cmp r1, r2 */
/* @0x2379ac bne 0x237998 <_ZN14CPhysicsObject14GetRestitutionEi+0x20> */
/* @0x2379b0 ldr r3, [r3, #0xc] */
/* @0x2379b4 cmp r3, #0 */
/* @0x2379b8 beq 0x2379c4 <_ZN14CPhysicsObject14GetRestitutionEi+0x4c> */
/* @0x2379bc ldr r0, [r3, #0x14] */
/* @0x2379c0 bx lr */
/* @0x2379c4 mov r0, #0 */
/* @0x2379c8 bx lr */

/* ── FUNC 0x2379cc · CPhysicsObject::SetFriction(int, float) · size=76 · insn=19 */
/* @0x2379cc ldr r3, [r0, #0x1c] */
/* @0x2379d0 ldr r0, [r3, #0x4] */
/* @0x2379d4 ldr r3, [r3] */
/* @0x2379d8 and r0, r1, r0 */
/* @0x2379dc ldr r3, [r3, r0, lsl #3] */
/* @0x2379e0 cmp r3, #0 */
/* @0x2379e4 bne 0x2379f8 <_ZN14CPhysicsObject11SetFrictionEif+0x2c> */
/* @0x2379e8 bx lr */
/* @0x2379ec ldr r3, [r3, #0x4] */
/* @0x2379f0 cmp r3, #0 */
/* @0x2379f4 beq 0x237a14 <_ZN14CPhysicsObject11SetFrictionEif+0x48> */
/* @0x2379f8 ldr r0, [r3, #0x8] */
/* @0x2379fc cmp r1, r0 */
/* @0x237a00 bne 0x2379ec <_ZN14CPhysicsObject11SetFrictionEif+0x20> */
/* @0x237a04 ldr r3, [r3, #0xc] */
/* @0x237a08 cmp r3, #0 */
/* @0x237a0c strne r2, [r3, #0x10] */
/* @0x237a10 bx lr */
/* @0x237a14 bx lr */

/* ── FUNC 0x237a18 · CPhysicsObject::SetDensity(int, float) · size=80 · insn=20 */
/* @0x237a18 ldr r3, [r0, #0x1c] */
/* @0x237a1c ldm r3, {r3, r12} */
/* @0x237a20 and r12, r1, r12 */
/* @0x237a24 ldr r3, [r3, r12, lsl #3] */
/* @0x237a28 cmp r3, #0 */
/* @0x237a2c bne 0x237a40 <_ZN14CPhysicsObject10SetDensityEif+0x28> */
/* @0x237a30 bx lr */
/* @0x237a34 ldr r3, [r3, #0x4] */
/* @0x237a38 cmp r3, #0 */
/* @0x237a3c beq 0x237a64 <_ZN14CPhysicsObject10SetDensityEif+0x4c> */
/* @0x237a40 ldr r12, [r3, #0x8] */
/* @0x237a44 cmp r1, r12 */
/* @0x237a48 bne 0x237a34 <_ZN14CPhysicsObject10SetDensityEif+0x1c> */
/* @0x237a4c ldr r3, [r3, #0xc] */
/* @0x237a50 cmp r3, #0 */
/* @0x237a54 bxeq lr */
/* @0x237a58 str r2, [r3] */
/* @0x237a5c ldr r0, [r0] */
/* @0x237a60 b 0x2c6c00 <_ZN6b2Body13ResetMassDataEv> */
/* @0x237a64 bx lr */

/* ── FUNC 0x237a68 · CPhysicsObject::SetRestitution(int, float) · size=76 · insn=19 */
/* @0x237a68 ldr r3, [r0, #0x1c] */
/* @0x237a6c ldr r0, [r3, #0x4] */
/* @0x237a70 ldr r3, [r3] */
/* @0x237a74 and r0, r1, r0 */
/* @0x237a78 ldr r3, [r3, r0, lsl #3] */
/* @0x237a7c cmp r3, #0 */
/* @0x237a80 bne 0x237a94 <_ZN14CPhysicsObject14SetRestitutionEif+0x2c> */
/* @0x237a84 bx lr */
/* @0x237a88 ldr r3, [r3, #0x4] */
/* @0x237a8c cmp r3, #0 */
/* @0x237a90 beq 0x237ab0 <_ZN14CPhysicsObject14SetRestitutionEif+0x48> */
/* @0x237a94 ldr r0, [r3, #0x8] */
/* @0x237a98 cmp r1, r0 */
/* @0x237a9c bne 0x237a88 <_ZN14CPhysicsObject14SetRestitutionEif+0x20> */
/* @0x237aa0 ldr r3, [r3, #0xc] */
/* @0x237aa4 cmp r3, #0 */
/* @0x237aa8 strne r2, [r3, #0x14] */
/* @0x237aac bx lr */
/* @0x237ab0 bx lr */

/* ── FUNC 0x237ab4 · b2ContactListener::~b2ContactListener() · size=24 · insn=6 */
/* @0x237ab4 ldr r3, [pc, #0xc] */
/* @0x237ab8 ldr r3, [pc, r3] */
/* @0x237abc add r3, r3, #8 */
/* @0x237ac0 str r3, [r0] */
/* @0x237ac4 bx lr */
/* @0x237ac8 andseq r9, r11, r8, lsl #20 */

/* ── FUNC 0x237ab4 · b2ContactListener::~b2ContactListener() · alias of the symbol above · insn=0 */

/* ── FUNC 0x237acc · b2ContactListener::BeginContact(b2Contact*) · size=4 · insn=1 */
/* @0x237acc bx lr */

/* ── FUNC 0x237ad0 · b2ContactListener::EndContact(b2Contact*) · size=4 · insn=1 */
/* @0x237ad0 bx lr */

/* ── FUNC 0x237ad4 · b2ContactListener::PreSolve(b2Contact*, b2Manifold const*) · size=4 · insn=1 */
/* @0x237ad4 bx lr */
