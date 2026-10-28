/* libyoyo.so 覆盖卡组 0254
 * 函数 0x2a6af2..0x2a7488，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a6af2 · png_get_sBIT · size=30 · insn=15 */
/* @0x2a6af2 cbz r0, 0x2a6b0e <png_get_sBIT+0x1c> */
/* @0x2a6af4 cbz r1, 0x2a6b08 <png_get_sBIT+0x16> */
/* @0x2a6af6 ldr r0, [r1, #0x8] */
/* @0x2a6af8 ands r0, r0, #0x2 */
/* @0x2a6afa andle r0, r7, r2 */
/* @0x2a6afc beq 0x2a6b0e <png_get_sBIT+0x1c> */
/* @0x2a6afe cbz r2, 0x2a6b0c <png_get_sBIT+0x1a> */
/* @0x2a6b00 adds r1, #0x44 */
/* @0x2a6b02 movs r0, #0x2 */
/* @0x2a6b04 str r1, [r2] */
/* @0x2a6b06 bx lr */
/* @0x2a6b08 mov r0, r1 */
/* @0x2a6b0a bx lr */
/* @0x2a6b0c mov r0, r2 */
/* @0x2a6b0e bx lr */

/* ── FUNC 0x2a6b10 · png_get_text · size=38 · insn=19 */
/* @0x2a6b10 cbz r0, 0x2a6b2a <png_get_text+0x1a> */
/* @0x2a6b12 cbz r1, 0x2a6b2a <png_get_text+0x1a> */
/* @0x2a6b14 ldr r0, [r1, #0x30] */
/* @0x2a6b16 cmp r0, #0x0 */
/* @0x2a6b18 ble 0x2a6b2a <png_get_text+0x1a> */
/* @0x2a6b1a cbz r2, 0x2a6b20 <png_get_text+0x10> */
/* @0x2a6b1c ldr r0, [r1, #0x38] */
/* @0x2a6b1e str r0, [r2] */
/* @0x2a6b20 cbz r3, 0x2a6b26 <png_get_text+0x16> */
/* @0x2a6b22 ldr r2, [r1, #0x30] */
/* @0x2a6b24 str r2, [r3] */
/* @0x2a6b26 ldr r0, [r1, #0x30] */
/* @0x2a6b28 bx lr */
/* @0x2a6b2a movs r0, #0x0 */
/* @0x2a6b2c cbz r3, 0x2a6b32 <png_get_text+0x22> */
/* @0x2a6b2e str r0, [r3] */
/* @0x2a6b30 bx lr */
/* @0x2a6b32 mov r0, r3 */
/* @0x2a6b34 bx lr */

/* ── FUNC 0x2a6b36 · png_get_tIME · size=32 · insn=15 */
/* @0x2a6b36 cbz r0, 0x2a6b54 <png_get_tIME+0x1e> */
/* @0x2a6b38 cbz r1, 0x2a6b4e <png_get_tIME+0x18> */
/* @0x2a6b3a ldr r0, [r1, #0x8] */
/* @0x2a6b3c ands r0, r0, #0x200 */
/* @0x2a6b3e andle r7, r8, r0 */
/* @0x2a6b40 beq 0x2a6b54 <png_get_tIME+0x1e> */
/* @0x2a6b42 cbz r2, 0x2a6b52 <png_get_tIME+0x1c> */
/* @0x2a6b44 adds r1, #0x3c */
/* @0x2a6b46 mov.w r0, #0x200 */
/* @0x2a6b4a str r1, [r2] */
/* @0x2a6b4c bx lr */
/* @0x2a6b4e mov r0, r1 */
/* @0x2a6b50 bx lr */
/* @0x2a6b52 mov r0, r2 */
/* @0x2a6b54 bx lr */

/* ── FUNC 0x2a6b56 · png_get_tRNS · size=78 · insn=38 */
/* @0x2a6b56 push {r4, lr} */
/* @0x2a6b58 ldr r4, [sp, #0x8] */
/* @0x2a6b5a cbz r0, 0x2a6ba2 <png_get_tRNS+0x4c> */
/* @0x2a6b5c cbz r1, 0x2a6ba0 <png_get_tRNS+0x4a> */
/* @0x2a6b5e ldr r0, [r1, #0x8] */
/* @0x2a6b60 ands r0, r0, #0x10 */
/* @0x2a6b62 andsle r0, sp, r0, lsl r0 */
/* @0x2a6b64 beq 0x2a6ba2 <png_get_tRNS+0x4c> */
/* @0x2a6b66 ldrb r0, [r1, #0x19] */
/* @0x2a6b68 cmp r0, #0x3 */
/* @0x2a6b6a bne 0x2a6b82 <png_get_tRNS+0x2c> */
/* @0x2a6b6c cbz r2, 0x2a6b76 <png_get_tRNS+0x20> */
/* @0x2a6b6e ldr r0, [r1, #0x4c] */
/* @0x2a6b70 str r0, [r2] */
/* @0x2a6b72 movs r0, #0x10 */
/* @0x2a6b74 b 0x2a6b78 <png_get_tRNS+0x22> */
/* @0x2a6b76 mov r0, r2 */
/* @0x2a6b78 cbz r4, 0x2a6b96 <png_get_tRNS+0x40> */
/* @0x2a6b7a add.w r2, r1, #0x50 */
/* @0x2a6b7e str r2, [r4] */
/* @0x2a6b80 b 0x2a6b96 <png_get_tRNS+0x40> */
/* @0x2a6b82 cbz r4, 0x2a6b8e <png_get_tRNS+0x38> */
/* @0x2a6b84 add.w r0, r1, #0x50 */
/* @0x2a6b86 eorvs r0, r0, r0, asr r0 */
/* @0x2a6b88 str r0, [r4] */
/* @0x2a6b8a movs r0, #0x10 */
/* @0x2a6b8c b 0x2a6b90 <png_get_tRNS+0x3a> */
/* @0x2a6b8e mov r0, r4 */
/* @0x2a6b90 cbz r2, 0x2a6b96 <png_get_tRNS+0x40> */
/* @0x2a6b92 movs r4, #0x0 */
/* @0x2a6b94 str r4, [r2] */
/* @0x2a6b96 cbz r3, 0x2a6ba2 <png_get_tRNS+0x4c> */
/* @0x2a6b98 ldrh r2, [r1, #0x16] */
/* @0x2a6b9a movs r0, #0x10 */
/* @0x2a6b9c str r2, [r3] */
/* @0x2a6b9e pop {r4, pc} */
/* @0x2a6ba0 mov r0, r1 */
/* @0x2a6ba2 pop {r4, pc} */

/* ── FUNC 0x2a6ba4 · png_get_unknown_chunks · size=26 · insn=12 */
/* @0x2a6ba4 cbz r0, 0x2a6bbc <png_get_unknown_chunks+0x18> */
/* @0x2a6ba6 cbz r1, 0x2a6bb6 <png_get_unknown_chunks+0x12> */
/* @0x2a6ba8 cbz r2, 0x2a6bba <png_get_unknown_chunks+0x16> */
/* @0x2a6baa ldr.w r3, [r1, #0xbc] */
/* @0x2a6bac ldrhvs r3, [r3], -r12 */
/* @0x2a6bae str r3, [r2] */
/* @0x2a6bb0 ldr.w r0, [r1, #0xc0] */
/* @0x2a6bb4 bx lr */
/* @0x2a6bb6 mov r0, r1 */
/* @0x2a6bb8 bx lr */
/* @0x2a6bba mov r0, r2 */
/* @0x2a6bbc bx lr */

/* ── FUNC 0x2a6bbe · png_get_rgb_to_gray_status · size=8 · insn=4 */
/* @0x2a6bbe cbz r0, 0x2a6bc4 <png_get_rgb_to_gray_status+0x6> */
/* @0x2a6bc0 ldrb.w r0, [r0, #0x2d4] */
/* @0x2a6bc2 .word 0x477002d4 */
/* @0x2a6bc4 bx lr */

/* ── FUNC 0x2a6bc6 · png_get_user_chunk_ptr · size=8 · insn=4 */
/* @0x2a6bc6 cbz r0, 0x2a6bcc <png_get_user_chunk_ptr+0x6> */
/* @0x2a6bc8 ldr.w r0, [r0, #0x2c4] */
/* @0x2a6bca ldrbmi r0, [r0, -r4, asr #5]! */
/* @0x2a6bcc bx lr */

/* ── FUNC 0x2a6bce · png_get_compression_buffer_size · size=8 · insn=4 */
/* @0x2a6bce cbz r0, 0x2a6bd4 <png_get_compression_buffer_size+0x6> */
/* @0x2a6bd0 ldr.w r0, [r0, #0x174] */
/* @0x2a6bd2 .word 0x47700174 */
/* @0x2a6bd4 bx lr */

/* ── FUNC 0x2a6bd6 · png_get_user_width_max · size=8 · insn=4 */
/* @0x2a6bd6 cbz r0, 0x2a6bdc <png_get_user_width_max+0x6> */
/* @0x2a6bd8 ldr.w r0, [r0, #0x308] */
/* @0x2a6bda ldrbmi r0, [r0, -r8, lsl #6]! */
/* @0x2a6bdc bx lr */

/* ── FUNC 0x2a6bde · png_get_user_height_max · size=8 · insn=4 */
/* @0x2a6bde cbz r0, 0x2a6be4 <png_get_user_height_max+0x6> */
/* @0x2a6be0 ldr.w r0, [r0, #0x30c] */
/* @0x2a6be2 ldrbmi r0, [r0, -r12, lsl #6]! */
/* @0x2a6be4 bx lr */

/* ── FUNC 0x2a6be6 · png_get_chunk_cache_max · size=8 · insn=4 */
/* @0x2a6be6 cbz r0, 0x2a6bec <png_get_chunk_cache_max+0x6> */
/* @0x2a6be8 ldr.w r0, [r0, #0x310] */
/* @0x2a6bea .word 0x47700310 */
/* @0x2a6bec bx lr */

/* ── FUNC 0x2a6bee · png_get_chunk_malloc_max · size=8 · insn=4 */
/* @0x2a6bee cbz r0, 0x2a6bf4 <png_get_chunk_malloc_max+0x6> */
/* @0x2a6bf0 ldr.w r0, [r0, #0x1a0] */
/* @0x2a6bf2 ldrbmi r0, [r0, -r0, lsr #3]! */
/* @0x2a6bf4 bx lr */

/* ── FUNC 0x2a6bf6 · png_get_io_state · size=6 · insn=2 */
/* @0x2a6bf6 ldr.w r0, [r0, #0x334] */
/* @0x2a6bfa bx lr */

/* ── FUNC 0x2a6bfc · png_get_io_chunk_name · size=6 · insn=2 */
/* @0x2a6bfc add.w r0, r0, #0x1e0 */
/* @0x2a6c00 bx lr */

/* ── FUNC 0x2a6c02 · png_create_struct_2 · size=84 · insn=38 */
/* @0x2a6c02 cmp r0, #0x2 */
/* @0x2a6c04 push {r4, r5, r6, lr} */
/* @0x2a6c06 mov r5, r1 */
/* @0x2a6c08 sub.w sp, sp, #0x338 */
/* @0x2a6c0a andle r7, r4, lr, asr #26 */
/* @0x2a6c0c beq 0x2a6c18 <png_create_struct_2+0x16> */
/* @0x2a6c0e cmp r0, #0x1 */
/* @0x2a6c10 bne 0x2a6c4a <png_create_struct_2+0x48> */
/* @0x2a6c12 mov.w r4, #0x338 */
/* @0x2a6c16 b 0x2a6c1c <png_create_struct_2+0x1a> */
/* @0x2a6c18 mov.w r4, #0x120 */
/* @0x2a6c1a .word 0xb1557490 */
/* @0x2a6c1c cbz r5, 0x2a6c34 <png_create_struct_2+0x32> */
/* @0x2a6c1e str r2, [sp, #0x2e8] */
/* @0x2a6c20 mov r0, sp */
/* @0x2a6c22 mov r1, r4 */
/* @0x2a6c24 blx r5 */
/* @0x2a6c26 mov r5, r0 */
/* @0x2a6c28 cbz r0, 0x2a6c4e <png_create_struct_2+0x4c> */
/* @0x2a6c2a movs r1, #0x0 */
/* @0x2a6c2c mov r2, r4 */
/* @0x2a6c2e blx 0xb65b0 <memset@plt> */
/* @0x2a6c32 b 0x2a6c4e <png_create_struct_2+0x4c> */
/* @0x2a6c34 mov r0, r4 */
/* @0x2a6c36 blx 0xb6544 <malloc@plt> */
/* @0x2a6c3a mov r6, r0 */
/* @0x2a6c3c cbz r0, 0x2a6c4e <png_create_struct_2+0x4c> */
/* @0x2a6c3e mov r1, r5 */
/* @0x2a6c40 mov r2, r4 */
/* @0x2a6c42 blx 0xb65b0 <memset@plt> */
/* @0x2a6c46 mov r0, r6 */
/* @0x2a6c48 b 0x2a6c50 <png_create_struct_2+0x4e> */
/* @0x2a6c4a movs r0, #0x0 */
/* @0x2a6c4c b 0x2a6c50 <png_create_struct_2+0x4e> */
/* @0x2a6c4e mov r0, r5 */
/* @0x2a6c50 add.w sp, sp, #0x338 */
/* @0x2a6c52 ldcllt p13, c7, [r0, #-312]! */
/* @0x2a6c54 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a6c56 · png_create_struct · size=8 · insn=3 */
/* @0x2a6c56 movs r1, #0x0 */
/* @0x2a6c58 mov r2, r1 */
/* @0x2a6c5a b.w 0x2a6c02 <png_create_struct_2> */

/* ── FUNC 0x2a6c5e · png_destroy_struct_2 · size=42 · insn=20 */
/* @0x2a6c5e push {lr} */
/* @0x2a6c60 mov r3, r1 */
/* @0x2a6c62 sub.w sp, sp, #0x33c */
/* @0x2a6c66 mov r1, r0 */
/* @0x2a6c68 cbz r0, 0x2a6c80 <png_destroy_struct_2+0x22> */
/* @0x2a6c6a cbz r3, 0x2a6c74 <png_destroy_struct_2+0x16> */
/* @0x2a6c6c mov r0, sp */
/* @0x2a6c6e str r2, [sp, #0x2e8] */
/* @0x2a6c70 blx r3 */
/* @0x2a6c72 b 0x2a6c80 <png_destroy_struct_2+0x22> */
/* @0x2a6c74 add.w sp, sp, #0x33c */
/* @0x2a6c76 .word 0xf85d7d4f */
/* @0x2a6c78 ldr lr, [sp], #4 */
/* @0x2a6c7a .word 0xf074eb04 */
/* @0x2a6c7c b.w 0x31babc <__udivdi3+0x424> */
/* @0x2a6c7e .word 0xf50dbf1e */
/* @0x2a6c80 add.w sp, sp, #0x33c */
/* @0x2a6c82 .word 0xf85d7d4f */
/* @0x2a6c84 ldr pc, [sp], #4 */
/* @0x2a6c86 .word 0x2100fb04 */

/* ── FUNC 0x2a6c88 · png_destroy_struct · size=8 · insn=3 */
/* @0x2a6c88 movs r1, #0x0 */
/* @0x2a6c8a mov r2, r1 */
/* @0x2a6c8c b.w 0x2a6c5e <png_destroy_struct_2> */

/* ── FUNC 0x2a6c90 · png_malloc_default · size=14 · insn=7 */
/* @0x2a6c90 cbz r0, 0x2a6c9a <png_malloc_default+0xa> */
/* @0x2a6c92 cbz r1, 0x2a6c9a <png_malloc_default+0xa> */
/* @0x2a6c94 mov r0, r1 */
/* @0x2a6c96 b.w 0x31bafc <__udivdi3+0x464> */
/* @0x2a6c98 andhs r11, r0, r1, lsr pc */
/* @0x2a6c9a movs r0, #0x0 */
/* @0x2a6c9c bx lr */

/* ── FUNC 0x2a6ca0 · png_malloc · size=56 · insn=26 */
/* @0x2a6ca0 push {r3, r4, r5, lr} */
/* @0x2a6ca2 mov r5, r0 */
/* @0x2a6ca4 cbnz r0, 0x2a6caa <png_malloc+0xa> */
/* @0x2a6ca6 movs r0, #0x0 */
/* @0x2a6ca8 pop {r3, r4, r5, pc} */
/* @0x2a6caa cmp r1, #0x0 */
/* @0x2a6cac beq 0x2a6ca6 <png_malloc+0x6> */
/* @0x2a6cae ldr.w r3, [r0, #0x2ec] */
/* @0x2a6cb0 smlattlt r11, r12, r2, r3 */
/* @0x2a6cb2 cbz r3, 0x2a6cb8 <png_malloc+0x18> */
/* @0x2a6cb4 blx r3 */
/* @0x2a6cb6 b 0x2a6cbc <png_malloc+0x1c> */
/* @0x2a6cb8 bl 0x2a6c90 <png_malloc_default> */
/* @0x2a6cbc cbnz r0, 0x2a6cd2 <png_malloc+0x32> */
/* @0x2a6cbe ldr.w r3, [r5, #0x130] */
/* @0x2a6cc0 sbcseq r3, r11, #48, #2 */
/* @0x2a6cc2 lsls r3, r3, #0xb */
/* @0x2a6cc4 bmi 0x2a6ca6 <png_malloc+0x6> */
/* @0x2a6cc6 ldr r1, [pc, #0xc] */
/* @0x2a6cc8 mov r0, r5 */
/* @0x2a6cca add r1, pc */
/* @0x2a6ccc bl 0x2a642c <png_error> */
/* @0x2a6cd0 b 0x2a6ca6 <png_malloc+0x6> */
/* @0x2a6cd2 pop {r3, r4, r5, pc} */
/* @0x2a6cd4 ldrh r3, [r4, r0] */
/* @0x2a6cd6 movs r6, r1 */

/* ── FUNC 0x2a6cd8 · png_calloc · size=24 · insn=10 */
/* @0x2a6cd8 push {r3, r4, r5, lr} */
/* @0x2a6cda mov r5, r1 */
/* @0x2a6cdc bl 0x2a6ca0 <png_malloc> */
/* @0x2a6ce0 mov r4, r0 */
/* @0x2a6ce2 cbz r0, 0x2a6cec <png_calloc+0x14> */
/* @0x2a6ce4 movs r1, #0x0 */
/* @0x2a6ce6 mov r2, r5 */
/* @0x2a6ce8 blx 0xb65b0 <memset@plt> */
/* @0x2a6cec mov r0, r4 */
/* @0x2a6cee pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a6cf0 · png_free_default · size=12 · insn=6 */
/* @0x2a6cf0 cbz r0, 0x2a6cfa <png_free_default+0xa> */
/* @0x2a6cf2 cbz r1, 0x2a6cfa <png_free_default+0xa> */
/* @0x2a6cf4 mov r0, r1 */
/* @0x2a6cf6 b.w 0x31babc <__udivdi3+0x424> */
/* @0x2a6cf8 ldrbmi r11, [r0, -r1, ror #29]! */
/* @0x2a6cfa bx lr */

/* ── FUNC 0x2a6cfc · png_free · size=26 · insn=11 */
/* @0x2a6cfc push {r3, lr} */
/* @0x2a6cfe cbz r0, 0x2a6d14 <png_free+0x18> */
/* @0x2a6d00 cbz r1, 0x2a6d14 <png_free+0x18> */
/* @0x2a6d02 ldr.w r3, [r0, #0x2f0] */
/* @0x2a6d04 strdlt r3, r4, [r11, -r0] */
/* @0x2a6d06 cbz r3, 0x2a6d0c <png_free+0x10> */
/* @0x2a6d08 blx r3 */
/* @0x2a6d0a pop {r3, pc} */
/* @0x2a6d0c pop.w {r3, lr} */
/* @0x2a6d10 b.w 0x2a6cf0 <png_free_default> */
/* @0x2a6d14 pop {r3, pc} */

/* ── FUNC 0x2a6d16 · png_malloc_warn · size=30 · insn=15 */
/* @0x2a6d16 push {r3, r4, r5, lr} */
/* @0x2a6d18 mov r4, r0 */
/* @0x2a6d1a cbz r0, 0x2a6d32 <png_malloc_warn+0x1c> */
/* @0x2a6d1c ldr.w r5, [r0, #0x130] */
/* @0x2a6d1e vst4.8 {d21, d23, d25, d27}, [r5:256], r0 */
/* @0x2a6d20 orr r3, r5, #0x100000 */
/* @0x2a6d22 .word 0xf8c01380 */
/* @0x2a6d24 str.w r3, [r0, #0x130] */
/* @0x2a6d26 .word 0xf7ff3130 */
/* @0x2a6d28 bl 0x2a6ca0 <png_malloc> */
/* @0x2a6d2a .word 0xf8c4ffba */
/* @0x2a6d2c str.w r5, [r4, #0x130] */
/* @0x2a6d2e ldclt p1, c5, [r8, #-192]! */
/* @0x2a6d30 pop {r3, r4, r5, pc} */
/* @0x2a6d32 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a6d34 · png_set_mem_fn · size=16 · insn=8 */
/* @0x2a6d34 cbz r0, 0x2a6d42 <png_set_mem_fn+0xe> */
/* @0x2a6d36 str.w r1, [r0, #0x2e8] */
/* @0x2a6d38 .word 0xf8c012e8 */
/* @0x2a6d3a str.w r2, [r0, #0x2ec] */
/* @0x2a6d3c .word 0xf8c022ec */
/* @0x2a6d3e str.w r3, [r0, #0x2f0] */
/* @0x2a6d40 .word 0x477032f0 */
/* @0x2a6d42 bx lr */

/* ── FUNC 0x2a6d44 · png_get_mem_ptr · size=8 · insn=4 */
/* @0x2a6d44 cbz r0, 0x2a6d4a <png_get_mem_ptr+0x6> */
/* @0x2a6d46 ldr.w r0, [r0, #0x2e8] */
/* @0x2a6d48 ldrbmi r0, [r0, -r8, ror #5]! */
/* @0x2a6d4a bx lr */

/* ── FUNC 0x2a6d4c · png_create_read_struct_2 · size=656 · insn=297 */
/* @0x2a6d4c push {r4, r5, r6, r7, lr} */
/* @0x2a6d4e sub sp, #0x84 */
/* @0x2a6d50 str r0, [sp] */
/* @0x2a6d52 str r3, [sp, #0x1c] */
/* @0x2a6d54 ldr r0, [sp, #0x98] */
/* @0x2a6d56 ldr r3, [pc, #0x250] */
/* @0x2a6d58 str r1, [sp, #0x14] */
/* @0x2a6d5a add r3, pc */
/* @0x2a6d5c str r3, [sp, #0x4] */
/* @0x2a6d5e str r0, [sp, #0x8] */
/* @0x2a6d60 str r2, [sp, #0x18] */
/* @0x2a6d62 ldr r0, [sp, #0x4] */
/* @0x2a6d64 ldr r2, [sp, #0xa0] */
/* @0x2a6d66 ldr r1, [sp, #0x9c] */
/* @0x2a6d68 ldr r3, [pc, #0x240] */
/* @0x2a6d6a str r2, [sp, #0x10] */
/* @0x2a6d6c str r1, [sp, #0xc] */
/* @0x2a6d6e ldr r3, [r0, r3] */
/* @0x2a6d70 movs r0, #0x1 */
/* @0x2a6d72 ldr r2, [sp, #0x8] */
/* @0x2a6d74 ldr r3, [r3] */
/* @0x2a6d76 str r3, [sp, #0x7c] */
/* @0x2a6d78 movs r3, #0x0 */
/* @0x2a6d7a str r3, [sp, #0x28] */
/* @0x2a6d7c bl 0x2a6c02 <png_create_struct_2> */
/* @0x2a6d80 str r0, [sp, #0x24] */
/* @0x2a6d82 ldr r0, [sp, #0x24] */
/* @0x2a6d84 cmp r0, #0x0 */
/* @0x2a6d86 beq.w 0x2a6f8a <png_create_read_struct_2+0x23e> */
/* @0x2a6d88 bls 0x507190 <SrcVerts+0x641d4> */
/* @0x2a6d8a ldr r2, [sp, #0x24] */
/* @0x2a6d8c ldr r3, [pc, #0x210] */
/* @0x2a6d8e str.w r3, [r2, #0x308] */
/* @0x2a6d90 bls 0x4f39b8 <SrcVerts+0x509fc> */
/* @0x2a6d92 ldr r2, [sp, #0x24] */
/* @0x2a6d94 str.w r3, [r2, #0x30c] */
/* @0x2a6d98 movw r2, #0x7fff */
/* @0x2a6d9c ldr r3, [sp, #0x24] */
/* @0x2a6d9e str.w r2, [r3, #0x310] */
/* @0x2a6da0 blls 0x4ef9e8 <SrcVerts+0x4ca2c> */
/* @0x2a6da2 ldr r3, [sp, #0x24] */
/* @0x2a6da4 ldr r2, [pc, #0x1fc] */
/* @0x2a6da6 ldr r0, [sp, #0x24] */
/* @0x2a6da8 str.w r2, [r3, #0x1a0] */
/* @0x2a6dac ldr r2, [sp, #0x4] */
/* @0x2a6dae ldr r3, [pc, #0x200] */
/* @0x2a6db0 ldr r1, [r2, r3] */
/* @0x2a6db2 mov.w r2, #0x100 */
/* @0x2a6db4 .word 0xf7ff7280 */
/* @0x2a6db6 bl 0x2a653c <png_set_longjmp_fn> */
/* @0x2a6db8 .word 0xf60ffbc1 */
/* @0x2a6dba blx 0xb6904 <setjmp@plt> */
/* @0x2a6dbc strmi lr, [r4], -r4, lsr #27 */
/* @0x2a6dbe mov r4, r0 */
/* @0x2a6dc0 cbz r0, 0x2a6dc6 <png_create_read_struct_2+0x7a> */
/* @0x2a6dc2 blx 0xb6c88 <abort@plt> */
/* @0x2a6dc4 stmdbge r2, {r1, r5, r6, r8, r9, r10, r11, sp, lr, pc} */
/* @0x2a6dc6 add r1, sp, #0x8 */
/* @0x2a6dc8 ldr r0, [sp, #0x24] */
/* @0x2a6dca ldm r1, {r1, r2, r3} */
/* @0x2a6dcc bl 0x2a6d34 <png_set_mem_fn> */
/* @0x2a6dd0 add r1, sp, #0x14 */
/* @0x2a6dd2 ldr r0, [sp, #0x24] */
/* @0x2a6dd4 ldm r1, {r1, r2, r3} */
/* @0x2a6dd6 bl 0x2a654e <png_set_error_fn> */
/* @0x2a6dd8 blls 0x2e5cc8 <FT_Get_CMap_Format+0x8> */
/* @0x2a6dda ldr r3, [sp] */
/* @0x2a6ddc cbz r3, 0x2a6e1a <png_create_read_struct_2+0xce> */
/* @0x2a6dde ldr r5, [pc, #0x1d4] */
/* @0x2a6de0 mov.w r3, #0xffffffff */
/* @0x2a6de4 movs r6, #0x1 */
/* @0x2a6de6 add r5, pc */
/* @0x2a6de8 ldr r0, [sp] */
/* @0x2a6dea adds r3, #0x1 */
/* @0x2a6dec ldrb r2, [r3, r5] */
/* @0x2a6dee mov r7, r3 */
/* @0x2a6df0 ldrb r1, [r0, r3] */
/* @0x2a6df2 cmp r1, r2 */
/* @0x2a6df4 beq 0x2a6e04 <png_create_read_struct_2+0xb8> */
/* @0x2a6df6 ldr r1, [sp, #0x24] */
/* @0x2a6df8 ldr.w r0, [r1, #0x130] */
/* @0x2a6dfc orr r0, r0, #0x20000 */
/* @0x2a6e00 str.w r0, [r1, #0x130] */
/* @0x2a6e04 ldr r0, [sp] */
/* @0x2a6e06 ldrb r1, [r0, r7] */
/* @0x2a6e08 cmp r1, #0x2e */
/* @0x2a6e0a bne 0x2a6e12 <png_create_read_struct_2+0xc6> */
/* @0x2a6e0c cbnz r4, 0x2a6e28 <png_create_read_struct_2+0xdc> */
/* @0x2a6e0e mov r4, r6 */
/* @0x2a6e10 b 0x2a6e14 <png_create_read_struct_2+0xc8> */
/* @0x2a6e12 cbz r1, 0x2a6e28 <png_create_read_struct_2+0xdc> */
/* @0x2a6e14 cmp r2, #0x0 */
/* @0x2a6e16 bne 0x2a6de8 <png_create_read_struct_2+0x9c> */
/* @0x2a6e18 b 0x2a6e28 <png_create_read_struct_2+0xdc> */
/* @0x2a6e1a ldr r3, [sp, #0x24] */
/* @0x2a6e1c ldr.w r2, [r3, #0x130] */
/* @0x2a6e20 orr r2, r2, #0x20000 */
/* @0x2a6e24 str.w r2, [r3, #0x130] */
/* @0x2a6e28 ldr r3, [sp, #0x24] */
/* @0x2a6e2a ldr.w r3, [r3, #0x130] */
/* @0x2a6e2c orrseq r3, r11, #48, #2 */
/* @0x2a6e2e lsls r3, r3, #0xe */
/* @0x2a6e30 bpl 0x2a6eb4 <png_create_read_struct_2+0x168> */
/* @0x2a6e32 ldr r1, [sp] */
/* @0x2a6e34 cbz r1, 0x2a6e88 <png_create_read_struct_2+0x13c> */
/* @0x2a6e36 movs r0, #0x0 */
/* @0x2a6e38 ldrb r4, [r1] */
/* @0x2a6e3a bl 0x2a5fcc <png_get_header_ver> */
/* @0x2a6e3c stmdavc r3, {r0, r1, r2, r6, r7, r11, r12, sp, lr, pc} */
/* @0x2a6e3e ldrb r3, [r0] */
/* @0x2a6e40 cmp r3, r4 */
/* @0x2a6e42 bne 0x2a6e70 <png_create_read_struct_2+0x124> */
/* @0x2a6e44 ldr r2, [sp] */
/* @0x2a6e46 ldrb r3, [r2] */
/* @0x2a6e48 cmp r3, #0x31 */
/* @0x2a6e4a beq 0x2a6e56 <png_create_read_struct_2+0x10a> */
/* @0x2a6e4c ldr r0, [sp] */
/* @0x2a6e4e ldrb r3, [r0] */
/* @0x2a6e50 cmp r3, #0x30 */
/* @0x2a6e52 bne 0x2a6eb4 <png_create_read_struct_2+0x168> */
/* @0x2a6e54 b 0x2a6e68 <png_create_read_struct_2+0x11c> */
/* @0x2a6e56 ldr r1, [sp] */
/* @0x2a6e58 movs r0, #0x0 */
/* @0x2a6e5a ldrb r4, [r1, #0x2] */
/* @0x2a6e5c bl 0x2a5fcc <png_get_header_ver> */
/* @0x2a6e60 ldrb r3, [r0, #0x2] */
/* @0x2a6e62 cmp r3, r4 */
/* @0x2a6e64 bne 0x2a6e70 <png_create_read_struct_2+0x124> */
/* @0x2a6e66 b 0x2a6e4c <png_create_read_struct_2+0x100> */
/* @0x2a6e68 ldr r2, [sp] */
/* @0x2a6e6a ldrb r3, [r2, #0x2] */
/* @0x2a6e6c cmp r3, #0x38 */
/* @0x2a6e6e bhi 0x2a6eb4 <png_create_read_struct_2+0x168> */
/* @0x2a6e70 add r4, sp, #0x2c */
/* @0x2a6e72 ldr r2, [pc, #0x144] */
/* @0x2a6e74 movs r1, #0x50 */
/* @0x2a6e76 ldr r3, [sp] */
/* @0x2a6e78 mov r0, r4 */
/* @0x2a6e7a add r2, pc */
/* @0x2a6e7c blx 0xb65c8 <snprintf@plt> */
/* @0x2a6e80 ldr r0, [sp, #0x24] */
/* @0x2a6e82 mov r1, r4 */
/* @0x2a6e84 bl 0x2a6474 <png_warning> */
/* @0x2a6e88 movs r0, #0x0 */
/* @0x2a6e8a add r4, sp, #0x2c */
/* @0x2a6e8c bl 0x2a5fcc <png_get_header_ver> */
/* @0x2a6e90 ldr r2, [pc, #0x128] */
/* @0x2a6e92 movs r1, #0x50 */
/* @0x2a6e94 add r2, pc */
/* @0x2a6e96 mov r3, r0 */
/* @0x2a6e98 mov r0, r4 */
/* @0x2a6e9a blx 0xb65c8 <snprintf@plt> */
/* @0x2a6e9c stmdals r9, {r1, r2, r4, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2a6e9e ldr r0, [sp, #0x24] */
/* @0x2a6ea0 mov r1, r4 */
/* @0x2a6ea2 bl 0x2a6474 <png_warning> */
/* @0x2a6ea4 stmdbmi r6, {r0, r1, r2, r5, r6, r7, r9, r11, r12, sp, lr, pc} ^ */
/* @0x2a6ea6 ldr r1, [pc, #0x118] */
/* @0x2a6ea8 ldr r0, [sp, #0x24] */
/* @0x2a6eaa add r1, pc */
/* @0x2a6eac bl 0x2a6474 <png_warning> */
/* @0x2a6eb0 movs r3, #0x1 */
/* @0x2a6eb2 str r3, [sp, #0x28] */
/* @0x2a6eb4 ldr r3, [sp, #0x28] */
/* @0x2a6eb6 cbnz r3, 0x2a6ee0 <png_create_read_struct_2+0x194> */
/* @0x2a6eb8 ldr r3, [sp, #0x24] */
/* @0x2a6eba mov.w r2, #0x2000 */
/* @0x2a6ebc .word 0x9c095200 */
/* @0x2a6ebe ldr r4, [sp, #0x24] */
/* @0x2a6ec0 ldr r0, [sp, #0x24] */
/* @0x2a6ec2 str.w r2, [r3, #0x174] */
/* @0x2a6ec4 blls 0x4ef49c <SrcVerts+0x4c4e0> */
/* @0x2a6ec6 ldr r3, [sp, #0x24] */
/* @0x2a6ec8 ldr.w r1, [r3, #0x174] */
/* @0x2a6ecc bl 0x2a6d16 <png_malloc_warn> */
/* @0x2a6ed0 ldr r3, [sp, #0x24] */
/* @0x2a6ed2 str.w r0, [r4, #0x170] */
/* @0x2a6ed4 .word 0xf8d30170 */
/* @0x2a6ed6 ldr.w r3, [r3, #0x170] */
/* @0x2a6ed8 stmdblt r11, {r4, r5, r6, r8, r12, sp} */
/* @0x2a6eda cbnz r3, 0x2a6ee0 <png_create_read_struct_2+0x194> */
/* @0x2a6edc movs r3, #0x1 */
/* @0x2a6ede str r3, [sp, #0x28] */
/* @0x2a6ee0 ldr r0, [sp, #0x4] */
/* @0x2a6ee2 ldr r3, [pc, #0xe0] */
/* @0x2a6ee4 ldr r2, [sp, #0x24] */
/* @0x2a6ee6 ldr r3, [r0, r3] */
/* @0x2a6ee8 str.w r3, [r2, #0x158] */
/* @0x2a6eec ldr r3, [pc, #0xd8] */
/* @0x2a6eee ldr r2, [sp, #0x24] */
/* @0x2a6ef0 ldr r3, [r0, r3] */
/* @0x2a6ef2 str.w r3, [r2, #0x15c] */
/* @0x2a6ef4 bls 0x4f346c <SrcVerts+0x504b0> */
/* @0x2a6ef6 ldr r2, [sp, #0x24] */
/* @0x2a6ef8 ldr r3, [sp, #0x24] */
/* @0x2a6efa str.w r3, [r2, #0x160] */
/* @0x2a6efc blls 0x533484 <g_pPNGFile+0x4b8> */
/* @0x2a6efe ldr r3, [sp, #0x28] */
/* @0x2a6f00 cbnz r3, 0x2a6f42 <png_create_read_struct_2+0x1f6> */
/* @0x2a6f02 ldr r0, [sp, #0x24] */
/* @0x2a6f04 movs r2, #0x38 */
/* @0x2a6f06 ldr r1, [pc, #0xc4] */
/* @0x2a6f08 add.w r0, r0, #0x138 */
/* @0x2a6f0c add r1, pc */
/* @0x2a6f0e blx 0xb69d0 <inflateInit_@plt> */
/* @0x2a6f10 andlo lr, r6, r0, ror #26 */
/* @0x2a6f12 adds r0, #0x6 */
/* @0x2a6f14 cmp r0, #0x6 */
/* @0x2a6f16 bhi 0x2a6f34 <png_create_read_struct_2+0x1e8> */
/* @0x2a6f18 tbb [pc, r0] */
/* @0x2a6f1c lsrs r0, r1, #0x10 */
/* @0x2a6f1e lsrs r4, r0, #0x10 */
/* @0x2a6f20 lsrs r4, r0, #0x10 */
/* @0x2a6f22 movs r3, r2 */
/* @0x2a6f24 ldr r1, [pc, #0xa8] */
/* @0x2a6f26 ldr r0, [sp, #0x24] */
/* @0x2a6f28 add r1, pc */
/* @0x2a6f2a b 0x2a6f3a <png_create_read_struct_2+0x1ee> */
/* @0x2a6f2c ldr r1, [pc, #0xa4] */
/* @0x2a6f2e ldr r0, [sp, #0x24] */
/* @0x2a6f30 add r1, pc */
/* @0x2a6f32 b 0x2a6f3a <png_create_read_struct_2+0x1ee> */
/* @0x2a6f34 ldr r1, [pc, #0xa0] */
/* @0x2a6f36 ldr r0, [sp, #0x24] */
/* @0x2a6f38 add r1, pc */
/* @0x2a6f3a bl 0x2a6474 <png_warning> */
/* @0x2a6f3c movwhs pc, #0x1a9b */
/* @0x2a6f3e movs r3, #0x1 */
/* @0x2a6f40 str r3, [sp, #0x28] */
/* @0x2a6f42 ldr r1, [sp, #0x28] */
/* @0x2a6f44 cbz r1, 0x2a6f68 <png_create_read_struct_2+0x21c> */
/* @0x2a6f46 ldr r0, [sp, #0x24] */
/* @0x2a6f48 movs r4, #0x0 */
/* @0x2a6f4a ldr r3, [sp, #0x24] */
/* @0x2a6f4c ldr.w r1, [r3, #0x170] */
/* @0x2a6f50 bl 0x2a6cfc <png_free> */
/* @0x2a6f54 ldr r3, [sp, #0x24] */
/* @0x2a6f56 ldr r1, [sp, #0x10] */
/* @0x2a6f58 ldr r0, [sp, #0x24] */
/* @0x2a6f5a str.w r4, [r3, #0x170] */
/* @0x2a6f5c bls 0x337524 */
/* @0x2a6f5e ldr r2, [sp, #0x8] */
/* @0x2a6f60 bl 0x2a6c5e <png_destroy_struct_2> */
/* @0x2a6f64 mov r0, r4 */
/* @0x2a6f66 b 0x2a6f8a <png_create_read_struct_2+0x23e> */
/* @0x2a6f68 ldr r2, [sp, #0x24] */
/* @0x2a6f6a ldr r3, [sp, #0x24] */
/* @0x2a6f6c ldr.w r3, [r3, #0x170] */
/* @0x2a6f70 str.w r3, [r2, #0x144] */
/* @0x2a6f74 ldr r2, [sp, #0x24] */
/* @0x2a6f76 ldr r3, [sp, #0x24] */
/* @0x2a6f78 ldr r0, [sp, #0x24] */
/* @0x2a6f7a ldr.w r3, [r3, #0x174] */
/* @0x2a6f7c .word 0xf8c23174 */
/* @0x2a6f7e str.w r3, [r2, #0x148] */
/* @0x2a6f80 strmi r3, [r10], -r8, asr #2 */
/* @0x2a6f82 mov r2, r1 */
/* @0x2a6f84 bl 0x2a804c <png_set_read_fn> */
/* @0x2a6f88 ldr r0, [sp, #0x24] */
/* @0x2a6f8a ldr r3, [pc, #0x20] */
/* @0x2a6f8c ldr r1, [sp, #0x4] */
/* @0x2a6f8e ldr r2, [sp, #0x7c] */
/* @0x2a6f90 ldr r3, [r1, r3] */
/* @0x2a6f92 ldr r3, [r3] */
/* @0x2a6f94 cmp r2, r3 */
/* @0x2a6f96 beq 0x2a6f9c <png_create_read_struct_2+0x250> */
/* @0x2a6f98 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a6f9c add sp, #0x84 */
/* @0x2a6f9e pop {r4, r5, r6, r7, pc} */
/* @0x2a6fa0 rsbs r0, r0, #0 */
/* @0x2a6fa2 movs r7, r1 */
/* @0x2a6fa4 asrs r0, r0, #0x8 */
/* @0x2a6fa6 lsls r2, r7, #0x1 */
/* @0x2a6fa8 add r6, sp, #0x3e8 */
/* @0x2a6faa movs r4, r2 */
/* @0x2a6fac pop {pc} */
/* @0x2a6fae .word 0xffff e4ac */
/* @0x2a6fb0 .word 0xffffe4ac */
/* @0x2a6fb2 .word 0xffff 558a */
/* @0x2a6fb4 andeq r5, lr, r10, lsl #11 */
/* @0x2a6fb6 movs r6, r1 */
/* @0x2a6fb8 ldr r6, [r4, r4] */
/* @0x2a6fba movs r6, r1 */
/* @0x2a6fbc ldr r7, [r4, r1] */
/* @0x2a6fbe movs r6, r1 */
/* @0x2a6fc0 ldr r7, [r0, r2] */
/* @0x2a6fc2 movs r6, r1 */
/* @0x2a6fc4 mcr2 p15, #0x2, pc, c4, c15, #0x7 */
/* @0x2a6fc8 mcr2 p15, #0x2, pc, c8, c15, #0x7 */
/* @0x2a6fcc str r4, [r7, r2] */
/* @0x2a6fce movs r6, r1 */
/* @0x2a6fd0 ldr r0, [r0, r1] */
/* @0x2a6fd2 movs r6, r1 */
/* @0x2a6fd4 ldr r2, [r1, r1] */
/* @0x2a6fd6 movs r6, r1 */
/* @0x2a6fd8 ldr r5, [r2, r1] */
/* @0x2a6fda movs r6, r1 */

/* ── FUNC 0x2a6fdc · png_create_read_struct · size=18 · insn=9 */
/* @0x2a6fdc push {r0, r1, r2, r3, r4, lr} */
/* @0x2a6fde movs r4, #0x0 */
/* @0x2a6fe0 str r4, [sp] */
/* @0x2a6fe2 str r4, [sp, #0x4] */
/* @0x2a6fe4 str r4, [sp, #0x8] */
/* @0x2a6fe6 bl 0x2a6d4c <png_create_read_struct_2> */
/* @0x2a6fe8 strhlt pc, [r4], -r1 */
/* @0x2a6fea add sp, #0x10 */
/* @0x2a6fec pop {r4, pc} */

/* ── FUNC 0x2a6ff0 · png_read_info · size=1112 · insn=511 */
/* @0x2a6ff0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a6ff4 mov r7, r1 */
/* @0x2a6ff6 sub sp, #0xb4 */
/* @0x2a6ff8 mov r4, r0 */
/* @0x2a6ffa cmp r0, #0x0 */
/* @0x2a6ffc beq.w 0x2a742c <png_read_info+0x43c> */
/* @0x2a7000 cmp r1, #0x0 */
/* @0x2a7002 beq.w 0x2a742c <png_read_info+0x43c> */
/* @0x2a7004 .word 0xf8df8213 */
/* @0x2a7006 ldr.w r8, [pc, #0x42c] */
/* @0x2a7008 .word 0xf004842c */
/* @0x2a700a bl 0x2abb94 <png_read_sig> */
/* @0x2a700c .word 0xf10dfdc3 */
/* @0x2a700e add.w r10, sp, #0x8 */
/* @0x2a7010 ldrbtmi r0, [r8], #2568 */
/* @0x2a7012 add r8, pc */
/* @0x2a7014 ldrb.w r3, [r8, #0x4] */
/* @0x2a7018 strb.w r3, [sp, #0x7] */
/* @0x2a701c ldrb.w r3, [sp, #0x7] */
/* @0x2a7020 add.w r9, sp, #0x10 */
/* @0x2a7024 ldr.w r0, [r8] */
/* @0x2a7028 add.w r5, r4, #0x1e0 */
/* @0x2a702c add.w r11, sp, #0x20 */
/* @0x2a7030 strb.w r3, [r10, #0x4] */
/* @0x2a7034 mov r3, r8 */
/* @0x2a7036 str.w r0, [r10] */
/* @0x2a7038 .word 0xf8530000 */
/* @0x2a703a ldr r0, [r3, #5]! */
/* @0x2a703c ldmdbvc r11, {r0, r2, r8, r9, r10, r11} */
/* @0x2a703e ldrb r3, [r3, #0x4] */
/* @0x2a7040 str r0, [sp, #0x10] */
/* @0x2a7042 strb.w r3, [sp, #0x14] */
/* @0x2a7044 .word 0x46433014 */
/* @0x2a7046 mov r3, r8 */
/* @0x2a7048 ldr r0, [r3, #10]! */
/* @0x2a704c ldrb r3, [r3, #0x4] */
/* @0x2a704e str r0, [sp, #0x18] */
/* @0x2a7050 strb.w r3, [sp, #0x1c] */
/* @0x2a7054 mov r3, r8 */
/* @0x2a7056 ldr r0, [r3, #15]! */
/* @0x2a7058 ldmdbvc r11, {r0, r1, r2, r3, r8, r9, r10, r11} */
/* @0x2a705a ldrb r3, [r3, #0x4] */
/* @0x2a705c str r0, [sp, #0x20] */
/* @0x2a705e strb.w r3, [sp, #0x24] */
/* @0x2a7060 strbmi r3, [r3], -r4, lsr #32 */
/* @0x2a7062 mov r3, r8 */
/* @0x2a7064 ldr r0, [r3, #20]! */
/* @0x2a7068 ldrb r3, [r3, #0x4] */
/* @0x2a706a str r0, [sp, #0x28] */
/* @0x2a706c strb.w r3, [sp, #0x2c] */
/* @0x2a7070 mov r3, r8 */
/* @0x2a7072 ldr r0, [r3, #25]! */
/* @0x2a7074 ldmdbvc r11, {r0, r3, r4, r8, r9, r10, r11} */
/* @0x2a7076 ldrb r3, [r3, #0x4] */
/* @0x2a7078 str r0, [sp, #0x30] */
/* @0x2a707a strb.w r3, [sp, #0x34] */
/* @0x2a707c .word 0x46433034 */
/* @0x2a707e mov r3, r8 */
/* @0x2a7080 ldr r0, [r3, #30]! */
/* @0x2a7084 ldrb r3, [r3, #0x4] */
/* @0x2a7086 str r0, [sp, #0x38] */
/* @0x2a7088 strb.w r3, [sp, #0x3c] */
/* @0x2a708c mov r3, r8 */
/* @0x2a708e ldr r0, [r3, #35]! */
/* @0x2a7090 ldmdbvc r11, {r0, r1, r5, r8, r9, r10, r11} */
/* @0x2a7092 ldrb r3, [r3, #0x4] */
/* @0x2a7094 str r0, [sp, #0x40] */
/* @0x2a7096 strb.w r3, [sp, #0x44] */
/* @0x2a7098 strbmi r3, [r3], -r4, asr #32 */
/* @0x2a709a mov r3, r8 */
/* @0x2a709c ldr r0, [r3, #40]! */
/* @0x2a70a0 str r0, [sp, #0x48] */
/* @0x2a70a2 ldrb r3, [r3, #0x4] */
/* @0x2a70a4 strb.w r3, [sp, #0x4c] */
/* @0x2a70a8 mov r3, r8 */
/* @0x2a70aa ldr r0, [r3, #45]! */
/* @0x2a70ac ldmdbvc r11, {r0, r2, r3, r5, r8, r9, r10, r11} */
/* @0x2a70ae ldrb r3, [r3, #0x4] */
/* @0x2a70b0 str r0, [sp, #0x50] */
/* @0x2a70b2 strb.w r3, [sp, #0x54] */
/* @0x2a70b4 .word 0x46433054 */
/* @0x2a70b6 mov r3, r8 */
/* @0x2a70b8 ldr r0, [r3, #50]! */
/* @0x2a70bc ldrb r3, [r3, #0x4] */
/* @0x2a70be str r0, [sp, #0x58] */
/* @0x2a70c0 strb.w r3, [sp, #0x5c] */
/* @0x2a70c4 mov r3, r8 */
/* @0x2a70c6 ldr r0, [r3, #55]! */
/* @0x2a70c8 ldmdbvc r11, {r0, r1, r2, r4, r5, r8, r9, r10, r11} */
/* @0x2a70ca ldrb r3, [r3, #0x4] */
/* @0x2a70cc str r0, [sp, #0x60] */
/* @0x2a70ce strb.w r3, [sp, #0x64] */
/* @0x2a70d0 strbmi r3, [r3], -r4, rrx */
/* @0x2a70d2 mov r3, r8 */
/* @0x2a70d4 ldr r0, [r3, #60]! */
/* @0x2a70d8 ldrb r3, [r3, #0x4] */
/* @0x2a70da str r0, [sp, #0x68] */
/* @0x2a70dc strb.w r3, [sp, #0x6c] */
/* @0x2a70e0 mov r3, r8 */
/* @0x2a70e2 ldr r0, [r3, #65]! */
/* @0x2a70e4 ldmdbvc r11, {r0, r6, r8, r9, r10, r11} */
/* @0x2a70e6 ldrb r3, [r3, #0x4] */
/* @0x2a70e8 str r0, [sp, #0x70] */
/* @0x2a70ea strb.w r3, [sp, #0x74] */
/* @0x2a70ec .word 0x46433074 */
/* @0x2a70ee mov r3, r8 */
/* @0x2a70f0 ldr r0, [r3, #70]! */
/* @0x2a70f4 ldrb r3, [r3, #0x4] */
/* @0x2a70f6 str r0, [sp, #0x78] */
/* @0x2a70f8 strb.w r3, [sp, #0x7c] */
/* @0x2a70fc mov r3, r8 */
/* @0x2a70fe ldr r0, [r3, #75]! */
/* @0x2a7100 ldmdbvc r11, {r0, r1, r3, r6, r8, r9, r10, r11} */
/* @0x2a7102 ldrb r3, [r3, #0x4] */
/* @0x2a7104 str r0, [sp, #0x80] */
/* @0x2a7106 strb.w r3, [sp, #0x84] */
/* @0x2a7108 strbmi r3, [r3], -r4, lsl #1 */
/* @0x2a710a mov r3, r8 */
/* @0x2a710c ldr r0, [r3, #80]! */
/* @0x2a7110 ldrb r3, [r3, #0x4] */
/* @0x2a7112 str r0, [sp, #0x88] */
/* @0x2a7114 strb.w r3, [sp, #0x8c] */
/* @0x2a7118 mov r3, r8 */
/* @0x2a711a ldr r0, [r3, #85]! */
/* @0x2a711c ldmdbvc r11, {r0, r2, r4, r6, r8, r9, r10, r11} */
/* @0x2a711e ldrb r3, [r3, #0x4] */
/* @0x2a7120 str r0, [sp, #0x90] */
/* @0x2a7122 strb.w r3, [sp, #0x94] */
/* @0x2a7124 .word 0x46433094 */
/* @0x2a7126 mov r3, r8 */
/* @0x2a7128 ldr r0, [r3, #90]! */
/* @0x2a712c ldrb r3, [r3, #0x4] */
/* @0x2a712e str r0, [sp, #0x98] */
/* @0x2a7130 strb.w r3, [sp, #0x9c] */
/* @0x2a7134 mov r3, r8 */
/* @0x2a7136 ldr r0, [r3, #95]! */
/* @0x2a7138 ldmdbvc r11, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11} */
/* @0x2a713a ldrb r3, [r3, #0x4] */
/* @0x2a713c str r0, [sp, #0xa0] */
/* @0x2a713e strb.w r3, [sp, #0xa4] */
/* @0x2a7140 strbmi r3, [r3], -r4, lsr #1 */
/* @0x2a7142 mov r3, r8 */
/* @0x2a7144 ldr r0, [r3, #100]! */
/* @0x2a7148 ldrb r3, [r3, #0x4] */
/* @0x2a714a str r0, [sp, #0xa8] */
/* @0x2a714c mov r0, r4 */
/* @0x2a714e strb.w r3, [sp, #0xac] */
/* @0x2a7150 .word 0xf00630ac */
/* @0x2a7152 bl 0x2adbc4 <png_read_chunk_header> */
/* @0x2a7154 .word 0x4649fd37 */
/* @0x2a7156 mov r1, r9 */
/* @0x2a7158 movs r2, #0x4 */
/* @0x2a715a mov r6, r0 */
/* @0x2a715c mov r0, r5 */
/* @0x2a715e blx 0xb6c40 <memcmp@plt> */
/* @0x2a7160 ldmdblt r8!, {r4, r5, r6, r8, r10, r11, sp, lr, pc} */
/* @0x2a7162 cbnz r0, 0x2a7174 <png_read_info+0x184> */
/* @0x2a7164 ldr.w r3, [r4, #0x12c] */
/* @0x2a7168 lsls r2, r3, #0x1c */
/* @0x2a716a itt mi */
/* @0x2a716c orrmi r3, r3, #0x2000 */
/* @0x2a7170 strmi.w r3, [r4, #0x12c] */
/* @0x2a7174 mov r0, r5 */
/* @0x2a7176 mov r1, r10 */
/* @0x2a7178 movs r2, #0x4 */
/* @0x2a717a blx 0xb6c40 <memcmp@plt> */
/* @0x2a717c stmdblt r8!, {r1, r5, r6, r8, r10, r11, sp, lr, pc} */
/* @0x2a717e cbnz r0, 0x2a718c <png_read_info+0x19c> */
/* @0x2a7180 mov r0, r4 */
/* @0x2a7182 mov r1, r7 */
/* @0x2a7184 mov r2, r6 */
/* @0x2a7186 bl 0x2abe50 <png_handle_IHDR> */
/* @0x2a7188 strb pc, [r7, -r3, ror #28] */
/* @0x2a718a b 0x2a701c <png_read_info+0x2c> */
/* @0x2a718c mov r0, r5 */
/* @0x2a718e add r1, sp, #0x18 */
/* @0x2a7190 movs r2, #0x4 */
/* @0x2a7192 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7194 stmdblt r8!, {r1, r2, r4, r6, r8, r10, r11, sp, lr, pc} */
/* @0x2a7196 cbnz r0, 0x2a71a4 <png_read_info+0x1b4> */
/* @0x2a7198 mov r0, r4 */
/* @0x2a719a mov r1, r7 */
/* @0x2a719c mov r2, r6 */
/* @0x2a719e bl 0x2ac0c8 <png_handle_IEND> */
/* @0x2a71a0 .word 0xe73bff93 */
/* @0x2a71a2 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a71a4 mov r0, r4 */
/* @0x2a71a6 mov r1, r5 */
/* @0x2a71a8 bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2a71ac cmp r0, #0x0 */
/* @0x2a71ae beq 0x2a722c <png_read_info+0x23c> */
/* @0x2a71b0 mov r0, r5 */
/* @0x2a71b2 mov r1, r9 */
/* @0x2a71b4 movs r2, #0x4 */
/* @0x2a71b6 blx 0xb6c40 <memcmp@plt> */
/* @0x2a71b8 stmdblt r8!, {r2, r6, r8, r10, r11, sp, lr, pc} */
/* @0x2a71ba cbnz r0, 0x2a71c8 <png_read_info+0x1d8> */
/* @0x2a71bc ldr.w r3, [r4, #0x12c] */
/* @0x2a71c0 orr r3, r3, #0x4 */
/* @0x2a71c4 str.w r3, [r4, #0x12c] */
/* @0x2a71c8 mov r0, r4 */
/* @0x2a71ca mov r1, r7 */
/* @0x2a71cc mov r2, r6 */
/* @0x2a71ce bl 0x2ada34 <png_handle_unknown> */
/* @0x2a71d0 qasxmi pc, r8, r1 */
/* @0x2a71d2 mov r0, r5 */
/* @0x2a71d4 mov r1, r11 */
/* @0x2a71d6 movs r2, #0x4 */
/* @0x2a71d8 blx 0xb6c40 <memcmp@plt> */
/* @0x2a71dc cbnz r0, 0x2a71ec <png_read_info+0x1fc> */
/* @0x2a71de ldr.w r3, [r4, #0x12c] */
/* @0x2a71e0 .word 0xf043312c */
/* @0x2a71e2 orr r3, r3, #0x2 */
/* @0x2a71e4 .word 0xf8c40302 */
/* @0x2a71e6 str.w r3, [r4, #0x12c] */
/* @0x2a71e8 ldr r3, [r7, -r12, lsr #2] */
/* @0x2a71ea b 0x2a701c <png_read_info+0x2c> */
/* @0x2a71ec mov r0, r5 */
/* @0x2a71ee mov r1, r9 */
/* @0x2a71f0 movs r2, #0x4 */
/* @0x2a71f2 blx 0xb6c40 <memcmp@plt> */
/* @0x2a71f4 stmdahs r0, {r1, r2, r5, r8, r10, r11, sp, lr, pc} */
/* @0x2a71f6 cmp r0, #0x0 */
/* @0x2a71f8 bne.w 0x2a701c <png_read_info+0x2c> */
/* @0x2a71fc ldr.w r3, [r4, #0x12c] */
/* @0x2a7200 lsls r0, r3, #0x1f */
/* @0x2a7202 bmi 0x2a720c <png_read_info+0x21c> */
/* @0x2a7204 ldr r1, [pc, #0x230] */
/* @0x2a7206 mov r0, r4 */
/* @0x2a7208 add r1, pc */
/* @0x2a720a b 0x2a7222 <png_read_info+0x232> */
/* @0x2a720c ldrb.w r2, [r4, #0x1ea] */
/* @0x2a7210 cmp r2, #0x3 */
/* @0x2a7212 bne.w 0x2a742c <png_read_info+0x43c> */
/* @0x2a7214 ldreq r8, [r9, r11, lsl #2] */
/* @0x2a7216 lsls r1, r3, #0x1e */
/* @0x2a7218 bmi.w 0x2a742c <png_read_info+0x43c> */
/* @0x2a721c ldr r1, [pc, #0x21c] */
/* @0x2a721e mov r0, r4 */
/* @0x2a7220 add r1, pc */
/* @0x2a7222 add sp, #0xb4 */
/* @0x2a7224 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a7228 b.w 0x2a642c <png_error> */
/* @0x2a722c mov r0, r5 */
/* @0x2a722e mov r1, r11 */
/* @0x2a7230 movs r2, #0x4 */
/* @0x2a7232 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7234 stmdblt r8!, {r1, r2, r8, r10, r11, sp, lr, pc} */
/* @0x2a7236 cbnz r0, 0x2a7244 <png_read_info+0x254> */
/* @0x2a7238 mov r0, r4 */
/* @0x2a723a mov r1, r7 */
/* @0x2a723c mov r2, r6 */
/* @0x2a723e bl 0x2abf64 <png_handle_PLTE> */
/* @0x2a7240 usat pc, #0xb, r1, lsl #29 */
/* @0x2a7242 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7244 mov r0, r5 */
/* @0x2a7246 mov r1, r9 */
/* @0x2a7248 movs r2, #0x4 */
/* @0x2a724a blx 0xb6c40 <memcmp@plt> */
/* @0x2a724c ldmiblt r8, {r1, r3, r4, r5, r6, r7, r10, r11, sp, lr, pc} ^ */
/* @0x2a724e cbnz r0, 0x2a7288 <png_read_info+0x298> */
/* @0x2a7250 ldr.w r3, [r4, #0x12c] */
/* @0x2a7254 lsls r2, r3, #0x1f */
/* @0x2a7256 bmi 0x2a7260 <png_read_info+0x270> */
/* @0x2a7258 ldr r1, [pc, #0x1e4] */
/* @0x2a725a mov r0, r4 */
/* @0x2a725c add r1, pc */
/* @0x2a725e b 0x2a7272 <png_read_info+0x282> */
/* @0x2a7260 ldrb.w r2, [r4, #0x1ea] */
/* @0x2a7264 cmp r2, #0x3 */
/* @0x2a7266 bne 0x2a7276 <png_read_info+0x286> */
/* @0x2a7268 lsls r3, r3, #0x1e */
/* @0x2a726a bmi 0x2a7276 <png_read_info+0x286> */
/* @0x2a726c ldr r1, [pc, #0x1d4] */
/* @0x2a726e mov r0, r4 */
/* @0x2a7270 add r1, pc */
/* @0x2a7272 bl 0x2a642c <png_error> */
/* @0x2a7274 .word 0xf8d4f8db */
/* @0x2a7276 ldr.w r3, [r4, #0x12c] */
/* @0x2a7278 .word 0xf8c4312c */
/* @0x2a727a str.w r6, [r4, #0x1d0] */
/* @0x2a727c .word 0xf04361d0 */
/* @0x2a727e orr r3, r3, #0x4 */
/* @0x2a7280 .word 0xf8c40304 */
/* @0x2a7282 str.w r3, [r4, #0x12c] */
/* @0x2a7284 sbcs r3, r1, r12, lsr #2 */
/* @0x2a7286 b 0x2a742c <png_read_info+0x43c> */
/* @0x2a7288 mov r0, r5 */
/* @0x2a728a add r1, sp, #0x28 */
/* @0x2a728c movs r2, #0x4 */
/* @0x2a728e blx 0xb6c40 <memcmp@plt> */
/* @0x2a7290 stmdblt r8!, {r3, r4, r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a7292 cbnz r0, 0x2a72a0 <png_read_info+0x2b0> */
/* @0x2a7294 mov r0, r4 */
/* @0x2a7296 mov r1, r7 */
/* @0x2a7298 mov r2, r6 */
/* @0x2a729a bl 0x2acd60 <png_handle_bKGD> */
/* @0x2a729c ldrt pc, [sp], r1, ror #26 */
/* @0x2a729e b 0x2a701c <png_read_info+0x2c> */
/* @0x2a72a0 mov r0, r5 */
/* @0x2a72a2 add r1, sp, #0x30 */
/* @0x2a72a4 movs r2, #0x4 */
/* @0x2a72a6 blx 0xb6c40 <memcmp@plt> */
/* @0x2a72a8 stmdblt r8!, {r2, r3, r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a72aa cbnz r0, 0x2a72b8 <png_read_info+0x2c8> */
/* @0x2a72ac mov r0, r4 */
/* @0x2a72ae mov r1, r7 */
/* @0x2a72b0 mov r2, r6 */
/* @0x2a72b2 bl 0x2ac328 <png_handle_cHRM> */
/* @0x2a72b4 .word 0xe6b1f839 */
/* @0x2a72b6 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a72b8 mov r0, r5 */
/* @0x2a72ba add r1, sp, #0x38 */
/* @0x2a72bc movs r2, #0x4 */
/* @0x2a72be blx 0xb6c40 <memcmp@plt> */
/* @0x2a72c0 stmdblt r8!, {r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a72c2 cbnz r0, 0x2a72d0 <png_read_info+0x2e0> */
/* @0x2a72c4 mov r0, r4 */
/* @0x2a72c6 mov r1, r7 */
/* @0x2a72c8 mov r2, r6 */
/* @0x2a72ca bl 0x2ac110 <png_handle_gAMA> */
/* @0x2a72cc strt pc, [r5], r1, lsr #30 */
/* @0x2a72ce b 0x2a701c <png_read_info+0x2c> */
/* @0x2a72d0 mov r0, r5 */
/* @0x2a72d2 add r1, sp, #0x40 */
/* @0x2a72d4 movs r2, #0x4 */
/* @0x2a72d6 blx 0xb6c40 <memcmp@plt> */
/* @0x2a72d8 stmdblt r8!, {r2, r4, r5, r7, r10, r11, sp, lr, pc} */
/* @0x2a72da cbnz r0, 0x2a72e8 <png_read_info+0x2f8> */
/* @0x2a72dc mov r0, r4 */
/* @0x2a72de mov r1, r7 */
/* @0x2a72e0 mov r2, r6 */
/* @0x2a72e2 bl 0x2ace98 <png_handle_hIST> */
/* @0x2a72e4 .word 0xe699fdd9 */
/* @0x2a72e6 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a72e8 mov r0, r5 */
/* @0x2a72ea add r1, sp, #0x58 */
/* @0x2a72ec movs r2, #0x4 */
/* @0x2a72ee blx 0xb6c40 <memcmp@plt> */
/* @0x2a72f0 stmdblt r8!, {r3, r5, r7, r10, r11, sp, lr, pc} */
/* @0x2a72f2 cbnz r0, 0x2a7300 <png_read_info+0x310> */
/* @0x2a72f4 mov r0, r4 */
/* @0x2a72f6 mov r1, r7 */
/* @0x2a72f8 mov r2, r6 */
/* @0x2a72fa bl 0x2ad030 <png_handle_oFFs> */
/* @0x2a72fc pkhbt pc, sp, r9, lsl #29 */
/* @0x2a72fe b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7300 mov r0, r5 */
/* @0x2a7302 add r1, sp, #0x60 */
/* @0x2a7304 movs r2, #0x4 */
/* @0x2a7306 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7308 stmdblt r8!, {r2, r3, r4, r7, r10, r11, sp, lr, pc} */
/* @0x2a730a cbnz r0, 0x2a7318 <png_read_info+0x328> */
/* @0x2a730c mov r0, r4 */
/* @0x2a730e mov r1, r7 */
/* @0x2a7310 mov r2, r6 */
/* @0x2a7312 bl 0x2ad128 <png_handle_pCAL> */
/* @0x2a7314 str pc, [r1], r9, lsl #30 */
/* @0x2a7316 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7318 mov r0, r5 */
/* @0x2a731a add r1, sp, #0x78 */
/* @0x2a731c movs r2, #0x4 */
/* @0x2a731e blx 0xb6c40 <memcmp@plt> */
/* @0x2a7320 stmdblt r8!, {r4, r7, r10, r11, sp, lr, pc} */
/* @0x2a7322 cbnz r0, 0x2a7330 <png_read_info+0x340> */
/* @0x2a7324 mov r0, r4 */
/* @0x2a7326 mov r1, r7 */
/* @0x2a7328 mov r2, r6 */
/* @0x2a732a bl 0x2ad350 <png_handle_sCAL> */
/* @0x2a732c uhadd16 pc, r5, r1 */
/* @0x2a732e b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7330 mov r0, r5 */
/* @0x2a7332 add r1, sp, #0x68 */
/* @0x2a7334 movs r2, #0x4 */
/* @0x2a7336 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7338 stmdblt r8!, {r2, r7, r10, r11, sp, lr, pc} */
/* @0x2a733a cbnz r0, 0x2a7348 <png_read_info+0x358> */
/* @0x2a733c mov r0, r4 */
/* @0x2a733e mov r1, r7 */
/* @0x2a7340 mov r2, r6 */
/* @0x2a7342 bl 0x2acf58 <png_handle_pHYs> */
/* @0x2a7344 strbt pc, [r9], -r9, lsl #28 */
/* @0x2a7346 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7348 mov r0, r5 */
/* @0x2a734a add r1, sp, #0x70 */
/* @0x2a734c movs r2, #0x4 */
/* @0x2a734e blx 0xb6c40 <memcmp@plt> */
/* @0x2a7350 stmdblt r8!, {r3, r4, r5, r6, r10, r11, sp, lr, pc} */
/* @0x2a7352 cbnz r0, 0x2a7360 <png_read_info+0x370> */
/* @0x2a7354 mov r0, r4 */
/* @0x2a7356 mov r1, r7 */
/* @0x2a7358 mov r2, r6 */
/* @0x2a735a bl 0x2ac238 <png_handle_sBIT> */
/* @0x2a735c ldrb pc, [sp], -sp, ror #30 */
/* @0x2a735e b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7360 mov r0, r5 */
/* @0x2a7362 add r1, sp, #0x88 */
/* @0x2a7364 movs r2, #0x4 */
/* @0x2a7366 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7368 stmdblt r8!, {r2, r3, r5, r6, r10, r11, sp, lr, pc} */
/* @0x2a736a cbnz r0, 0x2a7378 <png_read_info+0x388> */
/* @0x2a736c mov r0, r4 */
/* @0x2a736e mov r1, r7 */
/* @0x2a7370 mov r2, r6 */
/* @0x2a7372 bl 0x2ac694 <png_handle_sRGB> */
/* @0x2a7374 ldrb pc, [r1], -pc, lsl #19 */
/* @0x2a7376 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7378 mov r0, r5 */
/* @0x2a737a add r1, sp, #0x48 */
/* @0x2a737c movs r2, #0x4 */
/* @0x2a737e blx 0xb6c40 <memcmp@plt> */
/* @0x2a7380 stmdblt r8!, {r5, r6, r10, r11, sp, lr, pc} */
/* @0x2a7382 cbnz r0, 0x2a7390 <png_read_info+0x3a0> */
/* @0x2a7384 mov r0, r4 */
/* @0x2a7386 mov r1, r7 */
/* @0x2a7388 mov r2, r6 */
/* @0x2a738a bl 0x2ac814 <png_handle_iCCP> */
/* @0x2a738c strb pc, [r5], -r3, asr #20 */
/* @0x2a738e b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7390 mov r0, r5 */
/* @0x2a7392 add r1, sp, #0x80 */
/* @0x2a7394 movs r2, #0x4 */
/* @0x2a7396 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7398 stmdblt r8!, {r2, r4, r6, r10, r11, sp, lr, pc} */
/* @0x2a739a cbnz r0, 0x2a73a8 <png_read_info+0x3b8> */
/* @0x2a739c mov r0, r4 */
/* @0x2a739e mov r1, r7 */
/* @0x2a73a0 mov r2, r6 */
/* @0x2a73a2 bl 0x2ac9ec <png_handle_sPLT> */
/* @0x2a73a4 ldrt pc, [r9], -r3, lsr #22 */
/* @0x2a73a6 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a73a8 mov r0, r5 */
/* @0x2a73aa add r1, sp, #0x90 */
/* @0x2a73ac movs r2, #0x4 */
/* @0x2a73ae blx 0xb6c40 <memcmp@plt> */
/* @0x2a73b0 stmdblt r8!, {r3, r6, r10, r11, sp, lr, pc} */
/* @0x2a73b2 cbnz r0, 0x2a73c0 <png_read_info+0x3d0> */
/* @0x2a73b4 mov r0, r4 */
/* @0x2a73b6 mov r1, r7 */
/* @0x2a73b8 mov r2, r6 */
/* @0x2a73ba bl 0x2ad584 <png_handle_tEXt> */
/* @0x2a73bc strt pc, [sp], -r3, ror #17 */
/* @0x2a73be b 0x2a701c <png_read_info+0x2c> */
/* @0x2a73c0 mov r0, r5 */
/* @0x2a73c2 add r1, sp, #0x98 */
/* @0x2a73c4 movs r2, #0x4 */
/* @0x2a73c6 blx 0xb6c40 <memcmp@plt> */
/* @0x2a73c8 stmdblt r8!, {r2, r3, r4, r5, r10, r11, sp, lr, pc} */
/* @0x2a73ca cbnz r0, 0x2a73d8 <png_read_info+0x3e8> */
/* @0x2a73cc mov r0, r4 */
/* @0x2a73ce mov r1, r7 */
/* @0x2a73d0 mov r2, r6 */
/* @0x2a73d2 bl 0x2ad4d0 <png_handle_tIME> */
/* @0x2a73d4 qsub16 pc, r1, sp */
/* @0x2a73d6 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a73d8 mov r0, r5 */
/* @0x2a73da add r1, sp, #0xa0 */
/* @0x2a73dc movs r2, #0x4 */
/* @0x2a73de blx 0xb6c40 <memcmp@plt> */
/* @0x2a73e0 stmdblt r8!, {r4, r5, r10, r11, sp, lr, pc} */
/* @0x2a73e2 cbnz r0, 0x2a73f0 <png_read_info+0x400> */
/* @0x2a73e4 mov r0, r4 */
/* @0x2a73e6 mov r1, r7 */
/* @0x2a73e8 mov r2, r6 */
/* @0x2a73ea bl 0x2acbec <png_handle_tRNS> */
/* @0x2a73ec ssub8 pc, r5, pc */
/* @0x2a73ee b 0x2a701c <png_read_info+0x2c> */
/* @0x2a73f0 mov r0, r5 */
/* @0x2a73f2 add r1, sp, #0xa8 */
/* @0x2a73f4 movs r2, #0x4 */
/* @0x2a73f6 blx 0xb6c40 <memcmp@plt> */
/* @0x2a73f8 stmdblt r8!, {r2, r5, r10, r11, sp, lr, pc} */
/* @0x2a73fa cbnz r0, 0x2a7408 <png_read_info+0x418> */
/* @0x2a73fc mov r0, r4 */
/* @0x2a73fe mov r1, r7 */
/* @0x2a7400 mov r2, r6 */
/* @0x2a7402 bl 0x2ad6cc <png_handle_zTXt> */
/* @0x2a7404 str pc, [r9], -r3, ror #18 */
/* @0x2a7406 b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7408 mov r0, r5 */
/* @0x2a740a add r1, sp, #0x50 */
/* @0x2a740c movs r2, #0x4 */
/* @0x2a740e blx 0xb6c40 <memcmp@plt> */
/* @0x2a7410 stmdblt r8!, {r3, r4, r10, r11, sp, lr, pc} */
/* @0x2a7412 cbnz r0, 0x2a7420 <png_read_info+0x430> */
/* @0x2a7414 mov r0, r4 */
/* @0x2a7416 mov r1, r7 */
/* @0x2a7418 mov r2, r6 */
/* @0x2a741a bl 0x2ad850 <png_handle_iTXt> */
/* @0x2a741c ldrb pc, [sp, #0xa19]! */
/* @0x2a741e b 0x2a701c <png_read_info+0x2c> */
/* @0x2a7420 mov r0, r4 */
/* @0x2a7422 mov r1, r7 */
/* @0x2a7424 mov r2, r6 */
/* @0x2a7426 bl 0x2ada34 <png_handle_unknown> */
/* @0x2a7428 ldrb pc, [r7, #0xb05]! */
/* @0x2a742a b 0x2a701c <png_read_info+0x2c> */
/* @0x2a742c add sp, #0xb4 */
/* @0x2a742e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a7430 svclt #0x8ff0 */
/* @0x2a7432 nop */
/* @0x2a7434 ldrh r6, [r6, #0x6] */
/* @0x2a7436 movs r6, r1 */
/* @0x2a7438 strb r6, [r1, r7] */
/* @0x2a743a movs r6, r1 */
/* @0x2a743c strb r7, [r1, r7] */
/* @0x2a743e movs r6, r1 */
/* @0x2a7440 strb r2, [r7, r5] */
/* @0x2a7442 movs r6, r1 */
/* @0x2a7444 strb r7, [r7, r5] */
/* @0x2a7446 movs r6, r1 */

/* ── FUNC 0x2a7448 · png_read_update_info · size=48 · insn=22 */
/* @0x2a7448 push {r3, r4, r5, lr} */
/* @0x2a744a mov r5, r1 */
/* @0x2a744c mov r4, r0 */
/* @0x2a744e cbz r0, 0x2a7472 <png_read_update_info+0x2a> */
/* @0x2a7450 ldr.w r3, [r0, #0x130] */
/* @0x2a7454 lsls r3, r3, #0x19 */
/* @0x2a7456 bmi 0x2a745e <png_read_update_info+0x16> */
/* @0x2a7458 bl 0x2ae494 <png_read_start_row> */
/* @0x2a745c b 0x2a7466 <png_read_update_info+0x1e> */
/* @0x2a745e ldr r1, [pc, #0x14] */
/* @0x2a7460 add r1, pc */
/* @0x2a7462 bl 0x2a6474 <png_warning> */
/* @0x2a7464 strtmi pc, [r0], -r7, lsl #16 */
/* @0x2a7466 mov r0, r4 */
/* @0x2a7468 mov r1, r5 */
/* @0x2a746a pop.w {r3, r4, r5, lr} */
/* @0x2a746c .word 0xf0014038 */
/* @0x2a746e b.w 0x2a89bc <png_read_transform_info> */
/* @0x2a7470 vldmdblt r8!, {s22, s23, s24, s25, s26, s27, s28, s29, s30, s31} */
/* @0x2a7472 pop {r3, r4, r5, pc} */
/* @0x2a7474 strh r0, [r5, r6] */
/* @0x2a7476 movs r6, r1 */

/* ── FUNC 0x2a7478 · png_start_read_image · size=16 · insn=8 */
/* @0x2a7478 cbz r0, 0x2a7486 <png_start_read_image+0xe> */
/* @0x2a747a ldr.w r3, [r0, #0x130] */
/* @0x2a747c uasxeq r3, r11, r0 */
/* @0x2a747e lsls r3, r3, #0x19 */
/* @0x2a7480 bmi 0x2a7486 <png_start_read_image+0xe> */
/* @0x2a7482 b.w 0x2ae494 <png_read_start_row> */
/* @0x2a7484 ldrbmi r11, [r0, -r7, lsl #16]! */
/* @0x2a7486 bx lr */

/* ── FUNC 0x2a7488 · png_read_row · size=856 · insn=360 */
/* @0x2a7488 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a748c mov r4, r0 */
/* @0x2a748e ldr r7, [pc, #0x33c] */
/* @0x2a7490 sub sp, #0x4c */
/* @0x2a7492 mov r8, r1 */
/* @0x2a7494 mov r5, r2 */
/* @0x2a7496 add r7, pc */
/* @0x2a7498 add r6, sp, #0x10 */
/* @0x2a749a add.w r12, r7, #0x6c */
/* @0x2a749c ldrtmi r0, [r11], -r12, ror #24 */
/* @0x2a749e mov r3, r7 */
/* @0x2a74a0 adds r7, #0x88 */
/* @0x2a74a2 ldr r0, [r3, #5]! */
/* @0x2a74a4 ldmdbvc r11, {r0, r2, r8, r9, r10, r11} */
/* @0x2a74a6 ldrb r3, [r3, #0x4] */
/* @0x2a74a8 str r0, [sp, #0x8] */
/* @0x2a74aa strb.w r3, [sp, #0xc] */
/* @0x2a74ac ldm r12!, {r2, r3, r12, sp} */
/* @0x2a74ae ldm.w r12!, {r0, r1, r2, r3} */
/* @0x2a74b0 strgt r0, [pc], -pc */
/* @0x2a74b2 stm r6!, {r0, r1, r2, r3} */
/* @0x2a74b4 ldm.w r12, {r0, r1, r2} */
/* @0x2a74b8 stm.w r6, {r0, r1, r2} */
/* @0x2a74bc add r6, sp, #0x2c */
/* @0x2a74be ldm r7!, {r0, r1, r2, r3} */
/* @0x2a74c0 stm r6!, {r0, r1, r2, r3} */
/* @0x2a74c2 ldm.w r7, {r0, r1, r2} */
/* @0x2a74c4 stm r6, {r0, r1, r2} */
/* @0x2a74c6 stm.w r6, {r0, r1, r2} */
/* @0x2a74c8 .word 0x2c000007 */
/* @0x2a74ca cmp r4, #0x0 */
/* @0x2a74cc beq.w 0x2a77c6 <png_read_row+0x33e> */
/* @0x2a74d0 ldr.w r3, [r4, #0x130] */
/* @0x2a74d4 lsls r3, r3, #0x19 */
/* @0x2a74d6 bmi 0x2a74de <png_read_row+0x56> */
/* @0x2a74d8 mov r0, r4 */
/* @0x2a74da bl 0x2ae494 <png_read_start_row> */
/* @0x2a74dc .word 0xf894ffdb */
/* @0x2a74de ldrb.w r3, [r4, #0x1e7] */
/* @0x2a74e0 blhs 0x2b3c84 <jpeg_finish_output+0x494> */
/* @0x2a74e2 cmp r3, #0x0 */
/* @0x2a74e4 beq 0x2a759c <png_read_row+0x114> */
/* @0x2a74e6 ldr.w r3, [r4, #0x134] */
/* @0x2a74e8 .word 0x079f3134 */
/* @0x2a74ea lsls r7, r3, #0x1e */
/* @0x2a74ec bpl 0x2a759c <png_read_row+0x114> */
/* @0x2a74ee ldrb.w r2, [r4, #0x1e8] */
/* @0x2a74f0 .word 0xf8d421e8 */
/* @0x2a74f2 ldr.w r3, [r4, #0x1a8] */
/* @0x2a74f4 bhs 0x3f3b9c <VS_Common+0x840> */
/* @0x2a74f6 cmp r2, #0x5 */
/* @0x2a74f8 bhi 0x2a7598 <png_read_row+0x110> */
/* @0x2a74fa tbb [pc, r2] */
/* @0x2a74fc mrsne pc, apsr */
/* @0x2a74fe asrs r3, r0, #0x4 */
/* @0x2a7500 cmp r1, #0x1d */
/* @0x2a7502 asrs r5, r6 */
/* @0x2a7504 lsls r6, r3, #0x1d */
/* @0x2a7506 beq 0x2a759c <png_read_row+0x114> */
/* @0x2a7508 cbz r5, 0x2a7514 <png_read_row+0x8c> */
/* @0x2a750a ldr r2, [sp, #0x10] */
/* @0x2a750c mov r0, r4 */
/* @0x2a750e mov r1, r5 */
/* @0x2a7510 bl 0x2adc30 <png_combine_row> */
/* @0x2a7514 mov r0, r4 */
/* @0x2a7516 add sp, #0x4c */
/* @0x2a7518 pop.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a751c b.w 0x2ae25c <png_read_finish_row> */
/* @0x2a7520 lsls r0, r3, #0x1d */
/* @0x2a7522 bne 0x2a752c <png_read_row+0xa4> */
/* @0x2a7524 ldr.w r3, [r4, #0x18c] */
/* @0x2a7528 cmp r3, #0x4 */
/* @0x2a752a bhi 0x2a759c <png_read_row+0x114> */
/* @0x2a752c cmp r5, #0x0 */
/* @0x2a752e beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7530 mov r0, r4 */
/* @0x2a7532 mov r1, r5 */
/* @0x2a7534 ldr r2, [sp, #0x14] */
/* @0x2a7536 b 0x2a7510 <png_read_row+0x88> */
/* @0x2a7538 and r2, r3, #0x7 */
/* @0x2a753c cmp r2, #0x4 */
/* @0x2a753e beq 0x2a759c <png_read_row+0x114> */
/* @0x2a7540 cmp r5, #0x0 */
/* @0x2a7542 beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7544 lsls r1, r3, #0x1d */
/* @0x2a7546 bpl 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7548 mov r0, r4 */
/* @0x2a754a mov r1, r5 */
/* @0x2a754c ldr r2, [sp, #0x18] */
/* @0x2a754e b 0x2a7510 <png_read_row+0x88> */
/* @0x2a7550 lsls r2, r3, #0x1e */
/* @0x2a7552 bne 0x2a755c <png_read_row+0xd4> */
/* @0x2a7554 ldr.w r3, [r4, #0x18c] */
/* @0x2a7558 cmp r3, #0x2 */
/* @0x2a755a bhi 0x2a759c <png_read_row+0x114> */
/* @0x2a755c cmp r5, #0x0 */
/* @0x2a755e beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7560 mov r0, r4 */
/* @0x2a7562 mov r1, r5 */
/* @0x2a7564 ldr r2, [sp, #0x1c] */
/* @0x2a7566 b 0x2a7510 <png_read_row+0x88> */
/* @0x2a7568 and r2, r3, #0x3 */
/* @0x2a756c cmp r2, #0x2 */
/* @0x2a756e beq 0x2a759c <png_read_row+0x114> */
/* @0x2a7570 cmp r5, #0x0 */
/* @0x2a7572 beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7574 lsls r3, r3, #0x1e */
/* @0x2a7576 bpl 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7578 mov r0, r4 */
/* @0x2a757a mov r1, r5 */
/* @0x2a757c ldr r2, [sp, #0x20] */
/* @0x2a757e b 0x2a7510 <png_read_row+0x88> */
/* @0x2a7580 lsls r7, r3, #0x1f */
/* @0x2a7582 bmi 0x2a758c <png_read_row+0x104> */
/* @0x2a7584 ldr.w r3, [r4, #0x18c] */
/* @0x2a7588 cmp r3, #0x1 */
/* @0x2a758a bhi 0x2a759c <png_read_row+0x114> */
/* @0x2a758c cmp r5, #0x0 */
/* @0x2a758e beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7590 mov r0, r4 */
/* @0x2a7592 mov r1, r5 */
/* @0x2a7594 ldr r2, [sp, #0x24] */
/* @0x2a7596 b 0x2a7510 <png_read_row+0x88> */
/* @0x2a7598 lsls r6, r3, #0x1f */
/* @0x2a759a bpl 0x2a7514 <png_read_row+0x8c> */
/* @0x2a759c ldr.w r3, [r4, #0x12c] */
/* @0x2a75a0 lsls r0, r3, #0x1d */
/* @0x2a75a2 bmi 0x2a75ae <png_read_row+0x126> */
/* @0x2a75a4 ldr r1, [pc, #0x228] */
/* @0x2a75a6 mov r0, r4 */
/* @0x2a75a8 add r1, pc */
/* @0x2a75aa bl 0x2a642c <png_error> */
/* @0x2a75ac .word 0xf8d4ff3f */
/* @0x2a75ae ldr.w r3, [r4, #0x1b0] */
/* @0x2a75b0 .word 0xf8d431b0 */
/* @0x2a75b2 ldr.w r2, [r4, #0x1a4] */
/* @0x2a75b4 .word 0xf8c421a4 */
/* @0x2a75b6 str.w r3, [r4, #0x144] */
/* @0x2a75b8 .word 0xf8943144 */
/* @0x2a75ba ldrb.w r3, [r4, #0x1ed] */
/* @0x2a75bc blhs 0x473d78 <g_RomDisk+0x7c558> */
/* @0x2a75be cmp r3, #0x7 */
/* @0x2a75c0 bls 0x2a75c8 <png_read_row+0x140> */
/* @0x2a75c2 lsrs r3, r3, #0x3 */
/* @0x2a75c4 muls r3, r2, r3 */
/* @0x2a75c6 b 0x2a75ce <png_read_row+0x146> */
/* @0x2a75c8 muls r3, r2, r3 */
/* @0x2a75ca adds r3, #0x7 */
/* @0x2a75cc lsrs r3, r3, #0x3 */
/* @0x2a75ce add r6, sp, #0x8 */
/* @0x2a75d0 adds r3, #0x1 */
/* @0x2a75d2 str.w r3, [r4, #0x148] */
/* @0x2a75d4 .word 0xf8d43148 */
/* @0x2a75d6 ldr.w r3, [r4, #0x13c] */
/* @0x2a75d8 bllt 0xfeb73ad0 <b2_toiTime+0xfffffffffe41a62c> */
/* @0x2a75da cbnz r3, 0x2a7646 <png_read_row+0x1be> */
/* @0x2a75dc ldr.w r9, [pc, #0x1f4] */
/* @0x2a75e0 add r9, pc */
/* @0x2a75e2 add.w r7, r4, #0x1e0 */
/* @0x2a75e4 .word 0xf8d477f0 */
/* @0x2a75e6 ldr.w r3, [r4, #0x1d0] */
/* @0x2a75e8 stmiblt r3!, {r4, r6, r7, r8, r12, sp} */
/* @0x2a75ea cbnz r3, 0x2a7616 <png_read_row+0x18e> */
/* @0x2a75ec mov r1, r3 */
/* @0x2a75ee mov r0, r4 */
/* @0x2a75f0 bl 0x2abc94 <png_crc_finish> */
/* @0x2a75f4 mov r0, r4 */
/* @0x2a75f6 bl 0x2adbc4 <png_read_chunk_header> */
/* @0x2a75f8 ldrtmi pc, [r1], -r5, ror #21 */
/* @0x2a75fa mov r1, r6 */
/* @0x2a75fc movs r2, #0x4 */
/* @0x2a75fe str.w r0, [r4, #0x1d0] */
/* @0x2a7600 .word 0x463801d0 */
/* @0x2a7602 mov r0, r7 */
/* @0x2a7604 blx 0xb6c40 <memcmp@plt> */
/* @0x2a7608 cmp r0, #0x0 */
/* @0x2a760a beq 0x2a75e6 <png_read_row+0x15e> */
/* @0x2a760c mov r0, r4 */
/* @0x2a760e mov r1, r9 */
/* @0x2a7610 bl 0x2a642c <png_error> */
/* @0x2a7614 b 0x2a75e2 <png_read_row+0x15a> */
/* @0x2a7616 ldr.w r2, [r4, #0x174] */
/* @0x2a7618 qsub16mi r2, r0, r4 */
/* @0x2a761a mov r0, r4 */
/* @0x2a761c ldr.w r1, [r4, #0x170] */
/* @0x2a7620 cmp r2, r3 */
/* @0x2a7622 str.w r2, [r4, #0x13c] */
/* @0x2a7624 .word 0xf8c4213c */
/* @0x2a7626 str.w r1, [r4, #0x138] */
/* @0x2a7628 svclt #0x881138 */
/* @0x2a762a it hi */
/* @0x2a762c strhi.w r3, [r4, #0x13c] */
/* @0x2a7630 ldr.w r2, [r4, #0x13c] */
/* @0x2a7634 bl 0x2abc0c <png_crc_read> */
/* @0x2a7638 ldr.w r2, [r4, #0x1d0] */
/* @0x2a763c ldr.w r3, [r4, #0x13c] */
/* @0x2a7640 subs r3, r2, r3 */
/* @0x2a7642 str.w r3, [r4, #0x1d0] */
/* @0x2a7644 .word 0xf50431d0 */
/* @0x2a7646 add.w r0, r4, #0x138 */
/* @0x2a7648 swphs r7, r12, [r1] */
/* @0x2a764a movs r1, #0x1 */
/* @0x2a764c blx 0xb69dc <inflate@plt> */
/* @0x2a7650 cmp r0, #0x1 */
/* @0x2a7652 bne 0x2a768a <png_read_row+0x202> */
/* @0x2a7654 ldr.w r3, [r4, #0x148] */
/* @0x2a7658 cbnz r3, 0x2a7666 <png_read_row+0x1de> */
/* @0x2a765a ldr.w r3, [r4, #0x13c] */
/* @0x2a765c ldmdblt r3, {r2, r3, r4, r5, r8, r12, sp} */
/* @0x2a765e cbnz r3, 0x2a7666 <png_read_row+0x1de> */
/* @0x2a7660 ldr.w r3, [r4, #0x1d0] */
/* @0x2a7664 cbz r3, 0x2a7670 <png_read_row+0x1e8> */
/* @0x2a7666 ldr r1, [pc, #0x170] */
/* @0x2a7668 mov r0, r4 */
/* @0x2a766a add r1, pc */
/* @0x2a766c bl 0x2a642c <png_error> */
/* @0x2a7670 ldr.w r3, [r4, #0x12c] */
/* @0x2a7674 orr r3, r3, #0x8 */
/* @0x2a7678 str.w r3, [r4, #0x12c] */
/* @0x2a767c ldr.w r3, [r4, #0x130] */
/* @0x2a7680 orr r3, r3, #0x20 */
/* @0x2a7684 str.w r3, [r4, #0x130] */
/* @0x2a7688 b 0x2a76a8 <png_read_row+0x220> */
/* @0x2a768a cbz r0, 0x2a76a0 <png_read_row+0x218> */
/* @0x2a768c ldr.w r3, [r4, #0x150] */
/* @0x2a7690 cbnz r3, 0x2a7698 <png_read_row+0x210> */
/* @0x2a7692 ldr r1, [pc, #0x148] */
/* @0x2a7694 add r1, pc */
/* @0x2a7696 b 0x2a769a <png_read_row+0x212> */
/* @0x2a7698 mov r1, r3 */
/* @0x2a769a mov r0, r4 */
/* @0x2a769c bl 0x2a642c <png_error> */
/* @0x2a76a0 ldr.w r3, [r4, #0x148] */
/* @0x2a76a4 cmp r3, #0x0 */
/* @0x2a76a6 bne 0x2a75d6 <png_read_row+0x14e> */
/* @0x2a76a8 ldrb.w r3, [r4, #0x1ea] */
/* @0x2a76ac ldr.w r2, [r4, #0x1a4] */
/* @0x2a76b0 strb.w r3, [r4, #0x1cc] */
/* @0x2a76b4 ldrb.w r3, [r4, #0x1ee] */
/* @0x2a76b8 str.w r2, [r4, #0x1c4] */
/* @0x2a76bc strb.w r3, [r4, #0x1ce] */
/* @0x2a76c0 ldrb.w r3, [r4, #0x1eb] */
/* @0x2a76c4 strb.w r3, [r4, #0x1cd] */
/* @0x2a76c8 ldrb.w r3, [r4, #0x1ed] */
/* @0x2a76cc cmp r3, #0x7 */
/* @0x2a76ce strb.w r3, [r4, #0x1cf] */
/* @0x2a76d0 stmdble r2, {r0, r1, r2, r3, r6, r7, r8, r12, sp} */
/* @0x2a76d2 bls 0x2a76da <png_read_row+0x252> */
/* @0x2a76d4 lsrs r3, r3, #0x3 */
/* @0x2a76d6 muls r2, r3, r2 */
/* @0x2a76d8 b 0x2a76e0 <png_read_row+0x258> */
/* @0x2a76da muls r2, r3, r2 */
/* @0x2a76dc adds r2, #0x7 */
/* @0x2a76de lsrs r2, r2, #0x3 */
/* @0x2a76e0 str.w r2, [r4, #0x1c8] */
/* @0x2a76e4 ldr.w r2, [r4, #0x1b0] */
/* @0x2a76e8 ldrb r1, [r2] */
/* @0x2a76ea cbz r1, 0x2a7700 <png_read_row+0x278> */
/* @0x2a76ec ldr.w r3, [r4, #0x1ac] */
/* @0x2a76f0 mov r0, r4 */
/* @0x2a76f2 str r1, [sp] */
/* @0x2a76f4 adds r2, #0x1 */
/* @0x2a76f6 add.w r1, r4, #0x1c4 */
/* @0x2a76f8 movwlo r7, #0x11e2 */
/* @0x2a76fa adds r3, #0x1 */
/* @0x2a76fc bl 0x2ae148 <png_read_filter_row> */
/* @0x2a7700 ldr.w r2, [r4, #0x19c] */
/* @0x2a7704 ldr.w r1, [r4, #0x1b0] */
/* @0x2a7708 ldr.w r0, [r4, #0x1ac] */
/* @0x2a770c adds r2, #0x1 */
/* @0x2a770e blx 0xb65bc <memcpy@plt> */
/* @0x2a7710 .word 0xf8d4ef56 */
/* @0x2a7712 ldr.w r3, [r4, #0x2dc] */
/* @0x2a7714 smmlseq r9, r12, r2, r3 */
/* @0x2a7716 lsls r1, r3, #0x1d */
/* @0x2a7718 bpl 0x2a7730 <png_read_row+0x2a8> */
/* @0x2a771a ldrb.w r3, [r4, #0x2e4] */
/* @0x2a771c blhs 0x12b42b4 <b2_toiTime+0xb5ae10> */
/* @0x2a771e cmp r3, #0x40 */
/* @0x2a7720 bne 0x2a7730 <png_read_row+0x2a8> */
/* @0x2a7722 ldr.w r1, [r4, #0x1b0] */
/* @0x2a7724 .word 0xf50411b0 */
/* @0x2a7726 add.w r0, r4, #0x1c4 */
/* @0x2a7728 smlattlo r1, r2, r0, r7 */
/* @0x2a772a adds r1, #0x1 */
/* @0x2a772c bl 0x2ab9f8 <png_do_read_intrapixel> */
/* @0x2a7730 ldr.w r3, [r4, #0x134] */
/* @0x2a7734 cbnz r3, 0x2a773e <png_read_row+0x2b6> */
/* @0x2a7736 ldr.w r3, [r4, #0x130] */
/* @0x2a7738 subseq r3, r10, #48, #2 */
/* @0x2a773a lsls r2, r3, #0x9 */
/* @0x2a773c bpl 0x2a7744 <png_read_row+0x2bc> */
/* @0x2a773e mov r0, r4 */
/* @0x2a7740 bl 0x2aa92c <png_do_read_transformations> */
/* @0x2a7744 ldrb.w r3, [r4, #0x1e7] */
/* @0x2a7748 cbz r3, 0x2a7792 <png_read_row+0x30a> */
/* @0x2a774a ldr.w r3, [r4, #0x134] */
/* @0x2a774c .word 0x079b3134 */
/* @0x2a774e lsls r3, r3, #0x1e */
/* @0x2a7750 bpl 0x2a7792 <png_read_row+0x30a> */
/* @0x2a7752 ldrb.w r3, [r4, #0x1e8] */
/* @0x2a7754 blhs 0x3f3efc <VS_Common+0xba0> */
/* @0x2a7756 cmp r3, #0x5 */
/* @0x2a7758 bhi 0x2a7760 <png_read_row+0x2d8> */
/* @0x2a775a mov r0, r4 */
/* @0x2a775c bl 0x2ade1c <png_do_read_interlace> */
/* @0x2a7760 cbz r5, 0x2a7778 <png_read_row+0x2f0> */
/* @0x2a7762 ldrb.w r3, [r4, #0x1e8] */
/* @0x2a7764 bge 0x733f0c <g_SWFvertbuff+0x60e44> */
/* @0x2a7766 add r2, sp, #0x48 */
/* @0x2a7768 mov r0, r4 */
/* @0x2a776a mov r1, r5 */
/* @0x2a776c add.w r3, r2, r3, lsl #2 */
/* @0x2a7770 ldr r2, [r3, #-56] */
/* @0x2a7774 bl 0x2adc30 <png_combine_row> */
/* @0x2a7778 cmp.w r8, #0x0 */
/* @0x2a777c beq 0x2a77ae <png_read_row+0x326> */
/* @0x2a777e ldrb.w r3, [r4, #0x1e8] */
/* @0x2a7780 ldmdage r2, {r3, r5, r6, r7, r8, r12, sp} */
/* @0x2a7782 add r0, sp, #0x48 */
/* @0x2a7784 mov r1, r8 */
/* @0x2a7786 add.w r3, r0, r3, lsl #2 */
/* @0x2a7788 strtmi r0, [r0], -r3, lsl #7 */
/* @0x2a778a mov r0, r4 */
/* @0x2a778c ldr r2, [r3, #-28] */
/* @0x2a7790 b 0x2a77aa <png_read_row+0x322> */
/* @0x2a7792 cmp.w r8, #0x0 */
/* @0x2a7794 andle r0, r4, r0, lsl #30 */
/* @0x2a7796 beq 0x2a77a2 <png_read_row+0x31a> */
/* @0x2a7798 mov r0, r4 */
/* @0x2a779a mov r1, r8 */
/* @0x2a779c movs r2, #0xff */
/* @0x2a779e bl 0x2adc30 <png_combine_row> */
/* @0x2a77a0 .word 0xb125fa47 */
/* @0x2a77a2 cbz r5, 0x2a77ae <png_read_row+0x326> */
/* @0x2a77a4 mov r0, r4 */
/* @0x2a77a6 mov r1, r5 */
/* @0x2a77a8 movs r2, #0xff */
/* @0x2a77aa bl 0x2adc30 <png_combine_row> */
/* @0x2a77ac strtmi pc, [r0], -r1, asr #20 */
/* @0x2a77ae mov r0, r4 */
/* @0x2a77b0 bl 0x2ae25c <png_read_finish_row> */
/* @0x2a77b4 ldr.w r3, [r4, #0x25c] */
/* @0x2a77b8 cbz r3, 0x2a77c6 <png_read_row+0x33e> */
/* @0x2a77ba mov r0, r4 */
/* @0x2a77bc ldr.w r1, [r4, #0x1a8] */
/* @0x2a77c0 ldrb.w r2, [r4, #0x1e8] */
/* @0x2a77c4 blx r3 */
/* @0x2a77c6 add sp, #0x4c */
/* @0x2a77c8 pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2a77cc strh r2, [r6, #0x22] */
/* @0x2a77ce movs r6, r1 */
/* @0x2a77d0 strh r3, [r7, r2] */
/* @0x2a77d2 movs r6, r1 */
/* @0x2a77d4 strh r4, [r4, r2] */
/* @0x2a77d6 movs r6, r1 */
/* @0x2a77d8 strh r0, [r6, r0] */
/* @0x2a77da movs r6, r1 */
/* @0x2a77dc str r3, [r7, r6] */
/* @0x2a77de movs r6, r1 */
