/* libyoyo.so 覆盖卡组 0289
 * 函数 0x2e6a12..0x2e738c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e6a12 · FT_Stream_GetUShortLE · size=32 · insn=14 */
/* @0x2e6a12 mov r2, r0 */
/* @0x2e6a14 ldr r3, [r0, #0x20] */
/* @0x2e6a16 ldr r1, [r2, #0x24] */
/* @0x2e6a18 adds r0, r3, #0x1 */
/* @0x2e6a1a cmp r1, r0 */
/* @0x2e6a1c bls 0x2e6a2c <FT_Stream_GetUShortLE+0x1a> */
/* @0x2e6a1e ldrb r0, [r3, #0x1] */
/* @0x2e6a20 adds r3, #0x2 */
/* @0x2e6a22 ldrb r1, [r3, #-2] */
/* @0x2e6a26 orr.w r0, r1, r0, lsl #8 */
/* @0x2e6a2a b 0x2e6a2e <FT_Stream_GetUShortLE+0x1c> */
/* @0x2e6a2c movs r0, #0x0 */
/* @0x2e6a2e str r3, [r2, #0x20] */
/* @0x2e6a30 bx lr */

/* ── FUNC 0x2e6a32 · FT_Stream_GetUOffset · size=40 · insn=19 */
/* @0x2e6a32 mov r2, r0 */
/* @0x2e6a34 ldr r3, [r0, #0x20] */
/* @0x2e6a36 ldr r1, [r2, #0x24] */
/* @0x2e6a38 adds r0, r3, #0x2 */
/* @0x2e6a3a cmp r1, r0 */
/* @0x2e6a3c bls 0x2e6a54 <FT_Stream_GetUOffset+0x22> */
/* @0x2e6a3e ldrb r0, [r3, #0x1] */
/* @0x2e6a40 adds r3, #0x3 */
/* @0x2e6a42 ldrb r1, [r3, #-3] */
/* @0x2e6a46 lsls r0, r0, #0x8 */
/* @0x2e6a48 orr.w r0, r0, r1, lsl #16 */
/* @0x2e6a4a .word 0xf8134001 */
/* @0x2e6a4c ldrb r1, [r3, #-1] */
/* @0x2e6a4e movwmi r1, #0x8c01 */
/* @0x2e6a50 orrs r0, r1 */
/* @0x2e6a52 b 0x2e6a56 <FT_Stream_GetUOffset+0x24> */
/* @0x2e6a54 movs r0, #0x0 */
/* @0x2e6a56 str r3, [r2, #0x20] */
/* @0x2e6a58 bx lr */

/* ── FUNC 0x2e6a5a · FT_Stream_GetULong · size=48 · insn=21 */
/* @0x2e6a5a mov r2, r0 */
/* @0x2e6a5c ldr r3, [r0, #0x20] */
/* @0x2e6a5e ldr r1, [r2, #0x24] */
/* @0x2e6a60 adds r0, r3, #0x3 */
/* @0x2e6a62 cmp r1, r0 */
/* @0x2e6a64 bls 0x2e6a84 <FT_Stream_GetULong+0x2a> */
/* @0x2e6a66 ldrb r0, [r3, #0x1] */
/* @0x2e6a68 adds r3, #0x4 */
/* @0x2e6a6a ldrb r1, [r3, #-4] */
/* @0x2e6a6e lsls r0, r0, #0x10 */
/* @0x2e6a70 orr.w r0, r0, r1, lsl #24 */
/* @0x2e6a72 .word 0xf8136001 */
/* @0x2e6a74 ldrb r1, [r3, #-1] */
/* @0x2e6a76 movwmi r1, #0x8c01 */
/* @0x2e6a78 orrs r0, r1 */
/* @0x2e6a7a ldrb r1, [r3, #-2] */
/* @0x2e6a7e orr.w r0, r0, r1, lsl #8 */
/* @0x2e6a82 b 0x2e6a86 <FT_Stream_GetULong+0x2c> */
/* @0x2e6a84 movs r0, #0x0 */
/* @0x2e6a86 str r3, [r2, #0x20] */
/* @0x2e6a88 bx lr */

/* ── FUNC 0x2e6a8a · FT_Stream_GetULongLE · size=48 · insn=21 */
/* @0x2e6a8a mov r2, r0 */
/* @0x2e6a8c ldr r3, [r0, #0x20] */
/* @0x2e6a8e ldr r1, [r2, #0x24] */
/* @0x2e6a90 adds r0, r3, #0x3 */
/* @0x2e6a92 cmp r1, r0 */
/* @0x2e6a94 bls 0x2e6ab4 <FT_Stream_GetULongLE+0x2a> */
/* @0x2e6a96 ldrb r0, [r3, #0x2] */
/* @0x2e6a98 adds r3, #0x4 */
/* @0x2e6a9a ldrb r1, [r3, #-1] */
/* @0x2e6a9e lsls r0, r0, #0x10 */
/* @0x2e6aa0 orr.w r0, r0, r1, lsl #24 */
/* @0x2e6aa2 .word 0xf8136001 */
/* @0x2e6aa4 ldrb r1, [r3, #-4] */
/* @0x2e6aa6 movwmi r1, #0x8c04 */
/* @0x2e6aa8 orrs r0, r1 */
/* @0x2e6aaa ldrb r1, [r3, #-3] */
/* @0x2e6aae orr.w r0, r0, r1, lsl #8 */
/* @0x2e6ab2 b 0x2e6ab6 <FT_Stream_GetULongLE+0x2c> */
/* @0x2e6ab4 movs r0, #0x0 */
/* @0x2e6ab6 str r3, [r2, #0x20] */
/* @0x2e6ab8 bx lr */

/* ── FUNC 0x2e6aba · FT_Stream_ReadChar · size=74 · insn=34 */
/* @0x2e6aba push {r0, r1, r4, r5, r6, lr} */
/* @0x2e6abc movs r3, #0x0 */
/* @0x2e6abe str r3, [r1] */
/* @0x2e6ac0 mov r4, r0 */
/* @0x2e6ac2 ldr r6, [r0, #0x14] */
/* @0x2e6ac4 mov r5, r1 */
/* @0x2e6ac6 strb.w r3, [sp, #0x7] */
/* @0x2e6aca cbz r6, 0x2e6adc <FT_Stream_ReadChar+0x22> */
/* @0x2e6acc ldr r1, [r0, #0x8] */
/* @0x2e6ace add.w r2, sp, #0x7 */
/* @0x2e6ad2 movs r3, #0x1 */
/* @0x2e6ad4 blx r6 */
/* @0x2e6ad6 cmp r0, #0x1 */
/* @0x2e6ad8 bne 0x2e6af8 <FT_Stream_ReadChar+0x3e> */
/* @0x2e6ada b 0x2e6aec <FT_Stream_ReadChar+0x32> */
/* @0x2e6adc ldr r3, [r0, #0x8] */
/* @0x2e6ade ldr r2, [r0, #0x4] */
/* @0x2e6ae0 cmp r3, r2 */
/* @0x2e6ae2 bhs 0x2e6af8 <FT_Stream_ReadChar+0x3e> */
/* @0x2e6ae4 ldr r2, [r0] */
/* @0x2e6ae6 ldrb r3, [r2, r3] */
/* @0x2e6ae8 strb.w r3, [sp, #0x7] */
/* @0x2e6aea stmvs r3!, {r0, r1, r2, r12, sp} */
/* @0x2e6aec ldr r3, [r4, #0x8] */
/* @0x2e6aee ldrb.w r0, [sp, #0x7] */
/* @0x2e6af2 adds r3, #0x1 */
/* @0x2e6af4 str r3, [r4, #0x8] */
/* @0x2e6af6 b 0x2e6afe <FT_Stream_ReadChar+0x44> */
/* @0x2e6af8 movs r0, #0x0 */
/* @0x2e6afa movs r3, #0x55 */
/* @0x2e6afc str r3, [r5] */
/* @0x2e6afe sxtb r0, r0 */
/* @0x2e6b00 add sp, #0x8 */
/* @0x2e6b02 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e6b04 · FT_Stream_ReadUShort · size=76 · insn=37 */
/* @0x2e6b04 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e6b06 movs r3, #0x0 */
/* @0x2e6b08 str r3, [r1] */
/* @0x2e6b0a mov r5, r1 */
/* @0x2e6b0c ldr r3, [r0, #0x8] */
/* @0x2e6b0e mov r4, r0 */
/* @0x2e6b10 ldr r2, [r0, #0x4] */
/* @0x2e6b12 adds r1, r3, #0x1 */
/* @0x2e6b14 cmp r1, r2 */
/* @0x2e6b16 bhs 0x2e6b46 <FT_Stream_ReadUShort+0x42> */
/* @0x2e6b18 ldr r7, [r0, #0x14] */
/* @0x2e6b1a cbz r7, 0x2e6b2e <FT_Stream_ReadUShort+0x2a> */
/* @0x2e6b1c add r6, sp, #0x4 */
/* @0x2e6b1e mov r1, r3 */
/* @0x2e6b20 movs r3, #0x2 */
/* @0x2e6b22 mov r2, r6 */
/* @0x2e6b24 blx r7 */
/* @0x2e6b26 cmp r0, #0x2 */
/* @0x2e6b28 bne 0x2e6b46 <FT_Stream_ReadUShort+0x42> */
/* @0x2e6b2a mov r3, r6 */
/* @0x2e6b2c b 0x2e6b34 <FT_Stream_ReadUShort+0x30> */
/* @0x2e6b2e ldr r2, [r0] */
/* @0x2e6b30 adds r3, r2, r3 */
/* @0x2e6b32 beq 0x2e6b3c <FT_Stream_ReadUShort+0x38> */
/* @0x2e6b34 ldrb r0, [r3] */
/* @0x2e6b36 ldrb r3, [r3, #0x1] */
/* @0x2e6b38 orr.w r3, r3, r0, lsl #8 */
/* @0x2e6b3c ldr r2, [r4, #0x8] */
/* @0x2e6b3e mov r0, r3 */
/* @0x2e6b40 adds r2, #0x2 */
/* @0x2e6b42 str r2, [r4, #0x8] */
/* @0x2e6b44 b 0x2e6b4c <FT_Stream_ReadUShort+0x48> */
/* @0x2e6b46 movs r0, #0x0 */
/* @0x2e6b48 movs r3, #0x55 */
/* @0x2e6b4a str r3, [r5] */
/* @0x2e6b4c add sp, #0xc */
/* @0x2e6b4e pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6b50 · FT_Raccess_Get_HeaderInfo · size=468 · insn=207 */
/* @0x2e6b50 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e6b54 sub sp, #0x3c */
/* @0x2e6b56 ldr r6, [pc, #0x1c8] */
/* @0x2e6b58 mov r0, r1 */
/* @0x2e6b5a str r3, [sp, #0x8] */
/* @0x2e6b5c mov r4, r1 */
/* @0x2e6b5e add r6, pc */
/* @0x2e6b60 ldr r6, [r6] */
/* @0x2e6b62 mov r1, r2 */
/* @0x2e6b64 mov r5, r2 */
/* @0x2e6b66 ldr r7, [sp, #0x60] */
/* @0x2e6b68 ldr r3, [r6] */
/* @0x2e6b6a str r3, [sp, #0x34] */
/* @0x2e6b6c bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e6b70 str r6, [sp, #0xc] */
/* @0x2e6b72 str r0, [sp, #0x10] */
/* @0x2e6b74 cmp r0, #0x0 */
/* @0x2e6b76 bne.w 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6b78 cdpge p0, #0x0, c8, c5, c9, #0x6 */
/* @0x2e6b7a add r6, sp, #0x14 */
/* @0x2e6b7c mov r0, r4 */
/* @0x2e6b7e movs r2, #0x10 */
/* @0x2e6b80 mov r1, r6 */
/* @0x2e6b82 bl 0x2e698e <FT_Stream_Read> */
/* @0x2e6b84 andls pc, r4, r4, lsl #30 */
/* @0x2e6b86 str r0, [sp, #0x10] */
/* @0x2e6b88 cmp r0, #0x0 */
/* @0x2e6b8a bne.w 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6b8c .word 0xf89d80bf */
/* @0x2e6b8e ldrb.w r1, [sp, #0x14] */
/* @0x2e6b90 .word 0x06081014 */
/* @0x2e6b92 lsls r0, r1, #0x18 */
/* @0x2e6b94 bpl 0x2e6b9a <FT_Raccess_Get_HeaderInfo+0x4a> */
/* @0x2e6b96 movs r0, #0x2 */
/* @0x2e6b98 b 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6b9a ldrb.w r12, [sp, #0x18] */
/* @0x2e6b9c .word 0xf01cc018 */
/* @0x2e6b9e tst.w r12, #0x80 */
/* @0x2e6ba0 mvnsle r0, r0, lsl #31 */
/* @0x2e6ba2 bne 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6ba4 ldrb.w r0, [sp, #0x1c] */
/* @0x2e6ba8 lsls r2, r0, #0x18 */
/* @0x2e6baa bmi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6bac ldrb.w r2, [sp, #0x20] */
/* @0x2e6bb0 lsls r3, r2, #0x18 */
/* @0x2e6bb2 bmi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6bb4 ldrb.w r3, [sp, #0x15] */
/* @0x2e6bb8 ldrb.w r8, [sp, #0x17] */
/* @0x2e6bbc ldrb.w r11, [sp, #0x1d] */
/* @0x2e6bc0 lsls r3, r3, #0x10 */
/* @0x2e6bc2 ldrb.w r10, [sp, #0x1f] */
/* @0x2e6bc4 b 0x13cec48 <b2_toiTime+0xc757a4> */
/* @0x2e6bc6 orr.w r1, r3, r1, lsl #24 */
/* @0x2e6bc8 .word 0xf89d6101 */
/* @0x2e6bca ldrb.w r3, [sp, #0x16] */
/* @0x2e6bcc b 0x1332c2c <b2_toiTime+0xbd9788> */
/* @0x2e6bce orr.w r1, r1, r8 */
/* @0x2e6bd0 .word 0xf89d0108 */
/* @0x2e6bd2 ldrb.w r8, [sp, #0x1b] */
/* @0x2e6bd4 .word 0xf89d801b */
/* @0x2e6bd6 ldrb.w r9, [sp, #0x23] */
/* @0x2e6bd8 b 0x134ac6c <b2_toiTime+0xbf17c8> */
/* @0x2e6bda orr.w r3, r1, r3, lsl #8 */
/* @0x2e6bdc .word 0xf89d2303 */
/* @0x2e6bde ldrb.w r1, [sp, #0x19] */
/* @0x2e6be0 eorsvs r1, r11, r9, lsl r0 */
/* @0x2e6be2 str r3, [r7] */
/* @0x2e6be4 lsls r1, r1, #0x10 */
/* @0x2e6be6 orr.w r1, r1, r12, lsl #24 */
/* @0x2e6be8 .word 0xf89d610c */
/* @0x2e6bea ldrb.w r12, [sp, #0x1a] */
/* @0x2e6bec b 0x1356c5c <b2_toiTime+0xbfd7b8> */
/* @0x2e6bee orr.w r1, r1, r8 */
/* @0x2e6bf0 .word 0xf89d0108 */
/* @0x2e6bf2 ldrb.w r8, [sp, #0x1e] */
/* @0x2e6bf4 b 0x1746c74 <b2_toiTime+0xfed7d0> */
/* @0x2e6bf6 orrs.w r1, r1, r12, lsl #8 */
/* @0x2e6bf8 .word 0xf8cd210c */
/* @0x2e6bfa str.w r8, [sp] */
/* @0x2e6bfc .word 0xf89d8000 */
/* @0x2e6bfe ldrb.w r8, [sp, #0x21] */
/* @0x2e6c00 .word 0xf8cd8021 */
/* @0x2e6c02 str.w r8, [sp, #0x4] */
/* @0x2e6c04 .word 0xf89d8004 */
/* @0x2e6c06 ldrb.w r8, [sp, #0x22] */
/* @0x2e6c08 sbcle r8, r4, r2, lsr #32 */
/* @0x2e6c0a beq 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c0c ldr.w r12, [sp] */
/* @0x2e6c10 lsl.w r11, r11, #0x10 */
/* @0x2e6c14 orr.w r11, r11, r0, lsl #24 */
/* @0x2e6c18 cmp r3, r1 */
/* @0x2e6c1a orr.w r11, r11, r10 */
/* @0x2e6c1c b 0x15a984c <b2_toiTime+0xe503a8> */
/* @0x2e6c1e orr.w r11, r11, r12, lsl #8 */
/* @0x2e6c20 .word 0xf8dd2b0c */
/* @0x2e6c22 ldr.w r12, [sp, #0x4] */
/* @0x2e6c24 b 0x16d6c3c <b2_toiTime+0xf7d798> */
/* @0x2e6c26 lsl.w r0, r12, #0x10 */
/* @0x2e6c28 b 0x12f6c60 <b2_toiTime+0xb9d7bc> */
/* @0x2e6c2a orr.w r2, r0, r2, lsl #24 */
/* @0x2e6c2c b 0x137f43c <b2_toiTime+0xc25f98> */
/* @0x2e6c2e orr.w r9, r2, r9 */
/* @0x2e6c30 b 0x152905c <b2_toiTime+0xdcfbb8> */
/* @0x2e6c32 orr.w r8, r9, r8, lsl #8 */
/* @0x2e6c34 ble 0x3b0c5c <error_g0017+0x9900> */
/* @0x2e6c36 bge 0x2e6c40 <FT_Raccess_Get_HeaderInfo+0xf0> */
/* @0x2e6c38 rsb r2, r11, r1 */
/* @0x2e6c3c cmp r3, r2 */
/* @0x2e6c3e b 0x2e6c46 <FT_Raccess_Get_HeaderInfo+0xf6> */
/* @0x2e6c40 rsb r2, r8, r3 */
/* @0x2e6c44 cmp r1, r2 */
/* @0x2e6c46 bgt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c48 mvn r2, #0x80000000 */
/* @0x2e6c4c rsb r2, r11, r2 */
/* @0x2e6c50 cmp r2, r3 */
/* @0x2e6c52 blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c54 mvn r2, #0x80000000 */
/* @0x2e6c58 rsb r2, r8, r2 */
/* @0x2e6c5c cmp r2, r1 */
/* @0x2e6c5e blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c60 add.w r0, r3, r11 */
/* @0x2e6c64 mvn r2, #0x80000000 */
/* @0x2e6c68 subs r2, r2, r0 */
/* @0x2e6c6a cmp r2, r5 */
/* @0x2e6c6c blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c6e add.w r0, r1, r8 */
/* @0x2e6c70 .word 0xf06f0008 */
/* @0x2e6c72 mvn r2, #0x80000000 */
/* @0x2e6c74 bne 0x77747c <b2_toiTime+0x1dfd8> */
/* @0x2e6c76 subs r2, r2, r0 */
/* @0x2e6c78 cmp r2, r5 */
/* @0x2e6c7a blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c7c add r3, r5 */
/* @0x2e6c7e ldr r2, [r4, #0x4] */
/* @0x2e6c80 add r11, r3 */
/* @0x2e6c82 cmp r11, r2 */
/* @0x2e6c84 bhi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c86 add r5, r1 */
/* @0x2e6c88 add r8, r5 */
/* @0x2e6c8a cmp r8, r2 */
/* @0x2e6c8c bhi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6c8e str r3, [r7] */
/* @0x2e6c90 mov r0, r4 */
/* @0x2e6c92 mov r1, r5 */
/* @0x2e6c94 bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e6c98 str r0, [sp, #0x10] */
/* @0x2e6c9a cmp r0, #0x0 */
/* @0x2e6c9c bne 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6c9e add r7, sp, #0x24 */
/* @0x2e6ca0 ldrb.w r3, [sp, #0x23] */
/* @0x2e6ca4 mov r0, r4 */
/* @0x2e6ca6 movs r2, #0x10 */
/* @0x2e6ca8 mov r1, r7 */
/* @0x2e6caa adds r3, #0x1 */
/* @0x2e6cac strb.w r3, [sp, #0x33] */
/* @0x2e6cb0 bl 0x2e698e <FT_Stream_Read> */
/* @0x2e6cb4 str r0, [sp, #0x10] */
/* @0x2e6cb6 cbnz r0, 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6cb8 movs r3, #0x1 */
/* @0x2e6cba mov r2, r3 */
/* @0x2e6cbc ldrb r1, [r7, r0] */
/* @0x2e6cbe ldrb.w r12, [r6, r0] */
/* @0x2e6cc0 andlo r12, r1, r0 */
/* @0x2e6cc2 adds r0, #0x1 */
/* @0x2e6cc4 cmp r1, #0x0 */
/* @0x2e6cc6 it ne */
/* @0x2e6cc8 movne r2, #0x0 */
/* @0x2e6cca cmp r12, r1 */
/* @0x2e6ccc it ne */
/* @0x2e6cce movne r3, #0x0 */
/* @0x2e6cd0 cmp r0, #0x10 */
/* @0x2e6cd2 bne 0x2e6cbc <FT_Raccess_Get_HeaderInfo+0x16c> */
/* @0x2e6cd4 cbnz r2, 0x2e6cdc <FT_Raccess_Get_HeaderInfo+0x18c> */
/* @0x2e6cd6 cmp r3, #0x0 */
/* @0x2e6cd8 beq.w 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6cdc movs r1, #0x8 */
/* @0x2e6cde mov r0, r4 */
/* @0x2e6ce0 bl 0x2e6930 <FT_Stream_Skip> */
/* @0x2e6ce4 add r1, sp, #0x38 */
/* @0x2e6ce6 str r0, [r1, #-40]! */
/* @0x2e6ce8 strtmi r0, [r0], -r8, lsr #26 */
/* @0x2e6cea mov r0, r4 */
/* @0x2e6cec bl 0x2e6b04 <FT_Stream_ReadUShort> */
/* @0x2e6cf0 sxth r1, r0 */
/* @0x2e6cf2 ldr r0, [sp, #0x10] */
/* @0x2e6cf4 cbnz r0, 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6cf6 cmp r1, #0x0 */
/* @0x2e6cf8 blt.w 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46> */
/* @0x2e6cfc add r5, r1 */
/* @0x2e6cfe mov r0, r4 */
/* @0x2e6d00 mov r1, r5 */
/* @0x2e6d02 bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e6d04 stmdblt r8, {r4, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e6d06 cbnz r0, 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc> */
/* @0x2e6d08 ldr r3, [sp, #0x8] */
/* @0x2e6d0a str r5, [r3] */
/* @0x2e6d0c ldr r1, [sp, #0xc] */
/* @0x2e6d0e ldr r2, [sp, #0x34] */
/* @0x2e6d10 ldr r3, [r1] */
/* @0x2e6d12 cmp r2, r3 */
/* @0x2e6d14 beq 0x2e6d1a <FT_Raccess_Get_HeaderInfo+0x1ca> */
/* @0x2e6d16 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2e6d18 andlt lr, pc, lr, asr r12 */
/* @0x2e6d1a add sp, #0x3c */
/* @0x2e6d1c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e6d20 ldr r6, [r6, #0x5c] */
/* @0x2e6d22 movs r0, r2 */

/* ── FUNC 0x2e6d24 · FT_Stream_ReadUShortLE · size=76 · insn=37 */
/* @0x2e6d24 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e6d26 movs r3, #0x0 */
/* @0x2e6d28 str r3, [r1] */
/* @0x2e6d2a mov r5, r1 */
/* @0x2e6d2c ldr r3, [r0, #0x8] */
/* @0x2e6d2e mov r4, r0 */
/* @0x2e6d30 ldr r2, [r0, #0x4] */
/* @0x2e6d32 adds r1, r3, #0x1 */
/* @0x2e6d34 cmp r1, r2 */
/* @0x2e6d36 bhs 0x2e6d66 <FT_Stream_ReadUShortLE+0x42> */
/* @0x2e6d38 ldr r7, [r0, #0x14] */
/* @0x2e6d3a cbz r7, 0x2e6d4e <FT_Stream_ReadUShortLE+0x2a> */
/* @0x2e6d3c add r6, sp, #0x4 */
/* @0x2e6d3e mov r1, r3 */
/* @0x2e6d40 movs r3, #0x2 */
/* @0x2e6d42 mov r2, r6 */
/* @0x2e6d44 blx r7 */
/* @0x2e6d46 cmp r0, #0x2 */
/* @0x2e6d48 bne 0x2e6d66 <FT_Stream_ReadUShortLE+0x42> */
/* @0x2e6d4a mov r3, r6 */
/* @0x2e6d4c b 0x2e6d54 <FT_Stream_ReadUShortLE+0x30> */
/* @0x2e6d4e ldr r2, [r0] */
/* @0x2e6d50 adds r3, r2, r3 */
/* @0x2e6d52 beq 0x2e6d5c <FT_Stream_ReadUShortLE+0x38> */
/* @0x2e6d54 ldrb r0, [r3, #0x1] */
/* @0x2e6d56 ldrb r3, [r3] */
/* @0x2e6d58 orr.w r3, r3, r0, lsl #8 */
/* @0x2e6d5c ldr r2, [r4, #0x8] */
/* @0x2e6d5e mov r0, r3 */
/* @0x2e6d60 adds r2, #0x2 */
/* @0x2e6d62 str r2, [r4, #0x8] */
/* @0x2e6d64 b 0x2e6d6c <FT_Stream_ReadUShortLE+0x48> */
/* @0x2e6d66 movs r0, #0x0 */
/* @0x2e6d68 movs r3, #0x55 */
/* @0x2e6d6a str r3, [r5] */
/* @0x2e6d6c add sp, #0xc */
/* @0x2e6d6e pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6d70 · FT_Stream_ReadUOffset · size=84 · insn=41 */
/* @0x2e6d70 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e6d72 movs r3, #0x0 */
/* @0x2e6d74 str r3, [r1] */
/* @0x2e6d76 mov r5, r1 */
/* @0x2e6d78 ldr r3, [r0, #0x8] */
/* @0x2e6d7a mov r4, r0 */
/* @0x2e6d7c ldr r2, [r0, #0x4] */
/* @0x2e6d7e adds r1, r3, #0x2 */
/* @0x2e6d80 cmp r1, r2 */
/* @0x2e6d82 bhs 0x2e6dba <FT_Stream_ReadUOffset+0x4a> */
/* @0x2e6d84 ldr r7, [r0, #0x14] */
/* @0x2e6d86 cbz r7, 0x2e6d9a <FT_Stream_ReadUOffset+0x2a> */
/* @0x2e6d88 add r6, sp, #0x4 */
/* @0x2e6d8a mov r1, r3 */
/* @0x2e6d8c movs r3, #0x3 */
/* @0x2e6d8e mov r2, r6 */
/* @0x2e6d90 blx r7 */
/* @0x2e6d92 cmp r0, #0x3 */
/* @0x2e6d94 bne 0x2e6dba <FT_Stream_ReadUOffset+0x4a> */
/* @0x2e6d96 mov r2, r6 */
/* @0x2e6d98 b 0x2e6da0 <FT_Stream_ReadUOffset+0x30> */
/* @0x2e6d9a ldr r2, [r0] */
/* @0x2e6d9c adds r2, r2, r3 */
/* @0x2e6d9e beq 0x2e6db0 <FT_Stream_ReadUOffset+0x40> */
/* @0x2e6da0 ldrb r0, [r2, #0x1] */
/* @0x2e6da2 ldrb r3, [r2] */
/* @0x2e6da4 lsls r0, r0, #0x8 */
/* @0x2e6da6 orr.w r0, r0, r3, lsl #16 */
/* @0x2e6da8 ldmvc r3, {r0, r1, lr} */
/* @0x2e6daa ldrb r3, [r2, #0x2] */
/* @0x2e6dac orr.w r2, r0, r3 */
/* @0x2e6db0 ldr r3, [r4, #0x8] */
/* @0x2e6db2 mov r0, r2 */
/* @0x2e6db4 adds r3, #0x3 */
/* @0x2e6db6 str r3, [r4, #0x8] */
/* @0x2e6db8 b 0x2e6dc0 <FT_Stream_ReadUOffset+0x50> */
/* @0x2e6dba movs r0, #0x0 */
/* @0x2e6dbc movs r3, #0x55 */
/* @0x2e6dbe str r3, [r5] */
/* @0x2e6dc0 add sp, #0xc */
/* @0x2e6dc2 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6dc4 · FT_Stream_ReadULong · size=88 · insn=43 */
/* @0x2e6dc4 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e6dc6 movs r3, #0x0 */
/* @0x2e6dc8 str r3, [r1] */
/* @0x2e6dca mov r5, r1 */
/* @0x2e6dcc ldr r3, [r0, #0x8] */
/* @0x2e6dce mov r4, r0 */
/* @0x2e6dd0 ldr r2, [r0, #0x4] */
/* @0x2e6dd2 adds r1, r3, #0x3 */
/* @0x2e6dd4 cmp r1, r2 */
/* @0x2e6dd6 bhs 0x2e6e12 <FT_Stream_ReadULong+0x4e> */
/* @0x2e6dd8 ldr r7, [r0, #0x14] */
/* @0x2e6dda cbz r7, 0x2e6dee <FT_Stream_ReadULong+0x2a> */
/* @0x2e6ddc add r6, sp, #0x4 */
/* @0x2e6dde mov r1, r3 */
/* @0x2e6de0 movs r3, #0x4 */
/* @0x2e6de2 mov r2, r6 */
/* @0x2e6de4 blx r7 */
/* @0x2e6de6 cmp r0, #0x4 */
/* @0x2e6de8 bne 0x2e6e12 <FT_Stream_ReadULong+0x4e> */
/* @0x2e6dea mov r2, r6 */
/* @0x2e6dec b 0x2e6df4 <FT_Stream_ReadULong+0x30> */
/* @0x2e6dee ldr r2, [r0] */
/* @0x2e6df0 adds r2, r2, r3 */
/* @0x2e6df2 beq 0x2e6e08 <FT_Stream_ReadULong+0x44> */
/* @0x2e6df4 ldrb r0, [r2, #0x1] */
/* @0x2e6df6 ldrb r3, [r2] */
/* @0x2e6df8 lsls r0, r0, #0x10 */
/* @0x2e6dfa orr.w r0, r0, r3, lsl #24 */
/* @0x2e6dfc ldmvc r3, {r0, r1, sp, lr} ^ */
/* @0x2e6dfe ldrb r3, [r2, #0x3] */
/* @0x2e6e00 ldrb r2, [r2, #0x2] */
/* @0x2e6e02 orrs r0, r3 */
/* @0x2e6e04 orr.w r2, r0, r2, lsl #8 */
/* @0x2e6e08 ldr r3, [r4, #0x8] */
/* @0x2e6e0a mov r0, r2 */
/* @0x2e6e0c adds r3, #0x4 */
/* @0x2e6e0e str r3, [r4, #0x8] */
/* @0x2e6e10 b 0x2e6e18 <FT_Stream_ReadULong+0x54> */
/* @0x2e6e12 movs r0, #0x0 */
/* @0x2e6e14 movs r3, #0x55 */
/* @0x2e6e16 str r3, [r5] */
/* @0x2e6e18 add sp, #0xc */
/* @0x2e6e1a pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6e1c · anon_2e6e1c · size=200 · insn=51 */
/* @0x2e6e1c .word 0x43f7e92d */
/* @0x2e6e20 strmi r10, [lr], -r1, lsl #26 */
/* @0x2e6e24 strtmi r4, [r9], -r4, lsl #12 */
/* @0x2e6e28 .word 0xf7ff4690 */
/* @0x2e6e2c blls 0x366d60 <_ZTS12CDS_Priority+0x8db8> */
/* @0x2e6e30 teqle r12, r0, lsl #22 */
/* @0x2e6e34 strhle r4, [r1], -r0 */
/* @0x2e6e38 eors r2, r9, r2 */
/* @0x2e6e3c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e6e40 .word 0xffc0f7ff */
/* @0x2e6e44 stmdahs r0, {r0, r11, r12, pc} */
/* @0x2e6e48 qasxmi sp, r0, r2 */
/* @0x2e6e4c .word 0xf7ff2110 */
/* @0x2e6e50 andls pc, r1, pc, ror #26 */
/* @0x2e6e54 strtmi r11, [r0], -r0, ror #22 */
/* @0x2e6e58 .word 0xf7ff4629 */
/* @0x2e6e5c mcrls p14, #0x0, pc, c1, c3, #0x2 */
/* @0x2e6e60 bllt 0x878684 <b2_toiTime+0x11f1e0> */
/* @0x2e6e64 rscle r2, r7, r0, lsl #16 */
/* @0x2e6e68 ble 0xffc37968 <b2_toiTime+0xffffffffff4de4c4> */
/* @0x2e6e6c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e6e70 .word 0xffa8f7ff */
/* @0x2e6e74 ldmiblt r3, {r0, r8, r9, r11, r12, pc} ^ */
/* @0x2e6e78 strtmi r2, [r0], -r2, lsl #16 */
/* @0x2e6e7c strtmi sp, [r9], -lr, lsl #2 */
/* @0x2e6e80 .word 0xffa0f7ff */
/* @0x2e6e84 strmi r9, [r1], r1, lsl #22 */
/* @0x2e6e88 strtmi r11, [r0], -r11, ror #18 */
/* @0x2e6e8c .word 0xf7ff4629 */
/* @0x2e6e90 blls 0x366cfc <_ZTS12CDS_Priority+0x8d54> */
/* @0x2e6e94 .word 0xf8c8b93b */
/* @0x2e6e98 and r9, r8, r0 */
/* @0x2e6e9c .word 0xf7ff2108 */
/* @0x2e6ea0 andls pc, r1, r7, asr #26 */
/* @0x2e6ea4 strlo r11, [r1], -r0, lsr #18 */
/* @0x2e6ea8 .word 0x4630e7de */
/* @0x2e6eac ldrmi lr, [r8], -r0 */
/* @0x2e6eb0 pop {r0, r1, r12, sp, pc} */
/* @0x2e6eb4 strdeq r8, r9, [r0], -r0 */
/* @0x2e6eb8 bls 0x2eeec0 <FT_Done_Memory+0x524c> */
/* @0x2e6ebc tstlt r9, r8, lsl r0 */
/* @0x2e6ec0 stmdbmi r2, {r3, r9, r10, lr} */
/* @0x2e6ec4 svclt #0xaaf7ff */
/* @0x2e6ec8 .word 0x47702051 */
/* @0x2e6ecc andeq r1, r5, r0, lsl #12 */
/* @0x2e6ed0 bls 0x2eeed8 <FT_Done_Memory+0x5264> */
/* @0x2e6ed4 tstlt r9, r8, lsl r0 */
/* @0x2e6ed8 stmdbmi r2, {r3, r9, r10, lr} */
/* @0x2e6edc svclt #0x9ef7ff */
/* @0x2e6ee0 .word 0x47702051 */
/* @0x2e6ee4 andeq r1, r5, r7, lsl #12 */

/* ── FUNC 0x2e6ee8 · FT_Stream_ReadULongLE · size=88 · insn=43 */
/* @0x2e6ee8 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e6eea movs r3, #0x0 */
/* @0x2e6eec str r3, [r1] */
/* @0x2e6eee mov r5, r1 */
/* @0x2e6ef0 ldr r3, [r0, #0x8] */
/* @0x2e6ef2 mov r4, r0 */
/* @0x2e6ef4 ldr r2, [r0, #0x4] */
/* @0x2e6ef6 adds r1, r3, #0x3 */
/* @0x2e6ef8 cmp r1, r2 */
/* @0x2e6efa bhs 0x2e6f36 <FT_Stream_ReadULongLE+0x4e> */
/* @0x2e6efc ldr r7, [r0, #0x14] */
/* @0x2e6efe cbz r7, 0x2e6f12 <FT_Stream_ReadULongLE+0x2a> */
/* @0x2e6f00 add r6, sp, #0x4 */
/* @0x2e6f02 mov r1, r3 */
/* @0x2e6f04 movs r3, #0x4 */
/* @0x2e6f06 mov r2, r6 */
/* @0x2e6f08 blx r7 */
/* @0x2e6f0a cmp r0, #0x4 */
/* @0x2e6f0c bne 0x2e6f36 <FT_Stream_ReadULongLE+0x4e> */
/* @0x2e6f0e mov r2, r6 */
/* @0x2e6f10 b 0x2e6f18 <FT_Stream_ReadULongLE+0x30> */
/* @0x2e6f12 ldr r2, [r0] */
/* @0x2e6f14 adds r2, r2, r3 */
/* @0x2e6f16 beq 0x2e6f2c <FT_Stream_ReadULongLE+0x44> */
/* @0x2e6f18 ldrb r0, [r2, #0x2] */
/* @0x2e6f1a ldrb r3, [r2, #0x3] */
/* @0x2e6f1c lsls r0, r0, #0x10 */
/* @0x2e6f1e orr.w r0, r0, r3, lsl #24 */
/* @0x2e6f20 ldmdavc r3, {r0, r1, sp, lr} */
/* @0x2e6f22 ldrb r3, [r2] */
/* @0x2e6f24 ldrb r2, [r2, #0x1] */
/* @0x2e6f26 orrs r0, r3 */
/* @0x2e6f28 orr.w r2, r0, r2, lsl #8 */
/* @0x2e6f2c ldr r3, [r4, #0x8] */
/* @0x2e6f2e mov r0, r2 */
/* @0x2e6f30 adds r3, #0x4 */
/* @0x2e6f32 str r3, [r4, #0x8] */
/* @0x2e6f34 b 0x2e6f3c <FT_Stream_ReadULongLE+0x54> */
/* @0x2e6f36 movs r0, #0x0 */
/* @0x2e6f38 movs r3, #0x55 */
/* @0x2e6f3a str r3, [r5] */
/* @0x2e6f3c add sp, #0xc */
/* @0x2e6f3e pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6f40 · FT_Atan2 · size=32 · insn=15 */
/* @0x2e6f40 push {r0, r1, r4, lr} */
/* @0x2e6f42 cbnz r0, 0x2e6f46 <FT_Atan2+0x6> */
/* @0x2e6f44 cbz r1, 0x2e6f5a <FT_Atan2+0x1a> */
/* @0x2e6f46 stm.w sp, {r0, r1} */
/* @0x2e6f48 strbtmi r0, [r8], -r3 */
/* @0x2e6f4a mov r0, sp */
/* @0x2e6f4c bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8> */
/* @0x2e6f50 mov r0, sp */
/* @0x2e6f52 bl 0x2e4b38 <_ZNK11b2GearJoint8GetRatioEv+0x234> */
/* @0x2e6f54 stmdals r1, {r0, r4, r5, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e6f56 ldr r0, [sp, #0x4] */
/* @0x2e6f58 b 0x2e6f5c <FT_Atan2+0x1c> */
/* @0x2e6f5a mov r0, r1 */
/* @0x2e6f5c add sp, #0x8 */
/* @0x2e6f5e pop {r4, pc} */

/* ── FUNC 0x2e6f60 · FT_Vector_Unit · size=40 · insn=20 */
/* @0x2e6f60 push {r4, lr} */
/* @0x2e6f62 mov r4, r0 */
/* @0x2e6f64 cbz r0, 0x2e6f82 <FT_Vector_Unit+0x22> */
/* @0x2e6f66 ldr r2, [pc, #0x1c] */
/* @0x2e6f68 movs r3, #0x0 */
/* @0x2e6f6a stm.w r0, {r2, r3} */
/* @0x2e6f6c .word 0xf7fd000c */
/* @0x2e6f6e bl 0x2e4ac4 <_ZNK11b2GearJoint8GetRatioEv+0x1c0> */
/* @0x2e6f70 stmdavs r3!, {r0, r3, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e6f72 ldr r3, [r4] */
/* @0x2e6f74 adds r3, #0x80 */
/* @0x2e6f76 asrs r3, r3, #0x8 */
/* @0x2e6f78 str r3, [r4] */
/* @0x2e6f7a ldr r3, [r4, #0x4] */
/* @0x2e6f7c adds r3, #0x80 */
/* @0x2e6f7e asrs r3, r3, #0x8 */
/* @0x2e6f80 str r3, [r4, #0x4] */
/* @0x2e6f82 pop {r4, pc} */
/* @0x2e6f84 bls 0x2e703e <FT_Vector_Length+0x16> */
/* @0x2e6f86 lsls r3, r3, #0x3 */

/* ── FUNC 0x2e6f88 · FT_Cos · size=18 · insn=9 */
/* @0x2e6f88 push {r0, r1, r2, lr} */
/* @0x2e6f8a mov r1, r0 */
/* @0x2e6f8c mov r0, sp */
/* @0x2e6f8e bl 0x2e6f60 <FT_Vector_Unit> */
/* @0x2e6f90 stmdals r0, {r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e6f92 ldr r0, [sp] */
/* @0x2e6f94 add sp, #0xc */
/* @0x2e6f96 ldr pc, [sp], #4 */
/* @0x2e6f98 strlt pc, [r7, #-0xb04] */

/* ── FUNC 0x2e6f9a · FT_Sin · size=18 · insn=9 */
/* @0x2e6f9a push {r0, r1, r2, lr} */
/* @0x2e6f9c mov r1, r0 */
/* @0x2e6f9e mov r0, sp */
/* @0x2e6fa0 bl 0x2e6f60 <FT_Vector_Unit> */
/* @0x2e6fa2 stmdals r1, {r1, r2, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e6fa4 ldr r0, [sp, #0x4] */
/* @0x2e6fa6 add sp, #0xc */
/* @0x2e6fa8 ldr pc, [sp], #4 */
/* @0x2e6faa strlt pc, [r7, #-0xb04] */

/* ── FUNC 0x2e6fac · FT_Tan · size=24 · insn=11 */
/* @0x2e6fac push {r0, r1, r2, lr} */
/* @0x2e6fae mov r1, r0 */
/* @0x2e6fb0 mov r0, sp */
/* @0x2e6fb2 bl 0x2e6f60 <FT_Vector_Unit> */
/* @0x2e6fb4 stmdals r1, {r0, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e6fb6 ldr r0, [sp, #0x4] */
/* @0x2e6fb8 ldr r1, [sp] */
/* @0x2e6fba bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e6fbc andlt pc, r3, r12, ror pc */
/* @0x2e6fbe add sp, #0xc */
/* @0x2e6fc0 ldr pc, [sp], #4 */

/* ── FUNC 0x2e6fc4 · FT_Vector_Rotate · size=100 · insn=46 */
/* @0x2e6fc4 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e6fc6 mov r7, r1 */
/* @0x2e6fc8 mov r4, r0 */
/* @0x2e6fca cbz r0, 0x2e7024 <FT_Vector_Rotate+0x60> */
/* @0x2e6fcc cbz r1, 0x2e7024 <FT_Vector_Rotate+0x60> */
/* @0x2e6fce ldm r0, {r0, r1} */
/* @0x2e6fd0 stm.w sp, {r0, r1} */
/* @0x2e6fd4 cbnz r0, 0x2e6fd8 <FT_Vector_Rotate+0x14> */
/* @0x2e6fd6 cbz r1, 0x2e7024 <FT_Vector_Rotate+0x60> */
/* @0x2e6fd8 mov r0, sp */
/* @0x2e6fda bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8> */
/* @0x2e6fdc shsub8mi pc, r9, pc */
/* @0x2e6fde mov r1, r7 */
/* @0x2e6fe0 mov r5, r0 */
/* @0x2e6fe2 mov r0, sp */
/* @0x2e6fe4 bl 0x2e4ac4 <_ZNK11b2GearJoint8GetRatioEv+0x1c0> */
/* @0x2e6fe8 ldr r0, [sp] */
/* @0x2e6fea bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166> */
/* @0x2e6fec .word 0x4606fd3e */
/* @0x2e6fee mov r6, r0 */
/* @0x2e6ff0 ldr r0, [sp, #0x4] */
/* @0x2e6ff2 bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166> */
/* @0x2e6ff4 stchs p13, c15, [r0, #-232] */
/* @0x2e6ff6 cmp r5, #0x0 */
/* @0x2e6ff8 ble 0x2e7018 <FT_Vector_Rotate+0x54> */
/* @0x2e6ffa subs r3, r5, #0x1 */
/* @0x2e6ffc movs r2, #0x1 */
/* @0x2e6ffe lsl.w r3, r2, r3 */
/* @0x2e7000 ldmne r2!, {r0, r1, r8, r9, r12, sp, lr, pc} ^ */
/* @0x2e7002 adds r2, r6, r3 */
/* @0x2e7004 add r3, r0 */
/* @0x2e7006 add.w r6, r2, r6, asr #31 */
/* @0x2e7008 bl 0x3c4ba8 <error_g0017+0x1d84c> */
/* @0x2e700a add.w r0, r3, r0, asr #31 */
/* @0x2e700c smulwtmi lr, r0, r0 */
/* @0x2e700e asrs r6, r5 */
/* @0x2e7010 asr.w r5, r0, r5 */
/* @0x2e7014 str r6, [r4] */
/* @0x2e7016 b 0x2e7022 <FT_Vector_Rotate+0x5e> */
/* @0x2e7018 rsbs r5, r5, #0 */
/* @0x2e701a lsls r6, r5 */
/* @0x2e701c lsl.w r5, r0, r5 */
/* @0x2e7020 str r6, [r4] */
/* @0x2e7022 str r5, [r4, #0x4] */
/* @0x2e7024 add sp, #0xc */
/* @0x2e7026 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e7028 · FT_Vector_Length · size=82 · insn=39 */
/* @0x2e7028 push {r0, r1, r2, r4, r5, lr} */
/* @0x2e702a cbz r0, 0x2e7076 <FT_Vector_Length+0x4e> */
/* @0x2e702c ldm r0, {r0, r1} */
/* @0x2e702e stm.w sp, {r0, r1} */
/* @0x2e7030 strmi r0, [r3], -r3 */
/* @0x2e7032 mov r3, r0 */
/* @0x2e7034 mov r0, r1 */
/* @0x2e7036 cbnz r3, 0x2e7040 <FT_Vector_Length+0x18> */
/* @0x2e7038 cmp r0, #0x0 */
/* @0x2e703a it lt */
/* @0x2e703c rsblt r0, r0, #0 */
/* @0x2e703e b 0x2e7076 <FT_Vector_Length+0x4e> */
/* @0x2e7040 cbnz r1, 0x2e704c <FT_Vector_Length+0x24> */
/* @0x2e7042 eor.w r0, r3, r3, asr #31 */
/* @0x2e7044 bl 0xfeb033d8 <b2_toiTime+0xfffffffffe3a9f34> */
/* @0x2e7046 sub.w r0, r0, r3, asr #31 */
/* @0x2e7048 ands r7, r4, r3, ror #1 */
/* @0x2e704a b 0x2e7076 <FT_Vector_Length+0x4e> */
/* @0x2e704c mov r0, sp */
/* @0x2e704e bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8> */
/* @0x2e7050 strmi pc, [r5], -r5, asr #27 */
/* @0x2e7052 mov r5, r0 */
/* @0x2e7054 mov r0, sp */
/* @0x2e7056 bl 0x2e4b38 <_ZNK11b2GearJoint8GetRatioEv+0x234> */
/* @0x2e7058 stmdals r0, {r0, r1, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e705a ldr r0, [sp] */
/* @0x2e705c bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166> */
/* @0x2e7060 cmp r5, #0x0 */
/* @0x2e7062 ble 0x2e7072 <FT_Vector_Length+0x4a> */
/* @0x2e7064 subs r3, r5, #0x1 */
/* @0x2e7066 movs r2, #0x1 */
/* @0x2e7068 lsl.w r3, r2, r3 */
/* @0x2e706c add r0, r3 */
/* @0x2e706e asrs r0, r5 */
/* @0x2e7070 b 0x2e7076 <FT_Vector_Length+0x4e> */
/* @0x2e7072 rsbs r5, r5, #0 */
/* @0x2e7074 lsls r0, r5 */
/* @0x2e7076 add sp, #0xc */
/* @0x2e7078 pop {r4, r5, pc} */

/* ── FUNC 0x2e707a · FT_Hypot · size=18 · insn=8 */
/* @0x2e707a push {r0, r1, r2, lr} */
/* @0x2e707c stm.w sp, {r0, r1} */
/* @0x2e707e strbtmi r0, [r8], -r3 */
/* @0x2e7080 mov r0, sp */
/* @0x2e7082 bl 0x2e7028 <FT_Vector_Length> */
/* @0x2e7086 add sp, #0xc */
/* @0x2e7088 ldr pc, [sp], #4 */
/* @0x2e708a ldrblt pc, [r7, #0xb04]! */

/* ── FUNC 0x2e708c · FT_Vector_Polarize · size=66 · insn=31 */
/* @0x2e708c push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e708e mov r6, r1 */
/* @0x2e7090 mov r7, r2 */
/* @0x2e7092 cbz r0, 0x2e70ca <FT_Vector_Polarize+0x3e> */
/* @0x2e7094 cbz r1, 0x2e70ca <FT_Vector_Polarize+0x3e> */
/* @0x2e7096 cbz r2, 0x2e70ca <FT_Vector_Polarize+0x3e> */
/* @0x2e7098 ldm r0, {r0, r1} */
/* @0x2e709a stm.w sp, {r0, r1} */
/* @0x2e709c stmdblt r0, {r0, r1} */
/* @0x2e709e cbnz r0, 0x2e70a2 <FT_Vector_Polarize+0x16> */
/* @0x2e70a0 cbz r1, 0x2e70ca <FT_Vector_Polarize+0x3e> */
/* @0x2e70a2 mov r0, sp */
/* @0x2e70a4 bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8> */
/* @0x2e70a8 mov r5, r0 */
/* @0x2e70aa mov r0, sp */
/* @0x2e70ac bl 0x2e4b38 <_ZNK11b2GearJoint8GetRatioEv+0x234> */
/* @0x2e70b0 ldr r0, [sp] */
/* @0x2e70b2 bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166> */
/* @0x2e70b4 blls 0x366424 <_ZTS12CDS_Priority+0x847c> */
/* @0x2e70b6 ldr r3, [sp, #0x4] */
/* @0x2e70b8 cmp r5, #0x0 */
/* @0x2e70ba itet lt */
/* @0x2e70bc rsblt r5, r5, #0 */
/* @0x2e70be asrge.w r5, r0, r5 */
/* @0x2e70c0 blx 0x3244dc */
/* @0x2e70c2 lsllt.w r5, r0, r5 */
/* @0x2e70c4 eorsvs pc, r5, r5, lsl #10 */
/* @0x2e70c6 str r5, [r6] */
/* @0x2e70c8 str r3, [r7] */
/* @0x2e70ca add sp, #0xc */
/* @0x2e70cc pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e70ce · FT_Vector_From_Polar · size=16 · insn=8 */
/* @0x2e70ce cbz r0, 0x2e70dc <FT_Vector_From_Polar+0xe> */
/* @0x2e70d0 str r1, [r0] */
/* @0x2e70d2 movs r1, #0x0 */
/* @0x2e70d4 str r1, [r0, #0x4] */
/* @0x2e70d6 mov r1, r2 */
/* @0x2e70d8 b.w 0x2e6fc4 <FT_Vector_Rotate> */
/* @0x2e70da .word 0x4770bf74 */
/* @0x2e70dc bx lr */

/* ── FUNC 0x2e70de · anon_2e70de · size=0 · insn=1 */
/* @0x2e70de blmi 0x4670e6 <g_RomDisk+0x6f8c6> */

/* ── FUNC 0x2e70e0 · FT_Angle_Diff · size=32 · insn=14 */
/* @0x2e70e0 ldr r3, [pc, #0x18] */
/* @0x2e70e2 subs r0, r1, r0 */
/* @0x2e70e4 cmp r0, r3 */
/* @0x2e70e6 bge 0x2e70ee <FT_Angle_Diff+0xe> */
/* @0x2e70e8 add.w r0, r0, #0x1680000 */
/* @0x2e70ec b 0x2e70e4 <FT_Angle_Diff+0x4> */
/* @0x2e70ee cmp.w r0, #0xb40000 */
/* @0x2e70f0 stcle p15, c0, [r2, #-208] */
/* @0x2e70f2 ble 0x2e70fa <FT_Angle_Diff+0x1a> */
/* @0x2e70f4 sub.w r0, r0, #0x1680000 */
/* @0x2e70f8 b 0x2e70ee <FT_Angle_Diff+0xe> */
/* @0x2e70fa bx lr */
/* @0x2e70fc movs r1, r0 */
/* @0x2e70fe vqrshl.u8 d27, d0, d12 */

/* ── FUNC 0x2e7100 · ft_mem_qalloc · size=38 · insn=19 */
/* @0x2e7100 push {r4, lr} */
/* @0x2e7102 mov r4, r2 */
/* @0x2e7104 subs r2, r1, #0x0 */
/* @0x2e7106 mov r3, r0 */
/* @0x2e7108 ble 0x2e7118 <ft_mem_qalloc+0x18> */
/* @0x2e710a ldr r3, [r0, #0x4] */
/* @0x2e710c blx r3 */
/* @0x2e710e cmp r0, #0x0 */
/* @0x2e7110 ite eq */
/* @0x2e7112 moveq r3, #0x40 */
/* @0x2e7114 movne r3, #0x0 */
/* @0x2e7116 b 0x2e7122 <ft_mem_qalloc+0x22> */
/* @0x2e7118 itete eq */
/* @0x2e711a moveq r0, r2 */
/* @0x2e711c movne r0, #0x0 */
/* @0x2e711e moveq r3, r0 */
/* @0x2e7120 movne r3, #0x6 */
/* @0x2e7122 str r3, [r4] */
/* @0x2e7124 pop {r4, pc} */

/* ── FUNC 0x2e7126 · ft_mem_alloc · size=38 · insn=17 */
/* @0x2e7126 push {r0, r1, r4, r5, r6, lr} */
/* @0x2e7128 mov r5, r2 */
/* @0x2e712a add r2, sp, #0x4 */
/* @0x2e712c mov r4, r1 */
/* @0x2e712e bl 0x2e7100 <ft_mem_qalloc> */
/* @0x2e7132 ldr r1, [sp, #0x4] */
/* @0x2e7134 mov r6, r0 */
/* @0x2e7136 cbnz r1, 0x2e7142 <ft_mem_alloc+0x1c> */
/* @0x2e7138 cmp r4, #0x0 */
/* @0x2e713a ble 0x2e7142 <ft_mem_alloc+0x1c> */
/* @0x2e713c mov r2, r4 */
/* @0x2e713e blx 0xb65b0 <memset@plt> */
/* @0x2e7142 ldr r3, [sp, #0x4] */
/* @0x2e7144 mov r0, r6 */
/* @0x2e7146 str r3, [r5] */
/* @0x2e7148 add sp, #0x8 */
/* @0x2e714a pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e714c · FT_GlyphLoader_New · size=28 · insn=14 */
/* @0x2e714c push {r0, r1, r2, r4, r5, lr} */
/* @0x2e714e mov r4, r1 */
/* @0x2e7150 add r2, sp, #0x4 */
/* @0x2e7152 movs r1, #0x60 */
/* @0x2e7154 mov r5, r0 */
/* @0x2e7156 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e7158 blls 0x3670f8 <_ZTS12CDS_Priority+0x9150> */
/* @0x2e715a ldr r3, [sp, #0x4] */
/* @0x2e715c cbnz r3, 0x2e7162 <FT_GlyphLoader_New+0x16> */
/* @0x2e715e str r5, [r0] */
/* @0x2e7160 str r0, [r4] */
/* @0x2e7162 ldr r0, [sp, #0x4] */
/* @0x2e7164 add sp, #0xc */
/* @0x2e7166 pop {r4, r5, pc} */

/* ── FUNC 0x2e7168 · anon_2e7168 · size=396 · insn=100 */
/* @0x2e7168 .word 0x43f7e92d */
/* @0x2e716c strmi r10, [r4], -r2, lsl #28 */
/* @0x2e7170 ldrmi r4, [r7], -r8, lsl #12 */
/* @0x2e7174 .word 0xf04f460d */
/* @0x2e7178 .word 0xf8460900 */
/* @0x2e717c .word 0xf5cf9d04 */
/* @0x2e7180 pkhtbmi lr, r0, r12, asr #19 */
/* @0x2e7184 .word 0xf5cf4638 */
/* @0x2e7188 .word 0x4632e9d8 */
/* @0x2e718c .word 0x0100eb08 */
/* @0x2e7190 .word 0x31014620 */
/* @0x2e7194 .word 0xffc7f7ff */
/* @0x2e7198 .word 0x8004f8dd */
/* @0x2e719c .word 0xf1b84604 */
/* @0x2e71a0 tstle lr, r0, lsl #30 */
/* @0x2e71a4 .word 0x212f4628 */
/* @0x2e71a8 bl 0x1aa48ec <b2_toiTime+0x134b448> */
/* @0x2e71ac .word 0xb1684606 */
/* @0x2e71b0 stmdbeq r0, {r0, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2e71b4 strtmi r4, [r0], -r9, lsr #12 */
/* @0x2e71b8 andeq pc, r1, #1073741826 */
/* @0x2e71bc ldmib r4, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e71c0 movweq lr, #0x9b04 */
/* @0x2e71c4 .word 0xf8831c75 */
/* @0x2e71c8 and r8, r0, r1 */
/* @0x2e71cc ldrtmi r7, [r9], -r0, lsr #32 */
/* @0x2e71d0 .word 0xf5cf4620 */
/* @0x2e71d4 strtmi lr, [r0], -r10, lsr #20 */
/* @0x2e71d8 .word 0xf5cf4629 */
/* @0x2e71dc strtmi lr, [r0], -r6, lsr #20 */
/* @0x2e71e0 strbmi lr, [r8], -r0 */
/* @0x2e71e4 pop {r0, r1, r12, sp, pc} */
/* @0x2e71e8 strdeq r8, r9, [r0], -r0 */
/* @0x2e71ec bmi 0x4b8a38 <SrcVerts+0x15a7c> */
/* @0x2e71f0 ldrbtmi r11, [r10], #-1296 */
/* @0x2e71f4 ldrmi r6, [r12], -r0, lsl #16 */
/* @0x2e71f8 .word 0xffb6f7ff */
/* @0x2e71fc blls 0x393684 <ft_adobe_glyph_list+0x2d60> */
/* @0x2e7200 andhs r6, r0, r0, lsr #32 */
/* @0x2e7204 ldclt p0, c6, [r0, #-96] */
/* @0x2e7208 ldclt p0, c2, [r0, #-256] */
/* @0x2e720c andeq r7, r10, r7, asr #10 */
/* @0x2e7210 bmi 0x4b8a5c <SrcVerts+0x15aa0> */
/* @0x2e7214 ldrbtmi r11, [r10], #-1296 */
/* @0x2e7218 ldrmi r6, [r12], -r0, lsl #16 */
/* @0x2e721c .word 0xffa4f7ff */
/* @0x2e7220 blls 0x3936a8 <ft_adobe_glyph_list+0x2d84> */
/* @0x2e7224 andhs r6, r0, r0, lsr #32 */
/* @0x2e7228 ldclt p0, c6, [r0, #-96] */
/* @0x2e722c ldclt p0, c2, [r0, #-256] */
/* @0x2e7230 andeq r7, r10, lr, lsr #10 */
/* @0x2e7234 mvnsmi lr, sp, lsr #18 */
/* @0x2e7238 ldrmi r4, [r0], -r5, lsl #12 */
/* @0x2e723c sadd8mi r4, r7, r8 */
/* @0x2e7240 ldmdb r10!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e7244 .word 0x46044b10 */
/* @0x2e7248 stmdavs r8!, {r2, r3, r4, r7, r9, lr} */
/* @0x2e724c stcne p12, c13, [r1, #88]! */
/* @0x2e7250 .word 0xf7ffaa01 */
/* @0x2e7254 stcls p15, c15, [r1, #-416] */
/* @0x2e7258 stmiblt sp, {r1, r2, r9, r10, lr} */
/* @0x2e725c qasxmi r4, r2, r9 */
/* @0x2e7260 stmib r12!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} */
/* @0x2e7264 ldmdbne r3!, {r0, r3, r9, r11, lr} */
/* @0x2e7268 ldmdavs r1, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x2e726c .word 0x51318892 */
/* @0x2e7270 blls 0x5074e0 <SrcVerts+0x64524> */
/* @0x2e7274 andvs pc, r0, r8, asr #17 */
/* @0x2e7278 and r6, r1, sp, lsl r0 */
/* @0x2e727c and r2, r0, r10 */
/* @0x2e7280 andlt r4, r2, r8, lsr #12 */
/* @0x2e7284 ldrhhi lr, [r0, #141]! */
/* @0x2e7288 svcvc #0xfffff9 */
/* @0x2e728c andeq r7, r10, r10, ror #9 */
/* @0x2e7290 .word 0x4606b5f7 */
/* @0x2e7294 sadd16mi r4, pc, r0 */
/* @0x2e7298 .word 0xf5cf4615 */
/* @0x2e729c blmi 0x8217dc <b2_toiTime+0xc8338> */
/* @0x2e72a0 addsmi r4, r12, #4, #12 */
/* @0x2e72a4 .word 0xdc1d6830 */
/* @0x2e72a8 .word 0xf104aa01 */
/* @0x2e72ac .word 0xf7ff0112 */
/* @0x2e72b0 bls 0x366fa0 <_ZTS12CDS_Priority+0x8ff8> */
/* @0x2e72b4 ldmiblt r10!, {r1, r2, r9, r10, lr} */
/* @0x2e72b8 strtmi r4, [r2], -r9, lsr #12 */
/* @0x2e72bc ldmdb lr!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e72c0 ldrtmi r4, [r4], #-2316 */
/* @0x2e72c4 .word 0xf1014479 */
/* @0x2e72c8 .word 0xf8510310 */
/* @0x2e72cc addsmi r2, r9, #4, #22 */
/* @0x2e72d0 blhs 0x4253e8 <g_RomDisk+0x2dbc8> */
/* @0x2e72d4 stmdahi r11, {r0, r3, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2e72d8 eorhi r2, r3, r0 */
/* @0x2e72dc eorsvs r9, lr, r8, lsl #22 */
/* @0x2e72e0 and r6, r2, r8, lsl r0 */
/* @0x2e72e4 and r2, r0, r10 */
/* @0x2e72e8 andlt r4, r3, r0, lsl r6 */
/* @0x2e72ec svclt #0xbdf0 */
/* @0x2e72f0 svcvc #0xffffed */
/* @0x2e72f4 muleq r10, r4, r4 */

/* ── FUNC 0x2e72f8 · FT_New_Library · size=62 · insn=30 */
/* @0x2e72f8 push {r0, r1, r2, r4, r5, lr} */
/* @0x2e72fa mov r4, r1 */
/* @0x2e72fc mov r5, r0 */
/* @0x2e72fe cbz r0, 0x2e732c <FT_New_Library+0x34> */
/* @0x2e7300 cbz r1, 0x2e732c <FT_New_Library+0x34> */
/* @0x2e7302 movs r1, #0xc0 */
/* @0x2e7304 add r2, sp, #0x4 */
/* @0x2e7306 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e7308 blls 0x366f48 <_ZTS12CDS_Priority+0x8fa0> */
/* @0x2e730a ldr r3, [sp, #0x4] */
/* @0x2e730c cbnz r3, 0x2e7330 <FT_New_Library+0x38> */
/* @0x2e730e movs r2, #0x2 */
/* @0x2e7310 str r5, [r0] */
/* @0x2e7312 str r2, [r0, #0x4] */
/* @0x2e7314 movs r2, #0x8 */
/* @0x2e7316 str.w r3, [r0, #0xa8] */
/* @0x2e7318 addvs r3, r2, r8, lsr #1 */
/* @0x2e731a str r2, [r0, #0x8] */
/* @0x2e731c movs r2, #0x1 */
/* @0x2e731e str.w r3, [r0, #0xa4] */
/* @0x2e7320 sbcvs r3, r3, r4, lsr #1 */
/* @0x2e7322 str r3, [r0, #0xc] */
/* @0x2e7324 str.w r2, [r0, #0xbc] */
/* @0x2e7328 str r0, [r4] */
/* @0x2e732a b 0x2e7330 <FT_New_Library+0x38> */
/* @0x2e732c movs r0, #0x6 */
/* @0x2e732e b 0x2e7332 <FT_New_Library+0x3a> */
/* @0x2e7330 mov r0, r3 */
/* @0x2e7332 add sp, #0xc */
/* @0x2e7334 pop {r4, r5, pc} */

/* ── FUNC 0x2e7336 · ft_mem_free · size=10 · insn=5 */
/* @0x2e7336 push {r3, lr} */
/* @0x2e7338 cbz r1, 0x2e733e <ft_mem_free+0x8> */
/* @0x2e733a ldr r3, [r0, #0x8] */
/* @0x2e733c blx r3 */
/* @0x2e733e pop {r3, pc} */

/* ── FUNC 0x2e7340 · FT_GlyphLoader_Reset · size=76 · insn=33 */
/* @0x2e7340 push {r4, r5, r6, lr} */
/* @0x2e7342 mov r4, r0 */
/* @0x2e7344 ldr r6, [r0] */
/* @0x2e7346 movs r5, #0x0 */
/* @0x2e7348 ldr r1, [r4, #0x18] */
/* @0x2e734a mov r0, r6 */
/* @0x2e734c bl 0x2e7336 <ft_mem_free> */
/* @0x2e7350 mov r0, r6 */
/* @0x2e7352 ldr r1, [r4, #0x1c] */
/* @0x2e7354 str r5, [r4, #0x18] */
/* @0x2e7356 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7358 ldrtmi pc, [r0], -lr, ror #31 */
/* @0x2e735a mov r0, r6 */
/* @0x2e735c ldr r1, [r4, #0x20] */
/* @0x2e735e str r5, [r4, #0x1c] */
/* @0x2e7360 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7364 mov r0, r6 */
/* @0x2e7366 ldr r1, [r4, #0x28] */
/* @0x2e7368 str r5, [r4, #0x20] */
/* @0x2e736a bl 0x2e7336 <ft_mem_free> */
/* @0x2e736c ldrtmi pc, [r0], -r4, ror #31 */
/* @0x2e736e mov r0, r6 */
/* @0x2e7370 str r5, [r4, #0x28] */
/* @0x2e7372 ldr r1, [r4, #0x34] */
/* @0x2e7374 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7378 str r5, [r4, #0x34] */
/* @0x2e737a str r5, [r4, #0x2c] */
/* @0x2e737c mov r0, r4 */
/* @0x2e737e str r5, [r4, #0x4] */
/* @0x2e7380 str r5, [r4, #0x8] */
/* @0x2e7382 str r5, [r4, #0xc] */
/* @0x2e7384 pop.w {r4, r5, r6, lr} */
/* @0x2e7388 b.w 0x2e52bc <FT_GlyphLoader_Rewind> */

/* ── FUNC 0x2e738c · FT_GlyphLoader_Done · size=26 · insn=10 */
/* @0x2e738c push {r3, r4, r5, lr} */
/* @0x2e738e mov r4, r0 */
/* @0x2e7390 cbz r0, 0x2e73a4 <FT_GlyphLoader_Done+0x18> */
/* @0x2e7392 ldr r5, [r0] */
/* @0x2e7394 bl 0x2e7340 <FT_GlyphLoader_Reset> */
/* @0x2e7398 mov r1, r4 */
/* @0x2e739a mov r0, r5 */
/* @0x2e739c pop.w {r3, r4, r5, lr} */
/* @0x2e73a0 b.w 0x2e7336 <ft_mem_free> */
/* @0x2e73a4 pop {r3, r4, r5, pc} */
