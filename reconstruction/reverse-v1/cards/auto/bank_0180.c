/* libyoyo.so 覆盖卡组 0180
 * 函数 0x1feafc..0x2010e4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1feafc · SV_PhysicsAngularDamping(CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1feafc push {r3, r4, r6, r7, r8, lr} */
/* @0x1feb00 mov r1, #1 */
/* @0x1feb04 mov r6, r2 */
/* @0x1feb08 mov r2, #0 */
/* @0x1feb0c mov r4, r0 */
/* @0x1feb10 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1feb14 subs r7, r0, #0 */
/* @0x1feb18 beq 0x1feb4c <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x50> */
/* @0x1feb1c ldr r8, [r4, #0x84] */
/* @0x1feb20 cmp r8, #0 */
/* @0x1feb24 beq 0x1feb60 <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x64> */
/* @0x1feb28 ldr r3, [r6, #0xc] */
/* @0x1feb2c bic r3, r3, #-16777216 */
/* @0x1feb30 cmp r3, #0 */
/* @0x1feb34 bne 0x1feb54 <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x58> */
/* @0x1feb38 ldm r6, {r0, r1} */
/* @0x1feb3c vmov d6, r0, r1 */
/* @0x1feb40 ldr r3, [r8] */
/* @0x1feb44 vcvt.f32.f64 s15, d6 */
/* @0x1feb48 vstr s15, [r3, #152] */
/* @0x1feb4c mov r0, r7 */
/* @0x1feb50 pop {r3, r4, r6, r7, r8, pc} */
/* @0x1feb54 mov r0, r6 */
/* @0x1feb58 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1feb5c b 0x1feb3c <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x40> */
/* @0x1feb60 mov r7, r8 */
/* @0x1feb64 b 0x1feb4c <_Z24SV_PhysicsAngularDampingP9CInstanceiP6RValue+0x50> */

/* ── FUNC 0x1feb68 · SV_PhysicsLinearDamping(CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x1feb68 push {r3, r4, r6, r7, r8, lr} */
/* @0x1feb6c mov r1, #1 */
/* @0x1feb70 mov r6, r2 */
/* @0x1feb74 mov r2, #0 */
/* @0x1feb78 mov r4, r0 */
/* @0x1feb7c bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1feb80 subs r7, r0, #0 */
/* @0x1feb84 beq 0x1febb8 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x50> */
/* @0x1feb88 ldr r8, [r4, #0x84] */
/* @0x1feb8c cmp r8, #0 */
/* @0x1feb90 beq 0x1febcc <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x64> */
/* @0x1feb94 ldr r3, [r6, #0xc] */
/* @0x1feb98 bic r3, r3, #-16777216 */
/* @0x1feb9c cmp r3, #0 */
/* @0x1feba0 bne 0x1febc0 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x58> */
/* @0x1feba4 ldm r6, {r0, r1} */
/* @0x1feba8 vmov d6, r0, r1 */
/* @0x1febac ldr r3, [r8] */
/* @0x1febb0 vcvt.f32.f64 s15, d6 */
/* @0x1febb4 vstr s15, [r3, #148] */
/* @0x1febb8 mov r0, r7 */
/* @0x1febbc pop {r3, r4, r6, r7, r8, pc} */
/* @0x1febc0 mov r0, r6 */
/* @0x1febc4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1febc8 b 0x1feba8 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x40> */
/* @0x1febcc mov r7, r8 */
/* @0x1febd0 b 0x1febb8 <_Z23SV_PhysicsLinearDampingP9CInstanceiP6RValue+0x50> */

/* ── FUNC 0x1febd4 · SV_PhysicsBullet(CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1febd4 push {r3, r4, r6, r7, r8, lr} */
/* @0x1febd8 mov r1, #1 */
/* @0x1febdc mov r6, r2 */
/* @0x1febe0 mov r2, #0 */
/* @0x1febe4 mov r4, r0 */
/* @0x1febe8 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1febec subs r7, r0, #0 */
/* @0x1febf0 beq 0x1fec38 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x64> */
/* @0x1febf4 ldr r8, [r4, #0x84] */
/* @0x1febf8 cmp r8, #0 */
/* @0x1febfc beq 0x1fec4c <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x78> */
/* @0x1fec00 ldr r3, [r6, #0xc] */
/* @0x1fec04 bic r3, r3, #-16777216 */
/* @0x1fec08 cmp r3, #0 */
/* @0x1fec0c bne 0x1fec40 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x6c> */
/* @0x1fec10 ldm r6, {r0, r1} */
/* @0x1fec14 vmov.f64 d7, #5.000000e-01 */
/* @0x1fec18 ldr r3, [r8] */
/* @0x1fec1c vmov d6, r0, r1 */
/* @0x1fec20 ldrh r2, [r3, #4] */
/* @0x1fec24 vcmpe.f64 d6, d7 */
/* @0x1fec28 vmrs APSR_nzcv, fpscr */
/* @0x1fec2c orrgt r2, r2, #8 */
/* @0x1fec30 bicle r2, r2, #8 */
/* @0x1fec34 strh r2, [r3, #4] */
/* @0x1fec38 mov r0, r7 */
/* @0x1fec3c pop {r3, r4, r6, r7, r8, pc} */
/* @0x1fec40 mov r0, r6 */
/* @0x1fec44 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fec48 b 0x1fec14 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x40> */
/* @0x1fec4c mov r7, r8 */
/* @0x1fec50 b 0x1fec38 <_Z16SV_PhysicsBulletP9CInstanceiP6RValue+0x64> */

/* ── FUNC 0x1fec54 · SV_PhysicsFixedRotation(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fec54 push {r4, r5, r6, r7, r8, lr} */
/* @0x1fec58 mov r1, #1 */
/* @0x1fec5c mov r6, r2 */
/* @0x1fec60 mov r2, #0 */
/* @0x1fec64 mov r4, r0 */
/* @0x1fec68 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fec6c subs r7, r0, #0 */
/* @0x1fec70 beq 0x1fecb4 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x60> */
/* @0x1fec74 ldr r8, [r4, #0x84] */
/* @0x1fec78 cmp r8, #0 */
/* @0x1fec7c beq 0x1fecd0 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x7c> */
/* @0x1fec80 ldr r3, [r6, #0xc] */
/* @0x1fec84 bic r3, r3, #-16777216 */
/* @0x1fec88 cmp r3, #0 */
/* @0x1fec8c bne 0x1fecbc <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x68> */
/* @0x1fec90 ldm r6, {r4, r5} */
/* @0x1fec94 vmov.f64 d7, #5.000000e-01 */
/* @0x1fec98 ldr r0, [r8] */
/* @0x1fec9c vmov d6, r4, r5 */
/* @0x1feca0 vcmpe.f64 d6, d7 */
/* @0x1feca4 vmrs APSR_nzcv, fpscr */
/* @0x1feca8 movle r1, #0 */
/* @0x1fecac movgt r1, #1 */
/* @0x1fecb0 bl 0x2c7580 <_ZN6b2Body16SetFixedRotationEb> */
/* @0x1fecb4 mov r0, r7 */
/* @0x1fecb8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1fecbc mov r0, r6 */
/* @0x1fecc0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fecc4 mov r4, r0 */
/* @0x1fecc8 mov r5, r1 */
/* @0x1feccc b 0x1fec94 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x40> */
/* @0x1fecd0 mov r7, r8 */
/* @0x1fecd4 b 0x1fecb4 <_Z23SV_PhysicsFixedRotationP9CInstanceiP6RValue+0x60> */

/* ── FUNC 0x1fecd8 · SV_PhysicsActive(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fecd8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1fecdc mov r1, #1 */
/* @0x1fece0 mov r6, r2 */
/* @0x1fece4 mov r2, #0 */
/* @0x1fece8 mov r4, r0 */
/* @0x1fecec bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb> */
/* @0x1fecf0 subs r7, r0, #0 */
/* @0x1fecf4 beq 0x1fed38 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x60> */
/* @0x1fecf8 ldr r8, [r4, #0x84] */
/* @0x1fecfc cmp r8, #0 */
/* @0x1fed00 beq 0x1fed54 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x7c> */
/* @0x1fed04 ldr r3, [r6, #0xc] */
/* @0x1fed08 bic r3, r3, #-16777216 */
/* @0x1fed0c cmp r3, #0 */
/* @0x1fed10 bne 0x1fed40 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x68> */
/* @0x1fed14 ldm r6, {r4, r5} */
/* @0x1fed18 vmov.f64 d7, #5.000000e-01 */
/* @0x1fed1c ldr r0, [r8] */
/* @0x1fed20 vmov d6, r4, r5 */
/* @0x1fed24 vcmpe.f64 d6, d7 */
/* @0x1fed28 vmrs APSR_nzcv, fpscr */
/* @0x1fed2c movle r1, #0 */
/* @0x1fed30 movgt r1, #1 */
/* @0x1fed34 bl 0x2c74ac <_ZN6b2Body9SetActiveEb> */
/* @0x1fed38 mov r0, r7 */
/* @0x1fed3c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1fed40 mov r0, r6 */
/* @0x1fed44 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fed48 mov r4, r0 */
/* @0x1fed4c mov r5, r1 */
/* @0x1fed50 b 0x1fed18 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x40> */
/* @0x1fed54 mov r7, r8 */
/* @0x1fed58 b 0x1fed38 <_Z16SV_PhysicsActiveP9CInstanceiP6RValue+0x60> */

/* ── FUNC 0x1fed5c · InitLocalVariables() · size=3540 · insn=885 */
/* @0x1fed5c push {r4, lr} */
/* @0x1fed60 mov r3, #1 */
/* @0x1fed64 ldr r4, [pc, #0xa3c] */
/* @0x1fed68 ldr r1, [pc, #0xa3c] */
/* @0x1fed6c ldr r2, [pc, #0xa3c] */
/* @0x1fed70 add r4, pc, r4 */
/* @0x1fed74 ldr r0, [pc, #0xa38] */
/* @0x1fed78 ldr r1, [r4, r1] */
/* @0x1fed7c ldr r2, [r4, r2] */
/* @0x1fed80 add r0, pc, r0 */
/* @0x1fed84 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fed88 ldr r1, [pc, #0xa28] */
/* @0x1fed8c ldr r2, [pc, #0xa28] */
/* @0x1fed90 mov r3, #1 */
/* @0x1fed94 ldr r0, [pc, #0xa24] */
/* @0x1fed98 ldr r1, [r4, r1] */
/* @0x1fed9c ldr r2, [r4, r2] */
/* @0x1feda0 add r0, pc, r0 */
/* @0x1feda4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1feda8 ldr r1, [pc, #0xa14] */
/* @0x1fedac ldr r2, [pc, #0xa14] */
/* @0x1fedb0 mov r3, #1 */
/* @0x1fedb4 ldr r0, [pc, #0xa10] */
/* @0x1fedb8 ldr r1, [r4, r1] */
/* @0x1fedbc ldr r2, [r4, r2] */
/* @0x1fedc0 add r0, pc, r0 */
/* @0x1fedc4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fedc8 ldr r1, [pc, #0xa00] */
/* @0x1fedcc ldr r2, [pc, #0xa00] */
/* @0x1fedd0 mov r3, #1 */
/* @0x1fedd4 ldr r0, [pc, #0x9fc] */
/* @0x1fedd8 ldr r1, [r4, r1] */
/* @0x1feddc ldr r2, [r4, r2] */
/* @0x1fede0 add r0, pc, r0 */
/* @0x1fede4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fede8 ldr r1, [pc, #0x9ec] */
/* @0x1fedec ldr r2, [pc, #0x9ec] */
/* @0x1fedf0 mov r3, #1 */
/* @0x1fedf4 ldr r0, [pc, #0x9e8] */
/* @0x1fedf8 ldr r1, [r4, r1] */
/* @0x1fedfc ldr r2, [r4, r2] */
/* @0x1fee00 add r0, pc, r0 */
/* @0x1fee04 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fee08 ldr r1, [pc, #0x9d8] */
/* @0x1fee0c ldr r2, [pc, #0x9d8] */
/* @0x1fee10 mov r3, #1 */
/* @0x1fee14 ldr r0, [pc, #0x9d4] */
/* @0x1fee18 ldr r1, [r4, r1] */
/* @0x1fee1c ldr r2, [r4, r2] */
/* @0x1fee20 add r0, pc, r0 */
/* @0x1fee24 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fee28 ldr r1, [pc, #0x9c4] */
/* @0x1fee2c ldr r2, [pc, #0x9c4] */
/* @0x1fee30 mov r3, #1 */
/* @0x1fee34 ldr r0, [pc, #0x9c0] */
/* @0x1fee38 ldr r1, [r4, r1] */
/* @0x1fee3c ldr r2, [r4, r2] */
/* @0x1fee40 add r0, pc, r0 */
/* @0x1fee44 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fee48 ldr r1, [pc, #0x9b0] */
/* @0x1fee4c ldr r2, [pc, #0x9b0] */
/* @0x1fee50 mov r3, #1 */
/* @0x1fee54 ldr r0, [pc, #0x9ac] */
/* @0x1fee58 ldr r1, [r4, r1] */
/* @0x1fee5c ldr r2, [r4, r2] */
/* @0x1fee60 add r0, pc, r0 */
/* @0x1fee64 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fee68 ldr r1, [pc, #0x99c] */
/* @0x1fee6c ldr r2, [pc, #0x99c] */
/* @0x1fee70 mov r3, #1 */
/* @0x1fee74 ldr r0, [pc, #0x998] */
/* @0x1fee78 ldr r1, [r4, r1] */
/* @0x1fee7c ldr r2, [r4, r2] */
/* @0x1fee80 add r0, pc, r0 */
/* @0x1fee84 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fee88 ldr r1, [pc, #0x988] */
/* @0x1fee8c ldr r2, [pc, #0x988] */
/* @0x1fee90 mov r3, #1 */
/* @0x1fee94 ldr r0, [pc, #0x984] */
/* @0x1fee98 ldr r1, [r4, r1] */
/* @0x1fee9c ldr r2, [r4, r2] */
/* @0x1feea0 add r0, pc, r0 */
/* @0x1feea4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1feea8 ldr r1, [pc, #0x974] */
/* @0x1feeac ldr r2, [pc, #0x974] */
/* @0x1feeb0 mov r3, #1 */
/* @0x1feeb4 ldr r0, [pc, #0x970] */
/* @0x1feeb8 ldr r1, [r4, r1] */
/* @0x1feebc ldr r2, [r4, r2] */
/* @0x1feec0 add r0, pc, r0 */
/* @0x1feec4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1feec8 ldr r1, [pc, #0x960] */
/* @0x1feecc ldr r2, [pc, #0x960] */
/* @0x1feed0 mov r3, #1 */
/* @0x1feed4 ldr r0, [pc, #0x95c] */
/* @0x1feed8 ldr r1, [r4, r1] */
/* @0x1feedc ldr r2, [r4, r2] */
/* @0x1feee0 add r0, pc, r0 */
/* @0x1feee4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1feee8 ldr r1, [pc, #0x94c] */
/* @0x1feeec ldr r2, [pc, #0x94c] */
/* @0x1feef0 mov r3, #1 */
/* @0x1feef4 ldr r0, [pc, #0x948] */
/* @0x1feef8 ldr r1, [r4, r1] */
/* @0x1feefc ldr r2, [r4, r2] */
/* @0x1fef00 add r0, pc, r0 */
/* @0x1fef04 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fef08 ldr r1, [pc, #0x938] */
/* @0x1fef0c ldr r0, [pc, #0x938] */
/* @0x1fef10 mov r2, #0 */
/* @0x1fef14 mov r3, r2 */
/* @0x1fef18 ldr r1, [r4, r1] */
/* @0x1fef1c add r0, pc, r0 */
/* @0x1fef20 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fef24 ldr r1, [pc, #0x924] */
/* @0x1fef28 ldr r0, [pc, #0x924] */
/* @0x1fef2c mov r2, #0 */
/* @0x1fef30 mov r3, r2 */
/* @0x1fef34 ldr r1, [r4, r1] */
/* @0x1fef38 add r0, pc, r0 */
/* @0x1fef3c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fef40 ldr r1, [pc, #0x910] */
/* @0x1fef44 ldr r2, [pc, #0x910] */
/* @0x1fef48 mov r3, #1 */
/* @0x1fef4c ldr r0, [pc, #0x90c] */
/* @0x1fef50 ldr r1, [r4, r1] */
/* @0x1fef54 ldr r2, [r4, r2] */
/* @0x1fef58 add r0, pc, r0 */
/* @0x1fef5c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fef60 ldr r1, [pc, #0x8fc] */
/* @0x1fef64 ldr r2, [pc, #0x8fc] */
/* @0x1fef68 mov r3, #1 */
/* @0x1fef6c ldr r0, [pc, #0x8f8] */
/* @0x1fef70 ldr r1, [r4, r1] */
/* @0x1fef74 ldr r2, [r4, r2] */
/* @0x1fef78 add r0, pc, r0 */
/* @0x1fef7c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fef80 ldr r1, [pc, #0x8e8] */
/* @0x1fef84 ldr r2, [pc, #0x8e8] */
/* @0x1fef88 mov r3, #1 */
/* @0x1fef8c ldr r0, [pc, #0x8e4] */
/* @0x1fef90 ldr r1, [r4, r1] */
/* @0x1fef94 ldr r2, [r4, r2] */
/* @0x1fef98 add r0, pc, r0 */
/* @0x1fef9c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fefa0 ldr r1, [pc, #0x8d4] */
/* @0x1fefa4 ldr r2, [pc, #0x8d4] */
/* @0x1fefa8 mov r3, #1 */
/* @0x1fefac ldr r0, [pc, #0x8d0] */
/* @0x1fefb0 ldr r1, [r4, r1] */
/* @0x1fefb4 ldr r2, [r4, r2] */
/* @0x1fefb8 add r0, pc, r0 */
/* @0x1fefbc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fefc0 ldr r1, [pc, #0x8c0] */
/* @0x1fefc4 ldr r2, [pc, #0x8c0] */
/* @0x1fefc8 mov r3, #1 */
/* @0x1fefcc ldr r0, [pc, #0x8bc] */
/* @0x1fefd0 ldr r1, [r4, r1] */
/* @0x1fefd4 ldr r2, [r4, r2] */
/* @0x1fefd8 add r0, pc, r0 */
/* @0x1fefdc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fefe0 ldr r1, [pc, #0x8ac] */
/* @0x1fefe4 ldr r0, [pc, #0x8ac] */
/* @0x1fefe8 mov r2, #0 */
/* @0x1fefec mov r3, r2 */
/* @0x1feff0 ldr r1, [r4, r1] */
/* @0x1feff4 add r0, pc, r0 */
/* @0x1feff8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1feffc ldr r1, [pc, #0x898] */
/* @0x1ff000 ldr r0, [pc, #0x898] */
/* @0x1ff004 mov r2, #0 */
/* @0x1ff008 mov r3, r2 */
/* @0x1ff00c ldr r1, [r4, r1] */
/* @0x1ff010 add r0, pc, r0 */
/* @0x1ff014 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff018 ldr r1, [pc, #0x884] */
/* @0x1ff01c ldr r0, [pc, #0x884] */
/* @0x1ff020 mov r2, #0 */
/* @0x1ff024 mov r3, r2 */
/* @0x1ff028 ldr r1, [r4, r1] */
/* @0x1ff02c add r0, pc, r0 */
/* @0x1ff030 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff034 ldr r1, [pc, #0x870] */
/* @0x1ff038 ldr r0, [pc, #0x870] */
/* @0x1ff03c mov r2, #0 */
/* @0x1ff040 mov r3, r2 */
/* @0x1ff044 ldr r1, [r4, r1] */
/* @0x1ff048 add r0, pc, r0 */
/* @0x1ff04c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff050 ldr r1, [pc, #0x85c] */
/* @0x1ff054 ldr r2, [pc, #0x85c] */
/* @0x1ff058 mov r3, #1 */
/* @0x1ff05c ldr r0, [pc, #0x858] */
/* @0x1ff060 ldr r1, [r4, r1] */
/* @0x1ff064 ldr r2, [r4, r2] */
/* @0x1ff068 add r0, pc, r0 */
/* @0x1ff06c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff070 ldr r1, [pc, #0x848] */
/* @0x1ff074 ldr r2, [pc, #0x848] */
/* @0x1ff078 mov r3, #1 */
/* @0x1ff07c ldr r0, [pc, #0x844] */
/* @0x1ff080 ldr r1, [r4, r1] */
/* @0x1ff084 ldr r2, [r4, r2] */
/* @0x1ff088 add r0, pc, r0 */
/* @0x1ff08c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff090 ldr r1, [pc, #0x834] */
/* @0x1ff094 ldr r2, [pc, #0x834] */
/* @0x1ff098 mov r3, #1 */
/* @0x1ff09c ldr r0, [pc, #0x830] */
/* @0x1ff0a0 ldr r1, [r4, r1] */
/* @0x1ff0a4 ldr r2, [r4, r2] */
/* @0x1ff0a8 add r0, pc, r0 */
/* @0x1ff0ac bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff0b0 ldr r1, [pc, #0x820] */
/* @0x1ff0b4 ldr r0, [pc, #0x820] */
/* @0x1ff0b8 mov r2, #0 */
/* @0x1ff0bc mov r3, r2 */
/* @0x1ff0c0 ldr r1, [r4, r1] */
/* @0x1ff0c4 add r0, pc, r0 */
/* @0x1ff0c8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff0cc ldr r1, [pc, #0x80c] */
/* @0x1ff0d0 ldr r0, [pc, #0x80c] */
/* @0x1ff0d4 mov r2, #0 */
/* @0x1ff0d8 mov r3, r2 */
/* @0x1ff0dc ldr r1, [r4, r1] */
/* @0x1ff0e0 add r0, pc, r0 */
/* @0x1ff0e4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff0e8 ldr r1, [pc, #0x7f8] */
/* @0x1ff0ec ldr r0, [pc, #0x7f8] */
/* @0x1ff0f0 mov r2, #0 */
/* @0x1ff0f4 mov r3, r2 */
/* @0x1ff0f8 ldr r1, [r4, r1] */
/* @0x1ff0fc add r0, pc, r0 */
/* @0x1ff100 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff104 ldr r1, [pc, #0x7e4] */
/* @0x1ff108 ldr r0, [pc, #0x7e4] */
/* @0x1ff10c mov r2, #0 */
/* @0x1ff110 mov r3, r2 */
/* @0x1ff114 ldr r1, [r4, r1] */
/* @0x1ff118 add r0, pc, r0 */
/* @0x1ff11c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff120 ldr r1, [pc, #0x7d0] */
/* @0x1ff124 ldr r0, [pc, #0x7d0] */
/* @0x1ff128 mov r2, #0 */
/* @0x1ff12c mov r3, r2 */
/* @0x1ff130 ldr r1, [r4, r1] */
/* @0x1ff134 add r0, pc, r0 */
/* @0x1ff138 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff13c ldr r1, [pc, #0x7bc] */
/* @0x1ff140 ldr r2, [pc, #0x7bc] */
/* @0x1ff144 mov r3, #1 */
/* @0x1ff148 ldr r0, [pc, #0x7b8] */
/* @0x1ff14c ldr r1, [r4, r1] */
/* @0x1ff150 ldr r2, [r4, r2] */
/* @0x1ff154 add r0, pc, r0 */
/* @0x1ff158 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff15c ldr r1, [pc, #0x7a8] */
/* @0x1ff160 ldr r2, [pc, #0x7a8] */
/* @0x1ff164 mov r3, #1 */
/* @0x1ff168 ldr r0, [pc, #0x7a4] */
/* @0x1ff16c ldr r1, [r4, r1] */
/* @0x1ff170 ldr r2, [r4, r2] */
/* @0x1ff174 add r0, pc, r0 */
/* @0x1ff178 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff17c ldr r1, [pc, #0x794] */
/* @0x1ff180 ldr r2, [pc, #0x794] */
/* @0x1ff184 mov r3, #1 */
/* @0x1ff188 ldr r0, [pc, #0x790] */
/* @0x1ff18c ldr r1, [r4, r1] */
/* @0x1ff190 ldr r2, [r4, r2] */
/* @0x1ff194 add r0, pc, r0 */
/* @0x1ff198 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff19c ldr r1, [pc, #0x780] */
/* @0x1ff1a0 ldr r2, [pc, #0x780] */
/* @0x1ff1a4 mov r3, #1 */
/* @0x1ff1a8 ldr r0, [pc, #0x77c] */
/* @0x1ff1ac ldr r1, [r4, r1] */
/* @0x1ff1b0 ldr r2, [r4, r2] */
/* @0x1ff1b4 add r0, pc, r0 */
/* @0x1ff1b8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff1bc ldr r1, [pc, #0x76c] */
/* @0x1ff1c0 ldr r2, [pc, #0x76c] */
/* @0x1ff1c4 mov r3, #1 */
/* @0x1ff1c8 ldr r0, [pc, #0x768] */
/* @0x1ff1cc ldr r1, [r4, r1] */
/* @0x1ff1d0 ldr r2, [r4, r2] */
/* @0x1ff1d4 add r0, pc, r0 */
/* @0x1ff1d8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff1dc ldr r1, [pc, #0x758] */
/* @0x1ff1e0 ldr r2, [pc, #0x758] */
/* @0x1ff1e4 mov r3, #1 */
/* @0x1ff1e8 ldr r0, [pc, #0x754] */
/* @0x1ff1ec ldr r1, [r4, r1] */
/* @0x1ff1f0 ldr r2, [r4, r2] */
/* @0x1ff1f4 add r0, pc, r0 */
/* @0x1ff1f8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff1fc ldr r1, [pc, #0x744] */
/* @0x1ff200 ldr r2, [pc, #0x744] */
/* @0x1ff204 mov r3, #1 */
/* @0x1ff208 ldr r0, [pc, #0x740] */
/* @0x1ff20c ldr r1, [r4, r1] */
/* @0x1ff210 ldr r2, [r4, r2] */
/* @0x1ff214 add r0, pc, r0 */
/* @0x1ff218 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff21c ldr r1, [pc, #0x730] */
/* @0x1ff220 ldr r0, [pc, #0x730] */
/* @0x1ff224 mov r2, #0 */
/* @0x1ff228 mov r3, r2 */
/* @0x1ff22c ldr r1, [r4, r1] */
/* @0x1ff230 add r0, pc, r0 */
/* @0x1ff234 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff238 ldr r1, [pc, #0x71c] */
/* @0x1ff23c ldr r2, [pc, #0x71c] */
/* @0x1ff240 mov r3, #1 */
/* @0x1ff244 ldr r0, [pc, #0x718] */
/* @0x1ff248 ldr r1, [r4, r1] */
/* @0x1ff24c ldr r2, [r4, r2] */
/* @0x1ff250 add r0, pc, r0 */
/* @0x1ff254 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff258 ldr r1, [pc, #0x708] */
/* @0x1ff25c ldr r2, [pc, #0x708] */
/* @0x1ff260 mov r3, #1 */
/* @0x1ff264 ldr r0, [pc, #0x704] */
/* @0x1ff268 ldr r1, [r4, r1] */
/* @0x1ff26c ldr r2, [r4, r2] */
/* @0x1ff270 add r0, pc, r0 */
/* @0x1ff274 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff278 ldr r1, [pc, #0x6f4] */
/* @0x1ff27c ldr r2, [pc, #0x6f4] */
/* @0x1ff280 mov r3, #1 */
/* @0x1ff284 ldr r0, [pc, #0x6f0] */
/* @0x1ff288 ldr r1, [r4, r1] */
/* @0x1ff28c ldr r2, [r4, r2] */
/* @0x1ff290 add r0, pc, r0 */
/* @0x1ff294 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff298 ldr r1, [pc, #0x6e0] */
/* @0x1ff29c ldr r2, [pc, #0x6e0] */
/* @0x1ff2a0 mov r3, #1 */
/* @0x1ff2a4 ldr r0, [pc, #0x6dc] */
/* @0x1ff2a8 ldr r1, [r4, r1] */
/* @0x1ff2ac ldr r2, [r4, r2] */
/* @0x1ff2b0 add r0, pc, r0 */
/* @0x1ff2b4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff2b8 ldr r1, [pc, #0x6cc] */
/* @0x1ff2bc ldr r2, [pc, #0x6cc] */
/* @0x1ff2c0 mov r3, #1 */
/* @0x1ff2c4 ldr r0, [pc, #0x6c8] */
/* @0x1ff2c8 ldr r1, [r4, r1] */
/* @0x1ff2cc ldr r2, [r4, r2] */
/* @0x1ff2d0 add r0, pc, r0 */
/* @0x1ff2d4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff2d8 ldr r1, [pc, #0x6b8] */
/* @0x1ff2dc ldr r2, [pc, #0x6b8] */
/* @0x1ff2e0 mov r3, #1 */
/* @0x1ff2e4 ldr r0, [pc, #0x6b4] */
/* @0x1ff2e8 ldr r1, [r4, r1] */
/* @0x1ff2ec ldr r2, [r4, r2] */
/* @0x1ff2f0 add r0, pc, r0 */
/* @0x1ff2f4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff2f8 ldr r1, [pc, #0x6a4] */
/* @0x1ff2fc ldr r2, [pc, #0x6a4] */
/* @0x1ff300 mov r3, #1 */
/* @0x1ff304 ldr r0, [pc, #0x6a0] */
/* @0x1ff308 ldr r1, [r4, r1] */
/* @0x1ff30c ldr r2, [r4, r2] */
/* @0x1ff310 add r0, pc, r0 */
/* @0x1ff314 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff318 ldr r1, [pc, #0x690] */
/* @0x1ff31c ldr r2, [pc, #0x690] */
/* @0x1ff320 mov r3, #1 */
/* @0x1ff324 ldr r0, [pc, #0x68c] */
/* @0x1ff328 ldr r1, [r4, r1] */
/* @0x1ff32c ldr r2, [r4, r2] */
/* @0x1ff330 add r0, pc, r0 */
/* @0x1ff334 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff338 ldr r1, [pc, #0x67c] */
/* @0x1ff33c ldr r2, [pc, #0x67c] */
/* @0x1ff340 mov r3, #1 */
/* @0x1ff344 ldr r0, [pc, #0x678] */
/* @0x1ff348 ldr r1, [r4, r1] */
/* @0x1ff34c ldr r2, [r4, r2] */
/* @0x1ff350 add r0, pc, r0 */
/* @0x1ff354 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff358 ldr r1, [pc, #0x668] */
/* @0x1ff35c ldr r2, [pc, #0x668] */
/* @0x1ff360 mov r3, #1 */
/* @0x1ff364 ldr r0, [pc, #0x664] */
/* @0x1ff368 ldr r1, [r4, r1] */
/* @0x1ff36c ldr r2, [r4, r2] */
/* @0x1ff370 add r0, pc, r0 */
/* @0x1ff374 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff378 ldr r1, [pc, #0x654] */
/* @0x1ff37c ldr r2, [pc, #0x654] */
/* @0x1ff380 mov r3, #1 */
/* @0x1ff384 ldr r0, [pc, #0x650] */
/* @0x1ff388 ldr r1, [r4, r1] */
/* @0x1ff38c ldr r2, [r4, r2] */
/* @0x1ff390 add r0, pc, r0 */
/* @0x1ff394 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff398 ldr r1, [pc, #0x640] */
/* @0x1ff39c ldr r0, [pc, #0x640] */
/* @0x1ff3a0 mov r2, #0 */
/* @0x1ff3a4 mov r3, #1 */
/* @0x1ff3a8 ldr r1, [r4, r1] */
/* @0x1ff3ac add r0, pc, r0 */
/* @0x1ff3b0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff3b4 ldr r1, [pc, #0x62c] */
/* @0x1ff3b8 ldr r0, [pc, #0x62c] */
/* @0x1ff3bc mov r2, #0 */
/* @0x1ff3c0 mov r3, #1 */
/* @0x1ff3c4 ldr r1, [r4, r1] */
/* @0x1ff3c8 add r0, pc, r0 */
/* @0x1ff3cc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff3d0 ldr r1, [pc, #0x618] */
/* @0x1ff3d4 ldr r0, [pc, #0x618] */
/* @0x1ff3d8 mov r2, #0 */
/* @0x1ff3dc mov r3, r2 */
/* @0x1ff3e0 ldr r1, [r4, r1] */
/* @0x1ff3e4 add r0, pc, r0 */
/* @0x1ff3e8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff3ec ldr r1, [pc, #0x604] */
/* @0x1ff3f0 ldr r2, [pc, #0x604] */
/* @0x1ff3f4 mov r3, #1 */
/* @0x1ff3f8 ldr r0, [pc, #0x600] */
/* @0x1ff3fc ldr r1, [r4, r1] */
/* @0x1ff400 ldr r2, [r4, r2] */
/* @0x1ff404 add r0, pc, r0 */
/* @0x1ff408 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff40c ldr r1, [pc, #0x5f0] */
/* @0x1ff410 ldr r2, [pc, #0x5f0] */
/* @0x1ff414 mov r3, #1 */
/* @0x1ff418 ldr r0, [pc, #0x5ec] */
/* @0x1ff41c ldr r1, [r4, r1] */
/* @0x1ff420 ldr r2, [r4, r2] */
/* @0x1ff424 add r0, pc, r0 */
/* @0x1ff428 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff42c ldr r1, [pc, #0x5dc] */
/* @0x1ff430 ldr r2, [pc, #0x5dc] */
/* @0x1ff434 mov r3, #1 */
/* @0x1ff438 ldr r0, [pc, #0x5d8] */
/* @0x1ff43c ldr r1, [r4, r1] */
/* @0x1ff440 ldr r2, [r4, r2] */
/* @0x1ff444 add r0, pc, r0 */
/* @0x1ff448 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff44c ldr r1, [pc, #0x5c8] */
/* @0x1ff450 ldr r2, [pc, #0x5c8] */
/* @0x1ff454 mov r3, #1 */
/* @0x1ff458 ldr r0, [pc, #0x5c4] */
/* @0x1ff45c ldr r1, [r4, r1] */
/* @0x1ff460 ldr r2, [r4, r2] */
/* @0x1ff464 add r0, pc, r0 */
/* @0x1ff468 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff46c ldr r1, [pc, #0x5b4] */
/* @0x1ff470 ldr r2, [pc, #0x5b4] */
/* @0x1ff474 mov r3, #1 */
/* @0x1ff478 ldr r0, [pc, #0x5b0] */
/* @0x1ff47c ldr r1, [r4, r1] */
/* @0x1ff480 ldr r2, [r4, r2] */
/* @0x1ff484 add r0, pc, r0 */
/* @0x1ff488 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff48c ldr r1, [pc, #0x5a0] */
/* @0x1ff490 ldr r2, [pc, #0x5a0] */
/* @0x1ff494 mov r3, #1 */
/* @0x1ff498 ldr r0, [pc, #0x59c] */
/* @0x1ff49c ldr r1, [r4, r1] */
/* @0x1ff4a0 ldr r2, [r4, r2] */
/* @0x1ff4a4 add r0, pc, r0 */
/* @0x1ff4a8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff4ac ldr r1, [pc, #0x58c] */
/* @0x1ff4b0 ldr r2, [pc, #0x58c] */
/* @0x1ff4b4 mov r3, #1 */
/* @0x1ff4b8 ldr r0, [pc, #0x588] */
/* @0x1ff4bc ldr r1, [r4, r1] */
/* @0x1ff4c0 ldr r2, [r4, r2] */
/* @0x1ff4c4 add r0, pc, r0 */
/* @0x1ff4c8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff4cc ldr r1, [pc, #0x578] */
/* @0x1ff4d0 ldr r2, [pc, #0x578] */
/* @0x1ff4d4 mov r3, #1 */
/* @0x1ff4d8 ldr r0, [pc, #0x574] */
/* @0x1ff4dc ldr r1, [r4, r1] */
/* @0x1ff4e0 ldr r2, [r4, r2] */
/* @0x1ff4e4 add r0, pc, r0 */
/* @0x1ff4e8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff4ec ldr r1, [pc, #0x564] */
/* @0x1ff4f0 ldr r2, [pc, #0x564] */
/* @0x1ff4f4 mov r3, #1 */
/* @0x1ff4f8 ldr r0, [pc, #0x560] */
/* @0x1ff4fc ldr r1, [r4, r1] */
/* @0x1ff500 ldr r2, [r4, r2] */
/* @0x1ff504 add r0, pc, r0 */
/* @0x1ff508 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff50c ldr r1, [pc, #0x550] */
/* @0x1ff510 ldr r2, [pc, #0x550] */
/* @0x1ff514 mov r3, #1 */
/* @0x1ff518 ldr r0, [pc, #0x54c] */
/* @0x1ff51c ldr r1, [r4, r1] */
/* @0x1ff520 ldr r2, [r4, r2] */
/* @0x1ff524 add r0, pc, r0 */
/* @0x1ff528 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff52c ldr r1, [pc, #0x53c] */
/* @0x1ff530 ldr r2, [pc, #0x53c] */
/* @0x1ff534 mov r3, #1 */
/* @0x1ff538 ldr r0, [pc, #0x538] */
/* @0x1ff53c ldr r1, [r4, r1] */
/* @0x1ff540 ldr r2, [r4, r2] */
/* @0x1ff544 add r0, pc, r0 */
/* @0x1ff548 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff54c ldr r1, [pc, #0x528] */
/* @0x1ff550 ldr r2, [pc, #0x528] */
/* @0x1ff554 mov r3, #1 */
/* @0x1ff558 ldr r0, [pc, #0x524] */
/* @0x1ff55c ldr r1, [r4, r1] */
/* @0x1ff560 ldr r2, [r4, r2] */
/* @0x1ff564 add r0, pc, r0 */
/* @0x1ff568 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff56c ldr r1, [pc, #0x514] */
/* @0x1ff570 ldr r2, [pc, #0x514] */
/* @0x1ff574 mov r3, #1 */
/* @0x1ff578 ldr r0, [pc, #0x510] */
/* @0x1ff57c ldr r1, [r4, r1] */
/* @0x1ff580 ldr r2, [r4, r2] */
/* @0x1ff584 add r0, pc, r0 */
/* @0x1ff588 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff58c ldr r1, [pc, #0x500] */
/* @0x1ff590 ldr r0, [pc, #0x500] */
/* @0x1ff594 mov r2, #0 */
/* @0x1ff598 mov r3, r2 */
/* @0x1ff59c ldr r1, [r4, r1] */
/* @0x1ff5a0 add r0, pc, r0 */
/* @0x1ff5a4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff5a8 ldr r1, [pc, #0x4ec] */
/* @0x1ff5ac ldr r0, [pc, #0x4ec] */
/* @0x1ff5b0 mov r2, #0 */
/* @0x1ff5b4 mov r3, r2 */
/* @0x1ff5b8 ldr r1, [r4, r1] */
/* @0x1ff5bc add r0, pc, r0 */
/* @0x1ff5c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff5c4 ldr r1, [pc, #0x4d8] */
/* @0x1ff5c8 ldr r0, [pc, #0x4d8] */
/* @0x1ff5cc mov r2, #0 */
/* @0x1ff5d0 mov r3, r2 */
/* @0x1ff5d4 ldr r1, [r4, r1] */
/* @0x1ff5d8 add r0, pc, r0 */
/* @0x1ff5dc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff5e0 ldr r1, [pc, #0x4c4] */
/* @0x1ff5e4 ldr r0, [pc, #0x4c4] */
/* @0x1ff5e8 mov r2, #0 */
/* @0x1ff5ec mov r3, r2 */
/* @0x1ff5f0 ldr r1, [r4, r1] */
/* @0x1ff5f4 add r0, pc, r0 */
/* @0x1ff5f8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff5fc ldr r1, [pc, #0x4b0] */
/* @0x1ff600 ldr r0, [pc, #0x4b0] */
/* @0x1ff604 mov r2, #0 */
/* @0x1ff608 mov r3, r2 */
/* @0x1ff60c ldr r1, [r4, r1] */
/* @0x1ff610 add r0, pc, r0 */
/* @0x1ff614 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff618 ldr r1, [pc, #0x49c] */
/* @0x1ff61c ldr r0, [pc, #0x49c] */
/* @0x1ff620 mov r2, #0 */
/* @0x1ff624 mov r3, r2 */
/* @0x1ff628 ldr r1, [r4, r1] */
/* @0x1ff62c add r0, pc, r0 */
/* @0x1ff630 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff634 ldr r1, [pc, #0x488] */
/* @0x1ff638 ldr r0, [pc, #0x488] */
/* @0x1ff63c mov r2, #0 */
/* @0x1ff640 mov r3, r2 */
/* @0x1ff644 ldr r1, [r4, r1] */
/* @0x1ff648 add r0, pc, r0 */
/* @0x1ff64c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff650 ldr r1, [pc, #0x474] */
/* @0x1ff654 ldr r0, [pc, #0x474] */
/* @0x1ff658 mov r2, #0 */
/* @0x1ff65c mov r3, r2 */
/* @0x1ff660 ldr r1, [r4, r1] */
/* @0x1ff664 add r0, pc, r0 */
/* @0x1ff668 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff66c ldr r1, [pc, #0x460] */
/* @0x1ff670 ldr r0, [pc, #0x460] */
/* @0x1ff674 mov r2, #0 */
/* @0x1ff678 mov r3, r2 */
/* @0x1ff67c ldr r1, [r4, r1] */
/* @0x1ff680 add r0, pc, r0 */
/* @0x1ff684 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff688 ldr r1, [pc, #0x44c] */
/* @0x1ff68c ldr r0, [pc, #0x44c] */
/* @0x1ff690 mov r2, #0 */
/* @0x1ff694 mov r3, r2 */
/* @0x1ff698 ldr r1, [r4, r1] */
/* @0x1ff69c add r0, pc, r0 */
/* @0x1ff6a0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff6a4 ldr r1, [pc, #0x438] */
/* @0x1ff6a8 ldr r0, [pc, #0x438] */
/* @0x1ff6ac mov r2, #0 */
/* @0x1ff6b0 mov r3, r2 */
/* @0x1ff6b4 ldr r1, [r4, r1] */
/* @0x1ff6b8 add r0, pc, r0 */
/* @0x1ff6bc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff6c0 ldr r1, [pc, #0x424] */
/* @0x1ff6c4 ldr r0, [pc, #0x424] */
/* @0x1ff6c8 mov r2, #0 */
/* @0x1ff6cc mov r3, r2 */
/* @0x1ff6d0 ldr r1, [r4, r1] */
/* @0x1ff6d4 add r0, pc, r0 */
/* @0x1ff6d8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff6dc ldr r1, [pc, #0x410] */
/* @0x1ff6e0 ldr r0, [pc, #0x410] */
/* @0x1ff6e4 mov r2, #0 */
/* @0x1ff6e8 mov r3, r2 */
/* @0x1ff6ec ldr r1, [r4, r1] */
/* @0x1ff6f0 add r0, pc, r0 */
/* @0x1ff6f4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff6f8 ldr r1, [pc, #0x3fc] */
/* @0x1ff6fc ldr r0, [pc, #0x3fc] */
/* @0x1ff700 mov r2, #0 */
/* @0x1ff704 mov r3, r2 */
/* @0x1ff708 ldr r1, [r4, r1] */
/* @0x1ff70c add r0, pc, r0 */
/* @0x1ff710 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff714 ldr r1, [pc, #0x3e8] */
/* @0x1ff718 ldr r0, [pc, #0x3e8] */
/* @0x1ff71c mov r2, #0 */
/* @0x1ff720 mov r3, r2 */
/* @0x1ff724 ldr r1, [r4, r1] */
/* @0x1ff728 add r0, pc, r0 */
/* @0x1ff72c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff730 ldr r1, [pc, #0x3d4] */
/* @0x1ff734 ldr r0, [pc, #0x3d4] */
/* @0x1ff738 mov r2, #0 */
/* @0x1ff73c mov r3, r2 */
/* @0x1ff740 ldr r1, [r4, r1] */
/* @0x1ff744 add r0, pc, r0 */
/* @0x1ff748 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff74c ldr r1, [pc, #0x3c0] */
/* @0x1ff750 ldr r0, [pc, #0x3c0] */
/* @0x1ff754 mov r2, #0 */
/* @0x1ff758 mov r3, r2 */
/* @0x1ff75c ldr r1, [r4, r1] */
/* @0x1ff760 add r0, pc, r0 */
/* @0x1ff764 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff768 ldr r1, [pc, #0x3ac] */
/* @0x1ff76c ldr r0, [pc, #0x3ac] */
/* @0x1ff770 mov r2, #0 */
/* @0x1ff774 mov r3, r2 */
/* @0x1ff778 ldr r1, [r4, r1] */
/* @0x1ff77c add r0, pc, r0 */
/* @0x1ff780 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff784 ldr r1, [pc, #0x398] */
/* @0x1ff788 ldr r2, [pc, #0x398] */
/* @0x1ff78c mov r3, #1 */
/* @0x1ff790 ldr r0, [pc, #0x394] */
/* @0x1ff794 ldr r1, [r4, r1] */
/* @0x1ff798 ldr r2, [r4, r2] */
/* @0x1ff79c add r0, pc, r0 */
/* @0x1ff7a0 pop {r4, lr} */
/* @0x1ff7a4 b 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1ff7a8 andseq r2, pc, r0, ror #29 */
/* @0x1ff7ac .word 0xfffff4f8 */
/* @0x1ff7b0 .word 0xfffff4fc */
/* @0x1ff7b4 ldrsheq r1, [r3], -r4 */
/* @0x1ff7b8 .word 0xfffff500 */
/* @0x1ff7bc .word 0xfffff504 */
/* @0x1ff7c0 ldrsbeq r1, [r3], -r8 */
/* @0x1ff7c4 .word 0xfffff508 */
/* @0x1ff7c8 .word 0xfffff50c */
/* @0x1ff7cc andseq r4, r5, r0, ror #8 */
/* @0x1ff7d0 .word 0xfffff510 */
/* @0x1ff7d4 .word 0xfffff514 */
/* @0x1ff7d8 andseq r4, r5, r12, asr #8 */
/* @0x1ff7dc .word 0xfffff518 */
/* @0x1ff7e0 .word 0xfffff51c */
/* @0x1ff7e4 andseq r4, r5, r8, lsr r4 */
/* @0x1ff7e8 .word 0xfffff520 */
/* @0x1ff7ec .word 0xfffff524 */
/* @0x1ff7f0 andseq r4, r5, r0, lsr #8 */
/* @0x1ff7f4 .word 0xfffff528 */
/* @0x1ff7f8 .word 0xfffff52c */
/* @0x1ff7fc andseq r4, r5, r8, lsl #8 */
/* @0x1ff800 .word 0xfffff530 */
/* @0x1ff804 .word 0xfffff534 */
/* @0x1ff808 ldrsheq r4, [r5], -r0 */
/* @0x1ff80c .word 0xfffff538 */
/* @0x1ff810 .word 0xfffff53c */
/* @0x1ff814 ldrsbeq r4, [r5], -r8 */
/* @0x1ff818 .word 0xfffff540 */
/* @0x1ff81c .word 0xfffff544 */
/* @0x1ff820 andseq r4, r5, r4, asr #7 */
/* @0x1ff824 .word 0xfffff548 */
/* @0x1ff828 .word 0xfffff54c */
/* @0x1ff82c andseq r4, r5, r12, lsr #7 */
/* @0x1ff830 .word 0xfffff550 */
/* @0x1ff834 .word 0xfffff554 */
/* @0x1ff838 mulseq r5, r8, r3 */
/* @0x1ff83c .word 0xfffff558 */
/* @0x1ff840 .word 0xfffff55c */
/* @0x1ff844 andseq r4, r5, r0, lsl #7 */
/* @0x1ff848 .word 0xfffff560 */
/* @0x1ff84c andseq r4, r5, r8, ror r3 */
/* @0x1ff850 .word 0xfffff564 */
/* @0x1ff854 andseq r1, r3, r8, lsl #22 */
/* @0x1ff858 .word 0xfffff568 */
/* @0x1ff85c .word 0xfffff56c */
/* @0x1ff860 andseq r4, r5, r12, asr #6 */
/* @0x1ff864 .word 0xfffff570 */
/* @0x1ff868 .word 0xfffff574 */
/* @0x1ff86c andseq r4, r5, r4, lsr r3 */
/* @0x1ff870 .word 0xfffff578 */
/* @0x1ff874 .word 0xfffff57c */
/* @0x1ff878 andseq r4, r5, r12, lsl r3 */
/* @0x1ff87c .word 0xfffff580 */
/* @0x1ff880 .word 0xfffff584 */
/* @0x1ff884 andseq r4, r5, r4, lsl #6 */
/* @0x1ff888 .word 0xfffff588 */
/* @0x1ff88c .word 0xfffff58c */
/* @0x1ff890 ldrsheq r4, [r5], -r0 */
/* @0x1ff894 .word 0xfffff590 */
/* @0x1ff898 ldrsbeq r4, [r5], -r12 */
/* @0x1ff89c .word 0xfffff594 */
/* @0x1ff8a0 andseq r4, r5, r12, asr #5 */
/* @0x1ff8a4 .word 0xfffff598 */
/* @0x1ff8a8 ldrheq r4, [r5], -r12 */
/* @0x1ff8ac .word 0xfffff59c */
/* @0x1ff8b0 andseq r4, r5, r12, lsr #5 */
/* @0x1ff8b4 .word 0xfffff5a0 */
/* @0x1ff8b8 .word 0xfffff5a4 */
/* @0x1ff8bc mulseq r5, r8, r2 */
/* @0x1ff8c0 .word 0xfffff5a8 */
/* @0x1ff8c4 .word 0xfffff5ac */
/* @0x1ff8c8 andseq r4, r5, r8, lsl #5 */
/* @0x1ff8cc .word 0xfffff5b0 */
/* @0x1ff8d0 .word 0xfffff5b4 */
/* @0x1ff8d4 andseq r4, r5, r4, ror r2 */
/* @0x1ff8d8 .word 0xfffff5b8 */
/* @0x1ff8dc andseq r4, r5, r8, ror #4 */
/* @0x1ff8e0 .word 0xfffff5bc */
/* @0x1ff8e4 andseq r4, r5, r12, asr r2 */
/* @0x1ff8e8 .word 0xfffff5c0 */
/* @0x1ff8ec andseq r4, r5, r0, asr r2 */
/* @0x1ff8f0 .word 0xfffff5c4 */
/* @0x1ff8f4 andseq r4, r5, r4, asr #4 */
/* @0x1ff8f8 .word 0xfffff5c8 */
/* @0x1ff8fc andseq r4, r5, r8, lsr r2 */
/* @0x1ff900 .word 0xfffff5cc */
/* @0x1ff904 .word 0xfffff5d0 */
/* @0x1ff908 andseq r4, r5, r8, lsr #4 */
/* @0x1ff90c .word 0xfffff5d4 */
/* @0x1ff910 .word 0xfffff5d8 */
/* @0x1ff914 andseq r4, r5, r8, lsl r2 */
/* @0x1ff918 .word 0xfffff5dc */
/* @0x1ff91c .word 0xfffff5e0 */
/* @0x1ff920 andseq r4, r5, r8, lsl #4 */
/* @0x1ff924 .word 0xfffff5e4 */
/* @0x1ff928 .word 0xfffff5e8 */
/* @0x1ff92c ldrsheq r4, [r5], -r4 */
/* @0x1ff930 .word 0xfffff5ec */
/* @0x1ff934 .word 0xfffff5f0 */
/* @0x1ff938 andseq r4, r5, r0, ror #3 */
/* @0x1ff93c .word 0xfffff5f4 */
/* @0x1ff940 .word 0xfffff5f8 */
/* @0x1ff944 andseq r4, r5, r12, asr #3 */
/* @0x1ff948 .word 0xfffff5fc */
/* @0x1ff94c .word 0xfffff600 */
/* @0x1ff950 ldrheq r4, [r5], -r8 */
/* @0x1ff954 .word 0xfffff604 */
/* @0x1ff958 andseq r4, r5, r8, lsr #3 */
/* @0x1ff95c .word 0xfffff608 */
/* @0x1ff960 .word 0xfffff60c */
/* @0x1ff964 mulseq r5, r4, r1 */
/* @0x1ff968 .word 0xfffff610 */
/* @0x1ff96c .word 0xfffff614 */
/* @0x1ff970 andseq r4, r5, r4, lsl #3 */
/* @0x1ff974 .word 0xfffff618 */
/* @0x1ff978 .word 0xfffff61c */
/* @0x1ff97c andseq r4, r5, r12, ror r1 */
/* @0x1ff980 .word 0xfffff620 */
/* @0x1ff984 .word 0xfffff624 */
/* @0x1ff988 andseq r4, r5, r8, ror #2 */
/* @0x1ff98c .word 0xfffff628 */
/* @0x1ff990 .word 0xfffff62c */
/* @0x1ff994 andseq r4, r5, r4, asr r1 */
/* @0x1ff998 .word 0xfffff630 */
/* @0x1ff99c .word 0xfffff634 */
/* @0x1ff9a0 andseq r4, r5, r8, asr #2 */
/* @0x1ff9a4 .word 0xfffff638 */
/* @0x1ff9a8 .word 0xfffff63c */
/* @0x1ff9ac andseq r4, r5, r8, lsr r1 */
/* @0x1ff9b0 .word 0xfffff640 */
/* @0x1ff9b4 .word 0xfffff644 */
/* @0x1ff9b8 andseq r4, r5, r8, lsr #2 */
/* @0x1ff9bc .word 0xfffff648 */
/* @0x1ff9c0 .word 0xfffff64c */
/* @0x1ff9c4 andseq r4, r5, r12, lsl r1 */
/* @0x1ff9c8 .word 0xfffff650 */
/* @0x1ff9cc .word 0xfffff654 */
/* @0x1ff9d0 andseq r4, r5, r12, lsl #2 */
/* @0x1ff9d4 .word 0xfffff658 */
/* @0x1ff9d8 .word 0xfffff65c */
/* @0x1ff9dc andseq r4, r5, r0, lsl #2 */
/* @0x1ff9e0 .word 0xfffff660 */
/* @0x1ff9e4 ldrsheq r4, [r5], -r4 */
/* @0x1ff9e8 .word 0xfffff664 */
/* @0x1ff9ec andseq r4, r5, r4, ror #1 */
/* @0x1ff9f0 .word 0xfffff668 */
/* @0x1ff9f4 ldrsbeq r4, [r5], -r4 */
/* @0x1ff9f8 .word 0xfffff66c */
/* @0x1ff9fc .word 0xfffff670 */
/* @0x1ffa00 andseq r4, r5, r0, asr #1 */
/* @0x1ffa04 .word 0xfffff674 */
/* @0x1ffa08 .word 0xfffff678 */
/* @0x1ffa0c ldrheq r4, [r5], -r0 */
/* @0x1ffa10 .word 0xfffff67c */
/* @0x1ffa14 .word 0xfffff680 */
/* @0x1ffa18 andseq r4, r5, r0, lsr #1 */
/* @0x1ffa1c .word 0xfffff684 */
/* @0x1ffa20 .word 0xfffff688 */
/* @0x1ffa24 mulseq r5, r0, r0 */
/* @0x1ffa28 .word 0xfffff68c */
/* @0x1ffa2c .word 0xfffff690 */
/* @0x1ffa30 andseq r4, r5, r8, lsl #1 */
/* @0x1ffa34 .word 0xfffff694 */
/* @0x1ffa38 .word 0xfffff698 */
/* @0x1ffa3c andseq r4, r5, r0, lsl #1 */
/* @0x1ffa40 .word 0xfffff69c */
/* @0x1ffa44 .word 0xfffff6a0 */
/* @0x1ffa48 andseq r4, r5, r8, ror r0 */
/* @0x1ffa4c .word 0xfffff6a4 */
/* @0x1ffa50 .word 0xfffff6a8 */
/* @0x1ffa54 andseq r4, r5, r4, rrx */
/* @0x1ffa58 .word 0xfffff6ac */
/* @0x1ffa5c .word 0xfffff6b0 */
/* @0x1ffa60 andseq r4, r5, r0, asr r0 */
/* @0x1ffa64 .word 0xfffff6b4 */
/* @0x1ffa68 .word 0xfffff6b8 */
/* @0x1ffa6c andseq r4, r5, r4, asr #32 */
/* @0x1ffa70 .word 0xfffff6bc */
/* @0x1ffa74 .word 0xfffff6c0 */
/* @0x1ffa78 andseq r4, r5, r8, lsr r0 */
/* @0x1ffa7c .word 0xfffff6c4 */
/* @0x1ffa80 .word 0xfffff6c8 */
/* @0x1ffa84 andseq r4, r5, r4, lsr #32 */
/* @0x1ffa88 .word 0xfffff6cc */
/* @0x1ffa8c .word 0xfffff6d0 */
/* @0x1ffa90 andseq r4, r5, r8, lsl r0 */
/* @0x1ffa94 .word 0xfffff6d4 */
/* @0x1ffa98 andseq r4, r5, r8 */
/* @0x1ffa9c .word 0xfffff6d8 */
/* @0x1ffaa0 ldrsheq r3, [r5], -r8 */
/* @0x1ffaa4 .word 0xfffff6dc */
/* @0x1ffaa8 andseq r3, r5, r8, ror #31 */
/* @0x1ffaac .word 0xfffff6e0 */
/* @0x1ffab0 ldrsbeq r3, [r5], -r8 */
/* @0x1ffab4 .word 0xfffff6e4 */
/* @0x1ffab8 andseq r3, r5, r8, asr #31 */
/* @0x1ffabc .word 0xfffff6e8 */
/* @0x1ffac0 ldrheq r3, [r5], -r8 */
/* @0x1ffac4 .word 0xfffff6ec */
/* @0x1ffac8 andseq r3, r5, r8, lsr #31 */
/* @0x1ffacc .word 0xfffff6f0 */
/* @0x1ffad0 mulseq r5, r12, pc */
/* @0x1ffad4 .word 0xfffff6f4 */
/* @0x1ffad8 mulseq r5, r0, pc */
/* @0x1ffadc .word 0xfffff6f8 */
/* @0x1ffae0 andseq r3, r5, r12, lsl #31 */
/* @0x1ffae4 .word 0xfffff6fc */
/* @0x1ffae8 andseq r3, r5, r8, lsl #31 */
/* @0x1ffaec .word 0xfffff700 */
/* @0x1ffaf0 andseq r3, r5, r4, lsl #31 */
/* @0x1ffaf4 .word 0xfffff704 */
/* @0x1ffaf8 andseq r3, r5, r8, ror pc */
/* @0x1ffafc .word 0xfffff708 */
/* @0x1ffb00 andseq r3, r5, r12, ror #30 */
/* @0x1ffb04 .word 0xfffff70c */
/* @0x1ffb08 andseq r3, r5, r4, ror #30 */
/* @0x1ffb0c .word 0xfffff710 */
/* @0x1ffb10 andseq r3, r5, r12, asr pc */
/* @0x1ffb14 .word 0xfffff714 */
/* @0x1ffb18 andseq r3, r5, r12, asr #30 */
/* @0x1ffb1c .word 0xfffff718 */
/* @0x1ffb20 andseq r3, r5, r12, lsr pc */
/* @0x1ffb24 .word 0xfffff71c */
/* @0x1ffb28 .word 0xfffff720 */
/* @0x1ffb2c andseq r3, r5, r12, lsr #30 */

/* ── FUNC 0x1ffb30 · CreateNameFile() · size=160 · insn=40 */
/* @0x1ffb30 ldr r0, [pc, #0x80] */
/* @0x1ffb34 ldr r1, [pc, #0x80] */
/* @0x1ffb38 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ffb3c add r0, pc, r0 */
/* @0x1ffb40 add r1, pc, r1 */
/* @0x1ffb44 bl 0xb6844 <fopen@plt> */
/* @0x1ffb48 subs r6, r0, #0 */
/* @0x1ffb4c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1ffb50 ldr r7, [pc, #0x68] */
/* @0x1ffb54 ldr r7, [pc, r7] */
/* @0x1ffb58 ldr r3, [r7] */
/* @0x1ffb5c cmp r3, #0 */
/* @0x1ffb60 pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1ffb64 ldr r4, [pc, #0x58] */
/* @0x1ffb68 mov r5, #0 */
/* @0x1ffb6c ldr r8, [pc, #0x54] */
/* @0x1ffb70 ldr r9, [pc, #0x54] */
/* @0x1ffb74 ldr r4, [pc, r4] */
/* @0x1ffb78 add r8, pc, r8 */
/* @0x1ffb7c add r4, r4, #12 */
/* @0x1ffb80 add r9, pc, r9 */
/* @0x1ffb84 ldrb r3, [r4] */
/* @0x1ffb88 mov r1, r8 */
/* @0x1ffb8c ldr r2, [r4, #-0xc] */
/* @0x1ffb90 mov r0, r6 */
/* @0x1ffb94 cmp r3, #0 */
/* @0x1ffb98 add r5, r5, #1 */
/* @0x1ffb9c add r4, r4, #16 */
/* @0x1ffba0 movne r1, r9 */
/* @0x1ffba4 bl 0xb68a4 <fprintf@plt> */
/* @0x1ffba8 ldr r3, [r7] */
/* @0x1ffbac cmp r3, r5 */
/* @0x1ffbb0 bgt 0x1ffb84 <_Z14CreateNameFilev+0x54> */
/* @0x1ffbb4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1ffbb8 mulseq r5, r4, r11 */
/* @0x1ffbbc mulseq r5, r12, r11 */
/* @0x1ffbc0 andseq lr, lr, r0, ror #1 */
/* @0x1ffbc4 andseq lr, lr, r4, asr #1 */
/* @0x1ffbc8 andseq r3, r5, r8, ror #22 */
/* @0x1ffbcc andseq r5, r3, r4, lsr #2 */

/* ── FUNC 0x1ffbd0 · INITIALIZE_Variable_BuiltIn() · size=212 · insn=53 */
/* @0x1ffbd0 push {r3, r4, r5, lr} */
/* @0x1ffbd4 mov r0, #20 */
/* @0x1ffbd8 bl 0x27c524 <_Znwj> */
/* @0x1ffbdc ldr r1, [pc, #0xb4] */
/* @0x1ffbe0 mov r5, #0 */
/* @0x1ffbe4 mov r2, #128 */
/* @0x1ffbe8 mov r3, #127 */
/* @0x1ffbec add r1, pc, r1 */
/* @0x1ffbf0 mov r4, r0 */
/* @0x1ffbf4 str r2, [r0] */
/* @0x1ffbf8 str r3, [r4, #0x8] */
/* @0x1ffbfc mov r2, #70 */
/* @0x1ffc00 mov r3, #1 */
/* @0x1ffc04 mov r0, #1536 */
/* @0x1ffc08 str r5, [r4, #0x10] */
/* @0x1ffc0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ffc10 mov r2, #1536 */
/* @0x1ffc14 mov r1, r5 */
/* @0x1ffc18 str r0, [r4, #0x10] */
/* @0x1ffc1c bl 0xb65b0 <memset@plt> */
/* @0x1ffc20 ldr r2, [r4] */
/* @0x1ffc24 vldr s15, [pc, #104] */
/* @0x1ffc28 str r5, [r4, #0x4] */
/* @0x1ffc2c cmp r2, r5 */
/* @0x1ffc30 vmov s13, r2 */
/* @0x1ffc34 vcvt.f32.s32 s14, s13 */
/* @0x1ffc38 vmul.f32 s15, s14, s15 */
/* @0x1ffc3c vcvt.s32.f32 s15, s15 */
/* @0x1ffc40 vstr s15, [r4, #12] */
/* @0x1ffc44 ble 0x1ffc68 <_Z27INITIALIZE_Variable_BuiltInv+0x98> */
/* @0x1ffc48 add r2, r2, r2, lsl #1 */
/* @0x1ffc4c ldr r3, [r4, #0x10] */
/* @0x1ffc50 mov r1, r5 */
/* @0x1ffc54 add r2, r3, r2, lsl #2 */
/* @0x1ffc58 str r1, [r3, #0x8] */
/* @0x1ffc5c add r3, r3, #12 */
/* @0x1ffc60 cmp r3, r2 */
/* @0x1ffc64 bne 0x1ffc58 <_Z27INITIALIZE_Variable_BuiltInv+0x88> */
/* @0x1ffc68 ldr r3, [pc, #0x2c] */
/* @0x1ffc6c mov r1, #0 */
/* @0x1ffc70 ldr r0, [pc, #0x28] */
/* @0x1ffc74 mov r2, #8000 */
/* @0x1ffc78 ldr r3, [pc, r3] */
/* @0x1ffc7c ldr r0, [pc, r0] */
/* @0x1ffc80 str r4, [r3] */
/* @0x1ffc84 bl 0xb65b0 <memset@plt> */
/* @0x1ffc88 bl 0x1fed5c <_Z18InitLocalVariablesv> */
/* @0x1ffc8c pop {r3, r4, r5, lr} */
/* @0x1ffc90 b 0x1fd184 <_Z19InitGlobalVariablesv> */
/* @0x1ffc94 svclo #0x19999a */
/* @0x1ffc98 andseq r1, r3, r4, asr #8 */
/* @0x1ffc9c ldrheq r1, [pc], -r4 */
/* @0x1ffca0 ldrheq sp, [lr], -r12 */

/* ── FUNC 0x1ffca4 · GV_Argument(CInstance*, int, RValue*) · size=376 · insn=94 */
/* @0x1ffca4 push {r4, r5, r6, lr} */
/* @0x1ffca8 subs r5, r1, #0 */
/* @0x1ffcac mov r4, r2 */
/* @0x1ffcb0 blt 0x1ffd64 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xc0> */
/* @0x1ffcb4 ldr r3, [pc, #0x154] */
/* @0x1ffcb8 ldr r3, [pc, r3] */
/* @0x1ffcbc ldr r3, [r3] */
/* @0x1ffcc0 cmp r5, r3 */
/* @0x1ffcc4 bge 0x1ffd64 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xc0> */
/* @0x1ffcc8 ldr r3, [r4, #0xc] */
/* @0x1ffccc sub r3, r3, #1 */
/* @0x1ffcd0 bic r3, r3, #-16777216 */
/* @0x1ffcd4 bic r3, r3, #3 */
/* @0x1ffcd8 cmp r3, #0 */
/* @0x1ffcdc beq 0x1ffd9c <_Z11GV_ArgumentP9CInstanceiP6RValue+0xf8> */
/* @0x1ffce0 ldr r3, [pc, #0x12c] */
/* @0x1ffce4 mov r2, #0 */
/* @0x1ffce8 str r2, [r4] */
/* @0x1ffcec mov r1, #5 */
/* @0x1ffcf0 ldr r3, [pc, r3] */
/* @0x1ffcf4 str r1, [r4, #0xc] */
/* @0x1ffcf8 str r2, [r4, #0x8] */
/* @0x1ffcfc ldr r6, [r3] */
/* @0x1ffd00 add r3, r6, r5, lsl #4 */
/* @0x1ffd04 ldr r2, [r3, #0xc] */
/* @0x1ffd08 ldr r1, [r3, #0x8] */
/* @0x1ffd0c str r2, [r4, #0xc] */
/* @0x1ffd10 ldr r2, [r3, #0xc] */
/* @0x1ffd14 str r1, [r4, #0x8] */
/* @0x1ffd18 bic r2, r2, #-16777216 */
/* @0x1ffd1c cmp r2, #14 */
/* @0x1ffd20 addls pc, pc, r2, lsl #2 */
/* @0x1ffd24 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd28 b 0x1ffd88 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xe4> */
/* @0x1ffd2c b 0x1ffdcc <_Z11GV_ArgumentP9CInstanceiP6RValue+0x128> */
/* @0x1ffd30 b 0x1ffde4 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x140> */
/* @0x1ffd34 b 0x1ffd78 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd4> */
/* @0x1ffd38 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd3c b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd40 b 0x1ffda8 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x104> */
/* @0x1ffd44 b 0x1ffd78 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd4> */
/* @0x1ffd48 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd4c b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd50 b 0x1ffd88 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xe4> */
/* @0x1ffd54 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd58 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffd5c b 0x1ffd88 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xe4> */
/* @0x1ffd60 b 0x1ffd78 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd4> */
/* @0x1ffd64 ldr r0, [pc, #0xac] */
/* @0x1ffd68 mov r1, #1 */
/* @0x1ffd6c add r0, pc, r0 */
/* @0x1ffd70 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1ffd74 b 0x1ffcc8 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x24> */
/* @0x1ffd78 ldr r3, [r6, r5, lsl #4] */
/* @0x1ffd7c str r3, [r4] */
/* @0x1ffd80 mov r0, #1 */
/* @0x1ffd84 pop {r4, r5, r6, pc} */
/* @0x1ffd88 ldr r2, [r6, r5, lsl #4] */
/* @0x1ffd8c mov r0, #1 */
/* @0x1ffd90 ldr r3, [r3, #0x4] */
/* @0x1ffd94 stm r4, {r2, r3} */
/* @0x1ffd98 pop {r4, r5, r6, pc} */
/* @0x1ffd9c mov r0, r4 */
/* @0x1ffda0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1ffda4 b 0x1ffce0 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x3c> */
/* @0x1ffda8 ldr r3, [r6, r5, lsl #4] */
/* @0x1ffdac str r3, [r4] */
/* @0x1ffdb0 ldr r3, [r6, r5, lsl #4] */
/* @0x1ffdb4 cmp r3, #0 */
/* @0x1ffdb8 beq 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffdbc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1ffdc0 ldr r1, [r6, r5, lsl #4] */
/* @0x1ffdc4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1ffdc8 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffdcc ldr r3, [r6, r5, lsl #4] */
/* @0x1ffdd0 cmp r3, #0 */
/* @0x1ffdd4 ldrne r2, [r3, #0x4] */
/* @0x1ffdd8 addne r2, r2, #1 */
/* @0x1ffddc strne r2, [r3, #0x4] */
/* @0x1ffde0 b 0x1ffd7c <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd8> */
/* @0x1ffde4 ldr r3, [r6, r5, lsl #4] */
/* @0x1ffde8 cmp r3, #0 */
/* @0x1ffdec str r3, [r4] */
/* @0x1ffdf0 beq 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffdf4 ldr r1, [r3, #0x8] */
/* @0x1ffdf8 ldr r2, [r3] */
/* @0x1ffdfc cmp r1, #0 */
/* @0x1ffe00 streq r4, [r3, #0x8] */
/* @0x1ffe04 add r2, r2, #1 */
/* @0x1ffe08 str r2, [r3] */
/* @0x1ffe0c b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc> */
/* @0x1ffe10 andseq lr, lr, r4, asr r0 */
/* @0x1ffe14 andseq lr, lr, r0, lsr #32 */
/* @0x1ffe18 andseq r3, r5, r12, ror r9 */

/* ── FUNC 0x1ffe1c · GV_Argument0(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1ffe1c push {r3, r4, r5, lr} */
/* @0x1ffe20 mov r4, r2 */
/* @0x1ffe24 ldr r3, [r2, #0xc] */
/* @0x1ffe28 mov r5, r1 */
/* @0x1ffe2c sub r3, r3, #1 */
/* @0x1ffe30 bic r3, r3, #-16777216 */
/* @0x1ffe34 bic r3, r3, #3 */
/* @0x1ffe38 cmp r3, #0 */
/* @0x1ffe3c beq 0x1ffe8c <_Z12GV_Argument0P9CInstanceiP6RValue+0x70> */
/* @0x1ffe40 ldr r3, [pc, #0x50] */
/* @0x1ffe44 mov r0, #0 */
/* @0x1ffe48 str r0, [r4] */
/* @0x1ffe4c mov r12, #5 */
/* @0x1ffe50 ldr r3, [pc, r3] */
/* @0x1ffe54 str r0, [r4, #0x8] */
/* @0x1ffe58 str r12, [r4, #0xc] */
/* @0x1ffe5c ldr r3, [r3] */
/* @0x1ffe60 cmp r3, r0 */
/* @0x1ffe64 strle r0, [r4, #0x4] */
/* @0x1ffe68 ble 0x1ffe84 <_Z12GV_Argument0P9CInstanceiP6RValue+0x68> */
/* @0x1ffe6c ldr r3, [pc, #0x28] */
/* @0x1ffe70 mov r0, r4 */
/* @0x1ffe74 mov r2, r5 */
/* @0x1ffe78 ldr r3, [pc, r3] */
/* @0x1ffe7c ldr r1, [r3] */
/* @0x1ffe80 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1ffe84 mov r0, #1 */
/* @0x1ffe88 pop {r3, r4, r5, pc} */
/* @0x1ffe8c mov r0, r2 */
/* @0x1ffe90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1ffe94 b 0x1ffe40 <_Z12GV_Argument0P9CInstanceiP6RValue+0x24> */
/* @0x1ffe98 ldrheq sp, [lr], -r12 */
/* @0x1ffe9c mulseq lr, r8, lr */

/* ── FUNC 0x1ffea0 · GV_Argument1(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x1ffea0 push {r3, r4, r5, lr} */
/* @0x1ffea4 mov r4, r2 */
/* @0x1ffea8 ldr r3, [r2, #0xc] */
/* @0x1ffeac mov r5, r1 */
/* @0x1ffeb0 sub r3, r3, #1 */
/* @0x1ffeb4 bic r3, r3, #-16777216 */
/* @0x1ffeb8 bic r3, r3, #3 */
/* @0x1ffebc cmp r3, #0 */
/* @0x1ffec0 beq 0x1fff14 <_Z12GV_Argument1P9CInstanceiP6RValue+0x74> */
/* @0x1ffec4 ldr r3, [pc, #0x54] */
/* @0x1ffec8 mov r0, #0 */
/* @0x1ffecc str r0, [r4] */
/* @0x1ffed0 mov r12, #5 */
/* @0x1ffed4 ldr r3, [pc, r3] */
/* @0x1ffed8 str r0, [r4, #0x8] */
/* @0x1ffedc str r12, [r4, #0xc] */
/* @0x1ffee0 ldr r3, [r3] */
/* @0x1ffee4 cmp r3, #1 */
/* @0x1ffee8 strle r0, [r4, #0x4] */
/* @0x1ffeec ble 0x1fff0c <_Z12GV_Argument1P9CInstanceiP6RValue+0x6c> */
/* @0x1ffef0 ldr r3, [pc, #0x2c] */
/* @0x1ffef4 mov r0, r4 */
/* @0x1ffef8 mov r2, r5 */
/* @0x1ffefc ldr r3, [pc, r3] */
/* @0x1fff00 ldr r1, [r3] */
/* @0x1fff04 add r1, r1, #16 */
/* @0x1fff08 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1fff0c mov r0, #1 */
/* @0x1fff10 pop {r3, r4, r5, pc} */
/* @0x1fff14 mov r0, r2 */
/* @0x1fff18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1fff1c b 0x1ffec4 <_Z12GV_Argument1P9CInstanceiP6RValue+0x24> */
/* @0x1fff20 andseq sp, lr, r8, lsr lr */
/* @0x1fff24 andseq sp, lr, r4, lsl lr */

/* ── FUNC 0x1fff28 · GV_Argument2(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x1fff28 push {r3, r4, r5, lr} */
/* @0x1fff2c mov r4, r2 */
/* @0x1fff30 ldr r3, [r2, #0xc] */
/* @0x1fff34 mov r5, r1 */
/* @0x1fff38 sub r3, r3, #1 */
/* @0x1fff3c bic r3, r3, #-16777216 */
/* @0x1fff40 bic r3, r3, #3 */
/* @0x1fff44 cmp r3, #0 */
/* @0x1fff48 beq 0x1fff9c <_Z12GV_Argument2P9CInstanceiP6RValue+0x74> */
/* @0x1fff4c ldr r0, [pc, #0x54] */
/* @0x1fff50 mov r3, #0 */
/* @0x1fff54 str r3, [r4] */
/* @0x1fff58 mov r12, #5 */
/* @0x1fff5c ldr r0, [pc, r0] */
/* @0x1fff60 str r3, [r4, #0x8] */
/* @0x1fff64 str r12, [r4, #0xc] */
/* @0x1fff68 ldr r0, [r0] */
/* @0x1fff6c cmp r0, #2 */
/* @0x1fff70 strle r3, [r4, #0x4] */
/* @0x1fff74 ble 0x1fff94 <_Z12GV_Argument2P9CInstanceiP6RValue+0x6c> */
/* @0x1fff78 ldr r3, [pc, #0x2c] */
/* @0x1fff7c mov r0, r4 */
/* @0x1fff80 mov r2, r5 */
/* @0x1fff84 ldr r3, [pc, r3] */
/* @0x1fff88 ldr r1, [r3] */
/* @0x1fff8c add r1, r1, #32 */
/* @0x1fff90 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1fff94 mov r0, #1 */
/* @0x1fff98 pop {r3, r4, r5, pc} */
/* @0x1fff9c mov r0, r2 */
/* @0x1fffa0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1fffa4 b 0x1fff4c <_Z12GV_Argument2P9CInstanceiP6RValue+0x24> */
/* @0x1fffa8 ldrheq sp, [lr], -r0 */
/* @0x1fffac andseq sp, lr, r12, lsl #27 */

/* ── FUNC 0x1fffb0 · GV_Argument3(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x1fffb0 push {r3, r4, r5, lr} */
/* @0x1fffb4 mov r4, r2 */
/* @0x1fffb8 ldr r3, [r2, #0xc] */
/* @0x1fffbc mov r5, r1 */
/* @0x1fffc0 sub r3, r3, #1 */
/* @0x1fffc4 bic r3, r3, #-16777216 */
/* @0x1fffc8 bic r3, r3, #3 */
/* @0x1fffcc cmp r3, #0 */
/* @0x1fffd0 beq 0x200024 <_Z12GV_Argument3P9CInstanceiP6RValue+0x74> */
/* @0x1fffd4 ldr r0, [pc, #0x54] */
/* @0x1fffd8 mov r3, #0 */
/* @0x1fffdc str r3, [r4] */
/* @0x1fffe0 mov r12, #5 */
/* @0x1fffe4 ldr r0, [pc, r0] */
/* @0x1fffe8 str r3, [r4, #0x8] */
/* @0x1fffec str r12, [r4, #0xc] */
/* @0x1ffff0 ldr r0, [r0] */
/* @0x1ffff4 cmp r0, #3 */
/* @0x1ffff8 strle r3, [r4, #0x4] */
/* @0x1ffffc ble 0x20001c <_Z12GV_Argument3P9CInstanceiP6RValue+0x6c> */
/* @0x200000 ldr r3, [pc, #0x2c] */
/* @0x200004 mov r0, r4 */
/* @0x200008 mov r2, r5 */
/* @0x20000c ldr r3, [pc, r3] */
/* @0x200010 ldr r1, [r3] */
/* @0x200014 add r1, r1, #48 */
/* @0x200018 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20001c mov r0, #1 */
/* @0x200020 pop {r3, r4, r5, pc} */
/* @0x200024 mov r0, r2 */
/* @0x200028 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20002c b 0x1fffd4 <_Z12GV_Argument3P9CInstanceiP6RValue+0x24> */
/* @0x200030 andseq sp, lr, r8, lsr #26 */
/* @0x200034 andseq sp, lr, r4, lsl #26 */

/* ── FUNC 0x200038 · GV_Argument4(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200038 push {r3, r4, r5, lr} */
/* @0x20003c mov r4, r2 */
/* @0x200040 ldr r3, [r2, #0xc] */
/* @0x200044 mov r5, r1 */
/* @0x200048 sub r3, r3, #1 */
/* @0x20004c bic r3, r3, #-16777216 */
/* @0x200050 bic r3, r3, #3 */
/* @0x200054 cmp r3, #0 */
/* @0x200058 beq 0x2000ac <_Z12GV_Argument4P9CInstanceiP6RValue+0x74> */
/* @0x20005c ldr r0, [pc, #0x54] */
/* @0x200060 mov r3, #0 */
/* @0x200064 str r3, [r4] */
/* @0x200068 mov r12, #5 */
/* @0x20006c ldr r0, [pc, r0] */
/* @0x200070 str r3, [r4, #0x8] */
/* @0x200074 str r12, [r4, #0xc] */
/* @0x200078 ldr r0, [r0] */
/* @0x20007c cmp r0, #4 */
/* @0x200080 strle r3, [r4, #0x4] */
/* @0x200084 ble 0x2000a4 <_Z12GV_Argument4P9CInstanceiP6RValue+0x6c> */
/* @0x200088 ldr r3, [pc, #0x2c] */
/* @0x20008c mov r0, r4 */
/* @0x200090 mov r2, r5 */
/* @0x200094 ldr r3, [pc, r3] */
/* @0x200098 ldr r1, [r3] */
/* @0x20009c add r1, r1, #64 */
/* @0x2000a0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x2000a4 mov r0, #1 */
/* @0x2000a8 pop {r3, r4, r5, pc} */
/* @0x2000ac mov r0, r2 */
/* @0x2000b0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2000b4 b 0x20005c <_Z12GV_Argument4P9CInstanceiP6RValue+0x24> */
/* @0x2000b8 andseq sp, lr, r0, lsr #25 */
/* @0x2000bc andseq sp, lr, r12, ror r12 */

/* ── FUNC 0x2000c0 · GV_Argument5(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x2000c0 push {r3, r4, r5, lr} */
/* @0x2000c4 mov r4, r2 */
/* @0x2000c8 ldr r3, [r2, #0xc] */
/* @0x2000cc mov r5, r1 */
/* @0x2000d0 sub r3, r3, #1 */
/* @0x2000d4 bic r3, r3, #-16777216 */
/* @0x2000d8 bic r3, r3, #3 */
/* @0x2000dc cmp r3, #0 */
/* @0x2000e0 beq 0x200134 <_Z12GV_Argument5P9CInstanceiP6RValue+0x74> */
/* @0x2000e4 ldr r0, [pc, #0x54] */
/* @0x2000e8 mov r3, #0 */
/* @0x2000ec str r3, [r4] */
/* @0x2000f0 mov r12, #5 */
/* @0x2000f4 ldr r0, [pc, r0] */
/* @0x2000f8 str r3, [r4, #0x8] */
/* @0x2000fc str r12, [r4, #0xc] */
/* @0x200100 ldr r0, [r0] */
/* @0x200104 cmp r0, r12 */
/* @0x200108 strle r3, [r4, #0x4] */
/* @0x20010c ble 0x20012c <_Z12GV_Argument5P9CInstanceiP6RValue+0x6c> */
/* @0x200110 ldr r3, [pc, #0x2c] */
/* @0x200114 mov r0, r4 */
/* @0x200118 mov r2, r5 */
/* @0x20011c ldr r3, [pc, r3] */
/* @0x200120 ldr r1, [r3] */
/* @0x200124 add r1, r1, #80 */
/* @0x200128 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20012c mov r0, #1 */
/* @0x200130 pop {r3, r4, r5, pc} */
/* @0x200134 mov r0, r2 */
/* @0x200138 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20013c b 0x2000e4 <_Z12GV_Argument5P9CInstanceiP6RValue+0x24> */
/* @0x200140 andseq sp, lr, r8, lsl r12 */
/* @0x200144 ldrsheq sp, [lr], -r4 */

/* ── FUNC 0x200148 · GV_Argument6(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200148 push {r3, r4, r5, lr} */
/* @0x20014c mov r4, r2 */
/* @0x200150 ldr r3, [r2, #0xc] */
/* @0x200154 mov r5, r1 */
/* @0x200158 sub r3, r3, #1 */
/* @0x20015c bic r3, r3, #-16777216 */
/* @0x200160 bic r3, r3, #3 */
/* @0x200164 cmp r3, #0 */
/* @0x200168 beq 0x2001bc <_Z12GV_Argument6P9CInstanceiP6RValue+0x74> */
/* @0x20016c ldr r0, [pc, #0x54] */
/* @0x200170 mov r3, #0 */
/* @0x200174 str r3, [r4] */
/* @0x200178 mov r12, #5 */
/* @0x20017c ldr r0, [pc, r0] */
/* @0x200180 str r3, [r4, #0x8] */
/* @0x200184 str r12, [r4, #0xc] */
/* @0x200188 ldr r0, [r0] */
/* @0x20018c cmp r0, #6 */
/* @0x200190 strle r3, [r4, #0x4] */
/* @0x200194 ble 0x2001b4 <_Z12GV_Argument6P9CInstanceiP6RValue+0x6c> */
/* @0x200198 ldr r3, [pc, #0x2c] */
/* @0x20019c mov r0, r4 */
/* @0x2001a0 mov r2, r5 */
/* @0x2001a4 ldr r3, [pc, r3] */
/* @0x2001a8 ldr r1, [r3] */
/* @0x2001ac add r1, r1, #96 */
/* @0x2001b0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x2001b4 mov r0, #1 */
/* @0x2001b8 pop {r3, r4, r5, pc} */
/* @0x2001bc mov r0, r2 */
/* @0x2001c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2001c4 b 0x20016c <_Z12GV_Argument6P9CInstanceiP6RValue+0x24> */
/* @0x2001c8 mulseq lr, r0, r11 */
/* @0x2001cc andseq sp, lr, r12, ror #22 */

/* ── FUNC 0x2001d0 · GV_Argument7(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x2001d0 push {r3, r4, r5, lr} */
/* @0x2001d4 mov r4, r2 */
/* @0x2001d8 ldr r3, [r2, #0xc] */
/* @0x2001dc mov r5, r1 */
/* @0x2001e0 sub r3, r3, #1 */
/* @0x2001e4 bic r3, r3, #-16777216 */
/* @0x2001e8 bic r3, r3, #3 */
/* @0x2001ec cmp r3, #0 */
/* @0x2001f0 beq 0x200244 <_Z12GV_Argument7P9CInstanceiP6RValue+0x74> */
/* @0x2001f4 ldr r0, [pc, #0x54] */
/* @0x2001f8 mov r3, #0 */
/* @0x2001fc str r3, [r4] */
/* @0x200200 mov r12, #5 */
/* @0x200204 ldr r0, [pc, r0] */
/* @0x200208 str r3, [r4, #0x8] */
/* @0x20020c str r12, [r4, #0xc] */
/* @0x200210 ldr r0, [r0] */
/* @0x200214 cmp r0, #7 */
/* @0x200218 strle r3, [r4, #0x4] */
/* @0x20021c ble 0x20023c <_Z12GV_Argument7P9CInstanceiP6RValue+0x6c> */
/* @0x200220 ldr r3, [pc, #0x2c] */
/* @0x200224 mov r0, r4 */
/* @0x200228 mov r2, r5 */
/* @0x20022c ldr r3, [pc, r3] */
/* @0x200230 ldr r1, [r3] */
/* @0x200234 add r1, r1, #112 */
/* @0x200238 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20023c mov r0, #1 */
/* @0x200240 pop {r3, r4, r5, pc} */
/* @0x200244 mov r0, r2 */
/* @0x200248 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20024c b 0x2001f4 <_Z12GV_Argument7P9CInstanceiP6RValue+0x24> */
/* @0x200250 andseq sp, lr, r8, lsl #22 */
/* @0x200254 andseq sp, lr, r4, ror #21 */

/* ── FUNC 0x200258 · GV_Argument8(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200258 push {r3, r4, r5, lr} */
/* @0x20025c mov r4, r2 */
/* @0x200260 ldr r3, [r2, #0xc] */
/* @0x200264 mov r5, r1 */
/* @0x200268 sub r3, r3, #1 */
/* @0x20026c bic r3, r3, #-16777216 */
/* @0x200270 bic r3, r3, #3 */
/* @0x200274 cmp r3, #0 */
/* @0x200278 beq 0x2002cc <_Z12GV_Argument8P9CInstanceiP6RValue+0x74> */
/* @0x20027c ldr r0, [pc, #0x54] */
/* @0x200280 mov r3, #0 */
/* @0x200284 str r3, [r4] */
/* @0x200288 mov r12, #5 */
/* @0x20028c ldr r0, [pc, r0] */
/* @0x200290 str r3, [r4, #0x8] */
/* @0x200294 str r12, [r4, #0xc] */
/* @0x200298 ldr r0, [r0] */
/* @0x20029c cmp r0, #8 */
/* @0x2002a0 strle r3, [r4, #0x4] */
/* @0x2002a4 ble 0x2002c4 <_Z12GV_Argument8P9CInstanceiP6RValue+0x6c> */
/* @0x2002a8 ldr r3, [pc, #0x2c] */
/* @0x2002ac mov r0, r4 */
/* @0x2002b0 mov r2, r5 */
/* @0x2002b4 ldr r3, [pc, r3] */
/* @0x2002b8 ldr r1, [r3] */
/* @0x2002bc add r1, r1, #128 */
/* @0x2002c0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x2002c4 mov r0, #1 */
/* @0x2002c8 pop {r3, r4, r5, pc} */
/* @0x2002cc mov r0, r2 */
/* @0x2002d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2002d4 b 0x20027c <_Z12GV_Argument8P9CInstanceiP6RValue+0x24> */
/* @0x2002d8 andseq sp, lr, r0, lsl #21 */
/* @0x2002dc andseq sp, lr, r12, asr r10 */

/* ── FUNC 0x2002e0 · GV_Argument9(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x2002e0 push {r3, r4, r5, lr} */
/* @0x2002e4 mov r4, r2 */
/* @0x2002e8 ldr r3, [r2, #0xc] */
/* @0x2002ec mov r5, r1 */
/* @0x2002f0 sub r3, r3, #1 */
/* @0x2002f4 bic r3, r3, #-16777216 */
/* @0x2002f8 bic r3, r3, #3 */
/* @0x2002fc cmp r3, #0 */
/* @0x200300 beq 0x200354 <_Z12GV_Argument9P9CInstanceiP6RValue+0x74> */
/* @0x200304 ldr r0, [pc, #0x54] */
/* @0x200308 mov r3, #0 */
/* @0x20030c str r3, [r4] */
/* @0x200310 mov r12, #5 */
/* @0x200314 ldr r0, [pc, r0] */
/* @0x200318 str r3, [r4, #0x8] */
/* @0x20031c str r12, [r4, #0xc] */
/* @0x200320 ldr r0, [r0] */
/* @0x200324 cmp r0, #9 */
/* @0x200328 strle r3, [r4, #0x4] */
/* @0x20032c ble 0x20034c <_Z12GV_Argument9P9CInstanceiP6RValue+0x6c> */
/* @0x200330 ldr r3, [pc, #0x2c] */
/* @0x200334 mov r0, r4 */
/* @0x200338 mov r2, r5 */
/* @0x20033c ldr r3, [pc, r3] */
/* @0x200340 ldr r1, [r3] */
/* @0x200344 add r1, r1, #144 */
/* @0x200348 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20034c mov r0, #1 */
/* @0x200350 pop {r3, r4, r5, pc} */
/* @0x200354 mov r0, r2 */
/* @0x200358 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20035c b 0x200304 <_Z12GV_Argument9P9CInstanceiP6RValue+0x24> */
/* @0x200360 ldrsheq sp, [lr], -r8 */
/* @0x200364 ldrsbeq sp, [lr], -r4 */

/* ── FUNC 0x200368 · GV_Argument10(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200368 push {r3, r4, r5, lr} */
/* @0x20036c mov r4, r2 */
/* @0x200370 ldr r3, [r2, #0xc] */
/* @0x200374 mov r5, r1 */
/* @0x200378 sub r3, r3, #1 */
/* @0x20037c bic r3, r3, #-16777216 */
/* @0x200380 bic r3, r3, #3 */
/* @0x200384 cmp r3, #0 */
/* @0x200388 beq 0x2003dc <_Z13GV_Argument10P9CInstanceiP6RValue+0x74> */
/* @0x20038c ldr r0, [pc, #0x54] */
/* @0x200390 mov r3, #0 */
/* @0x200394 str r3, [r4] */
/* @0x200398 mov r12, #5 */
/* @0x20039c ldr r0, [pc, r0] */
/* @0x2003a0 str r3, [r4, #0x8] */
/* @0x2003a4 str r12, [r4, #0xc] */
/* @0x2003a8 ldr r0, [r0] */
/* @0x2003ac cmp r0, #10 */
/* @0x2003b0 strle r3, [r4, #0x4] */
/* @0x2003b4 ble 0x2003d4 <_Z13GV_Argument10P9CInstanceiP6RValue+0x6c> */
/* @0x2003b8 ldr r3, [pc, #0x2c] */
/* @0x2003bc mov r0, r4 */
/* @0x2003c0 mov r2, r5 */
/* @0x2003c4 ldr r3, [pc, r3] */
/* @0x2003c8 ldr r1, [r3] */
/* @0x2003cc add r1, r1, #160 */
/* @0x2003d0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x2003d4 mov r0, #1 */
/* @0x2003d8 pop {r3, r4, r5, pc} */
/* @0x2003dc mov r0, r2 */
/* @0x2003e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2003e4 b 0x20038c <_Z13GV_Argument10P9CInstanceiP6RValue+0x24> */
/* @0x2003e8 andseq sp, lr, r0, ror r9 */
/* @0x2003ec andseq sp, lr, r12, asr #18 */

/* ── FUNC 0x2003f0 · GV_Argument11(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x2003f0 push {r3, r4, r5, lr} */
/* @0x2003f4 mov r4, r2 */
/* @0x2003f8 ldr r3, [r2, #0xc] */
/* @0x2003fc mov r5, r1 */
/* @0x200400 sub r3, r3, #1 */
/* @0x200404 bic r3, r3, #-16777216 */
/* @0x200408 bic r3, r3, #3 */
/* @0x20040c cmp r3, #0 */
/* @0x200410 beq 0x200464 <_Z13GV_Argument11P9CInstanceiP6RValue+0x74> */
/* @0x200414 ldr r0, [pc, #0x54] */
/* @0x200418 mov r3, #0 */
/* @0x20041c str r3, [r4] */
/* @0x200420 mov r12, #5 */
/* @0x200424 ldr r0, [pc, r0] */
/* @0x200428 str r3, [r4, #0x8] */
/* @0x20042c str r12, [r4, #0xc] */
/* @0x200430 ldr r0, [r0] */
/* @0x200434 cmp r0, #11 */
/* @0x200438 strle r3, [r4, #0x4] */
/* @0x20043c ble 0x20045c <_Z13GV_Argument11P9CInstanceiP6RValue+0x6c> */
/* @0x200440 ldr r3, [pc, #0x2c] */
/* @0x200444 mov r0, r4 */
/* @0x200448 mov r2, r5 */
/* @0x20044c ldr r3, [pc, r3] */
/* @0x200450 ldr r1, [r3] */
/* @0x200454 add r1, r1, #176 */
/* @0x200458 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20045c mov r0, #1 */
/* @0x200460 pop {r3, r4, r5, pc} */
/* @0x200464 mov r0, r2 */
/* @0x200468 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20046c b 0x200414 <_Z13GV_Argument11P9CInstanceiP6RValue+0x24> */
/* @0x200470 andseq sp, lr, r8, ror #17 */
/* @0x200474 andseq sp, lr, r4, asr #17 */

/* ── FUNC 0x200478 · GV_Argument12(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200478 push {r3, r4, r5, lr} */
/* @0x20047c mov r4, r2 */
/* @0x200480 ldr r3, [r2, #0xc] */
/* @0x200484 mov r5, r1 */
/* @0x200488 sub r3, r3, #1 */
/* @0x20048c bic r3, r3, #-16777216 */
/* @0x200490 bic r3, r3, #3 */
/* @0x200494 cmp r3, #0 */
/* @0x200498 beq 0x2004ec <_Z13GV_Argument12P9CInstanceiP6RValue+0x74> */
/* @0x20049c ldr r0, [pc, #0x54] */
/* @0x2004a0 mov r3, #0 */
/* @0x2004a4 str r3, [r4] */
/* @0x2004a8 mov r12, #5 */
/* @0x2004ac ldr r0, [pc, r0] */
/* @0x2004b0 str r3, [r4, #0x8] */
/* @0x2004b4 str r12, [r4, #0xc] */
/* @0x2004b8 ldr r0, [r0] */
/* @0x2004bc cmp r0, #12 */
/* @0x2004c0 strle r3, [r4, #0x4] */
/* @0x2004c4 ble 0x2004e4 <_Z13GV_Argument12P9CInstanceiP6RValue+0x6c> */
/* @0x2004c8 ldr r3, [pc, #0x2c] */
/* @0x2004cc mov r0, r4 */
/* @0x2004d0 mov r2, r5 */
/* @0x2004d4 ldr r3, [pc, r3] */
/* @0x2004d8 ldr r1, [r3] */
/* @0x2004dc add r1, r1, #192 */
/* @0x2004e0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x2004e4 mov r0, #1 */
/* @0x2004e8 pop {r3, r4, r5, pc} */
/* @0x2004ec mov r0, r2 */
/* @0x2004f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2004f4 b 0x20049c <_Z13GV_Argument12P9CInstanceiP6RValue+0x24> */
/* @0x2004f8 andseq sp, lr, r0, ror #16 */
/* @0x2004fc andseq sp, lr, r12, lsr r8 */

/* ── FUNC 0x200500 · GV_Argument13(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200500 push {r3, r4, r5, lr} */
/* @0x200504 mov r4, r2 */
/* @0x200508 ldr r3, [r2, #0xc] */
/* @0x20050c mov r5, r1 */
/* @0x200510 sub r3, r3, #1 */
/* @0x200514 bic r3, r3, #-16777216 */
/* @0x200518 bic r3, r3, #3 */
/* @0x20051c cmp r3, #0 */
/* @0x200520 beq 0x200574 <_Z13GV_Argument13P9CInstanceiP6RValue+0x74> */
/* @0x200524 ldr r0, [pc, #0x54] */
/* @0x200528 mov r3, #0 */
/* @0x20052c str r3, [r4] */
/* @0x200530 mov r12, #5 */
/* @0x200534 ldr r0, [pc, r0] */
/* @0x200538 str r3, [r4, #0x8] */
/* @0x20053c str r12, [r4, #0xc] */
/* @0x200540 ldr r0, [r0] */
/* @0x200544 cmp r0, #13 */
/* @0x200548 strle r3, [r4, #0x4] */
/* @0x20054c ble 0x20056c <_Z13GV_Argument13P9CInstanceiP6RValue+0x6c> */
/* @0x200550 ldr r3, [pc, #0x2c] */
/* @0x200554 mov r0, r4 */
/* @0x200558 mov r2, r5 */
/* @0x20055c ldr r3, [pc, r3] */
/* @0x200560 ldr r1, [r3] */
/* @0x200564 add r1, r1, #208 */
/* @0x200568 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20056c mov r0, #1 */
/* @0x200570 pop {r3, r4, r5, pc} */
/* @0x200574 mov r0, r2 */
/* @0x200578 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20057c b 0x200524 <_Z13GV_Argument13P9CInstanceiP6RValue+0x24> */
/* @0x200580 ldrsbeq sp, [lr], -r8 */
/* @0x200584 ldrheq sp, [lr], -r4 */

/* ── FUNC 0x200588 · GV_Argument14(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200588 push {r3, r4, r5, lr} */
/* @0x20058c mov r4, r2 */
/* @0x200590 ldr r3, [r2, #0xc] */
/* @0x200594 mov r5, r1 */
/* @0x200598 sub r3, r3, #1 */
/* @0x20059c bic r3, r3, #-16777216 */
/* @0x2005a0 bic r3, r3, #3 */
/* @0x2005a4 cmp r3, #0 */
/* @0x2005a8 beq 0x2005fc <_Z13GV_Argument14P9CInstanceiP6RValue+0x74> */
/* @0x2005ac ldr r0, [pc, #0x54] */
/* @0x2005b0 mov r3, #0 */
/* @0x2005b4 str r3, [r4] */
/* @0x2005b8 mov r12, #5 */
/* @0x2005bc ldr r0, [pc, r0] */
/* @0x2005c0 str r3, [r4, #0x8] */
/* @0x2005c4 str r12, [r4, #0xc] */
/* @0x2005c8 ldr r0, [r0] */
/* @0x2005cc cmp r0, #14 */
/* @0x2005d0 strle r3, [r4, #0x4] */
/* @0x2005d4 ble 0x2005f4 <_Z13GV_Argument14P9CInstanceiP6RValue+0x6c> */
/* @0x2005d8 ldr r3, [pc, #0x2c] */
/* @0x2005dc mov r0, r4 */
/* @0x2005e0 mov r2, r5 */
/* @0x2005e4 ldr r3, [pc, r3] */
/* @0x2005e8 ldr r1, [r3] */
/* @0x2005ec add r1, r1, #224 */
/* @0x2005f0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x2005f4 mov r0, #1 */
/* @0x2005f8 pop {r3, r4, r5, pc} */
/* @0x2005fc mov r0, r2 */
/* @0x200600 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x200604 b 0x2005ac <_Z13GV_Argument14P9CInstanceiP6RValue+0x24> */
/* @0x200608 andseq sp, lr, r0, asr r7 */
/* @0x20060c andseq sp, lr, r12, lsr #14 */

/* ── FUNC 0x200610 · GV_Argument15(CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x200610 push {r3, r4, r5, lr} */
/* @0x200614 mov r4, r2 */
/* @0x200618 ldr r3, [r2, #0xc] */
/* @0x20061c mov r5, r1 */
/* @0x200620 sub r3, r3, #1 */
/* @0x200624 bic r3, r3, #-16777216 */
/* @0x200628 bic r3, r3, #3 */
/* @0x20062c cmp r3, #0 */
/* @0x200630 beq 0x200684 <_Z13GV_Argument15P9CInstanceiP6RValue+0x74> */
/* @0x200634 ldr r0, [pc, #0x54] */
/* @0x200638 mov r3, #0 */
/* @0x20063c str r3, [r4] */
/* @0x200640 mov r12, #5 */
/* @0x200644 ldr r0, [pc, r0] */
/* @0x200648 str r3, [r4, #0x8] */
/* @0x20064c str r12, [r4, #0xc] */
/* @0x200650 ldr r0, [r0] */
/* @0x200654 cmp r0, #15 */
/* @0x200658 strle r3, [r4, #0x4] */
/* @0x20065c ble 0x20067c <_Z13GV_Argument15P9CInstanceiP6RValue+0x6c> */
/* @0x200660 ldr r3, [pc, #0x2c] */
/* @0x200664 mov r0, r4 */
/* @0x200668 mov r2, r5 */
/* @0x20066c ldr r3, [pc, r3] */
/* @0x200670 ldr r1, [r3] */
/* @0x200674 add r1, r1, #240 */
/* @0x200678 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x20067c mov r0, #1 */
/* @0x200680 pop {r3, r4, r5, pc} */
/* @0x200684 mov r0, r2 */
/* @0x200688 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20068c b 0x200634 <_Z13GV_Argument15P9CInstanceiP6RValue+0x24> */
/* @0x200690 andseq sp, lr, r8, asr #13 */
/* @0x200694 andseq sp, lr, r4, lsr #13 */

/* ── FUNC 0x200698 · GV_PointerNull(CInstance*, int, RValue*) · size=504 · insn=126 */
/* @0x200698 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20069c mov r5, r2 */
/* @0x2006a0 ldr r2, [r2, #0xc] */
/* @0x2006a4 sub r3, r2, #1 */
/* @0x2006a8 bic r3, r3, #-16777216 */
/* @0x2006ac bics r4, r3, #3 */
/* @0x2006b0 beq 0x2006d0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x38> */
/* @0x2006b4 mov r3, #0 */
/* @0x2006b8 mov r2, #3 */
/* @0x2006bc str r3, [r5, #0x8] */
/* @0x2006c0 mov r0, #1 */
/* @0x2006c4 str r3, [r5] */
/* @0x2006c8 str r2, [r5, #0xc] */
/* @0x2006cc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2006d0 bic r2, r2, #-16777216 */
/* @0x2006d4 cmp r2, #2 */
/* @0x2006d8 beq 0x200748 <_Z14GV_PointerNullP9CInstanceiP6RValue+0xb0> */
/* @0x2006dc cmp r2, #3 */
/* @0x2006e0 beq 0x200720 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x88> */
/* @0x2006e4 cmp r2, #1 */
/* @0x2006e8 bne 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x2006ec ldr r4, [r5] */
/* @0x2006f0 cmp r4, #0 */
/* @0x2006f4 beq 0x200714 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x7c> */
/* @0x2006f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2006fc ldr r6, [r4, #0x4] */
/* @0x200700 sub r6, r6, #1 */
/* @0x200704 str r6, [r4, #0x4] */
/* @0x200708 cmp r6, #0 */
/* @0x20070c beq 0x200780 <_Z14GV_PointerNullP9CInstanceiP6RValue+0xe8> */
/* @0x200710 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200714 mov r3, #0 */
/* @0x200718 str r3, [r5] */
/* @0x20071c b 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x200720 ldr r3, [r5, #0x8] */
/* @0x200724 tst r3, #8 */
/* @0x200728 beq 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x20072c ldr r0, [r5] */
/* @0x200730 cmp r0, #0 */
/* @0x200734 beq 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x200738 ldr r3, [r0] */
/* @0x20073c ldr r3, [r3, #0x4] */
/* @0x200740 blx r3 */
/* @0x200744 b 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x200748 ldr r8, [r5] */
/* @0x20074c cmp r8, #0 */
/* @0x200750 beq 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x200754 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200758 ldr r3, [r8] */
/* @0x20075c ldr r2, [r8, #0x8] */
/* @0x200760 sub r3, r3, #1 */
/* @0x200764 str r3, [r8] */
/* @0x200768 cmp r5, r2 */
/* @0x20076c streq r4, [r8, #0x8] */
/* @0x200770 cmp r3, #0 */
/* @0x200774 ble 0x2007b8 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x120> */
/* @0x200778 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20077c b 0x2006b4 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1c> */
/* @0x200780 ldr r0, [r4] */
/* @0x200784 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200788 str r6, [r4] */
/* @0x20078c str r6, [r4, #0x8] */
/* @0x200790 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200794 ldr r6, [r4, #0x4] */
/* @0x200798 sub r6, r6, #1 */
/* @0x20079c str r6, [r4, #0x4] */
/* @0x2007a0 cmp r6, #0 */
/* @0x2007a4 beq 0x20086c <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1d4> */
/* @0x2007a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2007ac mov r0, r4 */
/* @0x2007b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2007b4 b 0x200710 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x78> */
/* @0x2007b8 ldr r3, [r8, #0x10] */
/* @0x2007bc cmp r3, #0 */
/* @0x2007c0 movgt r7, #0 */
/* @0x2007c4 movgt r11, #5 */
/* @0x2007c8 movgt r6, r7 */
/* @0x2007cc ble 0x200844 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1ac> */
/* @0x2007d0 ldr r3, [r8, #0x4] */
/* @0x2007d4 add r9, r3, r7, lsl #3 */
/* @0x2007d8 ldr r10, [r3, r7, lsl #3] */
/* @0x2007dc ldr r4, [r9, #0x4] */
/* @0x2007e0 add r10, r4, r10, lsl #4 */
/* @0x2007e4 cmp r4, r10 */
/* @0x2007e8 blo 0x200804 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x16c> */
/* @0x2007ec b 0x200864 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x1cc> */
/* @0x2007f0 str r6, [r4, #0x8] */
/* @0x2007f4 str r11, [r4, #0xc] */
/* @0x2007f8 str r6, [r4], #16 */
/* @0x2007fc cmp r10, r4 */
/* @0x200800 bls 0x200828 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x190> */
/* @0x200804 ldr r3, [r4, #0xc] */
/* @0x200808 sub r3, r3, #1 */
/* @0x20080c bic r3, r3, #-16777216 */
/* @0x200810 bic r3, r3, #3 */
/* @0x200814 cmp r3, #0 */
/* @0x200818 bne 0x2007f0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x158> */
/* @0x20081c mov r0, r4 */
/* @0x200820 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x200824 b 0x2007f0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x158> */
/* @0x200828 ldr r0, [r9, #0x4] */
/* @0x20082c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200830 ldr r3, [r8, #0x10] */
/* @0x200834 add r7, r7, #1 */
/* @0x200838 str r6, [r9, #0x4] */
/* @0x20083c cmp r7, r3 */
/* @0x200840 blt 0x2007d0 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x138> */
/* @0x200844 ldr r0, [r8, #0x4] */
/* @0x200848 mov r4, #0 */
/* @0x20084c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200850 str r4, [r8, #0x4] */
/* @0x200854 mov r0, r8 */
/* @0x200858 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20085c str r4, [r5] */
/* @0x200860 b 0x200778 <_Z14GV_PointerNullP9CInstanceiP6RValue+0xe0> */
/* @0x200864 mov r0, r4 */
/* @0x200868 b 0x20082c <_Z14GV_PointerNullP9CInstanceiP6RValue+0x194> */
/* @0x20086c ldr r0, [r4] */
/* @0x200870 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200874 mov r0, r4 */
/* @0x200878 str r6, [r4] */
/* @0x20087c str r6, [r4, #0x8] */
/* @0x200880 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x200884 mov r0, r4 */
/* @0x200888 bl 0x27d1d0 <_ZdlPv> */
/* @0x20088c b 0x2007a8 <_Z14GV_PointerNullP9CInstanceiP6RValue+0x110> */

/* ── FUNC 0x200890 · GV_Undefined(CInstance*, int, RValue*) · size=508 · insn=127 */
/* @0x200890 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x200894 mov r5, r2 */
/* @0x200898 ldr r2, [r2, #0xc] */
/* @0x20089c sub r3, r2, #1 */
/* @0x2008a0 bic r3, r3, #-16777216 */
/* @0x2008a4 bics r4, r3, #3 */
/* @0x2008a8 beq 0x2008cc <_Z12GV_UndefinedP9CInstanceiP6RValue+0x3c> */
/* @0x2008ac mov r3, #0 */
/* @0x2008b0 mov r2, #5 */
/* @0x2008b4 str r3, [r5, #0x8] */
/* @0x2008b8 mov r0, #1 */
/* @0x2008bc str r3, [r5] */
/* @0x2008c0 str r3, [r5, #0x4] */
/* @0x2008c4 str r2, [r5, #0xc] */
/* @0x2008c8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2008cc bic r2, r2, #-16777216 */
/* @0x2008d0 cmp r2, #2 */
/* @0x2008d4 beq 0x200944 <_Z12GV_UndefinedP9CInstanceiP6RValue+0xb4> */
/* @0x2008d8 cmp r2, #3 */
/* @0x2008dc beq 0x20091c <_Z12GV_UndefinedP9CInstanceiP6RValue+0x8c> */
/* @0x2008e0 cmp r2, #1 */
/* @0x2008e4 bne 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x2008e8 ldr r4, [r5] */
/* @0x2008ec cmp r4, #0 */
/* @0x2008f0 beq 0x200910 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x80> */
/* @0x2008f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2008f8 ldr r6, [r4, #0x4] */
/* @0x2008fc sub r6, r6, #1 */
/* @0x200900 str r6, [r4, #0x4] */
/* @0x200904 cmp r6, #0 */
/* @0x200908 beq 0x20097c <_Z12GV_UndefinedP9CInstanceiP6RValue+0xec> */
/* @0x20090c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200910 mov r3, #0 */
/* @0x200914 str r3, [r5] */
/* @0x200918 b 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x20091c ldr r3, [r5, #0x8] */
/* @0x200920 tst r3, #8 */
/* @0x200924 beq 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x200928 ldr r0, [r5] */
/* @0x20092c cmp r0, #0 */
/* @0x200930 beq 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x200934 ldr r3, [r0] */
/* @0x200938 ldr r3, [r3, #0x4] */
/* @0x20093c blx r3 */
/* @0x200940 b 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x200944 ldr r8, [r5] */
/* @0x200948 cmp r8, #0 */
/* @0x20094c beq 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x200950 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200954 ldr r3, [r8] */
/* @0x200958 ldr r2, [r8, #0x8] */
/* @0x20095c sub r3, r3, #1 */
/* @0x200960 str r3, [r8] */
/* @0x200964 cmp r5, r2 */
/* @0x200968 streq r4, [r8, #0x8] */
/* @0x20096c cmp r3, #0 */
/* @0x200970 ble 0x2009b4 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x124> */
/* @0x200974 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200978 b 0x2008ac <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1c> */
/* @0x20097c ldr r0, [r4] */
/* @0x200980 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200984 str r6, [r4] */
/* @0x200988 str r6, [r4, #0x8] */
/* @0x20098c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200990 ldr r6, [r4, #0x4] */
/* @0x200994 sub r6, r6, #1 */
/* @0x200998 str r6, [r4, #0x4] */
/* @0x20099c cmp r6, #0 */
/* @0x2009a0 beq 0x200a68 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1d8> */
/* @0x2009a4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2009a8 mov r0, r4 */
/* @0x2009ac bl 0x27d1d0 <_ZdlPv> */
/* @0x2009b0 b 0x20090c <_Z12GV_UndefinedP9CInstanceiP6RValue+0x7c> */
/* @0x2009b4 ldr r3, [r8, #0x10] */
/* @0x2009b8 cmp r3, #0 */
/* @0x2009bc movgt r7, #0 */
/* @0x2009c0 movgt r11, #5 */
/* @0x2009c4 movgt r6, r7 */
/* @0x2009c8 ble 0x200a40 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1b0> */
/* @0x2009cc ldr r3, [r8, #0x4] */
/* @0x2009d0 add r9, r3, r7, lsl #3 */
/* @0x2009d4 ldr r10, [r3, r7, lsl #3] */
/* @0x2009d8 ldr r4, [r9, #0x4] */
/* @0x2009dc add r10, r4, r10, lsl #4 */
/* @0x2009e0 cmp r4, r10 */
/* @0x2009e4 blo 0x200a00 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x170> */
/* @0x2009e8 b 0x200a60 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x1d0> */
/* @0x2009ec str r6, [r4, #0x8] */
/* @0x2009f0 str r11, [r4, #0xc] */
/* @0x2009f4 str r6, [r4], #16 */
/* @0x2009f8 cmp r10, r4 */
/* @0x2009fc bls 0x200a24 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x194> */
/* @0x200a00 ldr r3, [r4, #0xc] */
/* @0x200a04 sub r3, r3, #1 */
/* @0x200a08 bic r3, r3, #-16777216 */
/* @0x200a0c bic r3, r3, #3 */
/* @0x200a10 cmp r3, #0 */
/* @0x200a14 bne 0x2009ec <_Z12GV_UndefinedP9CInstanceiP6RValue+0x15c> */
/* @0x200a18 mov r0, r4 */
/* @0x200a1c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x200a20 b 0x2009ec <_Z12GV_UndefinedP9CInstanceiP6RValue+0x15c> */
/* @0x200a24 ldr r0, [r9, #0x4] */
/* @0x200a28 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200a2c ldr r3, [r8, #0x10] */
/* @0x200a30 add r7, r7, #1 */
/* @0x200a34 str r6, [r9, #0x4] */
/* @0x200a38 cmp r7, r3 */
/* @0x200a3c blt 0x2009cc <_Z12GV_UndefinedP9CInstanceiP6RValue+0x13c> */
/* @0x200a40 ldr r0, [r8, #0x4] */
/* @0x200a44 mov r4, #0 */
/* @0x200a48 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200a4c str r4, [r8, #0x4] */
/* @0x200a50 mov r0, r8 */
/* @0x200a54 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200a58 str r4, [r5] */
/* @0x200a5c b 0x200974 <_Z12GV_UndefinedP9CInstanceiP6RValue+0xe4> */
/* @0x200a60 mov r0, r4 */
/* @0x200a64 b 0x200a28 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x198> */
/* @0x200a68 ldr r0, [r4] */
/* @0x200a6c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200a70 mov r0, r4 */
/* @0x200a74 str r6, [r4] */
/* @0x200a78 str r6, [r4, #0x8] */
/* @0x200a7c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x200a80 mov r0, r4 */
/* @0x200a84 bl 0x27d1d0 <_ZdlPv> */
/* @0x200a88 b 0x2009a4 <_Z12GV_UndefinedP9CInstanceiP6RValue+0x114> */

/* ── FUNC 0x200a8c · GV_PointerInvalid(CInstance*, int, RValue*) · size=508 · insn=127 */
/* @0x200a8c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x200a90 mov r5, r2 */
/* @0x200a94 ldr r2, [r2, #0xc] */
/* @0x200a98 sub r3, r2, #1 */
/* @0x200a9c bic r3, r3, #-16777216 */
/* @0x200aa0 bics r4, r3, #3 */
/* @0x200aa4 beq 0x200ac8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x3c> */
/* @0x200aa8 mov r3, #0 */
/* @0x200aac mov r2, #3 */
/* @0x200ab0 str r3, [r5, #0x8] */
/* @0x200ab4 mov r0, #1 */
/* @0x200ab8 mvn r3, #0 */
/* @0x200abc str r2, [r5, #0xc] */
/* @0x200ac0 str r3, [r5] */
/* @0x200ac4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x200ac8 bic r2, r2, #-16777216 */
/* @0x200acc cmp r2, #2 */
/* @0x200ad0 beq 0x200b40 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xb4> */
/* @0x200ad4 cmp r2, #3 */
/* @0x200ad8 beq 0x200b18 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x8c> */
/* @0x200adc cmp r2, #1 */
/* @0x200ae0 bne 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200ae4 ldr r4, [r5] */
/* @0x200ae8 cmp r4, #0 */
/* @0x200aec beq 0x200b0c <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x80> */
/* @0x200af0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200af4 ldr r6, [r4, #0x4] */
/* @0x200af8 sub r6, r6, #1 */
/* @0x200afc str r6, [r4, #0x4] */
/* @0x200b00 cmp r6, #0 */
/* @0x200b04 beq 0x200b78 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xec> */
/* @0x200b08 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200b0c mov r3, #0 */
/* @0x200b10 str r3, [r5] */
/* @0x200b14 b 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200b18 ldr r3, [r5, #0x8] */
/* @0x200b1c tst r3, #8 */
/* @0x200b20 beq 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200b24 ldr r0, [r5] */
/* @0x200b28 cmp r0, #0 */
/* @0x200b2c beq 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200b30 ldr r3, [r0] */
/* @0x200b34 ldr r3, [r3, #0x4] */
/* @0x200b38 blx r3 */
/* @0x200b3c b 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200b40 ldr r8, [r5] */
/* @0x200b44 cmp r8, #0 */
/* @0x200b48 beq 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200b4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200b50 ldr r3, [r8] */
/* @0x200b54 ldr r2, [r8, #0x8] */
/* @0x200b58 sub r3, r3, #1 */
/* @0x200b5c str r3, [r8] */
/* @0x200b60 cmp r5, r2 */
/* @0x200b64 streq r4, [r8, #0x8] */
/* @0x200b68 cmp r3, #0 */
/* @0x200b6c ble 0x200bb0 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x124> */
/* @0x200b70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200b74 b 0x200aa8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1c> */
/* @0x200b78 ldr r0, [r4] */
/* @0x200b7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200b80 str r6, [r4] */
/* @0x200b84 str r6, [r4, #0x8] */
/* @0x200b88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200b8c ldr r6, [r4, #0x4] */
/* @0x200b90 sub r6, r6, #1 */
/* @0x200b94 str r6, [r4, #0x4] */
/* @0x200b98 cmp r6, #0 */
/* @0x200b9c beq 0x200c64 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1d8> */
/* @0x200ba0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200ba4 mov r0, r4 */
/* @0x200ba8 bl 0x27d1d0 <_ZdlPv> */
/* @0x200bac b 0x200b08 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x7c> */
/* @0x200bb0 ldr r3, [r8, #0x10] */
/* @0x200bb4 cmp r3, #0 */
/* @0x200bb8 movgt r7, #0 */
/* @0x200bbc movgt r11, #5 */
/* @0x200bc0 movgt r6, r7 */
/* @0x200bc4 ble 0x200c3c <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1b0> */
/* @0x200bc8 ldr r3, [r8, #0x4] */
/* @0x200bcc add r9, r3, r7, lsl #3 */
/* @0x200bd0 ldr r10, [r3, r7, lsl #3] */
/* @0x200bd4 ldr r4, [r9, #0x4] */
/* @0x200bd8 add r10, r4, r10, lsl #4 */
/* @0x200bdc cmp r4, r10 */
/* @0x200be0 blo 0x200bfc <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x170> */
/* @0x200be4 b 0x200c5c <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x1d0> */
/* @0x200be8 str r6, [r4, #0x8] */
/* @0x200bec str r11, [r4, #0xc] */
/* @0x200bf0 str r6, [r4], #16 */
/* @0x200bf4 cmp r10, r4 */
/* @0x200bf8 bls 0x200c20 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x194> */
/* @0x200bfc ldr r3, [r4, #0xc] */
/* @0x200c00 sub r3, r3, #1 */
/* @0x200c04 bic r3, r3, #-16777216 */
/* @0x200c08 bic r3, r3, #3 */
/* @0x200c0c cmp r3, #0 */
/* @0x200c10 bne 0x200be8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x15c> */
/* @0x200c14 mov r0, r4 */
/* @0x200c18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x200c1c b 0x200be8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x15c> */
/* @0x200c20 ldr r0, [r9, #0x4] */
/* @0x200c24 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200c28 ldr r3, [r8, #0x10] */
/* @0x200c2c add r7, r7, #1 */
/* @0x200c30 str r6, [r9, #0x4] */
/* @0x200c34 cmp r7, r3 */
/* @0x200c38 blt 0x200bc8 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x13c> */
/* @0x200c3c ldr r0, [r8, #0x4] */
/* @0x200c40 mov r4, #0 */
/* @0x200c44 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200c48 str r4, [r8, #0x4] */
/* @0x200c4c mov r0, r8 */
/* @0x200c50 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200c54 str r4, [r5] */
/* @0x200c58 b 0x200b70 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xe4> */
/* @0x200c5c mov r0, r4 */
/* @0x200c60 b 0x200c24 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x198> */
/* @0x200c64 ldr r0, [r4] */
/* @0x200c68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200c6c mov r0, r4 */
/* @0x200c70 str r6, [r4] */
/* @0x200c74 str r6, [r4, #0x8] */
/* @0x200c78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x200c7c mov r0, r4 */
/* @0x200c80 bl 0x27d1d0 <_ZdlPv> */
/* @0x200c84 b 0x200ba0 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0x114> */

/* ── FUNC 0x200c88 · GV_ArgumentCount(CInstance*, int, RValue*) · size=540 · insn=135 */
/* @0x200c88 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x200c8c mov r6, r2 */
/* @0x200c90 ldr r2, [r2, #0xc] */
/* @0x200c94 sub r3, r2, #1 */
/* @0x200c98 bic r3, r3, #-16777216 */
/* @0x200c9c bics r4, r3, #3 */
/* @0x200ca0 beq 0x200ce0 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x58> */
/* @0x200ca4 ldr r3, [pc, #0x1f4] */
/* @0x200ca8 mov r2, #0 */
/* @0x200cac str r2, [r6] */
/* @0x200cb0 mov r0, #1 */
/* @0x200cb4 ldr r3, [pc, r3] */
/* @0x200cb8 str r2, [r6, #0x8] */
/* @0x200cbc str r2, [r6, #0xc] */
/* @0x200cc0 ldr r4, [r3] */
/* @0x200cc4 vmov s15, r4 */
/* @0x200cc8 vcvt.f64.s32 d7, s15 */
/* @0x200ccc vmov r4, r5, d7 */
/* @0x200cd0 vmov r2, s14 */
/* @0x200cd4 mov r3, r5 */
/* @0x200cd8 stm r6, {r2, r3} */
/* @0x200cdc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x200ce0 bic r2, r2, #-16777216 */
/* @0x200ce4 cmp r2, #2 */
/* @0x200ce8 beq 0x200d58 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0xd0> */
/* @0x200cec cmp r2, #3 */
/* @0x200cf0 beq 0x200d30 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0xa8> */
/* @0x200cf4 cmp r2, #1 */
/* @0x200cf8 bne 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200cfc ldr r4, [r6] */
/* @0x200d00 cmp r4, #0 */
/* @0x200d04 beq 0x200d24 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x9c> */
/* @0x200d08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200d0c ldr r5, [r4, #0x4] */
/* @0x200d10 sub r5, r5, #1 */
/* @0x200d14 str r5, [r4, #0x4] */
/* @0x200d18 cmp r5, #0 */
/* @0x200d1c beq 0x200d90 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x108> */
/* @0x200d20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200d24 mov r3, #0 */
/* @0x200d28 str r3, [r6] */
/* @0x200d2c b 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200d30 ldr r3, [r6, #0x8] */
/* @0x200d34 tst r3, #8 */
/* @0x200d38 beq 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200d3c ldr r0, [r6] */
/* @0x200d40 cmp r0, #0 */
/* @0x200d44 beq 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200d48 ldr r3, [r0] */
/* @0x200d4c ldr r3, [r3, #0x4] */
/* @0x200d50 blx r3 */
/* @0x200d54 b 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200d58 ldr r8, [r6] */
/* @0x200d5c cmp r8, #0 */
/* @0x200d60 beq 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200d64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200d68 ldr r3, [r8] */
/* @0x200d6c ldr r2, [r8, #0x8] */
/* @0x200d70 sub r3, r3, #1 */
/* @0x200d74 str r3, [r8] */
/* @0x200d78 cmp r6, r2 */
/* @0x200d7c streq r4, [r8, #0x8] */
/* @0x200d80 cmp r3, #0 */
/* @0x200d84 ble 0x200dc8 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x140> */
/* @0x200d88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200d8c b 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c> */
/* @0x200d90 ldr r0, [r4] */
/* @0x200d94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200d98 str r5, [r4] */
/* @0x200d9c str r5, [r4, #0x8] */
/* @0x200da0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200da4 ldr r5, [r4, #0x4] */
/* @0x200da8 sub r5, r5, #1 */
/* @0x200dac str r5, [r4, #0x4] */
/* @0x200db0 cmp r5, #0 */
/* @0x200db4 beq 0x200e7c <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1f4> */
/* @0x200db8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200dbc mov r0, r4 */
/* @0x200dc0 bl 0x27d1d0 <_ZdlPv> */
/* @0x200dc4 b 0x200d20 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x98> */
/* @0x200dc8 ldr r3, [r8, #0x10] */
/* @0x200dcc cmp r3, #0 */
/* @0x200dd0 movgt r7, #0 */
/* @0x200dd4 movgt r11, #5 */
/* @0x200dd8 movgt r5, r7 */
/* @0x200ddc ble 0x200e54 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1cc> */
/* @0x200de0 ldr r3, [r8, #0x4] */
/* @0x200de4 add r9, r3, r7, lsl #3 */
/* @0x200de8 ldr r10, [r3, r7, lsl #3] */
/* @0x200dec ldr r4, [r9, #0x4] */
/* @0x200df0 add r10, r4, r10, lsl #4 */
/* @0x200df4 cmp r4, r10 */
/* @0x200df8 blo 0x200e14 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x18c> */
/* @0x200dfc b 0x200e74 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1ec> */
/* @0x200e00 str r5, [r4, #0x8] */
/* @0x200e04 str r11, [r4, #0xc] */
/* @0x200e08 str r5, [r4], #16 */
/* @0x200e0c cmp r10, r4 */
/* @0x200e10 bls 0x200e38 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1b0> */
/* @0x200e14 ldr r3, [r4, #0xc] */
/* @0x200e18 sub r3, r3, #1 */
/* @0x200e1c bic r3, r3, #-16777216 */
/* @0x200e20 bic r3, r3, #3 */
/* @0x200e24 cmp r3, #0 */
/* @0x200e28 bne 0x200e00 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x178> */
/* @0x200e2c mov r0, r4 */
/* @0x200e30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x200e34 b 0x200e00 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x178> */
/* @0x200e38 ldr r0, [r9, #0x4] */
/* @0x200e3c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200e40 ldr r3, [r8, #0x10] */
/* @0x200e44 add r7, r7, #1 */
/* @0x200e48 str r5, [r9, #0x4] */
/* @0x200e4c cmp r7, r3 */
/* @0x200e50 blt 0x200de0 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x158> */
/* @0x200e54 ldr r0, [r8, #0x4] */
/* @0x200e58 mov r4, #0 */
/* @0x200e5c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200e60 str r4, [r8, #0x4] */
/* @0x200e64 mov r0, r8 */
/* @0x200e68 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x200e6c str r4, [r6] */
/* @0x200e70 b 0x200d88 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x100> */
/* @0x200e74 mov r0, r4 */
/* @0x200e78 b 0x200e3c <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1b4> */
/* @0x200e7c ldr r0, [r4] */
/* @0x200e80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200e84 mov r0, r4 */
/* @0x200e88 str r5, [r4] */
/* @0x200e8c str r5, [r4, #0x8] */
/* @0x200e90 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x200e94 mov r0, r4 */
/* @0x200e98 bl 0x27d1d0 <_ZdlPv> */
/* @0x200e9c b 0x200db8 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x130> */
/* @0x200ea0 andseq sp, lr, r8, asr r0 */

/* ── FUNC 0x200ea4 · GV_DebugMode(CInstance*, int, RValue*) · size=548 · insn=137 */
/* @0x200ea4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x200ea8 mov r5, r2 */
/* @0x200eac ldr r2, [r2, #0xc] */
/* @0x200eb0 sub r3, r2, #1 */
/* @0x200eb4 bic r3, r3, #-16777216 */
/* @0x200eb8 bics r4, r3, #3 */
/* @0x200ebc beq 0x200f04 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x60> */
/* @0x200ec0 ldr r2, [pc, #0x1fc] */
/* @0x200ec4 mov r3, #0 */
/* @0x200ec8 str r3, [r5] */
/* @0x200ecc mov r0, #1 */
/* @0x200ed0 ldr r2, [pc, r2] */
/* @0x200ed4 str r3, [r5, #0x8] */
/* @0x200ed8 str r3, [r5, #0xc] */
/* @0x200edc ldr r2, [r2] */
/* @0x200ee0 ldr r2, [r2] */
/* @0x200ee4 ands r2, r2, #1 */
/* @0x200ee8 moveq r3, r2 */
/* @0x200eec movne r2, r3 */
/* @0x200ef0 moveq r2, #0 */
/* @0x200ef4 str r3, [r5] */
/* @0x200ef8 movteq r2, #0x3ff0 */
/* @0x200efc str r2, [r5, #0x4] */
/* @0x200f00 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x200f04 bic r2, r2, #-16777216 */
/* @0x200f08 cmp r2, #2 */
/* @0x200f0c beq 0x200f7c <_Z12GV_DebugModeP9CInstanceiP6RValue+0xd8> */
/* @0x200f10 cmp r2, #3 */
/* @0x200f14 beq 0x200f54 <_Z12GV_DebugModeP9CInstanceiP6RValue+0xb0> */
/* @0x200f18 cmp r2, #1 */
/* @0x200f1c bne 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200f20 ldr r4, [r5] */
/* @0x200f24 cmp r4, #0 */
/* @0x200f28 beq 0x200f48 <_Z12GV_DebugModeP9CInstanceiP6RValue+0xa4> */
/* @0x200f2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200f30 ldr r6, [r4, #0x4] */
/* @0x200f34 sub r6, r6, #1 */
/* @0x200f38 str r6, [r4, #0x4] */
/* @0x200f3c cmp r6, #0 */
/* @0x200f40 beq 0x200fb4 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x110> */
/* @0x200f44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200f48 mov r3, #0 */
/* @0x200f4c str r3, [r5] */
/* @0x200f50 b 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200f54 ldr r3, [r5, #0x8] */
/* @0x200f58 tst r3, #8 */
/* @0x200f5c beq 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200f60 ldr r0, [r5] */
/* @0x200f64 cmp r0, #0 */
/* @0x200f68 beq 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200f6c ldr r3, [r0] */
/* @0x200f70 ldr r3, [r3, #0x4] */
/* @0x200f74 blx r3 */
/* @0x200f78 b 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200f7c ldr r8, [r5] */
/* @0x200f80 cmp r8, #0 */
/* @0x200f84 beq 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200f8c ldr r3, [r8] */
/* @0x200f90 ldr r2, [r8, #0x8] */
/* @0x200f94 sub r3, r3, #1 */
/* @0x200f98 str r3, [r8] */
/* @0x200f9c cmp r5, r2 */
/* @0x200fa0 streq r4, [r8, #0x8] */
/* @0x200fa4 cmp r3, #0 */
/* @0x200fa8 ble 0x200fec <_Z12GV_DebugModeP9CInstanceiP6RValue+0x148> */
/* @0x200fac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200fb0 b 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c> */
/* @0x200fb4 ldr r0, [r4] */
/* @0x200fb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x200fbc str r6, [r4] */
/* @0x200fc0 str r6, [r4, #0x8] */
/* @0x200fc4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x200fc8 ldr r6, [r4, #0x4] */
/* @0x200fcc sub r6, r6, #1 */
/* @0x200fd0 str r6, [r4, #0x4] */
/* @0x200fd4 cmp r6, #0 */
/* @0x200fd8 beq 0x2010a0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1fc> */
/* @0x200fdc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x200fe0 mov r0, r4 */
/* @0x200fe4 bl 0x27d1d0 <_ZdlPv> */
/* @0x200fe8 b 0x200f44 <_Z12GV_DebugModeP9CInstanceiP6RValue+0xa0> */
/* @0x200fec ldr r3, [r8, #0x10] */
/* @0x200ff0 cmp r3, #0 */
/* @0x200ff4 movgt r7, #0 */
/* @0x200ff8 movgt r11, #5 */
/* @0x200ffc movgt r6, r7 */
/* @0x201000 ble 0x201078 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1d4> */
/* @0x201004 ldr r3, [r8, #0x4] */
/* @0x201008 add r9, r3, r7, lsl #3 */
/* @0x20100c ldr r10, [r3, r7, lsl #3] */
/* @0x201010 ldr r4, [r9, #0x4] */
/* @0x201014 add r10, r4, r10, lsl #4 */
/* @0x201018 cmp r4, r10 */
/* @0x20101c blo 0x201038 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x194> */
/* @0x201020 b 0x201098 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1f4> */
/* @0x201024 str r6, [r4, #0x8] */
/* @0x201028 str r11, [r4, #0xc] */
/* @0x20102c str r6, [r4], #16 */
/* @0x201030 cmp r10, r4 */
/* @0x201034 bls 0x20105c <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1b8> */
/* @0x201038 ldr r3, [r4, #0xc] */
/* @0x20103c sub r3, r3, #1 */
/* @0x201040 bic r3, r3, #-16777216 */
/* @0x201044 bic r3, r3, #3 */
/* @0x201048 cmp r3, #0 */
/* @0x20104c bne 0x201024 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x180> */
/* @0x201050 mov r0, r4 */
/* @0x201054 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x201058 b 0x201024 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x180> */
/* @0x20105c ldr r0, [r9, #0x4] */
/* @0x201060 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x201064 ldr r3, [r8, #0x10] */
/* @0x201068 add r7, r7, #1 */
/* @0x20106c str r6, [r9, #0x4] */
/* @0x201070 cmp r7, r3 */
/* @0x201074 blt 0x201004 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x160> */
/* @0x201078 ldr r0, [r8, #0x4] */
/* @0x20107c mov r4, #0 */
/* @0x201080 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x201084 str r4, [r8, #0x4] */
/* @0x201088 mov r0, r8 */
/* @0x20108c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x201090 str r4, [r5] */
/* @0x201094 b 0x200fac <_Z12GV_DebugModeP9CInstanceiP6RValue+0x108> */
/* @0x201098 mov r0, r4 */
/* @0x20109c b 0x201060 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1bc> */
/* @0x2010a0 ldr r0, [r4] */
/* @0x2010a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2010a8 mov r0, r4 */
/* @0x2010ac str r6, [r4] */
/* @0x2010b0 str r6, [r4, #0x8] */
/* @0x2010b4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2010b8 mov r0, r4 */
/* @0x2010bc bl 0x27d1d0 <_ZdlPv> */
/* @0x2010c0 b 0x200fdc <_Z12GV_DebugModeP9CInstanceiP6RValue+0x138> */
/* @0x2010c4 andseq pc, lr, r12, lsl r5 */

/* ── FUNC 0x2010c8 · MyZAlloc(void*, unsigned int, unsigned int) · size=28 · insn=7 */
/* @0x2010c8 mul r0, r2, r1 */
/* @0x2010cc ldr r1, [pc, #0xc] */
/* @0x2010d0 mov r3, #1 */
/* @0x2010d4 mov r2, #796 */
/* @0x2010d8 add r1, pc, r1 */
/* @0x2010dc b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2010e0 andseq r2, r5, r0, asr r6 */

/* ── FUNC 0x2010e4 · MyZFree(void*, void*) · size=8 · insn=2 */
/* @0x2010e4 mov r0, r1 */
/* @0x2010e8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
