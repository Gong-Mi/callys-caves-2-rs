/* libyoyo.so 覆盖卡组 0166
 * 函数 0x1e7e1c..0x1eef64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1e7e1c · CSprite::SetupBitmapTexture(SWF_Bitmap*, int, int, int, int, int, int, unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int) · size=1096 · insn=274 */
/* @0x1e7e1c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e7e20 subs r9, r1, #0 */
/* @0x1e7e24 sub sp, sp, #68 */
/* @0x1e7e28 mov r10, r3 */
/* @0x1e7e2c ldr r4, [sp, #0x78] */
/* @0x1e7e30 ldr r5, [sp, #0x80] */
/* @0x1e7e34 beq 0x1e7f58 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x13c> */
/* @0x1e7e38 mov r3, #0 */
/* @0x1e7e3c str r3, [sp, #0x18] */
/* @0x1e7e40 str r3, [sp, #0x1c] */
/* @0x1e7e44 cmp r2, #9 */
/* @0x1e7e48 addls pc, pc, r2, lsl #2 */
/* @0x1e7e4c b 0x1e7f58 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x13c> */
/* @0x1e7e50 b 0x1e7e78 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x5c> */
/* @0x1e7e54 b 0x1e7fe4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1c8> */
/* @0x1e7e58 b 0x1e8008 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1ec> */
/* @0x1e7e5c b 0x1e8118 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2fc> */
/* @0x1e7e60 b 0x1e813c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x320> */
/* @0x1e7e64 b 0x1e8160 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x344> */
/* @0x1e7e68 b 0x1e7f60 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x144> */
/* @0x1e7e6c b 0x1e7f60 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x144> */
/* @0x1e7e70 b 0x1e8160 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x344> */
/* @0x1e7e74 b 0x1e7f60 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x144> */
/* @0x1e7e78 ldr r2, [sp, #0x84] */
/* @0x1e7e7c cmp r2, #0 */
/* @0x1e7e80 beq 0x1e822c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x410> */
/* @0x1e7e84 ldr r2, [sp, #0x6c] */
/* @0x1e7e88 ldr r3, [sp, #0x88] */
/* @0x1e7e8c ldr r1, [pc, #0x3bc] */
/* @0x1e7e90 add r6, r2, r3 */
/* @0x1e7e94 mov r3, #1 */
/* @0x1e7e98 add r1, pc, r1 */
/* @0x1e7e9c movw r2, #0xec1 */
/* @0x1e7ea0 mov r0, r6 */
/* @0x1e7ea4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e7ea8 ldr r1, [sp, #0x84] */
/* @0x1e7eac ldr r2, [sp, #0x88] */
/* @0x1e7eb0 mov r5, r0 */
/* @0x1e7eb4 bl 0xb65bc <memcpy@plt> */
/* @0x1e7eb8 ldr r3, [sp, #0x88] */
/* @0x1e7ebc mov r1, r4 */
/* @0x1e7ec0 ldr r2, [sp, #0x6c] */
/* @0x1e7ec4 add r0, r5, r3 */
/* @0x1e7ec8 bl 0xb65bc <memcpy@plt> */
/* @0x1e7ecc mov r3, #0 */
/* @0x1e7ed0 mov r0, r5 */
/* @0x1e7ed4 str r3, [sp] */
/* @0x1e7ed8 mov r1, r6 */
/* @0x1e7edc add r2, sp, #24 */
/* @0x1e7ee0 add r3, sp, #28 */
/* @0x1e7ee4 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b> */
/* @0x1e7ee8 mov r11, r0 */
/* @0x1e7eec cmp r11, #0 */
/* @0x1e7ef0 beq 0x1e7f58 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x13c> */
/* @0x1e7ef4 ldr r3, [sp, #0x18] */
/* @0x1e7ef8 mov r2, r11 */
/* @0x1e7efc ldr r1, [sp, #0x1c] */
/* @0x1e7f00 mov r0, r3 */
/* @0x1e7f04 mul r3, r1, r3 */
/* @0x1e7f08 lsl r3, r3, #2 */
/* @0x1e7f0c bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0x1e7f10 str r0, [r9, #0x8] */
/* @0x1e7f14 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e7f18 cmp r0, #0 */
/* @0x1e7f1c beq 0x1e7f40 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x124> */
/* @0x1e7f20 ldr r3, [pc, #0x32c] */
/* @0x1e7f24 ldr r2, [r9, #0x8] */
/* @0x1e7f28 ldr r3, [pc, r3] */
/* @0x1e7f2c ldr r3, [r3, #0x4] */
/* @0x1e7f30 ldr r3, [r3, r2, lsl #2] */
/* @0x1e7f34 cmp r3, #0 */
/* @0x1e7f38 ldrne r3, [r3] */
/* @0x1e7f3c strne r3, [r9, #0xc] */
/* @0x1e7f40 ldr r2, [sp, #0x18] */
/* @0x1e7f44 mov r0, r11 */
/* @0x1e7f48 ldr r3, [sp, #0x1c] */
/* @0x1e7f4c str r2, [r9, #0x14] */
/* @0x1e7f50 str r3, [r9, #0x18] */
/* @0x1e7f54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e7f58 add sp, sp, #68 */
/* @0x1e7f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e7f60 ldr r1, [pc, #0x2f0] */
/* @0x1e7f64 movw r2, #0xf2a */
/* @0x1e7f68 mov r3, #1 */
/* @0x1e7f6c ldr r0, [sp, #0x6c] */
/* @0x1e7f70 add r1, pc, r1 */
/* @0x1e7f74 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e7f78 ldr r2, [sp, #0x6c] */
/* @0x1e7f7c cmp r2, #0 */
/* @0x1e7f80 add r5, r2, #3 */
/* @0x1e7f84 movge r5, r2 */
/* @0x1e7f88 asr r5, r5, #2 */
/* @0x1e7f8c cmp r5, #0 */
/* @0x1e7f90 movgt r3, #0 */
/* @0x1e7f94 mov r11, r0 */
/* @0x1e7f98 movgt r2, r0 */
/* @0x1e7f9c ble 0x1e7fd4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1b8> */
/* @0x1e7fa0 ldrb r1, [r4, #0x2] */
/* @0x1e7fa4 add r3, r3, #1 */
/* @0x1e7fa8 ldrb r6, [r4, #0x3] */
/* @0x1e7fac cmp r3, r5 */
/* @0x1e7fb0 ldrb r12, [r4] */
/* @0x1e7fb4 add r4, r4, #4 */
/* @0x1e7fb8 ldrb r0, [r4, #-0x3] */
/* @0x1e7fbc lsl r1, r1, #16 */
/* @0x1e7fc0 orr r1, r1, r6, lsl #24 */
/* @0x1e7fc4 orr r1, r1, r12 */
/* @0x1e7fc8 orr r1, r1, r0, lsl #8 */
/* @0x1e7fcc str r1, [r2], #4 */
/* @0x1e7fd0 bne 0x1e7fa0 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x184> */
/* @0x1e7fd4 ldr r3, [sp, #0x68] */
/* @0x1e7fd8 str r10, [sp, #0x18] */
/* @0x1e7fdc str r3, [sp, #0x1c] */
/* @0x1e7fe0 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0> */
/* @0x1e7fe4 mov r3, #0 */
/* @0x1e7fe8 mov r0, r4 */
/* @0x1e7fec str r3, [sp] */
/* @0x1e7ff0 add r2, sp, #24 */
/* @0x1e7ff4 ldr r1, [sp, #0x6c] */
/* @0x1e7ff8 add r3, sp, #28 */
/* @0x1e7ffc bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b> */
/* @0x1e8000 mov r11, r0 */
/* @0x1e8004 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0> */
/* @0x1e8008 add r3, sp, #28 */
/* @0x1e800c add r2, sp, #24 */
/* @0x1e8010 mov r0, r4 */
/* @0x1e8014 ldr r1, [sp, #0x6c] */
/* @0x1e8018 mov r4, #0 */
/* @0x1e801c str r4, [sp] */
/* @0x1e8020 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b> */
/* @0x1e8024 add r5, sp, #32 */
/* @0x1e8028 ldr r1, [sp, #0x70] */
/* @0x1e802c mov r11, r0 */
/* @0x1e8030 mov r0, r5 */
/* @0x1e8034 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x1e8038 mov r0, r5 */
/* @0x1e803c ldr r1, [sp, #0x70] */
/* @0x1e8040 bl 0x201a10 <_ZN7CStream12WriteIntegerEi> */
/* @0x1e8044 ldr r1, [sp, #0x7c] */
/* @0x1e8048 ldr r2, [sp, #0x70] */
/* @0x1e804c mov r0, r5 */
/* @0x1e8050 bl 0x2014c8 <_ZN7CStream5WriteEPvi> */
/* @0x1e8054 mov r1, r4 */
/* @0x1e8058 mov r2, r4 */
/* @0x1e805c mov r0, r5 */
/* @0x1e8060 bl 0x201284 <_ZN7CStream4SeekEis> */
/* @0x1e8064 mov r0, r5 */
/* @0x1e8068 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x1e806c mov r6, r0 */
/* @0x1e8070 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x1e8074 ldr r1, [pc, #0x1e0] */
/* @0x1e8078 movw r2, #0xee7 */
/* @0x1e807c mov r3, #1 */
/* @0x1e8080 add r1, pc, r1 */
/* @0x1e8084 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8088 mov r4, r0 */
/* @0x1e808c mov r0, r6 */
/* @0x1e8090 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x1e8094 mov r1, r4 */
/* @0x1e8098 mov r2, r0 */
/* @0x1e809c mov r0, r6 */
/* @0x1e80a0 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x1e80a4 cmp r6, #0 */
/* @0x1e80a8 beq 0x1e80bc <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2a0> */
/* @0x1e80ac mov r0, r6 */
/* @0x1e80b0 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1e80b4 mov r0, r6 */
/* @0x1e80b8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e80bc ldr r2, [sp, #0x1c] */
/* @0x1e80c0 ldr r3, [sp, #0x18] */
/* @0x1e80c4 mul r3, r2, r3 */
/* @0x1e80c8 cmp r3, #0 */
/* @0x1e80cc movgt r2, r11 */
/* @0x1e80d0 movgt r3, #0 */
/* @0x1e80d4 ble 0x1e8104 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2e8> */
/* @0x1e80d8 ldrb r0, [r4, r3] */
/* @0x1e80dc add r3, r3, #1 */
/* @0x1e80e0 ldr r1, [r2] */
/* @0x1e80e4 bic r1, r1, #-16777216 */
/* @0x1e80e8 orr r1, r1, r0, lsl #24 */
/* @0x1e80ec str r1, [r2], #4 */
/* @0x1e80f0 ldr r1, [sp, #0x18] */
/* @0x1e80f4 ldr r0, [sp, #0x1c] */
/* @0x1e80f8 mul r1, r0, r1 */
/* @0x1e80fc cmp r1, r3 */
/* @0x1e8100 bgt 0x1e80d8 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2bc> */
/* @0x1e8104 mov r0, r4 */
/* @0x1e8108 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e810c mov r0, r5 */
/* @0x1e8110 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1e8114 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0> */
/* @0x1e8118 mov r3, #0 */
/* @0x1e811c mov r0, r4 */
/* @0x1e8120 str r3, [sp] */
/* @0x1e8124 add r2, sp, #24 */
/* @0x1e8128 ldr r1, [sp, #0x6c] */
/* @0x1e812c add r3, sp, #28 */
/* @0x1e8130 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0x1e8134 mov r11, r0 */
/* @0x1e8138 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0> */
/* @0x1e813c mov r3, #0 */
/* @0x1e8140 mov r0, r4 */
/* @0x1e8144 str r3, [sp] */
/* @0x1e8148 add r2, sp, #24 */
/* @0x1e814c ldr r1, [sp, #0x6c] */
/* @0x1e8150 add r3, sp, #28 */
/* @0x1e8154 bl 0x18a918 <_Z11ReadGIFFilePviPiS0_b> */
/* @0x1e8158 mov r11, r0 */
/* @0x1e815c b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0> */
/* @0x1e8160 ldr r3, [sp, #0x68] */
/* @0x1e8164 movw r2, #0xf08 */
/* @0x1e8168 ldr r1, [pc, #0xf0] */
/* @0x1e816c mul r0, r3, r10 */
/* @0x1e8170 add r1, pc, r1 */
/* @0x1e8174 mov r3, #1 */
/* @0x1e8178 lsl r0, r0, #2 */
/* @0x1e817c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8180 ldr r2, [sp, #0x68] */
/* @0x1e8184 add r3, r10, #3 */
/* @0x1e8188 cmp r2, #0 */
/* @0x1e818c bic r2, r3, #3 */
/* @0x1e8190 mov r11, r0 */
/* @0x1e8194 ble 0x1e7fd4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1b8> */
/* @0x1e8198 lsl r3, r10, #2 */
/* @0x1e819c str r3, [sp, #0xc] */
/* @0x1e81a0 mov r3, r0 */
/* @0x1e81a4 str r11, [sp, #0x10] */
/* @0x1e81a8 str r9, [sp, #0x14] */
/* @0x1e81ac mov r1, r4 */
/* @0x1e81b0 mov r0, #0 */
/* @0x1e81b4 mov r11, r2 */
/* @0x1e81b8 mov r9, r3 */
/* @0x1e81bc cmp r10, #0 */
/* @0x1e81c0 ble 0x1e820c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x3f0> */
/* @0x1e81c4 add r8, r1, r10 */
/* @0x1e81c8 mov r2, r1 */
/* @0x1e81cc mov r12, r9 */
/* @0x1e81d0 ldrb r4, [r2], #1 */
/* @0x1e81d4 cmp r2, r8 */
/* @0x1e81d8 add r3, r5, r4, lsl #2 */
/* @0x1e81dc ldrb r4, [r5, r4, lsl #2] */
/* @0x1e81e0 ldrb r7, [r3, #0x2] */
/* @0x1e81e4 ldrb r6, [r3, #0x3] */
/* @0x1e81e8 ldrb r3, [r3, #0x1] */
/* @0x1e81ec lsl r7, r7, #16 */
/* @0x1e81f0 orr r6, r7, r6, lsl #24 */
/* @0x1e81f4 orr r4, r6, r4 */
/* @0x1e81f8 orr r3, r4, r3, lsl #8 */
/* @0x1e81fc str r3, [r12], #4 */
/* @0x1e8200 bne 0x1e81d0 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x3b4> */
/* @0x1e8204 ldr r2, [sp, #0xc] */
/* @0x1e8208 add r9, r9, r2 */
/* @0x1e820c ldr r3, [sp, #0x68] */
/* @0x1e8210 add r0, r0, #1 */
/* @0x1e8214 add r1, r1, r11 */
/* @0x1e8218 cmp r0, r3 */
/* @0x1e821c bne 0x1e81bc <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x3a0> */
/* @0x1e8220 ldr r11, [sp, #0x10] */
/* @0x1e8224 ldr r9, [sp, #0x14] */
/* @0x1e8228 b 0x1e7fd4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1b8> */
/* @0x1e822c ldr r2, [sp, #0x84] */
/* @0x1e8230 mov r0, r4 */
/* @0x1e8234 ldr r1, [sp, #0x6c] */
/* @0x1e8238 add r3, sp, #28 */
/* @0x1e823c str r2, [sp] */
/* @0x1e8240 add r2, sp, #24 */
/* @0x1e8244 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b> */
/* @0x1e8248 mov r11, r0 */
/* @0x1e824c b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0> */
/* @0x1e8250 andseq r10, r6, r12, lsl #11 */
/* @0x1e8254 .word 0x002059f4 */
/* @0x1e8258 ldrheq r10, [r6], -r4 */
/* @0x1e825c andseq r10, r6, r4, lsr #7 */
/* @0x1e8260 ldrheq r10, [r6], -r4 */

/* ── FUNC 0x1e8264 · CSprite::SetupSWFCollisionMasks(unsigned char**, int*, int) · size=296 · insn=74 */
/* @0x1e8264 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1e8268 subs r8, r1, #0 */
/* @0x1e826c mov r7, r2 */
/* @0x1e8270 mov r4, r3 */
/* @0x1e8274 mov r9, r0 */
/* @0x1e8278 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e827c cmp r2, #0 */
/* @0x1e8280 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e8284 ldrb r3, [r0, #0x31] */
/* @0x1e8288 cmp r3, #0 */
/* @0x1e828c bne 0x1e8380 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x11c> */
/* @0x1e8290 ldrb r3, [r9, #0x30] */
/* @0x1e8294 cmp r3, #0 */
/* @0x1e8298 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e829c cmp r4, #0 */
/* @0x1e82a0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e82a4 ldr r5, [pc, #0xdc] */
/* @0x1e82a8 add r0, r9, #64 */
/* @0x1e82ac lsl r1, r4, #3 */
/* @0x1e82b0 movw r3, #0xf82 */
/* @0x1e82b4 add r5, pc, r5 */
/* @0x1e82b8 mov r2, r5 */
/* @0x1e82bc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e82c0 cmp r4, #0 */
/* @0x1e82c4 str r4, [r9, #0x3c] */
/* @0x1e82c8 ble 0x1e8374 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x110> */
/* @0x1e82cc ldr r3, [r9, #0x1c] */
/* @0x1e82d0 mov r10, #0 */
/* @0x1e82d4 ldr r1, [r9, #0x20] */
/* @0x1e82d8 ldr r0, [r9, #0x40] */
/* @0x1e82dc mul r1, r1, r3 */
/* @0x1e82e0 add r0, r0, r10, lsl #3 */
/* @0x1e82e4 movw r3, #0xf86 */
/* @0x1e82e8 add r0, r0, #4 */
/* @0x1e82ec mov r2, r5 */
/* @0x1e82f0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e82f4 ldr r3, [r9, #0x1c] */
/* @0x1e82f8 ldr r1, [r9, #0x20] */
/* @0x1e82fc ldr r0, [r9, #0x40] */
/* @0x1e8300 mul r1, r1, r3 */
/* @0x1e8304 str r1, [r0, r10, lsl #3] */
/* @0x1e8308 add r10, r10, #1 */
/* @0x1e830c cmp r10, r4 */
/* @0x1e8310 bne 0x1e82e0 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x7c> */
/* @0x1e8314 lsl r10, r10, #2 */
/* @0x1e8318 mov r1, #0 */
/* @0x1e831c ldr r2, [r7, r1] */
/* @0x1e8320 add r3, r0, r1, lsl #1 */
/* @0x1e8324 ldr r6, [r8, r1] */
/* @0x1e8328 cmp r2, #0 */
/* @0x1e832c ldr r12, [r3, #0x4] */
/* @0x1e8330 addgt r2, r6, r2 */
/* @0x1e8334 ble 0x1e8368 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x104> */
/* @0x1e8338 ldrb r5, [r6], #1 */
/* @0x1e833c mov r3, #0 */
/* @0x1e8340 and r4, r5, #127 */
/* @0x1e8344 lsr r5, r5, #7 */
/* @0x1e8348 strb r5, [r12, r3] */
/* @0x1e834c add r3, r3, #1 */
/* @0x1e8350 cmp r4, r3 */
/* @0x1e8354 bge 0x1e8348 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0xe4> */
/* @0x1e8358 cmp r6, r2 */
/* @0x1e835c add r4, r4, #1 */
/* @0x1e8360 add r12, r12, r4 */
/* @0x1e8364 bne 0x1e8338 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0xd4> */
/* @0x1e8368 add r1, r1, #4 */
/* @0x1e836c cmp r1, r10 */
/* @0x1e8370 bne 0x1e831c <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0xb8> */
/* @0x1e8374 mov r3, #1 */
/* @0x1e8378 strb r3, [r9, #0x31] */
/* @0x1e837c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e8380 bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv> */
/* @0x1e8384 b 0x1e8290 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x2c> */
/* @0x1e8388 andseq r10, r6, r0, ror r1 */

/* ── FUNC 0x1e838c · CSprite::BuildSWFData(char*, int, int) · size=5024 · insn=1256 */
/* @0x1e838c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e8390 vpush {d8, d9} */
/* @0x1e8394 cmp r1, #0 */
/* @0x1e8398 sub sp, sp, #204 */
/* @0x1e839c str r0, [sp, #0x2c] */
/* @0x1e83a0 str r2, [sp, #0x64] */
/* @0x1e83a4 str r3, [sp, #0x68] */
/* @0x1e83a8 beq 0x1e96b0 <_ZN7CSprite12BuildSWFDataEPcii+0x1324> */
/* @0x1e83ac ldr r4, [r1] */
/* @0x1e83b0 movw r2, #0x101e */
/* @0x1e83b4 cmp r4, #0 */
/* @0x1e83b8 str r4, [sp, #0x58] */
/* @0x1e83bc addge r1, r1, #4 */
/* @0x1e83c0 ldrlt r4, [sp, #0x58] */
/* @0x1e83c4 movge r5, #4 */
/* @0x1e83c8 ldrlt r12, [r1, #0x4] */
/* @0x1e83cc addlt r1, r1, #8 */
/* @0x1e83d0 strge r5, [sp, #0x44] */
/* @0x1e83d4 biclt r4, r4, #-2147483648 */
/* @0x1e83d8 strlt r4, [sp, #0x58] */
/* @0x1e83dc ldr r5, [sp, #0x58] */
/* @0x1e83e0 strlt r12, [sp, #0x44] */
/* @0x1e83e4 cmp r5, #0 */
/* @0x1e83e8 strne r1, [sp, #0x60] */
/* @0x1e83ec addne r3, r5, #3 */
/* @0x1e83f0 ldr r4, [sp, #0x2c] */
/* @0x1e83f4 bicne r3, r3, #3 */
/* @0x1e83f8 ldreq r12, [sp, #0x58] */
/* @0x1e83fc addne r1, r1, r3 */
/* @0x1e8400 mov r3, #1 */
/* @0x1e8404 mov r9, r1 */
/* @0x1e8408 ldr r1, [pc, #0x420] */
/* @0x1e840c ldr r0, [r9], #4 */
/* @0x1e8410 add r1, pc, r1 */
/* @0x1e8414 streq r12, [sp, #0x60] */
/* @0x1e8418 str r0, [r4, #0x80] */
/* @0x1e841c lsl r0, r0, #2 */
/* @0x1e8420 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8424 ldr r2, [r4, #0x80] */
/* @0x1e8428 mov r1, #0 */
/* @0x1e842c lsl r2, r2, #2 */
/* @0x1e8430 str r0, [r4, #0x7c] */
/* @0x1e8434 bl 0xb65b0 <memset@plt> */
/* @0x1e8438 ldr r3, [r4, #0x80] */
/* @0x1e843c cmp r3, #0 */
/* @0x1e8440 ble 0x1e8ff4 <_ZN7CSprite12BuildSWFDataEPcii+0xc68> */
/* @0x1e8444 ldr r5, [pc, #0x3e8] */
/* @0x1e8448 mov r12, #0 */
/* @0x1e844c ldr r4, [pc, #0x3e4] */
/* @0x1e8450 vldr s16, [pc, #980] */
/* @0x1e8454 add r5, pc, r5 */
/* @0x1e8458 str r12, [sp, #0x54] */
/* @0x1e845c add r4, pc, r4 */
/* @0x1e8460 str r5, [sp, #0x5c] */
/* @0x1e8464 str r4, [sp, #0x7c] */
/* @0x1e8468 mov r7, r9 */
/* @0x1e846c str r12, [sp, #0x28] */
/* @0x1e8470 ldr r5, [pc, #0x3c4] */
/* @0x1e8474 ldr r12, [pc, #0x3c4] */
/* @0x1e8478 ldr r4, [pc, #0x3c4] */
/* @0x1e847c add r5, pc, r5 */
/* @0x1e8480 add r12, pc, r12 */
/* @0x1e8484 str r5, [sp, #0x70] */
/* @0x1e8488 add r4, pc, r4 */
/* @0x1e848c str r12, [sp, #0x74] */
/* @0x1e8490 str r4, [sp, #0x78] */
/* @0x1e8494 b 0x1e84e8 <_ZN7CSprite12BuildSWFDataEPcii+0x15c> */
/* @0x1e8498 mov r3, #1 */
/* @0x1e849c mov r0, #8 */
/* @0x1e84a0 ldr r1, [sp, #0x5c] */
/* @0x1e84a4 mov r2, #70 */
/* @0x1e84a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e84ac ldr r4, [sp, #0x2c] */
/* @0x1e84b0 ldr r5, [sp, #0x54] */
/* @0x1e84b4 add r7, r7, #8 */
/* @0x1e84b8 ldr r3, [r4, #0x7c] */
/* @0x1e84bc str r0, [r3, r5] */
/* @0x1e84c0 ldr r12, [sp, #0x2c] */
/* @0x1e84c4 ldr r4, [sp, #0x28] */
/* @0x1e84c8 ldr r5, [sp, #0x54] */
/* @0x1e84cc ldr r3, [r12, #0x80] */
/* @0x1e84d0 add r4, r4, #1 */
/* @0x1e84d4 add r5, r5, #4 */
/* @0x1e84d8 str r4, [sp, #0x28] */
/* @0x1e84dc cmp r3, r4 */
/* @0x1e84e0 str r5, [sp, #0x54] */
/* @0x1e84e4 ble 0x1e8ff0 <_ZN7CSprite12BuildSWFDataEPcii+0xc64> */
/* @0x1e84e8 ldm r7, {r4, r5} */
/* @0x1e84ec cmp r4, #1 */
/* @0x1e84f0 beq 0x1e8560 <_ZN7CSprite12BuildSWFDataEPcii+0x1d4> */
/* @0x1e84f4 cmp r4, #2 */
/* @0x1e84f8 bne 0x1e8498 <_ZN7CSprite12BuildSWFDataEPcii+0x10c> */
/* @0x1e84fc ldr r1, [sp, #0x7c] */
/* @0x1e8500 mov r3, #1 */
/* @0x1e8504 mov r0, #28 */
/* @0x1e8508 mov r2, #70 */
/* @0x1e850c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8510 ldr r12, [sp, #0x2c] */
/* @0x1e8514 ldr r3, [r12, #0x7c] */
/* @0x1e8518 ldr r12, [sp, #0x44] */
/* @0x1e851c cmp r12, #7 */
/* @0x1e8520 ldr r12, [sp, #0x54] */
/* @0x1e8524 mov r1, r0 */
/* @0x1e8528 str r0, [r3, r12] */
/* @0x1e852c stm r0, {r4, r5} */
/* @0x1e8530 ldr r8, [r7, #0x8] */
/* @0x1e8534 ldr r3, [r7, #0xc] */
/* @0x1e8538 ldr r9, [r7, #0x10] */
/* @0x1e853c bls 0x1e8f4c <_ZN7CSprite12BuildSWFDataEPcii+0xbc0> */
/* @0x1e8540 ldr r3, [r7, #0x14] */
/* @0x1e8544 mvn r2, #0 */
/* @0x1e8548 add r7, r7, #24 */
/* @0x1e854c str r2, [r0, #0x8] */
/* @0x1e8550 mov r2, #0 */
/* @0x1e8554 str r2, [r0, #0xc] */
/* @0x1e8558 str r3, [r0, #0x10] */
/* @0x1e855c b 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */
/* @0x1e8560 mov r3, r4 */
/* @0x1e8564 ldr r1, [sp, #0x70] */
/* @0x1e8568 movw r2, #0x102c */
/* @0x1e856c mov r0, #32 */
/* @0x1e8570 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8574 ldr r12, [sp, #0x2c] */
/* @0x1e8578 mov r3, r4 */
/* @0x1e857c ldr r1, [sp, #0x70] */
/* @0x1e8580 add r7, r7, #28 */
/* @0x1e8584 ldr r2, [r12, #0x7c] */
/* @0x1e8588 ldr r12, [sp, #0x54] */
/* @0x1e858c str r0, [sp, #0x48] */
/* @0x1e8590 ldr lr, [sp, #0x48] */
/* @0x1e8594 ldr r0, [r7, #-0x14] */
/* @0x1e8598 str lr, [r2, r12] */
/* @0x1e859c str r0, [lr, #0xc] */
/* @0x1e85a0 ldr r2, [r7, #-0x10] */
/* @0x1e85a4 str r4, [lr] */
/* @0x1e85a8 str r5, [lr, #0x4] */
/* @0x1e85ac str r2, [lr, #0x10] */
/* @0x1e85b0 movw r2, #0x103f */
/* @0x1e85b4 ldr r0, [r7, #-0xc] */
/* @0x1e85b8 ldr r12, [r7, #-0x4] */
/* @0x1e85bc str r0, [lr, #0x14] */
/* @0x1e85c0 ldr r0, [r7, #-0x8] */
/* @0x1e85c4 str r12, [lr, #0x1c] */
/* @0x1e85c8 str r0, [lr, #0x18] */
/* @0x1e85cc add r0, r12, r12, lsl #1 */
/* @0x1e85d0 lsl r0, r0, #3 */
/* @0x1e85d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e85d8 ldr r4, [sp, #0x48] */
/* @0x1e85dc ldr r3, [r4, #0x1c] */
/* @0x1e85e0 cmp r3, #0 */
/* @0x1e85e4 str r0, [r4, #0x8] */
/* @0x1e85e8 beq 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */
/* @0x1e85ec ldr r5, [pc, #0x254] */
/* @0x1e85f0 mov r3, r0 */
/* @0x1e85f4 ldr r12, [pc, #0x250] */
/* @0x1e85f8 mov r4, #0 */
/* @0x1e85fc add r5, pc, r5 */
/* @0x1e8600 str r5, [sp, #0x6c] */
/* @0x1e8604 ldr r5, [pc, #0x244] */
/* @0x1e8608 add r12, pc, r12 */
/* @0x1e860c str r4, [sp, #0x38] */
/* @0x1e8610 add r5, pc, r5 */
/* @0x1e8614 str r12, [sp, #0x4c] */
/* @0x1e8618 str r5, [sp, #0x50] */
/* @0x1e861c ldr r12, [sp, #0x38] */
/* @0x1e8620 add r5, r7, #12 */
/* @0x1e8624 ldr r0, [r7] */
/* @0x1e8628 add r6, r12, r12, lsl #1 */
/* @0x1e862c cmp r0, #0 */
/* @0x1e8630 add r6, r3, r6, lsl #3 */
/* @0x1e8634 str r0, [r6, #0x10] */
/* @0x1e8638 ldr r3, [r7, #0x4] */
/* @0x1e863c str r3, [r6, #0x14] */
/* @0x1e8640 ldr r2, [r7, #0x8] */
/* @0x1e8644 streq r0, [r6, #0x4] */
/* @0x1e8648 str r2, [r6, #0xc] */
/* @0x1e864c bne 0x1e8f2c <_ZN7CSprite12BuildSWFDataEPcii+0xba0> */
/* @0x1e8650 cmp r3, #0 */
/* @0x1e8654 streq r3, [r6, #0x8] */
/* @0x1e8658 bne 0x1e8f10 <_ZN7CSprite12BuildSWFDataEPcii+0xb84> */
/* @0x1e865c ldr r3, [r6, #0xc] */
/* @0x1e8660 cmp r3, #0 */
/* @0x1e8664 streq r3, [r6] */
/* @0x1e8668 bne 0x1e8ef0 <_ZN7CSprite12BuildSWFDataEPcii+0xb64> */
/* @0x1e866c ldr r2, [r6, #0x10] */
/* @0x1e8670 cmp r2, #0 */
/* @0x1e8674 beq 0x1e89dc <_ZN7CSprite12BuildSWFDataEPcii+0x650> */
/* @0x1e8678 ldr r4, [pc, #0x1d4] */
/* @0x1e867c mov r8, #0 */
/* @0x1e8680 ldr r12, [pc, #0x1d0] */
/* @0x1e8684 add r4, pc, r4 */
/* @0x1e8688 str r4, [sp, #0x30] */
/* @0x1e868c add r12, pc, r12 */
/* @0x1e8690 str r12, [sp, #0x34] */
/* @0x1e8694 b 0x1e86c4 <_ZN7CSprite12BuildSWFDataEPcii+0x338> */
/* @0x1e8698 cmp r7, #3 */
/* @0x1e869c beq 0x1e88d0 <_ZN7CSprite12BuildSWFDataEPcii+0x544> */
/* @0x1e86a0 cmp r7, #1 */
/* @0x1e86a4 addne r5, r5, #4 */
/* @0x1e86a8 movne r4, #0 */
/* @0x1e86ac beq 0x1e888c <_ZN7CSprite12BuildSWFDataEPcii+0x500> */
/* @0x1e86b0 ldr r3, [r6, #0x4] */
/* @0x1e86b4 str r4, [r3, r8, lsl #2] */
/* @0x1e86b8 add r8, r8, #1 */
/* @0x1e86bc cmp r2, r8 */
/* @0x1e86c0 bls 0x1e89dc <_ZN7CSprite12BuildSWFDataEPcii+0x650> */
/* @0x1e86c4 ldr r7, [r5] */
/* @0x1e86c8 cmp r7, #2 */
/* @0x1e86cc bne 0x1e8698 <_ZN7CSprite12BuildSWFDataEPcii+0x30c> */
/* @0x1e86d0 movw r2, #0x1079 */
/* @0x1e86d4 mov r3, #1 */
/* @0x1e86d8 mov r0, #92 */
/* @0x1e86dc ldr r1, [sp, #0x4c] */
/* @0x1e86e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e86e4 ldr r12, [sp, #0x44] */
/* @0x1e86e8 ldr r3, [r5, #0x4] */
/* @0x1e86ec add r2, sp, #164 */
/* @0x1e86f0 cmp r12, #7 */
/* @0x1e86f4 addls r5, r5, #8 */
/* @0x1e86f8 str r3, [r0, #0x4] */
/* @0x1e86fc mov r4, r0 */
/* @0x1e8700 ldrhi r3, [r5, #0x8] */
/* @0x1e8704 addhi r5, r5, #12 */
/* @0x1e8708 mvnls r3, #0 */
/* @0x1e870c str r3, [r0, #0x8] */
/* @0x1e8710 add r0, r5, #36 */
/* @0x1e8714 mov r3, r5 */
/* @0x1e8718 ldr r1, [r3], #4 */
/* @0x1e871c cmp r3, r0 */
/* @0x1e8720 str r1, [r2], #4 */
/* @0x1e8724 bne 0x1e8718 <_ZN7CSprite12BuildSWFDataEPcii+0x38c> */
/* @0x1e8728 ldr r1, [sp, #0xa4] */
/* @0x1e872c mov r3, #1065353216 */
/* @0x1e8730 ldr r2, [sp, #0xa8] */
/* @0x1e8734 vstr s16, [r4, #68] */
/* @0x1e8738 str r3, [r4, #0x48] */
/* @0x1e873c vstr s16, [r4, #56] */
/* @0x1e8740 str r1, [r4, #0xc] */
/* @0x1e8744 vstr s16, [r4, #48] */
/* @0x1e8748 str r2, [r4, #0x1c] */
/* @0x1e874c vstr s16, [r4, #44] */
/* @0x1e8750 ldr r1, [sp, #0xac] */
/* @0x1e8754 vstr s16, [r4, #40] */
/* @0x1e8758 ldr r2, [sp, #0xb0] */
/* @0x1e875c vstr s16, [r4, #36] */
/* @0x1e8760 str r3, [r4, #0x34] */
/* @0x1e8764 vstr s16, [r4, #24] */
/* @0x1e8768 str r1, [r4, #0x3c] */
/* @0x1e876c vstr s16, [r4, #20] */
/* @0x1e8770 str r2, [r4, #0x10] */
/* @0x1e8774 mov r3, #1 */
/* @0x1e8778 ldr r1, [sp, #0xb4] */
/* @0x1e877c add r5, r5, #40 */
/* @0x1e8780 ldr r2, [sp, #0xb8] */
/* @0x1e8784 str r1, [r4, #0x20] */
/* @0x1e8788 str r2, [r4, #0x40] */
/* @0x1e878c movw r2, #0x10a4 */
/* @0x1e8790 ldr r0, [r5, #-0x4] */
/* @0x1e8794 ldr r1, [sp, #0x50] */
/* @0x1e8798 str r0, [r4, #0x4c] */
/* @0x1e879c lsl r0, r0, #3 */
/* @0x1e87a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e87a4 ldr r11, [r4, #0x4c] */
/* @0x1e87a8 cmp r11, #0 */
/* @0x1e87ac str r0, [r4, #0x50] */
/* @0x1e87b0 ble 0x1e8804 <_ZN7CSprite12BuildSWFDataEPcii+0x478> */
/* @0x1e87b4 lsl r11, r11, #3 */
/* @0x1e87b8 mov r2, r5 */
/* @0x1e87bc mov r12, #0 */
/* @0x1e87c0 ldr r1, [r2] */
/* @0x1e87c4 mov r3, r0 */
/* @0x1e87c8 add r2, r2, #8 */
/* @0x1e87cc str r1, [r3, r12]! */
/* @0x1e87d0 add r12, r12, #8 */
/* @0x1e87d4 ldrb r1, [r2, #-0x2] */
/* @0x1e87d8 cmp r12, r11 */
/* @0x1e87dc ldrb r10, [r2, #-0x3] */
/* @0x1e87e0 ldrb r9, [r2, #-0x4] */
/* @0x1e87e4 ldrb lr, [r2, #-0x1] */
/* @0x1e87e8 lsl r1, r1, #16 */
/* @0x1e87ec orr r1, r1, r10, lsl #8 */
/* @0x1e87f0 orr r1, r1, r9 */
/* @0x1e87f4 orr r1, r1, lr, lsl #24 */
/* @0x1e87f8 str r1, [r3, #0x4] */
/* @0x1e87fc bne 0x1e87c0 <_ZN7CSprite12BuildSWFDataEPcii+0x434> */
/* @0x1e8800 add r5, r5, r12 */
/* @0x1e8804 mvn r2, #0 */
/* @0x1e8808 mov r3, #0 */
/* @0x1e880c str r2, [r4, #0x54] */
/* @0x1e8810 mov r1, r4 */
/* @0x1e8814 ldr r0, [sp, #0x2c] */
/* @0x1e8818 str r3, [r4, #0x58] */
/* @0x1e881c bl 0x1e7c8c <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData> */
/* @0x1e8820 str r7, [r4] */
/* @0x1e8824 ldr r2, [r6, #0x10] */
/* @0x1e8828 b 0x1e86b0 <_ZN7CSprite12BuildSWFDataEPcii+0x324> */
/* @0x1e882c andeq r0, r0, r0 */
/* @0x1e8830 andseq r10, r6, r4, lsl r0 */
/* @0x1e8834 ldrsbeq r8, [r4], -r12 */
/* @0x1e8838 ldrsbeq r8, [r4], -r4 */
/* @0x1e883c andseq r9, r6, r8, lsr #31 */
/* @0x1e8840 andseq r9, r6, r4, lsr #31 */
/* @0x1e8844 mulseq r6, r12, pc */
/* @0x1e8848 andseq r9, r6, r8, lsr #28 */
/* @0x1e884c andseq r9, r6, r12, lsl lr */
/* @0x1e8850 andseq r9, r6, r4, lsl lr */
/* @0x1e8854 andseq r9, r6, r0, lsr #27 */
/* @0x1e8858 mulseq r6, r8, sp */
/* @0x1e885c andseq r9, r6, r0, ror #19 */
/* @0x1e8860 ldrsbeq r9, [r6], -r8 */
/* @0x1e8864 ldrsbeq r9, [r6], -r0 */
/* @0x1e8868 ldrsbeq r8, [r4], -r4 */
/* @0x1e886c andseq r8, r4, r4, asr #11 */
/* @0x1e8870 ldrheq r8, [r4], -r12 */
/* @0x1e8874 andseq r8, r4, r12, lsr #3 */
/* @0x1e8878 andseq r8, r4, r0, lsl #3 */
/* @0x1e887c andseq r8, r4, r4, asr r1 */
/* @0x1e8880 andseq r8, r4, r12, lsr #32 */
/* @0x1e8884 eoreq r7, r0, r12, lsr #27 */
/* @0x1e8888 andseq r7, r4, r4, asr pc */
/* @0x1e888c ldr r1, [sp, #0x34] */
/* @0x1e8890 movw r2, #0x1066 */
/* @0x1e8894 mov r3, r7 */
/* @0x1e8898 mov r0, #8 */
/* @0x1e889c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e88a0 ldrb r3, [r5, #0x6] */
/* @0x1e88a4 ldrb r1, [r5, #0x4] */
/* @0x1e88a8 add r5, r5, #8 */
/* @0x1e88ac ldrb r2, [r5, #-0x1] */
/* @0x1e88b0 lsl r3, r3, #16 */
/* @0x1e88b4 mov r4, r0 */
/* @0x1e88b8 ldrb r0, [r5, #-0x3] */
/* @0x1e88bc orr r3, r3, r0, lsl #8 */
/* @0x1e88c0 orr r3, r3, r1 */
/* @0x1e88c4 orr r3, r3, r2, lsl #24 */
/* @0x1e88c8 str r3, [r4, #0x4] */
/* @0x1e88cc b 0x1e8820 <_ZN7CSprite12BuildSWFDataEPcii+0x494> */
/* @0x1e88d0 movw r2, #0x10c3 */
/* @0x1e88d4 mov r3, #1 */
/* @0x1e88d8 mov r0, #80 */
/* @0x1e88dc ldr r1, [sp, #0x30] */
/* @0x1e88e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e88e4 ldr r2, [r5, #0x4] */
/* @0x1e88e8 ldr r12, [sp, #0x28] */
/* @0x1e88ec mvn r3, #0 */
/* @0x1e88f0 cmp r12, #0 */
/* @0x1e88f4 add r12, r5, #12 */
/* @0x1e88f8 mov r4, r0 */
/* @0x1e88fc str r2, [r0, #0x4] */
/* @0x1e8900 ldr r0, [r5, #0x8] */
/* @0x1e8904 str r3, [r4, #0xc] */
/* @0x1e8908 str r0, [r4, #0x8] */
/* @0x1e890c beq 0x1e8950 <_ZN7CSprite12BuildSWFDataEPcii+0x5c4> */
/* @0x1e8910 ldr lr, [sp, #0x2c] */
/* @0x1e8914 ldr r2, [lr, #0x7c] */
/* @0x1e8918 ldr r3, [r2] */
/* @0x1e891c ldr r3, [r3, #0x4] */
/* @0x1e8920 cmp r0, r3 */
/* @0x1e8924 movne r3, #0 */
/* @0x1e8928 ldrne lr, [sp, #0x28] */
/* @0x1e892c bne 0x1e8944 <_ZN7CSprite12BuildSWFDataEPcii+0x5b8> */
/* @0x1e8930 b 0x1e89d0 <_ZN7CSprite12BuildSWFDataEPcii+0x644> */
/* @0x1e8934 ldr r1, [r2, #0x4]! */
/* @0x1e8938 ldr r1, [r1, #0x4] */
/* @0x1e893c cmp r0, r1 */
/* @0x1e8940 beq 0x1e89d4 <_ZN7CSprite12BuildSWFDataEPcii+0x648> */
/* @0x1e8944 add r3, r3, #1 */
/* @0x1e8948 cmp r3, lr */
/* @0x1e894c bne 0x1e8934 <_ZN7CSprite12BuildSWFDataEPcii+0x5a8> */
/* @0x1e8950 add r2, sp, #164 */
/* @0x1e8954 add r0, r12, #36 */
/* @0x1e8958 mov r3, r12 */
/* @0x1e895c ldr r1, [r3], #4 */
/* @0x1e8960 cmp r3, r0 */
/* @0x1e8964 str r1, [r2], #4 */
/* @0x1e8968 bne 0x1e895c <_ZN7CSprite12BuildSWFDataEPcii+0x5d0> */
/* @0x1e896c ldr r2, [sp, #0xa4] */
/* @0x1e8970 mov r3, #1065353216 */
/* @0x1e8974 str r3, [r4, #0x4c] */
/* @0x1e8978 add r5, r5, #48 */
/* @0x1e897c str r3, [r4, #0x38] */
/* @0x1e8980 vstr s16, [r4, #72] */
/* @0x1e8984 str r2, [r4, #0x10] */
/* @0x1e8988 vstr s16, [r4, #60] */
/* @0x1e898c ldr r2, [sp, #0xa8] */
/* @0x1e8990 vstr s16, [r4, #52] */
/* @0x1e8994 ldr r3, [sp, #0xb8] */
/* @0x1e8998 vstr s16, [r4, #48] */
/* @0x1e899c vstr s16, [r4, #44] */
/* @0x1e89a0 vstr s16, [r4, #40] */
/* @0x1e89a4 str r2, [r4, #0x20] */
/* @0x1e89a8 vstr s16, [r4, #28] */
/* @0x1e89ac ldr r2, [sp, #0xac] */
/* @0x1e89b0 vstr s16, [r4, #24] */
/* @0x1e89b4 str r3, [r4, #0x44] */
/* @0x1e89b8 str r2, [r4, #0x40] */
/* @0x1e89bc ldr r2, [sp, #0xb0] */
/* @0x1e89c0 str r2, [r4, #0x14] */
/* @0x1e89c4 ldr r2, [sp, #0xb4] */
/* @0x1e89c8 str r2, [r4, #0x24] */
/* @0x1e89cc b 0x1e8820 <_ZN7CSprite12BuildSWFDataEPcii+0x494> */
/* @0x1e89d0 mov r3, #0 */
/* @0x1e89d4 str r3, [r4, #0xc] */
/* @0x1e89d8 b 0x1e8950 <_ZN7CSprite12BuildSWFDataEPcii+0x5c4> */
/* @0x1e89dc ldr r7, [r6, #0x14] */
/* @0x1e89e0 cmp r7, #0 */
/* @0x1e89e4 beq 0x1e8fe8 <_ZN7CSprite12BuildSWFDataEPcii+0xc5c> */
/* @0x1e89e8 ldr r3, [r6, #0x8] */
/* @0x1e89ec add r7, r5, r7, lsl #2 */
/* @0x1e89f0 sub r3, r3, #4 */
/* @0x1e89f4 ldrb r2, [r5, #0x2] */
/* @0x1e89f8 add r5, r5, #4 */
/* @0x1e89fc ldrb r12, [r5, #-0x3] */
/* @0x1e8a00 ldrb r0, [r5, #-0x4] */
/* @0x1e8a04 ldrb r1, [r5, #-0x1] */
/* @0x1e8a08 lsl r2, r2, #16 */
/* @0x1e8a0c orr r2, r2, r12, lsl #8 */
/* @0x1e8a10 cmp r5, r7 */
/* @0x1e8a14 orr r2, r2, r0 */
/* @0x1e8a18 orr r2, r2, r1, lsl #24 */
/* @0x1e8a1c str r2, [r3, #0x4]! */
/* @0x1e8a20 bne 0x1e89f4 <_ZN7CSprite12BuildSWFDataEPcii+0x668> */
/* @0x1e8a24 ldr r3, [r6, #0xc] */
/* @0x1e8a28 cmp r3, #0 */
/* @0x1e8a2c beq 0x1e8d30 <_ZN7CSprite12BuildSWFDataEPcii+0x9a4> */
/* @0x1e8a30 ldr r9, [pc, #-0x1dc] */
/* @0x1e8a34 mov r5, #0 */
/* @0x1e8a38 ldr r10, [pc, #-0x1e0] */
/* @0x1e8a3c mov r8, r5 */
/* @0x1e8a40 ldr r11, [pc, #-0x1e4] */
/* @0x1e8a44 add r9, pc, r9 */
/* @0x1e8a48 ldr r4, [pc, #-0x1e8] */
/* @0x1e8a4c add r10, pc, r10 */
/* @0x1e8a50 str r9, [sp, #0x40] */
/* @0x1e8a54 add r11, pc, r11 */
/* @0x1e8a58 ldr r9, [sp, #0x44] */
/* @0x1e8a5c add r4, pc, r4 */
/* @0x1e8a60 ldr r12, [pc, #-0x1fc] */
/* @0x1e8a64 str r4, [sp, #0x30] */
/* @0x1e8a68 ldr r4, [pc, #-0x200] */
/* @0x1e8a6c add r12, pc, r12 */
/* @0x1e8a70 str r12, [sp, #0x34] */
/* @0x1e8a74 add r4, pc, r4 */
/* @0x1e8a78 str r4, [sp, #0x3c] */
/* @0x1e8a7c ldr r4, [r6] */
/* @0x1e8a80 cmp r9, #4 */
/* @0x1e8a84 ldr r3, [r7] */
/* @0x1e8a88 add r4, r4, r5 */
/* @0x1e8a8c str r3, [r4, #0x24] */
/* @0x1e8a90 ldr r3, [r7, #0x4] */
/* @0x1e8a94 str r3, [r4, #0x28] */
/* @0x1e8a98 ldr r3, [r7, #0x8] */
/* @0x1e8a9c str r3, [r4, #0x2c] */
/* @0x1e8aa0 ldr r0, [r7, #0xc] */
/* @0x1e8aa4 str r0, [r4, #0x30] */
/* @0x1e8aa8 ldr r3, [r7, #0x10] */
/* @0x1e8aac str r3, [r4, #0x34] */
/* @0x1e8ab0 ldr r3, [r7, #0x14] */
/* @0x1e8ab4 str r3, [r4, #0x38] */
/* @0x1e8ab8 ldr r3, [r7, #0x18] */
/* @0x1e8abc str r3, [r4, #0x3c] */
/* @0x1e8ac0 ldr r3, [r7, #0x1c] */
/* @0x1e8ac4 str r3, [r4, #0x40] */
/* @0x1e8ac8 bls 0x1e8d54 <_ZN7CSprite12BuildSWFDataEPcii+0x9c8> */
/* @0x1e8acc ldr r3, [r7, #0x20] */
/* @0x1e8ad0 cmp r9, #5 */
/* @0x1e8ad4 str r3, [r4, #0x44] */
/* @0x1e8ad8 ldr r3, [r7, #0x24] */
/* @0x1e8adc str r3, [r4, #0x48] */
/* @0x1e8ae0 beq 0x1e9724 <_ZN7CSprite12BuildSWFDataEPcii+0x1398> */
/* @0x1e8ae4 ldr r3, [r7, #0x28] */
/* @0x1e8ae8 cmp r0, #0 */
/* @0x1e8aec add r7, r7, #48 */
/* @0x1e8af0 str r3, [r4, #0x4c] */
/* @0x1e8af4 ldr r3, [r7, #-0x4] */
/* @0x1e8af8 streq r0, [r4] */
/* @0x1e8afc str r3, [r4, #0x50] */
/* @0x1e8b00 bne 0x1e8d7c <_ZN7CSprite12BuildSWFDataEPcii+0x9f0> */
/* @0x1e8b04 ldr r0, [r4, #0x34] */
/* @0x1e8b08 cmp r0, #0 */
/* @0x1e8b0c streq r0, [r4, #0x4] */
/* @0x1e8b10 bne 0x1e8da4 <_ZN7CSprite12BuildSWFDataEPcii+0xa18> */
/* @0x1e8b14 ldr r3, [r4, #0x38] */
/* @0x1e8b18 cmp r3, #0 */
/* @0x1e8b1c streq r3, [r4, #0x8] */
/* @0x1e8b20 bne 0x1e8dcc <_ZN7CSprite12BuildSWFDataEPcii+0xa40> */
/* @0x1e8b24 ldr r0, [r4, #0x3c] */
/* @0x1e8b28 cmp r0, #0 */
/* @0x1e8b2c streq r0, [r4, #0xc] */
/* @0x1e8b30 bne 0x1e8df8 <_ZN7CSprite12BuildSWFDataEPcii+0xa6c> */
/* @0x1e8b34 ldr r3, [r4, #0x40] */
/* @0x1e8b38 cmp r3, #0 */
/* @0x1e8b3c streq r3, [r4, #0x10] */
/* @0x1e8b40 bne 0x1e8e20 <_ZN7CSprite12BuildSWFDataEPcii+0xa94> */
/* @0x1e8b44 ldr r0, [r4, #0x44] */
/* @0x1e8b48 cmp r0, #0 */
/* @0x1e8b4c streq r0, [r4, #0x14] */
/* @0x1e8b50 bne 0x1e8e4c <_ZN7CSprite12BuildSWFDataEPcii+0xac0> */
/* @0x1e8b54 ldr r0, [r4, #0x48] */
/* @0x1e8b58 cmp r0, #0 */
/* @0x1e8b5c streq r0, [r4, #0x18] */
/* @0x1e8b60 bne 0x1e8e74 <_ZN7CSprite12BuildSWFDataEPcii+0xae8> */
/* @0x1e8b64 ldr r0, [r4, #0x4c] */
/* @0x1e8b68 cmp r0, #0 */
/* @0x1e8b6c streq r0, [r4, #0x1c] */
/* @0x1e8b70 bne 0x1e8ea0 <_ZN7CSprite12BuildSWFDataEPcii+0xb14> */
/* @0x1e8b74 ldr r2, [r4, #0x50] */
/* @0x1e8b78 cmp r2, #0 */
/* @0x1e8b7c streq r2, [r4, #0x20] */
/* @0x1e8b80 bne 0x1e8ecc <_ZN7CSprite12BuildSWFDataEPcii+0xb40> */
/* @0x1e8b84 ldr r12, [r4, #0x30] */
/* @0x1e8b88 lsls lr, r12, #1 */
/* @0x1e8b8c beq 0x1e8bb4 <_ZN7CSprite12BuildSWFDataEPcii+0x828> */
/* @0x1e8b90 ldr r3, [r4] */
/* @0x1e8b94 lsl r12, r12, #3 */
/* @0x1e8b98 mov r1, r7 */
/* @0x1e8b9c add r0, r3, r12 */
/* @0x1e8ba0 ldr lr, [r1], #4 */
/* @0x1e8ba4 str lr, [r3], #4 */
/* @0x1e8ba8 cmp r3, r0 */
/* @0x1e8bac bne 0x1e8ba0 <_ZN7CSprite12BuildSWFDataEPcii+0x814> */
/* @0x1e8bb0 add r7, r7, r12 */
/* @0x1e8bb4 ldr r12, [r4, #0x34] */
/* @0x1e8bb8 lsls lr, r12, #1 */
/* @0x1e8bbc beq 0x1e8be0 <_ZN7CSprite12BuildSWFDataEPcii+0x854> */
/* @0x1e8bc0 ldr r3, [r4, #0x4] */
/* @0x1e8bc4 sub r1, r7, #4 */
/* @0x1e8bc8 add r12, r3, r12, lsl #2 */
/* @0x1e8bcc ldr r0, [r1, #0x4]! */
/* @0x1e8bd0 strh r0, [r3], #2 */
/* @0x1e8bd4 cmp r3, r12 */
/* @0x1e8bd8 bne 0x1e8bcc <_ZN7CSprite12BuildSWFDataEPcii+0x840> */
/* @0x1e8bdc add r7, r7, lr, lsl #2 */
/* @0x1e8be0 ldr lr, [r4, #0x38] */
/* @0x1e8be4 adds lr, lr, lr, lsl #1 */
/* @0x1e8be8 beq 0x1e8c0c <_ZN7CSprite12BuildSWFDataEPcii+0x880> */
/* @0x1e8bec ldr r3, [r4, #0x8] */
/* @0x1e8bf0 sub r1, r7, #4 */
/* @0x1e8bf4 add r12, r3, lr, lsl #1 */
/* @0x1e8bf8 ldr r0, [r1, #0x4]! */
/* @0x1e8bfc strh r0, [r3], #2 */
/* @0x1e8c00 cmp r3, r12 */
/* @0x1e8c04 bne 0x1e8bf8 <_ZN7CSprite12BuildSWFDataEPcii+0x86c> */
/* @0x1e8c08 add r7, r7, lr, lsl #2 */
/* @0x1e8c0c ldr r12, [r4, #0x3c] */
/* @0x1e8c10 lsls r0, r12, #1 */
/* @0x1e8c14 beq 0x1e8c3c <_ZN7CSprite12BuildSWFDataEPcii+0x8b0> */
/* @0x1e8c18 ldr r3, [r4, #0xc] */
/* @0x1e8c1c lsl r12, r12, #3 */
/* @0x1e8c20 mov r1, r7 */
/* @0x1e8c24 add r0, r3, r12 */
/* @0x1e8c28 ldr lr, [r1], #4 */
/* @0x1e8c2c str lr, [r3], #4 */
/* @0x1e8c30 cmp r3, r0 */
/* @0x1e8c34 bne 0x1e8c28 <_ZN7CSprite12BuildSWFDataEPcii+0x89c> */
/* @0x1e8c38 add r7, r7, r12 */
/* @0x1e8c3c ldr lr, [r4, #0x40] */
/* @0x1e8c40 adds lr, lr, lr, lsl #1 */
/* @0x1e8c44 beq 0x1e8c68 <_ZN7CSprite12BuildSWFDataEPcii+0x8dc> */
/* @0x1e8c48 ldr r3, [r4, #0x10] */
/* @0x1e8c4c sub r1, r7, #4 */
/* @0x1e8c50 add r12, r3, lr, lsl #1 */
/* @0x1e8c54 ldr r0, [r1, #0x4]! */
/* @0x1e8c58 strh r0, [r3], #2 */
/* @0x1e8c5c cmp r3, r12 */
/* @0x1e8c60 bne 0x1e8c54 <_ZN7CSprite12BuildSWFDataEPcii+0x8c8> */
/* @0x1e8c64 add r7, r7, lr, lsl #2 */
/* @0x1e8c68 ldr r12, [r4, #0x44] */
/* @0x1e8c6c lsls lr, r12, #1 */
/* @0x1e8c70 beq 0x1e8c94 <_ZN7CSprite12BuildSWFDataEPcii+0x908> */
/* @0x1e8c74 ldr r3, [r4, #0x14] */
/* @0x1e8c78 sub r1, r7, #4 */
/* @0x1e8c7c add r12, r3, r12, lsl #2 */
/* @0x1e8c80 ldr r0, [r1, #0x4]! */
/* @0x1e8c84 strh r0, [r3], #2 */
/* @0x1e8c88 cmp r3, r12 */
/* @0x1e8c8c bne 0x1e8c80 <_ZN7CSprite12BuildSWFDataEPcii+0x8f4> */
/* @0x1e8c90 add r7, r7, lr, lsl #2 */
/* @0x1e8c94 ldr r12, [r4, #0x48] */
/* @0x1e8c98 lsls r1, r12, #1 */
/* @0x1e8c9c beq 0x1e8cc4 <_ZN7CSprite12BuildSWFDataEPcii+0x938> */
/* @0x1e8ca0 ldr r3, [r4, #0x18] */
/* @0x1e8ca4 lsl r12, r12, #3 */
/* @0x1e8ca8 mov r1, r7 */
/* @0x1e8cac add r0, r12, r3 */
/* @0x1e8cb0 ldr lr, [r1], #4 */
/* @0x1e8cb4 str lr, [r3], #4 */
/* @0x1e8cb8 cmp r3, r0 */
/* @0x1e8cbc bne 0x1e8cb0 <_ZN7CSprite12BuildSWFDataEPcii+0x924> */
/* @0x1e8cc0 add r7, r7, r12 */
/* @0x1e8cc4 ldr r12, [r4, #0x4c] */
/* @0x1e8cc8 lsls lr, r12, #1 */
/* @0x1e8ccc beq 0x1e8cf0 <_ZN7CSprite12BuildSWFDataEPcii+0x964> */
/* @0x1e8cd0 ldr r3, [r4, #0x1c] */
/* @0x1e8cd4 sub r1, r7, #4 */
/* @0x1e8cd8 add r12, r3, r12, lsl #2 */
/* @0x1e8cdc ldr r0, [r1, #0x4]! */
/* @0x1e8ce0 strh r0, [r3], #2 */
/* @0x1e8ce4 cmp r3, r12 */
/* @0x1e8ce8 bne 0x1e8cdc <_ZN7CSprite12BuildSWFDataEPcii+0x950> */
/* @0x1e8cec add r7, r7, lr, lsl #2 */
/* @0x1e8cf0 lsls r3, r2, #1 */
/* @0x1e8cf4 beq 0x1e8d1c <_ZN7CSprite12BuildSWFDataEPcii+0x990> */
/* @0x1e8cf8 ldr r3, [r4, #0x20] */
/* @0x1e8cfc lsl r2, r2, #3 */
/* @0x1e8d00 mov r1, r7 */
/* @0x1e8d04 add r12, r2, r3 */
/* @0x1e8d08 ldr r0, [r1], #4 */
/* @0x1e8d0c str r0, [r3], #4 */
/* @0x1e8d10 cmp r3, r12 */
/* @0x1e8d14 bne 0x1e8d08 <_ZN7CSprite12BuildSWFDataEPcii+0x97c> */
/* @0x1e8d18 add r7, r7, r2 */
/* @0x1e8d1c ldr r3, [r6, #0xc] */
/* @0x1e8d20 add r8, r8, #1 */
/* @0x1e8d24 add r5, r5, #84 */
/* @0x1e8d28 cmp r3, r8 */
/* @0x1e8d2c bhi 0x1e8a7c <_ZN7CSprite12BuildSWFDataEPcii+0x6f0> */
/* @0x1e8d30 ldr r4, [sp, #0x48] */
/* @0x1e8d34 ldr r5, [sp, #0x38] */
/* @0x1e8d38 ldr r3, [r4, #0x1c] */
/* @0x1e8d3c add r5, r5, #1 */
/* @0x1e8d40 str r5, [sp, #0x38] */
/* @0x1e8d44 cmp r3, r5 */
/* @0x1e8d48 bls 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */
/* @0x1e8d4c ldr r3, [r4, #0x8] */
/* @0x1e8d50 b 0x1e861c <_ZN7CSprite12BuildSWFDataEPcii+0x290> */
/* @0x1e8d54 add r7, r7, #32 */
/* @0x1e8d58 mov r3, #0 */
/* @0x1e8d5c str r3, [r4, #0x44] */
/* @0x1e8d60 str r3, [r4, #0x48] */
/* @0x1e8d64 cmp r0, #0 */
/* @0x1e8d68 mov r3, #0 */
/* @0x1e8d6c streq r0, [r4] */
/* @0x1e8d70 str r3, [r4, #0x4c] */
/* @0x1e8d74 str r3, [r4, #0x50] */
/* @0x1e8d78 beq 0x1e8b04 <_ZN7CSprite12BuildSWFDataEPcii+0x778> */
/* @0x1e8d7c lsl r0, r0, #3 */
/* @0x1e8d80 ldr r1, [sp, #0x40] */
/* @0x1e8d84 movw r2, #0x1137 */
/* @0x1e8d88 mov r3, #1 */
/* @0x1e8d8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8d90 str r0, [r4] */
/* @0x1e8d94 ldr r0, [r4, #0x34] */
/* @0x1e8d98 cmp r0, #0 */
/* @0x1e8d9c streq r0, [r4, #0x4] */
/* @0x1e8da0 beq 0x1e8b14 <_ZN7CSprite12BuildSWFDataEPcii+0x788> */
/* @0x1e8da4 mov r3, #1 */
/* @0x1e8da8 lsl r0, r0, #2 */
/* @0x1e8dac mov r1, r10 */
/* @0x1e8db0 movw r2, #0x113c */
/* @0x1e8db4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8db8 ldr r3, [r4, #0x38] */
/* @0x1e8dbc cmp r3, #0 */
/* @0x1e8dc0 streq r3, [r4, #0x8] */
/* @0x1e8dc4 str r0, [r4, #0x4] */
/* @0x1e8dc8 beq 0x1e8b24 <_ZN7CSprite12BuildSWFDataEPcii+0x798> */
/* @0x1e8dcc add r0, r3, r3, lsl #1 */
/* @0x1e8dd0 mov r1, r11 */
/* @0x1e8dd4 mov r3, #1 */
/* @0x1e8dd8 movw r2, #0x1141 */
/* @0x1e8ddc lsl r0, r0, r3 */
/* @0x1e8de0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8de4 str r0, [r4, #0x8] */
/* @0x1e8de8 ldr r0, [r4, #0x3c] */
/* @0x1e8dec cmp r0, #0 */
/* @0x1e8df0 streq r0, [r4, #0xc] */
/* @0x1e8df4 beq 0x1e8b34 <_ZN7CSprite12BuildSWFDataEPcii+0x7a8> */
/* @0x1e8df8 mov r3, #1 */
/* @0x1e8dfc lsl r0, r0, #3 */
/* @0x1e8e00 ldr r1, [sp, #0x30] */
/* @0x1e8e04 mov r2, #70 */
/* @0x1e8e08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8e0c ldr r3, [r4, #0x40] */
/* @0x1e8e10 cmp r3, #0 */
/* @0x1e8e14 streq r3, [r4, #0x10] */
/* @0x1e8e18 str r0, [r4, #0xc] */
/* @0x1e8e1c beq 0x1e8b44 <_ZN7CSprite12BuildSWFDataEPcii+0x7b8> */
/* @0x1e8e20 add r0, r3, r3, lsl #1 */
/* @0x1e8e24 ldr r1, [sp, #0x34] */
/* @0x1e8e28 mov r3, #1 */
/* @0x1e8e2c mov r2, #70 */
/* @0x1e8e30 lsl r0, r0, r3 */
/* @0x1e8e34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8e38 str r0, [r4, #0x10] */
/* @0x1e8e3c ldr r0, [r4, #0x44] */
/* @0x1e8e40 cmp r0, #0 */
/* @0x1e8e44 streq r0, [r4, #0x14] */
/* @0x1e8e48 beq 0x1e8b54 <_ZN7CSprite12BuildSWFDataEPcii+0x7c8> */
/* @0x1e8e4c lsl r0, r0, #2 */
/* @0x1e8e50 ldr r1, [sp, #0x3c] */
/* @0x1e8e54 mov r2, #70 */
/* @0x1e8e58 mov r3, #1 */
/* @0x1e8e5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8e60 str r0, [r4, #0x14] */
/* @0x1e8e64 ldr r0, [r4, #0x48] */
/* @0x1e8e68 cmp r0, #0 */
/* @0x1e8e6c streq r0, [r4, #0x18] */
/* @0x1e8e70 beq 0x1e8b64 <_ZN7CSprite12BuildSWFDataEPcii+0x7d8> */
/* @0x1e8e74 ldr r1, [pc, #-0x608] */
/* @0x1e8e78 lsl r0, r0, #3 */
/* @0x1e8e7c mov r2, #70 */
/* @0x1e8e80 mov r3, #1 */
/* @0x1e8e84 add r1, pc, r1 */
/* @0x1e8e88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8e8c str r0, [r4, #0x18] */
/* @0x1e8e90 ldr r0, [r4, #0x4c] */
/* @0x1e8e94 cmp r0, #0 */
/* @0x1e8e98 streq r0, [r4, #0x1c] */
/* @0x1e8e9c beq 0x1e8b74 <_ZN7CSprite12BuildSWFDataEPcii+0x7e8> */
/* @0x1e8ea0 ldr r1, [pc, #-0x630] */
/* @0x1e8ea4 mov r2, #70 */
/* @0x1e8ea8 lsl r0, r0, #2 */
/* @0x1e8eac mov r3, #1 */
/* @0x1e8eb0 add r1, pc, r1 */
/* @0x1e8eb4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8eb8 ldr r2, [r4, #0x50] */
/* @0x1e8ebc cmp r2, #0 */
/* @0x1e8ec0 streq r2, [r4, #0x20] */
/* @0x1e8ec4 str r0, [r4, #0x1c] */
/* @0x1e8ec8 beq 0x1e8b84 <_ZN7CSprite12BuildSWFDataEPcii+0x7f8> */
/* @0x1e8ecc ldr r1, [pc, #-0x658] */
/* @0x1e8ed0 lsl r0, r2, #3 */
/* @0x1e8ed4 mov r3, #1 */
/* @0x1e8ed8 mov r2, #70 */
/* @0x1e8edc add r1, pc, r1 */
/* @0x1e8ee0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8ee4 ldr r2, [r4, #0x50] */
/* @0x1e8ee8 str r0, [r4, #0x20] */
/* @0x1e8eec b 0x1e8b84 <_ZN7CSprite12BuildSWFDataEPcii+0x7f8> */
/* @0x1e8ef0 mov r0, #84 */
/* @0x1e8ef4 ldr r1, [sp, #0x6c] */
/* @0x1e8ef8 mul r0, r0, r3 */
/* @0x1e8efc movw r2, #0x1057 */
/* @0x1e8f00 mov r3, #1 */
/* @0x1e8f04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8f08 str r0, [r6] */
/* @0x1e8f0c b 0x1e866c <_ZN7CSprite12BuildSWFDataEPcii+0x2e0> */
/* @0x1e8f10 lsl r0, r3, #2 */
/* @0x1e8f14 ldr r1, [sp, #0x78] */
/* @0x1e8f18 movw r2, #0x1052 */
/* @0x1e8f1c mov r3, #1 */
/* @0x1e8f20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8f24 str r0, [r6, #0x8] */
/* @0x1e8f28 b 0x1e865c <_ZN7CSprite12BuildSWFDataEPcii+0x2d0> */
/* @0x1e8f2c mov r3, #1 */
/* @0x1e8f30 lsl r0, r0, #2 */
/* @0x1e8f34 ldr r1, [sp, #0x74] */
/* @0x1e8f38 movw r2, #0x104d */
/* @0x1e8f3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e8f40 ldr r3, [r6, #0x14] */
/* @0x1e8f44 str r0, [r6, #0x4] */
/* @0x1e8f48 b 0x1e8650 <_ZN7CSprite12BuildSWFDataEPcii+0x2c4> */
/* @0x1e8f4c mvn r2, #0 */
/* @0x1e8f50 str r2, [r0, #0x10] */
/* @0x1e8f54 str r2, [r0, #0x8] */
/* @0x1e8f58 mov r5, #0 */
/* @0x1e8f5c ldr r2, [r7, #0x14] */
/* @0x1e8f60 add r12, r7, #32 */
/* @0x1e8f64 ldr lr, [r7, #0x18] */
/* @0x1e8f68 cmp r2, r5 */
/* @0x1e8f6c ldr r6, [r7, #0x1c] */
/* @0x1e8f70 str r5, [r0, #0xc] */
/* @0x1e8f74 movle r0, r12 */
/* @0x1e8f78 addgt r0, r12, r2 */
/* @0x1e8f7c movgt r5, r12 */
/* @0x1e8f80 cmp lr, #0 */
/* @0x1e8f84 add r7, r2, lr */
/* @0x1e8f88 addgt r4, r0, lr */
/* @0x1e8f8c add r7, r7, r6 */
/* @0x1e8f90 movle r4, r0 */
/* @0x1e8f94 movle r0, #0 */
/* @0x1e8f98 cmp r6, #0 */
/* @0x1e8f9c str r5, [sp, #0x10] */
/* @0x1e8fa0 ldr r5, [sp, #0x60] */
/* @0x1e8fa4 movle r4, #0 */
/* @0x1e8fa8 str r4, [sp, #0x18] */
/* @0x1e8fac add r4, r7, #3 */
/* @0x1e8fb0 str r2, [sp, #0x4] */
/* @0x1e8fb4 bic r4, r4, #3 */
/* @0x1e8fb8 str r0, [sp, #0x14] */
/* @0x1e8fbc add r7, r12, r4 */
/* @0x1e8fc0 ldr r12, [sp, #0x58] */
/* @0x1e8fc4 str r9, [sp] */
/* @0x1e8fc8 mov r2, r8 */
/* @0x1e8fcc str lr, [sp, #0x8] */
/* @0x1e8fd0 str r6, [sp, #0xc] */
/* @0x1e8fd4 ldr r0, [sp, #0x2c] */
/* @0x1e8fd8 str r5, [sp, #0x1c] */
/* @0x1e8fdc str r12, [sp, #0x20] */
/* @0x1e8fe0 bl 0x1e7e1c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j> */
/* @0x1e8fe4 b 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */
/* @0x1e8fe8 mov r7, r5 */
/* @0x1e8fec b 0x1e8a24 <_ZN7CSprite12BuildSWFDataEPcii+0x698> */
/* @0x1e8ff0 mov r9, r7 */
/* @0x1e8ff4 ldr r5, [pc, #-0x77c] */
/* @0x1e8ff8 mov r3, #1 */
/* @0x1e8ffc ldr r12, [pc, #-0x780] */
/* @0x1e9000 mov r0, #28 */
/* @0x1e9004 add r5, pc, r5 */
/* @0x1e9008 mov r2, #70 */
/* @0x1e900c add r10, r9, #36 */
/* @0x1e9010 mov r1, r5 */
/* @0x1e9014 str r12, [sp, #0x34] */
/* @0x1e9018 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e901c ldr r12, [sp, #0x34] */
/* @0x1e9020 vldr s14, [r9, #8] */
/* @0x1e9024 ldr r3, [r9] */
/* @0x1e9028 ldr r12, [pc, r12] */
/* @0x1e902c vldr s15, [r12] */
/* @0x1e9030 str r12, [sp, #0x34] */
/* @0x1e9034 vmul.f32 s14, s14, s15 */
/* @0x1e9038 ldr r12, [sp, #0x2c] */
/* @0x1e903c str r0, [r12, #0x84] */
/* @0x1e9040 mov r4, r0 */
/* @0x1e9044 str r3, [r0, #0x4] */
/* @0x1e9048 ldr r3, [r9, #0x4] */
/* @0x1e904c cmp r3, #0 */
/* @0x1e9050 str r3, [r0, #0x18] */
/* @0x1e9054 ldr r12, [r9, #0x18] */
/* @0x1e9058 str r12, [sp, #0x3c] */
/* @0x1e905c ldr r12, [r9, #0x1c] */
/* @0x1e9060 str r12, [sp, #0x44] */
/* @0x1e9064 ldr r12, [r9, #0x20] */
/* @0x1e9068 vstr s14, [r0, #8] */
/* @0x1e906c vldr s14, [r9, #12] */
/* @0x1e9070 vmul.f32 s14, s15, s14 */
/* @0x1e9074 str r12, [sp, #0x48] */
/* @0x1e9078 vstr s14, [r0, #12] */
/* @0x1e907c vldr s14, [r9, #16] */
/* @0x1e9080 vmul.f32 s14, s15, s14 */
/* @0x1e9084 vstr s14, [r0, #16] */
/* @0x1e9088 vldr s14, [r9, #20] */
/* @0x1e908c vmul.f32 s15, s15, s14 */
/* @0x1e9090 vstr s15, [r0, #20] */
/* @0x1e9094 ble 0x1e9698 <_ZN7CSprite12BuildSWFDataEPcii+0x130c> */
/* @0x1e9098 add r0, r3, r3, lsl #1 */
/* @0x1e909c mov r1, r5 */
/* @0x1e90a0 mov r2, #70 */
/* @0x1e90a4 mov r3, #1 */
/* @0x1e90a8 lsl r0, r0, #3 */
/* @0x1e90ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e90b0 ldr r5, [sp, #0x2c] */
/* @0x1e90b4 ldr r3, [r5, #0x84] */
/* @0x1e90b8 ldr r1, [r3, #0x18] */
/* @0x1e90bc mov r2, r3 */
/* @0x1e90c0 cmp r1, #0 */
/* @0x1e90c4 str r0, [r4] */
/* @0x1e90c8 ble 0x1e9334 <_ZN7CSprite12BuildSWFDataEPcii+0xfa8> */
/* @0x1e90cc ldr r12, [pc, #-0x84c] */
/* @0x1e90d0 mov r4, #0 */
/* @0x1e90d4 vldr s16, [pc, #964] */
/* @0x1e90d8 str r4, [sp, #0x38] */
/* @0x1e90dc add r12, pc, r12 */
/* @0x1e90e0 str r4, [sp, #0x30] */
/* @0x1e90e4 str r12, [sp, #0x40] */
/* @0x1e90e8 vldr s14, [r10, #4] */
/* @0x1e90ec ldr r5, [sp, #0x34] */
/* @0x1e90f0 vldr s15, [r5] */
/* @0x1e90f4 vmul.f32 s14, s14, s15 */
/* @0x1e90f8 ldr r6, [r3] */
/* @0x1e90fc add r4, r10, #20 */
/* @0x1e9100 ldr r12, [sp, #0x38] */
/* @0x1e9104 ldr r2, [r10] */
/* @0x1e9108 add r5, r6, r12 */
/* @0x1e910c cmp r2, #0 */
/* @0x1e9110 str r2, [r5, #0x14] */
/* @0x1e9114 vstr s14, [r5, #4] */
/* @0x1e9118 vldr s14, [r10, #8] */
/* @0x1e911c vmul.f32 s14, s15, s14 */
/* @0x1e9120 vstr s14, [r5, #8] */
/* @0x1e9124 vldr s14, [r10, #12] */
/* @0x1e9128 vmul.f32 s14, s15, s14 */
/* @0x1e912c vstr s14, [r5, #12] */
/* @0x1e9130 vldr s14, [r10, #16] */
/* @0x1e9134 vmul.f32 s15, s15, s14 */
/* @0x1e9138 vstr s15, [r5, #16] */
/* @0x1e913c ble 0x1e9524 <_ZN7CSprite12BuildSWFDataEPcii+0x1198> */
/* @0x1e9140 add r0, r2, r2, lsl #3 */
/* @0x1e9144 ldr r1, [sp, #0x40] */
/* @0x1e9148 mov r2, #70 */
/* @0x1e914c mov r3, #1 */
/* @0x1e9150 lsl r0, r0, #4 */
/* @0x1e9154 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e9158 ldr r10, [r5, #0x14] */
/* @0x1e915c ldr r5, [sp, #0x38] */
/* @0x1e9160 cmp r10, #0 */
/* @0x1e9164 str r0, [r6, r5] */
/* @0x1e9168 ble 0x1e9704 <_ZN7CSprite12BuildSWFDataEPcii+0x1378> */
/* @0x1e916c vmov.f32 s14, #1.000000e+00 */
/* @0x1e9170 add r9, r0, #80 */
/* @0x1e9174 add r11, sp, #164 */
/* @0x1e9178 add r12, sp, #132 */
/* @0x1e917c add r7, sp, #148 */
/* @0x1e9180 mov r1, #100 */
/* @0x1e9184 mov r8, r9 */
/* @0x1e9188 mov r3, r0 */
/* @0x1e918c mla r10, r1, r10, r4 */
/* @0x1e9190 ldr r5, [sp, #0x34] */
/* @0x1e9194 vldr s15, [r5] */
/* @0x1e9198 add r1, sp, #144 */
/* @0x1e919c str r1, [sp, #0x28] */
/* @0x1e91a0 ldr r1, [r4] */
/* @0x1e91a4 add r5, r4, #16 */
/* @0x1e91a8 mov r2, #0 */
/* @0x1e91ac str r1, [r3] */
/* @0x1e91b0 ldr r1, [r4, #0x4] */
/* @0x1e91b4 str r1, [r3, #0x4] */
/* @0x1e91b8 ldr r1, [r4, #0x8] */
/* @0x1e91bc str r1, [r3, #0x8] */
/* @0x1e91c0 ldr r1, [r4, #0xc] */
/* @0x1e91c4 str r1, [r3, #0xc] */
/* @0x1e91c8 ldr r1, [r5, r2] */
/* @0x1e91cc str r1, [r12, r2] */
/* @0x1e91d0 add r2, r2, #4 */
/* @0x1e91d4 cmp r2, #16 */
/* @0x1e91d8 bne 0x1e91c8 <_ZN7CSprite12BuildSWFDataEPcii+0xe3c> */
/* @0x1e91dc add r6, r4, #44 */
/* @0x1e91e0 add r2, r4, #28 */
/* @0x1e91e4 add r1, sp, #144 */
/* @0x1e91e8 ldr r5, [r2, #0x4]! */
/* @0x1e91ec cmp r6, r2 */
/* @0x1e91f0 str r5, [r1, #0x4]! */
/* @0x1e91f4 bne 0x1e91e8 <_ZN7CSprite12BuildSWFDataEPcii+0xe5c> */
/* @0x1e91f8 mov r1, r3 */
/* @0x1e91fc mov r2, #0 */
/* @0x1e9200 ldr r5, [r7, r2] */
/* @0x1e9204 add r1, r1, #4 */
/* @0x1e9208 ldr r6, [r12, r2] */
/* @0x1e920c add r2, r2, #4 */
/* @0x1e9210 cmp r2, #16 */
/* @0x1e9214 str r5, [r1, #0x1c] */
/* @0x1e9218 str r6, [r1, #0xc] */
/* @0x1e921c str r5, [r1, #0x2c] */
/* @0x1e9220 bne 0x1e9200 <_ZN7CSprite12BuildSWFDataEPcii+0xe74> */
/* @0x1e9224 mov r2, #0 */
/* @0x1e9228 str r2, [r3, #0x30] */
/* @0x1e922c vldr s13, [r4, #48] */
/* @0x1e9230 vmul.f32 s13, s13, s15 */
/* @0x1e9234 add r5, r4, #100 */
/* @0x1e9238 add r2, r4, #64 */
/* @0x1e923c mov r1, r11 */
/* @0x1e9240 vstr s13, [r3, #64] */
/* @0x1e9244 vldr s13, [r4, #52] */
/* @0x1e9248 vmul.f32 s13, s13, s15 */
/* @0x1e924c vstr s13, [r3, #68] */
/* @0x1e9250 vldr s13, [r4, #56] */
/* @0x1e9254 vmul.f32 s13, s13, s15 */
/* @0x1e9258 vstr s13, [r3, #72] */
/* @0x1e925c vldr s13, [r4, #60] */
/* @0x1e9260 vmul.f32 s13, s13, s15 */
/* @0x1e9264 vstr s13, [r3, #76] */
/* @0x1e9268 ldr r4, [r2], #4 */
/* @0x1e926c cmp r5, r2 */
/* @0x1e9270 str r4, [r1], #4 */
/* @0x1e9274 bne 0x1e9268 <_ZN7CSprite12BuildSWFDataEPcii+0xedc> */
/* @0x1e9278 rsb r2, r0, r8 */
/* @0x1e927c cmp r5, r10 */
/* @0x1e9280 add r2, r2, r9 */
/* @0x1e9284 vstr s14, [r2, #-20] */
/* @0x1e9288 vstr s14, [r2, #-40] */
/* @0x1e928c vstr s14, [r2, #-60] */
/* @0x1e9290 vstr s14, [r2, #-80] */
/* @0x1e9294 vstr s16, [r2, #-24] */
/* @0x1e9298 vstr s16, [r2, #-28] */
/* @0x1e929c vstr s16, [r2, #-32] */
/* @0x1e92a0 vstr s16, [r2, #-36] */
/* @0x1e92a4 vstr s16, [r2, #-44] */
/* @0x1e92a8 vstr s16, [r2, #-48] */
/* @0x1e92ac vstr s16, [r2, #-52] */
/* @0x1e92b0 vstr s16, [r2, #-56] */
/* @0x1e92b4 vstr s16, [r2, #-64] */
/* @0x1e92b8 vstr s16, [r2, #-68] */
/* @0x1e92bc vstr s16, [r2, #-72] */
/* @0x1e92c0 vstr s16, [r2, #-76] */
/* @0x1e92c4 ldr r2, [sp, #0xa4] */
/* @0x1e92c8 mov r4, r5 */
/* @0x1e92cc add r8, r8, #144 */
/* @0x1e92d0 add r3, r3, #144 */
/* @0x1e92d4 str r2, [r3, #-0x40] */
/* @0x1e92d8 ldr r2, [sp, #0xa8] */
/* @0x1e92dc str r2, [r3, #-0x30] */
/* @0x1e92e0 ldr r2, [sp, #0xac] */
/* @0x1e92e4 str r2, [r3, #-0x10] */
/* @0x1e92e8 ldr r2, [sp, #0xb0] */
/* @0x1e92ec str r2, [r3, #-0x3c] */
/* @0x1e92f0 ldr r2, [sp, #0xb4] */
/* @0x1e92f4 str r2, [r3, #-0x2c] */
/* @0x1e92f8 ldr r2, [sp, #0xb8] */
/* @0x1e92fc str r2, [r3, #-0xc] */
/* @0x1e9300 bne 0x1e91a0 <_ZN7CSprite12BuildSWFDataEPcii+0xe14> */
/* @0x1e9304 ldr r4, [sp, #0x2c] */
/* @0x1e9308 ldr r3, [r4, #0x84] */
/* @0x1e930c ldr r5, [sp, #0x30] */
/* @0x1e9310 mov r2, r3 */
/* @0x1e9314 ldr r1, [r3, #0x18] */
/* @0x1e9318 add r5, r5, #1 */
/* @0x1e931c ldr r12, [sp, #0x38] */
/* @0x1e9320 cmp r1, r5 */
/* @0x1e9324 str r5, [sp, #0x30] */
/* @0x1e9328 add r12, r12, #24 */
/* @0x1e932c str r12, [sp, #0x38] */
/* @0x1e9330 bgt 0x1e90e8 <_ZN7CSprite12BuildSWFDataEPcii+0xd5c> */
/* @0x1e9334 ldr r4, [sp, #0x3c] */
/* @0x1e9338 cmp r4, #0 */
/* @0x1e933c bne 0x1e95a0 <_ZN7CSprite12BuildSWFDataEPcii+0x1214> */
/* @0x1e9340 vldr s14, [r2, #12] */
/* @0x1e9344 vldr s15, [r2, #20] */
/* @0x1e9348 ldr r5, [sp, #0x2c] */
/* @0x1e934c vcvt.s32.f32 s14, s14 */
/* @0x1e9350 ldrb r3, [r5, #0x78] */
/* @0x1e9354 cmp r3, #0 */
/* @0x1e9358 vcvt.s32.f32 s15, s15 */
/* @0x1e935c vstr s14, [r5, #28] */
/* @0x1e9360 vstr s15, [r5, #32] */
/* @0x1e9364 bne 0x1e9670 <_ZN7CSprite12BuildSWFDataEPcii+0x12e4> */
/* @0x1e9368 ldr r12, [sp, #0x3c] */
/* @0x1e936c strb r12, [r5, #0x30] */
/* @0x1e9370 ldr r4, [sp, #0x2c] */
/* @0x1e9374 mov r2, #0 */
/* @0x1e9378 mov r3, #1 */
/* @0x1e937c str r2, [r4, #0x4] */
/* @0x1e9380 strb r3, [r4, #0x34] */
/* @0x1e9384 ldr r5, [sp, #0x2c] */
/* @0x1e9388 ldr r12, [sp, #0x64] */
/* @0x1e938c ldr r1, [sp, #0x68] */
/* @0x1e9390 ldr r3, [r5, #0x84] */
/* @0x1e9394 vldr s15, [r3, #8] */
/* @0x1e9398 vcvt.s32.f32 s15, s15 */
/* @0x1e939c vldr s13, [r3, #16] */
/* @0x1e93a0 vldr s14, [r3, #12] */
/* @0x1e93a4 vmov r2, s15 */
/* @0x1e93a8 vldr s15, [r3, #20] */
/* @0x1e93ac vcvt.s32.f32 s13, s13 */
/* @0x1e93b0 str r12, [r5, #0x24] */
/* @0x1e93b4 str r1, [r5, #0x28] */
/* @0x1e93b8 vcvt.s32.f32 s14, s14 */
/* @0x1e93bc vstr s13, [r5, #12] */
/* @0x1e93c0 vcvt.s32.f32 s15, s15 */
/* @0x1e93c4 vstr s14, [r5, #16] */
/* @0x1e93c8 mov r0, r2 */
/* @0x1e93cc str r2, [r5, #0x8] */
/* @0x1e93d0 vmov r2, s13 */
/* @0x1e93d4 vstr s15, [r5, #20] */
/* @0x1e93d8 rsb r2, r2, r1 */
/* @0x1e93dc rsb r0, r0, r12 */
/* @0x1e93e0 ldr r3, [r3, #0x18] */
/* @0x1e93e4 mov r4, #1 */
/* @0x1e93e8 vmov s15, r2 */
/* @0x1e93ec ldr r5, [sp, #0x2c] */
/* @0x1e93f0 vmov s13, r0 */
/* @0x1e93f4 vcvt.f32.s32 s15, s15 */
/* @0x1e93f8 strb r4, [r5, #0x32] */
/* @0x1e93fc str r3, [r5, #0x18] */
/* @0x1e9400 vmul.f32 s15, s15, s15 */
/* @0x1e9404 vcvt.f32.s32 s14, s13 */
/* @0x1e9408 vmla.f32 s15, s14, s14 */
/* @0x1e940c vsqrt.f32 s18, s15 */
/* @0x1e9410 vcmp.f32 s18, s18 */
/* @0x1e9414 vmrs APSR_nzcv, fpscr */
/* @0x1e9418 bne 0x1e96f4 <_ZN7CSprite12BuildSWFDataEPcii+0x1368> */
/* @0x1e941c ldr r4, [sp, #0x2c] */
/* @0x1e9420 ldr r2, [r4, #0x28] */
/* @0x1e9424 ldr r3, [r4, #0xc] */
/* @0x1e9428 ldr r1, [r4, #0x10] */
/* @0x1e942c rsb r3, r3, r2 */
/* @0x1e9430 vmov s15, r3 */
/* @0x1e9434 ldr r3, [r4, #0x24] */
/* @0x1e9438 vcvt.f32.s32 s15, s15 */
/* @0x1e943c rsb r1, r3, r1 */
/* @0x1e9440 vmov s13, r1 */
/* @0x1e9444 vmul.f32 s15, s15, s15 */
/* @0x1e9448 vcvt.f32.s32 s14, s13 */
/* @0x1e944c vmla.f32 s15, s14, s14 */
/* @0x1e9450 vsqrt.f32 s17, s15 */
/* @0x1e9454 vcmp.f32 s17, s17 */
/* @0x1e9458 vmrs APSR_nzcv, fpscr */
/* @0x1e945c bne 0x1e96c0 <_ZN7CSprite12BuildSWFDataEPcii+0x1334> */
/* @0x1e9460 ldr r4, [sp, #0x2c] */
/* @0x1e9464 ldr r1, [r4, #0x14] */
/* @0x1e9468 ldr r0, [r4, #0x8] */
/* @0x1e946c rsb r5, r2, r1 */
/* @0x1e9470 rsb r0, r0, r3 */
/* @0x1e9474 vmov s15, r5 */
/* @0x1e9478 vmov s13, r0 */
/* @0x1e947c vcvt.f32.s32 s15, s15 */
/* @0x1e9480 vmul.f32 s15, s15, s15 */
/* @0x1e9484 vcvt.f32.s32 s14, s13 */
/* @0x1e9488 vmla.f32 s15, s14, s14 */
/* @0x1e948c vsqrt.f32 s16, s15 */
/* @0x1e9490 vcmp.f32 s16, s16 */
/* @0x1e9494 vmrs APSR_nzcv, fpscr */
/* @0x1e9498 bne 0x1e96d8 <_ZN7CSprite12BuildSWFDataEPcii+0x134c> */
/* @0x1e949c b 0x1e94a8 <_ZN7CSprite12BuildSWFDataEPcii+0x111c> */
/* @0x1e94a0 andeq r0, r0, r0 */
/* @0x1e94a4 andseq r8, r6, r4, ror lr */
/* @0x1e94a8 rsb r2, r2, r1 */
/* @0x1e94ac ldr r4, [sp, #0x2c] */
/* @0x1e94b0 vmov s14, r2 */
/* @0x1e94b4 ldr r0, [r4, #0x10] */
/* @0x1e94b8 vcvt.f32.s32 s14, s14 */
/* @0x1e94bc rsb r3, r3, r0 */
/* @0x1e94c0 vmov s13, r3 */
/* @0x1e94c4 vmul.f32 s14, s14, s14 */
/* @0x1e94c8 vcvt.f32.s32 s15, s13 */
/* @0x1e94cc vmla.f32 s14, s15, s15 */
/* @0x1e94d0 vsqrt.f32 s15, s14 */
/* @0x1e94d4 vcmp.f32 s15, s15 */
/* @0x1e94d8 vmrs APSR_nzcv, fpscr */
/* @0x1e94dc bne 0x1e9714 <_ZN7CSprite12BuildSWFDataEPcii+0x1388> */
/* @0x1e94e0 vcmpe.f32 s16, s15 */
/* @0x1e94e4 vmrs APSR_nzcv, fpscr */
/* @0x1e94e8 ble 0x1e9538 <_ZN7CSprite12BuildSWFDataEPcii+0x11ac> */
/* @0x1e94ec vcmpe.f32 s17, s16 */
/* @0x1e94f0 vmrs APSR_nzcv, fpscr */
/* @0x1e94f4 ble 0x1e9554 <_ZN7CSprite12BuildSWFDataEPcii+0x11c8> */
/* @0x1e94f8 vmov.f32 s14, s17 */
/* @0x1e94fc vcmpe.f32 s14, s18 */
/* @0x1e9500 vmrs APSR_nzcv, fpscr */
/* @0x1e9504 bpl 0x1e9574 <_ZN7CSprite12BuildSWFDataEPcii+0x11e8> */
/* @0x1e9508 vcvt.s32.f32 s15, s18 */
/* @0x1e950c ldr r4, [sp, #0x2c] */
/* @0x1e9510 mov r0, #1 */
/* @0x1e9514 vstr s15, [r4, #44] */
/* @0x1e9518 add sp, sp, #204 */
/* @0x1e951c vpop {d8, d9} */
/* @0x1e9520 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e9524 ldr r5, [sp, #0x38] */
/* @0x1e9528 mov r12, #0 */
/* @0x1e952c mov r10, r4 */
/* @0x1e9530 str r12, [r6, r5] */
/* @0x1e9534 b 0x1e930c <_ZN7CSprite12BuildSWFDataEPcii+0xf80> */
/* @0x1e9538 vcmpe.f32 s17, s15 */
/* @0x1e953c vmrs APSR_nzcv, fpscr */
/* @0x1e9540 bgt 0x1e94f8 <_ZN7CSprite12BuildSWFDataEPcii+0x116c> */
/* @0x1e9544 vcmpe.f32 s16, s15 */
/* @0x1e9548 vmrs APSR_nzcv, fpscr */
/* @0x1e954c vmovle.f32 s14, s15 */
/* @0x1e9550 ble 0x1e94fc <_ZN7CSprite12BuildSWFDataEPcii+0x1170> */
/* @0x1e9554 vcmpe.f32 s18, s16 */
/* @0x1e9558 vmrs APSR_nzcv, fpscr */
/* @0x1e955c bgt 0x1e9508 <_ZN7CSprite12BuildSWFDataEPcii+0x117c> */
/* @0x1e9560 vcmpe.f32 s17, s16 */
/* @0x1e9564 vmrs APSR_nzcv, fpscr */
/* @0x1e9568 ble 0x1e9598 <_ZN7CSprite12BuildSWFDataEPcii+0x120c> */
/* @0x1e956c vcvt.s32.f32 s15, s17 */
/* @0x1e9570 b 0x1e950c <_ZN7CSprite12BuildSWFDataEPcii+0x1180> */
/* @0x1e9574 vcmpe.f32 s16, s15 */
/* @0x1e9578 vmrs APSR_nzcv, fpscr */
/* @0x1e957c bgt 0x1e9560 <_ZN7CSprite12BuildSWFDataEPcii+0x11d4> */
/* @0x1e9580 vcmpe.f32 s17, s15 */
/* @0x1e9584 vmrs APSR_nzcv, fpscr */
/* @0x1e9588 bgt 0x1e956c <_ZN7CSprite12BuildSWFDataEPcii+0x11e0> */
/* @0x1e958c vcmpe.f32 s16, s15 */
/* @0x1e9590 vmrs APSR_nzcv, fpscr */
/* @0x1e9594 ble 0x1e96a8 <_ZN7CSprite12BuildSWFDataEPcii+0x131c> */
/* @0x1e9598 vcvt.s32.f32 s15, s16 */
/* @0x1e959c b 0x1e950c <_ZN7CSprite12BuildSWFDataEPcii+0x1180> */
/* @0x1e95a0 ldr r5, [pc, #-0x104] */
/* @0x1e95a4 lsl r6, r4, #2 */
/* @0x1e95a8 movw r2, #0x1286 */
/* @0x1e95ac mov r3, #1 */
/* @0x1e95b0 add r5, pc, r5 */
/* @0x1e95b4 mov r0, r6 */
/* @0x1e95b8 mov r1, r5 */
/* @0x1e95bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e95c0 mov r1, r5 */
/* @0x1e95c4 movw r2, #0x1287 */
/* @0x1e95c8 mov r3, #1 */
/* @0x1e95cc mov r4, r0 */
/* @0x1e95d0 mov r0, r6 */
/* @0x1e95d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e95d8 ldr r12, [sp, #0x3c] */
/* @0x1e95dc cmp r12, #0 */
/* @0x1e95e0 movgt r3, #0 */
/* @0x1e95e4 movgt r2, r10 */
/* @0x1e95e8 mov r5, r0 */
/* @0x1e95ec ble 0x1e9614 <_ZN7CSprite12BuildSWFDataEPcii+0x1288> */
/* @0x1e95f0 ldr r1, [r2], #4 */
/* @0x1e95f4 add r0, r1, #3 */
/* @0x1e95f8 str r1, [r4, r3] */
/* @0x1e95fc bic r1, r0, #3 */
/* @0x1e9600 str r2, [r5, r3] */
/* @0x1e9604 add r3, r3, #4 */
/* @0x1e9608 cmp r3, r6 */
/* @0x1e960c add r2, r2, r1 */
/* @0x1e9610 bne 0x1e95f0 <_ZN7CSprite12BuildSWFDataEPcii+0x1264> */
/* @0x1e9614 ldr r12, [sp, #0x2c] */
/* @0x1e9618 ldr lr, [sp, #0x44] */
/* @0x1e961c ldr r0, [sp, #0x48] */
/* @0x1e9620 ldrb r3, [r12, #0x78] */
/* @0x1e9624 str lr, [r12, #0x1c] */
/* @0x1e9628 cmp r3, #0 */
/* @0x1e962c str r0, [r12, #0x20] */
/* @0x1e9630 ldreq r12, [sp, #0x2c] */
/* @0x1e9634 moveq r3, #1 */
/* @0x1e9638 strbeq r3, [r12, #0x30] */
/* @0x1e963c ldr r3, [sp, #0x3c] */
/* @0x1e9640 mov r2, r4 */
/* @0x1e9644 mov r1, r5 */
/* @0x1e9648 ldr r0, [sp, #0x2c] */
/* @0x1e964c bl 0x1e8264 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii> */
/* @0x1e9650 mov r0, r5 */
/* @0x1e9654 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e9658 mov r0, r4 */
/* @0x1e965c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e9660 ldr r4, [sp, #0x2c] */
/* @0x1e9664 ldrb r3, [r4, #0x78] */
/* @0x1e9668 cmp r3, #0 */
/* @0x1e966c beq 0x1e9370 <_ZN7CSprite12BuildSWFDataEPcii+0xfe4> */
/* @0x1e9670 ldr r5, [sp, #0x2c] */
/* @0x1e9674 ldrb r3, [r5, #0x30] */
/* @0x1e9678 cmp r3, #0 */
/* @0x1e967c bne 0x1e9384 <_ZN7CSprite12BuildSWFDataEPcii+0xff8> */
/* @0x1e9680 ldr r3, [r5, #0x84] */
/* @0x1e9684 ldr r12, [r5, #0x24] */
/* @0x1e9688 ldr r0, [r5, #0x8] */
/* @0x1e968c ldr r1, [r5, #0x28] */
/* @0x1e9690 ldr r2, [r5, #0xc] */
/* @0x1e9694 b 0x1e93d8 <_ZN7CSprite12BuildSWFDataEPcii+0x104c> */
/* @0x1e9698 mov r3, #0 */
/* @0x1e969c mov r2, r0 */
/* @0x1e96a0 str r3, [r0] */
/* @0x1e96a4 b 0x1e9334 <_ZN7CSprite12BuildSWFDataEPcii+0xfa8> */
/* @0x1e96a8 vcvt.s32.f32 s15, s15 */
/* @0x1e96ac b 0x1e950c <_ZN7CSprite12BuildSWFDataEPcii+0x1180> */
/* @0x1e96b0 mov r0, r1 */
/* @0x1e96b4 add sp, sp, #204 */
/* @0x1e96b8 vpop {d8, d9} */
/* @0x1e96bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e96c0 vmov r0, s15 */
/* @0x1e96c4 bl 0xb6700 <sqrtf@plt> */
/* @0x1e96c8 ldr r3, [r4, #0x24] */
/* @0x1e96cc ldr r2, [r4, #0x28] */
/* @0x1e96d0 vmov s17, r0 */
/* @0x1e96d4 b 0x1e9460 <_ZN7CSprite12BuildSWFDataEPcii+0x10d4> */
/* @0x1e96d8 vmov r0, s15 */
/* @0x1e96dc bl 0xb6700 <sqrtf@plt> */
/* @0x1e96e0 ldr r3, [r4, #0x24] */
/* @0x1e96e4 ldr r2, [r4, #0x28] */
/* @0x1e96e8 ldr r1, [r4, #0x14] */
/* @0x1e96ec vmov s16, r0 */
/* @0x1e96f0 b 0x1e94a8 <_ZN7CSprite12BuildSWFDataEPcii+0x111c> */
/* @0x1e96f4 vmov r0, s15 */
/* @0x1e96f8 bl 0xb6700 <sqrtf@plt> */
/* @0x1e96fc vmov s18, r0 */
/* @0x1e9700 b 0x1e941c <_ZN7CSprite12BuildSWFDataEPcii+0x1090> */
/* @0x1e9704 ldr r12, [sp, #0x2c] */
/* @0x1e9708 mov r10, r4 */
/* @0x1e970c ldr r3, [r12, #0x84] */
/* @0x1e9710 b 0x1e930c <_ZN7CSprite12BuildSWFDataEPcii+0xf80> */
/* @0x1e9714 vmov r0, s14 */
/* @0x1e9718 bl 0xb6700 <sqrtf@plt> */
/* @0x1e971c vmov s15, r0 */
/* @0x1e9720 b 0x1e94e0 <_ZN7CSprite12BuildSWFDataEPcii+0x1154> */
/* @0x1e9724 add r7, r7, #40 */
/* @0x1e9728 b 0x1e8d64 <_ZN7CSprite12BuildSWFDataEPcii+0x9d8> */

/* ── FUNC 0x1e972c · CSprite::LoadFromChunk(YYSprite*, unsigned char*) · size=1084 · insn=271 */
/* @0x1e972c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e9730 vpush {d8, d9, d10} */
/* @0x1e9734 mov r5, r1 */
/* @0x1e9738 sub sp, sp, #20 */
/* @0x1e973c mov r4, r0 */
/* @0x1e9740 bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e9744 ldr r7, [r5, #0x1c] */
/* @0x1e9748 ldr r6, [r5, #0x20] */
/* @0x1e974c adds r7, r7, #0 */
/* @0x1e9750 ldr r2, [r5, #0x18] */
/* @0x1e9754 ldr r12, [r5, #0x24] */
/* @0x1e9758 movne r7, #1 */
/* @0x1e975c adds r6, r6, #0 */
/* @0x1e9760 ldr r1, [r5, #0x2c] */
/* @0x1e9764 ldr r0, [r5, #0x38] */
/* @0x1e9768 movne r6, #1 */
/* @0x1e976c ldr r3, [r5, #0x4] */
/* @0x1e9770 adds r12, r12, #0 */
/* @0x1e9774 ldr r11, [r5, #0x8] */
/* @0x1e9778 ldr r10, [r5, #0xc] */
/* @0x1e977c movne r12, #1 */
/* @0x1e9780 ldr r9, [r5, #0x10] */
/* @0x1e9784 adds r1, r1, #0 */
/* @0x1e9788 ldr r8, [r5, #0x14] */
/* @0x1e978c str r2, [r4, #0xc] */
/* @0x1e9790 movne r1, #1 */
/* @0x1e9794 ldr r2, [r5, #0x28] */
/* @0x1e9798 cmn r0, #1 */
/* @0x1e979c str r2, [r4, #0x4] */
/* @0x1e97a0 ldr r2, [r5, #0x30] */
/* @0x1e97a4 str r3, [r4, #0x1c] */
/* @0x1e97a8 ldr r3, [r5, #0x34] */
/* @0x1e97ac strb r7, [r4, #0x32] */
/* @0x1e97b0 ldr r7, [pc, #0x3a4] */
/* @0x1e97b4 str r11, [r4, #0x20] */
/* @0x1e97b8 str r10, [r4, #0x8] */
/* @0x1e97bc add r7, pc, r7 */
/* @0x1e97c0 str r9, [r4, #0x10] */
/* @0x1e97c4 str r8, [r4, #0x14] */
/* @0x1e97c8 strb r6, [r4, #0x33] */
/* @0x1e97cc strb r12, [r4, #0x34] */
/* @0x1e97d0 strb r1, [r4, #0x30] */
/* @0x1e97d4 str r2, [r4, #0x24] */
/* @0x1e97d8 str r0, [r4, #0x18] */
/* @0x1e97dc str r3, [r4, #0x28] */
/* @0x1e97e0 beq 0x1e99b8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x28c> */
/* @0x1e97e4 ldr r3, [pc, #0x374] */
/* @0x1e97e8 mov r2, #0 */
/* @0x1e97ec str r2, [r4, #0x74] */
/* @0x1e97f0 add r6, r5, #60 */
/* @0x1e97f4 ldr r3, [r7, r3] */
/* @0x1e97f8 ldrb r3, [r3] */
/* @0x1e97fc cmp r3, r2 */
/* @0x1e9800 beq 0x1e9814 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xe8> */
/* @0x1e9804 cmp r0, r2 */
/* @0x1e9808 bne 0x1e9814 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xe8> */
/* @0x1e980c ldr r0, [r6], #4 */
/* @0x1e9810 str r0, [r4, #0x18] */
/* @0x1e9814 cmp r0, #532676608 */
/* @0x1e9818 mvnhi r0, #0 */
/* @0x1e981c bhi 0x1e9824 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xf8> */
/* @0x1e9820 lsl r0, r0, #2 */
/* @0x1e9824 bl 0x27d14c <_Znaj> */
/* @0x1e9828 ldr r5, [r4, #0x18] */
/* @0x1e982c cmp r5, #0 */
/* @0x1e9830 lsl lr, r5, #2 */
/* @0x1e9834 movgt r3, #0 */
/* @0x1e9838 str r0, [r4, #0x54] */
/* @0x1e983c bgt 0x1e9984 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x258> */
/* @0x1e9840 ldr r3, [r6, r5, lsl #2] */
/* @0x1e9844 add r6, r6, lr */
/* @0x1e9848 cmp r3, #0 */
/* @0x1e984c str r3, [r4, #0x64] */
/* @0x1e9850 ble 0x1e9a58 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x32c> */
/* @0x1e9854 subs r3, r3, r5 */
/* @0x1e9858 add r6, r6, #4 */
/* @0x1e985c rsbs r5, r3, #0 */
/* @0x1e9860 str r6, [r4, #0x68] */
/* @0x1e9864 adcs r5, r5, r3 */
/* @0x1e9868 strb r5, [r4, #0x35] */
/* @0x1e986c ldr r2, [r4, #0x28] */
/* @0x1e9870 ldr r3, [r4, #0x24] */
/* @0x1e9874 ldr r1, [r4, #0x1c] */
/* @0x1e9878 mul r8, r2, r2 */
/* @0x1e987c ldr r0, [r4, #0x20] */
/* @0x1e9880 mul r12, r3, r3 */
/* @0x1e9884 rsb r3, r3, r1 */
/* @0x1e9888 rsb r2, r2, r0 */
/* @0x1e988c mul r3, r3, r3 */
/* @0x1e9890 vmov s19, r8 */
/* @0x1e9894 mul r2, r2, r2 */
/* @0x1e9898 vmov s18, r12 */
/* @0x1e989c vcvt.f32.s32 s19, s19 */
/* @0x1e98a0 vmov s13, r3 */
/* @0x1e98a4 vcvt.f32.s32 s18, s18 */
/* @0x1e98a8 vadd.f32 s14, s18, s19 */
/* @0x1e98ac vsqrt.f32 s15, s14 */
/* @0x1e98b0 vcmp.f32 s15, s15 */
/* @0x1e98b4 vcvt.f32.s32 s17, s13 */
/* @0x1e98b8 vmrs APSR_nzcv, fpscr */
/* @0x1e98bc vmov s13, r2 */
/* @0x1e98c0 vcvt.f32.s32 s16, s13 */
/* @0x1e98c4 bne 0x1e9b1c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3f0> */
/* @0x1e98c8 vmov r0, s15 */
/* @0x1e98cc bl 0xb6994 <ceilf@plt> */
/* @0x1e98d0 vadd.f32 s19, s17, s19 */
/* @0x1e98d4 vsqrt.f32 s15, s19 */
/* @0x1e98d8 vmov s20, r0 */
/* @0x1e98dc vcmp.f32 s15, s15 */
/* @0x1e98e0 vmrs APSR_nzcv, fpscr */
/* @0x1e98e4 bne 0x1e9b3c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x410> */
/* @0x1e98e8 vadd.f32 s18, s18, s16 */
/* @0x1e98ec vmov r0, s15 */
/* @0x1e98f0 bl 0xb6994 <ceilf@plt> */
/* @0x1e98f4 vsqrt.f32 s15, s18 */
/* @0x1e98f8 vmov s19, r0 */
/* @0x1e98fc vcmp.f32 s15, s15 */
/* @0x1e9900 vmrs APSR_nzcv, fpscr */
/* @0x1e9904 bne 0x1e9b4c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x420> */
/* @0x1e9908 vadd.f32 s16, s17, s16 */
/* @0x1e990c vmov r0, s15 */
/* @0x1e9910 bl 0xb6994 <ceilf@plt> */
/* @0x1e9914 vsqrt.f32 s15, s16 */
/* @0x1e9918 vmov s18, r0 */
/* @0x1e991c vcmp.f32 s15, s15 */
/* @0x1e9920 vmrs APSR_nzcv, fpscr */
/* @0x1e9924 bne 0x1e9b2c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x400> */
/* @0x1e9928 vmov r0, s15 */
/* @0x1e992c bl 0xb6994 <ceilf@plt> */
/* @0x1e9930 vcvt.s32.f32 s18, s18 */
/* @0x1e9934 vcvt.s32.f32 s19, s19 */
/* @0x1e9938 vmov r3, s18 */
/* @0x1e993c vmov r1, s19 */
/* @0x1e9940 vcvt.s32.f32 s20, s20 */
/* @0x1e9944 vmov s13, r0 */
/* @0x1e9948 vcvt.s32.f32 s13, s13 */
/* @0x1e994c cmp r3, r1 */
/* @0x1e9950 movlt r3, r1 */
/* @0x1e9954 vmov r1, s20 */
/* @0x1e9958 vmov r0, s13 */
/* @0x1e995c cmp r3, r0 */
/* @0x1e9960 movlt r3, r0 */
/* @0x1e9964 cmp r1, r3 */
/* @0x1e9968 strge r1, [r4, #0x2c] */
/* @0x1e996c strlt r3, [r4, #0x2c] */
/* @0x1e9970 mov r0, #1 */
/* @0x1e9974 add sp, sp, #20 */
/* @0x1e9978 vpop {d8, d9, d10} */
/* @0x1e997c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e9980 ldr r0, [r4, #0x54] */
/* @0x1e9984 ldr r2, [r6, r3] */
/* @0x1e9988 add r0, r0, r3 */
/* @0x1e998c ldr r12, [pc, #0x1d0] */
/* @0x1e9990 add r3, r3, #4 */
/* @0x1e9994 cmp r2, #0 */
/* @0x1e9998 mov r1, r2 */
/* @0x1e999c ldrne r1, [r7, r12] */
/* @0x1e99a0 ldrne r1, [r1] */
/* @0x1e99a4 addne r1, r1, r2 */
/* @0x1e99a8 cmp r3, lr */
/* @0x1e99ac str r1, [r0] */
/* @0x1e99b0 bne 0x1e9980 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x254> */
/* @0x1e99b4 b 0x1e9840 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x114> */
/* @0x1e99b8 ldr r1, [r5, #0x40] */
/* @0x1e99bc ldr r0, [pc, #0x19c] */
/* @0x1e99c0 str r1, [r4, #0x74] */
/* @0x1e99c4 ldr r0, [r7, r0] */
/* @0x1e99c8 ldrb r12, [r0] */
/* @0x1e99cc cmp r12, #0 */
/* @0x1e99d0 addne r6, r5, #76 */
/* @0x1e99d4 addeq r6, r5, #68 */
/* @0x1e99d8 ldrne r12, [r5, #0x48] */
/* @0x1e99dc ldrne r5, [r5, #0x44] */
/* @0x1e99e0 strne r12, [r4, #0x70] */
/* @0x1e99e4 mov r12, #0 */
/* @0x1e99e8 strne r5, [r4, #0x6c] */
/* @0x1e99ec cmp r1, #0 */
/* @0x1e99f0 str r12, [r4, #0x18] */
/* @0x1e99f4 beq 0x1e9b08 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3dc> */
/* @0x1e99f8 cmp r1, #1 */
/* @0x1e99fc beq 0x1e9a64 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x338> */
/* @0x1e9a00 cmp r1, #2 */
/* @0x1e9a04 bne 0x1e9970 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x244> */
/* @0x1e9a08 ldr r10, [r6, #0x4] */
/* @0x1e9a0c mov r0, #12 */
/* @0x1e9a10 ldr r8, [r6, #0x8] */
/* @0x1e9a14 ldr r11, [r6, #0xc] */
/* @0x1e9a18 ldr r9, [r6, #0x10] */
/* @0x1e9a1c ldr r7, [r6, #0x14] */
/* @0x1e9a20 str r12, [r4, #0x54] */
/* @0x1e9a24 bl 0x27c524 <_Znwj> */
/* @0x1e9a28 mov r3, r8 */
/* @0x1e9a2c str r11, [sp] */
/* @0x1e9a30 mov r2, r10 */
/* @0x1e9a34 str r9, [sp, #0x4] */
/* @0x1e9a38 add r1, r6, #24 */
/* @0x1e9a3c str r7, [sp, #0x8] */
/* @0x1e9a40 mov r5, r0 */
/* @0x1e9a44 bl 0xbd86c <_ZN15CSkeletonSpriteC2EPcjjjjj> */
/* @0x1e9a48 mvn r3, #-2147483648 */
/* @0x1e9a4c str r5, [r4, #0x58] */
/* @0x1e9a50 str r3, [r4, #0x18] */
/* @0x1e9a54 b 0x1e9970 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x244> */
/* @0x1e9a58 mov r3, #0 */
/* @0x1e9a5c str r3, [r4, #0x68] */
/* @0x1e9a60 b 0x1e986c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x140> */
/* @0x1e9a64 ldr r1, [r6] */
/* @0x1e9a68 str r12, [r4, #0x54] */
/* @0x1e9a6c cmp r1, #7 */
/* @0x1e9a70 addle r1, r6, #4 */
/* @0x1e9a74 ble 0x1e9ae8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3bc> */
/* @0x1e9a78 ldr r8, [r6, #0x4] */
/* @0x1e9a7c add r6, r6, #8 */
/* @0x1e9a80 cmp r8, #532676608 */
/* @0x1e9a84 lsl r5, r8, #2 */
/* @0x1e9a88 mvnhi r0, #0 */
/* @0x1e9a8c movls r0, r5 */
/* @0x1e9a90 bl 0x27d14c <_Znaj> */
/* @0x1e9a94 cmp r8, #0 */
/* @0x1e9a98 movgt r3, #0 */
/* @0x1e9a9c str r0, [r4, #0x54] */
/* @0x1e9aa0 bgt 0x1e9aac <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x380> */
/* @0x1e9aa4 b 0x1e9adc <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3b0> */
/* @0x1e9aa8 ldr r0, [r4, #0x54] */
/* @0x1e9aac ldr r2, [r6, r3] */
/* @0x1e9ab0 add r0, r0, r3 */
/* @0x1e9ab4 ldr r12, [pc, #0xa8] */
/* @0x1e9ab8 add r3, r3, #4 */
/* @0x1e9abc cmp r2, #0 */
/* @0x1e9ac0 mov r1, r2 */
/* @0x1e9ac4 ldrne r1, [r7, r12] */
/* @0x1e9ac8 ldrne r1, [r1] */
/* @0x1e9acc addne r1, r1, r2 */
/* @0x1e9ad0 cmp r3, r5 */
/* @0x1e9ad4 str r1, [r0] */
/* @0x1e9ad8 bne 0x1e9aa8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x37c> */
/* @0x1e9adc ldr r2, [r4, #0x24] */
/* @0x1e9ae0 add r1, r6, r5 */
/* @0x1e9ae4 ldr r3, [r4, #0x28] */
/* @0x1e9ae8 mov r12, #1 */
/* @0x1e9aec mov r0, r4 */
/* @0x1e9af0 strb r12, [r4, #0x78] */
/* @0x1e9af4 bl 0x1e838c <_ZN7CSprite12BuildSWFDataEPcii> */
/* @0x1e9af8 mov r0, #1 */
/* @0x1e9afc add sp, sp, #20 */
/* @0x1e9b00 vpop {d8, d9, d10} */
/* @0x1e9b04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e9b08 ldrb r3, [r0] */
/* @0x1e9b0c cmp r3, #0 */
/* @0x1e9b10 moveq r0, r1 */
/* @0x1e9b14 beq 0x1e9820 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xf4> */
/* @0x1e9b18 b 0x1e980c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xe0> */
/* @0x1e9b1c vmov r0, s14 */
/* @0x1e9b20 bl 0xb6700 <sqrtf@plt> */
/* @0x1e9b24 vmov s15, r0 */
/* @0x1e9b28 b 0x1e98c8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x19c> */
/* @0x1e9b2c vmov r0, s16 */
/* @0x1e9b30 bl 0xb6700 <sqrtf@plt> */
/* @0x1e9b34 vmov s15, r0 */
/* @0x1e9b38 b 0x1e9928 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x1fc> */
/* @0x1e9b3c vmov r0, s19 */
/* @0x1e9b40 bl 0xb6700 <sqrtf@plt> */
/* @0x1e9b44 vmov s15, r0 */
/* @0x1e9b48 b 0x1e98e8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x1bc> */
/* @0x1e9b4c vmov r0, s18 */
/* @0x1e9b50 bl 0xb6700 <sqrtf@plt> */
/* @0x1e9b54 vmov s15, r0 */
/* @0x1e9b58 b 0x1e9908 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x1dc> */
/* @0x1e9b5c mlaeq r0, r4, r4, r8 */
/* @0x1e9b60 .word 0xffffbcd4 */
/* @0x1e9b64 .word 0xffffbcf4 */

/* ── FUNC 0x1e9b68 · CSprite::LoadFromYYSFile(char const*, int, int) · size=168 · insn=42 */
/* @0x1e9b68 push {r4, r5, r6, r7, r8, lr} */
/* @0x1e9b6c sub sp, sp, #8 */
/* @0x1e9b70 mov r6, r0 */
/* @0x1e9b74 mov r0, r1 */
/* @0x1e9b78 mov r5, r1 */
/* @0x1e9b7c mov r8, r2 */
/* @0x1e9b80 mov r1, #0 */
/* @0x1e9b84 mov r7, r3 */
/* @0x1e9b88 str r1, [sp, #0x4] */
/* @0x1e9b8c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1e9b90 cmp r0, #0 */
/* @0x1e9b94 mov r0, r5 */
/* @0x1e9b98 beq 0x1e9be8 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x80> */
/* @0x1e9b9c add r1, sp, #4 */
/* @0x1e9ba0 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x1e9ba4 mov r4, r0 */
/* @0x1e9ba8 cmp r4, #0 */
/* @0x1e9bac moveq r5, r4 */
/* @0x1e9bb0 beq 0x1e9bd4 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x6c> */
/* @0x1e9bb4 mov r3, r7 */
/* @0x1e9bb8 mov r2, r8 */
/* @0x1e9bbc mov r0, r6 */
/* @0x1e9bc0 mov r1, r4 */
/* @0x1e9bc4 bl 0x1e838c <_ZN7CSprite12BuildSWFDataEPcii> */
/* @0x1e9bc8 subs r5, r0, #0 */
/* @0x1e9bcc movne r3, #1 */
/* @0x1e9bd0 strne r3, [r6, #0x74] */
/* @0x1e9bd4 mov r0, r4 */
/* @0x1e9bd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e9bdc mov r0, r5 */
/* @0x1e9be0 add sp, sp, #8 */
/* @0x1e9be4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1e9be8 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1e9bec cmp r0, #0 */
/* @0x1e9bf0 moveq r4, r0 */
/* @0x1e9bf4 moveq r5, r4 */
/* @0x1e9bf8 beq 0x1e9bd4 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x6c> */
/* @0x1e9bfc mov r0, r5 */
/* @0x1e9c00 add r1, sp, #4 */
/* @0x1e9c04 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x1e9c08 mov r4, r0 */
/* @0x1e9c0c b 0x1e9ba8 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x40> */

/* ── FUNC 0x1e9c10 · CSprite::DrawDictionaryItem(SWF_DictionaryItem*, yyMatrix, float, bool, bool, yyMatrix*, unsigned int*, unsigned int*, int*, int*, int*, Texture*, float, float) · size=7808 · insn=1952 */
/* @0x1e9c10 sub sp, sp, #8 */
/* @0x1e9c14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e9c18 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1e9c1c sub sp, sp, #500 */
/* @0x1e9c20 vldr s20, [sp, #664] */
/* @0x1e9c24 ldr r4, [sp, #0x2a8] */
/* @0x1e9c28 ldr r5, [sp, #0x2a8] */
/* @0x1e9c2c ldr r6, [sp, #0x2a8] */
/* @0x1e9c30 ldr r7, [sp, #0x2a8] */
/* @0x1e9c34 ldr r8, [sp, #0x2ac] */
/* @0x1e9c38 ldr r9, [sp, #0x2ac] */
/* @0x1e9c3c ldr r10, [sp, #0x2ac] */
/* @0x1e9c40 ldr r11, [sp, #0x2ac] */
/* @0x1e9c44 ldr r9, [r9, #0x4] */
/* @0x1e9c48 ldr r4, [r4] */
/* @0x1e9c4c ldr r5, [r5, #0x4] */
/* @0x1e9c50 ldr r6, [r6, #0x8] */
/* @0x1e9c54 ldr r7, [r7, #0xc] */
/* @0x1e9c58 ldr r8, [r8] */
/* @0x1e9c5c ldr r10, [r10, #0x8] */
/* @0x1e9c60 ldr r11, [r11, #0xc] */
/* @0x1e9c64 ldrb r12, [sp, #0x29c] */
/* @0x1e9c68 str r0, [sp, #0xa8] */
/* @0x1e9c6c add r0, sp, #596 */
/* @0x1e9c70 str r1, [sp, #0xa0] */
/* @0x1e9c74 stmib r0, {r2, r3} */
/* @0x1e9c78 vldr s19, [sp, #600] */
/* @0x1e9c7c str r4, [sp, #0x68] */
/* @0x1e9c80 vldr s18, [sp, #604] */
/* @0x1e9c84 str r5, [sp, #0x6c] */
/* @0x1e9c88 str r6, [sp, #0x70] */
/* @0x1e9c8c str r9, [sp, #0x7c] */
/* @0x1e9c90 str r7, [sp, #0x74] */
/* @0x1e9c94 str r8, [sp, #0x78] */
/* @0x1e9c98 str r10, [sp, #0x80] */
/* @0x1e9c9c str r11, [sp, #0x84] */
/* @0x1e9ca0 str r12, [sp, #0x60] */
/* @0x1e9ca4 vldr s29, [sp, #704] */
/* @0x1e9ca8 ldrb r4, [sp, #0x2a0] */
/* @0x1e9cac vldr s28, [sp, #708] */
/* @0x1e9cb0 vldr s17, [sp, #616] */
/* @0x1e9cb4 vldr s16, [sp, #620] */
/* @0x1e9cb8 vldr s22, [sp, #648] */
/* @0x1e9cbc vldr s21, [sp, #652] */
/* @0x1e9cc0 str r4, [sp, #0x88] */
/* @0x1e9cc4 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x1e9cc8 ldr r5, [sp, #0xa0] */
/* @0x1e9ccc ldr r6, [pc, #0x400] */
/* @0x1e9cd0 ldr r3, [r5] */
/* @0x1e9cd4 add r6, pc, r6 */
/* @0x1e9cd8 str r6, [sp, #0x44] */
/* @0x1e9cdc cmp r3, #1 */
/* @0x1e9ce0 movne r9, #0 */
/* @0x1e9ce4 strne r9, [sp, #0x54] */
/* @0x1e9ce8 beq 0x1e9d04 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xf4> */
/* @0x1e9cec ldr r0, [sp, #0x54] */
/* @0x1e9cf0 add sp, sp, #500 */
/* @0x1e9cf4 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1e9cf8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e9cfc add sp, sp, #8 */
/* @0x1e9d00 bx lr */
/* @0x1e9d04 ldr r3, [r5, #0x1c] */
/* @0x1e9d08 cmp r3, #0 */
/* @0x1e9d0c beq 0x1eba58 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e48> */
/* @0x1e9d10 movw r1, #0xaaab */
/* @0x1e9d14 movw r12, #0x5556 */
/* @0x1e9d18 movt r1, #0x2aaa */
/* @0x1e9d1c movt r12, #0x5555 */
/* @0x1e9d20 asr r2, r0, #31 */
/* @0x1e9d24 ldr r7, [pc, #0x3ac] */
/* @0x1e9d28 smull r8, r1, r1, r0 */
/* @0x1e9d2c vldr s30, [pc, #924] */
/* @0x1e9d30 ldr r9, [pc, #0x3a4] */
/* @0x1e9d34 smull r10, r0, r12, r0 */
/* @0x1e9d38 mov r11, #0 */
/* @0x1e9d3c add r7, pc, r7 */
/* @0x1e9d40 add r9, pc, r9 */
/* @0x1e9d44 rsb r1, r2, r1 */
/* @0x1e9d48 rsb r0, r2, r0 */
/* @0x1e9d4c str r7, [sp, #0xac] */
/* @0x1e9d50 str r9, [sp, #0xa4] */
/* @0x1e9d54 str r1, [sp, #0x58] */
/* @0x1e9d58 str r11, [sp, #0x9c] */
/* @0x1e9d5c str r0, [sp, #0x8c] */
/* @0x1e9d60 str r11, [sp, #0x54] */
/* @0x1e9d64 ldr r12, [sp, #0x9c] */
/* @0x1e9d68 ldr r4, [sp, #0xa0] */
/* @0x1e9d6c add r2, r12, r12, lsl #1 */
/* @0x1e9d70 ldr r1, [r4, #0x8] */
/* @0x1e9d74 add r1, r1, r2, lsl #3 */
/* @0x1e9d78 str r1, [sp, #0x50] */
/* @0x1e9d7c ldr r2, [r1, #0xc] */
/* @0x1e9d80 cmp r2, #0 */
/* @0x1e9d84 beq 0x1ea428 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x818> */
/* @0x1e9d88 mov r5, #0 */
/* @0x1e9d8c str r5, [sp, #0x48] */
/* @0x1e9d90 ldr r7, [sp, #0x48] */
/* @0x1e9d94 mov r6, #84 */
/* @0x1e9d98 ldr r8, [sp, #0x50] */
/* @0x1e9d9c mul r2, r6, r7 */
/* @0x1e9da0 ldr r1, [r8] */
/* @0x1e9da4 add r9, r1, r2 */
/* @0x1e9da8 str r9, [sp, #0x38] */
/* @0x1e9dac ldr r4, [r9, #0x28] */
/* @0x1e9db0 cmp r4, #0 */
/* @0x1e9db4 blt 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1e9db8 ldr r3, [r9, #0x38] */
/* @0x1e9dbc cmp r3, #0 */
/* @0x1e9dc0 beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1e9dc4 ldr r12, [r9, #0x30] */
/* @0x1e9dc8 ldr r2, [r1, r2] */
/* @0x1e9dcc cmp r12, #65536 */
/* @0x1e9dd0 bhi 0x1ea838 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xc28> */
/* @0x1e9dd4 cmp r12, #65536 */
/* @0x1e9dd8 movhs r12, #65536 */
/* @0x1e9ddc cmp r12, #0 */
/* @0x1e9de0 beq 0x1e9e34 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x224> */
/* @0x1e9de4 ldr r0, [pc, #0x304] */
/* @0x1e9de8 mov r1, #0 */
/* @0x1e9dec ldr r5, [sp, #0x44] */
/* @0x1e9df0 ldr r0, [r5, r0] */
/* @0x1e9df4 add r0, r0, #8 */
/* @0x1e9df8 vldr s15, [r2, #4] */
/* @0x1e9dfc vmul.f32 s14, s15, s17 */
/* @0x1e9e00 vldr s13, [r2] */
/* @0x1e9e04 add r1, r1, #1 */
/* @0x1e9e08 cmp r12, r1 */
/* @0x1e9e0c add r2, r2, #8 */
/* @0x1e9e10 add r0, r0, #8 */
/* @0x1e9e14 vmul.f32 s15, s15, s16 */
/* @0x1e9e18 vmla.f32 s14, s13, s19 */
/* @0x1e9e1c vmla.f32 s15, s13, s18 */
/* @0x1e9e20 vadd.f32 s14, s14, s22 */
/* @0x1e9e24 vadd.f32 s15, s15, s21 */
/* @0x1e9e28 vstr s14, [r0, #-16] */
/* @0x1e9e2c vstr s15, [r0, #-12] */
/* @0x1e9e30 bne 0x1e9df8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e8> */
/* @0x1e9e34 ldr r11, [sp, #0x60] */
/* @0x1e9e38 cmp r11, #0 */
/* @0x1e9e3c beq 0x1e9edc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2cc> */
/* @0x1e9e40 ldr r7, [sp, #0x38] */
/* @0x1e9e44 ldr r2, [r7, #0x18] */
/* @0x1e9e48 cmp r2, #0 */
/* @0x1e9e4c beq 0x1e9edc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2cc> */
/* @0x1e9e50 ldr r5, [r7, #0x48] */
/* @0x1e9e54 cmp r5, #65536 */
/* @0x1e9e58 bhi 0x1eb378 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1768> */
/* @0x1e9e5c cmp r5, #65536 */
/* @0x1e9e60 movhs r5, #65536 */
/* @0x1e9e64 cmp r5, #0 */
/* @0x1e9e68 beq 0x1e9edc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2cc> */
/* @0x1e9e6c ldr r9, [sp, #0x44] */
/* @0x1e9e70 mov r12, #0 */
/* @0x1e9e74 ldr r0, [pc, #0x274] */
/* @0x1e9e78 ldr r1, [pc, #0x274] */
/* @0x1e9e7c ldr r0, [r9, r0] */
/* @0x1e9e80 ldr r1, [r9, r1] */
/* @0x1e9e84 add r0, r0, #8 */
/* @0x1e9e88 add r1, r1, #8 */
/* @0x1e9e8c vldr s15, [r2, #4] */
/* @0x1e9e90 vmul.f32 s15, s15, s20 */
/* @0x1e9e94 vldr s13, [r2] */
/* @0x1e9e98 vldr s11, [r0, #-4] */
/* @0x1e9e9c vldr s12, [r0, #-8] */
/* @0x1e9ea0 add r12, r12, #1 */
/* @0x1e9ea4 cmp r5, r12 */
/* @0x1e9ea8 add r2, r2, #8 */
/* @0x1e9eac add r0, r0, #8 */
/* @0x1e9eb0 add r1, r1, #8 */
/* @0x1e9eb4 vmul.f32 s14, s15, s16 */
/* @0x1e9eb8 vmul.f32 s13, s13, s20 */
/* @0x1e9ebc vmul.f32 s15, s15, s17 */
/* @0x1e9ec0 vmla.f32 s14, s13, s18 */
/* @0x1e9ec4 vmla.f32 s15, s13, s19 */
/* @0x1e9ec8 vadd.f32 s14, s14, s11 */
/* @0x1e9ecc vadd.f32 s15, s15, s12 */
/* @0x1e9ed0 vstr s14, [r1, #-12] */
/* @0x1e9ed4 vstr s15, [r1, #-16] */
/* @0x1e9ed8 bne 0x1e9e8c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x27c> */
/* @0x1e9edc ldr r6, [sp, #0x50] */
/* @0x1e9ee0 ldr r2, [r6, #0x4] */
/* @0x1e9ee4 ldr r6, [r2, r4, lsl #2] */
/* @0x1e9ee8 cmp r6, #0 */
/* @0x1e9eec beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1e9ef0 ldr r7, [r6] */
/* @0x1e9ef4 cmp r7, #1 */
/* @0x1e9ef8 beq 0x1ea85c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xc4c> */
/* @0x1e9efc sub r3, r7, #2 */
/* @0x1e9f00 cmp r3, #1 */
/* @0x1e9f04 bls 0x1ead0c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10fc> */
/* @0x1e9f08 ldr r10, [sp, #0x38] */
/* @0x1e9f0c ldr r12, [r10, #0x2c] */
/* @0x1e9f10 cmp r12, #0 */
/* @0x1e9f14 blt 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */
/* @0x1e9f18 ldr r1, [r10, #0x40] */
/* @0x1e9f1c cmp r1, #0 */
/* @0x1e9f20 beq 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */
/* @0x1e9f24 ldr r3, [r10, #0xc] */
/* @0x1e9f28 cmp r3, #0 */
/* @0x1e9f2c beq 0x1e9f98 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x388> */
/* @0x1e9f30 ldr r5, [sp, #0x38] */
/* @0x1e9f34 ldr r4, [r5, #0x3c] */
/* @0x1e9f38 cmp r4, #65536 */
/* @0x1e9f3c movhs r4, #65536 */
/* @0x1e9f40 cmp r4, #0 */
/* @0x1e9f44 beq 0x1e9f98 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x388> */
/* @0x1e9f48 ldr r0, [pc, #0x194] */
/* @0x1e9f4c mov r2, #0 */
/* @0x1e9f50 ldr r6, [sp, #0x44] */
/* @0x1e9f54 ldr r0, [r6, r0] */
/* @0x1e9f58 add r0, r0, #8 */
/* @0x1e9f5c vldr s15, [r3, #4] */
/* @0x1e9f60 vmul.f32 s14, s15, s17 */
/* @0x1e9f64 vldr s13, [r3] */
/* @0x1e9f68 add r2, r2, #1 */
/* @0x1e9f6c cmp r4, r2 */
/* @0x1e9f70 add r3, r3, #8 */
/* @0x1e9f74 add r0, r0, #8 */
/* @0x1e9f78 vmul.f32 s15, s15, s16 */
/* @0x1e9f7c vmla.f32 s14, s13, s19 */
/* @0x1e9f80 vmla.f32 s15, s13, s18 */
/* @0x1e9f84 vadd.f32 s14, s14, s22 */
/* @0x1e9f88 vadd.f32 s15, s15, s21 */
/* @0x1e9f8c vstr s14, [r0, #-16] */
/* @0x1e9f90 vstr s15, [r0, #-12] */
/* @0x1e9f94 bne 0x1e9f5c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x34c> */
/* @0x1e9f98 ldr r11, [sp, #0x60] */
/* @0x1e9f9c cmp r11, #0 */
/* @0x1e9fa0 beq 0x1ea038 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x428> */
/* @0x1e9fa4 ldr r11, [sp, #0x38] */
/* @0x1e9fa8 ldr r3, [r11, #0x20] */
/* @0x1e9fac cmp r3, #0 */
/* @0x1e9fb0 beq 0x1ea038 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x428> */
/* @0x1e9fb4 ldr r5, [r11, #0x50] */
/* @0x1e9fb8 cmp r5, #65536 */
/* @0x1e9fbc movhs r5, #65536 */
/* @0x1e9fc0 cmp r5, #0 */
/* @0x1e9fc4 beq 0x1ea038 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x428> */
/* @0x1e9fc8 ldr r6, [sp, #0x44] */
/* @0x1e9fcc mov r4, #0 */
/* @0x1e9fd0 ldr r0, [pc, #0x10c] */
/* @0x1e9fd4 ldr r2, [pc, #0x104] */
/* @0x1e9fd8 ldr r0, [r6, r0] */
/* @0x1e9fdc ldr r2, [r6, r2] */
/* @0x1e9fe0 add r0, r0, #8 */
/* @0x1e9fe4 add r2, r2, #8 */
/* @0x1e9fe8 vldr s15, [r3, #4] */
/* @0x1e9fec vmul.f32 s15, s15, s20 */
/* @0x1e9ff0 vldr s13, [r3] */
/* @0x1e9ff4 vldr s11, [r0, #-4] */
/* @0x1e9ff8 vldr s12, [r0, #-8] */
/* @0x1e9ffc add r4, r4, #1 */
/* @0x1ea000 cmp r5, r4 */
/* @0x1ea004 add r3, r3, #8 */
/* @0x1ea008 add r0, r0, #8 */
/* @0x1ea00c add r2, r2, #8 */
/* @0x1ea010 vmul.f32 s14, s15, s16 */
/* @0x1ea014 vmul.f32 s13, s13, s20 */
/* @0x1ea018 vmul.f32 s15, s15, s17 */
/* @0x1ea01c vmla.f32 s14, s13, s18 */
/* @0x1ea020 vmla.f32 s15, s13, s19 */
/* @0x1ea024 vadd.f32 s14, s14, s11 */
/* @0x1ea028 vadd.f32 s15, s15, s12 */
/* @0x1ea02c vstr s14, [r2, #-12] */
/* @0x1ea030 vstr s15, [r2, #-16] */
/* @0x1ea034 bne 0x1e9fe8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x3d8> */
/* @0x1ea038 ldr r7, [sp, #0x50] */
/* @0x1ea03c add r4, sp, #368 */
/* @0x1ea040 ldr r8, [sp, #0x6c] */
/* @0x1ea044 mov r3, #0 */
/* @0x1ea048 ldr r10, [sp, #0x68] */
/* @0x1ea04c ldr r2, [r7, #0x8] */
/* @0x1ea050 ldr r11, [sp, #0x70] */
/* @0x1ea054 ldr r0, [r2, r12, lsl #2] */
/* @0x1ea058 ubfx r5, r0, #0x8, #0x8 */
/* @0x1ea05c ubfx r12, r0, #0x10, #0x8 */
/* @0x1ea060 uxtb r6, r0 */
/* @0x1ea064 lsr r0, r0, #24 */
/* @0x1ea068 mul r9, r5, r8 */
/* @0x1ea06c mul r2, r6, r10 */
/* @0x1ea070 ldr r10, [sp, #0x74] */
/* @0x1ea074 mul r8, r12, r11 */
/* @0x1ea078 mul r7, r0, r10 */
/* @0x1ea07c lsr r9, r9, #8 */
/* @0x1ea080 str r9, [sp, #0x174] */
/* @0x1ea084 lsr r2, r2, #8 */
/* @0x1ea088 ldr r9, [sp, #0x2b4] */
/* @0x1ea08c lsr r8, r8, #8 */
/* @0x1ea090 str r8, [sp, #0x178] */
/* @0x1ea094 ldr r8, [sp, #0x2b0] */
/* @0x1ea098 lsr r7, r7, #8 */
/* @0x1ea09c str r2, [sp, #0x170] */
/* @0x1ea0a0 str r7, [sp, #0x17c] */
/* @0x1ea0a4 ldr r10, [r8, r3] */
/* @0x1ea0a8 ldr r7, [r9, r3] */
/* @0x1ea0ac mul r2, r10, r2 */
/* @0x1ea0b0 add r2, r7, r2, asr #8 */
/* @0x1ea0b4 usat r2, #0x8, r2 */
/* @0x1ea0b8 str r2, [r4, r3] */
/* @0x1ea0bc add r3, r3, #4 */
/* @0x1ea0c0 cmp r3, #16 */
/* @0x1ea0c4 beq 0x1ea440 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x830> */
/* @0x1ea0c8 ldr r2, [r4, r3] */
/* @0x1ea0cc b 0x1ea0a4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x494> */
/* @0x1ea0d0 andeq r0, r0, r0 */
/* @0x1ea0d4 eoreq r7, r0, r12, ror pc */
/* @0x1ea0d8 ldrsbeq r8, [r6], -r12 */
/* @0x1ea0dc ldrheq r8, [r6], -r4 */
/* @0x1ea0e0 .word 0xfffff188 */
/* @0x1ea0e4 .word 0xfffff18c */
/* @0x1ea0e8 .word 0xffffbac4 */
/* @0x1ea0ec .word 0xffffc0a8 */
/* @0x1ea0f0 .word 0xfffff190 */
/* @0x1ea0f4 .word 0xfffff194 */
/* @0x1ea0f8 .word 0xffffbcd0 */
/* @0x1ea0fc ldr r5, [sp, #0x60] */
/* @0x1ea100 cmp r5, #0 */
/* @0x1ea104 beq 0x1ea358 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x748> */
/* @0x1ea108 ldr r6, [sp, #0x38] */
/* @0x1ea10c ldr r3, [r6, #0x4c] */
/* @0x1ea110 cmp r3, #0 */
/* @0x1ea114 beq 0x1ea358 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x748> */
/* @0x1ea118 ldr r7, [r6, #0x1c] */
/* @0x1ea11c str r3, [sp, #0x40] */
/* @0x1ea120 str r7, [sp, #0x4c] */
/* @0x1ea124 ble 0x1ea34c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x73c> */
/* @0x1ea128 str r8, [sp, #0x18] */
/* @0x1ea12c ldr r8, [sp, #0x40] */
/* @0x1ea130 mov r0, #4 */
/* @0x1ea134 ldr r9, [sp, #0x58] */
/* @0x1ea138 mov r1, #0 */
/* @0x1ea13c mov r2, #16 */
/* @0x1ea140 cmp r8, r9 */
/* @0x1ea144 movge r8, r9 */
/* @0x1ea148 str r8, [sp, #0x3c] */
/* @0x1ea14c add r3, r8, r8, lsl #1 */
/* @0x1ea150 lsl r3, r3, #1 */
/* @0x1ea154 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea158 cmp r8, #0 */
/* @0x1ea15c ble 0x1ea324 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x714> */
/* @0x1ea160 ldr r4, [sp, #0x44] */
/* @0x1ea164 add r10, r0, #16 */
/* @0x1ea168 ldr r1, [pc, #-0x8c] */
/* @0x1ea16c add r11, r0, #32 */
/* @0x1ea170 str r10, [sp, #0x34] */
/* @0x1ea174 add r12, r0, #48 */
/* @0x1ea178 str r11, [sp, #0x30] */
/* @0x1ea17c add r5, r0, #64 */
/* @0x1ea180 str r12, [sp, #0x2c] */
/* @0x1ea184 add r6, r0, #80 */
/* @0x1ea188 ldr r1, [r4, r1] */
/* @0x1ea18c mov r8, r12 */
/* @0x1ea190 ldr r3, [pc, #-0xb8] */
/* @0x1ea194 mov r7, r11 */
/* @0x1ea198 str r5, [sp, #0x28] */
/* @0x1ea19c str r1, [sp, #0x20] */
/* @0x1ea1a0 ldr r3, [r4, r3] */
/* @0x1ea1a4 str r6, [sp, #0x24] */
/* @0x1ea1a8 mov r6, r5 */
/* @0x1ea1ac str r10, [sp, #0x10] */
/* @0x1ea1b0 ldr r2, [pc, #-0xc0] */
/* @0x1ea1b4 ldr r9, [sp, #0x3c] */
/* @0x1ea1b8 ldr r10, [sp, #0x44] */
/* @0x1ea1bc ldr r5, [sp, #0x24] */
/* @0x1ea1c0 ldr r4, [sp, #0x4c] */
/* @0x1ea1c4 str r3, [sp, #0x1c] */
/* @0x1ea1c8 add r3, r0, #96 */
/* @0x1ea1cc str r9, [sp, #0xc] */
/* @0x1ea1d0 ldr r2, [r10, r2] */
/* @0x1ea1d4 vldr s15, [r2] */
/* @0x1ea1d8 ldrh r9, [r4, #2] */
/* @0x1ea1dc add r3, r3, #96 */
/* @0x1ea1e0 ldr r1, [sp, #0x10] */
/* @0x1ea1e4 add r4, r4, #4 */
/* @0x1ea1e8 ldr r2, [sp, #0x34] */
/* @0x1ea1ec ldrh r10, [r4, #-4] */
/* @0x1ea1f0 rsb r12, r0, r1 */
/* @0x1ea1f4 ldr r11, [sp, #0xc] */
/* @0x1ea1f8 lsl r9, r9, #3 */
/* @0x1ea1fc str r9, [sp, #0x5c] */
/* @0x1ea200 add r12, r12, r2 */
/* @0x1ea204 ldr r9, [sp, #0x2c] */
/* @0x1ea208 rsb r2, r0, r8 */
/* @0x1ea20c subs r11, r11, #1 */
/* @0x1ea210 str r11, [sp, #0xc] */
/* @0x1ea214 add r2, r2, r9 */
/* @0x1ea218 ldr r11, [sp, #0x30] */
/* @0x1ea21c ldr r9, [sp, #0x20] */
/* @0x1ea220 rsb r1, r0, r7 */
/* @0x1ea224 lsl r10, r10, #3 */
/* @0x1ea228 add r1, r1, r11 */
/* @0x1ea22c add r11, r9, r10 */
/* @0x1ea230 ldr r9, [sp, #0x1c] */
/* @0x1ea234 vldr s8, [r11] */
/* @0x1ea238 vldr s9, [r11, #4] */
/* @0x1ea23c add r10, r9, r10 */
/* @0x1ea240 ldr r11, [sp, #0x20] */
/* @0x1ea244 ldr r9, [sp, #0x5c] */
/* @0x1ea248 vldr s12, [r10] */
/* @0x1ea24c vldr s13, [r10, #4] */
/* @0x1ea250 add r7, r7, #96 */
/* @0x1ea254 add r10, r11, r9 */
/* @0x1ea258 ldr r11, [sp, #0x1c] */
/* @0x1ea25c vldr s14, [r10] */
/* @0x1ea260 vldr s2, [r10, #4] */
/* @0x1ea264 add r11, r11, r9 */
/* @0x1ea268 vldr s10, [r11] */
/* @0x1ea26c vldr s11, [r11, #4] */
/* @0x1ea270 ldr r11, [sp, #0x28] */
/* @0x1ea274 ldr r9, [sp, #0x10] */
/* @0x1ea278 rsb r10, r0, r6 */
/* @0x1ea27c add r10, r10, r11 */
/* @0x1ea280 ldr r11, [sp, #0x24] */
/* @0x1ea284 add r9, r9, #96 */
/* @0x1ea288 str r9, [sp, #0x10] */
/* @0x1ea28c rsb r9, r0, r5 */
/* @0x1ea290 vstr s8, [r3, #-192] */
/* @0x1ea294 add r11, r9, r11 */
/* @0x1ea298 ldr r9, [sp, #0x18] */
/* @0x1ea29c vstr s9, [r3, #-188] */
/* @0x1ea2a0 vstr s15, [r3, #-184] */
/* @0x1ea2a4 str r11, [sp, #0x5c] */
/* @0x1ea2a8 add r8, r8, #96 */
/* @0x1ea2ac str r9, [r3, #-0xb4] */
/* @0x1ea2b0 vstr s14, [r12, #-16] */
/* @0x1ea2b4 vstr s2, [r12, #-12] */
/* @0x1ea2b8 vstr s15, [r12, #-8] */
/* @0x1ea2bc str r9, [r12, #-0x4] */
/* @0x1ea2c0 add r6, r6, #96 */
/* @0x1ea2c4 ldr r12, [sp, #0x5c] */
/* @0x1ea2c8 vstr s12, [r1, #-32] */
/* @0x1ea2cc ldr r11, [sp, #0x14] */
/* @0x1ea2d0 vstr s13, [r1, #-28] */
/* @0x1ea2d4 vstr s15, [r1, #-24] */
/* @0x1ea2d8 add r5, r5, #96 */
/* @0x1ea2dc str r11, [r1, #-0x14] */
/* @0x1ea2e0 vstr s12, [r2, #-48] */
/* @0x1ea2e4 vstr s13, [r2, #-44] */
/* @0x1ea2e8 vstr s15, [r2, #-40] */
/* @0x1ea2ec str r11, [r2, #-0x24] */
/* @0x1ea2f0 vstr s14, [r10, #-64] */
/* @0x1ea2f4 vstr s2, [r10, #-60] */
/* @0x1ea2f8 vstr s15, [r10, #-56] */
/* @0x1ea2fc str r9, [r10, #-0x34] */
/* @0x1ea300 vstr s10, [r12, #-80] */
/* @0x1ea304 vstr s11, [r12, #-76] */
/* @0x1ea308 vstr s15, [r12, #-72] */
/* @0x1ea30c str r11, [r12, #-0x44] */
/* @0x1ea310 bne 0x1ea1d8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x5c8> */
/* @0x1ea314 ldr r5, [sp, #0x3c] */
/* @0x1ea318 ldr r4, [sp, #0x4c] */
/* @0x1ea31c add r4, r4, r5, lsl #2 */
/* @0x1ea320 str r4, [sp, #0x4c] */
/* @0x1ea324 ldr r6, [sp, #0x40] */
/* @0x1ea328 ldr r7, [sp, #0x3c] */
/* @0x1ea32c rsb r6, r7, r6 */
/* @0x1ea330 str r6, [sp, #0x40] */
/* @0x1ea334 cmp r6, #0 */
/* @0x1ea338 bgt 0x1ea12c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x51c> */
/* @0x1ea33c ldr r9, [sp, #0x38] */
/* @0x1ea340 ldr r8, [sp, #0x18] */
/* @0x1ea344 ldr r3, [r9, #0x4c] */
/* @0x1ea348 ldr r1, [r9, #0x40] */
/* @0x1ea34c ldr r10, [sp, #0x54] */
/* @0x1ea350 add r10, r10, r3, lsl #1 */
/* @0x1ea354 str r10, [sp, #0x54] */
/* @0x1ea358 ldr r11, [sp, #0x38] */
/* @0x1ea35c subs r4, r1, #0 */
/* @0x1ea360 ldr r5, [r11, #0x10] */
/* @0x1ea364 ble 0x1ea3f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7e8> */
/* @0x1ea368 ldr r7, [sp, #0x8c] */
/* @0x1ea36c ldr r9, [sp, #0x44] */
/* @0x1ea370 cmp r4, r7 */
/* @0x1ea374 movlt r6, r4 */
/* @0x1ea378 movge r6, r7 */
/* @0x1ea37c mov r0, #4 */
/* @0x1ea380 mov r1, #0 */
/* @0x1ea384 mov r2, #16 */
/* @0x1ea388 add r10, r6, r6, lsl #1 */
/* @0x1ea38c mov r3, r10 */
/* @0x1ea390 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea394 cmp r10, #0 */
/* @0x1ea398 ble 0x1ea3e4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7d4> */
/* @0x1ea39c ldr r2, [pc, #-0x2ac] */
/* @0x1ea3a0 add r3, r5, r10, lsl #1 */
/* @0x1ea3a4 ldr r1, [pc, #-0x2c8] */
/* @0x1ea3a8 add r0, r0, #16 */
/* @0x1ea3ac ldr r2, [r9, r2] */
/* @0x1ea3b0 ldr r12, [r9, r1] */
/* @0x1ea3b4 ldr r10, [r2] */
/* @0x1ea3b8 ldrh r2, [r5], #2 */
/* @0x1ea3bc add r0, r0, #16 */
/* @0x1ea3c0 cmp r5, r3 */
/* @0x1ea3c4 add r2, r12, r2, lsl #3 */
/* @0x1ea3c8 ldr r1, [r2] */
/* @0x1ea3cc ldr r2, [r2, #0x4] */
/* @0x1ea3d0 str r10, [r0, #-0x18] */
/* @0x1ea3d4 str r1, [r0, #-0x20] */
/* @0x1ea3d8 str r2, [r0, #-0x1c] */
/* @0x1ea3dc str r8, [r0, #-0x14] */
/* @0x1ea3e0 bne 0x1ea3b8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7a8> */
/* @0x1ea3e4 rsb r4, r6, r4 */
/* @0x1ea3e8 cmp r4, #0 */
/* @0x1ea3ec bgt 0x1ea370 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x760> */
/* @0x1ea3f0 ldr r12, [sp, #0x38] */
/* @0x1ea3f4 ldr r1, [r12, #0x40] */
/* @0x1ea3f8 ldr r4, [sp, #0x54] */
/* @0x1ea3fc add r4, r1, r4 */
/* @0x1ea400 str r4, [sp, #0x54] */
/* @0x1ea404 ldr r5, [sp, #0x50] */
/* @0x1ea408 ldr r6, [sp, #0x48] */
/* @0x1ea40c ldr r3, [r5, #0xc] */
/* @0x1ea410 add r6, r6, #1 */
/* @0x1ea414 str r6, [sp, #0x48] */
/* @0x1ea418 cmp r3, r6 */
/* @0x1ea41c bhi 0x1e9d90 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x180> */
/* @0x1ea420 ldr r7, [sp, #0xa0] */
/* @0x1ea424 ldr r3, [r7, #0x1c] */
/* @0x1ea428 ldr r8, [sp, #0x9c] */
/* @0x1ea42c add r8, r8, #1 */
/* @0x1ea430 str r8, [sp, #0x9c] */
/* @0x1ea434 cmp r3, r8 */
/* @0x1ea438 bhi 0x1e9d64 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x154> */
/* @0x1ea43c b 0x1e9cec <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xdc> */
/* @0x1ea440 ldr r9, [sp, #0x80] */
/* @0x1ea444 ldr r8, [sp, #0x7c] */
/* @0x1ea448 ldr r3, [sp, #0x178] */
/* @0x1ea44c ldr r2, [sp, #0x174] */
/* @0x1ea450 ldr r7, [sp, #0x78] */
/* @0x1ea454 mul r12, r12, r9 */
/* @0x1ea458 ldr r10, [sp, #0x84] */
/* @0x1ea45c mul r5, r5, r8 */
/* @0x1ea460 lsl r3, r3, #16 */
/* @0x1ea464 orr r3, r3, r2, lsl #8 */
/* @0x1ea468 ldr r2, [sp, #0x170] */
/* @0x1ea46c mul r6, r6, r7 */
/* @0x1ea470 orr r3, r3, r2 */
/* @0x1ea474 mul r0, r0, r10 */
/* @0x1ea478 ldr r2, [sp, #0x17c] */
/* @0x1ea47c lsr r12, r12, #8 */
/* @0x1ea480 ldr r4, [sp, #0x2b8] */
/* @0x1ea484 str r12, [sp, #0x1b8] */
/* @0x1ea488 lsr r5, r5, #8 */
/* @0x1ea48c ldr r12, [sp, #0x2b0] */
/* @0x1ea490 orr r8, r3, r2, lsl #24 */
/* @0x1ea494 str r5, [sp, #0x1b4] */
/* @0x1ea498 add r5, sp, #432 */
/* @0x1ea49c mov r3, #0 */
/* @0x1ea4a0 lsr r6, r6, #8 */
/* @0x1ea4a4 lsr r0, r0, #8 */
/* @0x1ea4a8 str r6, [sp, #0x1b0] */
/* @0x1ea4ac str r0, [sp, #0x1bc] */
/* @0x1ea4b0 ldr r2, [r12, r3] */
/* @0x1ea4b4 ldr r0, [r4, r3] */
/* @0x1ea4b8 mul r2, r2, r6 */
/* @0x1ea4bc add r2, r0, r2, asr #8 */
/* @0x1ea4c0 usat r2, #0x8, r2 */
/* @0x1ea4c4 str r2, [r5, r3] */
/* @0x1ea4c8 add r3, r3, #4 */
/* @0x1ea4cc cmp r3, #16 */
/* @0x1ea4d0 ldrne r6, [r5, r3] */
/* @0x1ea4d4 bne 0x1ea4b0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x8a0> */
/* @0x1ea4d8 ldr r3, [sp, #0x1b8] */
/* @0x1ea4dc ldr r2, [sp, #0x1b4] */
/* @0x1ea4e0 ldr r11, [sp, #0x88] */
/* @0x1ea4e4 ldr r0, [sp, #0x1b0] */
/* @0x1ea4e8 lsl r3, r3, #16 */
/* @0x1ea4ec ldr r12, [sp, #0x1bc] */
/* @0x1ea4f0 orr r3, r3, r2, lsl #8 */
/* @0x1ea4f4 cmp r11, #0 */
/* @0x1ea4f8 orr r3, r3, r0 */
/* @0x1ea4fc orr r12, r3, r12, lsl #24 */
/* @0x1ea500 str r12, [sp, #0x14] */
/* @0x1ea504 beq 0x1ea0fc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x4ec> */
/* @0x1ea508 ldr r12, [sp, #0x60] */
/* @0x1ea50c cmp r12, #0 */
/* @0x1ea510 beq 0x1ea790 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb80> */
/* @0x1ea514 ldr r4, [sp, #0x38] */
/* @0x1ea518 ldr r3, [r4, #0x4c] */
/* @0x1ea51c cmp r3, #0 */
/* @0x1ea520 beq 0x1ea790 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb80> */
/* @0x1ea524 ldr r5, [r4, #0x1c] */
/* @0x1ea528 str r3, [sp, #0x40] */
/* @0x1ea52c str r5, [sp, #0x4c] */
/* @0x1ea530 ble 0x1ea784 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb74> */
/* @0x1ea534 str r8, [sp, #0x18] */
/* @0x1ea538 ldr r6, [sp, #0x40] */
/* @0x1ea53c mov r0, #4 */
/* @0x1ea540 ldr r7, [sp, #0x58] */
/* @0x1ea544 mov r2, #24 */
/* @0x1ea548 ldr r1, [sp, #0x2bc] */
/* @0x1ea54c cmp r6, r7 */
/* @0x1ea550 movge r6, r7 */
/* @0x1ea554 str r6, [sp, #0x3c] */
/* @0x1ea558 add r3, r6, r6, lsl #1 */
/* @0x1ea55c lsl r3, r3, #1 */
/* @0x1ea560 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea564 cmp r6, #0 */
/* @0x1ea568 ble 0x1ea75c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb4c> */
/* @0x1ea56c ldr r12, [sp, #0x44] */
/* @0x1ea570 add r8, r0, #24 */
/* @0x1ea574 ldr r1, [pc, #-0x498] */
/* @0x1ea578 add r9, r0, #48 */
/* @0x1ea57c str r8, [sp, #0x28] */
/* @0x1ea580 add r10, r0, #72 */
/* @0x1ea584 str r9, [sp, #0x24] */
/* @0x1ea588 mov r7, r9 */
/* @0x1ea58c str r10, [sp, #0x34] */
/* @0x1ea590 ldr r3, [pc, #-0x4b8] */
/* @0x1ea594 ldr r1, [r12, r1] */
/* @0x1ea598 ldr r4, [sp, #0x3c] */
/* @0x1ea59c ldr r2, [pc, #-0x4ac] */
/* @0x1ea5a0 str r1, [sp, #0x20] */
/* @0x1ea5a4 add r1, r0, #96 */
/* @0x1ea5a8 str r1, [sp, #0x30] */
/* @0x1ea5ac ldr r3, [r12, r3] */
/* @0x1ea5b0 mov r6, r1 */
/* @0x1ea5b4 str r4, [sp, #0xc] */
/* @0x1ea5b8 ldr r4, [sp, #0x4c] */
/* @0x1ea5bc str r3, [sp, #0x1c] */
/* @0x1ea5c0 add r3, r0, #120 */
/* @0x1ea5c4 str r3, [sp, #0x2c] */
/* @0x1ea5c8 add r3, r0, #144 */
/* @0x1ea5cc ldr r5, [sp, #0x2c] */
/* @0x1ea5d0 str r8, [sp, #0x10] */
/* @0x1ea5d4 mov r8, r10 */
/* @0x1ea5d8 ldr r2, [r12, r2] */
/* @0x1ea5dc vldr s15, [r2] */
/* @0x1ea5e0 ldr r9, [sp, #0xc] */
/* @0x1ea5e4 add r4, r4, #4 */
/* @0x1ea5e8 ldr r11, [sp, #0x10] */
/* @0x1ea5ec add r3, r3, #144 */
/* @0x1ea5f0 subs r9, r9, #1 */
/* @0x1ea5f4 str r9, [sp, #0xc] */
/* @0x1ea5f8 ldrh r9, [r4, #-2] */
/* @0x1ea5fc rsb r12, r0, r11 */
/* @0x1ea600 ldr r1, [sp, #0x28] */
/* @0x1ea604 ldr r2, [sp, #0x24] */
/* @0x1ea608 ldrh r10, [r4, #-4] */
/* @0x1ea60c add r12, r12, r1 */
/* @0x1ea610 lsl r9, r9, #3 */
/* @0x1ea614 rsb r1, r0, r7 */
/* @0x1ea618 str r9, [sp, #0x5c] */
/* @0x1ea61c add r1, r1, r2 */
/* @0x1ea620 ldr r9, [sp, #0x34] */
/* @0x1ea624 rsb r2, r0, r8 */
/* @0x1ea628 lsl r10, r10, #3 */
/* @0x1ea62c add r7, r7, #144 */
/* @0x1ea630 add r2, r2, r9 */
/* @0x1ea634 ldr r9, [sp, #0x20] */
/* @0x1ea638 add r8, r8, #144 */
/* @0x1ea63c add r11, r9, r10 */
/* @0x1ea640 ldr r9, [sp, #0x1c] */
/* @0x1ea644 vldr s8, [r11] */
/* @0x1ea648 vldr s9, [r11, #4] */
/* @0x1ea64c add r10, r9, r10 */
/* @0x1ea650 ldr r11, [sp, #0x20] */
/* @0x1ea654 ldr r9, [sp, #0x5c] */
/* @0x1ea658 vldr s12, [r10] */
/* @0x1ea65c vldr s13, [r10, #4] */
/* @0x1ea660 add r10, r11, r9 */
/* @0x1ea664 ldr r11, [sp, #0x1c] */
/* @0x1ea668 vldr s14, [r10] */
/* @0x1ea66c vldr s2, [r10, #4] */
/* @0x1ea670 add r11, r11, r9 */
/* @0x1ea674 vldr s10, [r11] */
/* @0x1ea678 vldr s11, [r11, #4] */
/* @0x1ea67c ldr r11, [sp, #0x30] */
/* @0x1ea680 ldr r9, [sp, #0x10] */
/* @0x1ea684 rsb r10, r0, r6 */
/* @0x1ea688 add r10, r10, r11 */
/* @0x1ea68c ldr r11, [sp, #0x2c] */
/* @0x1ea690 add r9, r9, #144 */
/* @0x1ea694 str r9, [sp, #0x10] */
/* @0x1ea698 rsb r9, r0, r5 */
/* @0x1ea69c vstr s8, [r3, #-288] */
/* @0x1ea6a0 add r11, r9, r11 */
/* @0x1ea6a4 ldr r9, [sp, #0x18] */
/* @0x1ea6a8 vstr s9, [r3, #-284] */
/* @0x1ea6ac str r11, [sp, #0x5c] */
/* @0x1ea6b0 vstr s15, [r3, #-280] */
/* @0x1ea6b4 vstr s29, [r3, #-272] */
/* @0x1ea6b8 str r9, [r3, #-0x114] */
/* @0x1ea6bc vstr s28, [r3, #-268] */
/* @0x1ea6c0 vstr s14, [r12, #-24] */
/* @0x1ea6c4 vstr s2, [r12, #-20] */
/* @0x1ea6c8 vstr s15, [r12, #-16] */
/* @0x1ea6cc str r9, [r12, #-0xc] */
/* @0x1ea6d0 vstr s29, [r12, #-8] */
/* @0x1ea6d4 vstr s28, [r12, #-4] */
/* @0x1ea6d8 ldr r11, [sp, #0x14] */
/* @0x1ea6dc vstr s12, [r1, #-48] */
/* @0x1ea6e0 ldr r12, [sp, #0x5c] */
/* @0x1ea6e4 vstr s13, [r1, #-44] */
/* @0x1ea6e8 vstr s15, [r1, #-40] */
/* @0x1ea6ec vstr s29, [r1, #-32] */
/* @0x1ea6f0 str r11, [r1, #-0x24] */
/* @0x1ea6f4 vstr s28, [r1, #-28] */
/* @0x1ea6f8 add r6, r6, #144 */
/* @0x1ea6fc vstr s12, [r2, #-72] */
/* @0x1ea700 vstr s13, [r2, #-68] */
/* @0x1ea704 vstr s15, [r2, #-64] */
/* @0x1ea708 str r11, [r2, #-0x3c] */
/* @0x1ea70c vstr s29, [r2, #-56] */
/* @0x1ea710 vstr s28, [r2, #-52] */
/* @0x1ea714 add r5, r5, #144 */
/* @0x1ea718 vstr s14, [r10, #-96] */
/* @0x1ea71c vstr s2, [r10, #-92] */
/* @0x1ea720 vstr s15, [r10, #-88] */
/* @0x1ea724 str r9, [r10, #-0x54] */
/* @0x1ea728 vstr s29, [r10, #-80] */
/* @0x1ea72c vstr s28, [r10, #-76] */
/* @0x1ea730 vstr s10, [r12, #-120] */
/* @0x1ea734 vstr s11, [r12, #-116] */
/* @0x1ea738 vstr s15, [r12, #-112] */
/* @0x1ea73c str r11, [r12, #-0x6c] */
/* @0x1ea740 vstr s29, [r12, #-104] */
/* @0x1ea744 vstr s28, [r12, #-100] */
/* @0x1ea748 bne 0x1ea5e0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x9d0> */
/* @0x1ea74c ldr r5, [sp, #0x3c] */
/* @0x1ea750 ldr r4, [sp, #0x4c] */
/* @0x1ea754 add r4, r4, r5, lsl #2 */
/* @0x1ea758 str r4, [sp, #0x4c] */
/* @0x1ea75c ldr r6, [sp, #0x40] */
/* @0x1ea760 ldr r7, [sp, #0x3c] */
/* @0x1ea764 rsb r6, r7, r6 */
/* @0x1ea768 str r6, [sp, #0x40] */
/* @0x1ea76c cmp r6, #0 */
/* @0x1ea770 bgt 0x1ea538 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x928> */
/* @0x1ea774 ldr r9, [sp, #0x38] */
/* @0x1ea778 ldr r8, [sp, #0x18] */
/* @0x1ea77c ldr r3, [r9, #0x4c] */
/* @0x1ea780 ldr r1, [r9, #0x40] */
/* @0x1ea784 ldr r10, [sp, #0x54] */
/* @0x1ea788 add r10, r10, r3, lsl #1 */
/* @0x1ea78c str r10, [sp, #0x54] */
/* @0x1ea790 ldr r11, [sp, #0x38] */
/* @0x1ea794 subs r4, r1, #0 */
/* @0x1ea798 ldr r5, [r11, #0x10] */
/* @0x1ea79c ble 0x1ea3f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7e8> */
/* @0x1ea7a0 ldr r7, [sp, #0x8c] */
/* @0x1ea7a4 ldr r9, [sp, #0x2bc] */
/* @0x1ea7a8 ldr r10, [sp, #0x44] */
/* @0x1ea7ac cmp r4, r7 */
/* @0x1ea7b0 movlt r6, r4 */
/* @0x1ea7b4 movge r6, r7 */
/* @0x1ea7b8 mov r0, #4 */
/* @0x1ea7bc mov r1, r9 */
/* @0x1ea7c0 mov r2, #24 */
/* @0x1ea7c4 add r11, r6, r6, lsl #1 */
/* @0x1ea7c8 mov r3, r11 */
/* @0x1ea7cc bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea7d0 cmp r11, #0 */
/* @0x1ea7d4 ble 0x1ea828 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xc18> */
/* @0x1ea7d8 ldr r2, [pc, #-0x6e8] */
/* @0x1ea7dc add r3, r5, r11, lsl #1 */
/* @0x1ea7e0 ldr r1, [pc, #-0x704] */
/* @0x1ea7e4 add r0, r0, #24 */
/* @0x1ea7e8 ldr r2, [r10, r2] */
/* @0x1ea7ec ldr r1, [r10, r1] */
/* @0x1ea7f0 ldr r11, [r2] */
/* @0x1ea7f4 ldrh r2, [r5], #2 */
/* @0x1ea7f8 add r0, r0, #24 */
/* @0x1ea7fc cmp r5, r3 */
/* @0x1ea800 add r2, r1, r2, lsl #3 */
/* @0x1ea804 ldr r12, [r2] */
/* @0x1ea808 ldr r2, [r2, #0x4] */
/* @0x1ea80c vstr s29, [r0, #-32] */
/* @0x1ea810 str r11, [r0, #-0x28] */
/* @0x1ea814 vstr s28, [r0, #-28] */
/* @0x1ea818 str r12, [r0, #-0x30] */
/* @0x1ea81c str r2, [r0, #-0x2c] */
/* @0x1ea820 str r8, [r0, #-0x24] */
/* @0x1ea824 bne 0x1ea7f4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xbe4> */
/* @0x1ea828 rsb r4, r6, r4 */
/* @0x1ea82c cmp r4, #0 */
/* @0x1ea830 bgt 0x1ea7ac <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb9c> */
/* @0x1ea834 b 0x1ea3f0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7e0> */
/* @0x1ea838 ldr r10, [sp, #0x44] */
/* @0x1ea83c ldr r3, [pc, #-0x75c] */
/* @0x1ea840 ldr r1, [sp, #0xa4] */
/* @0x1ea844 ldr r3, [r10, r3] */
/* @0x1ea848 ldr r0, [r3] */
/* @0x1ea84c ldr r3, [r0] */
/* @0x1ea850 ldr r3, [r3, #0xc] */
/* @0x1ea854 blx r3 */
/* @0x1ea858 b 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */
/* @0x1ea85c ldr r9, [r6, #0x4] */
/* @0x1ea860 add r4, sp, #368 */
/* @0x1ea864 ldr r10, [sp, #0x6c] */
/* @0x1ea868 mov r2, #0 */
/* @0x1ea86c ldr r12, [sp, #0x70] */
/* @0x1ea870 ubfx r7, r9, #0x8, #0x8 */
/* @0x1ea874 ubfx r8, r9, #0x10, #0x8 */
/* @0x1ea878 ldr r11, [sp, #0x68] */
/* @0x1ea87c mul r6, r7, r10 */
/* @0x1ea880 ldr r10, [sp, #0x74] */
/* @0x1ea884 mul r5, r8, r12 */
/* @0x1ea888 uxtb r0, r9 */
/* @0x1ea88c lsr r9, r9, #24 */
/* @0x1ea890 mul r1, r0, r11 */
/* @0x1ea894 lsr r6, r6, #8 */
/* @0x1ea898 mul r12, r9, r10 */
/* @0x1ea89c lsr r5, r5, #8 */
/* @0x1ea8a0 str r6, [sp, #0x174] */
/* @0x1ea8a4 str r5, [sp, #0x178] */
/* @0x1ea8a8 ldr r6, [sp, #0x2b4] */
/* @0x1ea8ac lsr r1, r1, #8 */
/* @0x1ea8b0 ldr r5, [sp, #0x2b0] */
/* @0x1ea8b4 lsr r12, r12, #8 */
/* @0x1ea8b8 str r1, [sp, #0x170] */
/* @0x1ea8bc str r12, [sp, #0x17c] */
/* @0x1ea8c0 ldr r10, [r5, r2] */
/* @0x1ea8c4 ldr r12, [r6, r2] */
/* @0x1ea8c8 mul r1, r10, r1 */
/* @0x1ea8cc add r1, r12, r1, asr #8 */
/* @0x1ea8d0 usat r1, #0x8, r1 */
/* @0x1ea8d4 str r1, [r4, r2] */
/* @0x1ea8d8 add r2, r2, #4 */
/* @0x1ea8dc cmp r2, #16 */
/* @0x1ea8e0 ldrne r1, [r4, r2] */
/* @0x1ea8e4 bne 0x1ea8c0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xcb0> */
/* @0x1ea8e8 ldr r4, [sp, #0x80] */
/* @0x1ea8ec ldr r11, [sp, #0x78] */
/* @0x1ea8f0 ldr r12, [sp, #0x7c] */
/* @0x1ea8f4 ldr r5, [sp, #0x84] */
/* @0x1ea8f8 ldr r1, [sp, #0x178] */
/* @0x1ea8fc mul r8, r8, r4 */
/* @0x1ea900 ldr r6, [sp, #0x2b8] */
/* @0x1ea904 mul r2, r0, r11 */
/* @0x1ea908 ldr r0, [sp, #0x174] */
/* @0x1ea90c mul r7, r7, r12 */
/* @0x1ea910 lsl r1, r1, #16 */
/* @0x1ea914 mul r9, r9, r5 */
/* @0x1ea918 orr r1, r1, r0, lsl #8 */
/* @0x1ea91c ldr r12, [sp, #0x17c] */
/* @0x1ea920 add r5, sp, #432 */
/* @0x1ea924 ldr r0, [sp, #0x170] */
/* @0x1ea928 lsr r2, r2, #8 */
/* @0x1ea92c ldr r4, [sp, #0x2b0] */
/* @0x1ea930 lsr r7, r7, #8 */
/* @0x1ea934 orr r1, r1, r0 */
/* @0x1ea938 lsr r0, r8, #8 */
/* @0x1ea93c orr r8, r1, r12, lsl #24 */
/* @0x1ea940 mov r1, #0 */
/* @0x1ea944 lsr r9, r9, #8 */
/* @0x1ea948 str r2, [sp, #0x1b0] */
/* @0x1ea94c str r7, [sp, #0x1b4] */
/* @0x1ea950 str r0, [sp, #0x1b8] */
/* @0x1ea954 str r9, [sp, #0x1bc] */
/* @0x1ea958 ldr r12, [r4, r1] */
/* @0x1ea95c ldr r0, [r6, r1] */
/* @0x1ea960 mul r2, r12, r2 */
/* @0x1ea964 add r2, r0, r2, asr #8 */
/* @0x1ea968 usat r2, #0x8, r2 */
/* @0x1ea96c str r2, [r5, r1] */
/* @0x1ea970 add r1, r1, #4 */
/* @0x1ea974 cmp r1, #16 */
/* @0x1ea978 ldrne r2, [r5, r1] */
/* @0x1ea97c bne 0x1ea958 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xd48> */
/* @0x1ea980 ldr r2, [sp, #0x1b8] */
/* @0x1ea984 ldr r1, [sp, #0x1b4] */
/* @0x1ea988 ldr r6, [sp, #0x88] */
/* @0x1ea98c ldr r0, [sp, #0x1b0] */
/* @0x1ea990 lsl r2, r2, #16 */
/* @0x1ea994 ldr r12, [sp, #0x1bc] */
/* @0x1ea998 orr r2, r2, r1, lsl #8 */
/* @0x1ea99c cmp r6, #0 */
/* @0x1ea9a0 orr r2, r2, r0 */
/* @0x1ea9a4 orr r12, r2, r12, lsl #24 */
/* @0x1ea9a8 str r12, [sp, #0x14] */
/* @0x1ea9ac beq 0x1eb39c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x178c> */
/* @0x1ea9b0 ldr r7, [sp, #0x60] */
/* @0x1ea9b4 cmp r7, #0 */
/* @0x1ea9b8 beq 0x1eac48 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1038> */
/* @0x1ea9bc ldr r9, [sp, #0x38] */
/* @0x1ea9c0 ldr r2, [r9, #0x44] */
/* @0x1ea9c4 cmp r2, #0 */
/* @0x1ea9c8 beq 0x1eac48 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1038> */
/* @0x1ea9cc ldr r10, [r9, #0x14] */
/* @0x1ea9d0 str r2, [sp, #0x40] */
/* @0x1ea9d4 str r10, [sp, #0x4c] */
/* @0x1ea9d8 ble 0x1eac3c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x102c> */
/* @0x1ea9dc str r8, [sp, #0x18] */
/* @0x1ea9e0 ldr r11, [sp, #0x40] */
/* @0x1ea9e4 mov r0, #4 */
/* @0x1ea9e8 ldr r12, [sp, #0x58] */
/* @0x1ea9ec mov r2, #24 */
/* @0x1ea9f0 ldr r1, [sp, #0x2bc] */
/* @0x1ea9f4 cmp r11, r12 */
/* @0x1ea9f8 movge r11, r12 */
/* @0x1ea9fc str r11, [sp, #0x3c] */
/* @0x1eaa00 add r3, r11, r11, lsl #1 */
/* @0x1eaa04 lsl r3, r3, #1 */
/* @0x1eaa08 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eaa0c cmp r11, #0 */
/* @0x1eaa10 ble 0x1eac14 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1004> */
/* @0x1eaa14 ldr r6, [sp, #0x44] */
/* @0x1eaa18 add r4, r0, #48 */
/* @0x1eaa1c ldr r1, [pc, #-0x934] */
/* @0x1eaa20 add r5, r0, #72 */
/* @0x1eaa24 str r4, [sp, #0x30] */
/* @0x1eaa28 add r2, r0, #24 */
/* @0x1eaa2c str r5, [sp, #0x2c] */
/* @0x1eaa30 add r7, r0, #96 */
/* @0x1eaa34 str r2, [sp, #0x34] */
/* @0x1eaa38 add r8, r0, #120 */
/* @0x1eaa3c ldr r1, [r6, r1] */
/* @0x1eaa40 ldr r3, [pc, #-0x954] */
/* @0x1eaa44 str r7, [sp, #0x28] */
/* @0x1eaa48 mov r7, r4 */
/* @0x1eaa4c str r1, [sp, #0x20] */
/* @0x1eaa50 ldr r2, [pc, #-0x960] */
/* @0x1eaa54 ldr r3, [r6, r3] */
/* @0x1eaa58 ldr r9, [sp, #0x34] */
/* @0x1eaa5c ldr r10, [sp, #0x44] */
/* @0x1eaa60 str r8, [sp, #0x24] */
/* @0x1eaa64 mov r8, r5 */
/* @0x1eaa68 ldr r6, [sp, #0x28] */
/* @0x1eaa6c ldr r5, [sp, #0x24] */
/* @0x1eaa70 ldr r4, [sp, #0x4c] */
/* @0x1eaa74 str r3, [sp, #0x1c] */
/* @0x1eaa78 add r3, r0, #144 */
/* @0x1eaa7c str r9, [sp, #0x10] */
/* @0x1eaa80 str r11, [sp, #0xc] */
/* @0x1eaa84 ldr r2, [r10, r2] */
/* @0x1eaa88 vldr s15, [r2] */
/* @0x1eaa8c mov r2, r7 */
/* @0x1eaa90 mov r7, r6 */
/* @0x1eaa94 mov r6, r2 */
/* @0x1eaa98 ldrh r9, [r4, #2] */
/* @0x1eaa9c add r3, r3, #144 */
/* @0x1eaaa0 ldr r1, [sp, #0x10] */
/* @0x1eaaa4 add r4, r4, #4 */
/* @0x1eaaa8 ldr r2, [sp, #0x34] */
/* @0x1eaaac ldrh r10, [r4, #-4] */
/* @0x1eaab0 rsb r12, r0, r1 */
/* @0x1eaab4 ldr r11, [sp, #0xc] */
/* @0x1eaab8 lsl r9, r9, #3 */
/* @0x1eaabc str r9, [sp, #0x5c] */
/* @0x1eaac0 add r12, r12, r2 */
/* @0x1eaac4 ldr r9, [sp, #0x2c] */
/* @0x1eaac8 rsb r2, r0, r8 */
/* @0x1eaacc subs r11, r11, #1 */
/* @0x1eaad0 str r11, [sp, #0xc] */
/* @0x1eaad4 add r2, r2, r9 */
/* @0x1eaad8 ldr r11, [sp, #0x30] */
/* @0x1eaadc ldr r9, [sp, #0x20] */
/* @0x1eaae0 rsb r1, r0, r6 */
/* @0x1eaae4 lsl r10, r10, #3 */
/* @0x1eaae8 add r1, r1, r11 */
/* @0x1eaaec add r11, r9, r10 */
/* @0x1eaaf0 ldr r9, [sp, #0x1c] */
/* @0x1eaaf4 vldr s8, [r11] */
/* @0x1eaaf8 vldr s9, [r11, #4] */
/* @0x1eaafc add r10, r9, r10 */
/* @0x1eab00 ldr r11, [sp, #0x20] */
/* @0x1eab04 ldr r9, [sp, #0x5c] */
/* @0x1eab08 vldr s12, [r10] */
/* @0x1eab0c vldr s13, [r10, #4] */
/* @0x1eab10 add r6, r6, #144 */
/* @0x1eab14 add r10, r11, r9 */
/* @0x1eab18 ldr r11, [sp, #0x1c] */
/* @0x1eab1c vldr s14, [r10] */
/* @0x1eab20 vldr s2, [r10, #4] */
/* @0x1eab24 add r11, r11, r9 */
/* @0x1eab28 vldr s10, [r11] */
/* @0x1eab2c vldr s11, [r11, #4] */
/* @0x1eab30 ldr r11, [sp, #0x28] */
/* @0x1eab34 ldr r9, [sp, #0x10] */
/* @0x1eab38 rsb r10, r0, r7 */
/* @0x1eab3c add r10, r10, r11 */
/* @0x1eab40 ldr r11, [sp, #0x24] */
/* @0x1eab44 add r9, r9, #144 */
/* @0x1eab48 str r9, [sp, #0x10] */
/* @0x1eab4c rsb r9, r0, r5 */
/* @0x1eab50 vstr s8, [r3, #-288] */
/* @0x1eab54 add r11, r9, r11 */
/* @0x1eab58 ldr r9, [sp, #0x18] */
/* @0x1eab5c vstr s9, [r3, #-284] */
/* @0x1eab60 str r11, [sp, #0x5c] */
/* @0x1eab64 vstr s15, [r3, #-280] */
/* @0x1eab68 vstr s29, [r3, #-272] */
/* @0x1eab6c str r9, [r3, #-0x114] */
/* @0x1eab70 vstr s28, [r3, #-268] */
/* @0x1eab74 vstr s14, [r12, #-24] */
/* @0x1eab78 vstr s2, [r12, #-20] */
/* @0x1eab7c vstr s15, [r12, #-16] */
/* @0x1eab80 str r9, [r12, #-0xc] */
/* @0x1eab84 vstr s29, [r12, #-8] */
/* @0x1eab88 vstr s28, [r12, #-4] */
/* @0x1eab8c ldr r11, [sp, #0x14] */
/* @0x1eab90 vstr s12, [r1, #-48] */
/* @0x1eab94 ldr r12, [sp, #0x5c] */
/* @0x1eab98 vstr s13, [r1, #-44] */
/* @0x1eab9c vstr s15, [r1, #-40] */
/* @0x1eaba0 vstr s29, [r1, #-32] */
/* @0x1eaba4 str r11, [r1, #-0x24] */
/* @0x1eaba8 vstr s28, [r1, #-28] */
/* @0x1eabac add r8, r8, #144 */
/* @0x1eabb0 vstr s12, [r2, #-72] */
/* @0x1eabb4 vstr s13, [r2, #-68] */
/* @0x1eabb8 vstr s15, [r2, #-64] */
/* @0x1eabbc str r11, [r2, #-0x3c] */
/* @0x1eabc0 vstr s29, [r2, #-56] */
/* @0x1eabc4 vstr s28, [r2, #-52] */
/* @0x1eabc8 add r7, r7, #144 */
/* @0x1eabcc vstr s14, [r10, #-96] */
/* @0x1eabd0 vstr s2, [r10, #-92] */
/* @0x1eabd4 vstr s15, [r10, #-88] */
/* @0x1eabd8 str r9, [r10, #-0x54] */
/* @0x1eabdc vstr s29, [r10, #-80] */
/* @0x1eabe0 vstr s28, [r10, #-76] */
/* @0x1eabe4 add r5, r5, #144 */
/* @0x1eabe8 vstr s10, [r12, #-120] */
/* @0x1eabec vstr s11, [r12, #-116] */
/* @0x1eabf0 vstr s15, [r12, #-112] */
/* @0x1eabf4 str r11, [r12, #-0x6c] */
/* @0x1eabf8 vstr s29, [r12, #-104] */
/* @0x1eabfc vstr s28, [r12, #-100] */
/* @0x1eac00 bne 0x1eaa98 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xe88> */
/* @0x1eac04 ldr r5, [sp, #0x3c] */
/* @0x1eac08 ldr r4, [sp, #0x4c] */
/* @0x1eac0c add r4, r4, r5, lsl #2 */
/* @0x1eac10 str r4, [sp, #0x4c] */
/* @0x1eac14 ldr r6, [sp, #0x40] */
/* @0x1eac18 ldr r7, [sp, #0x3c] */
/* @0x1eac1c rsb r6, r7, r6 */
/* @0x1eac20 str r6, [sp, #0x40] */
/* @0x1eac24 cmp r6, #0 */
/* @0x1eac28 bgt 0x1ea9e0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xdd0> */
/* @0x1eac2c ldr r9, [sp, #0x38] */
/* @0x1eac30 ldr r8, [sp, #0x18] */
/* @0x1eac34 ldr r2, [r9, #0x44] */
/* @0x1eac38 ldr r3, [r9, #0x38] */
/* @0x1eac3c ldr r10, [sp, #0x54] */
/* @0x1eac40 add r10, r10, r2, lsl #1 */
/* @0x1eac44 str r10, [sp, #0x54] */
/* @0x1eac48 ldr r11, [sp, #0x38] */
/* @0x1eac4c subs r4, r3, #0 */
/* @0x1eac50 ldr r6, [r11, #0x8] */
/* @0x1eac54 ble 0x1eacfc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10ec> */
/* @0x1eac58 ldr r7, [sp, #0x8c] */
/* @0x1eac5c ldr r9, [sp, #0x2bc] */
/* @0x1eac60 ldr r10, [sp, #0x44] */
/* @0x1eac64 cmp r4, r7 */
/* @0x1eac68 movlt r5, r4 */
/* @0x1eac6c movge r5, r7 */
/* @0x1eac70 mov r0, #4 */
/* @0x1eac74 mov r1, r9 */
/* @0x1eac78 mov r2, #24 */
/* @0x1eac7c add r11, r5, r5, lsl #1 */
/* @0x1eac80 mov r3, r11 */
/* @0x1eac84 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eac88 cmp r11, #0 */
/* @0x1eac8c ble 0x1eace8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10d8> */
/* @0x1eac90 ldr r12, [pc, #-0xba8] */
/* @0x1eac94 mov r2, r6 */
/* @0x1eac98 ldr r1, [pc, #-0xba8] */
/* @0x1eac9c add r6, r6, r11, lsl #1 */
/* @0x1eaca0 add r3, r0, #24 */
/* @0x1eaca4 ldr r12, [r10, r12] */
/* @0x1eaca8 ldr r1, [r10, r1] */
/* @0x1eacac vldr s15, [r1] */
/* @0x1eacb0 ldrh r1, [r2], #2 */
/* @0x1eacb4 add r3, r3, #24 */
/* @0x1eacb8 cmp r2, r6 */
/* @0x1eacbc add r1, r12, r1, lsl #3 */
/* @0x1eacc0 ldr r0, [r1] */
/* @0x1eacc4 ldr r1, [r1, #0x4] */
/* @0x1eacc8 vstr s15, [r3, #-40] */
/* @0x1eaccc str r8, [r3, #-0x24] */
/* @0x1eacd0 vstr s29, [r3, #-32] */
/* @0x1eacd4 str r0, [r3, #-0x30] */
/* @0x1eacd8 vstr s28, [r3, #-28] */
/* @0x1eacdc str r1, [r3, #-0x2c] */
/* @0x1eace0 bne 0x1eacb0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10a0> */
/* @0x1eace4 mov r6, r2 */
/* @0x1eace8 rsb r4, r5, r4 */
/* @0x1eacec cmp r4, #0 */
/* @0x1eacf0 bgt 0x1eac64 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1054> */
/* @0x1eacf4 ldr r12, [sp, #0x38] */
/* @0x1eacf8 ldr r3, [r12, #0x38] */
/* @0x1eacfc ldr r4, [sp, #0x54] */
/* @0x1ead00 add r4, r3, r4 */
/* @0x1ead04 str r4, [sp, #0x54] */
/* @0x1ead08 b 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead0c cmp r7, #2 */
/* @0x1ead10 beq 0x1eb69c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a8c> */
/* @0x1ead14 cmp r7, #3 */
/* @0x1ead18 bne 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead1c ldr r3, [r6, #0xc] */
/* @0x1ead20 cmn r3, #1 */
/* @0x1ead24 beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead28 ldr r8, [sp, #0xa8] */
/* @0x1ead2c ldr r2, [r8, #0x7c] */
/* @0x1ead30 ldr r3, [r2, r3, lsl #2] */
/* @0x1ead34 ldr r2, [r3, #0x10] */
/* @0x1ead38 cmp r2, #0 */
/* @0x1ead3c bge 0x1eb82c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1c1c> */
/* @0x1ead40 ldr r3, [r3, #0xc] */
/* @0x1ead44 cmp r3, #0 */
/* @0x1ead48 str r3, [sp, #0x90] */
/* @0x1ead4c beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead50 vmov.f32 s15, #1.000000e+00 */
/* @0x1ead54 vldr s14, [r3, #4] */
/* @0x1ead58 vldr s13, [r3, #8] */
/* @0x1ead5c add r0, sp, #176 */
/* @0x1ead60 add r1, r6, #16 */
/* @0x1ead64 add r2, sp, #432 */
/* @0x1ead68 vstr s30, [sp, #488] */
/* @0x1ead6c vstr s30, [sp, #484] */
/* @0x1ead70 vstr s30, [sp, #480] */
/* @0x1ead74 vstr s30, [sp, #476] */
/* @0x1ead78 vstr s30, [sp, #468] */
/* @0x1ead7c vstr s30, [sp, #464] */
/* @0x1ead80 vstr s30, [sp, #460] */
/* @0x1ead84 vstr s30, [sp, #456] */
/* @0x1ead88 vstr s30, [sp, #448] */
/* @0x1ead8c vstr s30, [sp, #444] */
/* @0x1ead90 vstr s30, [sp, #440] */
/* @0x1ead94 vstr s30, [sp, #436] */
/* @0x1ead98 vcvt.f32.s32 s13, s13 */
/* @0x1ead9c vstr s15, [sp, #492] */
/* @0x1eada0 vstr s15, [sp, #472] */
/* @0x1eada4 vcvt.f32.s32 s14, s14 */
/* @0x1eada8 vdiv.f32 s14, s15, s14 */
/* @0x1eadac vdiv.f32 s15, s15, s13 */
/* @0x1eadb0 vstr s14, [sp, #432] */
/* @0x1eadb4 vstr s15, [sp, #452] */
/* @0x1eadb8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eadbc ldr r6, [r6, #0x4] */
/* @0x1eadc0 ldr r0, [pc, #-0xcdc] */
/* @0x1eadc4 bics r6, r6, #2 */
/* @0x1eadc8 bne 0x1eba08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1df8> */
/* @0x1eadcc ldr r12, [sp, #0x44] */
/* @0x1eadd0 add r4, sp, #368 */
/* @0x1eadd4 mov r1, r6 */
/* @0x1eadd8 mov r2, #2 */
/* @0x1eaddc mov r3, r6 */
/* @0x1eade0 ldr r5, [r12, r0] */
/* @0x1eade4 mov r0, r5 */
/* @0x1eade8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eadec mov r0, r5 */
/* @0x1eadf0 mov r1, r6 */
/* @0x1eadf4 mov r2, r7 */
/* @0x1eadf8 mov r3, r6 */
/* @0x1eadfc bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eae00 ldr r12, [sp, #0x2a8] */
/* @0x1eae04 mov r3, #0 */
/* @0x1eae08 ldr r5, [sp, #0x2b0] */
/* @0x1eae0c ldr r6, [sp, #0x2b4] */
/* @0x1eae10 ldr r1, [r5, r3] */
/* @0x1eae14 ldr r0, [r12, r3] */
/* @0x1eae18 ldr r2, [r6, r3] */
/* @0x1eae1c mul r1, r0, r1 */
/* @0x1eae20 add r2, r2, r1, lsr #8 */
/* @0x1eae24 usat r2, #0x8, r2 */
/* @0x1eae28 str r2, [r4, r3] */
/* @0x1eae2c add r3, r3, #4 */
/* @0x1eae30 cmp r3, #16 */
/* @0x1eae34 bne 0x1eae10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1200> */
/* @0x1eae38 ldr r3, [sp, #0x178] */
/* @0x1eae3c ldr r2, [sp, #0x174] */
/* @0x1eae40 ldr r7, [sp, #0x60] */
/* @0x1eae44 ldr r1, [sp, #0x170] */
/* @0x1eae48 lsl r3, r3, #16 */
/* @0x1eae4c ldr r0, [sp, #0x17c] */
/* @0x1eae50 orr r3, r3, r2, lsl #8 */
/* @0x1eae54 cmp r7, #0 */
/* @0x1eae58 orr r3, r3, r1 */
/* @0x1eae5c orr r4, r3, r0, lsl #24 */
/* @0x1eae60 beq 0x1eb264 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1654> */
/* @0x1eae64 ldr r8, [sp, #0x38] */
/* @0x1eae68 ldr r0, [r8, #0x44] */
/* @0x1eae6c cmp r0, #0 */
/* @0x1eae70 beq 0x1eb264 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1654> */
/* @0x1eae74 ldr r6, [sp, #0x2ac] */
/* @0x1eae78 add r5, sp, #432 */
/* @0x1eae7c ldr r7, [sp, #0x2b0] */
/* @0x1eae80 mov r3, #0 */
/* @0x1eae84 ldr r8, [sp, #0x2b8] */
/* @0x1eae88 ldr r1, [r7, r3] */
/* @0x1eae8c ldr r12, [r6, r3] */
/* @0x1eae90 ldr r2, [r8, r3] */
/* @0x1eae94 mul r1, r12, r1 */
/* @0x1eae98 add r2, r2, r1, lsr #8 */
/* @0x1eae9c usat r2, #0x8, r2 */
/* @0x1eaea0 str r2, [r5, r3] */
/* @0x1eaea4 add r3, r3, #4 */
/* @0x1eaea8 cmp r3, #16 */
/* @0x1eaeac bne 0x1eae88 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1278> */
/* @0x1eaeb0 ldr r3, [sp, #0x1b8] */
/* @0x1eaeb4 subs r9, r0, #0 */
/* @0x1eaeb8 ldr r10, [sp, #0x38] */
/* @0x1eaebc ldr r2, [sp, #0x1b4] */
/* @0x1eaec0 ldr r1, [sp, #0x1b0] */
/* @0x1eaec4 lsl r3, r3, #16 */
/* @0x1eaec8 ldr r12, [sp, #0x1bc] */
/* @0x1eaecc ldr r10, [r10, #0x14] */
/* @0x1eaed0 orr r3, r3, r2, lsl #8 */
/* @0x1eaed4 orr r3, r3, r1 */
/* @0x1eaed8 str r9, [sp, #0x94] */
/* @0x1eaedc orr r12, r3, r12, lsl #24 */
/* @0x1eaee0 str r12, [sp, #0x20] */
/* @0x1eaee4 str r10, [sp, #0x98] */
/* @0x1eaee8 ble 0x1eb258 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1648> */
/* @0x1eaeec str r4, [sp, #0x1c] */
/* @0x1eaef0 ldr r11, [sp, #0x94] */
/* @0x1eaef4 mov r0, #4 */
/* @0x1eaef8 ldr r12, [sp, #0x58] */
/* @0x1eaefc mov r2, #24 */
/* @0x1eaf00 ldr r1, [sp, #0x90] */
/* @0x1eaf04 cmp r11, r12 */
/* @0x1eaf08 movge r11, r12 */
/* @0x1eaf0c str r11, [sp, #0x64] */
/* @0x1eaf10 add r3, r11, r11, lsl #1 */
/* @0x1eaf14 lsl r3, r3, #1 */
/* @0x1eaf18 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eaf1c cmp r11, #0 */
/* @0x1eaf20 ble 0x1eb234 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1624> */
/* @0x1eaf24 ldr r6, [sp, #0x44] */
/* @0x1eaf28 add r4, r0, #48 */
/* @0x1eaf2c ldr r1, [pc, #-0xe44] */
/* @0x1eaf30 add r5, r0, #72 */
/* @0x1eaf34 str r4, [sp, #0x3c] */
/* @0x1eaf38 add r2, r0, #24 */
/* @0x1eaf3c str r5, [sp, #0x40] */
/* @0x1eaf40 add r7, r0, #96 */
/* @0x1eaf44 str r2, [sp, #0x34] */
/* @0x1eaf48 add r8, r0, #120 */
/* @0x1eaf4c ldr r1, [r6, r1] */
/* @0x1eaf50 vldr s9, [sp, #176] */
/* @0x1eaf54 ldr r3, [pc, #-0xe68] */
/* @0x1eaf58 vldr s10, [sp, #192] */
/* @0x1eaf5c ldr r9, [sp, #0x38] */
/* @0x1eaf60 vldr s11, [sp, #224] */
/* @0x1eaf64 ldr r10, [sp, #0x38] */
/* @0x1eaf68 vldr s12, [sp, #180] */
/* @0x1eaf6c str r1, [sp, #0x30] */
/* @0x1eaf70 vldr s13, [sp, #196] */
/* @0x1eaf74 str r7, [sp, #0x4c] */
/* @0x1eaf78 vldr s14, [sp, #228] */
/* @0x1eaf7c ldr r3, [r6, r3] */
/* @0x1eaf80 mov r6, r8 */
/* @0x1eaf84 ldr r10, [r10, #0x18] */
/* @0x1eaf88 ldr r11, [sp, #0x34] */
/* @0x1eaf8c str r4, [sp, #0x10] */
/* @0x1eaf90 ldr r2, [pc, #-0xea0] */
/* @0x1eaf94 ldr r4, [sp, #0x44] */
/* @0x1eaf98 ldr r9, [r9] */
/* @0x1eaf9c ldr r12, [sp, #0x64] */
/* @0x1eafa0 str r3, [sp, #0x2c] */
/* @0x1eafa4 add r3, r0, #144 */
/* @0x1eafa8 str r10, [sp, #0x28] */
/* @0x1eafac str r11, [sp, #0xc] */
/* @0x1eafb0 mov r11, r7 */
/* @0x1eafb4 str r5, [sp, #0x18] */
/* @0x1eafb8 str r8, [sp, #0x5c] */
/* @0x1eafbc str r9, [sp, #0x24] */
/* @0x1eafc0 str r12, [sp, #0x14] */
/* @0x1eafc4 ldr r2, [r4, r2] */
/* @0x1eafc8 ldr r5, [sp, #0x98] */
/* @0x1eafcc ldr r4, [r2] */
/* @0x1eafd0 mov r10, r5 */
/* @0x1eafd4 ldrh r12, [r10] */
/* @0x1eafd8 add r3, r3, #144 */
/* @0x1eafdc ldr r5, [sp, #0x14] */
/* @0x1eafe0 add r10, r10, #4 */
/* @0x1eafe4 ldr r7, [sp, #0xc] */
/* @0x1eafe8 ldrh r2, [r10, #-2] */
/* @0x1eafec subs r5, r5, #1 */
/* @0x1eaff0 ldr r8, [sp, #0x34] */
/* @0x1eaff4 lsl r12, r12, #3 */
/* @0x1eaff8 str r5, [sp, #0x14] */
/* @0x1eaffc rsb r1, r0, r7 */
/* @0x1eb000 ldr r5, [sp, #0x24] */
/* @0x1eb004 add r1, r1, r8 */
/* @0x1eb008 ldr r8, [sp, #0x28] */
/* @0x1eb00c lsl r2, r2, #3 */
/* @0x1eb010 add r9, r5, r12 */
/* @0x1eb014 vldr s2, [r9, #4] */
/* @0x1eb018 vmov.f32 s6, s2 */
/* @0x1eb01c add r7, r7, #144 */
/* @0x1eb020 str r7, [sp, #0xc] */
/* @0x1eb024 add r7, r5, r2 */
/* @0x1eb028 add r5, r8, r2 */
/* @0x1eb02c vldr s4, [r7, #4] */
/* @0x1eb030 str r7, [sp, #0x8] */
/* @0x1eb034 add r7, r8, r12 */
/* @0x1eb038 ldr r8, [sp, #0x2c] */
/* @0x1eb03c vldr s7, [r7, #4] */
/* @0x1eb040 vldr s5, [r7] */
/* @0x1eb044 ldr r7, [sp, #0x30] */
/* @0x1eb048 vldr s8, [r5, #4] */
/* @0x1eb04c vmla.f32 s6, s7, s20 */
/* @0x1eb050 vldr s7, [r5] */
/* @0x1eb054 add r5, r7, r12 */
/* @0x1eb058 add r12, r8, r12 */
/* @0x1eb05c vldr s1, [r5] */
/* @0x1eb060 vldr s3, [r5, #4] */
/* @0x1eb064 ldr r5, [sp, #0x2c] */
/* @0x1eb068 vldr s23, [r9] */
/* @0x1eb06c ldr r8, [r12, #0x4] */
/* @0x1eb070 ldr r9, [sp, #0x8] */
/* @0x1eb074 vldr s0, [r9] */
/* @0x1eb078 ldr r9, [r12] */
/* @0x1eb07c add r12, r7, r2 */
/* @0x1eb080 add r2, r5, r2 */
/* @0x1eb084 vldr s15, [r12] */
/* @0x1eb088 vldr s26, [r2, #4] */
/* @0x1eb08c vstr s15, [sp] */
/* @0x1eb090 vldr s15, [r12, #4] */
/* @0x1eb094 vstr s15, [sp, #8] */
/* @0x1eb098 vldr s15, [r2] */
/* @0x1eb09c vstr s1, [r3, #-288] */
/* @0x1eb0a0 vstr s3, [r3, #-284] */
/* @0x1eb0a4 ldr r5, [sp, #0x10] */
/* @0x1eb0a8 ldr r7, [sp, #0x3c] */
/* @0x1eb0ac ldr r12, [sp, #0x1c] */
/* @0x1eb0b0 rsb r2, r0, r5 */
/* @0x1eb0b4 add r5, r5, #144 */
/* @0x1eb0b8 str r5, [sp, #0x10] */
/* @0x1eb0bc ldr r5, [sp, #0x18] */
/* @0x1eb0c0 add r2, r2, r7 */
/* @0x1eb0c4 ldr r7, [sp, #0x40] */
/* @0x1eb0c8 rsb r5, r0, r5 */
/* @0x1eb0cc str r12, [r3, #-0x114] */
/* @0x1eb0d0 add r12, r5, r7 */
/* @0x1eb0d4 ldr r5, [sp, #0x18] */
/* @0x1eb0d8 ldr r7, [sp, #0x20] */
/* @0x1eb0dc add r5, r5, #144 */
/* @0x1eb0e0 str r5, [sp, #0x18] */
/* @0x1eb0e4 vmov.f32 s3, s4 */
/* @0x1eb0e8 ldr r5, [sp, #0x1c] */
/* @0x1eb0ec str r4, [r3, #-0x118] */
/* @0x1eb0f0 vmla.f32 s3, s8, s20 */
/* @0x1eb0f4 vmov.f32 s25, s23 */
/* @0x1eb0f8 vmov.f32 s24, s0 */
/* @0x1eb0fc vmla.f32 s25, s5, s20 */
/* @0x1eb100 vmla.f32 s24, s7, s20 */
/* @0x1eb104 vmul.f32 s1, s2, s10 */
/* @0x1eb108 vmul.f32 s2, s2, s13 */
/* @0x1eb10c vmov.f32 s8, s3 */
/* @0x1eb110 vmul.f32 s3, s4, s10 */
/* @0x1eb114 vmul.f32 s4, s4, s13 */
/* @0x1eb118 vmul.f32 s5, s6, s10 */
/* @0x1eb11c vmul.f32 s6, s6, s13 */
/* @0x1eb120 vmul.f32 s7, s8, s10 */
/* @0x1eb124 vmul.f32 s8, s8, s13 */
/* @0x1eb128 vmla.f32 s1, s23, s9 */
/* @0x1eb12c vmla.f32 s2, s23, s12 */
/* @0x1eb130 vmla.f32 s3, s0, s9 */
/* @0x1eb134 vmla.f32 s4, s0, s12 */
/* @0x1eb138 vmla.f32 s5, s25, s9 */
/* @0x1eb13c vmla.f32 s6, s25, s12 */
/* @0x1eb140 vmla.f32 s7, s24, s9 */
/* @0x1eb144 vmla.f32 s8, s24, s12 */
/* @0x1eb148 vadd.f32 s2, s2, s14 */
/* @0x1eb14c vadd.f32 s1, s1, s11 */
/* @0x1eb150 vstr s2, [r3, #-268] */
/* @0x1eb154 vldr s2, [sp] */
/* @0x1eb158 vadd.f32 s3, s3, s11 */
/* @0x1eb15c vstr s1, [r3, #-272] */
/* @0x1eb160 str r5, [r1, #-0xc] */
/* @0x1eb164 vstr s2, [r1, #-24] */
/* @0x1eb168 ldr r5, [sp, #0x4c] */
/* @0x1eb16c vldr s2, [sp, #8] */
/* @0x1eb170 str r4, [r1, #-0x10] */
/* @0x1eb174 vstr s2, [r1, #-20] */
/* @0x1eb178 vadd.f32 s4, s4, s14 */
/* @0x1eb17c vstr s3, [r1, #-8] */
/* @0x1eb180 vadd.f32 s5, s5, s11 */
/* @0x1eb184 vstr s4, [r1, #-4] */
/* @0x1eb188 str r7, [r2, #-0x24] */
/* @0x1eb18c rsb r1, r0, r11 */
/* @0x1eb190 ldr r7, [sp, #0x5c] */
/* @0x1eb194 add r1, r1, r5 */
/* @0x1eb198 str r8, [r2, #-0x2c] */
/* @0x1eb19c add r11, r11, #144 */
/* @0x1eb1a0 str r9, [r2, #-0x30] */
/* @0x1eb1a4 str r4, [r2, #-0x28] */
/* @0x1eb1a8 vadd.f32 s6, s6, s14 */
/* @0x1eb1ac vstr s5, [r2, #-32] */
/* @0x1eb1b0 vadd.f32 s7, s7, s11 */
/* @0x1eb1b4 vstr s6, [r2, #-28] */
/* @0x1eb1b8 rsb r2, r0, r6 */
/* @0x1eb1bc vstr s5, [r12, #-56] */
/* @0x1eb1c0 vstr s6, [r12, #-52] */
/* @0x1eb1c4 str r9, [r12, #-0x48] */
/* @0x1eb1c8 str r8, [r12, #-0x44] */
/* @0x1eb1cc add r2, r2, r7 */
/* @0x1eb1d0 ldr r8, [sp, #0x20] */
/* @0x1eb1d4 vldr s2, [sp] */
/* @0x1eb1d8 ldr r5, [sp, #0x1c] */
/* @0x1eb1dc add r6, r6, #144 */
/* @0x1eb1e0 str r4, [r12, #-0x40] */
/* @0x1eb1e4 str r8, [r12, #-0x3c] */
/* @0x1eb1e8 vstr s3, [r1, #-80] */
/* @0x1eb1ec vstr s4, [r1, #-76] */
/* @0x1eb1f0 vstr s2, [r1, #-96] */
/* @0x1eb1f4 str r4, [r1, #-0x58] */
/* @0x1eb1f8 vldr s3, [sp, #8] */
/* @0x1eb1fc vadd.f32 s8, s8, s14 */
/* @0x1eb200 vstr s3, [r1, #-92] */
/* @0x1eb204 str r5, [r1, #-0x54] */
/* @0x1eb208 vstr s15, [r2, #-120] */
/* @0x1eb20c vstr s26, [r2, #-116] */
/* @0x1eb210 str r4, [r2, #-0x70] */
/* @0x1eb214 str r8, [r2, #-0x6c] */
/* @0x1eb218 vstr s7, [r2, #-104] */
/* @0x1eb21c vstr s8, [r2, #-100] */
/* @0x1eb220 bne 0x1eafd4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x13c4> */
/* @0x1eb224 ldr r7, [sp, #0x64] */
/* @0x1eb228 ldr r6, [sp, #0x98] */
/* @0x1eb22c add r6, r6, r7, lsl #2 */
/* @0x1eb230 str r6, [sp, #0x98] */
/* @0x1eb234 ldr r8, [sp, #0x94] */
/* @0x1eb238 ldr r9, [sp, #0x64] */
/* @0x1eb23c rsb r8, r9, r8 */
/* @0x1eb240 str r8, [sp, #0x94] */
/* @0x1eb244 cmp r8, #0 */
/* @0x1eb248 bgt 0x1eaef0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x12e0> */
/* @0x1eb24c ldr r10, [sp, #0x38] */
/* @0x1eb250 ldr r4, [sp, #0x1c] */
/* @0x1eb254 ldr r0, [r10, #0x44] */
/* @0x1eb258 ldr r11, [sp, #0x54] */
/* @0x1eb25c add r11, r11, r0, lsl #1 */
/* @0x1eb260 str r11, [sp, #0x54] */
/* @0x1eb264 ldr r12, [sp, #0x38] */
/* @0x1eb268 ldr r10, [r12, #0x38] */
/* @0x1eb26c ldr r7, [r12, #0x8] */
/* @0x1eb270 cmp r10, #0 */
/* @0x1eb274 mov r3, r10 */
/* @0x1eb278 ble 0x1eb368 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1758> */
/* @0x1eb27c ldr r6, [sp, #0x90] */
/* @0x1eb280 ldr r8, [sp, #0x8c] */
/* @0x1eb284 ldr r9, [sp, #0x44] */
/* @0x1eb288 cmp r10, r8 */
/* @0x1eb28c movlt r5, r10 */
/* @0x1eb290 movge r5, r8 */
/* @0x1eb294 mov r0, #4 */
/* @0x1eb298 mov r1, r6 */
/* @0x1eb29c mov r2, #24 */
/* @0x1eb2a0 add r11, r5, r5, lsl #1 */
/* @0x1eb2a4 mov r3, r11 */
/* @0x1eb2a8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eb2ac cmp r11, #0 */
/* @0x1eb2b0 ble 0x1eb354 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1744> */
/* @0x1eb2b4 ldr r1, [pc, #0x7bc] */
/* @0x1eb2b8 mov r2, r7 */
/* @0x1eb2bc ldr r12, [pc, #0x7b8] */
/* @0x1eb2c0 add r11, r7, r11, lsl #1 */
/* @0x1eb2c4 ldr r7, [sp, #0x38] */
/* @0x1eb2c8 add r0, r0, #24 */
/* @0x1eb2cc vldr s7, [sp, #176] */
/* @0x1eb2d0 vldr s8, [sp, #192] */
/* @0x1eb2d4 vldr s9, [sp, #224] */
/* @0x1eb2d8 vldr s10, [sp, #180] */
/* @0x1eb2dc ldr r3, [r7] */
/* @0x1eb2e0 vldr s11, [sp, #196] */
/* @0x1eb2e4 ldr r7, [r9, r1] */
/* @0x1eb2e8 vldr s12, [sp, #228] */
/* @0x1eb2ec ldr r1, [r9, r12] */
/* @0x1eb2f0 vldr s6, [r1] */
/* @0x1eb2f4 ldrh r1, [r2], #2 */
/* @0x1eb2f8 add r0, r0, #24 */
/* @0x1eb2fc cmp r2, r11 */
/* @0x1eb300 lsl r1, r1, #3 */
/* @0x1eb304 add r12, r7, r1 */
/* @0x1eb308 vldr s15, [r12] */
/* @0x1eb30c add r1, r3, r1 */
/* @0x1eb310 ldr r12, [r12, #0x4] */
/* @0x1eb314 vstr s15, [r0, #-48] */
/* @0x1eb318 vstr s6, [r0, #-40] */
/* @0x1eb31c str r12, [r0, #-0x2c] */
/* @0x1eb320 vldr s15, [r1, #4] */
/* @0x1eb324 vmul.f32 s14, s15, s8 */
/* @0x1eb328 vldr s13, [r1] */
/* @0x1eb32c str r4, [r0, #-0x24] */
/* @0x1eb330 vmul.f32 s15, s15, s11 */
/* @0x1eb334 vmla.f32 s14, s13, s7 */
/* @0x1eb338 vmla.f32 s15, s13, s10 */
/* @0x1eb33c vadd.f32 s14, s14, s9 */
/* @0x1eb340 vadd.f32 s15, s15, s12 */
/* @0x1eb344 vstr s14, [r0, #-32] */
/* @0x1eb348 vstr s15, [r0, #-28] */
/* @0x1eb34c bne 0x1eb2f4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x16e4> */
/* @0x1eb350 mov r7, r2 */
/* @0x1eb354 rsb r10, r5, r10 */
/* @0x1eb358 cmp r10, #0 */
/* @0x1eb35c bgt 0x1eb288 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1678> */
/* @0x1eb360 ldr r8, [sp, #0x38] */
/* @0x1eb364 ldr r3, [r8, #0x38] */
/* @0x1eb368 ldr r9, [sp, #0x54] */
/* @0x1eb36c add r9, r3, r9 */
/* @0x1eb370 str r9, [sp, #0x54] */
/* @0x1eb374 b 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1eb378 ldr r8, [sp, #0x44] */
/* @0x1eb37c ldr r3, [pc, #0x6fc] */
/* @0x1eb380 ldr r1, [sp, #0xac] */
/* @0x1eb384 ldr r3, [r8, r3] */
/* @0x1eb388 ldr r0, [r3] */
/* @0x1eb38c ldr r3, [r0] */
/* @0x1eb390 ldr r3, [r3, #0xc] */
/* @0x1eb394 blx r3 */
/* @0x1eb398 b 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */
/* @0x1eb39c ldr r5, [sp, #0x60] */
/* @0x1eb3a0 cmp r5, #0 */
/* @0x1eb3a4 beq 0x1eb5f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19e8> */
/* @0x1eb3a8 ldr r6, [sp, #0x38] */
/* @0x1eb3ac ldr r2, [r6, #0x44] */
/* @0x1eb3b0 cmp r2, #0 */
/* @0x1eb3b4 beq 0x1eb5f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19e8> */
/* @0x1eb3b8 ldr r7, [r6, #0x14] */
/* @0x1eb3bc str r2, [sp, #0x40] */
/* @0x1eb3c0 str r7, [sp, #0x4c] */
/* @0x1eb3c4 ble 0x1eb5ec <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19dc> */
/* @0x1eb3c8 str r8, [sp, #0x18] */
/* @0x1eb3cc ldr r8, [sp, #0x40] */
/* @0x1eb3d0 mov r0, #4 */
/* @0x1eb3d4 ldr r9, [sp, #0x58] */
/* @0x1eb3d8 mov r1, #0 */
/* @0x1eb3dc mov r2, #16 */
/* @0x1eb3e0 cmp r8, r9 */
/* @0x1eb3e4 movge r8, r9 */
/* @0x1eb3e8 str r8, [sp, #0x3c] */
/* @0x1eb3ec add r3, r8, r8, lsl #1 */
/* @0x1eb3f0 lsl r3, r3, #1 */
/* @0x1eb3f4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eb3f8 cmp r8, #0 */
/* @0x1eb3fc ble 0x1eb5c4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19b4> */
/* @0x1eb400 ldr r4, [sp, #0x44] */
/* @0x1eb404 add r10, r0, #16 */
/* @0x1eb408 ldr r1, [pc, #0x668] */
/* @0x1eb40c add r11, r0, #32 */
/* @0x1eb410 str r10, [sp, #0x24] */
/* @0x1eb414 add r12, r0, #48 */
/* @0x1eb418 str r11, [sp, #0x2c] */
/* @0x1eb41c add r5, r0, #64 */
/* @0x1eb420 str r12, [sp, #0x28] */
/* @0x1eb424 add r6, r0, #80 */
/* @0x1eb428 ldr r1, [r4, r1] */
/* @0x1eb42c mov r8, r11 */
/* @0x1eb430 ldr r3, [pc, #0x64c] */
/* @0x1eb434 mov r7, r12 */
/* @0x1eb438 str r5, [sp, #0x34] */
/* @0x1eb43c str r1, [sp, #0x20] */
/* @0x1eb440 ldr r3, [r4, r3] */
/* @0x1eb444 str r6, [sp, #0x30] */
/* @0x1eb448 mov r6, r5 */
/* @0x1eb44c str r10, [sp, #0x10] */
/* @0x1eb450 ldr r2, [pc, #0x624] */
/* @0x1eb454 ldr r9, [sp, #0x3c] */
/* @0x1eb458 ldr r10, [sp, #0x44] */
/* @0x1eb45c ldr r5, [sp, #0x30] */
/* @0x1eb460 ldr r4, [sp, #0x4c] */
/* @0x1eb464 str r3, [sp, #0x1c] */
/* @0x1eb468 add r3, r0, #96 */
/* @0x1eb46c str r9, [sp, #0xc] */
/* @0x1eb470 ldr r2, [r10, r2] */
/* @0x1eb474 vldr s15, [r2] */
/* @0x1eb478 ldrh r9, [r4, #2] */
/* @0x1eb47c add r3, r3, #96 */
/* @0x1eb480 ldr r1, [sp, #0x10] */
/* @0x1eb484 add r4, r4, #4 */
/* @0x1eb488 ldr r2, [sp, #0x24] */
/* @0x1eb48c ldrh r10, [r4, #-4] */
/* @0x1eb490 rsb r12, r0, r1 */
/* @0x1eb494 ldr r11, [sp, #0xc] */
/* @0x1eb498 lsl r9, r9, #3 */
/* @0x1eb49c str r9, [sp, #0x5c] */
/* @0x1eb4a0 add r12, r12, r2 */
/* @0x1eb4a4 ldr r9, [sp, #0x28] */
/* @0x1eb4a8 rsb r2, r0, r7 */
/* @0x1eb4ac subs r11, r11, #1 */
/* @0x1eb4b0 str r11, [sp, #0xc] */
/* @0x1eb4b4 add r2, r2, r9 */
/* @0x1eb4b8 ldr r11, [sp, #0x2c] */
/* @0x1eb4bc ldr r9, [sp, #0x20] */
/* @0x1eb4c0 rsb r1, r0, r8 */
/* @0x1eb4c4 lsl r10, r10, #3 */
/* @0x1eb4c8 add r1, r1, r11 */
/* @0x1eb4cc add r11, r9, r10 */
/* @0x1eb4d0 ldr r9, [sp, #0x1c] */
/* @0x1eb4d4 vldr s8, [r11] */
/* @0x1eb4d8 vldr s9, [r11, #4] */
/* @0x1eb4dc add r10, r9, r10 */
/* @0x1eb4e0 ldr r11, [sp, #0x20] */
/* @0x1eb4e4 ldr r9, [sp, #0x5c] */
/* @0x1eb4e8 vldr s12, [r10] */
/* @0x1eb4ec vldr s13, [r10, #4] */
/* @0x1eb4f0 add r8, r8, #96 */
/* @0x1eb4f4 add r10, r11, r9 */
/* @0x1eb4f8 ldr r11, [sp, #0x1c] */
/* @0x1eb4fc vldr s14, [r10] */
/* @0x1eb500 vldr s2, [r10, #4] */
/* @0x1eb504 add r11, r11, r9 */
/* @0x1eb508 vldr s10, [r11] */
/* @0x1eb50c vldr s11, [r11, #4] */
/* @0x1eb510 ldr r11, [sp, #0x34] */
/* @0x1eb514 ldr r9, [sp, #0x10] */
/* @0x1eb518 rsb r10, r0, r6 */
/* @0x1eb51c add r10, r10, r11 */
/* @0x1eb520 ldr r11, [sp, #0x30] */
/* @0x1eb524 add r9, r9, #96 */
/* @0x1eb528 str r9, [sp, #0x10] */
/* @0x1eb52c rsb r9, r0, r5 */
/* @0x1eb530 vstr s8, [r3, #-192] */
/* @0x1eb534 add r11, r9, r11 */
/* @0x1eb538 ldr r9, [sp, #0x18] */
/* @0x1eb53c vstr s9, [r3, #-188] */
/* @0x1eb540 vstr s15, [r3, #-184] */
/* @0x1eb544 str r11, [sp, #0x5c] */
/* @0x1eb548 add r7, r7, #96 */
/* @0x1eb54c str r9, [r3, #-0xb4] */
/* @0x1eb550 vstr s14, [r12, #-16] */
/* @0x1eb554 vstr s2, [r12, #-12] */
/* @0x1eb558 vstr s15, [r12, #-8] */
/* @0x1eb55c str r9, [r12, #-0x4] */
/* @0x1eb560 add r6, r6, #96 */
/* @0x1eb564 ldr r12, [sp, #0x5c] */
/* @0x1eb568 vstr s12, [r1, #-32] */
/* @0x1eb56c ldr r11, [sp, #0x14] */
/* @0x1eb570 vstr s13, [r1, #-28] */
/* @0x1eb574 vstr s15, [r1, #-24] */
/* @0x1eb578 add r5, r5, #96 */
/* @0x1eb57c str r11, [r1, #-0x14] */
/* @0x1eb580 vstr s12, [r2, #-48] */
/* @0x1eb584 vstr s13, [r2, #-44] */
/* @0x1eb588 vstr s15, [r2, #-40] */
/* @0x1eb58c str r11, [r2, #-0x24] */
/* @0x1eb590 vstr s14, [r10, #-64] */
/* @0x1eb594 vstr s2, [r10, #-60] */
/* @0x1eb598 vstr s15, [r10, #-56] */
/* @0x1eb59c str r9, [r10, #-0x34] */
/* @0x1eb5a0 vstr s10, [r12, #-80] */
/* @0x1eb5a4 vstr s11, [r12, #-76] */
/* @0x1eb5a8 vstr s15, [r12, #-72] */
/* @0x1eb5ac str r11, [r12, #-0x44] */
/* @0x1eb5b0 bne 0x1eb478 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1868> */
/* @0x1eb5b4 ldr r5, [sp, #0x3c] */
/* @0x1eb5b8 ldr r4, [sp, #0x4c] */
/* @0x1eb5bc add r4, r4, r5, lsl #2 */
/* @0x1eb5c0 str r4, [sp, #0x4c] */
/* @0x1eb5c4 ldr r6, [sp, #0x40] */
/* @0x1eb5c8 ldr r7, [sp, #0x3c] */
/* @0x1eb5cc rsb r6, r7, r6 */
/* @0x1eb5d0 str r6, [sp, #0x40] */
/* @0x1eb5d4 cmp r6, #0 */
/* @0x1eb5d8 bgt 0x1eb3cc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x17bc> */
/* @0x1eb5dc ldr r9, [sp, #0x38] */
/* @0x1eb5e0 ldr r8, [sp, #0x18] */
/* @0x1eb5e4 ldr r2, [r9, #0x44] */
/* @0x1eb5e8 ldr r3, [r9, #0x38] */
/* @0x1eb5ec ldr r10, [sp, #0x54] */
/* @0x1eb5f0 add r10, r10, r2, lsl #1 */
/* @0x1eb5f4 str r10, [sp, #0x54] */
/* @0x1eb5f8 ldr r11, [sp, #0x38] */
/* @0x1eb5fc subs r4, r3, #0 */
/* @0x1eb600 ldr r6, [r11, #0x8] */
/* @0x1eb604 ble 0x1eacfc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10ec> */
/* @0x1eb608 ldr r7, [sp, #0x8c] */
/* @0x1eb60c ldr r9, [sp, #0x44] */
/* @0x1eb610 cmp r4, r7 */
/* @0x1eb614 movlt r5, r4 */
/* @0x1eb618 movge r5, r7 */
/* @0x1eb61c mov r0, #4 */
/* @0x1eb620 mov r1, #0 */
/* @0x1eb624 mov r2, #16 */
/* @0x1eb628 add r10, r5, r5, lsl #1 */
/* @0x1eb62c mov r3, r10 */
/* @0x1eb630 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eb634 cmp r10, #0 */
/* @0x1eb638 ble 0x1eb68c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a7c> */
/* @0x1eb63c ldr r1, [pc, #0x438] */
/* @0x1eb640 mov r2, r6 */
/* @0x1eb644 ldr r12, [pc, #0x42c] */
/* @0x1eb648 add r6, r6, r10, lsl #1 */
/* @0x1eb64c add r3, r0, #16 */
/* @0x1eb650 ldr r1, [r9, r1] */
/* @0x1eb654 ldr r12, [r9, r12] */
/* @0x1eb658 ldr r10, [r1] */
/* @0x1eb65c ldrh r1, [r2], #2 */
/* @0x1eb660 add r3, r3, #16 */
/* @0x1eb664 cmp r2, r6 */
/* @0x1eb668 add r1, r12, r1, lsl #3 */
/* @0x1eb66c ldr r0, [r1] */
/* @0x1eb670 ldr r1, [r1, #0x4] */
/* @0x1eb674 str r10, [r3, #-0x18] */
/* @0x1eb678 str r0, [r3, #-0x20] */
/* @0x1eb67c str r1, [r3, #-0x1c] */
/* @0x1eb680 str r8, [r3, #-0x14] */
/* @0x1eb684 bne 0x1eb65c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a4c> */
/* @0x1eb688 mov r6, r2 */
/* @0x1eb68c rsb r4, r5, r4 */
/* @0x1eb690 cmp r4, #0 */
/* @0x1eb694 bgt 0x1eb610 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a00> */
/* @0x1eb698 b 0x1eacf4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10e4> */
/* @0x1eb69c ldr r3, [r6, #0x8] */
/* @0x1eb6a0 cmp r3, #0 */
/* @0x1eb6a4 blt 0x1eb9ac <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1d9c> */
/* @0x1eb6a8 ldr r5, [sp, #0xa8] */
/* @0x1eb6ac ldr r2, [r5, #0x54] */
/* @0x1eb6b0 ldr r8, [r2, r3, lsl #2] */
/* @0x1eb6b4 ldrsh r0, [r8, #20] */
/* @0x1eb6b8 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1eb6bc cmp r0, #0 */
/* @0x1eb6c0 beq 0x1eba6c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e5c> */
/* @0x1eb6c4 ldr r10, [sp, #0x44] */
/* @0x1eb6c8 mov lr, #1065353216 */
/* @0x1eb6cc ldr r3, [pc, #0x3b4] */
/* @0x1eb6d0 add r4, sp, #368 */
/* @0x1eb6d4 ldrsh r2, [r8, #20] */
/* @0x1eb6d8 add r5, sp, #432 */
/* @0x1eb6dc ldrsh r9, [r8] */
/* @0x1eb6e0 mov r0, r4 */
/* @0x1eb6e4 ldr r3, [r10, r3] */
/* @0x1eb6e8 add r1, sp, #240 */
/* @0x1eb6ec ldrsh r11, [r8, #2] */
/* @0x1eb6f0 vmov s12, r9 */
/* @0x1eb6f4 ldr r3, [r3, #0x4] */
/* @0x1eb6f8 vmov s13, r11 */
/* @0x1eb6fc vcvt.f32.s32 s12, s12 */
/* @0x1eb700 ldr r3, [r3, r2, lsl #2] */
/* @0x1eb704 add r2, sp, #304 */
/* @0x1eb708 ldr r3, [r3] */
/* @0x1eb70c vldr s14, [r3, #4] */
/* @0x1eb710 vldr s15, [r3, #8] */
/* @0x1eb714 str lr, [sp, #0x16c] */
/* @0x1eb718 str lr, [sp, #0x158] */
/* @0x1eb71c vstr s30, [sp, #348] */
/* @0x1eb720 vcvt.f32.s32 s14, s14 */
/* @0x1eb724 str lr, [sp, #0x144] */
/* @0x1eb728 str lr, [sp, #0x130] */
/* @0x1eb72c vstr s30, [sp, #340] */
/* @0x1eb730 vstr s30, [sp, #336] */
/* @0x1eb734 vstr s30, [sp, #332] */
/* @0x1eb738 vstr s30, [sp, #328] */
/* @0x1eb73c vstr s30, [sp, #320] */
/* @0x1eb740 vstr s30, [sp, #316] */
/* @0x1eb744 vstr s30, [sp, #312] */
/* @0x1eb748 vstr s30, [sp, #308] */
/* @0x1eb74c vstr s30, [sp, #360] */
/* @0x1eb750 str r3, [sp, #0x90] */
/* @0x1eb754 vcvt.f32.s32 s15, s15 */
/* @0x1eb758 vcvt.f32.s32 s13, s13 */
/* @0x1eb75c vdiv.f32 s12, s12, s14 */
/* @0x1eb760 vdiv.f32 s13, s13, s15 */
/* @0x1eb764 vstr s12, [sp, #352] */
/* @0x1eb768 vstr s13, [sp, #356] */
/* @0x1eb76c ldrsh r12, [r8, #4] */
/* @0x1eb770 ldrsh r3, [r8, #6] */
/* @0x1eb774 vstr s30, [sp, #296] */
/* @0x1eb778 sub r12, r12, #1 */
/* @0x1eb77c str lr, [sp, #0x12c] */
/* @0x1eb780 sub r3, r3, #1 */
/* @0x1eb784 str lr, [sp, #0x118] */
/* @0x1eb788 vmov s2, r12 */
/* @0x1eb78c vstr s30, [sp, #292] */
/* @0x1eb790 vmov s3, r3 */
/* @0x1eb794 vstr s30, [sp, #288] */
/* @0x1eb798 vcvt.f32.s32 s12, s2 */
/* @0x1eb79c vstr s30, [sp, #284] */
/* @0x1eb7a0 vstr s30, [sp, #276] */
/* @0x1eb7a4 vstr s30, [sp, #272] */
/* @0x1eb7a8 vstr s30, [sp, #268] */
/* @0x1eb7ac vstr s30, [sp, #264] */
/* @0x1eb7b0 vstr s30, [sp, #256] */
/* @0x1eb7b4 vstr s30, [sp, #252] */
/* @0x1eb7b8 vstr s30, [sp, #248] */
/* @0x1eb7bc vstr s30, [sp, #244] */
/* @0x1eb7c0 vcvt.f32.s32 s13, s3 */
/* @0x1eb7c4 vdiv.f32 s14, s12, s14 */
/* @0x1eb7c8 vdiv.f32 s15, s13, s15 */
/* @0x1eb7cc vstr s14, [sp, #240] */
/* @0x1eb7d0 vstr s15, [sp, #260] */
/* @0x1eb7d4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb7d8 mov r2, r4 */
/* @0x1eb7dc mov r0, r5 */
/* @0x1eb7e0 ldr r1, [sp, #0x2a4] */
/* @0x1eb7e4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb7e8 mov r2, r5 */
/* @0x1eb7ec add r1, r6, #12 */
/* @0x1eb7f0 add r0, sp, #176 */
/* @0x1eb7f4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb7f8 ldr r0, [pc, #0x28c] */
/* @0x1eb7fc mov r2, r7 */
/* @0x1eb800 mov r1, #0 */
/* @0x1eb804 mov r3, #1 */
/* @0x1eb808 ldr r5, [r10, r0] */
/* @0x1eb80c mov r0, r5 */
/* @0x1eb810 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb814 mov r0, r5 */
/* @0x1eb818 mov r1, #0 */
/* @0x1eb81c mov r2, #3 */
/* @0x1eb820 mov r3, #1 */
/* @0x1eb824 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb828 b 0x1eae00 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11f0> */
/* @0x1eb82c ldr r3, [r8, #0x54] */
/* @0x1eb830 ldr r4, [r3, r2, lsl #2] */
/* @0x1eb834 ldrsh r0, [r4, #20] */
/* @0x1eb838 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1eb83c cmp r0, #0 */
/* @0x1eb840 beq 0x1eba60 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e50> */
/* @0x1eb844 ldrsh r12, [r4, #6] */
/* @0x1eb848 vmov.f32 s15, #1.000000e+00 */
/* @0x1eb84c ldrsh lr, [r4, #18] */
/* @0x1eb850 add r5, sp, #432 */
/* @0x1eb854 ldrsh r10, [r4, #4] */
/* @0x1eb858 ldrsh r11, [r4, #16] */
/* @0x1eb85c vmov s8, r12 */
/* @0x1eb860 vmov s14, lr */
/* @0x1eb864 ldr r8, [sp, #0x44] */
/* @0x1eb868 vmov s7, r10 */
/* @0x1eb86c ldr r3, [pc, #0x214] */
/* @0x1eb870 vmov s13, r11 */
/* @0x1eb874 ldrsh r2, [r4, #20] */
/* @0x1eb878 ldrsh r9, [r4] */
/* @0x1eb87c mov r0, r5 */
/* @0x1eb880 ldr r3, [r8, r3] */
/* @0x1eb884 ldrsh r4, [r4, #2] */
/* @0x1eb888 vcvt.f32.s32 s7, s7 */
/* @0x1eb88c ldr r3, [r3, #0x4] */
/* @0x1eb890 vmov s10, r9 */
/* @0x1eb894 vmov s12, r4 */
/* @0x1eb898 add r4, sp, #368 */
/* @0x1eb89c ldr r3, [r3, r2, lsl #2] */
/* @0x1eb8a0 mov r1, r4 */
/* @0x1eb8a4 add r2, sp, #304 */
/* @0x1eb8a8 vcvt.f32.s32 s8, s8 */
/* @0x1eb8ac ldr r3, [r3] */
/* @0x1eb8b0 vldr s11, [r3, #4] */
/* @0x1eb8b4 vldr s9, [r3, #8] */
/* @0x1eb8b8 vstr s15, [sp, #428] */
/* @0x1eb8bc vstr s15, [sp, #408] */
/* @0x1eb8c0 vstr s15, [sp, #388] */
/* @0x1eb8c4 vstr s15, [sp, #368] */
/* @0x1eb8c8 vstr s15, [sp, #364] */
/* @0x1eb8cc vstr s15, [sp, #344] */
/* @0x1eb8d0 str r3, [sp, #0x90] */
/* @0x1eb8d4 vstr s30, [sp, #412] */
/* @0x1eb8d8 vstr s30, [sp, #404] */
/* @0x1eb8dc vstr s30, [sp, #400] */
/* @0x1eb8e0 vcvt.f32.s32 s13, s13 */
/* @0x1eb8e4 vstr s30, [sp, #396] */
/* @0x1eb8e8 vstr s30, [sp, #392] */
/* @0x1eb8ec vstr s30, [sp, #384] */
/* @0x1eb8f0 vstr s30, [sp, #380] */
/* @0x1eb8f4 vstr s30, [sp, #376] */
/* @0x1eb8f8 vstr s30, [sp, #372] */
/* @0x1eb8fc vstr s30, [sp, #424] */
/* @0x1eb900 vstr s30, [sp, #360] */
/* @0x1eb904 vstr s30, [sp, #356] */
/* @0x1eb908 vcvt.f32.s32 s14, s14 */
/* @0x1eb90c vdiv.f32 s13, s7, s13 */
/* @0x1eb910 vdiv.f32 s14, s8, s14 */
/* @0x1eb914 vcvt.f32.s32 s9, s9 */
/* @0x1eb918 vcvt.f32.s32 s11, s11 */
/* @0x1eb91c vdiv.f32 s11, s15, s11 */
/* @0x1eb920 vdiv.f32 s15, s15, s9 */
/* @0x1eb924 vcvt.f32.s32 s10, s10 */
/* @0x1eb928 vcvt.f32.s32 s12, s12 */
/* @0x1eb92c vdiv.f32 s10, s10, s13 */
/* @0x1eb930 vdiv.f32 s12, s12, s14 */
/* @0x1eb934 vstr s10, [sp, #416] */
/* @0x1eb938 vstr s30, [sp, #352] */
/* @0x1eb93c vstr s30, [sp, #348] */
/* @0x1eb940 vstr s30, [sp, #340] */
/* @0x1eb944 vstr s30, [sp, #336] */
/* @0x1eb948 vstr s30, [sp, #332] */
/* @0x1eb94c vstr s30, [sp, #328] */
/* @0x1eb950 vstr s30, [sp, #320] */
/* @0x1eb954 vstr s30, [sp, #316] */
/* @0x1eb958 vstr s30, [sp, #312] */
/* @0x1eb95c vstr s30, [sp, #308] */
/* @0x1eb960 vmul.f32 s13, s11, s13 */
/* @0x1eb964 vstr s12, [sp, #420] */
/* @0x1eb968 vmul.f32 s14, s15, s14 */
/* @0x1eb96c vstr s13, [sp, #304] */
/* @0x1eb970 vstr s14, [sp, #324] */
/* @0x1eb974 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb978 add r0, sp, #176 */
/* @0x1eb97c add r1, r6, #16 */
/* @0x1eb980 mov r2, r5 */
/* @0x1eb984 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb988 ldr r6, [r6, #0x4] */
/* @0x1eb98c ldr r0, [pc, #0xf8] */
/* @0x1eb990 bics r6, r6, #2 */
/* @0x1eb994 bne 0x1eba40 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e30> */
/* @0x1eb998 mov r1, r6 */
/* @0x1eb99c mov r2, #2 */
/* @0x1eb9a0 mov r3, r6 */
/* @0x1eb9a4 ldr r5, [r8, r0] */
/* @0x1eb9a8 b 0x1eade4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11d4> */
/* @0x1eb9ac add r1, r6, #12 */
/* @0x1eb9b0 ldr r6, [r6, #0x58] */
/* @0x1eb9b4 add r0, sp, #176 */
/* @0x1eb9b8 ldr r2, [sp, #0x2a4] */
/* @0x1eb9bc str r6, [sp, #0x90] */
/* @0x1eb9c0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb9c4 ldr r0, [pc, #0xc0] */
/* @0x1eb9c8 mov r2, r7 */
/* @0x1eb9cc ldr r5, [sp, #0x44] */
/* @0x1eb9d0 mov r1, #0 */
/* @0x1eb9d4 mov r3, #1 */
/* @0x1eb9d8 ldr r4, [r5, r0] */
/* @0x1eb9dc mov r0, r4 */
/* @0x1eb9e0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb9e4 mov r0, r4 */
/* @0x1eb9e8 mov r1, #0 */
/* @0x1eb9ec mov r2, #3 */
/* @0x1eb9f0 mov r3, #1 */
/* @0x1eb9f4 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb9f8 cmp r6, #0 */
/* @0x1eb9fc beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1eba00 add r4, sp, #368 */
/* @0x1eba04 b 0x1eae00 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11f0> */
/* @0x1eba08 ldr r6, [sp, #0x44] */
/* @0x1eba0c add r4, sp, #368 */
/* @0x1eba10 mov r1, #0 */
/* @0x1eba14 mov r2, #2 */
/* @0x1eba18 mov r3, #1 */
/* @0x1eba1c ldr r5, [r6, r0] */
/* @0x1eba20 mov r0, r5 */
/* @0x1eba24 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eba28 mov r0, r5 */
/* @0x1eba2c mov r2, r7 */
/* @0x1eba30 mov r1, #0 */
/* @0x1eba34 mov r3, #1 */
/* @0x1eba38 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eba3c b 0x1eae00 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11f0> */
/* @0x1eba40 ldr r10, [sp, #0x44] */
/* @0x1eba44 mov r1, #0 */
/* @0x1eba48 mov r2, #2 */
/* @0x1eba4c mov r3, #1 */
/* @0x1eba50 ldr r5, [r10, r0] */
/* @0x1eba54 b 0x1eba20 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e10> */
/* @0x1eba58 str r3, [sp, #0x54] */
/* @0x1eba5c b 0x1e9cec <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xdc> */
/* @0x1eba60 ldr r9, [sp, #0xa0] */
/* @0x1eba64 ldr r3, [r9, #0x1c] */
/* @0x1eba68 b 0x1ea428 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x818> */
/* @0x1eba6c ldr r6, [sp, #0xa0] */
/* @0x1eba70 ldr r3, [r6, #0x1c] */
/* @0x1eba74 b 0x1ea428 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x818> */
/* @0x1eba78 .word 0xfffff190 */
/* @0x1eba7c .word 0xffffbcd0 */
/* @0x1eba80 .word 0xffffbac4 */
/* @0x1eba84 .word 0xfffff194 */
/* @0x1eba88 .word 0xffffbccc */
/* @0x1eba8c .word 0xffffc0a8 */

/* ── FUNC 0x1eba90 · CSprite::DrawSWFObject(SWF_TimelineObject*, yyMatrix*, yyMatrix*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, bool) · size=1144 · insn=286 */
/* @0x1eba90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1eba94 vpush {d8} */
/* @0x1eba98 add lr, r1, #80 */
/* @0x1eba9c sub sp, sp, #708 */
/* @0x1ebaa0 mov r4, r2 */
/* @0x1ebaa4 mov r10, r1 */
/* @0x1ebaa8 mov r8, r0 */
/* @0x1ebaac str r3, [sp, #0x7c] */
/* @0x1ebab0 add r12, sp, #192 */
/* @0x1ebab4 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ebab8 add r9, sp, #256 */
/* @0x1ebabc ldrb r5, [sp, #0x300] */
/* @0x1ebac0 ldr r7, [pc, #0x424] */
/* @0x1ebac4 stm r12!, {r0, r1, r2, r3} */
/* @0x1ebac8 add r7, pc, r7 */
/* @0x1ebacc ldm lr!, {r0, r1, r2, r3} */
/* @0x1ebad0 str r5, [sp, #0x78] */
/* @0x1ebad4 stm r12!, {r0, r1, r2, r3} */
/* @0x1ebad8 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ebadc stm r12!, {r0, r1, r2, r3} */
/* @0x1ebae0 ldm lr, {r0, r1, r2, r3} */
/* @0x1ebae4 stm r12, {r0, r1, r2, r3} */
/* @0x1ebae8 mov r2, r4 */
/* @0x1ebaec mov r0, r9 */
/* @0x1ebaf0 add r1, sp, #192 */
/* @0x1ebaf4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ebaf8 cmp r5, #0 */
/* @0x1ebafc bne 0x1ebc7c <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x1ec> */
/* @0x1ebb00 vmov.f32 s16, #1.000000e+00 */
/* @0x1ebb04 add r5, sp, #512 */
/* @0x1ebb08 add r4, sp, #576 */
/* @0x1ebb0c add r6, sp, #640 */
/* @0x1ebb10 mov r2, r10 */
/* @0x1ebb14 mov r3, #0 */
/* @0x1ebb18 ldr r12, [r2, #0x10] */
/* @0x1ebb1c add r2, r2, #4 */
/* @0x1ebb20 ldr r0, [r2, #0x1c] */
/* @0x1ebb24 ldr r1, [r2, #0x2c] */
/* @0x1ebb28 str r12, [r5, r3] */
/* @0x1ebb2c str r0, [r4, r3] */
/* @0x1ebb30 str r1, [r6, r3] */
/* @0x1ebb34 add r3, r3, #4 */
/* @0x1ebb38 cmp r3, #16 */
/* @0x1ebb3c bne 0x1ebb18 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x88> */
/* @0x1ebb40 ldr r3, [r8, #0x54] */
/* @0x1ebb44 ldr r2, [pc, #0x3a4] */
/* @0x1ebb48 ldr r3, [r3] */
/* @0x1ebb4c ldr r2, [r7, r2] */
/* @0x1ebb50 ldrsh r0, [r3, #20] */
/* @0x1ebb54 ldr r11, [r2] */
/* @0x1ebb58 str r3, [sp, #0x70] */
/* @0x1ebb5c bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1ebb60 ldr r3, [sp, #0x70] */
/* @0x1ebb64 cmp r0, #0 */
/* @0x1ebb68 beq 0x1ebc68 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x1d8> */
/* @0x1ebb6c ldr r1, [pc, #0x380] */
/* @0x1ebb70 adds r11, r11, #0 */
/* @0x1ebb74 ldrsh r2, [r3, #20] */
/* @0x1ebb78 movne r11, #1 */
/* @0x1ebb7c str r11, [sp, #0x68] */
/* @0x1ebb80 ldrsh r11, [r3] */
/* @0x1ebb84 ldr r1, [r7, r1] */
/* @0x1ebb88 ldrsh r3, [r3, #2] */
/* @0x1ebb8c vmov s14, r11 */
/* @0x1ebb90 vmov s15, r3 */
/* @0x1ebb94 ldr r3, [r1, #0x4] */
/* @0x1ebb98 vcvt.f32.s32 s14, s14 */
/* @0x1ebb9c ldr r3, [r3, r2, lsl #2] */
/* @0x1ebba0 ldr r7, [r3] */
/* @0x1ebba4 vldr s11, [r7, #4] */
/* @0x1ebba8 vcvt.f32.s32 s15, s15 */
/* @0x1ebbac vcvt.f32.s32 s12, s11 */
/* @0x1ebbb0 vldr s11, [r7, #8] */
/* @0x1ebbb4 vcvt.f32.s32 s13, s11 */
/* @0x1ebbb8 vdiv.f32 s14, s14, s12 */
/* @0x1ebbbc vdiv.f32 s15, s15, s13 */
/* @0x1ebbc0 ldr r3, [r10] */
/* @0x1ebbc4 cmp r3, #0 */
/* @0x1ebbc8 beq 0x1ebc58 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x1c8> */
/* @0x1ebbcc ldr r11, [r8, #0x7c] */
/* @0x1ebbd0 add lr, sp, #264 */
/* @0x1ebbd4 ldr r10, [r10, #0x4] */
/* @0x1ebbd8 mov r12, sp */
/* @0x1ebbdc ldm lr!, {r0, r1, r2, r3} */
/* @0x1ebbe0 ldr r10, [r11, r10, lsl #2] */
/* @0x1ebbe4 vstr s16, [sp, #56] */
/* @0x1ebbe8 ldr r11, [sp, #0x68] */
/* @0x1ebbec vstr s14, [sp, #96] */
/* @0x1ebbf0 vstr s15, [sp, #100] */
/* @0x1ebbf4 str r5, [sp, #0x50] */
/* @0x1ebbf8 str r10, [sp, #0x6c] */
/* @0x1ebbfc ldr r10, [sp, #0x78] */
/* @0x1ebc00 str r11, [sp, #0x40] */
/* @0x1ebc04 ldr r11, [sp, #0x2f4] */
/* @0x1ebc08 str r10, [sp, #0x3c] */
/* @0x1ebc0c ldr r10, [sp, #0x7c] */
/* @0x1ebc10 str r11, [sp, #0x48] */
/* @0x1ebc14 str r4, [sp, #0x54] */
/* @0x1ebc18 str r10, [sp, #0x44] */
/* @0x1ebc1c ldr r10, [sp, #0x2fc] */
/* @0x1ebc20 str r6, [sp, #0x58] */
/* @0x1ebc24 str r7, [sp, #0x5c] */
/* @0x1ebc28 str r10, [sp, #0x4c] */
/* @0x1ebc2c stm r12!, {r0, r1, r2, r3} */
/* @0x1ebc30 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ebc34 stm r12!, {r0, r1, r2, r3} */
/* @0x1ebc38 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ebc3c stm r12!, {r0, r1, r2, r3} */
/* @0x1ebc40 ldm lr, {r0, r1} */
/* @0x1ebc44 ldm r9, {r2, r3} */
/* @0x1ebc48 stm r12, {r0, r1} */
/* @0x1ebc4c mov r0, r8 */
/* @0x1ebc50 ldr r1, [sp, #0x6c] */
/* @0x1ebc54 bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1ebc58 mov r0, #0 */
/* @0x1ebc5c add sp, sp, #708 */
/* @0x1ebc60 vpop {d8} */
/* @0x1ebc64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ebc68 vldr s15, [pc, #632] */
/* @0x1ebc6c mov r7, r0 */
/* @0x1ebc70 vmov.f32 s14, s15 */
/* @0x1ebc74 str r0, [sp, #0x68] */
/* @0x1ebc78 b 0x1ebbc0 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x130> */
/* @0x1ebc7c add r3, sp, #320 */
/* @0x1ebc80 mov r0, #2 */
/* @0x1ebc84 str r3, [sp, #0x70] */
/* @0x1ebc88 add r11, sp, #448 */
/* @0x1ebc8c mov r1, r3 */
/* @0x1ebc90 add r5, sp, #512 */
/* @0x1ebc94 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ebc98 add r2, sp, #384 */
/* @0x1ebc9c mov r0, #0 */
/* @0x1ebca0 str r2, [sp, #0x74] */
/* @0x1ebca4 mov r1, r2 */
/* @0x1ebca8 add r4, sp, #576 */
/* @0x1ebcac bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ebcb0 mov r1, r11 */
/* @0x1ebcb4 mov r0, #1 */
/* @0x1ebcb8 add r6, sp, #640 */
/* @0x1ebcbc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ebcc0 ldr r3, [sp, #0x70] */
/* @0x1ebcc4 ldr r2, [sp, #0x74] */
/* @0x1ebcc8 mov r0, r5 */
/* @0x1ebccc mov r1, r3 */
/* @0x1ebcd0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ebcd4 mov r2, r11 */
/* @0x1ebcd8 mov r1, r5 */
/* @0x1ebcdc mov r0, r4 */
/* @0x1ebce0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ebce4 mov r2, r4 */
/* @0x1ebce8 mov r0, r6 */
/* @0x1ebcec mov r1, r9 */
/* @0x1ebcf0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ebcf4 ldr r2, [pc, #0x1fc] */
/* @0x1ebcf8 ldr r3, [pc, #0x1fc] */
/* @0x1ebcfc vldr s15, [pc, #484] */
/* @0x1ebd00 vmov.f32 s12, s15 */
/* @0x1ebd04 mov r1, #1065353216 */
/* @0x1ebd08 ldr r12, [r7, r2] */
/* @0x1ebd0c vldr s2, [r12] */
/* @0x1ebd10 ldr r0, [r7, r3] */
/* @0x1ebd14 vldr s3, [r0] */
/* @0x1ebd18 str r1, [sp, #0x98] */
/* @0x1ebd1c add r2, sp, #152 */
/* @0x1ebd20 vcvt.f32.s32 s2, s2 */
/* @0x1ebd24 str r1, [sp, #0xa4] */
/* @0x1ebd28 ldr r1, [pc, #0x1d0] */
/* @0x1ebd2c add r3, sp, #168 */
/* @0x1ebd30 add r0, sp, #184 */
/* @0x1ebd34 vstr s15, [sp, #144] */
/* @0x1ebd38 vstr s15, [sp, #148] */
/* @0x1ebd3c vstr s15, [sp, #156] */
/* @0x1ebd40 vstr s15, [sp, #160] */
/* @0x1ebd44 ldr r1, [r7, r1] */
/* @0x1ebd48 vldr s10, [r1] */
/* @0x1ebd4c vcvt.f32.s32 s3, s3 */
/* @0x1ebd50 vmov.f32 s11, s15 */
/* @0x1ebd54 vldr s13, [sp, #668] */
/* @0x1ebd58 vldr s14, [sp, #656] */
/* @0x1ebd5c vldr s4, [sp, #652] */
/* @0x1ebd60 vldr s5, [sp, #640] */
/* @0x1ebd64 vmul.f32 s13, s12, s13 */
/* @0x1ebd68 vldr s7, [sp, #672] */
/* @0x1ebd6c vldr s6, [sp, #684] */
/* @0x1ebd70 vldr s8, [sp, #700] */
/* @0x1ebd74 vldr s15, [sp, #688] */
/* @0x1ebd78 vldr s9, [r1] */
/* @0x1ebd7c cmp r3, r0 */
/* @0x1ebd80 add r2, r2, #8 */
/* @0x1ebd84 add r3, r3, #8 */
/* @0x1ebd88 vmul.f32 s14, s12, s14 */
/* @0x1ebd8c vmla.f32 s13, s11, s4 */
/* @0x1ebd90 vmla.f32 s14, s11, s5 */
/* @0x1ebd94 vmla.f32 s13, s10, s6 */
/* @0x1ebd98 vmla.f32 s14, s10, s7 */
/* @0x1ebd9c vadd.f32 s13, s13, s8 */
/* @0x1ebda0 vadd.f32 s14, s14, s15 */
/* @0x1ebda4 vdiv.f32 s14, s14, s13 */
/* @0x1ebda8 vmul.f32 s14, s2, s14 */
/* @0x1ebdac vstr s14, [r3, #-8] */
/* @0x1ebdb0 vmov.f32 s10, s9 */
/* @0x1ebdb4 vldr s15, [sp, #660] */
/* @0x1ebdb8 vldr s7, [sp, #644] */
/* @0x1ebdbc vldr s8, [sp, #676] */
/* @0x1ebdc0 vldr s14, [sp, #692] */
/* @0x1ebdc4 vmul.f32 s15, s12, s15 */
/* @0x1ebdc8 vmla.f32 s15, s11, s7 */
/* @0x1ebdcc vmla.f32 s15, s9, s8 */
/* @0x1ebdd0 vadd.f32 s15, s15, s14 */
/* @0x1ebdd4 vdiv.f32 s13, s15, s13 */
/* @0x1ebdd8 vmul.f32 s13, s3, s13 */
/* @0x1ebddc vstr s13, [r3, #-4] */
/* @0x1ebde0 vldrne s11, [r2, #-8] */
/* @0x1ebde4 vldrne s12, [r2, #-4] */
/* @0x1ebde8 bne 0x1ebd54 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x2c4> */
/* @0x1ebdec vldr s12, [sp, #168] */
/* @0x1ebdf0 vldr s14, [sp, #176] */
/* @0x1ebdf4 vsub.f32 s14, s14, s12 */
/* @0x1ebdf8 vldr s13, [sp, #172] */
/* @0x1ebdfc vldr s15, [sp, #180] */
/* @0x1ebe00 vldr s10, [sp, #184] */
/* @0x1ebe04 vldr s11, [sp, #188] */
/* @0x1ebe08 vmul.f32 s16, s14, s14 */
/* @0x1ebe0c vstr s14, [sp, #128] */
/* @0x1ebe10 vsub.f32 s15, s15, s13 */
/* @0x1ebe14 vmla.f32 s16, s15, s15 */
/* @0x1ebe18 vstr s15, [sp, #132] */
/* @0x1ebe1c vsub.f32 s12, s10, s12 */
/* @0x1ebe20 vsub.f32 s13, s11, s13 */
/* @0x1ebe24 vstr s12, [sp, #136] */
/* @0x1ebe28 vcmpe.f32 s16, #0 */
/* @0x1ebe2c vstr s13, [sp, #140] */
/* @0x1ebe30 vmrs APSR_nzcv, fpscr */
/* @0x1ebe34 ble 0x1ebe4c <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3bc> */
/* @0x1ebe38 vsqrt.f32 s15, s16 */
/* @0x1ebe3c vcmp.f32 s15, s15 */
/* @0x1ebe40 vmrs APSR_nzcv, fpscr */
/* @0x1ebe44 bne 0x1ebed8 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x448> */
/* @0x1ebe48 vmov.f32 s16, s15 */
/* @0x1ebe4c vldr s15, [sp, #136] */
/* @0x1ebe50 vldr s14, [sp, #140] */
/* @0x1ebe54 vldr s13, [pc, #140] */
/* @0x1ebe58 vmul.f32 s15, s15, s15 */
/* @0x1ebe5c vmla.f32 s15, s14, s14 */
/* @0x1ebe60 vcmpe.f32 s16, #0 */
/* @0x1ebe64 vmrs APSR_nzcv, fpscr */
/* @0x1ebe68 vcmpe.f32 s15, s13 */
/* @0x1ebe6c vmovle.f32 s16, s13 */
/* @0x1ebe70 vmrs APSR_nzcv, fpscr */
/* @0x1ebe74 ble 0x1ebe8c <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3fc> */
/* @0x1ebe78 vsqrt.f32 s14, s15 */
/* @0x1ebe7c vcmp.f32 s14, s14 */
/* @0x1ebe80 vmrs APSR_nzcv, fpscr */
/* @0x1ebe84 bne 0x1ebec8 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x438> */
/* @0x1ebe88 vmov.f32 s15, s14 */
/* @0x1ebe8c ldr r3, [pc, #0x70] */
/* @0x1ebe90 vmov.f32 s14, #5.000000e-01 */
/* @0x1ebe94 ldr r3, [r7, r3] */
/* @0x1ebe98 vcmp.f32 s15, s16 */
/* @0x1ebe9c vmrs APSR_nzcv, fpscr */
/* @0x1ebea0 vmovgt.f32 s16, s15 */
/* @0x1ebea4 vmul.f32 s16, s16, s14 */
/* @0x1ebea8 vcmpe.f32 s16, #0 */
/* @0x1ebeac vmrs APSR_nzcv, fpscr */
/* @0x1ebeb0 vmovgt.f32 s15, #1.000000e+00 */
/* @0x1ebeb4 vdivgt.f32 s16, s15, s16 */
/* @0x1ebeb8 vldr s15, [r3] */
/* @0x1ebebc vmovle.f32 s16, #1.000000e+00 */
/* @0x1ebec0 vmul.f32 s16, s16, s15 */
/* @0x1ebec4 b 0x1ebb10 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x80> */
/* @0x1ebec8 vmov r0, s15 */
/* @0x1ebecc bl 0xb6700 <sqrtf@plt> */
/* @0x1ebed0 vmov s14, r0 */
/* @0x1ebed4 b 0x1ebe88 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3f8> */
/* @0x1ebed8 vmov r0, s16 */
/* @0x1ebedc bl 0xb6700 <sqrtf@plt> */
/* @0x1ebee0 vmov s15, r0 */
/* @0x1ebee4 b 0x1ebe48 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3b8> */
/* @0x1ebee8 andeq r0, r0, r0 */
/* @0x1ebeec eoreq r6, r0, r8, lsl #3 */
/* @0x1ebef0 .word 0xffffe828 */
/* @0x1ebef4 .word 0xffffbccc */
/* @0x1ebef8 .word 0xffffe4f4 */
/* @0x1ebefc .word 0xffffe4f8 */
/* @0x1ebf00 .word 0xffffbcd0 */
/* @0x1ebf04 .word 0xffffc968 */

/* ── FUNC 0x1ebf08 · CSprite::DrawSWF(int, float, float, float, float, float, float, float, unsigned int, float) · size=2072 · insn=518 */
/* @0x1ebf08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ebf0c vpush {d8} */
/* @0x1ebf10 add r11, sp, #40 */
/* @0x1ebf14 ldr r12, [pc, #0x3a4] */
/* @0x1ebf18 sub sp, sp, #668 */
/* @0x1ebf1c str r0, [r11, #-0x264] */
/* @0x1ebf20 add r12, pc, r12 */
/* @0x1ebf24 str r12, [r11, #-0x28c] */
/* @0x1ebf28 ldr r12, [r11, #-0x264] */
/* @0x1ebf2c mov r4, r1 */
/* @0x1ebf30 ldr r0, [pc, #0x38c] */
/* @0x1ebf34 vmov s16, r2 */
/* @0x1ebf38 ldr r7, [r11, #0x18] */
/* @0x1ebf3c ldr r1, [r12, #0x7c] */
/* @0x1ebf40 ldr r12, [r11, #-0x28c] */
/* @0x1ebf44 cmp r1, #0 */
/* @0x1ebf48 ldr r0, [r12, r0] */
/* @0x1ebf4c ldr r1, [r0] */
/* @0x1ebf50 str r0, [r11, #-0x290] */
/* @0x1ebf54 str r1, [r11, #-0x30] */
/* @0x1ebf58 beq 0x1ec6ec <_ZN7CSprite7DrawSWFEifffffffjf+0x7e4> */
/* @0x1ebf5c ldr r12, [r11, #-0x264] */
/* @0x1ebf60 ldr r1, [r12, #0x84] */
/* @0x1ebf64 cmp r1, #0 */
/* @0x1ebf68 beq 0x1ec6ec <_ZN7CSprite7DrawSWFEifffffffjf+0x7e4> */
/* @0x1ebf6c ldr r12, [r11, #-0x28c] */
/* @0x1ebf70 mov r1, #0 */
/* @0x1ebf74 ldr r0, [pc, #0x34c] */
/* @0x1ebf78 mov r2, #2 */
/* @0x1ebf7c ldr r5, [r12, r0] */
/* @0x1ebf80 str r3, [r11, #-0x2ac] */
/* @0x1ebf84 mov r0, r5 */
/* @0x1ebf88 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ebf8c mov r2, #3 */
/* @0x1ebf90 mov r1, #0 */
/* @0x1ebf94 str r0, [r11, #-0x294] */
/* @0x1ebf98 mov r0, r5 */
/* @0x1ebf9c bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ebfa0 mov r1, #30 */
/* @0x1ebfa4 str r0, [r11, #-0x298] */
/* @0x1ebfa8 mov r0, r5 */
/* @0x1ebfac bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfb0 mov r1, #25 */
/* @0x1ebfb4 str r0, [r11, #-0x29c] */
/* @0x1ebfb8 mov r0, r5 */
/* @0x1ebfbc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfc0 mov r1, #29 */
/* @0x1ebfc4 str r0, [r11, #-0x2a0] */
/* @0x1ebfc8 mov r0, r5 */
/* @0x1ebfcc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfd0 mov r1, #28 */
/* @0x1ebfd4 str r0, [r11, #-0x2a4] */
/* @0x1ebfd8 mov r0, r5 */
/* @0x1ebfdc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebfe0 mov r1, #24 */
/* @0x1ebfe4 str r0, [r11, #-0x2a8] */
/* @0x1ebfe8 mov r0, r5 */
/* @0x1ebfec bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ebff0 mov r1, #4 */
/* @0x1ebff4 str r0, [r11, #-0x280] */
/* @0x1ebff8 mov r0, r5 */
/* @0x1ebffc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ec000 ldr r12, [r11, #-0x264] */
/* @0x1ec004 ldr r2, [r12, #0x84] */
/* @0x1ec008 ldr r6, [r2, #0x18] */
/* @0x1ec00c mov r1, r6 */
/* @0x1ec010 str r0, [r11, #-0x284] */
/* @0x1ec014 mov r0, r4 */
/* @0x1ec018 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ec01c vldr s15, [pc, #664] */
/* @0x1ec020 vldr s12, [r11, #28] */
/* @0x1ec024 vmul.f32 s15, s12, s15 */
/* @0x1ec028 ldr r3, [r11, #-0x2ac] */
/* @0x1ec02c vcvt.s32.f32 s15, s15 */
/* @0x1ec030 vmov r12, s15 */
/* @0x1ec034 subs r4, r1, #0 */
/* @0x1ec038 addlt r4, r4, r6 */
/* @0x1ec03c cmp r12, #255 */
/* @0x1ec040 movgt r12, #-16777216 */
/* @0x1ec044 ble 0x1ec70c <_ZN7CSprite7DrawSWFEifffffffjf+0x804> */
/* @0x1ec048 bic lr, r7, #-16777216 */
/* @0x1ec04c sub r6, r11, #496 */
/* @0x1ec050 orr r12, r12, lr */
/* @0x1ec054 ldr r1, [r11, #0x14] */
/* @0x1ec058 mov r0, r6 */
/* @0x1ec05c mov r9, #0 */
/* @0x1ec060 mov r10, #1065353216 */
/* @0x1ec064 vldr s13, [r11, #4] */
/* @0x1ec068 vldr s14, [r11, #8] */
/* @0x1ec06c uxtb r7, r7 */
/* @0x1ec070 vstr s13, [r11, #-512] */
/* @0x1ec074 vstr s14, [r11, #-508] */
/* @0x1ec078 str r12, [r11, #-0x258] */
/* @0x1ec07c mov r8, #0 */
/* @0x1ec080 str lr, [r11, #-0x254] */
/* @0x1ec084 add r4, r4, r4, lsl #1 */
/* @0x1ec088 str r7, [r11, #-0x240] */
/* @0x1ec08c uxtb r7, r12 */
/* @0x1ec090 str r3, [r11, #-0x2ac] */
/* @0x1ec094 str r7, [r11, #-0x250] */
/* @0x1ec098 ubfx r7, r12, #0x8, #0x8 */
/* @0x1ec09c str r10, [r11, #-0x1f4] */
/* @0x1ec0a0 str r7, [r11, #-0x24c] */
/* @0x1ec0a4 ubfx r7, r12, #0x10, #0x8 */
/* @0x1ec0a8 str r10, [r11, #-0x208] */
/* @0x1ec0ac lsr r12, r12, #24 */
/* @0x1ec0b0 str r7, [r11, #-0x248] */
/* @0x1ec0b4 sub r7, r11, #304 */
/* @0x1ec0b8 str r12, [r11, #-0x244] */
/* @0x1ec0bc ubfx r12, lr, #0x8, #0x8 */
/* @0x1ec0c0 str r10, [r11, #-0x21c] */
/* @0x1ec0c4 lsr lr, lr, #16 */
/* @0x1ec0c8 str r12, [r11, #-0x23c] */
/* @0x1ec0cc str lr, [r11, #-0x238] */
/* @0x1ec0d0 str r10, [r11, #-0x230] */
/* @0x1ec0d4 str r8, [r11, #-0x234] */
/* @0x1ec0d8 str r9, [r11, #-0x204] */
/* @0x1ec0dc str r9, [r11, #-0x20c] */
/* @0x1ec0e0 str r9, [r11, #-0x210] */
/* @0x1ec0e4 str r9, [r11, #-0x214] */
/* @0x1ec0e8 str r9, [r11, #-0x218] */
/* @0x1ec0ec str r9, [r11, #-0x220] */
/* @0x1ec0f0 str r9, [r11, #-0x224] */
/* @0x1ec0f4 str r9, [r11, #-0x228] */
/* @0x1ec0f8 str r9, [r11, #-0x22c] */
/* @0x1ec0fc str r9, [r11, #-0x1f8] */
/* @0x1ec100 bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* @0x1ec104 ldr r3, [r11, #-0x2ac] */
/* @0x1ec108 vneg.f32 s14, s16 */
/* @0x1ec10c ldr r12, [r11, #-0x28c] */
/* @0x1ec110 mov r0, r7 */
/* @0x1ec114 ldr r2, [pc, #0x1b0] */
/* @0x1ec118 sub r1, r11, #432 */
/* @0x1ec11c vmov s12, r3 */
/* @0x1ec120 vneg.f32 s13, s12 */
/* @0x1ec124 ldr r2, [r12, r2] */
/* @0x1ec128 vldr s15, [r2] */
/* @0x1ec12c vldr s12, [r11, #12] */
/* @0x1ec130 str r10, [r11, #-0x174] */
/* @0x1ec134 sub r2, r11, #368 */
/* @0x1ec138 str r10, [r11, #-0x188] */
/* @0x1ec13c sub r12, r11, #176 */
/* @0x1ec140 vdiv.f32 s14, s14, s15 */
/* @0x1ec144 str r10, [r11, #-0x19c] */
/* @0x1ec148 str r10, [r11, #-0x1b0] */
/* @0x1ec14c str r9, [r11, #-0x184] */
/* @0x1ec150 str r9, [r11, #-0x18c] */
/* @0x1ec154 str r9, [r11, #-0x190] */
/* @0x1ec158 str r9, [r11, #-0x194] */
/* @0x1ec15c str r9, [r11, #-0x198] */
/* @0x1ec160 str r9, [r11, #-0x1a0] */
/* @0x1ec164 str r9, [r11, #-0x1a4] */
/* @0x1ec168 str r9, [r11, #-0x1a8] */
/* @0x1ec16c str r9, [r11, #-0x1ac] */
/* @0x1ec170 str r9, [r11, #-0x178] */
/* @0x1ec174 str r10, [r11, #-0x134] */
/* @0x1ec178 str r10, [r11, #-0x148] */
/* @0x1ec17c str r9, [r11, #-0x138] */
/* @0x1ec180 str r9, [r11, #-0x13c] */
/* @0x1ec184 str r9, [r11, #-0x140] */
/* @0x1ec188 str r9, [r11, #-0x144] */
/* @0x1ec18c str r9, [r11, #-0x14c] */
/* @0x1ec190 str r9, [r11, #-0x150] */
/* @0x1ec194 str r9, [r11, #-0x154] */
/* @0x1ec198 str r9, [r11, #-0x158] */
/* @0x1ec19c str r9, [r11, #-0x160] */
/* @0x1ec1a0 str r9, [r11, #-0x164] */
/* @0x1ec1a4 str r9, [r11, #-0x168] */
/* @0x1ec1a8 str r9, [r11, #-0x16c] */
/* @0x1ec1ac vdiv.f32 s13, s13, s15 */
/* @0x1ec1b0 vstr s14, [r11, #-384] */
/* @0x1ec1b4 vmul.f32 s14, s15, s12 */
/* @0x1ec1b8 vstr s13, [r11, #-380] */
/* @0x1ec1bc vldr s13, [r11, #16] */
/* @0x1ec1c0 str r12, [r11, #-0x268] */
/* @0x1ec1c4 vmul.f32 s15, s15, s13 */
/* @0x1ec1c8 vstr s14, [r11, #-368] */
/* @0x1ec1cc vstr s15, [r11, #-348] */
/* @0x1ec1d0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ec1d4 mov r2, r6 */
/* @0x1ec1d8 sub r6, r11, #240 */
/* @0x1ec1dc mov r1, r7 */
/* @0x1ec1e0 mov r0, r6 */
/* @0x1ec1e4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ec1e8 mov r1, r6 */
/* @0x1ec1ec sub r0, r11, #176 */
/* @0x1ec1f0 sub r2, r11, #560 */
/* @0x1ec1f4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ec1f8 ldr r12, [r11, #-0x264] */
/* @0x1ec1fc mov r1, #939524096 */
/* @0x1ec200 mov r0, #1056964608 */
/* @0x1ec204 str r10, [r11, #-0x34] */
/* @0x1ec208 lsl r2, r4, #3 */
/* @0x1ec20c ldr r3, [r12, #0x84] */
/* @0x1ec210 str r10, [r11, #-0x48] */
/* @0x1ec214 str r9, [r11, #-0x38] */
/* @0x1ec218 str r9, [r11, #-0x44] */
/* @0x1ec21c str r9, [r11, #-0x4c] */
/* @0x1ec220 str r9, [r11, #-0x50] */
/* @0x1ec224 str r9, [r11, #-0x54] */
/* @0x1ec228 str r9, [r11, #-0x58] */
/* @0x1ec22c str r0, [r11, #-0x40] */
/* @0x1ec230 str r0, [r11, #-0x3c] */
/* @0x1ec234 str r1, [r11, #-0x5c] */
/* @0x1ec238 str r9, [r11, #-0x60] */
/* @0x1ec23c str r9, [r11, #-0x64] */
/* @0x1ec240 str r9, [r11, #-0x68] */
/* @0x1ec244 str r9, [r11, #-0x6c] */
/* @0x1ec248 str r1, [r11, #-0x70] */
/* @0x1ec24c ldr r1, [r3] */
/* @0x1ec250 add r12, r1, r2 */
/* @0x1ec254 str r12, [r11, #-0x288] */
/* @0x1ec258 ldr r3, [r12, #0x14] */
/* @0x1ec25c cmp r3, r8 */
/* @0x1ec260 lsl r3, r3, #2 */
/* @0x1ec264 add r3, r3, #14 */
/* @0x1ec268 bic r3, r3, #7 */
/* @0x1ec26c sub sp, sp, r3 */
/* @0x1ec270 add r7, sp, #24 */
/* @0x1ec274 ble 0x1ec664 <_ZN7CSprite7DrawSWFEifffffffjf+0x75c> */
/* @0x1ec278 mov r12, #1 */
/* @0x1ec27c ldr r10, [r1, r2] */
/* @0x1ec280 sub r3, r11, #112 */
/* @0x1ec284 sub r0, r11, #600 */
/* @0x1ec288 str r3, [r11, #-0x26c] */
/* @0x1ec28c sub r1, r11, #592 */
/* @0x1ec290 sub r2, r11, #596 */
/* @0x1ec294 sub r3, r11, #576 */
/* @0x1ec298 str r8, [r11, #-0x260] */
/* @0x1ec29c str r0, [r11, #-0x270] */
/* @0x1ec2a0 str r1, [r11, #-0x274] */
/* @0x1ec2a4 str r2, [r11, #-0x278] */
/* @0x1ec2a8 str r3, [r11, #-0x27c] */
/* @0x1ec2ac ldr r3, [r10, #0xc] */
/* @0x1ec2b0 cmp r3, #0 */
/* @0x1ec2b4 ble 0x1ec574 <_ZN7CSprite7DrawSWFEifffffffjf+0x66c> */
/* @0x1ec2b8 b 0x1ec2d4 <_ZN7CSprite7DrawSWFEifffffffjf+0x3cc> */
/* @0x1ec2bc cmnmi pc, #0 */
/* @0x1ec2c0 eoreq r5, r0, r0, lsr sp */
/* @0x1ec2c4 .word 0xffffbd00 */
/* @0x1ec2c8 .word 0xffffc0a8 */
/* @0x1ec2cc .word 0xfffff184 */
/* @0x1ec2d0 .word 0xffffc978 */
/* @0x1ec2d4 mov r0, r5 */
/* @0x1ec2d8 mov r1, #25 */
/* @0x1ec2dc mov r2, #1 */
/* @0x1ec2e0 str r10, [r7, r8, lsl #2] */
/* @0x1ec2e4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec2e8 mov r0, r5 */
/* @0x1ec2ec mov r1, #29 */
/* @0x1ec2f0 mov r2, #8 */
/* @0x1ec2f4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec2f8 mov r0, r5 */
/* @0x1ec2fc mov r1, #28 */
/* @0x1ec300 mov r2, #7 */
/* @0x1ec304 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec308 mov r0, r5 */
/* @0x1ec30c mov r1, #24 */
/* @0x1ec310 mov r2, #0 */
/* @0x1ec314 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec318 mov r2, #0 */
/* @0x1ec31c mov r0, r5 */
/* @0x1ec320 mov r1, #4 */
/* @0x1ec324 str r2, [r11, #-0x2ac] */
/* @0x1ec328 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec32c ldr r12, [r11, #-0x2ac] */
/* @0x1ec330 add r8, r8, #1 */
/* @0x1ec334 mov lr, r12 */
/* @0x1ec338 sub r1, r11, #600 */
/* @0x1ec33c sub r2, r11, #592 */
/* @0x1ec340 str r1, [sp] */
/* @0x1ec344 sub r3, r11, #596 */
/* @0x1ec348 str r2, [sp, #0x4] */
/* @0x1ec34c mov r1, r10 */
/* @0x1ec350 str r3, [sp, #0x8] */
/* @0x1ec354 sub r2, r11, #176 */
/* @0x1ec358 sub r3, r11, #576 */
/* @0x1ec35c ldr r0, [r11, #-0x264] */
/* @0x1ec360 str r3, [sp, #0xc] */
/* @0x1ec364 sub r3, r11, #112 */
/* @0x1ec368 str lr, [sp, #0x10] */
/* @0x1ec36c str r12, [r11, #-0x2ac] */
/* @0x1ec370 bl 0x1eba90 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b> */
/* @0x1ec374 ldr r3, [r10, #0xc] */
/* @0x1ec378 ldr r12, [r11, #-0x2ac] */
/* @0x1ec37c cmp r3, #0 */
/* @0x1ec380 ble 0x1ec3e0 <_ZN7CSprite7DrawSWFEifffffffjf+0x4d8> */
/* @0x1ec384 mov r0, r5 */
/* @0x1ec388 mov r1, #30 */
/* @0x1ec38c mov r2, r8 */
/* @0x1ec390 mov r12, #1 */
/* @0x1ec394 str r12, [r11, #-0x2ac] */
/* @0x1ec398 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec39c mov r0, r5 */
/* @0x1ec3a0 mov r1, #29 */
/* @0x1ec3a4 mov r2, #3 */
/* @0x1ec3a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3ac mov r0, r5 */
/* @0x1ec3b0 mov r1, #28 */
/* @0x1ec3b4 mov r2, #1 */
/* @0x1ec3b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3bc mov r0, r5 */
/* @0x1ec3c0 mov r1, #24 */
/* @0x1ec3c4 ldr r2, [r11, #-0x280] */
/* @0x1ec3c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3cc mov r0, r5 */
/* @0x1ec3d0 mov r1, #4 */
/* @0x1ec3d4 ldr r2, [r11, #-0x284] */
/* @0x1ec3d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec3dc ldr r12, [r11, #-0x2ac] */
/* @0x1ec3e0 ldr r0, [r11, #-0x288] */
/* @0x1ec3e4 ldr r1, [r11, #-0x260] */
/* @0x1ec3e8 ldr r3, [r0, #0x14] */
/* @0x1ec3ec add r1, r1, #1 */
/* @0x1ec3f0 str r1, [r11, #-0x260] */
/* @0x1ec3f4 cmp r3, r1 */
/* @0x1ec3f8 ble 0x1ec5c0 <_ZN7CSprite7DrawSWFEifffffffjf+0x6b8> */
/* @0x1ec3fc ldr r0, [r11, #-0x260] */
/* @0x1ec400 cmp r8, #0 */
/* @0x1ec404 ldr r1, [r11, #-0x288] */
/* @0x1ec408 add r10, r0, r0, lsl #3 */
/* @0x1ec40c ldr r3, [r1] */
/* @0x1ec410 add r10, r3, r10, lsl #4 */
/* @0x1ec414 beq 0x1ec2ac <_ZN7CSprite7DrawSWFEifffffffjf+0x3a4> */
/* @0x1ec418 ldr r1, [r10, #0x8] */
/* @0x1ec41c mov r4, #0 */
/* @0x1ec420 mov r6, r4 */
/* @0x1ec424 mov r9, r8 */
/* @0x1ec428 mov r2, r12 */
/* @0x1ec42c ldr r8, [r7, r6] */
/* @0x1ec430 add r12, r7, r6 */
/* @0x1ec434 ldr r3, [r8, #0xc] */
/* @0x1ec438 cmp r3, r1 */
/* @0x1ec43c blt 0x1ec454 <_ZN7CSprite7DrawSWFEifffffffjf+0x54c> */
/* @0x1ec440 add r4, r4, #1 */
/* @0x1ec444 cmp r4, r9 */
/* @0x1ec448 bge 0x1ec560 <_ZN7CSprite7DrawSWFEifffffffjf+0x658> */
/* @0x1ec44c lsl r6, r4, #2 */
/* @0x1ec450 b 0x1ec42c <_ZN7CSprite7DrawSWFEifffffffjf+0x524> */
/* @0x1ec454 mov r0, r5 */
/* @0x1ec458 mov r1, #29 */
/* @0x1ec45c mov r2, #8 */
/* @0x1ec460 str r12, [r11, #-0x2ac] */
/* @0x1ec464 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec468 mov r0, r5 */
/* @0x1ec46c mov r1, #28 */
/* @0x1ec470 mov r2, #8 */
/* @0x1ec474 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec478 mov r0, r5 */
/* @0x1ec47c mov r1, #24 */
/* @0x1ec480 mov r2, #0 */
/* @0x1ec484 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec488 sub r9, r9, #1 */
/* @0x1ec48c mov r0, r5 */
/* @0x1ec490 mov r1, #4 */
/* @0x1ec494 mov r2, #0 */
/* @0x1ec498 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec49c sub r2, r11, #600 */
/* @0x1ec4a0 sub r3, r11, #592 */
/* @0x1ec4a4 str r2, [sp] */
/* @0x1ec4a8 str r3, [sp, #0x4] */
/* @0x1ec4ac mov r1, r8 */
/* @0x1ec4b0 sub r0, r11, #596 */
/* @0x1ec4b4 sub r2, r11, #576 */
/* @0x1ec4b8 str r0, [sp, #0x8] */
/* @0x1ec4bc mov r3, #0 */
/* @0x1ec4c0 str r2, [sp, #0xc] */
/* @0x1ec4c4 sub r2, r11, #176 */
/* @0x1ec4c8 str r3, [sp, #0x10] */
/* @0x1ec4cc sub r3, r11, #112 */
/* @0x1ec4d0 ldr r0, [r11, #-0x264] */
/* @0x1ec4d4 bl 0x1eba90 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b> */
/* @0x1ec4d8 mov r2, r9 */
/* @0x1ec4dc mov r0, r5 */
/* @0x1ec4e0 mov r1, #30 */
/* @0x1ec4e4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec4e8 mov r0, r5 */
/* @0x1ec4ec mov r1, #29 */
/* @0x1ec4f0 mov r2, #3 */
/* @0x1ec4f4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec4f8 mov r0, r5 */
/* @0x1ec4fc mov r1, #28 */
/* @0x1ec500 mov r2, #1 */
/* @0x1ec504 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec508 mov r0, r5 */
/* @0x1ec50c mov r1, #24 */
/* @0x1ec510 ldr r2, [r11, #-0x280] */
/* @0x1ec514 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec518 mov r0, r5 */
/* @0x1ec51c mov r1, #4 */
/* @0x1ec520 ldr r2, [r11, #-0x284] */
/* @0x1ec524 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec528 cmp r9, r4 */
/* @0x1ec52c ldr r12, [r11, #-0x2ac] */
/* @0x1ec530 ble 0x1ec5a4 <_ZN7CSprite7DrawSWFEifffffffjf+0x69c> */
/* @0x1ec534 mov r3, r12 */
/* @0x1ec538 mov r8, r4 */
/* @0x1ec53c add r8, r8, #1 */
/* @0x1ec540 ldr r2, [r3, #0x4] */
/* @0x1ec544 cmp r8, r9 */
/* @0x1ec548 str r2, [r3], #4 */
/* @0x1ec54c bne 0x1ec53c <_ZN7CSprite7DrawSWFEifffffffjf+0x634> */
/* @0x1ec550 mov r9, r8 */
/* @0x1ec554 ldr r1, [r10, #0x8] */
/* @0x1ec558 mov r2, #1 */
/* @0x1ec55c b 0x1ec42c <_ZN7CSprite7DrawSWFEifffffffjf+0x524> */
/* @0x1ec560 ldr r3, [r10, #0xc] */
/* @0x1ec564 mov r8, r9 */
/* @0x1ec568 mov r12, r2 */
/* @0x1ec56c cmp r3, #0 */
/* @0x1ec570 bgt 0x1ec2d4 <_ZN7CSprite7DrawSWFEifffffffjf+0x3cc> */
/* @0x1ec574 cmp r8, #0 */
/* @0x1ec578 bne 0x1ec5b0 <_ZN7CSprite7DrawSWFEifffffffjf+0x6a8> */
/* @0x1ec57c mov r0, r5 */
/* @0x1ec580 mov r1, #25 */
/* @0x1ec584 mov r2, r8 */
/* @0x1ec588 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec58c ldr r3, [pc, #-0x2c4] */
/* @0x1ec590 mov r12, #1 */
/* @0x1ec594 ldr r0, [r11, #-0x28c] */
/* @0x1ec598 ldr r3, [r0, r3] */
/* @0x1ec59c ldrb lr, [r3] */
/* @0x1ec5a0 b 0x1ec338 <_ZN7CSprite7DrawSWFEifffffffjf+0x430> */
/* @0x1ec5a4 mov r8, r9 */
/* @0x1ec5a8 mov r12, #1 */
/* @0x1ec5ac b 0x1ec2ac <_ZN7CSprite7DrawSWFEifffffffjf+0x3a4> */
/* @0x1ec5b0 cmp r12, #0 */
/* @0x1ec5b4 moveq lr, r12 */
/* @0x1ec5b8 bne 0x1ec58c <_ZN7CSprite7DrawSWFEifffffffjf+0x684> */
/* @0x1ec5bc b 0x1ec338 <_ZN7CSprite7DrawSWFEifffffffjf+0x430> */
/* @0x1ec5c0 cmp r8, #0 */
/* @0x1ec5c4 beq 0x1ec664 <_ZN7CSprite7DrawSWFEifffffffjf+0x75c> */
/* @0x1ec5c8 mov r0, r5 */
/* @0x1ec5cc mov r1, #29 */
/* @0x1ec5d0 mov r2, #8 */
/* @0x1ec5d4 sub r7, r7, #4 */
/* @0x1ec5d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec5dc mov r0, r5 */
/* @0x1ec5e0 mov r1, #28 */
/* @0x1ec5e4 mov r2, #8 */
/* @0x1ec5e8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec5ec mov r0, r5 */
/* @0x1ec5f0 mov r1, #24 */
/* @0x1ec5f4 mov r2, #0 */
/* @0x1ec5f8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec5fc mov r0, r5 */
/* @0x1ec600 mov r1, #4 */
/* @0x1ec604 mov r2, #0 */
/* @0x1ec608 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec60c mov r6, #0 */
/* @0x1ec610 str r5, [r11, #-0x260] */
/* @0x1ec614 sub r9, r11, #596 */
/* @0x1ec618 mov r5, r7 */
/* @0x1ec61c sub r10, r11, #592 */
/* @0x1ec620 sub r7, r11, #576 */
/* @0x1ec624 mov r4, r6 */
/* @0x1ec628 ldr r1, [r5, #0x4]! */
/* @0x1ec62c sub r2, r11, #600 */
/* @0x1ec630 add r6, r6, #1 */
/* @0x1ec634 str r2, [sp] */
/* @0x1ec638 ldr r0, [r11, #-0x264] */
/* @0x1ec63c sub r2, r11, #176 */
/* @0x1ec640 str r10, [sp, #0x4] */
/* @0x1ec644 sub r3, r11, #112 */
/* @0x1ec648 str r9, [sp, #0x8] */
/* @0x1ec64c str r7, [sp, #0xc] */
/* @0x1ec650 str r4, [sp, #0x10] */
/* @0x1ec654 bl 0x1eba90 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b> */
/* @0x1ec658 cmp r6, r8 */
/* @0x1ec65c blt 0x1ec628 <_ZN7CSprite7DrawSWFEifffffffjf+0x720> */
/* @0x1ec660 ldr r5, [r11, #-0x260] */
/* @0x1ec664 ldr r3, [r11, #-0x294] */
/* @0x1ec668 mov r0, r5 */
/* @0x1ec66c mov r1, #0 */
/* @0x1ec670 mov r2, #2 */
/* @0x1ec674 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ec678 ldr r3, [r11, #-0x298] */
/* @0x1ec67c mov r0, r5 */
/* @0x1ec680 mov r1, #0 */
/* @0x1ec684 mov r2, #3 */
/* @0x1ec688 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ec68c mov r0, r5 */
/* @0x1ec690 ldr r2, [r11, #-0x29c] */
/* @0x1ec694 mov r1, #30 */
/* @0x1ec698 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec69c mov r0, r5 */
/* @0x1ec6a0 ldr r2, [r11, #-0x2a0] */
/* @0x1ec6a4 mov r1, #25 */
/* @0x1ec6a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6ac mov r0, r5 */
/* @0x1ec6b0 ldr r2, [r11, #-0x2a4] */
/* @0x1ec6b4 mov r1, #29 */
/* @0x1ec6b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6bc mov r0, r5 */
/* @0x1ec6c0 ldr r2, [r11, #-0x2a8] */
/* @0x1ec6c4 mov r1, #28 */
/* @0x1ec6c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6cc mov r0, r5 */
/* @0x1ec6d0 ldr r2, [r11, #-0x280] */
/* @0x1ec6d4 mov r1, #24 */
/* @0x1ec6d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6dc mov r0, r5 */
/* @0x1ec6e0 ldr r2, [r11, #-0x284] */
/* @0x1ec6e4 mov r1, #4 */
/* @0x1ec6e8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ec6ec ldr r12, [r11, #-0x290] */
/* @0x1ec6f0 ldr r2, [r11, #-0x30] */
/* @0x1ec6f4 ldr r3, [r12] */
/* @0x1ec6f8 cmp r2, r3 */
/* @0x1ec6fc bne 0x1ec71c <_ZN7CSprite7DrawSWFEifffffffjf+0x814> */
/* @0x1ec700 sub sp, r11, #40 */
/* @0x1ec704 vpop {d8} */
/* @0x1ec708 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ec70c cmp r12, #0 */
/* @0x1ec710 lslge r12, r12, #24 */
/* @0x1ec714 movlt r12, #0 */
/* @0x1ec718 b 0x1ec048 <_ZN7CSprite7DrawSWFEifffffffjf+0x140> */
/* @0x1ec71c bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── FUNC 0x1ec720 · CSprite::Draw(int, float, float, float, float, float, unsigned int, float) · size=916 · insn=229 */
/* @0x1ec720 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ec724 vpush {d8, d9} */
/* @0x1ec728 sub sp, sp, #36 */
/* @0x1ec72c vldr s16, [sp, #88] */
/* @0x1ec730 ldr r6, [r0, #0x18] */
/* @0x1ec734 mov r5, r0 */
/* @0x1ec738 ldr r4, [pc, #0x344] */
/* @0x1ec73c mov r8, r1 */
/* @0x1ec740 cmp r6, #0 */
/* @0x1ec744 mov r9, r2 */
/* @0x1ec748 add r4, pc, r4 */
/* @0x1ec74c vmov s18, r3 */
/* @0x1ec750 vldr s17, [sp, #92] */
/* @0x1ec754 vldr s19, [sp, #96] */
/* @0x1ec758 ldr r10, [sp, #0x64] */
/* @0x1ec75c ldr r11, [sp, #0x68] */
/* @0x1ec760 ble 0x1ec87c <_ZN7CSprite4DrawEifffffjf+0x15c> */
/* @0x1ec764 ldr r3, [pc, #0x31c] */
/* @0x1ec768 ldr r7, [r4, r3] */
/* @0x1ec76c ldrb r3, [r7] */
/* @0x1ec770 cmp r3, #0 */
/* @0x1ec774 bne 0x1ec960 <_ZN7CSprite4DrawEifffffjf+0x240> */
/* @0x1ec778 mov r0, r8 */
/* @0x1ec77c mov r1, r6 */
/* @0x1ec780 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ec784 ldr r3, [pc, #0x300] */
/* @0x1ec788 ldr r3, [r4, r3] */
/* @0x1ec78c ldrb r3, [r3] */
/* @0x1ec790 subs r8, r1, #0 */
/* @0x1ec794 addlt r8, r8, r6 */
/* @0x1ec798 cmp r3, #0 */
/* @0x1ec79c bne 0x1ec958 <_ZN7CSprite4DrawEifffffjf+0x238> */
/* @0x1ec7a0 vldr s13, [r5, #44] */
/* @0x1ec7a4 vcvt.f32.s32 s15, s13 */
/* @0x1ec7a8 ldr r3, [pc, #0x2e0] */
/* @0x1ec7ac ldr r3, [r4, r3] */
/* @0x1ec7b0 vmul.f32 s14, s15, s16 */
/* @0x1ec7b4 ldrb r3, [r3] */
/* @0x1ec7b8 vmul.f32 s15, s15, s17 */
/* @0x1ec7bc vabs.f32 s14, s14 */
/* @0x1ec7c0 vabs.f32 s15, s15 */
/* @0x1ec7c4 vcmp.f32 s14, s15 */
/* @0x1ec7c8 vmrs APSR_nzcv, fpscr */
/* @0x1ec7cc vmovgt.f32 s15, s14 */
/* @0x1ec7d0 cmp r3, #0 */
/* @0x1ec7d4 beq 0x1ec888 <_ZN7CSprite4DrawEifffffjf+0x168> */
/* @0x1ec7d8 ldr r0, [r5, #0x74] */
/* @0x1ec7dc cmp r0, #1 */
/* @0x1ec7e0 beq 0x1ec97c <_ZN7CSprite4DrawEifffffjf+0x25c> */
/* @0x1ec7e4 cmp r0, #2 */
/* @0x1ec7e8 beq 0x1ec9e8 <_ZN7CSprite4DrawEifffffjf+0x2c8> */
/* @0x1ec7ec ldr r3, [r5, #0x54] */
/* @0x1ec7f0 vldr s15, [pc, #644] */
/* @0x1ec7f4 vmul.f32 s19, s19, s15 */
/* @0x1ec7f8 vldr s15, [pc, #640] */
/* @0x1ec7fc cmp r3, #0 */
/* @0x1ec800 beq 0x1eca14 <_ZN7CSprite4DrawEifffffjf+0x2f4> */
/* @0x1ec804 ldr r1, [r5, #0x24] */
/* @0x1ec808 ldr r0, [r3, r8, lsl #2] */
/* @0x1ec80c vstr s18, [sp] */
/* @0x1ec810 ldr r2, [r5, #0x28] */
/* @0x1ec814 mov r3, r9 */
/* @0x1ec818 vmov s13, r1 */
/* @0x1ec81c vstr s16, [sp, #4] */
/* @0x1ec820 vstr s17, [sp, #8] */
/* @0x1ec824 str r10, [sp, #0x10] */
/* @0x1ec828 vmov s14, r2 */
/* @0x1ec82c str r11, [sp, #0x14] */
/* @0x1ec830 vdiv.f32 s19, s19, s15 */
/* @0x1ec834 vcvt.f32.s32 s13, s13 */
/* @0x1ec838 vstr s19, [sp, #12] */
/* @0x1ec83c vcvt.f32.s32 s14, s14 */
/* @0x1ec840 vmov r1, s13 */
/* @0x1ec844 vmov r2, s14 */
/* @0x1ec848 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0x1ec84c cmp r0, #0 */
/* @0x1ec850 bne 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec854 ldr r1, [pc, #0x238] */
/* @0x1ec858 ldr r3, [pc, #0x238] */
/* @0x1ec85c ldr r2, [r5, #0x5c] */
/* @0x1ec860 add r1, pc, r1 */
/* @0x1ec864 ldr r3, [r4, r3] */
/* @0x1ec868 ldr r0, [r3] */
/* @0x1ec86c ldr r3, [r0] */
/* @0x1ec870 ldr r3, [r3, #0xc] */
/* @0x1ec874 blx r3 */
/* @0x1ec878 b 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec87c add sp, sp, #36 */
/* @0x1ec880 vpop {d8, d9} */
/* @0x1ec884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ec888 ldr r3, [pc, #0x20c] */
/* @0x1ec88c ldr r3, [r4, r3] */
/* @0x1ec890 ldrb r3, [r3] */
/* @0x1ec894 cmp r3, #0 */
/* @0x1ec898 bne 0x1ec7d8 <_ZN7CSprite4DrawEifffffjf+0xb8> */
/* @0x1ec89c ldr r0, [r5, #0x74] */
/* @0x1ec8a0 cmp r0, #2 */
/* @0x1ec8a4 beq 0x1ec9e8 <_ZN7CSprite4DrawEifffffjf+0x2c8> */
/* @0x1ec8a8 ldr r3, [pc, #0x1f0] */
/* @0x1ec8ac ldr r3, [r4, r3] */
/* @0x1ec8b0 vldr s13, [r3, #4] */
/* @0x1ec8b4 vcvt.f32.s32 s14, s13 */
/* @0x1ec8b8 vsub.f32 s14, s14, s18 */
/* @0x1ec8bc vcmpe.f32 s15, s14 */
/* @0x1ec8c0 vmrs APSR_nzcv, fpscr */
/* @0x1ec8c4 blt 0x1ec914 <_ZN7CSprite4DrawEifffffjf+0x1f4> */
/* @0x1ec8c8 vldr s13, [r3, #12] */
/* @0x1ec8cc vcvt.f32.s32 s14, s13 */
/* @0x1ec8d0 vsub.f32 s14, s18, s14 */
/* @0x1ec8d4 vcmpe.f32 s15, s14 */
/* @0x1ec8d8 vmrs APSR_nzcv, fpscr */
/* @0x1ec8dc blt 0x1ec914 <_ZN7CSprite4DrawEifffffjf+0x1f4> */
/* @0x1ec8e0 vldr s13, [r3] */
/* @0x1ec8e4 vcvt.f32.s32 s14, s13 */
/* @0x1ec8e8 vmov s13, r9 */
/* @0x1ec8ec vsub.f32 s14, s14, s13 */
/* @0x1ec8f0 vcmpe.f32 s15, s14 */
/* @0x1ec8f4 vmrs APSR_nzcv, fpscr */
/* @0x1ec8f8 blt 0x1ec914 <_ZN7CSprite4DrawEifffffjf+0x1f4> */
/* @0x1ec8fc vldr s14, [r3, #8] */
/* @0x1ec900 vcvt.f32.s32 s14, s14 */
/* @0x1ec904 vsub.f32 s14, s13, s14 */
/* @0x1ec908 vcmpe.f32 s15, s14 */
/* @0x1ec90c vmrs APSR_nzcv, fpscr */
/* @0x1ec910 bge 0x1ec7dc <_ZN7CSprite4DrawEifffffjf+0xbc> */
/* @0x1ec914 ldr r3, [pc, #0x188] */
/* @0x1ec918 ldr r3, [r4, r3] */
/* @0x1ec91c ldrb r3, [r3] */
/* @0x1ec920 cmp r3, #0 */
/* @0x1ec924 beq 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec928 ldr r3, [pc, #0x178] */
/* @0x1ec92c ldr r6, [r4, r3] */
/* @0x1ec930 mov r0, r6 */
/* @0x1ec934 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ec938 cmp r0, #0 */
/* @0x1ec93c beq 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec940 mov r0, r6 */
/* @0x1ec944 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ec948 bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1ec94c cmp r0, #0 */
/* @0x1ec950 bne 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1ec954 b 0x1ec7d8 <_ZN7CSprite4DrawEifffffjf+0xb8> */
/* @0x1ec958 bl 0x168d94 <_Z22UpdateTransRoomExtentsv> */
/* @0x1ec95c b 0x1ec7a0 <_ZN7CSprite4DrawEifffffjf+0x80> */
/* @0x1ec960 ldr r3, [pc, #0x144] */
/* @0x1ec964 mov r1, #6 */
/* @0x1ec968 mov r2, #15 */
/* @0x1ec96c ldr r0, [r4, r3] */
/* @0x1ec970 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1ec974 ldr r6, [r5, #0x18] */
/* @0x1ec978 b 0x1ec778 <_ZN7CSprite4DrawEifffffjf+0x58> */
/* @0x1ec97c ldr r2, [r5, #0x24] */
/* @0x1ec980 mov r1, r8 */
/* @0x1ec984 str r9, [sp] */
/* @0x1ec988 mov r0, r5 */
/* @0x1ec98c ldr r3, [r5, #0x28] */
/* @0x1ec990 vstr s18, [sp, #4] */
/* @0x1ec994 vmov s14, r2 */
/* @0x1ec998 vstr s16, [sp, #8] */
/* @0x1ec99c vstr s17, [sp, #12] */
/* @0x1ec9a0 vstr s19, [sp, #16] */
/* @0x1ec9a4 vmov s15, r3 */
/* @0x1ec9a8 str r10, [sp, #0x14] */
/* @0x1ec9ac vcvt.f32.s32 s14, s14 */
/* @0x1ec9b0 str r11, [sp, #0x18] */
/* @0x1ec9b4 vcvt.f32.s32 s15, s15 */
/* @0x1ec9b8 vmov r2, s14 */
/* @0x1ec9bc vmov r3, s15 */
/* @0x1ec9c0 bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf> */
/* @0x1ec9c4 ldrb r3, [r7] */
/* @0x1ec9c8 cmp r3, #0 */
/* @0x1ec9cc beq 0x1ec87c <_ZN7CSprite4DrawEifffffjf+0x15c> */
/* @0x1ec9d0 ldr r3, [pc, #0xd4] */
/* @0x1ec9d4 ldr r0, [r4, r3] */
/* @0x1ec9d8 add sp, sp, #36 */
/* @0x1ec9dc vpop {d8, d9} */
/* @0x1ec9e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ec9e4 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1ec9e8 ldr r0, [r5, #0x58] */
/* @0x1ec9ec mov r1, r8 */
/* @0x1ec9f0 vstr s16, [sp] */
/* @0x1ec9f4 vstr s17, [sp, #4] */
/* @0x1ec9f8 vstr s19, [sp, #8] */
/* @0x1ec9fc str r10, [sp, #0xc] */
/* @0x1eca00 str r11, [sp, #0x10] */
/* @0x1eca04 mov r2, r9 */
/* @0x1eca08 vmov r3, s18 */
/* @0x1eca0c bl 0xc03bc <_ZN15CSkeletonSprite4DrawEifffffjf> */
/* @0x1eca10 b 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1eca14 vdiv.f32 s19, s19, s15 */
/* @0x1eca18 ldr r1, [r5, #0x24] */
/* @0x1eca1c ldr r2, [r5, #0x28] */
/* @0x1eca20 ldr r3, [r5, #0x50] */
/* @0x1eca24 vmov s15, r1 */
/* @0x1eca28 vmov s13, r2 */
/* @0x1eca2c ldr r0, [r3, r8, lsl #2] */
/* @0x1eca30 vstr s18, [sp] */
/* @0x1eca34 mov r3, r9 */
/* @0x1eca38 vstr s16, [sp, #4] */
/* @0x1eca3c vstr s17, [sp, #8] */
/* @0x1eca40 str r10, [sp, #0x10] */
/* @0x1eca44 str r11, [sp, #0x14] */
/* @0x1eca48 vcvt.f32.s32 s15, s15 */
/* @0x1eca4c vstr s19, [sp, #12] */
/* @0x1eca50 vcvt.f32.s32 s13, s13 */
/* @0x1eca54 vmov r1, s15 */
/* @0x1eca58 vmov r2, s13 */
/* @0x1eca5c bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0x1eca60 cmp r0, #0 */
/* @0x1eca64 bne 0x1ec9c4 <_ZN7CSprite4DrawEifffffjf+0x2a4> */
/* @0x1eca68 ldr r1, [pc, #0x40] */
/* @0x1eca6c ldr r3, [pc, #0x24] */
/* @0x1eca70 ldr r2, [r5, #0x5c] */
/* @0x1eca74 add r1, pc, r1 */
/* @0x1eca78 b 0x1ec864 <_ZN7CSprite4DrawEifffffjf+0x144> */
/* @0x1eca7c ldrdmi r0, r1, [r9], #-251 */
/* @0x1eca80 teqmi r4, #0 */
/* @0x1eca84 eoreq r5, r0, r8, lsl #10 */
/* @0x1eca88 .word 0xffffbf18 */
/* @0x1eca8c .word 0xffffd9e0 */
/* @0x1eca90 .word 0xffffc0b4 */
/* @0x1eca94 andseq r5, r6, r4, lsr sp */
/* @0x1eca98 .word 0xffffbac4 */
/* @0x1eca9c .word 0xffffe490 */
/* @0x1ecaa0 .word 0xffffe500 */
/* @0x1ecaa4 .word 0xffffbcd4 */
/* @0x1ecaa8 .word 0xffffc024 */
/* @0x1ecaac .word 0xffffbf1c */
/* @0x1ecab0 andseq r5, r6, r0, lsr #22 */

/* ── FUNC 0x1ecab4 · CSprite::DrawSimple(int, float, float) · size=784 · insn=196 */
/* @0x1ecab4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1ecab8 vpush {d8} */
/* @0x1ecabc vmov s16, r3 */
/* @0x1ecac0 ldr r4, [pc, #0x2d0] */
/* @0x1ecac4 sub sp, sp, #32 */
/* @0x1ecac8 ldr r12, [pc, #0x2cc] */
/* @0x1ecacc mov r5, r0 */
/* @0x1ecad0 add r4, pc, r4 */
/* @0x1ecad4 mov r8, r1 */
/* @0x1ecad8 vmov s17, r2 */
/* @0x1ecadc ldr r6, [r4, r12] */
/* @0x1ecae0 ldrb r3, [r6] */
/* @0x1ecae4 cmp r3, #0 */
/* @0x1ecae8 bne 0x1ecc78 <_ZN7CSprite10DrawSimpleEiff+0x1c4> */
/* @0x1ecaec ldr r7, [r5, #0x18] */
/* @0x1ecaf0 cmp r7, #0 */
/* @0x1ecaf4 ble 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecaf8 mov r0, r8 */
/* @0x1ecafc mov r1, r7 */
/* @0x1ecb00 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ecb04 ldr r3, [pc, #0x294] */
/* @0x1ecb08 ldr r3, [r4, r3] */
/* @0x1ecb0c ldrb r3, [r3] */
/* @0x1ecb10 subs r8, r1, #0 */
/* @0x1ecb14 addlt r8, r8, r7 */
/* @0x1ecb18 cmp r3, #0 */
/* @0x1ecb1c bne 0x1ecc90 <_ZN7CSprite10DrawSimpleEiff+0x1dc> */
/* @0x1ecb20 ldr r3, [pc, #0x27c] */
/* @0x1ecb24 ldr r2, [r5, #0x2c] */
/* @0x1ecb28 ldr r3, [r4, r3] */
/* @0x1ecb2c ldrb r3, [r3] */
/* @0x1ecb30 cmp r3, #0 */
/* @0x1ecb34 ldr r3, [r5, #0x74] */
/* @0x1ecb38 beq 0x1ecba0 <_ZN7CSprite10DrawSimpleEiff+0xec> */
/* @0x1ecb3c cmp r3, #1 */
/* @0x1ecb40 beq 0x1eccd0 <_ZN7CSprite10DrawSimpleEiff+0x21c> */
/* @0x1ecb44 cmp r3, #2 */
/* @0x1ecb48 beq 0x1ecc98 <_ZN7CSprite10DrawSimpleEiff+0x1e4> */
/* @0x1ecb4c ldr r3, [r5, #0x54] */
/* @0x1ecb50 cmp r3, #0 */
/* @0x1ecb54 beq 0x1ecd50 <_ZN7CSprite10DrawSimpleEiff+0x29c> */
/* @0x1ecb58 vldr s15, [r5, #36] */
/* @0x1ecb5c vldr s13, [r5, #40] */
/* @0x1ecb60 vcvt.f32.s32 s14, s15 */
/* @0x1ecb64 ldr r0, [r3, r8, lsl #2] */
/* @0x1ecb68 vcvt.f32.s32 s15, s13 */
/* @0x1ecb6c vsub.f32 s14, s17, s14 */
/* @0x1ecb70 vsub.f32 s15, s16, s15 */
/* @0x1ecb74 vmov r1, s14 */
/* @0x1ecb78 vmov r2, s15 */
/* @0x1ecb7c bl 0x174868 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff> */
/* @0x1ecb80 cmp r0, #0 */
/* @0x1ecb84 beq 0x1ecd28 <_ZN7CSprite10DrawSimpleEiff+0x274> */
/* @0x1ecb88 ldrb r3, [r6] */
/* @0x1ecb8c cmp r3, #0 */
/* @0x1ecb90 bne 0x1ecc60 <_ZN7CSprite10DrawSimpleEiff+0x1ac> */
/* @0x1ecb94 add sp, sp, #32 */
/* @0x1ecb98 vpop {d8} */
/* @0x1ecb9c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ecba0 cmp r3, #2 */
/* @0x1ecba4 beq 0x1ecc98 <_ZN7CSprite10DrawSimpleEiff+0x1e4> */
/* @0x1ecba8 ldr r1, [pc, #0x1f8] */
/* @0x1ecbac vmov s13, r2 */
/* @0x1ecbb0 vcvt.f32.s32 s15, s13 */
/* @0x1ecbb4 ldr r2, [r4, r1] */
/* @0x1ecbb8 vldr s13, [r2, #4] */
/* @0x1ecbbc vcvt.f32.s32 s14, s13 */
/* @0x1ecbc0 vsub.f32 s14, s14, s16 */
/* @0x1ecbc4 vcmpe.f32 s15, s14 */
/* @0x1ecbc8 vmrs APSR_nzcv, fpscr */
/* @0x1ecbcc blt 0x1ecc18 <_ZN7CSprite10DrawSimpleEiff+0x164> */
/* @0x1ecbd0 vldr s13, [r2, #12] */
/* @0x1ecbd4 vcvt.f32.s32 s14, s13 */
/* @0x1ecbd8 vsub.f32 s14, s16, s14 */
/* @0x1ecbdc vcmpe.f32 s15, s14 */
/* @0x1ecbe0 vmrs APSR_nzcv, fpscr */
/* @0x1ecbe4 blt 0x1ecc18 <_ZN7CSprite10DrawSimpleEiff+0x164> */
/* @0x1ecbe8 vldr s13, [r2] */
/* @0x1ecbec vcvt.f32.s32 s14, s13 */
/* @0x1ecbf0 vsub.f32 s14, s14, s17 */
/* @0x1ecbf4 vcmpe.f32 s15, s14 */
/* @0x1ecbf8 vmrs APSR_nzcv, fpscr */
/* @0x1ecbfc blt 0x1ecc18 <_ZN7CSprite10DrawSimpleEiff+0x164> */
/* @0x1ecc00 vldr s14, [r2, #8] */
/* @0x1ecc04 vcvt.f32.s32 s14, s14 */
/* @0x1ecc08 vsub.f32 s14, s17, s14 */
/* @0x1ecc0c vcmpe.f32 s15, s14 */
/* @0x1ecc10 vmrs APSR_nzcv, fpscr */
/* @0x1ecc14 bge 0x1ecb3c <_ZN7CSprite10DrawSimpleEiff+0x88> */
/* @0x1ecc18 ldr r3, [pc, #0x18c] */
/* @0x1ecc1c ldr r3, [r4, r3] */
/* @0x1ecc20 ldrb r3, [r3] */
/* @0x1ecc24 cmp r3, #0 */
/* @0x1ecc28 beq 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecc2c ldr r3, [pc, #0x17c] */
/* @0x1ecc30 ldr r7, [r4, r3] */
/* @0x1ecc34 mov r0, r7 */
/* @0x1ecc38 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ecc3c cmp r0, #0 */
/* @0x1ecc40 beq 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecc44 mov r0, r7 */
/* @0x1ecc48 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1ecc4c bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1ecc50 cmp r0, #0 */
/* @0x1ecc54 bne 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecc58 ldr r3, [r5, #0x74] */
/* @0x1ecc5c b 0x1ecb3c <_ZN7CSprite10DrawSimpleEiff+0x88> */
/* @0x1ecc60 ldr r3, [pc, #0x14c] */
/* @0x1ecc64 ldr r0, [r4, r3] */
/* @0x1ecc68 add sp, sp, #32 */
/* @0x1ecc6c vpop {d8} */
/* @0x1ecc70 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1ecc74 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1ecc78 ldr r3, [pc, #0x134] */
/* @0x1ecc7c mov r1, #6 */
/* @0x1ecc80 mov r2, #16 */
/* @0x1ecc84 ldr r0, [r4, r3] */
/* @0x1ecc88 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1ecc8c b 0x1ecaec <_ZN7CSprite10DrawSimpleEiff+0x38> */
/* @0x1ecc90 bl 0x168d94 <_Z22UpdateTransRoomExtentsv> */
/* @0x1ecc94 b 0x1ecb20 <_ZN7CSprite10DrawSimpleEiff+0x6c> */
/* @0x1ecc98 ldr r0, [r5, #0x58] */
/* @0x1ecc9c mov r12, #1065353216 */
/* @0x1ecca0 mov r2, #0 */
/* @0x1ecca4 mvn r3, #0 */
/* @0x1ecca8 str r2, [sp, #0x8] */
/* @0x1eccac mov r1, r8 */
/* @0x1eccb0 str r3, [sp, #0xc] */
/* @0x1eccb4 vmov r2, s17 */
/* @0x1eccb8 vmov r3, s16 */
/* @0x1eccbc str r12, [sp] */
/* @0x1eccc0 str r12, [sp, #0x4] */
/* @0x1eccc4 str r12, [sp, #0x10] */
/* @0x1eccc8 bl 0xc03bc <_ZN15CSkeletonSprite4DrawEifffffjf> */
/* @0x1ecccc b 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1eccd0 ldr r2, [r5, #0x24] */
/* @0x1eccd4 mov r12, #1065353216 */
/* @0x1eccd8 ldr r3, [r5, #0x28] */
/* @0x1eccdc mov r0, r5 */
/* @0x1ecce0 mvn lr, #0 */
/* @0x1ecce4 mov r5, #0 */
/* @0x1ecce8 vmov s14, r2 */
/* @0x1eccec vstr s17, [sp] */
/* @0x1eccf0 vmov s15, r3 */
/* @0x1eccf4 vstr s16, [sp, #4] */
/* @0x1eccf8 vcvt.f32.s32 s14, s14 */
/* @0x1eccfc mov r1, r8 */
/* @0x1ecd00 str r5, [sp, #0x10] */
/* @0x1ecd04 str lr, [sp, #0x14] */
/* @0x1ecd08 str r12, [sp, #0x8] */
/* @0x1ecd0c str r12, [sp, #0xc] */
/* @0x1ecd10 str r12, [sp, #0x18] */
/* @0x1ecd14 vcvt.f32.s32 s15, s15 */
/* @0x1ecd18 vmov r2, s14 */
/* @0x1ecd1c vmov r3, s15 */
/* @0x1ecd20 bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf> */
/* @0x1ecd24 b 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecd28 ldr r1, [pc, #0x88] */
/* @0x1ecd2c ldr r3, [pc, #0x88] */
/* @0x1ecd30 ldr r2, [r5, #0x5c] */
/* @0x1ecd34 add r1, pc, r1 */
/* @0x1ecd38 ldr r3, [r4, r3] */
/* @0x1ecd3c ldr r0, [r3] */
/* @0x1ecd40 ldr r3, [r0] */
/* @0x1ecd44 ldr r3, [r3, #0xc] */
/* @0x1ecd48 blx r3 */
/* @0x1ecd4c b 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecd50 vldr s13, [r5, #36] */
/* @0x1ecd54 vcvt.f32.s32 s14, s13 */
/* @0x1ecd58 vldr s13, [r5, #40] */
/* @0x1ecd5c ldr r3, [r5, #0x50] */
/* @0x1ecd60 ldr r0, [r3, r8, lsl #2] */
/* @0x1ecd64 vcvt.f32.s32 s15, s13 */
/* @0x1ecd68 vsub.f32 s14, s17, s14 */
/* @0x1ecd6c vsub.f32 s15, s16, s15 */
/* @0x1ecd70 vmov r1, s14 */
/* @0x1ecd74 vmov r2, s15 */
/* @0x1ecd78 bl 0x174498 <_Z22GR_Texture_Draw_Simpleiff> */
/* @0x1ecd7c cmp r0, #0 */
/* @0x1ecd80 bne 0x1ecb88 <_ZN7CSprite10DrawSimpleEiff+0xd4> */
/* @0x1ecd84 ldr r1, [pc, #0x34] */
/* @0x1ecd88 ldr r3, [pc, #0x2c] */
/* @0x1ecd8c ldr r2, [r5, #0x5c] */
/* @0x1ecd90 add r1, pc, r1 */
/* @0x1ecd94 b 0x1ecd38 <_ZN7CSprite10DrawSimpleEiff+0x284> */
/* @0x1ecd98 eoreq r5, r0, r0, lsl #3 */
/* @0x1ecd9c .word 0xffffbf18 */
/* @0x1ecda0 .word 0xffffd9e0 */
/* @0x1ecda4 .word 0xffffe490 */
/* @0x1ecda8 .word 0xffffe500 */
/* @0x1ecdac .word 0xffffbcd4 */
/* @0x1ecdb0 .word 0xffffc024 */
/* @0x1ecdb4 .word 0xffffbf1c */
/* @0x1ecdb8 andseq r5, r6, r0, ror #16 */
/* @0x1ecdbc .word 0xffffbac4 */
/* @0x1ecdc0 andseq r5, r6, r4, lsl #16 */

/* ── FUNC 0x1ecdc4 · CSprite::DrawStretched(int, float, float, float, float, unsigned int, float) · size=500 · insn=125 */
/* @0x1ecdc4 ldr r12, [r0, #0x18] */
/* @0x1ecdc8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ecdcc vpush {d8} */
/* @0x1ecdd0 cmp r12, #0 */
/* @0x1ecdd4 sub sp, sp, #36 */
/* @0x1ecdd8 mov r4, r0 */
/* @0x1ecddc mov r8, r2 */
/* @0x1ecde0 mov r7, r3 */
/* @0x1ecde4 vldr s16, [sp, #72] */
/* @0x1ecde8 ble 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ecdec vcmpe.f32 s16, #0 */
/* @0x1ecdf0 mov r5, #0 */
/* @0x1ecdf4 vmrs APSR_nzcv, fpscr */
/* @0x1ecdf8 bls 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ecdfc vldr s13, [sp, #76] */
/* @0x1ece00 vcmpe.f32 s13, #0 */
/* @0x1ece04 vmrs APSR_nzcv, fpscr */
/* @0x1ece08 bls 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ece0c ldr r6, [r0, #0x1c] */
/* @0x1ece10 cmp r6, #0 */
/* @0x1ece14 ble 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ece18 ldr r9, [r0, #0x20] */
/* @0x1ece1c cmp r9, #0 */
/* @0x1ece20 ble 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ece24 mov r0, r1 */
/* @0x1ece28 mov r1, r12 */
/* @0x1ece2c bl 0x318dec <__aeabi_idivmod> */
/* @0x1ece30 ldr r3, [r4, #0x74] */
/* @0x1ece34 cmp r3, #1 */
/* @0x1ece38 mov r2, r1 */
/* @0x1ece3c beq 0x1ecf54 <_ZN7CSprite13DrawStretchedEiffffjf+0x190> */
/* @0x1ece40 ldr r3, [r4, #0x54] */
/* @0x1ece44 vmov s15, r6 */
/* @0x1ece48 cmp r3, #0 */
/* @0x1ece4c vcvt.f32.s32 s14, s15 */
/* @0x1ece50 beq 0x1eced8 <_ZN7CSprite13DrawStretchedEiffffjf+0x114> */
/* @0x1ece54 ldr r0, [r3, r1, lsl #2] */
/* @0x1ece58 vldr s13, [sp, #84] */
/* @0x1ece5c vstr s13, [sp, #20] */
/* @0x1ece60 vmov s13, r9 */
/* @0x1ece64 ldr r2, [sp, #0x50] */
/* @0x1ece68 mov r1, r5 */
/* @0x1ece6c vcvt.f32.s32 s15, s13 */
/* @0x1ece70 str r7, [sp] */
/* @0x1ece74 str r5, [sp, #0xc] */
/* @0x1ece78 mov r3, r8 */
/* @0x1ece7c str r2, [sp, #0x10] */
/* @0x1ece80 mov r2, r5 */
/* @0x1ece84 vdiv.f32 s16, s16, s14 */
/* @0x1ece88 vldr s14, [sp, #76] */
/* @0x1ece8c vdiv.f32 s15, s14, s15 */
/* @0x1ece90 vstr s16, [sp, #4] */
/* @0x1ece94 vstr s15, [sp, #8] */
/* @0x1ece98 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0x1ece9c cmp r0, #0 */
/* @0x1ecea0 beq 0x1eceb0 <_ZN7CSprite13DrawStretchedEiffffjf+0xec> */
/* @0x1ecea4 add sp, sp, #36 */
/* @0x1ecea8 vpop {d8} */
/* @0x1eceac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1eceb0 ldr r3, [pc, #0xf0] */
/* @0x1eceb4 ldr r1, [pc, #0xf0] */
/* @0x1eceb8 ldr r3, [pc, r3] */
/* @0x1ecebc ldr r2, [r4, #0x5c] */
/* @0x1ecec0 add r1, pc, r1 */
/* @0x1ecec4 ldr r0, [r3] */
/* @0x1ecec8 ldr r3, [r0] */
/* @0x1ececc ldr r3, [r3, #0xc] */
/* @0x1eced0 blx r3 */
/* @0x1eced4 b 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1eced8 ldr r0, [r4, #0x50] */
/* @0x1ecedc vldr s13, [sp, #84] */
/* @0x1ecee0 vdiv.f32 s16, s16, s14 */
/* @0x1ecee4 vldr s14, [sp, #76] */
/* @0x1ecee8 mov r1, r5 */
/* @0x1eceec mov r3, r8 */
/* @0x1ecef0 ldr r0, [r0, r2, lsl #2] */
/* @0x1ecef4 vstr s13, [sp, #20] */
/* @0x1ecef8 vmov s13, r9 */
/* @0x1ecefc ldr r2, [sp, #0x50] */
/* @0x1ecf00 str r7, [sp] */
/* @0x1ecf04 str r5, [sp, #0xc] */
/* @0x1ecf08 str r2, [sp, #0x10] */
/* @0x1ecf0c mov r2, r5 */
/* @0x1ecf10 vcvt.f32.s32 s15, s13 */
/* @0x1ecf14 vstr s16, [sp, #4] */
/* @0x1ecf18 vdiv.f32 s15, s14, s15 */
/* @0x1ecf1c vstr s15, [sp, #8] */
/* @0x1ecf20 bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0x1ecf24 cmp r0, #0 */
/* @0x1ecf28 bne 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ecf2c ldr r3, [pc, #0x7c] */
/* @0x1ecf30 ldr r1, [pc, #0x7c] */
/* @0x1ecf34 ldr r3, [pc, r3] */
/* @0x1ecf38 ldr r2, [r4, #0x5c] */
/* @0x1ecf3c add r1, pc, r1 */
/* @0x1ecf40 ldr r0, [r3] */
/* @0x1ecf44 ldr r3, [r0] */
/* @0x1ecf48 ldr r3, [r3, #0xc] */
/* @0x1ecf4c blx r3 */
/* @0x1ecf50 b 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ecf54 vmov s15, r6 */
/* @0x1ecf58 vldr s13, [sp, #84] */
/* @0x1ecf5c vstr s13, [sp, #24] */
/* @0x1ecf60 vmov s13, r9 */
/* @0x1ecf64 vcvt.f32.s32 s14, s15 */
/* @0x1ecf68 ldr r3, [sp, #0x50] */
/* @0x1ecf6c str r8, [sp] */
/* @0x1ecf70 mov r2, r5 */
/* @0x1ecf74 str r7, [sp, #0x4] */
/* @0x1ecf78 mov r0, r4 */
/* @0x1ecf7c str r3, [sp, #0x14] */
/* @0x1ecf80 mov r3, r5 */
/* @0x1ecf84 str r5, [sp, #0x10] */
/* @0x1ecf88 vcvt.f32.s32 s15, s13 */
/* @0x1ecf8c vdiv.f32 s16, s16, s14 */
/* @0x1ecf90 vldr s14, [sp, #76] */
/* @0x1ecf94 vdiv.f32 s15, s14, s15 */
/* @0x1ecf98 vstr s16, [sp, #8] */
/* @0x1ecf9c vstr s15, [sp, #12] */
/* @0x1ecfa0 bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf> */
/* @0x1ecfa4 b 0x1ecea4 <_ZN7CSprite13DrawStretchedEiffffjf+0xe0> */
/* @0x1ecfa8 eoreq r0, r0, r12, asr r8 */
/* @0x1ecfac ldrsbeq r5, [r6], -r4 */
/* @0x1ecfb0 eoreq r0, r0, r0, ror #15 */
/* @0x1ecfb4 andseq r5, r6, r8, asr r6 */

/* ── FUNC 0x1ecfb8 · CSprite::DrawSWFTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) · size=548 · insn=137 */
/* @0x1ecfb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ecfbc vpush {d8, d9, d10, d11, d12} */
/* @0x1ecfc0 sub sp, sp, #36 */
/* @0x1ecfc4 vldr s17, [sp, #112] */
/* @0x1ecfc8 vcmp.f32 s17, #0 */
/* @0x1ecfcc vldr s18, [sp, #116] */
/* @0x1ecfd0 vmov s14, r3 */
/* @0x1ecfd4 mov r5, r0 */
/* @0x1ecfd8 mov r7, r1 */
/* @0x1ecfdc vmov s13, r2 */
/* @0x1ecfe0 ldrb r6, [sp, #0x78] */
/* @0x1ecfe4 vldr s21, [sp, #128] */
/* @0x1ecfe8 vmrs APSR_nzcv, fpscr */
/* @0x1ecfec vcmp.f32 s18, #0 */
/* @0x1ecff0 movne r3, #0 */
/* @0x1ecff4 moveq r3, #1 */
/* @0x1ecff8 ldrb r4, [sp, #0x7c] */
/* @0x1ecffc vldr s16, [sp, #132] */
/* @0x1ed000 ldr r8, [sp, #0x90] */
/* @0x1ed004 ldr r11, [sp, #0x94] */
/* @0x1ed008 vmrs APSR_nzcv, fpscr */
/* @0x1ed00c orreq r3, r3, #1 */
/* @0x1ed010 cmp r3, #0 */
/* @0x1ed014 bne 0x1ed1b4 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x1fc> */
/* @0x1ed018 vldr s15, [r0, #36] */
/* @0x1ed01c vcvt.f32.s32 s25, s15 */
/* @0x1ed020 vldr s15, [r0, #28] */
/* @0x1ed024 vcvt.f32.s32 s19, s15 */
/* @0x1ed028 vldr s15, [r0, #32] */
/* @0x1ed02c vcvt.f32.s32 s22, s15 */
/* @0x1ed030 vldr s15, [r0, #40] */
/* @0x1ed034 vcvt.f32.s32 s24, s15 */
/* @0x1ed038 vmul.f32 s25, s25, s17 */
/* @0x1ed03c vabs.f32 s12, s17 */
/* @0x1ed040 vmul.f32 s24, s24, s18 */
/* @0x1ed044 vabs.f32 s15, s18 */
/* @0x1ed048 vmul.f32 s19, s19, s12 */
/* @0x1ed04c vmul.f32 s22, s22, s15 */
/* @0x1ed050 vldr s15, [pc, #384] */
/* @0x1ed054 vmov r1, s19 */
/* @0x1ed058 vcmpe.f32 s25, #0 */
/* @0x1ed05c vmrs APSR_nzcv, fpscr */
/* @0x1ed060 vcmpe.f32 s24, #0 */
/* @0x1ed064 vaddmi.f32 s25, s25, s19 */
/* @0x1ed068 vmrs APSR_nzcv, fpscr */
/* @0x1ed06c vaddmi.f32 s24, s24, s22 */
/* @0x1ed070 cmp r6, #0 */
/* @0x1ed074 vmoveq.f32 s21, s15 */
/* @0x1ed078 cmp r4, #0 */
/* @0x1ed07c vsub.f32 s13, s13, s21 */
/* @0x1ed080 vmoveq.f32 s16, s15 */
/* @0x1ed084 vsub.f32 s13, s13, s25 */
/* @0x1ed088 vsub.f32 s14, s14, s16 */
/* @0x1ed08c vmov r0, s13 */
/* @0x1ed090 vsub.f32 s23, s14, s24 */
/* @0x1ed094 bl 0x1e62fc <_Z5fwrapff> */
/* @0x1ed098 vmov r1, s22 */
/* @0x1ed09c vmov s20, r0 */
/* @0x1ed0a0 vmov r0, s23 */
/* @0x1ed0a4 bl 0x1e62fc <_Z5fwrapff> */
/* @0x1ed0a8 vldr s14, [sp, #136] */
/* @0x1ed0ac vdiv.f32 s14, s14, s19 */
/* @0x1ed0b0 vmov s15, r0 */
/* @0x1ed0b4 vcmpe.f32 s20, #0 */
/* @0x1ed0b8 vmov r0, s14 */
/* @0x1ed0bc vmrs APSR_nzcv, fpscr */
/* @0x1ed0c0 vcmpe.f32 s15, #0 */
/* @0x1ed0c4 vsubgt.f32 s20, s20, s19 */
/* @0x1ed0c8 vmrs APSR_nzcv, fpscr */
/* @0x1ed0cc vadd.f32 s16, s24, s16 */
/* @0x1ed0d0 vsubgt.f32 s15, s15, s22 */
/* @0x1ed0d4 vadd.f32 s23, s16, s15 */
/* @0x1ed0d8 bl 0xb6994 <ceilf@plt> */
/* @0x1ed0dc vldr s15, [sp, #140] */
/* @0x1ed0e0 vdiv.f32 s15, s15, s22 */
/* @0x1ed0e4 vmov s16, r0 */
/* @0x1ed0e8 vmov r0, s15 */
/* @0x1ed0ec bl 0xb6994 <ceilf@plt> */
/* @0x1ed0f0 cmp r6, #0 */
/* @0x1ed0f4 vadd.f32 s21, s25, s21 */
/* @0x1ed0f8 moveq r6, #1 */
/* @0x1ed0fc vcvtne.s32.f32 s16, s16 */
/* @0x1ed100 vmovne r6, s16 */
/* @0x1ed104 vadd.f32 s20, s21, s20 */
/* @0x1ed108 vmov s15, r0 */
/* @0x1ed10c addne r6, r6, #1 */
/* @0x1ed110 cmp r4, #0 */
/* @0x1ed114 bne 0x1ed1c0 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x208> */
/* @0x1ed118 mov r10, #1 */
/* @0x1ed11c mov r9, #0 */
/* @0x1ed120 vldr s21, [pc, #176] */
/* @0x1ed124 vmov s14, r9 */
/* @0x1ed128 cmp r6, #0 */
/* @0x1ed12c vmov.f32 s16, s23 */
/* @0x1ed130 movgt r4, #0 */
/* @0x1ed134 vcvt.f32.s32 s15, s14 */
/* @0x1ed138 vmla.f32 s16, s15, s22 */
/* @0x1ed13c ble 0x1ed1a8 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x1f0> */
/* @0x1ed140 vmov s14, r4 */
/* @0x1ed144 ldr r2, [r5, #0x24] */
/* @0x1ed148 ldr r3, [r5, #0x28] */
/* @0x1ed14c add r4, r4, #1 */
/* @0x1ed150 vstr s16, [sp, #4] */
/* @0x1ed154 vstr s17, [sp, #8] */
/* @0x1ed158 vstr s18, [sp, #12] */
/* @0x1ed15c vstr s21, [sp, #16] */
/* @0x1ed160 str r8, [sp, #0x14] */
/* @0x1ed164 mov r0, r5 */
/* @0x1ed168 str r11, [sp, #0x18] */
/* @0x1ed16c mov r1, r7 */
/* @0x1ed170 vcvt.f32.s32 s15, s14 */
/* @0x1ed174 vmov.f32 s14, s20 */
/* @0x1ed178 vmla.f32 s14, s15, s19 */
/* @0x1ed17c vmov.f32 s15, s14 */
/* @0x1ed180 vstr s15, [sp] */
/* @0x1ed184 vmov s14, r2 */
/* @0x1ed188 vmov s15, r3 */
/* @0x1ed18c vcvt.f32.s32 s14, s14 */
/* @0x1ed190 vcvt.f32.s32 s15, s15 */
/* @0x1ed194 vmov r2, s14 */
/* @0x1ed198 vmov r3, s15 */
/* @0x1ed19c bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf> */
/* @0x1ed1a0 cmp r4, r6 */
/* @0x1ed1a4 bne 0x1ed140 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x188> */
/* @0x1ed1a8 add r9, r9, #1 */
/* @0x1ed1ac cmp r10, r9 */
/* @0x1ed1b0 bgt 0x1ed124 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x16c> */
/* @0x1ed1b4 add sp, sp, #36 */
/* @0x1ed1b8 vpop {d8, d9, d10, d11, d12} */
/* @0x1ed1bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ed1c0 vcvt.s32.f32 s15, s15 */
/* @0x1ed1c4 vmov r10, s15 */
/* @0x1ed1c8 add r10, r10, #1 */
/* @0x1ed1cc cmp r10, #0 */
/* @0x1ed1d0 bgt 0x1ed11c <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x164> */
/* @0x1ed1d4 b 0x1ed1b4 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x1fc> */
/* @0x1ed1d8 andeq r0, r0, r0 */

/* ── FUNC 0x1ed1dc · CSprite::DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) · size=500 · insn=125 */
/* @0x1ed1dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed1e0 vpush {d8, d9, d10} */
/* @0x1ed1e4 sub sp, sp, #52 */
/* @0x1ed1e8 vldr s21, [sp, #112] */
/* @0x1ed1ec ldr r5, [r0, #0x18] */
/* @0x1ed1f0 mov r4, r0 */
/* @0x1ed1f4 mov r10, r2 */
/* @0x1ed1f8 mov r6, r3 */
/* @0x1ed1fc cmp r5, #0 */
/* @0x1ed200 vldr s20, [sp, #116] */
/* @0x1ed204 ldrb r9, [sp, #0x78] */
/* @0x1ed208 vldr s19, [sp, #128] */
/* @0x1ed20c ldrb r8, [sp, #0x7c] */
/* @0x1ed210 vldr s18, [sp, #132] */
/* @0x1ed214 vldr s17, [sp, #136] */
/* @0x1ed218 vldr s16, [sp, #140] */
/* @0x1ed21c ldr r7, [sp, #0x90] */
/* @0x1ed220 ldr r11, [sp, #0x94] */
/* @0x1ed224 ble 0x1ed2b4 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xd8> */
/* @0x1ed228 mov r0, r1 */
/* @0x1ed22c mov r1, r5 */
/* @0x1ed230 bl 0x318dec <__aeabi_idivmod> */
/* @0x1ed234 ldr r3, [r4, #0x74] */
/* @0x1ed238 cmp r1, #0 */
/* @0x1ed23c addlt r1, r1, r5 */
/* @0x1ed240 cmp r3, #1 */
/* @0x1ed244 beq 0x1ed37c <_ZN7CSprite9DrawTiledEiffffbbffffjf+0x1a0> */
/* @0x1ed248 ldr r0, [r4, #0x54] */
/* @0x1ed24c cmp r0, #0 */
/* @0x1ed250 beq 0x1ed2f0 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0x114> */
/* @0x1ed254 ldr r0, [r0, r1, lsl #2] */
/* @0x1ed258 mov r3, r10 */
/* @0x1ed25c str r6, [sp] */
/* @0x1ed260 ldr r1, [r4, #0x24] */
/* @0x1ed264 vstr s21, [sp, #4] */
/* @0x1ed268 ldr r2, [r4, #0x28] */
/* @0x1ed26c vstr s20, [sp, #8] */
/* @0x1ed270 str r9, [sp, #0xc] */
/* @0x1ed274 vstr s19, [sp, #20] */
/* @0x1ed278 vmov s15, r1 */
/* @0x1ed27c str r8, [sp, #0x10] */
/* @0x1ed280 vstr s18, [sp, #24] */
/* @0x1ed284 vstr s17, [sp, #28] */
/* @0x1ed288 vcvt.f32.s32 s15, s15 */
/* @0x1ed28c vstr s16, [sp, #32] */
/* @0x1ed290 str r7, [sp, #0x24] */
/* @0x1ed294 str r11, [sp, #0x28] */
/* @0x1ed298 vmov r1, s15 */
/* @0x1ed29c vmov s15, r2 */
/* @0x1ed2a0 vcvt.f32.s32 s15, s15 */
/* @0x1ed2a4 vmov r2, s15 */
/* @0x1ed2a8 bl 0x1762b0 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf> */
/* @0x1ed2ac cmp r0, #0 */
/* @0x1ed2b0 beq 0x1ed2c0 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xe4> */
/* @0x1ed2b4 add sp, sp, #52 */
/* @0x1ed2b8 vpop {d8, d9, d10} */
/* @0x1ed2bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ed2c0 ldr r3, [pc, #0xf8] */
/* @0x1ed2c4 ldr r1, [pc, #0xf8] */
/* @0x1ed2c8 ldr r3, [pc, r3] */
/* @0x1ed2cc ldr r2, [r4, #0x5c] */
/* @0x1ed2d0 add r1, pc, r1 */
/* @0x1ed2d4 ldr r0, [r3] */
/* @0x1ed2d8 ldr r3, [r0] */
/* @0x1ed2dc ldr r3, [r3, #0xc] */
/* @0x1ed2e0 blx r3 */
/* @0x1ed2e4 add sp, sp, #52 */
/* @0x1ed2e8 vpop {d8, d9, d10} */
/* @0x1ed2ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ed2f0 ldr r12, [r4, #0x24] */
/* @0x1ed2f4 mov r3, r10 */
/* @0x1ed2f8 ldr r2, [r4, #0x50] */
/* @0x1ed2fc vmov s15, r12 */
/* @0x1ed300 ldr r0, [r2, r1, lsl #2] */
/* @0x1ed304 vcvt.f32.s32 s15, s15 */
/* @0x1ed308 str r6, [sp] */
/* @0x1ed30c ldr r2, [r4, #0x28] */
/* @0x1ed310 vstr s21, [sp, #4] */
/* @0x1ed314 vstr s20, [sp, #8] */
/* @0x1ed318 str r9, [sp, #0xc] */
/* @0x1ed31c str r8, [sp, #0x10] */
/* @0x1ed320 vstr s19, [sp, #20] */
/* @0x1ed324 vstr s18, [sp, #24] */
/* @0x1ed328 vstr s17, [sp, #28] */
/* @0x1ed32c vstr s16, [sp, #32] */
/* @0x1ed330 str r7, [sp, #0x24] */
/* @0x1ed334 str r11, [sp, #0x28] */
/* @0x1ed338 vmov r1, s15 */
/* @0x1ed33c vmov s15, r2 */
/* @0x1ed340 vcvt.f32.s32 s15, s15 */
/* @0x1ed344 vmov r2, s15 */
/* @0x1ed348 bl 0x175e90 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf> */
/* @0x1ed34c cmp r0, #0 */
/* @0x1ed350 bne 0x1ed2b4 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xd8> */
/* @0x1ed354 ldr r3, [pc, #0x6c] */
/* @0x1ed358 ldr r1, [pc, #0x6c] */
/* @0x1ed35c ldr r3, [pc, r3] */
/* @0x1ed360 ldr r2, [r4, #0x5c] */
/* @0x1ed364 add r1, pc, r1 */
/* @0x1ed368 ldr r0, [r3] */
/* @0x1ed36c ldr r3, [r0] */
/* @0x1ed370 ldr r3, [r3, #0xc] */
/* @0x1ed374 blx r3 */
/* @0x1ed378 b 0x1ed2b4 <_ZN7CSprite9DrawTiledEiffffbbffffjf+0xd8> */
/* @0x1ed37c vstr s21, [sp, #112] */
/* @0x1ed380 mov r0, r4 */
/* @0x1ed384 vstr s20, [sp, #116] */
/* @0x1ed388 str r9, [sp, #0x78] */
/* @0x1ed38c str r8, [sp, #0x7c] */
/* @0x1ed390 vstr s19, [sp, #128] */
/* @0x1ed394 vstr s18, [sp, #132] */
/* @0x1ed398 vstr s17, [sp, #136] */
/* @0x1ed39c vstr s16, [sp, #140] */
/* @0x1ed3a0 str r7, [sp, #0x90] */
/* @0x1ed3a4 str r11, [sp, #0x94] */
/* @0x1ed3a8 mov r2, r10 */
/* @0x1ed3ac mov r3, r6 */
/* @0x1ed3b0 add sp, sp, #52 */
/* @0x1ed3b4 vpop {d8, d9, d10} */
/* @0x1ed3b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed3bc b 0x1ecfb8 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf> */
/* @0x1ed3c0 eoreq r0, r0, r12, asr #8 */
/* @0x1ed3c4 andseq r5, r6, r4, asr #5 */
/* @0x1ed3c8 .word 0x002003b8 */
/* @0x1ed3cc andseq r5, r6, r0, lsr r2 */

/* ── FUNC 0x1ed3d0 · CSprite::Collision(int, float, float, float, float, float, float, float) · size=920 · insn=230 */
/* @0x1ed3d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed3d4 vpush {d8} */
/* @0x1ed3d8 sub sp, sp, #492 */
/* @0x1ed3dc vldr s17, [sp, #540] */
/* @0x1ed3e0 add r9, sp, #104 */
/* @0x1ed3e4 mov r7, r0 */
/* @0x1ed3e8 mov r5, r1 */
/* @0x1ed3ec ldr r1, [sp, #0x218] */
/* @0x1ed3f0 mov r0, r9 */
/* @0x1ed3f4 mov r4, #0 */
/* @0x1ed3f8 mov r6, #1065353216 */
/* @0x1ed3fc str r2, [sp, #0x58] */
/* @0x1ed400 str r3, [sp, #0x5c] */
/* @0x1ed404 vldr s16, [sp, #544] */
/* @0x1ed408 str r4, [sp, #0x54] */
/* @0x1ed40c add r10, sp, #296 */
/* @0x1ed410 str r4, [sp, #0x4c] */
/* @0x1ed414 str r4, [sp, #0x48] */
/* @0x1ed418 str r4, [sp, #0x44] */
/* @0x1ed41c str r4, [sp, #0x40] */
/* @0x1ed420 str r4, [sp, #0x38] */
/* @0x1ed424 str r4, [sp, #0x34] */
/* @0x1ed428 str r4, [sp, #0x30] */
/* @0x1ed42c str r4, [sp, #0x2c] */
/* @0x1ed430 str r4, [sp, #0x60] */
/* @0x1ed434 str r6, [sp, #0x64] */
/* @0x1ed438 str r6, [sp, #0x50] */
/* @0x1ed43c str r6, [sp, #0x3c] */
/* @0x1ed440 str r6, [sp, #0x28] */
/* @0x1ed444 ldr r11, [sp, #0x224] */
/* @0x1ed448 ldr r8, [sp, #0x228] */
/* @0x1ed44c bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* @0x1ed450 ldr r12, [pc, #0x304] */
/* @0x1ed454 vldr s14, [pc, #764] */
/* @0x1ed458 ldr r3, [pc, #0x300] */
/* @0x1ed45c mov r0, r10 */
/* @0x1ed460 add r12, pc, r12 */
/* @0x1ed464 str r12, [sp, #0x14] */
/* @0x1ed468 add r1, sp, #168 */
/* @0x1ed46c add r2, sp, #232 */
/* @0x1ed470 ldr r3, [r12, r3] */
/* @0x1ed474 vldr s15, [r3] */
/* @0x1ed478 vdiv.f32 s14, s14, s15 */
/* @0x1ed47c str r4, [sp, #0xd4] */
/* @0x1ed480 str r4, [sp, #0xcc] */
/* @0x1ed484 str r4, [sp, #0xc8] */
/* @0x1ed488 str r4, [sp, #0xc4] */
/* @0x1ed48c str r4, [sp, #0xc0] */
/* @0x1ed490 str r4, [sp, #0xb8] */
/* @0x1ed494 str r4, [sp, #0xb4] */
/* @0x1ed498 str r4, [sp, #0xb0] */
/* @0x1ed49c str r4, [sp, #0xac] */
/* @0x1ed4a0 str r4, [sp, #0xe0] */
/* @0x1ed4a4 str r4, [sp, #0x120] */
/* @0x1ed4a8 str r4, [sp, #0x11c] */
/* @0x1ed4ac str r4, [sp, #0x118] */
/* @0x1ed4b0 str r4, [sp, #0x114] */
/* @0x1ed4b4 str r4, [sp, #0x10c] */
/* @0x1ed4b8 str r4, [sp, #0x108] */
/* @0x1ed4bc str r4, [sp, #0x104] */
/* @0x1ed4c0 str r4, [sp, #0x100] */
/* @0x1ed4c4 str r4, [sp, #0xf8] */
/* @0x1ed4c8 str r4, [sp, #0xf4] */
/* @0x1ed4cc str r4, [sp, #0xf0] */
/* @0x1ed4d0 str r4, [sp, #0xec] */
/* @0x1ed4d4 add r4, sp, #360 */
/* @0x1ed4d8 str r6, [sp, #0xe4] */
/* @0x1ed4dc str r6, [sp, #0xd0] */
/* @0x1ed4e0 str r6, [sp, #0xbc] */
/* @0x1ed4e4 str r6, [sp, #0xa8] */
/* @0x1ed4e8 str r6, [sp, #0x124] */
/* @0x1ed4ec str r6, [sp, #0x110] */
/* @0x1ed4f0 vmul.f32 s17, s15, s17 */
/* @0x1ed4f4 vstr s14, [sp, #216] */
/* @0x1ed4f8 vstr s14, [sp, #220] */
/* @0x1ed4fc vmul.f32 s15, s15, s16 */
/* @0x1ed500 vstr s17, [sp, #232] */
/* @0x1ed504 vstr s15, [sp, #252] */
/* @0x1ed508 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ed50c mov r1, r10 */
/* @0x1ed510 mov r2, r9 */
/* @0x1ed514 mov r0, r4 */
/* @0x1ed518 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ed51c mov r1, r4 */
/* @0x1ed520 add r2, sp, #40 */
/* @0x1ed524 add r0, sp, #424 */
/* @0x1ed528 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ed52c ldr r1, [r7, #0x80] */
/* @0x1ed530 ldr r2, [r7, #0x7c] */
/* @0x1ed534 cmp r1, #0 */
/* @0x1ed538 ble 0x1ed570 <_ZN7CSprite9CollisionEifffffff+0x1a0> */
/* @0x1ed53c ldr r6, [r2] */
/* @0x1ed540 ldr r3, [r6, #0x4] */
/* @0x1ed544 cmp r5, r3 */
/* @0x1ed548 beq 0x1ed574 <_ZN7CSprite9CollisionEifffffff+0x1a4> */
/* @0x1ed54c mov r3, #0 */
/* @0x1ed550 b 0x1ed564 <_ZN7CSprite9CollisionEifffffff+0x194> */
/* @0x1ed554 ldr r6, [r2, #0x4]! */
/* @0x1ed558 ldr r0, [r6, #0x4] */
/* @0x1ed55c cmp r5, r0 */
/* @0x1ed560 beq 0x1ed574 <_ZN7CSprite9CollisionEifffffff+0x1a4> */
/* @0x1ed564 add r3, r3, #1 */
/* @0x1ed568 cmp r3, r1 */
/* @0x1ed56c bne 0x1ed554 <_ZN7CSprite9CollisionEifffffff+0x184> */
/* @0x1ed570 mov r6, #0 */
/* @0x1ed574 ldr r3, [r6] */
/* @0x1ed578 cmp r3, #1 */
/* @0x1ed57c beq 0x1ed590 <_ZN7CSprite9CollisionEifffffff+0x1c0> */
/* @0x1ed580 mov r0, #0 */
/* @0x1ed584 add sp, sp, #492 */
/* @0x1ed588 vpop {d8} */
/* @0x1ed58c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ed590 ldr r3, [r6, #0x1c] */
/* @0x1ed594 cmp r3, #0 */
/* @0x1ed598 beq 0x1ed580 <_ZN7CSprite9CollisionEifffffff+0x1b0> */
/* @0x1ed59c mov r12, #0 */
/* @0x1ed5a0 str r6, [sp, #0x20] */
/* @0x1ed5a4 str r12, [sp, #0x1c] */
/* @0x1ed5a8 str r12, [sp, #0x24] */
/* @0x1ed5ac ldr r12, [sp, #0x20] */
/* @0x1ed5b0 ldr r10, [r12, #0x8] */
/* @0x1ed5b4 ldr r12, [sp, #0x1c] */
/* @0x1ed5b8 add r10, r10, r12 */
/* @0x1ed5bc str r10, [sp, #0x18] */
/* @0x1ed5c0 ldr r2, [r10, #0xc] */
/* @0x1ed5c4 cmp r2, #0 */
/* @0x1ed5c8 movne r7, #0 */
/* @0x1ed5cc movne r9, r7 */
/* @0x1ed5d0 beq 0x1ed71c <_ZN7CSprite9CollisionEifffffff+0x34c> */
/* @0x1ed5d4 ldr r1, [sp, #0x18] */
/* @0x1ed5d8 ldr r12, [r1] */
/* @0x1ed5dc add r10, r12, r7 */
/* @0x1ed5e0 ldr r3, [r10, #0x28] */
/* @0x1ed5e4 cmp r3, #0 */
/* @0x1ed5e8 blt 0x1ed704 <_ZN7CSprite9CollisionEifffffff+0x334> */
/* @0x1ed5ec ldr r3, [r10, #0x38] */
/* @0x1ed5f0 cmp r3, #0 */
/* @0x1ed5f4 beq 0x1ed704 <_ZN7CSprite9CollisionEifffffff+0x334> */
/* @0x1ed5f8 ldr r0, [r10, #0x30] */
/* @0x1ed5fc ldr r3, [r10] */
/* @0x1ed600 cmp r0, #65536 */
/* @0x1ed604 movhs r0, #65536 */
/* @0x1ed608 cmp r0, #0 */
/* @0x1ed60c beq 0x1ed744 <_ZN7CSprite9CollisionEifffffff+0x374> */
/* @0x1ed610 ldr r2, [pc, #0x14c] */
/* @0x1ed614 mov r1, #0 */
/* @0x1ed618 ldr r12, [sp, #0x14] */
/* @0x1ed61c ldr r5, [r12, r2] */
/* @0x1ed620 add r2, r5, #8 */
/* @0x1ed624 vldr s12, [r3, #4] */
/* @0x1ed628 vldr s14, [sp, #444] */
/* @0x1ed62c vldr s15, [sp, #440] */
/* @0x1ed630 vmul.f32 s14, s12, s14 */
/* @0x1ed634 vldr s13, [r3] */
/* @0x1ed638 vldr s8, [sp, #428] */
/* @0x1ed63c vldr s9, [sp, #424] */
/* @0x1ed640 vldr s10, [sp, #476] */
/* @0x1ed644 vldr s11, [sp, #472] */
/* @0x1ed648 add r1, r1, #1 */
/* @0x1ed64c cmp r0, r1 */
/* @0x1ed650 add r3, r3, #8 */
/* @0x1ed654 add r2, r2, #8 */
/* @0x1ed658 vmul.f32 s15, s12, s15 */
/* @0x1ed65c vmla.f32 s14, s13, s8 */
/* @0x1ed660 vmla.f32 s15, s13, s9 */
/* @0x1ed664 vadd.f32 s14, s14, s10 */
/* @0x1ed668 vadd.f32 s15, s15, s11 */
/* @0x1ed66c vstr s14, [r2, #-12] */
/* @0x1ed670 vstr s15, [r2, #-16] */
/* @0x1ed674 bne 0x1ed624 <_ZN7CSprite9CollisionEifffffff+0x254> */
/* @0x1ed678 ldr r4, [r10, #0x8] */
/* @0x1ed67c mov r6, #0 */
/* @0x1ed680 b 0x1ed690 <_ZN7CSprite9CollisionEifffffff+0x2c0> */
/* @0x1ed684 ldr r3, [r10, #0x38] */
/* @0x1ed688 cmp r6, r3 */
/* @0x1ed68c bhs 0x1ed6fc <_ZN7CSprite9CollisionEifffffff+0x32c> */
/* @0x1ed690 ldrh r1, [r4, #2] */
/* @0x1ed694 add r6, r6, #1 */
/* @0x1ed698 ldrh r3, [r4] */
/* @0x1ed69c add r4, r4, #6 */
/* @0x1ed6a0 ldrh r12, [r4, #-2] */
/* @0x1ed6a4 add r1, r5, r1, lsl #3 */
/* @0x1ed6a8 add r3, r5, r3, lsl #3 */
/* @0x1ed6ac ldr r0, [r1] */
/* @0x1ed6b0 add r12, r5, r12, lsl #3 */
/* @0x1ed6b4 ldr r2, [r3] */
/* @0x1ed6b8 ldr r3, [r3, #0x4] */
/* @0x1ed6bc str r0, [sp] */
/* @0x1ed6c0 mov r0, r11 */
/* @0x1ed6c4 ldr r1, [r1, #0x4] */
/* @0x1ed6c8 str r1, [sp, #0x4] */
/* @0x1ed6cc ldr r1, [r12] */
/* @0x1ed6d0 str r1, [sp, #0x8] */
/* @0x1ed6d4 mov r1, r8 */
/* @0x1ed6d8 ldr r12, [r12, #0x4] */
/* @0x1ed6dc str r12, [sp, #0xc] */
/* @0x1ed6e0 bl 0x10c328 <_Z17Point_In_Triangleffffffff> */
/* @0x1ed6e4 cmp r0, #0 */
/* @0x1ed6e8 beq 0x1ed684 <_ZN7CSprite9CollisionEifffffff+0x2b4> */
/* @0x1ed6ec mov r0, #1 */
/* @0x1ed6f0 add sp, sp, #492 */
/* @0x1ed6f4 vpop {d8} */
/* @0x1ed6f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ed6fc ldr r12, [sp, #0x18] */
/* @0x1ed700 ldr r2, [r12, #0xc] */
/* @0x1ed704 add r9, r9, #1 */
/* @0x1ed708 add r7, r7, #84 */
/* @0x1ed70c cmp r2, r9 */
/* @0x1ed710 bhi 0x1ed5d4 <_ZN7CSprite9CollisionEifffffff+0x204> */
/* @0x1ed714 ldr r12, [sp, #0x20] */
/* @0x1ed718 ldr r3, [r12, #0x1c] */
/* @0x1ed71c ldr r12, [sp, #0x24] */
/* @0x1ed720 add r12, r12, #1 */
/* @0x1ed724 str r12, [sp, #0x24] */
/* @0x1ed728 ldr r12, [sp, #0x1c] */
/* @0x1ed72c add r12, r12, #24 */
/* @0x1ed730 str r12, [sp, #0x1c] */
/* @0x1ed734 ldr r12, [sp, #0x24] */
/* @0x1ed738 cmp r3, r12 */
/* @0x1ed73c bhi 0x1ed5ac <_ZN7CSprite9CollisionEifffffff+0x1dc> */
/* @0x1ed740 b 0x1ed580 <_ZN7CSprite9CollisionEifffffff+0x1b0> */
/* @0x1ed744 ldr r3, [pc, #0x18] */
/* @0x1ed748 ldr r12, [sp, #0x14] */
/* @0x1ed74c ldr r4, [r10, #0x8] */
/* @0x1ed750 ldr r5, [r12, r3] */
/* @0x1ed754 b 0x1ed67c <_ZN7CSprite9CollisionEifffffff+0x2ac> */
/* @0x1ed758 andhi r0, r0, r0 */
/* @0x1ed75c .word 0x002047f0 */
/* @0x1ed760 .word 0xfffff184 */
/* @0x1ed764 .word 0xfffff190 */

/* ── FUNC 0x1ed768 · CSprite::DrawShape(int, int, int, float, float, float, float, float, unsigned int, unsigned int, float) · size=4096 · insn=1024 */
/* @0x1ed768 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ed76c vpush {d8, d9} */
/* @0x1ed770 sub sp, sp, #1280 */
/* @0x1ed774 sub sp, sp, #12 */
/* @0x1ed778 ldr r7, [pc, #0x46c] */
/* @0x1ed77c mov r11, r0 */
/* @0x1ed780 str r1, [sp, #0x8c] */
/* @0x1ed784 add r7, pc, r7 */
/* @0x1ed788 ldr r1, [r0, #0x7c] */
/* @0x1ed78c str r2, [sp, #0x88] */
/* @0x1ed790 cmp r1, #0 */
/* @0x1ed794 str r3, [sp, #0xa8] */
/* @0x1ed798 beq 0x1ee27c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb14> */
/* @0x1ed79c ldr r3, [r0, #0x84] */
/* @0x1ed7a0 cmp r3, #0 */
/* @0x1ed7a4 beq 0x1ee27c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb14> */
/* @0x1ed7a8 ldr r6, [sp, #0x8c] */
/* @0x1ed7ac cmn r6, #1 */
/* @0x1ed7b0 beq 0x1ee68c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xf24> */
/* @0x1ed7b4 ldr r9, [sp, #0x8c] */
/* @0x1ed7b8 cmn r9, #2 */
/* @0x1ed7bc beq 0x1ee28c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb24> */
/* @0x1ed7c0 ldr r3, [pc, #0x454] */
/* @0x1ed7c4 mov r1, #0 */
/* @0x1ed7c8 mov r2, #2 */
/* @0x1ed7cc ldr r5, [r7, r3] */
/* @0x1ed7d0 mov r0, r5 */
/* @0x1ed7d4 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ed7d8 mov r2, #3 */
/* @0x1ed7dc mov r1, #0 */
/* @0x1ed7e0 str r0, [sp, #0xb0] */
/* @0x1ed7e4 mov r0, r5 */
/* @0x1ed7e8 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x1ed7ec vldr s15, [pc, #1008] */
/* @0x1ed7f0 str r0, [sp, #0xb4] */
/* @0x1ed7f4 add r0, sp, #2048 */
/* @0x1ed7f8 ldr lr, [r0, #-0x2a4] */
/* @0x1ed7fc vmov s12, lr */
/* @0x1ed800 vmul.f32 s15, s12, s15 */
/* @0x1ed804 vcvt.s32.f32 s15, s15 */
/* @0x1ed808 vmov r3, s15 */
/* @0x1ed80c cmp r3, #255 */
/* @0x1ed810 movgt r2, #-16777216 */
/* @0x1ed814 ble 0x1ee4cc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd64> */
/* @0x1ed818 ldr r6, [sp, #0x554] */
/* @0x1ed81c cmp r3, #255 */
/* @0x1ed820 ldr r10, [sp, #0x554] */
/* @0x1ed824 bic r6, r6, #-16777216 */
/* @0x1ed828 movgt r3, #-16777216 */
/* @0x1ed82c orr r2, r2, r6 */
/* @0x1ed830 str r2, [sp, #0x94] */
/* @0x1ed834 ldr r9, [sp, #0x94] */
/* @0x1ed838 ubfx r2, r6, #0x8, #0x8 */
/* @0x1ed83c str r6, [sp, #0xac] */
/* @0x1ed840 ubfx r1, r9, #0x8, #0x8 */
/* @0x1ed844 str r2, [sp, #0xcc] */
/* @0x1ed848 str r1, [sp, #0xbc] */
/* @0x1ed84c uxtb r2, r9 */
/* @0x1ed850 ubfx r1, r9, #0x10, #0x8 */
/* @0x1ed854 str r2, [sp, #0xb8] */
/* @0x1ed858 str r1, [sp, #0xc0] */
/* @0x1ed85c lsr r2, r9, #24 */
/* @0x1ed860 lsr r1, r6, #16 */
/* @0x1ed864 str r2, [sp, #0xc4] */
/* @0x1ed868 str r1, [sp, #0xd0] */
/* @0x1ed86c uxtb r2, r10 */
/* @0x1ed870 str r2, [sp, #0xc8] */
/* @0x1ed874 mov r2, #0 */
/* @0x1ed878 str r2, [sp, #0xd4] */
/* @0x1ed87c ble 0x1ee4dc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd74> */
/* @0x1ed880 add lr, sp, #2048 */
/* @0x1ed884 ldr r12, [sp, #0x558] */
/* @0x1ed888 add r6, sp, #392 */
/* @0x1ed88c vldr s16, [pc, #912] */
/* @0x1ed890 ldr r10, [lr, #-0x2c0] */
/* @0x1ed894 bic r1, r12, #-16777216 */
/* @0x1ed898 orr r3, r3, r1 */
/* @0x1ed89c mov r0, r6 */
/* @0x1ed8a0 ldr r1, [lr, #-0x2b0] */
/* @0x1ed8a4 mov r9, #1065353216 */
/* @0x1ed8a8 str r10, [sp, #0x178] */
/* @0x1ed8ac ubfx r2, r3, #0x8, #0x8 */
/* @0x1ed8b0 ldr r10, [lr, #-0x2bc] */
/* @0x1ed8b4 uxtb r12, r3 */
/* @0x1ed8b8 str r2, [sp, #0xdc] */
/* @0x1ed8bc vstr s16, [sp, #372] */
/* @0x1ed8c0 str r12, [sp, #0xd8] */
/* @0x1ed8c4 vstr s16, [sp, #364] */
/* @0x1ed8c8 str r10, [sp, #0x17c] */
/* @0x1ed8cc vstr s16, [sp, #360] */
/* @0x1ed8d0 str r12, [sp, #0xe8] */
/* @0x1ed8d4 vstr s16, [sp, #356] */
/* @0x1ed8d8 ubfx r12, r3, #0x10, #0x8 */
/* @0x1ed8dc str r2, [sp, #0xec] */
/* @0x1ed8e0 str r12, [sp, #0xe0] */
/* @0x1ed8e4 lsr r3, r3, #24 */
/* @0x1ed8e8 mov r2, #0 */
/* @0x1ed8ec str r3, [sp, #0xe4] */
/* @0x1ed8f0 str r3, [sp, #0xf0] */
/* @0x1ed8f4 vstr s16, [sp, #352] */
/* @0x1ed8f8 str r2, [sp, #0xf4] */
/* @0x1ed8fc vstr s16, [sp, #344] */
/* @0x1ed900 str r9, [sp, #0x184] */
/* @0x1ed904 vstr s16, [sp, #340] */
/* @0x1ed908 str r9, [sp, #0x170] */
/* @0x1ed90c vstr s16, [sp, #336] */
/* @0x1ed910 str r9, [sp, #0x15c] */
/* @0x1ed914 vstr s16, [sp, #332] */
/* @0x1ed918 str r9, [sp, #0x148] */
/* @0x1ed91c vstr s16, [sp, #384] */
/* @0x1ed920 bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f> */
/* @0x1ed924 ldr r3, [pc, #0x2c4] */
/* @0x1ed928 vldr s14, [pc, #696] */
/* @0x1ed92c add r10, sp, #2048 */
/* @0x1ed930 add r8, sp, #584 */
/* @0x1ed934 add r1, sp, #456 */
/* @0x1ed938 ldr r3, [r7, r3] */
/* @0x1ed93c vldr s15, [r3] */
/* @0x1ed940 vdiv.f32 s14, s14, s15 */
/* @0x1ed944 ldr r3, [r10, #-0x2b8] */
/* @0x1ed948 mov r0, r8 */
/* @0x1ed94c add r2, sp, #520 */
/* @0x1ed950 str r9, [sp, #0x204] */
/* @0x1ed954 vstr s16, [sp, #500] */
/* @0x1ed958 vmov s12, r3 */
/* @0x1ed95c ldr r3, [r10, #-0x2b4] */
/* @0x1ed960 str r9, [sp, #0x1f0] */
/* @0x1ed964 vstr s16, [sp, #492] */
/* @0x1ed968 str r9, [sp, #0x1dc] */
/* @0x1ed96c vstr s16, [sp, #488] */
/* @0x1ed970 str r9, [sp, #0x1c8] */
/* @0x1ed974 vstr s16, [sp, #484] */
/* @0x1ed978 vstr s16, [sp, #480] */
/* @0x1ed97c vstr s16, [sp, #472] */
/* @0x1ed980 vstr s16, [sp, #468] */
/* @0x1ed984 vstr s16, [sp, #464] */
/* @0x1ed988 vstr s16, [sp, #460] */
/* @0x1ed98c vstr s16, [sp, #512] */
/* @0x1ed990 str r9, [sp, #0x244] */
/* @0x1ed994 vstr s16, [sp, #576] */
/* @0x1ed998 str r9, [sp, #0x230] */
/* @0x1ed99c vstr s16, [sp, #572] */
/* @0x1ed9a0 vstr s16, [sp, #568] */
/* @0x1ed9a4 vstr s16, [sp, #564] */
/* @0x1ed9a8 vstr s16, [sp, #556] */
/* @0x1ed9ac vstr s16, [sp, #552] */
/* @0x1ed9b0 vstr s16, [sp, #548] */
/* @0x1ed9b4 vstr s16, [sp, #544] */
/* @0x1ed9b8 vstr s16, [sp, #536] */
/* @0x1ed9bc vstr s16, [sp, #532] */
/* @0x1ed9c0 vstr s16, [sp, #528] */
/* @0x1ed9c4 vstr s16, [sp, #524] */
/* @0x1ed9c8 add r4, sp, #712 */
/* @0x1ed9cc vmul.f32 s13, s15, s12 */
/* @0x1ed9d0 vstr s14, [sp, #504] */
/* @0x1ed9d4 vmov s12, r3 */
/* @0x1ed9d8 vstr s14, [sp, #508] */
/* @0x1ed9dc vmul.f32 s15, s15, s12 */
/* @0x1ed9e0 vstr s13, [sp, #520] */
/* @0x1ed9e4 vstr s15, [sp, #540] */
/* @0x1ed9e8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ed9ec mov r2, r6 */
/* @0x1ed9f0 add r6, sp, #648 */
/* @0x1ed9f4 mov r1, r8 */
/* @0x1ed9f8 mov r0, r6 */
/* @0x1ed9fc bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eda00 mov r1, r6 */
/* @0x1eda04 mov r0, r4 */
/* @0x1eda08 add r2, sp, #328 */
/* @0x1eda0c bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eda10 ldr r0, [r11, #0x54] */
/* @0x1eda14 ldr r1, [pc, #0x1d8] */
/* @0x1eda18 vstr s16, [sp, #832] */
/* @0x1eda1c str r9, [sp, #0x344] */
/* @0x1eda20 vstr s16, [sp, #820] */
/* @0x1eda24 str r9, [sp, #0x330] */
/* @0x1eda28 vstr s16, [sp, #812] */
/* @0x1eda2c vstr s16, [sp, #808] */
/* @0x1eda30 vstr s16, [sp, #804] */
/* @0x1eda34 vstr s16, [sp, #800] */
/* @0x1eda38 mov r2, #1056964608 */
/* @0x1eda3c mov r3, #939524096 */
/* @0x1eda40 str r2, [sp, #0x338] */
/* @0x1eda44 str r2, [sp, #0x33c] */
/* @0x1eda48 vstr s16, [sp, #792] */
/* @0x1eda4c str r3, [sp, #0x31c] */
/* @0x1eda50 vstr s16, [sp, #788] */
/* @0x1eda54 vstr s16, [sp, #784] */
/* @0x1eda58 vstr s16, [sp, #780] */
/* @0x1eda5c str r3, [sp, #0x308] */
/* @0x1eda60 ldr r8, [r0] */
/* @0x1eda64 ldr r3, [r7, r1] */
/* @0x1eda68 ldrsh r0, [r8, #20] */
/* @0x1eda6c ldr r6, [r3] */
/* @0x1eda70 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1eda74 cmp r0, #0 */
/* @0x1eda78 beq 0x1ee4bc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd54> */
/* @0x1eda7c ldr r3, [pc, #0x174] */
/* @0x1eda80 adds r6, r6, #0 */
/* @0x1eda84 ldrsh r2, [r8, #20] */
/* @0x1eda88 movne r6, #1 */
/* @0x1eda8c str r6, [sp, #0xa4] */
/* @0x1eda90 ldr r3, [r7, r3] */
/* @0x1eda94 ldrsh r0, [r8] */
/* @0x1eda98 ldrsh r8, [r8, #2] */
/* @0x1eda9c ldr r3, [r3, #0x4] */
/* @0x1edaa0 vmov s18, r0 */
/* @0x1edaa4 vmov s16, r8 */
/* @0x1edaa8 ldr r3, [r3, r2, lsl #2] */
/* @0x1edaac vcvt.f32.s32 s18, s18 */
/* @0x1edab0 ldr r3, [r3] */
/* @0x1edab4 ldr r1, [r3, #0x4] */
/* @0x1edab8 ldr r2, [r3, #0x8] */
/* @0x1edabc vcvt.f32.s32 s16, s16 */
/* @0x1edac0 str r3, [sp, #0xa0] */
/* @0x1edac4 vmov s12, r1 */
/* @0x1edac8 str r1, [sp, #0x7c] */
/* @0x1edacc vmov s13, r2 */
/* @0x1edad0 str r2, [sp, #0x78] */
/* @0x1edad4 vcvt.f32.s32 s14, s12 */
/* @0x1edad8 vcvt.f32.s32 s15, s13 */
/* @0x1edadc vdiv.f32 s18, s18, s14 */
/* @0x1edae0 vdiv.f32 s16, s16, s15 */
/* @0x1edae4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edae8 vldr s17, [pc, #308] */
/* @0x1edaec add r6, sp, #840 */
/* @0x1edaf0 ldr lr, [pc, #0x104] */
/* @0x1edaf4 add r9, sp, #248 */
/* @0x1edaf8 mov r12, r6 */
/* @0x1edafc str r6, [sp, #0x98] */
/* @0x1edb00 add lr, pc, lr */
/* @0x1edb04 str r9, [sp, #0x90] */
/* @0x1edb08 stm r12!, {r0, r1, r2, r3} */
/* @0x1edb0c mov r6, #0 */
/* @0x1edb10 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edb14 mov r9, #228 */
/* @0x1edb18 stm r12!, {r0, r1, r2, r3} */
/* @0x1edb1c ldm r4!, {r0, r1, r2, r3} */
/* @0x1edb20 stm r12!, {r0, r1, r2, r3} */
/* @0x1edb24 ldm r4, {r0, r1, r2, r3} */
/* @0x1edb28 stm r12, {r0, r1, r2, r3} */
/* @0x1edb2c ldm lr, {r0, r1, r2, r3} */
/* @0x1edb30 ldr r12, [pc, #0xe0] */
/* @0x1edb34 ldr r10, [sp, #0x90] */
/* @0x1edb38 stm r10, {r0, r1, r2, r3} */
/* @0x1edb3c ldr r12, [r7, r12] */
/* @0x1edb40 str r12, [sp, #0x84] */
/* @0x1edb44 ldr r12, [r12] */
/* @0x1edb48 cmp r6, r12 */
/* @0x1edb4c bge 0x1edd98 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x630> */
/* @0x1edb50 ldr r3, [pc, #0xc8] */
/* @0x1edb54 mul r4, r9, r6 */
/* @0x1edb58 ldr r10, [sp, #0x88] */
/* @0x1edb5c ldr r3, [r7, r3] */
/* @0x1edb60 add r8, r3, r4 */
/* @0x1edb64 str r3, [sp, #0x80] */
/* @0x1edb68 ldr r3, [r8, #0x8] */
/* @0x1edb6c cmp r3, r10 */
/* @0x1edb70 addge r6, r6, #1 */
/* @0x1edb74 bge 0x1edb48 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x3e0> */
/* @0x1edb78 mov r0, r5 */
/* @0x1edb7c mov r1, #29 */
/* @0x1edb80 mov r2, #8 */
/* @0x1edb84 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edb88 mov r0, r5 */
/* @0x1edb8c mov r1, #28 */
/* @0x1edb90 mov r2, #8 */
/* @0x1edb94 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edb98 mov r0, r5 */
/* @0x1edb9c mov r1, #24 */
/* @0x1edba0 mov r2, #0 */
/* @0x1edba4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edba8 mov r0, r5 */
/* @0x1edbac mov r2, #0 */
/* @0x1edbb0 mov r1, #4 */
/* @0x1edbb4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edbb8 ldr r0, [r11, #0x80] */
/* @0x1edbbc ldr r12, [sp, #0x80] */
/* @0x1edbc0 cmp r0, #0 */
/* @0x1edbc4 ldr r2, [r11, #0x7c] */
/* @0x1edbc8 ldr lr, [r12, r4] */
/* @0x1edbcc ble 0x1edc4c <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4e4> */
/* @0x1edbd0 ldr r12, [r2] */
/* @0x1edbd4 ldr r3, [r12, #0x4] */
/* @0x1edbd8 cmp lr, r3 */
/* @0x1edbdc beq 0x1edc50 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4e8> */
/* @0x1edbe0 b 0x1edc28 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4c0> */
/* @0x1edbe4 cmnmi pc, #0 */
/* @0x1edbe8 andhi r0, r0, r0 */
/* @0x1edbec eoreq r4, r0, r12, asr #9 */
/* @0x1edbf0 .word 0xfffff184 */
/* @0x1edbf4 .word 0xffffe828 */
/* @0x1edbf8 .word 0xffffbccc */
/* @0x1edbfc andseq r0, r7, r4, asr #8 */
/* @0x1edc00 .word 0xffffc978 */
/* @0x1edc04 .word 0xffffe4f4 */
/* @0x1edc08 .word 0xffffe4f8 */
/* @0x1edc0c .word 0xffffbcd0 */
/* @0x1edc10 .word 0xfffff198 */
/* @0x1edc14 .word 0xfffff19c */
/* @0x1edc18 .word 0xfffff1a0 */
/* @0x1edc1c .word 0xffffc0a8 */
/* @0x1edc20 .word 0xfffff1a4 */
/* @0x1edc24 andeq r0, r0, r0 */
/* @0x1edc28 mov r3, #0 */
/* @0x1edc2c b 0x1edc40 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4d8> */
/* @0x1edc30 ldr r12, [r2, #0x4]! */
/* @0x1edc34 ldr r1, [r12, #0x4] */
/* @0x1edc38 cmp lr, r1 */
/* @0x1edc3c beq 0x1edc50 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4e8> */
/* @0x1edc40 add r3, r3, #1 */
/* @0x1edc44 cmp r3, r0 */
/* @0x1edc48 bne 0x1edc30 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x4c8> */
/* @0x1edc4c mov r12, #0 */
/* @0x1edc50 vstr s17, [sp, #56] */
/* @0x1edc54 mov r3, #0 */
/* @0x1edc58 str r3, [sp, #0x3c] */
/* @0x1edc5c add r0, r8, #76 */
/* @0x1edc60 ldrb lr, [r8, #0xd4] */
/* @0x1edc64 add r3, r8, #196 */
/* @0x1edc68 str r0, [sp, #0x44] */
/* @0x1edc6c add r1, r8, #144 */
/* @0x1edc70 str r3, [sp, #0x54] */
/* @0x1edc74 add r2, r8, #164 */
/* @0x1edc78 str r3, [sp, #0x58] */
/* @0x1edc7c add r3, r8, #180 */
/* @0x1edc80 str lr, [sp, #0x40] */
/* @0x1edc84 add r4, r8, #20 */
/* @0x1edc88 str r1, [sp, #0x48] */
/* @0x1edc8c mov lr, sp */
/* @0x1edc90 str r2, [sp, #0x4c] */
/* @0x1edc94 add r10, r8, #12 */
/* @0x1edc98 str r3, [sp, #0x50] */
/* @0x1edc9c ldr r3, [r8, #0xd8] */
/* @0x1edca0 str r3, [sp, #0x5c] */
/* @0x1edca4 ldr r3, [r8, #0xdc] */
/* @0x1edca8 str r3, [sp, #0x60] */
/* @0x1edcac ldr r3, [r8, #0xe0] */
/* @0x1edcb0 str r3, [sp, #0x64] */
/* @0x1edcb4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edcb8 stm lr!, {r0, r1, r2, r3} */
/* @0x1edcbc ldm r4!, {r0, r1, r2, r3} */
/* @0x1edcc0 stm lr!, {r0, r1, r2, r3} */
/* @0x1edcc4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1edcc8 stm lr!, {r0, r1, r2, r3} */
/* @0x1edccc ldm r4, {r0, r1} */
/* @0x1edcd0 stm lr, {r0, r1} */
/* @0x1edcd4 mov r1, r12 */
/* @0x1edcd8 ldm r10, {r2, r3} */
/* @0x1edcdc mov r0, r11 */
/* @0x1edce0 bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1edce4 ldr r10, [sp, #0x84] */
/* @0x1edce8 mov r0, r5 */
/* @0x1edcec mov r1, #30 */
/* @0x1edcf0 ldr r2, [r10] */
/* @0x1edcf4 sub r2, r2, #1 */
/* @0x1edcf8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edcfc mov r0, r5 */
/* @0x1edd00 mov r1, #29 */
/* @0x1edd04 mov r2, #3 */
/* @0x1edd08 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd0c mov r0, r5 */
/* @0x1edd10 mov r1, #28 */
/* @0x1edd14 mov r2, #1 */
/* @0x1edd18 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd1c ldr r3, [pc, #-0x114] */
/* @0x1edd20 mov r0, r5 */
/* @0x1edd24 mov r1, #24 */
/* @0x1edd28 ldr r3, [r7, r3] */
/* @0x1edd2c ldr r2, [r3] */
/* @0x1edd30 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd34 ldr r3, [pc, #-0x128] */
/* @0x1edd38 mov r0, r5 */
/* @0x1edd3c mov r1, #4 */
/* @0x1edd40 ldr r3, [r7, r3] */
/* @0x1edd44 ldr r2, [r3] */
/* @0x1edd48 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1edd4c ldr r4, [r10] */
/* @0x1edd50 sub r8, r4, #1 */
/* @0x1edd54 str r8, [r10] */
/* @0x1edd58 cmp r6, r8 */
/* @0x1edd5c bge 0x1edd8c <_ZN7CSprite9DrawShapeEiiifffffjjf+0x624> */
/* @0x1edd60 ldr r12, [sp, #0x80] */
/* @0x1edd64 mla r10, r6, r9, r9 */
/* @0x1edd68 mla r4, r9, r4, r12 */
/* @0x1edd6c add r10, r12, r10 */
/* @0x1edd70 sub r0, r10, #228 */
/* @0x1edd74 mov r1, r10 */
/* @0x1edd78 mov r2, #228 */
/* @0x1edd7c add r10, r10, r2 */
/* @0x1edd80 bl 0xb65bc <memcpy@plt> */
/* @0x1edd84 cmp r10, r4 */
/* @0x1edd88 bne 0x1edd70 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x608> */
/* @0x1edd8c mov r12, r8 */
/* @0x1edd90 cmp r6, r12 */
/* @0x1edd94 blt 0x1edb50 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x3e8> */
/* @0x1edd98 ldr r0, [r11, #0x80] */
/* @0x1edd9c ldr r2, [r11, #0x7c] */
/* @0x1edda0 cmp r0, #0 */
/* @0x1edda4 ble 0x1edde4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x67c> */
/* @0x1edda8 ldr r4, [r2] */
/* @0x1eddac ldr r6, [sp, #0x8c] */
/* @0x1eddb0 ldr r3, [r4, #0x4] */
/* @0x1eddb4 cmp r6, r3 */
/* @0x1eddb8 beq 0x1edde8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x680> */
/* @0x1eddbc mov r3, #0 */
/* @0x1eddc0 mov lr, r6 */
/* @0x1eddc4 b 0x1eddd8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x670> */
/* @0x1eddc8 ldr r4, [r2, #0x4]! */
/* @0x1eddcc ldr r1, [r4, #0x4] */
/* @0x1eddd0 cmp lr, r1 */
/* @0x1eddd4 beq 0x1edde8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x680> */
/* @0x1eddd8 add r3, r3, #1 */
/* @0x1edddc cmp r3, r0 */
/* @0x1edde0 bne 0x1eddc8 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x660> */
/* @0x1edde4 mov r4, #0 */
/* @0x1edde8 ldr r9, [sp, #0xa8] */
/* @0x1eddec cmp r9, #0 */
/* @0x1eddf0 bgt 0x1edfe4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x87c> */
/* @0x1eddf4 cmp r12, #0 */
/* @0x1eddf8 add r9, sp, #184 */
/* @0x1eddfc add r10, sp, #216 */
/* @0x1ede00 add r12, sp, #776 */
/* @0x1ede04 add r6, sp, #200 */
/* @0x1ede08 str r9, [sp, #0x80] */
/* @0x1ede0c str r10, [sp, #0x9c] */
/* @0x1ede10 str r12, [sp, #0x6c] */
/* @0x1ede14 str r6, [sp, #0x88] */
/* @0x1ede18 beq 0x1ee734 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xfcc> */
/* @0x1ede1c ldr r3, [pc, #-0x224] */
/* @0x1ede20 ldr r3, [r7, r3] */
/* @0x1ede24 ldrb r9, [r3] */
/* @0x1ede28 cmp r9, #0 */
/* @0x1ede2c vmoveq.f32 s15, #1.000000e+00 */
/* @0x1ede30 beq 0x1ee5cc <_ZN7CSprite9DrawShapeEiiifffffjjf+0xe64> */
/* @0x1ede34 add r3, sp, #904 */
/* @0x1ede38 add r8, sp, #968 */
/* @0x1ede3c add r6, sp, #1024 */
/* @0x1ede40 mov r0, #2 */
/* @0x1ede44 mov r1, r3 */
/* @0x1ede48 add r6, r6, #8 */
/* @0x1ede4c str r3, [sp, #0x70] */
/* @0x1ede50 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ede54 mov r1, r8 */
/* @0x1ede58 mov r0, #0 */
/* @0x1ede5c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ede60 mov r1, r6 */
/* @0x1ede64 mov r0, #1 */
/* @0x1ede68 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x1ede6c ldr r3, [sp, #0x70] */
/* @0x1ede70 mov r2, r8 */
/* @0x1ede74 add r8, sp, #1088 */
/* @0x1ede78 add r8, r8, #8 */
/* @0x1ede7c mov r1, r3 */
/* @0x1ede80 mov r0, r8 */
/* @0x1ede84 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1ede88 mov r2, r6 */
/* @0x1ede8c add r6, sp, #1152 */
/* @0x1ede90 mov r1, r8 */
/* @0x1ede94 add r6, r6, #8 */
/* @0x1ede98 mov r0, r6 */
/* @0x1ede9c bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1edea0 add r0, sp, #1216 */
/* @0x1edea4 mov r2, r6 */
/* @0x1edea8 add r0, r0, #8 */
/* @0x1edeac add r1, sp, #840 */
/* @0x1edeb0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1edeb4 ldr r2, [pc, #-0x2b8] */
/* @0x1edeb8 ldr r3, [pc, #-0x2b8] */
/* @0x1edebc vldr s14, [pc, #-672] */
/* @0x1edec0 vmov.f32 s15, s14 */
/* @0x1edec4 ldr r1, [pc, #-0x2c0] */
/* @0x1edec8 ldr r12, [r7, r2] */
/* @0x1edecc vldr s2, [r12] */
/* @0x1eded0 ldr r0, [r7, r3] */
/* @0x1eded4 vldr s3, [r0] */
/* @0x1eded8 ldr r10, [sp, #0x6c] */
/* @0x1ededc add r2, sp, #288 */
/* @0x1edee0 vcvt.f32.s32 s2, s2 */
/* @0x1edee4 add r3, sp, #304 */
/* @0x1edee8 add r0, sp, #320 */
/* @0x1edeec mov lr, #1065353216 */
/* @0x1edef0 vstr s14, [sp, #280] */
/* @0x1edef4 vstr s14, [sp, #284] */
/* @0x1edef8 vstr s14, [sp, #292] */
/* @0x1edefc str lr, [sp, #0x120] */
/* @0x1edf00 str lr, [sp, #0x12c] */
/* @0x1edf04 vstr s14, [sp, #296] */
/* @0x1edf08 ldr r1, [r7, r1] */
/* @0x1edf0c vldr s11, [r1] */
/* @0x1edf10 vcvt.f32.s32 s3, s3 */
/* @0x1edf14 vmov.f32 s12, s14 */
/* @0x1edf18 add r12, sp, #2048 */
/* @0x1edf1c add lr, sp, #2048 */
/* @0x1edf20 vldr s13, [r12, #-796] */
/* @0x1edf24 vldr s14, [lr, #-808] */
/* @0x1edf28 vmul.f32 s13, s15, s13 */
/* @0x1edf2c add r6, sp, #2048 */
/* @0x1edf30 add r12, sp, #2048 */
/* @0x1edf34 vldr s4, [r6, #-812] */
/* @0x1edf38 vldr s5, [r12, #-824] */
/* @0x1edf3c add lr, sp, #2048 */
/* @0x1edf40 add r6, sp, #2048 */
/* @0x1edf44 vldr s6, [lr, #-780] */
/* @0x1edf48 vldr s7, [r6, #-792] */
/* @0x1edf4c add r12, sp, #2048 */
/* @0x1edf50 add lr, sp, #2048 */
/* @0x1edf54 vldr s8, [r12, #-764] */
/* @0x1edf58 vldr s9, [lr, #-776] */
/* @0x1edf5c vldr s10, [r1] */
/* @0x1edf60 add r6, sp, #2048 */
/* @0x1edf64 add r12, sp, #2048 */
/* @0x1edf68 add lr, sp, #2048 */
/* @0x1edf6c cmp r3, r0 */
/* @0x1edf70 add r2, r2, #8 */
/* @0x1edf74 add r3, r3, #8 */
/* @0x1edf78 vmul.f32 s14, s15, s14 */
/* @0x1edf7c vmla.f32 s13, s12, s4 */
/* @0x1edf80 vmla.f32 s14, s12, s5 */
/* @0x1edf84 vmla.f32 s13, s11, s6 */
/* @0x1edf88 vmla.f32 s14, s11, s7 */
/* @0x1edf8c vadd.f32 s13, s13, s8 */
/* @0x1edf90 vadd.f32 s14, s14, s9 */
/* @0x1edf94 vdiv.f32 s14, s14, s13 */
/* @0x1edf98 vmul.f32 s14, s2, s14 */
/* @0x1edf9c vstr s14, [r3, #-8] */
/* @0x1edfa0 vldr s14, [r6, #-804] */
/* @0x1edfa4 vmul.f32 s15, s15, s14 */
/* @0x1edfa8 vldr s8, [r12, #-820] */
/* @0x1edfac vldr s9, [lr, #-788] */
/* @0x1edfb0 add r6, sp, #2048 */
/* @0x1edfb4 vldr s14, [r6, #-772] */
/* @0x1edfb8 vmla.f32 s15, s12, s8 */
/* @0x1edfbc vmla.f32 s15, s10, s9 */
/* @0x1edfc0 vadd.f32 s15, s15, s14 */
/* @0x1edfc4 vdiv.f32 s15, s15, s13 */
/* @0x1edfc8 vmul.f32 s15, s3, s15 */
/* @0x1edfcc vmov.f32 s11, s10 */
/* @0x1edfd0 vstr s15, [r3, #-4] */
/* @0x1edfd4 beq 0x1ee4f4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd8c> */
/* @0x1edfd8 vldr s12, [r2, #-8] */
/* @0x1edfdc vldr s15, [r2, #-4] */
/* @0x1edfe0 b 0x1edf18 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x7b0> */
/* @0x1edfe4 ldr r3, [pc, #-0x3cc] */
/* @0x1edfe8 mov r6, #228 */
/* @0x1edfec mul r6, r6, r12 */
/* @0x1edff0 add r10, sp, #184 */
/* @0x1edff4 str r10, [sp, #0x80] */
/* @0x1edff8 add r9, sp, #216 */
/* @0x1edffc ldr r8, [r7, r3] */
/* @0x1ee000 add r12, r12, #1 */
/* @0x1ee004 ldm r10, {r0, r1, r2, r3} */
/* @0x1ee008 add lr, r8, r6 */
/* @0x1ee00c ldr r10, [sp, #0x8c] */
/* @0x1ee010 str r9, [sp, #0x9c] */
/* @0x1ee014 add r9, r6, #144 */
/* @0x1ee018 str r12, [sp, #0x74] */
/* @0x1ee01c add r9, r9, r8 */
/* @0x1ee020 ldr r12, [sp, #0xa8] */
/* @0x1ee024 str r10, [r8, r6] */
/* @0x1ee028 add r10, sp, #776 */
/* @0x1ee02c add r6, lr, #164 */
/* @0x1ee030 str r10, [sp, #0x6c] */
/* @0x1ee034 str r12, [lr, #0x8] */
/* @0x1ee038 add r12, lr, #180 */
/* @0x1ee03c stm r9, {r0, r1, r2, r3} */
/* @0x1ee040 mov r8, r10 */
/* @0x1ee044 ldr r9, [sp, #0x90] */
/* @0x1ee048 add r10, sp, #200 */
/* @0x1ee04c str r6, [sp, #0x8c] */
/* @0x1ee050 add r6, lr, #76 */
/* @0x1ee054 ldm r9, {r0, r1, r2, r3} */
/* @0x1ee058 add r9, lr, #196 */
/* @0x1ee05c stm r12, {r0, r1, r2, r3} */
/* @0x1ee060 ldr r12, [sp, #0x9c] */
/* @0x1ee064 ldm r12, {r0, r1, r2, r3} */
/* @0x1ee068 add r12, sp, #840 */
/* @0x1ee06c stm r9, {r0, r1, r2, r3} */
/* @0x1ee070 ldm r8!, {r0, r1, r2, r3} */
/* @0x1ee074 ldr r9, [sp, #0x88] */
/* @0x1ee078 str r10, [sp, #0x88] */
/* @0x1ee07c str r9, [lr, #0x4] */
/* @0x1ee080 add r9, lr, #12 */
/* @0x1ee084 stm r6!, {r0, r1, r2, r3} */
/* @0x1ee088 ldm r8!, {r0, r1, r2, r3} */
/* @0x1ee08c stm r6!, {r0, r1, r2, r3} */
/* @0x1ee090 ldm r8!, {r0, r1, r2, r3} */
/* @0x1ee094 stm r6!, {r0, r1, r2, r3} */
/* @0x1ee098 ldm r8, {r0, r1, r2, r3} */
/* @0x1ee09c stm r6, {r0, r1, r2, r3} */
/* @0x1ee0a0 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee0a4 ldr r6, [sp, #0x94] */
/* @0x1ee0a8 str r6, [lr, #0x8c] */
/* @0x1ee0ac stm r9!, {r0, r1, r2, r3} */
/* @0x1ee0b0 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee0b4 stm r9!, {r0, r1, r2, r3} */
/* @0x1ee0b8 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee0bc stm r9!, {r0, r1, r2, r3} */
/* @0x1ee0c0 ldm r12, {r0, r1, r2, r3} */
/* @0x1ee0c4 stm r9, {r0, r1, r2, r3} */
/* @0x1ee0c8 ldm r10, {r0, r1, r2, r3} */
/* @0x1ee0cc ldr r9, [sp, #0x8c] */
/* @0x1ee0d0 ldr r10, [sp, #0xac] */
/* @0x1ee0d4 ldr r12, [sp, #0xa4] */
/* @0x1ee0d8 ldr r6, [sp, #0xa0] */
/* @0x1ee0dc stm r9, {r0, r1, r2, r3} */
/* @0x1ee0e0 vstr s18, [lr, #220] */
/* @0x1ee0e4 vstr s16, [lr, #224] */
/* @0x1ee0e8 mov r0, r5 */
/* @0x1ee0ec str r10, [lr, #0xa0] */
/* @0x1ee0f0 mov r1, #25 */
/* @0x1ee0f4 ldr r10, [sp, #0x84] */
/* @0x1ee0f8 mov r2, #1 */
/* @0x1ee0fc ldr r9, [sp, #0x74] */
/* @0x1ee100 strb r12, [lr, #0xd4] */
/* @0x1ee104 str r6, [lr, #0xd8] */
/* @0x1ee108 str r9, [r10] */
/* @0x1ee10c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee110 mov r0, r5 */
/* @0x1ee114 mov r1, #29 */
/* @0x1ee118 mov r2, #8 */
/* @0x1ee11c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee120 mov r0, r5 */
/* @0x1ee124 mov r1, #28 */
/* @0x1ee128 mov r2, #7 */
/* @0x1ee12c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee130 mov r0, r5 */
/* @0x1ee134 mov r1, #24 */
/* @0x1ee138 mov r2, #0 */
/* @0x1ee13c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee140 mov r0, r5 */
/* @0x1ee144 mov r1, #4 */
/* @0x1ee148 mov r2, #0 */
/* @0x1ee14c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee150 ldr r3, [r10] */
/* @0x1ee154 cmp r3, #0 */
/* @0x1ee158 beq 0x1ee734 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xfcc> */
/* @0x1ee15c ldr r9, [sp, #0xa4] */
/* @0x1ee160 add r12, sp, #848 */
/* @0x1ee164 ldr r10, [sp, #0x6c] */
/* @0x1ee168 vstr s18, [sp, #96] */
/* @0x1ee16c ldr r6, [sp, #0x80] */
/* @0x1ee170 vstr s16, [sp, #100] */
/* @0x1ee174 str r9, [sp, #0x40] */
/* @0x1ee178 mov lr, sp */
/* @0x1ee17c ldr r9, [sp, #0x88] */
/* @0x1ee180 mov r8, #1065353216 */
/* @0x1ee184 str r10, [sp, #0x44] */
/* @0x1ee188 add r10, sp, #248 */
/* @0x1ee18c str r6, [sp, #0x48] */
/* @0x1ee190 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee194 ldr r6, [sp, #0x9c] */
/* @0x1ee198 str r9, [sp, #0x4c] */
/* @0x1ee19c ldr r9, [sp, #0xa0] */
/* @0x1ee1a0 str r10, [sp, #0x50] */
/* @0x1ee1a4 str r6, [sp, #0x54] */
/* @0x1ee1a8 mov r6, #0 */
/* @0x1ee1ac str r9, [sp, #0x5c] */
/* @0x1ee1b0 str r6, [sp, #0x3c] */
/* @0x1ee1b4 add r6, sp, #232 */
/* @0x1ee1b8 str r8, [sp, #0x38] */
/* @0x1ee1bc str r6, [sp, #0x58] */
/* @0x1ee1c0 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee1c4 ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee1c8 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee1cc ldm r12!, {r0, r1, r2, r3} */
/* @0x1ee1d0 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee1d4 ldm r12, {r0, r1} */
/* @0x1ee1d8 ldr r10, [sp, #0x98] */
/* @0x1ee1dc ldm r10, {r2, r3} */
/* @0x1ee1e0 stm lr, {r0, r1} */
/* @0x1ee1e4 mov r0, r11 */
/* @0x1ee1e8 mov r1, r4 */
/* @0x1ee1ec bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1ee1f0 ldr r6, [sp, #0x84] */
/* @0x1ee1f4 mov r0, r5 */
/* @0x1ee1f8 mov r1, #30 */
/* @0x1ee1fc ldr r2, [r6] */
/* @0x1ee200 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee204 mov r0, r5 */
/* @0x1ee208 mov r1, #29 */
/* @0x1ee20c mov r2, #3 */
/* @0x1ee210 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee214 mov r0, r5 */
/* @0x1ee218 mov r1, #28 */
/* @0x1ee21c mov r2, #1 */
/* @0x1ee220 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee224 ldr r3, [pc, #-0x61c] */
/* @0x1ee228 mov r0, r5 */
/* @0x1ee22c mov r1, #24 */
/* @0x1ee230 ldr r3, [r7, r3] */
/* @0x1ee234 ldr r2, [r3] */
/* @0x1ee238 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee23c ldr r3, [pc, #-0x630] */
/* @0x1ee240 mov r0, r5 */
/* @0x1ee244 mov r1, #4 */
/* @0x1ee248 ldr r3, [r7, r3] */
/* @0x1ee24c ldr r2, [r3] */
/* @0x1ee250 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee254 ldr r3, [sp, #0xb0] */
/* @0x1ee258 mov r0, r5 */
/* @0x1ee25c mov r1, #0 */
/* @0x1ee260 mov r2, #2 */
/* @0x1ee264 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ee268 mov r0, r5 */
/* @0x1ee26c ldr r3, [sp, #0xb4] */
/* @0x1ee270 mov r1, #0 */
/* @0x1ee274 mov r2, #3 */
/* @0x1ee278 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1ee27c add sp, sp, #1280 */
/* @0x1ee280 add sp, sp, #12 */
/* @0x1ee284 vpop {d8, d9} */
/* @0x1ee288 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ee28c ldr r3, [pc, #-0x67c] */
/* @0x1ee290 ldr r3, [r7, r3] */
/* @0x1ee294 str r3, [sp, #0x84] */
/* @0x1ee298 ldr r3, [r3] */
/* @0x1ee29c cmp r3, #0 */
/* @0x1ee2a0 ldr r3, [pc, #-0x68c] */
/* @0x1ee2a4 ble 0x1ee4ec <_ZN7CSprite9DrawShapeEiiifffffjjf+0xd84> */
/* @0x1ee2a8 ldr r5, [r7, r3] */
/* @0x1ee2ac mov r1, #29 */
/* @0x1ee2b0 mov r2, #8 */
/* @0x1ee2b4 mov r0, r5 */
/* @0x1ee2b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2bc mov r0, r5 */
/* @0x1ee2c0 mov r1, #28 */
/* @0x1ee2c4 mov r2, #8 */
/* @0x1ee2c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2cc mov r0, r5 */
/* @0x1ee2d0 mov r1, #24 */
/* @0x1ee2d4 mov r2, #0 */
/* @0x1ee2d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2dc mov r0, r5 */
/* @0x1ee2e0 mov r1, #4 */
/* @0x1ee2e4 mov r2, #0 */
/* @0x1ee2e8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee2ec ldr r12, [sp, #0x84] */
/* @0x1ee2f0 ldr r3, [r12] */
/* @0x1ee2f4 cmp r3, #0 */
/* @0x1ee2f8 ble 0x1ee410 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xca8> */
/* @0x1ee2fc ldr r3, [pc, #-0x6e4] */
/* @0x1ee300 mov r9, #0 */
/* @0x1ee304 mov r8, r9 */
/* @0x1ee308 vldr s16, [pc, #856] */
/* @0x1ee30c ldr r6, [r7, r3] */
/* @0x1ee310 str r7, [sp, #0x80] */
/* @0x1ee314 mov r7, r12 */
/* @0x1ee318 add r6, r6, #224 */
/* @0x1ee31c ldr r0, [r11, #0x80] */
/* @0x1ee320 sub r10, r6, #224 */
/* @0x1ee324 ldr lr, [r6, #-0xe0] */
/* @0x1ee328 cmp r0, #0 */
/* @0x1ee32c ldr r2, [r11, #0x7c] */
/* @0x1ee330 ble 0x1ee368 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xc00> */
/* @0x1ee334 ldr r12, [r2] */
/* @0x1ee338 ldr r3, [r12, #0x4] */
/* @0x1ee33c cmp lr, r3 */
/* @0x1ee340 beq 0x1ee36c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xc04> */
/* @0x1ee344 mov r3, #0 */
/* @0x1ee348 b 0x1ee35c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xbf4> */
/* @0x1ee34c ldr r12, [r2, #0x4]! */
/* @0x1ee350 ldr r1, [r12, #0x4] */
/* @0x1ee354 cmp lr, r1 */
/* @0x1ee358 beq 0x1ee36c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xc04> */
/* @0x1ee35c add r3, r3, #1 */
/* @0x1ee360 cmp r3, r0 */
/* @0x1ee364 bne 0x1ee34c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xbe4> */
/* @0x1ee368 mov r12, #0 */
/* @0x1ee36c vstr s16, [sp, #56] */
/* @0x1ee370 str r8, [sp, #0x3c] */
/* @0x1ee374 ldrb r2, [r6, #-0xc] */
/* @0x1ee378 sub r3, r6, #28 */
/* @0x1ee37c sub r0, r6, #148 */
/* @0x1ee380 str r3, [sp, #0x54] */
/* @0x1ee384 str r3, [sp, #0x58] */
/* @0x1ee388 sub r1, r6, #80 */
/* @0x1ee38c str r2, [sp, #0x40] */
/* @0x1ee390 sub r3, r6, #44 */
/* @0x1ee394 str r0, [sp, #0x44] */
/* @0x1ee398 sub r2, r6, #60 */
/* @0x1ee39c str r1, [sp, #0x48] */
/* @0x1ee3a0 add r4, r10, #20 */
/* @0x1ee3a4 str r2, [sp, #0x4c] */
/* @0x1ee3a8 mov lr, sp */
/* @0x1ee3ac str r3, [sp, #0x50] */
/* @0x1ee3b0 add r10, r10, #12 */
/* @0x1ee3b4 ldr r3, [r6, #-0x8] */
/* @0x1ee3b8 add r9, r9, #1 */
/* @0x1ee3bc str r3, [sp, #0x5c] */
/* @0x1ee3c0 ldr r3, [r6, #-0x4] */
/* @0x1ee3c4 str r3, [sp, #0x60] */
/* @0x1ee3c8 ldr r3, [r6], #228 */
/* @0x1ee3cc str r3, [sp, #0x64] */
/* @0x1ee3d0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ee3d4 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee3d8 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ee3dc stm lr!, {r0, r1, r2, r3} */
/* @0x1ee3e0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ee3e4 stm lr!, {r0, r1, r2, r3} */
/* @0x1ee3e8 ldm r4, {r0, r1} */
/* @0x1ee3ec stm lr, {r0, r1} */
/* @0x1ee3f0 mov r1, r12 */
/* @0x1ee3f4 ldm r10, {r2, r3} */
/* @0x1ee3f8 mov r0, r11 */
/* @0x1ee3fc bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1ee400 ldr r3, [r7] */
/* @0x1ee404 cmp r3, r9 */
/* @0x1ee408 bgt 0x1ee31c <_ZN7CSprite9DrawShapeEiiifffffjjf+0xbb4> */
/* @0x1ee40c ldr r7, [sp, #0x80] */
/* @0x1ee410 ldr r10, [sp, #0x84] */
/* @0x1ee414 mov r2, #0 */
/* @0x1ee418 ldr r3, [pc, #0x254] */
/* @0x1ee41c mov r0, r5 */
/* @0x1ee420 mov r1, #30 */
/* @0x1ee424 str r2, [r10] */
/* @0x1ee428 ldr r3, [r7, r3] */
/* @0x1ee42c ldr r2, [r3] */
/* @0x1ee430 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee434 ldr r3, [pc, #0x23c] */
/* @0x1ee438 mov r0, r5 */
/* @0x1ee43c mov r1, #25 */
/* @0x1ee440 ldr r3, [r7, r3] */
/* @0x1ee444 ldr r2, [r3] */
/* @0x1ee448 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee44c ldr r3, [pc, #0x228] */
/* @0x1ee450 mov r0, r5 */
/* @0x1ee454 mov r1, #29 */
/* @0x1ee458 ldr r3, [r7, r3] */
/* @0x1ee45c ldr r2, [r3] */
/* @0x1ee460 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee464 ldr r3, [pc, #0x214] */
/* @0x1ee468 mov r0, r5 */
/* @0x1ee46c mov r1, #28 */
/* @0x1ee470 ldr r3, [r7, r3] */
/* @0x1ee474 ldr r2, [r3] */
/* @0x1ee478 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee47c ldr r3, [pc, #0x200] */
/* @0x1ee480 mov r0, r5 */
/* @0x1ee484 mov r1, #24 */
/* @0x1ee488 ldr r3, [r7, r3] */
/* @0x1ee48c ldr r2, [r3] */
/* @0x1ee490 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee494 ldr r3, [pc, #0x1ec] */
/* @0x1ee498 mov r0, r5 */
/* @0x1ee49c mov r1, #4 */
/* @0x1ee4a0 ldr r3, [r7, r3] */
/* @0x1ee4a4 ldr r2, [r3] */
/* @0x1ee4a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee4ac add sp, sp, #1280 */
/* @0x1ee4b0 add sp, sp, #12 */
/* @0x1ee4b4 vpop {d8, d9} */
/* @0x1ee4b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ee4bc str r0, [sp, #0xa0] */
/* @0x1ee4c0 vmov.f32 s18, s16 */
/* @0x1ee4c4 str r0, [sp, #0xa4] */
/* @0x1ee4c8 b 0x1edae4 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x37c> */
/* @0x1ee4cc cmp r3, #0 */
/* @0x1ee4d0 lslge r2, r3, #24 */
/* @0x1ee4d4 movlt r2, #0 */
/* @0x1ee4d8 b 0x1ed818 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xb0> */
/* @0x1ee4dc cmp r3, r2 */
/* @0x1ee4e0 lslge r3, r3, #24 */
/* @0x1ee4e4 movlt r3, r2 */
/* @0x1ee4e8 b 0x1ed880 <_ZN7CSprite9DrawShapeEiiifffffjjf+0x118> */
/* @0x1ee4ec ldr r5, [r7, r3] */
/* @0x1ee4f0 b 0x1ee410 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xca8> */
/* @0x1ee4f4 vldr s12, [sp, #304] */
/* @0x1ee4f8 vldr s14, [sp, #312] */
/* @0x1ee4fc vsub.f32 s14, s14, s12 */
/* @0x1ee500 vldr s13, [sp, #308] */
/* @0x1ee504 vldr s15, [sp, #316] */
/* @0x1ee508 vldr s10, [sp, #320] */
/* @0x1ee50c vldr s11, [sp, #324] */
/* @0x1ee510 str r10, [sp, #0x6c] */
/* @0x1ee514 vmul.f32 s17, s14, s14 */
/* @0x1ee518 vstr s14, [sp, #264] */
/* @0x1ee51c vsub.f32 s15, s15, s13 */
/* @0x1ee520 vmla.f32 s17, s15, s15 */
/* @0x1ee524 vstr s15, [sp, #268] */
/* @0x1ee528 vsub.f32 s12, s10, s12 */
/* @0x1ee52c vsub.f32 s13, s11, s13 */
/* @0x1ee530 vstr s12, [sp, #272] */
/* @0x1ee534 vcmpe.f32 s17, #0 */
/* @0x1ee538 vstr s13, [sp, #276] */
/* @0x1ee53c vmrs APSR_nzcv, fpscr */
/* @0x1ee540 ble 0x1ee558 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xdf0> */
/* @0x1ee544 vsqrt.f32 s15, s17 */
/* @0x1ee548 vcmp.f32 s15, s15 */
/* @0x1ee54c vmrs APSR_nzcv, fpscr */
/* @0x1ee550 bne 0x1ee748 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xfe0> */
/* @0x1ee554 vmov.f32 s17, s15 */
/* @0x1ee558 vldr s15, [sp, #272] */
/* @0x1ee55c vldr s14, [sp, #276] */
/* @0x1ee560 vldr s13, [pc, #256] */
/* @0x1ee564 vmul.f32 s15, s15, s15 */
/* @0x1ee568 vmla.f32 s15, s14, s14 */
/* @0x1ee56c vcmpe.f32 s17, #0 */
/* @0x1ee570 vmrs APSR_nzcv, fpscr */
/* @0x1ee574 vcmpe.f32 s15, s13 */
/* @0x1ee578 vmovle.f32 s17, s13 */
/* @0x1ee57c vmrs APSR_nzcv, fpscr */
/* @0x1ee580 ble 0x1ee598 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xe30> */
/* @0x1ee584 vsqrt.f32 s14, s15 */
/* @0x1ee588 vcmp.f32 s14, s14 */
/* @0x1ee58c vmrs APSR_nzcv, fpscr */
/* @0x1ee590 bne 0x1ee758 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xff0> */
/* @0x1ee594 vmov.f32 s15, s14 */
/* @0x1ee598 ldr r3, [pc, #0xcc] */
/* @0x1ee59c vmov.f32 s14, #5.000000e-01 */
/* @0x1ee5a0 ldr r3, [r7, r3] */
/* @0x1ee5a4 vcmp.f32 s15, s17 */
/* @0x1ee5a8 vmrs APSR_nzcv, fpscr */
/* @0x1ee5ac vmovgt.f32 s17, s15 */
/* @0x1ee5b0 vmul.f32 s17, s17, s14 */
/* @0x1ee5b4 vldr s14, [r3] */
/* @0x1ee5b8 vmov.f32 s15, #1.000000e+00 */
/* @0x1ee5bc vcmpe.f32 s17, #0 */
/* @0x1ee5c0 vmrs APSR_nzcv, fpscr */
/* @0x1ee5c4 vdivgt.f32 s15, s15, s17 */
/* @0x1ee5c8 vmul.f32 s15, s15, s14 */
/* @0x1ee5cc str r9, [sp, #0x3c] */
/* @0x1ee5d0 add lr, sp, #848 */
/* @0x1ee5d4 ldr r9, [sp, #0xa4] */
/* @0x1ee5d8 vstr s15, [sp, #56] */
/* @0x1ee5dc ldr r6, [sp, #0x80] */
/* @0x1ee5e0 vstr s18, [sp, #96] */
/* @0x1ee5e4 ldr r10, [sp, #0x6c] */
/* @0x1ee5e8 mov r12, sp */
/* @0x1ee5ec str r9, [sp, #0x40] */
/* @0x1ee5f0 ldr r9, [sp, #0x88] */
/* @0x1ee5f4 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ee5f8 vstr s16, [sp, #100] */
/* @0x1ee5fc str r6, [sp, #0x48] */
/* @0x1ee600 str r9, [sp, #0x4c] */
/* @0x1ee604 ldr r6, [sp, #0x9c] */
/* @0x1ee608 ldr r9, [sp, #0xa0] */
/* @0x1ee60c str r10, [sp, #0x44] */
/* @0x1ee610 add r10, sp, #248 */
/* @0x1ee614 str r6, [sp, #0x54] */
/* @0x1ee618 add r6, sp, #232 */
/* @0x1ee61c str r10, [sp, #0x50] */
/* @0x1ee620 str r9, [sp, #0x5c] */
/* @0x1ee624 str r6, [sp, #0x58] */
/* @0x1ee628 stm r12!, {r0, r1, r2, r3} */
/* @0x1ee62c ldm lr!, {r0, r1, r2, r3} */
/* @0x1ee630 stm r12!, {r0, r1, r2, r3} */
/* @0x1ee634 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ee638 stm r12!, {r0, r1, r2, r3} */
/* @0x1ee63c ldm lr, {r0, r1} */
/* @0x1ee640 ldr r10, [sp, #0x98] */
/* @0x1ee644 ldm r10, {r2, r3} */
/* @0x1ee648 stm r12, {r0, r1} */
/* @0x1ee64c mov r0, r11 */
/* @0x1ee650 mov r1, r4 */
/* @0x1ee654 bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x1ee658 ldr r12, [sp, #0xa8] */
/* @0x1ee65c cmp r12, #0 */
/* @0x1ee660 bgt 0x1ee1f0 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xa88> */
/* @0x1ee664 b 0x1ee254 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xaec> */
/* @0x1ee668 andeq r0, r0, r0 */
/* @0x1ee66c .word 0xffffc968 */
/* @0x1ee670 .word 0xffffc0a8 */
/* @0x1ee674 .word 0xfffff1a8 */
/* @0x1ee678 .word 0xfffff1ac */
/* @0x1ee67c .word 0xfffff1b0 */
/* @0x1ee680 .word 0xfffff1b4 */
/* @0x1ee684 .word 0xfffff198 */
/* @0x1ee688 .word 0xfffff19c */
/* @0x1ee68c ldr r3, [pc, #-0x24] */
/* @0x1ee690 mov r1, #30 */
/* @0x1ee694 ldr r4, [r7, r3] */
/* @0x1ee698 mov r0, r4 */
/* @0x1ee69c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6a0 ldr r3, [pc, #-0x34] */
/* @0x1ee6a4 mov r1, #25 */
/* @0x1ee6a8 ldr r3, [r7, r3] */
/* @0x1ee6ac str r0, [r3] */
/* @0x1ee6b0 mov r0, r4 */
/* @0x1ee6b4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6b8 ldr r3, [pc, #-0x48] */
/* @0x1ee6bc mov r1, #29 */
/* @0x1ee6c0 ldr r3, [r7, r3] */
/* @0x1ee6c4 str r0, [r3] */
/* @0x1ee6c8 mov r0, r4 */
/* @0x1ee6cc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6d0 ldr r3, [pc, #-0x5c] */
/* @0x1ee6d4 mov r1, #28 */
/* @0x1ee6d8 ldr r3, [r7, r3] */
/* @0x1ee6dc str r0, [r3] */
/* @0x1ee6e0 mov r0, r4 */
/* @0x1ee6e4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee6e8 ldr r3, [pc, #-0x70] */
/* @0x1ee6ec mov r1, #24 */
/* @0x1ee6f0 ldr r3, [r7, r3] */
/* @0x1ee6f4 str r0, [r3] */
/* @0x1ee6f8 mov r0, r4 */
/* @0x1ee6fc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee700 ldr r3, [pc, #-0x84] */
/* @0x1ee704 mov r1, #4 */
/* @0x1ee708 ldr r3, [r7, r3] */
/* @0x1ee70c str r0, [r3] */
/* @0x1ee710 mov r0, r4 */
/* @0x1ee714 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x1ee718 ldr r3, [pc, #-0x98] */
/* @0x1ee71c ldr r3, [r7, r3] */
/* @0x1ee720 str r0, [r3] */
/* @0x1ee724 add sp, sp, #1280 */
/* @0x1ee728 add sp, sp, #12 */
/* @0x1ee72c vpop {d8, d9} */
/* @0x1ee730 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ee734 mov r0, r5 */
/* @0x1ee738 mov r1, #25 */
/* @0x1ee73c mov r2, #0 */
/* @0x1ee740 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1ee744 b 0x1ede1c <_ZN7CSprite9DrawShapeEiiifffffjjf+0x6b4> */
/* @0x1ee748 vmov r0, s17 */
/* @0x1ee74c bl 0xb6700 <sqrtf@plt> */
/* @0x1ee750 vmov s15, r0 */
/* @0x1ee754 b 0x1ee554 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xdec> */
/* @0x1ee758 vmov r0, s15 */
/* @0x1ee75c bl 0xb6700 <sqrtf@plt> */
/* @0x1ee760 vmov s14, r0 */
/* @0x1ee764 b 0x1ee594 <_ZN7CSprite9DrawShapeEiiifffffjjf+0xe2c> */

/* ── FUNC 0x1ee768 · CSprite::DrawShapeString(int, char const*, float, float, float, float, float, unsigned int, unsigned int, float) · size=4 · insn=1 */
/* @0x1ee768 bx lr */

/* ── FUNC 0x1ee76c · FINALIZE_Sprite_Class() · size=4 · insn=1 */
/* @0x1ee76c bx lr */

/* ── FUNC 0x1ee770 · ASYNCFunc_SpriteCleanup(HTTP_REQ_CONTEXT*) · size=8 · insn=2 */
/* @0x1ee770 ldr r0, [r0, #0x1c] */
/* @0x1ee774 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x1ee778 · CHashMap<char const*, int, 7>::~CHashMap() · size=40 · insn=10 */
/* @0x1ee778 push {r4, lr} */
/* @0x1ee77c mov r4, r0 */
/* @0x1ee780 ldr r0, [r0, #0x10] */
/* @0x1ee784 cmp r0, #0 */
/* @0x1ee788 beq 0x1ee798 <_ZN8CHashMapIPKciLi7EED2Ev+0x20> */
/* @0x1ee78c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ee790 mov r3, #0 */
/* @0x1ee794 str r3, [r4, #0x10] */
/* @0x1ee798 mov r0, r4 */
/* @0x1ee79c pop {r4, pc} */

/* ── FUNC 0x1ee778 · CHashMap<char const*, int, 7>::~CHashMap() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1ee7a0 · ASYNCFunc_SpriteAdd(HTTP_REQ_CONTEXT*, void*, int*) · size=740 · insn=185 */
/* @0x1ee7a0 vmov.f64 d7, #-1.000000e+00 */
/* @0x1ee7a4 vldr s10, [r1] */
/* @0x1ee7a8 vldr s12, [r0, #40] */
/* @0x1ee7ac push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ee7b0 mov r7, r1 */
/* @0x1ee7b4 ldr r1, [r0, #0x3c] */
/* @0x1ee7b8 sub sp, sp, #56 */
/* @0x1ee7bc mov r12, #0 */
/* @0x1ee7c0 mov r8, r2 */
/* @0x1ee7c4 cmp r1, r12 */
/* @0x1ee7c8 ldr r1, [pc, #0x294] */
/* @0x1ee7cc ldr r2, [r0, #0x20] */
/* @0x1ee7d0 mov r4, #0 */
/* @0x1ee7d4 add r1, pc, r1 */
/* @0x1ee7d8 ldr r3, [pc, #0x288] */
/* @0x1ee7dc str r1, [sp, #0x24] */
/* @0x1ee7e0 mov r5, #0 */
/* @0x1ee7e4 ldr lr, [pc, #0x280] */
/* @0x1ee7e8 mov r6, r0 */
/* @0x1ee7ec vcvt.f64.s32 d5, s10 */
/* @0x1ee7f0 ldr r1, [pc, #0x278] */
/* @0x1ee7f4 vmovgt d7, r4, r5 */
/* @0x1ee7f8 add r3, pc, r3 */
/* @0x1ee7fc add lr, pc, lr */
/* @0x1ee800 stm sp, {r2, r3} */
/* @0x1ee804 str r12, [sp, #0x10] */
/* @0x1ee808 mov r3, r5 */
/* @0x1ee80c str r12, [sp, #0x20] */
/* @0x1ee810 mov r0, #4 */
/* @0x1ee814 str r12, [sp, #0x30] */
/* @0x1ee818 mov r2, r4 */
/* @0x1ee81c str lr, [sp, #0x14] */
/* @0x1ee820 add r1, pc, r1 */
/* @0x1ee824 vcvt.f64.s32 d6, s12 */
/* @0x1ee828 vstr d5, [sp, #8] */
/* @0x1ee82c vstr d7, [sp, #40] */
/* @0x1ee830 vstr d6, [sp, #24] */
/* @0x1ee834 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1ee838 str r0, [r8] */
/* @0x1ee83c ldr r3, [r6, #0x28] */
/* @0x1ee840 ldr r12, [r7, #0x10] */
/* @0x1ee844 cmp r3, #200 */
/* @0x1ee848 beq 0x1ee858 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xb8> */
/* @0x1ee84c mov r0, #60 */
/* @0x1ee850 add sp, sp, #56 */
/* @0x1ee854 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ee858 ldr r2, [r6, #0x3c] */
/* @0x1ee85c cmp r2, #0 */
/* @0x1ee860 ble 0x1ee84c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xac> */
/* @0x1ee864 ldr r4, [pc, #0x208] */
/* @0x1ee868 ldr r1, [r7] */
/* @0x1ee86c ldr r4, [pc, r4] */
/* @0x1ee870 ldr r3, [r4, #0x4] */
/* @0x1ee874 ldr r0, [r3, r1, lsl #2] */
/* @0x1ee878 cmp r0, #0 */
/* @0x1ee87c beq 0x1ee84c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xac> */
/* @0x1ee880 ldr r5, [r6, #0x34] */
/* @0x1ee884 ands r1, r12, #2 */
/* @0x1ee888 movne r8, #0 */
/* @0x1ee88c moveq r8, #1 */
/* @0x1ee890 ldrb r3, [r5] */
/* @0x1ee894 cmp r3, #255 */
/* @0x1ee898 beq 0x1ee90c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x16c> */
/* @0x1ee89c cmp r3, #71 */
/* @0x1ee8a0 bne 0x1ee9e0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x240> */
/* @0x1ee8a4 ldrb r3, [r5, #0x1] */
/* @0x1ee8a8 cmp r3, #73 */
/* @0x1ee8ac beq 0x1ee970 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x1d0> */
/* @0x1ee8b0 ldr r3, [pc, #0x1c0] */
/* @0x1ee8b4 ldr r1, [pc, #0x1c0] */
/* @0x1ee8b8 ldr r3, [pc, r3] */
/* @0x1ee8bc ldr r2, [r6, #0x20] */
/* @0x1ee8c0 add r1, pc, r1 */
/* @0x1ee8c4 ldr r0, [r3] */
/* @0x1ee8c8 ldr r3, [r0] */
/* @0x1ee8cc ldr r3, [r3, #0xc] */
/* @0x1ee8d0 blx r3 */
/* @0x1ee8d4 ldr r2, [pc, #0x1a4] */
/* @0x1ee8d8 ldr r3, [r7] */
/* @0x1ee8dc ldr r2, [pc, r2] */
/* @0x1ee8e0 ldr r12, [r4, #0x4] */
/* @0x1ee8e4 ldr r1, [r2] */
/* @0x1ee8e8 mov r0, r3 */
/* @0x1ee8ec ldr r2, [r12, r3, lsl #2] */
/* @0x1ee8f0 ldr r1, [r1, r3, lsl #2] */
/* @0x1ee8f4 str r3, [r2, #0x60] */
/* @0x1ee8f8 str r1, [r2, #0x5c] */
/* @0x1ee8fc bl 0x130cac <_Z20MarkInstancesAsDirtyi> */
/* @0x1ee900 mov r0, #60 */
/* @0x1ee904 add sp, sp, #56 */
/* @0x1ee908 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ee90c ldrb r3, [r5, #0x1] */
/* @0x1ee910 cmp r3, #216 */
/* @0x1ee914 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1ee918 ldrb r3, [r5, #0x2] */
/* @0x1ee91c cmp r3, #255 */
/* @0x1ee920 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1ee924 ldr r10, [r7, #0x8] */
/* @0x1ee928 adds r1, r1, #0 */
/* @0x1ee92c ldr r9, [r7, #0xc] */
/* @0x1ee930 and lr, r12, #1 */
/* @0x1ee934 ldr r3, [r7, #0x4] */
/* @0x1ee938 movne r1, #1 */
/* @0x1ee93c ubfx r12, r12, #0x2, #0x1 */
/* @0x1ee940 str r1, [sp, #0x4] */
/* @0x1ee944 str r8, [sp, #0x14] */
/* @0x1ee948 mov r1, r5 */
/* @0x1ee94c str r10, [sp, #0xc] */
/* @0x1ee950 str r9, [sp, #0x10] */
/* @0x1ee954 str lr, [sp] */
/* @0x1ee958 str r12, [sp, #0x8] */
/* @0x1ee95c bl 0x1e7140 <_ZN7CSprite16LoadFromJPEGDataEPviibbbiib> */
/* @0x1ee960 cmp r0, #0 */
/* @0x1ee964 bne 0x1ee8d4 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x134> */
/* @0x1ee968 ldrb r3, [r5] */
/* @0x1ee96c b 0x1ee89c <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0xfc> */
/* @0x1ee970 ldrb r3, [r5, #0x2] */
/* @0x1ee974 cmp r3, #70 */
/* @0x1ee978 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1ee97c ldrb r3, [r5, #0x3] */
/* @0x1ee980 cmp r3, #56 */
/* @0x1ee984 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1ee988 ldr r2, [r4, #0x4] */
/* @0x1ee98c ldr r1, [r7, #0xc] */
/* @0x1ee990 ldr r0, [r7] */
/* @0x1ee994 ldr r12, [r7, #0x8] */
/* @0x1ee998 ldr r3, [r7, #0x10] */
/* @0x1ee99c str r8, [sp, #0x14] */
/* @0x1ee9a0 str r12, [sp, #0xc] */
/* @0x1ee9a4 ubfx lr, r3, #0x1, #0x1 */
/* @0x1ee9a8 str r1, [sp, #0x10] */
/* @0x1ee9ac and r9, r3, #1 */
/* @0x1ee9b0 str lr, [sp, #0x4] */
/* @0x1ee9b4 ubfx r3, r3, #0x2, #0x1 */
/* @0x1ee9b8 str r9, [sp] */
/* @0x1ee9bc str r3, [sp, #0x8] */
/* @0x1ee9c0 ldr r0, [r2, r0, lsl #2] */
/* @0x1ee9c4 ldr r1, [r6, #0x34] */
/* @0x1ee9c8 ldr r2, [r6, #0x3c] */
/* @0x1ee9cc ldr r3, [r7, #0x4] */
/* @0x1ee9d0 bl 0x1e71d8 <_ZN7CSprite15LoadFromGIFDataEPviibbbiib> */
/* @0x1ee9d4 cmp r0, #0 */
/* @0x1ee9d8 bne 0x1ee8d4 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x134> */
/* @0x1ee9dc ldrb r3, [r5] */
/* @0x1ee9e0 cmp r3, #137 */
/* @0x1ee9e4 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1ee9e8 ldrb r3, [r5, #0x1] */
/* @0x1ee9ec cmp r3, #80 */
/* @0x1ee9f0 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1ee9f4 ldrb r3, [r5, #0x2] */
/* @0x1ee9f8 cmp r3, #78 */
/* @0x1ee9fc bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1eea00 ldrb r3, [r5, #0x3] */
/* @0x1eea04 cmp r3, #71 */
/* @0x1eea08 bne 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1eea0c ldr r2, [r4, #0x4] */
/* @0x1eea10 ldr r1, [r7, #0xc] */
/* @0x1eea14 ldr r0, [r7] */
/* @0x1eea18 ldr r12, [r7, #0x8] */
/* @0x1eea1c ldr r3, [r7, #0x10] */
/* @0x1eea20 str r8, [sp, #0x14] */
/* @0x1eea24 str r12, [sp, #0xc] */
/* @0x1eea28 ubfx lr, r3, #0x1, #0x1 */
/* @0x1eea2c str r1, [sp, #0x10] */
/* @0x1eea30 and r5, r3, #1 */
/* @0x1eea34 str lr, [sp, #0x4] */
/* @0x1eea38 ubfx r3, r3, #0x2, #0x1 */
/* @0x1eea3c str r5, [sp] */
/* @0x1eea40 str r3, [sp, #0x8] */
/* @0x1eea44 ldr r0, [r2, r0, lsl #2] */
/* @0x1eea48 ldr r1, [r6, #0x34] */
/* @0x1eea4c ldr r2, [r6, #0x3c] */
/* @0x1eea50 ldr r3, [r7, #0x4] */
/* @0x1eea54 bl 0x1e70b0 <_ZN7CSprite15LoadFromPNGDataEPviibbbiib> */
/* @0x1eea58 cmp r0, #0 */
/* @0x1eea5c bne 0x1ee8d4 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x134> */
/* @0x1eea60 b 0x1ee8b0 <_Z19ASYNCFunc_SpriteAddP16HTTP_REQ_CONTEXTPvPi+0x110> */
/* @0x1eea64 andseq r2, r4, r12, ror r2 */
/* @0x1eea68 andseq r2, r4, r8, asr #4 */
/* @0x1eea6c andseq r2, r4, r8, asr #4 */
/* @0x1eea70 andseq r2, r4, r4, lsl r2 */
/* @0x1eea74 mlaeq r0, r12, r5, r2 */
/* @0x1eea78 andseq lr, pc, r12, asr lr */
/* @0x1eea7c mulseq r4, r8, r1 */
/* @0x1eea80 eoreq r2, r0, r0, lsr r5 */

/* ── FUNC 0x1eea84 · murmurhash(char const*, unsigned int, unsigned int) · size=260 · insn=65 */
/* @0x1eea84 push {r4, r5, r6, r7, r8, r9} */
/* @0x1eea88 lsr r8, r1, #2 */
/* @0x1eea8c rsb r7, r8, #0 */
/* @0x1eea90 cmp r7, #0 */
/* @0x1eea94 add r9, r0, r8, lsl #2 */
/* @0x1eea98 beq 0x1eeaf0 <_Z10murmurhashPKcjj+0x6c> */
/* @0x1eea9c rsb r6, r7, r7, lsl #30 */
/* @0x1eeaa0 movw r5, #0x2d51 */
/* @0x1eeaa4 movw r4, #0x3593 */
/* @0x1eeaa8 add r7, r9, r7, lsl #2 */
/* @0x1eeaac lsl r6, r6, #2 */
/* @0x1eeab0 movt r5, #0xcc9e */
/* @0x1eeab4 movt r4, #0x1b87 */
/* @0x1eeab8 mov r3, #0 */
/* @0x1eeabc ldr r12, [r7, r3] */
/* @0x1eeac0 add r3, r3, #4 */
/* @0x1eeac4 cmp r3, r6 */
/* @0x1eeac8 mul r12, r5, r12 */
/* @0x1eeacc ror r12, r12, #17 */
/* @0x1eead0 mul r12, r4, r12 */
/* @0x1eead4 eor r12, r2, r12 */
/* @0x1eead8 movw r2, #0x6b64 */
/* @0x1eeadc movt r2, #0xe654 */
/* @0x1eeae0 ror r12, r12, #19 */
/* @0x1eeae4 add r12, r12, r12, lsl #2 */
/* @0x1eeae8 add r2, r12, r2 */
/* @0x1eeaec bne 0x1eeabc <_Z10murmurhashPKcjj+0x38> */
/* @0x1eeaf0 and r3, r1, #3 */
/* @0x1eeaf4 cmp r3, #2 */
/* @0x1eeaf8 beq 0x1eeb80 <_Z10murmurhashPKcjj+0xfc> */
/* @0x1eeafc cmp r3, #3 */
/* @0x1eeb00 beq 0x1eeb6c <_Z10murmurhashPKcjj+0xe8> */
/* @0x1eeb04 cmp r3, #1 */
/* @0x1eeb08 beq 0x1eeb3c <_Z10murmurhashPKcjj+0xb8> */
/* @0x1eeb0c eor r2, r2, r1 */
/* @0x1eeb10 movw r12, #0xca6b */
/* @0x1eeb14 movt r12, #0x85eb */
/* @0x1eeb18 movw r3, #0xae35 */
/* @0x1eeb1c eor r2, r2, r2, lsr #16 */
/* @0x1eeb20 movt r3, #0xc2b2 */
/* @0x1eeb24 pop {r4, r5, r6, r7, r8, r9} */
/* @0x1eeb28 mul r0, r12, r2 */
/* @0x1eeb2c eor r0, r0, r0, lsr #13 */
/* @0x1eeb30 mul r0, r3, r0 */
/* @0x1eeb34 eor r0, r0, r0, lsr #16 */
/* @0x1eeb38 bx lr */
/* @0x1eeb3c mov r4, #0 */
/* @0x1eeb40 ldrb r12, [r0, r8, lsl #2] */
/* @0x1eeb44 movw r0, #0x2d51 */
/* @0x1eeb48 movt r0, #0xcc9e */
/* @0x1eeb4c movw r3, #0x3593 */
/* @0x1eeb50 eor r12, r4, r12 */
/* @0x1eeb54 movt r3, #0x1b87 */
/* @0x1eeb58 mul r0, r0, r12 */
/* @0x1eeb5c ror r0, r0, #17 */
/* @0x1eeb60 mul r3, r3, r0 */
/* @0x1eeb64 eor r2, r2, r3 */
/* @0x1eeb68 b 0x1eeb0c <_Z10murmurhashPKcjj+0x88> */
/* @0x1eeb6c ldrb r4, [r9, #0x2] */
/* @0x1eeb70 lsl r4, r4, #16 */
/* @0x1eeb74 ldrb r3, [r9, #0x1] */
/* @0x1eeb78 orr r4, r4, r3, lsl #8 */
/* @0x1eeb7c b 0x1eeb40 <_Z10murmurhashPKcjj+0xbc> */
/* @0x1eeb80 mov r4, #0 */
/* @0x1eeb84 b 0x1eeb74 <_Z10murmurhashPKcjj+0xf0> */

/* ── FUNC 0x1eeb88 · unsigned int CHashMapCalculateHash<char const*>(char const*) · size=32 · insn=8 */
/* @0x1eeb88 push {r4, lr} */
/* @0x1eeb8c mov r4, r0 */
/* @0x1eeb90 bl 0xb6538 <strlen@plt> */
/* @0x1eeb94 mov r2, #0 */
/* @0x1eeb98 mov r1, r0 */
/* @0x1eeb9c mov r0, r4 */
/* @0x1eeba0 pop {r4, lr} */
/* @0x1eeba4 b 0x1eea84 <_Z10murmurhashPKcjj> */

/* ── FUNC 0x1eeba8 · bool CHashMapCompareKeys<char const*>(char const*, char const*) · size=20 · insn=5 */
/* @0x1eeba8 push {r3, lr} */
/* @0x1eebac bl 0xb6574 <strcmp@plt> */
/* @0x1eebb0 rsbs r0, r0, #1 */
/* @0x1eebb4 movlo r0, #0 */
/* @0x1eebb8 pop {r3, pc} */

/* ── FUNC 0x1eebbc · Sprite_Init() · size=384 · insn=96 */
/* @0x1eebbc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1eebc0 ldr r9, [pc, #0x15c] */
/* @0x1eebc4 ldr r3, [pc, #0x15c] */
/* @0x1eebc8 add r9, pc, r9 */
/* @0x1eebcc ldr r7, [r9, r3] */
/* @0x1eebd0 ldr r0, [r7, #0x4] */
/* @0x1eebd4 cmp r0, #0 */
/* @0x1eebd8 beq 0x1eec78 <_Z11Sprite_Initv+0xbc> */
/* @0x1eebdc ldr r3, [pc, #0x148] */
/* @0x1eebe0 ldr r8, [r9, r3] */
/* @0x1eebe4 ldr r3, [r8] */
/* @0x1eebe8 cmp r3, #0 */
/* @0x1eebec ldr r3, [pc, #0x13c] */
/* @0x1eebf0 ldrle r10, [r9, r3] */
/* @0x1eebf4 ble 0x1eec5c <_Z11Sprite_Initv+0xa0> */
/* @0x1eebf8 ldr r10, [r9, r3] */
/* @0x1eebfc mov r4, #0 */
/* @0x1eec00 mov r6, r4 */
/* @0x1eec04 ldr r3, [r0, r4, lsl #2] */
/* @0x1eec08 lsl r5, r4, #2 */
/* @0x1eec0c add r2, r0, r5 */
/* @0x1eec10 add r4, r4, #1 */
/* @0x1eec14 cmp r3, #0 */
/* @0x1eec18 mov r0, r3 */
/* @0x1eec1c beq 0x1eec34 <_Z11Sprite_Initv+0x78> */
/* @0x1eec20 ldr r3, [r3] */
/* @0x1eec24 ldr r3, [r3, #0x4] */
/* @0x1eec28 blx r3 */
/* @0x1eec2c ldr r2, [r7, #0x4] */
/* @0x1eec30 add r2, r2, r5 */
/* @0x1eec34 str r6, [r2] */
/* @0x1eec38 ldr r3, [r10] */
/* @0x1eec3c ldr r0, [r3, r5] */
/* @0x1eec40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec44 ldr r2, [r8] */
/* @0x1eec48 ldr r3, [r10] */
/* @0x1eec4c cmp r2, r4 */
/* @0x1eec50 str r6, [r3, r5] */
/* @0x1eec54 ldr r0, [r7, #0x4] */
/* @0x1eec58 bgt 0x1eec04 <_Z11Sprite_Initv+0x48> */
/* @0x1eec5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec60 ldr r0, [r10] */
/* @0x1eec64 mov r4, #0 */
/* @0x1eec68 str r4, [r7, #0x4] */
/* @0x1eec6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec70 str r4, [r8] */
/* @0x1eec74 str r4, [r10] */
/* @0x1eec78 ldr r3, [pc, #0xb4] */
/* @0x1eec7c ldr r4, [r9, r3] */
/* @0x1eec80 ldr r0, [r4, #0x10] */
/* @0x1eec84 cmp r0, #0 */
/* @0x1eec88 beq 0x1eec90 <_Z11Sprite_Initv+0xd4> */
/* @0x1eec8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eec90 ldr r0, [r4] */
/* @0x1eec94 mov r5, #0 */
/* @0x1eec98 ldr r1, [pc, #0x98] */
/* @0x1eec9c mov r2, #70 */
/* @0x1eeca0 sub r12, r0, #1 */
/* @0x1eeca4 mov r3, #1 */
/* @0x1eeca8 add r0, r0, r0, lsl #1 */
/* @0x1eecac add r1, pc, r1 */
/* @0x1eecb0 str r5, [r4, #0x10] */
/* @0x1eecb4 lsl r6, r0, #2 */
/* @0x1eecb8 str r12, [r4, #0x8] */
/* @0x1eecbc mov r0, r6 */
/* @0x1eecc0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1eecc4 mov r2, r6 */
/* @0x1eecc8 mov r1, r5 */
/* @0x1eeccc str r0, [r4, #0x10] */
/* @0x1eecd0 bl 0xb65b0 <memset@plt> */
/* @0x1eecd4 ldr r2, [r4] */
/* @0x1eecd8 vldr s15, [pc, #64] */
/* @0x1eecdc str r5, [r4, #0x4] */
/* @0x1eece0 cmp r2, r5 */
/* @0x1eece4 vmov s13, r2 */
/* @0x1eece8 vcvt.f32.s32 s14, s13 */
/* @0x1eecec vmul.f32 s15, s14, s15 */
/* @0x1eecf0 vcvt.s32.f32 s15, s15 */
/* @0x1eecf4 vstr s15, [r4, #12] */
/* @0x1eecf8 pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1eecfc ldr r3, [r4, #0x10] */
/* @0x1eed00 add r2, r2, r2, lsl #1 */
/* @0x1eed04 mov r1, r5 */
/* @0x1eed08 add r2, r3, r2, lsl #2 */
/* @0x1eed0c str r1, [r3, #0x8] */
/* @0x1eed10 add r3, r3, #12 */
/* @0x1eed14 cmp r3, r2 */
/* @0x1eed18 bne 0x1eed0c <_Z11Sprite_Initv+0x150> */
/* @0x1eed1c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1eed20 svclo #0x19999a */
/* @0x1eed24 eoreq r3, r0, r8, lsl #1 */
/* @0x1eed28 .word 0xfffff1b8 */
/* @0x1eed2c .word 0xfffff1c0 */
/* @0x1eed30 .word 0xfffff1bc */
/* @0x1eed34 .word 0xfffff1c4 */
/* @0x1eed38 andseq r2, r4, r4, lsl #7 */

/* ── FUNC 0x1eed3c · Sprite_Free() · size=148 · insn=37 */
/* @0x1eed3c ldr r3, [pc, #0x80] */
/* @0x1eed40 ldr r2, [pc, #0x80] */
/* @0x1eed44 add r3, pc, r3 */
/* @0x1eed48 push {r4, r5, r6, lr} */
/* @0x1eed4c ldr r5, [r3, r2] */
/* @0x1eed50 ldr r2, [r5] */
/* @0x1eed54 cmp r2, #0 */
/* @0x1eed58 ldr r2, [pc, #0x6c] */
/* @0x1eed5c ble 0x1eedb8 <_Z11Sprite_Freev+0x7c> */
/* @0x1eed60 ldr r6, [r3, r2] */
/* @0x1eed64 mov r4, #0 */
/* @0x1eed68 ldr r2, [r6, #0x4] */
/* @0x1eed6c ldr r3, [r2, r4, lsl #2] */
/* @0x1eed70 add r4, r4, #1 */
/* @0x1eed74 cmp r3, #0 */
/* @0x1eed78 mov r0, r3 */
/* @0x1eed7c beq 0x1eed90 <_Z11Sprite_Freev+0x54> */
/* @0x1eed80 ldr r3, [r3] */
/* @0x1eed84 ldr r3, [r3, #0x4] */
/* @0x1eed88 blx r3 */
/* @0x1eed8c ldr r2, [r6, #0x4] */
/* @0x1eed90 ldr r3, [r5] */
/* @0x1eed94 cmp r3, r4 */
/* @0x1eed98 bgt 0x1eed6c <_Z11Sprite_Freev+0x30> */
/* @0x1eed9c mov r0, r2 */
/* @0x1eeda0 mov r4, #0 */
/* @0x1eeda4 str r4, [r5] */
/* @0x1eeda8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eedac str r4, [r6, #0x4] */
/* @0x1eedb0 str r4, [r6] */
/* @0x1eedb4 pop {r4, r5, r6, pc} */
/* @0x1eedb8 ldr r6, [r3, r2] */
/* @0x1eedbc ldr r2, [r6, #0x4] */
/* @0x1eedc0 b 0x1eed9c <_Z11Sprite_Freev+0x60> */
/* @0x1eedc4 eoreq r2, r0, r12, lsl #30 */
/* @0x1eedc8 .word 0xfffff1c0 */
/* @0x1eedcc .word 0xfffff1b8 */

/* ── FUNC 0x1eedd0 · Sprite_InitTextures() · size=96 · insn=24 */
/* @0x1eedd0 push {r4, r5, r6, lr} */
/* @0x1eedd4 ldr r6, [pc, #0x4c] */
/* @0x1eedd8 ldr r6, [pc, r6] */
/* @0x1eeddc ldr r3, [r6] */
/* @0x1eede0 cmp r3, #0 */
/* @0x1eede4 pople {r4, r5, r6, pc} */
/* @0x1eede8 ldr r5, [pc, #0x3c] */
/* @0x1eedec mov r4, #0 */
/* @0x1eedf0 ldr r5, [pc, r5] */
/* @0x1eedf4 ldr r3, [r5, #0x4] */
/* @0x1eedf8 ldr r0, [r3, r4, lsl #2] */
/* @0x1eedfc cmp r0, #0 */
/* @0x1eee00 beq 0x1eee14 <_Z19Sprite_InitTexturesv+0x44> */
/* @0x1eee04 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1eee08 ldr r3, [r5, #0x4] */
/* @0x1eee0c ldr r0, [r3, r4, lsl #2] */
/* @0x1eee10 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1eee14 ldr r3, [r6] */
/* @0x1eee18 add r4, r4, #1 */
/* @0x1eee1c cmp r3, r4 */
/* @0x1eee20 bgt 0x1eedf4 <_Z19Sprite_InitTexturesv+0x24> */
/* @0x1eee24 pop {r4, r5, r6, pc} */
/* @0x1eee28 eoreq r2, r0, r8, lsr r0 */
/* @0x1eee2c eoreq r2, r0, r8, lsl r0 */

/* ── FUNC 0x1eee30 · Sprite_FreeTextures() · size=84 · insn=21 */
/* @0x1eee30 push {r4, r5, r6, lr} */
/* @0x1eee34 ldr r5, [pc, #0x40] */
/* @0x1eee38 ldr r5, [pc, r5] */
/* @0x1eee3c ldr r3, [r5] */
/* @0x1eee40 cmp r3, #0 */
/* @0x1eee44 pople {r4, r5, r6, pc} */
/* @0x1eee48 ldr r6, [pc, #0x30] */
/* @0x1eee4c mov r4, #0 */
/* @0x1eee50 ldr r6, [pc, r6] */
/* @0x1eee54 ldr r3, [r6, #0x4] */
/* @0x1eee58 ldr r0, [r3, r4, lsl #2] */
/* @0x1eee5c add r4, r4, #1 */
/* @0x1eee60 cmp r0, #0 */
/* @0x1eee64 beq 0x1eee6c <_Z19Sprite_FreeTexturesv+0x3c> */
/* @0x1eee68 bl 0x1e56fc <_ZN7CSprite11FreeTextureEv> */
/* @0x1eee6c ldr r3, [r5] */
/* @0x1eee70 cmp r3, r4 */
/* @0x1eee74 bgt 0x1eee54 <_Z19Sprite_FreeTexturesv+0x24> */
/* @0x1eee78 pop {r4, r5, r6, pc} */
/* @0x1eee7c .word 0x00201fd8 */
/* @0x1eee80 .word 0x00201fb8 */

/* ── FUNC 0x1eee84 · Sprite_Number() · size=20 · insn=5 */
/* @0x1eee84 ldr r3, [pc, #0x8] */
/* @0x1eee88 ldr r3, [pc, r3] */
/* @0x1eee8c ldr r0, [r3] */
/* @0x1eee90 bx lr */
/* @0x1eee94 eoreq r1, r0, r8, lsl #31 */

/* ── FUNC 0x1eee98 · Sprite_Exists(int) · size=72 · insn=18 */
/* @0x1eee98 cmp r0, #0 */
/* @0x1eee9c blt 0x1eeed0 <_Z13Sprite_Existsi+0x38> */
/* @0x1eeea0 ldr r3, [pc, #0x30] */
/* @0x1eeea4 ldr r3, [pc, r3] */
/* @0x1eeea8 ldr r3, [r3] */
/* @0x1eeeac cmp r0, r3 */
/* @0x1eeeb0 bge 0x1eeed0 <_Z13Sprite_Existsi+0x38> */
/* @0x1eeeb4 ldr r3, [pc, #0x20] */
/* @0x1eeeb8 ldr r3, [pc, r3] */
/* @0x1eeebc ldr r3, [r3, #0x4] */
/* @0x1eeec0 ldr r0, [r3, r0, lsl #2] */
/* @0x1eeec4 adds r0, r0, #0 */
/* @0x1eeec8 movne r0, #1 */
/* @0x1eeecc bx lr */
/* @0x1eeed0 mov r0, #0 */
/* @0x1eeed4 bx lr */
/* @0x1eeed8 eoreq r1, r0, r12, ror #30 */
/* @0x1eeedc eoreq r1, r0, r0, asr pc */

/* ── FUNC 0x1eeee0 · Sprite_Name(int) · size=132 · insn=33 */
/* @0x1eeee0 cmp r0, #0 */
/* @0x1eeee4 blt 0x1eef34 <_Z11Sprite_Namei+0x54> */
/* @0x1eeee8 ldr r3, [pc, #0x5c] */
/* @0x1eeeec ldr r3, [pc, r3] */
/* @0x1eeef0 ldr r3, [r3] */
/* @0x1eeef4 cmp r0, r3 */
/* @0x1eeef8 bge 0x1eef28 <_Z11Sprite_Namei+0x48> */
/* @0x1eeefc ldr r3, [pc, #0x4c] */
/* @0x1eef00 ldr r3, [pc, r3] */
/* @0x1eef04 ldr r3, [r3, #0x4] */
/* @0x1eef08 ldr r3, [r3, r0, lsl #2] */
/* @0x1eef0c cmp r3, #0 */
/* @0x1eef10 beq 0x1eef40 <_Z11Sprite_Namei+0x60> */
/* @0x1eef14 ldr r3, [pc, #0x38] */
/* @0x1eef18 ldr r3, [pc, r3] */
/* @0x1eef1c ldr r3, [r3] */
/* @0x1eef20 ldr r0, [r3, r0, lsl #2] */
/* @0x1eef24 bx lr */
/* @0x1eef28 ldr r0, [pc, #0x28] */
/* @0x1eef2c add r0, pc, r0 */
/* @0x1eef30 bx lr */
/* @0x1eef34 ldr r0, [pc, #0x20] */
/* @0x1eef38 add r0, pc, r0 */
/* @0x1eef3c bx lr */
/* @0x1eef40 ldr r0, [pc, #0x18] */
/* @0x1eef44 add r0, pc, r0 */
/* @0x1eef48 bx lr */
/* @0x1eef4c eoreq r1, r0, r4, lsr #30 */
/* @0x1eef50 eoreq r1, r0, r8, lsl #30 */
/* @0x1eef54 .word 0x00201ef4 */
/* @0x1eef58 mulseq r4, r4, r11 */
/* @0x1eef5c andseq r1, r4, r8, lsl #23 */
/* @0x1eef60 andseq r1, r4, r12, ror r11 */

/* ── FUNC 0x1eef64 · Sprite_Find(char const*) · size=216 · insn=54 */
/* @0x1eef64 push {r4, r5, r6, r7, r8, lr} */
/* @0x1eef68 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1eef6c ldr r2, [pc, #0xc4] */
/* @0x1eef70 ldr r2, [pc, r2] */
/* @0x1eef74 ldr r1, [r2, #0x8] */
/* @0x1eef78 ldr r7, [r2, #0x10] */
/* @0x1eef7c bic r0, r0, #-2147483648 */
/* @0x1eef80 and r3, r0, r1 */
/* @0x1eef84 lsl r4, r3, #1 */
/* @0x1eef88 add r12, r4, r3 */
/* @0x1eef8c add r12, r7, r12, lsl #2 */
/* @0x1eef90 ldr r12, [r12, #0x8] */
/* @0x1eef94 cmp r12, #0 */
/* @0x1eef98 beq 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1eef9c cmp r0, r12 */
/* @0x1eefa0 beq 0x1ef018 <_Z11Sprite_FindPKc+0xb4> */
/* @0x1eefa4 ldr r8, [r2] */
/* @0x1eefa8 and r12, r1, r12 */
/* @0x1eefac add r2, r3, r8 */
/* @0x1eefb0 rsb r12, r12, r2 */
/* @0x1eefb4 tst r12, r1 */
/* @0x1eefb8 bmi 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1eefbc mov r12, #0 */
/* @0x1eefc0 b 0x1eefd4 <_Z11Sprite_FindPKc+0x70> */
/* @0x1eefc4 cmp r0, r2 */
/* @0x1eefc8 beq 0x1ef010 <_Z11Sprite_FindPKc+0xac> */
/* @0x1eefcc cmp r5, r12 */
/* @0x1eefd0 blt 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1eefd4 add r3, r3, #1 */
/* @0x1eefd8 add r12, r12, #1 */
/* @0x1eefdc and r3, r3, r1 */
/* @0x1eefe0 add r6, r3, r8 */
/* @0x1eefe4 lsl r4, r3, #1 */
/* @0x1eefe8 add r2, r4, r3 */
/* @0x1eefec add r2, r7, r2, lsl #2 */
/* @0x1eeff0 ldr r2, [r2, #0x8] */
/* @0x1eeff4 and r5, r1, r2 */
/* @0x1eeff8 cmp r2, #0 */
/* @0x1eeffc rsb r5, r5, r6 */
/* @0x1ef000 and r5, r5, r1 */
/* @0x1ef004 bne 0x1eefc4 <_Z11Sprite_FindPKc+0x60> */
/* @0x1ef008 mvn r0, #0 */
/* @0x1ef00c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ef010 cmn r3, #1 */
/* @0x1ef014 beq 0x1ef030 <_Z11Sprite_FindPKc+0xcc> */
/* @0x1ef018 add r3, r4, r3 */
/* @0x1ef01c add r7, r7, r3, lsl #2 */
/* @0x1ef020 cmn r7, #4 */
/* @0x1ef024 beq 0x1ef008 <_Z11Sprite_FindPKc+0xa4> */
/* @0x1ef028 ldr r0, [r7, #0x4] */
/* @0x1ef02c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ef030 mov r0, r3 */
/* @0x1ef034 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1ef038 eoreq r1, r0, r4, lsr #29 */
