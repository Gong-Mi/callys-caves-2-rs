/* libyoyo.so 覆盖卡组 0165
 * 函数 0x1e5988..0x1e7c8c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1e5988 · CSprite::AddFromBitmap(IBitmap*, bool, bool, bool) · size=420 · insn=105 */
/* @0x1e5988 ldr r12, [r0, #0x18] */
/* @0x1e598c push {r4, r5, r6, r7, r8, lr} */
/* @0x1e5990 cmp r12, #0 */
/* @0x1e5994 sub sp, sp, #8 */
/* @0x1e5998 mov r5, r0 */
/* @0x1e599c mov r4, r1 */
/* @0x1e59a0 mov r7, r2 */
/* @0x1e59a4 mov r6, r3 */
/* @0x1e59a8 ldrb r8, [sp, #0x20] */
/* @0x1e59ac beq 0x1e5af8 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x170> */
/* @0x1e59b0 add r1, r12, #1 */
/* @0x1e59b4 ldr r2, [pc, #0x16c] */
/* @0x1e59b8 add r0, r5, #72 */
/* @0x1e59bc str r1, [r5, #0x18] */
/* @0x1e59c0 movw r3, #0x663 */
/* @0x1e59c4 add r2, pc, r2 */
/* @0x1e59c8 lsl r1, r1, #2 */
/* @0x1e59cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e59d0 ldr r2, [r5, #0x18] */
/* @0x1e59d4 ldr r3, [r5, #0x48] */
/* @0x1e59d8 cmp r8, #0 */
/* @0x1e59dc sub r2, r2, #-1073741823 */
/* @0x1e59e0 ldr r0, [r3, r2, lsl #2] */
/* @0x1e59e4 beq 0x1e5ab4 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x12c> */
/* @0x1e59e8 cmp r0, #0 */
/* @0x1e59ec beq 0x1e59fc <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x74> */
/* @0x1e59f0 ldr r3, [r0] */
/* @0x1e59f4 ldr r3, [r3, #0x4] */
/* @0x1e59f8 blx r3 */
/* @0x1e59fc mov r0, #24 */
/* @0x1e5a00 bl 0x27c524 <_Znwj> */
/* @0x1e5a04 mov r2, r7 */
/* @0x1e5a08 mov r3, r6 */
/* @0x1e5a0c mov r12, #0 */
/* @0x1e5a10 mov r1, r4 */
/* @0x1e5a14 str r12, [sp] */
/* @0x1e5a18 mov r8, r0 */
/* @0x1e5a1c bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi> */
/* @0x1e5a20 ldr r2, [r5, #0x18] */
/* @0x1e5a24 ldr r3, [r5, #0x48] */
/* @0x1e5a28 sub r2, r2, #-1073741823 */
/* @0x1e5a2c str r8, [r3, r2, lsl #2] */
/* @0x1e5a30 ldr r3, [r5, #0x44] */
/* @0x1e5a34 cmp r3, #0 */
/* @0x1e5a38 movgt r4, #0 */
/* @0x1e5a3c ble 0x1e5a5c <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0xd4> */
/* @0x1e5a40 ldr r3, [r5, #0x54] */
/* @0x1e5a44 ldr r0, [r3, r4, lsl #2] */
/* @0x1e5a48 add r4, r4, #1 */
/* @0x1e5a4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e5a50 ldr r3, [r5, #0x44] */
/* @0x1e5a54 cmp r3, r4 */
/* @0x1e5a58 bgt 0x1e5a40 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0xb8> */
/* @0x1e5a5c ldr r0, [r5, #0x54] */
/* @0x1e5a60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e5a64 ldr r3, [r5, #0x18] */
/* @0x1e5a68 ldr r2, [r5, #0x48] */
/* @0x1e5a6c mov r0, #0 */
/* @0x1e5a70 sub r1, r3, #-1073741823 */
/* @0x1e5a74 str r0, [r5, #0x54] */
/* @0x1e5a78 str r3, [r5, #0x44] */
/* @0x1e5a7c ldr r0, [r2, r1, lsl #2] */
/* @0x1e5a80 ldr r1, [r5, #0x1c] */
/* @0x1e5a84 ldr r2, [r5, #0x20] */
/* @0x1e5a88 bl 0x1673ac <_ZN9CBitmap327StretchEii> */
/* @0x1e5a8c mov r0, r5 */
/* @0x1e5a90 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1e5a94 mov r0, r5 */
/* @0x1e5a98 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1e5a9c mov r0, r5 */
/* @0x1e5aa0 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv> */
/* @0x1e5aa4 mov r0, r5 */
/* @0x1e5aa8 add sp, sp, #8 */
/* @0x1e5aac pop {r4, r5, r6, r7, r8, lr} */
/* @0x1e5ab0 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */
/* @0x1e5ab4 cmp r0, #0 */
/* @0x1e5ab8 beq 0x1e5ac8 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x140> */
/* @0x1e5abc ldr r3, [r0] */
/* @0x1e5ac0 ldr r3, [r3, #0x4] */
/* @0x1e5ac4 blx r3 */
/* @0x1e5ac8 mov r0, #24 */
/* @0x1e5acc bl 0x27c524 <_Znwj> */
/* @0x1e5ad0 mov r2, r7 */
/* @0x1e5ad4 mov r3, r6 */
/* @0x1e5ad8 mov r1, r4 */
/* @0x1e5adc mov r8, r0 */
/* @0x1e5ae0 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0x1e5ae4 ldr r2, [r5, #0x18] */
/* @0x1e5ae8 ldr r3, [r5, #0x48] */
/* @0x1e5aec sub r2, r2, #-1073741823 */
/* @0x1e5af0 str r8, [r3, r2, lsl #2] */
/* @0x1e5af4 b 0x1e5a30 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0xa8> */
/* @0x1e5af8 ldr r3, [r1] */
/* @0x1e5afc mov r0, r1 */
/* @0x1e5b00 ldr r3, [r3, #0x10] */
/* @0x1e5b04 blx r3 */
/* @0x1e5b08 ldr r3, [r4] */
/* @0x1e5b0c ldr r3, [r3, #0x18] */
/* @0x1e5b10 str r0, [r5, #0x1c] */
/* @0x1e5b14 mov r0, r4 */
/* @0x1e5b18 blx r3 */
/* @0x1e5b1c ldr r12, [r5, #0x18] */
/* @0x1e5b20 str r0, [r5, #0x20] */
/* @0x1e5b24 b 0x1e59b0 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb+0x28> */
/* @0x1e5b28 andseq r12, r6, r0, ror #20 */

/* ── FUNC 0x1e5b2c · CSprite::AddFromSprite(CSprite*) · size=356 · insn=89 */
/* @0x1e5b2c ldr r3, [r0, #0x18] */
/* @0x1e5b30 push {r4, r5, r6, r7, r8, lr} */
/* @0x1e5b34 cmp r3, #0 */
/* @0x1e5b38 mov r6, r1 */
/* @0x1e5b3c mov r4, r0 */
/* @0x1e5b40 ldreq r2, [r1, #0x1c] */
/* @0x1e5b44 ldreq r3, [r1, #0x20] */
/* @0x1e5b48 ldr r1, [r0, #0x48] */
/* @0x1e5b4c streq r2, [r0, #0x1c] */
/* @0x1e5b50 streq r3, [r0, #0x20] */
/* @0x1e5b54 cmp r1, #0 */
/* @0x1e5b58 beq 0x1e5c64 <_ZN7CSprite13AddFromSpriteEPS_+0x138> */
/* @0x1e5b5c ldr r1, [r6, #0x48] */
/* @0x1e5b60 cmp r1, #0 */
/* @0x1e5b64 beq 0x1e5c74 <_ZN7CSprite13AddFromSpriteEPS_+0x148> */
/* @0x1e5b68 ldr r12, [r4, #0x18] */
/* @0x1e5b6c movw r3, #0x6ae */
/* @0x1e5b70 ldr r1, [r6, #0x18] */
/* @0x1e5b74 add r0, r4, #72 */
/* @0x1e5b78 ldr r2, [pc, #0x104] */
/* @0x1e5b7c add r1, r12, r1 */
/* @0x1e5b80 add r2, pc, r2 */
/* @0x1e5b84 lsl r1, r1, #2 */
/* @0x1e5b88 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e5b8c ldr r2, [r6, #0x18] */
/* @0x1e5b90 ldr r3, [r4, #0x18] */
/* @0x1e5b94 cmp r2, #0 */
/* @0x1e5b98 add r2, r3, r2 */
/* @0x1e5b9c str r2, [r4, #0x44] */
/* @0x1e5ba0 ble 0x1e5c3c <_ZN7CSprite13AddFromSpriteEPS_+0x110> */
/* @0x1e5ba4 mov r5, #0 */
/* @0x1e5ba8 mov r7, r5 */
/* @0x1e5bac b 0x1e5bb4 <_ZN7CSprite13AddFromSpriteEPS_+0x88> */
/* @0x1e5bb0 ldr r3, [r4, #0x18] */
/* @0x1e5bb4 ldr r2, [r4, #0x48] */
/* @0x1e5bb8 add r3, r5, r3 */
/* @0x1e5bbc ldr r3, [r2, r3, lsl #2] */
/* @0x1e5bc0 cmp r3, #0 */
/* @0x1e5bc4 mov r0, r3 */
/* @0x1e5bc8 beq 0x1e5be8 <_ZN7CSprite13AddFromSpriteEPS_+0xbc> */
/* @0x1e5bcc ldr r3, [r3] */
/* @0x1e5bd0 ldr r3, [r3, #0x4] */
/* @0x1e5bd4 blx r3 */
/* @0x1e5bd8 ldr r2, [r4, #0x18] */
/* @0x1e5bdc ldr r3, [r4, #0x48] */
/* @0x1e5be0 add r2, r5, r2 */
/* @0x1e5be4 str r7, [r3, r2, lsl #2] */
/* @0x1e5be8 mov r0, #24 */
/* @0x1e5bec bl 0x27c524 <_Znwj> */
/* @0x1e5bf0 ldr r3, [r6, #0x48] */
/* @0x1e5bf4 ldr r1, [r3, r5, lsl #2] */
/* @0x1e5bf8 mov r8, r0 */
/* @0x1e5bfc bl 0x165f98 <_ZN9CBitmap32C2EPS_> */
/* @0x1e5c00 ldr r3, [r4, #0x18] */
/* @0x1e5c04 ldr r0, [r4, #0x48] */
/* @0x1e5c08 add r3, r5, r3 */
/* @0x1e5c0c ldr r1, [r4, #0x1c] */
/* @0x1e5c10 ldr r2, [r4, #0x20] */
/* @0x1e5c14 add r5, r5, #1 */
/* @0x1e5c18 str r8, [r0, r3, lsl #2] */
/* @0x1e5c1c ldr r0, [r4, #0x48] */
/* @0x1e5c20 ldr r0, [r0, r3, lsl #2] */
/* @0x1e5c24 bl 0x1673ac <_ZN9CBitmap327StretchEii> */
/* @0x1e5c28 ldr r3, [r6, #0x18] */
/* @0x1e5c2c cmp r3, r5 */
/* @0x1e5c30 bgt 0x1e5bb0 <_ZN7CSprite13AddFromSpriteEPS_+0x84> */
/* @0x1e5c34 ldr r2, [r4, #0x18] */
/* @0x1e5c38 add r2, r3, r2 */
/* @0x1e5c3c str r2, [r4, #0x18] */
/* @0x1e5c40 mov r0, r4 */
/* @0x1e5c44 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1e5c48 mov r0, r4 */
/* @0x1e5c4c bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1e5c50 mov r0, r4 */
/* @0x1e5c54 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv> */
/* @0x1e5c58 mov r0, r4 */
/* @0x1e5c5c pop {r4, r5, r6, r7, r8, lr} */
/* @0x1e5c60 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */
/* @0x1e5c64 ldr r0, [pc, #0x1c] */
/* @0x1e5c68 add r0, pc, r0 */
/* @0x1e5c6c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e5c70 b 0x1e5b5c <_ZN7CSprite13AddFromSpriteEPS_+0x30> */
/* @0x1e5c74 ldr r0, [pc, #0x10] */
/* @0x1e5c78 add r0, pc, r0 */
/* @0x1e5c7c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e5c80 b 0x1e5b68 <_ZN7CSprite13AddFromSpriteEPS_+0x3c> */
/* @0x1e5c84 andseq r12, r6, r4, lsr #17 */
/* @0x1e5c88 ldrsheq r12, [r6], -r4 */
/* @0x1e5c8c andseq r12, r6, r12, lsr #16 */

/* ── FUNC 0x1e5c90 · CSprite::SetAlphaFromSprite(CSprite*) · size=212 · insn=53 */
/* @0x1e5c90 push {r3, r4, r5, r6, r7, lr} */
/* @0x1e5c94 mov r6, r1 */
/* @0x1e5c98 ldr r1, [r1, #0x18] */
/* @0x1e5c9c mov r5, r0 */
/* @0x1e5ca0 cmp r1, #0 */
/* @0x1e5ca4 pople {r3, r4, r5, r6, r7, pc} */
/* @0x1e5ca8 ldr r3, [r0, #0x54] */
/* @0x1e5cac cmp r3, #0 */
/* @0x1e5cb0 beq 0x1e5cc0 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x30> */
/* @0x1e5cb4 ldrb r3, [r0, #0x36] */
/* @0x1e5cb8 cmp r3, #0 */
/* @0x1e5cbc beq 0x1e5d48 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0xb8> */
/* @0x1e5cc0 ldr r3, [r6, #0x54] */
/* @0x1e5cc4 cmp r3, #0 */
/* @0x1e5cc8 beq 0x1e5cd8 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x48> */
/* @0x1e5ccc ldrb r3, [r6, #0x36] */
/* @0x1e5cd0 cmp r3, #0 */
/* @0x1e5cd4 beq 0x1e5d34 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0xa4> */
/* @0x1e5cd8 ldr r3, [r5, #0x18] */
/* @0x1e5cdc cmp r3, #0 */
/* @0x1e5ce0 movgt r4, #0 */
/* @0x1e5ce4 bgt 0x1e5cf0 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x60> */
/* @0x1e5ce8 b 0x1e5d20 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x90> */
/* @0x1e5cec ldr r1, [r6, #0x18] */
/* @0x1e5cf0 ldr r3, [r5, #0x48] */
/* @0x1e5cf4 mov r0, r4 */
/* @0x1e5cf8 ldr r7, [r3, r4, lsl #2] */
/* @0x1e5cfc bl 0x318dec <__aeabi_idivmod> */
/* @0x1e5d00 ldr r3, [r6, #0x48] */
/* @0x1e5d04 add r4, r4, #1 */
/* @0x1e5d08 mov r0, r7 */
/* @0x1e5d0c ldr r1, [r3, r1, lsl #2] */
/* @0x1e5d10 bl 0x1672d0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_> */
/* @0x1e5d14 ldr r3, [r5, #0x18] */
/* @0x1e5d18 cmp r3, r4 */
/* @0x1e5d1c bgt 0x1e5cec <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x5c> */
/* @0x1e5d20 mov r0, r5 */
/* @0x1e5d24 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1e5d28 mov r0, r5 */
/* @0x1e5d2c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1e5d30 b 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1e5d34 ldr r0, [pc, #0x20] */
/* @0x1e5d38 mov r1, r3 */
/* @0x1e5d3c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1e5d40 add r0, pc, r0 */
/* @0x1e5d44 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e5d48 ldr r0, [pc, #0x10] */
/* @0x1e5d4c mov r1, r3 */
/* @0x1e5d50 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1e5d54 add r0, pc, r0 */
/* @0x1e5d58 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1e5d5c andseq r12, r6, r0, lsl #16 */
/* @0x1e5d60 mulseq r6, r4, r7 */

/* ── FUNC 0x1e5d64 · CSprite::DrawPos(int, float, float, float, float, float, float, float, float, unsigned int, float) · size=208 · insn=52 */
/* @0x1e5d64 push {r4, r5, r6, r7, lr} */
/* @0x1e5d68 mov r4, r0 */
/* @0x1e5d6c ldr r5, [r0, #0x18] */
/* @0x1e5d70 sub sp, sp, #36 */
/* @0x1e5d74 mov r6, r2 */
/* @0x1e5d78 mov r7, r3 */
/* @0x1e5d7c cmp r5, #0 */
/* @0x1e5d80 ble 0x1e5df8 <_ZN7CSprite7DrawPosEiffffffffjf+0x94> */
/* @0x1e5d84 mov r0, r1 */
/* @0x1e5d88 mov r1, r5 */
/* @0x1e5d8c bl 0x318dec <__aeabi_idivmod> */
/* @0x1e5d90 ldr r0, [r4, #0x54] */
/* @0x1e5d94 cmp r1, #0 */
/* @0x1e5d98 addlt r1, r1, r5 */
/* @0x1e5d9c cmp r0, #0 */
/* @0x1e5da0 beq 0x1e5df8 <_ZN7CSprite7DrawPosEiffffffffjf+0x94> */
/* @0x1e5da4 ldr r3, [sp, #0x50] */
/* @0x1e5da8 vldr s15, [sp, #60] */
/* @0x1e5dac ldr r0, [r0, r1, lsl #2] */
/* @0x1e5db0 mov r2, r7 */
/* @0x1e5db4 vstr s15, [sp] */
/* @0x1e5db8 mov r1, r6 */
/* @0x1e5dbc vldr s15, [sp, #64] */
/* @0x1e5dc0 str r3, [sp, #0x14] */
/* @0x1e5dc4 vstr s15, [sp, #4] */
/* @0x1e5dc8 ldr r3, [sp, #0x38] */
/* @0x1e5dcc vldr s15, [sp, #68] */
/* @0x1e5dd0 vstr s15, [sp, #8] */
/* @0x1e5dd4 vldr s15, [sp, #72] */
/* @0x1e5dd8 vstr s15, [sp, #12] */
/* @0x1e5ddc vldr s15, [sp, #76] */
/* @0x1e5de0 vstr s15, [sp, #16] */
/* @0x1e5de4 vldr s15, [sp, #84] */
/* @0x1e5de8 vstr s15, [sp, #24] */
/* @0x1e5dec bl 0x17467c <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf> */
/* @0x1e5df0 cmp r0, #0 */
/* @0x1e5df4 beq 0x1e5e00 <_ZN7CSprite7DrawPosEiffffffffjf+0x9c> */
/* @0x1e5df8 add sp, sp, #36 */
/* @0x1e5dfc pop {r4, r5, r6, r7, pc} */
/* @0x1e5e00 ldr r3, [pc, #0x24] */
/* @0x1e5e04 ldr r1, [pc, #0x24] */
/* @0x1e5e08 ldr r3, [pc, r3] */
/* @0x1e5e0c ldr r2, [r4, #0x5c] */
/* @0x1e5e10 add r1, pc, r1 */
/* @0x1e5e14 ldr r0, [r3] */
/* @0x1e5e18 ldr r3, [r0] */
/* @0x1e5e1c ldr r3, [r3, #0xc] */
/* @0x1e5e20 blx r3 */
/* @0x1e5e24 add sp, sp, #36 */
/* @0x1e5e28 pop {r4, r5, r6, r7, pc} */
/* @0x1e5e2c eoreq r7, r0, r12, lsl #18 */
/* @0x1e5e30 andseq r12, r6, r4, lsl #15 */

/* ── FUNC 0x1e5e34 · CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float) · size=372 · insn=93 */
/* @0x1e5e34 push {r4, r5, r6, r7, lr} */
/* @0x1e5e38 mov r4, r0 */
/* @0x1e5e3c ldr r5, [r0, #0x18] */
/* @0x1e5e40 sub sp, sp, #36 */
/* @0x1e5e44 mov r6, r2 */
/* @0x1e5e48 mov r7, r3 */
/* @0x1e5e4c cmp r5, #0 */
/* @0x1e5e50 ble 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8> */
/* @0x1e5e54 mov r0, r1 */
/* @0x1e5e58 mov r1, r5 */
/* @0x1e5e5c bl 0x318dec <__aeabi_idivmod> */
/* @0x1e5e60 ldr r12, [r4, #0x74] */
/* @0x1e5e64 subs r0, r1, #0 */
/* @0x1e5e68 addlt r0, r0, r5 */
/* @0x1e5e6c cmp r12, #0 */
/* @0x1e5e70 bne 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8> */
/* @0x1e5e74 ldr r3, [r4, #0x54] */
/* @0x1e5e78 cmp r3, #0 */
/* @0x1e5e7c beq 0x1e5f10 <_ZN7CSprite8DrawPartEiffffffffjf+0xdc> */
/* @0x1e5e80 ldr r2, [sp, #0x50] */
/* @0x1e5e84 vldr s15, [sp, #60] */
/* @0x1e5e88 ldr r0, [r3, r0, lsl #2] */
/* @0x1e5e8c mov r1, r6 */
/* @0x1e5e90 mov r3, #0 */
/* @0x1e5e94 vstr s15, [sp] */
/* @0x1e5e98 str r2, [sp, #0x18] */
/* @0x1e5e9c vldr s15, [sp, #64] */
/* @0x1e5ea0 str r3, [sp, #0x14] */
/* @0x1e5ea4 vstr s15, [sp, #4] */
/* @0x1e5ea8 mov r2, r7 */
/* @0x1e5eac vldr s15, [sp, #68] */
/* @0x1e5eb0 ldr r3, [sp, #0x38] */
/* @0x1e5eb4 vstr s15, [sp, #8] */
/* @0x1e5eb8 vldr s15, [sp, #72] */
/* @0x1e5ebc vstr s15, [sp, #12] */
/* @0x1e5ec0 vldr s15, [sp, #76] */
/* @0x1e5ec4 vstr s15, [sp, #16] */
/* @0x1e5ec8 vldr s15, [sp, #84] */
/* @0x1e5ecc vstr s15, [sp, #28] */
/* @0x1e5ed0 bl 0x175450 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf> */
/* @0x1e5ed4 cmp r0, #0 */
/* @0x1e5ed8 beq 0x1e5ee4 <_ZN7CSprite8DrawPartEiffffffffjf+0xb0> */
/* @0x1e5edc add sp, sp, #36 */
/* @0x1e5ee0 pop {r4, r5, r6, r7, pc} */
/* @0x1e5ee4 ldr r3, [pc, #0xac] */
/* @0x1e5ee8 ldr r1, [pc, #0xac] */
/* @0x1e5eec ldr r3, [pc, r3] */
/* @0x1e5ef0 ldr r2, [r4, #0x5c] */
/* @0x1e5ef4 add r1, pc, r1 */
/* @0x1e5ef8 ldr r0, [r3] */
/* @0x1e5efc ldr r3, [r0] */
/* @0x1e5f00 ldr r3, [r3, #0xc] */
/* @0x1e5f04 blx r3 */
/* @0x1e5f08 add sp, sp, #36 */
/* @0x1e5f0c pop {r4, r5, r6, r7, pc} */
/* @0x1e5f10 ldr r3, [r4, #0x50] */
/* @0x1e5f14 vldr s15, [sp, #60] */
/* @0x1e5f18 mov r12, #0 */
/* @0x1e5f1c mov r1, r6 */
/* @0x1e5f20 mov r2, r7 */
/* @0x1e5f24 ldr r0, [r3, r0, lsl #2] */
/* @0x1e5f28 vstr s15, [sp] */
/* @0x1e5f2c ldr r3, [sp, #0x50] */
/* @0x1e5f30 vldr s15, [sp, #64] */
/* @0x1e5f34 str r12, [sp, #0x14] */
/* @0x1e5f38 vstr s15, [sp, #4] */
/* @0x1e5f3c vldr s15, [sp, #68] */
/* @0x1e5f40 vstr s15, [sp, #8] */
/* @0x1e5f44 str r3, [sp, #0x18] */
/* @0x1e5f48 vldr s15, [sp, #72] */
/* @0x1e5f4c ldr r3, [sp, #0x38] */
/* @0x1e5f50 vstr s15, [sp, #12] */
/* @0x1e5f54 vldr s15, [sp, #76] */
/* @0x1e5f58 vstr s15, [sp, #16] */
/* @0x1e5f5c vldr s15, [sp, #84] */
/* @0x1e5f60 vstr s15, [sp, #28] */
/* @0x1e5f64 bl 0x175208 <_Z20GR_Texture_Draw_Partifffffffffjf> */
/* @0x1e5f68 cmp r0, #0 */
/* @0x1e5f6c bne 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8> */
/* @0x1e5f70 ldr r3, [pc, #0x28] */
/* @0x1e5f74 ldr r1, [pc, #0x28] */
/* @0x1e5f78 ldr r3, [pc, r3] */
/* @0x1e5f7c ldr r2, [r4, #0x5c] */
/* @0x1e5f80 add r1, pc, r1 */
/* @0x1e5f84 ldr r0, [r3] */
/* @0x1e5f88 ldr r3, [r0] */
/* @0x1e5f8c ldr r3, [r3, #0xc] */
/* @0x1e5f90 blx r3 */
/* @0x1e5f94 b 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8> */
/* @0x1e5f98 eoreq r7, r0, r8, lsr #16 */
/* @0x1e5f9c andseq r12, r6, r0, lsr #13 */
/* @0x1e5fa0 mlaeq r0, r12, r7, r7 */
/* @0x1e5fa4 andseq r12, r6, r4, lsl r6 */

/* ── FUNC 0x1e5fa8 · CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=852 · insn=213 */
/* @0x1e5fa8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e5fac vpush {d8, d9, d10, d11} */
/* @0x1e5fb0 mov r5, r0 */
/* @0x1e5fb4 ldr r6, [r0, #0x18] */
/* @0x1e5fb8 sub sp, sp, #52 */
/* @0x1e5fbc ldr r4, [pc, #0x314] */
/* @0x1e5fc0 mov r8, r2 */
/* @0x1e5fc4 cmp r6, #0 */
/* @0x1e5fc8 mov r9, r3 */
/* @0x1e5fcc add r4, pc, r4 */
/* @0x1e5fd0 vldr s16, [sp, #112] */
/* @0x1e5fd4 vldr s17, [sp, #116] */
/* @0x1e5fd8 vldr s18, [sp, #128] */
/* @0x1e5fdc vldr s19, [sp, #132] */
/* @0x1e5fe0 ble 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e5fe4 mov r0, r1 */
/* @0x1e5fe8 mov r1, r6 */
/* @0x1e5fec bl 0x318dec <__aeabi_idivmod> */
/* @0x1e5ff0 ldr r0, [r5, #0x74] */
/* @0x1e5ff4 subs r7, r1, #0 */
/* @0x1e5ff8 addlt r7, r7, r6 */
/* @0x1e5ffc cmp r0, #0 */
/* @0x1e6000 bne 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e6004 ldr r3, [pc, #0x2d0] */
/* @0x1e6008 ldr r3, [r4, r3] */
/* @0x1e600c ldrb r3, [r3] */
/* @0x1e6010 cmp r3, #0 */
/* @0x1e6014 bne 0x1e6228 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x280> */
/* @0x1e6018 vldr s13, [sp, #136] */
/* @0x1e601c vcvt.f64.f32 d6, s13 */
/* @0x1e6020 vmov r0, r1, d6 */
/* @0x1e6024 bl 0x111070 <_Z14YYGML_degtoradd> */
/* @0x1e6028 vmov d7, r0, r1 */
/* @0x1e602c vcvt.f32.f64 s20, d7 */
/* @0x1e6030 vmov r0, s20 */
/* @0x1e6034 bl 0xb658c <cosf@plt> */
/* @0x1e6038 vmov s21, r0 */
/* @0x1e603c vmov r0, s20 */
/* @0x1e6040 bl 0xb6580 <sinf@plt> */
/* @0x1e6044 vmul.f32 s15, s17, s17 */
/* @0x1e6048 vmla.f32 s15, s16, s16 */
/* @0x1e604c vmov s22, r0 */
/* @0x1e6050 vsqrt.f32 s14, s15 */
/* @0x1e6054 vcmpe.f32 s18, s19 */
/* @0x1e6058 vmrs APSR_nzcv, fpscr */
/* @0x1e605c vcmp.f32 s14, s14 */
/* @0x1e6060 vmovle.f32 s20, s19 */
/* @0x1e6064 vmovgt.f32 s20, s18 */
/* @0x1e6068 vmrs APSR_nzcv, fpscr */
/* @0x1e606c bne 0x1e62c0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x318> */
/* @0x1e6070 ldr r3, [pc, #0x268] */
/* @0x1e6074 ldr r3, [r4, r3] */
/* @0x1e6078 ldrb r3, [r3] */
/* @0x1e607c cmp r3, #0 */
/* @0x1e6080 bne 0x1e612c <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x184> */
/* @0x1e6084 vmul.f32 s13, s21, s17 */
/* @0x1e6088 vldr s11, [sp, #124] */
/* @0x1e608c ldr r3, [pc, #0x250] */
/* @0x1e6090 ldr r3, [r4, r3] */
/* @0x1e6094 vmov.f32 s15, #5.000000e-01 */
/* @0x1e6098 vmul.f32 s12, s22, s16 */
/* @0x1e609c vmul.f32 s13, s13, s15 */
/* @0x1e60a0 vnmls.f32 s13, s12, s15 */
/* @0x1e60a4 vmls.f32 s11, s20, s13 */
/* @0x1e60a8 vmul.f32 s14, s20, s14 */
/* @0x1e60ac vmov.f32 s13, s11 */
/* @0x1e60b0 vldr s11, [r3, #4] */
/* @0x1e60b4 vcvt.f32.s32 s12, s11 */
/* @0x1e60b8 vmul.f32 s14, s14, s15 */
/* @0x1e60bc vsub.f32 s12, s12, s13 */
/* @0x1e60c0 vcmpe.f32 s14, s12 */
/* @0x1e60c4 vmrs APSR_nzcv, fpscr */
/* @0x1e60c8 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214> */
/* @0x1e60cc vldr s11, [r3, #12] */
/* @0x1e60d0 vcvt.f32.s32 s12, s11 */
/* @0x1e60d4 vsub.f32 s13, s13, s12 */
/* @0x1e60d8 vcmpe.f32 s14, s13 */
/* @0x1e60dc vmrs APSR_nzcv, fpscr */
/* @0x1e60e0 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214> */
/* @0x1e60e4 vmul.f32 s22, s22, s17 */
/* @0x1e60e8 vldr s12, [r3] */
/* @0x1e60ec vmul.f32 s22, s22, s15 */
/* @0x1e60f0 vmul.f32 s21, s21, s16 */
/* @0x1e60f4 vmla.f32 s22, s21, s15 */
/* @0x1e60f8 vldr s15, [sp, #120] */
/* @0x1e60fc vmla.f32 s15, s20, s22 */
/* @0x1e6100 vcvt.f32.s32 s13, s12 */
/* @0x1e6104 vsub.f32 s13, s13, s15 */
/* @0x1e6108 vcmpe.f32 s14, s13 */
/* @0x1e610c vmrs APSR_nzcv, fpscr */
/* @0x1e6110 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214> */
/* @0x1e6114 vldr s13, [r3, #8] */
/* @0x1e6118 vcvt.f32.s32 s13, s13 */
/* @0x1e611c vsub.f32 s15, s15, s13 */
/* @0x1e6120 vcmpe.f32 s14, s15 */
/* @0x1e6124 vmrs APSR_nzcv, fpscr */
/* @0x1e6128 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214> */
/* @0x1e612c ldr r3, [r5, #0x54] */
/* @0x1e6130 cmp r3, #0 */
/* @0x1e6134 beq 0x1e6230 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x288> */
/* @0x1e6138 vldr s13, [sp, #136] */
/* @0x1e613c vldr s15, [pc, #396] */
/* @0x1e6140 vmul.f32 s15, s13, s15 */
/* @0x1e6144 vldr s14, [pc, #392] */
/* @0x1e6148 ldr r0, [r3, r7, lsl #2] */
/* @0x1e614c vldr s11, [sp, #120] */
/* @0x1e6150 ldr r2, [sp, #0x8c] */
/* @0x1e6154 vstr s11, [sp, #4] */
/* @0x1e6158 ldr r3, [sp, #0x90] */
/* @0x1e615c vldr s12, [sp, #124] */
/* @0x1e6160 vldr s11, [sp, #156] */
/* @0x1e6164 mov r1, r8 */
/* @0x1e6168 str r2, [sp, #0x18] */
/* @0x1e616c vstr s17, [sp] */
/* @0x1e6170 ldr r2, [sp, #0x94] */
/* @0x1e6174 vstr s12, [sp, #8] */
/* @0x1e6178 str r3, [sp, #0x1c] */
/* @0x1e617c vstr s18, [sp, #12] */
/* @0x1e6180 ldr r3, [sp, #0x98] */
/* @0x1e6184 vstr s19, [sp, #16] */
/* @0x1e6188 str r2, [sp, #0x20] */
/* @0x1e618c vstr s11, [sp, #40] */
/* @0x1e6190 mov r2, r9 */
/* @0x1e6194 str r3, [sp, #0x24] */
/* @0x1e6198 vdiv.f32 s15, s15, s14 */
/* @0x1e619c vmov r3, s16 */
/* @0x1e61a0 vstr s15, [sp, #20] */
/* @0x1e61a4 bl 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf> */
/* @0x1e61a8 cmp r0, #0 */
/* @0x1e61ac beq 0x1e6200 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x258> */
/* @0x1e61b0 add sp, sp, #52 */
/* @0x1e61b4 vpop {d8, d9, d10, d11} */
/* @0x1e61b8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e61bc ldr r3, [pc, #0x124] */
/* @0x1e61c0 ldr r3, [r4, r3] */
/* @0x1e61c4 ldrb r3, [r3] */
/* @0x1e61c8 cmp r3, #0 */
/* @0x1e61cc beq 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e61d0 ldr r3, [pc, #0x114] */
/* @0x1e61d4 ldr r6, [r4, r3] */
/* @0x1e61d8 mov r0, r6 */
/* @0x1e61dc bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1e61e0 cmp r0, #0 */
/* @0x1e61e4 beq 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e61e8 mov r0, r6 */
/* @0x1e61ec bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1e61f0 bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1e61f4 cmp r0, #0 */
/* @0x1e61f8 bne 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e61fc b 0x1e612c <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x184> */
/* @0x1e6200 ldr r1, [pc, #0xe8] */
/* @0x1e6204 ldr r3, [pc, #0xe8] */
/* @0x1e6208 ldr r2, [r5, #0x5c] */
/* @0x1e620c add r1, pc, r1 */
/* @0x1e6210 ldr r3, [r4, r3] */
/* @0x1e6214 ldr r0, [r3] */
/* @0x1e6218 ldr r3, [r0] */
/* @0x1e621c ldr r3, [r3, #0xc] */
/* @0x1e6220 blx r3 */
/* @0x1e6224 b 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e6228 bl 0x168d94 <_Z22UpdateTransRoomExtentsv> */
/* @0x1e622c b 0x1e6018 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x70> */
/* @0x1e6230 vldr s11, [sp, #136] */
/* @0x1e6234 vldr s14, [pc, #148] */
/* @0x1e6238 vmul.f32 s14, s11, s14 */
/* @0x1e623c vldr s15, [pc, #144] */
/* @0x1e6240 ldr r3, [r5, #0x50] */
/* @0x1e6244 vldr s12, [sp, #120] */
/* @0x1e6248 vldr s13, [sp, #124] */
/* @0x1e624c vldr s11, [sp, #156] */
/* @0x1e6250 mov r1, r8 */
/* @0x1e6254 mov r2, r9 */
/* @0x1e6258 ldr r0, [r3, r7, lsl #2] */
/* @0x1e625c vstr s17, [sp] */
/* @0x1e6260 ldr r3, [sp, #0x8c] */
/* @0x1e6264 vstr s12, [sp, #4] */
/* @0x1e6268 vstr s13, [sp, #8] */
/* @0x1e626c vstr s18, [sp, #12] */
/* @0x1e6270 vstr s19, [sp, #16] */
/* @0x1e6274 vstr s11, [sp, #40] */
/* @0x1e6278 str r3, [sp, #0x18] */
/* @0x1e627c ldr r3, [sp, #0x90] */
/* @0x1e6280 vdiv.f32 s15, s14, s15 */
/* @0x1e6284 str r3, [sp, #0x1c] */
/* @0x1e6288 ldr r3, [sp, #0x94] */
/* @0x1e628c str r3, [sp, #0x20] */
/* @0x1e6290 ldr r3, [sp, #0x98] */
/* @0x1e6294 str r3, [sp, #0x24] */
/* @0x1e6298 vmov r3, s16 */
/* @0x1e629c vstr s15, [sp, #20] */
/* @0x1e62a0 bl 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf> */
/* @0x1e62a4 cmp r0, #0 */
/* @0x1e62a8 bne 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208> */
/* @0x1e62ac ldr r1, [pc, #0x44] */
/* @0x1e62b0 ldr r3, [pc, #0x3c] */
/* @0x1e62b4 ldr r2, [r5, #0x5c] */
/* @0x1e62b8 add r1, pc, r1 */
/* @0x1e62bc b 0x1e6210 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x268> */
/* @0x1e62c0 vmov r0, s15 */
/* @0x1e62c4 bl 0xb6700 <sqrtf@plt> */
/* @0x1e62c8 vmov s14, r0 */
/* @0x1e62cc b 0x1e6070 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0xc8> */
/* @0x1e62d0 ldrdmi r0, r1, [r9], #-251 */
/* @0x1e62d4 teqmi r4, #0 */
/* @0x1e62d8 eoreq r11, r0, r4, lsl #25 */
/* @0x1e62dc .word 0xffffd9e0 */
/* @0x1e62e0 .word 0xffffe490 */
/* @0x1e62e4 .word 0xffffe500 */
/* @0x1e62e8 .word 0xffffbcd4 */
/* @0x1e62ec .word 0xffffc024 */
/* @0x1e62f0 andseq r12, r6, r8, lsl #7 */
/* @0x1e62f4 .word 0xffffbac4 */
/* @0x1e62f8 ldrsbeq r12, [r6], -r12 */

/* ── FUNC 0x1e62fc · fwrap(float, float) · size=68 · insn=17 */
/* @0x1e62fc push {r3, lr} */
/* @0x1e6300 vpush {d8} */
/* @0x1e6304 vmov s16, r1 */
/* @0x1e6308 vmov s17, r0 */
/* @0x1e630c vcmpe.f32 s16, #0 */
/* @0x1e6310 vmrs APSR_nzcv, fpscr */
/* @0x1e6314 vmovls.f32 s16, s17 */
/* @0x1e6318 bls 0x1e6334 <_Z5fwrapff+0x38> */
/* @0x1e631c vdiv.f32 s17, s17, s16 */
/* @0x1e6320 vmov r0, s17 */
/* @0x1e6324 bl 0xb6910 <floorf@plt> */
/* @0x1e6328 vmov s15, r0 */
/* @0x1e632c vsub.f32 s17, s17, s15 */
/* @0x1e6330 vmul.f32 s16, s17, s16 */
/* @0x1e6334 vmov r0, s16 */
/* @0x1e6338 vpop {d8} */
/* @0x1e633c pop {r3, pc} */

/* ── FUNC 0x1e6340 · CSprite::Free() · size=28 · insn=7 */
/* @0x1e6340 push {r3, lr} */
/* @0x1e6344 subs r3, r0, #0 */
/* @0x1e6348 popeq {r3, pc} */
/* @0x1e634c ldr r3, [r3] */
/* @0x1e6350 ldr r3, [r3, #0x4] */
/* @0x1e6354 blx r3 */
/* @0x1e6358 pop {r3, pc} */

/* ── FUNC 0x1e635c · CSprite::GetBitmap24(int) · size=60 · insn=15 */
/* @0x1e635c cmp r1, #0 */
/* @0x1e6360 blt 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34> */
/* @0x1e6364 ldr r3, [r0, #0x18] */
/* @0x1e6368 cmp r1, r3 */
/* @0x1e636c bge 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34> */
/* @0x1e6370 ldr r3, [r0, #0x48] */
/* @0x1e6374 cmp r3, #0 */
/* @0x1e6378 beq 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34> */
/* @0x1e637c ldr r2, [r0, #0x74] */
/* @0x1e6380 cmp r2, #0 */
/* @0x1e6384 bne 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34> */
/* @0x1e6388 ldr r0, [r3, r1, lsl #2] */
/* @0x1e638c b 0x1675e8 <_ZN9CBitmap3214CreateBitmap24Ev> */
/* @0x1e6390 mov r0, #0 */
/* @0x1e6394 bx lr */

/* ── FUNC 0x1e6398 · CSprite::GetBitmap32(int) · size=60 · insn=15 */
/* @0x1e6398 cmp r1, #0 */
/* @0x1e639c blt 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34> */
/* @0x1e63a0 ldr r3, [r0, #0x18] */
/* @0x1e63a4 cmp r1, r3 */
/* @0x1e63a8 bge 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34> */
/* @0x1e63ac ldr r3, [r0, #0x48] */
/* @0x1e63b0 cmp r3, #0 */
/* @0x1e63b4 beq 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34> */
/* @0x1e63b8 ldr r2, [r0, #0x74] */
/* @0x1e63bc cmp r2, #0 */
/* @0x1e63c0 bne 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34> */
/* @0x1e63c4 ldr r0, [r3, r1, lsl #2] */
/* @0x1e63c8 b 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev> */
/* @0x1e63cc mov r0, #0 */
/* @0x1e63d0 bx lr */

/* ── FUNC 0x1e63d4 · CSprite::GetBoundingBoxImg(int) · size=248 · insn=62 */
/* @0x1e63d4 push {r4, r5, r6, lr} */
/* @0x1e63d8 mov r6, r0 */
/* @0x1e63dc mov r0, #16 */
/* @0x1e63e0 mov r5, r1 */
/* @0x1e63e4 bl 0x27c524 <_Znwj> */
/* @0x1e63e8 mov r3, #0 */
/* @0x1e63ec mov r2, #16 */
/* @0x1e63f0 mov r1, r3 */
/* @0x1e63f4 str r3, [r0] */
/* @0x1e63f8 mov r4, r0 */
/* @0x1e63fc str r3, [r0, #0x4] */
/* @0x1e6400 str r3, [r0, #0x8] */
/* @0x1e6404 str r3, [r0, #0xc] */
/* @0x1e6408 bl 0xb65b0 <memset@plt> */
/* @0x1e640c cmp r5, #0 */
/* @0x1e6410 blt 0x1e6458 <_ZN7CSprite17GetBoundingBoxImgEi+0x84> */
/* @0x1e6414 ldr r3, [r6, #0x18] */
/* @0x1e6418 cmp r5, r3 */
/* @0x1e641c bge 0x1e6458 <_ZN7CSprite17GetBoundingBoxImgEi+0x84> */
/* @0x1e6420 ldr r3, [r6, #0x54] */
/* @0x1e6424 cmp r3, #0 */
/* @0x1e6428 beq 0x1e6460 <_ZN7CSprite17GetBoundingBoxImgEi+0x8c> */
/* @0x1e642c ldr r3, [r3, r5, lsl #2] */
/* @0x1e6430 ldrsh r1, [r3, #8] */
/* @0x1e6434 ldrsh r2, [r3, #10] */
/* @0x1e6438 ldrsh r0, [r3, #4] */
/* @0x1e643c ldrsh r3, [r3, #6] */
/* @0x1e6440 str r1, [r4] */
/* @0x1e6444 add r1, r1, r0 */
/* @0x1e6448 add r3, r2, r3 */
/* @0x1e644c str r1, [r4, #0x8] */
/* @0x1e6450 str r3, [r4, #0xc] */
/* @0x1e6454 str r2, [r4, #0x4] */
/* @0x1e6458 mov r0, r4 */
/* @0x1e645c pop {r4, r5, r6, pc} */
/* @0x1e6460 ldr r3, [r6, #0x74] */
/* @0x1e6464 cmp r3, #1 */
/* @0x1e6468 beq 0x1e6484 <_ZN7CSprite17GetBoundingBoxImgEi+0xb0> */
/* @0x1e646c mov r0, r4 */
/* @0x1e6470 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e6474 ldr r3, [r6, #0x48] */
/* @0x1e6478 ldr r0, [r3, r5, lsl #2] */
/* @0x1e647c pop {r4, r5, r6, lr} */
/* @0x1e6480 b 0x167508 <_ZN9CBitmap3211BoundingBoxEv> */
/* @0x1e6484 ldr r3, [r6, #0x84] */
/* @0x1e6488 add r5, r5, r5, lsl #1 */
/* @0x1e648c ldr r3, [r3] */
/* @0x1e6490 add r5, r3, r5, lsl #3 */
/* @0x1e6494 vldr s15, [r5, #4] */
/* @0x1e6498 vcvt.s32.f32 s15, s15 */
/* @0x1e649c vldr s13, [r5, #8] */
/* @0x1e64a0 vldr s14, [r5, #12] */
/* @0x1e64a4 vmov r3, s15 */
/* @0x1e64a8 vldr s15, [r5, #16] */
/* @0x1e64ac vcvt.s32.f32 s13, s13 */
/* @0x1e64b0 vcvt.s32.f32 s14, s14 */
/* @0x1e64b4 vstr s13, [r4, #8] */
/* @0x1e64b8 vcvt.s32.f32 s15, s15 */
/* @0x1e64bc vstr s14, [r4, #4] */
/* @0x1e64c0 str r3, [r4] */
/* @0x1e64c4 vstr s15, [r4, #12] */
/* @0x1e64c8 b 0x1e6458 <_ZN7CSprite17GetBoundingBoxImgEi+0x84> */

/* ── FUNC 0x1e64cc · CSprite::LoadMaskFromStream(int, CStream*) · size=268 · insn=67 */
/* @0x1e64cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e64d0 mov r7, r0 */
/* @0x1e64d4 sub sp, sp, #12 */
/* @0x1e64d8 mov r0, r2 */
/* @0x1e64dc mov r6, r2 */
/* @0x1e64e0 mov r4, r1 */
/* @0x1e64e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e64e8 cmp r0, #800 */
/* @0x1e64ec beq 0x1e64fc <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0x30> */
/* @0x1e64f0 mov r0, #1 */
/* @0x1e64f4 add sp, sp, #12 */
/* @0x1e64f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e64fc mov r0, r6 */
/* @0x1e6500 lsl r8, r4, #3 */
/* @0x1e6504 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e6508 mov r10, r0 */
/* @0x1e650c mov r0, r6 */
/* @0x1e6510 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e6514 str r0, [sp, #0x4] */
/* @0x1e6518 mov r0, r6 */
/* @0x1e651c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e6520 ldr r2, [sp, #0x4] */
/* @0x1e6524 mov r0, r6 */
/* @0x1e6528 mul r5, r2, r10 */
/* @0x1e652c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e6530 mov r0, r6 */
/* @0x1e6534 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e6538 mov r0, r6 */
/* @0x1e653c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e6540 ldr r0, [r7, #0x40] */
/* @0x1e6544 ldr r2, [pc, #0x88] */
/* @0x1e6548 movw r3, #0xb4f */
/* @0x1e654c add r0, r0, r8 */
/* @0x1e6550 add r2, pc, r2 */
/* @0x1e6554 mov r1, r5 */
/* @0x1e6558 add r0, r0, #4 */
/* @0x1e655c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e6560 ldr r2, [sp, #0x4] */
/* @0x1e6564 ldr r3, [r7, #0x40] */
/* @0x1e6568 cmp r2, #0 */
/* @0x1e656c str r5, [r3, r4, lsl #3] */
/* @0x1e6570 ble 0x1e65c0 <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xf4> */
/* @0x1e6574 mov r4, #0 */
/* @0x1e6578 mov r9, r4 */
/* @0x1e657c cmp r10, #0 */
/* @0x1e6580 add r5, r10, r4 */
/* @0x1e6584 ble 0x1e65ac <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xe0> */
/* @0x1e6588 ldr r3, [r7, #0x40] */
/* @0x1e658c mov r0, r6 */
/* @0x1e6590 add r3, r3, r8 */
/* @0x1e6594 ldr r11, [r3, #0x4] */
/* @0x1e6598 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e659c strb r0, [r11, r4] */
/* @0x1e65a0 add r4, r4, #1 */
/* @0x1e65a4 cmp r5, r4 */
/* @0x1e65a8 bne 0x1e6588 <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xbc> */
/* @0x1e65ac ldr r3, [sp, #0x4] */
/* @0x1e65b0 add r9, r9, #1 */
/* @0x1e65b4 mov r4, r5 */
/* @0x1e65b8 cmp r9, r3 */
/* @0x1e65bc bne 0x1e657c <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xb0> */
/* @0x1e65c0 mov r3, #1 */
/* @0x1e65c4 mov r0, #1 */
/* @0x1e65c8 strb r3, [r7, #0x31] */
/* @0x1e65cc add sp, sp, #12 */
/* @0x1e65d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e65d4 ldrsbeq r11, [r6], -r4 */

/* ── FUNC 0x1e65d8 · CSprite::GenerateBitmapData() · size=728 · insn=182 */
/* @0x1e65d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e65dc mov r11, r0 */
/* @0x1e65e0 ldr r4, [r0, #0x74] */
/* @0x1e65e4 sub sp, sp, #36 */
/* @0x1e65e8 cmp r4, #0 */
/* @0x1e65ec beq 0x1e65fc <_ZN7CSprite18GenerateBitmapDataEv+0x24> */
/* @0x1e65f0 mov r0, #0 */
/* @0x1e65f4 add sp, sp, #36 */
/* @0x1e65f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e65fc ldr r1, [r0, #0x18] */
/* @0x1e6600 movw r3, #0xc3d */
/* @0x1e6604 ldr r2, [pc, #0x29c] */
/* @0x1e6608 add r0, r0, #72 */
/* @0x1e660c add r2, pc, r2 */
/* @0x1e6610 lsl r1, r1, #2 */
/* @0x1e6614 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e6618 ldr r3, [r11, #0x48] */
/* @0x1e661c cmp r3, #0 */
/* @0x1e6620 beq 0x1e6644 <_ZN7CSprite18GenerateBitmapDataEv+0x6c> */
/* @0x1e6624 ldr r0, [r3] */
/* @0x1e6628 cmp r0, #0 */
/* @0x1e662c beq 0x1e6644 <_ZN7CSprite18GenerateBitmapDataEv+0x6c> */
/* @0x1e6630 ldr r3, [r0] */
/* @0x1e6634 ldr r3, [r3, #0x4] */
/* @0x1e6638 blx r3 */
/* @0x1e663c ldr r3, [r11, #0x48] */
/* @0x1e6640 str r4, [r3] */
/* @0x1e6644 ldr r3, [r11, #0x18] */
/* @0x1e6648 cmp r3, #0 */
/* @0x1e664c ble 0x1e689c <_ZN7CSprite18GenerateBitmapDataEv+0x2c4> */
/* @0x1e6650 ldr r1, [pc, #0x254] */
/* @0x1e6654 mov r5, #0 */
/* @0x1e6658 mov r8, r5 */
/* @0x1e665c add r2, sp, #28 */
/* @0x1e6660 add r3, sp, #24 */
/* @0x1e6664 ldr r1, [pc, r1] */
/* @0x1e6668 str r2, [sp, #0x10] */
/* @0x1e666c str r3, [sp, #0x14] */
/* @0x1e6670 str r1, [sp, #0xc] */
/* @0x1e6674 ldr r2, [r11, #0x54] */
/* @0x1e6678 lsl r6, r5, #2 */
/* @0x1e667c ldr r1, [sp, #0xc] */
/* @0x1e6680 ldr r0, [r2, r5, lsl #2] */
/* @0x1e6684 ldr r3, [r1, #0x4] */
/* @0x1e6688 ldrsh lr, [r0, #20] */
/* @0x1e668c ldrsh r1, [r0] */
/* @0x1e6690 ldrsh r2, [r0, #2] */
/* @0x1e6694 ldr r4, [r3, lr, lsl #2] */
/* @0x1e6698 ldrsh lr, [r0, #6] */
/* @0x1e669c ldrsh r3, [r0, #4] */
/* @0x1e66a0 ldr r0, [r4] */
/* @0x1e66a4 str lr, [sp] */
/* @0x1e66a8 bl 0x17e2a8 <_ZN8Graphics16Texture_GrabRectEPviiii> */
/* @0x1e66ac subs r9, r0, #0 */
/* @0x1e66b0 beq 0x1e65f0 <_ZN7CSprite18GenerateBitmapDataEv+0x18> */
/* @0x1e66b4 ldr r3, [r11, #0x54] */
/* @0x1e66b8 ldr r3, [r3, r5, lsl #2] */
/* @0x1e66bc ldrsh r2, [r3, #12] */
/* @0x1e66c0 ldrsh r3, [r3, #4] */
/* @0x1e66c4 vmov s14, r2 */
/* @0x1e66c8 vmov s15, r3 */
/* @0x1e66cc vcvt.f32.s32 s14, s14 */
/* @0x1e66d0 vcvt.f32.s32 s15, s15 */
/* @0x1e66d4 vdiv.f32 s15, s14, s15 */
/* @0x1e66d8 vcvt.s32.f32 s15, s15 */
/* @0x1e66dc vmov r7, s15 */
/* @0x1e66e0 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x1e66e4 mov r1, #7 */
/* @0x1e66e8 ldr r3, [r0] */
/* @0x1e66ec mov r4, r0 */
/* @0x1e66f0 ldr r3, [r3, #0x1c] */
/* @0x1e66f4 blx r3 */
/* @0x1e66f8 ldr r3, [r11, #0x54] */
/* @0x1e66fc mov r1, r7 */
/* @0x1e6700 ldr r10, [r4] */
/* @0x1e6704 ldr r3, [r3, r5, lsl #2] */
/* @0x1e6708 ldrsh r0, [r3, #16] */
/* @0x1e670c bl 0x318d10 <__divsi3> */
/* @0x1e6710 ldr r3, [r10, #0xc] */
/* @0x1e6714 mov r1, r0 */
/* @0x1e6718 mov r0, r4 */
/* @0x1e671c blx r3 */
/* @0x1e6720 ldr r3, [r11, #0x54] */
/* @0x1e6724 mov r1, r7 */
/* @0x1e6728 ldr r10, [r4] */
/* @0x1e672c ldr r3, [r3, r5, lsl #2] */
/* @0x1e6730 ldrsh r0, [r3, #18] */
/* @0x1e6734 bl 0x318d10 <__divsi3> */
/* @0x1e6738 ldr r3, [r10, #0x14] */
/* @0x1e673c mov r1, r0 */
/* @0x1e6740 mov r0, r4 */
/* @0x1e6744 blx r3 */
/* @0x1e6748 str r8, [sp, #0x1c] */
/* @0x1e674c ldr lr, [r4] */
/* @0x1e6750 add r3, sp, #24 */
/* @0x1e6754 mov r1, #0 */
/* @0x1e6758 add r2, sp, #28 */
/* @0x1e675c mov r0, r4 */
/* @0x1e6760 str r8, [sp, #0x18] */
/* @0x1e6764 ldr r10, [lr, #0x24] */
/* @0x1e6768 blx r10 */
/* @0x1e676c ldr r2, [r4] */
/* @0x1e6770 ldr r10, [sp, #0x1c] */
/* @0x1e6774 ldr r2, [r2, #0x18] */
/* @0x1e6778 str r0, [sp, #0x8] */
/* @0x1e677c mov r0, r4 */
/* @0x1e6780 blx r2 */
/* @0x1e6784 ldr r2, [sp, #0x18] */
/* @0x1e6788 mov r1, #0 */
/* @0x1e678c mul r2, r2, r0 */
/* @0x1e6790 mov r0, r10 */
/* @0x1e6794 bl 0xb65b0 <memset@plt> */
/* @0x1e6798 ldr r10, [r11, #0x54] */
/* @0x1e679c mov r1, r7 */
/* @0x1e67a0 ldr r2, [r10, r5, lsl #2] */
/* @0x1e67a4 ldrsh r0, [r2, #10] */
/* @0x1e67a8 bl 0x318d10 <__divsi3> */
/* @0x1e67ac ldr r2, [sp, #0x1c] */
/* @0x1e67b0 ldr lr, [sp, #0x18] */
/* @0x1e67b4 mov r1, r7 */
/* @0x1e67b8 mla r7, lr, r0, r2 */
/* @0x1e67bc str r7, [sp, #0x1c] */
/* @0x1e67c0 ldr r2, [r10, r5, lsl #2] */
/* @0x1e67c4 ldrsh r0, [r2, #8] */
/* @0x1e67c8 bl 0x318d10 <__divsi3> */
/* @0x1e67cc add r0, r7, r0, lsl #2 */
/* @0x1e67d0 str r0, [sp, #0x1c] */
/* @0x1e67d4 ldr r3, [r10, r5, lsl #2] */
/* @0x1e67d8 ldrsh r2, [r3, #6] */
/* @0x1e67dc cmp r2, #0 */
/* @0x1e67e0 ble 0x1e6834 <_ZN7CSprite18GenerateBitmapDataEv+0x25c> */
/* @0x1e67e4 ldrh r2, [r3, #4] */
/* @0x1e67e8 mov r10, r9 */
/* @0x1e67ec mov r7, #0 */
/* @0x1e67f0 sxth r2, r2 */
/* @0x1e67f4 mov r1, r10 */
/* @0x1e67f8 add r7, r7, #1 */
/* @0x1e67fc lsl r2, r2, #2 */
/* @0x1e6800 bl 0xb65bc <memcpy@plt> */
/* @0x1e6804 ldr r3, [r11, #0x54] */
/* @0x1e6808 ldr r0, [sp, #0x1c] */
/* @0x1e680c ldr r2, [sp, #0x18] */
/* @0x1e6810 add r0, r0, r2 */
/* @0x1e6814 str r0, [sp, #0x1c] */
/* @0x1e6818 ldr r3, [r3, r6] */
/* @0x1e681c ldrh r2, [r3, #4] */
/* @0x1e6820 ldrsh r3, [r3, #6] */
/* @0x1e6824 cmp r3, r7 */
/* @0x1e6828 sxth r3, r2 */
/* @0x1e682c add r10, r10, r3, lsl #2 */
/* @0x1e6830 bgt 0x1e67f0 <_ZN7CSprite18GenerateBitmapDataEv+0x218> */
/* @0x1e6834 ldr r3, [r4] */
/* @0x1e6838 mov r0, r4 */
/* @0x1e683c ldr r1, [sp, #0x8] */
/* @0x1e6840 add r5, r5, #1 */
/* @0x1e6844 ldr r3, [r3, #0x28] */
/* @0x1e6848 blx r3 */
/* @0x1e684c mov r0, r9 */
/* @0x1e6850 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6854 mov r0, #24 */
/* @0x1e6858 bl 0x27c524 <_Znwj> */
/* @0x1e685c mov r2, #0 */
/* @0x1e6860 mov r3, r2 */
/* @0x1e6864 mov r1, r4 */
/* @0x1e6868 str r8, [sp] */
/* @0x1e686c mov r7, r0 */
/* @0x1e6870 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi> */
/* @0x1e6874 ldr r3, [r11, #0x48] */
/* @0x1e6878 mov r0, r4 */
/* @0x1e687c str r7, [r3, r6] */
/* @0x1e6880 ldr r3, [r4] */
/* @0x1e6884 str r5, [r11, #0x44] */
/* @0x1e6888 ldr r3, [r3, #0x4] */
/* @0x1e688c blx r3 */
/* @0x1e6890 ldr r3, [r11, #0x18] */
/* @0x1e6894 cmp r3, r5 */
/* @0x1e6898 bgt 0x1e6674 <_ZN7CSprite18GenerateBitmapDataEv+0x9c> */
/* @0x1e689c mov r0, #1 */
/* @0x1e68a0 add sp, sp, #36 */
/* @0x1e68a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e68a8 andseq r11, r6, r8, lsl lr */
/* @0x1e68ac .word 0x002072b8 */

/* ── FUNC 0x1e68b0 · CSprite::ClearSWFData() · size=668 · insn=167 */
/* @0x1e68b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e68b4 sub sp, sp, #12 */
/* @0x1e68b8 str r0, [sp, #0x4] */
/* @0x1e68bc ldr r0, [r0, #0x7c] */
/* @0x1e68c0 cmp r0, #0 */
/* @0x1e68c4 beq 0x1e6ab4 <_ZN7CSprite12ClearSWFDataEv+0x204> */
/* @0x1e68c8 ldr r2, [sp, #0x4] */
/* @0x1e68cc ldr r3, [r2, #0x80] */
/* @0x1e68d0 cmp r3, #0 */
/* @0x1e68d4 ble 0x1e6aa0 <_ZN7CSprite12ClearSWFDataEv+0x1f0> */
/* @0x1e68d8 mov r11, #0 */
/* @0x1e68dc b 0x1e6908 <_ZN7CSprite12ClearSWFDataEv+0x58> */
/* @0x1e68e0 cmp r3, #2 */
/* @0x1e68e4 beq 0x1e6b40 <_ZN7CSprite12ClearSWFDataEv+0x290> */
/* @0x1e68e8 mov r0, r9 */
/* @0x1e68ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e68f0 ldr r3, [sp, #0x4] */
/* @0x1e68f4 ldr r0, [r3, #0x7c] */
/* @0x1e68f8 ldr r3, [r3, #0x80] */
/* @0x1e68fc add r11, r11, #1 */
/* @0x1e6900 cmp r3, r11 */
/* @0x1e6904 ble 0x1e6aa0 <_ZN7CSprite12ClearSWFDataEv+0x1f0> */
/* @0x1e6908 ldr r9, [r0, r11, lsl #2] */
/* @0x1e690c cmp r9, #0 */
/* @0x1e6910 beq 0x1e68fc <_ZN7CSprite12ClearSWFDataEv+0x4c> */
/* @0x1e6914 ldr r3, [r9] */
/* @0x1e6918 cmp r3, #1 */
/* @0x1e691c bne 0x1e68e0 <_ZN7CSprite12ClearSWFDataEv+0x30> */
/* @0x1e6920 ldr r0, [r9, #0x8] */
/* @0x1e6924 cmp r0, #0 */
/* @0x1e6928 beq 0x1e68e8 <_ZN7CSprite12ClearSWFDataEv+0x38> */
/* @0x1e692c ldr r3, [r9, #0x1c] */
/* @0x1e6930 cmp r3, #0 */
/* @0x1e6934 movne r8, #0 */
/* @0x1e6938 movne r10, r8 */
/* @0x1e693c beq 0x1e6a98 <_ZN7CSprite12ClearSWFDataEv+0x1e8> */
/* @0x1e6940 ldr r4, [r0, r8] */
/* @0x1e6944 add r5, r0, r8 */
/* @0x1e6948 cmp r4, #0 */
/* @0x1e694c beq 0x1e69f8 <_ZN7CSprite12ClearSWFDataEv+0x148> */
/* @0x1e6950 ldr r3, [r5, #0xc] */
/* @0x1e6954 cmp r3, #0 */
/* @0x1e6958 beq 0x1e69f0 <_ZN7CSprite12ClearSWFDataEv+0x140> */
/* @0x1e695c mov r6, #0 */
/* @0x1e6960 mov r7, r6 */
/* @0x1e6964 ldr r0, [r4, r6] */
/* @0x1e6968 add r4, r4, r6 */
/* @0x1e696c cmp r0, #0 */
/* @0x1e6970 beq 0x1e6978 <_ZN7CSprite12ClearSWFDataEv+0xc8> */
/* @0x1e6974 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6978 ldr r0, [r4, #0x4] */
/* @0x1e697c cmp r0, #0 */
/* @0x1e6980 beq 0x1e6988 <_ZN7CSprite12ClearSWFDataEv+0xd8> */
/* @0x1e6984 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6988 ldr r0, [r4, #0x8] */
/* @0x1e698c cmp r0, #0 */
/* @0x1e6990 beq 0x1e6998 <_ZN7CSprite12ClearSWFDataEv+0xe8> */
/* @0x1e6994 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6998 ldr r0, [r4, #0xc] */
/* @0x1e699c cmp r0, #0 */
/* @0x1e69a0 beq 0x1e69a8 <_ZN7CSprite12ClearSWFDataEv+0xf8> */
/* @0x1e69a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e69a8 ldr r0, [r4, #0x10] */
/* @0x1e69ac cmp r0, #0 */
/* @0x1e69b0 beq 0x1e69b8 <_ZN7CSprite12ClearSWFDataEv+0x108> */
/* @0x1e69b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e69b8 ldr r0, [r4, #0x14] */
/* @0x1e69bc cmp r0, #0 */
/* @0x1e69c0 beq 0x1e69c8 <_ZN7CSprite12ClearSWFDataEv+0x118> */
/* @0x1e69c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e69c8 ldr r0, [r4, #0x18] */
/* @0x1e69cc cmp r0, #0 */
/* @0x1e69d0 beq 0x1e69d8 <_ZN7CSprite12ClearSWFDataEv+0x128> */
/* @0x1e69d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e69d8 ldr r3, [r5, #0xc] */
/* @0x1e69dc add r7, r7, #1 */
/* @0x1e69e0 add r6, r6, #84 */
/* @0x1e69e4 ldr r4, [r5] */
/* @0x1e69e8 cmp r3, r7 */
/* @0x1e69ec bhi 0x1e6964 <_ZN7CSprite12ClearSWFDataEv+0xb4> */
/* @0x1e69f0 mov r0, r4 */
/* @0x1e69f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e69f8 ldr r0, [r5, #0x4] */
/* @0x1e69fc cmp r0, #0 */
/* @0x1e6a00 beq 0x1e6a70 <_ZN7CSprite12ClearSWFDataEv+0x1c0> */
/* @0x1e6a04 ldr r3, [r5, #0x10] */
/* @0x1e6a08 cmp r3, #0 */
/* @0x1e6a0c beq 0x1e6a6c <_ZN7CSprite12ClearSWFDataEv+0x1bc> */
/* @0x1e6a10 mov r4, #0 */
/* @0x1e6a14 b 0x1e6a30 <_ZN7CSprite12ClearSWFDataEv+0x180> */
/* @0x1e6a18 mov r0, r6 */
/* @0x1e6a1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6a20 ldr r3, [r5, #0x10] */
/* @0x1e6a24 ldr r0, [r5, #0x4] */
/* @0x1e6a28 cmp r3, r4 */
/* @0x1e6a2c bls 0x1e6a6c <_ZN7CSprite12ClearSWFDataEv+0x1bc> */
/* @0x1e6a30 ldr r6, [r0, r4, lsl #2] */
/* @0x1e6a34 lsl r7, r4, #2 */
/* @0x1e6a38 add r4, r4, #1 */
/* @0x1e6a3c ldr r3, [r6] */
/* @0x1e6a40 cmp r3, #2 */
/* @0x1e6a44 bne 0x1e6a18 <_ZN7CSprite12ClearSWFDataEv+0x168> */
/* @0x1e6a48 ldr r0, [r6, #0x50] */
/* @0x1e6a4c cmp r0, #0 */
/* @0x1e6a50 beq 0x1e6a58 <_ZN7CSprite12ClearSWFDataEv+0x1a8> */
/* @0x1e6a54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6a58 ldr r0, [r6, #0x54] */
/* @0x1e6a5c bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x1e6a60 ldr r3, [r5, #0x4] */
/* @0x1e6a64 ldr r6, [r3, r7] */
/* @0x1e6a68 b 0x1e6a18 <_ZN7CSprite12ClearSWFDataEv+0x168> */
/* @0x1e6a6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6a70 ldr r0, [r5, #0x8] */
/* @0x1e6a74 cmp r0, #0 */
/* @0x1e6a78 beq 0x1e6a80 <_ZN7CSprite12ClearSWFDataEv+0x1d0> */
/* @0x1e6a7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6a80 ldr r3, [r9, #0x1c] */
/* @0x1e6a84 add r10, r10, #1 */
/* @0x1e6a88 add r8, r8, #24 */
/* @0x1e6a8c ldr r0, [r9, #0x8] */
/* @0x1e6a90 cmp r3, r10 */
/* @0x1e6a94 bhi 0x1e6940 <_ZN7CSprite12ClearSWFDataEv+0x90> */
/* @0x1e6a98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6a9c b 0x1e68e8 <_ZN7CSprite12ClearSWFDataEv+0x38> */
/* @0x1e6aa0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6aa4 ldr r2, [sp, #0x4] */
/* @0x1e6aa8 mov r3, #0 */
/* @0x1e6aac str r3, [r2, #0x7c] */
/* @0x1e6ab0 str r3, [r2, #0x80] */
/* @0x1e6ab4 ldr r2, [sp, #0x4] */
/* @0x1e6ab8 ldr r3, [r2, #0x84] */
/* @0x1e6abc cmp r3, #0 */
/* @0x1e6ac0 mov r0, r3 */
/* @0x1e6ac4 beq 0x1e6b38 <_ZN7CSprite12ClearSWFDataEv+0x288> */
/* @0x1e6ac8 ldr r2, [r3] */
/* @0x1e6acc cmp r2, #0 */
/* @0x1e6ad0 beq 0x1e6b28 <_ZN7CSprite12ClearSWFDataEv+0x278> */
/* @0x1e6ad4 ldr r1, [r3, #0x18] */
/* @0x1e6ad8 cmp r1, #0 */
/* @0x1e6adc ble 0x1e6b18 <_ZN7CSprite12ClearSWFDataEv+0x268> */
/* @0x1e6ae0 mov r4, #0 */
/* @0x1e6ae4 mov r5, r4 */
/* @0x1e6ae8 ldr r0, [r2, r4] */
/* @0x1e6aec add r5, r5, #1 */
/* @0x1e6af0 add r4, r4, #24 */
/* @0x1e6af4 cmp r0, #0 */
/* @0x1e6af8 beq 0x1e6b08 <_ZN7CSprite12ClearSWFDataEv+0x258> */
/* @0x1e6afc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6b00 ldr r2, [sp, #0x4] */
/* @0x1e6b04 ldr r3, [r2, #0x84] */
/* @0x1e6b08 ldr r2, [r3, #0x18] */
/* @0x1e6b0c cmp r2, r5 */
/* @0x1e6b10 ldr r2, [r3] */
/* @0x1e6b14 bgt 0x1e6ae8 <_ZN7CSprite12ClearSWFDataEv+0x238> */
/* @0x1e6b18 mov r0, r2 */
/* @0x1e6b1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6b20 ldr r3, [sp, #0x4] */
/* @0x1e6b24 ldr r0, [r3, #0x84] */
/* @0x1e6b28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6b2c ldr r2, [sp, #0x4] */
/* @0x1e6b30 mov r3, #0 */
/* @0x1e6b34 str r3, [r2, #0x84] */
/* @0x1e6b38 add sp, sp, #12 */
/* @0x1e6b3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e6b40 ldr r0, [r9, #0x8] */
/* @0x1e6b44 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x1e6b48 b 0x1e68e8 <_ZN7CSprite12ClearSWFDataEv+0x38> */

/* ── FUNC 0x1e6b4c · CSprite::Clear() · size=356 · insn=89 */
/* @0x1e6b4c ldr r3, [r0, #0x74] */
/* @0x1e6b50 push {r4, r5, r6, lr} */
/* @0x1e6b54 cmp r3, #1 */
/* @0x1e6b58 mov r4, r0 */
/* @0x1e6b5c beq 0x1e6ca8 <_ZN7CSprite5ClearEv+0x15c> */
/* @0x1e6b60 ldr r5, [r4, #0x58] */
/* @0x1e6b64 cmp r5, #0 */
/* @0x1e6b68 beq 0x1e6b84 <_ZN7CSprite5ClearEv+0x38> */
/* @0x1e6b6c mov r0, r5 */
/* @0x1e6b70 bl 0xbd910 <_ZN15CSkeletonSpriteD2Ev> */
/* @0x1e6b74 mov r0, r5 */
/* @0x1e6b78 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e6b7c mov r3, #0 */
/* @0x1e6b80 str r3, [r4, #0x58] */
/* @0x1e6b84 ldr r0, [r4, #0x54] */
/* @0x1e6b88 cmp r0, #0 */
/* @0x1e6b8c beq 0x1e6b9c <_ZN7CSprite5ClearEv+0x50> */
/* @0x1e6b90 ldrb r3, [r4, #0x36] */
/* @0x1e6b94 cmp r3, #0 */
/* @0x1e6b98 bne 0x1e6c6c <_ZN7CSprite5ClearEv+0x120> */
/* @0x1e6b9c ldr r2, [r4, #0x44] */
/* @0x1e6ba0 cmp r2, #0 */
/* @0x1e6ba4 movgt r5, #0 */
/* @0x1e6ba8 movgt r6, r5 */
/* @0x1e6bac ble 0x1e6be8 <_ZN7CSprite5ClearEv+0x9c> */
/* @0x1e6bb0 ldr r3, [r4, #0x48] */
/* @0x1e6bb4 ldr r3, [r3, r5, lsl #2] */
/* @0x1e6bb8 cmp r3, #0 */
/* @0x1e6bbc mov r0, r3 */
/* @0x1e6bc0 beq 0x1e6bdc <_ZN7CSprite5ClearEv+0x90> */
/* @0x1e6bc4 ldr r3, [r3] */
/* @0x1e6bc8 ldr r3, [r3, #0x4] */
/* @0x1e6bcc blx r3 */
/* @0x1e6bd0 ldr r3, [r4, #0x48] */
/* @0x1e6bd4 ldr r2, [r4, #0x44] */
/* @0x1e6bd8 str r6, [r3, r5, lsl #2] */
/* @0x1e6bdc add r5, r5, #1 */
/* @0x1e6be0 cmp r2, r5 */
/* @0x1e6be4 bgt 0x1e6bb0 <_ZN7CSprite5ClearEv+0x64> */
/* @0x1e6be8 mov r0, r4 */
/* @0x1e6bec mov r5, #0 */
/* @0x1e6bf0 bl 0x1e56fc <_ZN7CSprite11FreeTextureEv> */
/* @0x1e6bf4 ldr r0, [r4, #0x48] */
/* @0x1e6bf8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6bfc ldr r0, [r4, #0x50] */
/* @0x1e6c00 str r5, [r4, #0x48] */
/* @0x1e6c04 str r5, [r4, #0x44] */
/* @0x1e6c08 str r5, [r4, #0x18] */
/* @0x1e6c0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6c10 mov r1, r5 */
/* @0x1e6c14 mov r2, #16 */
/* @0x1e6c18 str r5, [r4, #0x50] */
/* @0x1e6c1c str r5, [r4, #0x4c] */
/* @0x1e6c20 add r0, r4, #8 */
/* @0x1e6c24 bl 0xb65b0 <memset@plt> */
/* @0x1e6c28 mov r3, #1 */
/* @0x1e6c2c strb r5, [r4, #0x33] */
/* @0x1e6c30 mov r0, r4 */
/* @0x1e6c34 str r5, [r4, #0x4] */
/* @0x1e6c38 str r5, [r4, #0x24] */
/* @0x1e6c3c str r5, [r4, #0x28] */
/* @0x1e6c40 str r5, [r4, #0x54] */
/* @0x1e6c44 str r3, [r4, #0x1c] */
/* @0x1e6c48 str r3, [r4, #0x20] */
/* @0x1e6c4c strb r3, [r4, #0x32] */
/* @0x1e6c50 strb r3, [r4, #0x34] */
/* @0x1e6c54 strb r3, [r4, #0x30] */
/* @0x1e6c58 bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv> */
/* @0x1e6c5c str r5, [r4, #0x5c] */
/* @0x1e6c60 str r5, [r4, #0x60] */
/* @0x1e6c64 str r5, [r4, #0x74] */
/* @0x1e6c68 pop {r4, r5, r6, pc} */
/* @0x1e6c6c ldr r3, [r4, #0x44] */
/* @0x1e6c70 cmp r3, #0 */
/* @0x1e6c74 ble 0x1e6c98 <_ZN7CSprite5ClearEv+0x14c> */
/* @0x1e6c78 mov r5, #0 */
/* @0x1e6c7c ldr r0, [r0, r5, lsl #2] */
/* @0x1e6c80 add r5, r5, #1 */
/* @0x1e6c84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6c88 ldr r3, [r4, #0x44] */
/* @0x1e6c8c ldr r0, [r4, #0x54] */
/* @0x1e6c90 cmp r3, r5 */
/* @0x1e6c94 bgt 0x1e6c7c <_ZN7CSprite5ClearEv+0x130> */
/* @0x1e6c98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e6c9c mov r3, #0 */
/* @0x1e6ca0 strb r3, [r4, #0x36] */
/* @0x1e6ca4 b 0x1e6b9c <_ZN7CSprite5ClearEv+0x50> */
/* @0x1e6ca8 bl 0x1e68b0 <_ZN7CSprite12ClearSWFDataEv> */
/* @0x1e6cac b 0x1e6b60 <_ZN7CSprite5ClearEv+0x14> */

/* ── FUNC 0x1e6cb0 · CSprite::LoadFromAnimation(IBitmapLoader*, bool, bool) · size=340 · insn=85 */
/* @0x1e6cb0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1e6cb4 mov r7, r1 */
/* @0x1e6cb8 mov r5, r0 */
/* @0x1e6cbc mov r4, r2 */
/* @0x1e6cc0 mov r6, r3 */
/* @0x1e6cc4 bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e6cc8 ldr r3, [r7] */
/* @0x1e6ccc mov r0, r7 */
/* @0x1e6cd0 strb r4, [r5, #0x32] */
/* @0x1e6cd4 strb r6, [r5, #0x33] */
/* @0x1e6cd8 ldr r3, [r3, #0xc] */
/* @0x1e6cdc blx r3 */
/* @0x1e6ce0 ldr r2, [pc, #0x118] */
/* @0x1e6ce4 movw r3, #0x4c6 */
/* @0x1e6ce8 add r2, pc, r2 */
/* @0x1e6cec lsl r1, r0, #2 */
/* @0x1e6cf0 str r0, [r5, #0x18] */
/* @0x1e6cf4 add r0, r5, #72 */
/* @0x1e6cf8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e6cfc ldr r3, [r5, #0x18] */
/* @0x1e6d00 cmp r3, #0 */
/* @0x1e6d04 str r3, [r5, #0x44] */
/* @0x1e6d08 pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e6d0c mov r4, #0 */
/* @0x1e6d10 mov r9, r4 */
/* @0x1e6d14 b 0x1e6d64 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0xb4> */
/* @0x1e6d18 mov r0, #24 */
/* @0x1e6d1c bl 0x27c524 <_Znwj> */
/* @0x1e6d20 ldrb r3, [r5, #0x33] */
/* @0x1e6d24 mov r1, r6 */
/* @0x1e6d28 ldrb r2, [r5, #0x32] */
/* @0x1e6d2c mov r10, r0 */
/* @0x1e6d30 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0x1e6d34 ldr r3, [r5, #0x48] */
/* @0x1e6d38 cmp r6, #0 */
/* @0x1e6d3c str r10, [r3, r8] */
/* @0x1e6d40 beq 0x1e6d54 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0xa4> */
/* @0x1e6d44 ldr r3, [r6] */
/* @0x1e6d48 mov r0, r6 */
/* @0x1e6d4c ldr r3, [r3, #0x4] */
/* @0x1e6d50 blx r3 */
/* @0x1e6d54 ldr r3, [r5, #0x18] */
/* @0x1e6d58 add r4, r4, #1 */
/* @0x1e6d5c cmp r3, r4 */
/* @0x1e6d60 ble 0x1e6dfc <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0x14c> */
/* @0x1e6d64 ldr r3, [r5, #0x48] */
/* @0x1e6d68 lsl r8, r4, #2 */
/* @0x1e6d6c ldr r3, [r3, r4, lsl #2] */
/* @0x1e6d70 cmp r3, #0 */
/* @0x1e6d74 mov r0, r3 */
/* @0x1e6d78 beq 0x1e6d90 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0xe0> */
/* @0x1e6d7c ldr r3, [r3] */
/* @0x1e6d80 ldr r3, [r3, #0x4] */
/* @0x1e6d84 blx r3 */
/* @0x1e6d88 ldr r3, [r5, #0x48] */
/* @0x1e6d8c str r9, [r3, r4, lsl #2] */
/* @0x1e6d90 ldr r3, [r7] */
/* @0x1e6d94 mov r0, r7 */
/* @0x1e6d98 mov r1, r4 */
/* @0x1e6d9c ldr r3, [r3, #0x10] */
/* @0x1e6da0 blx r3 */
/* @0x1e6da4 cmp r4, #0 */
/* @0x1e6da8 mov r6, r0 */
/* @0x1e6dac bne 0x1e6d18 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0x68> */
/* @0x1e6db0 ldr r3, [r0] */
/* @0x1e6db4 ldr r3, [r3, #0x10] */
/* @0x1e6db8 blx r3 */
/* @0x1e6dbc ldr r3, [r6] */
/* @0x1e6dc0 ldr r3, [r3, #0x18] */
/* @0x1e6dc4 str r0, [r5, #0x1c] */
/* @0x1e6dc8 mov r0, r6 */
/* @0x1e6dcc blx r3 */
/* @0x1e6dd0 str r0, [r5, #0x20] */
/* @0x1e6dd4 mov r0, #24 */
/* @0x1e6dd8 bl 0x27c524 <_Znwj> */
/* @0x1e6ddc ldrb r3, [r5, #0x33] */
/* @0x1e6de0 mov r1, r6 */
/* @0x1e6de4 ldrb r2, [r5, #0x32] */
/* @0x1e6de8 mov r10, r0 */
/* @0x1e6dec bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0x1e6df0 ldr r3, [r5, #0x48] */
/* @0x1e6df4 str r10, [r3, r8] */
/* @0x1e6df8 b 0x1e6d44 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0x94> */
/* @0x1e6dfc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e6e00 andseq r11, r6, r12, lsr r7 */

/* ── FUNC 0x1e6e04 · CSprite::LoadStrip(IBitmapLoader*, bool, bool, int, bool) · size=464 · insn=116 */
/* @0x1e6e04 ldr r12, [r1] */
/* @0x1e6e08 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e6e0c sub sp, sp, #12 */
/* @0x1e6e10 mov r4, r0 */
/* @0x1e6e14 mov r9, r3 */
/* @0x1e6e18 mov r0, r1 */
/* @0x1e6e1c ldr r3, [r12, #0x10] */
/* @0x1e6e20 mov r1, #0 */
/* @0x1e6e24 mov r8, r2 */
/* @0x1e6e28 ldr r6, [sp, #0x28] */
/* @0x1e6e2c ldrb r7, [sp, #0x2c] */
/* @0x1e6e30 blx r3 */
/* @0x1e6e34 mov r5, r0 */
/* @0x1e6e38 mov r0, r4 */
/* @0x1e6e3c bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e6e40 cmp r5, #0 */
/* @0x1e6e44 strb r8, [r4, #0x32] */
/* @0x1e6e48 strb r9, [r4, #0x33] */
/* @0x1e6e4c str r6, [r4, #0x18] */
/* @0x1e6e50 beq 0x1e6fa4 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x1a0> */
/* @0x1e6e54 cmp r6, #0 */
/* @0x1e6e58 mov r0, r5 */
/* @0x1e6e5c movle r3, #1 */
/* @0x1e6e60 strle r3, [r4, #0x18] */
/* @0x1e6e64 ldr r3, [r5] */
/* @0x1e6e68 ldr r3, [r3, #0x10] */
/* @0x1e6e6c blx r3 */
/* @0x1e6e70 ldr r1, [r4, #0x18] */
/* @0x1e6e74 bl 0x318d10 <__divsi3> */
/* @0x1e6e78 ldr r3, [r5] */
/* @0x1e6e7c ldr r3, [r3, #0x18] */
/* @0x1e6e80 str r0, [r4, #0x1c] */
/* @0x1e6e84 mov r0, r5 */
/* @0x1e6e88 blx r3 */
/* @0x1e6e8c cmp r7, #0 */
/* @0x1e6e90 str r0, [r4, #0x20] */
/* @0x1e6e94 mov r0, #24 */
/* @0x1e6e98 bne 0x1e6f80 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x17c> */
/* @0x1e6e9c bl 0x27c524 <_Znwj> */
/* @0x1e6ea0 ldrb r2, [r4, #0x32] */
/* @0x1e6ea4 ldrb r3, [r4, #0x33] */
/* @0x1e6ea8 mov r1, r5 */
/* @0x1e6eac str r7, [sp] */
/* @0x1e6eb0 mov r8, r0 */
/* @0x1e6eb4 bl 0x167188 <_ZN9CBitmap32C2EP7IBitmapbbb> */
/* @0x1e6eb8 ldr r3, [r5] */
/* @0x1e6ebc mov r0, r5 */
/* @0x1e6ec0 ldr r3, [r3, #0x4] */
/* @0x1e6ec4 blx r3 */
/* @0x1e6ec8 ldr r1, [r4, #0x18] */
/* @0x1e6ecc ldr r2, [pc, #0xf4] */
/* @0x1e6ed0 movw r3, #0x512 */
/* @0x1e6ed4 add r0, r4, #72 */
/* @0x1e6ed8 add r2, pc, r2 */
/* @0x1e6edc lsl r1, r1, #2 */
/* @0x1e6ee0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e6ee4 ldr r3, [r4, #0x18] */
/* @0x1e6ee8 cmp r3, #0 */
/* @0x1e6eec str r3, [r4, #0x44] */
/* @0x1e6ef0 movgt r5, #0 */
/* @0x1e6ef4 ble 0x1e6f60 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x15c> */
/* @0x1e6ef8 ldr r3, [r4, #0x48] */
/* @0x1e6efc lsl r6, r5, #2 */
/* @0x1e6f00 ldr r3, [r3, r5, lsl #2] */
/* @0x1e6f04 cmp r3, #0 */
/* @0x1e6f08 mov r0, r3 */
/* @0x1e6f0c beq 0x1e6f1c <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x118> */
/* @0x1e6f10 ldr r3, [r3] */
/* @0x1e6f14 ldr r3, [r3, #0x4] */
/* @0x1e6f18 blx r3 */
/* @0x1e6f1c mov r0, #24 */
/* @0x1e6f20 bl 0x27c524 <_Znwj> */
/* @0x1e6f24 ldr r2, [r4, #0x1c] */
/* @0x1e6f28 ldr r12, [r4, #0x20] */
/* @0x1e6f2c mov r3, #0 */
/* @0x1e6f30 mov r1, r8 */
/* @0x1e6f34 str r2, [sp] */
/* @0x1e6f38 str r12, [sp, #0x4] */
/* @0x1e6f3c mul r2, r5, r2 */
/* @0x1e6f40 add r5, r5, #1 */
/* @0x1e6f44 mov r7, r0 */
/* @0x1e6f48 bl 0x166020 <_ZN9CBitmap32C2EPS_iiii> */
/* @0x1e6f4c ldr r2, [r4, #0x18] */
/* @0x1e6f50 ldr r3, [r4, #0x48] */
/* @0x1e6f54 cmp r2, r5 */
/* @0x1e6f58 str r7, [r3, r6] */
/* @0x1e6f5c bgt 0x1e6ef8 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0xf4> */
/* @0x1e6f60 cmp r8, #0 */
/* @0x1e6f64 beq 0x1e6f78 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x174> */
/* @0x1e6f68 ldr r3, [r8] */
/* @0x1e6f6c mov r0, r8 */
/* @0x1e6f70 ldr r3, [r3, #0x4] */
/* @0x1e6f74 blx r3 */
/* @0x1e6f78 add sp, sp, #12 */
/* @0x1e6f7c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e6f80 bl 0x27c524 <_Znwj> */
/* @0x1e6f84 mov r2, #0 */
/* @0x1e6f88 mov r1, #1 */
/* @0x1e6f8c mov r3, r2 */
/* @0x1e6f90 str r1, [sp] */
/* @0x1e6f94 mov r1, r5 */
/* @0x1e6f98 mov r8, r0 */
/* @0x1e6f9c bl 0x167188 <_ZN9CBitmap32C2EP7IBitmapbbb> */
/* @0x1e6fa0 b 0x1e6eb8 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0xb4> */
/* @0x1e6fa4 ldr r3, [pc, #0x20] */
/* @0x1e6fa8 ldr r1, [pc, #0x20] */
/* @0x1e6fac ldr r3, [pc, r3] */
/* @0x1e6fb0 add r1, pc, r1 */
/* @0x1e6fb4 ldr r0, [r3] */
/* @0x1e6fb8 ldr r3, [r0] */
/* @0x1e6fbc ldr r3, [r3, #0xc] */
/* @0x1e6fc0 blx r3 */
/* @0x1e6fc4 b 0x1e6f78 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x174> */
/* @0x1e6fc8 andseq r11, r6, r12, asr #10 */
/* @0x1e6fcc eoreq r6, r0, r8, ror #14 */
/* @0x1e6fd0 andseq r11, r6, r8, lsl #12 */

/* ── FUNC 0x1e6fd4 · CSprite::LoadFromData(void*, int, int, int, bool, bool, bool, int, int, bool) · size=220 · insn=55 */
/* @0x1e6fd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e6fd8 sub sp, sp, #12 */
/* @0x1e6fdc mov r4, r0 */
/* @0x1e6fe0 mov r0, r1 */
/* @0x1e6fe4 mov r1, r2 */
/* @0x1e6fe8 mov r2, r3 */
/* @0x1e6fec ldrb r8, [sp, #0x34] */
/* @0x1e6ff0 ldrb r10, [sp, #0x38] */
/* @0x1e6ff4 ldrb r9, [sp, #0x3c] */
/* @0x1e6ff8 ldr r7, [sp, #0x40] */
/* @0x1e6ffc ldr r6, [sp, #0x44] */
/* @0x1e7000 ldrb r11, [sp, #0x48] */
/* @0x1e7004 bl 0x1a928c <_ZN13IBitmapLoader6CreateEPvii> */
/* @0x1e7008 ldr r3, [r0] */
/* @0x1e700c mov r5, r0 */
/* @0x1e7010 ldr r3, [r3, #0x8] */
/* @0x1e7014 blx r3 */
/* @0x1e7018 cmp r0, #0 */
/* @0x1e701c beq 0x1e708c <_ZN7CSprite12LoadFromDataEPviiibbbiib+0xb8> */
/* @0x1e7020 mov r2, r10 */
/* @0x1e7024 mov r3, r9 */
/* @0x1e7028 mov r0, r4 */
/* @0x1e702c mov r1, r5 */
/* @0x1e7030 bl 0x1e6cb0 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb> */
/* @0x1e7034 ldr r3, [r5] */
/* @0x1e7038 mov r0, r5 */
/* @0x1e703c mov r5, #1 */
/* @0x1e7040 ldr r3, [r3, #0x4] */
/* @0x1e7044 blx r3 */
/* @0x1e7048 mov r3, #0 */
/* @0x1e704c mov r0, r4 */
/* @0x1e7050 str r3, [r4, #0x4] */
/* @0x1e7054 strb r8, [r4, #0x30] */
/* @0x1e7058 str r7, [r4, #0x24] */
/* @0x1e705c str r6, [r4, #0x28] */
/* @0x1e7060 strb r5, [r4, #0x34] */
/* @0x1e7064 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1e7068 mov r0, r4 */
/* @0x1e706c bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1e7070 mov r0, r4 */
/* @0x1e7074 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv> */
/* @0x1e7078 mov r0, r4 */
/* @0x1e707c bl 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */
/* @0x1e7080 mov r0, r5 */
/* @0x1e7084 add sp, sp, #12 */
/* @0x1e7088 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e708c ldr r3, [sp, #0x30] */
/* @0x1e7090 mov r2, r10 */
/* @0x1e7094 str r11, [sp, #0x4] */
/* @0x1e7098 mov r0, r4 */
/* @0x1e709c mov r1, r5 */
/* @0x1e70a0 str r3, [sp] */
/* @0x1e70a4 mov r3, r9 */
/* @0x1e70a8 bl 0x1e6e04 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib> */
/* @0x1e70ac b 0x1e7034 <_ZN7CSprite12LoadFromDataEPviiibbbiib+0x60> */

/* ── FUNC 0x1e70b0 · CSprite::LoadFromPNGData(void*, int, int, bool, bool, bool, int, int, bool) · size=144 · insn=36 */
/* @0x1e70b0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e70b4 sub sp, sp, #44 */
/* @0x1e70b8 mov r12, #0 */
/* @0x1e70bc mov r9, r0 */
/* @0x1e70c0 mov r8, r3 */
/* @0x1e70c4 mov r0, r1 */
/* @0x1e70c8 str r12, [sp] */
/* @0x1e70cc mov r1, r2 */
/* @0x1e70d0 add r3, sp, #36 */
/* @0x1e70d4 add r2, sp, #32 */
/* @0x1e70d8 ldrb r4, [sp, #0x5c] */
/* @0x1e70dc ldrb r7, [sp, #0x48] */
/* @0x1e70e0 ldrb r6, [sp, #0x4c] */
/* @0x1e70e4 ldrb r5, [sp, #0x50] */
/* @0x1e70e8 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0x1e70ec subs r1, r0, #0 */
/* @0x1e70f0 moveq r4, r1 */
/* @0x1e70f4 beq 0x1e7134 <_ZN7CSprite15LoadFromPNGDataEPviibbbiib+0x84> */
/* @0x1e70f8 ldr r12, [sp, #0x54] */
/* @0x1e70fc mov r0, r9 */
/* @0x1e7100 str r4, [sp, #0x18] */
/* @0x1e7104 ldr r2, [sp, #0x20] */
/* @0x1e7108 str r12, [sp, #0x10] */
/* @0x1e710c ldr r12, [sp, #0x58] */
/* @0x1e7110 ldr r3, [sp, #0x24] */
/* @0x1e7114 str r8, [sp] */
/* @0x1e7118 str r7, [sp, #0x4] */
/* @0x1e711c str r6, [sp, #0x8] */
/* @0x1e7120 str r5, [sp, #0xc] */
/* @0x1e7124 str r12, [sp, #0x14] */
/* @0x1e7128 bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib> */
/* @0x1e712c mov r4, r0 */
/* @0x1e7130 bl 0x18a518 <_Z11FreePNGFilev> */
/* @0x1e7134 mov r0, r4 */
/* @0x1e7138 add sp, sp, #44 */
/* @0x1e713c pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1e7140 · CSprite::LoadFromJPEGData(void*, int, int, bool, bool, bool, int, int, bool) · size=152 · insn=38 */
/* @0x1e7140 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1e7144 sub sp, sp, #40 */
/* @0x1e7148 mov r12, #0 */
/* @0x1e714c mov r10, r0 */
/* @0x1e7150 mov r9, r3 */
/* @0x1e7154 mov r0, r1 */
/* @0x1e7158 str r12, [sp] */
/* @0x1e715c mov r1, r2 */
/* @0x1e7160 add r3, sp, #36 */
/* @0x1e7164 add r2, sp, #32 */
/* @0x1e7168 ldrb r8, [sp, #0x48] */
/* @0x1e716c ldrb r7, [sp, #0x4c] */
/* @0x1e7170 ldrb r6, [sp, #0x50] */
/* @0x1e7174 ldrb r5, [sp, #0x5c] */
/* @0x1e7178 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b> */
/* @0x1e717c subs r4, r0, #0 */
/* @0x1e7180 moveq r0, r4 */
/* @0x1e7184 beq 0x1e71d0 <_ZN7CSprite16LoadFromJPEGDataEPviibbbiib+0x90> */
/* @0x1e7188 ldr r12, [sp, #0x54] */
/* @0x1e718c mov r1, r4 */
/* @0x1e7190 ldr r2, [sp, #0x20] */
/* @0x1e7194 mov r0, r10 */
/* @0x1e7198 ldr r3, [sp, #0x24] */
/* @0x1e719c str r12, [sp, #0x10] */
/* @0x1e71a0 ldr r12, [sp, #0x58] */
/* @0x1e71a4 str r5, [sp, #0x18] */
/* @0x1e71a8 str r9, [sp] */
/* @0x1e71ac str r12, [sp, #0x14] */
/* @0x1e71b0 str r8, [sp, #0x4] */
/* @0x1e71b4 str r7, [sp, #0x8] */
/* @0x1e71b8 str r6, [sp, #0xc] */
/* @0x1e71bc bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib> */
/* @0x1e71c0 mov r5, r0 */
/* @0x1e71c4 mov r0, r4 */
/* @0x1e71c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e71cc mov r0, r5 */
/* @0x1e71d0 add sp, sp, #40 */
/* @0x1e71d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x1e71d8 · CSprite::LoadFromGIFData(void*, int, int, bool, bool, bool, int, int, bool) · size=152 · insn=38 */
/* @0x1e71d8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1e71dc sub sp, sp, #40 */
/* @0x1e71e0 mov r12, #0 */
/* @0x1e71e4 mov r10, r0 */
/* @0x1e71e8 mov r9, r3 */
/* @0x1e71ec mov r0, r1 */
/* @0x1e71f0 str r12, [sp] */
/* @0x1e71f4 mov r1, r2 */
/* @0x1e71f8 add r3, sp, #36 */
/* @0x1e71fc add r2, sp, #32 */
/* @0x1e7200 ldrb r8, [sp, #0x48] */
/* @0x1e7204 ldrb r7, [sp, #0x4c] */
/* @0x1e7208 ldrb r6, [sp, #0x50] */
/* @0x1e720c ldrb r5, [sp, #0x5c] */
/* @0x1e7210 bl 0x18a918 <_Z11ReadGIFFilePviPiS0_b> */
/* @0x1e7214 subs r4, r0, #0 */
/* @0x1e7218 moveq r0, r4 */
/* @0x1e721c beq 0x1e7268 <_ZN7CSprite15LoadFromGIFDataEPviibbbiib+0x90> */
/* @0x1e7220 ldr r12, [sp, #0x54] */
/* @0x1e7224 mov r1, r4 */
/* @0x1e7228 ldr r2, [sp, #0x20] */
/* @0x1e722c mov r0, r10 */
/* @0x1e7230 ldr r3, [sp, #0x24] */
/* @0x1e7234 str r12, [sp, #0x10] */
/* @0x1e7238 ldr r12, [sp, #0x58] */
/* @0x1e723c str r5, [sp, #0x18] */
/* @0x1e7240 str r9, [sp] */
/* @0x1e7244 str r12, [sp, #0x14] */
/* @0x1e7248 str r8, [sp, #0x4] */
/* @0x1e724c str r7, [sp, #0x8] */
/* @0x1e7250 str r6, [sp, #0xc] */
/* @0x1e7254 bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib> */
/* @0x1e7258 mov r5, r0 */
/* @0x1e725c mov r0, r4 */
/* @0x1e7260 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e7264 mov r0, r5 */
/* @0x1e7268 add sp, sp, #40 */
/* @0x1e726c pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x1e7270 · CSprite::LoadFromFile(char const*, int, bool, bool, bool, bool, int, int, bool) · size=572 · insn=143 */
/* @0x1e7270 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e7274 mov r5, r0 */
/* @0x1e7278 sub sp, sp, #36 */
/* @0x1e727c mov r0, r1 */
/* @0x1e7280 mov r4, r1 */
/* @0x1e7284 mov r6, r2 */
/* @0x1e7288 mov r7, r3 */
/* @0x1e728c bl 0xb6538 <strlen@plt> */
/* @0x1e7290 ldrb r8, [sp, #0x48] */
/* @0x1e7294 ldrb r9, [sp, #0x4c] */
/* @0x1e7298 ldrb r10, [sp, #0x5c] */
/* @0x1e729c cmp r0, #4 */
/* @0x1e72a0 ble 0x1e72c0 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x50> */
/* @0x1e72a4 sub r1, r0, #5 */
/* @0x1e72a8 ldr r0, [pc, #0x1f8] */
/* @0x1e72ac add r1, r4, r1 */
/* @0x1e72b0 add r0, pc, r0 */
/* @0x1e72b4 bl 0xb66d0 <strcasecmp@plt> */
/* @0x1e72b8 cmp r0, #0 */
/* @0x1e72bc beq 0x1e73d0 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x160> */
/* @0x1e72c0 mov r0, r4 */
/* @0x1e72c4 mov r3, #0 */
/* @0x1e72c8 str r3, [sp, #0x1c] */
/* @0x1e72cc bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1e72d0 cmp r0, #0 */
/* @0x1e72d4 beq 0x1e73a4 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x134> */
/* @0x1e72d8 mov r0, r4 */
/* @0x1e72dc add r1, sp, #28 */
/* @0x1e72e0 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x1e72e4 mov r11, r0 */
/* @0x1e72e8 cmp r11, #0 */
/* @0x1e72ec moveq r4, r11 */
/* @0x1e72f0 beq 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c> */
/* @0x1e72f4 ldrb r3, [r11] */
/* @0x1e72f8 cmp r3, #255 */
/* @0x1e72fc beq 0x1e7410 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x1a0> */
/* @0x1e7300 cmp r3, #71 */
/* @0x1e7304 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8> */
/* @0x1e7308 ldrb r3, [r11, #0x1] */
/* @0x1e730c cmp r3, #73 */
/* @0x1e7310 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8> */
/* @0x1e7314 ldrb r3, [r11, #0x2] */
/* @0x1e7318 cmp r3, #70 */
/* @0x1e731c bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8> */
/* @0x1e7320 ldrb r3, [r11, #0x3] */
/* @0x1e7324 cmp r3, #56 */
/* @0x1e7328 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8> */
/* @0x1e732c ldr r2, [sp, #0x54] */
/* @0x1e7330 mov r0, r5 */
/* @0x1e7334 ldr r12, [sp, #0x58] */
/* @0x1e7338 mov r1, r11 */
/* @0x1e733c str r7, [sp] */
/* @0x1e7340 mov r3, r6 */
/* @0x1e7344 str r2, [sp, #0xc] */
/* @0x1e7348 str r8, [sp, #0x4] */
/* @0x1e734c str r9, [sp, #0x8] */
/* @0x1e7350 str r12, [sp, #0x10] */
/* @0x1e7354 str r10, [sp, #0x14] */
/* @0x1e7358 ldr r2, [sp, #0x1c] */
/* @0x1e735c bl 0x1e71d8 <_ZN7CSprite15LoadFromGIFDataEPviibbbiib> */
/* @0x1e7360 subs r4, r0, #0 */
/* @0x1e7364 bne 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c> */
/* @0x1e7368 ldr r12, [sp, #0x54] */
/* @0x1e736c mov r0, r5 */
/* @0x1e7370 ldr r2, [sp, #0x1c] */
/* @0x1e7374 mov r3, r6 */
/* @0x1e7378 str r7, [sp] */
/* @0x1e737c mov r1, r11 */
/* @0x1e7380 str r12, [sp, #0xc] */
/* @0x1e7384 ldr r12, [sp, #0x58] */
/* @0x1e7388 str r8, [sp, #0x4] */
/* @0x1e738c str r9, [sp, #0x8] */
/* @0x1e7390 str r12, [sp, #0x10] */
/* @0x1e7394 str r10, [sp, #0x14] */
/* @0x1e7398 bl 0x1e70b0 <_ZN7CSprite15LoadFromPNGDataEPviibbbiib> */
/* @0x1e739c mov r4, r0 */
/* @0x1e73a0 b 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c> */
/* @0x1e73a4 mov r0, r4 */
/* @0x1e73a8 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1e73ac cmp r0, #0 */
/* @0x1e73b0 moveq r11, r0 */
/* @0x1e73b4 moveq r4, r11 */
/* @0x1e73b8 bne 0x1e7494 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x224> */
/* @0x1e73bc mov r0, r11 */
/* @0x1e73c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e73c4 mov r0, r4 */
/* @0x1e73c8 add sp, sp, #36 */
/* @0x1e73cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e73d0 mov r0, #12 */
/* @0x1e73d4 bl 0x27c524 <_Znwj> */
/* @0x1e73d8 mov r1, r4 */
/* @0x1e73dc mov r11, r0 */
/* @0x1e73e0 bl 0xbdbe0 <_ZN15CSkeletonSpriteC2EPc> */
/* @0x1e73e4 str r11, [r5, #0x58] */
/* @0x1e73e8 mov r0, r11 */
/* @0x1e73ec bl 0xbd96c <_ZN15CSkeletonSprite7HasDataEv> */
/* @0x1e73f0 cmp r0, #0 */
/* @0x1e73f4 beq 0x1e746c <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x1fc> */
/* @0x1e73f8 mvn r2, #-2147483648 */
/* @0x1e73fc mov r3, #2 */
/* @0x1e7400 str r2, [r5, #0x18] */
/* @0x1e7404 mov r4, #1 */
/* @0x1e7408 str r3, [r5, #0x74] */
/* @0x1e740c b 0x1e73c4 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x154> */
/* @0x1e7410 ldrb r3, [r11, #0x1] */
/* @0x1e7414 cmp r3, #216 */
/* @0x1e7418 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8> */
/* @0x1e741c ldrb r3, [r11, #0x2] */
/* @0x1e7420 cmp r3, #255 */
/* @0x1e7424 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8> */
/* @0x1e7428 ldr r12, [sp, #0x54] */
/* @0x1e742c mov r0, r5 */
/* @0x1e7430 ldr r2, [sp, #0x1c] */
/* @0x1e7434 mov r1, r11 */
/* @0x1e7438 str r7, [sp] */
/* @0x1e743c mov r3, r6 */
/* @0x1e7440 str r12, [sp, #0xc] */
/* @0x1e7444 ldr r12, [sp, #0x58] */
/* @0x1e7448 str r8, [sp, #0x4] */
/* @0x1e744c str r9, [sp, #0x8] */
/* @0x1e7450 str r12, [sp, #0x10] */
/* @0x1e7454 str r10, [sp, #0x14] */
/* @0x1e7458 bl 0x1e7140 <_ZN7CSprite16LoadFromJPEGDataEPviibbbiib> */
/* @0x1e745c subs r4, r0, #0 */
/* @0x1e7460 bne 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c> */
/* @0x1e7464 ldrb r3, [r11] */
/* @0x1e7468 b 0x1e7300 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x90> */
/* @0x1e746c ldr r11, [r5, #0x58] */
/* @0x1e7470 cmp r11, #0 */
/* @0x1e7474 beq 0x1e7488 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x218> */
/* @0x1e7478 mov r0, r11 */
/* @0x1e747c bl 0xbd910 <_ZN15CSkeletonSpriteD2Ev> */
/* @0x1e7480 mov r0, r11 */
/* @0x1e7484 bl 0x27d1d0 <_ZdlPv> */
/* @0x1e7488 mov r3, #0 */
/* @0x1e748c str r3, [r5, #0x58] */
/* @0x1e7490 b 0x1e72c0 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x50> */
/* @0x1e7494 mov r0, r4 */
/* @0x1e7498 add r1, sp, #28 */
/* @0x1e749c bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x1e74a0 mov r11, r0 */
/* @0x1e74a4 b 0x1e72e8 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x78> */
/* @0x1e74a8 andseq r11, r6, r12, lsr r3 */

/* ── FUNC 0x1e74ac · CSprite::CreateFromBitmap(IBitmap*, bool, bool, bool, bool, int, int, bool) · size=368 · insn=92 */
/* @0x1e74ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e74b0 sub sp, sp, #28 */
/* @0x1e74b4 mov r5, r1 */
/* @0x1e74b8 mov r10, r2 */
/* @0x1e74bc ldr r1, [r0, #0x5c] */
/* @0x1e74c0 mov r4, r0 */
/* @0x1e74c4 ldrb r2, [sp, #0x40] */
/* @0x1e74c8 mov r6, #1 */
/* @0x1e74cc str r3, [sp, #0x10] */
/* @0x1e74d0 ldrb r11, [sp, #0x44] */
/* @0x1e74d4 str r2, [sp, #0xc] */
/* @0x1e74d8 ldr r9, [sp, #0x48] */
/* @0x1e74dc ldr r8, [sp, #0x4c] */
/* @0x1e74e0 ldrb r7, [sp, #0x50] */
/* @0x1e74e4 str r1, [sp, #0x14] */
/* @0x1e74e8 bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e74ec ldr r12, [r5] */
/* @0x1e74f0 mov r0, r5 */
/* @0x1e74f4 ldr r1, [sp, #0x14] */
/* @0x1e74f8 str r6, [r4, #0x18] */
/* @0x1e74fc str r1, [r4, #0x5c] */
/* @0x1e7500 ldr r1, [r12, #0x10] */
/* @0x1e7504 blx r1 */
/* @0x1e7508 ldr r1, [r5] */
/* @0x1e750c ldr r1, [r1, #0x18] */
/* @0x1e7510 str r0, [r4, #0x1c] */
/* @0x1e7514 mov r0, r5 */
/* @0x1e7518 blx r1 */
/* @0x1e751c ldr r2, [sp, #0xc] */
/* @0x1e7520 ldr r3, [sp, #0x10] */
/* @0x1e7524 mov r1, #4 */
/* @0x1e7528 strb r11, [r4, #0x34] */
/* @0x1e752c strb r2, [r4, #0x33] */
/* @0x1e7530 mov r2, #0 */
/* @0x1e7534 str r2, [r4, #0x4] */
/* @0x1e7538 ldr r2, [pc, #0xd8] */
/* @0x1e753c strb r3, [r4, #0x32] */
/* @0x1e7540 movw r3, #0x62c */
/* @0x1e7544 strb r10, [r4, #0x30] */
/* @0x1e7548 add r2, pc, r2 */
/* @0x1e754c str r9, [r4, #0x24] */
/* @0x1e7550 str r8, [r4, #0x28] */
/* @0x1e7554 str r0, [r4, #0x20] */
/* @0x1e7558 add r0, r4, #72 */
/* @0x1e755c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e7560 ldr r3, [r4, #0x48] */
/* @0x1e7564 cmp r7, #0 */
/* @0x1e7568 str r6, [r4, #0x44] */
/* @0x1e756c ldr r0, [r3] */
/* @0x1e7570 beq 0x1e75dc <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0x130> */
/* @0x1e7574 cmp r0, #0 */
/* @0x1e7578 beq 0x1e7588 <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0xdc> */
/* @0x1e757c ldr r3, [r0] */
/* @0x1e7580 ldr r3, [r3, #0x4] */
/* @0x1e7584 blx r3 */
/* @0x1e7588 mov r0, #24 */
/* @0x1e758c bl 0x27c524 <_Znwj> */
/* @0x1e7590 ldrb r3, [r4, #0x33] */
/* @0x1e7594 ldrb r2, [r4, #0x32] */
/* @0x1e7598 mov r12, #0 */
/* @0x1e759c mov r1, r5 */
/* @0x1e75a0 str r12, [sp] */
/* @0x1e75a4 mov r6, r0 */
/* @0x1e75a8 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi> */
/* @0x1e75ac ldr r3, [r4, #0x48] */
/* @0x1e75b0 str r6, [r3] */
/* @0x1e75b4 mov r0, r4 */
/* @0x1e75b8 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1e75bc mov r0, r4 */
/* @0x1e75c0 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1e75c4 mov r0, r4 */
/* @0x1e75c8 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv> */
/* @0x1e75cc mov r0, r4 */
/* @0x1e75d0 add sp, sp, #28 */
/* @0x1e75d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e75d8 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */
/* @0x1e75dc cmp r0, #0 */
/* @0x1e75e0 beq 0x1e75f0 <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0x144> */
/* @0x1e75e4 ldr r3, [r0] */
/* @0x1e75e8 ldr r3, [r3, #0x4] */
/* @0x1e75ec blx r3 */
/* @0x1e75f0 mov r0, #24 */
/* @0x1e75f4 bl 0x27c524 <_Znwj> */
/* @0x1e75f8 ldrb r3, [r4, #0x33] */
/* @0x1e75fc mov r1, r5 */
/* @0x1e7600 ldrb r2, [r4, #0x32] */
/* @0x1e7604 mov r6, r0 */
/* @0x1e7608 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0x1e760c ldr r3, [r4, #0x48] */
/* @0x1e7610 str r6, [r3] */
/* @0x1e7614 b 0x1e75b4 <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0x108> */
/* @0x1e7618 ldrsbeq r10, [r6], -r12 */

/* ── FUNC 0x1e761c · CSprite::CSprite() · size=136 · insn=34 */
/* @0x1e761c ldr r3, [pc, #0x7c] */
/* @0x1e7620 mov r2, #1 */
/* @0x1e7624 push {r4, lr} */
/* @0x1e7628 ldr r3, [pc, r3] */
/* @0x1e762c mov r4, r0 */
/* @0x1e7630 strb r2, [r0, #0x35] */
/* @0x1e7634 mov r1, #0 */
/* @0x1e7638 add r2, r3, #8 */
/* @0x1e763c movt r1, #0x41f0 */
/* @0x1e7640 mov r3, #0 */
/* @0x1e7644 str r2, [r0] */
/* @0x1e7648 str r3, [r0, #0x40] */
/* @0x1e764c str r3, [r0, #0x3c] */
/* @0x1e7650 str r3, [r0, #0x48] */
/* @0x1e7654 str r3, [r0, #0x44] */
/* @0x1e7658 str r3, [r0, #0x18] */
/* @0x1e765c str r1, [r0, #0x6c] */
/* @0x1e7660 str r3, [r0, #0x50] */
/* @0x1e7664 str r3, [r0, #0x4c] */
/* @0x1e7668 strb r3, [r0, #0x31] */
/* @0x1e766c strb r3, [r0, #0x36] */
/* @0x1e7670 str r3, [r0, #0x74] */
/* @0x1e7674 strb r3, [r0, #0x78] */
/* @0x1e7678 str r3, [r0, #0x7c] */
/* @0x1e767c str r3, [r0, #0x84] */
/* @0x1e7680 str r3, [r0, #0x80] */
/* @0x1e7684 str r3, [r0, #0x58] */
/* @0x1e7688 str r3, [r0, #0x64] */
/* @0x1e768c str r3, [r0, #0x68] */
/* @0x1e7690 str r3, [r0, #0x70] */
/* @0x1e7694 bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e7698 mov r0, r4 */
/* @0x1e769c pop {r4, pc} */
/* @0x1e76a0 eoreq r9, r0, r8, lsr #15 */

/* ── FUNC 0x1e761c · CSprite::CSprite() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1e76a4 · CSprite::~CSprite() · size=40 · insn=10 */
/* @0x1e76a4 ldr r3, [pc, #0x1c] */
/* @0x1e76a8 push {r4, lr} */
/* @0x1e76ac ldr r3, [pc, r3] */
/* @0x1e76b0 mov r4, r0 */
/* @0x1e76b4 add r3, r3, #8 */
/* @0x1e76b8 str r3, [r0] */
/* @0x1e76bc bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e76c0 mov r0, r4 */
/* @0x1e76c4 pop {r4, pc} */
/* @0x1e76c8 eoreq r9, r0, r4, lsr #14 */

/* ── FUNC 0x1e76a4 · CSprite::~CSprite() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1e76cc · CSprite::~CSprite() · size=28 · insn=7 */
/* @0x1e76cc push {r4, lr} */
/* @0x1e76d0 mov r4, r0 */
/* @0x1e76d4 bl 0x1e76a4 <_ZN7CSpriteD2Ev> */
/* @0x1e76d8 mov r0, r4 */
/* @0x1e76dc bl 0x27d1d0 <_ZdlPv> */
/* @0x1e76e0 mov r0, r4 */
/* @0x1e76e4 pop {r4, pc} */

/* ── FUNC 0x1e76e8 · CSprite::Assign(CSprite*) · size=364 · insn=91 */
/* @0x1e76e8 ldr r3, [r1, #0x74] */
/* @0x1e76ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e76f0 cmp r3, #0 */
/* @0x1e76f4 sub sp, sp, #12 */
/* @0x1e76f8 mov r5, r1 */
/* @0x1e76fc mov r4, r0 */
/* @0x1e7700 beq 0x1e770c <_ZN7CSprite6AssignEPS_+0x24> */
/* @0x1e7704 add sp, sp, #12 */
/* @0x1e7708 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1e770c bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e7710 ldr r7, [r5, #0x20] */
/* @0x1e7714 add r3, r5, #8 */
/* @0x1e7718 ldrb lr, [r5, #0x36] */
/* @0x1e771c ldr r6, [r5, #0x1c] */
/* @0x1e7720 add r12, r4, #8 */
/* @0x1e7724 ldm r3, {r0, r1, r2, r3} */
/* @0x1e7728 cmp lr, #0 */
/* @0x1e772c str r7, [r4, #0x20] */
/* @0x1e7730 ldrb r7, [r5, #0x30] */
/* @0x1e7734 ldrb r11, [r5, #0x32] */
/* @0x1e7738 ldrb r10, [r5, #0x33] */
/* @0x1e773c str r7, [sp, #0x4] */
/* @0x1e7740 ldrb r9, [r5, #0x34] */
/* @0x1e7744 ldr r8, [r5, #0x4] */
/* @0x1e7748 ldr r7, [r5, #0x24] */
/* @0x1e774c str r6, [r4, #0x1c] */
/* @0x1e7750 ldr r6, [r5, #0x28] */
/* @0x1e7754 stm r12, {r0, r1, r2, r3} */
/* @0x1e7758 add r0, r4, #72 */
/* @0x1e775c ldr r3, [r5, #0x2c] */
/* @0x1e7760 ldr r2, [r5, #0x18] */
/* @0x1e7764 ldr r1, [sp, #0x4] */
/* @0x1e7768 str r3, [r4, #0x2c] */
/* @0x1e776c str r6, [r4, #0x28] */
/* @0x1e7770 ldreq r3, [r5, #0x54] */
/* @0x1e7774 strb r1, [r4, #0x30] */
/* @0x1e7778 str r2, [r4, #0x18] */
/* @0x1e777c strb r11, [r4, #0x32] */
/* @0x1e7780 strb r10, [r4, #0x33] */
/* @0x1e7784 strb r9, [r4, #0x34] */
/* @0x1e7788 str r8, [r4, #0x4] */
/* @0x1e778c str r7, [r4, #0x24] */
/* @0x1e7790 strbeq lr, [r4, #0x36] */
/* @0x1e7794 ldr r1, [r5, #0x44] */
/* @0x1e7798 ldr r2, [pc, #0xb0] */
/* @0x1e779c streq r3, [r4, #0x54] */
/* @0x1e77a0 movw r3, #0xa77 */
/* @0x1e77a4 str r1, [r4, #0x44] */
/* @0x1e77a8 add r2, pc, r2 */
/* @0x1e77ac lsl r1, r1, #2 */
/* @0x1e77b0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e77b4 ldr r3, [r4, #0x44] */
/* @0x1e77b8 cmp r3, #0 */
/* @0x1e77bc movgt r6, #0 */
/* @0x1e77c0 ble 0x1e7818 <_ZN7CSprite6AssignEPS_+0x130> */
/* @0x1e77c4 ldr r3, [r4, #0x48] */
/* @0x1e77c8 lsl r7, r6, #2 */
/* @0x1e77cc ldr r3, [r3, r6, lsl #2] */
/* @0x1e77d0 add r6, r6, #1 */
/* @0x1e77d4 cmp r3, #0 */
/* @0x1e77d8 mov r0, r3 */
/* @0x1e77dc beq 0x1e77ec <_ZN7CSprite6AssignEPS_+0x104> */
/* @0x1e77e0 ldr r3, [r3] */
/* @0x1e77e4 ldr r3, [r3, #0x4] */
/* @0x1e77e8 blx r3 */
/* @0x1e77ec mov r0, #24 */
/* @0x1e77f0 bl 0x27c524 <_Znwj> */
/* @0x1e77f4 ldr r3, [r5, #0x48] */
/* @0x1e77f8 ldr r1, [r3, r7] */
/* @0x1e77fc mov r8, r0 */
/* @0x1e7800 bl 0x165f98 <_ZN9CBitmap32C2EPS_> */
/* @0x1e7804 ldr r2, [r4, #0x44] */
/* @0x1e7808 ldr r3, [r4, #0x48] */
/* @0x1e780c cmp r2, r6 */
/* @0x1e7810 str r8, [r3, r7] */
/* @0x1e7814 bgt 0x1e77c4 <_ZN7CSprite6AssignEPS_+0xdc> */
/* @0x1e7818 mov r0, r4 */
/* @0x1e781c bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1e7820 ldr r3, [r5, #0x54] */
/* @0x1e7824 cmp r3, #0 */
/* @0x1e7828 beq 0x1e7838 <_ZN7CSprite6AssignEPS_+0x150> */
/* @0x1e782c ldrb r3, [r5, #0x36] */
/* @0x1e7830 cmp r3, #0 */
/* @0x1e7834 beq 0x1e7840 <_ZN7CSprite6AssignEPS_+0x158> */
/* @0x1e7838 mov r0, r4 */
/* @0x1e783c bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1e7840 mov r0, r4 */
/* @0x1e7844 add sp, sp, #12 */
/* @0x1e7848 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e784c b 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */
/* @0x1e7850 andseq r10, r6, r12, ror r12 */

/* ── FUNC 0x1e7854 · CSprite::LoadFromStream(CStream*) · size=752 · insn=188 */
/* @0x1e7854 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e7858 mov r6, r1 */
/* @0x1e785c mov r4, r0 */
/* @0x1e7860 bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1e7864 mov r0, r6 */
/* @0x1e7868 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e786c movw r3, #0x21e */
/* @0x1e7870 cmp r0, r3 */
/* @0x1e7874 mov r8, r0 */
/* @0x1e7878 beq 0x1e79d4 <_ZN7CSprite14LoadFromStreamEP7CStream+0x180> */
/* @0x1e787c cmp r0, #800 */
/* @0x1e7880 beq 0x1e789c <_ZN7CSprite14LoadFromStreamEP7CStream+0x48> */
/* @0x1e7884 movw r0, #0x21e */
/* @0x1e7888 cmp r8, r0 */
/* @0x1e788c cmpne r8, #800 */
/* @0x1e7890 movne r0, #0 */
/* @0x1e7894 moveq r0, #1 */
/* @0x1e7898 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e789c mov r0, r6 */
/* @0x1e78a0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e78a4 str r0, [r4, #0x24] */
/* @0x1e78a8 mov r0, r6 */
/* @0x1e78ac bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e78b0 str r0, [r4, #0x28] */
/* @0x1e78b4 mov r0, r6 */
/* @0x1e78b8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e78bc ldr r2, [pc, #0x270] */
/* @0x1e78c0 movw r3, #0xb18 */
/* @0x1e78c4 add r2, pc, r2 */
/* @0x1e78c8 lsl r1, r0, #2 */
/* @0x1e78cc str r0, [r4, #0x18] */
/* @0x1e78d0 add r0, r4, #72 */
/* @0x1e78d4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e78d8 ldr r3, [r4, #0x18] */
/* @0x1e78dc cmp r3, #0 */
/* @0x1e78e0 movgt r5, #0 */
/* @0x1e78e4 ble 0x1e7958 <_ZN7CSprite14LoadFromStreamEP7CStream+0x104> */
/* @0x1e78e8 ldr r3, [r4, #0x48] */
/* @0x1e78ec lsl r7, r5, #2 */
/* @0x1e78f0 ldr r3, [r3, r5, lsl #2] */
/* @0x1e78f4 add r5, r5, #1 */
/* @0x1e78f8 cmp r3, #0 */
/* @0x1e78fc mov r0, r3 */
/* @0x1e7900 beq 0x1e7910 <_ZN7CSprite14LoadFromStreamEP7CStream+0xbc> */
/* @0x1e7904 ldr r3, [r3] */
/* @0x1e7908 ldr r3, [r3, #0x4] */
/* @0x1e790c blx r3 */
/* @0x1e7910 mov r0, #24 */
/* @0x1e7914 bl 0x27c524 <_Znwj> */
/* @0x1e7918 mov r1, r6 */
/* @0x1e791c mov r9, r0 */
/* @0x1e7920 bl 0x165e2c <_ZN9CBitmap32C2EP7CStream> */
/* @0x1e7924 ldr r3, [r4, #0x48] */
/* @0x1e7928 str r9, [r3, r7] */
/* @0x1e792c ldr r3, [r4, #0x48] */
/* @0x1e7930 ldr r0, [r3, r7] */
/* @0x1e7934 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x1e7938 ldr r3, [r4, #0x48] */
/* @0x1e793c str r0, [r4, #0x1c] */
/* @0x1e7940 ldr r0, [r3, r7] */
/* @0x1e7944 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x1e7948 ldr r3, [r4, #0x18] */
/* @0x1e794c cmp r3, r5 */
/* @0x1e7950 str r0, [r4, #0x20] */
/* @0x1e7954 bgt 0x1e78e8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x94> */
/* @0x1e7958 mov r0, r6 */
/* @0x1e795c bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e7960 ldr r1, [r4, #0x18] */
/* @0x1e7964 cmp r1, #0 */
/* @0x1e7968 mov r5, r0 */
/* @0x1e796c strb r0, [r4, #0x35] */
/* @0x1e7970 ble 0x1e79c8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x174> */
/* @0x1e7974 cmp r0, #0 */
/* @0x1e7978 beq 0x1e7b00 <_ZN7CSprite14LoadFromStreamEP7CStream+0x2ac> */
/* @0x1e797c ldr r2, [pc, #0x1b4] */
/* @0x1e7980 movw r3, #0xb27 */
/* @0x1e7984 lsl r1, r1, #3 */
/* @0x1e7988 add r0, r4, #64 */
/* @0x1e798c add r2, pc, r2 */
/* @0x1e7990 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e7994 ldr r3, [r4, #0x18] */
/* @0x1e7998 cmp r3, #0 */
/* @0x1e799c str r3, [r4, #0x3c] */
/* @0x1e79a0 ble 0x1e79c8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x174> */
/* @0x1e79a4 mov r5, #0 */
/* @0x1e79a8 mov r1, r5 */
/* @0x1e79ac mov r0, r4 */
/* @0x1e79b0 mov r2, r6 */
/* @0x1e79b4 add r5, r5, #1 */
/* @0x1e79b8 bl 0x1e64cc <_ZN7CSprite18LoadMaskFromStreamEiP7CStream> */
/* @0x1e79bc ldr r3, [r4, #0x18] */
/* @0x1e79c0 cmp r3, r5 */
/* @0x1e79c4 bgt 0x1e79a8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x154> */
/* @0x1e79c8 mov r0, r4 */
/* @0x1e79cc bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv> */
/* @0x1e79d0 b 0x1e7884 <_ZN7CSprite14LoadFromStreamEP7CStream+0x30> */
/* @0x1e79d4 mov r0, r6 */
/* @0x1e79d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e79dc str r0, [r4, #0x1c] */
/* @0x1e79e0 mov r0, r6 */
/* @0x1e79e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e79e8 str r0, [r4, #0x20] */
/* @0x1e79ec mov r0, r6 */
/* @0x1e79f0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e79f4 str r0, [r4, #0x8] */
/* @0x1e79f8 mov r0, r6 */
/* @0x1e79fc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a00 str r0, [r4, #0x10] */
/* @0x1e7a04 mov r0, r6 */
/* @0x1e7a08 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a0c str r0, [r4, #0x14] */
/* @0x1e7a10 mov r0, r6 */
/* @0x1e7a14 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a18 str r0, [r4, #0xc] */
/* @0x1e7a1c mov r0, r6 */
/* @0x1e7a20 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e7a24 strb r0, [r4, #0x32] */
/* @0x1e7a28 mov r0, r6 */
/* @0x1e7a2c bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e7a30 strb r0, [r4, #0x33] */
/* @0x1e7a34 mov r0, r6 */
/* @0x1e7a38 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e7a3c strb r0, [r4, #0x34] */
/* @0x1e7a40 mov r0, r6 */
/* @0x1e7a44 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a48 str r0, [r4, #0x4] */
/* @0x1e7a4c mov r0, r6 */
/* @0x1e7a50 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1e7a54 strb r0, [r4, #0x30] */
/* @0x1e7a58 mov r0, r6 */
/* @0x1e7a5c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a60 str r0, [r4, #0x24] */
/* @0x1e7a64 mov r0, r6 */
/* @0x1e7a68 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a6c str r0, [r4, #0x28] */
/* @0x1e7a70 mov r0, r6 */
/* @0x1e7a74 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1e7a78 ldr r2, [pc, #0xbc] */
/* @0x1e7a7c movw r3, #0xb04 */
/* @0x1e7a80 add r2, pc, r2 */
/* @0x1e7a84 lsl r1, r0, #2 */
/* @0x1e7a88 str r0, [r4, #0x18] */
/* @0x1e7a8c add r0, r4, #72 */
/* @0x1e7a90 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e7a94 ldr r3, [r4, #0x18] */
/* @0x1e7a98 cmp r3, #0 */
/* @0x1e7a9c movgt r5, #0 */
/* @0x1e7aa0 ble 0x1e7af4 <_ZN7CSprite14LoadFromStreamEP7CStream+0x2a0> */
/* @0x1e7aa4 ldr r3, [r4, #0x48] */
/* @0x1e7aa8 lsl r7, r5, #2 */
/* @0x1e7aac ldr r3, [r3, r5, lsl #2] */
/* @0x1e7ab0 add r5, r5, #1 */
/* @0x1e7ab4 cmp r3, #0 */
/* @0x1e7ab8 mov r0, r3 */
/* @0x1e7abc beq 0x1e7acc <_ZN7CSprite14LoadFromStreamEP7CStream+0x278> */
/* @0x1e7ac0 ldr r3, [r3] */
/* @0x1e7ac4 ldr r3, [r3, #0x4] */
/* @0x1e7ac8 blx r3 */
/* @0x1e7acc mov r0, #24 */
/* @0x1e7ad0 bl 0x27c524 <_Znwj> */
/* @0x1e7ad4 mov r1, r6 */
/* @0x1e7ad8 mov r9, r0 */
/* @0x1e7adc bl 0x165e2c <_ZN9CBitmap32C2EP7CStream> */
/* @0x1e7ae0 ldr r2, [r4, #0x18] */
/* @0x1e7ae4 ldr r3, [r4, #0x48] */
/* @0x1e7ae8 cmp r2, r5 */
/* @0x1e7aec str r9, [r3, r7] */
/* @0x1e7af0 bgt 0x1e7aa4 <_ZN7CSprite14LoadFromStreamEP7CStream+0x250> */
/* @0x1e7af4 mov r0, r4 */
/* @0x1e7af8 bl 0x1e3bcc <_ZN7CSprite10CreateMaskEv> */
/* @0x1e7afc b 0x1e7884 <_ZN7CSprite14LoadFromStreamEP7CStream+0x30> */
/* @0x1e7b00 ldr r2, [pc, #0x38] */
/* @0x1e7b04 add r0, r4, #64 */
/* @0x1e7b08 mov r1, #8 */
/* @0x1e7b0c mov r3, #2864 */
/* @0x1e7b10 add r2, pc, r2 */
/* @0x1e7b14 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1e7b18 mov r3, #1 */
/* @0x1e7b1c mov r1, r5 */
/* @0x1e7b20 mov r2, r6 */
/* @0x1e7b24 mov r0, r4 */
/* @0x1e7b28 str r3, [r4, #0x3c] */
/* @0x1e7b2c bl 0x1e64cc <_ZN7CSprite18LoadMaskFromStreamEiP7CStream> */
/* @0x1e7b30 b 0x1e79c8 <_ZN7CSprite14LoadFromStreamEP7CStream+0x174> */
/* @0x1e7b34 andseq r10, r6, r0, ror #22 */
/* @0x1e7b38 mulseq r6, r8, r10 */
/* @0x1e7b3c andseq r10, r6, r4, lsr #19 */
/* @0x1e7b40 andseq r10, r6, r4, lsl r9 */

/* ── FUNC 0x1e7b44 · CSprite::SampleGradient(SWF_GradientFillStyleData*, int) · size=328 · insn=82 */
/* @0x1e7b44 cmp r1, #0 */
/* @0x1e7b48 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1e7b4c beq 0x1e7c78 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x134> */
/* @0x1e7b50 ldr r12, [r1, #0x4c] */
/* @0x1e7b54 cmp r12, #0 */
/* @0x1e7b58 ble 0x1e7c70 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x12c> */
/* @0x1e7b5c ldr r5, [r1, #0x50] */
/* @0x1e7b60 usat r2, #0x8, r2 */
/* @0x1e7b64 ldr r3, [r5] */
/* @0x1e7b68 cmp r2, r3 */
/* @0x1e7b6c blt 0x1e7bc0 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x7c> */
/* @0x1e7b70 cmp r12, #1 */
/* @0x1e7b74 beq 0x1e7bb4 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x70> */
/* @0x1e7b78 ldr r1, [r5, #0x8] */
/* @0x1e7b7c cmp r2, r1 */
/* @0x1e7b80 addle r4, r5, #8 */
/* @0x1e7b84 movle r0, #0 */
/* @0x1e7b88 ble 0x1e7bd0 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x8c> */
/* @0x1e7b8c add r3, r5, #16 */
/* @0x1e7b90 mov r0, #1 */
/* @0x1e7b94 b 0x1e7ba4 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x60> */
/* @0x1e7b98 ldr r1, [r3], #8 */
/* @0x1e7b9c cmp r2, r1 */
/* @0x1e7ba0 ble 0x1e7bc8 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x84> */
/* @0x1e7ba4 add r0, r0, #1 */
/* @0x1e7ba8 mov r4, r3 */
/* @0x1e7bac cmp r0, r12 */
/* @0x1e7bb0 bne 0x1e7b98 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x54> */
/* @0x1e7bb4 add r12, r5, r12, lsl #3 */
/* @0x1e7bb8 ldr r0, [r12, #-0x4] */
/* @0x1e7bbc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e7bc0 ldr r0, [r5, #0x4] */
/* @0x1e7bc4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e7bc8 sub r0, r0, #-536870911 */
/* @0x1e7bcc lsl r0, r0, #3 */
/* @0x1e7bd0 ldr r3, [r5, r0] */
/* @0x1e7bd4 add r5, r5, r0 */
/* @0x1e7bd8 cmp r1, r3 */
/* @0x1e7bdc beq 0x1e7c80 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x13c> */
/* @0x1e7be0 rsb r0, r3, r2 */
/* @0x1e7be4 rsb r1, r3, r1 */
/* @0x1e7be8 lsl r0, r0, #8 */
/* @0x1e7bec bl 0x318d10 <__divsi3> */
/* @0x1e7bf0 rsb r1, r0, #256 */
/* @0x1e7bf4 ldr r2, [r4, #0x4] */
/* @0x1e7bf8 ldr r3, [r5, #0x4] */
/* @0x1e7bfc ubfx r5, r2, #0x10, #0x8 */
/* @0x1e7c00 ubfx r4, r2, #0x8, #0x8 */
/* @0x1e7c04 ubfx r8, r3, #0x10, #0x8 */
/* @0x1e7c08 ubfx r6, r3, #0x8, #0x8 */
/* @0x1e7c0c mul r5, r5, r0 */
/* @0x1e7c10 uxtb r9, r2 */
/* @0x1e7c14 mul r8, r8, r1 */
/* @0x1e7c18 lsr r12, r2, #24 */
/* @0x1e7c1c mul r2, r4, r0 */
/* @0x1e7c20 lsr r7, r3, #24 */
/* @0x1e7c24 mul r6, r6, r1 */
/* @0x1e7c28 uxtb r4, r3 */
/* @0x1e7c2c mul r3, r9, r0 */
/* @0x1e7c30 lsr r5, r5, #8 */
/* @0x1e7c34 mul r0, r12, r0 */
/* @0x1e7c38 add r5, r5, r8, lsr #8 */
/* @0x1e7c3c mul r4, r4, r1 */
/* @0x1e7c40 lsr r2, r2, #8 */
/* @0x1e7c44 mul r1, r7, r1 */
/* @0x1e7c48 add r2, r2, r6, lsr #8 */
/* @0x1e7c4c lsl r5, r5, #16 */
/* @0x1e7c50 lsr r12, r0, #8 */
/* @0x1e7c54 lsr r3, r3, #8 */
/* @0x1e7c58 orr r2, r5, r2, lsl #8 */
/* @0x1e7c5c add r3, r3, r4, lsr #8 */
/* @0x1e7c60 orr r2, r2, r3 */
/* @0x1e7c64 add r0, r12, r1, lsr #8 */
/* @0x1e7c68 orr r0, r2, r0, lsl #24 */
/* @0x1e7c6c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e7c70 mov r0, #0 */
/* @0x1e7c74 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e7c78 mov r0, r1 */
/* @0x1e7c7c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1e7c80 mov r1, #256 */
/* @0x1e7c84 mov r0, #0 */
/* @0x1e7c88 b 0x1e7bf4 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0xb0> */

/* ── FUNC 0x1e7c8c · CSprite::SetupGradientTexture(SWF_GradientFillStyleData*) · size=400 · insn=100 */
/* @0x1e7c8c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1e7c90 vpush {d8, d9} */
/* @0x1e7c94 subs r6, r1, #0 */
/* @0x1e7c98 mov r7, r0 */
/* @0x1e7c9c beq 0x1e7cb4 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x28> */
/* @0x1e7ca0 ldr r4, [r6, #0x4] */
/* @0x1e7ca4 cmp r4, #0 */
/* @0x1e7ca8 beq 0x1e7cbc <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x30> */
/* @0x1e7cac cmp r4, #1 */
/* @0x1e7cb0 beq 0x1e7d50 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0xc4> */
/* @0x1e7cb4 vpop {d8, d9} */
/* @0x1e7cb8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1e7cbc ldr r1, [pc, #0x14c] */
/* @0x1e7cc0 mov r0, #1024 */
/* @0x1e7cc4 movw r2, #0xe7b */
/* @0x1e7cc8 mov r3, #1 */
/* @0x1e7ccc add r1, pc, r1 */
/* @0x1e7cd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e7cd4 sub r5, r0, #4 */
/* @0x1e7cd8 mov r9, r0 */
/* @0x1e7cdc mov r2, r4 */
/* @0x1e7ce0 mov r0, r7 */
/* @0x1e7ce4 mov r1, r6 */
/* @0x1e7ce8 add r4, r4, #1 */
/* @0x1e7cec bl 0x1e7b44 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai> */
/* @0x1e7cf0 cmp r4, #256 */
/* @0x1e7cf4 str r0, [r5, #0x4]! */
/* @0x1e7cf8 bne 0x1e7cdc <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x50> */
/* @0x1e7cfc mov r0, r4 */
/* @0x1e7d00 mov r3, #1024 */
/* @0x1e7d04 mov r1, #1 */
/* @0x1e7d08 mov r2, r9 */
/* @0x1e7d0c bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0x1e7d10 str r0, [r6, #0x54] */
/* @0x1e7d14 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1e7d18 cmp r0, #0 */
/* @0x1e7d1c beq 0x1e7d40 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0xb4> */
/* @0x1e7d20 ldr r3, [pc, #0xec] */
/* @0x1e7d24 ldr r2, [r6, #0x54] */
/* @0x1e7d28 ldr r3, [pc, r3] */
/* @0x1e7d2c ldr r3, [r3, #0x4] */
/* @0x1e7d30 ldr r3, [r3, r2, lsl #2] */
/* @0x1e7d34 cmp r3, #0 */
/* @0x1e7d38 ldrne r3, [r3] */
/* @0x1e7d3c strne r3, [r6, #0x58] */
/* @0x1e7d40 vpop {d8, d9} */
/* @0x1e7d44 mov r0, r9 */
/* @0x1e7d48 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1e7d4c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1e7d50 ldr r1, [pc, #0xc0] */
/* @0x1e7d54 mov r3, r4 */
/* @0x1e7d58 mov r0, #16384 */
/* @0x1e7d5c movw r2, #0xe86 */
/* @0x1e7d60 add r1, pc, r1 */
/* @0x1e7d64 vmov.f32 s18, #3.100000e+01 */
/* @0x1e7d68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1e7d6c mvn r8, #30 */
/* @0x1e7d70 vldr s17, [pc, #148] */
/* @0x1e7d74 sub r10, r0, #4 */
/* @0x1e7d78 mov r9, r0 */
/* @0x1e7d7c vmov s15, r8 */
/* @0x1e7d80 mov r5, r10 */
/* @0x1e7d84 mvn r4, #30 */
/* @0x1e7d88 vcvt.f32.s32 s16, s15 */
/* @0x1e7d8c vmul.f32 s16, s16, s16 */
/* @0x1e7d90 vmov s14, r4 */
/* @0x1e7d94 add r4, r4, #1 */
/* @0x1e7d98 vcvt.f32.s32 s15, s14 */
/* @0x1e7d9c vmov.f32 s14, s16 */
/* @0x1e7da0 vmla.f32 s14, s15, s15 */
/* @0x1e7da4 vsqrt.f32 s15, s14 */
/* @0x1e7da8 vcmp.f32 s15, s15 */
/* @0x1e7dac vmrs APSR_nzcv, fpscr */
/* @0x1e7db0 bne 0x1e7dfc <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x170> */
/* @0x1e7db4 vdiv.f32 s15, s15, s18 */
/* @0x1e7db8 mov r0, r7 */
/* @0x1e7dbc mov r1, r6 */
/* @0x1e7dc0 vmul.f32 s15, s15, s17 */
/* @0x1e7dc4 vcvt.s32.f32 s15, s15 */
/* @0x1e7dc8 vmov r2, s15 */
/* @0x1e7dcc bl 0x1e7b44 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai> */
/* @0x1e7dd0 cmp r4, #33 */
/* @0x1e7dd4 str r0, [r5, #0x4]! */
/* @0x1e7dd8 bne 0x1e7d90 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x104> */
/* @0x1e7ddc add r8, r8, #1 */
/* @0x1e7de0 add r10, r10, #256 */
/* @0x1e7de4 cmp r8, #33 */
/* @0x1e7de8 bne 0x1e7d7c <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0xf0> */
/* @0x1e7dec mov r1, #64 */
/* @0x1e7df0 mov r3, #16384 */
/* @0x1e7df4 mov r0, r1 */
/* @0x1e7df8 b 0x1e7d08 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x7c> */
/* @0x1e7dfc vmov r0, s14 */
/* @0x1e7e00 bl 0xb6700 <sqrtf@plt> */
/* @0x1e7e04 vmov s15, r0 */
/* @0x1e7e08 b 0x1e7db4 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x128> */
/* @0x1e7e0c cmnmi pc, #0 */
/* @0x1e7e10 andseq r10, r6, r8, asr r7 */
/* @0x1e7e14 .word 0x00205bf4 */
/* @0x1e7e18 andseq r10, r6, r4, asr #13 */
