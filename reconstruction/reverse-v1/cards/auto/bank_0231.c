/* libyoyo.so 覆盖卡组 0231
 * 函数 0x27e14c..0x27ebec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x27e14c · array_list_new · size=100 · insn=25 */
/* @0x27e14c push {r3, r4, r5, lr} */
/* @0x27e150 mov r1, #16 */
/* @0x27e154 mov r5, r0 */
/* @0x27e158 mov r0, #1 */
/* @0x27e15c bl 0xb6c34 <calloc@plt> */
/* @0x27e160 subs r4, r0, #0 */
/* @0x27e164 beq 0x27e19c <array_list_new+0x50> */
/* @0x27e168 mov r1, #32 */
/* @0x27e16c str r5, [r4, #0xc] */
/* @0x27e170 mov r3, #0 */
/* @0x27e174 str r1, [r4, #0x8] */
/* @0x27e178 mov r0, #4 */
/* @0x27e17c str r3, [r4, #0x4] */
/* @0x27e180 bl 0xb6c34 <calloc@plt> */
/* @0x27e184 mov r5, r0 */
/* @0x27e188 cmp r5, #0 */
/* @0x27e18c mov r0, r4 */
/* @0x27e190 str r5, [r4] */
/* @0x27e194 beq 0x27e1a4 <array_list_new+0x58> */
/* @0x27e198 pop {r3, r4, r5, pc} */
/* @0x27e19c mov r0, r4 */
/* @0x27e1a0 pop {r3, r4, r5, pc} */
/* @0x27e1a4 bl 0xb655c <free@plt> */
/* @0x27e1a8 mov r0, r5 */
/* @0x27e1ac pop {r3, r4, r5, pc} */

/* ── FUNC 0x27e1b0 · array_list_free · size=80 · insn=20 */
/* @0x27e1b0 push {r3, r4, r5, lr} */
/* @0x27e1b4 mov r5, r0 */
/* @0x27e1b8 ldm r0, {r2, r3} */
/* @0x27e1bc cmp r3, #0 */
/* @0x27e1c0 movgt r4, #0 */
/* @0x27e1c4 ble 0x27e1ec <array_list_free+0x3c> */
/* @0x27e1c8 ldr r0, [r2, r4, lsl #2] */
/* @0x27e1cc add r4, r4, #1 */
/* @0x27e1d0 cmp r0, #0 */
/* @0x27e1d4 beq 0x27e1e4 <array_list_free+0x34> */
/* @0x27e1d8 ldr r3, [r5, #0xc] */
/* @0x27e1dc blx r3 */
/* @0x27e1e0 ldm r5, {r2, r3} */
/* @0x27e1e4 cmp r3, r4 */
/* @0x27e1e8 bgt 0x27e1c8 <array_list_free+0x18> */
/* @0x27e1ec mov r0, r2 */
/* @0x27e1f0 bl 0xb655c <free@plt> */
/* @0x27e1f4 mov r0, r5 */
/* @0x27e1f8 pop {r3, r4, r5, lr} */
/* @0x27e1fc b 0xb655c <free@plt> */

/* ── FUNC 0x27e200 · array_list_get_idx · size=24 · insn=6 */
/* @0x27e200 ldr r3, [r0, #0x4] */
/* @0x27e204 cmp r3, r1 */
/* @0x27e208 ldrgt r3, [r0] */
/* @0x27e20c ldrgt r0, [r3, r1, lsl #2] */
/* @0x27e210 movle r0, #0 */
/* @0x27e214 bx lr */

/* ── FUNC 0x27e218 · array_list_put_idx · size=188 · insn=47 */
/* @0x27e218 push {r3, r4, r5, r6, r7, lr} */
/* @0x27e21c mov r4, r0 */
/* @0x27e220 ldr r3, [r0, #0x8] */
/* @0x27e224 mov r5, r1 */
/* @0x27e228 mov r7, r2 */
/* @0x27e22c cmp r1, r3 */
/* @0x27e230 bge 0x27e27c <array_list_put_idx+0x64> */
/* @0x27e234 ldr r3, [r4] */
/* @0x27e238 lsl r6, r5, #2 */
/* @0x27e23c add r1, r3, r6 */
/* @0x27e240 ldr r0, [r3, r5, lsl #2] */
/* @0x27e244 cmp r0, #0 */
/* @0x27e248 beq 0x27e25c <array_list_put_idx+0x44> */
/* @0x27e24c ldr r3, [r4, #0xc] */
/* @0x27e250 blx r3 */
/* @0x27e254 ldr r1, [r4] */
/* @0x27e258 add r1, r1, r6 */
/* @0x27e25c ldr r3, [r4, #0x4] */
/* @0x27e260 str r7, [r1] */
/* @0x27e264 cmp r5, r3 */
/* @0x27e268 blt 0x27e2c4 <array_list_put_idx+0xac> */
/* @0x27e26c add r5, r5, #1 */
/* @0x27e270 mov r0, #0 */
/* @0x27e274 str r5, [r4, #0x4] */
/* @0x27e278 pop {r3, r4, r5, r6, r7, pc} */
/* @0x27e27c lsl r3, r3, #1 */
/* @0x27e280 ldr r0, [r0] */
/* @0x27e284 cmp r3, r1 */
/* @0x27e288 movge r6, r3 */
/* @0x27e28c movlt r6, r1 */
/* @0x27e290 lsl r1, r6, #2 */
/* @0x27e294 bl 0xb6c28 <realloc@plt> */
/* @0x27e298 cmp r0, #0 */
/* @0x27e29c beq 0x27e2cc <array_list_put_idx+0xb4> */
/* @0x27e2a0 ldr r3, [r4, #0x8] */
/* @0x27e2a4 mov r1, #0 */
/* @0x27e2a8 str r0, [r4] */
/* @0x27e2ac rsb r2, r3, r6 */
/* @0x27e2b0 add r0, r0, r3, lsl #2 */
/* @0x27e2b4 lsl r2, r2, #2 */
/* @0x27e2b8 bl 0xb65b0 <memset@plt> */
/* @0x27e2bc str r6, [r4, #0x8] */
/* @0x27e2c0 b 0x27e234 <array_list_put_idx+0x1c> */
/* @0x27e2c4 mov r0, #0 */
/* @0x27e2c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x27e2cc mvn r0, #0 */
/* @0x27e2d0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x27e2d4 · array_list_add · size=12 · insn=3 */
/* @0x27e2d4 mov r2, r1 */
/* @0x27e2d8 ldr r1, [r0, #0x4] */
/* @0x27e2dc b 0x27e218 <array_list_put_idx> */

/* ── FUNC 0x27e2e0 · array_list_length · size=8 · insn=2 */
/* @0x27e2e0 ldr r0, [r0, #0x4] */
/* @0x27e2e4 bx lr */

/* ── FUNC 0x27e2e8 · mc_set_debug · size=20 · insn=5 */
/* @0x27e2e8 ldr r3, [pc, #0x8] */
/* @0x27e2ec add r3, pc, r3 */
/* @0x27e2f0 str r0, [r3] */
/* @0x27e2f4 bx lr */
/* @0x27e2f8 subeq r8, sp, r4, asr #17 */

/* ── FUNC 0x27e2fc · mc_get_debug · size=16 · insn=4 */
/* @0x27e2fc ldr r3, [pc, #0x4] */
/* @0x27e300 ldr r0, [pc, r3] */
/* @0x27e304 bx lr */
/* @0x27e308 strheq r8, [sp], #-128 */

/* ── FUNC 0x27e30c · mc_set_syslog · size=20 · insn=5 */
/* @0x27e30c ldr r3, [pc, #0x8] */
/* @0x27e310 add r3, pc, r3 */
/* @0x27e314 str r0, [r3, #0x4] */
/* @0x27e318 bx lr */
/* @0x27e31c subeq r8, sp, r0, lsr #17 */

/* ── FUNC 0x27e320 · mc_abort · size=36 · insn=9 */
/* @0x27e320 push {r0, r1, r2, r3} */
/* @0x27e324 str lr, [sp, #-0x4]! */
/* @0x27e328 sub sp, sp, #12 */
/* @0x27e32c add r1, sp, #20 */
/* @0x27e330 ldr r0, [sp, #0x10] */
/* @0x27e334 str r1, [sp, #0x4] */
/* @0x27e338 bl 0xb6cf4 <vprintf@plt> */
/* @0x27e33c mov r0, #1 */
/* @0x27e340 bl 0xb6688 <exit@plt> */

/* ── FUNC 0x27e344 · mc_debug · size=68 · insn=17 */
/* @0x27e344 push {r0, r1, r2, r3} */
/* @0x27e348 ldr r3, [pc, #0x34] */
/* @0x27e34c str lr, [sp, #-0x4]! */
/* @0x27e350 add r3, pc, r3 */
/* @0x27e354 sub sp, sp, #12 */
/* @0x27e358 ldr r3, [r3] */
/* @0x27e35c cmp r3, #0 */
/* @0x27e360 beq 0x27e374 <mc_debug+0x30> */
/* @0x27e364 add r1, sp, #20 */
/* @0x27e368 ldr r0, [sp, #0x10] */
/* @0x27e36c str r1, [sp, #0x4] */
/* @0x27e370 bl 0xb6cf4 <vprintf@plt> */
/* @0x27e374 add sp, sp, #12 */
/* @0x27e378 ldr lr, [sp], #4 */
/* @0x27e37c add sp, sp, #16 */
/* @0x27e380 bx lr */
/* @0x27e384 subeq r8, sp, r0, ror #16 */

/* ── FUNC 0x27e388 · mc_error · size=64 · insn=16 */
/* @0x27e388 push {r0, r1, r2, r3} */
/* @0x27e38c ldr r0, [pc, #0x30] */
/* @0x27e390 str lr, [sp, #-0x4]! */
/* @0x27e394 sub sp, sp, #12 */
/* @0x27e398 add r3, sp, #20 */
/* @0x27e39c ldr r0, [pc, r0] */
/* @0x27e3a0 ldr r1, [sp, #0x10] */
/* @0x27e3a4 add r0, r0, #168 */
/* @0x27e3a8 mov r2, r3 */
/* @0x27e3ac str r3, [sp, #0x4] */
/* @0x27e3b0 bl 0xb6d00 <vfprintf@plt> */
/* @0x27e3b4 add sp, sp, #12 */
/* @0x27e3b8 ldr lr, [sp], #4 */
/* @0x27e3bc add sp, sp, #16 */
/* @0x27e3c0 bx lr */
/* @0x27e3c4 andseq r3, r7, r8, lsr #1 */

/* ── FUNC 0x27e3c8 · mc_info · size=64 · insn=16 */
/* @0x27e3c8 push {r0, r1, r2, r3} */
/* @0x27e3cc ldr r0, [pc, #0x30] */
/* @0x27e3d0 str lr, [sp, #-0x4]! */
/* @0x27e3d4 sub sp, sp, #12 */
/* @0x27e3d8 add r3, sp, #20 */
/* @0x27e3dc ldr r0, [pc, r0] */
/* @0x27e3e0 ldr r1, [sp, #0x10] */
/* @0x27e3e4 add r0, r0, #168 */
/* @0x27e3e8 mov r2, r3 */
/* @0x27e3ec str r3, [sp, #0x4] */
/* @0x27e3f0 bl 0xb6d00 <vfprintf@plt> */
/* @0x27e3f4 add sp, sp, #12 */
/* @0x27e3f8 ldr lr, [sp], #4 */
/* @0x27e3fc add sp, sp, #16 */
/* @0x27e400 bx lr */
/* @0x27e404 andseq r3, r7, r8, rrx */

/* ── FUNC 0x27e408 · anon_27e408 · size=936 · insn=235 */
/* @0x27e408 ldr r2, [r0, #0x18] */
/* @0x27e40c mov r0, r1 */
/* @0x27e410 ldr r1, [pc, #0x4] */
/* @0x27e414 add r1, pc, r1 */
/* @0x27e418 b 0x280dbc <sprintbuf> */
/* @0x27e41c strdeq r4, r5, [r11], -r8 */
/* @0x27e420 ldrd r2, r3, [r0, #24] */
/* @0x27e424 mov r0, r1 */
/* @0x27e428 ldr r1, [pc, #0x4] */
/* @0x27e42c add r1, pc, r1 */
/* @0x27e430 b 0x280dbc <sprintbuf> */
/* @0x27e434 andeq r1, r12, r8, ror #27 */
/* @0x27e438 mov r0, r1 */
/* @0x27e43c ldr r1, [pc, #0x10] */
/* @0x27e440 push {r3, lr} */
/* @0x27e444 add r1, pc, r1 */
/* @0x27e448 bl 0x280dbc <sprintbuf> */
/* @0x27e44c mov r0, #0 */
/* @0x27e450 pop {r3, pc} */
/* @0x27e454 andeq r3, r11, r0, ror #28 */
/* @0x27e458 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27e45c sub sp, sp, #20 */
/* @0x27e460 ldr r3, [pc, #0x1f0] */
/* @0x27e464 mov r5, #0 */
/* @0x27e468 ldr r10, [pc, #0x1ec] */
/* @0x27e46c mov r7, r1 */
/* @0x27e470 add r3, pc, r3 */
/* @0x27e474 ldr r9, [pc, #0x1e4] */
/* @0x27e478 str r3, [sp, #0xc] */
/* @0x27e47c add r10, pc, r10 */
/* @0x27e480 ldr r3, [pc, #0x1dc] */
/* @0x27e484 add r9, pc, r9 */
/* @0x27e488 ldr r8, [pc, #0x1d8] */
/* @0x27e48c sub r11, r1, #1 */
/* @0x27e490 add r3, pc, r3 */
/* @0x27e494 str r3, [sp, #0x8] */
/* @0x27e498 add r8, pc, r8 */
/* @0x27e49c ldr r3, [pc, #0x1c8] */
/* @0x27e4a0 mov r6, r0 */
/* @0x27e4a4 mov r1, r5 */
/* @0x27e4a8 add r3, pc, r3 */
/* @0x27e4ac str r3, [sp, #0x4] */
/* @0x27e4b0 ldrb r4, [r11, #0x1]! */
/* @0x27e4b4 mov r2, r5 */
/* @0x27e4b8 add r5, r5, #1 */
/* @0x27e4bc cmp r4, #13 */
/* @0x27e4c0 beq 0x27e570 <mc_info+0x1a8> */
/* @0x27e4c4 bhi 0x27e4f4 <mc_info+0x12c> */
/* @0x27e4c8 cmp r4, #0 */
/* @0x27e4cc bne 0x27e564 <mc_info+0x19c> */
/* @0x27e4d0 rsb r2, r1, r2 */
/* @0x27e4d4 cmp r2, #0 */
/* @0x27e4d8 ble 0x27e4e8 <mc_info+0x120> */
/* @0x27e4dc mov r0, r6 */
/* @0x27e4e0 add r1, r7, r1 */
/* @0x27e4e4 bl 0x280d20 <printbuf_memappend> */
/* @0x27e4e8 mov r0, #0 */
/* @0x27e4ec add sp, sp, #20 */
/* @0x27e4f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27e4f4 cmp r4, #47 */
/* @0x27e4f8 beq 0x27e570 <mc_info+0x1a8> */
/* @0x27e4fc cmp r4, #92 */
/* @0x27e500 beq 0x27e570 <mc_info+0x1a8> */
/* @0x27e504 cmp r4, #34 */
/* @0x27e508 beq 0x27e570 <mc_info+0x1a8> */
/* @0x27e50c cmp r4, #31 */
/* @0x27e510 bhi 0x27e4b0 <mc_info+0xe8> */
/* @0x27e514 rsb r2, r1, r2 */
/* @0x27e518 cmp r2, #0 */
/* @0x27e51c ble 0x27e52c <mc_info+0x164> */
/* @0x27e520 add r1, r7, r1 */
/* @0x27e524 mov r0, r6 */
/* @0x27e528 bl 0x280d20 <printbuf_memappend> */
/* @0x27e52c ldr r3, [pc, #0x13c] */
/* @0x27e530 and r12, r4, #15 */
/* @0x27e534 ldr r1, [pc, #0x138] */
/* @0x27e538 mov r0, r6 */
/* @0x27e53c ldr r3, [pc, r3] */
/* @0x27e540 add r1, pc, r1 */
/* @0x27e544 ldr r3, [r3] */
/* @0x27e548 ldrb r2, [r3, r4, lsr #4] */
/* @0x27e54c ldrb r3, [r3, r12] */
/* @0x27e550 bl 0x280dbc <sprintbuf> */
/* @0x27e554 cmp r4, #0 */
/* @0x27e558 mov r1, r5 */
/* @0x27e55c bne 0x27e4b0 <mc_info+0xe8> */
/* @0x27e560 b 0x27e4e8 <mc_info+0x120> */
/* @0x27e564 sub r3, r4, #8 */
/* @0x27e568 cmp r3, #2 */
/* @0x27e56c bhi 0x27e50c <mc_info+0x144> */
/* @0x27e570 rsb r2, r1, r2 */
/* @0x27e574 cmp r2, #0 */
/* @0x27e578 ble 0x27e588 <mc_info+0x1c0> */
/* @0x27e57c add r1, r7, r1 */
/* @0x27e580 mov r0, r6 */
/* @0x27e584 bl 0x280d20 <printbuf_memappend> */
/* @0x27e588 cmp r4, #8 */
/* @0x27e58c beq 0x27e5c8 <mc_info+0x200> */
/* @0x27e590 cmp r4, #10 */
/* @0x27e594 beq 0x27e5e0 <mc_info+0x218> */
/* @0x27e598 cmp r4, #13 */
/* @0x27e59c beq 0x27e5f4 <mc_info+0x22c> */
/* @0x27e5a0 cmp r4, #9 */
/* @0x27e5a4 beq 0x27e608 <mc_info+0x240> */
/* @0x27e5a8 cmp r4, #34 */
/* @0x27e5ac beq 0x27e61c <mc_info+0x254> */
/* @0x27e5b0 cmp r4, #92 */
/* @0x27e5b4 beq 0x27e630 <mc_info+0x268> */
/* @0x27e5b8 cmp r4, #47 */
/* @0x27e5bc beq 0x27e644 <mc_info+0x27c> */
/* @0x27e5c0 mov r1, r5 */
/* @0x27e5c4 b 0x27e4b0 <mc_info+0xe8> */
/* @0x27e5c8 ldr r1, [pc, #0xa8] */
/* @0x27e5cc mov r0, r6 */
/* @0x27e5d0 mov r2, #2 */
/* @0x27e5d4 add r1, pc, r1 */
/* @0x27e5d8 bl 0x280d20 <printbuf_memappend> */
/* @0x27e5dc b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e5e0 mov r0, r6 */
/* @0x27e5e4 mov r1, r8 */
/* @0x27e5e8 mov r2, #2 */
/* @0x27e5ec bl 0x280d20 <printbuf_memappend> */
/* @0x27e5f0 b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e5f4 mov r0, r6 */
/* @0x27e5f8 mov r1, r9 */
/* @0x27e5fc mov r2, #2 */
/* @0x27e600 bl 0x280d20 <printbuf_memappend> */
/* @0x27e604 b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e608 mov r0, r6 */
/* @0x27e60c mov r1, r10 */
/* @0x27e610 mov r2, #2 */
/* @0x27e614 bl 0x280d20 <printbuf_memappend> */
/* @0x27e618 b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e61c mov r0, r6 */
/* @0x27e620 ldr r1, [sp, #0x4] */
/* @0x27e624 mov r2, #2 */
/* @0x27e628 bl 0x280d20 <printbuf_memappend> */
/* @0x27e62c b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e630 mov r0, r6 */
/* @0x27e634 ldr r1, [sp, #0x8] */
/* @0x27e638 mov r2, #2 */
/* @0x27e63c bl 0x280d20 <printbuf_memappend> */
/* @0x27e640 b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e644 mov r0, r6 */
/* @0x27e648 ldr r1, [sp, #0xc] */
/* @0x27e64c mov r2, #2 */
/* @0x27e650 bl 0x280d20 <printbuf_memappend> */
/* @0x27e654 b 0x27e5c0 <mc_info+0x1f8> */
/* @0x27e658 andeq r8, sp, r4, lsr #28 */
/* @0x27e65c andeq r8, sp, r12, lsl #28 */
/* @0x27e660 andeq r8, sp, r0, lsl #28 */
/* @0x27e664 andeq r8, sp, r0, lsl #28 */
/* @0x27e668 andeq r8, sp, r8, ror #27 */
/* @0x27e66c andeq r8, sp, r4, ror #27 */
/* @0x27e670 andseq r3, r7, r12, asr #6 */
/* @0x27e674 andeq r8, sp, r8, asr sp */
/* @0x27e678 andeq r8, sp, r8, lsr #25 */
/* @0x27e67c push {r4, r5, r6, lr} */
/* @0x27e680 mov r4, r1 */
/* @0x27e684 ldr r5, [pc, #0x30] */
/* @0x27e688 mov r6, r0 */
/* @0x27e68c mov r0, r1 */
/* @0x27e690 add r5, pc, r5 */
/* @0x27e694 mov r1, r5 */
/* @0x27e698 bl 0x280dbc <sprintbuf> */
/* @0x27e69c ldr r1, [r6, #0x18] */
/* @0x27e6a0 mov r0, r4 */
/* @0x27e6a4 bl 0x27e458 <mc_info+0x90> */
/* @0x27e6a8 mov r0, r4 */
/* @0x27e6ac mov r1, r5 */
/* @0x27e6b0 bl 0x280dbc <sprintbuf> */
/* @0x27e6b4 mov r0, #0 */
/* @0x27e6b8 pop {r4, r5, r6, pc} */
/* @0x27e6bc andeq r8, sp, r4, lsl r12 */
/* @0x27e6c0 push {r4, lr} */
/* @0x27e6c4 mov r4, r0 */
/* @0x27e6c8 ldr r0, [r0, #0x10] */
/* @0x27e6cc bl 0x280eb0 <printbuf_free> */
/* @0x27e6d0 mov r0, r4 */
/* @0x27e6d4 pop {r4, lr} */
/* @0x27e6d8 b 0xb655c <free@plt> */
/* @0x27e6dc push {r4, lr} */
/* @0x27e6e0 mov r4, r0 */
/* @0x27e6e4 ldr r0, [r0, #0x18] */
/* @0x27e6e8 bl 0x28094c <lh_table_free> */
/* @0x27e6ec ldr r0, [r4, #0x10] */
/* @0x27e6f0 bl 0x280eb0 <printbuf_free> */
/* @0x27e6f4 mov r0, r4 */
/* @0x27e6f8 pop {r4, lr} */
/* @0x27e6fc b 0xb655c <free@plt> */
/* @0x27e700 push {r4, lr} */
/* @0x27e704 mov r4, r0 */
/* @0x27e708 ldr r0, [r0, #0x18] */
/* @0x27e70c bl 0xb655c <free@plt> */
/* @0x27e710 ldr r0, [r4, #0x10] */
/* @0x27e714 bl 0x280eb0 <printbuf_free> */
/* @0x27e718 mov r0, r4 */
/* @0x27e71c pop {r4, lr} */
/* @0x27e720 b 0xb655c <free@plt> */
/* @0x27e724 push {r4, lr} */
/* @0x27e728 mov r1, #1 */
/* @0x27e72c mov r4, r0 */
/* @0x27e730 mov r0, #32 */
/* @0x27e734 bl 0xb6c34 <calloc@plt> */
/* @0x27e738 cmp r0, #0 */
/* @0x27e73c popeq {r4, pc} */
/* @0x27e740 ldr r3, [pc, #0x14] */
/* @0x27e744 mov r2, #1 */
/* @0x27e748 str r4, [r0] */
/* @0x27e74c add r3, pc, r3 */
/* @0x27e750 str r2, [r0, #0xc] */
/* @0x27e754 str r3, [r0, #0x4] */
/* @0x27e758 pop {r4, pc} */
/* @0x27e75c .word 0xffffff6c */
/* @0x27e760 push {r4, lr} */
/* @0x27e764 mov r4, r0 */
/* @0x27e768 ldr r0, [r0, #0x18] */
/* @0x27e76c bl 0x27e1b0 <array_list_free> */
/* @0x27e770 ldr r0, [r4, #0x10] */
/* @0x27e774 bl 0x280eb0 <printbuf_free> */
/* @0x27e778 mov r0, r4 */
/* @0x27e77c pop {r4, lr} */
/* @0x27e780 b 0xb655c <free@plt> */
/* @0x27e784 ldr r3, [r0, #0x18] */
/* @0x27e788 mov r0, r1 */
/* @0x27e78c cmp r3, #0 */
/* @0x27e790 bne 0x27e7a0 <mc_info+0x3d8> */
/* @0x27e794 ldr r1, [pc, #0x10] */
/* @0x27e798 add r1, pc, r1 */
/* @0x27e79c b 0x280dbc <sprintbuf> */
/* @0x27e7a0 ldr r1, [pc, #0x8] */
/* @0x27e7a4 add r1, pc, r1 */
/* @0x27e7a8 b 0x280dbc <sprintbuf> */
/* @0x27e7ac muleq r11, r0, r2 */
/* @0x27e7b0 andeq r6, r11, r12, ror r2 */

/* ── FUNC 0x27e7b4 · json_object_get · size=20 · insn=5 */
/* @0x27e7b4 cmp r0, #0 */
/* @0x27e7b8 ldrne r3, [r0, #0xc] */
/* @0x27e7bc addne r3, r3, #1 */
/* @0x27e7c0 strne r3, [r0, #0xc] */
/* @0x27e7c4 bx lr */

/* ── FUNC 0x27e7c8 · json_object_put · size=44 · insn=11 */
/* @0x27e7c8 push {r3, lr} */
/* @0x27e7cc subs r3, r0, #0 */
/* @0x27e7d0 popeq {r3, pc} */
/* @0x27e7d4 ldr r2, [r3, #0xc] */
/* @0x27e7d8 sub r2, r2, #1 */
/* @0x27e7dc str r2, [r3, #0xc] */
/* @0x27e7e0 cmp r2, #0 */
/* @0x27e7e4 popne {r3, pc} */
/* @0x27e7e8 ldr r3, [r3, #0x4] */
/* @0x27e7ec blx r3 */
/* @0x27e7f0 pop {r3, pc} */

/* ── FUNC 0x27e7f4 · anon_27e7f4 · size=28 · insn=8 */
/* @0x27e7f4 push {r4, lr} */
/* @0x27e7f8 mov r4, r0 */
/* @0x27e7fc ldr r0, [r0] */
/* @0x27e800 bl 0xb655c <free@plt> */
/* @0x27e804 ldr r0, [r4, #0x4] */
/* @0x27e808 pop {r4, lr} */
/* @0x27e80c b 0x27e7c8 <json_object_put> */
/* @0x27e810 b 0x27e7c8 <json_object_put> */

/* ── FUNC 0x27e814 · json_object_is_type · size=20 · insn=5 */
/* @0x27e814 ldr r0, [r0] */
/* @0x27e818 subs r3, r0, r1 */
/* @0x27e81c rsbs r0, r3, #0 */
/* @0x27e820 adcs r0, r0, r3 */
/* @0x27e824 bx lr */

/* ── FUNC 0x27e828 · json_object_get_type · size=8 · insn=2 */
/* @0x27e828 ldr r0, [r0] */
/* @0x27e82c bx lr */

/* ── FUNC 0x27e830 · json_object_to_json_string · size=108 · insn=27 */
/* @0x27e830 push {r4, lr} */
/* @0x27e834 subs r4, r0, #0 */
/* @0x27e838 beq 0x27e88c <json_object_to_json_string+0x5c> */
/* @0x27e83c ldr r0, [r4, #0x10] */
/* @0x27e840 cmp r0, #0 */
/* @0x27e844 beq 0x27e870 <json_object_to_json_string+0x40> */
/* @0x27e848 bl 0x280e9c <printbuf_reset> */
/* @0x27e84c ldr r1, [r4, #0x10] */
/* @0x27e850 ldr r3, [r4, #0x8] */
/* @0x27e854 mov r0, r4 */
/* @0x27e858 blx r3 */
/* @0x27e85c cmp r0, #0 */
/* @0x27e860 blt 0x27e884 <json_object_to_json_string+0x54> */
/* @0x27e864 ldr r3, [r4, #0x10] */
/* @0x27e868 ldr r0, [r3] */
/* @0x27e86c pop {r4, pc} */
/* @0x27e870 bl 0x280cc8 <printbuf_new> */
/* @0x27e874 cmp r0, #0 */
/* @0x27e878 mov r1, r0 */
/* @0x27e87c str r0, [r4, #0x10] */
/* @0x27e880 bne 0x27e850 <json_object_to_json_string+0x20> */
/* @0x27e884 mov r0, #0 */
/* @0x27e888 pop {r4, pc} */
/* @0x27e88c ldr r0, [pc, #0x4] */
/* @0x27e890 add r0, pc, r0 */
/* @0x27e894 pop {r4, pc} */
/* @0x27e898 andeq r3, r11, r4, lsl r10 */

/* ── FUNC 0x27e89c · json_object_new_object · size=88 · insn=22 */
/* @0x27e89c push {r4, lr} */
/* @0x27e8a0 mov r0, #4 */
/* @0x27e8a4 bl 0x27e724 <mc_info+0x35c> */
/* @0x27e8a8 subs r4, r0, #0 */
/* @0x27e8ac beq 0x27e8e0 <json_object_new_object+0x44> */
/* @0x27e8b0 ldr r12, [pc, #0x30] */
/* @0x27e8b4 mov r0, #16 */
/* @0x27e8b8 ldr r3, [pc, #0x2c] */
/* @0x27e8bc mov r1, #0 */
/* @0x27e8c0 ldr r2, [pc, #0x28] */
/* @0x27e8c4 add r12, pc, r12 */
/* @0x27e8c8 add r3, pc, r3 */
/* @0x27e8cc str r12, [r4, #0x4] */
/* @0x27e8d0 add r2, pc, r2 */
/* @0x27e8d4 str r3, [r4, #0x8] */
/* @0x27e8d8 bl 0x2808ec <lh_kchar_table_new> */
/* @0x27e8dc str r0, [r4, #0x18] */
/* @0x27e8e0 mov r0, r4 */
/* @0x27e8e4 pop {r4, pc} */
/* @0x27e8e8 .word 0xfffffe10 */
/* @0x27e8ec andeq r0, r0, r0, asr #32 */
/* @0x27e8f0 .word 0xffffff1c */

/* ── FUNC 0x27e8f4 · json_object_get_object · size=28 · insn=7 */
/* @0x27e8f4 cmp r0, #0 */
/* @0x27e8f8 bxeq lr */
/* @0x27e8fc ldr r3, [r0] */
/* @0x27e900 cmp r3, #4 */
/* @0x27e904 ldreq r0, [r0, #0x18] */
/* @0x27e908 movne r0, #0 */
/* @0x27e90c bx lr */

/* ── FUNC 0x27e910 · anon_27e910 · size=236 · insn=60 */
/* @0x27e910 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27e914 mov r4, r1 */
/* @0x27e918 ldr r1, [pc, #0xc8] */
/* @0x27e91c mov r5, r0 */
/* @0x27e920 mov r0, r4 */
/* @0x27e924 add r1, pc, r1 */
/* @0x27e928 bl 0x280dbc <sprintbuf> */
/* @0x27e92c mov r0, r5 */
/* @0x27e930 bl 0x27e8f4 <json_object_get_object> */
/* @0x27e934 ldr r5, [r0, #0x20] */
/* @0x27e938 cmp r5, #0 */
/* @0x27e93c beq 0x27e9d4 <json_object_get_object+0xe0> */
/* @0x27e940 ldr r10, [pc, #0xa4] */
/* @0x27e944 ldr r9, [pc, #0xa4] */
/* @0x27e948 ldr r11, [pc, #0xa4] */
/* @0x27e94c add r10, pc, r10 */
/* @0x27e950 ldr r8, [pc, #0xa0] */
/* @0x27e954 add r9, pc, r9 */
/* @0x27e958 ldr r7, [r5] */
/* @0x27e95c add r11, pc, r11 */
/* @0x27e960 ldr r6, [r5, #0x4] */
/* @0x27e964 add r8, pc, r8 */
/* @0x27e968 b 0x27e994 <json_object_get_object+0xa0> */
/* @0x27e96c ldr r3, [r6, #0x8] */
/* @0x27e970 blx r3 */
/* @0x27e974 ldr r5, [r5, #0x8] */
/* @0x27e978 mov r0, r4 */
/* @0x27e97c mov r1, r8 */
/* @0x27e980 cmp r5, #0 */
/* @0x27e984 beq 0x27e9d4 <json_object_get_object+0xe0> */
/* @0x27e988 ldr r7, [r5] */
/* @0x27e98c ldr r6, [r5, #0x4] */
/* @0x27e990 bl 0x280dbc <sprintbuf> */
/* @0x27e994 mov r1, r10 */
/* @0x27e998 mov r0, r4 */
/* @0x27e99c bl 0x280dbc <sprintbuf> */
/* @0x27e9a0 mov r1, r7 */
/* @0x27e9a4 mov r0, r4 */
/* @0x27e9a8 bl 0x27e458 <mc_info+0x90> */
/* @0x27e9ac mov r1, r9 */
/* @0x27e9b0 mov r0, r4 */
/* @0x27e9b4 bl 0x280dbc <sprintbuf> */
/* @0x27e9b8 subs r0, r6, #0 */
/* @0x27e9bc mov r1, r4 */
/* @0x27e9c0 bne 0x27e96c <json_object_get_object+0x78> */
/* @0x27e9c4 mov r0, r4 */
/* @0x27e9c8 mov r1, r11 */
/* @0x27e9cc bl 0x280dbc <sprintbuf> */
/* @0x27e9d0 b 0x27e974 <json_object_get_object+0x80> */
/* @0x27e9d4 ldr r1, [pc, #0x20] */
/* @0x27e9d8 mov r0, r4 */
/* @0x27e9dc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27e9e0 add r1, pc, r1 */
/* @0x27e9e4 b 0x280dbc <sprintbuf> */
/* @0x27e9e8 andeq r8, sp, r4, lsl #19 */
/* @0x27e9ec andeq r8, sp, r0, ror #18 */
/* @0x27e9f0 andeq r8, sp, r12, asr r9 */
/* @0x27e9f4 andeq r3, r11, r8, asr #18 */
/* @0x27e9f8 andeq r3, r11, r0, asr #23 */
/* @0x27e9fc andeq r3, r11, r0, asr #22 */

/* ── FUNC 0x27ea00 · json_object_object_add · size=56 · insn=14 */
/* @0x27ea00 push {r4, r5, r6, lr} */
/* @0x27ea04 mov r5, r1 */
/* @0x27ea08 mov r4, r0 */
/* @0x27ea0c ldr r0, [r0, #0x18] */
/* @0x27ea10 mov r6, r2 */
/* @0x27ea14 bl 0x280ca0 <lh_table_delete> */
/* @0x27ea18 mov r0, r5 */
/* @0x27ea1c ldr r4, [r4, #0x18] */
/* @0x27ea20 bl 0xb6640 <strdup@plt> */
/* @0x27ea24 mov r2, r6 */
/* @0x27ea28 mov r1, r0 */
/* @0x27ea2c mov r0, r4 */
/* @0x27ea30 pop {r4, r5, r6, lr} */
/* @0x27ea34 b 0x280998 <lh_table_insert> */

/* ── FUNC 0x27ea38 · json_object_object_get · size=8 · insn=2 */
/* @0x27ea38 ldr r0, [r0, #0x18] */
/* @0x27ea3c b 0x280bac <lh_table_lookup> */

/* ── FUNC 0x27ea40 · json_object_object_del · size=8 · insn=2 */
/* @0x27ea40 ldr r0, [r0, #0x18] */
/* @0x27ea44 b 0x280ca0 <lh_table_delete> */

/* ── FUNC 0x27ea48 · json_object_new_boolean · size=48 · insn=12 */
/* @0x27ea48 push {r4, lr} */
/* @0x27ea4c mov r4, r0 */
/* @0x27ea50 mov r0, #1 */
/* @0x27ea54 bl 0x27e724 <mc_info+0x35c> */
/* @0x27ea58 cmp r0, #0 */
/* @0x27ea5c popeq {r4, pc} */
/* @0x27ea60 ldr r3, [pc, #0xc] */
/* @0x27ea64 str r4, [r0, #0x18] */
/* @0x27ea68 add r3, pc, r3 */
/* @0x27ea6c str r3, [r0, #0x8] */
/* @0x27ea70 pop {r4, pc} */
/* @0x27ea74 .word 0xfffffd14 */

/* ── FUNC 0x27ea78 · json_object_get_boolean · size=128 · insn=32 */
/* @0x27ea78 cmp r0, #0 */
/* @0x27ea7c bxeq lr */
/* @0x27ea80 ldr r3, [r0] */
/* @0x27ea84 sub r3, r3, #1 */
/* @0x27ea88 cmp r3, #5 */
/* @0x27ea8c addls pc, pc, r3, lsl #2 */
/* @0x27ea90 b 0x27eaf0 <json_object_get_boolean+0x78> */
/* @0x27ea94 b 0x27eac0 <json_object_get_boolean+0x48> */
/* @0x27ea98 b 0x27eac8 <json_object_get_boolean+0x50> */
/* @0x27ea9c b 0x27eae0 <json_object_get_boolean+0x68> */
/* @0x27eaa0 b 0x27eaf0 <json_object_get_boolean+0x78> */
/* @0x27eaa4 b 0x27eaf0 <json_object_get_boolean+0x78> */
/* @0x27eaa8 b 0x27eaac <json_object_get_boolean+0x34> */
/* @0x27eaac ldr r3, [r0, #0x18] */
/* @0x27eab0 ldrb r0, [r3] */
/* @0x27eab4 adds r0, r0, #0 */
/* @0x27eab8 movne r0, #1 */
/* @0x27eabc bx lr */
/* @0x27eac0 ldr r0, [r0, #0x18] */
/* @0x27eac4 bx lr */
/* @0x27eac8 vldr d7, [r0, #24] */
/* @0x27eacc vcmp.f64 d7, #0 */
/* @0x27ead0 vmrs APSR_nzcv, fpscr */
/* @0x27ead4 moveq r0, #0 */
/* @0x27ead8 movne r0, #1 */
/* @0x27eadc bx lr */
/* @0x27eae0 ldr r0, [r0, #0x18] */
/* @0x27eae4 adds r0, r0, #0 */
/* @0x27eae8 movne r0, #1 */
/* @0x27eaec bx lr */
/* @0x27eaf0 mov r0, #0 */
/* @0x27eaf4 bx lr */

/* ── FUNC 0x27eaf8 · json_object_new_int · size=48 · insn=12 */
/* @0x27eaf8 push {r4, lr} */
/* @0x27eafc mov r4, r0 */
/* @0x27eb00 mov r0, #3 */
/* @0x27eb04 bl 0x27e724 <mc_info+0x35c> */
/* @0x27eb08 cmp r0, #0 */
/* @0x27eb0c popeq {r4, pc} */
/* @0x27eb10 ldr r3, [pc, #0xc] */
/* @0x27eb14 str r4, [r0, #0x18] */
/* @0x27eb18 add r3, pc, r3 */
/* @0x27eb1c str r3, [r0, #0x8] */
/* @0x27eb20 pop {r4, pc} */
/* @0x27eb24 .word 0xfffff8e8 */

/* ── FUNC 0x27eb28 · json_object_get_int · size=144 · insn=36 */
/* @0x27eb28 cmp r0, #0 */
/* @0x27eb2c str lr, [sp, #-0x4]! */
/* @0x27eb30 sub sp, sp, #12 */
/* @0x27eb34 beq 0x27eb70 <json_object_get_int+0x48> */
/* @0x27eb38 ldr r3, [r0] */
/* @0x27eb3c sub r3, r3, #1 */
/* @0x27eb40 cmp r3, #5 */
/* @0x27eb44 addls pc, pc, r3, lsl #2 */
/* @0x27eb48 b 0x27eb70 <json_object_get_int+0x48> */
/* @0x27eb4c b 0x27eb64 <json_object_get_int+0x3c> */
/* @0x27eb50 b 0x27eba0 <json_object_get_int+0x78> */
/* @0x27eb54 b 0x27eb64 <json_object_get_int+0x3c> */
/* @0x27eb58 b 0x27eb70 <json_object_get_int+0x48> */
/* @0x27eb5c b 0x27eb70 <json_object_get_int+0x48> */
/* @0x27eb60 b 0x27eb7c <json_object_get_int+0x54> */
/* @0x27eb64 ldr r0, [r0, #0x18] */
/* @0x27eb68 add sp, sp, #12 */
/* @0x27eb6c ldr pc, [sp], #4 */
/* @0x27eb70 mov r0, #0 */
/* @0x27eb74 add sp, sp, #12 */
/* @0x27eb78 ldr pc, [sp], #4 */
/* @0x27eb7c ldr r1, [pc, #0x30] */
/* @0x27eb80 add r2, sp, #4 */
/* @0x27eb84 ldr r0, [r0, #0x18] */
/* @0x27eb88 add r1, pc, r1 */
/* @0x27eb8c bl 0xb68f8 <sscanf@plt> */
/* @0x27eb90 cmp r0, #1 */
/* @0x27eb94 bne 0x27eb70 <json_object_get_int+0x48> */
/* @0x27eb98 ldr r0, [sp, #0x4] */
/* @0x27eb9c b 0x27eb68 <json_object_get_int+0x40> */
/* @0x27eba0 vldr d7, [r0, #24] */
/* @0x27eba4 vcvt.s32.f64 s13, d7 */
/* @0x27eba8 vmov r0, s13 */
/* @0x27ebac add sp, sp, #12 */
/* @0x27ebb0 ldr pc, [sp], #4 */
/* @0x27ebb4 andeq r3, r11, r4, lsl #19 */

/* ── FUNC 0x27ebb8 · json_object_new_double · size=52 · insn=13 */
/* @0x27ebb8 push {r3, r4, r5, lr} */
/* @0x27ebbc mov r4, r0 */
/* @0x27ebc0 mov r0, #2 */
/* @0x27ebc4 mov r5, r1 */
/* @0x27ebc8 bl 0x27e724 <mc_info+0x35c> */
/* @0x27ebcc cmp r0, #0 */
/* @0x27ebd0 popeq {r3, r4, r5, pc} */
/* @0x27ebd4 ldr r3, [pc, #0xc] */
/* @0x27ebd8 strd r4, r5, [r0, #24] */
/* @0x27ebdc add r3, pc, r3 */
/* @0x27ebe0 str r3, [r0, #0x8] */
/* @0x27ebe4 pop {r3, r4, r5, pc} */
/* @0x27ebe8 .word 0xfffff83c */

/* ── FUNC 0x27ebec · anon_27ebec · size=0 · insn=1 */
/* @0x27ebec andeq r0, r0, r0 */
