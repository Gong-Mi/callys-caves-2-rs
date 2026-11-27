/* libyoyo.so 覆盖卡组 0135
 * 函数 0x1a1a44..0x1a3368，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a1a44 · Eff_Effect08(int, float, float, int, unsigned int) · size=556 · insn=139 */
/* @0x1a1a44 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a1a48 vpush {d8} */
/* @0x1a1a4c sub sp, sp, #12 */
/* @0x1a1a50 mov r4, r3 */
/* @0x1a1a54 mov r7, r1 */
/* @0x1a1a58 mov r6, r2 */
/* @0x1a1a5c mov r8, r0 */
/* @0x1a1a60 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a1a64 cmp r4, #0 */
/* @0x1a1a68 ldr r3, [pc, #0x1f8] */
/* @0x1a1a6c mov r1, #8 */
/* @0x1a1a70 ldr r2, [pc, #0x1f4] */
/* @0x1a1a74 add r3, pc, r3 */
/* @0x1a1a78 vmov s16, r0 */
/* @0x1a1a7c beq 0x1a1b40 <_Z12Eff_Effect08iffij+0xfc> */
/* @0x1a1a80 cmp r4, #2 */
/* @0x1a1a84 mov r5, #0 */
/* @0x1a1a88 ldr r4, [r3, r2] */
/* @0x1a1a8c beq 0x1a1bd0 <_Z12Eff_Effect08iffij+0x18c> */
/* @0x1a1a90 ldr r0, [r4, #0x4] */
/* @0x1a1a94 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1a98 vldr s15, [pc, #444] */
/* @0x1a1a9c vmul.f32 s15, s16, s15 */
/* @0x1a1aa0 mov r1, #1061158912 */
/* @0x1a1aa4 ldr r0, [r4, #0x4] */
/* @0x1a1aa8 mov r2, r1 */
/* @0x1a1aac str r5, [sp] */
/* @0x1a1ab0 vmov r3, s15 */
/* @0x1a1ab4 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1ab8 ldr r0, [r4, #0x4] */
/* @0x1a1abc mov r1, r5 */
/* @0x1a1ac0 str r5, [sp] */
/* @0x1a1ac4 mov r3, #0 */
/* @0x1a1ac8 mov r2, #0 */
/* @0x1a1acc str r3, [sp, #0x4] */
/* @0x1a1ad0 movt r2, #0x43b4 */
/* @0x1a1ad4 mov r3, r5 */
/* @0x1a1ad8 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1adc vmov.f32 s15, #2.500000e+01 */
/* @0x1a1ae0 ldr r9, [r4, #0x4] */
/* @0x1a1ae4 vdiv.f32 s16, s15, s16 */
/* @0x1a1ae8 vcvt.f64.f32 d8, s16 */
/* @0x1a1aec vmov r0, r1, d8 */
/* @0x1a1af0 bl 0xb66e8 <lrint@plt> */
/* @0x1a1af4 mov r5, r0 */
/* @0x1a1af8 vmov r0, r1, d8 */
/* @0x1a1afc bl 0xb66e8 <lrint@plt> */
/* @0x1a1b00 mov r1, r5 */
/* @0x1a1b04 mov r2, r0 */
/* @0x1a1b08 mov r0, r9 */
/* @0x1a1b0c bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1b10 ldr r3, [r4, #0x4] */
/* @0x1a1b14 ldr r2, [sp, #0x30] */
/* @0x1a1b18 mov r12, #1 */
/* @0x1a1b1c mov r0, r8 */
/* @0x1a1b20 mov r1, r7 */
/* @0x1a1b24 str r12, [sp, #0x4] */
/* @0x1a1b28 str r2, [sp] */
/* @0x1a1b2c mov r2, r6 */
/* @0x1a1b30 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a1b34 add sp, sp, #12 */
/* @0x1a1b38 vpop {d8} */
/* @0x1a1b3c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a1b40 ldr r5, [r3, r2] */
/* @0x1a1b44 mov r9, #0 */
/* @0x1a1b48 ldr r0, [r5] */
/* @0x1a1b4c bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1b50 vldr s15, [pc, #264] */
/* @0x1a1b54 vmul.f32 s15, s16, s15 */
/* @0x1a1b58 movw r1, #0xcccd */
/* @0x1a1b5c movt r1, #0x3ecc */
/* @0x1a1b60 ldr r0, [r5] */
/* @0x1a1b64 str r9, [sp] */
/* @0x1a1b68 mov r2, r1 */
/* @0x1a1b6c vmov r3, s15 */
/* @0x1a1b70 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1b74 mov r3, r9 */
/* @0x1a1b78 ldr r0, [r5] */
/* @0x1a1b7c mov r1, r9 */
/* @0x1a1b80 str r9, [sp] */
/* @0x1a1b84 mov r2, #0 */
/* @0x1a1b88 str r4, [sp, #0x4] */
/* @0x1a1b8c movt r2, #0x43b4 */
/* @0x1a1b90 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1b94 vmov.f32 s15, #2.000000e+01 */
/* @0x1a1b98 ldr r9, [r5] */
/* @0x1a1b9c vdiv.f32 s16, s15, s16 */
/* @0x1a1ba0 vcvt.f64.f32 d8, s16 */
/* @0x1a1ba4 vmov r0, r1, d8 */
/* @0x1a1ba8 bl 0xb66e8 <lrint@plt> */
/* @0x1a1bac mov r4, r0 */
/* @0x1a1bb0 vmov r0, r1, d8 */
/* @0x1a1bb4 bl 0xb66e8 <lrint@plt> */
/* @0x1a1bb8 mov r1, r4 */
/* @0x1a1bbc mov r2, r0 */
/* @0x1a1bc0 mov r0, r9 */
/* @0x1a1bc4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1bc8 ldr r3, [r5] */
/* @0x1a1bcc b 0x1a1b14 <_Z12Eff_Effect08iffij+0xd0> */
/* @0x1a1bd0 ldr r0, [r4, #0x8] */
/* @0x1a1bd4 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1bd8 vldr s15, [pc, #132] */
/* @0x1a1bdc vmul.f32 s15, s16, s15 */
/* @0x1a1be0 movw r1, #0x999a */
/* @0x1a1be4 movt r1, #0x3f99 */
/* @0x1a1be8 ldr r0, [r4, #0x8] */
/* @0x1a1bec str r5, [sp] */
/* @0x1a1bf0 mov r2, r1 */
/* @0x1a1bf4 vmov r3, s15 */
/* @0x1a1bf8 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1bfc ldr r0, [r4, #0x8] */
/* @0x1a1c00 mov r1, r5 */
/* @0x1a1c04 str r5, [sp] */
/* @0x1a1c08 mov r3, #0 */
/* @0x1a1c0c mov r2, #0 */
/* @0x1a1c10 str r3, [sp, #0x4] */
/* @0x1a1c14 movt r2, #0x43b4 */
/* @0x1a1c18 mov r3, r5 */
/* @0x1a1c1c bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1c20 vmov.f32 s15, #3.000000e+01 */
/* @0x1a1c24 ldr r9, [r4, #0x8] */
/* @0x1a1c28 vdiv.f32 s16, s15, s16 */
/* @0x1a1c2c vcvt.f64.f32 d8, s16 */
/* @0x1a1c30 vmov r0, r1, d8 */
/* @0x1a1c34 bl 0xb66e8 <lrint@plt> */
/* @0x1a1c38 mov r5, r0 */
/* @0x1a1c3c vmov r0, r1, d8 */
/* @0x1a1c40 bl 0xb66e8 <lrint@plt> */
/* @0x1a1c44 mov r1, r5 */
/* @0x1a1c48 mov r2, r0 */
/* @0x1a1c4c mov r0, r9 */
/* @0x1a1c50 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1c54 ldr r3, [r4, #0x8] */
/* @0x1a1c58 b 0x1a1b14 <_Z12Eff_Effect08iffij+0xd0> */
/* @0x1a1c5c ldcllt p2, c12, [r5], #572 */
/* @0x1a1c60 stclt p7, c13, [r3], #40 */
/* @0x1a1c64 stclt p7, c13, [r3, #-40]! */
/* @0x1a1c68 .word 0x002501dc */
/* @0x1a1c6c .word 0xffffeb40 */

/* ── FUNC 0x1a1c70 · Eff_Create09() · size=44 · insn=11 */
/* @0x1a1c70 push {r4, lr} */
/* @0x1a1c74 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1c78 ldr r4, [pc, #0x18] */
/* @0x1a1c7c ldr r4, [pc, r4] */
/* @0x1a1c80 str r0, [r4] */
/* @0x1a1c84 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1c88 str r0, [r4, #0x4] */
/* @0x1a1c8c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1c90 str r0, [r4, #0x8] */
/* @0x1a1c94 pop {r4, pc} */
/* @0x1a1c98 eoreq lr, r4, r8, lsl r11 */

/* ── FUNC 0x1a1c9c · Eff_Effect09(int, float, float, int, unsigned int) · size=532 · insn=133 */
/* @0x1a1c9c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a1ca0 vpush {d8} */
/* @0x1a1ca4 sub sp, sp, #12 */
/* @0x1a1ca8 mov r4, r3 */
/* @0x1a1cac mov r7, r1 */
/* @0x1a1cb0 mov r8, r0 */
/* @0x1a1cb4 mov r6, r2 */
/* @0x1a1cb8 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a1cbc cmp r4, #0 */
/* @0x1a1cc0 ldr r12, [pc, #0x1e0] */
/* @0x1a1cc4 mov r1, #10 */
/* @0x1a1cc8 ldr r3, [pc, #0x1dc] */
/* @0x1a1ccc mov r5, #0 */
/* @0x1a1cd0 add r12, pc, r12 */
/* @0x1a1cd4 vmov s16, r0 */
/* @0x1a1cd8 beq 0x1a1d98 <_Z12Eff_Effect09iffij+0xfc> */
/* @0x1a1cdc cmp r4, #2 */
/* @0x1a1ce0 ldr r4, [r12, r3] */
/* @0x1a1ce4 beq 0x1a1e20 <_Z12Eff_Effect09iffij+0x184> */
/* @0x1a1ce8 ldr r0, [r4, #0x4] */
/* @0x1a1cec bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1cf0 mov r1, #0 */
/* @0x1a1cf4 movt r1, #0x4080 */
/* @0x1a1cf8 mov r3, r5 */
/* @0x1a1cfc ldr r0, [r4, #0x4] */
/* @0x1a1d00 mov r2, r1 */
/* @0x1a1d04 str r5, [sp] */
/* @0x1a1d08 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1d0c ldr r0, [r4, #0x4] */
/* @0x1a1d10 mov r1, #1065353216 */
/* @0x1a1d14 mov r2, #1056964608 */
/* @0x1a1d18 bl 0x1a3278 <_Z18ParticleType_Scaleiff> */
/* @0x1a1d1c mov r3, r5 */
/* @0x1a1d20 mov r1, r5 */
/* @0x1a1d24 ldr r0, [r4, #0x4] */
/* @0x1a1d28 movw r2, #0x999a */
/* @0x1a1d2c movt r2, #0x3e99 */
/* @0x1a1d30 bl 0x1a36f8 <_Z19ParticleType_Alpha3ifff> */
/* @0x1a1d34 vldr s15, [pc, #360] */
/* @0x1a1d38 vdiv.f32 s16, s15, s16 */
/* @0x1a1d3c ldr r9, [r4, #0x4] */
/* @0x1a1d40 vcvt.f64.f32 d8, s16 */
/* @0x1a1d44 vmov r0, r1, d8 */
/* @0x1a1d48 bl 0xb66e8 <lrint@plt> */
/* @0x1a1d4c mov r5, r0 */
/* @0x1a1d50 vmov r0, r1, d8 */
/* @0x1a1d54 bl 0xb66e8 <lrint@plt> */
/* @0x1a1d58 mov r1, r5 */
/* @0x1a1d5c mov r2, r0 */
/* @0x1a1d60 mov r0, r9 */
/* @0x1a1d64 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1d68 ldr r3, [r4, #0x4] */
/* @0x1a1d6c ldr r2, [sp, #0x30] */
/* @0x1a1d70 mov r12, #1 */
/* @0x1a1d74 mov r0, r8 */
/* @0x1a1d78 mov r1, r7 */
/* @0x1a1d7c str r12, [sp, #0x4] */
/* @0x1a1d80 str r2, [sp] */
/* @0x1a1d84 mov r2, r6 */
/* @0x1a1d88 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a1d8c add sp, sp, #12 */
/* @0x1a1d90 vpop {d8} */
/* @0x1a1d94 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a1d98 ldr r4, [r12, r3] */
/* @0x1a1d9c ldr r0, [r4] */
/* @0x1a1da0 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1da4 mov r1, #1073741824 */
/* @0x1a1da8 mov r3, r5 */
/* @0x1a1dac ldr r0, [r4] */
/* @0x1a1db0 mov r2, r1 */
/* @0x1a1db4 str r5, [sp] */
/* @0x1a1db8 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1dbc ldr r0, [r4] */
/* @0x1a1dc0 mov r1, #1065353216 */
/* @0x1a1dc4 mov r2, #1056964608 */
/* @0x1a1dc8 bl 0x1a3278 <_Z18ParticleType_Scaleiff> */
/* @0x1a1dcc mov r3, r5 */
/* @0x1a1dd0 mov r1, r5 */
/* @0x1a1dd4 ldr r0, [r4] */
/* @0x1a1dd8 movw r2, #0x999a */
/* @0x1a1ddc movt r2, #0x3e99 */
/* @0x1a1de0 bl 0x1a36f8 <_Z19ParticleType_Alpha3ifff> */
/* @0x1a1de4 vldr s15, [pc, #184] */
/* @0x1a1de8 vdiv.f32 s16, s15, s16 */
/* @0x1a1dec ldr r9, [r4] */
/* @0x1a1df0 vcvt.f64.f32 d8, s16 */
/* @0x1a1df4 vmov r0, r1, d8 */
/* @0x1a1df8 bl 0xb66e8 <lrint@plt> */
/* @0x1a1dfc mov r5, r0 */
/* @0x1a1e00 vmov r0, r1, d8 */
/* @0x1a1e04 bl 0xb66e8 <lrint@plt> */
/* @0x1a1e08 mov r1, r5 */
/* @0x1a1e0c mov r2, r0 */
/* @0x1a1e10 mov r0, r9 */
/* @0x1a1e14 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1e18 ldr r3, [r4] */
/* @0x1a1e1c b 0x1a1d6c <_Z12Eff_Effect09iffij+0xd0> */
/* @0x1a1e20 ldr r0, [r4, #0x8] */
/* @0x1a1e24 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1e28 mov r1, #1090519040 */
/* @0x1a1e2c mov r3, r5 */
/* @0x1a1e30 ldr r0, [r4, #0x8] */
/* @0x1a1e34 mov r2, r1 */
/* @0x1a1e38 str r5, [sp] */
/* @0x1a1e3c bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1e40 ldr r0, [r4, #0x8] */
/* @0x1a1e44 mov r1, #1065353216 */
/* @0x1a1e48 mov r2, #1056964608 */
/* @0x1a1e4c bl 0x1a3278 <_Z18ParticleType_Scaleiff> */
/* @0x1a1e50 mov r3, r5 */
/* @0x1a1e54 mov r1, r5 */
/* @0x1a1e58 ldr r0, [r4, #0x8] */
/* @0x1a1e5c movw r2, #0x999a */
/* @0x1a1e60 movt r2, #0x3e99 */
/* @0x1a1e64 bl 0x1a36f8 <_Z19ParticleType_Alpha3ifff> */
/* @0x1a1e68 vldr s15, [pc, #52] */
/* @0x1a1e6c vdiv.f32 s16, s15, s16 */
/* @0x1a1e70 ldr r9, [r4, #0x8] */
/* @0x1a1e74 vcvt.f64.f32 d8, s16 */
/* @0x1a1e78 vmov r0, r1, d8 */
/* @0x1a1e7c bl 0xb66e8 <lrint@plt> */
/* @0x1a1e80 mov r5, r0 */
/* @0x1a1e84 vmov r0, r1, d8 */
/* @0x1a1e88 bl 0xb66e8 <lrint@plt> */
/* @0x1a1e8c mov r1, r5 */
/* @0x1a1e90 mov r2, r0 */
/* @0x1a1e94 mov r0, r9 */
/* @0x1a1e98 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1e9c ldr r3, [r4, #0x8] */
/* @0x1a1ea0 b 0x1a1d6c <_Z12Eff_Effect09iffij+0xd0> */
/* @0x1a1ea4 sbcmi r0, r8, #0 */
/* @0x1a1ea8 eoreq pc, r4, r0, lsl #31 */
/* @0x1a1eac .word 0xffffeb44 */

/* ── FUNC 0x1a1eb0 · Eff_Create10() · size=28 · insn=7 */
/* @0x1a1eb0 push {r3, lr} */
/* @0x1a1eb4 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a1eb8 ldr r3, [pc, #0x8] */
/* @0x1a1ebc ldr r3, [pc, r3] */
/* @0x1a1ec0 str r0, [r3] */
/* @0x1a1ec4 pop {r3, pc} */
/* @0x1a1ec8 .word 0x0024e8dc */

/* ── FUNC 0x1a1ecc · anon_1a1ecc · size=0 · insn=1 */
/* @0x1a1ecc andeq r0, r0, r0 */

/* ── FUNC 0x1a1ed0 · Eff_Effect10(int, float, float, int, unsigned int) · size=708 · insn=177 */
/* @0x1a1ed0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a1ed4 vpush {d8, d9, d10} */
/* @0x1a1ed8 sub sp, sp, #12 */
/* @0x1a1edc vldr s17, [pc, #676] */
/* @0x1a1ee0 mov r10, r3 */
/* @0x1a1ee4 mov r7, r0 */
/* @0x1a1ee8 ldr r8, [sp, #0x48] */
/* @0x1a1eec bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a1ef0 ldr r4, [pc, #0x294] */
/* @0x1a1ef4 mov r5, #0 */
/* @0x1a1ef8 mov r1, #3 */
/* @0x1a1efc mov r9, #1 */
/* @0x1a1f00 ldr r4, [pc, r4] */
/* @0x1a1f04 ldr r6, [pc, #0x284] */
/* @0x1a1f08 vmov.f64 d9, #3.000000e+01 */
/* @0x1a1f0c vmov s16, r0 */
/* @0x1a1f10 ldr r0, [r4] */
/* @0x1a1f14 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a1f18 ldr r0, [r4] */
/* @0x1a1f1c vmov r1, s17 */
/* @0x1a1f20 mov r3, r5 */
/* @0x1a1f24 str r5, [sp] */
/* @0x1a1f28 movw r2, #0x999a */
/* @0x1a1f2c movt r2, #0x3e99 */
/* @0x1a1f30 bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a1f34 ldr r0, [r4] */
/* @0x1a1f38 mov r1, r5 */
/* @0x1a1f3c mov r2, r5 */
/* @0x1a1f40 mov r3, r5 */
/* @0x1a1f44 str r5, [sp] */
/* @0x1a1f48 str r9, [sp, #0x4] */
/* @0x1a1f4c bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a1f50 vmov.f32 s15, #7.000000e+00 */
/* @0x1a1f54 ldr r0, [r4] */
/* @0x1a1f58 mov r3, r5 */
/* @0x1a1f5c str r5, [sp] */
/* @0x1a1f60 vmul.f32 s15, s16, s15 */
/* @0x1a1f64 vmov r1, s15 */
/* @0x1a1f68 vmov r2, s15 */
/* @0x1a1f6c bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a1f70 mov r1, #0 */
/* @0x1a1f74 movt r1, #0x4382 */
/* @0x1a1f78 mov r3, r5 */
/* @0x1a1f7c ldr r0, [r4] */
/* @0x1a1f80 mov r2, r1 */
/* @0x1a1f84 str r5, [sp] */
/* @0x1a1f88 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a1f8c ldr r0, [r4] */
/* @0x1a1f90 movw r1, #0xcccd */
/* @0x1a1f94 movt r1, #0x3ecc */
/* @0x1a1f98 bl 0x1a3668 <_Z19ParticleType_Alpha1if> */
/* @0x1a1f9c ldr r6, [pc, r6] */
/* @0x1a1fa0 ldr r11, [r4] */
/* @0x1a1fa4 ldr r3, [r6] */
/* @0x1a1fa8 vldr s15, [r3, #20] */
/* @0x1a1fac vcvt.f32.s32 s15, s15 */
/* @0x1a1fb0 vmul.f32 s15, s15, s17 */
/* @0x1a1fb4 vdiv.f32 s15, s15, s16 */
/* @0x1a1fb8 vcvt.f64.f32 d5, s15 */
/* @0x1a1fbc vmov r0, r1, d5 */
/* @0x1a1fc0 bl 0xb66e8 <lrint@plt> */
/* @0x1a1fc4 ldr r3, [r6] */
/* @0x1a1fc8 vldr s15, [r3, #20] */
/* @0x1a1fcc vcvt.f32.s32 s15, s15 */
/* @0x1a1fd0 vmul.f32 s17, s15, s17 */
/* @0x1a1fd4 vdiv.f32 s16, s17, s16 */
/* @0x1a1fd8 mov r5, r0 */
/* @0x1a1fdc vcvt.f64.f32 d6, s16 */
/* @0x1a1fe0 vmov r0, r1, d6 */
/* @0x1a1fe4 bl 0xb66e8 <lrint@plt> */
/* @0x1a1fe8 mov r1, r5 */
/* @0x1a1fec mov r2, r0 */
/* @0x1a1ff0 mov r0, r11 */
/* @0x1a1ff4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a1ff8 cmp r10, #0 */
/* @0x1a1ffc bne 0x1a207c <_Z12Eff_Effect10iffij+0x1ac> */
/* @0x1a2000 mov r5, #2 */
/* @0x1a2004 vldr d8, [pc, #372] */
/* @0x1a2008 mov r0, #0 */
/* @0x1a200c mov r1, #0 */
/* @0x1a2010 movt r1, #0x3ff0 */
/* @0x1a2014 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2018 ldr r3, [r6] */
/* @0x1a201c vldr s14, [r3, #16] */
/* @0x1a2020 vcvt.f64.s32 d7, s14 */
/* @0x1a2024 vmov d5, r0, r1 */
/* @0x1a2028 mov r0, #0 */
/* @0x1a202c mov r1, #0 */
/* @0x1a2030 movt r1, #0x4034 */
/* @0x1a2034 vmul.f64 d6, d5, d8 */
/* @0x1a2038 vmul.f64 d7, d6, d7 */
/* @0x1a203c vcvt.f32.f64 s20, d7 */
/* @0x1a2040 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2044 ldr r3, [r4] */
/* @0x1a2048 stm sp, {r8, r9} */
/* @0x1a204c vmov d6, r0, r1 */
/* @0x1a2050 mov r0, r7 */
/* @0x1a2054 vsub.f64 d7, d6, d9 */
/* @0x1a2058 vmov r1, s20 */
/* @0x1a205c vcvt.f32.f64 s13, d7 */
/* @0x1a2060 vmov r2, s13 */
/* @0x1a2064 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a2068 subs r5, r5, #1 */
/* @0x1a206c bne 0x1a2008 <_Z12Eff_Effect10iffij+0x138> */
/* @0x1a2070 add sp, sp, #12 */
/* @0x1a2074 vpop {d8, d9, d10} */
/* @0x1a2078 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a207c cmp r10, #2 */
/* @0x1a2080 beq 0x1a2100 <_Z12Eff_Effect10iffij+0x230> */
/* @0x1a2084 mov r5, #5 */
/* @0x1a2088 vldr d8, [pc, #240] */
/* @0x1a208c mov r0, #0 */
/* @0x1a2090 mov r1, #0 */
/* @0x1a2094 movt r1, #0x3ff0 */
/* @0x1a2098 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a209c ldr r3, [r6] */
/* @0x1a20a0 vldr s14, [r3, #16] */
/* @0x1a20a4 vcvt.f64.s32 d7, s14 */
/* @0x1a20a8 vmov d5, r0, r1 */
/* @0x1a20ac mov r0, #0 */
/* @0x1a20b0 mov r1, #0 */
/* @0x1a20b4 movt r1, #0x4034 */
/* @0x1a20b8 vmul.f64 d6, d5, d8 */
/* @0x1a20bc vmul.f64 d7, d6, d7 */
/* @0x1a20c0 vcvt.f32.f64 s20, d7 */
/* @0x1a20c4 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a20c8 ldr r3, [r4] */
/* @0x1a20cc stm sp, {r8, r9} */
/* @0x1a20d0 vmov d6, r0, r1 */
/* @0x1a20d4 mov r0, r7 */
/* @0x1a20d8 vsub.f64 d7, d6, d9 */
/* @0x1a20dc vmov r1, s20 */
/* @0x1a20e0 vcvt.f32.f64 s13, d7 */
/* @0x1a20e4 vmov r2, s13 */
/* @0x1a20e8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a20ec subs r5, r5, #1 */
/* @0x1a20f0 bne 0x1a208c <_Z12Eff_Effect10iffij+0x1bc> */
/* @0x1a20f4 add sp, sp, #12 */
/* @0x1a20f8 vpop {d8, d9, d10} */
/* @0x1a20fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a2100 mov r5, #9 */
/* @0x1a2104 vldr d8, [pc, #116] */
/* @0x1a2108 mov r0, #0 */
/* @0x1a210c mov r1, #0 */
/* @0x1a2110 movt r1, #0x3ff0 */
/* @0x1a2114 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2118 ldr r3, [r6] */
/* @0x1a211c vldr s14, [r3, #16] */
/* @0x1a2120 vcvt.f64.s32 d7, s14 */
/* @0x1a2124 vmov d5, r0, r1 */
/* @0x1a2128 mov r0, #0 */
/* @0x1a212c mov r1, #0 */
/* @0x1a2130 movt r1, #0x4034 */
/* @0x1a2134 vmul.f64 d6, d5, d8 */
/* @0x1a2138 vmul.f64 d7, d6, d7 */
/* @0x1a213c vcvt.f32.f64 s20, d7 */
/* @0x1a2140 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2144 ldr r3, [r4] */
/* @0x1a2148 stm sp, {r8, r9} */
/* @0x1a214c vmov d6, r0, r1 */
/* @0x1a2150 mov r0, r7 */
/* @0x1a2154 vsub.f64 d7, d6, d9 */
/* @0x1a2158 vmov r1, s20 */
/* @0x1a215c vcvt.f32.f64 s13, d7 */
/* @0x1a2160 vmov r2, s13 */
/* @0x1a2164 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a2168 subs r5, r5, #1 */
/* @0x1a216c bne 0x1a2108 <_Z12Eff_Effect10iffij+0x238> */
/* @0x1a2170 add sp, sp, #12 */
/* @0x1a2174 vpop {d8, d9, d10} */
/* @0x1a2178 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a217c nop */
/* @0x1a2180 andmi r0, r0, r0 */
/* @0x1a2184 svclo #0xf33333 */
/* @0x1a2188 cdplo p12, #0x4, c12, c12, c13, #0x6 */
/* @0x1a218c mlaeq r4, r8, r8, lr */
/* @0x1a2190 eoreq r11, r4, r12, lsl #19 */

/* ── FUNC 0x1a2194 · anon_1a2194 · size=0 · insn=1 */
/* @0x1a2194 nop */

/* ── FUNC 0x1a2198 · Eff_Create11() · size=28 · insn=7 */
/* @0x1a2198 push {r3, lr} */
/* @0x1a219c bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x1a21a0 ldr r3, [pc, #0x8] */
/* @0x1a21a4 ldr r3, [pc, r3] */
/* @0x1a21a8 str r0, [r3] */
/* @0x1a21ac pop {r3, pc} */
/* @0x1a21b0 .word 0x0024e5f8 */

/* ── FUNC 0x1a21b4 · anon_1a21b4 · size=0 · insn=1 */
/* @0x1a21b4 andeq r0, r0, r0 */

/* ── FUNC 0x1a21b8 · Eff_Effect11(int, float, float, int, unsigned int) · size=752 · insn=188 */
/* @0x1a21b8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a21bc vpush {d8, d9, d10, d11} */
/* @0x1a21c0 sub sp, sp, #8 */
/* @0x1a21c4 mov r9, r3 */
/* @0x1a21c8 mov r7, r0 */
/* @0x1a21cc ldr r8, [sp, #0x48] */
/* @0x1a21d0 bl 0x19ff6c <_Z12Speed_Factorv> */
/* @0x1a21d4 ldr r4, [pc, #0x2c4] */
/* @0x1a21d8 mov r5, #0 */
/* @0x1a21dc mov r1, #13 */
/* @0x1a21e0 ldr r6, [pc, #0x2bc] */
/* @0x1a21e4 ldr r4, [pc, r4] */
/* @0x1a21e8 vmov s16, r0 */
/* @0x1a21ec ldr r0, [r4] */
/* @0x1a21f0 bl 0x1a31a4 <_Z18ParticleType_Shapeii> */
/* @0x1a21f4 mov r3, r5 */
/* @0x1a21f8 ldr r0, [r4] */
/* @0x1a21fc mov r2, #1048576000 */
/* @0x1a2200 str r5, [sp] */
/* @0x1a2204 movw r1, #0xcccd */
/* @0x1a2208 movt r1, #0x3dcc */
/* @0x1a220c bl 0x1a322c <_Z17ParticleType_Sizeiffff> */
/* @0x1a2210 ldr r0, [r4] */
/* @0x1a2214 movw r1, #0x999a */
/* @0x1a2218 movt r1, #0x3f19 */
/* @0x1a221c bl 0x1a3668 <_Z19ParticleType_Alpha1if> */
/* @0x1a2220 ldr r0, [r4] */
/* @0x1a2224 mov r1, r5 */
/* @0x1a2228 mov r3, r5 */
/* @0x1a222c str r5, [sp] */
/* @0x1a2230 mov r2, #0 */
/* @0x1a2234 str r2, [sp, #0x4] */
/* @0x1a2238 mov r2, #0 */
/* @0x1a223c movt r2, #0x43b4 */
/* @0x1a2240 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x1a2244 vmov.f32 s14, #2.500000e+00 */
/* @0x1a2248 ldr r0, [r4] */
/* @0x1a224c mov r3, r5 */
/* @0x1a2250 str r5, [sp] */
/* @0x1a2254 vmov.f32 s15, #3.000000e+00 */
/* @0x1a2258 vmul.f32 s14, s16, s14 */
/* @0x1a225c vmul.f32 s15, s16, s15 */
/* @0x1a2260 vmov r1, s14 */
/* @0x1a2264 vmov r2, s15 */
/* @0x1a2268 bl 0x1a3368 <_Z18ParticleType_Speediffff> */
/* @0x1a226c ldr r0, [r4] */
/* @0x1a2270 mov r3, r5 */
/* @0x1a2274 mov r1, #0 */
/* @0x1a2278 mov r2, #0 */
/* @0x1a227c movt r1, #0x4370 */
/* @0x1a2280 movt r2, #0x4396 */
/* @0x1a2284 mov r12, #0 */
/* @0x1a2288 movt r12, #0x41a0 */
/* @0x1a228c str r12, [sp] */
/* @0x1a2290 bl 0x1a33b4 <_Z22ParticleType_Directioniffff> */
/* @0x1a2294 ldr r6, [pc, r6] */
/* @0x1a2298 ldr r10, [r4] */
/* @0x1a229c ldr r3, [r6] */
/* @0x1a22a0 vldr s15, [r3, #20] */
/* @0x1a22a4 vcvt.f32.s32 s15, s15, #1 */
/* @0x1a22a8 vdiv.f32 s15, s15, s16 */
/* @0x1a22ac vcvt.f64.f32 d4, s15 */
/* @0x1a22b0 vmov r0, r1, d4 */
/* @0x1a22b4 bl 0xb66e8 <lrint@plt> */
/* @0x1a22b8 ldr r3, [r6] */
/* @0x1a22bc vcvt.f64.f32 d7, s16 */
/* @0x1a22c0 ldr r3, [r3, #0x14] */
/* @0x1a22c4 vmov s12, r3 */
/* @0x1a22c8 vcvt.f64.s32 d6, d6, #1 */
/* @0x1a22cc vdiv.f64 d5, d6, d7 */
/* @0x1a22d0 mov r5, r0 */
/* @0x1a22d4 vmov r0, r1, d5 */
/* @0x1a22d8 bl 0xb66e8 <lrint@plt> */
/* @0x1a22dc mov r1, r5 */
/* @0x1a22e0 mov r2, r0 */
/* @0x1a22e4 mov r0, r10 */
/* @0x1a22e8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii> */
/* @0x1a22ec cmp r9, #0 */
/* @0x1a22f0 bne 0x1a2374 <_Z12Eff_Effect11iffij+0x1bc> */
/* @0x1a22f4 mov r0, #0 */
/* @0x1a22f8 mov r1, #0 */
/* @0x1a22fc movt r1, #0x3ff0 */
/* @0x1a2300 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2304 vldr d5, [pc, #388] */
/* @0x1a2308 ldr r3, [r6] */
/* @0x1a230c vldr s12, [r3, #16] */
/* @0x1a2310 vcvt.f64.s32 d6, s12 */
/* @0x1a2314 vldr d7, [pc, #380] */
/* @0x1a2318 vmov d4, r0, r1 */
/* @0x1a231c mov r0, #0 */
/* @0x1a2320 mov r1, #0 */
/* @0x1a2324 movt r1, #0x4034 */
/* @0x1a2328 vmul.f64 d5, d4, d5 */
/* @0x1a232c vnmls.f64 d7, d5, d6 */
/* @0x1a2330 vcvt.f32.f64 s16, d7 */
/* @0x1a2334 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2338 ldr r3, [r4] */
/* @0x1a233c mov r2, #1 */
/* @0x1a2340 str r8, [sp] */
/* @0x1a2344 str r2, [sp, #0x4] */
/* @0x1a2348 vmov.f64 d6, #3.000000e+01 */
/* @0x1a234c vmov d5, r0, r1 */
/* @0x1a2350 mov r0, r7 */
/* @0x1a2354 vsub.f64 d6, d5, d6 */
/* @0x1a2358 vmov r1, s16 */
/* @0x1a235c vcvt.f32.f64 s11, d6 */
/* @0x1a2360 vmov r2, s11 */
/* @0x1a2364 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a2368 add sp, sp, #8 */
/* @0x1a236c vpop {d8, d9, d10, d11} */
/* @0x1a2370 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a2374 cmp r9, #2 */
/* @0x1a2378 vmov.f64 d10, #3.000000e+01 */
/* @0x1a237c beq 0x1a2408 <_Z12Eff_Effect11iffij+0x250> */
/* @0x1a2380 mov r5, #3 */
/* @0x1a2384 mov r9, #1 */
/* @0x1a2388 vldr d9, [pc, #256] */
/* @0x1a238c vldr d8, [pc, #260] */
/* @0x1a2390 mov r0, #0 */
/* @0x1a2394 mov r1, #0 */
/* @0x1a2398 movt r1, #0x3ff0 */
/* @0x1a239c bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a23a0 ldr r3, [r6] */
/* @0x1a23a4 vldr s14, [r3, #16] */
/* @0x1a23a8 vcvt.f64.s32 d7, s14 */
/* @0x1a23ac vmov.f64 d5, d8 */
/* @0x1a23b0 vmov d4, r0, r1 */
/* @0x1a23b4 mov r0, #0 */
/* @0x1a23b8 mov r1, #0 */
/* @0x1a23bc movt r1, #0x4034 */
/* @0x1a23c0 vmul.f64 d6, d4, d9 */
/* @0x1a23c4 vnmls.f64 d5, d6, d7 */
/* @0x1a23c8 vcvt.f32.f64 s22, d5 */
/* @0x1a23cc bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a23d0 ldr r3, [r4] */
/* @0x1a23d4 stm sp, {r8, r9} */
/* @0x1a23d8 vmov d6, r0, r1 */
/* @0x1a23dc mov r0, r7 */
/* @0x1a23e0 vsub.f64 d7, d6, d10 */
/* @0x1a23e4 vmov r1, s22 */
/* @0x1a23e8 vcvt.f32.f64 s13, d7 */
/* @0x1a23ec vmov r2, s13 */
/* @0x1a23f0 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a23f4 subs r5, r5, #1 */
/* @0x1a23f8 bne 0x1a2390 <_Z12Eff_Effect11iffij+0x1d8> */
/* @0x1a23fc add sp, sp, #8 */
/* @0x1a2400 vpop {d8, d9, d10, d11} */
/* @0x1a2404 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a2408 mov r5, #7 */
/* @0x1a240c mov r9, #1 */
/* @0x1a2410 vldr d9, [pc, #120] */
/* @0x1a2414 vldr d8, [pc, #124] */
/* @0x1a2418 mov r0, #0 */
/* @0x1a241c mov r1, #0 */
/* @0x1a2420 movt r1, #0x3ff0 */
/* @0x1a2424 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2428 ldr r3, [r6] */
/* @0x1a242c vldr s14, [r3, #16] */
/* @0x1a2430 vcvt.f64.s32 d7, s14 */
/* @0x1a2434 vmov.f64 d5, d8 */
/* @0x1a2438 vmov d4, r0, r1 */
/* @0x1a243c mov r0, #0 */
/* @0x1a2440 mov r1, #0 */
/* @0x1a2444 movt r1, #0x4034 */
/* @0x1a2448 vmul.f64 d6, d4, d9 */
/* @0x1a244c vnmls.f64 d5, d6, d7 */
/* @0x1a2450 vcvt.f32.f64 s22, d5 */
/* @0x1a2454 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2458 ldr r3, [r4] */
/* @0x1a245c stm sp, {r8, r9} */
/* @0x1a2460 vmov d6, r0, r1 */
/* @0x1a2464 mov r0, r7 */
/* @0x1a2468 vsub.f64 d7, d6, d10 */
/* @0x1a246c vmov r1, s22 */
/* @0x1a2470 vcvt.f32.f64 s13, d7 */
/* @0x1a2474 vmov r2, s13 */
/* @0x1a2478 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji> */
/* @0x1a247c subs r5, r5, #1 */
/* @0x1a2480 bne 0x1a2418 <_Z12Eff_Effect11iffij+0x260> */
/* @0x1a2484 add sp, sp, #8 */
/* @0x1a2488 vpop {d8, d9, d10, d11} */
/* @0x1a248c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a2490 andmi r0, r0, r0 */
/* @0x1a2494 svclo #0xf33333 */
/* @0x1a2498 andeq r0, r0, r0 */
/* @0x1a249c submi r0, lr, r0 */
/* @0x1a24a0 .word 0x0024e5b8 */
/* @0x1a24a4 mlaeq r4, r4, r6, r11 */

/* ── FUNC 0x1a24a8 · Eff_Create_Types() · size=76 · insn=19 */
/* @0x1a24a8 push {r3, lr} */
/* @0x1a24ac mov r2, #1 */
/* @0x1a24b0 ldr r3, [pc, #0x38] */
/* @0x1a24b4 ldr r3, [pc, r3] */
/* @0x1a24b8 strb r2, [r3] */
/* @0x1a24bc bl 0x1a0030 <_Z12Eff_Create00v> */
/* @0x1a24c0 bl 0x1a05e8 <_Z12Eff_Create01v> */
/* @0x1a24c4 bl 0x1a081c <_Z12Eff_Create02v> */
/* @0x1a24c8 bl 0x1a0a84 <_Z12Eff_Create03v> */
/* @0x1a24cc bl 0x1a0e38 <_Z12Eff_Create04v> */
/* @0x1a24d0 bl 0x1a1168 <_Z12Eff_Create05v> */
/* @0x1a24d4 bl 0x1a1564 <_Z12Eff_Create06v> */
/* @0x1a24d8 bl 0x1a17c0 <_Z12Eff_Create07v> */
/* @0x1a24dc bl 0x1a1a18 <_Z12Eff_Create08v> */
/* @0x1a24e0 bl 0x1a1c70 <_Z12Eff_Create09v> */
/* @0x1a24e4 bl 0x1a1eb0 <_Z12Eff_Create10v> */
/* @0x1a24e8 pop {r3, lr} */
/* @0x1a24ec b 0x1a2198 <_Z12Eff_Create11v> */
/* @0x1a24f0 eoreq lr, r4, r12, ror #5 */

/* ── FUNC 0x1a24f4 · Eff_Check_Systems() · size=220 · insn=55 */
/* @0x1a24f4 push {r3, r4, r5, lr} */
/* @0x1a24f8 ldr r4, [pc, #0xbc] */
/* @0x1a24fc ldr r3, [pc, #0xbc] */
/* @0x1a2500 add r4, pc, r4 */
/* @0x1a2504 ldr r5, [r4, r3] */
/* @0x1a2508 ldr r0, [r5] */
/* @0x1a250c bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a2510 cmp r0, #0 */
/* @0x1a2514 beq 0x1a2584 <_Z17Eff_Check_Systemsv+0x90> */
/* @0x1a2518 ldr r3, [pc, #0xa4] */
/* @0x1a251c ldr r5, [r4, r3] */
/* @0x1a2520 ldr r0, [r5] */
/* @0x1a2524 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a2528 cmp r0, #0 */
/* @0x1a252c beq 0x1a254c <_Z17Eff_Check_Systemsv+0x58> */
/* @0x1a2530 ldr r3, [pc, #0x90] */
/* @0x1a2534 ldr r3, [r4, r3] */
/* @0x1a2538 ldrb r3, [r3] */
/* @0x1a253c cmp r3, #0 */
/* @0x1a2540 popne {r3, r4, r5, pc} */
/* @0x1a2544 pop {r3, r4, r5, lr} */
/* @0x1a2548 b 0x1a24a8 <_Z16Eff_Create_Typesv> */
/* @0x1a254c mov r1, #1 */
/* @0x1a2550 mvn r0, #0 */
/* @0x1a2554 bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x1a2558 ldr r3, [pc, #0x6c] */
/* @0x1a255c str r0, [r5] */
/* @0x1a2560 ldr r3, [r4, r3] */
/* @0x1a2564 ldrb r3, [r3] */
/* @0x1a2568 cmp r3, #0 */
/* @0x1a256c movne r1, #24576 */
/* @0x1a2570 moveq r1, #20480 */
/* @0x1a2574 movtne r1, #0xc66a */
/* @0x1a2578 movteq r1, #0xc7c3 */
/* @0x1a257c bl 0x1a47d4 <_Z20ParticleSystem_Depthif> */
/* @0x1a2580 b 0x1a2530 <_Z17Eff_Check_Systemsv+0x3c> */
/* @0x1a2584 mov r1, #1 */
/* @0x1a2588 mvn r0, #0 */
/* @0x1a258c bl 0x1a42dc <_Z21ParticleSystem_Createib> */
/* @0x1a2590 ldr r3, [pc, #0x34] */
/* @0x1a2594 str r0, [r5] */
/* @0x1a2598 ldr r3, [r4, r3] */
/* @0x1a259c ldrb r3, [r3] */
/* @0x1a25a0 cmp r3, #0 */
/* @0x1a25a4 movne r1, #0 */
/* @0x1a25a8 moveq r1, #20480 */
/* @0x1a25ac movtne r1, #0x4248 */
/* @0x1a25b0 movteq r1, #0x47c3 */
/* @0x1a25b4 bl 0x1a47d4 <_Z20ParticleSystem_Depthif> */
/* @0x1a25b8 b 0x1a2518 <_Z17Eff_Check_Systemsv+0x24> */
/* @0x1a25bc eoreq pc, r4, r0, asr r7 */
/* @0x1a25c0 .word 0xffffeb54 */
/* @0x1a25c4 .word 0xffffeb58 */
/* @0x1a25c8 .word 0xffffeb50 */
/* @0x1a25cc .word 0xffffbcd4 */

/* ── FUNC 0x1a25d0 · Effect_Create(bool, int, float, float, int, unsigned int) · size=428 · insn=107 */
/* @0x1a25d0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a25d4 mov r5, r0 */
/* @0x1a25d8 mov r4, r1 */
/* @0x1a25dc mov r9, r2 */
/* @0x1a25e0 ldr r6, [sp, #0x20] */
/* @0x1a25e4 mov r8, r3 */
/* @0x1a25e8 ldr r7, [sp, #0x24] */
/* @0x1a25ec bl 0x1a24f4 <_Z17Eff_Check_Systemsv> */
/* @0x1a25f0 cmp r5, #0 */
/* @0x1a25f4 beq 0x1a2640 <_Z13Effect_Createbiffij+0x70> */
/* @0x1a25f8 ldr r0, [pc, #0x174] */
/* @0x1a25fc ldr r0, [pc, r0] */
/* @0x1a2600 ldr r0, [r0] */
/* @0x1a2604 cmp r4, #11 */
/* @0x1a2608 addls pc, pc, r4, lsl #2 */
/* @0x1a260c b 0x1a2770 <_Z13Effect_Createbiffij+0x1a0> */
/* @0x1a2610 b 0x1a2668 <_Z13Effect_Createbiffij+0x98> */
/* @0x1a2614 b 0x1a2680 <_Z13Effect_Createbiffij+0xb0> */
/* @0x1a2618 b 0x1a2698 <_Z13Effect_Createbiffij+0xc8> */
/* @0x1a261c b 0x1a26b0 <_Z13Effect_Createbiffij+0xe0> */
/* @0x1a2620 b 0x1a26c8 <_Z13Effect_Createbiffij+0xf8> */
/* @0x1a2624 b 0x1a26e0 <_Z13Effect_Createbiffij+0x110> */
/* @0x1a2628 b 0x1a26f8 <_Z13Effect_Createbiffij+0x128> */
/* @0x1a262c b 0x1a2710 <_Z13Effect_Createbiffij+0x140> */
/* @0x1a2630 b 0x1a2728 <_Z13Effect_Createbiffij+0x158> */
/* @0x1a2634 b 0x1a2740 <_Z13Effect_Createbiffij+0x170> */
/* @0x1a2638 b 0x1a2758 <_Z13Effect_Createbiffij+0x188> */
/* @0x1a263c b 0x1a2650 <_Z13Effect_Createbiffij+0x80> */
/* @0x1a2640 ldr r0, [pc, #0x130] */
/* @0x1a2644 ldr r0, [pc, r0] */
/* @0x1a2648 ldr r0, [r0] */
/* @0x1a264c b 0x1a2604 <_Z13Effect_Createbiffij+0x34> */
/* @0x1a2650 str r7, [sp, #0x20] */
/* @0x1a2654 mov r1, r9 */
/* @0x1a2658 mov r3, r6 */
/* @0x1a265c mov r2, r8 */
/* @0x1a2660 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a2664 b 0x1a21b8 <_Z12Eff_Effect11iffij> */
/* @0x1a2668 str r7, [sp, #0x20] */
/* @0x1a266c mov r1, r9 */
/* @0x1a2670 mov r3, r6 */
/* @0x1a2674 mov r2, r8 */
/* @0x1a2678 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a267c b 0x1a005c <_Z12Eff_Effect00iffij> */
/* @0x1a2680 str r7, [sp, #0x20] */
/* @0x1a2684 mov r1, r9 */
/* @0x1a2688 mov r3, r6 */
/* @0x1a268c mov r2, r8 */
/* @0x1a2690 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a2694 b 0x1a0614 <_Z12Eff_Effect01iffij> */
/* @0x1a2698 str r7, [sp, #0x20] */
/* @0x1a269c mov r1, r9 */
/* @0x1a26a0 mov r3, r6 */
/* @0x1a26a4 mov r2, r8 */
/* @0x1a26a8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a26ac b 0x1a0848 <_Z12Eff_Effect02iffij> */
/* @0x1a26b0 str r7, [sp, #0x20] */
/* @0x1a26b4 mov r1, r9 */
/* @0x1a26b8 mov r3, r6 */
/* @0x1a26bc mov r2, r8 */
/* @0x1a26c0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a26c4 b 0x1a0ab0 <_Z12Eff_Effect03iffij> */
/* @0x1a26c8 str r7, [sp, #0x20] */
/* @0x1a26cc mov r1, r9 */
/* @0x1a26d0 mov r3, r6 */
/* @0x1a26d4 mov r2, r8 */
/* @0x1a26d8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a26dc b 0x1a0e64 <_Z12Eff_Effect04iffij> */
/* @0x1a26e0 str r7, [sp, #0x20] */
/* @0x1a26e4 mov r1, r9 */
/* @0x1a26e8 mov r3, r6 */
/* @0x1a26ec mov r2, r8 */
/* @0x1a26f0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a26f4 b 0x1a1194 <_Z12Eff_Effect05iffij> */
/* @0x1a26f8 str r7, [sp, #0x20] */
/* @0x1a26fc mov r1, r9 */
/* @0x1a2700 mov r3, r6 */
/* @0x1a2704 mov r2, r8 */
/* @0x1a2708 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a270c b 0x1a1590 <_Z12Eff_Effect06iffij> */
/* @0x1a2710 str r7, [sp, #0x20] */
/* @0x1a2714 mov r1, r9 */
/* @0x1a2718 mov r3, r6 */
/* @0x1a271c mov r2, r8 */
/* @0x1a2720 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a2724 b 0x1a17ec <_Z12Eff_Effect07iffij> */
/* @0x1a2728 str r7, [sp, #0x20] */
/* @0x1a272c mov r1, r9 */
/* @0x1a2730 mov r3, r6 */
/* @0x1a2734 mov r2, r8 */
/* @0x1a2738 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a273c b 0x1a1a44 <_Z12Eff_Effect08iffij> */
/* @0x1a2740 str r7, [sp, #0x20] */
/* @0x1a2744 mov r1, r9 */
/* @0x1a2748 mov r3, r6 */
/* @0x1a274c mov r2, r8 */
/* @0x1a2750 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a2754 b 0x1a1c9c <_Z12Eff_Effect09iffij> */
/* @0x1a2758 str r7, [sp, #0x20] */
/* @0x1a275c mov r1, r9 */
/* @0x1a2760 mov r3, r6 */
/* @0x1a2764 mov r2, r8 */
/* @0x1a2768 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a276c b 0x1a1ed0 <_Z12Eff_Effect10iffij> */
/* @0x1a2770 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a2774 eoreq lr, r4, r8, lsr #3 */
/* @0x1a2778 eoreq lr, r4, r4, ror #2 */

/* ── FUNC 0x1a277c · Effect_Clear() · size=48 · insn=12 */
/* @0x1a277c push {r3, lr} */
/* @0x1a2780 ldr r3, [pc, #0x1c] */
/* @0x1a2784 ldr r3, [pc, r3] */
/* @0x1a2788 ldr r0, [r3] */
/* @0x1a278c bl 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari> */
/* @0x1a2790 ldr r3, [pc, #0x10] */
/* @0x1a2794 ldr r3, [pc, r3] */
/* @0x1a2798 ldr r0, [r3] */
/* @0x1a279c pop {r3, lr} */
/* @0x1a27a0 b 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari> */
/* @0x1a27a4 eoreq lr, r4, r0, lsr #32 */
/* @0x1a27a8 eoreq lr, r4, r4, lsl r0 */

/* ── FUNC 0x1a27ac · MyRandom(float, float, int) · size=372 · insn=93 */
/* @0x1a27ac push {r3, lr} */
/* @0x1a27b0 vpush {d8, d9, d10, d11, d12} */
/* @0x1a27b4 vmov s10, r1 */
/* @0x1a27b8 vmov s20, r0 */
/* @0x1a27bc vsub.f32 s21, s10, s20 */
/* @0x1a27c0 vcmpe.f32 s21, #0 */
/* @0x1a27c4 vmrs APSR_nzcv, fpscr */
/* @0x1a27c8 bls 0x1a2800 <_Z8MyRandomffi+0x54> */
/* @0x1a27cc cmp r2, #1 */
/* @0x1a27d0 beq 0x1a2898 <_Z8MyRandomffi+0xec> */
/* @0x1a27d4 cmp r2, #2 */
/* @0x1a27d8 beq 0x1a280c <_Z8MyRandomffi+0x60> */
/* @0x1a27dc mov r0, #0 */
/* @0x1a27e0 mov r1, #0 */
/* @0x1a27e4 movt r1, #0x3ff0 */
/* @0x1a27e8 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a27ec vcvt.f64.f32 d7, s20 */
/* @0x1a27f0 vcvt.f64.f32 d6, s21 */
/* @0x1a27f4 vmov d5, r0, r1 */
/* @0x1a27f8 vmla.f64 d7, d5, d6 */
/* @0x1a27fc vcvt.f32.f64 s20, d7 */
/* @0x1a2800 vmov r0, s20 */
/* @0x1a2804 vpop {d8, d9, d10, d11, d12} */
/* @0x1a2808 pop {r3, pc} */
/* @0x1a280c vmov.f64 d9, #5.000000e-01 */
/* @0x1a2810 vmov.f64 d8, #6.000000e+00 */
/* @0x1a2814 vmov.f32 s24, #5.000000e-01 */
/* @0x1a2818 mov r0, #0 */
/* @0x1a281c mov r1, #0 */
/* @0x1a2820 movt r1, #0x3ff0 */
/* @0x1a2824 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2828 vmov d6, r0, r1 */
/* @0x1a282c vsub.f64 d7, d6, d9 */
/* @0x1a2830 vmul.f64 d7, d7, d8 */
/* @0x1a2834 vcvt.f32.f64 s22, d7 */
/* @0x1a2838 vnmul.f32 s15, s22, s22 */
/* @0x1a283c vmul.f32 s15, s15, s24 */
/* @0x1a2840 vmov r0, s15 */
/* @0x1a2844 bl 0xb6988 <expf@plt> */
/* @0x1a2848 mov r1, #0 */
/* @0x1a284c movt r1, #0x3ff0 */
/* @0x1a2850 vmov s23, r0 */
/* @0x1a2854 mov r0, #0 */
/* @0x1a2858 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a285c vcvt.f64.f32 d7, s23 */
/* @0x1a2860 vmov d5, r0, r1 */
/* @0x1a2864 vcmpe.f64 d7, d5 */
/* @0x1a2868 vmrs APSR_nzcv, fpscr */
/* @0x1a286c ble 0x1a2818 <_Z8MyRandomffi+0x6c> */
/* @0x1a2870 vcmpe.f32 s22, #0 */
/* @0x1a2874 vldr s14, [pc, #160] */
/* @0x1a2878 vmrs APSR_nzcv, fpscr */
/* @0x1a287c vmovmi.f32 s15, #6.000000e+00 */
/* @0x1a2880 vaddmi.f32 s22, s22, s15 */
/* @0x1a2884 vmul.f32 s22, s22, s14 */
/* @0x1a2888 vmla.f32 s20, s22, s21 */
/* @0x1a288c vmov r0, s20 */
/* @0x1a2890 vpop {d8, d9, d10, d11, d12} */
/* @0x1a2894 pop {r3, pc} */
/* @0x1a2898 vmov.f64 d9, #5.000000e-01 */
/* @0x1a289c vmov.f64 d8, #6.000000e+00 */
/* @0x1a28a0 vmov.f32 s24, #5.000000e-01 */
/* @0x1a28a4 mov r0, #0 */
/* @0x1a28a8 mov r1, #0 */
/* @0x1a28ac movt r1, #0x3ff0 */
/* @0x1a28b0 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a28b4 vmov d6, r0, r1 */
/* @0x1a28b8 vsub.f64 d7, d6, d9 */
/* @0x1a28bc vmul.f64 d7, d7, d8 */
/* @0x1a28c0 vcvt.f32.f64 s22, d7 */
/* @0x1a28c4 vnmul.f32 s15, s22, s22 */
/* @0x1a28c8 vmul.f32 s15, s15, s24 */
/* @0x1a28cc vmov r0, s15 */
/* @0x1a28d0 bl 0xb6988 <expf@plt> */
/* @0x1a28d4 mov r1, #0 */
/* @0x1a28d8 movt r1, #0x3ff0 */
/* @0x1a28dc vmov s23, r0 */
/* @0x1a28e0 mov r0, #0 */
/* @0x1a28e4 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a28e8 vcvt.f64.f32 d7, s23 */
/* @0x1a28ec vmov d5, r0, r1 */
/* @0x1a28f0 vcmpe.f64 d7, d5 */
/* @0x1a28f4 vmrs APSR_nzcv, fpscr */
/* @0x1a28f8 ble 0x1a28a4 <_Z8MyRandomffi+0xf8> */
/* @0x1a28fc vmov.f32 s14, #3.000000e+00 */
/* @0x1a2900 vldr s15, [pc, #20] */
/* @0x1a2904 vadd.f32 s22, s22, s14 */
/* @0x1a2908 vmul.f32 s22, s22, s15 */
/* @0x1a290c vmla.f32 s20, s22, s21 */
/* @0x1a2910 vmov r0, s20 */
/* @0x1a2914 vpop {d8, d9, d10, d11, d12} */
/* @0x1a2918 pop {r3, pc} */
/* @0x1a291c vmullo.f32 s20, s21, s23 */

/* ── FUNC 0x1a2920 · Vector_To_Direction(float, float, float*, float*) · size=280 · insn=70 */
/* @0x1a2920 push {r3, r4, r5, lr} */
/* @0x1a2924 vpush {d8, d9} */
/* @0x1a2928 vmov s16, r0 */
/* @0x1a292c mov r4, r2 */
/* @0x1a2930 mov r5, r3 */
/* @0x1a2934 vcmp.f32 s16, #0 */
/* @0x1a2938 vmov s17, r1 */
/* @0x1a293c vmrs APSR_nzcv, fpscr */
/* @0x1a2940 bne 0x1a299c <_Z19Vector_To_DirectionffPfS_+0x7c> */
/* @0x1a2944 vcmpe.f32 s17, #0 */
/* @0x1a2948 vmrs APSR_nzcv, fpscr */
/* @0x1a294c ble 0x1a2980 <_Z19Vector_To_DirectionffPfS_+0x60> */
/* @0x1a2950 vldr s15, [pc, #204] */
/* @0x1a2954 vstr s15, [r2] */
/* @0x1a2958 vmul.f32 s14, s17, s17 */
/* @0x1a295c vstr s15, [r4] */
/* @0x1a2960 vmla.f32 s14, s16, s16 */
/* @0x1a2964 vsqrt.f32 s15, s14 */
/* @0x1a2968 vcmp.f32 s15, s15 */
/* @0x1a296c vmrs APSR_nzcv, fpscr */
/* @0x1a2970 bne 0x1a2a14 <_Z19Vector_To_DirectionffPfS_+0xf4> */
/* @0x1a2974 vpop {d8, d9} */
/* @0x1a2978 vstr s15, [r5] */
/* @0x1a297c pop {r3, r4, r5, pc} */
/* @0x1a2980 bmi 0x1a2a08 <_Z19Vector_To_DirectionffPfS_+0xe8> */
/* @0x1a2984 mov r4, #0 */
/* @0x1a2988 vldr s18, [pc, #152] */
/* @0x1a298c vldr s19, [r4] */
/* @0x1a2990 vdiv.f32 s14, s19, s18 */
/* @0x1a2994 vmov r0, s14 */
/* @0x1a2998 b 0x1a29ec <_Z19Vector_To_DirectionffPfS_+0xcc> */
/* @0x1a299c mov r0, r1 */
/* @0x1a29a0 vmov r1, s16 */
/* @0x1a29a4 bl 0xb6778 <atan2f@plt> */
/* @0x1a29a8 vldr s19, [pc, #124] */
/* @0x1a29ac vldr s14, [pc, #124] */
/* @0x1a29b0 vmov s15, r0 */
/* @0x1a29b4 vmul.f32 s19, s15, s19 */
/* @0x1a29b8 vdiv.f32 s19, s19, s14 */
/* @0x1a29bc vcmpe.f32 s19, #0 */
/* @0x1a29c0 vmrs APSR_nzcv, fpscr */
/* @0x1a29c4 vldrhi s18, [pc, #92] */
/* @0x1a29c8 vsubhi.f32 s19, s18, s19 */
/* @0x1a29cc vldrls s18, [pc, #84] */
/* @0x1a29d0 vnegls.f32 s19, s19 */
/* @0x1a29d4 vstrhi s19, [r4] */
/* @0x1a29d8 vdivls.f32 s14, s19, s18 */
/* @0x1a29dc vstrls s19, [r4] */
/* @0x1a29e0 vdivhi.f32 s15, s19, s18 */
/* @0x1a29e4 vmovls r0, s14 */
/* @0x1a29e8 vmovhi r0, s15 */
/* @0x1a29ec bl 0xb6910 <floorf@plt> */
/* @0x1a29f0 vmov s14, r0 */
/* @0x1a29f4 vcvt.s32.f32 s15, s14 */
/* @0x1a29f8 vcvt.f32.s32 s15, s15 */
/* @0x1a29fc vmls.f32 s19, s15, s18 */
/* @0x1a2a00 vmov.f32 s15, s19 */
/* @0x1a2a04 b 0x1a2958 <_Z19Vector_To_DirectionffPfS_+0x38> */
/* @0x1a2a08 vldr s15, [pc, #36] */
/* @0x1a2a0c vstr s15, [r2] */
/* @0x1a2a10 b 0x1a2958 <_Z19Vector_To_DirectionffPfS_+0x38> */
/* @0x1a2a14 vmov r0, s14 */
/* @0x1a2a18 bl 0xb6700 <sqrtf@plt> */
/* @0x1a2a1c vmov s15, r0 */
/* @0x1a2a20 b 0x1a2974 <_Z19Vector_To_DirectionffPfS_+0x54> */
/* @0x1a2a24 orrmi r0, r7, #0 */
/* @0x1a2a28 .word 0x43b40000 */
/* @0x1a2a2c teqmi r4, #0 */
/* @0x1a2a30 ldrdmi r0, r1, [r9], #-251 */
/* @0x1a2a34 adcsmi r0, r4, #0 */

/* ── FUNC 0x1a2a38 · Direction_To_Vector(float, float, float*, float*) · size=96 · insn=24 */
/* @0x1a2a38 vmov s14, r0 */
/* @0x1a2a3c vldr s15, [pc, #76] */
/* @0x1a2a40 push {r3, r4, r5, lr} */
/* @0x1a2a44 vpush {d8} */
/* @0x1a2a48 vldr s17, [pc, #68] */
/* @0x1a2a4c vmul.f32 s17, s14, s17 */
/* @0x1a2a50 vmov s16, r1 */
/* @0x1a2a54 mov r4, r2 */
/* @0x1a2a58 mov r5, r3 */
/* @0x1a2a5c vdiv.f32 s17, s17, s15 */
/* @0x1a2a60 vmov r0, s17 */
/* @0x1a2a64 bl 0xb658c <cosf@plt> */
/* @0x1a2a68 vmov s14, r0 */
/* @0x1a2a6c vmov r0, s17 */
/* @0x1a2a70 vmul.f32 s15, s14, s16 */
/* @0x1a2a74 vstr s15, [r4] */
/* @0x1a2a78 bl 0xb6580 <sinf@plt> */
/* @0x1a2a7c vmov s15, r0 */
/* @0x1a2a80 vnmul.f32 s16, s16, s15 */
/* @0x1a2a84 vstr s16, [r5] */
/* @0x1a2a88 vpop {d8} */
/* @0x1a2a8c pop {r3, r4, r5, pc} */
/* @0x1a2a90 teqmi r4, #0 */
/* @0x1a2a94 ldrdmi r0, r1, [r9], #-251 */

/* ── FUNC 0x1a2a98 · Compute_Color(RParticle&) · size=760 · insn=190 */
/* @0x1a2a98 ldr r3, [pc, #0x2ec] */
/* @0x1a2a9c ldr r2, [r0, #0x8] */
/* @0x1a2aa0 ldr r3, [pc, r3] */
/* @0x1a2aa4 ldr r1, [r0, #0x4] */
/* @0x1a2aa8 cmp r2, #0 */
/* @0x1a2aac ldr r3, [r3, #0x4] */
/* @0x1a2ab0 push {r4, r5, r6, lr} */
/* @0x1a2ab4 vpush {d8} */
/* @0x1a2ab8 mov r4, r0 */
/* @0x1a2abc sub sp, sp, #8 */
/* @0x1a2ac0 ldr r5, [r3, r1, lsl #2] */
/* @0x1a2ac4 ble 0x1a2b44 <_Z13Compute_ColorR9RParticle+0xac> */
/* @0x1a2ac8 ldr r3, [r0, #0xc] */
/* @0x1a2acc cmp r3, #0 */
/* @0x1a2ad0 ble 0x1a2b44 <_Z13Compute_ColorR9RParticle+0xac> */
/* @0x1a2ad4 ldr r1, [r5, #0x78] */
/* @0x1a2ad8 cmp r1, #1 */
/* @0x1a2adc beq 0x1a2b80 <_Z13Compute_ColorR9RParticle+0xe8> */
/* @0x1a2ae0 cmp r1, #2 */
/* @0x1a2ae4 bne 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0> */
/* @0x1a2ae8 vmov s13, r2 */
/* @0x1a2aec vmov s12, r3 */
/* @0x1a2af0 vcvt.f32.s32 s15, s13 */
/* @0x1a2af4 vadd.f32 s15, s15, s15 */
/* @0x1a2af8 vcvt.f32.s32 s14, s12 */
/* @0x1a2afc vdiv.f32 s15, s15, s14 */
/* @0x1a2b00 vmov.f32 s14, #2.000000e+00 */
/* @0x1a2b04 vcmpe.f32 s15, s14 */
/* @0x1a2b08 vmrs APSR_nzcv, fpscr */
/* @0x1a2b0c bgt 0x1a2d6c <_Z13Compute_ColorR9RParticle+0x2d4> */
/* @0x1a2b10 vmov.f32 s14, #1.000000e+00 */
/* @0x1a2b14 vcmpe.f32 s15, s14 */
/* @0x1a2b18 vmrs APSR_nzcv, fpscr */
/* @0x1a2b1c vsubpl.f32 s15, s15, s14 */
/* @0x1a2b20 bmi 0x1a2d74 <_Z13Compute_ColorR9RParticle+0x2dc> */
/* @0x1a2b24 ldr r0, [r5, #0x80] */
/* @0x1a2b28 ldr r1, [r5, #0x84] */
/* @0x1a2b2c vmov r2, s15 */
/* @0x1a2b30 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x1a2b34 str r0, [r4, #0x2c] */
/* @0x1a2b38 add sp, sp, #8 */
/* @0x1a2b3c vpop {d8} */
/* @0x1a2b40 pop {r4, r5, r6, pc} */
/* @0x1a2b44 ldr r3, [r5, #0x78] */
/* @0x1a2b48 cmp r3, #5 */
/* @0x1a2b4c addls pc, pc, r3, lsl #2 */
/* @0x1a2b50 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0> */
/* @0x1a2b54 b 0x1a2b6c <_Z13Compute_ColorR9RParticle+0xd4> */
/* @0x1a2b58 b 0x1a2b6c <_Z13Compute_ColorR9RParticle+0xd4> */
/* @0x1a2b5c b 0x1a2b6c <_Z13Compute_ColorR9RParticle+0xd4> */
/* @0x1a2b60 b 0x1a2bc4 <_Z13Compute_ColorR9RParticle+0x12c> */
/* @0x1a2b64 b 0x1a2c7c <_Z13Compute_ColorR9RParticle+0x1e4> */
/* @0x1a2b68 b 0x1a2d34 <_Z13Compute_ColorR9RParticle+0x29c> */
/* @0x1a2b6c ldr r3, [r5, #0x7c] */
/* @0x1a2b70 str r3, [r4, #0x2c] */
/* @0x1a2b74 add sp, sp, #8 */
/* @0x1a2b78 vpop {d8} */
/* @0x1a2b7c pop {r4, r5, r6, pc} */
/* @0x1a2b80 vmov s13, r2 */
/* @0x1a2b84 ldr r0, [r5, #0x7c] */
/* @0x1a2b88 vmov s12, r3 */
/* @0x1a2b8c ldr r1, [r5, #0x80] */
/* @0x1a2b90 vcvt.f32.s32 s14, s13 */
/* @0x1a2b94 vcvt.f32.s32 s15, s12 */
/* @0x1a2b98 vdiv.f32 s14, s14, s15 */
/* @0x1a2b9c vmov.f32 s15, #1.000000e+00 */
/* @0x1a2ba0 vcmp.f32 s14, s15 */
/* @0x1a2ba4 vmrs APSR_nzcv, fpscr */
/* @0x1a2ba8 vmovgt r2, s15 */
/* @0x1a2bac vmovle r2, s14 */
/* @0x1a2bb0 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x1a2bb4 str r0, [r4, #0x2c] */
/* @0x1a2bb8 add sp, sp, #8 */
/* @0x1a2bbc vpop {d8} */
/* @0x1a2bc0 pop {r4, r5, r6, pc} */
/* @0x1a2bc4 vldr s12, [r5, #124] */
/* @0x1a2bc8 vldr s13, [r5, #128] */
/* @0x1a2bcc vcvt.f32.u32 s12, s12 */
/* @0x1a2bd0 mov r2, #0 */
/* @0x1a2bd4 vcvt.f32.u32 s13, s13 */
/* @0x1a2bd8 vmov r0, s12 */
/* @0x1a2bdc vmov r1, s13 */
/* @0x1a2be0 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2be4 vldr s14, [r5, #132] */
/* @0x1a2be8 vldr s15, [r5, #136] */
/* @0x1a2bec vcvt.f32.u32 s14, s14 */
/* @0x1a2bf0 mov r2, #0 */
/* @0x1a2bf4 vcvt.f32.u32 s15, s15 */
/* @0x1a2bf8 vmov r1, s15 */
/* @0x1a2bfc vmov s16, r0 */
/* @0x1a2c00 vmov r0, s14 */
/* @0x1a2c04 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2c08 ldr r1, [r5, #0x90] */
/* @0x1a2c0c mov r2, #0 */
/* @0x1a2c10 vmov s13, r1 */
/* @0x1a2c14 vcvt.f32.u32 s13, s13 */
/* @0x1a2c18 vmov r1, s13 */
/* @0x1a2c1c vmov s17, r0 */
/* @0x1a2c20 ldr r0, [r5, #0x8c] */
/* @0x1a2c24 vmov s12, r0 */
/* @0x1a2c28 vcvt.f32.u32 s12, s12 */
/* @0x1a2c2c vmov r0, s12 */
/* @0x1a2c30 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2c34 vcvt.s32.f32 s17, s17 */
/* @0x1a2c38 vcvt.s32.f32 s16, s16 */
/* @0x1a2c3c vmov r1, s17 */
/* @0x1a2c40 vmov s14, r0 */
/* @0x1a2c44 vmov r0, s16 */
/* @0x1a2c48 vcvt.s32.f32 s14, s14 */
/* @0x1a2c4c vmov r2, s14 */
/* @0x1a2c50 bl 0x20f9ac <_Z9Color_RGBiii> */
/* @0x1a2c54 mov r3, r0 */
/* @0x1a2c58 add r0, sp, #4 */
/* @0x1a2c5c ubfx r2, r3, #0x8, #0x8 */
/* @0x1a2c60 strb r3, [sp, #0x4] */
/* @0x1a2c64 strb r2, [sp, #0x5] */
/* @0x1a2c68 ubfx r3, r3, #0x10, #0x8 */
/* @0x1a2c6c strb r3, [sp, #0x6] */
/* @0x1a2c70 bl 0x20fa2c <_Z16Color_RGBToColorR4TRGB> */
/* @0x1a2c74 str r0, [r4, #0x2c] */
/* @0x1a2c78 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0> */
/* @0x1a2c7c vldr s15, [r5, #124] */
/* @0x1a2c80 vldr s12, [r5, #128] */
/* @0x1a2c84 vcvt.f32.u32 s15, s15 */
/* @0x1a2c88 mov r2, #0 */
/* @0x1a2c8c vcvt.f32.u32 s12, s12 */
/* @0x1a2c90 vmov r0, s15 */
/* @0x1a2c94 vmov r1, s12 */
/* @0x1a2c98 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2c9c vldr s13, [r5, #132] */
/* @0x1a2ca0 vldr s14, [r5, #136] */
/* @0x1a2ca4 vcvt.f32.u32 s13, s13 */
/* @0x1a2ca8 mov r2, #0 */
/* @0x1a2cac vcvt.f32.u32 s14, s14 */
/* @0x1a2cb0 vmov r1, s14 */
/* @0x1a2cb4 vmov s16, r0 */
/* @0x1a2cb8 vmov r0, s13 */
/* @0x1a2cbc bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2cc0 ldr r1, [r5, #0x90] */
/* @0x1a2cc4 mov r2, #0 */
/* @0x1a2cc8 vmov s12, r1 */
/* @0x1a2ccc vcvt.f32.u32 s12, s12 */
/* @0x1a2cd0 vmov r1, s12 */
/* @0x1a2cd4 vmov s17, r0 */
/* @0x1a2cd8 ldr r0, [r5, #0x8c] */
/* @0x1a2cdc vmov s15, r0 */
/* @0x1a2ce0 vcvt.f32.u32 s15, s15 */
/* @0x1a2ce4 vmov r0, s15 */
/* @0x1a2ce8 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2cec vcvt.s32.f32 s17, s17 */
/* @0x1a2cf0 vcvt.s32.f32 s16, s16 */
/* @0x1a2cf4 vmov r1, s17 */
/* @0x1a2cf8 vmov s13, r0 */
/* @0x1a2cfc vmov r0, s16 */
/* @0x1a2d00 vcvt.s32.f32 s13, s13 */
/* @0x1a2d04 vmov r2, s13 */
/* @0x1a2d08 bl 0x20f9d8 <_Z9Color_HSViii> */
/* @0x1a2d0c mov r3, r0 */
/* @0x1a2d10 add r0, sp, #4 */
/* @0x1a2d14 ubfx r2, r3, #0x8, #0x8 */
/* @0x1a2d18 strb r3, [sp, #0x4] */
/* @0x1a2d1c strb r2, [sp, #0x5] */
/* @0x1a2d20 ubfx r3, r3, #0x10, #0x8 */
/* @0x1a2d24 strb r3, [sp, #0x6] */
/* @0x1a2d28 bl 0x20feac <_Z16Color_HSVToColorR4THSV> */
/* @0x1a2d2c str r0, [r4, #0x2c] */
/* @0x1a2d30 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0> */
/* @0x1a2d34 mov r0, #0 */
/* @0x1a2d38 mov r1, #0 */
/* @0x1a2d3c movt r1, #0x3ff0 */
/* @0x1a2d40 ldr r6, [r5, #0x7c] */
/* @0x1a2d44 ldr r5, [r5, #0x80] */
/* @0x1a2d48 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a2d4c vmov d6, r0, r1 */
/* @0x1a2d50 mov r0, r6 */
/* @0x1a2d54 mov r1, r5 */
/* @0x1a2d58 vcvt.f32.f64 s15, d6 */
/* @0x1a2d5c vmov r2, s15 */
/* @0x1a2d60 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x1a2d64 str r0, [r4, #0x2c] */
/* @0x1a2d68 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0> */
/* @0x1a2d6c vmov.f32 s15, #1.000000e+00 */
/* @0x1a2d70 b 0x1a2b24 <_Z13Compute_ColorR9RParticle+0x8c> */
/* @0x1a2d74 ldr r0, [r5, #0x7c] */
/* @0x1a2d78 ldr r1, [r5, #0x80] */
/* @0x1a2d7c vmov r2, s15 */
/* @0x1a2d80 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x1a2d84 str r0, [r4, #0x2c] */
/* @0x1a2d88 b 0x1a2b38 <_Z13Compute_ColorR9RParticle+0xa0> */
/* @0x1a2d8c eoreq sp, r4, r12, lsl #26 */

/* ── FUNC 0x1a2d90 · ParticleType_DestroyAll() · size=132 · insn=33 */
/* @0x1a2d90 push {r4, r5, r6, lr} */
/* @0x1a2d94 ldr r5, [pc, #0x6c] */
/* @0x1a2d98 ldr r5, [pc, r5] */
/* @0x1a2d9c ldr r0, [r5, #0x4] */
/* @0x1a2da0 cmp r0, #0 */
/* @0x1a2da4 popeq {r4, r5, r6, pc} */
/* @0x1a2da8 ldr r3, [r5] */
/* @0x1a2dac cmp r3, #0 */
/* @0x1a2db0 ble 0x1a2de0 <_Z23ParticleType_DestroyAllv+0x50> */
/* @0x1a2db4 mov r4, #0 */
/* @0x1a2db8 mov r6, r4 */
/* @0x1a2dbc ldr r0, [r0, r4, lsl #2] */
/* @0x1a2dc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a2dc4 ldr r2, [r5, #0x4] */
/* @0x1a2dc8 ldr r3, [r5] */
/* @0x1a2dcc str r6, [r2, r4, lsl #2] */
/* @0x1a2dd0 add r4, r4, #1 */
/* @0x1a2dd4 cmp r3, r4 */
/* @0x1a2dd8 ldr r0, [r5, #0x4] */
/* @0x1a2ddc bgt 0x1a2dbc <_Z23ParticleType_DestroyAllv+0x2c> */
/* @0x1a2de0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a2de4 ldr r1, [pc, #0x20] */
/* @0x1a2de8 ldr r3, [pc, #0x20] */
/* @0x1a2dec mov r2, #0 */
/* @0x1a2df0 ldr r1, [pc, r1] */
/* @0x1a2df4 str r2, [r5, #0x4] */
/* @0x1a2df8 ldr r3, [pc, r3] */
/* @0x1a2dfc str r2, [r1] */
/* @0x1a2e00 strb r2, [r3] */
/* @0x1a2e04 pop {r4, r5, r6, pc} */
/* @0x1a2e08 eoreq sp, r4, r4, lsl r10 */
/* @0x1a2e0c eoreq sp, r4, r0, asr #19 */
/* @0x1a2e10 eoreq sp, r4, r8, lsr #19 */

/* ── FUNC 0x1a2e14 · ParticleType_Exists(int) · size=72 · insn=18 */
/* @0x1a2e14 cmp r0, #0 */
/* @0x1a2e18 blt 0x1a2e4c <_Z19ParticleType_Existsi+0x38> */
/* @0x1a2e1c ldr r3, [pc, #0x30] */
/* @0x1a2e20 ldr r3, [pc, r3] */
/* @0x1a2e24 ldr r3, [r3] */
/* @0x1a2e28 cmp r0, r3 */
/* @0x1a2e2c bge 0x1a2e4c <_Z19ParticleType_Existsi+0x38> */
/* @0x1a2e30 ldr r3, [pc, #0x20] */
/* @0x1a2e34 ldr r3, [pc, r3] */
/* @0x1a2e38 ldr r3, [r3, #0x4] */
/* @0x1a2e3c ldr r0, [r3, r0, lsl #2] */
/* @0x1a2e40 adds r0, r0, #0 */
/* @0x1a2e44 movne r0, #1 */
/* @0x1a2e48 bx lr */
/* @0x1a2e4c mov r0, #0 */
/* @0x1a2e50 bx lr */
/* @0x1a2e54 mlaeq r4, r0, r9, sp */
/* @0x1a2e58 eoreq sp, r4, r8, ror r9 */

/* ── FUNC 0x1a2e5c · CreateParticle(float, float, int, RParticle&) · size=288 · insn=72 */
/* @0x1a2e5c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1a2e60 mov r7, r0 */
/* @0x1a2e64 mov r0, r2 */
/* @0x1a2e68 mov r6, r2 */
/* @0x1a2e6c mov r8, r1 */
/* @0x1a2e70 mov r4, r3 */
/* @0x1a2e74 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a2e78 cmp r0, #0 */
/* @0x1a2e7c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a2e80 ldr r3, [pc, #0xf0] */
/* @0x1a2e84 mov r12, #1 */
/* @0x1a2e88 mov r2, #0 */
/* @0x1a2e8c ldr r3, [pc, r3] */
/* @0x1a2e90 mov r9, r2 */
/* @0x1a2e94 ldr r3, [r3, #0x4] */
/* @0x1a2e98 ldr r5, [r3, r6, lsl #2] */
/* @0x1a2e9c str r7, [r4, #0x10] */
/* @0x1a2ea0 str r6, [r4, #0x4] */
/* @0x1a2ea4 ldr r1, [r5, #0x40] */
/* @0x1a2ea8 ldr r0, [r5, #0x3c] */
/* @0x1a2eac str r8, [r4, #0x14] */
/* @0x1a2eb0 strb r12, [r4] */
/* @0x1a2eb4 str r7, [r4, #0x18] */
/* @0x1a2eb8 str r8, [r4, #0x1c] */
/* @0x1a2ebc bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2ec0 ldr r1, [r5, #0x50] */
/* @0x1a2ec4 mov r2, r9 */
/* @0x1a2ec8 str r0, [r4, #0x20] */
/* @0x1a2ecc ldr r0, [r5, #0x4c] */
/* @0x1a2ed0 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2ed4 ldr r1, [r5, #0x68] */
/* @0x1a2ed8 mov r2, r9 */
/* @0x1a2edc str r0, [r4, #0x24] */
/* @0x1a2ee0 ldr r0, [r5, #0x64] */
/* @0x1a2ee4 bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2ee8 vldr s15, [r5, #40] */
/* @0x1a2eec vcvt.f32.s32 s15, s15 */
/* @0x1a2ef0 ldr r3, [r5, #0x24] */
/* @0x1a2ef4 mov r2, r9 */
/* @0x1a2ef8 vmov r1, s15 */
/* @0x1a2efc vmov s15, r3 */
/* @0x1a2f00 vcvt.f32.s32 s15, s15 */
/* @0x1a2f04 str r0, [r4, #0x28] */
/* @0x1a2f08 vmov r0, s15 */
/* @0x1a2f0c bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2f10 str r9, [r4, #0x8] */
/* @0x1a2f14 vmov s15, r0 */
/* @0x1a2f18 mov r0, r4 */
/* @0x1a2f1c vcvt.s32.f32 s15, s15 */
/* @0x1a2f20 vstr s15, [r4, #12] */
/* @0x1a2f24 bl 0x1a2a98 <_Z13Compute_ColorR9RParticle> */
/* @0x1a2f28 ldr r3, [r5, #0x94] */
/* @0x1a2f2c ldr r0, [r5, #0xc] */
/* @0x1a2f30 mov r2, r9 */
/* @0x1a2f34 ldr r1, [r5, #0x10] */
/* @0x1a2f38 str r3, [r4, #0x30] */
/* @0x1a2f3c bl 0x1a27ac <_Z8MyRandomffi> */
/* @0x1a2f40 ldrb r3, [r5, #0x6] */
/* @0x1a2f44 cmp r3, r9 */
/* @0x1a2f48 streq r3, [r4, #0x38] */
/* @0x1a2f4c str r0, [r4, #0x34] */
/* @0x1a2f50 bne 0x1a2f68 <_Z14CreateParticleffiR9RParticle+0x10c> */
/* @0x1a2f54 movw r0, #0x86a0 */
/* @0x1a2f58 movt r0, #0x1 */
/* @0x1a2f5c bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a2f60 str r0, [r4, #0x3c] */
/* @0x1a2f64 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1a2f68 movw r0, #0x2710 */
/* @0x1a2f6c bl 0xc4600 <_Z8YYRandomi> */
/* @0x1a2f70 str r0, [r4, #0x38] */
/* @0x1a2f74 b 0x1a2f54 <_Z14CreateParticleffiR9RParticle+0xf8> */
/* @0x1a2f78 eoreq sp, r4, r0, lsr #18 */

/* ── FUNC 0x1a2f7c · ParticleType_Clear(int) · size=236 · insn=59 */
/* @0x1a2f7c push {r4, r5, r6, r7, r8, lr} */
/* @0x1a2f80 mov r6, r0 */
/* @0x1a2f84 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a2f88 cmp r0, #0 */
/* @0x1a2f8c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a2f90 ldr r3, [pc, #0xcc] */
/* @0x1a2f94 mov r2, #0 */
/* @0x1a2f98 mov r1, #0 */
/* @0x1a2f9c mov r12, #1065353216 */
/* @0x1a2fa0 ldr r3, [pc, r3] */
/* @0x1a2fa4 mvn r4, #-16777216 */
/* @0x1a2fa8 mov r5, #100 */
/* @0x1a2fac mvn r7, #0 */
/* @0x1a2fb0 ldr r3, [r3, #0x4] */
/* @0x1a2fb4 mov r0, #1 */
/* @0x1a2fb8 mov r8, #0 */
/* @0x1a2fbc movt r8, #0x4387 */
/* @0x1a2fc0 ldr r3, [r3, r6, lsl #2] */
/* @0x1a2fc4 str r2, [r3, #0x14] */
/* @0x1a2fc8 str r2, [r3, #0x18] */
/* @0x1a2fcc str r2, [r3, #0x3c] */
/* @0x1a2fd0 str r2, [r3, #0x40] */
/* @0x1a2fd4 str r2, [r3, #0x44] */
/* @0x1a2fd8 str r7, [r3] */
/* @0x1a2fdc str r12, [r3, #0xc] */
/* @0x1a2fe0 strb r0, [r3, #0x4] */
/* @0x1a2fe4 str r12, [r3, #0x10] */
/* @0x1a2fe8 strb r1, [r3, #0x5] */
/* @0x1a2fec str r12, [r3, #0x1c] */
/* @0x1a2ff0 strb r1, [r3, #0x6] */
/* @0x1a2ff4 str r12, [r3, #0x20] */
/* @0x1a2ff8 str r1, [r3, #0x8] */
/* @0x1a2ffc str r2, [r3, #0x48] */
/* @0x1a3000 str r1, [r3, #0x34] */
/* @0x1a3004 str r2, [r3, #0x4c] */
/* @0x1a3008 str r1, [r3, #0x38] */
/* @0x1a300c str r2, [r3, #0x50] */
/* @0x1a3010 str r1, [r3, #0x2c] */
/* @0x1a3014 str r2, [r3, #0x54] */
/* @0x1a3018 str r1, [r3, #0x30] */
/* @0x1a301c str r2, [r3, #0x58] */
/* @0x1a3020 strb r1, [r3, #0x74] */
/* @0x1a3024 str r2, [r3, #0x64] */
/* @0x1a3028 str r2, [r3, #0x68] */
/* @0x1a302c str r2, [r3, #0x6c] */
/* @0x1a3030 str r2, [r3, #0x70] */
/* @0x1a3034 str r5, [r3, #0x24] */
/* @0x1a3038 str r5, [r3, #0x28] */
/* @0x1a303c str r2, [r3, #0x5c] */
/* @0x1a3040 str r1, [r3, #0x78] */
/* @0x1a3044 str r12, [r3, #0x94] */
/* @0x1a3048 str r12, [r3, #0x98] */
/* @0x1a304c str r12, [r3, #0x9c] */
/* @0x1a3050 str r8, [r3, #0x60] */
/* @0x1a3054 str r4, [r3, #0x7c] */
/* @0x1a3058 str r4, [r3, #0x80] */
/* @0x1a305c str r4, [r3, #0x84] */
/* @0x1a3060 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3064 eoreq sp, r4, r12, lsl #16 */

/* ── FUNC 0x1a3068 · ParticleType_Create() · size=248 · insn=62 */
/* @0x1a3068 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a306c ldr r3, [pc, #0xd8] */
/* @0x1a3070 ldr r2, [pc, #0xd8] */
/* @0x1a3074 add r3, pc, r3 */
/* @0x1a3078 ldr r7, [r3, r2] */
/* @0x1a307c ldr r2, [pc, #0xd0] */
/* @0x1a3080 ldr r1, [r7] */
/* @0x1a3084 cmp r1, #0 */
/* @0x1a3088 ble 0x1a312c <_Z19ParticleType_Createv+0xc4> */
/* @0x1a308c ldr r6, [r3, r2] */
/* @0x1a3090 ldr r5, [r6, #0x4] */
/* @0x1a3094 ldr r4, [r5] */
/* @0x1a3098 cmp r4, #0 */
/* @0x1a309c beq 0x1a3100 <_Z19ParticleType_Createv+0x98> */
/* @0x1a30a0 add r3, r5, #4 */
/* @0x1a30a4 mov r4, #0 */
/* @0x1a30a8 b 0x1a30b8 <_Z19ParticleType_Createv+0x50> */
/* @0x1a30ac ldr r2, [r5] */
/* @0x1a30b0 cmp r2, #0 */
/* @0x1a30b4 beq 0x1a3100 <_Z19ParticleType_Createv+0x98> */
/* @0x1a30b8 add r4, r4, #1 */
/* @0x1a30bc mov r5, r3 */
/* @0x1a30c0 cmp r4, r1 */
/* @0x1a30c4 add r3, r3, #4 */
/* @0x1a30c8 bne 0x1a30ac <_Z19ParticleType_Createv+0x44> */
/* @0x1a30cc lsl r5, r4, #2 */
/* @0x1a30d0 add r12, r4, #1 */
/* @0x1a30d4 ldr r2, [pc, #0x7c] */
/* @0x1a30d8 movw r3, #0x1b5 */
/* @0x1a30dc add r0, r6, #4 */
/* @0x1a30e0 add r2, pc, r2 */
/* @0x1a30e4 lsl r1, r12, #2 */
/* @0x1a30e8 str r12, [r7] */
/* @0x1a30ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a30f0 ldr r2, [r6, #0x4] */
/* @0x1a30f4 ldr r3, [r7] */
/* @0x1a30f8 add r5, r2, r5 */
/* @0x1a30fc str r3, [r6] */
/* @0x1a3100 ldr r1, [pc, #0x54] */
/* @0x1a3104 movw r2, #0x1b9 */
/* @0x1a3108 mov r3, #1 */
/* @0x1a310c mov r0, #164 */
/* @0x1a3110 add r1, pc, r1 */
/* @0x1a3114 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a3118 str r0, [r5] */
/* @0x1a311c mov r0, r4 */
/* @0x1a3120 bl 0x1a2f7c <_Z18ParticleType_Cleari> */
/* @0x1a3124 mov r0, r4 */
/* @0x1a3128 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a312c ldrne r3, [r3, r2] */
/* @0x1a3130 movne r4, #0 */
/* @0x1a3134 ldrne r5, [r3, #0x4] */
/* @0x1a3138 bne 0x1a3100 <_Z19ParticleType_Createv+0x98> */
/* @0x1a313c mov r5, r1 */
/* @0x1a3140 mov r4, r1 */
/* @0x1a3144 ldr r6, [r3, r2] */
/* @0x1a3148 b 0x1a30d0 <_Z19ParticleType_Createv+0x68> */
/* @0x1a314c .word 0x0024ebdc */
/* @0x1a3150 .word 0xffffeb60 */
/* @0x1a3154 .word 0xffffeb5c */
/* @0x1a3158 andseq r9, r10, r0, lsr #29 */
/* @0x1a315c andseq r9, r10, r0, ror lr */

/* ── FUNC 0x1a3160 · ParticleType_Destroy(int) · size=68 · insn=17 */
/* @0x1a3160 push {r3, r4, r5, lr} */
/* @0x1a3164 mov r4, r0 */
/* @0x1a3168 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a316c cmp r0, #0 */
/* @0x1a3170 popeq {r3, r4, r5, pc} */
/* @0x1a3174 ldr r5, [pc, #0x24] */
/* @0x1a3178 mov r0, r4 */
/* @0x1a317c bl 0x1a2f7c <_Z18ParticleType_Cleari> */
/* @0x1a3180 ldr r5, [pc, r5] */
/* @0x1a3184 ldr r3, [r5, #0x4] */
/* @0x1a3188 ldr r0, [r3, r4, lsl #2] */
/* @0x1a318c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a3190 ldr r3, [r5, #0x4] */
/* @0x1a3194 mov r2, #0 */
/* @0x1a3198 str r2, [r3, r4, lsl #2] */
/* @0x1a319c pop {r3, r4, r5, pc} */
/* @0x1a31a0 eoreq sp, r4, r12, lsr #12 */

/* ── FUNC 0x1a31a4 · ParticleType_Shape(int, int) · size=60 · insn=15 */
/* @0x1a31a4 push {r3, r4, r5, lr} */
/* @0x1a31a8 mov r5, r1 */
/* @0x1a31ac mov r4, r0 */
/* @0x1a31b0 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a31b4 cmp r0, #0 */
/* @0x1a31b8 popeq {r3, r4, r5, pc} */
/* @0x1a31bc ldr r3, [pc, #0x18] */
/* @0x1a31c0 mvn r2, #0 */
/* @0x1a31c4 ldr r3, [pc, r3] */
/* @0x1a31c8 ldr r3, [r3, #0x4] */
/* @0x1a31cc ldr r3, [r3, r4, lsl #2] */
/* @0x1a31d0 str r5, [r3, #0x8] */
/* @0x1a31d4 str r2, [r3] */
/* @0x1a31d8 pop {r3, r4, r5, pc} */
/* @0x1a31dc eoreq sp, r4, r8, ror #11 */

/* ── FUNC 0x1a31e0 · ParticleType_Sprite(int, int, bool, bool, bool) · size=76 · insn=19 */
/* @0x1a31e0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a31e4 mov r8, r1 */
/* @0x1a31e8 mov r7, r2 */
/* @0x1a31ec mov r6, r3 */
/* @0x1a31f0 mov r5, r0 */
/* @0x1a31f4 ldrb r4, [sp, #0x18] */
/* @0x1a31f8 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a31fc cmp r0, #0 */
/* @0x1a3200 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1a3204 ldr r12, [pc, #0x1c] */
/* @0x1a3208 ldr r12, [pc, r12] */
/* @0x1a320c ldr r3, [r12, #0x4] */
/* @0x1a3210 ldr r0, [r3, r5, lsl #2] */
/* @0x1a3214 str r8, [r0] */
/* @0x1a3218 strb r7, [r0, #0x4] */
/* @0x1a321c strb r6, [r0, #0x5] */
/* @0x1a3220 strb r4, [r0, #0x6] */
/* @0x1a3224 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a3228 eoreq sp, r4, r4, lsr #11 */

/* ── FUNC 0x1a322c · ParticleType_Size(int, float, float, float, float) · size=76 · insn=19 */
/* @0x1a322c push {r3, r4, r5, r6, r7, lr} */
/* @0x1a3230 mov r7, r1 */
/* @0x1a3234 mov r6, r2 */
/* @0x1a3238 mov r4, r0 */
/* @0x1a323c mov r5, r3 */
/* @0x1a3240 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3244 cmp r0, #0 */
/* @0x1a3248 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a324c ldr r12, [pc, #0x20] */
/* @0x1a3250 vldr s15, [sp, #24] */
/* @0x1a3254 ldr r12, [pc, r12] */
/* @0x1a3258 ldr r3, [r12, #0x4] */
/* @0x1a325c ldr r0, [r3, r4, lsl #2] */
/* @0x1a3260 vstr s15, [r0, #24] */
/* @0x1a3264 str r7, [r0, #0xc] */
/* @0x1a3268 str r6, [r0, #0x10] */
/* @0x1a326c str r5, [r0, #0x14] */
/* @0x1a3270 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a3274 eoreq sp, r4, r8, asr r5 */

/* ── FUNC 0x1a3278 · ParticleType_Scale(int, float, float) · size=60 · insn=15 */
/* @0x1a3278 push {r4, r5, r6, lr} */
/* @0x1a327c mov r6, r1 */
/* @0x1a3280 mov r4, r0 */
/* @0x1a3284 mov r5, r2 */
/* @0x1a3288 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a328c cmp r0, #0 */
/* @0x1a3290 popeq {r4, r5, r6, pc} */
/* @0x1a3294 ldr r3, [pc, #0x14] */
/* @0x1a3298 ldr r3, [pc, r3] */
/* @0x1a329c ldr r3, [r3, #0x4] */
/* @0x1a32a0 ldr r3, [r3, r4, lsl #2] */
/* @0x1a32a4 str r6, [r3, #0x1c] */
/* @0x1a32a8 str r5, [r3, #0x20] */
/* @0x1a32ac pop {r4, r5, r6, pc} */
/* @0x1a32b0 eoreq sp, r4, r4, lsl r5 */

/* ── FUNC 0x1a32b4 · ParticleType_Life(int, int, int) · size=60 · insn=15 */
/* @0x1a32b4 push {r4, r5, r6, lr} */
/* @0x1a32b8 mov r6, r1 */
/* @0x1a32bc mov r5, r2 */
/* @0x1a32c0 mov r4, r0 */
/* @0x1a32c4 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a32c8 cmp r0, #0 */
/* @0x1a32cc popeq {r4, r5, r6, pc} */
/* @0x1a32d0 ldr r3, [pc, #0x14] */
/* @0x1a32d4 ldr r3, [pc, r3] */
/* @0x1a32d8 ldr r3, [r3, #0x4] */
/* @0x1a32dc ldr r3, [r3, r4, lsl #2] */
/* @0x1a32e0 str r6, [r3, #0x24] */
/* @0x1a32e4 str r5, [r3, #0x28] */
/* @0x1a32e8 pop {r4, r5, r6, pc} */
/* @0x1a32ec .word 0x0024d4d8 */

/* ── FUNC 0x1a32f0 · ParticleType_Step(int, int, int) · size=60 · insn=15 */
/* @0x1a32f0 push {r4, r5, r6, lr} */
/* @0x1a32f4 mov r6, r1 */
/* @0x1a32f8 mov r5, r2 */
/* @0x1a32fc mov r4, r0 */
/* @0x1a3300 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3304 cmp r0, #0 */
/* @0x1a3308 popeq {r4, r5, r6, pc} */
/* @0x1a330c ldr r3, [pc, #0x14] */
/* @0x1a3310 ldr r3, [pc, r3] */
/* @0x1a3314 ldr r3, [r3, #0x4] */
/* @0x1a3318 ldr r3, [r3, r4, lsl #2] */
/* @0x1a331c str r6, [r3, #0x38] */
/* @0x1a3320 str r5, [r3, #0x34] */
/* @0x1a3324 pop {r4, r5, r6, pc} */
/* @0x1a3328 mlaeq r4, r12, r4, sp */

/* ── FUNC 0x1a332c · ParticleType_Death(int, int, int) · size=60 · insn=15 */
/* @0x1a332c push {r4, r5, r6, lr} */
/* @0x1a3330 mov r6, r1 */
/* @0x1a3334 mov r5, r2 */
/* @0x1a3338 mov r4, r0 */
/* @0x1a333c bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3340 cmp r0, #0 */
/* @0x1a3344 popeq {r4, r5, r6, pc} */
/* @0x1a3348 ldr r3, [pc, #0x14] */
/* @0x1a334c ldr r3, [pc, r3] */
/* @0x1a3350 ldr r3, [r3, #0x4] */
/* @0x1a3354 ldr r3, [r3, r4, lsl #2] */
/* @0x1a3358 str r6, [r3, #0x30] */
/* @0x1a335c str r5, [r3, #0x2c] */
/* @0x1a3360 pop {r4, r5, r6, pc} */
/* @0x1a3364 eoreq sp, r4, r0, ror #8 */

/* ── FUNC 0x1a3368 · ParticleType_Speed(int, float, float, float, float) · size=76 · insn=19 */
/* @0x1a3368 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a336c mov r7, r1 */
/* @0x1a3370 mov r6, r2 */
/* @0x1a3374 mov r4, r0 */
/* @0x1a3378 mov r5, r3 */
/* @0x1a337c bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x1a3380 cmp r0, #0 */
/* @0x1a3384 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a3388 ldr r12, [pc, #0x20] */
/* @0x1a338c vldr s15, [sp, #24] */
/* @0x1a3390 ldr r12, [pc, r12] */
/* @0x1a3394 ldr r3, [r12, #0x4] */
/* @0x1a3398 ldr r0, [r3, r4, lsl #2] */
/* @0x1a339c vstr s15, [r0, #72] */
/* @0x1a33a0 str r7, [r0, #0x3c] */
/* @0x1a33a4 str r6, [r0, #0x40] */
/* @0x1a33a8 str r5, [r0, #0x44] */
/* @0x1a33ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a33b0 eoreq sp, r4, r12, lsl r4 */
