/* libyoyo.so 覆盖卡组 0172
 * 函数 0x1f887c..0x1f8f00，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f887c · SV_CaptionLives(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1f887c ldr r3, [r2] */
/* @0x1f8880 mov r0, #1 */
/* @0x1f8884 cmp r3, #0 */
/* @0x1f8888 ldrne r2, [r3, #0x4] */
/* @0x1f888c addne r2, r2, #1 */
/* @0x1f8890 strne r2, [r3, #0x4] */
/* @0x1f8894 ldr r2, [pc, #0x8] */
/* @0x1f8898 ldr r2, [pc, r2] */
/* @0x1f889c str r3, [r2] */
/* @0x1f88a0 bx lr */
/* @0x1f88a4 andseq r6, pc, r0, ror #26 */

/* ── FUNC 0x1f88a8 · SV_CaptionHealth(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1f88a8 ldr r3, [r2] */
/* @0x1f88ac mov r0, #1 */
/* @0x1f88b0 cmp r3, #0 */
/* @0x1f88b4 ldrne r2, [r3, #0x4] */
/* @0x1f88b8 addne r2, r2, #1 */
/* @0x1f88bc strne r2, [r3, #0x4] */
/* @0x1f88c0 ldr r2, [pc, #0x8] */
/* @0x1f88c4 ldr r2, [pc, r2] */
/* @0x1f88c8 str r3, [r2] */
/* @0x1f88cc bx lr */
/* @0x1f88d0 andseq r6, pc, r12, lsr sp */

/* ── FUNC 0x1f88d4 · GV_EventType(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f88d4 ldr r3, [pc, #0x34] */
/* @0x1f88d8 mov r1, #0 */
/* @0x1f88dc push {r4, r5} */
/* @0x1f88e0 ldr r3, [pc, r3] */
/* @0x1f88e4 str r1, [r2, #0xc] */
/* @0x1f88e8 mov r0, #1 */
/* @0x1f88ec ldr r4, [r3] */
/* @0x1f88f0 vmov s15, r4 */
/* @0x1f88f4 vcvt.f64.s32 d7, s15 */
/* @0x1f88f8 vmov r4, r5, d7 */
/* @0x1f88fc vmov r1, s14 */
/* @0x1f8900 mov r3, r5 */
/* @0x1f8904 pop {r4, r5} */
/* @0x1f8908 stm r2, {r1, r3} */
/* @0x1f890c bx lr */
/* @0x1f8910 ldrsbeq r5, [pc], -r0 */

/* ── FUNC 0x1f8914 · GV_EventNumber(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8914 ldr r3, [pc, #0x34] */
/* @0x1f8918 mov r1, #0 */
/* @0x1f891c push {r4, r5} */
/* @0x1f8920 ldr r3, [pc, r3] */
/* @0x1f8924 str r1, [r2, #0xc] */
/* @0x1f8928 mov r0, #1 */
/* @0x1f892c ldr r4, [r3] */
/* @0x1f8930 vmov s15, r4 */
/* @0x1f8934 vcvt.f64.s32 d7, s15 */
/* @0x1f8938 vmov r4, r5, d7 */
/* @0x1f893c vmov r1, s14 */
/* @0x1f8940 mov r3, r5 */
/* @0x1f8944 pop {r4, r5} */
/* @0x1f8948 stm r2, {r1, r3} */
/* @0x1f894c bx lr */
/* @0x1f8950 mulseq pc, r4, r4 */

/* ── FUNC 0x1f8954 · GV_EventObject(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8954 ldr r3, [pc, #0x34] */
/* @0x1f8958 mov r1, #0 */
/* @0x1f895c push {r4, r5} */
/* @0x1f8960 ldr r3, [pc, r3] */
/* @0x1f8964 str r1, [r2, #0xc] */
/* @0x1f8968 mov r0, #1 */
/* @0x1f896c ldr r4, [r3] */
/* @0x1f8970 vmov s15, r4 */
/* @0x1f8974 vcvt.f64.s32 d7, s15 */
/* @0x1f8978 vmov r4, r5, d7 */
/* @0x1f897c vmov r1, s14 */
/* @0x1f8980 mov r3, r5 */
/* @0x1f8984 pop {r4, r5} */
/* @0x1f8988 stm r2, {r1, r3} */
/* @0x1f898c bx lr */
/* @0x1f8990 andseq r5, pc, r8, asr r4 */

/* ── FUNC 0x1f8994 · GV_EventAction(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8994 ldr r3, [pc, #0x34] */
/* @0x1f8998 mov r1, #0 */
/* @0x1f899c push {r4, r5} */
/* @0x1f89a0 ldr r3, [pc, r3] */
/* @0x1f89a4 str r1, [r2, #0xc] */
/* @0x1f89a8 mov r0, #1 */
/* @0x1f89ac ldr r4, [r3] */
/* @0x1f89b0 vmov s15, r4 */
/* @0x1f89b4 vcvt.f64.s32 d7, s15 */
/* @0x1f89b8 vmov r4, r5, d7 */
/* @0x1f89bc vmov r1, s14 */
/* @0x1f89c0 mov r3, r5 */
/* @0x1f89c4 pop {r4, r5} */
/* @0x1f89c8 stm r2, {r1, r3} */
/* @0x1f89cc bx lr */
/* @0x1f89d0 andseq r5, pc, r12, lsl #8 */

/* ── FUNC 0x1f89d4 · GV_SecureMode(CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1f89d4 mov r3, #0 */
/* @0x1f89d8 mov r0, #1 */
/* @0x1f89dc str r3, [r2, #0xc] */
/* @0x1f89e0 str r3, [r2] */
/* @0x1f89e4 str r3, [r2, #0x4] */
/* @0x1f89e8 bx lr */

/* ── FUNC 0x1f89ec · GV_ErrorOccurred(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f89ec ldr r3, [pc, #0x34] */
/* @0x1f89f0 mov r1, #0 */
/* @0x1f89f4 push {r4, r5} */
/* @0x1f89f8 ldr r3, [pc, r3] */
/* @0x1f89fc str r1, [r2, #0xc] */
/* @0x1f8a00 mov r0, #1 */
/* @0x1f8a04 ldrb r4, [r3] */
/* @0x1f8a08 vmov s15, r4 */
/* @0x1f8a0c vcvt.f64.u32 d7, s15 */
/* @0x1f8a10 vmov r4, r5, d7 */
/* @0x1f8a14 vmov r1, s14 */
/* @0x1f8a18 mov r3, r5 */
/* @0x1f8a1c pop {r4, r5} */
/* @0x1f8a20 stm r2, {r1, r3} */
/* @0x1f8a24 bx lr */
/* @0x1f8a28 andseq r5, pc, r8, lsr #7 */

/* ── FUNC 0x1f8a2c · SV_ErrorOccurred(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8a2c vmov.f64 d7, #5.000000e-01 */
/* @0x1f8a30 ldr r3, [pc, #0x30] */
/* @0x1f8a34 push {r4, r5} */
/* @0x1f8a38 ldr r3, [pc, r3] */
/* @0x1f8a3c ldr r4, [r2] */
/* @0x1f8a40 mov r0, #1 */
/* @0x1f8a44 ldr r5, [r2, #0x4] */
/* @0x1f8a48 vmov d6, r4, r5 */
/* @0x1f8a4c pop {r4, r5} */
/* @0x1f8a50 vcmpe.f64 d6, d7 */
/* @0x1f8a54 vmrs APSR_nzcv, fpscr */
/* @0x1f8a58 movlt r2, #0 */
/* @0x1f8a5c movge r2, #1 */
/* @0x1f8a60 strb r2, [r3] */
/* @0x1f8a64 bx lr */
/* @0x1f8a68 andseq r5, pc, r8, ror #6 */

/* ── FUNC 0x1f8a6c · SV_ErrorLast(CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x1f8a6c ldr r3, [r2] */
/* @0x1f8a70 mov r0, #1 */
/* @0x1f8a74 cmp r3, #0 */
/* @0x1f8a78 ldrne r2, [r3, #0x4] */
/* @0x1f8a7c addne r2, r2, #1 */
/* @0x1f8a80 strne r2, [r3, #0x4] */
/* @0x1f8a84 ldr r2, [pc, #0x8] */
/* @0x1f8a88 ldr r2, [pc, r2] */
/* @0x1f8a8c str r3, [r2] */
/* @0x1f8a90 bx lr */
/* @0x1f8a94 andseq r5, pc, r4, lsl r3 */

/* ── FUNC 0x1f8a98 · GV_GamemakerRegistered(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8a98 ldr r3, [pc, #0x34] */
/* @0x1f8a9c mov r1, #0 */
/* @0x1f8aa0 push {r4, r5} */
/* @0x1f8aa4 ldr r3, [pc, r3] */
/* @0x1f8aa8 str r1, [r2, #0xc] */
/* @0x1f8aac mov r0, #1 */
/* @0x1f8ab0 ldrb r4, [r3] */
/* @0x1f8ab4 vmov s15, r4 */
/* @0x1f8ab8 vcvt.f64.u32 d7, s15 */
/* @0x1f8abc vmov r4, r5, d7 */
/* @0x1f8ac0 vmov r1, s14 */
/* @0x1f8ac4 mov r3, r5 */
/* @0x1f8ac8 pop {r4, r5} */
/* @0x1f8acc stm r2, {r1, r3} */
/* @0x1f8ad0 bx lr */
/* @0x1f8ad4 andseq r8, pc, r8, lsl r2 */

/* ── FUNC 0x1f8ad8 · GV_ApplicationSurface(CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1f8ad8 ldr r3, [pc, #0x34] */
/* @0x1f8adc mov r1, #0 */
/* @0x1f8ae0 push {r4, r5} */
/* @0x1f8ae4 ldr r3, [pc, r3] */
/* @0x1f8ae8 str r1, [r2, #0xc] */
/* @0x1f8aec mov r0, #1 */
/* @0x1f8af0 ldr r4, [r3] */
/* @0x1f8af4 vmov s15, r4 */
/* @0x1f8af8 vcvt.f64.s32 d7, s15 */
/* @0x1f8afc vmov r4, r5, d7 */
/* @0x1f8b00 vmov r1, s14 */
/* @0x1f8b04 mov r3, r5 */
/* @0x1f8b08 pop {r4, r5} */
/* @0x1f8b0c stm r2, {r1, r3} */
/* @0x1f8b10 bx lr */
/* @0x1f8b14 ldrsheq r5, [pc], -r4 */

/* ── FUNC 0x1f8b18 · GV_ViewSurfaceID(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f8b18 ldr r3, [pc, #0x48] */
/* @0x1f8b1c cmp r1, #7 */
/* @0x1f8b20 push {r4, r5} */
/* @0x1f8b24 ldr r3, [pc, r3] */
/* @0x1f8b28 movhi r1, #0 */
/* @0x1f8b2c add r1, r1, #18 */
/* @0x1f8b30 ldr r3, [r3] */
/* @0x1f8b34 mov r12, #0 */
/* @0x1f8b38 mov r0, #1 */
/* @0x1f8b3c str r12, [r2, #0xc] */
/* @0x1f8b40 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8b44 ldr r4, [r3, #0x3c] */
/* @0x1f8b48 vmov s15, r4 */
/* @0x1f8b4c vcvt.f64.s32 d7, s15 */
/* @0x1f8b50 vmov r4, r5, d7 */
/* @0x1f8b54 vmov r1, s14 */
/* @0x1f8b58 mov r3, r5 */
/* @0x1f8b5c pop {r4, r5} */
/* @0x1f8b60 stm r2, {r1, r3} */
/* @0x1f8b64 bx lr */
/* @0x1f8b68 andseq r4, pc, r4, lsl #28 */

/* ── FUNC 0x1f8b6c · GV_ViewCamera(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1f8b6c ldr r3, [pc, #0x48] */
/* @0x1f8b70 cmp r1, #7 */
/* @0x1f8b74 push {r4, r5} */
/* @0x1f8b78 ldr r3, [pc, r3] */
/* @0x1f8b7c movhi r1, #0 */
/* @0x1f8b80 add r1, r1, #18 */
/* @0x1f8b84 ldr r3, [r3] */
/* @0x1f8b88 mov r12, #0 */
/* @0x1f8b8c mov r0, #1 */
/* @0x1f8b90 str r12, [r2, #0xc] */
/* @0x1f8b94 ldr r3, [r3, r1, lsl #2] */
/* @0x1f8b98 ldr r4, [r3, #0x40] */
/* @0x1f8b9c vmov s15, r4 */
/* @0x1f8ba0 vcvt.f64.s32 d7, s15 */
/* @0x1f8ba4 vmov r4, r5, d7 */
/* @0x1f8ba8 vmov r1, s14 */
/* @0x1f8bac mov r3, r5 */
/* @0x1f8bb0 pop {r4, r5} */
/* @0x1f8bb4 stm r2, {r1, r3} */
/* @0x1f8bb8 bx lr */
/* @0x1f8bbc ldrheq r4, [pc], -r0 */

/* ── FUNC 0x1f8bc0 · GV_X(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8bc0 vldr s15, [r0, #180] */
/* @0x1f8bc4 vcvt.f64.f32 d6, s15 */
/* @0x1f8bc8 push {r4, r5} */
/* @0x1f8bcc mov r3, #0 */
/* @0x1f8bd0 mov r0, #1 */
/* @0x1f8bd4 str r3, [r2, #0xc] */
/* @0x1f8bd8 vmov r4, r5, d6 */
/* @0x1f8bdc vmov r1, s12 */
/* @0x1f8be0 mov r3, r5 */
/* @0x1f8be4 pop {r4, r5} */
/* @0x1f8be8 stm r2, {r1, r3} */
/* @0x1f8bec bx lr */

/* ── FUNC 0x1f8bf0 · GV_Y(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8bf0 vldr s15, [r0, #184] */
/* @0x1f8bf4 vcvt.f64.f32 d6, s15 */
/* @0x1f8bf8 push {r4, r5} */
/* @0x1f8bfc mov r3, #0 */
/* @0x1f8c00 mov r0, #1 */
/* @0x1f8c04 str r3, [r2, #0xc] */
/* @0x1f8c08 vmov r4, r5, d6 */
/* @0x1f8c0c vmov r1, s12 */
/* @0x1f8c10 mov r3, r5 */
/* @0x1f8c14 pop {r4, r5} */
/* @0x1f8c18 stm r2, {r1, r3} */
/* @0x1f8c1c bx lr */

/* ── FUNC 0x1f8c20 · GV_XPrevious(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8c20 vldr s15, [r0, #196] */
/* @0x1f8c24 vcvt.f64.f32 d6, s15 */
/* @0x1f8c28 push {r4, r5} */
/* @0x1f8c2c mov r3, #0 */
/* @0x1f8c30 mov r0, #1 */
/* @0x1f8c34 str r3, [r2, #0xc] */
/* @0x1f8c38 vmov r4, r5, d6 */
/* @0x1f8c3c vmov r1, s12 */
/* @0x1f8c40 mov r3, r5 */
/* @0x1f8c44 pop {r4, r5} */
/* @0x1f8c48 stm r2, {r1, r3} */
/* @0x1f8c4c bx lr */

/* ── FUNC 0x1f8c50 · GV_YPrevious(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8c50 vldr s15, [r0, #200] */
/* @0x1f8c54 vcvt.f64.f32 d6, s15 */
/* @0x1f8c58 push {r4, r5} */
/* @0x1f8c5c mov r3, #0 */
/* @0x1f8c60 mov r0, #1 */
/* @0x1f8c64 str r3, [r2, #0xc] */
/* @0x1f8c68 vmov r4, r5, d6 */
/* @0x1f8c6c vmov r1, s12 */
/* @0x1f8c70 mov r3, r5 */
/* @0x1f8c74 pop {r4, r5} */
/* @0x1f8c78 stm r2, {r1, r3} */
/* @0x1f8c7c bx lr */

/* ── FUNC 0x1f8c80 · GV_XStart(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8c80 vldr s15, [r0, #188] */
/* @0x1f8c84 vcvt.f64.f32 d6, s15 */
/* @0x1f8c88 push {r4, r5} */
/* @0x1f8c8c mov r3, #0 */
/* @0x1f8c90 mov r0, #1 */
/* @0x1f8c94 str r3, [r2, #0xc] */
/* @0x1f8c98 vmov r4, r5, d6 */
/* @0x1f8c9c vmov r1, s12 */
/* @0x1f8ca0 mov r3, r5 */
/* @0x1f8ca4 pop {r4, r5} */
/* @0x1f8ca8 stm r2, {r1, r3} */
/* @0x1f8cac bx lr */

/* ── FUNC 0x1f8cb0 · GV_YStart(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8cb0 vldr s15, [r0, #192] */
/* @0x1f8cb4 vcvt.f64.f32 d6, s15 */
/* @0x1f8cb8 push {r4, r5} */
/* @0x1f8cbc mov r3, #0 */
/* @0x1f8cc0 mov r0, #1 */
/* @0x1f8cc4 str r3, [r2, #0xc] */
/* @0x1f8cc8 vmov r4, r5, d6 */
/* @0x1f8ccc vmov r1, s12 */
/* @0x1f8cd0 mov r3, r5 */
/* @0x1f8cd4 pop {r4, r5} */
/* @0x1f8cd8 stm r2, {r1, r3} */
/* @0x1f8cdc bx lr */

/* ── FUNC 0x1f8ce0 · GV_Hspeed(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8ce0 vldr s15, [r0, #224] */
/* @0x1f8ce4 vcvt.f64.f32 d6, s15 */
/* @0x1f8ce8 push {r4, r5} */
/* @0x1f8cec mov r3, #0 */
/* @0x1f8cf0 mov r0, #1 */
/* @0x1f8cf4 str r3, [r2, #0xc] */
/* @0x1f8cf8 vmov r4, r5, d6 */
/* @0x1f8cfc vmov r1, s12 */
/* @0x1f8d00 mov r3, r5 */
/* @0x1f8d04 pop {r4, r5} */
/* @0x1f8d08 stm r2, {r1, r3} */
/* @0x1f8d0c bx lr */

/* ── FUNC 0x1f8d10 · GV_Vspeed(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8d10 vldr s15, [r0, #228] */
/* @0x1f8d14 vcvt.f64.f32 d6, s15 */
/* @0x1f8d18 push {r4, r5} */
/* @0x1f8d1c mov r3, #0 */
/* @0x1f8d20 mov r0, #1 */
/* @0x1f8d24 str r3, [r2, #0xc] */
/* @0x1f8d28 vmov r4, r5, d6 */
/* @0x1f8d2c vmov r1, s12 */
/* @0x1f8d30 mov r3, r5 */
/* @0x1f8d34 pop {r4, r5} */
/* @0x1f8d38 stm r2, {r1, r3} */
/* @0x1f8d3c bx lr */

/* ── FUNC 0x1f8d40 · GV_Direction(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8d40 vldr s15, [r0, #204] */
/* @0x1f8d44 vcvt.f64.f32 d6, s15 */
/* @0x1f8d48 push {r4, r5} */
/* @0x1f8d4c mov r3, #0 */
/* @0x1f8d50 mov r0, #1 */
/* @0x1f8d54 str r3, [r2, #0xc] */
/* @0x1f8d58 vmov r4, r5, d6 */
/* @0x1f8d5c vmov r1, s12 */
/* @0x1f8d60 mov r3, r5 */
/* @0x1f8d64 pop {r4, r5} */
/* @0x1f8d68 stm r2, {r1, r3} */
/* @0x1f8d6c bx lr */

/* ── FUNC 0x1f8d70 · GV_Speed(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8d70 vldr s15, [r0, #208] */
/* @0x1f8d74 vcvt.f64.f32 d6, s15 */
/* @0x1f8d78 push {r4, r5} */
/* @0x1f8d7c mov r3, #0 */
/* @0x1f8d80 mov r0, #1 */
/* @0x1f8d84 str r3, [r2, #0xc] */
/* @0x1f8d88 vmov r4, r5, d6 */
/* @0x1f8d8c vmov r1, s12 */
/* @0x1f8d90 mov r3, r5 */
/* @0x1f8d94 pop {r4, r5} */
/* @0x1f8d98 stm r2, {r1, r3} */
/* @0x1f8d9c bx lr */

/* ── FUNC 0x1f8da0 · GV_Friction(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8da0 vldr s15, [r0, #212] */
/* @0x1f8da4 vcvt.f64.f32 d6, s15 */
/* @0x1f8da8 push {r4, r5} */
/* @0x1f8dac mov r3, #0 */
/* @0x1f8db0 mov r0, #1 */
/* @0x1f8db4 str r3, [r2, #0xc] */
/* @0x1f8db8 vmov r4, r5, d6 */
/* @0x1f8dbc vmov r1, s12 */
/* @0x1f8dc0 mov r3, r5 */
/* @0x1f8dc4 pop {r4, r5} */
/* @0x1f8dc8 stm r2, {r1, r3} */
/* @0x1f8dcc bx lr */

/* ── FUNC 0x1f8dd0 · GV_Gravity(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8dd0 vldr s15, [r0, #220] */
/* @0x1f8dd4 vcvt.f64.f32 d6, s15 */
/* @0x1f8dd8 push {r4, r5} */
/* @0x1f8ddc mov r3, #0 */
/* @0x1f8de0 mov r0, #1 */
/* @0x1f8de4 str r3, [r2, #0xc] */
/* @0x1f8de8 vmov r4, r5, d6 */
/* @0x1f8dec vmov r1, s12 */
/* @0x1f8df0 mov r3, r5 */
/* @0x1f8df4 pop {r4, r5} */
/* @0x1f8df8 stm r2, {r1, r3} */
/* @0x1f8dfc bx lr */

/* ── FUNC 0x1f8e00 · GV_GravityDir(CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1f8e00 vldr s15, [r0, #216] */
/* @0x1f8e04 vcvt.f64.f32 d6, s15 */
/* @0x1f8e08 push {r4, r5} */
/* @0x1f8e0c mov r3, #0 */
/* @0x1f8e10 mov r0, #1 */
/* @0x1f8e14 str r3, [r2, #0xc] */
/* @0x1f8e18 vmov r4, r5, d6 */
/* @0x1f8e1c vmov r1, s12 */
/* @0x1f8e20 mov r3, r5 */
/* @0x1f8e24 pop {r4, r5} */
/* @0x1f8e28 stm r2, {r1, r3} */
/* @0x1f8e2c bx lr */

/* ── FUNC 0x1f8e30 · GV_Id(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f8e30 push {r4, r5} */
/* @0x1f8e34 mov r3, #0 */
/* @0x1f8e38 ldr r4, [r0, #0x78] */
/* @0x1f8e3c mov r0, #1 */
/* @0x1f8e40 str r3, [r2, #0xc] */
/* @0x1f8e44 vmov s15, r4 */
/* @0x1f8e48 vcvt.f64.s32 d7, s15 */
/* @0x1f8e4c vmov r4, r5, d7 */
/* @0x1f8e50 vmov r1, s14 */
/* @0x1f8e54 mov r3, r5 */
/* @0x1f8e58 pop {r4, r5} */
/* @0x1f8e5c stm r2, {r1, r3} */
/* @0x1f8e60 bx lr */

/* ── FUNC 0x1f8e64 · GV_Solid(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f8e64 push {r4, r5} */
/* @0x1f8e68 mov r3, #0 */
/* @0x1f8e6c ldrb r4, [r0, #0x66] */
/* @0x1f8e70 mov r0, #1 */
/* @0x1f8e74 str r3, [r2, #0xc] */
/* @0x1f8e78 vmov s15, r4 */
/* @0x1f8e7c vcvt.f64.u32 d7, s15 */
/* @0x1f8e80 vmov r4, r5, d7 */
/* @0x1f8e84 vmov r1, s14 */
/* @0x1f8e88 mov r3, r5 */
/* @0x1f8e8c pop {r4, r5} */
/* @0x1f8e90 stm r2, {r1, r3} */
/* @0x1f8e94 bx lr */

/* ── FUNC 0x1f8e98 · GV_Visible(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f8e98 push {r4, r5} */
/* @0x1f8e9c mov r3, #0 */
/* @0x1f8ea0 ldrb r4, [r0, #0x65] */
/* @0x1f8ea4 mov r0, #1 */
/* @0x1f8ea8 str r3, [r2, #0xc] */
/* @0x1f8eac vmov s15, r4 */
/* @0x1f8eb0 vcvt.f64.u32 d7, s15 */
/* @0x1f8eb4 vmov r4, r5, d7 */
/* @0x1f8eb8 vmov r1, s14 */
/* @0x1f8ebc mov r3, r5 */
/* @0x1f8ec0 pop {r4, r5} */
/* @0x1f8ec4 stm r2, {r1, r3} */
/* @0x1f8ec8 bx lr */

/* ── FUNC 0x1f8ecc · GV_Persistent(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f8ecc push {r4, r5} */
/* @0x1f8ed0 mov r3, #0 */
/* @0x1f8ed4 ldrb r4, [r0, #0x67] */
/* @0x1f8ed8 mov r0, #1 */
/* @0x1f8edc str r3, [r2, #0xc] */
/* @0x1f8ee0 vmov s15, r4 */
/* @0x1f8ee4 vcvt.f64.u32 d7, s15 */
/* @0x1f8ee8 vmov r4, r5, d7 */
/* @0x1f8eec vmov r1, s14 */
/* @0x1f8ef0 mov r3, r5 */
/* @0x1f8ef4 pop {r4, r5} */
/* @0x1f8ef8 stm r2, {r1, r3} */
/* @0x1f8efc bx lr */

/* ── FUNC 0x1f8f00 · GV_ObjectIndex(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1f8f00 push {r4, r5} */
/* @0x1f8f04 mov r3, #0 */
/* @0x1f8f08 ldr r4, [r0, #0x7c] */
/* @0x1f8f0c mov r0, #1 */
/* @0x1f8f10 str r3, [r2, #0xc] */
/* @0x1f8f14 vmov s15, r4 */
/* @0x1f8f18 vcvt.f64.s32 d7, s15 */
/* @0x1f8f1c vmov r4, r5, d7 */
/* @0x1f8f20 vmov r1, s14 */
/* @0x1f8f24 mov r3, r5 */
/* @0x1f8f28 pop {r4, r5} */
/* @0x1f8f2c stm r2, {r1, r3} */
/* @0x1f8f30 bx lr */
