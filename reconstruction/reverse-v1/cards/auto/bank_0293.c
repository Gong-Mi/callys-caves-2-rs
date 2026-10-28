/* libyoyo.so 覆盖卡组 0293
 * 函数 0x2e73a6..0x2e8011，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e73a6 · anon_2e73a6 · size=56 · insn=14 */
/* @0x2e73a6 .word 0x43f8e92d */
/* @0x2e73aa strmi r4, [r4], -pc, lsl #12 */
/* @0x2e73ae .word 0xf8d0b198 */
/* @0x2e73b2 strhs r8, [r0, #-0x4] */
/* @0x2e73b6 strtmi r6, [r9], r6, asr #18 */
/* @0x2e73ba ldrtmi r4, [r8], -r5, asr #10 */
/* @0x2e73be ldmdavs r1!, {r1, r2, r12, lr, pc} */
/* @0x2e73c2 .word 0xf7ff3501 */
/* @0x2e73c6 .word 0xf846ffb7 */
/* @0x2e73ca ldrb r9, [r5, r4, lsl #22]! */
/* @0x2e73ce .word 0xf7ff6961 */
/* @0x2e73d2 movwhs pc, #0xfb1 */
/* @0x2e73d6 pop {r0, r1, r5, r6, r8, sp, lr} */
/* @0x2e73da ldrblt r8, [r7, #0x3f8]! */

/* ── FUNC 0x2e73a7 · ft_hash_str_free · size=54 · insn=0 */

/* ── FUNC 0x2e73dc · anon_2e73dc · size=132 · insn=33 */
/* @0x2e73dc movwhs r11, #0x5f7 */
/* @0x2e73e0 ldrmi r4, [r7], -sp, lsl #12 */
/* @0x2e73e4 stmdahs r0, {r0, r1, r4, sp, lr} */
/* @0x2e73e8 stmdbhs r0, {r2, r4, r5, r12, lr, pc} */
/* @0x2e73ec stmdavs r6, {r2, r4, r5, r12, lr, pc} */
/* @0x2e73f0 bge 0x32f898 */
/* @0x2e73f4 .word 0xf7ff4630 */
/* @0x2e73f8 blls 0x366e58 <_ZTS12CDS_Priority+0x8eb0> */
/* @0x2e73fc bllt 0x11b8c14 <b2_toiTime+0xa5f770> */
/* @0x2e7400 stmdavs r11!, {r1, r2, r6, r7, r8, sp, lr} */
/* @0x2e7404 strle r0, [r4, #-0x7d9] */
/* @0x2e7408 stmvs r10!, {r0, r3, r5, r6, r11, sp, lr} */
/* @0x2e740c blx 0x1265410 <b2_toiTime+0xb0bf6c> */
/* @0x2e7410 smmlaeq r10, r4, r0, lr */
/* @0x2e7414 stmvs r9!, {r1, r2, r8, r10, r12, lr, pc} ^ */
/* @0x2e7418 blx 0xffa2342a <b2_toiTime+0xffffffffff2c9f86> */
/* @0x2e741c smulwtvs r3, r11, r8 */
/* @0x2e7420 and r9, r11, r1 */
/* @0x2e7424 strle r0, [r7, #-0x79b] */
/* @0x2e7428 .word 0xb12b692b */
/* @0x2e742c ldrtmi r4, [r0], -r1, lsr #12 */
/* @0x2e7430 .word 0xff81f7ff */
/* @0x2e7434 and r6, r1, r12, lsr #18 */
/* @0x2e7438 movwls r2, #0x1306 */
/* @0x2e743c .word 0xb12b9b01 */
/* @0x2e7440 ldrtmi r4, [r0], -r1, lsr #12 */
/* @0x2e7444 .word 0xff77f7ff */
/* @0x2e7448 and r2, r0, r0, lsl #8 */
/* @0x2e744c eorsvs r6, r12, r6, ror #3 */
/* @0x2e7450 and r9, r2, r1, lsl #16 */
/* @0x2e7454 and r2, r0, r1, lsr #32 */
/* @0x2e7458 andlt r2, r3, r6 */
/* @0x2e745c ldrblt r11, [r0, #-0xdf0]! */

/* ── FUNC 0x2e73dd · FT_Stream_New · size=130 · insn=0 */

/* ── FUNC 0x2e745e · anon_2e745e · size=96 · insn=24 */
/* @0x2e745e .word 0x460eb570 */
/* @0x2e7462 .word 0xb1484604 */
/* @0x2e7466 .word 0xf7ff69c5 */
/* @0x2e746a stmdblt lr!, {r0, r1, r2, r4, r9, r11, r12, sp, lr, pc} */
/* @0x2e746e strtmi r4, [r1], -r8, lsr #12 */
/* @0x2e7472 ldrhtmi lr, [r0], #-141 */
/* @0x2e7476 svclt #0x5ef7ff */
/* @0x2e747a ldrlt r11, [r0, #-0xd70] */
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

/* ── FUNC 0x2e745f · FT_Stream_Free · size=30 · insn=0 */

/* ── FUNC 0x2e74bc · anon_2e74bc · size=72 · insn=18 */
/* @0x2e74bc .word 0x460eb573 */
/* @0x2e74c0 biclt r4, r8, r4, lsl #12 */
/* @0x2e74c4 biclt r6, sp, r5, lsl #28 */
/* @0x2e74c8 bge 0x341670 */
/* @0x2e74cc .word 0xff86f7ff */
/* @0x2e74d0 stmvs r11!, {r3, r5, r7, r8, r11, r12, sp, pc} ^ */
/* @0x2e74d4 .word 0xb1236d1b */
/* @0x2e74d8 stmdbls r1, {r5, r9, r10, lr} */
/* @0x2e74dc .word 0x46044798 */
/* @0x2e74e0 strhs lr, [r7], #-0 */
/* @0x2e74e4 stmdals r1, {r0, r4, r5, r8, r11, sp, lr} */
/* @0x2e74e8 ldmdavs r1!, {r0, r4, r8, r12, sp, pc} */
/* @0x2e74ec smlalbteq pc, r0, r1, r3 */
/* @0x2e74f0 .word 0xffb5f7ff */
/* @0x2e74f4 and r4, r2, r0, lsr #12 */
/* @0x2e74f8 and r2, r0, r3, lsr #32 */
/* @0x2e74fc andlt r2, r2, r2, lsr #32 */
/* @0x2e7500 strlt r11, [r0, #-0xd70] */

/* ── FUNC 0x2e74bd · FT_Attach_Stream · size=70 · insn=0 */

/* ── FUNC 0x2e7502 · anon_2e7502 · size=84 · insn=21 */
/* @0x2e7502 addlt r11, r9, r0, lsl #10 */
/* @0x2e7506 .word 0x9103b141 */
/* @0x2e750a movwhs r4, #0x669 */
/* @0x2e750e movwhs r9, #0x4304 */
/* @0x2e7512 .word 0xf7ff9300 */
/* @0x2e7516 .word 0xe000ffd2 */
/* @0x2e751a andlt r2, r9, r6 */
/* @0x2e751e blx 0x42569c <g_RomDisk+0x2de7c> */
/* @0x2e7522 .word 0x4604b510 */
/* @0x2e7526 ldrsblo pc, [r12], r0 */
/* @0x2e752a ldmdavs r11, {r0, r1, r7, r8, r12, sp, pc} ^ */
/* @0x2e752e strle r0, [sp, #-0x7db] */
/* @0x2e7532 stcvs p8, c6, [r1, #268]! */
/* @0x2e7536 .word 0xf7ff6e58 */
/* @0x2e753a movwhs pc, #0xefd */
/* @0x2e753e .word 0xf8d465a3 */
/* @0x2e7542 ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^ */
/* @0x2e7546 andeq pc, r1, #34 */
/* @0x2e754a ldclt p0, c6, [r0, #-360] */
/* @0x2e754e strvs r2, [r3, #0x300]! */
/* @0x2e7552 ldrlt r11, [r8, #-0xd10]! */

/* ── FUNC 0x2e7503 · FT_Attach_File · size=32 · insn=0 */

/* ── FUNC 0x2e7523 · ft_glyphslot_free_bitmap · size=50 · insn=0 */

/* ── FUNC 0x2e7554 · anon_2e7554 · size=1144 · insn=286 */
/* @0x2e7554 .word 0x4604b538 */
/* @0x2e7558 .word 0xf7ff460d */
/* @0x2e755c strvs pc, [r5, #0xfe2]! */
/* @0x2e7560 andeq r11, r0, r8, lsr sp */
/* @0x2e7564 svcmi #0xf0e92d */
/* @0x2e7568 addlt r4, r5, r10, lsl #13 */
/* @0x2e756c .word 0x46064615 */
/* @0x2e7570 rsbsle r2, lr, r0, lsl #16 */
/* @0x2e7574 blhs 0x302b88 <TT_New_Context+0x2980> */
/* @0x2e7578 stclvs p0, c13, [r4, #-492] */
/* @0x2e757c rsbsle r2, r8, r0, lsl #24 */
/* @0x2e7580 .word 0xf1044620 */
/* @0x2e7584 .word 0xf7ff086c */
/* @0x2e7588 smlabths r0, r12, pc, pc */
/* @0x2e758c .word 0xf1042220 */
/* @0x2e7590 .word 0xf5cf0018 */
/* @0x2e7594 andshs lr, r4, #917504 */
/* @0x2e7598 .word 0x21004640 */
/* @0x2e759c stmda r8, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} */
/* @0x2e75a0 strvs r2, [r7, #-0x700]! */
/* @0x2e75a4 strbtvs r0, [r7], #1386 */
/* @0x2e75a8 .word 0xf445bf48 */
/* @0x2e75ac strbvs r6, [r7, #-0x500]! */
/* @0x2e75b0 .word 0xf045bf48 */
/* @0x2e75b4 .word 0xf8840501 */
/* @0x2e75b8 uqsaxvs r7, r7, lr */
/* @0x2e75bc .word 0xf8c466a7 */
/* @0x2e75c0 .word 0xf8c47080 */
/* @0x2e75c4 .word 0xf8c47084 */
/* @0x2e75c8 .word 0xf8c47088 */
/* @0x2e75cc .word 0xf8c4708c */
/* @0x2e75d0 strtvs r7, [r7], #152 */
/* @0x2e75d4 .word 0x63e763a7 */
/* @0x2e75d8 addsvc pc, r0, r4, asr #17 */
/* @0x2e75dc addsvc pc, r4, r4, asr #17 */
/* @0x2e75e0 ldmdavs r11!, {r0, r1, r2, r4, r5, r9, r10, r11, sp, lr} ^ */
/* @0x2e75e4 .word 0x90a0f8d3 */
/* @0x2e75e8 svclt #0x4407eb */
/* @0x2e75ec streq pc, [r4, #-0x25] */
/* @0x2e75f0 streq pc, [r10, #-0x45] */
/* @0x2e75f4 svclt #0x480268 */
/* @0x2e75f8 streq pc, [r4, #-0x25] */
/* @0x2e75fc svceq #0xf1b9 */
/* @0x2e7600 vqadd.s8 d29, d8, d25 */
/* @0x2e7604 eormi r0, r11, r2, lsl #6 */
/* @0x2e7608 teqle r4, r0, lsl #22 */
/* @0x2e760c ldmdavs r3, {r1, r3, r4, r5, r11, sp, lr} */
/* @0x2e7610 movtvc pc, #0x403 */
/* @0x2e7614 svcvc #0x80f5b3 */
/* @0x2e7618 ldmvs r3!, {r0, r2, r3, r5, r8, r12, lr, pc} */
/* @0x2e761c strtle r0, [r10], #-1177 */
/* @0x2e7620 strle r0, [r7], #-1320 */
/* @0x2e7624 .word 0x1080f8d6 */
/* @0x2e7628 stmdavs r9, {r3, r7, r11, sp, lr} */
/* @0x2e762c stmdblt r9, {r3, r8, r11, r12, sp, pc} */
/* @0x2e7630 bllt 0x35f6bc <_ZTS12CDS_Priority+0x1714> */
/* @0x2e7634 .word 0xf10006a9 */
/* @0x2e7638 ldmdavs r2, {r0, r2, r4, r5, r6, r7, pc} */
/* @0x2e763c .word 0xf1400550 */
/* @0x2e7640 .word 0xf3c580f1 */
/* @0x2e7644 stmdbhs r1, {r0, r1, r8, lr} */
/* @0x2e7648 ldreq sp, [r1, #-0x102] */
/* @0x2e764c rschi pc, r10, r0, asr #2 */
/* @0x2e7650 ldrle r0, [r0, #-0x71a] */
/* @0x2e7654 sbcshs pc, r4, #14024704 */
/* @0x2e7658 rfeia r6! */
/* @0x2e765c ldmdblt r2, {r1, r2, r3, r4, r8, sp} ^ */
/* @0x2e7660 addhs pc, r4, #14024704 */
/* @0x2e7664 .word 0xf8d6b93a */
/* @0x2e7668 bhs 0x2f00a0 <FT_Done_Memory+0x642c> */
/* @0x2e766c sbcshi pc, r10, r0 */
/* @0x2e7670 eorhs lr, r3, r1 */
/* @0x2e7674 ldmvs r11!, {r8, sp, lr, pc} ^ */
/* @0x2e7678 ldcvs p6, c4, [r1, #128]! */
/* @0x2e767c ldcvs p6, c4, [pc], {82} */
/* @0x2e7680 ldrmi r4, [r8, r11, lsr #12]! */
/* @0x2e7684 .word 0xf0402800 */
/* @0x2e7688 stcvs p0, c8, [r3], #988 */
/* @0x2e768c addsmi r4, r3, #124, #20 */
/* @0x2e7690 strhs sp, [r0, -r1] */
/* @0x2e7694 .word 0x4640e053 */
/* @0x2e7698 mcr2 p7, #0x2, pc, c1, c14, #0x7 */
/* @0x2e769c stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x2e76a0 adcshi pc, lr, r0, asr #32 */
/* @0x2e76a4 ldrbtle r0, [r4], #1960 */
/* @0x2e76a8 svceq #0x10f015 */
/* @0x2e76ac bvs 0x1bc1f3c <b2_toiTime+0x1468a98> */
/* @0x2e76b0 .word 0xf8d46ae0 */
/* @0x2e76b4 blvs 0xb5771c <b2_toiTime+0x3fe278> */
/* @0x2e76b8 teqlo pc, #28 */
/* @0x2e76bc .word 0xf0234484 */
/* @0x2e76c0 rsbvs r0, r3, #-67108864 */
/* @0x2e76c4 .word 0xf10c69e3 */
/* @0x2e76c8 .word 0xf0200c3f */
/* @0x2e76cc .word 0xf02c003f */
/* @0x2e76d0 strmi r0, [r11], #-3135 */
/* @0x2e76d4 teqeq pc, r1, lsr #32 */
/* @0x2e76d8 .word 0xf022333f */
/* @0x2e76dc .word 0xf023023f */
/* @0x2e76e0 rscvs r0, r0, #-67108864 */
/* @0x2e76e4 bl 0xff300370 <b2_toiTime+0xfffffffffeba6ecc> */
/* @0x2e76e8 bne 0x1927720 <b2_toiTime+0x11ce27c> */
/* @0x2e76ec lsrvs r6, r2, #4 */
/* @0x2e76f0 ands r6, r10, r1, ror #3 */
/* @0x2e76f4 teqeq pc, r1, lsr #32 */
/* @0x2e76f8 stmibvs r1!, {r0, r5, r8, r9, sp, lr} ^ */
/* @0x2e76fc cpsid i */
/* @0x2e7700 .word 0xf0220c3f */
/* @0x2e7704 bne 0x1928008 <b2_toiTime+0x11ceb64> */
/* @0x2e7708 .word 0xf023333f */
/* @0x2e770c .word 0xf02c033f */
/* @0x2e7710 .word 0xf0210c3f */
/* @0x2e7714 .word 0xf020013f */
/* @0x2e7718 eorvs r0, r2, #63 */
/* @0x2e771c andeq lr, r12, #198656 */
/* @0x2e7720 bne 0x19c00b4 <b2_toiTime+0x1266c10> */
/* @0x2e7724 .word 0x61a262e0 */
/* @0x2e7728 bvs 0xfebbfebc <b2_toiTime+0xfffffffffe466a18> */
/* @0x2e772c .word 0xf0233320 */
/* @0x2e7730 adcvs r0, r3, #-67108864 */
/* @0x2e7734 .word 0x33206b63 */
/* @0x2e7738 teqeq pc, #35 */
/* @0x2e773c .word 0xf0156363 */
/* @0x2e7740 andle r0, r4, r0, lsl r2 */
/* @0x2e7744 strtvs r2, [r3], #-768 */
/* @0x2e7748 strbtvs r6, [r3], #-2915 */
/* @0x2e774c bvs 0xfebdf75c <b2_toiTime+0xfffffffffe4862b8> */
/* @0x2e7750 strtvs r6, [r3], #-1122 */
/* @0x2e7754 ldrle r0, [r2], #-1193 */
/* @0x2e7758 .word 0x07da68b3 */
/* @0x2e775c .word 0xf8d6d50f */
/* @0x2e7760 subhs r9, r0, #88 */
/* @0x2e7764 .word 0xf8d96ba0 */
/* @0x2e7768 .word 0xf7fd1010 */
/* @0x2e776c subhs pc, r0, #946176 */
/* @0x2e7770 blvs 0xffb005f8 <b2_toiTime+0xffffffffff3a7154> */
/* @0x2e7774 ldrsbne pc, [r4], -r9 */
/* @0x2e7778 blx 0xffb25774 <b2_toiTime+0xffffffffff3cc2d0> */
/* @0x2e777c streq r6, [r11, #-0x3e0]! */
/* @0x2e7780 .word 0xf8d6d436 */
/* @0x2e7784 ldmibvs r3!, {r7, sp, lr} */
/* @0x2e7788 eorsle r2, r1, r0, lsl #22 */
/* @0x2e778c cdpvs p8, #0x1, c6, c11, c3, #0x3 */
/* @0x2e7790 .word 0xf8d06858 */
/* @0x2e7794 .word 0xb11b309c */
/* @0x2e7798 stcvs p9, c6, [r2], #100 */
/* @0x2e779c mulle r5, r1, r2 */
/* @0x2e77a0 andhs r6, r0, #41216 */
/* @0x2e77a4 blx 0x14e57a6 <b2_toiTime+0xd8c302> */
/* @0x2e77a8 .word 0xb1484603 */
/* @0x2e77ac .word 0x461868da */
/* @0x2e77b0 .word 0xf1064621 */
/* @0x2e77b4 bvs 0xff8a83fc <b2_toiTime+0xffffffffff14ef58> */
/* @0x2e77b8 .word 0x47b84632 */
/* @0x2e77bc ands r4, r2, r7, lsl #12 */
/* @0x2e77c0 bmi 0xec2a54 <b2_toiTime+0x7695b0> */
/* @0x2e77c4 swple r4, r3, [lr] */
/* @0x2e77c8 .word 0x07d869b3 */
/* @0x2e77cc strbmi sp, [r0], -r3, lsl #10 */
/* @0x2e77d0 .word 0xf7fe4631 */
/* @0x2e77d4 ldmibvs r3!, {r0, r2, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e77d8 strle r0, [r4, #-0x799] */
/* @0x2e77dc ldmdbvs r1!, {r6, r9, r10, lr} */
/* @0x2e77e0 .word 0xf7fe6972 */
/* @0x2e77e4 .word 0xf104fe1f */
/* @0x2e77e8 ldrtmi r0, [r1], -r0, asr #32 */
/* @0x2e77ec mcr2 p7, #0x5, pc, c12, c14, #0x7 */
/* @0x2e77f0 stcvs p9, c11, [r3], #732 */
/* @0x2e77f4 addsmi r4, r3, #143360 */
/* @0x2e77f8 bmi 0xbdb848 <b2_toiTime+0x4823a4> */
/* @0x2e77fc mulle pc, r3, r2 */
/* @0x2e7800 strle r0, [sp, #-0x76a] */
/* @0x2e7804 smlabtmi r3, r5, r3, pc */
/* @0x2e7808 .word 0xf415b921 */
/* @0x2e780c svclt #0xc5f80 */
/* @0x2e7810 .word 0x21022100 */
/* @0x2e7814 andlt r4, r5, r0, lsr #12 */
/* @0x2e7818 svcmi #0xf0e8bd */
/* @0x2e781c bllt 0x1a2581c <b2_toiTime+0x12cc378> */
/* @0x2e7820 eor r4, r9, r8, lsr r6 */
/* @0x2e7824 strle r0, [r1, #-0x79b] */
/* @0x2e7828 ldrle r0, [r6, #-0x72b] */
/* @0x2e782c .word 0xb080f8d6 */
/* @0x2e7830 strtmi r4, [r1], -r8, asr #12 */
/* @0x2e7834 ldrsblo pc, [r8], -r11 */
/* @0x2e7838 movwhs r9, #0x303 */
/* @0x2e783c andslo pc, r8, r11, asr #17 */
/* @0x2e7840 .word 0x3000f8d9 */
/* @0x2e7844 strls r6, [r0, #-0x95b] */
/* @0x2e7848 ldmvs pc, {r1, r4, r5, r7, r8, r10, r11, sp, lr} ^ */
/* @0x2e784c sbfxmi r4, r3, #0xc, #0x19 */
/* @0x2e7850 .word 0xf8cb9b03 */
/* @0x2e7854 .word 0x46073018 */
/* @0x2e7858 ldmvs r11!, {r0, r4, r5, r6, r8, r9, r10, sp, lr, pc} ^ */
/* @0x2e785c ldcvs p6, c4, [r1, #128]! */
/* @0x2e7860 ldcvs p6, c4, [pc], {82} */
/* @0x2e7864 orrmi pc, r0, #1157627904 */
/* @0x2e7868 stmdahs r0, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e786c stcvs p1, c13, [r3], #888 */
/* @0x2e7870 addsmi r4, r3, #4, #20 */
/* @0x2e7874 .word 0xe70cd1da */
/* @0x2e7878 pop {r0, r2, r12, sp, pc} */
/* @0x2e787c svclt #0x8ff0 */
/* @0x2e7880 svcvs #0x75746c */
/* @0x2e7884 rsbvs r7, r9, #1929379840 */
/* @0x2e7888 .word 0x636f6d70 */
/* @0x2e788c .word 0x43f7e92d */
/* @0x2e7890 ldrmi r4, [r7], -sp, lsl #12 */
/* @0x2e7894 .word 0xf8dd461e */
/* @0x2e7898 strmi r8, [r4], -r8, lsr #32 */
/* @0x2e789c suble r2, sp, r0, lsl #16 */
/* @0x2e78a0 svceq #0xf1b8 */
/* @0x2e78a4 stmdbvs r3, {r2, r3, r6, r12, lr, pc} */
/* @0x2e78a8 suble r4, r11, #-1879048183 */
/* @0x2e78ac stmdbeq r2, {r0, r4, r8, r9, r11, sp, lr, pc} */
/* @0x2e78b0 ldrmi sp, [r9, #0x248] */
/* @0x2e78b4 stmdblt r10, {r1, r2, r6, r11, r12, lr, pc} */
/* @0x2e78b8 sub r2, r6, r0 */
/* @0x2e78bc ldmvs r11, {r0, r1, r9, r10, r11, sp, lr} ^ */
/* @0x2e78c0 ldrsbgt pc, [r4], #-131 */
/* @0x2e78c4 svceq #0xf1bc */
/* @0x2e78c8 adcseq sp, r2, r8, lsl #2 */
/* @0x2e78cc .word 0xf446d43c */
/* @0x2e78d0 .word 0xf1a87680 */
/* @0x2e78d4 .word 0xf0060704 */
/* @0x2e78d8 eor r0, r10, r0, lsl r8 */
/* @0x2e78dc strhle r0, [r3, -r3] */
/* @0x2e78e0 movwmi pc, #0x33c6 */
/* @0x2e78e4 mvnsle r2, r1, lsl #22 */
/* @0x2e78e8 andhi pc, r0, sp, asr #17 */
/* @0x2e78ec strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e78f0 shasxmi r4, r3, r10 */
/* @0x2e78f4 stmdblt r8, {r5, r6, r7, r8, r9, r10, lr} ^ */
/* @0x2e78f8 subseq pc, r8, r4, lsl #2 */
/* @0x2e78fc ldrtmi r4, [r10], -r1, asr #12 */
/* @0x2e7900 andlt r4, r3, r3, lsr r6 */
/* @0x2e7904 mvnsmi lr, #12386304 */
/* @0x2e7908 blt 0x17e5904 <b2_toiTime+0x108c460> */
/* @0x2e790c blhs 0x4d4420 <SrcVerts+0x31464> */
/* @0x2e7910 bfi sp, r11, #2, #25 */
/* @0x2e7914 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e7918 .word 0xf7ff4632 */
/* @0x2e791c stmiblt r0!, {r0, r1, r5, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e7920 .word 0xf1b86d63 */
/* @0x2e7924 andle r0, r7, r0, lsl #30 */
/* @0x2e7928 strlo r6, [r1, #-0xc5b] */
/* @0x2e792c .word 0xf847029b */
/* @0x2e7930 strbmi r3, [sp, #-0xf04] */
/* @0x2e7934 ldr sp, [pc, lr, ror #3]! */
/* @0x2e7938 .word 0xe7f66c1b */
/* @0x2e793c and r2, r4, r3, lsr #32 */
/* @0x2e7940 and r2, r2, r6 */
/* @0x2e7944 and r2, r0, r0, lsl r0 */
/* @0x2e7948 andlt r2, r3, r7 */
/* @0x2e794c mvnshi lr, #12386304 */
/* @0x2e7950 .word 0x460fb5f7 */
/* @0x2e7954 sadd16mi r4, lr, r5 */
/* @0x2e7958 stmdahs r0, {r2, r9, r10, lr} */
/* @0x2e795c blhs 0x31ba1c <__udivdi3+0x384> */
/* @0x2e7960 stmdbvs r3, {r1, r2, r3, r5, r12, lr, pc} */
/* @0x2e7964 eorle r4, sp, #-1879048183 */
/* @0x2e7968 ldmvs r11, {r0, r1, r9, r10, r11, sp, lr} ^ */
/* @0x2e796c ldrsbgt pc, [r4], #-131 */
/* @0x2e7970 svceq #0xf1bc */
/* @0x2e7974 strls sp, [r0], -r7, lsl #2 */
/* @0x2e7978 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2e797c strtmi r2, [r11], -r1, lsl #4 */
/* @0x2e7980 .word 0xff84f7ff */
/* @0x2e7984 .word 0x0793e01f */
/* @0x2e7988 .word 0xf3c2d103 */
/* @0x2e798c blhs 0x3385a0 */
/* @0x2e7990 .word 0x9600d1f1 */
/* @0x2e7994 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2e7998 strtmi r2, [r11], -r1, lsl #4 */
/* @0x2e799c stmdblt r8, {r5, r6, r7, r8, r9, r10, lr} ^ */
/* @0x2e79a0 subseq pc, r8, r4, lsl #2 */
/* @0x2e79a4 andhs r4, r1, #51380224 */
/* @0x2e79a8 andlt r4, r3, r11, lsr #12 */
/* @0x2e79ac ldrhtmi lr, [r0], #141 */
/* @0x2e79b0 ldmiblt pc!, {r0, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2e79b4 blhs 0x4d44c8 <SrcVerts+0x3150c> */
/* @0x2e79b8 ldrb sp, [r12, r5, lsl #2] */
/* @0x2e79bc and r2, r2, r3, lsr #32 */
/* @0x2e79c0 and r2, r0, r6 */
/* @0x2e79c4 andlt r2, r3, r0, lsl r0 */
/* @0x2e79c8 ldrblt r11, [r0, #-0xdf0]! */

/* ── FUNC 0x2e7555 · ft_glyphslot_set_bitmap · size=14 · insn=0 */

/* ── FUNC 0x2e7565 · FT_Load_Glyph · size=808 · insn=0 */

/* ── FUNC 0x2e788d · FT_Get_Advances · size=196 · insn=0 */

/* ── FUNC 0x2e7951 · FT_Get_Advance · size=122 · insn=0 */

/* ── FUNC 0x2e79ca · anon_2e79ca · size=40 · insn=10 */
/* @0x2e79ca .word 0x460bb570 */
/* @0x2e79ce .word 0x46044616 */
/* @0x2e79d2 stclvs p1, c11, [r5, #352] */
/* @0x2e79d6 .word 0xf7fdb115 */
/* @0x2e79da strmi pc, [r3], -r2, asr #31 */
/* @0x2e79de ldrtmi r4, [r2], -r0, lsr #12 */
/* @0x2e79e2 pop {r0, r3, r4, r9, r10, lr} */
/* @0x2e79e6 .word 0xf7ff4070 */
/* @0x2e79ea .word 0x2023bdbc */
/* @0x2e79ee ldrblt r11, [r3, #-0xd70]! */

/* ── FUNC 0x2e79cb · FT_Load_Char · size=38 · insn=0 */

/* ── FUNC 0x2e79f0 · anon_2e79f0 · size=300 · insn=75 */
/* @0x2e79f0 .word 0x460eb573 */
/* @0x2e79f4 strmi r6, [r4], -r3, asr #16 */
/* @0x2e79f8 .word 0xf8d06e5d */
/* @0x2e79fc ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^ */
/* @0x2e7a00 strle r0, [r6, #-0x7d1] */
/* @0x2e7a04 stcvs p6, c4, [r1, #160]! */
/* @0x2e7a08 ldc2 p7, c15, [r5], {255} */
/* @0x2e7a0c strvs r2, [r3, #0x300]! */
/* @0x2e7a10 .word 0xf042e002 */
/* @0x2e7a14 subsvs r0, r10, r1, lsl #4 */
/* @0x2e7a18 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x2e7a1c .word 0xf7ffaa01 */
/* @0x2e7a20 strvs pc, [r0, #0xb82]! */
/* @0x2e7a24 andlt r9, r2, r1, lsl #16 */
/* @0x2e7a28 ldrblt r11, [r0, #-0xd70]! */
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
/* @0x2e7a70 ldrbmi lr, [r3, sp, lsr #18]! */
/* @0x2e7a74 strmi r4, [r5], -lr, lsl #12 */
/* @0x2e7a78 suble r2, r8, r0, lsl #16 */
/* @0x2e7a7c blhs 0x303290 <TT_New_Context+0x3088> */
/* @0x2e7a80 .word 0xf8d3d047 */
/* @0x2e7a84 strbtmi r8, [r10], -r8 */
/* @0x2e7a88 .word 0x464068db */
/* @0x2e7a8c .word 0xf7ff6ad9 */
/* @0x2e7a90 blls 0x3267c0 */
/* @0x2e7a94 blhs 0x2f92ac <ps_hints_apply+0x7eac> */
/* @0x2e7a98 subvs sp, r5, r4, lsr r1 */
/* @0x2e7a9c vmulvs.f32 s20, s30, s4 */
/* @0x2e7aa0 .word 0xf8422128 */
/* @0x2e7aa4 .word 0xf8d73d04 */
/* @0x2e7aa8 ldmdavs r11!, {r3, r12, pc} ^ */
/* @0x2e7aac .word 0xa00cf8d7 */
/* @0x2e7ab0 strbmi r6, [r8], -r3 */
/* @0x2e7ab4 blx 0x10e5aba <b2_toiTime+0x98c616> */
/* @0x2e7ab8 strmi r9, [r1], -r1, lsl #22 */
/* @0x2e7abc .word 0xf8c4b98b */
/* @0x2e7ac0 ldmdavs r11!, {r2, r3, r4, r7} */
/* @0x2e7ac4 ldreq r6, [r11, #0x81b] */
/* @0x2e7ac8 strbmi sp, [r8], -r3, lsl #8 */
/* @0x2e7acc blx 0x12a5ad2 <b2_toiTime+0xb4c62e> */
/* @0x2e7ad0 blls 0x34badc */
/* @0x2e7ad4 .word 0xf8dab92b */
/* @0x2e7ad8 tstlt r3, r0, asr #32 */
/* @0x2e7adc ldrmi r4, [r8, r0, lsr #12] */
/* @0x2e7ae0 blls 0x34baec */
/* @0x2e7ae4 teqlt r11, r0, lsl #6 */
/* @0x2e7ae8 .word 0xf7ff4620 */
/* @0x2e7aec .word 0x4640ff9e */
/* @0x2e7af0 .word 0xf7ff4621 */
/* @0x2e7af4 and pc, r8, r0, lsr #24 */
/* @0x2e7af8 adcvs r6, r3, r11, ror #26 */
/* @0x2e7afc .word 0xb126656c */
/* @0x2e7b00 and r6, r2, r4, lsr r0 */
/* @0x2e7b04 movwhs r11, #0x10e */
/* @0x2e7b08 stmdals r0, {r0, r1, r4, r5, sp, lr} */
/* @0x2e7b0c eorhs lr, r3, r2 */
/* @0x2e7b10 andhs lr, r6, r0 */
/* @0x2e7b14 pop {r1, r12, sp, pc} */
/* @0x2e7b18 ldrlt r8, [r8, #-0x7f0]! */

/* ── FUNC 0x2e79f1 · ft_glyphslot_alloc_bitmap · size=58 · insn=0 */

/* ── FUNC 0x2e7a71 · FT_New_GlyphSlot · size=170 · insn=0 */

/* ── FUNC 0x2e7b1a · anon_2e7b1a · size=928 · insn=232 */
/* @0x2e7b1a .word 0x4604b538 */
/* @0x2e7b1e stmdavs r2, {r5, r6, r7, r8, r12, sp, pc} ^ */
/* @0x2e7b22 cdpvs p1, #0x1, c2, c3, c0, #0x0 */
/* @0x2e7b26 ldclvs p8, c6, [r3, #-628] */
/* @0x2e7b2a adcmi r11, r3, #-1073741780 */
/* @0x2e7b2e stmvs r3!, {r0, r4, r8, r12, lr, pc} */
/* @0x2e7b32 ldrbvs r11, [r3, #-0x909] */
/* @0x2e7b36 addvs lr, r11, r0 */
/* @0x2e7b3a .word 0xb10b6963 */
/* @0x2e7b3e ldrmi r4, [r8, r0, lsr #12] */
/* @0x2e7b42 .word 0xf7ff4620 */
/* @0x2e7b46 qsub16mi pc, r8, r1 */
/* @0x2e7b4a pop {r0, r5, r9, r10, lr} */
/* @0x2e7b4e .word 0xf7ff4038 */
/* @0x2e7b52 ssub8mi r11, r9, r1 */
/* @0x2e7b56 .word 0xe7e7689b */
/* @0x2e7b5a ldrlt r11, [r8, #-0xd38]! */
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
/* @0x2e7dba .word 0x4606b570 */
/* @0x2e7dbe biclt r4, r9, r12, lsl #12 */
/* @0x2e7dc2 stmdbvs r11, {r4, r6, r7, r8, r12, sp, pc} */
/* @0x2e7dc6 strle r0, [lr, #-0x7db] */
/* @0x2e7dca strhs r6, [r0, #-0x849] */
/* @0x2e7dce blx 0xfefa5dd2 <b2_toiTime+0xfffffffffe84c92e> */
/* @0x2e7dd2 stmvs r1!, {r4, r5, r9, r10, lr} */
/* @0x2e7dd6 .word 0xf7ff6065 */
/* @0x2e7dda adcvs pc, r5, sp, lsr #21 */
/* @0x2e7dde stmvs r1!, {r4, r5, r9, r10, lr} ^ */
/* @0x2e7de2 blx 0xfed25de6 <b2_toiTime+0xfffffffffe5cc942> */
/* @0x2e7de6 strtmi r6, [r0], -r5, ror #1 */
/* @0x2e7dea andshs r2, r4, #0, #2 */
/* @0x2e7dee bl 0xffb2552e <b2_toiTime+0xffffffffff3cc08a> */
/* @0x2e7df2 ldcllt p0, c2, [r0, #-0]! */
/* @0x2e7df6 ldcllt p0, c2, [r0, #-80]! */
/* @0x2e7dfa ldcllt p0, c2, [r0, #-24]! */
/* @0x2e7dfe stmdavs r0, {r4, r8, r12, sp, pc} */
/* @0x2e7e02 svclt #0xdaf7ff */
/* @0x2e7e06 ldrbmi r2, [r0, -r1, lsr #32]! */
/* @0x2e7e0a .word 0x460cb510 */
/* @0x2e7e0e stmdbvs r3, {r3, r5, r8, r12, sp, pc} ^ */
/* @0x2e7e12 stmibvs r0, {r0, r1, r3, r4, r8, r12, sp, pc} ^ */
/* @0x2e7e16 .word 0xf7ff6809 */
/* @0x2e7e1a movwhs pc, #0xa8d */
/* @0x2e7e1e ldclt p0, c6, [r0, #-140] */
/* @0x2e7e22 mvnsmi lr, sp, lsr #18 */
/* @0x2e7e26 movwls r2, #0x1300 */
/* @0x2e7e2a stmdbvs r3, {r2, r9, r10, lr} ^ */
/* @0x2e7e2e stmdavs r2, {r0, r2, r3, r9, r10, lr} ^ */
/* @0x2e7e32 addsmi r11, r1, #-1409286144 */
/* @0x2e7e36 ldrsbhi pc, [r12], -r0 */
/* @0x2e7e3a cmphs r5, #32768 */
/* @0x2e7e3e eor r9, r11, r1, lsl #6 */
/* @0x2e7e42 strbmi r10, [r0], -r1, lsl #20 */
/* @0x2e7e46 .word 0xf95bf7ff */
/* @0x2e7e4a strmi r9, [r2], -r1, lsl #28 */
/* @0x2e7e4e bllt 0xa7fed6 <b2_toiTime+0x326a32> */
/* @0x2e7e52 strtmi r6, [r0], -r7, ror #18 */
/* @0x2e7e56 strtmi r6, [r11], -r1, lsr #17 */
/* @0x2e7e5a adcmi r4, r8, #184, #14 */
/* @0x2e7e5e andle r4, r6, #7340032 */
/* @0x2e7e62 stmdavs r1!, {r6, r9, r10, lr} */
/* @0x2e7e66 blx 0x1ca5e6a <b2_toiTime+0x154c9c6> */
/* @0x2e7e6a eorvs r2, r6, r5, asr r3 */
/* @0x2e7e6e stmdavs r3!, {r0, r8, r9, r12, pc} */
/* @0x2e7e72 rsbvs r4, r5, #486539264 */
/* @0x2e7e76 stmvs r3!, {r0, r1, r5, r9, sp, lr} */
/* @0x2e7e7a adcvs r4, r7, pc, lsl r4 */
/* @0x2e7e7e stmvs r3, {r2, r3, sp, lr, pc} */
/* @0x2e7e82 sbcsle r4, r10, #805306377 */
/* @0x2e7e86 addmi r1, r10, #860160 */
/* @0x2e7e8a stmdavs r2, {r0, r1, r2, r4, r6, r7, r8, r9, r12, lr, pc} */
/* @0x2e7e8e addvs r4, r5, sp, lsl r4 */
/* @0x2e7e92 andvs r4, r2, #436207616 */
/* @0x2e7e96 subvs r4, r2, #167772160 */
/* @0x2e7e9a andlt r9, r2, r1, lsl #16 */
/* @0x2e7e9e ldrhhi lr, [r0, #141]! */
/* @0x2e7ea2 .word 0x4604b538 */
/* @0x2e7ea6 .word 0xf7ff4615 */
/* @0x2e7eaa ldmdblt r8, {r0, r1, r3, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e7eae eorvs r6, r11, r3, lsr #20 */
/* @0x2e7eb2 rsbvs r6, r0, #32, #4 */
/* @0x2e7eb6 ldrlt r11, [r0, #-0xd38] */

/* ── FUNC 0x2e7b1b · FT_Done_GlyphSlot · size=66 · insn=0 */

/* ── FUNC 0x2e7dbb · FT_Outline_Done_Internal · size=68 · insn=0 */

/* ── FUNC 0x2e7dff · FT_Outline_Done · size=12 · insn=0 */

/* ── FUNC 0x2e7e0b · FT_Stream_ReleaseFrame · size=24 · insn=0 */

/* ── FUNC 0x2e7e23 · FT_Stream_EnterFrame · size=128 · insn=0 */

/* ── FUNC 0x2e7ea3 · FT_Stream_ExtractFrame · size=22 · insn=0 */

/* ── FUNC 0x2e7eb8 · anon_2e7eb8 · size=472 · insn=118 */
/* @0x2e7eb8 .word 0x4604b510 */
/* @0x2e7ebc .word 0xb12b6943 */
/* @0x2e7ec0 stmdavs r1!, {r6, r7, r8, r11, sp, lr} */
/* @0x2e7ec4 blx 0x10e5ec8 <b2_toiTime+0x98ca24> */
/* @0x2e7ec8 eorvs r2, r3, r0, lsl #6 */
/* @0x2e7ecc eorvs r2, r3, #0, #6 */
/* @0x2e7ed0 ldclt p2, c6, [r0, #-396] */
/* @0x2e7ed4 mvnsmi lr, sp, lsr #18 */
/* @0x2e7ed8 ldrmi r4, [r7], -r6, lsl #12 */
/* @0x2e7edc .word 0xf0002900 */
/* @0x2e7ee0 stmdahs r0, {r1, r2, r3, r7, pc} */
/* @0x2e7ee4 addhi pc, lr, r0 */
/* @0x2e7ee8 vstrne s12, [sp, #-12] */
/* @0x2e7eec stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2e7ef0 .word 0x0c04f815 */
/* @0x2e7ef4 bhs 0x82fb04 <b2_toiTime+0xd6660> */
/* @0x2e7ef8 ldm pc, {r1, r5, r6, r11, r12, lr, pc} ^ */
/* @0x2e7efc mrsvs pc, apsr */
/* @0x2e7f00 stmdahs r8!, {r0, r5, r6, r8, sp, lr} */
/* @0x2e7f04 stchs p1, c6, [r12], #-388 */
/* @0x2e7f08 .word 0x37373030 */
/* @0x2e7f0c cdpmi p1, #0x4, c4, c14, c1, #0x2 */
/* @0x2e7f10 ldmdbne r9, {r1, r2, r4, r6, r9, r10, r12, lr} */
/* @0x2e7f14 rfeda r5! */
/* @0x2e7f18 .word 0xf7ff1c02 */
/* @0x2e7f1c strmi pc, [r4], -r2, lsl #31 */
/* @0x2e7f20 .word 0xd1652800 */
/* @0x2e7f24 .word 0xf04f6a34 */
/* @0x2e7f28 strlo r0, [r4, #-0x801] */
/* @0x2e7f2c ldrb r4, [pc, r3, lsr #12] */
/* @0x2e7f30 .word 0x2c03f815 */
/* @0x2e7f34 ldmne r12, {r0, r4, r5, r6, r9, r11, sp, lr} */
/* @0x2e7f38 ldmdale r8, {r2, r3, r7, r9, lr} ^ */
/* @0x2e7f3c mvnsle r2, r8, lsl r8 */
/* @0x2e7f40 .word 0x0c02f835 */
/* @0x2e7f44 ldrtmi r4, [r8], #-1561 */
/* @0x2e7f48 bl 0x1125688 <b2_toiTime+0x9cc1e4> */
/* @0x2e7f4c mrrcne p7, #0xe, lr, r12, c13 */
/* @0x2e7f50 ldmdavc r11, {r3, r4, r8, sp} */
/* @0x2e7f54 ldcne p0, c14, [r12], {55} */
/* @0x2e7f58 ldmdavc r11, {r1, r3, r4, r11, r12, sp, lr} ^ */
/* @0x2e7f5c ldcne p0, c14, [r12], {2} */
/* @0x2e7f60 ldmdavc r11, {r1, r3, r4, r6, r11, r12, sp, lr} */
/* @0x2e7f64 movwhs lr, #0x2a43 */
/* @0x2e7f68 eor r2, r12, r0, lsl r1 */
/* @0x2e7f6c ldcne p8, c7, [r12, #-360] */
/* @0x2e7f70 ldreq r7, [r2], #-2073 */
/* @0x2e7f74 andvs lr, r1, #270336 */
/* @0x2e7f78 ldmvc r11, {r0, r3, r4, r6, r7, r11, r12, sp, lr} */
/* @0x2e7f7c and r4, r8, r10, lsl #6 */
/* @0x2e7f80 ldcne p8, c7, [r12, #-616] */
/* @0x2e7f84 ldreq r7, [r2], #-2265 */
/* @0x2e7f88 andvs lr, r1, #270336 */
/* @0x2e7f8c ldmdavc r11, {r0, r3, r4, r11, r12, sp, lr} ^ */
/* @0x2e7f90 b 0x1378bc0 <b2_toiTime+0xc1f71c> */
/* @0x2e7f94 .word 0x21002303 */
/* @0x2e7f98 ldmdavc r9, {r0, r2, r4, sp, lr, pc} ^ */
/* @0x2e7f9c ldmdavc r10, {r2, r3, r4, r6, r7, r10, r11, r12} */
/* @0x2e7fa0 b 0x13287cc <b2_toiTime+0xbcf328> */
/* @0x2e7fa4 ldmvc r10, {r1, r8, lr} */
/* @0x2e7fa8 ldmdavc r9, {r1, r2, sp, lr, pc} ^ */
/* @0x2e7fac ldmvc r10, {r2, r3, r4, r6, r7, r10, r11, r12} */
/* @0x2e7fb0 b 0x13287dc <b2_toiTime+0xbcf338> */
/* @0x2e7fb4 ldmdavc r10, {r1, r8, lr} */
/* @0x2e7fb8 movweq lr, #0x2a41 */
/* @0x2e7fbc and r2, r2, r8, lsl #2 */
/* @0x2e7fc0 strhs r6, [r0], #-563 */
/* @0x2e7fc4 bfieq lr, r4, #0, #3 */
/* @0x2e7fc8 .word 0x2c02f835 */
/* @0x2e7fcc addmi r11, r11, r4, asr #30 */
/* @0x2e7fd0 .word 0xf815410b */
/* @0x2e7fd4 stmdbhs r2, {r0, r1, r10, r11, r12} */
/* @0x2e7fd8 stmdbhs r4, {r0, r2, r12, lr, pc} */
/* @0x2e7fdc stmdbhs r1, {r0, r2, r12, lr, pc} */
/* @0x2e7fe0 ldrtpl sp, [r11], #259 */
/* @0x2e7fe4 adcspl lr, r11, #42205184 */
/* @0x2e7fe8 umlalspl lr, r11, pc, r7 */
/* @0x2e7fec ldrbhs lr, [r5], #-1949 */
/* @0x2e7ff0 svceq #0xf1b8 */
/* @0x2e7ff4 ldrtmi sp, [r0], -r9 */
/* @0x2e7ff8 .word 0xff5ef7ff */
/* @0x2e7ffc andhs lr, r6, r5 */
/* @0x2e8000 ldrhhi lr, [r0, #141]! */
/* @0x2e8004 pop {r3, r5, sp} */
/* @0x2e8008 qsub8mi r8, r0, r0 */
/* @0x2e800c ldrhhi lr, [r0, #141]! */
/* @0x2e8010 mvnsmi lr, sp, lsr #18 */
/* @0x2e8014 stmdaeq r0, {r1, r4, r5, r7, r8, r12, sp, lr, pc} */
/* @0x2e8018 .word 0x4606461f */
/* @0x2e801c movweq pc, #0x4f */
/* @0x2e8020 .word 0x9c08460d */
/* @0x2e8024 blle 0x3ccc30 <error_g0017+0x258d4> */
/* @0x2e8028 blle 0x338aac */
/* @0x2e802c ble 0x338a98 */
/* @0x2e8030 eor r2, r2, r6, lsl #6 */
/* @0x2e8034 stmdblt r9!, {r0, r1, r2, r8, r12, sp, pc} */
/* @0x2e8038 ldrtmi r4, [r0], -r1, lsr #12 */
/* @0x2e803c .word 0xf97bf7ff */
/* @0x2e8040 ands r2, sp, r0, lsl #8 */
/* @0x2e8044 andmi pc, r0, pc, rrx */
/* @0x2e8048 mcr p0, #0x3, pc, c2, c0, #0x1 */
/* @0x2e804c stcle p2, c4, [r1, #-540] */
/* @0x2e8050 ands r2, r2, r10, lsl #6 */
/* @0x2e8054 .word 0xf207fb05 */
/* @0x2e8058 svceq #0xf1b8 */
/* @0x2e805c ldrmi sp, [r1], -r5, lsl #2 */
/* @0x2e8060 bge 0x339928 */
/* @0x2e8064 .word 0xf85ff7ff */
/* @0x2e8068 ldmvs r7!, {r0, r3, sp, lr, pc} ^ */
/* @0x2e806c blx 0x439936 <g_RomDisk+0x42116> */
/* @0x2e8070 strtmi pc, [r3], -r8, lsl #2 */
/* @0x2e8074 ldmdblt r0, {r3, r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e8078 movwls r2, #0x1340 */
/* @0x2e807c strmi lr, [r4], -r0 */
/* @0x2e8080 strtmi r9, [r0], -r1, lsl #20 */
/* @0x2e8084 andsvs r9, r10, r9, lsl #22 */
/* @0x2e8088 pop {r1, r12, sp, pc} */
/* @0x2e808c push {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e7eb9 · FT_Stream_ExitFrame · size=28 · insn=0 */

/* ── FUNC 0x2e7ed5 · FT_Stream_ReadFields · size=316 · insn=0 */

/* ── FUNC 0x2e8011 · ft_mem_qrealloc · size=126 · insn=0 */
