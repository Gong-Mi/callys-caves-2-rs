/* libyoyo.so 覆盖卡组 0058
 * 函数 0x129bfc..0x12ae64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x129bfc · F_PartEmitterCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x129bfc push {r4, lr} */
/* @0x129c00 mov r3, #0 */
/* @0x129c04 mov r1, r3 */
/* @0x129c08 str r3, [r0, #0xc] */
/* @0x129c0c mov r4, r0 */
/* @0x129c10 ldr r0, [sp, #0x8] */
/* @0x129c14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129c18 bl 0x1a39b4 <_Z29ParticleSystem_Emitter_Createi> */
/* @0x129c1c vmov s15, r0 */
/* @0x129c20 vcvt.f64.s32 d7, s15 */
/* @0x129c24 vmov r0, r1, d7 */
/* @0x129c28 vmov r2, s14 */
/* @0x129c2c mov r3, r1 */
/* @0x129c30 stm r4, {r2, r3} */
/* @0x129c34 pop {r4, pc} */

/* ── FUNC 0x129c38 · F_PartEmitterDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129c38 push {r3, r4, r5, lr} */
/* @0x129c3c mov r1, #0 */
/* @0x129c40 ldr r4, [sp, #0x10] */
/* @0x129c44 mov r0, r4 */
/* @0x129c48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129c4c mov r1, #1 */
/* @0x129c50 mov r5, r0 */
/* @0x129c54 mov r0, r4 */
/* @0x129c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129c5c mov r1, r0 */
/* @0x129c60 mov r0, r5 */
/* @0x129c64 pop {r3, r4, r5, lr} */
/* @0x129c68 b 0x1a38ac <_Z30ParticleSystem_Emitter_Destroyii> */

/* ── FUNC 0x129c6c · F_PartEmitterDestroyAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x129c6c push {r3, lr} */
/* @0x129c70 mov r1, #0 */
/* @0x129c74 ldr r0, [sp, #0x8] */
/* @0x129c78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129c7c pop {r3, lr} */
/* @0x129c80 b 0x1a37b8 <_Z33ParticleSystem_Emitter_DestroyAlli> */

/* ── FUNC 0x129c84 · F_PartEmitterExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x129c84 push {r4, r5, r6, lr} */
/* @0x129c88 mov r1, #0 */
/* @0x129c8c ldr r5, [sp, #0x10] */
/* @0x129c90 mov r4, r0 */
/* @0x129c94 str r1, [r0, #0xc] */
/* @0x129c98 mov r0, r5 */
/* @0x129c9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129ca0 mov r1, #1 */
/* @0x129ca4 mov r6, r0 */
/* @0x129ca8 mov r0, r5 */
/* @0x129cac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129cb0 mov r1, r0 */
/* @0x129cb4 mov r0, r6 */
/* @0x129cb8 bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii> */
/* @0x129cbc vmov s15, r0 */
/* @0x129cc0 vcvt.f64.u32 d7, s15 */
/* @0x129cc4 vmov r0, r1, d7 */
/* @0x129cc8 vmov r2, s14 */
/* @0x129ccc mov r3, r1 */
/* @0x129cd0 stm r4, {r2, r3} */
/* @0x129cd4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x129cd8 · F_PartEmitterClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x129cd8 push {r3, r4, r5, lr} */
/* @0x129cdc mov r1, #0 */
/* @0x129ce0 ldr r4, [sp, #0x10] */
/* @0x129ce4 mov r0, r4 */
/* @0x129ce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129cec mov r1, #1 */
/* @0x129cf0 mov r5, r0 */
/* @0x129cf4 mov r0, r4 */
/* @0x129cf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129cfc mov r1, r0 */
/* @0x129d00 mov r0, r5 */
/* @0x129d04 pop {r3, r4, r5, lr} */
/* @0x129d08 b 0x1a38ec <_Z28ParticleSystem_Emitter_Clearii> */

/* ── FUNC 0x129d0c · F_PartEmitterRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x129d0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x129d10 sub sp, sp, #20 */
/* @0x129d14 mov r1, #0 */
/* @0x129d18 ldr r4, [sp, #0x38] */
/* @0x129d1c mov r0, r4 */
/* @0x129d20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129d24 mov r1, #1 */
/* @0x129d28 mov r5, r0 */
/* @0x129d2c mov r0, r4 */
/* @0x129d30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129d34 mov r1, #2 */
/* @0x129d38 mov r8, r0 */
/* @0x129d3c mov r0, r4 */
/* @0x129d40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129d44 mov r1, #3 */
/* @0x129d48 mov r7, r0 */
/* @0x129d4c mov r0, r4 */
/* @0x129d50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129d54 mov r1, #4 */
/* @0x129d58 mov r6, r0 */
/* @0x129d5c mov r0, r4 */
/* @0x129d60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129d64 mov r1, #5 */
/* @0x129d68 mov r11, r0 */
/* @0x129d6c mov r0, r4 */
/* @0x129d70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129d74 mov r1, #6 */
/* @0x129d78 mov r10, r0 */
/* @0x129d7c mov r0, r4 */
/* @0x129d80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129d84 mov r1, #7 */
/* @0x129d88 mov r9, r0 */
/* @0x129d8c mov r0, r4 */
/* @0x129d90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129d94 str r11, [sp] */
/* @0x129d98 str r10, [sp, #0x4] */
/* @0x129d9c mov r1, r8 */
/* @0x129da0 str r9, [sp, #0x8] */
/* @0x129da4 mov r2, r7 */
/* @0x129da8 mov r3, r6 */
/* @0x129dac str r0, [sp, #0xc] */
/* @0x129db0 mov r0, r5 */
/* @0x129db4 bl 0x1a394c <_Z29ParticleSystem_Emitter_Regioniiffffii> */
/* @0x129db8 add sp, sp, #20 */
/* @0x129dbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x129dc0 · F_PartEmitterBurst(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x129dc0 push {r4, r5, r6, r7, r8, lr} */
/* @0x129dc4 mov r1, #0 */
/* @0x129dc8 ldr r4, [sp, #0x18] */
/* @0x129dcc mov r0, r4 */
/* @0x129dd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129dd4 mov r1, #1 */
/* @0x129dd8 mov r7, r0 */
/* @0x129ddc mov r0, r4 */
/* @0x129de0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129de4 mov r1, #2 */
/* @0x129de8 mov r6, r0 */
/* @0x129dec mov r0, r4 */
/* @0x129df0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129df4 mov r1, #3 */
/* @0x129df8 mov r5, r0 */
/* @0x129dfc mov r0, r4 */
/* @0x129e00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129e04 mov r1, r6 */
/* @0x129e08 mov r2, r5 */
/* @0x129e0c mov r3, r0 */
/* @0x129e10 mov r0, r7 */
/* @0x129e14 pop {r4, r5, r6, r7, r8, lr} */
/* @0x129e18 b 0x1a3cf0 <_Z28ParticleSystem_Emitter_Burstiiii> */

/* ── FUNC 0x129e1c · F_PartEmitterStream(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x129e1c push {r4, r5, r6, r7, r8, lr} */
/* @0x129e20 mov r1, #0 */
/* @0x129e24 ldr r4, [sp, #0x18] */
/* @0x129e28 mov r0, r4 */
/* @0x129e2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129e30 mov r1, #1 */
/* @0x129e34 mov r7, r0 */
/* @0x129e38 mov r0, r4 */
/* @0x129e3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129e40 mov r1, #2 */
/* @0x129e44 mov r6, r0 */
/* @0x129e48 mov r0, r4 */
/* @0x129e4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129e50 mov r1, #3 */
/* @0x129e54 mov r5, r0 */
/* @0x129e58 mov r0, r4 */
/* @0x129e5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129e60 mov r1, r6 */
/* @0x129e64 mov r2, r5 */
/* @0x129e68 mov r3, r0 */
/* @0x129e6c mov r0, r7 */
/* @0x129e70 pop {r4, r5, r6, r7, r8, lr} */
/* @0x129e74 b 0x1a3ad4 <_Z29ParticleSystem_Emitter_Streamiiii> */

/* ── FUNC 0x129e78 · F_EffectCreateBelow(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x129e78 push {r4, r5, r6, r7, r8, lr} */
/* @0x129e7c sub sp, sp, #8 */
/* @0x129e80 mov r1, #0 */
/* @0x129e84 ldr r4, [sp, #0x20] */
/* @0x129e88 mov r0, r4 */
/* @0x129e8c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129e90 mov r1, #1 */
/* @0x129e94 mov r7, r0 */
/* @0x129e98 mov r0, r4 */
/* @0x129e9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129ea0 mov r1, #2 */
/* @0x129ea4 mov r6, r0 */
/* @0x129ea8 mov r0, r4 */
/* @0x129eac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129eb0 mov r1, #3 */
/* @0x129eb4 mov r5, r0 */
/* @0x129eb8 mov r0, r4 */
/* @0x129ebc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129ec0 mov r1, #4 */
/* @0x129ec4 mov r8, r0 */
/* @0x129ec8 mov r0, r4 */
/* @0x129ecc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129ed0 str r8, [sp] */
/* @0x129ed4 mov r1, r7 */
/* @0x129ed8 mov r2, r6 */
/* @0x129edc mov r3, r5 */
/* @0x129ee0 str r0, [sp, #0x4] */
/* @0x129ee4 mov r0, #1 */
/* @0x129ee8 bl 0x1a25d0 <_Z13Effect_Createbiffij> */
/* @0x129eec add sp, sp, #8 */
/* @0x129ef0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x129ef4 · F_EffectCreateAbove(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x129ef4 push {r4, r5, r6, r7, r8, lr} */
/* @0x129ef8 sub sp, sp, #8 */
/* @0x129efc mov r1, #0 */
/* @0x129f00 ldr r4, [sp, #0x20] */
/* @0x129f04 mov r0, r4 */
/* @0x129f08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129f0c mov r1, #1 */
/* @0x129f10 mov r7, r0 */
/* @0x129f14 mov r0, r4 */
/* @0x129f18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129f1c mov r1, #2 */
/* @0x129f20 mov r6, r0 */
/* @0x129f24 mov r0, r4 */
/* @0x129f28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129f2c mov r1, #3 */
/* @0x129f30 mov r5, r0 */
/* @0x129f34 mov r0, r4 */
/* @0x129f38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129f3c mov r1, #4 */
/* @0x129f40 mov r8, r0 */
/* @0x129f44 mov r0, r4 */
/* @0x129f48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129f4c str r8, [sp] */
/* @0x129f50 mov r1, r7 */
/* @0x129f54 mov r2, r6 */
/* @0x129f58 mov r3, r5 */
/* @0x129f5c str r0, [sp, #0x4] */
/* @0x129f60 mov r0, #0 */
/* @0x129f64 bl 0x1a25d0 <_Z13Effect_Createbiffij> */
/* @0x129f68 add sp, sp, #8 */
/* @0x129f6c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x129f70 · F_EffectClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x129f70 b 0x1a277c <_Z12Effect_Clearv> */

/* ── FUNC 0x129f74 · InitParticlesFunctions() · size=2300 · insn=575 */
/* @0x129f74 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x129f78 mov r2, #0 */
/* @0x129f7c ldr r4, [pc, #0x70c] */
/* @0x129f80 mov r3, #1 */
/* @0x129f84 ldr r1, [pc, #0x708] */
/* @0x129f88 add r4, pc, r4 */
/* @0x129f8c ldr r0, [pc, #0x704] */
/* @0x129f90 add r0, pc, r0 */
/* @0x129f94 ldr r1, [r4, r1] */
/* @0x129f98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x129f9c ldr r1, [pc, #0x6f8] */
/* @0x129fa0 ldr r0, [pc, #0x6f8] */
/* @0x129fa4 mov r2, #1 */
/* @0x129fa8 mov r3, r2 */
/* @0x129fac add r0, pc, r0 */
/* @0x129fb0 ldr r1, [r4, r1] */
/* @0x129fb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x129fb8 ldr r1, [pc, #0x6e4] */
/* @0x129fbc ldr r0, [pc, #0x6e4] */
/* @0x129fc0 mov r2, #1 */
/* @0x129fc4 mov r3, r2 */
/* @0x129fc8 add r0, pc, r0 */
/* @0x129fcc ldr r1, [r4, r1] */
/* @0x129fd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x129fd4 ldr r1, [pc, #0x6d0] */
/* @0x129fd8 ldr r0, [pc, #0x6d0] */
/* @0x129fdc mov r2, #1 */
/* @0x129fe0 mov r3, r2 */
/* @0x129fe4 add r0, pc, r0 */
/* @0x129fe8 ldr r1, [r4, r1] */
/* @0x129fec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x129ff0 ldr r1, [pc, #0x6bc] */
/* @0x129ff4 ldr r0, [pc, #0x6bc] */
/* @0x129ff8 mov r2, #2 */
/* @0x129ffc mov r3, #1 */
/* @0x12a000 add r0, pc, r0 */
/* @0x12a004 ldr r1, [r4, r1] */
/* @0x12a008 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a00c ldr r1, [pc, #0x6a8] */
/* @0x12a010 ldr r0, [pc, #0x6a8] */
/* @0x12a014 mov r2, #5 */
/* @0x12a018 mov r3, #1 */
/* @0x12a01c add r0, pc, r0 */
/* @0x12a020 ldr r1, [r4, r1] */
/* @0x12a024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a028 ldr r1, [pc, #0x694] */
/* @0x12a02c ldr r0, [pc, #0x694] */
/* @0x12a030 mov r2, #5 */
/* @0x12a034 mov r3, #1 */
/* @0x12a038 add r0, pc, r0 */
/* @0x12a03c ldr r1, [r4, r1] */
/* @0x12a040 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a044 ldr r1, [pc, #0x680] */
/* @0x12a048 ldr r0, [pc, #0x680] */
/* @0x12a04c mov r2, #3 */
/* @0x12a050 mov r3, #1 */
/* @0x12a054 add r0, pc, r0 */
/* @0x12a058 ldr r1, [r4, r1] */
/* @0x12a05c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a060 ldr r1, [pc, #0x66c] */
/* @0x12a064 ldr r0, [pc, #0x66c] */
/* @0x12a068 mov r2, #3 */
/* @0x12a06c mov r3, #1 */
/* @0x12a070 add r0, pc, r0 */
/* @0x12a074 ldr r1, [r4, r1] */
/* @0x12a078 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a07c ldr r1, [pc, #0x658] */
/* @0x12a080 ldr r0, [pc, #0x658] */
/* @0x12a084 mov r2, #3 */
/* @0x12a088 mov r3, #1 */
/* @0x12a08c add r0, pc, r0 */
/* @0x12a090 ldr r1, [r4, r1] */
/* @0x12a094 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a098 ldr r1, [pc, #0x644] */
/* @0x12a09c ldr r0, [pc, #0x644] */
/* @0x12a0a0 mov r2, #3 */
/* @0x12a0a4 mov r3, #1 */
/* @0x12a0a8 add r0, pc, r0 */
/* @0x12a0ac ldr r1, [r4, r1] */
/* @0x12a0b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a0b4 ldr r1, [pc, #0x630] */
/* @0x12a0b8 ldr r0, [pc, #0x630] */
/* @0x12a0bc mov r2, #5 */
/* @0x12a0c0 mov r3, #1 */
/* @0x12a0c4 add r0, pc, r0 */
/* @0x12a0c8 ldr r1, [r4, r1] */
/* @0x12a0cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a0d0 ldr r1, [pc, #0x61c] */
/* @0x12a0d4 ldr r0, [pc, #0x61c] */
/* @0x12a0d8 mov r2, #5 */
/* @0x12a0dc mov r3, #1 */
/* @0x12a0e0 add r0, pc, r0 */
/* @0x12a0e4 ldr r1, [r4, r1] */
/* @0x12a0e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a0ec ldr r1, [pc, #0x608] */
/* @0x12a0f0 ldr r0, [pc, #0x608] */
/* @0x12a0f4 mov r2, #6 */
/* @0x12a0f8 mov r3, #1 */
/* @0x12a0fc add r0, pc, r0 */
/* @0x12a100 ldr r1, [r4, r1] */
/* @0x12a104 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a108 ldr r1, [pc, #0x5f4] */
/* @0x12a10c ldr r0, [pc, #0x5f4] */
/* @0x12a110 mov r2, #3 */
/* @0x12a114 mov r3, #1 */
/* @0x12a118 add r0, pc, r0 */
/* @0x12a11c ldr r1, [r4, r1] */
/* @0x12a120 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a124 ldr r1, [pc, #0x5e0] */
/* @0x12a128 ldr r0, [pc, #0x5e0] */
/* @0x12a12c mov r2, #3 */
/* @0x12a130 mov r3, #1 */
/* @0x12a134 ldr r10, [r4, r1] */
/* @0x12a138 add r0, pc, r0 */
/* @0x12a13c mov r1, r10 */
/* @0x12a140 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a144 ldr r1, [pc, #0x5c8] */
/* @0x12a148 ldr r0, [pc, #0x5c8] */
/* @0x12a14c mov r2, #7 */
/* @0x12a150 mov r3, #1 */
/* @0x12a154 ldr r9, [r4, r1] */
/* @0x12a158 add r0, pc, r0 */
/* @0x12a15c mov r1, r9 */
/* @0x12a160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a164 ldr r1, [pc, #0x5b0] */
/* @0x12a168 ldr r0, [pc, #0x5b0] */
/* @0x12a16c mov r2, #7 */
/* @0x12a170 mov r3, #1 */
/* @0x12a174 ldr r8, [r4, r1] */
/* @0x12a178 add r0, pc, r0 */
/* @0x12a17c mov r1, r8 */
/* @0x12a180 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a184 ldr r1, [pc, #0x598] */
/* @0x12a188 ldr r0, [pc, #0x598] */
/* @0x12a18c mov r2, #2 */
/* @0x12a190 mov r3, #1 */
/* @0x12a194 ldr r7, [r4, r1] */
/* @0x12a198 add r0, pc, r0 */
/* @0x12a19c mov r1, r7 */
/* @0x12a1a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a1a4 ldr r1, [pc, #0x580] */
/* @0x12a1a8 ldr r0, [pc, #0x580] */
/* @0x12a1ac mov r2, #3 */
/* @0x12a1b0 mov r3, #1 */
/* @0x12a1b4 ldr r6, [r4, r1] */
/* @0x12a1b8 add r0, pc, r0 */
/* @0x12a1bc mov r1, r6 */
/* @0x12a1c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a1c4 ldr r1, [pc, #0x568] */
/* @0x12a1c8 ldr r0, [pc, #0x568] */
/* @0x12a1cc mov r2, #4 */
/* @0x12a1d0 mov r3, #1 */
/* @0x12a1d4 ldr r5, [r4, r1] */
/* @0x12a1d8 add r0, pc, r0 */
/* @0x12a1dc mov r1, r5 */
/* @0x12a1e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a1e4 ldr r0, [pc, #0x550] */
/* @0x12a1e8 mov r1, r5 */
/* @0x12a1ec mov r2, #4 */
/* @0x12a1f0 add r0, pc, r0 */
/* @0x12a1f4 mov r3, #1 */
/* @0x12a1f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a1fc ldr r0, [pc, #0x53c] */
/* @0x12a200 mov r1, r10 */
/* @0x12a204 mov r2, #3 */
/* @0x12a208 add r0, pc, r0 */
/* @0x12a20c mov r3, #1 */
/* @0x12a210 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a214 ldr r0, [pc, #0x528] */
/* @0x12a218 mov r1, r9 */
/* @0x12a21c mov r2, #7 */
/* @0x12a220 add r0, pc, r0 */
/* @0x12a224 mov r3, #1 */
/* @0x12a228 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a22c ldr r0, [pc, #0x514] */
/* @0x12a230 mov r1, r8 */
/* @0x12a234 mov r2, #7 */
/* @0x12a238 add r0, pc, r0 */
/* @0x12a23c mov r3, #1 */
/* @0x12a240 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a244 ldr r0, [pc, #0x500] */
/* @0x12a248 mov r1, r7 */
/* @0x12a24c mov r2, #2 */
/* @0x12a250 add r0, pc, r0 */
/* @0x12a254 mov r3, #1 */
/* @0x12a258 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a25c ldr r0, [pc, #0x4ec] */
/* @0x12a260 mov r1, r6 */
/* @0x12a264 mov r2, #3 */
/* @0x12a268 add r0, pc, r0 */
/* @0x12a26c mov r3, #1 */
/* @0x12a270 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a274 ldr r0, [pc, #0x4d8] */
/* @0x12a278 mov r1, r5 */
/* @0x12a27c mov r2, #4 */
/* @0x12a280 add r0, pc, r0 */
/* @0x12a284 mov r3, #1 */
/* @0x12a288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a28c ldr r0, [pc, #0x4c4] */
/* @0x12a290 mov r1, r5 */
/* @0x12a294 mov r2, #4 */
/* @0x12a298 add r0, pc, r0 */
/* @0x12a29c mov r3, #1 */
/* @0x12a2a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a2a4 ldr r1, [pc, #0x4b0] */
/* @0x12a2a8 ldr r0, [pc, #0x4b0] */
/* @0x12a2ac mov r2, #2 */
/* @0x12a2b0 mov r3, #1 */
/* @0x12a2b4 add r0, pc, r0 */
/* @0x12a2b8 ldr r1, [r4, r1] */
/* @0x12a2bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a2c0 ldr r1, [pc, #0x49c] */
/* @0x12a2c4 ldr r0, [pc, #0x49c] */
/* @0x12a2c8 mov r2, #3 */
/* @0x12a2cc mov r3, #1 */
/* @0x12a2d0 add r0, pc, r0 */
/* @0x12a2d4 ldr r1, [r4, r1] */
/* @0x12a2d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a2dc ldr r1, [pc, #0x488] */
/* @0x12a2e0 ldr r0, [pc, #0x488] */
/* @0x12a2e4 mov r2, #4 */
/* @0x12a2e8 mov r3, #1 */
/* @0x12a2ec ldr r5, [r4, r1] */
/* @0x12a2f0 add r0, pc, r0 */
/* @0x12a2f4 mov r1, r5 */
/* @0x12a2f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a2fc ldr r0, [pc, #0x470] */
/* @0x12a300 mov r1, r5 */
/* @0x12a304 mov r2, #4 */
/* @0x12a308 add r0, pc, r0 */
/* @0x12a30c mov r3, #1 */
/* @0x12a310 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a314 ldr r1, [pc, #0x45c] */
/* @0x12a318 ldr r0, [pc, #0x45c] */
/* @0x12a31c mov r2, #2 */
/* @0x12a320 mov r3, #1 */
/* @0x12a324 add r0, pc, r0 */
/* @0x12a328 ldr r1, [r4, r1] */
/* @0x12a32c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a330 ldr r1, [pc, #0x448] */
/* @0x12a334 ldr r0, [pc, #0x448] */
/* @0x12a338 mov r2, #0 */
/* @0x12a33c mov r3, #1 */
/* @0x12a340 add r0, pc, r0 */
/* @0x12a344 ldr r1, [r4, r1] */
/* @0x12a348 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a34c ldr r1, [pc, #0x434] */
/* @0x12a350 ldr r0, [pc, #0x434] */
/* @0x12a354 mov r2, #1 */
/* @0x12a358 mov r3, r2 */
/* @0x12a35c add r0, pc, r0 */
/* @0x12a360 ldr r1, [r4, r1] */
/* @0x12a364 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a368 ldr r1, [pc, #0x420] */
/* @0x12a36c ldr r0, [pc, #0x420] */
/* @0x12a370 mov r2, #1 */
/* @0x12a374 mov r3, r2 */
/* @0x12a378 add r0, pc, r0 */
/* @0x12a37c ldr r1, [r4, r1] */
/* @0x12a380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a384 ldr r1, [pc, #0x40c] */
/* @0x12a388 ldr r0, [pc, #0x40c] */
/* @0x12a38c mov r2, #1 */
/* @0x12a390 mov r3, r2 */
/* @0x12a394 add r0, pc, r0 */
/* @0x12a398 ldr r1, [r4, r1] */
/* @0x12a39c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a3a0 ldr r1, [pc, #0x3f8] */
/* @0x12a3a4 ldr r0, [pc, #0x3f8] */
/* @0x12a3a8 mov r2, #2 */
/* @0x12a3ac mov r3, #1 */
/* @0x12a3b0 add r0, pc, r0 */
/* @0x12a3b4 ldr r1, [r4, r1] */
/* @0x12a3b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a3bc ldr r1, [pc, #0x3e4] */
/* @0x12a3c0 ldr r0, [pc, #0x3e4] */
/* @0x12a3c4 mov r2, #2 */
/* @0x12a3c8 mov r3, #1 */
/* @0x12a3cc add r0, pc, r0 */
/* @0x12a3d0 ldr r1, [r4, r1] */
/* @0x12a3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a3d8 ldr r1, [pc, #0x3d0] */
/* @0x12a3dc ldr r0, [pc, #0x3d0] */
/* @0x12a3e0 mov r2, #3 */
/* @0x12a3e4 mov r3, #1 */
/* @0x12a3e8 add r0, pc, r0 */
/* @0x12a3ec ldr r1, [r4, r1] */
/* @0x12a3f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a3f4 ldr r1, [pc, #0x3bc] */
/* @0x12a3f8 ldr r0, [pc, #0x3bc] */
/* @0x12a3fc mov r2, #2 */
/* @0x12a400 mov r3, #1 */
/* @0x12a404 add r0, pc, r0 */
/* @0x12a408 ldr r1, [r4, r1] */
/* @0x12a40c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a410 ldr r1, [pc, #0x3a8] */
/* @0x12a414 ldr r0, [pc, #0x3a8] */
/* @0x12a418 mov r2, #2 */
/* @0x12a41c mov r3, #1 */
/* @0x12a420 add r0, pc, r0 */
/* @0x12a424 ldr r1, [r4, r1] */
/* @0x12a428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a42c ldr r1, [pc, #0x394] */
/* @0x12a430 ldr r0, [pc, #0x394] */
/* @0x12a434 mov r2, #1 */
/* @0x12a438 mov r3, r2 */
/* @0x12a43c add r0, pc, r0 */
/* @0x12a440 ldr r1, [r4, r1] */
/* @0x12a444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a448 ldr r1, [pc, #0x380] */
/* @0x12a44c ldr r0, [pc, #0x380] */
/* @0x12a450 mov r2, #1 */
/* @0x12a454 mov r3, r2 */
/* @0x12a458 add r0, pc, r0 */
/* @0x12a45c ldr r1, [r4, r1] */
/* @0x12a460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a464 ldr r3, [pc, #0x36c] */
/* @0x12a468 ldr r3, [r4, r3] */
/* @0x12a46c ldrb r3, [r3] */
/* @0x12a470 cmp r3, #0 */
/* @0x12a474 beq 0x12a4cc <_Z22InitParticlesFunctionsv+0x558> */
/* @0x12a478 ldr r1, [pc, #0x35c] */
/* @0x12a47c mov r2, #2 */
/* @0x12a480 ldr r0, [pc, #0x358] */
/* @0x12a484 mov r3, #1 */
/* @0x12a488 add r0, pc, r0 */
/* @0x12a48c ldr r1, [r4, r1] */
/* @0x12a490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a494 ldr r1, [pc, #0x348] */
/* @0x12a498 ldr r0, [pc, #0x348] */
/* @0x12a49c mov r2, #1 */
/* @0x12a4a0 mov r3, r2 */
/* @0x12a4a4 add r0, pc, r0 */
/* @0x12a4a8 ldr r1, [r4, r1] */
/* @0x12a4ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a4b0 ldr r1, [pc, #0x334] */
/* @0x12a4b4 ldr r0, [pc, #0x334] */
/* @0x12a4b8 mov r2, #2 */
/* @0x12a4bc mov r3, #1 */
/* @0x12a4c0 add r0, pc, r0 */
/* @0x12a4c4 ldr r1, [r4, r1] */
/* @0x12a4c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a4cc ldr r1, [pc, #0x320] */
/* @0x12a4d0 mov r2, #5 */
/* @0x12a4d4 ldr r0, [pc, #0x31c] */
/* @0x12a4d8 mov r3, #1 */
/* @0x12a4dc ldr r1, [r4, r1] */
/* @0x12a4e0 add r0, pc, r0 */
/* @0x12a4e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a4e8 ldr r1, [pc, #0x30c] */
/* @0x12a4ec ldr r0, [pc, #0x30c] */
/* @0x12a4f0 mov r2, #6 */
/* @0x12a4f4 mov r3, #1 */
/* @0x12a4f8 ldr r5, [r4, r1] */
/* @0x12a4fc add r0, pc, r0 */
/* @0x12a500 mov r1, r5 */
/* @0x12a504 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a508 ldr r0, [pc, #0x2f4] */
/* @0x12a50c mov r1, r5 */
/* @0x12a510 mov r2, #6 */
/* @0x12a514 add r0, pc, r0 */
/* @0x12a518 mov r3, #1 */
/* @0x12a51c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a520 ldr r1, [pc, #0x2e0] */
/* @0x12a524 ldr r0, [pc, #0x2e0] */
/* @0x12a528 mov r2, #1 */
/* @0x12a52c mov r3, r2 */
/* @0x12a530 ldr r1, [r4, r1] */
/* @0x12a534 add r0, pc, r0 */
/* @0x12a538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a53c ldr r1, [pc, #0x2cc] */
/* @0x12a540 ldr r0, [pc, #0x2cc] */
/* @0x12a544 mov r2, #1 */
/* @0x12a548 mov r3, r2 */
/* @0x12a54c ldr r1, [r4, r1] */
/* @0x12a550 add r0, pc, r0 */
/* @0x12a554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a558 ldr r1, [pc, #0x2b8] */
/* @0x12a55c ldr r0, [pc, #0x2b8] */
/* @0x12a560 mov r2, #1 */
/* @0x12a564 mov r3, r2 */
/* @0x12a568 ldr r1, [r4, r1] */
/* @0x12a56c add r0, pc, r0 */
/* @0x12a570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a574 ldr r1, [pc, #0x2a4] */
/* @0x12a578 ldr r0, [pc, #0x2a4] */
/* @0x12a57c mov r2, #2 */
/* @0x12a580 mov r3, #1 */
/* @0x12a584 ldr r1, [r4, r1] */
/* @0x12a588 add r0, pc, r0 */
/* @0x12a58c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a590 ldr r1, [pc, #0x290] */
/* @0x12a594 ldr r0, [pc, #0x290] */
/* @0x12a598 mov r2, #1 */
/* @0x12a59c mov r3, r2 */
/* @0x12a5a0 ldr r1, [r4, r1] */
/* @0x12a5a4 add r0, pc, r0 */
/* @0x12a5a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a5ac ldr r1, [pc, #0x27c] */
/* @0x12a5b0 ldr r0, [pc, #0x27c] */
/* @0x12a5b4 mov r2, #2 */
/* @0x12a5b8 mov r3, #1 */
/* @0x12a5bc ldr r1, [r4, r1] */
/* @0x12a5c0 add r0, pc, r0 */
/* @0x12a5c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a5c8 ldr r1, [pc, #0x268] */
/* @0x12a5cc ldr r0, [pc, #0x268] */
/* @0x12a5d0 mov r2, #2 */
/* @0x12a5d4 mov r3, #1 */
/* @0x12a5d8 ldr r1, [r4, r1] */
/* @0x12a5dc add r0, pc, r0 */
/* @0x12a5e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a5e4 ldr r1, [pc, #0x254] */
/* @0x12a5e8 ldr r0, [pc, #0x254] */
/* @0x12a5ec mov r2, #8 */
/* @0x12a5f0 mov r3, #1 */
/* @0x12a5f4 ldr r1, [r4, r1] */
/* @0x12a5f8 add r0, pc, r0 */
/* @0x12a5fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a600 ldr r1, [pc, #0x240] */
/* @0x12a604 ldr r0, [pc, #0x240] */
/* @0x12a608 mov r2, #4 */
/* @0x12a60c mov r3, #1 */
/* @0x12a610 ldr r1, [r4, r1] */
/* @0x12a614 add r0, pc, r0 */
/* @0x12a618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a61c ldr r1, [pc, #0x22c] */
/* @0x12a620 ldr r0, [pc, #0x22c] */
/* @0x12a624 mov r2, #4 */
/* @0x12a628 mov r3, #1 */
/* @0x12a62c ldr r1, [r4, r1] */
/* @0x12a630 add r0, pc, r0 */
/* @0x12a634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a638 ldr r1, [pc, #0x218] */
/* @0x12a63c ldr r0, [pc, #0x218] */
/* @0x12a640 mov r2, #5 */
/* @0x12a644 mov r3, #1 */
/* @0x12a648 ldr r1, [r4, r1] */
/* @0x12a64c add r0, pc, r0 */
/* @0x12a650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a654 ldr r1, [pc, #0x204] */
/* @0x12a658 ldr r0, [pc, #0x204] */
/* @0x12a65c mov r2, #5 */
/* @0x12a660 mov r3, #1 */
/* @0x12a664 ldr r1, [r4, r1] */
/* @0x12a668 add r0, pc, r0 */
/* @0x12a66c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a670 ldr r1, [pc, #0x1f0] */
/* @0x12a674 ldr r0, [pc, #0x1f0] */
/* @0x12a678 mov r2, #0 */
/* @0x12a67c mov r3, #1 */
/* @0x12a680 ldr r1, [r4, r1] */
/* @0x12a684 add r0, pc, r0 */
/* @0x12a688 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12a68c b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12a690 eoreq r7, r12, r8, asr #25 */
/* @0x12a694 .word 0xffffd008 */
/* @0x12a698 eoreq r2, r1, r12, ror #30 */
/* @0x12a69c .word 0xffffd00c */
/* @0x12a6a0 eoreq r2, r1, r4, ror #30 */
/* @0x12a6a4 .word 0xffffd010 */
/* @0x12a6a8 eoreq r2, r1, r12, asr pc */
/* @0x12a6ac .word 0xffffd014 */
/* @0x12a6b0 eoreq r2, r1, r4, asr pc */
/* @0x12a6b4 .word 0xffffd018 */
/* @0x12a6b8 eoreq r2, r1, r8, asr #30 */
/* @0x12a6bc .word 0xffffd01c */
/* @0x12a6c0 eoreq r2, r1, r12, lsr pc */
/* @0x12a6c4 .word 0xffffd020 */
/* @0x12a6c8 eoreq r2, r1, r4, lsr pc */
/* @0x12a6cc .word 0xffffd024 */
/* @0x12a6d0 eoreq r2, r1, r8, lsr #30 */
/* @0x12a6d4 .word 0xffffd028 */
/* @0x12a6d8 eoreq r2, r1, r12, lsl pc */
/* @0x12a6dc .word 0xffffd02c */
/* @0x12a6e0 eoreq r2, r1, r0, lsl pc */
/* @0x12a6e4 .word 0xffffd030 */
/* @0x12a6e8 eoreq r2, r1, r4, lsl #30 */
/* @0x12a6ec .word 0xffffd034 */
/* @0x12a6f0 .word 0x00212ef8 */
/* @0x12a6f4 .word 0xffffd038 */
/* @0x12a6f8 eoreq r2, r1, r12, ror #29 */
/* @0x12a6fc .word 0xffffd03c */
/* @0x12a700 eoreq r2, r1, r4, ror #29 */
/* @0x12a704 .word 0xffffd040 */
/* @0x12a708 eoreq r2, r1, r0, ror #29 */
/* @0x12a70c .word 0xffffd044 */
/* @0x12a710 .word 0x00212ed4 */
/* @0x12a714 .word 0xffffd048 */
/* @0x12a718 eoreq r2, r1, r8, asr #29 */
/* @0x12a71c .word 0xffffd04c */
/* @0x12a720 .word 0x00212ebc */
/* @0x12a724 .word 0xffffd050 */
/* @0x12a728 .word 0x00212eb0 */
/* @0x12a72c .word 0xffffd054 */
/* @0x12a730 eoreq r2, r1, r4, lsr #29 */
/* @0x12a734 .word 0xffffd058 */
/* @0x12a738 mlaeq r1, r8, lr, r2 */
/* @0x12a73c mlaeq r1, r4, lr, r2 */
/* @0x12a740 eoreq r2, r1, r12, lsl #29 */
/* @0x12a744 eoreq r2, r1, r12, lsl #29 */
/* @0x12a748 eoreq r2, r1, r12, lsl #29 */
/* @0x12a74c eoreq r2, r1, r12, lsl #29 */
/* @0x12a750 eoreq r2, r1, r8, lsl #29 */
/* @0x12a754 eoreq r2, r1, r4, lsl #29 */
/* @0x12a758 eoreq r2, r1, r0, lsl #29 */
/* @0x12a75c .word 0xffffd05c */
/* @0x12a760 eoreq r2, r1, r8, ror lr */
/* @0x12a764 .word 0xffffd060 */
/* @0x12a768 eoreq r2, r1, r0, ror lr */
/* @0x12a76c .word 0xffffd064 */
/* @0x12a770 eoreq r2, r1, r4, ror #28 */
/* @0x12a774 eoreq r2, r1, r0, ror #28 */
/* @0x12a778 .word 0xffffd068 */
/* @0x12a77c eoreq r2, r1, r4, asr lr */
/* @0x12a780 .word 0xffffd06c */
/* @0x12a784 eoreq r2, r1, r8, asr #28 */
/* @0x12a788 .word 0xffffd070 */
/* @0x12a78c eoreq r2, r1, r0, asr #28 */
/* @0x12a790 .word 0xffffd074 */
/* @0x12a794 eoreq r2, r1, r8, lsr lr */
/* @0x12a798 .word 0xffffd078 */
/* @0x12a79c eoreq r2, r1, r0, lsr lr */
/* @0x12a7a0 .word 0xffffd07c */
/* @0x12a7a4 eoreq r2, r1, r8, lsr #28 */
/* @0x12a7a8 .word 0xffffd080 */
/* @0x12a7ac eoreq r2, r1, r4, lsr #28 */
/* @0x12a7b0 .word 0xffffd084 */
/* @0x12a7b4 eoreq r2, r1, r12, lsl lr */
/* @0x12a7b8 .word 0xffffd088 */
/* @0x12a7bc eoreq r2, r1, r8, lsl lr */
/* @0x12a7c0 .word 0xffffd08c */
/* @0x12a7c4 eoreq r2, r1, r12, lsl lr */
/* @0x12a7c8 .word 0xffffd090 */
/* @0x12a7cc eoreq r2, r1, r12, lsl lr */
/* @0x12a7d0 .word 0xffffd094 */
/* @0x12a7d4 eoreq r2, r1, r4, lsl lr */
/* @0x12a7d8 .word 0xffffbcd4 */
/* @0x12a7dc .word 0xffffd098 */
/* @0x12a7e0 .word 0x00212df8 */
/* @0x12a7e4 .word 0xffffd09c */
/* @0x12a7e8 .word 0x00212df8 */
/* @0x12a7ec .word 0xffffd0a0 */
/* @0x12a7f0 .word 0x00212df4 */
/* @0x12a7f4 .word 0xffffd0a4 */
/* @0x12a7f8 eoreq r2, r1, r8, ror #27 */
/* @0x12a7fc .word 0xffffd0a8 */
/* @0x12a800 eoreq r2, r1, r4, ror #27 */
/* @0x12a804 eoreq r2, r1, r8, ror #27 */
/* @0x12a808 .word 0xffffd0ac */
/* @0x12a80c eoreq r2, r1, r8, ror #27 */
/* @0x12a810 .word 0xffffd0b0 */
/* @0x12a814 eoreq r2, r1, r4, ror #27 */
/* @0x12a818 .word 0xffffd0b4 */
/* @0x12a81c eoreq r2, r1, r0, ror #27 */
/* @0x12a820 .word 0xffffd0b8 */
/* @0x12a824 .word 0x00212dd8 */
/* @0x12a828 .word 0xffffd0bc */
/* @0x12a82c .word 0x00212dd4 */
/* @0x12a830 .word 0xffffd0c0 */
/* @0x12a834 .word 0x00212dd4 */
/* @0x12a838 .word 0xffffd0c4 */
/* @0x12a83c eoreq r2, r1, r12, asr #27 */
/* @0x12a840 .word 0xffffd0c8 */
/* @0x12a844 eoreq r2, r1, r4, asr #27 */
/* @0x12a848 .word 0xffffd0cc */
/* @0x12a84c .word 0x00212dbc */
/* @0x12a850 .word 0xffffd0d0 */
/* @0x12a854 .word 0x00212db4 */
/* @0x12a858 .word 0xffffd0d4 */
/* @0x12a85c eoreq r2, r1, r12, lsr #27 */
/* @0x12a860 .word 0xffffd0d8 */
/* @0x12a864 eoreq r2, r1, r4, lsr #27 */
/* @0x12a868 .word 0xffffd0dc */
/* @0x12a86c mlaeq r1, r12, sp, r2 */

/* ── FUNC 0x12a870 · F_SpriteAddSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12a870 push {r3, lr} */
/* @0x12a874 mov r12, #0 */
/* @0x12a878 ldr r3, [pc, #0x34] */
/* @0x12a87c mov r2, r0 */
/* @0x12a880 mov r1, r12 */
/* @0x12a884 str r1, [r0] */
/* @0x12a888 ldr r3, [pc, r3] */
/* @0x12a88c movt r12, #0xbff0 */
/* @0x12a890 str r12, [r2, #0x4] */
/* @0x12a894 ldr r0, [r3] */
/* @0x12a898 str r1, [r2, #0xc] */
/* @0x12a89c ldr r1, [pc, #0x14] */
/* @0x12a8a0 ldr r3, [r0] */
/* @0x12a8a4 add r1, pc, r1 */
/* @0x12a8a8 ldr r3, [r3, #0xc] */
/* @0x12a8ac blx r3 */
/* @0x12a8b0 pop {r3, pc} */
/* @0x12a8b4 eoreq r2, r12, r12, lsl #29 */
/* @0x12a8b8 eoreq r2, r1, r12, lsl #23 */

/* ── FUNC 0x12a8bc · F_SpriteReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12a8bc push {r3, lr} */
/* @0x12a8c0 mov r12, #0 */
/* @0x12a8c4 ldr r3, [pc, #0x34] */
/* @0x12a8c8 mov r2, r0 */
/* @0x12a8cc mov r1, r12 */
/* @0x12a8d0 str r1, [r0] */
/* @0x12a8d4 ldr r3, [pc, r3] */
/* @0x12a8d8 movt r12, #0xbff0 */
/* @0x12a8dc str r12, [r2, #0x4] */
/* @0x12a8e0 ldr r0, [r3] */
/* @0x12a8e4 str r1, [r2, #0xc] */
/* @0x12a8e8 ldr r1, [pc, #0x14] */
/* @0x12a8ec ldr r3, [r0] */
/* @0x12a8f0 add r1, pc, r1 */
/* @0x12a8f4 ldr r3, [r3, #0xc] */
/* @0x12a8f8 blx r3 */
/* @0x12a8fc pop {r3, pc} */
/* @0x12a900 eoreq r2, r12, r0, asr #28 */
/* @0x12a904 eoreq r2, r1, r0, asr #22 */

/* ── FUNC 0x12a908 · F_BackgroundAddBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12a908 push {r3, lr} */
/* @0x12a90c mov r12, #0 */
/* @0x12a910 ldr r3, [pc, #0x34] */
/* @0x12a914 mov r2, r0 */
/* @0x12a918 mov r1, r12 */
/* @0x12a91c str r1, [r0] */
/* @0x12a920 ldr r3, [pc, r3] */
/* @0x12a924 movt r12, #0xbff0 */
/* @0x12a928 str r12, [r2, #0x4] */
/* @0x12a92c ldr r0, [r3] */
/* @0x12a930 str r1, [r2, #0xc] */
/* @0x12a934 ldr r1, [pc, #0x14] */
/* @0x12a938 ldr r3, [r0] */
/* @0x12a93c add r1, pc, r1 */
/* @0x12a940 ldr r3, [r3, #0xc] */
/* @0x12a944 blx r3 */
/* @0x12a948 pop {r3, pc} */
/* @0x12a94c .word 0x002c2df4 */
/* @0x12a950 .word 0x00212af4 */

/* ── FUNC 0x12a954 · F_BackgroundReplaceBackground(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12a954 push {r3, lr} */
/* @0x12a958 mov r12, #0 */
/* @0x12a95c ldr r3, [pc, #0x34] */
/* @0x12a960 mov r2, r0 */
/* @0x12a964 mov r1, r12 */
/* @0x12a968 str r1, [r0] */
/* @0x12a96c ldr r3, [pc, r3] */
/* @0x12a970 movt r12, #0xbff0 */
/* @0x12a974 str r12, [r2, #0x4] */
/* @0x12a978 ldr r0, [r3] */
/* @0x12a97c str r1, [r2, #0xc] */
/* @0x12a980 ldr r1, [pc, #0x14] */
/* @0x12a984 ldr r3, [r0] */
/* @0x12a988 add r1, pc, r1 */
/* @0x12a98c ldr r3, [r3, #0xc] */
/* @0x12a990 blx r3 */
/* @0x12a994 pop {r3, pc} */
/* @0x12a998 eoreq r2, r12, r8, lsr #27 */
/* @0x12a99c eoreq r2, r1, r8, lsr #21 */

/* ── FUNC 0x12a9a0 · F_FontAddGetEnableAA(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12a9a0 ldr r3, [pc, #0x28] */
/* @0x12a9a4 mov r2, #0 */
/* @0x12a9a8 str r2, [r0, #0xc] */
/* @0x12a9ac ldr r3, [pc, r3] */
/* @0x12a9b0 ldrb r3, [r3] */
/* @0x12a9b4 cmp r3, r2 */
/* @0x12a9b8 movne r3, r2 */
/* @0x12a9bc moveq r2, r3 */
/* @0x12a9c0 movtne r2, #0x3ff0 */
/* @0x12a9c4 str r3, [r0] */
/* @0x12a9c8 str r2, [r0, #0x4] */
/* @0x12a9cc bx lr */
/* @0x12a9d0 eoreq r3, r12, r12, lsr #9 */

/* ── FUNC 0x12a9d4 · F_FontGetDynamicTextureSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x12a9d4 ldr r3, [pc, #0x20] */
/* @0x12a9d8 mov r2, #0 */
/* @0x12a9dc str r2, [r0, #0xc] */
/* @0x12a9e0 ldr r3, [pc, r3] */
/* @0x12a9e4 ldr r2, [r3] */
/* @0x12a9e8 vmov s15, r2 */
/* @0x12a9ec vcvt.f64.s32 d7, s15 */
/* @0x12a9f0 vmov r2, r3, d7 */
/* @0x12a9f4 stm r0, {r2, r3} */
/* @0x12a9f8 bx lr */
/* @0x12a9fc eoreq r3, r12, r4, ror r4 */

/* ── FUNC 0x12aa00 · F_TimeLineMomentAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x12aa00 push {r3, lr} */
/* @0x12aa04 ldr r3, [pc, #0x1c] */
/* @0x12aa08 ldr r1, [pc, #0x1c] */
/* @0x12aa0c ldr r3, [pc, r3] */
/* @0x12aa10 add r1, pc, r1 */
/* @0x12aa14 ldr r0, [r3] */
/* @0x12aa18 ldr r3, [r0] */
/* @0x12aa1c ldr r3, [r3, #0xc] */
/* @0x12aa20 blx r3 */
/* @0x12aa24 pop {r3, pc} */
/* @0x12aa28 eoreq r2, r12, r8, lsl #26 */
/* @0x12aa2c eoreq r2, r1, r8, lsr r10 */

/* ── FUNC 0x12aa30 · F_ObjectEventAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x12aa30 push {r3, lr} */
/* @0x12aa34 ldr r3, [pc, #0x1c] */
/* @0x12aa38 ldr r1, [pc, #0x1c] */
/* @0x12aa3c ldr r3, [pc, r3] */
/* @0x12aa40 add r1, pc, r1 */
/* @0x12aa44 ldr r0, [r3] */
/* @0x12aa48 ldr r3, [r0] */
/* @0x12aa4c ldr r3, [r3, #0xc] */
/* @0x12aa50 blx r3 */
/* @0x12aa54 pop {r3, pc} */
/* @0x12aa58 .word 0x002c2cd8 */
/* @0x12aa5c eoreq r2, r1, r4, lsr r10 */

/* ── FUNC 0x12aa60 · F_FontSetCacheSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x12aa60 mov r3, #0 */
/* @0x12aa64 str r3, [r0, #0xc] */
/* @0x12aa68 str r3, [r0] */
/* @0x12aa6c str r3, [r0, #0x4] */
/* @0x12aa70 bx lr */

/* ── FUNC 0x12aa74 · F_SpriteSetCacheSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x12aa74 mov r3, #0 */
/* @0x12aa78 str r3, [r0, #0xc] */
/* @0x12aa7c str r3, [r0] */
/* @0x12aa80 str r3, [r0, #0x4] */
/* @0x12aa84 bx lr */

/* ── FUNC 0x12aa88 · F_SpriteSetCacheSizeExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x12aa88 mov r3, #0 */
/* @0x12aa8c str r3, [r0, #0xc] */
/* @0x12aa90 str r3, [r0] */
/* @0x12aa94 str r3, [r0, #0x4] */
/* @0x12aa98 bx lr */

/* ── FUNC 0x12aa9c · F_SpriteGetTPE(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x12aa9c mov r3, #0 */
/* @0x12aaa0 str r3, [r0, #0xc] */
/* @0x12aaa4 str r3, [r0] */
/* @0x12aaa8 str r3, [r0, #0x4] */
/* @0x12aaac bx lr */

/* ── FUNC 0x12aab0 · F_FontSetDynamicTextureSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12aab0 push {r3, lr} */
/* @0x12aab4 mov r1, #0 */
/* @0x12aab8 ldr r0, [sp, #0x8] */
/* @0x12aabc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12aac0 ldr r3, [pc, #0x8] */
/* @0x12aac4 ldr r3, [pc, r3] */
/* @0x12aac8 str r0, [r3] */
/* @0x12aacc pop {r3, pc} */
/* @0x12aad0 mlaeq r12, r0, r3, r3 */

/* ── FUNC 0x12aad4 · F_ObjectGetSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x12aad4 push {r4, lr} */
/* @0x12aad8 mov r1, #0 */
/* @0x12aadc mov r4, r0 */
/* @0x12aae0 ldr r0, [sp, #0x8] */
/* @0x12aae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12aae8 ldr r3, [pc, #0x74] */
/* @0x12aaec ldr r3, [pc, r3] */
/* @0x12aaf0 ldr r3, [r3] */
/* @0x12aaf4 ldr r2, [r3, #0x4] */
/* @0x12aaf8 ldr r3, [r3] */
/* @0x12aafc and r2, r0, r2 */
/* @0x12ab00 ldr r3, [r3, r2, lsl #3] */
/* @0x12ab04 cmp r3, #0 */
/* @0x12ab08 bne 0x12ab1c <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ab0c b 0x12ab48 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ab10 ldr r3, [r3, #0x4] */
/* @0x12ab14 cmp r3, #0 */
/* @0x12ab18 beq 0x12ab48 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ab1c ldr r2, [r3, #0x8] */
/* @0x12ab20 cmp r0, r2 */
/* @0x12ab24 bne 0x12ab10 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12ab28 ldr r3, [r3, #0xc] */
/* @0x12ab2c cmp r3, #0 */
/* @0x12ab30 beq 0x12ab48 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ab34 ldr r2, [r3, #0x4] */
/* @0x12ab38 vmov s15, r2 */
/* @0x12ab3c vcvt.f64.s32 d7, s15 */
/* @0x12ab40 vmov r2, r3, d7 */
/* @0x12ab44 b 0x12ab54 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ab48 mov r3, #0 */
/* @0x12ab4c movt r3, #0xbff0 */
/* @0x12ab50 mov r2, #0 */
/* @0x12ab54 mov r1, #0 */
/* @0x12ab58 stm r4, {r2, r3} */
/* @0x12ab5c str r1, [r4, #0xc] */
/* @0x12ab60 pop {r4, pc} */
/* @0x12ab64 eoreq r3, r12, r0, asr r1 */

/* ── FUNC 0x12ab68 · F_ObjectGetSolid(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x12ab68 push {r4, lr} */
/* @0x12ab6c mov r1, #0 */
/* @0x12ab70 mov r4, r0 */
/* @0x12ab74 ldr r0, [sp, #0x8] */
/* @0x12ab78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ab7c ldr r3, [pc, #0x7c] */
/* @0x12ab80 ldr r3, [pc, r3] */
/* @0x12ab84 ldr r3, [r3] */
/* @0x12ab88 ldr r2, [r3, #0x4] */
/* @0x12ab8c ldr r3, [r3] */
/* @0x12ab90 and r2, r0, r2 */
/* @0x12ab94 ldr r3, [r3, r2, lsl #3] */
/* @0x12ab98 cmp r3, #0 */
/* @0x12ab9c bne 0x12abb0 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12aba0 b 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12aba4 ldr r3, [r3, #0x4] */
/* @0x12aba8 cmp r3, #0 */
/* @0x12abac beq 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12abb0 ldr r2, [r3, #0x8] */
/* @0x12abb4 cmp r0, r2 */
/* @0x12abb8 bne 0x12aba4 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12abbc ldr r3, [r3, #0xc] */
/* @0x12abc0 cmp r3, #0 */
/* @0x12abc4 beq 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12abc8 ldr r3, [r3] */
/* @0x12abcc tst r3, #1 */
/* @0x12abd0 beq 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12abd4 mov r3, #0 */
/* @0x12abd8 str r3, [r4, #0xc] */
/* @0x12abdc mov r2, r3 */
/* @0x12abe0 movt r2, #0x3ff0 */
/* @0x12abe4 b 0x12abf4 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12abe8 mov r3, #0 */
/* @0x12abec str r3, [r4, #0xc] */
/* @0x12abf0 mov r2, r3 */
/* @0x12abf4 str r3, [r4] */
/* @0x12abf8 str r2, [r4, #0x4] */
/* @0x12abfc pop {r4, pc} */
/* @0x12ac00 strhteq r3, [r12], -r12 */

/* ── FUNC 0x12ac04 · F_ObjectGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x12ac04 push {r4, lr} */
/* @0x12ac08 mov r1, #0 */
/* @0x12ac0c mov r4, r0 */
/* @0x12ac10 ldr r0, [sp, #0x8] */
/* @0x12ac14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ac18 ldr r3, [pc, #0x7c] */
/* @0x12ac1c ldr r3, [pc, r3] */
/* @0x12ac20 ldr r3, [r3] */
/* @0x12ac24 ldr r2, [r3, #0x4] */
/* @0x12ac28 ldr r3, [r3] */
/* @0x12ac2c and r2, r0, r2 */
/* @0x12ac30 ldr r3, [r3, r2, lsl #3] */
/* @0x12ac34 cmp r3, #0 */
/* @0x12ac38 bne 0x12ac4c <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ac3c b 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ac40 ldr r3, [r3, #0x4] */
/* @0x12ac44 cmp r3, #0 */
/* @0x12ac48 beq 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ac4c ldr r2, [r3, #0x8] */
/* @0x12ac50 cmp r0, r2 */
/* @0x12ac54 bne 0x12ac40 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12ac58 ldr r3, [r3, #0xc] */
/* @0x12ac5c cmp r3, #0 */
/* @0x12ac60 beq 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ac64 ldr r3, [r3] */
/* @0x12ac68 tst r3, #2 */
/* @0x12ac6c beq 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ac70 mov r3, #0 */
/* @0x12ac74 str r3, [r4, #0xc] */
/* @0x12ac78 mov r2, r3 */
/* @0x12ac7c movt r2, #0x3ff0 */
/* @0x12ac80 b 0x12ac90 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12ac84 mov r3, #0 */
/* @0x12ac88 str r3, [r4, #0xc] */
/* @0x12ac8c mov r2, r3 */
/* @0x12ac90 str r3, [r4] */
/* @0x12ac94 str r2, [r4, #0x4] */
/* @0x12ac98 pop {r4, pc} */
/* @0x12ac9c eoreq r3, r12, r0, lsr #32 */

/* ── FUNC 0x12aca0 · F_ObjectGetDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x12aca0 push {r4, lr} */
/* @0x12aca4 mov r1, #0 */
/* @0x12aca8 mov r4, r0 */
/* @0x12acac ldr r0, [sp, #0x8] */
/* @0x12acb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12acb4 ldr r3, [pc, #0x74] */
/* @0x12acb8 ldr r3, [pc, r3] */
/* @0x12acbc ldr r3, [r3] */
/* @0x12acc0 ldr r2, [r3, #0x4] */
/* @0x12acc4 ldr r3, [r3] */
/* @0x12acc8 and r2, r0, r2 */
/* @0x12accc ldr r3, [r3, r2, lsl #3] */
/* @0x12acd0 cmp r3, #0 */
/* @0x12acd4 bne 0x12ace8 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12acd8 b 0x12ad14 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12acdc ldr r3, [r3, #0x4] */
/* @0x12ace0 cmp r3, #0 */
/* @0x12ace4 beq 0x12ad14 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ace8 ldr r2, [r3, #0x8] */
/* @0x12acec cmp r0, r2 */
/* @0x12acf0 bne 0x12acdc <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12acf4 ldr r3, [r3, #0xc] */
/* @0x12acf8 cmp r3, #0 */
/* @0x12acfc beq 0x12ad14 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ad00 ldr r2, [r3, #0x8] */
/* @0x12ad04 vmov s15, r2 */
/* @0x12ad08 vcvt.f64.s32 d7, s15 */
/* @0x12ad0c vmov r2, r3, d7 */
/* @0x12ad10 b 0x12ad20 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ad14 mov r3, #0 */
/* @0x12ad18 movt r3, #0xbff0 */
/* @0x12ad1c mov r2, #0 */
/* @0x12ad20 mov r1, #0 */
/* @0x12ad24 stm r4, {r2, r3} */
/* @0x12ad28 str r1, [r4, #0xc] */
/* @0x12ad2c pop {r4, pc} */
/* @0x12ad30 eoreq r2, r12, r4, lsl #31 */

/* ── FUNC 0x12ad34 · F_ObjectGetPersistent(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x12ad34 push {r4, lr} */
/* @0x12ad38 mov r1, #0 */
/* @0x12ad3c mov r4, r0 */
/* @0x12ad40 ldr r0, [sp, #0x8] */
/* @0x12ad44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ad48 ldr r3, [pc, #0x7c] */
/* @0x12ad4c ldr r3, [pc, r3] */
/* @0x12ad50 ldr r3, [r3] */
/* @0x12ad54 ldr r2, [r3, #0x4] */
/* @0x12ad58 ldr r3, [r3] */
/* @0x12ad5c and r2, r0, r2 */
/* @0x12ad60 ldr r3, [r3, r2, lsl #3] */
/* @0x12ad64 cmp r3, #0 */
/* @0x12ad68 bne 0x12ad7c <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ad6c b 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ad70 ldr r3, [r3, #0x4] */
/* @0x12ad74 cmp r3, #0 */
/* @0x12ad78 beq 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ad7c ldr r2, [r3, #0x8] */
/* @0x12ad80 cmp r0, r2 */
/* @0x12ad84 bne 0x12ad70 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12ad88 ldr r3, [r3, #0xc] */
/* @0x12ad8c cmp r3, #0 */
/* @0x12ad90 beq 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ad94 ldr r3, [r3] */
/* @0x12ad98 tst r3, #4 */
/* @0x12ad9c beq 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ada0 mov r3, #0 */
/* @0x12ada4 str r3, [r4, #0xc] */
/* @0x12ada8 mov r2, r3 */
/* @0x12adac movt r2, #0x3ff0 */
/* @0x12adb0 b 0x12adc0 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12adb4 mov r3, #0 */
/* @0x12adb8 str r3, [r4, #0xc] */
/* @0x12adbc mov r2, r3 */
/* @0x12adc0 str r3, [r4] */
/* @0x12adc4 str r2, [r4, #0x4] */
/* @0x12adc8 pop {r4, pc} */
/* @0x12adcc .word 0x002c2ef0 */

/* ── FUNC 0x12add0 · F_ObjectGetMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x12add0 push {r4, lr} */
/* @0x12add4 mov r1, #0 */
/* @0x12add8 mov r4, r0 */
/* @0x12addc ldr r0, [sp, #0x8] */
/* @0x12ade0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ade4 ldr r3, [pc, #0x74] */
/* @0x12ade8 ldr r3, [pc, r3] */
/* @0x12adec ldr r3, [r3] */
/* @0x12adf0 ldr r2, [r3, #0x4] */
/* @0x12adf4 ldr r3, [r3] */
/* @0x12adf8 and r2, r0, r2 */
/* @0x12adfc ldr r3, [r3, r2, lsl #3] */
/* @0x12ae00 cmp r3, #0 */
/* @0x12ae04 bne 0x12ae18 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ae08 b 0x12ae44 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ae0c ldr r3, [r3, #0x4] */
/* @0x12ae10 cmp r3, #0 */
/* @0x12ae14 beq 0x12ae44 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ae18 ldr r2, [r3, #0x8] */
/* @0x12ae1c cmp r0, r2 */
/* @0x12ae20 bne 0x12ae0c <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12ae24 ldr r3, [r3, #0xc] */
/* @0x12ae28 cmp r3, #0 */
/* @0x12ae2c beq 0x12ae44 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ae30 ldr r2, [r3, #0x10] */
/* @0x12ae34 vmov s15, r2 */
/* @0x12ae38 vcvt.f64.s32 d7, s15 */
/* @0x12ae3c vmov r2, r3, d7 */
/* @0x12ae40 b 0x12ae50 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12ae44 mov r3, #0 */
/* @0x12ae48 movt r3, #0xbff0 */
/* @0x12ae4c mov r2, #0 */
/* @0x12ae50 mov r1, #0 */
/* @0x12ae54 stm r4, {r2, r3} */
/* @0x12ae58 str r1, [r4, #0xc] */
/* @0x12ae5c pop {r4, pc} */
/* @0x12ae60 eoreq r2, r12, r4, asr lr */

/* ── FUNC 0x12ae64 · F_ObjectGetParent(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x12ae64 push {r4, lr} */
/* @0x12ae68 mov r1, #0 */
/* @0x12ae6c mov r4, r0 */
/* @0x12ae70 ldr r0, [sp, #0x8] */
/* @0x12ae74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ae78 ldr r3, [pc, #0x74] */
/* @0x12ae7c ldr r3, [pc, r3] */
/* @0x12ae80 ldr r3, [r3] */
/* @0x12ae84 ldr r2, [r3, #0x4] */
/* @0x12ae88 ldr r3, [r3] */
/* @0x12ae8c and r2, r0, r2 */
/* @0x12ae90 ldr r3, [r3, r2, lsl #3] */
/* @0x12ae94 cmp r3, #0 */
/* @0x12ae98 bne 0x12aeac <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ae9c b 0x12aed8 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12aea0 ldr r3, [r3, #0x4] */
/* @0x12aea4 cmp r3, #0 */
/* @0x12aea8 beq 0x12aed8 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12aeac ldr r2, [r3, #0x8] */
/* @0x12aeb0 cmp r0, r2 */
/* @0x12aeb4 bne 0x12aea0 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12aeb8 ldr r3, [r3, #0xc] */
/* @0x12aebc cmp r3, #0 */
/* @0x12aec0 beq 0x12aed8 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12aec4 ldr r2, [r3, #0xc] */
/* @0x12aec8 vmov s15, r2 */
/* @0x12aecc vcvt.f64.s32 d7, s15 */
/* @0x12aed0 vmov r2, r3, d7 */
/* @0x12aed4 b 0x12aee4 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12aed8 mov r3, #0 */
/* @0x12aedc movt r3, #0xbff0 */
/* @0x12aee0 mov r2, #0 */
/* @0x12aee4 mov r1, #0 */
/* @0x12aee8 stm r4, {r2, r3} */
/* @0x12aeec str r1, [r4, #0xc] */
/* @0x12aef0 pop {r4, pc} */
/* @0x12aef4 eoreq r2, r12, r0, asr #27 */
