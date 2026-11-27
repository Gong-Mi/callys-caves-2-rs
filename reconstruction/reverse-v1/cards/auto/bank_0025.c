/* libyoyo.so 覆盖卡组 0025
 * 函数 0xf7db4..0xf9530，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf7db4 · CFontGM::InitTexture() · size=72 · insn=18 */
/* @0xf7db4 push {r4, lr} */
/* @0xf7db8 mov r4, r0 */
/* @0xf7dbc bl 0xf707c <_ZN7CFontGM11FreeTextureEv> */
/* @0xf7dc0 ldr r3, [r4, #0x20] */
/* @0xf7dc4 cmp r3, #0 */
/* @0xf7dc8 popge {r4, pc} */
/* @0xf7dcc ldr r3, [r4, #0x4] */
/* @0xf7dd0 cmp r3, #0 */
/* @0xf7dd4 popeq {r4, pc} */
/* @0xf7dd8 ldrb r3, [r3] */
/* @0xf7ddc cmp r3, #0 */
/* @0xf7de0 popeq {r4, pc} */
/* @0xf7de4 ldr r0, [r4, #0x24] */
/* @0xf7de8 add r2, r4, #48 */
/* @0xf7dec ldr r1, [r4, #0x28] */
/* @0xf7df0 bl 0x173fdc <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte> */
/* @0xf7df4 str r0, [r4, #0x38] */
/* @0xf7df8 pop {r4, pc} */

/* ── FUNC 0xf7dfc · CFontGM::Assign(CFontGM*) · size=240 · insn=60 */
/* @0xf7dfc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf7e00 mov r5, r1 */
/* @0xf7e04 mov r4, r0 */
/* @0xf7e08 bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf7e0c cmp r5, #0 */
/* @0xf7e10 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf7e14 ldr r0, [r5, #0x4] */
/* @0xf7e18 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf7e1c ldr r2, [r5, #0x40] */
/* @0xf7e20 ldr r3, [r5, #0x20] */
/* @0xf7e24 ldr r11, [r5, #0x8] */
/* @0xf7e28 ldrb r10, [r5, #0xc] */
/* @0xf7e2c cmp r3, #0 */
/* @0xf7e30 ldrb r9, [r5, #0xd] */
/* @0xf7e34 ldr r8, [r5, #0x18] */
/* @0xf7e38 ldr r7, [r5, #0x1c] */
/* @0xf7e3c ldr r6, [r5, #0x10] */
/* @0xf7e40 ldr r12, [r5, #0x14] */
/* @0xf7e44 ldr r1, [r5, #0x2c] */
/* @0xf7e48 str r2, [r4, #0x40] */
/* @0xf7e4c ldr r2, [r5, #0x44] */
/* @0xf7e50 str r11, [r4, #0x8] */
/* @0xf7e54 strb r10, [r4, #0xc] */
/* @0xf7e58 str r2, [r4, #0x44] */
/* @0xf7e5c strb r9, [r4, #0xd] */
/* @0xf7e60 str r8, [r4, #0x18] */
/* @0xf7e64 str r3, [r4, #0x20] */
/* @0xf7e68 str r7, [r4, #0x1c] */
/* @0xf7e6c str r6, [r4, #0x10] */
/* @0xf7e70 str r12, [r4, #0x14] */
/* @0xf7e74 str r1, [r4, #0x2c] */
/* @0xf7e78 str r0, [r4, #0x4] */
/* @0xf7e7c blt 0xf7e8c <_ZN7CFontGM6AssignEPS_+0x90> */
/* @0xf7e80 mov r0, r4 */
/* @0xf7e84 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf7e88 b 0xf7db4 <_ZN7CFontGM11InitTextureEv> */
/* @0xf7e8c ldr r2, [r5, #0x28] */
/* @0xf7e90 movw r3, #0x271 */
/* @0xf7e94 ldr r12, [r5, #0x24] */
/* @0xf7e98 add r0, r4, #52 */
/* @0xf7e9c ldr r1, [r5, #0x30] */
/* @0xf7ea0 str r2, [r4, #0x28] */
/* @0xf7ea4 ldr r2, [pc, #0x3c] */
/* @0xf7ea8 str r12, [r4, #0x24] */
/* @0xf7eac add r2, pc, r2 */
/* @0xf7eb0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xf7eb4 ldr r3, [r4, #0x30] */
/* @0xf7eb8 cmp r3, #0 */
/* @0xf7ebc ble 0xf7e80 <_ZN7CFontGM6AssignEPS_+0x84> */
/* @0xf7ec0 mov r3, #0 */
/* @0xf7ec4 ldr r1, [r5, #0x34] */
/* @0xf7ec8 ldr r2, [r4, #0x34] */
/* @0xf7ecc ldrb r1, [r1, r3] */
/* @0xf7ed0 strb r1, [r2, r3] */
/* @0xf7ed4 add r3, r3, #1 */
/* @0xf7ed8 ldr r2, [r4, #0x30] */
/* @0xf7edc cmp r2, r3 */
/* @0xf7ee0 bgt 0xf7ec4 <_ZN7CFontGM6AssignEPS_+0xc8> */
/* @0xf7ee4 b 0xf7e80 <_ZN7CFontGM6AssignEPS_+0x84> */
/* @0xf7ee8 eoreq pc, r3, r8, asr r11 */

/* ── FUNC 0xf7eec · CFontGM::Draw_String(float, float, unsigned short*, unsigned int, float) · size=1056 · insn=264 */
/* @0xf7eec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf7ef0 vpush {d8} */
/* @0xf7ef4 mov r6, r0 */
/* @0xf7ef8 sub sp, sp, #44 */
/* @0xf7efc mov r0, r3 */
/* @0xf7f00 mov r5, r3 */
/* @0xf7f04 vmov s16, r1 */
/* @0xf7f08 vmov s17, r2 */
/* @0xf7f0c bl 0xf6c78 <_Z8yywcslenPKt> */
/* @0xf7f10 ldr r9, [pc, #0x3e4] */
/* @0xf7f14 add r9, pc, r9 */
/* @0xf7f18 mov r4, r0 */
/* @0xf7f1c ldr r0, [r6, #0x20] */
/* @0xf7f20 cmp r0, #0 */
/* @0xf7f24 blt 0xf7ffc <_ZN7CFontGM11Draw_StringEffPtjf+0x110> */
/* @0xf7f28 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0xf7f2c cmp r0, #0 */
/* @0xf7f30 bne 0xf7f40 <_ZN7CFontGM11Draw_StringEffPtjf+0x54> */
/* @0xf7f34 add sp, sp, #44 */
/* @0xf7f38 vpop {d8} */
/* @0xf7f3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf7f40 ldr r0, [r6, #0x20] */
/* @0xf7f44 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xf7f48 cmp r4, #0 */
/* @0xf7f4c mov r10, r0 */
/* @0xf7f50 ble 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48> */
/* @0xf7f54 lsl r8, r4, #1 */
/* @0xf7f58 mov r11, #0 */
/* @0xf7f5c mov r4, #0 */
/* @0xf7f60 b 0xf7f70 <_ZN7CFontGM11Draw_StringEffPtjf+0x84> */
/* @0xf7f64 add r4, r4, #2 */
/* @0xf7f68 cmp r4, r8 */
/* @0xf7f6c beq 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48> */
/* @0xf7f70 ldrh r7, [r5, r4] */
/* @0xf7f74 cmp r7, #0 */
/* @0xf7f78 beq 0xf7f64 <_ZN7CFontGM11Draw_StringEffPtjf+0x78> */
/* @0xf7f7c mov r0, r6 */
/* @0xf7f80 mov r1, r7 */
/* @0xf7f84 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf7f88 vmov r3, s17 */
/* @0xf7f8c subs r9, r0, #0 */
/* @0xf7f90 mov r0, r10 */
/* @0xf7f94 beq 0xf7f64 <_ZN7CFontGM11Draw_StringEffPtjf+0x78> */
/* @0xf7f98 cmp r7, #32 */
/* @0xf7f9c beq 0xf7fe4 <_ZN7CFontGM11Draw_StringEffPtjf+0xf8> */
/* @0xf7fa0 ldrsh r2, [r9, #12] */
/* @0xf7fa4 vldr s15, [r6, #72] */
/* @0xf7fa8 ldrsh r1, [r9, #6] */
/* @0xf7fac vldr s13, [sp, #92] */
/* @0xf7fb0 ldr r12, [sp, #0x58] */
/* @0xf7fb4 vmov s14, r2 */
/* @0xf7fb8 ldr r2, [r6, #0x4c] */
/* @0xf7fbc vstr s13, [sp, #16] */
/* @0xf7fc0 vmov.f32 s13, s16 */
/* @0xf7fc4 vstr s15, [sp] */
/* @0xf7fc8 str r11, [sp, #0x8] */
/* @0xf7fcc str r2, [sp, #0x4] */
/* @0xf7fd0 str r12, [sp, #0xc] */
/* @0xf7fd4 vcvt.f32.s32 s14, s14 */
/* @0xf7fd8 vmla.f32 s13, s14, s15 */
/* @0xf7fdc vmov r2, s13 */
/* @0xf7fe0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0xf7fe4 ldrsh r9, [r9, #10] */
/* @0xf7fe8 vldr s15, [r6, #72] */
/* @0xf7fec vmov s14, r9 */
/* @0xf7ff0 vcvt.f32.s32 s14, s14 */
/* @0xf7ff4 vmla.f32 s16, s14, s15 */
/* @0xf7ff8 b 0xf7f64 <_ZN7CFontGM11Draw_StringEffPtjf+0x78> */
/* @0xf7ffc ldr r8, [r6, #0x3c] */
/* @0xf8000 cmp r8, #0 */
/* @0xf8004 beq 0xf82dc <_ZN7CFontGM11Draw_StringEffPtjf+0x3f0> */
/* @0xf8008 ldr r3, [pc, #0x2f0] */
/* @0xf800c ldrsh r2, [r8, #20] */
/* @0xf8010 ldr r3, [r9, r3] */
/* @0xf8014 ldr r3, [r3, #0x4] */
/* @0xf8018 ldr r8, [r3, r2, lsl #2] */
/* @0xf801c vldr s15, [pc, #724] */
/* @0xf8020 vldr s14, [sp, #92] */
/* @0xf8024 vmul.f32 s15, s14, s15 */
/* @0xf8028 vcvt.s32.f32 s15, s15 */
/* @0xf802c vmov r10, s15 */
/* @0xf8030 cmp r10, #255 */
/* @0xf8034 movgt r10, #-16777216 */
/* @0xf8038 bgt 0xf8048 <_ZN7CFontGM11Draw_StringEffPtjf+0x15c> */
/* @0xf803c cmp r10, #0 */
/* @0xf8040 lslge r10, r10, #24 */
/* @0xf8044 movlt r10, #0 */
/* @0xf8048 ldr r3, [pc, #0x2b4] */
/* @0xf804c ldr r2, [sp, #0x58] */
/* @0xf8050 ldr r3, [r9, r3] */
/* @0xf8054 orr r10, r10, r2 */
/* @0xf8058 ldrb r3, [r3] */
/* @0xf805c cmp r3, #0 */
/* @0xf8060 beq 0xf8278 <_ZN7CFontGM11Draw_StringEffPtjf+0x38c> */
/* @0xf8064 bic r10, r10, #65536 */
/* @0xf8068 bic r10, r10, #1 */
/* @0xf806c orr r12, r10, #65536 */
/* @0xf8070 str r12, [sp, #0x1c] */
/* @0xf8074 orr r12, r10, #1 */
/* @0xf8078 str r12, [sp, #0x20] */
/* @0xf807c ldr r12, [sp, #0x1c] */
/* @0xf8080 orr r12, r12, #1 */
/* @0xf8084 str r12, [sp, #0x24] */
/* @0xf8088 cmp r4, #0 */
/* @0xf808c ble 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48> */
/* @0xf8090 lsl r11, r4, #1 */
/* @0xf8094 mov r3, r9 */
/* @0xf8098 mov r4, #0 */
/* @0xf809c mov r9, r11 */
/* @0xf80a0 mov r11, r3 */
/* @0xf80a4 b 0xf80b4 <_ZN7CFontGM11Draw_StringEffPtjf+0x1c8> */
/* @0xf80a8 add r4, r4, #2 */
/* @0xf80ac cmp r4, r9 */
/* @0xf80b0 beq 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48> */
/* @0xf80b4 ldrh r1, [r5, r4] */
/* @0xf80b8 cmp r1, #0 */
/* @0xf80bc beq 0xf80a8 <_ZN7CFontGM11Draw_StringEffPtjf+0x1bc> */
/* @0xf80c0 mov r0, r6 */
/* @0xf80c4 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf80c8 cmp r0, #0 */
/* @0xf80cc cmpne r8, #0 */
/* @0xf80d0 mov r7, r0 */
/* @0xf80d4 beq 0xf80a8 <_ZN7CFontGM11Draw_StringEffPtjf+0x1bc> */
/* @0xf80d8 mov r0, #4 */
/* @0xf80dc ldr r1, [r8] */
/* @0xf80e0 mov r2, #24 */
/* @0xf80e4 mov r3, #6 */
/* @0xf80e8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xf80ec cmp r0, #0 */
/* @0xf80f0 beq 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48> */
/* @0xf80f4 ldrsh r2, [r7, #12] */
/* @0xf80f8 vmov.f32 s13, s16 */
/* @0xf80fc vldr s12, [r6, #72] */
/* @0xf8100 ldrsh r3, [r7, #6] */
/* @0xf8104 ldrsh r12, [r7, #8] */
/* @0xf8108 vldr s15, [r6, #80] */
/* @0xf810c vmov s11, r2 */
/* @0xf8110 vldr s8, [r6, #76] */
/* @0xf8114 vadd.f32 s14, s17, s15 */
/* @0xf8118 ldr r2, [r6, #0x3c] */
/* @0xf811c vmov s9, r3 */
/* @0xf8120 ldrsh r1, [r7, #2] */
/* @0xf8124 vmov s10, r12 */
/* @0xf8128 ldr r3, [pc, #0x1d8] */
/* @0xf812c ldrsh r12, [r7, #4] */
/* @0xf8130 cmp r2, #0 */
/* @0xf8134 vcvt.f32.s32 s11, s11 */
/* @0xf8138 vmla.f32 s13, s11, s12 */
/* @0xf813c vmov.f32 s11, s13 */
/* @0xf8140 vadd.f32 s13, s13, s15 */
/* @0xf8144 vcvt.f32.s32 s9, s9 */
/* @0xf8148 vcvt.f32.s32 s10, s10 */
/* @0xf814c vmla.f32 s13, s12, s9 */
/* @0xf8150 vmla.f32 s14, s10, s8 */
/* @0xf8154 vstr s13, [r0, #24] */
/* @0xf8158 vstr s13, [r0, #48] */
/* @0xf815c vstr s13, [r0, #72] */
/* @0xf8160 vmov s8, r12 */
/* @0xf8164 ldr r12, [sp, #0x20] */
/* @0xf8168 vsub.f32 s13, s11, s15 */
/* @0xf816c vstr s14, [r0, #52] */
/* @0xf8170 vstr s14, [r0, #76] */
/* @0xf8174 vstr s14, [r0, #100] */
/* @0xf8178 vsub.f32 s14, s17, s15 */
/* @0xf817c vstr s13, [r0] */
/* @0xf8180 vstr s13, [r0, #96] */
/* @0xf8184 vstr s13, [r0, #120] */
/* @0xf8188 vmov s13, r1 */
/* @0xf818c vstr s14, [r0, #4] */
/* @0xf8190 vstr s14, [r0, #28] */
/* @0xf8194 vstr s14, [r0, #124] */
/* @0xf8198 vcvt.f32.s32 s11, s13 */
/* @0xf819c ldr r3, [r11, r3] */
/* @0xf81a0 str r12, [r0, #0x24] */
/* @0xf81a4 ldr r12, [sp, #0x1c] */
/* @0xf81a8 ldr r3, [r3] */
/* @0xf81ac str r10, [r0, #0xc] */
/* @0xf81b0 str r10, [r0, #0x84] */
/* @0xf81b4 str r3, [r0, #0x80] */
/* @0xf81b8 vcvt.f32.s32 s14, s8 */
/* @0xf81bc str r3, [r0, #0x68] */
/* @0xf81c0 str r3, [r0, #0x50] */
/* @0xf81c4 str r3, [r0, #0x38] */
/* @0xf81c8 str r3, [r0, #0x20] */
/* @0xf81cc str r3, [r0, #0x8] */
/* @0xf81d0 str r12, [r0, #0x3c] */
/* @0xf81d4 str r12, [r0, #0x54] */
/* @0xf81d8 ldr r12, [sp, #0x24] */
/* @0xf81dc str r12, [r0, #0x6c] */
/* @0xf81e0 beq 0xf8288 <_ZN7CFontGM11Draw_StringEffPtjf+0x39c> */
/* @0xf81e4 ldrsh r3, [r2] */
/* @0xf81e8 vldr s8, [r8, #8] */
/* @0xf81ec vmov s13, r3 */
/* @0xf81f0 vcvt.f32.s32 s13, s13 */
/* @0xf81f4 vadd.f32 s13, s13, s11 */
/* @0xf81f8 vsub.f32 s11, s13, s15 */
/* @0xf81fc vmul.f32 s11, s11, s8 */
/* @0xf8200 vstr s11, [r0, #16] */
/* @0xf8204 vstr s11, [r0, #112] */
/* @0xf8208 vstr s11, [r0, #136] */
/* @0xf820c ldrsh r2, [r2, #2] */
/* @0xf8210 vadd.f32 s13, s9, s13 */
/* @0xf8214 vldr s11, [r8, #12] */
/* @0xf8218 vmov s7, r2 */
/* @0xf821c vcvt.f32.s32 s7, s7 */
/* @0xf8220 vadd.f32 s7, s7, s14 */
/* @0xf8224 vadd.f32 s14, s10, s7 */
/* @0xf8228 vadd.f32 s13, s15, s13 */
/* @0xf822c vadd.f32 s14, s15, s14 */
/* @0xf8230 vsub.f32 s15, s7, s15 */
/* @0xf8234 vmul.f32 s13, s8, s13 */
/* @0xf8238 vmul.f32 s14, s11, s14 */
/* @0xf823c vstr s13, [r0, #40] */
/* @0xf8240 vstr s13, [r0, #88] */
/* @0xf8244 vstr s13, [r0, #64] */
/* @0xf8248 vmul.f32 s15, s15, s11 */
/* @0xf824c vstr s14, [r0, #68] */
/* @0xf8250 vstr s14, [r0, #92] */
/* @0xf8254 vstr s14, [r0, #116] */
/* @0xf8258 vstr s15, [r0, #20] */
/* @0xf825c vstr s15, [r0, #44] */
/* @0xf8260 vstr s15, [r0, #140] */
/* @0xf8264 ldrsh r7, [r7, #10] */
/* @0xf8268 vmov s15, r7 */
/* @0xf826c vcvt.f32.s32 s15, s15 */
/* @0xf8270 vmla.f32 s16, s12, s15 */
/* @0xf8274 b 0xf80a8 <_ZN7CFontGM11Draw_StringEffPtjf+0x1bc> */
/* @0xf8278 str r10, [sp, #0x24] */
/* @0xf827c str r10, [sp, #0x1c] */
/* @0xf8280 str r10, [sp, #0x20] */
/* @0xf8284 b 0xf8088 <_ZN7CFontGM11Draw_StringEffPtjf+0x19c> */
/* @0xf8288 vldr s13, [r8, #8] */
/* @0xf828c vmul.f32 s15, s13, s11 */
/* @0xf8290 vadd.f32 s10, s14, s10 */
/* @0xf8294 vstr s15, [r0, #16] */
/* @0xf8298 vstr s15, [r0, #112] */
/* @0xf829c vstr s15, [r0, #136] */
/* @0xf82a0 vldr s15, [r8, #12] */
/* @0xf82a4 vadd.f32 s11, s11, s9 */
/* @0xf82a8 vmul.f32 s14, s15, s14 */
/* @0xf82ac vmul.f32 s13, s13, s11 */
/* @0xf82b0 vstr s14, [r0, #20] */
/* @0xf82b4 vstr s14, [r0, #44] */
/* @0xf82b8 vstr s14, [r0, #140] */
/* @0xf82bc vmul.f32 s15, s15, s10 */
/* @0xf82c0 vstr s13, [r0, #40] */
/* @0xf82c4 vstr s13, [r0, #64] */
/* @0xf82c8 vstr s13, [r0, #88] */
/* @0xf82cc vstr s15, [r0, #68] */
/* @0xf82d0 vstr s15, [r0, #92] */
/* @0xf82d4 vstr s15, [r0, #116] */
/* @0xf82d8 b 0xf8264 <_ZN7CFontGM11Draw_StringEffPtjf+0x378> */
/* @0xf82dc ldr r3, [r6, #0x38] */
/* @0xf82e0 cmp r3, #0 */
/* @0xf82e4 ldrge r2, [pc, #0x14] */
/* @0xf82e8 ldrge r2, [r9, r2] */
/* @0xf82ec ldrge r2, [r2, #0x4] */
/* @0xf82f0 ldrge r8, [r2, r3, lsl #2] */
/* @0xf82f4 b 0xf801c <_ZN7CFontGM11Draw_StringEffPtjf+0x130> */
/* @0xf82f8 cmnmi pc, #0 */
/* @0xf82fc eoreq r9, pc, r12, lsr sp */
/* @0xf8300 .word 0xffffbccc */
/* @0xf8304 .word 0xffffc1fc */
/* @0xf8308 .word 0xffffbcd0 */

/* ── FUNC 0xf830c · CFontGM::Draw_String_Transformed(float, float, unsigned short*, float, float, float, unsigned int, float) · size=2040 · insn=510 */
/* @0xf830c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf8310 vpush {d8, d9, d10, d11, d12} */
/* @0xf8314 sub sp, sp, #44 */
/* @0xf8318 vldr s25, [sp, #136] */
/* @0xf831c mov r6, r0 */
/* @0xf8320 mov r0, r3 */
/* @0xf8324 mov r5, r3 */
/* @0xf8328 vmov s16, r1 */
/* @0xf832c vldr s18, [sp, #120] */
/* @0xf8330 vmov s17, r2 */
/* @0xf8334 vldr s19, [sp, #124] */
/* @0xf8338 vldr s24, [sp, #128] */
/* @0xf833c ldr r11, [sp, #0x84] */
/* @0xf8340 bl 0xf6c78 <_Z8yywcslenPKt> */
/* @0xf8344 vldr s15, [pc, #996] */
/* @0xf8348 vmul.f32 s15, s25, s15 */
/* @0xf834c ldr r8, [pc, #0x3e8] */
/* @0xf8350 add r8, pc, r8 */
/* @0xf8354 vcvt.s32.f32 s15, s15 */
/* @0xf8358 vmov r7, s15 */
/* @0xf835c mov r4, r0 */
/* @0xf8360 cmp r7, #255 */
/* @0xf8364 movgt r7, #-16777216 */
/* @0xf8368 bgt 0xf8378 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x6c> */
/* @0xf836c cmp r7, #0 */
/* @0xf8370 lslge r7, r7, #24 */
/* @0xf8374 movlt r7, #0 */
/* @0xf8378 ldr r3, [pc, #0x3c0] */
/* @0xf837c vabs.f32 s14, s24 */
/* @0xf8380 orr r7, r7, r11 */
/* @0xf8384 vldr s15, [pc, #936] */
/* @0xf8388 ldr r3, [r8, r3] */
/* @0xf838c vcmpe.f32 s14, s15 */
/* @0xf8390 ldrb r3, [r3] */
/* @0xf8394 cmp r3, #0 */
/* @0xf8398 streq r7, [sp, #0x20] */
/* @0xf839c bicne r7, r7, #65536 */
/* @0xf83a0 streq r7, [sp, #0x1c] */
/* @0xf83a4 bicne r7, r7, #1 */
/* @0xf83a8 moveq r9, r7 */
/* @0xf83ac orrne r9, r7, #65536 */
/* @0xf83b0 orrne r12, r7, #1 */
/* @0xf83b4 strne r12, [sp, #0x1c] */
/* @0xf83b8 orrne r12, r9, #1 */
/* @0xf83bc strne r12, [sp, #0x20] */
/* @0xf83c0 vmrs APSR_nzcv, fpscr */
/* @0xf83c4 bpl 0xf83ec <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xe0> */
/* @0xf83c8 ldr r0, [r6, #0x20] */
/* @0xf83cc cmp r0, #0 */
/* @0xf83d0 blt 0xf84dc <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1d0> */
/* @0xf83d4 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0xf83d8 cmp r0, #0 */
/* @0xf83dc bne 0xf8960 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x654> */
/* @0xf83e0 add sp, sp, #44 */
/* @0xf83e4 vpop {d8, d9, d10, d11, d12} */
/* @0xf83e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf83ec vldr s21, [pc, #836] */
/* @0xf83f0 vmul.f32 s21, s24, s21 */
/* @0xf83f4 vmov r0, s21 */
/* @0xf83f8 bl 0xb6580 <sinf@plt> */
/* @0xf83fc vmov s20, r0 */
/* @0xf8400 vmov r0, s21 */
/* @0xf8404 bl 0xb658c <cosf@plt> */
/* @0xf8408 vmul.f32 s22, s20, s18 */
/* @0xf840c vmov s21, r0 */
/* @0xf8410 ldr r0, [r6, #0x20] */
/* @0xf8414 cmp r0, #0 */
/* @0xf8418 vmul.f32 s23, s21, s18 */
/* @0xf841c blt 0xf86f0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x3e4> */
/* @0xf8420 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0xf8424 cmp r0, #0 */
/* @0xf8428 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf842c ldr r0, [r6, #0x20] */
/* @0xf8430 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xf8434 cmp r4, #0 */
/* @0xf8438 mov r9, r0 */
/* @0xf843c ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8440 lsl r4, r4, #1 */
/* @0xf8444 mov r7, #0 */
/* @0xf8448 b 0xf8458 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x14c> */
/* @0xf844c add r7, r7, #2 */
/* @0xf8450 cmp r7, r4 */
/* @0xf8454 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8458 ldrh r8, [r5, r7] */
/* @0xf845c cmp r8, #0 */
/* @0xf8460 beq 0xf844c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x140> */
/* @0xf8464 mov r0, r6 */
/* @0xf8468 mov r1, r8 */
/* @0xf846c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf8470 subs r10, r0, #0 */
/* @0xf8474 mov r0, r9 */
/* @0xf8478 beq 0xf844c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x140> */
/* @0xf847c cmp r8, #32 */
/* @0xf8480 beq 0xf84c4 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1b8> */
/* @0xf8484 ldrsh r12, [r10, #12] */
/* @0xf8488 vmov.f32 s8, s16 */
/* @0xf848c ldrsh r1, [r10, #6] */
/* @0xf8490 vstr s18, [sp] */
/* @0xf8494 vstr s19, [sp, #4] */
/* @0xf8498 vstr s24, [sp, #8] */
/* @0xf849c vmov s15, r12 */
/* @0xf84a0 str r11, [sp, #0xc] */
/* @0xf84a4 vmov.f32 s14, s17 */
/* @0xf84a8 vstr s25, [sp, #16] */
/* @0xf84ac vcvt.f32.s32 s15, s15 */
/* @0xf84b0 vmla.f32 s8, s15, s23 */
/* @0xf84b4 vmls.f32 s14, s22, s15 */
/* @0xf84b8 vmov r2, s8 */
/* @0xf84bc vmov r3, s14 */
/* @0xf84c0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0xf84c4 ldrsh r10, [r10, #10] */
/* @0xf84c8 vmov s15, r10 */
/* @0xf84cc vcvt.f32.s32 s15, s15 */
/* @0xf84d0 vmla.f32 s16, s15, s23 */
/* @0xf84d4 vmls.f32 s17, s22, s15 */
/* @0xf84d8 b 0xf844c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x140> */
/* @0xf84dc ldr r3, [r6, #0x3c] */
/* @0xf84e0 cmp r3, #0 */
/* @0xf84e4 beq 0xf8aec <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x7e0> */
/* @0xf84e8 ldr r1, [pc, #0x258] */
/* @0xf84ec ldrsh r2, [r3, #20] */
/* @0xf84f0 mov r3, r1 */
/* @0xf84f4 ldr r3, [r8, r3] */
/* @0xf84f8 ldr r3, [r3, #0x4] */
/* @0xf84fc ldr r3, [r3, r2, lsl #2] */
/* @0xf8500 ldr r3, [r3] */
/* @0xf8504 str r3, [sp, #0x24] */
/* @0xf8508 cmp r4, #0 */
/* @0xf850c ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8510 lsl r10, r4, #1 */
/* @0xf8514 mov r4, #0 */
/* @0xf8518 b 0xf8528 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x21c> */
/* @0xf851c add r4, r4, #2 */
/* @0xf8520 cmp r4, r10 */
/* @0xf8524 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8528 ldrh r1, [r5, r4] */
/* @0xf852c cmp r1, #0 */
/* @0xf8530 beq 0xf851c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x210> */
/* @0xf8534 mov r0, r6 */
/* @0xf8538 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf853c subs r11, r0, #0 */
/* @0xf8540 beq 0xf851c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x210> */
/* @0xf8544 mov r0, #4 */
/* @0xf8548 ldr r1, [sp, #0x24] */
/* @0xf854c mov r2, #24 */
/* @0xf8550 mov r3, #6 */
/* @0xf8554 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xf8558 cmp r0, #0 */
/* @0xf855c beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8560 ldrsh r2, [r11, #12] */
/* @0xf8564 vmov.f32 s13, s16 */
/* @0xf8568 vldr s15, [r6, #80] */
/* @0xf856c ldrsh r3, [r11, #6] */
/* @0xf8570 ldrsh r12, [r11, #8] */
/* @0xf8574 vmov s12, r2 */
/* @0xf8578 ldrsh r1, [r11, #2] */
/* @0xf857c vsub.f32 s14, s17, s15 */
/* @0xf8580 ldr r2, [r6, #0x3c] */
/* @0xf8584 vmov s10, r3 */
/* @0xf8588 ldr r3, [pc, #0x1b4] */
/* @0xf858c vmov s11, r12 */
/* @0xf8590 ldrsh r12, [r11, #4] */
/* @0xf8594 vmov s8, r1 */
/* @0xf8598 cmp r2, #0 */
/* @0xf859c vcvt.f32.s32 s12, s12 */
/* @0xf85a0 vstr s14, [r0, #124] */
/* @0xf85a4 vstr s14, [r0, #4] */
/* @0xf85a8 vstr s14, [r0, #28] */
/* @0xf85ac vmla.f32 s13, s12, s18 */
/* @0xf85b0 vcvt.f32.s32 s10, s10 */
/* @0xf85b4 vcvt.f32.s32 s11, s11 */
/* @0xf85b8 vmov.f32 s9, s13 */
/* @0xf85bc vmov.f32 s14, s17 */
/* @0xf85c0 vmla.f32 s9, s10, s18 */
/* @0xf85c4 vmla.f32 s14, s11, s19 */
/* @0xf85c8 vadd.f32 s12, s15, s9 */
/* @0xf85cc vmov s9, r12 */
/* @0xf85d0 ldr r12, [sp, #0x1c] */
/* @0xf85d4 vadd.f32 s14, s15, s14 */
/* @0xf85d8 vstr s12, [r0, #24] */
/* @0xf85dc vstr s12, [r0, #72] */
/* @0xf85e0 vstr s12, [r0, #48] */
/* @0xf85e4 vsub.f32 s13, s13, s15 */
/* @0xf85e8 vstr s14, [r0, #76] */
/* @0xf85ec vstr s14, [r0, #52] */
/* @0xf85f0 vstr s14, [r0, #100] */
/* @0xf85f4 vstr s13, [r0, #120] */
/* @0xf85f8 vstr s13, [r0] */
/* @0xf85fc vstr s13, [r0, #96] */
/* @0xf8600 ldr r3, [r8, r3] */
/* @0xf8604 str r12, [r0, #0x24] */
/* @0xf8608 vcvt.f32.s32 s12, s8 */
/* @0xf860c ldr r12, [sp, #0x20] */
/* @0xf8610 ldr r3, [r3] */
/* @0xf8614 str r7, [r0, #0xc] */
/* @0xf8618 str r7, [r0, #0x84] */
/* @0xf861c str r3, [r0, #0x80] */
/* @0xf8620 str r3, [r0, #0x68] */
/* @0xf8624 str r3, [r0, #0x50] */
/* @0xf8628 vcvt.f32.s32 s14, s9 */
/* @0xf862c str r3, [r0, #0x38] */
/* @0xf8630 str r3, [r0, #0x20] */
/* @0xf8634 str r3, [r0, #0x8] */
/* @0xf8638 str r9, [r0, #0x3c] */
/* @0xf863c str r9, [r0, #0x54] */
/* @0xf8640 str r12, [r0, #0x6c] */
/* @0xf8644 beq 0xf8a6c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x760> */
/* @0xf8648 ldrsh r3, [r2] */
/* @0xf864c ldrsh r1, [r2, #20] */
/* @0xf8650 vmov s13, r3 */
/* @0xf8654 ldr r3, [pc, #0xec] */
/* @0xf8658 vcvt.f32.s32 s13, s13 */
/* @0xf865c ldr r3, [r8, r3] */
/* @0xf8660 ldr r3, [r3, #0x4] */
/* @0xf8664 vadd.f32 s13, s13, s12 */
/* @0xf8668 ldr r3, [r3, r1, lsl #2] */
/* @0xf866c vldr s9, [r3, #8] */
/* @0xf8670 vsub.f32 s12, s13, s15 */
/* @0xf8674 vmul.f32 s12, s12, s9 */
/* @0xf8678 vstr s12, [r0, #16] */
/* @0xf867c vstr s12, [r0, #112] */
/* @0xf8680 vstr s12, [r0, #136] */
/* @0xf8684 ldrsh r2, [r2, #2] */
/* @0xf8688 vadd.f32 s13, s10, s13 */
/* @0xf868c vldr s12, [r3, #12] */
/* @0xf8690 vmov s8, r2 */
/* @0xf8694 vcvt.f32.s32 s8, s8 */
/* @0xf8698 vadd.f32 s8, s8, s14 */
/* @0xf869c vadd.f32 s14, s11, s8 */
/* @0xf86a0 vadd.f32 s13, s15, s13 */
/* @0xf86a4 vadd.f32 s14, s15, s14 */
/* @0xf86a8 vsub.f32 s15, s8, s15 */
/* @0xf86ac vmul.f32 s13, s9, s13 */
/* @0xf86b0 vmul.f32 s14, s12, s14 */
/* @0xf86b4 vstr s13, [r0, #40] */
/* @0xf86b8 vstr s13, [r0, #64] */
/* @0xf86bc vstr s13, [r0, #88] */
/* @0xf86c0 vmul.f32 s15, s15, s12 */
/* @0xf86c4 vstr s14, [r0, #68] */
/* @0xf86c8 vstr s14, [r0, #92] */
/* @0xf86cc vstr s14, [r0, #116] */
/* @0xf86d0 vstr s15, [r0, #20] */
/* @0xf86d4 vstr s15, [r0, #44] */
/* @0xf86d8 vstr s15, [r0, #140] */
/* @0xf86dc ldrsh r11, [r11, #10] */
/* @0xf86e0 vmov s15, r11 */
/* @0xf86e4 vcvt.f32.s32 s15, s15 */
/* @0xf86e8 vmla.f32 s16, s15, s18 */
/* @0xf86ec b 0xf851c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x210> */
/* @0xf86f0 ldr r3, [r6, #0x3c] */
/* @0xf86f4 cmp r3, #0 */
/* @0xf86f8 beq 0xf8ad4 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x7c8> */
/* @0xf86fc ldr r1, [pc, #0x44] */
/* @0xf8700 ldrsh r2, [r3, #20] */
/* @0xf8704 mov r3, r1 */
/* @0xf8708 ldr r3, [r8, r3] */
/* @0xf870c ldr r3, [r3, #0x4] */
/* @0xf8710 ldr r3, [r3, r2, lsl #2] */
/* @0xf8714 ldr r3, [r3] */
/* @0xf8718 str r3, [sp, #0x24] */
/* @0xf871c cmp r4, #0 */
/* @0xf8720 ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8724 lsl r10, r4, #1 */
/* @0xf8728 mov r4, #0 */
/* @0xf872c b 0xf8758 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x44c> */
/* @0xf8730 cmnmi pc, #0 */
/* @0xf8734 blo 0xfe1bd0f8 <b2_toiTime+0xfffffffffda63c54> */
/* @0xf8738 vstmialo lr, {s30, s31} */
/* @0xf873c eoreq r9, pc, r0, lsl #18 */
/* @0xf8740 .word 0xffffc1fc */
/* @0xf8744 .word 0xffffbcd0 */
/* @0xf8748 .word 0xffffbccc */
/* @0xf874c add r4, r4, #2 */
/* @0xf8750 cmp r4, r10 */
/* @0xf8754 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8758 ldrh r1, [r5, r4] */
/* @0xf875c cmp r1, #0 */
/* @0xf8760 beq 0xf874c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x440> */
/* @0xf8764 mov r0, r6 */
/* @0xf8768 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf876c subs r11, r0, #0 */
/* @0xf8770 beq 0xf874c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x440> */
/* @0xf8774 mov r0, #4 */
/* @0xf8778 ldr r1, [sp, #0x24] */
/* @0xf877c mov r2, #24 */
/* @0xf8780 mov r3, #6 */
/* @0xf8784 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xf8788 cmp r0, #0 */
/* @0xf878c beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8790 ldrsh r2, [r11, #12] */
/* @0xf8794 vmov.f32 s14, s17 */
/* @0xf8798 ldrsh r3, [r11, #6] */
/* @0xf879c vldr s15, [r6, #80] */
/* @0xf87a0 ldrsh r12, [r11, #8] */
/* @0xf87a4 vmov s12, r2 */
/* @0xf87a8 ldrsh r1, [r11, #2] */
/* @0xf87ac vmov.f32 s13, s16 */
/* @0xf87b0 ldr r2, [r6, #0x3c] */
/* @0xf87b4 vmov s10, r3 */
/* @0xf87b8 ldr r3, [pc, #-0x7c] */
/* @0xf87bc vmov s11, r12 */
/* @0xf87c0 ldrsh r12, [r11, #4] */
/* @0xf87c4 cmp r2, #0 */
/* @0xf87c8 vcvt.f32.s32 s12, s12 */
/* @0xf87cc vmls.f32 s14, s22, s12 */
/* @0xf87d0 vmla.f32 s13, s12, s23 */
/* @0xf87d4 vcvt.f32.s32 s10, s10 */
/* @0xf87d8 vmul.f32 s12, s18, s10 */
/* @0xf87dc vcvt.f32.s32 s11, s11 */
/* @0xf87e0 vmov.f32 s8, s14 */
/* @0xf87e4 vmov.f32 s9, s13 */
/* @0xf87e8 vmls.f32 s8, s20, s12 */
/* @0xf87ec vmul.f32 s7, s19, s11 */
/* @0xf87f0 vmla.f32 s9, s12, s21 */
/* @0xf87f4 vmul.f32 s6, s20, s7 */
/* @0xf87f8 vmul.f32 s7, s7, s21 */
/* @0xf87fc vmov.f32 s12, s8 */
/* @0xf8800 vadd.f32 s8, s6, s9 */
/* @0xf8804 vadd.f32 s5, s7, s12 */
/* @0xf8808 vadd.f32 s6, s13, s6 */
/* @0xf880c vadd.f32 s7, s14, s7 */
/* @0xf8810 vsub.f32 s13, s13, s15 */
/* @0xf8814 vsub.f32 s9, s9, s15 */
/* @0xf8818 vstr s13, [r0, #120] */
/* @0xf881c vstr s13, [r0] */
/* @0xf8820 vadd.f32 s8, s15, s8 */
/* @0xf8824 vstr s9, [r0, #24] */
/* @0xf8828 vadd.f32 s13, s15, s5 */
/* @0xf882c vstr s8, [r0, #72] */
/* @0xf8830 vstr s8, [r0, #48] */
/* @0xf8834 vmov s8, r1 */
/* @0xf8838 vsub.f32 s14, s14, s15 */
/* @0xf883c vstr s13, [r0, #76] */
/* @0xf8840 vstr s13, [r0, #52] */
/* @0xf8844 vmov s13, r12 */
/* @0xf8848 ldr r12, [sp, #0x1c] */
/* @0xf884c vsub.f32 s9, s12, s15 */
/* @0xf8850 vstr s14, [r0, #124] */
/* @0xf8854 vstr s14, [r0, #4] */
/* @0xf8858 vadd.f32 s6, s15, s6 */
/* @0xf885c vstr s9, [r0, #28] */
/* @0xf8860 vadd.f32 s7, s15, s7 */
/* @0xf8864 vstr s6, [r0, #96] */
/* @0xf8868 vstr s7, [r0, #100] */
/* @0xf886c ldr r3, [r8, r3] */
/* @0xf8870 str r12, [r0, #0x24] */
/* @0xf8874 vcvt.f32.s32 s12, s8 */
/* @0xf8878 ldr r12, [sp, #0x20] */
/* @0xf887c ldr r3, [r3] */
/* @0xf8880 str r7, [r0, #0xc] */
/* @0xf8884 str r7, [r0, #0x84] */
/* @0xf8888 str r3, [r0, #0x80] */
/* @0xf888c str r3, [r0, #0x68] */
/* @0xf8890 str r3, [r0, #0x50] */
/* @0xf8894 vcvt.f32.s32 s14, s13 */
/* @0xf8898 str r3, [r0, #0x38] */
/* @0xf889c str r3, [r0, #0x20] */
/* @0xf88a0 str r3, [r0, #0x8] */
/* @0xf88a4 str r9, [r0, #0x3c] */
/* @0xf88a8 str r9, [r0, #0x54] */
/* @0xf88ac str r12, [r0, #0x6c] */
/* @0xf88b0 beq 0xf8a04 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x6f8> */
/* @0xf88b4 ldrsh r3, [r2] */
/* @0xf88b8 ldrsh r1, [r2, #20] */
/* @0xf88bc vmov s13, r3 */
/* @0xf88c0 ldr r3, [pc, #-0x180] */
/* @0xf88c4 vcvt.f32.s32 s13, s13 */
/* @0xf88c8 ldr r3, [r8, r3] */
/* @0xf88cc ldr r3, [r3, #0x4] */
/* @0xf88d0 vadd.f32 s13, s13, s12 */
/* @0xf88d4 ldr r3, [r3, r1, lsl #2] */
/* @0xf88d8 vldr s9, [r3, #8] */
/* @0xf88dc vsub.f32 s12, s13, s15 */
/* @0xf88e0 vmul.f32 s12, s12, s9 */
/* @0xf88e4 vstr s12, [r0, #16] */
/* @0xf88e8 vstr s12, [r0, #112] */
/* @0xf88ec vstr s12, [r0, #136] */
/* @0xf88f0 ldrsh r2, [r2, #2] */
/* @0xf88f4 vadd.f32 s13, s10, s13 */
/* @0xf88f8 vldr s12, [r3, #12] */
/* @0xf88fc vmov s8, r2 */
/* @0xf8900 vcvt.f32.s32 s8, s8 */
/* @0xf8904 vadd.f32 s8, s8, s14 */
/* @0xf8908 vadd.f32 s14, s11, s8 */
/* @0xf890c vadd.f32 s13, s15, s13 */
/* @0xf8910 vadd.f32 s14, s15, s14 */
/* @0xf8914 vsub.f32 s15, s8, s15 */
/* @0xf8918 vmul.f32 s13, s9, s13 */
/* @0xf891c vmul.f32 s14, s12, s14 */
/* @0xf8920 vstr s13, [r0, #40] */
/* @0xf8924 vstr s13, [r0, #64] */
/* @0xf8928 vstr s13, [r0, #88] */
/* @0xf892c vmul.f32 s15, s15, s12 */
/* @0xf8930 vstr s14, [r0, #68] */
/* @0xf8934 vstr s14, [r0, #92] */
/* @0xf8938 vstr s14, [r0, #116] */
/* @0xf893c vstr s15, [r0, #20] */
/* @0xf8940 vstr s15, [r0, #44] */
/* @0xf8944 vstr s15, [r0, #140] */
/* @0xf8948 ldrsh r11, [r11, #10] */
/* @0xf894c vmov s15, r11 */
/* @0xf8950 vcvt.f32.s32 s15, s15 */
/* @0xf8954 vmla.f32 s16, s15, s23 */
/* @0xf8958 vmls.f32 s17, s22, s15 */
/* @0xf895c b 0xf874c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x440> */
/* @0xf8960 ldr r0, [r6, #0x20] */
/* @0xf8964 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xf8968 cmp r4, #0 */
/* @0xf896c mov r9, r0 */
/* @0xf8970 ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf8974 lsl r4, r4, #1 */
/* @0xf8978 mov r7, #0 */
/* @0xf897c b 0xf898c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x680> */
/* @0xf8980 add r7, r7, #2 */
/* @0xf8984 cmp r7, r4 */
/* @0xf8988 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4> */
/* @0xf898c ldrh r8, [r5, r7] */
/* @0xf8990 cmp r8, #0 */
/* @0xf8994 beq 0xf8980 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x674> */
/* @0xf8998 mov r0, r6 */
/* @0xf899c mov r1, r8 */
/* @0xf89a0 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf89a4 vmov r3, s17 */
/* @0xf89a8 subs r10, r0, #0 */
/* @0xf89ac mov r0, r9 */
/* @0xf89b0 beq 0xf8980 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x674> */
/* @0xf89b4 cmp r8, #32 */
/* @0xf89b8 beq 0xf89f0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x6e4> */
/* @0xf89bc ldrsh r2, [r10, #12] */
/* @0xf89c0 vmov.f32 s8, s16 */
/* @0xf89c4 ldrsh r1, [r10, #6] */
/* @0xf89c8 vstr s18, [sp] */
/* @0xf89cc vstr s19, [sp, #4] */
/* @0xf89d0 vstr s24, [sp, #8] */
/* @0xf89d4 vmov s15, r2 */
/* @0xf89d8 str r11, [sp, #0xc] */
/* @0xf89dc vstr s25, [sp, #16] */
/* @0xf89e0 vcvt.f32.s32 s15, s15 */
/* @0xf89e4 vmla.f32 s8, s15, s18 */
/* @0xf89e8 vmov r2, s8 */
/* @0xf89ec bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0xf89f0 ldrsh r10, [r10, #10] */
/* @0xf89f4 vmov s15, r10 */
/* @0xf89f8 vcvt.f32.s32 s15, s15 */
/* @0xf89fc vmla.f32 s16, s15, s18 */
/* @0xf8a00 b 0xf8980 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x674> */
/* @0xf8a04 ldr r3, [pc, #-0x2c4] */
/* @0xf8a08 vadd.f32 s10, s12, s10 */
/* @0xf8a0c ldr r2, [r6, #0x38] */
/* @0xf8a10 ldr r3, [r8, r3] */
/* @0xf8a14 ldr r3, [r3, #0x4] */
/* @0xf8a18 ldr r3, [r3, r2, lsl #2] */
/* @0xf8a1c vldr s13, [r3, #8] */
/* @0xf8a20 vmul.f32 s12, s13, s12 */
/* @0xf8a24 vadd.f32 s11, s14, s11 */
/* @0xf8a28 vstr s12, [r0, #16] */
/* @0xf8a2c vstr s12, [r0, #112] */
/* @0xf8a30 vstr s12, [r0, #136] */
/* @0xf8a34 vldr s15, [r3, #12] */
/* @0xf8a38 vmul.f32 s10, s13, s10 */
/* @0xf8a3c vmul.f32 s14, s15, s14 */
/* @0xf8a40 vstr s10, [r0, #40] */
/* @0xf8a44 vstr s10, [r0, #64] */
/* @0xf8a48 vstr s10, [r0, #88] */
/* @0xf8a4c vmul.f32 s11, s15, s11 */
/* @0xf8a50 vstr s14, [r0, #20] */
/* @0xf8a54 vstr s14, [r0, #44] */
/* @0xf8a58 vstr s14, [r0, #140] */
/* @0xf8a5c vstr s11, [r0, #68] */
/* @0xf8a60 vstr s11, [r0, #92] */
/* @0xf8a64 vstr s11, [r0, #116] */
/* @0xf8a68 b 0xf8948 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x63c> */
/* @0xf8a6c ldr r3, [pc, #-0x32c] */
/* @0xf8a70 vadd.f32 s10, s10, s12 */
/* @0xf8a74 ldr r2, [r6, #0x38] */
/* @0xf8a78 ldr r3, [r8, r3] */
/* @0xf8a7c ldr r3, [r3, #0x4] */
/* @0xf8a80 ldr r3, [r3, r2, lsl #2] */
/* @0xf8a84 vldr s13, [r3, #8] */
/* @0xf8a88 vmul.f32 s12, s13, s12 */
/* @0xf8a8c vadd.f32 s11, s11, s14 */
/* @0xf8a90 vstr s12, [r0, #16] */
/* @0xf8a94 vstr s12, [r0, #112] */
/* @0xf8a98 vstr s12, [r0, #136] */
/* @0xf8a9c vldr s15, [r3, #12] */
/* @0xf8aa0 vmul.f32 s10, s13, s10 */
/* @0xf8aa4 vmul.f32 s14, s15, s14 */
/* @0xf8aa8 vstr s10, [r0, #40] */
/* @0xf8aac vstr s10, [r0, #64] */
/* @0xf8ab0 vstr s10, [r0, #88] */
/* @0xf8ab4 vmul.f32 s11, s15, s11 */
/* @0xf8ab8 vstr s14, [r0, #20] */
/* @0xf8abc vstr s14, [r0, #44] */
/* @0xf8ac0 vstr s14, [r0, #140] */
/* @0xf8ac4 vstr s11, [r0, #68] */
/* @0xf8ac8 vstr s11, [r0, #92] */
/* @0xf8acc vstr s11, [r0, #116] */
/* @0xf8ad0 b 0xf86dc <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x3d0> */
/* @0xf8ad4 ldr r2, [r6, #0x38] */
/* @0xf8ad8 cmp r2, #0 */
/* @0xf8adc strlt r3, [sp, #0x24] */
/* @0xf8ae0 blt 0xf871c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x410> */
/* @0xf8ae4 ldr r3, [pc, #-0x3a4] */
/* @0xf8ae8 b 0xf8708 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x3fc> */
/* @0xf8aec ldr r2, [r6, #0x38] */
/* @0xf8af0 cmp r2, #0 */
/* @0xf8af4 strlt r3, [sp, #0x24] */
/* @0xf8af8 blt 0xf8508 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1fc> */
/* @0xf8afc ldr r3, [pc, #-0x3bc] */
/* @0xf8b00 b 0xf84f4 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1e8> */

/* ── FUNC 0xf8b04 · CFontGM::TextWidth(unsigned short*) · size=84 · insn=21 */
/* @0xf8b04 push {r4, r5, r6, lr} */
/* @0xf8b08 subs r5, r1, #0 */
/* @0xf8b0c mov r6, r0 */
/* @0xf8b10 beq 0xf8b44 <_ZN7CFontGM9TextWidthEPt+0x40> */
/* @0xf8b14 ldrh r1, [r5] */
/* @0xf8b18 cmp r1, #0 */
/* @0xf8b1c beq 0xf8b50 <_ZN7CFontGM9TextWidthEPt+0x4c> */
/* @0xf8b20 mov r4, #0 */
/* @0xf8b24 mov r0, r6 */
/* @0xf8b28 bl 0xf6e78 <_ZN7CFontGM8GetShiftEi> */
/* @0xf8b2c ldrh r1, [r5, #2]! */
/* @0xf8b30 cmp r1, #0 */
/* @0xf8b34 add r4, r4, r0 */
/* @0xf8b38 bne 0xf8b24 <_ZN7CFontGM9TextWidthEPt+0x20> */
/* @0xf8b3c mov r0, r4 */
/* @0xf8b40 pop {r4, r5, r6, pc} */
/* @0xf8b44 mov r4, r5 */
/* @0xf8b48 mov r0, r4 */
/* @0xf8b4c pop {r4, r5, r6, pc} */
/* @0xf8b50 mov r4, r1 */
/* @0xf8b54 b 0xf8b3c <_ZN7CFontGM9TextWidthEPt+0x38> */

/* ── FUNC 0xf8b58 · CFontGM::Draw_String_Color(float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=1024 · insn=256 */
/* @0xf8b58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf8b5c vpush {d8, d9, d10, d11} */
/* @0xf8b60 sub sp, sp, #68 */
/* @0xf8b64 vldr s21, [sp, #152] */
/* @0xf8b68 mov r5, r0 */
/* @0xf8b6c mov r0, r3 */
/* @0xf8b70 mov r4, r3 */
/* @0xf8b74 str r2, [sp, #0x3c] */
/* @0xf8b78 vmov s17, r1 */
/* @0xf8b7c bl 0xf6c78 <_Z8yywcslenPKt> */
/* @0xf8b80 mov r1, r4 */
/* @0xf8b84 mov r7, r0 */
/* @0xf8b88 mov r0, r5 */
/* @0xf8b8c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0xf8b90 vmov s20, r0 */
/* @0xf8b94 ldr r0, [r5, #0x20] */
/* @0xf8b98 cmp r0, #0 */
/* @0xf8b9c blt 0xf8c40 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0xe8> */
/* @0xf8ba0 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0xf8ba4 cmp r0, #0 */
/* @0xf8ba8 bne 0xf8bb8 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x60> */
/* @0xf8bac add sp, sp, #68 */
/* @0xf8bb0 vpop {d8, d9, d10, d11} */
/* @0xf8bb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf8bb8 ldr r0, [r5, #0x20] */
/* @0xf8bbc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xf8bc0 cmp r7, #0 */
/* @0xf8bc4 mov r9, r0 */
/* @0xf8bc8 ble 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54> */
/* @0xf8bcc vldr s16, [pc, #896] */
/* @0xf8bd0 lsl r7, r7, #1 */
/* @0xf8bd4 vmov.f32 s22, s16 */
/* @0xf8bd8 mov r6, #0 */
/* @0xf8bdc ldr r11, [sp, #0x88] */
/* @0xf8be0 b 0xf8bf0 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x98> */
/* @0xf8be4 add r6, r6, #2 */
/* @0xf8be8 cmp r6, r7 */
/* @0xf8bec beq 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54> */
/* @0xf8bf0 ldrh r10, [r4, r6] */
/* @0xf8bf4 cmp r10, #0 */
/* @0xf8bf8 beq 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c> */
/* @0xf8bfc mov r1, r10 */
/* @0xf8c00 mov r0, r5 */
/* @0xf8c04 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf8c08 ldr r1, [sp, #0x8c] */
/* @0xf8c0c subs r8, r0, #0 */
/* @0xf8c10 mov r0, r11 */
/* @0xf8c14 beq 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c> */
/* @0xf8c18 cmp r10, #32 */
/* @0xf8c1c bne 0xf8db4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x25c> */
/* @0xf8c20 ldrsh r8, [r8, #10] */
/* @0xf8c24 vldr s14, [r5, #72] */
/* @0xf8c28 vmov s15, r8 */
/* @0xf8c2c vcvt.f32.s32 s15, s15 */
/* @0xf8c30 vmul.f32 s15, s15, s14 */
/* @0xf8c34 vadd.f32 s17, s17, s15 */
/* @0xf8c38 vadd.f32 s16, s16, s15 */
/* @0xf8c3c b 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c> */
/* @0xf8c40 cmp r7, #0 */
/* @0xf8c44 ble 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54> */
/* @0xf8c48 vldr s16, [pc, #772] */
/* @0xf8c4c vmov.f32 s22, #1.000000e+00 */
/* @0xf8c50 lsl r7, r7, #1 */
/* @0xf8c54 mov r6, #0 */
/* @0xf8c58 vmov.f32 s23, s16 */
/* @0xf8c5c b 0xf8c6c <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x114> */
/* @0xf8c60 add r6, r6, #2 */
/* @0xf8c64 cmp r6, r7 */
/* @0xf8c68 beq 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54> */
/* @0xf8c6c ldrh r1, [r4, r6] */
/* @0xf8c70 cmp r1, #0 */
/* @0xf8c74 beq 0xf8c60 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x108> */
/* @0xf8c78 mov r0, r5 */
/* @0xf8c7c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf8c80 ldr r1, [sp, #0x8c] */
/* @0xf8c84 subs r8, r0, #0 */
/* @0xf8c88 ldr r0, [sp, #0x88] */
/* @0xf8c8c beq 0xf8c60 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x108> */
/* @0xf8c90 vcvt.f32.s32 s18, s20 */
/* @0xf8c94 vdiv.f32 s19, s16, s18 */
/* @0xf8c98 vmov r2, s19 */
/* @0xf8c9c bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8ca0 ldr r1, [sp, #0x8c] */
/* @0xf8ca4 mov r11, r0 */
/* @0xf8ca8 ldrsh r0, [r8, #10] */
/* @0xf8cac vmov s15, r0 */
/* @0xf8cb0 ldr r0, [sp, #0x88] */
/* @0xf8cb4 vcvt.f32.s32 s15, s15 */
/* @0xf8cb8 vadd.f32 s15, s15, s16 */
/* @0xf8cbc vdiv.f32 s15, s15, s18 */
/* @0xf8cc0 vmov r2, s15 */
/* @0xf8cc4 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8cc8 ldrsh r3, [r8, #10] */
/* @0xf8ccc ldr r1, [sp, #0x90] */
/* @0xf8cd0 vmov s15, r3 */
/* @0xf8cd4 vcvt.f32.s32 s15, s15 */
/* @0xf8cd8 vadd.f32 s15, s15, s16 */
/* @0xf8cdc vdiv.f32 s15, s15, s18 */
/* @0xf8ce0 mov r10, r0 */
/* @0xf8ce4 ldr r0, [sp, #0x94] */
/* @0xf8ce8 vmov r2, s15 */
/* @0xf8cec bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8cf0 ldr r1, [sp, #0x90] */
/* @0xf8cf4 vmov r2, s19 */
/* @0xf8cf8 mov r9, r0 */
/* @0xf8cfc ldr r0, [sp, #0x94] */
/* @0xf8d00 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8d04 mov lr, r0 */
/* @0xf8d08 ldr r0, [r5, #0x3c] */
/* @0xf8d0c cmp r0, #0 */
/* @0xf8d10 beq 0xf8ecc <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x374> */
/* @0xf8d14 ldrsh r12, [r8, #8] */
/* @0xf8d18 vldr s14, [r5, #72] */
/* @0xf8d1c ldrsh r1, [r8, #2] */
/* @0xf8d20 ldrsh r2, [r8, #4] */
/* @0xf8d24 vmov s15, r12 */
/* @0xf8d28 ldrsh r3, [r8, #6] */
/* @0xf8d2c vmov s13, r1 */
/* @0xf8d30 vcvt.f32.s32 s15, s15 */
/* @0xf8d34 vstr s15, [sp] */
/* @0xf8d38 ldrsh r12, [r8, #12] */
/* @0xf8d3c vcvt.f32.s32 s13, s13 */
/* @0xf8d40 vstr s14, [sp, #12] */
/* @0xf8d44 vmov s14, r3 */
/* @0xf8d48 vstr s23, [sp, #20] */
/* @0xf8d4c vmov s15, r12 */
/* @0xf8d50 ldr r12, [sp, #0x3c] */
/* @0xf8d54 str r11, [sp, #0x18] */
/* @0xf8d58 vstr s21, [sp, #40] */
/* @0xf8d5c str r10, [sp, #0x1c] */
/* @0xf8d60 str r12, [sp, #0x8] */
/* @0xf8d64 str r9, [sp, #0x20] */
/* @0xf8d68 vcvt.f32.s32 s15, s15 */
/* @0xf8d6c str lr, [sp, #0x24] */
/* @0xf8d70 vmov r1, s13 */
/* @0xf8d74 vmov s13, r2 */
/* @0xf8d78 ldr lr, [r5, #0x4c] */
/* @0xf8d7c str lr, [sp, #0x10] */
/* @0xf8d80 vadd.f32 s15, s15, s17 */
/* @0xf8d84 vcvt.f32.s32 s13, s13 */
/* @0xf8d88 vstr s15, [sp, #4] */
/* @0xf8d8c vcvt.f32.s32 s14, s14 */
/* @0xf8d90 vmov r2, s13 */
/* @0xf8d94 vmov r3, s14 */
/* @0xf8d98 bl 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf> */
/* @0xf8d9c ldrsh r8, [r8, #10] */
/* @0xf8da0 vmov s15, r8 */
/* @0xf8da4 vcvt.f32.s32 s15, s15 */
/* @0xf8da8 vadd.f32 s17, s17, s15 */
/* @0xf8dac vadd.f32 s16, s16, s15 */
/* @0xf8db0 b 0xf8c60 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x108> */
/* @0xf8db4 vcvt.f32.s32 s18, s20 */
/* @0xf8db8 vdiv.f32 s19, s16, s18 */
/* @0xf8dbc vmov r2, s19 */
/* @0xf8dc0 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8dc4 ldr r1, [sp, #0x8c] */
/* @0xf8dc8 mov r12, r0 */
/* @0xf8dcc ldrsh r0, [r8, #10] */
/* @0xf8dd0 str r12, [sp, #0x34] */
/* @0xf8dd4 vmov s15, r0 */
/* @0xf8dd8 mov r0, r11 */
/* @0xf8ddc vcvt.f32.s32 s15, s15 */
/* @0xf8de0 vadd.f32 s15, s15, s16 */
/* @0xf8de4 vdiv.f32 s15, s15, s18 */
/* @0xf8de8 vmov r2, s15 */
/* @0xf8dec bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8df0 ldrsh r3, [r8, #10] */
/* @0xf8df4 ldr r1, [sp, #0x90] */
/* @0xf8df8 vmov s15, r3 */
/* @0xf8dfc vcvt.f32.s32 s15, s15 */
/* @0xf8e00 vadd.f32 s15, s15, s16 */
/* @0xf8e04 vdiv.f32 s15, s15, s18 */
/* @0xf8e08 str r0, [sp, #0x38] */
/* @0xf8e0c ldr r0, [sp, #0x94] */
/* @0xf8e10 vmov r2, s15 */
/* @0xf8e14 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8e18 ldr r1, [sp, #0x90] */
/* @0xf8e1c vmov r2, s19 */
/* @0xf8e20 mov r10, r0 */
/* @0xf8e24 ldr r0, [sp, #0x94] */
/* @0xf8e28 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf8e2c vldr s13, [r9, #28] */
/* @0xf8e30 vcvt.f32.s32 s14, s13 */
/* @0xf8e34 vldr s15, [r5, #72] */
/* @0xf8e38 vldr s13, [r5, #76] */
/* @0xf8e3c ldrsh r1, [r8, #6] */
/* @0xf8e40 vstr s13, [sp, #48] */
/* @0xf8e44 ldr r12, [sp, #0x34] */
/* @0xf8e48 mov r2, #0 */
/* @0xf8e4c mov r3, r2 */
/* @0xf8e50 vstr s14, [sp] */
/* @0xf8e54 vldr s13, [r9, #32] */
/* @0xf8e58 vcvt.f32.s32 s14, s13 */
/* @0xf8e5c vldr s13, [sp, #48] */
/* @0xf8e60 vstr s14, [sp, #4] */
/* @0xf8e64 ldrsh lr, [r8, #12] */
/* @0xf8e68 vstr s13, [sp, #20] */
/* @0xf8e6c vmov.f32 s13, s17 */
/* @0xf8e70 str r12, [sp, #0x1c] */
/* @0xf8e74 vstr s15, [sp, #16] */
/* @0xf8e78 vmov s14, lr */
/* @0xf8e7c ldr r12, [sp, #0x3c] */
/* @0xf8e80 vstr s22, [sp, #24] */
/* @0xf8e84 str r10, [sp, #0x24] */
/* @0xf8e88 vcvt.f32.s32 s14, s14 */
/* @0xf8e8c vstr s21, [sp, #44] */
/* @0xf8e90 str r12, [sp, #0xc] */
/* @0xf8e94 ldr r12, [sp, #0x38] */
/* @0xf8e98 str r12, [sp, #0x20] */
/* @0xf8e9c vmla.f32 s13, s14, s15 */
/* @0xf8ea0 str r0, [sp, #0x28] */
/* @0xf8ea4 mov r0, r9 */
/* @0xf8ea8 vstr s13, [sp, #8] */
/* @0xf8eac bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf> */
/* @0xf8eb0 ldrsh r8, [r8, #10] */
/* @0xf8eb4 vldr s14, [r5, #72] */
/* @0xf8eb8 vmov s15, r8 */
/* @0xf8ebc vcvt.f32.s32 s15, s15 */
/* @0xf8ec0 vmla.f32 s17, s15, s14 */
/* @0xf8ec4 vadd.f32 s16, s16, s15 */
/* @0xf8ec8 b 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c> */
/* @0xf8ecc ldrsh r0, [r8, #8] */
/* @0xf8ed0 ldrsh r1, [r8, #2] */
/* @0xf8ed4 ldrsh r2, [r8, #4] */
/* @0xf8ed8 vmov s15, r0 */
/* @0xf8edc ldrsh r3, [r8, #6] */
/* @0xf8ee0 ldr r0, [r5, #0x38] */
/* @0xf8ee4 vmov s13, r1 */
/* @0xf8ee8 vcvt.f32.s32 s15, s15 */
/* @0xf8eec vmov s14, r3 */
/* @0xf8ef0 vstr s15, [sp] */
/* @0xf8ef4 ldrsh r12, [r8, #12] */
/* @0xf8ef8 vcvt.f32.s32 s13, s13 */
/* @0xf8efc vstr s22, [sp, #12] */
/* @0xf8f00 vstr s22, [sp, #16] */
/* @0xf8f04 vstr s23, [sp, #20] */
/* @0xf8f08 vmov s15, r12 */
/* @0xf8f0c ldr r12, [sp, #0x3c] */
/* @0xf8f10 str r11, [sp, #0x18] */
/* @0xf8f14 vstr s21, [sp, #40] */
/* @0xf8f18 str r10, [sp, #0x1c] */
/* @0xf8f1c str r12, [sp, #0x8] */
/* @0xf8f20 str r9, [sp, #0x20] */
/* @0xf8f24 vcvt.f32.s32 s15, s15 */
/* @0xf8f28 str lr, [sp, #0x24] */
/* @0xf8f2c vmov r1, s13 */
/* @0xf8f30 vmov s13, r2 */
/* @0xf8f34 vadd.f32 s15, s15, s17 */
/* @0xf8f38 vcvt.f32.s32 s13, s13 */
/* @0xf8f3c vstr s15, [sp, #4] */
/* @0xf8f40 vcvt.f32.s32 s14, s14 */
/* @0xf8f44 vmov r2, s13 */
/* @0xf8f48 vmov r3, s14 */
/* @0xf8f4c bl 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf> */
/* @0xf8f50 b 0xf8d9c <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x244> */
/* @0xf8f54 andeq r0, r0, r0 */

/* ── FUNC 0xf8f58 · CFontGM::Draw_String_Transformed_Color(float, float, unsigned short*, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=1100 · insn=275 */
/* @0xf8f58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf8f5c vpush {d8, d9, d10, d11, d12, d13} */
/* @0xf8f60 mov r6, r0 */
/* @0xf8f64 vldr s20, [pc, #912] */
/* @0xf8f68 sub sp, sp, #60 */
/* @0xf8f6c mov r0, r3 */
/* @0xf8f70 mov r4, r3 */
/* @0xf8f74 vmov s19, r2 */
/* @0xf8f78 vldr s17, [sp, #152] */
/* @0xf8f7c vmov s18, r1 */
/* @0xf8f80 vldr s16, [sp, #144] */
/* @0xf8f84 vldr s26, [sp, #148] */
/* @0xf8f88 vldr s27, [sp, #172] */
/* @0xf8f8c bl 0xf6c78 <_Z8yywcslenPKt> */
/* @0xf8f90 mov r1, r4 */
/* @0xf8f94 mov r7, r0 */
/* @0xf8f98 mov r0, r6 */
/* @0xf8f9c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0xf8fa0 vmul.f32 s20, s17, s20 */
/* @0xf8fa4 vmov s25, r0 */
/* @0xf8fa8 vmov r0, s20 */
/* @0xf8fac bl 0xb6580 <sinf@plt> */
/* @0xf8fb0 vmov s22, r0 */
/* @0xf8fb4 vmov r0, s20 */
/* @0xf8fb8 bl 0xb658c <cosf@plt> */
/* @0xf8fbc vmov s23, r0 */
/* @0xf8fc0 ldr r0, [r6, #0x20] */
/* @0xf8fc4 cmp r0, #0 */
/* @0xf8fc8 blt 0xf9068 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x110> */
/* @0xf8fcc bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0xf8fd0 cmp r0, #0 */
/* @0xf8fd4 bne 0xf8fe4 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x8c> */
/* @0xf8fd8 add sp, sp, #60 */
/* @0xf8fdc vpop {d8, d9, d10, d11, d12, d13} */
/* @0xf8fe0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf8fe4 ldr r0, [r6, #0x20] */
/* @0xf8fe8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xf8fec cmp r7, #0 */
/* @0xf8ff0 mov r9, r0 */
/* @0xf8ff4 ble 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80> */
/* @0xf8ff8 vmul.f32 s22, s22, s16 */
/* @0xf8ffc lsl r7, r7, #1 */
/* @0xf9000 mov r5, #0 */
/* @0xf9004 vldr s20, [pc, #756] */
/* @0xf9008 ldr r11, [sp, #0x9c] */
/* @0xf900c vmul.f32 s23, s23, s16 */
/* @0xf9010 b 0xf9020 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xc8> */
/* @0xf9014 add r5, r5, #2 */
/* @0xf9018 cmp r5, r7 */
/* @0xf901c beq 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80> */
/* @0xf9020 ldrh r10, [r4, r5] */
/* @0xf9024 cmp r10, #0 */
/* @0xf9028 beq 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc> */
/* @0xf902c mov r1, r10 */
/* @0xf9030 mov r0, r6 */
/* @0xf9034 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf9038 ldr r1, [sp, #0xa0] */
/* @0xf903c subs r8, r0, #0 */
/* @0xf9040 mov r0, r11 */
/* @0xf9044 beq 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc> */
/* @0xf9048 cmp r10, #32 */
/* @0xf904c bne 0xf91f0 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x298> */
/* @0xf9050 ldrsh r8, [r8, #10] */
/* @0xf9054 vmov s15, r8 */
/* @0xf9058 vcvt.f32.s32 s15, s15 */
/* @0xf905c vmla.f32 s18, s15, s23 */
/* @0xf9060 vmls.f32 s19, s22, s15 */
/* @0xf9064 b 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc> */
/* @0xf9068 cmp r7, #0 */
/* @0xf906c ble 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80> */
/* @0xf9070 lsl r7, r7, #1 */
/* @0xf9074 mov r5, #0 */
/* @0xf9078 vldr s17, [pc, #640] */
/* @0xf907c b 0xf908c <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x134> */
/* @0xf9080 add r5, r5, #2 */
/* @0xf9084 cmp r5, r7 */
/* @0xf9088 beq 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80> */
/* @0xf908c ldrh r1, [r4, r5] */
/* @0xf9090 cmp r1, #0 */
/* @0xf9094 beq 0xf9080 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x128> */
/* @0xf9098 mov r0, r6 */
/* @0xf909c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi> */
/* @0xf90a0 ldr r1, [sp, #0xa0] */
/* @0xf90a4 subs r8, r0, #0 */
/* @0xf90a8 ldr r0, [sp, #0x9c] */
/* @0xf90ac beq 0xf9080 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x128> */
/* @0xf90b0 vcvt.f32.s32 s21, s25 */
/* @0xf90b4 vdiv.f32 s24, s17, s21 */
/* @0xf90b8 vmov r2, s24 */
/* @0xf90bc bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf90c0 ldrsh r3, [r8, #10] */
/* @0xf90c4 ldr r1, [sp, #0xa0] */
/* @0xf90c8 vmov s15, r3 */
/* @0xf90cc vcvt.f32.s32 s15, s15 */
/* @0xf90d0 vadd.f32 s15, s15, s17 */
/* @0xf90d4 vdiv.f32 s15, s15, s21 */
/* @0xf90d8 mov r11, r0 */
/* @0xf90dc ldr r0, [sp, #0x9c] */
/* @0xf90e0 vmov r2, s15 */
/* @0xf90e4 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf90e8 ldr r1, [sp, #0xa4] */
/* @0xf90ec mov r10, r0 */
/* @0xf90f0 ldrsh r0, [r8, #10] */
/* @0xf90f4 vmov s15, r0 */
/* @0xf90f8 ldr r0, [sp, #0xa8] */
/* @0xf90fc vcvt.f32.s32 s15, s15 */
/* @0xf9100 vadd.f32 s15, s15, s17 */
/* @0xf9104 vdiv.f32 s15, s15, s21 */
/* @0xf9108 vmov r2, s15 */
/* @0xf910c bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf9110 ldr r1, [sp, #0xa4] */
/* @0xf9114 vmov r2, s24 */
/* @0xf9118 mov r9, r0 */
/* @0xf911c ldr r0, [sp, #0xa8] */
/* @0xf9120 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf9124 mov lr, r0 */
/* @0xf9128 ldr r0, [r6, #0x3c] */
/* @0xf912c cmp r0, #0 */
/* @0xf9130 beq 0xf9304 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x3ac> */
/* @0xf9134 ldrsh r3, [r8, #12] */
/* @0xf9138 ldrsh r1, [r8, #2] */
/* @0xf913c ldrsh r2, [r8, #4] */
/* @0xf9140 vmov s15, r3 */
/* @0xf9144 ldrsh r3, [r8, #8] */
/* @0xf9148 vcvt.f32.s32 s15, s15 */
/* @0xf914c vmov s12, r3 */
/* @0xf9150 ldrsh r3, [r8, #6] */
/* @0xf9154 vstr s16, [sp, #12] */
/* @0xf9158 vstr s26, [sp, #16] */
/* @0xf915c vstr s20, [sp, #20] */
/* @0xf9160 str r11, [sp, #0x18] */
/* @0xf9164 vstr s27, [sp, #40] */
/* @0xf9168 str r10, [sp, #0x1c] */
/* @0xf916c str r9, [sp, #0x20] */
/* @0xf9170 str lr, [sp, #0x24] */
/* @0xf9174 vmul.f32 s13, s15, s23 */
/* @0xf9178 vmul.f32 s14, s22, s15 */
/* @0xf917c vmov.f32 s15, s18 */
/* @0xf9180 vmla.f32 s15, s13, s16 */
/* @0xf9184 vmov.f32 s13, s15 */
/* @0xf9188 vstr s13, [sp, #4] */
/* @0xf918c vmov.f32 s15, s19 */
/* @0xf9190 vmls.f32 s15, s14, s16 */
/* @0xf9194 vmov.f32 s14, s15 */
/* @0xf9198 vstr s14, [sp, #8] */
/* @0xf919c vmov s14, r2 */
/* @0xf91a0 vcvt.f32.s32 s15, s12 */
/* @0xf91a4 vmov s12, r1 */
/* @0xf91a8 vstr s15, [sp] */
/* @0xf91ac vmov s15, r3 */
/* @0xf91b0 vcvt.f32.s32 s12, s12 */
/* @0xf91b4 vcvt.f32.s32 s14, s14 */
/* @0xf91b8 vmov r1, s12 */
/* @0xf91bc vcvt.f32.s32 s15, s15 */
/* @0xf91c0 vmov r2, s14 */
/* @0xf91c4 vmov r3, s15 */
/* @0xf91c8 bl 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf> */
/* @0xf91cc ldrsh r8, [r8, #10] */
/* @0xf91d0 vmov s15, r8 */
/* @0xf91d4 vcvt.f32.s32 s15, s15 */
/* @0xf91d8 vmul.f32 s13, s15, s23 */
/* @0xf91dc vmul.f32 s14, s22, s15 */
/* @0xf91e0 vmla.f32 s18, s13, s16 */
/* @0xf91e4 vmls.f32 s19, s14, s16 */
/* @0xf91e8 vadd.f32 s17, s17, s15 */
/* @0xf91ec b 0xf9080 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x128> */
/* @0xf91f0 vcvt.f32.s32 s21, s25 */
/* @0xf91f4 vdiv.f32 s24, s20, s21 */
/* @0xf91f8 vmov r2, s24 */
/* @0xf91fc bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf9200 ldr r1, [sp, #0xa0] */
/* @0xf9204 mov r12, r0 */
/* @0xf9208 ldrsh r0, [r8, #10] */
/* @0xf920c str r12, [sp, #0x30] */
/* @0xf9210 vmov s15, r0 */
/* @0xf9214 mov r0, r11 */
/* @0xf9218 vcvt.f32.s32 s15, s15 */
/* @0xf921c vadd.f32 s15, s15, s20 */
/* @0xf9220 vdiv.f32 s15, s15, s21 */
/* @0xf9224 vmov r2, s15 */
/* @0xf9228 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf922c ldrsh r3, [r8, #10] */
/* @0xf9230 ldr r1, [sp, #0xa4] */
/* @0xf9234 vmov s15, r3 */
/* @0xf9238 vcvt.f32.s32 s15, s15 */
/* @0xf923c vadd.f32 s15, s15, s20 */
/* @0xf9240 vdiv.f32 s15, s15, s21 */
/* @0xf9244 str r0, [sp, #0x34] */
/* @0xf9248 ldr r0, [sp, #0xa8] */
/* @0xf924c vmov r2, s15 */
/* @0xf9250 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf9254 ldr r1, [sp, #0xa4] */
/* @0xf9258 vmov r2, s24 */
/* @0xf925c mov r10, r0 */
/* @0xf9260 ldr r0, [sp, #0xa8] */
/* @0xf9264 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0xf9268 ldrsh r3, [r8, #12] */
/* @0xf926c vmov.f32 s13, s18 */
/* @0xf9270 vldr s12, [r9, #28] */
/* @0xf9274 ldrsh r1, [r8, #6] */
/* @0xf9278 mov r2, #0 */
/* @0xf927c vmov s15, r3 */
/* @0xf9280 ldr r12, [sp, #0x30] */
/* @0xf9284 mov r3, r2 */
/* @0xf9288 vcvt.f32.s32 s15, s15 */
/* @0xf928c vmov.f32 s14, s19 */
/* @0xf9290 vmla.f32 s13, s15, s23 */
/* @0xf9294 vmls.f32 s14, s22, s15 */
/* @0xf9298 vcvt.f32.s32 s15, s12 */
/* @0xf929c vstr s15, [sp] */
/* @0xf92a0 vldr s15, [r9, #32] */
/* @0xf92a4 vcvt.f32.s32 s15, s15 */
/* @0xf92a8 str r0, [sp, #0x28] */
/* @0xf92ac ldr r0, [sp, #0x34] */
/* @0xf92b0 vstr s16, [sp, #16] */
/* @0xf92b4 str r12, [sp, #0x1c] */
/* @0xf92b8 vstr s26, [sp, #20] */
/* @0xf92bc str r10, [sp, #0x24] */
/* @0xf92c0 vstr s17, [sp, #24] */
/* @0xf92c4 str r0, [sp, #0x20] */
/* @0xf92c8 vstr s27, [sp, #44] */
/* @0xf92cc vstr s13, [sp, #8] */
/* @0xf92d0 vstr s14, [sp, #12] */
/* @0xf92d4 mov r0, r9 */
/* @0xf92d8 vstr s15, [sp, #4] */
/* @0xf92dc bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf> */
/* @0xf92e0 ldrsh r8, [r8, #10] */
/* @0xf92e4 vmov s15, r8 */
/* @0xf92e8 vcvt.f32.s32 s15, s15 */
/* @0xf92ec vmla.f32 s18, s15, s23 */
/* @0xf92f0 vmls.f32 s19, s22, s15 */
/* @0xf92f4 vadd.f32 s20, s20, s15 */
/* @0xf92f8 b 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc> */
/* @0xf92fc vstmialo lr, {s30, s31} */
/* @0xf9300 andeq r0, r0, r0 */
/* @0xf9304 ldrsh r0, [r8, #12] */
/* @0xf9308 ldrsh r3, [r8, #8] */
/* @0xf930c ldrsh r1, [r8, #2] */
/* @0xf9310 vmov s15, r0 */
/* @0xf9314 ldrsh r2, [r8, #4] */
/* @0xf9318 vmov s12, r3 */
/* @0xf931c ldrsh r3, [r8, #6] */
/* @0xf9320 vcvt.f32.s32 s15, s15 */
/* @0xf9324 vstr s16, [sp, #12] */
/* @0xf9328 vstr s26, [sp, #16] */
/* @0xf932c vstr s20, [sp, #20] */
/* @0xf9330 str r11, [sp, #0x18] */
/* @0xf9334 vstr s27, [sp, #40] */
/* @0xf9338 ldr r0, [r6, #0x38] */
/* @0xf933c str r10, [sp, #0x1c] */
/* @0xf9340 str r9, [sp, #0x20] */
/* @0xf9344 str lr, [sp, #0x24] */
/* @0xf9348 vmul.f32 s13, s15, s23 */
/* @0xf934c vmul.f32 s14, s22, s15 */
/* @0xf9350 vmov.f32 s15, s18 */
/* @0xf9354 vmla.f32 s15, s13, s16 */
/* @0xf9358 vmov.f32 s13, s15 */
/* @0xf935c vstr s13, [sp, #4] */
/* @0xf9360 vmov.f32 s15, s19 */
/* @0xf9364 vmls.f32 s15, s14, s16 */
/* @0xf9368 vmov.f32 s14, s15 */
/* @0xf936c vstr s14, [sp, #8] */
/* @0xf9370 vmov s14, r2 */
/* @0xf9374 vcvt.f32.s32 s15, s12 */
/* @0xf9378 vmov s12, r1 */
/* @0xf937c vstr s15, [sp] */
/* @0xf9380 vmov s15, r3 */
/* @0xf9384 vcvt.f32.s32 s12, s12 */
/* @0xf9388 vcvt.f32.s32 s14, s14 */
/* @0xf938c vmov r1, s12 */
/* @0xf9390 vcvt.f32.s32 s15, s15 */
/* @0xf9394 vmov r2, s14 */
/* @0xf9398 vmov r3, s15 */
/* @0xf939c bl 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf> */
/* @0xf93a0 b 0xf91cc <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x274> */

/* ── FUNC 0xf93a4 · CFontGM::TextHeight(unsigned short*) · size=8 · insn=2 */
/* @0xf93a4 ldr r0, [r0, #0x2c] */
/* @0xf93a8 bx lr */

/* ── FUNC 0xf93ac · CFontGM::Free() · size=28 · insn=7 */
/* @0xf93ac push {r3, lr} */
/* @0xf93b0 subs r3, r0, #0 */
/* @0xf93b4 popeq {r3, pc} */
/* @0xf93b8 ldr r3, [r3] */
/* @0xf93bc ldr r3, [r3, #0x4] */
/* @0xf93c0 blx r3 */
/* @0xf93c4 pop {r3, pc} */

/* ── FUNC 0xf93c8 · CFontGM::GetName() · size=8 · insn=2 */
/* @0xf93c8 ldr r0, [r0, #0x4] */
/* @0xf93cc bx lr */

/* ── FUNC 0xf93d0 · CFontGM::GetSize() · size=8 · insn=2 */
/* @0xf93d0 ldr r0, [r0, #0x8] */
/* @0xf93d4 bx lr */

/* ── FUNC 0xf93d8 · CFontGM::GetBold() · size=8 · insn=2 */
/* @0xf93d8 ldrb r0, [r0, #0xc] */
/* @0xf93dc bx lr */

/* ── FUNC 0xf93e0 · CFontGM::GetItalic() · size=8 · insn=2 */
/* @0xf93e0 ldrb r0, [r0, #0xd] */
/* @0xf93e4 bx lr */

/* ── FUNC 0xf93e8 · CFontGM::GetFirst() · size=8 · insn=2 */
/* @0xf93e8 ldr r0, [r0, #0x18] */
/* @0xf93ec bx lr */

/* ── FUNC 0xf93f0 · CFontGM::GetLast() · size=8 · insn=2 */
/* @0xf93f0 ldr r0, [r0, #0x1c] */
/* @0xf93f4 bx lr */

/* ── FUNC 0xf93f8 · CFontGM::CFont_Create() · size=28 · insn=7 */
/* @0xf93f8 push {r4, lr} */
/* @0xf93fc mov r0, #144 */
/* @0xf9400 bl 0x27c524 <_Znwj> */
/* @0xf9404 mov r4, r0 */
/* @0xf9408 bl 0xf71c8 <_ZN7CFontGMC2Ev> */
/* @0xf940c mov r0, r4 */
/* @0xf9410 pop {r4, pc} */

/* ── FUNC 0xf9414 · CFontGM::CFont_Free(void*) · size=12 · insn=3 */
/* @0xf9414 cmp r0, #0 */
/* @0xf9418 bxeq lr */
/* @0xf941c b 0xf93ac <_ZN7CFontGM4FreeEv> */

/* ── FUNC 0xf9420 · CFontGM::CFont_GetName(void*) · size=12 · insn=3 */
/* @0xf9420 cmp r0, #0 */
/* @0xf9424 bxeq lr */
/* @0xf9428 b 0xf93c8 <_ZN7CFontGM7GetNameEv> */

/* ── FUNC 0xf942c · CFontGM::CFont_GetSize(void*) · size=12 · insn=3 */
/* @0xf942c cmp r0, #0 */
/* @0xf9430 bxeq lr */
/* @0xf9434 b 0xf93d0 <_ZN7CFontGM7GetSizeEv> */

/* ── FUNC 0xf9438 · CFontGM::CFont_GetBold(void*) · size=28 · insn=7 */
/* @0xf9438 push {r3, lr} */
/* @0xf943c subs r3, r0, #0 */
/* @0xf9440 beq 0xf944c <_ZN7CFontGM13CFont_GetBoldEPv+0x14> */
/* @0xf9444 bl 0xf93d8 <_ZN7CFontGM7GetBoldEv> */
/* @0xf9448 pop {r3, pc} */
/* @0xf944c mov r0, r3 */
/* @0xf9450 pop {r3, pc} */

/* ── FUNC 0xf9454 · CFontGM::CFont_GetItalic(void*) · size=28 · insn=7 */
/* @0xf9454 push {r3, lr} */
/* @0xf9458 subs r3, r0, #0 */
/* @0xf945c beq 0xf9468 <_ZN7CFontGM15CFont_GetItalicEPv+0x14> */
/* @0xf9460 bl 0xf93e0 <_ZN7CFontGM9GetItalicEv> */
/* @0xf9464 pop {r3, pc} */
/* @0xf9468 mov r0, r3 */
/* @0xf946c pop {r3, pc} */

/* ── FUNC 0xf9470 · CFontGM::CFont_GetFirst(void*) · size=12 · insn=3 */
/* @0xf9470 cmp r0, #0 */
/* @0xf9474 bxeq lr */
/* @0xf9478 b 0xf93e8 <_ZN7CFontGM8GetFirstEv> */

/* ── FUNC 0xf947c · CFontGM::CFont_GetLast(void*) · size=12 · insn=3 */
/* @0xf947c cmp r0, #0 */
/* @0xf9480 bxeq lr */
/* @0xf9484 b 0xf93f0 <_ZN7CFontGM7GetLastEv> */

/* ── FUNC 0xf9488 · CFontGM::CFont_Clear(void*) · size=4 · insn=1 */
/* @0xf9488 bx lr */

/* ── FUNC 0xf948c · CFontGM::CFont_Assign(void*, void*) · size=20 · insn=5 */
/* @0xf948c cmp r0, #0 */
/* @0xf9490 bxeq lr */
/* @0xf9494 cmp r1, #0 */
/* @0xf9498 bxeq lr */
/* @0xf949c b 0xf7dfc <_ZN7CFontGM6AssignEPS_> */

/* ── FUNC 0xf94a0 · CFontGM::CFont_LoadFromStream(void*, void*) · size=44 · insn=11 */
/* @0xf94a0 subs r2, r0, #0 */
/* @0xf94a4 push {r3, lr} */
/* @0xf94a8 beq 0xf94c4 <_ZN7CFontGM20CFont_LoadFromStreamEPvS0_+0x24> */
/* @0xf94ac cmp r1, #0 */
/* @0xf94b0 beq 0xf94bc <_ZN7CFontGM20CFont_LoadFromStreamEPvS0_+0x1c> */
/* @0xf94b4 bl 0xf79a0 <_ZN7CFontGM14LoadFromStreamEP7CStream> */
/* @0xf94b8 pop {r3, pc} */
/* @0xf94bc mov r0, r1 */
/* @0xf94c0 pop {r3, pc} */
/* @0xf94c4 mov r0, r2 */
/* @0xf94c8 pop {r3, pc} */

/* ── FUNC 0xf94cc · CFontGM::CFont_InitTexture(void*) · size=12 · insn=3 */
/* @0xf94cc cmp r0, #0 */
/* @0xf94d0 bxeq lr */
/* @0xf94d4 b 0xf7db4 <_ZN7CFontGM11InitTextureEv> */

/* ── FUNC 0xf94d8 · CFontGM::CFont_FreeTexture(void*) · size=12 · insn=3 */
/* @0xf94d8 cmp r0, #0 */
/* @0xf94dc bxeq lr */
/* @0xf94e0 b 0xf707c <_ZN7CFontGM11FreeTextureEv> */

/* ── FUNC 0xf94e4 · CFontGM::GetTexture() · size=20 · insn=5 */
/* @0xf94e4 ldr r3, [r0, #0x3c] */
/* @0xf94e8 cmp r3, #0 */
/* @0xf94ec movne r0, r3 */
/* @0xf94f0 ldreq r0, [r0, #0x38] */
/* @0xf94f4 bx lr */

/* ── FUNC 0xf94f8 · CFontGM::CFont_Draw_String(void*, float, float, unsigned short*, unsigned int, float) · size=28 · insn=7 */
/* @0xf94f8 cmp r0, #0 */
/* @0xf94fc str r4, [sp, #-0x4]! */
/* @0xf9500 beq 0xf950c <_ZN7CFontGM17CFont_Draw_StringEPvffPtjf+0x14> */
/* @0xf9504 ldr r4, [sp], #4 */
/* @0xf9508 b 0xf7eec <_ZN7CFontGM11Draw_StringEffPtjf> */
/* @0xf950c ldr r4, [sp], #4 */
/* @0xf9510 bx lr */

/* ── FUNC 0xf9514 · CFontGM::CFont_Draw_String_Transformed(void*, float, float, unsigned short*, float, float, float, unsigned int, float) · size=28 · insn=7 */
/* @0xf9514 cmp r0, #0 */
/* @0xf9518 push {r4, r5, r6, r7} */
/* @0xf951c beq 0xf9528 <_ZN7CFontGM29CFont_Draw_String_TransformedEPvffPtfffjf+0x14> */
/* @0xf9520 pop {r4, r5, r6, r7} */
/* @0xf9524 b 0xf830c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf> */
/* @0xf9528 pop {r4, r5, r6, r7} */
/* @0xf952c bx lr */

/* ── FUNC 0xf9530 · CFontGM::CFont_Draw_String_Color(void*, float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=28 · insn=7 */
/* @0xf9530 cmp r0, #0 */
/* @0xf9534 push {r4, r5, r6, r7} */
/* @0xf9538 beq 0xf9544 <_ZN7CFontGM23CFont_Draw_String_ColorEPvffPtjjjjf+0x14> */
/* @0xf953c pop {r4, r5, r6, r7} */
/* @0xf9540 b 0xf8b58 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf> */
/* @0xf9544 pop {r4, r5, r6, r7} */
/* @0xf9548 bx lr */
