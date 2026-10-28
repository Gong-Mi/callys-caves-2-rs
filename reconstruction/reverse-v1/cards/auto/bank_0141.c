/* libyoyo.so 覆盖卡组 0141
 * 函数 0x1a8b50..0x1ab144，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a8b50 · TBitmap::TBitmap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a8b8c · BitmapLoader::Create(int) · size=140 · insn=35 */
/* @0x1a8b8c ldr r3, [r0, #0x8] */
/* @0x1a8b90 push {r4, r5, r6, lr} */
/* @0x1a8b94 cmp r3, r1 */
/* @0x1a8b98 mov r4, r0 */
/* @0x1a8b9c movle r4, #0 */
/* @0x1a8ba0 ble 0x1a8c0c <_ZN12BitmapLoader6CreateEi+0x80> */
/* @0x1a8ba4 ldr r0, [r4, #0x4] */
/* @0x1a8ba8 mov r3, #0 */
/* @0x1a8bac ldr r1, [pc, #0x60] */
/* @0x1a8bb0 mov r2, #396 */
/* @0x1a8bb4 ldr r12, [r0, #0x10] */
/* @0x1a8bb8 add r1, pc, r1 */
/* @0x1a8bbc ldr r5, [r0, #0x14] */
/* @0x1a8bc0 mul r5, r5, r12 */
/* @0x1a8bc4 lsl r5, r5, #2 */
/* @0x1a8bc8 add r5, r5, #52 */
/* @0x1a8bcc mov r0, r5 */
/* @0x1a8bd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a8bd4 ldr r1, [r4, #0x4] */
/* @0x1a8bd8 mov r2, r5 */
/* @0x1a8bdc mov r6, r0 */
/* @0x1a8be0 bl 0xb65bc <memcpy@plt> */
/* @0x1a8be4 mov r0, #44 */
/* @0x1a8be8 bl 0x27c524 <_Znwj> */
/* @0x1a8bec mov r4, r0 */
/* @0x1a8bf0 bl 0x1a8b50 <_ZN7TBitmapC2Ev> */
/* @0x1a8bf4 ldr r3, [r4] */
/* @0x1a8bf8 mov r2, r5 */
/* @0x1a8bfc mov r1, r6 */
/* @0x1a8c00 mov r0, r4 */
/* @0x1a8c04 ldr r3, [r3, #0x38] */
/* @0x1a8c08 blx r3 */
/* @0x1a8c0c mov r0, r4 */
/* @0x1a8c10 pop {r4, r5, r6, pc} */
/* @0x1a8c14 ldrheq r4, [r10], -r12 */

/* ── FUNC 0x1a8c18 · TBitmap::TBitmap(Gdiplus::Bitmap*) · size=36 · insn=9 */
/* @0x1a8c18 ldr r2, [pc, #0x18] */
/* @0x1a8c1c mvn r1, #0 */
/* @0x1a8c20 str r1, [r0, #0x24] */
/* @0x1a8c24 ldr r2, [pc, r2] */
/* @0x1a8c28 str r1, [r0, #0x28] */
/* @0x1a8c2c add r2, r2, #8 */
/* @0x1a8c30 str r2, [r0] */
/* @0x1a8c34 bx lr */
/* @0x1a8c38 .word 0x00247bdc */

/* ── FUNC 0x1a8c18 · TBitmap::TBitmap(Gdiplus::Bitmap*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a8c3c · TBitmap::Create() · size=156 · insn=39 */
/* @0x1a8c3c ldr r3, [r0, #0x14] */
/* @0x1a8c40 sub r3, r3, #1 */
/* @0x1a8c44 cmp r3, #6 */
/* @0x1a8c48 addls pc, pc, r3, lsl #2 */
/* @0x1a8c4c b 0x1a8c7c <_ZN7TBitmap6CreateEv+0x40> */
/* @0x1a8c50 b 0x1a8cbc <_ZN7TBitmap6CreateEv+0x80> */
/* @0x1a8c54 b 0x1a8c9c <_ZN7TBitmap6CreateEv+0x60> */
/* @0x1a8c58 b 0x1a8cb0 <_ZN7TBitmap6CreateEv+0x74> */
/* @0x1a8c5c b 0x1a8c6c <_ZN7TBitmap6CreateEv+0x30> */
/* @0x1a8c60 b 0x1a8c6c <_ZN7TBitmap6CreateEv+0x30> */
/* @0x1a8c64 b 0x1a8c8c <_ZN7TBitmap6CreateEv+0x50> */
/* @0x1a8c68 b 0x1a8c7c <_ZN7TBitmap6CreateEv+0x40> */
/* @0x1a8c6c ldr r3, [r0, #0x18] */
/* @0x1a8c70 lsl r3, r3, #1 */
/* @0x1a8c74 str r3, [r0, #0x20] */
/* @0x1a8c78 bx lr */
/* @0x1a8c7c ldr r3, [r0, #0x18] */
/* @0x1a8c80 lsl r3, r3, #2 */
/* @0x1a8c84 str r3, [r0, #0x20] */
/* @0x1a8c88 bx lr */
/* @0x1a8c8c ldr r3, [r0, #0x18] */
/* @0x1a8c90 add r3, r3, r3, lsl #1 */
/* @0x1a8c94 str r3, [r0, #0x20] */
/* @0x1a8c98 bx lr */
/* @0x1a8c9c ldr r3, [r0, #0x18] */
/* @0x1a8ca0 add r3, r3, r3, lsr #31 */
/* @0x1a8ca4 asr r3, r3, #1 */
/* @0x1a8ca8 str r3, [r0, #0x20] */
/* @0x1a8cac bx lr */
/* @0x1a8cb0 ldr r3, [r0, #0x18] */
/* @0x1a8cb4 str r3, [r0, #0x20] */
/* @0x1a8cb8 bx lr */
/* @0x1a8cbc ldr r3, [r0, #0x18] */
/* @0x1a8cc0 add r2, r3, #7 */
/* @0x1a8cc4 cmp r3, #0 */
/* @0x1a8cc8 movlt r3, r2 */
/* @0x1a8ccc asr r3, r3, #3 */
/* @0x1a8cd0 str r3, [r0, #0x20] */
/* @0x1a8cd4 bx lr */

/* ── FUNC 0x1a8cd8 · TBitmap::SetPixelFormat(TPixelFormat) · size=20 · insn=5 */
/* @0x1a8cd8 ldr r2, [r0, #0x28] */
/* @0x1a8cdc str r1, [r0, #0x14] */
/* @0x1a8ce0 add r2, r2, #1 */
/* @0x1a8ce4 str r2, [r0, #0x28] */
/* @0x1a8ce8 b 0x1a8c3c <_ZN7TBitmap6CreateEv> */

/* ── FUNC 0x1a8cec · TBitmap::SetHeight(int) · size=20 · insn=5 */
/* @0x1a8cec ldr r2, [r0, #0x28] */
/* @0x1a8cf0 str r1, [r0, #0x1c] */
/* @0x1a8cf4 add r2, r2, #1 */
/* @0x1a8cf8 str r2, [r0, #0x28] */
/* @0x1a8cfc b 0x1a8c3c <_ZN7TBitmap6CreateEv> */

/* ── FUNC 0x1a8d00 · TBitmap::SetWidth(int) · size=20 · insn=5 */
/* @0x1a8d00 ldr r2, [r0, #0x28] */
/* @0x1a8d04 str r1, [r0, #0x18] */
/* @0x1a8d08 add r2, r2, #1 */
/* @0x1a8d0c str r2, [r0, #0x28] */
/* @0x1a8d10 b 0x1a8c3c <_ZN7TBitmap6CreateEv> */

/* ── FUNC 0x1a8d14 · TBitmap::Setup() · size=208 · insn=52 */
/* @0x1a8d14 ldr r3, [r0, #0x4] */
/* @0x1a8d18 push {r4, lr} */
/* @0x1a8d1c mov r4, r0 */
/* @0x1a8d20 ldr r12, [r3, #0x8] */
/* @0x1a8d24 ldr r1, [r3, #0x10] */
/* @0x1a8d28 ldr r2, [r3, #0x14] */
/* @0x1a8d2c sub r12, r12, #2 */
/* @0x1a8d30 ldrh r0, [r3, #26] */
/* @0x1a8d34 add r12, r3, r12 */
/* @0x1a8d38 str r1, [r4, #0x18] */
/* @0x1a8d3c str r12, [r4, #0xc] */
/* @0x1a8d40 str r2, [r4, #0x1c] */
/* @0x1a8d44 bl 0x1a8b28 <_Z15GetTPixelFormati> */
/* @0x1a8d48 sub r3, r0, #1 */
/* @0x1a8d4c str r0, [r4, #0x14] */
/* @0x1a8d50 cmp r3, #6 */
/* @0x1a8d54 addls pc, pc, r3, lsl #2 */
/* @0x1a8d58 b 0x1a8d84 <_ZN7TBitmap5SetupEv+0x70> */
/* @0x1a8d5c b 0x1a8da8 <_ZN7TBitmap5SetupEv+0x94> */
/* @0x1a8d60 b 0x1a8dc4 <_ZN7TBitmap5SetupEv+0xb0> */
/* @0x1a8d64 b 0x1a8dd8 <_ZN7TBitmap5SetupEv+0xc4> */
/* @0x1a8d68 b 0x1a8d88 <_ZN7TBitmap5SetupEv+0x74> */
/* @0x1a8d6c b 0x1a8d88 <_ZN7TBitmap5SetupEv+0x74> */
/* @0x1a8d70 b 0x1a8d98 <_ZN7TBitmap5SetupEv+0x84> */
/* @0x1a8d74 b 0x1a8d78 <_ZN7TBitmap5SetupEv+0x64> */
/* @0x1a8d78 ldr r3, [r4, #0x18] */
/* @0x1a8d7c lsl r3, r3, #2 */
/* @0x1a8d80 str r3, [r4, #0x20] */
/* @0x1a8d84 pop {r4, pc} */
/* @0x1a8d88 ldr r3, [r4, #0x18] */
/* @0x1a8d8c lsl r3, r3, #1 */
/* @0x1a8d90 str r3, [r4, #0x20] */
/* @0x1a8d94 pop {r4, pc} */
/* @0x1a8d98 ldr r3, [r4, #0x18] */
/* @0x1a8d9c add r3, r3, r3, lsl #1 */
/* @0x1a8da0 str r3, [r4, #0x20] */
/* @0x1a8da4 pop {r4, pc} */
/* @0x1a8da8 ldr r3, [r4, #0x18] */
/* @0x1a8dac add r2, r3, #7 */
/* @0x1a8db0 cmp r3, #0 */
/* @0x1a8db4 movlt r3, r2 */
/* @0x1a8db8 asr r3, r3, #3 */
/* @0x1a8dbc str r3, [r4, #0x20] */
/* @0x1a8dc0 pop {r4, pc} */
/* @0x1a8dc4 ldr r3, [r4, #0x18] */
/* @0x1a8dc8 add r3, r3, r3, lsr #31 */
/* @0x1a8dcc asr r3, r3, #1 */
/* @0x1a8dd0 str r3, [r4, #0x20] */
/* @0x1a8dd4 pop {r4, pc} */
/* @0x1a8dd8 ldr r3, [r4, #0x18] */
/* @0x1a8ddc str r3, [r4, #0x20] */
/* @0x1a8de0 pop {r4, pc} */

/* ── FUNC 0x1a8de4 · TBitmap::ReadDIB(CStream*, int) · size=552 · insn=138 */
/* @0x1a8de4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a8de8 mov r5, r0 */
/* @0x1a8dec mov r0, r1 */
/* @0x1a8df0 mov r4, r1 */
/* @0x1a8df4 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x1a8df8 ldr r1, [pc, #0x204] */
/* @0x1a8dfc mov r2, #129 */
/* @0x1a8e00 mov r3, #1 */
/* @0x1a8e04 add r1, pc, r1 */
/* @0x1a8e08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a8e0c str r0, [r5, #0x4] */
/* @0x1a8e10 mov r0, r4 */
/* @0x1a8e14 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x1a8e18 mov r1, #0 */
/* @0x1a8e1c mov r2, r1 */
/* @0x1a8e20 sub r3, r0, #2 */
/* @0x1a8e24 mov r0, r4 */
/* @0x1a8e28 str r3, [r5, #0x10] */
/* @0x1a8e2c bl 0x201284 <_ZN7CStream4SeekEis> */
/* @0x1a8e30 ldr r1, [r5, #0x4] */
/* @0x1a8e34 mov r2, #2 */
/* @0x1a8e38 mov r0, r4 */
/* @0x1a8e3c bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x1a8e40 mov r0, r4 */
/* @0x1a8e44 ldr r6, [r5, #0x4] */
/* @0x1a8e48 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x1a8e4c mov r1, r6 */
/* @0x1a8e50 sub r2, r0, #2 */
/* @0x1a8e54 mov r0, r4 */
/* @0x1a8e58 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x1a8e5c mov r0, r5 */
/* @0x1a8e60 bl 0x1a8d14 <_ZN7TBitmap5SetupEv> */
/* @0x1a8e64 ldr r3, [r5, #0x20] */
/* @0x1a8e68 ldr r2, [r5, #0x1c] */
/* @0x1a8e6c mov r0, r4 */
/* @0x1a8e70 ldr r1, [r5, #0xc] */
/* @0x1a8e74 mul r2, r2, r3 */
/* @0x1a8e78 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x1a8e7c ldr r0, [r5, #0x1c] */
/* @0x1a8e80 sub r0, r0, #1 */
/* @0x1a8e84 cmp r0, #0 */
/* @0x1a8e88 ldrgt r2, [r5, #0x20] */
/* @0x1a8e8c movgt r6, #0 */
/* @0x1a8e90 ble 0x1a8edc <_ZN7TBitmap7ReadDIBEP7CStreami+0xf8> */
/* @0x1a8e94 ldr r12, [r5, #0xc] */
/* @0x1a8e98 cmp r2, #0 */
/* @0x1a8e9c movgt r3, #0 */
/* @0x1a8ea0 mla r1, r6, r2, r12 */
/* @0x1a8ea4 mla r12, r2, r0, r12 */
/* @0x1a8ea8 ble 0x1a8ecc <_ZN7TBitmap7ReadDIBEP7CStreami+0xe8> */
/* @0x1a8eac ldrb r2, [r1, r3] */
/* @0x1a8eb0 ldrb r4, [r12, r3] */
/* @0x1a8eb4 strb r4, [r1, r3] */
/* @0x1a8eb8 strb r2, [r12, r3] */
/* @0x1a8ebc add r3, r3, #1 */
/* @0x1a8ec0 ldr r2, [r5, #0x20] */
/* @0x1a8ec4 cmp r2, r3 */
/* @0x1a8ec8 bgt 0x1a8eac <_ZN7TBitmap7ReadDIBEP7CStreami+0xc8> */
/* @0x1a8ecc add r6, r6, #1 */
/* @0x1a8ed0 sub r0, r0, #1 */
/* @0x1a8ed4 cmp r6, r0 */
/* @0x1a8ed8 blt 0x1a8e94 <_ZN7TBitmap7ReadDIBEP7CStreami+0xb0> */
/* @0x1a8edc ldr r3, [r5, #0x14] */
/* @0x1a8ee0 cmp r3, #3 */
/* @0x1a8ee4 popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a8ee8 ldr r0, [r5, #0x18] */
/* @0x1a8eec mov r2, #158 */
/* @0x1a8ef0 ldr r12, [r5, #0x1c] */
/* @0x1a8ef4 mov r3, #1 */
/* @0x1a8ef8 ldr r1, [pc, #0x108] */
/* @0x1a8efc mul r0, r12, r0 */
/* @0x1a8f00 add r1, pc, r1 */
/* @0x1a8f04 lsl r0, r0, #2 */
/* @0x1a8f08 add r0, r0, #52 */
/* @0x1a8f0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a8f10 ldr r3, [r5, #0x4] */
/* @0x1a8f14 add r1, r3, #48 */
/* @0x1a8f18 mov r8, r0 */
/* @0x1a8f1c mov r2, r0 */
/* @0x1a8f20 ldr r4, [r3] */
/* @0x1a8f24 add r3, r3, #16 */
/* @0x1a8f28 ldr lr, [r3, #-0xc] */
/* @0x1a8f2c add r2, r2, #16 */
/* @0x1a8f30 ldr r12, [r3, #-0x8] */
/* @0x1a8f34 ldr r0, [r3, #-0x4] */
/* @0x1a8f38 cmp r3, r1 */
/* @0x1a8f3c str r4, [r2, #-0x10] */
/* @0x1a8f40 str lr, [r2, #-0xc] */
/* @0x1a8f44 str r12, [r2, #-0x8] */
/* @0x1a8f48 str r0, [r2, #-0x4] */
/* @0x1a8f4c bne 0x1a8f20 <_ZN7TBitmap7ReadDIBEP7CStreami+0x13c> */
/* @0x1a8f50 ldr r0, [r3] */
/* @0x1a8f54 mov r1, #32 */
/* @0x1a8f58 mov r3, #52 */
/* @0x1a8f5c add r9, r8, r3 */
/* @0x1a8f60 str r0, [r2] */
/* @0x1a8f64 ldr r2, [r5, #0x18] */
/* @0x1a8f68 ldr r6, [r5, #0x1c] */
/* @0x1a8f6c ldr r0, [r5, #0x4] */
/* @0x1a8f70 strh r1, [r8, #26] */
/* @0x1a8f74 mul r6, r6, r2 */
/* @0x1a8f78 add r12, r0, r3 */
/* @0x1a8f7c str r3, [r8, #0x8] */
/* @0x1a8f80 cmp r6, #0 */
/* @0x1a8f84 ble 0x1a8fd4 <_ZN7TBitmap7ReadDIBEP7CStreami+0x1f0> */
/* @0x1a8f88 ldr r2, [r5, #0xc] */
/* @0x1a8f8c add lr, r8, #48 */
/* @0x1a8f90 mov r1, #3 */
/* @0x1a8f94 mov r7, #1 */
/* @0x1a8f98 add r6, r2, r6 */
/* @0x1a8f9c mov r4, #2 */
/* @0x1a8fa0 ldrb r3, [r2], #1 */
/* @0x1a8fa4 cmp r2, r6 */
/* @0x1a8fa8 smlabb r11, r1, r3, r7 */
/* @0x1a8fac smlabb r10, r1, r3, r4 */
/* @0x1a8fb0 smulbb r3, r3, r1 */
/* @0x1a8fb4 ldrb r11, [r12, r11] */
/* @0x1a8fb8 ldrb r10, [r12, r10] */
/* @0x1a8fbc ldrb r3, [r12, r3] */
/* @0x1a8fc0 orr r10, r11, r10 */
/* @0x1a8fc4 orr r3, r10, r3 */
/* @0x1a8fc8 orr r3, r3, #-16777216 */
/* @0x1a8fcc str r3, [lr, #0x4]! */
/* @0x1a8fd0 bne 0x1a8fa0 <_ZN7TBitmap7ReadDIBEP7CStreami+0x1bc> */
/* @0x1a8fd4 str r9, [r5, #0xc] */
/* @0x1a8fd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a8fdc ldr r3, [r5, #0x18] */
/* @0x1a8fe0 ldr r2, [r5, #0x1c] */
/* @0x1a8fe4 mov r1, #7 */
/* @0x1a8fe8 str r8, [r5, #0x4] */
/* @0x1a8fec str r1, [r5, #0x14] */
/* @0x1a8ff0 mul r3, r2, r3 */
/* @0x1a8ff4 lsl r3, r3, #2 */
/* @0x1a8ff8 add r3, r3, #52 */
/* @0x1a8ffc str r3, [r5, #0x10] */
/* @0x1a9000 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a9004 andseq r4, r10, r0, ror r3 */
/* @0x1a9008 andseq r4, r10, r4, ror r2 */

/* ── FUNC 0x1a900c · TBitmap::LoadFromStream(CStream*) · size=116 · insn=29 */
/* @0x1a900c ldr r3, [r0] */
/* @0x1a9010 push {r4, r5, r6, lr} */
/* @0x1a9014 mov r4, r1 */
/* @0x1a9018 sub sp, sp, #8 */
/* @0x1a901c ldr r3, [r3, #0x30] */
/* @0x1a9020 mov r5, r0 */
/* @0x1a9024 blx r3 */
/* @0x1a9028 mov r0, r4 */
/* @0x1a902c bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x1a9030 mov r6, r0 */
/* @0x1a9034 mov r0, r4 */
/* @0x1a9038 bl 0x201160 <_ZN7CStream11GetPositionEv> */
/* @0x1a903c cmp r6, r0 */
/* @0x1a9040 beq 0x1a9064 <_ZN7TBitmap14LoadFromStreamEP7CStream+0x58> */
/* @0x1a9044 mov r2, #2 */
/* @0x1a9048 mov r0, r4 */
/* @0x1a904c add r1, sp, #6 */
/* @0x1a9050 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x1a9054 ldrh r2, [sp, #6] */
/* @0x1a9058 movw r3, #0x4d42 */
/* @0x1a905c cmp r2, r3 */
/* @0x1a9060 beq 0x1a906c <_ZN7TBitmap14LoadFromStreamEP7CStream+0x60> */
/* @0x1a9064 add sp, sp, #8 */
/* @0x1a9068 pop {r4, r5, r6, pc} */
/* @0x1a906c mov r0, r5 */
/* @0x1a9070 mov r1, r4 */
/* @0x1a9074 mov r2, #0 */
/* @0x1a9078 bl 0x1a8de4 <_ZN7TBitmap7ReadDIBEP7CStreami> */
/* @0x1a907c b 0x1a9064 <_ZN7TBitmap14LoadFromStreamEP7CStream+0x58> */

/* ── FUNC 0x1a9080 · TBitmap::FromBitmap(IBitmap*) · size=172 · insn=43 */
/* @0x1a9080 push {r3, r4, r5, lr} */
/* @0x1a9084 mov r5, r1 */
/* @0x1a9088 ldr r3, [r0] */
/* @0x1a908c mov r4, r0 */
/* @0x1a9090 ldr r3, [r3, #0x30] */
/* @0x1a9094 blx r3 */
/* @0x1a9098 ldr r3, [r5] */
/* @0x1a909c mov r0, r5 */
/* @0x1a90a0 ldr r3, [r3, #0x10] */
/* @0x1a90a4 blx r3 */
/* @0x1a90a8 ldr r3, [r5] */
/* @0x1a90ac ldr r3, [r3, #0x18] */
/* @0x1a90b0 str r0, [r4, #0x18] */
/* @0x1a90b4 mov r0, r5 */
/* @0x1a90b8 blx r3 */
/* @0x1a90bc ldr r3, [r5, #0x4] */
/* @0x1a90c0 cmp r3, #0 */
/* @0x1a90c4 streq r3, [r4, #0x4] */
/* @0x1a90c8 str r0, [r4, #0x1c] */
/* @0x1a90cc beq 0x1a9118 <_ZN7TBitmap10FromBitmapEP7IBitmap+0x98> */
/* @0x1a90d0 ldr r0, [r5, #0x10] */
/* @0x1a90d4 mov r3, #1 */
/* @0x1a90d8 ldr r1, [pc, #0x48] */
/* @0x1a90dc movw r2, #0x116 */
/* @0x1a90e0 add r1, pc, r1 */
/* @0x1a90e4 str r0, [r4, #0x10] */
/* @0x1a90e8 ldr r0, [r5, #0x10] */
/* @0x1a90ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a90f0 str r0, [r4, #0x4] */
/* @0x1a90f4 ldr r2, [r5, #0x10] */
/* @0x1a90f8 ldr r1, [r5, #0x4] */
/* @0x1a90fc bl 0xb65bc <memcpy@plt> */
/* @0x1a9100 ldr r3, [r4, #0x4] */
/* @0x1a9104 mov r0, r4 */
/* @0x1a9108 ldr r2, [r3, #0x8] */
/* @0x1a910c add r3, r3, r2 */
/* @0x1a9110 str r3, [r4, #0xc] */
/* @0x1a9114 bl 0x1a8d14 <_ZN7TBitmap5SetupEv> */
/* @0x1a9118 ldr r3, [r4, #0x28] */
/* @0x1a911c add r3, r3, #1 */
/* @0x1a9120 str r3, [r4, #0x28] */
/* @0x1a9124 pop {r3, r4, r5, pc} */
/* @0x1a9128 mulseq r10, r4, r0 */

/* ── FUNC 0x1a912c · IBitmap::Create() · size=28 · insn=7 */
/* @0x1a912c push {r4, lr} */
/* @0x1a9130 mov r0, #44 */
/* @0x1a9134 bl 0x27c524 <_Znwj> */
/* @0x1a9138 mov r4, r0 */
/* @0x1a913c bl 0x1a8b50 <_ZN7TBitmapC2Ev> */
/* @0x1a9140 mov r0, r4 */
/* @0x1a9144 pop {r4, pc} */

/* ── FUNC 0x1a9148 · BitmapLoader::BitmapLoader(char const*) · size=36 · insn=9 */
/* @0x1a9148 ldr r2, [pc, #0x18] */
/* @0x1a914c mov r1, #0 */
/* @0x1a9150 str r1, [r0, #0x8] */
/* @0x1a9154 ldr r2, [pc, r2] */
/* @0x1a9158 str r1, [r0, #0xc] */
/* @0x1a915c add r2, r2, #8 */
/* @0x1a9160 str r2, [r0] */
/* @0x1a9164 bx lr */
/* @0x1a9168 .word 0x002476b0 */

/* ── FUNC 0x1a9148 · BitmapLoader::BitmapLoader(char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a916c · BitmapLoader::BitmapLoader(void*, int, int) · size=172 · insn=43 */
/* @0x1a916c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1a9170 mov r10, r1 */
/* @0x1a9174 mul r9, r3, r2 */
/* @0x1a9178 ldr r12, [pc, #0x90] */
/* @0x1a917c ldr r1, [pc, #0x90] */
/* @0x1a9180 mov r4, r0 */
/* @0x1a9184 mov r5, #0 */
/* @0x1a9188 ldr r12, [pc, r12] */
/* @0x1a918c str r5, [r0, #0xc] */
/* @0x1a9190 mov r6, #1 */
/* @0x1a9194 str r5, [r0, #0x8] */
/* @0x1a9198 mov r8, r2 */
/* @0x1a919c lsl r9, r9, #2 */
/* @0x1a91a0 mov r7, r3 */
/* @0x1a91a4 add r12, r12, #8 */
/* @0x1a91a8 mov r3, r5 */
/* @0x1a91ac str r12, [r0] */
/* @0x1a91b0 add r1, pc, r1 */
/* @0x1a91b4 add r0, r9, #52 */
/* @0x1a91b8 str r6, [r4, #0x10] */
/* @0x1a91bc movw r2, #0x169 */
/* @0x1a91c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a91c4 mov r3, #52 */
/* @0x1a91c8 mov lr, #32 */
/* @0x1a91cc mov r2, r9 */
/* @0x1a91d0 mov r1, r10 */
/* @0x1a91d4 mov r12, r0 */
/* @0x1a91d8 str r0, [r4, #0x4] */
/* @0x1a91dc str r8, [r0, #0x10] */
/* @0x1a91e0 str r7, [r0, #0x14] */
/* @0x1a91e4 mov r0, #40 */
/* @0x1a91e8 str r5, [r12, #0x1c] */
/* @0x1a91ec str r0, [r12, #0xc] */
/* @0x1a91f0 add r0, r12, r3 */
/* @0x1a91f4 strh r6, [r12, #24] */
/* @0x1a91f8 strh lr, [r12, #26] */
/* @0x1a91fc str r3, [r12, #0x8] */
/* @0x1a9200 bl 0xb65bc <memcpy@plt> */
/* @0x1a9204 str r6, [r4, #0x8] */
/* @0x1a9208 mov r0, r4 */
/* @0x1a920c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1a9210 eoreq r7, r4, r12, ror r6 */
/* @0x1a9214 andseq r3, r10, r4, asr #31 */

/* ── FUNC 0x1a916c · BitmapLoader::BitmapLoader(void*, int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a9218 · BitmapLoader::BitmapLoader(void*, int) · size=36 · insn=9 */
/* @0x1a9218 ldr r2, [pc, #0x18] */
/* @0x1a921c mov r1, #0 */
/* @0x1a9220 str r1, [r0, #0x8] */
/* @0x1a9224 ldr r2, [pc, r2] */
/* @0x1a9228 str r1, [r0, #0xc] */
/* @0x1a922c add r2, r2, #8 */
/* @0x1a9230 str r2, [r0] */
/* @0x1a9234 bx lr */
/* @0x1a9238 eoreq r7, r4, r0, ror #11 */

/* ── FUNC 0x1a9218 · BitmapLoader::BitmapLoader(void*, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1a923c · IBitmapLoader::Create(char const*) · size=36 · insn=9 */
/* @0x1a923c push {r3, r4, r5, lr} */
/* @0x1a9240 mov r5, r0 */
/* @0x1a9244 mov r0, #20 */
/* @0x1a9248 bl 0x27c524 <_Znwj> */
/* @0x1a924c mov r1, r5 */
/* @0x1a9250 mov r4, r0 */
/* @0x1a9254 bl 0x1a9148 <_ZN12BitmapLoaderC2EPKc> */
/* @0x1a9258 mov r0, r4 */
/* @0x1a925c pop {r3, r4, r5, pc} */

/* ── FUNC 0x1a9260 · IBitmapLoader::Create(void*, int) · size=44 · insn=11 */
/* @0x1a9260 push {r4, r5, r6, lr} */
/* @0x1a9264 mov r6, r0 */
/* @0x1a9268 mov r0, #20 */
/* @0x1a926c mov r5, r1 */
/* @0x1a9270 bl 0x27c524 <_Znwj> */
/* @0x1a9274 mov r1, r6 */
/* @0x1a9278 mov r2, r5 */
/* @0x1a927c mov r4, r0 */
/* @0x1a9280 bl 0x1a9218 <_ZN12BitmapLoaderC2EPvi> */
/* @0x1a9284 mov r0, r4 */
/* @0x1a9288 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1a928c · IBitmapLoader::Create(void*, int, int) · size=52 · insn=13 */
/* @0x1a928c push {r3, r4, r5, r6, r7, lr} */
/* @0x1a9290 mov r7, r0 */
/* @0x1a9294 mov r0, #20 */
/* @0x1a9298 mov r6, r1 */
/* @0x1a929c mov r5, r2 */
/* @0x1a92a0 bl 0x27c524 <_Znwj> */
/* @0x1a92a4 mov r1, r7 */
/* @0x1a92a8 mov r2, r6 */
/* @0x1a92ac mov r3, r5 */
/* @0x1a92b0 mov r4, r0 */
/* @0x1a92b4 bl 0x1a916c <_ZN12BitmapLoaderC2EPvii> */
/* @0x1a92b8 mov r0, r4 */
/* @0x1a92bc pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1a92c0 · CRoom::CreateWADStorage() · size=200 · insn=50 */
/* @0x1a92c0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a92c4 mov r3, #1 */
/* @0x1a92c8 ldr r7, [pc, #0xb4] */
/* @0x1a92cc mov r6, r0 */
/* @0x1a92d0 mov r2, #111 */
/* @0x1a92d4 mov r0, #96 */
/* @0x1a92d8 add r7, pc, r7 */
/* @0x1a92dc mov r4, #0 */
/* @0x1a92e0 mov r8, #88 */
/* @0x1a92e4 mov r1, r7 */
/* @0x1a92e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a92ec mov r2, r8 */
/* @0x1a92f0 mov r1, r4 */
/* @0x1a92f4 str r0, [r6, #0xac] */
/* @0x1a92f8 bl 0xb65b0 <memset@plt> */
/* @0x1a92fc ldr r5, [r6, #0xac] */
/* @0x1a9300 mov lr, #92 */
/* @0x1a9304 mov r12, #30 */
/* @0x1a9308 mov r1, r7 */
/* @0x1a930c mov r2, #121 */
/* @0x1a9310 str r5, [r6, #0xb0] */
/* @0x1a9314 mov r3, #1 */
/* @0x1a9318 str lr, [r5, #0x34] */
/* @0x1a931c mov r0, #4 */
/* @0x1a9320 str r12, [r5, #0x10] */
/* @0x1a9324 str r8, [r5, #0x30] */
/* @0x1a9328 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a932c mov r1, r7 */
/* @0x1a9330 mov r2, #124 */
/* @0x1a9334 mov r3, r0 */
/* @0x1a9338 str r0, [r5, #0x58] */
/* @0x1a933c strb r4, [r3], #1 */
/* @0x1a9340 add r3, r3, #1 */
/* @0x1a9344 strb r4, [r0, #0x1] */
/* @0x1a9348 mov r0, #4 */
/* @0x1a934c strb r4, [r3], #1 */
/* @0x1a9350 strb r4, [r3] */
/* @0x1a9354 mov r3, #1 */
/* @0x1a9358 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a935c mov r3, r0 */
/* @0x1a9360 str r0, [r5, #0x5c] */
/* @0x1a9364 strb r4, [r3], #1 */
/* @0x1a9368 add r3, r3, #1 */
/* @0x1a936c strb r4, [r0, #0x1] */
/* @0x1a9370 strb r4, [r3], #1 */
/* @0x1a9374 strb r4, [r3] */
/* @0x1a9378 ldr r3, [r5, #0x5c] */
/* @0x1a937c str r3, [r6, #0xc4] */
/* @0x1a9380 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a9384 ldrsbeq r3, [r10], -r0 */

/* ── FUNC 0x1a9388 · CRoom::Debug() · size=160 · insn=40 */
/* @0x1a9388 ldr r3, [pc, #0x8c] */
/* @0x1a938c push {r4, r5, r6, r7, lr} */
/* @0x1a9390 ldr r3, [pc, r3] */
/* @0x1a9394 ldr r1, [pc, #0x84] */
/* @0x1a9398 mov r4, r0 */
/* @0x1a939c ldr r6, [r3] */
/* @0x1a93a0 sub sp, sp, #20 */
/* @0x1a93a4 add r1, pc, r1 */
/* @0x1a93a8 ldr r3, [r6] */
/* @0x1a93ac mov r0, r6 */
/* @0x1a93b0 ldr r3, [r3, #0xc] */
/* @0x1a93b4 blx r3 */
/* @0x1a93b8 ldr r4, [r4, #0x80] */
/* @0x1a93bc cmp r4, #0 */
/* @0x1a93c0 beq 0x1a9414 <_ZN5CRoom5DebugEv+0x8c> */
/* @0x1a93c4 ldr r7, [pc, #0x58] */
/* @0x1a93c8 mov r5, #1000 */
/* @0x1a93cc add r7, pc, r7 */
/* @0x1a93d0 vldr s14, [r4, #384] */
/* @0x1a93d4 vcvt.f64.f32 d7, s14 */
/* @0x1a93d8 ldr r3, [r6] */
/* @0x1a93dc mov r2, r4 */
/* @0x1a93e0 mov r0, r6 */
/* @0x1a93e4 mov r1, r7 */
/* @0x1a93e8 vstr d7, [sp] */
/* @0x1a93ec ldr r12, [r4, #0x80] */
/* @0x1a93f0 ldr r12, [r12, #0x14] */
/* @0x1a93f4 str r12, [sp, #0x8] */
/* @0x1a93f8 ldr r3, [r3, #0xc] */
/* @0x1a93fc blx r3 */
/* @0x1a9400 ldr r4, [r4, #0x178] */
/* @0x1a9404 cmp r4, #0 */
/* @0x1a9408 beq 0x1a9414 <_ZN5CRoom5DebugEv+0x8c> */
/* @0x1a940c subs r5, r5, #1 */
/* @0x1a9410 bne 0x1a93d0 <_ZN5CRoom5DebugEv+0x48> */
/* @0x1a9414 add sp, sp, #20 */
/* @0x1a9418 pop {r4, r5, r6, r7, pc} */
/* @0x1a941c eoreq r4, r4, r4, lsl #7 */
/* @0x1a9420 andseq r3, r10, r8, lsr lr */
/* @0x1a9424 andseq r3, r10, r4, lsr #28 */

/* ── FUNC 0x1a9428 · CLayer::Serialize(IBuffer*) · size=3584 · insn=896 */
/* @0x1a9428 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a942c add r8, r1, #44 */
/* @0x1a9430 ldr r6, [r0] */
/* @0x1a9434 sub sp, sp, #28 */
/* @0x1a9438 ldr r3, [r1] */
/* @0x1a943c mov r4, r1 */
/* @0x1a9440 mov r5, #0 */
/* @0x1a9444 mov r2, r8 */
/* @0x1a9448 vmov s13, r6 */
/* @0x1a944c str r5, [r1, #0x38] */
/* @0x1a9450 str r0, [sp, #0xc] */
/* @0x1a9454 mov r0, r1 */
/* @0x1a9458 vcvt.f64.s32 d6, s13 */
/* @0x1a945c mov r1, #6 */
/* @0x1a9460 vmov r6, r7, d6 */
/* @0x1a9464 vstr s12, [r4, #44] */
/* @0x1a9468 str r7, [r4, #0x30] */
/* @0x1a946c ldr r3, [r3, #0x8] */
/* @0x1a9470 blx r3 */
/* @0x1a9474 ldr r3, [sp, #0xc] */
/* @0x1a9478 mov r0, r4 */
/* @0x1a947c ldr r1, [r3, #0x1c] */
/* @0x1a9480 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1a9484 ldr r3, [sp, #0xc] */
/* @0x1a9488 mov r2, r8 */
/* @0x1a948c mov r1, #6 */
/* @0x1a9490 mov r0, r4 */
/* @0x1a9494 ldr r6, [r3, #0x4] */
/* @0x1a9498 ldr r3, [r4] */
/* @0x1a949c str r5, [r4, #0x38] */
/* @0x1a94a0 vmov s13, r6 */
/* @0x1a94a4 vcvt.f64.s32 d6, s13 */
/* @0x1a94a8 vmov r6, r7, d6 */
/* @0x1a94ac vstr s12, [r4, #44] */
/* @0x1a94b0 str r7, [r4, #0x30] */
/* @0x1a94b4 ldr r3, [r3, #0x8] */
/* @0x1a94b8 blx r3 */
/* @0x1a94bc ldr r3, [sp, #0xc] */
/* @0x1a94c0 vldr s15, [r3, #8] */
/* @0x1a94c4 vcvt.f64.f32 d6, s15 */
/* @0x1a94c8 ldr r3, [r4] */
/* @0x1a94cc mov r2, r8 */
/* @0x1a94d0 mov r1, #8 */
/* @0x1a94d4 str r5, [r4, #0x38] */
/* @0x1a94d8 mov r0, r4 */
/* @0x1a94dc vmov r6, r7, d6 */
/* @0x1a94e0 vstr s12, [r4, #44] */
/* @0x1a94e4 str r7, [r4, #0x30] */
/* @0x1a94e8 ldr r3, [r3, #0x8] */
/* @0x1a94ec blx r3 */
/* @0x1a94f0 ldr r3, [sp, #0xc] */
/* @0x1a94f4 vldr s15, [r3, #12] */
/* @0x1a94f8 vcvt.f64.f32 d6, s15 */
/* @0x1a94fc ldr r3, [r4] */
/* @0x1a9500 mov r2, r8 */
/* @0x1a9504 mov r1, #8 */
/* @0x1a9508 str r5, [r4, #0x38] */
/* @0x1a950c mov r0, r4 */
/* @0x1a9510 vmov r6, r7, d6 */
/* @0x1a9514 vstr s12, [r4, #44] */
/* @0x1a9518 str r7, [r4, #0x30] */
/* @0x1a951c ldr r3, [r3, #0x8] */
/* @0x1a9520 blx r3 */
/* @0x1a9524 ldr r3, [sp, #0xc] */
/* @0x1a9528 vldr s15, [r3, #16] */
/* @0x1a952c vcvt.f64.f32 d6, s15 */
/* @0x1a9530 ldr r3, [r4] */
/* @0x1a9534 mov r2, r8 */
/* @0x1a9538 mov r1, #8 */
/* @0x1a953c str r5, [r4, #0x38] */
/* @0x1a9540 mov r0, r4 */
/* @0x1a9544 vmov r6, r7, d6 */
/* @0x1a9548 vstr s12, [r4, #44] */
/* @0x1a954c str r7, [r4, #0x30] */
/* @0x1a9550 ldr r3, [r3, #0x8] */
/* @0x1a9554 blx r3 */
/* @0x1a9558 ldr r3, [sp, #0xc] */
/* @0x1a955c vldr s15, [r3, #20] */
/* @0x1a9560 vcvt.f64.f32 d6, s15 */
/* @0x1a9564 ldr r3, [r4] */
/* @0x1a9568 mov r2, r8 */
/* @0x1a956c mov r1, #8 */
/* @0x1a9570 str r5, [r4, #0x38] */
/* @0x1a9574 mov r0, r4 */
/* @0x1a9578 vmov r6, r7, d6 */
/* @0x1a957c vstr s12, [r4, #44] */
/* @0x1a9580 str r7, [r4, #0x30] */
/* @0x1a9584 ldr r3, [r3, #0x8] */
/* @0x1a9588 blx r3 */
/* @0x1a958c ldr r3, [sp, #0xc] */
/* @0x1a9590 mov r2, r8 */
/* @0x1a9594 mov r1, #6 */
/* @0x1a9598 mov r0, r4 */
/* @0x1a959c ldrb r6, [r3, #0x18] */
/* @0x1a95a0 ldr r3, [r4] */
/* @0x1a95a4 str r5, [r4, #0x38] */
/* @0x1a95a8 vmov s13, r6 */
/* @0x1a95ac vcvt.f64.u32 d6, s13 */
/* @0x1a95b0 vmov r6, r7, d6 */
/* @0x1a95b4 vstr s12, [r4, #44] */
/* @0x1a95b8 str r7, [r4, #0x30] */
/* @0x1a95bc ldr r3, [r3, #0x8] */
/* @0x1a95c0 blx r3 */
/* @0x1a95c4 ldr r3, [sp, #0xc] */
/* @0x1a95c8 mov r2, r8 */
/* @0x1a95cc mov r1, #6 */
/* @0x1a95d0 mov r0, r4 */
/* @0x1a95d4 ldrb r6, [r3, #0x19] */
/* @0x1a95d8 ldr r3, [r4] */
/* @0x1a95dc str r5, [r4, #0x38] */
/* @0x1a95e0 vmov s13, r6 */
/* @0x1a95e4 vcvt.f64.u32 d6, s13 */
/* @0x1a95e8 vmov r6, r7, d6 */
/* @0x1a95ec vstr s12, [r4, #44] */
/* @0x1a95f0 str r7, [r4, #0x30] */
/* @0x1a95f4 ldr r3, [r3, #0x8] */
/* @0x1a95f8 blx r3 */
/* @0x1a95fc ldr r3, [sp, #0xc] */
/* @0x1a9600 mov r2, r8 */
/* @0x1a9604 mov r1, #6 */
/* @0x1a9608 mov r0, r4 */
/* @0x1a960c ldr r6, [r3, #0x20] */
/* @0x1a9610 ldr r3, [r4] */
/* @0x1a9614 str r5, [r4, #0x38] */
/* @0x1a9618 vmov s13, r6 */
/* @0x1a961c vcvt.f64.s32 d6, s13 */
/* @0x1a9620 vmov r6, r7, d6 */
/* @0x1a9624 vstr s12, [r4, #44] */
/* @0x1a9628 str r7, [r4, #0x30] */
/* @0x1a962c ldr r3, [r3, #0x8] */
/* @0x1a9630 blx r3 */
/* @0x1a9634 ldr r3, [sp, #0xc] */
/* @0x1a9638 mov r2, r8 */
/* @0x1a963c mov r1, #6 */
/* @0x1a9640 mov r0, r4 */
/* @0x1a9644 ldr r6, [r3, #0x24] */
/* @0x1a9648 ldr r3, [r4] */
/* @0x1a964c str r5, [r4, #0x38] */
/* @0x1a9650 vmov s13, r6 */
/* @0x1a9654 vcvt.f64.s32 d6, s13 */
/* @0x1a9658 vmov r6, r7, d6 */
/* @0x1a965c vstr s12, [r4, #44] */
/* @0x1a9660 str r7, [r4, #0x30] */
/* @0x1a9664 ldr r3, [r3, #0x8] */
/* @0x1a9668 blx r3 */
/* @0x1a966c ldr r3, [sp, #0xc] */
/* @0x1a9670 mov r1, #6 */
/* @0x1a9674 mov r2, r8 */
/* @0x1a9678 mov r0, r4 */
/* @0x1a967c ldr r6, [r3, #0x28] */
/* @0x1a9680 ldr r3, [r4] */
/* @0x1a9684 str r5, [r4, #0x38] */
/* @0x1a9688 vmov s13, r6 */
/* @0x1a968c vcvt.f64.s32 d6, s13 */
/* @0x1a9690 vmov r6, r7, d6 */
/* @0x1a9694 vstr s12, [r4, #44] */
/* @0x1a9698 str r7, [r4, #0x30] */
/* @0x1a969c ldr r3, [r3, #0x8] */
/* @0x1a96a0 blx r3 */
/* @0x1a96a4 ldr r1, [sp, #0xc] */
/* @0x1a96a8 ldr r3, [r1, #0x58] */
/* @0x1a96ac cmp r3, r5 */
/* @0x1a96b0 beq 0x1aa20c <_ZN6CLayer9SerializeEP7IBuffer+0xde4> */
/* @0x1a96b4 mov r7, r5 */
/* @0x1a96b8 mov r2, r5 */
/* @0x1a96bc mov r0, r5 */
/* @0x1a96c0 mov r12, r5 */
/* @0x1a96c4 str r5, [sp, #0x10] */
/* @0x1a96c8 str r5, [sp, #0x14] */
/* @0x1a96cc ldr r1, [r3] */
/* @0x1a96d0 sub r1, r1, #1 */
/* @0x1a96d4 cmp r1, #6 */
/* @0x1a96d8 addls pc, pc, r1, lsl #2 */
/* @0x1a96dc b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1a96e0 b 0x1aa1fc <_ZN6CLayer9SerializeEP7IBuffer+0xdd4> */
/* @0x1a96e4 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1a96e8 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1a96ec b 0x1aa204 <_ZN6CLayer9SerializeEP7IBuffer+0xddc> */
/* @0x1a96f0 b 0x1aa1f4 <_ZN6CLayer9SerializeEP7IBuffer+0xdcc> */
/* @0x1a96f4 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1a96f8 b 0x1a96fc <_ZN6CLayer9SerializeEP7IBuffer+0x2d4> */
/* @0x1a96fc add r12, r12, #1 */
/* @0x1a9700 ldr r3, [r3, #0x14] */
/* @0x1a9704 cmp r3, #0 */
/* @0x1a9708 bne 0x1a96cc <_ZN6CLayer9SerializeEP7IBuffer+0x2a4> */
/* @0x1a970c vmov s13, r2 */
/* @0x1a9710 str r0, [sp, #0x14] */
/* @0x1a9714 str r12, [sp, #0x10] */
/* @0x1a9718 vcvt.f64.s32 d6, s13 */
/* @0x1a971c vmov r2, r3, d6 */
/* @0x1a9720 ldr r1, [r4] */
/* @0x1a9724 mov r6, #0 */
/* @0x1a9728 str r2, [r4, #0x2c] */
/* @0x1a972c mov r0, r4 */
/* @0x1a9730 str r3, [r4, #0x30] */
/* @0x1a9734 mov r2, r8 */
/* @0x1a9738 ldr r3, [r1, #0x8] */
/* @0x1a973c mov r1, #6 */
/* @0x1a9740 str r6, [r4, #0x38] */
/* @0x1a9744 blx r3 */
/* @0x1a9748 ldr r3, [sp, #0xc] */
/* @0x1a974c ldr r9, [r3, #0x58] */
/* @0x1a9750 cmp r9, r6 */
/* @0x1a9754 bne 0x1a9768 <_ZN6CLayer9SerializeEP7IBuffer+0x340> */
/* @0x1a9758 b 0x1a9a14 <_ZN6CLayer9SerializeEP7IBuffer+0x5ec> */
/* @0x1a975c ldr r9, [r9, #0x14] */
/* @0x1a9760 cmp r9, #0 */
/* @0x1a9764 beq 0x1a9a14 <_ZN6CLayer9SerializeEP7IBuffer+0x5ec> */
/* @0x1a9768 ldr r3, [r9] */
/* @0x1a976c cmp r3, #1 */
/* @0x1a9770 bne 0x1a975c <_ZN6CLayer9SerializeEP7IBuffer+0x334> */
/* @0x1a9774 ldr r5, [r9, #0x1c] */
/* @0x1a9778 mov r1, #6 */
/* @0x1a977c ldr r3, [r4] */
/* @0x1a9780 mov r2, r8 */
/* @0x1a9784 mov r0, r4 */
/* @0x1a9788 ldrb r10, [r5] */
/* @0x1a978c str r6, [r4, #0x38] */
/* @0x1a9790 vmov s13, r10 */
/* @0x1a9794 vcvt.f64.u32 d6, s13 */
/* @0x1a9798 vmov r10, r11, d6 */
/* @0x1a979c vstr s12, [r4, #44] */
/* @0x1a97a0 str r11, [r4, #0x30] */
/* @0x1a97a4 ldr r3, [r3, #0x8] */
/* @0x1a97a8 blx r3 */
/* @0x1a97ac ldrb r10, [r5, #0x1] */
/* @0x1a97b0 ldr r3, [r4] */
/* @0x1a97b4 mov r1, #6 */
/* @0x1a97b8 mov r2, r8 */
/* @0x1a97bc mov r0, r4 */
/* @0x1a97c0 vmov s15, r10 */
/* @0x1a97c4 str r6, [r4, #0x38] */
/* @0x1a97c8 vcvt.f64.u32 d7, s15 */
/* @0x1a97cc vmov r10, r11, d7 */
/* @0x1a97d0 vstr s14, [r4, #44] */
/* @0x1a97d4 str r11, [r4, #0x30] */
/* @0x1a97d8 ldr r3, [r3, #0x8] */
/* @0x1a97dc blx r3 */
/* @0x1a97e0 ldr r10, [r5, #0x4] */
/* @0x1a97e4 ldr r3, [r4] */
/* @0x1a97e8 mov r1, #6 */
/* @0x1a97ec mov r2, r8 */
/* @0x1a97f0 mov r0, r4 */
/* @0x1a97f4 vmov s13, r10 */
/* @0x1a97f8 str r6, [r4, #0x38] */
/* @0x1a97fc vcvt.f64.s32 d6, s13 */
/* @0x1a9800 vmov r10, r11, d6 */
/* @0x1a9804 vstr s12, [r4, #44] */
/* @0x1a9808 str r11, [r4, #0x30] */
/* @0x1a980c ldr r3, [r3, #0x8] */
/* @0x1a9810 blx r3 */
/* @0x1a9814 ldrb r10, [r5, #0x8] */
/* @0x1a9818 ldr r3, [r4] */
/* @0x1a981c mov r1, #6 */
/* @0x1a9820 mov r2, r8 */
/* @0x1a9824 mov r0, r4 */
/* @0x1a9828 vmov s15, r10 */
/* @0x1a982c str r6, [r4, #0x38] */
/* @0x1a9830 vcvt.f64.u32 d7, s15 */
/* @0x1a9834 vmov r10, r11, d7 */
/* @0x1a9838 vstr s14, [r4, #44] */
/* @0x1a983c str r11, [r4, #0x30] */
/* @0x1a9840 ldr r3, [r3, #0x8] */
/* @0x1a9844 blx r3 */
/* @0x1a9848 ldrb r10, [r5, #0x9] */
/* @0x1a984c ldr r3, [r4] */
/* @0x1a9850 mov r1, #6 */
/* @0x1a9854 mov r2, r8 */
/* @0x1a9858 mov r0, r4 */
/* @0x1a985c vmov s13, r10 */
/* @0x1a9860 str r6, [r4, #0x38] */
/* @0x1a9864 vcvt.f64.u32 d6, s13 */
/* @0x1a9868 vmov r10, r11, d6 */
/* @0x1a986c vstr s12, [r4, #44] */
/* @0x1a9870 str r11, [r4, #0x30] */
/* @0x1a9874 ldr r3, [r3, #0x8] */
/* @0x1a9878 blx r3 */
/* @0x1a987c vldr s14, [r5, #12] */
/* @0x1a9880 vcvt.f64.f32 d6, s14 */
/* @0x1a9884 ldr r3, [r4] */
/* @0x1a9888 mov r1, #8 */
/* @0x1a988c mov r2, r8 */
/* @0x1a9890 str r6, [r4, #0x38] */
/* @0x1a9894 mov r0, r4 */
/* @0x1a9898 vmov r10, r11, d6 */
/* @0x1a989c vstr s12, [r4, #44] */
/* @0x1a98a0 str r11, [r4, #0x30] */
/* @0x1a98a4 ldr r3, [r3, #0x8] */
/* @0x1a98a8 blx r3 */
/* @0x1a98ac vldr s14, [r5, #16] */
/* @0x1a98b0 vcvt.f64.f32 d6, s14 */
/* @0x1a98b4 ldr r3, [r4] */
/* @0x1a98b8 mov r1, #8 */
/* @0x1a98bc mov r2, r8 */
/* @0x1a98c0 str r6, [r4, #0x38] */
/* @0x1a98c4 mov r0, r4 */
/* @0x1a98c8 vmov r10, r11, d6 */
/* @0x1a98cc vstr s12, [r4, #44] */
/* @0x1a98d0 str r11, [r4, #0x30] */
/* @0x1a98d4 ldr r3, [r3, #0x8] */
/* @0x1a98d8 blx r3 */
/* @0x1a98dc ldrb r10, [r5, #0x14] */
/* @0x1a98e0 ldr r3, [r4] */
/* @0x1a98e4 mov r1, #6 */
/* @0x1a98e8 mov r2, r8 */
/* @0x1a98ec mov r0, r4 */
/* @0x1a98f0 vmov s15, r10 */
/* @0x1a98f4 str r6, [r4, #0x38] */
/* @0x1a98f8 vcvt.f64.u32 d7, s15 */
/* @0x1a98fc vmov r10, r11, d7 */
/* @0x1a9900 vstr s14, [r4, #44] */
/* @0x1a9904 str r11, [r4, #0x30] */
/* @0x1a9908 ldr r3, [r3, #0x8] */
/* @0x1a990c blx r3 */
/* @0x1a9910 ldr r10, [r5, #0x18] */
/* @0x1a9914 ldr r3, [r4] */
/* @0x1a9918 mov r1, #6 */
/* @0x1a991c mov r2, r8 */
/* @0x1a9920 mov r0, r4 */
/* @0x1a9924 vmov s13, r10 */
/* @0x1a9928 str r6, [r4, #0x38] */
/* @0x1a992c vcvt.f64.s32 d6, s13 */
/* @0x1a9930 vmov r10, r11, d6 */
/* @0x1a9934 vstr s12, [r4, #44] */
/* @0x1a9938 str r11, [r4, #0x30] */
/* @0x1a993c ldr r3, [r3, #0x8] */
/* @0x1a9940 blx r3 */
/* @0x1a9944 vldr s14, [r5, #28] */
/* @0x1a9948 vcvt.f64.f32 d6, s14 */
/* @0x1a994c ldr r3, [r4] */
/* @0x1a9950 mov r1, #8 */
/* @0x1a9954 mov r2, r8 */
/* @0x1a9958 str r6, [r4, #0x38] */
/* @0x1a995c mov r0, r4 */
/* @0x1a9960 vmov r10, r11, d6 */
/* @0x1a9964 vstr s12, [r4, #44] */
/* @0x1a9968 str r11, [r4, #0x30] */
/* @0x1a996c ldr r3, [r3, #0x8] */
/* @0x1a9970 blx r3 */
/* @0x1a9974 vldr s14, [r5, #32] */
/* @0x1a9978 vcvt.f64.f32 d6, s14 */
/* @0x1a997c ldr r3, [r4] */
/* @0x1a9980 mov r1, #8 */
/* @0x1a9984 mov r2, r8 */
/* @0x1a9988 str r6, [r4, #0x38] */
/* @0x1a998c mov r0, r4 */
/* @0x1a9990 vmov r10, r11, d6 */
/* @0x1a9994 vstr s12, [r4, #44] */
/* @0x1a9998 str r11, [r4, #0x30] */
/* @0x1a999c ldr r3, [r3, #0x8] */
/* @0x1a99a0 blx r3 */
/* @0x1a99a4 vldr s14, [r5, #36] */
/* @0x1a99a8 vcvt.f64.f32 d6, s14 */
/* @0x1a99ac ldr r3, [r4] */
/* @0x1a99b0 mov r1, #8 */
/* @0x1a99b4 mov r2, r8 */
/* @0x1a99b8 str r6, [r4, #0x38] */
/* @0x1a99bc mov r0, r4 */
/* @0x1a99c0 vmov r10, r11, d6 */
/* @0x1a99c4 vstr s12, [r4, #44] */
/* @0x1a99c8 str r11, [r4, #0x30] */
/* @0x1a99cc ldr r3, [r3, #0x8] */
/* @0x1a99d0 blx r3 */
/* @0x1a99d4 ldr r10, [r5, #0x28] */
/* @0x1a99d8 ldr r3, [r4] */
/* @0x1a99dc mov r0, r4 */
/* @0x1a99e0 str r6, [r4, #0x38] */
/* @0x1a99e4 mov r1, #6 */
/* @0x1a99e8 vmov s15, r10 */
/* @0x1a99ec mov r2, r8 */
/* @0x1a99f0 vcvt.f64.s32 d7, s15 */
/* @0x1a99f4 vmov r10, r11, d7 */
/* @0x1a99f8 vstr s14, [r4, #44] */
/* @0x1a99fc str r11, [r4, #0x30] */
/* @0x1a9a00 ldr r3, [r3, #0x8] */
/* @0x1a9a04 blx r3 */
/* @0x1a9a08 ldr r9, [r9, #0x14] */
/* @0x1a9a0c cmp r9, #0 */
/* @0x1a9a10 bne 0x1a9768 <_ZN6CLayer9SerializeEP7IBuffer+0x340> */
/* @0x1a9a14 vmov s13, r7 */
/* @0x1a9a18 ldr r3, [r4] */
/* @0x1a9a1c mov r9, #0 */
/* @0x1a9a20 mov r0, r4 */
/* @0x1a9a24 vcvt.f64.s32 d6, s13 */
/* @0x1a9a28 str r9, [r4, #0x38] */
/* @0x1a9a2c mov r1, #6 */
/* @0x1a9a30 mov r2, r8 */
/* @0x1a9a34 vmov r6, r7, d6 */
/* @0x1a9a38 vstr s12, [r4, #44] */
/* @0x1a9a3c str r7, [r4, #0x30] */
/* @0x1a9a40 ldr r3, [r3, #0x8] */
/* @0x1a9a44 blx r3 */
/* @0x1a9a48 ldr r3, [sp, #0xc] */
/* @0x1a9a4c ldr r7, [r3, #0x58] */
/* @0x1a9a50 cmp r7, r9 */
/* @0x1a9a54 strne r8, [sp, #0x4] */
/* @0x1a9a58 movne r5, r7 */
/* @0x1a9a5c bne 0x1a9a70 <_ZN6CLayer9SerializeEP7IBuffer+0x648> */
/* @0x1a9a60 b 0x1a9c9c <_ZN6CLayer9SerializeEP7IBuffer+0x874> */
/* @0x1a9a64 ldr r5, [r5, #0x14] */
/* @0x1a9a68 cmp r5, #0 */
/* @0x1a9a6c beq 0x1a9c98 <_ZN6CLayer9SerializeEP7IBuffer+0x870> */
/* @0x1a9a70 ldr r3, [r5] */
/* @0x1a9a74 cmp r3, #5 */
/* @0x1a9a78 bne 0x1a9a64 <_ZN6CLayer9SerializeEP7IBuffer+0x63c> */
/* @0x1a9a7c ldr r6, [r5, #0x1c] */
/* @0x1a9a80 mov r1, #6 */
/* @0x1a9a84 ldr r3, [r4] */
/* @0x1a9a88 mov r0, r4 */
/* @0x1a9a8c ldr r2, [sp, #0x4] */
/* @0x1a9a90 vmov s13, r6 */
/* @0x1a9a94 str r9, [r4, #0x38] */
/* @0x1a9a98 vcvt.f64.s32 d6, s13 */
/* @0x1a9a9c vmov r6, r7, d6 */
/* @0x1a9aa0 vstr s12, [r4, #44] */
/* @0x1a9aa4 str r7, [r4, #0x30] */
/* @0x1a9aa8 ldr r3, [r3, #0x8] */
/* @0x1a9aac blx r3 */
/* @0x1a9ab0 ldr r1, [r5, #0xc] */
/* @0x1a9ab4 mov r0, r4 */
/* @0x1a9ab8 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1a9abc vldr s14, [r5, #32] */
/* @0x1a9ac0 vcvt.f64.f32 d6, s14 */
/* @0x1a9ac4 ldr r3, [r4] */
/* @0x1a9ac8 mov r1, #8 */
/* @0x1a9acc ldr r2, [sp, #0x4] */
/* @0x1a9ad0 str r9, [r4, #0x38] */
/* @0x1a9ad4 mov r0, r4 */
/* @0x1a9ad8 vmov r6, r7, d6 */
/* @0x1a9adc vstr s12, [r4, #44] */
/* @0x1a9ae0 str r7, [r4, #0x30] */
/* @0x1a9ae4 ldr r3, [r3, #0x8] */
/* @0x1a9ae8 blx r3 */
/* @0x1a9aec vldr s14, [r5, #36] */
/* @0x1a9af0 vcvt.f64.f32 d6, s14 */
/* @0x1a9af4 ldr r3, [r4] */
/* @0x1a9af8 mov r1, #8 */
/* @0x1a9afc ldr r2, [sp, #0x4] */
/* @0x1a9b00 str r9, [r4, #0x38] */
/* @0x1a9b04 mov r0, r4 */
/* @0x1a9b08 vmov r6, r7, d6 */
/* @0x1a9b0c vstr s12, [r4, #44] */
/* @0x1a9b10 str r7, [r4, #0x30] */
/* @0x1a9b14 ldr r3, [r3, #0x8] */
/* @0x1a9b18 blx r3 */
/* @0x1a9b1c ldr r6, [r5, #0x28] */
/* @0x1a9b20 ldr r3, [r4] */
/* @0x1a9b24 mov r1, #6 */
/* @0x1a9b28 ldr r2, [sp, #0x4] */
/* @0x1a9b2c mov r0, r4 */
/* @0x1a9b30 vmov s15, r6 */
/* @0x1a9b34 str r9, [r4, #0x38] */
/* @0x1a9b38 vcvt.f64.s32 d7, s15 */
/* @0x1a9b3c vmov r6, r7, d7 */
/* @0x1a9b40 vstr s14, [r4, #44] */
/* @0x1a9b44 str r7, [r4, #0x30] */
/* @0x1a9b48 ldr r3, [r3, #0x8] */
/* @0x1a9b4c blx r3 */
/* @0x1a9b50 ldr r6, [r5, #0x2c] */
/* @0x1a9b54 ldr r3, [r4] */
/* @0x1a9b58 mov r1, #6 */
/* @0x1a9b5c ldr r2, [sp, #0x4] */
/* @0x1a9b60 mov r0, r4 */
/* @0x1a9b64 vmov s13, r6 */
/* @0x1a9b68 str r9, [r4, #0x38] */
/* @0x1a9b6c vcvt.f64.s32 d6, s13 */
/* @0x1a9b70 vmov r6, r7, d6 */
/* @0x1a9b74 vstr s12, [r4, #44] */
/* @0x1a9b78 str r7, [r4, #0x30] */
/* @0x1a9b7c ldr r3, [r3, #0x8] */
/* @0x1a9b80 blx r3 */
/* @0x1a9b84 vldr s14, [r5, #48] */
/* @0x1a9b88 vcvt.f64.f32 d6, s14 */
/* @0x1a9b8c ldr r3, [r4] */
/* @0x1a9b90 str r9, [r4, #0x38] */
/* @0x1a9b94 mov r0, r4 */
/* @0x1a9b98 mov r1, #8 */
/* @0x1a9b9c ldr r2, [sp, #0x4] */
/* @0x1a9ba0 vmov r6, r7, d6 */
/* @0x1a9ba4 vstr s12, [r4, #44] */
/* @0x1a9ba8 str r7, [r4, #0x30] */
/* @0x1a9bac ldr r3, [r3, #0x8] */
/* @0x1a9bb0 blx r3 */
/* @0x1a9bb4 ldr r3, [r5, #0x28] */
/* @0x1a9bb8 cmp r3, #0 */
/* @0x1a9bbc ble 0x1a9c58 <_ZN6CLayer9SerializeEP7IBuffer+0x830> */
/* @0x1a9bc0 mov r1, #0 */
/* @0x1a9bc4 mov r0, r5 */
/* @0x1a9bc8 str r1, [sp, #0x8] */
/* @0x1a9bcc mov r11, r0 */
/* @0x1a9bd0 ldr r2, [r5, #0x2c] */
/* @0x1a9bd4 mov r5, r1 */
/* @0x1a9bd8 mov r1, r3 */
/* @0x1a9bdc cmp r2, #0 */
/* @0x1a9be0 ble 0x1a9c40 <_ZN6CLayer9SerializeEP7IBuffer+0x818> */
/* @0x1a9be4 lsl r10, r5, #2 */
/* @0x1a9be8 mov r8, #0 */
/* @0x1a9bec ldr r2, [r11, #0x34] */
/* @0x1a9bf0 mov r0, r4 */
/* @0x1a9bf4 ldr r12, [r4] */
/* @0x1a9bf8 mov r1, #5 */
/* @0x1a9bfc add r8, r8, #1 */
/* @0x1a9c00 add r5, r5, #1 */
/* @0x1a9c04 ldr r6, [r2, r10] */
/* @0x1a9c08 add r10, r10, #4 */
/* @0x1a9c0c ldr r2, [sp, #0x4] */
/* @0x1a9c10 str r9, [r4, #0x38] */
/* @0x1a9c14 vmov s13, r6 */
/* @0x1a9c18 vcvt.f64.u32 d6, s13 */
/* @0x1a9c1c vmov r6, r7, d6 */
/* @0x1a9c20 vstr s12, [r4, #44] */
/* @0x1a9c24 str r7, [r4, #0x30] */
/* @0x1a9c28 ldr r12, [r12, #0x8] */
/* @0x1a9c2c blx r12 */
/* @0x1a9c30 ldr r2, [r11, #0x2c] */
/* @0x1a9c34 cmp r2, r8 */
/* @0x1a9c38 bgt 0x1a9bec <_ZN6CLayer9SerializeEP7IBuffer+0x7c4> */
/* @0x1a9c3c ldr r1, [r11, #0x28] */
/* @0x1a9c40 ldr r3, [sp, #0x8] */
/* @0x1a9c44 add r3, r3, #1 */
/* @0x1a9c48 str r3, [sp, #0x8] */
/* @0x1a9c4c cmp r1, r3 */
/* @0x1a9c50 bgt 0x1a9bdc <_ZN6CLayer9SerializeEP7IBuffer+0x7b4> */
/* @0x1a9c54 mov r5, r11 */
/* @0x1a9c58 ldr r6, [r5, #0x38] */
/* @0x1a9c5c mov r0, r4 */
/* @0x1a9c60 ldr r3, [r4] */
/* @0x1a9c64 mov r1, #5 */
/* @0x1a9c68 str r9, [r4, #0x38] */
/* @0x1a9c6c vmov s13, r6 */
/* @0x1a9c70 ldr r2, [sp, #0x4] */
/* @0x1a9c74 vcvt.f64.u32 d6, s13 */
/* @0x1a9c78 vmov r6, r7, d6 */
/* @0x1a9c7c vstr s12, [r4, #44] */
/* @0x1a9c80 str r7, [r4, #0x30] */
/* @0x1a9c84 ldr r3, [r3, #0x8] */
/* @0x1a9c88 blx r3 */
/* @0x1a9c8c ldr r5, [r5, #0x14] */
/* @0x1a9c90 cmp r5, #0 */
/* @0x1a9c94 bne 0x1a9a70 <_ZN6CLayer9SerializeEP7IBuffer+0x648> */
/* @0x1a9c98 ldr r8, [sp, #0x4] */
/* @0x1a9c9c vldr s13, [sp, #20] */
/* @0x1a9ca0 vcvt.f64.s32 d6, s13 */
/* @0x1a9ca4 ldr r3, [r4] */
/* @0x1a9ca8 mov r5, #0 */
/* @0x1a9cac mov r0, r4 */
/* @0x1a9cb0 str r5, [r4, #0x38] */
/* @0x1a9cb4 mov r1, #6 */
/* @0x1a9cb8 mov r2, r8 */
/* @0x1a9cbc vmov r6, r7, d6 */
/* @0x1a9cc0 vstr s12, [r4, #44] */
/* @0x1a9cc4 str r7, [r4, #0x30] */
/* @0x1a9cc8 ldr r3, [r3, #0x8] */
/* @0x1a9ccc blx r3 */
/* @0x1a9cd0 ldr r3, [sp, #0xc] */
/* @0x1a9cd4 ldr r9, [r3, #0x58] */
/* @0x1a9cd8 cmp r9, r5 */
/* @0x1a9cdc bne 0x1a9cf0 <_ZN6CLayer9SerializeEP7IBuffer+0x8c8> */
/* @0x1a9ce0 b 0x1a9ef4 <_ZN6CLayer9SerializeEP7IBuffer+0xacc> */
/* @0x1a9ce4 ldr r9, [r9, #0x14] */
/* @0x1a9ce8 cmp r9, #0 */
/* @0x1a9cec beq 0x1a9ef4 <_ZN6CLayer9SerializeEP7IBuffer+0xacc> */
/* @0x1a9cf0 ldr r3, [r9] */
/* @0x1a9cf4 cmp r3, #4 */
/* @0x1a9cf8 bne 0x1a9ce4 <_ZN6CLayer9SerializeEP7IBuffer+0x8bc> */
/* @0x1a9cfc ldr r6, [r9, #0x1c] */
/* @0x1a9d00 mov r1, #6 */
/* @0x1a9d04 ldr r3, [r4] */
/* @0x1a9d08 mov r2, r8 */
/* @0x1a9d0c mov r0, r4 */
/* @0x1a9d10 str r5, [r4, #0x38] */
/* @0x1a9d14 vmov s13, r6 */
/* @0x1a9d18 vcvt.f64.s32 d6, s13 */
/* @0x1a9d1c vmov r6, r7, d6 */
/* @0x1a9d20 vstr s12, [r4, #44] */
/* @0x1a9d24 str r7, [r4, #0x30] */
/* @0x1a9d28 ldr r3, [r3, #0x8] */
/* @0x1a9d2c blx r3 */
/* @0x1a9d30 vldr s15, [r9, #36] */
/* @0x1a9d34 vcvt.f64.f32 d6, s15 */
/* @0x1a9d38 ldr r3, [r4] */
/* @0x1a9d3c mov r1, #8 */
/* @0x1a9d40 mov r2, r8 */
/* @0x1a9d44 str r5, [r4, #0x38] */
/* @0x1a9d48 mov r0, r4 */
/* @0x1a9d4c vmov r6, r7, d6 */
/* @0x1a9d50 vstr s12, [r4, #44] */
/* @0x1a9d54 str r7, [r4, #0x30] */
/* @0x1a9d58 ldr r3, [r3, #0x8] */
/* @0x1a9d5c blx r3 */
/* @0x1a9d60 ldr r6, [r9, #0x28] */
/* @0x1a9d64 ldr r3, [r4] */
/* @0x1a9d68 mov r1, #6 */
/* @0x1a9d6c mov r2, r8 */
/* @0x1a9d70 mov r0, r4 */
/* @0x1a9d74 vmov s15, r6 */
/* @0x1a9d78 str r5, [r4, #0x38] */
/* @0x1a9d7c vcvt.f64.s32 d7, s15 */
/* @0x1a9d80 vmov r6, r7, d7 */
/* @0x1a9d84 vstr s14, [r4, #44] */
/* @0x1a9d88 str r7, [r4, #0x30] */
/* @0x1a9d8c ldr r3, [r3, #0x8] */
/* @0x1a9d90 blx r3 */
/* @0x1a9d94 vldr s15, [r9, #44] */
/* @0x1a9d98 vcvt.f64.f32 d6, s15 */
/* @0x1a9d9c ldr r3, [r4] */
/* @0x1a9da0 mov r1, #8 */
/* @0x1a9da4 mov r2, r8 */
/* @0x1a9da8 str r5, [r4, #0x38] */
/* @0x1a9dac mov r0, r4 */
/* @0x1a9db0 vmov r6, r7, d6 */
/* @0x1a9db4 vstr s12, [r4, #44] */
/* @0x1a9db8 str r7, [r4, #0x30] */
/* @0x1a9dbc ldr r3, [r3, #0x8] */
/* @0x1a9dc0 blx r3 */
/* @0x1a9dc4 vldr s15, [r9, #48] */
/* @0x1a9dc8 vcvt.f64.f32 d6, s15 */
/* @0x1a9dcc ldr r3, [r4] */
/* @0x1a9dd0 mov r1, #8 */
/* @0x1a9dd4 mov r2, r8 */
/* @0x1a9dd8 str r5, [r4, #0x38] */
/* @0x1a9ddc mov r0, r4 */
/* @0x1a9de0 vmov r6, r7, d6 */
/* @0x1a9de4 vstr s12, [r4, #44] */
/* @0x1a9de8 str r7, [r4, #0x30] */
/* @0x1a9dec ldr r3, [r3, #0x8] */
/* @0x1a9df0 blx r3 */
/* @0x1a9df4 vldr s15, [r9, #52] */
/* @0x1a9df8 vcvt.f64.f32 d6, s15 */
/* @0x1a9dfc ldr r3, [r4] */
/* @0x1a9e00 mov r1, #8 */
/* @0x1a9e04 mov r2, r8 */
/* @0x1a9e08 str r5, [r4, #0x38] */
/* @0x1a9e0c mov r0, r4 */
/* @0x1a9e10 vmov r6, r7, d6 */
/* @0x1a9e14 vstr s12, [r4, #44] */
/* @0x1a9e18 str r7, [r4, #0x30] */
/* @0x1a9e1c ldr r3, [r3, #0x8] */
/* @0x1a9e20 blx r3 */
/* @0x1a9e24 ldr r6, [r9, #0x38] */
/* @0x1a9e28 ldr r3, [r4] */
/* @0x1a9e2c mov r1, #5 */
/* @0x1a9e30 mov r2, r8 */
/* @0x1a9e34 mov r0, r4 */
/* @0x1a9e38 vmov s15, r6 */
/* @0x1a9e3c str r5, [r4, #0x38] */
/* @0x1a9e40 vcvt.f64.u32 d7, s15 */
/* @0x1a9e44 vmov r6, r7, d7 */
/* @0x1a9e48 vstr s14, [r4, #44] */
/* @0x1a9e4c str r7, [r4, #0x30] */
/* @0x1a9e50 ldr r3, [r3, #0x8] */
/* @0x1a9e54 blx r3 */
/* @0x1a9e58 vldr s15, [r9, #60] */
/* @0x1a9e5c vcvt.f64.f32 d6, s15 */
/* @0x1a9e60 ldr r3, [r4] */
/* @0x1a9e64 mov r1, #8 */
/* @0x1a9e68 mov r2, r8 */
/* @0x1a9e6c str r5, [r4, #0x38] */
/* @0x1a9e70 mov r0, r4 */
/* @0x1a9e74 vmov r6, r7, d6 */
/* @0x1a9e78 vstr s12, [r4, #44] */
/* @0x1a9e7c str r7, [r4, #0x30] */
/* @0x1a9e80 ldr r3, [r3, #0x8] */
/* @0x1a9e84 blx r3 */
/* @0x1a9e88 vldr s15, [r9, #64] */
/* @0x1a9e8c vcvt.f64.f32 d6, s15 */
/* @0x1a9e90 ldr r3, [r4] */
/* @0x1a9e94 mov r1, #8 */
/* @0x1a9e98 mov r2, r8 */
/* @0x1a9e9c str r5, [r4, #0x38] */
/* @0x1a9ea0 mov r0, r4 */
/* @0x1a9ea4 vmov r6, r7, d6 */
/* @0x1a9ea8 vstr s12, [r4, #44] */
/* @0x1a9eac str r7, [r4, #0x30] */
/* @0x1a9eb0 ldr r3, [r3, #0x8] */
/* @0x1a9eb4 blx r3 */
/* @0x1a9eb8 vldr s15, [r9, #68] */
/* @0x1a9ebc vcvt.f64.f32 d6, s15 */
/* @0x1a9ec0 ldr r3, [r4] */
/* @0x1a9ec4 str r5, [r4, #0x38] */
/* @0x1a9ec8 mov r0, r4 */
/* @0x1a9ecc mov r1, #8 */
/* @0x1a9ed0 mov r2, r8 */
/* @0x1a9ed4 vmov r6, r7, d6 */
/* @0x1a9ed8 vstr s12, [r4, #44] */
/* @0x1a9edc str r7, [r4, #0x30] */
/* @0x1a9ee0 ldr r3, [r3, #0x8] */
/* @0x1a9ee4 blx r3 */
/* @0x1a9ee8 ldr r9, [r9, #0x14] */
/* @0x1a9eec cmp r9, #0 */
/* @0x1a9ef0 bne 0x1a9cf0 <_ZN6CLayer9SerializeEP7IBuffer+0x8c8> */
/* @0x1a9ef4 vldr s15, [sp, #16] */
/* @0x1a9ef8 vcvt.f64.s32 d7, s15 */
/* @0x1a9efc ldr r3, [r4] */
/* @0x1a9f00 mov r5, #0 */
/* @0x1a9f04 mov r0, r4 */
/* @0x1a9f08 str r5, [r4, #0x38] */
/* @0x1a9f0c mov r1, #6 */
/* @0x1a9f10 mov r2, r8 */
/* @0x1a9f14 vmov r6, r7, d7 */
/* @0x1a9f18 vstr s14, [r4, #44] */
/* @0x1a9f1c str r7, [r4, #0x30] */
/* @0x1a9f20 ldr r3, [r3, #0x8] */
/* @0x1a9f24 blx r3 */
/* @0x1a9f28 ldr r3, [sp, #0xc] */
/* @0x1a9f2c ldr r9, [r3, #0x58] */
/* @0x1a9f30 cmp r9, r5 */
/* @0x1a9f34 bne 0x1a9f48 <_ZN6CLayer9SerializeEP7IBuffer+0xb20> */
/* @0x1a9f38 b 0x1aa1ec <_ZN6CLayer9SerializeEP7IBuffer+0xdc4> */
/* @0x1a9f3c ldr r9, [r9, #0x14] */
/* @0x1a9f40 cmp r9, #0 */
/* @0x1a9f44 beq 0x1aa1ec <_ZN6CLayer9SerializeEP7IBuffer+0xdc4> */
/* @0x1a9f48 ldr r3, [r9] */
/* @0x1a9f4c cmp r3, #7 */
/* @0x1a9f50 bne 0x1a9f3c <_ZN6CLayer9SerializeEP7IBuffer+0xb14> */
/* @0x1a9f54 ldrb r6, [r9, #0x1c] */
/* @0x1a9f58 mov r1, #6 */
/* @0x1a9f5c ldr r3, [r4] */
/* @0x1a9f60 mov r2, r8 */
/* @0x1a9f64 mov r0, r4 */
/* @0x1a9f68 str r5, [r4, #0x38] */
/* @0x1a9f6c vmov s15, r6 */
/* @0x1a9f70 vcvt.f64.u32 d7, s15 */
/* @0x1a9f74 vmov r6, r7, d7 */
/* @0x1a9f78 vstr s14, [r4, #44] */
/* @0x1a9f7c str r7, [r4, #0x30] */
/* @0x1a9f80 ldr r3, [r3, #0x8] */
/* @0x1a9f84 blx r3 */
/* @0x1a9f88 ldr r6, [r9, #0x20] */
/* @0x1a9f8c ldr r3, [r4] */
/* @0x1a9f90 mov r1, #6 */
/* @0x1a9f94 mov r2, r8 */
/* @0x1a9f98 mov r0, r4 */
/* @0x1a9f9c vmov s13, r6 */
/* @0x1a9fa0 str r5, [r4, #0x38] */
/* @0x1a9fa4 vcvt.f64.s32 d6, s13 */
/* @0x1a9fa8 vmov r6, r7, d6 */
/* @0x1a9fac vstr s12, [r4, #44] */
/* @0x1a9fb0 str r7, [r4, #0x30] */
/* @0x1a9fb4 ldr r3, [r3, #0x8] */
/* @0x1a9fb8 blx r3 */
/* @0x1a9fbc vldr s15, [r9, #36] */
/* @0x1a9fc0 vcvt.f64.f32 d6, s15 */
/* @0x1a9fc4 ldr r3, [r4] */
/* @0x1a9fc8 mov r1, #8 */
/* @0x1a9fcc mov r2, r8 */
/* @0x1a9fd0 str r5, [r4, #0x38] */
/* @0x1a9fd4 mov r0, r4 */
/* @0x1a9fd8 vmov r6, r7, d6 */
/* @0x1a9fdc vstr s12, [r4, #44] */
/* @0x1a9fe0 str r7, [r4, #0x30] */
/* @0x1a9fe4 ldr r3, [r3, #0x8] */
/* @0x1a9fe8 blx r3 */
/* @0x1a9fec vldr s15, [r9, #40] */
/* @0x1a9ff0 vcvt.f64.f32 d6, s15 */
/* @0x1a9ff4 ldr r3, [r4] */
/* @0x1a9ff8 mov r1, #8 */
/* @0x1a9ffc mov r2, r8 */
/* @0x1aa000 str r5, [r4, #0x38] */
/* @0x1aa004 mov r0, r4 */
/* @0x1aa008 vmov r6, r7, d6 */
/* @0x1aa00c vstr s12, [r4, #44] */
/* @0x1aa010 str r7, [r4, #0x30] */
/* @0x1aa014 ldr r3, [r3, #0x8] */
/* @0x1aa018 blx r3 */
/* @0x1aa01c ldr r6, [r9, #0x2c] */
/* @0x1aa020 ldr r3, [r4] */
/* @0x1aa024 mov r1, #6 */
/* @0x1aa028 mov r2, r8 */
/* @0x1aa02c mov r0, r4 */
/* @0x1aa030 vmov s15, r6 */
/* @0x1aa034 str r5, [r4, #0x38] */
/* @0x1aa038 vcvt.f64.s32 d7, s15 */
/* @0x1aa03c vmov r6, r7, d7 */
/* @0x1aa040 vstr s14, [r4, #44] */
/* @0x1aa044 str r7, [r4, #0x30] */
/* @0x1aa048 ldr r3, [r3, #0x8] */
/* @0x1aa04c blx r3 */
/* @0x1aa050 ldr r6, [r9, #0x30] */
/* @0x1aa054 ldr r3, [r4] */
/* @0x1aa058 mov r1, #6 */
/* @0x1aa05c mov r2, r8 */
/* @0x1aa060 mov r0, r4 */
/* @0x1aa064 vmov s13, r6 */
/* @0x1aa068 str r5, [r4, #0x38] */
/* @0x1aa06c vcvt.f64.s32 d6, s13 */
/* @0x1aa070 vmov r6, r7, d6 */
/* @0x1aa074 vstr s12, [r4, #44] */
/* @0x1aa078 str r7, [r4, #0x30] */
/* @0x1aa07c ldr r3, [r3, #0x8] */
/* @0x1aa080 blx r3 */
/* @0x1aa084 vldr s15, [r9, #52] */
/* @0x1aa088 vcvt.f64.f32 d6, s15 */
/* @0x1aa08c ldr r3, [r4] */
/* @0x1aa090 mov r1, #8 */
/* @0x1aa094 mov r2, r8 */
/* @0x1aa098 str r5, [r4, #0x38] */
/* @0x1aa09c mov r0, r4 */
/* @0x1aa0a0 vmov r6, r7, d6 */
/* @0x1aa0a4 vstr s12, [r4, #44] */
/* @0x1aa0a8 str r7, [r4, #0x30] */
/* @0x1aa0ac ldr r3, [r3, #0x8] */
/* @0x1aa0b0 blx r3 */
/* @0x1aa0b4 vldr s15, [r9, #56] */
/* @0x1aa0b8 vcvt.f64.f32 d6, s15 */
/* @0x1aa0bc ldr r3, [r4] */
/* @0x1aa0c0 mov r1, #8 */
/* @0x1aa0c4 mov r2, r8 */
/* @0x1aa0c8 str r5, [r4, #0x38] */
/* @0x1aa0cc mov r0, r4 */
/* @0x1aa0d0 vmov r6, r7, d6 */
/* @0x1aa0d4 vstr s12, [r4, #44] */
/* @0x1aa0d8 str r7, [r4, #0x30] */
/* @0x1aa0dc ldr r3, [r3, #0x8] */
/* @0x1aa0e0 blx r3 */
/* @0x1aa0e4 vldr s15, [r9, #60] */
/* @0x1aa0e8 vcvt.f64.f32 d6, s15 */
/* @0x1aa0ec ldr r3, [r4] */
/* @0x1aa0f0 mov r1, #8 */
/* @0x1aa0f4 mov r2, r8 */
/* @0x1aa0f8 str r5, [r4, #0x38] */
/* @0x1aa0fc mov r0, r4 */
/* @0x1aa100 vmov r6, r7, d6 */
/* @0x1aa104 vstr s12, [r4, #44] */
/* @0x1aa108 str r7, [r4, #0x30] */
/* @0x1aa10c ldr r3, [r3, #0x8] */
/* @0x1aa110 blx r3 */
/* @0x1aa114 ldr r6, [r9, #0x40] */
/* @0x1aa118 ldr r3, [r4] */
/* @0x1aa11c mov r1, #5 */
/* @0x1aa120 mov r2, r8 */
/* @0x1aa124 mov r0, r4 */
/* @0x1aa128 vmov s15, r6 */
/* @0x1aa12c str r5, [r4, #0x38] */
/* @0x1aa130 vcvt.f64.u32 d7, s15 */
/* @0x1aa134 vmov r6, r7, d7 */
/* @0x1aa138 vstr s14, [r4, #44] */
/* @0x1aa13c str r7, [r4, #0x30] */
/* @0x1aa140 ldr r3, [r3, #0x8] */
/* @0x1aa144 blx r3 */
/* @0x1aa148 vldr s15, [r9, #68] */
/* @0x1aa14c vcvt.f64.f32 d6, s15 */
/* @0x1aa150 ldr r3, [r4] */
/* @0x1aa154 mov r1, #8 */
/* @0x1aa158 mov r2, r8 */
/* @0x1aa15c str r5, [r4, #0x38] */
/* @0x1aa160 mov r0, r4 */
/* @0x1aa164 vmov r6, r7, d6 */
/* @0x1aa168 vstr s12, [r4, #44] */
/* @0x1aa16c str r7, [r4, #0x30] */
/* @0x1aa170 ldr r3, [r3, #0x8] */
/* @0x1aa174 blx r3 */
/* @0x1aa178 ldr r6, [r9, #0x48] */
/* @0x1aa17c ldr r3, [r4] */
/* @0x1aa180 mov r1, #6 */
/* @0x1aa184 mov r2, r8 */
/* @0x1aa188 mov r0, r4 */
/* @0x1aa18c vmov s15, r6 */
/* @0x1aa190 str r5, [r4, #0x38] */
/* @0x1aa194 vcvt.f64.s32 d7, s15 */
/* @0x1aa198 vmov r6, r7, d7 */
/* @0x1aa19c vstr s14, [r4, #44] */
/* @0x1aa1a0 str r7, [r4, #0x30] */
/* @0x1aa1a4 ldr r3, [r3, #0x8] */
/* @0x1aa1a8 blx r3 */
/* @0x1aa1ac ldr r6, [r9, #0x4c] */
/* @0x1aa1b0 ldr r3, [r4] */
/* @0x1aa1b4 mov r0, r4 */
/* @0x1aa1b8 str r5, [r4, #0x38] */
/* @0x1aa1bc mov r1, #6 */
/* @0x1aa1c0 vmov s13, r6 */
/* @0x1aa1c4 mov r2, r8 */
/* @0x1aa1c8 vcvt.f64.s32 d6, s13 */
/* @0x1aa1cc vmov r6, r7, d6 */
/* @0x1aa1d0 vstr s12, [r4, #44] */
/* @0x1aa1d4 str r7, [r4, #0x30] */
/* @0x1aa1d8 ldr r3, [r3, #0x8] */
/* @0x1aa1dc blx r3 */
/* @0x1aa1e0 ldr r9, [r9, #0x14] */
/* @0x1aa1e4 cmp r9, #0 */
/* @0x1aa1e8 bne 0x1a9f48 <_ZN6CLayer9SerializeEP7IBuffer+0xb20> */
/* @0x1aa1ec add sp, sp, #28 */
/* @0x1aa1f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1aa1f4 add r7, r7, #1 */
/* @0x1aa1f8 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1aa1fc add r2, r2, #1 */
/* @0x1aa200 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1aa204 add r0, r0, #1 */
/* @0x1aa208 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8> */
/* @0x1aa20c str r3, [sp, #0x10] */
/* @0x1aa210 mov r2, #0 */
/* @0x1aa214 ldr r1, [sp, #0x10] */
/* @0x1aa218 mov r3, #0 */
/* @0x1aa21c str r1, [sp, #0x14] */
/* @0x1aa220 mov r7, r1 */
/* @0x1aa224 b 0x1a9720 <_ZN6CLayer9SerializeEP7IBuffer+0x2f8> */

/* ── FUNC 0x1aa228 · CRoom::Serialise(IBuffer*) · size=2856 · insn=714 */
/* @0x1aa228 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aa22c mov r9, r0 */
/* @0x1aa230 ldrb r3, [r0, #0x70] */
/* @0x1aa234 mov r6, r1 */
/* @0x1aa238 cmp r3, #0 */
/* @0x1aa23c bne 0x1aad38 <_ZN5CRoom9SerialiseEP7IBuffer+0xb10> */
/* @0x1aa240 ldr r1, [r9, #0x8] */
/* @0x1aa244 mov r0, r6 */
/* @0x1aa248 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1aa24c vldr s12, [r9, #16] */
/* @0x1aa250 vcvt.f64.s32 d7, s12 */
/* @0x1aa254 ldr r12, [r6] */
/* @0x1aa258 add r7, r6, #44 */
/* @0x1aa25c mov r5, #0 */
/* @0x1aa260 mov r1, #6 */
/* @0x1aa264 str r5, [r6, #0x38] */
/* @0x1aa268 mov r2, r7 */
/* @0x1aa26c mov r0, r6 */
/* @0x1aa270 mov r10, r5 */
/* @0x1aa274 mov r8, r5 */
/* @0x1aa278 mov r11, r9 */
/* @0x1aa27c vstr s14, [r6, #44] */
/* @0x1aa280 vstr s15, [r6, #48] */
/* @0x1aa284 ldr r12, [r12, #0x8] */
/* @0x1aa288 blx r12 */
/* @0x1aa28c vldr s14, [r9, #20] */
/* @0x1aa290 vcvt.f64.s32 d7, s14 */
/* @0x1aa294 ldr r12, [r6] */
/* @0x1aa298 mov r2, r7 */
/* @0x1aa29c str r5, [r6, #0x38] */
/* @0x1aa2a0 mov r1, #6 */
/* @0x1aa2a4 mov r0, r6 */
/* @0x1aa2a8 vstr s14, [r6, #44] */
/* @0x1aa2ac vstr s15, [r6, #48] */
/* @0x1aa2b0 ldr r12, [r12, #0x8] */
/* @0x1aa2b4 blx r12 */
/* @0x1aa2b8 vldr s14, [r9, #12] */
/* @0x1aa2bc vcvt.f64.s32 d7, s14 */
/* @0x1aa2c0 ldr r12, [r6] */
/* @0x1aa2c4 mov r2, r7 */
/* @0x1aa2c8 str r5, [r6, #0x38] */
/* @0x1aa2cc mov r1, #6 */
/* @0x1aa2d0 mov r0, r6 */
/* @0x1aa2d4 vstr s14, [r6, #44] */
/* @0x1aa2d8 vstr s15, [r6, #48] */
/* @0x1aa2dc ldr r12, [r12, #0x8] */
/* @0x1aa2e0 blx r12 */
/* @0x1aa2e4 ldrb r2, [r9, #0x18] */
/* @0x1aa2e8 ldr r12, [r6] */
/* @0x1aa2ec mov r1, #6 */
/* @0x1aa2f0 str r5, [r6, #0x38] */
/* @0x1aa2f4 mov r0, r6 */
/* @0x1aa2f8 vmov s14, r2 */
/* @0x1aa2fc mov r2, r7 */
/* @0x1aa300 vcvt.f64.u32 d7, s14 */
/* @0x1aa304 vstr s14, [r6, #44] */
/* @0x1aa308 vstr s15, [r6, #48] */
/* @0x1aa30c ldr r12, [r12, #0x8] */
/* @0x1aa310 blx r12 */
/* @0x1aa314 vldr s14, [r9, #28] */
/* @0x1aa318 vcvt.f64.u32 d7, s14 */
/* @0x1aa31c ldr r12, [r6] */
/* @0x1aa320 mov r2, r7 */
/* @0x1aa324 str r5, [r6, #0x38] */
/* @0x1aa328 mov r1, #5 */
/* @0x1aa32c mov r0, r6 */
/* @0x1aa330 vstr s14, [r6, #44] */
/* @0x1aa334 vstr s15, [r6, #48] */
/* @0x1aa338 ldr r12, [r12, #0x8] */
/* @0x1aa33c blx r12 */
/* @0x1aa340 ldrb r4, [r9, #0x20] */
/* @0x1aa344 str r5, [r6, #0x38] */
/* @0x1aa348 mov r1, #6 */
/* @0x1aa34c ldr r12, [r6] */
/* @0x1aa350 mov r2, r7 */
/* @0x1aa354 vmov s13, r4 */
/* @0x1aa358 mov r0, r6 */
/* @0x1aa35c vcvt.f64.u32 d6, s13 */
/* @0x1aa360 vmov r4, r5, d6 */
/* @0x1aa364 vstr s12, [r6, #44] */
/* @0x1aa368 str r5, [r6, #0x30] */
/* @0x1aa36c ldr r12, [r12, #0x8] */
/* @0x1aa370 blx r12 */
/* @0x1aa374 mov r0, r6 */
/* @0x1aa378 ldr r1, [r9, #0x68] */
/* @0x1aa37c bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1aa380 ldr r4, [r11, #0x24] */
/* @0x1aa384 mov r1, #6 */
/* @0x1aa388 ldr r12, [r6] */
/* @0x1aa38c mov r0, r6 */
/* @0x1aa390 add r10, r10, #1 */
/* @0x1aa394 add r11, r11, #4 */
/* @0x1aa398 ldrb r2, [r4] */
/* @0x1aa39c str r8, [r6, #0x38] */
/* @0x1aa3a0 vmov s14, r2 */
/* @0x1aa3a4 mov r2, r7 */
/* @0x1aa3a8 vcvt.f64.u32 d7, s14 */
/* @0x1aa3ac vstr s14, [r6, #44] */
/* @0x1aa3b0 vstr s15, [r6, #48] */
/* @0x1aa3b4 ldr r12, [r12, #0x8] */
/* @0x1aa3b8 blx r12 */
/* @0x1aa3bc ldrb r3, [r4, #0x1] */
/* @0x1aa3c0 ldr r12, [r6] */
/* @0x1aa3c4 mov r1, #6 */
/* @0x1aa3c8 mov r2, r7 */
/* @0x1aa3cc mov r0, r6 */
/* @0x1aa3d0 vmov s14, r3 */
/* @0x1aa3d4 str r8, [r6, #0x38] */
/* @0x1aa3d8 vcvt.f64.u32 d7, s14 */
/* @0x1aa3dc vstr s14, [r6, #44] */
/* @0x1aa3e0 vstr s15, [r6, #48] */
/* @0x1aa3e4 ldr r12, [r12, #0x8] */
/* @0x1aa3e8 blx r12 */
/* @0x1aa3ec vldr s14, [r4, #4] */
/* @0x1aa3f0 vcvt.f64.s32 d7, s14 */
/* @0x1aa3f4 ldr r12, [r6] */
/* @0x1aa3f8 mov r1, #6 */
/* @0x1aa3fc mov r2, r7 */
/* @0x1aa400 mov r0, r6 */
/* @0x1aa404 str r8, [r6, #0x38] */
/* @0x1aa408 vstr s14, [r6, #44] */
/* @0x1aa40c vstr s15, [r6, #48] */
/* @0x1aa410 ldr r12, [r12, #0x8] */
/* @0x1aa414 blx r12 */
/* @0x1aa418 vldr s14, [r4, #8] */
/* @0x1aa41c vcvt.f64.f32 d7, s14 */
/* @0x1aa420 ldr r12, [r6] */
/* @0x1aa424 mov r1, #8 */
/* @0x1aa428 mov r2, r7 */
/* @0x1aa42c str r8, [r6, #0x38] */
/* @0x1aa430 mov r0, r6 */
/* @0x1aa434 vstr s14, [r6, #44] */
/* @0x1aa438 vstr s15, [r6, #48] */
/* @0x1aa43c ldr r12, [r12, #0x8] */
/* @0x1aa440 blx r12 */
/* @0x1aa444 vldr s14, [r4, #12] */
/* @0x1aa448 vcvt.f64.f32 d7, s14 */
/* @0x1aa44c ldr r12, [r6] */
/* @0x1aa450 mov r1, #8 */
/* @0x1aa454 mov r2, r7 */
/* @0x1aa458 str r8, [r6, #0x38] */
/* @0x1aa45c mov r0, r6 */
/* @0x1aa460 vstr s14, [r6, #44] */
/* @0x1aa464 vstr s15, [r6, #48] */
/* @0x1aa468 ldr r12, [r12, #0x8] */
/* @0x1aa46c blx r12 */
/* @0x1aa470 ldrb r2, [r4, #0x10] */
/* @0x1aa474 ldr r12, [r6] */
/* @0x1aa478 mov r1, #6 */
/* @0x1aa47c mov r0, r6 */
/* @0x1aa480 str r8, [r6, #0x38] */
/* @0x1aa484 vmov s14, r2 */
/* @0x1aa488 mov r2, r7 */
/* @0x1aa48c vcvt.f64.u32 d7, s14 */
/* @0x1aa490 vstr s14, [r6, #44] */
/* @0x1aa494 vstr s15, [r6, #48] */
/* @0x1aa498 ldr r12, [r12, #0x8] */
/* @0x1aa49c blx r12 */
/* @0x1aa4a0 ldrb r3, [r4, #0x11] */
/* @0x1aa4a4 ldr r12, [r6] */
/* @0x1aa4a8 mov r1, #6 */
/* @0x1aa4ac mov r2, r7 */
/* @0x1aa4b0 mov r0, r6 */
/* @0x1aa4b4 vmov s14, r3 */
/* @0x1aa4b8 str r8, [r6, #0x38] */
/* @0x1aa4bc vcvt.f64.u32 d7, s14 */
/* @0x1aa4c0 vstr s14, [r6, #44] */
/* @0x1aa4c4 vstr s15, [r6, #48] */
/* @0x1aa4c8 ldr r12, [r12, #0x8] */
/* @0x1aa4cc blx r12 */
/* @0x1aa4d0 vldr s14, [r4, #20] */
/* @0x1aa4d4 vcvt.f64.f32 d7, s14 */
/* @0x1aa4d8 ldr r12, [r6] */
/* @0x1aa4dc mov r1, #8 */
/* @0x1aa4e0 mov r2, r7 */
/* @0x1aa4e4 str r8, [r6, #0x38] */
/* @0x1aa4e8 mov r0, r6 */
/* @0x1aa4ec vstr s14, [r6, #44] */
/* @0x1aa4f0 vstr s15, [r6, #48] */
/* @0x1aa4f4 ldr r12, [r12, #0x8] */
/* @0x1aa4f8 blx r12 */
/* @0x1aa4fc vldr s14, [r4, #24] */
/* @0x1aa500 vcvt.f64.f32 d7, s14 */
/* @0x1aa504 ldr r12, [r6] */
/* @0x1aa508 mov r1, #8 */
/* @0x1aa50c mov r2, r7 */
/* @0x1aa510 str r8, [r6, #0x38] */
/* @0x1aa514 mov r0, r6 */
/* @0x1aa518 vstr s14, [r6, #44] */
/* @0x1aa51c vstr s15, [r6, #48] */
/* @0x1aa520 ldr r12, [r12, #0x8] */
/* @0x1aa524 blx r12 */
/* @0x1aa528 vldr s14, [r4, #28] */
/* @0x1aa52c vcvt.f64.f32 d7, s14 */
/* @0x1aa530 ldr r12, [r6] */
/* @0x1aa534 mov r1, #8 */
/* @0x1aa538 mov r2, r7 */
/* @0x1aa53c str r8, [r6, #0x38] */
/* @0x1aa540 mov r0, r6 */
/* @0x1aa544 vstr s14, [r6, #44] */
/* @0x1aa548 vstr s15, [r6, #48] */
/* @0x1aa54c ldr r12, [r12, #0x8] */
/* @0x1aa550 blx r12 */
/* @0x1aa554 vldr s14, [r4, #32] */
/* @0x1aa558 vcvt.f64.f32 d7, s14 */
/* @0x1aa55c ldr r12, [r6] */
/* @0x1aa560 mov r1, #8 */
/* @0x1aa564 mov r2, r7 */
/* @0x1aa568 str r8, [r6, #0x38] */
/* @0x1aa56c mov r0, r6 */
/* @0x1aa570 vstr s14, [r6, #44] */
/* @0x1aa574 vstr s15, [r6, #48] */
/* @0x1aa578 ldr r12, [r12, #0x8] */
/* @0x1aa57c blx r12 */
/* @0x1aa580 vldr s14, [r4, #36] */
/* @0x1aa584 vcvt.f64.s32 d7, s14 */
/* @0x1aa588 ldr r12, [r6] */
/* @0x1aa58c mov r1, #6 */
/* @0x1aa590 mov r2, r7 */
/* @0x1aa594 mov r0, r6 */
/* @0x1aa598 str r8, [r6, #0x38] */
/* @0x1aa59c vstr s14, [r6, #44] */
/* @0x1aa5a0 vstr s15, [r6, #48] */
/* @0x1aa5a4 ldr r12, [r12, #0x8] */
/* @0x1aa5a8 blx r12 */
/* @0x1aa5ac vldr s15, [r4, #40] */
/* @0x1aa5b0 vcvt.f64.f32 d6, s15 */
/* @0x1aa5b4 ldr r12, [r6] */
/* @0x1aa5b8 str r8, [r6, #0x38] */
/* @0x1aa5bc mov r0, r6 */
/* @0x1aa5c0 mov r1, #8 */
/* @0x1aa5c4 mov r2, r7 */
/* @0x1aa5c8 vmov r4, r5, d6 */
/* @0x1aa5cc vstr s12, [r6, #44] */
/* @0x1aa5d0 str r5, [r6, #0x30] */
/* @0x1aa5d4 ldr r12, [r12, #0x8] */
/* @0x1aa5d8 blx r12 */
/* @0x1aa5dc cmp r10, #8 */
/* @0x1aa5e0 bne 0x1aa380 <_ZN5CRoom9SerialiseEP7IBuffer+0x158> */
/* @0x1aa5e4 ldrb r4, [r9, #0x44] */
/* @0x1aa5e8 mov r2, #0 */
/* @0x1aa5ec ldr r12, [r6] */
/* @0x1aa5f0 mov r11, #0 */
/* @0x1aa5f4 str r2, [r6, #0x38] */
/* @0x1aa5f8 mov r0, r6 */
/* @0x1aa5fc vmov s13, r4 */
/* @0x1aa600 mov r1, #6 */
/* @0x1aa604 mov r2, r7 */
/* @0x1aa608 mov r8, r11 */
/* @0x1aa60c vcvt.f64.u32 d6, s13 */
/* @0x1aa610 mov r10, r9 */
/* @0x1aa614 vmov r4, r5, d6 */
/* @0x1aa618 vstr s12, [r6, #44] */
/* @0x1aa61c str r5, [r6, #0x30] */
/* @0x1aa620 ldr r12, [r12, #0x8] */
/* @0x1aa624 blx r12 */
/* @0x1aa628 ldr r4, [r10, #0x48] */
/* @0x1aa62c mov r1, #6 */
/* @0x1aa630 ldr r12, [r6] */
/* @0x1aa634 mov r0, r6 */
/* @0x1aa638 add r11, r11, #1 */
/* @0x1aa63c add r10, r10, #4 */
/* @0x1aa640 ldrb r2, [r4] */
/* @0x1aa644 str r8, [r6, #0x38] */
/* @0x1aa648 vmov s14, r2 */
/* @0x1aa64c mov r2, r7 */
/* @0x1aa650 vcvt.f64.u32 d7, s14 */
/* @0x1aa654 vstr s14, [r6, #44] */
/* @0x1aa658 vstr s15, [r6, #48] */
/* @0x1aa65c ldr r12, [r12, #0x8] */
/* @0x1aa660 blx r12 */
/* @0x1aa664 vldr s14, [r4, #4] */
/* @0x1aa668 vcvt.s32.f32 s14, s14 */
/* @0x1aa66c ldr r12, [r6] */
/* @0x1aa670 mov r1, #6 */
/* @0x1aa674 mov r2, r7 */
/* @0x1aa678 str r8, [r6, #0x38] */
/* @0x1aa67c mov r0, r6 */
/* @0x1aa680 vcvt.f64.s32 d7, s14 */
/* @0x1aa684 vstr s14, [r6, #44] */
/* @0x1aa688 vstr s15, [r6, #48] */
/* @0x1aa68c ldr r12, [r12, #0x8] */
/* @0x1aa690 blx r12 */
/* @0x1aa694 vldr s14, [r4, #8] */
/* @0x1aa698 vcvt.s32.f32 s14, s14 */
/* @0x1aa69c ldr r12, [r6] */
/* @0x1aa6a0 mov r1, #6 */
/* @0x1aa6a4 mov r2, r7 */
/* @0x1aa6a8 str r8, [r6, #0x38] */
/* @0x1aa6ac mov r0, r6 */
/* @0x1aa6b0 vcvt.f64.s32 d7, s14 */
/* @0x1aa6b4 vstr s14, [r6, #44] */
/* @0x1aa6b8 vstr s15, [r6, #48] */
/* @0x1aa6bc ldr r12, [r12, #0x8] */
/* @0x1aa6c0 blx r12 */
/* @0x1aa6c4 vldr s14, [r4, #12] */
/* @0x1aa6c8 vcvt.s32.f32 s14, s14 */
/* @0x1aa6cc ldr r12, [r6] */
/* @0x1aa6d0 mov r1, #6 */
/* @0x1aa6d4 mov r2, r7 */
/* @0x1aa6d8 str r8, [r6, #0x38] */
/* @0x1aa6dc mov r0, r6 */
/* @0x1aa6e0 vcvt.f64.s32 d7, s14 */
/* @0x1aa6e4 vstr s14, [r6, #44] */
/* @0x1aa6e8 vstr s15, [r6, #48] */
/* @0x1aa6ec ldr r12, [r12, #0x8] */
/* @0x1aa6f0 blx r12 */
/* @0x1aa6f4 vldr s14, [r4, #16] */
/* @0x1aa6f8 vcvt.s32.f32 s14, s14 */
/* @0x1aa6fc ldr r12, [r6] */
/* @0x1aa700 mov r1, #6 */
/* @0x1aa704 mov r2, r7 */
/* @0x1aa708 str r8, [r6, #0x38] */
/* @0x1aa70c mov r0, r6 */
/* @0x1aa710 vcvt.f64.s32 d7, s14 */
/* @0x1aa714 vstr s14, [r6, #44] */
/* @0x1aa718 vstr s15, [r6, #48] */
/* @0x1aa71c ldr r12, [r12, #0x8] */
/* @0x1aa720 blx r12 */
/* @0x1aa724 vldr s14, [r4, #20] */
/* @0x1aa728 vcvt.f64.s32 d7, s14 */
/* @0x1aa72c ldr r12, [r6] */
/* @0x1aa730 mov r1, #6 */
/* @0x1aa734 mov r2, r7 */
/* @0x1aa738 mov r0, r6 */
/* @0x1aa73c str r8, [r6, #0x38] */
/* @0x1aa740 vstr s14, [r6, #44] */
/* @0x1aa744 vstr s15, [r6, #48] */
/* @0x1aa748 ldr r12, [r12, #0x8] */
/* @0x1aa74c blx r12 */
/* @0x1aa750 vldr s14, [r4, #24] */
/* @0x1aa754 vcvt.f64.s32 d7, s14 */
/* @0x1aa758 ldr r12, [r6] */
/* @0x1aa75c mov r1, #6 */
/* @0x1aa760 mov r2, r7 */
/* @0x1aa764 mov r0, r6 */
/* @0x1aa768 str r8, [r6, #0x38] */
/* @0x1aa76c vstr s14, [r6, #44] */
/* @0x1aa770 vstr s15, [r6, #48] */
/* @0x1aa774 ldr r12, [r12, #0x8] */
/* @0x1aa778 blx r12 */
/* @0x1aa77c vldr s14, [r4, #28] */
/* @0x1aa780 vcvt.f64.s32 d7, s14 */
/* @0x1aa784 ldr r12, [r6] */
/* @0x1aa788 mov r1, #6 */
/* @0x1aa78c mov r2, r7 */
/* @0x1aa790 mov r0, r6 */
/* @0x1aa794 str r8, [r6, #0x38] */
/* @0x1aa798 vstr s14, [r6, #44] */
/* @0x1aa79c vstr s15, [r6, #48] */
/* @0x1aa7a0 ldr r12, [r12, #0x8] */
/* @0x1aa7a4 blx r12 */
/* @0x1aa7a8 vldr s14, [r4, #32] */
/* @0x1aa7ac vcvt.f64.s32 d7, s14 */
/* @0x1aa7b0 ldr r12, [r6] */
/* @0x1aa7b4 mov r1, #6 */
/* @0x1aa7b8 mov r2, r7 */
/* @0x1aa7bc mov r0, r6 */
/* @0x1aa7c0 str r8, [r6, #0x38] */
/* @0x1aa7c4 vstr s14, [r6, #44] */
/* @0x1aa7c8 vstr s15, [r6, #48] */
/* @0x1aa7cc ldr r12, [r12, #0x8] */
/* @0x1aa7d0 blx r12 */
/* @0x1aa7d4 vldr s14, [r4, #36] */
/* @0x1aa7d8 vcvt.f64.f32 d7, s14 */
/* @0x1aa7dc ldr r12, [r6] */
/* @0x1aa7e0 mov r1, #8 */
/* @0x1aa7e4 mov r2, r7 */
/* @0x1aa7e8 str r8, [r6, #0x38] */
/* @0x1aa7ec mov r0, r6 */
/* @0x1aa7f0 vstr s14, [r6, #44] */
/* @0x1aa7f4 vstr s15, [r6, #48] */
/* @0x1aa7f8 ldr r12, [r12, #0x8] */
/* @0x1aa7fc blx r12 */
/* @0x1aa800 vldr s14, [r4, #40] */
/* @0x1aa804 vcvt.f64.s32 d7, s14 */
/* @0x1aa808 ldr r12, [r6] */
/* @0x1aa80c mov r1, #6 */
/* @0x1aa810 mov r2, r7 */
/* @0x1aa814 mov r0, r6 */
/* @0x1aa818 str r8, [r6, #0x38] */
/* @0x1aa81c vstr s14, [r6, #44] */
/* @0x1aa820 vstr s15, [r6, #48] */
/* @0x1aa824 ldr r12, [r12, #0x8] */
/* @0x1aa828 blx r12 */
/* @0x1aa82c vldr s14, [r4, #44] */
/* @0x1aa830 vcvt.f64.s32 d7, s14 */
/* @0x1aa834 ldr r12, [r6] */
/* @0x1aa838 mov r1, #6 */
/* @0x1aa83c mov r2, r7 */
/* @0x1aa840 mov r0, r6 */
/* @0x1aa844 str r8, [r6, #0x38] */
/* @0x1aa848 vstr s14, [r6, #44] */
/* @0x1aa84c vstr s15, [r6, #48] */
/* @0x1aa850 ldr r12, [r12, #0x8] */
/* @0x1aa854 blx r12 */
/* @0x1aa858 vldr s14, [r4, #48] */
/* @0x1aa85c vcvt.f64.s32 d7, s14 */
/* @0x1aa860 ldr r12, [r6] */
/* @0x1aa864 mov r1, #6 */
/* @0x1aa868 mov r2, r7 */
/* @0x1aa86c mov r0, r6 */
/* @0x1aa870 str r8, [r6, #0x38] */
/* @0x1aa874 vstr s14, [r6, #44] */
/* @0x1aa878 vstr s15, [r6, #48] */
/* @0x1aa87c ldr r12, [r12, #0x8] */
/* @0x1aa880 blx r12 */
/* @0x1aa884 vldr s14, [r4, #52] */
/* @0x1aa888 vcvt.f64.s32 d7, s14 */
/* @0x1aa88c ldr r12, [r6] */
/* @0x1aa890 mov r1, #6 */
/* @0x1aa894 mov r2, r7 */
/* @0x1aa898 mov r0, r6 */
/* @0x1aa89c str r8, [r6, #0x38] */
/* @0x1aa8a0 vstr s14, [r6, #44] */
/* @0x1aa8a4 vstr s15, [r6, #48] */
/* @0x1aa8a8 ldr r12, [r12, #0x8] */
/* @0x1aa8ac blx r12 */
/* @0x1aa8b0 vldr s14, [r4, #56] */
/* @0x1aa8b4 vcvt.f64.s32 d7, s14 */
/* @0x1aa8b8 ldr r12, [r6] */
/* @0x1aa8bc mov r1, #6 */
/* @0x1aa8c0 mov r2, r7 */
/* @0x1aa8c4 mov r0, r6 */
/* @0x1aa8c8 str r8, [r6, #0x38] */
/* @0x1aa8cc vstr s14, [r6, #44] */
/* @0x1aa8d0 vstr s15, [r6, #48] */
/* @0x1aa8d4 ldr r12, [r12, #0x8] */
/* @0x1aa8d8 blx r12 */
/* @0x1aa8dc vldr s14, [r4, #60] */
/* @0x1aa8e0 vcvt.f64.s32 d7, s14 */
/* @0x1aa8e4 ldr r12, [r6] */
/* @0x1aa8e8 mov r1, #6 */
/* @0x1aa8ec mov r2, r7 */
/* @0x1aa8f0 mov r0, r6 */
/* @0x1aa8f4 str r8, [r6, #0x38] */
/* @0x1aa8f8 vstr s14, [r6, #44] */
/* @0x1aa8fc vstr s15, [r6, #48] */
/* @0x1aa900 ldr r12, [r12, #0x8] */
/* @0x1aa904 blx r12 */
/* @0x1aa908 ldr r4, [r4, #0x40] */
/* @0x1aa90c ldr r12, [r6] */
/* @0x1aa910 mov r0, r6 */
/* @0x1aa914 str r8, [r6, #0x38] */
/* @0x1aa918 mov r1, #6 */
/* @0x1aa91c vmov s13, r4 */
/* @0x1aa920 mov r2, r7 */
/* @0x1aa924 vcvt.f64.s32 d6, s13 */
/* @0x1aa928 vmov r4, r5, d6 */
/* @0x1aa92c vstr s12, [r6, #44] */
/* @0x1aa930 str r5, [r6, #0x30] */
/* @0x1aa934 ldr r12, [r12, #0x8] */
/* @0x1aa938 blx r12 */
/* @0x1aa93c cmp r11, #8 */
/* @0x1aa940 bne 0x1aa628 <_ZN5CRoom9SerialiseEP7IBuffer+0x400> */
/* @0x1aa944 ldr r4, [r9, #0xb8] */
/* @0x1aa948 mov r2, #0 */
/* @0x1aa94c ldr r3, [r6] */
/* @0x1aa950 mov r0, r6 */
/* @0x1aa954 str r2, [r6, #0x38] */
/* @0x1aa958 mov r1, #6 */
/* @0x1aa95c vmov s13, r4 */
/* @0x1aa960 mov r2, r7 */
/* @0x1aa964 vcvt.f64.s32 d6, s13 */
/* @0x1aa968 vmov r4, r5, d6 */
/* @0x1aa96c vstr s12, [r6, #44] */
/* @0x1aa970 str r5, [r6, #0x30] */
/* @0x1aa974 ldr r3, [r3, #0x8] */
/* @0x1aa978 blx r3 */
/* @0x1aa97c ldr r3, [r9, #0xb8] */
/* @0x1aa980 cmp r3, #0 */
/* @0x1aa984 movgt r10, #0 */
/* @0x1aa988 movgt r11, r10 */
/* @0x1aa98c movgt r8, r10 */
/* @0x1aa990 ble 0x1aac20 <_ZN5CRoom9SerialiseEP7IBuffer+0x9f8> */
/* @0x1aa994 ldr r4, [r9, #0xc0] */
/* @0x1aa998 mov r1, #8 */
/* @0x1aa99c ldr r3, [r6] */
/* @0x1aa9a0 mov r2, r7 */
/* @0x1aa9a4 add r4, r4, r10 */
/* @0x1aa9a8 vldr s14, [r4] */
/* @0x1aa9ac vcvt.f64.f32 d7, s14 */
/* @0x1aa9b0 mov r0, r6 */
/* @0x1aa9b4 str r8, [r6, #0x38] */
/* @0x1aa9b8 add r11, r11, #1 */
/* @0x1aa9bc add r10, r10, #56 */
/* @0x1aa9c0 vstr s14, [r6, #44] */
/* @0x1aa9c4 vstr s15, [r6, #48] */
/* @0x1aa9c8 ldr r3, [r3, #0x8] */
/* @0x1aa9cc blx r3 */
/* @0x1aa9d0 vldr s14, [r4, #4] */
/* @0x1aa9d4 vcvt.f64.f32 d7, s14 */
/* @0x1aa9d8 ldr r3, [r6] */
/* @0x1aa9dc mov r1, #8 */
/* @0x1aa9e0 mov r2, r7 */
/* @0x1aa9e4 str r8, [r6, #0x38] */
/* @0x1aa9e8 mov r0, r6 */
/* @0x1aa9ec vstr s14, [r6, #44] */
/* @0x1aa9f0 vstr s15, [r6, #48] */
/* @0x1aa9f4 ldr r3, [r3, #0x8] */
/* @0x1aa9f8 blx r3 */
/* @0x1aa9fc vldr s14, [r4, #8] */
/* @0x1aaa00 vcvt.f64.s32 d7, s14 */
/* @0x1aaa04 ldr r3, [r6] */
/* @0x1aaa08 mov r1, #6 */
/* @0x1aaa0c mov r2, r7 */
/* @0x1aaa10 mov r0, r6 */
/* @0x1aaa14 str r8, [r6, #0x38] */
/* @0x1aaa18 vstr s14, [r6, #44] */
/* @0x1aaa1c vstr s15, [r6, #48] */
/* @0x1aaa20 ldr r3, [r3, #0x8] */
/* @0x1aaa24 blx r3 */
/* @0x1aaa28 vldr s14, [r4, #12] */
/* @0x1aaa2c vcvt.f64.s32 d7, s14 */
/* @0x1aaa30 ldr r3, [r6] */
/* @0x1aaa34 mov r1, #6 */
/* @0x1aaa38 mov r2, r7 */
/* @0x1aaa3c mov r0, r6 */
/* @0x1aaa40 str r8, [r6, #0x38] */
/* @0x1aaa44 vstr s14, [r6, #44] */
/* @0x1aaa48 vstr s15, [r6, #48] */
/* @0x1aaa4c ldr r3, [r3, #0x8] */
/* @0x1aaa50 blx r3 */
/* @0x1aaa54 vldr s14, [r4, #16] */
/* @0x1aaa58 vcvt.f64.s32 d7, s14 */
/* @0x1aaa5c ldr r3, [r6] */
/* @0x1aaa60 mov r1, #6 */
/* @0x1aaa64 mov r2, r7 */
/* @0x1aaa68 mov r0, r6 */
/* @0x1aaa6c str r8, [r6, #0x38] */
/* @0x1aaa70 vstr s14, [r6, #44] */
/* @0x1aaa74 vstr s15, [r6, #48] */
/* @0x1aaa78 ldr r3, [r3, #0x8] */
/* @0x1aaa7c blx r3 */
/* @0x1aaa80 vldr s14, [r4, #20] */
/* @0x1aaa84 vcvt.f64.s32 d7, s14 */
/* @0x1aaa88 ldr r3, [r6] */
/* @0x1aaa8c mov r1, #6 */
/* @0x1aaa90 mov r2, r7 */
/* @0x1aaa94 mov r0, r6 */
/* @0x1aaa98 str r8, [r6, #0x38] */
/* @0x1aaa9c vstr s14, [r6, #44] */
/* @0x1aaaa0 vstr s15, [r6, #48] */
/* @0x1aaaa4 ldr r3, [r3, #0x8] */
/* @0x1aaaa8 blx r3 */
/* @0x1aaaac vldr s14, [r4, #24] */
/* @0x1aaab0 vcvt.f64.s32 d7, s14 */
/* @0x1aaab4 ldr r3, [r6] */
/* @0x1aaab8 mov r1, #6 */
/* @0x1aaabc mov r2, r7 */
/* @0x1aaac0 mov r0, r6 */
/* @0x1aaac4 str r8, [r6, #0x38] */
/* @0x1aaac8 vstr s14, [r6, #44] */
/* @0x1aaacc vstr s15, [r6, #48] */
/* @0x1aaad0 ldr r3, [r3, #0x8] */
/* @0x1aaad4 blx r3 */
/* @0x1aaad8 vldr s14, [r4, #28] */
/* @0x1aaadc vcvt.f64.f32 d7, s14 */
/* @0x1aaae0 ldr r3, [r6] */
/* @0x1aaae4 mov r1, #8 */
/* @0x1aaae8 mov r2, r7 */
/* @0x1aaaec str r8, [r6, #0x38] */
/* @0x1aaaf0 mov r0, r6 */
/* @0x1aaaf4 vstr s14, [r6, #44] */
/* @0x1aaaf8 vstr s15, [r6, #48] */
/* @0x1aaafc ldr r3, [r3, #0x8] */
/* @0x1aab00 blx r3 */
/* @0x1aab04 vldr s14, [r4, #32] */
/* @0x1aab08 vcvt.f64.s32 d7, s14 */
/* @0x1aab0c ldr r3, [r6] */
/* @0x1aab10 mov r1, #6 */
/* @0x1aab14 mov r2, r7 */
/* @0x1aab18 mov r0, r6 */
/* @0x1aab1c str r8, [r6, #0x38] */
/* @0x1aab20 vstr s14, [r6, #44] */
/* @0x1aab24 vstr s15, [r6, #48] */
/* @0x1aab28 ldr r3, [r3, #0x8] */
/* @0x1aab2c blx r3 */
/* @0x1aab30 vldr s14, [r4, #36] */
/* @0x1aab34 vcvt.f64.f32 d7, s14 */
/* @0x1aab38 ldr r3, [r6] */
/* @0x1aab3c mov r1, #8 */
/* @0x1aab40 mov r2, r7 */
/* @0x1aab44 str r8, [r6, #0x38] */
/* @0x1aab48 mov r0, r6 */
/* @0x1aab4c vstr s14, [r6, #44] */
/* @0x1aab50 vstr s15, [r6, #48] */
/* @0x1aab54 ldr r3, [r3, #0x8] */
/* @0x1aab58 blx r3 */
/* @0x1aab5c vldr s14, [r4, #40] */
/* @0x1aab60 vcvt.f64.f32 d7, s14 */
/* @0x1aab64 ldr r3, [r6] */
/* @0x1aab68 mov r1, #8 */
/* @0x1aab6c mov r2, r7 */
/* @0x1aab70 str r8, [r6, #0x38] */
/* @0x1aab74 mov r0, r6 */
/* @0x1aab78 vstr s14, [r6, #44] */
/* @0x1aab7c vstr s15, [r6, #48] */
/* @0x1aab80 ldr r3, [r3, #0x8] */
/* @0x1aab84 blx r3 */
/* @0x1aab88 vldr s14, [r4, #44] */
/* @0x1aab8c vcvt.f64.s32 d7, s14 */
/* @0x1aab90 ldr r3, [r6] */
/* @0x1aab94 mov r1, #6 */
/* @0x1aab98 mov r2, r7 */
/* @0x1aab9c mov r0, r6 */
/* @0x1aaba0 str r8, [r6, #0x38] */
/* @0x1aaba4 vstr s14, [r6, #44] */
/* @0x1aaba8 vstr s15, [r6, #48] */
/* @0x1aabac ldr r3, [r3, #0x8] */
/* @0x1aabb0 blx r3 */
/* @0x1aabb4 vldr s14, [r4, #48] */
/* @0x1aabb8 vcvt.f64.f32 d7, s14 */
/* @0x1aabbc ldr r3, [r6] */
/* @0x1aabc0 mov r1, #8 */
/* @0x1aabc4 mov r2, r7 */
/* @0x1aabc8 str r8, [r6, #0x38] */
/* @0x1aabcc mov r0, r6 */
/* @0x1aabd0 vstr s14, [r6, #44] */
/* @0x1aabd4 vstr s15, [r6, #48] */
/* @0x1aabd8 ldr r3, [r3, #0x8] */
/* @0x1aabdc blx r3 */
/* @0x1aabe0 ldrb r4, [r4, #0x34] */
/* @0x1aabe4 ldr r3, [r6] */
/* @0x1aabe8 mov r0, r6 */
/* @0x1aabec str r8, [r6, #0x38] */
/* @0x1aabf0 mov r1, #6 */
/* @0x1aabf4 vmov s13, r4 */
/* @0x1aabf8 mov r2, r7 */
/* @0x1aabfc vcvt.f64.u32 d6, s13 */
/* @0x1aac00 vmov r4, r5, d6 */
/* @0x1aac04 vstr s12, [r6, #44] */
/* @0x1aac08 str r5, [r6, #0x30] */
/* @0x1aac0c ldr r3, [r3, #0x8] */
/* @0x1aac10 blx r3 */
/* @0x1aac14 ldr r3, [r9, #0xb8] */
/* @0x1aac18 cmp r3, r11 */
/* @0x1aac1c bgt 0x1aa994 <_ZN5CRoom9SerialiseEP7IBuffer+0x76c> */
/* @0x1aac20 ldr r4, [r9, #0xdc] */
/* @0x1aac24 mov r2, #0 */
/* @0x1aac28 ldr r3, [r6] */
/* @0x1aac2c mov r0, r6 */
/* @0x1aac30 str r2, [r6, #0x38] */
/* @0x1aac34 mov r1, #6 */
/* @0x1aac38 vmov s15, r4 */
/* @0x1aac3c mov r2, r7 */
/* @0x1aac40 vcvt.f64.s32 d7, s15 */
/* @0x1aac44 vmov r4, r5, d7 */
/* @0x1aac48 vstr s14, [r6, #44] */
/* @0x1aac4c str r5, [r6, #0x30] */
/* @0x1aac50 ldr r3, [r3, #0x8] */
/* @0x1aac54 blx r3 */
/* @0x1aac58 ldr r4, [r9, #0xd4] */
/* @0x1aac5c cmp r4, #0 */
/* @0x1aac60 beq 0x1aac7c <_ZN5CRoom9SerialiseEP7IBuffer+0xa54> */
/* @0x1aac64 mov r0, r4 */
/* @0x1aac68 mov r1, r6 */
/* @0x1aac6c bl 0x1a9428 <_ZN6CLayer9SerializeEP7IBuffer> */
/* @0x1aac70 ldr r4, [r4, #0x68] */
/* @0x1aac74 cmp r4, #0 */
/* @0x1aac78 bne 0x1aac64 <_ZN5CRoom9SerialiseEP7IBuffer+0xa3c> */
/* @0x1aac7c ldr r4, [r9, #0x88] */
/* @0x1aac80 mov r2, #0 */
/* @0x1aac84 ldr r3, [r6] */
/* @0x1aac88 mov r0, r6 */
/* @0x1aac8c str r2, [r6, #0x38] */
/* @0x1aac90 mov r1, #6 */
/* @0x1aac94 vmov s15, r4 */
/* @0x1aac98 mov r2, r7 */
/* @0x1aac9c vcvt.f64.s32 d7, s15 */
/* @0x1aaca0 vmov r4, r5, d7 */
/* @0x1aaca4 vstr s14, [r6, #44] */
/* @0x1aaca8 str r5, [r6, #0x30] */
/* @0x1aacac ldr r3, [r3, #0x8] */
/* @0x1aacb0 blx r3 */
/* @0x1aacb4 ldr r4, [r9, #0x80] */
/* @0x1aacb8 cmp r4, #0 */
/* @0x1aacbc beq 0x1aacd8 <_ZN5CRoom9SerialiseEP7IBuffer+0xab0> */
/* @0x1aacc0 mov r0, r4 */
/* @0x1aacc4 mov r1, r6 */
/* @0x1aacc8 bl 0x196bf4 <_ZN9CInstance9SerialiseEP7IBuffer> */
/* @0x1aaccc ldr r4, [r4, #0x178] */
/* @0x1aacd0 cmp r4, #0 */
/* @0x1aacd4 bne 0x1aacc0 <_ZN5CRoom9SerialiseEP7IBuffer+0xa98> */
/* @0x1aacd8 ldr r4, [r9, #0x94] */
/* @0x1aacdc mov r1, #0 */
/* @0x1aace0 ldr r3, [r6] */
/* @0x1aace4 mov r2, r7 */
/* @0x1aace8 str r1, [r6, #0x38] */
/* @0x1aacec mov r0, r6 */
/* @0x1aacf0 vmov s13, r4 */
/* @0x1aacf4 mov r1, #6 */
/* @0x1aacf8 vcvt.f64.s32 d6, s13 */
/* @0x1aacfc vmov r4, r5, d6 */
/* @0x1aad00 vstr s12, [r6, #44] */
/* @0x1aad04 str r5, [r6, #0x30] */
/* @0x1aad08 ldr r3, [r3, #0x8] */
/* @0x1aad0c blx r3 */
/* @0x1aad10 ldr r4, [r9, #0x8c] */
/* @0x1aad14 cmp r4, #0 */
/* @0x1aad18 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1aad1c mov r0, r4 */
/* @0x1aad20 mov r1, r6 */
/* @0x1aad24 bl 0x196bf4 <_ZN9CInstance9SerialiseEP7IBuffer> */
/* @0x1aad28 ldr r4, [r4, #0x178] */
/* @0x1aad2c cmp r4, #0 */
/* @0x1aad30 bne 0x1aad1c <_ZN5CRoom9SerialiseEP7IBuffer+0xaf4> */
/* @0x1aad34 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1aad38 ldr r0, [pc, #0xc] */
/* @0x1aad3c mov r1, #1 */
/* @0x1aad40 add r0, pc, r0 */
/* @0x1aad44 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1aad48 b 0x1aa240 <_ZN5CRoom9SerialiseEP7IBuffer+0x18> */
/* @0x1aad4c ldrheq r2, [r10], -r12 */

/* ── FUNC 0x1aad50 · MemoryInWad(void*) · size=92 · insn=23 */
/* @0x1aad50 ldr r1, [pc, #0x4c] */
/* @0x1aad54 mov r2, r0 */
/* @0x1aad58 ldr r12, [pc, #0x48] */
/* @0x1aad5c asr r3, r0, #31 */
/* @0x1aad60 ldr r1, [pc, r1] */
/* @0x1aad64 ldr r12, [pc, r12] */
/* @0x1aad68 ldr r0, [r1] */
/* @0x1aad6c push {r4, r5} */
/* @0x1aad70 ldr r4, [r12] */
/* @0x1aad74 asr r1, r0, #31 */
/* @0x1aad78 cmp r3, r1 */
/* @0x1aad7c cmpeq r2, r0 */
/* @0x1aad80 asr r5, r4, #31 */
/* @0x1aad84 movhi r0, #0 */
/* @0x1aad88 movls r0, #1 */
/* @0x1aad8c cmp r3, r5 */
/* @0x1aad90 cmpeq r2, r4 */
/* @0x1aad94 pop {r4, r5} */
/* @0x1aad98 movlo r0, #0 */
/* @0x1aad9c andhs r0, r0, #1 */
/* @0x1aada0 bx lr */
/* @0x1aada4 eoreq r5, r4, r8, lsr #21 */
/* @0x1aada8 eoreq r2, r4, r0, ror #23 */

/* ── FUNC 0x1aadac · CRoom::AddInstanceToStorage(float, float, int) · size=460 · insn=115 */
/* @0x1aadac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aadb0 vpush {d8} */
/* @0x1aadb4 sub sp, sp, #20 */
/* @0x1aadb8 ldr r7, [r0, #0xc8] */
/* @0x1aadbc mov r6, r0 */
/* @0x1aadc0 str r3, [sp, #0xc] */
/* @0x1aadc4 vmov s17, r1 */
/* @0x1aadc8 cmp r7, #0 */
/* @0x1aadcc vmov s16, r2 */
/* @0x1aadd0 beq 0x1aaf38 <_ZN5CRoom20AddInstanceToStorageEffi+0x18c> */
/* @0x1aadd4 ldr r12, [r7] */
/* @0x1aadd8 mov r0, #44 */
/* @0x1aaddc ldr r1, [pc, #0x188] */
/* @0x1aade0 movw r2, #0x4c9 */
/* @0x1aade4 mov r3, #1 */
/* @0x1aade8 mla r0, r12, r0, r0 */
/* @0x1aadec add r1, pc, r1 */
/* @0x1aadf0 add r0, r0, #4 */
/* @0x1aadf4 str r0, [sp, #0x8] */
/* @0x1aadf8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aadfc ldr r2, [r7] */
/* @0x1aae00 cmp r2, #0 */
/* @0x1aae04 add r1, r0, #4 */
/* @0x1aae08 str r1, [sp, #0x4] */
/* @0x1aae0c add r1, r0, r2, lsl #2 */
/* @0x1aae10 mov r10, r0 */
/* @0x1aae14 add r1, r1, #8 */
/* @0x1aae18 ble 0x1aae98 <_ZN5CRoom20AddInstanceToStorageEffi+0xec> */
/* @0x1aae1c ldr lr, [sp, #0x4] */
/* @0x1aae20 mov r4, r7 */
/* @0x1aae24 mov r12, #0 */
/* @0x1aae28 str r1, [lr], #4 */
/* @0x1aae2c ldr r3, [r4, #0x4]! */
/* @0x1aae30 cmp r3, #0 */
/* @0x1aae34 streq r3, [lr, #-0x4] */
/* @0x1aae38 beq 0x1aae88 <_ZN5CRoom20AddInstanceToStorageEffi+0xdc> */
/* @0x1aae3c add r0, r3, #32 */
/* @0x1aae40 mov r2, r1 */
/* @0x1aae44 ldr r11, [r3] */
/* @0x1aae48 add r3, r3, #16 */
/* @0x1aae4c ldr r9, [r3, #-0xc] */
/* @0x1aae50 add r2, r2, #16 */
/* @0x1aae54 ldr r8, [r3, #-0x8] */
/* @0x1aae58 ldr r5, [r3, #-0x4] */
/* @0x1aae5c cmp r3, r0 */
/* @0x1aae60 str r11, [r2, #-0x10] */
/* @0x1aae64 str r9, [r2, #-0xc] */
/* @0x1aae68 str r8, [r2, #-0x8] */
/* @0x1aae6c str r5, [r2, #-0x4] */
/* @0x1aae70 bne 0x1aae44 <_ZN5CRoom20AddInstanceToStorageEffi+0x98> */
/* @0x1aae74 ldr r0, [r3] */
/* @0x1aae78 ldr r3, [r3, #0x4] */
/* @0x1aae7c str r0, [r2] */
/* @0x1aae80 str r3, [r2, #0x4] */
/* @0x1aae84 ldr r2, [r7] */
/* @0x1aae88 add r12, r12, #1 */
/* @0x1aae8c add r1, r1, #40 */
/* @0x1aae90 cmp r2, r12 */
/* @0x1aae94 bgt 0x1aae28 <_ZN5CRoom20AddInstanceToStorageEffi+0x7c> */
/* @0x1aae98 mov r0, r7 */
/* @0x1aae9c str r2, [r10] */
/* @0x1aaea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aaea4 ldr r1, [r10] */
/* @0x1aaea8 ldr r7, [sp, #0x8] */
/* @0x1aaeac lsl r1, r1, #2 */
/* @0x1aaeb0 sub r12, r7, #40 */
/* @0x1aaeb4 vcvt.s32.f32 s17, s17 */
/* @0x1aaeb8 ldr r7, [sp, #0x4] */
/* @0x1aaebc str r10, [r6, #0xc8] */
/* @0x1aaec0 add r3, r10, r12 */
/* @0x1aaec4 ldr r2, [pc, #0xa4] */
/* @0x1aaec8 mov r4, #1065353216 */
/* @0x1aaecc str r3, [r7, r1] */
/* @0x1aaed0 mov r6, #0 */
/* @0x1aaed4 ldr r7, [sp, #0xc] */
/* @0x1aaed8 ldr r2, [pc, r2] */
/* @0x1aaedc mov r1, #0 */
/* @0x1aaee0 mvn r5, #0 */
/* @0x1aaee4 ldr r0, [r2] */
/* @0x1aaee8 str r7, [r3, #0x8] */
/* @0x1aaeec vcvt.s32.f32 s16, s16 */
/* @0x1aaef0 vmov r7, s17 */
/* @0x1aaef4 add r0, r0, #1 */
/* @0x1aaef8 str r0, [r2] */
/* @0x1aaefc ldr r2, [r10] */
/* @0x1aaf00 str r0, [r3, #0xc] */
/* @0x1aaf04 add r2, r2, #1 */
/* @0x1aaf08 str r7, [r10, r12] */
/* @0x1aaf0c vstr s16, [r3, #4] */
/* @0x1aaf10 str r6, [r3, #0x20] */
/* @0x1aaf14 str r5, [r3, #0x1c] */
/* @0x1aaf18 str r4, [r3, #0x14] */
/* @0x1aaf1c str r4, [r3, #0x18] */
/* @0x1aaf20 str r1, [r3, #0x10] */
/* @0x1aaf24 str r1, [r3, #0x24] */
/* @0x1aaf28 str r2, [r10] */
/* @0x1aaf2c add sp, sp, #20 */
/* @0x1aaf30 vpop {d8} */
/* @0x1aaf34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1aaf38 ldr r1, [pc, #0x34] */
/* @0x1aaf3c mov r0, #48 */
/* @0x1aaf40 movw r2, #0x4e1 */
/* @0x1aaf44 mov r3, #1 */
/* @0x1aaf48 add r1, pc, r1 */
/* @0x1aaf4c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aaf50 mov r12, #8 */
/* @0x1aaf54 add r1, r0, #4 */
/* @0x1aaf58 mov r10, r0 */
/* @0x1aaf5c str r1, [sp, #0x4] */
/* @0x1aaf60 mov r1, r7 */
/* @0x1aaf64 str r7, [r0] */
/* @0x1aaf68 b 0x1aaeb4 <_ZN5CRoom20AddInstanceToStorageEffi+0x108> */
/* @0x1aaf6c ldrheq r2, [r10], -r12 */
/* @0x1aaf70 eoreq r5, r4, r4, lsr r9 */
/* @0x1aaf74 andseq r2, r10, r0, ror #4 */

/* ── FUNC 0x1aaf78 · CRoom::AddTileToStorage(int, int, int, int, int, int, int, int, float, float, unsigned int) · size=396 · insn=99 */
/* @0x1aaf78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aaf7c vpush {d8} */
/* @0x1aaf80 mov r6, r0 */
/* @0x1aaf84 ldr r7, [r6, #0xc4] */
/* @0x1aaf88 mov r0, #52 */
/* @0x1aaf8c sub sp, sp, #28 */
/* @0x1aaf90 vldr s17, [sp, #92] */
/* @0x1aaf94 vldr s16, [sp, #96] */
/* @0x1aaf98 ldr r12, [r7] */
/* @0x1aaf9c str r1, [sp, #0xc] */
/* @0x1aafa0 ldr r1, [pc, #0x154] */
/* @0x1aafa4 mla r0, r12, r0, r0 */
/* @0x1aafa8 str r2, [sp, #0x10] */
/* @0x1aafac str r3, [sp, #0x14] */
/* @0x1aafb0 add r1, pc, r1 */
/* @0x1aafb4 movw r2, #0x51b */
/* @0x1aafb8 mov r3, #1 */
/* @0x1aafbc str r0, [sp, #0x4] */
/* @0x1aafc0 add r0, r0, #4 */
/* @0x1aafc4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aafc8 ldr r2, [r7] */
/* @0x1aafcc cmp r2, #0 */
/* @0x1aafd0 add r1, r0, #4 */
/* @0x1aafd4 str r1, [sp, #0x8] */
/* @0x1aafd8 add r1, r0, r2, lsl #2 */
/* @0x1aafdc mov r10, r0 */
/* @0x1aafe0 add r1, r1, #8 */
/* @0x1aafe4 ble 0x1ab054 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0xdc> */
/* @0x1aafe8 ldr lr, [sp, #0x8] */
/* @0x1aafec mov r4, r7 */
/* @0x1aaff0 mov r12, #0 */
/* @0x1aaff4 str r1, [lr], #4 */
/* @0x1aaff8 ldr r3, [r4, #0x4]! */
/* @0x1aaffc cmp r3, #0 */
/* @0x1ab000 streq r3, [lr, #-0x4] */
/* @0x1ab004 beq 0x1ab044 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0xcc> */
/* @0x1ab008 add r0, r3, #48 */
/* @0x1ab00c mov r2, r1 */
/* @0x1ab010 ldr r11, [r3] */
/* @0x1ab014 add r3, r3, #16 */
/* @0x1ab018 ldr r9, [r3, #-0xc] */
/* @0x1ab01c add r2, r2, #16 */
/* @0x1ab020 ldr r8, [r3, #-0x8] */
/* @0x1ab024 ldr r5, [r3, #-0x4] */
/* @0x1ab028 cmp r3, r0 */
/* @0x1ab02c str r11, [r2, #-0x10] */
/* @0x1ab030 str r9, [r2, #-0xc] */
/* @0x1ab034 str r8, [r2, #-0x8] */
/* @0x1ab038 str r5, [r2, #-0x4] */
/* @0x1ab03c bne 0x1ab010 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0x98> */
/* @0x1ab040 ldr r2, [r7] */
/* @0x1ab044 add r12, r12, #1 */
/* @0x1ab048 add r1, r1, #48 */
/* @0x1ab04c cmp r2, r12 */
/* @0x1ab050 bgt 0x1aaff4 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0x7c> */
/* @0x1ab054 str r2, [r10] */
/* @0x1ab058 mov r0, r7 */
/* @0x1ab05c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ab060 ldr r4, [sp, #0x4] */
/* @0x1ab064 ldr r3, [pc, #0x94] */
/* @0x1ab068 ldr r1, [r10] */
/* @0x1ab06c sub r2, r4, #44 */
/* @0x1ab070 ldr r4, [sp, #0x8] */
/* @0x1ab074 ldr r3, [pc, r3] */
/* @0x1ab078 str r10, [r6, #0xc4] */
/* @0x1ab07c add r12, r10, r2 */
/* @0x1ab080 ldr r0, [r3] */
/* @0x1ab084 str r12, [r4, r1, lsl #2] */
/* @0x1ab088 ldr r4, [sp, #0xc] */
/* @0x1ab08c add r0, r0, #1 */
/* @0x1ab090 str r0, [r3] */
/* @0x1ab094 ldr r3, [r10] */
/* @0x1ab098 str r4, [r12, #0x8] */
/* @0x1ab09c ldr r4, [sp, #0x10] */
/* @0x1ab0a0 add r3, r3, #1 */
/* @0x1ab0a4 str r0, [r12, #0x20] */
/* @0x1ab0a8 str r4, [r12, #0xc] */
/* @0x1ab0ac ldr r4, [sp, #0x14] */
/* @0x1ab0b0 str r4, [r12, #0x10] */
/* @0x1ab0b4 ldr r4, [sp, #0x48] */
/* @0x1ab0b8 str r4, [r12, #0x14] */
/* @0x1ab0bc ldr r4, [sp, #0x4c] */
/* @0x1ab0c0 str r4, [r12, #0x18] */
/* @0x1ab0c4 ldr r4, [sp, #0x50] */
/* @0x1ab0c8 str r4, [r10, r2] */
/* @0x1ab0cc vstr s17, [r12, #36] */
/* @0x1ab0d0 ldr r4, [sp, #0x54] */
/* @0x1ab0d4 vstr s16, [r12, #40] */
/* @0x1ab0d8 str r4, [r12, #0x4] */
/* @0x1ab0dc ldr r4, [sp, #0x58] */
/* @0x1ab0e0 str r4, [r12, #0x1c] */
/* @0x1ab0e4 ldr r4, [sp, #0x64] */
/* @0x1ab0e8 str r4, [r12, #0x2c] */
/* @0x1ab0ec str r3, [r10] */
/* @0x1ab0f0 add sp, sp, #28 */
/* @0x1ab0f4 vpop {d8} */
/* @0x1ab0f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ab0fc ldrsheq r2, [r10], -r8 */
/* @0x1ab100 mlaeq r4, r12, r7, r5 */

/* ── FUNC 0x1ab104 · CRoom::ClearStorageTiles() · size=60 · insn=15 */
/* @0x1ab104 push {r4, lr} */
/* @0x1ab108 mov r4, r0 */
/* @0x1ab10c ldr r0, [r0, #0xc4] */
/* @0x1ab110 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ab114 ldr r1, [pc, #0x20] */
/* @0x1ab118 mov r3, #1 */
/* @0x1ab11c mov r0, #4 */
/* @0x1ab120 add r1, pc, r1 */
/* @0x1ab124 movw r2, #0x549 */
/* @0x1ab128 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab12c mov r3, #0 */
/* @0x1ab130 str r3, [r0] */
/* @0x1ab134 str r0, [r4, #0xc4] */
/* @0x1ab138 pop {r4, pc} */
/* @0x1ab13c andseq r2, r10, r8, lsl #1 */

/* ── FUNC 0x1ab140 · CRoom::ClearStorageInstances() · size=4 · insn=1 */
/* @0x1ab140 bx lr */

/* ── FUNC 0x1ab144 · CRoom::AddInstance(float, float, int) · size=416 · insn=104 */
/* @0x1ab144 ldr r12, [pc, #0x18c] */
/* @0x1ab148 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ab14c ldr r12, [pc, r12] */
/* @0x1ab150 sub sp, sp, #12 */
/* @0x1ab154 mov r5, r0 */
/* @0x1ab158 ldr r6, [r12] */
/* @0x1ab15c mov r0, #432 */
/* @0x1ab160 mov r9, r3 */
/* @0x1ab164 mov r8, r1 */
/* @0x1ab168 mov r7, r2 */
/* @0x1ab16c add r6, r6, #1 */
/* @0x1ab170 str r6, [r12] */
/* @0x1ab174 bl 0x27c524 <_Znwj> */
/* @0x1ab178 mov r3, r6 */
/* @0x1ab17c mov r12, #1 */
/* @0x1ab180 mov r2, r7 */
/* @0x1ab184 mov r1, r8 */
/* @0x1ab188 str r12, [sp, #0x4] */
/* @0x1ab18c str r9, [sp] */
/* @0x1ab190 mov r4, r0 */
/* @0x1ab194 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ab198 mov r0, r4 */
/* @0x1ab19c mov r1, r5 */
/* @0x1ab1a0 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1ab1a4 ldr r3, [r5, #0x84] */
/* @0x1ab1a8 ldr r2, [r5, #0x88] */
/* @0x1ab1ac cmp r3, #0 */
/* @0x1ab1b0 vldrne s14, [r4, #384] */
/* @0x1ab1b4 add r2, r2, #1 */
/* @0x1ab1b8 str r2, [r5, #0x88] */
/* @0x1ab1bc beq 0x1ab2bc <_ZN5CRoom11AddInstanceEffi+0x178> */
/* @0x1ab1c0 vldr s15, [r3, #388] */
/* @0x1ab1c4 vcmpe.f32 s15, s14 */
/* @0x1ab1c8 vmrs APSR_nzcv, fpscr */
/* @0x1ab1cc bls 0x1ab288 <_ZN5CRoom11AddInstanceEffi+0x144> */
/* @0x1ab1d0 ldr r3, [r3, #0x17c] */
/* @0x1ab1d4 cmp r3, #0 */
/* @0x1ab1d8 bne 0x1ab1c0 <_ZN5CRoom11AddInstanceEffi+0x7c> */
/* @0x1ab1dc ldr r2, [r5, #0x80] */
/* @0x1ab1e0 vstr s14, [r4, #388] */
/* @0x1ab1e4 str r4, [r2, #0x17c] */
/* @0x1ab1e8 str r2, [r4, #0x178] */
/* @0x1ab1ec str r4, [r5, #0x80] */
/* @0x1ab1f0 str r3, [r4, #0x17c] */
/* @0x1ab1f4 ldr r6, [pc, #0xe0] */
/* @0x1ab1f8 movw r2, #0x132 */
/* @0x1ab1fc ldr r1, [pc, #0xdc] */
/* @0x1ab200 mov r3, #1 */
/* @0x1ab204 ldr r6, [pc, r6] */
/* @0x1ab208 mov r0, #16 */
/* @0x1ab20c add r1, pc, r1 */
/* @0x1ab210 ldr r9, [r4, #0x78] */
/* @0x1ab214 ldm r6, {r7, r8} */
/* @0x1ab218 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab21c and r8, r9, r8 */
/* @0x1ab220 ldr r2, [r7, r8, lsl #3] */
/* @0x1ab224 add r3, r7, r8, lsl #3 */
/* @0x1ab228 cmp r2, #0 */
/* @0x1ab22c ldrne r2, [r3, #0x4] */
/* @0x1ab230 movne r1, #0 */
/* @0x1ab234 str r9, [r0, #0x8] */
/* @0x1ab238 str r4, [r0, #0xc] */
/* @0x1ab23c strne r2, [r0] */
/* @0x1ab240 streq r0, [r3, #0x4] */
/* @0x1ab244 strne r0, [r2, #0x4] */
/* @0x1ab248 strne r0, [r3, #0x4] */
/* @0x1ab24c ldr r3, [r6, #0x8] */
/* @0x1ab250 streq r0, [r7, r8, lsl #3] */
/* @0x1ab254 strne r1, [r0, #0x4] */
/* @0x1ab258 mov r1, r4 */
/* @0x1ab25c streq r2, [r0, #0x4] */
/* @0x1ab260 add r3, r3, #1 */
/* @0x1ab264 streq r2, [r0] */
/* @0x1ab268 mov r0, r5 */
/* @0x1ab26c str r3, [r6, #0x8] */
/* @0x1ab270 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1ab274 mov r0, r4 */
/* @0x1ab278 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ab27c mov r0, r4 */
/* @0x1ab280 add sp, sp, #12 */
/* @0x1ab284 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1ab288 ldr r2, [r3, #0x178] */
/* @0x1ab28c cmp r2, #0 */
/* @0x1ab290 streq r3, [r4, #0x17c] */
/* @0x1ab294 strne r2, [r4, #0x178] */
/* @0x1ab298 ldrne r2, [r3, #0x178] */
/* @0x1ab29c streq r4, [r3, #0x178] */
/* @0x1ab2a0 strne r3, [r4, #0x17c] */
/* @0x1ab2a4 streq r4, [r5, #0x84] */
/* @0x1ab2a8 strne r4, [r2, #0x17c] */
/* @0x1ab2ac streq r2, [r4, #0x178] */
/* @0x1ab2b0 strne r4, [r3, #0x178] */
/* @0x1ab2b4 vstr s14, [r4, #388] */
/* @0x1ab2b8 b 0x1ab1f4 <_ZN5CRoom11AddInstanceEffi+0xb0> */
/* @0x1ab2bc ldr r2, [r4, #0x180] */
/* @0x1ab2c0 str r4, [r5, #0x84] */
/* @0x1ab2c4 str r4, [r5, #0x80] */
/* @0x1ab2c8 str r2, [r4, #0x184] */
/* @0x1ab2cc str r3, [r4, #0x17c] */
/* @0x1ab2d0 str r3, [r4, #0x178] */
/* @0x1ab2d4 b 0x1ab1f4 <_ZN5CRoom11AddInstanceEffi+0xb0> */
/* @0x1ab2d8 eoreq r5, r4, r0, asr #13 */
/* @0x1ab2dc eoreq r2, r4, r0, asr #20 */
/* @0x1ab2e0 andseq r1, r10, r0, lsr #21 */
