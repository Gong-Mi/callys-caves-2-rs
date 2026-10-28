/* libyoyo.so 覆盖卡组 0252
 * 函数 0x2a5b08..0x2a658e，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a5b08 · png_calculate_crc · size=48 · insn=21 */
/* @0x2a5b08 push {r4, lr} */
/* @0x2a5b0a mov r4, r0 */
/* @0x2a5b0c ldrb.w r3, [r0, #0x1e0] */
/* @0x2a5b10 tst.w r3, #0x20 */
/* @0x2a5b14 ldr.w r3, [r0, #0x130] */
/* @0x2a5b18 beq 0x2a5b26 <png_calculate_crc+0x1e> */
/* @0x2a5b1a and r3, r3, #0x300 */
/* @0x2a5b1c .word 0xf5b37340 */
/* @0x2a5b1e cmp.w r3, #0x300 */
/* @0x2a5b20 .word 0xd1027f40 */
/* @0x2a5b22 bne 0x2a5b2a <png_calculate_crc+0x22> */
/* @0x2a5b24 pop {r4, pc} */
/* @0x2a5b26 lsls r3, r3, #0x14 */
/* @0x2a5b28 bmi 0x2a5b36 <png_calculate_crc+0x2e> */
/* @0x2a5b2a ldr.w r0, [r4, #0x1d4] */
/* @0x2a5b2c .word 0xf61101d4 */
/* @0x2a5b2e blx 0xb6ea4 <crc32@plt> */
/* @0x2a5b30 .word 0xf8c4e9ba */
/* @0x2a5b32 str.w r0, [r4, #0x1d4] */
/* @0x2a5b34 ldclt p1, c0, [r0, #-848] */
/* @0x2a5b36 pop {r4, pc} */

/* ── FUNC 0x2a5b38 · png_info_init_3 · size=44 · insn=20 */
/* @0x2a5b38 push {r4, lr} */
/* @0x2a5b3a mov r4, r0 */
/* @0x2a5b3c ldr r0, [r0] */
/* @0x2a5b3e cbz r0, 0x2a5b62 <png_info_init_3+0x2a> */
/* @0x2a5b40 cmp.w r1, #0x120 */
/* @0x2a5b44 bhs 0x2a5b54 <png_info_init_3+0x1c> */
/* @0x2a5b46 bl 0x2a6c88 <png_destroy_struct> */
/* @0x2a5b48 mulhs r2, pc, r8 */
/* @0x2a5b4a movs r0, #0x2 */
/* @0x2a5b4c bl 0x2a6c56 <png_create_struct> */
/* @0x2a5b50 str r0, [r4] */
/* @0x2a5b52 cbz r0, 0x2a5b62 <png_info_init_3+0x2a> */
/* @0x2a5b54 movs r1, #0x0 */
/* @0x2a5b56 mov.w r2, #0x120 */
/* @0x2a5b58 pop {r4, r7, r9, r12, sp, lr} */
/* @0x2a5b5a pop.w {r4, lr} */
/* @0x2a5b5c .word 0xf0754010 */
/* @0x2a5b5e b.w 0x31bacc <__udivdi3+0x434> */
/* @0x2a5b60 ldclt p15, c11, [r0, #-724] */
/* @0x2a5b62 pop {r4, pc} */

/* ── FUNC 0x2a5b64 · png_create_info_struct · size=44 · insn=18 */
/* @0x2a5b64 push {r0, r1, r2, lr} */
/* @0x2a5b66 mov r3, r0 */
/* @0x2a5b68 cbz r0, 0x2a5b8a <png_create_info_struct+0x26> */
/* @0x2a5b6a movs r0, #0x2 */
/* @0x2a5b6c ldr.w r1, [r3, #0x2ec] */
/* @0x2a5b70 ldr.w r2, [r3, #0x2e8] */
/* @0x2a5b74 bl 0x2a6c02 <png_create_struct_2> */
/* @0x2a5b78 str r0, [sp, #0x4] */
/* @0x2a5b7a cbz r0, 0x2a5b86 <png_create_info_struct+0x22> */
/* @0x2a5b7c add r0, sp, #0x4 */
/* @0x2a5b7e mov.w r1, #0x120 */
/* @0x2a5b80 .word 0xf7ff7190 */
/* @0x2a5b82 bl 0x2a5b38 <png_info_init_3> */
/* @0x2a5b84 stmdals r1, {r0, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a5b86 ldr r0, [sp, #0x4] */
/* @0x2a5b88 b 0x2a5b8a <png_create_info_struct+0x26> */
/* @0x2a5b8a add sp, #0xc */
/* @0x2a5b8c ldr pc, [sp], #4 */

/* ── FUNC 0x2a5b90 · png_data_freer · size=48 · insn=20 */
/* @0x2a5b90 cbz r0, 0x2a5bba <png_data_freer+0x2a> */
/* @0x2a5b92 cbz r1, 0x2a5bba <png_data_freer+0x2a> */
/* @0x2a5b94 cmp r2, #0x1 */
/* @0x2a5b96 bne 0x2a5ba0 <png_data_freer+0x10> */
/* @0x2a5b98 ldr.w r2, [r1, #0xb8] */
/* @0x2a5b9c orrs r3, r2 */
/* @0x2a5b9e b 0x2a5bac <png_data_freer+0x1c> */
/* @0x2a5ba0 cmp r2, #0x2 */
/* @0x2a5ba2 bne 0x2a5bb2 <png_data_freer+0x22> */
/* @0x2a5ba4 ldr.w r2, [r1, #0xb8] */
/* @0x2a5ba8 bic.w r3, r2, r3 */
/* @0x2a5bac str.w r3, [r1, #0xb8] */
/* @0x2a5bb0 bx lr */
/* @0x2a5bb2 ldr r1, [pc, #0x8] */
/* @0x2a5bb4 add r1, pc */
/* @0x2a5bb6 b.w 0x2a6474 <png_warning> */
/* @0x2a5bb8 .word 0x4770bc5d */
/* @0x2a5bba bx lr */
/* @0x2a5bbc str r2, [r5, #0x68] */
/* @0x2a5bbe movs r6, r1 */

/* ── FUNC 0x2a5bc0 · png_free_data · size=766 · insn=321 */
/* @0x2a5bc0 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a5bc4 mov r4, r1 */
/* @0x2a5bc6 mov r6, r2 */
/* @0x2a5bc8 mov r7, r3 */
/* @0x2a5bca mov r5, r0 */
/* @0x2a5bcc cmp r0, #0x0 */
/* @0x2a5bce beq.w 0x2a5eba <png_free_data+0x2fa> */
/* @0x2a5bd0 stmdbhs r0, {r2, r4, r5, r6, r8, pc} */
/* @0x2a5bd2 cmp r1, #0x0 */
/* @0x2a5bd4 beq.w 0x2a5eba <png_free_data+0x2fa> */
/* @0x2a5bd8 ldr.w r3, [r1, #0xb8] */
/* @0x2a5bdc and r3, r3, #0x4000 */
/* @0x2a5be0 tst r3, r2 */
/* @0x2a5be2 beq 0x2a5c34 <png_free_data+0x74> */
/* @0x2a5be4 adds r3, r7, #0x1 */
/* @0x2a5be6 bne 0x2a5bee <png_free_data+0x2e> */
/* @0x2a5be8 mov.w r8, #0x0 */
/* @0x2a5bec b 0x2a5c0e <png_free_data+0x4e> */
/* @0x2a5bee ldr r3, [r1, #0x38] */
/* @0x2a5bf0 cbz r3, 0x2a5c34 <png_free_data+0x74> */
/* @0x2a5bf2 mov.w r8, #0x1c */
/* @0x2a5bf4 blx 0x4a7c6e <SrcVerts+0x4cb2> */
/* @0x2a5bf6 mul r8, r8, r7 */
/* @0x2a5bf8 strbmi pc, [r3], #-2055 */
/* @0x2a5bfa add r3, r8 */
/* @0x2a5bfc ldr r1, [r3, #0x4] */
/* @0x2a5bfe cbz r1, 0x2a5c34 <png_free_data+0x74> */
/* @0x2a5c00 bl 0x2a6cfc <png_free> */
/* @0x2a5c04 ldr r3, [r4, #0x38] */
/* @0x2a5c06 movs r2, #0x0 */
/* @0x2a5c08 add r3, r8 */
/* @0x2a5c0a str r2, [r3, #0x4] */
/* @0x2a5c0c b 0x2a5c34 <png_free_data+0x74> */
/* @0x2a5c0e ldr r3, [r4, #0x30] */
/* @0x2a5c10 mov r0, r5 */
/* @0x2a5c12 cmp r8, r3 */
/* @0x2a5c14 bge 0x2a5c28 <png_free_data+0x68> */
/* @0x2a5c16 mov r3, r8 */
/* @0x2a5c18 mov r1, r4 */
/* @0x2a5c1a mov.w r2, #0x4000 */
/* @0x2a5c1c cpsie i */
/* @0x2a5c1e add.w r8, r8, #0x1 */
/* @0x2a5c20 .word 0xf7ff0801 */
/* @0x2a5c22 bl 0x2a5bc0 <png_free_data> */
/* @0x2a5c24 ldrb pc, [r2, sp, asr #31]! */
/* @0x2a5c26 b 0x2a5c0e <png_free_data+0x4e> */
/* @0x2a5c28 ldr r1, [r4, #0x38] */
/* @0x2a5c2a bl 0x2a6cfc <png_free> */
/* @0x2a5c2c movwhs pc, #0x867 */
/* @0x2a5c2e movs r3, #0x0 */
/* @0x2a5c30 str r3, [r4, #0x38] */
/* @0x2a5c32 str r3, [r4, #0x30] */
/* @0x2a5c34 ldr.w r3, [r4, #0xb8] */
/* @0x2a5c38 and r3, r3, #0x2000 */
/* @0x2a5c3c tst r3, r6 */
/* @0x2a5c3e beq 0x2a5c54 <png_free_data+0x94> */
/* @0x2a5c40 mov r0, r5 */
/* @0x2a5c42 ldr r1, [r4, #0x4c] */
/* @0x2a5c44 bl 0x2a6cfc <png_free> */
/* @0x2a5c48 movs r3, #0x0 */
/* @0x2a5c4a str r3, [r4, #0x4c] */
/* @0x2a5c4c ldr r3, [r4, #0x8] */
/* @0x2a5c4e bic r3, r3, #0x10 */
/* @0x2a5c50 adcvs r0, r3, r0, lsl r3 */
/* @0x2a5c52 str r3, [r4, #0x8] */
/* @0x2a5c54 ldr.w r3, [r4, #0xb8] */
/* @0x2a5c58 ands r3, r6 */
/* @0x2a5c5a lsls r0, r3, #0x17 */
/* @0x2a5c5c bpl 0x2a5c66 <png_free_data+0xa6> */
/* @0x2a5c5e ldr r2, [r4, #0x8] */
/* @0x2a5c60 bic r2, r2, #0x4000 */
/* @0x2a5c64 str r2, [r4, #0x8] */
/* @0x2a5c66 lsls r1, r3, #0x18 */
/* @0x2a5c68 bpl 0x2a5cce <png_free_data+0x10e> */
/* @0x2a5c6a mov r0, r5 */
/* @0x2a5c6c ldr.w r1, [r4, #0xa0] */
/* @0x2a5c70 bl 0x2a6cfc <png_free> */
/* @0x2a5c74 mov r0, r5 */
/* @0x2a5c76 ldr.w r1, [r4, #0xac] */
/* @0x2a5c78 .word 0xf00110ac */
/* @0x2a5c7a bl 0x2a6cfc <png_free> */
/* @0x2a5c7c .word 0xf8d4f83f */
/* @0x2a5c7e ldr.w r2, [r4, #0xb0] */
/* @0x2a5c80 movwhs r2, #0xb0 */
/* @0x2a5c82 movs r3, #0x0 */
/* @0x2a5c84 str.w r3, [r4, #0xa0] */
/* @0x2a5c88 str.w r3, [r4, #0xac] */
/* @0x2a5c8c cbz r2, 0x2a5cc6 <png_free_data+0x106> */
/* @0x2a5c8e mov r8, r3 */
/* @0x2a5c90 mov r9, r3 */
/* @0x2a5c92 ldrb.w r3, [r4, #0xb5] */
/* @0x2a5c94 ldrmi r3, [r8, #0xb5] */
/* @0x2a5c96 cmp r8, r3 */
/* @0x2a5c98 bge 0x2a5cb6 <png_free_data+0xf6> */
/* @0x2a5c9a ldr.w r3, [r4, #0xb0] */
/* @0x2a5c9c .word 0x462830b0 */
/* @0x2a5c9e mov r0, r5 */
/* @0x2a5ca0 ldr.w r1, [r3, r8, lsl #2] */
/* @0x2a5ca4 bl 0x2a6cfc <png_free> */
/* @0x2a5ca8 ldr.w r3, [r4, #0xb0] */
/* @0x2a5cac str.w r9, [r3, r8, lsl #2] */
/* @0x2a5cb0 add.w r8, r8, #0x1 */
/* @0x2a5cb4 b 0x2a5c92 <png_free_data+0xd2> */
/* @0x2a5cb6 mov r0, r5 */
/* @0x2a5cb8 ldr.w r1, [r4, #0xb0] */
/* @0x2a5cbc bl 0x2a6cfc <png_free> */
/* @0x2a5cc0 movs r3, #0x0 */
/* @0x2a5cc2 str.w r3, [r4, #0xb0] */
/* @0x2a5cc4 stmvs r3!, {r4, r5, r7, r12, sp} */
/* @0x2a5cc6 ldr r3, [r4, #0x8] */
/* @0x2a5cc8 bic r3, r3, #0x400 */
/* @0x2a5ccc str r3, [r4, #0x8] */
/* @0x2a5cce ldr.w r3, [r4, #0xb8] */
/* @0x2a5cd0 .word 0xf00330b8 */
/* @0x2a5cd2 and r3, r3, #0x10 */
/* @0x2a5cd4 eorsmi r0, r3, #16, #6 */
/* @0x2a5cd6 tst r3, r6 */
/* @0x2a5cd8 beq 0x2a5d00 <png_free_data+0x140> */
/* @0x2a5cda mov r0, r5 */
/* @0x2a5cdc ldr.w r1, [r4, #0xc4] */
/* @0x2a5ce0 bl 0x2a6cfc <png_free> */
/* @0x2a5ce4 mov r0, r5 */
/* @0x2a5ce6 ldr.w r1, [r4, #0xc8] */
/* @0x2a5ce8 .word 0xf00110c8 */
/* @0x2a5cea bl 0x2a6cfc <png_free> */
/* @0x2a5cec movwhs pc, #0x807 */
/* @0x2a5cee movs r3, #0x0 */
/* @0x2a5cf0 str.w r3, [r4, #0xc4] */
/* @0x2a5cf4 str.w r3, [r4, #0xc8] */
/* @0x2a5cf8 ldr r3, [r4, #0x8] */
/* @0x2a5cfa bic r3, r3, #0x1000 */
/* @0x2a5cfc adcvs r5, r3, r0, lsl #7 */
/* @0x2a5cfe str r3, [r4, #0x8] */
/* @0x2a5d00 ldr.w r3, [r4, #0xb8] */
/* @0x2a5d04 and r3, r3, #0x20 */
/* @0x2a5d08 tst r3, r6 */
/* @0x2a5d0a beq 0x2a5d84 <png_free_data+0x1c4> */
/* @0x2a5d0c adds r2, r7, #0x1 */
/* @0x2a5d0e beq 0x2a5d46 <png_free_data+0x186> */
/* @0x2a5d10 ldr.w r3, [r4, #0xd4] */
/* @0x2a5d14 cbz r3, 0x2a5d84 <png_free_data+0x1c4> */
/* @0x2a5d16 lsl.w r8, r7, #0x4 */
/* @0x2a5d18 strtmi r1, [r8], -r7, lsl #16 */
/* @0x2a5d1a mov r0, r5 */
/* @0x2a5d1c ldr.w r1, [r3, r8] */
/* @0x2a5d20 bl 0x2a6cfc <png_free> */
/* @0x2a5d24 ldr.w r3, [r4, #0xd4] */
/* @0x2a5d28 mov r0, r5 */
/* @0x2a5d2a add r3, r8 */
/* @0x2a5d2c ldr r1, [r3, #0x8] */
/* @0x2a5d2e bl 0x2a6cfc <png_free> */
/* @0x2a5d30 .word 0xf8d4ffe5 */
/* @0x2a5d32 ldr.w r2, [r4, #0xd4] */
/* @0x2a5d34 movwhs r2, #0xd4 */
/* @0x2a5d36 movs r3, #0x0 */
/* @0x2a5d38 str.w r3, [r2, r8] */
/* @0x2a5d3c ldr.w r2, [r4, #0xd4] */
/* @0x2a5d40 add r2, r8 */
/* @0x2a5d42 str r3, [r2, #0x8] */
/* @0x2a5d44 b 0x2a5d84 <png_free_data+0x1c4> */
/* @0x2a5d46 ldr.w r3, [r4, #0xd8] */
/* @0x2a5d48 ldrsblt r3, [r11, r8]! */
/* @0x2a5d4a cbz r3, 0x2a5d7c <png_free_data+0x1bc> */
/* @0x2a5d4c mov.w r8, #0x0 */
/* @0x2a5d50 ldr.w r3, [r4, #0xd8] */
/* @0x2a5d54 mov r0, r5 */
/* @0x2a5d56 cmp r8, r3 */
/* @0x2a5d58 bge 0x2a5d6a <png_free_data+0x1aa> */
/* @0x2a5d5a mov r3, r8 */
/* @0x2a5d5c mov r1, r4 */
/* @0x2a5d5e movs r2, #0x20 */
/* @0x2a5d60 add.w r8, r8, #0x1 */
/* @0x2a5d64 bl 0x2a5bc0 <png_free_data> */
/* @0x2a5d68 b 0x2a5d50 <png_free_data+0x190> */
/* @0x2a5d6a ldr.w r1, [r4, #0xd4] */
/* @0x2a5d6c .word 0xf00010d4 */
/* @0x2a5d6e bl 0x2a6cfc <png_free> */
/* @0x2a5d70 movwhs pc, #0xfc5 */
/* @0x2a5d72 movs r3, #0x0 */
/* @0x2a5d74 str.w r3, [r4, #0xd4] */
/* @0x2a5d78 str.w r3, [r4, #0xd8] */
/* @0x2a5d7c ldr r3, [r4, #0x8] */
/* @0x2a5d7e bic r3, r3, #0x2000 */
/* @0x2a5d80 adcvs r5, r3, r0, lsl #6 */
/* @0x2a5d82 str r3, [r4, #0x8] */
/* @0x2a5d84 ldr.w r1, [r5, #0x31c] */
/* @0x2a5d88 cbz r1, 0x2a5d96 <png_free_data+0x1d6> */
/* @0x2a5d8a mov r0, r5 */
/* @0x2a5d8c bl 0x2a6cfc <png_free> */
/* @0x2a5d90 movs r3, #0x0 */
/* @0x2a5d92 str.w r3, [r5, #0x31c] */
/* @0x2a5d94 .word 0xf8d4331c */
/* @0x2a5d96 ldr.w r3, [r4, #0xb8] */
/* @0x2a5d98 vst4.32 {d3, d4, d5, d6}, [r3:256], r8 */
/* @0x2a5d9a and r3, r3, #0x200 */
/* @0x2a5d9c eorsmi r7, r3, #0, #6 */
/* @0x2a5d9e tst r3, r6 */
/* @0x2a5da0 beq 0x2a5e02 <png_free_data+0x242> */
/* @0x2a5da2 adds r3, r7, #0x1 */
/* @0x2a5da4 beq 0x2a5dca <png_free_data+0x20a> */
/* @0x2a5da6 ldr.w r3, [r4, #0xbc] */
/* @0x2a5da8 cmplt r3, #188 */
/* @0x2a5daa cbz r3, 0x2a5e02 <png_free_data+0x242> */
/* @0x2a5dac mov.w r8, #0x14 */
/* @0x2a5db0 mov r0, r5 */
/* @0x2a5db2 mul r8, r8, r7 */
/* @0x2a5db4 strbmi pc, [r3], #-2055 */
/* @0x2a5db6 add r3, r8 */
/* @0x2a5db8 ldr r1, [r3, #0x8] */
/* @0x2a5dba bl 0x2a6cfc <png_free> */
/* @0x2a5dbc .word 0xf8d4ff9f */
/* @0x2a5dbe ldr.w r3, [r4, #0xbc] */
/* @0x2a5dc0 andhs r3, r0, #188 */
/* @0x2a5dc2 movs r2, #0x0 */
/* @0x2a5dc4 add r3, r8 */
/* @0x2a5dc6 str r2, [r3, #0x8] */
/* @0x2a5dc8 b 0x2a5e02 <png_free_data+0x242> */
/* @0x2a5dca ldr.w r3, [r4, #0xc0] */
/* @0x2a5dcc biclt r3, r3, r0, asr #1 */
/* @0x2a5dce cbz r3, 0x2a5e02 <png_free_data+0x242> */
/* @0x2a5dd0 mov.w r8, #0x0 */
/* @0x2a5dd4 ldr.w r3, [r4, #0xc0] */
/* @0x2a5dd8 mov r0, r5 */
/* @0x2a5dda cmp r8, r3 */
/* @0x2a5ddc bge 0x2a5df0 <png_free_data+0x230> */
/* @0x2a5dde mov r3, r8 */
/* @0x2a5de0 mov r1, r4 */
/* @0x2a5de2 mov.w r2, #0x200 */
/* @0x2a5de4 .word 0xf1087200 */
/* @0x2a5de6 add.w r8, r8, #0x1 */
/* @0x2a5de8 .word 0xf7ff0801 */
/* @0x2a5dea bl 0x2a5bc0 <png_free_data> */
/* @0x2a5dec ldrb pc, [r1, r9, ror #29]! */
/* @0x2a5dee b 0x2a5dd4 <png_free_data+0x214> */
/* @0x2a5df0 ldr.w r1, [r4, #0xbc] */
/* @0x2a5df4 bl 0x2a6cfc <png_free> */
/* @0x2a5df8 movs r3, #0x0 */
/* @0x2a5dfa str.w r3, [r4, #0xbc] */
/* @0x2a5dfc .word 0xf8c430bc */
/* @0x2a5dfe str.w r3, [r4, #0xc0] */
/* @0x2a5e00 .word 0xf8d430c0 */
/* @0x2a5e02 ldr.w r3, [r4, #0xb8] */
/* @0x2a5e04 .word 0xf00330b8 */
/* @0x2a5e06 and r3, r3, #0x8 */
/* @0x2a5e08 eorsmi r0, r3, #8, #6 */
/* @0x2a5e0a tst r3, r6 */
/* @0x2a5e0c beq 0x2a5e22 <png_free_data+0x262> */
/* @0x2a5e0e mov r0, r5 */
/* @0x2a5e10 ldr r1, [r4, #0x7c] */
/* @0x2a5e12 bl 0x2a6cfc <png_free> */
/* @0x2a5e14 movwhs pc, #0xf73 */
/* @0x2a5e16 movs r3, #0x0 */
/* @0x2a5e18 str r3, [r4, #0x7c] */
/* @0x2a5e1a ldr r3, [r4, #0x8] */
/* @0x2a5e1c bic r3, r3, #0x40 */
/* @0x2a5e20 str r3, [r4, #0x8] */
/* @0x2a5e22 ldr.w r3, [r4, #0xb8] */
/* @0x2a5e24 vst4.32 {d3, d4, d5, d6}, [r3:256], r8 */
/* @0x2a5e26 and r3, r3, #0x1000 */
/* @0x2a5e28 eorsmi r5, r3, #128, #6 */
/* @0x2a5e2a tst r3, r6 */
/* @0x2a5e2c beq 0x2a5e44 <png_free_data+0x284> */
/* @0x2a5e2e mov r0, r5 */
/* @0x2a5e30 ldr r1, [r4, #0x10] */
/* @0x2a5e32 bl 0x2a5af0 <png_zfree> */
/* @0x2a5e34 stmvs r2!, {r0, r2, r3, r4, r6, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a5e36 ldr r2, [r4, #0x8] */
/* @0x2a5e38 movs r3, #0x0 */
/* @0x2a5e3a str r3, [r4, #0x10] */
/* @0x2a5e3c bic r2, r2, #0x8 */
/* @0x2a5e40 strh r3, [r4, #0x14] */
/* @0x2a5e42 str r2, [r4, #0x8] */
/* @0x2a5e44 ldr.w r3, [r4, #0xb8] */
/* @0x2a5e48 and r3, r3, #0x40 */
/* @0x2a5e4c tst r3, r6 */
/* @0x2a5e4e beq 0x2a5e96 <png_free_data+0x2d6> */
/* @0x2a5e50 ldr.w r3, [r4, #0xf8] */
/* @0x2a5e54 cbz r3, 0x2a5e8e <png_free_data+0x2ce> */
/* @0x2a5e56 mov.w r8, #0x0 */
/* @0x2a5e58 strbmi r0, [r1], r0, lsl #16 */
/* @0x2a5e5a mov r9, r8 */
/* @0x2a5e5c ldr r3, [r4, #0x4] */
/* @0x2a5e5e cmp r8, r3 */
/* @0x2a5e60 bge 0x2a5e7e <png_free_data+0x2be> */
/* @0x2a5e62 ldr.w r3, [r4, #0xf8] */
/* @0x2a5e64 qsub8mi r3, r8, r8 */
/* @0x2a5e66 mov r0, r5 */
/* @0x2a5e68 ldr.w r1, [r3, r8, lsl #2] */
/* @0x2a5e6c bl 0x2a6cfc <png_free> */
/* @0x2a5e70 ldr.w r3, [r4, #0xf8] */
/* @0x2a5e74 str.w r9, [r3, r8, lsl #2] */
/* @0x2a5e78 add.w r8, r8, #0x1 */
/* @0x2a5e7c b 0x2a5e5c <png_free_data+0x29c> */
/* @0x2a5e7e mov r0, r5 */
/* @0x2a5e80 ldr.w r1, [r4, #0xf8] */
/* @0x2a5e84 bl 0x2a6cfc <png_free> */
/* @0x2a5e88 movs r3, #0x0 */
/* @0x2a5e8a str.w r3, [r4, #0xf8] */
/* @0x2a5e8c stmvs r3!, {r3, r4, r5, r6, r7, r12, sp} */
/* @0x2a5e8e ldr r3, [r4, #0x8] */
/* @0x2a5e90 bic r3, r3, #0x8000 */
/* @0x2a5e94 str r3, [r4, #0x8] */
/* @0x2a5e96 adds r7, #0x1 */
/* @0x2a5e98 ldr.w r3, [r4, #0xb8] */
/* @0x2a5e9c bne 0x2a5eaa <png_free_data+0x2ea> */
/* @0x2a5e9e bic.w r6, r3, r6 */
/* @0x2a5ea0 .word 0xf8c40606 */
/* @0x2a5ea2 str.w r6, [r4, #0xb8] */
/* @0x2a5ea4 pop {r3, r4, r5, r7, sp, lr} */
/* @0x2a5ea6 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2a5ea8 .word 0xf42683f8 */
/* @0x2a5eaa bic r6, r6, #0x4200 */
/* @0x2a5eac .word 0xf0264684 */
/* @0x2a5eae bic r6, r6, #0x20 */
/* @0x2a5eb0 b 0xb67738 <b2_toiTime+0x40e294> */
/* @0x2a5eb2 bic.w r3, r3, r6 */
/* @0x2a5eb4 .word 0xf8c40306 */
/* @0x2a5eb6 str.w r3, [r4, #0xb8] */
/* @0x2a5eb8 pop {r3, r4, r5, r7, r12, sp} */
/* @0x2a5eba pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2a5ebc ldrlt r8, [r3, #-0x3f8] */

/* ── FUNC 0x2a5ebe · png_info_destroy · size=58 · insn=26 */
/* @0x2a5ebe push {r0, r1, r4, lr} */
/* @0x2a5ec0 mov.w r3, #0xffffffff */
/* @0x2a5ec2 .word 0x460433ff */
/* @0x2a5ec4 mov r4, r0 */
/* @0x2a5ec6 movw r2, #0x7fff */
/* @0x2a5eca str r1, [sp, #0x4] */
/* @0x2a5ecc bl 0x2a5bc0 <png_free_data> */
/* @0x2a5ece .word 0xf8d4fe78 */
/* @0x2a5ed0 ldr.w r3, [r4, #0x2cc] */
/* @0x2a5ed2 smlalbtlt r3, r11, r12, r2 */
/* @0x2a5ed4 cbz r3, 0x2a5eea <png_info_destroy+0x2c> */
/* @0x2a5ed6 mov r0, r4 */
/* @0x2a5ed8 ldr.w r1, [r4, #0x2d0] */
/* @0x2a5eda .word 0xf00012d0 */
/* @0x2a5edc bl 0x2a6cfc <png_free> */
/* @0x2a5ede movwhs pc, #0xf0e */
/* @0x2a5ee0 movs r3, #0x0 */
/* @0x2a5ee2 str.w r3, [r4, #0x2d0] */
/* @0x2a5ee6 str.w r3, [r4, #0x2cc] */
/* @0x2a5eea add r0, sp, #0x4 */
/* @0x2a5eec mov.w r1, #0x120 */
/* @0x2a5eee .word 0xf7ff7190 */
/* @0x2a5ef0 bl 0x2a5b38 <png_info_init_3> */
/* @0x2a5ef2 andlt pc, r2, r2, lsr #28 */
/* @0x2a5ef4 add sp, #0x8 */
/* @0x2a5ef6 pop {r4, pc} */

/* ── FUNC 0x2a5ef8 · png_destroy_info_struct · size=40 · insn=19 */
/* @0x2a5ef8 push {r4, r5, r6, lr} */
/* @0x2a5efa mov r4, r1 */
/* @0x2a5efc mov r6, r0 */
/* @0x2a5efe cbz r0, 0x2a5f1e <png_destroy_info_struct+0x26> */
/* @0x2a5f00 cbz r1, 0x2a5f1e <png_destroy_info_struct+0x26> */
/* @0x2a5f02 ldr r5, [r1] */
/* @0x2a5f04 cbz r5, 0x2a5f1e <png_destroy_info_struct+0x26> */
/* @0x2a5f06 mov r1, r5 */
/* @0x2a5f08 bl 0x2a5ebe <png_info_destroy> */
/* @0x2a5f0c mov r0, r5 */
/* @0x2a5f0e ldr.w r1, [r6, #0x2f0] */
/* @0x2a5f10 .word 0xf8d612f0 */
/* @0x2a5f12 ldr.w r2, [r6, #0x2e8] */
/* @0x2a5f14 .word 0xf00022e8 */
/* @0x2a5f16 bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2a5f18 movwhs pc, #0xea2 */
/* @0x2a5f1a movs r3, #0x0 */
/* @0x2a5f1c str r3, [r4] */
/* @0x2a5f1e pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a5f20 · png_get_io_ptr · size=8 · insn=4 */
/* @0x2a5f20 cbz r0, 0x2a5f26 <png_get_io_ptr+0x6> */
/* @0x2a5f22 ldr.w r0, [r0, #0x118] */
/* @0x2a5f24 .word 0x47700118 */
/* @0x2a5f26 bx lr */

/* ── FUNC 0x2a5f28 · png_init_io · size=8 · insn=4 */
/* @0x2a5f28 cbz r0, 0x2a5f2e <png_init_io+0x6> */
/* @0x2a5f2a str.w r1, [r0, #0x118] */
/* @0x2a5f2c .word 0x47701118 */
/* @0x2a5f2e bx lr */

/* ── FUNC 0x2a5f30 · png_convert_to_rfc1123 · size=132 · insn=54 */
/* @0x2a5f30 push {r4, r5, r6, lr} */
/* @0x2a5f32 mov r4, r1 */
/* @0x2a5f34 sub sp, #0x18 */
/* @0x2a5f36 mov r5, r0 */
/* @0x2a5f38 cmp r0, #0x0 */
/* @0x2a5f3a beq 0x2a5fa6 <png_convert_to_rfc1123+0x76> */
/* @0x2a5f3c ldr.w r3, [r0, #0x2bc] */
/* @0x2a5f40 cbnz r3, 0x2a5f4c <png_convert_to_rfc1123+0x1c> */
/* @0x2a5f42 movs r1, #0x1d */
/* @0x2a5f44 bl 0x2a6ca0 <png_malloc> */
/* @0x2a5f48 str.w r0, [r5, #0x2bc] */
/* @0x2a5f4c ldrb r0, [r4, #0x2] */
/* @0x2a5f4e movs r1, #0xc */
/* @0x2a5f50 ldrb r6, [r4, #0x3] */
/* @0x2a5f52 subs r0, #0x1 */
/* @0x2a5f54 blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2a5f58 ldr r3, [pc, #0x50] */
/* @0x2a5f5a ldrb r0, [r4, #0x4] */
/* @0x2a5f5c and r6, r6, #0x1f */
/* @0x2a5f60 add r3, pc */
/* @0x2a5f62 adds r3, #0x8 */
/* @0x2a5f64 add.w r1, r3, r1, lsl #2 */
/* @0x2a5f68 ldrh r3, [r4] */
/* @0x2a5f6a str r1, [sp] */
/* @0x2a5f6c movs r1, #0x18 */
/* @0x2a5f6e str r3, [sp, #0x4] */
/* @0x2a5f70 blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2a5f74 ldrb r0, [r4, #0x5] */
/* @0x2a5f76 uxtb r1, r1 */
/* @0x2a5f78 str r1, [sp, #0x8] */
/* @0x2a5f7a movs r1, #0x3c */
/* @0x2a5f7c blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2a5f80 ldrb r0, [r4, #0x6] */
/* @0x2a5f82 uxtb r1, r1 */
/* @0x2a5f84 str r1, [sp, #0xc] */
/* @0x2a5f86 movs r1, #0x3d */
/* @0x2a5f88 blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2a5f8c ldr r2, [pc, #0x20] */
/* @0x2a5f8e mov r3, r6 */
/* @0x2a5f90 add r2, pc */
/* @0x2a5f92 uxtb r1, r1 */
/* @0x2a5f94 str r1, [sp, #0x10] */
/* @0x2a5f96 movs r1, #0x1d */
/* @0x2a5f98 ldr.w r0, [r5, #0x2bc] */
/* @0x2a5f9c blx 0xb65c8 <snprintf@plt> */
/* @0x2a5fa0 ldr.w r0, [r5, #0x2bc] */
/* @0x2a5fa4 b 0x2a5fa6 <png_convert_to_rfc1123+0x76> */
/* @0x2a5fa6 add sp, #0x18 */
/* @0x2a5fa8 pop {r4, r5, r6, pc} */
/* @0x2a5faa nop */
/* @0x2a5fac ldr r1, [sp, #0x180] */
/* @0x2a5fae movs r6, r1 */
/* @0x2a5fb0 str r0, [r7, #0x2c] */
/* @0x2a5fb2 movs r6, r1 */

/* ── FUNC 0x2a5fb4 · png_get_copyright · size=12 · insn=6 */
/* @0x2a5fb4 ldr r0, [pc, #0x4] */
/* @0x2a5fb6 add r0, pc */
/* @0x2a5fb8 bx lr */
/* @0x2a5fba nop */
/* @0x2a5fbc str r0, [r6, #0x2c] */
/* @0x2a5fbe movs r6, r1 */

/* ── FUNC 0x2a5fc0 · png_get_libpng_ver · size=12 · insn=6 */
/* @0x2a5fc0 ldr r0, [pc, #0x4] */
/* @0x2a5fc2 add r0, pc */
/* @0x2a5fc4 bx lr */
/* @0x2a5fc6 nop */
/* @0x2a5fc8 str r6, [r5, #0x38] */
/* @0x2a5fca movs r6, r1 */

/* ── FUNC 0x2a5fcc · png_get_header_ver · size=12 · insn=6 */
/* @0x2a5fcc ldr r0, [pc, #0x4] */
/* @0x2a5fce add r0, pc */
/* @0x2a5fd0 bx lr */
/* @0x2a5fd2 nop */
/* @0x2a5fd4 str r2, [r4, #0x38] */
/* @0x2a5fd6 movs r6, r1 */

/* ── FUNC 0x2a5fd8 · png_get_header_version · size=12 · insn=6 */
/* @0x2a5fd8 ldr r0, [pc, #0x4] */
/* @0x2a5fda add r0, pc */
/* @0x2a5fdc bx lr */
/* @0x2a5fde nop */
/* @0x2a5fe0 str r5, [r3, #0x38] */
/* @0x2a5fe2 movs r6, r1 */

/* ── FUNC 0x2a5fe4 · png_handle_as_unknown · size=66 · insn=32 */
/* @0x2a5fe4 push {r4, r5, r6, lr} */
/* @0x2a5fe6 mov r6, r1 */
/* @0x2a5fe8 cbz r0, 0x2a6024 <png_handle_as_unknown+0x40> */
/* @0x2a5fea cbz r1, 0x2a601c <png_handle_as_unknown+0x38> */
/* @0x2a5fec ldr.w r4, [r0, #0x2cc] */
/* @0x2a5ff0 cmp r4, #0x0 */
/* @0x2a5ff2 ble 0x2a6020 <png_handle_as_unknown+0x3c> */
/* @0x2a5ff4 movs r5, #0x5 */
/* @0x2a5ff6 ldr.w r3, [r0, #0x2d0] */
/* @0x2a5ff8 .word 0x436532d0 */
/* @0x2a5ffa muls r5, r4, r5 */
/* @0x2a5ffc subs r5, #0x5 */
/* @0x2a5ffe add r5, r3 */
/* @0x2a6000 mov r0, r6 */
/* @0x2a6002 mov r1, r5 */
/* @0x2a6004 movs r2, #0x4 */
/* @0x2a6006 blx 0xb6c40 <memcmp@plt> */
/* @0x2a6008 stmdblt r8, {r2, r3, r4, r9, r10, r11, sp, lr, pc} */
/* @0x2a600a cbnz r0, 0x2a6010 <png_handle_as_unknown+0x2c> */
/* @0x2a600c ldrb r0, [r5, #0x4] */
/* @0x2a600e pop {r4, r5, r6, pc} */
/* @0x2a6010 subs r4, #0x1 */
/* @0x2a6012 sub.w r5, r5, #0x5 */
/* @0x2a6014 mvnsle r0, r5, lsl #10 */
/* @0x2a6016 bne 0x2a6000 <png_handle_as_unknown+0x1c> */
/* @0x2a6018 mov r0, r4 */
/* @0x2a601a b 0x2a6024 <png_handle_as_unknown+0x40> */
/* @0x2a601c mov r0, r1 */
/* @0x2a601e pop {r4, r5, r6, pc} */
/* @0x2a6020 movs r0, #0x0 */
/* @0x2a6022 pop {r4, r5, r6, pc} */
/* @0x2a6024 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a6026 · png_reset_zstream · size=16 · insn=8 */
/* @0x2a6026 cbz r0, 0x2a6030 <png_reset_zstream+0xa> */
/* @0x2a6028 add.w r0, r0, #0x138 */
/* @0x2a602a .word 0xf075709c */
/* @0x2a602c b.w 0x31badc <__udivdi3+0x444> */
/* @0x2a602e .word 0xf06fbd56 */
/* @0x2a6030 mvn r0, #0x1 */
/* @0x2a6032 ldrbmi r0, [r0, -r1]! */
/* @0x2a6034 bx lr */

/* ── FUNC 0x2a6036 · png_access_version_number · size=6 · insn=2 */
/* @0x2a6036 movw r0, #0x28b3 */
/* @0x2a603a bx lr */

/* ── FUNC 0x2a603c · png_64bit_product · size=42 · insn=18 */
/* @0x2a603c push {r4, r5, r6, lr} */
/* @0x2a603e lsrs r4, r0, #0x10 */
/* @0x2a6040 lsrs r5, r1, #0x10 */
/* @0x2a6042 uxth r0, r0 */
/* @0x2a6044 uxth r1, r1 */
/* @0x2a6046 mul r6, r1, r0 */
/* @0x2a6048 msrmi SPSR_f, #0, #12 */
/* @0x2a604a muls r0, r5, r0 */
/* @0x2a604c mla r0, r1, r4, r0 */
/* @0x2a6050 muls r4, r5, r4 */
/* @0x2a6052 add.w r0, r0, r6, lsr #16 */
/* @0x2a6054 adcslt r4, r6, #22 */
/* @0x2a6056 uxth r6, r6 */
/* @0x2a6058 add.w r4, r4, r0, lsr #16 */
/* @0x2a605c orr.w r6, r6, r0, lsl #16 */
/* @0x2a6060 str r4, [r2] */
/* @0x2a6062 str r6, [r3] */
/* @0x2a6064 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a6068 · png_check_cHRM_fixed · size=328 · insn=156 */
/* @0x2a6068 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a606c sub sp, #0x14 */
/* @0x2a606e mov r8, r1 */
/* @0x2a6070 mov r9, r2 */
/* @0x2a6072 mov r6, r3 */
/* @0x2a6074 ldr r7, [sp, #0x38] */
/* @0x2a6076 ldr.w r11, [sp, #0x3c] */
/* @0x2a6078 .word 0x4604b03c */
/* @0x2a607a mov r4, r0 */
/* @0x2a607c ldr.w r10, [sp, #0x48] */
/* @0x2a6080 cmp r0, #0x0 */
/* @0x2a6082 beq.w 0x2a6188 <png_check_cHRM_fixed+0x120> */
/* @0x2a6084 stmdbhs r0, {r0, r7, pc} */
/* @0x2a6086 cmp r1, #0x0 */
/* @0x2a6088 blt 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a608a cmp r2, #0x0 */
/* @0x2a608c ble 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a608e cmp r3, #0x0 */
/* @0x2a6090 blt 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a6092 cmp r7, #0x0 */
/* @0x2a6094 blt 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a6096 cmp.w r11, #0x0 */
/* @0x2a6098 blle 0x4a9ca0 <SrcVerts+0x6ce4> */
/* @0x2a609a blt 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a609c ldr r2, [sp, #0x40] */
/* @0x2a609e cmp r2, #0x0 */
/* @0x2a60a0 blt 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a60a2 ldr r3, [sp, #0x44] */
/* @0x2a60a4 cmp r3, #0x0 */
/* @0x2a60a6 blt 0x2a60ae <png_check_cHRM_fixed+0x46> */
/* @0x2a60a8 cmp.w r10, #0x0 */
/* @0x2a60ac bge 0x2a60bc <png_check_cHRM_fixed+0x54> */
/* @0x2a60ae ldr r1, [pc, #0xe4] */
/* @0x2a60b0 mov r0, r4 */
/* @0x2a60b2 movs r5, #0x0 */
/* @0x2a60b4 add r1, pc */
/* @0x2a60b6 bl 0x2a6474 <png_warning> */
/* @0x2a60b8 .word 0xe000f9dd */
/* @0x2a60ba b 0x2a60be <png_check_cHRM_fixed+0x56> */
/* @0x2a60bc movs r5, #0x1 */
/* @0x2a60be mvn r3, #0x80000000 */
/* @0x2a60c0 ldrmi r4, [r8, #0x300] */
/* @0x2a60c2 cmp r8, r3 */
/* @0x2a60c4 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60c6 cmp r9, r3 */
/* @0x2a60c8 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60ca cmp r6, r3 */
/* @0x2a60cc beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60ce cmp r7, r3 */
/* @0x2a60d0 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60d2 cmp r11, r3 */
/* @0x2a60d4 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60d6 ldr r2, [sp, #0x40] */
/* @0x2a60d8 cmp r2, r3 */
/* @0x2a60da beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60dc ldr r2, [sp, #0x44] */
/* @0x2a60de cmp r2, r3 */
/* @0x2a60e0 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e> */
/* @0x2a60e2 cmp r10, r3 */
/* @0x2a60e4 bne 0x2a60f2 <png_check_cHRM_fixed+0x8a> */
/* @0x2a60e6 ldr r1, [pc, #0xb0] */
/* @0x2a60e8 mov r0, r4 */
/* @0x2a60ea movs r5, #0x0 */
/* @0x2a60ec add r1, pc */
/* @0x2a60ee bl 0x2a6474 <png_warning> */
/* @0x2a60f0 .word 0xf5c9f9c1 */
/* @0x2a60f2 rsb.w r2, r9, #0x18600 */
/* @0x2a60f4 adclo r3, r0, #805306380 */
/* @0x2a60f6 adds r2, #0xa0 */
/* @0x2a60f8 cmp r2, r8 */
/* @0x2a60fa bge 0x2a6108 <png_check_cHRM_fixed+0xa0> */
/* @0x2a60fc ldr r1, [pc, #0x9c] */
/* @0x2a60fe mov r0, r4 */
/* @0x2a6100 movs r5, #0x0 */
/* @0x2a6102 add r1, pc */
/* @0x2a6104 bl 0x2a6474 <png_warning> */
/* @0x2a6108 rsb.w r3, r7, #0x18600 */
/* @0x2a610c adds r3, #0xa0 */
/* @0x2a610e cmp r3, r6 */
/* @0x2a6110 bge 0x2a611e <png_check_cHRM_fixed+0xb6> */
/* @0x2a6112 ldr r1, [pc, #0x8c] */
/* @0x2a6114 mov r0, r4 */
/* @0x2a6116 movs r5, #0x0 */
/* @0x2a6118 add r1, pc */
/* @0x2a611a bl 0x2a6474 <png_warning> */
/* @0x2a611c bls 0x6e47d0 <g_SWFvertbuff+0x11708> */
/* @0x2a611e ldr r2, [sp, #0x40] */
/* @0x2a6120 rsb.w r3, r2, #0x18600 */
/* @0x2a6124 adds r3, #0xa0 */
/* @0x2a6126 cmp r3, r11 */
/* @0x2a6128 bge 0x2a6136 <png_check_cHRM_fixed+0xce> */
/* @0x2a612a ldr r1, [pc, #0x78] */
/* @0x2a612c mov r0, r4 */
/* @0x2a612e movs r5, #0x0 */
/* @0x2a6130 add r1, pc */
/* @0x2a6132 bl 0x2a6474 <png_warning> */
/* @0x2a6134 .word 0xf5caf99f */
/* @0x2a6136 rsb.w r3, r10, #0x18600 */
/* @0x2a6138 bls 0x6f304c <g_SWFvertbuff+0x1ff84> */
/* @0x2a613a ldr r2, [sp, #0x44] */
/* @0x2a613c adds r3, #0xa0 */
/* @0x2a613e cmp r3, r2 */
/* @0x2a6140 bge 0x2a614e <png_check_cHRM_fixed+0xe6> */
/* @0x2a6142 ldr r1, [pc, #0x64] */
/* @0x2a6144 mov r0, r4 */
/* @0x2a6146 movs r5, #0x0 */
/* @0x2a6148 add r1, pc */
/* @0x2a614a bl 0x2a6474 <png_warning> */
/* @0x2a614c bl 0xff4647a0 <b2_toiTime+0xfffffffffed0b2fc> */
/* @0x2a614e rsb r0, r6, r11 */
/* @0x2a6150 bl 0xff466184 <b2_toiTime+0xfffffffffed0cce0> */
/* @0x2a6152 rsb r1, r7, r10 */
/* @0x2a6154 strbtmi r0, [r10], -r10, lsl #2 */
/* @0x2a6156 mov r2, sp */
/* @0x2a6158 add r3, sp, #0x4 */
/* @0x2a615a bl 0x2a603c <png_64bit_product> */
/* @0x2a615c blls 0x6e5f20 <g_SWFvertbuff+0x12e58> */
/* @0x2a615e ldr r3, [sp, #0x40] */
/* @0x2a6160 ldr r2, [sp, #0x44] */
/* @0x2a6162 subs r0, r3, r7 */
/* @0x2a6164 add r3, sp, #0xc */
/* @0x2a6166 subs r1, r2, r6 */
/* @0x2a6168 add r2, sp, #0x8 */
/* @0x2a616a bl 0x2a603c <png_64bit_product> */
/* @0x2a616c blls 0x365f10 <_ZTS12CDS_Priority+0x7f68> */
/* @0x2a616e ldr r3, [sp, #0x8] */
/* @0x2a6170 ldr r2, [sp] */
/* @0x2a6172 cmp r2, r3 */
/* @0x2a6174 bne 0x2a618c <png_check_cHRM_fixed+0x124> */
/* @0x2a6176 ldr r3, [sp, #0xc] */
/* @0x2a6178 ldr r2, [sp, #0x4] */
/* @0x2a617a cmp r2, r3 */
/* @0x2a617c bne 0x2a618c <png_check_cHRM_fixed+0x124> */
/* @0x2a617e ldr r1, [pc, #0x2c] */
/* @0x2a6180 mov r0, r4 */
/* @0x2a6182 add r1, pc */
/* @0x2a6184 bl 0x2a6474 <png_warning> */
/* @0x2a6188 movs r0, #0x0 */
/* @0x2a618a b 0x2a618e <png_check_cHRM_fixed+0x126> */
/* @0x2a618c mov r0, r5 */
/* @0x2a618e add sp, #0x14 */
/* @0x2a6190 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a6194 str r0, [r6, #0x2c] */
/* @0x2a6196 movs r6, r1 */
/* @0x2a6198 str r4, [r5, #0x2c] */
/* @0x2a619a movs r6, r1 */
/* @0x2a619c str r4, [r2, #0x30] */
/* @0x2a619e movs r6, r1 */
/* @0x2a61a0 str r7, [r2, #0x30] */
/* @0x2a61a2 movs r6, r1 */
/* @0x2a61a4 str r6, [r2, #0x30] */
/* @0x2a61a6 movs r6, r1 */
/* @0x2a61a8 str r7, [r2, #0x30] */
/* @0x2a61aa movs r6, r1 */
/* @0x2a61ac str r5, [r6, #0x2c] */
/* @0x2a61ae movs r6, r1 */

/* ── FUNC 0x2a61b0 · png_check_IHDR · size=488 · insn=223 */
/* @0x2a61b0 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a61b4 mov r5, r3 */
/* @0x2a61b6 ldr r3, [sp, #0x38] */
/* @0x2a61b8 subs.w r8, r1, #0x0 */
/* @0x2a61bc mov r4, r0 */
/* @0x2a61be mov r7, r2 */
/* @0x2a61c0 ldr r6, [sp, #0x30] */
/* @0x2a61c2 ldr.w r11, [sp, #0x34] */
/* @0x2a61c4 movwls r11, #0x1034 */
/* @0x2a61c6 str r3, [sp, #0x4] */
/* @0x2a61c8 ldr.w r9, [sp, #0x3c] */
/* @0x2a61cc bne 0x2a61d4 <png_check_IHDR+0x24> */
/* @0x2a61ce ldr r1, [pc, #0x188] */
/* @0x2a61d0 add r1, pc */
/* @0x2a61d2 b 0x2a61de <png_check_IHDR+0x2e> */
/* @0x2a61d4 mov.w r10, #0x0 */
/* @0x2a61d8 bge 0x2a61e6 <png_check_IHDR+0x36> */
/* @0x2a61da ldr r1, [pc, #0x180] */
/* @0x2a61dc add r1, pc */
/* @0x2a61de bl 0x2a6474 <png_warning> */
/* @0x2a61e0 .word 0xf04ff949 */
/* @0x2a61e2 mov.w r10, #0x1 */
/* @0x2a61e4 .word 0xf1080a01 */
/* @0x2a61e6 add.w r1, r8, #0x7 */
/* @0x2a61e8 bmi 0x18e660c <b2_toiTime+0x118d168> */
/* @0x2a61ea ldr r2, [pc, #0x164] */
/* @0x2a61ec bic r1, r1, #0x7 */
/* @0x2a61f0 cmp r1, r2 */
/* @0x2a61f2 bls 0x2a6202 <png_check_IHDR+0x52> */
/* @0x2a61f4 ldr r1, [pc, #0x168] */
/* @0x2a61f6 mov r0, r4 */
/* @0x2a61f8 mov.w r10, #0x1 */
/* @0x2a61fc add r1, pc */
/* @0x2a61fe bl 0x2a6474 <png_warning> */
/* @0x2a6200 .word 0xf8d4f939 */
/* @0x2a6202 ldr.w r2, [r4, #0x308] */
/* @0x2a6204 ldrmi r2, [r0, #0x308] */
/* @0x2a6206 cmp r8, r2 */
/* @0x2a6208 bhi 0x2a6210 <png_check_IHDR+0x60> */
/* @0x2a620a ldr r2, [pc, #0x148] */
/* @0x2a620c cmp r8, r2 */
/* @0x2a620e bls 0x2a621e <png_check_IHDR+0x6e> */
/* @0x2a6210 ldr r1, [pc, #0x150] */
/* @0x2a6212 mov r0, r4 */
/* @0x2a6214 mov.w r10, #0x1 */
/* @0x2a6218 add r1, pc */
/* @0x2a621a bl 0x2a6474 <png_warning> */
/* @0x2a621c svchs #0xf92b */
/* @0x2a621e cmp r7, #0x0 */
/* @0x2a6220 bne 0x2a622a <png_check_IHDR+0x7a> */
/* @0x2a6222 ldr r1, [pc, #0x144] */
/* @0x2a6224 mov r0, r4 */
/* @0x2a6226 add r1, pc */
/* @0x2a6228 b 0x2a6232 <png_check_IHDR+0x82> */
/* @0x2a622a bge 0x2a623a <png_check_IHDR+0x8a> */
/* @0x2a622c ldr r1, [pc, #0x13c] */
/* @0x2a622e mov r0, r4 */
/* @0x2a6230 add r1, pc */
/* @0x2a6232 bl 0x2a6474 <png_warning> */
/* @0x2a6234 .word 0xf04ff91f */
/* @0x2a6236 mov.w r10, #0x1 */
/* @0x2a6238 .word 0xf8d40a01 */
/* @0x2a623a ldr.w r2, [r4, #0x30c] */
/* @0x2a623c addsmi r2, r7, #12, #6 */
/* @0x2a623e cmp r7, r2 */
/* @0x2a6240 bhi 0x2a6248 <png_check_IHDR+0x98> */
/* @0x2a6242 ldr r2, [pc, #0x110] */
/* @0x2a6244 cmp r7, r2 */
/* @0x2a6246 bls 0x2a6256 <png_check_IHDR+0xa6> */
/* @0x2a6248 ldr r1, [pc, #0x124] */
/* @0x2a624a mov r0, r4 */
/* @0x2a624c mov.w r10, #0x1 */
/* @0x2a6250 add r1, pc */
/* @0x2a6252 bl 0x2a6474 <png_warning> */
/* @0x2a6254 cdpne p9, #0x6, c15, c10, c15, #0x0 */
/* @0x2a6256 subs r2, r5, #0x1 */
/* @0x2a6258 cmp r2, #0x1 */
/* @0x2a625a bls 0x2a6276 <png_check_IHDR+0xc6> */
/* @0x2a625c cmp r5, #0x4 */
/* @0x2a625e beq 0x2a6276 <png_check_IHDR+0xc6> */
/* @0x2a6260 cmp r5, #0x8 */
/* @0x2a6262 beq 0x2a6276 <png_check_IHDR+0xc6> */
/* @0x2a6264 cmp r5, #0x10 */
/* @0x2a6266 beq 0x2a6276 <png_check_IHDR+0xc6> */
/* @0x2a6268 ldr r1, [pc, #0x108] */
/* @0x2a626a mov r0, r4 */
/* @0x2a626c mov.w r10, #0x1 */
/* @0x2a6270 add r1, pc */
/* @0x2a6272 bl 0x2a6474 <png_warning> */
/* @0x2a6274 .word 0xf026f8ff */
/* @0x2a6276 bic r7, r6, #0x4 */
/* @0x2a6278 svchs #0x10704 */
/* @0x2a627a cmp r7, #0x1 */
/* @0x2a627c beq 0x2a6282 <png_check_IHDR+0xd2> */
/* @0x2a627e cmp r6, #0x6 */
/* @0x2a6280 bls 0x2a6290 <png_check_IHDR+0xe0> */
/* @0x2a6282 ldr r1, [pc, #0xf4] */
/* @0x2a6284 mov r0, r4 */
/* @0x2a6286 mov.w r10, #0x1 */
/* @0x2a6288 ldrbtmi r0, [r9], #-2561 */
/* @0x2a628a add r1, pc */
/* @0x2a628c bl 0x2a6474 <png_warning> */
/* @0x2a6290 cmp r6, #0x3 */
/* @0x2a6292 bne 0x2a629a <png_check_IHDR+0xea> */
/* @0x2a6294 cmp r5, #0x8 */
/* @0x2a6296 bgt 0x2a62a6 <png_check_IHDR+0xf6> */
/* @0x2a6298 b 0x2a62b4 <png_check_IHDR+0x104> */
/* @0x2a629a cmp r7, #0x2 */
/* @0x2a629c beq 0x2a62a2 <png_check_IHDR+0xf2> */
/* @0x2a629e cmp r6, #0x4 */
/* @0x2a62a0 bne 0x2a62b4 <png_check_IHDR+0x104> */
/* @0x2a62a2 cmp r5, #0x7 */
/* @0x2a62a4 bgt 0x2a62b4 <png_check_IHDR+0x104> */
/* @0x2a62a6 ldr r1, [pc, #0xd4] */
/* @0x2a62a8 mov r0, r4 */
/* @0x2a62aa mov.w r10, #0x1 */
/* @0x2a62ac ldrbtmi r0, [r9], #-2561 */
/* @0x2a62ae add r1, pc */
/* @0x2a62b0 bl 0x2a6474 <png_warning> */
/* @0x2a62b4 cmp.w r11, #0x1 */
/* @0x2a62b8 ble 0x2a62c8 <png_check_IHDR+0x118> */
/* @0x2a62ba ldr r1, [pc, #0xc4] */
/* @0x2a62bc mov r0, r4 */
/* @0x2a62be mov.w r10, #0x1 */
/* @0x2a62c0 ldrbtmi r0, [r9], #-2561 */
/* @0x2a62c2 add r1, pc */
/* @0x2a62c4 bl 0x2a6474 <png_warning> */
/* @0x2a62c8 ldr r3, [sp, #0x4] */
/* @0x2a62ca cbz r3, 0x2a62da <png_check_IHDR+0x12a> */
/* @0x2a62cc ldr r1, [pc, #0xb4] */
/* @0x2a62ce mov r0, r4 */
/* @0x2a62d0 mov.w r10, #0x1 */
/* @0x2a62d4 add r1, pc */
/* @0x2a62d6 bl 0x2a6474 <png_warning> */
/* @0x2a62d8 .word 0xf8d4f8cd */
/* @0x2a62da ldr.w r2, [r4, #0x12c] */
/* @0x2a62dc ldrbeq r2, [r0], #300 */
/* @0x2a62de lsls r0, r2, #0x13 */
/* @0x2a62e0 bpl 0x2a62f2 <png_check_IHDR+0x142> */
/* @0x2a62e2 ldr.w r2, [r4, #0x2dc] */
/* @0x2a62e4 ldrdlt r2, r3, [r2, -r12]! */
/* @0x2a62e6 cbz r2, 0x2a62f2 <png_check_IHDR+0x142> */
/* @0x2a62e8 ldr r1, [pc, #0x9c] */
/* @0x2a62ea mov r0, r4 */
/* @0x2a62ec add r1, pc */
/* @0x2a62ee bl 0x2a6474 <png_warning> */
/* @0x2a62f0 .word 0xf1b9f8c1 */
/* @0x2a62f2 cmp.w r9, #0x0 */
/* @0x2a62f4 andsle r0, sp, r0, lsl #30 */
/* @0x2a62f6 beq 0x2a6334 <png_check_IHDR+0x184> */
/* @0x2a62f8 ldr.w r2, [r4, #0x2dc] */
/* @0x2a62fc lsls r1, r2, #0x1d */
/* @0x2a62fe bpl 0x2a6312 <png_check_IHDR+0x162> */
/* @0x2a6300 cmp.w r9, #0x40 */
/* @0x2a6304 bne 0x2a6312 <png_check_IHDR+0x162> */
/* @0x2a6306 ldr.w r2, [r4, #0x12c] */
/* @0x2a6308 ldrbeq r2, [r2], #300 */
/* @0x2a630a lsls r2, r2, #0x13 */
/* @0x2a630c bmi 0x2a6312 <png_check_IHDR+0x162> */
/* @0x2a630e cmp r7, #0x2 */
/* @0x2a6310 beq 0x2a6320 <png_check_IHDR+0x170> */
/* @0x2a6312 ldr r1, [pc, #0x78] */
/* @0x2a6314 mov r0, r4 */
/* @0x2a6316 mov.w r10, #0x1 */
/* @0x2a6318 ldrbtmi r0, [r9], #-2561 */
/* @0x2a631a add r1, pc */
/* @0x2a631c bl 0x2a6474 <png_warning> */
/* @0x2a6320 ldr.w r2, [r4, #0x12c] */
/* @0x2a6324 lsls r3, r2, #0x13 */
/* @0x2a6326 bpl 0x2a6334 <png_check_IHDR+0x184> */
/* @0x2a6328 ldr r1, [pc, #0x64] */
/* @0x2a632a mov r0, r4 */
/* @0x2a632c add r1, pc */
/* @0x2a632e bl 0x2a6474 <png_warning> */
/* @0x2a6330 and pc, r2, r1, lsr #17 */
/* @0x2a6332 b 0x2a633a <png_check_IHDR+0x18a> */
/* @0x2a6334 cmp.w r10, #0x0 */
/* @0x2a6338 beq 0x2a634a <png_check_IHDR+0x19a> */
/* @0x2a633a ldr r1, [pc, #0x58] */
/* @0x2a633c mov r0, r4 */
/* @0x2a633e add r1, pc */
/* @0x2a6340 add sp, #0xc */
/* @0x2a6342 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a6344 .word 0xf0004ff0 */
/* @0x2a6346 b.w 0x2a642c <png_error> */
/* @0x2a6348 andlt r11, r3, r1, ror r8 */
/* @0x2a634a add sp, #0xc */
/* @0x2a634c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a6350 .word 0xfff8 1fff */
/* @0x2a6354 rsbs r0, r0, #0 */
/* @0x2a6356 movs r7, r1 */
/* @0x2a6358 str r0, [r4, #0x2c] */
/* @0x2a635a movs r6, r1 */
/* @0x2a635c str r0, [r6, #0x2c] */
/* @0x2a635e movs r6, r1 */
/* @0x2a6360 str r4, [r5, #0x2c] */
/* @0x2a6362 movs r6, r1 */
/* @0x2a6364 str r7, [r7, #0x2c] */
/* @0x2a6366 movs r6, r1 */
/* @0x2a6368 str r0, [r3, #0x30] */
/* @0x2a636a movs r6, r1 */
/* @0x2a636c str r3, [r5, #0x30] */
/* @0x2a636e movs r6, r1 */
/* @0x2a6370 str r0, [r5, #0x30] */
/* @0x2a6372 movs r6, r1 */
/* @0x2a6374 str r0, [r6, #0x30] */
/* @0x2a6376 movs r6, r1 */
/* @0x2a6378 str r0, [r6, #0x30] */
/* @0x2a637a movs r6, r1 */
/* @0x2a637c str r7, [r4, #0x30] */
/* @0x2a637e movs r6, r1 */
/* @0x2a6380 str r4, [r0, #0x34] */
/* @0x2a6382 movs r6, r1 */
/* @0x2a6384 str r3, [r2, #0x34] */
/* @0x2a6386 movs r6, r1 */
/* @0x2a6388 str r6, [r3, #0x34] */
/* @0x2a638a movs r6, r1 */
/* @0x2a638c str r1, [r4, #0x34] */
/* @0x2a638e movs r6, r1 */
/* @0x2a6390 str r5, [r5, #0x34] */
/* @0x2a6392 movs r6, r1 */
/* @0x2a6394 str r1, [r7, #0x34] */
/* @0x2a6396 movs r6, r1 */

/* ── FUNC 0x2a6398 · anon_2a6398 · size=144 · insn=37 */
/* @0x2a6398 mvnsmi lr, #737280 */
/* @0x2a639c cdpmi p4, #0x2, c2, c2, c0, #0x0 */
/* @0x2a63a0 .word 0xf04f4623 */
/* @0x2a63a4 .word 0xf04f0c5b */
/* @0x2a63a8 ldrbtmi r0, [lr], #-2141 */
/* @0x2a63ac stmdbne r5, {r0, r10, r12, sp} */
/* @0x2a63b0 .word 0x51dff895 */
/* @0x2a63b4 strbeq pc, [r1, -r5, lsr #3] */
/* @0x2a63b8 stmdale r3, {r0, r3, r4, r5, r8, r9, r10, r11, sp} */
/* @0x2a63bc ldrbeq pc, [r11, -r5, lsr #3] */
/* @0x2a63c0 ldmdale r2, {r0, r2, r8, r9, r10, r11, sp} */
/* @0x2a63c4 ldmdbne r5, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a63c8 streq pc, [pc, #-0x5] */
/* @0x2a63cc .word 0xf80118cf */
/* @0x2a63d0 .word 0xf816c003 */
/* @0x2a63d4 ldclpl p0, c9, [r5, #-36]! */
/* @0x2a63d8 andls pc, r1, r7, lsl #17 */
/* @0x2a63dc stmdbeq r3, {r0, r1, r8, r12, sp, lr, pc} */
/* @0x2a63e0 movwlo r7, #0x40bd */
/* @0x2a63e4 andhi pc, r9, r1, lsl #16 */
/* @0x2a63e8 strbpl lr, [sp], #1 */
/* @0x2a63ec .word 0x2c043301 */
/* @0x2a63f0 ldmdblt r2, {r2, r3, r4, r6, r7, r8, r12, lr, pc} */
/* @0x2a63f4 pop {r1, r3, r6, r7, r10, r12, lr} */
/* @0x2a63f8 stmne r12, {r4, r5, r6, r7, r8, r9, pc} ^ */
/* @0x2a63fc strhs r2, [r0, #-0x3a]! */
/* @0x2a6400 ldcne p4, c5, [r8], {200} */
/* @0x2a6404 .word 0xf1037065 */
/* @0x2a6408 bne 0xff767914 <b2_toiTime+0xffffffffff00e470> */
/* @0x2a640c .word 0xf814181c */
/* @0x2a6410 .word 0xb12c4c02 */
/* @0x2a6414 stmdane r10, {r0, r12, sp} */
/* @0x2a6418 .word 0xf80242a8 */
/* @0x2a641c mvnsle r4, r1, lsl #24 */
/* @0x2a6420 strpl r2, [r11], #-768 */
/* @0x2a6424 mvnshi lr, #12386304 */
/* @0x2a6428 andeq r9, lr, lr, asr #10 */

/* ── FUNC 0x2a642c · png_error · size=72 · insn=33 */
/* @0x2a642c push {r4, r5, r6, lr} */
/* @0x2a642e mov r6, r1 */
/* @0x2a6430 mov r4, r0 */
/* @0x2a6432 cbz r0, 0x2a643c <png_error+0x10> */
/* @0x2a6434 ldr.w r3, [r0, #0x104] */
/* @0x2a6438 cbz r3, 0x2a643c <png_error+0x10> */
/* @0x2a643a blx r3 */
/* @0x2a643c ldr r0, [pc, #0x2c] */
/* @0x2a643e mov r2, r6 */
/* @0x2a6440 ldr r1, [pc, #0x2c] */
/* @0x2a6442 add r0, pc */
/* @0x2a6444 ldr r0, [r0] */
/* @0x2a6446 add.w r5, r0, #0xa8 */
/* @0x2a6448 ldrbtmi r0, [r9], #-1448 */
/* @0x2a644a add r1, pc */
/* @0x2a644c mov r0, r5 */
/* @0x2a644e blx 0xb68a4 <fprintf@plt> */
/* @0x2a6450 andhs lr, r10, r10, lsr #20 */
/* @0x2a6452 movs r0, #0xa */
/* @0x2a6454 mov r1, r5 */
/* @0x2a6456 blx 0xb68b0 <fputc@plt> */
/* @0x2a6458 .word 0xb12cea2c */
/* @0x2a645a cbz r4, 0x2a6468 <png_error+0x3c> */
/* @0x2a645c ldr.w r3, [r4, #0x100] */
/* @0x2a6460 cbz r3, 0x2a6468 <png_error+0x3c> */
/* @0x2a6462 mov r0, r4 */
/* @0x2a6464 movs r1, #0x1 */
/* @0x2a6466 blx r3 */
/* @0x2a6468 blx 0xb6c88 <abort@plt> */
/* @0x2a646c add sp, #0x18 */
/* @0x2a646e movs r4, r2 */
/* @0x2a6470 str r7, [r7, #0x24] */
/* @0x2a6472 movs r6, r1 */

/* ── FUNC 0x2a6474 · png_warning · size=88 · insn=41 */
/* @0x2a6474 push {r4, lr} */
/* @0x2a6476 mov r2, r1 */
/* @0x2a6478 cbz r0, 0x2a6490 <png_warning+0x1c> */
/* @0x2a647a ldrb r3, [r1] */
/* @0x2a647c cmp r3, #0x23 */
/* @0x2a647e bne 0x2a64b4 <png_warning+0x40> */
/* @0x2a6480 movs r3, #0x1 */
/* @0x2a6482 ldrb r1, [r2, r3] */
/* @0x2a6484 cmp r1, #0x20 */
/* @0x2a6486 beq 0x2a64b6 <png_warning+0x42> */
/* @0x2a6488 adds r3, #0x1 */
/* @0x2a648a cmp r3, #0xf */
/* @0x2a648c bne 0x2a6482 <png_warning+0xe> */
/* @0x2a648e b 0x2a64b6 <png_warning+0x42> */
/* @0x2a6490 mov r3, r0 */
/* @0x2a6492 ldr r1, [pc, #0x30] */
/* @0x2a6494 add r2, r3 */
/* @0x2a6496 add r1, pc */
/* @0x2a6498 ldr r1, [r1] */
/* @0x2a649a add.w r4, r1, #0xa8 */
/* @0x2a649c stmdbmi r10, {r3, r5, r7, r10} */
/* @0x2a649e ldr r1, [pc, #0x28] */
/* @0x2a64a0 mov r0, r4 */
/* @0x2a64a2 add r1, pc */
/* @0x2a64a4 blx 0xb68a4 <fprintf@plt> */
/* @0x2a64a8 mov r1, r4 */
/* @0x2a64aa movs r0, #0xa */
/* @0x2a64ac pop.w {r4, lr} */
/* @0x2a64b0 b.w 0x31baec <__udivdi3+0x454> */
/* @0x2a64b4 movs r3, #0x0 */
/* @0x2a64b6 ldr.w r4, [r0, #0x108] */
/* @0x2a64b8 .word 0x2c004108 */
/* @0x2a64ba cmp r4, #0x0 */
/* @0x2a64bc beq 0x2a6492 <png_warning+0x1e> */
/* @0x2a64be adds r1, r2, r3 */
/* @0x2a64c0 blx r4 */
/* @0x2a64c2 pop {r4, pc} */
/* @0x2a64c4 add r7, sp, #0x2c8 */
/* @0x2a64c6 movs r4, r2 */
/* @0x2a64c8 str r0, [r7, #0x20] */
/* @0x2a64ca movs r6, r1 */

/* ── FUNC 0x2a64cc · png_chunk_error · size=56 · insn=25 */
/* @0x2a64cc ldr r3, [pc, #0x30] */
/* @0x2a64ce mov r2, r1 */
/* @0x2a64d0 push {r4, r5, r6, lr} */
/* @0x2a64d2 add r3, pc */
/* @0x2a64d4 ldr r3, [r3] */
/* @0x2a64d6 sub sp, #0x58 */
/* @0x2a64d8 mov r6, r0 */
/* @0x2a64da ldr r4, [r3] */
/* @0x2a64dc mov r5, r3 */
/* @0x2a64de str r4, [sp, #0x54] */
/* @0x2a64e0 cbz r0, 0x2a64ec <png_chunk_error+0x20> */
/* @0x2a64e2 mov r1, sp */
/* @0x2a64e4 bl 0x2a6398 <png_check_IHDR+0x1e8> */
/* @0x2a64e8 mov r0, r6 */
/* @0x2a64ea mov r1, sp */
/* @0x2a64ec bl 0x2a642c <png_error> */
/* @0x2a64f0 ldr r2, [sp, #0x54] */
/* @0x2a64f2 ldr r3, [r5] */
/* @0x2a64f4 cmp r2, r3 */
/* @0x2a64f6 beq 0x2a64fc <png_chunk_error+0x30> */
/* @0x2a64f8 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a64fc add sp, #0x58 */
/* @0x2a64fe pop {r4, r5, r6, pc} */
/* @0x2a6500 strb r2, [r0, #0x12] */
/* @0x2a6502 movs r4, r2 */

/* ── FUNC 0x2a6504 · png_chunk_warning · size=56 · insn=25 */
/* @0x2a6504 ldr r3, [pc, #0x30] */
/* @0x2a6506 mov r2, r1 */
/* @0x2a6508 push {r4, r5, r6, lr} */
/* @0x2a650a add r3, pc */
/* @0x2a650c ldr r3, [r3] */
/* @0x2a650e sub sp, #0x58 */
/* @0x2a6510 mov r6, r0 */
/* @0x2a6512 ldr r4, [r3] */
/* @0x2a6514 mov r5, r3 */
/* @0x2a6516 str r4, [sp, #0x54] */
/* @0x2a6518 cbz r0, 0x2a6524 <png_chunk_warning+0x20> */
/* @0x2a651a mov r1, sp */
/* @0x2a651c bl 0x2a6398 <png_check_IHDR+0x1e8> */
/* @0x2a6520 mov r0, r6 */
/* @0x2a6522 mov r1, sp */
/* @0x2a6524 bl 0x2a6474 <png_warning> */
/* @0x2a6528 ldr r2, [sp, #0x54] */
/* @0x2a652a ldr r3, [r5] */
/* @0x2a652c cmp r2, r3 */
/* @0x2a652e beq 0x2a6534 <png_chunk_warning+0x30> */
/* @0x2a6530 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a6534 add sp, #0x58 */
/* @0x2a6536 pop {r4, r5, r6, pc} */
/* @0x2a6538 strb r2, [r1, #0x11] */
/* @0x2a653a movs r4, r2 */

/* ── FUNC 0x2a653c · png_set_longjmp_fn · size=18 · insn=8 */
/* @0x2a653c cbz r0, 0x2a654c <png_set_longjmp_fn+0x10> */
/* @0x2a653e cmp.w r2, #0x100 */
/* @0x2a6540 smlabble r2, r0, pc, r7 */
/* @0x2a6542 bne 0x2a654a <png_set_longjmp_fn+0xe> */
/* @0x2a6544 str.w r1, [r0, #0x100] */
/* @0x2a6548 bx lr */
/* @0x2a654a movs r0, #0x0 */
/* @0x2a654c bx lr */

/* ── FUNC 0x2a654e · png_set_error_fn · size=16 · insn=8 */
/* @0x2a654e cbz r0, 0x2a655c <png_set_error_fn+0xe> */
/* @0x2a6550 str.w r1, [r0, #0x10c] */
/* @0x2a6552 .word 0xf8c0110c */
/* @0x2a6554 str.w r2, [r0, #0x104] */
/* @0x2a6556 .word 0xf8c02104 */
/* @0x2a6558 str.w r3, [r0, #0x108] */
/* @0x2a655a ldrbmi r3, [r0, -r8, lsl #2]! */
/* @0x2a655c bx lr */

/* ── FUNC 0x2a655e · png_get_error_ptr · size=8 · insn=4 */
/* @0x2a655e cbz r0, 0x2a6564 <png_get_error_ptr+0x6> */
/* @0x2a6560 ldr.w r0, [r0, #0x10c] */
/* @0x2a6562 ldrbmi r0, [r0, -r12, lsl #2]! */
/* @0x2a6564 bx lr */

/* ── FUNC 0x2a6566 · png_get_valid · size=14 · insn=7 */
/* @0x2a6566 cbz r0, 0x2a6572 <png_get_valid+0xc> */
/* @0x2a6568 cbz r1, 0x2a6570 <png_get_valid+0xa> */
/* @0x2a656a ldr r0, [r1, #0x8] */
/* @0x2a656c ands r0, r2 */
/* @0x2a656e bx lr */
/* @0x2a6570 mov r0, r1 */
/* @0x2a6572 bx lr */

/* ── FUNC 0x2a6574 · png_get_rowbytes · size=12 · insn=6 */
/* @0x2a6574 cbz r0, 0x2a657e <png_get_rowbytes+0xa> */
/* @0x2a6576 cbz r1, 0x2a657c <png_get_rowbytes+0x8> */
/* @0x2a6578 ldr r0, [r1, #0xc] */
/* @0x2a657a bx lr */
/* @0x2a657c mov r0, r1 */
/* @0x2a657e bx lr */

/* ── FUNC 0x2a6580 · png_get_rows · size=14 · insn=6 */
/* @0x2a6580 cbz r0, 0x2a658c <png_get_rows+0xc> */
/* @0x2a6582 cbz r1, 0x2a658a <png_get_rows+0xa> */
/* @0x2a6584 ldr.w r0, [r1, #0xf8] */
/* @0x2a6588 bx lr */
/* @0x2a658a mov r0, r1 */
/* @0x2a658c bx lr */

/* ── FUNC 0x2a658e · png_get_image_width · size=12 · insn=6 */
/* @0x2a658e cbz r0, 0x2a6598 <png_get_image_width+0xa> */
/* @0x2a6590 cbz r1, 0x2a6596 <png_get_image_width+0x8> */
/* @0x2a6592 ldr r0, [r1] */
/* @0x2a6594 bx lr */
/* @0x2a6596 mov r0, r1 */
/* @0x2a6598 bx lr */
