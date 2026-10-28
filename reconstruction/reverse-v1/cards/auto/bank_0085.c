/* libyoyo.so 覆盖卡组 0085
 * 函数 0x14e798..0x1515ec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x14e798 · F_PhysicsParticleRadius(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14e798 push {r3, r4, r5, lr} */
/* @0x14e79c mov r1, #0 */
/* @0x14e7a0 ldr r3, [pc, #0x68] */
/* @0x14e7a4 mov r2, r1 */
/* @0x14e7a8 str r1, [r0] */
/* @0x14e7ac movt r2, #0xbff0 */
/* @0x14e7b0 ldr r3, [pc, r3] */
/* @0x14e7b4 mov r4, r0 */
/* @0x14e7b8 str r1, [r0, #0xc] */
/* @0x14e7bc ldr r3, [r3] */
/* @0x14e7c0 str r2, [r0, #0x4] */
/* @0x14e7c4 cmp r3, r1 */
/* @0x14e7c8 beq 0x14e7fc <_Z23F_PhysicsParticleRadiusR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e7cc ldr r5, [r3, #0xb4] */
/* @0x14e7d0 cmp r5, r1 */
/* @0x14e7d4 beq 0x14e7fc <_Z23F_PhysicsParticleRadiusR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e7d8 ldr r0, [r5, #0x10] */
/* @0x14e7dc bl 0x2cb498 <_ZNK7b2World17GetParticleRadiusEv> */
/* @0x14e7e0 vldr s15, [r5, #96] */
/* @0x14e7e4 vmov s12, r0 */
/* @0x14e7e8 vdiv.f32 s15, s12, s15 */
/* @0x14e7ec vcvt.f64.f32 d6, s15 */
/* @0x14e7f0 vmov r2, r3, d6 */
/* @0x14e7f4 stm r4, {r2, r3} */
/* @0x14e7f8 pop {r3, r4, r5, pc} */
/* @0x14e7fc ldr r0, [pc, #0x10] */
/* @0x14e800 mov r1, #0 */
/* @0x14e804 pop {r3, r4, r5, lr} */
/* @0x14e808 add r0, pc, r0 */
/* @0x14e80c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e810 eoreq pc, r9, r8, ror r1 */
/* @0x14e814 andseq r6, pc, r8, lsr #5 */

/* ── FUNC 0x14e818 · F_PhysicsParticleDensity(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14e818 ldr r3, [pc, #0x70] */
/* @0x14e81c mov r1, #0 */
/* @0x14e820 push {r4, lr} */
/* @0x14e824 ldr r3, [pc, r3] */
/* @0x14e828 str r1, [r0] */
/* @0x14e82c mov r2, r1 */
/* @0x14e830 ldr r3, [r3] */
/* @0x14e834 movt r2, #0xbff0 */
/* @0x14e838 mov r4, r0 */
/* @0x14e83c str r1, [r0, #0xc] */
/* @0x14e840 cmp r3, r1 */
/* @0x14e844 str r2, [r0, #0x4] */
/* @0x14e848 beq 0x14e87c <_Z24F_PhysicsParticleDensityR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e84c ldr r3, [r3, #0xb4] */
/* @0x14e850 cmp r3, r1 */
/* @0x14e854 beq 0x14e87c <_Z24F_PhysicsParticleDensityR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e858 ldr r0, [r3, #0x10] */
/* @0x14e85c bl 0x2cb450 <_ZNK7b2World18GetParticleDensityEv> */
/* @0x14e860 vmov s15, r0 */
/* @0x14e864 vcvt.f64.f32 d7, s15 */
/* @0x14e868 vmov r0, r1, d7 */
/* @0x14e86c vmov r2, s14 */
/* @0x14e870 mov r3, r1 */
/* @0x14e874 stm r4, {r2, r3} */
/* @0x14e878 pop {r4, pc} */
/* @0x14e87c ldr r0, [pc, #0x10] */
/* @0x14e880 mov r1, #0 */
/* @0x14e884 pop {r4, lr} */
/* @0x14e888 add r0, pc, r0 */
/* @0x14e88c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e890 eoreq pc, r9, r4, lsl #2 */
/* @0x14e894 andseq r6, pc, r0, lsl #5 */

/* ── FUNC 0x14e898 · F_PhysicsParticleDamping(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14e898 ldr r3, [pc, #0x70] */
/* @0x14e89c mov r1, #0 */
/* @0x14e8a0 push {r4, lr} */
/* @0x14e8a4 ldr r3, [pc, r3] */
/* @0x14e8a8 str r1, [r0] */
/* @0x14e8ac mov r2, r1 */
/* @0x14e8b0 ldr r3, [r3] */
/* @0x14e8b4 movt r2, #0xbff0 */
/* @0x14e8b8 mov r4, r0 */
/* @0x14e8bc str r1, [r0, #0xc] */
/* @0x14e8c0 cmp r3, r1 */
/* @0x14e8c4 str r2, [r0, #0x4] */
/* @0x14e8c8 beq 0x14e8fc <_Z24F_PhysicsParticleDampingR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e8cc ldr r3, [r3, #0xb4] */
/* @0x14e8d0 cmp r3, r1 */
/* @0x14e8d4 beq 0x14e8fc <_Z24F_PhysicsParticleDampingR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e8d8 ldr r0, [r3, #0x10] */
/* @0x14e8dc bl 0x2cb480 <_ZNK7b2World18GetParticleDampingEv> */
/* @0x14e8e0 vmov s15, r0 */
/* @0x14e8e4 vcvt.f64.f32 d7, s15 */
/* @0x14e8e8 vmov r0, r1, d7 */
/* @0x14e8ec vmov r2, s14 */
/* @0x14e8f0 mov r3, r1 */
/* @0x14e8f4 stm r4, {r2, r3} */
/* @0x14e8f8 pop {r4, pc} */
/* @0x14e8fc ldr r0, [pc, #0x10] */
/* @0x14e900 mov r1, #0 */
/* @0x14e904 pop {r4, lr} */
/* @0x14e908 add r0, pc, r0 */
/* @0x14e90c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e910 eoreq pc, r9, r4, lsl #1 */
/* @0x14e914 andseq r6, pc, r12, asr r2 */

/* ── FUNC 0x14e918 · F_PhysicsParticleGravityScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x14e918 ldr r3, [pc, #0x70] */
/* @0x14e91c mov r1, #0 */
/* @0x14e920 push {r4, lr} */
/* @0x14e924 ldr r3, [pc, r3] */
/* @0x14e928 str r1, [r0] */
/* @0x14e92c mov r2, r1 */
/* @0x14e930 ldr r3, [r3] */
/* @0x14e934 movt r2, #0xbff0 */
/* @0x14e938 mov r4, r0 */
/* @0x14e93c str r1, [r0, #0xc] */
/* @0x14e940 cmp r3, r1 */
/* @0x14e944 str r2, [r0, #0x4] */
/* @0x14e948 beq 0x14e97c <_Z29F_PhysicsParticleGravityScaleR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e94c ldr r3, [r3, #0xb4] */
/* @0x14e950 cmp r3, r1 */
/* @0x14e954 beq 0x14e97c <_Z29F_PhysicsParticleGravityScaleR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x14e958 ldr r0, [r3, #0x10] */
/* @0x14e95c bl 0x2cb468 <_ZNK7b2World23GetParticleGravityScaleEv> */
/* @0x14e960 vmov s15, r0 */
/* @0x14e964 vcvt.f64.f32 d7, s15 */
/* @0x14e968 vmov r0, r1, d7 */
/* @0x14e96c vmov r2, s14 */
/* @0x14e970 mov r3, r1 */
/* @0x14e974 stm r4, {r2, r3} */
/* @0x14e978 pop {r4, pc} */
/* @0x14e97c ldr r0, [pc, #0x10] */
/* @0x14e980 mov r1, #0 */
/* @0x14e984 pop {r4, lr} */
/* @0x14e988 add r0, pc, r0 */
/* @0x14e98c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e990 eoreq pc, r9, r4 */
/* @0x14e994 andseq r6, pc, r8, lsr r2 */

/* ── FUNC 0x14e998 · F_PhysicsParticleSetMaxCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14e998 ldr r3, [pc, #0x4c] */
/* @0x14e99c push {r4, lr} */
/* @0x14e9a0 ldr r3, [pc, r3] */
/* @0x14e9a4 ldr r0, [sp, #0x8] */
/* @0x14e9a8 ldr r3, [r3] */
/* @0x14e9ac cmp r3, #0 */
/* @0x14e9b0 beq 0x14e9d8 <_Z28F_PhysicsParticleSetMaxCountR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14e9b4 ldr r4, [r3, #0xb4] */
/* @0x14e9b8 cmp r4, #0 */
/* @0x14e9bc beq 0x14e9d8 <_Z28F_PhysicsParticleSetMaxCountR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14e9c0 mov r1, #0 */
/* @0x14e9c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14e9c8 mov r1, r0 */
/* @0x14e9cc ldr r0, [r4, #0x10] */
/* @0x14e9d0 pop {r4, lr} */
/* @0x14e9d4 b 0x2cb438 <_ZN7b2World19SetParticleMaxCountEi> */
/* @0x14e9d8 ldr r0, [pc, #0x10] */
/* @0x14e9dc mov r1, #0 */
/* @0x14e9e0 pop {r4, lr} */
/* @0x14e9e4 add r0, pc, r0 */
/* @0x14e9e8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14e9ec eoreq lr, r9, r8, lsl #31 */
/* @0x14e9f0 andseq r6, pc, r12, lsr r2 */

/* ── FUNC 0x14e9f4 · F_PhysicsParticleSetRadius(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x14e9f4 ldr r3, [pc, #0x58] */
/* @0x14e9f8 push {r4, lr} */
/* @0x14e9fc ldr r3, [pc, r3] */
/* @0x14ea00 ldr r0, [sp, #0x8] */
/* @0x14ea04 ldr r3, [r3] */
/* @0x14ea08 cmp r3, #0 */
/* @0x14ea0c beq 0x14ea40 <_Z26F_PhysicsParticleSetRadiusR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14ea10 ldr r4, [r3, #0xb4] */
/* @0x14ea14 cmp r4, #0 */
/* @0x14ea18 beq 0x14ea40 <_Z26F_PhysicsParticleSetRadiusR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x14ea1c mov r1, #0 */
/* @0x14ea20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ea24 vldr s15, [r4, #96] */
/* @0x14ea28 vmov s14, r0 */
/* @0x14ea2c ldr r0, [r4, #0x10] */
/* @0x14ea30 pop {r4, lr} */
/* @0x14ea34 vmul.f32 s15, s14, s15 */
/* @0x14ea38 vmov r1, s15 */
/* @0x14ea3c b 0x2cb48c <_ZN7b2World17SetParticleRadiusEf> */
/* @0x14ea40 ldr r0, [pc, #0x10] */
/* @0x14ea44 mov r1, #0 */
/* @0x14ea48 pop {r4, lr} */
/* @0x14ea4c add r0, pc, r0 */
/* @0x14ea50 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ea54 eoreq lr, r9, r12, lsr #30 */
/* @0x14ea58 andseq r6, pc, r4, lsr r2 */

/* ── FUNC 0x14ea5c · F_PhysicsParticleSetDensity(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14ea5c ldr r3, [pc, #0x4c] */
/* @0x14ea60 push {r4, lr} */
/* @0x14ea64 ldr r3, [pc, r3] */
/* @0x14ea68 ldr r0, [sp, #0x8] */
/* @0x14ea6c ldr r3, [r3] */
/* @0x14ea70 cmp r3, #0 */
/* @0x14ea74 beq 0x14ea9c <_Z27F_PhysicsParticleSetDensityR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14ea78 ldr r4, [r3, #0xb4] */
/* @0x14ea7c cmp r4, #0 */
/* @0x14ea80 beq 0x14ea9c <_Z27F_PhysicsParticleSetDensityR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14ea84 mov r1, #0 */
/* @0x14ea88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ea8c mov r1, r0 */
/* @0x14ea90 ldr r0, [r4, #0x10] */
/* @0x14ea94 pop {r4, lr} */
/* @0x14ea98 b 0x2cb444 <_ZN7b2World18SetParticleDensityEf> */
/* @0x14ea9c ldr r0, [pc, #0x10] */
/* @0x14eaa0 mov r1, #0 */
/* @0x14eaa4 pop {r4, lr} */
/* @0x14eaa8 add r0, pc, r0 */
/* @0x14eaac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14eab0 eoreq lr, r9, r4, asr #29 */
/* @0x14eab4 ldrsbeq r6, [pc], -r8 */

/* ── FUNC 0x14eab8 · F_PhysicsParticleSetDamping(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14eab8 ldr r3, [pc, #0x4c] */
/* @0x14eabc push {r4, lr} */
/* @0x14eac0 ldr r3, [pc, r3] */
/* @0x14eac4 ldr r0, [sp, #0x8] */
/* @0x14eac8 ldr r3, [r3] */
/* @0x14eacc cmp r3, #0 */
/* @0x14ead0 beq 0x14eaf8 <_Z27F_PhysicsParticleSetDampingR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14ead4 ldr r4, [r3, #0xb4] */
/* @0x14ead8 cmp r4, #0 */
/* @0x14eadc beq 0x14eaf8 <_Z27F_PhysicsParticleSetDampingR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14eae0 mov r1, #0 */
/* @0x14eae4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14eae8 mov r1, r0 */
/* @0x14eaec ldr r0, [r4, #0x10] */
/* @0x14eaf0 pop {r4, lr} */
/* @0x14eaf4 b 0x2cb474 <_ZN7b2World18SetParticleDampingEf> */
/* @0x14eaf8 ldr r0, [pc, #0x10] */
/* @0x14eafc mov r1, #0 */
/* @0x14eb00 pop {r4, lr} */
/* @0x14eb04 add r0, pc, r0 */
/* @0x14eb08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14eb0c eoreq lr, r9, r8, ror #28 */
/* @0x14eb10 ldrsbeq r6, [pc], -r8 */

/* ── FUNC 0x14eb14 · F_PhysicsParticleSetGravityScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x14eb14 ldr r3, [pc, #0x4c] */
/* @0x14eb18 push {r4, lr} */
/* @0x14eb1c ldr r3, [pc, r3] */
/* @0x14eb20 ldr r0, [sp, #0x8] */
/* @0x14eb24 ldr r3, [r3] */
/* @0x14eb28 cmp r3, #0 */
/* @0x14eb2c beq 0x14eb54 <_Z32F_PhysicsParticleSetGravityScaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14eb30 ldr r4, [r3, #0xb4] */
/* @0x14eb34 cmp r4, #0 */
/* @0x14eb38 beq 0x14eb54 <_Z32F_PhysicsParticleSetGravityScaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14eb3c mov r1, #0 */
/* @0x14eb40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14eb44 mov r1, r0 */
/* @0x14eb48 ldr r0, [r4, #0x10] */
/* @0x14eb4c pop {r4, lr} */
/* @0x14eb50 b 0x2cb45c <_ZN7b2World23SetParticleGravityScaleEf> */
/* @0x14eb54 ldr r0, [pc, #0x10] */
/* @0x14eb58 mov r1, #0 */
/* @0x14eb5c pop {r4, lr} */
/* @0x14eb60 add r0, pc, r0 */
/* @0x14eb64 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14eb68 eoreq lr, r9, r12, lsl #28 */
/* @0x14eb6c ldrsbeq r6, [pc], -r12 */

/* ── FUNC 0x14eb70 · F_PhysicsCreateWorld(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x14eb70 push {r3, r4, r5, r6, r7, lr} */
/* @0x14eb74 ldr r3, [pc, #0xa0] */
/* @0x14eb78 ldr r0, [sp, #0x18] */
/* @0x14eb7c ldr r3, [pc, r3] */
/* @0x14eb80 ldr r4, [r3] */
/* @0x14eb84 cmp r4, #0 */
/* @0x14eb88 beq 0x14ebe8 <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x14eb8c mov r1, #0 */
/* @0x14eb90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14eb94 ldr r3, [pc, #0x84] */
/* @0x14eb98 ldr r3, [pc, r3] */
/* @0x14eb9c ldrb r3, [r3] */
/* @0x14eba0 cmp r3, #0 */
/* @0x14eba4 ldreq r5, [r4, #0xc] */
/* @0x14eba8 mov r6, r0 */
/* @0x14ebac bne 0x14ebcc <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x14ebb0 ldr r3, [r4, #0xb4] */
/* @0x14ebb4 cmp r3, #0 */
/* @0x14ebb8 beq 0x14ebfc <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x14ebbc str r6, [r3, #0x60] */
/* @0x14ebc0 ldr r3, [r4, #0xb4] */
/* @0x14ebc4 str r5, [r3, #0x58] */
/* @0x14ebc8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x14ebcc ldr r0, [pc, #0x50] */
/* @0x14ebd0 ldr r0, [pc, r0] */
/* @0x14ebd4 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x14ebd8 vmov d7, r0, r1 */
/* @0x14ebdc vcvt.s32.f64 s15, d7 */
/* @0x14ebe0 vmov r5, s15 */
/* @0x14ebe4 b 0x14ebb0 <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x14ebe8 ldr r0, [pc, #0x38] */
/* @0x14ebec mov r1, r4 */
/* @0x14ebf0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x14ebf4 add r0, pc, r0 */
/* @0x14ebf8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ebfc mov r0, #488 */
/* @0x14ec00 bl 0x27c524 <_Znwj> */
/* @0x14ec04 mov r1, r6 */
/* @0x14ec08 mov r2, r5 */
/* @0x14ec0c mov r7, r0 */
/* @0x14ec10 bl 0x237ca0 <_ZN13CPhysicsWorldC2Efi> */
/* @0x14ec14 str r7, [r4, #0xb4] */
/* @0x14ec18 pop {r3, r4, r5, r6, r7, pc} */
/* @0x14ec1c eoreq lr, r9, r12, lsr #27 */
/* @0x14ec20 eoreq lr, r9, r12, lsl #27 */
/* @0x14ec24 eoreq lr, r9, r12, asr sp */
/* @0x14ec28 andseq r5, pc, r8, lsl r3 */

/* ── FUNC 0x14ec2c · Object_GetInstance(int, CInstance*, CInstance*) · size=216 · insn=54 */
/* @0x14ec2c cmn r0, #1 */
/* @0x14ec30 beq 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> */
/* @0x14ec34 cmn r0, #2 */
/* @0x14ec38 beq 0x14ecac <_Z18Object_GetInstanceiP9CInstanceS0_+0x80> */
/* @0x14ec3c movw r3, #0x869f */
/* @0x14ec40 movt r3, #0x1 */
/* @0x14ec44 cmp r0, r3 */
/* @0x14ec48 bgt 0x14ecb4 <_Z18Object_GetInstanceiP9CInstanceS0_+0x88> */
/* @0x14ec4c ldr r3, [pc, #0xa8] */
/* @0x14ec50 ldr r3, [pc, r3] */
/* @0x14ec54 ldr r3, [r3] */
/* @0x14ec58 ldr r2, [r3, #0x4] */
/* @0x14ec5c ldr r3, [r3] */
/* @0x14ec60 and r2, r0, r2 */
/* @0x14ec64 ldr r1, [r3, r2, lsl #3] */
/* @0x14ec68 cmp r1, #0 */
/* @0x14ec6c bne 0x14ec84 <_Z18Object_GetInstanceiP9CInstanceS0_+0x58> */
/* @0x14ec70 mov r0, r1 */
/* @0x14ec74 bx lr */
/* @0x14ec78 ldr r1, [r1, #0x4] */
/* @0x14ec7c cmp r1, #0 */
/* @0x14ec80 beq 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> */
/* @0x14ec84 ldr r3, [r1, #0x8] */
/* @0x14ec88 cmp r0, r3 */
/* @0x14ec8c bne 0x14ec78 <_Z18Object_GetInstanceiP9CInstanceS0_+0x4c> */
/* @0x14ec90 ldr r0, [r1, #0xc] */
/* @0x14ec94 cmp r0, #0 */
/* @0x14ec98 beq 0x14ecf8 <_Z18Object_GetInstanceiP9CInstanceS0_+0xcc> */
/* @0x14ec9c ldr r0, [r0, #0xd0] */
/* @0x14eca0 cmp r0, #0 */
/* @0x14eca4 ldrne r0, [r0, #0x8] */
/* @0x14eca8 bx lr */
/* @0x14ecac mov r0, r2 */
/* @0x14ecb0 bx lr */
/* @0x14ecb4 ldr r3, [pc, #0x44] */
/* @0x14ecb8 ldr r3, [pc, r3] */
/* @0x14ecbc ldr r2, [r3, #0x4] */
/* @0x14ecc0 ldr r3, [r3] */
/* @0x14ecc4 and r2, r0, r2 */
/* @0x14ecc8 ldr r1, [r3, r2, lsl #3] */
/* @0x14eccc cmp r1, #0 */
/* @0x14ecd0 bne 0x14ece4 <_Z18Object_GetInstanceiP9CInstanceS0_+0xb8> */
/* @0x14ecd4 b 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> */
/* @0x14ecd8 ldr r1, [r1, #0x4] */
/* @0x14ecdc cmp r1, #0 */
/* @0x14ece0 beq 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> */
/* @0x14ece4 ldr r3, [r1, #0x8] */
/* @0x14ece8 cmp r0, r3 */
/* @0x14ecec bne 0x14ecd8 <_Z18Object_GetInstanceiP9CInstanceS0_+0xac> */
/* @0x14ecf0 ldr r0, [r1, #0xc] */
/* @0x14ecf4 bx lr */
/* @0x14ecf8 bx lr */
/* @0x14ecfc eoreq lr, r9, r12, ror #31 */
/* @0x14ed00 eoreq lr, r9, r12, lsl #31 */

/* ── FUNC 0x14ed04 · F_PhysicsCreateDistanceJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=600 · insn=150 */
/* @0x14ed04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14ed08 sub sp, sp, #292 */
/* @0x14ed0c ldr r6, [pc, #0x22c] */
/* @0x14ed10 mov r8, r2 */
/* @0x14ed14 ldr r12, [pc, #0x228] */
/* @0x14ed18 mov r3, #0 */
/* @0x14ed1c add r6, pc, r6 */
/* @0x14ed20 ldr r4, [sp, #0x148] */
/* @0x14ed24 mov r5, r0 */
/* @0x14ed28 mov r9, r1 */
/* @0x14ed2c ldr r7, [r6, r12] */
/* @0x14ed30 mov r0, r3 */
/* @0x14ed34 mov r1, r3 */
/* @0x14ed38 movt r0, #0xbff0 */
/* @0x14ed3c str r3, [r5, #0xc] */
/* @0x14ed40 ldr r2, [r7] */
/* @0x14ed44 str r0, [r5, #0x4] */
/* @0x14ed48 mov r0, r4 */
/* @0x14ed4c str r3, [r5] */
/* @0x14ed50 str r2, [sp, #0x11c] */
/* @0x14ed54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ed58 mov r1, r9 */
/* @0x14ed5c mov r2, r8 */
/* @0x14ed60 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14ed64 subs r10, r0, #0 */
/* @0x14ed68 beq 0x14eeac <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x14ed6c mov r1, #1 */
/* @0x14ed70 mov r0, r4 */
/* @0x14ed74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ed78 mov r1, r9 */
/* @0x14ed7c mov r2, r8 */
/* @0x14ed80 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14ed84 subs r9, r0, #0 */
/* @0x14ed88 beq 0x14eef4 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x14ed8c ldr r8, [r10, #0x84] */
/* @0x14ed90 cmp r8, #0 */
/* @0x14ed94 beq 0x14ee6c <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x14ed98 ldr r9, [r9, #0x84] */
/* @0x14ed9c cmp r9, #0 */
/* @0x14eda0 beq 0x14ee6c <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x14eda4 ldr r3, [pc, #0x19c] */
/* @0x14eda8 ldr r3, [r6, r3] */
/* @0x14edac ldr r3, [r3] */
/* @0x14edb0 ldr r6, [r3, #0xb4] */
/* @0x14edb4 cmp r6, #0 */
/* @0x14edb8 beq 0x14ee98 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x14edbc mov r1, #2 */
/* @0x14edc0 mov r0, r4 */
/* @0x14edc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14edc8 mov r1, #3 */
/* @0x14edcc mov r10, r0 */
/* @0x14edd0 mov r0, r4 */
/* @0x14edd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14edd8 mov r1, #4 */
/* @0x14eddc mov r2, r0 */
/* @0x14ede0 mov r0, r4 */
/* @0x14ede4 str r2, [sp, #0x10] */
/* @0x14ede8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14edec mov r1, #5 */
/* @0x14edf0 mov r3, r0 */
/* @0x14edf4 mov r0, r4 */
/* @0x14edf8 str r3, [sp, #0x14] */
/* @0x14edfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14ee00 mov r1, #6 */
/* @0x14ee04 mov r11, r0 */
/* @0x14ee08 mov r0, r4 */
/* @0x14ee0c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14ee10 ldr r2, [sp, #0x10] */
/* @0x14ee14 ldr r3, [sp, #0x14] */
/* @0x14ee18 mov r1, r8 */
/* @0x14ee1c str r11, [sp, #0x8] */
/* @0x14ee20 str r2, [sp] */
/* @0x14ee24 mov r2, r9 */
/* @0x14ee28 str r3, [sp, #0x4] */
/* @0x14ee2c mov r3, r10 */
/* @0x14ee30 str r0, [sp, #0xc] */
/* @0x14ee34 mov r0, r6 */
/* @0x14ee38 bl 0x238e70 <_ZN13CPhysicsWorld19CreateDistanceJointEP14CPhysicsObjectS1_ffffb> */
/* @0x14ee3c vmov s15, r0 */
/* @0x14ee40 vcvt.f64.s32 d7, s15 */
/* @0x14ee44 vmov r0, r1, d7 */
/* @0x14ee48 vmov r2, s14 */
/* @0x14ee4c mov r3, r1 */
/* @0x14ee50 stm r5, {r2, r3} */
/* @0x14ee54 ldr r2, [sp, #0x11c] */
/* @0x14ee58 ldr r3, [r7] */
/* @0x14ee5c cmp r2, r3 */
/* @0x14ee60 bne 0x14ef3c <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x14ee64 add sp, sp, #292 */
/* @0x14ee68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14ee6c ldr r3, [pc, #0xd4] */
/* @0x14ee70 ldr r3, [r6, r3] */
/* @0x14ee74 ldr r3, [r3] */
/* @0x14ee78 ldr r3, [r3, #0xb4] */
/* @0x14ee7c cmp r3, #0 */
/* @0x14ee80 beq 0x14ee98 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x14ee84 ldr r0, [pc, #0xc0] */
/* @0x14ee88 mov r1, #0 */
/* @0x14ee8c add r0, pc, r0 */
/* @0x14ee90 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ee94 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x14ee98 ldr r0, [pc, #0xb0] */
/* @0x14ee9c mov r1, #0 */
/* @0x14eea0 add r0, pc, r0 */
/* @0x14eea4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14eea8 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x14eeac add r5, sp, #28 */
/* @0x14eeb0 mov r1, r10 */
/* @0x14eeb4 mov r2, #256 */
/* @0x14eeb8 mov r0, r5 */
/* @0x14eebc bl 0xb65b0 <memset@plt> */
/* @0x14eec0 mov r1, r10 */
/* @0x14eec4 mov r0, r4 */
/* @0x14eec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14eecc ldr r2, [pc, #0x80] */
/* @0x14eed0 mov r1, #256 */
/* @0x14eed4 add r2, pc, r2 */
/* @0x14eed8 mov r3, r0 */
/* @0x14eedc mov r0, r5 */
/* @0x14eee0 bl 0xb65c8 <snprintf@plt> */
/* @0x14eee4 mov r0, r5 */
/* @0x14eee8 mov r1, r10 */
/* @0x14eeec bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14eef0 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x14eef4 add r5, sp, #28 */
/* @0x14eef8 mov r1, r9 */
/* @0x14eefc mov r2, #256 */
/* @0x14ef00 mov r0, r5 */
/* @0x14ef04 bl 0xb65b0 <memset@plt> */
/* @0x14ef08 mov r0, r4 */
/* @0x14ef0c mov r1, #1 */
/* @0x14ef10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ef14 ldr r2, [pc, #0x3c] */
/* @0x14ef18 mov r1, #256 */
/* @0x14ef1c add r2, pc, r2 */
/* @0x14ef20 mov r3, r0 */
/* @0x14ef24 mov r0, r5 */
/* @0x14ef28 bl 0xb65c8 <snprintf@plt> */
/* @0x14ef2c mov r0, r5 */
/* @0x14ef30 mov r1, r9 */
/* @0x14ef34 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ef38 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x14ef3c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14ef40 eoreq r2, r10, r4, lsr pc */
/* @0x14ef44 .word 0xffffbd00 */
/* @0x14ef48 .word 0xffffbcd8 */
/* @0x14ef4c andseq r5, pc, r0, lsr pc */
/* @0x14ef50 andseq r4, pc, r4, lsl #31 */
/* @0x14ef54 andseq r5, pc, r12, asr #29 */
/* @0x14ef58 andseq r5, pc, r4, lsl #29 */

/* ── FUNC 0x14ef5c · F_PhysicsCreateRopeJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=628 · insn=157 */
/* @0x14ef5c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14ef60 sub sp, sp, #308 */
/* @0x14ef64 ldr r6, [pc, #0x248] */
/* @0x14ef68 mov r8, r2 */
/* @0x14ef6c ldr r12, [pc, #0x244] */
/* @0x14ef70 mov r3, #0 */
/* @0x14ef74 add r6, pc, r6 */
/* @0x14ef78 ldr r4, [sp, #0x158] */
/* @0x14ef7c mov r5, r0 */
/* @0x14ef80 mov r9, r1 */
/* @0x14ef84 ldr r7, [r6, r12] */
/* @0x14ef88 mov r0, r3 */
/* @0x14ef8c mov r1, r3 */
/* @0x14ef90 movt r0, #0xbff0 */
/* @0x14ef94 str r3, [r5, #0xc] */
/* @0x14ef98 ldr r2, [r7] */
/* @0x14ef9c str r0, [r5, #0x4] */
/* @0x14efa0 mov r0, r4 */
/* @0x14efa4 str r3, [r5] */
/* @0x14efa8 str r2, [sp, #0x12c] */
/* @0x14efac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14efb0 mov r1, r9 */
/* @0x14efb4 mov r2, r8 */
/* @0x14efb8 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14efbc subs r10, r0, #0 */
/* @0x14efc0 beq 0x14f120 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x14efc4 mov r1, #1 */
/* @0x14efc8 mov r0, r4 */
/* @0x14efcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14efd0 mov r1, r9 */
/* @0x14efd4 mov r2, r8 */
/* @0x14efd8 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14efdc subs r9, r0, #0 */
/* @0x14efe0 beq 0x14f168 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14efe4 ldr r8, [r10, #0x84] */
/* @0x14efe8 cmp r8, #0 */
/* @0x14efec beq 0x14f0e0 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x14eff0 ldr r9, [r9, #0x84] */
/* @0x14eff4 cmp r9, #0 */
/* @0x14eff8 beq 0x14f0e0 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x14effc ldr r3, [pc, #0x1b8] */
/* @0x14f000 ldr r3, [r6, r3] */
/* @0x14f004 ldr r3, [r3] */
/* @0x14f008 ldr r6, [r3, #0xb4] */
/* @0x14f00c cmp r6, #0 */
/* @0x14f010 beq 0x14f10c <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x14f014 mov r1, #2 */
/* @0x14f018 mov r0, r4 */
/* @0x14f01c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f020 mov r1, #3 */
/* @0x14f024 mov r10, r0 */
/* @0x14f028 mov r0, r4 */
/* @0x14f02c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f030 mov r1, #4 */
/* @0x14f034 mov r12, r0 */
/* @0x14f038 mov r0, r4 */
/* @0x14f03c str r12, [sp, #0x1c] */
/* @0x14f040 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f044 mov r1, #5 */
/* @0x14f048 mov r2, r0 */
/* @0x14f04c mov r0, r4 */
/* @0x14f050 str r2, [sp, #0x20] */
/* @0x14f054 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f058 mov r1, #6 */
/* @0x14f05c mov r3, r0 */
/* @0x14f060 mov r0, r4 */
/* @0x14f064 str r3, [sp, #0x24] */
/* @0x14f068 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f06c mov r1, #7 */
/* @0x14f070 mov r11, r0 */
/* @0x14f074 mov r0, r4 */
/* @0x14f078 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f07c ldr r2, [sp, #0x20] */
/* @0x14f080 ldr r3, [sp, #0x24] */
/* @0x14f084 mov r1, r8 */
/* @0x14f088 ldr r12, [sp, #0x1c] */
/* @0x14f08c str r2, [sp, #0x4] */
/* @0x14f090 mov r2, r9 */
/* @0x14f094 str r3, [sp, #0x8] */
/* @0x14f098 mov r3, r10 */
/* @0x14f09c str r12, [sp] */
/* @0x14f0a0 str r11, [sp, #0xc] */
/* @0x14f0a4 str r0, [sp, #0x10] */
/* @0x14f0a8 mov r0, r6 */
/* @0x14f0ac bl 0x238f60 <_ZN13CPhysicsWorld15CreateRopeJointEP14CPhysicsObjectS1_fffffb> */
/* @0x14f0b0 vmov s15, r0 */
/* @0x14f0b4 vcvt.f64.s32 d7, s15 */
/* @0x14f0b8 vmov r0, r1, d7 */
/* @0x14f0bc vmov r2, s14 */
/* @0x14f0c0 mov r3, r1 */
/* @0x14f0c4 stm r5, {r2, r3} */
/* @0x14f0c8 ldr r2, [sp, #0x12c] */
/* @0x14f0cc ldr r3, [r7] */
/* @0x14f0d0 cmp r2, r3 */
/* @0x14f0d4 bne 0x14f1b0 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x14f0d8 add sp, sp, #308 */
/* @0x14f0dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14f0e0 ldr r3, [pc, #0xd4] */
/* @0x14f0e4 ldr r3, [r6, r3] */
/* @0x14f0e8 ldr r3, [r3] */
/* @0x14f0ec ldr r3, [r3, #0xb4] */
/* @0x14f0f0 cmp r3, #0 */
/* @0x14f0f4 beq 0x14f10c <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x14f0f8 ldr r0, [pc, #0xc0] */
/* @0x14f0fc mov r1, #0 */
/* @0x14f100 add r0, pc, r0 */
/* @0x14f104 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f108 b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x14f10c ldr r0, [pc, #0xb0] */
/* @0x14f110 mov r1, #0 */
/* @0x14f114 add r0, pc, r0 */
/* @0x14f118 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f11c b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x14f120 add r5, sp, #44 */
/* @0x14f124 mov r1, r10 */
/* @0x14f128 mov r2, #256 */
/* @0x14f12c mov r0, r5 */
/* @0x14f130 bl 0xb65b0 <memset@plt> */
/* @0x14f134 mov r1, r10 */
/* @0x14f138 mov r0, r4 */
/* @0x14f13c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f140 ldr r2, [pc, #0x80] */
/* @0x14f144 mov r1, #256 */
/* @0x14f148 add r2, pc, r2 */
/* @0x14f14c mov r3, r0 */
/* @0x14f150 mov r0, r5 */
/* @0x14f154 bl 0xb65c8 <snprintf@plt> */
/* @0x14f158 mov r0, r5 */
/* @0x14f15c mov r1, r10 */
/* @0x14f160 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f164 b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x14f168 add r5, sp, #44 */
/* @0x14f16c mov r1, r9 */
/* @0x14f170 mov r2, #256 */
/* @0x14f174 mov r0, r5 */
/* @0x14f178 bl 0xb65b0 <memset@plt> */
/* @0x14f17c mov r0, r4 */
/* @0x14f180 mov r1, #1 */
/* @0x14f184 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f188 ldr r2, [pc, #0x3c] */
/* @0x14f18c mov r1, #256 */
/* @0x14f190 add r2, pc, r2 */
/* @0x14f194 mov r3, r0 */
/* @0x14f198 mov r0, r5 */
/* @0x14f19c bl 0xb65c8 <snprintf@plt> */
/* @0x14f1a0 mov r0, r5 */
/* @0x14f1a4 mov r1, r9 */
/* @0x14f1a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f1ac b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x14f1b0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14f1b4 .word 0x002a2cdc */
/* @0x14f1b8 .word 0xffffbd00 */
/* @0x14f1bc .word 0xffffbcd8 */
/* @0x14f1c0 andseq r5, pc, r12, lsl sp */
/* @0x14f1c4 andseq r4, pc, r0, lsl sp */
/* @0x14f1c8 andseq r5, pc, r8, asr r12 */
/* @0x14f1cc andseq r5, pc, r0, lsl r12 */

/* ── FUNC 0x14f1d0 · F_PhysicsCreateRevoluteJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=728 · insn=182 */
/* @0x14f1d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14f1d4 vpush {d8} */
/* @0x14f1d8 sub sp, sp, #316 */
/* @0x14f1dc ldr r9, [pc, #0x2a8] */
/* @0x14f1e0 mov r7, r2 */
/* @0x14f1e4 ldr r12, [pc, #0x2a4] */
/* @0x14f1e8 mov r3, #0 */
/* @0x14f1ec add r9, pc, r9 */
/* @0x14f1f0 ldr r4, [sp, #0x168] */
/* @0x14f1f4 mov r5, r0 */
/* @0x14f1f8 mov r8, r1 */
/* @0x14f1fc ldr r6, [r9, r12] */
/* @0x14f200 mov r0, r3 */
/* @0x14f204 mov r1, r3 */
/* @0x14f208 movt r0, #0xbff0 */
/* @0x14f20c str r3, [r5, #0xc] */
/* @0x14f210 ldr r2, [r6] */
/* @0x14f214 str r0, [r5, #0x4] */
/* @0x14f218 mov r0, r4 */
/* @0x14f21c str r3, [r5] */
/* @0x14f220 str r2, [sp, #0x134] */
/* @0x14f224 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f228 mov r1, r8 */
/* @0x14f22c mov r2, r7 */
/* @0x14f230 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14f234 subs r10, r0, #0 */
/* @0x14f238 beq 0x14f3f0 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x14f23c mov r1, #1 */
/* @0x14f240 mov r0, r4 */
/* @0x14f244 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f248 mov r1, r8 */
/* @0x14f24c mov r2, r7 */
/* @0x14f250 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14f254 subs r8, r0, #0 */
/* @0x14f258 beq 0x14f438 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x14f25c ldr r7, [r10, #0x84] */
/* @0x14f260 cmp r7, #0 */
/* @0x14f264 beq 0x14f3b0 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f268 ldr r8, [r8, #0x84] */
/* @0x14f26c cmp r8, #0 */
/* @0x14f270 beq 0x14f3b0 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f274 ldr r3, [pc, #0x218] */
/* @0x14f278 ldr r3, [r9, r3] */
/* @0x14f27c ldr r3, [r3] */
/* @0x14f280 ldr r9, [r3, #0xb4] */
/* @0x14f284 cmp r9, #0 */
/* @0x14f288 beq 0x14f3dc <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14f28c mov r1, #2 */
/* @0x14f290 mov r0, r4 */
/* @0x14f294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f298 mov r1, #3 */
/* @0x14f29c mov r3, r0 */
/* @0x14f2a0 mov r0, r4 */
/* @0x14f2a4 str r3, [sp, #0x20] */
/* @0x14f2a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f2ac mov r1, #4 */
/* @0x14f2b0 mov r12, r0 */
/* @0x14f2b4 mov r0, r4 */
/* @0x14f2b8 str r12, [sp, #0x24] */
/* @0x14f2bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f2c0 mov r1, #5 */
/* @0x14f2c4 vmov s17, r0 */
/* @0x14f2c8 mov r0, r4 */
/* @0x14f2cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f2d0 mov r1, #6 */
/* @0x14f2d4 vmov s16, r0 */
/* @0x14f2d8 mov r0, r4 */
/* @0x14f2dc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f2e0 mov r1, #7 */
/* @0x14f2e4 mov r2, r0 */
/* @0x14f2e8 mov r0, r4 */
/* @0x14f2ec str r2, [sp, #0x28] */
/* @0x14f2f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f2f4 mov r1, #8 */
/* @0x14f2f8 str r0, [sp, #0x2c] */
/* @0x14f2fc mov r0, r4 */
/* @0x14f300 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f304 mov r1, #9 */
/* @0x14f308 mov r11, r0 */
/* @0x14f30c mov r0, r4 */
/* @0x14f310 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f314 mov r1, #10 */
/* @0x14f318 mov r10, r0 */
/* @0x14f31c mov r0, r4 */
/* @0x14f320 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f324 vldr s14, [pc, #344] */
/* @0x14f328 vmul.f32 s17, s17, s14 */
/* @0x14f32c vldr s15, [pc, #340] */
/* @0x14f330 ldr r2, [sp, #0x28] */
/* @0x14f334 mov r1, r7 */
/* @0x14f338 ldr r12, [sp, #0x24] */
/* @0x14f33c ldr r3, [sp, #0x20] */
/* @0x14f340 str r2, [sp, #0xc] */
/* @0x14f344 ldr r2, [sp, #0x2c] */
/* @0x14f348 str r12, [sp] */
/* @0x14f34c str r11, [sp, #0x14] */
/* @0x14f350 str r2, [sp, #0x10] */
/* @0x14f354 mov r2, r8 */
/* @0x14f358 str r10, [sp, #0x18] */
/* @0x14f35c vmul.f32 s14, s16, s14 */
/* @0x14f360 vdiv.f32 s17, s17, s15 */
/* @0x14f364 str r0, [sp, #0x1c] */
/* @0x14f368 mov r0, r9 */
/* @0x14f36c vdiv.f32 s15, s14, s15 */
/* @0x14f370 vstr s17, [sp, #4] */
/* @0x14f374 vstr s15, [sp, #8] */
/* @0x14f378 bl 0x239050 <_ZN13CPhysicsWorld19CreateRevoluteJointEP14CPhysicsObjectS1_ffffbffbb> */
/* @0x14f37c vmov s15, r0 */
/* @0x14f380 vcvt.f64.s32 d7, s15 */
/* @0x14f384 vmov r0, r1, d7 */
/* @0x14f388 vmov r2, s14 */
/* @0x14f38c mov r3, r1 */
/* @0x14f390 stm r5, {r2, r3} */
/* @0x14f394 ldr r2, [sp, #0x134] */
/* @0x14f398 ldr r3, [r6] */
/* @0x14f39c cmp r2, r3 */
/* @0x14f3a0 bne 0x14f480 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x14f3a4 add sp, sp, #316 */
/* @0x14f3a8 vpop {d8} */
/* @0x14f3ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14f3b0 ldr r3, [pc, #0xdc] */
/* @0x14f3b4 ldr r3, [r9, r3] */
/* @0x14f3b8 ldr r3, [r3] */
/* @0x14f3bc ldr r3, [r3, #0xb4] */
/* @0x14f3c0 cmp r3, #0 */
/* @0x14f3c4 beq 0x14f3dc <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14f3c8 ldr r0, [pc, #0xc8] */
/* @0x14f3cc mov r1, #0 */
/* @0x14f3d0 add r0, pc, r0 */
/* @0x14f3d4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f3d8 b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x14f3dc ldr r0, [pc, #0xb8] */
/* @0x14f3e0 mov r1, #0 */
/* @0x14f3e4 add r0, pc, r0 */
/* @0x14f3e8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f3ec b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x14f3f0 add r5, sp, #52 */
/* @0x14f3f4 mov r1, r10 */
/* @0x14f3f8 mov r2, #256 */
/* @0x14f3fc mov r0, r5 */
/* @0x14f400 bl 0xb65b0 <memset@plt> */
/* @0x14f404 mov r1, r10 */
/* @0x14f408 mov r0, r4 */
/* @0x14f40c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f410 ldr r2, [pc, #0x88] */
/* @0x14f414 mov r1, #256 */
/* @0x14f418 add r2, pc, r2 */
/* @0x14f41c mov r3, r0 */
/* @0x14f420 mov r0, r5 */
/* @0x14f424 bl 0xb65c8 <snprintf@plt> */
/* @0x14f428 mov r0, r5 */
/* @0x14f42c mov r1, r10 */
/* @0x14f430 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f434 b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x14f438 add r5, sp, #52 */
/* @0x14f43c mov r1, r8 */
/* @0x14f440 mov r2, #256 */
/* @0x14f444 mov r0, r5 */
/* @0x14f448 bl 0xb65b0 <memset@plt> */
/* @0x14f44c mov r0, r4 */
/* @0x14f450 mov r1, #1 */
/* @0x14f454 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f458 ldr r2, [pc, #0x44] */
/* @0x14f45c mov r1, #256 */
/* @0x14f460 add r2, pc, r2 */
/* @0x14f464 mov r3, r0 */
/* @0x14f468 mov r0, r5 */
/* @0x14f46c bl 0xb65c8 <snprintf@plt> */
/* @0x14f470 mov r0, r5 */
/* @0x14f474 mov r1, r8 */
/* @0x14f478 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f47c b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x14f480 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14f484 ldrdmi r0, r1, [r9], #-251 */
/* @0x14f488 teqmi r4, #0 */
/* @0x14f48c eoreq r2, r10, r4, ror #20 */
/* @0x14f490 .word 0xffffbd00 */
/* @0x14f494 .word 0xffffbcd8 */
/* @0x14f498 andseq r5, pc, r12, lsr #21 */
/* @0x14f49c andseq r4, pc, r0, asr #20 */
/* @0x14f4a0 andseq r5, pc, r8, lsl #19 */
/* @0x14f4a4 andseq r5, pc, r0, asr #18 */

/* ── FUNC 0x14f4a8 · F_PhysicsCreatePrismaticJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=744 · insn=186 */
/* @0x14f4a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14f4ac sub sp, sp, #340 */
/* @0x14f4b0 ldr r9, [pc, #0x2bc] */
/* @0x14f4b4 mov r7, r2 */
/* @0x14f4b8 ldr r12, [pc, #0x2b8] */
/* @0x14f4bc mov r3, #0 */
/* @0x14f4c0 add r9, pc, r9 */
/* @0x14f4c4 ldr r4, [sp, #0x178] */
/* @0x14f4c8 mov r5, r0 */
/* @0x14f4cc mov r8, r1 */
/* @0x14f4d0 ldr r6, [r9, r12] */
/* @0x14f4d4 mov r0, r3 */
/* @0x14f4d8 mov r1, r3 */
/* @0x14f4dc movt r0, #0xbff0 */
/* @0x14f4e0 str r3, [r5, #0xc] */
/* @0x14f4e4 ldr r2, [r6] */
/* @0x14f4e8 str r0, [r5, #0x4] */
/* @0x14f4ec mov r0, r4 */
/* @0x14f4f0 str r3, [r5] */
/* @0x14f4f4 str r2, [sp, #0x14c] */
/* @0x14f4f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f4fc mov r1, r8 */
/* @0x14f500 mov r2, r7 */
/* @0x14f504 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14f508 subs r10, r0, #0 */
/* @0x14f50c beq 0x14f6e0 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x14f510 mov r1, #1 */
/* @0x14f514 mov r0, r4 */
/* @0x14f518 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f51c mov r1, r8 */
/* @0x14f520 mov r2, r7 */
/* @0x14f524 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14f528 subs r8, r0, #0 */
/* @0x14f52c beq 0x14f728 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x14f530 ldr r7, [r10, #0x84] */
/* @0x14f534 cmp r7, #0 */
/* @0x14f538 beq 0x14f6a0 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x14f53c ldr r8, [r8, #0x84] */
/* @0x14f540 cmp r8, #0 */
/* @0x14f544 beq 0x14f6a0 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x14f548 ldr r3, [pc, #0x22c] */
/* @0x14f54c ldr r3, [r9, r3] */
/* @0x14f550 ldr r3, [r3] */
/* @0x14f554 ldr r9, [r3, #0xb4] */
/* @0x14f558 cmp r9, #0 */
/* @0x14f55c beq 0x14f6cc <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x14f560 mov r1, #2 */
/* @0x14f564 mov r0, r4 */
/* @0x14f568 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f56c mov r1, #3 */
/* @0x14f570 mov r3, r0 */
/* @0x14f574 mov r0, r4 */
/* @0x14f578 str r3, [sp, #0x28] */
/* @0x14f57c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f580 mov r1, #4 */
/* @0x14f584 mov r12, r0 */
/* @0x14f588 mov r0, r4 */
/* @0x14f58c str r12, [sp, #0x2c] */
/* @0x14f590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f594 mov r1, #5 */
/* @0x14f598 str r0, [sp, #0x34] */
/* @0x14f59c mov r0, r4 */
/* @0x14f5a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f5a4 mov r1, #6 */
/* @0x14f5a8 str r0, [sp, #0x38] */
/* @0x14f5ac mov r0, r4 */
/* @0x14f5b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f5b4 mov r1, #7 */
/* @0x14f5b8 str r0, [sp, #0x3c] */
/* @0x14f5bc mov r0, r4 */
/* @0x14f5c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f5c4 mov r1, #8 */
/* @0x14f5c8 str r0, [sp, #0x40] */
/* @0x14f5cc mov r0, r4 */
/* @0x14f5d0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f5d4 mov r1, #9 */
/* @0x14f5d8 mov r2, r0 */
/* @0x14f5dc mov r0, r4 */
/* @0x14f5e0 str r2, [sp, #0x30] */
/* @0x14f5e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f5e8 mov r1, #10 */
/* @0x14f5ec str r0, [sp, #0x44] */
/* @0x14f5f0 mov r0, r4 */
/* @0x14f5f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f5f8 mov r1, #11 */
/* @0x14f5fc mov r11, r0 */
/* @0x14f600 mov r0, r4 */
/* @0x14f604 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f608 mov r1, #12 */
/* @0x14f60c mov r10, r0 */
/* @0x14f610 mov r0, r4 */
/* @0x14f614 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f618 ldr r1, [sp, #0x34] */
/* @0x14f61c ldr r2, [sp, #0x30] */
/* @0x14f620 ldr r12, [sp, #0x2c] */
/* @0x14f624 str r1, [sp, #0x4] */
/* @0x14f628 ldr r1, [sp, #0x38] */
/* @0x14f62c str r2, [sp, #0x14] */
/* @0x14f630 ldr r2, [sp, #0x44] */
/* @0x14f634 str r1, [sp, #0x8] */
/* @0x14f638 ldr r1, [sp, #0x3c] */
/* @0x14f63c str r2, [sp, #0x18] */
/* @0x14f640 mov r2, r8 */
/* @0x14f644 ldr r3, [sp, #0x28] */
/* @0x14f648 str r1, [sp, #0xc] */
/* @0x14f64c ldr r1, [sp, #0x40] */
/* @0x14f650 str r12, [sp] */
/* @0x14f654 str r11, [sp, #0x1c] */
/* @0x14f658 str r1, [sp, #0x10] */
/* @0x14f65c mov r1, r7 */
/* @0x14f660 str r10, [sp, #0x20] */
/* @0x14f664 str r0, [sp, #0x24] */
/* @0x14f668 mov r0, r9 */
/* @0x14f66c bl 0x239164 <_ZN13CPhysicsWorld20CreatePrismaticJointEP14CPhysicsObjectS1_ffffffbffbb> */
/* @0x14f670 vmov s15, r0 */
/* @0x14f674 vcvt.f64.s32 d7, s15 */
/* @0x14f678 vmov r0, r1, d7 */
/* @0x14f67c vmov r2, s14 */
/* @0x14f680 mov r3, r1 */
/* @0x14f684 stm r5, {r2, r3} */
/* @0x14f688 ldr r2, [sp, #0x14c] */
/* @0x14f68c ldr r3, [r6] */
/* @0x14f690 cmp r2, r3 */
/* @0x14f694 bne 0x14f770 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x14f698 add sp, sp, #340 */
/* @0x14f69c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14f6a0 ldr r3, [pc, #0xd4] */
/* @0x14f6a4 ldr r3, [r9, r3] */
/* @0x14f6a8 ldr r3, [r3] */
/* @0x14f6ac ldr r3, [r3, #0xb4] */
/* @0x14f6b0 cmp r3, #0 */
/* @0x14f6b4 beq 0x14f6cc <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x14f6b8 ldr r0, [pc, #0xc0] */
/* @0x14f6bc mov r1, #0 */
/* @0x14f6c0 add r0, pc, r0 */
/* @0x14f6c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f6c8 b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f6cc ldr r0, [pc, #0xb0] */
/* @0x14f6d0 mov r1, #0 */
/* @0x14f6d4 add r0, pc, r0 */
/* @0x14f6d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f6dc b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f6e0 add r5, sp, #76 */
/* @0x14f6e4 mov r1, r10 */
/* @0x14f6e8 mov r2, #256 */
/* @0x14f6ec mov r0, r5 */
/* @0x14f6f0 bl 0xb65b0 <memset@plt> */
/* @0x14f6f4 mov r1, r10 */
/* @0x14f6f8 mov r0, r4 */
/* @0x14f6fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f700 ldr r2, [pc, #0x80] */
/* @0x14f704 mov r1, #256 */
/* @0x14f708 add r2, pc, r2 */
/* @0x14f70c mov r3, r0 */
/* @0x14f710 mov r0, r5 */
/* @0x14f714 bl 0xb65c8 <snprintf@plt> */
/* @0x14f718 mov r0, r5 */
/* @0x14f71c mov r1, r10 */
/* @0x14f720 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f724 b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f728 add r5, sp, #76 */
/* @0x14f72c mov r1, r8 */
/* @0x14f730 mov r2, #256 */
/* @0x14f734 mov r0, r5 */
/* @0x14f738 bl 0xb65b0 <memset@plt> */
/* @0x14f73c mov r0, r4 */
/* @0x14f740 mov r1, #1 */
/* @0x14f744 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f748 ldr r2, [pc, #0x3c] */
/* @0x14f74c mov r1, #256 */
/* @0x14f750 add r2, pc, r2 */
/* @0x14f754 mov r3, r0 */
/* @0x14f758 mov r0, r5 */
/* @0x14f75c bl 0xb65c8 <snprintf@plt> */
/* @0x14f760 mov r0, r5 */
/* @0x14f764 mov r1, r8 */
/* @0x14f768 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f76c b 0x14f688 <_Z29F_PhysicsCreatePrismaticJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f770 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14f774 mlaeq r10, r0, r7, r2 */
/* @0x14f778 .word 0xffffbd00 */
/* @0x14f77c .word 0xffffbcd8 */
/* @0x14f780 andseq r5, pc, r12, lsl r8 */
/* @0x14f784 andseq r4, pc, r0, asr r7 */
/* @0x14f788 mulseq pc, r8, r6 */
/* @0x14f78c andseq r5, pc, r0, asr r6 */

/* ── FUNC 0x14f790 · F_PhysicsCreatePulleyJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=720 · insn=180 */
/* @0x14f790 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14f794 sub sp, sp, #340 */
/* @0x14f798 ldr r9, [pc, #0x2a4] */
/* @0x14f79c mov r7, r2 */
/* @0x14f7a0 ldr r12, [pc, #0x2a0] */
/* @0x14f7a4 mov r3, #0 */
/* @0x14f7a8 add r9, pc, r9 */
/* @0x14f7ac ldr r4, [sp, #0x178] */
/* @0x14f7b0 mov r5, r0 */
/* @0x14f7b4 mov r8, r1 */
/* @0x14f7b8 ldr r6, [r9, r12] */
/* @0x14f7bc mov r0, r3 */
/* @0x14f7c0 mov r1, r3 */
/* @0x14f7c4 movt r0, #0xbff0 */
/* @0x14f7c8 str r3, [r5, #0xc] */
/* @0x14f7cc ldr r2, [r6] */
/* @0x14f7d0 str r0, [r5, #0x4] */
/* @0x14f7d4 mov r0, r4 */
/* @0x14f7d8 str r3, [r5] */
/* @0x14f7dc str r2, [sp, #0x14c] */
/* @0x14f7e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f7e4 mov r1, r8 */
/* @0x14f7e8 mov r2, r7 */
/* @0x14f7ec bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14f7f0 subs r10, r0, #0 */
/* @0x14f7f4 beq 0x14f9b0 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x14f7f8 mov r1, #1 */
/* @0x14f7fc mov r0, r4 */
/* @0x14f800 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f804 mov r1, r8 */
/* @0x14f808 mov r2, r7 */
/* @0x14f80c bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14f810 subs r8, r0, #0 */
/* @0x14f814 beq 0x14f9f8 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x14f818 ldr r7, [r10, #0x84] */
/* @0x14f81c cmp r7, #0 */
/* @0x14f820 beq 0x14f970 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f824 ldr r8, [r8, #0x84] */
/* @0x14f828 cmp r8, #0 */
/* @0x14f82c beq 0x14f970 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14f830 ldr r3, [pc, #0x214] */
/* @0x14f834 ldr r3, [r9, r3] */
/* @0x14f838 ldr r3, [r3] */
/* @0x14f83c ldr r9, [r3, #0xb4] */
/* @0x14f840 cmp r9, #0 */
/* @0x14f844 beq 0x14f99c <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14f848 mov r1, #2 */
/* @0x14f84c mov r0, r4 */
/* @0x14f850 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f854 mov r1, #3 */
/* @0x14f858 mov r3, r0 */
/* @0x14f85c mov r0, r4 */
/* @0x14f860 str r3, [sp, #0x2c] */
/* @0x14f864 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f868 mov r1, #4 */
/* @0x14f86c mov r12, r0 */
/* @0x14f870 mov r0, r4 */
/* @0x14f874 str r12, [sp, #0x30] */
/* @0x14f878 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f87c mov r1, #5 */
/* @0x14f880 mov r2, r0 */
/* @0x14f884 mov r0, r4 */
/* @0x14f888 str r2, [sp, #0x34] */
/* @0x14f88c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f890 mov r1, #6 */
/* @0x14f894 str r0, [sp, #0x38] */
/* @0x14f898 mov r0, r4 */
/* @0x14f89c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f8a0 mov r1, #7 */
/* @0x14f8a4 str r0, [sp, #0x3c] */
/* @0x14f8a8 mov r0, r4 */
/* @0x14f8ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f8b0 mov r1, #8 */
/* @0x14f8b4 str r0, [sp, #0x40] */
/* @0x14f8b8 mov r0, r4 */
/* @0x14f8bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f8c0 mov r1, #9 */
/* @0x14f8c4 str r0, [sp, #0x44] */
/* @0x14f8c8 mov r0, r4 */
/* @0x14f8cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f8d0 mov r1, #10 */
/* @0x14f8d4 mov r11, r0 */
/* @0x14f8d8 mov r0, r4 */
/* @0x14f8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14f8e0 mov r1, #11 */
/* @0x14f8e4 mov r10, r0 */
/* @0x14f8e8 mov r0, r4 */
/* @0x14f8ec bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14f8f0 ldr r2, [sp, #0x34] */
/* @0x14f8f4 ldr r12, [sp, #0x30] */
/* @0x14f8f8 mov r1, r7 */
/* @0x14f8fc ldr r3, [sp, #0x2c] */
/* @0x14f900 str r2, [sp, #0x4] */
/* @0x14f904 ldr r2, [sp, #0x38] */
/* @0x14f908 str r12, [sp] */
/* @0x14f90c str r11, [sp, #0x18] */
/* @0x14f910 str r2, [sp, #0x8] */
/* @0x14f914 ldr r2, [sp, #0x3c] */
/* @0x14f918 str r10, [sp, #0x1c] */
/* @0x14f91c str r2, [sp, #0xc] */
/* @0x14f920 ldr r2, [sp, #0x40] */
/* @0x14f924 str r2, [sp, #0x10] */
/* @0x14f928 ldr r2, [sp, #0x44] */
/* @0x14f92c str r2, [sp, #0x14] */
/* @0x14f930 mov r2, r8 */
/* @0x14f934 str r0, [sp, #0x20] */
/* @0x14f938 mov r0, r9 */
/* @0x14f93c bl 0x2392a8 <_ZN13CPhysicsWorld17CreatePulleyJointEP14CPhysicsObjectS1_fffffffffb> */
/* @0x14f940 vmov s15, r0 */
/* @0x14f944 vcvt.f64.s32 d7, s15 */
/* @0x14f948 vmov r0, r1, d7 */
/* @0x14f94c vmov r2, s14 */
/* @0x14f950 mov r3, r1 */
/* @0x14f954 stm r5, {r2, r3} */
/* @0x14f958 ldr r2, [sp, #0x14c] */
/* @0x14f95c ldr r3, [r6] */
/* @0x14f960 cmp r2, r3 */
/* @0x14f964 bne 0x14fa40 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x14f968 add sp, sp, #340 */
/* @0x14f96c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14f970 ldr r3, [pc, #0xd4] */
/* @0x14f974 ldr r3, [r9, r3] */
/* @0x14f978 ldr r3, [r3] */
/* @0x14f97c ldr r3, [r3, #0xb4] */
/* @0x14f980 cmp r3, #0 */
/* @0x14f984 beq 0x14f99c <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14f988 ldr r0, [pc, #0xc0] */
/* @0x14f98c mov r1, #0 */
/* @0x14f990 add r0, pc, r0 */
/* @0x14f994 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f998 b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14f99c ldr r0, [pc, #0xb0] */
/* @0x14f9a0 mov r1, #0 */
/* @0x14f9a4 add r0, pc, r0 */
/* @0x14f9a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f9ac b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14f9b0 add r5, sp, #76 */
/* @0x14f9b4 mov r1, r10 */
/* @0x14f9b8 mov r2, #256 */
/* @0x14f9bc mov r0, r5 */
/* @0x14f9c0 bl 0xb65b0 <memset@plt> */
/* @0x14f9c4 mov r1, r10 */
/* @0x14f9c8 mov r0, r4 */
/* @0x14f9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14f9d0 ldr r2, [pc, #0x80] */
/* @0x14f9d4 mov r1, #256 */
/* @0x14f9d8 add r2, pc, r2 */
/* @0x14f9dc mov r3, r0 */
/* @0x14f9e0 mov r0, r5 */
/* @0x14f9e4 bl 0xb65c8 <snprintf@plt> */
/* @0x14f9e8 mov r0, r5 */
/* @0x14f9ec mov r1, r10 */
/* @0x14f9f0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14f9f4 b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14f9f8 add r5, sp, #76 */
/* @0x14f9fc mov r1, r8 */
/* @0x14fa00 mov r2, #256 */
/* @0x14fa04 mov r0, r5 */
/* @0x14fa08 bl 0xb65b0 <memset@plt> */
/* @0x14fa0c mov r0, r4 */
/* @0x14fa10 mov r1, #1 */
/* @0x14fa14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fa18 ldr r2, [pc, #0x3c] */
/* @0x14fa1c mov r1, #256 */
/* @0x14fa20 add r2, pc, r2 */
/* @0x14fa24 mov r3, r0 */
/* @0x14fa28 mov r0, r5 */
/* @0x14fa2c bl 0xb65c8 <snprintf@plt> */
/* @0x14fa30 mov r0, r5 */
/* @0x14fa34 mov r1, r8 */
/* @0x14fa38 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fa3c b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14fa40 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14fa44 eoreq r2, r10, r8, lsr #9 */
/* @0x14fa48 .word 0xffffbd00 */
/* @0x14fa4c .word 0xffffbcd8 */
/* @0x14fa50 andseq r5, pc, r12, lsr #11 */
/* @0x14fa54 andseq r4, pc, r0, lsl #9 */
/* @0x14fa58 andseq r5, pc, r8, asr #7 */
/* @0x14fa5c andseq r5, pc, r0, lsl #7 */

/* ── FUNC 0x14fa60 · F_PhysicsCreateWheelJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=720 · insn=180 */
/* @0x14fa60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14fa64 sub sp, sp, #340 */
/* @0x14fa68 ldr r9, [pc, #0x2a4] */
/* @0x14fa6c mov r7, r2 */
/* @0x14fa70 ldr r12, [pc, #0x2a0] */
/* @0x14fa74 mov r3, #0 */
/* @0x14fa78 add r9, pc, r9 */
/* @0x14fa7c ldr r4, [sp, #0x178] */
/* @0x14fa80 mov r5, r0 */
/* @0x14fa84 mov r8, r1 */
/* @0x14fa88 ldr r6, [r9, r12] */
/* @0x14fa8c mov r0, r3 */
/* @0x14fa90 mov r1, r3 */
/* @0x14fa94 movt r0, #0xbff0 */
/* @0x14fa98 str r3, [r5, #0xc] */
/* @0x14fa9c ldr r2, [r6] */
/* @0x14faa0 str r0, [r5, #0x4] */
/* @0x14faa4 mov r0, r4 */
/* @0x14faa8 str r3, [r5] */
/* @0x14faac str r2, [sp, #0x14c] */
/* @0x14fab0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fab4 mov r1, r8 */
/* @0x14fab8 mov r2, r7 */
/* @0x14fabc bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14fac0 subs r10, r0, #0 */
/* @0x14fac4 beq 0x14fc80 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x14fac8 mov r1, #1 */
/* @0x14facc mov r0, r4 */
/* @0x14fad0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fad4 mov r1, r8 */
/* @0x14fad8 mov r2, r7 */
/* @0x14fadc bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14fae0 subs r8, r0, #0 */
/* @0x14fae4 beq 0x14fcc8 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x14fae8 ldr r7, [r10, #0x84] */
/* @0x14faec cmp r7, #0 */
/* @0x14faf0 beq 0x14fc40 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14faf4 ldr r8, [r8, #0x84] */
/* @0x14faf8 cmp r8, #0 */
/* @0x14fafc beq 0x14fc40 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x14fb00 ldr r3, [pc, #0x214] */
/* @0x14fb04 ldr r3, [r9, r3] */
/* @0x14fb08 ldr r3, [r3] */
/* @0x14fb0c ldr r9, [r3, #0xb4] */
/* @0x14fb10 cmp r9, #0 */
/* @0x14fb14 beq 0x14fc6c <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14fb18 mov r1, #2 */
/* @0x14fb1c mov r0, r4 */
/* @0x14fb20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fb24 mov r1, #3 */
/* @0x14fb28 mov r3, r0 */
/* @0x14fb2c mov r0, r4 */
/* @0x14fb30 str r3, [sp, #0x2c] */
/* @0x14fb34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fb38 mov r1, #4 */
/* @0x14fb3c mov r12, r0 */
/* @0x14fb40 mov r0, r4 */
/* @0x14fb44 str r12, [sp, #0x30] */
/* @0x14fb48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fb4c mov r1, #5 */
/* @0x14fb50 mov r2, r0 */
/* @0x14fb54 mov r0, r4 */
/* @0x14fb58 str r2, [sp, #0x34] */
/* @0x14fb5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fb60 mov r1, #6 */
/* @0x14fb64 str r0, [sp, #0x38] */
/* @0x14fb68 mov r0, r4 */
/* @0x14fb6c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14fb70 mov r1, #7 */
/* @0x14fb74 str r0, [sp, #0x44] */
/* @0x14fb78 mov r0, r4 */
/* @0x14fb7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fb80 mov r1, #8 */
/* @0x14fb84 str r0, [sp, #0x3c] */
/* @0x14fb88 mov r0, r4 */
/* @0x14fb8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fb90 mov r1, #9 */
/* @0x14fb94 str r0, [sp, #0x40] */
/* @0x14fb98 mov r0, r4 */
/* @0x14fb9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fba0 mov r1, #10 */
/* @0x14fba4 mov r11, r0 */
/* @0x14fba8 mov r0, r4 */
/* @0x14fbac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fbb0 mov r1, #11 */
/* @0x14fbb4 mov r10, r0 */
/* @0x14fbb8 mov r0, r4 */
/* @0x14fbbc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14fbc0 ldr r2, [sp, #0x34] */
/* @0x14fbc4 ldr r12, [sp, #0x30] */
/* @0x14fbc8 mov r1, r7 */
/* @0x14fbcc ldr r3, [sp, #0x2c] */
/* @0x14fbd0 str r2, [sp, #0x4] */
/* @0x14fbd4 ldr r2, [sp, #0x38] */
/* @0x14fbd8 str r12, [sp] */
/* @0x14fbdc str r11, [sp, #0x18] */
/* @0x14fbe0 str r2, [sp, #0x8] */
/* @0x14fbe4 ldr r2, [sp, #0x44] */
/* @0x14fbe8 str r10, [sp, #0x1c] */
/* @0x14fbec str r2, [sp, #0xc] */
/* @0x14fbf0 ldr r2, [sp, #0x3c] */
/* @0x14fbf4 str r2, [sp, #0x10] */
/* @0x14fbf8 ldr r2, [sp, #0x40] */
/* @0x14fbfc str r2, [sp, #0x14] */
/* @0x14fc00 mov r2, r8 */
/* @0x14fc04 str r0, [sp, #0x20] */
/* @0x14fc08 mov r0, r9 */
/* @0x14fc0c bl 0x239444 <_ZN13CPhysicsWorld16CreateWheelJointEP14CPhysicsObjectS1_ffffbffffb> */
/* @0x14fc10 vmov s15, r0 */
/* @0x14fc14 vcvt.f64.s32 d7, s15 */
/* @0x14fc18 vmov r0, r1, d7 */
/* @0x14fc1c vmov r2, s14 */
/* @0x14fc20 mov r3, r1 */
/* @0x14fc24 stm r5, {r2, r3} */
/* @0x14fc28 ldr r2, [sp, #0x14c] */
/* @0x14fc2c ldr r3, [r6] */
/* @0x14fc30 cmp r2, r3 */
/* @0x14fc34 bne 0x14fd10 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x14fc38 add sp, sp, #340 */
/* @0x14fc3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x14fc40 ldr r3, [pc, #0xd4] */
/* @0x14fc44 ldr r3, [r9, r3] */
/* @0x14fc48 ldr r3, [r3] */
/* @0x14fc4c ldr r3, [r3, #0xb4] */
/* @0x14fc50 cmp r3, #0 */
/* @0x14fc54 beq 0x14fc6c <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14fc58 ldr r0, [pc, #0xc0] */
/* @0x14fc5c mov r1, #0 */
/* @0x14fc60 add r0, pc, r0 */
/* @0x14fc64 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fc68 b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14fc6c ldr r0, [pc, #0xb0] */
/* @0x14fc70 mov r1, #0 */
/* @0x14fc74 add r0, pc, r0 */
/* @0x14fc78 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fc7c b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14fc80 add r5, sp, #76 */
/* @0x14fc84 mov r1, r10 */
/* @0x14fc88 mov r2, #256 */
/* @0x14fc8c mov r0, r5 */
/* @0x14fc90 bl 0xb65b0 <memset@plt> */
/* @0x14fc94 mov r1, r10 */
/* @0x14fc98 mov r0, r4 */
/* @0x14fc9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fca0 ldr r2, [pc, #0x80] */
/* @0x14fca4 mov r1, #256 */
/* @0x14fca8 add r2, pc, r2 */
/* @0x14fcac mov r3, r0 */
/* @0x14fcb0 mov r0, r5 */
/* @0x14fcb4 bl 0xb65c8 <snprintf@plt> */
/* @0x14fcb8 mov r0, r5 */
/* @0x14fcbc mov r1, r10 */
/* @0x14fcc0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fcc4 b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14fcc8 add r5, sp, #76 */
/* @0x14fccc mov r1, r8 */
/* @0x14fcd0 mov r2, #256 */
/* @0x14fcd4 mov r0, r5 */
/* @0x14fcd8 bl 0xb65b0 <memset@plt> */
/* @0x14fcdc mov r0, r4 */
/* @0x14fce0 mov r1, #1 */
/* @0x14fce4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fce8 ldr r2, [pc, #0x3c] */
/* @0x14fcec mov r1, #256 */
/* @0x14fcf0 add r2, pc, r2 */
/* @0x14fcf4 mov r3, r0 */
/* @0x14fcf8 mov r0, r5 */
/* @0x14fcfc bl 0xb65c8 <snprintf@plt> */
/* @0x14fd00 mov r0, r5 */
/* @0x14fd04 mov r1, r8 */
/* @0x14fd08 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fd0c b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x14fd10 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14fd14 .word 0x002a21d8 */
/* @0x14fd18 .word 0xffffbd00 */
/* @0x14fd1c .word 0xffffbcd8 */
/* @0x14fd20 ldrsbeq r5, [pc], -r12 */
/* @0x14fd24 ldrheq r4, [pc], -r0 */
/* @0x14fd28 ldrsheq r5, [pc], -r8 */
/* @0x14fd2c ldrheq r5, [pc], -r0 */

/* ── FUNC 0x14fd30 · F_PhysicsCreateGearJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=568 · insn=142 */
/* @0x14fd30 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x14fd34 sub sp, sp, #272 */
/* @0x14fd38 ldr r5, [pc, #0x208] */
/* @0x14fd3c mov r7, r2 */
/* @0x14fd40 ldr lr, [pc, #0x204] */
/* @0x14fd44 mov r3, r0 */
/* @0x14fd48 add r5, pc, r5 */
/* @0x14fd4c ldr r4, [sp, #0x130] */
/* @0x14fd50 mov r12, #0 */
/* @0x14fd54 mov r8, r1 */
/* @0x14fd58 ldr r6, [r5, lr] */
/* @0x14fd5c mov r0, r12 */
/* @0x14fd60 mov r1, r12 */
/* @0x14fd64 movt r0, #0xbff0 */
/* @0x14fd68 str r12, [r3, #0xc] */
/* @0x14fd6c ldr r2, [r6] */
/* @0x14fd70 str r0, [r3, #0x4] */
/* @0x14fd74 mov r0, r4 */
/* @0x14fd78 str r12, [r3] */
/* @0x14fd7c str r2, [sp, #0x10c] */
/* @0x14fd80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fd84 mov r1, r8 */
/* @0x14fd88 mov r2, r7 */
/* @0x14fd8c bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14fd90 subs r9, r0, #0 */
/* @0x14fd94 beq 0x14fea0 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x14fd98 mov r1, #1 */
/* @0x14fd9c mov r0, r4 */
/* @0x14fda0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fda4 mov r1, r8 */
/* @0x14fda8 mov r2, r7 */
/* @0x14fdac bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14fdb0 subs r10, r0, #0 */
/* @0x14fdb4 beq 0x14fefc <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x14fdb8 ldr r3, [r9, #0x84] */
/* @0x14fdbc cmp r3, #0 */
/* @0x14fdc0 beq 0x14fe50 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x14fdc4 ldr r3, [r10, #0x84] */
/* @0x14fdc8 cmp r3, #0 */
/* @0x14fdcc beq 0x14fe50 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x14fdd0 mov r1, #2 */
/* @0x14fdd4 mov r0, r4 */
/* @0x14fdd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fddc bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj> */
/* @0x14fde0 mov r1, #3 */
/* @0x14fde4 mov r7, r0 */
/* @0x14fde8 mov r0, r4 */
/* @0x14fdec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fdf0 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj> */
/* @0x14fdf4 cmp r0, #0 */
/* @0x14fdf8 cmpne r7, #0 */
/* @0x14fdfc mov r8, r0 */
/* @0x14fe00 moveq r1, #0 */
/* @0x14fe04 movne r1, #1 */
/* @0x14fe08 beq 0x14fe90 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x14fe0c ldr r3, [pc, #0x13c] */
/* @0x14fe10 ldr r3, [r5, r3] */
/* @0x14fe14 ldr r3, [r3] */
/* @0x14fe18 ldr r5, [r3, #0xb4] */
/* @0x14fe1c cmp r5, #0 */
/* @0x14fe20 beq 0x14fee8 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x14fe24 mov r0, r4 */
/* @0x14fe28 mov r1, #4 */
/* @0x14fe2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14fe30 ldr r1, [r9, #0x84] */
/* @0x14fe34 ldr r2, [r10, #0x84] */
/* @0x14fe38 mov r3, r7 */
/* @0x14fe3c str r8, [sp] */
/* @0x14fe40 str r0, [sp, #0x4] */
/* @0x14fe44 mov r0, r5 */
/* @0x14fe48 bl 0x23974c <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f> */
/* @0x14fe4c b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x14fe50 ldr r3, [pc, #0xf8] */
/* @0x14fe54 ldr r3, [r5, r3] */
/* @0x14fe58 ldr r3, [r3] */
/* @0x14fe5c ldr r3, [r3, #0xb4] */
/* @0x14fe60 cmp r3, #0 */
/* @0x14fe64 beq 0x14fee8 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x14fe68 ldr r0, [pc, #0xe4] */
/* @0x14fe6c mov r1, #0 */
/* @0x14fe70 add r0, pc, r0 */
/* @0x14fe74 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fe78 ldr r2, [sp, #0x10c] */
/* @0x14fe7c ldr r3, [r6] */
/* @0x14fe80 cmp r2, r3 */
/* @0x14fe84 bne 0x14ff44 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x14fe88 add sp, sp, #272 */
/* @0x14fe8c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x14fe90 ldr r0, [pc, #0xc0] */
/* @0x14fe94 add r0, pc, r0 */
/* @0x14fe98 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fe9c b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x14fea0 add r5, sp, #12 */
/* @0x14fea4 mov r1, r9 */
/* @0x14fea8 mov r2, #256 */
/* @0x14feac mov r0, r5 */
/* @0x14feb0 bl 0xb65b0 <memset@plt> */
/* @0x14feb4 mov r1, r9 */
/* @0x14feb8 mov r0, r4 */
/* @0x14febc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14fec0 ldr r2, [pc, #0x94] */
/* @0x14fec4 mov r1, #256 */
/* @0x14fec8 add r2, pc, r2 */
/* @0x14fecc mov r3, r0 */
/* @0x14fed0 mov r0, r5 */
/* @0x14fed4 bl 0xb65c8 <snprintf@plt> */
/* @0x14fed8 mov r0, r5 */
/* @0x14fedc mov r1, r9 */
/* @0x14fee0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fee4 b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x14fee8 ldr r0, [pc, #0x70] */
/* @0x14feec mov r1, #0 */
/* @0x14fef0 add r0, pc, r0 */
/* @0x14fef4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14fef8 b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x14fefc add r5, sp, #12 */
/* @0x14ff00 mov r1, r10 */
/* @0x14ff04 mov r2, #256 */
/* @0x14ff08 mov r0, r5 */
/* @0x14ff0c bl 0xb65b0 <memset@plt> */
/* @0x14ff10 mov r0, r4 */
/* @0x14ff14 mov r1, #1 */
/* @0x14ff18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ff1c ldr r2, [pc, #0x40] */
/* @0x14ff20 mov r1, #256 */
/* @0x14ff24 add r2, pc, r2 */
/* @0x14ff28 mov r3, r0 */
/* @0x14ff2c mov r0, r5 */
/* @0x14ff30 bl 0xb65c8 <snprintf@plt> */
/* @0x14ff34 mov r0, r5 */
/* @0x14ff38 mov r1, r10 */
/* @0x14ff3c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14ff40 b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x14ff44 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x14ff48 eoreq r1, r10, r8, lsl #30 */
/* @0x14ff4c .word 0xffffbd00 */
/* @0x14ff50 .word 0xffffbcd8 */
/* @0x14ff54 andseq r5, pc, r8, lsr #2 */
/* @0x14ff58 andseq r3, pc, r8, lsr pc */
/* @0x14ff5c ldrsbeq r4, [pc], -r8 */
/* @0x14ff60 andseq r3, pc, r4, lsr pc */
/* @0x14ff64 andseq r4, pc, r12, ror lr */

/* ── FUNC 0x14ff68 · F_PhysicsCreateWeldJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=628 · insn=157 */
/* @0x14ff68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14ff6c sub sp, sp, #308 */
/* @0x14ff70 ldr r6, [pc, #0x248] */
/* @0x14ff74 mov r8, r2 */
/* @0x14ff78 ldr r12, [pc, #0x244] */
/* @0x14ff7c mov r3, #0 */
/* @0x14ff80 add r6, pc, r6 */
/* @0x14ff84 ldr r4, [sp, #0x158] */
/* @0x14ff88 mov r5, r0 */
/* @0x14ff8c mov r9, r1 */
/* @0x14ff90 ldr r7, [r6, r12] */
/* @0x14ff94 mov r0, r3 */
/* @0x14ff98 mov r1, r3 */
/* @0x14ff9c movt r0, #0xbff0 */
/* @0x14ffa0 str r3, [r5, #0xc] */
/* @0x14ffa4 ldr r2, [r7] */
/* @0x14ffa8 str r0, [r5, #0x4] */
/* @0x14ffac mov r0, r4 */
/* @0x14ffb0 str r3, [r5] */
/* @0x14ffb4 str r2, [sp, #0x12c] */
/* @0x14ffb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ffbc mov r1, r9 */
/* @0x14ffc0 mov r2, r8 */
/* @0x14ffc4 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14ffc8 subs r10, r0, #0 */
/* @0x14ffcc beq 0x15012c <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x14ffd0 mov r1, #1 */
/* @0x14ffd4 mov r0, r4 */
/* @0x14ffd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14ffdc mov r1, r9 */
/* @0x14ffe0 mov r2, r8 */
/* @0x14ffe4 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x14ffe8 subs r9, r0, #0 */
/* @0x14ffec beq 0x150174 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x14fff0 ldr r8, [r10, #0x84] */
/* @0x14fff4 cmp r8, #0 */
/* @0x14fff8 beq 0x1500ec <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x14fffc ldr r9, [r9, #0x84] */
/* @0x150000 cmp r9, #0 */
/* @0x150004 beq 0x1500ec <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x150008 ldr r3, [pc, #0x1b8] */
/* @0x15000c ldr r3, [r6, r3] */
/* @0x150010 ldr r3, [r3] */
/* @0x150014 ldr r6, [r3, #0xb4] */
/* @0x150018 cmp r6, #0 */
/* @0x15001c beq 0x150118 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x150020 mov r1, #2 */
/* @0x150024 mov r0, r4 */
/* @0x150028 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x15002c mov r1, #3 */
/* @0x150030 mov r10, r0 */
/* @0x150034 mov r0, r4 */
/* @0x150038 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x15003c mov r1, #4 */
/* @0x150040 mov r12, r0 */
/* @0x150044 mov r0, r4 */
/* @0x150048 str r12, [sp, #0x1c] */
/* @0x15004c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x150050 mov r1, #5 */
/* @0x150054 mov r2, r0 */
/* @0x150058 mov r0, r4 */
/* @0x15005c str r2, [sp, #0x20] */
/* @0x150060 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x150064 mov r1, #6 */
/* @0x150068 mov r3, r0 */
/* @0x15006c mov r0, r4 */
/* @0x150070 str r3, [sp, #0x24] */
/* @0x150074 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x150078 mov r1, #7 */
/* @0x15007c mov r11, r0 */
/* @0x150080 mov r0, r4 */
/* @0x150084 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x150088 ldr r2, [sp, #0x20] */
/* @0x15008c ldr r3, [sp, #0x24] */
/* @0x150090 mov r1, r8 */
/* @0x150094 ldr r12, [sp, #0x1c] */
/* @0x150098 str r2, [sp, #0x4] */
/* @0x15009c mov r2, r9 */
/* @0x1500a0 str r3, [sp, #0x8] */
/* @0x1500a4 mov r3, r10 */
/* @0x1500a8 str r12, [sp] */
/* @0x1500ac str r11, [sp, #0xc] */
/* @0x1500b0 str r0, [sp, #0x10] */
/* @0x1500b4 mov r0, r6 */
/* @0x1500b8 bl 0x239570 <_ZN13CPhysicsWorld15CreateWeldJointEP14CPhysicsObjectS1_fffffb> */
/* @0x1500bc vmov s15, r0 */
/* @0x1500c0 vcvt.f64.s32 d7, s15 */
/* @0x1500c4 vmov r0, r1, d7 */
/* @0x1500c8 vmov r2, s14 */
/* @0x1500cc mov r3, r1 */
/* @0x1500d0 stm r5, {r2, r3} */
/* @0x1500d4 ldr r2, [sp, #0x12c] */
/* @0x1500d8 ldr r3, [r7] */
/* @0x1500dc cmp r2, r3 */
/* @0x1500e0 bne 0x1501bc <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x1500e4 add sp, sp, #308 */
/* @0x1500e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1500ec ldr r3, [pc, #0xd4] */
/* @0x1500f0 ldr r3, [r6, r3] */
/* @0x1500f4 ldr r3, [r3] */
/* @0x1500f8 ldr r3, [r3, #0xb4] */
/* @0x1500fc cmp r3, #0 */
/* @0x150100 beq 0x150118 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x150104 ldr r0, [pc, #0xc0] */
/* @0x150108 mov r1, #0 */
/* @0x15010c add r0, pc, r0 */
/* @0x150110 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x150114 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x150118 ldr r0, [pc, #0xb0] */
/* @0x15011c mov r1, #0 */
/* @0x150120 add r0, pc, r0 */
/* @0x150124 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x150128 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x15012c add r5, sp, #44 */
/* @0x150130 mov r1, r10 */
/* @0x150134 mov r2, #256 */
/* @0x150138 mov r0, r5 */
/* @0x15013c bl 0xb65b0 <memset@plt> */
/* @0x150140 mov r1, r10 */
/* @0x150144 mov r0, r4 */
/* @0x150148 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15014c ldr r2, [pc, #0x80] */
/* @0x150150 mov r1, #256 */
/* @0x150154 add r2, pc, r2 */
/* @0x150158 mov r3, r0 */
/* @0x15015c mov r0, r5 */
/* @0x150160 bl 0xb65c8 <snprintf@plt> */
/* @0x150164 mov r0, r5 */
/* @0x150168 mov r1, r10 */
/* @0x15016c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x150170 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x150174 add r5, sp, #44 */
/* @0x150178 mov r1, r9 */
/* @0x15017c mov r2, #256 */
/* @0x150180 mov r0, r5 */
/* @0x150184 bl 0xb65b0 <memset@plt> */
/* @0x150188 mov r0, r4 */
/* @0x15018c mov r1, #1 */
/* @0x150190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x150194 ldr r2, [pc, #0x3c] */
/* @0x150198 mov r1, #256 */
/* @0x15019c add r2, pc, r2 */
/* @0x1501a0 mov r3, r0 */
/* @0x1501a4 mov r0, r5 */
/* @0x1501a8 bl 0xb65c8 <snprintf@plt> */
/* @0x1501ac mov r0, r5 */
/* @0x1501b0 mov r1, r9 */
/* @0x1501b4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1501b8 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1501bc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1501c0 .word 0x002a1cd0 */
/* @0x1501c4 .word 0xffffbd00 */
/* @0x1501c8 .word 0xffffbcd8 */
/* @0x1501cc andseq r4, pc, r0, lsr lr */
/* @0x1501d0 andseq r3, pc, r4, lsl #26 */
/* @0x1501d4 andseq r4, pc, r12, asr #24 */
/* @0x1501d8 andseq r4, pc, r4, lsl #24 */

/* ── FUNC 0x1501dc · F_PhysicsCreateFrictionJoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=600 · insn=150 */
/* @0x1501dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1501e0 sub sp, sp, #292 */
/* @0x1501e4 ldr r6, [pc, #0x22c] */
/* @0x1501e8 mov r8, r2 */
/* @0x1501ec ldr r12, [pc, #0x228] */
/* @0x1501f0 mov r3, #0 */
/* @0x1501f4 add r6, pc, r6 */
/* @0x1501f8 ldr r4, [sp, #0x148] */
/* @0x1501fc mov r5, r0 */
/* @0x150200 mov r9, r1 */
/* @0x150204 ldr r7, [r6, r12] */
/* @0x150208 mov r0, r3 */
/* @0x15020c mov r1, r3 */
/* @0x150210 movt r0, #0xbff0 */
/* @0x150214 str r3, [r5, #0xc] */
/* @0x150218 ldr r2, [r7] */
/* @0x15021c str r0, [r5, #0x4] */
/* @0x150220 mov r0, r4 */
/* @0x150224 str r3, [r5] */
/* @0x150228 str r2, [sp, #0x11c] */
/* @0x15022c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x150230 mov r1, r9 */
/* @0x150234 mov r2, r8 */
/* @0x150238 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x15023c subs r10, r0, #0 */
/* @0x150240 beq 0x150384 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x150244 mov r1, #1 */
/* @0x150248 mov r0, r4 */
/* @0x15024c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x150250 mov r1, r9 */
/* @0x150254 mov r2, r8 */
/* @0x150258 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_> */
/* @0x15025c subs r9, r0, #0 */
/* @0x150260 beq 0x1503cc <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x150264 ldr r8, [r10, #0x84] */
/* @0x150268 cmp r8, #0 */
/* @0x15026c beq 0x150344 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x150270 ldr r9, [r9, #0x84] */
/* @0x150274 cmp r9, #0 */
/* @0x150278 beq 0x150344 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x15027c ldr r3, [pc, #0x19c] */
/* @0x150280 ldr r3, [r6, r3] */
/* @0x150284 ldr r3, [r3] */
/* @0x150288 ldr r6, [r3, #0xb4] */
/* @0x15028c cmp r6, #0 */
/* @0x150290 beq 0x150370 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x150294 mov r1, #2 */
/* @0x150298 mov r0, r4 */
/* @0x15029c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1502a0 mov r1, #3 */
/* @0x1502a4 mov r10, r0 */
/* @0x1502a8 mov r0, r4 */
/* @0x1502ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1502b0 mov r1, #4 */
/* @0x1502b4 mov r2, r0 */
/* @0x1502b8 mov r0, r4 */
/* @0x1502bc str r2, [sp, #0x10] */
/* @0x1502c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1502c4 mov r1, #5 */
/* @0x1502c8 mov r3, r0 */
/* @0x1502cc mov r0, r4 */
/* @0x1502d0 str r3, [sp, #0x14] */
/* @0x1502d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1502d8 mov r1, #6 */
/* @0x1502dc mov r11, r0 */
/* @0x1502e0 mov r0, r4 */
/* @0x1502e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1502e8 ldr r2, [sp, #0x10] */
/* @0x1502ec ldr r3, [sp, #0x14] */
/* @0x1502f0 mov r1, r8 */
/* @0x1502f4 str r11, [sp, #0x8] */
/* @0x1502f8 str r2, [sp] */
/* @0x1502fc mov r2, r9 */
/* @0x150300 str r3, [sp, #0x4] */
/* @0x150304 mov r3, r10 */
/* @0x150308 str r0, [sp, #0xc] */
/* @0x15030c mov r0, r6 */
/* @0x150310 bl 0x239674 <_ZN13CPhysicsWorld19CreateFrictionJointEP14CPhysicsObjectS1_ffffb> */
/* @0x150314 vmov s15, r0 */
/* @0x150318 vcvt.f64.s32 d7, s15 */
/* @0x15031c vmov r0, r1, d7 */
/* @0x150320 vmov r2, s14 */
/* @0x150324 mov r3, r1 */
/* @0x150328 stm r5, {r2, r3} */
/* @0x15032c ldr r2, [sp, #0x11c] */
/* @0x150330 ldr r3, [r7] */
/* @0x150334 cmp r2, r3 */
/* @0x150338 bne 0x150414 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x15033c add sp, sp, #292 */
/* @0x150340 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x150344 ldr r3, [pc, #0xd4] */
/* @0x150348 ldr r3, [r6, r3] */
/* @0x15034c ldr r3, [r3] */
/* @0x150350 ldr r3, [r3, #0xb4] */
/* @0x150354 cmp r3, #0 */
/* @0x150358 beq 0x150370 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x15035c ldr r0, [pc, #0xc0] */
/* @0x150360 mov r1, #0 */
/* @0x150364 add r0, pc, r0 */
/* @0x150368 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x15036c b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x150370 ldr r0, [pc, #0xb0] */
/* @0x150374 mov r1, #0 */
/* @0x150378 add r0, pc, r0 */
/* @0x15037c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x150380 b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x150384 add r5, sp, #28 */
/* @0x150388 mov r1, r10 */
/* @0x15038c mov r2, #256 */
/* @0x150390 mov r0, r5 */
/* @0x150394 bl 0xb65b0 <memset@plt> */
/* @0x150398 mov r1, r10 */
/* @0x15039c mov r0, r4 */
/* @0x1503a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1503a4 ldr r2, [pc, #0x80] */
/* @0x1503a8 mov r1, #256 */
/* @0x1503ac add r2, pc, r2 */
/* @0x1503b0 mov r3, r0 */
/* @0x1503b4 mov r0, r5 */
/* @0x1503b8 bl 0xb65c8 <snprintf@plt> */
/* @0x1503bc mov r0, r5 */
/* @0x1503c0 mov r1, r10 */
/* @0x1503c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1503c8 b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x1503cc add r5, sp, #28 */
/* @0x1503d0 mov r1, r9 */
/* @0x1503d4 mov r2, #256 */
/* @0x1503d8 mov r0, r5 */
/* @0x1503dc bl 0xb65b0 <memset@plt> */
/* @0x1503e0 mov r0, r4 */
/* @0x1503e4 mov r1, #1 */
/* @0x1503e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1503ec ldr r2, [pc, #0x3c] */
/* @0x1503f0 mov r1, #256 */
/* @0x1503f4 add r2, pc, r2 */
/* @0x1503f8 mov r3, r0 */
/* @0x1503fc mov r0, r5 */
/* @0x150400 bl 0xb65c8 <snprintf@plt> */
/* @0x150404 mov r0, r5 */
/* @0x150408 mov r1, r9 */
/* @0x15040c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x150410 b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x150414 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x150418 eoreq r1, r10, r12, asr r10 */
/* @0x15041c .word 0xffffbd00 */
/* @0x150420 .word 0xffffbcd8 */
/* @0x150424 ldrsbeq r4, [pc], -r8 */
/* @0x150428 andseq r3, pc, r12, lsr #21 */
/* @0x15042c ldrsheq r4, [pc], -r4 */
/* @0x150430 andseq r4, pc, r12, lsr #19 */

/* ── FUNC 0x150434 · InitPhysicsFunctions · size=3548 · insn=887 */
/* @0x150434 push {r4, lr} */
/* @0x150438 mov r2, #1 */
/* @0x15043c ldr r4, [pc, #0xab8] */
/* @0x150440 mov r3, r2 */
/* @0x150444 ldr r1, [pc, #0xab4] */
/* @0x150448 add r4, pc, r4 */
/* @0x15044c ldr r0, [pc, #0xab0] */
/* @0x150450 ldr r1, [r4, r1] */
/* @0x150454 add r0, pc, r0 */
/* @0x150458 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15045c ldr r1, [pc, #0xaa4] */
/* @0x150460 ldr r0, [pc, #0xaa4] */
/* @0x150464 mov r2, #2 */
/* @0x150468 mov r3, #1 */
/* @0x15046c ldr r1, [r4, r1] */
/* @0x150470 add r0, pc, r0 */
/* @0x150474 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150478 ldr r1, [pc, #0xa90] */
/* @0x15047c ldr r0, [pc, #0xa90] */
/* @0x150480 mov r2, #1 */
/* @0x150484 mov r3, r2 */
/* @0x150488 ldr r1, [r4, r1] */
/* @0x15048c add r0, pc, r0 */
/* @0x150490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150494 ldr r1, [pc, #0xa7c] */
/* @0x150498 ldr r0, [pc, #0xa7c] */
/* @0x15049c mov r2, #1 */
/* @0x1504a0 mov r3, r2 */
/* @0x1504a4 ldr r1, [r4, r1] */
/* @0x1504a8 add r0, pc, r0 */
/* @0x1504ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1504b0 ldr r1, [pc, #0xa68] */
/* @0x1504b4 ldr r0, [pc, #0xa68] */
/* @0x1504b8 mov r2, #1 */
/* @0x1504bc mov r3, r2 */
/* @0x1504c0 ldr r1, [r4, r1] */
/* @0x1504c4 add r0, pc, r0 */
/* @0x1504c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1504cc ldr r1, [pc, #0xa54] */
/* @0x1504d0 ldr r0, [pc, #0xa54] */
/* @0x1504d4 mov r2, #1 */
/* @0x1504d8 mov r3, r2 */
/* @0x1504dc ldr r1, [r4, r1] */
/* @0x1504e0 add r0, pc, r0 */
/* @0x1504e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1504e8 ldr r1, [pc, #0xa40] */
/* @0x1504ec ldr r0, [pc, #0xa40] */
/* @0x1504f0 mov r2, #0 */
/* @0x1504f4 mov r3, #1 */
/* @0x1504f8 ldr r1, [r4, r1] */
/* @0x1504fc add r0, pc, r0 */
/* @0x150500 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150504 ldr r1, [pc, #0xa2c] */
/* @0x150508 ldr r0, [pc, #0xa2c] */
/* @0x15050c mov r2, #1 */
/* @0x150510 mov r3, r2 */
/* @0x150514 ldr r1, [r4, r1] */
/* @0x150518 add r0, pc, r0 */
/* @0x15051c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150520 ldr r1, [pc, #0xa18] */
/* @0x150524 ldr r0, [pc, #0xa18] */
/* @0x150528 mov r2, #2 */
/* @0x15052c mov r3, #1 */
/* @0x150530 ldr r1, [r4, r1] */
/* @0x150534 add r0, pc, r0 */
/* @0x150538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15053c ldr r1, [pc, #0xa04] */
/* @0x150540 ldr r0, [pc, #0xa04] */
/* @0x150544 mov r2, #2 */
/* @0x150548 mov r3, #1 */
/* @0x15054c ldr r1, [r4, r1] */
/* @0x150550 add r0, pc, r0 */
/* @0x150554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150558 ldr r1, [pc, #0x9f0] */
/* @0x15055c ldr r0, [pc, #0x9f0] */
/* @0x150560 mov r2, #2 */
/* @0x150564 mov r3, #1 */
/* @0x150568 ldr r1, [r4, r1] */
/* @0x15056c add r0, pc, r0 */
/* @0x150570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150574 ldr r1, [pc, #0x9dc] */
/* @0x150578 ldr r0, [pc, #0x9dc] */
/* @0x15057c mov r2, #2 */
/* @0x150580 mov r3, #1 */
/* @0x150584 ldr r1, [r4, r1] */
/* @0x150588 add r0, pc, r0 */
/* @0x15058c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150590 ldr r1, [pc, #0x9c8] */
/* @0x150594 ldr r0, [pc, #0x9c8] */
/* @0x150598 mov r2, #2 */
/* @0x15059c mov r3, #1 */
/* @0x1505a0 ldr r1, [r4, r1] */
/* @0x1505a4 add r0, pc, r0 */
/* @0x1505a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1505ac ldr r1, [pc, #0x9b4] */
/* @0x1505b0 ldr r0, [pc, #0x9b4] */
/* @0x1505b4 mov r2, #2 */
/* @0x1505b8 mov r3, #1 */
/* @0x1505bc ldr r1, [r4, r1] */
/* @0x1505c0 add r0, pc, r0 */
/* @0x1505c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1505c8 ldr r1, [pc, #0x9a0] */
/* @0x1505cc ldr r0, [pc, #0x9a0] */
/* @0x1505d0 mov r2, #2 */
/* @0x1505d4 mov r3, #1 */
/* @0x1505d8 ldr r1, [r4, r1] */
/* @0x1505dc add r0, pc, r0 */
/* @0x1505e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1505e4 ldr r1, [pc, #0x98c] */
/* @0x1505e8 ldr r0, [pc, #0x98c] */
/* @0x1505ec mov r2, #2 */
/* @0x1505f0 mov r3, #1 */
/* @0x1505f4 ldr r1, [r4, r1] */
/* @0x1505f8 add r0, pc, r0 */
/* @0x1505fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150600 ldr r1, [pc, #0x978] */
/* @0x150604 ldr r0, [pc, #0x978] */
/* @0x150608 mov r2, #2 */
/* @0x15060c mov r3, #1 */
/* @0x150610 ldr r1, [r4, r1] */
/* @0x150614 add r0, pc, r0 */
/* @0x150618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15061c ldr r1, [pc, #0x964] */
/* @0x150620 ldr r0, [pc, #0x964] */
/* @0x150624 mov r2, #3 */
/* @0x150628 mov r3, #1 */
/* @0x15062c ldr r1, [r4, r1] */
/* @0x150630 add r0, pc, r0 */
/* @0x150634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150638 ldr r1, [pc, #0x950] */
/* @0x15063c ldr r0, [pc, #0x950] */
/* @0x150640 mov r2, #5 */
/* @0x150644 mov r3, #1 */
/* @0x150648 ldr r1, [r4, r1] */
/* @0x15064c add r0, pc, r0 */
/* @0x150650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150654 ldr r1, [pc, #0x93c] */
/* @0x150658 ldr r0, [pc, #0x93c] */
/* @0x15065c mov r2, #1 */
/* @0x150660 mov r3, r2 */
/* @0x150664 ldr r1, [r4, r1] */
/* @0x150668 add r0, pc, r0 */
/* @0x15066c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150670 ldr r1, [pc, #0x928] */
/* @0x150674 ldr r0, [pc, #0x928] */
/* @0x150678 mov r2, #2 */
/* @0x15067c mov r3, #1 */
/* @0x150680 ldr r1, [r4, r1] */
/* @0x150684 add r0, pc, r0 */
/* @0x150688 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15068c ldr r1, [pc, #0x914] */
/* @0x150690 ldr r0, [pc, #0x914] */
/* @0x150694 mov r2, #3 */
/* @0x150698 mov r3, #1 */
/* @0x15069c ldr r1, [r4, r1] */
/* @0x1506a0 add r0, pc, r0 */
/* @0x1506a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1506a8 ldr r1, [pc, #0x900] */
/* @0x1506ac ldr r0, [pc, #0x900] */
/* @0x1506b0 mov r2, #2 */
/* @0x1506b4 mov r3, #1 */
/* @0x1506b8 ldr r1, [r4, r1] */
/* @0x1506bc add r0, pc, r0 */
/* @0x1506c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1506c4 ldr r1, [pc, #0x8ec] */
/* @0x1506c8 ldr r0, [pc, #0x8ec] */
/* @0x1506cc mov r2, #4 */
/* @0x1506d0 mov r3, #1 */
/* @0x1506d4 ldr r1, [r4, r1] */
/* @0x1506d8 add r0, pc, r0 */
/* @0x1506dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1506e0 ldr r1, [pc, #0x8d8] */
/* @0x1506e4 ldr r0, [pc, #0x8d8] */
/* @0x1506e8 mov r2, #1 */
/* @0x1506ec mov r3, r2 */
/* @0x1506f0 ldr r1, [r4, r1] */
/* @0x1506f4 add r0, pc, r0 */
/* @0x1506f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1506fc ldr r1, [pc, #0x8c4] */
/* @0x150700 ldr r0, [pc, #0x8c4] */
/* @0x150704 mov r2, #4 */
/* @0x150708 mov r3, #1 */
/* @0x15070c ldr r1, [r4, r1] */
/* @0x150710 add r0, pc, r0 */
/* @0x150714 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150718 ldr r1, [pc, #0x8b0] */
/* @0x15071c ldr r0, [pc, #0x8b0] */
/* @0x150720 mov r2, #4 */
/* @0x150724 mov r3, #1 */
/* @0x150728 ldr r1, [r4, r1] */
/* @0x15072c add r0, pc, r0 */
/* @0x150730 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150734 ldr r1, [pc, #0x89c] */
/* @0x150738 ldr r0, [pc, #0x89c] */
/* @0x15073c mov r2, #1 */
/* @0x150740 mov r3, r2 */
/* @0x150744 ldr r1, [r4, r1] */
/* @0x150748 add r0, pc, r0 */
/* @0x15074c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150750 ldr r1, [pc, #0x888] */
/* @0x150754 ldr r0, [pc, #0x888] */
/* @0x150758 mov r2, #4 */
/* @0x15075c mov r3, #1 */
/* @0x150760 ldr r1, [r4, r1] */
/* @0x150764 add r0, pc, r0 */
/* @0x150768 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15076c ldr r1, [pc, #0x874] */
/* @0x150770 ldr r0, [pc, #0x874] */
/* @0x150774 mov r2, #4 */
/* @0x150778 mov r3, #1 */
/* @0x15077c ldr r1, [r4, r1] */
/* @0x150780 add r0, pc, r0 */
/* @0x150784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150788 ldr r1, [pc, #0x860] */
/* @0x15078c ldr r0, [pc, #0x860] */
/* @0x150790 mov r2, #1 */
/* @0x150794 mov r3, r2 */
/* @0x150798 ldr r1, [r4, r1] */
/* @0x15079c add r0, pc, r0 */
/* @0x1507a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1507a4 ldr r1, [pc, #0x84c] */
/* @0x1507a8 ldr r0, [pc, #0x84c] */
/* @0x1507ac mov r2, #4 */
/* @0x1507b0 mov r3, #1 */
/* @0x1507b4 ldr r1, [r4, r1] */
/* @0x1507b8 add r0, pc, r0 */
/* @0x1507bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1507c0 ldr r1, [pc, #0x838] */
/* @0x1507c4 ldr r0, [pc, #0x838] */
/* @0x1507c8 mov r2, #0 */
/* @0x1507cc mov r3, #1 */
/* @0x1507d0 ldr r1, [r4, r1] */
/* @0x1507d4 add r0, pc, r0 */
/* @0x1507d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1507dc ldr r1, [pc, #0x824] */
/* @0x1507e0 ldr r0, [pc, #0x824] */
/* @0x1507e4 mov r2, #4 */
/* @0x1507e8 mov r3, #1 */
/* @0x1507ec ldr r1, [r4, r1] */
/* @0x1507f0 add r0, pc, r0 */
/* @0x1507f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1507f8 ldr r1, [pc, #0x810] */
/* @0x1507fc ldr r0, [pc, #0x810] */
/* @0x150800 mov r2, #2 */
/* @0x150804 mov r3, #1 */
/* @0x150808 ldr r1, [r4, r1] */
/* @0x15080c add r0, pc, r0 */
/* @0x150810 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150814 ldr r1, [pc, #0x7fc] */
/* @0x150818 ldr r0, [pc, #0x7fc] */
/* @0x15081c mov r2, #1 */
/* @0x150820 mov r3, r2 */
/* @0x150824 ldr r1, [r4, r1] */
/* @0x150828 add r0, pc, r0 */
/* @0x15082c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150830 ldr r1, [pc, #0x7e8] */
/* @0x150834 ldr r0, [pc, #0x7e8] */
/* @0x150838 mov r2, #1 */
/* @0x15083c mov r3, r2 */
/* @0x150840 ldr r1, [r4, r1] */
/* @0x150844 add r0, pc, r0 */
/* @0x150848 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15084c ldr r1, [pc, #0x7d4] */
/* @0x150850 ldr r0, [pc, #0x7d4] */
/* @0x150854 mov r2, #1 */
/* @0x150858 mov r3, r2 */
/* @0x15085c ldr r1, [r4, r1] */
/* @0x150860 add r0, pc, r0 */
/* @0x150864 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150868 ldr r1, [pc, #0x7c0] */
/* @0x15086c ldr r0, [pc, #0x7c0] */
/* @0x150870 mov r2, #2 */
/* @0x150874 mov r3, #1 */
/* @0x150878 ldr r1, [r4, r1] */
/* @0x15087c add r0, pc, r0 */
/* @0x150880 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150884 ldr r1, [pc, #0x7ac] */
/* @0x150888 ldr r0, [pc, #0x7ac] */
/* @0x15088c mov r2, #2 */
/* @0x150890 mov r3, #1 */
/* @0x150894 ldr r1, [r4, r1] */
/* @0x150898 add r0, pc, r0 */
/* @0x15089c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1508a0 ldr r1, [pc, #0x798] */
/* @0x1508a4 ldr r0, [pc, #0x798] */
/* @0x1508a8 mov r2, #2 */
/* @0x1508ac mov r3, #1 */
/* @0x1508b0 ldr r1, [r4, r1] */
/* @0x1508b4 add r0, pc, r0 */
/* @0x1508b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1508bc ldr r1, [pc, #0x784] */
/* @0x1508c0 ldr r0, [pc, #0x784] */
/* @0x1508c4 mov r2, #7 */
/* @0x1508c8 mov r3, #1 */
/* @0x1508cc ldr r1, [r4, r1] */
/* @0x1508d0 add r0, pc, r0 */
/* @0x1508d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1508d8 ldr r1, [pc, #0x770] */
/* @0x1508dc ldr r0, [pc, #0x770] */
/* @0x1508e0 mov r2, #8 */
/* @0x1508e4 mov r3, #1 */
/* @0x1508e8 ldr r1, [r4, r1] */
/* @0x1508ec add r0, pc, r0 */
/* @0x1508f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1508f4 ldr r1, [pc, #0x75c] */
/* @0x1508f8 ldr r0, [pc, #0x75c] */
/* @0x1508fc mov r2, #11 */
/* @0x150900 mov r3, #1 */
/* @0x150904 ldr r1, [r4, r1] */
/* @0x150908 add r0, pc, r0 */
/* @0x15090c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150910 ldr r1, [pc, #0x748] */
/* @0x150914 ldr r0, [pc, #0x748] */
/* @0x150918 mov r2, #13 */
/* @0x15091c mov r3, #1 */
/* @0x150920 ldr r1, [r4, r1] */
/* @0x150924 add r0, pc, r0 */
/* @0x150928 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15092c ldr r1, [pc, #0x734] */
/* @0x150930 ldr r0, [pc, #0x734] */
/* @0x150934 mov r2, #12 */
/* @0x150938 mov r3, #1 */
/* @0x15093c ldr r1, [r4, r1] */
/* @0x150940 add r0, pc, r0 */
/* @0x150944 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150948 ldr r1, [pc, #0x720] */
/* @0x15094c ldr r0, [pc, #0x720] */
/* @0x150950 mov r2, #12 */
/* @0x150954 mov r3, #1 */
/* @0x150958 ldr r1, [r4, r1] */
/* @0x15095c add r0, pc, r0 */
/* @0x150960 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150964 ldr r1, [pc, #0x70c] */
/* @0x150968 ldr r0, [pc, #0x70c] */
/* @0x15096c mov r2, #5 */
/* @0x150970 mov r3, #1 */
/* @0x150974 ldr r1, [r4, r1] */
/* @0x150978 add r0, pc, r0 */
/* @0x15097c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150980 ldr r1, [pc, #0x6f8] */
/* @0x150984 ldr r0, [pc, #0x6f8] */
/* @0x150988 mov r2, #8 */
/* @0x15098c mov r3, #1 */
/* @0x150990 ldr r1, [r4, r1] */
/* @0x150994 add r0, pc, r0 */
/* @0x150998 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15099c ldr r1, [pc, #0x6e4] */
/* @0x1509a0 ldr r0, [pc, #0x6e4] */
/* @0x1509a4 mov r2, #7 */
/* @0x1509a8 mov r3, #0 */
/* @0x1509ac ldr r1, [r4, r1] */
/* @0x1509b0 add r0, pc, r0 */
/* @0x1509b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1509b8 ldr r1, [pc, #0x6d0] */
/* @0x1509bc ldr r0, [pc, #0x6d0] */
/* @0x1509c0 mov r2, #2 */
/* @0x1509c4 mov r3, #1 */
/* @0x1509c8 ldr r1, [r4, r1] */
/* @0x1509cc add r0, pc, r0 */
/* @0x1509d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1509d4 ldr r1, [pc, #0x6bc] */
/* @0x1509d8 ldr r0, [pc, #0x6bc] */
/* @0x1509dc mov r2, #2 */
/* @0x1509e0 mov r3, #1 */
/* @0x1509e4 ldr r1, [r4, r1] */
/* @0x1509e8 add r0, pc, r0 */
/* @0x1509ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1509f0 ldr r1, [pc, #0x6a8] */
/* @0x1509f4 ldr r0, [pc, #0x6a8] */
/* @0x1509f8 mov r2, #3 */
/* @0x1509fc mov r3, #1 */
/* @0x150a00 ldr r1, [r4, r1] */
/* @0x150a04 add r0, pc, r0 */
/* @0x150a08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150a0c ldr r1, [pc, #0x694] */
/* @0x150a10 ldr r0, [pc, #0x694] */
/* @0x150a14 mov r2, #1 */
/* @0x150a18 mov r3, r2 */
/* @0x150a1c ldr r1, [r4, r1] */
/* @0x150a20 add r0, pc, r0 */
/* @0x150a24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150a28 ldr r1, [pc, #0x680] */
/* @0x150a2c ldr r0, [pc, #0x680] */
/* @0x150a30 mov r2, #8 */
/* @0x150a34 mov r3, #1 */
/* @0x150a38 ldr r1, [r4, r1] */
/* @0x150a3c add r0, pc, r0 */
/* @0x150a40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150a44 ldr r1, [pc, #0x66c] */
/* @0x150a48 ldr r0, [pc, #0x66c] */
/* @0x150a4c mov r2, #1 */
/* @0x150a50 mov r3, r2 */
/* @0x150a54 ldr r1, [r4, r1] */
/* @0x150a58 add r0, pc, r0 */
/* @0x150a5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150a60 ldr r1, [pc, #0x658] */
/* @0x150a64 ldr r0, [pc, #0x658] */
/* @0x150a68 mov r2, #3 */
/* @0x150a6c mov r3, #0 */
/* @0x150a70 ldr r1, [r4, r1] */
/* @0x150a74 add r0, pc, r0 */
/* @0x150a78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150a7c ldr r1, [pc, #0x644] */
/* @0x150a80 ldr r0, [pc, #0x644] */
/* @0x150a84 mov r2, #4 */
/* @0x150a88 mov r3, #0 */
/* @0x150a8c ldr r1, [r4, r1] */
/* @0x150a90 add r0, pc, r0 */
/* @0x150a94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150a98 ldr r1, [pc, #0x630] */
/* @0x150a9c ldr r0, [pc, #0x630] */
/* @0x150aa0 mov r2, #1 */
/* @0x150aa4 mov r3, #0 */
/* @0x150aa8 ldr r1, [r4, r1] */
/* @0x150aac add r0, pc, r0 */
/* @0x150ab0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150ab4 ldr r1, [pc, #0x61c] */
/* @0x150ab8 ldr r0, [pc, #0x61c] */
/* @0x150abc mov r2, #2 */
/* @0x150ac0 mov r3, #0 */
/* @0x150ac4 ldr r1, [r4, r1] */
/* @0x150ac8 add r0, pc, r0 */
/* @0x150acc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150ad0 ldr r1, [pc, #0x608] */
/* @0x150ad4 ldr r0, [pc, #0x608] */
/* @0x150ad8 mov r2, #2 */
/* @0x150adc mov r3, #0 */
/* @0x150ae0 ldr r1, [r4, r1] */
/* @0x150ae4 add r0, pc, r0 */
/* @0x150ae8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150aec ldr r1, [pc, #0x5f4] */
/* @0x150af0 ldr r0, [pc, #0x5f4] */
/* @0x150af4 mov r2, #4 */
/* @0x150af8 mov r3, #1 */
/* @0x150afc ldr r1, [r4, r1] */
/* @0x150b00 add r0, pc, r0 */
/* @0x150b04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150b08 ldr r1, [pc, #0x5e0] */
/* @0x150b0c ldr r0, [pc, #0x5e0] */
/* @0x150b10 mov r2, #9 */
/* @0x150b14 mov r3, #1 */
/* @0x150b18 ldr r1, [r4, r1] */
/* @0x150b1c add r0, pc, r0 */
/* @0x150b20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150b24 ldr r1, [pc, #0x5cc] */
/* @0x150b28 ldr r0, [pc, #0x5cc] */
/* @0x150b2c mov r2, #0 */
/* @0x150b30 mov r3, #1 */
/* @0x150b34 ldr r1, [r4, r1] */
/* @0x150b38 add r0, pc, r0 */
/* @0x150b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150b40 ldr r1, [pc, #0x5b8] */
/* @0x150b44 ldr r0, [pc, #0x5b8] */
/* @0x150b48 mov r2, #2 */
/* @0x150b4c mov r3, #1 */
/* @0x150b50 ldr r1, [r4, r1] */
/* @0x150b54 add r0, pc, r0 */
/* @0x150b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150b5c ldr r1, [pc, #0x5a4] */
/* @0x150b60 ldr r0, [pc, #0x5a4] */
/* @0x150b64 mov r2, #2 */
/* @0x150b68 mov r3, #1 */
/* @0x150b6c ldr r1, [r4, r1] */
/* @0x150b70 add r0, pc, r0 */
/* @0x150b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150b78 ldr r1, [pc, #0x590] */
/* @0x150b7c ldr r0, [pc, #0x590] */
/* @0x150b80 mov r2, #12 */
/* @0x150b84 mov r3, #1 */
/* @0x150b88 ldr r1, [r4, r1] */
/* @0x150b8c add r0, pc, r0 */
/* @0x150b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150b94 ldr r1, [pc, #0x57c] */
/* @0x150b98 ldr r0, [pc, #0x57c] */
/* @0x150b9c mov r2, #2 */
/* @0x150ba0 mov r3, #1 */
/* @0x150ba4 ldr r1, [r4, r1] */
/* @0x150ba8 add r0, pc, r0 */
/* @0x150bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150bb0 ldr r1, [pc, #0x568] */
/* @0x150bb4 ldr r0, [pc, #0x568] */
/* @0x150bb8 mov r2, #3 */
/* @0x150bbc mov r3, #1 */
/* @0x150bc0 ldr r1, [r4, r1] */
/* @0x150bc4 add r0, pc, r0 */
/* @0x150bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150bcc ldr r1, [pc, #0x554] */
/* @0x150bd0 ldr r0, [pc, #0x554] */
/* @0x150bd4 mov r2, #1 */
/* @0x150bd8 mov r3, r2 */
/* @0x150bdc ldr r1, [r4, r1] */
/* @0x150be0 add r0, pc, r0 */
/* @0x150be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150be8 ldr r1, [pc, #0x540] */
/* @0x150bec ldr r0, [pc, #0x540] */
/* @0x150bf0 mov r2, #3 */
/* @0x150bf4 mov r3, #1 */
/* @0x150bf8 ldr r1, [r4, r1] */
/* @0x150bfc add r0, pc, r0 */
/* @0x150c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150c04 ldr r1, [pc, #0x52c] */
/* @0x150c08 ldr r0, [pc, #0x52c] */
/* @0x150c0c mov r2, #0 */
/* @0x150c10 mov r3, #1 */
/* @0x150c14 ldr r1, [r4, r1] */
/* @0x150c18 add r0, pc, r0 */
/* @0x150c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150c20 ldr r1, [pc, #0x518] */
/* @0x150c24 ldr r0, [pc, #0x518] */
/* @0x150c28 mov r2, #2 */
/* @0x150c2c mov r3, #1 */
/* @0x150c30 ldr r1, [r4, r1] */
/* @0x150c34 add r0, pc, r0 */
/* @0x150c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150c3c ldr r1, [pc, #0x504] */
/* @0x150c40 ldr r0, [pc, #0x504] */
/* @0x150c44 mov r2, #1 */
/* @0x150c48 mov r3, r2 */
/* @0x150c4c ldr r1, [r4, r1] */
/* @0x150c50 add r0, pc, r0 */
/* @0x150c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150c58 ldr r1, [pc, #0x4f0] */
/* @0x150c5c ldr r0, [pc, #0x4f0] */
/* @0x150c60 mov r2, #1 */
/* @0x150c64 mov r3, r2 */
/* @0x150c68 ldr r1, [r4, r1] */
/* @0x150c6c add r0, pc, r0 */
/* @0x150c70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150c74 ldr r1, [pc, #0x4dc] */
/* @0x150c78 ldr r0, [pc, #0x4dc] */
/* @0x150c7c mov r2, #3 */
/* @0x150c80 mov r3, #1 */
/* @0x150c84 ldr r1, [r4, r1] */
/* @0x150c88 add r0, pc, r0 */
/* @0x150c8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150c90 ldr r1, [pc, #0x4c8] */
/* @0x150c94 ldr r0, [pc, #0x4c8] */
/* @0x150c98 mov r2, #1 */
/* @0x150c9c mov r3, #0 */
/* @0x150ca0 ldr r1, [r4, r1] */
/* @0x150ca4 add r0, pc, r0 */
/* @0x150ca8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150cac ldr r1, [pc, #0x4b4] */
/* @0x150cb0 ldr r0, [pc, #0x4b4] */
/* @0x150cb4 mov r2, #1 */
/* @0x150cb8 mov r3, #0 */
/* @0x150cbc ldr r1, [r4, r1] */
/* @0x150cc0 add r0, pc, r0 */
/* @0x150cc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150cc8 ldr r1, [pc, #0x4a0] */
/* @0x150ccc ldr r0, [pc, #0x4a0] */
/* @0x150cd0 mov r2, #1 */
/* @0x150cd4 mov r3, #0 */
/* @0x150cd8 ldr r1, [r4, r1] */
/* @0x150cdc add r0, pc, r0 */
/* @0x150ce0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150ce4 ldr r1, [pc, #0x48c] */
/* @0x150ce8 ldr r0, [pc, #0x48c] */
/* @0x150cec mov r2, #1 */
/* @0x150cf0 mov r3, #0 */
/* @0x150cf4 ldr r1, [r4, r1] */
/* @0x150cf8 add r0, pc, r0 */
/* @0x150cfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150d00 ldr r1, [pc, #0x478] */
/* @0x150d04 ldr r0, [pc, #0x478] */
/* @0x150d08 mov r2, #1 */
/* @0x150d0c mov r3, #0 */
/* @0x150d10 ldr r1, [r4, r1] */
/* @0x150d14 add r0, pc, r0 */
/* @0x150d18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150d1c ldr r1, [pc, #0x464] */
/* @0x150d20 ldr r0, [pc, #0x464] */
/* @0x150d24 mov r2, #1 */
/* @0x150d28 mov r3, #0 */
/* @0x150d2c ldr r1, [r4, r1] */
/* @0x150d30 add r0, pc, r0 */
/* @0x150d34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150d38 ldr r1, [pc, #0x450] */
/* @0x150d3c ldr r0, [pc, #0x450] */
/* @0x150d40 mov r2, #1 */
/* @0x150d44 mov r3, #0 */
/* @0x150d48 ldr r1, [r4, r1] */
/* @0x150d4c add r0, pc, r0 */
/* @0x150d50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150d54 ldr r1, [pc, #0x43c] */
/* @0x150d58 ldr r0, [pc, #0x43c] */
/* @0x150d5c mov r2, #1 */
/* @0x150d60 mov r3, #0 */
/* @0x150d64 ldr r1, [r4, r1] */
/* @0x150d68 add r0, pc, r0 */
/* @0x150d6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150d70 ldr r1, [pc, #0x428] */
/* @0x150d74 ldr r0, [pc, #0x428] */
/* @0x150d78 mov r2, #1 */
/* @0x150d7c mov r3, #0 */
/* @0x150d80 ldr r1, [r4, r1] */
/* @0x150d84 add r0, pc, r0 */
/* @0x150d88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150d8c ldr r1, [pc, #0x414] */
/* @0x150d90 ldr r0, [pc, #0x414] */
/* @0x150d94 mov r2, #1 */
/* @0x150d98 mov r3, #0 */
/* @0x150d9c ldr r1, [r4, r1] */
/* @0x150da0 add r0, pc, r0 */
/* @0x150da4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150da8 ldr r1, [pc, #0x400] */
/* @0x150dac ldr r0, [pc, #0x400] */
/* @0x150db0 mov r2, #2 */
/* @0x150db4 mov r3, #0 */
/* @0x150db8 ldr r1, [r4, r1] */
/* @0x150dbc add r0, pc, r0 */
/* @0x150dc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150dc4 ldr r1, [pc, #0x3ec] */
/* @0x150dc8 ldr r0, [pc, #0x3ec] */
/* @0x150dcc mov r2, #1 */
/* @0x150dd0 mov r3, #0 */
/* @0x150dd4 ldr r1, [r4, r1] */
/* @0x150dd8 add r0, pc, r0 */
/* @0x150ddc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150de0 ldr r1, [pc, #0x3d8] */
/* @0x150de4 ldr r0, [pc, #0x3d8] */
/* @0x150de8 mov r2, #0 */
/* @0x150dec mov r3, r2 */
/* @0x150df0 ldr r1, [r4, r1] */
/* @0x150df4 add r0, pc, r0 */
/* @0x150df8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150dfc ldr r1, [pc, #0x3c4] */
/* @0x150e00 ldr r0, [pc, #0x3c4] */
/* @0x150e04 mov r2, #0 */
/* @0x150e08 mov r3, r2 */
/* @0x150e0c ldr r1, [r4, r1] */
/* @0x150e10 add r0, pc, r0 */
/* @0x150e14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150e18 ldr r1, [pc, #0x3b0] */
/* @0x150e1c ldr r0, [pc, #0x3b0] */
/* @0x150e20 mov r2, #0 */
/* @0x150e24 mov r3, r2 */
/* @0x150e28 ldr r1, [r4, r1] */
/* @0x150e2c add r0, pc, r0 */
/* @0x150e30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150e34 ldr r1, [pc, #0x39c] */
/* @0x150e38 ldr r0, [pc, #0x39c] */
/* @0x150e3c mov r2, #0 */
/* @0x150e40 mov r3, r2 */
/* @0x150e44 ldr r1, [r4, r1] */
/* @0x150e48 add r0, pc, r0 */
/* @0x150e4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150e50 ldr r1, [pc, #0x388] */
/* @0x150e54 ldr r0, [pc, #0x388] */
/* @0x150e58 mov r2, #0 */
/* @0x150e5c mov r3, r2 */
/* @0x150e60 ldr r1, [r4, r1] */
/* @0x150e64 add r0, pc, r0 */
/* @0x150e68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150e6c ldr r1, [pc, #0x374] */
/* @0x150e70 ldr r0, [pc, #0x374] */
/* @0x150e74 mov r2, #1 */
/* @0x150e78 mov r3, #0 */
/* @0x150e7c ldr r1, [r4, r1] */
/* @0x150e80 add r0, pc, r0 */
/* @0x150e84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150e88 ldr r1, [pc, #0x360] */
/* @0x150e8c ldr r0, [pc, #0x360] */
/* @0x150e90 mov r2, #1 */
/* @0x150e94 mov r3, #0 */
/* @0x150e98 ldr r1, [r4, r1] */
/* @0x150e9c add r0, pc, r0 */
/* @0x150ea0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150ea4 ldr r1, [pc, #0x34c] */
/* @0x150ea8 ldr r0, [pc, #0x34c] */
/* @0x150eac mov r2, #1 */
/* @0x150eb0 mov r3, #0 */
/* @0x150eb4 ldr r1, [r4, r1] */
/* @0x150eb8 add r0, pc, r0 */
/* @0x150ebc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150ec0 ldr r1, [pc, #0x338] */
/* @0x150ec4 ldr r0, [pc, #0x338] */
/* @0x150ec8 mov r2, #1 */
/* @0x150ecc mov r3, #0 */
/* @0x150ed0 ldr r1, [r4, r1] */
/* @0x150ed4 add r0, pc, r0 */
/* @0x150ed8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150edc ldr r1, [pc, #0x324] */
/* @0x150ee0 ldr r0, [pc, #0x324] */
/* @0x150ee4 mov r2, #1 */
/* @0x150ee8 mov r3, #0 */
/* @0x150eec ldr r1, [r4, r1] */
/* @0x150ef0 add r0, pc, r0 */
/* @0x150ef4 pop {r4, lr} */
/* @0x150ef8 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x150efc eoreq r1, r10, r8, lsl #16 */
/* @0x150f00 .word 0xffffdc88 */
/* @0x150f04 andseq r4, pc, r0, lsr #23 */
/* @0x150f08 .word 0xffffdc8c */
/* @0x150f0c mulseq pc, r12, r11 */
/* @0x150f10 .word 0xffffdc90 */
/* @0x150f14 mulseq pc, r8, r11 */
/* @0x150f18 .word 0xffffdc94 */
/* @0x150f1c mulseq pc, r8, r11 */
/* @0x150f20 .word 0xffffdc98 */
/* @0x150f24 mulseq pc, r12, r11 */
/* @0x150f28 .word 0xffffdc9c */
/* @0x150f2c mulseq pc, r12, r11 */
/* @0x150f30 .word 0xffffdca0 */
/* @0x150f34 mulseq pc, r8, r11 */
/* @0x150f38 .word 0xffffdca4 */
/* @0x150f3c mulseq pc, r4, r11 */
/* @0x150f40 .word 0xffffdca8 */
/* @0x150f44 mulseq pc, r8, r11 */
/* @0x150f48 .word 0xffffdcac */
/* @0x150f4c mulseq pc, r8, r11 */
/* @0x150f50 .word 0xffffdcb0 */
/* @0x150f54 mulseq pc, r8, r11 */
/* @0x150f58 .word 0xffffdcb4 */
/* @0x150f5c mulseq pc, r12, r11 */
/* @0x150f60 .word 0xffffdcb8 */
/* @0x150f64 andseq r4, pc, r0, lsr #23 */
/* @0x150f68 .word 0xffffdcbc */
/* @0x150f6c andseq r4, pc, r8, lsr #23 */
/* @0x150f70 .word 0xffffdcc0 */
/* @0x150f74 andseq r4, pc, r8, lsr #23 */
/* @0x150f78 .word 0xffffdcc4 */
/* @0x150f7c ldrheq r4, [pc], -r0 */
/* @0x150f80 .word 0xffffdcc8 */
/* @0x150f84 ldrheq r4, [pc], -r8 */
/* @0x150f88 .word 0xffffdccc */
/* @0x150f8c andseq r4, pc, r0, asr #23 */
/* @0x150f90 .word 0xffffdcd0 */
/* @0x150f94 andseq r4, pc, r4, asr #23 */
/* @0x150f98 .word 0xffffdcd4 */
/* @0x150f9c andseq r4, pc, r8, asr #23 */
/* @0x150fa0 .word 0xffffdcd8 */
/* @0x150fa4 ldrsbeq r4, [pc], -r0 */
/* @0x150fa8 .word 0xffffdcdc */
/* @0x150fac ldrsbeq r4, [pc], -r4 */
/* @0x150fb0 .word 0xffffdce0 */
/* @0x150fb4 ldrsbeq r4, [pc], -r4 */
/* @0x150fb8 .word 0xffffdce4 */
/* @0x150fbc ldrsbeq r4, [pc], -r0 */
/* @0x150fc0 .word 0xffffdce8 */
/* @0x150fc4 ldrsbeq r4, [pc], -r0 */
/* @0x150fc8 .word 0xffffdcec */
/* @0x150fcc andseq r4, pc, r12, asr #23 */
/* @0x150fd0 .word 0xffffdcf0 */
/* @0x150fd4 andseq r4, pc, r4, asr #23 */
/* @0x150fd8 .word 0xffffdcf4 */
/* @0x150fdc andseq r4, pc, r0, asr #23 */
/* @0x150fe0 .word 0xffffdcf8 */
/* @0x150fe4 andseq r4, pc, r4, asr #23 */
/* @0x150fe8 .word 0xffffdcfc */
/* @0x150fec andseq r4, pc, r4, asr #23 */
/* @0x150ff0 .word 0xffffdd00 */
/* @0x150ff4 andseq r4, pc, r4, asr #23 */
/* @0x150ff8 .word 0xffffdd04 */
/* @0x150ffc andseq r4, pc, r0, asr #23 */
/* @0x151000 .word 0xffffdd08 */
/* @0x151004 ldrheq r4, [pc], -r12 */
/* @0x151008 .word 0xffffdd0c */
/* @0x15100c ldrheq r4, [pc], -r4 */
/* @0x151010 .word 0xffffdd10 */
/* @0x151014 ldrheq r4, [pc], -r0 */
/* @0x151018 .word 0xffffdd14 */
/* @0x15101c andseq r4, pc, r12, lsr #23 */
/* @0x151020 .word 0xffffdd18 */
/* @0x151024 andseq r4, pc, r8, lsr #23 */
/* @0x151028 .word 0xffffdd1c */
/* @0x15102c andseq r4, pc, r0, lsr #23 */
/* @0x151030 .word 0xffffdd20 */
/* @0x151034 mulseq pc, r12, r11 */
/* @0x151038 .word 0xffffdd24 */
/* @0x15103c mulseq pc, r8, r11 */
/* @0x151040 .word 0xffffdd28 */
/* @0x151044 mulseq pc, r0, r11 */
/* @0x151048 .word 0xffffdd2c */
/* @0x15104c andseq r4, pc, r12, lsl #23 */
/* @0x151050 .word 0xffffdd30 */
/* @0x151054 mulseq pc, r0, r11 */
/* @0x151058 .word 0xffffdd34 */
/* @0x15105c mulseq pc, r0, r11 */
/* @0x151060 .word 0xffffdd38 */
/* @0x151064 mulseq pc, r4, r11 */
/* @0x151068 .word 0xffffdd3c */
/* @0x15106c mulseq pc, r8, r11 */
/* @0x151070 .word 0xffffdd40 */
/* @0x151074 mulseq pc, r8, r11 */
/* @0x151078 .word 0xffffdd44 */
/* @0x15107c mulseq pc, r8, r11 */
/* @0x151080 .word 0xffffdd48 */
/* @0x151084 mulseq pc, r8, r11 */
/* @0x151088 .word 0xffffdd4c */
/* @0x15108c mulseq pc, r8, r11 */
/* @0x151090 .word 0xffffdd50 */
/* @0x151094 mulseq pc, r12, r11 */
/* @0x151098 .word 0xffffdd54 */
/* @0x15109c mulseq pc, r12, r11 */
/* @0x1510a0 .word 0xffffdd58 */
/* @0x1510a4 mulseq pc, r8, r11 */
/* @0x1510a8 .word 0xffffdd5c */
/* @0x1510ac mulseq pc, r4, r11 */
/* @0x1510b0 .word 0xffffdd60 */
/* @0x1510b4 mulseq pc, r0, r11 */
/* @0x1510b8 .word 0xffffdd64 */
/* @0x1510bc andseq r4, pc, r12, lsl #23 */
/* @0x1510c0 .word 0xffffdd68 */
/* @0x1510c4 andseq r4, pc, r8, lsl #23 */
/* @0x1510c8 .word 0xffffdd6c */
/* @0x1510cc mulseq pc, r4, r11 */
/* @0x1510d0 .word 0xffffdd70 */
/* @0x1510d4 mulseq pc, r12, r11 */
/* @0x1510d8 .word 0xffffdd74 */
/* @0x1510dc andseq r4, pc, r4, lsr #23 */
/* @0x1510e0 .word 0xffffdd78 */
/* @0x1510e4 andseq r4, pc, r4, lsr #23 */
/* @0x1510e8 .word 0xffffdd7c */
/* @0x1510ec andseq r4, pc, r12, lsr #23 */
/* @0x1510f0 .word 0xffffdd80 */
/* @0x1510f4 andseq r4, pc, r8, lsr #23 */
/* @0x1510f8 .word 0xffffdd84 */
/* @0x1510fc andseq r4, pc, r8, lsr #23 */
/* @0x151100 .word 0xffffdd88 */
/* @0x151104 andseq r4, pc, r4, lsr #23 */
/* @0x151108 .word 0xffffdd8c */
/* @0x15110c andseq r4, pc, r4, lsr #23 */
/* @0x151110 .word 0xffffdd90 */
/* @0x151114 andseq r4, pc, r12, lsr #23 */
/* @0x151118 .word 0xffffdd94 */
/* @0x15111c ldrheq r4, [pc], -r0 */
/* @0x151120 .word 0xffffdd98 */
/* @0x151124 ldrheq r4, [pc], -r4 */
/* @0x151128 .word 0xffffdd9c */
/* @0x15112c ldrheq r4, [pc], -r4 */
/* @0x151130 .word 0xffffdda0 */
/* @0x151134 ldrheq r4, [pc], -r8 */
/* @0x151138 .word 0xffffdda4 */
/* @0x15113c andseq r4, pc, r0, asr #23 */
/* @0x151140 .word 0xffffdda8 */
/* @0x151144 andseq r4, pc, r0, asr #23 */
/* @0x151148 .word 0xffffddac */
/* @0x15114c andseq r4, pc, r0, asr #23 */
/* @0x151150 .word 0xffffddb0 */
/* @0x151154 andseq r4, pc, r4, asr #23 */
/* @0x151158 .word 0xffffddb4 */
/* @0x15115c andseq r4, pc, r8, asr #23 */
/* @0x151160 .word 0xffffddb8 */
/* @0x151164 andseq r4, pc, r12, asr #23 */
/* @0x151168 .word 0xffffddbc */
/* @0x15116c ldrsbeq r4, [pc], -r0 */
/* @0x151170 .word 0xffffddc0 */
/* @0x151174 ldrsbeq r4, [pc], -r8 */
/* @0x151178 .word 0xffffddc4 */
/* @0x15117c andseq r4, pc, r0, ror #23 */
/* @0x151180 .word 0xffffddc8 */
/* @0x151184 andseq r4, pc, r8, ror #23 */
/* @0x151188 .word 0xffffddcc */
/* @0x15118c ldrsheq r4, [pc], -r0 */
/* @0x151190 .word 0xffffddd0 */
/* @0x151194 ldrsheq r4, [pc], -r8 */
/* @0x151198 .word 0xffffddd4 */
/* @0x15119c andseq r4, pc, r0, lsl #24 */
/* @0x1511a0 .word 0xffffddd8 */
/* @0x1511a4 andseq r4, pc, r4, lsl #24 */
/* @0x1511a8 .word 0xffffdddc */
/* @0x1511ac andseq r4, pc, r8, lsl #24 */
/* @0x1511b0 .word 0xffffdde0 */
/* @0x1511b4 andseq r4, pc, r0, lsl r12 */
/* @0x1511b8 .word 0xffffdde4 */
/* @0x1511bc andseq r4, pc, r8, lsl r12 */
/* @0x1511c0 .word 0xffffdde8 */
/* @0x1511c4 andseq r4, pc, r0, lsr #24 */
/* @0x1511c8 .word 0xffffddec */
/* @0x1511cc andseq r4, pc, r4, lsr #24 */
/* @0x1511d0 .word 0xffffddf0 */
/* @0x1511d4 andseq r4, pc, r4, lsr #24 */
/* @0x1511d8 .word 0xffffddf4 */
/* @0x1511dc andseq r4, pc, r8, lsr #24 */
/* @0x1511e0 .word 0xffffddf8 */
/* @0x1511e4 andseq r4, pc, r12, lsr #24 */
/* @0x1511e8 .word 0xffffddfc */
/* @0x1511ec andseq r4, pc, r4, lsr r12 */
/* @0x1511f0 .word 0xffffde00 */
/* @0x1511f4 andseq r4, pc, r8, lsr r12 */
/* @0x1511f8 .word 0xffffde04 */
/* @0x1511fc andseq r4, pc, r8, lsr r12 */
/* @0x151200 .word 0xffffde08 */
/* @0x151204 andseq r4, pc, r12, lsr r12 */
/* @0x151208 .word 0xffffde0c */
/* @0x15120c andseq r4, pc, r0, asr #24 */

/* ── FUNC 0x151210 · F_GamepadGetDeviceCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x151210 ldr r3, [pc, #0x20] */
/* @0x151214 mov r2, #0 */
/* @0x151218 str r2, [r0, #0xc] */
/* @0x15121c ldr r3, [pc, r3] */
/* @0x151220 ldr r2, [r3] */
/* @0x151224 vmov s15, r2 */
/* @0x151228 vcvt.f64.s32 d7, s15 */
/* @0x15122c vmov r2, r3, d7 */
/* @0x151230 stm r0, {r2, r3} */
/* @0x151234 bx lr */
/* @0x151238 eoreq lr, r9, r4, asr #16 */

/* ── FUNC 0x15123c · F_GamepadSupported(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x15123c push {r3, r4, r5, lr} */
/* @0x151240 mov r5, #0 */
/* @0x151244 str r5, [r0, #0xc] */
/* @0x151248 mov r4, r0 */
/* @0x15124c bl 0x190ac4 <_Z17GamepadSupportedMv> */
/* @0x151250 cmp r0, #0 */
/* @0x151254 movne r0, r5 */
/* @0x151258 moveq r3, r0 */
/* @0x15125c movne r3, r0 */
/* @0x151260 movtne r3, #0x3ff0 */
/* @0x151264 stm r4, {r0, r3} */
/* @0x151268 pop {r3, r4, r5, pc} */

/* ── FUNC 0x15126c · F_GamepadConnected(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x15126c push {r3, r4, r5, lr} */
/* @0x151270 mov r5, #0 */
/* @0x151274 mov r4, r0 */
/* @0x151278 str r5, [r0, #0xc] */
/* @0x15127c str r5, [r0] */
/* @0x151280 mov r1, r5 */
/* @0x151284 str r5, [r0, #0x4] */
/* @0x151288 ldr r0, [sp, #0x10] */
/* @0x15128c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151290 cmp r0, #0 */
/* @0x151294 poplt {r3, r4, r5, pc} */
/* @0x151298 ldr r3, [pc, #0x3c] */
/* @0x15129c ldr r3, [pc, r3] */
/* @0x1512a0 ldr r3, [r3] */
/* @0x1512a4 cmp r0, r3 */
/* @0x1512a8 popge {r3, r4, r5, pc} */
/* @0x1512ac ldr r3, [pc, #0x2c] */
/* @0x1512b0 ldr r3, [pc, r3] */
/* @0x1512b4 ldr r3, [r3] */
/* @0x1512b8 ldr r3, [r3, r0, lsl #2] */
/* @0x1512bc ldrb r3, [r3] */
/* @0x1512c0 cmp r3, #0 */
/* @0x1512c4 movne r3, #0 */
/* @0x1512c8 movtne r3, #0x3ff0 */
/* @0x1512cc moveq r5, r3 */
/* @0x1512d0 str r5, [r4] */
/* @0x1512d4 str r3, [r4, #0x4] */
/* @0x1512d8 pop {r3, r4, r5, pc} */
/* @0x1512dc eoreq lr, r9, r4, asr #15 */
/* @0x1512e0 .word 0x0029e7b4 */

/* ── FUNC 0x1512e4 · F_GamepadGetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1512e4 push {r4, lr} */
/* @0x1512e8 mov r3, #0 */
/* @0x1512ec mov r4, r0 */
/* @0x1512f0 str r3, [r0, #0xc] */
/* @0x1512f4 str r3, [r0] */
/* @0x1512f8 mov r1, r3 */
/* @0x1512fc str r3, [r0, #0x4] */
/* @0x151300 ldr r0, [sp, #0x8] */
/* @0x151304 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151308 cmp r0, #0 */
/* @0x15130c poplt {r4, pc} */
/* @0x151310 ldr r3, [pc, #0x30] */
/* @0x151314 ldr r3, [pc, r3] */
/* @0x151318 ldr r3, [r3] */
/* @0x15131c cmp r0, r3 */
/* @0x151320 popge {r4, pc} */
/* @0x151324 ldr r3, [pc, #0x20] */
/* @0x151328 ldr r3, [pc, r3] */
/* @0x15132c ldr r3, [r3] */
/* @0x151330 ldr r3, [r3, r0, lsl #2] */
/* @0x151334 vldr s15, [r3, #28] */
/* @0x151338 vcvt.f64.f32 d6, s15 */
/* @0x15133c vmov r2, r3, d6 */
/* @0x151340 stm r4, {r2, r3} */
/* @0x151344 pop {r4, pc} */
/* @0x151348 eoreq lr, r9, r12, asr #14 */
/* @0x15134c eoreq lr, r9, r12, lsr r7 */

/* ── FUNC 0x151350 · F_GamepadGetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x151350 push {r4, lr} */
/* @0x151354 mov r3, #0 */
/* @0x151358 mov r4, r0 */
/* @0x15135c str r3, [r0, #0xc] */
/* @0x151360 str r3, [r0] */
/* @0x151364 mov r1, r3 */
/* @0x151368 str r3, [r0, #0x4] */
/* @0x15136c ldr r0, [sp, #0x8] */
/* @0x151370 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151374 cmp r0, #0 */
/* @0x151378 poplt {r4, pc} */
/* @0x15137c ldr r3, [pc, #0x30] */
/* @0x151380 ldr r3, [pc, r3] */
/* @0x151384 ldr r3, [r3] */
/* @0x151388 cmp r0, r3 */
/* @0x15138c popge {r4, pc} */
/* @0x151390 ldr r3, [pc, #0x20] */
/* @0x151394 ldr r3, [pc, r3] */
/* @0x151398 ldr r3, [r3] */
/* @0x15139c ldr r3, [r3, r0, lsl #2] */
/* @0x1513a0 vldr s15, [r3, #32] */
/* @0x1513a4 vcvt.f64.f32 d6, s15 */
/* @0x1513a8 vmov r2, r3, d6 */
/* @0x1513ac stm r4, {r2, r3} */
/* @0x1513b0 pop {r4, pc} */
/* @0x1513b4 eoreq lr, r9, r0, ror #13 */
/* @0x1513b8 .word 0x0029e6d0 */

/* ── FUNC 0x1513bc · F_GamepadGetDescription(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1513bc push {r4, lr} */
/* @0x1513c0 mov r2, #1 */
/* @0x1513c4 ldr r3, [sp, #0x8] */
/* @0x1513c8 mov r1, #0 */
/* @0x1513cc str r2, [r0, #0xc] */
/* @0x1513d0 mov r4, r0 */
/* @0x1513d4 str r1, [r0] */
/* @0x1513d8 mov r0, r3 */
/* @0x1513dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1513e0 subs r2, r0, #0 */
/* @0x1513e4 poplt {r4, pc} */
/* @0x1513e8 ldr r3, [pc, #0x2c] */
/* @0x1513ec ldr r3, [pc, r3] */
/* @0x1513f0 ldr r3, [r3] */
/* @0x1513f4 cmp r2, r3 */
/* @0x1513f8 popge {r4, pc} */
/* @0x1513fc ldr r3, [pc, #0x1c] */
/* @0x151400 mov r0, r4 */
/* @0x151404 pop {r4, lr} */
/* @0x151408 ldr r3, [pc, r3] */
/* @0x15140c ldr r3, [r3] */
/* @0x151410 ldr r1, [r3, r2, lsl #2] */
/* @0x151414 add r1, r1, #44 */
/* @0x151418 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x15141c eoreq lr, r9, r4, ror r6 */
/* @0x151420 eoreq lr, r9, r12, asr r6 */

/* ── FUNC 0x151424 · F_GamepadButtonCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x151424 push {r4, lr} */
/* @0x151428 mov r3, #0 */
/* @0x15142c mov r4, r0 */
/* @0x151430 str r3, [r0, #0xc] */
/* @0x151434 str r3, [r0] */
/* @0x151438 mov r1, r3 */
/* @0x15143c str r3, [r0, #0x4] */
/* @0x151440 ldr r0, [sp, #0x8] */
/* @0x151444 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151448 cmp r0, #0 */
/* @0x15144c poplt {r4, pc} */
/* @0x151450 ldr r3, [pc, #0x3c] */
/* @0x151454 ldr r3, [pc, r3] */
/* @0x151458 ldr r3, [r3] */
/* @0x15145c cmp r0, r3 */
/* @0x151460 popge {r4, pc} */
/* @0x151464 ldr r3, [pc, #0x2c] */
/* @0x151468 ldr r3, [pc, r3] */
/* @0x15146c ldr r3, [r3] */
/* @0x151470 ldr r0, [r3, r0, lsl #2] */
/* @0x151474 bl 0x18ead0 <_ZNK9GMGamePad11ButtonCountEv> */
/* @0x151478 vmov s15, r0 */
/* @0x15147c vcvt.f64.s32 d7, s15 */
/* @0x151480 vmov r0, r1, d7 */
/* @0x151484 vmov r2, s14 */
/* @0x151488 mov r3, r1 */
/* @0x15148c stm r4, {r2, r3} */
/* @0x151490 pop {r4, pc} */
/* @0x151494 eoreq lr, r9, r12, lsl #12 */
/* @0x151498 .word 0x0029e5fc */

/* ── FUNC 0x15149c · anon_15149c · size=20 · insn=6 */
/* @0x15149c push {r3, lr} */
/* @0x1514a0 bl 0x190ac4 <_Z17GamepadSupportedMv> */
/* @0x1514a4 cmp r0, #0 */
/* @0x1514a8 popne {r3, pc} */
/* @0x1514ac pop {r3, lr} */
/* @0x1514b0 b 0x1909f4 <_Z21GamepadReportFailureMv> */

/* ── FUNC 0x1514b4 · F_GamepadButtonCheck(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1514b4 push {r4, r5, r6, lr} */
/* @0x1514b8 mov r4, #0 */
/* @0x1514bc ldr r6, [sp, #0x10] */
/* @0x1514c0 mov r5, r0 */
/* @0x1514c4 str r4, [r0, #0xc] */
/* @0x1514c8 str r4, [r0] */
/* @0x1514cc str r4, [r0, #0x4] */
/* @0x1514d0 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1514d4 mov r1, r4 */
/* @0x1514d8 mov r0, r6 */
/* @0x1514dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1514e0 subs r4, r0, #0 */
/* @0x1514e4 poplt {r4, r5, r6, pc} */
/* @0x1514e8 ldr r3, [pc, #0x58] */
/* @0x1514ec ldr r3, [pc, r3] */
/* @0x1514f0 ldr r3, [r3] */
/* @0x1514f4 cmp r4, r3 */
/* @0x1514f8 popge {r4, r5, r6, pc} */
/* @0x1514fc mov r1, #1 */
/* @0x151500 mov r0, r6 */
/* @0x151504 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151508 mov r1, r0 */
/* @0x15150c mov r0, r4 */
/* @0x151510 bl 0x190acc <_Z23TranslateGamepadButtonMii> */
/* @0x151514 ldr r3, [pc, #0x30] */
/* @0x151518 ldr r3, [pc, r3] */
/* @0x15151c ldr r3, [r3] */
/* @0x151520 mov r1, r0 */
/* @0x151524 ldr r0, [r3, r4, lsl #2] */
/* @0x151528 bl 0x18eb5c <_ZNK9GMGamePad10ButtonDownEi> */
/* @0x15152c vmov s15, r0 */
/* @0x151530 vcvt.f64.u32 d7, s15 */
/* @0x151534 vmov r0, r1, d7 */
/* @0x151538 vmov r2, s14 */
/* @0x15153c mov r3, r1 */
/* @0x151540 stm r5, {r2, r3} */
/* @0x151544 pop {r4, r5, r6, pc} */
/* @0x151548 eoreq lr, r9, r4, ror r5 */
/* @0x15154c eoreq lr, r9, r12, asr #10 */

/* ── FUNC 0x151550 · F_GamepadButtonCheckPressed(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x151550 push {r4, r5, r6, lr} */
/* @0x151554 mov r4, #0 */
/* @0x151558 ldr r6, [sp, #0x10] */
/* @0x15155c mov r5, r0 */
/* @0x151560 str r4, [r0, #0xc] */
/* @0x151564 str r4, [r0] */
/* @0x151568 str r4, [r0, #0x4] */
/* @0x15156c bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x151570 mov r1, r4 */
/* @0x151574 mov r0, r6 */
/* @0x151578 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15157c subs r4, r0, #0 */
/* @0x151580 poplt {r4, r5, r6, pc} */
/* @0x151584 ldr r3, [pc, #0x58] */
/* @0x151588 ldr r3, [pc, r3] */
/* @0x15158c ldr r3, [r3] */
/* @0x151590 cmp r4, r3 */
/* @0x151594 popge {r4, r5, r6, pc} */
/* @0x151598 mov r1, #1 */
/* @0x15159c mov r0, r6 */
/* @0x1515a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1515a4 mov r1, r0 */
/* @0x1515a8 mov r0, r4 */
/* @0x1515ac bl 0x190acc <_Z23TranslateGamepadButtonMii> */
/* @0x1515b0 ldr r3, [pc, #0x30] */
/* @0x1515b4 ldr r3, [pc, r3] */
/* @0x1515b8 ldr r3, [r3] */
/* @0x1515bc mov r1, r0 */
/* @0x1515c0 ldr r0, [r3, r4, lsl #2] */
/* @0x1515c4 bl 0x18ebd8 <_ZNK9GMGamePad13ButtonPressedEi> */
/* @0x1515c8 vmov s15, r0 */
/* @0x1515cc vcvt.f64.u32 d7, s15 */
/* @0x1515d0 vmov r0, r1, d7 */
/* @0x1515d4 vmov r2, s14 */
/* @0x1515d8 mov r3, r1 */
/* @0x1515dc stm r5, {r2, r3} */
/* @0x1515e0 pop {r4, r5, r6, pc} */
/* @0x1515e4 .word 0x0029e4d8 */
/* @0x1515e8 .word 0x0029e4b0 */

/* ── FUNC 0x1515ec · F_GamepadButtonCheckReleased(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x1515ec push {r4, r5, r6, lr} */
/* @0x1515f0 mov r4, #0 */
/* @0x1515f4 ldr r6, [sp, #0x10] */
/* @0x1515f8 mov r5, r0 */
/* @0x1515fc str r4, [r0, #0xc] */
/* @0x151600 str r4, [r0] */
/* @0x151604 str r4, [r0, #0x4] */
/* @0x151608 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x15160c mov r1, r4 */
/* @0x151610 mov r0, r6 */
/* @0x151614 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151618 subs r4, r0, #0 */
/* @0x15161c poplt {r4, r5, r6, pc} */
/* @0x151620 ldr r3, [pc, #0x58] */
/* @0x151624 ldr r3, [pc, r3] */
/* @0x151628 ldr r3, [r3] */
/* @0x15162c cmp r4, r3 */
/* @0x151630 popge {r4, r5, r6, pc} */
/* @0x151634 mov r1, #1 */
/* @0x151638 mov r0, r6 */
/* @0x15163c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151640 mov r1, r0 */
/* @0x151644 mov r0, r4 */
/* @0x151648 bl 0x190acc <_Z23TranslateGamepadButtonMii> */
/* @0x15164c ldr r3, [pc, #0x30] */
/* @0x151650 ldr r3, [pc, r3] */
/* @0x151654 ldr r3, [r3] */
/* @0x151658 mov r1, r0 */
/* @0x15165c ldr r0, [r3, r4, lsl #2] */
/* @0x151660 bl 0x18ec90 <_ZNK9GMGamePad14ButtonReleasedEi> */
/* @0x151664 vmov s15, r0 */
/* @0x151668 vcvt.f64.u32 d7, s15 */
/* @0x15166c vmov r0, r1, d7 */
/* @0x151670 vmov r2, s14 */
/* @0x151674 mov r3, r1 */
/* @0x151678 stm r5, {r2, r3} */
/* @0x15167c pop {r4, r5, r6, pc} */
/* @0x151680 eoreq lr, r9, r12, lsr r4 */
/* @0x151684 eoreq lr, r9, r4, lsl r4 */
