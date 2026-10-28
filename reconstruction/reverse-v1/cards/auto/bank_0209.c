/* libyoyo.so 覆盖卡组 0209
 * 函数 0x234a80..0x235ad0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x234a80 · ogg_stream_pageout_fill · size=104 · insn=26 */
/* @0x234a80 push {r4, r5, r6, lr} */
/* @0x234a84 mov r6, r1 */
/* @0x234a88 mov r5, r2 */
/* @0x234a8c mov r4, r0 */
/* @0x234a90 bl 0x23412c <ogg_stream_check> */
/* @0x234a94 cmp r0, #0 */
/* @0x234a98 bne 0x234ae0 <ogg_stream_pageout_fill+0x60> */
/* @0x234a9c ldr r3, [r4, #0x148] */
/* @0x234aa0 ldr r2, [r4, #0x1c] */
/* @0x234aa4 cmp r3, #0 */
/* @0x234aa8 bne 0x234ad4 <ogg_stream_pageout_fill+0x54> */
/* @0x234aac cmp r2, #0 */
/* @0x234ab0 beq 0x234ac0 <ogg_stream_pageout_fill+0x40> */
/* @0x234ab4 ldr r2, [r4, #0x14c] */
/* @0x234ab8 rsbs r2, r2, #1 */
/* @0x234abc movlo r2, #0 */
/* @0x234ac0 mov r0, r4 */
/* @0x234ac4 mov r1, r6 */
/* @0x234ac8 mov r3, r5 */
/* @0x234acc pop {r4, r5, r6, lr} */
/* @0x234ad0 b 0x234434 <ogg_page_checksum_set+0xe0> */
/* @0x234ad4 adds r2, r2, #0 */
/* @0x234ad8 movne r2, #1 */
/* @0x234adc b 0x234ac0 <ogg_stream_pageout_fill+0x40> */
/* @0x234ae0 mov r0, #0 */
/* @0x234ae4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x234ae8 · ogg_stream_eos · size=28 · insn=7 */
/* @0x234ae8 push {r4, lr} */
/* @0x234aec mov r4, r0 */
/* @0x234af0 bl 0x23412c <ogg_stream_check> */
/* @0x234af4 cmp r0, #0 */
/* @0x234af8 ldreq r0, [r4, #0x148] */
/* @0x234afc movne r0, #1 */
/* @0x234b00 pop {r4, pc} */

/* ── FUNC 0x234b04 · ogg_sync_init · size=40 · insn=10 */
/* @0x234b04 push {r3, lr} */
/* @0x234b08 subs r3, r0, #0 */
/* @0x234b0c beq 0x234b24 <ogg_sync_init+0x20> */
/* @0x234b10 mvn r2, #0 */
/* @0x234b14 mov r1, #0 */
/* @0x234b18 str r2, [r3, #0x4] */
/* @0x234b1c mov r2, #28 */
/* @0x234b20 bl 0xb65b0 <memset@plt> */
/* @0x234b24 mov r0, #0 */
/* @0x234b28 pop {r3, pc} */

/* ── FUNC 0x234b2c · ogg_sync_clear · size=52 · insn=13 */
/* @0x234b2c push {r4, lr} */
/* @0x234b30 subs r4, r0, #0 */
/* @0x234b34 beq 0x234b58 <ogg_sync_clear+0x2c> */
/* @0x234b38 ldr r0, [r4] */
/* @0x234b3c cmp r0, #0 */
/* @0x234b40 beq 0x234b48 <ogg_sync_clear+0x1c> */
/* @0x234b44 bl 0xb655c <free@plt> */
/* @0x234b48 mov r0, r4 */
/* @0x234b4c mov r1, #0 */
/* @0x234b50 mov r2, #28 */
/* @0x234b54 bl 0xb65b0 <memset@plt> */
/* @0x234b58 mov r0, #0 */
/* @0x234b5c pop {r4, pc} */

/* ── FUNC 0x234b60 · ogg_sync_destroy · size=32 · insn=8 */
/* @0x234b60 push {r4, lr} */
/* @0x234b64 subs r4, r0, #0 */
/* @0x234b68 beq 0x234b78 <ogg_sync_destroy+0x18> */
/* @0x234b6c bl 0x234b2c <ogg_sync_clear> */
/* @0x234b70 mov r0, r4 */
/* @0x234b74 bl 0xb655c <free@plt> */
/* @0x234b78 mov r0, #0 */
/* @0x234b7c pop {r4, pc} */

/* ── FUNC 0x234b80 · ogg_sync_check · size=12 · insn=3 */
/* @0x234b80 ldr r0, [r0, #0x4] */
/* @0x234b84 asr r0, r0, #31 */
/* @0x234b88 bx lr */

/* ── FUNC 0x234b8c · ogg_sync_buffer · size=200 · insn=50 */
/* @0x234b8c push {r4, r5, r6, lr} */
/* @0x234b90 mov r5, r1 */
/* @0x234b94 mov r4, r0 */
/* @0x234b98 bl 0x234b80 <ogg_sync_check> */
/* @0x234b9c cmp r0, #0 */
/* @0x234ba0 bne 0x234c2c <ogg_sync_buffer+0xa0> */
/* @0x234ba4 ldr r1, [r4, #0xc] */
/* @0x234ba8 ldr r2, [r4, #0x8] */
/* @0x234bac cmp r1, #0 */
/* @0x234bb0 beq 0x234bdc <ogg_sync_buffer+0x50> */
/* @0x234bb4 rsb r2, r1, r2 */
/* @0x234bb8 str r2, [r4, #0x8] */
/* @0x234bbc cmp r2, #0 */
/* @0x234bc0 ble 0x234bd4 <ogg_sync_buffer+0x48> */
/* @0x234bc4 ldr r0, [r4] */
/* @0x234bc8 add r1, r0, r1 */
/* @0x234bcc bl 0xb6694 <memmove@plt> */
/* @0x234bd0 ldr r2, [r4, #0x8] */
/* @0x234bd4 mov r3, #0 */
/* @0x234bd8 str r3, [r4, #0xc] */
/* @0x234bdc ldr r3, [r4, #0x4] */
/* @0x234be0 ldr r0, [r4] */
/* @0x234be4 rsb r3, r2, r3 */
/* @0x234be8 cmp r3, r5 */
/* @0x234bec bge 0x234c24 <ogg_sync_buffer+0x98> */
/* @0x234bf0 cmp r0, #0 */
/* @0x234bf4 add r5, r5, r2 */
/* @0x234bf8 add r5, r5, #4096 */
/* @0x234bfc beq 0x234c34 <ogg_sync_buffer+0xa8> */
/* @0x234c00 mov r1, r5 */
/* @0x234c04 bl 0xb6c28 <realloc@plt> */
/* @0x234c08 mov r6, r0 */
/* @0x234c0c cmp r6, #0 */
/* @0x234c10 beq 0x234c44 <ogg_sync_buffer+0xb8> */
/* @0x234c14 ldr r2, [r4, #0x8] */
/* @0x234c18 mov r0, r6 */
/* @0x234c1c str r6, [r4] */
/* @0x234c20 str r5, [r4, #0x4] */
/* @0x234c24 add r0, r0, r2 */
/* @0x234c28 pop {r4, r5, r6, pc} */
/* @0x234c2c mov r0, #0 */
/* @0x234c30 pop {r4, r5, r6, pc} */
/* @0x234c34 mov r0, r5 */
/* @0x234c38 bl 0xb6544 <malloc@plt> */
/* @0x234c3c mov r6, r0 */
/* @0x234c40 b 0x234c0c <ogg_sync_buffer+0x80> */
/* @0x234c44 mov r0, r4 */
/* @0x234c48 bl 0x234b2c <ogg_sync_clear> */
/* @0x234c4c mov r0, r6 */
/* @0x234c50 pop {r4, r5, r6, pc} */

/* ── FUNC 0x234c54 · ogg_sync_wrote · size=60 · insn=15 */
/* @0x234c54 push {r3, r4, r5, lr} */
/* @0x234c58 mov r5, r1 */
/* @0x234c5c mov r4, r0 */
/* @0x234c60 bl 0x234b80 <ogg_sync_check> */
/* @0x234c64 cmp r0, #0 */
/* @0x234c68 bne 0x234c88 <ogg_sync_wrote+0x34> */
/* @0x234c6c ldr r1, [r4, #0x8] */
/* @0x234c70 ldr r3, [r4, #0x4] */
/* @0x234c74 add r1, r5, r1 */
/* @0x234c78 cmp r1, r3 */
/* @0x234c7c bgt 0x234c88 <ogg_sync_wrote+0x34> */
/* @0x234c80 str r1, [r4, #0x8] */
/* @0x234c84 pop {r3, r4, r5, pc} */
/* @0x234c88 mvn r0, #0 */
/* @0x234c8c pop {r3, r4, r5, pc} */

/* ── FUNC 0x234c90 · ogg_sync_pageseek · size=444 · insn=111 */
/* @0x234c90 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x234c94 sub sp, sp, #28 */
/* @0x234c98 mov r4, r0 */
/* @0x234c9c mov r8, r1 */
/* @0x234ca0 ldr r5, [r0] */
/* @0x234ca4 ldr r6, [r0, #0xc] */
/* @0x234ca8 ldr r7, [r0, #0x8] */
/* @0x234cac bl 0x234b80 <ogg_sync_check> */
/* @0x234cb0 cmp r0, #0 */
/* @0x234cb4 bne 0x234cdc <ogg_sync_pageseek+0x4c> */
/* @0x234cb8 ldr r0, [r4, #0x14] */
/* @0x234cbc add r5, r5, r6 */
/* @0x234cc0 rsb r6, r6, r7 */
/* @0x234cc4 cmp r0, #0 */
/* @0x234cc8 beq 0x234ce8 <ogg_sync_pageseek+0x58> */
/* @0x234ccc ldr r3, [r4, #0x18] */
/* @0x234cd0 add r3, r0, r3 */
/* @0x234cd4 cmp r6, r3 */
/* @0x234cd8 bge 0x234d54 <ogg_sync_pageseek+0xc4> */
/* @0x234cdc mov r0, #0 */
/* @0x234ce0 add sp, sp, #28 */
/* @0x234ce4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x234ce8 cmp r6, #26 */
/* @0x234cec ble 0x234cdc <ogg_sync_pageseek+0x4c> */
/* @0x234cf0 ldr r1, [pc, #0x150] */
/* @0x234cf4 mov r0, r5 */
/* @0x234cf8 mov r2, #4 */
/* @0x234cfc add r1, pc, r1 */
/* @0x234d00 bl 0xb6c40 <memcmp@plt> */
/* @0x234d04 cmp r0, #0 */
/* @0x234d08 bne 0x234e08 <ogg_sync_pageseek+0x178> */
/* @0x234d0c ldrb r3, [r5, #0x1a] */
/* @0x234d10 add r12, r3, #27 */
/* @0x234d14 cmp r6, r12 */
/* @0x234d18 blt 0x234cdc <ogg_sync_pageseek+0x4c> */
/* @0x234d1c cmp r3, #0 */
/* @0x234d20 ldr r3, [r4, #0x18] */
/* @0x234d24 addne r2, r5, #26 */
/* @0x234d28 beq 0x234d48 <ogg_sync_pageseek+0xb8> */
/* @0x234d2c ldrb r1, [r2, #0x1]! */
/* @0x234d30 add r0, r0, #1 */
/* @0x234d34 add r3, r3, r1 */
/* @0x234d38 str r3, [r4, #0x18] */
/* @0x234d3c ldrb r1, [r5, #0x1a] */
/* @0x234d40 cmp r1, r0 */
/* @0x234d44 bgt 0x234d2c <ogg_sync_pageseek+0x9c> */
/* @0x234d48 mov r0, r12 */
/* @0x234d4c str r12, [r4, #0x14] */
/* @0x234d50 b 0x234cd0 <ogg_sync_pageseek+0x40> */
/* @0x234d54 mov r7, r5 */
/* @0x234d58 mov r3, #0 */
/* @0x234d5c ldr r0, [r7, #0x16]! */
/* @0x234d60 add r9, sp, #4 */
/* @0x234d64 strb r3, [r5, #0x16] */
/* @0x234d68 strb r3, [r5, #0x17] */
/* @0x234d6c strb r3, [r5, #0x18] */
/* @0x234d70 strb r3, [r5, #0x19] */
/* @0x234d74 ldr r3, [r4, #0x14] */
/* @0x234d78 ldr r2, [r4, #0x18] */
/* @0x234d7c str r0, [sp, #0x4] */
/* @0x234d80 add r0, sp, #8 */
/* @0x234d84 add r1, r5, r3 */
/* @0x234d88 str r3, [sp, #0xc] */
/* @0x234d8c str r1, [sp, #0x10] */
/* @0x234d90 str r2, [sp, #0x14] */
/* @0x234d94 str r5, [sp, #0x8] */
/* @0x234d98 bl 0x234354 <ogg_page_checksum_set> */
/* @0x234d9c mov r0, r9 */
/* @0x234da0 mov r1, r7 */
/* @0x234da4 mov r2, #4 */
/* @0x234da8 bl 0xb6c40 <memcmp@plt> */
/* @0x234dac cmp r0, #0 */
/* @0x234db0 ldrne r0, [r9] */
/* @0x234db4 strne r0, [r5, #0x16] */
/* @0x234db8 bne 0x234e08 <ogg_sync_pageseek+0x178> */
/* @0x234dbc ldr r0, [r4, #0x18] */
/* @0x234dc0 cmp r8, #0 */
/* @0x234dc4 ldr r3, [r4, #0x14] */
/* @0x234dc8 ldr r2, [r4, #0xc] */
/* @0x234dcc ldr r1, [r4] */
/* @0x234dd0 strne r0, [r8, #0xc] */
/* @0x234dd4 add r0, r3, r0 */
/* @0x234dd8 add r1, r1, r2 */
/* @0x234ddc strne r3, [r8, #0x4] */
/* @0x234de0 strne r1, [r8] */
/* @0x234de4 add r2, r2, r0 */
/* @0x234de8 addne r1, r1, r3 */
/* @0x234dec mov r3, #0 */
/* @0x234df0 strne r1, [r8, #0x8] */
/* @0x234df4 str r3, [r4, #0x10] */
/* @0x234df8 str r2, [r4, #0xc] */
/* @0x234dfc str r3, [r4, #0x14] */
/* @0x234e00 str r3, [r4, #0x18] */
/* @0x234e04 b 0x234ce0 <ogg_sync_pageseek+0x50> */
/* @0x234e08 mov r3, #0 */
/* @0x234e0c sub r2, r6, #1 */
/* @0x234e10 str r3, [r4, #0x14] */
/* @0x234e14 add r0, r5, #1 */
/* @0x234e18 str r3, [r4, #0x18] */
/* @0x234e1c mov r1, #79 */
/* @0x234e20 bl 0xb66a0 <memchr@plt> */
/* @0x234e24 ldr r2, [r4] */
/* @0x234e28 subs r3, r0, #0 */
/* @0x234e2c ldreq r3, [r4, #0x8] */
/* @0x234e30 addeq r3, r2, r3 */
/* @0x234e34 rsb r0, r3, r5 */
/* @0x234e38 rsb r3, r2, r3 */
/* @0x234e3c str r3, [r4, #0xc] */
/* @0x234e40 add sp, sp, #28 */
/* @0x234e44 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x234e48 andseq r0, r2, r0, ror #7 */

/* ── FUNC 0x234e4c · ogg_sync_pageout · size=96 · insn=24 */
/* @0x234e4c push {r3, r4, r5, lr} */
/* @0x234e50 mov r5, r1 */
/* @0x234e54 mov r4, r0 */
/* @0x234e58 bl 0x234b80 <ogg_sync_check> */
/* @0x234e5c cmp r0, #0 */
/* @0x234e60 beq 0x234e78 <ogg_sync_pageout+0x2c> */
/* @0x234e64 b 0x234e94 <ogg_sync_pageout+0x48> */
/* @0x234e68 beq 0x234e94 <ogg_sync_pageout+0x48> */
/* @0x234e6c ldr r3, [r4, #0x10] */
/* @0x234e70 cmp r3, #0 */
/* @0x234e74 beq 0x234e9c <ogg_sync_pageout+0x50> */
/* @0x234e78 mov r0, r4 */
/* @0x234e7c mov r1, r5 */
/* @0x234e80 bl 0x234c90 <ogg_sync_pageseek> */
/* @0x234e84 cmp r0, #0 */
/* @0x234e88 ble 0x234e68 <ogg_sync_pageout+0x1c> */
/* @0x234e8c mov r0, #1 */
/* @0x234e90 pop {r3, r4, r5, pc} */
/* @0x234e94 mov r0, #0 */
/* @0x234e98 pop {r3, r4, r5, pc} */
/* @0x234e9c mov r3, #1 */
/* @0x234ea0 mvn r0, #0 */
/* @0x234ea4 str r3, [r4, #0x10] */
/* @0x234ea8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x234eac · ogg_stream_pagein · size=956 · insn=239 */
/* @0x234eac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x234eb0 mov r4, r0 */
/* @0x234eb4 sub sp, sp, #44 */
/* @0x234eb8 mov r0, r1 */
/* @0x234ebc mov r7, r1 */
/* @0x234ec0 ldr r9, [r1] */
/* @0x234ec4 ldr r10, [r1, #0x8] */
/* @0x234ec8 ldr r8, [r1, #0xc] */
/* @0x234ecc bl 0x233f74 <ogg_page_version> */
/* @0x234ed0 str r0, [sp, #0x14] */
/* @0x234ed4 mov r0, r7 */
/* @0x234ed8 bl 0x233f80 <ogg_page_continued> */
/* @0x234edc mov r11, r0 */
/* @0x234ee0 mov r0, r7 */
/* @0x234ee4 bl 0x233f90 <ogg_page_bos> */
/* @0x234ee8 mov r5, r0 */
/* @0x234eec mov r0, r7 */
/* @0x234ef0 bl 0x233fa0 <ogg_page_eos> */
/* @0x234ef4 str r0, [sp, #0x1c] */
/* @0x234ef8 mov r0, r7 */
/* @0x234efc bl 0x233fb0 <ogg_page_granulepos> */
/* @0x234f00 strd r0, r1, [sp, #32] */
/* @0x234f04 mov r0, r7 */
/* @0x234f08 bl 0x23409c <ogg_page_serialno> */
/* @0x234f0c mov r6, r0 */
/* @0x234f10 mov r0, r7 */
/* @0x234f14 bl 0x2340c4 <ogg_page_pageno> */
/* @0x234f18 ldrb r7, [r9, #0x1a] */
/* @0x234f1c str r0, [sp, #0x18] */
/* @0x234f20 mov r0, r4 */
/* @0x234f24 bl 0x23412c <ogg_stream_check> */
/* @0x234f28 cmp r0, #0 */
/* @0x234f2c bne 0x235220 <ogg_stream_pagein+0x374> */
/* @0x234f30 ldr r1, [r4, #0xc] */
/* @0x234f34 ldr r3, [r4, #0x24] */
/* @0x234f38 cmp r1, #0 */
/* @0x234f3c beq 0x234f5c <ogg_stream_pagein+0xb0> */
/* @0x234f40 ldr r2, [r4, #0x8] */
/* @0x234f44 rsb r2, r1, r2 */
/* @0x234f48 str r2, [r4, #0x8] */
/* @0x234f4c cmp r2, #0 */
/* @0x234f50 bne 0x235234 <ogg_stream_pagein+0x388> */
/* @0x234f54 mov r2, #0 */
/* @0x234f58 str r2, [r4, #0xc] */
/* @0x234f5c cmp r3, #0 */
/* @0x234f60 bne 0x2350a8 <ogg_stream_pagein+0x1fc> */
/* @0x234f64 ldr r3, [r4, #0x150] */
/* @0x234f68 cmp r3, r6 */
/* @0x234f6c bne 0x235220 <ogg_stream_pagein+0x374> */
/* @0x234f70 ldr r3, [sp, #0x14] */
/* @0x234f74 cmp r3, #0 */
/* @0x234f78 bgt 0x235220 <ogg_stream_pagein+0x374> */
/* @0x234f7c mov r0, r4 */
/* @0x234f80 add r1, r7, #1 */
/* @0x234f84 bl 0x2342a0 <ogg_stream_init+0xfc> */
/* @0x234f88 cmp r0, #0 */
/* @0x234f8c str r0, [sp, #0x14] */
/* @0x234f90 bne 0x235220 <ogg_stream_pagein+0x374> */
/* @0x234f94 ldr r6, [r4, #0x154] */
/* @0x234f98 ldr r3, [sp, #0x18] */
/* @0x234f9c cmp r6, r3 */
/* @0x234fa0 beq 0x235000 <ogg_stream_pagein+0x154> */
/* @0x234fa4 ldr r12, [r4, #0x20] */
/* @0x234fa8 ldr r0, [r4, #0x1c] */
/* @0x234fac cmp r12, r0 */
/* @0x234fb0 bge 0x234fdc <ogg_stream_pagein+0x130> */
/* @0x234fb4 ldr r3, [r4, #0x10] */
/* @0x234fb8 ldr r2, [r4, #0x8] */
/* @0x234fbc add r0, r3, r0, lsl #2 */
/* @0x234fc0 add r3, r3, r12, lsl #2 */
/* @0x234fc4 ldr r1, [r3], #4 */
/* @0x234fc8 cmp r3, r0 */
/* @0x234fcc uxtb r1, r1 */
/* @0x234fd0 rsb r2, r1, r2 */
/* @0x234fd4 bne 0x234fc4 <ogg_stream_pagein+0x118> */
/* @0x234fd8 str r2, [r4, #0x8] */
/* @0x234fdc cmn r6, #1 */
/* @0x234fe0 str r12, [r4, #0x1c] */
/* @0x234fe4 beq 0x235000 <ogg_stream_pagein+0x154> */
/* @0x234fe8 ldr r2, [r4, #0x10] */
/* @0x234fec add r3, r12, #1 */
/* @0x234ff0 mov r1, #1024 */
/* @0x234ff4 str r3, [r4, #0x1c] */
/* @0x234ff8 str r1, [r2, r12, lsl #2] */
/* @0x234ffc str r3, [r4, #0x20] */
/* @0x235000 cmp r11, #0 */
/* @0x235004 bne 0x235110 <ogg_stream_pagein+0x264> */
/* @0x235008 mov r6, #0 */
/* @0x23500c cmp r8, #0 */
/* @0x235010 bne 0x235184 <ogg_stream_pagein+0x2d8> */
/* @0x235014 cmp r6, r7 */
/* @0x235018 bge 0x2351d8 <ogg_stream_pagein+0x32c> */
/* @0x23501c ldr r10, [r4, #0x14] */
/* @0x235020 mvn r11, #0 */
/* @0x235024 ldr r8, [r4, #0x10] */
/* @0x235028 add r12, r9, r6 */
/* @0x23502c add r1, r6, #1 */
/* @0x235030 stmib sp, {r7, r10, r11} */
/* @0x235034 b 0x23505c <ogg_stream_pagein+0x1b0> */
/* @0x235038 str r5, [r4, #0x1c] */
/* @0x23503c str r3, [sp, #0xc] */
/* @0x235040 str r5, [r4, #0x20] */
/* @0x235044 ldr r10, [sp, #0x4] */
/* @0x235048 mov r5, #0 */
/* @0x23504c add r12, r12, #1 */
/* @0x235050 add r1, r1, #1 */
/* @0x235054 cmp r10, r0 */
/* @0x235058 ble 0x2351c0 <ogg_stream_pagein+0x314> */
/* @0x23505c ldr r3, [r4, #0x1c] */
/* @0x235060 cmp r5, #0 */
/* @0x235064 ldrb r2, [r12, #0x1b] */
/* @0x235068 mvn r10, #0 */
/* @0x23506c ldr r7, [sp, #0x8] */
/* @0x235070 mvn r11, #0 */
/* @0x235074 lsl r6, r3, #3 */
/* @0x235078 orr r9, r2, #256 */
/* @0x23507c str r2, [r8, r3, lsl #2] */
/* @0x235080 mov r0, r1 */
/* @0x235084 strd r10, r11, [r7, r6] */
/* @0x235088 add r5, r3, #1 */
/* @0x23508c strne r9, [r8, r3, lsl #2] */
/* @0x235090 cmp r2, #255 */
/* @0x235094 bne 0x235038 <ogg_stream_pagein+0x18c> */
/* @0x235098 add r3, r3, #1 */
/* @0x23509c mov r0, r1 */
/* @0x2350a0 str r3, [r4, #0x1c] */
/* @0x2350a4 b 0x235044 <ogg_stream_pagein+0x198> */
/* @0x2350a8 ldr r2, [r4, #0x1c] */
/* @0x2350ac cmp r2, r3 */
/* @0x2350b0 beq 0x2350f0 <ogg_stream_pagein+0x244> */
/* @0x2350b4 ldr r0, [r4, #0x10] */
/* @0x2350b8 rsb r2, r3, r2 */
/* @0x2350bc str r3, [sp, #0x10] */
/* @0x2350c0 add r1, r0, r3, lsl #2 */
/* @0x2350c4 lsl r2, r2, #2 */
/* @0x2350c8 bl 0xb6694 <memmove@plt> */
/* @0x2350cc ldr r3, [sp, #0x10] */
/* @0x2350d0 ldr r2, [r4, #0x1c] */
/* @0x2350d4 ldr r0, [r4, #0x14] */
/* @0x2350d8 rsb r2, r3, r2 */
/* @0x2350dc add r1, r0, r3, lsl #3 */
/* @0x2350e0 lsl r2, r2, #3 */
/* @0x2350e4 bl 0xb6694 <memmove@plt> */
/* @0x2350e8 ldr r2, [r4, #0x1c] */
/* @0x2350ec ldr r3, [sp, #0x10] */
/* @0x2350f0 ldr r1, [r4, #0x20] */
/* @0x2350f4 rsb r2, r3, r2 */
/* @0x2350f8 str r2, [r4, #0x1c] */
/* @0x2350fc mov r2, #0 */
/* @0x235100 rsb r3, r3, r1 */
/* @0x235104 str r2, [r4, #0x24] */
/* @0x235108 str r3, [r4, #0x20] */
/* @0x23510c b 0x234f64 <ogg_stream_pagein+0xb8> */
/* @0x235110 ldr r3, [r4, #0x1c] */
/* @0x235114 cmp r3, #0 */
/* @0x235118 ble 0x235130 <ogg_stream_pagein+0x284> */
/* @0x23511c ldr r2, [r4, #0x10] */
/* @0x235120 sub r3, r3, #-1073741823 */
/* @0x235124 ldr r3, [r2, r3, lsl #2] */
/* @0x235128 cmp r3, #1024 */
/* @0x23512c bne 0x235008 <ogg_stream_pagein+0x15c> */
/* @0x235130 cmp r7, #0 */
/* @0x235134 beq 0x235254 <ogg_stream_pagein+0x3a8> */
/* @0x235138 ldrb r3, [r9, #0x1b] */
/* @0x23513c cmp r3, #255 */
/* @0x235140 add r10, r10, r3 */
/* @0x235144 rsb r8, r3, r8 */
/* @0x235148 addeq r2, r9, #27 */
/* @0x23514c moveq r6, #0 */
/* @0x235150 beq 0x23516c <ogg_stream_pagein+0x2c0> */
/* @0x235154 b 0x235260 <ogg_stream_pagein+0x3b4> */
/* @0x235158 ldrb r3, [r2, #0x1]! */
/* @0x23515c cmp r3, #255 */
/* @0x235160 add r10, r10, r3 */
/* @0x235164 rsb r8, r3, r8 */
/* @0x235168 bne 0x23524c <ogg_stream_pagein+0x3a0> */
/* @0x23516c add r6, r6, #1 */
/* @0x235170 cmp r7, r6 */
/* @0x235174 bgt 0x235158 <ogg_stream_pagein+0x2ac> */
/* @0x235178 cmp r8, #0 */
/* @0x23517c mov r5, #0 */
/* @0x235180 beq 0x235014 <ogg_stream_pagein+0x168> */
/* @0x235184 mov r0, r4 */
/* @0x235188 mov r1, r8 */
/* @0x23518c bl 0x234238 <ogg_stream_init+0x94> */
/* @0x235190 cmp r0, #0 */
/* @0x235194 bne 0x235220 <ogg_stream_pagein+0x374> */
/* @0x235198 ldr r3, [r4, #0x8] */
/* @0x23519c mov r2, r8 */
/* @0x2351a0 ldr r0, [r4] */
/* @0x2351a4 mov r1, r10 */
/* @0x2351a8 add r0, r0, r3 */
/* @0x2351ac bl 0xb65bc <memcpy@plt> */
/* @0x2351b0 ldr r3, [r4, #0x8] */
/* @0x2351b4 add r8, r3, r8 */
/* @0x2351b8 str r8, [r4, #0x8] */
/* @0x2351bc b 0x235014 <ogg_stream_pagein+0x168> */
/* @0x2351c0 ldr r11, [sp, #0xc] */
/* @0x2351c4 ldr r10, [sp, #0x8] */
/* @0x2351c8 cmn r11, #1 */
/* @0x2351cc lslne r11, r11, #3 */
/* @0x2351d0 ldrdne r2, r3, [sp, #32] */
/* @0x2351d4 strdne r2, r3, [r10, r11] */
/* @0x2351d8 ldr r3, [sp, #0x1c] */
/* @0x2351dc cmp r3, #0 */
/* @0x2351e0 beq 0x235208 <ogg_stream_pagein+0x35c> */
/* @0x2351e4 ldr r3, [r4, #0x1c] */
/* @0x2351e8 mov r2, #1 */
/* @0x2351ec str r2, [r4, #0x148] */
/* @0x2351f0 cmp r3, #0 */
/* @0x2351f4 subgt r3, r3, #-1073741823 */
/* @0x2351f8 ldrgt r2, [r4, #0x10] */
/* @0x2351fc ldrgt r1, [r2, r3, lsl #2] */
/* @0x235200 orrgt r1, r1, #512 */
/* @0x235204 strgt r1, [r2, r3, lsl #2] */
/* @0x235208 ldr r7, [sp, #0x18] */
/* @0x23520c ldr r0, [sp, #0x14] */
/* @0x235210 add r3, r7, #1 */
/* @0x235214 str r3, [r4, #0x154] */
/* @0x235218 add sp, sp, #44 */
/* @0x23521c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x235220 mvn r3, #0 */
/* @0x235224 str r3, [sp, #0x14] */
/* @0x235228 ldr r0, [sp, #0x14] */
/* @0x23522c add sp, sp, #44 */
/* @0x235230 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x235234 ldr r0, [r4] */
/* @0x235238 str r3, [sp, #0x10] */
/* @0x23523c add r1, r0, r1 */
/* @0x235240 bl 0xb6694 <memmove@plt> */
/* @0x235244 ldr r3, [sp, #0x10] */
/* @0x235248 b 0x234f54 <ogg_stream_pagein+0xa8> */
/* @0x23524c add r6, r6, #1 */
/* @0x235250 b 0x235178 <ogg_stream_pagein+0x2cc> */
/* @0x235254 mov r5, r7 */
/* @0x235258 mov r6, r7 */
/* @0x23525c b 0x23500c <ogg_stream_pagein+0x160> */
/* @0x235260 mov r6, #1 */
/* @0x235264 b 0x235178 <ogg_stream_pagein+0x2cc> */

/* ── FUNC 0x235268 · ogg_sync_reset · size=44 · insn=11 */
/* @0x235268 push {r4, lr} */
/* @0x23526c mov r4, r0 */
/* @0x235270 bl 0x234b80 <ogg_sync_check> */
/* @0x235274 cmp r0, #0 */
/* @0x235278 streq r0, [r4, #0x8] */
/* @0x23527c streq r0, [r4, #0xc] */
/* @0x235280 streq r0, [r4, #0x10] */
/* @0x235284 mvnne r0, #0 */
/* @0x235288 streq r0, [r4, #0x14] */
/* @0x23528c streq r0, [r4, #0x18] */
/* @0x235290 pop {r4, pc} */

/* ── FUNC 0x235294 · ogg_stream_reset · size=96 · insn=24 */
/* @0x235294 push {r3, r4, r5, lr} */
/* @0x235298 mov r4, r0 */
/* @0x23529c bl 0x23412c <ogg_stream_check> */
/* @0x2352a0 cmp r0, #0 */
/* @0x2352a4 bne 0x2352ec <ogg_stream_reset+0x58> */
/* @0x2352a8 mov r5, #344 */
/* @0x2352ac mov r12, #352 */
/* @0x2352b0 str r0, [r4, #0x8] */
/* @0x2352b4 mov r2, #0 */
/* @0x2352b8 mov r3, #0 */
/* @0x2352bc str r0, [r4, #0xc] */
/* @0x2352c0 str r0, [r4, #0x1c] */
/* @0x2352c4 mvn r1, #0 */
/* @0x2352c8 str r0, [r4, #0x20] */
/* @0x2352cc str r0, [r4, #0x24] */
/* @0x2352d0 str r0, [r4, #0x144] */
/* @0x2352d4 str r0, [r4, #0x148] */
/* @0x2352d8 str r0, [r4, #0x14c] */
/* @0x2352dc strd r2, r3, [r4, r5] */
/* @0x2352e0 strd r2, r3, [r4, r12] */
/* @0x2352e4 str r1, [r4, #0x154] */
/* @0x2352e8 pop {r3, r4, r5, pc} */
/* @0x2352ec mvn r0, #0 */
/* @0x2352f0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2352f4 · ogg_stream_reset_serialno · size=52 · insn=13 */
/* @0x2352f4 push {r4, r5, r6, lr} */
/* @0x2352f8 mov r6, r1 */
/* @0x2352fc mov r4, r0 */
/* @0x235300 bl 0x23412c <ogg_stream_check> */
/* @0x235304 subs r5, r0, #0 */
/* @0x235308 bne 0x235320 <ogg_stream_reset_serialno+0x2c> */
/* @0x23530c mov r0, r4 */
/* @0x235310 bl 0x235294 <ogg_stream_reset> */
/* @0x235314 str r6, [r4, #0x150] */
/* @0x235318 mov r0, r5 */
/* @0x23531c pop {r4, r5, r6, pc} */
/* @0x235320 mvn r5, #0 */
/* @0x235324 b 0x235318 <ogg_stream_reset_serialno+0x24> */

/* ── FUNC 0x235328 · ogg_stream_packetout · size=52 · insn=13 */
/* @0x235328 push {r3, r4, r5, lr} */
/* @0x23532c mov r4, r1 */
/* @0x235330 mov r5, r0 */
/* @0x235334 bl 0x23412c <ogg_stream_check> */
/* @0x235338 cmp r0, #0 */
/* @0x23533c beq 0x235348 <ogg_stream_packetout+0x20> */
/* @0x235340 mov r0, #0 */
/* @0x235344 pop {r3, r4, r5, pc} */
/* @0x235348 mov r0, r5 */
/* @0x23534c mov r1, r4 */
/* @0x235350 mov r2, #1 */
/* @0x235354 pop {r3, r4, r5, lr} */
/* @0x235358 b 0x233e64 <oggpackB_get_buffer+0x4> */

/* ── FUNC 0x23535c · ogg_stream_packetpeek · size=48 · insn=12 */
/* @0x23535c push {r3, r4, r5, lr} */
/* @0x235360 mov r4, r1 */
/* @0x235364 mov r5, r0 */
/* @0x235368 bl 0x23412c <ogg_stream_check> */
/* @0x23536c subs r2, r0, #0 */
/* @0x235370 beq 0x23537c <ogg_stream_packetpeek+0x20> */
/* @0x235374 mov r0, #0 */
/* @0x235378 pop {r3, r4, r5, pc} */
/* @0x23537c mov r0, r5 */
/* @0x235380 mov r1, r4 */
/* @0x235384 pop {r3, r4, r5, lr} */
/* @0x235388 b 0x233e64 <oggpackB_get_buffer+0x4> */

/* ── FUNC 0x23538c · ogg_packet_clear · size=36 · insn=9 */
/* @0x23538c push {r4, lr} */
/* @0x235390 mov r4, r0 */
/* @0x235394 ldr r0, [r0] */
/* @0x235398 bl 0xb655c <free@plt> */
/* @0x23539c mov r0, r4 */
/* @0x2353a0 mov r1, #0 */
/* @0x2353a4 mov r2, #32 */
/* @0x2353a8 pop {r4, lr} */
/* @0x2353ac b 0xb65b0 <memset@plt> */

/* ── FUNC 0x2353b0 · Key::~Key() · size=48 · insn=12 */
/* @0x2353b0 push {r4, lr} */
/* @0x2353b4 mov r4, r0 */
/* @0x2353b8 ldr r0, [r0, #0x4] */
/* @0x2353bc cmp r0, #0 */
/* @0x2353c0 beq 0x2353c8 <_ZN3KeyD2Ev+0x18> */
/* @0x2353c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2353c8 ldr r0, [r4, #0x8] */
/* @0x2353cc cmp r0, #0 */
/* @0x2353d0 beq 0x2353d8 <_ZN3KeyD2Ev+0x28> */
/* @0x2353d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2353d8 mov r0, r4 */
/* @0x2353dc pop {r4, pc} */

/* ── FUNC 0x2353b0 · Key::~Key() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2353e0 · Section::~Section() · size=72 · insn=18 */
/* @0x2353e0 push {r3, r4, r5, lr} */
/* @0x2353e4 mov r5, r0 */
/* @0x2353e8 ldr r0, [r0, #0x8] */
/* @0x2353ec cmp r0, #0 */
/* @0x2353f0 beq 0x235414 <_ZN7SectionD2Ev+0x34> */
/* @0x2353f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2353f8 b 0x235414 <_ZN7SectionD2Ev+0x34> */
/* @0x2353fc ldr r3, [r4] */
/* @0x235400 mov r0, r4 */
/* @0x235404 str r3, [r5, #0x4] */
/* @0x235408 bl 0x2353b0 <_ZN3KeyD2Ev> */
/* @0x23540c mov r0, r4 */
/* @0x235410 bl 0x27d1d0 <_ZdlPv> */
/* @0x235414 ldr r4, [r5, #0x4] */
/* @0x235418 cmp r4, #0 */
/* @0x23541c bne 0x2353fc <_ZN7SectionD2Ev+0x1c> */
/* @0x235420 mov r0, r5 */
/* @0x235424 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2353e0 · Section::~Section() · alias of the symbol above · insn=0 */

/* ── FUNC 0x235428 · IniFile::~IniFile() · size=96 · insn=24 */
/* @0x235428 push {r3, r4, r5, lr} */
/* @0x23542c mov r5, r0 */
/* @0x235430 ldr r4, [r0, #0x8] */
/* @0x235434 cmp r4, #0 */
/* @0x235438 beq 0x235460 <_ZN7IniFileD2Ev+0x38> */
/* @0x23543c ldr r3, [r4] */
/* @0x235440 mov r0, r4 */
/* @0x235444 str r3, [r5, #0x8] */
/* @0x235448 bl 0x2353e0 <_ZN7SectionD2Ev> */
/* @0x23544c mov r0, r4 */
/* @0x235450 bl 0x27d1d0 <_ZdlPv> */
/* @0x235454 ldr r4, [r5, #0x8] */
/* @0x235458 cmp r4, #0 */
/* @0x23545c bne 0x23543c <_ZN7IniFileD2Ev+0x14> */
/* @0x235460 ldr r0, [r5] */
/* @0x235464 cmp r0, #0 */
/* @0x235468 beq 0x235470 <_ZN7IniFileD2Ev+0x48> */
/* @0x23546c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x235470 ldr r0, [r5, #0x10] */
/* @0x235474 cmp r0, #0 */
/* @0x235478 beq 0x235480 <_ZN7IniFileD2Ev+0x58> */
/* @0x23547c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x235480 mov r0, r5 */
/* @0x235484 pop {r3, r4, r5, pc} */

/* ── FUNC 0x235428 · IniFile::~IniFile() · alias of the symbol above · insn=0 */

/* ── FUNC 0x235488 · IniFile::IniFile() · size=32 · insn=8 */
/* @0x235488 mov r2, #0 */
/* @0x23548c str r2, [r0] */
/* @0x235490 str r2, [r0, #0x4] */
/* @0x235494 str r2, [r0, #0x8] */
/* @0x235498 str r2, [r0, #0x10] */
/* @0x23549c str r2, [r0, #0x14] */
/* @0x2354a0 strb r2, [r0, #0x18] */
/* @0x2354a4 bx lr */

/* ── FUNC 0x235488 · IniFile::IniFile() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2354a8 · IniFile::NextLine() · size=112 · insn=28 */
/* @0x2354a8 ldr r1, [r0, #0x10] */
/* @0x2354ac ldr r3, [r0, #0xc] */
/* @0x2354b0 str r4, [sp, #-0x4]! */
/* @0x2354b4 add r2, r1, r3 */
/* @0x2354b8 ldrb r12, [r1, r3] */
/* @0x2354bc cmp r12, #13 */
/* @0x2354c0 cmpne r12, #10 */
/* @0x2354c4 beq 0x2354fc <_ZN7IniFile8NextLineEv+0x54> */
/* @0x2354c8 ldr r12, [r0, #0x4] */
/* @0x2354cc cmp r3, r12 */
/* @0x2354d0 bge 0x2354fc <_ZN7IniFile8NextLineEv+0x54> */
/* @0x2354d4 add r12, r1, r12 */
/* @0x2354d8 rsb r4, r1, #1 */
/* @0x2354dc add r3, r4, r2 */
/* @0x2354e0 str r3, [r0, #0xc] */
/* @0x2354e4 ldrb r1, [r2, #0x1]! */
/* @0x2354e8 cmp r1, #13 */
/* @0x2354ec cmpne r1, #10 */
/* @0x2354f0 beq 0x2354fc <_ZN7IniFile8NextLineEv+0x54> */
/* @0x2354f4 cmp r2, r12 */
/* @0x2354f8 bne 0x2354dc <_ZN7IniFile8NextLineEv+0x34> */
/* @0x2354fc ldr r2, [r0, #0x14] */
/* @0x235500 add r3, r3, #1 */
/* @0x235504 ldr r4, [sp], #4 */
/* @0x235508 str r3, [r0, #0xc] */
/* @0x23550c add r3, r2, #1 */
/* @0x235510 str r3, [r0, #0x14] */
/* @0x235514 bx lr */

/* ── FUNC 0x235518 · IniFile::IsWhiteSpace() · size=96 · insn=24 */
/* @0x235518 ldr r3, [r0, #0xc] */
/* @0x23551c ldr r2, [r0, #0x4] */
/* @0x235520 cmp r3, r2 */
/* @0x235524 bge 0x235568 <_ZN7IniFile12IsWhiteSpaceEv+0x50> */
/* @0x235528 ldr r2, [r0, #0x10] */
/* @0x23552c ldrb r3, [r2, r3] */
/* @0x235530 sub r0, r3, #9 */
/* @0x235534 cmp r3, #32 */
/* @0x235538 cmpne r0, #1 */
/* @0x23553c movhi r0, #0 */
/* @0x235540 movls r0, #1 */
/* @0x235544 bxls lr */
/* @0x235548 cmp r3, #13 */
/* @0x23554c beq 0x235570 <_ZN7IniFile12IsWhiteSpaceEv+0x58> */
/* @0x235550 cmp r3, #35 */
/* @0x235554 beq 0x235570 <_ZN7IniFile12IsWhiteSpaceEv+0x58> */
/* @0x235558 subs r3, r3, #59 */
/* @0x23555c rsbs r0, r3, #0 */
/* @0x235560 adcs r0, r0, r3 */
/* @0x235564 bx lr */
/* @0x235568 mov r0, #0 */
/* @0x23556c bx lr */
/* @0x235570 mov r0, #1 */
/* @0x235574 bx lr */

/* ── FUNC 0x235578 · IniFile::SkipWhiteSpace() · size=108 · insn=27 */
/* @0x235578 push {r4, lr} */
/* @0x23557c mov r4, r0 */
/* @0x235580 mov r0, r4 */
/* @0x235584 bl 0x235518 <_ZN7IniFile12IsWhiteSpaceEv> */
/* @0x235588 cmp r0, #0 */
/* @0x23558c popeq {r4, pc} */
/* @0x235590 ldr r3, [r4, #0xc] */
/* @0x235594 ldr r2, [r4, #0x4] */
/* @0x235598 cmp r3, r2 */
/* @0x23559c popge {r4, pc} */
/* @0x2355a0 ldr r2, [r4, #0x10] */
/* @0x2355a4 ldrb r2, [r2, r3] */
/* @0x2355a8 cmp r2, #35 */
/* @0x2355ac cmpne r2, #59 */
/* @0x2355b0 bne 0x2355c8 <_ZN7IniFile14SkipWhiteSpaceEv+0x50> */
/* @0x2355b4 mov r0, r4 */
/* @0x2355b8 bl 0x2354a8 <_ZN7IniFile8NextLineEv> */
/* @0x2355bc ldr r3, [r4, #0xc] */
/* @0x2355c0 ldr r2, [r4, #0x10] */
/* @0x2355c4 ldrb r2, [r2, r3] */
/* @0x2355c8 cmp r2, #10 */
/* @0x2355cc add r3, r3, #1 */
/* @0x2355d0 str r3, [r4, #0xc] */
/* @0x2355d4 ldreq r2, [r4, #0x14] */
/* @0x2355d8 addeq r2, r2, #1 */
/* @0x2355dc streq r2, [r4, #0x14] */
/* @0x2355e0 b 0x235580 <_ZN7IniFile14SkipWhiteSpaceEv+0x8> */

/* ── FUNC 0x2355e4 · IniFile::GetSection() · size=300 · insn=75 */
/* @0x2355e4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2355e8 mov r4, r0 */
/* @0x2355ec bl 0x235578 <_ZN7IniFile14SkipWhiteSpaceEv> */
/* @0x2355f0 ldr r0, [r4, #0x10] */
/* @0x2355f4 ldr r3, [r4, #0xc] */
/* @0x2355f8 ldr r6, [r4, #0x4] */
/* @0x2355fc add r2, r0, r3 */
/* @0x235600 ldrb r1, [r0, r3] */
/* @0x235604 cmp r1, #91 */
/* @0x235608 beq 0x23563c <_ZN7IniFile10GetSectionEv+0x58> */
/* @0x23560c cmp r3, r6 */
/* @0x235610 bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118> */
/* @0x235614 add r5, r6, r0 */
/* @0x235618 rsb r12, r0, #1 */
/* @0x23561c b 0x235628 <_ZN7IniFile10GetSectionEv+0x44> */
/* @0x235620 cmp r2, r5 */
/* @0x235624 beq 0x2356fc <_ZN7IniFile10GetSectionEv+0x118> */
/* @0x235628 add r3, r12, r2 */
/* @0x23562c str r3, [r4, #0xc] */
/* @0x235630 ldrb r1, [r2, #0x1]! */
/* @0x235634 cmp r1, #91 */
/* @0x235638 bne 0x235620 <_ZN7IniFile10GetSectionEv+0x3c> */
/* @0x23563c cmp r3, r6 */
/* @0x235640 bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118> */
/* @0x235644 add r7, r3, #1 */
/* @0x235648 str r7, [r4, #0xc] */
/* @0x23564c ldrb r2, [r0, r7] */
/* @0x235650 cmp r2, #93 */
/* @0x235654 beq 0x235704 <_ZN7IniFile10GetSectionEv+0x120> */
/* @0x235658 cmp r7, r6 */
/* @0x23565c bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118> */
/* @0x235660 add r3, r3, #2 */
/* @0x235664 add r5, r6, #1 */
/* @0x235668 b 0x235674 <_ZN7IniFile10GetSectionEv+0x90> */
/* @0x23566c cmp r3, r5 */
/* @0x235670 beq 0x2356fc <_ZN7IniFile10GetSectionEv+0x118> */
/* @0x235674 str r3, [r4, #0xc] */
/* @0x235678 mov r12, r3 */
/* @0x23567c ldrb r2, [r0, r3] */
/* @0x235680 add r3, r3, #1 */
/* @0x235684 cmp r2, #93 */
/* @0x235688 bne 0x23566c <_ZN7IniFile10GetSectionEv+0x88> */
/* @0x23568c cmp r12, r6 */
/* @0x235690 bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118> */
/* @0x235694 mov r0, #12 */
/* @0x235698 rsb r8, r7, r12 */
/* @0x23569c bl 0x27c524 <_Znwj> */
/* @0x2356a0 ldr r1, [pc, #0x64] */
/* @0x2356a4 mov r6, #0 */
/* @0x2356a8 mov r3, #1 */
/* @0x2356ac mov r2, #253 */
/* @0x2356b0 add r1, pc, r1 */
/* @0x2356b4 mov r5, r0 */
/* @0x2356b8 add r0, r8, #1 */
/* @0x2356bc str r6, [r5] */
/* @0x2356c0 str r6, [r5, #0x4] */
/* @0x2356c4 str r6, [r5, #0x8] */
/* @0x2356c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2356cc ldr r1, [r4, #0x10] */
/* @0x2356d0 mov r2, r8 */
/* @0x2356d4 add r1, r1, r7 */
/* @0x2356d8 str r0, [r5, #0x8] */
/* @0x2356dc bl 0xb65bc <memcpy@plt> */
/* @0x2356e0 ldr r3, [r5, #0x8] */
/* @0x2356e4 mov r0, r5 */
/* @0x2356e8 strb r6, [r3, r8] */
/* @0x2356ec ldr r3, [r4, #0xc] */
/* @0x2356f0 add r3, r3, #1 */
/* @0x2356f4 str r3, [r4, #0xc] */
/* @0x2356f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2356fc mov r0, #0 */
/* @0x235700 pop {r4, r5, r6, r7, r8, pc} */
/* @0x235704 mov r12, r7 */
/* @0x235708 b 0x23568c <_ZN7IniFile10GetSectionEv+0xa8> */
/* @0x23570c andseq pc, r1, r4, lsr r10 */

/* ── FUNC 0x235710 · IniFile::GetKey() · size=896 · insn=224 */
/* @0x235710 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x235714 mov r4, r0 */
/* @0x235718 bl 0x235578 <_ZN7IniFile14SkipWhiteSpaceEv> */
/* @0x23571c ldr r6, [r4, #0xc] */
/* @0x235720 ldr r3, [r4, #0x4] */
/* @0x235724 cmp r6, r3 */
/* @0x235728 bge 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c> */
/* @0x23572c ldr r3, [r4, #0x10] */
/* @0x235730 ldrb r3, [r3, r6] */
/* @0x235734 cmp r3, #91 */
/* @0x235738 beq 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c> */
/* @0x23573c cmp r3, #61 */
/* @0x235740 beq 0x235a18 <_ZN7IniFile6GetKeyEv+0x308> */
/* @0x235744 mvn r5, #0 */
/* @0x235748 b 0x235778 <_ZN7IniFile6GetKeyEv+0x68> */
/* @0x23574c ldr r3, [r4, #0xc] */
/* @0x235750 mvn r5, #0 */
/* @0x235754 ldr r0, [r4, #0x10] */
/* @0x235758 add r3, r3, #1 */
/* @0x23575c str r3, [r4, #0xc] */
/* @0x235760 ldrb r0, [r0, r3] */
/* @0x235764 cmp r0, #61 */
/* @0x235768 beq 0x2357b4 <_ZN7IniFile6GetKeyEv+0xa4> */
/* @0x23576c ldr r0, [r4, #0x4] */
/* @0x235770 cmp r0, r3 */
/* @0x235774 ble 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c> */
/* @0x235778 mov r0, r4 */
/* @0x23577c bl 0x235518 <_ZN7IniFile12IsWhiteSpaceEv> */
/* @0x235780 cmp r0, #0 */
/* @0x235784 beq 0x23574c <_ZN7IniFile6GetKeyEv+0x3c> */
/* @0x235788 cmp r5, #0 */
/* @0x23578c ldrlt r5, [r4, #0xc] */
/* @0x235790 ldrge r3, [r4, #0xc] */
/* @0x235794 movlt r3, r5 */
/* @0x235798 b 0x235754 <_ZN7IniFile6GetKeyEv+0x44> */
/* @0x23579c mov r0, r7 */
/* @0x2357a0 bl 0x2353b0 <_ZN3KeyD2Ev> */
/* @0x2357a4 mov r0, r7 */
/* @0x2357a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2357ac mov r0, #0 */
/* @0x2357b0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2357b4 ldr r2, [r4, #0x4] */
/* @0x2357b8 cmp r2, r3 */
/* @0x2357bc ble 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c> */
/* @0x2357c0 cmp r5, #0 */
/* @0x2357c4 movlt r5, r3 */
/* @0x2357c8 mov r0, #12 */
/* @0x2357cc rsb r5, r6, r5 */
/* @0x2357d0 bl 0x27c524 <_Znwj> */
/* @0x2357d4 ldr r1, [pc, #0x2a8] */
/* @0x2357d8 mov r8, #0 */
/* @0x2357dc mov r3, #1 */
/* @0x2357e0 movw r2, #0x129 */
/* @0x2357e4 add r1, pc, r1 */
/* @0x2357e8 mov r7, r0 */
/* @0x2357ec add r0, r5, #1 */
/* @0x2357f0 str r8, [r7, #0x4] */
/* @0x2357f4 str r8, [r7, #0x8] */
/* @0x2357f8 str r8, [r7] */
/* @0x2357fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x235800 ldr r1, [r4, #0x10] */
/* @0x235804 mov r2, r5 */
/* @0x235808 add r1, r1, r6 */
/* @0x23580c str r0, [r7, #0x4] */
/* @0x235810 bl 0xb65bc <memcpy@plt> */
/* @0x235814 ldr r3, [r7, #0x4] */
/* @0x235818 strb r8, [r3, r5] */
/* @0x23581c ldr r12, [r4, #0x10] */
/* @0x235820 ldr r2, [r4, #0xc] */
/* @0x235824 ldr r0, [r4, #0x4] */
/* @0x235828 add r3, r12, r2 */
/* @0x23582c ldrb r1, [r12, r2] */
/* @0x235830 cmp r1, #61 */
/* @0x235834 beq 0x235868 <_ZN7IniFile6GetKeyEv+0x158> */
/* @0x235838 cmp r2, r0 */
/* @0x23583c bge 0x23579c <_ZN7IniFile6GetKeyEv+0x8c> */
/* @0x235840 add lr, r12, r0 */
/* @0x235844 rsb r12, r12, #1 */
/* @0x235848 b 0x235854 <_ZN7IniFile6GetKeyEv+0x144> */
/* @0x23584c cmp r3, lr */
/* @0x235850 beq 0x23579c <_ZN7IniFile6GetKeyEv+0x8c> */
/* @0x235854 add r2, r12, r3 */
/* @0x235858 str r2, [r4, #0xc] */
/* @0x23585c ldrb r1, [r3, #0x1]! */
/* @0x235860 cmp r1, #61 */
/* @0x235864 bne 0x23584c <_ZN7IniFile6GetKeyEv+0x13c> */
/* @0x235868 cmp r2, r0 */
/* @0x23586c bge 0x23579c <_ZN7IniFile6GetKeyEv+0x8c> */
/* @0x235870 add r2, r2, #1 */
/* @0x235874 mov r0, r4 */
/* @0x235878 str r2, [r4, #0xc] */
/* @0x23587c ldr r5, [r4, #0x14] */
/* @0x235880 bl 0x235578 <_ZN7IniFile14SkipWhiteSpaceEv> */
/* @0x235884 ldr r3, [r4, #0x14] */
/* @0x235888 cmp r3, r5 */
/* @0x23588c bne 0x23579c <_ZN7IniFile6GetKeyEv+0x8c> */
/* @0x235890 ldr r9, [r4, #0xc] */
/* @0x235894 ldr r1, [r4, #0x10] */
/* @0x235898 ldrb r3, [r1, r9] */
/* @0x23589c cmp r3, #34 */
/* @0x2358a0 addeq r9, r9, #1 */
/* @0x2358a4 moveq r6, #34 */
/* @0x2358a8 beq 0x235a28 <_ZN7IniFile6GetKeyEv+0x318> */
/* @0x2358ac cmp r3, #39 */
/* @0x2358b0 beq 0x235a20 <_ZN7IniFile6GetKeyEv+0x310> */
/* @0x2358b4 mov lr, r9 */
/* @0x2358b8 mov r8, #0 */
/* @0x2358bc mov r6, #59 */
/* @0x2358c0 mov r5, #35 */
/* @0x2358c4 cmp r3, #10 */
/* @0x2358c8 cmpne r3, #13 */
/* @0x2358cc moveq r10, #0 */
/* @0x2358d0 movne r10, #1 */
/* @0x2358d4 beq 0x235a10 <_ZN7IniFile6GetKeyEv+0x300> */
/* @0x2358d8 cmp r5, r3 */
/* @0x2358dc beq 0x235a0c <_ZN7IniFile6GetKeyEv+0x2fc> */
/* @0x2358e0 cmp r6, r3 */
/* @0x2358e4 beq 0x235a0c <_ZN7IniFile6GetKeyEv+0x2fc> */
/* @0x2358e8 ldr r12, [r4, #0x4] */
/* @0x2358ec cmp r12, lr */
/* @0x2358f0 ble 0x235a0c <_ZN7IniFile6GetKeyEv+0x2fc> */
/* @0x2358f4 add r1, r1, lr */
/* @0x2358f8 mov r2, lr */
/* @0x2358fc mvn r0, #0 */
/* @0x235900 cmp r3, #32 */
/* @0x235904 cmpne r3, #9 */
/* @0x235908 mvnne r0, #0 */
/* @0x23590c bne 0x235918 <_ZN7IniFile6GetKeyEv+0x208> */
/* @0x235910 cmp r0, #0 */
/* @0x235914 movlt r0, r2 */
/* @0x235918 add r2, r2, #1 */
/* @0x23591c str r2, [r4, #0xc] */
/* @0x235920 ldrb r3, [r1, #0x1]! */
/* @0x235924 cmp r3, #13 */
/* @0x235928 cmpne r3, #10 */
/* @0x23592c beq 0x235948 <_ZN7IniFile6GetKeyEv+0x238> */
/* @0x235930 cmp r5, r3 */
/* @0x235934 beq 0x235948 <_ZN7IniFile6GetKeyEv+0x238> */
/* @0x235938 cmp r6, r3 */
/* @0x23593c beq 0x235948 <_ZN7IniFile6GetKeyEv+0x238> */
/* @0x235940 cmp r2, r12 */
/* @0x235944 bne 0x235900 <_ZN7IniFile6GetKeyEv+0x1f0> */
/* @0x235948 eor r3, r8, #1 */
/* @0x23594c cmp r0, #0 */
/* @0x235950 movlt r3, #0 */
/* @0x235954 andge r3, r3, #1 */
/* @0x235958 cmp r3, #0 */
/* @0x23595c beq 0x2359a4 <_ZN7IniFile6GetKeyEv+0x294> */
/* @0x235960 ldr r1, [pc, #0x120] */
/* @0x235964 rsb r5, lr, r0 */
/* @0x235968 mov r3, #1 */
/* @0x23596c add r0, r5, #1 */
/* @0x235970 add r1, pc, r1 */
/* @0x235974 movw r2, #0x16a */
/* @0x235978 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x23597c ldr r1, [r4, #0x10] */
/* @0x235980 mov r2, r5 */
/* @0x235984 add r1, r1, r9 */
/* @0x235988 str r0, [r7, #0x8] */
/* @0x23598c bl 0xb65bc <memcpy@plt> */
/* @0x235990 ldr r3, [r7, #0x8] */
/* @0x235994 mov r2, #0 */
/* @0x235998 mov r0, r7 */
/* @0x23599c strb r2, [r3, r5] */
/* @0x2359a0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2359a4 rsb r2, lr, r2 */
/* @0x2359a8 add r0, r2, #1 */
/* @0x2359ac mov r10, r2 */
/* @0x2359b0 ldr r1, [pc, #0xd4] */
/* @0x2359b4 mov r3, #1 */
/* @0x2359b8 movw r2, #0x16a */
/* @0x2359bc add r1, pc, r1 */
/* @0x2359c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2359c4 ldr r1, [r4, #0x10] */
/* @0x2359c8 mov r2, r10 */
/* @0x2359cc add r1, r1, r9 */
/* @0x2359d0 str r0, [r7, #0x8] */
/* @0x2359d4 bl 0xb65bc <memcpy@plt> */
/* @0x2359d8 ldr r3, [r7, #0x8] */
/* @0x2359dc cmp r8, #0 */
/* @0x2359e0 mov r2, #0 */
/* @0x2359e4 strb r2, [r3, r10] */
/* @0x2359e8 beq 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4> */
/* @0x2359ec ldr r3, [r4, #0x10] */
/* @0x2359f0 ldr r2, [r4, #0xc] */
/* @0x2359f4 add r0, r3, r2 */
/* @0x2359f8 ldrb r1, [r3, r2] */
/* @0x2359fc cmp r1, r5 */
/* @0x235a00 beq 0x235a40 <_ZN7IniFile6GetKeyEv+0x330> */
/* @0x235a04 mov r0, r7 */
/* @0x235a08 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x235a0c mov r10, #0 */
/* @0x235a10 mov r0, #1 */
/* @0x235a14 b 0x2359b0 <_ZN7IniFile6GetKeyEv+0x2a0> */
/* @0x235a18 mov r5, r6 */
/* @0x235a1c b 0x2357c8 <_ZN7IniFile6GetKeyEv+0xb8> */
/* @0x235a20 add r9, r9, #1 */
/* @0x235a24 mov r6, #39 */
/* @0x235a28 str r9, [r4, #0xc] */
/* @0x235a2c mov r5, r6 */
/* @0x235a30 mov r8, #1 */
/* @0x235a34 ldrb r3, [r1, r9] */
/* @0x235a38 mov lr, r9 */
/* @0x235a3c b 0x2358c4 <_ZN7IniFile6GetKeyEv+0x1b4> */
/* @0x235a40 cmp r6, r5 */
/* @0x235a44 bne 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4> */
/* @0x235a48 ldr r1, [r4, #0x4] */
/* @0x235a4c cmp r1, r2 */
/* @0x235a50 ble 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4> */
/* @0x235a54 add r1, r3, r1 */
/* @0x235a58 rsb r3, r3, #1 */
/* @0x235a5c mov r2, r0 */
/* @0x235a60 add r0, r3, r2 */
/* @0x235a64 str r0, [r4, #0xc] */
/* @0x235a68 ldrb r0, [r2, #0x1]! */
/* @0x235a6c cmp r0, #13 */
/* @0x235a70 cmpne r0, #10 */
/* @0x235a74 beq 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4> */
/* @0x235a78 cmp r2, r1 */
/* @0x235a7c beq 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4> */
/* @0x235a80 b 0x235a60 <_ZN7IniFile6GetKeyEv+0x350> */
/* @0x235a84 andseq pc, r1, r0, lsl #18 */
/* @0x235a88 andseq pc, r1, r4, ror r7 */
/* @0x235a8c andseq pc, r1, r8, lsr #14 */

/* ── FUNC 0x235a90 · IniFile::GetSection(char const*) · size=64 · insn=16 */
/* @0x235a90 push {r3, r4, r5, lr} */
/* @0x235a94 mov r5, r1 */
/* @0x235a98 ldr r4, [r0, #0x8] */
/* @0x235a9c cmp r4, #0 */
/* @0x235aa0 bne 0x235ab4 <_ZN7IniFile10GetSectionEPKc+0x24> */
/* @0x235aa4 b 0x235ac8 <_ZN7IniFile10GetSectionEPKc+0x38> */
/* @0x235aa8 ldr r4, [r4] */
/* @0x235aac cmp r4, #0 */
/* @0x235ab0 beq 0x235ac8 <_ZN7IniFile10GetSectionEPKc+0x38> */
/* @0x235ab4 mov r0, r5 */
/* @0x235ab8 ldr r1, [r4, #0x8] */
/* @0x235abc bl 0xb6574 <strcmp@plt> */
/* @0x235ac0 cmp r0, #0 */
/* @0x235ac4 bne 0x235aa8 <_ZN7IniFile10GetSectionEPKc+0x18> */
/* @0x235ac8 mov r0, r4 */
/* @0x235acc pop {r3, r4, r5, pc} */

/* ── FUNC 0x235ad0 · IniFile::GetKey(char const*, char const*) · size=76 · insn=19 */
/* @0x235ad0 push {r3, r4, r5, lr} */
/* @0x235ad4 mov r5, r2 */
/* @0x235ad8 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc> */
/* @0x235adc cmp r0, #0 */
/* @0x235ae0 popeq {r3, r4, r5, pc} */
/* @0x235ae4 ldr r4, [r0, #0x4] */
/* @0x235ae8 cmp r4, #0 */
/* @0x235aec bne 0x235b00 <_ZN7IniFile6GetKeyEPKcS1_+0x30> */
/* @0x235af0 b 0x235b14 <_ZN7IniFile6GetKeyEPKcS1_+0x44> */
/* @0x235af4 ldr r4, [r4] */
/* @0x235af8 cmp r4, #0 */
/* @0x235afc beq 0x235b14 <_ZN7IniFile6GetKeyEPKcS1_+0x44> */
/* @0x235b00 mov r0, r5 */
/* @0x235b04 ldr r1, [r4, #0x4] */
/* @0x235b08 bl 0xb6574 <strcmp@plt> */
/* @0x235b0c cmp r0, #0 */
/* @0x235b10 bne 0x235af4 <_ZN7IniFile6GetKeyEPKcS1_+0x24> */
/* @0x235b14 mov r0, r4 */
/* @0x235b18 pop {r3, r4, r5, pc} */
