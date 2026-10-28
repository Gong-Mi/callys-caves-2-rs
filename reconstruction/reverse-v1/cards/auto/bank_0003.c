/* libyoyo.so 覆盖卡组 0003
 * 函数 0xc2b58..0xc3ff4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc2b58 · CBackground::CBackground() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc2b80 · CBackground::Assign(CBackground*) · size=180 · insn=45 */
/* @0xc2b80 push {r4, r5, r6, lr} */
/* @0xc2b84 mov r4, r1 */
/* @0xc2b88 mov r5, r0 */
/* @0xc2b8c bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2b90 ldrb r3, [r4, #0x18] */
/* @0xc2b94 ldrb r2, [r4, #0xa] */
/* @0xc2b98 cmp r3, #0 */
/* @0xc2b9c ldr lr, [r4] */
/* @0xc2ba0 ldr r12, [r4, #0x4] */
/* @0xc2ba4 ldrb r0, [r4, #0x8] */
/* @0xc2ba8 ldrb r1, [r4, #0x9] */
/* @0xc2bac strb r2, [r5, #0xa] */
/* @0xc2bb0 ldreq r2, [r4, #0x14] */
/* @0xc2bb4 strbeq r3, [r5, #0x18] */
/* @0xc2bb8 ldr r3, [r4, #0x10] */
/* @0xc2bbc streq r2, [r5, #0x14] */
/* @0xc2bc0 cmp r3, #0 */
/* @0xc2bc4 str lr, [r5] */
/* @0xc2bc8 str r12, [r5, #0x4] */
/* @0xc2bcc strb r0, [r5, #0x8] */
/* @0xc2bd0 strb r1, [r5, #0x9] */
/* @0xc2bd4 beq 0xc2c08 <_ZN11CBackground6AssignEPS_+0x88> */
/* @0xc2bd8 ldr r0, [r5, #0x10] */
/* @0xc2bdc cmp r0, #0 */
/* @0xc2be0 beq 0xc2bf0 <_ZN11CBackground6AssignEPS_+0x70> */
/* @0xc2be4 ldr r3, [r0] */
/* @0xc2be8 ldr r3, [r3, #0x4] */
/* @0xc2bec blx r3 */
/* @0xc2bf0 mov r0, #24 */
/* @0xc2bf4 bl 0x27c524 <_Znwj> */
/* @0xc2bf8 ldr r1, [r4, #0x10] */
/* @0xc2bfc mov r6, r0 */
/* @0xc2c00 bl 0x165f98 <_ZN9CBitmap32C2EPS_> */
/* @0xc2c04 str r6, [r5, #0x10] */
/* @0xc2c08 mov r0, r5 */
/* @0xc2c0c bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc2c10 ldr r3, [r4, #0x14] */
/* @0xc2c14 cmp r3, #0 */
/* @0xc2c18 beq 0xc2c28 <_ZN11CBackground6AssignEPS_+0xa8> */
/* @0xc2c1c ldrb r3, [r4, #0x18] */
/* @0xc2c20 cmp r3, #0 */
/* @0xc2c24 popeq {r4, r5, r6, pc} */
/* @0xc2c28 mov r0, r5 */
/* @0xc2c2c pop {r4, r5, r6, lr} */
/* @0xc2c30 b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */

/* ── FUNC 0xc2c34 · CBackground::GetBitmap24() · size=16 · insn=4 */
/* @0xc2c34 ldr r0, [r0, #0x10] */
/* @0xc2c38 cmp r0, #0 */
/* @0xc2c3c bxeq lr */
/* @0xc2c40 b 0x1675e8 <_ZN9CBitmap3214CreateBitmap24Ev> */

/* ── FUNC 0xc2c44 · CBackground::LoadFromChunk(YYBackground*, unsigned char*) · size=260 · insn=65 */
/* @0xc2c44 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc2c48 mov r5, r1 */
/* @0xc2c4c mov r4, r0 */
/* @0xc2c50 bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2c54 ldr r3, [r5, #0x10] */
/* @0xc2c58 cmp r3, #0 */
/* @0xc2c5c bne 0xc2d1c <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0xd8> */
/* @0xc2c60 mov r3, #0 */
/* @0xc2c64 str r3, [r4] */
/* @0xc2c68 mov r2, r3 */
/* @0xc2c6c str r3, [r4, #0x4] */
/* @0xc2c70 ldr r6, [r5, #0x4] */
/* @0xc2c74 mov r1, #0 */
/* @0xc2c78 ldr r0, [r5, #0x8] */
/* @0xc2c7c subs r6, r6, r1 */
/* @0xc2c80 ldr r3, [pc, #0xb8] */
/* @0xc2c84 ldr r7, [r5, #0xc] */
/* @0xc2c88 ldr r3, [pc, r3] */
/* @0xc2c8c movne r6, #1 */
/* @0xc2c90 subs r0, r0, r1 */
/* @0xc2c94 strb r6, [r4, #0x8] */
/* @0xc2c98 ldrb r12, [r3] */
/* @0xc2c9c movne r0, #1 */
/* @0xc2ca0 subs r3, r7, r1 */
/* @0xc2ca4 strb r0, [r4, #0x9] */
/* @0xc2ca8 movne r3, #1 */
/* @0xc2cac cmp r12, r1 */
/* @0xc2cb0 strb r3, [r4, #0xa] */
/* @0xc2cb4 str r2, [r4, #0x14] */
/* @0xc2cb8 str r1, [r4, #0x10] */
/* @0xc2cbc beq 0xc2d14 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0xd0> */
/* @0xc2cc0 ldr r3, [r5, #0x14] */
/* @0xc2cc4 cmp r3, #1 */
/* @0xc2cc8 ble 0xc2d14 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0xd0> */
/* @0xc2ccc ldr r10, [r5, #0x18] */
/* @0xc2cd0 add r1, r5, #64 */
/* @0xc2cd4 ldr r9, [r5, #0x1c] */
/* @0xc2cd8 ldr r8, [r5, #0x20] */
/* @0xc2cdc ldr r7, [r5, #0x24] */
/* @0xc2ce0 ldr r6, [r5, #0x28] */
/* @0xc2ce4 ldr r12, [r5, #0x2c] */
/* @0xc2ce8 ldr r0, [r5, #0x30] */
/* @0xc2cec ldrd r2, r3, [r5, #56] */
/* @0xc2cf0 str r10, [r4, #0x1c] */
/* @0xc2cf4 str r9, [r4, #0x20] */
/* @0xc2cf8 str r8, [r4, #0x24] */
/* @0xc2cfc str r7, [r4, #0x28] */
/* @0xc2d00 str r6, [r4, #0x2c] */
/* @0xc2d04 str r12, [r4, #0x30] */
/* @0xc2d08 str r0, [r4, #0x34] */
/* @0xc2d0c strd r2, r3, [r4, #56] */
/* @0xc2d10 str r1, [r4, #0x40] */
/* @0xc2d14 mov r0, #1 */
/* @0xc2d18 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc2d1c ldr r2, [pc, #0x20] */
/* @0xc2d20 ldr r2, [pc, r2] */
/* @0xc2d24 ldr r2, [r2] */
/* @0xc2d28 adds r2, r2, r3 */
/* @0xc2d2c beq 0xc2c60 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0x1c> */
/* @0xc2d30 ldrsh r1, [r2, #16] */
/* @0xc2d34 ldrsh r3, [r2, #18] */
/* @0xc2d38 stm r4, {r1, r3} */
/* @0xc2d3c b 0xc2c70 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh+0x2c> */
/* @0xc2d40 mlaseq r2, r12, r12, r10 */
/* @0xc2d44 eorseq r10, r2, r4, lsr #24 */

/* ── FUNC 0xc2d48 · CBackground::~CBackground() · size=20 · insn=5 */
/* @0xc2d48 push {r4, lr} */
/* @0xc2d4c mov r4, r0 */
/* @0xc2d50 bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2d54 mov r0, r4 */
/* @0xc2d58 pop {r4, pc} */

/* ── FUNC 0xc2d48 · CBackground::~CBackground() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc2d5c · CBackground::Free() · size=28 · insn=7 */
/* @0xc2d5c push {r4, lr} */
/* @0xc2d60 subs r4, r0, #0 */
/* @0xc2d64 popeq {r4, pc} */
/* @0xc2d68 bl 0xc2d48 <_ZN11CBackgroundD2Ev> */
/* @0xc2d6c mov r0, r4 */
/* @0xc2d70 pop {r4, lr} */
/* @0xc2d74 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0xc2d78 · CBackground::GetWidth() · size=8 · insn=2 */
/* @0xc2d78 ldr r0, [r0] */
/* @0xc2d7c bx lr */

/* ── FUNC 0xc2d80 · CBackground::GetHeight() · size=8 · insn=2 */
/* @0xc2d80 ldr r0, [r0, #0x4] */
/* @0xc2d84 bx lr */

/* ── FUNC 0xc2d88 · CBackground::GetTransparent() · size=8 · insn=2 */
/* @0xc2d88 ldrb r0, [r0, #0x8] */
/* @0xc2d8c bx lr */

/* ── FUNC 0xc2d90 · CBackground::Smooth() · size=8 · insn=2 */
/* @0xc2d90 ldrb r0, [r0, #0x9] */
/* @0xc2d94 bx lr */

/* ── FUNC 0xc2d98 · CBackground::GetPreload() · size=8 · insn=2 */
/* @0xc2d98 ldrb r0, [r0, #0xa] */
/* @0xc2d9c bx lr */

/* ── FUNC 0xc2da0 · CBackground::GenerateBitmapData() · size=652 · insn=163 */
/* @0xc2da0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc2da4 mov r4, r0 */
/* @0xc2da8 ldr r6, [r0, #0x10] */
/* @0xc2dac sub sp, sp, #20 */
/* @0xc2db0 cmp r6, #0 */
/* @0xc2db4 beq 0xc2dc4 <_ZN11CBackground18GenerateBitmapDataEv+0x24> */
/* @0xc2db8 mov r0, #0 */
/* @0xc2dbc add sp, sp, #20 */
/* @0xc2dc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc2dc4 ldr r3, [pc, #0x25c] */
/* @0xc2dc8 ldr r0, [r0, #0x14] */
/* @0xc2dcc ldr r3, [pc, r3] */
/* @0xc2dd0 ldrsh r12, [r0, #20] */
/* @0xc2dd4 ldr r3, [r3, #0x4] */
/* @0xc2dd8 ldrsh r1, [r0] */
/* @0xc2ddc ldrsh r2, [r0, #2] */
/* @0xc2de0 ldr lr, [r3, r12, lsl #2] */
/* @0xc2de4 ldrsh r12, [r0, #6] */
/* @0xc2de8 ldrsh r3, [r0, #4] */
/* @0xc2dec ldr r0, [lr] */
/* @0xc2df0 str r12, [sp] */
/* @0xc2df4 bl 0x17e2a8 <_ZN8Graphics16Texture_GrabRectEPviiii> */
/* @0xc2df8 subs r9, r0, #0 */
/* @0xc2dfc beq 0xc2db8 <_ZN11CBackground18GenerateBitmapDataEv+0x18> */
/* @0xc2e00 ldr r3, [r4, #0x14] */
/* @0xc2e04 ldrsh r2, [r3, #12] */
/* @0xc2e08 ldrsh r3, [r3, #4] */
/* @0xc2e0c vmov s14, r2 */
/* @0xc2e10 vmov s15, r3 */
/* @0xc2e14 vcvt.f32.s32 s14, s14 */
/* @0xc2e18 vcvt.f32.s32 s15, s15 */
/* @0xc2e1c vdiv.f32 s15, s14, s15 */
/* @0xc2e20 vcvt.s32.f32 s15, s15 */
/* @0xc2e24 vmov r8, s15 */
/* @0xc2e28 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0xc2e2c mov r1, #7 */
/* @0xc2e30 ldr r3, [r0] */
/* @0xc2e34 mov r7, r0 */
/* @0xc2e38 ldr r3, [r3, #0x1c] */
/* @0xc2e3c blx r3 */
/* @0xc2e40 ldr r3, [r4, #0x14] */
/* @0xc2e44 mov r1, r8 */
/* @0xc2e48 ldr r5, [r7] */
/* @0xc2e4c ldrsh r0, [r3, #16] */
/* @0xc2e50 bl 0x318d10 <__divsi3> */
/* @0xc2e54 ldr r3, [r5, #0xc] */
/* @0xc2e58 mov r1, r0 */
/* @0xc2e5c mov r0, r7 */
/* @0xc2e60 blx r3 */
/* @0xc2e64 ldr r3, [r4, #0x14] */
/* @0xc2e68 mov r1, r8 */
/* @0xc2e6c ldr r5, [r7] */
/* @0xc2e70 ldrsh r0, [r3, #18] */
/* @0xc2e74 bl 0x318d10 <__divsi3> */
/* @0xc2e78 ldr r3, [r5, #0x14] */
/* @0xc2e7c mov r1, r0 */
/* @0xc2e80 mov r0, r7 */
/* @0xc2e84 blx r3 */
/* @0xc2e88 add r2, sp, #16 */
/* @0xc2e8c mov r1, r6 */
/* @0xc2e90 add r3, sp, #8 */
/* @0xc2e94 str r6, [r2, #-0x4]! */
/* @0xc2e98 mov r0, r7 */
/* @0xc2e9c ldr r12, [r7] */
/* @0xc2ea0 str r6, [sp, #0x8] */
/* @0xc2ea4 ldr r12, [r12, #0x24] */
/* @0xc2ea8 blx r12 */
/* @0xc2eac ldr r3, [r7] */
/* @0xc2eb0 ldr r5, [sp, #0xc] */
/* @0xc2eb4 ldr r3, [r3, #0x18] */
/* @0xc2eb8 mov r10, r0 */
/* @0xc2ebc mov r0, r7 */
/* @0xc2ec0 blx r3 */
/* @0xc2ec4 ldr r2, [sp, #0x8] */
/* @0xc2ec8 mov r1, r6 */
/* @0xc2ecc mul r2, r2, r0 */
/* @0xc2ed0 mov r0, r5 */
/* @0xc2ed4 bl 0xb65b0 <memset@plt> */
/* @0xc2ed8 ldr r5, [r4, #0x14] */
/* @0xc2edc mov r1, r8 */
/* @0xc2ee0 ldrsh r0, [r5, #10] */
/* @0xc2ee4 bl 0x318d10 <__divsi3> */
/* @0xc2ee8 ldr r3, [sp, #0xc] */
/* @0xc2eec ldr r11, [sp, #0x8] */
/* @0xc2ef0 mov r1, r8 */
/* @0xc2ef4 mla r11, r11, r0, r3 */
/* @0xc2ef8 ldrsh r0, [r5, #8] */
/* @0xc2efc bl 0x318d10 <__divsi3> */
/* @0xc2f00 ldrsh r3, [r5, #6] */
/* @0xc2f04 cmp r3, #0 */
/* @0xc2f08 ldrhgt r3, [r5, #4] */
/* @0xc2f0c movgt r5, r9 */
/* @0xc2f10 add r0, r11, r0, lsl #2 */
/* @0xc2f14 str r0, [sp, #0xc] */
/* @0xc2f18 ble 0xc2f5c <_ZN11CBackground18GenerateBitmapDataEv+0x1bc> */
/* @0xc2f1c sxth r2, r3 */
/* @0xc2f20 mov r1, r5 */
/* @0xc2f24 add r6, r6, #1 */
/* @0xc2f28 lsl r2, r2, #2 */
/* @0xc2f2c bl 0xb65bc <memcpy@plt> */
/* @0xc2f30 ldr r2, [r4, #0x14] */
/* @0xc2f34 ldr r0, [sp, #0xc] */
/* @0xc2f38 ldr r1, [sp, #0x8] */
/* @0xc2f3c ldrh r3, [r2, #4] */
/* @0xc2f40 ldrsh r2, [r2, #6] */
/* @0xc2f44 add r0, r0, r1 */
/* @0xc2f48 str r0, [sp, #0xc] */
/* @0xc2f4c cmp r2, r6 */
/* @0xc2f50 sxth r2, r3 */
/* @0xc2f54 add r5, r5, r2, lsl #2 */
/* @0xc2f58 bgt 0xc2f1c <_ZN11CBackground18GenerateBitmapDataEv+0x17c> */
/* @0xc2f5c ldr r3, [r7] */
/* @0xc2f60 mov r1, r10 */
/* @0xc2f64 mov r0, r7 */
/* @0xc2f68 ldr r3, [r3, #0x28] */
/* @0xc2f6c blx r3 */
/* @0xc2f70 mov r0, r9 */
/* @0xc2f74 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc2f78 mov r0, #24 */
/* @0xc2f7c bl 0x27c524 <_Znwj> */
/* @0xc2f80 mov r3, #0 */
/* @0xc2f84 mov r2, r3 */
/* @0xc2f88 mov r1, r7 */
/* @0xc2f8c str r3, [sp] */
/* @0xc2f90 mov r5, r0 */
/* @0xc2f94 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi> */
/* @0xc2f98 ldr r3, [r7] */
/* @0xc2f9c mov r0, r7 */
/* @0xc2fa0 str r5, [r4, #0x10] */
/* @0xc2fa4 ldr r3, [r3, #0x4] */
/* @0xc2fa8 blx r3 */
/* @0xc2fac ldr r3, [r4, #0x14] */
/* @0xc2fb0 cmp r3, #0 */
/* @0xc2fb4 beq 0xc3014 <_ZN11CBackground18GenerateBitmapDataEv+0x274> */
/* @0xc2fb8 ldrb r3, [r4, #0x18] */
/* @0xc2fbc mov r0, r4 */
/* @0xc2fc0 cmp r3, #0 */
/* @0xc2fc4 streq r3, [r4, #0x14] */
/* @0xc2fc8 bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc2fcc mov r0, r4 */
/* @0xc2fd0 bl 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */
/* @0xc2fd4 ldr r3, [r4, #0x14] */
/* @0xc2fd8 cmp r3, #0 */
/* @0xc2fdc beq 0xc300c <_ZN11CBackground18GenerateBitmapDataEv+0x26c> */
/* @0xc2fe0 ldrh r2, [r3, #14] */
/* @0xc2fe4 uxth r8, r8 */
/* @0xc2fe8 ldrh r1, [r3, #12] */
/* @0xc2fec mul r1, r1, r8 */
/* @0xc2ff0 mul r8, r2, r8 */
/* @0xc2ff4 uxth r1, r1 */
/* @0xc2ff8 strh r1, [r3, #12] */
/* @0xc2ffc strh r1, [r3, #16] */
/* @0xc3000 uxth r2, r8 */
/* @0xc3004 strh r2, [r3, #14] */
/* @0xc3008 strh r2, [r3, #18] */
/* @0xc300c mov r0, #1 */
/* @0xc3010 b 0xc2dbc <_ZN11CBackground18GenerateBitmapDataEv+0x1c> */
/* @0xc3014 mov r0, r4 */
/* @0xc3018 bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc301c mov r0, r4 */
/* @0xc3020 bl 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */
/* @0xc3024 b 0xc300c <_ZN11CBackground18GenerateBitmapDataEv+0x26c> */
/* @0xc3028 eorseq r10, r2, r0, asr r11 */

/* ── FUNC 0xc302c · ASYNCFunc_BackgroundCleanup(HTTP_REQ_CONTEXT*) · size=8 · insn=2 */
/* @0xc302c ldr r0, [r0, #0x1c] */
/* @0xc3030 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0xc3034 · ASYNCFunc_BackgroundAdd(HTTP_REQ_CONTEXT*, void*, int*) · size=616 · insn=154 */
/* @0xc3034 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc3038 vldr s12, [r0, #40] */
/* @0xc303c vmov.f64 d7, #-1.000000e+00 */
/* @0xc3040 ldr r8, [r1] */
/* @0xc3044 mov r7, r1 */
/* @0xc3048 ldr r1, [r0, #0x3c] */
/* @0xc304c sub sp, sp, #60 */
/* @0xc3050 mov r12, #0 */
/* @0xc3054 mov r9, r2 */
/* @0xc3058 vmov s13, r8 */
/* @0xc305c cmp r1, r12 */
/* @0xc3060 ldr r1, [pc, #0x210] */
/* @0xc3064 mov r4, #0 */
/* @0xc3068 ldr r2, [r0, #0x20] */
/* @0xc306c mov r5, #0 */
/* @0xc3070 add r1, pc, r1 */
/* @0xc3074 ldr r3, [pc, #0x200] */
/* @0xc3078 str r1, [sp, #0x24] */
/* @0xc307c mov r6, r0 */
/* @0xc3080 ldr lr, [pc, #0x1f8] */
/* @0xc3084 add r3, pc, r3 */
/* @0xc3088 vcvt.f64.s32 d5, s13 */
/* @0xc308c ldr r1, [pc, #0x1f0] */
/* @0xc3090 stm sp, {r2, r3} */
/* @0xc3094 vmovgt d7, r4, r5 */
/* @0xc3098 add lr, pc, lr */
/* @0xc309c mov r3, r5 */
/* @0xc30a0 str r12, [sp, #0x10] */
/* @0xc30a4 mov r0, #4 */
/* @0xc30a8 str r12, [sp, #0x20] */
/* @0xc30ac mov r2, r4 */
/* @0xc30b0 str r12, [sp, #0x30] */
/* @0xc30b4 add r1, pc, r1 */
/* @0xc30b8 str lr, [sp, #0x14] */
/* @0xc30bc vstr d7, [sp, #40] */
/* @0xc30c0 vcvt.f64.s32 d6, s12 */
/* @0xc30c4 vstr d5, [sp, #8] */
/* @0xc30c8 vstr d6, [sp, #24] */
/* @0xc30cc bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xc30d0 str r0, [r9] */
/* @0xc30d4 ldr r3, [r6, #0x28] */
/* @0xc30d8 ldr r12, [r7, #0x4] */
/* @0xc30dc cmp r3, #200 */
/* @0xc30e0 beq 0xc30f0 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xbc> */
/* @0xc30e4 mov r0, #60 */
/* @0xc30e8 add sp, sp, #60 */
/* @0xc30ec pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xc30f0 ldr r2, [r6, #0x3c] */
/* @0xc30f4 cmp r2, #0 */
/* @0xc30f8 ble 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0> */
/* @0xc30fc ldr r3, [pc, #0x184] */
/* @0xc3100 add r3, pc, r3 */
/* @0xc3104 ldr r3, [r3, #0x4] */
/* @0xc3108 ldr r0, [r3, r8, lsl #2] */
/* @0xc310c cmp r0, #0 */
/* @0xc3110 beq 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0> */
/* @0xc3114 ldr r4, [r6, #0x34] */
/* @0xc3118 and r3, r12, #1 */
/* @0xc311c eor r5, r3, #1 */
/* @0xc3120 ldrb r1, [r4] */
/* @0xc3124 cmp r1, #255 */
/* @0xc3128 beq 0xc3170 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x13c> */
/* @0xc312c cmp r1, #71 */
/* @0xc3130 bne 0xc320c <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x1d8> */
/* @0xc3134 ldrb r3, [r4, #0x1] */
/* @0xc3138 cmp r3, #73 */
/* @0xc313c beq 0xc31b4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x180> */
/* @0xc3140 ldr r3, [pc, #0x144] */
/* @0xc3144 ldr r1, [pc, #0x144] */
/* @0xc3148 ldr r3, [pc, r3] */
/* @0xc314c ldr r2, [r6, #0x20] */
/* @0xc3150 add r1, pc, r1 */
/* @0xc3154 ldr r0, [r3] */
/* @0xc3158 ldr r3, [r0] */
/* @0xc315c ldr r3, [r3, #0xc] */
/* @0xc3160 blx r3 */
/* @0xc3164 mov r0, #60 */
/* @0xc3168 add sp, sp, #60 */
/* @0xc316c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xc3170 ldrb r1, [r4, #0x1] */
/* @0xc3174 cmp r1, #216 */
/* @0xc3178 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc317c ldrb r1, [r4, #0x2] */
/* @0xc3180 cmp r1, #255 */
/* @0xc3184 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc3188 ubfx r1, r12, #0x1, #0x1 */
/* @0xc318c str r5, [sp, #0x8] */
/* @0xc3190 ubfx r12, r12, #0x2, #0x1 */
/* @0xc3194 str r1, [sp] */
/* @0xc3198 str r12, [sp, #0x4] */
/* @0xc319c mov r1, r4 */
/* @0xc31a0 bl 0xc271c <_ZN11CBackground16LoadFromJPEGDataEPvibbbb> */
/* @0xc31a4 cmp r0, #0 */
/* @0xc31a8 bne 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0> */
/* @0xc31ac ldrb r1, [r4] */
/* @0xc31b0 b 0xc312c <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xf8> */
/* @0xc31b4 ldrb r3, [r4, #0x2] */
/* @0xc31b8 cmp r3, #70 */
/* @0xc31bc bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc31c0 ldrb r3, [r4, #0x3] */
/* @0xc31c4 cmp r3, #56 */
/* @0xc31c8 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc31cc ldr r2, [pc, #0xc0] */
/* @0xc31d0 ldr r3, [r7, #0x4] */
/* @0xc31d4 add r2, pc, r2 */
/* @0xc31d8 str r5, [sp, #0x8] */
/* @0xc31dc ubfx r0, r3, #0x1, #0x1 */
/* @0xc31e0 ubfx r1, r3, #0x2, #0x1 */
/* @0xc31e4 ldr r2, [r2, #0x4] */
/* @0xc31e8 and r3, r3, #1 */
/* @0xc31ec stm sp, {r0, r1} */
/* @0xc31f0 ldr r1, [r6, #0x34] */
/* @0xc31f4 ldr r0, [r2, r8, lsl #2] */
/* @0xc31f8 ldr r2, [r6, #0x3c] */
/* @0xc31fc bl 0xc279c <_ZN11CBackground15LoadFromGIFDataEPvibbbb> */
/* @0xc3200 cmp r0, #0 */
/* @0xc3204 bne 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0> */
/* @0xc3208 ldrb r1, [r4] */
/* @0xc320c cmp r1, #137 */
/* @0xc3210 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc3214 ldrb r3, [r4, #0x1] */
/* @0xc3218 cmp r3, #80 */
/* @0xc321c bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc3220 ldrb r3, [r4, #0x2] */
/* @0xc3224 cmp r3, #78 */
/* @0xc3228 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc322c ldrb r3, [r4, #0x3] */
/* @0xc3230 cmp r3, #71 */
/* @0xc3234 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc3238 ldr r2, [pc, #0x58] */
/* @0xc323c ldr r3, [r7, #0x4] */
/* @0xc3240 add r2, pc, r2 */
/* @0xc3244 str r5, [sp, #0x8] */
/* @0xc3248 ubfx r0, r3, #0x1, #0x1 */
/* @0xc324c ubfx r1, r3, #0x2, #0x1 */
/* @0xc3250 ldr r2, [r2, #0x4] */
/* @0xc3254 and r3, r3, #1 */
/* @0xc3258 stm sp, {r0, r1} */
/* @0xc325c ldr r1, [r6, #0x34] */
/* @0xc3260 ldr r0, [r2, r8, lsl #2] */
/* @0xc3264 ldr r2, [r6, #0x3c] */
/* @0xc3268 bl 0xc26ac <_ZN11CBackground15LoadFromPNGDataEPvibbbb> */
/* @0xc326c cmp r0, #0 */
/* @0xc3270 bne 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0> */
/* @0xc3274 b 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c> */
/* @0xc3278 eoreq sp, r6, r0, ror #19 */
/* @0xc327c .word 0x0026d9bc */
/* @0xc3280 eoreq sp, r6, r12, lsr #19 */
/* @0xc3284 eoreq sp, r6, r0, lsl #19 */
/* @0xc3288 eorseq r6, r11, r8, lsr #23 */
/* @0xc328c eorseq r10, r2, r12, asr #11 */
/* @0xc3290 eoreq sp, r6, r8, lsl #18 */
/* @0xc3294 ldrsbteq r6, [r11], -r4 */
/* @0xc3298 eorseq r6, r11, r8, ror #20 */

/* ── FUNC 0xc329c · Background_Init() · size=180 · insn=45 */
/* @0xc329c push {r3, r4, r5, r6, r7, lr} */
/* @0xc32a0 ldr r3, [pc, #0x94] */
/* @0xc32a4 add r3, pc, r3 */
/* @0xc32a8 ldr r3, [r3, #0x4] */
/* @0xc32ac cmp r3, #0 */
/* @0xc32b0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0xc32b4 ldr r5, [pc, #0x84] */
/* @0xc32b8 ldr r5, [pc, r5] */
/* @0xc32bc ldr r2, [r5] */
/* @0xc32c0 cmp r2, #0 */
/* @0xc32c4 ble 0xc3304 <_Z15Background_Initv+0x68> */
/* @0xc32c8 ldr r6, [pc, #0x74] */
/* @0xc32cc mov r4, #0 */
/* @0xc32d0 mov r7, r4 */
/* @0xc32d4 add r6, pc, r6 */
/* @0xc32d8 ldr r0, [r3, r4, lsl #2] */
/* @0xc32dc cmp r0, #0 */
/* @0xc32e0 beq 0xc32f4 <_Z15Background_Initv+0x58> */
/* @0xc32e4 bl 0xc2d5c <_ZN11CBackground4FreeEv> */
/* @0xc32e8 ldr r3, [r6, #0x4] */
/* @0xc32ec str r7, [r3, r4, lsl #2] */
/* @0xc32f0 ldr r3, [r6, #0x4] */
/* @0xc32f4 ldr r2, [r5] */
/* @0xc32f8 add r4, r4, #1 */
/* @0xc32fc cmp r2, r4 */
/* @0xc3300 bgt 0xc32d8 <_Z15Background_Initv+0x3c> */
/* @0xc3304 mov r0, r3 */
/* @0xc3308 ldr r6, [pc, #0x38] */
/* @0xc330c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc3310 ldr r3, [pc, #0x34] */
/* @0xc3314 ldr r6, [pc, r6] */
/* @0xc3318 mov r4, #0 */
/* @0xc331c add r3, pc, r3 */
/* @0xc3320 ldr r0, [r6] */
/* @0xc3324 str r4, [r3, #0x4] */
/* @0xc3328 str r4, [r3] */
/* @0xc332c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc3330 str r4, [r6] */
/* @0xc3334 str r4, [r5] */
/* @0xc3338 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc333c eorseq r6, r11, r4, lsl #20 */
/* @0xc3340 mlaseq r2, r0, r6, r10 */
/* @0xc3344 ldrsbteq r6, [r11], -r4 */
/* @0xc3348 eorseq r10, r2, r8, lsr r6 */
/* @0xc334c eorseq r6, r11, r12, lsl #19 */

/* ── FUNC 0xc3350 · Background_Load(unsigned char*, unsigned int, unsigned char*) · size=384 · insn=96 */
/* @0xc3350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc3354 sub sp, sp, #20 */
/* @0xc3358 ldr r9, [r0] */
/* @0xc335c mov r3, #92 */
/* @0xc3360 ldr r4, [pc, #0x150] */
/* @0xc3364 mov r8, r0 */
/* @0xc3368 ldr r12, [pc, #0x14c] */
/* @0xc336c ldr r10, [pc, #0x14c] */
/* @0xc3370 add r4, pc, r4 */
/* @0xc3374 lsl r5, r9, #2 */
/* @0xc3378 ldr r12, [pc, r12] */
/* @0xc337c add r10, pc, r10 */
/* @0xc3380 ldr r6, [pc, #0x13c] */
/* @0xc3384 str r2, [sp, #0x8] */
/* @0xc3388 add r0, r10, #4 */
/* @0xc338c mov r2, r4 */
/* @0xc3390 mov r1, r5 */
/* @0xc3394 str r9, [r12] */
/* @0xc3398 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc339c ldr r6, [pc, r6] */
/* @0xc33a0 mov r1, r5 */
/* @0xc33a4 mov r2, r4 */
/* @0xc33a8 mov r3, #94 */
/* @0xc33ac mov r0, r6 */
/* @0xc33b0 str r9, [r10] */
/* @0xc33b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc33b8 cmp r9, #0 */
/* @0xc33bc beq 0xc34a4 <_Z15Background_LoadPhjS_+0x154> */
/* @0xc33c0 ldr r3, [pc, #0x100] */
/* @0xc33c4 mov r4, #0 */
/* @0xc33c8 str r9, [sp, #0x4] */
/* @0xc33cc add r3, pc, r3 */
/* @0xc33d0 str r3, [sp, #0xc] */
/* @0xc33d4 b 0xc3490 <_Z15Background_LoadPhjS_+0x140> */
/* @0xc33d8 ldr r9, [pc, #0xec] */
/* @0xc33dc ldr r9, [pc, r9] */
/* @0xc33e0 ldr r11, [r9] */
/* @0xc33e4 adds r1, r11, r5 */
/* @0xc33e8 beq 0xc34b0 <_Z15Background_LoadPhjS_+0x160> */
/* @0xc33ec mov r0, #72 */
/* @0xc33f0 str r1, [sp] */
/* @0xc33f4 bl 0x27c524 <_Znwj> */
/* @0xc33f8 mov r7, r0 */
/* @0xc33fc bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc3400 ldr r1, [sp] */
/* @0xc3404 mov r0, r7 */
/* @0xc3408 ldr r2, [sp, #0x8] */
/* @0xc340c bl 0xc2c44 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh> */
/* @0xc3410 ldr r12, [r11, r5] */
/* @0xc3414 cmp r12, #0 */
/* @0xc3418 ldrne r3, [r9] */
/* @0xc341c moveq r11, r12 */
/* @0xc3420 addne r11, r3, r12 */
/* @0xc3424 mov r0, r11 */
/* @0xc3428 bl 0xb6538 <strlen@plt> */
/* @0xc342c ldr r1, [sp, #0xc] */
/* @0xc3430 mov r3, #1 */
/* @0xc3434 mov r2, #105 */
/* @0xc3438 add r0, r0, r3 */
/* @0xc343c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc3440 mov r1, r11 */
/* @0xc3444 mov r5, r0 */
/* @0xc3448 bl 0xb65a4 <strcpy@plt> */
/* @0xc344c ldr r2, [r6] */
/* @0xc3450 lsl r11, r4, #2 */
/* @0xc3454 ldr r0, [r2, r4, lsl #2] */
/* @0xc3458 cmp r0, #0 */
/* @0xc345c beq 0xc3470 <_Z15Background_LoadPhjS_+0x120> */
/* @0xc3460 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc3464 ldr r2, [r6] */
/* @0xc3468 mov r3, #0 */
/* @0xc346c str r3, [r2, r4, lsl #2] */
/* @0xc3470 ldr r2, [r10, #0x4] */
/* @0xc3474 add r4, r4, #1 */
/* @0xc3478 ldr r3, [sp, #0x4] */
/* @0xc347c str r7, [r2, r11] */
/* @0xc3480 cmp r4, r3 */
/* @0xc3484 ldr r2, [r6] */
/* @0xc3488 str r5, [r2, r11] */
/* @0xc348c beq 0xc34a4 <_Z15Background_LoadPhjS_+0x154> */
/* @0xc3490 ldr r5, [r8, #0x4]! */
/* @0xc3494 cmp r5, #0 */
/* @0xc3498 bne 0xc33d8 <_Z15Background_LoadPhjS_+0x88> */
/* @0xc349c mov r7, r5 */
/* @0xc34a0 b 0xc344c <_Z15Background_LoadPhjS_+0xfc> */
/* @0xc34a4 mov r0, #1 */
/* @0xc34a8 add sp, sp, #20 */
/* @0xc34ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc34b0 mov r5, r1 */
/* @0xc34b4 b 0xc349c <_Z15Background_LoadPhjS_+0x14c> */
/* @0xc34b8 eoreq sp, r6, r0, lsl r7 */
/* @0xc34bc ldrsbteq r10, [r2], -r0 */
/* @0xc34c0 eorseq r6, r11, r12, lsr #18 */
/* @0xc34c4 ldrhteq r10, [r2], -r0 */
/* @0xc34c8 .word 0x0026d6b4 */
/* @0xc34cc eorseq r10, r2, r8, ror #10 */

/* ── FUNC 0xc34d0 · Background_Free() · size=168 · insn=42 */
/* @0xc34d0 push {r3, r4, r5, r6, r7, lr} */
/* @0xc34d4 ldr r5, [pc, #0x88] */
/* @0xc34d8 ldr r5, [pc, r5] */
/* @0xc34dc ldr r3, [r5] */
/* @0xc34e0 cmp r3, #0 */
/* @0xc34e4 ble 0xc3554 <_Z15Background_Freev+0x84> */
/* @0xc34e8 ldr r3, [pc, #0x78] */
/* @0xc34ec mov r4, #0 */
/* @0xc34f0 ldr r6, [pc, #0x74] */
/* @0xc34f4 mov r7, r4 */
/* @0xc34f8 add r3, pc, r3 */
/* @0xc34fc add r6, pc, r6 */
/* @0xc3500 ldr r2, [r3, #0x4] */
/* @0xc3504 ldr r0, [r2, r4, lsl #2] */
/* @0xc3508 cmp r0, #0 */
/* @0xc350c beq 0xc3520 <_Z15Background_Freev+0x50> */
/* @0xc3510 bl 0xc2d5c <_ZN11CBackground4FreeEv> */
/* @0xc3514 ldr r3, [r6, #0x4] */
/* @0xc3518 str r7, [r3, r4, lsl #2] */
/* @0xc351c ldr r2, [r6, #0x4] */
/* @0xc3520 ldr r3, [r5] */
/* @0xc3524 add r4, r4, #1 */
/* @0xc3528 cmp r3, r4 */
/* @0xc352c bgt 0xc3504 <_Z15Background_Freev+0x34> */
/* @0xc3530 mov r0, r2 */
/* @0xc3534 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc3538 ldr r2, [pc, #0x30] */
/* @0xc353c mov r3, #0 */
/* @0xc3540 str r3, [r5] */
/* @0xc3544 add r2, pc, r2 */
/* @0xc3548 str r3, [r2, #0x4] */
/* @0xc354c str r3, [r2] */
/* @0xc3550 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc3554 ldr r3, [pc, #0x18] */
/* @0xc3558 add r3, pc, r3 */
/* @0xc355c ldr r2, [r3, #0x4] */
/* @0xc3560 b 0xc3530 <_Z15Background_Freev+0x60> */
/* @0xc3564 eorseq r10, r2, r0, ror r4 */
/* @0xc3568 ldrhteq r6, [r11], -r0 */
/* @0xc356c eorseq r6, r11, r12, lsr #15 */
/* @0xc3570 eorseq r6, r11, r4, ror #14 */
/* @0xc3574 eorseq r6, r11, r0, asr r7 */

/* ── FUNC 0xc3578 · Background_InitTextures() · size=96 · insn=24 */
/* @0xc3578 push {r4, r5, r6, lr} */
/* @0xc357c ldr r6, [pc, #0x4c] */
/* @0xc3580 ldr r6, [pc, r6] */
/* @0xc3584 ldr r3, [r6] */
/* @0xc3588 cmp r3, #0 */
/* @0xc358c pople {r4, r5, r6, pc} */
/* @0xc3590 ldr r5, [pc, #0x3c] */
/* @0xc3594 mov r4, #0 */
/* @0xc3598 add r5, pc, r5 */
/* @0xc359c ldr r3, [r5, #0x4] */
/* @0xc35a0 ldr r0, [r3, r4, lsl #2] */
/* @0xc35a4 cmp r0, #0 */
/* @0xc35a8 beq 0xc35bc <_Z23Background_InitTexturesv+0x44> */
/* @0xc35ac bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc35b0 ldr r3, [r5, #0x4] */
/* @0xc35b4 ldr r0, [r3, r4, lsl #2] */
/* @0xc35b8 bl 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */
/* @0xc35bc ldr r3, [r6] */
/* @0xc35c0 add r4, r4, #1 */
/* @0xc35c4 cmp r3, r4 */
/* @0xc35c8 bgt 0xc359c <_Z23Background_InitTexturesv+0x24> */
/* @0xc35cc pop {r4, r5, r6, pc} */
/* @0xc35d0 eorseq r10, r2, r8, asr #7 */
/* @0xc35d4 eorseq r6, r11, r0, lsl r7 */

/* ── FUNC 0xc35d8 · Background_FreeTextures() · size=84 · insn=21 */
/* @0xc35d8 push {r4, r5, r6, lr} */
/* @0xc35dc ldr r5, [pc, #0x40] */
/* @0xc35e0 ldr r5, [pc, r5] */
/* @0xc35e4 ldr r3, [r5] */
/* @0xc35e8 cmp r3, #0 */
/* @0xc35ec pople {r4, r5, r6, pc} */
/* @0xc35f0 ldr r6, [pc, #0x30] */
/* @0xc35f4 mov r4, #0 */
/* @0xc35f8 add r6, pc, r6 */
/* @0xc35fc ldr r3, [r6, #0x4] */
/* @0xc3600 ldr r0, [r3, r4, lsl #2] */
/* @0xc3604 add r4, r4, #1 */
/* @0xc3608 cmp r0, #0 */
/* @0xc360c beq 0xc3614 <_Z23Background_FreeTexturesv+0x3c> */
/* @0xc3610 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv> */
/* @0xc3614 ldr r3, [r5] */
/* @0xc3618 cmp r3, r4 */
/* @0xc361c bgt 0xc35fc <_Z23Background_FreeTexturesv+0x24> */
/* @0xc3620 pop {r4, r5, r6, pc} */
/* @0xc3624 eorseq r10, r2, r8, ror #6 */
/* @0xc3628 ldrhteq r6, [r11], -r0 */

/* ── FUNC 0xc362c · Background_Number() · size=20 · insn=5 */
/* @0xc362c ldr r3, [pc, #0x8] */
/* @0xc3630 ldr r3, [pc, r3] */
/* @0xc3634 ldr r0, [r3] */
/* @0xc3638 bx lr */
/* @0xc363c eorseq r10, r2, r8, lsl r3 */

/* ── FUNC 0xc3640 · Background_Exists(int) · size=72 · insn=18 */
/* @0xc3640 cmp r0, #0 */
/* @0xc3644 blt 0xc3678 <_Z17Background_Existsi+0x38> */
/* @0xc3648 ldr r3, [pc, #0x30] */
/* @0xc364c ldr r3, [pc, r3] */
/* @0xc3650 ldr r3, [r3] */
/* @0xc3654 cmp r0, r3 */
/* @0xc3658 bge 0xc3678 <_Z17Background_Existsi+0x38> */
/* @0xc365c ldr r3, [pc, #0x20] */
/* @0xc3660 add r3, pc, r3 */
/* @0xc3664 ldr r3, [r3, #0x4] */
/* @0xc3668 ldr r0, [r3, r0, lsl #2] */
/* @0xc366c adds r0, r0, #0 */
/* @0xc3670 movne r0, #1 */
/* @0xc3674 bx lr */
/* @0xc3678 mov r0, #0 */
/* @0xc367c bx lr */
/* @0xc3680 ldrshteq r10, [r2], -r12 */
/* @0xc3684 eorseq r6, r11, r8, asr #12 */

/* ── FUNC 0xc3688 · Background_Name(int) · size=132 · insn=33 */
/* @0xc3688 cmp r0, #0 */
/* @0xc368c blt 0xc36dc <_Z15Background_Namei+0x54> */
/* @0xc3690 ldr r3, [pc, #0x5c] */
/* @0xc3694 ldr r3, [pc, r3] */
/* @0xc3698 ldr r3, [r3] */
/* @0xc369c cmp r0, r3 */
/* @0xc36a0 bge 0xc36d0 <_Z15Background_Namei+0x48> */
/* @0xc36a4 ldr r3, [pc, #0x4c] */
/* @0xc36a8 add r3, pc, r3 */
/* @0xc36ac ldr r3, [r3, #0x4] */
/* @0xc36b0 ldr r3, [r3, r0, lsl #2] */
/* @0xc36b4 cmp r3, #0 */
/* @0xc36b8 beq 0xc36e8 <_Z15Background_Namei+0x60> */
/* @0xc36bc ldr r3, [pc, #0x38] */
/* @0xc36c0 ldr r3, [pc, r3] */
/* @0xc36c4 ldr r3, [r3] */
/* @0xc36c8 ldr r0, [r3, r0, lsl #2] */
/* @0xc36cc bx lr */
/* @0xc36d0 ldr r0, [pc, #0x28] */
/* @0xc36d4 add r0, pc, r0 */
/* @0xc36d8 bx lr */
/* @0xc36dc ldr r0, [pc, #0x20] */
/* @0xc36e0 add r0, pc, r0 */
/* @0xc36e4 bx lr */
/* @0xc36e8 ldr r0, [pc, #0x18] */
/* @0xc36ec add r0, pc, r0 */
/* @0xc36f0 bx lr */
/* @0xc36f4 ldrhteq r10, [r2], -r4 */
/* @0xc36f8 eorseq r6, r11, r0, lsl #12 */
/* @0xc36fc eorseq r10, r2, r12, lsl #5 */
/* @0xc3700 eoreq sp, r6, r12, ror #7 */
/* @0xc3704 eoreq sp, r6, r0, ror #7 */
/* @0xc3708 .word 0x0026d3d4 */

/* ── FUNC 0xc370c · Background_Find(char const*) · size=136 · insn=34 */
/* @0xc370c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xc3710 mov r7, r0 */
/* @0xc3714 ldr r3, [pc, #0x6c] */
/* @0xc3718 ldr r3, [pc, r3] */
/* @0xc371c ldr r6, [r3] */
/* @0xc3720 cmp r6, #0 */
/* @0xc3724 ble 0xc3778 <_Z15Background_FindPKc+0x6c> */
/* @0xc3728 ldr r3, [pc, #0x5c] */
/* @0xc372c mov r4, #0 */
/* @0xc3730 ldr r2, [pc, #0x58] */
/* @0xc3734 mov r5, r4 */
/* @0xc3738 ldr r3, [pc, r3] */
/* @0xc373c add r2, pc, r2 */
/* @0xc3740 ldr r9, [r3] */
/* @0xc3744 ldr r8, [r2, #0x4] */
/* @0xc3748 ldr r3, [r8, r4] */
/* @0xc374c mov r1, r7 */
/* @0xc3750 cmp r3, #0 */
/* @0xc3754 beq 0xc3768 <_Z15Background_FindPKc+0x5c> */
/* @0xc3758 ldr r0, [r9, r4] */
/* @0xc375c bl 0xb6574 <strcmp@plt> */
/* @0xc3760 cmp r0, #0 */
/* @0xc3764 beq 0xc3780 <_Z15Background_FindPKc+0x74> */
/* @0xc3768 add r5, r5, #1 */
/* @0xc376c add r4, r4, #4 */
/* @0xc3770 cmp r5, r6 */
/* @0xc3774 bne 0xc3748 <_Z15Background_FindPKc+0x3c> */
/* @0xc3778 mvn r0, #0 */
/* @0xc377c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc3780 mov r0, r5 */
/* @0xc3784 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xc3788 eorseq r10, r2, r0, lsr r2 */
/* @0xc378c eorseq r10, r2, r4, lsl r2 */
/* @0xc3790 eorseq r6, r11, r12, ror #10 */

/* ── FUNC 0xc3794 · Background_Data(int) · size=64 · insn=16 */
/* @0xc3794 cmp r0, #0 */
/* @0xc3798 blt 0xc37c4 <_Z15Background_Datai+0x30> */
/* @0xc379c ldr r3, [pc, #0x28] */
/* @0xc37a0 ldr r3, [pc, r3] */
/* @0xc37a4 ldr r3, [r3] */
/* @0xc37a8 cmp r0, r3 */
/* @0xc37ac bge 0xc37c4 <_Z15Background_Datai+0x30> */
/* @0xc37b0 ldr r3, [pc, #0x18] */
/* @0xc37b4 add r3, pc, r3 */
/* @0xc37b8 ldr r3, [r3, #0x4] */
/* @0xc37bc ldr r0, [r3, r0, lsl #2] */
/* @0xc37c0 bx lr */
/* @0xc37c4 mov r0, #0 */
/* @0xc37c8 bx lr */
/* @0xc37cc eorseq r10, r2, r8, lsr #3 */
/* @0xc37d0 ldrshteq r6, [r11], -r4 */

/* ── FUNC 0xc37d4 · Background_CreateNew() · size=256 · insn=64 */
/* @0xc37d4 push {r4, r5, r6, r7, r8, lr} */
/* @0xc37d8 sub sp, sp, #264 */
/* @0xc37dc ldr r4, [pc, #0xd8] */
/* @0xc37e0 movw r3, #0x16f */
/* @0xc37e4 ldr r5, [pc, #0xd4] */
/* @0xc37e8 ldr r4, [pc, r4] */
/* @0xc37ec ldr r8, [pc, #0xd0] */
/* @0xc37f0 ldr r5, [pc, r5] */
/* @0xc37f4 ldr r7, [pc, #0xcc] */
/* @0xc37f8 ldr r12, [r4] */
/* @0xc37fc add r8, pc, r8 */
/* @0xc3800 ldr lr, [r5] */
/* @0xc3804 add r7, pc, r7 */
/* @0xc3808 add r12, r12, #1 */
/* @0xc380c mov r2, r8 */
/* @0xc3810 add r0, r7, #4 */
/* @0xc3814 ldr r6, [pc, #0xb0] */
/* @0xc3818 lsl r1, r12, #2 */
/* @0xc381c str lr, [sp, #0x104] */
/* @0xc3820 str r12, [r4] */
/* @0xc3824 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc3828 ldr r12, [r4] */
/* @0xc382c ldr r6, [pc, r6] */
/* @0xc3830 mov r2, r8 */
/* @0xc3834 movw r3, #0x171 */
/* @0xc3838 mov r0, r6 */
/* @0xc383c add r8, sp, #4 */
/* @0xc3840 lsl r1, r12, #2 */
/* @0xc3844 str r12, [r7] */
/* @0xc3848 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc384c ldr r3, [r4] */
/* @0xc3850 ldr r2, [pc, #0x78] */
/* @0xc3854 mov r1, #256 */
/* @0xc3858 mov r0, r8 */
/* @0xc385c sub r3, r3, #1 */
/* @0xc3860 add r2, pc, r2 */
/* @0xc3864 bl 0xb65c8 <snprintf@plt> */
/* @0xc3868 ldr r3, [r4] */
/* @0xc386c mov r0, r8 */
/* @0xc3870 ldr r6, [r6] */
/* @0xc3874 sub r8, r3, #-1073741823 */
/* @0xc3878 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc387c str r0, [r6, r8, lsl #2] */
/* @0xc3880 mov r0, #72 */
/* @0xc3884 bl 0x27c524 <_Znwj> */
/* @0xc3888 mov r6, r0 */
/* @0xc388c bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc3890 ldr r1, [r4] */
/* @0xc3894 ldr r3, [r7, #0x4] */
/* @0xc3898 sub r1, r1, #-1073741823 */
/* @0xc389c ldr r2, [sp, #0x104] */
/* @0xc38a0 str r6, [r3, r1, lsl #2] */
/* @0xc38a4 ldr r3, [r5] */
/* @0xc38a8 cmp r2, r3 */
/* @0xc38ac bne 0xc38b8 <_Z20Background_CreateNewv+0xe4> */
/* @0xc38b0 add sp, sp, #264 */
/* @0xc38b4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc38b8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc38bc eorseq r10, r2, r0, ror #2 */
/* @0xc38c0 eorseq r10, r2, r0, ror #2 */
/* @0xc38c4 eoreq sp, r6, r4, lsl #5 */
/* @0xc38c8 eorseq r6, r11, r4, lsr #9 */
/* @0xc38cc eorseq r10, r2, r0, lsr #2 */
/* @0xc38d0 eoreq sp, r6, r12, ror #4 */

/* ── FUNC 0xc38d4 · Background_Add(char const*, bool, bool, bool) · size=464 · insn=116 */
/* @0xc38d4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc38d8 subs r5, r0, #0 */
/* @0xc38dc ldr r4, [pc, #0x19c] */
/* @0xc38e0 mov r9, r3 */
/* @0xc38e4 ldr r0, [pc, #0x198] */
/* @0xc38e8 sub sp, sp, #1040 */
/* @0xc38ec add r4, pc, r4 */
/* @0xc38f0 mov r8, r1 */
/* @0xc38f4 mov r7, r2 */
/* @0xc38f8 ldr r6, [r4, r0] */
/* @0xc38fc ldr r3, [r6] */
/* @0xc3900 str r3, [sp, #0x40c] */
/* @0xc3904 beq 0xc3a5c <_Z14Background_AddPKcbbb+0x188> */
/* @0xc3908 ldr r0, [pc, #0x178] */
/* @0xc390c mov r1, r5 */
/* @0xc3910 mov r2, #7 */
/* @0xc3914 add r0, pc, r0 */
/* @0xc3918 bl 0xb65e0 <strncmp@plt> */
/* @0xc391c cmp r0, #0 */
/* @0xc3920 beq 0xc3940 <_Z14Background_AddPKcbbb+0x6c> */
/* @0xc3924 ldr r0, [pc, #0x160] */
/* @0xc3928 mov r1, r5 */
/* @0xc392c mov r2, #8 */
/* @0xc3930 add r0, pc, r0 */
/* @0xc3934 bl 0xb65e0 <strncmp@plt> */
/* @0xc3938 cmp r0, #0 */
/* @0xc393c bne 0xc39d8 <_Z14Background_AddPKcbbb+0x104> */
/* @0xc3940 bl 0xc37d4 <_Z20Background_CreateNewv> */
/* @0xc3944 mov r0, #8 */
/* @0xc3948 bl 0x27c524 <_Znwj> */
/* @0xc394c ldr r3, [pc, #0x13c] */
/* @0xc3950 cmp r7, #0 */
/* @0xc3954 ldr lr, [pc, #0x138] */
/* @0xc3958 ldr r2, [pc, #0x138] */
/* @0xc395c mov r10, #1 */
/* @0xc3960 movne r7, #2 */
/* @0xc3964 moveq r7, #0 */
/* @0xc3968 orr r8, r7, r8 */
/* @0xc396c ldr r7, [r4, r3] */
/* @0xc3970 cmp r9, #0 */
/* @0xc3974 ldr r3, [pc, #0x120] */
/* @0xc3978 mov r1, #7 */
/* @0xc397c movne r9, #4 */
/* @0xc3980 moveq r9, #0 */
/* @0xc3984 orr r8, r8, r9 */
/* @0xc3988 mov r12, r0 */
/* @0xc398c str r8, [r0, #0x4] */
/* @0xc3990 mov r0, r5 */
/* @0xc3994 ldr r5, [r7] */
/* @0xc3998 sub r5, r5, #1 */
/* @0xc399c str r5, [r12] */
/* @0xc39a0 ldr lr, [r4, lr] */
/* @0xc39a4 strb r10, [lr] */
/* @0xc39a8 ldr r2, [r4, r2] */
/* @0xc39ac ldr r3, [r4, r3] */
/* @0xc39b0 str r12, [sp] */
/* @0xc39b4 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0xc39b8 ldr r0, [r7] */
/* @0xc39bc sub r0, r0, #1 */
/* @0xc39c0 ldr r2, [sp, #0x40c] */
/* @0xc39c4 ldr r3, [r6] */
/* @0xc39c8 cmp r2, r3 */
/* @0xc39cc bne 0xc3a7c <_Z14Background_AddPKcbbb+0x1a8> */
/* @0xc39d0 add sp, sp, #1040 */
/* @0xc39d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc39d8 mov r0, r5 */
/* @0xc39dc bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc39e0 cmp r0, #0 */
/* @0xc39e4 bne 0xc3a64 <_Z14Background_AddPKcbbb+0x190> */
/* @0xc39e8 mov r0, r5 */
/* @0xc39ec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xc39f0 cmp r0, #0 */
/* @0xc39f4 beq 0xc3a5c <_Z14Background_AddPKcbbb+0x188> */
/* @0xc39f8 mov r2, r5 */
/* @0xc39fc add r5, sp, #12 */
/* @0xc3a00 mov r1, #1024 */
/* @0xc3a04 mov r0, r5 */
/* @0xc3a08 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0xc3a0c bl 0xc37d4 <_Z20Background_CreateNewv> */
/* @0xc3a10 ldr r2, [pc, #0x78] */
/* @0xc3a14 mov r3, r7 */
/* @0xc3a18 ldr r0, [pc, #0x80] */
/* @0xc3a1c eor r12, r8, #1 */
/* @0xc3a20 mov r1, r5 */
/* @0xc3a24 ldr r7, [r4, r2] */
/* @0xc3a28 add r0, pc, r0 */
/* @0xc3a2c mov r2, r8 */
/* @0xc3a30 ldr r0, [r0, #0x4] */
/* @0xc3a34 ldr lr, [r7] */
/* @0xc3a38 sub lr, lr, #-1073741823 */
/* @0xc3a3c ldr r0, [r0, lr, lsl #2] */
/* @0xc3a40 stm sp, {r9, r12} */
/* @0xc3a44 bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb> */
/* @0xc3a48 cmp r0, #0 */
/* @0xc3a4c bne 0xc39b8 <_Z14Background_AddPKcbbb+0xe4> */
/* @0xc3a50 ldr r3, [r7] */
/* @0xc3a54 sub r3, r3, #1 */
/* @0xc3a58 str r3, [r7] */
/* @0xc3a5c mvn r0, #0 */
/* @0xc3a60 b 0xc39c0 <_Z14Background_AddPKcbbb+0xec> */
/* @0xc3a64 mov r2, r5 */
/* @0xc3a68 add r5, sp, #12 */
/* @0xc3a6c mov r1, #1024 */
/* @0xc3a70 mov r0, r5 */
/* @0xc3a74 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0xc3a78 b 0xc3a0c <_Z14Background_AddPKcbbb+0x138> */
/* @0xc3a7c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc3a80 eorseq lr, r2, r4, ror #6 */
/* @0xc3a84 .word 0xffffbd00 */
/* @0xc3a88 eoreq sp, r6, r12, asr #3 */
/* @0xc3a8c .word 0x0026d1b8 */
/* @0xc3a90 .word 0xffffbcf8 */
/* @0xc3a94 .word 0xffffbd04 */
/* @0xc3a98 .word 0xffffbd08 */
/* @0xc3a9c .word 0xffffbd0c */
/* @0xc3aa0 eorseq r6, r11, r0, lsl #5 */

/* ── FUNC 0xc3aa4 · Background_Replace(int, char const*, bool, bool, bool) · size=552 · insn=138 */
/* @0xc3aa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc3aa8 subs r6, r0, #0 */
/* @0xc3aac ldr r4, [pc, #0x1f0] */
/* @0xc3ab0 sub sp, sp, #1040 */
/* @0xc3ab4 ldr r0, [pc, #0x1ec] */
/* @0xc3ab8 mov r9, r3 */
/* @0xc3abc add r4, pc, r4 */
/* @0xc3ac0 sub sp, sp, #12 */
/* @0xc3ac4 mov r8, r2 */
/* @0xc3ac8 mov r7, r1 */
/* @0xc3acc ldr r5, [r4, r0] */
/* @0xc3ad0 ldrb r10, [sp, #0x440] */
/* @0xc3ad4 ldr r3, [r5] */
/* @0xc3ad8 str r3, [sp, #0x414] */
/* @0xc3adc blt 0xc3bb0 <_Z18Background_ReplaceiPKcbbb+0x10c> */
/* @0xc3ae0 ldr r3, [pc, #0x1c4] */
/* @0xc3ae4 ldr r3, [r4, r3] */
/* @0xc3ae8 ldr r3, [r3] */
/* @0xc3aec cmp r6, r3 */
/* @0xc3af0 bge 0xc3bb0 <_Z18Background_ReplaceiPKcbbb+0x10c> */
/* @0xc3af4 cmp r1, #0 */
/* @0xc3af8 beq 0xc3c3c <_Z18Background_ReplaceiPKcbbb+0x198> */
/* @0xc3afc ldr r0, [pc, #0x1ac] */
/* @0xc3b00 mov r2, #7 */
/* @0xc3b04 add r0, pc, r0 */
/* @0xc3b08 bl 0xb65e0 <strncmp@plt> */
/* @0xc3b0c cmp r0, #0 */
/* @0xc3b10 beq 0xc3b30 <_Z18Background_ReplaceiPKcbbb+0x8c> */
/* @0xc3b14 ldr r0, [pc, #0x198] */
/* @0xc3b18 mov r1, r7 */
/* @0xc3b1c mov r2, #8 */
/* @0xc3b20 add r0, pc, r0 */
/* @0xc3b24 bl 0xb65e0 <strncmp@plt> */
/* @0xc3b28 cmp r0, #0 */
/* @0xc3b2c bne 0xc3bd0 <_Z18Background_ReplaceiPKcbbb+0x12c> */
/* @0xc3b30 ldr r11, [pc, #0x180] */
/* @0xc3b34 add r11, pc, r11 */
/* @0xc3b38 ldr r3, [r11, #0x4] */
/* @0xc3b3c ldr r3, [r3, r6, lsl #2] */
/* @0xc3b40 cmp r3, #0 */
/* @0xc3b44 beq 0xc3c5c <_Z18Background_ReplaceiPKcbbb+0x1b8> */
/* @0xc3b48 mov r0, #8 */
/* @0xc3b4c bl 0x27c524 <_Znwj> */
/* @0xc3b50 cmp r9, #0 */
/* @0xc3b54 ldr r3, [pc, #0x160] */
/* @0xc3b58 mov r1, #7 */
/* @0xc3b5c movne r9, #2 */
/* @0xc3b60 moveq r9, #0 */
/* @0xc3b64 cmp r10, #0 */
/* @0xc3b68 orr r8, r9, r8 */
/* @0xc3b6c ldr r2, [pc, #0x14c] */
/* @0xc3b70 movne r10, #4 */
/* @0xc3b74 moveq r10, #0 */
/* @0xc3b78 orr r8, r8, r10 */
/* @0xc3b7c stm r0, {r6, r8} */
/* @0xc3b80 mov r12, r0 */
/* @0xc3b84 ldr lr, [r4, r3] */
/* @0xc3b88 mov r0, r7 */
/* @0xc3b8c ldr r3, [pc, #0x130] */
/* @0xc3b90 mov r6, #1 */
/* @0xc3b94 strb r6, [lr] */
/* @0xc3b98 ldr r2, [r4, r2] */
/* @0xc3b9c ldr r3, [r4, r3] */
/* @0xc3ba0 str r12, [sp] */
/* @0xc3ba4 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0xc3ba8 mov r0, #0 */
/* @0xc3bac b 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110> */
/* @0xc3bb0 mov r0, #0 */
/* @0xc3bb4 ldr r2, [sp, #0x414] */
/* @0xc3bb8 ldr r3, [r5] */
/* @0xc3bbc cmp r2, r3 */
/* @0xc3bc0 bne 0xc3ca0 <_Z18Background_ReplaceiPKcbbb+0x1fc> */
/* @0xc3bc4 add sp, sp, #1040 */
/* @0xc3bc8 add sp, sp, #12 */
/* @0xc3bcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc3bd0 mov r0, r7 */
/* @0xc3bd4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc3bd8 cmp r0, #0 */
/* @0xc3bdc bne 0xc3c44 <_Z18Background_ReplaceiPKcbbb+0x1a0> */
/* @0xc3be0 mov r0, r7 */
/* @0xc3be4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xc3be8 cmp r0, #0 */
/* @0xc3bec beq 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110> */
/* @0xc3bf0 add r4, sp, #20 */
/* @0xc3bf4 mov r2, r7 */
/* @0xc3bf8 mov r1, #1024 */
/* @0xc3bfc mov r0, r4 */
/* @0xc3c00 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0xc3c04 ldr r7, [pc, #0xbc] */
/* @0xc3c08 add r7, pc, r7 */
/* @0xc3c0c ldr r3, [r7, #0x4] */
/* @0xc3c10 ldr r0, [r3, r6, lsl #2] */
/* @0xc3c14 cmp r0, #0 */
/* @0xc3c18 beq 0xc3c7c <_Z18Background_ReplaceiPKcbbb+0x1d8> */
/* @0xc3c1c eor r12, r8, #1 */
/* @0xc3c20 str r10, [sp] */
/* @0xc3c24 mov r1, r4 */
/* @0xc3c28 mov r3, r9 */
/* @0xc3c2c mov r2, r8 */
/* @0xc3c30 str r12, [sp, #0x4] */
/* @0xc3c34 bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb> */
/* @0xc3c38 b 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110> */
/* @0xc3c3c mov r0, r1 */
/* @0xc3c40 b 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110> */
/* @0xc3c44 add r4, sp, #20 */
/* @0xc3c48 mov r2, r7 */
/* @0xc3c4c mov r1, #1024 */
/* @0xc3c50 mov r0, r4 */
/* @0xc3c54 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0xc3c58 b 0xc3c04 <_Z18Background_ReplaceiPKcbbb+0x160> */
/* @0xc3c5c mov r0, #72 */
/* @0xc3c60 bl 0x27c524 <_Znwj> */
/* @0xc3c64 str r0, [sp, #0xc] */
/* @0xc3c68 bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc3c6c ldr r2, [r11, #0x4] */
/* @0xc3c70 ldr r3, [sp, #0xc] */
/* @0xc3c74 str r3, [r2, r6, lsl #2] */
/* @0xc3c78 b 0xc3b48 <_Z18Background_ReplaceiPKcbbb+0xa4> */
/* @0xc3c7c mov r0, #72 */
/* @0xc3c80 bl 0x27c524 <_Znwj> */
/* @0xc3c84 mov r11, r0 */
/* @0xc3c88 bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc3c8c ldr r3, [r7, #0x4] */
/* @0xc3c90 str r11, [r3, r6, lsl #2] */
/* @0xc3c94 ldr r3, [r7, #0x4] */
/* @0xc3c98 ldr r0, [r3, r6, lsl #2] */
/* @0xc3c9c b 0xc3c1c <_Z18Background_ReplaceiPKcbbb+0x178> */
/* @0xc3ca0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc3ca4 mlaseq r2, r4, r1, lr */
/* @0xc3ca8 .word 0xffffbd00 */
/* @0xc3cac .word 0xffffbcf8 */
/* @0xc3cb0 .word 0x0026cfdc */
/* @0xc3cb4 eoreq r12, r6, r8, asr #31 */
/* @0xc3cb8 eorseq r6, r11, r4, ror r1 */
/* @0xc3cbc .word 0xffffbd04 */
/* @0xc3cc0 .word 0xffffbd08 */
/* @0xc3cc4 .word 0xffffbd0c */
/* @0xc3cc8 eorseq r6, r11, r0, lsr #1 */

/* ── FUNC 0xc3ccc · Background_Add_Alpha(char const*, bool) · size=404 · insn=101 */
/* @0xc3ccc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc3cd0 sub sp, sp, #1296 */
/* @0xc3cd4 ldr r5, [pc, #0x16c] */
/* @0xc3cd8 mov r10, r1 */
/* @0xc3cdc mov r4, r0 */
/* @0xc3ce0 ldr r5, [pc, r5] */
/* @0xc3ce4 ldr r3, [r5] */
/* @0xc3ce8 str r3, [sp, #0x50c] */
/* @0xc3cec bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc3cf0 cmp r0, #0 */
/* @0xc3cf4 beq 0xc3e14 <_Z20Background_Add_AlphaPKcb+0x148> */
/* @0xc3cf8 add r8, sp, #268 */
/* @0xc3cfc mov r2, r4 */
/* @0xc3d00 mov r1, #1024 */
/* @0xc3d04 mov r0, r8 */
/* @0xc3d08 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0xc3d0c ldr r4, [pc, #0x138] */
/* @0xc3d10 movw r3, #0x213 */
/* @0xc3d14 ldr r9, [pc, #0x134] */
/* @0xc3d18 ldr r4, [pc, r4] */
/* @0xc3d1c ldr r6, [pc, #0x130] */
/* @0xc3d20 add r9, pc, r9 */
/* @0xc3d24 ldr r7, [pc, #0x12c] */
/* @0xc3d28 ldr r1, [r4] */
/* @0xc3d2c add r6, pc, r6 */
/* @0xc3d30 mov r2, r9 */
/* @0xc3d34 add r0, r6, #4 */
/* @0xc3d38 add r1, r1, #1 */
/* @0xc3d3c str r1, [r4] */
/* @0xc3d40 lsl r1, r1, #2 */
/* @0xc3d44 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc3d48 ldr r12, [r4] */
/* @0xc3d4c ldr r7, [pc, r7] */
/* @0xc3d50 mov r2, r9 */
/* @0xc3d54 movw r3, #0x215 */
/* @0xc3d58 add r9, sp, #12 */
/* @0xc3d5c lsl r1, r12, #2 */
/* @0xc3d60 mov r0, r7 */
/* @0xc3d64 str r12, [r6] */
/* @0xc3d68 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc3d6c ldr r3, [r4] */
/* @0xc3d70 mov r1, #256 */
/* @0xc3d74 ldr r2, [pc, #0xe0] */
/* @0xc3d78 mov r0, r9 */
/* @0xc3d7c sub r3, r3, #1 */
/* @0xc3d80 add r2, pc, r2 */
/* @0xc3d84 bl 0xb65c8 <snprintf@plt> */
/* @0xc3d88 ldr r3, [r4] */
/* @0xc3d8c mov r0, r9 */
/* @0xc3d90 ldr r7, [r7] */
/* @0xc3d94 sub r9, r3, #-1073741823 */
/* @0xc3d98 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc3d9c str r0, [r7, r9, lsl #2] */
/* @0xc3da0 mov r0, #72 */
/* @0xc3da4 bl 0x27c524 <_Znwj> */
/* @0xc3da8 mov r7, r0 */
/* @0xc3dac bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc3db0 ldr lr, [r4] */
/* @0xc3db4 mov r12, #1 */
/* @0xc3db8 ldr r0, [r6, #0x4] */
/* @0xc3dbc mov r3, #0 */
/* @0xc3dc0 sub lr, lr, #-1073741823 */
/* @0xc3dc4 mov r1, r8 */
/* @0xc3dc8 mov r2, r12 */
/* @0xc3dcc str r7, [r0, lr, lsl #2] */
/* @0xc3dd0 ldr r0, [r6, #0x4] */
/* @0xc3dd4 ldr r0, [r0, lr, lsl #2] */
/* @0xc3dd8 stm sp, {r10, r12} */
/* @0xc3ddc bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb> */
/* @0xc3de0 cmp r0, #0 */
/* @0xc3de4 ldrne r0, [r4] */
/* @0xc3de8 mvneq r0, #0 */
/* @0xc3dec ldreq r3, [r4] */
/* @0xc3df0 subne r0, r0, #1 */
/* @0xc3df4 addeq r3, r3, r0 */
/* @0xc3df8 streq r3, [r4] */
/* @0xc3dfc ldr r2, [sp, #0x50c] */
/* @0xc3e00 ldr r3, [r5] */
/* @0xc3e04 cmp r2, r3 */
/* @0xc3e08 bne 0xc3e44 <_Z20Background_Add_AlphaPKcb+0x178> */
/* @0xc3e0c add sp, sp, #1296 */
/* @0xc3e10 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc3e14 mov r0, r4 */
/* @0xc3e18 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xc3e1c cmp r0, #0 */
/* @0xc3e20 beq 0xc3e3c <_Z20Background_Add_AlphaPKcb+0x170> */
/* @0xc3e24 add r8, sp, #268 */
/* @0xc3e28 mov r2, r4 */
/* @0xc3e2c mov r1, #1024 */
/* @0xc3e30 mov r0, r8 */
/* @0xc3e34 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0xc3e38 b 0xc3d0c <_Z20Background_Add_AlphaPKcb+0x40> */
/* @0xc3e3c mvn r0, #0 */
/* @0xc3e40 b 0xc3dfc <_Z20Background_Add_AlphaPKcb+0x130> */
/* @0xc3e44 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc3e48 eorseq r9, r2, r0, ror r12 */
/* @0xc3e4c eorseq r9, r2, r0, lsr r12 */
/* @0xc3e50 eoreq r12, r6, r0, ror #26 */
/* @0xc3e54 eorseq r5, r11, r12, ror pc */
/* @0xc3e58 eorseq r9, r2, r0, lsl #24 */
/* @0xc3e5c eoreq r12, r6, r12, asr #26 */

/* ── FUNC 0xc3e60 · Background_Replace_Alpha(int, char const*, bool) · size=276 · insn=69 */
/* @0xc3e60 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc3e64 sub sp, sp, #1040 */
/* @0xc3e68 ldr r4, [pc, #0xf8] */
/* @0xc3e6c sub sp, sp, #4 */
/* @0xc3e70 subs r5, r0, #0 */
/* @0xc3e74 mov r6, r1 */
/* @0xc3e78 ldr r4, [pc, r4] */
/* @0xc3e7c mov r7, r2 */
/* @0xc3e80 ldr r3, [r4] */
/* @0xc3e84 str r3, [sp, #0x40c] */
/* @0xc3e88 blt 0xc3ea0 <_Z24Background_Replace_AlphaiPKcb+0x40> */
/* @0xc3e8c ldr r3, [pc, #0xd8] */
/* @0xc3e90 ldr r3, [pc, r3] */
/* @0xc3e94 ldr r3, [r3] */
/* @0xc3e98 cmp r5, r3 */
/* @0xc3e9c blt 0xc3ec0 <_Z24Background_Replace_AlphaiPKcb+0x60> */
/* @0xc3ea0 mov r0, #0 */
/* @0xc3ea4 ldr r2, [sp, #0x40c] */
/* @0xc3ea8 ldr r3, [r4] */
/* @0xc3eac cmp r2, r3 */
/* @0xc3eb0 bne 0xc3f64 <_Z24Background_Replace_AlphaiPKcb+0x104> */
/* @0xc3eb4 add sp, sp, #1040 */
/* @0xc3eb8 add sp, sp, #4 */
/* @0xc3ebc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xc3ec0 mov r0, r1 */
/* @0xc3ec4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc3ec8 cmp r0, #0 */
/* @0xc3ecc bne 0xc3f28 <_Z24Background_Replace_AlphaiPKcb+0xc8> */
/* @0xc3ed0 mov r0, r6 */
/* @0xc3ed4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xc3ed8 cmp r0, #0 */
/* @0xc3edc beq 0xc3ea0 <_Z24Background_Replace_AlphaiPKcb+0x40> */
/* @0xc3ee0 mov r2, r6 */
/* @0xc3ee4 add r6, sp, #12 */
/* @0xc3ee8 mov r1, #1024 */
/* @0xc3eec mov r0, r6 */
/* @0xc3ef0 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0xc3ef4 ldr r8, [pc, #0x74] */
/* @0xc3ef8 add r8, pc, r8 */
/* @0xc3efc ldr r3, [r8, #0x4] */
/* @0xc3f00 ldr r0, [r3, r5, lsl #2] */
/* @0xc3f04 cmp r0, #0 */
/* @0xc3f08 beq 0xc3f40 <_Z24Background_Replace_AlphaiPKcb+0xe0> */
/* @0xc3f0c mov r2, #1 */
/* @0xc3f10 str r7, [sp] */
/* @0xc3f14 mov r1, r6 */
/* @0xc3f18 str r2, [sp, #0x4] */
/* @0xc3f1c mov r3, #0 */
/* @0xc3f20 bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb> */
/* @0xc3f24 b 0xc3ea4 <_Z24Background_Replace_AlphaiPKcb+0x44> */
/* @0xc3f28 mov r2, r6 */
/* @0xc3f2c add r6, sp, #12 */
/* @0xc3f30 mov r1, #1024 */
/* @0xc3f34 mov r0, r6 */
/* @0xc3f38 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0xc3f3c b 0xc3ef4 <_Z24Background_Replace_AlphaiPKcb+0x94> */
/* @0xc3f40 mov r0, #72 */
/* @0xc3f44 bl 0x27c524 <_Znwj> */
/* @0xc3f48 mov r9, r0 */
/* @0xc3f4c bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc3f50 ldr r3, [r8, #0x4] */
/* @0xc3f54 str r9, [r3, r5, lsl #2] */
/* @0xc3f58 ldr r3, [r8, #0x4] */
/* @0xc3f5c ldr r0, [r3, r5, lsl #2] */
/* @0xc3f60 b 0xc3f0c <_Z24Background_Replace_AlphaiPKcb+0xac> */
/* @0xc3f64 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc3f68 ldrsbteq r9, [r2], -r8 */
/* @0xc3f6c ldrhteq r9, [r2], -r8 */
/* @0xc3f70 ldrhteq r5, [r11], -r0 */

/* ── FUNC 0xc3f74 · Background_Delete(int) · size=128 · insn=32 */
/* @0xc3f74 push {r4, r5, r6, lr} */
/* @0xc3f78 subs r4, r0, #0 */
/* @0xc3f7c blt 0xc3fe0 <_Z17Background_Deletei+0x6c> */
/* @0xc3f80 ldr r3, [pc, #0x60] */
/* @0xc3f84 ldr r3, [pc, r3] */
/* @0xc3f88 ldr r3, [r3] */
/* @0xc3f8c cmp r4, r3 */
/* @0xc3f90 bge 0xc3fe0 <_Z17Background_Deletei+0x6c> */
/* @0xc3f94 ldr r6, [pc, #0x50] */
/* @0xc3f98 add r6, pc, r6 */
/* @0xc3f9c ldr r3, [r6, #0x4] */
/* @0xc3fa0 ldr r0, [r3, r4, lsl #2] */
/* @0xc3fa4 cmp r0, #0 */
/* @0xc3fa8 popeq {r4, r5, r6, pc} */
/* @0xc3fac ldr r5, [pc, #0x3c] */
/* @0xc3fb0 bl 0xc2d5c <_ZN11CBackground4FreeEv> */
/* @0xc3fb4 ldr r3, [r6, #0x4] */
/* @0xc3fb8 mov r6, #0 */
/* @0xc3fbc ldr r5, [pc, r5] */
/* @0xc3fc0 str r6, [r3, r4, lsl #2] */
/* @0xc3fc4 ldr r3, [r5] */
/* @0xc3fc8 ldr r0, [r3, r4, lsl #2] */
/* @0xc3fcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc3fd0 ldr r3, [r5] */
/* @0xc3fd4 mov r0, #1 */
/* @0xc3fd8 str r6, [r3, r4, lsl #2] */
/* @0xc3fdc pop {r4, r5, r6, pc} */
/* @0xc3fe0 mov r0, #0 */
/* @0xc3fe4 pop {r4, r5, r6, pc} */
/* @0xc3fe8 eorseq r9, r2, r4, asr #19 */
/* @0xc3fec eorseq r5, r11, r0, lsl sp */
/* @0xc3ff0 mlaseq r2, r0, r9, r9 */

/* ── FUNC 0xc3ff4 · Background_Duplicate(int) · size=340 · insn=85 */
/* @0xc3ff4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc3ff8 subs r8, r0, #0 */
/* @0xc3ffc ldr r6, [pc, #0x12c] */
/* @0xc4000 sub sp, sp, #268 */
/* @0xc4004 ldr r6, [pc, r6] */
/* @0xc4008 ldr r3, [r6] */
/* @0xc400c str r3, [sp, #0x104] */
/* @0xc4010 blt 0xc4124 <_Z20Background_Duplicatei+0x130> */
/* @0xc4014 ldr r4, [pc, #0x118] */
/* @0xc4018 ldr r4, [pc, r4] */
/* @0xc401c ldr r3, [r4] */
/* @0xc4020 cmp r8, r3 */
/* @0xc4024 bge 0xc4124 <_Z20Background_Duplicatei+0x130> */
/* @0xc4028 ldr r5, [pc, #0x108] */
/* @0xc402c add r5, pc, r5 */
/* @0xc4030 ldr r2, [r5, #0x4] */
/* @0xc4034 ldr r2, [r2, r8, lsl #2] */
/* @0xc4038 cmp r2, #0 */
/* @0xc403c beq 0xc4124 <_Z20Background_Duplicatei+0x130> */
/* @0xc4040 ldr r9, [pc, #0xf4] */
/* @0xc4044 add r12, r3, #1 */
/* @0xc4048 add r0, r5, #4 */
/* @0xc404c movw r3, #0x27b */
/* @0xc4050 add r9, pc, r9 */
/* @0xc4054 lsl r1, r12, #2 */
/* @0xc4058 ldr r7, [pc, #0xe0] */
/* @0xc405c mov r2, r9 */
/* @0xc4060 str r12, [r4] */
/* @0xc4064 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc4068 ldr r12, [r4] */
/* @0xc406c ldr r7, [pc, r7] */
/* @0xc4070 mov r2, r9 */
/* @0xc4074 movw r3, #0x27d */
/* @0xc4078 add r9, sp, #4 */
/* @0xc407c lsl r1, r12, #2 */
/* @0xc4080 mov r0, r7 */
/* @0xc4084 str r12, [r5] */
/* @0xc4088 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc408c ldr r3, [r4] */
/* @0xc4090 mov r1, #256 */
/* @0xc4094 ldr r2, [pc, #0xa8] */
/* @0xc4098 mov r0, r9 */
/* @0xc409c sub r3, r3, #1 */
/* @0xc40a0 add r2, pc, r2 */
/* @0xc40a4 bl 0xb65c8 <snprintf@plt> */
/* @0xc40a8 ldr r3, [r4] */
/* @0xc40ac mov r0, r9 */
/* @0xc40b0 ldr r7, [r7] */
/* @0xc40b4 sub r9, r3, #-1073741823 */
/* @0xc40b8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc40bc str r0, [r7, r9, lsl #2] */
/* @0xc40c0 mov r0, #72 */
/* @0xc40c4 bl 0x27c524 <_Znwj> */
/* @0xc40c8 mov r7, r0 */
/* @0xc40cc bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc40d0 ldr r2, [r4] */
/* @0xc40d4 ldr r3, [r5, #0x4] */
/* @0xc40d8 sub r2, r2, #-1073741823 */
/* @0xc40dc str r7, [r3, r2, lsl #2] */
/* @0xc40e0 ldr r3, [r5, #0x4] */
/* @0xc40e4 ldr r0, [r3, r2, lsl #2] */
/* @0xc40e8 ldr r1, [r3, r8, lsl #2] */
/* @0xc40ec bl 0xc2b80 <_ZN11CBackground6AssignEPS_> */
/* @0xc40f0 ldr r2, [r4] */
/* @0xc40f4 ldr r3, [r5, #0x4] */
/* @0xc40f8 sub r2, r2, #-1073741823 */
/* @0xc40fc ldr r0, [r3, r2, lsl #2] */
/* @0xc4100 bl 0xc2da0 <_ZN11CBackground18GenerateBitmapDataEv> */
/* @0xc4104 ldr r0, [r4] */
/* @0xc4108 sub r0, r0, #1 */
/* @0xc410c ldr r2, [sp, #0x104] */
/* @0xc4110 ldr r3, [r6] */
/* @0xc4114 cmp r2, r3 */
/* @0xc4118 bne 0xc412c <_Z20Background_Duplicatei+0x138> */
/* @0xc411c add sp, sp, #268 */
/* @0xc4120 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xc4124 mvn r0, #0 */
/* @0xc4128 b 0xc410c <_Z20Background_Duplicatei+0x118> */
/* @0xc412c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc4130 eorseq r9, r2, r12, asr #18 */
/* @0xc4134 eorseq r9, r2, r0, lsr r9 */
/* @0xc4138 eorseq r5, r11, r12, ror r12 */
/* @0xc413c eoreq r12, r6, r0, lsr r10 */
/* @0xc4140 eorseq r9, r2, r0, ror #17 */
/* @0xc4144 eoreq r12, r6, r12, lsr #20 */
