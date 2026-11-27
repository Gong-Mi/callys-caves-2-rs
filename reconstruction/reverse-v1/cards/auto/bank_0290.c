/* libyoyo.so 覆盖卡组 0290
 * 函数 0x2e73a6..0x2e82f8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e73a6 · ft_hash_str_free · size=54 · insn=26 */
/* @0x2e73a6 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e73aa mov r7, r1 */
/* @0x2e73ac mov r4, r0 */
/* @0x2e73ae cbz r0, 0x2e73d8 <ft_hash_str_free+0x32> */
/* @0x2e73b0 ldr.w r8, [r0, #0x4] */
/* @0x2e73b2 strhs r8, [r0, #-0x4] */
/* @0x2e73b4 movs r5, #0x0 */
/* @0x2e73b6 ldr r6, [r0, #0x14] */
/* @0x2e73b8 mov r9, r5 */
/* @0x2e73ba cmp r5, r8 */
/* @0x2e73bc mov r0, r7 */
/* @0x2e73be beq 0x2e73ce <ft_hash_str_free+0x28> */
/* @0x2e73c0 ldr r1, [r6] */
/* @0x2e73c2 adds r5, #0x1 */
/* @0x2e73c4 bl 0x2e7336 <ft_mem_free> */
/* @0x2e73c6 .word 0xf846ffb7 */
/* @0x2e73c8 str r9, [r6], #4 */
/* @0x2e73ca ldrb r9, [r5, r4, lsl #22]! */
/* @0x2e73cc b 0x2e73ba <ft_hash_str_free+0x14> */
/* @0x2e73ce ldr r1, [r4, #0x14] */
/* @0x2e73d0 bl 0x2e7336 <ft_mem_free> */
/* @0x2e73d2 movwhs pc, #0xfb1 */
/* @0x2e73d4 movs r3, #0x0 */
/* @0x2e73d6 str r3, [r4, #0x14] */
/* @0x2e73d8 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e73da ldrblt r8, [r7, #0x3f8]! */

/* ── FUNC 0x2e73dc · FT_Stream_New · size=130 · insn=61 */
/* @0x2e73dc push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e73de movs r3, #0x0 */
/* @0x2e73e0 mov r5, r1 */
/* @0x2e73e2 mov r7, r2 */
/* @0x2e73e4 str r3, [r2] */
/* @0x2e73e6 cmp r0, #0x0 */
/* @0x2e73e8 beq 0x2e7454 <FT_Stream_New+0x78> */
/* @0x2e73ea cmp r1, #0x0 */
/* @0x2e73ec beq 0x2e7458 <FT_Stream_New+0x7c> */
/* @0x2e73ee ldr r6, [r0] */
/* @0x2e73f0 movs r1, #0x28 */
/* @0x2e73f2 add r2, sp, #0x4 */
/* @0x2e73f4 mov r0, r6 */
/* @0x2e73f6 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e73f8 blls 0x366e58 <_ZTS12CDS_Priority+0x8eb0> */
/* @0x2e73fa ldr r3, [sp, #0x4] */
/* @0x2e73fc mov r4, r0 */
/* @0x2e73fe cbnz r3, 0x2e7450 <FT_Stream_New+0x74> */
/* @0x2e7400 str r6, [r0, #0x1c] */
/* @0x2e7402 ldr r3, [r5] */
/* @0x2e7404 lsls r1, r3, #0x1f */
/* @0x2e7406 bpl 0x2e7412 <FT_Stream_New+0x36> */
/* @0x2e7408 ldr r1, [r5, #0x4] */
/* @0x2e740a ldr r2, [r5, #0x8] */
/* @0x2e740c bl 0x2e688a <FT_Stream_OpenMemory> */
/* @0x2e7410 b 0x2e743c <FT_Stream_New+0x60> */
/* @0x2e7412 lsls r2, r3, #0x1d */
/* @0x2e7414 bpl 0x2e7424 <FT_Stream_New+0x48> */
/* @0x2e7416 ldr r1, [r5, #0xc] */
/* @0x2e7418 bl 0x2e9bd4 <FT_Stream_Open> */
/* @0x2e741c ldr r3, [r5, #0xc] */
/* @0x2e741e str r3, [r4, #0x10] */
/* @0x2e7420 str r0, [sp, #0x4] */
/* @0x2e7422 b 0x2e743c <FT_Stream_New+0x60> */
/* @0x2e7424 lsls r3, r3, #0x1e */
/* @0x2e7426 bpl 0x2e7438 <FT_Stream_New+0x5c> */
/* @0x2e7428 ldr r3, [r5, #0x10] */
/* @0x2e742a cbz r3, 0x2e7438 <FT_Stream_New+0x5c> */
/* @0x2e742c mov r1, r4 */
/* @0x2e742e mov r0, r6 */
/* @0x2e7430 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7434 ldr r4, [r5, #0x10] */
/* @0x2e7436 b 0x2e743c <FT_Stream_New+0x60> */
/* @0x2e7438 movs r3, #0x6 */
/* @0x2e743a str r3, [sp, #0x4] */
/* @0x2e743c ldr r3, [sp, #0x4] */
/* @0x2e743e cbz r3, 0x2e744c <FT_Stream_New+0x70> */
/* @0x2e7440 mov r1, r4 */
/* @0x2e7442 mov r0, r6 */
/* @0x2e7444 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7448 movs r4, #0x0 */
/* @0x2e744a b 0x2e744e <FT_Stream_New+0x72> */
/* @0x2e744c str r6, [r4, #0x1c] */
/* @0x2e744e str r4, [r7] */
/* @0x2e7450 ldr r0, [sp, #0x4] */
/* @0x2e7452 b 0x2e745a <FT_Stream_New+0x7e> */
/* @0x2e7454 movs r0, #0x21 */
/* @0x2e7456 b 0x2e745a <FT_Stream_New+0x7e> */
/* @0x2e7458 movs r0, #0x6 */
/* @0x2e745a add sp, #0xc */
/* @0x2e745c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e745e · FT_Stream_Free · size=30 · insn=13 */
/* @0x2e745e push {r4, r5, r6, lr} */
/* @0x2e7460 mov r6, r1 */
/* @0x2e7462 mov r4, r0 */
/* @0x2e7464 cbz r0, 0x2e747a <FT_Stream_Free+0x1c> */
/* @0x2e7466 ldr r5, [r0, #0x1c] */
/* @0x2e7468 bl 0x2e689a <FT_Stream_Close> */
/* @0x2e746a stmdblt lr!, {r0, r1, r2, r4, r9, r11, r12, sp, lr, pc} */
/* @0x2e746c cbnz r6, 0x2e747a <FT_Stream_Free+0x1c> */
/* @0x2e746e mov r0, r5 */
/* @0x2e7470 mov r1, r4 */
/* @0x2e7472 pop.w {r4, r5, r6, lr} */
/* @0x2e7476 b.w 0x2e7336 <ft_mem_free> */
/* @0x2e747a pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e747e · anon_2e747e · size=60 · insn=16 */
/* @0x2e747e movwhs r11, #0x408a */
/* @0x2e7482 .word 0x91054614 */
/* @0x2e7486 andeq lr, r3, #13312 */
/* @0x2e748a movwls r10, #0x2902 */
/* @0x2e748e .word 0xffa5f7ff */
/* @0x2e7492 stmdals r1, {r3, r5, r6, r8, r11, r12, sp, pc} */
/* @0x2e7496 strtmi r11, [r2], -r8, lsr #2 */
/* @0x2e749a .word 0xf7ff4907 */
/* @0x2e749e .word 0x4604fcbe */
/* @0x2e74a2 ldrbhs lr, [r1], #-0 */
/* @0x2e74a6 .word 0x21009801 */
/* @0x2e74aa .word 0xffd8f7ff */
/* @0x2e74ae strmi lr, [r4], -r0 */
/* @0x2e74b2 andlt r4, r10, r0, lsr #12 */
/* @0x2e74b6 .word 0x1607bd10 */
/* @0x2e74ba ldrblt r0, [r3, #-0x5]! */

/* ── FUNC 0x2e74bc · FT_Attach_Stream · size=70 · insn=32 */
/* @0x2e74bc push {r0, r1, r4, r5, r6, lr} */
/* @0x2e74be mov r6, r1 */
/* @0x2e74c0 mov r4, r0 */
/* @0x2e74c2 cbz r0, 0x2e74f8 <FT_Attach_Stream+0x3c> */
/* @0x2e74c4 ldr r5, [r0, #0x60] */
/* @0x2e74c6 cbz r5, 0x2e74fc <FT_Attach_Stream+0x40> */
/* @0x2e74c8 ldr r0, [r5, #0x4] */
/* @0x2e74ca add r2, sp, #0x4 */
/* @0x2e74cc bl 0x2e73dc <FT_Stream_New> */
/* @0x2e74d0 cbnz r0, 0x2e74fe <FT_Attach_Stream+0x42> */
/* @0x2e74d2 ldr r3, [r5, #0xc] */
/* @0x2e74d4 ldr r3, [r3, #0x50] */
/* @0x2e74d6 cbz r3, 0x2e74e2 <FT_Attach_Stream+0x26> */
/* @0x2e74d8 mov r0, r4 */
/* @0x2e74da ldr r1, [sp, #0x4] */
/* @0x2e74dc blx r3 */
/* @0x2e74de mov r4, r0 */
/* @0x2e74e0 b 0x2e74e4 <FT_Attach_Stream+0x28> */
/* @0x2e74e2 movs r4, #0x7 */
/* @0x2e74e4 ldr r1, [r6, #0x10] */
/* @0x2e74e6 ldr r0, [sp, #0x4] */
/* @0x2e74e8 cbz r1, 0x2e74f0 <FT_Attach_Stream+0x34> */
/* @0x2e74ea ldr r1, [r6] */
/* @0x2e74ec ubfx r1, r1, #0x1, #0x1 */
/* @0x2e74f0 bl 0x2e745e <FT_Stream_Free> */
/* @0x2e74f4 mov r0, r4 */
/* @0x2e74f6 b 0x2e74fe <FT_Attach_Stream+0x42> */
/* @0x2e74f8 movs r0, #0x23 */
/* @0x2e74fa b 0x2e74fe <FT_Attach_Stream+0x42> */
/* @0x2e74fc movs r0, #0x22 */
/* @0x2e74fe add sp, #0x8 */
/* @0x2e7500 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e7502 · FT_Attach_File · size=32 · insn=15 */
/* @0x2e7502 push {lr} */
/* @0x2e7504 sub sp, #0x24 */
/* @0x2e7506 cbz r1, 0x2e751a <FT_Attach_File+0x18> */
/* @0x2e7508 str r1, [sp, #0xc] */
/* @0x2e750a mov r1, sp */
/* @0x2e750c movs r3, #0x0 */
/* @0x2e750e str r3, [sp, #0x10] */
/* @0x2e7510 movs r3, #0x4 */
/* @0x2e7512 str r3, [sp] */
/* @0x2e7514 bl 0x2e74bc <FT_Attach_Stream> */
/* @0x2e7516 .word 0xe000ffd2 */
/* @0x2e7518 b 0x2e751c <FT_Attach_File+0x1a> */
/* @0x2e751a movs r0, #0x6 */
/* @0x2e751c add sp, #0x24 */
/* @0x2e751e ldr pc, [sp], #4 */

/* ── FUNC 0x2e7522 · ft_glyphslot_free_bitmap · size=50 · insn=23 */
/* @0x2e7522 push {r4, lr} */
/* @0x2e7524 mov r4, r0 */
/* @0x2e7526 ldr.w r3, [r0, #0x9c] */
/* @0x2e752a cbz r3, 0x2e754e <ft_glyphslot_free_bitmap+0x2c> */
/* @0x2e752c ldr r3, [r3, #0x4] */
/* @0x2e752e lsls r3, r3, #0x1f */
/* @0x2e7530 bpl 0x2e754e <ft_glyphslot_free_bitmap+0x2c> */
/* @0x2e7532 ldr r3, [r0, #0x4] */
/* @0x2e7534 ldr r1, [r4, #0x58] */
/* @0x2e7536 ldr r0, [r3, #0x64] */
/* @0x2e7538 bl 0x2e7336 <ft_mem_free> */
/* @0x2e753a movwhs pc, #0xefd */
/* @0x2e753c movs r3, #0x0 */
/* @0x2e753e str r3, [r4, #0x58] */
/* @0x2e7540 ldr.w r3, [r4, #0x9c] */
/* @0x2e7542 ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^ */
/* @0x2e7544 ldr r2, [r3, #0x4] */
/* @0x2e7546 bic r2, r2, #0x1 */
/* @0x2e754a str r2, [r3, #0x4] */
/* @0x2e754c pop {r4, pc} */
/* @0x2e754e movs r3, #0x0 */
/* @0x2e7550 str r3, [r4, #0x58] */
/* @0x2e7552 pop {r4, pc} */

/* ── FUNC 0x2e7554 · ft_glyphslot_set_bitmap · size=14 · insn=7 */
/* @0x2e7554 push {r3, r4, r5, lr} */
/* @0x2e7556 mov r4, r0 */
/* @0x2e7558 mov r5, r1 */
/* @0x2e755a bl 0x2e7522 <ft_glyphslot_free_bitmap> */
/* @0x2e755c strvs pc, [r5, #0xfe2]! */
/* @0x2e755e str r5, [r4, #0x58] */
/* @0x2e7560 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e7564 · FT_Load_Glyph · size=808 · insn=369 */
/* @0x2e7564 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e7568 mov r10, r1 */
/* @0x2e756a sub sp, #0x14 */
/* @0x2e756c mov r5, r2 */
/* @0x2e756e mov r6, r0 */
/* @0x2e7570 cmp r0, #0x0 */
/* @0x2e7572 beq 0x2e7672 <FT_Load_Glyph+0x10e> */
/* @0x2e7574 ldr r3, [r0, #0x58] */
/* @0x2e7576 cmp r3, #0x0 */
/* @0x2e7578 beq 0x2e7672 <FT_Load_Glyph+0x10e> */
/* @0x2e757a ldr r4, [r0, #0x54] */
/* @0x2e757c cmp r4, #0x0 */
/* @0x2e757e beq 0x2e7672 <FT_Load_Glyph+0x10e> */
/* @0x2e7580 mov r0, r4 */
/* @0x2e7582 add.w r8, r4, #0x6c */
/* @0x2e7584 .word 0xf7ff086c */
/* @0x2e7586 bl 0x2e7522 <ft_glyphslot_free_bitmap> */
/* @0x2e7588 smlabths r0, r12, pc, pc */
/* @0x2e758a movs r1, #0x0 */
/* @0x2e758c movs r2, #0x20 */
/* @0x2e758e add.w r0, r4, #0x18 */
/* @0x2e7590 .word 0xf5cf0018 */
/* @0x2e7592 blx 0xb65b0 <memset@plt> */
/* @0x2e7594 andshs lr, r4, #917504 */
/* @0x2e7596 movs r2, #0x14 */
/* @0x2e7598 mov r0, r8 */
/* @0x2e759a movs r1, #0x0 */
/* @0x2e759c blx 0xb65b0 <memset@plt> */
/* @0x2e75a0 movs r7, #0x0 */
/* @0x2e75a2 str r7, [r4, #0x50] */
/* @0x2e75a4 lsls r2, r5, #0x15 */
/* @0x2e75a6 str r7, [r4, #0x4c] */
/* @0x2e75a8 it mi */
/* @0x2e75aa orrmi r5, r5, #0x800 */
/* @0x2e75ac strbvs r6, [r7, #-0x500]! */
/* @0x2e75ae str r7, [r4, #0x54] */
/* @0x2e75b0 it mi */
/* @0x2e75b2 orrmi r5, r5, #0x1 */
/* @0x2e75b4 .word 0xf8840501 */
/* @0x2e75b6 strb.w r7, [r4, #0x5e] */
/* @0x2e75b8 uqsaxvs r7, r7, lr */
/* @0x2e75ba str r7, [r4, #0x64] */
/* @0x2e75bc str r7, [r4, #0x68] */
/* @0x2e75be str.w r7, [r4, #0x80] */
/* @0x2e75c0 .word 0xf8c47080 */
/* @0x2e75c2 str.w r7, [r4, #0x84] */
/* @0x2e75c4 .word 0xf8c47084 */
/* @0x2e75c6 str.w r7, [r4, #0x88] */
/* @0x2e75c8 .word 0xf8c47088 */
/* @0x2e75ca str.w r7, [r4, #0x8c] */
/* @0x2e75cc .word 0xf8c4708c */
/* @0x2e75ce str.w r7, [r4, #0x98] */
/* @0x2e75d0 strtvs r7, [r7], #152 */
/* @0x2e75d2 str r7, [r4, #0x48] */
/* @0x2e75d4 str r7, [r4, #0x38] */
/* @0x2e75d6 str r7, [r4, #0x3c] */
/* @0x2e75d8 str.w r7, [r4, #0x90] */
/* @0x2e75dc str.w r7, [r4, #0x94] */
/* @0x2e75e0 ldr r7, [r6, #0x60] */
/* @0x2e75e2 ldr r3, [r7, #0x4] */
/* @0x2e75e4 ldr.w r9, [r3, #0xa0] */
/* @0x2e75e8 lsls r3, r5, #0x1f */
/* @0x2e75ea itt mi */
/* @0x2e75ec bicmi r5, r5, #0x4 */
/* @0x2e75f0 orrmi r5, r5, #0xa */
/* @0x2e75f4 lsls r0, r5, #0x9 */
/* @0x2e75f6 it mi */
/* @0x2e75f8 bicmi r5, r5, #0x4 */
/* @0x2e75fc cmp.w r9, #0x0 */
/* @0x2e7600 beq 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7602 movw r3, #0x8002 */
/* @0x2e7604 eormi r0, r11, r2, lsl #6 */
/* @0x2e7606 ands r3, r5 */
/* @0x2e7608 cmp r3, #0x0 */
/* @0x2e760a bne 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e760c ldr r2, [r7] */
/* @0x2e760e ldr r3, [r2] */
/* @0x2e7610 and r3, r3, #0x300 */
/* @0x2e7614 cmp.w r3, #0x100 */
/* @0x2e7618 bne 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e761a ldr r3, [r6, #0x8] */
/* @0x2e761c lsls r1, r3, #0x12 */
/* @0x2e761e bmi 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7620 lsls r0, r5, #0x14 */
/* @0x2e7622 bmi 0x2e7634 <FT_Load_Glyph+0xd0> */
/* @0x2e7624 ldr.w r1, [r6, #0x80] */
/* @0x2e7628 ldr r0, [r1, #0x8] */
/* @0x2e762a ldr r1, [r1] */
/* @0x2e762c cbnz r0, 0x2e7632 <FT_Load_Glyph+0xce> */
/* @0x2e762e cbnz r1, 0x2e7634 <FT_Load_Glyph+0xd0> */
/* @0x2e7630 b 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7632 cbnz r1, 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7634 lsls r1, r5, #0x1a */
/* @0x2e7636 bmi.w 0x2e7824 <FT_Load_Glyph+0x2c0> */
/* @0x2e7638 ldmdavs r2, {r0, r2, r4, r5, r6, r7, pc} */
/* @0x2e763a ldr r2, [r2] */
/* @0x2e763c lsls r0, r2, #0x15 */
/* @0x2e763e bpl.w 0x2e7824 <FT_Load_Glyph+0x2c0> */
/* @0x2e7640 .word 0xf3c580f1 */
/* @0x2e7642 ubfx r1, r5, #0x10, #0x4 */
/* @0x2e7644 stmdbhs r1, {r0, r1, r8, lr} */
/* @0x2e7646 cmp r1, #0x1 */
/* @0x2e7648 bne 0x2e7650 <FT_Load_Glyph+0xec> */
/* @0x2e764a lsls r1, r2, #0x14 */
/* @0x2e764c bpl.w 0x2e7824 <FT_Load_Glyph+0x2c0> */
/* @0x2e7650 lsls r2, r3, #0x1c */
/* @0x2e7652 bpl 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7654 ldr.w r2, [r6, #0x2d4] */
/* @0x2e7658 cbz r2, 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e765a ldrh.w r2, [r6, #0x11e] */
/* @0x2e765c ldmdblt r2, {r1, r2, r3, r4, r8, sp} ^ */
/* @0x2e765e cbnz r2, 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7660 ldr.w r2, [r6, #0x284] */
/* @0x2e7664 cbnz r2, 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7666 ldr.w r2, [r6, #0x28c] */
/* @0x2e7668 bhs 0x2f00a0 <FT_Done_Memory+0x642c> */
/* @0x2e766a cmp r2, #0x0 */
/* @0x2e766c beq.w 0x2e7824 <FT_Load_Glyph+0x2c0> */
/* @0x2e7670 b 0x2e7676 <FT_Load_Glyph+0x112> */
/* @0x2e7672 movs r0, #0x23 */
/* @0x2e7674 b 0x2e7878 <FT_Load_Glyph+0x314> */
/* @0x2e7676 ldr r3, [r7, #0xc] */
/* @0x2e7678 mov r0, r4 */
/* @0x2e767a ldr r1, [r6, #0x58] */
/* @0x2e767c mov r2, r10 */
/* @0x2e767e ldr r7, [r3, #0x48] */
/* @0x2e7680 mov r3, r5 */
/* @0x2e7682 blx r7 */
/* @0x2e7684 cmp r0, #0x0 */
/* @0x2e7686 bne.w 0x2e7878 <FT_Load_Glyph+0x314> */
/* @0x2e7688 stcvs p0, c8, [r3], #988 */
/* @0x2e768a ldr r3, [r4, #0x48] */
/* @0x2e768c ldr r2, [pc, #0x1f0] */
/* @0x2e768e cmp r3, r2 */
/* @0x2e7690 beq 0x2e7696 <FT_Load_Glyph+0x132> */
/* @0x2e7692 movs r7, #0x0 */
/* @0x2e7694 b 0x2e773e <FT_Load_Glyph+0x1da> */
/* @0x2e7696 mov r0, r8 */
/* @0x2e7698 bl 0x2e631e <FT_Outline_Check> */
/* @0x2e769c mov r7, r0 */
/* @0x2e769e cmp r0, #0x0 */
/* @0x2e76a0 bne.w 0x2e7820 <FT_Load_Glyph+0x2bc> */
/* @0x2e76a4 lsls r0, r5, #0x1e */
/* @0x2e76a6 bmi 0x2e7692 <FT_Load_Glyph+0x12e> */
/* @0x2e76a8 tst.w r5, #0x10 */
/* @0x2e76ac ldr r2, [r4, #0x20] */
/* @0x2e76ae ldr r3, [r4, #0x24] */
/* @0x2e76b0 ldr r0, [r4, #0x2c] */
/* @0x2e76b2 ldr.w r12, [r4, #0x18] */
/* @0x2e76b4 blvs 0xb5771c <b2_toiTime+0x3fe278> */
/* @0x2e76b6 ldr r1, [r4, #0x30] */
/* @0x2e76b8 beq 0x2e76f4 <FT_Load_Glyph+0x190> */
/* @0x2e76ba adds r3, #0x3f */
/* @0x2e76bc add r12, r0 */
/* @0x2e76be bic r3, r3, #0x3f */
/* @0x2e76c0 rsbvs r0, r3, #-67108864 */
/* @0x2e76c2 str r3, [r4, #0x24] */
/* @0x2e76c4 ldr r3, [r4, #0x1c] */
/* @0x2e76c6 add.w r12, r12, #0x3f */
/* @0x2e76c8 .word 0xf0200c3f */
/* @0x2e76ca bic r0, r0, #0x3f */
/* @0x2e76cc .word 0xf02c003f */
/* @0x2e76ce bic r12, r12, #0x3f */
/* @0x2e76d0 strmi r0, [r11], #-3135 */
/* @0x2e76d2 add r3, r1 */
/* @0x2e76d4 bic r1, r1, #0x3f */
/* @0x2e76d8 adds r3, #0x3f */
/* @0x2e76da bic r2, r2, #0x3f */
/* @0x2e76dc .word 0xf023023f */
/* @0x2e76de bic r3, r3, #0x3f */
/* @0x2e76e0 rscvs r0, r0, #-67108864 */
/* @0x2e76e2 str r0, [r4, #0x2c] */
/* @0x2e76e4 str r1, [r4, #0x30] */
/* @0x2e76e6 rsb r0, r0, r12 */
/* @0x2e76e8 bne 0x1927720 <b2_toiTime+0x11ce27c> */
/* @0x2e76ea subs r1, r3, r1 */
/* @0x2e76ec str r2, [r4, #0x20] */
/* @0x2e76ee str r0, [r4, #0x18] */
/* @0x2e76f0 str r1, [r4, #0x1c] */
/* @0x2e76f2 b 0x2e772a <FT_Load_Glyph+0x1c6> */
/* @0x2e76f4 bic r1, r1, #0x3f */
/* @0x2e76f8 str r1, [r4, #0x30] */
/* @0x2e76fa ldr r1, [r4, #0x1c] */
/* @0x2e76fc add r12, r2 */
/* @0x2e76fe add.w r12, r12, #0x3f */
/* @0x2e7700 .word 0xf0220c3f */
/* @0x2e7702 bic r2, r2, #0x3f */
/* @0x2e7704 bne 0x1928008 <b2_toiTime+0x11ceb64> */
/* @0x2e7706 subs r1, r3, r1 */
/* @0x2e7708 adds r3, #0x3f */
/* @0x2e770a bic r3, r3, #0x3f */
/* @0x2e770c .word 0xf02c033f */
/* @0x2e770e bic r12, r12, #0x3f */
/* @0x2e7710 .word 0xf0210c3f */
/* @0x2e7712 bic r1, r1, #0x3f */
/* @0x2e7714 .word 0xf020013f */
/* @0x2e7716 bic r0, r0, #0x3f */
/* @0x2e7718 eorvs r0, r2, #63 */
/* @0x2e771a str r2, [r4, #0x20] */
/* @0x2e771c rsb r2, r2, r12 */
/* @0x2e7720 str r3, [r4, #0x24] */
/* @0x2e7722 subs r3, r3, r1 */
/* @0x2e7724 str r0, [r4, #0x2c] */
/* @0x2e7726 str r2, [r4, #0x18] */
/* @0x2e7728 str r3, [r4, #0x1c] */
/* @0x2e772a ldr r3, [r4, #0x28] */
/* @0x2e772c adds r3, #0x20 */
/* @0x2e772e bic r3, r3, #0x3f */
/* @0x2e7730 adcvs r0, r3, #-67108864 */
/* @0x2e7732 str r3, [r4, #0x28] */
/* @0x2e7734 ldr r3, [r4, #0x34] */
/* @0x2e7736 adds r3, #0x20 */
/* @0x2e7738 bic r3, r3, #0x3f */
/* @0x2e773c str r3, [r4, #0x34] */
/* @0x2e773e ands r2, r5, #0x10 */
/* @0x2e7740 andle r0, r4, r0, lsl r2 */
/* @0x2e7742 beq 0x2e774e <FT_Load_Glyph+0x1ea> */
/* @0x2e7744 movs r3, #0x0 */
/* @0x2e7746 str r3, [r4, #0x40] */
/* @0x2e7748 ldr r3, [r4, #0x34] */
/* @0x2e774a str r3, [r4, #0x44] */
/* @0x2e774c b 0x2e7754 <FT_Load_Glyph+0x1f0> */
/* @0x2e774e ldr r3, [r4, #0x28] */
/* @0x2e7750 str r2, [r4, #0x44] */
/* @0x2e7752 str r3, [r4, #0x40] */
/* @0x2e7754 lsls r1, r5, #0x12 */
/* @0x2e7756 bmi 0x2e777e <FT_Load_Glyph+0x21a> */
/* @0x2e7758 ldr r3, [r6, #0x8] */
/* @0x2e775a lsls r2, r3, #0x1f */
/* @0x2e775c bpl 0x2e777e <FT_Load_Glyph+0x21a> */
/* @0x2e775e ldr.w r9, [r6, #0x58] */
/* @0x2e7760 subhs r9, r0, #88 */
/* @0x2e7762 movs r2, #0x40 */
/* @0x2e7764 ldr r0, [r4, #0x38] */
/* @0x2e7766 ldr.w r1, [r9, #0x10] */
/* @0x2e7768 .word 0xf7fd1010 */
/* @0x2e776a bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e776c subhs pc, r0, #946176 */
/* @0x2e776e movs r2, #0x40 */
/* @0x2e7770 str r0, [r4, #0x38] */
/* @0x2e7772 ldr r0, [r4, #0x3c] */
/* @0x2e7774 ldr.w r1, [r9, #0x14] */
/* @0x2e7778 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e777c str r0, [r4, #0x3c] */
/* @0x2e777e lsls r3, r5, #0x14 */
/* @0x2e7780 bmi 0x2e77f0 <FT_Load_Glyph+0x28c> */
/* @0x2e7782 ldr.w r6, [r6, #0x80] */
/* @0x2e7784 ldmibvs r3!, {r7, sp, lr} */
/* @0x2e7786 ldr r3, [r6, #0x18] */
/* @0x2e7788 cmp r3, #0x0 */
/* @0x2e778a beq 0x2e77f0 <FT_Load_Glyph+0x28c> */
/* @0x2e778c ldr r3, [r4, #0x4] */
/* @0x2e778e ldr r3, [r3, #0x60] */
/* @0x2e7790 ldr r0, [r3, #0x4] */
/* @0x2e7792 ldr.w r3, [r0, #0x9c] */
/* @0x2e7794 .word 0xb11b309c */
/* @0x2e7796 cbz r3, 0x2e77a0 <FT_Load_Glyph+0x23c> */
/* @0x2e7798 ldr r1, [r3, #0x10] */
/* @0x2e779a ldr r2, [r4, #0x48] */
/* @0x2e779c cmp r1, r2 */
/* @0x2e779e beq 0x2e77ac <FT_Load_Glyph+0x248> */
/* @0x2e77a0 ldr r1, [r4, #0x48] */
/* @0x2e77a2 movs r2, #0x0 */
/* @0x2e77a4 bl 0x2e5e36 <FT_Lookup_Renderer> */
/* @0x2e77a8 mov r3, r0 */
/* @0x2e77aa cbz r0, 0x2e77c0 <FT_Load_Glyph+0x25c> */
/* @0x2e77ac ldr r2, [r3, #0xc] */
/* @0x2e77ae mov r0, r3 */
/* @0x2e77b0 mov r1, r4 */
/* @0x2e77b2 add.w r3, r6, #0x10 */
/* @0x2e77b4 bvs 0xff8a83fc <b2_toiTime+0xffffffffff14ef58> */
/* @0x2e77b6 ldr r7, [r2, #0x2c] */
/* @0x2e77b8 mov r2, r6 */
/* @0x2e77ba blx r7 */
/* @0x2e77bc mov r7, r0 */
/* @0x2e77be b 0x2e77e6 <FT_Load_Glyph+0x282> */
/* @0x2e77c0 ldr r3, [r4, #0x48] */
/* @0x2e77c2 ldr r2, [pc, #0xbc] */
/* @0x2e77c4 cmp r3, r2 */
/* @0x2e77c6 bne 0x2e77e6 <FT_Load_Glyph+0x282> */
/* @0x2e77c8 ldr r3, [r6, #0x18] */
/* @0x2e77ca lsls r0, r3, #0x1f */
/* @0x2e77cc bpl 0x2e77d6 <FT_Load_Glyph+0x272> */
/* @0x2e77ce mov r0, r8 */
/* @0x2e77d0 mov r1, r6 */
/* @0x2e77d2 bl 0x2e6580 <FT_Outline_Transform> */
/* @0x2e77d4 ldmibvs r3!, {r0, r2, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e77d6 ldr r3, [r6, #0x18] */
/* @0x2e77d8 lsls r1, r3, #0x1e */
/* @0x2e77da bpl 0x2e77e6 <FT_Load_Glyph+0x282> */
/* @0x2e77dc mov r0, r8 */
/* @0x2e77de ldr r1, [r6, #0x10] */
/* @0x2e77e0 ldr r2, [r6, #0x14] */
/* @0x2e77e2 bl 0x2e6424 <FT_Outline_Translate> */
/* @0x2e77e4 .word 0xf104fe1f */
/* @0x2e77e6 add.w r0, r4, #0x40 */
/* @0x2e77e8 ldrtmi r0, [r1], -r0, asr #32 */
/* @0x2e77ea mov r1, r6 */
/* @0x2e77ec bl 0x2e6548 <FT_Vector_Transform> */
/* @0x2e77f0 cbnz r7, 0x2e7820 <FT_Load_Glyph+0x2bc> */
/* @0x2e77f2 ldr r3, [r4, #0x48] */
/* @0x2e77f4 ldr r2, [pc, #0x8c] */
/* @0x2e77f6 cmp r3, r2 */
/* @0x2e77f8 beq 0x2e7820 <FT_Load_Glyph+0x2bc> */
/* @0x2e77fa ldr r2, [pc, #0x8c] */
/* @0x2e77fc cmp r3, r2 */
/* @0x2e77fe beq 0x2e7820 <FT_Load_Glyph+0x2bc> */
/* @0x2e7800 lsls r2, r5, #0x1d */
/* @0x2e7802 bpl 0x2e7820 <FT_Load_Glyph+0x2bc> */
/* @0x2e7804 ubfx r1, r5, #0x10, #0x4 */
/* @0x2e7808 cbnz r1, 0x2e7814 <FT_Load_Glyph+0x2b0> */
/* @0x2e780a tst.w r5, #0x1000 */
/* @0x2e780c svclt #0xc5f80 */
/* @0x2e780e ite eq */
/* @0x2e7810 moveq r1, #0x0 */
/* @0x2e7812 movne r1, #0x2 */
/* @0x2e7814 mov r0, r4 */
/* @0x2e7816 add sp, #0x14 */
/* @0x2e7818 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e781c b.w 0x2e5ed8 <FT_Render_Glyph> */
/* @0x2e7820 mov r0, r7 */
/* @0x2e7822 b 0x2e7878 <FT_Load_Glyph+0x314> */
/* @0x2e7824 lsls r3, r3, #0x1e */
/* @0x2e7826 bpl 0x2e782c <FT_Load_Glyph+0x2c8> */
/* @0x2e7828 lsls r3, r5, #0x1c */
/* @0x2e782a bpl 0x2e785a <FT_Load_Glyph+0x2f6> */
/* @0x2e782c ldr.w r11, [r6, #0x80] */
/* @0x2e7830 mov r0, r9 */
/* @0x2e7832 mov r1, r4 */
/* @0x2e7834 ldr.w r3, [r11, #0x18] */
/* @0x2e7838 str r3, [sp, #0xc] */
/* @0x2e783a movs r3, #0x0 */
/* @0x2e783c str.w r3, [r11, #0x18] */
/* @0x2e7840 ldr.w r3, [r9] */
/* @0x2e7844 ldr r3, [r3, #0x14] */
/* @0x2e7846 str r5, [sp] */
/* @0x2e7848 ldr r2, [r6, #0x58] */
/* @0x2e784a ldr r7, [r3, #0xc] */
/* @0x2e784c mov r3, r10 */
/* @0x2e784e blx r7 */
/* @0x2e7850 ldr r3, [sp, #0xc] */
/* @0x2e7852 str.w r3, [r11, #0x18] */
/* @0x2e7854 .word 0x46073018 */
/* @0x2e7856 mov r7, r0 */
/* @0x2e7858 b 0x2e773e <FT_Load_Glyph+0x1da> */
/* @0x2e785a ldr r3, [r7, #0xc] */
/* @0x2e785c mov r0, r4 */
/* @0x2e785e ldr r1, [r6, #0x58] */
/* @0x2e7860 mov r2, r10 */
/* @0x2e7862 ldr r7, [r3, #0x48] */
/* @0x2e7864 orr r3, r5, #0x4000 */
/* @0x2e7868 blx r7 */
/* @0x2e786a cmp r0, #0x0 */
/* @0x2e786c bne 0x2e782c <FT_Load_Glyph+0x2c8> */
/* @0x2e786e ldr r3, [r4, #0x48] */
/* @0x2e7870 ldr r2, [pc, #0x10] */
/* @0x2e7872 cmp r3, r2 */
/* @0x2e7874 bne 0x2e782c <FT_Load_Glyph+0x2c8> */
/* @0x2e7876 b 0x2e7692 <FT_Load_Glyph+0x12e> */
/* @0x2e7878 add sp, #0x14 */
/* @0x2e787a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e787c svclt #0x8ff0 */
/* @0x2e787e nop */
/* @0x2e7880 strb r4, [r5, #0x11] */
/* @0x2e7882 ldr r5, [r6, #0x74] */
/* @0x2e7884 strb r3, [r6, #0x11] */
/* @0x2e7886 str r1, [r5, #0x24] */
/* @0x2e7888 ldr r0, [r6, #0x54] */
/* @0x2e788a str r7, [r5, #0x34] */

/* ── FUNC 0x2e788c · FT_Get_Advances · size=196 · insn=87 */
/* @0x2e788c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e7890 mov r5, r1 */
/* @0x2e7892 mov r7, r2 */
/* @0x2e7894 mov r6, r3 */
/* @0x2e7896 ldr.w r8, [sp, #0x28] */
/* @0x2e7898 strmi r8, [r4], -r8, lsr #32 */
/* @0x2e789a mov r4, r0 */
/* @0x2e789c cmp r0, #0x0 */
/* @0x2e789e beq 0x2e793c <FT_Get_Advances+0xb0> */
/* @0x2e78a0 cmp.w r8, #0x0 */
/* @0x2e78a4 beq 0x2e7940 <FT_Get_Advances+0xb4> */
/* @0x2e78a6 ldr r3, [r0, #0x10] */
/* @0x2e78a8 cmp r1, r3 */
/* @0x2e78aa bhs 0x2e7944 <FT_Get_Advances+0xb8> */
/* @0x2e78ac adds.w r9, r1, r2 */
/* @0x2e78b0 bhs 0x2e7944 <FT_Get_Advances+0xb8> */
/* @0x2e78b2 cmp r9, r3 */
/* @0x2e78b4 bhi 0x2e7944 <FT_Get_Advances+0xb8> */
/* @0x2e78b6 cbnz r2, 0x2e78bc <FT_Get_Advances+0x30> */
/* @0x2e78b8 movs r0, #0x0 */
/* @0x2e78ba b 0x2e794a <FT_Get_Advances+0xbe> */
/* @0x2e78bc ldr r3, [r0, #0x60] */
/* @0x2e78be ldr r3, [r3, #0xc] */
/* @0x2e78c0 ldr.w r12, [r3, #0x54] */
/* @0x2e78c4 cmp.w r12, #0x0 */
/* @0x2e78c8 bne 0x2e78dc <FT_Get_Advances+0x50> */
/* @0x2e78ca lsls r2, r6, #0x2 */
/* @0x2e78cc bmi 0x2e7948 <FT_Get_Advances+0xbc> */
/* @0x2e78ce orr r6, r6, #0x100 */
/* @0x2e78d0 .word 0xf1a87680 */
/* @0x2e78d2 sub.w r7, r8, #0x4 */
/* @0x2e78d4 .word 0xf0060704 */
/* @0x2e78d6 and r8, r6, #0x10 */
/* @0x2e78d8 eor r0, r10, r0, lsl r8 */
/* @0x2e78da b 0x2e7932 <FT_Get_Advances+0xa6> */
/* @0x2e78dc lsls r3, r6, #0x1e */
/* @0x2e78de bne 0x2e78e8 <FT_Get_Advances+0x5c> */
/* @0x2e78e0 ubfx r3, r6, #0x10, #0x4 */
/* @0x2e78e4 cmp r3, #0x1 */
/* @0x2e78e6 bne 0x2e78ca <FT_Get_Advances+0x3e> */
/* @0x2e78e8 str.w r8, [sp] */
/* @0x2e78ec mov r0, r4 */
/* @0x2e78ee mov r1, r5 */
/* @0x2e78f0 mov r2, r7 */
/* @0x2e78f2 mov r3, r6 */
/* @0x2e78f4 blx r12 */
/* @0x2e78f6 cbnz r0, 0x2e790c <FT_Get_Advances+0x80> */
/* @0x2e78f8 add.w r0, r4, #0x58 */
/* @0x2e78fc mov r1, r8 */
/* @0x2e78fe mov r2, r7 */
/* @0x2e7900 mov r3, r6 */
/* @0x2e7902 add sp, #0xc */
/* @0x2e7904 pop.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e7908 b.w 0x2e4db2 <FT_MulDiv+0x76> */
/* @0x2e790c uxtb r3, r0 */
/* @0x2e790e cmp r3, #0x7 */
/* @0x2e7910 bne 0x2e794a <FT_Get_Advances+0xbe> */
/* @0x2e7912 b 0x2e78ca <FT_Get_Advances+0x3e> */
/* @0x2e7914 mov r0, r4 */
/* @0x2e7916 mov r1, r5 */
/* @0x2e7918 mov r2, r6 */
/* @0x2e791a bl 0x2e7564 <FT_Load_Glyph> */
/* @0x2e791c stmiblt r0!, {r0, r1, r5, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e791e cbnz r0, 0x2e794a <FT_Get_Advances+0xbe> */
/* @0x2e7920 ldr r3, [r4, #0x54] */
/* @0x2e7922 cmp.w r8, #0x0 */
/* @0x2e7924 andle r0, r7, r0, lsl #30 */
/* @0x2e7926 beq 0x2e7938 <FT_Get_Advances+0xac> */
/* @0x2e7928 ldr r3, [r3, #0x44] */
/* @0x2e792a adds r5, #0x1 */
/* @0x2e792c lsls r3, r3, #0xa */
/* @0x2e792e str r3, [r7, #4]! */
/* @0x2e7930 strbmi r3, [sp, #-0xf04] */
/* @0x2e7932 cmp r5, r9 */
/* @0x2e7934 bne 0x2e7914 <FT_Get_Advances+0x88> */
/* @0x2e7936 b 0x2e78b8 <FT_Get_Advances+0x2c> */
/* @0x2e7938 ldr r3, [r3, #0x40] */
/* @0x2e793a b 0x2e792a <FT_Get_Advances+0x9e> */
/* @0x2e793c movs r0, #0x23 */
/* @0x2e793e b 0x2e794a <FT_Get_Advances+0xbe> */
/* @0x2e7940 movs r0, #0x6 */
/* @0x2e7942 b 0x2e794a <FT_Get_Advances+0xbe> */
/* @0x2e7944 movs r0, #0x10 */
/* @0x2e7946 b 0x2e794a <FT_Get_Advances+0xbe> */
/* @0x2e7948 movs r0, #0x7 */
/* @0x2e794a add sp, #0xc */
/* @0x2e794c pop.w {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2e7950 · FT_Get_Advance · size=122 · insn=55 */
/* @0x2e7950 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e7952 mov r7, r1 */
/* @0x2e7954 mov r5, r2 */
/* @0x2e7956 mov r6, r3 */
/* @0x2e7958 mov r4, r0 */
/* @0x2e795a cmp r0, #0x0 */
/* @0x2e795c beq 0x2e79bc <FT_Get_Advance+0x6c> */
/* @0x2e795e cmp r3, #0x0 */
/* @0x2e7960 beq 0x2e79c0 <FT_Get_Advance+0x70> */
/* @0x2e7962 ldr r3, [r0, #0x10] */
/* @0x2e7964 cmp r1, r3 */
/* @0x2e7966 bhs 0x2e79c4 <FT_Get_Advance+0x74> */
/* @0x2e7968 ldr r3, [r0, #0x60] */
/* @0x2e796a ldr r3, [r3, #0xc] */
/* @0x2e796c ldr.w r12, [r3, #0x54] */
/* @0x2e7970 cmp.w r12, #0x0 */
/* @0x2e7974 bne 0x2e7986 <FT_Get_Advance+0x36> */
/* @0x2e7976 str r6, [sp] */
/* @0x2e7978 mov r0, r4 */
/* @0x2e797a mov r1, r7 */
/* @0x2e797c movs r2, #0x1 */
/* @0x2e797e mov r3, r5 */
/* @0x2e7980 bl 0x2e788c <FT_Get_Advances> */
/* @0x2e7984 b 0x2e79c6 <FT_Get_Advance+0x76> */
/* @0x2e7986 lsls r3, r2, #0x1e */
/* @0x2e7988 bne 0x2e7992 <FT_Get_Advance+0x42> */
/* @0x2e798a ubfx r3, r2, #0x10, #0x4 */
/* @0x2e798c blhs 0x3385a0 */
/* @0x2e798e cmp r3, #0x1 */
/* @0x2e7990 bne 0x2e7976 <FT_Get_Advance+0x26> */
/* @0x2e7992 str r6, [sp] */
/* @0x2e7994 mov r0, r4 */
/* @0x2e7996 mov r1, r7 */
/* @0x2e7998 movs r2, #0x1 */
/* @0x2e799a mov r3, r5 */
/* @0x2e799c blx r12 */
/* @0x2e799e cbnz r0, 0x2e79b4 <FT_Get_Advance+0x64> */
/* @0x2e79a0 add.w r0, r4, #0x58 */
/* @0x2e79a4 mov r1, r6 */
/* @0x2e79a6 movs r2, #0x1 */
/* @0x2e79a8 mov r3, r5 */
/* @0x2e79aa add sp, #0xc */
/* @0x2e79ac pop.w {r4, r5, r6, r7, lr} */
/* @0x2e79b0 b.w 0x2e4db2 <FT_MulDiv+0x76> */
/* @0x2e79b4 uxtb r3, r0 */
/* @0x2e79b6 cmp r3, #0x7 */
/* @0x2e79b8 bne 0x2e79c6 <FT_Get_Advance+0x76> */
/* @0x2e79ba b 0x2e7976 <FT_Get_Advance+0x26> */
/* @0x2e79bc movs r0, #0x23 */
/* @0x2e79be b 0x2e79c6 <FT_Get_Advance+0x76> */
/* @0x2e79c0 movs r0, #0x6 */
/* @0x2e79c2 b 0x2e79c6 <FT_Get_Advance+0x76> */
/* @0x2e79c4 movs r0, #0x10 */
/* @0x2e79c6 add sp, #0xc */
/* @0x2e79c8 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e79ca · FT_Load_Char · size=38 · insn=19 */
/* @0x2e79ca push {r4, r5, r6, lr} */
/* @0x2e79cc mov r3, r1 */
/* @0x2e79ce mov r6, r2 */
/* @0x2e79d0 mov r4, r0 */
/* @0x2e79d2 cbz r0, 0x2e79ec <FT_Load_Char+0x22> */
/* @0x2e79d4 ldr r5, [r0, #0x5c] */
/* @0x2e79d6 cbz r5, 0x2e79de <FT_Load_Char+0x14> */
/* @0x2e79d8 bl 0x2e5960 <FT_Get_Char_Index> */
/* @0x2e79da strmi pc, [r3], -r2, asr #31 */
/* @0x2e79dc mov r3, r0 */
/* @0x2e79de mov r0, r4 */
/* @0x2e79e0 mov r2, r6 */
/* @0x2e79e2 mov r1, r3 */
/* @0x2e79e4 pop.w {r4, r5, r6, lr} */
/* @0x2e79e6 .word 0xf7ff4070 */
/* @0x2e79e8 b.w 0x2e7564 <FT_Load_Glyph> */
/* @0x2e79ea .word 0x2023bdbc */
/* @0x2e79ec movs r0, #0x23 */
/* @0x2e79ee pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e79f0 · ft_glyphslot_alloc_bitmap · size=58 · insn=28 */
/* @0x2e79f0 push {r0, r1, r4, r5, r6, lr} */
/* @0x2e79f2 mov r6, r1 */
/* @0x2e79f4 ldr r3, [r0, #0x4] */
/* @0x2e79f6 mov r4, r0 */
/* @0x2e79f8 ldr r5, [r3, #0x64] */
/* @0x2e79fa ldr.w r3, [r0, #0x9c] */
/* @0x2e79fc ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^ */
/* @0x2e79fe ldr r2, [r3, #0x4] */
/* @0x2e7a00 lsls r1, r2, #0x1f */
/* @0x2e7a02 bpl 0x2e7a12 <ft_glyphslot_alloc_bitmap+0x22> */
/* @0x2e7a04 mov r0, r5 */
/* @0x2e7a06 ldr r1, [r4, #0x58] */
/* @0x2e7a08 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7a0c movs r3, #0x0 */
/* @0x2e7a0e str r3, [r4, #0x58] */
/* @0x2e7a10 b 0x2e7a18 <ft_glyphslot_alloc_bitmap+0x28> */
/* @0x2e7a12 orr r2, r2, #0x1 */
/* @0x2e7a14 subsvs r0, r10, r1, lsl #4 */
/* @0x2e7a16 str r2, [r3, #0x4] */
/* @0x2e7a18 mov r0, r5 */
/* @0x2e7a1a mov r1, r6 */
/* @0x2e7a1c add r2, sp, #0x4 */
/* @0x2e7a1e bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e7a20 strvs pc, [r0, #0xb82]! */
/* @0x2e7a22 str r0, [r4, #0x58] */
/* @0x2e7a24 ldr r0, [sp, #0x4] */
/* @0x2e7a26 add sp, #0x8 */
/* @0x2e7a28 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e7a2c · anon_2e7a2c · size=64 · insn=17 */
/* @0x2e7a2c stmdavs r3, {r2, r9, r10, lr} ^ */
/* @0x2e7a30 stmvs r11!, {r0, r2, r3, r4, r9, r10, r11, sp, lr} ^ */
/* @0x2e7a34 mrrcvs p8, #0xa, r6, r11, c14 */
/* @0x2e7a38 ldrmi r11, [r8, r3, lsl #2] */
/* @0x2e7a3c .word 0xf7ff4620 */
/* @0x2e7a40 .word 0xf8d4fd70 */
/* @0x2e7a44 .word 0xb193309c */
/* @0x2e7a48 ldmdavs r2, {r1, r3, r5, r11, sp, lr} */
/* @0x2e7a4c strvc pc, [r0, #-0x412] */
/* @0x2e7a50 ldmdavs r8, {r0, r2, r8, r12, lr, pc} */
/* @0x2e7a54 ldc2 p7, c15, [r10], {255} */
/* @0x2e7a58 ldrsblo pc, [r12], r4 */
/* @0x2e7a5c shadd16mi r6, r0, sp */
/* @0x2e7a60 ldrsbne pc, [r12], r4 */
/* @0x2e7a64 stc2l p7, c15, [r7], #-1020 */
/* @0x2e7a68 .word 0xf8c42300 */
/* @0x2e7a6c ldcllt p0, c3, [r0, #-624]! */

/* ── FUNC 0x2e7a70 · FT_New_GlyphSlot · size=170 · insn=81 */
/* @0x2e7a70 push.w {r0, r1, r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2e7a74 mov r6, r1 */
/* @0x2e7a76 mov r5, r0 */
/* @0x2e7a78 cmp r0, #0x0 */
/* @0x2e7a7a beq 0x2e7b0e <FT_New_GlyphSlot+0x9e> */
/* @0x2e7a7c ldr r3, [r0, #0x60] */
/* @0x2e7a7e cmp r3, #0x0 */
/* @0x2e7a80 beq 0x2e7b12 <FT_New_GlyphSlot+0xa2> */
/* @0x2e7a82 ldr.w r8, [r3, #0x8] */
/* @0x2e7a84 strbtmi r8, [r10], -r8 */
/* @0x2e7a86 mov r2, sp */
/* @0x2e7a88 ldr r3, [r3, #0xc] */
/* @0x2e7a8a mov r0, r8 */
/* @0x2e7a8c ldr r1, [r3, #0x2c] */
/* @0x2e7a8e bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e7a90 blls 0x3267c0 */
/* @0x2e7a92 ldr r3, [sp] */
/* @0x2e7a94 mov r4, r0 */
/* @0x2e7a96 cmp r3, #0x0 */
/* @0x2e7a98 bne 0x2e7b04 <FT_New_GlyphSlot+0x94> */
/* @0x2e7a9a str r5, [r0, #0x4] */
/* @0x2e7a9c add r2, sp, #0x8 */
/* @0x2e7a9e ldr r7, [r5, #0x60] */
/* @0x2e7aa0 movs r1, #0x28 */
/* @0x2e7aa2 str r3, [r2, #-4]! */
/* @0x2e7aa4 .word 0xf8d73d04 */
/* @0x2e7aa6 ldr.w r9, [r7, #0x8] */
/* @0x2e7aa8 ldmdavs r11!, {r3, r12, pc} ^ */
/* @0x2e7aaa ldr r3, [r7, #0x4] */
/* @0x2e7aac ldr.w r10, [r7, #0xc] */
/* @0x2e7ab0 str r3, [r0] */
/* @0x2e7ab2 mov r0, r9 */
/* @0x2e7ab4 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e7ab8 ldr r3, [sp, #0x4] */
/* @0x2e7aba mov r1, r0 */
/* @0x2e7abc cbnz r3, 0x2e7ae2 <FT_New_GlyphSlot+0x72> */
/* @0x2e7abe str.w r0, [r4, #0x9c] */
/* @0x2e7ac0 ldmdavs r11!, {r2, r3, r4, r7} */
/* @0x2e7ac2 ldr r3, [r7] */
/* @0x2e7ac4 ldr r3, [r3] */
/* @0x2e7ac6 lsls r3, r3, #0x16 */
/* @0x2e7ac8 bmi 0x2e7ad2 <FT_New_GlyphSlot+0x62> */
/* @0x2e7aca mov r0, r9 */
/* @0x2e7acc bl 0x2e714c <FT_GlyphLoader_New> */
/* @0x2e7ad0 str r0, [sp, #0x4] */
/* @0x2e7ad2 ldr r3, [sp, #0x4] */
/* @0x2e7ad4 cbnz r3, 0x2e7ae2 <FT_New_GlyphSlot+0x72> */
/* @0x2e7ad6 ldr.w r3, [r10, #0x40] */
/* @0x2e7ad8 tstlt r3, r0, asr #32 */
/* @0x2e7ada cbz r3, 0x2e7ae2 <FT_New_GlyphSlot+0x72> */
/* @0x2e7adc mov r0, r4 */
/* @0x2e7ade blx r3 */
/* @0x2e7ae0 str r0, [sp, #0x4] */
/* @0x2e7ae2 ldr r3, [sp, #0x4] */
/* @0x2e7ae4 str r3, [sp] */
/* @0x2e7ae6 cbz r3, 0x2e7af8 <FT_New_GlyphSlot+0x88> */
/* @0x2e7ae8 mov r0, r4 */
/* @0x2e7aea bl 0x2e7a2a <ft_glyphslot_alloc_bitmap+0x3a> */
/* @0x2e7aec .word 0x4640ff9e */
/* @0x2e7aee mov r0, r8 */
/* @0x2e7af0 mov r1, r4 */
/* @0x2e7af2 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7af4 and pc, r8, r0, lsr #24 */
/* @0x2e7af6 b 0x2e7b0a <FT_New_GlyphSlot+0x9a> */
/* @0x2e7af8 ldr r3, [r5, #0x54] */
/* @0x2e7afa str r3, [r4, #0x8] */
/* @0x2e7afc str r4, [r5, #0x54] */
/* @0x2e7afe cbz r6, 0x2e7b0a <FT_New_GlyphSlot+0x9a> */
/* @0x2e7b00 str r4, [r6] */
/* @0x2e7b02 b 0x2e7b0a <FT_New_GlyphSlot+0x9a> */
/* @0x2e7b04 cbz r6, 0x2e7b0a <FT_New_GlyphSlot+0x9a> */
/* @0x2e7b06 movs r3, #0x0 */
/* @0x2e7b08 str r3, [r6] */
/* @0x2e7b0a ldr r0, [sp] */
/* @0x2e7b0c b 0x2e7b14 <FT_New_GlyphSlot+0xa4> */
/* @0x2e7b0e movs r0, #0x23 */
/* @0x2e7b10 b 0x2e7b14 <FT_New_GlyphSlot+0xa4> */
/* @0x2e7b12 movs r0, #0x6 */
/* @0x2e7b14 add sp, #0x8 */
/* @0x2e7b16 pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2e7b18 ldrlt r8, [r8, #-0x7f0]! */

/* ── FUNC 0x2e7b1a · FT_Done_GlyphSlot · size=66 · insn=33 */
/* @0x2e7b1a push {r3, r4, r5, lr} */
/* @0x2e7b1c mov r4, r0 */
/* @0x2e7b1e cbz r0, 0x2e7b5a <FT_Done_GlyphSlot+0x40> */
/* @0x2e7b20 ldr r2, [r0, #0x4] */
/* @0x2e7b22 movs r1, #0x0 */
/* @0x2e7b24 ldr r3, [r2, #0x60] */
/* @0x2e7b26 ldr r5, [r3, #0x8] */
/* @0x2e7b28 ldr r3, [r2, #0x54] */
/* @0x2e7b2a cbz r3, 0x2e7b5a <FT_Done_GlyphSlot+0x40> */
/* @0x2e7b2c cmp r3, r4 */
/* @0x2e7b2e bne 0x2e7b54 <FT_Done_GlyphSlot+0x3a> */
/* @0x2e7b30 ldr r3, [r4, #0x8] */
/* @0x2e7b32 cbnz r1, 0x2e7b38 <FT_Done_GlyphSlot+0x1e> */
/* @0x2e7b34 str r3, [r2, #0x54] */
/* @0x2e7b36 b 0x2e7b3a <FT_Done_GlyphSlot+0x20> */
/* @0x2e7b38 str r3, [r1, #0x8] */
/* @0x2e7b3a ldr r3, [r4, #0x14] */
/* @0x2e7b3c cbz r3, 0x2e7b42 <FT_Done_GlyphSlot+0x28> */
/* @0x2e7b3e mov r0, r4 */
/* @0x2e7b40 blx r3 */
/* @0x2e7b42 mov r0, r4 */
/* @0x2e7b44 bl 0x2e7a2a <ft_glyphslot_alloc_bitmap+0x3a> */
/* @0x2e7b46 qsub16mi pc, r8, r1 */
/* @0x2e7b48 mov r0, r5 */
/* @0x2e7b4a mov r1, r4 */
/* @0x2e7b4c pop.w {r3, r4, r5, lr} */
/* @0x2e7b4e .word 0xf7ff4038 */
/* @0x2e7b50 b.w 0x2e7336 <ft_mem_free> */
/* @0x2e7b52 ssub8mi r11, r9, r1 */
/* @0x2e7b54 mov r1, r3 */
/* @0x2e7b56 ldr r3, [r3, #0x8] */
/* @0x2e7b58 b 0x2e7b2a <FT_Done_GlyphSlot+0x10> */
/* @0x2e7b5a pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e7b5e · anon_2e7b5e · size=600 · insn=151 */
/* @0x2e7b5e stmdavs r3, {r2, r9, r10, lr} */
/* @0x2e7b62 stmvs r3, {r0, r2, r3, r4, r6, r9, r10, r11, sp, lr} ^ */
/* @0x2e7b66 swplt r6, r11, [r3] */
/* @0x2e7b6a qadd8mi r4, r8, r8 */
/* @0x2e7b6e pop {r0, r5, r9, r10, lr} */
/* @0x2e7b72 .word 0xf7ff4038 */
/* @0x2e7b76 ldrblt r11, [r8, #0xbdf]! */
/* @0x2e7b7a strmi r4, [r4], -pc, lsl #12 */
/* @0x2e7b7e strhs r11, [r0, #-0x1a8] */
/* @0x2e7b82 bvs 0x1bb9442 <b2_toiTime+0x145ff9e> */
/* @0x2e7b86 ble 0x538602 <obj_numb_event+0x1692> */
/* @0x2e7b8a .word 0xf8536aa3 */
/* @0x2e7b8e .word 0xf7ff0025 */
/* @0x2e7b92 bvs 0xfebe7b2a <b2_toiTime+0xfffffffffe48e686> */
/* @0x2e7b96 eorvs pc, r5, r3, asr #16 */
/* @0x2e7b9a ldrb r3, [r2, r1, lsl #10]! */
/* @0x2e7b9e bvs 0xfeb39486 <b2_toiTime+0xfffffffffe3dffe2> */
/* @0x2e7ba2 blx 0xff525ba8 <b2_toiTime+0xfffffffffedcc704> */
/* @0x2e7ba6 adcvs r2, r3, #0, #6 */
/* @0x2e7baa ldcllt p2, c6, [r8, #396]! */
/* @0x2e7bae .word 0xe92d0000 */
/* @0x2e7bb2 strdlt r4, r5, [r7], r0 */
/* @0x2e7bb6 .word 0xf10d68c7 */
/* @0x2e7bba stmvs r5, {r2, r4, r9, r11} */
/* @0x2e7bbe andls r4, r3, #6291456 */
/* @0x2e7bc2 ldrbmi r4, [r2], -r8, lsl #13 */
/* @0x2e7bc6 qsub16mi r6, r8, r9 */
/* @0x2e7bca .word 0xf8dd469b */
/* @0x2e7bce .word 0xf7ff9044 */
/* @0x2e7bd2 bls 0x46667e <g_RomDisk+0x6ee5e> */
/* @0x2e7bd6 bhs 0x2f93ee <ps_hints_apply+0x7fee> */
/* @0x2e7bda strvs sp, [r6], -r12, asr #2 */
/* @0x2e7bde .word 0xf8d86645 */
/* @0x2e7be2 strvs r2, [r2], r0 */
/* @0x2e7be6 tstlt r10, r3, lsl #20 */
/* @0x2e7bea vst2.32 {d22, d23}, [r2], r2 */
/* @0x2e7bee addvs r6, r2, r0, lsl #5 */
/* @0x2e7bf2 .word 0x21444628 */
/* @0x2e7bf6 .word 0xf7ff4652 */
/* @0x2e7bfa blls 0x466656 <g_RomDisk+0x6ee36> */
/* @0x2e7bfe blhs 0x2f941e <ps_hints_apply+0x801e> */
/* @0x2e7c02 .word 0xf8c4d139 */
/* @0x2e7c06 movtvs r0, #0x3080 */
/* @0x2e7c0a bls 0x6f9cb2 <g_SWFvertbuff+0x26bea> */
/* @0x2e7c0e .word 0xf8d44293 */
/* @0x2e7c12 ble 0x62fe1a <g_SWFaavertbuff+0x5cd52> */
/* @0x2e7c16 ldmdblt r9, {r0, r4, r6, r8, r9, r11, sp, lr} ^ */
/* @0x2e7c1a eorsne pc, r3, r9, asr r8 */
/* @0x2e7c1e vstmiaeq r3, {s29, s30, s31} */
/* @0x2e7c22 smlabble r3, r1, r2, r4 */
/* @0x2e7c26 .word 0x010ceb09 */
/* @0x2e7c2a cmpvs r1, #4784128 */
/* @0x2e7c2e strb r3, [r12, r1, lsl #6]! */
/* @0x2e7c32 .word 0x33fff04f */
/* @0x2e7c36 .word 0xf8d763d3 */
/* @0x2e7c3a .word 0xf1bcc030 */
/* @0x2e7c3e andle r0, r8, r0, lsl #30 */
/* @0x2e7c42 andls pc, r0, sp, asr #17 */
/* @0x2e7c46 .word 0xf8d84621 */
/* @0x2e7c4a ldrbmi r0, [r10], -r0 */
/* @0x2e7c4e .word 0x47e09b10 */
/* @0x2e7c52 cdpvs p0, #0xa, c9, c3, c5, #0x0 */
/* @0x2e7c56 andlo pc, r0, r8, asr #17 */
/* @0x2e7c5a stmdblt r3!, {r0, r2, r8, r9, r11, r12, pc} ^ */
/* @0x2e7c5e .word 0xf7fc4620 */
/* @0x2e7c62 smlawtlt r0, r12, lr, pc */
/* @0x2e7c66 blhs 0xc9477a <b2_toiTime+0x53b2d6> */
/* @0x2e7c6a andls sp, r5, r1 */
/* @0x2e7c6e blls 0x79fc82 <b2_toiTime+0x467de> */
/* @0x2e7c72 and r6, r0, r12, lsl r0 */
/* @0x2e7c76 blls 0x43147e <g_RomDisk+0x39c5e> */
/* @0x2e7c7a qadd8mi r11, r0, r3 */
/* @0x2e7c7e .word 0xf7ff4629 */
/* @0x2e7c82 blvs 0x21e7a72 <b2_toiTime+0x1a8e5ce> */
/* @0x2e7c86 strtmi r11, [r0], -r11, lsl #2 */
/* @0x2e7c8a qadd8mi r4, r8, r8 */
/* @0x2e7c8e .word 0xf7ff4631 */
/* @0x2e7c92 qsaxmi pc, r8, r1 */
/* @0x2e7c96 .word 0xf7ff4621 */
/* @0x2e7c9a bls 0x7a69d6 <b2_toiTime+0x4d532> */
/* @0x2e7c9e andsvs r2, r3, r0, lsl #6 */
/* @0x2e7ca2 andlt r9, r7, r5, lsl #16 */
/* @0x2e7ca6 svchi #0xf0e8bd */
/* @0x2e7caa cmnvs r2, #0, #30 */
/* @0x2e7cae ldrlt r6, [r0, #-0x96e] */
/* @0x2e7cb2 stmdavs r1!, {r2, r9, r10, lr} */
/* @0x2e7cb6 .word 0xf7ff69c0 */
/* @0x2e7cba movwhs pc, #0xb3d */
/* @0x2e7cbe rsbvs r6, r3, r3, lsr #32 */
/* @0x2e7cc2 ldclt p1, c6, [r0, #-652] */
/* @0x2e7cc6 ldrblt r0, [r8, #0x0]! */
/* @0x2e7cca stmdavs r6, {r0, r4, r9, r10, lr} */
/* @0x2e7cce bmi 0x5f94ea <g_SWFaavertbuff+0x26422> */
/* @0x2e7cd2 shadd16mi r4, r0, pc */
/* @0x2e7cd6 .word 0xf7ff447a */
/* @0x2e7cda strmi pc, [r4], -r6, asr #20 */
/* @0x2e7cde qsub16mi r11, r8, r0 */
/* @0x2e7ce2 bls 0x47956e <g_RomDisk+0x81d4e> */
/* @0x2e7ce6 blx 0xff565cec <b2_toiTime+0xfffffffffee0c848> */
/* @0x2e7cea stmdblt r8, {r0, r2, r9, r10, lr} */
/* @0x2e7cee and r6, r3, r12, lsr r0 */
/* @0x2e7cf2 qasxmi r4, r1, r0 */
/* @0x2e7cf6 blx 0xaa5cfc <b2_toiTime+0x34c858> */
/* @0x2e7cfa ldcllt p6, c4, [r8, #160]! */
/* @0x2e7cfe ldcllt p0, c2, [r8, #256]! */
/* @0x2e7d02 bvs 0xfe81790a <b2_toiTime+0xfffffffffe0be466> */
/* @0x2e7d06 ldrblt r0, [r8, #0xa]! */
/* @0x2e7d0a stmdavs r6, {r0, r4, r9, r10, lr} */
/* @0x2e7d0e bmi 0x5f952a <g_SWFaavertbuff+0x26462> */
/* @0x2e7d12 shadd16mi r4, r0, pc */
/* @0x2e7d16 .word 0xf7ff447a */
/* @0x2e7d1a strmi pc, [r4], -r6, lsr #20 */
/* @0x2e7d1e qsub16mi r11, r8, r0 */
/* @0x2e7d22 bls 0x4795ae <g_RomDisk+0x81d8e> */
/* @0x2e7d26 blx 0xfed65d2c <b2_toiTime+0xfffffffffe60c888> */
/* @0x2e7d2a stmdblt r8, {r0, r2, r9, r10, lr} */
/* @0x2e7d2e and r6, r3, r12, lsr r0 */
/* @0x2e7d32 qasxmi r4, r1, r0 */
/* @0x2e7d36 blx 0x2a5d3a <png_free_data+0x17a> */
/* @0x2e7d3a ldcllt p6, c4, [r8, #160]! */
/* @0x2e7d3e ldcllt p0, c2, [r8, #256]! */
/* @0x2e7d42 bvs 0x1b9794a <b2_toiTime+0x143e4a6> */
/* @0x2e7d46 ldrblt r0, [r8, #0xa]! */
/* @0x2e7d4a stmdavs r6, {r0, r4, r9, r10, lr} */
/* @0x2e7d4e bmi 0x5f956a <g_SWFaavertbuff+0x264a2> */
/* @0x2e7d52 shadd16mi r4, r0, pc */
/* @0x2e7d56 .word 0xf7ff447a */
/* @0x2e7d5a strmi pc, [r4], -r6, lsl #20 */
/* @0x2e7d5e qsub16mi r11, r8, r0 */
/* @0x2e7d62 bls 0x4795ee <g_RomDisk+0x81dce> */
/* @0x2e7d66 blx 0xfe565d6c <b2_toiTime+0xfffffffffde0c8c8> */
/* @0x2e7d6a stmdblt r8, {r0, r2, r9, r10, lr} */
/* @0x2e7d6e and r6, r3, r12, lsr r0 */
/* @0x2e7d72 qasxmi r4, r1, r0 */
/* @0x2e7d76 blx 0xffaa5d7a <b2_toiTime+0xffffffffff34c8d6> */
/* @0x2e7d7a ldcllt p6, c4, [r8, #160]! */
/* @0x2e7d7e ldcllt p0, c2, [r8, #256]! */
/* @0x2e7d82 bvs 0xc1798a <b2_toiTime+0x4be4e6> */
/* @0x2e7d86 ldrblt r0, [r0, #-0xa]! */
/* @0x2e7d8a stmvs r11, {r0, r2, r9, r10, lr} */
/* @0x2e7d8e ldrmi r4, [r6], -r12, lsl #12 */
/* @0x2e7d92 strmi r11, [r8], -r11, lsl #2 */
/* @0x2e7d96 ldmvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^ */
/* @0x2e7d9a ldrdlt r6, r7, [r11, -r11] */
/* @0x2e7d9e ldrmi r4, [r8, r0, lsr #12] */
/* @0x2e7da2 bvs 0xfeb3964a <b2_toiTime+0xfffffffffe3e01a6> */
/* @0x2e7da6 blx 0xff4a5daa <b2_toiTime+0xfffffffffed4c906> */
/* @0x2e7daa strtmi r2, [r8], -r0, lsl #6 */
/* @0x2e7dae strtmi r6, [r1], -r3, lsr #5 */
/* @0x2e7db2 ldrhtmi lr, [r0], #-141 */
/* @0x2e7db6 blt 0xff2a5dba <b2_toiTime+0xfffffffffeb4c916> */

/* ── FUNC 0x2e7dba · FT_Outline_Done_Internal · size=68 · insn=31 */
/* @0x2e7dba push {r4, r5, r6, lr} */
/* @0x2e7dbc mov r6, r0 */
/* @0x2e7dbe mov r4, r1 */
/* @0x2e7dc0 cbz r1, 0x2e7df6 <FT_Outline_Done_Internal+0x3c> */
/* @0x2e7dc2 cbz r0, 0x2e7dfa <FT_Outline_Done_Internal+0x40> */
/* @0x2e7dc4 ldr r3, [r1, #0x10] */
/* @0x2e7dc6 lsls r3, r3, #0x1f */
/* @0x2e7dc8 bpl 0x2e7de8 <FT_Outline_Done_Internal+0x2e> */
/* @0x2e7dca ldr r1, [r1, #0x4] */
/* @0x2e7dcc movs r5, #0x0 */
/* @0x2e7dce bl 0x2e7336 <ft_mem_free> */
/* @0x2e7dd2 mov r0, r6 */
/* @0x2e7dd4 ldr r1, [r4, #0x8] */
/* @0x2e7dd6 str r5, [r4, #0x4] */
/* @0x2e7dd8 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7dda adcvs pc, r5, sp, lsr #21 */
/* @0x2e7ddc str r5, [r4, #0x8] */
/* @0x2e7dde mov r0, r6 */
/* @0x2e7de0 ldr r1, [r4, #0xc] */
/* @0x2e7de2 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7de6 str r5, [r4, #0xc] */
/* @0x2e7de8 mov r0, r4 */
/* @0x2e7dea movs r1, #0x0 */
/* @0x2e7dec movs r2, #0x14 */
/* @0x2e7dee blx 0xb65b0 <memset@plt> */
/* @0x2e7df2 movs r0, #0x0 */
/* @0x2e7df4 pop {r4, r5, r6, pc} */
/* @0x2e7df6 movs r0, #0x14 */
/* @0x2e7df8 pop {r4, r5, r6, pc} */
/* @0x2e7dfa movs r0, #0x6 */
/* @0x2e7dfc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e7dfe · FT_Outline_Done · size=12 · insn=5 */
/* @0x2e7dfe cbz r0, 0x2e7e06 <FT_Outline_Done+0x8> */
/* @0x2e7e00 ldr r0, [r0] */
/* @0x2e7e02 b.w 0x2e7dba <FT_Outline_Done_Internal> */
/* @0x2e7e06 movs r0, #0x21 */
/* @0x2e7e08 bx lr */

/* ── FUNC 0x2e7e0a · FT_Stream_ReleaseFrame · size=24 · insn=12 */
/* @0x2e7e0a push {r4, lr} */
/* @0x2e7e0c mov r4, r1 */
/* @0x2e7e0e cbz r0, 0x2e7e1c <FT_Stream_ReleaseFrame+0x12> */
/* @0x2e7e10 ldr r3, [r0, #0x14] */
/* @0x2e7e12 cbz r3, 0x2e7e1c <FT_Stream_ReleaseFrame+0x12> */
/* @0x2e7e14 ldr r0, [r0, #0x1c] */
/* @0x2e7e16 ldr r1, [r1] */
/* @0x2e7e18 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7e1a movwhs pc, #0xa8d */
/* @0x2e7e1c movs r3, #0x0 */
/* @0x2e7e1e str r3, [r4] */
/* @0x2e7e20 pop {r4, pc} */

/* ── FUNC 0x2e7e22 · FT_Stream_EnterFrame · size=128 · insn=59 */
/* @0x2e7e22 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2e7e26 movs r3, #0x0 */
/* @0x2e7e28 str r3, [sp, #0x4] */
/* @0x2e7e2a mov r4, r0 */
/* @0x2e7e2c ldr r3, [r0, #0x14] */
/* @0x2e7e2e mov r5, r1 */
/* @0x2e7e30 ldr r2, [r0, #0x4] */
/* @0x2e7e32 cbz r3, 0x2e7e80 <FT_Stream_EnterFrame+0x5e> */
/* @0x2e7e34 cmp r1, r2 */
/* @0x2e7e36 ldr.w r8, [r0, #0x1c] */
/* @0x2e7e3a bls 0x2e7e42 <FT_Stream_EnterFrame+0x20> */
/* @0x2e7e3c movs r3, #0x55 */
/* @0x2e7e3e str r3, [sp, #0x4] */
/* @0x2e7e40 b 0x2e7e9a <FT_Stream_EnterFrame+0x78> */
/* @0x2e7e42 add r2, sp, #0x4 */
/* @0x2e7e44 mov r0, r8 */
/* @0x2e7e46 bl 0x2e7100 <ft_mem_qalloc> */
/* @0x2e7e4a ldr r6, [sp, #0x4] */
/* @0x2e7e4c mov r2, r0 */
/* @0x2e7e4e str r0, [r4] */
/* @0x2e7e50 cbnz r6, 0x2e7e9a <FT_Stream_EnterFrame+0x78> */
/* @0x2e7e52 ldr r7, [r4, #0x14] */
/* @0x2e7e54 mov r0, r4 */
/* @0x2e7e56 ldr r1, [r4, #0x8] */
/* @0x2e7e58 mov r3, r5 */
/* @0x2e7e5a blx r7 */
/* @0x2e7e5c cmp r0, r5 */
/* @0x2e7e5e mov r7, r0 */
/* @0x2e7e60 bhs 0x2e7e70 <FT_Stream_EnterFrame+0x4e> */
/* @0x2e7e62 mov r0, r8 */
/* @0x2e7e64 ldr r1, [r4] */
/* @0x2e7e66 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7e6a movs r3, #0x55 */
/* @0x2e7e6c str r6, [r4] */
/* @0x2e7e6e str r3, [sp, #0x4] */
/* @0x2e7e70 ldr r3, [r4] */
/* @0x2e7e72 add r5, r3 */
/* @0x2e7e74 str r5, [r4, #0x24] */
/* @0x2e7e76 str r3, [r4, #0x20] */
/* @0x2e7e78 ldr r3, [r4, #0x8] */
/* @0x2e7e7a add r7, r3 */
/* @0x2e7e7c str r7, [r4, #0x8] */
/* @0x2e7e7e b 0x2e7e9a <FT_Stream_EnterFrame+0x78> */
/* @0x2e7e80 ldr r3, [r0, #0x8] */
/* @0x2e7e82 cmp r3, r2 */
/* @0x2e7e84 bhs 0x2e7e3c <FT_Stream_EnterFrame+0x1a> */
/* @0x2e7e86 subs r2, r2, r3 */
/* @0x2e7e88 cmp r2, r1 */
/* @0x2e7e8a blo 0x2e7e3c <FT_Stream_EnterFrame+0x1a> */
/* @0x2e7e8c ldr r2, [r0] */
/* @0x2e7e8e add r5, r3 */
/* @0x2e7e90 str r5, [r0, #0x8] */
/* @0x2e7e92 add r2, r3 */
/* @0x2e7e94 str r2, [r0, #0x20] */
/* @0x2e7e96 add r2, r1 */
/* @0x2e7e98 str r2, [r0, #0x24] */
/* @0x2e7e9a ldr r0, [sp, #0x4] */
/* @0x2e7e9c add sp, #0x8 */
/* @0x2e7e9e pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e7ea2 · FT_Stream_ExtractFrame · size=22 · insn=11 */
/* @0x2e7ea2 push {r3, r4, r5, lr} */
/* @0x2e7ea4 mov r4, r0 */
/* @0x2e7ea6 mov r5, r2 */
/* @0x2e7ea8 bl 0x2e7e22 <FT_Stream_EnterFrame> */
/* @0x2e7eaa ldmdblt r8, {r0, r1, r3, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e7eac cbnz r0, 0x2e7eb6 <FT_Stream_ExtractFrame+0x14> */
/* @0x2e7eae ldr r3, [r4, #0x20] */
/* @0x2e7eb0 str r3, [r5] */
/* @0x2e7eb2 str r0, [r4, #0x20] */
/* @0x2e7eb4 str r0, [r4, #0x24] */
/* @0x2e7eb6 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e7eb8 · FT_Stream_ExitFrame · size=28 · insn=13 */
/* @0x2e7eb8 push {r4, lr} */
/* @0x2e7eba mov r4, r0 */
/* @0x2e7ebc ldr r3, [r0, #0x14] */
/* @0x2e7ebe cbz r3, 0x2e7ecc <FT_Stream_ExitFrame+0x14> */
/* @0x2e7ec0 ldr r0, [r0, #0x1c] */
/* @0x2e7ec2 ldr r1, [r4] */
/* @0x2e7ec4 bl 0x2e7336 <ft_mem_free> */
/* @0x2e7ec8 movs r3, #0x0 */
/* @0x2e7eca str r3, [r4] */
/* @0x2e7ecc movs r3, #0x0 */
/* @0x2e7ece str r3, [r4, #0x20] */
/* @0x2e7ed0 str r3, [r4, #0x24] */
/* @0x2e7ed2 pop {r4, pc} */

/* ── FUNC 0x2e7ed4 · FT_Stream_ReadFields · size=316 · insn=142 */
/* @0x2e7ed4 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e7ed8 mov r6, r0 */
/* @0x2e7eda mov r7, r2 */
/* @0x2e7edc cmp r1, #0x0 */
/* @0x2e7ede beq.w 0x2e7ffe <FT_Stream_ReadFields+0x12a> */
/* @0x2e7ee0 stmdahs r0, {r1, r2, r3, r7, pc} */
/* @0x2e7ee2 cmp r0, #0x0 */
/* @0x2e7ee4 beq.w 0x2e8004 <FT_Stream_ReadFields+0x130> */
/* @0x2e7ee8 ldr r3, [r0, #0x20] */
/* @0x2e7eea adds r5, r1, #0x4 */
/* @0x2e7eec mov.w r8, #0x0 */
/* @0x2e7ef0 ldrb r0, [r5, #-4] */
/* @0x2e7ef4 subs r2, r0, #0x4 */
/* @0x2e7ef6 cmp r2, #0x15 */
/* @0x2e7ef8 bhi 0x2e7fc0 <FT_Stream_ReadFields+0xec> */
/* @0x2e7efa tbb [pc, r2] */
/* @0x2e7efc mrsvs pc, apsr */
/* @0x2e7efe str r3, [r1, #0x10] */
/* @0x2e7f00 str r1, [r4, #0x14] */
/* @0x2e7f02 cmp r0, #0x28 */
/* @0x2e7f04 str r1, [r4, #0x14] */
/* @0x2e7f06 cmp r4, #0x2c */
/* @0x2e7f08 adds r0, #0x30 */
/* @0x2e7f0a adds r7, #0x37 */
/* @0x2e7f0c adcs r1, r0 */
/* @0x2e7f0e ldr r6, [pc, #0x138] */
/* @0x2e7f10 ldrsb r6, [r2, r1] */
/* @0x2e7f12 adds r1, r3, r4 */
/* @0x2e7f14 mov r0, r6 */
/* @0x2e7f16 ldrh r1, [r5, #-2] */
/* @0x2e7f18 .word 0xf7ff1c02 */
/* @0x2e7f1a bl 0x2e7e22 <FT_Stream_EnterFrame> */
/* @0x2e7f1c strmi pc, [r4], -r2, lsl #31 */
/* @0x2e7f1e mov r4, r0 */
/* @0x2e7f20 cmp r0, #0x0 */
/* @0x2e7f22 bne 0x2e7ff0 <FT_Stream_ReadFields+0x11c> */
/* @0x2e7f24 ldr r4, [r6, #0x20] */
/* @0x2e7f26 mov.w r8, #0x1 */
/* @0x2e7f28 strlo r0, [r4, #-0x801] */
/* @0x2e7f2a adds r5, #0x4 */
/* @0x2e7f2c mov r3, r4 */
/* @0x2e7f2e b 0x2e7ef0 <FT_Stream_ReadFields+0x1c> */
/* @0x2e7f30 ldrb r2, [r5, #-3] */
/* @0x2e7f34 ldr r1, [r6, #0x24] */
/* @0x2e7f36 adds r4, r3, r2 */
/* @0x2e7f38 cmp r4, r1 */
/* @0x2e7f3a bhi 0x2e7fee <FT_Stream_ReadFields+0x11a> */
/* @0x2e7f3c cmp r0, #0x18 */
/* @0x2e7f3e bne 0x2e7f2a <FT_Stream_ReadFields+0x56> */
/* @0x2e7f40 ldrh r0, [r5, #-2] */
/* @0x2e7f44 mov r1, r3 */
/* @0x2e7f46 add r0, r7 */
/* @0x2e7f48 blx 0xb65bc <memcpy@plt> */
/* @0x2e7f4c b 0x2e7f2a <FT_Stream_ReadFields+0x56> */
/* @0x2e7f4e adds r4, r3, #0x1 */
/* @0x2e7f50 movs r1, #0x18 */
/* @0x2e7f52 ldrb r3, [r3] */
/* @0x2e7f54 b 0x2e7fc6 <FT_Stream_ReadFields+0xf2> */
/* @0x2e7f56 adds r4, r3, #0x2 */
/* @0x2e7f58 ldrb r2, [r3] */
/* @0x2e7f5a ldrb r3, [r3, #0x1] */
/* @0x2e7f5c b 0x2e7f64 <FT_Stream_ReadFields+0x90> */
/* @0x2e7f5e adds r4, r3, #0x2 */
/* @0x2e7f60 ldrb r2, [r3, #0x1] */
/* @0x2e7f62 ldrb r3, [r3] */
/* @0x2e7f64 orr.w r3, r3, r2, lsl #8 */
/* @0x2e7f68 movs r1, #0x10 */
/* @0x2e7f6a b 0x2e7fc6 <FT_Stream_ReadFields+0xf2> */
/* @0x2e7f6c ldrb r2, [r3, #0x1] */
/* @0x2e7f6e adds r4, r3, #0x4 */
/* @0x2e7f70 ldrb r1, [r3] */
/* @0x2e7f72 lsls r2, r2, #0x10 */
/* @0x2e7f74 orr.w r2, r2, r1, lsl #24 */
/* @0x2e7f78 ldrb r1, [r3, #0x3] */
/* @0x2e7f7a ldrb r3, [r3, #0x2] */
/* @0x2e7f7c orrs r2, r1 */
/* @0x2e7f7e b 0x2e7f92 <FT_Stream_ReadFields+0xbe> */
/* @0x2e7f80 ldrb r2, [r3, #0x2] */
/* @0x2e7f82 adds r4, r3, #0x4 */
/* @0x2e7f84 ldrb r1, [r3, #0x3] */
/* @0x2e7f86 lsls r2, r2, #0x10 */
/* @0x2e7f88 orr.w r2, r2, r1, lsl #24 */
/* @0x2e7f8c ldrb r1, [r3] */
/* @0x2e7f8e ldrb r3, [r3, #0x1] */
/* @0x2e7f90 orrs r2, r1 */
/* @0x2e7f92 orr.w r3, r2, r3, lsl #8 */
/* @0x2e7f94 .word 0x21002303 */
/* @0x2e7f96 movs r1, #0x0 */
/* @0x2e7f98 b 0x2e7fc6 <FT_Stream_ReadFields+0xf2> */
/* @0x2e7f9a ldrb r1, [r3, #0x1] */
/* @0x2e7f9c adds r4, r3, #0x3 */
/* @0x2e7f9e ldrb r2, [r3] */
/* @0x2e7fa0 lsls r1, r1, #0x8 */
/* @0x2e7fa2 orr.w r1, r1, r2, lsl #16 */
/* @0x2e7fa4 ldmvc r10, {r1, r8, lr} */
/* @0x2e7fa6 ldrb r2, [r3, #0x2] */
/* @0x2e7fa8 b 0x2e7fb8 <FT_Stream_ReadFields+0xe4> */
/* @0x2e7faa ldrb r1, [r3, #0x1] */
/* @0x2e7fac adds r4, r3, #0x3 */
/* @0x2e7fae ldrb r2, [r3, #0x2] */
/* @0x2e7fb0 lsls r1, r1, #0x8 */
/* @0x2e7fb2 orr.w r1, r1, r2, lsl #16 */
/* @0x2e7fb4 ldmdavc r10, {r1, r8, lr} */
/* @0x2e7fb6 ldrb r2, [r3] */
/* @0x2e7fb8 orr.w r3, r1, r2 */
/* @0x2e7fbc movs r1, #0x8 */
/* @0x2e7fbe b 0x2e7fc6 <FT_Stream_ReadFields+0xf2> */
/* @0x2e7fc0 str r3, [r6, #0x20] */
/* @0x2e7fc2 movs r4, #0x0 */
/* @0x2e7fc4 b 0x2e7ff0 <FT_Stream_ReadFields+0x11c> */
/* @0x2e7fc6 lsls r2, r0, #0x1f */
/* @0x2e7fc8 ldrh r2, [r5, #-2] */
/* @0x2e7fcc itt mi */
/* @0x2e7fce lslmi r3, r1 */
/* @0x2e7fd0 asrmi r3, r1 */
/* @0x2e7fd2 ldrb r1, [r5, #-3] */
/* @0x2e7fd4 stmdbhs r2, {r0, r1, r10, r11, r12} */
/* @0x2e7fd6 cmp r1, #0x2 */
/* @0x2e7fd8 beq 0x2e7fe6 <FT_Stream_ReadFields+0x112> */
/* @0x2e7fda cmp r1, #0x4 */
/* @0x2e7fdc beq 0x2e7fea <FT_Stream_ReadFields+0x116> */
/* @0x2e7fde cmp r1, #0x1 */
/* @0x2e7fe0 bne 0x2e7fea <FT_Stream_ReadFields+0x116> */
/* @0x2e7fe2 strb r3, [r7, r2] */
/* @0x2e7fe4 b 0x2e7f2a <FT_Stream_ReadFields+0x56> */
/* @0x2e7fe6 strh r3, [r7, r2] */
/* @0x2e7fe8 b 0x2e7f2a <FT_Stream_ReadFields+0x56> */
/* @0x2e7fea str r3, [r7, r2] */
/* @0x2e7fec b 0x2e7f2a <FT_Stream_ReadFields+0x56> */
/* @0x2e7fee movs r4, #0x55 */
/* @0x2e7ff0 cmp.w r8, #0x0 */
/* @0x2e7ff4 beq 0x2e800a <FT_Stream_ReadFields+0x136> */
/* @0x2e7ff6 mov r0, r6 */
/* @0x2e7ff8 bl 0x2e7eb8 <FT_Stream_ExitFrame> */
/* @0x2e7ffc b 0x2e800a <FT_Stream_ReadFields+0x136> */
/* @0x2e7ffe movs r0, #0x6 */
/* @0x2e8000 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e8004 movs r0, #0x28 */
/* @0x2e8006 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e8008 qsub8mi r8, r0, r0 */
/* @0x2e800a mov r0, r4 */
/* @0x2e800c pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e8010 · ft_mem_qrealloc · size=126 · insn=54 */
/* @0x2e8010 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2e8014 subs.w r8, r2, #0x0 */
/* @0x2e8018 mov r7, r3 */
/* @0x2e801a mov r6, r0 */
/* @0x2e801c mov.w r3, #0x0 */
/* @0x2e8020 mov r5, r1 */
/* @0x2e8022 ldr r4, [sp, #0x20] */
/* @0x2e8024 str r3, [sp, #0x4] */
/* @0x2e8026 blt 0x2e8030 <ft_mem_qrealloc+0x20> */
/* @0x2e8028 cmp r7, r3 */
/* @0x2e802a blt 0x2e8030 <ft_mem_qrealloc+0x20> */
/* @0x2e802c cmp r1, r3 */
/* @0x2e802e bge 0x2e8034 <ft_mem_qrealloc+0x24> */
/* @0x2e8030 movs r3, #0x6 */
/* @0x2e8032 b 0x2e807a <ft_mem_qrealloc+0x6a> */
/* @0x2e8034 cbz r7, 0x2e8038 <ft_mem_qrealloc+0x28> */
/* @0x2e8036 cbnz r1, 0x2e8044 <ft_mem_qrealloc+0x34> */
/* @0x2e8038 mov r1, r4 */
/* @0x2e803a mov r0, r6 */
/* @0x2e803c bl 0x2e7336 <ft_mem_free> */
/* @0x2e8040 movs r4, #0x0 */
/* @0x2e8042 b 0x2e8080 <ft_mem_qrealloc+0x70> */
/* @0x2e8044 mvn r0, #0x80000000 */
/* @0x2e8048 blx 0x318d10 <__divsi3> */
/* @0x2e804c cmp r7, r0 */
/* @0x2e804e ble 0x2e8054 <ft_mem_qrealloc+0x44> */
/* @0x2e8050 movs r3, #0xa */
/* @0x2e8052 b 0x2e807a <ft_mem_qrealloc+0x6a> */
/* @0x2e8054 mul r2, r5, r7 */
/* @0x2e8058 cmp.w r8, #0x0 */
/* @0x2e805c bne 0x2e806a <ft_mem_qrealloc+0x5a> */
/* @0x2e805e mov r1, r2 */
/* @0x2e8060 mov r0, r6 */
/* @0x2e8062 add r2, sp, #0x4 */
/* @0x2e8064 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e8068 b 0x2e807e <ft_mem_qrealloc+0x6e> */
/* @0x2e806a ldr r7, [r6, #0xc] */
/* @0x2e806c mov r0, r6 */
/* @0x2e806e mul r1, r5, r8 */
/* @0x2e8070 strtmi pc, [r3], -r8, lsl #2 */
/* @0x2e8072 mov r3, r4 */
/* @0x2e8074 blx r7 */
/* @0x2e8076 cbnz r0, 0x2e807e <ft_mem_qrealloc+0x6e> */
/* @0x2e8078 movs r3, #0x40 */
/* @0x2e807a str r3, [sp, #0x4] */
/* @0x2e807c b 0x2e8080 <ft_mem_qrealloc+0x70> */
/* @0x2e807e mov r4, r0 */
/* @0x2e8080 ldr r2, [sp, #0x4] */
/* @0x2e8082 mov r0, r4 */
/* @0x2e8084 ldr r3, [sp, #0x24] */
/* @0x2e8086 str r2, [r3] */
/* @0x2e8088 add sp, #0x8 */
/* @0x2e808a pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e808c push {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e808e · ft_mem_realloc · size=66 · insn=30 */
/* @0x2e808e push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2e8092 add r5, sp, #0x10 */
/* @0x2e8094 movs r7, #0x0 */
/* @0x2e8096 mov r6, r1 */
/* @0x2e8098 str r7, [r5, #-4]! */
/* @0x2e809a ldrmi r7, [r4], -r4, lsl #26 */
/* @0x2e809c mov r4, r2 */
/* @0x2e809e ldr r7, [sp, #0x28] */
/* @0x2e80a0 mov r8, r3 */
/* @0x2e80a2 str r5, [sp, #0x4] */
/* @0x2e80a4 str r7, [sp] */
/* @0x2e80a6 bl 0x2e8010 <ft_mem_qrealloc> */
/* @0x2e80aa ldr r1, [sp, #0xc] */
/* @0x2e80ac mov r5, r0 */
/* @0x2e80ae cbnz r1, 0x2e80c2 <ft_mem_realloc+0x34> */
/* @0x2e80b0 cmp r8, r4 */
/* @0x2e80b2 ble 0x2e80c2 <ft_mem_realloc+0x34> */
/* @0x2e80b4 rsb r2, r4, r8 */
/* @0x2e80b6 blx 0x4688e0 <g_RomDisk+0x710c0> */
/* @0x2e80b8 mla r0, r6, r4, r0 */
/* @0x2e80ba cmnmi r2, #4 */
/* @0x2e80bc muls r2, r6, r2 */
/* @0x2e80be blx 0xb65b0 <memset@plt> */
/* @0x2e80c2 ldr r2, [sp, #0xc] */
/* @0x2e80c4 mov r0, r5 */
/* @0x2e80c6 ldr r3, [sp, #0x2c] */
/* @0x2e80c8 str r2, [r3] */
/* @0x2e80ca add sp, #0x10 */
/* @0x2e80cc pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e80ce ldrlt r8, [pc, #-0x1f0] */

/* ── FUNC 0x2e80d0 · FT_GlyphLoader_CreateExtra · size=54 · insn=24 */
/* @0x2e80d0 push {r0, r1, r2, r3, r4, lr} */
/* @0x2e80d2 mov r4, r0 */
/* @0x2e80d4 ldr r3, [r0, #0x4] */
/* @0x2e80d6 movs r2, #0x0 */
/* @0x2e80d8 add r1, sp, #0xc */
/* @0x2e80da str r2, [sp] */
/* @0x2e80dc str r1, [sp, #0x4] */
/* @0x2e80de movs r1, #0x8 */
/* @0x2e80e0 lsls r3, r3, #0x1 */
/* @0x2e80e2 ldr r0, [r0] */
/* @0x2e80e4 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e80e8 ldr r3, [sp, #0xc] */
/* @0x2e80ea str r0, [r4, #0x28] */
/* @0x2e80ec cbnz r3, 0x2e8100 <FT_GlyphLoader_CreateExtra+0x30> */
/* @0x2e80ee movs r3, #0x1 */
/* @0x2e80f0 strb r3, [r4, #0x10] */
/* @0x2e80f2 ldr r3, [r4, #0x4] */
/* @0x2e80f4 add.w r0, r0, r3, lsl #3 */
/* @0x2e80f8 str r0, [r4, #0x2c] */
/* @0x2e80fa mov r0, r4 */
/* @0x2e80fc bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40> */
/* @0x2e8100 ldr r0, [sp, #0xc] */
/* @0x2e8102 add sp, #0x10 */
/* @0x2e8104 pop {r4, pc} */

/* ── FUNC 0x2e8106 · FT_GlyphLoader_CheckPoints · size=248 · insn=110 */
/* @0x2e8106 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e810a mov r9, r2 */
/* @0x2e810c ldrsh.w r5, [r0, #0x3a] */
/* @0x2e810e addlt r5, r5, r10, lsr r0 */
/* @0x2e8110 sub sp, #0x14 */
/* @0x2e8112 ldrsh.w r2, [r0, #0x16] */
/* @0x2e8116 movs r3, #0x0 */
/* @0x2e8118 ldr r6, [r0, #0x4] */
/* @0x2e811a mov r4, r0 */
/* @0x2e811c add r5, r2 */
/* @0x2e811e ldr r7, [r0] */
/* @0x2e8120 add r1, r5 */
/* @0x2e8122 str r3, [sp, #0xc] */
/* @0x2e8124 cmp r1, r6 */
/* @0x2e8126 bls 0x2e81a8 <FT_GlyphLoader_CheckPoints+0xa2> */
/* @0x2e8128 adds r5, r1, #0x7 */
/* @0x2e812a bic r5, r5, #0x7 */
/* @0x2e812e cmp.w r5, #0x8000 */
/* @0x2e8132 blo 0x2e8138 <FT_GlyphLoader_CheckPoints+0x32> */
/* @0x2e8134 movs r0, #0xa */
/* @0x2e8136 b 0x2e81f8 <FT_GlyphLoader_CheckPoints+0xf2> */
/* @0x2e8138 ldr r3, [r0, #0x18] */
/* @0x2e813a add.w r8, sp, #0xc */
/* @0x2e813e mov r0, r7 */
/* @0x2e8140 str.w r8, [sp, #0x4] */
/* @0x2e8142 .word 0x21088004 */
/* @0x2e8144 movs r1, #0x8 */
/* @0x2e8146 mov r2, r6 */
/* @0x2e8148 str r3, [sp] */
/* @0x2e814a mov r3, r5 */
/* @0x2e814c bl 0x2e808e <ft_mem_realloc> */
/* @0x2e814e blls 0x3e7fd2 <error_g0017+0x40c76> */
/* @0x2e8150 ldr r3, [sp, #0xc] */
/* @0x2e8152 str r0, [r4, #0x18] */
/* @0x2e8154 cmp r3, #0x0 */
/* @0x2e8156 bne 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6> */
/* @0x2e8158 ldr r3, [r4, #0x1c] */
/* @0x2e815a mov r0, r7 */
/* @0x2e815c movs r1, #0x1 */
/* @0x2e815e mov r2, r6 */
/* @0x2e8160 stm.w sp, {r3, r8} */
/* @0x2e8162 strtmi r0, [r11], -r8, lsl #2 */
/* @0x2e8164 mov r3, r5 */
/* @0x2e8166 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e816a ldr r3, [sp, #0xc] */
/* @0x2e816c str r0, [r4, #0x1c] */
/* @0x2e816e cmp r3, #0x0 */
/* @0x2e8170 bne 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6> */
/* @0x2e8172 ldrb r3, [r4, #0x10] */
/* @0x2e8174 cbz r3, 0x2e81a4 <FT_GlyphLoader_CheckPoints+0x9e> */
/* @0x2e8176 ldr r3, [r4, #0x28] */
/* @0x2e8178 movs r1, #0x8 */
/* @0x2e817a mov r0, r7 */
/* @0x2e817c lsls r2, r6, #0x1 */
/* @0x2e817e stm.w sp, {r3, r8} */
/* @0x2e8182 lsls r3, r5, #0x1 */
/* @0x2e8184 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8186 blls 0x3e7f9a <error_g0017+0x40c3e> */
/* @0x2e8188 ldr r3, [sp, #0xc] */
/* @0x2e818a mov r1, r0 */
/* @0x2e818c str r0, [r4, #0x28] */
/* @0x2e818e cbnz r3, 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6> */
/* @0x2e8190 lsl.w r8, r5, #0x3 */
/* @0x2e8192 rscseq r0, r2, r5, asr #17 */
/* @0x2e8194 lsls r2, r6, #0x3 */
/* @0x2e8196 add r0, r8 */
/* @0x2e8198 add r1, r2 */
/* @0x2e819a blx 0xb6694 <memmove@plt> */
/* @0x2e819e ldr r3, [r4, #0x28] */
/* @0x2e81a0 add r3, r8 */
/* @0x2e81a2 str r3, [r4, #0x2c] */
/* @0x2e81a4 movs r3, #0x1 */
/* @0x2e81a6 str r5, [r4, #0x4] */
/* @0x2e81a8 ldrsh.w r5, [r4, #0x38] */
/* @0x2e81aa rfeib r4! */
/* @0x2e81ac ldrsh.w r1, [r4, #0x14] */
/* @0x2e81ae stmvs r2!, {r2, r4, r12} */
/* @0x2e81b0 ldr r2, [r4, #0x8] */
/* @0x2e81b2 add r5, r1 */
/* @0x2e81b4 add r9, r5 */
/* @0x2e81b6 cmp r9, r2 */
/* @0x2e81b8 bls 0x2e81e4 <FT_GlyphLoader_CheckPoints+0xde> */
/* @0x2e81ba add.w r9, r9, #0x3 */
/* @0x2e81be bic r5, r9, #0x3 */
/* @0x2e81c2 cmp.w r5, #0x8000 */
/* @0x2e81c6 bhs 0x2e8134 <FT_GlyphLoader_CheckPoints+0x2e> */
/* @0x2e81c8 ldr r3, [r4, #0x20] */
/* @0x2e81ca mov r0, r7 */
/* @0x2e81cc movs r1, #0x2 */
/* @0x2e81ce str r3, [sp] */
/* @0x2e81d0 add r3, sp, #0xc */
/* @0x2e81d2 str r3, [sp, #0x4] */
/* @0x2e81d4 mov r3, r5 */
/* @0x2e81d6 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e81da ldr r3, [sp, #0xc] */
/* @0x2e81dc str r0, [r4, #0x20] */
/* @0x2e81de cbnz r3, 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6> */
/* @0x2e81e0 str r5, [r4, #0x8] */
/* @0x2e81e2 b 0x2e81e6 <FT_GlyphLoader_CheckPoints+0xe0> */
/* @0x2e81e4 cbz r3, 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6> */
/* @0x2e81e6 mov r0, r4 */
/* @0x2e81e8 bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40> */
/* @0x2e81ea blls 0x3e70a2 <error_g0017+0x3fd46> */
/* @0x2e81ec ldr r3, [sp, #0xc] */
/* @0x2e81ee cbz r3, 0x2e81f6 <FT_GlyphLoader_CheckPoints+0xf0> */
/* @0x2e81f0 mov r0, r4 */
/* @0x2e81f2 bl 0x2e7340 <FT_GlyphLoader_Reset> */
/* @0x2e81f6 ldr r0, [sp, #0xc] */
/* @0x2e81f8 add sp, #0x14 */
/* @0x2e81fa pop.w {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2e81fe · FT_GlyphLoader_CopyPoints · size=118 · insn=50 */
/* @0x2e81fe push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e8202 mov r5, r1 */
/* @0x2e8204 ldrh.w r10, [r1, #0x16] */
/* @0x2e8206 .word 0x4604a016 */
/* @0x2e8208 mov r4, r0 */
/* @0x2e820a ldrh.w r9, [r1, #0x14] */
/* @0x2e820e sxth.w r7, r10 */
/* @0x2e8212 sxth.w r11, r9 */
/* @0x2e8216 mov r1, r7 */
/* @0x2e8218 mov r2, r11 */
/* @0x2e821a bl 0x2e8106 <FT_GlyphLoader_CheckPoints> */
/* @0x2e821e mov r8, r0 */
/* @0x2e8220 cbnz r0, 0x2e826e <FT_GlyphLoader_CopyPoints+0x70> */
/* @0x2e8222 lsls r6, r7, #0x3 */
/* @0x2e8224 ldr r1, [r5, #0x18] */
/* @0x2e8226 ldr r0, [r4, #0x18] */
/* @0x2e8228 mov r2, r6 */
/* @0x2e822a blx 0xb65bc <memcpy@plt> */
/* @0x2e822e ldr r1, [r5, #0x1c] */
/* @0x2e8230 mov r2, r7 */
/* @0x2e8232 ldr r0, [r4, #0x1c] */
/* @0x2e8234 blx 0xb65bc <memcpy@plt> */
/* @0x2e8236 bvs 0xb22946 <b2_toiTime+0x3c94a2> */
/* @0x2e8238 ldr r0, [r4, #0x20] */
/* @0x2e823a ldr r1, [r5, #0x20] */
/* @0x2e823c lsl.w r2, r11, #0x1 */
/* @0x2e823e .word 0xf5ce024b */
/* @0x2e8240 blx 0xb65bc <memcpy@plt> */
/* @0x2e8242 stcvc p9, c14, [r3], #-752 */
/* @0x2e8244 ldrb r3, [r4, #0x10] */
/* @0x2e8246 cbz r3, 0x2e8260 <FT_GlyphLoader_CopyPoints+0x62> */
/* @0x2e8248 ldrb r3, [r5, #0x10] */
/* @0x2e824a cbz r3, 0x2e8260 <FT_GlyphLoader_CopyPoints+0x62> */
/* @0x2e824c ldr r1, [r5, #0x28] */
/* @0x2e824e mov r2, r6 */
/* @0x2e8250 ldr r0, [r4, #0x28] */
/* @0x2e8252 blx 0xb65bc <memcpy@plt> */
/* @0x2e8256 ldr r0, [r4, #0x2c] */
/* @0x2e8258 ldr r1, [r5, #0x2c] */
/* @0x2e825a mov r2, r6 */
/* @0x2e825c blx 0xb65bc <memcpy@plt> */
/* @0x2e825e .word 0xf8a4e9ae */
/* @0x2e8260 strh.w r10, [r4, #0x16] */
/* @0x2e8262 qadd16mi r10, r0, r6 */
/* @0x2e8264 mov r0, r4 */
/* @0x2e8266 strh.w r9, [r4, #0x14] */
/* @0x2e826a bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40> */
/* @0x2e826e mov r0, r8 */
/* @0x2e8270 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e8272 ldrlt r8, [r0, #-0xff8]! */

/* ── FUNC 0x2e8274 · FT_GlyphLoader_CheckSubGlyphs · size=70 · insn=34 */
/* @0x2e8274 push {r4, r5, lr} */
/* @0x2e8276 sub sp, #0x14 */
/* @0x2e8278 mov r4, r0 */
/* @0x2e827a movs r3, #0x0 */
/* @0x2e827c ldr r5, [r4, #0x54] */
/* @0x2e827e str r3, [sp, #0xc] */
/* @0x2e8280 ldr r3, [r4, #0x30] */
/* @0x2e8282 ldr r2, [r4, #0xc] */
/* @0x2e8284 add r3, r5 */
/* @0x2e8286 ldr r0, [r0] */
/* @0x2e8288 add r1, r3 */
/* @0x2e828a cmp r1, r2 */
/* @0x2e828c bls 0x2e82b4 <FT_GlyphLoader_CheckSubGlyphs+0x40> */
/* @0x2e828e ldr r3, [r4, #0x34] */
/* @0x2e8290 adds r5, r1, #0x1 */
/* @0x2e8292 bic r5, r5, #0x1 */
/* @0x2e8294 .word 0x21200501 */
/* @0x2e8296 movs r1, #0x20 */
/* @0x2e8298 str r3, [sp] */
/* @0x2e829a add r3, sp, #0xc */
/* @0x2e829c str r3, [sp, #0x4] */
/* @0x2e829e mov r3, r5 */
/* @0x2e82a0 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e82a4 ldr r3, [sp, #0xc] */
/* @0x2e82a6 str r0, [r4, #0x34] */
/* @0x2e82a8 cbnz r3, 0x2e82b4 <FT_GlyphLoader_CheckSubGlyphs+0x40> */
/* @0x2e82aa ldr r3, [r4, #0x30] */
/* @0x2e82ac str r5, [r4, #0xc] */
/* @0x2e82ae add.w r0, r0, r3, lsl #5 */
/* @0x2e82b0 strvs r1, [r0, #0x43]! */
/* @0x2e82b2 str r0, [r4, #0x58] */
/* @0x2e82b4 ldr r0, [sp, #0xc] */
/* @0x2e82b6 add sp, #0x14 */
/* @0x2e82b8 pop {r4, r5, pc} */

/* ── FUNC 0x2e82bc · ft_hash_str_init · size=60 · insn=29 */
/* @0x2e82bc push {r0, r1, r2, r3, r4, lr} */
/* @0x2e82be mov r4, r0 */
/* @0x2e82c0 movs r3, #0xf1 */
/* @0x2e82c2 movs r2, #0x50 */
/* @0x2e82c4 stm.w r0, {r2, r3} */
/* @0x2e82c8 movs r2, #0x0 */
/* @0x2e82ca str r2, [r0, #0x8] */
/* @0x2e82cc ldr r0, [pc, #0x20] */
/* @0x2e82ce str r2, [sp] */
/* @0x2e82d0 add r0, pc */
/* @0x2e82d2 str r0, [r4, #0xc] */
/* @0x2e82d4 ldr r0, [pc, #0x1c] */
/* @0x2e82d6 add r0, pc */
/* @0x2e82d8 str r0, [r4, #0x10] */
/* @0x2e82da add r0, sp, #0xc */
/* @0x2e82dc str r0, [sp, #0x4] */
/* @0x2e82de mov r0, r1 */
/* @0x2e82e0 movs r1, #0x4 */
/* @0x2e82e2 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e82e4 .word 0x6160fed4 */
/* @0x2e82e6 str r0, [r4, #0x14] */
/* @0x2e82e8 ldr r0, [sp, #0xc] */
/* @0x2e82ea add sp, #0x10 */
/* @0x2e82ec pop {r4, pc} */
/* @0x2e82ee nop */
/* @0x2e82f0 stm r6!, {r0, r5, r7} */
/* @0x2e82f2 vtbx.8 d28, {d15, d16}, d5 */
/* @0x2e82f4 .word 0xffffc945 */
/* @0x2e82f6 .word 0xffff b5f0 */

/* ── FUNC 0x2e82f8 · FT_CMap_Done · size=126 · insn=58 */
/* @0x2e82f8 push {r4, r5, r6, r7, lr} */
/* @0x2e82fa mov r6, r0 */
/* @0x2e82fc sub sp, #0x14 */
/* @0x2e82fe cmp r0, #0x0 */
/* @0x2e8300 beq 0x2e8372 <FT_CMap_Done+0x7a> */
/* @0x2e8302 ldr r4, [r0] */
/* @0x2e8304 movs r5, #0x0 */
/* @0x2e8306 ldr r0, [r4, #0x64] */
/* @0x2e8308 ldr r2, [r4, #0x24] */
/* @0x2e830a cmp r5, r2 */
/* @0x2e830c bge 0x2e8372 <FT_CMap_Done+0x7a> */
/* @0x2e830e ldr r3, [r4, #0x28] */
/* @0x2e8310 ldr.w r1, [r3, r5, lsl #2] */
/* @0x2e8314 cmp r1, r6 */
/* @0x2e8316 bne 0x2e836e <FT_CMap_Done+0x76> */
/* @0x2e8318 add.w r1, r2, #0x40000000 */
/* @0x2e831c subs r1, #0x1 */
/* @0x2e831e ldr.w r7, [r3, r1, lsl #2] */
/* @0x2e8320 .word 0x21047021 */
/* @0x2e8322 movs r1, #0x4 */
/* @0x2e8324 str r3, [sp] */
/* @0x2e8326 add r3, sp, #0xc */
/* @0x2e8328 str r3, [sp, #0x4] */
/* @0x2e832a subs r3, r2, #0x1 */
/* @0x2e832c bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8330 ldr r3, [sp, #0xc] */
/* @0x2e8332 str r0, [r4, #0x28] */
/* @0x2e8334 cbnz r3, 0x2e8372 <FT_CMap_Done+0x7a> */
/* @0x2e8336 adds r3, r5, #0x1 */
/* @0x2e8338 lsls r5, r5, #0x2 */
/* @0x2e833a ldr r2, [r4, #0x24] */
/* @0x2e833c cmp r3, r2 */
/* @0x2e833e add.w r2, r2, #0xffffffff */
/* @0x2e8340 ble 0x574f44 <g_SWFlineaavertbuff+0x21e7c> */
/* @0x2e8342 bge 0x2e835a <FT_CMap_Done+0x62> */
/* @0x2e8344 cmp r3, r2 */
/* @0x2e8346 ldr r2, [r4, #0x28] */
/* @0x2e8348 add.w r3, r3, #0x1 */
/* @0x2e834c itett ne */
/* @0x2e834e addne r1, r2, r5 */
/* @0x2e8350 streq r7, [r2, r5] */
/* @0x2e8352 ldrne r1, [r1, #0x4] */
/* @0x2e8354 strne r1, [r2, r5] */
/* @0x2e8356 adds r5, #0x4 */
/* @0x2e8358 b 0x2e833a <FT_CMap_Done+0x42> */
/* @0x2e835a ldr r3, [r4, #0x5c] */
/* @0x2e835c mov r0, r6 */
/* @0x2e835e str r2, [r4, #0x24] */
/* @0x2e8360 cmp r3, r6 */
/* @0x2e8362 itt eq */
/* @0x2e8364 moveq r3, #0x0 */
/* @0x2e8366 streq r3, [r4, #0x5c] */
/* @0x2e8368 bl 0x2e7b5c <FT_Done_GlyphSlot+0x42> */
/* @0x2e836c b 0x2e8372 <FT_CMap_Done+0x7a> */
/* @0x2e836e adds r5, #0x1 */
/* @0x2e8370 b 0x2e830a <FT_CMap_Done+0x12> */
/* @0x2e8372 add sp, #0x14 */
/* @0x2e8374 pop {r4, r5, r6, r7, pc} */
