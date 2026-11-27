/* libyoyo.so 覆盖卡组 0257
 * 函数 0x2acbec..0x2aec48，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2acbec · png_handle_tRNS · size=372 · insn=171 */
/* @0x2acbec ldr r3, [pc, #0x148] */
/* @0x2acbee push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2acbf0 ldrbtmi r4, [r11], #-496 */
/* @0x2acbf2 add r3, pc */
/* @0x2acbf4 ldr r3, [r3] */
/* @0x2acbf6 mov r5, r2 */
/* @0x2acbf8 sub sp, #0x118 */
/* @0x2acbfa ldr r2, [r3] */
/* @0x2acbfc mov r4, r0 */
/* @0x2acbfe mov r7, r1 */
/* @0x2acc00 mov r8, r3 */
/* @0x2acc02 str r2, [sp, #0x114] */
/* @0x2acc04 ldr.w r2, [r0, #0x12c] */
/* @0x2acc08 tst.w r2, #0x1 */
/* @0x2acc0c bne 0x2acc18 <png_handle_tRNS+0x2c> */
/* @0x2acc0e ldr r1, [pc, #0x12c] */
/* @0x2acc10 add r1, pc */
/* @0x2acc12 bl 0x2a642c <png_error> */
/* @0x2acc14 and pc, r11, r11, lsl #24 */
/* @0x2acc16 b 0x2acc30 <png_handle_tRNS+0x44> */
/* @0x2acc18 lsls r1, r2, #0x1d */
/* @0x2acc1a bpl 0x2acc22 <png_handle_tRNS+0x36> */
/* @0x2acc1c ldr r1, [pc, #0x120] */
/* @0x2acc1e add r1, pc */
/* @0x2acc20 b 0x2accee <png_handle_tRNS+0x102> */
/* @0x2acc22 cbz r7, 0x2acc30 <png_handle_tRNS+0x44> */
/* @0x2acc24 ldr r3, [r7, #0x8] */
/* @0x2acc26 lsls r2, r3, #0x1b */
/* @0x2acc28 bpl 0x2acc30 <png_handle_tRNS+0x44> */
/* @0x2acc2a ldr r1, [pc, #0x118] */
/* @0x2acc2c add r1, pc */
/* @0x2acc2e b 0x2accee <png_handle_tRNS+0x102> */
/* @0x2acc30 ldrb.w r2, [r4, #0x1ea] */
/* @0x2acc34 cbnz r2, 0x2acc60 <png_handle_tRNS+0x74> */
/* @0x2acc36 cmp r5, #0x2 */
/* @0x2acc38 mov r0, r4 */
/* @0x2acc3a beq 0x2acc42 <png_handle_tRNS+0x56> */
/* @0x2acc3c ldr r1, [pc, #0x108] */
/* @0x2acc3e add r1, pc */
/* @0x2acc40 b 0x2accee <png_handle_tRNS+0x102> */
/* @0x2acc42 add r6, sp, #0xc */
/* @0x2acc44 mov r2, r5 */
/* @0x2acc46 mov r1, r6 */
/* @0x2acc48 bl 0x2abc0c <png_crc_read> */
/* @0x2acc4c ldrb r2, [r6] */
/* @0x2acc4e movs r3, #0x1 */
/* @0x2acc50 strh.w r3, [r4, #0x1de] */
/* @0x2acc54 ldrb r3, [r6, #0x1] */
/* @0x2acc56 add.w r3, r3, r2, lsl #8 */
/* @0x2acc58 .word 0xf8a42302 */
/* @0x2acc5a strh.w r3, [r4, #0x258] */
/* @0x2acc5c sub r3, sp, r8, asr r2 */
/* @0x2acc5e b 0x2accfc <png_handle_tRNS+0x110> */
/* @0x2acc60 cmp r2, #0x2 */
/* @0x2acc62 bne 0x2acca6 <png_handle_tRNS+0xba> */
/* @0x2acc64 cmp r5, #0x6 */
/* @0x2acc66 mov r0, r4 */
/* @0x2acc68 beq 0x2acc70 <png_handle_tRNS+0x84> */
/* @0x2acc6a ldr r1, [pc, #0xe0] */
/* @0x2acc6c add r1, pc */
/* @0x2acc6e b 0x2accee <png_handle_tRNS+0x102> */
/* @0x2acc70 add r6, sp, #0xc */
/* @0x2acc72 mov r2, r5 */
/* @0x2acc74 mov r1, r6 */
/* @0x2acc76 bl 0x2abc0c <png_crc_read> */
/* @0x2acc78 ldmdavc r2!, {r0, r3, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2acc7a ldrb r2, [r6] */
/* @0x2acc7c movs r3, #0x1 */
/* @0x2acc7e strh.w r3, [r4, #0x1de] */
/* @0x2acc80 ldmdavc r3!, {r1, r2, r3, r4, r6, r7, r8, r12, sp} ^ */
/* @0x2acc82 ldrb r3, [r6, #0x1] */
/* @0x2acc84 add.w r3, r3, r2, lsl #8 */
/* @0x2acc88 ldrb r2, [r6, #0x2] */
/* @0x2acc8a strh.w r3, [r4, #0x252] */
/* @0x2acc8c ldmvc r3!, {r1, r4, r6, r9, r12, sp} ^ */
/* @0x2acc8e ldrb r3, [r6, #0x3] */
/* @0x2acc90 add.w r3, r3, r2, lsl #8 */
/* @0x2acc94 ldrb r2, [r6, #0x4] */
/* @0x2acc96 strh.w r3, [r4, #0x254] */
/* @0x2acc98 ldmdbvc r3!, {r2, r4, r6, r9, r12, sp} ^ */
/* @0x2acc9a ldrb r3, [r6, #0x5] */
/* @0x2acc9c add.w r3, r3, r2, lsl #8 */
/* @0x2acca0 strh.w r3, [r4, #0x256] */
/* @0x2acca4 b 0x2accfc <png_handle_tRNS+0x110> */
/* @0x2acca6 cmp r2, #0x3 */
/* @0x2acca8 bne 0x2acce8 <png_handle_tRNS+0xfc> */
/* @0x2accaa ldr.w r3, [r4, #0x12c] */
/* @0x2accac ldreq r3, [r11, r12, lsr #2] */
/* @0x2accae lsls r3, r3, #0x1e */
/* @0x2accb0 bmi 0x2accbc <png_handle_tRNS+0xd0> */
/* @0x2accb2 ldr r1, [pc, #0x9c] */
/* @0x2accb4 mov r0, r4 */
/* @0x2accb6 add r1, pc */
/* @0x2accb8 bl 0x2a6474 <png_warning> */
/* @0x2accbc ldrh.w r3, [r4, #0x1dc] */
/* @0x2accc0 mov r0, r4 */
/* @0x2accc2 cmp r5, r3 */
/* @0x2accc4 bhi 0x2acccc <png_handle_tRNS+0xe0> */
/* @0x2accc6 cmp.w r5, #0x100 */
/* @0x2accc8 stmdble r2, {r7, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2accca bls 0x2accd2 <png_handle_tRNS+0xe6> */
/* @0x2acccc ldr r1, [pc, #0x84] */
/* @0x2accce add r1, pc */
/* @0x2accd0 b 0x2accee <png_handle_tRNS+0x102> */
/* @0x2accd2 cbnz r5, 0x2accda <png_handle_tRNS+0xee> */
/* @0x2accd4 ldr r1, [pc, #0x80] */
/* @0x2accd6 add r1, pc */
/* @0x2accd8 b 0x2accee <png_handle_tRNS+0x102> */
/* @0x2accda add r1, sp, #0x14 */
/* @0x2accdc mov r2, r5 */
/* @0x2accde bl 0x2abc0c <png_crc_read> */
/* @0x2acce0 .word 0xf8a4ff95 */
/* @0x2acce2 strh.w r5, [r4, #0x1de] */
/* @0x2acce4 ldrd r5, r6, [r9], -lr */
/* @0x2acce6 b 0x2accfc <png_handle_tRNS+0x110> */
/* @0x2acce8 ldr r1, [pc, #0x70] */
/* @0x2accea mov r0, r4 */
/* @0x2accec add r1, pc */
/* @0x2accee bl 0x2a6474 <png_warning> */
/* @0x2accf0 strtmi pc, [r0], -r1, asr #23 */
/* @0x2accf2 mov r0, r4 */
/* @0x2accf4 mov r1, r5 */
/* @0x2accf6 bl 0x2abc94 <png_crc_finish> */
/* @0x2accf8 ands pc, r2, sp, asr #31 */
/* @0x2accfa b 0x2acd22 <png_handle_tRNS+0x136> */
/* @0x2accfc mov r0, r4 */
/* @0x2accfe movs r1, #0x0 */
/* @0x2acd00 bl 0x2abc94 <png_crc_finish> */
/* @0x2acd04 cbz r0, 0x2acd0e <png_handle_tRNS+0x122> */
/* @0x2acd06 movs r3, #0x0 */
/* @0x2acd08 strh.w r3, [r4, #0x1de] */
/* @0x2acd0c b 0x2acd22 <png_handle_tRNS+0x136> */
/* @0x2acd0e add.w r2, r4, #0x250 */
/* @0x2acd10 rfeia r4! */
/* @0x2acd12 ldrh.w r3, [r4, #0x1de] */
/* @0x2acd14 andls r3, r0, #-2147483593 */
/* @0x2acd16 str r2, [sp] */
/* @0x2acd18 mov r0, r4 */
/* @0x2acd1a mov r1, r7 */
/* @0x2acd1c add r2, sp, #0x14 */
/* @0x2acd1e bl 0x2af14c <png_set_tRNS> */
/* @0x2acd20 bls 0x142b57c <b2_toiTime+0xcd20d8> */
/* @0x2acd22 ldr r2, [sp, #0x114] */
/* @0x2acd24 ldr.w r3, [r8] */
/* @0x2acd28 cmp r2, r3 */
/* @0x2acd2a beq 0x2acd30 <png_handle_tRNS+0x144> */
/* @0x2acd2c blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2acd30 add sp, #0x118 */
/* @0x2acd32 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2acd34 svclt #0x81f0 */
/* @0x2acd36 nop */
/* @0x2acd38 lsrs r2, r4, #0x15 */
/* @0x2acd3a movs r4, r2 */
/* @0x2acd3c lsls r2, r4, #0x19 */
/* @0x2acd3e movs r6, r1 */
/* @0x2acd40 lsls r5, r5, #0x19 */
/* @0x2acd42 movs r6, r1 */
/* @0x2acd44 lsls r7, r6, #0x19 */
/* @0x2acd46 movs r6, r1 */
/* @0x2acd48 lsls r2, r7, #0x19 */
/* @0x2acd4a movs r6, r1 */
/* @0x2acd4c lsls r4, r1, #0x19 */
/* @0x2acd4e movs r6, r1 */
/* @0x2acd50 lsls r6, r3, #0x18 */
/* @0x2acd52 movs r6, r1 */
/* @0x2acd54 lsls r2, r5, #0x17 */
/* @0x2acd56 movs r6, r1 */
/* @0x2acd58 lsls r7, r2, #0x18 */
/* @0x2acd5a movs r6, r1 */
/* @0x2acd5c lsls r0, r3, #0x18 */
/* @0x2acd5e movs r6, r1 */

/* ── FUNC 0x2acd60 · png_handle_bKGD · size=312 · insn=134 */
/* @0x2acd60 push {r0, r1, r4, r5, r6, lr} */
/* @0x2acd62 mov r5, r2 */
/* @0x2acd64 ldr.w r3, [r0, #0x12c] */
/* @0x2acd68 mov r4, r0 */
/* @0x2acd6a mov r6, r1 */
/* @0x2acd6c lsls r2, r3, #0x1f */
/* @0x2acd6e bmi 0x2acd7a <png_handle_bKGD+0x1a> */
/* @0x2acd70 ldr r1, [pc, #0x10c] */
/* @0x2acd72 add r1, pc */
/* @0x2acd74 bl 0x2a642c <png_error> */
/* @0x2acd78 b 0x2acda6 <png_handle_bKGD+0x46> */
/* @0x2acd7a lsls r1, r3, #0x1d */
/* @0x2acd7c bpl 0x2acd84 <png_handle_bKGD+0x24> */
/* @0x2acd7e ldr r1, [pc, #0x104] */
/* @0x2acd80 add r1, pc */
/* @0x2acd82 b 0x2acdc6 <png_handle_bKGD+0x66> */
/* @0x2acd84 ldrb.w r2, [r0, #0x1ea] */
/* @0x2acd88 cmp r2, #0x3 */
/* @0x2acd8a bne 0x2acd96 <png_handle_bKGD+0x36> */
/* @0x2acd8c lsls r2, r3, #0x1e */
/* @0x2acd8e bmi 0x2acd96 <png_handle_bKGD+0x36> */
/* @0x2acd90 ldr r1, [pc, #0xf4] */
/* @0x2acd92 add r1, pc */
/* @0x2acd94 b 0x2acdc6 <png_handle_bKGD+0x66> */
/* @0x2acd96 cbz r6, 0x2acda6 <png_handle_bKGD+0x46> */
/* @0x2acd98 ldr r3, [r6, #0x8] */
/* @0x2acd9a lsls r3, r3, #0x1a */
/* @0x2acd9c bpl 0x2acda6 <png_handle_bKGD+0x46> */
/* @0x2acd9e ldr r1, [pc, #0xec] */
/* @0x2acda0 mov r0, r4 */
/* @0x2acda2 add r1, pc */
/* @0x2acda4 b 0x2acdc6 <png_handle_bKGD+0x66> */
/* @0x2acda6 ldrb.w r3, [r4, #0x1ea] */
/* @0x2acda8 blhs 0x379558 <_ZTS13C_UTF16String+0x10604> */
/* @0x2acdaa cmp r3, #0x3 */
/* @0x2acdac beq 0x2acdba <png_handle_bKGD+0x5a> */
/* @0x2acdae tst.w r3, #0x2 */
/* @0x2acdb0 svclt #0xc0f02 */
/* @0x2acdb2 ite eq */
/* @0x2acdb4 moveq r3, #0x2 */
/* @0x2acdb6 movne r3, #0x6 */
/* @0x2acdb8 b 0x2acdbc <png_handle_bKGD+0x5c> */
/* @0x2acdba movs r3, #0x1 */
/* @0x2acdbc cmp r5, r3 */
/* @0x2acdbe mov r0, r4 */
/* @0x2acdc0 beq 0x2acdd4 <png_handle_bKGD+0x74> */
/* @0x2acdc2 ldr r1, [pc, #0xcc] */
/* @0x2acdc4 add r1, pc */
/* @0x2acdc6 bl 0x2a6474 <png_warning> */
/* @0x2acdc8 qsaxmi pc, r0, r5 */
/* @0x2acdca mov r0, r4 */
/* @0x2acdcc mov r1, r5 */
/* @0x2acdce bl 0x2abc94 <png_crc_finish> */
/* @0x2acdd0 subs pc, r3, r1, ror #30 */
/* @0x2acdd2 b 0x2ace7c <png_handle_bKGD+0x11c> */
/* @0x2acdd4 mov r1, sp */
/* @0x2acdd6 mov r2, r5 */
/* @0x2acdd8 bl 0x2abc0c <png_crc_read> */
/* @0x2acddc mov r0, r4 */
/* @0x2acdde movs r1, #0x0 */
/* @0x2acde0 bl 0x2abc94 <png_crc_finish> */
/* @0x2acde4 cmp r0, #0x0 */
/* @0x2acde6 bne 0x2ace7c <png_handle_bKGD+0x11c> */
/* @0x2acde8 ldrb.w r2, [r4, #0x1ea] */
/* @0x2acdec ldrb.w r3, [sp] */
/* @0x2acdf0 cmp r2, #0x3 */
/* @0x2acdf2 bne 0x2ace2a <png_handle_bKGD+0xca> */
/* @0x2acdf4 strb.w r3, [r4, #0x1fc] */
/* @0x2acdf8 cmp r6, #0x0 */
/* @0x2acdfa beq 0x2ace70 <png_handle_bKGD+0x110> */
/* @0x2acdfc ldrh r2, [r6, #0x14] */
/* @0x2acdfe cbz r2, 0x2ace70 <png_handle_bKGD+0x110> */
/* @0x2ace00 cmp r3, r2 */
/* @0x2ace02 blo 0x2ace10 <png_handle_bKGD+0xb0> */
/* @0x2ace04 ldr r1, [pc, #0x8c] */
/* @0x2ace06 mov r0, r4 */
/* @0x2ace08 add r1, pc */
/* @0x2ace0a bl 0x2a6474 <png_warning> */
/* @0x2ace0c eors pc, r5, r3, lsr r11 */
/* @0x2ace0e b 0x2ace7c <png_handle_bKGD+0x11c> */
/* @0x2ace10 ldr.w r1, [r4, #0x1d8] */
/* @0x2ace14 add.w r3, r3, r3, lsl #1 */
/* @0x2ace18 adds r2, r1, r3 */
/* @0x2ace1a ldrb r3, [r1, r3] */
/* @0x2ace1c strh.w r3, [r4, #0x1fe] */
/* @0x2ace20 ldrb r3, [r2, #0x1] */
/* @0x2ace22 strh.w r3, [r4, #0x200] */
/* @0x2ace24 ldmvc r3, {r9, r12, sp} */
/* @0x2ace26 ldrb r3, [r2, #0x2] */
/* @0x2ace28 b 0x2ace6c <png_handle_bKGD+0x10c> */
/* @0x2ace2a tst.w r2, #0x2 */
/* @0x2ace2c .word 0xf89d0f02 */
/* @0x2ace2e ldrb.w r2, [sp, #0x1] */
/* @0x2ace30 bl 0x334e3c */
/* @0x2ace32 add.w r3, r2, r3, lsl #8 */
/* @0x2ace34 .word 0xd1092303 */
/* @0x2ace36 bne 0x2ace4c <png_handle_bKGD+0xec> */
/* @0x2ace38 uxth r3, r3 */
/* @0x2ace3a strh.w r3, [r4, #0x204] */
/* @0x2ace3c .word 0xf8a43204 */
/* @0x2ace3e strh.w r3, [r4, #0x202] */
/* @0x2ace40 .word 0xf8a43202 */
/* @0x2ace42 strh.w r3, [r4, #0x200] */
/* @0x2ace44 .word 0xf8a43200 */
/* @0x2ace46 strh.w r3, [r4, #0x1fe] */
/* @0x2ace48 ldrsh r3, [r1], -lr */
/* @0x2ace4a b 0x2ace70 <png_handle_bKGD+0x110> */
/* @0x2ace4c ldrb.w r2, [sp, #0x2] */
/* @0x2ace50 strh.w r3, [r4, #0x1fe] */
/* @0x2ace54 ldrb.w r3, [sp, #0x3] */
/* @0x2ace58 add.w r3, r3, r2, lsl #8 */
/* @0x2ace5c ldrb.w r2, [sp, #0x4] */
/* @0x2ace60 strh.w r3, [r4, #0x200] */
/* @0x2ace64 ldrb.w r3, [sp, #0x5] */
/* @0x2ace68 add.w r3, r3, r2, lsl #8 */
/* @0x2ace6c strh.w r3, [r4, #0x202] */
/* @0x2ace70 mov r0, r4 */
/* @0x2ace72 mov r1, r6 */
/* @0x2ace74 add.w r2, r4, #0x1fc */
/* @0x2ace78 bl 0x2ae6b4 <png_set_bKGD> */
/* @0x2ace7c add sp, #0x8 */
/* @0x2ace7e pop {r4, r5, r6, pc} */
/* @0x2ace80 lsls r4, r7, #0x16 */
/* @0x2ace82 movs r6, r1 */
/* @0x2ace84 lsls r7, r0, #0x17 */
/* @0x2ace86 movs r6, r1 */
/* @0x2ace88 lsls r5, r1, #0x17 */
/* @0x2ace8a movs r6, r1 */
/* @0x2ace8c lsls r6, r2, #0x17 */
/* @0x2ace8e movs r6, r1 */
/* @0x2ace90 lsls r1, r1, #0x17 */
/* @0x2ace92 movs r6, r1 */
/* @0x2ace94 lsls r1, r4, #0x16 */
/* @0x2ace96 movs r6, r1 */

/* ── FUNC 0x2ace98 · png_handle_hIST · size=192 · insn=90 */
/* @0x2ace98 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2ace9c mov r4, r0 */
/* @0x2ace9e ldr.w r3, [r0, #0x12c] */
/* @0x2acea0 .word 0xf5ad312c */
/* @0x2acea2 sub.w sp, sp, #0x20c */
/* @0x2acea4 strmi r7, [pc], -r3, lsl #26 */
/* @0x2acea6 mov r7, r1 */
/* @0x2acea8 mov r5, r2 */
/* @0x2aceaa lsls r6, r3, #0x1f */
/* @0x2aceac bmi 0x2aceb8 <png_handle_hIST+0x20> */
/* @0x2aceae ldr r1, [pc, #0x94] */
/* @0x2aceb0 add r1, pc */
/* @0x2aceb2 bl 0x2a642c <png_error> */
/* @0x2aceb4 ldrh pc, [r6], -r11 */
/* @0x2aceb6 b 0x2acee6 <png_handle_hIST+0x4e> */
/* @0x2aceb8 lsls r1, r3, #0x1d */
/* @0x2aceba bpl 0x2acec2 <png_handle_hIST+0x2a> */
/* @0x2acebc ldr r1, [pc, #0x88] */
/* @0x2acebe add r1, pc */
/* @0x2acec0 b 0x2aceca <png_handle_hIST+0x32> */
/* @0x2acec2 lsls r2, r3, #0x1e */
/* @0x2acec4 bmi 0x2aced8 <png_handle_hIST+0x40> */
/* @0x2acec6 ldr r1, [pc, #0x84] */
/* @0x2acec8 add r1, pc */
/* @0x2aceca bl 0x2a6474 <png_warning> */
/* @0x2acecc .word 0x4620fad3 */
/* @0x2acece mov r0, r4 */
/* @0x2aced0 mov r1, r5 */
/* @0x2aced2 bl 0x2abc94 <png_crc_finish> */
/* @0x2aced4 ldrsbt pc, [r0], -pc */
/* @0x2aced6 b 0x2acf3a <png_handle_hIST+0xa2> */
/* @0x2aced8 cbz r7, 0x2acee6 <png_handle_hIST+0x4e> */
/* @0x2aceda ldr r3, [r7, #0x8] */
/* @0x2acedc lsls r3, r3, #0x19 */
/* @0x2acede bpl 0x2acee6 <png_handle_hIST+0x4e> */
/* @0x2acee0 ldr r1, [pc, #0x6c] */
/* @0x2acee2 add r1, pc */
/* @0x2acee4 b 0x2aceca <png_handle_hIST+0x32> */
/* @0x2acee6 cmp.w r5, #0x200 */
/* @0x2acee8 stmdale r4, {r8, r9, r10, r11, r12, sp, lr} */
/* @0x2aceea bhi 0x2acef6 <png_handle_hIST+0x5e> */
/* @0x2aceec ldrh.w r3, [r4, #0x1dc] */
/* @0x2acef0 cmp.w r5, r3, lsl #1 */
/* @0x2acef4 beq 0x2acefe <png_handle_hIST+0x66> */
/* @0x2acef6 ldr r1, [pc, #0x5c] */
/* @0x2acef8 mov r0, r4 */
/* @0x2acefa add r1, pc */
/* @0x2acefc b 0x2aceca <png_handle_hIST+0x32> */
/* @0x2acefe lsr.w r9, r5, #0x1 */
/* @0x2acf00 .word 0xf10d0955 */
/* @0x2acf02 add.w r8, sp, #0x8 */
/* @0x2acf04 stcge p8, c0, [r1, #-32] */
/* @0x2acf06 add r5, sp, #0x4 */
/* @0x2acf08 movs r6, #0x0 */
/* @0x2acf0a cmp r6, r9 */
/* @0x2acf0c mov r0, r4 */
/* @0x2acf0e beq 0x2acf28 <png_handle_hIST+0x90> */
/* @0x2acf10 movs r2, #0x2 */
/* @0x2acf12 mov r1, r5 */
/* @0x2acf14 bl 0x2abc0c <png_crc_read> */
/* @0x2acf18 ldrb r2, [r5] */
/* @0x2acf1a ldrb r3, [r5, #0x1] */
/* @0x2acf1c add.w r3, r3, r2, lsl #8 */
/* @0x2acf20 strh.w r3, [r8, r6, lsl #1] */
/* @0x2acf24 adds r6, #0x1 */
/* @0x2acf26 b 0x2acf0a <png_handle_hIST+0x72> */
/* @0x2acf28 movs r1, #0x0 */
/* @0x2acf2a bl 0x2abc94 <png_crc_finish> */
/* @0x2acf2c stmdblt r0!, {r0, r1, r4, r5, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2acf2e cbnz r0, 0x2acf3a <png_handle_hIST+0xa2> */
/* @0x2acf30 mov r0, r4 */
/* @0x2acf32 mov r1, r7 */
/* @0x2acf34 add r2, sp, #0x8 */
/* @0x2acf36 bl 0x2aea08 <png_set_hIST> */
/* @0x2acf38 .word 0xf50dfd67 */
/* @0x2acf3a add.w sp, sp, #0x20c */
/* @0x2acf3c pop {r0, r1, r8, r10, r11, r12, sp, lr} */
/* @0x2acf3e pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2acf40 svclt #0x83f0 */
/* @0x2acf42 nop */
/* @0x2acf44 lsls r2, r3, #0x14 */
/* @0x2acf46 movs r6, r1 */
/* @0x2acf48 lsls r5, r4, #0x14 */
/* @0x2acf4a movs r6, r1 */
/* @0x2acf4c lsls r3, r6, #0x14 */
/* @0x2acf4e movs r6, r1 */
/* @0x2acf50 lsls r2, r6, #0x14 */
/* @0x2acf52 movs r6, r1 */
/* @0x2acf54 lsls r7, r5, #0x14 */
/* @0x2acf56 movs r6, r1 */

/* ── FUNC 0x2acf58 · png_handle_pHYs · size=216 · insn=98 */
/* @0x2acf58 ldr r3, [pc, #0xc0] */
/* @0x2acf5a push {r4, r5, r6, r7, lr} */
/* @0x2acf5c add r3, pc */
/* @0x2acf5e ldr r3, [r3] */
/* @0x2acf60 mov r5, r2 */
/* @0x2acf62 sub sp, #0x1c */
/* @0x2acf64 ldr r2, [r3] */
/* @0x2acf66 mov r4, r0 */
/* @0x2acf68 mov r6, r1 */
/* @0x2acf6a mov r7, r3 */
/* @0x2acf6c str r2, [sp, #0x14] */
/* @0x2acf6e ldr.w r2, [r0, #0x12c] */
/* @0x2acf70 .word 0xf012212c */
/* @0x2acf72 tst.w r2, #0x1 */
/* @0x2acf74 .word 0xd1040f01 */
/* @0x2acf76 bne 0x2acf82 <png_handle_pHYs+0x2a> */
/* @0x2acf78 ldr r1, [pc, #0xa4] */
/* @0x2acf7a add r1, pc */
/* @0x2acf7c bl 0x2a642c <png_error> */
/* @0x2acf80 b 0x2acfa6 <png_handle_pHYs+0x4e> */
/* @0x2acf82 lsls r2, r2, #0x1d */
/* @0x2acf84 bpl 0x2acf8c <png_handle_pHYs+0x34> */
/* @0x2acf86 ldr r1, [pc, #0x9c] */
/* @0x2acf88 add r1, pc */
/* @0x2acf8a b 0x2acf98 <png_handle_pHYs+0x40> */
/* @0x2acf8c cbz r1, 0x2acfa6 <png_handle_pHYs+0x4e> */
/* @0x2acf8e ldr r2, [r1, #0x8] */
/* @0x2acf90 lsls r3, r2, #0x18 */
/* @0x2acf92 bpl 0x2acfa6 <png_handle_pHYs+0x4e> */
/* @0x2acf94 ldr r1, [pc, #0x90] */
/* @0x2acf96 add r1, pc */
/* @0x2acf98 bl 0x2a6474 <png_warning> */
/* @0x2acf9c mov r0, r4 */
/* @0x2acf9e mov r1, r5 */
/* @0x2acfa0 bl 0x2abc94 <png_crc_finish> */
/* @0x2acfa4 b 0x2ad00a <png_handle_pHYs+0xb2> */
/* @0x2acfa6 cmp r5, #0x9 */
/* @0x2acfa8 mov r0, r4 */
/* @0x2acfaa beq 0x2acfb2 <png_handle_pHYs+0x5a> */
/* @0x2acfac ldr r1, [pc, #0x7c] */
/* @0x2acfae add r1, pc */
/* @0x2acfb0 b 0x2acf98 <png_handle_pHYs+0x40> */
/* @0x2acfb2 add r1, sp, #0x8 */
/* @0x2acfb4 mov r2, r5 */
/* @0x2acfb6 bl 0x2abc0c <png_crc_read> */
/* @0x2acfb8 strtmi pc, [r0], -r9, lsr #28 */
/* @0x2acfba mov r0, r4 */
/* @0x2acfbc movs r1, #0x0 */
/* @0x2acfbe bl 0x2abc94 <png_crc_finish> */
/* @0x2acfc0 bllt 0x6ec96c <g_SWFvertbuff+0x198a4> */
/* @0x2acfc2 cbnz r0, 0x2ad00a <png_handle_pHYs+0xb2> */
/* @0x2acfc4 ldrb.w r2, [sp, #0x9] */
/* @0x2acfc8 mov r0, r4 */
/* @0x2acfca ldrb.w r3, [sp, #0x8] */
/* @0x2acfcc .word 0xf89d3008 */
/* @0x2acfce ldrb.w r1, [sp, #0xc] */
/* @0x2acfd0 ldreq r1, [r2], #-12 */
/* @0x2acfd2 lsls r2, r2, #0x10 */
/* @0x2acfd4 ldrb.w lr, [sp, #0xa] */
/* @0x2acfd8 add.w r2, r2, r3, lsl #24 */
/* @0x2acfdc ldrb.w r3, [sp, #0xb] */
/* @0x2acfe0 ldrb.w r5, [sp, #0xe] */
/* @0x2acfe4 add r2, r3 */
/* @0x2acfe6 ldrb.w r3, [sp, #0xd] */
/* @0x2acfe8 bl 0x339024 */
/* @0x2acfea add.w r2, r2, lr, lsl #8 */
/* @0x2acfec ldreq r2, [r11], #-526 */
/* @0x2acfee lsls r3, r3, #0x10 */
/* @0x2acff0 add.w r3, r3, r1, lsl #24 */
/* @0x2acff4 ldrb.w r1, [sp, #0xf] */
/* @0x2acff8 add r3, r1 */
/* @0x2acffa ldrb.w r1, [sp, #0x10] */
/* @0x2acffc bl 0x371044 <_ZTS13C_UTF16String+0x80f0> */
/* @0x2acffe add.w r3, r3, r5, lsl #8 */
/* @0x2ad000 .word 0x91002305 */
/* @0x2ad002 str r1, [sp] */
/* @0x2ad004 mov r1, r6 */
/* @0x2ad006 bl 0x2aec6a <png_set_pHYs> */
/* @0x2ad008 bls 0x42c8d0 <g_RomDisk+0x350b0> */
/* @0x2ad00a ldr r2, [sp, #0x14] */
/* @0x2ad00c ldr r3, [r7] */
/* @0x2ad00e cmp r2, r3 */
/* @0x2ad010 beq 0x2ad016 <png_handle_pHYs+0xbe> */
/* @0x2ad012 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2ad014 andlt lr, r7, r0, ror #21 */
/* @0x2ad016 add sp, #0x1c */
/* @0x2ad018 pop {r4, r5, r6, r7, pc} */
/* @0x2ad01a nop */
/* @0x2ad01c lsrs r0, r7, #0x7 */
/* @0x2ad01e movs r4, r2 */
/* @0x2ad020 lsls r3, r1, #0x13 */
/* @0x2ad022 movs r6, r1 */
/* @0x2ad024 lsls r6, r2, #0x13 */
/* @0x2ad026 movs r6, r1 */
/* @0x2ad028 lsls r0, r4, #0x13 */
/* @0x2ad02a movs r6, r1 */
/* @0x2ad02c lsls r5, r3, #0x13 */
/* @0x2ad02e movs r6, r1 */

/* ── FUNC 0x2ad030 · png_handle_oFFs · size=248 · insn=106 */
/* @0x2ad030 ldr r3, [pc, #0xe0] */
/* @0x2ad032 push {r4, r5, r6, r7, lr} */
/* @0x2ad034 add r3, pc */
/* @0x2ad036 ldr r3, [r3] */
/* @0x2ad038 mov r5, r2 */
/* @0x2ad03a sub sp, #0x1c */
/* @0x2ad03c ldr r2, [r3] */
/* @0x2ad03e mov r4, r0 */
/* @0x2ad040 mov r6, r1 */
/* @0x2ad042 mov r7, r3 */
/* @0x2ad044 str r2, [sp, #0x14] */
/* @0x2ad046 ldr.w r2, [r0, #0x12c] */
/* @0x2ad048 .word 0xf012212c */
/* @0x2ad04a tst.w r2, #0x1 */
/* @0x2ad04c .word 0xd1040f01 */
/* @0x2ad04e bne 0x2ad05a <png_handle_oFFs+0x2a> */
/* @0x2ad050 ldr r1, [pc, #0xc4] */
/* @0x2ad052 add r1, pc */
/* @0x2ad054 bl 0x2a642c <png_error> */
/* @0x2ad058 b 0x2ad07e <png_handle_oFFs+0x4e> */
/* @0x2ad05a lsls r2, r2, #0x1d */
/* @0x2ad05c bpl 0x2ad064 <png_handle_oFFs+0x34> */
/* @0x2ad05e ldr r1, [pc, #0xbc] */
/* @0x2ad060 add r1, pc */
/* @0x2ad062 b 0x2ad070 <png_handle_oFFs+0x40> */
/* @0x2ad064 cbz r1, 0x2ad07e <png_handle_oFFs+0x4e> */
/* @0x2ad066 ldr r3, [r1, #0x8] */
/* @0x2ad068 lsls r3, r3, #0x17 */
/* @0x2ad06a bpl 0x2ad07e <png_handle_oFFs+0x4e> */
/* @0x2ad06c ldr r1, [pc, #0xb0] */
/* @0x2ad06e add r1, pc */
/* @0x2ad070 bl 0x2a6474 <png_warning> */
/* @0x2ad074 mov r0, r4 */
/* @0x2ad076 mov r1, r5 */
/* @0x2ad078 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad07c b 0x2ad102 <png_handle_oFFs+0xd2> */
/* @0x2ad07e cmp r5, #0x9 */
/* @0x2ad080 mov r0, r4 */
/* @0x2ad082 beq 0x2ad08a <png_handle_oFFs+0x5a> */
/* @0x2ad084 ldr r1, [pc, #0x9c] */
/* @0x2ad086 add r1, pc */
/* @0x2ad088 b 0x2ad070 <png_handle_oFFs+0x40> */
/* @0x2ad08a add r1, sp, #0x8 */
/* @0x2ad08c mov r2, r5 */
/* @0x2ad08e bl 0x2abc0c <png_crc_read> */
/* @0x2ad090 .word 0x4620fdbd */
/* @0x2ad092 mov r0, r4 */
/* @0x2ad094 movs r1, #0x0 */
/* @0x2ad096 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad098 bllt 0xfe6ec894 <b2_toiTime+0xfffffffffdf933f0> */
/* @0x2ad09a cbnz r0, 0x2ad102 <png_handle_oFFs+0xd2> */
/* @0x2ad09c ldrb.w r2, [sp, #0x8] */
/* @0x2ad0a0 ldrb.w r0, [sp, #0x9] */
/* @0x2ad0a4 tst.w r2, #0x80 */
/* @0x2ad0a8 ldrb.w r1, [sp, #0xb] */
/* @0x2ad0ac lsl.w r2, r2, #0x18 */
/* @0x2ad0b0 ldrb.w r3, [sp, #0xa] */
/* @0x2ad0b4 add.w r2, r2, r0, lsl #16 */
/* @0x2ad0b8 add r2, r1 */
/* @0x2ad0ba add.w r2, r2, r3, lsl #8 */
/* @0x2ad0bc andle r2, r3, r3, lsl #4 */
/* @0x2ad0be beq 0x2ad0c8 <png_handle_oFFs+0x98> */
/* @0x2ad0c0 rsbs r2, r2, #0 */
/* @0x2ad0c2 bic r2, r2, #0x80000000 */
/* @0x2ad0c4 subsmi r4, r2, #0, #4 */
/* @0x2ad0c6 rsbs r2, r2, #0 */
/* @0x2ad0c8 ldrb.w r3, [sp, #0xc] */
/* @0x2ad0cc ldrb.w r5, [sp, #0xd] */
/* @0x2ad0d0 tst.w r3, #0x80 */
/* @0x2ad0d4 ldrb.w r0, [sp, #0xf] */
/* @0x2ad0d8 lsl.w r3, r3, #0x18 */
/* @0x2ad0dc ldrb.w r1, [sp, #0xe] */
/* @0x2ad0e0 add.w r3, r3, r5, lsl #16 */
/* @0x2ad0e4 add r3, r0 */
/* @0x2ad0e6 add.w r3, r3, r1, lsl #8 */
/* @0x2ad0e8 andle r2, r3, r1, lsl #6 */
/* @0x2ad0ea beq 0x2ad0f4 <png_handle_oFFs+0xc4> */
/* @0x2ad0ec rsbs r3, r3, #0 */
/* @0x2ad0ee bic r3, r3, #0x80000000 */
/* @0x2ad0f0 subsmi r4, r11, #0, #6 */
/* @0x2ad0f2 rsbs r3, r3, #0 */
/* @0x2ad0f4 ldrb.w r1, [sp, #0x10] */
/* @0x2ad0f8 mov r0, r4 */
/* @0x2ad0fa str r1, [sp] */
/* @0x2ad0fc mov r1, r6 */
/* @0x2ad0fe bl 0x2aeb0a <png_set_oFFs> */
/* @0x2ad100 bls 0x42c518 <g_RomDisk+0x34cf8> */
/* @0x2ad102 ldr r2, [sp, #0x14] */
/* @0x2ad104 ldr r3, [r7] */
/* @0x2ad106 cmp r2, r3 */
/* @0x2ad108 beq 0x2ad10e <png_handle_oFFs+0xde> */
/* @0x2ad10a blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2ad10c andlt lr, r7, r4, ror #20 */
/* @0x2ad10e add sp, #0x1c */
/* @0x2ad110 pop {r4, r5, r6, r7, pc} */
/* @0x2ad112 nop */
/* @0x2ad114 lsrs r0, r4, #0x4 */
/* @0x2ad116 movs r4, r2 */
/* @0x2ad118 lsls r5, r2, #0x11 */
/* @0x2ad11a movs r6, r1 */
/* @0x2ad11c lsls r0, r4, #0x11 */
/* @0x2ad11e movs r6, r1 */
/* @0x2ad120 lsls r2, r5, #0x11 */
/* @0x2ad122 movs r6, r1 */
/* @0x2ad124 lsls r7, r4, #0x11 */
/* @0x2ad126 movs r6, r1 */

/* ── FUNC 0x2ad128 · png_handle_pCAL · size=552 · insn=243 */
/* @0x2ad128 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ad12c mov r8, r1 */
/* @0x2ad12e ldr.w r3, [r0, #0x12c] */
/* @0x2ad130 addlt r3, r11, r12, lsr #2 */
/* @0x2ad132 sub sp, #0x2c */
/* @0x2ad134 mov r4, r0 */
/* @0x2ad136 mov r6, r2 */
/* @0x2ad138 lsls r1, r3, #0x1f */
/* @0x2ad13a bmi 0x2ad146 <png_handle_pCAL+0x1e> */
/* @0x2ad13c ldr r1, [pc, #0x1ec] */
/* @0x2ad13e add r1, pc */
/* @0x2ad140 bl 0x2a642c <png_error> */
/* @0x2ad144 b 0x2ad174 <png_handle_pCAL+0x4c> */
/* @0x2ad146 lsls r2, r3, #0x1d */
/* @0x2ad148 bpl 0x2ad150 <png_handle_pCAL+0x28> */
/* @0x2ad14a ldr r1, [pc, #0x1e4] */
/* @0x2ad14c add r1, pc */
/* @0x2ad14e b 0x2ad162 <png_handle_pCAL+0x3a> */
/* @0x2ad150 cmp.w r8, #0x0 */
/* @0x2ad154 beq 0x2ad174 <png_handle_pCAL+0x4c> */
/* @0x2ad156 ldr.w r3, [r8, #0x8] */
/* @0x2ad158 ldrbeq r3, [r11, #-0x8] */
/* @0x2ad15a lsls r3, r3, #0x15 */
/* @0x2ad15c bpl 0x2ad174 <png_handle_pCAL+0x4c> */
/* @0x2ad15e ldr r1, [pc, #0x1d4] */
/* @0x2ad160 add r1, pc */
/* @0x2ad162 bl 0x2a6474 <png_warning> */
/* @0x2ad164 strtmi pc, [r0], -r7, lsl #19 */
/* @0x2ad166 mov r0, r4 */
/* @0x2ad168 mov r1, r6 */
/* @0x2ad16a add sp, #0x2c */
/* @0x2ad16c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ad170 b.w 0x2abc94 <png_crc_finish> */
/* @0x2ad174 mov r0, r4 */
/* @0x2ad176 ldr.w r1, [r4, #0x330] */
/* @0x2ad178 .word 0xf7f91330 */
/* @0x2ad17a bl 0x2a6cfc <png_free> */
/* @0x2ad17c ldclne p13, c15, [r1], #-764 */
/* @0x2ad17e adds r1, r6, #0x1 */
/* @0x2ad180 mov r0, r4 */
/* @0x2ad182 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad184 strmi pc, [r1], -r8, asr #27 */
/* @0x2ad186 mov r1, r0 */
/* @0x2ad188 str.w r0, [r4, #0x330] */
/* @0x2ad18c mov r0, r4 */
/* @0x2ad18e cbnz r1, 0x2ad196 <png_handle_pCAL+0x6e> */
/* @0x2ad190 ldr r1, [pc, #0x1a4] */
/* @0x2ad192 add r1, pc */
/* @0x2ad194 b 0x2ad2c2 <png_handle_pCAL+0x19a> */
/* @0x2ad196 mov r2, r6 */
/* @0x2ad198 bl 0x2abc0c <png_crc_read> */
/* @0x2ad19c mov r0, r4 */
/* @0x2ad19e movs r1, #0x0 */
/* @0x2ad1a0 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad1a4 cmp r0, #0x0 */
/* @0x2ad1a6 bne 0x2ad268 <png_handle_pCAL+0x140> */
/* @0x2ad1a8 ldr.w r3, [r4, #0x330] */
/* @0x2ad1ac strb r0, [r3, r6] */
/* @0x2ad1ae ldr.w r3, [r4, #0x330] */
/* @0x2ad1b0 sasxmi r3, r10, r0 */
/* @0x2ad1b2 mov r2, r3 */
/* @0x2ad1b4 mov r5, r2 */
/* @0x2ad1b6 adds r2, #0x1 */
/* @0x2ad1b8 ldrb r1, [r5] */
/* @0x2ad1ba cmp r1, #0x0 */
/* @0x2ad1bc bne 0x2ad1b4 <png_handle_pCAL+0x8c> */
/* @0x2ad1be cmp r6, #0xb */
/* @0x2ad1c0 add.w r10, r3, r6 */
/* @0x2ad1c4 bls 0x2ad1ce <png_handle_pCAL+0xa6> */
/* @0x2ad1c6 rsb r3, r5, r10 */
/* @0x2ad1c8 blhs 0x5addf8 <g_SWFlineaavertbuff+0x5ad30> */
/* @0x2ad1ca cmp r3, #0xc */
/* @0x2ad1cc bgt 0x2ad1d6 <png_handle_pCAL+0xae> */
/* @0x2ad1ce ldr r1, [pc, #0x16c] */
/* @0x2ad1d0 mov r0, r4 */
/* @0x2ad1d2 add r1, pc */
/* @0x2ad1d4 b 0x2ad264 <png_handle_pCAL+0x13c> */
/* @0x2ad1d6 ldrb r1, [r5, #0x1] */
/* @0x2ad1d8 ldrb.w r9, [r5, #0x2] */
/* @0x2ad1dc tst.w r1, #0x80 */
/* @0x2ad1e0 ldrb r2, [r5, #0x4] */
/* @0x2ad1e2 lsl.w r1, r1, #0x18 */
/* @0x2ad1e4 stmvc r11!, {r0, r8, sp, lr} ^ */
/* @0x2ad1e6 ldrb r3, [r5, #0x3] */
/* @0x2ad1e8 add.w r9, r1, r9, lsl #16 */
/* @0x2ad1ec add r9, r2 */
/* @0x2ad1ee add.w r9, r9, r3, lsl #8 */
/* @0x2ad1f0 andle r2, r5, r3, lsl #18 */
/* @0x2ad1f2 beq 0x2ad200 <png_handle_pCAL+0xd8> */
/* @0x2ad1f4 rsb.w r9, r9, #0x0 */
/* @0x2ad1f8 bic r9, r9, #0x80000000 */
/* @0x2ad1fc rsb.w r9, r9, #0x0 */
/* @0x2ad200 ldrb r1, [r5, #0x5] */
/* @0x2ad202 ldrb.w r11, [r5, #0x6] */
/* @0x2ad204 .word 0xf011b006 */
/* @0x2ad206 tst.w r1, #0x80 */
/* @0x2ad208 bvc 0xd31010 <b2_toiTime+0x5d7b6c> */
/* @0x2ad20a ldrb r2, [r5, #0x8] */
/* @0x2ad20c lsl.w r1, r1, #0x18 */
/* @0x2ad210 ldrb r3, [r5, #0x7] */
/* @0x2ad212 add.w r11, r1, r11, lsl #16 */
/* @0x2ad214 ldrmi r4, [r3], #2827 */
/* @0x2ad216 add r11, r2 */
/* @0x2ad218 beq 0x2ad22e <png_handle_pCAL+0x106> */
/* @0x2ad21a add.w r11, r11, r3, lsl #8 */
/* @0x2ad21c .word 0xf1cb2b03 */
/* @0x2ad21e rsb.w r11, r11, #0x0 */
/* @0x2ad220 .word 0xf02b0b00 */
/* @0x2ad222 bic r11, r11, #0x80000000 */
/* @0x2ad224 .word 0xf1cb4b00 */
/* @0x2ad226 rsb.w r2, r11, #0x0 */
/* @0x2ad228 andls r0, r9, #0, #4 */
/* @0x2ad22a str r2, [sp, #0x24] */
/* @0x2ad22c b 0x2ad234 <png_handle_pCAL+0x10c> */
/* @0x2ad22e add.w r3, r11, r3, lsl #8 */
/* @0x2ad230 movwls r2, #0x9303 */
/* @0x2ad232 str r3, [sp, #0x24] */
/* @0x2ad234 ldrb.w r11, [r5, #0x9] */
/* @0x2ad238 ldrb r6, [r5, #0xa] */
/* @0x2ad23a cmp.w r11, #0x0 */
/* @0x2ad23c .word 0xd1010f00 */
/* @0x2ad23e bne 0x2ad244 <png_handle_pCAL+0x11c> */
/* @0x2ad240 cmp r6, #0x2 */
/* @0x2ad242 b 0x2ad25c <png_handle_pCAL+0x134> */
/* @0x2ad244 cmp.w r11, #0x1 */
/* @0x2ad248 beq 0x2ad250 <png_handle_pCAL+0x128> */
/* @0x2ad24a cmp.w r11, #0x2 */
/* @0x2ad24c .word 0xd1010f02 */
/* @0x2ad24e bne 0x2ad254 <png_handle_pCAL+0x12c> */
/* @0x2ad250 cmp r6, #0x3 */
/* @0x2ad252 b 0x2ad25c <png_handle_pCAL+0x134> */
/* @0x2ad254 cmp.w r11, #0x3 */
/* @0x2ad258 bne 0x2ad27e <png_handle_pCAL+0x156> */
/* @0x2ad25a cmp r6, #0x4 */
/* @0x2ad25c beq 0x2ad28a <png_handle_pCAL+0x162> */
/* @0x2ad25e ldr r1, [pc, #0xe0] */
/* @0x2ad260 mov r0, r4 */
/* @0x2ad262 add r1, pc */
/* @0x2ad264 bl 0x2a6474 <png_warning> */
/* @0x2ad268 mov r0, r4 */
/* @0x2ad26a ldr.w r1, [r4, #0x330] */
/* @0x2ad26c .word 0xf7f91330 */
/* @0x2ad26e bl 0x2a6cfc <png_free> */
/* @0x2ad270 movwhs pc, #0xd45 */
/* @0x2ad272 movs r3, #0x0 */
/* @0x2ad274 str.w r3, [r4, #0x330] */
/* @0x2ad278 add sp, #0x2c */
/* @0x2ad27a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ad27c stmdble r4, {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ad27e bls 0x2ad28a <png_handle_pCAL+0x162> */
/* @0x2ad280 ldr r1, [pc, #0xc0] */
/* @0x2ad282 mov r0, r4 */
/* @0x2ad284 add r1, pc */
/* @0x2ad286 bl 0x2a6474 <png_warning> */
/* @0x2ad288 .word 0xf105f8f5 */
/* @0x2ad28a add.w r3, r5, #0xb */
/* @0x2ad28c ldrmi r0, [r9], -r11, lsl #6 */
/* @0x2ad28e mov r1, r3 */
/* @0x2ad290 mov r5, r1 */
/* @0x2ad292 adds r1, #0x1 */
/* @0x2ad294 ldrb r2, [r5] */
/* @0x2ad296 cmp r2, #0x0 */
/* @0x2ad298 bne 0x2ad290 <png_handle_pCAL+0x168> */
/* @0x2ad29a mov r0, r4 */
/* @0x2ad29c lsls r1, r6, #0x2 */
/* @0x2ad29e str r2, [sp, #0x1c] */
/* @0x2ad2a0 str r3, [sp, #0x20] */
/* @0x2ad2a2 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad2a4 bls 0x4ac78c <SrcVerts+0x97d0> */
/* @0x2ad2a6 ldr r2, [sp, #0x1c] */
/* @0x2ad2a8 ldr r3, [sp, #0x20] */
/* @0x2ad2aa mov r7, r0 */
/* @0x2ad2ac cbnz r0, 0x2ad2dc <png_handle_pCAL+0x1b4> */
/* @0x2ad2ae mov r0, r4 */
/* @0x2ad2b0 ldr.w r1, [r4, #0x330] */
/* @0x2ad2b4 bl 0x2a6cfc <png_free> */
/* @0x2ad2b8 ldr r1, [pc, #0x8c] */
/* @0x2ad2ba mov r0, r4 */
/* @0x2ad2bc str.w r7, [r4, #0x330] */
/* @0x2ad2c0 add r1, pc */
/* @0x2ad2c2 add sp, #0x2c */
/* @0x2ad2c4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ad2c8 b.w 0x2a6474 <png_warning> */
/* @0x2ad2cc cmp r1, r10 */
/* @0x2ad2ce mov r5, r1 */
/* @0x2ad2d0 bhi 0x2ad304 <png_handle_pCAL+0x1dc> */
/* @0x2ad2d2 ldrb r0, [r5] */
/* @0x2ad2d4 adds r1, #0x1 */
/* @0x2ad2d6 cmp r0, #0x0 */
/* @0x2ad2d8 bne 0x2ad2cc <png_handle_pCAL+0x1a4> */
/* @0x2ad2da adds r2, #0x1 */
/* @0x2ad2dc cmp r2, r6 */
/* @0x2ad2de bge 0x2ad2e8 <png_handle_pCAL+0x1c0> */
/* @0x2ad2e0 adds r1, r5, #0x1 */
/* @0x2ad2e2 str.w r1, [r7, r2, lsl #2] */
/* @0x2ad2e4 ldrb r1, [r1, r2, lsr #32]! */
/* @0x2ad2e6 b 0x2ad2cc <png_handle_pCAL+0x1a4> */
/* @0x2ad2e8 ldr r2, [sp, #0x24] */
/* @0x2ad2ea mov r0, r4 */
/* @0x2ad2ec str r3, [sp, #0xc] */
/* @0x2ad2ee mov r1, r8 */
/* @0x2ad2f0 str r6, [sp, #0x8] */
/* @0x2ad2f2 mov r3, r9 */
/* @0x2ad2f4 stm.w sp, {r2, r11} */
/* @0x2ad2f8 str r7, [sp, #0x10] */
/* @0x2ad2fa ldr.w r2, [r4, #0x330] */
/* @0x2ad2fc .word 0xf0012330 */
/* @0x2ad2fe bl 0x2aeb24 <png_set_pCAL> */
/* @0x2ad300 and pc, r4, r1, lsl r12 */
/* @0x2ad302 b 0x2ad30e <png_handle_pCAL+0x1e6> */
/* @0x2ad304 ldr r1, [pc, #0x44] */
/* @0x2ad306 mov r0, r4 */
/* @0x2ad308 add r1, pc */
/* @0x2ad30a bl 0x2a6474 <png_warning> */
/* @0x2ad30c .word 0x4620f8b3 */
/* @0x2ad30e mov r0, r4 */
/* @0x2ad310 ldr.w r1, [r4, #0x330] */
/* @0x2ad314 bl 0x2a6cfc <png_free> */
/* @0x2ad318 movs r3, #0x0 */
/* @0x2ad31a mov r0, r4 */
/* @0x2ad31c str.w r3, [r4, #0x330] */
/* @0x2ad320 mov r1, r7 */
/* @0x2ad322 add sp, #0x2c */
/* @0x2ad324 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ad328 b.w 0x2a6cfc <png_free> */
/* @0x2ad32c lsls r3, r1, #0xf */
/* @0x2ad32e movs r6, r1 */
/* @0x2ad330 lsls r6, r2, #0xf */
/* @0x2ad332 movs r6, r1 */
/* @0x2ad334 lsls r2, r3, #0xf */
/* @0x2ad336 movs r6, r1 */
/* @0x2ad338 lsls r5, r7, #0xe */
/* @0x2ad33a movs r6, r1 */
/* @0x2ad33c lsls r0, r3, #0xe */
/* @0x2ad33e movs r6, r1 */
/* @0x2ad340 lsls r2, r3, #0xc */
/* @0x2ad342 movs r6, r1 */
/* @0x2ad344 lsls r2, r4, #0xc */
/* @0x2ad346 movs r6, r1 */
/* @0x2ad348 lsls r0, r2, #0xc */
/* @0x2ad34a movs r6, r1 */
/* @0x2ad34c lsls r2, r4, #0x9 */
/* @0x2ad34e movs r6, r1 */

/* ── FUNC 0x2ad350 · png_handle_sCAL · size=384 · insn=168 */
/* @0x2ad350 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2ad354 vpush {d8} */
/* @0x2ad358 mov r6, r1 */
/* @0x2ad35a ldr.w r3, [r0, #0x12c] */
/* @0x2ad35c addlt r3, r7, r12, lsr #2 */
/* @0x2ad35e sub sp, #0x1c */
/* @0x2ad360 mov r4, r0 */
/* @0x2ad362 mov r5, r2 */
/* @0x2ad364 lsls r1, r3, #0x1f */
/* @0x2ad366 bmi 0x2ad372 <png_handle_sCAL+0x22> */
/* @0x2ad368 ldr r1, [pc, #0x140] */
/* @0x2ad36a add r1, pc */
/* @0x2ad36c bl 0x2a642c <png_error> */
/* @0x2ad370 b 0x2ad3a2 <png_handle_sCAL+0x52> */
/* @0x2ad372 lsls r2, r3, #0x1d */
/* @0x2ad374 bpl 0x2ad37c <png_handle_sCAL+0x2c> */
/* @0x2ad376 ldr r1, [pc, #0x138] */
/* @0x2ad378 add r1, pc */
/* @0x2ad37a b 0x2ad388 <png_handle_sCAL+0x38> */
/* @0x2ad37c cbz r6, 0x2ad396 <png_handle_sCAL+0x46> */
/* @0x2ad37e ldr r3, [r6, #0x8] */
/* @0x2ad380 lsls r3, r3, #0x11 */
/* @0x2ad382 bpl 0x2ad396 <png_handle_sCAL+0x46> */
/* @0x2ad384 ldr r1, [pc, #0x12c] */
/* @0x2ad386 add r1, pc */
/* @0x2ad388 bl 0x2a6474 <png_warning> */
/* @0x2ad38c mov r0, r4 */
/* @0x2ad38e mov r1, r5 */
/* @0x2ad390 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad394 b 0x2ad4a2 <png_handle_sCAL+0x152> */
/* @0x2ad396 cmp r5, #0x3 */
/* @0x2ad398 bhi 0x2ad3a2 <png_handle_sCAL+0x52> */
/* @0x2ad39a ldr r1, [pc, #0x11c] */
/* @0x2ad39c mov r0, r4 */
/* @0x2ad39e add r1, pc */
/* @0x2ad3a0 b 0x2ad388 <png_handle_sCAL+0x38> */
/* @0x2ad3a2 adds r1, r5, #0x1 */
/* @0x2ad3a4 mov r0, r4 */
/* @0x2ad3a6 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad3a8 .word 0x4601fcb6 */
/* @0x2ad3aa mov r1, r0 */
/* @0x2ad3ac str.w r0, [r4, #0x330] */
/* @0x2ad3b0 mov r0, r4 */
/* @0x2ad3b2 cbnz r1, 0x2ad3ba <png_handle_sCAL+0x6a> */
/* @0x2ad3b4 ldr r1, [pc, #0x104] */
/* @0x2ad3b6 add r1, pc */
/* @0x2ad3b8 b 0x2ad388 <png_handle_sCAL+0x38> */
/* @0x2ad3ba mov r2, r5 */
/* @0x2ad3bc bl 0x2abc0c <png_crc_read> */
/* @0x2ad3c0 mov r0, r4 */
/* @0x2ad3c2 movs r1, #0x0 */
/* @0x2ad3c4 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad3c8 mov r7, r0 */
/* @0x2ad3ca cmp r0, #0x0 */
/* @0x2ad3cc bne 0x2ad470 <png_handle_sCAL+0x120> */
/* @0x2ad3ce ldr.w r3, [r4, #0x330] */
/* @0x2ad3d0 .word 0xf10d3330 */
/* @0x2ad3d2 add.w r9, sp, #0x14 */
/* @0x2ad3d4 .word 0x46490914 */
/* @0x2ad3d6 mov r1, r9 */
/* @0x2ad3d8 strb r0, [r3, r5] */
/* @0x2ad3da ldr.w r0, [r4, #0x330] */
/* @0x2ad3dc andlo r0, r1, r0, lsr r3 */
/* @0x2ad3de adds r0, #0x1 */
/* @0x2ad3e0 blx 0xb6658 <strtod@plt> */
/* @0x2ad3e4 ldr r3, [sp, #0x14] */
/* @0x2ad3e6 ldrb r3, [r3] */
/* @0x2ad3e8 vmov d8, r0, r1 */
/* @0x2ad3ec cbz r3, 0x2ad3f6 <png_handle_sCAL+0xa6> */
/* @0x2ad3ee ldr r1, [pc, #0xd0] */
/* @0x2ad3f0 mov r0, r4 */
/* @0x2ad3f2 add r1, pc */
/* @0x2ad3f4 b 0x2ad434 <png_handle_sCAL+0xe4> */
/* @0x2ad3f6 ldr.w r2, [r4, #0x330] */
/* @0x2ad3f8 mrrcne p3, #0x3, r2, r3, c0 */
/* @0x2ad3fa adds r3, r2, #0x1 */
/* @0x2ad3fc mov r1, r3 */
/* @0x2ad3fe adds r3, #0x1 */
/* @0x2ad400 ldrb r7, [r1] */
/* @0x2ad402 cmp r7, #0x0 */
/* @0x2ad404 bne 0x2ad3fc <png_handle_sCAL+0xac> */
/* @0x2ad406 add r2, r5 */
/* @0x2ad408 mov r8, r3 */
/* @0x2ad40a cmp r3, r2 */
/* @0x2ad40c bls 0x2ad416 <png_handle_sCAL+0xc6> */
/* @0x2ad40e ldr r1, [pc, #0xb4] */
/* @0x2ad410 mov r0, r4 */
/* @0x2ad412 add r1, pc */
/* @0x2ad414 b 0x2ad434 <png_handle_sCAL+0xe4> */
/* @0x2ad416 mov r0, r3 */
/* @0x2ad418 mov r1, r9 */
/* @0x2ad41a blx 0xb6658 <strtod@plt> */
/* @0x2ad41c blls 0x42789c <g_RomDisk+0x3007c> */
/* @0x2ad41e ldr r3, [sp, #0x14] */
/* @0x2ad420 ldrb.w r9, [r3] */
/* @0x2ad424 vmov d7, r0, r1 */
/* @0x2ad428 cmp.w r9, #0x0 */
/* @0x2ad42c beq 0x2ad448 <png_handle_sCAL+0xf8> */
/* @0x2ad42e ldr r1, [pc, #0x98] */
/* @0x2ad430 mov r0, r4 */
/* @0x2ad432 add r1, pc */
/* @0x2ad434 bl 0x2a6474 <png_warning> */
/* @0x2ad438 mov r0, r4 */
/* @0x2ad43a ldr.w r1, [r4, #0x330] */
/* @0x2ad43c .word 0xf7f91330 */
/* @0x2ad43e bl 0x2a6cfc <png_free> */
/* @0x2ad440 .word 0xf8c4fc5d */
/* @0x2ad442 str.w r7, [r4, #0x330] */
/* @0x2ad444 eor r7, r12, r0, lsr r3 */
/* @0x2ad446 b 0x2ad4a2 <png_handle_sCAL+0x152> */
/* @0x2ad448 ldr.w r3, [r4, #0x330] */
/* @0x2ad44c add r5, r3 */
/* @0x2ad44e cmp r8, r5 */
/* @0x2ad450 bhi 0x2ad466 <png_handle_sCAL+0x116> */
/* @0x2ad452 vcmpe.f64 d8, #0 */
/* @0x2ad454 vsqrt.f64 d24, d0 */
/* @0x2ad456 vmrs APSR_nzcv, fpscr */
/* @0x2ad458 stmdble r4, {r4, r9, r11, r12, sp, lr, pc} */
/* @0x2ad45a bls 0x2ad466 <png_handle_sCAL+0x116> */
/* @0x2ad45c vcmpe.f64 d7, #0 */
/* @0x2ad460 vmrs APSR_nzcv, fpscr */
/* @0x2ad464 bhi 0x2ad482 <png_handle_sCAL+0x132> */
/* @0x2ad466 ldr r1, [pc, #0x64] */
/* @0x2ad468 mov r0, r4 */
/* @0x2ad46a add r1, pc */
/* @0x2ad46c bl 0x2a6474 <png_warning> */
/* @0x2ad470 mov r0, r4 */
/* @0x2ad472 ldr.w r1, [r4, #0x330] */
/* @0x2ad474 .word 0xf7f91330 */
/* @0x2ad476 bl 0x2a6cfc <png_free> */
/* @0x2ad478 movwhs pc, #0xc41 */
/* @0x2ad47a movs r3, #0x0 */
/* @0x2ad47c str.w r3, [r4, #0x330] */
/* @0x2ad480 b 0x2ad4a2 <png_handle_sCAL+0x152> */
/* @0x2ad482 ldrb r2, [r3] */
/* @0x2ad484 vstr d8, [sp] */
/* @0x2ad488 strd r0, r1, [sp, #8] */
/* @0x2ad48c mov r0, r4 */
/* @0x2ad48e mov r1, r6 */
/* @0x2ad490 bl 0x2aec48 <png_set_sCAL> */
/* @0x2ad494 mov r0, r4 */
/* @0x2ad496 ldr.w r1, [r4, #0x330] */
/* @0x2ad498 .word 0xf7f91330 */
/* @0x2ad49a bl 0x2a6cfc <png_free> */
/* @0x2ad49c .word 0xf8c4fc2f */
/* @0x2ad49e str.w r9, [r4, #0x330] */
/* @0x2ad4a0 andlt r9, r7, r0, lsr r3 */
/* @0x2ad4a2 add sp, #0x1c */
/* @0x2ad4a4 vpop {d8} */
/* @0x2ad4a8 pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2ad4ac lsls r0, r0, #0xa */
/* @0x2ad4ae movs r6, r1 */
/* @0x2ad4b0 lsls r3, r1, #0xa */
/* @0x2ad4b2 movs r6, r1 */
/* @0x2ad4b4 lsls r5, r2, #0xa */
/* @0x2ad4b6 movs r6, r1 */
/* @0x2ad4b8 lsls r2, r2, #0xa */
/* @0x2ad4ba movs r6, r1 */
/* @0x2ad4bc lsls r7, r1, #0xa */
/* @0x2ad4be movs r6, r1 */
/* @0x2ad4c0 lsls r5, r7, #0x9 */
/* @0x2ad4c2 movs r6, r1 */
/* @0x2ad4c4 lsls r2, r0, #0xa */
/* @0x2ad4c6 movs r6, r1 */
/* @0x2ad4c8 lsls r7, r6, #0x9 */
/* @0x2ad4ca movs r6, r1 */
/* @0x2ad4cc lsls r5, r4, #0x9 */
/* @0x2ad4ce movs r6, r1 */

/* ── FUNC 0x2ad4d0 · png_handle_tIME · size=180 · insn=82 */
/* @0x2ad4d0 push {r0, r1, r2, r3, r4, r5, r6, lr} */
/* @0x2ad4d2 mov r4, r0 */
/* @0x2ad4d4 ldr.w r3, [r0, #0x12c] */
/* @0x2ad4d8 mov r6, r1 */
/* @0x2ad4da mov r5, r2 */
/* @0x2ad4dc lsls r3, r3, #0x1f */
/* @0x2ad4de bmi 0x2ad4ea <png_handle_tIME+0x1a> */
/* @0x2ad4e0 ldr r1, [pc, #0x94] */
/* @0x2ad4e2 add r1, pc */
/* @0x2ad4e4 bl 0x2a642c <png_error> */
/* @0x2ad4e8 b 0x2ad4f8 <png_handle_tIME+0x28> */
/* @0x2ad4ea cbz r1, 0x2ad4f8 <png_handle_tIME+0x28> */
/* @0x2ad4ec ldr r3, [r1, #0x8] */
/* @0x2ad4ee lsls r1, r3, #0x16 */
/* @0x2ad4f0 bpl 0x2ad4f8 <png_handle_tIME+0x28> */
/* @0x2ad4f2 ldr r1, [pc, #0x88] */
/* @0x2ad4f4 add r1, pc */
/* @0x2ad4f6 b 0x2ad512 <png_handle_tIME+0x42> */
/* @0x2ad4f8 ldr.w r3, [r4, #0x12c] */
/* @0x2ad4fc mov r0, r4 */
/* @0x2ad4fe lsls r2, r3, #0x1d */
/* @0x2ad500 itt mi */
/* @0x2ad502 orrmi r3, r3, #0x8 */
/* @0x2ad504 .word 0xf8c40308 */
/* @0x2ad506 strmi.w r3, [r4, #0x12c] */
/* @0x2ad508 stchs p1, c3, [r7, #-176] */
/* @0x2ad50a cmp r5, #0x7 */
/* @0x2ad50c beq 0x2ad520 <png_handle_tIME+0x50> */
/* @0x2ad50e ldr r1, [pc, #0x70] */
/* @0x2ad510 add r1, pc */
/* @0x2ad512 bl 0x2a6474 <png_warning> */
/* @0x2ad514 strtmi pc, [r0], -pc, lsr #31 */
/* @0x2ad516 mov r0, r4 */
/* @0x2ad518 mov r1, r5 */
/* @0x2ad51a bl 0x2abc94 <png_crc_finish> */
/* @0x2ad51c .word 0xe029fbbb */
/* @0x2ad51e b 0x2ad574 <png_handle_tIME+0xa4> */
/* @0x2ad520 mov r1, sp */
/* @0x2ad522 mov r2, r5 */
/* @0x2ad524 bl 0x2abc0c <png_crc_read> */
/* @0x2ad528 mov r0, r4 */
/* @0x2ad52a movs r1, #0x0 */
/* @0x2ad52c bl 0x2abc94 <png_crc_finish> */
/* @0x2ad530 cbnz r0, 0x2ad574 <png_handle_tIME+0xa4> */
/* @0x2ad532 ldrb.w r3, [sp, #0x6] */
/* @0x2ad534 strtmi r3, [r0], -r6 */
/* @0x2ad536 mov r0, r4 */
/* @0x2ad538 ldrb.w r2, [sp] */
/* @0x2ad53c mov r1, r6 */
/* @0x2ad53e strb.w r3, [sp, #0xe] */
/* @0x2ad540 .word 0xf89d300e */
/* @0x2ad542 ldrb.w r3, [sp, #0x5] */
/* @0x2ad544 .word 0xf88d3005 */
/* @0x2ad546 strb.w r3, [sp, #0xd] */
/* @0x2ad548 .word 0xf89d300d */
/* @0x2ad54a ldrb.w r3, [sp, #0x4] */
/* @0x2ad54c .word 0xf88d3004 */
/* @0x2ad54e strb.w r3, [sp, #0xc] */
/* @0x2ad550 .word 0xf89d300c */
/* @0x2ad552 ldrb.w r3, [sp, #0x3] */
/* @0x2ad554 .word 0xf88d3003 */
/* @0x2ad556 strb.w r3, [sp, #0xb] */
/* @0x2ad558 .word 0xf89d300b */
/* @0x2ad55a ldrb.w r3, [sp, #0x2] */
/* @0x2ad55c .word 0xf88d3002 */
/* @0x2ad55e strb.w r3, [sp, #0xa] */
/* @0x2ad560 .word 0xf89d300a */
/* @0x2ad562 ldrb.w r3, [sp, #0x1] */
/* @0x2ad564 bl 0x379570 <_ZTS13C_UTF16String+0x1061c> */
/* @0x2ad566 add.w r3, r3, r2, lsl #8 */
/* @0x2ad568 bge 0x3b6178 <error_g0017+0xee1c> */
/* @0x2ad56a add r2, sp, #0x10 */
/* @0x2ad56c strh r3, [r2, #-8]! */
/* @0x2ad570 bl 0x2af100 <png_set_tIME> */
/* @0x2ad574 add sp, #0x10 */
/* @0x2ad576 pop {r4, r5, r6, pc} */
/* @0x2ad578 lsls r7, r7, #0x7 */
/* @0x2ad57a movs r6, r1 */
/* @0x2ad57c lsls r5, r0, #0x8 */
/* @0x2ad57e movs r6, r1 */
/* @0x2ad580 lsls r6, r7, #0x7 */
/* @0x2ad582 movs r6, r1 */

/* ── FUNC 0x2ad584 · png_handle_tEXt · size=328 · insn=152 */
/* @0x2ad584 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2ad588 mov r4, r0 */
/* @0x2ad58a ldr.w r3, [r0, #0x310] */
/* @0x2ad58c pkhbtmi r3, r9, r0, lsl #6 */
/* @0x2ad58e mov r9, r1 */
/* @0x2ad590 mov r5, r2 */
/* @0x2ad592 cbz r3, 0x2ad5b6 <png_handle_tEXt+0x32> */
/* @0x2ad594 cmp r3, #0x1 */
/* @0x2ad596 beq 0x2ad5ac <png_handle_tEXt+0x28> */
/* @0x2ad598 subs r3, #0x1 */
/* @0x2ad59a str.w r3, [r0, #0x310] */
/* @0x2ad59c blhs 0x2fa1e4 <ps_hints_apply+0x8de4> */
/* @0x2ad59e cmp r3, #0x1 */
/* @0x2ad5a0 bne 0x2ad5b6 <png_handle_tEXt+0x32> */
/* @0x2ad5a2 ldr r1, [pc, #0x114] */
/* @0x2ad5a4 add r1, pc */
/* @0x2ad5a6 bl 0x2a6474 <png_warning> */
/* @0x2ad5a8 strtmi pc, [r0], -r5, ror #30 */
/* @0x2ad5aa mov r0, r4 */
/* @0x2ad5ac mov r1, r5 */
/* @0x2ad5ae pop.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2ad5b0 .word 0xf7fe43f8 */
/* @0x2ad5b2 b.w 0x2abc94 <png_crc_finish> */
/* @0x2ad5b4 .word 0xf8d4bb6f */
/* @0x2ad5b6 ldr.w r3, [r4, #0x12c] */
/* @0x2ad5b8 ldrbeq r3, [r9, r12, lsr #2] */
/* @0x2ad5ba lsls r1, r3, #0x1f */
/* @0x2ad5bc bmi 0x2ad5c8 <png_handle_tEXt+0x44> */
/* @0x2ad5be ldr r1, [pc, #0xfc] */
/* @0x2ad5c0 mov r0, r4 */
/* @0x2ad5c2 add r1, pc */
/* @0x2ad5c4 bl 0x2a642c <png_error> */
/* @0x2ad5c8 ldr.w r3, [r4, #0x12c] */
/* @0x2ad5cc mov r0, r4 */
/* @0x2ad5ce ldr.w r1, [r4, #0x330] */
/* @0x2ad5d0 smmlareq r10, r0, r3, r1 */
/* @0x2ad5d2 lsls r2, r3, #0x1d */
/* @0x2ad5d4 itt mi */
/* @0x2ad5d6 orrmi r3, r3, #0x8 */
/* @0x2ad5d8 .word 0xf8c40308 */
/* @0x2ad5da strmi.w r3, [r4, #0x12c] */
/* @0x2ad5dc .word 0xf7f9312c */
/* @0x2ad5de bl 0x2a6cfc <png_free> */
/* @0x2ad5e0 .word 0x1c69fb8d */
/* @0x2ad5e2 adds r1, r5, #0x1 */
/* @0x2ad5e4 mov r0, r4 */
/* @0x2ad5e6 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad5e8 .word 0x4601fb96 */
/* @0x2ad5ea mov r1, r0 */
/* @0x2ad5ec str.w r0, [r4, #0x330] */
/* @0x2ad5f0 mov r0, r4 */
/* @0x2ad5f2 cbnz r1, 0x2ad5fa <png_handle_tEXt+0x76> */
/* @0x2ad5f4 ldr r1, [pc, #0xc8] */
/* @0x2ad5f6 add r1, pc */
/* @0x2ad5f8 b 0x2ad6aa <png_handle_tEXt+0x126> */
/* @0x2ad5fa mov r2, r5 */
/* @0x2ad5fc bl 0x2abc0c <png_crc_read> */
/* @0x2ad600 mov r0, r4 */
/* @0x2ad602 movs r1, #0x0 */
/* @0x2ad604 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad608 cbz r0, 0x2ad61e <png_handle_tEXt+0x9a> */
/* @0x2ad60a mov r0, r4 */
/* @0x2ad60c ldr.w r1, [r4, #0x330] */
/* @0x2ad610 bl 0x2a6cfc <png_free> */
/* @0x2ad614 movs r3, #0x0 */
/* @0x2ad616 str.w r3, [r4, #0x330] */
/* @0x2ad618 pop {r4, r5, r8, r9, r12, sp} */
/* @0x2ad61a pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2ad61c .word 0xf8d483f8 */
/* @0x2ad61e ldr.w r8, [r4, #0x330] */
/* @0x2ad620 bl 0x4ce2e8 <SrcVerts+0x2b32c> */
/* @0x2ad622 add.w r2, r8, r5 */
/* @0x2ad624 strbmi r0, [r3], -r5, lsl #4 */
/* @0x2ad626 mov r3, r8 */
/* @0x2ad628 strb.w r0, [r8, r5] */
/* @0x2ad62c mov r7, r3 */
/* @0x2ad62e adds r3, #0x1 */
/* @0x2ad630 ldrb r6, [r7] */
/* @0x2ad632 cmp r6, #0x0 */
/* @0x2ad634 bne 0x2ad62c <png_handle_tEXt+0xa8> */
/* @0x2ad636 mov r0, r4 */
/* @0x2ad638 movs r1, #0x1c */
/* @0x2ad63a cmp r7, r2 */
/* @0x2ad63c ite eq */
/* @0x2ad63e moveq r7, r2 */
/* @0x2ad640 movne r7, r3 */
/* @0x2ad642 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad644 strmi pc, [r5], -r8, ror #22 */
/* @0x2ad646 mov r5, r0 */
/* @0x2ad648 cbnz r0, 0x2ad666 <png_handle_tEXt+0xe2> */
/* @0x2ad64a ldr r1, [pc, #0x78] */
/* @0x2ad64c mov r0, r4 */
/* @0x2ad64e add r1, pc */
/* @0x2ad650 bl 0x2a6474 <png_warning> */
/* @0x2ad654 mov r0, r4 */
/* @0x2ad656 ldr.w r1, [r4, #0x330] */
/* @0x2ad658 .word 0xf7f91330 */
/* @0x2ad65a bl 0x2a6cfc <png_free> */
/* @0x2ad65c .word 0xf8c4fb4f */
/* @0x2ad65e str.w r5, [r4, #0x330] */
/* @0x2ad660 pop {r4, r5, r8, r9, r12, lr} */
/* @0x2ad662 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2ad664 .word 0xf04f83f8 */
/* @0x2ad666 mov.w r3, #0xffffffff */
/* @0x2ad668 strdvs r3, r4, [r7], pc */
/* @0x2ad66a str r7, [r0, #0x8] */
/* @0x2ad66c stm.w r0, {r3, r8} */
/* @0x2ad670 str r6, [r0, #0x14] */
/* @0x2ad672 str r6, [r0, #0x18] */
/* @0x2ad674 str r6, [r0, #0x10] */
/* @0x2ad676 mov r0, r7 */
/* @0x2ad678 blx 0xb6538 <strlen@plt> */
/* @0x2ad67c mov r1, r9 */
/* @0x2ad67e mov r2, r5 */
/* @0x2ad680 movs r3, #0x1 */
/* @0x2ad682 str r0, [r5, #0xc] */
/* @0x2ad684 mov r0, r4 */
/* @0x2ad686 bl 0x2aeef8 <png_set_text_2> */
/* @0x2ad688 .word 0xf8d4fc37 */
/* @0x2ad68a ldr.w r1, [r4, #0x330] */
/* @0x2ad68c .word 0x46071330 */
/* @0x2ad68e mov r7, r0 */
/* @0x2ad690 mov r0, r4 */
/* @0x2ad692 bl 0x2a6cfc <png_free> */
/* @0x2ad694 .word 0xf8c4fb33 */
/* @0x2ad696 str.w r6, [r4, #0x330] */
/* @0x2ad698 qasxmi r6, r0, r0 */
/* @0x2ad69a mov r0, r4 */
/* @0x2ad69c mov r1, r5 */
/* @0x2ad69e bl 0x2a6cfc <png_free> */
/* @0x2ad6a0 teqlt r7, sp, lsr #22 */
/* @0x2ad6a2 cbz r7, 0x2ad6b2 <png_handle_tEXt+0x12e> */
/* @0x2ad6a4 ldr r1, [pc, #0x20] */
/* @0x2ad6a6 mov r0, r4 */
/* @0x2ad6a8 add r1, pc */
/* @0x2ad6aa pop.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2ad6ac .word 0xf7f843f8 */
/* @0x2ad6ae b.w 0x2a6474 <png_warning> */
/* @0x2ad6b0 pop {r0, r5, r6, r7, r9, r10, r11, r12, sp, pc} */
/* @0x2ad6b2 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2ad6b4 svclt #0x83f8 */
/* @0x2ad6b6 nop */
/* @0x2ad6b8 lsls r6, r0, #0x6 */
/* @0x2ad6ba movs r6, r1 */
/* @0x2ad6bc lsls r1, r1, #0x6 */
/* @0x2ad6be movs r6, r1 */
/* @0x2ad6c0 lsls r6, r5, #0x5 */
/* @0x2ad6c2 movs r6, r1 */
/* @0x2ad6c4 lsls r6, r6, #0x4 */
/* @0x2ad6c6 movs r6, r1 */
/* @0x2ad6c8 lsls r4, r0, #0x4 */
/* @0x2ad6ca movs r6, r1 */

/* ── FUNC 0x2ad6cc · png_handle_zTXt · size=388 · insn=174 */
/* @0x2ad6cc push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2ad6d0 mov r4, r0 */
/* @0x2ad6d2 ldr.w r3, [r0, #0x310] */
/* @0x2ad6d4 .word 0x460f3310 */
/* @0x2ad6d6 mov r7, r1 */
/* @0x2ad6d8 mov r5, r2 */
/* @0x2ad6da cbz r3, 0x2ad6fc <png_handle_zTXt+0x30> */
/* @0x2ad6dc cmp r3, #0x1 */
/* @0x2ad6de beq 0x2ad6f4 <png_handle_zTXt+0x28> */
/* @0x2ad6e0 subs r3, #0x1 */
/* @0x2ad6e2 str.w r3, [r0, #0x310] */
/* @0x2ad6e4 blhs 0x2fa32c <ps_hints_apply+0x8f2c> */
/* @0x2ad6e6 cmp r3, #0x1 */
/* @0x2ad6e8 bne 0x2ad6fc <png_handle_zTXt+0x30> */
/* @0x2ad6ea ldr r1, [pc, #0x148] */
/* @0x2ad6ec add r1, pc */
/* @0x2ad6ee bl 0x2a6474 <png_warning> */
/* @0x2ad6f0 strtmi pc, [r0], -r1, asr #29 */
/* @0x2ad6f2 mov r0, r4 */
/* @0x2ad6f4 mov r1, r5 */
/* @0x2ad6f6 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad6f8 adds pc, r7, sp, asr #21 */
/* @0x2ad6fa b 0x2ad82c <png_handle_zTXt+0x160> */
/* @0x2ad6fc ldr.w r3, [r4, #0x12c] */
/* @0x2ad700 lsls r1, r3, #0x1f */
/* @0x2ad702 bmi 0x2ad70e <png_handle_zTXt+0x42> */
/* @0x2ad704 ldr r1, [pc, #0x130] */
/* @0x2ad706 mov r0, r4 */
/* @0x2ad708 add r1, pc */
/* @0x2ad70a bl 0x2a642c <png_error> */
/* @0x2ad70c .word 0xf8d4fe8f */
/* @0x2ad70e ldr.w r3, [r4, #0x12c] */
/* @0x2ad710 strtmi r3, [r0], -r12, lsr #2 */
/* @0x2ad712 mov r0, r4 */
/* @0x2ad714 ldr.w r1, [r4, #0x330] */
/* @0x2ad718 lsls r2, r3, #0x1d */
/* @0x2ad71a itt mi */
/* @0x2ad71c orrmi r3, r3, #0x8 */
/* @0x2ad720 strmi.w r3, [r4, #0x12c] */
/* @0x2ad724 bl 0x2a6cfc <png_free> */
/* @0x2ad728 adds r1, r5, #0x1 */
/* @0x2ad72a mov r0, r4 */
/* @0x2ad72c bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad730 mov r1, r0 */
/* @0x2ad732 str.w r0, [r4, #0x330] */
/* @0x2ad734 qasxmi r0, r0, r0 */
/* @0x2ad736 mov r0, r4 */
/* @0x2ad738 cbnz r1, 0x2ad744 <png_handle_zTXt+0x78> */
/* @0x2ad73a ldr r1, [pc, #0x100] */
/* @0x2ad73c add r1, pc */
/* @0x2ad73e bl 0x2a6474 <png_warning> */
/* @0x2ad740 .word 0xe073fe99 */
/* @0x2ad742 b 0x2ad82c <png_handle_zTXt+0x160> */
/* @0x2ad744 mov r2, r5 */
/* @0x2ad746 bl 0x2abc0c <png_crc_read> */
/* @0x2ad748 strtmi pc, [r0], -r1, ror #20 */
/* @0x2ad74a mov r0, r4 */
/* @0x2ad74c movs r1, #0x0 */
/* @0x2ad74e bl 0x2abc94 <png_crc_finish> */
/* @0x2ad750 stmiblt r8!, {r0, r5, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2ad752 cbnz r0, 0x2ad780 <png_handle_zTXt+0xb4> */
/* @0x2ad754 ldr.w r3, [r4, #0x330] */
/* @0x2ad758 strb r0, [r3, r5] */
/* @0x2ad75a ldr.w r3, [r4, #0x330] */
/* @0x2ad75c sasxmi r3, r10, r0 */
/* @0x2ad75e mov r2, r3 */
/* @0x2ad760 mov r6, r2 */
/* @0x2ad762 adds r2, #0x1 */
/* @0x2ad764 ldrb r1, [r6] */
/* @0x2ad766 cmp r1, #0x0 */
/* @0x2ad768 bne 0x2ad760 <png_handle_zTXt+0x94> */
/* @0x2ad76a cmp r5, #0x1 */
/* @0x2ad76c bls 0x2ad776 <png_handle_zTXt+0xaa> */
/* @0x2ad76e subs r2, r5, #0x2 */
/* @0x2ad770 add r3, r2 */
/* @0x2ad772 cmp r6, r3 */
/* @0x2ad774 blo 0x2ad792 <png_handle_zTXt+0xc6> */
/* @0x2ad776 ldr r1, [pc, #0xc8] */
/* @0x2ad778 mov r0, r4 */
/* @0x2ad77a add r1, pc */
/* @0x2ad77c bl 0x2a6474 <png_warning> */
/* @0x2ad780 mov r0, r4 */
/* @0x2ad782 ldr.w r1, [r4, #0x330] */
/* @0x2ad784 .word 0xf7f91330 */
/* @0x2ad786 bl 0x2a6cfc <png_free> */
/* @0x2ad788 movwhs pc, #0xab9 */
/* @0x2ad78a movs r3, #0x0 */
/* @0x2ad78c str.w r3, [r4, #0x330] */
/* @0x2ad790 b 0x2ad82c <png_handle_zTXt+0x160> */
/* @0x2ad792 ldrb r3, [r6, #0x1] */
/* @0x2ad794 cbz r3, 0x2ad7a0 <png_handle_zTXt+0xd4> */
/* @0x2ad796 ldr r1, [pc, #0xac] */
/* @0x2ad798 mov r0, r4 */
/* @0x2ad79a add r1, pc */
/* @0x2ad79c bl 0x2a6474 <png_warning> */
/* @0x2ad7a0 ldr.w r3, [r4, #0x330] */
/* @0x2ad7a4 adds r6, #0x2 */
/* @0x2ad7a6 mov r2, r5 */
/* @0x2ad7a8 mov r0, r4 */
/* @0x2ad7aa rsb r8, r3, r6 */
/* @0x2ad7ac .word 0x21000806 */
/* @0x2ad7ae movs r1, #0x0 */
/* @0x2ad7b0 add r3, sp, #0xc */
/* @0x2ad7b2 str r3, [sp] */
/* @0x2ad7b4 mov r3, r8 */
/* @0x2ad7b6 bl 0x2abd08 <png_decompress_chunk> */
/* @0x2ad7b8 strtmi pc, [r0], -r7, lsr #21 */
/* @0x2ad7ba mov r0, r4 */
/* @0x2ad7bc movs r1, #0x1c */
/* @0x2ad7be bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad7c0 strmi pc, [r5], -r10, lsr #21 */
/* @0x2ad7c2 mov r5, r0 */
/* @0x2ad7c4 cbnz r0, 0x2ad7e0 <png_handle_zTXt+0x114> */
/* @0x2ad7c6 ldr r1, [pc, #0x80] */
/* @0x2ad7c8 mov r0, r4 */
/* @0x2ad7ca add r1, pc */
/* @0x2ad7cc bl 0x2a6474 <png_warning> */
/* @0x2ad7d0 mov r0, r4 */
/* @0x2ad7d2 ldr.w r1, [r4, #0x330] */
/* @0x2ad7d4 .word 0xf7f91330 */
/* @0x2ad7d6 bl 0x2a6cfc <png_free> */
/* @0x2ad7d8 .word 0xf8c4fa91 */
/* @0x2ad7da str.w r5, [r4, #0x330] */
/* @0x2ad7dc eor r5, r5, r0, lsr r3 */
/* @0x2ad7de b 0x2ad82c <png_handle_zTXt+0x160> */
/* @0x2ad7e0 movs r6, #0x0 */
/* @0x2ad7e2 str r6, [r0] */
/* @0x2ad7e4 ldr.w r3, [r4, #0x330] */
/* @0x2ad7e8 mov r1, r7 */
/* @0x2ad7ea str r6, [r0, #0x14] */
/* @0x2ad7ec mov r2, r5 */
/* @0x2ad7ee str r6, [r0, #0x18] */
/* @0x2ad7f0 str r3, [r0, #0x4] */
/* @0x2ad7f2 str r6, [r0, #0x10] */
/* @0x2ad7f4 ldr.w r3, [r4, #0x330] */
/* @0x2ad7f8 add r3, r8 */
/* @0x2ad7fa str r3, [r0, #0x8] */
/* @0x2ad7fc ldr r3, [sp, #0xc] */
/* @0x2ad7fe str r3, [r0, #0xc] */
/* @0x2ad800 movs r3, #0x1 */
/* @0x2ad802 mov r0, r4 */
/* @0x2ad804 bl 0x2aeef8 <png_set_text_2> */
/* @0x2ad808 mov r1, r5 */
/* @0x2ad80a mov r7, r0 */
/* @0x2ad80c mov r0, r4 */
/* @0x2ad80e bl 0x2a6cfc <png_free> */
/* @0x2ad810 qsub16mi pc, r0, r5 */
/* @0x2ad812 mov r0, r4 */
/* @0x2ad814 ldr.w r1, [r4, #0x330] */
/* @0x2ad818 bl 0x2a6cfc <png_free> */
/* @0x2ad81c str.w r6, [r4, #0x330] */
/* @0x2ad820 cbz r7, 0x2ad82c <png_handle_zTXt+0x160> */
/* @0x2ad822 ldr r1, [pc, #0x28] */
/* @0x2ad824 mov r0, r4 */
/* @0x2ad826 add r1, pc */
/* @0x2ad828 bl 0x2a642c <png_error> */
/* @0x2ad82c add sp, #0x10 */
/* @0x2ad82e pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2ad830 svclt #0x81f0 */
/* @0x2ad832 nop */
/* @0x2ad834 lsls r2, r5, #0x3 */
/* @0x2ad836 movs r6, r1 */
/* @0x2ad838 lsls r7, r5, #0x3 */
/* @0x2ad83a movs r6, r1 */
/* @0x2ad83c lsls r4, r2, #0x3 */
/* @0x2ad83e movs r6, r1 */
/* @0x2ad840 lsls r2, r7, #0x2 */
/* @0x2ad842 movs r6, r1 */
/* @0x2ad844 lsls r7, r5, #0x2 */
/* @0x2ad846 movs r6, r1 */
/* @0x2ad848 lsls r6, r4, #0x2 */
/* @0x2ad84a movs r6, r1 */
/* @0x2ad84c lsls r2, r6, #0x1 */
/* @0x2ad84e movs r6, r1 */

/* ── FUNC 0x2ad850 · png_handle_iTXt · size=484 · insn=211 */
/* @0x2ad850 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ad854 mov r4, r0 */
/* @0x2ad856 ldr.w r3, [r0, #0x310] */
/* @0x2ad858 addlt r3, r5, r0, lsl r3 */
/* @0x2ad85a sub sp, #0x14 */
/* @0x2ad85c mov r10, r1 */
/* @0x2ad85e mov r5, r2 */
/* @0x2ad860 cbz r3, 0x2ad882 <png_handle_iTXt+0x32> */
/* @0x2ad862 cmp r3, #0x1 */
/* @0x2ad864 beq 0x2ad87a <png_handle_iTXt+0x2a> */
/* @0x2ad866 subs r3, #0x1 */
/* @0x2ad868 str.w r3, [r0, #0x310] */
/* @0x2ad86c cmp r3, #0x1 */
/* @0x2ad86e bne 0x2ad882 <png_handle_iTXt+0x32> */
/* @0x2ad870 ldr r1, [pc, #0x1a4] */
/* @0x2ad872 add r1, pc */
/* @0x2ad874 bl 0x2a6474 <png_warning> */
/* @0x2ad878 mov r0, r4 */
/* @0x2ad87a mov r1, r5 */
/* @0x2ad87c bl 0x2abc94 <png_crc_finish> */
/* @0x2ad880 b 0x2ada10 <png_handle_iTXt+0x1c0> */
/* @0x2ad882 ldr.w r3, [r4, #0x12c] */
/* @0x2ad884 ldrbeq r3, [r9, r12, lsr #2] */
/* @0x2ad886 lsls r1, r3, #0x1f */
/* @0x2ad888 bmi 0x2ad894 <png_handle_iTXt+0x44> */
/* @0x2ad88a ldr r1, [pc, #0x190] */
/* @0x2ad88c mov r0, r4 */
/* @0x2ad88e add r1, pc */
/* @0x2ad890 bl 0x2a642c <png_error> */
/* @0x2ad894 ldr.w r3, [r4, #0x12c] */
/* @0x2ad898 mov r0, r4 */
/* @0x2ad89a ldr.w r1, [r4, #0x330] */
/* @0x2ad89c smmlareq r10, r0, r3, r1 */
/* @0x2ad89e lsls r2, r3, #0x1d */
/* @0x2ad8a0 itt mi */
/* @0x2ad8a2 orrmi r3, r3, #0x8 */
/* @0x2ad8a4 .word 0xf8c40308 */
/* @0x2ad8a6 strmi.w r3, [r4, #0x12c] */
/* @0x2ad8a8 .word 0xf7f9312c */
/* @0x2ad8aa bl 0x2a6cfc <png_free> */
/* @0x2ad8ac .word 0x1c69fa27 */
/* @0x2ad8ae adds r1, r5, #0x1 */
/* @0x2ad8b0 mov r0, r4 */
/* @0x2ad8b2 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad8b4 .word 0x4601fa30 */
/* @0x2ad8b6 mov r1, r0 */
/* @0x2ad8b8 str.w r0, [r4, #0x330] */
/* @0x2ad8bc mov r0, r4 */
/* @0x2ad8be cbnz r1, 0x2ad8ca <png_handle_iTXt+0x7a> */
/* @0x2ad8c0 ldr r1, [pc, #0x15c] */
/* @0x2ad8c2 add r1, pc */
/* @0x2ad8c4 bl 0x2a6474 <png_warning> */
/* @0x2ad8c8 b 0x2ada10 <png_handle_iTXt+0x1c0> */
/* @0x2ad8ca mov r2, r5 */
/* @0x2ad8cc bl 0x2abc0c <png_crc_read> */
/* @0x2ad8d0 mov r0, r4 */
/* @0x2ad8d2 movs r1, #0x0 */
/* @0x2ad8d4 bl 0x2abc94 <png_crc_finish> */
/* @0x2ad8d8 cbnz r0, 0x2ad908 <png_handle_iTXt+0xb8> */
/* @0x2ad8da ldr.w r3, [r4, #0x330] */
/* @0x2ad8dc ldrbpl r3, [r8, #-0x330] */
/* @0x2ad8de strb r0, [r3, r5] */
/* @0x2ad8e0 ldr.w r11, [r4, #0x330] */
/* @0x2ad8e4 mov r2, r11 */
/* @0x2ad8e6 mov r3, r2 */
/* @0x2ad8e8 adds r2, #0x1 */
/* @0x2ad8ea ldrb r1, [r3] */
/* @0x2ad8ec cmp r1, #0x0 */
/* @0x2ad8ee bne 0x2ad8e6 <png_handle_iTXt+0x96> */
/* @0x2ad8f0 cmp r5, #0x2 */
/* @0x2ad8f2 bls 0x2ad8fe <png_handle_iTXt+0xae> */
/* @0x2ad8f4 mov r1, r2 */
/* @0x2ad8f6 subs r2, r5, #0x3 */
/* @0x2ad8f8 add r2, r11 */
/* @0x2ad8fa cmp r1, r2 */
/* @0x2ad8fc blo 0x2ad91a <png_handle_iTXt+0xca> */
/* @0x2ad8fe ldr r1, [pc, #0x124] */
/* @0x2ad900 mov r0, r4 */
/* @0x2ad902 add r1, pc */
/* @0x2ad904 bl 0x2a6474 <png_warning> */
/* @0x2ad908 mov r0, r4 */
/* @0x2ad90a ldr.w r1, [r4, #0x330] */
/* @0x2ad90c .word 0xf7f91330 */
/* @0x2ad90e bl 0x2a6cfc <png_free> */
/* @0x2ad910 movwhs pc, #0x9f5 */
/* @0x2ad912 movs r3, #0x0 */
/* @0x2ad914 str.w r3, [r4, #0x330] */
/* @0x2ad918 b 0x2ada10 <png_handle_iTXt+0x1c0> */
/* @0x2ad91a add.w r8, r3, #0x3 */
/* @0x2ad91c .word 0xf8930803 */
/* @0x2ad91e ldrb.w r9, [r3, #0x1] */
/* @0x2ad920 ldmvc r9, {r0, r12, pc} */
/* @0x2ad922 ldrb r1, [r3, #0x2] */
/* @0x2ad924 mov r3, r8 */
/* @0x2ad926 mov r7, r3 */
/* @0x2ad928 adds r3, #0x1 */
/* @0x2ad92a ldrb r2, [r7] */
/* @0x2ad92c cmp r2, #0x0 */
/* @0x2ad92e bne 0x2ad926 <png_handle_iTXt+0xd6> */
/* @0x2ad930 add.w r2, r11, r5 */
/* @0x2ad934 mov r7, r3 */
/* @0x2ad936 cmp r3, r2 */
/* @0x2ad938 bhs 0x2ad8fe <png_handle_iTXt+0xae> */
/* @0x2ad93a mov r0, r3 */
/* @0x2ad93c adds r3, #0x1 */
/* @0x2ad93e ldrb r6, [r0] */
/* @0x2ad940 cmp r6, #0x0 */
/* @0x2ad942 bne 0x2ad93a <png_handle_iTXt+0xea> */
/* @0x2ad944 cmp r3, r2 */
/* @0x2ad946 blo 0x2ad962 <png_handle_iTXt+0x112> */
/* @0x2ad948 ldr r1, [pc, #0xdc] */
/* @0x2ad94a mov r0, r4 */
/* @0x2ad94c add r1, pc */
/* @0x2ad94e bl 0x2a6474 <png_warning> */
/* @0x2ad950 qadd8mi pc, r0, r1 */
/* @0x2ad952 mov r0, r4 */
/* @0x2ad954 ldr.w r1, [r4, #0x330] */
/* @0x2ad958 bl 0x2a6cfc <png_free> */
/* @0x2ad95c str.w r6, [r4, #0x330] */
/* @0x2ad960 b 0x2ada10 <png_handle_iTXt+0x1c0> */
/* @0x2ad962 rsb r6, r11, r3 */
/* @0x2ad964 .word 0xf1b90603 */
/* @0x2ad966 cmp.w r9, #0x0 */
/* @0x2ad968 andle r0, r7, r0, lsl #30 */
/* @0x2ad96a beq 0x2ad97c <png_handle_iTXt+0x12c> */
/* @0x2ad96c add r3, sp, #0xc */
/* @0x2ad96e mov r0, r4 */
/* @0x2ad970 str r3, [sp] */
/* @0x2ad972 mov r2, r5 */
/* @0x2ad974 mov r3, r6 */
/* @0x2ad976 bl 0x2abd08 <png_decompress_chunk> */
/* @0x2ad978 and pc, r4, r7, asr #19 */
/* @0x2ad97a b 0x2ad986 <png_handle_iTXt+0x136> */
/* @0x2ad97c add.w r0, r11, r6 */
/* @0x2ad980 blx 0xb6538 <strlen@plt> */
/* @0x2ad984 str r0, [sp, #0xc] */
/* @0x2ad986 mov r0, r4 */
/* @0x2ad988 movs r1, #0x1c */
/* @0x2ad98a bl 0x2a6d16 <png_malloc_warn> */
/* @0x2ad98c strmi pc, [r5], -r4, asr #19 */
/* @0x2ad98e mov r5, r0 */
/* @0x2ad990 cbnz r0, 0x2ad9ac <png_handle_iTXt+0x15c> */
/* @0x2ad992 ldr r1, [pc, #0x98] */
/* @0x2ad994 mov r0, r4 */
/* @0x2ad996 add r1, pc */
/* @0x2ad998 bl 0x2a6474 <png_warning> */
/* @0x2ad99c mov r0, r4 */
/* @0x2ad99e ldr.w r1, [r4, #0x330] */
/* @0x2ad9a0 .word 0xf7f91330 */
/* @0x2ad9a2 bl 0x2a6cfc <png_free> */
/* @0x2ad9a4 .word 0xf8c4f9ab */
/* @0x2ad9a6 str.w r5, [r4, #0x330] */
/* @0x2ad9a8 eors r5, r1, r0, lsr r3 */
/* @0x2ad9aa b 0x2ada10 <png_handle_iTXt+0x1c0> */
/* @0x2ad9ac add.w r3, r9, #0x1 */
/* @0x2ad9b0 str r3, [r0] */
/* @0x2ad9b2 ldr.w r3, [r4, #0x330] */
/* @0x2ad9b4 bl 0xff57a67c <b2_toiTime+0xfffffffffee211d8> */
/* @0x2ad9b6 rsb r7, r11, r7 */
/* @0x2ad9b8 bl 0xff56f5dc <b2_toiTime+0xfffffffffee16138> */
/* @0x2ad9ba rsb r8, r11, r8 */
/* @0x2ad9bc strtmi r0, [r10], -r8, lsl #16 */
/* @0x2ad9be mov r2, r5 */
/* @0x2ad9c0 add r3, r7 */
/* @0x2ad9c2 str r3, [r0, #0x18] */
/* @0x2ad9c4 ldr.w r3, [r4, #0x330] */
/* @0x2ad9c8 movs r7, #0x0 */
/* @0x2ad9ca str r7, [r0, #0xc] */
/* @0x2ad9cc mov r1, r10 */
/* @0x2ad9ce add r3, r8 */
/* @0x2ad9d0 str r3, [r0, #0x14] */
/* @0x2ad9d2 ldr r3, [sp, #0xc] */
/* @0x2ad9d4 str r3, [r0, #0x10] */
/* @0x2ad9d6 ldr.w r3, [r4, #0x330] */
/* @0x2ad9d8 subvs r3, r3, r0, lsr r3 */
/* @0x2ad9da str r3, [r0, #0x4] */
/* @0x2ad9dc ldr.w r3, [r4, #0x330] */
/* @0x2ad9e0 add r6, r3 */
/* @0x2ad9e2 movs r3, #0x1 */
/* @0x2ad9e4 str r6, [r0, #0x8] */
/* @0x2ad9e6 mov r0, r4 */
/* @0x2ad9e8 bl 0x2aeef8 <png_set_text_2> */
/* @0x2ad9ec mov r1, r5 */
/* @0x2ad9ee mov r6, r0 */
/* @0x2ad9f0 mov r0, r4 */
/* @0x2ad9f2 bl 0x2a6cfc <png_free> */
/* @0x2ad9f4 strtmi pc, [r0], -r3, lsl #19 */
/* @0x2ad9f6 mov r0, r4 */
/* @0x2ad9f8 ldr.w r1, [r4, #0x330] */
/* @0x2ad9fc bl 0x2a6cfc <png_free> */
/* @0x2ada00 str.w r7, [r4, #0x330] */
/* @0x2ada04 cbz r6, 0x2ada10 <png_handle_iTXt+0x1c0> */
/* @0x2ada06 ldr r1, [pc, #0x28] */
/* @0x2ada08 mov r0, r4 */
/* @0x2ada0a add r1, pc */
/* @0x2ada0c bl 0x2a642c <png_error> */
/* @0x2ada10 add sp, #0x14 */
/* @0x2ada12 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ada14 svclt #0x8ff0 */
/* @0x2ada16 nop */
/* @0x2ada18 lsls r6, r1, #0x1 */
/* @0x2ada1a movs r6, r1 */
/* @0x2ada1c lsls r3, r2, #0x1 */
/* @0x2ada1e movs r6, r1 */
/* @0x2ada20 movs r0, r7 */
/* @0x2ada22 movs r6, r1 */
/* @0x2ada24 movs r0, r3 */
/* @0x2ada26 movs r6, r1 */
/* @0x2ada28 vaddl.u32 q8, d3, d13 */
/* @0x2ada2c vaddl.u32 q0, d14, d13 */
/* @0x2ada30 vhadd.u32 d16, d2, d13 */

/* ── FUNC 0x2ada34 · png_handle_unknown · size=320 · insn=133 */
/* @0x2ada34 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2ada38 mov r4, r0 */
/* @0x2ada3a ldr.w r3, [r0, #0x310] */
/* @0x2ada3c .word 0x460f3310 */
/* @0x2ada3e mov r7, r1 */
/* @0x2ada40 mov r5, r2 */
/* @0x2ada42 cbz r3, 0x2ada5e <png_handle_unknown+0x2a> */
/* @0x2ada44 cmp r3, #0x1 */
/* @0x2ada46 beq.w 0x2adb52 <png_handle_unknown+0x11e> */
/* @0x2ada48 bllo 0x30dc60 <af_shaper_get_elem+0x34ce> */
/* @0x2ada4a subs r3, #0x1 */
/* @0x2ada4c str.w r3, [r0, #0x310] */
/* @0x2ada50 cmp r3, #0x1 */
/* @0x2ada52 bne 0x2ada5e <png_handle_unknown+0x2a> */
/* @0x2ada54 ldr r1, [pc, #0x108] */
/* @0x2ada56 add r1, pc */
/* @0x2ada58 bl 0x2a6474 <png_warning> */
/* @0x2ada5c b 0x2adb50 <png_handle_unknown+0x11c> */
/* @0x2ada5e ldr.w r6, [r4, #0x12c] */
/* @0x2ada60 ldrbeq r6, [r0, -r12, lsr #2]! */
/* @0x2ada62 lsls r0, r6, #0x1d */
/* @0x2ada64 bpl 0x2ada8a <png_handle_unknown+0x56> */
/* @0x2ada66 ldr r3, [pc, #0xfc] */
/* @0x2ada68 mov r1, sp */
/* @0x2ada6a movs r2, #0x4 */
/* @0x2ada6c add r3, pc */
/* @0x2ada6e ldr r0, [r3] */
/* @0x2ada70 ldrb r3, [r3, #0x4] */
/* @0x2ada72 str r0, [sp] */
/* @0x2ada74 add.w r0, r4, #0x1e0 */
/* @0x2ada78 strb.w r3, [sp, #0x4] */
/* @0x2ada7c blx 0xb6c40 <memcmp@plt> */
/* @0x2ada80 cbz r0, 0x2ada8a <png_handle_unknown+0x56> */
/* @0x2ada82 orr r6, r6, #0x8 */
/* @0x2ada84 .word 0xf8c40608 */
/* @0x2ada86 str.w r6, [r4, #0x12c] */
/* @0x2ada88 .word 0xf894612c */
/* @0x2ada8a ldrb.w r3, [r4, #0x1e0] */
/* @0x2ada8c ldreq r3, [r9], r0, ror #3 */
/* @0x2ada8e lsls r1, r3, #0x1a */
/* @0x2ada90 bmi 0x2adab0 <png_handle_unknown+0x7c> */
/* @0x2ada92 mov r0, r4 */
/* @0x2ada94 add.w r1, r4, #0x1e0 */
/* @0x2ada98 bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2ada9c cmp r0, #0x3 */
/* @0x2ada9e beq 0x2adab0 <png_handle_unknown+0x7c> */
/* @0x2adaa0 ldr.w r3, [r4, #0x2c8] */
/* @0x2adaa4 cbnz r3, 0x2adab0 <png_handle_unknown+0x7c> */
/* @0x2adaa6 ldr r1, [pc, #0xc0] */
/* @0x2adaa8 mov r0, r4 */
/* @0x2adaaa add r1, pc */
/* @0x2adaac bl 0x2a64cc <png_chunk_error> */
/* @0x2adab0 ldr.w r3, [r4, #0x130] */
/* @0x2adab4 lsls r2, r3, #0x10 */
/* @0x2adab6 bmi 0x2adac0 <png_handle_unknown+0x8c> */
/* @0x2adab8 ldr.w r3, [r4, #0x2c8] */
/* @0x2adabc cmp r3, #0x0 */
/* @0x2adabe beq 0x2adb50 <png_handle_unknown+0x11c> */
/* @0x2adac0 add.w r8, r4, #0x1e0 */
/* @0x2adac4 ldr.w r3, [r8] */
/* @0x2adac8 add.w r6, r4, #0x314 */
/* @0x2adacc str.w r5, [r4, #0x320] */
/* @0x2adad0 str.w r3, [r4, #0x314] */
/* @0x2adad4 movs r3, #0x0 */
/* @0x2adad6 strb.w r3, [r4, #0x318] */
/* @0x2adad8 ldmdblt r5, {r3, r4, r8, r9, r12, sp} */
/* @0x2adada cbnz r5, 0x2adae2 <png_handle_unknown+0xae> */
/* @0x2adadc str.w r5, [r4, #0x31c] */
/* @0x2adae0 b 0x2adaf8 <png_handle_unknown+0xc4> */
/* @0x2adae2 mov r1, r5 */
/* @0x2adae4 mov r0, r4 */
/* @0x2adae6 bl 0x2a6ca0 <png_malloc> */
/* @0x2adae8 .word 0x462af8db */
/* @0x2adaea mov r2, r5 */
/* @0x2adaec mov r1, r0 */
/* @0x2adaee str.w r0, [r4, #0x31c] */
/* @0x2adaf0 qadd16mi r0, r0, r12 */
/* @0x2adaf2 mov r0, r4 */
/* @0x2adaf4 bl 0x2abc0c <png_crc_read> */
/* @0x2adaf8 ldr.w r3, [r4, #0x2c8] */
/* @0x2adafc mov r0, r4 */
/* @0x2adafe cbz r3, 0x2adb36 <png_handle_unknown+0x102> */
/* @0x2adb00 mov r1, r6 */
/* @0x2adb02 blx r3 */
/* @0x2adb04 cmp r0, #0x0 */
/* @0x2adb06 bge 0x2adb14 <png_handle_unknown+0xe0> */
/* @0x2adb08 ldr r1, [pc, #0x60] */
/* @0x2adb0a mov r0, r4 */
/* @0x2adb0c add r1, pc */
/* @0x2adb0e bl 0x2a64cc <png_chunk_error> */
/* @0x2adb10 ldrsb pc, [r5], -sp */
/* @0x2adb12 b 0x2adb40 <png_handle_unknown+0x10c> */
/* @0x2adb14 bne 0x2adb40 <png_handle_unknown+0x10c> */
/* @0x2adb16 ldrb.w r3, [r4, #0x1e0] */
/* @0x2adb18 ldreq r3, [r11], r0, ror #3 */
/* @0x2adb1a lsls r3, r3, #0x1a */
/* @0x2adb1c bmi 0x2adb34 <png_handle_unknown+0x100> */
/* @0x2adb1e mov r0, r4 */
/* @0x2adb20 mov r1, r8 */
/* @0x2adb22 bl 0x2a5fe4 <png_handle_as_unknown> */
/* @0x2adb24 stmdahs r3, {r0, r1, r2, r3, r4, r6, r9, r11, r12, sp, lr, pc} */
/* @0x2adb26 cmp r0, #0x3 */
/* @0x2adb28 beq 0x2adb34 <png_handle_unknown+0x100> */
/* @0x2adb2a ldr r1, [pc, #0x44] */
/* @0x2adb2c mov r0, r4 */
/* @0x2adb2e add r1, pc */
/* @0x2adb30 bl 0x2a64cc <png_chunk_error> */
/* @0x2adb34 mov r0, r4 */
/* @0x2adb36 mov r1, r7 */
/* @0x2adb38 mov r2, r6 */
/* @0x2adb3a movs r3, #0x1 */
/* @0x2adb3c bl 0x2af340 <png_set_unknown_chunks> */
/* @0x2adb40 mov r0, r4 */
/* @0x2adb42 ldr.w r1, [r4, #0x31c] */
/* @0x2adb44 .word 0xf7f9131c */
/* @0x2adb46 bl 0x2a6cfc <png_free> */
/* @0x2adb48 strhs pc, [r0, #-0x8d9] */
/* @0x2adb4a movs r5, #0x0 */
/* @0x2adb4c str.w r5, [r4, #0x31c] */
/* @0x2adb50 mov r0, r4 */
/* @0x2adb52 mov r1, r5 */
/* @0x2adb54 add sp, #0x8 */
/* @0x2adb56 pop.w {r4, r5, r6, r7, r8, lr} */
/* @0x2adb58 .word 0xf7fe41f0 */
/* @0x2adb5a b.w 0x2abc94 <png_crc_finish> */
/* @0x2adb5c svclt #0xb89b */
/* @0x2adb5e nop */
/* @0x2adb60 .word 0xff3e 000d */
/* @0x2adb64 subs r4, r7, #0x5 */
/* @0x2adb66 movs r6, r1 */
/* @0x2adb68 vhadd.u16 d0, d4, d13 */
/* @0x2adb6c cdp2 p0, #0xc, c0, c9, c13, #0x0 */
/* @0x2adb70 cdp2 p0, #0x9, c0, c0, c13, #0x0 */

/* ── FUNC 0x2adb74 · png_check_chunk_name · size=80 · insn=38 */
/* @0x2adb74 ldrb r3, [r1] */
/* @0x2adb76 sub.w r2, r3, #0x41 */
/* @0x2adb78 bhs 0x10ee484 <b2_toiTime+0x994fe0> */
/* @0x2adb7a cmp r2, #0x39 */
/* @0x2adb7c bhi 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adb7e subs r3, #0x5b */
/* @0x2adb80 cmp r3, #0x5 */
/* @0x2adb82 bls 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adb84 ldrb r3, [r1, #0x1] */
/* @0x2adb86 sub.w r2, r3, #0x41 */
/* @0x2adb88 bhs 0x10ee494 <b2_toiTime+0x994ff0> */
/* @0x2adb8a cmp r2, #0x39 */
/* @0x2adb8c bhi 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adb8e subs r3, #0x5b */
/* @0x2adb90 cmp r3, #0x5 */
/* @0x2adb92 bls 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adb94 ldrb r3, [r1, #0x2] */
/* @0x2adb96 sub.w r2, r3, #0x41 */
/* @0x2adb98 bhs 0x10ee4a4 <b2_toiTime+0x995000> */
/* @0x2adb9a cmp r2, #0x39 */
/* @0x2adb9c bhi 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adb9e subs r3, #0x5b */
/* @0x2adba0 cmp r3, #0x5 */
/* @0x2adba2 bls 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adba4 ldrb r3, [r1, #0x3] */
/* @0x2adba6 sub.w r2, r3, #0x41 */
/* @0x2adba8 bhs 0x10ee4b4 <b2_toiTime+0x995010> */
/* @0x2adbaa cmp r2, #0x39 */
/* @0x2adbac bhi 0x2adbb4 <png_check_chunk_name+0x40> */
/* @0x2adbae subs r3, #0x5b */
/* @0x2adbb0 cmp r3, #0x5 */
/* @0x2adbb2 bhi 0x2adbbc <png_check_chunk_name+0x48> */
/* @0x2adbb4 ldr r1, [pc, #0x8] */
/* @0x2adbb6 add r1, pc */
/* @0x2adbb8 b.w 0x2a64cc <png_chunk_error> */
/* @0x2adbbc bx lr */
/* @0x2adbbe nop */
/* @0x2adbc0 cdp2 p0, #0x3, c0, c3, c13, #0x0 */

/* ── FUNC 0x2adbc4 · png_read_chunk_header · size=108 · insn=45 */
/* @0x2adbc4 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2adbc8 add r6, sp, #0x4 */
/* @0x2adbca ldr r5, [pc, #0x60] */
/* @0x2adbcc mov r4, r0 */
/* @0x2adbce movs r2, #0x8 */
/* @0x2adbd0 mov r1, r6 */
/* @0x2adbd2 add r5, pc */
/* @0x2adbd4 ldr r5, [r5] */
/* @0x2adbd6 add.w r7, r4, #0x1e0 */
/* @0x2adbd8 stmdavs r11!, {r4, r5, r6, r7, r8, r9, r10, r12, sp, lr} */
/* @0x2adbda ldr r3, [r5] */
/* @0x2adbdc str r3, [sp, #0xc] */
/* @0x2adbde movs r3, #0x21 */
/* @0x2adbe0 str.w r3, [r0, #0x334] */
/* @0x2adbe4 bl 0x2a8030 <png_read_data> */
/* @0x2adbe8 mov r1, r6 */
/* @0x2adbea mov r0, r4 */
/* @0x2adbec bl 0x2abb6c <png_get_uint_31> */
/* @0x2adbf0 mov r8, r0 */
/* @0x2adbf2 ldr r0, [r6, #0x4] */
/* @0x2adbf4 str.w r0, [r4, #0x1e0] */
/* @0x2adbf8 mov r0, r4 */
/* @0x2adbfa bl 0x2a5af4 <png_reset_crc> */
/* @0x2adbfc andhs pc, r4, #492 */
/* @0x2adbfe movs r2, #0x4 */
/* @0x2adc00 mov r0, r4 */
/* @0x2adc02 mov r1, r7 */
/* @0x2adc04 bl 0x2a5b08 <png_calculate_crc> */
/* @0x2adc08 mov r0, r4 */
/* @0x2adc0a mov r1, r7 */
/* @0x2adc0c bl 0x2adb74 <png_check_chunk_name> */
/* @0x2adc10 movs r3, #0x41 */
/* @0x2adc12 ldr r2, [sp, #0xc] */
/* @0x2adc14 mov r0, r8 */
/* @0x2adc16 str.w r3, [r4, #0x334] */
/* @0x2adc18 stmdavs r11!, {r2, r4, r5, r8, r9, r12, sp} */
/* @0x2adc1a ldr r3, [r5] */
/* @0x2adc1c cmp r2, r3 */
/* @0x2adc1e beq 0x2adc24 <png_read_chunk_header+0x60> */
/* @0x2adc20 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2adc24 add sp, #0x10 */
/* @0x2adc26 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2adc28 svclt #0x81f0 */
/* @0x2adc2a nop */
/* @0x2adc2c stc2 p0, c0, [r2, #76] */

/* ── FUNC 0x2adc30 · png_combine_row · size=490 · insn=227 */
/* @0x2adc30 cmp r2, #0xff */
/* @0x2adc32 mov r3, r1 */
/* @0x2adc34 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2adc38 mov r5, r2 */
/* @0x2adc3a ldr.w r1, [r0, #0x1b0] */
/* @0x2adc3c .word 0xf89011b0 */
/* @0x2adc3e ldrb.w r2, [r0, #0x1cf] */
/* @0x2adc40 .word 0xf8d021cf */
/* @0x2adc42 ldr.w r4, [r0, #0x18c] */
/* @0x2adc44 smlabble pc, r12, r1, r4 */
/* @0x2adc46 bne 0x2adc68 <png_combine_row+0x38> */
/* @0x2adc48 cmp r2, #0x7 */
/* @0x2adc4a add.w r1, r1, #0x1 */
/* @0x2adc4c stmdble r2, {r0, r8} */
/* @0x2adc4e bls 0x2adc56 <png_combine_row+0x26> */
/* @0x2adc50 lsrs r2, r2, #0x3 */
/* @0x2adc52 muls r2, r4, r2 */
/* @0x2adc54 b 0x2adc5c <png_combine_row+0x2c> */
/* @0x2adc56 muls r2, r4, r2 */
/* @0x2adc58 adds r2, #0x7 */
/* @0x2adc5a lsrs r2, r2, #0x3 */
/* @0x2adc5c mov r0, r3 */
/* @0x2adc5e add sp, #0xc */
/* @0x2adc60 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2adc64 b.w 0x31bb0c <__udivdi3+0x474> */
/* @0x2adc68 cmp r2, #0x2 */
/* @0x2adc6a beq 0x2adcfa <png_combine_row+0xca> */
/* @0x2adc6c cmp r2, #0x4 */
/* @0x2adc6e beq.w 0x2add7a <png_combine_row+0x14a> */
/* @0x2adc70 bhs 0x30de88 <af_shaper_get_elem+0x36f6> */
/* @0x2adc72 cmp r2, #0x1 */
/* @0x2adc74 bne.w 0x2adde4 <png_combine_row+0x1b4> */
/* @0x2adc78 ldr.w r2, [r0, #0x134] */
/* @0x2adc7c adds r1, #0x1 */
/* @0x2adc7e movs r6, #0x0 */
/* @0x2adc80 movw r8, #0x7f7f */
/* @0x2adc84 and r2, r2, #0x10000 */
/* @0x2adc88 cmp r2, #0x0 */
/* @0x2adc8a ite eq */
/* @0x2adc8c moveq r7, #0x7 */
/* @0x2adc8e movne r7, #0x0 */
/* @0x2adc90 ite eq */
/* @0x2adc92 moveq.w r12, #0x0 */
/* @0x2adc94 .word 0xf04f0c00 */
/* @0x2adc96 movne.w r12, #0x7 */
/* @0x2adc98 svclt #0xc0c07 */
/* @0x2adc9a ite eq */
/* @0x2adc9c moveq.w r2, #0xffffffff */
/* @0x2adca0 movne r2, #0x1 */
/* @0x2adca2 str r2, [sp, #0x4] */
/* @0x2adca4 mov r0, r7 */
/* @0x2adca6 movs r2, #0x80 */
/* @0x2adca8 cmp r6, r4 */
/* @0x2adcaa beq.w 0x2ade14 <png_combine_row+0x1e4> */
/* @0x2adcac eormi r8, r10, #179 */
/* @0x2adcae tst r2, r5 */
/* @0x2adcb0 beq 0x2adcda <png_combine_row+0xaa> */
/* @0x2adcb2 ldrb.w r9, [r1] */
/* @0x2adcb4 .word 0xf1c09000 */
/* @0x2adcb6 rsb.w r11, r0, #0x7 */
/* @0x2adcb8 .word 0xf8930b07 */
/* @0x2adcba ldrb.w r10, [r3] */
/* @0x2adcbc blx 0x14d5cc4 <b2_toiTime+0xd7c820> */
/* @0x2adcbe asr.w r11, r8, r11 */
/* @0x2adcc0 blx 0x152c8f4 <b2_toiTime+0xdd3450> */
/* @0x2adcc2 asr.w r9, r9, r0 */
/* @0x2adcc4 b 0x5ac0cc <g_SWFlineaavertbuff+0x59004> */
/* @0x2adcc6 and.w r10, r11, r10 */
/* @0x2adcc8 .word 0xf0090a0a */
/* @0x2adcca and r9, r9, #0x1 */
/* @0x2adccc blx 0x4f00d8 <SrcVerts+0x4d11c> */
/* @0x2adcce lsl.w r9, r9, r0 */
/* @0x2adcd0 b 0x152c0d8 <b2_toiTime+0xdd2c34> */
/* @0x2adcd2 orr.w r9, r9, r10 */
/* @0x2adcd4 .word 0xf883090a */
/* @0x2adcd6 strb.w r9, [r3] */
/* @0x2adcd8 strbmi r9, [r0, #-0x0]! */
/* @0x2adcda cmp r0, r12 */
/* @0x2adcdc bne 0x2adce6 <png_combine_row+0xb6> */
/* @0x2adcde adds r1, #0x1 */
/* @0x2adce0 adds r3, #0x1 */
/* @0x2adce2 mov r0, r7 */
/* @0x2adce4 b 0x2adcec <png_combine_row+0xbc> */
/* @0x2adce6 ldr.w r9, [sp, #0x4] */
/* @0x2adce8 strbmi r9, [r8], #-4 */
/* @0x2adcea add r0, r9 */
/* @0x2adcec cmp r2, #0x1 */
/* @0x2adcee add.w r6, r6, #0x1 */
/* @0x2adcf0 svclt #0x140601 */
/* @0x2adcf2 ite ne */
/* @0x2adcf4 asrne r2, r2, #0x1 */
/* @0x2adcf6 moveq r2, #0x80 */
/* @0x2adcf8 b 0x2adca8 <png_combine_row+0x78> */
/* @0x2adcfa ldr.w r2, [r0, #0x134] */
/* @0x2adcfc .word 0x31012134 */
/* @0x2adcfe adds r1, #0x1 */
/* @0x2add00 movs r6, #0x0 */
/* @0x2add02 movs r0, #0x80 */
/* @0x2add04 and r2, r2, #0x10000 */
/* @0x2add08 movw r8, #0x3f3f */
/* @0x2add0c cmp r2, #0x0 */
/* @0x2add0e ite eq */
/* @0x2add10 moveq r7, #0x6 */
/* @0x2add12 movne r7, #0x0 */
/* @0x2add14 ite eq */
/* @0x2add16 mvneq r12, #0x1 */
/* @0x2add18 .word 0xf04f0c01 */
/* @0x2add1a movne.w r12, #0x2 */
/* @0x2add1c svclt #0xc0c02 */
/* @0x2add1e ite eq */
/* @0x2add20 moveq.w r10, #0x0 */
/* @0x2add24 movne.w r10, #0x6 */
/* @0x2add28 str.w r10, [sp, #0x4] */
/* @0x2add2c mov r2, r7 */
/* @0x2add2e cmp r6, r4 */
/* @0x2add30 beq 0x2ade14 <png_combine_row+0x1e4> */
/* @0x2add32 tst r0, r5 */
/* @0x2add34 beq 0x2add5e <png_combine_row+0x12e> */
/* @0x2add36 ldrb.w r9, [r1] */
/* @0x2add38 .word 0xf1c29000 */
/* @0x2add3a rsb.w r11, r2, #0x6 */
/* @0x2add3c .word 0xf8930b06 */
/* @0x2add3e ldrb.w r10, [r3] */
/* @0x2add40 blx 0x14d5d48 <b2_toiTime+0xd7c8a4> */
/* @0x2add42 asr.w r11, r8, r11 */
/* @0x2add44 blx 0x152c978 <b2_toiTime+0xdd34d4> */
/* @0x2add46 asr.w r9, r9, r2 */
/* @0x2add48 b 0x5ac158 <g_SWFlineaavertbuff+0x59090> */
/* @0x2add4a and.w r10, r11, r10 */
/* @0x2add4c .word 0xf0090a0a */
/* @0x2add4e and r9, r9, #0x3 */
/* @0x2add50 blx 0x4f0164 <SrcVerts+0x4d1a8> */
/* @0x2add52 lsl.w r9, r9, r2 */
/* @0x2add54 b 0x152c164 <b2_toiTime+0xdd2cc0> */
/* @0x2add56 orr.w r9, r9, r10 */
/* @0x2add58 .word 0xf883090a */
/* @0x2add5a strb.w r9, [r3] */
/* @0x2add5c .word 0xf8dd9000 */
/* @0x2add5e ldr.w r9, [sp, #0x4] */
/* @0x2add60 strlo r9, [r1], -r4 */
/* @0x2add62 adds r6, #0x1 */
/* @0x2add64 cmp r2, r9 */
/* @0x2add66 ittte eq */
/* @0x2add68 addeq r1, #0x1 */
/* @0x2add6a addeq r3, #0x1 */
/* @0x2add6c moveq r2, r7 */
/* @0x2add6e addne r2, r12 */
/* @0x2add70 cmp r0, #0x1 */
/* @0x2add72 ite ne */
/* @0x2add74 asrne r0, r0, #0x1 */
/* @0x2add76 moveq r0, #0x80 */
/* @0x2add78 b 0x2add2e <png_combine_row+0xfe> */
/* @0x2add7a ldr.w r0, [r0, #0x134] */
/* @0x2add7c .word 0x31010134 */
/* @0x2add7e adds r1, #0x1 */
/* @0x2add80 movs r7, #0x0 */
/* @0x2add82 movs r6, #0x80 */
/* @0x2add84 ands r8, r0, #0x10000 */
/* @0x2add88 ittte ne */
/* @0x2add8a movne r12, r2 */
/* @0x2add8c movne r2, #0x0 */
/* @0x2add8e movne r8, r12 */
/* @0x2add90 mvneq r12, #0x3 */
/* @0x2add94 mov r0, r2 */
/* @0x2add96 cmp r7, r4 */
/* @0x2add98 beq 0x2ade14 <png_combine_row+0x1e4> */
/* @0x2add9a tst r6, r5 */
/* @0x2add9c beq 0x2addca <png_combine_row+0x19a> */
/* @0x2add9e ldrb.w r9, [r1] */
/* @0x2adda0 .word 0xf6409000 */
/* @0x2adda2 movw r10, #0xf0f */
/* @0x2adda4 .word 0xf1c07a0f */
/* @0x2adda6 rsb.w r11, r0, #0x4 */
/* @0x2adda8 blx 0x15309c0 <b2_toiTime+0xdd751c> */
/* @0x2addaa asr.w r11, r10, r11 */
/* @0x2addac .word 0xf893fb0b */
/* @0x2addae ldrb.w r10, [r3] */
/* @0x2addb0 blx 0x1515db8 <b2_toiTime+0xdbc914> */
/* @0x2addb2 asr.w r9, r9, r0 */
/* @0x2addb4 .word 0xf009f900 */
/* @0x2addb6 and r9, r9, #0xf */
/* @0x2addb8 b 0x5701fc <g_SWFlineaavertbuff+0x1d134> */
/* @0x2addba and.w r10, r11, r10 */
/* @0x2addbc blx 0x4f05ec <SrcVerts+0x4d630> */
/* @0x2addbe lsl.w r9, r9, r0 */
/* @0x2addc0 b 0x152c1c8 <b2_toiTime+0xdd2d24> */
/* @0x2addc2 orr.w r9, r9, r10 */
/* @0x2addc4 .word 0xf883090a */
/* @0x2addc6 strb.w r9, [r3] */
/* @0x2addc8 strbmi r9, [r0, #-0x0] */
/* @0x2addca cmp r0, r8 */
/* @0x2addcc add.w r7, r7, #0x1 */
/* @0x2addd0 ittte eq */
/* @0x2addd2 addeq r1, #0x1 */
/* @0x2addd4 addeq r3, #0x1 */
/* @0x2addd6 moveq r0, r2 */
/* @0x2addd8 addne r0, r12 */
/* @0x2addda cmp r6, #0x1 */
/* @0x2adddc ite ne */
/* @0x2addde asrne r6, r6, #0x1 */
/* @0x2adde0 moveq r6, #0x80 */
/* @0x2adde2 b 0x2add96 <png_combine_row+0x166> */
/* @0x2adde4 add.w r8, r1, #0x1 */
/* @0x2adde8 lsr.w r9, r2, #0x3 */
/* @0x2addec movs r6, #0x80 */
/* @0x2addee movs r7, #0x0 */
/* @0x2addf0 cmp r7, r4 */
/* @0x2addf2 beq 0x2ade14 <png_combine_row+0x1e4> */
/* @0x2addf4 tst r6, r5 */
/* @0x2addf6 beq 0x2ade04 <png_combine_row+0x1d4> */
/* @0x2addf8 mov r0, r3 */
/* @0x2addfa mov r1, r8 */
/* @0x2addfc mov r2, r9 */
/* @0x2addfe blx 0xb65bc <memcpy@plt> */
/* @0x2ade00 .word 0x4603ebde */
/* @0x2ade02 mov r3, r0 */
/* @0x2ade04 cmp r6, #0x1 */
/* @0x2ade06 add r8, r9 */
/* @0x2ade08 add r3, r9 */
/* @0x2ade0a ite ne */
/* @0x2ade0c lsrne r6, r6, #0x1 */
/* @0x2ade0e moveq r6, #0x80 */
/* @0x2ade10 adds r7, #0x1 */
/* @0x2ade12 b 0x2addf0 <png_combine_row+0x1c0> */
/* @0x2ade14 add sp, #0xc */
/* @0x2ade16 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ade18 strdeq r8, r9, [r0], -r0 */

/* ── FUNC 0x2ade1c · png_do_read_interlace · size=812 · insn=323 */
/* @0x2ade1c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ade20 sub sp, #0x3c */
/* @0x2ade22 ldr.w r10, [pc, #0x31c] */
/* @0x2ade24 .word 0x4604a31c */
/* @0x2ade26 mov r4, r0 */
/* @0x2ade28 ldr.w r12, [pc, #0x318] */
/* @0x2ade2c add.w r9, r0, #0x1c4 */
/* @0x2ade30 add r10, pc */
/* @0x2ade32 ldr.w r10, [r10] */
/* @0x2ade34 .word 0xf8d0a000 */
/* @0x2ade36 ldr.w r6, [r0, #0x1b0] */
/* @0x2ade38 ldrbtmi r6, [r12], #432 */
/* @0x2ade3a add r12, pc */
/* @0x2ade3c ldrb.w r8, [r0, #0x1e8] */
/* @0x2ade40 ldr.w r3, [r10] */
/* @0x2ade44 add.w r12, r12, #0x8 */
/* @0x2ade48 ldr.w r7, [r0, #0x134] */
/* @0x2ade4c add r5, sp, #0x10 */
/* @0x2ade4e adds r6, #0x1 */
/* @0x2ade50 str.w r10, [sp, #0xc] */
/* @0x2ade54 str r3, [sp, #0x34] */
/* @0x2ade56 ldm.w r12!, {r0, r1, r2, r3} */
/* @0x2ade58 strgt r0, [pc, #-0xf] */
/* @0x2ade5a stm r5!, {r0, r1, r2, r3} */
/* @0x2ade5c ldm.w r12, {r0, r1, r2} */
/* @0x2ade60 stm.w r5, {r0, r1, r2} */
/* @0x2ade64 beq.w 0x2ae12c <png_do_read_interlace+0x310> */
/* @0x2ade68 cmp.w r9, #0x0 */
/* @0x2ade6c beq.w 0x2ae12c <png_do_read_interlace+0x310> */
/* @0x2ade70 add r1, sp, #0x38 */
/* @0x2ade72 ldr.w r2, [r4, #0x1c4] */
/* @0x2ade74 bl 0x2f658c <ps_hints_apply+0x518c> */
/* @0x2ade76 add.w r3, r1, r8, lsl #2 */
/* @0x2ade78 .word 0xf8940388 */
/* @0x2ade7a ldrb.w r8, [r4, #0x1cf] */
/* @0x2ade7c cdpne p1, #0x5, c8, c1, c15, #0x6 */
/* @0x2ade7e subs r1, r2, #0x1 */
/* @0x2ade80 ldr r3, [r3, #-40] */
/* @0x2ade84 cmp.w r8, #0x2 */
/* @0x2ade88 mul r5, r2, r3 */
/* @0x2ade8c str r3, [sp, #0x8] */
/* @0x2ade8e add.w r0, r5, #0xffffffff */
/* @0x2ade90 .word 0xd06930ff */
/* @0x2ade92 beq 0x2adf68 <png_do_read_interlace+0x14c> */
/* @0x2ade94 cmp.w r8, #0x4 */
/* @0x2ade98 beq.w 0x2ae01a <png_do_read_interlace+0x1fe> */
/* @0x2ade9c cmp.w r8, #0x1 */
/* @0x2adea0 bne.w 0x2ae0d6 <png_do_read_interlace+0x2ba> */
/* @0x2adea4 ands r12, r7, #0x10000 */
/* @0x2adea8 add.w r1, r6, r1, lsr #3 */
/* @0x2adeac add.w r0, r6, r0, lsr #3 */
/* @0x2adeb0 add.w r3, r5, #0x7 */
/* @0x2adeb4 add.w r6, r2, #0x7 */
/* @0x2adeb8 beq 0x2aded0 <png_do_read_interlace+0xb4> */
/* @0x2adeba movs r2, #0x0 */
/* @0x2adebc and r6, r6, #0x7 */
/* @0x2adec0 and r3, r3, #0x7 */
/* @0x2adec4 mov.w r8, #0xffffffff */
/* @0x2adec8 str r2, [sp] */
/* @0x2adeca mov.w r12, #0x7 */
/* @0x2adecc and r0, r9, r7, lsl #24 */
/* @0x2adece b 0x2adee4 <png_do_read_interlace+0xc8> */
/* @0x2aded0 mvns r6, r6 */
/* @0x2aded2 mvns r3, r3 */
/* @0x2aded4 and r6, r6, #0x7 */
/* @0x2aded8 and r3, r3, #0x7 */
/* @0x2adedc mov.w r10, #0x7 */
/* @0x2adee0 str.w r10, [sp] */
/* @0x2adee4 movs r7, #0x0 */
/* @0x2adee6 ldr.w r2, [r4, #0x1c4] */
/* @0x2adee8 addsmi r2, r7, #196, #2 */
/* @0x2adeea cmp r7, r2 */
/* @0x2adeec bhs 0x2adf54 <png_do_read_interlace+0x138> */
/* @0x2adeee ldrb.w r9, [r1] */
/* @0x2adef0 blx 0x1511ef8 <b2_toiTime+0xdb8a54> */
/* @0x2adef2 asr.w r9, r9, r6 */
/* @0x2adef4 .word 0xf009f906 */
/* @0x2adef6 and r9, r9, #0x1 */
/* @0x2adef8 .word 0xf8cd0901 */
/* @0x2adefa str.w r9, [sp, #0x4] */
/* @0x2adefc .word 0xf04f9004 */
/* @0x2adefe mov.w r9, #0x0 */
/* @0x2adf00 bls 0x330308 */
/* @0x2adf02 ldr r2, [sp, #0x8] */
/* @0x2adf04 cmp r9, r2 */
/* @0x2adf06 bge 0x2adf40 <png_do_read_interlace+0x124> */
/* @0x2adf08 ldrb.w r10, [r0] */
/* @0x2adf0c rsb.w r11, r3, #0x7 */
/* @0x2adf10 movw r2, #0x7f7f */
/* @0x2adf14 add.w r9, r9, #0x1 */
/* @0x2adf18 asr.w r11, r2, r11 */
/* @0x2adf1c and.w r2, r11, r10 */
/* @0x2adf20 ldr.w r11, [sp, #0x4] */
/* @0x2adf24 lsl.w r10, r11, r3 */
/* @0x2adf28 orr.w r10, r2, r10 */
/* @0x2adf2c ldr r2, [sp] */
/* @0x2adf2e strb.w r10, [r0] */
/* @0x2adf30 addsmi r10, r3, #0 */
/* @0x2adf32 cmp r3, r2 */
/* @0x2adf34 itet eq */
/* @0x2adf36 addeq.w r0, r0, #0xffffffff */
/* @0x2adf38 strbmi r3, [r3], #-255 */
/* @0x2adf3a addne r3, r8 */
/* @0x2adf3c moveq r3, r12 */
/* @0x2adf3e b 0x2adf02 <png_do_read_interlace+0xe6> */
/* @0x2adf40 ldr.w r10, [sp] */
/* @0x2adf44 adds r7, #0x1 */
/* @0x2adf46 cmp r6, r10 */
/* @0x2adf48 itet eq */
/* @0x2adf4a addeq.w r1, r1, #0xffffffff */
/* @0x2adf4c strbmi r3, [r6], #-511 */
/* @0x2adf4e addne r6, r8 */
/* @0x2adf50 moveq r6, r12 */
/* @0x2adf52 b 0x2adee6 <png_do_read_interlace+0xca> */
/* @0x2adf54 ldrb.w r3, [r4, #0x1cf] */
/* @0x2adf58 str.w r5, [r4, #0x1c4] */
/* @0x2adf5c cmp r3, #0x7 */
/* @0x2adf5e bls.w 0x2ae122 <png_do_read_interlace+0x306> */
/* @0x2adf60 ldmeq r11, {r5, r6, r7, pc} ^ */
/* @0x2adf62 lsrs r3, r3, #0x3 */
/* @0x2adf64 muls r5, r3, r5 */
/* @0x2adf66 b 0x2ae128 <png_do_read_interlace+0x30c> */
/* @0x2adf68 ands r12, r7, #0x10000 */
/* @0x2adf6c add.w r1, r6, r1, lsr #2 */
/* @0x2adf70 add.w r0, r6, r0, lsr #2 */
/* @0x2adf74 str r1, [sp] */
/* @0x2adf76 add.w r2, r2, #0x3 */
/* @0x2adf78 .word 0xf1050203 */
/* @0x2adf7a add.w r3, r5, #0x3 */
/* @0x2adf7c andle r0, r12, r3, lsl #6 */
/* @0x2adf7e beq 0x2adf9a <png_do_read_interlace+0x17e> */
/* @0x2adf80 and r2, r2, #0x3 */
/* @0x2adf84 and r3, r3, #0x3 */
/* @0x2adf88 mvn r8, #0x1 */
/* @0x2adf8c mov.w r9, #0x0 */
/* @0x2adf90 lsls r6, r2, #0x1 */
/* @0x2adf92 lsls r3, r3, #0x1 */
/* @0x2adf94 mov.w r12, #0x6 */
/* @0x2adf98 b 0x2adfae <png_do_read_interlace+0x192> */
/* @0x2adf9a mvns r2, r2 */
/* @0x2adf9c mvns r3, r3 */
/* @0x2adf9e and r6, r2, #0x3 */
/* @0x2adfa0 .word 0xf0030603 */
/* @0x2adfa2 and r3, r3, #0x3 */
/* @0x2adfa4 .word 0xf04f0303 */
/* @0x2adfa6 mov.w r9, #0x6 */
/* @0x2adfa8 rsbseq r0, r6, r6, lsl #18 */
/* @0x2adfaa lsls r6, r6, #0x1 */
/* @0x2adfac lsls r3, r3, #0x1 */
/* @0x2adfae movs r7, #0x0 */
/* @0x2adfb0 ldr.w r2, [r4, #0x1c4] */
/* @0x2adfb4 cmp r7, r2 */
/* @0x2adfb6 bhs 0x2adf54 <png_do_read_interlace+0x138> */
/* @0x2adfb8 ldr r1, [sp] */
/* @0x2adfba ldrb r2, [r1] */
/* @0x2adfbc asrs r2, r6 */
/* @0x2adfbe and r2, r2, #0x3 */
/* @0x2adfc0 andls r0, r1, #805306368 */
/* @0x2adfc2 str r2, [sp, #0x4] */
/* @0x2adfc4 movs r2, #0x0 */
/* @0x2adfc6 ldr r1, [sp, #0x8] */
/* @0x2adfc8 cmp r2, r1 */
/* @0x2adfca bge 0x2ae006 <png_do_read_interlace+0x1ea> */
/* @0x2adfcc rsb.w r11, r3, #0x6 */
/* @0x2adfd0 movw r10, #0x3f3f */
/* @0x2adfd4 asr.w r11, r10, r11 */
/* @0x2adfd8 ldrb.w r10, [r0] */
/* @0x2adfdc cmp r3, r9 */
/* @0x2adfde add.w r2, r2, #0x1 */
/* @0x2adfe0 b 0x56e7ec <g_SWFlineaavertbuff+0x1b724> */
/* @0x2adfe2 and.w r1, r11, r10 */
/* @0x2adfe4 .word 0xf8dd010a */
/* @0x2adfe6 ldr.w r11, [sp, #0x4] */
/* @0x2adfe8 blx 0x59a000 <g_SWFlineaavertbuff+0x46f38> */
/* @0x2adfea lsl.w r10, r11, r3 */
/* @0x2adfec svclt #0x8fa03 */
/* @0x2adfee it eq */
/* @0x2adff0 moveq r3, r12 */
/* @0x2adff2 orr.w r10, r1, r10 */
/* @0x2adff4 svclt #0x180a0a */
/* @0x2adff6 it ne */
/* @0x2adff8 addne r3, r8 */
/* @0x2adffa strb.w r10, [r0] */
/* @0x2adffc svclt #0x8a000 */
/* @0x2adffe it eq */
/* @0x2ae000 addeq.w r0, r0, #0xffffffff */
/* @0x2ae004 b 0x2adfc6 <png_do_read_interlace+0x1aa> */
/* @0x2ae006 cmp r6, r9 */
/* @0x2ae008 bne 0x2ae014 <png_do_read_interlace+0x1f8> */
/* @0x2ae00a ldr r2, [sp] */
/* @0x2ae00c mov r6, r12 */
/* @0x2ae00e subs r2, #0x1 */
/* @0x2ae010 str r2, [sp] */
/* @0x2ae012 b 0x2ae016 <png_do_read_interlace+0x1fa> */
/* @0x2ae014 add r6, r8 */
/* @0x2ae016 adds r7, #0x1 */
/* @0x2ae018 b 0x2adfb0 <png_do_read_interlace+0x194> */
/* @0x2ae01a ands r7, r7, #0x10000 */
/* @0x2ae01c bl 0x43be24 <g_RomDisk+0x44604> */
/* @0x2ae01e add.w r1, r6, r1, lsr #1 */
/* @0x2ae020 bl 0x42e56c <g_RomDisk+0x36d4c> */
/* @0x2ae022 add.w r0, r6, r0, lsr #1 */
/* @0x2ae024 qaddls r0, r0, r0 */
/* @0x2ae026 str r1, [sp] */
/* @0x2ae028 add.w r2, r2, #0x1 */
/* @0x2ae02c add.w r3, r5, #0x1 */
/* @0x2ae030 beq 0x2ae048 <png_do_read_interlace+0x22c> */
/* @0x2ae032 and r2, r2, #0x1 */
/* @0x2ae034 .word 0xf0030201 */
/* @0x2ae036 and r3, r3, #0x1 */
/* @0x2ae038 .word 0xf04f0301 */
/* @0x2ae03a mov.w r9, #0x0 */
/* @0x2ae03c addseq r0, r6, r0, lsl #18 */
/* @0x2ae03e lsls r6, r2, #0x2 */
/* @0x2ae040 lsls r3, r3, #0x2 */
/* @0x2ae042 mvn r2, #0x3 */
/* @0x2ae044 and r0, sp, r3, lsl #4 */
/* @0x2ae046 b 0x2ae064 <png_do_read_interlace+0x248> */
/* @0x2ae048 tst.w r2, #0x1 */
/* @0x2ae04c mov r9, r8 */
/* @0x2ae04e ite ne */
/* @0x2ae050 movne r6, #0x0 */
/* @0x2ae052 moveq r6, #0x4 */
/* @0x2ae054 ands r3, r3, #0x1 */
/* @0x2ae058 mov r2, r8 */
/* @0x2ae05a itete ne */
/* @0x2ae05c movne r8, r7 */
/* @0x2ae05e moveq r8, r3 */
/* @0x2ae060 movne r3, r8 */
/* @0x2ae062 moveq r3, r2 */
/* @0x2ae064 mov.w r12, #0x0 */
/* @0x2ae068 ldr.w r7, [r4, #0x1c4] */
/* @0x2ae06c cmp r12, r7 */
/* @0x2ae06e bhs.w 0x2adf54 <png_do_read_interlace+0x138> */
/* @0x2ae070 stmdbls r0, {r0, r4, r5, r6, r8, r9, r10, r11, sp, pc} */
/* @0x2ae072 ldr r1, [sp] */
/* @0x2ae074 ldrb r7, [r1] */
/* @0x2ae076 asrs r7, r6 */
/* @0x2ae078 and r7, r7, #0xf */
/* @0x2ae07c str r7, [sp, #0x4] */
/* @0x2ae07e movs r7, #0x0 */
/* @0x2ae080 ldr r1, [sp, #0x8] */
/* @0x2ae082 cmp r7, r1 */
/* @0x2ae084 bge 0x2ae0c0 <png_do_read_interlace+0x2a4> */
/* @0x2ae086 rsb.w r11, r3, #0x4 */
/* @0x2ae088 .word 0xf6400b04 */
/* @0x2ae08a movw r10, #0xf0f */
/* @0x2ae08c blx 0x154c8d0 <b2_toiTime+0xdf342c> */
/* @0x2ae08e asr.w r11, r10, r11 */
/* @0x2ae090 .word 0xf890fb0b */
/* @0x2ae092 ldrb.w r10, [r0] */
/* @0x2ae094 strbmi r10, [r11, #-0x0] */
/* @0x2ae096 cmp r3, r9 */
/* @0x2ae098 add.w r7, r7, #0x1 */
/* @0x2ae09c and.w r1, r11, r10 */
/* @0x2ae0a0 ldr.w r11, [sp, #0x4] */
/* @0x2ae0a4 lsl.w r10, r11, r3 */
/* @0x2ae0a8 it eq */
/* @0x2ae0aa moveq r3, r8 */
/* @0x2ae0ac orr.w r10, r1, r10 */
/* @0x2ae0b0 it ne */
/* @0x2ae0b2 addne r3, r3, r2 */
/* @0x2ae0b4 strb.w r10, [r0] */
/* @0x2ae0b8 it eq */
/* @0x2ae0ba addeq.w r0, r0, #0xffffffff */
/* @0x2ae0bc .word 0xe7df30ff */
/* @0x2ae0be b 0x2ae080 <png_do_read_interlace+0x264> */
/* @0x2ae0c0 cmp r6, r9 */
/* @0x2ae0c2 bne 0x2ae0ce <png_do_read_interlace+0x2b2> */
/* @0x2ae0c4 ldr r1, [sp] */
/* @0x2ae0c6 mov r6, r8 */
/* @0x2ae0c8 subs r1, #0x1 */
/* @0x2ae0ca str r1, [sp] */
/* @0x2ae0cc b 0x2ae0d0 <png_do_read_interlace+0x2b4> */
/* @0x2ae0ce add r6, r2 */
/* @0x2ae0d0 add.w r12, r12, #0x1 */
/* @0x2ae0d4 b 0x2ae068 <png_do_read_interlace+0x24c> */
/* @0x2ae0d6 lsr.w r8, r8, #0x3 */
/* @0x2ae0d8 .word 0xf10d08d8 */
/* @0x2ae0da add.w r10, sp, #0x2c */
/* @0x2ae0dc strhs r0, [r0, -r12, lsr #20] */
/* @0x2ae0de movs r7, #0x0 */
/* @0x2ae0e0 mla r9, r1, r8, r6 */
/* @0x2ae0e4 mla r6, r8, r0, r6 */
/* @0x2ae0e8 ldr.w r3, [r4, #0x1c4] */
/* @0x2ae0ec cmp r7, r3 */
/* @0x2ae0ee bhs.w 0x2adf54 <png_do_read_interlace+0x138> */
/* @0x2ae0f0 uasxmi r10, r0, r1 */
/* @0x2ae0f2 mov r0, r10 */
/* @0x2ae0f4 mov r1, r9 */
/* @0x2ae0f6 mov r2, r8 */
/* @0x2ae0f8 mov.w r11, #0x0 */
/* @0x2ae0fc blx 0xb65bc <memcpy@plt> */
/* @0x2ae100 ldr r3, [sp, #0x8] */
/* @0x2ae102 cmp r11, r3 */
/* @0x2ae104 bge 0x2ae11a <png_do_read_interlace+0x2fe> */
/* @0x2ae106 mov r0, r6 */
/* @0x2ae108 mov r1, r10 */
/* @0x2ae10a mov r2, r8 */
/* @0x2ae10c rsb r6, r8, r6 */
/* @0x2ae110 blx 0xb65bc <memcpy@plt> */
/* @0x2ae114 add.w r11, r11, #0x1 */
/* @0x2ae118 b 0x2ae100 <png_do_read_interlace+0x2e4> */
/* @0x2ae11a rsb r9, r8, r9 */
/* @0x2ae11c strlo r0, [r1, -r9, lsl #18] */
/* @0x2ae11e adds r7, #0x1 */
/* @0x2ae120 b 0x2ae0e8 <png_do_read_interlace+0x2cc> */
/* @0x2ae122 muls r5, r3, r5 */
/* @0x2ae124 adds r5, #0x7 */
/* @0x2ae126 lsrs r5, r5, #0x3 */
/* @0x2ae128 str.w r5, [r4, #0x1c8] */
/* @0x2ae12c ldr r1, [sp, #0xc] */
/* @0x2ae12e ldr r2, [sp, #0x34] */
/* @0x2ae130 ldr r3, [r1] */
/* @0x2ae132 cmp r2, r3 */
/* @0x2ae134 beq 0x2ae13a <png_do_read_interlace+0x31e> */
/* @0x2ae136 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2ae138 andlt lr, pc, lr, asr #20 */
/* @0x2ae13a add sp, #0x3c */
/* @0x2ae13c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae140 smladx r0, r4, r3, r0 */
/* @0x2ae144 subs r6, r5, r6 */
/* @0x2ae146 movs r6, r1 */

/* ── FUNC 0x2ae148 · png_read_filter_row · size=276 · insn=127 */
/* @0x2ae148 push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ae14c mov r4, r2 */
/* @0x2ae14e ldr r2, [sp, #0x28] */
/* @0x2ae150 cmp r2, #0x4 */
/* @0x2ae152 bhi 0x2ae246 <png_read_filter_row+0xfe> */
/* @0x2ae154 tbb [pc, r2] */
/* @0x2ae158 lsls r5, r7, #0xd */
/* @0x2ae15a movs r1, #0x15 */
/* @0x2ae15c lsls r0, r0, #0x1 */
/* @0x2ae15e ldrb r3, [r1, #0xb] */
/* @0x2ae160 ldr r0, [r1, #0x4] */
/* @0x2ae162 adds r3, #0x7 */
/* @0x2ae164 asrs r3, r3, #0x3 */
/* @0x2ae166 adds r2, r4, r3 */
/* @0x2ae168 rsbs r1, r3, #0 */
/* @0x2ae16a add r2, r1 */
/* @0x2ae16c add r4, r1 */
/* @0x2ae16e cmp r3, r0 */
/* @0x2ae170 bhs 0x2ae17e <png_read_filter_row+0x36> */
/* @0x2ae172 ldrb r5, [r4, r3] */
/* @0x2ae174 ldrb r1, [r2, r3] */
/* @0x2ae176 add r1, r5 */
/* @0x2ae178 strb r1, [r2, r3] */
/* @0x2ae17a adds r3, #0x1 */
/* @0x2ae17c b 0x2ae16e <png_read_filter_row+0x26> */
/* @0x2ae17e pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae180 stmdavs r9, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^ */
/* @0x2ae182 ldr r1, [r1, #0x4] */
/* @0x2ae184 movs r2, #0x0 */
/* @0x2ae186 cmp r2, r1 */
/* @0x2ae188 beq 0x2ae196 <png_read_filter_row+0x4e> */
/* @0x2ae18a ldrb r5, [r3, r2] */
/* @0x2ae18c ldrb r0, [r4, r2] */
/* @0x2ae18e add r0, r5 */
/* @0x2ae190 strb r0, [r4, r2] */
/* @0x2ae192 adds r2, #0x1 */
/* @0x2ae194 b 0x2ae186 <png_read_filter_row+0x3e> */
/* @0x2ae196 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae198 bvc 0xff4d2180 <b2_toiTime+0xfffffffffed78cdc> */
/* @0x2ae19a ldrb r0, [r1, #0xb] */
/* @0x2ae19c movs r2, #0x0 */
/* @0x2ae19e ldr r5, [r1, #0x4] */
/* @0x2ae1a0 adds r0, #0x7 */
/* @0x2ae1a2 asrs r0, r0, #0x3 */
/* @0x2ae1a4 subs r5, r5, r0 */
/* @0x2ae1a6 cmp r2, r0 */
/* @0x2ae1a8 beq 0x2ae1b8 <png_read_filter_row+0x70> */
/* @0x2ae1aa ldrb r6, [r3, r2] */
/* @0x2ae1ac ldrb r1, [r4, r2] */
/* @0x2ae1ae add.w r1, r1, r6, lsr #1 */
/* @0x2ae1b0 strtpl r0, [r1], #342 */
/* @0x2ae1b2 strb r1, [r4, r2] */
/* @0x2ae1b4 adds r2, #0x1 */
/* @0x2ae1b6 b 0x2ae1a6 <png_read_filter_row+0x5e> */
/* @0x2ae1b8 adds r0, r4, r2 */
/* @0x2ae1ba add r2, r3 */
/* @0x2ae1bc movs r1, #0x0 */
/* @0x2ae1be cmp r1, r5 */
/* @0x2ae1c0 beq 0x2ae1d4 <png_read_filter_row+0x8c> */
/* @0x2ae1c2 ldrb r6, [r2, r1] */
/* @0x2ae1c4 ldrb r3, [r4, r1] */
/* @0x2ae1c6 add r3, r6 */
/* @0x2ae1c8 ldrb r6, [r0, r1] */
/* @0x2ae1ca add.w r3, r6, r3, lsr #1 */
/* @0x2ae1cc strbpl r0, [r3], #-851 */
/* @0x2ae1ce strb r3, [r0, r1] */
/* @0x2ae1d0 adds r1, #0x1 */
/* @0x2ae1d2 b 0x2ae1be <png_read_filter_row+0x76> */
/* @0x2ae1d4 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae1d8 ldrb r0, [r1, #0xb] */
/* @0x2ae1da ldr r2, [r1, #0x4] */
/* @0x2ae1dc adds r0, #0x7 */
/* @0x2ae1de asrs r0, r0, #0x3 */
/* @0x2ae1e0 rsb r9, r0, r2 */
/* @0x2ae1e4 movs r2, #0x0 */
/* @0x2ae1e6 cmp r2, r0 */
/* @0x2ae1e8 beq 0x2ae1f6 <png_read_filter_row+0xae> */
/* @0x2ae1ea ldrb r5, [r3, r2] */
/* @0x2ae1ec ldrb r1, [r4, r2] */
/* @0x2ae1ee add r1, r5 */
/* @0x2ae1f0 strb r1, [r4, r2] */
/* @0x2ae1f2 adds r2, #0x1 */
/* @0x2ae1f4 b 0x2ae1e6 <png_read_filter_row+0x9e> */
/* @0x2ae1f6 adds r5, r4, r2 */
/* @0x2ae1f8 add.w r10, r3, r2 */
/* @0x2ae1fc movs r2, #0x0 */
/* @0x2ae1fe cmp r2, r9 */
/* @0x2ae200 beq 0x2ae242 <png_read_filter_row+0xfa> */
/* @0x2ae202 ldrb r0, [r3, r2] */
/* @0x2ae204 ldrb r1, [r4, r2] */
/* @0x2ae206 ldrb.w r6, [r10, r2] */
/* @0x2ae208 bne 0x686218 <g_SWFlinevertbuff+0x33150> */
/* @0x2ae20a subs r7, r1, r0 */
/* @0x2ae20c rsb r11, r0, r6 */
/* @0x2ae210 eor.w r12, r7, r7, asr #31 */
/* @0x2ae214 sub.w r12, r12, r7, asr #31 */
/* @0x2ae218 eor.w r8, r11, r11, asr #31 */
/* @0x2ae21c sub.w r8, r8, r11, asr #31 */
/* @0x2ae220 add r7, r11 */
/* @0x2ae222 cmp r7, #0x0 */
/* @0x2ae224 it lt */
/* @0x2ae226 rsblt r7, r7, #0 */
/* @0x2ae228 cmp r8, r12 */
/* @0x2ae22a bgt 0x2ae230 <png_read_filter_row+0xe8> */
/* @0x2ae22c cmp r8, r7 */
/* @0x2ae22e ble 0x2ae238 <png_read_filter_row+0xf0> */
/* @0x2ae230 cmp r12, r7 */
/* @0x2ae232 ite gt */
/* @0x2ae234 movgt r1, r0 */
/* @0x2ae236 movle r1, r6 */
/* @0x2ae238 ldrb r0, [r5, r2] */
/* @0x2ae23a add r1, r0 */
/* @0x2ae23c strb r1, [r5, r2] */
/* @0x2ae23e adds r2, #0x1 */
/* @0x2ae240 b 0x2ae1fe <png_read_filter_row+0xb6> */
/* @0x2ae242 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae244 stmdbmi r4, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae246 ldr r1, [pc, #0x10] */
/* @0x2ae248 add r1, pc */
/* @0x2ae24a bl 0x2a6474 <png_warning> */
/* @0x2ae24c movwhs pc, #0x913 */
/* @0x2ae24e movs r3, #0x0 */
/* @0x2ae250 strb r3, [r4] */
/* @0x2ae252 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae254 svclt #0x8ff8 */
/* @0x2ae256 nop */
/* @0x2ae258 .word 0xf7b4 000d */

/* ── FUNC 0x2ae25c · png_read_finish_row · size=568 · insn=242 */
/* @0x2ae25c push {r4, r5, r6, r7, lr} */
/* @0x2ae25e mov r4, r0 */
/* @0x2ae260 ldr r6, [pc, #0x214] */
/* @0x2ae262 sub sp, #0x84 */
/* @0x2ae264 add r5, sp, #0x10 */
/* @0x2ae266 add r6, pc */
/* @0x2ae268 add.w r7, r6, #0x24 */
/* @0x2ae26c ldm r7!, {r0, r1, r2, r3} */
/* @0x2ae26e stm r5!, {r0, r1, r2, r3} */
/* @0x2ae270 ldm.w r7, {r0, r1, r2} */
/* @0x2ae274 add.w r7, r6, #0x8 */
/* @0x2ae278 stm.w r5, {r0, r1, r2} */
/* @0x2ae27c add r5, sp, #0x2c */
/* @0x2ae27e ldm r7!, {r0, r1, r2, r3} */
/* @0x2ae280 stm r5!, {r0, r1, r2, r3} */
/* @0x2ae282 ldm.w r7, {r0, r1, r2} */
/* @0x2ae284 .word 0xf1060007 */
/* @0x2ae286 add.w r7, r6, #0x40 */
/* @0x2ae288 ldrblo r0, [r12], -r0, asr #14 */
/* @0x2ae28a adds r6, #0x5c */
/* @0x2ae28c stm.w r5, {r0, r1, r2} */
/* @0x2ae290 add r5, sp, #0x48 */
/* @0x2ae292 ldm r7!, {r0, r1, r2, r3} */
/* @0x2ae294 stm r5!, {r0, r1, r2, r3} */
/* @0x2ae296 ldm.w r7, {r0, r1, r2} */
/* @0x2ae298 stm r5, {r0, r1, r2} */
/* @0x2ae29a stm.w r5, {r0, r1, r2} */
/* @0x2ae29c ldcge p0, c0, [r9, #-28] */
/* @0x2ae29e add r5, sp, #0x64 */
/* @0x2ae2a0 ldm r6!, {r0, r1, r2, r3} */
/* @0x2ae2a2 stm r5!, {r0, r1, r2, r3} */
/* @0x2ae2a4 ldm.w r6, {r0, r1, r2} */
/* @0x2ae2a8 ldr.w r3, [r4, #0x1a8] */
/* @0x2ae2ac adds r3, #0x1 */
/* @0x2ae2ae str.w r3, [r4, #0x1a8] */
/* @0x2ae2b0 stm r5, {r3, r5, r7, r8, r12, sp} */
/* @0x2ae2b2 stm.w r5, {r0, r1, r2} */
/* @0x2ae2b4 .word 0xf8d40007 */
/* @0x2ae2b6 ldr.w r2, [r4, #0x194] */
/* @0x2ae2b8 addsmi r2, r3, #148, #2 */
/* @0x2ae2ba cmp r3, r2 */
/* @0x2ae2bc blo.w 0x2ae474 <png_read_finish_row+0x218> */
/* @0x2ae2c0 ldrb.w r3, [r4, #0x1e7] */
/* @0x2ae2c4 cmp r3, #0x0 */
/* @0x2ae2c6 beq 0x2ae342 <png_read_finish_row+0xe6> */
/* @0x2ae2c8 ldr.w r2, [r4, #0x19c] */
/* @0x2ae2cc movs r1, #0x0 */
/* @0x2ae2ce ldr.w r0, [r4, #0x1ac] */
/* @0x2ae2d0 .word 0xf8c401ac */
/* @0x2ae2d2 str.w r1, [r4, #0x1a8] */
/* @0x2ae2d4 andlo r1, r1, #168, #2 */
/* @0x2ae2d6 adds r2, #0x1 */
/* @0x2ae2d8 blx 0xb65b0 <memset@plt> */
/* @0x2ae2dc ldrb.w r5, [r4, #0x1e8] */
/* @0x2ae2e0 adds r5, #0x1 */
/* @0x2ae2e2 uxtb r5, r5 */
/* @0x2ae2e4 cmp r5, #0x6 */
/* @0x2ae2e6 bls 0x2ae2ee <png_read_finish_row+0x92> */
/* @0x2ae2e8 strb.w r5, [r4, #0x1e8] */
/* @0x2ae2ec b 0x2ae342 <png_read_finish_row+0xe6> */
/* @0x2ae2ee add r3, sp, #0x80 */
/* @0x2ae2f0 add.w r6, r3, r5, lsl #2 */
/* @0x2ae2f4 ldr.w r3, [r4, #0x18c] */
/* @0x2ae2f8 ldr r1, [r6, #-84] */
/* @0x2ae2fc subs r3, #0x1 */
/* @0x2ae2fe adds r0, r3, r1 */
/* @0x2ae300 ldr r3, [r6, #-112] */
/* @0x2ae304 subs r0, r0, r3 */
/* @0x2ae306 blx 0x318c48 <__udivsi3> */
/* @0x2ae308 .word 0xf8d4eca0 */
/* @0x2ae30a ldr.w r3, [r4, #0x134] */
/* @0x2ae30c .word 0x079a3134 */
/* @0x2ae30e lsls r2, r3, #0x1e */
/* @0x2ae310 mov r7, r0 */
/* @0x2ae312 str.w r0, [r4, #0x1a4] */
/* @0x2ae314 .word 0xf10001a4 */
/* @0x2ae316 bmi.w 0x2ae470 <png_read_finish_row+0x214> */
/* @0x2ae318 .word 0xf8d480ab */
/* @0x2ae31a ldr.w r3, [r4, #0x190] */
/* @0x2ae31c .word 0xf8563190 */
/* @0x2ae31e ldr r1, [r6, #-28] */
/* @0x2ae320 bllo 0x2f5398 <ps_hints_apply+0x3f98> */
/* @0x2ae322 subs r3, #0x1 */
/* @0x2ae324 ldr r2, [r6, #-56] */
/* @0x2ae328 adds r0, r3, r1 */
/* @0x2ae32a subs r0, r0, r2 */
/* @0x2ae32c blx 0x318c48 <__udivsi3> */
/* @0x2ae330 adds r3, r5, #0x1 */
/* @0x2ae332 uxtb r3, r3 */
/* @0x2ae334 str.w r0, [r4, #0x194] */
/* @0x2ae338 cmp r7, #0x0 */
/* @0x2ae33a bne.w 0x2ae470 <png_read_finish_row+0x214> */
/* @0x2ae33c sadd8mi r8, sp, r9 */
/* @0x2ae33e mov r5, r3 */
/* @0x2ae340 b 0x2ae2e4 <png_read_finish_row+0x88> */
/* @0x2ae342 ldr.w r3, [r4, #0x130] */
/* @0x2ae344 .word 0x069b3130 */
/* @0x2ae346 lsls r3, r3, #0x1a */
/* @0x2ae348 bmi 0x2ae444 <png_read_finish_row+0x1e8> */
/* @0x2ae34a ldr r3, [pc, #0x130] */
/* @0x2ae34c add r5, sp, #0x8 */
/* @0x2ae34e add r3, pc */
/* @0x2ae350 ldr r0, [r3] */
/* @0x2ae352 ldrb r3, [r3, #0x4] */
/* @0x2ae354 str r0, [sp, #0x8] */
/* @0x2ae356 strb.w r3, [sp, #0xc] */
/* @0x2ae358 .word 0xf10d300c */
/* @0x2ae35a add.w r3, sp, #0x7 */
/* @0x2ae35c .word 0xf8c40307 */
/* @0x2ae35e str.w r3, [r4, #0x144] */
/* @0x2ae360 movwhs r3, #0x1144 */
/* @0x2ae362 movs r3, #0x1 */
/* @0x2ae364 str.w r3, [r4, #0x148] */
/* @0x2ae368 ldr.w r3, [r4, #0x13c] */
/* @0x2ae36c cbnz r3, 0x2ae3d6 <png_read_finish_row+0x17a> */
/* @0x2ae36e ldr r7, [pc, #0x110] */
/* @0x2ae370 add r7, pc */
/* @0x2ae372 add.w r6, r4, #0x1e0 */
/* @0x2ae374 .word 0xf8d476f0 */
/* @0x2ae376 ldr.w r3, [r4, #0x1d0] */
/* @0x2ae378 stmiblt r3!, {r4, r6, r7, r8, r12, sp} */
/* @0x2ae37a cbnz r3, 0x2ae3a6 <png_read_finish_row+0x14a> */
/* @0x2ae37c mov r1, r3 */
/* @0x2ae37e mov r0, r4 */
/* @0x2ae380 bl 0x2abc94 <png_crc_finish> */
/* @0x2ae384 mov r0, r4 */
/* @0x2ae386 bl 0x2adbc4 <png_read_chunk_header> */
/* @0x2ae388 qadd16mi pc, r9, sp */
/* @0x2ae38a mov r1, r5 */
/* @0x2ae38c movs r2, #0x4 */
/* @0x2ae38e str.w r0, [r4, #0x1d0] */
/* @0x2ae390 .word 0x463001d0 */
/* @0x2ae392 mov r0, r6 */
/* @0x2ae394 blx 0xb6c40 <memcmp@plt> */
/* @0x2ae398 cmp r0, #0x0 */
/* @0x2ae39a beq 0x2ae376 <png_read_finish_row+0x11a> */
/* @0x2ae39c mov r0, r4 */
/* @0x2ae39e mov r1, r7 */
/* @0x2ae3a0 bl 0x2a642c <png_error> */
/* @0x2ae3a4 b 0x2ae372 <png_read_finish_row+0x116> */
/* @0x2ae3a6 ldr.w r2, [r4, #0x174] */
/* @0x2ae3a8 qsub16mi r2, r0, r4 */
/* @0x2ae3aa mov r0, r4 */
/* @0x2ae3ac ldr.w r1, [r4, #0x170] */
/* @0x2ae3b0 cmp r2, r3 */
/* @0x2ae3b2 str.w r2, [r4, #0x13c] */
/* @0x2ae3b4 .word 0xf8c4213c */
/* @0x2ae3b6 str.w r1, [r4, #0x138] */
/* @0x2ae3b8 svclt #0x881138 */
/* @0x2ae3ba it hi */
/* @0x2ae3bc strhi.w r3, [r4, #0x13c] */
/* @0x2ae3c0 ldr.w r2, [r4, #0x13c] */
/* @0x2ae3c4 bl 0x2abc0c <png_crc_read> */
/* @0x2ae3c8 ldr.w r2, [r4, #0x1d0] */
/* @0x2ae3cc ldr.w r3, [r4, #0x13c] */
/* @0x2ae3d0 subs r3, r2, r3 */
/* @0x2ae3d2 str.w r3, [r4, #0x1d0] */
/* @0x2ae3d4 .word 0xf50431d0 */
/* @0x2ae3d6 add.w r0, r4, #0x138 */
/* @0x2ae3d8 swphs r7, r12, [r1] */
/* @0x2ae3da movs r1, #0x1 */
/* @0x2ae3dc blx 0xb69dc <inflate@plt> */
/* @0x2ae3e0 cmp r0, #0x1 */
/* @0x2ae3e2 bne 0x2ae3fe <png_read_finish_row+0x1a2> */
/* @0x2ae3e4 ldr.w r3, [r4, #0x148] */
/* @0x2ae3e8 cbz r3, 0x2ae3f6 <png_read_finish_row+0x19a> */
/* @0x2ae3ea ldr.w r3, [r4, #0x13c] */
/* @0x2ae3ec ldmdblt r3, {r2, r3, r4, r5, r8, r12, sp} */
/* @0x2ae3ee cbnz r3, 0x2ae3f6 <png_read_finish_row+0x19a> */
/* @0x2ae3f0 ldr.w r3, [r4, #0x1d0] */
/* @0x2ae3f4 cbz r3, 0x2ae426 <png_read_finish_row+0x1ca> */
/* @0x2ae3f6 ldr r1, [pc, #0x8c] */
/* @0x2ae3f8 mov r0, r4 */
/* @0x2ae3fa add r1, pc */
/* @0x2ae3fc b 0x2ae422 <png_read_finish_row+0x1c6> */
/* @0x2ae3fe cbz r0, 0x2ae414 <png_read_finish_row+0x1b8> */
/* @0x2ae400 ldr.w r3, [r4, #0x150] */
/* @0x2ae404 cbnz r3, 0x2ae40c <png_read_finish_row+0x1b0> */
/* @0x2ae406 ldr r1, [pc, #0x80] */
/* @0x2ae408 add r1, pc */
/* @0x2ae40a b 0x2ae40e <png_read_finish_row+0x1b2> */
/* @0x2ae40c mov r1, r3 */
/* @0x2ae40e mov r0, r4 */
/* @0x2ae410 bl 0x2a642c <png_error> */
/* @0x2ae414 ldr.w r3, [r4, #0x148] */
/* @0x2ae418 cmp r3, #0x0 */
/* @0x2ae41a bne 0x2ae368 <png_read_finish_row+0x10c> */
/* @0x2ae41c ldr r1, [pc, #0x6c] */
/* @0x2ae41e mov r0, r4 */
/* @0x2ae420 add r1, pc */
/* @0x2ae422 bl 0x2a6474 <png_warning> */
/* @0x2ae424 .word 0xf8d4f827 */
/* @0x2ae426 ldr.w r3, [r4, #0x12c] */
/* @0x2ae428 .word 0xf043312c */
/* @0x2ae42a orr r3, r3, #0x8 */
/* @0x2ae42c .word 0xf8c40308 */
/* @0x2ae42e str.w r3, [r4, #0x12c] */
/* @0x2ae430 .word 0xf8d4312c */
/* @0x2ae432 ldr.w r3, [r4, #0x130] */
/* @0x2ae434 .word 0xf0433130 */
/* @0x2ae436 orr r3, r3, #0x20 */
/* @0x2ae438 .word 0xf8c40320 */
/* @0x2ae43a str.w r3, [r4, #0x130] */
/* @0x2ae43c movwhs r3, #0x130 */
/* @0x2ae43e movs r3, #0x0 */
/* @0x2ae440 str.w r3, [r4, #0x148] */
/* @0x2ae444 ldr.w r3, [r4, #0x1d0] */
/* @0x2ae448 cbnz r3, 0x2ae450 <png_read_finish_row+0x1f4> */
/* @0x2ae44a ldr.w r3, [r4, #0x13c] */
/* @0x2ae44c .word 0xb123313c */
/* @0x2ae44e cbz r3, 0x2ae45a <png_read_finish_row+0x1fe> */
/* @0x2ae450 ldr r1, [pc, #0x3c] */
/* @0x2ae452 mov r0, r4 */
/* @0x2ae454 add r1, pc */
/* @0x2ae456 bl 0x2a6474 <png_warning> */
/* @0x2ae458 .word 0xf504f80d */
/* @0x2ae45a add.w r0, r4, #0x138 */
/* @0x2ae45c .word 0xf608709c */
/* @0x2ae45e blx 0xb6f40 <inflateReset@plt> */
/* @0x2ae460 .word 0xf8d4ed70 */
/* @0x2ae462 ldr.w r3, [r4, #0x12c] */
/* @0x2ae464 .word 0xf043312c */
/* @0x2ae466 orr r3, r3, #0x8 */
/* @0x2ae468 .word 0xf8c40308 */
/* @0x2ae46a str.w r3, [r4, #0x12c] */
/* @0x2ae46c and r3, r1, r12, lsr #2 */
/* @0x2ae46e b 0x2ae474 <png_read_finish_row+0x218> */
/* @0x2ae470 strb.w r5, [r4, #0x1e8] */
/* @0x2ae474 add sp, #0x84 */
/* @0x2ae476 pop {r4, r5, r6, r7, pc} */
/* @0x2ae478 asrs r2, r0, #0x1e */
/* @0x2ae47a movs r6, r1 */
/* @0x2ae47c asrs r2, r3, #0x1a */
/* @0x2ae47e movs r6, r1 */
/* @0x2ae480 b 0x2adeac <png_do_read_interlace+0x90> */
/* @0x2ae482 movs r5, r1 */
/* @0x2ae484 b 0x2addc8 <png_combine_row+0x198> */
/* @0x2ae486 movs r5, r1 */
/* @0x2ae488 .word 0xf616 000d */
/* @0x2ae48c b 0x2add84 <png_combine_row+0x154> */
/* @0x2ae48e movs r5, r1 */
/* @0x2ae490 rsbs.w r0, lr, #0x8d0000 */

/* ── FUNC 0x2ae494 · png_read_start_row · size=544 · insn=243 */
/* @0x2ae494 push {r4, r5, r6, r7, lr} */
/* @0x2ae496 mov r4, r0 */
/* @0x2ae498 ldr r6, [pc, #0x210] */
/* @0x2ae49a sub sp, #0x3c */
/* @0x2ae49c add r6, pc */
/* @0x2ae49e mov r5, sp */
/* @0x2ae4a0 add.w r7, r6, #0x24 */
/* @0x2ae4a4 adds r6, #0x8 */
/* @0x2ae4a6 ldm r7!, {r0, r1, r2, r3} */
/* @0x2ae4a8 stm r5!, {r0, r1, r2, r3} */
/* @0x2ae4aa ldm.w r7, {r0, r1, r2} */
/* @0x2ae4ac stm r5, {r0, r1, r2} */
/* @0x2ae4ae stm.w r5, {r0, r1, r2} */
/* @0x2ae4b0 stcge p0, c0, [r7, #-28] */
/* @0x2ae4b2 add r5, sp, #0x1c */
/* @0x2ae4b4 ldm r6!, {r0, r1, r2, r3} */
/* @0x2ae4b6 stm r5!, {r0, r1, r2, r3} */
/* @0x2ae4b8 movs r3, #0x0 */
/* @0x2ae4ba ldm.w r6, {r0, r1, r2} */
/* @0x2ae4bc .word 0xf8c40007 */
/* @0x2ae4be str.w r3, [r4, #0x13c] */
/* @0x2ae4c0 stm r5, {r2, r3, r4, r5, r8, r12, sp} */
/* @0x2ae4c2 stm.w r5, {r0, r1, r2} */
/* @0x2ae4c4 strtmi r0, [r0], -r7 */
/* @0x2ae4c6 mov r0, r4 */
/* @0x2ae4c8 bl 0x2ab178 <png_init_read_transformations> */
/* @0x2ae4cc ldrb.w r2, [r4, #0x1e7] */
/* @0x2ae4d0 ldr.w r5, [r4, #0x134] */
/* @0x2ae4d4 ldr.w r3, [r4, #0x190] */
/* @0x2ae4d8 ldr.w r6, [r4, #0x18c] */
/* @0x2ae4dc cbz r2, 0x2ae510 <png_read_start_row+0x7c> */
/* @0x2ae4de lsls r2, r5, #0x1e */
/* @0x2ae4e0 add r2, sp, #0x38 */
/* @0x2ae4e2 it pl */
/* @0x2ae4e4 addpl r3, #0x7 */
/* @0x2ae4e6 add.w r0, r6, #0xffffffff */
/* @0x2ae4e8 svclt #0x5830ff */
/* @0x2ae4ea it pl */
/* @0x2ae4ec lsrpl r3, r3, #0x3 */
/* @0x2ae4ee str.w r3, [r4, #0x194] */
/* @0x2ae4f0 .word 0xf8943194 */
/* @0x2ae4f2 ldrb.w r3, [r4, #0x1e8] */
/* @0x2ae4f4 bl 0x33ac9c */
/* @0x2ae4f6 add.w r3, r2, r3, lsl #2 */
/* @0x2ae4f8 .word 0xf8530383 */
/* @0x2ae4fa ldr r1, [r3, #-28] */
/* @0x2ae4fc .word 0xf8531c1c */
/* @0x2ae4fe ldr r3, [r3, #-56] */
/* @0x2ae500 strmi r3, [r8], #-3128 */
/* @0x2ae502 add r0, r1 */
/* @0x2ae504 subs r0, r0, r3 */
/* @0x2ae506 blx 0x318c48 <__udivsi3> */
/* @0x2ae508 .word 0xf8c4eba0 */
/* @0x2ae50a str.w r0, [r4, #0x1a4] */
/* @0x2ae50c and r0, r3, r4, lsr #3 */
/* @0x2ae50e b 0x2ae518 <png_read_start_row+0x84> */
/* @0x2ae510 str.w r3, [r4, #0x194] */
/* @0x2ae514 str.w r6, [r4, #0x1a4] */
/* @0x2ae518 lsls r7, r5, #0x1d */
/* @0x2ae51a ldrb.w r0, [r4, #0x1ed] */
/* @0x2ae51c strle r0, [r4, #-0x1ed] */
/* @0x2ae51e bpl 0x2ae52a <png_read_start_row+0x96> */
/* @0x2ae520 ldrb.w r3, [r4, #0x1eb] */
/* @0x2ae524 cmp r3, #0x7 */
/* @0x2ae526 it ls */
/* @0x2ae528 movls r0, #0x8 */
/* @0x2ae52a ands r7, r5, #0x1000 */
/* @0x2ae52c andsle r5, r12, r0, lsl #15 */
/* @0x2ae52e beq 0x2ae56a <png_read_start_row+0xd6> */
/* @0x2ae530 ldrb.w r3, [r4, #0x1ea] */
/* @0x2ae534 cmp r3, #0x3 */
/* @0x2ae536 bne 0x2ae546 <png_read_start_row+0xb2> */
/* @0x2ae538 ldrh.w r0, [r4, #0x1de] */
/* @0x2ae53c cmp r0, #0x0 */
/* @0x2ae53e ite eq */
/* @0x2ae540 moveq r0, #0x18 */
/* @0x2ae542 movne r0, #0x20 */
/* @0x2ae544 b 0x2ae56a <png_read_start_row+0xd6> */
/* @0x2ae546 cbnz r3, 0x2ae558 <png_read_start_row+0xc4> */
/* @0x2ae548 ldrh.w r3, [r4, #0x1de] */
/* @0x2ae54c cmp r0, #0x8 */
/* @0x2ae54e it lt */
/* @0x2ae550 movlt r0, #0x8 */
/* @0x2ae552 cbz r3, 0x2ae56a <png_read_start_row+0xd6> */
/* @0x2ae554 lsls r0, r0, #0x1 */
/* @0x2ae556 b 0x2ae56a <png_read_start_row+0xd6> */
/* @0x2ae558 cmp r3, #0x2 */
/* @0x2ae55a bne 0x2ae56a <png_read_start_row+0xd6> */
/* @0x2ae55c ldrh.w r3, [r4, #0x1de] */
/* @0x2ae560 cbz r3, 0x2ae56a <png_read_start_row+0xd6> */
/* @0x2ae562 lsls r0, r0, #0x2 */
/* @0x2ae564 movs r1, #0x3 */
/* @0x2ae566 blx 0x318d10 <__divsi3> */
/* @0x2ae568 .word 0xf415ebd4 */
/* @0x2ae56a ands r2, r5, #0x8000 */
/* @0x2ae56c andsle r4, r1, r0, lsl #4 */
/* @0x2ae56e beq 0x2ae594 <png_read_start_row+0x100> */
/* @0x2ae570 ldrb.w r3, [r4, #0x1ea] */
/* @0x2ae574 cmp r3, #0x3 */
/* @0x2ae576 beq 0x2ae592 <png_read_start_row+0xfe> */
/* @0x2ae578 cbnz r3, 0x2ae584 <png_read_start_row+0xf0> */
/* @0x2ae57a cmp r0, #0x8 */
/* @0x2ae57c ite gt */
/* @0x2ae57e movgt r0, #0x20 */
/* @0x2ae580 movle r0, #0x10 */
/* @0x2ae582 b 0x2ae594 <png_read_start_row+0x100> */
/* @0x2ae584 cmp r3, #0x2 */
/* @0x2ae586 bne 0x2ae594 <png_read_start_row+0x100> */
/* @0x2ae588 cmp r0, #0x20 */
/* @0x2ae58a ite gt */
/* @0x2ae58c movgt r0, #0x40 */
/* @0x2ae58e movle r0, #0x20 */
/* @0x2ae590 b 0x2ae594 <png_read_start_row+0x100> */
/* @0x2ae592 movs r0, #0x20 */
/* @0x2ae594 lsls r1, r5, #0x11 */
/* @0x2ae596 bpl 0x2ae5ca <png_read_start_row+0x136> */
/* @0x2ae598 ldrh.w r3, [r4, #0x1de] */
/* @0x2ae59c cbz r3, 0x2ae5a0 <png_read_start_row+0x10c> */
/* @0x2ae59e cbnz r7, 0x2ae5aa <png_read_start_row+0x116> */
/* @0x2ae5a0 cbnz r2, 0x2ae5aa <png_read_start_row+0x116> */
/* @0x2ae5a2 ldrb.w r3, [r4, #0x1ea] */
/* @0x2ae5a4 blhs 0x3bad54 <error_g0017+0x139f8> */
/* @0x2ae5a6 cmp r3, #0x4 */
/* @0x2ae5a8 bne 0x2ae5b4 <png_read_start_row+0x120> */
/* @0x2ae5aa cmp r0, #0x10 */
/* @0x2ae5ac ite gt */
/* @0x2ae5ae movgt r0, #0x40 */
/* @0x2ae5b0 movle r0, #0x20 */
/* @0x2ae5b2 b 0x2ae5ca <png_read_start_row+0x136> */
/* @0x2ae5b4 cmp r0, #0x8 */
/* @0x2ae5b6 bgt 0x2ae5c2 <png_read_start_row+0x12e> */
/* @0x2ae5b8 cmp r3, #0x6 */
/* @0x2ae5ba ite ne */
/* @0x2ae5bc movne r0, #0x18 */
/* @0x2ae5be moveq r0, #0x20 */
/* @0x2ae5c0 b 0x2ae5ca <png_read_start_row+0x136> */
/* @0x2ae5c2 cmp r3, #0x6 */
/* @0x2ae5c4 ite ne */
/* @0x2ae5c6 movne r0, #0x30 */
/* @0x2ae5c8 moveq r0, #0x40 */
/* @0x2ae5ca lsls r3, r5, #0xb */
/* @0x2ae5cc bpl 0x2ae5e0 <png_read_start_row+0x14c> */
/* @0x2ae5ce ldrb.w r2, [r4, #0x128] */
/* @0x2ae5d0 .word 0xf8942128 */
/* @0x2ae5d2 ldrb.w r3, [r4, #0x129] */
/* @0x2ae5d4 blx 0x73aa82 <g_SWFvertbuff+0x679ba> */
/* @0x2ae5d6 smulbb r3, r2, r3 */
/* @0x2ae5d8 addsmi pc, r8, #201326592 */
/* @0x2ae5da cmp r0, r3 */
/* @0x2ae5dc it lt */
/* @0x2ae5de movlt r0, r3 */
/* @0x2ae5e0 adds r6, #0x7 */
/* @0x2ae5e2 cmp r0, #0x7 */
/* @0x2ae5e4 bic r6, r6, #0x7 */
/* @0x2ae5e8 it gt */
/* @0x2ae5ea lsrgt r5, r0, #0x3 */
/* @0x2ae5ec ldr.w r3, [r4, #0x328] */
/* @0x2ae5f0 it le */
/* @0x2ae5f2 mulle r5, r6, r0 */
/* @0x2ae5f4 .word 0xf100f500 */
/* @0x2ae5f6 add.w r0, r0, #0x7 */
/* @0x2ae5f8 svclt #0xcc0007 */
/* @0x2ae5fa ite gt */
/* @0x2ae5fc mulgt r5, r6, r5 */
/* @0x2ae5fe lsrle r5, r5, #0x3 */
/* @0x2ae600 adds r5, #0x1 */
/* @0x2ae602 add.w r5, r5, r0, asr #3 */
/* @0x2ae604 ldrlo r0, [r0, #-0x5e0]! */
/* @0x2ae606 adds r5, #0x30 */
/* @0x2ae608 cmp r5, r3 */
/* @0x2ae60a bls 0x2ae648 <png_read_start_row+0x1b4> */
/* @0x2ae60c mov r0, r4 */
/* @0x2ae60e ldr.w r1, [r4, #0x2f4] */
/* @0x2ae610 .word 0xf7f812f4 */
/* @0x2ae612 bl 0x2a6cfc <png_free> */
/* @0x2ae614 .word 0xf894fb73 */
/* @0x2ae616 ldrb.w r3, [r4, #0x1e7] */
/* @0x2ae618 strtmi r3, [r0], -r7, ror #3 */
/* @0x2ae61a mov r0, r4 */
/* @0x2ae61c mov r1, r5 */
/* @0x2ae61e cbz r3, 0x2ae626 <png_read_start_row+0x192> */
/* @0x2ae620 bl 0x2a6cd8 <png_calloc> */
/* @0x2ae624 b 0x2ae62a <png_read_start_row+0x196> */
/* @0x2ae626 bl 0x2a6ca0 <png_malloc> */
/* @0x2ae628 .word 0xf8c4fb3b */
/* @0x2ae62a str.w r0, [r4, #0x2f4] */
/* @0x2ae62c .word 0xf8d402f4 */
/* @0x2ae62e ldr.w r3, [r4, #0x2f4] */
/* @0x2ae630 .word 0xf8c432f4 */
/* @0x2ae632 str.w r5, [r4, #0x328] */
/* @0x2ae634 .word 0xf1035328 */
/* @0x2ae636 add.w r2, r3, #0xf */
/* @0x2ae638 .word 0xf002020f */
/* @0x2ae63a and r2, r2, #0xf */
/* @0x2ae63c .word 0xf1c2020f */
/* @0x2ae63e rsb.w r2, r2, #0x20 */
/* @0x2ae640 ldrmi r0, [r3], #-544 */
/* @0x2ae642 add r3, r2 */
/* @0x2ae644 str.w r3, [r4, #0x1b0] */
/* @0x2ae648 ldr.w r3, [r4, #0x19c] */
/* @0x2ae64c adds r3, #0x1 */
/* @0x2ae64e bne 0x2ae65a <png_read_start_row+0x1c6> */
/* @0x2ae650 ldr r1, [pc, #0x5c] */
/* @0x2ae652 mov r0, r4 */
/* @0x2ae654 add r1, pc */
/* @0x2ae656 bl 0x2a642c <png_error> */
/* @0x2ae658 .word 0xf8d4fee9 */
/* @0x2ae65a ldr.w r3, [r4, #0x19c] */
/* @0x2ae65c mrrcne p1, #0x9, r3, r10, c12 */
/* @0x2ae65e adds r2, r3, #0x1 */
/* @0x2ae660 ldr.w r3, [r4, #0x32c] */
/* @0x2ae664 cmp r2, r3 */
/* @0x2ae666 bls 0x2ae68c <png_read_start_row+0x1f8> */
/* @0x2ae668 mov r0, r4 */
/* @0x2ae66a ldr.w r1, [r4, #0x1ac] */
/* @0x2ae66c .word 0xf7f811ac */
/* @0x2ae66e bl 0x2a6cfc <png_free> */
/* @0x2ae670 .word 0xf8d4fb45 */
/* @0x2ae672 ldr.w r1, [r4, #0x19c] */
/* @0x2ae674 qadd8mi r1, r0, r12 */
/* @0x2ae676 mov r0, r4 */
/* @0x2ae678 adds r1, #0x1 */
/* @0x2ae67a bl 0x2a6ca0 <png_malloc> */
/* @0x2ae67c .word 0xf8d4fb11 */
/* @0x2ae67e ldr.w r3, [r4, #0x19c] */
/* @0x2ae680 movwlo r3, #0x119c */
/* @0x2ae682 adds r3, #0x1 */
/* @0x2ae684 str.w r3, [r4, #0x32c] */
/* @0x2ae688 str.w r0, [r4, #0x1ac] */
/* @0x2ae68c ldr.w r2, [r4, #0x19c] */
/* @0x2ae690 movs r1, #0x0 */
/* @0x2ae692 ldr.w r0, [r4, #0x1ac] */
/* @0x2ae694 andlo r0, r1, #172, #2 */
/* @0x2ae696 adds r2, #0x1 */
/* @0x2ae698 blx 0xb65b0 <memset@plt> */
/* @0x2ae69c ldr.w r3, [r4, #0x130] */
/* @0x2ae6a0 orr r3, r3, #0x40 */
/* @0x2ae6a4 str.w r3, [r4, #0x130] */
/* @0x2ae6a8 add sp, #0x3c */
/* @0x2ae6aa pop {r4, r5, r6, r7, pc} */
/* @0x2ae6ac asrs r4, r1, #0x15 */
/* @0x2ae6ae movs r6, r1 */
/* @0x2ae6b0 .word 0xf3f5 000d */

/* ── FUNC 0x2ae6b4 · png_set_bKGD · size=32 · insn=14 */
/* @0x2ae6b4 cbz r0, 0x2ae6d2 <png_set_bKGD+0x1e> */
/* @0x2ae6b6 cbz r1, 0x2ae6d2 <png_set_bKGD+0x1e> */
/* @0x2ae6b8 ldr r3, [r2] */
/* @0x2ae6ba str.w r3, [r1, #0x5a] */
/* @0x2ae6bc ldmdavs r3, {r1, r3, r4, r6, r12, sp} ^ */
/* @0x2ae6be ldr r3, [r2, #0x4] */
/* @0x2ae6c0 str.w r3, [r1, #0x5e] */
/* @0x2ae6c4 ldrh r3, [r2, #0x8] */
/* @0x2ae6c6 strh.w r3, [r1, #0x62] */
/* @0x2ae6c8 stmvs r11, {r1, r5, r6, r12, sp} */
/* @0x2ae6ca ldr r3, [r1, #0x8] */
/* @0x2ae6cc orr r3, r3, #0x20 */
/* @0x2ae6d0 str r3, [r1, #0x8] */
/* @0x2ae6d2 bx lr */

/* ── FUNC 0x2ae6d4 · anon_2ae6d4 · size=0 · insn=1 */
/* @0x2ae6d4 andeq r0, r0, r0 */

/* ── FUNC 0x2ae6d8 · png_set_cHRM · size=264 · insn=73 */
/* @0x2ae6d8 vpush {d8, d9, d10} */
/* @0x2ae6dc vmov d9, r2, r3 */
/* @0x2ae6e0 vldr d8, [sp, #24] */
/* @0x2ae6e4 vldr d0, [sp, #32] */
/* @0x2ae6e8 vldr d1, [sp, #40] */
/* @0x2ae6ec vldr d2, [sp, #48] */
/* @0x2ae6f0 vldr d3, [sp, #56] */
/* @0x2ae6f4 vldr d4, [sp, #64] */
/* @0x2ae6f8 vldr d5, [sp, #72] */
/* @0x2ae6fc cmp r0, #0x0 */
/* @0x2ae6fe beq 0x2ae7d0 <png_set_cHRM+0xf8> */
/* @0x2ae700 cmp r1, #0x0 */
/* @0x2ae702 beq 0x2ae7d0 <png_set_cHRM+0xf8> */
/* @0x2ae704 vcvt.f32.f64 s15, d9 */
/* @0x2ae708 vldr d6, [pc, #204] */
/* @0x2ae70c ldr r3, [r1, #0x8] */
/* @0x2ae70e orr r3, r3, #0x4 */
/* @0x2ae710 addvs r0, r11, r4, lsl #6 */
/* @0x2ae712 str r3, [r1, #0x8] */
/* @0x2ae714 vstr s15, [r1, #128] */
/* @0x2ae718 vcvt.f32.f64 s15, d8 */
/* @0x2ae71c vstr s15, [r1, #132] */
/* @0x2ae720 vcvt.f32.f64 s15, d0 */
/* @0x2ae724 vstr s15, [r1, #136] */
/* @0x2ae728 vcvt.f32.f64 s15, d1 */
/* @0x2ae72c vstr s15, [r1, #140] */
/* @0x2ae730 vcvt.f32.f64 s15, d2 */
/* @0x2ae734 vstr s15, [r1, #144] */
/* @0x2ae738 vcvt.f32.f64 s15, d3 */
/* @0x2ae73c vstr s15, [r1, #148] */
/* @0x2ae740 vcvt.f32.f64 s15, d4 */
/* @0x2ae744 vstr s15, [r1, #152] */
/* @0x2ae748 vcvt.f32.f64 s15, d5 */
/* @0x2ae74c vstr s15, [r1, #156] */
/* @0x2ae750 vmov.f64 d7, #5.000000e-01 */
/* @0x2ae754 vmov.f64 d10, d7 */
/* @0x2ae758 vmla.f64 d10, d9, d6 */
/* @0x2ae75c vcvt.s32.f64 s18, d10 */
/* @0x2ae760 vmov.f64 d10, d7 */
/* @0x2ae764 vstr s18, [r1, #256] */
/* @0x2ae768 vmla.f64 d10, d0, d6 */
/* @0x2ae76c vcvt.s32.f64 s0, d10 */
/* @0x2ae770 vstr s0, [r1, #264] */
/* @0x2ae774 vmov.f64 d0, d7 */
/* @0x2ae778 vmla.f64 d0, d1, d6 */
/* @0x2ae77c vcvt.s32.f64 s2, d0 */
/* @0x2ae780 vstr s2, [r1, #268] */
/* @0x2ae784 vmov.f64 d1, d7 */
/* @0x2ae788 vmla.f64 d1, d2, d6 */
/* @0x2ae78c vcvt.s32.f64 s4, d1 */
/* @0x2ae790 vstr s4, [r1, #272] */
/* @0x2ae794 vmov.f64 d2, d7 */
/* @0x2ae798 vmla.f64 d2, d3, d6 */
/* @0x2ae79c vcvt.s32.f64 s6, d2 */
/* @0x2ae7a0 vmov.f64 d9, d7 */
/* @0x2ae7a4 vstr s6, [r1, #276] */
/* @0x2ae7a8 vmov.f64 d3, d7 */
/* @0x2ae7ac vmla.f64 d9, d8, d6 */
/* @0x2ae7b0 vmla.f64 d3, d4, d6 */
/* @0x2ae7b4 vmla.f64 d7, d5, d6 */
/* @0x2ae7b8 vcvt.s32.f64 s16, d9 */
/* @0x2ae7bc vcvt.s32.f64 s8, d3 */
/* @0x2ae7c0 vstr s16, [r1, #260] */
/* @0x2ae7c4 vcvt.s32.f64 s14, d7 */
/* @0x2ae7c8 vstr s8, [r1, #280] */
/* @0x2ae7cc vstr s14, [r1, #284] */
/* @0x2ae7d0 vpop {d8, d9, d10} */
/* @0x2ae7d4 bx lr */
/* @0x2ae7d6 nop */
/* @0x2ae7d8 movs r0, r0 */
/* @0x2ae7da movs r0, r0 */
/* @0x2ae7dc ldr r0, [r0, #0x20] */
/* @0x2ae7de lsrs r0, r7 */

/* ── FUNC 0x2ae7e0 · png_set_cHRM_fixed · size=280 · insn=131 */
/* @0x2ae7e0 push.w {r4, r5, r6, r7, r9, r10, r11, lr} */
/* @0x2ae7e4 sub sp, #0x18 */
/* @0x2ae7e6 mov r4, r1 */
/* @0x2ae7e8 mov r11, r2 */
/* @0x2ae7ea mov r10, r3 */
/* @0x2ae7ec ldr.w r9, [sp, #0x38] */
/* @0x2ae7f0 ldr r7, [sp, #0x3c] */
/* @0x2ae7f2 ldr r6, [sp, #0x40] */
/* @0x2ae7f4 ldr r5, [sp, #0x44] */
/* @0x2ae7f6 cmp r0, #0x0 */
/* @0x2ae7f8 beq 0x2ae8ea <png_set_cHRM_fixed+0x10a> */
/* @0x2ae7fa cmp r1, #0x0 */
/* @0x2ae7fc beq 0x2ae8ea <png_set_cHRM_fixed+0x10a> */
/* @0x2ae7fe ldr r3, [sp, #0x48] */
/* @0x2ae800 mov r1, r2 */
/* @0x2ae802 str r7, [sp] */
/* @0x2ae804 mov r2, r10 */
/* @0x2ae806 str r6, [sp, #0x4] */
/* @0x2ae808 str r3, [sp, #0xc] */
/* @0x2ae80a ldr r3, [sp, #0x4c] */
/* @0x2ae80c str r5, [sp, #0x8] */
/* @0x2ae80e str r3, [sp, #0x10] */
/* @0x2ae810 mov r3, r9 */
/* @0x2ae812 bl 0x2a6068 <png_check_cHRM_fixed> */
/* @0x2ae814 stmdahs r0, {r0, r3, r5, r10, r11, r12, sp, lr, pc} */
/* @0x2ae816 cmp r0, #0x0 */
/* @0x2ae818 beq 0x2ae8ea <png_set_cHRM_fixed+0x10a> */
/* @0x2ae81a vmov s11, r11 */
/* @0x2ae81c vldr s22, [pc, #576] */
/* @0x2ae81e vldr d7, [pc, #208] */
/* @0x2ae820 blls 0x74d4f8 <g_SWFvertbuff+0x7a430> */
/* @0x2ae822 ldr r3, [sp, #0x48] */
/* @0x2ae824 vcvt.f64.s32 d6, s11 */
/* @0x2ae828 str.w r11, [r4, #0x100] */
/* @0x2ae82c vmov s11, r10 */
/* @0x2ae830 str.w r10, [r4, #0x104] */
/* @0x2ae834 str.w r3, [r4, #0x118] */
/* @0x2ae838 ldr r3, [sp, #0x4c] */
/* @0x2ae83a str.w r9, [r4, #0x108] */
/* @0x2ae83c .word 0xf8c49108 */
/* @0x2ae83e str.w r7, [r4, #0x10c] */
/* @0x2ae840 .word 0xf8c4710c */
/* @0x2ae842 str.w r3, [r4, #0x11c] */
/* @0x2ae844 mcr p1, #0x4, r3, c6, c12, #0x0 */
/* @0x2ae846 vdiv.f64 d6, d6, d7 */
/* @0x2ae848 .word 0xf8c46b07 */
/* @0x2ae84a str.w r6, [r4, #0x110] */
/* @0x2ae84c .word 0xf8c46110 */
/* @0x2ae84e str.w r5, [r4, #0x114] */
/* @0x2ae850 mrc p1, #0x5, r5, c7, c4, #0x0 */
/* @0x2ae852 vcvt.f32.f64 s12, d6 */
/* @0x2ae854 vstr d6, [r4, #792] */
/* @0x2ae856 vstr s12, [r4, #128] */
/* @0x2ae858 .word 0xeeb86a20 */
/* @0x2ae85a vcvt.f64.s32 d6, s11 */
/* @0x2ae85c vmls.f64 d6, d21, d21 */
/* @0x2ae85e vmov s11, r9 */
/* @0x2ae860 .word 0xee869a90 */
/* @0x2ae862 vdiv.f64 d6, d6, d7 */
/* @0x2ae864 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae866 vcvt.f32.f64 s12, d6 */
/* @0x2ae868 vstr d6, [r4, #792] */
/* @0x2ae86a vstr s12, [r4, #132] */
/* @0x2ae86c .word 0xeeb86a21 */
/* @0x2ae86e vcvt.f64.s32 d6, s11 */
/* @0x2ae870 vmls.f64 d6, d21, d21 */
/* @0x2ae872 vmov s11, r7 */
/* @0x2ae874 .word 0xee867a90 */
/* @0x2ae876 vdiv.f64 d6, d6, d7 */
/* @0x2ae878 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae87a vcvt.f32.f64 s12, d6 */
/* @0x2ae87c vstr d6, [r4, #792] */
/* @0x2ae87e vstr s12, [r4, #136] */
/* @0x2ae880 .word 0xeeb86a22 */
/* @0x2ae882 vcvt.f64.s32 d6, s11 */
/* @0x2ae884 vmls.f64 d6, d21, d21 */
/* @0x2ae886 vmov s11, r6 */
/* @0x2ae888 .word 0xee866a90 */
/* @0x2ae88a vdiv.f64 d6, d6, d7 */
/* @0x2ae88c vmov.f64 d6, #1.437500e+00 */
/* @0x2ae88e vcvt.f32.f64 s12, d6 */
/* @0x2ae890 vstr d6, [r4, #792] */
/* @0x2ae892 vstr s12, [r4, #140] */
/* @0x2ae894 .word 0xeeb86a23 */
/* @0x2ae896 vcvt.f64.s32 d6, s11 */
/* @0x2ae898 vmls.f64 d6, d21, d21 */
/* @0x2ae89a vmov s11, r5 */
/* @0x2ae89c .word 0xee865a90 */
/* @0x2ae89e vdiv.f64 d6, d6, d7 */
/* @0x2ae8a0 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae8a2 vcvt.f32.f64 s12, d6 */
/* @0x2ae8a4 vstr d6, [r4, #792] */
/* @0x2ae8a6 vstr s12, [r4, #144] */
/* @0x2ae8a8 .word 0xeeb86a24 */
/* @0x2ae8aa vcvt.f64.s32 d6, s11 */
/* @0x2ae8ac vldr d22, [sp, #916] */
/* @0x2ae8ae vldr s11, [sp, #72] */
/* @0x2ae8b0 .word 0xee865a12 */
/* @0x2ae8b2 vdiv.f64 d6, d6, d7 */
/* @0x2ae8b4 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae8b6 vcvt.f32.f64 s12, d6 */
/* @0x2ae8b8 vstr d6, [r4, #792] */
/* @0x2ae8ba vstr s12, [r4, #148] */
/* @0x2ae8bc .word 0xeeb86a25 */
/* @0x2ae8be vcvt.f64.s32 d6, s11 */
/* @0x2ae8c0 vmls.f64 d6, d21, d21 */
/* @0x2ae8c2 vmov s11, r3 */
/* @0x2ae8c4 stmvs r3!, {r4, r7, r9, r11, r12, sp} */
/* @0x2ae8c6 ldr r3, [r4, #0x8] */
/* @0x2ae8c8 orr r3, r3, #0x4 */
/* @0x2ae8cc str r3, [r4, #0x8] */
/* @0x2ae8ce vdiv.f64 d6, d6, d7 */
/* @0x2ae8d0 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae8d2 vcvt.f32.f64 s12, d6 */
/* @0x2ae8d4 vstr d6, [r4, #792] */
/* @0x2ae8d6 vstr s12, [r4, #152] */
/* @0x2ae8d8 .word 0xeeb86a26 */
/* @0x2ae8da vcvt.f64.s32 d6, s11 */
/* @0x2ae8dc .word 0xee866be5 */
/* @0x2ae8de vdiv.f64 d7, d6, d7 */
/* @0x2ae8e0 vmov.f64 d7, #1.437500e+00 */
/* @0x2ae8e2 vcvt.f32.f64 s14, d7 */
/* @0x2ae8e4 vstr d7, [r4, #796] */
/* @0x2ae8e6 vstr s14, [r4, #156] */
/* @0x2ae8e8 andlt r7, r6, r7, lsr #20 */
/* @0x2ae8ea add sp, #0x18 */
/* @0x2ae8ec pop.w {r4, r5, r6, r7, r9, r10, r11, pc} */
/* @0x2ae8f0 movs r0, r0 */
/* @0x2ae8f2 movs r0, r0 */
/* @0x2ae8f4 ldr r0, [r0, #0x20] */
/* @0x2ae8f6 lsrs r0, r7 */

/* ── FUNC 0x2ae8f8 · png_set_gAMA · size=144 · insn=54 */
/* @0x2ae8f8 push {r3, r4, r5, lr} */
/* @0x2ae8fa vpush {d8} */
/* @0x2ae8fc strmi r8, [r12], -r2, lsl #22 */
/* @0x2ae8fe mov r4, r1 */
/* @0x2ae900 vmov d7, r2, r3 */
/* @0x2ae904 mov r5, r0 */
/* @0x2ae906 cbz r0, 0x2ae964 <png_set_gAMA+0x6c> */
/* @0x2ae908 cbz r1, 0x2ae964 <png_set_gAMA+0x6c> */
/* @0x2ae90a vldr d8, [pc, #100] */
/* @0x2ae90c .word 0xeeb48b19 */
/* @0x2ae90e vcmpe.f64 d7, d8 */
/* @0x2ae910 vsqrt.f64 d23, d8 */
/* @0x2ae912 vmrs APSR_nzcv, fpscr */
/* @0x2ae914 vstrle s30, [r5, #-64] */
/* @0x2ae916 ble 0x2ae924 <png_set_gAMA+0x2c> */
/* @0x2ae918 ldr r1, [pc, #0x64] */
/* @0x2ae91a add r1, pc */
/* @0x2ae91c bl 0x2a6474 <png_warning> */
/* @0x2ae920 vmov.f64 d7, d8 */
/* @0x2ae924 vldr d5, [pc, #80] */
/* @0x2ae928 ldr r3, [r4, #0x8] */
/* @0x2ae92a vcvt.f32.f64 s13, d7 */
/* @0x2ae92c .word 0xf0436bc7 */
/* @0x2ae92e orr r3, r3, #0x1 */
/* @0x2ae930 adcvs r0, r3, r1, lsl #6 */
/* @0x2ae932 str r3, [r4, #0x8] */
/* @0x2ae934 vstr s13, [r4, #40] */
/* @0x2ae938 vmov.f64 d6, #5.000000e-01 */
/* @0x2ae93c vmla.f64 d6, d7, d5 */
/* @0x2ae940 vcvt.s32.f64 s12, d6 */
/* @0x2ae944 vcmp.f64 d7, #0 */
/* @0x2ae948 vstr s12, [r4, #252] */
/* @0x2ae94c vmrs APSR_nzcv, fpscr */
/* @0x2ae950 bne 0x2ae964 <png_set_gAMA+0x6c> */
/* @0x2ae952 vpop {d8} */
/* @0x2ae954 strtmi r8, [r8], -r2, lsl #22 */
/* @0x2ae956 mov r0, r5 */
/* @0x2ae958 ldr r1, [pc, #0x28] */
/* @0x2ae95a add r1, pc */
/* @0x2ae95c pop.w {r3, r4, r5, lr} */
/* @0x2ae960 b.w 0x2a6474 <png_warning> */
/* @0x2ae964 vpop {d8} */
/* @0x2ae968 pop {r3, r4, r5, pc} */
/* @0x2ae96a nop */
/* @0x2ae96c nop.w */
/* @0x2ae970 str r4, [r5, r7] */
/* @0x2ae972 subs r0, r7, #0x2 */
/* @0x2ae974 ldrh.w r4, [r5, #0xd4] */
/* @0x2ae978 movs r0, r0 */
/* @0x2ae97a movs r0, r0 */
/* @0x2ae97c ldr r0, [r0, #0x20] */
/* @0x2ae97e lsrs r0, r7 */
/* @0x2ae980 adcs r0, r12, #0xd */
/* @0x2ae984 .word 0xf137 000d */

/* ── FUNC 0x2ae988 · png_set_gAMA_fixed · size=124 · insn=50 */
/* @0x2ae988 push {r4, r5, r6, lr} */
/* @0x2ae98a mov r5, r1 */
/* @0x2ae98c mov r4, r2 */
/* @0x2ae98e mov r6, r0 */
/* @0x2ae990 cbz r0, 0x2ae9e8 <png_set_gAMA_fixed+0x60> */
/* @0x2ae992 cbz r1, 0x2ae9e8 <png_set_gAMA_fixed+0x60> */
/* @0x2ae994 mvn r3, #0x80000000 */
/* @0x2ae998 cmp r2, r3 */
/* @0x2ae99a bne 0x2ae9a6 <png_set_gAMA_fixed+0x1e> */
/* @0x2ae99c ldr r1, [pc, #0x58] */
/* @0x2ae99e add r1, pc */
/* @0x2ae9a0 bl 0x2a6474 <png_warning> */
/* @0x2ae9a4 b 0x2ae9b4 <png_set_gAMA_fixed+0x2c> */
/* @0x2ae9a6 cmp r2, #0x0 */
/* @0x2ae9a8 bge 0x2ae9b4 <png_set_gAMA_fixed+0x2c> */
/* @0x2ae9aa ldr r1, [pc, #0x50] */
/* @0x2ae9ac movs r4, #0x0 */
/* @0x2ae9ae add r1, pc */
/* @0x2ae9b0 bl 0x2a6474 <png_warning> */
/* @0x2ae9b4 vmov s15, r4 */
/* @0x2ae9b8 ldr r3, [r5, #0x8] */
/* @0x2ae9ba str.w r4, [r5, #0xfc] */
/* @0x2ae9bc mrc p0, #0x5, r4, c8, c12, #0x7 */
/* @0x2ae9be vcvt.f64.s32 d6, s15 */
/* @0x2ae9c0 vldr d6, [pc, #924] */
/* @0x2ae9c2 vldr d7, [pc, #44] */
/* @0x2ae9c4 .word 0xf0437b0b */
/* @0x2ae9c6 orr r3, r3, #0x1 */
/* @0x2ae9c8 adcvs r0, r11, r1, lsl #6 */
/* @0x2ae9ca str r3, [r5, #0x8] */
/* @0x2ae9cc vdiv.f64 d7, d6, d7 */
/* @0x2ae9d0 vcvt.f32.f64 s14, d7 */
/* @0x2ae9d4 vstr s14, [r5, #40] */
/* @0x2ae9d8 cbnz r4, 0x2ae9e8 <png_set_gAMA_fixed+0x60> */
/* @0x2ae9da ldr r1, [pc, #0x24] */
/* @0x2ae9dc mov r0, r6 */
/* @0x2ae9de pop.w {r4, r5, r6, lr} */
/* @0x2ae9e0 ldrbtmi r4, [r9], #-112 */
/* @0x2ae9e2 add r1, pc */
/* @0x2ae9e4 b.w 0x2a6474 <png_warning> */
/* @0x2ae9e8 pop {r4, r5, r6, pc} */
/* @0x2ae9ea nop */
/* @0x2ae9ec nop.w */
/* @0x2ae9f0 movs r0, r0 */
/* @0x2ae9f2 movs r0, r0 */
/* @0x2ae9f4 ldr r0, [r0, #0x20] */
/* @0x2ae9f6 lsrs r0, r7 */
/* @0x2ae9f8 .word 0xf0d8 000d */
/* @0x2ae9fc .word 0xf0f3 000d */
/* @0x2aea00 .word 0xf0af 000d */

/* ── FUNC 0x2aea04 · anon_2aea04 · size=0 · insn=1 */
/* @0x2aea04 andhi pc, r0, pc, lsr #7 */

/* ── FUNC 0x2aea08 · png_set_hIST · size=124 · insn=55 */
/* @0x2aea08 push {r4, r5, r6, lr} */
/* @0x2aea0a mov r4, r1 */
/* @0x2aea0c mov r6, r2 */
/* @0x2aea0e mov r5, r0 */
/* @0x2aea10 cbz r0, 0x2aea7a <png_set_hIST+0x72> */
/* @0x2aea12 cbz r1, 0x2aea7a <png_set_hIST+0x72> */
/* @0x2aea14 ldrh r3, [r1, #0x14] */
/* @0x2aea16 subs r3, #0x1 */
/* @0x2aea18 uxth r3, r3 */
/* @0x2aea1a cmp r3, #0xff */
/* @0x2aea1c bls 0x2aea24 <png_set_hIST+0x1c> */
/* @0x2aea1e ldr r1, [pc, #0x5c] */
/* @0x2aea20 add r1, pc */
/* @0x2aea22 b 0x2aea46 <png_set_hIST+0x3e> */
/* @0x2aea24 movs r2, #0x8 */
/* @0x2aea26 movs r3, #0x0 */
/* @0x2aea28 bl 0x2a5bc0 <png_free_data> */
/* @0x2aea2c mov r0, r5 */
/* @0x2aea2e mov.w r1, #0x200 */
/* @0x2aea30 .word 0xf7f87100 */
/* @0x2aea32 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aea34 .word 0xf8c5f970 */
/* @0x2aea36 str.w r0, [r5, #0x2b8] */
/* @0x2aea38 strhlt r0, [r8, -r8] */
/* @0x2aea3a cbz r0, 0x2aea40 <png_set_hIST+0x38> */
/* @0x2aea3c movs r3, #0x0 */
/* @0x2aea3e b 0x2aea4e <png_set_hIST+0x46> */
/* @0x2aea40 ldr r1, [pc, #0x3c] */
/* @0x2aea42 mov r0, r5 */
/* @0x2aea44 add r1, pc */
/* @0x2aea46 pop.w {r4, r5, r6, lr} */
/* @0x2aea48 .word 0xf7f74070 */
/* @0x2aea4a b.w 0x2a6474 <png_warning> */
/* @0x2aea4c bhi 0xfeb5dea0 <b2_toiTime+0xfffffffffe4049fc> */
/* @0x2aea4e ldrh r2, [r4, #0x14] */
/* @0x2aea50 ldr.w r1, [r5, #0x2b8] */
/* @0x2aea54 cmp r3, r2 */
/* @0x2aea56 bge 0x2aea64 <png_set_hIST+0x5c> */
/* @0x2aea58 ldrh.w r2, [r6, r3, lsl #1] */
/* @0x2aea5c strh.w r2, [r1, r3, lsl #1] */
/* @0x2aea60 adds r3, #0x1 */
/* @0x2aea62 b 0x2aea4e <png_set_hIST+0x46> */
/* @0x2aea64 ldr r3, [r4, #0x8] */
/* @0x2aea66 str r1, [r4, #0x7c] */
/* @0x2aea68 orr r3, r3, #0x40 */
/* @0x2aea6c str r3, [r4, #0x8] */
/* @0x2aea6e ldr.w r3, [r4, #0xb8] */
/* @0x2aea70 .word 0xf04330b8 */
/* @0x2aea72 orr r3, r3, #0x8 */
/* @0x2aea74 .word 0xf8c40308 */
/* @0x2aea76 str.w r3, [r4, #0xb8] */
/* @0x2aea78 ldcllt p0, c3, [r0, #-736]! */
/* @0x2aea7a pop {r4, r5, r6, pc} */
/* @0x2aea7c .word 0xf0a0 000d */
/* @0x2aea80 .word 0xf0aa 000d */

/* ── FUNC 0x2aea84 · png_set_IHDR · size=134 · insn=66 */
/* @0x2aea84 push {r4, r5, r6, r7, lr} */
/* @0x2aea86 sub sp, #0x14 */
/* @0x2aea88 mov r4, r1 */
/* @0x2aea8a mov r5, r2 */
/* @0x2aea8c ldr r6, [sp, #0x28] */
/* @0x2aea8e ldr.w r12, [sp, #0x2c] */
/* @0x2aea90 svcls #0xcc02c */
/* @0x2aea92 ldr r7, [sp, #0x30] */
/* @0x2aea94 ldr r1, [sp, #0x34] */
/* @0x2aea96 ldr r2, [sp, #0x38] */
/* @0x2aea98 cmp r0, #0x0 */
/* @0x2aea9a beq 0x2aeb06 <png_set_IHDR+0x82> */
/* @0x2aea9c cmp r4, #0x0 */
/* @0x2aea9e beq 0x2aeb06 <png_set_IHDR+0x82> */
/* @0x2aeaa0 str r3, [r4, #0x4] */
/* @0x2aeaa2 strb.w r12, [r4, #0x19] */
/* @0x2aeaa4 blx 0x1a9eb10 <b2_toiTime+0x134566c> */
/* @0x2aeaa6 uxtb.w r12, r12 */
/* @0x2aeaa8 strtvc pc, [r1], r12, lsl #25 */
/* @0x2aeaaa strb r1, [r4, #0x1a] */
/* @0x2aeaac uxtb r1, r1 */
/* @0x2aeaae strb r2, [r4, #0x1b] */
/* @0x2aeab0 uxtb r2, r2 */
/* @0x2aeab2 strb r7, [r4, #0x1c] */
/* @0x2aeab4 uxtb r7, r7 */
/* @0x2aeab6 str r1, [sp, #0x8] */
/* @0x2aeab8 mov r1, r5 */
/* @0x2aeaba str r2, [sp, #0xc] */
/* @0x2aeabc mov r2, r3 */
/* @0x2aeabe str r5, [r4] */
/* @0x2aeac0 uxtb r3, r6 */
/* @0x2aeac2 strb r6, [r4, #0x18] */
/* @0x2aeac4 str.w r12, [sp] */
/* @0x2aeac8 str r7, [sp, #0x4] */
/* @0x2aeaca bl 0x2a61b0 <png_check_IHDR> */
/* @0x2aeacc .word 0x7e63fb71 */
/* @0x2aeace ldrb r3, [r4, #0x19] */
/* @0x2aead0 cmp r3, #0x3 */
/* @0x2aead2 bne 0x2aead8 <png_set_IHDR+0x54> */
/* @0x2aead4 movs r2, #0x1 */
/* @0x2aead6 b 0x2aeade <png_set_IHDR+0x5a> */
/* @0x2aead8 lsls r2, r3, #0x1e */
/* @0x2aeada bpl 0x2aead4 <png_set_IHDR+0x50> */
/* @0x2aeadc movs r2, #0x3 */
/* @0x2aeade lsls r3, r3, #0x1d */
/* @0x2aeae0 strb r2, [r4, #0x1d] */
/* @0x2aeae2 bpl 0x2aeaea <png_set_IHDR+0x66> */
/* @0x2aeae4 ldrb r3, [r4, #0x1d] */
/* @0x2aeae6 adds r3, #0x1 */
/* @0x2aeae8 strb r3, [r4, #0x1d] */
/* @0x2aeaea ldrb r2, [r4, #0x18] */
/* @0x2aeaec ldrb r3, [r4, #0x1d] */
/* @0x2aeaee muls r3, r2, r3 */
/* @0x2aeaf0 uxtb r3, r3 */
/* @0x2aeaf2 strb r3, [r4, #0x1e] */
/* @0x2aeaf4 cmp r3, #0x7 */
/* @0x2aeaf6 bls 0x2aeafe <png_set_IHDR+0x7a> */
/* @0x2aeaf8 lsrs r3, r3, #0x3 */
/* @0x2aeafa muls r5, r3, r5 */
/* @0x2aeafc b 0x2aeb04 <png_set_IHDR+0x80> */
/* @0x2aeafe muls r5, r3, r5 */
/* @0x2aeb00 adds r5, #0x7 */
/* @0x2aeb02 lsrs r5, r5, #0x3 */
/* @0x2aeb04 str r5, [r4, #0xc] */
/* @0x2aeb06 add sp, #0x14 */
/* @0x2aeb08 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2aeb0a · png_set_oFFs · size=24 · insn=11 */
/* @0x2aeb0a cbz r0, 0x2aeb20 <png_set_oFFs+0x16> */
/* @0x2aeb0c cbz r1, 0x2aeb20 <png_set_oFFs+0x16> */
/* @0x2aeb0e str r3, [r1, #0x68] */
/* @0x2aeb10 ldr r3, [sp] */
/* @0x2aeb12 str r2, [r1, #0x64] */
/* @0x2aeb14 strb.w r3, [r1, #0x6c] */
/* @0x2aeb16 stmvs r11, {r2, r3, r5, r6, r12, sp} */
/* @0x2aeb18 ldr r3, [r1, #0x8] */
/* @0x2aeb1a orr r3, r3, #0x100 */
/* @0x2aeb1e str r3, [r1, #0x8] */
/* @0x2aeb20 bx lr */

/* ── FUNC 0x2aeb22 · anon_2aeb22 · size=0 · insn=1 */
/* @0x2aeb22 .word 0xe92d0000 */

/* ── FUNC 0x2aeb24 · png_set_pCAL · size=292 · insn=133 */
/* @0x2aeb24 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aeb28 mov r11, r3 */
/* @0x2aeb2a ldr r3, [sp, #0x30] */
/* @0x2aeb2c mov r4, r1 */
/* @0x2aeb2e ldr.w r9, [sp, #0x34] */
/* @0x2aeb30 .word 0x46059034 */
/* @0x2aeb32 mov r5, r0 */
/* @0x2aeb34 ldr r7, [sp, #0x38] */
/* @0x2aeb36 str r3, [sp, #0x4] */
/* @0x2aeb38 ldr r6, [sp, #0x3c] */
/* @0x2aeb3a ldr.w r8, [sp, #0x40] */
/* @0x2aeb3c stmdahs r0, {r6, pc} */
/* @0x2aeb3e cmp r0, #0x0 */
/* @0x2aeb40 beq 0x2aec32 <png_set_pCAL+0x10e> */
/* @0x2aeb42 cmp r1, #0x0 */
/* @0x2aeb44 beq 0x2aec32 <png_set_pCAL+0x10e> */
/* @0x2aeb46 mov r0, r2 */
/* @0x2aeb48 str r2, [sp] */
/* @0x2aeb4a blx 0xb6538 <strlen@plt> */
/* @0x2aeb4c .word 0xf100ecf6 */
/* @0x2aeb4e add.w r10, r0, #0x1 */
/* @0x2aeb50 strtmi r0, [r8], -r1, lsl #20 */
/* @0x2aeb52 mov r0, r5 */
/* @0x2aeb54 mov r1, r10 */
/* @0x2aeb56 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aeb58 bls 0x2eced8 <FT_Done_Memory+0x3264> */
/* @0x2aeb5a ldr r2, [sp] */
/* @0x2aeb5c str.w r0, [r4, #0xa0] */
/* @0x2aeb60 cbnz r0, 0x2aeb6a <png_set_pCAL+0x46> */
/* @0x2aeb62 ldr r1, [pc, #0xd4] */
/* @0x2aeb64 mov r0, r5 */
/* @0x2aeb66 add r1, pc */
/* @0x2aeb68 b 0x2aec14 <png_set_pCAL+0xf0> */
/* @0x2aeb6a mov r1, r2 */
/* @0x2aeb6c mov r2, r10 */
/* @0x2aeb6e blx 0xb65bc <memcpy@plt> */
/* @0x2aeb70 blls 0x32a010 */
/* @0x2aeb72 ldr r3, [sp, #0x4] */
/* @0x2aeb74 strb.w r9, [r4, #0xb4] */
/* @0x2aeb78 mov r0, r6 */
/* @0x2aeb7a str.w r11, [r4, #0xa4] */
/* @0x2aeb7c .word 0xf8c4b0a4 */
/* @0x2aeb7e str.w r3, [r4, #0xa8] */
/* @0x2aeb80 .word 0xf88430a8 */
/* @0x2aeb82 strb.w r7, [r4, #0xb5] */
/* @0x2aeb84 .word 0xf60770b5 */
/* @0x2aeb86 blx 0xb6538 <strlen@plt> */
/* @0x2aeb88 .word 0xf100ecd8 */
/* @0x2aeb8a add.w r9, r0, #0x1 */
/* @0x2aeb8c strtmi r0, [r8], -r1, lsl #18 */
/* @0x2aeb8e mov r0, r5 */
/* @0x2aeb90 mov r1, r9 */
/* @0x2aeb92 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aeb94 .word 0xf8c4f8c0 */
/* @0x2aeb96 str.w r0, [r4, #0xac] */
/* @0x2aeb98 ldmdblt r8, {r2, r3, r5, r7} */
/* @0x2aeb9a cbnz r0, 0x2aeba4 <png_set_pCAL+0x80> */
/* @0x2aeb9c ldr r1, [pc, #0x9c] */
/* @0x2aeb9e mov r0, r5 */
/* @0x2aeba0 add r1, pc */
/* @0x2aeba2 b 0x2aec14 <png_set_pCAL+0xf0> */
/* @0x2aeba4 mov r1, r6 */
/* @0x2aeba6 adds r6, r7, #0x1 */
/* @0x2aeba8 mov r2, r9 */
/* @0x2aebaa lsls r6, r6, #0x2 */
/* @0x2aebac blx 0xb65bc <memcpy@plt> */
/* @0x2aebb0 mov r0, r5 */
/* @0x2aebb2 mov r1, r6 */
/* @0x2aebb4 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aebb8 str.w r0, [r4, #0xb0] */
/* @0x2aebbc cbnz r0, 0x2aebc6 <png_set_pCAL+0xa2> */
/* @0x2aebbe ldr r1, [pc, #0x80] */
/* @0x2aebc0 mov r0, r5 */
/* @0x2aebc2 add r1, pc */
/* @0x2aebc4 b 0x2aec14 <png_set_pCAL+0xf0> */
/* @0x2aebc6 mov r2, r6 */
/* @0x2aebc8 movs r1, #0x0 */
/* @0x2aebca blx 0xb65b0 <memset@plt> */
/* @0x2aebcc .word 0xf1a8ecf2 */
/* @0x2aebce sub.w r8, r8, #0x4 */
/* @0x2aebd0 strhs r0, [r0], -r4, lsl #16 */
/* @0x2aebd2 movs r6, #0x0 */
/* @0x2aebd4 b 0x2aebe2 <png_set_pCAL+0xbe> */
/* @0x2aebd6 ldr r1, [r8, #4]! */
/* @0x2aebd8 strbmi r1, [r10], -r4, lsl #30 */
/* @0x2aebda mov r2, r9 */
/* @0x2aebdc blx 0xb65bc <memcpy@plt> */
/* @0x2aebe0 adds r6, #0x1 */
/* @0x2aebe2 cmp r6, r7 */
/* @0x2aebe4 bge 0x2aec1e <png_set_pCAL+0xfa> */
/* @0x2aebe6 ldr.w r0, [r8, #0x4] */
/* @0x2aebe8 .word 0xf6070004 */
/* @0x2aebea blx 0xb6538 <strlen@plt> */
/* @0x2aebec .word 0xf8d4eca6 */
/* @0x2aebee ldr.w r10, [r4, #0xb0] */
/* @0x2aebf0 .word 0xf100a0b0 */
/* @0x2aebf2 add.w r9, r0, #0x1 */
/* @0x2aebf4 strtmi r0, [r8], -r1, lsl #18 */
/* @0x2aebf6 mov r0, r5 */
/* @0x2aebf8 mov r1, r9 */
/* @0x2aebfa bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aebfc .word 0xf84af88c */
/* @0x2aebfe str.w r0, [r10, r6, lsl #2] */
/* @0x2aec00 .word 0xf8d40026 */
/* @0x2aec02 ldr.w r3, [r4, #0xb0] */
/* @0x2aec04 .word 0xf85330b0 */
/* @0x2aec06 ldr.w r0, [r3, r6, lsl #2] */
/* @0x2aec08 stmdahs r0, {r1, r2, r5} */
/* @0x2aec0a cmp r0, #0x0 */
/* @0x2aec0c bne 0x2aebd6 <png_set_pCAL+0xb2> */
/* @0x2aec0e ldr r1, [pc, #0x34] */
/* @0x2aec10 mov r0, r5 */
/* @0x2aec12 add r1, pc */
/* @0x2aec14 add sp, #0xc */
/* @0x2aec16 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aec18 .word 0xf7f74ff0 */
/* @0x2aec1a b.w 0x2a6474 <png_warning> */
/* @0x2aec1c stmvs r3!, {r0, r1, r3, r5, r10, r11, r12, sp, pc} */
/* @0x2aec1e ldr r3, [r4, #0x8] */
/* @0x2aec20 orr r3, r3, #0x400 */
/* @0x2aec24 str r3, [r4, #0x8] */
/* @0x2aec26 ldr.w r3, [r4, #0xb8] */
/* @0x2aec28 .word 0xf04330b8 */
/* @0x2aec2a orr r3, r3, #0x80 */
/* @0x2aec2c .word 0xf8c40380 */
/* @0x2aec2e str.w r3, [r4, #0xb8] */
/* @0x2aec30 strhlt r3, [r3], -r8 */
/* @0x2aec32 add sp, #0xc */
/* @0x2aec34 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aec38 vext.32 d0, d0, d13, #0x0 */
/* @0x2aec3c vaddl.s16 q0, d11, d13 */
/* @0x2aec40 vaddl.s16 q0, d12, d13 */
/* @0x2aec44 .word 0xef70 000d */

/* ── FUNC 0x2aec48 · png_set_sCAL · size=34 · insn=12 */
/* @0x2aec48 cbz r0, 0x2aec68 <png_set_sCAL+0x20> */
/* @0x2aec4a cbz r1, 0x2aec68 <png_set_sCAL+0x20> */
/* @0x2aec4c strb.w r2, [r1, #0xdc] */
/* @0x2aec50 ldrd r2, r3, [sp] */
/* @0x2aec54 strd r2, r3, [r1, #224] */
/* @0x2aec58 ldrd r2, r3, [sp, #8] */
/* @0x2aec5c strd r2, r3, [r1, #232] */
/* @0x2aec60 ldr r3, [r1, #0x8] */
/* @0x2aec62 orr r3, r3, #0x4000 */
/* @0x2aec64 addvs r4, r11, r0, lsl #7 */
/* @0x2aec66 str r3, [r1, #0x8] */
/* @0x2aec68 bx lr */
